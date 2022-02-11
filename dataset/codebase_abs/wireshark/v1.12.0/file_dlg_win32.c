static int
F_1 ()
{
T_1 V_1 = FALSE ;
int V_2 ;
#if ( V_3 >= 1500 )
#if ( V_3 >= 1800 )
T_2 V_4 ;
T_3 V_5 = 0 ;
int V_6 = V_7 ;
F_2 ( & V_4 , sizeof( T_2 ) ) ;
V_4 . V_8 = sizeof( T_2 ) ;
V_4 . V_9 = 5 ;
F_3 ( V_5 , V_10 , V_6 ) ;
V_1 = F_4 (
& V_4 ,
V_10 ,
V_5 ) ;
#else
T_4 V_4 ;
F_2 ( & V_4 , sizeof( T_4 ) ) ;
V_4 . V_8 = sizeof( T_4 ) ;
F_5 ( & V_4 ) ;
V_1 = ( V_4 . V_9 >= 5 ) ;
#endif
V_2 = ( V_1 ) ? sizeof( V_11 ) : V_12 ;
#else
V_2 = sizeof( V_11 ) + 12 ;
#endif
return V_2 ;
}
T_1
F_6 ( T_5 V_13 , T_6 * V_14 , unsigned int * type , T_6 * V_15 ) {
V_11 * V_16 ;
T_7 V_17 [ V_18 ] = F_7 ( L_1 ) ;
int V_2 ;
T_1 V_19 ;
if ( ! V_14 || ! V_15 )
return FALSE ;
if ( V_14 -> V_20 > 0 ) {
F_8 ( V_17 , V_18 , F_9 ( V_14 -> V_21 ) ) ;
}
if ( V_15 -> V_20 > 0 ) {
V_22 = F_10 ( V_15 -> V_21 ) ;
} else if ( V_22 ) {
F_11 ( V_22 ) ;
V_22 = NULL ;
}
V_2 = F_1 () ;
V_16 = F_12 ( V_2 ) ;
V_16 -> V_23 = V_2 ;
V_16 -> V_24 = V_13 ;
V_16 -> V_25 = ( V_26 ) F_13 ( V_13 , V_27 ) ;
V_16 -> V_28 = F_14 () ;
V_16 -> V_29 = NULL ;
V_16 -> V_30 = 0 ;
V_16 -> V_31 = V_32 ;
V_16 -> V_33 = V_17 ;
V_16 -> V_34 = V_18 ;
V_16 -> V_35 = NULL ;
V_16 -> V_36 = 0 ;
if ( V_37 . V_38 == V_39 && V_37 . V_40 [ 0 ] != '\0' ) {
V_16 -> V_41 = F_9 ( V_37 . V_40 ) ;
} else {
V_16 -> V_41 = F_9 ( F_15 () ) ;
}
V_16 -> V_42 = F_7 ( L_2 ) ;
V_16 -> V_43 = V_44 | V_45 | V_46 |
V_47 | V_48 | V_49 |
V_50 | V_51 ;
V_16 -> V_52 = NULL ;
V_16 -> V_53 = V_54 ;
V_16 -> V_55 = F_7 ( L_3 ) ;
V_19 = F_16 ( V_16 ) ;
if ( V_19 ) {
F_17 ( V_14 , L_4 , F_18 ( V_17 ) ) ;
F_17 ( V_15 , L_4 , V_22 ? V_22 : L_1 ) ;
* type = V_56 ;
}
F_11 ( ( void * ) V_16 -> V_28 ) ;
F_11 ( ( void * ) V_16 ) ;
F_11 ( V_22 ) ;
V_22 = NULL ;
return V_19 ;
}
T_8
F_19 ( T_5 V_57 , T_9 * V_58 , int V_59 )
{
T_10 V_60 ;
T_11 V_61 ;
V_60 = F_20 ( V_58 ) ;
if ( F_21 ( V_58 -> V_62 , V_60 ) ) {
return V_63 ;
}
if ( F_22 ( V_58 -> V_64 , V_60 ) ) {
V_61 = F_23 ( V_57 ,
F_7 ( L_5 )
F_7 ( L_6 )
F_7 ( L_7 ) ,
F_7 ( L_8 ) ,
V_65 | V_66 | V_67 ) ;
} else {
V_61 = F_23 ( V_57 ,
F_7 ( L_9 )
F_7 ( L_10 )
F_7 ( L_11 ) ,
F_7 ( L_8 ) ,
V_68 | V_66 | V_67 ) ;
}
switch ( V_61 ) {
case V_69 :
return V_70 ;
case V_71 :
case V_72 :
return V_73 ;
case V_74 :
default:
return V_75 ;
}
}
T_1
F_24 ( T_5 V_13 , T_9 * V_58 , T_6 * V_14 , int * V_59 ,
T_1 * V_76 , T_1 V_77 )
{
T_10 V_78 ;
T_12 * V_79 ;
V_11 * V_16 ;
T_7 V_17 [ V_18 ] = F_7 ( L_1 ) ;
int V_2 ;
T_1 V_80 ;
T_1 V_81 = FALSE ;
if ( ! V_14 || ! V_59 || ! V_76 )
return FALSE ;
if ( V_14 -> V_20 > 0 ) {
F_8 ( V_17 , V_18 , F_9 ( V_14 -> V_21 ) ) ;
}
if ( V_77 )
V_78 = F_20 ( V_58 ) ;
else
V_78 = 0 ;
V_79 = F_25 ( V_58 -> V_62 ,
V_58 -> V_64 ,
V_78 ) ;
if ( V_79 == NULL )
return FALSE ;
V_82 = FALSE ;
V_2 = F_1 () ;
V_16 = F_12 ( V_2 ) ;
V_16 -> V_23 = V_2 ;
V_16 -> V_24 = V_13 ;
V_16 -> V_25 = ( V_26 ) F_13 ( V_13 , V_27 ) ;
V_16 -> V_28 = F_26 ( V_79 ) ;
V_16 -> V_29 = NULL ;
V_16 -> V_30 = 0 ;
V_16 -> V_31 = 1 ;
V_16 -> V_33 = V_17 ;
V_16 -> V_34 = V_18 ;
V_16 -> V_35 = NULL ;
V_16 -> V_36 = 0 ;
V_16 -> V_41 = F_9 ( F_15 () ) ;
V_16 -> V_42 = F_7 ( L_12 ) ;
V_16 -> V_43 = V_44 | V_45 | V_46 |
V_47 | V_83 | V_49 |
V_84 | V_50 | V_51 ;
V_16 -> V_52 = NULL ;
V_16 -> V_85 = ( V_86 ) V_58 ;
V_16 -> V_53 = V_87 ;
V_16 -> V_55 = F_7 ( L_13 ) ;
V_80 = F_27 ( V_16 ) ;
if ( V_80 ) {
F_17 ( V_14 , L_4 , F_18 ( V_17 ) ) ;
* V_59 = F_28 ( V_79 , int , V_16 -> V_31 - 1 ) ;
* V_76 = V_82 ;
} else {
if ( F_29 () != 0 ) {
F_30 ( V_14 , 0 ) ;
V_80 = TRUE ;
}
}
V_88 = NULL ;
F_31 ( V_79 , TRUE ) ;
F_11 ( ( void * ) V_16 -> V_28 ) ;
F_11 ( ( void * ) V_16 ) ;
return V_80 ;
}
T_1 F_32 ( T_5 V_13 , T_6 * V_14 , int * V_59 )
{
V_11 * V_16 ;
T_7 V_17 [ V_18 ] = F_7 ( L_1 ) ;
int V_2 ;
T_1 V_80 ;
#if ( V_3 >= 1500 )
T_4 V_4 ;
#endif
if ( ! V_14 || ! V_59 )
return FALSE ;
if ( V_14 -> V_20 > 0 ) {
F_8 ( V_17 , V_18 , F_9 ( V_14 -> V_21 ) ) ;
}
#if ( V_3 >= 1500 )
F_2 ( & V_4 , sizeof( T_4 ) ) ;
V_4 . V_8 = sizeof( T_4 ) ;
F_5 ( & V_4 ) ;
if ( V_4 . V_9 >= 5 ) {
V_2 = sizeof( V_11 ) ;
} else {
V_2 = V_12 ;
}
#else
V_2 = sizeof( V_11 ) + 12 ;
#endif
V_16 = F_12 ( V_2 ) ;
V_16 -> V_23 = V_2 ;
V_16 -> V_24 = V_13 ;
V_16 -> V_25 = ( V_26 ) F_13 ( V_13 , V_27 ) ;
V_16 -> V_28 = F_7 ( L_14 ) ;
V_16 -> V_29 = NULL ;
V_16 -> V_30 = 0 ;
V_16 -> V_31 = 1 ;
V_16 -> V_33 = V_17 ;
V_16 -> V_34 = V_18 ;
V_16 -> V_35 = NULL ;
V_16 -> V_36 = 0 ;
V_16 -> V_41 = F_9 ( F_15 () ) ;
V_16 -> V_42 = F_7 ( L_15 ) ;
V_16 -> V_43 = V_44 | V_45 | V_46 |
V_47 | V_83 | V_49 |
V_84 | V_50 ;
V_16 -> V_52 = NULL ;
V_16 -> V_53 = V_89 ;
V_16 -> V_55 = F_7 ( L_16 ) ;
V_80 = F_27 ( V_16 ) ;
if ( V_80 ) {
F_17 ( V_14 , L_4 , F_18 ( V_17 ) ) ;
* V_59 = V_16 -> V_31 - 1 ;
}
V_88 = NULL ;
F_11 ( ( void * ) V_16 ) ;
return V_80 ;
}
T_1
F_33 ( T_5 V_13 , T_9 * V_58 ,
T_6 * V_14 ,
int * V_59 ,
T_1 * V_76 ,
T_13 * V_90 ) {
T_12 * V_79 ;
V_11 * V_16 ;
T_7 V_17 [ V_18 ] = F_7 ( L_1 ) ;
int V_2 ;
T_1 V_80 ;
if ( ! V_14 || ! V_59 || ! V_76 || ! V_90 )
return FALSE ;
if ( V_14 -> V_20 > 0 ) {
F_8 ( V_17 , V_18 , F_9 ( V_14 -> V_21 ) ) ;
}
V_79 = F_25 ( V_58 -> V_62 ,
V_58 -> V_64 , 0 ) ;
if ( V_79 == NULL )
return FALSE ;
V_91 = V_90 ;
V_92 = V_58 ;
V_82 = FALSE ;
V_2 = F_1 () ;
V_16 = F_12 ( V_2 ) ;
V_16 -> V_23 = V_2 ;
V_16 -> V_24 = V_13 ;
V_16 -> V_25 = ( V_26 ) F_13 ( V_13 , V_27 ) ;
V_16 -> V_28 = F_26 ( V_79 ) ;
V_16 -> V_29 = NULL ;
V_16 -> V_30 = 0 ;
V_16 -> V_31 = 1 ;
V_16 -> V_33 = V_17 ;
V_16 -> V_34 = V_18 ;
V_16 -> V_35 = NULL ;
V_16 -> V_36 = 0 ;
V_16 -> V_41 = F_9 ( F_15 () ) ;
V_16 -> V_42 = F_7 ( L_17 ) ;
V_16 -> V_43 = V_44 | V_45 | V_46 |
V_47 | V_83 | V_49 |
V_84 | V_50 | V_51 ;
V_16 -> V_52 = NULL ;
V_16 -> V_85 = ( V_86 ) V_58 ;
V_16 -> V_53 = V_93 ;
V_16 -> V_55 = F_7 ( L_18 ) ;
V_80 = F_27 ( V_16 ) ;
if ( V_80 ) {
F_17 ( V_14 , L_4 , F_18 ( V_17 ) ) ;
* V_59 = F_28 ( V_79 , int , V_16 -> V_31 - 1 ) ;
* V_76 = V_82 ;
} else {
if ( F_29 () != 0 ) {
F_30 ( V_14 , 0 ) ;
V_80 = TRUE ;
}
}
V_88 = NULL ;
V_91 = NULL ;
V_92 = NULL ;
F_31 ( V_79 , TRUE ) ;
F_11 ( ( void * ) V_16 -> V_28 ) ;
F_11 ( ( void * ) V_16 ) ;
return V_80 ;
}
T_1
F_34 ( T_5 V_13 , T_6 * V_14 , T_6 * V_15 , int * V_94 ) {
V_11 * V_16 ;
T_7 V_17 [ V_18 ] = F_7 ( L_1 ) ;
int V_2 ;
T_1 V_19 ;
if ( ! V_14 || ! V_15 || ! V_94 )
return FALSE ;
if ( V_14 -> V_20 > 0 ) {
F_8 ( V_17 , V_18 , F_9 ( V_14 -> V_21 ) ) ;
}
if ( V_15 -> V_20 > 0 ) {
V_22 = F_10 ( V_15 -> V_21 ) ;
} else if ( V_22 ) {
F_11 ( V_22 ) ;
V_22 = NULL ;
}
V_2 = F_1 () ;
V_16 = F_12 ( V_2 ) ;
V_16 -> V_23 = V_2 ;
V_16 -> V_24 = V_13 ;
V_16 -> V_25 = ( V_26 ) F_13 ( V_13 , V_27 ) ;
V_16 -> V_28 = F_14 () ;
V_16 -> V_29 = NULL ;
V_16 -> V_30 = 0 ;
V_16 -> V_31 = V_95 ;
V_16 -> V_33 = V_17 ;
V_16 -> V_34 = V_18 ;
V_16 -> V_35 = NULL ;
V_16 -> V_36 = 0 ;
if ( V_37 . V_38 == V_39 && V_37 . V_40 [ 0 ] != '\0' ) {
V_16 -> V_41 = F_9 ( V_37 . V_40 ) ;
} else {
V_16 -> V_41 = F_9 ( F_15 () ) ;
}
V_16 -> V_42 = F_7 ( L_19 ) ;
V_16 -> V_43 = V_44 | V_45 | V_46 |
V_47 | V_48 | V_49 |
V_50 | V_51 ;
V_16 -> V_52 = NULL ;
V_16 -> V_53 = V_96 ;
V_16 -> V_55 = F_7 ( L_20 ) ;
V_19 = F_16 ( V_16 ) ;
if ( V_19 ) {
F_17 ( V_14 , L_4 , F_18 ( V_17 ) ) ;
F_17 ( V_15 , L_4 , V_22 ? V_22 : L_1 ) ;
switch ( V_97 ) {
case V_98 :
* V_94 = 1 ;
break;
case V_99 :
* V_94 = 0 ;
break;
case V_100 :
* V_94 = - 1 ;
break;
default:
F_35 () ;
}
}
F_11 ( ( void * ) V_16 -> V_28 ) ;
F_11 ( ( void * ) V_16 ) ;
F_11 ( V_22 ) ;
V_22 = NULL ;
return V_19 ;
}
void
F_36 ( T_5 V_13 , T_9 * V_58 , T_14 V_101 ) {
V_11 * V_16 ;
T_7 V_14 [ V_18 ] = F_7 ( L_1 ) ;
char * V_102 ;
T_15 V_103 ;
int V_2 ;
V_92 = V_58 ;
V_2 = F_1 () ;
V_16 = F_12 ( V_2 ) ;
V_16 -> V_23 = V_2 ;
V_16 -> V_24 = V_13 ;
V_16 -> V_25 = ( V_26 ) F_13 ( V_13 , V_27 ) ;
V_16 -> V_28 = V_104 ;
V_16 -> V_29 = NULL ;
V_16 -> V_30 = 0 ;
V_16 -> V_31 = V_101 ;
V_16 -> V_33 = V_14 ;
V_16 -> V_34 = V_18 ;
V_16 -> V_35 = NULL ;
V_16 -> V_36 = 0 ;
V_16 -> V_41 = F_9 ( F_15 () ) ;
V_16 -> V_42 = F_7 ( L_21 ) ;
V_16 -> V_43 = V_44 | V_45 | V_46 |
V_47 | V_83 | V_49 |
V_84 | V_50 | V_51 ;
V_16 -> V_52 = NULL ;
V_16 -> V_85 = ( V_86 ) V_58 ;
V_16 -> V_53 = V_105 ;
V_16 -> V_55 = F_7 ( L_22 ) ;
V_106 . V_107 = V_108 ;
V_106 . V_109 = TRUE ;
V_106 . V_110 = NULL ;
V_106 . V_111 = TRUE ;
V_106 . V_112 = TRUE ;
V_106 . V_113 = V_114 ;
V_106 . V_115 = FALSE ;
V_106 . V_116 = FALSE ;
if ( F_27 ( V_16 ) ) {
V_106 . V_117 = F_18 ( V_14 ) ;
switch ( V_16 -> V_31 ) {
case V_118 :
V_106 . V_119 = F_37 ( TRUE , V_106 . V_117 ) ;
if ( V_106 . V_119 == NULL ) {
F_38 ( V_106 . V_117 , V_120 , TRUE ) ;
F_11 ( ( void * ) V_16 ) ;
return;
}
V_103 = F_39 ( V_58 , & V_106 ) ;
break;
case V_121 :
V_106 . V_119 = F_40 ( TRUE , V_106 . V_117 ) ;
if ( V_106 . V_119 == NULL ) {
F_38 ( V_106 . V_117 , V_120 , TRUE ) ;
F_11 ( ( void * ) V_16 ) ;
return;
}
V_103 = F_39 ( V_58 , & V_106 ) ;
break;
case V_122 :
V_103 = F_41 ( V_58 , & V_106 ) ;
break;
case V_123 :
V_103 = F_42 ( V_58 , & V_106 ) ;
break;
case V_124 :
V_103 = F_43 ( V_58 , & V_106 ) ;
break;
case V_125 :
V_103 = F_44 ( V_58 , & V_106 ) ;
break;
default:
F_11 ( ( void * ) V_16 ) ;
return;
}
switch ( V_103 ) {
case V_126 :
break;
case V_127 :
F_38 ( V_106 . V_117 , V_120 , TRUE ) ;
break;
case V_128 :
F_45 ( V_106 . V_117 , V_120 ) ;
break;
}
V_102 = F_46 ( F_18 ( V_14 ) ) ;
F_47 ( V_102 ) ;
}
V_92 = NULL ;
F_11 ( ( void * ) V_16 ) ;
}
void
F_48 ( T_5 V_13 , T_9 * V_58 ) {
V_11 * V_16 ;
T_7 V_14 [ V_18 ] = F_7 ( L_1 ) ;
char * V_102 ;
const T_16 * V_129 ;
char * V_130 ;
int V_131 ;
int V_2 ;
if ( ! V_58 -> V_132 ) {
F_49 ( V_133 , V_134 , L_23 ) ;
return;
}
V_2 = F_1 () ;
V_16 = F_12 ( V_2 ) ;
V_16 -> V_23 = V_2 ;
V_16 -> V_24 = V_13 ;
V_16 -> V_25 = ( V_26 ) F_13 ( V_13 , V_27 ) ;
V_16 -> V_28 = V_135 ;
V_16 -> V_29 = NULL ;
V_16 -> V_30 = 0 ;
V_16 -> V_31 = V_136 ;
V_16 -> V_33 = V_14 ;
V_16 -> V_34 = V_18 ;
V_16 -> V_35 = NULL ;
V_16 -> V_36 = 0 ;
V_16 -> V_41 = F_9 ( F_15 () ) ;
V_16 -> V_42 = F_7 ( L_24 ) ;
V_16 -> V_43 = V_44 | V_45 | V_46 |
V_47 | V_83 | V_49 |
V_84 | V_50 | V_51 ;
V_16 -> V_52 = NULL ;
V_16 -> V_85 = V_58 -> V_132 -> V_137 ;
V_16 -> V_53 = V_138 ;
V_16 -> V_55 = F_7 ( L_25 ) ;
if ( F_27 ( V_16 ) ) {
F_11 ( ( void * ) V_16 ) ;
V_130 = F_18 ( V_14 ) ;
V_129 = F_50 ( V_58 -> V_132 -> V_139 , 0 , - 1 ) +
V_58 -> V_132 -> V_140 ;
V_131 = F_51 ( V_130 , V_141 | V_142 | V_143 | V_144 , 0666 ) ;
if ( V_131 == - 1 ) {
F_38 ( V_130 , V_120 , TRUE ) ;
return;
}
if ( F_52 ( V_131 , V_129 , V_58 -> V_132 -> V_137 ) < 0 ) {
F_45 ( V_130 , V_120 ) ;
F_53 ( V_131 ) ;
return;
}
if ( F_53 ( V_131 ) < 0 ) {
F_45 ( V_130 , V_120 ) ;
return;
}
V_102 = F_46 ( V_130 ) ;
F_47 ( V_102 ) ;
} else {
F_11 ( ( void * ) V_16 ) ;
}
}
void
F_54 ( T_5 V_13 ) {
V_11 * V_16 ;
T_7 V_14 [ V_18 ] = F_7 ( L_1 ) ;
char * V_102 ;
T_17 * V_145 = NULL ;
char * V_130 ;
int V_131 ;
int V_2 ;
int V_146 ;
V_146 = F_55 () ;
if ( V_146 == 0 ) {
F_49 ( V_133 , V_134 , L_26 ) ;
return;
}
V_2 = F_1 () ;
V_16 = F_12 ( V_2 ) ;
V_16 -> V_23 = V_2 ;
V_16 -> V_24 = V_13 ;
V_16 -> V_25 = ( V_26 ) F_13 ( V_13 , V_27 ) ;
V_16 -> V_28 = V_147 ;
V_16 -> V_29 = NULL ;
V_16 -> V_30 = 0 ;
V_16 -> V_31 = V_148 ;
V_16 -> V_33 = V_14 ;
V_16 -> V_34 = V_18 ;
V_16 -> V_35 = NULL ;
V_16 -> V_36 = 0 ;
V_16 -> V_41 = F_9 ( F_15 () ) ;
V_16 -> V_42 = F_7 ( L_27 ) ;
V_16 -> V_43 = V_44 | V_45 | V_46 |
V_47 | V_83 | V_49 |
V_84 | V_50 | V_51 ;
V_16 -> V_52 = NULL ;
V_16 -> V_85 = V_146 ;
V_16 -> V_53 = V_149 ;
V_16 -> V_55 = F_7 ( L_28 ) ;
if ( F_27 ( V_16 ) ) {
F_11 ( ( void * ) V_16 ) ;
V_130 = F_18 ( V_14 ) ;
V_145 = F_56 () ;
V_131 = F_51 ( V_130 , V_141 | V_142 | V_143 | V_144 , 0666 ) ;
if ( V_131 == - 1 ) {
F_38 ( V_130 , V_120 , TRUE ) ;
F_11 ( V_145 ) ;
return;
}
if ( F_57 ( V_131 , V_145 , ( unsigned int ) strlen ( V_145 ) ) < 0 ) {
F_45 ( V_130 , V_120 ) ;
F_58 ( V_131 ) ;
F_11 ( V_145 ) ;
return;
}
if ( F_58 ( V_131 ) < 0 ) {
F_45 ( V_130 , V_120 ) ;
F_11 ( V_145 ) ;
return;
}
V_102 = F_46 ( V_130 ) ;
F_47 ( V_102 ) ;
} else {
F_11 ( ( void * ) V_16 ) ;
}
F_11 ( V_145 ) ;
}
void
F_59 ( T_5 V_13 , T_9 * V_58 , T_18 V_150 ) {
V_11 * V_16 ;
T_7 V_14 [ V_18 ] = F_7 ( L_1 ) ;
T_17 * V_102 ;
int V_2 ;
V_2 = F_1 () ;
V_16 = F_12 ( V_2 ) ;
V_16 -> V_23 = V_2 ;
V_16 -> V_24 = V_13 ;
V_16 -> V_25 = ( V_26 ) F_13 ( V_13 , V_27 ) ;
V_16 -> V_28 = V_151 ;
V_16 -> V_29 = NULL ;
V_16 -> V_30 = 0 ;
V_16 -> V_31 = V_152 ;
V_16 -> V_33 = V_14 ;
V_16 -> V_34 = V_18 ;
V_16 -> V_35 = NULL ;
V_16 -> V_36 = 0 ;
V_16 -> V_41 = F_9 ( F_15 () ) ;
V_16 -> V_42 = F_7 ( L_29 ) ;
V_16 -> V_43 = V_44 | V_46 |
V_47 | V_83 | V_49 |
V_84 | V_50 ;
V_16 -> V_52 = NULL ;
V_16 -> V_53 = NULL ;
V_16 -> V_55 = NULL ;
V_153 = V_58 -> V_62 ;
if ( F_27 ( V_16 ) ) {
F_11 ( ( void * ) V_16 ) ;
if ( ! F_60 ( F_18 ( V_14 ) , V_150 , FALSE ) )
return;
V_102 = F_46 ( F_18 ( V_14 ) ) ;
F_47 ( V_102 ) ;
} else {
F_11 ( ( void * ) V_16 ) ;
}
}
void
F_61 ( T_5 V_13 , T_18 V_154 ) {
V_11 * V_16 ;
T_7 V_14 [ V_18 ] = F_7 ( L_1 ) ;
T_17 * V_102 ;
int V_2 ;
V_2 = F_1 () ;
V_16 = F_12 ( V_2 ) ;
V_16 -> V_23 = V_2 ;
V_16 -> V_24 = V_13 ;
V_16 -> V_25 = ( V_26 ) F_13 ( V_13 , V_27 ) ;
V_16 -> V_28 = V_151 ;
V_16 -> V_29 = NULL ;
V_16 -> V_30 = 0 ;
V_16 -> V_31 = V_152 ;
V_16 -> V_33 = V_14 ;
V_16 -> V_34 = V_18 ;
V_16 -> V_35 = NULL ;
V_16 -> V_36 = 0 ;
V_16 -> V_41 = F_9 ( F_15 () ) ;
V_16 -> V_42 = F_7 ( L_30 ) ;
V_16 -> V_43 = V_44 | V_46 |
V_47 | V_83 | V_49 |
V_84 | V_50 ;
V_16 -> V_52 = NULL ;
V_16 -> V_53 = NULL ;
V_16 -> V_55 = NULL ;
if ( F_16 ( V_16 ) ) {
F_11 ( ( void * ) V_16 ) ;
if ( ! F_62 ( F_18 ( V_14 ) , V_154 ) )
return;
V_102 = F_46 ( F_18 ( V_14 ) ) ;
F_47 ( V_102 ) ;
} else {
F_11 ( ( void * ) V_16 ) ;
}
}
static void
F_63 ( T_5 V_155 , T_19 * args ) {
T_5 V_156 ;
V_156 = F_64 ( V_155 , V_157 ) ;
if ( F_65 ( V_156 , V_158 , 0 , 0 ) == V_159 ) {
args -> V_111 = TRUE ;
V_156 = F_64 ( V_155 , V_160 ) ;
F_66 ( V_156 , TRUE ) ;
if ( F_65 ( V_156 , V_158 , 0 , 0 ) == V_159 )
args -> V_112 = TRUE ;
else
args -> V_112 = FALSE ;
} else {
args -> V_111 = FALSE ;
args -> V_112 = FALSE ;
V_156 = F_64 ( V_155 , V_160 ) ;
F_66 ( V_156 , FALSE ) ;
}
V_156 = F_64 ( V_155 , V_161 ) ;
if ( F_65 ( V_156 , V_158 , 0 , 0 ) == V_159 ) {
V_156 = F_64 ( V_155 , V_162 ) ;
switch ( F_65 ( V_156 , V_163 , 0 , 0 ) ) {
case 0 :
args -> V_113 = V_164 ;
break;
case 1 :
args -> V_113 = V_114 ;
break;
case 2 :
args -> V_113 = V_165 ;
break;
default:
F_35 () ;
}
F_66 ( V_156 , TRUE ) ;
} else {
args -> V_113 = V_166 ;
V_156 = F_64 ( V_155 , V_162 ) ;
F_66 ( V_156 , FALSE ) ;
}
V_156 = F_64 ( V_155 , V_167 ) ;
if ( F_65 ( V_156 , V_158 , 0 , 0 ) == V_159 )
args -> V_115 = TRUE ;
else
args -> V_115 = FALSE ;
V_156 = F_64 ( V_155 , V_168 ) ;
if ( F_65 ( V_156 , V_158 , 0 , 0 ) == V_159 )
args -> V_116 = TRUE ;
else
args -> V_116 = FALSE ;
}
static void
F_67 ( T_5 V_155 , T_19 * args ) {
T_5 V_156 ;
V_156 = F_64 ( V_155 , V_157 ) ;
F_65 ( V_156 , V_169 , args -> V_111 , 0 ) ;
V_156 = F_64 ( V_155 , V_160 ) ;
F_65 ( V_156 , V_169 , args -> V_112 , 0 ) ;
V_156 = F_64 ( V_155 , V_161 ) ;
F_65 ( V_156 , V_169 , args -> V_113 != V_166 , 0 ) ;
V_156 = F_64 ( V_155 , V_162 ) ;
F_65 ( V_156 , V_170 , 0 , ( V_171 ) F_7 ( L_31 ) ) ;
F_65 ( V_156 , V_170 , 0 , ( V_171 ) F_7 ( L_32 ) ) ;
F_65 ( V_156 , V_170 , 0 , ( V_171 ) F_7 ( L_33 ) ) ;
switch ( args -> V_113 ) {
case V_166 :
case V_164 :
F_65 ( V_156 , V_172 , 0 , 0 ) ;
break;
case V_114 :
F_65 ( V_156 , V_172 , 1 , 0 ) ;
break;
case V_165 :
F_65 ( V_156 , V_172 , 2 , 0 ) ;
default:
F_35 () ;
}
V_156 = F_64 ( V_155 , V_167 ) ;
F_65 ( V_156 , V_169 , args -> V_115 , 0 ) ;
V_156 = F_64 ( V_155 , V_168 ) ;
F_65 ( V_156 , V_169 , args -> V_116 , 0 ) ;
F_63 ( V_155 , args ) ;
}
static T_1
F_68 ( T_5 V_173 , T_17 * V_174 ) {
T_5 V_156 ;
int V_175 ;
T_1 V_176 = FALSE ;
T_20 * V_177 ;
const struct V_178 * V_179 ;
int V_180 = 0 ;
T_17 * V_181 ;
T_7 V_182 [ V_183 ] ;
T_21 V_184 ;
T_22 V_185 = 0 ;
T_21 V_186 ;
T_23 V_187 ;
struct V_188 * V_189 ;
T_22 V_190 ;
T_23 V_191 ;
T_23 V_192 ;
double V_193 = 0 ;
double V_194 = 0 ;
double V_195 ;
T_1 V_196 = FALSE ;
for ( V_175 = V_197 ; V_175 <= V_198 ; V_175 ++ ) {
V_156 = F_64 ( V_173 , V_175 ) ;
if ( V_156 ) {
F_66 ( V_156 , FALSE ) ;
}
}
for ( V_175 = V_197 ; V_175 <= V_198 ; V_175 ++ ) {
V_156 = F_64 ( V_173 , V_175 ) ;
if ( V_156 ) {
F_69 ( V_156 , F_7 ( L_34 ) ) ;
}
}
if ( V_174 == NULL || strlen ( V_174 ) < 1 ) {
return FALSE ;
}
V_156 = F_64 ( V_173 , V_197 ) ;
if ( F_70 ( V_174 ) == V_199 ) {
F_69 ( V_156 , F_7 ( L_35 ) ) ;
return FALSE ;
}
V_177 = F_71 ( V_174 , V_200 , & V_180 , & V_181 , TRUE ) ;
if ( V_156 && V_177 == NULL ) {
if( V_180 == V_201 ) {
F_69 ( V_156 , F_7 ( L_36 ) ) ;
} else {
F_69 ( V_156 , F_7 ( L_37 ) ) ;
}
return FALSE ;
}
for ( V_175 = V_202 ; V_175 <= V_198 ; V_175 ++ ) {
V_156 = F_64 ( V_173 , V_175 ) ;
if ( V_156 ) {
F_66 ( V_156 , TRUE ) ;
}
}
V_156 = F_64 ( V_173 , V_197 ) ;
F_69 ( V_156 , F_9 ( F_72 ( F_73 ( V_177 ) ) ) ) ;
V_186 = F_74 ( V_177 , & V_180 ) ;
F_75 ( V_182 , V_183 , L_38 V_203 L_39 , V_186 ) ;
V_156 = F_64 ( V_173 , V_204 ) ;
F_69 ( V_156 , V_182 ) ;
time ( & V_191 ) ;
while ( ( F_76 ( V_177 , & V_180 , & V_181 , & V_184 ) ) ) {
V_179 = F_77 ( V_177 ) ;
V_195 = F_78 ( ( const V_205 * ) & V_179 -> V_206 ) ;
if( V_185 == 0 ) {
V_193 = V_195 ;
V_194 = V_195 ;
}
if ( V_195 < V_193 ) {
V_193 = V_195 ;
}
if ( V_195 > V_194 ) {
V_194 = V_195 ;
}
V_185 ++ ;
if( V_185 % 100 == 0 ) {
time ( & V_192 ) ;
if( V_192 - V_191 >= ( T_23 ) V_37 . V_207 ) {
V_196 = TRUE ;
break;
}
}
}
if( V_180 != 0 ) {
F_79 ( V_182 , V_183 , F_7 ( L_40 ) , V_185 ) ;
V_156 = F_64 ( V_173 , V_208 ) ;
F_69 ( V_156 , V_182 ) ;
F_80 ( V_177 ) ;
return TRUE ;
}
if( V_196 ) {
F_79 ( V_182 , V_183 , F_7 ( L_41 ) , V_185 ) ;
} else {
F_79 ( V_182 , V_183 , F_7 ( L_42 ) , V_185 ) ;
}
V_156 = F_64 ( V_173 , V_208 ) ;
F_69 ( V_156 , V_182 ) ;
V_187 = ( long ) V_193 ;
V_189 = localtime ( & V_187 ) ;
if( V_189 ) {
F_79 ( V_182 , V_183 ,
F_7 ( L_43 ) ,
V_189 -> V_209 + 1900 ,
V_189 -> V_210 + 1 ,
V_189 -> V_211 ,
V_189 -> V_212 ,
V_189 -> V_213 ,
V_189 -> V_214 ) ;
} else {
F_79 ( V_182 , V_183 , F_7 ( L_44 ) ) ;
}
V_156 = F_64 ( V_173 , V_215 ) ;
F_69 ( V_156 , V_182 ) ;
V_190 = ( unsigned int ) ( V_194 - V_193 ) ;
if( V_190 / 86400 ) {
F_79 ( V_182 , V_183 , F_7 ( L_45 ) ,
V_190 / 86400 , V_190 % 86400 / 3600 , V_190 % 3600 / 60 , V_190 % 60 ) ;
} else {
F_79 ( V_182 , V_183 , F_7 ( L_46 ) ,
V_190 % 86400 / 3600 , V_190 % 3600 / 60 , V_190 % 60 ) ;
}
if( V_196 ) {
F_79 ( V_182 , V_183 , F_7 ( L_47 ) ) ;
}
V_156 = F_64 ( V_173 , V_198 ) ;
F_69 ( V_156 , V_182 ) ;
F_80 ( V_177 ) ;
return TRUE ;
}
static char *
F_81 ( T_5 V_216 ) {
T_7 * V_217 = NULL ;
T_11 V_20 ;
char * V_218 ;
V_20 = F_82 ( V_216 ) ;
if ( V_20 > 0 ) {
V_20 ++ ;
V_217 = F_83 ( V_20 * sizeof( T_7 ) ) ;
V_20 = F_84 ( V_216 , V_217 , V_20 ) ;
V_218 = F_85 ( V_217 , - 1 , NULL , NULL , NULL ) ;
F_11 ( V_217 ) ;
return V_218 ;
} else {
return NULL ;
}
}
static void
F_86 ( T_5 V_216 , T_7 * V_219 ) {
T_7 * V_217 = NULL ;
T_11 V_20 ;
T_24 * V_220 ;
if ( V_219 ) {
V_20 = ( F_87 ( V_219 ) + 1 ) * sizeof( T_7 ) ;
V_217 = F_83 ( V_20 ) ;
memcpy ( V_217 , V_219 , V_20 ) ;
} else {
V_20 = F_82 ( V_216 ) ;
if ( V_20 > 0 ) {
V_20 ++ ;
V_217 = F_83 ( V_20 * sizeof( T_7 ) ) ;
V_20 = F_84 ( V_216 , V_217 , V_20 ) ;
}
}
if ( V_20 == 0 ) {
F_65 ( V_216 , V_221 , ( V_171 ) 1 , V_222 ) ;
return;
} else if ( F_88 ( F_18 ( V_217 ) , & V_220 ) ) {
if ( V_220 != NULL )
F_89 ( V_220 ) ;
F_65 ( V_216 , V_221 , 0 , F_90 ( 0xe4 , 0xff , 0xc7 ) ) ;
} else {
F_65 ( V_216 , V_221 , 0 , F_90 ( 0xff , 0xcc , 0xcc ) ) ;
}
if ( V_217 ) F_11 ( V_217 ) ;
}
static T_25 T_26
V_54 ( T_5 V_173 , T_27 V_223 , V_171 V_224 , V_86 V_225 ) {
T_5 V_156 , V_57 ;
T_28 * V_226 = ( T_28 * ) V_225 ;
T_7 V_227 [ V_18 ] ;
T_11 V_175 ;
switch( V_223 ) {
case V_228 :
if( V_22 != NULL ) {
V_156 = F_64 ( V_173 , V_229 ) ;
F_69 ( V_156 , F_9 ( V_22 ) ) ;
}
V_156 = F_64 ( V_173 , V_230 ) ;
F_65 ( V_156 , V_170 , 0 , ( V_171 ) F_7 ( L_48 ) ) ;
for ( V_175 = 0 ; V_231 [ V_175 ] . V_232 != NULL ; V_175 += 1 ) {
F_65 ( V_156 , V_170 , 0 , ( V_171 ) F_9 ( V_231 [ V_175 ] . V_232 ) ) ;
}
F_65 ( V_156 , V_172 , 0 , 0 ) ;
V_156 = F_64 ( V_173 , V_233 ) ;
F_65 ( V_156 , V_169 , V_234 . V_235 , 0 ) ;
V_156 = F_64 ( V_173 , V_236 ) ;
F_65 ( V_156 , V_169 , V_234 . V_237 , 0 ) ;
V_156 = F_64 ( V_173 , V_238 ) ;
F_65 ( V_156 , V_169 , V_234 . V_239 , 0 ) ;
V_156 = F_64 ( V_173 , V_240 ) ;
F_65 ( V_156 , V_169 , V_234 . V_241 , 0 ) ;
F_68 ( V_173 , NULL ) ;
break;
case V_242 :
switch ( V_226 -> V_243 . V_244 ) {
case V_245 :
V_156 = F_64 ( V_173 , V_229 ) ;
if ( V_22 )
F_11 ( V_22 ) ;
V_22 = F_81 ( V_156 ) ;
V_156 = F_64 ( V_173 , V_230 ) ;
V_56 = ( unsigned int ) F_65 ( V_156 , V_163 , 0 , 0 ) ;
V_156 = F_64 ( V_173 , V_233 ) ;
if ( F_65 ( V_156 , V_158 , 0 , 0 ) == V_159 )
V_234 . V_235 = TRUE ;
V_156 = F_64 ( V_173 , V_236 ) ;
if ( F_65 ( V_156 , V_158 , 0 , 0 ) == V_159 )
V_234 . V_237 = TRUE ;
V_156 = F_64 ( V_173 , V_238 ) ;
if ( F_65 ( V_156 , V_158 , 0 , 0 ) == V_159 )
V_234 . V_239 = TRUE ;
V_156 = F_64 ( V_173 , V_240 ) ;
if ( F_65 ( V_156 , V_158 , 0 , 0 ) == V_159 )
V_234 . V_241 = TRUE ;
break;
case V_246 :
V_57 = F_91 ( V_173 ) ;
F_92 ( V_57 , V_227 , V_18 ) ;
F_68 ( V_173 , F_18 ( V_227 ) ) ;
break;
case V_247 :
F_93 ( V_248 ) ;
break;
default:
break;
}
break;
case V_249 :
V_156 = ( T_5 ) V_225 ;
switch( V_224 ) {
case ( V_250 << 16 ) | V_229 :
F_86 ( V_156 , NULL ) ;
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
F_94 ( T_12 * V_251 , int V_252 )
{
T_6 * V_253 = F_95 ( L_1 ) ;
T_6 * V_254 = F_95 ( L_1 ) ;
T_17 V_255 ;
T_29 * V_256 , * V_257 ;
T_7 * V_258 ;
T_30 V_259 = 0 ;
V_256 = F_96 ( V_252 ) ;
F_17 ( V_253 , L_1 ) ;
V_255 = '\0' ;
for ( V_257 = V_256 ; V_257 != NULL ;
V_257 = F_97 ( V_257 ) ) {
if ( V_255 != '\0' )
F_98 ( V_253 , V_255 ) ;
F_99 ( V_253 , L_49 , ( char * ) V_257 -> V_260 ) ;
V_255 = ';' ;
}
F_100 ( V_256 ) ;
F_17 ( V_254 , L_50 ,
F_101 ( V_252 ) ,
V_253 -> V_21 ) ;
V_258 = F_9 ( V_254 -> V_21 ) ;
V_251 = F_102 ( V_251 , V_258 , ( T_22 ) strlen ( V_254 -> V_21 ) ) ;
V_251 = F_103 ( V_251 , V_259 ) ;
F_104 ( V_254 , TRUE ) ;
V_258 = F_9 ( V_253 -> V_21 ) ;
V_251 = F_102 ( V_251 , V_258 , ( T_22 ) strlen ( V_253 -> V_21 ) ) ;
V_251 = F_103 ( V_251 , V_259 ) ;
F_104 ( V_253 , TRUE ) ;
}
static T_7 *
F_14 ( void ) {
T_7 * V_258 ;
int V_252 ;
T_12 * V_251 ;
static const T_30 V_259 = 0 ;
T_6 * V_253 ;
T_17 V_255 ;
T_29 * V_256 , * V_257 ;
V_251 = F_105 ( FALSE , FALSE , 2 ) ;
V_258 = F_9 ( L_51 ) ;
V_251 = F_102 ( V_251 , V_258 , ( T_22 ) strlen ( L_51 ) ) ;
V_251 = F_103 ( V_251 , V_259 ) ;
V_258 = F_9 ( L_52 ) ;
V_251 = F_102 ( V_251 , V_258 , ( T_22 ) strlen ( L_52 ) ) ;
V_251 = F_103 ( V_251 , V_259 ) ;
V_258 = F_9 ( L_53 ) ;
V_251 = F_102 ( V_251 , V_258 , ( T_22 ) strlen ( L_53 ) ) ;
V_251 = F_103 ( V_251 , V_259 ) ;
V_253 = F_95 ( L_1 ) ;
V_256 = F_106 () ;
V_255 = '\0' ;
for ( V_257 = V_256 ; V_257 != NULL ;
V_257 = F_97 ( V_257 ) ) {
if ( V_255 != '\0' )
F_98 ( V_253 , V_255 ) ;
F_99 ( V_253 , L_49 , ( char * ) V_257 -> V_260 ) ;
V_255 = ';' ;
}
F_100 ( V_256 ) ;
V_258 = F_9 ( V_253 -> V_21 ) ;
V_251 = F_102 ( V_251 , V_258 , ( T_22 ) strlen ( V_253 -> V_21 ) ) ;
V_251 = F_103 ( V_251 , V_259 ) ;
for ( V_252 = 0 ; V_252 < F_107 () ; V_252 ++ ) {
F_94 ( V_251 , V_252 ) ;
}
V_251 = F_103 ( V_251 , V_259 ) ;
return ( T_7 * ) F_31 ( V_251 , FALSE ) ;
}
static void
F_108 ( T_12 * V_251 , int V_261 )
{
T_6 * V_253 = F_95 ( L_1 ) ;
T_6 * V_254 = F_95 ( L_1 ) ;
T_17 V_255 ;
T_29 * V_256 , * V_257 ;
T_7 * V_258 ;
T_30 V_259 = 0 ;
V_256 = F_109 ( V_261 , TRUE ) ;
if ( V_256 == NULL ) {
F_17 ( V_253 , L_52 ) ;
} else {
F_17 ( V_253 , L_1 ) ;
V_255 = '\0' ;
for ( V_257 = V_256 ; V_257 != NULL ;
V_257 = F_97 ( V_257 ) ) {
if ( V_255 != '\0' )
F_98 ( V_253 , V_255 ) ;
F_99 ( V_253 , L_49 , ( char * ) V_257 -> V_260 ) ;
V_255 = ';' ;
}
F_100 ( V_256 ) ;
}
F_17 ( V_254 , L_50 , F_72 ( V_261 ) ,
V_253 -> V_21 ) ;
V_258 = F_9 ( V_254 -> V_21 ) ;
V_251 = F_102 ( V_251 , V_258 , ( T_22 ) strlen ( V_254 -> V_21 ) ) ;
V_251 = F_103 ( V_251 , V_259 ) ;
F_104 ( V_254 , TRUE ) ;
V_258 = F_9 ( V_253 -> V_21 ) ;
V_251 = F_102 ( V_251 , V_258 , ( T_22 ) strlen ( V_253 -> V_21 ) ) ;
V_251 = F_103 ( V_251 , V_259 ) ;
F_104 ( V_253 , TRUE ) ;
}
static T_7 *
F_26 ( T_12 * V_79 ) {
T_22 V_175 ;
int V_261 ;
T_12 * V_251 = F_105 ( FALSE , FALSE , 2 ) ;
T_30 V_259 = 0 ;
for ( V_175 = 0 ; V_175 < V_79 -> V_20 ; V_175 ++ ) {
V_261 = F_28 ( V_79 , int , V_175 ) ;
F_108 ( V_251 , V_261 ) ;
}
V_251 = F_103 ( V_251 , V_259 ) ;
return ( T_7 * ) F_31 ( V_251 , FALSE ) ;
}
static T_25 T_26
V_87 ( T_5 V_262 , T_27 V_223 , V_171 V_224 , V_86 V_225 ) {
T_5 V_156 ;
T_28 * V_226 = ( T_28 * ) V_225 ;
switch( V_223 ) {
case V_228 : {
V_11 * V_263 = ( V_11 * ) V_225 ;
T_9 * V_58 = ( T_9 * ) V_263 -> V_85 ;
V_88 = V_262 ;
V_153 = V_58 -> V_62 ;
V_156 = F_64 ( V_262 , V_264 ) ;
F_65 ( V_156 , V_169 , V_82 , 0 ) ;
break;
}
case V_249 :
V_156 = ( T_5 ) V_225 ;
switch ( V_224 ) {
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
case V_242 :
switch ( V_226 -> V_243 . V_244 ) {
case V_247 :
F_93 ( V_265 ) ;
break;
case V_245 : {
T_5 V_57 ;
char * V_130 ;
V_11 * V_263 = ( V_11 * ) V_226 -> V_266 ;
T_9 * V_58 = ( T_9 * ) V_263 -> V_85 ;
V_156 = F_64 ( V_262 , V_264 ) ;
if ( F_65 ( V_156 , V_158 , 0 , 0 ) == V_159 )
V_82 = TRUE ;
else
V_82 = FALSE ;
V_57 = F_91 ( V_262 ) ;
V_130 = F_18 ( V_226 -> V_266 -> V_33 ) ;
if ( F_110 ( V_58 -> V_267 , V_130 ) ) {
T_17 * V_21 = F_111 (
L_54
L_55 ,
V_130 ) ;
F_23 ( V_57 , F_9 ( V_21 ) , F_7 ( L_56 ) , V_268 | V_269 | V_270 ) ;
F_11 ( V_21 ) ;
F_112 ( V_262 , V_271 , 1L ) ;
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
static T_25 T_26
V_89 ( T_5 V_262 , T_27 V_223 , V_171 V_224 , V_86 V_225 ) {
switch( V_223 ) {
case V_228 :
V_88 = V_262 ;
break;
case V_249 :
break;
case V_242 :
break;
default:
break;
}
return 0 ;
}
static T_25 T_26
V_93 ( T_5 V_262 , T_27 V_223 , V_171 V_224 , V_86 V_225 ) {
T_5 V_156 ;
T_28 * V_226 = ( T_28 * ) V_225 ;
switch( V_223 ) {
case V_228 : {
V_88 = V_262 ;
V_153 = V_92 -> V_62 ;
F_113 ( V_262 , V_91 ) ;
V_156 = F_64 ( V_262 , V_264 ) ;
F_65 ( V_156 , V_169 , V_82 , 0 ) ;
break;
}
case V_249 :
V_156 = ( T_5 ) V_225 ;
switch ( V_224 ) {
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
F_114 ( V_262 , V_156 , V_224 , V_91 ) ;
break;
}
break;
case V_242 :
switch ( V_226 -> V_243 . V_244 ) {
case V_247 :
F_93 ( V_265 ) ;
break;
case V_245 : {
T_5 V_57 ;
char * V_130 ;
V_11 * V_263 = ( V_11 * ) V_226 -> V_266 ;
T_9 * V_58 = ( T_9 * ) V_263 -> V_85 ;
V_156 = F_64 ( V_262 , V_264 ) ;
if ( F_65 ( V_156 , V_158 , 0 , 0 ) == V_159 )
V_82 = TRUE ;
else
V_82 = FALSE ;
V_57 = F_91 ( V_262 ) ;
V_130 = F_18 ( V_226 -> V_266 -> V_33 ) ;
if ( F_110 ( V_58 -> V_267 , V_130 ) ) {
T_17 * V_21 = F_111 (
L_54
L_55 ,
V_130 ) ;
F_23 ( V_57 , F_9 ( V_21 ) , F_7 ( L_56 ) , V_268 | V_269 | V_270 ) ;
F_11 ( V_21 ) ;
F_112 ( V_262 , V_271 , 1L ) ;
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
F_115 ( T_5 V_155 , T_13 * V_90 ) {
T_5 V_156 ;
T_1 V_272 = FALSE ;
T_7 V_273 [ V_274 ] ;
T_11 V_275 ;
T_10 V_276 = 0 , V_277 = 0 ;
T_10 V_278 ;
T_1 V_279 = TRUE ;
V_156 = F_64 ( V_155 , V_280 ) ;
if ( F_65 ( V_156 , V_158 , 0 , 0 ) == V_159 )
V_272 = TRUE ;
V_156 = F_64 ( V_155 , V_281 ) ;
F_66 ( V_156 , ! V_272 ) ;
if ( V_90 -> V_282 ) {
F_79 ( V_273 , V_274 , F_7 ( L_42 ) , V_92 -> V_283 - V_90 -> V_276 ) ;
} else {
F_79 ( V_273 , V_274 , F_7 ( L_42 ) , V_92 -> V_283 ) ;
}
F_69 ( V_156 , V_273 ) ;
V_156 = F_64 ( V_155 , V_284 ) ;
F_66 ( V_156 , V_272 ) ;
if ( V_90 -> V_285 )
V_278 = V_90 -> V_286 ;
else
V_278 = V_90 -> V_278 ;
if ( V_90 -> V_282 ) {
F_79 ( V_273 , V_274 , F_7 ( L_42 ) , V_278 - V_90 -> V_277 ) ;
} else {
F_79 ( V_273 , V_274 , F_7 ( L_42 ) , V_278 ) ;
}
F_69 ( V_156 , V_273 ) ;
V_275 = ( V_92 -> V_287 ) ? V_92 -> V_287 -> V_288 : 0 ;
V_156 = F_64 ( V_155 , V_289 ) ;
F_66 ( V_156 , V_275 && ! V_272 ) ;
if ( V_90 -> V_282 && V_92 -> V_287 && V_92 -> V_287 -> V_290 . V_291 ) {
F_79 ( V_273 , V_274 , F_7 ( L_57 ) ) ;
} else {
F_79 ( V_273 , V_274 , F_7 ( L_42 ) , V_275 ? 1 : 0 ) ;
}
F_69 ( V_156 , V_273 ) ;
V_156 = F_64 ( V_155 , V_292 ) ;
F_66 ( V_156 , V_275 && V_272 ) ;
if ( V_90 -> V_282 && V_92 -> V_287 && V_92 -> V_287 -> V_290 . V_291 ) {
F_79 ( V_273 , V_274 , F_7 ( L_57 ) ) ;
} else {
F_79 ( V_273 , V_274 , F_7 ( L_42 ) , V_275 ? 1 : 0 ) ;
}
F_69 ( V_156 , V_273 ) ;
V_156 = F_64 ( V_155 , V_293 ) ;
F_66 ( V_156 , V_92 -> V_294 ) ;
V_156 = F_64 ( V_155 , V_295 ) ;
F_66 ( V_156 , V_92 -> V_294 && ! V_272 ) ;
if ( V_90 -> V_282 ) {
F_79 ( V_273 , V_274 , F_7 ( L_42 ) , V_92 -> V_294 - V_90 -> V_296 ) ;
} else {
F_79 ( V_273 , V_274 , F_7 ( L_42 ) , V_92 -> V_294 ) ;
}
F_69 ( V_156 , V_273 ) ;
V_156 = F_64 ( V_155 , V_297 ) ;
F_66 ( V_156 , V_92 -> V_294 && V_272 ) ;
if ( V_90 -> V_282 ) {
F_79 ( V_273 , V_274 , F_7 ( L_42 ) , V_90 -> V_298 - V_90 -> V_299 ) ;
} else {
F_79 ( V_273 , V_274 , F_7 ( L_42 ) , V_90 -> V_298 ) ;
}
F_69 ( V_156 , V_273 ) ;
V_156 = F_64 ( V_155 , V_300 ) ;
F_66 ( V_156 , V_90 -> V_301 ) ;
V_156 = F_64 ( V_155 , V_302 ) ;
F_66 ( V_156 , V_90 -> V_301 && ! V_272 ) ;
if ( V_90 -> V_282 ) {
F_79 ( V_273 , V_274 , F_7 ( L_42 ) , V_90 -> V_301 - V_90 -> V_303 ) ;
} else {
F_79 ( V_273 , V_274 , F_7 ( L_42 ) , V_90 -> V_301 ) ;
}
F_69 ( V_156 , V_273 ) ;
V_156 = F_64 ( V_155 , V_304 ) ;
F_66 ( V_156 , V_90 -> V_305 && V_272 ) ;
if ( V_90 -> V_282 ) {
F_79 ( V_273 , V_274 , F_7 ( L_42 ) , V_90 -> V_305 - V_90 -> V_306 ) ;
} else {
F_79 ( V_273 , V_274 , F_7 ( L_42 ) , V_90 -> V_305 ) ;
}
F_69 ( V_156 , V_273 ) ;
switch ( F_116 ( V_90 ) ) {
case V_307 :
V_156 = F_64 ( V_155 , V_308 ) ;
F_65 ( V_156 , V_221 , ( V_171 ) 1 , V_222 ) ;
V_156 = F_64 ( V_155 , V_309 ) ;
F_66 ( V_156 , ! V_272 ) ;
if ( V_90 -> V_282 ) {
F_79 ( V_273 , V_274 , F_7 ( L_42 ) , V_90 -> V_310 - V_90 -> V_311 ) ;
} else {
F_79 ( V_273 , V_274 , F_7 ( L_42 ) , V_90 -> V_310 ) ;
}
F_69 ( V_156 , V_273 ) ;
V_156 = F_64 ( V_155 , V_312 ) ;
F_66 ( V_156 , V_272 ) ;
if ( V_90 -> V_282 ) {
F_79 ( V_273 , V_274 , F_7 ( L_42 ) , V_90 -> V_313 - V_90 -> V_314 ) ;
} else {
F_79 ( V_273 , V_274 , F_7 ( L_42 ) , V_90 -> V_313 ) ;
}
F_69 ( V_156 , V_273 ) ;
break;
case V_315 :
if ( V_90 -> V_316 == V_317 ) V_279 = FALSE ;
V_156 = F_64 ( V_155 , V_308 ) ;
F_65 ( V_156 , V_221 , 0 , F_90 ( 0xff , 0xcc , 0xcc ) ) ;
V_156 = F_64 ( V_155 , V_309 ) ;
F_69 ( V_156 , F_7 ( L_58 ) ) ;
V_156 = F_64 ( V_155 , V_312 ) ;
F_69 ( V_156 , F_7 ( L_34 ) ) ;
break;
case V_318 :
if ( V_90 -> V_316 == V_317 ) V_279 = FALSE ;
V_156 = F_64 ( V_155 , V_308 ) ;
F_65 ( V_156 , V_221 , 0 , F_90 ( 0xff , 0xcc , 0xcc ) ) ;
V_156 = F_64 ( V_155 , V_309 ) ;
F_69 ( V_156 , F_7 ( L_59 ) ) ;
V_156 = F_64 ( V_155 , V_312 ) ;
F_69 ( V_156 , F_7 ( L_34 ) ) ;
break;
default:
F_35 () ;
}
switch( V_90 -> V_316 ) {
case ( V_319 ) :
V_276 = V_90 -> V_276 ;
V_277 = V_90 -> V_277 ;
break;
case ( V_320 ) :
V_276 = ( V_92 -> V_287 && V_92 -> V_287 -> V_290 . V_291 ) ? 1 : 0 ;
V_277 = V_276 ;
break;
case ( V_321 ) :
V_276 = V_90 -> V_296 ;
V_277 = V_90 -> V_299 ;
break;
case ( V_322 ) :
V_276 = V_90 -> V_303 ;
V_277 = V_90 -> V_306 ;
break;
case ( V_317 ) :
V_276 = V_90 -> V_311 ;
V_277 = V_90 -> V_314 ;
break;
default:
F_35 () ;
}
V_156 = F_64 ( V_155 , V_323 ) ;
F_66 ( V_156 , V_276 ) ;
V_156 = F_64 ( V_155 , V_324 ) ;
F_66 ( V_156 , V_276 && ! V_272 ) ;
F_79 ( V_273 , V_274 , F_7 ( L_42 ) , V_276 ) ;
F_69 ( V_156 , V_273 ) ;
V_156 = F_64 ( V_155 , V_325 ) ;
F_66 ( V_156 , V_277 && V_272 ) ;
F_79 ( V_273 , V_274 , F_7 ( L_42 ) , V_277 ) ;
F_69 ( V_156 , V_273 ) ;
V_156 = F_64 ( F_91 ( V_155 ) , V_72 ) ;
F_66 ( V_156 , V_279 ) ;
}
static void
F_113 ( T_5 V_155 , T_13 * V_90 ) {
T_5 V_156 ;
if ( V_90 -> V_326 )
V_156 = F_64 ( V_155 , V_280 ) ;
else
V_156 = F_64 ( V_155 , V_327 ) ;
F_65 ( V_156 , V_169 , TRUE , 0 ) ;
if( V_90 -> V_328 != NULL ) {
V_156 = F_64 ( V_155 , V_308 ) ;
F_69 ( V_156 , F_9 ( F_117 ( V_90 -> V_328 ) ) ) ;
}
F_115 ( V_155 , V_90 ) ;
switch( V_90 -> V_316 ) {
case ( V_319 ) :
V_156 = F_64 ( V_155 , V_329 ) ;
break;
case ( V_320 ) :
V_156 = F_64 ( V_155 , V_330 ) ;
break;
case ( V_321 ) :
V_156 = F_64 ( V_155 , V_293 ) ;
break;
case ( V_322 ) :
V_156 = F_64 ( V_155 , V_300 ) ;
break;
case ( V_317 ) :
V_156 = F_64 ( V_155 , V_331 ) ;
break;
default:
F_35 () ;
}
F_65 ( V_156 , V_169 , TRUE , 0 ) ;
}
static void
F_114 ( T_5 V_155 , T_5 V_332 , V_171 V_224 , T_13 * V_90 ) {
T_5 V_156 ;
T_7 V_333 [ V_334 ] ;
if ( ! V_90 ) return;
switch( V_224 ) {
case ( V_335 << 16 ) | V_327 :
case ( V_335 << 16 ) | V_280 :
V_156 = F_64 ( V_155 , V_327 ) ;
if ( F_65 ( V_156 , V_158 , 0 , 0 ) == V_159 )
V_90 -> V_326 = FALSE ;
else
V_90 -> V_326 = TRUE ;
F_115 ( V_155 , V_90 ) ;
break;
case ( V_335 << 16 ) | V_329 :
if ( F_65 ( V_332 , V_158 , 0 , 0 ) == V_159 ) {
V_90 -> V_316 = V_319 ;
F_115 ( V_155 , V_90 ) ;
}
break;
case ( V_335 << 16 ) | V_330 :
if ( F_65 ( V_332 , V_158 , 0 , 0 ) == V_159 ) {
V_90 -> V_316 = V_320 ;
F_115 ( V_155 , V_90 ) ;
}
break;
case ( V_335 << 16 ) | V_293 :
if ( F_65 ( V_332 , V_158 , 0 , 0 ) == V_159 ) {
V_90 -> V_316 = V_321 ;
F_115 ( V_155 , V_90 ) ;
}
break;
case ( V_335 << 16 ) | V_300 :
if ( F_65 ( V_332 , V_158 , 0 , 0 ) == V_159 ) {
V_90 -> V_316 = V_322 ;
F_115 ( V_155 , V_90 ) ;
}
break;
case ( V_335 << 16 ) | V_331 :
if ( F_65 ( V_332 , V_158 , 0 , 0 ) == V_159 ) {
V_90 -> V_316 = V_317 ;
F_115 ( V_155 , V_90 ) ;
V_156 = F_64 ( V_155 , V_308 ) ;
F_118 ( V_156 ) ;
}
break;
case ( V_336 << 16 ) | V_308 :
V_156 = F_64 ( V_155 , V_331 ) ;
F_65 ( V_156 , V_337 , 0 , 0 ) ;
break;
case ( V_250 << 16 ) | V_308 :
F_65 ( V_332 , V_338 , ( V_171 ) V_334 , ( V_86 ) V_333 ) ;
F_119 ( V_90 , F_18 ( V_333 ) ) ;
F_115 ( V_155 , V_90 ) ;
break;
case ( V_335 << 16 ) | V_323 :
if ( F_65 ( V_332 , V_158 , 0 , 0 ) == V_159 ) {
V_90 -> V_282 = TRUE ;
} else {
V_90 -> V_282 = FALSE ;
}
F_115 ( V_155 , V_90 ) ;
break;
}
}
static T_25 T_26
V_96 ( T_5 V_339 , T_27 V_223 , V_171 V_224 , V_86 V_225 ) {
T_5 V_156 , V_57 ;
T_28 * V_226 = ( T_28 * ) V_225 ;
T_7 V_227 [ V_18 ] ;
switch( V_223 ) {
case V_228 :
if( V_22 != NULL ) {
V_156 = F_64 ( V_339 , V_229 ) ;
F_69 ( V_156 , F_9 ( V_22 ) ) ;
}
V_156 = F_64 ( V_339 , V_340 ) ;
F_65 ( V_156 , V_169 , TRUE , 0 ) ;
V_97 = V_98 ;
F_68 ( V_339 , NULL ) ;
break;
case V_242 :
switch ( V_226 -> V_243 . V_244 ) {
case V_245 :
V_156 = F_64 ( V_339 , V_229 ) ;
if ( V_22 )
F_11 ( V_22 ) ;
V_22 = F_81 ( V_156 ) ;
V_156 = F_64 ( V_339 , V_340 ) ;
if( F_65 ( V_156 , V_158 , 0 , 0 ) == V_159 ) {
V_97 = V_99 ;
} else {
V_156 = F_64 ( V_339 , V_341 ) ;
if( F_65 ( V_156 , V_158 , 0 , 0 ) == V_159 ) {
V_97 = V_100 ;
}
}
break;
case V_246 :
V_57 = F_91 ( V_339 ) ;
F_92 ( V_57 , V_227 , V_18 ) ;
F_68 ( V_339 , F_18 ( V_227 ) ) ;
break;
case V_247 :
F_93 ( V_342 ) ;
break;
default:
break;
}
break;
case V_249 :
V_156 = ( T_5 ) V_225 ;
switch( V_224 ) {
case ( V_250 << 16 ) | V_229 :
F_86 ( V_156 , NULL ) ;
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
static T_25 T_26
V_105 ( T_5 V_343 , T_27 V_223 , V_171 V_224 , V_86 V_225 ) {
T_5 V_156 ;
T_28 * V_226 = ( T_28 * ) V_225 ;
T_1 V_344 ;
int V_175 , V_345 ;
switch( V_223 ) {
case V_228 : {
V_11 * V_263 = ( V_11 * ) V_225 ;
T_9 * V_58 = ( T_9 * ) V_263 -> V_85 ;
F_120 ( & V_106 . V_90 , V_58 ) ;
V_106 . V_90 . V_326 = TRUE ;
F_113 ( V_343 , & V_106 . V_90 ) ;
F_67 ( V_343 , & V_106 ) ;
break;
}
case V_249 :
V_156 = ( T_5 ) V_225 ;
switch ( V_224 ) {
case ( V_346 << 16 ) | V_162 :
default:
F_114 ( V_343 , V_156 , V_224 , & V_106 . V_90 ) ;
F_63 ( V_343 , & V_106 ) ;
break;
}
break;
case V_242 :
switch ( V_226 -> V_243 . V_244 ) {
case V_245 :
break;
case V_347 :
V_345 = V_226 -> V_266 -> V_31 ;
if ( V_345 == 2 )
V_106 . V_107 = V_108 ;
else
V_106 . V_107 = V_348 ;
if ( V_345 == 3 || V_345 == 4 || V_345 == 5 || V_345 == 6 )
V_344 = FALSE ;
else
V_344 = TRUE ;
for ( V_175 = V_349 ; V_175 <= V_168 ; V_175 ++ ) {
V_156 = F_64 ( V_343 , V_175 ) ;
F_66 ( V_156 , V_344 ) ;
}
break;
case V_247 :
F_93 ( V_350 ) ;
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
static T_25 T_26
V_138 ( T_5 V_343 , T_27 V_223 , V_171 V_224 , V_86 V_225 ) {
T_5 V_156 ;
V_11 * V_263 = ( V_11 * ) V_225 ;
T_7 V_351 [ V_274 ] ;
T_28 * V_226 = ( T_28 * ) V_225 ;
switch( V_223 ) {
case V_228 :
F_79 ( V_351 , V_274 , F_7 ( L_60 ) ,
V_263 -> V_85 , F_9 ( F_121 ( V_263 -> V_85 , L_1 , L_61 ) ) ) ;
V_156 = F_64 ( V_343 , V_352 ) ;
F_69 ( V_156 , V_351 ) ;
break;
case V_242 :
switch ( V_226 -> V_243 . V_244 ) {
case V_247 :
F_93 ( V_353 ) ;
break;
default:
break;
}
default:
break;
}
return 0 ;
}
static T_25 T_26
V_149 ( T_5 V_343 , T_27 V_223 , V_171 V_224 , V_86 V_225 ) {
T_5 V_156 ;
V_11 * V_263 = ( V_11 * ) V_225 ;
T_7 V_354 [ V_274 ] ;
T_28 * V_226 = ( T_28 * ) V_225 ;
switch( V_223 ) {
case V_228 :
F_79 ( V_354 , V_274 , F_7 ( L_62 ) ,
V_263 -> V_85 , F_9 ( F_121 ( V_263 -> V_85 , L_1 , L_61 ) ) ) ;
V_156 = F_64 ( V_343 , V_355 ) ;
F_69 ( V_156 , V_354 ) ;
break;
case V_242 :
switch ( V_226 -> V_243 . V_244 ) {
case V_247 :
F_93 ( V_353 ) ;
break;
default:
break;
}
default:
break;
}
return 0 ;
}
