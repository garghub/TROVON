int __init bcm63xx_wdt_register(void)
{
wdt_resources[0].start = bcm63xx_regset_address(RSET_WDT);
wdt_resources[0].end = wdt_resources[0].start;
wdt_resources[0].end += RSET_WDT_SIZE - 1;
return platform_device_register(&bcm63xx_wdt_device);
}
