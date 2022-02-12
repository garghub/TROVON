static int qcom_usb_hsic_phy_power_on(struct phy *phy)
{
struct qcom_usb_hsic_phy *uphy = phy_get_drvdata(phy);
struct ulpi *ulpi = uphy->ulpi;
struct pinctrl_state *pins_default;
int ret;
ret = clk_prepare_enable(uphy->phy_clk);
if (ret)
return ret;
ret = clk_prepare_enable(uphy->cal_clk);
if (ret)
goto err_cal;
ret = clk_prepare_enable(uphy->cal_sleep_clk);
if (ret)
goto err_sleep;
ret = ulpi_write(ulpi, ULPI_HSIC_IO_CAL, 0xff);
if (ret)
goto err_ulpi;
ret = ulpi_write(ulpi, ULPI_HSIC_CFG, 0xa8);
if (ret)
goto err_ulpi;
pins_default = pinctrl_lookup_state(uphy->pctl, PINCTRL_STATE_DEFAULT);
if (IS_ERR(pins_default))
return PTR_ERR(pins_default);
ret = pinctrl_select_state(uphy->pctl, pins_default);
if (ret)
goto err_ulpi;
ret = ulpi_write(ulpi, ULPI_SET(ULPI_HSIC_CFG), 0x01);
if (ret)
goto err_ulpi;
ret = ulpi_write(ulpi, ULPI_CLR(ULPI_IFC_CTRL),
ULPI_IFC_CTRL_AUTORESUME);
if (ret)
goto err_ulpi;
return ret;
err_ulpi:
clk_disable_unprepare(uphy->cal_sleep_clk);
err_sleep:
clk_disable_unprepare(uphy->cal_clk);
err_cal:
clk_disable_unprepare(uphy->phy_clk);
return ret;
}
static int qcom_usb_hsic_phy_power_off(struct phy *phy)
{
struct qcom_usb_hsic_phy *uphy = phy_get_drvdata(phy);
clk_disable_unprepare(uphy->cal_sleep_clk);
clk_disable_unprepare(uphy->cal_clk);
clk_disable_unprepare(uphy->phy_clk);
return 0;
}
static int qcom_usb_hsic_phy_probe(struct ulpi *ulpi)
{
struct qcom_usb_hsic_phy *uphy;
struct phy_provider *p;
struct clk *clk;
uphy = devm_kzalloc(&ulpi->dev, sizeof(*uphy), GFP_KERNEL);
if (!uphy)
return -ENOMEM;
ulpi_set_drvdata(ulpi, uphy);
uphy->ulpi = ulpi;
uphy->pctl = devm_pinctrl_get(&ulpi->dev);
if (IS_ERR(uphy->pctl))
return PTR_ERR(uphy->pctl);
uphy->phy_clk = clk = devm_clk_get(&ulpi->dev, "phy");
if (IS_ERR(clk))
return PTR_ERR(clk);
uphy->cal_clk = clk = devm_clk_get(&ulpi->dev, "cal");
if (IS_ERR(clk))
return PTR_ERR(clk);
uphy->cal_sleep_clk = clk = devm_clk_get(&ulpi->dev, "cal_sleep");
if (IS_ERR(clk))
return PTR_ERR(clk);
uphy->phy = devm_phy_create(&ulpi->dev, ulpi->dev.of_node,
&qcom_usb_hsic_phy_ops);
if (IS_ERR(uphy->phy))
return PTR_ERR(uphy->phy);
phy_set_drvdata(uphy->phy, uphy);
p = devm_of_phy_provider_register(&ulpi->dev, of_phy_simple_xlate);
return PTR_ERR_OR_ZERO(p);
}
