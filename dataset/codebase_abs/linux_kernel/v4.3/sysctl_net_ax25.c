int F_1 ( T_1 * T_1 )\r\n{\r\nchar V_1 [ sizeof( L_1 ) + V_2 ] ;\r\nint V_3 ;\r\nstruct V_4 * V_5 ;\r\nV_5 = F_2 ( V_6 , sizeof( V_6 ) , V_7 ) ;\r\nif ( ! V_5 )\r\nreturn - V_8 ;\r\nfor ( V_3 = 0 ; V_3 < V_9 ; V_3 ++ )\r\nV_5 [ V_3 ] . V_10 = & T_1 -> V_11 [ V_3 ] ;\r\nsnprintf ( V_1 , sizeof( V_1 ) , L_2 , T_1 -> V_12 -> V_13 ) ;\r\nT_1 -> V_14 = F_3 ( & V_15 , V_1 , V_5 ) ;\r\nif ( ! T_1 -> V_14 ) {\r\nF_4 ( V_5 ) ;\r\nreturn - V_8 ;\r\n}\r\nreturn 0 ;\r\n}\r\nvoid F_5 ( T_1 * T_1 )\r\n{\r\nstruct V_16 * V_17 = T_1 -> V_14 ;\r\nstruct V_4 * V_5 ;\r\nif ( V_17 ) {\r\nT_1 -> V_14 = NULL ;\r\nV_5 = V_17 -> V_18 ;\r\nF_6 ( V_17 ) ;\r\nF_4 ( V_5 ) ;\r\n}\r\n}
