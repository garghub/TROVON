static int F_1 ( T_1 * V_1 , T_2 V_2 , T_3 * V_3 ,
int V_4 , T_3 * V_5 , T_3 * V_6 , T_4 V_7 )
{
int V_8 = - V_9 ;
int V_10 = 0 ;
T_5 V_11 [ V_12 ] =
{ 0x00 , 0x00 , 0x00 , 0x00 , 0x10 , 0x00 , 0x00 , 0x00 } ;
switch ( V_2 ) {
case 0 :
V_1 -> V_13 = 28 ;
V_1 -> V_14 = V_15 ;
memcpy ( & V_1 -> V_16 . T_3 [ V_10 ] , V_3 , V_17 ) ;
V_10 += V_17 ;
memcpy ( & V_1 -> V_16 . T_3 [ V_10 ] , & V_6 [ 0 ] , 16 ) ;
V_10 += 16 ;
memcpy ( & V_1 -> V_16 . T_3 [ V_10 ] , V_11 , V_12 ) ;
V_10 += V_12 ;
memcpy ( & V_1 -> V_16 . T_3 [ V_10 ] , V_5 , V_12 ) ;
V_10 += V_12 ;
memcpy ( & V_1 -> V_16 . T_3 [ V_10 ] , & V_6 [ 16 ] , 8 ) ;
V_10 += 8 ;
memcpy ( & V_1 -> V_16 . T_3 [ V_10 ] , & V_6 [ 24 ] , 8 ) ;
V_8 = 0 ;
break;
case 1 :
case 2 :
case 3 :
V_1 -> V_13 = 26 ;
V_1 -> V_14 = V_18 ;
if ( V_4 )
V_2 |= 0x8000 ;
V_1 -> V_16 . T_2 [ V_10 ] = F_2 ( V_2 ) ;
V_10 += 2 ;
memcpy ( & V_1 -> V_16 . T_3 [ V_10 ] , V_5 , V_12 ) ;
V_10 += V_12 ;
memcpy ( & V_1 -> V_16 . T_3 [ V_10 ] , V_6 , V_7 ) ;
V_10 += V_7 ;
memcpy ( & V_1 -> V_16 . T_3 [ V_10 ] , V_11 , V_12 ) ;
V_8 = 0 ;
break;
default:
break;
}
return V_8 ;
}
static int F_3 ( T_1 * V_1 , T_2 V_2 , T_3 * V_3 )
{
int V_8 ;
switch ( V_2 ) {
case 0 :
if ( ! F_4 ( V_3 ) ) {
V_1 -> V_13 = 7 ;
V_1 -> V_14 = V_19 ;
memcpy ( & V_1 -> V_16 . T_3 [ 0 ] , V_3 , V_17 ) ;
V_8 = 0 ;
}
break;
case 1 :
case 2 :
case 3 :
V_1 -> V_13 = 2 ;
V_1 -> V_14 = V_20 ;
V_1 -> V_16 . T_2 [ 0 ] = F_2 ( V_2 ) ;
V_8 = 0 ;
break;
default:
break;
}
return V_8 ;
}
static int F_5 ( struct V_21 * V_22 , T_2 V_2 ,
T_3 * V_6 , T_4 V_7 ,
bool V_23 , bool V_4 )
{
T_5 V_24 = V_22 -> V_25 ;
int V_26 = V_22 -> V_27 - 1 ;
int V_8 = 0 ;
if ( ! F_6 ( & ( V_22 -> V_28 ) ) ) {
F_7 ( V_29 , L_1 ) ;
V_8 = - V_30 ;
goto V_31;
}
F_8 ( V_29 , L_2 ,
V_6 , V_7 ) ;
switch ( V_7 ) {
case V_32 :
case V_33 :
if ( ( V_2 < 0 ) || ( V_2 >= V_34 ) )
V_2 = V_26 ;
memset ( V_22 -> V_35 . V_6 [ V_2 ] . V_6 , 0 , V_33 ) ;
memcpy ( V_22 -> V_35 . V_6 [ V_2 ] . V_6 , V_6 , V_7 ) ;
V_22 -> V_35 . V_6 [ V_2 ] . V_13 = V_7 ;
F_8 ( V_29 , L_3 , V_7 ) ;
F_8 ( V_29 , L_4 ,
V_22 -> V_35 . V_6 [ V_2 ] . V_6 ,
V_22 -> V_35 . V_6 [ V_2 ] . V_13 , V_2 ) ;
if ( ( V_2 == V_26 ) && ( V_22 -> V_35 . V_6 [ V_26 ] . V_13 > 0 ) )
V_22 -> V_25 = 1 ;
break;
case 0 :
if ( V_4 && ( V_2 >= 0 ) && ( V_2 < V_34 ) ) {
F_8 ( V_29 , L_5 , V_2 ,
V_22 -> V_35 . V_6 [ V_2 ] . V_13 ) ;
if ( V_22 -> V_35 . V_6 [ V_2 ] . V_13 > 0 ) {
V_22 -> V_27 = V_2 + 1 ;
V_22 -> V_25 = 1 ;
} else {
F_7 ( V_29 , L_6 ) ;
V_8 = - V_9 ;
}
}
break;
default:
F_7 ( V_29 , L_7 ) ;
V_8 = - V_9 ;
goto V_31;
}
if ( V_23 ) {
V_22 -> V_25 = 1 ;
V_22 -> V_36 = V_37 ;
} else {
V_22 -> V_25 = 0 ;
V_22 -> V_36 = V_38 ;
}
F_9 ( V_29 , L_8 , V_24 ) ;
F_9 ( V_29 , L_9 , V_22 -> V_25 ) ;
F_9 ( V_29 , L_10 , V_7 ) ;
if ( V_8 == 0 ) {
F_8 ( V_29 , L_11 , V_22 -> V_25 ,
V_22 -> V_27 ) ;
if ( V_22 -> V_25 == V_24 ) {
if ( V_7 != 0 ) {
F_10 ( V_22 ) ;
}
} else {
F_11 ( V_22 ) ;
}
}
V_31:
return V_8 ;
}
static int F_12 ( struct V_39 * V_40 ,
struct V_41 * V_42 ,
union V_43 * V_44 , char * V_45 )
{
struct V_21 * V_22 = F_13 ( V_40 ) ;
unsigned long V_46 ;
int V_8 = 0 ;
if( V_22 -> V_47 == V_48 ) {
V_8 = - V_49 ;
goto V_31;
}
F_14 ( V_22 , & V_46 ) ;
F_15 ( V_22 ) ;
F_11 ( V_22 ) ;
F_16 ( V_22 ) ;
F_17 ( V_22 , & V_46 ) ;
V_31:
return V_8 ;
}
static int F_18 ( struct V_39 * V_40 , struct V_41 * V_42 , char * V_50 , char * V_45 )
{
strcpy ( V_50 , L_12 ) ;
return 0 ;
}
static int F_19 ( struct V_39 * V_40 , struct V_41 * V_42 , struct V_51 * V_52 , char * V_45 )
{
struct V_21 * V_22 = F_13 ( V_40 ) ;
unsigned long V_46 ;
int V_53 = 0 ;
int V_8 = 0 ;
if( V_22 -> V_47 == V_48 ) {
V_8 = - V_49 ;
goto V_31;
}
if( ! F_20 ( V_54 ) ) {
V_8 = - V_55 ;
return V_8 ;
}
if( V_52 -> V_56 == 1 ) {
int V_57 = V_52 -> V_58 / 100000 ;
V_53 = F_21 ( V_57 ) ;
}
if( V_52 -> V_56 == 0 ) {
V_53 = V_52 -> V_58 ;
}
if( V_53 > 14 ) {
V_53 = V_53 | 0x100 ;
}
F_14 ( V_22 , & V_46 ) ;
F_15 ( V_22 ) ;
V_22 -> V_59 = V_53 ;
F_11 ( V_22 ) ;
F_22 ( V_22 -> V_40 ) ;
F_16 ( V_22 ) ;
F_17 ( V_22 , & V_46 ) ;
V_31:
return V_8 ;
}
static int F_23 ( struct V_39 * V_40 , struct V_41 * V_42 , struct V_51 * V_52 , char * V_45 )
{
struct V_21 * V_22 = F_13 ( V_40 ) ;
unsigned long V_46 ;
int V_8 = - 1 ;
if( V_22 -> V_47 == V_48 ) {
V_8 = - V_49 ;
goto V_31;
}
F_14 ( V_22 , & V_46 ) ;
F_15 ( V_22 ) ;
V_22 -> V_60 . V_13 = 2 ;
V_22 -> V_60 . V_14 = V_61 ;
V_8 = F_24 ( & ( V_22 -> V_28 ) , ( V_62 ) & ( V_22 -> V_60 ) ) ;
if( V_8 == V_63 ) {
T_6 V_53 = F_25 ( V_22 -> V_60 . V_16 . T_2 [ 0 ] ) ;
V_52 -> V_58 = F_26 ( V_53 ) * 100000 ;
V_52 -> V_56 = 1 ;
}
F_16 ( V_22 ) ;
F_17 ( V_22 , & V_46 ) ;
V_8 = ( V_8 == V_63 ? 0 : - V_64 ) ;
V_31:
return V_8 ;
}
static int F_27 ( struct V_39 * V_40 , struct V_41 * V_42 , struct V_65 * V_66 , char * V_45 )
{
struct V_21 * V_22 = F_13 ( V_40 ) ;
unsigned long V_46 ;
struct V_67 * V_68 = (struct V_67 * ) V_45 ;
int V_8 = 0 ;
int V_69 = - 1 ;
int V_70 ;
T_7 * V_71 ;
int V_72 = 0 ;
V_66 -> V_73 = sizeof( struct V_67 ) ;
memset ( V_68 , 0 , sizeof( struct V_67 ) ) ;
F_14 ( V_22 , & V_46 ) ;
F_15 ( V_22 ) ;
memset ( V_68 , 0 , sizeof( struct V_67 ) ) ;
V_74:
V_22 -> V_60 . V_13 = 1 + ( sizeof( * V_71 ) / sizeof( T_6 ) ) ;
V_22 -> V_60 . V_14 = V_75 ;
V_69 = F_24 ( & ( V_22 -> V_28 ) , ( V_62 ) & ( V_22 -> V_60 ) ) ;
if( V_69 != V_63 ) {
F_9 ( V_29 , L_13 , V_69 ) ;
if ( V_72 < 10 ) {
V_72 ++ ;
F_17 ( V_22 , & V_46 ) ;
F_14 ( V_22 , & V_46 ) ;
V_69 = F_28 ( V_40 ) ;
if ( V_69 != V_63 ) {
F_9 ( V_29 , L_14 , V_69 ) ;
V_8 = - V_64 ;
goto V_76;
}
F_17 ( V_22 , & V_46 ) ;
F_14 ( V_22 , & V_46 ) ;
goto V_74;
} else {
F_9 ( V_29 , L_15 , V_72 ) ;
V_8 = - V_64 ;
goto V_76;
}
}
F_17 ( V_22 , & V_46 ) ;
F_14 ( V_22 , & V_46 ) ;
V_71 = ( T_7 * ) & ( V_22 -> V_60 . V_16 . V_77 ) ;
V_68 -> V_78 = F_25 ( * V_71 ) * V_79 ;
if ( V_72 > 0 ) {
F_9 ( V_29 , L_16 , V_72 ) ;
}
V_68 -> V_80 = V_81 ;
V_68 -> V_82 = V_83 ;
V_68 -> V_84 . V_85 = ( V_86 ) V_87 ;
V_68 -> V_84 . V_88 = ( V_86 ) ( F_29 ( V_89 ) - 1 ) ;
V_68 -> V_84 . V_90 = ( V_86 ) ( F_29 ( V_91 ) - 1 ) ;
V_68 -> V_92 = 0 ;
V_22 -> V_60 . V_13 = 6 ;
V_22 -> V_60 . V_14 = V_93 ;
V_69 = F_24 ( & ( V_22 -> V_28 ) , ( V_62 ) & ( V_22 -> V_60 ) ) ;
if( V_69 == V_63 ) {
for( V_70 = 0 ; V_70 < V_94 ; V_70 ++ )
if( V_22 -> V_60 . V_16 . T_3 [ V_70 + 2 ] != 0 ) {
V_68 -> V_95 [ V_70 ] = V_22 -> V_60 . V_16 . T_3 [ V_70 + 2 ] * V_79 / 2 ;
V_68 -> V_92 ++ ;
}
} else {
F_9 ( V_29 , L_17 , V_69 ) ;
V_8 = - V_64 ;
goto V_76;
}
V_68 -> V_96 = V_97 ;
V_68 -> V_98 = V_99 ;
F_17 ( V_22 , & V_46 ) ;
F_14 ( V_22 , & V_46 ) ;
if( F_6 ( & ( V_22 -> V_28 ) ) ) {
V_68 -> V_100 [ 0 ] = V_32 ;
V_68 -> V_100 [ 1 ] = V_33 ;
V_68 -> V_101 = 2 ;
V_68 -> V_102 = V_34 ;
}
V_68 -> V_103 = V_104 ;
V_68 -> V_105 = 1 ;
V_68 -> V_106 [ 0 ] = V_107 ;
V_68 -> V_108 = V_109 ;
V_68 -> V_110 = V_111 ;
F_17 ( V_22 , & V_46 ) ;
F_14 ( V_22 , & V_46 ) ;
F_9 ( V_29 , L_18 ) ;
F_30 ( V_22 -> V_40 ) ;
V_68 -> V_112 = V_22 -> V_113 . V_85 ;
F_9 ( V_29 , L_19 ) ;
F_31 ( V_68 -> V_114 ) ;
F_32 ( V_68 -> V_114 , V_115 ) ;
F_32 ( V_68 -> V_114 , V_116 ) ;
F_32 ( V_68 -> V_114 , V_117 ) ;
F_32 ( V_68 -> V_114 , V_118 ) ;
F_32 ( V_68 -> V_114 , V_119 ) ;
F_32 ( V_68 -> V_114 , V_120 ) ;
F_32 ( V_68 -> V_114 , V_121 ) ;
V_68 -> V_122 = V_123 | V_124 ;
V_68 -> V_125 = V_126 ;
V_76:
F_16 ( V_22 ) ;
F_17 ( V_22 , & V_46 ) ;
return V_8 ;
}
static int F_33 ( struct V_39 * V_40 , struct V_41 * V_42 , struct V_127 * V_128 , char * V_45 )
{
struct V_21 * V_22 = F_13 ( V_40 ) ;
unsigned long V_46 ;
int V_8 = 0 ;
#if 1
int V_69 = - 1 ;
#endif
if( V_22 -> V_47 == V_48 ) {
V_8 = - V_49 ;
goto V_31;
}
F_14 ( V_22 , & V_46 ) ;
F_15 ( V_22 ) ;
V_128 -> V_129 = V_130 ;
memcpy ( & V_128 -> V_131 , V_22 -> V_40 -> V_132 , V_17 ) ;
#if 1
if ( F_34 ( V_22 -> V_28 . V_133 . V_134 ) == V_135 ) {
V_22 -> V_60 . V_14 = V_136 ;
V_22 -> V_60 . V_13 = 4 ;
V_69 = F_24 ( & ( V_22 -> V_28 ) , ( V_62 ) & ( V_22 -> V_60 ) ) ;
if( V_69 == V_63 ) {
memcpy ( & V_128 -> V_131 , V_22 -> V_60 . V_16 . T_3 , V_17 ) ;
} else {
V_8 = - V_64 ;
}
}
#endif
F_16 ( V_22 ) ;
F_17 ( V_22 , & V_46 ) ;
V_31:
return V_8 ;
}
static int F_35 ( struct V_39 * V_40 , struct V_41 * V_42 , struct V_65 * V_66 , char * V_45 )
{
struct V_21 * V_22 = F_13 ( V_40 ) ;
unsigned long V_46 ;
int V_8 ;
int V_137 = - 1 ;
int V_138 = 0 ;
T_8 V_70 ;
struct V_127 * V_139 = NULL ;
struct V_140 * V_85 = NULL ;
#ifdef F_36
T_9 * V_141 = & V_22 -> V_142 ;
#else
T_10 * V_141 = & V_22 -> V_143 ;
#endif
if( V_22 -> V_47 == V_48 ) {
V_8 = - V_49 ;
goto V_31;
}
F_14 ( V_22 , & V_46 ) ;
F_15 ( V_22 ) ;
V_22 -> V_142 . V_144 = FALSE ;
V_22 -> V_143 . V_144 = FALSE ;
V_22 -> V_60 . V_13 = 2 ;
V_22 -> V_60 . V_14 = V_145 ;
V_22 -> V_60 . V_16 . T_2 [ 0 ] = F_34 ( 0x7FFF ) ;
V_8 = F_37 ( & ( V_22 -> V_28 ) , ( V_62 ) & ( V_22 -> V_60 ) ) ;
F_9 ( V_29 , L_20 , V_8 ) ;
V_22 -> V_60 . V_13 = 2 ;
V_22 -> V_60 . V_14 = V_146 ;
V_22 -> V_60 . V_16 . T_2 [ 0 ] = F_34 ( 0 ) ;
V_8 = F_37 ( & ( V_22 -> V_28 ) , ( V_62 ) & ( V_22 -> V_60 ) ) ;
F_9 ( V_29 , L_21 , V_8 ) ;
#ifdef F_36
V_8 = F_38 ( & ( V_22 -> V_28 ) , V_147 ) ;
#else
V_8 = F_38 ( & ( V_22 -> V_28 ) , V_148 ) ;
#endif
F_16 ( V_22 ) ;
F_17 ( V_22 , & V_46 ) ;
if( V_8 == V_63 ) {
F_9 ( V_29 , L_22 ) ;
while( ( * V_141 ) . V_144 == FALSE && V_8 == V_63 ) {
F_9 ( V_29 , L_23 ) ;
if( V_138 ++ > V_149 ) {
V_8 = - V_150 ;
} else {
for( V_70 = 0 ; V_70 < 100 ; V_70 ++ ) {
F_39 ( 10 ) ;
F_40 ( ) ;
}
}
}
F_41 () ;
if ( V_8 != V_63 ) {
F_42 ( V_29 , L_24 ) ;
} else {
V_137 = ( * V_141 ) . V_137 ;
if ( V_137 > V_151 ) {
V_137 = V_151 ;
}
V_66 -> V_73 = V_137 ;
V_139 = (struct V_127 * ) V_45 ;
V_85 = (struct V_140 * ) V_45 +
( sizeof( struct V_127 ) * V_137 ) ;
V_66 -> V_46 = 0 ;
for( V_70 = 0 ; V_70 < V_137 ; V_70 ++ ) {
#ifdef F_36
memcpy ( V_139 [ V_70 ] . V_131 ,
( * V_141 ) . V_152 [ V_70 ] . V_153 , V_17 ) ;
#else
F_43 ( L_25 ,
( * V_141 ) . V_154 [ V_70 ] . V_155 ) ;
memcpy ( V_139 [ V_70 ] . V_131 ,
( * V_141 ) . V_154 [ V_70 ] . V_155 , V_17 ) ;
#endif
}
( * V_141 ) . V_144 = FALSE ;
F_44 ( V_22 -> V_40 ) ;
}
}
V_31:
return V_8 ;
}
static int F_45 ( struct V_39 * V_40 , struct V_41 * V_42 , struct V_156 * V_157 , char * V_45 )
{
struct V_21 * V_22 = F_13 ( V_40 ) ;
unsigned long V_46 ;
int V_8 = 0 ;
int V_158 = V_157 -> V_159 ;
if( V_22 -> V_47 == V_48 ) {
V_8 = - V_49 ;
goto V_31;
}
if( ( V_158 < 1 ) || ( V_158 > 3 ) ) {
V_8 = - V_9 ;
goto V_31;
}
F_14 ( V_22 , & V_46 ) ;
F_15 ( V_22 ) ;
V_22 -> V_160 = V_158 ;
F_11 ( V_22 ) ;
F_16 ( V_22 ) ;
F_17 ( V_22 , & V_46 ) ;
V_31:
return V_8 ;
}
static int F_46 ( struct V_39 * V_40 , struct V_41 * V_42 , struct V_156 * V_157 , char * V_45 )
{
struct V_21 * V_22 = F_13 ( V_40 ) ;
int V_8 = 0 ;
if( V_22 -> V_47 == V_48 ) {
V_8 = - V_49 ;
goto V_31;
}
V_157 -> V_159 = V_22 -> V_160 ;
V_157 -> V_161 = 0 ;
V_31:
return V_8 ;
}
static int F_47 ( struct V_39 * V_40 , struct V_41 * V_42 , struct V_65 * V_66 , char * V_162 )
{
struct V_21 * V_22 = F_13 ( V_40 ) ;
unsigned long V_46 ;
int V_8 = 0 ;
if( V_22 -> V_47 == V_48 ) {
V_8 = - V_49 ;
goto V_31;
}
if ( V_66 -> V_46 != 0 && V_66 -> V_73 > V_163 ) {
V_8 = - V_9 ;
goto V_31;
}
F_14 ( V_22 , & V_46 ) ;
F_15 ( V_22 ) ;
memset ( V_22 -> V_164 , 0 , sizeof( V_22 -> V_164 ) ) ;
if( V_66 -> V_46 == 0 ) {
if ( F_34 ( V_22 -> V_28 . V_133 . V_134 ) == V_135 ) {
strcpy ( V_22 -> V_164 , L_26 ) ;
} else {
strcpy ( V_22 -> V_164 , V_165 ) ;
}
} else {
memcpy ( V_22 -> V_164 , V_162 , V_66 -> V_73 ) ;
}
F_8 ( V_29 , L_27 , V_162 ) ;
F_11 ( V_22 ) ;
F_48 ( V_22 -> V_40 ) ;
F_16 ( V_22 ) ;
F_17 ( V_22 , & V_46 ) ;
V_31:
return V_8 ;
}
static int F_49 ( struct V_39 * V_40 , struct V_41 * V_42 , struct V_65 * V_66 , char * V_166 )
{
struct V_21 * V_22 = F_13 ( V_40 ) ;
unsigned long V_46 ;
int V_8 = 0 ;
int V_69 = - 1 ;
T_11 * V_167 ;
if( V_22 -> V_47 == V_48 ) {
V_8 = - V_49 ;
goto V_31;
}
F_14 ( V_22 , & V_46 ) ;
F_15 ( V_22 ) ;
V_22 -> V_60 . V_13 = 1 + ( sizeof( * V_167 ) / sizeof( T_6 ) ) ;
#if 1
V_22 -> V_60 . V_14 = V_168 ;
#endif
#if 1
if ( F_34 ( V_22 -> V_28 . V_133 . V_134 ) == V_169 ) {
V_22 -> V_60 . V_14 = V_170 ;
}
#endif
V_69 = F_24 ( & ( V_22 -> V_28 ) , ( V_62 ) & ( V_22 -> V_60 ) ) ;
if( V_69 == V_63 ) {
V_167 = ( T_11 * ) & ( V_22 -> V_60 . V_16 . V_77 ) ;
V_167 -> V_73 = F_25 ( V_167 -> V_73 ) ;
V_66 -> V_73 = V_167 -> V_73 ;
if( V_167 -> V_73 < V_163 ) {
V_167 -> V_50 [ V_167 -> V_73 ] = '\0' ;
}
V_66 -> V_46 = 1 ;
#if 1
if( V_167 -> V_50 [ 0 ] == '\0' ) {
V_22 -> V_60 . V_13 = 1 + ( sizeof( * V_167 ) / sizeof( T_6 ) ) ;
V_22 -> V_60 . V_14 = V_171 ;
V_69 = F_24 ( & ( V_22 -> V_28 ) , ( V_62 ) & ( V_22 -> V_60 ) ) ;
if( V_69 == V_63 ) {
V_167 = ( T_11 * ) & ( V_22 -> V_60 . V_16 . V_77 ) ;
V_167 -> V_73 = F_25 ( V_167 -> V_73 ) ;
V_66 -> V_73 = V_167 -> V_73 ;
V_66 -> V_46 = 1 ;
} else {
V_8 = - V_64 ;
goto V_76;
}
}
#endif
if ( V_167 -> V_73 > V_172 ) {
V_8 = - V_64 ;
goto V_76;
}
memcpy ( V_166 , V_167 -> V_50 , V_167 -> V_73 ) ;
} else {
V_8 = - V_64 ;
goto V_76;
}
V_76:
F_16 ( V_22 ) ;
F_17 ( V_22 , & V_46 ) ;
V_31:
return V_8 ;
}
static int F_50 ( struct V_39 * V_40 , struct V_41 * V_42 , struct V_65 * V_173 , char * V_174 )
{
struct V_21 * V_22 = F_13 ( V_40 ) ;
unsigned long V_46 ;
int V_2 = ( V_173 -> V_46 & V_175 ) - 1 ;
int V_8 = 0 ;
bool V_23 = true ;
if ( V_22 -> V_47 == V_48 ) {
V_8 = - V_49 ;
goto V_31;
}
if ( V_173 -> V_46 & V_176 )
V_23 = false ;
F_14 ( V_22 , & V_46 ) ;
F_15 ( V_22 ) ;
V_8 = F_5 ( V_22 , V_2 , V_174 , V_173 -> V_73 ,
V_23 , true ) ;
if ( V_8 == 0 )
F_51 ( V_40 ) ;
F_16 ( V_22 ) ;
F_17 ( V_22 , & V_46 ) ;
V_31:
return V_8 ;
}
static int F_52 ( struct V_39 * V_40 , struct V_41 * V_42 , struct V_65 * V_173 , char * V_6 )
{
struct V_21 * V_22 = F_13 ( V_40 ) ;
unsigned long V_46 ;
int V_8 = 0 ;
int V_177 ;
F_8 ( V_29 , L_28 , V_22 -> V_25 , V_22 -> V_27 ) ;
if( V_22 -> V_47 == V_48 ) {
V_8 = - V_49 ;
goto V_31;
}
if( ! F_20 ( V_54 ) ) {
V_8 = - V_55 ;
return V_8 ;
}
F_14 ( V_22 , & V_46 ) ;
F_15 ( V_22 ) ;
if( ! F_6 ( & ( V_22 -> V_28 ) ) ) {
V_8 = - V_30 ;
goto V_76;
}
V_177 = ( V_173 -> V_46 & V_175 ) - 1 ;
V_173 -> V_46 = 0 ;
if( V_22 -> V_25 == 0 ) {
V_173 -> V_46 |= V_176 ;
}
if( ( V_177 < 0 ) || ( V_177 >= V_34 ) ) {
V_177 = V_22 -> V_27 - 1 ;
}
V_173 -> V_46 |= V_177 + 1 ;
V_173 -> V_73 = V_22 -> V_35 . V_6 [ V_177 ] . V_13 ;
memcpy ( V_6 , V_22 -> V_35 . V_6 [ V_177 ] . V_6 , V_173 -> V_73 ) ;
V_76:
F_16 ( V_22 ) ;
F_17 ( V_22 , & V_46 ) ;
V_31:
return V_8 ;
}
static int F_53 ( struct V_39 * V_40 , struct V_41 * V_42 , struct V_65 * V_66 , char * V_178 )
{
struct V_21 * V_22 = F_13 ( V_40 ) ;
unsigned long V_46 ;
int V_8 = 0 ;
if( V_22 -> V_47 == V_48 ) {
V_8 = - V_49 ;
goto V_31;
}
#if 0
if( !capable(CAP_NET_ADMIN )) {
ret = -EPERM;
return ret;
}
#endif
if( V_66 -> V_73 > V_163 ) {
V_8 = - V_9 ;
goto V_31;
}
F_14 ( V_22 , & V_46 ) ;
F_15 ( V_22 ) ;
memset ( V_22 -> V_179 , 0 , sizeof( V_22 -> V_179 ) ) ;
memcpy ( V_22 -> V_179 , V_178 , V_66 -> V_73 ) ;
F_11 ( V_22 ) ;
F_16 ( V_22 ) ;
F_17 ( V_22 , & V_46 ) ;
V_31:
return V_8 ;
}
static int F_54 ( struct V_39 * V_40 , struct V_41 * V_42 , struct V_65 * V_66 , char * V_178 )
{
struct V_21 * V_22 = F_13 ( V_40 ) ;
unsigned long V_46 ;
int V_8 = 0 ;
int V_69 = - 1 ;
T_11 * V_167 ;
if( V_22 -> V_47 == V_48 ) {
V_8 = - V_49 ;
goto V_31;
}
F_14 ( V_22 , & V_46 ) ;
F_15 ( V_22 ) ;
V_22 -> V_60 . V_13 = 1 + ( sizeof( * V_167 ) / sizeof( T_6 ) ) ;
V_22 -> V_60 . V_14 = V_180 ;
V_69 = F_24 ( & ( V_22 -> V_28 ) , ( V_62 ) & ( V_22 -> V_60 ) ) ;
if( V_69 == V_63 ) {
V_167 = ( T_11 * ) & ( V_22 -> V_60 . V_16 . V_77 ) ;
V_167 -> V_73 = F_25 ( V_167 -> V_73 ) ;
if ( V_167 -> V_73 > V_172 ) {
V_8 = - V_64 ;
} else {
V_66 -> V_73 = V_167 -> V_73 ;
memcpy ( V_178 , V_167 -> V_50 , V_167 -> V_73 ) ;
}
} else {
V_8 = - V_64 ;
}
F_16 ( V_22 ) ;
F_17 ( V_22 , & V_46 ) ;
V_31:
return V_8 ;
}
static int F_55 ( struct V_39 * V_40 , struct V_41 * V_42 , T_12 * V_181 , char * V_45 )
{
struct V_21 * V_22 = F_13 ( V_40 ) ;
unsigned long V_46 ;
int V_8 = 0 ;
T_6 V_182 ;
T_6 V_183 ;
if( V_22 -> V_47 == V_48 ) {
V_8 = - V_49 ;
goto V_31;
}
F_14 ( V_22 , & V_46 ) ;
F_15 ( V_22 ) ;
switch( * V_181 ) {
case V_184 :
V_182 = 1 ;
V_183 = 1 ;
V_22 -> V_185 = V_186 ;
break;
case V_187 :
case V_188 :
V_182 = 1 ;
V_183 = 0 ;
V_22 -> V_185 = V_186 ;
break;
#if 0
case IW_MODE_MASTER:
portType = 1;
lp->CreateIBSS = 0;
lp->DownloadFirmware = WVLAN_DRV_MODE_AP;
break;
#endif
default:
V_182 = 0 ;
V_183 = 0 ;
V_8 = - V_9 ;
}
if( V_182 != 0 ) {
if( ( V_22 -> V_189 != V_182 ) || ( V_22 -> V_190 != V_183 ) ) {
V_22 -> V_189 = V_182 ;
V_22 -> V_190 = V_183 ;
F_56 ( V_22 ) ;
F_57 ( V_22 -> V_40 ) ;
}
}
F_16 ( V_22 ) ;
F_17 ( V_22 , & V_46 ) ;
V_31:
return V_8 ;
}
static int F_58 ( struct V_39 * V_40 , struct V_41 * V_42 , T_12 * V_181 , char * V_45 )
{
struct V_21 * V_22 = F_13 ( V_40 ) ;
unsigned long V_46 ;
int V_8 = 0 ;
int V_69 = - 1 ;
T_6 * V_191 ;
if( V_22 -> V_47 == V_48 ) {
V_8 = - V_49 ;
goto V_31;
}
F_14 ( V_22 , & V_46 ) ;
F_15 ( V_22 ) ;
V_22 -> V_60 . V_13 = 1 + ( sizeof( * V_191 ) / sizeof( T_6 ) ) ;
V_22 -> V_60 . V_14 = V_192 ;
V_69 = F_24 ( & ( V_22 -> V_28 ) , ( V_62 ) & ( V_22 -> V_60 ) ) ;
if( V_69 == V_63 ) {
V_191 = ( T_6 * ) & ( V_22 -> V_60 . V_16 . V_77 ) ;
* V_191 = F_25 ( * V_191 ) ;
switch( * V_191 ) {
case 1 :
#if 0
#if ( V_193 ) & V_194
if ( CNV_INT_TO_LITTLE( lp->hcfCtx.IFB_FWIdentity.comp_id ) == COMP_ID_FW_AP ) {
*mode = IW_MODE_MASTER;
} else {
*mode = IW_MODE_INFRA;
}
#else
*mode = IW_MODE_INFRA;
#endif
#endif
if ( F_34 ( V_22 -> V_28 . V_133 . V_134 ) == V_169 ) {
* V_181 = V_195 ;
} else {
if( V_22 -> V_190 ) {
* V_181 = V_184 ;
} else {
* V_181 = V_188 ;
}
}
break;
case 3 :
* V_181 = V_184 ;
break;
default:
V_8 = - V_64 ;
break;
}
} else {
V_8 = - V_64 ;
}
F_16 ( V_22 ) ;
F_17 ( V_22 , & V_46 ) ;
V_31:
return V_8 ;
}
static int F_59 ( struct V_39 * V_40 , struct V_41 * V_42 , struct V_156 * V_196 , char * V_45 )
{
struct V_21 * V_22 = F_13 ( V_40 ) ;
unsigned long V_46 ;
int V_8 = 0 ;
if( V_22 -> V_47 == V_48 ) {
V_8 = - V_49 ;
goto V_31;
}
F_43 ( L_29 ) ;
#if 0
if( !capable( CAP_NET_ADMIN )) {
ret = -EPERM;
return ret;
}
#endif
F_14 ( V_22 , & V_46 ) ;
F_15 ( V_22 ) ;
if( V_196 -> V_197 ) {
V_22 -> V_198 = 0 ;
} else {
V_22 -> V_198 = 1 ;
}
F_11 ( V_22 ) ;
F_16 ( V_22 ) ;
F_17 ( V_22 , & V_46 ) ;
V_31:
return V_8 ;
}
static int F_60 ( struct V_39 * V_40 , struct V_41 * V_42 , struct V_156 * V_199 , char * V_45 )
{
struct V_21 * V_22 = F_13 ( V_40 ) ;
unsigned long V_46 ;
int V_8 = 0 ;
if( V_22 -> V_47 == V_48 ) {
V_8 = - V_49 ;
goto V_31;
}
F_43 ( L_30 ) ;
F_14 ( V_22 , & V_46 ) ;
F_15 ( V_22 ) ;
V_199 -> V_46 = 0 ;
V_199 -> V_159 = 0 ;
if( V_22 -> V_198 ) {
V_199 -> V_197 = 0 ;
} else {
V_199 -> V_197 = 1 ;
}
F_16 ( V_22 ) ;
F_17 ( V_22 , & V_46 ) ;
V_31:
return V_8 ;
}
static int F_61 ( struct V_39 * V_40 , struct V_41 * V_42 , struct V_156 * V_199 , char * V_45 )
{
struct V_21 * V_22 = F_13 ( V_40 ) ;
unsigned long V_46 ;
int V_8 = 0 ;
if( V_22 -> V_47 == V_48 ) {
V_8 = - V_49 ;
goto V_31;
}
F_14 ( V_22 , & V_46 ) ;
F_15 ( V_22 ) ;
#ifdef F_62
V_199 -> V_159 = V_200 ;
V_199 -> V_46 = V_201 ;
#else
V_199 -> V_159 = V_107 ;
V_199 -> V_46 = V_104 ;
#endif
V_199 -> V_161 = 1 ;
V_199 -> V_197 = 0 ;
F_16 ( V_22 ) ;
F_17 ( V_22 , & V_46 ) ;
V_31:
return V_8 ;
}
static int F_63 ( struct V_39 * V_40 , struct V_41 * V_42 , struct V_156 * V_202 , char * V_45 )
{
int V_8 = 0 ;
struct V_21 * V_22 = F_13 ( V_40 ) ;
unsigned long V_46 ;
int V_203 = V_202 -> V_159 ;
if( V_22 -> V_47 == V_48 ) {
V_8 = - V_49 ;
goto V_31;
}
if( V_202 -> V_161 == 0 ) {
V_8 = - V_9 ;
goto V_31;
}
if( V_202 -> V_197 ) {
V_203 = 2347 ;
}
if( ( V_203 < 256 ) || ( V_203 > 2347 ) ) {
V_8 = - V_9 ;
goto V_31;
}
F_14 ( V_22 , & V_46 ) ;
F_15 ( V_22 ) ;
V_22 -> V_204 = V_203 ;
F_11 ( V_22 ) ;
F_16 ( V_22 ) ;
F_17 ( V_22 , & V_46 ) ;
V_31:
return V_8 ;
}
static int F_64 ( struct V_39 * V_40 , struct V_41 * V_42 , struct V_156 * V_202 , char * V_45 )
{
int V_8 = 0 ;
struct V_21 * V_22 = F_13 ( V_40 ) ;
unsigned long V_46 ;
if( V_22 -> V_47 == V_48 ) {
V_8 = - V_49 ;
goto V_31;
}
F_14 ( V_22 , & V_46 ) ;
F_15 ( V_22 ) ;
V_202 -> V_159 = V_22 -> V_204 ;
V_202 -> V_197 = ( V_202 -> V_159 == 2347 ) ;
V_202 -> V_161 = 1 ;
F_16 ( V_22 ) ;
F_17 ( V_22 , & V_46 ) ;
V_31:
return V_8 ;
}
static int F_65 ( struct V_39 * V_40 , struct V_41 * V_42 , struct V_156 * V_199 , char * V_45 )
{
struct V_21 * V_22 = F_13 ( V_40 ) ;
unsigned long V_46 ;
int V_8 = 0 ;
#ifdef F_36
int V_69 = - 1 ;
int V_177 = 0 ;
#endif
if( V_22 -> V_47 == V_48 ) {
V_8 = - V_49 ;
goto V_31;
}
F_14 ( V_22 , & V_46 ) ;
F_15 ( V_22 ) ;
#ifdef F_36
V_22 -> V_60 . V_13 = 2 ;
V_22 -> V_60 . V_14 = V_61 ;
V_69 = F_24 ( & ( V_22 -> V_28 ) , ( V_62 ) & ( V_22 -> V_60 ) ) ;
if( V_69 == V_63 ) {
V_177 = ( F_25 ( V_22 -> V_60 . V_16 . T_2 [ 0 ] ) & 0x100 ) ? 1 : 0 ;
F_43 ( L_31 , V_177 ) ;
} else {
F_42 ( V_29 , L_32 ) ;
V_8 = - V_9 ;
goto V_76;
}
if( V_199 -> V_159 > 0 &&
V_199 -> V_159 <= 1 * V_79 ) {
V_22 -> V_205 [ V_177 ] = 0x0001 ;
}
else if( V_199 -> V_159 > 1 * V_79 &&
V_199 -> V_159 <= 2 * V_79 ) {
if( V_199 -> V_161 == 1 ) {
V_22 -> V_205 [ V_177 ] = 0x0002 ;
} else {
V_22 -> V_205 [ V_177 ] = 0x0003 ;
}
}
else if( V_199 -> V_159 > 2 * V_79 &&
V_199 -> V_159 <= 5 * V_79 ) {
if( V_199 -> V_161 == 1 ) {
V_22 -> V_205 [ V_177 ] = 0x0004 ;
} else {
V_22 -> V_205 [ V_177 ] = 0x0007 ;
}
}
else if( V_199 -> V_159 > 5 * V_79 &&
V_199 -> V_159 <= 6 * V_79 ) {
if( V_199 -> V_161 == 1 ) {
V_22 -> V_205 [ V_177 ] = 0x0010 ;
} else {
V_22 -> V_205 [ V_177 ] = 0x0017 ;
}
}
else if( V_199 -> V_159 > 6 * V_79 &&
V_199 -> V_159 <= 9 * V_79 ) {
if( V_199 -> V_161 == 1 ) {
V_22 -> V_205 [ V_177 ] = 0x0020 ;
} else {
V_22 -> V_205 [ V_177 ] = 0x0037 ;
}
}
else if( V_199 -> V_159 > 9 * V_79 &&
V_199 -> V_159 <= 11 * V_79 ) {
if( V_199 -> V_161 == 1 ) {
V_22 -> V_205 [ V_177 ] = 0x0008 ;
} else {
V_22 -> V_205 [ V_177 ] = 0x003F ;
}
}
else if( V_199 -> V_159 > 11 * V_79 &&
V_199 -> V_159 <= 12 * V_79 ) {
if( V_199 -> V_161 == 1 ) {
V_22 -> V_205 [ V_177 ] = 0x0040 ;
} else {
V_22 -> V_205 [ V_177 ] = 0x007F ;
}
}
else if( V_199 -> V_159 > 12 * V_79 &&
V_199 -> V_159 <= 18 * V_79 ) {
if( V_199 -> V_161 == 1 ) {
V_22 -> V_205 [ V_177 ] = 0x0080 ;
} else {
V_22 -> V_205 [ V_177 ] = 0x00FF ;
}
}
else if( V_199 -> V_159 > 18 * V_79 &&
V_199 -> V_159 <= 24 * V_79 ) {
if( V_199 -> V_161 == 1 ) {
V_22 -> V_205 [ V_177 ] = 0x0100 ;
} else {
V_22 -> V_205 [ V_177 ] = 0x01FF ;
}
}
else if( V_199 -> V_159 > 24 * V_79 &&
V_199 -> V_159 <= 36 * V_79 ) {
if( V_199 -> V_161 == 1 ) {
V_22 -> V_205 [ V_177 ] = 0x0200 ;
} else {
V_22 -> V_205 [ V_177 ] = 0x03FF ;
}
}
else if( V_199 -> V_159 > 36 * V_79 &&
V_199 -> V_159 <= 48 * V_79 ) {
if( V_199 -> V_161 == 1 ) {
V_22 -> V_205 [ V_177 ] = 0x0400 ;
} else {
V_22 -> V_205 [ V_177 ] = 0x07FF ;
}
}
else if( V_199 -> V_159 > 48 * V_79 &&
V_199 -> V_159 <= 54 * V_79 ) {
if( V_199 -> V_161 == 1 ) {
V_22 -> V_205 [ V_177 ] = 0x0800 ;
} else {
V_22 -> V_205 [ V_177 ] = 0x0FFF ;
}
}
else if( V_199 -> V_161 == 0 ) {
V_22 -> V_205 [ V_177 ] = V_206 ;
} else {
V_199 -> V_159 = 0 ;
V_8 = - V_9 ;
goto V_76;
}
#else
if( V_199 -> V_159 > 0 &&
V_199 -> V_159 <= 1 * V_79 ) {
V_22 -> V_205 [ 0 ] = 1 ;
}
else if( V_199 -> V_159 > 1 * V_79 &&
V_199 -> V_159 <= 2 * V_79 ) {
if( V_199 -> V_161 ) {
V_22 -> V_205 [ 0 ] = 2 ;
} else {
V_22 -> V_205 [ 0 ] = 6 ;
}
}
else if( V_199 -> V_159 > 2 * V_79 &&
V_199 -> V_159 <= 5 * V_79 ) {
if( V_199 -> V_161 ) {
V_22 -> V_205 [ 0 ] = 4 ;
} else {
V_22 -> V_205 [ 0 ] = 7 ;
}
}
else if( V_199 -> V_159 > 5 * V_79 &&
V_199 -> V_159 <= 11 * V_79 ) {
if( V_199 -> V_161 ) {
V_22 -> V_205 [ 0 ] = 5 ;
} else {
V_22 -> V_205 [ 0 ] = 3 ;
}
}
else if( V_199 -> V_161 == 0 ) {
V_22 -> V_205 [ 0 ] = 3 ;
} else {
V_199 -> V_159 = 0 ;
V_8 = - V_9 ;
goto V_76;
}
#endif
F_11 ( V_22 ) ;
V_76:
F_16 ( V_22 ) ;
F_17 ( V_22 , & V_46 ) ;
V_31:
return V_8 ;
}
static int F_66 ( struct V_39 * V_40 , struct V_41 * V_42 , struct V_156 * V_199 , char * V_45 )
{
struct V_21 * V_22 = F_13 ( V_40 ) ;
unsigned long V_46 ;
int V_8 = 0 ;
int V_69 = - 1 ;
T_6 V_207 ;
if( V_22 -> V_47 == V_48 ) {
V_8 = - V_49 ;
goto V_31;
}
F_14 ( V_22 , & V_46 ) ;
F_15 ( V_22 ) ;
V_22 -> V_60 . V_13 = 1 + ( sizeof( V_207 ) / sizeof( T_6 ) ) ;
V_22 -> V_60 . V_14 = V_75 ;
V_69 = F_24 ( & ( V_22 -> V_28 ) , ( V_62 ) & ( V_22 -> V_60 ) ) ;
if( V_69 == V_63 ) {
#ifdef F_36
V_207 = F_25 ( V_22 -> V_60 . V_16 . T_2 [ 0 ] ) ;
if( V_207 & 0x0001 ) {
V_207 = 1 ;
}
else if( V_207 & 0x0002 ) {
V_207 = 2 ;
}
else if( V_207 & 0x0004 ) {
V_207 = 5 ;
}
else if( V_207 & 0x0008 ) {
V_207 = 11 ;
}
else if( V_207 & 0x00010 ) {
V_207 = 6 ;
}
else if( V_207 & 0x00020 ) {
V_207 = 9 ;
}
else if( V_207 & 0x00040 ) {
V_207 = 12 ;
}
else if( V_207 & 0x00080 ) {
V_207 = 18 ;
}
else if( V_207 & 0x00100 ) {
V_207 = 24 ;
}
else if( V_207 & 0x00200 ) {
V_207 = 36 ;
}
else if( V_207 & 0x00400 ) {
V_207 = 48 ;
}
else if( V_207 & 0x00800 ) {
V_207 = 54 ;
}
#else
V_207 = ( T_6 ) F_67 ( V_22 -> V_60 . V_16 . V_77 [ 0 ] ) ;
#endif
V_199 -> V_159 = V_207 * V_79 ;
} else {
V_199 -> V_159 = 0 ;
V_8 = - V_64 ;
}
F_16 ( V_22 ) ;
F_17 ( V_22 , & V_46 ) ;
V_31:
return V_8 ;
}
static int F_68 ( struct V_39 * V_40 , struct V_41 * V_42 , struct V_65 * V_66 , char * V_45 )
{
struct V_21 * V_22 = F_13 ( V_40 ) ;
unsigned long V_46 ;
int V_8 = 0 ;
int V_69 = - 1 ;
int V_72 = 0 ;
if( V_22 -> V_47 == V_48 ) {
V_8 = - V_49 ;
goto V_31;
}
F_14 ( V_22 , & V_46 ) ;
F_15 ( V_22 ) ;
if( ( V_22 -> V_28 . V_208 & V_209 ) != 0 )
{
F_9 ( V_29 , L_33 ) ;
F_28 ( V_40 ) ;
}
V_74:
V_22 -> V_143 . V_144 = FALSE ;
#ifdef F_36
V_22 -> V_60 . V_13 = 5 ;
V_22 -> V_60 . V_14 = V_210 ;
V_22 -> V_60 . V_16 . T_2 [ 0 ] = F_34 ( 0x3FFF ) ;
V_22 -> V_60 . V_16 . T_2 [ 1 ] = F_34 ( 0xFFFF ) ;
V_22 -> V_60 . V_16 . T_2 [ 2 ] = F_34 ( 0xFFFF ) ;
V_22 -> V_60 . V_16 . T_2 [ 3 ] = F_34 ( 0x0007 ) ;
#else
V_22 -> V_60 . V_13 = 2 ;
V_22 -> V_60 . V_14 = V_210 ;
V_22 -> V_60 . V_16 . T_2 [ 0 ] = F_34 ( 0x7FFF ) ;
#endif
V_69 = F_37 ( & ( V_22 -> V_28 ) , ( V_62 ) & ( V_22 -> V_60 ) ) ;
F_9 ( V_29 , L_34 , V_69 ) ;
F_17 ( V_22 , & V_46 ) ;
F_14 ( V_22 , & V_46 ) ;
if( V_69 != V_63 ) {
V_72 ++ ;
if( V_72 <= 10 ) {
F_9 ( V_29 , L_35 , V_72 ) ;
F_28 ( V_40 ) ;
F_17 ( V_22 , & V_46 ) ;
F_14 ( V_22 , & V_46 ) ;
goto V_74;
}
}
V_22 -> V_60 . V_13 = 18 ;
V_22 -> V_60 . V_14 = V_146 ;
V_22 -> V_60 . V_16 . T_2 [ 0 ] = F_34 ( 0 ) ;
V_22 -> V_60 . V_16 . T_2 [ 1 ] = F_34 ( 0 ) ;
V_69 = F_37 ( & ( V_22 -> V_28 ) , ( V_62 ) & ( V_22 -> V_60 ) ) ;
F_17 ( V_22 , & V_46 ) ;
F_14 ( V_22 , & V_46 ) ;
F_9 ( V_29 , L_36 , V_69 ) ;
V_69 = F_38 ( & ( V_22 -> V_28 ) , V_148 ) ;
if( V_69 == V_63 ) {
F_9 ( V_29 , L_22 ) ;
} else {
F_9 ( V_29 , L_37 ) ;
}
F_16 ( V_22 ) ;
F_17 ( V_22 , & V_46 ) ;
V_31:
return V_8 ;
}
static int F_69 ( struct V_39 * V_40 , struct V_41 * V_42 , struct V_65 * V_66 , char * V_45 )
{
struct V_21 * V_22 = F_13 ( V_40 ) ;
unsigned long V_46 ;
int V_8 = 0 ;
int V_70 ;
char * V_211 ;
char * V_212 ;
struct V_213 V_214 ;
T_13 * V_215 ;
T_5 V_216 [ 512 ] ;
T_5 * V_217 ;
T_6 V_218 ;
if( V_22 -> V_47 == V_48 ) {
V_8 = - V_49 ;
goto V_31;
}
F_14 ( V_22 , & V_46 ) ;
F_15 ( V_22 ) ;
if( ! V_22 -> V_143 . V_144 ) {
V_8 = - V_219 ;
goto V_76;
}
F_9 ( V_29 , L_38 ,
V_22 -> V_143 . V_137 ) ;
V_211 = V_45 ;
V_212 = V_45 + V_220 ;
for( V_70 = 0 ; V_70 < V_22 -> V_143 . V_137 ; V_70 ++ ) {
V_215 = ( T_13 * ) & V_22 -> V_143 . V_154 [ V_70 ] ;
memset ( & V_214 , 0 , sizeof( V_214 ) ) ;
V_214 . V_221 = V_115 ;
V_214 . V_16 . V_128 . V_129 = V_130 ;
memcpy ( V_214 . V_16 . V_128 . V_131 , V_215 -> V_155 , V_17 ) ;
V_214 . V_13 = V_222 ;
V_211 = F_70 ( V_42 , V_211 , V_212 ,
& V_214 , V_222 ) ;
memset ( & V_214 , 0 , sizeof( V_214 ) ) ;
V_214 . V_221 = V_223 ;
if( V_215 -> V_224 & V_225 ) {
V_214 . V_16 . V_181 = V_188 ;
} else {
V_214 . V_16 . V_181 = V_195 ;
}
V_214 . V_13 = V_226 ;
V_211 = F_70 ( V_42 , V_211 , V_212 ,
& V_214 , V_226 ) ;
memset ( & V_214 , 0 , sizeof( V_214 ) ) ;
V_214 . V_221 = V_227 ;
V_214 . V_16 . V_85 . V_88 = F_29 ( V_215 -> signal ) ;
V_214 . V_16 . V_85 . V_90 = F_29 ( V_215 -> V_228 ) ;
V_214 . V_16 . V_85 . V_85 = V_214 . V_16 . V_85 . V_88 - V_214 . V_16 . V_85 . V_90 ;
V_214 . V_16 . V_85 . V_229 = V_22 -> V_143 . V_144 | V_230 ;
V_214 . V_13 = V_231 ;
V_211 = F_70 ( V_42 , V_211 , V_212 ,
& V_214 , V_231 ) ;
if( V_215 -> V_232 [ 1 ] > 0 ) {
memset ( & V_214 , 0 , sizeof( V_214 ) ) ;
V_214 . V_221 = V_233 ;
V_214 . V_16 . V_66 . V_73 = V_215 -> V_232 [ 1 ] ;
V_214 . V_16 . V_66 . V_46 = 1 ;
V_211 = F_71 ( V_42 , V_211 , V_212 ,
& V_214 , & V_215 -> V_232 [ 2 ] ) ;
}
memset ( & V_214 , 0 , sizeof( V_214 ) ) ;
V_214 . V_221 = V_234 ;
V_214 . V_16 . V_66 . V_73 = 0 ;
if( V_215 -> V_224 & V_235 ) {
V_214 . V_16 . V_66 . V_46 |= V_236 ;
} else {
V_214 . V_16 . V_66 . V_46 |= V_176 ;
}
V_211 = F_71 ( V_42 , V_211 , V_212 , & V_214 , NULL ) ;
memset ( & V_214 , 0 , sizeof( V_214 ) ) ;
V_214 . V_221 = V_237 ;
V_214 . V_13 = V_238 ;
V_214 . V_16 . V_52 . V_58 = F_72 ( V_215 ) ;
V_214 . V_16 . V_52 . V_56 = 0 ;
V_211 = F_70 ( V_42 , V_211 , V_212 ,
& V_214 , V_238 ) ;
memset ( & V_214 , 0 , sizeof( V_214 ) ) ;
memset ( V_216 , 0 , sizeof( V_216 ) ) ;
V_214 . V_221 = V_239 ;
sprintf ( V_216 , L_39 , V_215 -> V_240 ) ;
V_214 . V_16 . V_66 . V_73 = strlen ( V_216 ) ;
V_211 = F_71 ( V_42 , V_211 , V_212 , & V_214 , V_216 ) ;
V_217 = NULL ;
V_218 = 0 ;
V_217 = F_73 ( V_215 , & V_218 ) ;
if( V_217 != NULL ) {
memset ( & V_214 , 0 , sizeof( V_214 ) ) ;
V_214 . V_221 = V_241 ;
V_214 . V_16 . V_66 . V_73 = V_218 ;
V_211 = F_71 ( V_42 , V_211 , V_212 ,
& V_214 , V_217 ) ;
}
}
V_66 -> V_73 = V_211 - V_45 ;
V_76:
F_16 ( V_22 ) ;
F_17 ( V_22 , & V_46 ) ;
V_31:
return V_8 ;
}
static int F_74 ( struct V_39 * V_40 ,
struct V_41 * V_42 ,
struct V_156 * V_66 , char * V_45 )
{
struct V_21 * V_22 = F_13 ( V_40 ) ;
unsigned long V_46 ;
T_1 V_1 ;
int V_8 ;
int V_242 = V_66 -> V_46 & V_243 ;
int V_244 = V_66 -> V_159 ;
if ( V_22 -> V_47 == V_48 ) {
V_8 = - V_49 ;
goto V_31;
}
F_14 ( V_22 , & V_46 ) ;
F_15 ( V_22 ) ;
if ( V_242 > V_245 )
V_242 = V_245 + 1 ;
F_9 ( V_29 , L_40 , V_246 [ V_242 ] ) ;
switch ( V_242 ) {
case V_247 :
if ( ( V_244 == V_248 ) ||
( V_244 == V_249 ) )
V_8 = 0 ;
else
V_8 = - V_9 ;
break;
case V_250 :
F_9 ( V_29 , L_41 , V_244 ) ;
if ( V_244 )
V_22 -> V_25 = 2 ;
else
V_22 -> V_25 = 0 ;
V_1 . V_13 = 2 ;
V_1 . V_14 = V_251 ;
V_1 . V_16 . T_2 [ 0 ] = F_2 ( V_22 -> V_25 ) ;
V_8 = F_37 ( & V_22 -> V_28 , ( V_62 ) & V_1 ) ;
break;
case V_252 :
V_22 -> V_253 = ! V_244 ;
if ( V_22 -> V_253 )
F_75 ( & ( V_22 -> V_28 ) , V_254 | V_255 ) ;
else
F_75 ( & ( V_22 -> V_28 ) , V_256 | V_255 ) ;
V_8 = 0 ;
break;
case V_245 :
if ( V_244 == V_257 )
V_8 = - V_9 ;
else
V_8 = 0 ;
break;
case V_258 :
if ( V_244 != 0 )
V_22 -> V_259 = 4 ;
else
V_22 -> V_259 = 0 ;
V_8 = - V_260 ;
break;
case V_261 :
V_8 = - V_260 ;
if ( V_244 & V_262 )
V_22 -> V_263 = 1 ;
else if ( V_244 & V_264 )
V_22 -> V_263 = 0 ;
else
V_8 = - V_9 ;
break;
case V_265 :
V_22 -> V_266 = V_244 ;
V_8 = - V_260 ;
break;
case V_267 :
case V_268 :
case V_269 :
case V_270 :
case V_271 :
V_8 = - V_260 ;
break;
default:
F_9 ( V_29 , L_42 , V_242 ) ;
V_8 = - V_30 ;
break;
}
F_16 ( V_22 ) ;
F_17 ( V_22 , & V_46 ) ;
V_31:
return V_8 ;
}
static void F_76 ( struct V_21 * V_22 )
{
T_1 V_1 ;
int V_70 ;
for ( V_70 = 0 ; V_70 < 100 ; V_70 ++ ) {
F_77 ( 1000 ) ;
V_1 . V_13 = 2 ;
V_1 . V_14 = 0xFD91 ;
V_1 . V_16 . T_2 [ 0 ] = 0 ;
F_24 ( & ( V_22 -> V_28 ) , ( V_62 ) & V_1 ) ;
if ( V_1 . V_16 . T_2 [ 0 ] == 0 )
break;
}
if ( V_70 >= 100 )
F_9 ( V_29 , L_43 ) ;
}
static int F_78 ( struct V_39 * V_40 ,
struct V_41 * V_42 ,
struct V_65 * V_173 , char * V_174 )
{
struct V_21 * V_22 = F_13 ( V_40 ) ;
unsigned long V_46 ;
int V_8 ;
int V_2 = ( V_173 -> V_46 & V_175 ) - 1 ;
T_1 V_1 ;
struct V_272 * V_273 = (struct V_272 * ) V_174 ;
bool V_23 = true ;
bool V_4 = false ;
if ( V_22 -> V_47 == V_48 ) {
V_8 = - V_49 ;
goto V_31;
}
if ( V_173 -> V_46 & V_176 ) {
V_273 -> V_274 = V_38 ;
V_23 = false ;
}
if ( V_273 -> V_275 & V_276 )
V_4 = true ;
F_14 ( V_22 , & V_46 ) ;
F_15 ( V_22 ) ;
memset ( & V_1 , 0 , sizeof( V_1 ) ) ;
switch ( V_273 -> V_274 ) {
case V_277 :
F_9 ( V_29 , L_44 , V_2 ) ;
if ( sizeof( V_273 -> V_278 ) != 8 ) {
F_9 ( V_29 , L_45 ) ;
V_8 = - V_9 ;
goto V_76;
}
V_8 = F_1 ( & V_1 , V_2 , V_273 -> V_3 . V_131 ,
V_4 ,
V_273 -> V_278 , V_273 -> V_6 , V_273 -> V_7 ) ;
if ( V_8 != 0 ) {
F_9 ( V_29 , L_46 ) ;
goto V_76;
}
F_76 ( V_22 ) ;
V_22 -> V_36 = V_277 ;
V_8 = F_37 ( & ( V_22 -> V_28 ) , ( V_62 ) & V_1 ) ;
break;
case V_37 :
F_9 ( V_29 , L_47 , V_2 ) ;
if ( V_173 -> V_46 & V_279 ) {
F_7 ( V_29 , L_48 ) ;
V_8 = - V_9 ;
goto V_76;
}
V_8 = F_5 ( V_22 , V_2 , V_273 -> V_6 , V_273 -> V_7 ,
V_23 , V_4 ) ;
break;
case V_280 :
F_9 ( V_29 , L_49 , V_2 ) ;
V_8 = - V_30 ;
break;
case V_38 :
F_9 ( V_29 , L_50 , V_2 ) ;
if ( V_22 -> V_36 == V_277 ) {
V_8 = F_3 ( & V_1 , V_2 ,
V_273 -> V_3 . V_131 ) ;
F_76 ( V_22 ) ;
V_22 -> V_36 = V_38 ;
V_8 = F_37 ( & ( V_22 -> V_28 ) , ( V_62 ) & V_1 ) ;
} else if ( V_22 -> V_36 == V_37 ) {
V_8 = F_5 ( V_22 , V_2 ,
V_273 -> V_6 , V_273 -> V_7 ,
false , false ) ;
} else {
V_8 = 0 ;
}
break;
default:
F_9 ( V_29 , L_51 , V_2 ) ;
V_8 = - V_30 ;
break;
}
V_76:
F_16 ( V_22 ) ;
F_17 ( V_22 , & V_46 ) ;
V_31:
return V_8 ;
}
static int F_79 ( struct V_39 * V_40 ,
struct V_41 * V_42 ,
struct V_65 * V_66 , char * V_45 )
{
int V_8 = 0 ;
V_8 = 0 ;
return V_8 ;
}
struct V_281 * F_30 ( struct V_39 * V_40 )
{
struct V_281 * V_282 ;
struct V_21 * V_22 = F_13 ( V_40 ) ;
F_80 ( V_29 , L_52 , L_53 , V_40 -> V_50 , V_40 ) ;
V_282 = NULL ;
V_282 = & ( V_22 -> V_113 ) ;
V_282 -> V_85 . V_229 = 0x00 ;
if( ! ( V_22 -> V_46 & V_283 ) )
{
T_14 * V_284 ;
T_15 V_285 ;
int V_69 ;
V_282 -> V_69 = 0 ;
V_22 -> V_60 . V_13 = 1 + ( sizeof( * V_284 ) / sizeof( T_6 ) ) ;
V_22 -> V_60 . V_14 = V_286 ;
V_69 = F_24 ( & ( V_22 -> V_28 ) , ( V_62 ) & ( V_22 -> V_60 ) ) ;
if( V_69 == V_63 ) {
V_284 = ( T_14 * ) & ( V_22 -> V_60 ) ;
V_282 -> V_85 . V_85 = ( V_86 ) F_25 ( V_284 -> V_287 ) ;
V_282 -> V_85 . V_88 = ( V_86 ) F_29 ( F_25 ( V_284 -> V_288 ) ) ;
V_282 -> V_85 . V_90 = ( V_86 ) F_29 ( F_25 ( V_284 -> V_289 ) ) ;
V_282 -> V_85 . V_229 |= ( V_290 |
V_291 |
V_292 |
V_230 ) ;
} else {
memset ( & ( V_282 -> V_85 ) , 0 , sizeof( V_282 -> V_85 ) ) ;
}
if( V_22 -> V_47 == V_48 ) {
if( F_81 ( V_22 , & V_285 ) == 0 ) {
V_282 -> V_293 . V_294 = 0L ;
V_282 -> V_293 . V_295 = V_285 . V_296 ;
V_282 -> V_293 . V_297 = V_285 . V_298 +
V_285 . V_299 +
V_285 . V_300 ;
V_282 -> V_293 . V_72 = V_285 . V_301 ;
V_282 -> V_293 . V_302 = V_285 . V_303 ;
} else {
memset ( & ( V_282 -> V_293 ) , 0 , sizeof( V_282 -> V_293 ) ) ;
}
} else {
memset ( & ( V_282 -> V_293 ) , 0 , sizeof( V_282 -> V_293 ) ) ;
}
}
return V_282 ;
}
struct V_281 * F_82 ( struct V_39 * V_40 )
{
unsigned long V_46 ;
struct V_21 * V_22 = F_13 ( V_40 ) ;
struct V_281 * V_282 = NULL ;
F_14 ( V_22 , & V_46 ) ;
F_15 ( V_22 ) ;
#ifdef F_83
if( V_22 -> V_304 == 1 ) {
F_9 ( V_29 , L_54 ) ;
} else
#endif
{
V_282 = F_30 ( V_40 ) ;
}
F_16 ( V_22 ) ;
F_17 ( V_22 , & V_46 ) ;
return V_282 ;
}
inline void F_84 ( struct V_39 * V_40 , V_86 * V_305 )
{
struct V_140 V_113 ;
int V_69 ;
V_86 V_306 [ 2 ] ;
T_16 V_307 [ 1 ] ;
struct V_21 * V_22 = F_13 ( V_40 ) ;
if ( ! V_22 -> V_308 . V_309 ) {
return;
}
memset ( V_306 , 0 , sizeof( V_306 ) ) ;
memset ( V_307 , 0 , sizeof( T_16 ) ) ;
V_307 [ 0 ] . V_310 = V_306 ;
V_307 [ 0 ] . V_311 = sizeof( V_306 ) ;
V_307 [ 0 ] . V_312 = 0 ;
V_69 = F_85 ( & ( V_22 -> V_28 ) , & V_307 [ 0 ] , 0 ) ;
if( V_69 == V_63 ) {
V_113 . V_88 = ( V_86 ) F_29 ( V_306 [ 1 ] ) ;
V_113 . V_90 = ( V_86 ) F_29 ( V_306 [ 0 ] ) ;
V_113 . V_85 = V_113 . V_88 > V_113 . V_90 ? V_113 . V_88 - V_113 . V_90 : 0 ;
V_113 . V_229 = ( V_290 |
V_291 |
V_292 |
V_230 ) ;
F_86 ( V_40 , V_305 , & V_113 ) ;
}
}
void F_22 ( struct V_39 * V_40 )
{
union V_43 V_313 ;
struct V_21 * V_22 = F_13 ( V_40 ) ;
memset ( & V_313 , 0 , sizeof( V_313 ) ) ;
V_313 . V_52 . V_58 = V_22 -> V_59 ;
V_313 . V_52 . V_56 = 0 ;
F_87 ( V_40 , V_314 , & V_313 , NULL ) ;
return;
}
void F_57 ( struct V_39 * V_40 )
{
union V_43 V_313 ;
struct V_21 * V_22 = F_13 ( V_40 ) ;
memset ( & V_313 , 0 , sizeof( V_313 ) ) ;
if ( F_34 ( V_22 -> V_28 . V_133 . V_134 ) == V_135 ) {
V_313 . V_181 = V_188 ;
} else {
V_313 . V_181 = V_195 ;
}
F_87 ( V_40 , V_315 , & V_313 , NULL ) ;
return;
}
void F_48 ( struct V_39 * V_40 )
{
union V_43 V_313 ;
struct V_21 * V_22 = F_13 ( V_40 ) ;
memset ( & V_313 , 0 , sizeof( V_313 ) ) ;
V_313 . V_166 . V_73 = strlen ( V_22 -> V_164 ) ;
V_313 . V_166 . V_316 = ( void V_317 * ) V_22 -> V_164 ;
V_313 . V_166 . V_46 = 1 ;
F_87 ( V_40 , V_318 , & V_313 , V_22 -> V_164 ) ;
return;
}
void F_51 ( struct V_39 * V_40 )
{
union V_43 V_313 ;
struct V_21 * V_22 = F_13 ( V_40 ) ;
int V_177 = 0 ;
memset ( & V_313 , 0 , sizeof( V_313 ) ) ;
if( V_22 -> V_25 == 0 ) {
V_313 . V_319 . V_46 = V_176 ;
} else {
V_313 . V_319 . V_46 |= V_22 -> V_27 ;
V_177 = V_22 -> V_27 - 1 ;
#if 1
if ( F_34 ( V_22 -> V_28 . V_133 . V_134 ) == V_169 ) {
if( V_22 -> V_266 ) {
V_313 . V_319 . V_46 |= V_279 ;
} else {
V_313 . V_319 . V_46 |= V_320 ;
}
}
#endif
if( F_20 ( V_54 ) ) {
V_313 . V_319 . V_316 = ( void V_317 * ) V_22 -> V_35 . V_6 [ V_177 ] . V_6 ;
V_313 . V_319 . V_73 = V_22 -> V_35 . V_6 [ V_177 ] . V_13 ;
} else {
V_313 . V_319 . V_46 |= V_321 ;
}
}
F_87 ( V_40 , V_322 , & V_313 ,
V_22 -> V_35 . V_6 [ V_177 ] . V_6 ) ;
return;
}
void F_88 ( struct V_39 * V_40 )
{
union V_43 V_313 ;
struct V_21 * V_22 = F_13 ( V_40 ) ;
int V_69 ;
F_89 ( V_40 ) ;
V_22 -> V_60 . V_14 = V_136 ;
V_22 -> V_60 . V_13 = 4 ;
V_69 = F_24 ( & ( V_22 -> V_28 ) , ( V_62 ) & ( V_22 -> V_60 ) ) ;
if( V_69 == V_63 ) {
memset ( & V_313 , 0 , sizeof( V_313 ) ) ;
memcpy ( V_313 . V_3 . V_131 , V_22 -> V_60 . V_16 . T_3 , V_17 ) ;
V_313 . V_3 . V_129 = V_130 ;
F_87 ( V_40 , V_115 , & V_313 , NULL ) ;
}
return;
}
void F_44 ( struct V_39 * V_40 )
{
union V_43 V_313 ;
memset ( & V_313 , 0 , sizeof( V_313 ) ) ;
V_313 . V_3 . V_129 = V_130 ;
F_87 ( V_40 , V_116 , & V_313 , NULL ) ;
return;
}
void F_90 ( struct V_39 * V_40 )
{
union V_43 V_313 ;
memset ( & V_313 , 0 , sizeof( V_313 ) ) ;
memcpy ( V_313 . V_3 . V_131 , V_40 -> V_132 , V_17 ) ;
V_313 . V_3 . V_129 = V_130 ;
F_87 ( V_40 , V_117 , & V_313 , NULL ) ;
return;
}
void F_91 ( struct V_39 * V_40 )
{
union V_43 V_313 ;
memset ( & V_313 , 0 , sizeof( V_313 ) ) ;
memcpy ( V_313 . V_3 . V_131 , V_40 -> V_132 , V_17 ) ;
V_313 . V_3 . V_129 = V_130 ;
F_87 ( V_40 , V_118 , & V_313 , NULL ) ;
return;
}
void F_92 ( struct V_39 * V_40 )
{
union V_43 V_313 ;
struct V_21 * V_22 = F_13 ( V_40 ) ;
struct V_323 V_324 ;
int V_2 ;
char * V_325 ;
char * V_326 ;
T_17 * V_327 ;
V_2 = V_22 -> V_328 [ V_329 + 1 ] >> 3 ;
V_2 &= 0x03 ;
V_327 = ( T_17 * ) & V_22 -> V_328 [ V_329 ] ;
V_325 = ( char * ) V_327 -> V_330 ;
V_326 = ( char * ) V_327 -> V_331 ;
F_43 ( L_55 , V_2 ,
V_327 -> V_69 ) ;
memset ( & V_313 , 0 , sizeof( V_313 ) ) ;
memset ( & V_324 , 0 , sizeof( V_324 ) ) ;
V_324 . V_46 = V_2 & V_332 ;
V_324 . V_46 |= ( V_325 [ 0 ] & 1 ) ?
V_333 : V_334 ;
V_324 . V_335 . V_129 = V_130 ;
memcpy ( V_324 . V_335 . V_131 , V_326 , V_17 ) ;
V_313 . V_66 . V_73 = sizeof( V_324 ) ;
F_87 ( V_40 , V_119 , & V_313 , ( char * ) & V_324 ) ;
return;
}
void F_89 ( struct V_39 * V_40 )
{
union V_43 V_313 ;
struct V_21 * V_22 = F_13 ( V_40 ) ;
int V_69 ;
T_13 V_66 ;
T_6 V_73 ;
T_5 * V_217 ;
memset ( & V_313 , 0 , sizeof( V_313 ) ) ;
V_22 -> V_60 . V_13 = 45 ;
V_22 -> V_60 . V_14 = V_336 ;
V_69 = F_24 ( & ( V_22 -> V_28 ) , ( V_62 ) & ( V_22 -> V_60 ) ) ;
if( V_69 == V_63 )
{
V_73 = 0 ;
memcpy ( & V_66 . V_232 , & ( V_22 -> V_60 . V_16 . T_3 [ 1 ] ) , 88 ) ;
V_217 = F_73 ( & V_66 , & V_73 ) ;
if( V_73 != 0 )
{
V_313 . V_66 . V_73 = V_217 [ 1 ] + 2 ;
F_87 ( V_40 , V_120 ,
& V_313 , V_217 ) ;
F_87 ( V_40 , V_121 ,
& V_313 , V_217 ) ;
}
}
return;
}
