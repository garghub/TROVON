static T_1 char * F_1 ( const char * V_1 , const char * V_2 )
{
const char * V_3 ;
int V_4 ;
char * V_5 ;
V_3 = F_2 ( V_1 , V_2 ) ;
V_4 = 0 ;
while ( V_3 [ V_4 ] && V_3 [ V_4 ] != ' ' && V_3 [ V_4 ] != ',' )
V_4 ++ ;
V_5 = F_3 ( V_4 + 1 , V_6 ) ;
if ( V_5 ) {
strncpy ( V_5 , V_3 , V_4 ) ;
V_5 [ V_4 ] = '\0' ;
}
return V_5 ;
}
static T_1 int F_4 ( const char * V_1 , const char * V_2 ,
int * V_5 )
{
if ( ! V_5 )
return 0 ;
if ( ! F_5 ( V_1 , V_2 ) )
return 0 ;
* V_5 = F_6 ( V_1 , V_2 ) ;
return 1 ;
}
static T_1 int F_7 ( const char * V_1 , const char * V_2 ,
int * V_5 )
{
if ( ! V_5 )
return 0 ;
if ( F_5 ( V_1 , V_2 ) ) {
if ( V_1 [ strlen ( V_2 ) ] == '=' )
* V_5 = F_8 ( V_1 + strlen ( V_2 ) + 1 ,
NULL , 0 ) ;
else
* V_5 = 1 ;
} else {
if ( F_5 ( V_1 , L_1 ) && F_5 ( V_1 + 2 , V_2 ) )
* V_5 = 0 ;
else
return 0 ;
}
return 1 ;
}
static int T_2 F_9 ( char * V_7 )
{
char * V_1 ;
F_10 ( L_2 ) ;
if ( ! V_7 || ! * V_7 ) {
F_10 ( L_3 ) ;
return 0 ;
} else
F_10 ( L_4 , V_7 ) ;
while ( ( V_1 = F_11 ( & V_7 , L_5 ) ) ) {
if ( ! * V_1 )
continue;
if ( F_7 ( V_1 , L_6 , & V_8 ) )
;
else if ( F_4 ( V_1 , L_7 , & V_9 ) )
;
else if ( F_7 ( V_1 , L_8 , & V_10 ) )
;
else if ( F_7 ( V_1 , L_9 , & V_11 ) )
;
else if ( F_7 ( V_1 , L_10 , & V_12 ) )
;
else if ( F_7 ( V_1 , L_11 , & V_13 ) )
V_13 = ! V_13 ;
else if ( F_5 ( V_1 , L_12 ) )
V_14 = F_1 ( V_1 , L_12 ) ;
else
V_14 = V_1 ;
}
return 0 ;
}
static int T_2 F_12 ( void )
{
#ifndef F_13
char * V_15 = NULL ;
#endif
F_10 ( L_13 ) ;
F_14 ( L_14
L_15 V_16 L_16 ) ;
F_14 ( L_17 V_17 L_18 ) ;
if ( V_18 )
return - V_19 ;
#ifndef F_13
if ( F_15 ( L_19 , & V_15 ) )
return - V_19 ;
F_9 ( V_15 ) ;
#endif
return F_16 ( & V_20 ) ;
}
static void T_3 F_17 ( void )
{
F_10 ( L_20 ) ;
F_18 ( & V_20 ) ;
}
static inline void T_4 F_19 ( struct V_21 * V_22 )
{
V_22 -> V_23 = F_20 ( V_22 -> V_24 . V_25 ,
V_22 -> V_24 . V_26 , V_27 , 1 ) ;
if ( V_22 -> V_23 < 0 ) {
F_21 ( L_21 ) ;
return;
}
V_22 -> V_28 = 1 ;
}
static inline void F_22 ( struct V_21 * V_22 )
{
if ( V_22 -> V_28 )
F_23 ( V_22 -> V_23 , V_22 -> V_24 . V_25 ,
V_22 -> V_24 . V_26 ) ;
}
static void F_24 ( struct V_21 * V_22 )
{
F_10 ( L_22 ) ;
if ( ! V_22 )
return;
F_25 ( V_22 ) ;
F_26 ( & V_22 -> V_29 -> V_30 ) ;
F_27 ( V_22 -> V_29 -> V_31 . V_32 ) ;
if ( V_22 -> V_33 )
F_28 ( V_22 -> V_29 ) ;
F_22 ( V_22 ) ;
if ( V_22 -> V_34 && V_22 -> V_35 ) {
F_29 ( V_22 -> V_35 ) ;
F_30 ( V_22 -> V_35 ) ;
}
if ( V_22 -> V_36 ) {
F_29 ( V_22 -> V_36 ) ;
F_30 ( V_22 -> V_36 ) ;
}
if ( V_22 -> V_37 ) {
F_29 ( V_22 -> V_37 ) ;
F_30 ( V_22 -> V_37 ) ;
}
#ifdef F_31
F_32 ( V_22 ) ;
#endif
if ( V_22 -> V_38 )
F_33 ( ( void V_39 * ) V_22 -> V_38 ) ;
if ( V_22 -> V_24 . V_40 )
F_33 ( ( void V_39 * ) V_22 -> V_24 . V_40 ) ;
if ( V_22 -> V_41 & V_42 )
F_34 ( V_22 -> V_43 , V_44 ) ;
if ( V_22 -> V_41 & V_45 )
F_34 ( V_22 -> V_24 . V_25 ,
V_22 -> V_24 . V_26 ) ;
F_35 ( V_22 -> V_29 ) ;
}
static int T_4 F_36 ( struct V_46 * V_47 ,
const struct V_48 * V_49 )
{
struct V_50 * V_29 ;
struct V_21 * V_22 ;
int V_4 , V_51 , V_52 ;
int V_53 , V_54 ;
struct V_55 V_56 ;
int V_57 ;
const char * V_58 ;
struct V_59 * V_60 ;
int V_61 = 0 ;
int V_62 = 1 ;
int V_63 ;
F_10 ( L_23 ) ;
V_64 ++ ;
if ( V_64 != 1 ) {
F_21 ( L_24
L_25 , V_64 ) ;
return - V_19 ;
}
V_29 = F_37 ( sizeof( struct V_21 ) , & V_47 -> V_65 ) ;
if ( ! V_29 ) {
F_21 ( L_26 ) ;
return - V_19 ;
}
if ( F_38 ( & V_29 -> V_30 , 256 , 1 ) < 0 ) {
F_21 ( L_27 ) ;
goto V_66;
}
V_22 = V_29 -> V_67 ;
V_22 -> V_29 = V_29 ;
V_22 -> V_68 = & V_69 ;
V_22 -> V_47 = V_47 ;
V_29 -> V_31 . V_32 = F_39 ( 64 * 1024 , V_6 ) ;
if ( V_29 -> V_31 . V_32 == NULL ) {
F_21 ( L_28 ) ;
goto V_70;
}
V_22 -> V_71 = V_12 ;
if ( ( V_51 = F_40 ( V_47 ) ) ) {
F_21 ( L_29 ) ;
F_24 ( V_22 ) ;
return - V_19 ;
}
if ( ( V_49 -> V_72 == V_73 ) ||
( V_49 -> V_72 == V_74 ) ||
( V_49 -> V_72 == V_75 ) ||
( V_49 -> V_72 == V_76 ) ||
( V_49 -> V_72 == V_77 ) ||
( V_49 -> V_72 == V_78 ) ||
( V_49 -> V_72 == V_79 ) ) {
V_61 = 2 ;
V_62 = 0 ;
}
V_22 -> V_24 . V_25 = F_41 ( V_47 , V_61 ) ;
V_22 -> V_24 . V_26 = F_42 ( V_47 , V_61 ) ;
V_22 -> V_43 = F_41 ( V_47 , V_62 ) ;
F_10 ( L_30 ,
( unsigned long long ) F_41 ( V_47 , V_61 ) ,
( unsigned long long ) F_42 ( V_47 , V_61 ) ,
( unsigned long long ) F_41 ( V_47 , V_62 ) ,
( unsigned long long ) F_42 ( V_47 , V_62 ) ) ;
if ( ! F_43 ( V_22 -> V_24 . V_25 , V_22 -> V_24 . V_26 ,
V_80 ) ) {
F_21 ( L_31 ) ;
F_24 ( V_22 ) ;
return - V_19 ;
}
V_22 -> V_41 |= V_45 ;
if ( ! F_43 ( V_22 -> V_43 ,
V_44 ,
V_80 ) ) {
F_21 ( L_32 ) ;
F_24 ( V_22 ) ;
return - V_19 ;
}
V_22 -> V_41 |= V_42 ;
V_22 -> V_81 = V_47 -> V_72 ;
if ( F_44 ( V_47 , V_22 ) ) {
F_24 ( V_22 ) ;
return - V_19 ;
}
if ( F_45 ( V_47 , & V_53 , & V_54 ) ) {
F_24 ( V_22 ) ;
return - V_19 ;
}
F_14 ( L_33
L_34 ,
V_47 -> V_82 -> V_83 , F_46 ( V_47 -> V_84 ) ,
F_47 ( V_47 -> V_84 ) , V_22 -> V_2 ,
F_48 ( V_53 ) , F_49 ( V_54 ) ) ;
V_22 -> V_8 = V_8 ;
V_22 -> V_10 = V_10 ;
if ( F_50 ( V_22 ) && V_22 -> V_8 == 1 ) {
F_14 ( L_35 ,
V_22 -> V_2 ) ;
V_22 -> V_8 = 0 ;
}
if ( F_51 ( V_54 ) >= F_52 ( V_9 ) ) {
V_22 -> V_85 . V_26 = F_51 ( V_54 ) ;
V_22 -> V_34 = 0 ;
} else {
V_22 -> V_85 . V_26 = F_52 ( V_9 ) ;
V_22 -> V_34 = 1 ;
}
if ( V_22 -> V_8 ) {
V_22 -> V_86 . V_26 = V_87 ;
V_22 -> V_88 = V_22 -> V_86 . V_26 - 1 ;
}
if ( V_22 -> V_10 )
V_22 -> V_89 . V_26 = V_90 ;
if ( ! ( V_60 = F_53 ( V_47 ) ) ) {
F_21 ( L_36 ) ;
F_24 ( V_22 ) ;
return - V_19 ;
}
if ( F_54 ( V_60 , & V_56 ) ) {
F_21 ( L_37 ) ;
F_55 ( V_60 ) ;
F_24 ( V_22 ) ;
return - V_19 ;
}
if ( F_52 ( V_91 ) < V_54 )
V_63 = ( V_54 >> 12 ) ;
else
V_63 = F_51 ( F_52 ( V_91 ) ) / V_92 ;
if ( V_22 -> V_8 )
V_22 -> V_86 . V_63 = V_63 + V_56 . V_93 ;
if ( V_22 -> V_10 )
V_22 -> V_89 . V_63 = V_63 +
+ V_56 . V_93 + ( V_22 -> V_86 . V_26 >> 12 ) ;
if ( V_22 -> V_34 )
V_22 -> V_85 . V_63 = V_63 +
+ V_56 . V_93 + ( V_22 -> V_86 . V_26 >> 12 )
+ ( V_22 -> V_89 . V_26 >> 12 ) ;
V_22 -> V_24 . V_40 = ( V_94 V_39 * ) F_56
( V_22 -> V_24 . V_25 , ( ( V_63 + V_22 -> V_85 . V_63 ) << 12 )
+ V_22 -> V_85 . V_26 ) ;
if ( ! V_22 -> V_24 . V_40 ) {
F_21 ( L_38 ) ;
F_24 ( V_22 ) ;
return - V_19 ;
}
V_22 -> V_38 =
( V_94 V_39 * ) F_56 ( V_22 -> V_43 ,
V_44 ) ;
if ( ! V_22 -> V_38 ) {
F_21 ( L_39 ) ;
F_24 ( V_22 ) ;
return - V_19 ;
}
if ( V_22 -> V_8 ) {
if ( ! ( V_22 -> V_37 =
F_57 ( V_60 , V_22 -> V_86 . V_26 >> 12 ,
V_95 ) ) ) {
F_21 ( L_40 ) ;
F_55 ( V_60 ) ;
F_24 ( V_22 ) ;
return - V_96 ;
}
if ( F_58 ( V_22 -> V_37 ,
V_22 -> V_86 . V_63 ) ) {
F_21 ( L_41 ) ;
F_55 ( V_60 ) ;
F_24 ( V_22 ) ;
return - V_97 ;
}
V_22 -> V_86 . V_25 = V_22 -> V_24 . V_25
+ ( V_22 -> V_86 . V_63 << 12 ) ;
V_22 -> V_86 . V_40 = V_22 -> V_24 . V_40
+ ( V_22 -> V_86 . V_63 << 12 ) ;
V_22 -> V_98 = 0 ;
}
if ( V_22 -> V_10 ) {
V_57 = V_22 -> V_99 ? V_100
: V_95 ;
if ( ! ( V_22 -> V_36 =
F_57 ( V_60 , V_22 -> V_89 . V_26 >> 12 ,
V_57 ) ) ) {
F_21 ( L_42 ) ;
F_55 ( V_60 ) ;
F_24 ( V_22 ) ;
return - V_96 ;
}
if ( F_58 ( V_22 -> V_36 ,
V_22 -> V_89 . V_63 ) ) {
F_21 ( L_43 ) ;
F_55 ( V_60 ) ;
F_24 ( V_22 ) ;
return - V_97 ;
}
if ( V_22 -> V_99 )
V_22 -> V_89 . V_25
= V_22 -> V_36 -> V_25 ;
else
V_22 -> V_89 . V_25 = V_22 -> V_24 . V_25
+ ( V_22 -> V_89 . V_63 << 12 ) ;
V_22 -> V_89 . V_40 = V_22 -> V_24 . V_40
+ ( V_22 -> V_89 . V_63 << 12 ) ;
}
if ( V_22 -> V_34 ) {
if ( ! ( V_22 -> V_35 =
F_57 ( V_60 , V_22 -> V_85 . V_26 >> 12 ,
V_95 ) ) ) {
F_59 ( L_44
L_45 ) ;
V_22 -> V_34 = 0 ;
}
if ( F_58 ( V_22 -> V_35 ,
V_22 -> V_85 . V_63 ) ) {
F_59 ( L_46
L_45 ) ;
V_22 -> V_34 = 0 ;
}
}
if ( ! V_22 -> V_34 )
V_22 -> V_85 . V_63 = 0 ;
V_22 -> V_85 . V_25 = V_22 -> V_24 . V_25
+ ( V_22 -> V_85 . V_63 << 12 ) ;
V_22 -> V_85 . V_40 = V_22 -> V_24 . V_40 + ( V_22 -> V_85 . V_63 << 12 ) ;
V_22 -> V_101 = V_22 -> V_85 . V_63 << 12 ;
F_55 ( V_60 ) ;
if ( V_11 )
F_19 ( V_22 ) ;
F_10 ( L_47 ,
V_22 -> V_85 . V_25 , V_22 -> V_85 . V_63 , V_22 -> V_85 . V_26 ,
V_22 -> V_85 . V_40 ) ;
F_10 ( L_48 ,
V_22 -> V_43 , V_44 ,
V_22 -> V_38 ) ;
F_10 ( L_49 ,
V_22 -> V_86 . V_25 , V_22 -> V_86 . V_26 ,
V_22 -> V_86 . V_40 ) ;
F_10 ( L_50 ,
V_22 -> V_89 . V_25 , V_22 -> V_89 . V_26 ,
V_22 -> V_89 . V_40 , V_22 -> V_89 . V_63 ,
V_22 -> V_89 . V_25 ) ;
F_10 ( L_51
L_52 , V_9 , V_8 , V_10 , V_12 , V_13 ) ;
F_10 ( L_53 , V_14 ? V_14 : L_54 ) ;
if ( V_102 )
F_60 ( V_22 ) ;
V_52 = F_61 ( V_22 ) ;
if ( V_52 ) {
V_22 -> V_71 = 1 ;
F_59 ( L_55 ) ;
V_4 = 0 ;
while ( V_52 ) {
if ( V_52 & 1 ) {
V_58 = F_62 ( 1 << V_4 ) ;
if ( V_58 )
F_63 ( L_56 , V_58 ) ;
}
V_52 >>= 1 ;
++ V_4 ;
}
F_63 ( L_57 ) ;
}
if ( V_103 == 1 )
F_60 ( V_22 ) ;
if ( F_64 ( V_22 ) &&
V_104 . V_105 != V_106 ) {
F_21 ( L_58 ) ;
F_24 ( V_22 ) ;
return - V_19 ;
}
if ( V_103 == 2 )
F_60 ( V_22 ) ;
if ( V_104 . V_105 == V_106 )
F_65 ( V_22 ) ;
if ( V_103 == 3 )
F_60 ( V_22 ) ;
if ( F_64 ( V_22 ) )
F_66 ( V_22 , & V_22 -> V_107 ) ;
if ( V_103 == 4 )
F_60 ( V_22 ) ;
if ( F_67 ( V_22 ) ) {
F_24 ( V_22 ) ;
return - V_19 ;
}
if ( V_103 == 5 )
F_60 ( V_22 ) ;
#ifdef F_31
F_68 ( V_22 ) ;
#endif
if ( V_103 == 6 )
F_60 ( V_22 ) ;
F_69 ( V_47 , V_22 ) ;
V_4 = F_70 ( V_22 , & V_22 -> V_108 ,
V_103 > 6 ? V_103 - 6 : 0 ) ;
if ( V_4 != 0 ) {
F_10 ( L_59 , V_4 ) ;
F_60 ( V_22 ) ;
}
F_71 ( V_22 , & V_22 -> V_108 ) ;
if ( V_103 == 18 )
F_60 ( V_22 ) ;
V_22 -> V_109 = F_72 ( & V_22 -> V_108 ) ;
if ( V_22 -> V_10 ) {
F_73 ( V_22 ) ;
F_74 ( V_22 ) ;
}
if ( V_103 == 19 )
F_60 ( V_22 ) ;
if ( V_22 -> V_8 )
F_75 ( V_22 ) ;
if ( V_103 == 20 )
F_60 ( V_22 ) ;
if ( V_110 )
F_60 ( V_22 ) ;
if ( F_76 ( V_22 -> V_29 ) < 0 ) {
F_21 ( L_60 ) ;
F_24 ( V_22 ) ;
return - V_19 ;
}
V_22 -> V_33 = 1 ;
V_22 -> V_111 = 0 ;
F_77 ( & V_22 -> V_112 . V_113 ) ;
F_78 ( & V_22 -> V_114 ) ;
V_22 -> V_115 = 0 ;
V_22 -> V_112 . V_116 = 0 ;
V_22 -> V_112 . V_117 = 0 ;
return 0 ;
V_70:
F_26 ( & V_29 -> V_30 ) ;
V_66:
F_35 ( V_29 ) ;
return - V_19 ;
}
static void T_5
F_79 ( struct V_46 * V_47 )
{
struct V_21 * V_22 = F_80 ( V_47 ) ;
F_10 ( L_61 ) ;
if ( ! V_22 )
return;
F_24 ( V_22 ) ;
F_69 ( V_47 , NULL ) ;
}
int T_1 F_81 ( const struct V_118 * V_119 )
{
F_10 ( L_62 ,
V_119 -> V_120 , V_119 -> V_121 . V_122 ) ;
switch ( V_119 -> V_120 ) {
case 16 :
return ( V_119 -> V_121 . V_122 == 6 ) ? 16 : 15 ;
case 32 :
return 24 ;
default:
return V_119 -> V_120 ;
}
}
static T_1 int F_82 ( const struct V_118 * V_119 )
{
int V_123 = V_119 -> V_124 + V_119 -> V_125 + V_119 -> V_126 +
V_119 -> V_127 ;
int V_128 = V_119 -> V_129 + V_119 -> V_130 + V_119 -> V_131 +
V_119 -> V_132 ;
return ( 1000000000 / V_119 -> V_133 * 1000 + 500 ) / V_123 / V_128 ;
}
static void T_4 F_65 ( struct V_21 * V_22 )
{
struct V_118 * V_119 ;
int V_123 , V_128 ;
F_10 ( L_63 ) ;
V_22 -> V_134 = 1 ;
V_22 -> V_135 = V_104 . V_136 ;
V_22 -> V_137 = V_104 . V_138 * F_83 ( 64 ) ;
V_22 -> V_139 = V_104 . V_140 ;
V_119 = & V_22 -> V_107 ;
memset ( V_119 , 0 , sizeof( * V_119 ) ) ;
V_119 -> V_124 = V_104 . V_141 ;
V_119 -> V_129 = V_104 . V_142 ;
V_119 -> V_120 = V_104 . V_143 ;
switch ( V_104 . V_143 ) {
case 15 :
V_119 -> V_120 = 16 ;
break;
case 24 :
V_119 -> V_120 = 32 ;
break;
}
F_10 ( L_64 ,
V_22 -> V_135 , V_22 -> V_137 ,
F_49 ( V_22 -> V_137 ) ) ;
F_10 ( L_65 ,
V_119 -> V_124 , V_119 -> V_129 , V_119 -> V_120 ,
V_22 -> V_139 ) ;
V_119 -> V_125 = ( V_119 -> V_124 / 8 ) & 0xf8 ;
V_119 -> V_126 = 32 ;
V_119 -> V_130 = 16 ;
V_119 -> V_131 = 4 ;
V_119 -> V_127 = ( V_119 -> V_124 / 8 ) & 0xf8 ;
V_119 -> V_132 = 4 ;
V_123 = V_119 -> V_124 + V_119 -> V_125 +
V_119 -> V_126 + V_119 -> V_127 ;
V_128 = V_119 -> V_129 + V_119 -> V_130 +
V_119 -> V_131 + V_119 -> V_132 ;
V_119 -> V_133 = 10000000 / V_123 * 1000 / V_128 * 100 / 60 ;
V_119 -> V_144 = - 1 ;
V_119 -> V_145 = - 1 ;
if ( V_119 -> V_120 > 8 ) {
V_119 -> V_146 . V_63 = V_104 . V_147 ;
V_119 -> V_146 . V_122 = V_104 . V_148 ;
V_119 -> V_121 . V_63 = V_104 . V_149 ;
V_119 -> V_121 . V_122 = V_104 . V_150 ;
V_119 -> V_151 . V_63 = V_104 . V_152 ;
V_119 -> V_151 . V_122 = V_104 . V_153 ;
V_119 -> V_154 . V_63 = V_104 . V_155 ;
V_119 -> V_154 . V_122 = V_104 . V_156 ;
} else {
V_119 -> V_146 . V_122 = 8 ;
V_119 -> V_121 . V_122 = 8 ;
V_119 -> V_151 . V_122 = 8 ;
}
}
static int T_4 F_84 ( struct V_21 * V_22 )
{
struct V_118 * V_119 ;
int V_157 = 0 ;
F_10 ( L_66 ) ;
V_119 = & V_22 -> V_29 -> V_119 ;
if ( F_64 ( V_22 ) ) {
memcpy ( V_119 , & V_22 -> V_107 ,
sizeof( struct V_118 ) ) ;
V_157 = 5 ;
} else {
const V_94 * V_158 = F_85 ( & V_22 -> V_47 -> V_65 ) ;
V_94 * V_159 = NULL ;
if ( V_158 ) {
V_159 = F_86 ( V_158 , V_160 , V_6 ) ;
if ( V_159 ) {
F_87 ( V_159 ,
& V_22 -> V_29 -> V_161 ) ;
F_27 ( V_159 ) ;
}
}
if ( V_14 ) {
F_63 ( L_67
L_68 ) ;
V_157 = F_88 ( V_119 , V_22 -> V_29 , V_14 ,
V_22 -> V_29 -> V_161 . V_162 ,
V_22 -> V_29 -> V_161 . V_163 ,
NULL , 0 ) ;
if ( V_157 && V_157 > 1 ) {
F_63 ( L_69
L_70
L_71 ) ;
V_157 = F_88 ( V_119 , V_22 -> V_29 , V_14 ,
NULL , 0 , NULL , 0 ) ;
if ( V_157 )
V_157 |= 8 ;
}
}
if ( ! V_157 )
V_157 = F_88 ( V_119 , V_22 -> V_29 , V_164 ,
NULL , 0 , NULL , 0 ) ;
}
if ( ! V_157 ) {
F_21 ( L_72 ) ;
return 1 ;
}
F_14 ( L_73 , V_119 -> V_124 , V_119 -> V_129 ,
V_119 -> V_120 , F_82 ( V_119 ) ) ;
F_10 ( L_74 , V_157 ) ;
#if V_165
V_119 -> V_166 = V_119 -> V_124 ;
V_119 -> V_167 =
V_22 -> V_85 . V_26 / 2 / ( V_119 -> V_120 * V_119 -> V_124 ) ;
if ( V_119 -> V_167 < V_119 -> V_129 )
V_119 -> V_167 = V_119 -> V_129 ;
#else
V_119 -> V_167 = V_119 -> V_129 ;
#endif
if ( V_22 -> V_8 )
V_119 -> V_168 |= V_169 ;
else
V_119 -> V_168 &= ~ V_169 ;
return 0 ;
}
static int T_4 F_67 ( struct V_21 * V_22 )
{
struct V_50 * V_29 = V_22 -> V_29 ;
F_10 ( L_75 ) ;
V_29 -> V_170 = V_171 ;
V_29 -> V_68 = & V_69 ;
V_29 -> V_172 = V_22 -> V_172 ;
V_29 -> V_31 . V_26 = 64 * 1024 ;
V_29 -> V_31 . V_173 = 8 ;
V_29 -> V_31 . V_174 = 32 ;
V_29 -> V_31 . V_170 = V_175 ;
if ( F_84 ( V_22 ) )
return 1 ;
V_29 -> V_31 . V_176 = 1 ;
strcpy ( V_29 -> V_177 . V_178 , V_22 -> V_2 ) ;
V_29 -> V_177 . V_179 = V_22 -> V_85 . V_25 ;
V_29 -> V_177 . V_180 = V_22 -> V_85 . V_26 ;
V_29 -> V_177 . type = V_181 ;
V_29 -> V_177 . V_182 = 0 ;
V_29 -> V_177 . V_183 = 8 ;
V_29 -> V_177 . V_184 = 1 ;
V_29 -> V_177 . V_185 = 0 ;
V_29 -> V_177 . V_186 = V_22 -> V_43 ;
V_29 -> V_177 . V_187 = V_44 ;
V_29 -> V_177 . V_8 = V_188 ;
F_66 ( V_22 , & V_29 -> V_119 ) ;
return 0 ;
}
static void F_66 ( struct V_21 * V_22 ,
struct V_118 * V_119 )
{
F_10 ( L_76 ) ;
V_22 -> V_189 = V_119 -> V_120 ;
V_22 -> V_190 = F_81 ( V_119 ) ;
V_22 -> V_124 = V_119 -> V_124 ;
V_22 -> V_129 = V_119 -> V_124 ;
V_22 -> V_133 = V_119 -> V_133 ;
V_22 -> V_29 -> V_177 . V_191 = V_22 -> V_191 ;
V_22 -> V_29 -> V_177 . V_192 = V_22 -> V_193 ;
switch ( V_22 -> V_189 ) {
case 8 :
V_22 -> V_191 = V_194 ;
V_22 -> V_193 = V_119 -> V_166 ;
break;
case 16 :
V_22 -> V_191 = V_195 ;
V_22 -> V_193 = V_119 -> V_166 * 2 ;
break;
case 32 :
V_22 -> V_191 = V_195 ;
V_22 -> V_193 = V_119 -> V_166 * 4 ;
break;
}
if ( F_89 ( V_22 ) )
V_22 -> V_193 = F_90 ( V_22 -> V_193 , V_196 ) ;
else
V_22 -> V_193 = F_90 ( V_22 -> V_193 , V_197 ) ;
if ( F_64 ( V_22 ) )
V_22 -> V_193 = V_22 -> V_139 ;
V_22 -> V_29 -> V_198 = ( char V_39 * ) V_22 -> V_85 . V_40 ;
V_22 -> V_29 -> V_177 . V_192 = V_22 -> V_193 ;
V_22 -> V_29 -> V_177 . V_191 = V_22 -> V_191 ;
}
static int F_91 ( struct V_50 * V_29 , int V_199 )
{
struct V_21 * V_22 = F_92 ( V_29 ) ;
if ( V_199 )
V_22 -> V_111 ++ ;
return 0 ;
}
static int F_93 ( struct V_50 * V_29 , int V_199 )
{
struct V_21 * V_22 = F_92 ( V_29 ) ;
if ( V_199 ) {
V_22 -> V_111 -- ;
F_94 ( 1 ) ;
if ( ! V_22 -> V_111 )
F_25 ( V_22 ) ;
}
return 0 ;
}
static int F_95 ( struct V_118 * V_119 ,
struct V_50 * V_29 )
{
int V_200 = 0 ;
struct V_118 V_201 ;
struct V_21 * V_22 ;
static int V_202 = 1 ;
int V_4 ;
static const int V_203 [] = {
128 * 8 ,
128 * 16 ,
128 * 32 ,
128 * 64 ,
0
} ;
F_10 ( L_77 , V_119 -> V_168 ) ;
V_22 = F_92 ( V_29 ) ;
if ( F_96 ( V_22 , V_119 ) != 0 )
return - V_204 ;
V_201 = * V_119 ;
for ( V_4 = 0 ; V_203 [ V_4 ] != 0 ; V_4 ++ ) {
if ( V_203 [ V_4 ] >= V_201 . V_166 ) {
V_201 . V_166 = V_203 [ V_4 ] ;
break;
}
}
if ( V_201 . V_120 <= 8 )
V_201 . V_120 = 8 ;
else if ( V_201 . V_120 <= 16 ) {
if ( V_201 . V_120 == 16 )
V_201 . V_121 . V_122 = 6 ;
V_201 . V_120 = 16 ;
} else if ( V_201 . V_120 <= 32 )
V_201 . V_120 = 32 ;
else
return - V_204 ;
V_200 = ( ( V_29 -> V_119 . V_124 != V_119 -> V_124 ) ||
( V_29 -> V_119 . V_129 != V_119 -> V_129 ) ||
( V_29 -> V_119 . V_166 != V_119 -> V_166 ) ||
( V_29 -> V_119 . V_167 != V_119 -> V_167 ) ||
( V_29 -> V_119 . V_120 != V_119 -> V_120 ) ||
memcmp ( & V_29 -> V_119 . V_146 , & V_119 -> V_146 , sizeof( V_119 -> V_146 ) ) ||
memcmp ( & V_29 -> V_119 . V_121 , & V_119 -> V_121 ,
sizeof( V_119 -> V_121 ) ) ||
memcmp ( & V_29 -> V_119 . V_151 , & V_119 -> V_151 , sizeof( V_119 -> V_151 ) ) ) ;
if ( F_64 ( V_22 ) &&
( V_200 ||
V_119 -> V_167 > V_22 -> V_107 . V_167 ||
V_119 -> V_167 < V_22 -> V_107 . V_129 ||
V_119 -> V_205 || V_119 -> V_206 ) ) {
if ( V_202 ) {
F_21 ( L_78 ) ;
V_202 = 0 ;
}
return - V_204 ;
}
switch ( F_81 ( & V_201 ) ) {
case 8 :
V_201 . V_146 . V_63 = V_201 . V_121 . V_63 = V_201 . V_151 . V_63 = 0 ;
V_201 . V_146 . V_122 = V_201 . V_121 . V_122 = V_201 . V_151 . V_122 = 8 ;
V_201 . V_154 . V_63 = V_201 . V_154 . V_122 = 0 ;
break;
case 15 :
V_201 . V_146 . V_63 = 10 ;
V_201 . V_121 . V_63 = 5 ;
V_201 . V_151 . V_63 = 0 ;
V_201 . V_146 . V_122 = V_201 . V_121 . V_122 = V_201 . V_151 . V_122 = 5 ;
V_201 . V_154 . V_63 = V_201 . V_154 . V_122 = 0 ;
break;
case 16 :
V_201 . V_146 . V_63 = 11 ;
V_201 . V_121 . V_63 = 5 ;
V_201 . V_151 . V_63 = 0 ;
V_201 . V_146 . V_122 = 5 ;
V_201 . V_121 . V_122 = 6 ;
V_201 . V_151 . V_122 = 5 ;
V_201 . V_154 . V_63 = V_201 . V_154 . V_122 = 0 ;
break;
case 24 :
V_201 . V_146 . V_63 = 16 ;
V_201 . V_121 . V_63 = 8 ;
V_201 . V_151 . V_63 = 0 ;
V_201 . V_146 . V_122 = V_201 . V_121 . V_122 = V_201 . V_151 . V_122 = 8 ;
V_201 . V_154 . V_63 = V_201 . V_154 . V_122 = 0 ;
break;
case 32 :
V_201 . V_146 . V_63 = 16 ;
V_201 . V_121 . V_63 = 8 ;
V_201 . V_151 . V_63 = 0 ;
V_201 . V_146 . V_122 = V_201 . V_121 . V_122 = V_201 . V_151 . V_122 = 8 ;
V_201 . V_154 . V_63 = 24 ;
V_201 . V_154 . V_122 = 8 ;
break;
}
if ( V_201 . V_205 < 0 )
V_201 . V_205 = 0 ;
if ( V_201 . V_207 < 0 )
V_201 . V_207 = 0 ;
if ( V_201 . V_205 > V_201 . V_166 - V_201 . V_124 )
V_201 . V_205 = V_201 . V_166 - V_201 . V_124 ;
if ( V_201 . V_207 > V_201 . V_167 - V_201 . V_129 )
V_201 . V_207 = V_201 . V_167 - V_201 . V_129 ;
V_201 . V_146 . V_208 = V_201 . V_121 . V_208 = V_201 . V_151 . V_208 =
V_201 . V_154 . V_208 = 0 ;
* V_119 = V_201 ;
return 0 ;
}
static int F_97 ( struct V_50 * V_29 )
{
struct V_209 * V_210 ;
struct V_21 * V_22 = F_92 ( V_29 ) ;
if ( F_64 ( V_22 ) ) {
F_21 ( L_78 ) ;
return - V_204 ;
}
V_210 = F_3 ( sizeof( * V_210 ) , V_211 ) ;
if ( ! V_210 )
return - V_96 ;
F_10 ( L_79 , V_29 -> V_119 . V_124 ,
V_29 -> V_119 . V_129 , V_29 -> V_119 . V_120 ) ;
F_98 ( V_212 , F_99 ( V_212 ) & ~ V_213 ) ;
F_100 ( V_214 , V_29 ) ;
if ( F_101 ( V_22 , V_29 ) )
F_102 ( V_22 ) ;
memcpy ( V_210 , & V_22 -> V_108 , sizeof( * V_210 ) ) ;
if ( F_103 ( V_22 , V_210 , & V_29 -> V_119 ) )
goto V_215;
if ( F_104 ( V_22 , V_210 , 0 ) )
goto V_215;
#if V_216 > 0
F_70 ( V_22 , V_210 , 0 ) ;
F_71 ( V_22 , V_210 ) ;
#endif
F_66 ( V_22 , & V_29 -> V_119 ) ;
if ( F_101 ( V_22 , V_29 ) )
F_75 ( V_22 ) ;
F_105 ( & V_29 -> V_119 , V_29 ) ;
F_100 ( V_217 , V_29 ) ;
if ( F_101 ( V_22 , V_29 ) ) {
V_29 -> V_170 = V_218 | V_219 |
V_220 | V_221 |
V_222 ;
} else
V_29 -> V_170 = V_218 | V_219 ;
F_27 ( V_210 ) ;
return 0 ;
V_215:
F_27 ( V_210 ) ;
return - V_204 ;
}
static int F_106 ( unsigned V_223 , unsigned V_146 , unsigned V_121 ,
unsigned V_151 , unsigned V_154 ,
struct V_50 * V_29 )
{
struct V_21 * V_22 = F_92 ( V_29 ) ;
#if V_224 > 0
F_10 ( L_80 , V_223 , V_22 -> V_190 ) ;
#endif
if ( V_223 > 255 )
return 1 ;
if ( V_22 -> V_190 == 8 ) {
V_146 >>= 8 ;
V_121 >>= 8 ;
V_151 >>= 8 ;
F_107 ( V_22 , V_223 , V_146 , V_121 , V_151 ,
V_154 ) ;
}
if ( V_223 < 16 ) {
switch ( V_22 -> V_190 ) {
case 15 :
V_22 -> V_172 [ V_223 ] = ( ( V_146 & 0xf800 ) >> 1 ) |
( ( V_121 & 0xf800 ) >> 6 ) |
( ( V_151 & 0xf800 ) >> 11 ) ;
break;
case 16 :
V_22 -> V_172 [ V_223 ] = ( V_146 & 0xf800 ) |
( ( V_121 & 0xfc00 ) >> 5 ) |
( ( V_151 & 0xf800 ) >> 11 ) ;
break;
case 24 :
V_22 -> V_172 [ V_223 ] = ( ( V_146 & 0xff00 ) << 8 ) |
( V_121 & 0xff00 ) |
( ( V_151 & 0xff00 ) >> 8 ) ;
break;
}
}
return 0 ;
}
static int F_100 ( int V_225 , struct V_50 * V_29 )
{
F_108 ( V_225 , V_29 ) ;
return 0 ;
}
static int F_105 ( struct V_118 * V_119 ,
struct V_50 * V_29 )
{
F_109 ( V_119 , V_29 ) ;
return 0 ;
}
static int F_110 ( struct V_50 * V_29 , unsigned int V_226 ,
unsigned long V_227 )
{
int V_228 = 0 ;
struct V_21 * V_22 = F_92 ( V_29 ) ;
T_6 V_109 = 0 ;
switch ( V_226 ) {
case V_229 :
if ( F_111 ( V_109 , ( V_230 V_231 * ) V_227 ) )
return - V_232 ;
V_228 = F_112 ( V_22 , V_109 ) ;
break;
default:
break;
}
return V_228 ;
}
static void F_113 ( struct V_50 * V_29 ,
const struct V_233 * V_234 )
{
struct V_21 * V_22 = F_92 ( V_29 ) ;
T_6 V_235 , V_236 ;
#if V_224 > 0
F_10 ( L_81 ) ;
#endif
if ( ! F_101 ( V_22 , V_29 ) || V_22 -> V_190 == 4 ) {
F_114 ( V_29 , V_234 ) ;
return;
}
if ( V_234 -> V_235 == V_237 )
V_235 = V_238 ;
else
V_235 = V_239 ;
if ( V_22 -> V_190 != 8 )
V_236 = V_22 -> V_172 [ V_234 -> V_236 ] ;
else
V_236 = V_234 -> V_236 ;
F_115 ( V_22 , V_234 -> V_240 , V_234 -> V_241 ,
V_234 -> V_145 , V_234 -> V_144 , V_236 ,
V_22 -> V_193 , V_29 -> V_119 . V_120 ,
V_235 ) ;
}
static void F_116 ( struct V_50 * V_29 ,
const struct V_242 * V_243 )
{
struct V_21 * V_22 = F_92 ( V_29 ) ;
#if V_224 > 0
F_10 ( L_82 ) ;
#endif
if ( ! F_101 ( V_22 , V_29 ) || V_22 -> V_190 == 4 ) {
F_117 ( V_29 , V_243 ) ;
return;
}
F_118 ( V_22 , V_243 -> V_244 , V_243 -> V_245 , V_243 -> V_240 ,
V_243 -> V_241 , V_243 -> V_145 , V_243 -> V_144 ,
V_22 -> V_193 , V_29 -> V_119 . V_120 ) ;
}
static void F_119 ( struct V_50 * V_29 ,
const struct V_246 * V_247 )
{
struct V_21 * V_22 = F_92 ( V_29 ) ;
T_6 V_248 , V_249 ;
#if V_224 > 0
F_10 ( L_83 ) ;
#endif
if ( ! F_101 ( V_22 , V_29 ) || V_22 -> V_190 == 4
|| V_247 -> V_190 != 1 ) {
F_120 ( V_29 , V_247 ) ;
return;
}
if ( V_22 -> V_190 != 8 ) {
V_248 = V_22 -> V_172 [ V_247 -> V_250 ] ;
V_249 = V_22 -> V_172 [ V_247 -> V_251 ] ;
} else {
V_248 = V_247 -> V_250 ;
V_249 = V_247 -> V_251 ;
}
if ( ! F_121 ( V_22 , V_248 , V_249 , V_247 -> V_145 ,
V_247 -> V_144 , V_247 -> V_252 ,
V_247 -> V_240 , V_247 -> V_241 ,
V_22 -> V_193 , V_29 -> V_119 . V_120 ) ) {
F_120 ( V_29 , V_247 ) ;
return;
}
}
static int F_122 ( struct V_50 * V_29 , struct V_253 * V_89 )
{
struct V_21 * V_22 = F_92 ( V_29 ) ;
T_6 V_25 ;
#if V_224 > 0
F_10 ( L_84 ) ;
#endif
if ( ! V_22 -> V_10 )
return - V_19 ;
F_123 ( V_22 ) ;
V_25 = ( V_22 -> V_99 || F_89 ( V_22 ) ) ? V_22 -> V_89 . V_25 :
( V_22 -> V_89 . V_63 << 12 ) ;
if ( F_99 ( V_254 ) != V_25 ) {
T_6 V_255 , V_256 ;
F_10 ( L_85 ) ;
F_10 ( L_86 ,
V_89 -> V_247 . V_145 , V_89 -> V_247 . V_144 ,
V_89 -> V_247 . V_240 , V_89 -> V_247 . V_241 ) ;
F_73 ( V_22 ) ;
F_74 ( V_22 ) ;
F_124 ( V_22 , V_89 -> V_247 . V_240 ,
V_89 -> V_247 . V_241 ) ;
if ( V_22 -> V_190 != 8 ) {
V_255 = V_22 -> V_172 [ V_89 -> V_247 . V_250 ] ;
V_256 = V_22 -> V_172 [ V_89 -> V_247 . V_251 ] ;
} else {
V_255 = V_89 -> V_247 . V_250 ;
V_256 = V_89 -> V_247 . V_251 ;
}
F_125 ( V_22 , V_256 , V_255 ) ;
F_126 ( V_22 , V_89 -> V_247 . V_145 ,
V_89 -> V_247 . V_144 ,
V_22 -> V_257 ) ;
if ( V_89 -> V_258 )
F_127 ( V_22 ) ;
return 0 ;
}
if ( V_89 -> V_259 & V_260 ) {
T_6 V_240 , V_241 ;
V_240 = V_89 -> V_247 . V_240 - V_29 -> V_119 . V_205 ;
V_241 = V_89 -> V_247 . V_241 - V_29 -> V_119 . V_207 ;
F_124 ( V_22 , V_240 , V_241 ) ;
}
if ( V_89 -> V_259 & V_261 ) {
if ( V_89 -> V_247 . V_145 > 64 || V_89 -> V_247 . V_144 > 64 )
return - V_262 ;
F_74 ( V_22 ) ;
}
if ( V_89 -> V_259 & V_263 ) {
T_6 V_255 , V_256 ;
if ( V_22 -> V_190 != 8 ) {
V_255 = V_22 -> V_172 [ V_89 -> V_247 . V_250 ] ;
V_256 = V_22 -> V_172 [ V_89 -> V_247 . V_251 ] ;
} else {
V_255 = V_89 -> V_247 . V_250 ;
V_256 = V_89 -> V_247 . V_251 ;
}
F_125 ( V_22 , V_256 , V_255 ) ;
}
if ( V_89 -> V_259 & ( V_264 | V_265 ) ) {
T_6 V_266 = ( F_90 ( V_89 -> V_247 . V_145 , 8 ) / 8 ) ;
T_6 V_26 = V_266 * V_89 -> V_247 . V_144 ;
V_94 * V_267 = ( V_94 * ) V_89 -> V_247 . V_252 ;
V_94 * V_268 = ( V_94 * ) V_89 -> V_269 ;
V_94 V_270 [ 64 ] ;
T_6 V_4 ;
if ( V_89 -> V_247 . V_190 != 1 )
return - V_262 ;
switch ( V_89 -> V_235 ) {
case V_271 :
for ( V_4 = 0 ; V_4 < V_26 ; V_4 ++ )
V_270 [ V_4 ] = V_267 [ V_4 ] ^ V_268 [ V_4 ] ;
break;
case V_237 :
default:
for ( V_4 = 0 ; V_4 < V_26 ; V_4 ++ )
V_270 [ V_4 ] = V_267 [ V_4 ] & V_268 [ V_4 ] ;
break;
}
memcpy ( V_22 -> V_257 , V_270 , V_26 ) ;
F_126 ( V_22 , V_89 -> V_247 . V_145 ,
V_89 -> V_247 . V_144 , V_270 ) ;
}
if ( V_89 -> V_258 )
F_127 ( V_22 ) ;
return 0 ;
}
static int F_128 ( struct V_50 * V_29 )
{
struct V_21 * V_22 = F_92 ( V_29 ) ;
#if V_224 > 0
F_10 ( L_87 ) ;
#endif
if ( V_22 -> V_272 )
return 0 ;
F_129 ( V_22 ) ;
return 0 ;
}
