static int ucb1x00_assabet_add(struct ucb1x00_dev *dev)
{
device_create_file(&dev->ucb->dev, &dev_attr_vbatt);
device_create_file(&dev->ucb->dev, &dev_attr_vcharger);
device_create_file(&dev->ucb->dev, &dev_attr_batt_temp);
return 0;
}
static void ucb1x00_assabet_remove(struct ucb1x00_dev *dev)
{
device_remove_file(&dev->ucb->dev, &dev_attr_batt_temp);
device_remove_file(&dev->ucb->dev, &dev_attr_vcharger);
device_remove_file(&dev->ucb->dev, &dev_attr_vbatt);
}
static int __init ucb1x00_assabet_init(void)
{
return ucb1x00_register_driver(&ucb1x00_assabet_driver);
}
static void __exit ucb1x00_assabet_exit(void)
{
ucb1x00_unregister_driver(&ucb1x00_assabet_driver);
}
