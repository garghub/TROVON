static int F_1 ( struct V_1 * V_2 , char * V_3 , unsigned int V_4 )\r\n{\r\nstruct V_5 V_6 ;\r\nstruct V_7 * V_8 ;\r\nint V_9 = 0 ;\r\nV_8 = F_2 ( V_10 , V_2 -> V_11 . V_12 . V_13 ,\r\nV_2 -> V_11 . V_12 . V_14 ) ;\r\nif ( F_3 ( V_8 ) )\r\nreturn F_4 ( V_8 ) ;\r\nV_2 -> V_11 . V_15 . V_8 = V_8 ;\r\nV_6 . V_3 = V_3 ;\r\nV_6 . V_16 = NULL ;\r\nV_6 . V_8 = V_8 ;\r\nV_6 . V_17 = V_2 -> V_18 ;\r\nV_6 . V_19 = V_4 ;\r\nV_6 . V_20 = V_21 ;\r\nV_9 = F_5 ( & V_6 , V_2 -> V_11 . V_22 - sizeof( * V_2 ) , 0 , false ) ;\r\nif ( V_9 < 0 ) {\r\nF_6 ( V_2 -> V_11 . V_15 . V_8 -> V_23 ) ;\r\nreturn V_9 ;\r\n}\r\nreturn 0 ;\r\n}\r\nstatic void F_7 ( struct V_1 * V_2 )\r\n{\r\nstruct V_24 V_6 = {\r\n. V_8 = V_2 -> V_11 . V_15 . V_8 ,\r\n. V_17 = V_2 -> V_18 ,\r\n} ;\r\nif ( V_6 . V_8 -> V_25 != NULL )\r\nV_6 . V_8 -> V_25 ( & V_6 ) ;\r\nF_6 ( V_6 . V_8 -> V_23 ) ;\r\n}\r\nstatic void F_8 ( struct V_26 * V_27 , int V_28 )\r\n{\r\nstruct V_29 * V_30 = F_9 ( V_27 ) ;\r\nF_7 ( V_30 -> V_31 ) ;\r\nF_10 ( V_30 -> V_32 ) ;\r\nF_10 ( V_30 -> V_31 ) ;\r\n}\r\nstatic int F_11 ( struct V_33 * V_33 , struct V_34 * V_35 , struct V_34 * V_36 ,\r\nstruct V_26 * V_27 , int V_37 , int V_28 )\r\n{\r\nstruct V_34 * V_38 [ V_39 + 1 ] ;\r\nstruct V_29 * V_30 ;\r\nstruct V_1 * V_40 , * V_2 ;\r\nchar * V_41 ;\r\nint V_9 = 0 , V_42 ;\r\nT_1 V_4 = 0 ;\r\nT_1 V_43 = 0 ;\r\nif ( V_35 == NULL )\r\nreturn - V_44 ;\r\nV_42 = F_12 ( V_38 , V_39 , V_35 , V_45 ) ;\r\nif ( V_42 < 0 )\r\nreturn V_42 ;\r\nif ( V_38 [ V_46 ] == NULL )\r\nreturn - V_44 ;\r\nif ( V_38 [ V_47 ] == NULL )\r\nreturn - V_44 ;\r\nV_40 = (struct V_1 * ) F_13 ( V_38 [ V_47 ] ) ;\r\nif ( F_14 ( V_38 [ V_47 ] ) < V_40 -> V_11 . V_22 )\r\nreturn - V_44 ;\r\nif ( V_38 [ V_48 ] != NULL )\r\nV_43 = F_15 ( V_38 [ V_48 ] ) ;\r\nif ( ! F_16 ( V_43 , V_27 , V_28 ) ) {\r\nV_9 = F_17 ( V_43 , V_36 , V_27 , sizeof( * V_30 ) , V_28 ) ;\r\nif ( V_9 )\r\nreturn V_9 ;\r\nV_9 = V_49 ;\r\n} else {\r\nif ( V_28 )\r\nreturn 0 ;\r\nF_18 ( V_27 , V_28 ) ;\r\nif ( ! V_37 )\r\nreturn - V_50 ;\r\n}\r\nV_30 = F_9 ( V_27 ) ;\r\nV_4 = F_15 ( V_38 [ V_46 ] ) ;\r\nV_42 = - V_51 ;\r\nV_41 = F_19 ( V_52 , V_53 ) ;\r\nif ( F_20 ( ! V_41 ) )\r\ngoto V_54;\r\nif ( V_38 [ V_55 ] == NULL ||\r\nF_21 ( V_41 , V_38 [ V_55 ] , V_52 ) >= V_52 )\r\nstrcpy ( V_41 , L_1 ) ;\r\nV_2 = F_22 ( V_40 , V_40 -> V_11 . V_22 , V_53 ) ;\r\nif ( F_20 ( ! V_2 ) )\r\ngoto V_56;\r\nV_42 = F_1 ( V_2 , V_41 , V_4 ) ;\r\nif ( V_42 < 0 )\r\ngoto V_57;\r\nF_23 ( & V_30 -> V_58 ) ;\r\nif ( V_9 != V_49 ) {\r\nF_7 ( V_30 -> V_31 ) ;\r\nF_10 ( V_30 -> V_32 ) ;\r\nF_10 ( V_30 -> V_31 ) ;\r\n}\r\nV_30 -> V_32 = V_41 ;\r\nV_30 -> V_31 = V_2 ;\r\nV_30 -> V_59 = V_4 ;\r\nF_24 ( & V_30 -> V_58 ) ;\r\nif ( V_9 == V_49 )\r\nF_25 ( V_27 ) ;\r\nreturn V_9 ;\r\nV_57:\r\nF_10 ( V_2 ) ;\r\nV_56:\r\nF_10 ( V_41 ) ;\r\nV_54:\r\nif ( V_9 == V_49 )\r\nF_26 ( V_27 , V_36 ) ;\r\nreturn V_42 ;\r\n}\r\nstatic int V_29 ( struct V_60 * V_61 , const struct V_26 * V_27 ,\r\nstruct V_62 * V_63 )\r\n{\r\nint V_9 = 0 , V_64 = 0 ;\r\nstruct V_29 * V_30 = V_27 -> V_65 ;\r\nstruct V_66 V_6 ;\r\nif ( F_27 ( V_61 , V_67 ) )\r\nreturn V_68 ;\r\nF_28 ( & V_30 -> V_58 ) ;\r\nV_30 -> V_69 . V_70 = V_71 ;\r\nF_29 ( & V_30 -> V_72 , V_61 ) ;\r\nV_6 . V_73 = V_61 -> V_74 ;\r\nV_6 . V_75 = NULL ;\r\nV_6 . V_76 = V_30 -> V_59 ;\r\nV_6 . V_8 = V_30 -> V_31 -> V_11 . V_15 . V_8 ;\r\nV_6 . V_17 = V_30 -> V_31 -> V_18 ;\r\nV_9 = V_6 . V_8 -> V_8 ( V_61 , & V_6 ) ;\r\nswitch ( V_9 ) {\r\ncase V_77 :\r\nV_64 = V_78 ;\r\nbreak;\r\ncase V_79 :\r\nV_64 = V_80 ;\r\nV_30 -> V_81 . V_82 ++ ;\r\nbreak;\r\ncase V_83 :\r\nV_64 = V_84 ;\r\nbreak;\r\ndefault:\r\nF_30 ( L_2 ,\r\nV_9 ) ;\r\nV_64 = V_85 ;\r\nbreak;\r\n}\r\nF_31 ( & V_30 -> V_58 ) ;\r\nreturn V_64 ;\r\n}\r\nstatic int F_32 ( struct V_60 * V_61 , struct V_26 * V_27 , int V_28 , int V_86 )\r\n{\r\nunsigned char * V_87 = F_33 ( V_61 ) ;\r\nstruct V_29 * V_30 = V_27 -> V_65 ;\r\nstruct V_1 * V_2 ;\r\nstruct V_88 V_89 ;\r\nstruct V_90 V_91 ;\r\nV_2 = F_22 ( V_30 -> V_31 , V_30 -> V_31 -> V_11 . V_12 . V_22 , V_67 ) ;\r\nif ( F_20 ( ! V_2 ) )\r\ngoto V_92;\r\nV_91 . V_93 = V_30 -> V_94 - V_28 ;\r\nV_91 . V_95 = V_30 -> V_96 - V_86 ;\r\nstrcpy ( V_2 -> V_11 . V_12 . V_13 , V_30 -> V_31 -> V_11 . V_15 . V_8 -> V_13 ) ;\r\nif ( F_34 ( V_61 , V_47 , V_30 -> V_31 -> V_11 . V_12 . V_22 , V_2 ) ||\r\nF_35 ( V_61 , V_48 , V_30 -> V_97 ) ||\r\nF_35 ( V_61 , V_46 , V_30 -> V_59 ) ||\r\nF_34 ( V_61 , V_98 , sizeof( struct V_90 ) , & V_91 ) ||\r\nF_36 ( V_61 , V_55 , V_30 -> V_32 ) )\r\ngoto V_92;\r\nV_89 . V_99 = F_37 ( V_71 - V_30 -> V_69 . V_99 ) ;\r\nV_89 . V_70 = F_37 ( V_71 - V_30 -> V_69 . V_70 ) ;\r\nV_89 . V_100 = F_37 ( V_30 -> V_69 . V_100 ) ;\r\nif ( F_34 ( V_61 , V_101 , sizeof ( V_89 ) , & V_89 ) )\r\ngoto V_92;\r\nF_10 ( V_2 ) ;\r\nreturn V_61 -> V_102 ;\r\nV_92:\r\nF_38 ( V_61 , V_87 ) ;\r\nF_10 ( V_2 ) ;\r\nreturn - 1 ;\r\n}\r\nstatic int T_2 F_39 ( void )\r\n{\r\nint V_103 , V_104 ;\r\nV_103 = F_40 ( & V_105 , V_106 ) ;\r\nif ( V_103 < 0 )\r\nF_41 ( L_3 ) ;\r\nV_104 = F_40 ( & V_107 , V_106 ) ;\r\nif ( V_104 < 0 )\r\nF_41 ( L_4 ) ;\r\nif ( V_103 < 0 && V_104 < 0 ) {\r\nreturn V_103 ;\r\n} else\r\nreturn 0 ;\r\n}\r\nstatic void T_3 F_42 ( void )\r\n{\r\nF_43 ( & V_105 ) ;\r\nF_43 ( & V_107 ) ;\r\n}
