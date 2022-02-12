static int lcc_mdm9615_probe(struct platform_device *pdev)
{
u32 val;
struct regmap *regmap;
regmap = qcom_cc_map(pdev, &lcc_mdm9615_desc);
if (IS_ERR(regmap))
return PTR_ERR(regmap);
regmap_read(regmap, 0x4, &val);
if (val == 0x12) {
slimbus_src.freq_tbl = clk_tbl_aif_osr_492;
mi2s_osr_src.freq_tbl = clk_tbl_aif_osr_492;
codec_i2s_mic_osr_src.freq_tbl = clk_tbl_aif_osr_492;
spare_i2s_mic_osr_src.freq_tbl = clk_tbl_aif_osr_492;
codec_i2s_spkr_osr_src.freq_tbl = clk_tbl_aif_osr_492;
spare_i2s_spkr_osr_src.freq_tbl = clk_tbl_aif_osr_492;
pcm_src.freq_tbl = clk_tbl_pcm_492;
}
regmap_write(regmap, 0xc4, 0x1);
return qcom_cc_really_probe(pdev, &lcc_mdm9615_desc, regmap);
}
