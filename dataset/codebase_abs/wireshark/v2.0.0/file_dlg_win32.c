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
V_102 = F_39 ( V_58 , & V_105 ) ;
break;
case V_120 :
V_105 . V_118 = F_40 ( TRUE , V_105 . V_116 ) ;
if ( V_105 . V_118 == NULL ) {
F_38 ( V_105 . V_116 , V_119 , TRUE ) ;
F_11 ( ( void * ) V_16 ) ;
return;
}
V_102 = F_39 ( V_58 , & V_105 ) ;
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
if ( F_57 ( V_130 , V_144 , ( unsigned int ) strlen ( V_144 ) ) < 0 ) {
F_45 ( V_129 , V_119 ) ;
F_58 ( V_130 ) ;
F_11 ( V_144 ) ;
return;
}
if ( F_58 ( V_130 ) < 0 ) {
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
F_59 ( T_5 V_13 , T_9 * V_58 , T_18 V_149 ) {
V_11 * V_16 ;
T_7 V_14 [ V_18 ] = F_7 ( L_1 ) ;
T_17 * V_101 ;
int V_2 ;
V_2 = F_1 () ;
V_16 = F_12 ( V_2 ) ;
V_16 -> V_23 = V_2 ;
V_16 -> V_24 = V_13 ;
V_16 -> V_25 = ( V_26 ) F_13 ( V_13 , V_27 ) ;
V_16 -> V_28 = V_150 ;
V_16 -> V_29 = NULL ;
V_16 -> V_30 = 0 ;
V_16 -> V_31 = V_151 ;
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
V_152 = V_58 -> V_80 ;
if ( F_27 ( V_16 ) ) {
F_11 ( ( void * ) V_16 ) ;
if ( ! F_60 ( F_18 ( V_14 ) , V_149 , FALSE ) )
return;
V_101 = F_46 ( F_18 ( V_14 ) ) ;
F_47 ( V_101 ) ;
} else {
F_11 ( ( void * ) V_16 ) ;
}
}
void
F_61 ( T_5 V_13 , T_18 V_153 ) {
V_11 * V_16 ;
T_7 V_14 [ V_18 ] = F_7 ( L_1 ) ;
T_17 * V_101 ;
int V_2 ;
V_2 = F_1 () ;
V_16 = F_12 ( V_2 ) ;
V_16 -> V_23 = V_2 ;
V_16 -> V_24 = V_13 ;
V_16 -> V_25 = ( V_26 ) F_13 ( V_13 , V_27 ) ;
V_16 -> V_28 = V_150 ;
V_16 -> V_29 = NULL ;
V_16 -> V_30 = 0 ;
V_16 -> V_31 = V_151 ;
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
if ( ! F_62 ( F_18 ( V_14 ) , V_153 ) )
return;
V_101 = F_46 ( F_18 ( V_14 ) ) ;
F_47 ( V_101 ) ;
} else {
F_11 ( ( void * ) V_16 ) ;
}
}
static void
F_63 ( T_5 V_154 , T_19 * args ) {
T_5 V_155 ;
V_155 = F_64 ( V_154 , V_156 ) ;
if ( F_65 ( V_155 , V_157 , 0 , 0 ) == V_158 ) {
args -> V_110 = TRUE ;
V_155 = F_64 ( V_154 , V_159 ) ;
F_66 ( V_155 , TRUE ) ;
if ( F_65 ( V_155 , V_157 , 0 , 0 ) == V_158 )
args -> V_111 = TRUE ;
else
args -> V_111 = FALSE ;
} else {
args -> V_110 = FALSE ;
args -> V_111 = FALSE ;
V_155 = F_64 ( V_154 , V_159 ) ;
F_66 ( V_155 , FALSE ) ;
}
V_155 = F_64 ( V_154 , V_160 ) ;
if ( F_65 ( V_155 , V_157 , 0 , 0 ) == V_158 ) {
V_155 = F_64 ( V_154 , V_161 ) ;
switch ( F_65 ( V_155 , V_162 , 0 , 0 ) ) {
case 0 :
args -> V_112 = V_163 ;
break;
case 1 :
args -> V_112 = V_113 ;
break;
case 2 :
args -> V_112 = V_164 ;
break;
default:
F_35 () ;
}
F_66 ( V_155 , TRUE ) ;
} else {
args -> V_112 = V_165 ;
V_155 = F_64 ( V_154 , V_161 ) ;
F_66 ( V_155 , FALSE ) ;
}
V_155 = F_64 ( V_154 , V_166 ) ;
if ( F_65 ( V_155 , V_157 , 0 , 0 ) == V_158 )
args -> V_114 = TRUE ;
else
args -> V_114 = FALSE ;
V_155 = F_64 ( V_154 , V_167 ) ;
if ( F_65 ( V_155 , V_157 , 0 , 0 ) == V_158 )
args -> V_115 = TRUE ;
else
args -> V_115 = FALSE ;
}
static void
F_67 ( T_5 V_154 , T_19 * args ) {
T_5 V_155 ;
V_155 = F_64 ( V_154 , V_156 ) ;
F_65 ( V_155 , V_168 , args -> V_110 , 0 ) ;
V_155 = F_64 ( V_154 , V_159 ) ;
F_65 ( V_155 , V_168 , args -> V_111 , 0 ) ;
V_155 = F_64 ( V_154 , V_160 ) ;
F_65 ( V_155 , V_168 , args -> V_112 != V_165 , 0 ) ;
V_155 = F_64 ( V_154 , V_161 ) ;
F_65 ( V_155 , V_169 , 0 , ( V_170 ) F_7 ( L_31 ) ) ;
F_65 ( V_155 , V_169 , 0 , ( V_170 ) F_7 ( L_32 ) ) ;
F_65 ( V_155 , V_169 , 0 , ( V_170 ) F_7 ( L_33 ) ) ;
switch ( args -> V_112 ) {
case V_165 :
case V_163 :
F_65 ( V_155 , V_171 , 0 , 0 ) ;
break;
case V_113 :
F_65 ( V_155 , V_171 , 1 , 0 ) ;
break;
case V_164 :
F_65 ( V_155 , V_171 , 2 , 0 ) ;
default:
F_35 () ;
}
V_155 = F_64 ( V_154 , V_166 ) ;
F_65 ( V_155 , V_168 , args -> V_114 , 0 ) ;
V_155 = F_64 ( V_154 , V_167 ) ;
F_65 ( V_155 , V_168 , args -> V_115 , 0 ) ;
F_63 ( V_154 , args ) ;
}
static T_1
F_68 ( T_5 V_172 , T_17 * V_173 ) {
T_5 V_155 ;
int V_174 ;
T_20 * V_175 ;
const struct V_176 * V_177 ;
int V_178 = 0 ;
T_17 * V_179 ;
T_7 V_180 [ V_181 ] ;
T_21 V_182 ;
T_22 V_183 = 0 ;
T_21 V_184 ;
T_23 V_185 ;
struct V_186 * V_187 ;
T_22 V_188 ;
T_23 V_189 ;
T_23 V_190 ;
double V_191 = 0 ;
double V_192 = 0 ;
double V_193 ;
T_1 V_194 = FALSE ;
for ( V_174 = V_195 ; V_174 <= V_196 ; V_174 ++ ) {
V_155 = F_64 ( V_172 , V_174 ) ;
if ( V_155 ) {
F_66 ( V_155 , FALSE ) ;
}
}
for ( V_174 = V_195 ; V_174 <= V_196 ; V_174 ++ ) {
V_155 = F_64 ( V_172 , V_174 ) ;
if ( V_155 ) {
F_69 ( V_155 , F_7 ( L_34 ) ) ;
}
}
if ( V_173 == NULL || strlen ( V_173 ) < 1 ) {
return FALSE ;
}
V_155 = F_64 ( V_172 , V_195 ) ;
if ( F_70 ( V_173 ) == V_197 ) {
F_69 ( V_155 , F_7 ( L_35 ) ) ;
return FALSE ;
}
V_175 = F_71 ( V_173 , V_198 , & V_178 , & V_179 , TRUE ) ;
if ( V_155 && V_175 == NULL ) {
if( V_178 == V_199 ) {
F_69 ( V_155 , F_7 ( L_36 ) ) ;
} else {
F_69 ( V_155 , F_7 ( L_37 ) ) ;
}
return FALSE ;
}
for ( V_174 = V_200 ; V_174 <= V_196 ; V_174 ++ ) {
V_155 = F_64 ( V_172 , V_174 ) ;
if ( V_155 ) {
F_66 ( V_155 , TRUE ) ;
}
}
V_155 = F_64 ( V_172 , V_195 ) ;
F_69 ( V_155 , F_9 ( F_72 ( F_73 ( V_175 ) ) ) ) ;
V_184 = F_74 ( V_175 , & V_178 ) ;
F_75 ( V_180 , V_181 , L_38 V_201 L_39 , V_184 ) ;
V_155 = F_64 ( V_172 , V_202 ) ;
F_69 ( V_155 , V_180 ) ;
time ( & V_189 ) ;
while ( ( F_76 ( V_175 , & V_178 , & V_179 , & V_182 ) ) ) {
V_177 = F_77 ( V_175 ) ;
V_193 = F_78 ( ( const V_203 * ) & V_177 -> V_204 ) ;
if( V_183 == 0 ) {
V_191 = V_193 ;
V_192 = V_193 ;
}
if ( V_193 < V_191 ) {
V_191 = V_193 ;
}
if ( V_193 > V_192 ) {
V_192 = V_193 ;
}
V_183 ++ ;
if( V_183 % 100 == 0 ) {
time ( & V_190 ) ;
if( V_190 - V_189 >= ( T_23 ) V_37 . V_205 ) {
V_194 = TRUE ;
break;
}
}
}
if( V_178 != 0 ) {
F_79 ( V_180 , V_181 , F_7 ( L_40 ) , V_183 ) ;
V_155 = F_64 ( V_172 , V_206 ) ;
F_69 ( V_155 , V_180 ) ;
F_80 ( V_175 ) ;
return TRUE ;
}
if( V_194 ) {
F_79 ( V_180 , V_181 , F_7 ( L_41 ) , V_183 ) ;
} else {
F_79 ( V_180 , V_181 , F_7 ( L_42 ) , V_183 ) ;
}
V_155 = F_64 ( V_172 , V_206 ) ;
F_69 ( V_155 , V_180 ) ;
V_185 = ( long ) V_191 ;
V_187 = localtime ( & V_185 ) ;
if( V_187 ) {
F_79 ( V_180 , V_181 ,
F_7 ( L_43 ) ,
V_187 -> V_207 + 1900 ,
V_187 -> V_208 + 1 ,
V_187 -> V_209 ,
V_187 -> V_210 ,
V_187 -> V_211 ,
V_187 -> V_212 ) ;
} else {
F_79 ( V_180 , V_181 , F_7 ( L_44 ) ) ;
}
V_155 = F_64 ( V_172 , V_213 ) ;
F_69 ( V_155 , V_180 ) ;
V_188 = ( unsigned int ) ( V_192 - V_191 ) ;
if( V_188 / 86400 ) {
F_79 ( V_180 , V_181 , F_7 ( L_45 ) ,
V_188 / 86400 , V_188 % 86400 / 3600 , V_188 % 3600 / 60 , V_188 % 60 ) ;
} else {
F_79 ( V_180 , V_181 , F_7 ( L_46 ) ,
V_188 % 86400 / 3600 , V_188 % 3600 / 60 , V_188 % 60 ) ;
}
if( V_194 ) {
F_79 ( V_180 , V_181 , F_7 ( L_47 ) ) ;
}
V_155 = F_64 ( V_172 , V_196 ) ;
F_69 ( V_155 , V_180 ) ;
F_80 ( V_175 ) ;
return TRUE ;
}
static char *
F_81 ( T_5 V_214 ) {
T_7 * V_215 = NULL ;
T_11 V_20 ;
char * V_216 ;
V_20 = F_82 ( V_214 ) ;
if ( V_20 > 0 ) {
V_20 ++ ;
V_215 = F_83 ( V_20 * sizeof( T_7 ) ) ;
V_20 = F_84 ( V_214 , V_215 , V_20 ) ;
V_216 = F_85 ( V_215 , - 1 , NULL , NULL , NULL ) ;
F_11 ( V_215 ) ;
return V_216 ;
} else {
return NULL ;
}
}
static void
F_86 ( T_5 V_214 , T_7 * V_217 ) {
T_7 * V_215 = NULL ;
T_11 V_20 ;
T_24 * V_218 ;
if ( V_217 ) {
V_20 = ( F_87 ( V_217 ) + 1 ) * sizeof( T_7 ) ;
V_215 = F_83 ( V_20 ) ;
memcpy ( V_215 , V_217 , V_20 ) ;
} else {
V_20 = F_82 ( V_214 ) ;
if ( V_20 > 0 ) {
V_20 ++ ;
V_215 = F_83 ( V_20 * sizeof( T_7 ) ) ;
V_20 = F_84 ( V_214 , V_215 , V_20 ) ;
}
}
if ( V_20 == 0 ) {
F_65 ( V_214 , V_219 , ( V_170 ) 1 , V_220 ) ;
return;
} else if ( F_88 ( F_18 ( V_215 ) , & V_218 , NULL ) ) {
if ( V_218 != NULL )
F_89 ( V_218 ) ;
F_65 ( V_214 , V_219 , 0 , F_90 ( 0xe4 , 0xff , 0xc7 ) ) ;
} else {
F_65 ( V_214 , V_219 , 0 , F_90 ( 0xff , 0xcc , 0xcc ) ) ;
}
if ( V_215 ) F_11 ( V_215 ) ;
}
static T_25 T_26
V_54 ( T_5 V_172 , T_27 V_221 , V_170 V_222 , V_85 V_223 ) {
T_5 V_155 , V_57 ;
T_28 * V_224 = ( T_28 * ) V_223 ;
T_7 V_225 [ V_18 ] ;
T_11 V_174 ;
switch( V_221 ) {
case V_226 :
if( V_22 != NULL ) {
V_155 = F_64 ( V_172 , V_227 ) ;
F_69 ( V_155 , F_9 ( V_22 ) ) ;
}
V_155 = F_64 ( V_172 , V_228 ) ;
F_65 ( V_155 , V_169 , 0 , ( V_170 ) F_7 ( L_48 ) ) ;
for ( V_174 = 0 ; V_229 [ V_174 ] . V_230 != NULL ; V_174 += 1 ) {
F_65 ( V_155 , V_169 , 0 , ( V_170 ) F_9 ( V_229 [ V_174 ] . V_230 ) ) ;
}
F_65 ( V_155 , V_171 , 0 , 0 ) ;
V_155 = F_64 ( V_172 , V_231 ) ;
F_65 ( V_155 , V_168 , V_232 . V_233 , 0 ) ;
V_155 = F_64 ( V_172 , V_234 ) ;
F_65 ( V_155 , V_168 , V_232 . V_235 , 0 ) ;
V_155 = F_64 ( V_172 , V_236 ) ;
F_65 ( V_155 , V_168 , V_232 . V_237 , 0 ) ;
V_155 = F_64 ( V_172 , V_238 ) ;
F_65 ( V_155 , V_168 , V_232 . V_239 , 0 ) ;
F_68 ( V_172 , NULL ) ;
break;
case V_240 :
switch ( V_224 -> V_241 . V_242 ) {
case V_243 :
V_155 = F_64 ( V_172 , V_227 ) ;
if ( V_22 )
F_11 ( V_22 ) ;
V_22 = F_81 ( V_155 ) ;
V_155 = F_64 ( V_172 , V_228 ) ;
V_56 = ( unsigned int ) F_65 ( V_155 , V_162 , 0 , 0 ) ;
V_155 = F_64 ( V_172 , V_231 ) ;
if ( F_65 ( V_155 , V_157 , 0 , 0 ) == V_158 )
V_232 . V_233 = TRUE ;
V_155 = F_64 ( V_172 , V_234 ) ;
if ( F_65 ( V_155 , V_157 , 0 , 0 ) == V_158 )
V_232 . V_235 = TRUE ;
V_155 = F_64 ( V_172 , V_236 ) ;
if ( F_65 ( V_155 , V_157 , 0 , 0 ) == V_158 )
V_232 . V_237 = TRUE ;
V_155 = F_64 ( V_172 , V_238 ) ;
if ( F_65 ( V_155 , V_157 , 0 , 0 ) == V_158 )
V_232 . V_239 = TRUE ;
break;
case V_244 :
V_57 = F_91 ( V_172 ) ;
F_92 ( V_57 , V_225 , V_18 ) ;
F_68 ( V_172 , F_18 ( V_225 ) ) ;
break;
case V_245 :
F_93 ( V_246 ) ;
break;
default:
break;
}
break;
case V_247 :
V_155 = ( T_5 ) V_223 ;
switch( V_222 ) {
case ( V_248 << 16 ) | V_227 :
F_86 ( V_155 , NULL ) ;
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
F_94 ( T_12 * V_249 , int V_250 )
{
T_6 * V_251 = F_95 ( L_1 ) ;
T_6 * V_252 = F_95 ( L_1 ) ;
T_17 V_253 ;
T_29 * V_254 , * V_255 ;
T_7 * V_256 ;
T_30 V_257 = 0 ;
V_254 = F_96 ( V_250 ) ;
F_17 ( V_251 , L_1 ) ;
V_253 = '\0' ;
for ( V_255 = V_254 ; V_255 != NULL ;
V_255 = F_97 ( V_255 ) ) {
if ( V_253 != '\0' )
F_98 ( V_251 , V_253 ) ;
F_99 ( V_251 , L_49 , ( char * ) V_255 -> V_258 ) ;
V_253 = ';' ;
}
F_100 ( V_254 ) ;
F_17 ( V_252 , L_50 ,
F_101 ( V_250 ) ,
V_251 -> V_21 ) ;
V_256 = F_9 ( V_252 -> V_21 ) ;
V_249 = F_102 ( V_249 , V_256 , ( T_22 ) strlen ( V_252 -> V_21 ) ) ;
V_249 = F_103 ( V_249 , V_257 ) ;
F_104 ( V_252 , TRUE ) ;
V_256 = F_9 ( V_251 -> V_21 ) ;
V_249 = F_102 ( V_249 , V_256 , ( T_22 ) strlen ( V_251 -> V_21 ) ) ;
V_249 = F_103 ( V_249 , V_257 ) ;
F_104 ( V_251 , TRUE ) ;
}
static T_7 *
F_14 ( void ) {
T_7 * V_256 ;
int V_250 ;
T_12 * V_249 ;
static const T_30 V_257 = 0 ;
T_6 * V_251 ;
T_17 V_253 ;
T_29 * V_254 , * V_255 ;
V_249 = F_105 ( FALSE , FALSE , 2 ) ;
V_256 = F_9 ( L_51 ) ;
V_249 = F_102 ( V_249 , V_256 , ( T_22 ) strlen ( L_51 ) ) ;
V_249 = F_103 ( V_249 , V_257 ) ;
V_256 = F_9 ( L_52 ) ;
V_249 = F_102 ( V_249 , V_256 , ( T_22 ) strlen ( L_52 ) ) ;
V_249 = F_103 ( V_249 , V_257 ) ;
V_256 = F_9 ( L_53 ) ;
V_249 = F_102 ( V_249 , V_256 , ( T_22 ) strlen ( L_53 ) ) ;
V_249 = F_103 ( V_249 , V_257 ) ;
V_251 = F_95 ( L_1 ) ;
V_254 = F_106 () ;
V_253 = '\0' ;
for ( V_255 = V_254 ; V_255 != NULL ;
V_255 = F_97 ( V_255 ) ) {
if ( V_253 != '\0' )
F_98 ( V_251 , V_253 ) ;
F_99 ( V_251 , L_49 , ( char * ) V_255 -> V_258 ) ;
V_253 = ';' ;
}
F_100 ( V_254 ) ;
V_256 = F_9 ( V_251 -> V_21 ) ;
V_249 = F_102 ( V_249 , V_256 , ( T_22 ) strlen ( V_251 -> V_21 ) ) ;
V_249 = F_103 ( V_249 , V_257 ) ;
for ( V_250 = 0 ; V_250 < F_107 () ; V_250 ++ ) {
F_94 ( V_249 , V_250 ) ;
}
V_249 = F_103 ( V_249 , V_257 ) ;
return ( T_7 * ) F_31 ( V_249 , FALSE ) ;
}
static void
F_108 ( T_12 * V_249 , int V_259 )
{
T_6 * V_251 = F_95 ( L_1 ) ;
T_6 * V_252 = F_95 ( L_1 ) ;
T_17 V_253 ;
T_29 * V_254 , * V_255 ;
T_7 * V_256 ;
T_30 V_257 = 0 ;
V_254 = F_109 ( V_259 , TRUE ) ;
if ( V_254 == NULL ) {
F_17 ( V_251 , L_52 ) ;
} else {
F_17 ( V_251 , L_1 ) ;
V_253 = '\0' ;
for ( V_255 = V_254 ; V_255 != NULL ;
V_255 = F_97 ( V_255 ) ) {
if ( V_253 != '\0' )
F_98 ( V_251 , V_253 ) ;
F_99 ( V_251 , L_49 , ( char * ) V_255 -> V_258 ) ;
V_253 = ';' ;
}
F_100 ( V_254 ) ;
}
F_17 ( V_252 , L_50 , F_72 ( V_259 ) ,
V_251 -> V_21 ) ;
V_256 = F_9 ( V_252 -> V_21 ) ;
V_249 = F_102 ( V_249 , V_256 , ( T_22 ) strlen ( V_252 -> V_21 ) ) ;
V_249 = F_103 ( V_249 , V_257 ) ;
F_104 ( V_252 , TRUE ) ;
V_256 = F_9 ( V_251 -> V_21 ) ;
V_249 = F_102 ( V_249 , V_256 , ( T_22 ) strlen ( V_251 -> V_21 ) ) ;
V_249 = F_103 ( V_249 , V_257 ) ;
F_104 ( V_251 , TRUE ) ;
}
static T_7 *
F_26 ( T_12 * V_78 ) {
T_22 V_174 ;
int V_259 ;
T_12 * V_249 = F_105 ( FALSE , FALSE , 2 ) ;
T_30 V_257 = 0 ;
for ( V_174 = 0 ; V_174 < V_78 -> V_20 ; V_174 ++ ) {
V_259 = F_28 ( V_78 , int , V_174 ) ;
F_108 ( V_249 , V_259 ) ;
}
V_249 = F_103 ( V_249 , V_257 ) ;
return ( T_7 * ) F_31 ( V_249 , FALSE ) ;
}
static T_25 T_26
V_86 ( T_5 V_260 , T_27 V_221 , V_170 V_222 , V_85 V_223 ) {
T_5 V_155 ;
T_28 * V_224 = ( T_28 * ) V_223 ;
switch( V_221 ) {
case V_226 : {
V_11 * V_261 = ( V_11 * ) V_223 ;
T_9 * V_58 = ( T_9 * ) V_261 -> V_84 ;
V_87 = V_260 ;
V_152 = V_58 -> V_80 ;
V_155 = F_64 ( V_260 , V_262 ) ;
F_65 ( V_155 , V_168 , V_81 , 0 ) ;
break;
}
case V_247 :
V_155 = ( T_5 ) V_223 ;
switch ( V_222 ) {
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
case V_240 :
switch ( V_224 -> V_241 . V_242 ) {
case V_245 :
F_93 ( V_263 ) ;
break;
case V_243 : {
T_5 V_57 ;
char * V_129 ;
V_11 * V_261 = ( V_11 * ) V_224 -> V_264 ;
T_9 * V_58 = ( T_9 * ) V_261 -> V_84 ;
V_155 = F_64 ( V_260 , V_262 ) ;
if ( F_65 ( V_155 , V_157 , 0 , 0 ) == V_158 )
V_81 = TRUE ;
else
V_81 = FALSE ;
V_57 = F_91 ( V_260 ) ;
V_129 = F_18 ( V_224 -> V_264 -> V_33 ) ;
if ( F_110 ( V_58 -> V_265 , V_129 ) ) {
T_17 * V_21 = F_111 (
L_54
L_55 ,
V_129 ) ;
F_23 ( V_57 , F_9 ( V_21 ) , F_7 ( L_56 ) , V_266 | V_267 | V_268 ) ;
F_11 ( V_21 ) ;
F_112 ( V_260 , V_269 , 1L ) ;
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
V_88 ( T_5 V_260 , T_27 V_221 , V_170 V_222 , V_85 V_223 ) {
switch( V_221 ) {
case V_226 :
V_87 = V_260 ;
break;
case V_247 :
break;
case V_240 :
break;
default:
break;
}
return 0 ;
}
static T_25 T_26
V_92 ( T_5 V_260 , T_27 V_221 , V_170 V_222 , V_85 V_223 ) {
T_5 V_155 ;
T_28 * V_224 = ( T_28 * ) V_223 ;
switch( V_221 ) {
case V_226 : {
V_87 = V_260 ;
V_152 = V_91 -> V_80 ;
F_113 ( V_260 , V_90 ) ;
V_155 = F_64 ( V_260 , V_262 ) ;
F_65 ( V_155 , V_168 , V_81 , 0 ) ;
break;
}
case V_247 :
V_155 = ( T_5 ) V_223 ;
switch ( V_222 ) {
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
F_114 ( V_260 , V_155 , V_222 , V_90 ) ;
break;
}
break;
case V_240 :
switch ( V_224 -> V_241 . V_242 ) {
case V_245 :
F_93 ( V_263 ) ;
break;
case V_243 : {
T_5 V_57 ;
char * V_129 ;
V_11 * V_261 = ( V_11 * ) V_224 -> V_264 ;
T_9 * V_58 = ( T_9 * ) V_261 -> V_84 ;
V_155 = F_64 ( V_260 , V_262 ) ;
if ( F_65 ( V_155 , V_157 , 0 , 0 ) == V_158 )
V_81 = TRUE ;
else
V_81 = FALSE ;
V_57 = F_91 ( V_260 ) ;
V_129 = F_18 ( V_224 -> V_264 -> V_33 ) ;
if ( F_110 ( V_58 -> V_265 , V_129 ) ) {
T_17 * V_21 = F_111 (
L_54
L_55 ,
V_129 ) ;
F_23 ( V_57 , F_9 ( V_21 ) , F_7 ( L_56 ) , V_266 | V_267 | V_268 ) ;
F_11 ( V_21 ) ;
F_112 ( V_260 , V_269 , 1L ) ;
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
F_115 ( T_5 V_154 , T_13 * V_89 ) {
T_5 V_155 ;
T_1 V_270 = FALSE ;
T_7 V_271 [ V_272 ] ;
T_11 V_273 ;
T_10 V_274 = 0 , V_275 = 0 ;
T_10 V_276 ;
T_1 V_277 = TRUE ;
V_155 = F_64 ( V_154 , V_278 ) ;
if ( F_65 ( V_155 , V_157 , 0 , 0 ) == V_158 )
V_270 = TRUE ;
V_155 = F_64 ( V_154 , V_279 ) ;
F_66 ( V_155 , ! V_270 ) ;
if ( V_89 -> V_280 ) {
F_79 ( V_271 , V_272 , F_7 ( L_42 ) , V_91 -> V_281 - V_89 -> V_274 ) ;
} else {
F_79 ( V_271 , V_272 , F_7 ( L_42 ) , V_91 -> V_281 ) ;
}
F_69 ( V_155 , V_271 ) ;
V_155 = F_64 ( V_154 , V_282 ) ;
F_66 ( V_155 , V_270 ) ;
if ( V_89 -> V_283 )
V_276 = V_89 -> V_284 ;
else
V_276 = V_89 -> V_276 ;
if ( V_89 -> V_280 ) {
F_79 ( V_271 , V_272 , F_7 ( L_42 ) , V_276 - V_89 -> V_275 ) ;
} else {
F_79 ( V_271 , V_272 , F_7 ( L_42 ) , V_276 ) ;
}
F_69 ( V_155 , V_271 ) ;
V_273 = ( V_91 -> V_285 ) ? V_91 -> V_285 -> V_286 : 0 ;
V_155 = F_64 ( V_154 , V_287 ) ;
F_66 ( V_155 , V_273 && ! V_270 ) ;
if ( V_89 -> V_280 && V_91 -> V_285 && V_91 -> V_285 -> V_288 . V_289 ) {
F_79 ( V_271 , V_272 , F_7 ( L_57 ) ) ;
} else {
F_79 ( V_271 , V_272 , F_7 ( L_58 ) , V_273 ? 1 : 0 ) ;
}
F_69 ( V_155 , V_271 ) ;
V_155 = F_64 ( V_154 , V_290 ) ;
F_66 ( V_155 , V_273 && V_270 ) ;
if ( V_89 -> V_280 && V_91 -> V_285 && V_91 -> V_285 -> V_288 . V_289 ) {
F_79 ( V_271 , V_272 , F_7 ( L_57 ) ) ;
} else {
F_79 ( V_271 , V_272 , F_7 ( L_58 ) , V_273 ? 1 : 0 ) ;
}
F_69 ( V_155 , V_271 ) ;
V_155 = F_64 ( V_154 , V_291 ) ;
F_66 ( V_155 , V_91 -> V_292 ) ;
V_155 = F_64 ( V_154 , V_293 ) ;
F_66 ( V_155 , V_91 -> V_292 && ! V_270 ) ;
if ( V_89 -> V_280 ) {
F_79 ( V_271 , V_272 , F_7 ( L_42 ) , V_91 -> V_292 - V_89 -> V_294 ) ;
} else {
F_79 ( V_271 , V_272 , F_7 ( L_42 ) , V_91 -> V_292 ) ;
}
F_69 ( V_155 , V_271 ) ;
V_155 = F_64 ( V_154 , V_295 ) ;
F_66 ( V_155 , V_91 -> V_292 && V_270 ) ;
if ( V_89 -> V_280 ) {
F_79 ( V_271 , V_272 , F_7 ( L_42 ) , V_89 -> V_296 - V_89 -> V_297 ) ;
} else {
F_79 ( V_271 , V_272 , F_7 ( L_42 ) , V_89 -> V_296 ) ;
}
F_69 ( V_155 , V_271 ) ;
V_155 = F_64 ( V_154 , V_298 ) ;
F_66 ( V_155 , V_89 -> V_299 ) ;
V_155 = F_64 ( V_154 , V_300 ) ;
F_66 ( V_155 , V_89 -> V_299 && ! V_270 ) ;
if ( V_89 -> V_280 ) {
F_79 ( V_271 , V_272 , F_7 ( L_42 ) , V_89 -> V_299 - V_89 -> V_301 ) ;
} else {
F_79 ( V_271 , V_272 , F_7 ( L_42 ) , V_89 -> V_299 ) ;
}
F_69 ( V_155 , V_271 ) ;
V_155 = F_64 ( V_154 , V_302 ) ;
F_66 ( V_155 , V_89 -> V_303 && V_270 ) ;
if ( V_89 -> V_280 ) {
F_79 ( V_271 , V_272 , F_7 ( L_42 ) , V_89 -> V_303 - V_89 -> V_304 ) ;
} else {
F_79 ( V_271 , V_272 , F_7 ( L_42 ) , V_89 -> V_303 ) ;
}
F_69 ( V_155 , V_271 ) ;
switch ( F_116 ( V_89 ) ) {
case V_305 :
V_155 = F_64 ( V_154 , V_306 ) ;
F_65 ( V_155 , V_219 , ( V_170 ) 1 , V_220 ) ;
V_155 = F_64 ( V_154 , V_307 ) ;
F_66 ( V_155 , ! V_270 ) ;
if ( V_89 -> V_280 ) {
F_79 ( V_271 , V_272 , F_7 ( L_42 ) , V_89 -> V_308 - V_89 -> V_309 ) ;
} else {
F_79 ( V_271 , V_272 , F_7 ( L_42 ) , V_89 -> V_308 ) ;
}
F_69 ( V_155 , V_271 ) ;
V_155 = F_64 ( V_154 , V_310 ) ;
F_66 ( V_155 , V_270 ) ;
if ( V_89 -> V_280 ) {
F_79 ( V_271 , V_272 , F_7 ( L_42 ) , V_89 -> V_311 - V_89 -> V_312 ) ;
} else {
F_79 ( V_271 , V_272 , F_7 ( L_42 ) , V_89 -> V_311 ) ;
}
F_69 ( V_155 , V_271 ) ;
break;
case V_313 :
if ( V_89 -> V_314 == V_315 ) V_277 = FALSE ;
V_155 = F_64 ( V_154 , V_306 ) ;
F_65 ( V_155 , V_219 , 0 , F_90 ( 0xff , 0xcc , 0xcc ) ) ;
V_155 = F_64 ( V_154 , V_307 ) ;
F_69 ( V_155 , F_7 ( L_59 ) ) ;
V_155 = F_64 ( V_154 , V_310 ) ;
F_69 ( V_155 , F_7 ( L_34 ) ) ;
break;
case V_316 :
if ( V_89 -> V_314 == V_315 ) V_277 = FALSE ;
V_155 = F_64 ( V_154 , V_306 ) ;
F_65 ( V_155 , V_219 , 0 , F_90 ( 0xff , 0xcc , 0xcc ) ) ;
V_155 = F_64 ( V_154 , V_307 ) ;
F_69 ( V_155 , F_7 ( L_60 ) ) ;
V_155 = F_64 ( V_154 , V_310 ) ;
F_69 ( V_155 , F_7 ( L_34 ) ) ;
break;
default:
F_35 () ;
}
switch( V_89 -> V_314 ) {
case ( V_317 ) :
V_274 = V_89 -> V_274 ;
V_275 = V_89 -> V_275 ;
break;
case ( V_318 ) :
V_274 = ( V_91 -> V_285 && V_91 -> V_285 -> V_288 . V_289 ) ? 1 : 0 ;
V_275 = V_274 ;
break;
case ( V_319 ) :
V_274 = V_89 -> V_294 ;
V_275 = V_89 -> V_297 ;
break;
case ( V_320 ) :
V_274 = V_89 -> V_301 ;
V_275 = V_89 -> V_304 ;
break;
case ( V_315 ) :
V_274 = V_89 -> V_309 ;
V_275 = V_89 -> V_312 ;
break;
default:
F_35 () ;
}
V_155 = F_64 ( V_154 , V_321 ) ;
F_66 ( V_155 , V_274 ) ;
V_155 = F_64 ( V_154 , V_322 ) ;
F_66 ( V_155 , V_274 && ! V_270 ) ;
F_79 ( V_271 , V_272 , F_7 ( L_42 ) , V_274 ) ;
F_69 ( V_155 , V_271 ) ;
V_155 = F_64 ( V_154 , V_323 ) ;
F_66 ( V_155 , V_275 && V_270 ) ;
F_79 ( V_271 , V_272 , F_7 ( L_42 ) , V_275 ) ;
F_69 ( V_155 , V_271 ) ;
V_155 = F_64 ( F_91 ( V_154 ) , V_71 ) ;
F_66 ( V_155 , V_277 ) ;
}
static void
F_113 ( T_5 V_154 , T_13 * V_89 ) {
T_5 V_155 ;
if ( V_89 -> V_324 )
V_155 = F_64 ( V_154 , V_278 ) ;
else
V_155 = F_64 ( V_154 , V_325 ) ;
F_65 ( V_155 , V_168 , TRUE , 0 ) ;
if( V_89 -> V_326 != NULL ) {
char * V_327 ;
V_155 = F_64 ( V_154 , V_306 ) ;
V_327 = F_117 ( NULL , V_89 -> V_326 ) ;
F_69 ( V_155 , F_9 ( V_327 ) ) ;
F_118 ( NULL , V_327 ) ;
}
F_115 ( V_154 , V_89 ) ;
switch( V_89 -> V_314 ) {
case ( V_317 ) :
V_155 = F_64 ( V_154 , V_328 ) ;
break;
case ( V_318 ) :
V_155 = F_64 ( V_154 , V_329 ) ;
break;
case ( V_319 ) :
V_155 = F_64 ( V_154 , V_291 ) ;
break;
case ( V_320 ) :
V_155 = F_64 ( V_154 , V_298 ) ;
break;
case ( V_315 ) :
V_155 = F_64 ( V_154 , V_330 ) ;
break;
default:
F_35 () ;
}
F_65 ( V_155 , V_168 , TRUE , 0 ) ;
}
static void
F_114 ( T_5 V_154 , T_5 V_331 , V_170 V_222 , T_13 * V_89 ) {
T_5 V_155 ;
T_7 V_332 [ V_333 ] ;
if ( ! V_89 ) return;
switch( V_222 ) {
case ( V_334 << 16 ) | V_325 :
case ( V_334 << 16 ) | V_278 :
V_155 = F_64 ( V_154 , V_325 ) ;
if ( F_65 ( V_155 , V_157 , 0 , 0 ) == V_158 )
V_89 -> V_324 = FALSE ;
else
V_89 -> V_324 = TRUE ;
F_115 ( V_154 , V_89 ) ;
break;
case ( V_334 << 16 ) | V_328 :
if ( F_65 ( V_331 , V_157 , 0 , 0 ) == V_158 ) {
V_89 -> V_314 = V_317 ;
F_115 ( V_154 , V_89 ) ;
}
break;
case ( V_334 << 16 ) | V_329 :
if ( F_65 ( V_331 , V_157 , 0 , 0 ) == V_158 ) {
V_89 -> V_314 = V_318 ;
F_115 ( V_154 , V_89 ) ;
}
break;
case ( V_334 << 16 ) | V_291 :
if ( F_65 ( V_331 , V_157 , 0 , 0 ) == V_158 ) {
V_89 -> V_314 = V_319 ;
F_115 ( V_154 , V_89 ) ;
}
break;
case ( V_334 << 16 ) | V_298 :
if ( F_65 ( V_331 , V_157 , 0 , 0 ) == V_158 ) {
V_89 -> V_314 = V_320 ;
F_115 ( V_154 , V_89 ) ;
}
break;
case ( V_334 << 16 ) | V_330 :
if ( F_65 ( V_331 , V_157 , 0 , 0 ) == V_158 ) {
V_89 -> V_314 = V_315 ;
F_115 ( V_154 , V_89 ) ;
V_155 = F_64 ( V_154 , V_306 ) ;
F_119 ( V_155 ) ;
}
break;
case ( V_335 << 16 ) | V_306 :
V_155 = F_64 ( V_154 , V_330 ) ;
F_65 ( V_155 , V_336 , 0 , 0 ) ;
break;
case ( V_248 << 16 ) | V_306 :
F_65 ( V_331 , V_337 , ( V_170 ) V_333 , ( V_85 ) V_332 ) ;
F_120 ( V_89 , F_18 ( V_332 ) ) ;
F_115 ( V_154 , V_89 ) ;
break;
case ( V_334 << 16 ) | V_321 :
if ( F_65 ( V_331 , V_157 , 0 , 0 ) == V_158 ) {
V_89 -> V_280 = TRUE ;
} else {
V_89 -> V_280 = FALSE ;
}
F_115 ( V_154 , V_89 ) ;
break;
}
}
static T_25 T_26
V_95 ( T_5 V_338 , T_27 V_221 , V_170 V_222 , V_85 V_223 ) {
T_5 V_155 , V_57 ;
T_28 * V_224 = ( T_28 * ) V_223 ;
T_7 V_225 [ V_18 ] ;
switch( V_221 ) {
case V_226 :
if( V_22 != NULL ) {
V_155 = F_64 ( V_338 , V_227 ) ;
F_69 ( V_155 , F_9 ( V_22 ) ) ;
}
V_155 = F_64 ( V_338 , V_339 ) ;
F_65 ( V_155 , V_168 , TRUE , 0 ) ;
V_96 = V_97 ;
F_68 ( V_338 , NULL ) ;
break;
case V_240 :
switch ( V_224 -> V_241 . V_242 ) {
case V_243 :
V_155 = F_64 ( V_338 , V_227 ) ;
if ( V_22 )
F_11 ( V_22 ) ;
V_22 = F_81 ( V_155 ) ;
V_155 = F_64 ( V_338 , V_339 ) ;
if( F_65 ( V_155 , V_157 , 0 , 0 ) == V_158 ) {
V_96 = V_98 ;
} else {
V_155 = F_64 ( V_338 , V_340 ) ;
if( F_65 ( V_155 , V_157 , 0 , 0 ) == V_158 ) {
V_96 = V_99 ;
}
}
break;
case V_244 :
V_57 = F_91 ( V_338 ) ;
F_92 ( V_57 , V_225 , V_18 ) ;
F_68 ( V_338 , F_18 ( V_225 ) ) ;
break;
case V_245 :
F_93 ( V_341 ) ;
break;
default:
break;
}
break;
case V_247 :
V_155 = ( T_5 ) V_223 ;
switch( V_222 ) {
case ( V_248 << 16 ) | V_227 :
F_86 ( V_155 , NULL ) ;
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
V_104 ( T_5 V_342 , T_27 V_221 , V_170 V_222 , V_85 V_223 ) {
T_5 V_155 ;
T_28 * V_224 = ( T_28 * ) V_223 ;
T_1 V_343 ;
int V_174 , V_344 ;
switch( V_221 ) {
case V_226 : {
V_11 * V_261 = ( V_11 * ) V_223 ;
T_9 * V_58 = ( T_9 * ) V_261 -> V_84 ;
F_121 ( & V_105 . V_89 , V_58 ) ;
V_105 . V_89 . V_324 = TRUE ;
F_113 ( V_342 , & V_105 . V_89 ) ;
F_67 ( V_342 , & V_105 ) ;
break;
}
case V_247 :
V_155 = ( T_5 ) V_223 ;
switch ( V_222 ) {
case ( V_345 << 16 ) | V_161 :
default:
F_114 ( V_342 , V_155 , V_222 , & V_105 . V_89 ) ;
F_63 ( V_342 , & V_105 ) ;
break;
}
break;
case V_240 :
switch ( V_224 -> V_241 . V_242 ) {
case V_243 :
break;
case V_346 :
V_344 = V_224 -> V_264 -> V_31 ;
if ( V_344 == 2 )
V_105 . V_106 = V_107 ;
else
V_105 . V_106 = V_347 ;
if ( V_344 == 3 || V_344 == 4 || V_344 == 5 || V_344 == 6 )
V_343 = FALSE ;
else
V_343 = TRUE ;
for ( V_174 = V_348 ; V_174 <= V_167 ; V_174 ++ ) {
V_155 = F_64 ( V_342 , V_174 ) ;
F_66 ( V_155 , V_343 ) ;
}
break;
case V_245 :
F_93 ( V_349 ) ;
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
V_137 ( T_5 V_342 , T_27 V_221 , V_170 V_222 , V_85 V_223 ) {
T_5 V_155 ;
V_11 * V_261 = ( V_11 * ) V_223 ;
T_7 V_350 [ V_272 ] ;
T_28 * V_224 = ( T_28 * ) V_223 ;
switch( V_221 ) {
case V_226 :
F_79 ( V_350 , V_272 , F_7 ( L_61 ) ,
V_261 -> V_84 , F_9 ( F_122 ( V_261 -> V_84 , L_1 , L_62 ) ) ) ;
V_155 = F_64 ( V_342 , V_351 ) ;
F_69 ( V_155 , V_350 ) ;
break;
case V_240 :
switch ( V_224 -> V_241 . V_242 ) {
case V_245 :
F_93 ( V_352 ) ;
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
V_148 ( T_5 V_342 , T_27 V_221 , V_170 V_222 , V_85 V_223 ) {
T_5 V_155 ;
V_11 * V_261 = ( V_11 * ) V_223 ;
T_7 V_353 [ V_272 ] ;
T_28 * V_224 = ( T_28 * ) V_223 ;
switch( V_221 ) {
case V_226 :
F_79 ( V_353 , V_272 , F_7 ( L_63 ) ,
V_261 -> V_84 , F_9 ( F_122 ( V_261 -> V_84 , L_1 , L_62 ) ) ) ;
V_155 = F_64 ( V_342 , V_354 ) ;
F_69 ( V_155 , V_353 ) ;
break;
case V_240 :
switch ( V_224 -> V_241 . V_242 ) {
case V_245 :
F_93 ( V_352 ) ;
break;
default:
break;
}
default:
break;
}
return 0 ;
}
