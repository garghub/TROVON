static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
union V_5 * V_6 , char * V_7 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
unsigned long V_10 ;
int V_11 = 0 ;
F_3 ( L_1 ) ;
F_4 ( V_12 ) ;
if( V_9 -> V_13 == V_14 ) {
V_11 = - V_15 ;
goto V_16;
}
F_5 ( V_9 , & V_10 ) ;
F_6 ( V_9 ) ;
F_7 ( V_9 ) ;
F_8 ( V_9 ) ;
F_9 ( V_9 , & V_10 ) ;
V_16:
F_10 ( V_12 ) ;
return V_11 ;
}
static int F_11 ( struct V_1 * V_2 , struct V_3 * V_4 , char * V_17 , char * V_7 )
{
F_3 ( L_2 ) ;
F_4 ( V_12 ) ;
strcpy ( V_17 , L_3 ) ;
F_10 ( V_12 ) ;
return 0 ;
}
static int F_12 ( struct V_1 * V_2 , struct V_3 * V_4 , struct V_18 * V_19 , char * V_7 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
unsigned long V_10 ;
int V_20 = 0 ;
int V_11 = 0 ;
F_3 ( L_4 ) ;
F_4 ( V_12 ) ;
if( V_9 -> V_13 == V_14 ) {
V_11 = - V_15 ;
goto V_16;
}
if( ! F_13 ( V_21 ) ) {
V_11 = - V_22 ;
F_10 ( V_12 ) ;
return V_11 ;
}
if( V_19 -> V_23 == 1 ) {
int V_24 = V_19 -> V_25 / 100000 ;
V_20 = F_14 ( V_24 ) ;
}
if( V_19 -> V_23 == 0 ) {
V_20 = V_19 -> V_25 ;
}
if( V_20 > 14 ) {
V_20 = V_20 | 0x100 ;
}
F_5 ( V_9 , & V_10 ) ;
F_6 ( V_9 ) ;
V_9 -> V_26 = V_20 ;
F_7 ( V_9 ) ;
F_15 ( V_9 -> V_2 ) ;
F_8 ( V_9 ) ;
F_9 ( V_9 , & V_10 ) ;
V_16:
F_10 ( V_12 ) ;
return V_11 ;
}
static int F_16 ( struct V_1 * V_2 , struct V_3 * V_4 , struct V_18 * V_19 , char * V_7 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
unsigned long V_10 ;
int V_11 = - 1 ;
F_3 ( L_5 ) ;
F_4 ( V_12 ) ;
if( V_9 -> V_13 == V_14 ) {
V_11 = - V_15 ;
goto V_16;
}
F_5 ( V_9 , & V_10 ) ;
F_6 ( V_9 ) ;
V_9 -> V_27 . V_28 = 2 ;
V_9 -> V_27 . V_29 = V_30 ;
V_11 = F_17 ( & ( V_9 -> V_31 ) , ( V_32 ) & ( V_9 -> V_27 ) ) ;
if( V_11 == V_33 ) {
T_1 V_20 = F_18 ( V_9 -> V_27 . V_34 . V_35 [ 0 ] ) ;
#ifdef F_19
V_19 -> V_25 = F_20 ( V_20 ) * 100000 ;
V_19 -> V_23 = 1 ;
#else
V_19 -> V_25 = V_20 ;
V_19 -> V_23 = 0 ;
#endif
}
F_8 ( V_9 ) ;
F_9 ( V_9 , & V_10 ) ;
V_11 = ( V_11 == V_33 ? 0 : - V_36 ) ;
V_16:
F_10 ( V_12 ) ;
return V_11 ;
}
static int F_21 ( struct V_1 * V_2 , struct V_3 * V_4 , struct V_37 * V_38 , char * V_7 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
unsigned long V_10 ;
struct V_39 * V_40 = (struct V_39 * ) V_7 ;
int V_11 = 0 ;
int V_41 = - 1 ;
int V_42 ;
T_2 * V_43 ;
int V_44 = 0 ;
F_3 ( L_6 ) ;
F_4 ( V_12 ) ;
V_38 -> V_45 = sizeof( struct V_39 ) ;
memset ( V_40 , 0 , sizeof( struct V_39 ) ) ;
F_5 ( V_9 , & V_10 ) ;
F_6 ( V_9 ) ;
memset ( V_40 , 0 , sizeof( struct V_39 ) ) ;
V_46:
V_9 -> V_27 . V_28 = 1 + ( sizeof( * V_43 ) / sizeof( T_1 ) ) ;
V_9 -> V_27 . V_29 = V_47 ;
V_41 = F_17 ( & ( V_9 -> V_31 ) , ( V_32 ) & ( V_9 -> V_27 ) ) ;
if( V_41 != V_33 ) {
F_22 ( V_12 , L_7 , V_41 ) ;
if ( V_44 < 10 ) {
V_44 ++ ;
F_9 ( V_9 , & V_10 ) ;
F_5 ( V_9 , & V_10 ) ;
V_41 = F_23 ( V_2 ) ;
if ( V_41 != V_33 ) {
F_22 ( V_12 , L_8 , V_41 ) ;
V_11 = - V_36 ;
goto V_48;
}
F_9 ( V_9 , & V_10 ) ;
F_5 ( V_9 , & V_10 ) ;
goto V_46;
} else {
F_22 ( V_12 , L_9 , V_44 ) ;
V_11 = - V_36 ;
goto V_48;
}
}
F_9 ( V_9 , & V_10 ) ;
F_5 ( V_9 , & V_10 ) ;
V_43 = ( T_2 * ) & ( V_9 -> V_27 . V_34 . V_49 ) ;
V_40 -> V_50 = F_18 ( * V_43 ) * V_51 ;
if ( V_44 > 0 ) {
F_22 ( V_12 , L_10 , V_44 ) ;
}
V_40 -> V_52 = V_53 ;
V_40 -> V_54 = V_55 ;
#ifdef F_24
V_40 -> V_56 . V_57 = ( V_58 ) V_59 ;
V_40 -> V_56 . V_60 = ( V_58 ) ( F_25 ( V_61 ) - 1 ) ;
V_40 -> V_56 . V_62 = ( V_58 ) ( F_25 ( V_63 ) - 1 ) ;
#else
V_40 -> V_56 . V_57 = 100 ;
V_40 -> V_56 . V_60 = 100 ;
V_40 -> V_56 . V_62 = 100 ;
#endif
V_40 -> V_64 = 0 ;
V_9 -> V_27 . V_28 = 6 ;
V_9 -> V_27 . V_29 = V_65 ;
V_41 = F_17 ( & ( V_9 -> V_31 ) , ( V_32 ) & ( V_9 -> V_27 ) ) ;
if( V_41 == V_33 ) {
for( V_42 = 0 ; V_42 < V_66 ; V_42 ++ )
if( V_9 -> V_27 . V_34 . V_67 [ V_42 + 2 ] != 0 ) {
V_40 -> V_68 [ V_42 ] = V_9 -> V_27 . V_34 . V_67 [ V_42 + 2 ] * V_51 / 2 ;
V_40 -> V_64 ++ ;
}
} else {
F_22 ( V_12 , L_11 , V_41 ) ;
V_11 = - V_36 ;
goto V_48;
}
V_40 -> V_69 = V_70 ;
V_40 -> V_71 = V_72 ;
#if V_73 > 8
F_9 ( V_9 , & V_10 ) ;
F_5 ( V_9 , & V_10 ) ;
if( F_26 ( & ( V_9 -> V_31 ) ) ) {
V_40 -> V_74 [ 0 ] = V_75 ;
V_40 -> V_74 [ 1 ] = V_76 ;
V_40 -> V_77 = 2 ;
V_40 -> V_78 = V_79 ;
}
#endif
V_40 -> V_80 = V_81 ;
V_40 -> V_82 = 1 ;
V_40 -> V_83 [ 0 ] = V_84 ;
#if V_73 > 10
V_40 -> V_85 = V_73 ;
V_40 -> V_86 = V_87 ;
#endif
#if V_73 > 11
F_9 ( V_9 , & V_10 ) ;
F_5 ( V_9 , & V_10 ) ;
F_22 ( V_12 , L_12 ) ;
F_27 ( V_9 -> V_2 ) ;
V_40 -> V_88 = V_9 -> V_89 . V_57 ;
F_22 ( V_12 , L_13 ) ;
#endif
V_40 -> V_90 [ 0 ] = ( V_91 |
F_28 ( V_92 ) |
F_28 ( V_93 ) ) ;
V_40 -> V_90 [ 1 ] = V_94 ;
V_40 -> V_90 [ 4 ] = ( F_28 ( V_95 ) |
F_28 ( V_96 ) |
F_28 ( V_97 ) ) ;
V_40 -> V_98 = V_99 | V_100 ;
V_48:
F_8 ( V_9 ) ;
F_9 ( V_9 , & V_10 ) ;
F_10 ( V_12 ) ;
return V_11 ;
}
static int F_29 ( struct V_1 * V_2 , struct V_3 * V_4 , struct V_101 * V_102 , char * V_7 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
unsigned long V_10 ;
int V_11 = 0 ;
#if 1
int V_41 = - 1 ;
#endif
F_3 ( L_14 ) ;
F_4 ( V_12 ) ;
if( V_9 -> V_13 == V_14 ) {
V_11 = - V_15 ;
goto V_16;
}
F_5 ( V_9 , & V_10 ) ;
F_6 ( V_9 ) ;
memset ( & V_102 -> V_103 , 0 , V_104 ) ;
V_102 -> V_105 = V_106 ;
memcpy ( & V_102 -> V_103 , V_9 -> V_2 -> V_107 , V_104 ) ;
#if 1
if ( F_30 ( V_9 -> V_31 . V_108 . V_109 ) == V_110 ) {
V_9 -> V_27 . V_29 = V_111 ;
V_9 -> V_27 . V_28 = 4 ;
V_41 = F_17 ( & ( V_9 -> V_31 ) , ( V_32 ) & ( V_9 -> V_27 ) ) ;
if( V_41 == V_33 ) {
memcpy ( & V_102 -> V_103 , V_9 -> V_27 . V_34 . V_67 , V_104 ) ;
} else {
V_11 = - V_36 ;
}
}
#endif
F_8 ( V_9 ) ;
F_9 ( V_9 , & V_10 ) ;
V_16:
F_10 ( V_12 ) ;
return V_11 ;
}
static int F_31 ( struct V_1 * V_2 , struct V_3 * V_4 , struct V_37 * V_38 , char * V_7 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
unsigned long V_10 ;
int V_11 ;
int V_112 = - 1 ;
int V_113 = 0 ;
T_3 V_42 ;
struct V_101 * V_114 = NULL ;
struct V_115 * V_57 = NULL ;
#ifdef F_32
T_4 * V_116 = & V_9 -> V_117 ;
#else
T_5 * V_116 = & V_9 -> V_118 ;
#endif
F_3 ( L_15 ) ;
F_4 ( V_12 ) ;
if( V_9 -> V_13 == V_14 ) {
V_11 = - V_15 ;
goto V_16;
}
F_5 ( V_9 , & V_10 ) ;
F_6 ( V_9 ) ;
V_9 -> V_117 . V_119 = FALSE ;
V_9 -> V_118 . V_119 = FALSE ;
V_9 -> V_27 . V_28 = 2 ;
V_9 -> V_27 . V_29 = V_120 ;
V_9 -> V_27 . V_34 . V_35 [ 0 ] = F_30 ( 0x7FFF ) ;
V_11 = F_33 ( & ( V_9 -> V_31 ) , ( V_32 ) & ( V_9 -> V_27 ) ) ;
F_22 ( V_12 , L_16 , V_11 ) ;
V_9 -> V_27 . V_28 = 2 ;
V_9 -> V_27 . V_29 = V_121 ;
V_9 -> V_27 . V_34 . V_35 [ 0 ] = F_30 ( 0 ) ;
V_11 = F_33 ( & ( V_9 -> V_31 ) , ( V_32 ) & ( V_9 -> V_27 ) ) ;
F_22 ( V_12 , L_17 , V_11 ) ;
#ifdef F_32
V_11 = F_34 ( & ( V_9 -> V_31 ) , V_122 ) ;
#else
V_11 = F_34 ( & ( V_9 -> V_31 ) , V_123 ) ;
#endif
F_8 ( V_9 ) ;
F_9 ( V_9 , & V_10 ) ;
if( V_11 == V_33 ) {
F_22 ( V_12 , L_18 ) ;
while( ( * V_116 ) . V_119 == FALSE && V_11 == V_33 ) {
F_22 ( V_12 , L_19 ) ;
if( V_113 ++ > V_124 ) {
V_11 = - V_125 ;
} else {
for( V_42 = 0 ; V_42 < 100 ; V_42 ++ ) {
F_35 ( 10 ) ;
F_36 ( ) ;
}
}
}
F_37 () ;
if ( V_11 != V_33 ) {
F_38 ( V_12 , L_20 ) ;
} else {
V_112 = ( * V_116 ) . V_112 ;
if ( V_112 > V_126 ) {
V_112 = V_126 ;
}
V_38 -> V_45 = V_112 ;
V_114 = (struct V_101 * ) V_7 ;
V_57 = (struct V_115 * ) V_7 +
( sizeof( struct V_101 ) * V_112 ) ;
V_38 -> V_10 = 0 ;
for( V_42 = 0 ; V_42 < V_112 ; V_42 ++ ) {
#ifdef F_32
memcpy ( V_114 [ V_42 ] . V_103 ,
( * V_116 ) . V_127 [ V_42 ] . V_128 , V_104 ) ;
#else
F_39 ( L_21 ,
( * V_116 ) . V_129 [ V_42 ] . V_130 ) ;
memcpy ( V_114 [ V_42 ] . V_103 ,
( * V_116 ) . V_129 [ V_42 ] . V_130 , V_104 ) ;
#endif
}
( * V_116 ) . V_119 = FALSE ;
F_40 ( V_9 -> V_2 ) ;
}
}
V_16:
F_10 ( V_12 ) ;
return V_11 ;
}
static int F_41 ( struct V_1 * V_2 , struct V_3 * V_4 , struct V_131 * V_132 , char * V_7 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
unsigned long V_10 ;
int V_11 = 0 ;
int V_133 = V_132 -> V_134 ;
F_3 ( L_22 ) ;
F_4 ( V_12 ) ;
if( V_9 -> V_13 == V_14 ) {
V_11 = - V_15 ;
goto V_16;
}
if( ( V_133 < 1 ) || ( V_133 > 3 ) ) {
V_11 = - V_135 ;
goto V_16;
}
F_5 ( V_9 , & V_10 ) ;
F_6 ( V_9 ) ;
V_9 -> V_136 = V_133 ;
F_7 ( V_9 ) ;
F_8 ( V_9 ) ;
F_9 ( V_9 , & V_10 ) ;
V_16:
F_10 ( V_12 ) ;
return V_11 ;
}
static int F_42 ( struct V_1 * V_2 , struct V_3 * V_4 , struct V_131 * V_132 , char * V_7 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
int V_11 = 0 ;
F_3 ( L_23 ) ;
F_4 ( V_12 ) ;
if( V_9 -> V_13 == V_14 ) {
V_11 = - V_15 ;
goto V_16;
}
V_132 -> V_134 = V_9 -> V_136 ;
V_132 -> V_137 = 0 ;
V_16:
F_10 ( V_12 ) ;
return V_11 ;
}
static int F_43 ( struct V_1 * V_2 , struct V_3 * V_4 , struct V_37 * V_38 , char * V_138 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
unsigned long V_10 ;
int V_11 = 0 ;
F_3 ( L_24 ) ;
F_4 ( V_12 ) ;
if( V_9 -> V_13 == V_14 ) {
V_11 = - V_15 ;
goto V_16;
}
if ( V_38 -> V_10 != 0 && V_38 -> V_45 > V_139 + 1 ) {
V_11 = - V_135 ;
goto V_16;
}
F_5 ( V_9 , & V_10 ) ;
F_6 ( V_9 ) ;
memset ( V_9 -> V_140 , 0 , sizeof( V_9 -> V_140 ) ) ;
if( V_38 -> V_10 == 0 ) {
if ( F_30 ( V_9 -> V_31 . V_108 . V_109 ) == V_110 ) {
strcpy ( V_9 -> V_140 , L_25 ) ;
} else {
strcpy ( V_9 -> V_140 , V_141 ) ;
}
} else {
memcpy ( V_9 -> V_140 , V_138 , V_38 -> V_45 ) ;
}
F_44 ( V_12 , L_26 , V_138 ) ;
F_7 ( V_9 ) ;
F_45 ( V_9 -> V_2 ) ;
F_8 ( V_9 ) ;
F_9 ( V_9 , & V_10 ) ;
V_16:
F_10 ( V_12 ) ;
return V_11 ;
}
static int F_46 ( struct V_1 * V_2 , struct V_3 * V_4 , struct V_37 * V_38 , char * V_142 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
unsigned long V_10 ;
int V_11 = 0 ;
int V_41 = - 1 ;
T_6 * V_143 ;
F_3 ( L_27 ) ;
F_4 ( V_12 ) ;
if( V_9 -> V_13 == V_14 ) {
V_11 = - V_15 ;
goto V_16;
}
F_5 ( V_9 , & V_10 ) ;
F_6 ( V_9 ) ;
V_9 -> V_27 . V_28 = 1 + ( sizeof( * V_143 ) / sizeof( T_1 ) ) ;
#if 1
V_9 -> V_27 . V_29 = V_144 ;
#endif
#if 1
if ( F_30 ( V_9 -> V_31 . V_108 . V_109 ) == V_145 ) {
V_9 -> V_27 . V_29 = V_146 ;
}
#endif
V_41 = F_17 ( & ( V_9 -> V_31 ) , ( V_32 ) & ( V_9 -> V_27 ) ) ;
if( V_41 == V_33 ) {
V_143 = ( T_6 * ) & ( V_9 -> V_27 . V_34 . V_49 ) ;
V_143 -> V_45 = F_18 ( V_143 -> V_45 ) ;
V_38 -> V_45 = V_143 -> V_45 ;
V_38 -> V_45 = V_143 -> V_45 + 1 ;
if( V_143 -> V_45 < V_139 ) {
V_143 -> V_17 [ V_143 -> V_45 ] = '\0' ;
}
V_38 -> V_10 = 1 ;
#if 1
#ifdef F_47
if( V_143 -> V_17 [ 0 ] == '\0' ) {
V_9 -> V_27 . V_28 = 1 + ( sizeof( * V_143 ) / sizeof( T_1 ) ) ;
V_9 -> V_27 . V_29 = V_147 ;
V_41 = F_17 ( & ( V_9 -> V_31 ) , ( V_32 ) & ( V_9 -> V_27 ) ) ;
if( V_41 == V_33 ) {
V_143 = ( T_6 * ) & ( V_9 -> V_27 . V_34 . V_49 ) ;
V_143 -> V_45 = F_18 ( V_143 -> V_45 ) ;
V_38 -> V_45 = V_143 -> V_45 + 1 ;
if( V_143 -> V_45 < V_139 ) {
V_143 -> V_17 [ V_143 -> V_45 ] = '\0' ;
}
V_38 -> V_10 = 1 ;
} else {
V_11 = - V_36 ;
goto V_48;
}
}
#endif
#endif
V_38 -> V_45 -- ;
if ( V_143 -> V_45 > V_148 ) {
V_11 = - V_36 ;
goto V_48;
}
memcpy ( V_142 , V_143 -> V_17 , V_143 -> V_45 ) ;
} else {
V_11 = - V_36 ;
goto V_48;
}
V_48:
F_8 ( V_9 ) ;
F_9 ( V_9 , & V_10 ) ;
V_16:
F_10 ( V_12 ) ;
return V_11 ;
}
static int F_48 ( struct V_1 * V_2 , struct V_3 * V_4 , struct V_37 * V_149 , char * V_150 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
unsigned long V_10 ;
int V_11 = 0 ;
#if 1
T_7 V_151 ;
#endif
F_3 ( L_28 ) ;
F_4 ( V_12 ) ;
if( V_9 -> V_13 == V_14 ) {
V_11 = - V_15 ;
goto V_16;
}
F_5 ( V_9 , & V_10 ) ;
F_6 ( V_9 ) ;
if( ! F_26 ( & ( V_9 -> V_31 ) ) ) {
F_49 ( V_12 , L_29 ) ;
V_11 = - V_152 ;
goto V_48;
}
F_44 ( V_12 , L_30 ,
V_150 , V_149 -> V_45 ,
V_149 -> V_10 ) ;
V_151 = V_9 -> V_153 ;
if( ( V_149 -> V_45 ) != 0 ) {
int V_154 = ( V_149 -> V_10 & V_155 ) - 1 ;
int V_156 = V_9 -> V_157 - 1 ;
switch( V_149 -> V_45 ) {
case 0 :
break;
case V_75 :
case V_76 :
if( ( V_154 < 0 ) || ( V_154 >= V_79 ) ) {
V_154 = V_156 ;
}
memset ( V_9 -> V_158 . V_159 [ V_154 ] . V_159 , 0 , V_76 ) ;
memcpy ( V_9 -> V_158 . V_159 [ V_154 ] . V_159 , V_150 , V_149 -> V_45 ) ;
V_9 -> V_158 . V_159 [ V_154 ] . V_28 = V_149 -> V_45 ;
F_44 ( V_12 , L_31 , V_149 -> V_45 ) ;
F_44 ( V_12 , L_32 , V_9 -> V_158 . V_159 [ V_154 ] . V_159 ,
V_9 -> V_158 . V_159 [ V_154 ] . V_28 , V_154 ) ;
if( ( V_154 == V_156 ) && ( V_9 -> V_158 . V_159 [ V_156 ] . V_28 > 0 ) ) {
V_9 -> V_153 = 1 ;
}
break;
default:
F_49 ( V_12 , L_33 ) ;
V_11 = - V_135 ;
goto V_48;
}
} else {
int V_154 = ( V_149 -> V_10 & V_155 ) - 1 ;
if( ( V_154 >= 0 ) && ( V_154 < V_79 ) ) {
F_44 ( V_12 , L_34 , V_154 ,
V_9 -> V_158 . V_159 [ V_154 ] . V_28 ) ;
if( V_9 -> V_158 . V_159 [ V_154 ] . V_28 > 0 ) {
V_9 -> V_157 = V_154 + 1 ;
V_9 -> V_153 = 1 ;
} else {
F_49 ( V_12 , L_35 ) ;
F_10 ( V_12 ) ;
V_11 = - V_135 ;
}
}
}
if( V_149 -> V_10 & V_160 ) {
V_9 -> V_153 = 0 ;
} else {
V_9 -> V_153 = 1 ;
}
if( V_149 -> V_10 & V_161 ) {
F_49 ( V_12 , L_36 ) ;
V_11 = - V_135 ;
}
F_22 ( V_12 , L_37 , V_151 ) ;
F_22 ( V_12 , L_38 , V_9 -> V_153 ) ;
F_22 ( V_12 , L_39 ,
V_149 -> V_45 ) ;
F_22 ( V_12 , L_40 ,
V_149 -> V_10 ) ;
if( V_11 == 0 ) {
F_44 ( V_12 , L_41 , V_9 -> V_153 ,
V_9 -> V_157 ) ;
if( V_9 -> V_153 == V_151 ) {
if( V_149 -> V_45 != 0 ) {
F_50 ( V_9 ) ;
}
} else {
F_7 ( V_9 ) ;
}
}
F_51 ( V_2 ) ;
V_48:
F_8 ( V_9 ) ;
F_9 ( V_9 , & V_10 ) ;
V_16:
F_10 ( V_12 ) ;
return V_11 ;
}
static int F_52 ( struct V_1 * V_2 , struct V_3 * V_4 , struct V_37 * V_149 , char * V_159 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
unsigned long V_10 ;
int V_11 = 0 ;
int V_154 ;
F_3 ( L_42 ) ;
F_4 ( V_12 ) ;
F_44 ( V_12 , L_43 , V_9 -> V_153 , V_9 -> V_157 ) ;
if( V_9 -> V_13 == V_14 ) {
V_11 = - V_15 ;
goto V_16;
}
if( ! F_13 ( V_21 ) ) {
V_11 = - V_22 ;
F_10 ( V_12 ) ;
return V_11 ;
}
F_5 ( V_9 , & V_10 ) ;
F_6 ( V_9 ) ;
if( ! F_26 ( & ( V_9 -> V_31 ) ) ) {
V_11 = - V_152 ;
goto V_48;
}
V_154 = ( V_149 -> V_10 & V_155 ) - 1 ;
V_149 -> V_10 = 0 ;
if( V_9 -> V_153 == 0 ) {
V_149 -> V_10 |= V_160 ;
}
if( ( V_154 < 0 ) || ( V_154 >= V_79 ) ) {
V_154 = V_9 -> V_157 - 1 ;
}
V_149 -> V_10 |= V_154 + 1 ;
V_149 -> V_45 = V_9 -> V_158 . V_159 [ V_154 ] . V_28 ;
memcpy ( V_159 , V_9 -> V_158 . V_159 [ V_154 ] . V_159 , V_149 -> V_45 ) ;
V_48:
F_8 ( V_9 ) ;
F_9 ( V_9 , & V_10 ) ;
V_16:
F_10 ( V_12 ) ;
return V_11 ;
}
static int F_53 ( struct V_1 * V_2 , struct V_3 * V_4 , struct V_37 * V_38 , char * V_162 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
unsigned long V_10 ;
int V_11 = 0 ;
F_3 ( L_44 ) ;
F_4 ( V_12 ) ;
if( V_9 -> V_13 == V_14 ) {
V_11 = - V_15 ;
goto V_16;
}
#if 0
if( !capable(CAP_NET_ADMIN )) {
ret = -EPERM;
DBG_LEAVE( DbgInfo );
return ret;
}
#endif
if( V_38 -> V_45 > V_139 ) {
V_11 = - V_135 ;
goto V_16;
}
F_5 ( V_9 , & V_10 ) ;
F_6 ( V_9 ) ;
memset ( V_9 -> V_163 , 0 , sizeof( V_9 -> V_163 ) ) ;
memcpy ( V_9 -> V_163 , V_162 , V_38 -> V_45 ) ;
F_7 ( V_9 ) ;
F_8 ( V_9 ) ;
F_9 ( V_9 , & V_10 ) ;
V_16:
F_10 ( V_12 ) ;
return V_11 ;
}
static int F_54 ( struct V_1 * V_2 , struct V_3 * V_4 , struct V_37 * V_38 , char * V_162 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
unsigned long V_10 ;
int V_11 = 0 ;
int V_41 = - 1 ;
T_6 * V_143 ;
F_3 ( L_45 ) ;
F_4 ( V_12 ) ;
if( V_9 -> V_13 == V_14 ) {
V_11 = - V_15 ;
goto V_16;
}
F_5 ( V_9 , & V_10 ) ;
F_6 ( V_9 ) ;
V_9 -> V_27 . V_28 = 1 + ( sizeof( * V_143 ) / sizeof( T_1 ) ) ;
V_9 -> V_27 . V_29 = V_164 ;
V_41 = F_17 ( & ( V_9 -> V_31 ) , ( V_32 ) & ( V_9 -> V_27 ) ) ;
if( V_41 == V_33 ) {
V_143 = ( T_6 * ) & ( V_9 -> V_27 . V_34 . V_49 ) ;
V_143 -> V_45 = F_18 ( V_143 -> V_45 ) ;
if ( V_143 -> V_45 > V_148 ) {
V_11 = - V_36 ;
} else {
V_38 -> V_45 = V_143 -> V_45 ;
memcpy ( V_162 , V_143 -> V_17 , V_143 -> V_45 ) ;
}
} else {
V_11 = - V_36 ;
}
F_8 ( V_9 ) ;
F_9 ( V_9 , & V_10 ) ;
V_16:
F_10 ( V_12 ) ;
return V_11 ;
}
static int F_55 ( struct V_1 * V_2 , struct V_3 * V_4 , T_8 * V_165 , char * V_7 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
unsigned long V_10 ;
int V_11 = 0 ;
T_1 V_166 ;
T_1 V_167 ;
F_3 ( L_46 ) ;
F_4 ( V_12 ) ;
if( V_9 -> V_13 == V_14 ) {
V_11 = - V_15 ;
goto V_16;
}
F_5 ( V_9 , & V_10 ) ;
F_6 ( V_9 ) ;
switch( * V_165 ) {
case V_168 :
V_166 = 1 ;
V_167 = 1 ;
V_9 -> V_169 = V_170 ;
break;
case V_171 :
case V_172 :
V_166 = 1 ;
V_167 = 0 ;
V_9 -> V_169 = V_170 ;
break;
#if 0
case IW_MODE_MASTER:
portType = 1;
lp->CreateIBSS = 0;
lp->DownloadFirmware = WVLAN_DRV_MODE_AP;
break;
#endif
default:
V_166 = 0 ;
V_167 = 0 ;
V_11 = - V_135 ;
}
if( V_166 != 0 ) {
if( ( V_9 -> V_173 != V_166 ) || ( V_9 -> V_174 != V_167 ) ) {
V_9 -> V_173 = V_166 ;
V_9 -> V_174 = V_167 ;
F_56 ( V_9 ) ;
F_57 ( V_9 -> V_2 ) ;
}
}
F_8 ( V_9 ) ;
F_9 ( V_9 , & V_10 ) ;
V_16:
F_10 ( V_12 ) ;
return V_11 ;
}
static int F_58 ( struct V_1 * V_2 , struct V_3 * V_4 , T_8 * V_165 , char * V_7 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
unsigned long V_10 ;
int V_11 = 0 ;
int V_41 = - 1 ;
T_1 * V_175 ;
F_3 ( L_47 ) ;
F_4 ( V_12 ) ;
if( V_9 -> V_13 == V_14 ) {
V_11 = - V_15 ;
goto V_16;
}
F_5 ( V_9 , & V_10 ) ;
F_6 ( V_9 ) ;
V_9 -> V_27 . V_28 = 1 + ( sizeof( * V_175 ) / sizeof( T_1 ) ) ;
V_9 -> V_27 . V_29 = V_176 ;
V_41 = F_17 ( & ( V_9 -> V_31 ) , ( V_32 ) & ( V_9 -> V_27 ) ) ;
if( V_41 == V_33 ) {
V_175 = ( T_1 * ) & ( V_9 -> V_27 . V_34 . V_49 ) ;
* V_175 = F_18 ( * V_175 ) ;
switch( * V_175 ) {
case 1 :
#if 0
#if ( V_177 ) & V_178
if ( CNV_INT_TO_LITTLE( lp->hcfCtx.IFB_FWIdentity.comp_id ) == COMP_ID_FW_AP ) {
*mode = IW_MODE_MASTER;
} else {
*mode = IW_MODE_INFRA;
}
#else
*mode = IW_MODE_INFRA;
#endif
#endif
if ( F_30 ( V_9 -> V_31 . V_108 . V_109 ) == V_145 ) {
* V_165 = V_179 ;
} else {
if( V_9 -> V_174 ) {
* V_165 = V_168 ;
} else {
* V_165 = V_172 ;
}
}
break;
case 3 :
* V_165 = V_168 ;
break;
default:
V_11 = - V_36 ;
break;
}
} else {
V_11 = - V_36 ;
}
F_8 ( V_9 ) ;
F_9 ( V_9 , & V_10 ) ;
V_16:
F_10 ( V_12 ) ;
return V_11 ;
}
static int F_59 ( struct V_1 * V_2 , struct V_3 * V_4 , struct V_131 * V_180 , char * V_7 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
unsigned long V_10 ;
int V_11 = 0 ;
F_3 ( L_48 ) ;
F_4 ( V_12 ) ;
if( V_9 -> V_13 == V_14 ) {
V_11 = - V_15 ;
goto V_16;
}
F_39 ( L_49 ) ;
#if 0
if( !capable( CAP_NET_ADMIN )) {
ret = -EPERM;
DBG_LEAVE( DbgInfo );
return ret;
}
#endif
F_5 ( V_9 , & V_10 ) ;
F_6 ( V_9 ) ;
if( V_180 -> V_181 ) {
V_9 -> V_182 = 0 ;
} else {
V_9 -> V_182 = 1 ;
}
F_7 ( V_9 ) ;
F_8 ( V_9 ) ;
F_9 ( V_9 , & V_10 ) ;
V_16:
F_10 ( V_12 ) ;
return V_11 ;
}
static int F_60 ( struct V_1 * V_2 , struct V_3 * V_4 , struct V_131 * V_183 , char * V_7 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
unsigned long V_10 ;
int V_11 = 0 ;
F_3 ( L_50 ) ;
F_4 ( V_12 ) ;
if( V_9 -> V_13 == V_14 ) {
V_11 = - V_15 ;
goto V_16;
}
F_39 ( L_51 ) ;
F_5 ( V_9 , & V_10 ) ;
F_6 ( V_9 ) ;
V_183 -> V_10 = 0 ;
V_183 -> V_134 = 0 ;
if( V_9 -> V_182 ) {
V_183 -> V_181 = 0 ;
} else {
V_183 -> V_181 = 1 ;
}
F_8 ( V_9 ) ;
F_9 ( V_9 , & V_10 ) ;
V_16:
F_10 ( V_12 ) ;
return V_11 ;
}
static int F_61 ( struct V_1 * V_2 , struct V_3 * V_4 , struct V_131 * V_183 , char * V_7 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
unsigned long V_10 ;
int V_11 = 0 ;
F_3 ( L_52 ) ;
F_4 ( V_12 ) ;
if( V_9 -> V_13 == V_14 ) {
V_11 = - V_15 ;
goto V_16;
}
F_5 ( V_9 , & V_10 ) ;
F_6 ( V_9 ) ;
#ifdef F_62
V_183 -> V_134 = V_184 ;
V_183 -> V_10 = V_185 ;
#else
V_183 -> V_134 = V_84 ;
V_183 -> V_10 = V_81 ;
#endif
V_183 -> V_137 = 1 ;
V_183 -> V_181 = 0 ;
F_8 ( V_9 ) ;
F_9 ( V_9 , & V_10 ) ;
V_16:
F_10 ( V_12 ) ;
return V_11 ;
}
static int F_63 ( struct V_1 * V_2 , struct V_3 * V_4 , struct V_131 * V_186 , char * V_7 )
{
int V_11 = 0 ;
struct V_8 * V_9 = F_2 ( V_2 ) ;
unsigned long V_10 ;
int V_187 = V_186 -> V_134 ;
F_3 ( L_53 ) ;
F_4 ( V_12 ) ;
if( V_9 -> V_13 == V_14 ) {
V_11 = - V_15 ;
goto V_16;
}
if( V_186 -> V_137 == 0 ) {
V_11 = - V_135 ;
goto V_16;
}
#if V_73 > 8
if( V_186 -> V_181 ) {
V_187 = 2347 ;
}
#endif
if( ( V_187 < 256 ) || ( V_187 > 2347 ) ) {
V_11 = - V_135 ;
goto V_16;
}
F_5 ( V_9 , & V_10 ) ;
F_6 ( V_9 ) ;
V_9 -> V_188 = V_187 ;
F_7 ( V_9 ) ;
F_8 ( V_9 ) ;
F_9 ( V_9 , & V_10 ) ;
V_16:
F_10 ( V_12 ) ;
return V_11 ;
}
static int F_64 ( struct V_1 * V_2 , struct V_3 * V_4 , struct V_131 * V_186 , char * V_7 )
{
int V_11 = 0 ;
struct V_8 * V_9 = F_2 ( V_2 ) ;
unsigned long V_10 ;
F_3 ( L_54 ) ;
F_4 ( V_12 ) ;
if( V_9 -> V_13 == V_14 ) {
V_11 = - V_15 ;
goto V_16;
}
F_5 ( V_9 , & V_10 ) ;
F_6 ( V_9 ) ;
V_186 -> V_134 = V_9 -> V_188 ;
#if V_73 > 8
V_186 -> V_181 = ( V_186 -> V_134 == 2347 ) ;
#endif
V_186 -> V_137 = 1 ;
F_8 ( V_9 ) ;
F_9 ( V_9 , & V_10 ) ;
V_16:
F_10 ( V_12 ) ;
return V_11 ;
}
static int F_65 ( struct V_1 * V_2 , struct V_3 * V_4 , struct V_131 * V_183 , char * V_7 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
unsigned long V_10 ;
int V_11 = 0 ;
#ifdef F_32
int V_41 = - 1 ;
int V_154 = 0 ;
#endif
F_3 ( L_55 ) ;
F_4 ( V_12 ) ;
if( V_9 -> V_13 == V_14 ) {
V_11 = - V_15 ;
goto V_16;
}
F_5 ( V_9 , & V_10 ) ;
F_6 ( V_9 ) ;
#ifdef F_32
V_9 -> V_27 . V_28 = 2 ;
V_9 -> V_27 . V_29 = V_30 ;
V_41 = F_17 ( & ( V_9 -> V_31 ) , ( V_32 ) & ( V_9 -> V_27 ) ) ;
if( V_41 == V_33 ) {
V_154 = ( F_18 ( V_9 -> V_27 . V_34 . V_35 [ 0 ] ) & 0x100 ) ? 1 : 0 ;
F_39 ( L_56 , V_154 ) ;
} else {
F_38 ( V_12 , L_57 ) ;
F_10 ( V_12 ) ;
V_11 = - V_135 ;
goto V_48;
}
if( V_183 -> V_134 > 0 &&
V_183 -> V_134 <= 1 * V_51 ) {
V_9 -> V_189 [ V_154 ] = 0x0001 ;
}
else if( V_183 -> V_134 > 1 * V_51 &&
V_183 -> V_134 <= 2 * V_51 ) {
if( V_183 -> V_137 == 1 ) {
V_9 -> V_189 [ V_154 ] = 0x0002 ;
} else {
V_9 -> V_189 [ V_154 ] = 0x0003 ;
}
}
else if( V_183 -> V_134 > 2 * V_51 &&
V_183 -> V_134 <= 5 * V_51 ) {
if( V_183 -> V_137 == 1 ) {
V_9 -> V_189 [ V_154 ] = 0x0004 ;
} else {
V_9 -> V_189 [ V_154 ] = 0x0007 ;
}
}
else if( V_183 -> V_134 > 5 * V_51 &&
V_183 -> V_134 <= 6 * V_51 ) {
if( V_183 -> V_137 == 1 ) {
V_9 -> V_189 [ V_154 ] = 0x0010 ;
} else {
V_9 -> V_189 [ V_154 ] = 0x0017 ;
}
}
else if( V_183 -> V_134 > 6 * V_51 &&
V_183 -> V_134 <= 9 * V_51 ) {
if( V_183 -> V_137 == 1 ) {
V_9 -> V_189 [ V_154 ] = 0x0020 ;
} else {
V_9 -> V_189 [ V_154 ] = 0x0037 ;
}
}
else if( V_183 -> V_134 > 9 * V_51 &&
V_183 -> V_134 <= 11 * V_51 ) {
if( V_183 -> V_137 == 1 ) {
V_9 -> V_189 [ V_154 ] = 0x0008 ;
} else {
V_9 -> V_189 [ V_154 ] = 0x003F ;
}
}
else if( V_183 -> V_134 > 11 * V_51 &&
V_183 -> V_134 <= 12 * V_51 ) {
if( V_183 -> V_137 == 1 ) {
V_9 -> V_189 [ V_154 ] = 0x0040 ;
} else {
V_9 -> V_189 [ V_154 ] = 0x007F ;
}
}
else if( V_183 -> V_134 > 12 * V_51 &&
V_183 -> V_134 <= 18 * V_51 ) {
if( V_183 -> V_137 == 1 ) {
V_9 -> V_189 [ V_154 ] = 0x0080 ;
} else {
V_9 -> V_189 [ V_154 ] = 0x00FF ;
}
}
else if( V_183 -> V_134 > 18 * V_51 &&
V_183 -> V_134 <= 24 * V_51 ) {
if( V_183 -> V_137 == 1 ) {
V_9 -> V_189 [ V_154 ] = 0x0100 ;
} else {
V_9 -> V_189 [ V_154 ] = 0x01FF ;
}
}
else if( V_183 -> V_134 > 24 * V_51 &&
V_183 -> V_134 <= 36 * V_51 ) {
if( V_183 -> V_137 == 1 ) {
V_9 -> V_189 [ V_154 ] = 0x0200 ;
} else {
V_9 -> V_189 [ V_154 ] = 0x03FF ;
}
}
else if( V_183 -> V_134 > 36 * V_51 &&
V_183 -> V_134 <= 48 * V_51 ) {
if( V_183 -> V_137 == 1 ) {
V_9 -> V_189 [ V_154 ] = 0x0400 ;
} else {
V_9 -> V_189 [ V_154 ] = 0x07FF ;
}
}
else if( V_183 -> V_134 > 48 * V_51 &&
V_183 -> V_134 <= 54 * V_51 ) {
if( V_183 -> V_137 == 1 ) {
V_9 -> V_189 [ V_154 ] = 0x0800 ;
} else {
V_9 -> V_189 [ V_154 ] = 0x0FFF ;
}
}
else if( V_183 -> V_137 == 0 ) {
V_9 -> V_189 [ V_154 ] = V_190 ;
} else {
V_183 -> V_134 = 0 ;
V_11 = - V_135 ;
goto V_48;
}
#else
if( V_183 -> V_134 > 0 &&
V_183 -> V_134 <= 1 * V_51 ) {
V_9 -> V_189 [ 0 ] = 1 ;
}
else if( V_183 -> V_134 > 1 * V_51 &&
V_183 -> V_134 <= 2 * V_51 ) {
if( V_183 -> V_137 ) {
V_9 -> V_189 [ 0 ] = 2 ;
} else {
V_9 -> V_189 [ 0 ] = 6 ;
}
}
else if( V_183 -> V_134 > 2 * V_51 &&
V_183 -> V_134 <= 5 * V_51 ) {
if( V_183 -> V_137 ) {
V_9 -> V_189 [ 0 ] = 4 ;
} else {
V_9 -> V_189 [ 0 ] = 7 ;
}
}
else if( V_183 -> V_134 > 5 * V_51 &&
V_183 -> V_134 <= 11 * V_51 ) {
if( V_183 -> V_137 ) {
V_9 -> V_189 [ 0 ] = 5 ;
} else {
V_9 -> V_189 [ 0 ] = 3 ;
}
}
else if( V_183 -> V_137 == 0 ) {
V_9 -> V_189 [ 0 ] = 3 ;
} else {
V_183 -> V_134 = 0 ;
V_11 = - V_135 ;
goto V_48;
}
#endif
F_7 ( V_9 ) ;
V_48:
F_8 ( V_9 ) ;
F_9 ( V_9 , & V_10 ) ;
V_16:
F_10 ( V_12 ) ;
return V_11 ;
}
static int F_66 ( struct V_1 * V_2 , struct V_3 * V_4 , struct V_131 * V_183 , char * V_7 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
unsigned long V_10 ;
int V_11 = 0 ;
int V_41 = - 1 ;
T_1 V_191 ;
F_3 ( L_58 ) ;
F_4 ( V_12 ) ;
if( V_9 -> V_13 == V_14 ) {
V_11 = - V_15 ;
goto V_16;
}
F_5 ( V_9 , & V_10 ) ;
F_6 ( V_9 ) ;
V_9 -> V_27 . V_28 = 1 + ( sizeof( V_191 ) / sizeof( T_1 ) ) ;
V_9 -> V_27 . V_29 = V_47 ;
V_41 = F_17 ( & ( V_9 -> V_31 ) , ( V_32 ) & ( V_9 -> V_27 ) ) ;
if( V_41 == V_33 ) {
#ifdef F_32
V_191 = F_18 ( V_9 -> V_27 . V_34 . V_35 [ 0 ] ) ;
if( V_191 & 0x0001 ) {
V_191 = 1 ;
}
else if( V_191 & 0x0002 ) {
V_191 = 2 ;
}
else if( V_191 & 0x0004 ) {
V_191 = 5 ;
}
else if( V_191 & 0x0008 ) {
V_191 = 11 ;
}
else if( V_191 & 0x00010 ) {
V_191 = 6 ;
}
else if( V_191 & 0x00020 ) {
V_191 = 9 ;
}
else if( V_191 & 0x00040 ) {
V_191 = 12 ;
}
else if( V_191 & 0x00080 ) {
V_191 = 18 ;
}
else if( V_191 & 0x00100 ) {
V_191 = 24 ;
}
else if( V_191 & 0x00200 ) {
V_191 = 36 ;
}
else if( V_191 & 0x00400 ) {
V_191 = 48 ;
}
else if( V_191 & 0x00800 ) {
V_191 = 54 ;
}
#else
V_191 = ( T_1 ) F_67 ( V_9 -> V_27 . V_34 . V_49 [ 0 ] ) ;
#endif
V_183 -> V_134 = V_191 * V_51 ;
} else {
V_183 -> V_134 = 0 ;
V_11 = - V_36 ;
}
F_8 ( V_9 ) ;
F_9 ( V_9 , & V_10 ) ;
V_16:
F_10 ( V_12 ) ;
return V_11 ;
}
static int F_68 ( struct V_1 * V_2 , struct V_3 * V_4 , struct V_37 * V_38 , char * V_7 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
unsigned long V_10 ;
int V_11 = 0 ;
int V_41 = - 1 ;
int V_44 = 0 ;
F_3 ( L_59 ) ;
F_4 ( V_12 ) ;
if( V_9 -> V_13 == V_14 ) {
V_11 = - V_15 ;
goto V_16;
}
F_5 ( V_9 , & V_10 ) ;
F_6 ( V_9 ) ;
if( ( V_9 -> V_31 . V_192 & V_193 ) != 0 )
{
F_22 ( V_12 , L_60 ) ;
F_23 ( V_2 ) ;
}
V_46:
V_9 -> V_118 . V_119 = FALSE ;
#ifdef F_32
V_9 -> V_27 . V_28 = 5 ;
V_9 -> V_27 . V_29 = V_194 ;
V_9 -> V_27 . V_34 . V_35 [ 0 ] = F_30 ( 0x3FFF ) ;
V_9 -> V_27 . V_34 . V_35 [ 1 ] = F_30 ( 0xFFFF ) ;
V_9 -> V_27 . V_34 . V_35 [ 2 ] = F_30 ( 0xFFFF ) ;
V_9 -> V_27 . V_34 . V_35 [ 3 ] = F_30 ( 0x0007 ) ;
#else
V_9 -> V_27 . V_28 = 2 ;
V_9 -> V_27 . V_29 = V_194 ;
V_9 -> V_27 . V_34 . V_35 [ 0 ] = F_30 ( 0x7FFF ) ;
#endif
V_41 = F_33 ( & ( V_9 -> V_31 ) , ( V_32 ) & ( V_9 -> V_27 ) ) ;
F_22 ( V_12 , L_61 , V_41 ) ;
F_9 ( V_9 , & V_10 ) ;
F_5 ( V_9 , & V_10 ) ;
if( V_41 != V_33 ) {
V_44 ++ ;
if( V_44 <= 10 ) {
F_22 ( V_12 , L_62 , V_44 ) ;
F_23 ( V_2 ) ;
F_9 ( V_9 , & V_10 ) ;
F_5 ( V_9 , & V_10 ) ;
goto V_46;
}
}
V_9 -> V_27 . V_28 = 18 ;
V_9 -> V_27 . V_29 = V_121 ;
V_9 -> V_27 . V_34 . V_35 [ 0 ] = F_30 ( 0 ) ;
V_9 -> V_27 . V_34 . V_35 [ 1 ] = F_30 ( 0 ) ;
V_41 = F_33 ( & ( V_9 -> V_31 ) , ( V_32 ) & ( V_9 -> V_27 ) ) ;
F_9 ( V_9 , & V_10 ) ;
F_5 ( V_9 , & V_10 ) ;
F_22 ( V_12 , L_63 , V_41 ) ;
V_41 = F_34 ( & ( V_9 -> V_31 ) , V_123 ) ;
if( V_41 == V_33 ) {
F_22 ( V_12 , L_18 ) ;
} else {
F_22 ( V_12 , L_64 ) ;
}
F_8 ( V_9 ) ;
F_9 ( V_9 , & V_10 ) ;
V_16:
F_10 ( V_12 ) ;
return V_11 ;
}
static int F_69 ( struct V_1 * V_2 , struct V_3 * V_4 , struct V_37 * V_38 , char * V_7 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
unsigned long V_10 ;
int V_11 = 0 ;
int V_42 ;
char * V_195 ;
char * V_196 ;
struct V_197 V_198 ;
T_9 * V_199 ;
T_7 V_200 [ 512 ] ;
T_7 * V_201 ;
T_1 V_202 ;
F_3 ( L_65 ) ;
F_4 ( V_12 ) ;
if( V_9 -> V_13 == V_14 ) {
V_11 = - V_15 ;
goto V_16;
}
F_5 ( V_9 , & V_10 ) ;
F_6 ( V_9 ) ;
if( ! V_9 -> V_118 . V_119 ) {
V_11 = - V_203 ;
goto V_48;
}
F_22 ( V_12 , L_66 ,
V_9 -> V_118 . V_112 ) ;
V_195 = V_7 ;
V_196 = V_7 + V_204 ;
for( V_42 = 0 ; V_42 < V_9 -> V_118 . V_112 ; V_42 ++ ) {
V_199 = ( T_9 * ) & V_9 -> V_118 . V_129 [ V_42 ] ;
memset ( & V_198 , 0 , sizeof( V_198 ) ) ;
V_198 . V_205 = V_92 ;
V_198 . V_34 . V_102 . V_105 = V_106 ;
memcpy ( V_198 . V_34 . V_102 . V_103 , V_199 -> V_130 , V_104 ) ;
V_198 . V_28 = V_206 ;
V_195 = F_70 ( V_4 , V_195 , V_196 , & V_198 , V_206 ) ;
memset ( & V_198 , 0 , sizeof( V_198 ) ) ;
V_198 . V_205 = V_207 ;
if( V_199 -> V_208 & V_209 ) {
V_198 . V_34 . V_165 = V_172 ;
} else {
V_198 . V_34 . V_165 = V_179 ;
}
V_198 . V_28 = V_210 ;
V_195 = F_70 ( V_4 , V_195 , V_196 , & V_198 , V_210 ) ;
memset ( & V_198 , 0 , sizeof( V_198 ) ) ;
V_198 . V_205 = V_211 ;
V_198 . V_34 . V_57 . V_60 = F_25 ( V_199 -> signal ) ;
V_198 . V_34 . V_57 . V_62 = F_25 ( V_199 -> V_212 ) ;
V_198 . V_34 . V_57 . V_57 = V_198 . V_34 . V_57 . V_60 - V_198 . V_34 . V_57 . V_62 ;
V_198 . V_34 . V_57 . V_213 = V_9 -> V_118 . V_119 | V_214 ;
V_198 . V_28 = V_215 ;
V_195 = F_70 ( V_4 , V_195 , V_196 , & V_198 , V_215 ) ;
if( V_199 -> V_216 [ 1 ] > 0 ) {
memset ( & V_198 , 0 , sizeof( V_198 ) ) ;
V_198 . V_205 = V_217 ;
V_198 . V_34 . V_38 . V_45 = V_199 -> V_216 [ 1 ] ;
V_198 . V_34 . V_38 . V_10 = 1 ;
V_195 = F_71 ( V_4 , V_195 , V_196 , & V_198 , & V_199 -> V_216 [ 2 ] ) ;
}
memset ( & V_198 , 0 , sizeof( V_198 ) ) ;
V_198 . V_205 = V_218 ;
V_198 . V_34 . V_38 . V_45 = 0 ;
if( V_199 -> V_208 & V_219 ) {
V_198 . V_34 . V_38 . V_10 |= V_220 ;
} else {
V_198 . V_34 . V_38 . V_10 |= V_160 ;
}
V_195 = F_71 ( V_4 , V_195 , V_196 , & V_198 , NULL ) ;
memset ( & V_198 , 0 , sizeof( V_198 ) ) ;
V_198 . V_205 = V_221 ;
V_198 . V_28 = V_222 ;
V_198 . V_34 . V_19 . V_25 = F_72 ( V_199 ) ;
V_198 . V_34 . V_19 . V_23 = 0 ;
V_195 = F_70 ( V_4 , V_195 , V_196 , & V_198 , V_222 ) ;
#if V_73 > 14
memset ( & V_198 , 0 , sizeof( V_198 ) ) ;
memset ( V_200 , 0 , sizeof( V_200 ) ) ;
V_198 . V_205 = V_96 ;
sprintf ( V_200 , L_67 , V_199 -> V_223 ) ;
V_198 . V_34 . V_38 . V_45 = strlen ( V_200 ) ;
V_195 = F_71 ( V_4 , V_195 , V_196 , & V_198 , V_200 ) ;
V_201 = NULL ;
V_202 = 0 ;
V_201 = F_73 ( V_199 , & V_202 ) ;
if( V_201 != NULL ) {
memset ( & V_198 , 0 , sizeof( V_198 ) ) ;
memset ( V_200 , 0 , sizeof( V_200 ) ) ;
V_198 . V_205 = V_96 ;
sprintf ( V_200 , L_68 , F_74 ( V_201 , V_202 ) ) ;
V_198 . V_34 . V_38 . V_45 = strlen ( V_200 ) ;
V_195 = F_71 ( V_4 , V_195 , V_196 , & V_198 , V_200 ) ;
}
#endif
}
V_38 -> V_45 = V_195 - V_7 ;
V_48:
F_8 ( V_9 ) ;
F_9 ( V_9 , & V_10 ) ;
V_16:
F_10 ( V_12 ) ;
return V_11 ;
}
static int F_75 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_131 * V_38 , char * V_7 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
unsigned long V_10 ;
int V_11 ;
int V_224 = V_38 -> V_10 & V_225 ;
int V_226 = V_38 -> V_134 ;
F_3 ( L_69 ) ;
F_4 ( V_12 ) ;
if( V_9 -> V_13 == V_14 ) {
V_11 = - V_15 ;
goto V_16;
}
F_5 ( V_9 , & V_10 ) ;
F_6 ( V_9 ) ;
switch ( V_224 ) {
case V_227 :
F_22 ( V_12 , L_70 ) ;
if ( V_226 == V_228 )
V_11 = 0 ;
else
V_11 = - V_135 ;
break;
case V_229 :
F_22 ( V_12 , L_71 , V_226 ) ;
if ( V_226 )
V_9 -> V_153 = 2 ;
else
V_9 -> V_153 = 0 ;
V_11 = 0 ;
break;
case V_230 :
F_22 ( V_12 , L_72 ) ;
V_9 -> V_231 = ! V_226 ;
if( V_9 -> V_231 )
F_76 ( & ( V_9 -> V_31 ) , V_232 | V_233 ) ;
else
F_76 ( & ( V_9 -> V_31 ) , V_234 | V_233 ) ;
V_11 = 0 ;
break;
case V_235 :
F_22 ( V_12 , L_73 ) ;
V_11 = 0 ;
break;
case V_236 :
F_22 ( V_12 , L_74 ) ;
V_11 = - V_135 ;
break;
case V_237 :
F_22 ( V_12 , L_75 ) ;
V_11 = - V_135 ;
break;
case V_238 :
F_22 ( V_12 , L_76 ) ;
V_11 = - V_135 ;
break;
case V_239 :
F_22 ( V_12 , L_77 ) ;
V_11 = - V_135 ;
break;
case V_240 :
F_22 ( V_12 , L_78 ) ;
V_11 = - V_135 ;
break;
case V_241 :
F_22 ( V_12 , L_79 ) ;
V_11 = - V_135 ;
break;
case V_242 :
F_22 ( V_12 , L_80 ) ;
V_11 = - V_135 ;
break;
default:
F_22 ( V_12 , L_81 , V_224 ) ;
V_11 = - V_135 ;
break;
}
F_8 ( V_9 ) ;
F_9 ( V_9 , & V_10 ) ;
V_16:
F_10 ( V_12 ) ;
return V_11 ;
}
static int F_77 ( T_10 * V_243 , int V_244 , int V_245 , V_67 * V_246 ,
int V_247 , V_67 * V_248 , V_67 * V_159 , T_11 V_249 )
{
int V_11 = - V_135 ;
int V_250 = 0 ;
T_7 V_251 [ V_252 ] =
{ 0x00 , 0x00 , 0x00 , 0x00 , 0x10 , 0x00 , 0x00 , 0x00 } ;
F_3 ( L_82 ) ;
F_4 ( V_12 ) ;
switch ( V_244 )
{
case V_253 :
F_22 ( V_12 , L_83 , V_245 ) ;
#if 0
for( count = 0; count < 100; count++ )
{
usleep( 1000 );
ltv.len = 2;
ltv.typ = 0xFD91;
ltv.u.u16[0] = 0;
wl_get_info( sock, &ltv, ifname );
if( ltv.u.u16[0] == 0 )
{
break;
}
}
if( count == 100 )
{
wpa_printf( MSG_DEBUG, "Timed out waiting for TxQ!" );
}
#endif
switch ( V_245 ) {
case 0 :
V_243 -> V_28 = 28 ;
V_243 -> V_29 = V_254 ;
memcpy ( & V_243 -> V_34 . V_67 [ V_250 ] , V_246 , V_104 ) ;
V_250 += V_104 ;
memcpy ( & V_243 -> V_34 . V_67 [ V_250 ] , & V_159 [ 0 ] , 16 ) ;
V_250 += 16 ;
memcpy ( & V_243 -> V_34 . V_67 [ V_250 ] , V_251 , V_252 ) ;
V_250 += V_252 ;
memcpy ( & V_243 -> V_34 . V_67 [ V_250 ] , V_248 , V_252 ) ;
V_250 += V_252 ;
memcpy ( & V_243 -> V_34 . V_67 [ V_250 ] , & V_159 [ 16 ] , 8 ) ;
V_250 += 8 ;
memcpy ( & V_243 -> V_34 . V_67 [ V_250 ] , & V_159 [ 24 ] , 8 ) ;
V_11 = 0 ;
break;
case 1 :
case 2 :
case 3 :
V_243 -> V_28 = 26 ;
V_243 -> V_29 = V_255 ;
V_243 -> V_34 . V_35 [ V_250 ] = V_245 ;
if( V_247 )
V_243 -> V_34 . V_35 [ V_250 ] |= 0x8000 ;
V_250 += 2 ;
memcpy ( & V_243 -> V_34 . V_67 [ V_250 ] , V_248 , V_252 ) ;
V_250 += V_252 ;
memcpy ( & V_243 -> V_34 . V_67 [ V_250 ] , V_159 , V_249 ) ;
V_250 += V_249 ;
memcpy ( & V_243 -> V_34 . V_67 [ V_250 ] , V_251 , V_252 ) ;
V_243 -> V_34 . V_35 [ 0 ] = F_30 ( V_243 -> V_34 . V_35 [ 0 ] ) ;
V_11 = 0 ;
break;
default:
break;
}
break;
case V_256 :
F_22 ( V_12 , L_84 , V_245 ) ;
break;
case V_257 :
F_22 ( V_12 , L_85 , V_245 ) ;
break;
case V_258 :
F_22 ( V_12 , L_86 , V_245 ) ;
switch ( V_245 ) {
case 0 :
if ( memcmp ( V_246 , L_87 , V_104 ) != 0 ) {
V_243 -> V_28 = 7 ;
V_243 -> V_29 = V_259 ;
memcpy ( & V_243 -> V_34 . V_67 [ 0 ] , V_246 , V_104 ) ;
V_11 = 0 ;
}
break;
case 1 :
case 2 :
case 3 :
V_243 -> V_28 = 2 ;
V_243 -> V_29 = V_260 ;
V_243 -> V_34 . V_35 [ 0 ] = V_245 ;
V_11 = 0 ;
break;
default:
break;
}
break;
default:
F_22 ( V_12 , L_88 , V_245 ) ;
break;
}
F_10 ( V_12 ) ;
return V_11 ;
}
static int F_78 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_37 * V_149 , char * V_150 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
unsigned long V_10 ;
int V_11 ;
int V_245 = ( V_149 -> V_10 & V_155 ) - 1 ;
T_10 V_243 ;
struct V_261 * V_262 = (struct V_261 * ) V_150 ;
F_3 ( L_89 ) ;
F_4 ( V_12 ) ;
if( V_9 -> V_13 == V_14 ) {
V_11 = - V_15 ;
goto V_16;
}
if ( sizeof( V_262 -> V_263 ) != 8 ) {
F_22 ( V_12 , L_90 ) ;
F_10 ( V_12 ) ;
return - V_135 ;
}
if( V_262 -> V_244 == V_256 ) {
struct V_37 V_264 ;
char * V_265 ;
V_264 . V_10 = V_149 -> V_10 ;
V_264 . V_45 = V_262 -> V_249 ;
V_265 = V_262 -> V_159 ;
V_11 = F_48 ( V_2 , V_4 , & V_264 , V_265 ) ;
goto V_16;
}
F_5 ( V_9 , & V_10 ) ;
F_6 ( V_9 ) ;
memset ( & V_243 , 0 , sizeof( V_243 ) ) ;
V_11 = F_77 ( & V_243 , V_262 -> V_244 , V_245 , V_262 -> V_246 . V_103 ,
V_262 -> V_266 & V_267 ,
V_262 -> V_263 , V_262 -> V_159 , V_262 -> V_249 ) ;
if ( V_11 != 0 ) {
F_22 ( V_12 , L_91 ) ;
goto V_48;
}
V_11 = F_33 ( & ( V_9 -> V_31 ) , ( V_32 ) & V_243 ) ;
V_48:
if( V_11 == V_33 ) {
F_22 ( V_12 , L_92 ) ;
} else {
F_22 ( V_12 , L_93 ) ;
}
F_8 ( V_9 ) ;
F_9 ( V_9 , & V_10 ) ;
V_16:
F_10 ( V_12 ) ;
return V_11 ;
}
static int F_79 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_37 * V_38 , char * V_7 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
unsigned long V_10 ;
int V_11 = 0 ;
T_10 V_243 ;
F_3 ( L_94 ) ;
F_4 ( V_12 ) ;
if( V_9 -> V_13 == V_14 ) {
V_11 = - V_15 ;
goto V_16;
}
F_5 ( V_9 , & V_10 ) ;
F_6 ( V_9 ) ;
memset ( & V_243 , 0 , sizeof( V_243 ) ) ;
V_243 . V_28 = 2 ;
V_243 . V_29 = V_268 ;
V_9 -> V_269 = V_243 . V_34 . V_35 [ 0 ] = 4 ;
V_243 . V_34 . V_35 [ 0 ] = F_30 ( V_243 . V_34 . V_35 [ 0 ] ) ;
V_11 = F_33 ( & ( V_9 -> V_31 ) , ( V_32 ) & V_243 ) ;
F_8 ( V_9 ) ;
F_9 ( V_9 , & V_10 ) ;
V_16:
F_10 ( V_12 ) ;
return V_11 ;
}
struct V_270 * F_27 ( struct V_1 * V_2 )
{
struct V_270 * V_271 ;
struct V_8 * V_9 = F_2 ( V_2 ) ;
F_3 ( L_95 ) ;
F_4 ( V_12 ) ;
F_80 ( V_12 , L_96 , L_97 , V_2 -> V_17 , V_2 ) ;
V_271 = NULL ;
V_271 = & ( V_9 -> V_89 ) ;
V_271 -> V_57 . V_213 = 0x00 ;
if( ! ( V_9 -> V_10 & V_272 ) )
{
T_12 * V_273 ;
T_13 V_274 ;
int V_41 ;
V_271 -> V_41 = 0 ;
V_9 -> V_27 . V_28 = 1 + ( sizeof( * V_273 ) / sizeof( T_1 ) ) ;
V_9 -> V_27 . V_29 = V_275 ;
V_41 = F_17 ( & ( V_9 -> V_31 ) , ( V_32 ) & ( V_9 -> V_27 ) ) ;
if( V_41 == V_33 ) {
V_273 = ( T_12 * ) & ( V_9 -> V_27 ) ;
#ifdef F_24
V_271 -> V_57 . V_57 = ( V_58 ) F_18 ( V_273 -> V_276 ) ;
V_271 -> V_57 . V_60 = ( V_58 ) F_25 ( F_18 ( V_273 -> V_277 ) ) ;
V_271 -> V_57 . V_62 = ( V_58 ) F_25 ( F_18 ( V_273 -> V_278 ) ) ;
V_271 -> V_57 . V_213 |= ( V_279 |
V_280 |
V_281 |
V_214 ) ;
#else
V_271 -> V_57 . V_57 = F_81 ( F_18 ( V_273 -> V_276 ) ,
V_282 ,
V_59 ) ;
V_271 -> V_57 . V_60 = F_81 ( F_18 ( V_273 -> V_277 ) ,
V_61 ,
V_283 ) ;
V_271 -> V_57 . V_62 = F_81 ( F_18 ( V_273 -> V_278 ) ,
V_63 ,
V_284 ) ;
V_271 -> V_57 . V_213 |= ( V_279 |
V_280 |
V_281 ) ;
#endif
} else {
memset ( & ( V_271 -> V_57 ) , 0 , sizeof( V_271 -> V_57 ) ) ;
}
if( V_9 -> V_13 == V_14 ) {
if( F_82 ( V_9 , & V_274 ) == 0 ) {
V_271 -> V_285 . V_286 = 0L ;
V_271 -> V_285 . V_287 = V_274 . V_288 ;
V_271 -> V_285 . V_289 = V_274 . V_290 +
V_274 . V_291 +
V_274 . V_292 ;
V_271 -> V_285 . V_44 = V_274 . V_293 ;
V_271 -> V_285 . V_294 = V_274 . V_295 ;
} else {
memset ( & ( V_271 -> V_285 ) , 0 , sizeof( V_271 -> V_285 ) ) ;
}
} else {
memset ( & ( V_271 -> V_285 ) , 0 , sizeof( V_271 -> V_285 ) ) ;
}
}
F_10 ( V_12 ) ;
return V_271 ;
}
struct V_270 * F_83 ( struct V_1 * V_2 )
{
unsigned long V_10 ;
struct V_8 * V_9 = F_2 ( V_2 ) ;
struct V_270 * V_271 = NULL ;
F_3 ( L_98 ) ;
F_4 ( V_12 ) ;
F_5 ( V_9 , & V_10 ) ;
F_6 ( V_9 ) ;
#ifdef F_84
if( V_9 -> V_296 == 1 ) {
F_22 ( V_12 , L_99 ) ;
} else
#endif
{
V_271 = F_27 ( V_2 ) ;
}
F_8 ( V_9 ) ;
F_9 ( V_9 , & V_10 ) ;
F_10 ( V_12 ) ;
return V_271 ;
}
inline void F_85 ( struct V_1 * V_2 , V_58 * V_297 )
{
struct V_115 V_89 ;
int V_41 ;
V_58 V_298 [ 2 ] ;
T_14 V_299 [ 1 ] ;
struct V_8 * V_9 = F_2 ( V_2 ) ;
if ( ! V_9 -> V_300 . V_301 ) {
return;
}
memset ( V_298 , 0 , sizeof( V_298 ) ) ;
memset ( V_299 , 0 , sizeof( T_14 ) ) ;
V_299 [ 0 ] . V_302 = V_298 ;
V_299 [ 0 ] . V_303 = sizeof( V_298 ) ;
V_299 [ 0 ] . V_304 = 0 ;
V_41 = F_86 ( & ( V_9 -> V_31 ) , & V_299 [ 0 ] , 0 ) ;
if( V_41 == V_33 ) {
V_89 . V_60 = ( V_58 ) F_25 ( V_298 [ 1 ] ) ;
V_89 . V_62 = ( V_58 ) F_25 ( V_298 [ 0 ] ) ;
V_89 . V_57 = V_89 . V_60 > V_89 . V_62 ? V_89 . V_60 - V_89 . V_62 : 0 ;
V_89 . V_213 = ( V_279 |
V_280 |
V_281 |
V_214 ) ;
F_87 ( V_2 , V_297 , & V_89 ) ;
}
}
void F_15 ( struct V_1 * V_2 )
{
#if V_73 > 13
union V_5 V_305 ;
struct V_8 * V_9 = F_2 ( V_2 ) ;
memset ( & V_305 , 0 , sizeof( V_305 ) ) ;
V_305 . V_19 . V_25 = V_9 -> V_26 ;
V_305 . V_19 . V_23 = 0 ;
F_88 ( V_2 , V_306 , & V_305 , NULL ) ;
#endif
return;
}
void F_57 ( struct V_1 * V_2 )
{
#if V_73 > 13
union V_5 V_305 ;
struct V_8 * V_9 = F_2 ( V_2 ) ;
memset ( & V_305 , 0 , sizeof( V_305 ) ) ;
if ( F_30 ( V_9 -> V_31 . V_108 . V_109 ) == V_110 ) {
V_305 . V_165 = V_172 ;
} else {
V_305 . V_165 = V_179 ;
}
F_88 ( V_2 , V_307 , & V_305 , NULL ) ;
#endif
return;
}
void F_45 ( struct V_1 * V_2 )
{
#if V_73 > 13
union V_5 V_305 ;
struct V_8 * V_9 = F_2 ( V_2 ) ;
memset ( & V_305 , 0 , sizeof( V_305 ) ) ;
V_305 . V_142 . V_45 = strlen ( V_9 -> V_140 ) ;
V_305 . V_142 . V_308 = ( V_309 ) V_9 -> V_140 ;
V_305 . V_142 . V_10 = 1 ;
F_88 ( V_2 , V_310 , & V_305 , V_9 -> V_140 ) ;
#endif
return;
}
void F_51 ( struct V_1 * V_2 )
{
#if V_73 > 13
union V_5 V_305 ;
struct V_8 * V_9 = F_2 ( V_2 ) ;
int V_154 = 0 ;
memset ( & V_305 , 0 , sizeof( V_305 ) ) ;
if( V_9 -> V_153 == 0 ) {
V_305 . V_311 . V_10 = V_160 ;
} else {
V_305 . V_311 . V_10 |= V_9 -> V_157 ;
V_154 = V_9 -> V_157 - 1 ;
#if 1
if ( F_30 ( V_9 -> V_31 . V_108 . V_109 ) == V_145 ) {
if( V_9 -> V_312 ) {
V_305 . V_311 . V_10 |= V_161 ;
} else {
V_305 . V_311 . V_10 |= V_313 ;
}
}
#endif
if( F_13 ( V_21 ) ) {
V_305 . V_311 . V_308 = ( V_309 ) V_9 -> V_158 . V_159 [ V_154 ] . V_159 ;
V_305 . V_311 . V_45 = V_9 -> V_158 . V_159 [ V_154 ] . V_28 ;
} else {
V_305 . V_311 . V_10 |= V_314 ;
}
}
F_88 ( V_2 , V_315 , & V_305 ,
V_9 -> V_158 . V_159 [ V_154 ] . V_159 ) ;
#endif
return;
}
void F_89 ( struct V_1 * V_2 )
{
#if V_73 > 13
union V_5 V_305 ;
struct V_8 * V_9 = F_2 ( V_2 ) ;
int V_41 ;
F_90 ( V_2 ) ;
V_9 -> V_27 . V_29 = V_111 ;
V_9 -> V_27 . V_28 = 4 ;
V_41 = F_17 ( & ( V_9 -> V_31 ) , ( V_32 ) & ( V_9 -> V_27 ) ) ;
if( V_41 == V_33 ) {
memset ( & V_305 , 0 , sizeof( V_305 ) ) ;
memcpy ( V_305 . V_246 . V_103 , V_9 -> V_27 . V_34 . V_67 , V_104 ) ;
V_305 . V_246 . V_105 = V_106 ;
F_88 ( V_2 , V_92 , & V_305 , NULL ) ;
}
#endif
return;
}
void F_40 ( struct V_1 * V_2 )
{
#if V_73 > 13
union V_5 V_305 ;
memset ( & V_305 , 0 , sizeof( V_305 ) ) ;
V_305 . V_246 . V_105 = V_106 ;
F_88 ( V_2 , V_93 , & V_305 , NULL ) ;
#endif
return;
}
void F_91 ( struct V_1 * V_2 )
{
#if V_73 > 14
union V_5 V_305 ;
memset ( & V_305 , 0 , sizeof( V_305 ) ) ;
memcpy ( V_305 . V_246 . V_103 , V_2 -> V_107 , V_104 ) ;
V_305 . V_246 . V_105 = V_106 ;
F_88 ( V_2 , V_95 , & V_305 , NULL ) ;
#endif
return;
}
void F_92 ( struct V_1 * V_2 )
{
#if V_73 > 14
union V_5 V_305 ;
memset ( & V_305 , 0 , sizeof( V_305 ) ) ;
memcpy ( V_305 . V_246 . V_103 , V_2 -> V_107 , V_104 ) ;
V_305 . V_246 . V_105 = V_106 ;
F_88 ( V_2 , V_97 , & V_305 , NULL ) ;
#endif
return;
}
void F_93 ( struct V_1 * V_2 )
{
#if V_73 > 14
char V_200 [ 512 ] ;
union V_5 V_305 ;
struct V_8 * V_9 = F_2 ( V_2 ) ;
int V_245 ;
char * V_316 ;
char * V_317 ;
T_15 * V_318 ;
V_245 = V_9 -> V_319 [ V_320 + 1 ] >> 3 ;
V_245 &= 0x03 ;
V_318 = ( T_15 * ) & V_9 -> V_319 [ V_320 ] ;
V_316 = ( char * ) V_318 -> V_321 ;
V_317 = ( char * ) V_318 -> V_322 ;
F_39 ( L_100 , V_245 ,
V_318 -> V_41 ) ;
memset ( & V_305 , 0 , sizeof( V_305 ) ) ;
memset ( V_200 , 0 , sizeof( V_200 ) ) ;
#if V_323
sprintf ( V_200 , L_101
L_102 , V_245 , V_316 [ 0 ] & 0x01 ? L_103 : L_104 ,
V_317 ) ;
#endif
V_305 . V_38 . V_45 = strlen ( V_200 ) ;
F_88 ( V_2 , V_96 , & V_305 , V_200 ) ;
#endif
return;
}
void F_90 ( struct V_1 * V_2 )
{
#if V_73 > 14
char V_200 [ 512 ] ;
union V_5 V_305 ;
struct V_8 * V_9 = F_2 ( V_2 ) ;
int V_41 ;
T_9 V_38 ;
T_1 V_45 ;
T_7 * V_201 ;
memset ( & V_305 , 0 , sizeof( V_305 ) ) ;
memset ( V_200 , 0 , sizeof( V_200 ) ) ;
V_9 -> V_27 . V_28 = 45 ;
V_9 -> V_27 . V_29 = V_324 ;
V_41 = F_17 ( & ( V_9 -> V_31 ) , ( V_32 ) & ( V_9 -> V_27 ) ) ;
if( V_41 == V_33 )
{
V_45 = 0 ;
memcpy ( & V_38 . V_216 , & ( V_9 -> V_27 . V_34 . V_67 [ 1 ] ) , 88 ) ;
V_201 = F_73 ( & V_38 , & V_45 ) ;
if( V_45 != 0 )
{
sprintf ( V_200 , L_105 , F_74 ( V_201 , V_45 ) ) ;
V_305 . V_38 . V_45 = strlen ( V_200 ) ;
F_88 ( V_2 , V_96 , & V_305 , V_200 ) ;
}
}
#endif
return;
}
