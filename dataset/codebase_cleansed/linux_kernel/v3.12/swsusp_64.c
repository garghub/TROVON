void do_after_copyback(void)\r\n{\r\niommu_restore();\r\ntouch_softlockup_watchdog();\r\nmb();\r\n}\r\nvoid _iommu_save(void)\r\n{\r\niommu_save();\r\n}
