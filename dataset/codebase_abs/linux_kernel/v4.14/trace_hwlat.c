static void F_1 ( struct V_1 * V_2 )\r\n{\r\nstruct V_3 * V_4 = V_5 ;\r\nstruct V_6 * V_7 = & V_8 ;\r\nstruct V_9 * V_10 = V_4 -> V_11 . V_10 ;\r\nstruct V_12 * V_13 ;\r\nstruct V_14 * V_15 ;\r\nunsigned long V_16 ;\r\nint V_17 ;\r\nV_17 = F_2 () ;\r\nF_3 ( V_16 ) ;\r\nV_13 = F_4 ( V_10 , V_18 , sizeof( * V_15 ) ,\r\nV_16 , V_17 ) ;\r\nif ( ! V_13 )\r\nreturn;\r\nV_15 = F_5 ( V_13 ) ;\r\nV_15 -> V_19 = V_2 -> V_19 ;\r\nV_15 -> V_20 = V_2 -> V_20 ;\r\nV_15 -> V_21 = V_2 -> V_21 ;\r\nV_15 -> V_22 = V_2 -> V_22 ;\r\nV_15 -> V_23 = V_2 -> V_23 ;\r\nV_15 -> V_24 = V_2 -> V_24 ;\r\nif ( ! F_6 ( V_7 , V_15 , V_10 , V_13 ) )\r\nF_7 ( V_10 , V_13 ) ;\r\n}\r\nvoid F_8 ( bool V_25 )\r\n{\r\nif ( F_9 () != V_26 )\r\nreturn;\r\nif ( ! F_10 ( V_27 ) ) {\r\nif ( V_25 )\r\nV_28 = F_11 () ;\r\nelse\r\nV_23 = F_11 () - V_28 ;\r\n}\r\nif ( V_25 )\r\nV_24 ++ ;\r\n}\r\nstatic int F_12 ( void )\r\n{\r\nstruct V_3 * V_4 = V_5 ;\r\nT_1 V_29 , V_30 , V_31 , V_32 ;\r\nT_2 V_33 , V_34 , V_35 = 0 ;\r\nT_3 V_2 = 0 ;\r\nT_3 V_36 = V_37 ;\r\nT_3 V_38 = 0 ;\r\nint V_39 = - 1 ;\r\nF_13 ( V_36 , V_40 ) ;\r\nV_26 = F_9 () ;\r\nV_23 = 0 ;\r\nV_24 = 0 ;\r\nF_14 () ;\r\nV_41 = true ;\r\nF_15 ( V_32 , 0 ) ;\r\nV_29 = F_11 () ;\r\ndo {\r\nV_30 = F_11 () ;\r\nV_31 = F_11 () ;\r\nif ( F_16 ( V_32 ) ) {\r\nV_33 = F_17 ( F_18 ( V_30 , V_32 ) ) ;\r\nif ( V_33 < 0 ) {\r\nF_19 ( V_42 L_1 ) ;\r\ngoto V_43;\r\n}\r\nif ( V_33 > V_38 )\r\nV_38 = V_33 ;\r\n}\r\nV_32 = V_31 ;\r\nV_34 = F_17 ( F_18 ( V_31 , V_29 ) ) ;\r\nif ( V_34 < V_35 ) {\r\nF_19 ( L_2 ) ;\r\nbreak;\r\n}\r\nV_35 = V_34 ;\r\nV_33 = F_17 ( F_18 ( V_31 , V_30 ) ) ;\r\nif ( V_33 < 0 ) {\r\nF_19 ( V_42 L_1 ) ;\r\ngoto V_43;\r\n}\r\nif ( V_33 > V_2 )\r\nV_2 = V_33 ;\r\n} while ( V_34 <= V_44 . V_45 );\r\nF_14 () ;\r\nV_41 = false ;\r\nF_14 () ;\r\nV_39 = 0 ;\r\nif ( V_2 > V_36 || V_38 > V_36 ) {\r\nstruct V_1 V_46 ;\r\nV_39 = 1 ;\r\nif ( V_23 )\r\nF_13 ( V_23 , V_40 ) ;\r\nV_44 . V_47 ++ ;\r\nV_46 . V_19 = V_44 . V_47 ;\r\nV_46 . V_20 = V_2 ;\r\nV_46 . V_21 = V_38 ;\r\nF_20 ( & V_46 . V_22 ) ;\r\nV_46 . V_23 = V_23 ;\r\nV_46 . V_24 = V_24 ;\r\nF_1 ( & V_46 ) ;\r\nif ( V_2 > V_4 -> V_48 )\r\nV_4 -> V_48 = V_2 ;\r\n}\r\nV_43:\r\nreturn V_39 ;\r\n}\r\nstatic void F_21 ( void )\r\n{\r\nstruct V_49 * V_50 = & V_51 ;\r\nint V_52 ;\r\nif ( V_53 )\r\nreturn;\r\nif ( ! F_22 ( V_50 , & V_54 -> V_55 ) )\r\ngoto V_56;\r\nF_23 () ;\r\nF_24 ( V_50 , V_57 , V_58 ) ;\r\nV_52 = F_25 ( F_9 () , V_50 ) ;\r\nF_26 () ;\r\nif ( V_52 >= V_59 )\r\nV_52 = F_27 ( V_50 ) ;\r\nif ( V_52 >= V_59 )\r\ngoto V_56;\r\nF_28 ( V_50 ) ;\r\nF_29 ( V_52 , V_50 ) ;\r\nF_30 ( 0 , V_50 ) ;\r\nreturn;\r\nV_56:\r\nV_53 = true ;\r\n}\r\nstatic int F_31 ( void * V_60 )\r\n{\r\nT_3 V_61 ;\r\nwhile ( ! F_32 () ) {\r\nF_21 () ;\r\nF_33 () ;\r\nF_12 () ;\r\nF_34 () ;\r\nF_35 ( & V_44 . V_62 ) ;\r\nV_61 = V_44 . V_63 - V_44 . V_45 ;\r\nF_36 ( & V_44 . V_62 ) ;\r\nF_13 ( V_61 , V_64 ) ;\r\nif ( V_61 < 1 )\r\nV_61 = 1 ;\r\nif ( F_37 ( V_61 ) )\r\nbreak;\r\n}\r\nreturn 0 ;\r\n}\r\nstatic int F_38 ( struct V_3 * V_4 )\r\n{\r\nstruct V_49 * V_50 = & V_51 ;\r\nstruct V_65 * V_66 ;\r\nint V_52 ;\r\nV_50 = & V_51 ;\r\nF_23 () ;\r\nF_24 ( V_50 , V_57 , V_58 ) ;\r\nF_26 () ;\r\nV_52 = F_27 ( V_50 ) ;\r\nV_66 = F_39 ( F_31 , NULL , L_3 ) ;\r\nif ( F_40 ( V_66 ) ) {\r\nF_19 ( V_42 L_4 ) ;\r\nreturn - V_67 ;\r\n}\r\nF_28 ( V_50 ) ;\r\nF_29 ( V_52 , V_50 ) ;\r\nF_30 ( V_66 -> V_68 , V_50 ) ;\r\nV_69 = V_66 ;\r\nF_41 ( V_66 ) ;\r\nreturn 0 ;\r\n}\r\nstatic void F_42 ( void )\r\n{\r\nif ( ! V_69 )\r\nreturn;\r\nF_43 ( V_69 ) ;\r\nV_69 = NULL ;\r\n}\r\nstatic T_4 F_44 ( struct V_70 * V_71 , char T_5 * V_72 ,\r\nT_6 V_73 , T_7 * V_74 )\r\n{\r\nchar V_75 [ V_76 ] ;\r\nT_3 * V_15 = V_71 -> V_77 ;\r\nT_3 V_78 ;\r\nint V_79 ;\r\nif ( ! V_15 )\r\nreturn - V_80 ;\r\nif ( V_73 > sizeof( V_75 ) )\r\nV_73 = sizeof( V_75 ) ;\r\nV_78 = * V_15 ;\r\nV_79 = snprintf ( V_75 , sizeof( V_75 ) , L_5 , V_78 ) ;\r\nreturn F_45 ( V_72 , V_73 , V_74 , V_75 , V_79 ) ;\r\n}\r\nstatic T_4\r\nF_46 ( struct V_70 * V_71 , const char T_5 * V_72 ,\r\nT_6 V_73 , T_7 * V_74 )\r\n{\r\nT_3 V_78 ;\r\nint V_81 ;\r\nV_81 = F_47 ( V_72 , V_73 , 10 , & V_78 ) ;\r\nif ( V_81 )\r\nreturn V_81 ;\r\nF_35 ( & V_44 . V_62 ) ;\r\nif ( V_78 < V_44 . V_63 )\r\nV_44 . V_45 = V_78 ;\r\nelse\r\nV_81 = - V_82 ;\r\nF_36 ( & V_44 . V_62 ) ;\r\nif ( V_81 )\r\nreturn V_81 ;\r\nreturn V_73 ;\r\n}\r\nstatic T_4\r\nF_48 ( struct V_70 * V_71 , const char T_5 * V_72 ,\r\nT_6 V_73 , T_7 * V_74 )\r\n{\r\nT_3 V_78 ;\r\nint V_81 ;\r\nV_81 = F_47 ( V_72 , V_73 , 10 , & V_78 ) ;\r\nif ( V_81 )\r\nreturn V_81 ;\r\nF_35 ( & V_44 . V_62 ) ;\r\nif ( V_44 . V_45 < V_78 )\r\nV_44 . V_63 = V_78 ;\r\nelse\r\nV_81 = - V_82 ;\r\nF_36 ( & V_44 . V_62 ) ;\r\nif ( V_81 )\r\nreturn V_81 ;\r\nreturn V_73 ;\r\n}\r\nstatic int F_49 ( void )\r\n{\r\nstruct V_83 * V_84 ;\r\nstruct V_83 * V_85 ;\r\nV_84 = F_50 () ;\r\nif ( F_40 ( V_84 ) )\r\nreturn - V_67 ;\r\nV_85 = F_51 ( L_6 , V_84 ) ;\r\nif ( ! V_85 )\r\nreturn - V_67 ;\r\nV_86 = F_52 ( L_7 , 0640 ,\r\nV_85 ,\r\n& V_44 . V_63 ,\r\n& V_87 ) ;\r\nif ( ! V_86 )\r\ngoto V_81;\r\nV_88 = F_52 ( L_8 , 0644 ,\r\nV_85 ,\r\n& V_44 . V_45 ,\r\n& V_89 ) ;\r\nif ( ! V_88 )\r\ngoto V_81;\r\nreturn 0 ;\r\nV_81:\r\nF_53 ( V_85 ) ;\r\nreturn - V_67 ;\r\n}\r\nstatic void F_54 ( struct V_3 * V_4 )\r\n{\r\nint V_81 ;\r\nV_81 = F_38 ( V_4 ) ;\r\nif ( V_81 )\r\nF_19 ( V_42 L_9 ) ;\r\n}\r\nstatic void F_55 ( struct V_3 * V_4 )\r\n{\r\nF_42 () ;\r\n}\r\nstatic int F_56 ( struct V_3 * V_4 )\r\n{\r\nif ( V_90 )\r\nreturn - V_91 ;\r\nV_5 = V_4 ;\r\nV_53 = false ;\r\nV_44 . V_47 = 0 ;\r\nV_4 -> V_48 = 0 ;\r\nV_92 = V_37 ;\r\nif ( ! V_37 )\r\nV_37 = V_93 ;\r\nif ( F_57 ( V_4 ) )\r\nF_54 ( V_4 ) ;\r\nV_90 = true ;\r\nreturn 0 ;\r\n}\r\nstatic void F_58 ( struct V_3 * V_4 )\r\n{\r\nF_42 () ;\r\nV_93 = V_37 ;\r\nV_37 = V_92 ;\r\nV_90 = false ;\r\n}\r\nT_8 static int F_59 ( void )\r\n{\r\nint V_39 ;\r\nF_60 ( & V_44 . V_62 ) ;\r\nV_39 = F_61 ( & V_94 ) ;\r\nif ( V_39 )\r\nreturn V_39 ;\r\nF_49 () ;\r\nreturn 0 ;\r\n}
