static bool hnae3_client_match(enum hnae3_client_type client_type,
enum hnae3_dev_type dev_type)
{
if ((dev_type == HNAE3_DEV_KNIC) && (client_type == HNAE3_CLIENT_KNIC ||
client_type == HNAE3_CLIENT_ROCE))
return true;
if (dev_type == HNAE3_DEV_UNIC && client_type == HNAE3_CLIENT_UNIC)
return true;
return false;
}
static int hnae3_match_n_instantiate(struct hnae3_client *client,
struct hnae3_ae_dev *ae_dev, bool is_reg)
{
int ret;
if (!(hnae3_client_match(client->type, ae_dev->dev_type) &&
hnae_get_bit(ae_dev->flag, HNAE3_DEV_INITED_B))) {
return 0;
}
if (is_reg) {
ret = ae_dev->ops->init_client_instance(client, ae_dev);
if (ret)
dev_err(&ae_dev->pdev->dev,
"fail to instantiate client\n");
return ret;
}
ae_dev->ops->uninit_client_instance(client, ae_dev);
return 0;
}
int hnae3_register_client(struct hnae3_client *client)
{
struct hnae3_client *client_tmp;
struct hnae3_ae_dev *ae_dev;
int ret = 0;
mutex_lock(&hnae3_common_lock);
list_for_each_entry(client_tmp, &hnae3_client_list, node) {
if (client_tmp->type == client->type)
goto exit;
}
list_add_tail(&client->node, &hnae3_client_list);
list_for_each_entry(ae_dev, &hnae3_ae_dev_list, node) {
ret = hnae3_match_n_instantiate(client, ae_dev, true);
if (ret)
dev_err(&ae_dev->pdev->dev,
"match and instantiation failed for port\n");
}
exit:
mutex_unlock(&hnae3_common_lock);
return ret;
}
void hnae3_unregister_client(struct hnae3_client *client)
{
struct hnae3_ae_dev *ae_dev;
mutex_lock(&hnae3_common_lock);
list_for_each_entry(ae_dev, &hnae3_ae_dev_list, node) {
hnae3_match_n_instantiate(client, ae_dev, false);
}
list_del(&client->node);
mutex_unlock(&hnae3_common_lock);
}
int hnae3_register_ae_algo(struct hnae3_ae_algo *ae_algo)
{
const struct pci_device_id *id;
struct hnae3_ae_dev *ae_dev;
struct hnae3_client *client;
int ret = 0;
mutex_lock(&hnae3_common_lock);
list_add_tail(&ae_algo->node, &hnae3_ae_algo_list);
list_for_each_entry(ae_dev, &hnae3_ae_dev_list, node) {
id = pci_match_id(ae_algo->pdev_id_table, ae_dev->pdev);
if (!id)
continue;
ae_dev->ops = ae_algo->ops;
ret = ae_algo->ops->init_ae_dev(ae_dev);
if (ret) {
dev_err(&ae_dev->pdev->dev, "init ae_dev error.\n");
continue;
}
hnae_set_bit(ae_dev->flag, HNAE3_DEV_INITED_B, 1);
list_for_each_entry(client, &hnae3_client_list, node) {
ret = hnae3_match_n_instantiate(client, ae_dev, true);
if (ret)
dev_err(&ae_dev->pdev->dev,
"match and instantiation failed\n");
}
}
mutex_unlock(&hnae3_common_lock);
return ret;
}
void hnae3_unregister_ae_algo(struct hnae3_ae_algo *ae_algo)
{
const struct pci_device_id *id;
struct hnae3_ae_dev *ae_dev;
struct hnae3_client *client;
mutex_lock(&hnae3_common_lock);
list_for_each_entry(ae_dev, &hnae3_ae_dev_list, node) {
id = pci_match_id(ae_algo->pdev_id_table, ae_dev->pdev);
if (!id)
continue;
list_for_each_entry(client, &hnae3_client_list, node)
hnae3_match_n_instantiate(client, ae_dev, false);
ae_algo->ops->uninit_ae_dev(ae_dev);
hnae_set_bit(ae_dev->flag, HNAE3_DEV_INITED_B, 0);
}
list_del(&ae_algo->node);
mutex_unlock(&hnae3_common_lock);
}
int hnae3_register_ae_dev(struct hnae3_ae_dev *ae_dev)
{
const struct pci_device_id *id;
struct hnae3_ae_algo *ae_algo;
struct hnae3_client *client;
int ret = 0;
mutex_lock(&hnae3_common_lock);
list_add_tail(&ae_dev->node, &hnae3_ae_dev_list);
list_for_each_entry(ae_algo, &hnae3_ae_algo_list, node) {
id = pci_match_id(ae_algo->pdev_id_table, ae_dev->pdev);
if (!id)
continue;
ae_dev->ops = ae_algo->ops;
if (!ae_dev->ops) {
dev_err(&ae_dev->pdev->dev, "ae_dev ops are null\n");
goto out_err;
}
ret = ae_dev->ops->init_ae_dev(ae_dev);
if (ret) {
dev_err(&ae_dev->pdev->dev, "init ae_dev error\n");
goto out_err;
}
hnae_set_bit(ae_dev->flag, HNAE3_DEV_INITED_B, 1);
break;
}
list_for_each_entry(client, &hnae3_client_list, node) {
ret = hnae3_match_n_instantiate(client, ae_dev, true);
if (ret)
dev_err(&ae_dev->pdev->dev,
"match and instantiation failed\n");
}
out_err:
mutex_unlock(&hnae3_common_lock);
return ret;
}
void hnae3_unregister_ae_dev(struct hnae3_ae_dev *ae_dev)
{
const struct pci_device_id *id;
struct hnae3_ae_algo *ae_algo;
struct hnae3_client *client;
mutex_lock(&hnae3_common_lock);
list_for_each_entry(ae_algo, &hnae3_ae_algo_list, node) {
id = pci_match_id(ae_algo->pdev_id_table, ae_dev->pdev);
if (!id)
continue;
list_for_each_entry(client, &hnae3_client_list, node)
hnae3_match_n_instantiate(client, ae_dev, false);
ae_algo->ops->uninit_ae_dev(ae_dev);
hnae_set_bit(ae_dev->flag, HNAE3_DEV_INITED_B, 0);
}
list_del(&ae_dev->node);
mutex_unlock(&hnae3_common_lock);
}
