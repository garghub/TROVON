static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 ) -> V_4 ;
}
static inline struct V_2 * F_3 ( struct V_1 * V_5 )
{
return V_5 -> V_3 ;
}
static void F_4 ( T_1 V_6 , T_1 V_7 , struct V_1 * V_8 ,
struct V_2 * V_3 , int V_9 )
{
T_1 V_10 ;
V_10 = V_8 -> V_11 [ V_9 >> 2 ] ;
V_10 &= ~ V_6 ;
V_10 |= V_7 ;
V_8 -> V_11 [ V_9 >> 2 ] = V_10 ;
F_5 ( V_10 , V_8 -> V_12 + F_6 ( V_8 ) + V_9 ) ;
}
static void F_7 ( T_1 V_13 , struct V_1 * V_8 ,
struct V_2 * V_3 , int V_9 )
{
V_8 -> V_11 [ V_9 >> 2 ] = V_13 ;
F_5 ( V_13 , V_8 -> V_12 + F_6 ( V_8 ) + V_9 ) ;
}
static inline T_1 F_8 ( struct V_1 * V_8 , int V_9 )
{
return V_8 -> V_11 [ V_9 >> 2 ] ;
}
static T_1 F_9 ( struct V_1 * V_8 , struct V_2 * V_3 )
{
F_10 ( V_8 -> V_12 + F_6 ( V_8 ) + V_14 ) ;
return F_10 ( V_8 -> V_12 + F_6 ( V_8 ) + V_14 ) ;
}
static inline void F_11 ( struct V_1 * V_8 ,
struct V_2 * V_3 )
{
V_8 -> V_15 = V_8 -> V_16 +
( ( V_8 -> V_17 - 1 ) % V_18 ) * sizeof( struct V_19 ) ;
F_5 ( V_8 -> V_15 , V_8 -> V_12 + V_20 + V_8 -> V_21 * 4 ) ;
F_10 ( V_8 -> V_12 + V_20 + V_8 -> V_21 * 4 ) ;
}
static inline void F_12 ( struct V_1 * V_8 ,
struct V_2 * V_3 )
{
V_8 -> V_22 = V_8 -> V_23 +
( ( V_8 -> V_24 - 1 ) % V_25 ) * sizeof( struct V_26 ) ;
F_5 ( V_8 -> V_22 , V_8 -> V_12 + V_27 + V_8 -> V_21 * 4 ) ;
}
static inline unsigned int F_13 ( struct V_1 * V_8 )
{
return V_8 -> V_17 == V_8 -> V_28 ;
}
static inline unsigned int F_14 ( struct V_1 * V_8 ,
struct V_2 * V_3 )
{
return F_10 ( V_8 -> V_12 + V_29 + V_8 -> V_21 * 4 ) == V_8 -> V_15 ;
}
static int F_15 ( T_1 V_10 , struct V_1 * V_8 ,
struct V_2 * V_3 , const char * V_30 )
{
int V_31 = 0 ;
if ( V_32 > 1 ) {
if ( F_16 ( V_10 ) != V_8 -> V_21 ) {
F_17 ( V_33 L_1 ,
V_3 -> V_34 , V_30 , F_16 ( V_10 ) , V_10 ) ;
V_31 = - 1 ;
}
if ( V_10 & 0x0df80c00 ) {
F_17 ( V_33 L_2 ,
V_3 -> V_34 , V_30 , V_10 ) ;
V_31 = - 1 ;
}
}
return V_31 ;
}
static void F_18 ( struct V_2 * V_3 ,
struct V_1 * V_8 ,
char * V_30 )
{
F_17 ( V_33 L_3 ,
V_3 -> V_34 , V_8 -> V_17 , V_8 -> V_28 , V_30 ) ;
}
static void F_19 ( struct V_1 * V_8 )
{
struct V_35 * V_36 = V_8 -> V_37 -> V_36 ;
struct V_19 * V_38 = V_8 -> V_38 ;
struct V_26 * V_39 = V_8 -> V_39 ;
struct V_40 * * V_41 ;
int V_42 ;
F_20 ( V_36 , V_43 , V_38 , V_8 -> V_16 ) ;
F_20 ( V_36 , V_44 , V_39 , V_8 -> V_23 ) ;
V_41 = V_8 -> V_45 ;
for ( V_42 = 0 ; V_42 < V_18 ; V_42 ++ ) {
if ( * V_41 ) {
F_21 ( V_36 , F_22 ( V_38 -> V_46 ) ,
( * V_41 ) -> V_47 , V_48 ) ;
F_23 ( * V_41 ) ;
}
V_41 ++ ;
V_38 ++ ;
}
V_41 = V_8 -> V_49 ;
for ( V_42 = 0 ; V_42 < V_25 ; V_42 ++ ) {
if ( * V_41 ) {
F_21 ( V_36 , F_22 ( V_39 -> V_46 ) ,
F_24 ( V_50 ) , V_51 ) ;
F_23 ( * V_41 ) ;
}
V_41 ++ ;
V_39 ++ ;
}
}
static inline int F_25 ( struct V_1 * V_8 ,
struct V_2 * V_3 )
{
unsigned int V_52 = V_8 -> V_24 % V_25 ;
struct V_26 * V_39 = V_8 -> V_39 + V_52 ;
const int V_47 = F_24 ( V_50 ) ;
struct V_40 * V_53 ;
int V_31 = 0 ;
V_53 = F_26 ( V_47 ) ;
V_8 -> V_49 [ V_52 ] = V_53 ;
if ( V_53 ) {
V_53 -> V_54 = F_27 ( V_53 , V_3 ) ;
V_39 -> V_46 = F_28 ( F_29 ( V_8 -> V_37 -> V_36 ,
V_53 -> V_46 , V_47 , V_51 ) ) ;
} else {
V_39 -> V_46 = 0 ;
V_31 = - 1 ;
}
return V_31 ;
}
static int F_30 ( struct V_1 * V_8 ,
struct V_2 * V_3 , char * V_30 )
{
T_2 V_42 = 0 ;
do {
if ( ! ( F_9 ( V_8 , V_3 ) & V_55 ) ) {
F_17 ( V_33 L_4 , V_3 -> V_34 ,
V_30 , V_42 ) ;
goto V_56;
}
F_31 ( 10 ) ;
F_32 () ;
} while ( ++ V_42 > 0 );
F_17 ( V_57 L_5 , V_3 -> V_34 , V_30 ) ;
V_56:
return ( V_42 >= 0 ) ? V_42 : - V_58 ;
}
static int F_33 ( struct V_2 * V_3 , char * V_30 )
{
void T_3 * V_59 = F_1 ( V_3 ) -> V_12 ;
T_4 V_42 = 0 ;
F_5 ( V_60 , V_59 + V_61 ) ;
V_59 += V_62 ;
do {
T_1 V_10 = F_10 ( V_59 ) ;
if ( V_10 & V_63 ) {
F_17 ( V_33 L_6 , V_3 -> V_34 , V_30 ) ;
F_5 ( V_63 , V_59 ) ;
goto V_56;
} else if ( V_10 & V_64 ) {
F_17 ( V_57 L_7 , V_3 -> V_34 , V_30 ) ;
F_5 ( V_64 , V_59 ) ;
V_42 = - 1 ;
goto V_56;
}
F_32 () ;
} while ( ++ V_42 > 0 );
F_17 ( V_57 L_5 , V_3 -> V_34 , V_30 ) ;
V_56:
return V_42 ;
}
static inline int F_34 ( struct V_1 * V_8 )
{
int V_65 = V_8 -> V_66 % V_67 ;
T_2 V_42 = 0 ;
do {
if ( ! ( V_8 -> V_68 & ( V_69 | V_70 ) ) ||
( V_8 -> V_71 [ V_65 ] & F_28 ( V_72 ) ) )
break;
F_35 () ;
F_31 ( 10 ) ;
} while ( ++ V_42 > 0 );
return ( V_42 >= 0 ) ? V_42 : - V_58 ;
}
static inline void F_36 ( struct V_1 * V_8 ,
struct V_2 * V_3 )
{
struct V_26 * V_39 = V_8 -> V_39 + V_8 -> V_73 % V_25 ;
struct V_35 * V_36 = V_8 -> V_37 -> V_36 ;
struct V_40 * V_53 ;
int V_74 ;
V_53 = V_8 -> V_49 [ V_8 -> V_73 ++ % V_25 ] ;
if ( ! V_53 ) {
F_17 ( V_33 L_8 , V_3 -> V_34 , V_75 ) ;
goto V_76;
}
V_74 = F_37 ( F_22 ( V_39 -> V_77 ) ) ;
F_21 ( V_36 , F_22 ( V_39 -> V_46 ) ,
F_24 ( V_50 ) , V_51 ) ;
if ( ( V_53 -> V_46 [ -- V_74 ] & V_78 ) == V_78 ) {
V_3 -> V_79 . V_80 ++ ;
V_3 -> V_79 . V_81 += V_74 ;
F_38 ( V_53 , V_74 ) ;
if ( F_39 ( V_3 ) )
V_53 -> V_54 = F_27 ( V_53 , V_3 ) ;
F_40 ( V_53 ) ;
} else {
if ( V_53 -> V_46 [ V_74 ] & V_82 )
V_3 -> V_79 . V_83 ++ ;
else if ( ! ( V_53 -> V_46 [ V_74 ] & V_84 ) )
V_3 -> V_79 . V_85 ++ ;
else if ( ( V_53 -> V_46 [ V_74 ] & ( V_86 | V_87 ) ) !=
( V_86 | V_87 ) )
V_3 -> V_79 . V_88 ++ ;
V_3 -> V_79 . V_89 ++ ;
F_41 ( V_53 ) ;
}
V_76:
while ( ( V_8 -> V_24 - V_8 -> V_73 ) % V_25 ) {
if ( F_25 ( V_8 , V_3 ) < 0 )
break;
V_8 -> V_24 ++ ;
}
F_12 ( V_8 , V_3 ) ;
V_39 -> V_77 = 0x00000000 ;
V_39 -> V_90 = F_28 ( 0xbabeface ) ;
}
static void F_42 ( struct V_35 * V_36 )
{
struct V_91 * V_92 ;
struct V_1 * V_93 ;
int V_42 ;
V_92 = F_43 ( V_36 ) ;
V_93 = V_92 -> V_93 ;
for ( V_42 = 0 ; V_42 < V_94 ; V_42 ++ )
F_44 ( F_3 ( V_93 + V_42 ) ) ;
F_45 ( V_36 , NULL ) ;
for ( V_42 = 0 ; V_42 < V_94 ; V_42 ++ )
F_46 ( V_93 [ V_42 ] . V_3 ) ;
F_47 ( V_93 ) ;
F_47 ( V_92 ) ;
}
static int T_5 F_48 ( struct V_35 * V_36 ,
const struct V_95 * V_96 )
{
struct V_91 * V_4 ;
struct V_1 * V_8 ;
void T_3 * V_59 ;
int V_42 , V_97 ;
F_17 ( V_33 L_9 , V_98 ) ;
V_97 = F_49 ( V_36 ) ;
if ( V_97 < 0 )
goto V_99;
V_97 = F_50 ( V_36 , 0 , L_10 ) ;
if ( V_97 < 0 ) {
F_17 ( V_57 L_11 ,
V_100 ) ;
goto V_101;
}
V_97 = F_50 ( V_36 , 1 , L_12 ) ;
if ( V_97 < 0 ) {
F_17 ( V_57 L_13 ,
V_100 ) ;
goto V_102;
}
V_59 = F_51 ( V_36 , 0 ) ;
if ( ! V_59 ) {
F_17 ( V_57 L_14 ,
V_100 , ( unsigned long long ) F_52 ( V_36 , 0 ) ,
( unsigned long long ) F_53 ( V_36 , 0 ) ) ;
V_97 = - V_103 ;
goto V_104;
}
F_17 ( V_33 L_15 ,
( unsigned long long ) F_53 ( V_36 , 0 ) ,
( unsigned long long ) F_53 ( V_36 , 1 ) , V_36 -> V_105 ) ;
F_54 ( V_36 , V_106 , 0xf8 ) ;
F_55 ( V_36 ) ;
V_97 = F_56 ( V_36 , V_59 ) ;
if ( V_97 < 0 )
goto V_107;
V_4 = F_43 ( V_36 ) ;
V_97 = F_57 ( V_36 -> V_105 , V_108 , V_109 , V_100 , V_4 -> V_93 ) ;
if ( V_97 < 0 ) {
F_17 ( V_110 L_16 , V_100 , V_36 -> V_105 ) ;
goto V_111;
}
F_5 ( 0x00000001 , V_59 + V_112 ) ;
{
T_1 V_13 ;
V_13 = ( V_67 >> 5 ) - 1 ;
V_13 |= V_13 << 4 ;
V_13 |= V_13 << 8 ;
V_13 |= V_13 << 16 ;
F_5 ( V_13 , V_59 + V_113 ) ;
}
F_5 ( ( T_1 ) ( ( ( V_67 >> 5 ) - 1 ) << 20 ) , V_59 + V_114 ) ;
V_4 -> V_115 = ( V_116 * ) F_58 ( V_36 ,
V_67 * sizeof( V_116 ) , & V_4 -> V_117 ) ;
if ( ! V_4 -> V_115 )
goto V_118;
F_5 ( V_4 -> V_117 , V_59 + V_119 ) ;
V_97 = - V_120 ;
for ( V_42 = 0 ; V_42 < V_94 ; V_42 ++ ) {
V_8 = V_4 -> V_93 + V_42 ;
V_8 -> V_71 = ( V_116 * ) F_58 ( V_36 ,
V_67 * sizeof( T_1 ) , & V_8 -> V_121 ) ;
if ( ! V_8 -> V_71 )
goto V_122;
F_5 ( V_8 -> V_121 , V_59 + V_123 + V_42 * 4 ) ;
}
for ( V_42 = 0 ; V_42 < V_94 ; V_42 ++ ) {
V_8 = V_4 -> V_93 + V_42 ;
V_8 -> V_124 = ( V_116 * ) F_58 ( V_36 ,
V_67 * sizeof( T_1 ) , & V_8 -> V_125 ) ;
if ( ! V_8 -> V_124 )
goto V_126;
F_5 ( V_8 -> V_125 , V_59 + V_127 + V_42 * 4 ) ;
}
F_5 ( 0x42104000 , V_59 + V_128 ) ;
F_5 ( 0xdef6d800 , V_59 + V_129 ) ;
F_5 ( 0x18181818 , V_59 + V_130 ) ;
F_5 ( 0x0000000e , V_59 + V_131 ) ;
F_5 ( 0xff200001 , V_59 + V_61 ) ;
V_97 = 0 ;
V_99:
return V_97 ;
V_126:
while ( -- V_42 >= 0 ) {
V_8 = V_4 -> V_93 + V_42 ;
F_20 ( V_36 , V_67 * sizeof( T_1 ) ,
V_8 -> V_124 , V_8 -> V_125 ) ;
}
V_42 = V_94 ;
V_122:
while ( -- V_42 >= 0 ) {
V_8 = V_4 -> V_93 + V_42 ;
F_20 ( V_36 , V_67 * sizeof( T_1 ) ,
V_8 -> V_71 , V_8 -> V_121 ) ;
}
F_20 ( V_36 , V_67 * sizeof( T_1 ) , V_4 -> V_115 ,
V_4 -> V_117 ) ;
V_118:
F_59 ( V_36 -> V_105 , V_4 -> V_93 ) ;
V_111:
F_42 ( V_36 ) ;
V_107:
F_60 ( V_59 ) ;
V_104:
F_61 ( V_36 , 1 ) ;
V_102:
F_61 ( V_36 , 0 ) ;
V_101:
F_62 ( V_36 ) ;
goto V_99;
}
static void F_63 ( struct V_1 * V_8 ,
struct V_2 * V_3 )
{
F_7 ( 0x00000000 , V_8 , V_3 , V_132 ) ;
F_7 ( V_133 | ( V_50 >> 5 ) , V_8 , V_3 , V_134 ) ;
F_7 ( 0x02408000 , V_8 , V_3 , V_135 ) ;
F_7 ( 0x00050008 & ~ V_136 , V_8 , V_3 , V_137 ) ;
}
static inline int F_64 ( struct V_1 * V_8 , int V_138 )
{
int V_31 = 0 ;
if ( ( V_138 < 0 ) || ( V_138 > V_139 ) )
V_31 = - V_140 ;
else
V_8 -> V_37 -> V_141 = V_138 ;
return V_31 ;
}
static int F_56 ( struct V_35 * V_36 , void T_3 * V_59 )
{
struct V_91 * V_92 ;
struct V_1 * V_93 ;
int V_42 , V_31 = - V_120 ;
V_93 = F_65 ( V_94 , sizeof( * V_93 ) , V_142 ) ;
if ( ! V_93 ) {
F_17 ( V_57 L_17 , V_100 ) ;
goto V_143;
}
for ( V_42 = 0 ; V_42 < V_94 ; V_42 ++ ) {
V_93 [ V_42 ] . V_3 = F_66 ( V_93 + V_42 ) ;
if ( ! V_93 [ V_42 ] . V_3 )
goto V_144;
}
V_92 = F_67 ( sizeof( * V_92 ) , V_142 ) ;
if ( ! V_92 ) {
F_17 ( V_57 L_18 , V_100 ) ;
goto V_144;
}
V_92 -> V_93 = V_93 ;
F_68 ( & V_92 -> V_145 ) ;
for ( V_42 = 0 ; V_42 < V_94 ; V_42 ++ ) {
struct V_1 * V_8 = V_93 + V_42 ;
struct V_2 * V_146 = F_3 ( V_8 ) ;
T_6 * V_147 = F_2 ( V_146 ) ;
V_146 -> V_12 = ( unsigned long ) V_59 ;
V_146 -> V_105 = V_36 -> V_105 ;
V_146 -> V_148 = & V_149 ;
V_146 -> V_150 = V_151 ;
F_69 ( V_146 , & V_36 -> V_3 ) ;
V_8 -> V_21 = V_42 ;
V_8 -> V_37 = V_92 ;
V_8 -> V_12 = V_59 ;
F_68 ( & V_8 -> V_145 ) ;
V_147 -> V_152 = V_153 ;
V_147 -> V_154 = V_155 ;
F_63 ( V_8 , V_146 ) ;
V_8 -> V_156 = V_157 ;
V_8 -> V_158 = V_159 ;
V_31 = F_70 ( V_146 ) ;
if ( V_31 < 0 )
goto V_160;
V_31 = F_71 ( V_146 ) ;
if ( V_31 < 0 ) {
F_17 ( V_57 L_19 , V_100 ) ;
F_19 ( V_8 ) ;
goto V_160;
}
}
V_31 = F_64 ( V_93 , V_161 ) ;
if ( V_31 < 0 )
goto V_160;
F_45 ( V_36 , V_92 ) ;
return V_31 ;
V_160:
while ( V_42 -- > 0 ) {
F_19 ( V_93 + V_42 ) ;
F_44 ( F_3 ( V_93 + V_42 ) ) ;
}
F_47 ( V_92 ) ;
V_42 = V_94 ;
V_144:
while ( V_42 -- > 0 )
F_46 ( V_93 [ V_42 ] . V_3 ) ;
F_47 ( V_93 ) ;
V_143:
return V_31 ;
}
static void F_72 ( unsigned long V_46 )
{
struct V_2 * V_3 = (struct V_2 * ) V_46 ;
struct V_1 * V_8 = F_1 ( V_3 ) ;
goto V_56;
V_56:
V_8 -> V_162 . V_163 = V_164 + V_151 ;
F_73 ( & V_8 -> V_162 ) ;
}
static void F_74 ( struct V_2 * V_3 )
{
}
static int F_75 ( struct V_1 * V_8 )
{
T_7 * V_165 = & V_8 -> V_165 ;
if ( V_165 -> V_166 && ( V_165 -> V_167 != V_168 ) ) {
struct V_2 * V_3 = F_3 ( V_8 ) ;
F_17 ( V_169 L_20 , V_3 -> V_34 ) ;
return - 1 ;
}
return 0 ;
}
static void F_76 ( struct V_35 * V_36 , void T_3 * V_59 )
{
int V_42 ;
F_77 ( & V_170 ) ;
for ( V_42 = 0 ; V_42 < 16 ; V_42 ++ )
F_78 ( V_36 , V_42 << 2 , V_171 + V_42 ) ;
F_5 ( 0x001c0000 , V_59 + V_112 ) ;
F_5 ( 0x0000ffff , V_59 + V_172 ) ;
F_5 ( 0x0000ffff , V_59 + V_173 ) ;
F_5 ( 0x0000ffff , V_59 + V_174 ) ;
F_5 ( 0x00000000 , V_59 + V_174 ) ;
F_10 ( V_59 + V_62 ) ;
F_31 ( 10 ) ;
for ( V_42 = 0 ; V_42 < 16 ; V_42 ++ )
F_79 ( V_36 , V_42 << 2 , V_171 [ V_42 ] ) ;
F_80 ( & V_170 ) ;
}
static int F_81 ( struct V_2 * V_3 )
{
struct V_1 * V_8 = F_1 ( V_3 ) ;
struct V_91 * V_92 ;
int V_31 = - V_58 ;
if ( ( F_75 ( V_8 ) < 0 ) )
goto V_175;
if ( ( V_31 = F_82 ( V_3 ) ) )
goto V_175;
V_92 = V_8 -> V_37 ;
if ( V_8 -> V_68 & V_176 ) {
V_8 -> V_68 &= ~ V_176 ;
F_4 ( 0 , V_177 , V_8 , V_3 , V_132 ) ;
F_4 ( 0 , 0x00050000 , V_8 , V_3 , V_137 ) ;
F_7 ( V_178 , V_8 , V_3 , V_179 ) ;
F_17 ( V_169 L_21 , V_3 -> V_34 ) ;
goto V_56;
}
V_8 -> V_68 = V_69 | V_70 ;
F_4 ( 0 , V_177 | V_180 , V_8 , V_3 , V_132 ) ;
if ( F_9 ( V_8 , V_3 ) & V_55 ) {
F_17 ( V_57 L_22 , V_3 -> V_34 ) ;
V_31 = - V_58 ;
goto V_143;
} else
F_17 ( V_169 L_23 , V_3 -> V_34 ) ;
F_7 ( V_178 , V_8 , V_3 , V_179 ) ;
F_7 ( V_181 | V_182 , V_8 , V_3 , V_183 ) ;
if ( ( V_31 = F_30 ( V_8 , V_3 , L_24 ) ) < 0 )
goto V_184;
if ( ( V_31 = F_34 ( V_8 ) ) < 0 ) {
F_17 ( V_57 L_5 , V_100 , L_25 ) ;
goto V_184;
}
if ( V_32 > 2 )
F_18 ( V_3 , V_8 , L_26 ) ;
V_56:
F_83 ( V_3 ) ;
F_84 ( & V_8 -> V_162 ) ;
V_8 -> V_162 . V_163 = V_164 + 10 * V_185 ;
V_8 -> V_162 . V_46 = ( unsigned long ) V_3 ;
V_8 -> V_162 . V_186 = F_72 ;
F_73 ( & V_8 -> V_162 ) ;
F_85 ( V_3 ) ;
return 0 ;
V_184:
F_7 ( 0xffffffff , V_8 , V_3 , V_179 ) ;
F_4 ( V_177 | V_180 , 0 , V_8 , V_3 , V_132 ) ;
V_143:
F_86 ( V_3 ) ;
V_175:
return V_31 ;
}
static int F_87 ( struct V_1 * V_8 , struct V_2 * V_3 )
{
}
static T_8 V_153 ( struct V_40 * V_53 ,
struct V_2 * V_3 )
{
struct V_1 * V_8 = F_1 ( V_3 ) ;
struct V_91 * V_92 = V_8 -> V_37 ;
struct V_19 * V_38 ;
int V_187 ;
V_187 = V_8 -> V_17 % V_18 ;
V_8 -> V_45 [ V_187 ] = V_53 ;
V_38 = V_8 -> V_38 + V_187 ;
V_38 -> V_10 = V_188 | F_88 ( V_53 -> V_47 ) ;
V_38 -> V_46 = F_28 ( F_29 ( V_92 -> V_36 , V_53 -> V_46 , V_53 -> V_47 ,
V_48 ) ) ;
V_38 -> V_189 = 0x00000000 ;
V_38 -> V_164 = V_164 ;
F_89 () ;
#ifdef F_90
F_91 ( & V_8 -> V_145 ) ;
while ( F_87 ( V_8 , V_3 ) ) ;
F_92 ( & V_8 -> V_145 ) ;
#endif
if ( V_32 > 2 )
F_18 ( V_3 , V_8 , L_27 ) ;
if ( ! ( ( ++ V_8 -> V_17 - V_8 -> V_28 ) % V_18 ) )
F_93 ( V_3 ) ;
if ( F_14 ( V_8 , V_3 ) )
F_11 ( V_8 , V_3 ) ;
return V_190 ;
}
static int F_94 ( struct V_2 * V_3 )
{
struct V_1 * V_8 = F_1 ( V_3 ) ;
F_95 ( & V_8 -> V_162 ) ;
F_93 ( V_3 ) ;
F_4 ( V_177 | V_180 , 0 , V_8 , V_3 , V_132 ) ;
F_4 ( 0x00050000 , 0 , V_8 , V_3 , V_137 ) ;
F_7 ( 0xffffffff , V_8 , V_3 , V_179 ) ;
V_8 -> V_68 |= V_176 ;
F_86 ( V_3 ) ;
return 0 ;
}
static inline int F_96 ( int V_191 )
{
int V_31 = 0 ;
#ifdef F_97
if ( V_191 >= 2 )
V_31 = - 1 ;
#endif
return V_31 ;
}
static int F_98 ( struct V_2 * V_3 , T_1 * V_192 , T_1 * V_10 )
{
struct V_1 * V_8 = F_1 ( V_3 ) ;
int V_31 = - 1 ;
T_1 V_193 ;
* V_10 &= ~ V_194 ;
if ( * V_192 ) {
T_1 V_195 = 0 , V_196 = 0 , V_197 ;
int V_198 ;
V_198 = V_8 -> V_37 -> V_141 ;
if ( ! V_198 )
goto V_56;
if ( F_96 ( V_8 -> V_21 ) < 0 )
goto V_56;
V_197 = V_198 / * V_192 ;
if ( V_197 > V_199 ) {
V_197 >>= 4 ;
* V_10 |= 0x00000036 ;
} else
* V_10 |= 0x00000037 ;
if ( V_197 >> 22 ) {
V_195 = 63 ;
V_196 = 15 ;
} else if ( V_197 ) {
V_196 = 0 ;
while ( 0xffffffc0 & V_197 ) {
V_196 ++ ;
V_197 >>= 1 ;
}
V_195 = V_197 ;
}
V_193 = ( V_196 << 8 ) | V_195 ;
V_197 = V_195 << V_196 ;
if ( ! ( * V_10 & 0x00000001 ) )
V_197 <<= 4 ;
* V_192 = V_198 / V_197 ;
} else {
V_193 = 0 ;
}
F_7 ( V_193 , V_8 , V_3 , V_200 ) ;
V_31 = 0 ;
V_56:
return V_31 ;
}
static int F_99 ( struct V_2 * V_3 , struct V_201 * V_202 , int V_203 )
{
T_7 T_9 * line = V_202 -> V_204 . V_205 . V_206 ;
struct V_1 * V_8 = F_1 ( V_3 ) ;
const T_10 V_207 = sizeof( V_8 -> V_165 ) ;
int V_31 = 0 ;
if ( V_3 -> V_68 & V_208 )
return - V_209 ;
if ( V_203 != V_210 )
return - V_140 ;
switch( V_202 -> V_204 . type ) {
case V_211 :
V_202 -> V_204 . type = V_212 ;
if ( V_202 -> V_204 . V_207 < V_207 ) {
V_202 -> V_204 . V_207 = V_207 ;
return - V_213 ;
}
if ( F_100 ( line , & V_8 -> V_165 , V_207 ) )
return - V_214 ;
break;
case V_212 :
if ( ! F_101 ( V_215 ) )
return - V_216 ;
if ( V_8 -> V_68 & V_176 ) {
F_17 ( V_169 L_28
L_29 , V_3 -> V_34 ) ;
return - V_216 ;
}
if ( F_102 ( & V_8 -> V_165 , line , V_207 ) )
return - V_214 ;
V_31 = F_103 ( V_8 , V_3 ) ;
break;
default:
V_31 = F_104 ( V_3 , V_202 , V_203 ) ;
break;
}
return V_31 ;
}
static int F_105 ( const struct V_217 * V_5 , int V_7 )
{
int V_42 ;
for ( V_42 = 0 ; V_5 [ V_42 ] . define != - 1 ; V_42 ++ ) {
if ( V_7 == V_5 [ V_42 ] . define )
break;
}
if ( V_5 [ V_42 ] . define == - 1 )
return - 1 ;
else
return V_42 ;
}
static int F_106 ( struct V_1 * V_8 ,
struct V_2 * V_3 )
{
T_7 * V_165 = & V_8 -> V_165 ;
int V_31 = - V_140 ;
T_1 V_192 , V_10 ;
V_192 = V_165 -> V_218 ;
V_10 = F_8 ( V_8 , V_132 ) ;
if ( F_98 ( V_3 , & V_192 , & V_10 ) < 0 )
goto V_56;
if ( V_192 ) {
F_17 ( V_33 L_30 , V_3 -> V_34 ) ;
if ( V_165 -> V_218 != V_192 ) {
F_17 ( V_33 L_31 ,
V_3 -> V_34 , V_165 -> V_218 , V_192 ) ;
V_165 -> V_218 = V_192 ;
}
} else {
V_10 |= V_177 | V_180 ;
F_17 ( V_33 L_32 , V_3 -> V_34 ) ;
}
F_7 ( V_10 , V_8 , V_3 , V_132 ) ;
V_31 = 0 ;
V_56:
return V_31 ;
}
static int F_107 ( struct V_1 * V_8 ,
struct V_2 * V_3 )
{
static const struct V_217 V_158 [] = {
{ V_159 , 0x00000000 } ,
{ V_219 , 0x00200000 } ,
{ V_220 , 0x00400000 } ,
{ V_221 , 0x00500000 } ,
{ V_222 , 0x00600000 } ,
{ - 1 , 0 }
} ;
int V_42 , V_31 = 0 ;
V_42 = F_105 ( V_158 , V_8 -> V_158 ) ;
if ( V_42 >= 0 )
F_4 ( V_223 , V_158 [ V_42 ] . V_13 , V_8 , V_3 , V_132 ) ;
else
V_31 = - V_140 ;
return V_31 ;
}
static int F_108 ( struct V_1 * V_8 ,
struct V_2 * V_3 )
{
T_7 * V_165 = & V_8 -> V_165 ;
T_1 V_10 ;
V_10 = F_8 ( V_8 , V_135 ) ;
if ( V_165 -> V_166 ) {
F_17 ( V_33 L_33 , V_3 -> V_34 ) ;
V_10 |= 0x00000100 ;
} else {
F_17 ( V_33 L_34 , V_3 -> V_34 ) ;
V_10 &= ~ 0x00000100 ;
}
F_7 ( V_10 , V_8 , V_3 , V_135 ) ;
return 0 ;
}
static int F_109 ( struct V_1 * V_8 ,
struct V_2 * V_3 )
{
static const struct V_217 V_224 [] = {
{ V_157 , 0x00000010 } ,
{ V_225 , 0x00000000 } ,
{ V_226 , 0x00000011 } ,
{ V_227 , 0x00000001 }
} ;
int V_42 , V_31 = 0 ;
V_42 = F_105 ( V_224 , V_8 -> V_156 ) ;
if ( V_42 >= 0 )
F_4 ( V_228 , V_224 [ V_42 ] . V_13 , V_8 , V_3 , V_135 ) ;
else
V_31 = - V_140 ;
return V_31 ;
}
static int F_103 ( struct V_1 * V_8 , struct V_2 * V_3 )
{
struct {
int (* F_110)( struct V_1 * , struct V_2 * );
} * V_5 , V_229 [] = {
{ F_107 } ,
{ F_106 } ,
{ F_108 } ,
{ F_109 } ,
{ NULL }
} ;
int V_31 = 0 ;
for ( V_5 = V_229 ; V_5 -> F_110 ; V_5 ++ ) {
if ( ( V_31 = V_5 -> F_110 ( V_8 , V_3 ) ) < 0 )
break;
}
return V_31 ;
}
static T_11 V_108 ( int V_105 , void * V_230 )
{
struct V_1 * V_93 = V_230 ;
struct V_91 * V_4 ;
struct V_2 * V_3 ;
void T_3 * V_59 ;
T_1 V_10 ;
unsigned long V_68 ;
int V_42 , V_231 = 1 ;
V_4 = V_93 -> V_37 ;
V_3 = F_3 ( V_93 ) ;
F_111 ( & V_4 -> V_145 , V_68 ) ;
V_59 = V_93 -> V_12 ;
V_10 = F_10 ( V_59 + V_62 ) ;
if ( ! V_10 ) {
V_231 = 0 ;
goto V_99;
}
if ( V_32 > 3 )
F_17 ( V_33 L_35 , V_100 , V_10 ) ;
F_5 ( V_10 , V_59 + V_62 ) ;
if ( V_10 & V_64 ) {
F_17 ( V_57 L_36 ,
V_3 -> V_34 ) ;
goto V_99;
}
V_10 &= ~ V_63 ;
if ( V_10 & V_232 ) {
if ( V_32 > 0 )
F_17 ( V_33 L_37 , V_100 ) ;
if ( V_4 -> V_115 [ V_4 -> V_233 ++ % V_67 ] & F_28 ( V_64 ) )
F_17 ( V_57 L_7 , V_3 -> V_34 , L_38 ) ;
if ( ! ( V_10 &= ~ V_232 ) )
goto V_99;
}
if ( V_10 & V_234 ) {
V_42 = V_94 - 1 ;
do {
F_112 ( V_4 , V_93 + V_42 ) ;
} while ( -- V_42 >= 0 );
V_10 &= ~ V_234 ;
}
if ( V_10 & V_235 ) {
V_42 = V_94 - 1 ;
do {
F_113 ( V_4 , V_93 + V_42 ) ;
} while ( -- V_42 >= 0 );
V_10 &= ~ V_235 ;
}
V_99:
F_114 ( & V_4 -> V_145 , V_68 ) ;
return F_115 ( V_231 ) ;
}
static void F_113 ( struct V_91 * V_92 ,
struct V_1 * V_8 )
{
struct V_2 * V_3 = F_3 ( V_8 ) ;
T_1 V_10 ;
int V_65 , V_236 = 0 ;
V_237:
V_65 = V_8 -> V_66 % V_67 ;
V_10 = F_22 ( V_8 -> V_71 [ V_65 ] ) ;
if ( ! V_10 ) {
if ( V_32 > 4 )
F_17 ( V_33 L_39 , V_3 -> V_34 ,
V_10 ) ;
if ( ( V_32 > 1 ) && ( V_236 > 1 ) )
F_17 ( V_33 L_40 , V_3 -> V_34 , V_236 ) ;
if ( V_236 && F_116 ( V_3 ) )
if ( ( V_8 -> V_17 - V_8 -> V_28 ) % V_18 )
F_117 ( V_3 ) ;
if ( F_39 ( V_3 ) && F_14 ( V_8 , V_3 ) &&
! F_13 ( V_8 ) )
F_11 ( V_8 , V_3 ) ;
return;
}
V_236 ++ ;
V_8 -> V_71 [ V_65 ] = 0 ;
V_8 -> V_66 ++ ;
if ( F_15 ( V_10 , V_8 , V_3 , L_41 ) < 0 )
return;
if ( V_10 & V_238 ) {
if ( V_10 & V_239 ) {
struct V_40 * V_53 ;
struct V_19 * V_38 ;
if ( V_32 > 2 )
F_18 ( V_3 , V_8 , L_42 ) ;
V_65 = V_8 -> V_28 % V_18 ;
V_38 = V_8 -> V_38 + V_65 ;
V_53 = V_8 -> V_45 [ V_65 ] ;
if ( V_53 ) {
F_21 ( V_92 -> V_36 , F_22 ( V_38 -> V_46 ) ,
V_53 -> V_47 , V_48 ) ;
if ( V_38 -> V_10 & V_188 ) {
V_3 -> V_79 . V_240 ++ ;
V_3 -> V_79 . V_241 += V_53 -> V_47 ;
}
F_41 ( V_53 ) ;
V_8 -> V_45 [ V_65 ] = NULL ;
++ V_8 -> V_28 ;
} else {
if ( V_32 > 1 )
F_17 ( V_57 L_43 ,
V_3 -> V_34 , V_65 ) ;
}
V_38 -> V_46 = V_38 -> V_187 ;
V_38 -> V_10 = V_188 | F_88 ( 2 * V_242 ) ;
V_38 -> V_189 = 0x00000000 ;
V_38 -> V_164 = 0 ;
if ( ! ( V_10 &= ~ V_239 ) )
goto V_237;
}
if ( V_10 & V_243 ) {
F_17 ( V_57 L_44 , V_100 ) ;
V_8 -> V_68 = V_70 ;
F_5 ( V_244 | V_245 ,
V_8 -> V_12 + 0x0c * V_8 -> V_21 + V_246 ) ;
F_5 ( V_60 , V_8 -> V_12 + V_61 ) ;
return;
}
if ( V_10 & V_247 ) {
F_17 ( V_169 L_45 , V_3 -> V_34 ) ;
if ( ! ( V_10 &= ~ V_247 ) )
goto V_237;
}
if ( V_10 & V_248 ) {
F_17 ( V_57 L_46 , V_100 ) ;
if ( ! ( V_10 &= ~ V_248 ) )
goto V_237;
}
if ( V_10 & V_72 ) {
void T_3 * V_249 ;
unsigned long V_250 ;
int V_42 ;
for ( V_42 = 1 ; V_42 ; V_42 <<= 1 ) {
if ( ! ( F_9 ( V_8 , V_3 ) & V_55 ) )
break;
}
if ( ! V_42 )
F_17 ( V_169 L_47 , V_3 -> V_34 ) ;
V_249 = V_8 -> V_12 + 0x0c * V_8 -> V_21 ;
if ( V_8 -> V_68 & V_70 ) {
if ( V_32 > 2 )
F_18 ( V_3 , V_8 , L_48 ) ;
V_250 = V_8 -> V_16 +
( V_8 -> V_28 % V_18 ) *
sizeof( struct V_19 ) ;
F_5 ( V_250 , V_249 + V_251 ) ;
F_11 ( V_8 , V_3 ) ;
F_5 ( V_244 | V_252 , V_249 + V_246 ) ;
if ( F_33 ( V_3 , L_49 ) < 0 )
goto V_253;
V_8 -> V_68 &= ~ V_70 ;
}
if ( V_8 -> V_68 & V_69 ) {
V_250 = V_8 -> V_23 +
( V_8 -> V_73 % V_25 ) *
sizeof( struct V_26 ) ;
F_5 ( V_250 , V_249 + V_254 ) ;
F_12 ( V_8 , V_3 ) ;
F_5 ( V_244 | V_255 , V_249 + V_246 ) ;
if ( F_33 ( V_3 , L_50 ) < 0 )
goto V_253;
V_8 -> V_68 &= ~ V_69 ;
F_118 () ;
F_7 ( 0x08050008 , V_8 , V_3 , V_137 ) ;
}
V_253:
if ( ! ( V_10 &= ~ V_72 ) )
goto V_237;
}
if ( V_10 & V_256 ) {
if ( V_32 > 0 )
F_17 ( V_169 L_51 , V_3 -> V_34 ) ;
if ( ! ( V_10 &= ~ V_256 ) )
goto V_237;
}
} else {
if ( V_10 & V_257 ) {
#ifdef F_90
while ( ! F_87 ( V_8 , V_3 ) ) ;
#endif
F_17 ( V_169 L_52 , V_3 -> V_34 ) ;
V_10 &= ~ V_257 ;
}
if ( V_10 & V_258 ) {
F_17 ( V_169 L_53 , V_3 -> V_34 ) ;
V_3 -> V_79 . V_259 ++ ;
V_10 &= ~ V_258 ;
}
}
goto V_237;
}
static void F_112 ( struct V_91 * V_4 ,
struct V_1 * V_8 )
{
struct V_2 * V_3 = F_3 ( V_8 ) ;
T_1 V_10 ;
int V_65 ;
V_237:
V_65 = V_8 -> V_260 % V_67 ;
V_10 = F_22 ( V_8 -> V_124 [ V_65 ] ) ;
if ( ! V_10 )
return;
V_8 -> V_124 [ V_65 ] = 0 ;
V_8 -> V_260 ++ ;
if ( F_15 ( V_10 , V_8 , V_3 , L_54 ) < 0 )
return;
if ( ! ( V_10 & V_238 ) ) {
struct V_26 * V_39 ;
if ( V_32 > 4 )
F_17 ( V_33 L_55 , V_3 -> V_34 ,
V_10 ) ;
V_10 &= 0x00ffffff ;
if ( V_10 & V_258 ) {
F_17 ( V_33 L_56 , V_3 -> V_34 ) ;
V_65 = V_8 -> V_73 % V_25 ;
V_39 = V_8 -> V_39 + V_65 ;
while ( ! ( V_39 -> V_261 & V_262 ) ) {
V_39 ++ ;
V_65 ++ ;
if ( ! ( V_65 = V_65 % V_25 ) )
V_39 = V_8 -> V_39 ;
}
F_25 ( V_8 , V_3 ) ;
if ( ! V_39 -> V_46 )
goto V_237;
V_39 -> V_261 &= ~ V_262 ;
V_39 -> V_77 = 0x00000000 ;
V_39 -> V_90 = F_28 ( 0xbabeface ) ;
goto V_237;
}
if ( V_10 & V_263 ) {
F_36 ( V_8 , V_3 ) ;
goto V_237;
}
if ( V_10 & V_257 ) {
F_17 ( V_169 L_57 , V_3 -> V_34 ) ;
V_10 &= ~ V_257 ;
goto V_237;
}
} else {
if ( V_32 > 1 ) {
static struct {
T_1 V_6 ;
const char * V_264 ;
} V_265 [] = {
{ 0x00008000 , L_58 } ,
{ 0x00000020 , L_59 } ,
{ 0x00000010 , L_60 } ,
{ 0x00000008 , L_61 } ,
{ 0 , NULL }
} , * V_266 ;
for ( V_266 = V_265 ; V_266 -> V_264 ; V_266 ++ ) {
if ( V_10 & V_266 -> V_6 ) {
F_17 ( V_33 L_62 ,
V_3 -> V_34 , V_266 -> V_264 ) ;
if ( ! ( V_10 &= ~ V_266 -> V_6 ) )
goto V_237;
}
}
} else {
if ( ! ( V_10 &= ~ 0x0000c03c ) )
goto V_237;
}
if ( V_10 & V_247 ) {
F_17 ( V_169 L_45 , V_3 -> V_34 ) ;
if ( ! ( V_10 &= ~ V_247 ) )
goto V_237;
}
if ( V_10 & V_267 ) {
struct V_26 * V_39 ;
void T_3 * V_249 ;
int V_65 ;
V_249 = V_8 -> V_12 + 0x0c * V_8 -> V_21 ;
F_4 ( V_136 , 0 , V_8 , V_3 , V_137 ) ;
F_7 ( V_182 , V_8 , V_3 , V_183 ) ;
V_8 -> V_68 |= V_268 ;
do {
V_65 = V_8 -> V_73 ++ % V_25 ;
V_39 = V_8 -> V_39 + V_65 ;
if ( ! ( V_39 -> V_77 & V_269 ) )
break;
if ( V_39 -> V_77 & V_270 ) {
V_3 -> V_79 . V_271 ++ ;
V_39 -> V_261 |= V_262 ;
V_39 -> V_77 = 0x00000000 ;
V_39 -> V_90 = F_28 ( 0xbabeface ) ;
} else
F_36 ( V_8 , V_3 ) ;
} while ( 1 );
if ( V_32 > 0 ) {
if ( V_8 -> V_68 & V_268 )
F_17 ( V_33
L_63 , V_100 ) ;
}
#ifdef F_119
#warning "FIXME: CH0BRDA"
F_5 ( V_8 -> V_23 +
( V_8 -> V_73 % V_25 ) *
sizeof( struct V_26 ) , V_249 + V_254 ) ;
F_5 ( V_244 | V_272 | V_255 , V_249 + V_246 ) ;
if ( F_33 ( V_3 , L_64 ) < 0 ) {
F_17 ( V_57 L_65 ,
V_3 -> V_34 , L_64 ) ;
goto V_273;
}
F_5 ( V_244 | V_255 , V_249 + V_246 ) ;
if ( F_33 ( V_3 , L_50 ) < 0 ) {
F_17 ( V_57 L_65 ,
V_3 -> V_34 , L_50 ) ;
goto V_273;
}
V_273:
#endif
F_4 ( 0 , V_136 , V_8 , V_3 , V_137 ) ;
goto V_237;
}
if ( V_10 & V_256 ) {
F_17 ( V_169 L_51 , V_3 -> V_34 ) ;
if ( ! ( V_10 &= ~ V_256 ) )
goto V_237;
}
if ( V_10 & V_274 ) {
F_17 ( V_33 L_66 , V_100 ) ;
if ( ! ( V_10 &= ~ V_274 ) )
goto V_237;
}
}
}
static struct V_40 * F_120 ( struct V_1 * V_8 )
{
struct V_40 * V_53 ;
V_53 = F_26 ( V_242 ) ;
if ( V_53 ) {
int V_275 = V_8 -> V_28 % V_18 ;
struct V_19 * V_38 = V_8 -> V_38 + V_275 ;
V_53 -> V_47 = V_242 ;
F_121 ( V_53 , V_98 ,
strlen ( V_98 ) % V_242 ) ;
V_38 -> V_10 = V_188 | F_88 ( V_242 ) ;
V_38 -> V_46 = F_28 ( F_29 ( V_8 -> V_37 -> V_36 ,
V_53 -> V_46 , V_242 ,
V_48 ) ) ;
V_8 -> V_45 [ V_275 ] = V_53 ;
}
return V_53 ;
}
static int F_70 ( struct V_2 * V_3 )
{
struct V_1 * V_8 = F_1 ( V_3 ) ;
struct V_35 * V_36 = V_8 -> V_37 -> V_36 ;
struct V_19 * V_38 ;
struct V_26 * V_39 ;
void * V_250 ;
int V_42 ;
V_250 = F_58 ( V_36 , V_44 , & V_8 -> V_23 ) ;
if ( ! V_250 )
goto V_143;
V_8 -> V_39 = V_39 = (struct V_26 * ) V_250 ;
V_250 = F_58 ( V_36 , V_43 , & V_8 -> V_16 ) ;
if ( ! V_250 )
goto V_276;
V_8 -> V_38 = V_38 = (struct V_19 * ) V_250 ;
memset ( V_8 -> V_45 , 0 , sizeof( struct V_40 * ) * V_18 ) ;
V_8 -> V_28 = 0xffffffff ;
V_42 = V_8 -> V_17 = 0 ;
do {
V_38 -> V_10 = V_188 | F_88 ( 2 * V_242 ) ;
V_38 -> V_189 = 0x00000000 ;
V_38 -> V_46 = F_28 ( V_8 -> V_16 ) ;
( V_38 ++ ) -> V_187 = F_28 ( V_8 -> V_16 +
( ++ V_42 % V_18 ) * sizeof( * V_38 ) ) ;
} while ( V_42 < V_18 );
if ( ! F_120 ( V_8 ) )
goto V_277;
memset ( V_8 -> V_49 , 0 , sizeof( struct V_40 * ) * V_25 ) ;
V_42 = V_8 -> V_24 = V_8 -> V_73 = 0 ;
do {
V_39 -> V_261 = V_278 ;
V_39 -> V_77 = 0x00000000 ;
V_39 -> V_90 = F_28 ( 0xbabeface ) ;
V_39 -> V_261 |= F_122 ( V_50 ) ;
if ( F_25 ( V_8 , V_3 ) >= 0 )
V_8 -> V_24 ++ ;
( V_39 ++ ) -> V_187 = F_28 ( V_8 -> V_23 +
( ++ V_42 % V_25 ) * sizeof( * V_39 ) ) ;
} while ( V_42 < V_25 );
return 0 ;
V_277:
F_20 ( V_36 , V_43 , V_250 , V_8 -> V_16 ) ;
V_276:
F_20 ( V_36 , V_44 , V_39 , V_8 -> V_23 ) ;
V_143:
return - V_120 ;
}
static void T_12 F_123 ( struct V_35 * V_36 )
{
struct V_91 * V_92 ;
struct V_1 * V_93 ;
void T_3 * V_59 ;
int V_42 ;
V_92 = F_43 ( V_36 ) ;
V_93 = V_92 -> V_93 ;
V_59 = V_93 -> V_12 ;
F_76 ( V_36 , V_59 ) ;
F_59 ( V_36 -> V_105 , V_93 ) ;
F_20 ( V_36 , V_67 * sizeof( T_1 ) , V_92 -> V_115 ,
V_92 -> V_117 ) ;
for ( V_42 = 0 ; V_42 < V_94 ; V_42 ++ ) {
struct V_1 * V_8 = V_93 + V_42 ;
F_19 ( V_8 ) ;
F_20 ( V_36 , V_67 * sizeof( T_1 ) ,
V_8 -> V_124 , V_8 -> V_125 ) ;
F_20 ( V_36 , V_67 * sizeof( T_1 ) ,
V_8 -> V_71 , V_8 -> V_121 ) ;
}
F_42 ( V_36 ) ;
F_60 ( V_59 ) ;
F_61 ( V_36 , 1 ) ;
F_61 ( V_36 , 0 ) ;
F_62 ( V_36 ) ;
}
static int V_155 ( struct V_2 * V_3 , unsigned short V_158 ,
unsigned short V_156 )
{
struct V_1 * V_8 = F_1 ( V_3 ) ;
if ( V_158 != V_159 &&
V_158 != V_219 &&
V_158 != V_220 &&
V_158 != V_221 &&
V_158 != V_222 )
return - V_279 ;
if ( V_156 != V_280 &&
V_156 != V_157 &&
V_156 != V_225 &&
V_156 != V_226 &&
V_156 != V_227 )
return - V_279 ;
V_8 -> V_158 = V_158 ;
V_8 -> V_156 = V_156 ;
return 0 ;
}
static int T_13 F_124 ( char * V_281 )
{
int * args [] = { & V_32 , & V_161 , NULL } , * * V_5 = args ;
while ( * V_5 && ( F_125 ( & V_281 , * V_5 ) == 2 ) )
V_5 ++ ;
return 1 ;
}
static int T_13 F_126 ( void )
{
return F_127 ( & V_282 ) ;
}
static void T_14 F_128 ( void )
{
F_129 ( & V_282 ) ;
}
