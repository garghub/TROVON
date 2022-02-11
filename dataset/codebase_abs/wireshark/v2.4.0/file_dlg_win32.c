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
V_105 . V_116 = NULL ;
if ( F_27 ( V_16 ) ) {
V_105 . V_117 = F_18 ( V_14 ) ;
switch ( V_16 -> V_31 ) {
case V_118 :
V_105 . V_116 = F_37 ( TRUE , V_105 . V_117 ) ;
if ( V_105 . V_116 == NULL ) {
F_38 ( V_105 . V_117 , V_119 , TRUE ) ;
F_11 ( ( void * ) V_16 ) ;
return;
}
V_102 = F_39 ( V_58 , & V_105 , TRUE ) ;
break;
case V_120 :
V_105 . V_116 = F_40 ( TRUE , V_105 . V_117 ) ;
if ( V_105 . V_116 == NULL ) {
F_38 ( V_105 . V_117 , V_119 , TRUE ) ;
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
F_38 ( V_105 . V_117 , V_119 , TRUE ) ;
break;
case V_128 :
F_46 ( V_105 . V_117 , V_119 ) ;
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
T_7 V_185 [ V_184 ] ;
T_21 V_186 ;
T_22 V_187 = 0 ;
T_21 V_188 ;
T_17 * V_189 ;
T_23 V_190 ;
struct V_191 * V_192 ;
T_22 V_193 ;
T_23 V_194 ;
T_23 V_195 ;
double V_196 = 0 ;
double V_197 = 0 ;
double V_198 ;
T_1 V_199 = FALSE ;
for ( V_177 = V_200 ; V_177 <= V_201 ; V_177 ++ ) {
V_158 = F_63 ( V_175 , V_177 ) ;
if ( V_158 ) {
F_65 ( V_158 , FALSE ) ;
}
}
for ( V_177 = V_200 ; V_177 <= V_201 ; V_177 ++ ) {
V_158 = F_63 ( V_175 , V_177 ) ;
if ( V_158 ) {
F_68 ( V_158 , F_7 ( L_34 ) ) ;
}
}
if ( V_176 == NULL || strlen ( V_176 ) < 1 ) {
return FALSE ;
}
V_158 = F_63 ( V_175 , V_200 ) ;
if ( F_69 ( V_176 ) == V_202 ) {
F_68 ( V_158 , F_7 ( L_35 ) ) ;
return FALSE ;
}
V_178 = F_70 ( V_176 , V_203 , & V_181 , & V_182 , TRUE ) ;
if ( V_158 && V_178 == NULL ) {
if( V_181 == V_204 ) {
F_68 ( V_158 , F_7 ( L_36 ) ) ;
} else {
F_68 ( V_158 , F_7 ( L_37 ) ) ;
}
return FALSE ;
}
for ( V_177 = V_205 ; V_177 <= V_201 ; V_177 ++ ) {
V_158 = F_63 ( V_175 , V_177 ) ;
if ( V_158 ) {
F_65 ( V_158 , TRUE ) ;
}
}
V_158 = F_63 ( V_175 , V_200 ) ;
F_68 ( V_158 , F_9 ( F_71 ( F_72 ( V_178 ) ) ) ) ;
V_188 = F_73 ( V_178 , & V_181 ) ;
V_189 = F_74 ( V_188 , V_206 | V_207 ) ;
time ( & V_194 ) ;
while ( ( F_75 ( V_178 , & V_181 , & V_182 , & V_186 ) ) ) {
V_180 = F_76 ( V_178 ) ;
V_198 = F_77 ( ( const V_208 * ) & V_180 -> V_209 ) ;
if( V_187 == 0 ) {
V_196 = V_198 ;
V_197 = V_198 ;
}
if ( V_198 < V_196 ) {
V_196 = V_198 ;
}
if ( V_198 > V_197 ) {
V_197 = V_198 ;
}
V_187 ++ ;
if( V_187 % 100 == 0 ) {
time ( & V_195 ) ;
if( V_195 - V_194 >= ( T_23 ) V_37 . V_210 ) {
V_199 = TRUE ;
break;
}
}
}
if( V_181 != 0 ) {
F_78 ( V_183 , V_184 , L_38 ,
V_189 , V_187 ) ;
F_11 ( V_189 ) ;
V_158 = F_63 ( V_175 , V_211 ) ;
F_68 ( V_158 , V_183 ) ;
F_79 ( V_178 ) ;
return TRUE ;
}
if( V_199 ) {
F_78 ( V_183 , V_184 , L_39 ,
V_189 , V_187 ) ;
} else {
F_78 ( V_183 , V_184 , L_40 ,
V_189 , V_187 ) ;
}
F_11 ( V_189 ) ;
V_158 = F_63 ( V_175 , V_211 ) ;
F_68 ( V_158 , V_183 ) ;
V_190 = ( long ) V_196 ;
V_192 = localtime ( & V_190 ) ;
if( V_192 ) {
F_80 ( V_185 , V_184 ,
F_7 ( L_41 ) ,
V_192 -> V_212 + 1900 ,
V_192 -> V_213 + 1 ,
V_192 -> V_214 ,
V_192 -> V_215 ,
V_192 -> V_216 ,
V_192 -> V_217 ) ;
} else {
F_80 ( V_185 , V_184 , F_7 ( L_42 ) ) ;
}
V_193 = ( unsigned int ) ( V_197 - V_196 ) ;
if( V_193 / 86400 ) {
F_80 ( V_183 , V_184 , F_7 ( L_43 ) ,
V_185 , V_193 / 86400 , V_193 % 86400 / 3600 , V_193 % 3600 / 60 , V_193 % 60 ) ;
} else {
F_80 ( V_183 , V_184 , F_7 ( L_44 ) ,
V_185 , V_193 % 86400 / 3600 , V_193 % 3600 / 60 , V_193 % 60 ) ;
}
if( V_199 ) {
F_80 ( V_183 , V_184 , F_7 ( L_45 ) , V_185 ) ;
}
V_158 = F_63 ( V_175 , V_201 ) ;
F_68 ( V_158 , V_183 ) ;
F_79 ( V_178 ) ;
return TRUE ;
}
static char *
F_81 ( T_5 V_218 ) {
T_7 * V_219 = NULL ;
T_11 V_20 ;
char * V_220 ;
V_20 = F_82 ( V_218 ) ;
if ( V_20 > 0 ) {
V_20 ++ ;
V_219 = F_83 ( V_20 * sizeof( T_7 ) ) ;
V_20 = F_84 ( V_218 , V_219 , V_20 ) ;
V_220 = F_85 ( V_219 , - 1 , NULL , NULL , NULL ) ;
F_11 ( V_219 ) ;
return V_220 ;
} else {
return NULL ;
}
}
static void
F_86 ( T_5 V_218 , T_7 * V_221 ) {
T_7 * V_219 = NULL ;
T_11 V_20 ;
T_24 * V_222 ;
if ( V_221 ) {
V_20 = ( F_87 ( V_221 ) + 1 ) * sizeof( T_7 ) ;
V_219 = F_83 ( V_20 ) ;
memcpy ( V_219 , V_221 , V_20 ) ;
} else {
V_20 = F_82 ( V_218 ) ;
if ( V_20 > 0 ) {
V_20 ++ ;
V_219 = F_83 ( V_20 * sizeof( T_7 ) ) ;
V_20 = F_84 ( V_218 , V_219 , V_20 ) ;
}
}
if ( V_20 == 0 ) {
F_64 ( V_218 , V_223 , ( V_173 ) 1 , V_224 ) ;
return;
} else if ( F_88 ( F_18 ( V_219 ) , & V_222 , NULL ) ) {
if ( V_222 != NULL )
F_89 ( V_222 ) ;
F_64 ( V_218 , V_223 , 0 , F_90 ( 0xe4 , 0xff , 0xc7 ) ) ;
} else {
F_64 ( V_218 , V_223 , 0 , F_90 ( 0xff , 0xcc , 0xcc ) ) ;
}
if ( V_219 ) F_11 ( V_219 ) ;
}
static T_25 T_26
V_54 ( T_5 V_175 , T_27 V_225 , V_173 V_226 , V_85 V_227 ) {
T_5 V_158 , V_57 ;
T_28 * V_228 = ( T_28 * ) V_227 ;
T_7 V_229 [ V_18 ] ;
T_11 V_177 ;
switch( V_225 ) {
case V_230 :
if( V_22 != NULL ) {
V_158 = F_63 ( V_175 , V_231 ) ;
F_68 ( V_158 , F_9 ( V_22 ) ) ;
}
V_158 = F_63 ( V_175 , V_232 ) ;
F_64 ( V_158 , V_172 , 0 , ( V_173 ) F_7 ( L_46 ) ) ;
for ( V_177 = 0 ; V_233 [ V_177 ] . V_234 != NULL ; V_177 += 1 ) {
F_64 ( V_158 , V_172 , 0 , ( V_173 ) F_9 ( V_233 [ V_177 ] . V_234 ) ) ;
}
F_64 ( V_158 , V_174 , 0 , 0 ) ;
F_67 ( V_175 , NULL ) ;
break;
case V_235 :
switch ( V_228 -> V_236 . V_237 ) {
case V_238 :
V_158 = F_63 ( V_175 , V_231 ) ;
if ( V_22 )
F_11 ( V_22 ) ;
V_22 = F_81 ( V_158 ) ;
V_158 = F_63 ( V_175 , V_232 ) ;
V_56 = ( unsigned int ) F_64 ( V_158 , V_165 , 0 , 0 ) ;
break;
case V_239 :
V_57 = F_91 ( V_175 ) ;
F_92 ( V_57 , V_229 , V_18 ) ;
F_67 ( V_175 , F_18 ( V_229 ) ) ;
break;
case V_240 :
F_93 ( V_241 ) ;
break;
default:
break;
}
break;
case V_242 :
V_158 = ( T_5 ) V_227 ;
switch( V_226 ) {
case ( V_243 << 16 ) | V_231 :
F_86 ( V_158 , NULL ) ;
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
F_94 ( T_12 * V_244 , int V_245 )
{
T_6 * V_246 = F_95 ( L_1 ) ;
T_6 * V_247 = F_95 ( L_1 ) ;
T_17 V_248 ;
T_29 * V_249 , * V_250 ;
const T_7 * V_251 ;
T_30 V_252 = 0 ;
V_249 = F_96 ( V_245 ) ;
F_17 ( V_246 , L_1 ) ;
V_248 = '\0' ;
for ( V_250 = V_249 ; V_250 != NULL ;
V_250 = F_97 ( V_250 ) ) {
if ( V_248 != '\0' )
F_98 ( V_246 , V_248 ) ;
F_99 ( V_246 , L_47 , ( char * ) V_250 -> V_253 ) ;
V_248 = ';' ;
}
F_100 ( V_249 ) ;
F_17 ( V_247 , L_48 ,
F_101 ( V_245 ) ,
V_246 -> V_21 ) ;
V_251 = F_9 ( V_247 -> V_21 ) ;
V_244 = F_102 ( V_244 , V_251 , ( T_22 ) strlen ( V_247 -> V_21 ) ) ;
V_244 = F_103 ( V_244 , V_252 ) ;
F_104 ( V_247 , TRUE ) ;
V_251 = F_9 ( V_246 -> V_21 ) ;
V_244 = F_102 ( V_244 , V_251 , ( T_22 ) strlen ( V_246 -> V_21 ) ) ;
V_244 = F_103 ( V_244 , V_252 ) ;
F_104 ( V_246 , TRUE ) ;
}
static T_7 *
F_14 ( void ) {
const T_7 * V_251 ;
int V_245 ;
T_12 * V_244 ;
static const T_30 V_252 = 0 ;
T_6 * V_246 ;
T_17 V_248 ;
T_29 * V_249 , * V_250 ;
V_244 = F_105 ( FALSE , FALSE , 2 ) ;
V_251 = F_9 ( L_49 ) ;
V_244 = F_102 ( V_244 , V_251 , ( T_22 ) strlen ( L_49 ) ) ;
V_244 = F_103 ( V_244 , V_252 ) ;
V_251 = F_9 ( V_254 ) ;
V_244 = F_102 ( V_244 , V_251 , ( T_22 ) strlen ( V_254 ) ) ;
V_244 = F_103 ( V_244 , V_252 ) ;
V_251 = F_9 ( L_50 ) ;
V_244 = F_102 ( V_244 , V_251 , ( T_22 ) strlen ( L_50 ) ) ;
V_244 = F_103 ( V_244 , V_252 ) ;
V_246 = F_95 ( L_1 ) ;
V_249 = F_106 () ;
V_248 = '\0' ;
for ( V_250 = V_249 ; V_250 != NULL ;
V_250 = F_97 ( V_250 ) ) {
if ( V_248 != '\0' )
F_98 ( V_246 , V_248 ) ;
F_99 ( V_246 , L_47 , ( char * ) V_250 -> V_253 ) ;
V_248 = ';' ;
}
F_100 ( V_249 ) ;
V_251 = F_9 ( V_246 -> V_21 ) ;
V_244 = F_102 ( V_244 , V_251 , ( T_22 ) strlen ( V_246 -> V_21 ) ) ;
V_244 = F_103 ( V_244 , V_252 ) ;
for ( V_245 = 0 ; V_245 < F_107 () ; V_245 ++ ) {
F_94 ( V_244 , V_245 ) ;
}
V_244 = F_103 ( V_244 , V_252 ) ;
return ( T_7 * ) F_31 ( V_244 , FALSE ) ;
}
static void
F_108 ( T_12 * V_244 , int V_255 )
{
T_6 * V_246 = F_95 ( L_1 ) ;
T_6 * V_247 = F_95 ( L_1 ) ;
T_17 V_248 ;
T_29 * V_249 , * V_250 ;
const T_7 * V_251 ;
T_30 V_252 = 0 ;
V_249 = F_109 ( V_255 , TRUE ) ;
if ( V_249 == NULL ) {
F_17 ( V_246 , V_254 ) ;
} else {
F_17 ( V_246 , L_1 ) ;
V_248 = '\0' ;
for ( V_250 = V_249 ; V_250 != NULL ;
V_250 = F_97 ( V_250 ) ) {
if ( V_248 != '\0' )
F_98 ( V_246 , V_248 ) ;
F_99 ( V_246 , L_47 , ( char * ) V_250 -> V_253 ) ;
V_248 = ';' ;
}
F_100 ( V_249 ) ;
}
F_17 ( V_247 , L_48 , F_71 ( V_255 ) ,
V_246 -> V_21 ) ;
V_251 = F_9 ( V_247 -> V_21 ) ;
V_244 = F_102 ( V_244 , V_251 , ( T_22 ) strlen ( V_247 -> V_21 ) ) ;
V_244 = F_103 ( V_244 , V_252 ) ;
F_104 ( V_247 , TRUE ) ;
V_251 = F_9 ( V_246 -> V_21 ) ;
V_244 = F_102 ( V_244 , V_251 , ( T_22 ) strlen ( V_246 -> V_21 ) ) ;
V_244 = F_103 ( V_244 , V_252 ) ;
F_104 ( V_246 , TRUE ) ;
}
static T_7 *
F_26 ( T_12 * V_78 ) {
T_22 V_177 ;
int V_255 ;
T_12 * V_244 = F_105 ( FALSE , FALSE , 2 ) ;
T_30 V_252 = 0 ;
for ( V_177 = 0 ; V_177 < V_78 -> V_20 ; V_177 ++ ) {
V_255 = F_28 ( V_78 , int , V_177 ) ;
F_108 ( V_244 , V_255 ) ;
}
V_244 = F_103 ( V_244 , V_252 ) ;
return ( T_7 * ) F_31 ( V_244 , FALSE ) ;
}
static T_25 T_26
V_86 ( T_5 V_256 , T_27 V_225 , V_173 V_226 , V_85 V_227 ) {
T_5 V_158 ;
T_28 * V_228 = ( T_28 * ) V_227 ;
switch( V_225 ) {
case V_230 : {
V_11 * V_257 = ( V_11 * ) V_227 ;
T_9 * V_58 = ( T_9 * ) V_257 -> V_84 ;
V_87 = V_256 ;
V_154 = V_58 -> V_80 ;
V_158 = F_63 ( V_256 , V_258 ) ;
F_64 ( V_158 , V_171 , V_81 , 0 ) ;
break;
}
case V_242 :
V_158 = ( T_5 ) V_227 ;
switch ( V_226 ) {
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
case V_235 :
switch ( V_228 -> V_236 . V_237 ) {
case V_240 :
F_93 ( V_259 ) ;
break;
case V_238 : {
T_5 V_57 ;
char * V_130 ;
V_11 * V_257 = ( V_11 * ) V_228 -> V_260 ;
T_9 * V_58 = ( T_9 * ) V_257 -> V_84 ;
V_158 = F_63 ( V_256 , V_258 ) ;
if ( F_64 ( V_158 , V_160 , 0 , 0 ) == V_161 )
V_81 = TRUE ;
else
V_81 = FALSE ;
V_57 = F_91 ( V_256 ) ;
V_130 = F_18 ( V_228 -> V_260 -> V_33 ) ;
if ( F_110 ( V_58 -> V_261 , V_130 ) ) {
T_17 * V_21 = F_111 (
L_51
L_52 ,
V_130 ) ;
F_23 ( V_57 , F_9 ( V_21 ) , F_7 ( L_53 ) , V_262 | V_263 | V_264 ) ;
F_11 ( V_21 ) ;
F_112 ( V_256 , V_265 , 1L ) ;
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
V_88 ( T_5 V_256 , T_27 V_225 , V_173 V_226 , V_85 V_227 ) {
switch( V_225 ) {
case V_230 :
V_87 = V_256 ;
break;
case V_242 :
break;
case V_235 :
break;
default:
break;
}
return 0 ;
}
static T_25 T_26
V_92 ( T_5 V_256 , T_27 V_225 , V_173 V_226 , V_85 V_227 ) {
T_5 V_158 ;
T_28 * V_228 = ( T_28 * ) V_227 ;
switch( V_225 ) {
case V_230 : {
V_87 = V_256 ;
V_154 = V_91 -> V_80 ;
F_113 ( V_256 , V_90 ) ;
V_158 = F_63 ( V_256 , V_258 ) ;
F_64 ( V_158 , V_171 , V_81 , 0 ) ;
break;
}
case V_242 :
V_158 = ( T_5 ) V_227 ;
switch ( V_226 ) {
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
F_114 ( V_256 , V_158 , V_226 , V_90 ) ;
break;
}
break;
case V_235 :
switch ( V_228 -> V_236 . V_237 ) {
case V_240 :
F_93 ( V_259 ) ;
break;
case V_238 : {
T_5 V_57 ;
char * V_130 ;
V_11 * V_257 = ( V_11 * ) V_228 -> V_260 ;
T_9 * V_58 = ( T_9 * ) V_257 -> V_84 ;
V_158 = F_63 ( V_256 , V_258 ) ;
if ( F_64 ( V_158 , V_160 , 0 , 0 ) == V_161 )
V_81 = TRUE ;
else
V_81 = FALSE ;
V_57 = F_91 ( V_256 ) ;
V_130 = F_18 ( V_228 -> V_260 -> V_33 ) ;
if ( F_110 ( V_58 -> V_261 , V_130 ) ) {
T_17 * V_21 = F_111 (
L_51
L_52 ,
V_130 ) ;
F_23 ( V_57 , F_9 ( V_21 ) , F_7 ( L_53 ) , V_262 | V_263 | V_264 ) ;
F_11 ( V_21 ) ;
F_112 ( V_256 , V_265 , 1L ) ;
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
F_115 ( T_5 V_157 , T_13 * V_89 ) {
T_5 V_158 ;
T_1 V_266 = FALSE ;
T_7 V_267 [ V_268 ] ;
T_11 V_269 ;
T_10 V_270 = 0 , V_271 = 0 ;
T_10 V_272 ;
T_1 V_273 = TRUE ;
V_158 = F_63 ( V_157 , V_274 ) ;
if ( F_64 ( V_158 , V_160 , 0 , 0 ) == V_161 )
V_266 = TRUE ;
V_158 = F_63 ( V_157 , V_275 ) ;
F_65 ( V_158 , ! V_266 ) ;
if ( V_89 -> V_276 ) {
F_80 ( V_267 , V_268 , F_7 ( L_54 ) , V_91 -> V_277 - V_89 -> V_270 ) ;
} else {
F_80 ( V_267 , V_268 , F_7 ( L_54 ) , V_91 -> V_277 ) ;
}
F_68 ( V_158 , V_267 ) ;
V_158 = F_63 ( V_157 , V_278 ) ;
F_65 ( V_158 , V_266 ) ;
if ( V_89 -> V_279 )
V_272 = V_89 -> V_280 ;
else
V_272 = V_89 -> V_272 ;
if ( V_89 -> V_276 ) {
F_80 ( V_267 , V_268 , F_7 ( L_54 ) , V_272 - V_89 -> V_271 ) ;
} else {
F_80 ( V_267 , V_268 , F_7 ( L_54 ) , V_272 ) ;
}
F_68 ( V_158 , V_267 ) ;
V_269 = ( V_91 -> V_281 ) ? V_91 -> V_281 -> V_282 : 0 ;
V_158 = F_63 ( V_157 , V_283 ) ;
F_65 ( V_158 , V_269 && ! V_266 ) ;
if ( V_89 -> V_276 && V_91 -> V_281 && V_91 -> V_281 -> V_284 . V_285 ) {
F_80 ( V_267 , V_268 , F_7 ( L_55 ) ) ;
} else {
F_80 ( V_267 , V_268 , F_7 ( L_56 ) , V_269 ? 1 : 0 ) ;
}
F_68 ( V_158 , V_267 ) ;
V_158 = F_63 ( V_157 , V_286 ) ;
F_65 ( V_158 , V_269 && V_266 ) ;
if ( V_89 -> V_276 && V_91 -> V_281 && V_91 -> V_281 -> V_284 . V_285 ) {
F_80 ( V_267 , V_268 , F_7 ( L_55 ) ) ;
} else {
F_80 ( V_267 , V_268 , F_7 ( L_56 ) , V_269 ? 1 : 0 ) ;
}
F_68 ( V_158 , V_267 ) ;
V_158 = F_63 ( V_157 , V_287 ) ;
F_65 ( V_158 , V_91 -> V_288 ) ;
V_158 = F_63 ( V_157 , V_289 ) ;
F_65 ( V_158 , V_91 -> V_288 && ! V_266 ) ;
if ( V_89 -> V_276 ) {
F_80 ( V_267 , V_268 , F_7 ( L_54 ) , V_91 -> V_288 - V_89 -> V_290 ) ;
} else {
F_80 ( V_267 , V_268 , F_7 ( L_54 ) , V_91 -> V_288 ) ;
}
F_68 ( V_158 , V_267 ) ;
V_158 = F_63 ( V_157 , V_291 ) ;
F_65 ( V_158 , V_91 -> V_288 && V_266 ) ;
if ( V_89 -> V_276 ) {
F_80 ( V_267 , V_268 , F_7 ( L_54 ) , V_89 -> V_292 - V_89 -> V_293 ) ;
} else {
F_80 ( V_267 , V_268 , F_7 ( L_54 ) , V_89 -> V_292 ) ;
}
F_68 ( V_158 , V_267 ) ;
V_158 = F_63 ( V_157 , V_294 ) ;
F_65 ( V_158 , V_89 -> V_295 ) ;
V_158 = F_63 ( V_157 , V_296 ) ;
F_65 ( V_158 , V_89 -> V_295 && ! V_266 ) ;
if ( V_89 -> V_276 ) {
F_80 ( V_267 , V_268 , F_7 ( L_54 ) , V_89 -> V_295 - V_89 -> V_297 ) ;
} else {
F_80 ( V_267 , V_268 , F_7 ( L_54 ) , V_89 -> V_295 ) ;
}
F_68 ( V_158 , V_267 ) ;
V_158 = F_63 ( V_157 , V_298 ) ;
F_65 ( V_158 , V_89 -> V_299 && V_266 ) ;
if ( V_89 -> V_276 ) {
F_80 ( V_267 , V_268 , F_7 ( L_54 ) , V_89 -> V_299 - V_89 -> V_300 ) ;
} else {
F_80 ( V_267 , V_268 , F_7 ( L_54 ) , V_89 -> V_299 ) ;
}
F_68 ( V_158 , V_267 ) ;
switch ( F_116 ( V_89 ) ) {
case V_301 :
V_158 = F_63 ( V_157 , V_302 ) ;
F_64 ( V_158 , V_223 , ( V_173 ) 1 , V_224 ) ;
V_158 = F_63 ( V_157 , V_303 ) ;
F_65 ( V_158 , ! V_266 ) ;
if ( V_89 -> V_276 ) {
F_80 ( V_267 , V_268 , F_7 ( L_54 ) , V_89 -> V_304 - V_89 -> V_305 ) ;
} else {
F_80 ( V_267 , V_268 , F_7 ( L_54 ) , V_89 -> V_304 ) ;
}
F_68 ( V_158 , V_267 ) ;
V_158 = F_63 ( V_157 , V_306 ) ;
F_65 ( V_158 , V_266 ) ;
if ( V_89 -> V_276 ) {
F_80 ( V_267 , V_268 , F_7 ( L_54 ) , V_89 -> V_307 - V_89 -> V_308 ) ;
} else {
F_80 ( V_267 , V_268 , F_7 ( L_54 ) , V_89 -> V_307 ) ;
}
F_68 ( V_158 , V_267 ) ;
break;
case V_309 :
if ( V_89 -> V_310 == V_311 ) V_273 = FALSE ;
V_158 = F_63 ( V_157 , V_302 ) ;
F_64 ( V_158 , V_223 , 0 , F_90 ( 0xff , 0xcc , 0xcc ) ) ;
V_158 = F_63 ( V_157 , V_303 ) ;
F_68 ( V_158 , F_7 ( L_57 ) ) ;
V_158 = F_63 ( V_157 , V_306 ) ;
F_68 ( V_158 , F_7 ( L_34 ) ) ;
break;
case V_312 :
if ( V_89 -> V_310 == V_311 ) V_273 = FALSE ;
V_158 = F_63 ( V_157 , V_302 ) ;
F_64 ( V_158 , V_223 , 0 , F_90 ( 0xff , 0xcc , 0xcc ) ) ;
V_158 = F_63 ( V_157 , V_303 ) ;
F_68 ( V_158 , F_7 ( L_58 ) ) ;
V_158 = F_63 ( V_157 , V_306 ) ;
F_68 ( V_158 , F_7 ( L_34 ) ) ;
break;
default:
F_35 () ;
}
switch( V_89 -> V_310 ) {
case ( V_313 ) :
V_270 = V_89 -> V_270 ;
V_271 = V_89 -> V_271 ;
break;
case ( V_314 ) :
V_270 = ( V_91 -> V_281 && V_91 -> V_281 -> V_284 . V_285 ) ? 1 : 0 ;
V_271 = V_270 ;
break;
case ( V_315 ) :
V_270 = V_89 -> V_290 ;
V_271 = V_89 -> V_293 ;
break;
case ( V_316 ) :
V_270 = V_89 -> V_297 ;
V_271 = V_89 -> V_300 ;
break;
case ( V_311 ) :
V_270 = V_89 -> V_305 ;
V_271 = V_89 -> V_308 ;
break;
default:
F_35 () ;
}
V_158 = F_63 ( V_157 , V_317 ) ;
F_65 ( V_158 , V_270 ) ;
V_158 = F_63 ( V_157 , V_318 ) ;
F_65 ( V_158 , V_270 && ! V_266 ) ;
F_80 ( V_267 , V_268 , F_7 ( L_54 ) , V_270 ) ;
F_68 ( V_158 , V_267 ) ;
V_158 = F_63 ( V_157 , V_319 ) ;
F_65 ( V_158 , V_271 && V_266 ) ;
F_80 ( V_267 , V_268 , F_7 ( L_54 ) , V_271 ) ;
F_68 ( V_158 , V_267 ) ;
V_158 = F_63 ( F_91 ( V_157 ) , V_71 ) ;
F_65 ( V_158 , V_273 ) ;
}
static void
F_113 ( T_5 V_157 , T_13 * V_89 ) {
T_5 V_158 ;
if ( V_89 -> V_320 )
V_158 = F_63 ( V_157 , V_274 ) ;
else
V_158 = F_63 ( V_157 , V_321 ) ;
F_64 ( V_158 , V_171 , TRUE , 0 ) ;
if( V_89 -> V_322 != NULL ) {
char * V_323 ;
V_158 = F_63 ( V_157 , V_302 ) ;
V_323 = F_117 ( NULL , V_89 -> V_322 ) ;
F_68 ( V_158 , F_9 ( V_323 ) ) ;
F_118 ( NULL , V_323 ) ;
}
F_115 ( V_157 , V_89 ) ;
switch( V_89 -> V_310 ) {
case ( V_313 ) :
V_158 = F_63 ( V_157 , V_324 ) ;
break;
case ( V_314 ) :
V_158 = F_63 ( V_157 , V_325 ) ;
break;
case ( V_315 ) :
V_158 = F_63 ( V_157 , V_287 ) ;
break;
case ( V_316 ) :
V_158 = F_63 ( V_157 , V_294 ) ;
break;
case ( V_311 ) :
V_158 = F_63 ( V_157 , V_326 ) ;
break;
default:
F_35 () ;
}
F_64 ( V_158 , V_171 , TRUE , 0 ) ;
}
static void
F_114 ( T_5 V_157 , T_5 V_327 , V_173 V_226 , T_13 * V_89 ) {
T_5 V_158 ;
T_7 V_328 [ V_329 ] ;
if ( ! V_89 ) return;
switch( V_226 ) {
case ( V_330 << 16 ) | V_321 :
case ( V_330 << 16 ) | V_274 :
V_158 = F_63 ( V_157 , V_321 ) ;
if ( F_64 ( V_158 , V_160 , 0 , 0 ) == V_161 )
V_89 -> V_320 = FALSE ;
else
V_89 -> V_320 = TRUE ;
F_115 ( V_157 , V_89 ) ;
break;
case ( V_330 << 16 ) | V_324 :
if ( F_64 ( V_327 , V_160 , 0 , 0 ) == V_161 ) {
V_89 -> V_310 = V_313 ;
F_115 ( V_157 , V_89 ) ;
}
break;
case ( V_330 << 16 ) | V_325 :
if ( F_64 ( V_327 , V_160 , 0 , 0 ) == V_161 ) {
V_89 -> V_310 = V_314 ;
F_115 ( V_157 , V_89 ) ;
}
break;
case ( V_330 << 16 ) | V_287 :
if ( F_64 ( V_327 , V_160 , 0 , 0 ) == V_161 ) {
V_89 -> V_310 = V_315 ;
F_115 ( V_157 , V_89 ) ;
}
break;
case ( V_330 << 16 ) | V_294 :
if ( F_64 ( V_327 , V_160 , 0 , 0 ) == V_161 ) {
V_89 -> V_310 = V_316 ;
F_115 ( V_157 , V_89 ) ;
}
break;
case ( V_330 << 16 ) | V_326 :
if ( F_64 ( V_327 , V_160 , 0 , 0 ) == V_161 ) {
V_89 -> V_310 = V_311 ;
F_115 ( V_157 , V_89 ) ;
V_158 = F_63 ( V_157 , V_302 ) ;
F_119 ( V_158 ) ;
}
break;
case ( V_331 << 16 ) | V_302 :
V_158 = F_63 ( V_157 , V_326 ) ;
F_64 ( V_158 , V_332 , 0 , 0 ) ;
break;
case ( V_243 << 16 ) | V_302 :
F_64 ( V_327 , V_333 , ( V_173 ) V_329 , ( V_85 ) V_328 ) ;
F_120 ( V_89 , F_18 ( V_328 ) ) ;
F_115 ( V_157 , V_89 ) ;
break;
case ( V_330 << 16 ) | V_317 :
if ( F_64 ( V_327 , V_160 , 0 , 0 ) == V_161 ) {
V_89 -> V_276 = TRUE ;
} else {
V_89 -> V_276 = FALSE ;
}
F_115 ( V_157 , V_89 ) ;
break;
}
}
static T_25 T_26
V_95 ( T_5 V_334 , T_27 V_225 , V_173 V_226 , V_85 V_227 ) {
T_5 V_158 , V_57 ;
T_28 * V_228 = ( T_28 * ) V_227 ;
T_7 V_229 [ V_18 ] ;
switch( V_225 ) {
case V_230 :
if( V_22 != NULL ) {
V_158 = F_63 ( V_334 , V_231 ) ;
F_68 ( V_158 , F_9 ( V_22 ) ) ;
}
V_158 = F_63 ( V_334 , V_335 ) ;
F_64 ( V_158 , V_171 , TRUE , 0 ) ;
V_96 = V_97 ;
F_67 ( V_334 , NULL ) ;
break;
case V_235 :
switch ( V_228 -> V_236 . V_237 ) {
case V_238 :
V_158 = F_63 ( V_334 , V_231 ) ;
if ( V_22 )
F_11 ( V_22 ) ;
V_22 = F_81 ( V_158 ) ;
V_158 = F_63 ( V_334 , V_335 ) ;
if( F_64 ( V_158 , V_160 , 0 , 0 ) == V_161 ) {
V_96 = V_98 ;
} else {
V_158 = F_63 ( V_334 , V_336 ) ;
if( F_64 ( V_158 , V_160 , 0 , 0 ) == V_161 ) {
V_96 = V_99 ;
}
}
break;
case V_239 :
V_57 = F_91 ( V_334 ) ;
F_92 ( V_57 , V_229 , V_18 ) ;
F_67 ( V_334 , F_18 ( V_229 ) ) ;
break;
case V_240 :
F_93 ( V_337 ) ;
break;
default:
break;
}
break;
case V_242 :
V_158 = ( T_5 ) V_227 ;
switch( V_226 ) {
case ( V_243 << 16 ) | V_231 :
F_86 ( V_158 , NULL ) ;
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
V_104 ( T_5 V_338 , T_27 V_225 , V_173 V_226 , V_85 V_227 ) {
T_5 V_158 ;
T_28 * V_228 = ( T_28 * ) V_227 ;
T_1 V_339 ;
int V_177 , V_340 ;
switch( V_225 ) {
case V_230 : {
V_11 * V_257 = ( V_11 * ) V_227 ;
T_9 * V_58 = ( T_9 * ) V_257 -> V_84 ;
F_121 ( & V_105 . V_89 , V_58 ) ;
V_105 . V_89 . V_320 = TRUE ;
F_113 ( V_338 , & V_105 . V_89 ) ;
F_66 ( V_338 , & V_105 ) ;
break;
}
case V_242 :
V_158 = ( T_5 ) V_227 ;
switch ( V_226 ) {
case ( V_341 << 16 ) | V_164 :
default:
F_114 ( V_338 , V_158 , V_226 , & V_105 . V_89 ) ;
F_62 ( V_338 , & V_105 ) ;
break;
}
break;
case V_235 :
switch ( V_228 -> V_236 . V_237 ) {
case V_238 :
break;
case V_342 :
V_340 = V_228 -> V_260 -> V_31 ;
if ( V_340 == 2 )
V_105 . V_106 = V_107 ;
else
V_105 . V_106 = V_343 ;
if ( V_340 == 3 || V_340 == 4 || V_340 == 5 || V_340 == 6 )
V_339 = FALSE ;
else
V_339 = TRUE ;
for ( V_177 = V_344 ; V_177 <= V_170 ; V_177 ++ ) {
V_158 = F_63 ( V_338 , V_177 ) ;
F_65 ( V_158 , V_339 ) ;
}
break;
case V_240 :
F_93 ( V_345 ) ;
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
V_138 ( T_5 V_338 , T_27 V_225 , V_173 V_226 , V_85 V_227 ) {
T_5 V_158 ;
V_11 * V_257 = ( V_11 * ) V_227 ;
T_7 V_346 [ V_268 ] ;
T_28 * V_228 = ( T_28 * ) V_227 ;
switch( V_225 ) {
case V_230 :
F_80 ( V_346 , V_268 , F_7 ( L_59 ) ,
V_257 -> V_84 , F_9 ( F_122 ( V_257 -> V_84 , L_1 , L_60 ) ) ) ;
V_158 = F_63 ( V_338 , V_347 ) ;
F_68 ( V_158 , V_346 ) ;
break;
case V_235 :
switch ( V_228 -> V_236 . V_237 ) {
case V_240 :
F_93 ( V_348 ) ;
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
V_149 ( T_5 V_338 , T_27 V_225 , V_173 V_226 , V_85 V_227 ) {
T_5 V_158 ;
V_11 * V_257 = ( V_11 * ) V_227 ;
T_7 V_349 [ V_268 ] ;
T_28 * V_228 = ( T_28 * ) V_227 ;
switch( V_225 ) {
case V_230 :
F_80 ( V_349 , V_268 , F_7 ( L_61 ) ,
V_257 -> V_84 , F_9 ( F_122 ( V_257 -> V_84 , L_1 , L_60 ) ) ) ;
V_158 = F_63 ( V_338 , V_350 ) ;
F_68 ( V_158 , V_349 ) ;
break;
case V_235 :
switch ( V_228 -> V_236 . V_237 ) {
case V_240 :
F_93 ( V_348 ) ;
break;
default:
break;
}
default:
break;
}
return 0 ;
}
