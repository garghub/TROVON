static int edid_size(const u8 *edid, int data_size)
{
if (data_size < EDID_LENGTH)
return 0;
return (edid[0x7e] + 1) * EDID_LENGTH;
}
static void *edid_load(struct drm_connector *connector, const char *name,
const char *connector_name)
{
const struct firmware *fw = NULL;
const u8 *fwdata;
u8 *edid;
int fwsize, builtin;
int i, valid_extensions = 0;
bool print_bad_edid = !connector->bad_edid_counter || (drm_debug & DRM_UT_KMS);
builtin = 0;
for (i = 0; i < GENERIC_EDIDS; i++) {
if (strcmp(name, generic_edid_name[i]) == 0) {
fwdata = generic_edid[i];
fwsize = sizeof(generic_edid[i]);
builtin = 1;
break;
}
}
if (!builtin) {
struct platform_device *pdev;
int err;
pdev = platform_device_register_simple(connector_name, -1, NULL, 0);
if (IS_ERR(pdev)) {
DRM_ERROR("Failed to register EDID firmware platform device "
"for connector \"%s\"\n", connector_name);
return ERR_CAST(pdev);
}
err = request_firmware(&fw, name, &pdev->dev);
platform_device_unregister(pdev);
if (err) {
DRM_ERROR("Requesting EDID firmware \"%s\" failed (err=%d)\n",
name, err);
return ERR_PTR(err);
}
fwdata = fw->data;
fwsize = fw->size;
}
if (edid_size(fwdata, fwsize) != fwsize) {
DRM_ERROR("Size of EDID firmware \"%s\" is invalid "
"(expected %d, got %d\n", name,
edid_size(fwdata, fwsize), (int)fwsize);
edid = ERR_PTR(-EINVAL);
goto out;
}
edid = kmemdup(fwdata, fwsize, GFP_KERNEL);
if (edid == NULL) {
edid = ERR_PTR(-ENOMEM);
goto out;
}
if (!drm_edid_block_valid(edid, 0, print_bad_edid,
&connector->edid_corrupt)) {
connector->bad_edid_counter++;
DRM_ERROR("Base block of EDID firmware \"%s\" is invalid ",
name);
kfree(edid);
edid = ERR_PTR(-EINVAL);
goto out;
}
for (i = 1; i <= edid[0x7e]; i++) {
if (i != valid_extensions + 1)
memcpy(edid + (valid_extensions + 1) * EDID_LENGTH,
edid + i * EDID_LENGTH, EDID_LENGTH);
if (drm_edid_block_valid(edid + i * EDID_LENGTH, i,
print_bad_edid,
NULL))
valid_extensions++;
}
if (valid_extensions != edid[0x7e]) {
u8 *new_edid;
edid[EDID_LENGTH-1] += edid[0x7e] - valid_extensions;
DRM_INFO("Found %d valid extensions instead of %d in EDID data "
"\"%s\" for connector \"%s\"\n", valid_extensions,
edid[0x7e], name, connector_name);
edid[0x7e] = valid_extensions;
new_edid = krealloc(edid, (valid_extensions + 1) * EDID_LENGTH,
GFP_KERNEL);
if (new_edid)
edid = new_edid;
}
DRM_INFO("Got %s EDID base block and %d extension%s from "
"\"%s\" for connector \"%s\"\n", builtin ? "built-in" :
"external", valid_extensions, valid_extensions == 1 ? "" : "s",
name, connector_name);
out:
release_firmware(fw);
return edid;
}
int drm_load_edid_firmware(struct drm_connector *connector)
{
const char *connector_name = connector->name;
char *edidname = edid_firmware, *last, *colon;
int ret;
struct edid *edid;
if (*edidname == '\0')
return 0;
colon = strchr(edidname, ':');
if (colon != NULL) {
if (strncmp(connector_name, edidname, colon - edidname))
return 0;
edidname = colon + 1;
if (*edidname == '\0')
return 0;
}
last = edidname + strlen(edidname) - 1;
if (*last == '\n')
*last = '\0';
edid = edid_load(connector, edidname, connector_name);
if (IS_ERR_OR_NULL(edid))
return 0;
drm_mode_connector_update_edid_property(connector, edid);
ret = drm_add_edid_modes(connector, edid);
drm_edid_to_eld(connector, edid);
kfree(edid);
return ret;
}
