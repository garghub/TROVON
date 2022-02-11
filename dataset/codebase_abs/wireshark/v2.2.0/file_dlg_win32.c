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
case V_125 :
V_102 = F_45 ( V_58 , & V_105 ) ;
break;
default:
F_11 ( ( void * ) V_16 ) ;
return;
}
switch ( V_102 ) {
case V_126 :
break;
case V_127 :
F_38 ( V_105 . V_116 , V_119 , TRUE ) ;
break;
case V_128 :
F_46 ( V_105 . V_116 , V_119 ) ;
break;
}
V_101 = F_47 ( F_18 ( V_14 ) ) ;
F_48 ( V_101 ) ;
}
V_91 = NULL ;
F_11 ( ( void * ) V_16 ) ;
}
void
F_49 ( T_5 V_13 , T_9 * V_58 ) {
V_11 * V_16 ;
T_7 V_14 [ V_18 ] = F_7 ( L_1 ) ;
char * V_101 ;
const T_16 * V_129 ;
char * V_130 ;
int V_131 ;
int V_2 ;
if ( ! V_58 -> V_132 ) {
F_50 ( V_133 , V_134 , L_23 ) ;
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
V_47 | V_82 | V_49 |
V_83 | V_50 | V_51 ;
V_16 -> V_52 = NULL ;
V_16 -> V_84 = V_58 -> V_132 -> V_137 ;
V_16 -> V_53 = V_138 ;
V_16 -> V_55 = F_7 ( L_25 ) ;
if ( F_27 ( V_16 ) ) {
F_11 ( ( void * ) V_16 ) ;
V_130 = F_18 ( V_14 ) ;
V_129 = F_51 ( V_58 -> V_132 -> V_139 , 0 , - 1 ) +
V_58 -> V_132 -> V_140 ;
V_131 = F_52 ( V_130 , V_141 | V_142 | V_143 | V_144 , 0666 ) ;
if ( V_131 == - 1 ) {
F_38 ( V_130 , V_119 , TRUE ) ;
return;
}
if ( F_53 ( V_131 , V_129 , V_58 -> V_132 -> V_137 ) < 0 ) {
F_46 ( V_130 , V_119 ) ;
F_54 ( V_131 ) ;
return;
}
if ( F_54 ( V_131 ) < 0 ) {
F_46 ( V_130 , V_119 ) ;
return;
}
V_101 = F_47 ( V_130 ) ;
F_48 ( V_101 ) ;
} else {
F_11 ( ( void * ) V_16 ) ;
}
}
void
F_55 ( T_5 V_13 ) {
V_11 * V_16 ;
T_7 V_14 [ V_18 ] = F_7 ( L_1 ) ;
char * V_101 ;
T_17 * V_145 = NULL ;
char * V_130 ;
int V_131 ;
int V_2 ;
int V_146 ;
V_146 = F_56 () ;
if ( V_146 == 0 ) {
F_50 ( V_133 , V_134 , L_26 ) ;
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
V_47 | V_82 | V_49 |
V_83 | V_50 | V_51 ;
V_16 -> V_52 = NULL ;
V_16 -> V_84 = V_146 ;
V_16 -> V_53 = V_149 ;
V_16 -> V_55 = F_7 ( L_28 ) ;
if ( F_27 ( V_16 ) ) {
F_11 ( ( void * ) V_16 ) ;
V_130 = F_18 ( V_14 ) ;
V_145 = F_57 () ;
V_131 = F_52 ( V_130 , V_141 | V_142 | V_143 | V_144 , 0666 ) ;
if ( V_131 == - 1 ) {
F_38 ( V_130 , V_119 , TRUE ) ;
F_11 ( V_145 ) ;
return;
}
if ( F_53 ( V_131 , V_145 , ( unsigned int ) strlen ( V_145 ) ) < 0 ) {
F_46 ( V_130 , V_119 ) ;
F_54 ( V_131 ) ;
F_11 ( V_145 ) ;
return;
}
if ( F_54 ( V_131 ) < 0 ) {
F_46 ( V_130 , V_119 ) ;
F_11 ( V_145 ) ;
return;
}
V_101 = F_47 ( V_130 ) ;
F_48 ( V_101 ) ;
} else {
F_11 ( ( void * ) V_16 ) ;
}
F_11 ( V_145 ) ;
}
void
F_58 ( T_5 V_13 , T_9 * V_58 , T_18 V_150 ) {
V_11 * V_16 ;
T_7 V_14 [ V_18 ] = F_7 ( L_1 ) ;
T_17 * V_101 ;
int V_2 ;
T_17 * V_151 = NULL ;
V_2 = F_1 () ;
V_16 = F_12 ( V_2 ) ;
V_16 -> V_23 = V_2 ;
V_16 -> V_24 = V_13 ;
V_16 -> V_25 = ( V_26 ) F_13 ( V_13 , V_27 ) ;
V_16 -> V_28 = V_152 ;
V_16 -> V_29 = NULL ;
V_16 -> V_30 = 0 ;
V_16 -> V_31 = V_153 ;
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
V_154 = V_58 -> V_80 ;
if ( F_27 ( V_16 ) ) {
F_11 ( ( void * ) V_16 ) ;
if ( ! F_59 ( F_18 ( V_14 ) , V_150 , FALSE , & V_151 ) )
{
F_50 ( V_133 , V_134 , L_4 , V_151 ) ;
F_11 ( V_151 ) ;
return;
}
V_101 = F_47 ( F_18 ( V_14 ) ) ;
F_48 ( V_101 ) ;
} else {
F_11 ( ( void * ) V_16 ) ;
}
}
void
F_60 ( T_5 V_13 , T_18 V_155 ) {
V_11 * V_16 ;
T_7 V_14 [ V_18 ] = F_7 ( L_1 ) ;
T_17 * V_101 ;
int V_2 ;
T_17 * V_151 = NULL ;
V_2 = F_1 () ;
V_16 = F_12 ( V_2 ) ;
V_16 -> V_23 = V_2 ;
V_16 -> V_24 = V_13 ;
V_16 -> V_25 = ( V_26 ) F_13 ( V_13 , V_27 ) ;
V_16 -> V_28 = V_152 ;
V_16 -> V_29 = NULL ;
V_16 -> V_30 = 0 ;
V_16 -> V_31 = V_153 ;
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
if ( ! F_61 ( F_18 ( V_14 ) , V_155 , & V_151 , V_156 ) ) {
F_50 ( V_133 , V_134 , L_4 , V_151 ) ;
F_11 ( V_151 ) ;
return;
}
V_101 = F_47 ( F_18 ( V_14 ) ) ;
F_48 ( V_101 ) ;
} else {
F_11 ( ( void * ) V_16 ) ;
}
}
static void
F_62 ( T_5 V_157 , T_19 * args ) {
T_5 V_158 ;
V_158 = F_63 ( V_157 , V_159 ) ;
if ( F_64 ( V_158 , V_160 , 0 , 0 ) == V_161 ) {
args -> V_110 = TRUE ;
V_158 = F_63 ( V_157 , V_162 ) ;
F_65 ( V_158 , TRUE ) ;
if ( F_64 ( V_158 , V_160 , 0 , 0 ) == V_161 )
args -> V_111 = TRUE ;
else
args -> V_111 = FALSE ;
} else {
args -> V_110 = FALSE ;
args -> V_111 = FALSE ;
V_158 = F_63 ( V_157 , V_162 ) ;
F_65 ( V_158 , FALSE ) ;
}
V_158 = F_63 ( V_157 , V_163 ) ;
if ( F_64 ( V_158 , V_160 , 0 , 0 ) == V_161 ) {
V_158 = F_63 ( V_157 , V_164 ) ;
switch ( F_64 ( V_158 , V_165 , 0 , 0 ) ) {
case 0 :
args -> V_112 = V_166 ;
break;
case 1 :
args -> V_112 = V_113 ;
break;
case 2 :
args -> V_112 = V_167 ;
break;
default:
F_35 () ;
}
F_65 ( V_158 , TRUE ) ;
} else {
args -> V_112 = V_168 ;
V_158 = F_63 ( V_157 , V_164 ) ;
F_65 ( V_158 , FALSE ) ;
}
V_158 = F_63 ( V_157 , V_169 ) ;
if ( F_64 ( V_158 , V_160 , 0 , 0 ) == V_161 )
args -> V_114 = TRUE ;
else
args -> V_114 = FALSE ;
V_158 = F_63 ( V_157 , V_170 ) ;
if ( F_64 ( V_158 , V_160 , 0 , 0 ) == V_161 )
args -> V_115 = TRUE ;
else
args -> V_115 = FALSE ;
}
static void
F_66 ( T_5 V_157 , T_19 * args ) {
T_5 V_158 ;
V_158 = F_63 ( V_157 , V_159 ) ;
F_64 ( V_158 , V_171 , args -> V_110 , 0 ) ;
V_158 = F_63 ( V_157 , V_162 ) ;
F_64 ( V_158 , V_171 , args -> V_111 , 0 ) ;
V_158 = F_63 ( V_157 , V_163 ) ;
F_64 ( V_158 , V_171 , args -> V_112 != V_168 , 0 ) ;
V_158 = F_63 ( V_157 , V_164 ) ;
F_64 ( V_158 , V_172 , 0 , ( V_173 ) F_7 ( L_31 ) ) ;
F_64 ( V_158 , V_172 , 0 , ( V_173 ) F_7 ( L_32 ) ) ;
F_64 ( V_158 , V_172 , 0 , ( V_173 ) F_7 ( L_33 ) ) ;
switch ( args -> V_112 ) {
case V_168 :
case V_166 :
F_64 ( V_158 , V_174 , 0 , 0 ) ;
break;
case V_113 :
F_64 ( V_158 , V_174 , 1 , 0 ) ;
break;
case V_167 :
F_64 ( V_158 , V_174 , 2 , 0 ) ;
default:
F_35 () ;
}
V_158 = F_63 ( V_157 , V_169 ) ;
F_64 ( V_158 , V_171 , args -> V_114 , 0 ) ;
V_158 = F_63 ( V_157 , V_170 ) ;
F_64 ( V_158 , V_171 , args -> V_115 , 0 ) ;
F_62 ( V_157 , args ) ;
}
static T_1
F_67 ( T_5 V_175 , T_17 * V_176 ) {
T_5 V_158 ;
int V_177 ;
T_20 * V_178 ;
const struct V_179 * V_180 ;
int V_181 = 0 ;
T_17 * V_182 ;
T_7 V_183 [ V_184 ] ;
T_21 V_185 ;
T_22 V_186 = 0 ;
T_21 V_187 ;
T_23 V_188 ;
struct V_189 * V_190 ;
T_22 V_191 ;
T_23 V_192 ;
T_23 V_193 ;
double V_194 = 0 ;
double V_195 = 0 ;
double V_196 ;
T_1 V_197 = FALSE ;
for ( V_177 = V_198 ; V_177 <= V_199 ; V_177 ++ ) {
V_158 = F_63 ( V_175 , V_177 ) ;
if ( V_158 ) {
F_65 ( V_158 , FALSE ) ;
}
}
for ( V_177 = V_198 ; V_177 <= V_199 ; V_177 ++ ) {
V_158 = F_63 ( V_175 , V_177 ) ;
if ( V_158 ) {
F_68 ( V_158 , F_7 ( L_34 ) ) ;
}
}
if ( V_176 == NULL || strlen ( V_176 ) < 1 ) {
return FALSE ;
}
V_158 = F_63 ( V_175 , V_198 ) ;
if ( F_69 ( V_176 ) == V_200 ) {
F_68 ( V_158 , F_7 ( L_35 ) ) ;
return FALSE ;
}
V_178 = F_70 ( V_176 , V_201 , & V_181 , & V_182 , TRUE ) ;
if ( V_158 && V_178 == NULL ) {
if( V_181 == V_202 ) {
F_68 ( V_158 , F_7 ( L_36 ) ) ;
} else {
F_68 ( V_158 , F_7 ( L_37 ) ) ;
}
return FALSE ;
}
for ( V_177 = V_203 ; V_177 <= V_199 ; V_177 ++ ) {
V_158 = F_63 ( V_175 , V_177 ) ;
if ( V_158 ) {
F_65 ( V_158 , TRUE ) ;
}
}
V_158 = F_63 ( V_175 , V_198 ) ;
F_68 ( V_158 , F_9 ( F_71 ( F_72 ( V_178 ) ) ) ) ;
V_187 = F_73 ( V_178 , & V_181 ) ;
F_74 ( V_183 , V_184 , L_38 V_204 L_39 , V_187 ) ;
V_158 = F_63 ( V_175 , V_205 ) ;
F_68 ( V_158 , V_183 ) ;
time ( & V_192 ) ;
while ( ( F_75 ( V_178 , & V_181 , & V_182 , & V_185 ) ) ) {
V_180 = F_76 ( V_178 ) ;
V_196 = F_77 ( ( const V_206 * ) & V_180 -> V_207 ) ;
if( V_186 == 0 ) {
V_194 = V_196 ;
V_195 = V_196 ;
}
if ( V_196 < V_194 ) {
V_194 = V_196 ;
}
if ( V_196 > V_195 ) {
V_195 = V_196 ;
}
V_186 ++ ;
if( V_186 % 100 == 0 ) {
time ( & V_193 ) ;
if( V_193 - V_192 >= ( T_23 ) V_37 . V_208 ) {
V_197 = TRUE ;
break;
}
}
}
if( V_181 != 0 ) {
F_78 ( V_183 , V_184 , F_7 ( L_40 ) , V_186 ) ;
V_158 = F_63 ( V_175 , V_209 ) ;
F_68 ( V_158 , V_183 ) ;
F_79 ( V_178 ) ;
return TRUE ;
}
if( V_197 ) {
F_78 ( V_183 , V_184 , F_7 ( L_41 ) , V_186 ) ;
} else {
F_78 ( V_183 , V_184 , F_7 ( L_42 ) , V_186 ) ;
}
V_158 = F_63 ( V_175 , V_209 ) ;
F_68 ( V_158 , V_183 ) ;
V_188 = ( long ) V_194 ;
V_190 = localtime ( & V_188 ) ;
if( V_190 ) {
F_78 ( V_183 , V_184 ,
F_7 ( L_43 ) ,
V_190 -> V_210 + 1900 ,
V_190 -> V_211 + 1 ,
V_190 -> V_212 ,
V_190 -> V_213 ,
V_190 -> V_214 ,
V_190 -> V_215 ) ;
} else {
F_78 ( V_183 , V_184 , F_7 ( L_44 ) ) ;
}
V_158 = F_63 ( V_175 , V_216 ) ;
F_68 ( V_158 , V_183 ) ;
V_191 = ( unsigned int ) ( V_195 - V_194 ) ;
if( V_191 / 86400 ) {
F_78 ( V_183 , V_184 , F_7 ( L_45 ) ,
V_191 / 86400 , V_191 % 86400 / 3600 , V_191 % 3600 / 60 , V_191 % 60 ) ;
} else {
F_78 ( V_183 , V_184 , F_7 ( L_46 ) ,
V_191 % 86400 / 3600 , V_191 % 3600 / 60 , V_191 % 60 ) ;
}
if( V_197 ) {
F_78 ( V_183 , V_184 , F_7 ( L_47 ) ) ;
}
V_158 = F_63 ( V_175 , V_199 ) ;
F_68 ( V_158 , V_183 ) ;
F_79 ( V_178 ) ;
return TRUE ;
}
static char *
F_80 ( T_5 V_217 ) {
T_7 * V_218 = NULL ;
T_11 V_20 ;
char * V_219 ;
V_20 = F_81 ( V_217 ) ;
if ( V_20 > 0 ) {
V_20 ++ ;
V_218 = F_82 ( V_20 * sizeof( T_7 ) ) ;
V_20 = F_83 ( V_217 , V_218 , V_20 ) ;
V_219 = F_84 ( V_218 , - 1 , NULL , NULL , NULL ) ;
F_11 ( V_218 ) ;
return V_219 ;
} else {
return NULL ;
}
}
static void
F_85 ( T_5 V_217 , T_7 * V_220 ) {
T_7 * V_218 = NULL ;
T_11 V_20 ;
T_24 * V_221 ;
if ( V_220 ) {
V_20 = ( F_86 ( V_220 ) + 1 ) * sizeof( T_7 ) ;
V_218 = F_82 ( V_20 ) ;
memcpy ( V_218 , V_220 , V_20 ) ;
} else {
V_20 = F_81 ( V_217 ) ;
if ( V_20 > 0 ) {
V_20 ++ ;
V_218 = F_82 ( V_20 * sizeof( T_7 ) ) ;
V_20 = F_83 ( V_217 , V_218 , V_20 ) ;
}
}
if ( V_20 == 0 ) {
F_64 ( V_217 , V_222 , ( V_173 ) 1 , V_223 ) ;
return;
} else if ( F_87 ( F_18 ( V_218 ) , & V_221 , NULL ) ) {
if ( V_221 != NULL )
F_88 ( V_221 ) ;
F_64 ( V_217 , V_222 , 0 , F_89 ( 0xe4 , 0xff , 0xc7 ) ) ;
} else {
F_64 ( V_217 , V_222 , 0 , F_89 ( 0xff , 0xcc , 0xcc ) ) ;
}
if ( V_218 ) F_11 ( V_218 ) ;
}
static T_25 T_26
V_54 ( T_5 V_175 , T_27 V_224 , V_173 V_225 , V_85 V_226 ) {
T_5 V_158 , V_57 ;
T_28 * V_227 = ( T_28 * ) V_226 ;
T_7 V_228 [ V_18 ] ;
T_11 V_177 ;
switch( V_224 ) {
case V_229 :
if( V_22 != NULL ) {
V_158 = F_63 ( V_175 , V_230 ) ;
F_68 ( V_158 , F_9 ( V_22 ) ) ;
}
V_158 = F_63 ( V_175 , V_231 ) ;
F_64 ( V_158 , V_172 , 0 , ( V_173 ) F_7 ( L_48 ) ) ;
for ( V_177 = 0 ; V_232 [ V_177 ] . V_233 != NULL ; V_177 += 1 ) {
F_64 ( V_158 , V_172 , 0 , ( V_173 ) F_9 ( V_232 [ V_177 ] . V_233 ) ) ;
}
F_64 ( V_158 , V_174 , 0 , 0 ) ;
V_158 = F_63 ( V_175 , V_234 ) ;
F_64 ( V_158 , V_171 , V_235 . V_236 , 0 ) ;
V_158 = F_63 ( V_175 , V_237 ) ;
F_64 ( V_158 , V_171 , V_235 . V_238 , 0 ) ;
V_158 = F_63 ( V_175 , V_239 ) ;
F_64 ( V_158 , V_171 , V_235 . V_240 , 0 ) ;
V_158 = F_63 ( V_175 , V_241 ) ;
F_64 ( V_158 , V_171 , V_235 . V_242 , 0 ) ;
F_67 ( V_175 , NULL ) ;
break;
case V_243 :
switch ( V_227 -> V_244 . V_245 ) {
case V_246 :
V_158 = F_63 ( V_175 , V_230 ) ;
if ( V_22 )
F_11 ( V_22 ) ;
V_22 = F_80 ( V_158 ) ;
V_158 = F_63 ( V_175 , V_231 ) ;
V_56 = ( unsigned int ) F_64 ( V_158 , V_165 , 0 , 0 ) ;
V_158 = F_63 ( V_175 , V_234 ) ;
if ( F_64 ( V_158 , V_160 , 0 , 0 ) == V_161 )
V_235 . V_236 = TRUE ;
V_158 = F_63 ( V_175 , V_237 ) ;
if ( F_64 ( V_158 , V_160 , 0 , 0 ) == V_161 )
V_235 . V_238 = TRUE ;
V_158 = F_63 ( V_175 , V_239 ) ;
if ( F_64 ( V_158 , V_160 , 0 , 0 ) == V_161 )
V_235 . V_240 = TRUE ;
V_158 = F_63 ( V_175 , V_241 ) ;
if ( F_64 ( V_158 , V_160 , 0 , 0 ) == V_161 )
V_235 . V_242 = TRUE ;
break;
case V_247 :
V_57 = F_90 ( V_175 ) ;
F_91 ( V_57 , V_228 , V_18 ) ;
F_67 ( V_175 , F_18 ( V_228 ) ) ;
break;
case V_248 :
F_92 ( V_249 ) ;
break;
default:
break;
}
break;
case V_250 :
V_158 = ( T_5 ) V_226 ;
switch( V_225 ) {
case ( V_251 << 16 ) | V_230 :
F_85 ( V_158 , NULL ) ;
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
F_93 ( T_12 * V_252 , int V_253 )
{
T_6 * V_254 = F_94 ( L_1 ) ;
T_6 * V_255 = F_94 ( L_1 ) ;
T_17 V_256 ;
T_29 * V_257 , * V_258 ;
const T_7 * V_259 ;
T_30 V_260 = 0 ;
V_257 = F_95 ( V_253 ) ;
F_17 ( V_254 , L_1 ) ;
V_256 = '\0' ;
for ( V_258 = V_257 ; V_258 != NULL ;
V_258 = F_96 ( V_258 ) ) {
if ( V_256 != '\0' )
F_97 ( V_254 , V_256 ) ;
F_98 ( V_254 , L_49 , ( char * ) V_258 -> V_261 ) ;
V_256 = ';' ;
}
F_99 ( V_257 ) ;
F_17 ( V_255 , L_50 ,
F_100 ( V_253 ) ,
V_254 -> V_21 ) ;
V_259 = F_9 ( V_255 -> V_21 ) ;
V_252 = F_101 ( V_252 , V_259 , ( T_22 ) strlen ( V_255 -> V_21 ) ) ;
V_252 = F_102 ( V_252 , V_260 ) ;
F_103 ( V_255 , TRUE ) ;
V_259 = F_9 ( V_254 -> V_21 ) ;
V_252 = F_101 ( V_252 , V_259 , ( T_22 ) strlen ( V_254 -> V_21 ) ) ;
V_252 = F_102 ( V_252 , V_260 ) ;
F_103 ( V_254 , TRUE ) ;
}
static T_7 *
F_14 ( void ) {
const T_7 * V_259 ;
int V_253 ;
T_12 * V_252 ;
static const T_30 V_260 = 0 ;
T_6 * V_254 ;
T_17 V_256 ;
T_29 * V_257 , * V_258 ;
V_252 = F_104 ( FALSE , FALSE , 2 ) ;
V_259 = F_9 ( L_51 ) ;
V_252 = F_101 ( V_252 , V_259 , ( T_22 ) strlen ( L_51 ) ) ;
V_252 = F_102 ( V_252 , V_260 ) ;
V_259 = F_9 ( V_262 ) ;
V_252 = F_101 ( V_252 , V_259 , ( T_22 ) strlen ( V_262 ) ) ;
V_252 = F_102 ( V_252 , V_260 ) ;
V_259 = F_9 ( L_52 ) ;
V_252 = F_101 ( V_252 , V_259 , ( T_22 ) strlen ( L_52 ) ) ;
V_252 = F_102 ( V_252 , V_260 ) ;
V_254 = F_94 ( L_1 ) ;
V_257 = F_105 () ;
V_256 = '\0' ;
for ( V_258 = V_257 ; V_258 != NULL ;
V_258 = F_96 ( V_258 ) ) {
if ( V_256 != '\0' )
F_97 ( V_254 , V_256 ) ;
F_98 ( V_254 , L_49 , ( char * ) V_258 -> V_261 ) ;
V_256 = ';' ;
}
F_99 ( V_257 ) ;
V_259 = F_9 ( V_254 -> V_21 ) ;
V_252 = F_101 ( V_252 , V_259 , ( T_22 ) strlen ( V_254 -> V_21 ) ) ;
V_252 = F_102 ( V_252 , V_260 ) ;
for ( V_253 = 0 ; V_253 < F_106 () ; V_253 ++ ) {
F_93 ( V_252 , V_253 ) ;
}
V_252 = F_102 ( V_252 , V_260 ) ;
return ( T_7 * ) F_31 ( V_252 , FALSE ) ;
}
static void
F_107 ( T_12 * V_252 , int V_263 )
{
T_6 * V_254 = F_94 ( L_1 ) ;
T_6 * V_255 = F_94 ( L_1 ) ;
T_17 V_256 ;
T_29 * V_257 , * V_258 ;
const T_7 * V_259 ;
T_30 V_260 = 0 ;
V_257 = F_108 ( V_263 , TRUE ) ;
if ( V_257 == NULL ) {
F_17 ( V_254 , V_262 ) ;
} else {
F_17 ( V_254 , L_1 ) ;
V_256 = '\0' ;
for ( V_258 = V_257 ; V_258 != NULL ;
V_258 = F_96 ( V_258 ) ) {
if ( V_256 != '\0' )
F_97 ( V_254 , V_256 ) ;
F_98 ( V_254 , L_49 , ( char * ) V_258 -> V_261 ) ;
V_256 = ';' ;
}
F_99 ( V_257 ) ;
}
F_17 ( V_255 , L_50 , F_71 ( V_263 ) ,
V_254 -> V_21 ) ;
V_259 = F_9 ( V_255 -> V_21 ) ;
V_252 = F_101 ( V_252 , V_259 , ( T_22 ) strlen ( V_255 -> V_21 ) ) ;
V_252 = F_102 ( V_252 , V_260 ) ;
F_103 ( V_255 , TRUE ) ;
V_259 = F_9 ( V_254 -> V_21 ) ;
V_252 = F_101 ( V_252 , V_259 , ( T_22 ) strlen ( V_254 -> V_21 ) ) ;
V_252 = F_102 ( V_252 , V_260 ) ;
F_103 ( V_254 , TRUE ) ;
}
static T_7 *
F_26 ( T_12 * V_78 ) {
T_22 V_177 ;
int V_263 ;
T_12 * V_252 = F_104 ( FALSE , FALSE , 2 ) ;
T_30 V_260 = 0 ;
for ( V_177 = 0 ; V_177 < V_78 -> V_20 ; V_177 ++ ) {
V_263 = F_28 ( V_78 , int , V_177 ) ;
F_107 ( V_252 , V_263 ) ;
}
V_252 = F_102 ( V_252 , V_260 ) ;
return ( T_7 * ) F_31 ( V_252 , FALSE ) ;
}
static T_25 T_26
V_86 ( T_5 V_264 , T_27 V_224 , V_173 V_225 , V_85 V_226 ) {
T_5 V_158 ;
T_28 * V_227 = ( T_28 * ) V_226 ;
switch( V_224 ) {
case V_229 : {
V_11 * V_265 = ( V_11 * ) V_226 ;
T_9 * V_58 = ( T_9 * ) V_265 -> V_84 ;
V_87 = V_264 ;
V_154 = V_58 -> V_80 ;
V_158 = F_63 ( V_264 , V_266 ) ;
F_64 ( V_158 , V_171 , V_81 , 0 ) ;
break;
}
case V_250 :
V_158 = ( T_5 ) V_226 ;
switch ( V_225 ) {
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
case V_243 :
switch ( V_227 -> V_244 . V_245 ) {
case V_248 :
F_92 ( V_267 ) ;
break;
case V_246 : {
T_5 V_57 ;
char * V_130 ;
V_11 * V_265 = ( V_11 * ) V_227 -> V_268 ;
T_9 * V_58 = ( T_9 * ) V_265 -> V_84 ;
V_158 = F_63 ( V_264 , V_266 ) ;
if ( F_64 ( V_158 , V_160 , 0 , 0 ) == V_161 )
V_81 = TRUE ;
else
V_81 = FALSE ;
V_57 = F_90 ( V_264 ) ;
V_130 = F_18 ( V_227 -> V_268 -> V_33 ) ;
if ( F_109 ( V_58 -> V_269 , V_130 ) ) {
T_17 * V_21 = F_110 (
L_53
L_54 ,
V_130 ) ;
F_23 ( V_57 , F_9 ( V_21 ) , F_7 ( L_55 ) , V_270 | V_271 | V_272 ) ;
F_11 ( V_21 ) ;
F_111 ( V_264 , V_273 , 1L ) ;
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
V_88 ( T_5 V_264 , T_27 V_224 , V_173 V_225 , V_85 V_226 ) {
switch( V_224 ) {
case V_229 :
V_87 = V_264 ;
break;
case V_250 :
break;
case V_243 :
break;
default:
break;
}
return 0 ;
}
static T_25 T_26
V_92 ( T_5 V_264 , T_27 V_224 , V_173 V_225 , V_85 V_226 ) {
T_5 V_158 ;
T_28 * V_227 = ( T_28 * ) V_226 ;
switch( V_224 ) {
case V_229 : {
V_87 = V_264 ;
V_154 = V_91 -> V_80 ;
F_112 ( V_264 , V_90 ) ;
V_158 = F_63 ( V_264 , V_266 ) ;
F_64 ( V_158 , V_171 , V_81 , 0 ) ;
break;
}
case V_250 :
V_158 = ( T_5 ) V_226 ;
switch ( V_225 ) {
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
F_113 ( V_264 , V_158 , V_225 , V_90 ) ;
break;
}
break;
case V_243 :
switch ( V_227 -> V_244 . V_245 ) {
case V_248 :
F_92 ( V_267 ) ;
break;
case V_246 : {
T_5 V_57 ;
char * V_130 ;
V_11 * V_265 = ( V_11 * ) V_227 -> V_268 ;
T_9 * V_58 = ( T_9 * ) V_265 -> V_84 ;
V_158 = F_63 ( V_264 , V_266 ) ;
if ( F_64 ( V_158 , V_160 , 0 , 0 ) == V_161 )
V_81 = TRUE ;
else
V_81 = FALSE ;
V_57 = F_90 ( V_264 ) ;
V_130 = F_18 ( V_227 -> V_268 -> V_33 ) ;
if ( F_109 ( V_58 -> V_269 , V_130 ) ) {
T_17 * V_21 = F_110 (
L_53
L_54 ,
V_130 ) ;
F_23 ( V_57 , F_9 ( V_21 ) , F_7 ( L_55 ) , V_270 | V_271 | V_272 ) ;
F_11 ( V_21 ) ;
F_111 ( V_264 , V_273 , 1L ) ;
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
F_114 ( T_5 V_157 , T_13 * V_89 ) {
T_5 V_158 ;
T_1 V_274 = FALSE ;
T_7 V_275 [ V_276 ] ;
T_11 V_277 ;
T_10 V_278 = 0 , V_279 = 0 ;
T_10 V_280 ;
T_1 V_281 = TRUE ;
V_158 = F_63 ( V_157 , V_282 ) ;
if ( F_64 ( V_158 , V_160 , 0 , 0 ) == V_161 )
V_274 = TRUE ;
V_158 = F_63 ( V_157 , V_283 ) ;
F_65 ( V_158 , ! V_274 ) ;
if ( V_89 -> V_284 ) {
F_78 ( V_275 , V_276 , F_7 ( L_42 ) , V_91 -> V_285 - V_89 -> V_278 ) ;
} else {
F_78 ( V_275 , V_276 , F_7 ( L_42 ) , V_91 -> V_285 ) ;
}
F_68 ( V_158 , V_275 ) ;
V_158 = F_63 ( V_157 , V_286 ) ;
F_65 ( V_158 , V_274 ) ;
if ( V_89 -> V_287 )
V_280 = V_89 -> V_288 ;
else
V_280 = V_89 -> V_280 ;
if ( V_89 -> V_284 ) {
F_78 ( V_275 , V_276 , F_7 ( L_42 ) , V_280 - V_89 -> V_279 ) ;
} else {
F_78 ( V_275 , V_276 , F_7 ( L_42 ) , V_280 ) ;
}
F_68 ( V_158 , V_275 ) ;
V_277 = ( V_91 -> V_289 ) ? V_91 -> V_289 -> V_290 : 0 ;
V_158 = F_63 ( V_157 , V_291 ) ;
F_65 ( V_158 , V_277 && ! V_274 ) ;
if ( V_89 -> V_284 && V_91 -> V_289 && V_91 -> V_289 -> V_292 . V_293 ) {
F_78 ( V_275 , V_276 , F_7 ( L_56 ) ) ;
} else {
F_78 ( V_275 , V_276 , F_7 ( L_57 ) , V_277 ? 1 : 0 ) ;
}
F_68 ( V_158 , V_275 ) ;
V_158 = F_63 ( V_157 , V_294 ) ;
F_65 ( V_158 , V_277 && V_274 ) ;
if ( V_89 -> V_284 && V_91 -> V_289 && V_91 -> V_289 -> V_292 . V_293 ) {
F_78 ( V_275 , V_276 , F_7 ( L_56 ) ) ;
} else {
F_78 ( V_275 , V_276 , F_7 ( L_57 ) , V_277 ? 1 : 0 ) ;
}
F_68 ( V_158 , V_275 ) ;
V_158 = F_63 ( V_157 , V_295 ) ;
F_65 ( V_158 , V_91 -> V_296 ) ;
V_158 = F_63 ( V_157 , V_297 ) ;
F_65 ( V_158 , V_91 -> V_296 && ! V_274 ) ;
if ( V_89 -> V_284 ) {
F_78 ( V_275 , V_276 , F_7 ( L_42 ) , V_91 -> V_296 - V_89 -> V_298 ) ;
} else {
F_78 ( V_275 , V_276 , F_7 ( L_42 ) , V_91 -> V_296 ) ;
}
F_68 ( V_158 , V_275 ) ;
V_158 = F_63 ( V_157 , V_299 ) ;
F_65 ( V_158 , V_91 -> V_296 && V_274 ) ;
if ( V_89 -> V_284 ) {
F_78 ( V_275 , V_276 , F_7 ( L_42 ) , V_89 -> V_300 - V_89 -> V_301 ) ;
} else {
F_78 ( V_275 , V_276 , F_7 ( L_42 ) , V_89 -> V_300 ) ;
}
F_68 ( V_158 , V_275 ) ;
V_158 = F_63 ( V_157 , V_302 ) ;
F_65 ( V_158 , V_89 -> V_303 ) ;
V_158 = F_63 ( V_157 , V_304 ) ;
F_65 ( V_158 , V_89 -> V_303 && ! V_274 ) ;
if ( V_89 -> V_284 ) {
F_78 ( V_275 , V_276 , F_7 ( L_42 ) , V_89 -> V_303 - V_89 -> V_305 ) ;
} else {
F_78 ( V_275 , V_276 , F_7 ( L_42 ) , V_89 -> V_303 ) ;
}
F_68 ( V_158 , V_275 ) ;
V_158 = F_63 ( V_157 , V_306 ) ;
F_65 ( V_158 , V_89 -> V_307 && V_274 ) ;
if ( V_89 -> V_284 ) {
F_78 ( V_275 , V_276 , F_7 ( L_42 ) , V_89 -> V_307 - V_89 -> V_308 ) ;
} else {
F_78 ( V_275 , V_276 , F_7 ( L_42 ) , V_89 -> V_307 ) ;
}
F_68 ( V_158 , V_275 ) ;
switch ( F_115 ( V_89 ) ) {
case V_309 :
V_158 = F_63 ( V_157 , V_310 ) ;
F_64 ( V_158 , V_222 , ( V_173 ) 1 , V_223 ) ;
V_158 = F_63 ( V_157 , V_311 ) ;
F_65 ( V_158 , ! V_274 ) ;
if ( V_89 -> V_284 ) {
F_78 ( V_275 , V_276 , F_7 ( L_42 ) , V_89 -> V_312 - V_89 -> V_313 ) ;
} else {
F_78 ( V_275 , V_276 , F_7 ( L_42 ) , V_89 -> V_312 ) ;
}
F_68 ( V_158 , V_275 ) ;
V_158 = F_63 ( V_157 , V_314 ) ;
F_65 ( V_158 , V_274 ) ;
if ( V_89 -> V_284 ) {
F_78 ( V_275 , V_276 , F_7 ( L_42 ) , V_89 -> V_315 - V_89 -> V_316 ) ;
} else {
F_78 ( V_275 , V_276 , F_7 ( L_42 ) , V_89 -> V_315 ) ;
}
F_68 ( V_158 , V_275 ) ;
break;
case V_317 :
if ( V_89 -> V_318 == V_319 ) V_281 = FALSE ;
V_158 = F_63 ( V_157 , V_310 ) ;
F_64 ( V_158 , V_222 , 0 , F_89 ( 0xff , 0xcc , 0xcc ) ) ;
V_158 = F_63 ( V_157 , V_311 ) ;
F_68 ( V_158 , F_7 ( L_58 ) ) ;
V_158 = F_63 ( V_157 , V_314 ) ;
F_68 ( V_158 , F_7 ( L_34 ) ) ;
break;
case V_320 :
if ( V_89 -> V_318 == V_319 ) V_281 = FALSE ;
V_158 = F_63 ( V_157 , V_310 ) ;
F_64 ( V_158 , V_222 , 0 , F_89 ( 0xff , 0xcc , 0xcc ) ) ;
V_158 = F_63 ( V_157 , V_311 ) ;
F_68 ( V_158 , F_7 ( L_59 ) ) ;
V_158 = F_63 ( V_157 , V_314 ) ;
F_68 ( V_158 , F_7 ( L_34 ) ) ;
break;
default:
F_35 () ;
}
switch( V_89 -> V_318 ) {
case ( V_321 ) :
V_278 = V_89 -> V_278 ;
V_279 = V_89 -> V_279 ;
break;
case ( V_322 ) :
V_278 = ( V_91 -> V_289 && V_91 -> V_289 -> V_292 . V_293 ) ? 1 : 0 ;
V_279 = V_278 ;
break;
case ( V_323 ) :
V_278 = V_89 -> V_298 ;
V_279 = V_89 -> V_301 ;
break;
case ( V_324 ) :
V_278 = V_89 -> V_305 ;
V_279 = V_89 -> V_308 ;
break;
case ( V_319 ) :
V_278 = V_89 -> V_313 ;
V_279 = V_89 -> V_316 ;
break;
default:
F_35 () ;
}
V_158 = F_63 ( V_157 , V_325 ) ;
F_65 ( V_158 , V_278 ) ;
V_158 = F_63 ( V_157 , V_326 ) ;
F_65 ( V_158 , V_278 && ! V_274 ) ;
F_78 ( V_275 , V_276 , F_7 ( L_42 ) , V_278 ) ;
F_68 ( V_158 , V_275 ) ;
V_158 = F_63 ( V_157 , V_327 ) ;
F_65 ( V_158 , V_279 && V_274 ) ;
F_78 ( V_275 , V_276 , F_7 ( L_42 ) , V_279 ) ;
F_68 ( V_158 , V_275 ) ;
V_158 = F_63 ( F_90 ( V_157 ) , V_71 ) ;
F_65 ( V_158 , V_281 ) ;
}
static void
F_112 ( T_5 V_157 , T_13 * V_89 ) {
T_5 V_158 ;
if ( V_89 -> V_328 )
V_158 = F_63 ( V_157 , V_282 ) ;
else
V_158 = F_63 ( V_157 , V_329 ) ;
F_64 ( V_158 , V_171 , TRUE , 0 ) ;
if( V_89 -> V_330 != NULL ) {
char * V_331 ;
V_158 = F_63 ( V_157 , V_310 ) ;
V_331 = F_116 ( NULL , V_89 -> V_330 ) ;
F_68 ( V_158 , F_9 ( V_331 ) ) ;
F_117 ( NULL , V_331 ) ;
}
F_114 ( V_157 , V_89 ) ;
switch( V_89 -> V_318 ) {
case ( V_321 ) :
V_158 = F_63 ( V_157 , V_332 ) ;
break;
case ( V_322 ) :
V_158 = F_63 ( V_157 , V_333 ) ;
break;
case ( V_323 ) :
V_158 = F_63 ( V_157 , V_295 ) ;
break;
case ( V_324 ) :
V_158 = F_63 ( V_157 , V_302 ) ;
break;
case ( V_319 ) :
V_158 = F_63 ( V_157 , V_334 ) ;
break;
default:
F_35 () ;
}
F_64 ( V_158 , V_171 , TRUE , 0 ) ;
}
static void
F_113 ( T_5 V_157 , T_5 V_335 , V_173 V_225 , T_13 * V_89 ) {
T_5 V_158 ;
T_7 V_336 [ V_337 ] ;
if ( ! V_89 ) return;
switch( V_225 ) {
case ( V_338 << 16 ) | V_329 :
case ( V_338 << 16 ) | V_282 :
V_158 = F_63 ( V_157 , V_329 ) ;
if ( F_64 ( V_158 , V_160 , 0 , 0 ) == V_161 )
V_89 -> V_328 = FALSE ;
else
V_89 -> V_328 = TRUE ;
F_114 ( V_157 , V_89 ) ;
break;
case ( V_338 << 16 ) | V_332 :
if ( F_64 ( V_335 , V_160 , 0 , 0 ) == V_161 ) {
V_89 -> V_318 = V_321 ;
F_114 ( V_157 , V_89 ) ;
}
break;
case ( V_338 << 16 ) | V_333 :
if ( F_64 ( V_335 , V_160 , 0 , 0 ) == V_161 ) {
V_89 -> V_318 = V_322 ;
F_114 ( V_157 , V_89 ) ;
}
break;
case ( V_338 << 16 ) | V_295 :
if ( F_64 ( V_335 , V_160 , 0 , 0 ) == V_161 ) {
V_89 -> V_318 = V_323 ;
F_114 ( V_157 , V_89 ) ;
}
break;
case ( V_338 << 16 ) | V_302 :
if ( F_64 ( V_335 , V_160 , 0 , 0 ) == V_161 ) {
V_89 -> V_318 = V_324 ;
F_114 ( V_157 , V_89 ) ;
}
break;
case ( V_338 << 16 ) | V_334 :
if ( F_64 ( V_335 , V_160 , 0 , 0 ) == V_161 ) {
V_89 -> V_318 = V_319 ;
F_114 ( V_157 , V_89 ) ;
V_158 = F_63 ( V_157 , V_310 ) ;
F_118 ( V_158 ) ;
}
break;
case ( V_339 << 16 ) | V_310 :
V_158 = F_63 ( V_157 , V_334 ) ;
F_64 ( V_158 , V_340 , 0 , 0 ) ;
break;
case ( V_251 << 16 ) | V_310 :
F_64 ( V_335 , V_341 , ( V_173 ) V_337 , ( V_85 ) V_336 ) ;
F_119 ( V_89 , F_18 ( V_336 ) ) ;
F_114 ( V_157 , V_89 ) ;
break;
case ( V_338 << 16 ) | V_325 :
if ( F_64 ( V_335 , V_160 , 0 , 0 ) == V_161 ) {
V_89 -> V_284 = TRUE ;
} else {
V_89 -> V_284 = FALSE ;
}
F_114 ( V_157 , V_89 ) ;
break;
}
}
static T_25 T_26
V_95 ( T_5 V_342 , T_27 V_224 , V_173 V_225 , V_85 V_226 ) {
T_5 V_158 , V_57 ;
T_28 * V_227 = ( T_28 * ) V_226 ;
T_7 V_228 [ V_18 ] ;
switch( V_224 ) {
case V_229 :
if( V_22 != NULL ) {
V_158 = F_63 ( V_342 , V_230 ) ;
F_68 ( V_158 , F_9 ( V_22 ) ) ;
}
V_158 = F_63 ( V_342 , V_343 ) ;
F_64 ( V_158 , V_171 , TRUE , 0 ) ;
V_96 = V_97 ;
F_67 ( V_342 , NULL ) ;
break;
case V_243 :
switch ( V_227 -> V_244 . V_245 ) {
case V_246 :
V_158 = F_63 ( V_342 , V_230 ) ;
if ( V_22 )
F_11 ( V_22 ) ;
V_22 = F_80 ( V_158 ) ;
V_158 = F_63 ( V_342 , V_343 ) ;
if( F_64 ( V_158 , V_160 , 0 , 0 ) == V_161 ) {
V_96 = V_98 ;
} else {
V_158 = F_63 ( V_342 , V_344 ) ;
if( F_64 ( V_158 , V_160 , 0 , 0 ) == V_161 ) {
V_96 = V_99 ;
}
}
break;
case V_247 :
V_57 = F_90 ( V_342 ) ;
F_91 ( V_57 , V_228 , V_18 ) ;
F_67 ( V_342 , F_18 ( V_228 ) ) ;
break;
case V_248 :
F_92 ( V_345 ) ;
break;
default:
break;
}
break;
case V_250 :
V_158 = ( T_5 ) V_226 ;
switch( V_225 ) {
case ( V_251 << 16 ) | V_230 :
F_85 ( V_158 , NULL ) ;
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
V_104 ( T_5 V_346 , T_27 V_224 , V_173 V_225 , V_85 V_226 ) {
T_5 V_158 ;
T_28 * V_227 = ( T_28 * ) V_226 ;
T_1 V_347 ;
int V_177 , V_348 ;
switch( V_224 ) {
case V_229 : {
V_11 * V_265 = ( V_11 * ) V_226 ;
T_9 * V_58 = ( T_9 * ) V_265 -> V_84 ;
F_120 ( & V_105 . V_89 , V_58 ) ;
V_105 . V_89 . V_328 = TRUE ;
F_112 ( V_346 , & V_105 . V_89 ) ;
F_66 ( V_346 , & V_105 ) ;
break;
}
case V_250 :
V_158 = ( T_5 ) V_226 ;
switch ( V_225 ) {
case ( V_349 << 16 ) | V_164 :
default:
F_113 ( V_346 , V_158 , V_225 , & V_105 . V_89 ) ;
F_62 ( V_346 , & V_105 ) ;
break;
}
break;
case V_243 :
switch ( V_227 -> V_244 . V_245 ) {
case V_246 :
break;
case V_350 :
V_348 = V_227 -> V_268 -> V_31 ;
if ( V_348 == 2 )
V_105 . V_106 = V_107 ;
else
V_105 . V_106 = V_351 ;
if ( V_348 == 3 || V_348 == 4 || V_348 == 5 || V_348 == 6 )
V_347 = FALSE ;
else
V_347 = TRUE ;
for ( V_177 = V_352 ; V_177 <= V_170 ; V_177 ++ ) {
V_158 = F_63 ( V_346 , V_177 ) ;
F_65 ( V_158 , V_347 ) ;
}
break;
case V_248 :
F_92 ( V_353 ) ;
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
V_138 ( T_5 V_346 , T_27 V_224 , V_173 V_225 , V_85 V_226 ) {
T_5 V_158 ;
V_11 * V_265 = ( V_11 * ) V_226 ;
T_7 V_354 [ V_276 ] ;
T_28 * V_227 = ( T_28 * ) V_226 ;
switch( V_224 ) {
case V_229 :
F_78 ( V_354 , V_276 , F_7 ( L_60 ) ,
V_265 -> V_84 , F_9 ( F_121 ( V_265 -> V_84 , L_1 , L_61 ) ) ) ;
V_158 = F_63 ( V_346 , V_355 ) ;
F_68 ( V_158 , V_354 ) ;
break;
case V_243 :
switch ( V_227 -> V_244 . V_245 ) {
case V_248 :
F_92 ( V_356 ) ;
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
V_149 ( T_5 V_346 , T_27 V_224 , V_173 V_225 , V_85 V_226 ) {
T_5 V_158 ;
V_11 * V_265 = ( V_11 * ) V_226 ;
T_7 V_357 [ V_276 ] ;
T_28 * V_227 = ( T_28 * ) V_226 ;
switch( V_224 ) {
case V_229 :
F_78 ( V_357 , V_276 , F_7 ( L_62 ) ,
V_265 -> V_84 , F_9 ( F_121 ( V_265 -> V_84 , L_1 , L_61 ) ) ) ;
V_158 = F_63 ( V_346 , V_358 ) ;
F_68 ( V_158 , V_357 ) ;
break;
case V_243 :
switch ( V_227 -> V_244 . V_245 ) {
case V_248 :
F_92 ( V_356 ) ;
break;
default:
break;
}
default:
break;
}
return 0 ;
}
