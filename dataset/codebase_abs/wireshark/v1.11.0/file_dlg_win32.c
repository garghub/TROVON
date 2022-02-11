T_1
F_1 ( T_2 V_1 , T_3 * V_2 , T_3 * V_3 ) {
T_4 * V_4 ;
T_5 V_5 [ V_6 ] = F_2 ( L_1 ) ;
int V_7 ;
T_1 V_8 ;
#if ( V_9 >= 1500 )
T_6 V_10 ;
#endif
if ( ! V_2 || ! V_3 )
return FALSE ;
if ( V_2 -> V_11 > 0 ) {
F_3 ( V_5 , V_6 , F_4 ( V_2 -> V_12 ) ) ;
}
if ( V_3 -> V_11 > 0 ) {
V_13 = F_5 ( V_3 -> V_12 ) ;
} else if ( V_13 ) {
F_6 ( V_13 ) ;
V_13 = NULL ;
}
#if ( V_9 >= 1500 )
F_7 ( & V_10 , sizeof( T_6 ) ) ;
V_10 . V_14 = sizeof( T_6 ) ;
F_8 ( & V_10 ) ;
if ( V_10 . V_15 >= 5 ) {
V_7 = sizeof( T_4 ) ;
} else {
V_7 = V_16 ;
}
#else
V_7 = sizeof( T_4 ) + 12 ;
#endif
V_4 = F_9 ( V_7 ) ;
V_4 -> V_17 = V_7 ;
V_4 -> V_18 = V_1 ;
V_4 -> V_19 = ( V_20 ) F_10 ( V_1 , V_21 ) ;
V_4 -> V_22 = F_11 () ;
V_4 -> V_23 = NULL ;
V_4 -> V_24 = 0 ;
V_4 -> V_25 = V_26 ;
V_4 -> V_27 = V_5 ;
V_4 -> V_28 = V_6 ;
V_4 -> V_29 = NULL ;
V_4 -> V_30 = 0 ;
if ( V_31 . V_32 == V_33 && V_31 . V_34 [ 0 ] != '\0' ) {
V_4 -> V_35 = F_4 ( V_31 . V_34 ) ;
} else {
V_4 -> V_35 = F_4 ( F_12 () ) ;
}
V_4 -> V_36 = F_2 ( L_2 ) ;
V_4 -> V_37 = V_38 | V_39 | V_40 |
V_41 | V_42 | V_43 |
V_44 | V_45 ;
V_4 -> V_46 = NULL ;
V_4 -> V_47 = V_48 ;
V_4 -> V_49 = F_2 ( L_3 ) ;
V_8 = F_13 ( V_4 ) ;
if ( V_8 ) {
F_14 ( V_2 , L_4 , F_15 ( V_5 ) ) ;
F_14 ( V_3 , L_4 , V_13 ? V_13 : L_1 ) ;
}
F_6 ( ( void * ) V_4 -> V_22 ) ;
F_6 ( ( void * ) V_4 ) ;
F_6 ( V_13 ) ;
V_13 = NULL ;
return V_8 ;
}
T_7
F_16 ( T_2 V_50 , T_8 * V_51 , int V_52 )
{
T_9 V_53 ;
T_10 V_54 ;
V_53 = F_17 ( V_51 ) ;
if ( F_18 ( V_51 -> V_55 , V_53 ) ) {
return V_56 ;
}
if ( F_19 ( V_51 -> V_57 , V_53 ) ) {
V_54 = F_20 ( V_50 ,
F_2 ( L_5 )
F_2 ( L_6 )
F_2 ( L_7 ) ,
F_2 ( L_8 ) ,
V_58 | V_59 | V_60 ) ;
} else {
V_54 = F_20 ( V_50 ,
F_2 ( L_9 )
F_2 ( L_10 )
F_2 ( L_11 ) ,
F_2 ( L_8 ) ,
V_61 | V_59 | V_60 ) ;
}
switch ( V_54 ) {
case V_62 :
return V_63 ;
case V_64 :
case V_65 :
return V_66 ;
case V_67 :
default:
return V_68 ;
}
}
T_1
F_21 ( T_2 V_1 , T_8 * V_51 , T_3 * V_2 , int * V_52 ,
T_1 * V_69 , T_1 V_70 )
{
T_9 V_71 ;
T_11 * V_72 ;
T_4 * V_4 ;
T_5 V_5 [ V_6 ] = F_2 ( L_1 ) ;
int V_7 ;
T_1 V_73 ;
#if ( V_9 >= 1500 )
T_6 V_10 ;
#endif
T_1 V_74 = FALSE ;
if ( ! V_2 || ! V_52 || ! V_69 )
return FALSE ;
if ( V_2 -> V_11 > 0 ) {
F_3 ( V_5 , V_6 , F_4 ( V_2 -> V_12 ) ) ;
}
if ( V_70 )
V_71 = F_17 ( V_51 ) ;
else
V_71 = 0 ;
V_72 = F_22 ( V_51 -> V_55 , V_51 -> V_57 ,
V_71 ) ;
if ( V_72 == NULL )
return FALSE ;
V_75 = FALSE ;
#if ( V_9 >= 1500 )
F_7 ( & V_10 , sizeof( T_6 ) ) ;
V_10 . V_14 = sizeof( T_6 ) ;
F_8 ( & V_10 ) ;
if ( V_10 . V_15 >= 5 ) {
V_7 = sizeof( T_4 ) ;
} else {
V_7 = V_16 ;
}
#else
V_7 = sizeof( T_4 ) + 12 ;
#endif
V_4 = F_9 ( V_7 ) ;
V_4 -> V_17 = V_7 ;
V_4 -> V_18 = V_1 ;
V_4 -> V_19 = ( V_20 ) F_10 ( V_1 , V_21 ) ;
V_4 -> V_22 = F_23 ( V_72 ) ;
V_4 -> V_23 = NULL ;
V_4 -> V_24 = 0 ;
V_4 -> V_25 = 1 ;
V_4 -> V_27 = V_5 ;
V_4 -> V_28 = V_6 ;
V_4 -> V_29 = NULL ;
V_4 -> V_30 = 0 ;
V_4 -> V_35 = F_4 ( F_12 () ) ;
V_4 -> V_36 = F_2 ( L_12 ) ;
V_4 -> V_37 = V_38 | V_39 | V_40 |
V_41 | V_76 | V_43 |
V_77 | V_44 | V_45 ;
V_4 -> V_46 = NULL ;
V_4 -> V_78 = ( V_79 ) V_51 ;
V_4 -> V_47 = V_80 ;
V_4 -> V_49 = F_2 ( L_13 ) ;
V_73 = F_24 ( V_4 ) ;
if ( V_73 ) {
F_14 ( V_2 , L_4 , F_15 ( V_5 ) ) ;
* V_52 = F_25 ( V_72 , int , V_4 -> V_25 - 1 ) ;
* V_69 = V_75 ;
} else {
if ( F_26 () != 0 ) {
F_27 ( V_2 , 0 ) ;
V_73 = TRUE ;
}
}
V_81 = NULL ;
F_28 ( V_72 , TRUE ) ;
F_6 ( ( void * ) V_4 -> V_22 ) ;
F_6 ( ( void * ) V_4 ) ;
return V_73 ;
}
T_1
F_29 ( T_2 V_1 , T_8 * V_51 ,
T_3 * V_2 ,
int * V_52 ,
T_1 * V_69 ,
T_12 * V_82 ) {
T_11 * V_72 ;
T_4 * V_4 ;
T_5 V_5 [ V_6 ] = F_2 ( L_1 ) ;
int V_7 ;
T_1 V_73 ;
#if ( V_9 >= 1500 )
T_6 V_10 ;
#endif
if ( ! V_2 || ! V_52 || ! V_69 || ! V_82 )
return FALSE ;
if ( V_2 -> V_11 > 0 ) {
F_3 ( V_5 , V_6 , F_4 ( V_2 -> V_12 ) ) ;
}
V_72 = F_22 ( V_51 -> V_55 ,
V_51 -> V_57 , 0 ) ;
if ( V_72 == NULL )
return FALSE ;
V_83 = V_82 ;
V_84 = V_51 ;
V_75 = FALSE ;
#if ( V_9 >= 1500 )
F_7 ( & V_10 , sizeof( T_6 ) ) ;
V_10 . V_14 = sizeof( T_6 ) ;
F_8 ( & V_10 ) ;
if ( V_10 . V_15 >= 5 ) {
V_7 = sizeof( T_4 ) ;
} else {
V_7 = V_16 ;
}
#else
V_7 = sizeof( T_4 ) + 12 ;
#endif
V_4 = F_9 ( V_7 ) ;
V_4 -> V_17 = V_7 ;
V_4 -> V_18 = V_1 ;
V_4 -> V_19 = ( V_20 ) F_10 ( V_1 , V_21 ) ;
V_4 -> V_22 = F_23 ( V_72 ) ;
V_4 -> V_23 = NULL ;
V_4 -> V_24 = 0 ;
V_4 -> V_25 = 1 ;
V_4 -> V_27 = V_5 ;
V_4 -> V_28 = V_6 ;
V_4 -> V_29 = NULL ;
V_4 -> V_30 = 0 ;
V_4 -> V_35 = F_4 ( F_12 () ) ;
V_4 -> V_36 = F_2 ( L_14 ) ;
V_4 -> V_37 = V_38 | V_39 | V_40 |
V_41 | V_76 | V_43 |
V_77 | V_44 | V_45 ;
V_4 -> V_46 = NULL ;
V_4 -> V_47 = V_85 ;
V_4 -> V_49 = F_2 ( L_15 ) ;
V_73 = F_24 ( V_4 ) ;
if ( V_73 ) {
F_14 ( V_2 , L_4 , F_15 ( V_5 ) ) ;
* V_52 = F_25 ( V_72 , int , V_4 -> V_25 - 1 ) ;
* V_69 = V_75 ;
} else {
if ( F_26 () != 0 ) {
F_27 ( V_2 , 0 ) ;
V_73 = TRUE ;
}
}
V_81 = NULL ;
V_83 = NULL ;
V_84 = NULL ;
F_28 ( V_72 , TRUE ) ;
F_6 ( ( void * ) V_4 -> V_22 ) ;
F_6 ( ( void * ) V_4 ) ;
return V_73 ;
}
T_1
F_30 ( T_2 V_1 , T_3 * V_2 , T_3 * V_3 , int * V_86 ) {
T_4 * V_4 ;
T_5 V_5 [ V_6 ] = F_2 ( L_1 ) ;
int V_7 ;
T_1 V_8 ;
#if ( V_9 >= 1500 )
T_6 V_10 ;
#endif
if ( ! V_2 || ! V_3 || ! V_86 )
return FALSE ;
if ( V_2 -> V_11 > 0 ) {
F_3 ( V_5 , V_6 , F_4 ( V_2 -> V_12 ) ) ;
}
if ( V_3 -> V_11 > 0 ) {
V_13 = F_5 ( V_3 -> V_12 ) ;
} else if ( V_13 ) {
F_6 ( V_13 ) ;
V_13 = NULL ;
}
#if ( V_9 >= 1500 )
F_7 ( & V_10 , sizeof( T_6 ) ) ;
V_10 . V_14 = sizeof( T_6 ) ;
F_8 ( & V_10 ) ;
if ( V_10 . V_15 >= 5 ) {
V_7 = sizeof( T_4 ) ;
} else {
V_7 = V_16 ;
}
#else
V_7 = sizeof( T_4 ) + 12 ;
#endif
V_4 = F_9 ( V_7 ) ;
V_4 -> V_17 = V_7 ;
V_4 -> V_18 = V_1 ;
V_4 -> V_19 = ( V_20 ) F_10 ( V_1 , V_21 ) ;
V_4 -> V_22 = F_11 () ;
V_4 -> V_23 = NULL ;
V_4 -> V_24 = 0 ;
V_4 -> V_25 = V_87 ;
V_4 -> V_27 = V_5 ;
V_4 -> V_28 = V_6 ;
V_4 -> V_29 = NULL ;
V_4 -> V_30 = 0 ;
if ( V_31 . V_32 == V_33 && V_31 . V_34 [ 0 ] != '\0' ) {
V_4 -> V_35 = F_4 ( V_31 . V_34 ) ;
} else {
V_4 -> V_35 = F_4 ( F_12 () ) ;
}
V_4 -> V_36 = F_2 ( L_16 ) ;
V_4 -> V_37 = V_38 | V_39 | V_40 |
V_41 | V_42 | V_43 |
V_44 | V_45 ;
V_4 -> V_46 = NULL ;
V_4 -> V_47 = V_88 ;
V_4 -> V_49 = F_2 ( L_17 ) ;
V_8 = F_13 ( V_4 ) ;
if ( V_8 ) {
F_14 ( V_2 , L_4 , F_15 ( V_5 ) ) ;
F_14 ( V_3 , L_4 , V_13 ? V_13 : L_1 ) ;
switch ( V_89 ) {
case V_90 :
* V_86 = 1 ;
break;
case V_91 :
* V_86 = 0 ;
break;
case V_92 :
* V_86 = - 1 ;
break;
default:
F_31 () ;
}
}
F_6 ( ( void * ) V_4 -> V_22 ) ;
F_6 ( ( void * ) V_4 ) ;
F_6 ( V_13 ) ;
V_13 = NULL ;
return V_8 ;
}
void
F_32 ( T_2 V_1 , T_8 * V_51 , T_13 V_93 ) {
T_4 * V_4 ;
T_5 V_2 [ V_6 ] = F_2 ( L_1 ) ;
char * V_94 ;
T_14 V_95 ;
int V_7 ;
#if ( V_9 >= 1500 )
T_6 V_10 ;
#endif
V_84 = V_51 ;
#if ( V_9 >= 1500 )
F_7 ( & V_10 , sizeof( T_6 ) ) ;
V_10 . V_14 = sizeof( T_6 ) ;
F_8 ( & V_10 ) ;
if ( V_10 . V_15 >= 5 ) {
V_7 = sizeof( T_4 ) ;
} else {
V_7 = V_16 ;
}
#else
V_7 = sizeof( T_4 ) + 12 ;
#endif
V_4 = F_9 ( V_7 ) ;
V_4 -> V_17 = V_7 ;
V_4 -> V_18 = V_1 ;
V_4 -> V_19 = ( V_20 ) F_10 ( V_1 , V_21 ) ;
V_4 -> V_22 = V_96 ;
V_4 -> V_23 = NULL ;
V_4 -> V_24 = 0 ;
V_4 -> V_25 = V_93 ;
V_4 -> V_27 = V_2 ;
V_4 -> V_28 = V_6 ;
V_4 -> V_29 = NULL ;
V_4 -> V_30 = 0 ;
V_4 -> V_35 = F_4 ( F_12 () ) ;
V_4 -> V_36 = F_2 ( L_18 ) ;
V_4 -> V_37 = V_38 | V_39 | V_40 |
V_41 | V_76 | V_43 |
V_77 | V_44 | V_45 ;
V_4 -> V_46 = NULL ;
V_4 -> V_78 = ( V_79 ) V_51 ;
V_4 -> V_47 = V_97 ;
V_4 -> V_49 = F_2 ( L_19 ) ;
V_98 . V_99 = V_100 ;
V_98 . V_101 = TRUE ;
V_98 . V_102 = NULL ;
V_98 . V_103 = TRUE ;
V_98 . V_104 = TRUE ;
V_98 . V_105 = V_106 ;
V_98 . V_107 = FALSE ;
V_98 . V_108 = FALSE ;
if ( F_24 ( V_4 ) ) {
V_98 . V_109 = F_15 ( V_2 ) ;
switch ( V_4 -> V_25 ) {
case V_110 :
V_98 . V_111 = F_33 ( TRUE , V_98 . V_109 ) ;
if ( V_98 . V_111 == NULL ) {
F_34 ( V_98 . V_109 , V_112 , TRUE ) ;
F_6 ( ( void * ) V_4 ) ;
return;
}
V_95 = F_35 ( V_51 , & V_98 ) ;
break;
case V_113 :
V_98 . V_111 = F_36 ( TRUE , V_98 . V_109 ) ;
if ( V_98 . V_111 == NULL ) {
F_34 ( V_98 . V_109 , V_112 , TRUE ) ;
F_6 ( ( void * ) V_4 ) ;
return;
}
V_95 = F_35 ( V_51 , & V_98 ) ;
break;
case V_114 :
V_95 = F_37 ( V_51 , & V_98 ) ;
break;
case V_115 :
V_95 = F_38 ( V_51 , & V_98 ) ;
break;
case V_116 :
V_95 = F_39 ( V_51 , & V_98 ) ;
break;
case V_117 :
V_95 = F_40 ( V_51 , & V_98 ) ;
break;
default:
F_6 ( ( void * ) V_4 ) ;
return;
}
switch ( V_95 ) {
case V_118 :
break;
case V_119 :
F_34 ( V_98 . V_109 , V_112 , TRUE ) ;
break;
case V_120 :
F_41 ( V_98 . V_109 , V_112 ) ;
break;
}
V_94 = F_42 ( F_15 ( V_2 ) ) ;
F_43 ( V_94 ) ;
}
V_84 = NULL ;
F_6 ( ( void * ) V_4 ) ;
}
void
F_44 ( T_2 V_1 , T_8 * V_51 ) {
T_4 * V_4 ;
T_5 V_2 [ V_6 ] = F_2 ( L_1 ) ;
char * V_94 ;
const T_15 * V_121 ;
char * V_122 ;
int V_123 ;
int V_7 ;
#if ( V_9 >= 1500 )
T_6 V_10 ;
#endif
if ( ! V_51 -> V_124 ) {
F_45 ( V_125 , V_126 , L_20 ) ;
return;
}
#if ( V_9 >= 1500 )
F_7 ( & V_10 , sizeof( T_6 ) ) ;
V_10 . V_14 = sizeof( T_6 ) ;
F_8 ( & V_10 ) ;
if ( V_10 . V_15 >= 5 ) {
V_7 = sizeof( T_4 ) ;
} else {
V_7 = V_16 ;
}
#else
V_7 = sizeof( T_4 ) + 12 ;
#endif
V_4 = F_9 ( V_7 ) ;
V_4 -> V_17 = V_7 ;
V_4 -> V_18 = V_1 ;
V_4 -> V_19 = ( V_20 ) F_10 ( V_1 , V_21 ) ;
V_4 -> V_22 = V_127 ;
V_4 -> V_23 = NULL ;
V_4 -> V_24 = 0 ;
V_4 -> V_25 = V_128 ;
V_4 -> V_27 = V_2 ;
V_4 -> V_28 = V_6 ;
V_4 -> V_29 = NULL ;
V_4 -> V_30 = 0 ;
V_4 -> V_35 = F_4 ( F_12 () ) ;
V_4 -> V_36 = F_2 ( L_21 ) ;
V_4 -> V_37 = V_38 | V_39 | V_40 |
V_41 | V_76 | V_43 |
V_77 | V_44 | V_45 ;
V_4 -> V_46 = NULL ;
V_4 -> V_78 = V_51 -> V_124 -> V_129 ;
V_4 -> V_47 = V_130 ;
V_4 -> V_49 = F_2 ( L_22 ) ;
if ( F_24 ( V_4 ) ) {
F_6 ( ( void * ) V_4 ) ;
V_122 = F_15 ( V_2 ) ;
V_121 = F_46 ( V_51 -> V_124 -> V_131 , 0 , - 1 ) +
V_51 -> V_124 -> V_132 ;
V_123 = F_47 ( V_122 , V_133 | V_134 | V_135 | V_136 , 0666 ) ;
if ( V_123 == - 1 ) {
F_34 ( V_122 , V_112 , TRUE ) ;
return;
}
if ( F_48 ( V_123 , V_121 , V_51 -> V_124 -> V_129 ) < 0 ) {
F_41 ( V_122 , V_112 ) ;
F_49 ( V_123 ) ;
return;
}
if ( F_49 ( V_123 ) < 0 ) {
F_41 ( V_122 , V_112 ) ;
return;
}
V_94 = F_42 ( V_122 ) ;
F_43 ( V_94 ) ;
} else {
F_6 ( ( void * ) V_4 ) ;
}
}
void
F_50 ( T_2 V_1 ) {
T_4 * V_4 ;
T_5 V_2 [ V_6 ] = F_2 ( L_1 ) ;
char * V_94 ;
T_16 * V_137 ;
char * V_122 ;
int V_123 ;
int V_7 ;
int V_138 ;
#if ( V_9 >= 1500 )
T_6 V_10 ;
#endif
V_138 = F_51 () ;
if ( V_138 == 0 ) {
F_45 ( V_125 , V_126 , L_23 ) ;
return;
}
#if ( V_9 >= 1500 )
F_7 ( & V_10 , sizeof( T_6 ) ) ;
V_10 . V_14 = sizeof( T_6 ) ;
F_8 ( & V_10 ) ;
if ( V_10 . V_15 >= 5 ) {
V_7 = sizeof( T_4 ) ;
} else {
V_7 = V_16 ;
}
#else
V_7 = sizeof( T_4 ) + 12 ;
#endif
V_4 = F_9 ( V_7 ) ;
V_4 -> V_17 = V_7 ;
V_4 -> V_18 = V_1 ;
V_4 -> V_19 = ( V_20 ) F_10 ( V_1 , V_21 ) ;
V_4 -> V_22 = V_139 ;
V_4 -> V_23 = NULL ;
V_4 -> V_24 = 0 ;
V_4 -> V_25 = V_140 ;
V_4 -> V_27 = V_2 ;
V_4 -> V_28 = V_6 ;
V_4 -> V_29 = NULL ;
V_4 -> V_30 = 0 ;
V_4 -> V_35 = F_4 ( F_12 () ) ;
V_4 -> V_36 = F_2 ( L_24 ) ;
V_4 -> V_37 = V_38 | V_39 | V_40 |
V_41 | V_76 | V_43 |
V_77 | V_44 | V_45 ;
V_4 -> V_46 = NULL ;
V_4 -> V_78 = V_138 ;
V_4 -> V_47 = V_141 ;
V_4 -> V_49 = F_2 ( L_25 ) ;
if ( F_24 ( V_4 ) ) {
F_6 ( ( void * ) V_4 ) ;
V_122 = F_15 ( V_2 ) ;
V_137 = F_52 () ;
V_123 = F_47 ( V_122 , V_133 | V_134 | V_135 | V_136 , 0666 ) ;
if ( V_123 == - 1 ) {
F_34 ( V_122 , V_112 , TRUE ) ;
F_6 ( V_137 ) ;
return;
}
if ( F_53 ( V_123 , V_137 , ( unsigned int ) strlen ( V_137 ) ) < 0 ) {
F_41 ( V_122 , V_112 ) ;
F_54 ( V_123 ) ;
F_6 ( V_137 ) ;
return;
}
if ( F_54 ( V_123 ) < 0 ) {
F_41 ( V_122 , V_112 ) ;
F_6 ( V_137 ) ;
return;
}
V_94 = F_42 ( V_122 ) ;
F_43 ( V_94 ) ;
} else {
F_6 ( ( void * ) V_4 ) ;
}
F_6 ( V_137 ) ;
}
void
F_55 ( T_2 V_1 , T_8 * V_51 , T_17 V_142 ) {
T_4 * V_4 ;
T_5 V_2 [ V_6 ] = F_2 ( L_1 ) ;
T_16 * V_94 ;
int V_7 ;
#if ( V_9 >= 1500 )
T_6 V_10 ;
#endif
#if ( V_9 >= 1500 )
F_7 ( & V_10 , sizeof( T_6 ) ) ;
V_10 . V_14 = sizeof( T_6 ) ;
F_8 ( & V_10 ) ;
if ( V_10 . V_15 >= 5 ) {
V_7 = sizeof( T_4 ) ;
} else {
V_7 = V_16 ;
}
#else
V_7 = sizeof( T_4 ) + 12 ;
#endif
V_4 = F_9 ( V_7 ) ;
V_4 -> V_17 = V_7 ;
V_4 -> V_18 = V_1 ;
V_4 -> V_19 = ( V_20 ) F_10 ( V_1 , V_21 ) ;
V_4 -> V_22 = V_143 ;
V_4 -> V_23 = NULL ;
V_4 -> V_24 = 0 ;
V_4 -> V_25 = V_144 ;
V_4 -> V_27 = V_2 ;
V_4 -> V_28 = V_6 ;
V_4 -> V_29 = NULL ;
V_4 -> V_30 = 0 ;
V_4 -> V_35 = F_4 ( F_12 () ) ;
V_4 -> V_36 = F_2 ( L_26 ) ;
V_4 -> V_37 = V_38 | V_40 |
V_41 | V_76 | V_43 |
V_77 | V_44 ;
V_4 -> V_46 = NULL ;
V_4 -> V_47 = NULL ;
V_4 -> V_49 = NULL ;
V_145 = V_51 -> V_55 ;
if ( F_24 ( V_4 ) ) {
F_6 ( ( void * ) V_4 ) ;
if ( ! F_56 ( F_15 ( V_2 ) , V_142 , FALSE ) )
return;
V_94 = F_42 ( F_15 ( V_2 ) ) ;
F_43 ( V_94 ) ;
} else {
F_6 ( ( void * ) V_4 ) ;
}
}
void
F_57 ( T_2 V_1 , T_17 V_146 ) {
T_4 * V_4 ;
T_5 V_2 [ V_6 ] = F_2 ( L_1 ) ;
T_16 * V_94 ;
int V_7 ;
#if ( V_9 >= 1500 )
T_6 V_10 ;
#endif
#if ( V_9 >= 1500 )
F_7 ( & V_10 , sizeof( T_6 ) ) ;
V_10 . V_14 = sizeof( T_6 ) ;
F_8 ( & V_10 ) ;
if ( V_10 . V_15 >= 5 ) {
V_7 = sizeof( T_4 ) ;
} else {
V_7 = V_16 ;
}
#else
V_7 = sizeof( T_4 ) + 12 ;
#endif
V_4 = F_9 ( V_7 ) ;
V_4 -> V_17 = V_7 ;
V_4 -> V_18 = V_1 ;
V_4 -> V_19 = ( V_20 ) F_10 ( V_1 , V_21 ) ;
V_4 -> V_22 = V_143 ;
V_4 -> V_23 = NULL ;
V_4 -> V_24 = 0 ;
V_4 -> V_25 = V_144 ;
V_4 -> V_27 = V_2 ;
V_4 -> V_28 = V_6 ;
V_4 -> V_29 = NULL ;
V_4 -> V_30 = 0 ;
V_4 -> V_35 = F_4 ( F_12 () ) ;
V_4 -> V_36 = F_2 ( L_27 ) ;
V_4 -> V_37 = V_38 | V_40 |
V_41 | V_76 | V_43 |
V_77 | V_44 ;
V_4 -> V_46 = NULL ;
V_4 -> V_47 = NULL ;
V_4 -> V_49 = NULL ;
if ( F_13 ( V_4 ) ) {
F_6 ( ( void * ) V_4 ) ;
if ( ! F_58 ( F_15 ( V_2 ) , V_146 ) )
return;
V_94 = F_42 ( F_15 ( V_2 ) ) ;
F_43 ( V_94 ) ;
} else {
F_6 ( ( void * ) V_4 ) ;
}
}
static void
F_59 ( T_2 V_147 , T_18 * args ) {
T_2 V_148 ;
V_148 = F_60 ( V_147 , V_149 ) ;
if ( F_61 ( V_148 , V_150 , 0 , 0 ) == V_151 ) {
args -> V_103 = TRUE ;
V_148 = F_60 ( V_147 , V_152 ) ;
F_62 ( V_148 , TRUE ) ;
if ( F_61 ( V_148 , V_150 , 0 , 0 ) == V_151 )
args -> V_104 = TRUE ;
else
args -> V_104 = FALSE ;
} else {
args -> V_103 = FALSE ;
args -> V_104 = FALSE ;
V_148 = F_60 ( V_147 , V_152 ) ;
F_62 ( V_148 , FALSE ) ;
}
V_148 = F_60 ( V_147 , V_153 ) ;
if ( F_61 ( V_148 , V_150 , 0 , 0 ) == V_151 ) {
V_148 = F_60 ( V_147 , V_154 ) ;
switch ( F_61 ( V_148 , V_155 , 0 , 0 ) ) {
case 0 :
args -> V_105 = V_156 ;
break;
case 1 :
args -> V_105 = V_106 ;
break;
case 2 :
args -> V_105 = V_157 ;
break;
default:
F_31 () ;
}
F_62 ( V_148 , TRUE ) ;
} else {
args -> V_105 = V_158 ;
V_148 = F_60 ( V_147 , V_154 ) ;
F_62 ( V_148 , FALSE ) ;
}
V_148 = F_60 ( V_147 , V_159 ) ;
if ( F_61 ( V_148 , V_150 , 0 , 0 ) == V_151 )
args -> V_107 = TRUE ;
else
args -> V_107 = FALSE ;
V_148 = F_60 ( V_147 , V_160 ) ;
if ( F_61 ( V_148 , V_150 , 0 , 0 ) == V_151 )
args -> V_108 = TRUE ;
else
args -> V_108 = FALSE ;
}
static void
F_63 ( T_2 V_147 , T_18 * args ) {
T_2 V_148 ;
V_148 = F_60 ( V_147 , V_149 ) ;
F_61 ( V_148 , V_161 , args -> V_103 , 0 ) ;
V_148 = F_60 ( V_147 , V_152 ) ;
F_61 ( V_148 , V_161 , args -> V_104 , 0 ) ;
V_148 = F_60 ( V_147 , V_153 ) ;
F_61 ( V_148 , V_161 , args -> V_105 != V_158 , 0 ) ;
V_148 = F_60 ( V_147 , V_154 ) ;
F_61 ( V_148 , V_162 , 0 , ( V_163 ) F_2 ( L_28 ) ) ;
F_61 ( V_148 , V_162 , 0 , ( V_163 ) F_2 ( L_29 ) ) ;
F_61 ( V_148 , V_162 , 0 , ( V_163 ) F_2 ( L_30 ) ) ;
switch ( args -> V_105 ) {
case V_158 :
case V_156 :
F_61 ( V_148 , V_164 , 0 , 0 ) ;
break;
case V_106 :
F_61 ( V_148 , V_164 , 1 , 0 ) ;
break;
case V_157 :
F_61 ( V_148 , V_164 , 2 , 0 ) ;
default:
F_31 () ;
}
V_148 = F_60 ( V_147 , V_159 ) ;
F_61 ( V_148 , V_161 , args -> V_107 , 0 ) ;
V_148 = F_60 ( V_147 , V_160 ) ;
F_61 ( V_148 , V_161 , args -> V_108 , 0 ) ;
F_59 ( V_147 , args ) ;
}
static T_1
F_64 ( T_2 V_165 , T_16 * V_166 ) {
T_2 V_148 ;
int V_167 ;
T_1 V_168 = FALSE ;
T_19 * V_169 ;
const struct V_170 * V_171 ;
int V_172 = 0 ;
T_16 * V_173 ;
T_5 V_174 [ V_175 ] ;
T_20 V_176 ;
T_21 V_177 = 0 ;
T_20 V_178 ;
T_22 V_179 ;
struct V_180 * V_181 ;
T_21 V_182 ;
T_22 V_183 ;
T_22 V_184 ;
double V_185 = 0 ;
double V_186 = 0 ;
double V_187 ;
T_1 V_188 = FALSE ;
for ( V_167 = V_189 ; V_167 <= V_190 ; V_167 ++ ) {
V_148 = F_60 ( V_165 , V_167 ) ;
if ( V_148 ) {
F_62 ( V_148 , FALSE ) ;
}
}
for ( V_167 = V_189 ; V_167 <= V_190 ; V_167 ++ ) {
V_148 = F_60 ( V_165 , V_167 ) ;
if ( V_148 ) {
F_65 ( V_148 , F_2 ( L_31 ) ) ;
}
}
if ( V_166 == NULL || strlen ( V_166 ) < 1 ) {
return FALSE ;
}
V_148 = F_60 ( V_165 , V_189 ) ;
if ( F_66 ( V_166 ) == V_191 ) {
F_65 ( V_148 , F_2 ( L_32 ) ) ;
return FALSE ;
}
V_169 = F_67 ( V_166 , & V_172 , & V_173 , TRUE ) ;
if ( V_148 && V_169 == NULL ) {
if( V_172 == V_192 ) {
F_65 ( V_148 , F_2 ( L_33 ) ) ;
} else {
F_65 ( V_148 , F_2 ( L_34 ) ) ;
}
return FALSE ;
}
for ( V_167 = V_193 ; V_167 <= V_190 ; V_167 ++ ) {
V_148 = F_60 ( V_165 , V_167 ) ;
if ( V_148 ) {
F_62 ( V_148 , TRUE ) ;
}
}
V_148 = F_60 ( V_165 , V_189 ) ;
F_65 ( V_148 , F_4 ( F_68 ( F_69 ( V_169 ) ) ) ) ;
V_178 = F_70 ( V_169 , & V_172 ) ;
F_71 ( V_174 , V_175 , L_35 V_194 L_36 , V_178 ) ;
V_148 = F_60 ( V_165 , V_195 ) ;
F_65 ( V_148 , V_174 ) ;
time ( & V_183 ) ;
while ( ( F_72 ( V_169 , & V_172 , & V_173 , & V_176 ) ) ) {
V_171 = F_73 ( V_169 ) ;
V_187 = F_74 ( ( const V_196 * ) & V_171 -> V_197 ) ;
if( V_177 == 0 ) {
V_185 = V_187 ;
V_186 = V_187 ;
}
if ( V_187 < V_185 ) {
V_185 = V_187 ;
}
if ( V_187 > V_186 ) {
V_186 = V_187 ;
}
V_177 ++ ;
if( V_177 % 100 == 0 ) {
time ( & V_184 ) ;
if( V_184 - V_183 >= ( T_22 ) V_31 . V_198 ) {
V_188 = TRUE ;
break;
}
}
}
if( V_172 != 0 ) {
F_75 ( V_174 , V_175 , F_2 ( L_37 ) , V_177 ) ;
V_148 = F_60 ( V_165 , V_199 ) ;
F_65 ( V_148 , V_174 ) ;
F_76 ( V_169 ) ;
return TRUE ;
}
if( V_188 ) {
F_75 ( V_174 , V_175 , F_2 ( L_38 ) , V_177 ) ;
} else {
F_75 ( V_174 , V_175 , F_2 ( L_39 ) , V_177 ) ;
}
V_148 = F_60 ( V_165 , V_199 ) ;
F_65 ( V_148 , V_174 ) ;
V_179 = ( long ) V_185 ;
V_181 = localtime ( & V_179 ) ;
if( V_181 ) {
F_75 ( V_174 , V_175 ,
F_2 ( L_40 ) ,
V_181 -> V_200 + 1900 ,
V_181 -> V_201 + 1 ,
V_181 -> V_202 ,
V_181 -> V_203 ,
V_181 -> V_204 ,
V_181 -> V_205 ) ;
} else {
F_75 ( V_174 , V_175 , F_2 ( L_41 ) ) ;
}
V_148 = F_60 ( V_165 , V_206 ) ;
F_65 ( V_148 , V_174 ) ;
V_182 = ( unsigned int ) ( V_186 - V_185 ) ;
if( V_182 / 86400 ) {
F_75 ( V_174 , V_175 , F_2 ( L_42 ) ,
V_182 / 86400 , V_182 % 86400 / 3600 , V_182 % 3600 / 60 , V_182 % 60 ) ;
} else {
F_75 ( V_174 , V_175 , F_2 ( L_43 ) ,
V_182 % 86400 / 3600 , V_182 % 3600 / 60 , V_182 % 60 ) ;
}
if( V_188 ) {
F_75 ( V_174 , V_175 , F_2 ( L_44 ) ) ;
}
V_148 = F_60 ( V_165 , V_190 ) ;
F_65 ( V_148 , V_174 ) ;
F_76 ( V_169 ) ;
return TRUE ;
}
static char *
F_77 ( T_2 V_207 ) {
T_5 * V_208 = NULL ;
T_10 V_11 ;
char * V_209 ;
V_11 = F_78 ( V_207 ) ;
if ( V_11 > 0 ) {
V_11 ++ ;
V_208 = F_79 ( V_11 * sizeof( T_5 ) ) ;
V_11 = F_80 ( V_207 , V_208 , V_11 ) ;
V_209 = F_81 ( V_208 , - 1 , NULL , NULL , NULL ) ;
F_6 ( V_208 ) ;
return V_209 ;
} else {
return NULL ;
}
}
static void
F_82 ( T_2 V_207 , T_5 * V_210 ) {
T_5 * V_208 = NULL ;
T_10 V_11 ;
T_23 * V_211 ;
if ( V_210 ) {
V_11 = ( F_83 ( V_210 ) + 1 ) * sizeof( T_5 ) ;
V_208 = F_79 ( V_11 ) ;
memcpy ( V_208 , V_210 , V_11 ) ;
} else {
V_11 = F_78 ( V_207 ) ;
if ( V_11 > 0 ) {
V_11 ++ ;
V_208 = F_79 ( V_11 * sizeof( T_5 ) ) ;
V_11 = F_80 ( V_207 , V_208 , V_11 ) ;
}
}
if ( V_11 == 0 ) {
F_61 ( V_207 , V_212 , ( V_163 ) 1 , V_213 ) ;
return;
} else if ( F_84 ( F_15 ( V_208 ) , & V_211 ) ) {
if ( V_211 != NULL )
F_85 ( V_211 ) ;
F_61 ( V_207 , V_212 , 0 , F_86 ( 0xe4 , 0xff , 0xc7 ) ) ;
} else {
F_61 ( V_207 , V_212 , 0 , F_86 ( 0xff , 0xcc , 0xcc ) ) ;
}
if ( V_208 ) F_6 ( V_208 ) ;
}
static T_24 T_25
V_48 ( T_2 V_165 , T_26 V_214 , V_163 V_215 , V_79 V_216 ) {
T_2 V_148 , V_50 ;
T_27 * V_217 = ( T_27 * ) V_216 ;
T_5 V_218 [ V_6 ] ;
switch( V_214 ) {
case V_219 :
if( V_13 != NULL ) {
V_148 = F_60 ( V_165 , V_220 ) ;
F_65 ( V_148 , F_4 ( V_13 ) ) ;
}
V_148 = F_60 ( V_165 , V_221 ) ;
F_61 ( V_148 , V_161 , V_222 . V_223 , 0 ) ;
V_148 = F_60 ( V_165 , V_224 ) ;
F_61 ( V_148 , V_161 , V_222 . V_225 , 0 ) ;
V_148 = F_60 ( V_165 , V_226 ) ;
F_61 ( V_148 , V_161 , V_222 . V_227 , 0 ) ;
V_148 = F_60 ( V_165 , V_228 ) ;
F_61 ( V_148 , V_161 , V_222 . V_229 , 0 ) ;
F_64 ( V_165 , NULL ) ;
break;
case V_230 :
switch ( V_217 -> V_231 . V_232 ) {
case V_233 :
V_148 = F_60 ( V_165 , V_220 ) ;
if ( V_13 )
F_6 ( V_13 ) ;
V_13 = F_77 ( V_148 ) ;
V_148 = F_60 ( V_165 , V_221 ) ;
if ( F_61 ( V_148 , V_150 , 0 , 0 ) == V_151 )
V_222 . V_223 = TRUE ;
V_148 = F_60 ( V_165 , V_224 ) ;
if ( F_61 ( V_148 , V_150 , 0 , 0 ) == V_151 )
V_222 . V_225 = TRUE ;
V_148 = F_60 ( V_165 , V_226 ) ;
if ( F_61 ( V_148 , V_150 , 0 , 0 ) == V_151 )
V_222 . V_227 = TRUE ;
V_148 = F_60 ( V_165 , V_228 ) ;
if ( F_61 ( V_148 , V_150 , 0 , 0 ) == V_151 )
V_222 . V_229 = TRUE ;
break;
case V_234 :
V_50 = F_87 ( V_165 ) ;
F_88 ( V_50 , V_218 , V_6 ) ;
F_64 ( V_165 , F_15 ( V_218 ) ) ;
break;
case V_235 :
F_89 ( V_236 ) ;
break;
default:
break;
}
break;
case V_237 :
V_148 = ( T_2 ) V_216 ;
switch( V_215 ) {
case ( V_238 << 16 ) | V_220 :
F_82 ( V_148 , NULL ) ;
break;
default:
break;
}
break;
default:
break;
}
return 0 ;
}
static void
F_90 ( T_11 * V_239 , int V_240 )
{
T_3 * V_241 = F_91 ( L_1 ) ;
T_3 * V_242 = F_91 ( L_1 ) ;
T_16 V_243 ;
T_28 * V_244 , * V_245 ;
T_5 * V_246 ;
T_29 V_247 = 0 ;
V_244 = F_92 ( V_240 , TRUE ) ;
if ( V_244 == NULL ) {
F_14 ( V_241 , L_45 ) ;
} else {
F_14 ( V_241 , L_1 ) ;
V_243 = '\0' ;
for ( V_245 = V_244 ; V_245 != NULL ;
V_245 = F_93 ( V_245 ) ) {
if ( V_243 != '\0' )
F_94 ( V_241 , V_243 ) ;
F_95 ( V_241 , L_46 , ( char * ) V_245 -> V_248 ) ;
V_243 = ';' ;
}
F_96 ( V_244 ) ;
}
F_14 ( V_242 , L_47 , F_68 ( V_240 ) ,
V_241 -> V_12 ) ;
V_246 = F_4 ( V_242 -> V_12 ) ;
V_239 = F_97 ( V_239 , V_246 , ( T_21 ) strlen ( V_242 -> V_12 ) ) ;
V_239 = F_98 ( V_239 , V_247 ) ;
F_99 ( V_242 , TRUE ) ;
V_246 = F_4 ( V_241 -> V_12 ) ;
V_239 = F_97 ( V_239 , V_246 , ( T_21 ) strlen ( V_241 -> V_12 ) ) ;
V_239 = F_98 ( V_239 , V_247 ) ;
F_99 ( V_241 , TRUE ) ;
}
static T_5 *
F_11 ( void ) {
T_5 * V_246 ;
int V_240 ;
T_11 * V_239 ;
static const T_29 V_247 = 0 ;
T_3 * V_241 ;
T_16 V_243 ;
T_28 * V_244 , * V_245 ;
V_239 = F_100 ( FALSE , FALSE , 2 ) ;
V_246 = F_4 ( L_48 ) ;
V_239 = F_97 ( V_239 , V_246 , ( T_21 ) strlen ( L_48 ) ) ;
V_239 = F_98 ( V_239 , V_247 ) ;
V_246 = F_4 ( L_45 ) ;
V_239 = F_97 ( V_239 , V_246 , ( T_21 ) strlen ( L_45 ) ) ;
V_239 = F_98 ( V_239 , V_247 ) ;
V_246 = F_4 ( L_49 ) ;
V_239 = F_97 ( V_239 , V_246 , ( T_21 ) strlen ( L_49 ) ) ;
V_239 = F_98 ( V_239 , V_247 ) ;
V_241 = F_91 ( L_1 ) ;
V_244 = F_101 () ;
V_243 = '\0' ;
for ( V_245 = V_244 ; V_245 != NULL ;
V_245 = F_93 ( V_245 ) ) {
if ( V_243 != '\0' )
F_94 ( V_241 , V_243 ) ;
F_95 ( V_241 , L_46 , ( char * ) V_245 -> V_248 ) ;
V_243 = ';' ;
}
F_96 ( V_244 ) ;
V_246 = F_4 ( V_241 -> V_12 ) ;
V_239 = F_97 ( V_239 , V_246 , ( T_21 ) strlen ( V_241 -> V_12 ) ) ;
V_239 = F_98 ( V_239 , V_247 ) ;
for ( V_240 = 0 ; V_240 < V_249 ; V_240 ++ ) {
if ( V_240 == V_250 )
continue;
F_90 ( V_239 , V_240 ) ;
}
V_239 = F_98 ( V_239 , V_247 ) ;
return ( T_5 * ) F_28 ( V_239 , FALSE ) ;
}
static T_5 *
F_23 ( T_11 * V_72 ) {
T_21 V_167 ;
int V_240 ;
T_11 * V_239 = F_100 ( FALSE , FALSE , 2 ) ;
T_29 V_247 = 0 ;
for ( V_167 = 0 ; V_167 < V_72 -> V_11 ; V_167 ++ ) {
V_240 = F_25 ( V_72 , int , V_167 ) ;
F_90 ( V_239 , V_240 ) ;
}
V_239 = F_98 ( V_239 , V_247 ) ;
return ( T_5 * ) F_28 ( V_239 , FALSE ) ;
}
static T_24 T_25
V_80 ( T_2 V_251 , T_26 V_214 , V_163 V_215 , V_79 V_216 ) {
T_2 V_148 ;
T_27 * V_217 = ( T_27 * ) V_216 ;
switch( V_214 ) {
case V_219 : {
T_4 * V_252 = ( T_4 * ) V_216 ;
T_8 * V_51 = ( T_8 * ) V_252 -> V_78 ;
V_81 = V_251 ;
V_145 = V_51 -> V_55 ;
V_148 = F_60 ( V_251 , V_253 ) ;
F_61 ( V_148 , V_161 , V_75 , 0 ) ;
break;
}
case V_237 :
V_148 = ( T_2 ) V_216 ;
switch ( V_215 ) {
#if 0
case (CBN_SELCHANGE << 16) | EWFD_FILE_TYPE_COMBO:
index = SendMessage(cur_ctrl, CB_GETCURSEL, 0, 0);
if (index != CB_ERR) {
new_filetype = SendMessage(cur_ctrl, CB_GETITEMDATA, (WPARAM) index, 0);
if (new_filetype != CB_ERR) {
if (g_filetype != new_filetype) {
if (wtap_can_save_with_wiretap(new_filetype, cfile.linktypes)) {
cur_ctrl = GetDlgItem(sf_hwnd, EWFD_CAPTURED_BTN);
EnableWindow(cur_ctrl, TRUE);
cur_ctrl = GetDlgItem(sf_hwnd, EWFD_DISPLAYED_BTN);
EnableWindow(cur_ctrl, TRUE);
} else {
cur_ctrl = GetDlgItem(sf_hwnd, EWFD_CAPTURED_BTN);
SendMessage(cur_ctrl, BM_SETCHECK, 0, 0);
EnableWindow(cur_ctrl, FALSE);
cur_ctrl = GetDlgItem(sf_hwnd, EWFD_DISPLAYED_BTN);
EnableWindow(cur_ctrl, FALSE);
}
g_filetype = new_filetype;
cur_ctrl = GetDlgItem(sf_hwnd, EWFD_GZIP_CB);
if (wtap_dump_can_compress(file_type) {
EnableWindow(cur_ctrl);
} else {
g_compressed = FALSE;
DisableWindow(cur_ctrl);
}
SendMessage(cur_ctrl, BM_SETCHECK, g_compressed, 0);
}
}
}
break;
#endif
default:
break;
}
break;
case V_230 :
switch ( V_217 -> V_231 . V_232 ) {
case V_235 :
F_89 ( V_254 ) ;
break;
case V_233 : {
T_2 V_50 ;
char * V_122 ;
T_4 * V_252 = ( T_4 * ) V_217 -> V_255 ;
T_8 * V_51 = ( T_8 * ) V_252 -> V_78 ;
V_148 = F_60 ( V_251 , V_253 ) ;
if ( F_61 ( V_148 , V_150 , 0 , 0 ) == V_151 )
V_75 = TRUE ;
else
V_75 = FALSE ;
V_50 = F_87 ( V_251 ) ;
V_122 = F_15 ( V_217 -> V_255 -> V_27 ) ;
if ( F_102 ( V_51 -> V_256 , V_122 ) ) {
T_16 * V_12 = F_103 (
L_50
L_51 ,
V_122 ) ;
F_20 ( V_50 , F_4 ( V_12 ) , F_2 ( L_52 ) , V_257 | V_258 | V_259 ) ;
F_6 ( V_12 ) ;
F_104 ( V_251 , V_260 , 1L ) ;
return 1 ;
}
}
break;
default:
break;
}
break;
default:
break;
}
return 0 ;
}
static T_24 T_25
V_85 ( T_2 V_251 , T_26 V_214 , V_163 V_215 , V_79 V_216 ) {
T_2 V_148 ;
T_27 * V_217 = ( T_27 * ) V_216 ;
switch( V_214 ) {
case V_219 : {
V_81 = V_251 ;
V_145 = V_84 -> V_55 ;
F_105 ( V_251 , V_83 ) ;
V_148 = F_60 ( V_251 , V_253 ) ;
F_61 ( V_148 , V_161 , V_75 , 0 ) ;
break;
}
case V_237 :
V_148 = ( T_2 ) V_216 ;
switch ( V_215 ) {
#if 0
case (CBN_SELCHANGE << 16) | EWFD_FILE_TYPE_COMBO:
index = SendMessage(cur_ctrl, CB_GETCURSEL, 0, 0);
if (index != CB_ERR) {
new_filetype = SendMessage(cur_ctrl, CB_GETITEMDATA, (WPARAM) index, 0);
if (new_filetype != CB_ERR) {
if (g_filetype != new_filetype) {
if (wtap_can_save_with_wiretap(new_filetype, cfile.linktypes)) {
cur_ctrl = GetDlgItem(sf_hwnd, EWFD_CAPTURED_BTN);
EnableWindow(cur_ctrl, TRUE);
cur_ctrl = GetDlgItem(sf_hwnd, EWFD_DISPLAYED_BTN);
EnableWindow(cur_ctrl, TRUE);
} else {
cur_ctrl = GetDlgItem(sf_hwnd, EWFD_CAPTURED_BTN);
SendMessage(cur_ctrl, BM_SETCHECK, 0, 0);
EnableWindow(cur_ctrl, FALSE);
cur_ctrl = GetDlgItem(sf_hwnd, EWFD_DISPLAYED_BTN);
EnableWindow(cur_ctrl, FALSE);
}
g_filetype = new_filetype;
}
}
}
break;
#endif
default:
F_106 ( V_251 , V_148 , V_215 , V_83 ) ;
break;
}
break;
case V_230 :
switch ( V_217 -> V_231 . V_232 ) {
case V_235 :
F_89 ( V_254 ) ;
break;
case V_233 : {
T_2 V_50 ;
char * V_122 ;
T_4 * V_252 = ( T_4 * ) V_217 -> V_255 ;
T_8 * V_51 = ( T_8 * ) V_252 -> V_78 ;
V_148 = F_60 ( V_251 , V_253 ) ;
if ( F_61 ( V_148 , V_150 , 0 , 0 ) == V_151 )
V_75 = TRUE ;
else
V_75 = FALSE ;
V_50 = F_87 ( V_251 ) ;
V_122 = F_15 ( V_217 -> V_255 -> V_27 ) ;
if ( F_102 ( V_51 -> V_256 , V_122 ) ) {
T_16 * V_12 = F_103 (
L_50
L_51 ,
V_122 ) ;
F_20 ( V_50 , F_4 ( V_12 ) , F_2 ( L_52 ) , V_257 | V_258 | V_259 ) ;
F_6 ( V_12 ) ;
F_104 ( V_251 , V_260 , 1L ) ;
return 1 ;
}
}
break;
default:
break;
}
break;
default:
break;
}
return 0 ;
}
static void
F_107 ( T_2 V_147 , T_12 * V_82 ) {
T_2 V_148 ;
T_1 V_261 = FALSE ;
T_5 V_262 [ V_263 ] ;
T_10 V_264 ;
T_9 V_265 = 0 , V_266 = 0 ;
T_9 V_267 ;
T_1 V_268 = TRUE ;
V_148 = F_60 ( V_147 , V_269 ) ;
if ( F_61 ( V_148 , V_150 , 0 , 0 ) == V_151 )
V_261 = TRUE ;
V_148 = F_60 ( V_147 , V_270 ) ;
F_62 ( V_148 , ! V_261 ) ;
if ( V_82 -> V_271 ) {
F_75 ( V_262 , V_263 , F_2 ( L_39 ) , V_84 -> V_272 - V_82 -> V_265 ) ;
} else {
F_75 ( V_262 , V_263 , F_2 ( L_39 ) , V_84 -> V_272 ) ;
}
F_65 ( V_148 , V_262 ) ;
V_148 = F_60 ( V_147 , V_273 ) ;
F_62 ( V_148 , V_261 ) ;
if ( V_82 -> V_274 )
V_267 = V_82 -> V_275 ;
else
V_267 = V_82 -> V_267 ;
if ( V_82 -> V_271 ) {
F_75 ( V_262 , V_263 , F_2 ( L_39 ) , V_267 - V_82 -> V_266 ) ;
} else {
F_75 ( V_262 , V_263 , F_2 ( L_39 ) , V_267 ) ;
}
F_65 ( V_148 , V_262 ) ;
V_264 = ( V_84 -> V_276 ) ? V_84 -> V_276 -> V_277 : 0 ;
V_148 = F_60 ( V_147 , V_278 ) ;
F_62 ( V_148 , V_264 && ! V_261 ) ;
if ( V_82 -> V_271 && V_84 -> V_276 && V_84 -> V_276 -> V_279 . V_280 ) {
F_75 ( V_262 , V_263 , F_2 ( L_53 ) ) ;
} else {
F_75 ( V_262 , V_263 , F_2 ( L_39 ) , V_264 ? 1 : 0 ) ;
}
F_65 ( V_148 , V_262 ) ;
V_148 = F_60 ( V_147 , V_281 ) ;
F_62 ( V_148 , V_264 && V_261 ) ;
if ( V_82 -> V_271 && V_84 -> V_276 && V_84 -> V_276 -> V_279 . V_280 ) {
F_75 ( V_262 , V_263 , F_2 ( L_53 ) ) ;
} else {
F_75 ( V_262 , V_263 , F_2 ( L_39 ) , V_264 ? 1 : 0 ) ;
}
F_65 ( V_148 , V_262 ) ;
V_148 = F_60 ( V_147 , V_282 ) ;
F_62 ( V_148 , V_84 -> V_283 ) ;
V_148 = F_60 ( V_147 , V_284 ) ;
F_62 ( V_148 , V_84 -> V_283 && ! V_261 ) ;
if ( V_82 -> V_271 ) {
F_75 ( V_262 , V_263 , F_2 ( L_39 ) , V_84 -> V_283 - V_82 -> V_285 ) ;
} else {
F_75 ( V_262 , V_263 , F_2 ( L_39 ) , V_84 -> V_283 ) ;
}
F_65 ( V_148 , V_262 ) ;
V_148 = F_60 ( V_147 , V_286 ) ;
F_62 ( V_148 , V_84 -> V_283 && V_261 ) ;
if ( V_82 -> V_271 ) {
F_75 ( V_262 , V_263 , F_2 ( L_39 ) , V_82 -> V_287 - V_82 -> V_288 ) ;
} else {
F_75 ( V_262 , V_263 , F_2 ( L_39 ) , V_82 -> V_287 ) ;
}
F_65 ( V_148 , V_262 ) ;
V_148 = F_60 ( V_147 , V_289 ) ;
F_62 ( V_148 , V_82 -> V_290 ) ;
V_148 = F_60 ( V_147 , V_291 ) ;
F_62 ( V_148 , V_82 -> V_290 && ! V_261 ) ;
if ( V_82 -> V_271 ) {
F_75 ( V_262 , V_263 , F_2 ( L_39 ) , V_82 -> V_290 - V_82 -> V_292 ) ;
} else {
F_75 ( V_262 , V_263 , F_2 ( L_39 ) , V_82 -> V_290 ) ;
}
F_65 ( V_148 , V_262 ) ;
V_148 = F_60 ( V_147 , V_293 ) ;
F_62 ( V_148 , V_82 -> V_294 && V_261 ) ;
if ( V_82 -> V_271 ) {
F_75 ( V_262 , V_263 , F_2 ( L_39 ) , V_82 -> V_294 - V_82 -> V_295 ) ;
} else {
F_75 ( V_262 , V_263 , F_2 ( L_39 ) , V_82 -> V_294 ) ;
}
F_65 ( V_148 , V_262 ) ;
switch ( F_108 ( V_82 ) ) {
case V_296 :
V_148 = F_60 ( V_147 , V_297 ) ;
F_61 ( V_148 , V_212 , ( V_163 ) 1 , V_213 ) ;
V_148 = F_60 ( V_147 , V_298 ) ;
F_62 ( V_148 , ! V_261 ) ;
if ( V_82 -> V_271 ) {
F_75 ( V_262 , V_263 , F_2 ( L_39 ) , V_82 -> V_299 - V_82 -> V_300 ) ;
} else {
F_75 ( V_262 , V_263 , F_2 ( L_39 ) , V_82 -> V_299 ) ;
}
F_65 ( V_148 , V_262 ) ;
V_148 = F_60 ( V_147 , V_301 ) ;
F_62 ( V_148 , V_261 ) ;
if ( V_82 -> V_271 ) {
F_75 ( V_262 , V_263 , F_2 ( L_39 ) , V_82 -> V_302 - V_82 -> V_303 ) ;
} else {
F_75 ( V_262 , V_263 , F_2 ( L_39 ) , V_82 -> V_302 ) ;
}
F_65 ( V_148 , V_262 ) ;
break;
case V_304 :
if ( V_82 -> V_305 == V_306 ) V_268 = FALSE ;
V_148 = F_60 ( V_147 , V_297 ) ;
F_61 ( V_148 , V_212 , 0 , F_86 ( 0xff , 0xcc , 0xcc ) ) ;
V_148 = F_60 ( V_147 , V_298 ) ;
F_65 ( V_148 , F_2 ( L_54 ) ) ;
V_148 = F_60 ( V_147 , V_301 ) ;
F_65 ( V_148 , F_2 ( L_31 ) ) ;
break;
case V_307 :
if ( V_82 -> V_305 == V_306 ) V_268 = FALSE ;
V_148 = F_60 ( V_147 , V_297 ) ;
F_61 ( V_148 , V_212 , 0 , F_86 ( 0xff , 0xcc , 0xcc ) ) ;
V_148 = F_60 ( V_147 , V_298 ) ;
F_65 ( V_148 , F_2 ( L_55 ) ) ;
V_148 = F_60 ( V_147 , V_301 ) ;
F_65 ( V_148 , F_2 ( L_31 ) ) ;
break;
default:
F_31 () ;
}
switch( V_82 -> V_305 ) {
case ( V_308 ) :
V_265 = V_82 -> V_265 ;
V_266 = V_82 -> V_266 ;
break;
case ( V_309 ) :
V_265 = ( V_84 -> V_276 && V_84 -> V_276 -> V_279 . V_280 ) ? 1 : 0 ;
V_266 = V_265 ;
break;
case ( V_310 ) :
V_265 = V_82 -> V_285 ;
V_266 = V_82 -> V_288 ;
break;
case ( V_311 ) :
V_265 = V_82 -> V_292 ;
V_266 = V_82 -> V_295 ;
break;
case ( V_306 ) :
V_265 = V_82 -> V_300 ;
V_266 = V_82 -> V_303 ;
break;
default:
F_31 () ;
}
V_148 = F_60 ( V_147 , V_312 ) ;
F_62 ( V_148 , V_265 ) ;
V_148 = F_60 ( V_147 , V_313 ) ;
F_62 ( V_148 , V_265 && ! V_261 ) ;
F_75 ( V_262 , V_263 , F_2 ( L_39 ) , V_265 ) ;
F_65 ( V_148 , V_262 ) ;
V_148 = F_60 ( V_147 , V_314 ) ;
F_62 ( V_148 , V_266 && V_261 ) ;
F_75 ( V_262 , V_263 , F_2 ( L_39 ) , V_266 ) ;
F_65 ( V_148 , V_262 ) ;
V_148 = F_60 ( F_87 ( V_147 ) , V_65 ) ;
F_62 ( V_148 , V_268 ) ;
}
static void
F_105 ( T_2 V_147 , T_12 * V_82 ) {
T_2 V_148 ;
if ( V_82 -> V_315 )
V_148 = F_60 ( V_147 , V_269 ) ;
else
V_148 = F_60 ( V_147 , V_316 ) ;
F_61 ( V_148 , V_161 , TRUE , 0 ) ;
if( V_82 -> V_317 != NULL ) {
V_148 = F_60 ( V_147 , V_297 ) ;
F_65 ( V_148 , F_4 ( F_109 ( V_82 -> V_317 ) ) ) ;
}
F_107 ( V_147 , V_82 ) ;
switch( V_82 -> V_305 ) {
case ( V_308 ) :
V_148 = F_60 ( V_147 , V_318 ) ;
break;
case ( V_309 ) :
V_148 = F_60 ( V_147 , V_319 ) ;
break;
case ( V_310 ) :
V_148 = F_60 ( V_147 , V_282 ) ;
break;
case ( V_311 ) :
V_148 = F_60 ( V_147 , V_289 ) ;
break;
case ( V_306 ) :
V_148 = F_60 ( V_147 , V_320 ) ;
break;
default:
F_31 () ;
}
F_61 ( V_148 , V_161 , TRUE , 0 ) ;
}
static void
F_106 ( T_2 V_147 , T_2 V_321 , V_163 V_215 , T_12 * V_82 ) {
T_2 V_148 ;
T_5 V_322 [ V_323 ] ;
if ( ! V_82 ) return;
switch( V_215 ) {
case ( V_324 << 16 ) | V_316 :
case ( V_324 << 16 ) | V_269 :
V_148 = F_60 ( V_147 , V_316 ) ;
if ( F_61 ( V_148 , V_150 , 0 , 0 ) == V_151 )
V_82 -> V_315 = FALSE ;
else
V_82 -> V_315 = TRUE ;
F_107 ( V_147 , V_82 ) ;
break;
case ( V_324 << 16 ) | V_318 :
if ( F_61 ( V_321 , V_150 , 0 , 0 ) == V_151 ) {
V_82 -> V_305 = V_308 ;
F_107 ( V_147 , V_82 ) ;
}
break;
case ( V_324 << 16 ) | V_319 :
if ( F_61 ( V_321 , V_150 , 0 , 0 ) == V_151 ) {
V_82 -> V_305 = V_309 ;
F_107 ( V_147 , V_82 ) ;
}
break;
case ( V_324 << 16 ) | V_282 :
if ( F_61 ( V_321 , V_150 , 0 , 0 ) == V_151 ) {
V_82 -> V_305 = V_310 ;
F_107 ( V_147 , V_82 ) ;
}
break;
case ( V_324 << 16 ) | V_289 :
if ( F_61 ( V_321 , V_150 , 0 , 0 ) == V_151 ) {
V_82 -> V_305 = V_311 ;
F_107 ( V_147 , V_82 ) ;
}
break;
case ( V_324 << 16 ) | V_320 :
if ( F_61 ( V_321 , V_150 , 0 , 0 ) == V_151 ) {
V_82 -> V_305 = V_306 ;
F_107 ( V_147 , V_82 ) ;
V_148 = F_60 ( V_147 , V_297 ) ;
F_110 ( V_148 ) ;
}
break;
case ( V_325 << 16 ) | V_297 :
V_148 = F_60 ( V_147 , V_320 ) ;
F_61 ( V_148 , V_326 , 0 , 0 ) ;
break;
case ( V_238 << 16 ) | V_297 :
F_61 ( V_321 , V_327 , ( V_163 ) V_323 , ( V_79 ) V_322 ) ;
F_111 ( V_82 , F_15 ( V_322 ) ) ;
F_107 ( V_147 , V_82 ) ;
break;
case ( V_324 << 16 ) | V_312 :
if ( F_61 ( V_321 , V_150 , 0 , 0 ) == V_151 ) {
V_82 -> V_271 = TRUE ;
} else {
V_82 -> V_271 = FALSE ;
}
F_107 ( V_147 , V_82 ) ;
break;
}
}
static T_24 T_25
V_88 ( T_2 V_328 , T_26 V_214 , V_163 V_215 , V_79 V_216 ) {
T_2 V_148 , V_50 ;
T_27 * V_217 = ( T_27 * ) V_216 ;
T_5 V_218 [ V_6 ] ;
switch( V_214 ) {
case V_219 :
if( V_13 != NULL ) {
V_148 = F_60 ( V_328 , V_220 ) ;
F_65 ( V_148 , F_4 ( V_13 ) ) ;
}
V_148 = F_60 ( V_328 , V_329 ) ;
F_61 ( V_148 , V_161 , TRUE , 0 ) ;
V_89 = V_90 ;
F_64 ( V_328 , NULL ) ;
break;
case V_230 :
switch ( V_217 -> V_231 . V_232 ) {
case V_233 :
V_148 = F_60 ( V_328 , V_220 ) ;
if ( V_13 )
F_6 ( V_13 ) ;
V_13 = F_77 ( V_148 ) ;
V_148 = F_60 ( V_328 , V_329 ) ;
if( F_61 ( V_148 , V_150 , 0 , 0 ) == V_151 ) {
V_89 = V_91 ;
} else {
V_148 = F_60 ( V_328 , V_330 ) ;
if( F_61 ( V_148 , V_150 , 0 , 0 ) == V_151 ) {
V_89 = V_92 ;
}
}
break;
case V_234 :
V_50 = F_87 ( V_328 ) ;
F_88 ( V_50 , V_218 , V_6 ) ;
F_64 ( V_328 , F_15 ( V_218 ) ) ;
break;
case V_235 :
F_89 ( V_331 ) ;
break;
default:
break;
}
break;
case V_237 :
V_148 = ( T_2 ) V_216 ;
switch( V_215 ) {
case ( V_238 << 16 ) | V_220 :
F_82 ( V_148 , NULL ) ;
break;
default:
break;
}
break;
default:
break;
}
return 0 ;
}
static T_24 T_25
V_97 ( T_2 V_332 , T_26 V_214 , V_163 V_215 , V_79 V_216 ) {
T_2 V_148 ;
T_27 * V_217 = ( T_27 * ) V_216 ;
T_1 V_333 ;
int V_167 , V_334 ;
switch( V_214 ) {
case V_219 : {
T_4 * V_252 = ( T_4 * ) V_216 ;
T_8 * V_51 = ( T_8 * ) V_252 -> V_78 ;
F_112 ( & V_98 . V_82 , V_51 ) ;
V_98 . V_82 . V_315 = TRUE ;
F_105 ( V_332 , & V_98 . V_82 ) ;
F_63 ( V_332 , & V_98 ) ;
break;
}
case V_237 :
V_148 = ( T_2 ) V_216 ;
switch ( V_215 ) {
case ( V_335 << 16 ) | V_154 :
default:
F_106 ( V_332 , V_148 , V_215 , & V_98 . V_82 ) ;
F_59 ( V_332 , & V_98 ) ;
break;
}
break;
case V_230 :
switch ( V_217 -> V_231 . V_232 ) {
case V_233 :
break;
case V_336 :
V_334 = V_217 -> V_255 -> V_25 ;
if ( V_334 == 2 )
V_98 . V_99 = V_100 ;
else
V_98 . V_99 = V_337 ;
if ( V_334 == 3 || V_334 == 4 || V_334 == 5 || V_334 == 6 )
V_333 = FALSE ;
else
V_333 = TRUE ;
for ( V_167 = V_338 ; V_167 <= V_160 ; V_167 ++ ) {
V_148 = F_60 ( V_332 , V_167 ) ;
F_62 ( V_148 , V_333 ) ;
}
break;
case V_235 :
F_89 ( V_339 ) ;
break;
default:
break;
}
break;
default:
break;
}
return 0 ;
}
static T_24 T_25
V_130 ( T_2 V_332 , T_26 V_214 , V_163 V_215 , V_79 V_216 ) {
T_2 V_148 ;
T_4 * V_252 = ( T_4 * ) V_216 ;
T_5 V_340 [ V_263 ] ;
T_27 * V_217 = ( T_27 * ) V_216 ;
switch( V_214 ) {
case V_219 :
F_75 ( V_340 , V_263 , F_2 ( L_56 ) ,
V_252 -> V_78 , F_4 ( F_113 ( V_252 -> V_78 , L_1 , L_57 ) ) ) ;
V_148 = F_60 ( V_332 , V_341 ) ;
F_65 ( V_148 , V_340 ) ;
break;
case V_230 :
switch ( V_217 -> V_231 . V_232 ) {
case V_235 :
F_89 ( V_342 ) ;
break;
default:
break;
}
default:
break;
}
return 0 ;
}
static T_24 T_25
V_141 ( T_2 V_332 , T_26 V_214 , V_163 V_215 , V_79 V_216 ) {
T_2 V_148 ;
T_4 * V_252 = ( T_4 * ) V_216 ;
T_5 V_343 [ V_263 ] ;
T_27 * V_217 = ( T_27 * ) V_216 ;
switch( V_214 ) {
case V_219 :
F_75 ( V_343 , V_263 , F_2 ( L_58 ) ,
V_252 -> V_78 , F_4 ( F_113 ( V_252 -> V_78 , L_1 , L_57 ) ) ) ;
V_148 = F_60 ( V_332 , V_344 ) ;
F_65 ( V_148 , V_343 ) ;
break;
case V_230 :
switch ( V_217 -> V_231 . V_232 ) {
case V_235 :
F_89 ( V_342 ) ;
break;
default:
break;
}
default:
break;
}
return 0 ;
}
