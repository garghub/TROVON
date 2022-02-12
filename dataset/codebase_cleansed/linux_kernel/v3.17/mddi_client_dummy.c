static int mddi_dummy_suspend(struct msm_panel_data *panel_data)
{
return 0;
}
static int mddi_dummy_resume(struct msm_panel_data *panel_data)
{
return 0;
}
static int mddi_dummy_blank(struct msm_panel_data *panel_data)
{
return 0;
}
static int mddi_dummy_unblank(struct msm_panel_data *panel_data)
{
return 0;
}
static int mddi_dummy_probe(struct platform_device *pdev)
{
struct msm_mddi_client_data *client_data = pdev->dev.platform_data;
struct panel_info *panel =
devm_kzalloc(&pdev->dev, sizeof(struct panel_info), GFP_KERNEL);
if (!panel)
return -ENOMEM;
platform_set_drvdata(pdev, panel);
panel->panel_data.suspend = mddi_dummy_suspend;
panel->panel_data.resume = mddi_dummy_resume;
panel->panel_data.blank = mddi_dummy_blank;
panel->panel_data.unblank = mddi_dummy_unblank;
panel->panel_data.caps = MSMFB_CAP_PARTIAL_UPDATES;
panel->pdev.name = "msm_panel";
panel->pdev.id = pdev->id;
platform_device_add_resources(&panel->pdev,
client_data->fb_resource, 1);
panel->panel_data.fb_data = client_data->private_client_data;
panel->pdev.dev.platform_data = &panel->panel_data;
return platform_device_register(&panel->pdev);
}
static int __init mddi_client_dummy_init(void)
{
platform_driver_register(&mddi_client_dummy);
return 0;
}
