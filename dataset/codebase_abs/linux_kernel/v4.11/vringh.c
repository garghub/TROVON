inline int F_1 ( const struct V_1 * V_2 ,\r\nint (* F_2)( const struct V_1 * V_2 ,\r\nT_1 * V_3 , const T_2 * V_4 ) ,\r\nT_1 * V_5 )\r\n{\r\nT_1 V_6 , V_7 , V_8 ;\r\nint V_9 ;\r\nV_9 = F_2 ( V_2 , & V_6 , & V_2 -> V_10 . V_11 -> V_12 ) ;\r\nif ( V_9 ) {\r\nF_3 ( L_1 ,\r\n& V_2 -> V_10 . V_11 -> V_12 ) ;\r\nreturn V_9 ;\r\n}\r\nif ( * V_5 == V_6 )\r\nreturn V_2 -> V_10 . V_13 ;\r\nF_4 ( V_2 -> V_14 ) ;\r\nV_7 = * V_5 & ( V_2 -> V_10 . V_13 - 1 ) ;\r\nV_9 = F_2 ( V_2 , & V_8 , & V_2 -> V_10 . V_11 -> V_15 [ V_7 ] ) ;\r\nif ( V_9 ) {\r\nF_3 ( L_2 ,\r\n* V_5 , & V_2 -> V_10 . V_11 -> V_15 [ V_7 ] ) ;\r\nreturn V_9 ;\r\n}\r\nif ( V_8 >= V_2 -> V_10 . V_13 ) {\r\nF_3 ( L_3 ,\r\nV_8 , V_2 -> V_10 . V_13 ) ;\r\nreturn - V_16 ;\r\n}\r\n( * V_5 ) ++ ;\r\nreturn V_8 ;\r\n}\r\nstatic inline T_3 F_5 ( struct V_17 * V_18 ,\r\nvoid * V_19 , T_4 V_20 ,\r\nint (* F_6)( void * V_21 , void * V_19 ,\r\nT_4 V_20 ) )\r\n{\r\nint V_9 , V_22 = 0 ;\r\nwhile ( V_20 && V_18 -> V_7 < V_18 -> V_23 ) {\r\nT_4 V_24 ;\r\nV_24 = F_7 ( V_18 -> V_18 [ V_18 -> V_7 ] . V_25 , V_20 ) ;\r\nV_9 = F_6 ( V_18 -> V_18 [ V_18 -> V_7 ] . V_26 , V_19 , V_24 ) ;\r\nif ( V_9 )\r\nreturn V_9 ;\r\nV_22 += V_24 ;\r\nV_20 -= V_24 ;\r\nV_19 += V_24 ;\r\nV_18 -> V_27 += V_24 ;\r\nV_18 -> V_18 [ V_18 -> V_7 ] . V_25 -= V_24 ;\r\nV_18 -> V_18 [ V_18 -> V_7 ] . V_26 += V_24 ;\r\nif ( ! V_18 -> V_18 [ V_18 -> V_7 ] . V_25 ) {\r\nV_18 -> V_18 [ V_18 -> V_7 ] . V_25 = V_18 -> V_27 ;\r\nV_18 -> V_18 [ V_18 -> V_7 ] . V_26 -= V_18 -> V_27 ;\r\nV_18 -> V_27 = 0 ;\r\nV_18 -> V_7 ++ ;\r\n}\r\n}\r\nreturn V_22 ;\r\n}\r\nstatic inline bool F_8 ( struct V_1 * V_2 , T_5 V_21 , T_4 * V_20 ,\r\nstruct V_28 * V_29 ,\r\nbool (* F_9)( struct V_1 * ,\r\nT_5 , struct V_28 * ) )\r\n{\r\nif ( V_21 < V_29 -> V_30 || V_21 > V_29 -> V_31 ) {\r\nif ( ! F_9 ( V_2 , V_21 , V_29 ) )\r\nreturn false ;\r\n}\r\nF_10 ( V_21 < V_29 -> V_30 || V_21 > V_29 -> V_31 ) ;\r\nif ( F_11 ( V_21 + * V_20 == 0 ) ) {\r\nif ( V_29 -> V_31 == - 1ULL )\r\nreturn true ;\r\ngoto V_32;\r\n}\r\nif ( V_21 + * V_20 < V_21 ) {\r\nF_3 ( L_4 ,\r\n* V_20 , ( unsigned long long ) V_21 ) ;\r\nreturn false ;\r\n}\r\nif ( F_11 ( V_21 + * V_20 - 1 > V_29 -> V_31 ) )\r\ngoto V_32;\r\nreturn true ;\r\nV_32:\r\n* V_20 = V_29 -> V_31 + 1 - V_21 ;\r\nreturn true ;\r\n}\r\nstatic inline bool F_12 ( struct V_1 * V_2 , T_5 V_21 , T_4 * V_20 ,\r\nstruct V_28 * V_29 ,\r\nbool (* F_9)( struct V_1 * ,\r\nT_5 , struct V_28 * ) )\r\n{\r\nreturn true ;\r\n}\r\nstatic int F_13 ( const struct V_1 * V_2 ,\r\nint * V_33 , T_1 * V_7 , void * V_21 ,\r\nconst struct V_34 * V_35 ,\r\nstruct V_34 * * V_36 , int * V_37 )\r\n{\r\nT_6 V_20 ;\r\nif ( * V_33 != - 1 ) {\r\nF_3 ( L_5 , * V_33 , * V_7 ) ;\r\nreturn - V_16 ;\r\n}\r\nV_20 = F_14 ( V_2 , V_35 -> V_20 ) ;\r\nif ( F_11 ( V_20 % sizeof( struct V_34 ) ) ) {\r\nF_3 ( L_6 , V_35 -> V_20 ) ;\r\nreturn - V_16 ;\r\n}\r\nif ( V_35 -> V_38 & F_15 ( V_2 , V_39 ) )\r\n* V_33 = F_16 ( V_2 , V_35 -> V_40 ) ;\r\nelse\r\n* V_33 = - 2 ;\r\n* V_36 = V_21 ;\r\n* V_37 = V_20 / sizeof( struct V_34 ) ;\r\n* V_7 = 0 ;\r\nreturn 0 ;\r\n}\r\nstatic int F_17 ( struct V_17 * V_18 , T_7 V_41 )\r\n{\r\nstruct V_42 * V_43 ;\r\nunsigned int V_44 , V_45 = ( V_18 -> V_46 & ~ V_47 ) * 2 ;\r\nif ( V_45 < 8 )\r\nV_45 = 8 ;\r\nV_44 = ( V_18 -> V_46 & V_47 ) ;\r\nif ( V_44 )\r\nV_43 = F_18 ( V_18 -> V_18 , V_45 * sizeof( struct V_48 ) , V_41 ) ;\r\nelse {\r\nV_43 = F_19 ( V_45 * sizeof( struct V_48 ) , V_41 ) ;\r\nif ( V_43 ) {\r\nmemcpy ( V_43 , V_18 -> V_18 ,\r\nV_18 -> V_46 * sizeof( struct V_48 ) ) ;\r\nV_44 = V_47 ;\r\n}\r\n}\r\nif ( ! V_43 )\r\nreturn - V_49 ;\r\nV_18 -> V_18 = V_43 ;\r\nV_18 -> V_46 = ( V_45 | V_44 ) ;\r\nreturn 0 ;\r\n}\r\nstatic T_1 T_8 F_20 ( const struct V_1 * V_2 , int * V_33 ,\r\nstruct V_34 * * V_36 , int * V_37 )\r\n{\r\nT_1 V_7 = * V_33 ;\r\n* V_33 = - 1 ;\r\n* V_36 = V_2 -> V_10 . V_35 ;\r\n* V_37 = V_2 -> V_10 . V_13 ;\r\nreturn V_7 ;\r\n}\r\nstatic int F_21 ( struct V_1 * V_2 , void * V_50 , const void * V_51 ,\r\nbool (* F_22)( struct V_1 * V_2 , T_5 V_21 , T_4 * V_20 ,\r\nstruct V_28 * V_29 ,\r\nbool (* F_9)( struct V_1 * V_2 ,\r\nT_5 ,\r\nstruct V_28 * ) ) ,\r\nbool (* F_9)( struct V_1 * V_2 ,\r\nT_5 V_21 ,\r\nstruct V_28 * V_52 ) ,\r\nstruct V_28 * V_29 ,\r\nint (* F_23)( void * V_50 , const void * V_51 , T_4 V_20 ) )\r\n{\r\nT_4 V_53 , V_20 = sizeof( struct V_34 ) ;\r\ndo {\r\nT_5 V_21 ;\r\nint V_9 ;\r\nV_53 = V_20 ;\r\nV_21 = ( T_5 ) ( unsigned long ) V_51 - V_29 -> V_54 ;\r\nif ( ! F_22 ( V_2 , V_21 , & V_53 , V_29 , F_9 ) )\r\nreturn - V_16 ;\r\nV_9 = F_23 ( V_50 , V_51 , V_53 ) ;\r\nif ( V_9 )\r\nreturn V_9 ;\r\nV_50 += V_53 ;\r\nV_51 += V_53 ;\r\nV_20 -= V_53 ;\r\n} while ( V_20 );\r\nreturn 0 ;\r\n}\r\nstatic inline int\r\nF_24 ( struct V_1 * V_2 , T_1 V_7 ,\r\nstruct V_17 * V_55 ,\r\nstruct V_17 * V_56 ,\r\nbool (* F_22)( struct V_1 * V_2 , T_5 V_21 , T_4 * V_20 ,\r\nstruct V_28 * V_29 ,\r\nbool (* F_9)( struct V_1 * , T_5 ,\r\nstruct V_28 * ) ) ,\r\nbool (* F_9)( struct V_1 * , T_5 , struct V_28 * ) ,\r\nT_7 V_41 ,\r\nint (* F_23)( void * V_50 , const void * V_51 , T_4 V_20 ) )\r\n{\r\nint V_9 , V_57 = 0 , V_33 , V_37 ;\r\nstruct V_34 V_35 , * V_36 ;\r\nstruct V_28 V_29 = { - 1ULL , 0 } , V_58 ;\r\nbool V_59 = false ;\r\nV_36 = V_2 -> V_10 . V_35 ;\r\nV_37 = V_2 -> V_10 . V_13 ;\r\nV_33 = - 1 ;\r\nif ( V_55 )\r\nV_55 -> V_7 = V_55 -> V_23 = 0 ;\r\nelse if ( V_56 )\r\nV_56 -> V_7 = V_56 -> V_23 = 0 ;\r\nelse\r\nF_25 () ;\r\nfor (; ; ) {\r\nvoid * V_21 ;\r\nstruct V_17 * V_18 ;\r\nT_4 V_20 ;\r\nif ( F_11 ( V_59 ) )\r\nV_9 = F_21 ( V_2 , & V_35 , & V_36 [ V_7 ] , F_22 , F_9 ,\r\n& V_58 , F_23 ) ;\r\nelse\r\nV_9 = F_23 ( & V_35 , & V_36 [ V_7 ] , sizeof( V_35 ) ) ;\r\nif ( F_11 ( V_9 ) )\r\ngoto V_60;\r\nif ( F_11 ( V_35 . V_38 &\r\nF_15 ( V_2 , V_61 ) ) ) {\r\nT_5 V_62 = F_26 ( V_2 , V_35 . V_21 ) ;\r\nV_20 = F_14 ( V_2 , V_35 . V_20 ) ;\r\nif ( ! F_22 ( V_2 , V_62 , & V_20 , & V_29 , F_9 ) ) {\r\nV_9 = - V_16 ;\r\ngoto V_60;\r\n}\r\nif ( F_11 ( V_20 != F_14 ( V_2 , V_35 . V_20 ) ) ) {\r\nV_59 = true ;\r\nV_58 = V_29 ;\r\n}\r\nV_21 = ( void * ) ( long ) ( V_62 + V_29 . V_54 ) ;\r\nV_9 = F_13 ( V_2 , & V_33 , & V_7 , V_21 , & V_35 ,\r\n& V_36 , & V_37 ) ;\r\nif ( V_9 )\r\ngoto V_60;\r\ncontinue;\r\n}\r\nif ( V_57 ++ == V_2 -> V_10 . V_13 ) {\r\nF_3 ( L_7 , V_36 ) ;\r\nV_9 = - V_63 ;\r\ngoto V_60;\r\n}\r\nif ( V_35 . V_38 & F_15 ( V_2 , V_64 ) )\r\nV_18 = V_56 ;\r\nelse {\r\nV_18 = V_55 ;\r\nif ( F_11 ( V_56 && V_56 -> V_7 ) ) {\r\nF_3 ( L_8 ,\r\n& V_36 [ V_7 ] ) ;\r\nV_9 = - V_16 ;\r\ngoto V_60;\r\n}\r\n}\r\nif ( ! V_18 ) {\r\nF_3 ( L_9 ,\r\n! V_56 ? L_10 : L_11 ) ;\r\nV_9 = - V_65 ;\r\ngoto V_60;\r\n}\r\nV_66:\r\nV_20 = F_14 ( V_2 , V_35 . V_20 ) ;\r\nif ( ! F_22 ( V_2 , F_26 ( V_2 , V_35 . V_21 ) , & V_20 , & V_29 ,\r\nF_9 ) ) {\r\nV_9 = - V_16 ;\r\ngoto V_60;\r\n}\r\nV_21 = ( void * ) ( unsigned long ) ( F_26 ( V_2 , V_35 . V_21 ) +\r\nV_29 . V_54 ) ;\r\nif ( F_11 ( V_18 -> V_23 == ( V_18 -> V_46 & ~ V_47 ) ) ) {\r\nV_9 = F_17 ( V_18 , V_41 ) ;\r\nif ( V_9 )\r\ngoto V_60;\r\n}\r\nV_18 -> V_18 [ V_18 -> V_23 ] . V_26 = V_21 ;\r\nV_18 -> V_18 [ V_18 -> V_23 ] . V_25 = V_20 ;\r\nV_18 -> V_23 ++ ;\r\nif ( F_11 ( V_20 != F_14 ( V_2 , V_35 . V_20 ) ) ) {\r\nV_35 . V_20 = F_27 ( V_2 ,\r\nF_14 ( V_2 , V_35 . V_20 ) - V_20 ) ;\r\nV_35 . V_21 = F_28 ( V_2 ,\r\nF_26 ( V_2 , V_35 . V_21 ) + V_20 ) ;\r\ngoto V_66;\r\n}\r\nif ( V_35 . V_38 & F_15 ( V_2 , V_39 ) ) {\r\nV_7 = F_16 ( V_2 , V_35 . V_40 ) ;\r\n} else {\r\nif ( F_11 ( V_33 > 0 ) ) {\r\nV_7 = F_20 ( V_2 , & V_33 ,\r\n& V_36 , & V_37 ) ;\r\nV_59 = false ;\r\n} else\r\nbreak;\r\n}\r\nif ( V_7 >= V_37 ) {\r\nF_3 ( L_12 , V_7 , V_37 ) ;\r\nV_9 = - V_16 ;\r\ngoto V_60;\r\n}\r\n}\r\nreturn 0 ;\r\nV_60:\r\nreturn V_9 ;\r\n}\r\nstatic inline int F_29 ( struct V_1 * V_2 ,\r\nconst struct V_67 * V_23 ,\r\nunsigned int V_68 ,\r\nint (* F_30)( const struct V_1 * V_2 ,\r\nT_2 * V_4 , T_1 V_3 ) ,\r\nint (* F_31)( struct V_67 * V_50 ,\r\nconst struct V_67\r\n* V_51 , unsigned V_13 ) )\r\n{\r\nstruct V_69 * V_70 ;\r\nint V_9 ;\r\nT_1 V_71 , V_72 ;\r\nV_70 = V_2 -> V_10 . V_23 ;\r\nV_71 = V_2 -> V_73 + V_2 -> V_74 ;\r\nV_72 = V_71 % V_2 -> V_10 . V_13 ;\r\nif ( V_68 > 1 && F_11 ( V_72 + V_68 >= V_2 -> V_10 . V_13 ) ) {\r\nT_1 V_53 = V_2 -> V_10 . V_13 - V_72 ;\r\nV_9 = F_31 ( & V_70 -> V_15 [ V_72 ] , V_23 , V_53 ) ;\r\nif ( ! V_9 )\r\nV_9 = F_31 ( & V_70 -> V_15 [ 0 ] , V_23 + V_53 ,\r\nV_68 - V_53 ) ;\r\n} else\r\nV_9 = F_31 ( & V_70 -> V_15 [ V_72 ] , V_23 , V_68 ) ;\r\nif ( V_9 ) {\r\nF_3 ( L_13 ,\r\nV_68 , V_72 , & V_70 -> V_15 [ V_72 ] ) ;\r\nreturn V_9 ;\r\n}\r\nF_32 ( V_2 -> V_14 ) ;\r\nV_9 = F_30 ( V_2 , & V_2 -> V_10 . V_23 -> V_12 , V_71 + V_68 ) ;\r\nif ( V_9 ) {\r\nF_3 ( L_14 ,\r\n& V_2 -> V_10 . V_23 -> V_12 ) ;\r\nreturn V_9 ;\r\n}\r\nV_2 -> V_74 += V_68 ;\r\nreturn 0 ;\r\n}\r\nstatic inline int F_33 ( struct V_1 * V_2 ,\r\nint (* F_2)( const struct V_1 * V_2 ,\r\nT_1 * V_3 ,\r\nconst T_2 * V_4 ) )\r\n{\r\nbool V_75 ;\r\nT_1 V_76 ;\r\nint V_9 ;\r\nF_34 ( V_2 -> V_14 ) ;\r\nif ( ! V_2 -> V_77 ) {\r\nT_1 V_38 ;\r\nV_9 = F_2 ( V_2 , & V_38 , & V_2 -> V_10 . V_11 -> V_38 ) ;\r\nif ( V_9 ) {\r\nF_3 ( L_15 ,\r\n& V_2 -> V_10 . V_11 -> V_38 ) ;\r\nreturn V_9 ;\r\n}\r\nreturn ( ! ( V_38 & V_78 ) ) ;\r\n}\r\nV_9 = F_2 ( V_2 , & V_76 , & F_35 ( & V_2 -> V_10 ) ) ;\r\nif ( V_9 ) {\r\nF_3 ( L_16 ,\r\n& F_35 ( & V_2 -> V_10 ) ) ;\r\nreturn V_9 ;\r\n}\r\nif ( F_11 ( V_2 -> V_74 > 0xffff ) )\r\nV_75 = true ;\r\nelse\r\nV_75 = F_36 ( V_76 ,\r\nV_2 -> V_73 + V_2 -> V_74 ,\r\nV_2 -> V_73 ) ;\r\nV_2 -> V_73 += V_2 -> V_74 ;\r\nV_2 -> V_74 = 0 ;\r\nreturn V_75 ;\r\n}\r\nstatic inline bool F_37 ( struct V_1 * V_2 ,\r\nint (* F_2)( const struct V_1 * V_2 ,\r\nT_1 * V_3 , const T_2 * V_4 ) ,\r\nint (* F_30)( const struct V_1 * V_2 ,\r\nT_2 * V_4 , T_1 V_3 ) )\r\n{\r\nT_1 V_11 ;\r\nif ( ! V_2 -> V_77 ) {\r\nif ( F_30 ( V_2 , & V_2 -> V_10 . V_23 -> V_38 , 0 ) != 0 ) {\r\nF_3 ( L_17 ,\r\n& V_2 -> V_10 . V_23 -> V_38 ) ;\r\nreturn true ;\r\n}\r\n} else {\r\nif ( F_30 ( V_2 , & F_38 ( & V_2 -> V_10 ) ,\r\nV_2 -> V_5 ) != 0 ) {\r\nF_3 ( L_18 ,\r\n& F_38 ( & V_2 -> V_10 ) ) ;\r\nreturn true ;\r\n}\r\n}\r\nF_34 ( V_2 -> V_14 ) ;\r\nif ( F_2 ( V_2 , & V_11 , & V_2 -> V_10 . V_11 -> V_12 ) != 0 ) {\r\nF_3 ( L_19 ,\r\n& V_2 -> V_10 . V_11 -> V_12 ) ;\r\nreturn true ;\r\n}\r\nreturn V_11 == V_2 -> V_5 ;\r\n}\r\nstatic inline void F_39 ( struct V_1 * V_2 ,\r\nint (* F_30)( const struct V_1 * V_2 ,\r\nT_2 * V_4 , T_1 V_3 ) )\r\n{\r\nif ( ! V_2 -> V_77 ) {\r\nif ( F_30 ( V_2 , & V_2 -> V_10 . V_23 -> V_38 ,\r\nV_79 ) ) {\r\nF_3 ( L_20 ,\r\n& V_2 -> V_10 . V_23 -> V_38 ) ;\r\n}\r\n}\r\n}\r\nstatic inline int F_40 ( const struct V_1 * V_2 , T_1 * V_3 , const T_2 * V_4 )\r\n{\r\nT_2 V_80 = 0 ;\r\nint V_81 = F_41 ( V_80 , ( V_82 T_2 V_83 * ) V_4 ) ;\r\n* V_3 = F_16 ( V_2 , V_80 ) ;\r\nreturn V_81 ;\r\n}\r\nstatic inline int F_42 ( const struct V_1 * V_2 , T_2 * V_4 , T_1 V_3 )\r\n{\r\nT_2 V_80 = F_15 ( V_2 , V_3 ) ;\r\nreturn F_43 ( V_80 , ( V_82 T_2 V_83 * ) V_4 ) ;\r\n}\r\nstatic inline int F_44 ( void * V_50 , const void * V_51 , T_4 V_20 )\r\n{\r\nreturn F_45 ( V_50 , ( V_82 void V_83 * ) V_51 , V_20 ) ?\r\n- V_84 : 0 ;\r\n}\r\nstatic inline int F_46 ( struct V_67 * V_50 ,\r\nconst struct V_67 * V_51 ,\r\nunsigned int V_13 )\r\n{\r\nreturn F_47 ( ( V_82 void V_83 * ) V_50 , V_51 ,\r\nsizeof( * V_50 ) * V_13 ) ? - V_84 : 0 ;\r\n}\r\nstatic inline int F_48 ( void * V_51 , void * V_50 , T_4 V_20 )\r\n{\r\nreturn F_45 ( V_50 , ( V_82 void V_83 * ) V_51 , V_20 ) ?\r\n- V_84 : 0 ;\r\n}\r\nstatic inline int F_49 ( void * V_50 , void * V_51 , T_4 V_20 )\r\n{\r\nreturn F_47 ( ( V_82 void V_83 * ) V_50 , V_51 , V_20 ) ?\r\n- V_84 : 0 ;\r\n}\r\nint F_50 ( struct V_1 * V_2 , T_5 V_85 ,\r\nunsigned int V_13 , bool V_14 ,\r\nstruct V_34 V_83 * V_35 ,\r\nstruct V_86 V_83 * V_11 ,\r\nstruct V_69 V_83 * V_23 )\r\n{\r\nif ( ! V_13 || V_13 > 0xffff || ( V_13 & ( V_13 - 1 ) ) ) {\r\nF_3 ( L_21 , V_13 ) ;\r\nreturn - V_16 ;\r\n}\r\nV_2 -> V_87 = ( V_85 & ( 1ULL << V_88 ) ) ;\r\nV_2 -> V_77 = ( V_85 & ( 1 << V_89 ) ) ;\r\nV_2 -> V_14 = V_14 ;\r\nV_2 -> V_74 = 0 ;\r\nV_2 -> V_5 = 0 ;\r\nV_2 -> V_73 = 0 ;\r\nV_2 -> V_10 . V_13 = V_13 ;\r\nV_2 -> V_10 . V_35 = ( V_82 struct V_34 * ) V_35 ;\r\nV_2 -> V_10 . V_11 = ( V_82 struct V_86 * ) V_11 ;\r\nV_2 -> V_10 . V_23 = ( V_82 struct V_69 * ) V_23 ;\r\nreturn 0 ;\r\n}\r\nint F_51 ( struct V_1 * V_2 ,\r\nstruct V_90 * V_55 ,\r\nstruct V_90 * V_56 ,\r\nbool (* F_9)( struct V_1 * V_2 ,\r\nT_5 V_21 , struct V_28 * V_52 ) ,\r\nT_1 * V_8 )\r\n{\r\nint V_9 ;\r\n* V_8 = V_2 -> V_10 . V_13 ;\r\nV_9 = F_1 ( V_2 , F_40 , & V_2 -> V_5 ) ;\r\nif ( V_9 < 0 )\r\nreturn V_9 ;\r\nif ( V_9 == V_2 -> V_10 . V_13 )\r\nreturn 0 ;\r\nF_52 ( sizeof( struct V_17 ) != sizeof( struct V_90 ) ) ;\r\nF_52 ( F_53 ( struct V_17 , V_18 ) !=\r\nF_53 ( struct V_90 , V_18 ) ) ;\r\nF_52 ( F_53 ( struct V_17 , V_7 ) !=\r\nF_53 ( struct V_90 , V_7 ) ) ;\r\nF_52 ( F_53 ( struct V_17 , V_23 ) !=\r\nF_53 ( struct V_90 , V_23 ) ) ;\r\nF_52 ( F_53 ( struct V_17 , V_46 ) !=\r\nF_53 ( struct V_90 , V_46 ) ) ;\r\nF_52 ( sizeof( struct V_48 ) != sizeof( struct V_42 ) ) ;\r\nF_52 ( F_53 ( struct V_48 , V_26 ) !=\r\nF_53 ( struct V_42 , V_26 ) ) ;\r\nF_52 ( F_53 ( struct V_48 , V_25 ) !=\r\nF_53 ( struct V_42 , V_25 ) ) ;\r\nF_52 ( sizeof( ( (struct V_48 * ) NULL ) -> V_26 )\r\n!= sizeof( ( (struct V_42 * ) NULL ) -> V_26 ) ) ;\r\nF_52 ( sizeof( ( (struct V_48 * ) NULL ) -> V_25 )\r\n!= sizeof( ( (struct V_42 * ) NULL ) -> V_25 ) ) ;\r\n* V_8 = V_9 ;\r\nV_9 = F_24 ( V_2 , * V_8 , (struct V_17 * ) V_55 ,\r\n(struct V_17 * ) V_56 ,\r\nF_8 , F_9 , V_91 , F_44 ) ;\r\nif ( V_9 )\r\nreturn V_9 ;\r\nreturn 1 ;\r\n}\r\nT_3 F_54 ( struct V_90 * V_55 , void * V_50 , T_4 V_20 )\r\n{\r\nreturn F_5 ( (struct V_17 * ) V_55 ,\r\nV_50 , V_20 , F_48 ) ;\r\n}\r\nT_3 F_55 ( struct V_90 * V_56 ,\r\nconst void * V_51 , T_4 V_20 )\r\n{\r\nreturn F_5 ( (struct V_17 * ) V_56 ,\r\n( void * ) V_51 , V_20 , F_49 ) ;\r\n}\r\nvoid F_56 ( struct V_1 * V_2 , unsigned int V_13 )\r\n{\r\nV_2 -> V_5 -= V_13 ;\r\n}\r\nint F_57 ( struct V_1 * V_2 , T_1 V_8 , T_6 V_20 )\r\n{\r\nstruct V_67 V_23 ;\r\nV_23 . V_92 = F_27 ( V_2 , V_8 ) ;\r\nV_23 . V_20 = F_27 ( V_2 , V_20 ) ;\r\nreturn F_29 ( V_2 , & V_23 , 1 , F_42 , F_46 ) ;\r\n}\r\nint F_58 ( struct V_1 * V_2 ,\r\nconst struct V_67 V_23 [] ,\r\nunsigned V_68 )\r\n{\r\nreturn F_29 ( V_2 , V_23 , V_68 ,\r\nF_42 , F_46 ) ;\r\n}\r\nbool F_59 ( struct V_1 * V_2 )\r\n{\r\nreturn F_37 ( V_2 , F_40 , F_42 ) ;\r\n}\r\nvoid F_60 ( struct V_1 * V_2 )\r\n{\r\nF_39 ( V_2 , F_42 ) ;\r\n}\r\nint F_61 ( struct V_1 * V_2 )\r\n{\r\nreturn F_33 ( V_2 , F_40 ) ;\r\n}\r\nstatic inline int F_62 ( const struct V_1 * V_2 ,\r\nT_1 * V_3 , const T_2 * V_4 )\r\n{\r\n* V_3 = F_16 ( V_2 , F_63 ( * V_4 ) ) ;\r\nreturn 0 ;\r\n}\r\nstatic inline int F_64 ( const struct V_1 * V_2 , T_2 * V_4 , T_1 V_3 )\r\n{\r\nF_65 ( * V_4 , F_15 ( V_2 , V_3 ) ) ;\r\nreturn 0 ;\r\n}\r\nstatic inline int F_66 ( void * V_50 , const void * V_51 , T_4 V_20 )\r\n{\r\nmemcpy ( V_50 , V_51 , V_20 ) ;\r\nreturn 0 ;\r\n}\r\nstatic inline int F_67 ( struct V_67 * V_50 ,\r\nconst struct V_67 * V_51 ,\r\nunsigned int V_13 )\r\n{\r\nmemcpy ( V_50 , V_51 , V_13 * sizeof( * V_50 ) ) ;\r\nreturn 0 ;\r\n}\r\nstatic inline int F_68 ( void * V_51 , void * V_50 , T_4 V_20 )\r\n{\r\nmemcpy ( V_50 , V_51 , V_20 ) ;\r\nreturn 0 ;\r\n}\r\nint F_69 ( struct V_1 * V_2 , T_5 V_85 ,\r\nunsigned int V_13 , bool V_14 ,\r\nstruct V_34 * V_35 ,\r\nstruct V_86 * V_11 ,\r\nstruct V_69 * V_23 )\r\n{\r\nif ( ! V_13 || V_13 > 0xffff || ( V_13 & ( V_13 - 1 ) ) ) {\r\nF_3 ( L_21 , V_13 ) ;\r\nreturn - V_16 ;\r\n}\r\nV_2 -> V_87 = ( V_85 & ( 1ULL << V_88 ) ) ;\r\nV_2 -> V_77 = ( V_85 & ( 1 << V_89 ) ) ;\r\nV_2 -> V_14 = V_14 ;\r\nV_2 -> V_74 = 0 ;\r\nV_2 -> V_5 = 0 ;\r\nV_2 -> V_73 = 0 ;\r\nV_2 -> V_10 . V_13 = V_13 ;\r\nV_2 -> V_10 . V_35 = V_35 ;\r\nV_2 -> V_10 . V_11 = V_11 ;\r\nV_2 -> V_10 . V_23 = V_23 ;\r\nreturn 0 ;\r\n}\r\nint F_70 ( struct V_1 * V_2 ,\r\nstruct V_17 * V_55 ,\r\nstruct V_17 * V_56 ,\r\nT_1 * V_8 ,\r\nT_7 V_41 )\r\n{\r\nint V_9 ;\r\nV_9 = F_1 ( V_2 , F_62 , & V_2 -> V_5 ) ;\r\nif ( V_9 < 0 )\r\nreturn V_9 ;\r\nif ( V_9 == V_2 -> V_10 . V_13 )\r\nreturn 0 ;\r\n* V_8 = V_9 ;\r\nV_9 = F_24 ( V_2 , * V_8 , V_55 , V_56 , F_12 , NULL ,\r\nV_41 , F_66 ) ;\r\nif ( V_9 )\r\nreturn V_9 ;\r\nreturn 1 ;\r\n}\r\nT_3 F_71 ( struct V_17 * V_55 , void * V_50 , T_4 V_20 )\r\n{\r\nreturn F_5 ( V_55 , V_50 , V_20 , F_68 ) ;\r\n}\r\nT_3 F_72 ( struct V_17 * V_56 ,\r\nconst void * V_51 , T_4 V_20 )\r\n{\r\nreturn F_5 ( V_56 , ( void * ) V_51 , V_20 , F_68 ) ;\r\n}\r\nvoid F_73 ( struct V_1 * V_2 , unsigned int V_13 )\r\n{\r\nV_2 -> V_5 -= V_13 ;\r\n}\r\nint F_74 ( struct V_1 * V_2 , T_1 V_8 , T_6 V_20 )\r\n{\r\nstruct V_67 V_23 ;\r\nV_23 . V_92 = F_27 ( V_2 , V_8 ) ;\r\nV_23 . V_20 = F_27 ( V_2 , V_20 ) ;\r\nreturn F_29 ( V_2 , & V_23 , 1 , F_64 , F_67 ) ;\r\n}\r\nbool F_75 ( struct V_1 * V_2 )\r\n{\r\nreturn F_37 ( V_2 , F_62 , F_64 ) ;\r\n}\r\nvoid F_76 ( struct V_1 * V_2 )\r\n{\r\nF_39 ( V_2 , F_64 ) ;\r\n}\r\nint F_77 ( struct V_1 * V_2 )\r\n{\r\nreturn F_33 ( V_2 , F_62 ) ;\r\n}
