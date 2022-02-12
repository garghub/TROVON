static struct msm_bus_scale_pdata *wil_platform_get_pdata(
struct device *dev,
struct device_node *of_node)
{
struct msm_bus_scale_pdata *pdata;
struct msm_bus_paths *usecase;
int i, j, ret, len;
unsigned int num_usecases, num_paths, mem_size;
const uint32_t *vec_arr;
struct msm_bus_vectors *vectors;
ret = of_property_read_u32(of_node, "qcom,msm-bus,num-cases",
&num_usecases);
if (ret) {
dev_err(dev, "Error: num-usecases not found\n");
return NULL;
}
ret = of_property_read_u32(of_node, "qcom,msm-bus,num-paths",
&num_paths);
if (ret) {
dev_err(dev, "Error: num_paths not found\n");
return NULL;
}
mem_size = sizeof(struct msm_bus_scale_pdata) +
sizeof(struct msm_bus_paths) * num_usecases +
sizeof(struct msm_bus_vectors) * num_usecases * num_paths;
pdata = kzalloc(mem_size, GFP_KERNEL);
if (!pdata)
return NULL;
ret = of_property_read_string(of_node, "qcom,msm-bus,name",
&pdata->name);
if (ret) {
dev_err(dev, "Error: Client name not found\n");
goto err;
}
if (of_property_read_bool(of_node, "qcom,msm-bus,active-only")) {
pdata->active_only = 1;
} else {
dev_info(dev, "active_only flag absent.\n");
dev_info(dev, "Using dual context by default\n");
}
pdata->num_usecases = num_usecases;
pdata->usecase = (struct msm_bus_paths *)(pdata + 1);
vec_arr = of_get_property(of_node, "qcom,msm-bus,vectors-KBps", &len);
if (vec_arr == NULL) {
dev_err(dev, "Error: Vector array not found\n");
goto err;
}
if (len != num_usecases * num_paths * sizeof(uint32_t) * 4) {
dev_err(dev, "Error: Length-error on getting vectors\n");
goto err;
}
vectors = (struct msm_bus_vectors *)(pdata->usecase + num_usecases);
for (i = 0; i < num_usecases; i++) {
usecase = &pdata->usecase[i];
usecase->num_paths = num_paths;
usecase->vectors = &vectors[i];
for (j = 0; j < num_paths; j++) {
int index = ((i * num_paths) + j) * 4;
usecase->vectors[j].src = be32_to_cpu(vec_arr[index]);
usecase->vectors[j].dst =
be32_to_cpu(vec_arr[index + 1]);
usecase->vectors[j].ab = (uint64_t)
KBTOB(be32_to_cpu(vec_arr[index + 2]));
usecase->vectors[j].ib = (uint64_t)
KBTOB(be32_to_cpu(vec_arr[index + 3]));
}
}
return pdata;
err:
kfree(pdata);
return NULL;
}
static int wil_platform_bus_request(void *handle,
uint32_t kbps )
{
int rc, i;
struct wil_platform_msm *msm = (struct wil_platform_msm *)handle;
int vote = 0;
struct msm_bus_paths *usecase;
uint32_t usecase_kbps;
uint32_t min_kbps = ~0;
for (i = 0; i < msm->pdata->num_usecases; i++) {
usecase = &msm->pdata->usecase[i];
usecase_kbps = div64_u64(usecase->vectors[0].ib, 1000);
if (usecase_kbps >= kbps && usecase_kbps < min_kbps) {
min_kbps = usecase_kbps;
vote = i;
}
}
rc = msm_bus_scale_client_update_request(msm->msm_bus_handle, vote);
if (rc)
dev_err(msm->dev, "Failed msm_bus voting. kbps=%d vote=%d, rc=%d\n",
kbps, vote, rc);
else
dev_info(msm->dev, "msm_bus_scale_client_update_request succeeded. kbps=%d vote=%d\n",
kbps, vote);
return rc;
}
static void wil_platform_uninit(void *handle)
{
struct wil_platform_msm *msm = (struct wil_platform_msm *)handle;
dev_info(msm->dev, "wil_platform_uninit\n");
if (msm->msm_bus_handle)
msm_bus_scale_unregister_client(msm->msm_bus_handle);
kfree(msm->pdata);
kfree(msm);
}
static int wil_platform_msm_bus_register(struct wil_platform_msm *msm,
struct device_node *node)
{
msm->pdata = wil_platform_get_pdata(msm->dev, node);
if (!msm->pdata) {
dev_err(msm->dev, "Failed getting DT info\n");
return -EINVAL;
}
msm->msm_bus_handle = msm_bus_scale_register_client(msm->pdata);
if (!msm->msm_bus_handle) {
dev_err(msm->dev, "Failed msm_bus registration\n");
return -EINVAL;
}
dev_info(msm->dev, "msm_bus registration succeeded! handle 0x%x\n",
msm->msm_bus_handle);
return 0;
}
void *wil_platform_msm_init(struct device *dev, struct wil_platform_ops *ops)
{
struct device_node *of_node;
struct wil_platform_msm *msm;
int rc;
of_node = of_find_compatible_node(NULL, NULL, "qcom,wil6210");
if (!of_node) {
dev_err(dev, "DT node not found\n");
return NULL;
}
msm = kzalloc(sizeof(*msm), GFP_KERNEL);
if (!msm)
return NULL;
msm->dev = dev;
rc = wil_platform_msm_bus_register(msm, of_node);
if (rc)
goto cleanup;
memset(ops, 0, sizeof(*ops));
ops->bus_request = wil_platform_bus_request;
ops->uninit = wil_platform_uninit;
return (void *)msm;
cleanup:
kfree(msm);
return NULL;
}
