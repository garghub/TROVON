struct V_1 * F_1 ( struct V_2 * V_3 )\r\n{\r\nstruct V_4 * V_5 = F_2 ( V_3 ) ;\r\nint V_6 = V_3 -> V_7 >> V_8 ;\r\nif ( F_3 ( ! V_5 -> V_9 ) )\r\nreturn NULL ;\r\nreturn F_4 ( V_5 -> V_9 , V_6 ) ;\r\n}\r\nvoid * F_5 ( struct V_2 * V_3 )\r\n{\r\nreturn F_6 ( V_3 ) ;\r\n}\r\nvoid F_7 ( struct V_2 * V_3 , void * V_10 )\r\n{\r\n}\r\nint F_8 ( struct V_2 * V_3 ,\r\nstruct V_11 * V_12 )\r\n{\r\nstruct V_4 * V_5 = F_2 ( V_3 ) ;\r\nint V_13 ;\r\nV_13 = F_9 ( V_3 , V_3 -> V_7 , V_12 ) ;\r\nif ( V_13 < 0 )\r\nreturn V_13 ;\r\nreturn V_5 -> V_14 -> V_15 ( V_5 , V_12 ) ;\r\n}\r\nint F_10 ( struct V_2 * V_3 )\r\n{\r\nif ( ! V_3 -> V_16 ) {\r\nstruct V_4 * V_5 = F_2 ( V_3 ) ;\r\nF_11 ( & V_5 -> V_17 ) ;\r\nF_12 ( V_5 ) ;\r\nF_13 ( & V_5 -> V_17 ) ;\r\n}\r\nreturn 0 ;\r\n}\r\nvoid F_14 ( struct V_2 * V_3 )\r\n{\r\nif ( ! V_3 -> V_16 ) {\r\nstruct V_4 * V_5 = F_2 ( V_3 ) ;\r\nF_11 ( & V_5 -> V_17 ) ;\r\nF_15 ( F_2 ( V_3 ) ) ;\r\nF_13 ( & V_5 -> V_17 ) ;\r\n}\r\n}\r\nstatic void F_16 ( struct V_4 * V_5 )\r\n{\r\nif ( V_5 -> V_10 )\r\nF_17 ( V_5 -> V_18 . V_16 -> V_19 ,\r\nV_5 -> V_10 ) ;\r\nif ( V_5 -> V_9 )\r\nF_18 ( V_5 -> V_9 ) ;\r\nF_19 ( & V_5 -> V_18 , V_5 -> V_20 ) ;\r\n}\r\nstatic void * F_20 ( struct V_4 * V_5 )\r\n{\r\nF_21 ( & V_5 -> V_17 ) ;\r\nreturn F_22 ( V_5 -> V_18 . V_16 -> V_19 ) ;\r\n}\r\nstatic int F_23 ( struct V_4 * V_5 ,\r\nstruct V_11 * V_12 )\r\n{\r\nreturn F_24 ( V_5 -> V_18 . V_21 , V_12 , 0 ) ;\r\n}\r\nstruct V_2 * F_25 ( struct V_22 * V_23 ,\r\nstruct V_24 * V_25 , struct V_1 * V_20 )\r\n{\r\nstruct V_4 * V_5 ;\r\nT_1 V_7 = F_26 ( V_25 -> V_19 -> V_7 ) ;\r\nint V_13 , V_6 ;\r\nV_13 = F_27 ( V_23 , V_7 , V_26 ,\r\nV_25 -> V_19 -> V_27 ,\r\n& V_28 , & V_5 ) ;\r\nif ( V_13 < 0 )\r\nreturn F_28 ( V_13 ) ;\r\nV_6 = V_7 / V_29 ;\r\nV_5 -> V_20 = V_20 ;\r\nV_5 -> V_9 = F_29 ( V_6 , sizeof( struct V_30 * ) ) ;\r\nif ( ! V_5 -> V_9 ) {\r\nV_13 = - V_31 ;\r\ngoto V_32;\r\n}\r\nV_13 = F_30 ( V_20 , V_5 -> V_9 ,\r\nNULL , V_6 ) ;\r\nif ( V_13 )\r\ngoto V_32;\r\nV_13 = F_31 ( V_23 , & V_5 -> V_18 ) ;\r\nif ( V_13 )\r\ngoto V_32;\r\nreturn & V_5 -> V_18 ;\r\nV_32:\r\nF_32 ( & V_5 -> V_18 ) ;\r\nreturn F_28 ( V_13 ) ;\r\n}
