static const struct V_1 * F_1 ( const char * V_2 )\r\n{\r\nconst struct V_1 * type = F_2 ( - V_3 ) ;\r\nstruct V_4 * V_5 ;\r\nF_3 ( & V_6 ) ;\r\nF_4 (node, &alg_types, list) {\r\nif ( strcmp ( V_5 -> type -> V_2 , V_2 ) )\r\ncontinue;\r\nif ( F_5 ( V_5 -> type -> V_7 ) )\r\ntype = V_5 -> type ;\r\nbreak;\r\n}\r\nF_6 ( & V_6 ) ;\r\nreturn type ;\r\n}\r\nint F_7 ( const struct V_1 * type )\r\n{\r\nstruct V_4 * V_5 ;\r\nint V_8 = - V_9 ;\r\nF_8 ( & V_6 ) ;\r\nF_4 (node, &alg_types, list) {\r\nif ( ! strcmp ( V_5 -> type -> V_2 , type -> V_2 ) )\r\ngoto V_10;\r\n}\r\nV_5 = F_9 ( sizeof( * V_5 ) , V_11 ) ;\r\nV_8 = - V_12 ;\r\nif ( ! V_5 )\r\ngoto V_10;\r\ntype -> V_13 -> V_7 = V_14 ;\r\nif ( type -> V_15 )\r\ntype -> V_15 -> V_7 = V_14 ;\r\nV_5 -> type = type ;\r\nF_10 ( & V_5 -> V_16 , & V_17 ) ;\r\nV_8 = 0 ;\r\nV_10:\r\nF_11 ( & V_6 ) ;\r\nreturn V_8 ;\r\n}\r\nint F_12 ( const struct V_1 * type )\r\n{\r\nstruct V_4 * V_5 ;\r\nint V_8 = - V_3 ;\r\nF_8 ( & V_6 ) ;\r\nF_4 (node, &alg_types, list) {\r\nif ( strcmp ( V_5 -> type -> V_2 , type -> V_2 ) )\r\ncontinue;\r\nF_13 ( & V_5 -> V_16 ) ;\r\nF_14 ( V_5 ) ;\r\nV_8 = 0 ;\r\nbreak;\r\n}\r\nF_11 ( & V_6 ) ;\r\nreturn V_8 ;\r\n}\r\nstatic void F_15 ( const struct V_1 * type , void * V_18 )\r\n{\r\nif ( ! type )\r\nreturn;\r\ntype -> V_19 ( V_18 ) ;\r\nF_16 ( type -> V_7 ) ;\r\n}\r\nint F_17 ( struct V_20 * V_21 )\r\n{\r\nif ( V_21 -> V_22 )\r\nF_18 ( V_21 -> V_22 ) ;\r\nreturn 0 ;\r\n}\r\nvoid F_19 ( struct V_21 * V_22 )\r\n{\r\nstruct V_23 * V_24 = F_20 ( V_22 ) ;\r\nunsigned int V_25 = V_24 -> V_26 ;\r\nbool V_27 = V_25 && ! V_24 -> V_28 ;\r\nV_22 = V_24 -> V_29 ;\r\nV_24 = F_20 ( V_22 ) ;\r\nF_21 ( V_22 ) ;\r\nV_24 -> V_26 -= V_25 ;\r\nif ( ! V_27 )\r\nV_27 = ! -- V_24 -> V_28 ;\r\nF_22 ( V_22 ) ;\r\nif ( V_27 )\r\nF_18 ( V_22 ) ;\r\n}\r\nstatic int F_23 ( struct V_20 * V_21 , struct V_30 * V_31 , int V_32 )\r\n{\r\nconst T_1 V_33 = V_34 ;\r\nstruct V_21 * V_22 = V_21 -> V_22 ;\r\nstruct V_23 * V_24 = F_20 ( V_22 ) ;\r\nstruct V_35 * V_36 = ( void * ) V_31 ;\r\nconst struct V_1 * type ;\r\nvoid * V_18 ;\r\nint V_8 ;\r\nif ( V_21 -> V_37 == V_38 )\r\nreturn - V_39 ;\r\nif ( V_32 != sizeof( * V_36 ) )\r\nreturn - V_39 ;\r\nV_36 -> V_40 [ sizeof( V_36 -> V_40 ) - 1 ] = 0 ;\r\nV_36 -> V_41 [ sizeof( V_36 -> V_41 ) - 1 ] = 0 ;\r\ntype = F_1 ( V_36 -> V_40 ) ;\r\nif ( F_24 ( type ) && F_25 ( type ) == - V_3 ) {\r\nF_26 ( L_1 , V_36 -> V_40 ) ;\r\ntype = F_1 ( V_36 -> V_40 ) ;\r\n}\r\nif ( F_24 ( type ) )\r\nreturn F_25 ( type ) ;\r\nV_18 = type -> V_42 ( V_36 -> V_41 ,\r\nV_36 -> V_43 & ~ V_33 ,\r\nV_36 -> V_44 & ~ V_33 ) ;\r\nif ( F_24 ( V_18 ) ) {\r\nF_16 ( type -> V_7 ) ;\r\nreturn F_25 ( V_18 ) ;\r\n}\r\nV_8 = - V_45 ;\r\nF_21 ( V_22 ) ;\r\nif ( V_24 -> V_28 | V_24 -> V_26 )\r\ngoto V_10;\r\nF_27 ( V_24 -> type , type ) ;\r\nF_27 ( V_24 -> V_18 , V_18 ) ;\r\nV_8 = 0 ;\r\nV_10:\r\nF_22 ( V_22 ) ;\r\nF_15 ( type , V_18 ) ;\r\nreturn V_8 ;\r\n}\r\nstatic int F_28 ( struct V_21 * V_22 , char T_2 * V_46 ,\r\nunsigned int V_47 )\r\n{\r\nstruct V_23 * V_24 = F_20 ( V_22 ) ;\r\nconst struct V_1 * type = V_24 -> type ;\r\nT_3 * V_48 ;\r\nint V_8 ;\r\nV_48 = F_29 ( V_22 , V_47 , V_11 ) ;\r\nif ( ! V_48 )\r\nreturn - V_12 ;\r\nV_8 = - V_49 ;\r\nif ( F_30 ( V_48 , V_46 , V_47 ) )\r\ngoto V_50;\r\nV_8 = type -> V_51 ( V_24 -> V_18 , V_48 , V_47 ) ;\r\nV_50:\r\nF_31 ( V_22 , V_48 , V_47 ) ;\r\nreturn V_8 ;\r\n}\r\nstatic int F_32 ( struct V_20 * V_21 , int V_52 , int V_53 ,\r\nchar T_2 * V_54 , unsigned int V_55 )\r\n{\r\nstruct V_21 * V_22 = V_21 -> V_22 ;\r\nstruct V_23 * V_24 = F_20 ( V_22 ) ;\r\nconst struct V_1 * type ;\r\nint V_8 = - V_45 ;\r\nF_21 ( V_22 ) ;\r\nif ( V_24 -> V_28 )\r\ngoto V_10;\r\ntype = V_24 -> type ;\r\nV_8 = - V_56 ;\r\nif ( V_52 != V_57 || ! type )\r\ngoto V_10;\r\nswitch ( V_53 ) {\r\ncase V_58 :\r\nif ( V_21 -> V_37 == V_38 )\r\ngoto V_10;\r\nif ( ! type -> V_51 )\r\ngoto V_10;\r\nV_8 = F_28 ( V_22 , V_54 , V_55 ) ;\r\nbreak;\r\ncase V_59 :\r\nif ( V_21 -> V_37 == V_38 )\r\ngoto V_10;\r\nif ( ! type -> V_60 )\r\ngoto V_10;\r\nV_8 = type -> V_60 ( V_24 -> V_18 , V_55 ) ;\r\n}\r\nV_10:\r\nF_22 ( V_22 ) ;\r\nreturn V_8 ;\r\n}\r\nint F_33 ( struct V_21 * V_22 , struct V_20 * V_61 )\r\n{\r\nstruct V_23 * V_24 = F_20 ( V_22 ) ;\r\nconst struct V_1 * type ;\r\nstruct V_21 * V_62 ;\r\nunsigned int V_25 ;\r\nint V_8 ;\r\nF_21 ( V_22 ) ;\r\ntype = V_24 -> type ;\r\nV_8 = - V_39 ;\r\nif ( ! type )\r\ngoto V_10;\r\nV_62 = F_34 ( F_35 ( V_22 ) , V_63 , V_11 , & V_64 , 0 ) ;\r\nV_8 = - V_12 ;\r\nif ( ! V_62 )\r\ngoto V_10;\r\nF_36 ( V_61 , V_62 ) ;\r\nF_37 ( V_62 , V_61 ) ;\r\nF_38 ( V_22 , V_62 ) ;\r\nV_8 = type -> V_65 ( V_24 -> V_18 , V_62 ) ;\r\nV_25 = V_8 == - V_66 ;\r\nif ( V_25 && type -> V_67 )\r\nV_8 = type -> V_67 ( V_24 -> V_18 , V_62 ) ;\r\nif ( V_8 )\r\ngoto V_10;\r\nV_62 -> V_68 = V_63 ;\r\nif ( V_25 || ! V_24 -> V_28 ++ )\r\nF_39 ( V_22 ) ;\r\nV_24 -> V_26 += V_25 ;\r\nF_20 ( V_62 ) -> V_29 = V_22 ;\r\nF_20 ( V_62 ) -> type = type ;\r\nF_20 ( V_62 ) -> V_26 = V_25 ;\r\nV_61 -> V_13 = type -> V_13 ;\r\nV_61 -> V_37 = V_38 ;\r\nif ( V_25 )\r\nV_61 -> V_13 = type -> V_15 ;\r\nV_8 = 0 ;\r\nV_10:\r\nF_22 ( V_22 ) ;\r\nreturn V_8 ;\r\n}\r\nstatic int F_40 ( struct V_20 * V_21 , struct V_20 * V_61 , int V_69 )\r\n{\r\nreturn F_33 ( V_21 -> V_22 , V_61 ) ;\r\n}\r\nstatic void F_41 ( struct V_21 * V_22 )\r\n{\r\nstruct V_23 * V_24 = F_20 ( V_22 ) ;\r\nF_15 ( V_24 -> type , V_24 -> V_18 ) ;\r\n}\r\nstatic int F_42 ( struct V_70 * V_70 , struct V_20 * V_21 , int V_71 ,\r\nint V_72 )\r\n{\r\nstruct V_21 * V_22 ;\r\nint V_8 ;\r\nif ( V_21 -> type != V_73 )\r\nreturn - V_74 ;\r\nif ( V_71 != 0 )\r\nreturn - V_75 ;\r\nV_8 = - V_12 ;\r\nV_22 = F_34 ( V_70 , V_63 , V_11 , & V_64 , V_72 ) ;\r\nif ( ! V_22 )\r\ngoto V_50;\r\nV_21 -> V_13 = & V_76 ;\r\nF_36 ( V_21 , V_22 ) ;\r\nV_22 -> V_68 = V_63 ;\r\nV_22 -> V_77 = F_41 ;\r\nreturn 0 ;\r\nV_50:\r\nreturn V_8 ;\r\n}\r\nint F_43 ( struct V_78 * V_79 , struct V_80 * V_81 , int V_82 )\r\n{\r\nT_4 V_83 ;\r\nT_5 V_84 ;\r\nint V_85 , V_86 ;\r\nV_84 = F_44 ( V_81 , V_79 -> V_87 , V_82 , V_88 , & V_83 ) ;\r\nif ( V_84 < 0 )\r\nreturn V_84 ;\r\nV_85 = ( V_83 + V_84 + V_89 - 1 ) >> V_90 ;\r\nif ( F_45 ( V_85 == 0 ) )\r\nreturn - V_39 ;\r\nF_46 ( V_79 -> V_91 , V_85 + 1 ) ;\r\nfor ( V_86 = 0 , V_82 = V_84 ; V_86 < V_85 ; V_86 ++ ) {\r\nint V_92 = F_47 ( int , V_82 , V_89 - V_83 ) ;\r\nF_48 ( V_79 -> V_91 + V_86 , V_79 -> V_87 [ V_86 ] , V_92 , V_83 ) ;\r\nV_83 = 0 ;\r\nV_82 -= V_92 ;\r\n}\r\nF_49 ( V_79 -> V_91 + V_85 - 1 ) ;\r\nV_79 -> V_85 = V_85 ;\r\nreturn V_84 ;\r\n}\r\nvoid F_50 ( struct V_78 * V_93 , struct V_78 * V_94 )\r\n{\r\nF_51 ( V_93 -> V_91 + V_93 -> V_85 - 1 ) ;\r\nF_52 ( V_93 -> V_91 , V_93 -> V_85 + 1 , V_94 -> V_91 ) ;\r\n}\r\nvoid F_53 ( struct V_78 * V_79 )\r\n{\r\nint V_86 ;\r\nfor ( V_86 = 0 ; V_86 < V_79 -> V_85 ; V_86 ++ )\r\nF_54 ( V_79 -> V_87 [ V_86 ] ) ;\r\n}\r\nint F_55 ( struct V_95 * V_96 , struct V_97 * V_98 )\r\n{\r\nstruct V_99 * V_100 ;\r\nF_56 (cmsg, msg) {\r\nif ( ! F_57 ( V_96 , V_100 ) )\r\nreturn - V_39 ;\r\nif ( V_100 -> V_101 != V_57 )\r\ncontinue;\r\nswitch ( V_100 -> V_102 ) {\r\ncase V_103 :\r\nif ( V_100 -> V_104 < F_58 ( sizeof( * V_98 -> V_105 ) ) )\r\nreturn - V_39 ;\r\nV_98 -> V_105 = ( void * ) F_59 ( V_100 ) ;\r\nif ( V_100 -> V_104 < F_58 ( V_98 -> V_105 -> V_106 +\r\nsizeof( * V_98 -> V_105 ) ) )\r\nreturn - V_39 ;\r\nbreak;\r\ncase V_107 :\r\nif ( V_100 -> V_104 < F_58 ( sizeof( T_1 ) ) )\r\nreturn - V_39 ;\r\nV_98 -> V_108 = * ( T_1 * ) F_59 ( V_100 ) ;\r\nbreak;\r\ncase V_109 :\r\nif ( V_100 -> V_104 < F_58 ( sizeof( T_1 ) ) )\r\nreturn - V_39 ;\r\nV_98 -> V_110 = * ( T_1 * ) F_59 ( V_100 ) ;\r\nbreak;\r\ndefault:\r\nreturn - V_39 ;\r\n}\r\n}\r\nreturn 0 ;\r\n}\r\nint F_60 ( int V_8 , struct V_111 * V_112 )\r\n{\r\nswitch ( V_8 ) {\r\ncase - V_113 :\r\ncase - V_45 :\r\nF_61 ( & V_112 -> V_112 ) ;\r\nF_62 ( & V_112 -> V_112 ) ;\r\nV_8 = V_112 -> V_8 ;\r\nbreak;\r\n} ;\r\nreturn V_8 ;\r\n}\r\nvoid F_63 ( struct V_114 * V_115 , int V_8 )\r\n{\r\nstruct V_111 * V_112 = V_115 -> V_116 ;\r\nif ( V_8 == - V_113 )\r\nreturn;\r\nV_112 -> V_8 = V_8 ;\r\nF_64 ( & V_112 -> V_112 ) ;\r\n}\r\nstatic int T_6 F_65 ( void )\r\n{\r\nint V_8 = F_66 ( & V_64 , 0 ) ;\r\nif ( V_8 )\r\ngoto V_50;\r\nV_8 = F_67 ( & V_117 ) ;\r\nif ( V_8 != 0 )\r\ngoto V_118;\r\nV_50:\r\nreturn V_8 ;\r\nV_118:\r\nF_68 ( & V_64 ) ;\r\ngoto V_50;\r\n}\r\nstatic void T_7 F_69 ( void )\r\n{\r\nF_70 ( V_63 ) ;\r\nF_68 ( & V_64 ) ;\r\n}
