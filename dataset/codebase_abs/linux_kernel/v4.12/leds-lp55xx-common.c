static struct V_1 * F_1 ( struct V_2 * V_3 )\r\n{\r\nreturn F_2 ( V_3 , struct V_1 , V_3 ) ;\r\n}\r\nstatic struct V_1 * F_3 ( struct V_4 * V_5 )\r\n{\r\nreturn F_1 ( F_4 ( V_5 ) ) ;\r\n}\r\nstatic void F_5 ( struct V_6 * V_7 )\r\n{\r\nstruct V_8 * V_9 = V_7 -> V_9 ;\r\nT_1 V_10 = V_9 -> V_11 . V_10 ;\r\nT_1 V_12 = V_9 -> V_11 . V_12 ;\r\nF_6 ( V_7 , V_10 , V_12 ) ;\r\n}\r\nstatic int F_7 ( struct V_6 * V_7 )\r\n{\r\nstruct V_8 * V_9 = V_7 -> V_9 ;\r\nT_1 V_10 = V_9 -> V_13 . V_10 ;\r\nT_1 V_12 = V_9 -> V_13 . V_12 ;\r\nint V_14 ;\r\nV_14 = F_6 ( V_7 , V_10 , V_12 ) ;\r\nif ( V_14 )\r\nreturn V_14 ;\r\nF_8 ( 1000 , 2000 ) ;\r\nV_14 = F_9 ( V_7 , V_10 , & V_12 ) ;\r\nif ( V_14 )\r\nreturn V_14 ;\r\nif ( V_12 != V_9 -> V_13 . V_12 )\r\nreturn - V_15 ;\r\nreturn 0 ;\r\n}\r\nstatic int F_10 ( struct V_6 * V_7 )\r\n{\r\nstruct V_8 * V_9 = V_7 -> V_9 ;\r\nif ( ! V_9 -> V_16 )\r\nreturn 0 ;\r\nreturn V_9 -> V_16 ( V_7 ) ;\r\n}\r\nstatic T_2 F_11 ( struct V_4 * V_5 ,\r\nstruct V_17 * V_18 ,\r\nchar * V_19 )\r\n{\r\nstruct V_1 * V_20 = F_3 ( V_5 ) ;\r\nreturn F_12 ( V_19 , V_21 , L_1 , V_20 -> V_22 ) ;\r\n}\r\nstatic T_2 F_13 ( struct V_4 * V_5 ,\r\nstruct V_17 * V_18 ,\r\nconst char * V_19 , T_3 V_23 )\r\n{\r\nstruct V_1 * V_20 = F_3 ( V_5 ) ;\r\nstruct V_6 * V_7 = V_20 -> V_7 ;\r\nunsigned long V_24 ;\r\nif ( F_14 ( V_19 , 0 , & V_24 ) )\r\nreturn - V_25 ;\r\nif ( V_24 > V_20 -> V_26 )\r\nreturn - V_25 ;\r\nif ( ! V_7 -> V_9 -> V_27 )\r\nreturn V_23 ;\r\nF_15 ( & V_7 -> V_28 ) ;\r\nV_7 -> V_9 -> V_27 ( V_20 , ( T_1 ) V_24 ) ;\r\nF_16 ( & V_7 -> V_28 ) ;\r\nreturn V_23 ;\r\n}\r\nstatic T_2 F_17 ( struct V_4 * V_5 ,\r\nstruct V_17 * V_18 ,\r\nchar * V_19 )\r\n{\r\nstruct V_1 * V_20 = F_3 ( V_5 ) ;\r\nreturn F_12 ( V_19 , V_21 , L_1 , V_20 -> V_26 ) ;\r\n}\r\nstatic int F_18 ( struct V_2 * V_3 ,\r\nenum V_29 V_30 )\r\n{\r\nstruct V_1 * V_20 = F_1 ( V_3 ) ;\r\nstruct V_8 * V_9 = V_20 -> V_7 -> V_9 ;\r\nV_20 -> V_30 = ( T_1 ) V_30 ;\r\nreturn V_9 -> V_31 ( V_20 ) ;\r\n}\r\nstatic int F_19 ( struct V_1 * V_20 ,\r\nstruct V_6 * V_7 , int V_32 )\r\n{\r\nstruct V_33 * V_34 = V_7 -> V_34 ;\r\nstruct V_8 * V_9 = V_7 -> V_9 ;\r\nstruct V_4 * V_5 = & V_7 -> V_35 -> V_5 ;\r\nchar V_36 [ 32 ] ;\r\nint V_14 ;\r\nint V_37 = V_9 -> V_37 ;\r\nif ( V_32 >= V_37 ) {\r\nF_20 ( V_5 , L_2 , V_32 , V_37 ) ;\r\nreturn - V_25 ;\r\n}\r\nif ( V_34 -> V_38 [ V_32 ] . V_22 == 0 )\r\nreturn 0 ;\r\nV_20 -> V_22 = V_34 -> V_38 [ V_32 ] . V_22 ;\r\nV_20 -> V_26 = V_34 -> V_38 [ V_32 ] . V_26 ;\r\nV_20 -> V_39 = V_34 -> V_38 [ V_32 ] . V_39 ;\r\nV_20 -> V_3 . V_40 = V_34 -> V_38 [ V_32 ] . V_40 ;\r\nif ( V_20 -> V_39 >= V_37 ) {\r\nF_20 ( V_5 , L_3 ,\r\nV_37 - 1 ) ;\r\nreturn - V_25 ;\r\n}\r\nV_20 -> V_3 . V_41 = F_18 ;\r\nV_20 -> V_3 . V_42 = V_43 ;\r\nif ( V_34 -> V_38 [ V_32 ] . V_36 ) {\r\nV_20 -> V_3 . V_36 = V_34 -> V_38 [ V_32 ] . V_36 ;\r\n} else {\r\nsnprintf ( V_36 , sizeof( V_36 ) , L_4 ,\r\nV_34 -> V_44 ? : V_7 -> V_35 -> V_36 , V_32 ) ;\r\nV_20 -> V_3 . V_36 = V_36 ;\r\n}\r\nV_14 = F_21 ( V_5 , & V_20 -> V_3 ) ;\r\nif ( V_14 ) {\r\nF_20 ( V_5 , L_5 , V_14 ) ;\r\nreturn V_14 ;\r\n}\r\nreturn 0 ;\r\n}\r\nstatic void F_22 ( const struct V_45 * V_46 , void * V_47 )\r\n{\r\nstruct V_6 * V_7 = V_47 ;\r\nstruct V_4 * V_5 = & V_7 -> V_35 -> V_5 ;\r\nenum V_48 V_49 = V_7 -> V_50 ;\r\nif ( ! V_46 ) {\r\nF_20 ( V_5 , L_6 ) ;\r\ngoto V_51;\r\n}\r\nF_15 ( & V_7 -> V_28 ) ;\r\nV_7 -> V_52 [ V_49 - 1 ] . V_53 = V_54 ;\r\nV_7 -> V_46 = V_46 ;\r\nif ( V_7 -> V_9 -> V_55 )\r\nV_7 -> V_9 -> V_55 ( V_7 ) ;\r\nF_16 ( & V_7 -> V_28 ) ;\r\nV_51:\r\nF_23 ( V_7 -> V_46 ) ;\r\n}\r\nstatic int F_24 ( struct V_6 * V_7 )\r\n{\r\nconst char * V_36 = V_7 -> V_35 -> V_36 ;\r\nstruct V_4 * V_5 = & V_7 -> V_35 -> V_5 ;\r\nreturn F_25 ( V_56 , false , V_36 , V_5 ,\r\nV_57 , V_7 , F_22 ) ;\r\n}\r\nstatic T_2 F_26 ( struct V_4 * V_5 ,\r\nstruct V_17 * V_18 ,\r\nchar * V_19 )\r\n{\r\nstruct V_1 * V_20 = F_27 ( F_28 ( V_5 ) ) ;\r\nstruct V_6 * V_7 = V_20 -> V_7 ;\r\nreturn sprintf ( V_19 , L_1 , V_7 -> V_50 ) ;\r\n}\r\nstatic T_2 F_29 ( struct V_4 * V_5 ,\r\nstruct V_17 * V_18 ,\r\nconst char * V_19 , T_3 V_23 )\r\n{\r\nstruct V_1 * V_20 = F_27 ( F_28 ( V_5 ) ) ;\r\nstruct V_6 * V_7 = V_20 -> V_7 ;\r\nunsigned long V_12 ;\r\nint V_14 ;\r\nif ( F_14 ( V_19 , 0 , & V_12 ) )\r\nreturn - V_25 ;\r\nswitch ( V_12 ) {\r\ncase V_58 :\r\ncase V_59 :\r\ncase V_60 :\r\nF_15 ( & V_7 -> V_28 ) ;\r\nV_7 -> V_50 = V_12 ;\r\nV_14 = F_24 ( V_7 ) ;\r\nF_16 ( & V_7 -> V_28 ) ;\r\nbreak;\r\ndefault:\r\nF_20 ( V_5 , L_7 , V_12 ) ;\r\nreturn - V_25 ;\r\n}\r\nif ( V_14 ) {\r\nF_20 ( V_5 , L_8 , V_14 ) ;\r\nreturn V_14 ;\r\n}\r\nreturn V_23 ;\r\n}\r\nstatic inline void F_30 ( struct V_6 * V_7 , bool V_61 )\r\n{\r\nif ( V_7 -> V_9 -> V_62 )\r\nV_7 -> V_9 -> V_62 ( V_7 , V_61 ) ;\r\n}\r\nstatic T_2 F_31 ( struct V_4 * V_5 ,\r\nstruct V_17 * V_18 ,\r\nconst char * V_19 , T_3 V_23 )\r\n{\r\nstruct V_1 * V_20 = F_27 ( F_28 ( V_5 ) ) ;\r\nstruct V_6 * V_7 = V_20 -> V_7 ;\r\nunsigned long V_12 ;\r\nif ( F_14 ( V_19 , 0 , & V_12 ) )\r\nreturn - V_25 ;\r\nif ( V_12 <= 0 ) {\r\nF_30 ( V_7 , false ) ;\r\nreturn V_23 ;\r\n}\r\nF_15 ( & V_7 -> V_28 ) ;\r\nF_30 ( V_7 , true ) ;\r\nF_16 ( & V_7 -> V_28 ) ;\r\nreturn V_23 ;\r\n}\r\nint F_6 ( struct V_6 * V_7 , T_1 V_63 , T_1 V_12 )\r\n{\r\nreturn F_32 ( V_7 -> V_35 , V_63 , V_12 ) ;\r\n}\r\nint F_9 ( struct V_6 * V_7 , T_1 V_63 , T_1 * V_12 )\r\n{\r\nT_4 V_14 ;\r\nV_14 = F_33 ( V_7 -> V_35 , V_63 ) ;\r\nif ( V_14 < 0 )\r\nreturn V_14 ;\r\n* V_12 = V_14 ;\r\nreturn 0 ;\r\n}\r\nint F_34 ( struct V_6 * V_7 , T_1 V_63 , T_1 V_64 , T_1 V_12 )\r\n{\r\nint V_14 ;\r\nT_1 V_65 ;\r\nV_14 = F_9 ( V_7 , V_63 , & V_65 ) ;\r\nif ( V_14 )\r\nreturn V_14 ;\r\nV_65 &= ~ V_64 ;\r\nV_65 |= V_12 & V_64 ;\r\nreturn F_6 ( V_7 , V_63 , V_65 ) ;\r\n}\r\nbool F_35 ( struct V_6 * V_7 )\r\n{\r\nstruct V_66 * V_66 ;\r\nint V_67 ;\r\nV_66 = F_36 ( & V_7 -> V_35 -> V_5 , L_9 ) ;\r\nif ( F_37 ( V_66 ) )\r\ngoto V_68;\r\nV_67 = F_38 ( V_66 ) ;\r\nif ( V_67 )\r\ngoto V_68;\r\nif ( F_39 ( V_66 ) != V_69 ) {\r\nF_40 ( V_66 ) ;\r\ngoto V_68;\r\n}\r\nF_41 ( & V_7 -> V_35 -> V_5 , L_10 , V_69 ) ;\r\nV_7 -> V_66 = V_66 ;\r\nreturn true ;\r\nV_68:\r\nF_41 ( & V_7 -> V_35 -> V_5 , L_11 ) ;\r\nreturn false ;\r\n}\r\nint F_42 ( struct V_6 * V_7 )\r\n{\r\nstruct V_33 * V_34 ;\r\nstruct V_8 * V_9 ;\r\nstruct V_4 * V_5 = & V_7 -> V_35 -> V_5 ;\r\nint V_14 = 0 ;\r\nF_43 ( ! V_7 ) ;\r\nV_34 = V_7 -> V_34 ;\r\nV_9 = V_7 -> V_9 ;\r\nif ( ! V_34 || ! V_9 )\r\nreturn - V_25 ;\r\nif ( F_44 ( V_34 -> V_70 ) ) {\r\nV_14 = F_45 ( V_5 , V_34 -> V_70 ,\r\nV_71 , L_12 ) ;\r\nif ( V_14 < 0 ) {\r\nF_20 ( V_5 , L_13 ,\r\nV_14 ) ;\r\ngoto V_67;\r\n}\r\nF_46 ( V_34 -> V_70 , 0 ) ;\r\nF_8 ( 1000 , 2000 ) ;\r\nF_46 ( V_34 -> V_70 , 1 ) ;\r\nF_8 ( 1000 , 2000 ) ;\r\n}\r\nF_5 ( V_7 ) ;\r\nF_8 ( 10000 , 20000 ) ;\r\nV_14 = F_7 ( V_7 ) ;\r\nif ( V_14 ) {\r\nF_20 ( V_5 , L_14 , V_14 ) ;\r\ngoto V_67;\r\n}\r\nV_14 = F_10 ( V_7 ) ;\r\nif ( V_14 ) {\r\nF_20 ( V_5 , L_15 , V_14 ) ;\r\ngoto V_72;\r\n}\r\nreturn 0 ;\r\nV_72:\r\nF_47 ( V_7 ) ;\r\nV_67:\r\nreturn V_14 ;\r\n}\r\nvoid F_47 ( struct V_6 * V_7 )\r\n{\r\nstruct V_33 * V_34 = V_7 -> V_34 ;\r\nif ( V_7 -> V_66 )\r\nF_40 ( V_7 -> V_66 ) ;\r\nif ( F_44 ( V_34 -> V_70 ) )\r\nF_46 ( V_34 -> V_70 , 0 ) ;\r\n}\r\nint F_48 ( struct V_1 * V_20 , struct V_6 * V_7 )\r\n{\r\nstruct V_33 * V_34 = V_7 -> V_34 ;\r\nstruct V_8 * V_9 = V_7 -> V_9 ;\r\nint V_73 = V_34 -> V_73 ;\r\nstruct V_1 * V_74 ;\r\nT_1 V_22 ;\r\nint V_14 ;\r\nint V_75 ;\r\nif ( ! V_9 -> V_31 ) {\r\nF_20 ( & V_7 -> V_35 -> V_5 , L_16 ) ;\r\nreturn - V_25 ;\r\n}\r\nfor ( V_75 = 0 ; V_75 < V_73 ; V_75 ++ ) {\r\nif ( V_34 -> V_38 [ V_75 ] . V_22 == 0 )\r\ncontinue;\r\nV_22 = V_34 -> V_38 [ V_75 ] . V_22 ;\r\nV_74 = V_20 + V_75 ;\r\nV_14 = F_19 ( V_74 , V_7 , V_75 ) ;\r\nif ( V_14 )\r\ngoto V_76;\r\nV_7 -> V_77 ++ ;\r\nV_74 -> V_7 = V_7 ;\r\nif ( V_9 -> V_27 )\r\nV_9 -> V_27 ( V_74 , V_22 ) ;\r\n}\r\nreturn 0 ;\r\nV_76:\r\nF_49 ( V_20 , V_7 ) ;\r\nreturn V_14 ;\r\n}\r\nvoid F_49 ( struct V_1 * V_20 , struct V_6 * V_7 )\r\n{\r\nint V_75 ;\r\nstruct V_1 * V_74 ;\r\nfor ( V_75 = 0 ; V_75 < V_7 -> V_77 ; V_75 ++ ) {\r\nV_74 = V_20 + V_75 ;\r\nF_50 ( & V_74 -> V_3 ) ;\r\n}\r\n}\r\nint F_51 ( struct V_6 * V_7 )\r\n{\r\nstruct V_4 * V_5 = & V_7 -> V_35 -> V_5 ;\r\nstruct V_8 * V_9 = V_7 -> V_9 ;\r\nint V_14 ;\r\nif ( ! V_9 -> V_62 || ! V_9 -> V_55 )\r\ngoto V_78;\r\nV_14 = F_52 ( & V_5 -> V_79 , & V_80 ) ;\r\nif ( V_14 )\r\nreturn V_14 ;\r\nV_78:\r\nreturn V_9 -> V_81 ?\r\nF_52 ( & V_5 -> V_79 , V_9 -> V_81 ) : 0 ;\r\n}\r\nvoid F_53 ( struct V_6 * V_7 )\r\n{\r\nstruct V_4 * V_5 = & V_7 -> V_35 -> V_5 ;\r\nstruct V_8 * V_9 = V_7 -> V_9 ;\r\nif ( V_9 -> V_81 )\r\nF_54 ( & V_5 -> V_79 , V_9 -> V_81 ) ;\r\nF_54 ( & V_5 -> V_79 , & V_80 ) ;\r\n}\r\nstruct V_33 * F_55 ( struct V_4 * V_5 ,\r\nstruct V_82 * V_83 )\r\n{\r\nstruct V_82 * V_84 ;\r\nstruct V_33 * V_34 ;\r\nstruct V_85 * V_9 ;\r\nint V_73 ;\r\nint V_75 = 0 ;\r\nV_34 = F_56 ( V_5 , sizeof( * V_34 ) , V_57 ) ;\r\nif ( ! V_34 )\r\nreturn F_57 ( - V_86 ) ;\r\nV_73 = F_58 ( V_83 ) ;\r\nif ( V_73 == 0 ) {\r\nF_20 ( V_5 , L_17 ) ;\r\nreturn F_57 ( - V_25 ) ;\r\n}\r\nV_9 = F_56 ( V_5 , sizeof( * V_9 ) * V_73 , V_57 ) ;\r\nif ( ! V_9 )\r\nreturn F_57 ( - V_86 ) ;\r\nV_34 -> V_38 = & V_9 [ 0 ] ;\r\nV_34 -> V_73 = V_73 ;\r\nF_59 (np, child) {\r\nV_9 [ V_75 ] . V_39 = V_75 ;\r\nF_60 ( V_84 , L_18 , & V_9 [ V_75 ] . V_36 ) ;\r\nF_61 ( V_84 , L_19 , & V_9 [ V_75 ] . V_22 ) ;\r\nF_61 ( V_84 , L_20 , & V_9 [ V_75 ] . V_26 ) ;\r\nV_9 [ V_75 ] . V_40 =\r\nF_62 ( V_84 , L_21 , NULL ) ;\r\nV_75 ++ ;\r\n}\r\nF_60 ( V_83 , L_22 , & V_34 -> V_44 ) ;\r\nF_61 ( V_83 , L_23 , & V_34 -> V_87 ) ;\r\nV_34 -> V_70 = F_63 ( V_83 , L_24 , 0 ) ;\r\nF_61 ( V_83 , L_25 , ( T_1 * ) & V_34 -> V_88 ) ;\r\nreturn V_34 ;\r\n}
