static inline int F_1 ( T_1 V_1 )\r\n{\r\nreturn ( ( V_1 & ~ 0x01 ) * 1000 ) / 128 ;\r\n}\r\nstatic inline T_2 F_2 ( int V_1 )\r\n{\r\nreturn ( V_1 * 128 ) / 1000 ;\r\n}\r\nstatic struct V_2 * F_3 ( struct V_3 * V_4 )\r\n{\r\nstruct V_2 * V_2 = F_4 ( V_4 ) ;\r\nF_5 ( & V_2 -> V_5 ) ;\r\nif ( F_6 ( V_6 , V_2 -> V_7 + V_8 / 3 ) ) {\r\nint V_9 ;\r\nfor ( V_9 = 0 ; V_9 < F_7 ( V_2 -> V_10 ) ; ++ V_9 ) {\r\nint V_11 = F_8 ( V_4 ,\r\nV_12 [ V_9 ] ) ;\r\nif ( V_11 > - 1 )\r\nV_2 -> V_10 [ V_9 ] = F_1 ( V_11 ) ;\r\n}\r\nV_2 -> V_7 = V_6 ;\r\n}\r\nF_9 ( & V_2 -> V_5 ) ;\r\nreturn V_2 ;\r\n}\r\nstatic T_3 F_10 ( struct V_13 * V_14 ,\r\nstruct V_15 * V_16 ,\r\nchar * V_17 )\r\n{\r\nstruct V_18 * V_19 = F_11 ( V_16 ) ;\r\nstruct V_2 * V_2 = F_3 ( F_12 ( V_14 ) ) ;\r\nreturn sprintf ( V_17 , L_1 , V_2 -> V_10 [ V_19 -> V_20 ] ) ;\r\n}\r\nstatic T_3 F_13 ( struct V_13 * V_14 ,\r\nstruct V_15 * V_16 ,\r\nconst char * V_17 , T_4 V_21 )\r\n{\r\nstruct V_18 * V_19 = F_11 ( V_16 ) ;\r\nstruct V_3 * V_4 = F_12 ( V_14 ) ;\r\nstruct V_2 * V_2 = F_4 ( V_4 ) ;\r\nlong V_1 ;\r\nint V_11 ;\r\nif ( F_14 ( V_17 , 10 , & V_1 ) < 0 )\r\nreturn - V_22 ;\r\nV_1 = F_15 ( V_1 , - 256000 , 255000 ) ;\r\nF_5 ( & V_2 -> V_5 ) ;\r\nV_2 -> V_10 [ V_19 -> V_20 ] = V_1 ;\r\nV_11 = F_16 ( V_4 , V_12 [ V_19 -> V_20 ] ,\r\nF_2 ( V_1 ) ) ;\r\nF_9 ( & V_2 -> V_5 ) ;\r\nreturn V_11 ? : V_21 ;\r\n}\r\nstatic int F_17 ( struct V_3 * V_4 ,\r\nconst struct V_23 * V_24 )\r\n{\r\nstruct V_2 * V_2 ;\r\nint V_11 ;\r\nif ( ! F_18 ( V_4 -> V_25 ,\r\nV_26 ) ) {\r\nF_19 ( & V_4 -> V_14 ,\r\nL_2 ) ;\r\nreturn - V_27 ;\r\n}\r\nV_2 = F_20 ( & V_4 -> V_14 , sizeof( * V_2 ) , V_28 ) ;\r\nif ( ! V_2 )\r\nreturn - V_29 ;\r\nF_21 ( V_4 , V_2 ) ;\r\nV_11 = F_8 ( V_4 , V_30 ) ;\r\nif ( V_11 < 0 ) {\r\nF_19 ( & V_4 -> V_14 , L_3 ) ;\r\nreturn V_11 ;\r\n}\r\nV_2 -> V_31 = V_11 ;\r\nV_11 = F_16 ( V_4 , V_30 ,\r\nV_32 ) ;\r\nif ( V_11 < 0 ) {\r\nF_19 ( & V_4 -> V_14 , L_4 ) ;\r\ngoto V_33;\r\n}\r\nV_11 = F_8 ( V_4 , V_30 ) ;\r\nif ( V_11 < 0 ) {\r\nF_19 ( & V_4 -> V_14 , L_3 ) ;\r\ngoto V_33;\r\n}\r\nV_11 &= ~ V_34 ;\r\nif ( V_11 != V_32 ) {\r\nF_19 ( & V_4 -> V_14 , L_5 ) ;\r\nV_11 = - V_27 ;\r\ngoto V_33;\r\n}\r\nV_2 -> V_7 = V_6 - V_8 ;\r\nF_22 ( & V_2 -> V_5 ) ;\r\nV_11 = F_23 ( & V_4 -> V_14 . V_35 , & V_36 ) ;\r\nif ( V_11 ) {\r\nF_24 ( & V_4 -> V_14 , L_6 ) ;\r\ngoto V_33;\r\n}\r\nV_2 -> V_37 = F_25 ( & V_4 -> V_14 ) ;\r\nif ( F_26 ( V_2 -> V_37 ) ) {\r\nF_24 ( & V_4 -> V_14 , L_7 ) ;\r\nV_11 = F_27 ( V_2 -> V_37 ) ;\r\ngoto V_38;\r\n}\r\nF_28 ( & V_4 -> V_14 , L_8 ) ;\r\nreturn 0 ;\r\nV_38:\r\nF_29 ( & V_4 -> V_14 . V_35 , & V_36 ) ;\r\nV_33:\r\nF_16 ( V_4 , V_30 ,\r\nV_2 -> V_31 ) ;\r\nreturn V_11 ;\r\n}\r\nstatic int F_30 ( struct V_3 * V_4 )\r\n{\r\nstruct V_2 * V_2 = F_4 ( V_4 ) ;\r\nF_31 ( V_2 -> V_37 ) ;\r\nF_29 ( & V_4 -> V_14 . V_35 , & V_36 ) ;\r\nif ( V_2 -> V_31 & V_39 ) {\r\nint V_40 ;\r\nV_40 = F_8 ( V_4 , V_30 ) ;\r\nif ( V_40 >= 0 )\r\nF_16 ( V_4 , V_30 ,\r\nV_40 | V_39 ) ;\r\n}\r\nreturn 0 ;\r\n}\r\nstatic int F_32 ( struct V_13 * V_14 )\r\n{\r\nstruct V_3 * V_4 = F_12 ( V_14 ) ;\r\nint V_40 ;\r\nV_40 = F_8 ( V_4 , V_30 ) ;\r\nif ( V_40 < 0 )\r\nreturn V_40 ;\r\nV_40 |= V_39 ;\r\nreturn F_16 ( V_4 , V_30 , V_40 ) ;\r\n}\r\nstatic int F_33 ( struct V_13 * V_14 )\r\n{\r\nstruct V_3 * V_4 = F_12 ( V_14 ) ;\r\nint V_40 ;\r\nV_40 = F_8 ( V_4 , V_30 ) ;\r\nif ( V_40 < 0 )\r\nreturn V_40 ;\r\nV_40 &= ~ V_39 ;\r\nreturn F_16 ( V_4 , V_30 , V_40 ) ;\r\n}
