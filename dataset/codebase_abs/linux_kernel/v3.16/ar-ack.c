static const char * F_1 ( T_1 V_1 )\r\n{\r\nstatic const char * const V_2 [] = {\r\nL_1 , L_2 , L_3 , L_4 , L_5 , L_6 , L_7 , L_8 , L_9 ,\r\nL_10 , L_11\r\n} ;\r\nif ( V_1 >= F_2 ( V_2 ) )\r\nV_1 = F_2 ( V_2 ) - 1 ;\r\nreturn V_2 [ V_1 ] ;\r\n}\r\nvoid F_3 ( struct V_3 * V_4 , T_1 V_5 ,\r\nT_2 V_6 , bool V_7 )\r\n{\r\nunsigned long V_8 ;\r\nT_3 V_9 = V_10 [ V_5 ] ;\r\nF_4 ( V_9 , > , 0 ) ;\r\nF_5 ( L_12 ,\r\nV_4 -> V_11 , F_1 ( V_5 ) , F_6 ( V_6 ) ,\r\nV_7 ) ;\r\nif ( V_9 < V_10 [ V_4 -> V_12 ] ) {\r\nif ( V_7 )\r\ngoto V_13;\r\nreturn;\r\n}\r\nif ( V_9 == V_10 [ V_4 -> V_12 ] ) {\r\nif ( V_9 <= 4 )\r\nV_4 -> V_14 = V_6 ;\r\nif ( V_7 )\r\ngoto V_13;\r\nreturn;\r\n}\r\nV_4 -> V_12 = V_5 ;\r\nV_4 -> V_14 = V_6 ;\r\nswitch ( V_5 ) {\r\ncase V_15 :\r\nF_7 ( L_13 ) ;\r\nV_8 = V_16 ;\r\ngoto V_17;\r\ncase V_18 :\r\nif ( ! V_7 ) {\r\nF_7 ( L_14 ) ;\r\nV_8 = V_19 ;\r\ngoto V_17;\r\n}\r\ngoto V_13;\r\ncase V_20 :\r\nV_8 = V_21 ;\r\nif ( ! V_8 )\r\ngoto V_13;\r\nif ( ! V_7 || V_6 == F_8 ( 1 ) ) {\r\nF_7 ( L_14 ) ;\r\ngoto V_17;\r\n}\r\ndefault:\r\nF_7 ( L_15 ) ;\r\ngoto V_13;\r\n}\r\nV_17:\r\nV_8 += V_22 ;\r\nif ( ! F_9 ( & V_4 -> V_23 ) ||\r\nF_10 ( V_4 -> V_23 . V_24 , V_8 ) )\r\nF_11 ( & V_4 -> V_23 , V_8 ) ;\r\nreturn;\r\nV_13:\r\nF_7 ( L_16 , F_6 ( V_6 ) ) ;\r\nF_12 ( & V_4 -> V_23 ) ;\r\nF_13 ( & V_4 -> V_25 ) ;\r\nif ( V_4 -> V_26 <= V_27 &&\r\n! F_14 ( V_28 , & V_4 -> V_29 ) )\r\nF_15 ( V_4 ) ;\r\nF_16 ( & V_4 -> V_25 ) ;\r\n}\r\nvoid F_17 ( struct V_3 * V_4 , T_1 V_5 ,\r\nT_2 V_6 , bool V_7 )\r\n{\r\nT_3 V_9 = V_10 [ V_5 ] ;\r\nif ( V_9 > V_10 [ V_4 -> V_12 ] ) {\r\nF_18 ( & V_4 -> V_30 ) ;\r\nF_3 ( V_4 , V_5 , V_6 , V_7 ) ;\r\nF_19 ( & V_4 -> V_30 ) ;\r\n}\r\n}\r\nstatic void F_20 ( struct V_3 * V_4 , T_1 V_31 ,\r\nunsigned long V_32 )\r\n{\r\nF_13 ( & V_4 -> V_25 ) ;\r\nif ( V_4 -> V_26 >= V_27 )\r\nV_31 = 0 ;\r\nif ( V_31 & 1 ) {\r\nF_7 ( L_17 ) ;\r\nF_21 ( V_33 , & V_4 -> V_29 ) ;\r\n}\r\nif ( V_31 & 2 ) {\r\nF_7 ( L_18 ) ;\r\nF_21 ( V_34 , & V_4 -> V_35 ) ;\r\nF_11 ( & V_4 -> V_36 , V_32 ) ;\r\n} else {\r\nF_7 ( L_19 ) ;\r\nF_22 ( & V_4 -> V_36 ) ;\r\nF_23 ( V_37 , & V_4 -> V_29 ) ;\r\nF_23 ( V_34 , & V_4 -> V_35 ) ;\r\n}\r\nF_16 ( & V_4 -> V_25 ) ;\r\n}\r\nstatic void F_24 ( struct V_3 * V_4 )\r\n{\r\nstruct V_38 * V_39 ;\r\nstruct V_40 * V_41 ;\r\nstruct V_42 * V_43 ;\r\nunsigned long * V_44 , V_32 ;\r\nint V_45 , V_46 ;\r\nT_1 V_31 ;\r\nF_5 ( L_20 ,\r\nV_4 -> V_47 , V_4 -> V_48 ,\r\nF_25 ( & V_4 -> V_49 ) ,\r\nF_26 ( V_4 -> V_50 , V_4 -> V_51 , V_4 -> V_52 ) ) ;\r\nV_46 = 0 ;\r\nV_31 = 0 ;\r\nV_32 = 0 ;\r\nfor ( V_45 = V_4 -> V_51 ;\r\nV_45 != V_4 -> V_50 || V_46 ;\r\nV_45 = ( V_45 + 1 ) & ( V_4 -> V_52 - 1 )\r\n) {\r\nV_44 = V_4 -> V_53 + V_45 ;\r\nF_27 () ;\r\nif ( * V_44 & 1 )\r\ncontinue;\r\nV_43 = (struct V_42 * ) * V_44 ;\r\nV_39 = F_28 ( V_43 ) ;\r\nif ( V_39 -> V_54 ) {\r\nV_39 -> V_54 = false ;\r\nV_39 -> V_41 . V_6 =\r\nF_29 ( F_30 ( & V_4 -> V_55 -> V_6 ) ) ;\r\nV_41 = (struct V_40 * ) V_43 -> V_56 ;\r\nV_41 -> V_6 = V_39 -> V_41 . V_6 ;\r\nF_31 ( L_21 ,\r\nF_6 ( V_39 -> V_41 . V_6 ) , F_6 ( V_39 -> V_41 . V_57 ) ) ;\r\nif ( F_32 ( V_4 -> V_55 -> V_58 , V_43 ) < 0 ) {\r\nV_46 = 0 ;\r\nV_39 -> V_32 = V_22 + 3 ;\r\n} else {\r\nV_39 -> V_32 =\r\nV_22 + V_59 * V_60 ;\r\n}\r\n}\r\nif ( F_33 ( V_22 + 1 , V_39 -> V_32 ) ) {\r\nV_39 -> V_54 = true ;\r\nV_31 |= 1 ;\r\n} else if ( V_31 & 2 ) {\r\nif ( F_34 ( V_39 -> V_32 , V_32 ) )\r\nV_32 = V_39 -> V_32 ;\r\n} else {\r\nV_32 = V_39 -> V_32 ;\r\nV_31 |= 2 ;\r\n}\r\n}\r\nF_20 ( V_4 , V_31 , V_32 ) ;\r\nF_35 ( L_22 ) ;\r\n}\r\nstatic void F_36 ( struct V_3 * V_4 )\r\n{\r\nstruct V_38 * V_39 ;\r\nstruct V_42 * V_43 ;\r\nunsigned long * V_44 , V_32 ;\r\nint V_45 ;\r\nT_1 V_31 ;\r\nF_5 ( L_23 ,\r\nV_4 -> V_51 , V_4 -> V_48 , V_4 -> V_50 ) ;\r\nif ( V_4 -> V_26 >= V_27 )\r\nreturn;\r\nV_31 = 0 ;\r\nV_32 = 0 ;\r\nfor ( V_45 = V_4 -> V_48 ;\r\nV_45 != V_4 -> V_50 ;\r\nV_45 = ( V_45 + 1 ) & ( V_4 -> V_52 - 1 )\r\n) {\r\nV_44 = V_4 -> V_53 + V_45 ;\r\nF_27 () ;\r\nV_43 = (struct V_42 * ) ( * V_44 & ~ 1 ) ;\r\nV_39 = F_28 ( V_43 ) ;\r\nASSERT ( ! ( * V_44 & 1 ) ) ;\r\nif ( V_39 -> V_54 ) {\r\n;\r\n} else if ( F_33 ( V_22 + 1 , V_39 -> V_32 ) ) {\r\nV_39 -> V_54 = true ;\r\nV_31 |= 1 ;\r\n} else if ( V_31 & 2 ) {\r\nif ( F_34 ( V_39 -> V_32 , V_32 ) )\r\nV_32 = V_39 -> V_32 ;\r\n} else {\r\nV_32 = V_39 -> V_32 ;\r\nV_31 |= 2 ;\r\n}\r\n}\r\nF_20 ( V_4 , V_31 , V_32 ) ;\r\nF_35 ( L_22 ) ;\r\n}\r\nstatic int F_37 ( struct V_3 * V_4 ,\r\nstruct V_61 * V_62 ,\r\nstruct V_42 * V_63 )\r\n{\r\nstruct V_38 * V_39 ;\r\nstruct V_42 * V_43 ;\r\nunsigned long * V_44 , V_32 ;\r\nint V_45 ;\r\nT_1 V_64 [ V_65 ] , V_31 ;\r\nF_5 ( L_24 ,\r\nV_4 -> V_47 ,\r\nF_26 ( V_4 -> V_50 , V_4 -> V_51 , V_4 -> V_52 ) ,\r\nV_62 -> V_66 ) ;\r\nif ( F_38 ( V_63 , 0 , V_64 , V_62 -> V_66 ) < 0 )\r\ngoto V_67;\r\nV_31 = 0 ;\r\nV_32 = 0 ;\r\nfor ( V_45 = 0 ; V_45 < V_62 -> V_66 ; V_45 ++ ) {\r\nV_44 = V_4 -> V_53 ;\r\nV_44 += ( V_4 -> V_51 + V_45 ) & ( V_4 -> V_52 - 1 ) ;\r\nF_27 () ;\r\nV_43 = (struct V_42 * ) ( * V_44 & ~ 1 ) ;\r\nV_39 = F_28 ( V_43 ) ;\r\nswitch ( V_64 [ V_45 ] ) {\r\ncase V_68 :\r\nV_39 -> V_54 = false ;\r\n* V_44 |= 1 ;\r\nbreak;\r\ncase V_69 :\r\nV_39 -> V_54 = true ;\r\n* V_44 &= ~ 1 ;\r\nV_31 = 1 ;\r\nbreak;\r\ndefault:\r\nF_7 ( L_25 , V_64 [ V_45 ] ) ;\r\ngoto V_67;\r\n}\r\n}\r\nF_39 () ;\r\nV_4 -> V_48 = ( V_4 -> V_51 + V_45 ) & ( V_4 -> V_52 - 1 ) ;\r\nfor ( V_45 = V_4 -> V_48 ;\r\nV_45 != V_4 -> V_50 ;\r\nV_45 = ( V_45 + 1 ) & ( V_4 -> V_52 - 1 )\r\n) {\r\nV_44 = V_4 -> V_53 + V_45 ;\r\nF_27 () ;\r\nV_43 = (struct V_42 * ) ( * V_44 & ~ 1 ) ;\r\nV_39 = F_28 ( V_43 ) ;\r\nif ( * V_44 & 1 ) {\r\nV_39 -> V_54 = true ;\r\n* V_44 &= ~ 1 ;\r\nV_31 |= 1 ;\r\n} else if ( V_39 -> V_54 ) {\r\n;\r\n} else if ( F_33 ( V_22 + 1 , V_39 -> V_32 ) ) {\r\nV_39 -> V_54 = true ;\r\nV_31 |= 1 ;\r\n} else if ( V_31 & 2 ) {\r\nif ( F_34 ( V_39 -> V_32 , V_32 ) )\r\nV_32 = V_39 -> V_32 ;\r\n} else {\r\nV_32 = V_39 -> V_32 ;\r\nV_31 |= 2 ;\r\n}\r\n}\r\nF_20 ( V_4 , V_31 , V_32 ) ;\r\nF_35 ( L_26 ) ;\r\nreturn 0 ;\r\nV_67:\r\nF_35 ( L_27 ) ;\r\nreturn - V_70 ;\r\n}\r\nstatic void F_40 ( struct V_3 * V_4 , T_4 V_71 )\r\n{\r\nunsigned long V_72 ;\r\nint V_73 = V_4 -> V_51 , V_74 ;\r\nint V_75 = F_26 ( V_4 -> V_50 , V_73 , V_4 -> V_52 ) ;\r\nF_5 ( L_28 , V_4 -> V_47 , V_75 , V_71 ) ;\r\nF_4 ( V_71 - V_4 -> V_47 , <= , V_75 ) ;\r\nwhile ( V_4 -> V_47 < V_71 ) {\r\nF_27 () ;\r\nV_72 = V_4 -> V_53 [ V_73 ] & ~ 1 ;\r\nF_41 ( (struct V_42 * ) V_72 ) ;\r\nV_74 = V_73 ;\r\nV_73 = ( V_73 + 1 ) & ( V_4 -> V_52 - 1 ) ;\r\nV_4 -> V_51 = V_73 ;\r\nif ( V_4 -> V_48 == V_74 )\r\nV_4 -> V_48 = V_73 ;\r\nV_4 -> V_47 ++ ;\r\n}\r\nF_42 ( & V_4 -> V_76 ) ;\r\n}\r\nstatic void F_43 ( struct V_3 * V_4 )\r\n{\r\nF_40 ( V_4 , F_25 ( & V_4 -> V_49 ) ) ;\r\n}\r\nstatic int F_44 ( struct V_3 * V_4 )\r\n{\r\nstruct V_38 * V_39 ;\r\nstruct V_42 * V_63 ;\r\nbool V_77 ;\r\nint V_78 ;\r\nF_5 ( L_29 , V_4 -> V_79 , V_4 -> V_80 ) ;\r\nF_18 ( & V_4 -> V_30 ) ;\r\nV_78 = - V_81 ;\r\nif ( F_45 ( V_82 , & V_4 -> V_35 ) )\r\ngoto V_83;\r\nV_63 = F_46 ( & V_4 -> V_84 ) ;\r\nif ( V_63 ) {\r\nV_39 = F_28 ( V_63 ) ;\r\nF_7 ( L_30 ,\r\nF_6 ( V_39 -> V_41 . V_57 ) , V_4 -> V_80 ) ;\r\nif ( F_6 ( V_39 -> V_41 . V_57 ) != V_4 -> V_80 ) {\r\nF_47 ( & V_4 -> V_84 , V_63 ) ;\r\nV_4 -> V_80 = F_6 ( F_28 ( V_63 ) -> V_41 . V_57 ) ;\r\nF_7 ( L_31 , V_63 , V_4 -> V_80 ) ;\r\n} else {\r\nV_63 -> V_85 = V_86 ;\r\nV_77 = ( ( V_39 -> V_41 . V_35 & V_87 ) &&\r\n! ( V_39 -> V_41 . V_35 & V_88 ) ) ;\r\nV_78 = F_48 ( V_4 , V_63 , true , V_77 ) ;\r\nF_49 ( V_78 < 0 ) ;\r\nF_7 ( L_32 , V_4 -> V_79 ) ;\r\nV_4 -> V_79 ++ ;\r\nV_63 = F_50 ( & V_4 -> V_84 ) ;\r\nif ( V_63 )\r\nV_4 -> V_80 =\r\nF_6 ( F_28 ( V_63 ) -> V_41 . V_57 ) ;\r\nelse\r\nV_4 -> V_80 = 0 ;\r\nF_7 ( L_33 , V_63 , V_4 -> V_80 ) ;\r\n}\r\n}\r\nV_78 = 0 ;\r\nV_83:\r\nF_19 ( & V_4 -> V_30 ) ;\r\nF_35 ( L_34 , V_78 ) ;\r\nreturn V_78 ;\r\n}\r\nstatic void F_51 ( struct V_3 * V_4 ,\r\nstruct V_42 * V_63 )\r\n{\r\nstruct V_38 * V_39 , * V_89 ;\r\nstruct V_42 * V_90 ;\r\nT_4 V_57 ;\r\nV_39 = F_28 ( V_63 ) ;\r\nV_57 = F_6 ( V_39 -> V_41 . V_57 ) ;\r\nF_5 ( L_35 , V_57 ) ;\r\nV_63 -> V_91 = V_92 ;\r\nF_4 ( V_39 -> V_4 , == , NULL ) ;\r\nV_39 -> V_4 = V_4 ;\r\nF_52 ( V_4 ) ;\r\nF_18 ( & V_4 -> V_30 ) ;\r\nF_53 (&call->rx_oos_queue, p) {\r\nV_89 = F_28 ( V_90 ) ;\r\nif ( F_6 ( V_89 -> V_41 . V_57 ) > V_57 ) {\r\nF_7 ( L_36 ,\r\nV_57 , F_6 ( V_89 -> V_41 . V_57 ) ) ;\r\nF_54 ( V_90 , V_63 , & V_4 -> V_84 ) ;\r\ngoto V_93;\r\n}\r\n}\r\nF_7 ( L_37 , V_57 ) ;\r\nF_55 ( & V_4 -> V_84 , V_63 ) ;\r\nV_93:\r\nif ( V_4 -> V_80 == 0 || V_57 < V_4 -> V_80 )\r\nV_4 -> V_80 = V_57 ;\r\nF_56 ( & V_4 -> V_25 ) ;\r\nif ( V_4 -> V_26 < V_27 &&\r\nV_4 -> V_79 == V_4 -> V_80 ) {\r\nF_7 ( L_38 ) ;\r\nF_21 ( V_94 , & V_4 -> V_29 ) ;\r\n}\r\nF_57 ( & V_4 -> V_25 ) ;\r\nF_19 ( & V_4 -> V_30 ) ;\r\nF_35 ( L_39 , V_4 -> V_80 ) ;\r\n}\r\nstatic void F_58 ( struct V_3 * V_4 )\r\n{\r\nstruct V_38 * V_39 ;\r\nstruct V_42 * V_63 ;\r\nunsigned long V_72 , * V_53 ;\r\nT_1 V_95 = V_4 -> V_52 ;\r\nint V_73 ;\r\nV_53 = V_4 -> V_53 ;\r\nV_4 -> V_53 = NULL ;\r\nwhile ( F_26 ( V_4 -> V_50 , V_4 -> V_51 , V_95 ) > 0 ) {\r\nV_73 = V_4 -> V_51 ;\r\nF_27 () ;\r\nV_72 = V_53 [ V_73 ] & ~ 1 ;\r\nF_39 () ;\r\nV_4 -> V_51 = ( V_4 -> V_51 + 1 ) & ( V_95 - 1 ) ;\r\nV_63 = (struct V_42 * ) V_72 ;\r\nV_39 = F_28 ( V_63 ) ;\r\nF_7 ( L_40 , F_6 ( V_39 -> V_41 . V_57 ) ) ;\r\nF_41 ( V_63 ) ;\r\n}\r\nF_59 ( V_53 ) ;\r\n}\r\nstatic void F_60 ( struct V_3 * V_4 , struct V_42 * V_63 ,\r\nunsigned int V_96 , int V_66 )\r\n{\r\nstruct V_97 V_98 ;\r\nstruct V_99 * V_100 ;\r\nunsigned int V_101 ;\r\nif ( F_38 ( V_63 , V_66 + 3 , & V_98 , sizeof( V_98 ) ) < 0 ) {\r\nF_35 ( L_41 ) ;\r\nreturn;\r\n}\r\nF_31 ( L_42 ,\r\nV_96 ,\r\nF_6 ( V_98 . V_102 ) , F_6 ( V_98 . V_103 ) ,\r\nF_6 ( V_98 . V_104 ) , F_6 ( V_98 . V_105 ) ) ;\r\nV_101 = F_61 ( F_6 ( V_98 . V_102 ) , F_6 ( V_98 . V_103 ) ) ;\r\nV_100 = V_4 -> V_55 -> V_58 -> V_100 ;\r\nif ( V_101 < V_100 -> V_106 ) {\r\nF_18 ( & V_100 -> V_30 ) ;\r\nV_100 -> V_106 = V_101 ;\r\nV_100 -> V_101 = V_101 + V_100 -> V_107 ;\r\nF_19 ( & V_100 -> V_30 ) ;\r\nF_62 ( L_43 , V_100 -> V_101 , V_100 -> V_106 ) ;\r\n}\r\n}\r\nstatic int F_63 ( struct V_3 * V_4 ,\r\nT_4 * V_108 )\r\n{\r\nstruct V_61 V_62 ;\r\nstruct V_38 * V_39 ;\r\nstruct V_42 * V_63 ;\r\nbool V_109 ;\r\nint V_96 ;\r\nT_4 V_71 , V_110 ;\r\nF_5 ( L_22 ) ;\r\nV_111:\r\nV_63 = F_46 ( & V_4 -> V_112 ) ;\r\nif ( ! V_63 )\r\nreturn - V_113 ;\r\nF_62 ( L_44 , V_63 ) ;\r\nV_39 = F_28 ( V_63 ) ;\r\nF_7 ( L_45 , V_114 [ V_39 -> V_41 . type ] , V_4 -> V_26 ) ;\r\nV_109 = false ;\r\nswitch ( V_39 -> V_41 . type ) {\r\ncase V_115 :\r\nF_31 ( L_46 ,\r\nF_6 ( V_39 -> V_41 . V_6 ) , F_6 ( V_39 -> V_41 . V_57 ) ) ;\r\nif ( F_64 ( V_4 , V_63 , V_108 ) < 0 )\r\ngoto V_67;\r\nF_51 ( V_4 , V_63 ) ;\r\ngoto V_111;\r\ncase V_116 :\r\nif ( F_38 ( V_63 , 0 , & V_62 , sizeof( V_62 ) ) < 0 ) {\r\nF_7 ( L_47 ) ;\r\ngoto V_67;\r\n}\r\nif ( ! F_65 ( V_63 , sizeof( V_62 ) ) )\r\nF_66 () ;\r\nV_96 = F_6 ( V_39 -> V_41 . V_6 ) ;\r\nV_71 = F_6 ( V_62 . V_117 ) ;\r\nV_110 = F_25 ( & V_4 -> V_49 ) ;\r\nF_31 ( L_48 ,\r\nV_96 ,\r\nF_67 ( V_62 . V_118 ) ,\r\nV_71 ,\r\nF_6 ( V_62 . V_119 ) ,\r\nF_6 ( V_62 . V_6 ) ,\r\nF_1 ( V_62 . V_1 ) ,\r\nV_62 . V_66 ) ;\r\nF_60 ( V_4 , V_63 , V_96 , V_62 . V_66 ) ;\r\nif ( V_62 . V_1 == V_120 ) {\r\nF_31 ( L_49 , V_96 ) ;\r\nF_17 ( V_4 , V_121 ,\r\nV_39 -> V_41 . V_6 , true ) ;\r\n}\r\nif ( V_96 - V_4 -> V_122 <= 0 ) {\r\nF_7 ( L_50 ,\r\nV_96 , V_4 -> V_122 ) ;\r\ngoto V_123;\r\n}\r\nV_4 -> V_122 = V_96 ;\r\nif ( V_4 -> V_26 != V_124 &&\r\nV_4 -> V_26 != V_125 &&\r\nV_4 -> V_26 != V_126 &&\r\nV_4 -> V_26 != V_127 )\r\ngoto V_123;\r\nF_7 ( L_51 , V_110 , V_4 -> V_47 , V_4 -> V_26 ) ;\r\nif ( V_71 > 0 ) {\r\nif ( V_71 - 1 > V_110 ) {\r\nF_7 ( L_52\r\nL_53 ,\r\nV_71 - 1 , V_110 ) ;\r\ngoto V_67;\r\n}\r\nif ( ( V_4 -> V_26 == V_125 ||\r\nV_4 -> V_26 == V_127 ) &&\r\nV_71 > V_110 )\r\ngoto V_128;\r\nF_68 () ;\r\nF_40 ( V_4 , V_71 - 1 ) ;\r\n}\r\nif ( V_62 . V_66 > 0 ) {\r\nif ( V_71 - 1 + V_62 . V_66 > V_110 ) {\r\nF_7 ( L_54\r\nL_55 ,\r\nV_71 - 1 , V_62 . V_66 , V_110 ) ;\r\ngoto V_67;\r\n}\r\nif ( F_37 ( V_4 , & V_62 , V_63 ) < 0 )\r\ngoto V_67;\r\n}\r\ngoto V_123;\r\ncase V_129 :\r\ngoto V_128;\r\ncase V_130 :\r\ncase V_131 :\r\nF_66 () ;\r\ncase V_132 :\r\ncase V_133 :\r\ncase V_134 :\r\nF_66 () ;\r\n}\r\nV_128:\r\nF_69 ( & V_4 -> V_25 ) ;\r\nF_7 ( L_56 , V_4 -> V_26 ) ;\r\nswitch ( V_4 -> V_26 ) {\r\ncase V_125 :\r\nV_4 -> V_26 = V_135 ;\r\nbreak;\r\ncase V_127 :\r\nF_7 ( L_57 ) ;\r\nV_4 -> V_26 = V_27 ;\r\nV_109 = true ;\r\nbreak;\r\ncase V_124 :\r\ncase V_136 :\r\ngoto V_137;\r\ndefault:\r\nF_70 ( & V_4 -> V_25 ) ;\r\ngoto V_123;\r\n}\r\nF_70 ( & V_4 -> V_25 ) ;\r\nF_7 ( L_58 ,\r\nF_26 ( V_4 -> V_50 , V_4 -> V_51 , V_4 -> V_52 ) ) ;\r\nF_22 ( & V_4 -> V_36 ) ;\r\nF_23 ( V_34 , & V_4 -> V_35 ) ;\r\nF_23 ( V_37 , & V_4 -> V_29 ) ;\r\nif ( V_4 -> V_53 )\r\nF_58 ( V_4 ) ;\r\nif ( V_109 ) {\r\nF_7 ( L_59 ) ;\r\nV_63 -> V_85 = V_138 ;\r\nV_39 -> V_4 = V_4 ;\r\nF_52 ( V_4 ) ;\r\nF_18 ( & V_4 -> V_30 ) ;\r\nif ( F_48 ( V_4 , V_63 , true , true ) < 0 )\r\nF_66 () ;\r\nF_19 ( & V_4 -> V_30 ) ;\r\ngoto V_111;\r\n}\r\nV_123:\r\nF_41 ( V_63 ) ;\r\ngoto V_111;\r\nV_137:\r\nF_70 ( & V_4 -> V_25 ) ;\r\nV_67:\r\nF_41 ( V_63 ) ;\r\nF_35 ( L_27 ) ;\r\nreturn - V_70 ;\r\n}\r\nstatic int F_71 ( struct V_3 * V_4 , T_4 V_85 , T_4 error ,\r\nbool V_139 )\r\n{\r\nstruct V_38 * V_39 ;\r\nstruct V_42 * V_63 ;\r\nint V_78 ;\r\nF_5 ( L_60 ,\r\nV_4 -> V_11 , V_4 -> V_35 , V_85 , error , V_139 ) ;\r\nif ( V_139 ) {\r\nF_22 ( & V_4 -> V_36 ) ;\r\nF_22 ( & V_4 -> V_23 ) ;\r\nF_23 ( V_34 , & V_4 -> V_35 ) ;\r\n}\r\nif ( V_85 != V_140 &&\r\n! F_45 ( V_141 , & V_4 -> V_35 ) ) {\r\nF_35 ( L_61 ) ;\r\nreturn 0 ;\r\n}\r\nif ( ! F_45 ( V_142 , & V_4 -> V_35 ) ) {\r\nV_63 = F_72 ( 0 , V_143 ) ;\r\nif ( ! V_63 )\r\nreturn - V_144 ;\r\nF_73 ( V_63 ) ;\r\nV_63 -> V_85 = V_85 ;\r\nV_39 = F_28 ( V_63 ) ;\r\nmemset ( V_39 , 0 , sizeof( * V_39 ) ) ;\r\nV_39 -> error = error ;\r\nV_39 -> V_4 = V_4 ;\r\nF_52 ( V_4 ) ;\r\nF_18 ( & V_4 -> V_30 ) ;\r\nV_78 = F_48 ( V_4 , V_63 , true , V_139 ) ;\r\nF_19 ( & V_4 -> V_30 ) ;\r\nF_49 ( V_78 < 0 ) ;\r\n}\r\nreturn 0 ;\r\n}\r\nvoid F_74 ( struct V_145 * V_146 )\r\n{\r\nstruct V_3 * V_4 =\r\nF_75 ( V_146 , struct V_3 , V_147 ) ;\r\nstruct V_61 V_62 ;\r\nstruct V_97 V_98 ;\r\nstruct V_40 V_41 ;\r\nstruct V_148 V_149 ;\r\nstruct V_150 V_151 [ 5 ] ;\r\nunsigned long V_152 ;\r\nT_2 V_153 , V_154 ;\r\nT_5 V_155 ;\r\nint V_156 , V_45 , V_157 , V_158 , V_78 , V_101 ;\r\nT_4 V_159 = V_160 ;\r\nT_1 * V_161 = NULL ;\r\nF_5 ( L_62 ,\r\nV_4 -> V_11 , V_162 [ V_4 -> V_26 ] , V_4 -> V_29 ,\r\n( V_22 - V_4 -> V_163 ) / ( V_60 / 10 ) ) ;\r\nif ( F_14 ( V_164 , & V_4 -> V_35 ) ) {\r\nF_7 ( L_63 ) ;\r\nreturn;\r\n}\r\nV_149 . V_165 = & V_4 -> V_55 -> V_58 -> V_100 -> V_166 . V_167 . sin ;\r\nV_149 . V_168 = sizeof( V_4 -> V_55 -> V_58 -> V_100 -> V_166 . V_167 . sin ) ;\r\nV_149 . V_169 = NULL ;\r\nV_149 . V_170 = 0 ;\r\nV_149 . V_171 = 0 ;\r\nV_41 . V_172 = V_4 -> V_55 -> V_172 ;\r\nV_41 . V_173 = V_4 -> V_173 ;\r\nV_41 . V_174 = V_4 -> V_175 ;\r\nV_41 . V_57 = 0 ;\r\nV_41 . type = V_116 ;\r\nV_41 . V_35 = V_4 -> V_55 -> V_176 ;\r\nV_41 . V_177 = 0 ;\r\nV_41 . V_178 = V_4 -> V_55 -> V_179 ;\r\nV_41 . V_180 = 0 ;\r\nV_41 . V_181 = V_4 -> V_55 -> V_182 ;\r\nmemset ( V_151 , 0 , sizeof( V_151 ) ) ;\r\nV_151 [ 0 ] . V_183 = & V_41 ;\r\nV_151 [ 0 ] . V_184 = sizeof( V_41 ) ;\r\nif ( F_45 ( V_185 , & V_4 -> V_29 ) ) {\r\nF_76 ( V_4 ) ;\r\nF_23 ( V_185 , & V_4 -> V_29 ) ;\r\n}\r\nif ( F_45 ( V_186 , & V_4 -> V_29 ) ) {\r\nint error ;\r\nF_23 ( V_187 , & V_4 -> V_29 ) ;\r\nF_23 ( V_188 , & V_4 -> V_29 ) ;\r\nF_23 ( V_189 , & V_4 -> V_29 ) ;\r\nerror = V_4 -> V_55 -> V_58 -> V_100 -> V_190 ;\r\nF_7 ( L_64 , error ) ;\r\nif ( F_71 ( V_4 , V_191 ,\r\nerror , true ) < 0 )\r\ngoto V_192;\r\nF_23 ( V_186 , & V_4 -> V_29 ) ;\r\ngoto V_193;\r\n}\r\nif ( F_45 ( V_187 , & V_4 -> V_29 ) ) {\r\nF_4 ( V_4 -> V_26 , > , V_27 ) ;\r\nF_23 ( V_188 , & V_4 -> V_29 ) ;\r\nF_23 ( V_189 , & V_4 -> V_29 ) ;\r\nF_7 ( L_65 ) ;\r\nif ( F_71 ( V_4 , V_194 ,\r\nV_4 -> V_55 -> error , true ) < 0 )\r\ngoto V_192;\r\nF_23 ( V_187 , & V_4 -> V_29 ) ;\r\ngoto V_193;\r\n}\r\nif ( F_45 ( V_188 , & V_4 -> V_29 ) ) {\r\nV_41 . type = V_130 ;\r\nV_156 = V_188 ;\r\ngoto V_195;\r\n}\r\nif ( F_45 ( V_189 , & V_4 -> V_29 ) ) {\r\nF_4 ( V_4 -> V_26 , > , V_27 ) ;\r\nif ( F_71 ( V_4 , V_194 ,\r\nV_196 , true ) < 0 )\r\ngoto V_192;\r\nV_41 . type = V_131 ;\r\nV_153 = F_29 ( V_4 -> V_159 ) ;\r\nV_151 [ 1 ] . V_183 = & V_153 ;\r\nV_151 [ 1 ] . V_184 = sizeof( V_153 ) ;\r\nV_156 = V_189 ;\r\ngoto V_195;\r\n}\r\nif ( F_45 ( V_197 , & V_4 -> V_29 ) ) {\r\nV_156 = V_197 ;\r\nV_62 . V_198 = F_77 ( 8 ) ;\r\nV_62 . V_118 = 0 ;\r\nV_62 . V_6 = 0 ;\r\nV_62 . V_1 = V_18 ;\r\nV_62 . V_66 = 0 ;\r\nV_4 -> V_12 = 0 ;\r\nF_18 ( & V_4 -> V_30 ) ;\r\nV_62 . V_6 = V_4 -> V_14 ;\r\nV_62 . V_119 = V_4 -> V_199 ;\r\nV_62 . V_117 = F_29 ( V_4 -> V_200 + 1 ) ;\r\nF_19 ( & V_4 -> V_30 ) ;\r\nV_154 = 0 ;\r\nV_151 [ 1 ] . V_183 = & V_62 ;\r\nV_151 [ 1 ] . V_184 = sizeof( V_62 ) ;\r\nV_151 [ 2 ] . V_183 = & V_154 ;\r\nV_151 [ 2 ] . V_184 = 3 ;\r\nV_151 [ 3 ] . V_183 = & V_98 ;\r\nV_151 [ 3 ] . V_184 = sizeof( V_98 ) ;\r\ngoto V_201;\r\n}\r\nif ( V_4 -> V_29 & ( ( 1 << V_202 ) |\r\n( 1 << V_203 ) )\r\n) {\r\nT_4 V_85 ;\r\nif ( F_45 ( V_203 , & V_4 -> V_29 ) )\r\nV_85 = V_204 ;\r\nelse\r\nV_85 = V_205 ;\r\nF_7 ( L_66 ) ;\r\nF_43 ( V_4 ) ;\r\nif ( F_71 ( V_4 , V_85 , V_196 , true ) < 0 )\r\ngoto V_192;\r\nF_23 ( V_202 , & V_4 -> V_29 ) ;\r\nF_23 ( V_203 , & V_4 -> V_29 ) ;\r\ngoto V_193;\r\n}\r\nif ( F_78 ( V_206 , & V_4 -> V_29 ) ) {\r\nF_7 ( L_67 ) ;\r\nF_43 ( V_4 ) ;\r\n}\r\nif ( F_45 ( V_207 , & V_4 -> V_29 ) ) {\r\nF_69 ( & V_4 -> V_25 ) ;\r\nif ( V_4 -> V_26 <= V_27 ) {\r\nV_4 -> V_26 = V_208 ;\r\nV_4 -> V_159 = V_209 ;\r\nF_21 ( V_189 , & V_4 -> V_29 ) ;\r\n}\r\nF_70 ( & V_4 -> V_25 ) ;\r\nF_7 ( L_68 ) ;\r\nif ( F_71 ( V_4 , V_194 ,\r\nV_210 , true ) < 0 )\r\ngoto V_192;\r\nF_23 ( V_207 , & V_4 -> V_29 ) ;\r\ngoto V_193;\r\n}\r\nif ( ! F_79 ( & V_4 -> V_112 ) ) {\r\nswitch ( F_63 ( V_4 , & V_159 ) ) {\r\ncase 0 :\r\ncase - V_113 :\r\nbreak;\r\ncase - V_144 :\r\ngoto V_192;\r\ncase - V_211 :\r\ncase - V_212 :\r\ncase - V_70 :\r\nF_80 ( V_4 , V_159 ) ;\r\ngoto V_193;\r\n}\r\n}\r\nif ( F_78 ( V_37 , & V_4 -> V_29 ) )\r\nF_36 ( V_4 ) ;\r\nif ( F_78 ( V_33 , & V_4 -> V_29 ) )\r\nF_24 ( V_4 ) ;\r\nif ( F_45 ( V_28 , & V_4 -> V_29 ) ) {\r\nF_7 ( L_69 ,\r\nV_4 -> V_200 , V_4 -> V_213 ,\r\nV_4 -> V_214 [ 0 ] ) ;\r\nif ( V_4 -> V_26 > V_215 &&\r\nV_4 -> V_12 != V_121 ) {\r\nF_23 ( V_28 , & V_4 -> V_29 ) ;\r\ngoto V_216;\r\n}\r\nV_156 = V_28 ;\r\nV_161 = F_81 ( V_4 -> V_213 - V_4 -> V_200 ,\r\nV_143 ) ;\r\nif ( ! V_161 )\r\ngoto V_192;\r\nV_62 . V_198 = F_77 ( 8 ) ;\r\nV_62 . V_118 = 0 ;\r\nV_62 . V_6 = 0 ;\r\nV_62 . V_1 = 0 ;\r\nF_18 ( & V_4 -> V_30 ) ;\r\nV_62 . V_1 = V_4 -> V_12 ;\r\nV_62 . V_6 = V_4 -> V_14 ;\r\nV_62 . V_119 = V_4 -> V_199 ;\r\nV_62 . V_117 = F_29 ( V_4 -> V_200 + 1 ) ;\r\nV_62 . V_66 = 0 ;\r\nfor ( V_45 = 0 ; V_45 < V_217 ; V_45 ++ ) {\r\nV_157 = V_45 * V_218 ;\r\nfor ( V_152 = V_4 -> V_214 [ V_45 ] ; V_152 ; V_152 >>= 1\r\n) {\r\nF_7 ( L_70 , V_45 , V_157 , V_152 ) ;\r\nif ( V_152 & 1 ) {\r\nV_161 [ V_157 ] = V_68 ;\r\nV_62 . V_66 = V_157 + 1 ;\r\n}\r\nV_157 ++ ;\r\n}\r\n}\r\nV_4 -> V_12 = 0 ;\r\nF_19 ( & V_4 -> V_30 ) ;\r\nV_154 = 0 ;\r\nV_151 [ 1 ] . V_183 = & V_62 ;\r\nV_151 [ 1 ] . V_184 = sizeof( V_62 ) ;\r\nV_151 [ 2 ] . V_183 = V_161 ;\r\nV_151 [ 2 ] . V_184 = V_62 . V_66 ;\r\nV_151 [ 3 ] . V_183 = & V_154 ;\r\nV_151 [ 3 ] . V_184 = 3 ;\r\nV_151 [ 4 ] . V_183 = & V_98 ;\r\nV_151 [ 4 ] . V_184 = sizeof( V_98 ) ;\r\nswitch ( V_62 . V_1 ) {\r\ncase V_20 :\r\ncase V_219 :\r\ncase V_220 :\r\ncase V_221 :\r\ncase V_222 :\r\ncase V_120 :\r\ncase V_121 :\r\ngoto V_223;\r\ncase V_15 :\r\ncase V_18 :\r\ngoto V_201;\r\n}\r\n}\r\nif ( F_78 ( V_224 , & V_4 -> V_29 ) ) {\r\nF_7 ( L_71 ) ;\r\nF_18 ( & V_4 -> V_30 ) ;\r\nif ( V_4 -> V_26 == V_225 ) {\r\nF_7 ( L_72 ) ;\r\nF_82 ( & V_4 -> V_55 -> V_30 ) ;\r\nif ( ! F_45 ( V_82 , & V_4 -> V_35 ) &&\r\n! F_45 ( V_185 , & V_4 -> V_29 ) ) {\r\nF_7 ( L_73 ) ;\r\nV_4 -> V_26 = V_226 ;\r\nF_83 ( & V_4 -> V_227 ,\r\n& V_4 -> V_228 -> V_229 ) ;\r\n}\r\nF_84 ( & V_4 -> V_55 -> V_30 ) ;\r\nF_56 ( & V_4 -> V_25 ) ;\r\nif ( V_4 -> V_26 < V_27 )\r\nF_21 ( V_230 , & V_4 -> V_29 ) ;\r\nF_57 ( & V_4 -> V_25 ) ;\r\n}\r\nF_19 ( & V_4 -> V_30 ) ;\r\nif ( ! F_45 ( V_230 , & V_4 -> V_29 ) )\r\ngoto V_216;\r\n}\r\nif ( F_45 ( V_230 , & V_4 -> V_29 ) ) {\r\nF_7 ( L_74 ) ;\r\nif ( F_71 ( V_4 , V_140 ,\r\n0 , false ) < 0 )\r\ngoto V_192;\r\nF_23 ( V_230 , & V_4 -> V_29 ) ;\r\ngoto V_216;\r\n}\r\nif ( F_78 ( V_231 , & V_4 -> V_29 ) ) {\r\nF_7 ( L_75 ) ;\r\nF_4 ( V_4 -> V_79 , == , 0 ) ;\r\nV_4 -> V_79 = 1 ;\r\nF_13 ( & V_4 -> V_25 ) ;\r\nif ( V_4 -> V_26 < V_27 )\r\nF_21 ( V_94 , & V_4 -> V_29 ) ;\r\nF_16 ( & V_4 -> V_25 ) ;\r\n}\r\nif ( F_78 ( V_94 , & V_4 -> V_29 ) ) {\r\nwhile ( V_4 -> V_79 == V_4 -> V_80 )\r\nif ( F_44 ( V_4 ) < 0 )\r\nbreak;\r\ngoto V_216;\r\n}\r\ngoto V_216;\r\nV_223:\r\nV_62 . V_118 = F_77 ( F_25 ( & V_4 -> V_55 -> V_232 ) -\r\nF_6 ( V_62 . V_6 ) ) ;\r\nV_201:\r\nV_101 = V_4 -> V_55 -> V_58 -> V_100 -> V_233 ;\r\nV_101 -= V_4 -> V_55 -> V_58 -> V_100 -> V_107 ;\r\nV_98 . V_103 = F_29 ( V_101 ) ;\r\nV_98 . V_104 = F_29 ( V_234 ) ;\r\nV_98 . V_102 = F_29 ( V_235 ) ;\r\nV_98 . V_105 = F_29 ( V_236 ) ;\r\nV_41 . V_6 = F_29 ( F_30 ( & V_4 -> V_55 -> V_6 ) ) ;\r\nF_31 ( L_76 ,\r\nF_6 ( V_41 . V_6 ) ,\r\nF_67 ( V_62 . V_118 ) ,\r\nF_6 ( V_62 . V_117 ) ,\r\nF_6 ( V_62 . V_119 ) ,\r\nF_6 ( V_62 . V_6 ) ,\r\nF_1 ( V_62 . V_1 ) ,\r\nV_62 . V_66 ) ;\r\nF_22 ( & V_4 -> V_23 ) ;\r\nif ( V_62 . V_66 > 0 )\r\nF_21 ( V_237 , & V_4 -> V_35 ) ;\r\ngoto V_238;\r\nV_195:\r\nF_7 ( L_77 ) ;\r\nV_41 . V_6 = F_29 ( F_30 ( & V_4 -> V_55 -> V_6 ) ) ;\r\nF_31 ( L_78 , V_114 [ V_41 . type ] , F_6 ( V_41 . V_6 ) ) ;\r\nV_238:\r\nV_155 = V_151 [ 0 ] . V_184 ;\r\nV_158 = 1 ;\r\nif ( V_151 [ 4 ] . V_184 ) {\r\nV_158 = 5 ;\r\nV_155 += V_151 [ 4 ] . V_184 ;\r\nV_155 += V_151 [ 3 ] . V_184 ;\r\nV_155 += V_151 [ 2 ] . V_184 ;\r\nV_155 += V_151 [ 1 ] . V_184 ;\r\n} else if ( V_151 [ 3 ] . V_184 ) {\r\nV_158 = 4 ;\r\nV_155 += V_151 [ 3 ] . V_184 ;\r\nV_155 += V_151 [ 2 ] . V_184 ;\r\nV_155 += V_151 [ 1 ] . V_184 ;\r\n} else if ( V_151 [ 2 ] . V_184 ) {\r\nV_158 = 3 ;\r\nV_155 += V_151 [ 2 ] . V_184 ;\r\nV_155 += V_151 [ 1 ] . V_184 ;\r\n} else if ( V_151 [ 1 ] . V_184 ) {\r\nV_158 = 2 ;\r\nV_155 += V_151 [ 1 ] . V_184 ;\r\n}\r\nV_78 = F_85 ( V_4 -> V_55 -> V_58 -> V_239 -> V_228 ,\r\n& V_149 , V_151 , V_158 , V_155 ) ;\r\nif ( V_78 < 0 ) {\r\nF_7 ( L_79 , V_78 ) ;\r\nF_13 ( & V_4 -> V_25 ) ;\r\nif ( V_4 -> V_26 < V_240 )\r\nF_15 ( V_4 ) ;\r\nF_16 ( & V_4 -> V_25 ) ;\r\ngoto error;\r\n}\r\nswitch ( V_156 ) {\r\ncase V_189 :\r\nF_23 ( V_156 , & V_4 -> V_29 ) ;\r\nF_23 ( V_203 , & V_4 -> V_29 ) ;\r\ngoto V_193;\r\ncase V_197 :\r\nF_69 ( & V_4 -> V_25 ) ;\r\nif ( V_4 -> V_26 == V_241 )\r\nV_4 -> V_26 = V_27 ;\r\nF_70 ( & V_4 -> V_25 ) ;\r\ngoto V_193;\r\ndefault:\r\nF_23 ( V_156 , & V_4 -> V_29 ) ;\r\nswitch ( V_4 -> V_26 ) {\r\ncase V_125 :\r\ncase V_135 :\r\ncase V_136 :\r\ncase V_215 :\r\nF_7 ( L_80 ) ;\r\nF_17 ( V_4 , V_15 ,\r\nV_4 -> V_14 , false ) ;\r\ndefault:\r\nbreak;\r\n}\r\ngoto V_216;\r\n}\r\nV_193:\r\nF_22 ( & V_4 -> V_23 ) ;\r\nif ( F_78 ( V_197 , & V_4 -> V_29 ) )\r\nF_86 ( V_4 ) ;\r\nF_23 ( V_28 , & V_4 -> V_29 ) ;\r\nV_216:\r\nif ( V_4 -> V_29 || ! F_79 ( & V_4 -> V_112 ) ) {\r\nF_13 ( & V_4 -> V_25 ) ;\r\nif ( V_4 -> V_26 < V_240 )\r\nF_15 ( V_4 ) ;\r\nF_16 ( & V_4 -> V_25 ) ;\r\n}\r\nif ( V_4 -> V_26 >= V_27 &&\r\n! F_87 ( & V_4 -> V_227 ) ) {\r\nF_7 ( L_81 ,\r\nV_4 , V_4 -> V_29 , V_4 -> V_35 ,\r\nF_6 ( V_4 -> V_55 -> V_173 ) ) ;\r\nF_13 ( & V_4 -> V_25 ) ;\r\nif ( ! F_45 ( V_82 , & V_4 -> V_35 ) &&\r\n! F_14 ( V_185 , & V_4 -> V_29 ) )\r\nF_15 ( V_4 ) ;\r\nF_16 ( & V_4 -> V_25 ) ;\r\n}\r\nerror:\r\nF_23 ( V_164 , & V_4 -> V_35 ) ;\r\nF_59 ( V_161 ) ;\r\nif ( V_4 -> V_29 && ! F_88 ( & V_4 -> V_147 ) ) {\r\nF_7 ( L_82 , F_6 ( V_4 -> V_55 -> V_173 ) ) ;\r\nF_15 ( V_4 ) ;\r\n}\r\nF_35 ( L_22 ) ;\r\nreturn;\r\nV_192:\r\nF_7 ( L_83 ) ;\r\ngoto V_216;\r\n}
