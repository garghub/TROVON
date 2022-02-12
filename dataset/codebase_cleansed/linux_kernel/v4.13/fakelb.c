static int fakelb_hw_ed(struct ieee802154_hw *hw, u8 *level)
{
BUG_ON(!level);
*level = 0xbe;
return 0;
}
static int fakelb_hw_channel(struct ieee802154_hw *hw, u8 page, u8 channel)
{
struct fakelb_phy *phy = hw->priv;
write_lock_bh(&fakelb_ifup_phys_lock);
phy->page = page;
phy->channel = channel;
write_unlock_bh(&fakelb_ifup_phys_lock);
return 0;
}
static int fakelb_hw_xmit(struct ieee802154_hw *hw, struct sk_buff *skb)
{
struct fakelb_phy *current_phy = hw->priv, *phy;
read_lock_bh(&fakelb_ifup_phys_lock);
WARN_ON(current_phy->suspended);
list_for_each_entry(phy, &fakelb_ifup_phys, list_ifup) {
if (current_phy == phy)
continue;
if (current_phy->page == phy->page &&
current_phy->channel == phy->channel) {
struct sk_buff *newskb = pskb_copy(skb, GFP_ATOMIC);
if (newskb)
ieee802154_rx_irqsafe(phy->hw, newskb, 0xcc);
}
}
read_unlock_bh(&fakelb_ifup_phys_lock);
ieee802154_xmit_complete(hw, skb, false);
return 0;
}
static int fakelb_hw_start(struct ieee802154_hw *hw)
{
struct fakelb_phy *phy = hw->priv;
write_lock_bh(&fakelb_ifup_phys_lock);
phy->suspended = false;
list_add(&phy->list_ifup, &fakelb_ifup_phys);
write_unlock_bh(&fakelb_ifup_phys_lock);
return 0;
}
static void fakelb_hw_stop(struct ieee802154_hw *hw)
{
struct fakelb_phy *phy = hw->priv;
write_lock_bh(&fakelb_ifup_phys_lock);
phy->suspended = true;
list_del(&phy->list_ifup);
write_unlock_bh(&fakelb_ifup_phys_lock);
}
static int
fakelb_set_promiscuous_mode(struct ieee802154_hw *hw, const bool on)
{
return 0;
}
static int fakelb_add_one(struct device *dev)
{
struct ieee802154_hw *hw;
struct fakelb_phy *phy;
int err;
hw = ieee802154_alloc_hw(sizeof(*phy), &fakelb_ops);
if (!hw)
return -ENOMEM;
phy = hw->priv;
phy->hw = hw;
hw->phy->supported.channels[0] |= 1;
hw->phy->supported.channels[0] |= 0x7fe;
hw->phy->supported.channels[0] |= 0x7FFF800;
hw->phy->supported.channels[1] |= 1;
hw->phy->supported.channels[1] |= 0x7fe;
hw->phy->supported.channels[2] |= 1;
hw->phy->supported.channels[2] |= 0x7fe;
hw->phy->supported.channels[3] |= 0x3fff;
hw->phy->supported.channels[4] |= 1;
hw->phy->supported.channels[4] |= 0x1e;
hw->phy->supported.channels[4] |= 0xffe0;
hw->phy->supported.channels[5] |= 0xf;
hw->phy->supported.channels[5] |= 0xf0;
hw->phy->supported.channels[6] |= 0x3ff;
hw->phy->supported.channels[6] |= 0x3ffc00;
ieee802154_random_extended_addr(&hw->phy->perm_extended_addr);
hw->phy->current_channel = 13;
phy->channel = hw->phy->current_channel;
hw->flags = IEEE802154_HW_PROMISCUOUS;
hw->parent = dev;
err = ieee802154_register_hw(hw);
if (err)
goto err_reg;
mutex_lock(&fakelb_phys_lock);
list_add_tail(&phy->list, &fakelb_phys);
mutex_unlock(&fakelb_phys_lock);
return 0;
err_reg:
ieee802154_free_hw(phy->hw);
return err;
}
static void fakelb_del(struct fakelb_phy *phy)
{
list_del(&phy->list);
ieee802154_unregister_hw(phy->hw);
ieee802154_free_hw(phy->hw);
}
static int fakelb_probe(struct platform_device *pdev)
{
struct fakelb_phy *phy, *tmp;
int err, i;
for (i = 0; i < numlbs; i++) {
err = fakelb_add_one(&pdev->dev);
if (err < 0)
goto err_slave;
}
dev_info(&pdev->dev, "added %i fake ieee802154 hardware devices\n", numlbs);
return 0;
err_slave:
mutex_lock(&fakelb_phys_lock);
list_for_each_entry_safe(phy, tmp, &fakelb_phys, list)
fakelb_del(phy);
mutex_unlock(&fakelb_phys_lock);
return err;
}
static int fakelb_remove(struct platform_device *pdev)
{
struct fakelb_phy *phy, *tmp;
mutex_lock(&fakelb_phys_lock);
list_for_each_entry_safe(phy, tmp, &fakelb_phys, list)
fakelb_del(phy);
mutex_unlock(&fakelb_phys_lock);
return 0;
}
static __init int fakelb_init_module(void)
{
ieee802154fake_dev = platform_device_register_simple(
"ieee802154fakelb", -1, NULL, 0);
return platform_driver_register(&ieee802154fake_driver);
}
static __exit void fake_remove_module(void)
{
platform_driver_unregister(&ieee802154fake_driver);
platform_device_unregister(ieee802154fake_dev);
}
