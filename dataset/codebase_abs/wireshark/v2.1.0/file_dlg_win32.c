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
if ( F_21 ( V_59 , V_60 ) ) {
return V_62 ;
}
if ( F_22 ( V_58 -> V_63 , V_60 ) ) {
V_61 = F_23 ( V_57 ,
F_7 ( L_5 )
F_7 ( L_6 )
F_7 ( L_7 ) ,
F_7 ( L_8 ) ,
V_64 | V_65 | V_66 ) ;
} else {
V_61 = F_23 ( V_57 ,
F_7 ( L_9 )
F_7 ( L_10 )
F_7 ( L_11 ) ,
F_7 ( L_8 ) ,
V_67 | V_65 | V_66 ) ;
}
switch ( V_61 ) {
case V_68 :
return V_69 ;
case V_70 :
case V_71 :
return V_72 ;
case V_73 :
default:
return V_74 ;
}
}
T_1
F_24 ( T_5 V_13 , T_9 * V_58 , T_6 * V_14 , int * V_59 ,
T_1 * V_75 , T_1 V_76 )
{
T_10 V_77 ;
T_12 * V_78 ;
V_11 * V_16 ;
T_7 V_17 [ V_18 ] = F_7 ( L_1 ) ;
int V_2 ;
T_1 V_79 ;
if ( ! V_14 || ! V_59 || ! V_75 )
return FALSE ;
if ( V_14 -> V_20 > 0 ) {
F_8 ( V_17 , V_18 , F_9 ( V_14 -> V_21 ) ) ;
}
if ( V_76 )
V_77 = F_20 ( V_58 ) ;
else
V_77 = 0 ;
V_78 = F_25 ( V_58 -> V_80 ,
V_58 -> V_63 ,
V_77 ) ;
if ( V_78 == NULL )
return FALSE ;
V_81 = FALSE ;
V_2 = F_1 () ;
V_16 = F_12 ( V_2 ) ;
V_16 -> V_23 = V_2 ;
V_16 -> V_24 = V_13 ;
V_16 -> V_25 = ( V_26 ) F_13 ( V_13 , V_27 ) ;
V_16 -> V_28 = F_26 ( V_78 ) ;
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
V_47 | V_82 | V_49 |
V_83 | V_50 | V_51 ;
V_16 -> V_52 = NULL ;
V_16 -> V_84 = ( V_85 ) V_58 ;
V_16 -> V_53 = V_86 ;
V_16 -> V_55 = F_7 ( L_13 ) ;
V_79 = F_27 ( V_16 ) ;
if ( V_79 ) {
F_17 ( V_14 , L_4 , F_18 ( V_17 ) ) ;
* V_59 = F_28 ( V_78 , int , V_16 -> V_31 - 1 ) ;
* V_75 = V_81 ;
} else {
if ( F_29 () != 0 ) {
F_30 ( V_14 , 0 ) ;
V_79 = TRUE ;
}
}
V_87 = NULL ;
F_31 ( V_78 , TRUE ) ;
F_11 ( ( void * ) V_16 -> V_28 ) ;
F_11 ( ( void * ) V_16 ) ;
return V_79 ;
}
T_1 F_32 ( T_5 V_13 , T_6 * V_14 , int * V_59 )
{
V_11 * V_16 ;
T_7 V_17 [ V_18 ] = F_7 ( L_1 ) ;
int V_2 ;
T_1 V_79 ;
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
V_47 | V_82 | V_49 |
V_83 | V_50 ;
V_16 -> V_52 = NULL ;
V_16 -> V_53 = V_88 ;
V_16 -> V_55 = F_7 ( L_16 ) ;
V_79 = F_27 ( V_16 ) ;
if ( V_79 ) {
F_17 ( V_14 , L_4 , F_18 ( V_17 ) ) ;
* V_59 = V_16 -> V_31 - 1 ;
}
V_87 = NULL ;
F_11 ( ( void * ) V_16 ) ;
return V_79 ;
}
T_1
F_33 ( T_5 V_13 , T_9 * V_58 ,
T_6 * V_14 ,
int * V_59 ,
T_1 * V_75 ,
T_13 * V_89 ) {
T_12 * V_78 ;
V_11 * V_16 ;
T_7 V_17 [ V_18 ] = F_7 ( L_1 ) ;
int V_2 ;
T_1 V_79 ;
if ( ! V_14 || ! V_59 || ! V_75 || ! V_89 )
return FALSE ;
if ( V_14 -> V_20 > 0 ) {
F_8 ( V_17 , V_18 , F_9 ( V_14 -> V_21 ) ) ;
}
V_78 = F_25 ( V_58 -> V_80 ,
V_58 -> V_63 , 0 ) ;
if ( V_78 == NULL )
return FALSE ;
V_90 = V_89 ;
V_91 = V_58 ;
V_81 = FALSE ;
V_2 = F_1 () ;
V_16 = F_12 ( V_2 ) ;
V_16 -> V_23 = V_2 ;
V_16 -> V_24 = V_13 ;
V_16 -> V_25 = ( V_26 ) F_13 ( V_13 , V_27 ) ;
V_16 -> V_28 = F_26 ( V_78 ) ;
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
V_47 | V_82 | V_49 |
V_83 | V_50 | V_51 ;
V_16 -> V_52 = NULL ;
V_16 -> V_84 = ( V_85 ) V_58 ;
V_16 -> V_53 = V_92 ;
V_16 -> V_55 = F_7 ( L_18 ) ;
V_79 = F_27 ( V_16 ) ;
if ( V_79 ) {
F_17 ( V_14 , L_4 , F_18 ( V_17 ) ) ;
* V_59 = F_28 ( V_78 , int , V_16 -> V_31 - 1 ) ;
* V_75 = V_81 ;
} else {
if ( F_29 () != 0 ) {
F_30 ( V_14 , 0 ) ;
V_79 = TRUE ;
}
}
V_87 = NULL ;
V_90 = NULL ;
V_91 = NULL ;
F_31 ( V_78 , TRUE ) ;
F_11 ( ( void * ) V_16 -> V_28 ) ;
F_11 ( ( void * ) V_16 ) ;
return V_79 ;
}
T_1
F_34 ( T_5 V_13 , T_6 * V_14 , T_6 * V_15 , int * V_93 ) {
V_11 * V_16 ;
T_7 V_17 [ V_18 ] = F_7 ( L_1 ) ;
int V_2 ;
T_1 V_19 ;
if ( ! V_14 || ! V_15 || ! V_93 )
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
V_16 -> V_31 = V_94 ;
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
V_16 -> V_53 = V_95 ;
V_16 -> V_55 = F_7 ( L_20 ) ;
V_19 = F_16 ( V_16 ) ;
if ( V_19 ) {
F_17 ( V_14 , L_4 , F_18 ( V_17 ) ) ;
F_17 ( V_15 , L_4 , V_22 ? V_22 : L_1 ) ;
switch ( V_96 ) {
case V_97 :
* V_93 = 1 ;
break;
case V_98 :
* V_93 = 0 ;
break;
case V_99 :
* V_93 = - 1 ;
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
F_36 ( T_5 V_13 , T_9 * V_58 , T_14 V_100 ) {
V_11 * V_16 ;
T_7 V_14 [ V_18 ] = F_7 ( L_1 ) ;
char * V_101 ;
T_15 V_102 ;
int V_2 ;
V_91 = V_58 ;
V_2 = F_1 () ;
V_16 = F_12 ( V_2 ) ;
V_16 -> V_23 = V_2 ;
V_16 -> V_24 = V_13 ;
V_16 -> V_25 = ( V_26 ) F_13 ( V_13 , V_27 ) ;
V_16 -> V_28 = V_103 ;
V_16 -> V_29 = NULL ;
V_16 -> V_30 = 0 ;
V_16 -> V_31 = V_100 ;
V_16 -> V_33 = V_14 ;
V_16 -> V_34 = V_18 ;
V_16 -> V_35 = NULL ;
V_16 -> V_36 = 0 ;
V_16 -> V_41 = F_9 ( F_15 () ) ;
V_16 -> V_42 = F_7 ( L_21 ) ;
V_16 -> V_43 = V_44 | V_45 | V_46 |
V_47 | V_82 | V_49 |
V_83 | V_50 | V_51 ;
V_16 -> V_52 = NULL ;
V_16 -> V_84 = ( V_85 ) V_58 ;
V_16 -> V_53 = V_104 ;
V_16 -> V_55 = F_7 ( L_22 ) ;
V_105 . V_106 = V_107 ;
V_105 . V_108 = TRUE ;
V_105 . V_109 = NULL ;
V_105 . V_110 = TRUE ;
V_105 . V_111 = TRUE ;
V_105 . V_112 = V_113 ;
V_105 . V_114 = FALSE ;
V_105 . V_115 = FALSE ;
if ( F_27 ( V_16 ) ) {
V_105 . V_116 = F_18 ( V_14 ) ;
switch ( V_16 -> V_31 ) {
case V_117 :
V_105 . V_118 = F_37 ( TRUE , V_105 . V_116 ) ;
if ( V_105 . V_118 == NULL ) {
F_38 ( V_105 . V_116 , V_119 , TRUE ) ;
F_11 ( ( void * ) V_16 ) ;
return;
}
V_102 = F_39 ( V_58 , & V_105 , TRUE ) ;
break;
case V_120 :
V_105 . V_118 = F_40 ( TRUE , V_105 . V_116 ) ;
if ( V_105 . V_118 == NULL ) {
F_38 ( V_105 . V_116 , V_119 , TRUE ) ;
F_11 ( ( void * ) V_16 ) ;
return;
}
V_102 = F_39 ( V_58 , & V_105 , TRUE ) ;
break;
case V_121 :
V_102 = F_41 ( V_58 , & V_105 ) ;
break;
case V_122 :
V_102 = F_42 ( V_58 , & V_105 ) ;
break;
case V_123 :
V_102 = F_43 ( V_58 , & V_105 ) ;
break;
case V_124 :
V_102 = F_44 ( V_58 , & V_105 ) ;
break;
default:
F_11 ( ( void * ) V_16 ) ;
return;
}
switch ( V_102 ) {
case V_125 :
break;
case V_126 :
F_38 ( V_105 . V_116 , V_119 , TRUE ) ;
break;
case V_127 :
F_45 ( V_105 . V_116 , V_119 ) ;
break;
}
V_101 = F_46 ( F_18 ( V_14 ) ) ;
F_47 ( V_101 ) ;
}
V_91 = NULL ;
F_11 ( ( void * ) V_16 ) ;
}
void
F_48 ( T_5 V_13 , T_9 * V_58 ) {
V_11 * V_16 ;
T_7 V_14 [ V_18 ] = F_7 ( L_1 ) ;
char * V_101 ;
const T_16 * V_128 ;
char * V_129 ;
int V_130 ;
int V_2 ;
if ( ! V_58 -> V_131 ) {
F_49 ( V_132 , V_133 , L_23 ) ;
return;
}
V_2 = F_1 () ;
V_16 = F_12 ( V_2 ) ;
V_16 -> V_23 = V_2 ;
V_16 -> V_24 = V_13 ;
V_16 -> V_25 = ( V_26 ) F_13 ( V_13 , V_27 ) ;
V_16 -> V_28 = V_134 ;
V_16 -> V_29 = NULL ;
V_16 -> V_30 = 0 ;
V_16 -> V_31 = V_135 ;
V_16 -> V_33 = V_14 ;
V_16 -> V_34 = V_18 ;
V_16 -> V_35 = NULL ;
V_16 -> V_36 = 0 ;
V_16 -> V_41 = F_9 ( F_15 () ) ;
V_16 -> V_42 = F_7 ( L_24 ) ;
V_16 -> V_43 = V_44 | V_45 | V_46 |
V_47 | V_82 | V_49 |
V_83 | V_50 | V_51 ;
V_16 -> V_52 = NULL ;
V_16 -> V_84 = V_58 -> V_131 -> V_136 ;
V_16 -> V_53 = V_137 ;
V_16 -> V_55 = F_7 ( L_25 ) ;
if ( F_27 ( V_16 ) ) {
F_11 ( ( void * ) V_16 ) ;
V_129 = F_18 ( V_14 ) ;
V_128 = F_50 ( V_58 -> V_131 -> V_138 , 0 , - 1 ) +
V_58 -> V_131 -> V_139 ;
V_130 = F_51 ( V_129 , V_140 | V_141 | V_142 | V_143 , 0666 ) ;
if ( V_130 == - 1 ) {
F_38 ( V_129 , V_119 , TRUE ) ;
return;
}
if ( F_52 ( V_130 , V_128 , V_58 -> V_131 -> V_136 ) < 0 ) {
F_45 ( V_129 , V_119 ) ;
F_53 ( V_130 ) ;
return;
}
if ( F_53 ( V_130 ) < 0 ) {
F_45 ( V_129 , V_119 ) ;
return;
}
V_101 = F_46 ( V_129 ) ;
F_47 ( V_101 ) ;
} else {
F_11 ( ( void * ) V_16 ) ;
}
}
void
F_54 ( T_5 V_13 ) {
V_11 * V_16 ;
T_7 V_14 [ V_18 ] = F_7 ( L_1 ) ;
char * V_101 ;
T_17 * V_144 = NULL ;
char * V_129 ;
int V_130 ;
int V_2 ;
int V_145 ;
V_145 = F_55 () ;
if ( V_145 == 0 ) {
F_49 ( V_132 , V_133 , L_26 ) ;
return;
}
V_2 = F_1 () ;
V_16 = F_12 ( V_2 ) ;
V_16 -> V_23 = V_2 ;
V_16 -> V_24 = V_13 ;
V_16 -> V_25 = ( V_26 ) F_13 ( V_13 , V_27 ) ;
V_16 -> V_28 = V_146 ;
V_16 -> V_29 = NULL ;
V_16 -> V_30 = 0 ;
V_16 -> V_31 = V_147 ;
V_16 -> V_33 = V_14 ;
V_16 -> V_34 = V_18 ;
V_16 -> V_35 = NULL ;
V_16 -> V_36 = 0 ;
V_16 -> V_41 = F_9 ( F_15 () ) ;
V_16 -> V_42 = F_7 ( L_27 ) ;
V_16 -> V_43 = V_44 | V_45 | V_46 |
V_47 | V_82 | V_49 |
V_83 | V_50 | V_51 ;
V_16 -> V_52 = NULL ;
V_16 -> V_84 = V_145 ;
V_16 -> V_53 = V_148 ;
V_16 -> V_55 = F_7 ( L_28 ) ;
if ( F_27 ( V_16 ) ) {
F_11 ( ( void * ) V_16 ) ;
V_129 = F_18 ( V_14 ) ;
V_144 = F_56 () ;
V_130 = F_51 ( V_129 , V_140 | V_141 | V_142 | V_143 , 0666 ) ;
if ( V_130 == - 1 ) {
F_38 ( V_129 , V_119 , TRUE ) ;
F_11 ( V_144 ) ;
return;
}
if ( F_52 ( V_130 , V_144 , ( unsigned int ) strlen ( V_144 ) ) < 0 ) {
F_45 ( V_129 , V_119 ) ;
F_53 ( V_130 ) ;
F_11 ( V_144 ) ;
return;
}
if ( F_53 ( V_130 ) < 0 ) {
F_45 ( V_129 , V_119 ) ;
F_11 ( V_144 ) ;
return;
}
V_101 = F_46 ( V_129 ) ;
F_47 ( V_101 ) ;
} else {
F_11 ( ( void * ) V_16 ) ;
}
F_11 ( V_144 ) ;
}
void
F_57 ( T_5 V_13 , T_9 * V_58 , T_18 V_149 ) {
V_11 * V_16 ;
T_7 V_14 [ V_18 ] = F_7 ( L_1 ) ;
T_17 * V_101 ;
int V_2 ;
T_17 * V_150 = NULL ;
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
V_47 | V_82 | V_49 |
V_83 | V_50 ;
V_16 -> V_52 = NULL ;
V_16 -> V_53 = NULL ;
V_16 -> V_55 = NULL ;
V_153 = V_58 -> V_80 ;
if ( F_27 ( V_16 ) ) {
F_11 ( ( void * ) V_16 ) ;
if ( ! F_58 ( F_18 ( V_14 ) , V_149 , FALSE , & V_150 ) )
{
F_49 ( V_132 , V_133 , L_4 , V_150 ) ;
F_11 ( V_150 ) ;
return;
}
V_101 = F_46 ( F_18 ( V_14 ) ) ;
F_47 ( V_101 ) ;
} else {
F_11 ( ( void * ) V_16 ) ;
}
}
void
F_59 ( T_5 V_13 , T_18 V_154 ) {
V_11 * V_16 ;
T_7 V_14 [ V_18 ] = F_7 ( L_1 ) ;
T_17 * V_101 ;
int V_2 ;
T_17 * V_150 = NULL ;
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
V_47 | V_82 | V_49 |
V_83 | V_50 ;
V_16 -> V_52 = NULL ;
V_16 -> V_53 = NULL ;
V_16 -> V_55 = NULL ;
if ( F_16 ( V_16 ) ) {
F_11 ( ( void * ) V_16 ) ;
if ( ! F_60 ( F_18 ( V_14 ) , V_154 , & V_150 , V_155 ) ) {
F_49 ( V_132 , V_133 , L_4 , V_150 ) ;
F_11 ( V_150 ) ;
return;
}
V_101 = F_46 ( F_18 ( V_14 ) ) ;
F_47 ( V_101 ) ;
} else {
F_11 ( ( void * ) V_16 ) ;
}
}
static void
F_61 ( T_5 V_156 , T_19 * args ) {
T_5 V_157 ;
V_157 = F_62 ( V_156 , V_158 ) ;
if ( F_63 ( V_157 , V_159 , 0 , 0 ) == V_160 ) {
args -> V_110 = TRUE ;
V_157 = F_62 ( V_156 , V_161 ) ;
F_64 ( V_157 , TRUE ) ;
if ( F_63 ( V_157 , V_159 , 0 , 0 ) == V_160 )
args -> V_111 = TRUE ;
else
args -> V_111 = FALSE ;
} else {
args -> V_110 = FALSE ;
args -> V_111 = FALSE ;
V_157 = F_62 ( V_156 , V_161 ) ;
F_64 ( V_157 , FALSE ) ;
}
V_157 = F_62 ( V_156 , V_162 ) ;
if ( F_63 ( V_157 , V_159 , 0 , 0 ) == V_160 ) {
V_157 = F_62 ( V_156 , V_163 ) ;
switch ( F_63 ( V_157 , V_164 , 0 , 0 ) ) {
case 0 :
args -> V_112 = V_165 ;
break;
case 1 :
args -> V_112 = V_113 ;
break;
case 2 :
args -> V_112 = V_166 ;
break;
default:
F_35 () ;
}
F_64 ( V_157 , TRUE ) ;
} else {
args -> V_112 = V_167 ;
V_157 = F_62 ( V_156 , V_163 ) ;
F_64 ( V_157 , FALSE ) ;
}
V_157 = F_62 ( V_156 , V_168 ) ;
if ( F_63 ( V_157 , V_159 , 0 , 0 ) == V_160 )
args -> V_114 = TRUE ;
else
args -> V_114 = FALSE ;
V_157 = F_62 ( V_156 , V_169 ) ;
if ( F_63 ( V_157 , V_159 , 0 , 0 ) == V_160 )
args -> V_115 = TRUE ;
else
args -> V_115 = FALSE ;
}
static void
F_65 ( T_5 V_156 , T_19 * args ) {
T_5 V_157 ;
V_157 = F_62 ( V_156 , V_158 ) ;
F_63 ( V_157 , V_170 , args -> V_110 , 0 ) ;
V_157 = F_62 ( V_156 , V_161 ) ;
F_63 ( V_157 , V_170 , args -> V_111 , 0 ) ;
V_157 = F_62 ( V_156 , V_162 ) ;
F_63 ( V_157 , V_170 , args -> V_112 != V_167 , 0 ) ;
V_157 = F_62 ( V_156 , V_163 ) ;
F_63 ( V_157 , V_171 , 0 , ( V_172 ) F_7 ( L_31 ) ) ;
F_63 ( V_157 , V_171 , 0 , ( V_172 ) F_7 ( L_32 ) ) ;
F_63 ( V_157 , V_171 , 0 , ( V_172 ) F_7 ( L_33 ) ) ;
switch ( args -> V_112 ) {
case V_167 :
case V_165 :
F_63 ( V_157 , V_173 , 0 , 0 ) ;
break;
case V_113 :
F_63 ( V_157 , V_173 , 1 , 0 ) ;
break;
case V_166 :
F_63 ( V_157 , V_173 , 2 , 0 ) ;
default:
F_35 () ;
}
V_157 = F_62 ( V_156 , V_168 ) ;
F_63 ( V_157 , V_170 , args -> V_114 , 0 ) ;
V_157 = F_62 ( V_156 , V_169 ) ;
F_63 ( V_157 , V_170 , args -> V_115 , 0 ) ;
F_61 ( V_156 , args ) ;
}
static T_1
F_66 ( T_5 V_174 , T_17 * V_175 ) {
T_5 V_157 ;
int V_176 ;
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
for ( V_176 = V_197 ; V_176 <= V_198 ; V_176 ++ ) {
V_157 = F_62 ( V_174 , V_176 ) ;
if ( V_157 ) {
F_64 ( V_157 , FALSE ) ;
}
}
for ( V_176 = V_197 ; V_176 <= V_198 ; V_176 ++ ) {
V_157 = F_62 ( V_174 , V_176 ) ;
if ( V_157 ) {
F_67 ( V_157 , F_7 ( L_34 ) ) ;
}
}
if ( V_175 == NULL || strlen ( V_175 ) < 1 ) {
return FALSE ;
}
V_157 = F_62 ( V_174 , V_197 ) ;
if ( F_68 ( V_175 ) == V_199 ) {
F_67 ( V_157 , F_7 ( L_35 ) ) ;
return FALSE ;
}
V_177 = F_69 ( V_175 , V_200 , & V_180 , & V_181 , TRUE ) ;
if ( V_157 && V_177 == NULL ) {
if( V_180 == V_201 ) {
F_67 ( V_157 , F_7 ( L_36 ) ) ;
} else {
F_67 ( V_157 , F_7 ( L_37 ) ) ;
}
return FALSE ;
}
for ( V_176 = V_202 ; V_176 <= V_198 ; V_176 ++ ) {
V_157 = F_62 ( V_174 , V_176 ) ;
if ( V_157 ) {
F_64 ( V_157 , TRUE ) ;
}
}
V_157 = F_62 ( V_174 , V_197 ) ;
F_67 ( V_157 , F_9 ( F_70 ( F_71 ( V_177 ) ) ) ) ;
V_186 = F_72 ( V_177 , & V_180 ) ;
F_73 ( V_182 , V_183 , L_38 V_203 L_39 , V_186 ) ;
V_157 = F_62 ( V_174 , V_204 ) ;
F_67 ( V_157 , V_182 ) ;
time ( & V_191 ) ;
while ( ( F_74 ( V_177 , & V_180 , & V_181 , & V_184 ) ) ) {
V_179 = F_75 ( V_177 ) ;
V_195 = F_76 ( ( const V_205 * ) & V_179 -> V_206 ) ;
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
F_77 ( V_182 , V_183 , F_7 ( L_40 ) , V_185 ) ;
V_157 = F_62 ( V_174 , V_208 ) ;
F_67 ( V_157 , V_182 ) ;
F_78 ( V_177 ) ;
return TRUE ;
}
if( V_196 ) {
F_77 ( V_182 , V_183 , F_7 ( L_41 ) , V_185 ) ;
} else {
F_77 ( V_182 , V_183 , F_7 ( L_42 ) , V_185 ) ;
}
V_157 = F_62 ( V_174 , V_208 ) ;
F_67 ( V_157 , V_182 ) ;
V_187 = ( long ) V_193 ;
V_189 = localtime ( & V_187 ) ;
if( V_189 ) {
F_77 ( V_182 , V_183 ,
F_7 ( L_43 ) ,
V_189 -> V_209 + 1900 ,
V_189 -> V_210 + 1 ,
V_189 -> V_211 ,
V_189 -> V_212 ,
V_189 -> V_213 ,
V_189 -> V_214 ) ;
} else {
F_77 ( V_182 , V_183 , F_7 ( L_44 ) ) ;
}
V_157 = F_62 ( V_174 , V_215 ) ;
F_67 ( V_157 , V_182 ) ;
V_190 = ( unsigned int ) ( V_194 - V_193 ) ;
if( V_190 / 86400 ) {
F_77 ( V_182 , V_183 , F_7 ( L_45 ) ,
V_190 / 86400 , V_190 % 86400 / 3600 , V_190 % 3600 / 60 , V_190 % 60 ) ;
} else {
F_77 ( V_182 , V_183 , F_7 ( L_46 ) ,
V_190 % 86400 / 3600 , V_190 % 3600 / 60 , V_190 % 60 ) ;
}
if( V_196 ) {
F_77 ( V_182 , V_183 , F_7 ( L_47 ) ) ;
}
V_157 = F_62 ( V_174 , V_198 ) ;
F_67 ( V_157 , V_182 ) ;
F_78 ( V_177 ) ;
return TRUE ;
}
static char *
F_79 ( T_5 V_216 ) {
T_7 * V_217 = NULL ;
T_11 V_20 ;
char * V_218 ;
V_20 = F_80 ( V_216 ) ;
if ( V_20 > 0 ) {
V_20 ++ ;
V_217 = F_81 ( V_20 * sizeof( T_7 ) ) ;
V_20 = F_82 ( V_216 , V_217 , V_20 ) ;
V_218 = F_83 ( V_217 , - 1 , NULL , NULL , NULL ) ;
F_11 ( V_217 ) ;
return V_218 ;
} else {
return NULL ;
}
}
static void
F_84 ( T_5 V_216 , T_7 * V_219 ) {
T_7 * V_217 = NULL ;
T_11 V_20 ;
T_24 * V_220 ;
if ( V_219 ) {
V_20 = ( F_85 ( V_219 ) + 1 ) * sizeof( T_7 ) ;
V_217 = F_81 ( V_20 ) ;
memcpy ( V_217 , V_219 , V_20 ) ;
} else {
V_20 = F_80 ( V_216 ) ;
if ( V_20 > 0 ) {
V_20 ++ ;
V_217 = F_81 ( V_20 * sizeof( T_7 ) ) ;
V_20 = F_82 ( V_216 , V_217 , V_20 ) ;
}
}
if ( V_20 == 0 ) {
F_63 ( V_216 , V_221 , ( V_172 ) 1 , V_222 ) ;
return;
} else if ( F_86 ( F_18 ( V_217 ) , & V_220 , NULL ) ) {
if ( V_220 != NULL )
F_87 ( V_220 ) ;
F_63 ( V_216 , V_221 , 0 , F_88 ( 0xe4 , 0xff , 0xc7 ) ) ;
} else {
F_63 ( V_216 , V_221 , 0 , F_88 ( 0xff , 0xcc , 0xcc ) ) ;
}
if ( V_217 ) F_11 ( V_217 ) ;
}
static T_25 T_26
V_54 ( T_5 V_174 , T_27 V_223 , V_172 V_224 , V_85 V_225 ) {
T_5 V_157 , V_57 ;
T_28 * V_226 = ( T_28 * ) V_225 ;
T_7 V_227 [ V_18 ] ;
T_11 V_176 ;
switch( V_223 ) {
case V_228 :
if( V_22 != NULL ) {
V_157 = F_62 ( V_174 , V_229 ) ;
F_67 ( V_157 , F_9 ( V_22 ) ) ;
}
V_157 = F_62 ( V_174 , V_230 ) ;
F_63 ( V_157 , V_171 , 0 , ( V_172 ) F_7 ( L_48 ) ) ;
for ( V_176 = 0 ; V_231 [ V_176 ] . V_232 != NULL ; V_176 += 1 ) {
F_63 ( V_157 , V_171 , 0 , ( V_172 ) F_9 ( V_231 [ V_176 ] . V_232 ) ) ;
}
F_63 ( V_157 , V_173 , 0 , 0 ) ;
V_157 = F_62 ( V_174 , V_233 ) ;
F_63 ( V_157 , V_170 , V_234 . V_235 , 0 ) ;
V_157 = F_62 ( V_174 , V_236 ) ;
F_63 ( V_157 , V_170 , V_234 . V_237 , 0 ) ;
V_157 = F_62 ( V_174 , V_238 ) ;
F_63 ( V_157 , V_170 , V_234 . V_239 , 0 ) ;
V_157 = F_62 ( V_174 , V_240 ) ;
F_63 ( V_157 , V_170 , V_234 . V_241 , 0 ) ;
F_66 ( V_174 , NULL ) ;
break;
case V_242 :
switch ( V_226 -> V_243 . V_244 ) {
case V_245 :
V_157 = F_62 ( V_174 , V_229 ) ;
if ( V_22 )
F_11 ( V_22 ) ;
V_22 = F_79 ( V_157 ) ;
V_157 = F_62 ( V_174 , V_230 ) ;
V_56 = ( unsigned int ) F_63 ( V_157 , V_164 , 0 , 0 ) ;
V_157 = F_62 ( V_174 , V_233 ) ;
if ( F_63 ( V_157 , V_159 , 0 , 0 ) == V_160 )
V_234 . V_235 = TRUE ;
V_157 = F_62 ( V_174 , V_236 ) ;
if ( F_63 ( V_157 , V_159 , 0 , 0 ) == V_160 )
V_234 . V_237 = TRUE ;
V_157 = F_62 ( V_174 , V_238 ) ;
if ( F_63 ( V_157 , V_159 , 0 , 0 ) == V_160 )
V_234 . V_239 = TRUE ;
V_157 = F_62 ( V_174 , V_240 ) ;
if ( F_63 ( V_157 , V_159 , 0 , 0 ) == V_160 )
V_234 . V_241 = TRUE ;
break;
case V_246 :
V_57 = F_89 ( V_174 ) ;
F_90 ( V_57 , V_227 , V_18 ) ;
F_66 ( V_174 , F_18 ( V_227 ) ) ;
break;
case V_247 :
F_91 ( V_248 ) ;
break;
default:
break;
}
break;
case V_249 :
V_157 = ( T_5 ) V_225 ;
switch( V_224 ) {
case ( V_250 << 16 ) | V_229 :
F_84 ( V_157 , NULL ) ;
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
F_92 ( T_12 * V_251 , int V_252 )
{
T_6 * V_253 = F_93 ( L_1 ) ;
T_6 * V_254 = F_93 ( L_1 ) ;
T_17 V_255 ;
T_29 * V_256 , * V_257 ;
const T_7 * V_258 ;
T_30 V_259 = 0 ;
V_256 = F_94 ( V_252 ) ;
F_17 ( V_253 , L_1 ) ;
V_255 = '\0' ;
for ( V_257 = V_256 ; V_257 != NULL ;
V_257 = F_95 ( V_257 ) ) {
if ( V_255 != '\0' )
F_96 ( V_253 , V_255 ) ;
F_97 ( V_253 , L_49 , ( char * ) V_257 -> V_260 ) ;
V_255 = ';' ;
}
F_98 ( V_256 ) ;
F_17 ( V_254 , L_50 ,
F_99 ( V_252 ) ,
V_253 -> V_21 ) ;
V_258 = F_9 ( V_254 -> V_21 ) ;
V_251 = F_100 ( V_251 , V_258 , ( T_22 ) strlen ( V_254 -> V_21 ) ) ;
V_251 = F_101 ( V_251 , V_259 ) ;
F_102 ( V_254 , TRUE ) ;
V_258 = F_9 ( V_253 -> V_21 ) ;
V_251 = F_100 ( V_251 , V_258 , ( T_22 ) strlen ( V_253 -> V_21 ) ) ;
V_251 = F_101 ( V_251 , V_259 ) ;
F_102 ( V_253 , TRUE ) ;
}
static T_7 *
F_14 ( void ) {
const T_7 * V_258 ;
int V_252 ;
T_12 * V_251 ;
static const T_30 V_259 = 0 ;
T_6 * V_253 ;
T_17 V_255 ;
T_29 * V_256 , * V_257 ;
V_251 = F_103 ( FALSE , FALSE , 2 ) ;
V_258 = F_9 ( L_51 ) ;
V_251 = F_100 ( V_251 , V_258 , ( T_22 ) strlen ( L_51 ) ) ;
V_251 = F_101 ( V_251 , V_259 ) ;
V_258 = F_9 ( V_261 ) ;
V_251 = F_100 ( V_251 , V_258 , ( T_22 ) strlen ( V_261 ) ) ;
V_251 = F_101 ( V_251 , V_259 ) ;
V_258 = F_9 ( L_52 ) ;
V_251 = F_100 ( V_251 , V_258 , ( T_22 ) strlen ( L_52 ) ) ;
V_251 = F_101 ( V_251 , V_259 ) ;
V_253 = F_93 ( L_1 ) ;
V_256 = F_104 () ;
V_255 = '\0' ;
for ( V_257 = V_256 ; V_257 != NULL ;
V_257 = F_95 ( V_257 ) ) {
if ( V_255 != '\0' )
F_96 ( V_253 , V_255 ) ;
F_97 ( V_253 , L_49 , ( char * ) V_257 -> V_260 ) ;
V_255 = ';' ;
}
F_98 ( V_256 ) ;
V_258 = F_9 ( V_253 -> V_21 ) ;
V_251 = F_100 ( V_251 , V_258 , ( T_22 ) strlen ( V_253 -> V_21 ) ) ;
V_251 = F_101 ( V_251 , V_259 ) ;
for ( V_252 = 0 ; V_252 < F_105 () ; V_252 ++ ) {
F_92 ( V_251 , V_252 ) ;
}
V_251 = F_101 ( V_251 , V_259 ) ;
return ( T_7 * ) F_31 ( V_251 , FALSE ) ;
}
static void
F_106 ( T_12 * V_251 , int V_262 )
{
T_6 * V_253 = F_93 ( L_1 ) ;
T_6 * V_254 = F_93 ( L_1 ) ;
T_17 V_255 ;
T_29 * V_256 , * V_257 ;
const T_7 * V_258 ;
T_30 V_259 = 0 ;
V_256 = F_107 ( V_262 , TRUE ) ;
if ( V_256 == NULL ) {
F_17 ( V_253 , V_261 ) ;
} else {
F_17 ( V_253 , L_1 ) ;
V_255 = '\0' ;
for ( V_257 = V_256 ; V_257 != NULL ;
V_257 = F_95 ( V_257 ) ) {
if ( V_255 != '\0' )
F_96 ( V_253 , V_255 ) ;
F_97 ( V_253 , L_49 , ( char * ) V_257 -> V_260 ) ;
V_255 = ';' ;
}
F_98 ( V_256 ) ;
}
F_17 ( V_254 , L_50 , F_70 ( V_262 ) ,
V_253 -> V_21 ) ;
V_258 = F_9 ( V_254 -> V_21 ) ;
V_251 = F_100 ( V_251 , V_258 , ( T_22 ) strlen ( V_254 -> V_21 ) ) ;
V_251 = F_101 ( V_251 , V_259 ) ;
F_102 ( V_254 , TRUE ) ;
V_258 = F_9 ( V_253 -> V_21 ) ;
V_251 = F_100 ( V_251 , V_258 , ( T_22 ) strlen ( V_253 -> V_21 ) ) ;
V_251 = F_101 ( V_251 , V_259 ) ;
F_102 ( V_253 , TRUE ) ;
}
static T_7 *
F_26 ( T_12 * V_78 ) {
T_22 V_176 ;
int V_262 ;
T_12 * V_251 = F_103 ( FALSE , FALSE , 2 ) ;
T_30 V_259 = 0 ;
for ( V_176 = 0 ; V_176 < V_78 -> V_20 ; V_176 ++ ) {
V_262 = F_28 ( V_78 , int , V_176 ) ;
F_106 ( V_251 , V_262 ) ;
}
V_251 = F_101 ( V_251 , V_259 ) ;
return ( T_7 * ) F_31 ( V_251 , FALSE ) ;
}
static T_25 T_26
V_86 ( T_5 V_263 , T_27 V_223 , V_172 V_224 , V_85 V_225 ) {
T_5 V_157 ;
T_28 * V_226 = ( T_28 * ) V_225 ;
switch( V_223 ) {
case V_228 : {
V_11 * V_264 = ( V_11 * ) V_225 ;
T_9 * V_58 = ( T_9 * ) V_264 -> V_84 ;
V_87 = V_263 ;
V_153 = V_58 -> V_80 ;
V_157 = F_62 ( V_263 , V_265 ) ;
F_63 ( V_157 , V_170 , V_81 , 0 ) ;
break;
}
case V_249 :
V_157 = ( T_5 ) V_225 ;
switch ( V_224 ) {
#if 0
case (CBN_SELCHANGE << 16) | EWFD_FILE_TYPE_COMBO:
file_index = SendMessage(cur_ctrl, CB_GETCURSEL, 0, 0);
if (file_index != CB_ERR) {
new_filetype = SendMessage(cur_ctrl, CB_GETITEMDATA, (WPARAM) file_index, 0);
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
if (wtap_dump_can_compress(file_type)) {
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
F_91 ( V_266 ) ;
break;
case V_245 : {
T_5 V_57 ;
char * V_129 ;
V_11 * V_264 = ( V_11 * ) V_226 -> V_267 ;
T_9 * V_58 = ( T_9 * ) V_264 -> V_84 ;
V_157 = F_62 ( V_263 , V_265 ) ;
if ( F_63 ( V_157 , V_159 , 0 , 0 ) == V_160 )
V_81 = TRUE ;
else
V_81 = FALSE ;
V_57 = F_89 ( V_263 ) ;
V_129 = F_18 ( V_226 -> V_267 -> V_33 ) ;
if ( F_108 ( V_58 -> V_268 , V_129 ) ) {
T_17 * V_21 = F_109 (
L_53
L_54 ,
V_129 ) ;
F_23 ( V_57 , F_9 ( V_21 ) , F_7 ( L_55 ) , V_269 | V_270 | V_271 ) ;
F_11 ( V_21 ) ;
F_110 ( V_263 , V_272 , 1L ) ;
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
V_88 ( T_5 V_263 , T_27 V_223 , V_172 V_224 , V_85 V_225 ) {
switch( V_223 ) {
case V_228 :
V_87 = V_263 ;
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
V_92 ( T_5 V_263 , T_27 V_223 , V_172 V_224 , V_85 V_225 ) {
T_5 V_157 ;
T_28 * V_226 = ( T_28 * ) V_225 ;
switch( V_223 ) {
case V_228 : {
V_87 = V_263 ;
V_153 = V_91 -> V_80 ;
F_111 ( V_263 , V_90 ) ;
V_157 = F_62 ( V_263 , V_265 ) ;
F_63 ( V_157 , V_170 , V_81 , 0 ) ;
break;
}
case V_249 :
V_157 = ( T_5 ) V_225 ;
switch ( V_224 ) {
#if 0
case (CBN_SELCHANGE << 16) | EWFD_FILE_TYPE_COMBO:
file_index = SendMessage(cur_ctrl, CB_GETCURSEL, 0, 0);
if (file_index != CB_ERR) {
new_filetype = SendMessage(cur_ctrl, CB_GETITEMDATA, (WPARAM) file_index, 0);
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
F_112 ( V_263 , V_157 , V_224 , V_90 ) ;
break;
}
break;
case V_242 :
switch ( V_226 -> V_243 . V_244 ) {
case V_247 :
F_91 ( V_266 ) ;
break;
case V_245 : {
T_5 V_57 ;
char * V_129 ;
V_11 * V_264 = ( V_11 * ) V_226 -> V_267 ;
T_9 * V_58 = ( T_9 * ) V_264 -> V_84 ;
V_157 = F_62 ( V_263 , V_265 ) ;
if ( F_63 ( V_157 , V_159 , 0 , 0 ) == V_160 )
V_81 = TRUE ;
else
V_81 = FALSE ;
V_57 = F_89 ( V_263 ) ;
V_129 = F_18 ( V_226 -> V_267 -> V_33 ) ;
if ( F_108 ( V_58 -> V_268 , V_129 ) ) {
T_17 * V_21 = F_109 (
L_53
L_54 ,
V_129 ) ;
F_23 ( V_57 , F_9 ( V_21 ) , F_7 ( L_55 ) , V_269 | V_270 | V_271 ) ;
F_11 ( V_21 ) ;
F_110 ( V_263 , V_272 , 1L ) ;
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
F_113 ( T_5 V_156 , T_13 * V_89 ) {
T_5 V_157 ;
T_1 V_273 = FALSE ;
T_7 V_274 [ V_275 ] ;
T_11 V_276 ;
T_10 V_277 = 0 , V_278 = 0 ;
T_10 V_279 ;
T_1 V_280 = TRUE ;
V_157 = F_62 ( V_156 , V_281 ) ;
if ( F_63 ( V_157 , V_159 , 0 , 0 ) == V_160 )
V_273 = TRUE ;
V_157 = F_62 ( V_156 , V_282 ) ;
F_64 ( V_157 , ! V_273 ) ;
if ( V_89 -> V_283 ) {
F_77 ( V_274 , V_275 , F_7 ( L_42 ) , V_91 -> V_284 - V_89 -> V_277 ) ;
} else {
F_77 ( V_274 , V_275 , F_7 ( L_42 ) , V_91 -> V_284 ) ;
}
F_67 ( V_157 , V_274 ) ;
V_157 = F_62 ( V_156 , V_285 ) ;
F_64 ( V_157 , V_273 ) ;
if ( V_89 -> V_286 )
V_279 = V_89 -> V_287 ;
else
V_279 = V_89 -> V_279 ;
if ( V_89 -> V_283 ) {
F_77 ( V_274 , V_275 , F_7 ( L_42 ) , V_279 - V_89 -> V_278 ) ;
} else {
F_77 ( V_274 , V_275 , F_7 ( L_42 ) , V_279 ) ;
}
F_67 ( V_157 , V_274 ) ;
V_276 = ( V_91 -> V_288 ) ? V_91 -> V_288 -> V_289 : 0 ;
V_157 = F_62 ( V_156 , V_290 ) ;
F_64 ( V_157 , V_276 && ! V_273 ) ;
if ( V_89 -> V_283 && V_91 -> V_288 && V_91 -> V_288 -> V_291 . V_292 ) {
F_77 ( V_274 , V_275 , F_7 ( L_56 ) ) ;
} else {
F_77 ( V_274 , V_275 , F_7 ( L_57 ) , V_276 ? 1 : 0 ) ;
}
F_67 ( V_157 , V_274 ) ;
V_157 = F_62 ( V_156 , V_293 ) ;
F_64 ( V_157 , V_276 && V_273 ) ;
if ( V_89 -> V_283 && V_91 -> V_288 && V_91 -> V_288 -> V_291 . V_292 ) {
F_77 ( V_274 , V_275 , F_7 ( L_56 ) ) ;
} else {
F_77 ( V_274 , V_275 , F_7 ( L_57 ) , V_276 ? 1 : 0 ) ;
}
F_67 ( V_157 , V_274 ) ;
V_157 = F_62 ( V_156 , V_294 ) ;
F_64 ( V_157 , V_91 -> V_295 ) ;
V_157 = F_62 ( V_156 , V_296 ) ;
F_64 ( V_157 , V_91 -> V_295 && ! V_273 ) ;
if ( V_89 -> V_283 ) {
F_77 ( V_274 , V_275 , F_7 ( L_42 ) , V_91 -> V_295 - V_89 -> V_297 ) ;
} else {
F_77 ( V_274 , V_275 , F_7 ( L_42 ) , V_91 -> V_295 ) ;
}
F_67 ( V_157 , V_274 ) ;
V_157 = F_62 ( V_156 , V_298 ) ;
F_64 ( V_157 , V_91 -> V_295 && V_273 ) ;
if ( V_89 -> V_283 ) {
F_77 ( V_274 , V_275 , F_7 ( L_42 ) , V_89 -> V_299 - V_89 -> V_300 ) ;
} else {
F_77 ( V_274 , V_275 , F_7 ( L_42 ) , V_89 -> V_299 ) ;
}
F_67 ( V_157 , V_274 ) ;
V_157 = F_62 ( V_156 , V_301 ) ;
F_64 ( V_157 , V_89 -> V_302 ) ;
V_157 = F_62 ( V_156 , V_303 ) ;
F_64 ( V_157 , V_89 -> V_302 && ! V_273 ) ;
if ( V_89 -> V_283 ) {
F_77 ( V_274 , V_275 , F_7 ( L_42 ) , V_89 -> V_302 - V_89 -> V_304 ) ;
} else {
F_77 ( V_274 , V_275 , F_7 ( L_42 ) , V_89 -> V_302 ) ;
}
F_67 ( V_157 , V_274 ) ;
V_157 = F_62 ( V_156 , V_305 ) ;
F_64 ( V_157 , V_89 -> V_306 && V_273 ) ;
if ( V_89 -> V_283 ) {
F_77 ( V_274 , V_275 , F_7 ( L_42 ) , V_89 -> V_306 - V_89 -> V_307 ) ;
} else {
F_77 ( V_274 , V_275 , F_7 ( L_42 ) , V_89 -> V_306 ) ;
}
F_67 ( V_157 , V_274 ) ;
switch ( F_114 ( V_89 ) ) {
case V_308 :
V_157 = F_62 ( V_156 , V_309 ) ;
F_63 ( V_157 , V_221 , ( V_172 ) 1 , V_222 ) ;
V_157 = F_62 ( V_156 , V_310 ) ;
F_64 ( V_157 , ! V_273 ) ;
if ( V_89 -> V_283 ) {
F_77 ( V_274 , V_275 , F_7 ( L_42 ) , V_89 -> V_311 - V_89 -> V_312 ) ;
} else {
F_77 ( V_274 , V_275 , F_7 ( L_42 ) , V_89 -> V_311 ) ;
}
F_67 ( V_157 , V_274 ) ;
V_157 = F_62 ( V_156 , V_313 ) ;
F_64 ( V_157 , V_273 ) ;
if ( V_89 -> V_283 ) {
F_77 ( V_274 , V_275 , F_7 ( L_42 ) , V_89 -> V_314 - V_89 -> V_315 ) ;
} else {
F_77 ( V_274 , V_275 , F_7 ( L_42 ) , V_89 -> V_314 ) ;
}
F_67 ( V_157 , V_274 ) ;
break;
case V_316 :
if ( V_89 -> V_317 == V_318 ) V_280 = FALSE ;
V_157 = F_62 ( V_156 , V_309 ) ;
F_63 ( V_157 , V_221 , 0 , F_88 ( 0xff , 0xcc , 0xcc ) ) ;
V_157 = F_62 ( V_156 , V_310 ) ;
F_67 ( V_157 , F_7 ( L_58 ) ) ;
V_157 = F_62 ( V_156 , V_313 ) ;
F_67 ( V_157 , F_7 ( L_34 ) ) ;
break;
case V_319 :
if ( V_89 -> V_317 == V_318 ) V_280 = FALSE ;
V_157 = F_62 ( V_156 , V_309 ) ;
F_63 ( V_157 , V_221 , 0 , F_88 ( 0xff , 0xcc , 0xcc ) ) ;
V_157 = F_62 ( V_156 , V_310 ) ;
F_67 ( V_157 , F_7 ( L_59 ) ) ;
V_157 = F_62 ( V_156 , V_313 ) ;
F_67 ( V_157 , F_7 ( L_34 ) ) ;
break;
default:
F_35 () ;
}
switch( V_89 -> V_317 ) {
case ( V_320 ) :
V_277 = V_89 -> V_277 ;
V_278 = V_89 -> V_278 ;
break;
case ( V_321 ) :
V_277 = ( V_91 -> V_288 && V_91 -> V_288 -> V_291 . V_292 ) ? 1 : 0 ;
V_278 = V_277 ;
break;
case ( V_322 ) :
V_277 = V_89 -> V_297 ;
V_278 = V_89 -> V_300 ;
break;
case ( V_323 ) :
V_277 = V_89 -> V_304 ;
V_278 = V_89 -> V_307 ;
break;
case ( V_318 ) :
V_277 = V_89 -> V_312 ;
V_278 = V_89 -> V_315 ;
break;
default:
F_35 () ;
}
V_157 = F_62 ( V_156 , V_324 ) ;
F_64 ( V_157 , V_277 ) ;
V_157 = F_62 ( V_156 , V_325 ) ;
F_64 ( V_157 , V_277 && ! V_273 ) ;
F_77 ( V_274 , V_275 , F_7 ( L_42 ) , V_277 ) ;
F_67 ( V_157 , V_274 ) ;
V_157 = F_62 ( V_156 , V_326 ) ;
F_64 ( V_157 , V_278 && V_273 ) ;
F_77 ( V_274 , V_275 , F_7 ( L_42 ) , V_278 ) ;
F_67 ( V_157 , V_274 ) ;
V_157 = F_62 ( F_89 ( V_156 ) , V_71 ) ;
F_64 ( V_157 , V_280 ) ;
}
static void
F_111 ( T_5 V_156 , T_13 * V_89 ) {
T_5 V_157 ;
if ( V_89 -> V_327 )
V_157 = F_62 ( V_156 , V_281 ) ;
else
V_157 = F_62 ( V_156 , V_328 ) ;
F_63 ( V_157 , V_170 , TRUE , 0 ) ;
if( V_89 -> V_329 != NULL ) {
char * V_330 ;
V_157 = F_62 ( V_156 , V_309 ) ;
V_330 = F_115 ( NULL , V_89 -> V_329 ) ;
F_67 ( V_157 , F_9 ( V_330 ) ) ;
F_116 ( NULL , V_330 ) ;
}
F_113 ( V_156 , V_89 ) ;
switch( V_89 -> V_317 ) {
case ( V_320 ) :
V_157 = F_62 ( V_156 , V_331 ) ;
break;
case ( V_321 ) :
V_157 = F_62 ( V_156 , V_332 ) ;
break;
case ( V_322 ) :
V_157 = F_62 ( V_156 , V_294 ) ;
break;
case ( V_323 ) :
V_157 = F_62 ( V_156 , V_301 ) ;
break;
case ( V_318 ) :
V_157 = F_62 ( V_156 , V_333 ) ;
break;
default:
F_35 () ;
}
F_63 ( V_157 , V_170 , TRUE , 0 ) ;
}
static void
F_112 ( T_5 V_156 , T_5 V_334 , V_172 V_224 , T_13 * V_89 ) {
T_5 V_157 ;
T_7 V_335 [ V_336 ] ;
if ( ! V_89 ) return;
switch( V_224 ) {
case ( V_337 << 16 ) | V_328 :
case ( V_337 << 16 ) | V_281 :
V_157 = F_62 ( V_156 , V_328 ) ;
if ( F_63 ( V_157 , V_159 , 0 , 0 ) == V_160 )
V_89 -> V_327 = FALSE ;
else
V_89 -> V_327 = TRUE ;
F_113 ( V_156 , V_89 ) ;
break;
case ( V_337 << 16 ) | V_331 :
if ( F_63 ( V_334 , V_159 , 0 , 0 ) == V_160 ) {
V_89 -> V_317 = V_320 ;
F_113 ( V_156 , V_89 ) ;
}
break;
case ( V_337 << 16 ) | V_332 :
if ( F_63 ( V_334 , V_159 , 0 , 0 ) == V_160 ) {
V_89 -> V_317 = V_321 ;
F_113 ( V_156 , V_89 ) ;
}
break;
case ( V_337 << 16 ) | V_294 :
if ( F_63 ( V_334 , V_159 , 0 , 0 ) == V_160 ) {
V_89 -> V_317 = V_322 ;
F_113 ( V_156 , V_89 ) ;
}
break;
case ( V_337 << 16 ) | V_301 :
if ( F_63 ( V_334 , V_159 , 0 , 0 ) == V_160 ) {
V_89 -> V_317 = V_323 ;
F_113 ( V_156 , V_89 ) ;
}
break;
case ( V_337 << 16 ) | V_333 :
if ( F_63 ( V_334 , V_159 , 0 , 0 ) == V_160 ) {
V_89 -> V_317 = V_318 ;
F_113 ( V_156 , V_89 ) ;
V_157 = F_62 ( V_156 , V_309 ) ;
F_117 ( V_157 ) ;
}
break;
case ( V_338 << 16 ) | V_309 :
V_157 = F_62 ( V_156 , V_333 ) ;
F_63 ( V_157 , V_339 , 0 , 0 ) ;
break;
case ( V_250 << 16 ) | V_309 :
F_63 ( V_334 , V_340 , ( V_172 ) V_336 , ( V_85 ) V_335 ) ;
F_118 ( V_89 , F_18 ( V_335 ) ) ;
F_113 ( V_156 , V_89 ) ;
break;
case ( V_337 << 16 ) | V_324 :
if ( F_63 ( V_334 , V_159 , 0 , 0 ) == V_160 ) {
V_89 -> V_283 = TRUE ;
} else {
V_89 -> V_283 = FALSE ;
}
F_113 ( V_156 , V_89 ) ;
break;
}
}
static T_25 T_26
V_95 ( T_5 V_341 , T_27 V_223 , V_172 V_224 , V_85 V_225 ) {
T_5 V_157 , V_57 ;
T_28 * V_226 = ( T_28 * ) V_225 ;
T_7 V_227 [ V_18 ] ;
switch( V_223 ) {
case V_228 :
if( V_22 != NULL ) {
V_157 = F_62 ( V_341 , V_229 ) ;
F_67 ( V_157 , F_9 ( V_22 ) ) ;
}
V_157 = F_62 ( V_341 , V_342 ) ;
F_63 ( V_157 , V_170 , TRUE , 0 ) ;
V_96 = V_97 ;
F_66 ( V_341 , NULL ) ;
break;
case V_242 :
switch ( V_226 -> V_243 . V_244 ) {
case V_245 :
V_157 = F_62 ( V_341 , V_229 ) ;
if ( V_22 )
F_11 ( V_22 ) ;
V_22 = F_79 ( V_157 ) ;
V_157 = F_62 ( V_341 , V_342 ) ;
if( F_63 ( V_157 , V_159 , 0 , 0 ) == V_160 ) {
V_96 = V_98 ;
} else {
V_157 = F_62 ( V_341 , V_343 ) ;
if( F_63 ( V_157 , V_159 , 0 , 0 ) == V_160 ) {
V_96 = V_99 ;
}
}
break;
case V_246 :
V_57 = F_89 ( V_341 ) ;
F_90 ( V_57 , V_227 , V_18 ) ;
F_66 ( V_341 , F_18 ( V_227 ) ) ;
break;
case V_247 :
F_91 ( V_344 ) ;
break;
default:
break;
}
break;
case V_249 :
V_157 = ( T_5 ) V_225 ;
switch( V_224 ) {
case ( V_250 << 16 ) | V_229 :
F_84 ( V_157 , NULL ) ;
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
V_104 ( T_5 V_345 , T_27 V_223 , V_172 V_224 , V_85 V_225 ) {
T_5 V_157 ;
T_28 * V_226 = ( T_28 * ) V_225 ;
T_1 V_346 ;
int V_176 , V_347 ;
switch( V_223 ) {
case V_228 : {
V_11 * V_264 = ( V_11 * ) V_225 ;
T_9 * V_58 = ( T_9 * ) V_264 -> V_84 ;
F_119 ( & V_105 . V_89 , V_58 ) ;
V_105 . V_89 . V_327 = TRUE ;
F_111 ( V_345 , & V_105 . V_89 ) ;
F_65 ( V_345 , & V_105 ) ;
break;
}
case V_249 :
V_157 = ( T_5 ) V_225 ;
switch ( V_224 ) {
case ( V_348 << 16 ) | V_163 :
default:
F_112 ( V_345 , V_157 , V_224 , & V_105 . V_89 ) ;
F_61 ( V_345 , & V_105 ) ;
break;
}
break;
case V_242 :
switch ( V_226 -> V_243 . V_244 ) {
case V_245 :
break;
case V_349 :
V_347 = V_226 -> V_267 -> V_31 ;
if ( V_347 == 2 )
V_105 . V_106 = V_107 ;
else
V_105 . V_106 = V_350 ;
if ( V_347 == 3 || V_347 == 4 || V_347 == 5 || V_347 == 6 )
V_346 = FALSE ;
else
V_346 = TRUE ;
for ( V_176 = V_351 ; V_176 <= V_169 ; V_176 ++ ) {
V_157 = F_62 ( V_345 , V_176 ) ;
F_64 ( V_157 , V_346 ) ;
}
break;
case V_247 :
F_91 ( V_352 ) ;
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
V_137 ( T_5 V_345 , T_27 V_223 , V_172 V_224 , V_85 V_225 ) {
T_5 V_157 ;
V_11 * V_264 = ( V_11 * ) V_225 ;
T_7 V_353 [ V_275 ] ;
T_28 * V_226 = ( T_28 * ) V_225 ;
switch( V_223 ) {
case V_228 :
F_77 ( V_353 , V_275 , F_7 ( L_60 ) ,
V_264 -> V_84 , F_9 ( F_120 ( V_264 -> V_84 , L_1 , L_61 ) ) ) ;
V_157 = F_62 ( V_345 , V_354 ) ;
F_67 ( V_157 , V_353 ) ;
break;
case V_242 :
switch ( V_226 -> V_243 . V_244 ) {
case V_247 :
F_91 ( V_355 ) ;
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
V_148 ( T_5 V_345 , T_27 V_223 , V_172 V_224 , V_85 V_225 ) {
T_5 V_157 ;
V_11 * V_264 = ( V_11 * ) V_225 ;
T_7 V_356 [ V_275 ] ;
T_28 * V_226 = ( T_28 * ) V_225 ;
switch( V_223 ) {
case V_228 :
F_77 ( V_356 , V_275 , F_7 ( L_62 ) ,
V_264 -> V_84 , F_9 ( F_120 ( V_264 -> V_84 , L_1 , L_61 ) ) ) ;
V_157 = F_62 ( V_345 , V_357 ) ;
F_67 ( V_157 , V_356 ) ;
break;
case V_242 :
switch ( V_226 -> V_243 . V_244 ) {
case V_247 :
F_91 ( V_355 ) ;
break;
default:
break;
}
default:
break;
}
return 0 ;
}
