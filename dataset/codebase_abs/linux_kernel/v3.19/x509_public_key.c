static int T_1 F_1 ( char * V_1 )\r\n{\r\nif ( ! V_1 )\r\nreturn 1 ;\r\nif ( strncmp ( V_1 , L_1 , 3 ) == 0 ) {\r\nstruct V_2 * V_3 ;\r\nV_3 = F_2 ( V_1 + 3 ) ;\r\nif ( V_3 == F_3 ( - V_4 ) )\r\nF_4 ( L_2 ) ;\r\nelse if ( ! F_5 ( V_3 ) )\r\nV_5 = V_3 ;\r\n} else if ( strcmp ( V_1 , L_3 ) == 0 ) {\r\nV_6 = true ;\r\n}\r\nreturn 1 ;\r\n}\r\nstruct V_7 * F_6 ( struct V_7 * V_8 ,\r\nconst struct V_2 * V_9 ,\r\nbool V_10 )\r\n{\r\nT_2 V_7 ;\r\nchar * V_11 , * V_3 ;\r\nV_3 = V_11 = F_7 ( 2 + 1 + V_9 -> V_12 * 2 + 1 , V_13 ) ;\r\nif ( ! V_11 )\r\nreturn F_3 ( - V_14 ) ;\r\nif ( V_10 ) {\r\n* V_3 ++ = 'i' ;\r\n* V_3 ++ = 'd' ;\r\n} else {\r\n* V_3 ++ = 'e' ;\r\n* V_3 ++ = 'x' ;\r\n}\r\n* V_3 ++ = ':' ;\r\nV_3 = F_8 ( V_3 , V_9 -> V_15 , V_9 -> V_12 ) ;\r\n* V_3 = 0 ;\r\nF_9 ( L_4 , V_11 ) ;\r\nV_7 = F_10 ( F_11 ( V_8 , 1 ) ,\r\n& V_16 , V_11 ) ;\r\nif ( F_5 ( V_7 ) )\r\nF_9 ( L_5 , V_11 , F_12 ( V_7 ) ) ;\r\nF_13 ( V_11 ) ;\r\nif ( F_5 ( V_7 ) ) {\r\nswitch ( F_12 ( V_7 ) ) {\r\ncase - V_17 :\r\ncase - V_18 :\r\ncase - V_19 :\r\nreturn F_3 ( - V_20 ) ;\r\ndefault:\r\nreturn F_14 ( V_7 ) ;\r\n}\r\n}\r\nF_15 ( L_6 , V_21 ,\r\nF_16 ( F_17 ( V_7 ) ) ) ;\r\nreturn F_17 ( V_7 ) ;\r\n}\r\nint F_18 ( struct V_22 * V_23 )\r\n{\r\nstruct V_24 * V_25 ;\r\nstruct V_26 * V_27 ;\r\nT_3 V_28 , V_29 ;\r\nvoid * V_30 ;\r\nint V_31 ;\r\nF_15 ( L_7 , V_21 ) ;\r\nif ( V_23 -> V_32 )\r\nreturn - V_33 ;\r\nif ( V_23 -> V_34 . V_35 . V_36 )\r\nreturn 0 ;\r\nV_23 -> V_34 . V_35 . V_36 = F_19 ( V_23 -> V_37 , V_23 -> V_38 ) ;\r\nif ( ! V_23 -> V_34 . V_35 . V_36 )\r\nreturn - V_14 ;\r\nV_23 -> V_34 . V_39 = 1 ;\r\nV_25 = F_20 ( V_40 [ V_23 -> V_34 . V_41 ] , 0 , 0 ) ;\r\nif ( F_5 ( V_25 ) ) {\r\nif ( F_12 ( V_25 ) == - V_42 ) {\r\nV_23 -> V_32 = true ;\r\nreturn - V_33 ;\r\n}\r\nreturn F_12 ( V_25 ) ;\r\n}\r\nV_29 = F_21 ( V_25 ) + sizeof( * V_27 ) ;\r\nV_28 = F_22 ( V_25 ) ;\r\nV_31 = - V_14 ;\r\nV_30 = F_23 ( V_28 + V_29 , V_13 ) ;\r\nif ( ! V_30 )\r\ngoto error;\r\nV_23 -> V_34 . V_30 = V_30 ;\r\nV_23 -> V_34 . V_28 = V_28 ;\r\nV_27 = V_30 + V_28 ;\r\nV_27 -> V_25 = V_25 ;\r\nV_27 -> V_43 = V_44 ;\r\nV_31 = F_24 ( V_27 ) ;\r\nif ( V_31 < 0 )\r\ngoto error;\r\nF_25 () ;\r\nV_31 = F_26 ( V_27 , V_23 -> V_45 , V_23 -> V_46 , V_30 ) ;\r\nerror:\r\nF_27 ( V_25 ) ;\r\nF_15 ( L_8 , V_21 , V_31 ) ;\r\nreturn V_31 ;\r\n}\r\nint F_28 ( const struct V_47 * V_48 ,\r\nstruct V_22 * V_23 )\r\n{\r\nint V_31 ;\r\nF_15 ( L_7 , V_21 ) ;\r\nV_31 = F_18 ( V_23 ) ;\r\nif ( V_31 < 0 )\r\nreturn V_31 ;\r\nV_31 = F_29 ( V_48 , & V_23 -> V_34 ) ;\r\nif ( V_31 == - V_33 )\r\nV_23 -> V_32 = true ;\r\nF_9 ( L_9 , V_31 ) ;\r\nreturn V_31 ;\r\n}\r\nstatic int F_30 ( struct V_22 * V_23 ,\r\nstruct V_7 * V_49 )\r\n{\r\nstruct V_7 * V_7 ;\r\nint V_31 = 1 ;\r\nif ( ! V_49 )\r\nreturn - V_50 ;\r\nif ( V_5 && ! F_31 ( V_23 -> V_51 , V_5 ) )\r\nreturn - V_52 ;\r\nV_7 = F_6 ( V_49 , V_23 -> V_51 ,\r\nfalse ) ;\r\nif ( ! F_5 ( V_7 ) ) {\r\nif ( ! V_6\r\n|| F_32 ( V_53 , & V_7 -> V_43 ) )\r\nV_31 = F_28 ( V_7 -> V_54 . V_15 , V_23 ) ;\r\nF_33 ( V_7 ) ;\r\n}\r\nreturn V_31 ;\r\n}\r\nstatic int F_34 ( struct V_55 * V_56 )\r\n{\r\nstruct V_57 * V_58 ;\r\nstruct V_22 * V_23 ;\r\nconst char * V_59 ;\r\nT_3 V_60 , V_61 ;\r\nchar * V_27 = NULL , * V_3 ;\r\nint V_31 ;\r\nV_23 = F_35 ( V_56 -> V_15 , V_56 -> V_62 ) ;\r\nif ( F_5 ( V_23 ) )\r\nreturn F_12 ( V_23 ) ;\r\nF_15 ( L_10 , V_23 -> V_63 ) ;\r\nF_15 ( L_11 , V_23 -> V_64 ) ;\r\nif ( V_23 -> V_48 -> V_65 >= V_66 ||\r\nV_23 -> V_34 . V_65 >= V_66 ||\r\nV_23 -> V_34 . V_41 >= V_67 ||\r\n! V_65 [ V_23 -> V_48 -> V_65 ] ||\r\n! V_65 [ V_23 -> V_34 . V_65 ] ||\r\n! V_40 [ V_23 -> V_34 . V_41 ] ) {\r\nV_31 = - V_33 ;\r\ngoto V_68;\r\n}\r\nF_15 ( L_12 , V_69 [ V_23 -> V_48 -> V_65 ] ) ;\r\nF_15 ( L_13 ,\r\nV_23 -> V_70 . V_71 + 1900 , V_23 -> V_70 . V_72 + 1 ,\r\nV_23 -> V_70 . V_73 , V_23 -> V_70 . V_74 ,\r\nV_23 -> V_70 . V_75 , V_23 -> V_70 . V_76 ) ;\r\nF_15 ( L_14 ,\r\nV_23 -> V_77 . V_71 + 1900 , V_23 -> V_77 . V_72 + 1 ,\r\nV_23 -> V_77 . V_73 , V_23 -> V_77 . V_74 ,\r\nV_23 -> V_77 . V_75 , V_23 -> V_77 . V_76 ) ;\r\nF_15 ( L_15 ,\r\nV_69 [ V_23 -> V_34 . V_65 ] ,\r\nV_40 [ V_23 -> V_34 . V_41 ] ) ;\r\nV_23 -> V_48 -> V_78 = V_65 [ V_23 -> V_48 -> V_65 ] ;\r\nV_23 -> V_48 -> V_79 = V_80 ;\r\nif ( ! V_23 -> V_51 ||\r\nF_36 ( V_23 -> V_81 , V_23 -> V_51 ) ) {\r\nV_31 = F_28 ( V_23 -> V_48 , V_23 ) ;\r\nif ( V_31 < 0 )\r\ngoto V_68;\r\n} else if ( ! V_56 -> V_82 ) {\r\nV_31 = F_30 ( V_23 , F_37 () ) ;\r\nif ( ! V_31 )\r\nV_56 -> V_82 = 1 ;\r\n}\r\nV_61 = strlen ( V_23 -> V_64 ) ;\r\nif ( V_23 -> V_83 ) {\r\nV_60 = V_23 -> V_84 ;\r\nV_59 = V_23 -> V_83 ;\r\n} else {\r\nV_60 = V_23 -> V_85 ;\r\nV_59 = V_23 -> V_86 ;\r\n}\r\nif ( V_60 > 1 && * V_59 == 0 ) {\r\nV_60 -- ;\r\nV_59 ++ ;\r\n}\r\nV_31 = - V_14 ;\r\nV_27 = F_7 ( V_61 + 2 + V_60 * 2 + 1 , V_13 ) ;\r\nif ( ! V_27 )\r\ngoto V_68;\r\nV_3 = memcpy ( V_27 , V_23 -> V_64 , V_61 ) ;\r\nV_3 += V_61 ;\r\n* V_3 ++ = ':' ;\r\n* V_3 ++ = ' ' ;\r\nV_3 = F_8 ( V_3 , V_59 , V_60 ) ;\r\n* V_3 = 0 ;\r\nV_58 = F_7 ( sizeof( struct V_57 ) , V_13 ) ;\r\nif ( ! V_58 )\r\ngoto V_87;\r\nV_58 -> V_11 [ 0 ] = V_23 -> V_11 ;\r\nV_58 -> V_11 [ 1 ] = V_23 -> V_81 ;\r\nF_38 ( V_88 . V_89 ) ;\r\nV_56 -> V_90 [ 0 ] = & V_88 ;\r\nV_56 -> V_90 [ 1 ] = V_58 ;\r\nV_56 -> V_54 [ 0 ] = V_23 -> V_48 ;\r\nV_56 -> V_91 = V_27 ;\r\nV_56 -> V_92 = 100 ;\r\nV_23 -> V_48 = NULL ;\r\nV_23 -> V_11 = NULL ;\r\nV_23 -> V_81 = NULL ;\r\nV_27 = NULL ;\r\nV_31 = 0 ;\r\nV_87:\r\nF_13 ( V_27 ) ;\r\nV_68:\r\nF_39 ( V_23 ) ;\r\nreturn V_31 ;\r\n}\r\nstatic int T_1 F_40 ( void )\r\n{\r\nreturn F_41 ( & V_93 ) ;\r\n}\r\nstatic void T_4 F_42 ( void )\r\n{\r\nF_43 ( & V_93 ) ;\r\n}
