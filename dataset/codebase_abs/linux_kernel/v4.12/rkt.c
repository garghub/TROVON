static int F_1 ( struct V_1 * V_2 , int V_3 )\r\n{\r\nint V_4 ;\r\nV_4 = F_2 ( V_2 , V_3 ) ;\r\nif ( V_3 == V_5 ) {\r\nif ( V_2 -> V_6 -> V_7 > V_8 ) {\r\nV_2 -> V_9 -> V_10 . V_11 =\r\nF_3 ( V_8 + V_12 ) ;\r\nV_2 -> V_6 -> V_7 = V_8 ;\r\n}\r\n}\r\nreturn V_4 ;\r\n}\r\nstatic int F_4 ( struct V_1 * V_2 , T_1 V_13 )\r\n{\r\nif ( ! V_13 ) {\r\nF_5 ( V_2 -> V_14 . V_15 ) ;\r\nreturn 0 ;\r\n}\r\nV_2 -> V_16 = V_2 -> V_14 . V_15 = F_6 ( V_2 -> V_17 , V_13 ) ;\r\nif ( V_2 -> V_16 == NULL )\r\nreturn - 1 ;\r\nV_2 -> V_18 = & V_2 -> V_14 . V_15 -> V_18 ;\r\nreturn 0 ;\r\n}\r\nint F_7 ( struct V_1 * V_2 )\r\n{\r\nV_2 -> V_19 . V_20 = F_4 ;\r\nV_2 -> V_19 . V_21 = F_1 ;\r\nreturn F_8 ( V_2 ) ;\r\n}
