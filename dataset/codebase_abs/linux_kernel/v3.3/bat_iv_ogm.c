void F_1 ( struct V_1 * V_1 )\r\n{\r\nstruct V_2 * V_2 ;\r\nV_1 -> V_3 = V_4 ;\r\nV_1 -> V_5 = F_2 ( V_1 -> V_3 , V_6 ) ;\r\nV_2 = (struct V_2 * ) V_1 -> V_5 ;\r\nV_2 -> V_7 = V_8 ;\r\nV_2 -> V_9 = V_10 ;\r\nV_2 -> V_11 = V_12 ;\r\nV_2 -> V_13 = 2 ;\r\nV_2 -> V_14 = V_15 ;\r\nV_2 -> V_16 = 0 ;\r\nV_2 -> V_17 = 0 ;\r\n}\r\nvoid F_3 ( struct V_1 * V_1 )\r\n{\r\nstruct V_2 * V_2 ;\r\nV_2 = (struct V_2 * ) V_1 -> V_5 ;\r\nV_2 -> V_11 = V_18 ;\r\nV_2 -> V_13 = V_19 ;\r\n}\r\nvoid F_4 ( struct V_1 * V_1 )\r\n{\r\nstruct V_2 * V_2 ;\r\nV_2 = (struct V_2 * ) V_1 -> V_5 ;\r\nmemcpy ( V_2 -> V_20 ,\r\nV_1 -> V_21 -> V_22 , V_23 ) ;\r\nmemcpy ( V_2 -> V_24 ,\r\nV_1 -> V_21 -> V_22 , V_23 ) ;\r\n}\r\nstatic unsigned long F_5 ( const struct V_25 * V_25 )\r\n{\r\nreturn V_26 + F_6 (\r\nF_7 ( & V_25 -> V_27 ) -\r\nV_28 + ( F_8 () % 2 * V_28 ) ) ;\r\n}\r\nstatic unsigned long F_9 ( void )\r\n{\r\nreturn V_26 + F_6 ( F_8 () % ( V_28 / 2 ) ) ;\r\n}\r\nstatic T_1 F_10 ( T_1 V_14 , const struct V_25 * V_25 )\r\n{\r\nint F_10 = F_7 ( & V_25 -> F_10 ) ;\r\nreturn ( V_14 * ( V_15 - F_10 ) ) / ( V_15 ) ;\r\n}\r\nstatic int F_11 ( int V_29 , int V_3 ,\r\nint V_16 )\r\n{\r\nint V_30 = V_29 + V_4 + F_12 ( V_16 ) ;\r\nreturn ( V_30 <= V_3 ) &&\r\n( V_30 <= V_31 ) ;\r\n}\r\nstatic void F_13 ( struct V_32 * V_32 ,\r\nstruct V_1 * V_1 )\r\n{\r\nstruct V_25 * V_25 = F_14 ( V_1 -> V_33 ) ;\r\nchar * V_34 ;\r\nT_1 V_35 ;\r\nT_2 V_29 ;\r\nstruct V_2 * V_2 ;\r\nstruct V_36 * V_37 ;\r\nif ( V_1 -> V_38 != V_39 )\r\nreturn;\r\nV_35 = 0 ;\r\nV_29 = 0 ;\r\nV_2 = (struct V_2 * ) V_32 -> V_37 -> V_40 ;\r\nwhile ( F_11 ( V_29 , V_32 -> V_3 ,\r\nV_2 -> V_16 ) ) {\r\nif ( ( V_32 -> V_41 & ( 1 << V_35 ) ) &&\r\n( V_32 -> V_42 == V_1 ) )\r\nV_2 -> V_11 |= V_43 ;\r\nelse\r\nV_2 -> V_11 &= ~ V_43 ;\r\nV_34 = ( V_35 > 0 ? L_1 : ( V_32 -> V_44 ?\r\nL_2 :\r\nL_1 ) ) ;\r\nF_15 ( V_45 , V_25 ,\r\nL_3\r\nL_4 ,\r\nV_34 , ( V_35 > 0 ? L_5 : L_6 ) ,\r\nV_2 -> V_20 ,\r\nF_16 ( V_2 -> V_46 ) ,\r\nV_2 -> V_14 , V_2 -> V_13 ,\r\n( V_2 -> V_11 & V_43 ?\r\nL_7 : L_8 ) ,\r\nV_2 -> V_17 , V_1 -> V_21 -> V_47 ,\r\nV_1 -> V_21 -> V_22 ) ;\r\nV_29 += V_4 +\r\nF_12 ( V_2 -> V_16 ) ;\r\nV_35 ++ ;\r\nV_2 = (struct V_2 * )\r\n( V_32 -> V_37 -> V_40 + V_29 ) ;\r\n}\r\nV_37 = F_17 ( V_32 -> V_37 , V_6 ) ;\r\nif ( V_37 )\r\nF_18 ( V_37 , V_1 , V_48 ) ;\r\n}\r\nvoid F_19 ( struct V_32 * V_32 )\r\n{\r\nstruct V_1 * V_1 ;\r\nstruct V_49 * V_33 ;\r\nstruct V_25 * V_25 ;\r\nstruct V_1 * V_50 = NULL ;\r\nstruct V_2 * V_2 ;\r\nunsigned char V_51 ;\r\nV_2 = (struct V_2 * )\r\n( V_32 -> V_37 -> V_40 ) ;\r\nV_51 = ( V_2 -> V_11 & V_43 ? 1 : 0 ) ;\r\nif ( ! V_32 -> V_42 ) {\r\nF_20 ( L_9\r\nL_10 ) ;\r\ngoto V_52;\r\n}\r\nV_33 = V_32 -> V_42 -> V_33 ;\r\nV_25 = F_14 ( V_33 ) ;\r\nif ( V_32 -> V_42 -> V_38 != V_39 )\r\ngoto V_52;\r\nV_50 = F_21 ( V_25 ) ;\r\nif ( ! V_50 )\r\ngoto V_52;\r\nif ( ( V_51 && ( V_2 -> V_13 == 1 ) ) ||\r\n( V_32 -> V_44 && ( V_32 -> V_42 != V_50 ) ) ) {\r\nF_15 ( V_45 , V_25 ,\r\nL_11\r\nL_12 ,\r\n( V_32 -> V_44 ? L_2 : L_1 ) ,\r\nV_2 -> V_20 ,\r\nF_16 ( V_2 -> V_46 ) ,\r\nV_2 -> V_13 ,\r\nV_32 -> V_42 -> V_21 -> V_47 ,\r\nV_32 -> V_42 -> V_21 -> V_22 ) ;\r\nF_18 ( V_32 -> V_37 , V_32 -> V_42 ,\r\nV_48 ) ;\r\nV_32 -> V_37 = NULL ;\r\ngoto V_52;\r\n}\r\nF_22 () ;\r\nF_23 (hard_iface, &hardif_list, list) {\r\nif ( V_1 -> V_33 != V_33 )\r\ncontinue;\r\nF_13 ( V_32 , V_1 ) ;\r\n}\r\nF_24 () ;\r\nV_52:\r\nif ( V_50 )\r\nF_25 ( V_50 ) ;\r\n}\r\nstatic bool F_26 ( const struct V_2\r\n* V_53 ,\r\nstruct V_25 * V_25 ,\r\nint V_3 , unsigned long V_54 ,\r\nbool V_51 ,\r\nconst struct V_1 * V_42 ,\r\nconst struct V_32 * V_32 )\r\n{\r\nstruct V_2 * V_2 ;\r\nint V_55 = V_32 -> V_3 + V_3 ;\r\nstruct V_1 * V_50 = NULL ;\r\nbool V_56 = false ;\r\nV_2 = (struct V_2 * ) V_32 -> V_37 -> V_40 ;\r\nif ( F_27 ( V_54 , V_32 -> V_54 ) &&\r\nF_28 ( V_54 + F_6 ( V_57 ) ,\r\nV_32 -> V_54 ) &&\r\n( V_55 <= V_31 ) ) {\r\nV_50 = F_21 ( V_25 ) ;\r\nif ( ! V_50 )\r\ngoto V_52;\r\nif ( ( ! V_51 ) &&\r\n( ! ( V_2 -> V_11 & V_43 ) ) &&\r\n( V_2 -> V_13 != 1 ) &&\r\n( ( ! V_32 -> V_44 ) ||\r\n( V_32 -> V_42 == V_50 ) ) ) {\r\nV_56 = true ;\r\ngoto V_52;\r\n}\r\nif ( ( V_51 ) &&\r\n( V_53 -> V_13 == 1 ) &&\r\n( V_32 -> V_42 == V_42 ) &&\r\n( V_2 -> V_11 & V_43 ||\r\n( V_32 -> V_44 &&\r\nV_32 -> V_42 != V_50 ) ) ) {\r\nV_56 = true ;\r\ngoto V_52;\r\n}\r\n}\r\nV_52:\r\nif ( V_50 )\r\nF_25 ( V_50 ) ;\r\nreturn V_56 ;\r\n}\r\nstatic void F_29 ( const unsigned char * V_5 ,\r\nint V_3 , unsigned long V_54 ,\r\nbool V_58 ,\r\nstruct V_1 * V_42 ,\r\nint V_59 )\r\n{\r\nstruct V_25 * V_25 = F_14 ( V_42 -> V_33 ) ;\r\nstruct V_32 * V_60 ;\r\nunsigned char * V_61 ;\r\nif ( ! F_30 ( & V_42 -> V_62 ) )\r\nreturn;\r\nif ( ! V_59 ) {\r\nif ( ! F_31 ( & V_25 -> V_63 ) ) {\r\nF_15 ( V_45 , V_25 ,\r\nL_13 ) ;\r\ngoto V_52;\r\n}\r\n}\r\nV_60 = F_2 ( sizeof( * V_60 ) , V_6 ) ;\r\nif ( ! V_60 ) {\r\nif ( ! V_59 )\r\nF_32 ( & V_25 -> V_63 ) ;\r\ngoto V_52;\r\n}\r\nif ( ( F_7 ( & V_25 -> V_64 ) ) &&\r\n( V_3 < V_31 ) )\r\nV_60 -> V_37 = F_33 ( V_31 +\r\nsizeof( struct V_65 ) ) ;\r\nelse\r\nV_60 -> V_37 = F_33 ( V_3 +\r\nsizeof( struct V_65 ) ) ;\r\nif ( ! V_60 -> V_37 ) {\r\nif ( ! V_59 )\r\nF_32 ( & V_25 -> V_63 ) ;\r\nF_34 ( V_60 ) ;\r\ngoto V_52;\r\n}\r\nF_35 ( V_60 -> V_37 , sizeof( struct V_65 ) ) ;\r\nF_36 ( & V_60 -> V_66 ) ;\r\nV_61 = F_37 ( V_60 -> V_37 , V_3 ) ;\r\nV_60 -> V_3 = V_3 ;\r\nmemcpy ( V_61 , V_5 , V_3 ) ;\r\nV_60 -> V_44 = V_59 ;\r\nV_60 -> V_42 = V_42 ;\r\nV_60 -> V_67 = 0 ;\r\nV_60 -> V_41 = V_12 ;\r\nV_60 -> V_54 = V_54 ;\r\nif ( V_58 )\r\nV_60 -> V_41 |= 1 ;\r\nF_38 ( & V_25 -> V_68 ) ;\r\nF_39 ( & V_60 -> V_66 , & V_25 -> V_69 ) ;\r\nF_40 ( & V_25 -> V_68 ) ;\r\nF_41 ( & V_60 -> V_70 ,\r\nV_71 ) ;\r\nF_42 ( V_72 ,\r\n& V_60 -> V_70 ,\r\nV_54 - V_26 ) ;\r\nreturn;\r\nV_52:\r\nF_25 ( V_42 ) ;\r\n}\r\nstatic void F_43 ( struct V_32 * V_60 ,\r\nconst unsigned char * V_5 ,\r\nint V_3 , bool V_58 )\r\n{\r\nunsigned char * V_61 ;\r\nV_61 = F_37 ( V_60 -> V_37 , V_3 ) ;\r\nmemcpy ( V_61 , V_5 , V_3 ) ;\r\nV_60 -> V_3 += V_3 ;\r\nV_60 -> V_67 ++ ;\r\nif ( V_58 )\r\nV_60 -> V_41 |=\r\n( 1 << V_60 -> V_67 ) ;\r\n}\r\nstatic void F_44 ( struct V_25 * V_25 ,\r\nunsigned char * V_5 ,\r\nint V_3 , struct V_1 * V_42 ,\r\nint V_59 , unsigned long V_54 )\r\n{\r\nstruct V_32 * V_60 = NULL , * V_73 = NULL ;\r\nstruct V_74 * V_75 ;\r\nstruct V_2 * V_2 ;\r\nbool V_58 ;\r\nV_2 = (struct V_2 * ) V_5 ;\r\nV_58 = V_2 -> V_11 & V_43 ? 1 : 0 ;\r\nF_38 ( & V_25 -> V_68 ) ;\r\nif ( ( F_7 ( & V_25 -> V_64 ) ) && ( ! V_59 ) ) {\r\nF_45 (forw_packet_pos, tmp_node,\r\n&bat_priv->forw_bat_list, list) {\r\nif ( F_26 ( V_2 ,\r\nV_25 , V_3 ,\r\nV_54 , V_58 ,\r\nV_42 ,\r\nV_73 ) ) {\r\nV_60 = V_73 ;\r\nbreak;\r\n}\r\n}\r\n}\r\nif ( ! V_60 ) {\r\nF_40 ( & V_25 -> V_68 ) ;\r\nif ( ( ! V_59 ) &&\r\n( F_7 ( & V_25 -> V_64 ) ) )\r\nV_54 += F_6 ( V_57 ) ;\r\nF_29 ( V_5 , V_3 ,\r\nV_54 , V_58 ,\r\nV_42 , V_59 ) ;\r\n} else {\r\nF_43 ( V_60 , V_5 , V_3 ,\r\nV_58 ) ;\r\nF_40 ( & V_25 -> V_68 ) ;\r\n}\r\n}\r\nstatic void F_46 ( struct V_76 * V_76 ,\r\nconst struct V_65 * V_65 ,\r\nstruct V_2 * V_2 ,\r\nint V_51 , struct V_1 * V_42 )\r\n{\r\nstruct V_25 * V_25 = F_14 ( V_42 -> V_33 ) ;\r\nstruct V_77 * V_78 ;\r\nT_1 V_79 , V_80 , V_81 = 0 ;\r\nT_1 V_16 ;\r\nif ( V_2 -> V_13 <= 1 ) {\r\nF_15 ( V_45 , V_25 , L_14 ) ;\r\nreturn;\r\n}\r\nV_78 = F_47 ( V_76 ) ;\r\nV_79 = V_2 -> V_14 ;\r\nV_80 = V_2 -> V_13 ;\r\nV_16 = V_2 -> V_16 ;\r\nV_2 -> V_13 -- ;\r\nmemcpy ( V_2 -> V_24 , V_65 -> V_82 , V_23 ) ;\r\nif ( V_78 && V_78 -> V_81 != 0 ) {\r\nif ( ! F_48 ( V_78 -> V_83 , V_65 -> V_82 ) ) {\r\nV_2 -> V_14 = V_78 -> V_81 ;\r\nif ( V_78 -> V_84 )\r\nV_2 -> V_13 = V_78 -> V_84 - 1 ;\r\n}\r\nV_81 = V_78 -> V_81 ;\r\n}\r\nif ( V_78 )\r\nF_49 ( V_78 ) ;\r\nV_2 -> V_14 = F_10 ( V_2 -> V_14 , V_25 ) ;\r\nF_15 ( V_45 , V_25 ,\r\nL_15\r\nL_16 ,\r\nV_79 , V_81 , V_2 -> V_14 , V_80 - 1 ,\r\nV_2 -> V_13 ) ;\r\nV_2 -> V_46 = F_50 ( V_2 -> V_46 ) ;\r\nV_2 -> V_85 = F_51 ( V_2 -> V_85 ) ;\r\nV_2 -> V_11 &= ~ V_18 ;\r\nif ( V_51 )\r\nV_2 -> V_11 |= V_43 ;\r\nelse\r\nV_2 -> V_11 &= ~ V_43 ;\r\nF_44 ( V_25 , ( unsigned char * ) V_2 ,\r\nV_4 + F_12 ( V_16 ) ,\r\nV_42 , 0 , F_9 () ) ;\r\n}\r\nvoid F_52 ( struct V_1 * V_1 , int V_16 )\r\n{\r\nstruct V_25 * V_25 = F_14 ( V_1 -> V_33 ) ;\r\nstruct V_2 * V_2 ;\r\nstruct V_1 * V_50 ;\r\nint V_86 ;\r\nV_86 = F_7 ( & V_25 -> V_87 ) ;\r\nV_50 = F_21 ( V_25 ) ;\r\nV_2 = (struct V_2 * ) V_1 -> V_5 ;\r\nV_2 -> V_46 =\r\nF_50 ( ( V_88 ) F_7 ( & V_1 -> V_46 ) ) ;\r\nV_2 -> V_17 = F_7 ( & V_25 -> V_17 ) ;\r\nV_2 -> V_85 = F_51 ( ( V_89 )\r\nF_7 ( & V_25 -> V_85 ) ) ;\r\nif ( V_16 >= 0 )\r\nV_2 -> V_16 = V_16 ;\r\nif ( V_86 == V_90 )\r\nV_2 -> V_11 |= V_91 ;\r\nelse\r\nV_2 -> V_11 &= ~ V_91 ;\r\nif ( ( V_1 == V_50 ) &&\r\n( F_7 ( & V_25 -> V_92 ) == V_93 ) )\r\nV_2 -> V_94 =\r\n( T_1 ) F_7 ( & V_25 -> V_95 ) ;\r\nelse\r\nV_2 -> V_94 = V_12 ;\r\nF_32 ( & V_1 -> V_46 ) ;\r\nF_53 ( V_1 ) ;\r\nF_44 ( V_25 , V_1 -> V_5 ,\r\nV_1 -> V_3 , V_1 , 1 ,\r\nF_5 ( V_25 ) ) ;\r\nif ( V_50 )\r\nF_25 ( V_50 ) ;\r\n}\r\nstatic void F_54 ( struct V_25 * V_25 ,\r\nstruct V_76 * V_76 ,\r\nconst struct V_65 * V_65 ,\r\nconst struct V_2\r\n* V_2 ,\r\nstruct V_1 * V_42 ,\r\nconst unsigned char * V_96 , int V_97 )\r\n{\r\nstruct V_77 * V_77 = NULL , * V_98 = NULL ;\r\nstruct V_77 * V_78 = NULL ;\r\nstruct V_76 * V_99 ;\r\nstruct V_74 * V_100 ;\r\nT_1 V_101 , V_102 ;\r\nF_15 ( V_45 , V_25 , L_17\r\nL_18 ) ;\r\nF_22 () ;\r\nF_55 (tmp_neigh_node, node,\r\n&orig_node->neigh_list, list) {\r\nif ( F_48 ( V_98 -> V_83 , V_65 -> V_82 ) &&\r\n( V_98 -> V_42 == V_42 ) &&\r\nF_30 ( & V_98 -> V_62 ) ) {\r\nif ( V_77 )\r\nF_49 ( V_77 ) ;\r\nV_77 = V_98 ;\r\ncontinue;\r\n}\r\nif ( V_97 )\r\ncontinue;\r\nF_38 ( & V_98 -> V_103 ) ;\r\nF_56 ( V_98 -> V_104 ,\r\n& V_98 -> V_105 , 0 ) ;\r\nV_98 -> V_81 =\r\nF_57 ( V_98 -> V_104 ) ;\r\nF_40 ( & V_98 -> V_103 ) ;\r\n}\r\nif ( ! V_77 ) {\r\nstruct V_76 * V_106 ;\r\nV_106 = F_58 ( V_25 , V_65 -> V_82 ) ;\r\nif ( ! V_106 )\r\ngoto V_107;\r\nV_77 = F_59 ( V_76 , V_106 ,\r\nV_65 -> V_82 , V_42 ) ;\r\nF_60 ( V_106 ) ;\r\nif ( ! V_77 )\r\ngoto V_107;\r\n} else\r\nF_15 ( V_45 , V_25 ,\r\nL_19 ) ;\r\nF_24 () ;\r\nV_76 -> V_11 = V_2 -> V_11 ;\r\nV_77 -> V_108 = V_26 ;\r\nF_38 ( & V_77 -> V_103 ) ;\r\nF_56 ( V_77 -> V_104 ,\r\n& V_77 -> V_105 ,\r\nV_2 -> V_14 ) ;\r\nV_77 -> V_81 = F_57 ( V_77 -> V_104 ) ;\r\nF_40 ( & V_77 -> V_103 ) ;\r\nif ( ! V_97 ) {\r\nV_76 -> V_84 = V_2 -> V_13 ;\r\nV_77 -> V_84 = V_2 -> V_13 ;\r\n}\r\nF_61 ( V_76 , V_77 ) ;\r\nV_78 = F_47 ( V_76 ) ;\r\nif ( V_78 == V_77 )\r\ngoto V_109;\r\nif ( V_78 && ( V_78 -> V_81 > V_77 -> V_81 ) )\r\ngoto V_109;\r\nif ( V_78 && ( V_77 -> V_81 == V_78 -> V_81 ) ) {\r\nV_99 = V_78 -> V_76 ;\r\nF_38 ( & V_99 -> V_110 ) ;\r\nV_101 =\r\nV_99 -> V_111 [ V_42 -> V_112 ] ;\r\nF_40 ( & V_99 -> V_110 ) ;\r\nV_99 = V_77 -> V_76 ;\r\nF_38 ( & V_99 -> V_110 ) ;\r\nV_102 =\r\nV_99 -> V_111 [ V_42 -> V_112 ] ;\r\nF_40 ( & V_99 -> V_110 ) ;\r\nif ( V_101 >= V_102 )\r\ngoto V_109;\r\n}\r\nF_62 ( V_25 , V_76 , V_77 ) ;\r\nV_109:\r\nif ( ( ( V_2 -> V_20 != V_65 -> V_82 ) &&\r\n( V_2 -> V_13 > 2 ) ) ||\r\n( V_2 -> V_11 & V_18 ) )\r\nF_63 ( V_25 , V_76 , V_96 ,\r\nV_2 -> V_16 ,\r\nV_2 -> V_17 ,\r\nV_2 -> V_85 ) ;\r\nif ( V_76 -> V_94 != V_2 -> V_94 )\r\nF_64 ( V_25 , V_76 ,\r\nV_2 -> V_94 ) ;\r\nV_76 -> V_94 = V_2 -> V_94 ;\r\nif ( ( V_76 -> V_94 ) &&\r\n( F_7 ( & V_25 -> V_92 ) == V_113 ) &&\r\n( F_7 ( & V_25 -> V_114 ) > 2 ) )\r\nF_65 ( V_25 , V_76 ) ;\r\ngoto V_52;\r\nV_107:\r\nF_24 () ;\r\nV_52:\r\nif ( V_77 )\r\nF_49 ( V_77 ) ;\r\nif ( V_78 )\r\nF_49 ( V_78 ) ;\r\n}\r\nstatic int F_66 ( struct V_76 * V_76 ,\r\nstruct V_76 * V_115 ,\r\nstruct V_2 * V_2 ,\r\nstruct V_1 * V_42 )\r\n{\r\nstruct V_25 * V_25 = F_14 ( V_42 -> V_33 ) ;\r\nstruct V_77 * V_77 = NULL , * V_98 ;\r\nstruct V_74 * V_100 ;\r\nT_1 V_116 ;\r\nT_1 V_117 , V_118 , V_119 ;\r\nint V_120 , V_121 = 0 ;\r\nF_22 () ;\r\nF_55 (tmp_neigh_node, node,\r\n&orig_neigh_node->neigh_list, list) {\r\nif ( ! F_48 ( V_98 -> V_83 , V_115 -> V_20 ) )\r\ncontinue;\r\nif ( V_98 -> V_42 != V_42 )\r\ncontinue;\r\nif ( ! F_30 ( & V_98 -> V_62 ) )\r\ncontinue;\r\nV_77 = V_98 ;\r\nbreak;\r\n}\r\nF_24 () ;\r\nif ( ! V_77 )\r\nV_77 = F_59 ( V_115 ,\r\nV_115 ,\r\nV_115 -> V_20 ,\r\nV_42 ) ;\r\nif ( ! V_77 )\r\ngoto V_52;\r\nif ( V_76 == V_115 )\r\nV_77 -> V_108 = V_26 ;\r\nV_76 -> V_108 = V_26 ;\r\nF_38 ( & V_76 -> V_110 ) ;\r\nV_117 = V_115 -> V_111 [ V_42 -> V_112 ] ;\r\nV_118 = V_77 -> V_122 ;\r\nF_40 ( & V_76 -> V_110 ) ;\r\nV_116 = ( V_117 > V_118 ?\r\nV_118 : V_117 ) ;\r\nif ( ( V_116 < V_123 ) ||\r\n( V_118 < V_124 ) )\r\nV_119 = 0 ;\r\nelse\r\nV_119 = ( V_15 * V_116 ) / V_118 ;\r\nV_120 = V_15 - ( V_15 *\r\n( V_125 - V_118 ) *\r\n( V_125 - V_118 ) *\r\n( V_125 - V_118 ) ) /\r\n( V_125 *\r\nV_125 *\r\nV_125 ) ;\r\nV_2 -> V_14 = ( ( V_2 -> V_14 * V_119\r\n* V_120 ) /\r\n( V_15 * V_15 ) ) ;\r\nF_15 ( V_45 , V_25 ,\r\nL_20\r\nL_21\r\nL_22\r\nL_23 ,\r\nV_76 -> V_20 , V_115 -> V_20 , V_116 ,\r\nV_118 , V_119 , V_120 , V_2 -> V_14 ) ;\r\nif ( V_2 -> V_14 >= V_126 )\r\nV_121 = 1 ;\r\nV_52:\r\nif ( V_77 )\r\nF_49 ( V_77 ) ;\r\nreturn V_121 ;\r\n}\r\nstatic int F_67 ( const struct V_65 * V_65 ,\r\nconst struct V_2\r\n* V_2 ,\r\nconst struct V_1 * V_42 )\r\n{\r\nstruct V_25 * V_25 = F_14 ( V_42 -> V_33 ) ;\r\nstruct V_76 * V_76 ;\r\nstruct V_77 * V_98 ;\r\nstruct V_74 * V_100 ;\r\nint V_97 = 0 ;\r\nT_3 V_127 ;\r\nint V_128 = 0 ;\r\nint V_129 , V_121 = - 1 ;\r\nV_76 = F_58 ( V_25 , V_2 -> V_20 ) ;\r\nif ( ! V_76 )\r\nreturn 0 ;\r\nF_38 ( & V_76 -> V_110 ) ;\r\nV_127 = V_2 -> V_46 - V_76 -> V_130 ;\r\nif ( F_68 ( V_25 , V_127 ,\r\n& V_76 -> V_131 ) )\r\ngoto V_52;\r\nF_22 () ;\r\nF_55 (tmp_neigh_node, node,\r\n&orig_node->neigh_list, list) {\r\nV_97 |= F_69 ( V_98 -> V_132 ,\r\nV_76 -> V_130 ,\r\nV_2 -> V_46 ) ;\r\nif ( F_48 ( V_98 -> V_83 , V_65 -> V_82 ) &&\r\n( V_98 -> V_42 == V_42 ) )\r\nV_129 = 1 ;\r\nelse\r\nV_129 = 0 ;\r\nV_128 |= F_70 ( V_25 ,\r\nV_98 -> V_132 ,\r\nV_127 , V_129 ) ;\r\nV_98 -> V_122 =\r\nF_71 ( V_98 -> V_132 ) ;\r\n}\r\nF_24 () ;\r\nif ( V_128 ) {\r\nF_15 ( V_45 , V_25 ,\r\nL_24 ,\r\nV_76 -> V_130 , V_2 -> V_46 ) ;\r\nV_76 -> V_130 = V_2 -> V_46 ;\r\n}\r\nV_121 = V_97 ;\r\nV_52:\r\nF_40 ( & V_76 -> V_110 ) ;\r\nF_60 ( V_76 ) ;\r\nreturn V_121 ;\r\n}\r\nstatic void F_72 ( const struct V_65 * V_65 ,\r\nstruct V_2 * V_2 ,\r\nconst unsigned char * V_96 ,\r\nstruct V_1 * V_42 )\r\n{\r\nstruct V_25 * V_25 = F_14 ( V_42 -> V_33 ) ;\r\nstruct V_1 * V_1 ;\r\nstruct V_76 * V_115 , * V_76 ;\r\nstruct V_77 * V_78 = NULL , * V_133 = NULL ;\r\nstruct V_77 * V_134 = NULL ;\r\nint V_135 ;\r\nint V_136 = 0 , V_137 = 0 , V_138 = 0 ;\r\nint V_139 = 0 , V_140 , V_141 ;\r\nint V_97 ;\r\nV_88 V_142 ;\r\nif ( V_2 -> V_7 != V_8 )\r\nreturn;\r\nV_142 = F_7 ( & V_42 -> V_46 ) ;\r\nV_135 = ( V_2 -> V_11 & V_43 ? 1 : 0 ) ;\r\nV_141 = ( F_48 ( V_65 -> V_82 ,\r\nV_2 -> V_20 ) ? 1 : 0 ) ;\r\nF_15 ( V_45 , V_25 ,\r\nL_25\r\nL_26\r\nL_27 ,\r\nV_65 -> V_82 , V_42 -> V_21 -> V_47 ,\r\nV_42 -> V_21 -> V_22 , V_2 -> V_20 ,\r\nV_2 -> V_24 , V_2 -> V_46 ,\r\nV_2 -> V_17 , V_2 -> V_85 ,\r\nV_2 -> V_16 , V_2 -> V_14 ,\r\nV_2 -> V_13 , V_2 -> V_9 ,\r\nV_135 ) ;\r\nF_22 () ;\r\nF_23 (hard_iface, &hardif_list, list) {\r\nif ( V_1 -> V_38 != V_39 )\r\ncontinue;\r\nif ( V_1 -> V_33 != V_42 -> V_33 )\r\ncontinue;\r\nif ( F_48 ( V_65 -> V_82 ,\r\nV_1 -> V_21 -> V_22 ) )\r\nV_136 = 1 ;\r\nif ( F_48 ( V_2 -> V_20 ,\r\nV_1 -> V_21 -> V_22 ) )\r\nV_137 = 1 ;\r\nif ( F_48 ( V_2 -> V_24 ,\r\nV_1 -> V_21 -> V_22 ) )\r\nV_138 = 1 ;\r\nif ( F_73 ( V_65 -> V_82 ) )\r\nV_139 = 1 ;\r\n}\r\nF_24 () ;\r\nif ( V_2 -> V_9 != V_10 ) {\r\nF_15 ( V_45 , V_25 ,\r\nL_28 ,\r\nV_2 -> V_9 ) ;\r\nreturn;\r\n}\r\nif ( V_136 ) {\r\nF_15 ( V_45 , V_25 ,\r\nL_29\r\nL_30 ,\r\nV_65 -> V_82 ) ;\r\nreturn;\r\n}\r\nif ( V_139 ) {\r\nF_15 ( V_45 , V_25 , L_31\r\nL_32\r\nL_30 , V_65 -> V_82 ) ;\r\nreturn;\r\n}\r\nif ( V_137 ) {\r\nunsigned long * V_143 ;\r\nint V_144 ;\r\nV_115 = F_58 ( V_25 , V_65 -> V_82 ) ;\r\nif ( ! V_115 )\r\nreturn;\r\nif ( V_135 &&\r\nF_48 ( V_42 -> V_21 -> V_22 ,\r\nV_2 -> V_20 ) ) {\r\nV_144 = V_42 -> V_112 * V_145 ;\r\nF_38 ( & V_115 -> V_110 ) ;\r\nV_143 = & ( V_115 -> V_146 [ V_144 ] ) ;\r\nF_74 ( V_143 ,\r\nV_142 -\r\nV_2 -> V_46 - 2 ) ;\r\nV_115 -> V_111 [ V_42 -> V_112 ] =\r\nF_71 ( V_143 ) ;\r\nF_40 ( & V_115 -> V_110 ) ;\r\n}\r\nF_15 ( V_45 , V_25 , L_31\r\nL_33 ) ;\r\nF_60 ( V_115 ) ;\r\nreturn;\r\n}\r\nif ( V_138 ) {\r\nF_15 ( V_45 , V_25 ,\r\nL_34\r\nL_35 , V_65 -> V_82 ) ;\r\nreturn;\r\n}\r\nV_76 = F_58 ( V_25 , V_2 -> V_20 ) ;\r\nif ( ! V_76 )\r\nreturn;\r\nV_97 = F_67 ( V_65 , V_2 ,\r\nV_42 ) ;\r\nif ( V_97 == - 1 ) {\r\nF_15 ( V_45 , V_25 ,\r\nL_36\r\nL_37 , V_65 -> V_82 ) ;\r\ngoto V_52;\r\n}\r\nif ( V_2 -> V_14 == 0 ) {\r\nF_15 ( V_45 , V_25 ,\r\nL_38 ) ;\r\ngoto V_52;\r\n}\r\nV_78 = F_47 ( V_76 ) ;\r\nif ( V_78 )\r\nV_133 = F_47 ( V_78 -> V_76 ) ;\r\nif ( V_78 && V_133 &&\r\n( F_48 ( V_78 -> V_83 , V_2 -> V_24 ) ) &&\r\n! ( F_48 ( V_2 -> V_20 ,\r\nV_2 -> V_24 ) ) &&\r\n( F_48 ( V_78 -> V_83 , V_133 -> V_83 ) ) ) {\r\nF_15 ( V_45 , V_25 ,\r\nL_39\r\nL_40 , V_65 -> V_82 ) ;\r\ngoto V_52;\r\n}\r\nV_115 = ( V_141 ?\r\nV_76 :\r\nF_58 ( V_25 , V_65 -> V_82 ) ) ;\r\nif ( ! V_115 )\r\ngoto V_52;\r\nV_134 = F_47 ( V_115 ) ;\r\nif ( ! V_141 && ( ! V_134 ) ) {\r\nF_15 ( V_45 , V_25 ,\r\nL_41 ) ;\r\ngoto V_147;\r\n}\r\nV_140 = F_66 ( V_76 , V_115 ,\r\nV_2 , V_42 ) ;\r\nF_75 ( V_76 , V_115 , V_2 ) ;\r\nif ( V_140 &&\r\n( ! V_97 ||\r\n( ( V_76 -> V_130 == V_2 -> V_46 ) &&\r\n( V_76 -> V_84 - 3 <= V_2 -> V_13 ) ) ) )\r\nF_54 ( V_25 , V_76 , V_65 ,\r\nV_2 , V_42 ,\r\nV_96 , V_97 ) ;\r\nif ( V_141 ) {\r\nF_46 ( V_76 , V_65 , V_2 ,\r\n1 , V_42 ) ;\r\nF_15 ( V_45 , V_25 , L_42\r\nL_43 ) ;\r\ngoto V_147;\r\n}\r\nif ( ! V_140 ) {\r\nF_15 ( V_45 , V_25 ,\r\nL_44 ) ;\r\ngoto V_147;\r\n}\r\nif ( V_97 ) {\r\nF_15 ( V_45 , V_25 ,\r\nL_45 ) ;\r\ngoto V_147;\r\n}\r\nF_15 ( V_45 , V_25 ,\r\nL_46 ) ;\r\nF_46 ( V_76 , V_65 , V_2 , 0 , V_42 ) ;\r\nV_147:\r\nif ( ( V_115 ) && ( ! V_141 ) )\r\nF_60 ( V_115 ) ;\r\nV_52:\r\nif ( V_78 )\r\nF_49 ( V_78 ) ;\r\nif ( V_133 )\r\nF_49 ( V_133 ) ;\r\nif ( V_134 )\r\nF_49 ( V_134 ) ;\r\nF_60 ( V_76 ) ;\r\n}\r\nvoid F_76 ( const struct V_65 * V_65 , unsigned char * V_5 ,\r\nint V_3 , struct V_1 * V_42 )\r\n{\r\nstruct V_2 * V_2 ;\r\nint V_29 = 0 ;\r\nunsigned char * V_96 ;\r\nV_2 = (struct V_2 * ) V_5 ;\r\ndo {\r\nV_2 -> V_46 = F_16 ( V_2 -> V_46 ) ;\r\nV_2 -> V_85 = F_77 ( V_2 -> V_85 ) ;\r\nV_96 = V_5 + V_29 + V_4 ;\r\nF_72 ( V_65 , V_2 ,\r\nV_96 , V_42 ) ;\r\nV_29 += V_4 +\r\nF_12 ( V_2 -> V_16 ) ;\r\nV_2 = (struct V_2 * )\r\n( V_5 + V_29 ) ;\r\n} while ( F_11 ( V_29 , V_3 ,\r\nV_2 -> V_16 ) );\r\n}
