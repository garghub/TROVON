static bool F_1 ( struct V_1 * V_2 , unsigned int V_3 )\r\n{\r\nswitch ( V_3 ) {\r\ncase V_4 :\r\ncase V_5 :\r\ncase V_6 ... V_7 :\r\ncase V_8 ... V_9 :\r\ncase V_10 :\r\ncase V_11 :\r\ncase V_12 :\r\ncase V_13 :\r\nreturn true ;\r\ndefault:\r\nreturn false ;\r\n}\r\n}\r\nstatic void F_2 ( bool V_14 )\r\n{\r\nF_3 ( V_15 -> V_16 , V_17 ,\r\nV_18 ,\r\nV_14 ? V_18 : 0 ) ;\r\nF_3 ( V_15 -> V_16 , V_19 ,\r\nV_20 , V_20 ) ;\r\n}\r\nstatic void F_4 ( void )\r\n{\r\nF_2 ( false ) ;\r\n}\r\nstatic int F_5 ( struct V_21 * V_22 ,\r\nunsigned long V_23 , void * V_24 )\r\n{\r\nF_2 ( true ) ;\r\nF_6 ( 1 ) ;\r\nreturn V_25 ;\r\n}\r\nstatic int F_7 ( struct V_26 * V_27 ,\r\nconst struct V_28 * V_29 )\r\n{\r\nconst struct V_30 * V_31 ;\r\nstruct V_32 * V_33 ;\r\nint V_34 ;\r\nV_31 = F_8 ( V_35 , & V_27 -> V_2 ) ;\r\nif ( ! V_31 ) {\r\nF_9 ( & V_27 -> V_2 , L_1 ) ;\r\nreturn - V_36 ;\r\n}\r\nV_33 = F_10 ( & V_27 -> V_2 , sizeof( * V_33 ) , V_37 ) ;\r\nif ( ! V_33 )\r\nreturn - V_38 ;\r\nF_11 ( V_27 , V_33 ) ;\r\nV_33 -> V_39 = ( long ) V_31 -> V_40 ;\r\nV_33 -> V_16 = F_12 ( V_27 , & V_41 ) ;\r\nif ( F_13 ( V_33 -> V_16 ) ) {\r\nV_34 = F_14 ( V_33 -> V_16 ) ;\r\nF_9 ( & V_27 -> V_2 , L_2 , V_34 ) ;\r\nreturn V_34 ;\r\n}\r\nV_34 = F_15 ( & V_27 -> V_2 , - 1 , V_42 ,\r\nF_16 ( V_42 ) , NULL , 0 , NULL ) ;\r\nif ( V_34 ) {\r\nF_9 ( & V_27 -> V_2 , L_3 , V_34 ) ;\r\nreturn V_34 ;\r\n}\r\nV_15 = V_33 ;\r\nif ( F_17 ( V_27 -> V_2 . V_43 ) ) {\r\nif ( ! V_44 )\r\nV_44 = F_4 ;\r\nelse\r\nF_18 ( & V_27 -> V_2 , L_4 ) ;\r\n}\r\nV_45 . V_46 = F_5 ;\r\nV_45 . V_47 = 192 ;\r\nV_34 = F_19 ( & V_45 ) ;\r\nif ( V_34 ) {\r\nF_9 ( & V_27 -> V_2 , L_5 , V_34 ) ;\r\nreturn V_34 ;\r\n}\r\nreturn 0 ;\r\n}\r\nstatic int F_20 ( struct V_26 * V_27 )\r\n{\r\nstruct V_32 * V_33 = F_21 ( V_27 ) ;\r\nif ( V_33 == V_15 ) {\r\nV_15 = NULL ;\r\nV_44 = NULL ;\r\n}\r\nreturn 0 ;\r\n}
