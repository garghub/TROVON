static T_1 F_1 ( T_2 * T_3 V_1 ,
T_4 T_5 V_1 , void * V_2 ) {
F_2 ( ( V_3 ) V_2 ) ;
return FALSE ;
}
static void
F_3 ( void )
{
V_4 = NULL ;
}
static T_6 * F_4 ( T_7 * V_5 ) {
T_8 * V_6 ;
T_6 * V_7 ;
#ifdef F_5
int V_8 ;
#endif
V_6 = F_6 ( V_5 ) ;
V_7 = ( T_6 * ) F_7 ( V_6 , V_9 ) ;
if ( ! V_7 ) {
V_7 = F_8 ( F_9 () , T_6 ) ;
V_7 -> V_10 = NULL ;
if ( V_11 ) {
#ifdef F_5
V_7 -> V_12 = F_8 ( F_9 () , V_13 ) ;
V_7 -> V_14 = F_8 ( F_9 () , V_13 ) ;
V_8 = F_10 ( V_7 -> V_12 ) ;
if ( V_8 == V_15 ) {
F_11 ( F_9 () , F_1 ,
V_7 -> V_12 ) ;
V_8 = F_10 ( V_7 -> V_14 ) ;
if ( V_8 == V_15 ) {
F_11 ( F_9 () , F_1 ,
V_7 -> V_14 ) ;
}
}
V_7 -> V_16 = F_12 ( 0L , V_17 , 0 ) ;
V_7 -> V_16 = F_12 ( V_7 -> V_16 ,
V_18 ,
( V_19 ) sizeof( V_18 ) ) ;
#endif
}
F_13 ( V_6 , V_9 , V_7 ) ;
}
return V_7 ;
}
static void F_14 ( T_6 * V_7 ,
T_9 V_20 ,
T_10 * V_21 ,
T_10 * V_22 ,
T_10 * V_23 ) {
T_11 * V_24 ;
if ( V_7 -> V_10 == NULL ) {
V_7 -> V_10 = F_15 ( F_9 () ) ;
}
V_24 = ( T_11 * ) F_16 ( F_9 () , sizeof( T_11 ) ) ;
V_24 -> V_21 = V_21 ;
V_24 -> V_25 = V_22 ;
V_24 -> V_23 = V_23 ;
V_24 -> V_26 = F_17 ( F_9 () ) ;
V_24 -> V_27 = 0 ;
V_24 -> V_28 = NULL ;
F_18 ( V_7 -> V_10 , V_20 , V_24 ) ;
}
static T_11 * F_19 ( T_6 * V_7 ,
T_9 V_20 )
{
if ( V_7 -> V_10 == NULL )
return NULL ;
return ( T_11 * ) F_20 ( V_7 -> V_10 , V_20 ) ;
}
static void F_21 ( T_6 * V_7 ,
T_9 V_20 ,
T_9 V_29 ,
T_12 * V_30 ,
T_9 V_31 )
{
T_11 * V_24 = F_19 ( V_7 , V_20 ) ;
if ( V_24 != NULL ) {
T_13 * V_32 = ( T_13 * ) F_22 ( F_9 () , T_13 ) ;
V_32 -> V_30 = V_30 ;
V_32 -> V_31 = V_31 ;
V_32 -> V_33 = V_29 ;
F_23 ( V_24 -> V_26 , V_32 ) ;
++ V_24 -> V_27 ;
}
}
static void F_24 ( T_6 * V_7 ,
T_9 V_20 ) {
T_11 * V_24 = F_19 ( V_7 , V_20 ) ;
if ( V_24 != NULL ) {
++ V_24 -> V_27 ;
}
}
static T_14 F_25 ( T_6 * V_7 ,
T_9 V_20 ) {
T_11 * V_24 = F_19 ( V_7 , V_20 ) ;
return V_24 == NULL ? 0 : V_24 -> V_27 ;
}
static T_11 * F_26 ( T_6 * V_7 ,
T_9 V_20 ) {
T_11 * V_24 = F_19 ( V_7 , V_20 ) ;
T_15 * V_34 ;
if ( V_24 == NULL ) {
return NULL ;
}
if ( V_24 -> V_28 == NULL ) {
T_13 * V_32 ;
T_12 * V_30 ;
T_9 V_35 ;
T_9 V_36 ;
T_16 * V_37 = V_24 -> V_26 ;
T_17 * V_29 ;
if ( F_27 ( V_37 ) == 0 ) {
return V_24 ;
}
V_35 = 0 ;
V_29 = F_28 ( F_29 ( V_37 ) ) ;
while ( V_29 != NULL ) {
V_32 = ( T_13 * ) F_30 ( V_29 ) ;
V_35 += V_32 -> V_31 ;
V_29 = F_28 ( V_29 ) ;
}
if ( V_35 != 0 ) {
V_30 = ( T_12 * ) F_16 ( F_9 () , V_35 ) ;
V_37 = V_24 -> V_26 ;
V_36 = 0 ;
V_29 = F_28 ( F_29 ( V_37 ) ) ;
while ( V_29 != NULL ) {
V_32 = ( T_13 * ) F_30 ( V_29 ) ;
memcpy ( V_30 + V_36 , V_32 -> V_30 , V_32 -> V_31 ) ;
V_36 += V_32 -> V_31 ;
V_29 = F_28 ( V_29 ) ;
}
V_34 = F_31 ( V_30 , V_35 , V_35 ) ;
V_24 -> V_28 = V_34 ;
}
}
return V_24 ;
}
static void F_32 ( T_15 * V_34 ,
int V_36 ,
T_7 * V_5 V_1 ,
T_18 * V_38 ,
const int V_39 )
{
T_9 V_20 = F_33 ( V_34 , V_36 ) & V_40 ;
F_34 ( V_38 , V_39 , V_34 , V_36 , 4 , V_41 ) ;
if ( V_39 == V_42 ) {
F_35 ( V_38 , L_1 , V_20 ) ;
}
}
static void F_36 ( T_15 * V_34 ,
int V_36 ,
T_18 * V_38 ,
const T_19 * V_29 ) {
T_20 * V_43 ;
T_18 * V_44 ;
V_43 = F_34 ( V_38 , V_45 , V_34 , V_36 , 1 , V_41 ) ;
V_44 = F_37 ( V_43 , V_46 ) ;
if ( V_29 -> type == V_47 ||
V_29 -> type == V_48 ||
V_29 -> type == V_49 ||
V_29 -> type == V_50 ) {
F_34 ( V_44 , V_51 , V_34 , V_36 , 1 , V_41 ) ;
if ( V_29 -> V_52 & V_53 ) {
F_35 ( V_38 , L_2 ) ;
F_35 ( V_43 , L_2 ) ;
}
}
if ( V_29 -> type == V_48 ) {
F_34 ( V_44 , V_54 , V_34 ,
V_36 , 1 , V_41 ) ;
if ( V_29 -> V_52 & V_55 ) {
F_35 ( V_43 , L_3 ) ;
}
}
if ( V_29 -> type == V_56 ) {
F_34 ( V_44 , V_57 , V_34 ,
V_36 , 1 , V_41 ) ;
if ( V_29 -> V_52 & V_58 ) {
F_35 ( V_43 , L_4 ) ;
}
}
}
static int F_38 ( T_15 * V_34 ,
int V_36 ,
T_7 * V_5 ,
T_18 * T_21 V_1 ,
T_18 * V_59 ,
T_20 * V_60 ,
T_6 * V_7 ,
T_9 V_20 ,
const T_19 * V_29 )
{
T_22 V_61 ;
T_14 V_27 ;
T_1 V_62 ;
F_35 ( V_60 , L_5 ,
V_20 ,
V_29 -> V_31 ) ;
F_34 ( V_59 , V_63 , V_34 , V_36 , V_29 -> V_31 , V_64 ) ;
V_27 = F_25 ( V_7 , V_20 ) ;
if ( V_29 -> V_31 != 0 || V_27 != 0 ) {
T_15 * V_65 = NULL ;
T_15 * V_66 = NULL ;
T_11 * V_24 = NULL ;
T_12 * V_67 ;
T_1 V_68 = FALSE ;
T_1 V_69 ;
char * V_70 = NULL ;
if ( V_29 -> V_31 != 0 ) {
V_65 = F_39 ( V_34 , V_36 , V_29 -> V_31 ) ;
V_68 = V_27 == 0 &&
( V_29 -> V_52 & V_53 ) != 0 ;
if ( ! V_5 -> V_71 -> V_52 . V_72 ) {
if ( ! V_68 ) {
if ( V_73 ) {
V_67 = ( T_12 * ) F_40 ( F_9 () , V_65 , 0 , V_29 -> V_31 ) ;
F_21 ( V_7 , V_20 , V_5 -> V_74 , V_67 , V_29 -> V_31 ) ;
} else {
F_24 ( V_7 , V_20 ) ;
}
}
}
} else {
V_68 = ( V_27 == 1 ) ;
}
if ( ! ( V_29 -> V_52 & V_53 ) ) {
F_41 ( V_5 -> V_75 , V_76 ) ;
F_35 ( V_60 , L_6 ) ;
goto V_77;
}
V_69 = V_68 ;
V_24 = F_26 ( V_7 , V_20 ) ;
if ( V_24 == NULL ) {
goto V_77;
}
V_66 = V_24 -> V_28 ;
if ( V_73 ) {
V_69 = TRUE ;
}
if ( ! V_69 ) {
goto V_77;
}
if ( V_66 == NULL ) {
if ( V_65 == NULL )
goto V_77;
V_66 = V_65 ;
} else {
F_42 ( V_5 , V_66 , L_7 ) ;
}
if ( V_69 && V_24 -> V_23 != NULL &&
F_43 ( V_24 -> V_23 , L_8 ) != 0 ) {
T_15 * V_78 = NULL ;
T_20 * V_79 = NULL ;
T_18 * V_80 = NULL ;
if ( V_81 &&
( F_43 ( V_24 -> V_23 , L_9 ) == 0 ||
F_43 ( V_24 -> V_23 , L_10 ) == 0 ) ) {
V_78 = F_44 ( V_34 , V_66 , 0 ,
F_45 ( V_66 ) ) ;
}
V_80 = F_46 ( V_59 , V_66 ,
0 , F_45 ( V_66 ) , V_82 , & V_79 ,
L_11 ,
V_24 -> V_23 ,
F_45 ( V_66 ) ) ;
if ( V_24 -> V_27 > 1 ) {
T_16 * V_37 = V_24 -> V_26 ;
T_17 * V_83 ;
T_13 * V_32 ;
T_9 V_33 = 0 ;
T_23 * V_84 = F_47 ( F_48 () , L_12 ) ;
V_83 = F_28 ( F_29 ( V_37 ) ) ;
while ( V_83 != NULL ) {
V_32 = ( T_13 * ) F_30 ( V_83 ) ;
if ( V_33 != V_32 -> V_33 ) {
F_49 ( V_84 , L_13 , V_32 -> V_33 ) ;
V_33 = V_32 -> V_33 ;
}
V_83 = F_28 ( V_83 ) ;
}
F_50 ( V_80 , V_5 , & V_85 , V_66 , 0 ,
F_45 ( V_66 ) ,
L_14 ,
V_24 -> V_27 , F_51 ( V_84 ) ) ;
}
if ( V_78 != NULL ) {
F_35 ( V_79 , L_15 , F_45 ( V_78 ) ) ;
V_66 = V_78 ;
F_42 ( V_5 , V_66 , L_16 ) ;
} else {
if ( V_81 ) {
F_35 ( V_79 , L_17 ) ;
}
F_52 ( V_66 , V_5 , V_80 ) ;
goto V_77;
}
}
if ( V_69 && V_86 != NULL ) {
V_61 = F_53 ( V_86 ,
V_5 -> V_87 ) ;
} else {
V_61 = NULL ;
}
if ( V_61 == NULL && V_69 && V_24 -> V_21 != NULL &&
V_88 != NULL ) {
if ( V_24 -> V_25 ) {
V_70 = F_54 ( F_48 () , V_24 -> V_25 ) ;
}
V_5 -> V_89 = V_24 -> V_21 ;
V_61 = F_55 ( V_88 ,
V_24 -> V_21 ) ;
}
if ( V_61 != NULL ) {
V_62 = F_56 ( V_61 , V_66 , V_5 , V_59 , V_70 ) ;
} else {
V_62 = FALSE ;
}
if ( ! V_62 && V_69 && V_24 -> V_21 != NULL ) {
F_56 ( V_90 , V_65 , V_5 , V_59 , V_70 ) ;
} else {
F_52 ( V_65 , V_5 , V_59 ) ;
}
V_77:
;
}
return V_29 -> V_31 ;
}
static T_12 * F_57 ( T_15 * V_34 ,
V_3 V_91 ,
T_24 V_16 ,
int V_36 ,
T_9 V_31 ,
T_14 * V_92 ) {
int V_8 ;
const T_12 * V_93 = F_58 ( V_34 , V_36 , V_31 ) ;
T_12 * V_94 = ( T_12 * ) F_16 ( F_48 () , V_95 ) ;
#ifdef F_59
V_91 -> V_96 = ( F_59 V_97 * ) V_93 ;
#else
F_60 (cast-qual)
V_91 -> V_96 = ( V_97 * ) V_93 ;
F_61 (cast-qual)
#endif
V_91 -> V_98 = V_31 ;
V_91 -> V_99 = V_94 ;
V_91 -> V_100 = V_95 ;
V_8 = F_62 ( V_91 , V_101 ) ;
if ( V_8 == V_102 ) {
if ( V_91 -> V_103 == V_16 ) {
V_8 = F_63 ( V_91 ,
V_18 ,
sizeof( V_18 ) ) ;
if ( V_8 == V_15 ) {
V_8 = F_62 ( V_91 , V_101 ) ;
}
}
}
if ( V_8 != V_15 ) {
return NULL ;
}
* V_92 = V_95 - V_91 -> V_100 ;
return ( T_12 * ) F_64 ( F_9 () , V_94 , * V_92 ) ;
}
static T_25 * F_65 ( T_7 * V_5 V_1 ,
T_9 V_20 ,
T_26 V_104 ,
T_12 * V_105 ,
T_14 V_31 ) {
T_25 * V_106 ;
if ( V_4 == NULL )
V_4 = F_17 ( F_9 () ) ;
V_106 = F_22 ( F_9 () , T_25 ) ;
V_106 -> V_20 = V_20 ;
V_106 -> V_107 = V_105 ;
V_106 -> V_108 = V_31 ;
V_106 -> V_104 = V_104 ;
F_23 ( V_4 , V_106 ) ;
return V_106 ;
}
static T_25 * F_66 ( T_7 * V_5 V_1 ,
T_9 V_20 ,
T_26 V_104 ) {
T_17 * V_29 ;
if ( ( V_4 == NULL ) || ( F_29 ( V_4 ) == NULL ) )
return NULL ;
V_29 = F_28 ( F_29 ( V_4 ) ) ;
while ( V_29 != NULL ) {
T_25 * V_109 = ( T_25 * ) F_30 ( V_29 ) ;
if ( V_109 -> V_20 == V_20 && V_109 -> V_104 == V_104 )
return V_109 ;
V_29 = F_28 ( V_29 ) ;
}
return NULL ;
}
static T_10 * F_67 ( T_10 * V_21 ) {
T_10 * V_110 = V_21 ;
while ( * V_110 != '\0' && * V_110 != ';' && ! F_68 ( * V_110 ) ) {
* V_110 = F_69 ( * V_110 ) ;
++ V_110 ;
}
if ( * V_110 == '\0' ) {
V_110 = NULL ;
}
if ( V_110 != NULL ) {
* V_110 ++ = '\0' ;
while ( * V_110 == ';' || F_68 ( * V_110 ) ) {
++ V_110 ;
}
if ( * V_110 != '\0' ) {
return V_110 ;
}
}
return NULL ;
}
static int F_70 (
T_15 * V_34 ,
int V_36 ,
T_7 * V_5 ,
T_18 * V_38 ,
const T_19 * V_29 ,
T_6 * V_7 ) {
T_9 V_20 ;
int V_111 = V_29 -> V_31 ;
int V_112 = 0 ;
T_15 * V_113 = NULL ;
const T_10 * V_114 = NULL ;
const T_10 * V_115 = NULL ;
const T_10 * V_116 = NULL ;
const T_10 * V_117 = NULL ;
const T_10 * V_118 = NULL ;
const T_10 * V_119 = NULL ;
T_10 * V_21 = NULL ;
T_10 * V_23 = NULL ;
T_9 V_120 = 0 ;
T_20 * V_121 ;
T_18 * V_122 ;
V_20 = F_33 ( V_34 , V_36 ) & V_40 ;
F_32 ( V_34 , V_36 , V_5 , V_38 , V_42 ) ;
V_36 += 4 ;
if ( V_29 -> type == V_48 ) {
F_32 ( V_34 , V_36 , V_5 , V_38 , V_123 ) ;
V_36 += 4 ;
F_34 ( V_38 , V_124 , V_34 , V_36 , 2 , V_41 ) ;
F_34 ( V_38 , V_125 , V_34 , V_36 , 2 , V_41 ) ;
F_34 ( V_38 , V_126 , V_34 , V_36 , 2 , V_41 ) ;
V_36 += 2 ;
}
switch ( V_29 -> type ) {
case V_48 :
V_111 -= 10 ;
break;
case V_49 :
case V_50 :
V_111 -= 4 ;
break;
default:
F_71 () ;
}
V_121 = F_34 ( V_38 ,
V_127 ,
V_34 ,
V_36 ,
V_111 ,
V_64 ) ;
V_122 = F_37 ( V_121 ,
V_128 ) ;
if ( ! V_11 ) {
V_113 = V_34 ;
V_112 = V_36 ;
} else {
T_25 * V_106 ;
V_106 = F_66 ( V_5 ,
V_20 ,
V_29 -> type ) ;
if ( V_106 == NULL ) {
T_12 * V_129 = NULL ;
T_14 V_92 = 0 ;
#ifdef F_5
V_3 V_91 ;
if ( V_20 % 2 == 0 ) {
V_91 = V_7 -> V_14 ;
} else if ( V_29 -> type == V_50 ) {
V_91 = V_7 -> V_14 ;
} else if ( V_29 -> type == V_48 ) {
V_91 = V_7 -> V_12 ;
} else if ( V_29 -> type == V_49 ) {
V_91 = V_7 -> V_14 ;
} else {
F_71 () ;
}
V_129 = F_57 ( V_34 ,
V_91 ,
V_7 -> V_16 ,
V_36 ,
V_111 ,
& V_92 ) ;
if ( V_129 == NULL ) {
F_72 ( V_5 , V_38 , & V_130 ) ;
F_35 ( V_38 , L_18 ) ;
return - 1 ;
}
#endif
V_106 = F_65 ( V_5 , V_20 , V_29 -> type , V_129 , V_92 ) ;
}
V_113 = F_73 ( V_34 , V_106 -> V_107 ,
V_106 -> V_108 ,
V_106 -> V_108 ) ;
F_42 ( V_5 , V_113 , L_19 ) ;
V_112 = 0 ;
}
if ( V_113 == NULL || ! V_11 ) {
V_120 = 0 ;
} else {
V_120 = F_33 ( V_113 , V_112 ) ;
F_34 ( V_122 ,
V_131 ,
V_113 ,
V_112 ,
4 ,
V_41 ) ;
}
V_112 += 4 ;
while ( V_120 -- ) {
T_10 * V_132 ;
const T_10 * V_133 ;
T_18 * V_134 ;
T_20 * V_105 ;
int V_135 ;
int V_136 ;
int V_137 ;
int V_138 ;
if ( F_74 ( V_113 , V_112 ) < 4 ) {
F_75 ( V_5 , V_38 , & V_139 ,
L_20 ) ;
break;
}
V_135 = V_112 ;
V_137 = F_33 ( V_113 , V_112 ) ;
V_112 += 4 ;
if ( F_74 ( V_113 , V_112 ) < V_137 ) {
F_75 ( V_5 , V_38 , & V_139 ,
L_21 ) ;
break;
}
V_132 = ( T_10 * ) F_76 ( F_48 () , V_113 ,
V_112 ,
V_137 , V_140 | V_64 ) ;
V_112 += V_137 ;
if ( F_74 ( V_113 , V_112 ) < 4 ) {
F_75 ( V_5 , V_38 , & V_139 ,
L_22 ) ;
break;
}
V_136 = V_112 ;
V_138 = F_33 ( V_113 , V_112 ) ;
V_112 += 4 ;
if ( F_74 ( V_113 , V_112 ) < V_138 ) {
F_75 ( V_5 , V_38 , & V_139 ,
L_23 ) ;
break;
}
V_133 = ( T_10 * ) F_76 ( F_48 () , V_113 ,
V_112 ,
V_138 , V_140 | V_64 ) ;
V_112 += V_138 ;
if ( V_38 ) {
V_105 = F_34 ( V_38 ,
V_141 ,
V_113 ,
V_135 ,
V_112 - V_135 ,
V_64 ) ;
F_35 ( V_105 , L_24 , V_132 , V_133 ) ;
V_134 = F_37 ( V_105 , V_142 ) ;
F_34 ( V_134 , V_143 , V_113 ,
V_135 , 4 , V_140 | V_41 ) ;
F_34 ( V_134 , V_144 , V_113 ,
V_136 , 4 , V_140 | V_41 ) ;
}
if ( F_77 ( V_132 , L_25 ) == 0 ) {
V_114 = V_133 ;
} else if ( F_77 ( V_132 , L_26 ) == 0 ) {
V_115 = V_133 ;
} else if ( F_77 ( V_132 , L_27 ) == 0 ) {
V_116 = V_133 ;
} else if ( F_77 ( V_132 , L_28 ) == 0 ) {
V_117 = V_133 ;
} else if ( F_77 ( V_132 , L_29 ) == 0 ) {
V_118 = V_133 ;
} else if ( F_77 ( V_132 , L_30 ) == 0 ) {
V_119 = V_133 ;
} else if ( F_77 ( V_132 , L_31 ) == 0 ) {
V_21 = F_54 ( F_9 () , V_133 ) ;
} else if ( F_77 ( V_132 , L_32 ) == 0 ) {
V_23 = F_54 ( F_9 () , V_133 ) ;
}
}
if ( V_116 != NULL ) {
if ( V_119 == NULL ) {
F_35 ( V_38 , L_33 ,
V_114 , V_118 , V_117 , V_115 , V_116 ) ;
} else {
F_35 ( V_38 , L_34 ,
V_119 , V_116 ) ;
}
}
if ( V_21 != NULL && ! V_5 -> V_71 -> V_52 . V_72 ) {
T_10 * V_22 = F_67 ( V_21 ) ;
F_14 ( V_7 , V_20 , V_21 ,
V_22 , V_23 ) ;
}
return V_29 -> V_31 ;
}
static int F_78 (
T_15 * V_34 ,
int V_36 ,
T_7 * V_5 ,
T_18 * V_38 ,
const T_19 * V_29 ) {
T_9 V_145 ;
T_20 * V_146 ;
const char * V_147 ;
F_32 ( V_34 , V_36 , V_5 , V_38 , V_42 ) ;
V_36 += 4 ;
V_146 = F_34 ( V_38 , V_148 , V_34 , V_36 , 4 , V_41 ) ;
V_145 = F_33 ( V_34 , V_36 ) ;
if ( F_79 ( V_145 , V_149 ) == NULL ) {
F_75 ( V_5 , V_146 , & V_150 ,
L_35 , V_145 ) ;
}
V_147 = F_80 ( V_145 , V_149 , L_36 ) ;
F_35 ( V_38 , L_37 , V_147 ) ;
return V_29 -> V_31 ;
}
static int F_81 (
T_15 * V_34 ,
int V_36 ,
T_7 * V_5 ,
T_18 * V_38 ,
const T_19 * V_29 ) {
T_9 V_151 ;
T_20 * V_146 , * V_152 ;
T_18 * V_153 ;
T_18 * V_44 ;
if ( V_29 -> V_31 < 4 ) {
F_72 ( V_5 , V_38 , & V_154 ) ;
return - 1 ;
}
V_151 = F_33 ( V_34 , V_36 ) ;
if ( V_29 -> V_31 < V_151 * 8 ) {
F_75 ( V_5 , V_38 , & V_154 ,
L_38 , V_151 ) ;
return - 1 ;
}
F_34 ( V_38 , V_155 , V_34 , V_36 , 4 , V_41 ) ;
V_36 += 4 ;
while ( V_151 > 0 ) {
const T_10 * V_156 ;
T_9 V_157 ;
V_152 = F_34 ( V_38 , V_158 , V_34 , V_36 , 8 , V_64 ) ;
V_153 = F_37 ( V_152 , V_159 ) ;
if ( V_153 ) {
V_146 = F_34 ( V_153 , V_45 , V_34 , V_36 , 1 , V_41 ) ;
V_44 = F_37 ( V_146 , V_46 ) ;
F_34 ( V_44 , V_160 , V_34 , V_36 , 1 , V_41 ) ;
F_34 ( V_44 , V_161 , V_34 , V_36 , 1 , V_41 ) ;
}
V_36 += 1 ;
V_156 = F_80 ( F_82 ( V_34 , V_36 ) , V_162 , L_39 ) ;
F_34 ( V_153 , V_163 , V_34 , V_36 , 3 , V_41 ) ;
V_36 += 3 ;
V_157 = F_33 ( V_34 , V_36 ) ;
F_34 ( V_153 , V_164 , V_34 , V_36 , 4 , V_41 ) ;
F_35 ( V_152 , L_40 , V_156 , V_157 ) ;
F_35 ( V_38 , L_40 , V_156 , V_157 ) ;
V_36 += 4 ;
-- V_151 ;
}
return V_29 -> V_31 ;
}
static int F_83 ( T_15 * V_34 , int V_36 , T_7 * V_5 V_1 ,
T_18 * V_38 , const T_19 * V_29 )
{
T_9 V_165 = F_33 ( V_34 , V_36 ) ;
F_34 ( V_38 , V_166 , V_34 , V_36 , 4 , V_41 ) ;
F_35 ( V_38 , L_41 , V_165 ) ;
return V_29 -> V_31 ;
}
static int F_84 ( T_15 * V_34 ,
int V_36 ,
T_7 * V_5 ,
T_18 * V_38 ,
const T_19 * V_29 ) {
T_9 V_167 ;
T_20 * V_146 ;
F_32 ( V_34 , V_36 , V_5 , V_38 , V_168 ) ;
V_36 += 4 ;
V_146 = F_34 ( V_38 , V_169 , V_34 , V_36 , 4 , V_41 ) ;
V_167 = F_33 ( V_34 , V_36 ) ;
if ( F_79 ( V_167 , V_170 ) == NULL ) {
F_75 ( V_5 , V_146 , & V_171 ,
L_42 , V_167 ) ;
}
F_35 ( V_38 , L_43 ,
F_80 ( V_167 , V_149 , L_36 ) ) ;
return V_29 -> V_31 ;
}
static int F_85 (
T_15 * V_34 ,
int V_36 ,
T_7 * V_5 ,
T_18 * V_38 ,
const T_19 * V_29 )
{
T_9 V_172 ;
F_32 ( V_34 , V_36 , V_5 , V_38 , V_42 ) ;
V_36 += 4 ;
V_172 = F_33 ( V_34 , V_36 ) & 0x7FFFFFFF ;
F_34 ( V_38 , V_173 , V_34 , V_36 , 4 , V_41 ) ;
F_35 ( V_38 , L_44 , V_172 ) ;
return V_29 -> V_31 ;
}
static int F_86 ( T_15 * V_34 , T_7 * V_5 , T_18 * V_174 , void * V_30 V_1 )
{
T_12 V_175 ;
T_19 V_29 ;
T_9 V_20 = 0 ;
const T_10 * V_176 ;
T_18 * V_59 ;
T_20 * V_177 , * V_178 = NULL ;
int V_36 = 0 ;
T_6 * V_7 ;
V_7 = F_4 ( V_5 ) ;
F_87 ( V_5 -> V_75 , V_179 , L_45 ) ;
V_177 = F_34 ( V_174 , V_9 , V_34 , V_36 , - 1 , V_64 ) ;
V_59 = F_37 ( V_177 , V_180 ) ;
V_175 = F_88 ( V_34 , V_36 ) & 0x80 ;
F_34 ( V_59 , V_181 , V_34 , V_36 , 2 , V_64 ) ;
if ( V_175 ) {
V_29 . V_182 = F_89 ( V_34 , V_36 ) & 0x7FFF ;
F_34 ( V_59 , V_183 , V_34 , V_36 , 2 , V_41 ) ;
V_36 += 2 ;
V_178 = F_34 ( V_59 , V_184 , V_34 , V_36 , 2 , V_41 ) ;
V_29 . type = F_89 ( V_34 , V_36 ) ;
if ( V_29 . type >= V_185 ) {
F_75 ( V_5 , V_178 , & V_186 ,
L_46 , V_29 . type ) ;
return - 1 ;
}
V_36 += 2 ;
} else {
V_29 . type = V_47 ;
V_29 . V_182 = 0 ;
V_20 = F_33 ( V_34 , V_36 ) & V_40 ;
F_34 ( V_59 , V_42 , V_34 , V_36 , 4 , V_41 ) ;
V_36 += 4 ;
}
V_176 = F_80 ( V_29 . type , V_187 , L_39 ) ;
F_90 ( V_5 -> V_75 , V_76 , L_47 , V_176 ) ;
F_35 ( V_59 , L_48 , V_176 ) ;
V_29 . V_52 = F_88 ( V_34 , V_36 ) ;
if ( V_59 ) {
F_36 ( V_34 , V_36 , V_59 , & V_29 ) ;
}
V_36 += 1 ;
V_29 . V_31 = F_82 ( V_34 , V_36 ) ;
F_91 ( V_177 , V_29 . V_31 + 8 ) ;
F_34 ( V_59 , V_188 , V_34 , V_36 , 3 , V_41 ) ;
V_36 += 3 ;
if ( ( T_14 ) F_74 ( V_34 , V_36 ) < V_29 . V_31 ) {
F_75 ( V_5 , V_174 , & V_139 ,
L_49 ,
V_29 . V_31 , F_74 ( V_34 , V_36 ) ) ;
return - 1 ;
}
if ( ! V_175 ) {
return V_36 + F_38 ( V_34 , V_36 , V_5 , V_174 , V_59 ,
V_177 , V_7 , V_20 , & V_29 ) ;
}
if ( V_29 . V_182 < V_189 ) {
F_35 ( V_177 , L_50 ) ;
return V_29 . V_31 + 8 ;
}
switch ( V_29 . type ) {
case V_48 :
case V_49 :
case V_50 :
F_70 ( V_34 , V_36 , V_5 , V_59 , & V_29 , V_7 ) ;
break;
case V_190 :
F_78 ( V_34 , V_36 , V_5 , V_59 , & V_29 ) ;
break;
case V_56 :
F_81 ( V_34 , V_36 , V_5 , V_59 , & V_29 ) ;
break;
case V_191 :
F_83 ( V_34 , V_36 , V_5 , V_59 , & V_29 ) ;
break;
case V_192 :
F_84 ( V_34 , V_36 , V_5 , V_59 , & V_29 ) ;
break;
case V_193 :
F_85 ( V_34 , V_36 , V_5 , V_59 , & V_29 ) ;
break;
case V_194 :
break;
default:
F_75 ( V_5 , V_178 , & V_186 ,
L_51 , V_29 . type ) ;
break;
}
F_41 ( V_5 -> V_75 , V_76 ) ;
return 8 + V_29 . V_31 ;
}
static T_14 F_92 ( T_7 * V_5 V_1 , T_15 * V_34 ,
int V_36 , void * V_30 V_1 )
{
return ( T_14 ) F_82 ( V_34 , V_36 + 5 ) + 8 ;
}
static int F_93 ( T_15 * V_34 , T_7 * V_5 , T_18 * V_174 , void * V_30 V_1 )
{
F_94 ( V_5 -> V_75 , V_76 ) ;
F_95 ( V_34 , V_5 , V_174 , TRUE , 8 , F_92 , F_86 , V_30 ) ;
return F_96 ( V_34 ) ;
}
static T_1 F_97 ( T_15 * V_34 ,
T_7 * V_5 ,
T_18 * V_174 ,
void * V_30 V_1 )
{
T_12 V_195 = F_88 ( V_34 , 0 ) ;
if ( V_195 != 0x80 && V_195 != 0x0 ) {
return FALSE ;
}
if ( F_93 ( V_34 , V_5 , V_174 , NULL ) != 0 ) {
return TRUE ;
}
return FALSE ;
}
void F_98 ( void )
{
static T_27 V_196 [] = {
{ & V_63 ,
{ L_52 , L_53 ,
V_197 , V_198 , NULL , 0x0 ,
NULL , V_199
}
} ,
{ & V_181 ,
{ L_54 , L_55 ,
V_200 , 16 , F_99 ( & V_201 ) , 0x8000 ,
L_56 , V_199
}
} ,
{ & V_183 ,
{ L_57 , L_58 ,
V_202 , V_203 , NULL , 0x7FFF ,
NULL , V_199
}
} ,
{ & V_184 ,
{ L_59 , L_60 ,
V_202 , V_203 ,
F_100 ( V_187 ) , 0x0 ,
NULL , V_199
}
} ,
{ & V_45 ,
{ L_61 , L_62 ,
V_204 , V_205 , NULL , 0x0 ,
NULL , V_199
}
} ,
{ & V_51 ,
{ L_63 , L_64 ,
V_200 , 8 ,
F_99 ( & V_206 ) , V_53 ,
NULL , V_199
}
} ,
{ & V_54 ,
{ L_65 , L_64 ,
V_200 , 8 ,
F_99 ( & V_206 ) , V_55 ,
NULL , V_199
}
} ,
{ & V_57 ,
{ L_66 , L_67 ,
V_200 , 8 ,
F_99 ( & V_206 ) , V_58 ,
NULL , V_199
}
} ,
{ & V_160 ,
{ L_66 , L_68 ,
V_200 , 8 ,
F_99 ( & V_206 ) , V_207 ,
NULL , V_199
}
} ,
{ & V_161 ,
{ L_69 , L_70 ,
V_200 , 8 ,
F_99 ( & V_206 ) , V_208 ,
NULL , V_199
}
} ,
{ & V_188 ,
{ L_71 , L_72 ,
V_209 , V_203 , NULL , 0x0 ,
NULL , V_199
}
} ,
{ & V_127 ,
{ L_73 , L_74 ,
V_197 , V_198 , NULL , 0x0 ,
NULL , V_199
}
} ,
{ & V_141 ,
{ L_75 , L_76 ,
V_210 , V_198 , NULL , 0x0 ,
NULL , V_199
}
} ,
{ & V_143 ,
{ L_77 , L_78 ,
V_211 , V_198 , NULL , 0x0 ,
NULL , V_199
}
} ,
{ & V_144 ,
{ L_79 , L_80 ,
V_211 , V_198 , NULL , 0x0 ,
NULL , V_199
}
} ,
{ & V_42 ,
{ L_81 , L_82 ,
V_212 , V_203 , NULL , V_40 ,
NULL , V_199
}
} ,
{ & V_123 ,
{ L_83 , L_84 ,
V_212 , V_203 , NULL , V_40 ,
NULL , V_199
}
} ,
{ & V_124 ,
{ L_85 , L_86 ,
V_202 , V_203 , NULL , 0xE000 ,
NULL , V_199
}
} ,
{ & V_125 ,
{ L_87 , L_88 ,
V_202 , V_205 , NULL , 0x1F00 ,
L_89 , V_199
}
} ,
{ & V_126 ,
{ L_90 , L_91 ,
V_202 , V_203 , NULL , 0x00FF ,
L_92 , V_199
}
} ,
{ & V_131 ,
{ L_93 , L_94 ,
V_212 , V_203 , NULL , 0x0 ,
NULL , V_199
}
} ,
{ & V_148 ,
{ L_95 , L_96 ,
V_212 , V_203 , F_100 ( V_149 ) , 0x0 ,
NULL , V_199
}
} ,
{ & V_155 ,
{ L_97 , L_98 ,
V_212 , V_203 , NULL , 0x0 ,
NULL , V_199
}
} ,
{ & V_158 ,
{ L_99 , L_100 ,
V_210 , V_198 , NULL , 0x0 ,
NULL , V_199
}
} ,
{ & V_163 ,
{ L_101 , L_102 ,
V_209 , V_203 , F_100 ( V_162 ) , 0x0 ,
NULL , V_199
}
} ,
{ & V_164 ,
{ L_79 , L_103 ,
V_212 , V_203 , NULL , 0x0 ,
NULL , V_199
}
} ,
{ & V_166 ,
{ L_104 , L_105 ,
V_209 , V_203 , NULL , 0x0 ,
NULL , V_199
}
} ,
{ & V_168 ,
{ L_106 , L_107 ,
V_212 , V_203 , NULL , V_40 ,
NULL , V_199
}
} ,
{ & V_169 ,
{ L_108 , L_109 ,
V_212 , V_203 , F_100 ( V_170 ) , 0x0 ,
NULL , V_199
}
} ,
{ & V_173 ,
{ L_110 , L_111 ,
V_212 , V_203 , NULL , 0x7FFFFFFF ,
NULL , V_199
}
} ,
} ;
static T_28 * V_213 [] = {
& V_180 ,
& V_46 ,
& V_128 ,
& V_142 ,
& V_159 ,
& V_82 ,
} ;
static T_29 V_214 [] = {
{ & V_130 , { L_112 , V_215 , V_216 , L_113 , V_217 } } ,
{ & V_139 , { L_114 , V_218 , V_216 , L_115 , V_217 } } ,
{ & V_154 , { L_116 , V_218 , V_216 , L_117 , V_217 } } ,
{ & V_150 , { L_118 , V_219 , V_220 , L_119 , V_217 } } ,
{ & V_171 , { L_120 , V_219 , V_220 , L_121 , V_217 } } ,
{ & V_186 , { L_122 , V_219 , V_220 , L_123 , V_217 } } ,
{ & V_85 , { L_124 , V_221 , V_222 , L_125 , V_217 } } ,
} ;
T_30 * V_223 ;
T_31 * V_224 ;
V_9 = F_101 ( L_45 , L_45 , L_126 ) ;
F_102 ( V_9 , V_196 , F_103 ( V_196 ) ) ;
F_104 ( V_213 , F_103 ( V_213 ) ) ;
V_224 = F_105 ( V_9 ) ;
F_106 ( V_224 , V_214 , F_103 ( V_214 ) ) ;
V_225 = F_107 ( L_126 , F_93 , V_9 ) ;
V_223 = F_108 ( V_9 , NULL ) ;
F_109 ( V_223 , L_127 ,
L_128 ,
L_129
L_130 ,
& V_73 ) ;
F_109 ( V_223 , L_131 ,
L_132 ,
L_133 ,
& V_11 ) ;
F_109 ( V_223 , L_134 ,
L_135 ,
L_136
L_137 ,
& V_81 ) ;
F_110 ( & F_3 ) ;
V_226 = F_111 ( L_126 ) ;
V_227 = F_111 ( L_138 ) ;
}
void F_112 ( void ) {
F_113 ( L_139 , V_228 , V_225 ) ;
F_114 ( 0 , V_225 ) ;
V_90 = F_115 ( L_140 , V_9 ) ;
V_86 = F_116 ( L_141 ) ;
V_88 = F_116 ( L_142 ) ;
F_117 ( L_143 , F_97 , L_144 , L_145 , V_9 , V_229 ) ;
}
