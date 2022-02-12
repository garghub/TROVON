static u8 *edid_load(struct drm_connector *connector, const char *name,
const char *connector_name)
{
const struct firmware *fw;
struct platform_device *pdev;
u8 *fwdata = NULL, *edid, *new_edid;
int fwsize, expected;
int builtin = 0, err = 0;
int i, valid_extensions = 0;
bool print_bad_edid = !connector->bad_edid_counter || (drm_debug & DRM_UT_KMS);
pdev = platform_device_register_simple(connector_name, -1, NULL, 0);
if (IS_ERR(pdev)) {
DRM_ERROR("Failed to register EDID firmware platform device "
"for connector \"%s\"\n", connector_name);
err = -EINVAL;
goto out;
}
err = request_firmware(&fw, name, &pdev->dev);
platform_device_unregister(pdev);
if (err) {
i = 0;
while (i < GENERIC_EDIDS && strcmp(name, generic_edid_name[i]))
i++;
if (i < GENERIC_EDIDS) {
err = 0;
builtin = 1;
fwdata = generic_edid[i];
fwsize = sizeof(generic_edid[i]);
}
}
if (err) {
DRM_ERROR("Requesting EDID firmware \"%s\" failed (err=%d)\n",
name, err);
goto out;
}
if (fwdata == NULL) {
fwdata = (u8 *) fw->data;
fwsize = fw->size;
}
expected = (fwdata[0x7e] + 1) * EDID_LENGTH;
if (expected != fwsize) {
DRM_ERROR("Size of EDID firmware \"%s\" is invalid "
"(expected %d, got %d)\n", name, expected, (int) fwsize);
err = -EINVAL;
goto relfw_out;
}
edid = kmemdup(fwdata, fwsize, GFP_KERNEL);
if (edid == NULL) {
err = -ENOMEM;
goto relfw_out;
}
if (!drm_edid_block_valid(edid, 0, print_bad_edid)) {
connector->bad_edid_counter++;
DRM_ERROR("Base block of EDID firmware \"%s\" is invalid ",
name);
kfree(edid);
err = -EINVAL;
goto relfw_out;
}
for (i = 1; i <= edid[0x7e]; i++) {
if (i != valid_extensions + 1)
memcpy(edid + (valid_extensions + 1) * EDID_LENGTH,
edid + i * EDID_LENGTH, EDID_LENGTH);
if (drm_edid_block_valid(edid + i * EDID_LENGTH, i, print_bad_edid))
valid_extensions++;
}
if (valid_extensions != edid[0x7e]) {
edid[EDID_LENGTH-1] += edid[0x7e] - valid_extensions;
DRM_INFO("Found %d valid extensions instead of %d in EDID data "
"\"%s\" for connector \"%s\"\n", valid_extensions,
edid[0x7e], name, connector_name);
edid[0x7e] = valid_extensions;
new_edid = krealloc(edid, (valid_extensions + 1) * EDID_LENGTH,
GFP_KERNEL);
if (new_edid == NULL) {
err = -ENOMEM;
kfree(edid);
goto relfw_out;
}
edid = new_edid;
}
DRM_INFO("Got %s EDID base block and %d extension%s from "
"\"%s\" for connector \"%s\"\n", builtin ? "built-in" :
"external", valid_extensions, valid_extensions == 1 ? "" : "s",
name, connector_name);
relfw_out:
release_firmware(fw);
out:
if (err)
return ERR_PTR(err);
return edid;
}
int drm_load_edid_firmware(struct drm_connector *connector)
{
const char *connector_name = drm_get_connector_name(connector);
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
edid = (struct edid *) edid_load(connector, edidname, connector_name);
if (IS_ERR_OR_NULL(edid))
return 0;
drm_mode_connector_update_edid_property(connector, edid);
ret = drm_add_edid_modes(connector, edid);
kfree(edid);
return ret;
}
