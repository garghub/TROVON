static union V_1 F_1 ( union V_1 V_2 , union V_1 V_3 ,\r\nunion V_1 V_4 , enum V_5 V_6 )\r\n{\r\nint V_7 ;\r\nint V_8 ;\r\nT_1 V_9 ;\r\nunsigned V_10 ;\r\nunsigned V_11 ;\r\nunsigned V_12 ;\r\nunsigned V_13 ;\r\nT_1 V_14 ;\r\nT_1 V_15 ;\r\nT_1 V_16 ;\r\nT_1 V_17 ;\r\nint V_18 ;\r\nV_19 ;\r\nV_20 ;\r\nV_21 ;\r\nV_22 ;\r\nV_23 ;\r\nV_24 ;\r\nV_25 ;\r\nV_26 ;\r\nV_27 ;\r\nF_2 () ;\r\nswitch ( V_28 ) {\r\ncase V_29 :\r\nF_3 ( V_30 ) ;\r\nreturn F_4 ( V_2 ) ;\r\ncase V_31 :\r\nV_32 ;\r\n}\r\nswitch ( F_5 ( V_33 , V_34 ) ) {\r\ncase F_5 ( V_35 , V_29 ) :\r\ncase F_5 ( V_36 , V_29 ) :\r\ncase F_5 ( V_37 , V_29 ) :\r\ncase F_5 ( V_31 , V_29 ) :\r\ncase F_5 ( V_38 , V_29 ) :\r\nreturn F_4 ( V_4 ) ;\r\ncase F_5 ( V_29 , V_29 ) :\r\ncase F_5 ( V_29 , V_35 ) :\r\ncase F_5 ( V_29 , V_36 ) :\r\ncase F_5 ( V_29 , V_37 ) :\r\ncase F_5 ( V_29 , V_31 ) :\r\ncase F_5 ( V_29 , V_38 ) :\r\nreturn F_4 ( V_3 ) ;\r\ncase F_5 ( V_36 , V_35 ) :\r\ncase F_5 ( V_37 , V_35 ) :\r\ncase F_5 ( V_31 , V_35 ) :\r\ncase F_5 ( V_38 , V_35 ) :\r\nreturn V_4 ;\r\ncase F_5 ( V_35 , V_35 ) :\r\ncase F_5 ( V_35 , V_36 ) :\r\ncase F_5 ( V_35 , V_37 ) :\r\ncase F_5 ( V_35 , V_31 ) :\r\ncase F_5 ( V_35 , V_38 ) :\r\nreturn V_3 ;\r\ncase F_5 ( V_38 , V_36 ) :\r\ncase F_5 ( V_36 , V_38 ) :\r\nif ( V_28 == V_35 )\r\nreturn V_2 ;\r\nF_3 ( V_30 ) ;\r\nreturn F_6 () ;\r\ncase F_5 ( V_37 , V_38 ) :\r\ncase F_5 ( V_31 , V_38 ) :\r\ncase F_5 ( V_38 , V_37 ) :\r\ncase F_5 ( V_38 , V_31 ) :\r\ncase F_5 ( V_38 , V_38 ) :\r\nif ( V_28 == V_35 )\r\nreturn V_2 ;\r\nreturn F_7 ( V_39 ^ V_40 ) ;\r\ncase F_5 ( V_36 , V_36 ) :\r\ncase F_5 ( V_36 , V_37 ) :\r\ncase F_5 ( V_36 , V_31 ) :\r\ncase F_5 ( V_37 , V_36 ) :\r\ncase F_5 ( V_31 , V_36 ) :\r\nif ( V_28 == V_38 )\r\nreturn F_7 ( V_41 ) ;\r\nreturn V_2 ;\r\ncase F_5 ( V_31 , V_31 ) :\r\nV_42 ;\r\ncase F_5 ( V_37 , V_31 ) :\r\nif ( V_28 == V_35 )\r\nreturn V_2 ;\r\nelse if ( V_28 == V_38 )\r\nreturn F_7 ( V_41 ) ;\r\nV_43 ;\r\nbreak;\r\ncase F_5 ( V_31 , V_37 ) :\r\nif ( V_28 == V_35 )\r\nreturn V_2 ;\r\nelse if ( V_28 == V_38 )\r\nreturn F_7 ( V_41 ) ;\r\nV_42 ;\r\nbreak;\r\ncase F_5 ( V_37 , V_37 ) :\r\nif ( V_28 == V_35 )\r\nreturn V_2 ;\r\nelse if ( V_28 == V_38 )\r\nreturn F_7 ( V_41 ) ;\r\n}\r\nassert ( V_44 & V_45 ) ;\r\nassert ( V_46 & V_45 ) ;\r\nV_7 = V_47 + V_48 ;\r\nV_8 = V_39 ^ V_40 ;\r\nif ( V_6 & V_49 )\r\nV_8 ^= 1 ;\r\nV_44 <<= 64 - ( V_50 + 1 ) ;\r\nV_46 <<= 64 - ( V_50 + 1 ) ;\r\n#define F_8 ( V_3 , V_4 ) ((u64)(x) * (u64)y)\r\nV_10 = V_44 ;\r\nV_11 = V_44 >> 32 ;\r\nV_12 = V_46 ;\r\nV_13 = V_46 >> 32 ;\r\nV_14 = F_8 ( V_10 , V_12 ) ;\r\nV_15 = F_8 ( V_11 , V_13 ) ;\r\nV_16 = F_8 ( V_10 , V_13 ) ;\r\nV_17 = V_14 + ( V_16 << 32 ) ;\r\nV_15 += V_17 < V_14 ;\r\nV_14 = V_17 ;\r\nV_15 = V_15 + ( V_16 >> 32 ) ;\r\nV_16 = F_8 ( V_11 , V_12 ) ;\r\nV_17 = V_14 + ( V_16 << 32 ) ;\r\nV_15 += V_17 < V_14 ;\r\nV_14 = V_17 ;\r\nV_15 = V_15 + ( V_16 >> 32 ) ;\r\nV_9 = V_15 | ( V_14 != 0 ) ;\r\nif ( ( V_51 ) V_9 < 0 ) {\r\nV_9 = ( V_9 >> ( 64 - ( V_50 + 1 + 3 ) ) ) |\r\n( ( V_9 << ( V_50 + 1 + 3 ) ) != 0 ) ;\r\nV_7 ++ ;\r\n} else {\r\nV_9 = ( V_9 >> ( 64 - ( V_50 + 1 + 3 + 1 ) ) ) |\r\n( ( V_9 << ( V_50 + 1 + 3 + 1 ) ) != 0 ) ;\r\n}\r\nassert ( V_9 & ( V_45 << 3 ) ) ;\r\nassert ( V_52 & V_45 ) ;\r\nV_52 <<= 3 ;\r\nif ( V_53 > V_7 ) {\r\nV_18 = V_53 - V_7 ;\r\nV_9 = F_9 ( V_9 , V_18 ) ;\r\nV_7 += V_18 ;\r\n} else if ( V_7 > V_53 ) {\r\nV_18 = V_7 - V_53 ;\r\nV_52 = F_9 ( V_52 , V_18 ) ;\r\nV_53 += V_18 ;\r\n}\r\nassert ( V_53 == V_7 ) ;\r\nassert ( V_53 <= V_54 ) ;\r\nif ( V_41 == V_8 ) {\r\nV_52 = V_52 + V_9 ;\r\nif ( V_52 >> ( V_50 + 1 + 3 ) ) {\r\nV_52 = F_10 ( V_52 ) ;\r\nV_53 ++ ;\r\n}\r\n} else {\r\nif ( V_52 >= V_9 ) {\r\nV_52 = V_52 - V_9 ;\r\n} else {\r\nV_52 = V_9 - V_52 ;\r\nV_41 = V_8 ;\r\n}\r\nif ( V_52 == 0 )\r\nreturn F_11 ( V_55 . V_9 == V_56 ) ;\r\nwhile ( ( V_52 >> ( V_50 + 3 ) ) == 0 ) {\r\nV_52 <<= 1 ;\r\nV_53 -- ;\r\n}\r\n}\r\nreturn F_12 ( V_41 , V_53 , V_52 ) ;\r\n}\r\nunion V_1 F_13 ( union V_1 V_2 , union V_1 V_3 ,\r\nunion V_1 V_4 )\r\n{\r\nreturn F_1 ( V_2 , V_3 , V_4 , 0 ) ;\r\n}\r\nunion V_1 F_14 ( union V_1 V_2 , union V_1 V_3 ,\r\nunion V_1 V_4 )\r\n{\r\nreturn F_1 ( V_2 , V_3 , V_4 , V_49 ) ;\r\n}
