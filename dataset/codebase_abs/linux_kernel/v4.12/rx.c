static inline T_1 * F_1 ( struct V_1 * V_2 )\r\n{\r\nreturn F_2 ( V_2 -> V_3 ) + V_2 -> V_4 ;\r\n}\r\nstatic inline T_2 F_3 ( struct V_5 * V_6 , const T_1 * V_7 )\r\n{\r\n#if F_4 ( V_8 )\r\nreturn F_5 ( ( const V_9 * ) ( V_7 + V_6 -> V_10 ) ) ;\r\n#else\r\nconst T_1 * V_11 = V_7 + V_6 -> V_10 ;\r\nreturn ( T_2 ) V_11 [ 0 ] |\r\n( T_2 ) V_11 [ 1 ] << 8 |\r\n( T_2 ) V_11 [ 2 ] << 16 |\r\n( T_2 ) V_11 [ 3 ] << 24 ;\r\n#endif\r\n}\r\nstatic inline struct V_1 *\r\nF_6 ( struct V_12 * V_13 , struct V_1 * V_14 )\r\n{\r\nif ( F_7 ( V_14 == V_1 ( V_13 , V_13 -> V_15 ) ) )\r\nreturn V_1 ( V_13 , 0 ) ;\r\nelse\r\nreturn V_14 + 1 ;\r\n}\r\nstatic inline void F_8 ( struct V_5 * V_6 ,\r\nstruct V_1 * V_14 ,\r\nunsigned int V_16 )\r\n{\r\nF_9 ( & V_6 -> V_17 -> V_18 , V_14 -> V_19 , V_16 ,\r\nV_20 ) ;\r\n}\r\nvoid F_10 ( struct V_5 * V_6 )\r\n{\r\nV_6 -> V_21 = F_11 ( V_6 -> V_22 + V_6 -> V_23 ,\r\nV_24 ) ;\r\nV_6 -> V_25 = V_6 -> V_26 ? 1 :\r\n( ( V_27 - sizeof( struct V_28 ) ) /\r\nV_6 -> V_21 ) ;\r\nV_6 -> V_29 = ( V_27 << V_6 -> V_26 ) /\r\nV_6 -> V_25 ;\r\nV_6 -> V_30 = F_12 ( V_31 ,\r\nV_6 -> V_25 ) ;\r\n}\r\nstatic struct V_3 * F_13 ( struct V_12 * V_13 )\r\n{\r\nstruct V_5 * V_6 = V_13 -> V_6 ;\r\nstruct V_3 * V_3 ;\r\nstruct V_28 * V_32 ;\r\nunsigned V_33 ;\r\nV_33 = V_13 -> V_34 & V_13 -> V_35 ;\r\nV_3 = V_13 -> V_36 [ V_33 ] ;\r\nif ( V_3 == NULL )\r\nreturn NULL ;\r\nV_13 -> V_36 [ V_33 ] = NULL ;\r\nif ( V_13 -> V_34 != V_13 -> V_37 )\r\n++ V_13 -> V_34 ;\r\nif ( F_14 ( V_3 ) == 1 ) {\r\n++ V_13 -> V_38 ;\r\nreturn V_3 ;\r\n} else {\r\nV_32 = F_2 ( V_3 ) ;\r\nF_15 ( & V_6 -> V_17 -> V_18 , V_32 -> V_19 ,\r\nV_27 << V_6 -> V_26 ,\r\nV_20 ) ;\r\nF_16 ( V_3 ) ;\r\n++ V_13 -> V_39 ;\r\n}\r\nreturn NULL ;\r\n}\r\nstatic int F_17 ( struct V_12 * V_13 , bool V_40 )\r\n{\r\nstruct V_5 * V_6 = V_13 -> V_6 ;\r\nstruct V_1 * V_14 ;\r\nstruct V_3 * V_3 ;\r\nunsigned int V_4 ;\r\nstruct V_28 * V_32 ;\r\nT_3 V_19 ;\r\nunsigned V_33 , V_41 ;\r\nV_41 = 0 ;\r\ndo {\r\nV_3 = F_13 ( V_13 ) ;\r\nif ( V_3 == NULL ) {\r\nV_3 = F_18 ( V_42 | V_43 |\r\n( V_40 ? V_44 : V_45 ) ,\r\nV_6 -> V_26 ) ;\r\nif ( F_7 ( V_3 == NULL ) )\r\nreturn - V_46 ;\r\nV_19 =\r\nF_19 ( & V_6 -> V_17 -> V_18 , V_3 , 0 ,\r\nV_27 << V_6 -> V_26 ,\r\nV_20 ) ;\r\nif ( F_7 ( F_20 ( & V_6 -> V_17 -> V_18 ,\r\nV_19 ) ) ) {\r\nF_21 ( V_3 , V_6 -> V_26 ) ;\r\nreturn - V_47 ;\r\n}\r\nV_32 = F_2 ( V_3 ) ;\r\nV_32 -> V_19 = V_19 ;\r\n} else {\r\nV_32 = F_2 ( V_3 ) ;\r\nV_19 = V_32 -> V_19 ;\r\n}\r\nV_19 += sizeof( struct V_28 ) ;\r\nV_4 = sizeof( struct V_28 ) ;\r\ndo {\r\nV_33 = V_13 -> V_48 & V_13 -> V_15 ;\r\nV_14 = V_1 ( V_13 , V_33 ) ;\r\nV_14 -> V_19 = V_19 + V_6 -> V_23 ;\r\nV_14 -> V_3 = V_3 ;\r\nV_14 -> V_4 = V_4 + V_6 -> V_23 ;\r\nV_14 -> V_16 = V_6 -> V_22 ;\r\nV_14 -> V_49 = 0 ;\r\n++ V_13 -> V_48 ;\r\nF_22 ( V_3 ) ;\r\nV_19 += V_6 -> V_21 ;\r\nV_4 += V_6 -> V_21 ;\r\n} while ( V_4 + V_6 -> V_21 <= V_27 );\r\nV_14 -> V_49 = V_50 ;\r\n} while ( ++ V_41 < V_6 -> V_30 );\r\nreturn 0 ;\r\n}\r\nstatic void F_23 ( struct V_5 * V_6 ,\r\nstruct V_1 * V_14 )\r\n{\r\nstruct V_3 * V_3 = V_14 -> V_3 ;\r\nif ( V_3 ) {\r\nstruct V_28 * V_32 = F_2 ( V_3 ) ;\r\nF_15 ( & V_6 -> V_17 -> V_18 ,\r\nV_32 -> V_19 ,\r\nV_27 << V_6 -> V_26 ,\r\nV_20 ) ;\r\n}\r\n}\r\nstatic void F_24 ( struct V_12 * V_13 ,\r\nstruct V_1 * V_14 ,\r\nunsigned int V_51 )\r\n{\r\ndo {\r\nif ( V_14 -> V_3 ) {\r\nF_16 ( V_14 -> V_3 ) ;\r\nV_14 -> V_3 = NULL ;\r\n}\r\nV_14 = F_6 ( V_13 , V_14 ) ;\r\n} while ( -- V_51 );\r\n}\r\nstatic void F_25 ( struct V_52 * V_53 ,\r\nstruct V_1 * V_14 )\r\n{\r\nstruct V_3 * V_3 = V_14 -> V_3 ;\r\nstruct V_12 * V_13 = F_26 ( V_53 ) ;\r\nstruct V_5 * V_6 = V_13 -> V_6 ;\r\nunsigned V_33 ;\r\nif ( ! ( V_14 -> V_49 & V_50 ) )\r\nreturn;\r\nV_33 = V_13 -> V_37 & V_13 -> V_35 ;\r\nif ( V_13 -> V_36 [ V_33 ] == NULL ) {\r\nunsigned V_54 = V_13 -> V_34 &\r\nV_13 -> V_35 ;\r\nif ( V_54 == V_33 )\r\n++ V_13 -> V_34 ;\r\nV_13 -> V_36 [ V_33 ] = V_3 ;\r\n++ V_13 -> V_37 ;\r\nreturn;\r\n}\r\n++ V_13 -> V_55 ;\r\nF_23 ( V_6 , V_14 ) ;\r\nF_16 ( V_14 -> V_3 ) ;\r\n}\r\nstatic void F_27 ( struct V_12 * V_13 ,\r\nstruct V_1 * V_14 )\r\n{\r\nif ( V_14 -> V_3 )\r\nF_16 ( V_14 -> V_3 ) ;\r\nif ( V_14 -> V_49 & V_50 ) {\r\nF_23 ( V_13 -> V_6 , V_14 ) ;\r\nF_24 ( V_13 , V_14 , 1 ) ;\r\n}\r\nV_14 -> V_3 = NULL ;\r\n}\r\nstatic void F_28 ( struct V_52 * V_53 ,\r\nstruct V_1 * V_14 ,\r\nunsigned int V_56 )\r\n{\r\nstruct V_12 * V_13 = F_26 ( V_53 ) ;\r\ndo {\r\nF_25 ( V_53 , V_14 ) ;\r\nV_14 = F_6 ( V_13 , V_14 ) ;\r\n} while ( -- V_56 );\r\n}\r\nstatic void F_29 ( struct V_52 * V_53 ,\r\nstruct V_1 * V_14 ,\r\nunsigned int V_56 )\r\n{\r\nstruct V_12 * V_13 = F_26 ( V_53 ) ;\r\nF_28 ( V_53 , V_14 , V_56 ) ;\r\nF_24 ( V_13 , V_14 , V_56 ) ;\r\n}\r\nvoid F_30 ( struct V_12 * V_13 , bool V_40 )\r\n{\r\nstruct V_5 * V_6 = V_13 -> V_6 ;\r\nunsigned int V_57 , V_58 ;\r\nint V_59 , V_60 = 0 ;\r\nif ( ! V_13 -> V_61 )\r\nreturn;\r\nV_57 = ( V_13 -> V_48 - V_13 -> V_62 ) ;\r\nF_31 ( V_57 > V_13 -> V_6 -> V_63 ) ;\r\nif ( V_57 >= V_13 -> V_64 )\r\ngoto V_65;\r\nif ( F_7 ( V_57 < V_13 -> V_66 ) ) {\r\nif ( V_57 )\r\nV_13 -> V_66 = V_57 ;\r\n}\r\nV_58 = V_6 -> V_30 * V_6 -> V_25 ;\r\nV_59 = V_13 -> V_67 - V_57 ;\r\nF_31 ( V_59 < V_58 ) ;\r\nF_32 ( V_13 -> V_6 , V_68 , V_13 -> V_6 -> V_69 ,\r\nL_1\r\nL_2 ,\r\nF_33 ( V_13 ) , V_57 ,\r\nV_13 -> V_67 ) ;\r\ndo {\r\nV_60 = F_17 ( V_13 , V_40 ) ;\r\nif ( F_7 ( V_60 ) ) {\r\nif ( V_13 -> V_48 == V_13 -> V_62 )\r\nF_34 ( V_13 ) ;\r\ngoto V_65;\r\n}\r\n} while ( ( V_59 -= V_58 ) >= V_58 );\r\nF_32 ( V_13 -> V_6 , V_68 , V_13 -> V_6 -> V_69 ,\r\nL_3\r\nL_4 , F_33 ( V_13 ) ,\r\nV_13 -> V_48 - V_13 -> V_62 ) ;\r\nV_65:\r\nif ( V_13 -> V_70 != V_13 -> V_48 )\r\nF_35 ( V_13 ) ;\r\n}\r\nvoid F_36 ( unsigned long V_71 )\r\n{\r\nstruct V_12 * V_13 = (struct V_12 * ) V_71 ;\r\nF_37 ( V_13 ) ;\r\n++ V_13 -> V_72 ;\r\n}\r\nstatic void F_38 ( struct V_12 * V_13 ,\r\nstruct V_1 * V_14 ,\r\nint V_16 )\r\n{\r\nstruct V_5 * V_6 = V_13 -> V_6 ;\r\nunsigned V_73 = V_14 -> V_16 - V_6 -> type -> V_74 ;\r\nif ( F_39 ( V_16 <= V_73 ) )\r\nreturn;\r\nV_14 -> V_49 |= V_75 ;\r\nif ( ( V_16 > V_14 -> V_16 ) && F_40 ( V_6 ) ) {\r\nif ( F_41 () )\r\nF_42 ( V_6 , V_76 , V_6 -> V_69 ,\r\nL_5\r\nL_6 ,\r\nF_33 ( V_13 ) , V_16 , V_73 ,\r\nV_6 -> type -> V_74 ) ;\r\nF_43 ( V_6 , V_77 ) ;\r\n} else {\r\nif ( F_41 () )\r\nF_42 ( V_6 , V_76 , V_6 -> V_69 ,\r\nL_7\r\nL_8 ,\r\nF_33 ( V_13 ) , V_16 , V_73 ) ;\r\n}\r\nF_44 ( V_13 ) -> V_78 ++ ;\r\n}\r\nstatic void\r\nF_45 ( struct V_52 * V_53 , struct V_1 * V_14 ,\r\nunsigned int V_56 , T_1 * V_7 )\r\n{\r\nstruct V_79 * V_80 = & V_53 -> V_81 ;\r\nT_4 V_82 ;\r\nstruct V_5 * V_6 = V_53 -> V_6 ;\r\nstruct V_83 * V_84 ;\r\nV_84 = F_46 ( V_80 ) ;\r\nif ( F_7 ( ! V_84 ) ) {\r\nstruct V_12 * V_13 ;\r\nV_13 = F_26 ( V_53 ) ;\r\nF_24 ( V_13 , V_14 , V_56 ) ;\r\nreturn;\r\n}\r\nif ( V_6 -> V_69 -> V_85 & V_86 )\r\nF_47 ( V_84 , F_3 ( V_6 , V_7 ) ,\r\nV_87 ) ;\r\nV_84 -> V_88 = ( ( V_14 -> V_49 & V_89 ) ?\r\nV_90 : V_91 ) ;\r\nfor (; ; ) {\r\nF_48 ( V_84 , F_49 ( V_84 ) -> V_92 ,\r\nV_14 -> V_3 , V_14 -> V_4 ,\r\nV_14 -> V_16 ) ;\r\nV_14 -> V_3 = NULL ;\r\nV_84 -> V_16 += V_14 -> V_16 ;\r\nif ( F_49 ( V_84 ) -> V_92 == V_56 )\r\nbreak;\r\nV_14 = F_6 ( & V_53 -> V_13 , V_14 ) ;\r\n}\r\nV_84 -> V_93 = V_84 -> V_16 ;\r\nV_84 -> V_94 += V_56 * V_6 -> V_29 ;\r\nF_50 ( V_84 , V_53 -> V_13 . V_95 ) ;\r\nV_82 = F_51 ( V_80 ) ;\r\nif ( V_82 != V_96 )\r\nV_53 -> V_97 += 2 ;\r\n}\r\nstatic struct V_83 * F_52 ( struct V_52 * V_53 ,\r\nstruct V_1 * V_14 ,\r\nunsigned int V_56 ,\r\nT_1 * V_7 , int V_98 )\r\n{\r\nstruct V_5 * V_6 = V_53 -> V_6 ;\r\nstruct V_83 * V_84 ;\r\nV_84 = F_53 ( V_6 -> V_69 ,\r\nV_6 -> V_23 + V_6 -> V_99 +\r\nV_98 ) ;\r\nif ( F_7 ( V_84 == NULL ) ) {\r\nF_54 ( & V_6 -> V_100 ) ;\r\nreturn NULL ;\r\n}\r\nF_31 ( V_14 -> V_16 < V_98 ) ;\r\nmemcpy ( V_84 -> V_11 + V_6 -> V_23 , V_7 - V_6 -> V_99 ,\r\nV_6 -> V_99 + V_98 ) ;\r\nF_55 ( V_84 , V_6 -> V_23 + V_6 -> V_99 ) ;\r\nF_56 ( V_84 , V_98 ) ;\r\nif ( V_14 -> V_16 > V_98 ) {\r\nV_14 -> V_4 += V_98 ;\r\nV_14 -> V_16 -= V_98 ;\r\nfor (; ; ) {\r\nF_48 ( V_84 , F_49 ( V_84 ) -> V_92 ,\r\nV_14 -> V_3 , V_14 -> V_4 ,\r\nV_14 -> V_16 ) ;\r\nV_14 -> V_3 = NULL ;\r\nV_84 -> V_16 += V_14 -> V_16 ;\r\nV_84 -> V_93 += V_14 -> V_16 ;\r\nif ( F_49 ( V_84 ) -> V_92 == V_56 )\r\nbreak;\r\nV_14 = F_6 ( & V_53 -> V_13 , V_14 ) ;\r\n}\r\n} else {\r\nF_21 ( V_14 -> V_3 , V_6 -> V_26 ) ;\r\nV_14 -> V_3 = NULL ;\r\nV_56 = 0 ;\r\n}\r\nV_84 -> V_94 += V_56 * V_6 -> V_29 ;\r\nV_84 -> V_101 = F_57 ( V_84 , V_6 -> V_69 ) ;\r\nF_58 ( V_84 , & V_53 -> V_81 ) ;\r\nreturn V_84 ;\r\n}\r\nvoid F_59 ( struct V_12 * V_13 , unsigned int V_33 ,\r\nunsigned int V_56 , unsigned int V_16 , T_5 V_49 )\r\n{\r\nstruct V_5 * V_6 = V_13 -> V_6 ;\r\nstruct V_52 * V_53 = F_44 ( V_13 ) ;\r\nstruct V_1 * V_14 ;\r\nV_13 -> V_102 ++ ;\r\nV_14 = V_1 ( V_13 , V_33 ) ;\r\nV_14 -> V_49 |= V_49 ;\r\nif ( V_56 == 1 ) {\r\nif ( ! ( V_49 & V_103 ) )\r\nF_38 ( V_13 , V_14 , V_16 ) ;\r\n} else if ( F_7 ( V_56 > V_104 ) ||\r\nF_7 ( V_16 <= ( V_56 - 1 ) * V_6 -> V_22 ) ||\r\nF_7 ( V_16 > V_56 * V_6 -> V_22 ) ||\r\nF_7 ( ! V_6 -> V_105 ) ) {\r\nF_60 ( ! ( V_16 == 0 && V_14 -> V_49 & V_75 ) ) ;\r\nV_14 -> V_49 |= V_75 ;\r\n}\r\nF_32 ( V_6 , V_68 , V_6 -> V_69 ,\r\nL_9 ,\r\nF_33 ( V_13 ) , V_33 ,\r\n( V_33 + V_56 - 1 ) & V_13 -> V_15 , V_16 ,\r\n( V_14 -> V_49 & V_89 ) ? L_10 : L_11 ,\r\n( V_14 -> V_49 & V_75 ) ? L_12 : L_11 ) ;\r\nif ( F_7 ( V_14 -> V_49 & V_75 ) ) {\r\nF_61 ( V_53 ) ;\r\nF_29 ( V_53 , V_14 , V_56 ) ;\r\nreturn;\r\n}\r\nif ( V_56 == 1 && ! ( V_49 & V_103 ) )\r\nV_14 -> V_16 = V_16 ;\r\nF_8 ( V_6 , V_14 , V_14 -> V_16 ) ;\r\nF_62 ( F_1 ( V_14 ) ) ;\r\nV_14 -> V_4 += V_6 -> V_99 ;\r\nV_14 -> V_16 -= V_6 -> V_99 ;\r\nif ( V_56 > 1 ) {\r\nunsigned int V_106 = V_56 - 1 ;\r\nfor (; ; ) {\r\nV_14 = F_6 ( V_13 , V_14 ) ;\r\nif ( -- V_106 == 0 )\r\nbreak;\r\nF_8 ( V_6 , V_14 , V_6 -> V_22 ) ;\r\n}\r\nV_14 -> V_16 = V_16 - ( V_56 - 1 ) * V_6 -> V_22 ;\r\nF_8 ( V_6 , V_14 , V_14 -> V_16 ) ;\r\n}\r\nV_14 = V_1 ( V_13 , V_33 ) ;\r\nF_28 ( V_53 , V_14 , V_56 ) ;\r\nF_61 ( V_53 ) ;\r\nV_53 -> V_107 = V_56 ;\r\nV_53 -> V_108 = V_33 ;\r\n}\r\nstatic void F_63 ( struct V_52 * V_53 , T_1 * V_7 ,\r\nstruct V_1 * V_14 ,\r\nunsigned int V_56 )\r\n{\r\nstruct V_83 * V_84 ;\r\nT_5 V_98 = F_64 ( T_5 , V_14 -> V_16 , V_109 ) ;\r\nV_84 = F_52 ( V_53 , V_14 , V_56 , V_7 , V_98 ) ;\r\nif ( F_7 ( V_84 == NULL ) ) {\r\nstruct V_12 * V_13 ;\r\nV_13 = F_26 ( V_53 ) ;\r\nF_24 ( V_13 , V_14 , V_56 ) ;\r\nreturn;\r\n}\r\nF_50 ( V_84 , V_53 -> V_13 . V_95 ) ;\r\nF_65 ( V_84 ) ;\r\nif ( F_39 ( V_14 -> V_49 & V_89 ) )\r\nV_84 -> V_88 = V_90 ;\r\nif ( V_53 -> type -> V_110 )\r\nif ( V_53 -> type -> V_110 ( V_53 , V_84 ) )\r\nreturn;\r\nF_66 ( V_84 ) ;\r\n}\r\nvoid F_67 ( struct V_52 * V_53 )\r\n{\r\nstruct V_5 * V_6 = V_53 -> V_6 ;\r\nstruct V_1 * V_14 =\r\nV_1 ( & V_53 -> V_13 , V_53 -> V_108 ) ;\r\nT_1 * V_7 = F_1 ( V_14 ) ;\r\nif ( V_14 -> V_49 & V_103 )\r\nV_14 -> V_16 = F_68 ( ( V_111 * )\r\n( V_7 + V_6 -> V_112 ) ) ;\r\nif ( F_7 ( V_6 -> V_113 ) ) {\r\nstruct V_12 * V_13 ;\r\nF_69 ( V_6 , V_7 , V_14 -> V_16 ) ;\r\nV_13 = F_26 ( V_53 ) ;\r\nF_24 ( V_13 , V_14 ,\r\nV_53 -> V_107 ) ;\r\ngoto V_65;\r\n}\r\nif ( F_7 ( ! ( V_6 -> V_69 -> V_85 & V_114 ) ) )\r\nV_14 -> V_49 &= ~ V_89 ;\r\nif ( ( V_14 -> V_49 & V_115 ) && ! V_53 -> type -> V_110 )\r\nF_45 ( V_53 , V_14 , V_53 -> V_107 , V_7 ) ;\r\nelse\r\nF_63 ( V_53 , V_7 , V_14 , V_53 -> V_107 ) ;\r\nV_65:\r\nV_53 -> V_107 = 0 ;\r\n}\r\nint F_70 ( struct V_12 * V_13 )\r\n{\r\nstruct V_5 * V_6 = V_13 -> V_6 ;\r\nunsigned int V_116 ;\r\nint V_60 ;\r\nV_116 = F_71 ( F_72 ( V_6 -> V_63 ) , V_117 ) ;\r\nF_31 ( V_116 > V_118 ) ;\r\nV_13 -> V_15 = V_116 - 1 ;\r\nF_73 ( V_6 , V_119 , V_6 -> V_69 ,\r\nL_13 ,\r\nF_33 ( V_13 ) , V_6 -> V_63 ,\r\nV_13 -> V_15 ) ;\r\nV_13 -> V_120 = F_74 ( V_116 , sizeof( * V_13 -> V_120 ) ,\r\nV_45 ) ;\r\nif ( ! V_13 -> V_120 )\r\nreturn - V_46 ;\r\nV_60 = F_75 ( V_13 ) ;\r\nif ( V_60 ) {\r\nF_76 ( V_13 -> V_120 ) ;\r\nV_13 -> V_120 = NULL ;\r\n}\r\nreturn V_60 ;\r\n}\r\nstatic void F_77 ( struct V_5 * V_6 ,\r\nstruct V_12 * V_13 )\r\n{\r\nunsigned int V_121 , V_122 ;\r\n#ifdef F_78\r\nV_121 = V_123 ;\r\n#else\r\nif ( F_79 ( & V_124 ) )\r\nV_121 = V_123 ;\r\nelse\r\nV_121 = V_125 ;\r\n#endif\r\nV_122 = F_72 ( V_121 /\r\nV_6 -> V_25 ) ;\r\nV_13 -> V_36 = F_74 ( V_122 ,\r\nsizeof( * V_13 -> V_36 ) , V_45 ) ;\r\nV_13 -> V_35 = V_122 - 1 ;\r\n}\r\nvoid F_80 ( struct V_12 * V_13 )\r\n{\r\nstruct V_5 * V_6 = V_13 -> V_6 ;\r\nunsigned int V_67 , V_126 , V_127 ;\r\nF_73 ( V_13 -> V_6 , V_128 , V_13 -> V_6 -> V_69 ,\r\nL_14 , F_33 ( V_13 ) ) ;\r\nV_13 -> V_48 = 0 ;\r\nV_13 -> V_70 = 0 ;\r\nV_13 -> V_62 = 0 ;\r\nV_13 -> V_66 = - 1U ;\r\nF_77 ( V_6 , V_13 ) ;\r\nV_13 -> V_34 = 0 ;\r\nV_13 -> V_37 = V_13 -> V_35 + 1 ;\r\nV_13 -> V_38 = 0 ;\r\nV_13 -> V_39 = 0 ;\r\nV_13 -> V_55 = 0 ;\r\nV_67 = V_6 -> V_63 - V_129 ;\r\nV_127 =\r\nV_67 - V_6 -> V_30 * V_6 -> V_25 ;\r\nif ( V_130 != 0 ) {\r\nV_126 = V_67 * F_81 ( V_130 , 100U ) / 100U ;\r\nif ( V_126 > V_127 )\r\nV_126 = V_127 ;\r\n} else {\r\nV_126 = V_127 ;\r\n}\r\nV_13 -> V_67 = V_67 ;\r\nV_13 -> V_64 = V_126 ;\r\nV_13 -> V_61 = true ;\r\nF_82 ( V_13 ) ;\r\n}\r\nvoid F_83 ( struct V_12 * V_13 )\r\n{\r\nint V_131 ;\r\nstruct V_5 * V_6 = V_13 -> V_6 ;\r\nstruct V_1 * V_14 ;\r\nF_73 ( V_13 -> V_6 , V_128 , V_13 -> V_6 -> V_69 ,\r\nL_15 , F_33 ( V_13 ) ) ;\r\nF_84 ( & V_13 -> V_132 ) ;\r\nif ( V_13 -> V_120 ) {\r\nfor ( V_131 = V_13 -> V_62 ; V_131 < V_13 -> V_48 ;\r\nV_131 ++ ) {\r\nunsigned V_33 = V_131 & V_13 -> V_15 ;\r\nV_14 = V_1 ( V_13 , V_33 ) ;\r\nF_27 ( V_13 , V_14 ) ;\r\n}\r\n}\r\nfor ( V_131 = 0 ; V_131 <= V_13 -> V_35 ; V_131 ++ ) {\r\nstruct V_3 * V_3 = V_13 -> V_36 [ V_131 ] ;\r\nstruct V_28 * V_32 ;\r\nif ( V_3 == NULL )\r\ncontinue;\r\nV_32 = F_2 ( V_3 ) ;\r\nF_15 ( & V_6 -> V_17 -> V_18 , V_32 -> V_19 ,\r\nV_27 << V_6 -> V_26 ,\r\nV_20 ) ;\r\nF_16 ( V_3 ) ;\r\n}\r\nF_76 ( V_13 -> V_36 ) ;\r\nV_13 -> V_36 = NULL ;\r\n}\r\nvoid F_85 ( struct V_12 * V_13 )\r\n{\r\nF_73 ( V_13 -> V_6 , V_128 , V_13 -> V_6 -> V_69 ,\r\nL_16 , F_33 ( V_13 ) ) ;\r\nF_86 ( V_13 ) ;\r\nF_76 ( V_13 -> V_120 ) ;\r\nV_13 -> V_120 = NULL ;\r\n}\r\nint F_87 ( struct V_133 * V_69 , const struct V_83 * V_84 ,\r\nT_5 V_134 , T_2 V_135 )\r\n{\r\nstruct V_5 * V_6 = F_88 ( V_69 ) ;\r\nstruct V_52 * V_53 ;\r\nstruct V_136 V_137 ;\r\nstruct V_138 V_139 ;\r\nint V_60 ;\r\nif ( V_135 == V_140 )\r\nreturn - V_141 ;\r\nif ( ! F_89 ( V_84 , & V_139 , 0 ) )\r\nreturn - V_142 ;\r\nif ( V_139 . V_143 . V_144 != F_90 ( V_145 ) && V_139 . V_143 . V_144 != F_90 ( V_146 ) )\r\nreturn - V_142 ;\r\nif ( V_139 . V_147 . V_49 & V_148 )\r\nreturn - V_142 ;\r\nF_91 ( & V_137 , V_149 ,\r\nV_6 -> V_105 ? V_150 : 0 ,\r\nV_134 ) ;\r\nV_137 . V_151 =\r\nV_152 | V_153 |\r\nV_154 | V_155 |\r\nV_156 | V_157 ;\r\nV_137 . V_158 = V_139 . V_143 . V_144 ;\r\nV_137 . V_159 = V_139 . V_143 . V_159 ;\r\nif ( V_139 . V_143 . V_144 == F_90 ( V_145 ) ) {\r\nV_137 . V_160 [ 0 ] = V_139 . V_161 . V_162 . V_163 ;\r\nV_137 . V_164 [ 0 ] = V_139 . V_161 . V_162 . V_165 ;\r\n} else {\r\nmemcpy ( V_137 . V_160 , & V_139 . V_161 . V_166 . V_163 , sizeof( struct V_167 ) ) ;\r\nmemcpy ( V_137 . V_164 , & V_139 . V_161 . V_166 . V_165 , sizeof( struct V_167 ) ) ;\r\n}\r\nV_137 . V_168 = V_139 . V_169 . V_163 ;\r\nV_137 . V_170 = V_139 . V_169 . V_165 ;\r\nV_60 = V_6 -> type -> V_171 ( V_6 , & V_137 ) ;\r\nif ( V_60 < 0 )\r\nreturn V_60 ;\r\nV_53 = F_92 ( V_6 , V_134 ) ;\r\nV_53 -> V_172 [ V_60 ] = V_135 ;\r\n++ V_53 -> V_173 ;\r\nif ( V_137 . V_158 == F_90 ( V_145 ) )\r\nF_93 ( V_6 , V_68 , V_6 -> V_69 ,\r\nL_17 ,\r\n( V_137 . V_159 == V_174 ) ? L_18 : L_19 ,\r\nV_137 . V_160 , F_94 ( V_137 . V_168 ) , V_137 . V_164 ,\r\nF_94 ( V_137 . V_170 ) , V_134 , V_135 , V_60 ) ;\r\nelse\r\nF_93 ( V_6 , V_68 , V_6 -> V_69 ,\r\nL_20 ,\r\n( V_137 . V_159 == V_174 ) ? L_18 : L_19 ,\r\nV_137 . V_160 , F_94 ( V_137 . V_168 ) , V_137 . V_164 ,\r\nF_94 ( V_137 . V_170 ) , V_134 , V_135 , V_60 ) ;\r\nreturn V_60 ;\r\n}\r\nbool F_95 ( struct V_5 * V_6 , unsigned int V_175 )\r\n{\r\nbool (* F_96)( struct V_5 * V_6 , T_2 V_135 , unsigned int V_33 );\r\nunsigned int V_176 , V_33 , V_177 ;\r\nT_2 V_135 ;\r\nif ( ! F_97 ( & V_6 -> V_178 ) )\r\nreturn false ;\r\nF_96 = V_6 -> type -> V_179 ;\r\nV_176 = V_6 -> V_180 ;\r\nV_33 = V_6 -> V_181 ;\r\nV_177 = V_6 -> type -> V_182 ;\r\nwhile ( V_175 -- ) {\r\nstruct V_52 * V_53 = F_92 ( V_6 , V_176 ) ;\r\nV_135 = V_53 -> V_172 [ V_33 ] ;\r\nif ( V_135 != V_140 &&\r\nF_96 ( V_6 , V_135 , V_33 ) ) {\r\nF_93 ( V_6 , V_68 , V_6 -> V_69 ,\r\nL_21 ,\r\nV_33 , V_176 , V_135 ) ;\r\nV_53 -> V_172 [ V_33 ] = V_140 ;\r\n}\r\nif ( ++ V_33 == V_177 ) {\r\nif ( ++ V_176 == V_6 -> V_183 )\r\nV_176 = 0 ;\r\nV_33 = 0 ;\r\n}\r\n}\r\nV_6 -> V_180 = V_176 ;\r\nV_6 -> V_181 = V_33 ;\r\nF_98 ( & V_6 -> V_178 ) ;\r\nreturn true ;\r\n}\r\nbool F_99 ( const struct V_136 * V_137 )\r\n{\r\nif ( ! ( V_137 -> V_49 & V_184 ) ||\r\nV_137 -> V_185 == V_186 )\r\nreturn false ;\r\nif ( V_137 -> V_151 &\r\n( V_187 | V_188 ) &&\r\nF_100 ( V_137 -> V_189 ) )\r\nreturn true ;\r\nif ( ( V_137 -> V_151 &\r\n( V_152 | V_154 ) ) ==\r\n( V_152 | V_154 ) ) {\r\nif ( V_137 -> V_158 == F_90 ( V_145 ) &&\r\nF_101 ( V_137 -> V_164 [ 0 ] ) )\r\nreturn true ;\r\nif ( V_137 -> V_158 == F_90 ( V_146 ) &&\r\n( ( const T_1 * ) V_137 -> V_164 ) [ 0 ] == 0xff )\r\nreturn true ;\r\n}\r\nreturn false ;\r\n}
