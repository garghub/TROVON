static int hclge_mdio_write(struct mii_bus *bus, int phyid, int regnum,
u16 data)
{
struct hclge_mdio_cfg_cmd *mdio_cmd;
struct hclge_dev *hdev = bus->priv;
struct hclge_desc desc;
int ret;
hclge_cmd_setup_basic_desc(&desc, HCLGE_OPC_MDIO_CONFIG, false);
mdio_cmd = (struct hclge_mdio_cfg_cmd *)desc.data;
hnae_set_field(mdio_cmd->phyid, HCLGE_MDIO_PHYID_M,
HCLGE_MDIO_PHYID_S, phyid);
hnae_set_field(mdio_cmd->phyad, HCLGE_MDIO_PHYREG_M,
HCLGE_MDIO_PHYREG_S, regnum);
hnae_set_bit(mdio_cmd->ctrl_bit, HCLGE_MDIO_CTRL_START_B, 1);
hnae_set_field(mdio_cmd->ctrl_bit, HCLGE_MDIO_CTRL_ST_M,
HCLGE_MDIO_CTRL_ST_S, 1);
hnae_set_field(mdio_cmd->ctrl_bit, HCLGE_MDIO_CTRL_OP_M,
HCLGE_MDIO_CTRL_OP_S, HCLGE_MDIO_C22_WRITE);
mdio_cmd->data_wr = cpu_to_le16(data);
ret = hclge_cmd_send(&hdev->hw, &desc, 1);
if (ret) {
dev_err(&hdev->pdev->dev,
"mdio write fail when sending cmd, status is %d.\n",
ret);
return ret;
}
return 0;
}
static int hclge_mdio_read(struct mii_bus *bus, int phyid, int regnum)
{
struct hclge_mdio_cfg_cmd *mdio_cmd;
struct hclge_dev *hdev = bus->priv;
struct hclge_desc desc;
int ret;
hclge_cmd_setup_basic_desc(&desc, HCLGE_OPC_MDIO_CONFIG, true);
mdio_cmd = (struct hclge_mdio_cfg_cmd *)desc.data;
hnae_set_field(mdio_cmd->phyid, HCLGE_MDIO_PHYID_M,
HCLGE_MDIO_PHYID_S, phyid);
hnae_set_field(mdio_cmd->phyad, HCLGE_MDIO_PHYREG_M,
HCLGE_MDIO_PHYREG_S, regnum);
hnae_set_bit(mdio_cmd->ctrl_bit, HCLGE_MDIO_CTRL_START_B, 1);
hnae_set_field(mdio_cmd->ctrl_bit, HCLGE_MDIO_CTRL_ST_M,
HCLGE_MDIO_CTRL_ST_S, 1);
hnae_set_field(mdio_cmd->ctrl_bit, HCLGE_MDIO_CTRL_OP_M,
HCLGE_MDIO_CTRL_OP_S, HCLGE_MDIO_C22_READ);
ret = hclge_cmd_send(&hdev->hw, &desc, 1);
if (ret) {
dev_err(&hdev->pdev->dev,
"mdio read fail when get data, status is %d.\n",
ret);
return ret;
}
if (hnae_get_bit(le16_to_cpu(mdio_cmd->sta), HCLGE_MDIO_STA_B)) {
dev_err(&hdev->pdev->dev, "mdio read data error\n");
return -EIO;
}
return le16_to_cpu(mdio_cmd->data_rd);
}
int hclge_mac_mdio_config(struct hclge_dev *hdev)
{
struct hclge_mac *mac = &hdev->hw.mac;
struct phy_device *phydev;
struct mii_bus *mdio_bus;
int ret;
if (hdev->hw.mac.phy_addr >= PHY_MAX_ADDR)
return 0;
mdio_bus = devm_mdiobus_alloc(&hdev->pdev->dev);
if (!mdio_bus)
return -ENOMEM;
mdio_bus->name = "hisilicon MII bus";
mdio_bus->read = hclge_mdio_read;
mdio_bus->write = hclge_mdio_write;
snprintf(mdio_bus->id, MII_BUS_ID_SIZE, "%s-%s", "mii",
dev_name(&hdev->pdev->dev));
mdio_bus->parent = &hdev->pdev->dev;
mdio_bus->priv = hdev;
mdio_bus->phy_mask = ~(1 << mac->phy_addr);
ret = mdiobus_register(mdio_bus);
if (ret) {
dev_err(mdio_bus->parent,
"Failed to register MDIO bus ret = %#x\n", ret);
return ret;
}
phydev = mdiobus_get_phy(mdio_bus, mac->phy_addr);
if (!phydev) {
dev_err(mdio_bus->parent, "Failed to get phy device\n");
mdiobus_unregister(mdio_bus);
return -EIO;
}
mac->phydev = phydev;
mac->mdio_bus = mdio_bus;
return 0;
}
static void hclge_mac_adjust_link(struct net_device *netdev)
{
struct hnae3_handle *h = *((void **)netdev_priv(netdev));
struct hclge_vport *vport = hclge_get_vport(h);
struct hclge_dev *hdev = vport->back;
int duplex, speed;
int ret;
speed = netdev->phydev->speed;
duplex = netdev->phydev->duplex;
ret = hclge_cfg_mac_speed_dup(hdev, speed, duplex);
if (ret)
netdev_err(netdev, "failed to adjust link.\n");
}
int hclge_mac_start_phy(struct hclge_dev *hdev)
{
struct net_device *netdev = hdev->vport[0].nic.netdev;
struct phy_device *phydev = hdev->hw.mac.phydev;
int ret;
if (!phydev)
return 0;
ret = phy_connect_direct(netdev, phydev,
hclge_mac_adjust_link,
PHY_INTERFACE_MODE_SGMII);
if (ret) {
netdev_err(netdev, "phy_connect_direct err.\n");
return ret;
}
phy_start(phydev);
return 0;
}
void hclge_mac_stop_phy(struct hclge_dev *hdev)
{
struct net_device *netdev = hdev->vport[0].nic.netdev;
struct phy_device *phydev = netdev->phydev;
if (!phydev)
return;
phy_stop(phydev);
phy_disconnect(phydev);
}
