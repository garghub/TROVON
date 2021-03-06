static int s5p_cec_adap_enable(struct cec_adapter *adap, bool enable)\r\n{\r\nstruct s5p_cec_dev *cec = adap->priv;\r\nif (enable) {\r\npm_runtime_get_sync(cec->dev);\r\ns5p_cec_reset(cec);\r\ns5p_cec_set_divider(cec);\r\ns5p_cec_threshold(cec);\r\ns5p_cec_unmask_tx_interrupts(cec);\r\ns5p_cec_unmask_rx_interrupts(cec);\r\ns5p_cec_enable_rx(cec);\r\n} else {\r\ns5p_cec_mask_tx_interrupts(cec);\r\ns5p_cec_mask_rx_interrupts(cec);\r\npm_runtime_disable(cec->dev);\r\n}\r\nreturn 0;\r\n}\r\nstatic int s5p_cec_adap_log_addr(struct cec_adapter *adap, u8 addr)\r\n{\r\nstruct s5p_cec_dev *cec = adap->priv;\r\ns5p_cec_set_addr(cec, addr);\r\nreturn 0;\r\n}\r\nstatic int s5p_cec_adap_transmit(struct cec_adapter *adap, u8 attempts,\r\nu32 signal_free_time, struct cec_msg *msg)\r\n{\r\nstruct s5p_cec_dev *cec = adap->priv;\r\ns5p_cec_copy_packet(cec, msg->msg, msg->len, max(1, attempts - 1));\r\nreturn 0;\r\n}\r\nstatic irqreturn_t s5p_cec_irq_handler(int irq, void *priv)\r\n{\r\nstruct s5p_cec_dev *cec = priv;\r\nu32 status = 0;\r\nstatus = s5p_cec_get_status(cec);\r\ndev_dbg(cec->dev, "irq received\n");\r\nif (status & CEC_STATUS_TX_DONE) {\r\nif (status & CEC_STATUS_TX_ERROR) {\r\ndev_dbg(cec->dev, "CEC_STATUS_TX_ERROR set\n");\r\ncec->tx = STATE_ERROR;\r\n} else {\r\ndev_dbg(cec->dev, "CEC_STATUS_TX_DONE\n");\r\ncec->tx = STATE_DONE;\r\n}\r\ns5p_clr_pending_tx(cec);\r\n}\r\nif (status & CEC_STATUS_RX_DONE) {\r\nif (status & CEC_STATUS_RX_ERROR) {\r\ndev_dbg(cec->dev, "CEC_STATUS_RX_ERROR set\n");\r\ns5p_cec_rx_reset(cec);\r\ns5p_cec_enable_rx(cec);\r\n} else {\r\ndev_dbg(cec->dev, "CEC_STATUS_RX_DONE set\n");\r\nif (cec->rx != STATE_IDLE)\r\ndev_dbg(cec->dev, "Buffer overrun (worker did not process previous message)\n");\r\ncec->rx = STATE_BUSY;\r\ncec->msg.len = status >> 24;\r\ncec->msg.rx_status = CEC_RX_STATUS_OK;\r\ns5p_cec_get_rx_buf(cec, cec->msg.len,\r\ncec->msg.msg);\r\ncec->rx = STATE_DONE;\r\ns5p_cec_enable_rx(cec);\r\n}\r\ns5p_clr_pending_rx(cec);\r\n}\r\nreturn IRQ_WAKE_THREAD;\r\n}\r\nstatic irqreturn_t s5p_cec_irq_handler_thread(int irq, void *priv)\r\n{\r\nstruct s5p_cec_dev *cec = priv;\r\ndev_dbg(cec->dev, "irq processing thread\n");\r\nswitch (cec->tx) {\r\ncase STATE_DONE:\r\ncec_transmit_done(cec->adap, CEC_TX_STATUS_OK, 0, 0, 0, 0);\r\ncec->tx = STATE_IDLE;\r\nbreak;\r\ncase STATE_ERROR:\r\ncec_transmit_done(cec->adap,\r\nCEC_TX_STATUS_MAX_RETRIES | CEC_TX_STATUS_ERROR,\r\n0, 0, 0, 1);\r\ncec->tx = STATE_IDLE;\r\nbreak;\r\ncase STATE_BUSY:\r\ndev_err(cec->dev, "state set to busy, this should not occur here\n");\r\nbreak;\r\ndefault:\r\nbreak;\r\n}\r\nswitch (cec->rx) {\r\ncase STATE_DONE:\r\ncec_received_msg(cec->adap, &cec->msg);\r\ncec->rx = STATE_IDLE;\r\nbreak;\r\ndefault:\r\nbreak;\r\n}\r\nreturn IRQ_HANDLED;\r\n}\r\nstatic int s5p_cec_probe(struct platform_device *pdev)\r\n{\r\nstruct device *dev = &pdev->dev;\r\nstruct resource *res;\r\nstruct s5p_cec_dev *cec;\r\nint ret;\r\ncec = devm_kzalloc(&pdev->dev, sizeof(*cec), GFP_KERNEL);\r\nif (!cec)\r\nreturn -ENOMEM;\r\ncec->dev = dev;\r\ncec->irq = platform_get_irq(pdev, 0);\r\nif (cec->irq < 0)\r\nreturn cec->irq;\r\nret = devm_request_threaded_irq(dev, cec->irq, s5p_cec_irq_handler,\r\ns5p_cec_irq_handler_thread, 0, pdev->name, cec);\r\nif (ret)\r\nreturn ret;\r\ncec->clk = devm_clk_get(dev, "hdmicec");\r\nif (IS_ERR(cec->clk))\r\nreturn PTR_ERR(cec->clk);\r\ncec->pmu = syscon_regmap_lookup_by_phandle(dev->of_node,\r\n"samsung,syscon-phandle");\r\nif (IS_ERR(cec->pmu))\r\nreturn -EPROBE_DEFER;\r\nres = platform_get_resource(pdev, IORESOURCE_MEM, 0);\r\ncec->reg = devm_ioremap_resource(dev, res);\r\nif (IS_ERR(cec->reg))\r\nreturn PTR_ERR(cec->reg);\r\ncec->adap = cec_allocate_adapter(&s5p_cec_adap_ops, cec,\r\nCEC_NAME,\r\nCEC_CAP_PHYS_ADDR | CEC_CAP_LOG_ADDRS | CEC_CAP_TRANSMIT |\r\nCEC_CAP_PASSTHROUGH | CEC_CAP_RC, 1);\r\nret = PTR_ERR_OR_ZERO(cec->adap);\r\nif (ret)\r\nreturn ret;\r\nret = cec_register_adapter(cec->adap, &pdev->dev);\r\nif (ret) {\r\ncec_delete_adapter(cec->adap);\r\nreturn ret;\r\n}\r\nplatform_set_drvdata(pdev, cec);\r\npm_runtime_enable(dev);\r\ndev_dbg(dev, "successfuly probed\n");\r\nreturn 0;\r\n}\r\nstatic int s5p_cec_remove(struct platform_device *pdev)\r\n{\r\nstruct s5p_cec_dev *cec = platform_get_drvdata(pdev);\r\ncec_unregister_adapter(cec->adap);\r\npm_runtime_disable(&pdev->dev);\r\nreturn 0;\r\n}\r\nstatic int __maybe_unused s5p_cec_runtime_suspend(struct device *dev)\r\n{\r\nstruct s5p_cec_dev *cec = dev_get_drvdata(dev);\r\nclk_disable_unprepare(cec->clk);\r\nreturn 0;\r\n}\r\nstatic int __maybe_unused s5p_cec_runtime_resume(struct device *dev)\r\n{\r\nstruct s5p_cec_dev *cec = dev_get_drvdata(dev);\r\nint ret;\r\nret = clk_prepare_enable(cec->clk);\r\nif (ret < 0)\r\nreturn ret;\r\nreturn 0;\r\n}
