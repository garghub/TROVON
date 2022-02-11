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
F_33 ( V_3 , L_5 , V_30 ) ;
V_56:
return ( V_42 >= 0 ) ? V_42 : - V_57 ;
}
static int F_34 ( struct V_2 * V_3 , char * V_30 )
{
void T_3 * V_58 = F_1 ( V_3 ) -> V_12 ;
T_4 V_42 = 0 ;
F_5 ( V_59 , V_58 + V_60 ) ;
V_58 += V_61 ;
do {
T_1 V_10 = F_10 ( V_58 ) ;
if ( V_10 & V_62 ) {
F_35 ( V_3 , L_6 , V_30 ) ;
F_5 ( V_62 , V_58 ) ;
goto V_56;
} else if ( V_10 & V_63 ) {
F_33 ( V_3 , L_7 , V_30 ) ;
F_5 ( V_63 , V_58 ) ;
V_42 = - 1 ;
goto V_56;
}
F_32 () ;
} while ( ++ V_42 > 0 );
F_33 ( V_3 , L_5 , V_30 ) ;
V_56:
return V_42 ;
}
static inline int F_36 ( struct V_1 * V_8 )
{
int V_64 = V_8 -> V_65 % V_66 ;
T_2 V_42 = 0 ;
do {
if ( ! ( V_8 -> V_67 & ( V_68 | V_69 ) ) ||
( V_8 -> V_70 [ V_64 ] & F_28 ( V_71 ) ) )
break;
F_37 () ;
F_31 ( 10 ) ;
} while ( ++ V_42 > 0 );
return ( V_42 >= 0 ) ? V_42 : - V_57 ;
}
static inline void F_38 ( struct V_1 * V_8 ,
struct V_2 * V_3 )
{
struct V_26 * V_39 = V_8 -> V_39 + V_8 -> V_72 % V_25 ;
struct V_35 * V_36 = V_8 -> V_37 -> V_36 ;
struct V_40 * V_53 ;
int V_73 ;
V_53 = V_8 -> V_49 [ V_8 -> V_72 ++ % V_25 ] ;
if ( ! V_53 ) {
F_17 ( V_33 L_8 , V_3 -> V_34 , V_74 ) ;
goto V_75;
}
V_73 = F_39 ( F_22 ( V_39 -> V_76 ) ) ;
F_21 ( V_36 , F_22 ( V_39 -> V_46 ) ,
F_24 ( V_50 ) , V_51 ) ;
if ( ( V_53 -> V_46 [ -- V_73 ] & V_77 ) == V_77 ) {
V_3 -> V_78 . V_79 ++ ;
V_3 -> V_78 . V_80 += V_73 ;
F_40 ( V_53 , V_73 ) ;
if ( F_41 ( V_3 ) )
V_53 -> V_54 = F_27 ( V_53 , V_3 ) ;
F_42 ( V_53 ) ;
} else {
if ( V_53 -> V_46 [ V_73 ] & V_81 )
V_3 -> V_78 . V_82 ++ ;
else if ( ! ( V_53 -> V_46 [ V_73 ] & V_83 ) )
V_3 -> V_78 . V_84 ++ ;
else if ( ( V_53 -> V_46 [ V_73 ] & ( V_85 | V_86 ) ) !=
( V_85 | V_86 ) )
V_3 -> V_78 . V_87 ++ ;
V_3 -> V_78 . V_88 ++ ;
F_43 ( V_53 ) ;
}
V_75:
while ( ( V_8 -> V_24 - V_8 -> V_72 ) % V_25 ) {
if ( F_25 ( V_8 , V_3 ) < 0 )
break;
V_8 -> V_24 ++ ;
}
F_12 ( V_8 , V_3 ) ;
V_39 -> V_76 = 0x00000000 ;
V_39 -> V_89 = F_28 ( 0xbabeface ) ;
}
static void F_44 ( struct V_35 * V_36 )
{
struct V_90 * V_91 ;
struct V_1 * V_92 ;
int V_42 ;
V_91 = F_45 ( V_36 ) ;
V_92 = V_91 -> V_92 ;
for ( V_42 = 0 ; V_42 < V_93 ; V_42 ++ )
F_46 ( F_3 ( V_92 + V_42 ) ) ;
F_47 ( V_36 , NULL ) ;
for ( V_42 = 0 ; V_42 < V_93 ; V_42 ++ )
F_48 ( V_92 [ V_42 ] . V_3 ) ;
F_49 ( V_92 ) ;
F_49 ( V_91 ) ;
}
static int T_5 F_50 ( struct V_35 * V_36 ,
const struct V_94 * V_95 )
{
struct V_90 * V_4 ;
struct V_1 * V_8 ;
void T_3 * V_58 ;
int V_42 , V_96 ;
F_17 ( V_33 L_9 , V_97 ) ;
V_96 = F_51 ( V_36 ) ;
if ( V_96 < 0 )
goto V_98;
V_96 = F_52 ( V_36 , 0 , L_10 ) ;
if ( V_96 < 0 ) {
F_53 ( L_11 ) ;
goto V_99;
}
V_96 = F_52 ( V_36 , 1 , L_12 ) ;
if ( V_96 < 0 ) {
F_53 ( L_13 ) ;
goto V_100;
}
V_58 = F_54 ( V_36 , 0 ) ;
if ( ! V_58 ) {
F_53 ( L_14 ,
( unsigned long long ) F_55 ( V_36 , 0 ) ,
( unsigned long long ) F_56 ( V_36 , 0 ) ) ;
V_96 = - V_101 ;
goto V_102;
}
F_17 ( V_33 L_15 ,
( unsigned long long ) F_56 ( V_36 , 0 ) ,
( unsigned long long ) F_56 ( V_36 , 1 ) , V_36 -> V_103 ) ;
F_57 ( V_36 , V_104 , 0xf8 ) ;
F_58 ( V_36 ) ;
V_96 = F_59 ( V_36 , V_58 ) ;
if ( V_96 < 0 )
goto V_105;
V_4 = F_45 ( V_36 ) ;
V_96 = F_60 ( V_36 -> V_103 , V_106 , V_107 , V_108 , V_4 -> V_92 ) ;
if ( V_96 < 0 ) {
F_61 ( L_16 , V_36 -> V_103 ) ;
goto V_109;
}
F_5 ( 0x00000001 , V_58 + V_110 ) ;
{
T_1 V_13 ;
V_13 = ( V_66 >> 5 ) - 1 ;
V_13 |= V_13 << 4 ;
V_13 |= V_13 << 8 ;
V_13 |= V_13 << 16 ;
F_5 ( V_13 , V_58 + V_111 ) ;
}
F_5 ( ( T_1 ) ( ( ( V_66 >> 5 ) - 1 ) << 20 ) , V_58 + V_112 ) ;
V_4 -> V_113 = ( V_114 * ) F_62 ( V_36 ,
V_66 * sizeof( V_114 ) , & V_4 -> V_115 ) ;
if ( ! V_4 -> V_113 )
goto V_116;
F_5 ( V_4 -> V_115 , V_58 + V_117 ) ;
V_96 = - V_118 ;
for ( V_42 = 0 ; V_42 < V_93 ; V_42 ++ ) {
V_8 = V_4 -> V_92 + V_42 ;
V_8 -> V_70 = ( V_114 * ) F_62 ( V_36 ,
V_66 * sizeof( T_1 ) , & V_8 -> V_119 ) ;
if ( ! V_8 -> V_70 )
goto V_120;
F_5 ( V_8 -> V_119 , V_58 + V_121 + V_42 * 4 ) ;
}
for ( V_42 = 0 ; V_42 < V_93 ; V_42 ++ ) {
V_8 = V_4 -> V_92 + V_42 ;
V_8 -> V_122 = ( V_114 * ) F_62 ( V_36 ,
V_66 * sizeof( T_1 ) , & V_8 -> V_123 ) ;
if ( ! V_8 -> V_122 )
goto V_124;
F_5 ( V_8 -> V_123 , V_58 + V_125 + V_42 * 4 ) ;
}
F_5 ( 0x42104000 , V_58 + V_126 ) ;
F_5 ( 0xdef6d800 , V_58 + V_127 ) ;
F_5 ( 0x18181818 , V_58 + V_128 ) ;
F_5 ( 0x0000000e , V_58 + V_129 ) ;
F_5 ( 0xff200001 , V_58 + V_60 ) ;
V_96 = 0 ;
V_98:
return V_96 ;
V_124:
while ( -- V_42 >= 0 ) {
V_8 = V_4 -> V_92 + V_42 ;
F_20 ( V_36 , V_66 * sizeof( T_1 ) ,
V_8 -> V_122 , V_8 -> V_123 ) ;
}
V_42 = V_93 ;
V_120:
while ( -- V_42 >= 0 ) {
V_8 = V_4 -> V_92 + V_42 ;
F_20 ( V_36 , V_66 * sizeof( T_1 ) ,
V_8 -> V_70 , V_8 -> V_119 ) ;
}
F_20 ( V_36 , V_66 * sizeof( T_1 ) , V_4 -> V_113 ,
V_4 -> V_115 ) ;
V_116:
F_63 ( V_36 -> V_103 , V_4 -> V_92 ) ;
V_109:
F_44 ( V_36 ) ;
V_105:
F_64 ( V_58 ) ;
V_102:
F_65 ( V_36 , 1 ) ;
V_100:
F_65 ( V_36 , 0 ) ;
V_99:
F_66 ( V_36 ) ;
goto V_98;
}
static void F_67 ( struct V_1 * V_8 ,
struct V_2 * V_3 )
{
F_7 ( 0x00000000 , V_8 , V_3 , V_130 ) ;
F_7 ( V_131 | ( V_50 >> 5 ) , V_8 , V_3 , V_132 ) ;
F_7 ( 0x02408000 , V_8 , V_3 , V_133 ) ;
F_7 ( 0x00050008 & ~ V_134 , V_8 , V_3 , V_135 ) ;
}
static inline int F_68 ( struct V_1 * V_8 , int V_136 )
{
int V_31 = 0 ;
if ( ( V_136 < 0 ) || ( V_136 > V_137 ) )
V_31 = - V_138 ;
else
V_8 -> V_37 -> V_139 = V_136 ;
return V_31 ;
}
static int F_59 ( struct V_35 * V_36 , void T_3 * V_58 )
{
struct V_90 * V_91 ;
struct V_1 * V_92 ;
int V_42 , V_31 = - V_118 ;
V_92 = F_69 ( V_93 , sizeof( * V_92 ) , V_140 ) ;
if ( ! V_92 )
goto V_141;
for ( V_42 = 0 ; V_42 < V_93 ; V_42 ++ ) {
V_92 [ V_42 ] . V_3 = F_70 ( V_92 + V_42 ) ;
if ( ! V_92 [ V_42 ] . V_3 )
goto V_142;
}
V_91 = F_71 ( sizeof( * V_91 ) , V_140 ) ;
if ( ! V_91 )
goto V_142;
V_91 -> V_92 = V_92 ;
F_72 ( & V_91 -> V_143 ) ;
for ( V_42 = 0 ; V_42 < V_93 ; V_42 ++ ) {
struct V_1 * V_8 = V_92 + V_42 ;
struct V_2 * V_144 = F_3 ( V_8 ) ;
T_6 * V_145 = F_2 ( V_144 ) ;
V_144 -> V_12 = ( unsigned long ) V_58 ;
V_144 -> V_103 = V_36 -> V_103 ;
V_144 -> V_146 = & V_147 ;
V_144 -> V_148 = V_149 ;
F_73 ( V_144 , & V_36 -> V_3 ) ;
V_8 -> V_21 = V_42 ;
V_8 -> V_37 = V_91 ;
V_8 -> V_12 = V_58 ;
F_72 ( & V_8 -> V_143 ) ;
V_145 -> V_150 = V_151 ;
V_145 -> V_152 = V_153 ;
F_67 ( V_8 , V_144 ) ;
V_8 -> V_154 = V_155 ;
V_8 -> V_156 = V_157 ;
V_31 = F_74 ( V_144 ) ;
if ( V_31 < 0 )
goto V_158;
V_31 = F_75 ( V_144 ) ;
if ( V_31 < 0 ) {
F_53 ( L_17 ) ;
F_19 ( V_8 ) ;
goto V_158;
}
}
V_31 = F_68 ( V_92 , V_159 ) ;
if ( V_31 < 0 )
goto V_158;
F_47 ( V_36 , V_91 ) ;
return V_31 ;
V_158:
while ( V_42 -- > 0 ) {
F_19 ( V_92 + V_42 ) ;
F_46 ( F_3 ( V_92 + V_42 ) ) ;
}
F_49 ( V_91 ) ;
V_42 = V_93 ;
V_142:
while ( V_42 -- > 0 )
F_48 ( V_92 [ V_42 ] . V_3 ) ;
F_49 ( V_92 ) ;
V_141:
return V_31 ;
}
static void F_76 ( unsigned long V_46 )
{
struct V_2 * V_3 = (struct V_2 * ) V_46 ;
struct V_1 * V_8 = F_1 ( V_3 ) ;
goto V_56;
V_56:
V_8 -> V_160 . V_161 = V_162 + V_149 ;
F_77 ( & V_8 -> V_160 ) ;
}
static void F_78 ( struct V_2 * V_3 )
{
}
static int F_79 ( struct V_1 * V_8 )
{
T_7 * V_163 = & V_8 -> V_163 ;
if ( V_163 -> V_164 && ( V_163 -> V_165 != V_166 ) ) {
struct V_2 * V_3 = F_3 ( V_8 ) ;
F_80 ( V_3 , L_18 ) ;
return - 1 ;
}
return 0 ;
}
static void F_81 ( struct V_35 * V_36 , void T_3 * V_58 )
{
int V_42 ;
F_82 ( & V_167 ) ;
for ( V_42 = 0 ; V_42 < 16 ; V_42 ++ )
F_83 ( V_36 , V_42 << 2 , V_168 + V_42 ) ;
F_5 ( 0x001c0000 , V_58 + V_110 ) ;
F_5 ( 0x0000ffff , V_58 + V_169 ) ;
F_5 ( 0x0000ffff , V_58 + V_170 ) ;
F_5 ( 0x0000ffff , V_58 + V_171 ) ;
F_5 ( 0x00000000 , V_58 + V_171 ) ;
F_10 ( V_58 + V_61 ) ;
F_31 ( 10 ) ;
for ( V_42 = 0 ; V_42 < 16 ; V_42 ++ )
F_84 ( V_36 , V_42 << 2 , V_168 [ V_42 ] ) ;
F_85 ( & V_167 ) ;
}
static int F_86 ( struct V_2 * V_3 )
{
struct V_1 * V_8 = F_1 ( V_3 ) ;
struct V_90 * V_91 ;
int V_31 = - V_57 ;
if ( ( F_79 ( V_8 ) < 0 ) )
goto V_172;
if ( ( V_31 = F_87 ( V_3 ) ) )
goto V_172;
V_91 = V_8 -> V_37 ;
if ( V_8 -> V_67 & V_173 ) {
V_8 -> V_67 &= ~ V_173 ;
F_4 ( 0 , V_174 , V_8 , V_3 , V_130 ) ;
F_4 ( 0 , 0x00050000 , V_8 , V_3 , V_135 ) ;
F_7 ( V_175 , V_8 , V_3 , V_176 ) ;
F_80 ( V_3 , L_19 ) ;
goto V_56;
}
V_8 -> V_67 = V_68 | V_69 ;
F_4 ( 0 , V_174 | V_177 , V_8 , V_3 , V_130 ) ;
if ( F_9 ( V_8 , V_3 ) & V_55 ) {
F_33 ( V_3 , L_20 ) ;
V_31 = - V_57 ;
goto V_141;
} else
F_80 ( V_3 , L_21 ) ;
F_7 ( V_175 , V_8 , V_3 , V_176 ) ;
F_7 ( V_178 | V_179 , V_8 , V_3 , V_180 ) ;
if ( ( V_31 = F_30 ( V_8 , V_3 , L_22 ) ) < 0 )
goto V_181;
if ( ( V_31 = F_36 ( V_8 ) ) < 0 ) {
F_53 ( L_23 ) ;
goto V_181;
}
if ( V_32 > 2 )
F_18 ( V_3 , V_8 , L_24 ) ;
V_56:
F_88 ( V_3 ) ;
F_89 ( & V_8 -> V_160 ) ;
V_8 -> V_160 . V_161 = V_162 + 10 * V_182 ;
V_8 -> V_160 . V_46 = ( unsigned long ) V_3 ;
V_8 -> V_160 . V_183 = F_76 ;
F_77 ( & V_8 -> V_160 ) ;
F_90 ( V_3 ) ;
return 0 ;
V_181:
F_7 ( 0xffffffff , V_8 , V_3 , V_176 ) ;
F_4 ( V_174 | V_177 , 0 , V_8 , V_3 , V_130 ) ;
V_141:
F_91 ( V_3 ) ;
V_172:
return V_31 ;
}
static int F_92 ( struct V_1 * V_8 , struct V_2 * V_3 )
{
}
static T_8 V_151 ( struct V_40 * V_53 ,
struct V_2 * V_3 )
{
struct V_1 * V_8 = F_1 ( V_3 ) ;
struct V_90 * V_91 = V_8 -> V_37 ;
struct V_19 * V_38 ;
int V_184 ;
V_184 = V_8 -> V_17 % V_18 ;
V_8 -> V_45 [ V_184 ] = V_53 ;
V_38 = V_8 -> V_38 + V_184 ;
V_38 -> V_10 = V_185 | F_93 ( V_53 -> V_47 ) ;
V_38 -> V_46 = F_28 ( F_29 ( V_91 -> V_36 , V_53 -> V_46 , V_53 -> V_47 ,
V_48 ) ) ;
V_38 -> V_186 = 0x00000000 ;
V_38 -> V_162 = V_162 ;
F_94 () ;
#ifdef F_95
F_96 ( & V_8 -> V_143 ) ;
while ( F_92 ( V_8 , V_3 ) ) ;
F_97 ( & V_8 -> V_143 ) ;
#endif
if ( V_32 > 2 )
F_18 ( V_3 , V_8 , L_25 ) ;
if ( ! ( ( ++ V_8 -> V_17 - V_8 -> V_28 ) % V_18 ) )
F_98 ( V_3 ) ;
if ( F_14 ( V_8 , V_3 ) )
F_11 ( V_8 , V_3 ) ;
return V_187 ;
}
static int F_99 ( struct V_2 * V_3 )
{
struct V_1 * V_8 = F_1 ( V_3 ) ;
F_100 ( & V_8 -> V_160 ) ;
F_98 ( V_3 ) ;
F_4 ( V_174 | V_177 , 0 , V_8 , V_3 , V_130 ) ;
F_4 ( 0x00050000 , 0 , V_8 , V_3 , V_135 ) ;
F_7 ( 0xffffffff , V_8 , V_3 , V_176 ) ;
V_8 -> V_67 |= V_173 ;
F_91 ( V_3 ) ;
return 0 ;
}
static inline int F_101 ( int V_188 )
{
int V_31 = 0 ;
#ifdef F_102
if ( V_188 >= 2 )
V_31 = - 1 ;
#endif
return V_31 ;
}
static int F_103 ( struct V_2 * V_3 , T_1 * V_189 , T_1 * V_10 )
{
struct V_1 * V_8 = F_1 ( V_3 ) ;
int V_31 = - 1 ;
T_1 V_190 ;
* V_10 &= ~ V_191 ;
if ( * V_189 ) {
T_1 V_192 = 0 , V_193 = 0 , V_194 ;
int V_195 ;
V_195 = V_8 -> V_37 -> V_139 ;
if ( ! V_195 )
goto V_56;
if ( F_101 ( V_8 -> V_21 ) < 0 )
goto V_56;
V_194 = V_195 / * V_189 ;
if ( V_194 > V_196 ) {
V_194 >>= 4 ;
* V_10 |= 0x00000036 ;
} else
* V_10 |= 0x00000037 ;
if ( V_194 >> 22 ) {
V_192 = 63 ;
V_193 = 15 ;
} else if ( V_194 ) {
V_193 = 0 ;
while ( 0xffffffc0 & V_194 ) {
V_193 ++ ;
V_194 >>= 1 ;
}
V_192 = V_194 ;
}
V_190 = ( V_193 << 8 ) | V_192 ;
V_194 = V_192 << V_193 ;
if ( ! ( * V_10 & 0x00000001 ) )
V_194 <<= 4 ;
* V_189 = V_195 / V_194 ;
} else {
V_190 = 0 ;
}
F_7 ( V_190 , V_8 , V_3 , V_197 ) ;
V_31 = 0 ;
V_56:
return V_31 ;
}
static int F_104 ( struct V_2 * V_3 , struct V_198 * V_199 , int V_200 )
{
T_7 T_9 * line = V_199 -> V_201 . V_202 . V_203 ;
struct V_1 * V_8 = F_1 ( V_3 ) ;
const T_10 V_204 = sizeof( V_8 -> V_163 ) ;
int V_31 = 0 ;
if ( V_3 -> V_67 & V_205 )
return - V_206 ;
if ( V_200 != V_207 )
return - V_138 ;
switch( V_199 -> V_201 . type ) {
case V_208 :
V_199 -> V_201 . type = V_209 ;
if ( V_199 -> V_201 . V_204 < V_204 ) {
V_199 -> V_201 . V_204 = V_204 ;
return - V_210 ;
}
if ( F_105 ( line , & V_8 -> V_163 , V_204 ) )
return - V_211 ;
break;
case V_209 :
if ( ! F_106 ( V_212 ) )
return - V_213 ;
if ( V_8 -> V_67 & V_173 ) {
F_80 ( V_3 , L_26 ) ;
return - V_213 ;
}
if ( F_107 ( & V_8 -> V_163 , line , V_204 ) )
return - V_211 ;
V_31 = F_108 ( V_8 , V_3 ) ;
break;
default:
V_31 = F_109 ( V_3 , V_199 , V_200 ) ;
break;
}
return V_31 ;
}
static int F_110 ( const struct V_214 * V_5 , int V_7 )
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
static int F_111 ( struct V_1 * V_8 ,
struct V_2 * V_3 )
{
T_7 * V_163 = & V_8 -> V_163 ;
int V_31 = - V_138 ;
T_1 V_189 , V_10 ;
V_189 = V_163 -> V_215 ;
V_10 = F_8 ( V_8 , V_130 ) ;
if ( F_103 ( V_3 , & V_189 , & V_10 ) < 0 )
goto V_56;
if ( V_189 ) {
F_17 ( V_33 L_27 , V_3 -> V_34 ) ;
if ( V_163 -> V_215 != V_189 ) {
F_17 ( V_33 L_28 ,
V_3 -> V_34 , V_163 -> V_215 , V_189 ) ;
V_163 -> V_215 = V_189 ;
}
} else {
V_10 |= V_174 | V_177 ;
F_17 ( V_33 L_29 , V_3 -> V_34 ) ;
}
F_7 ( V_10 , V_8 , V_3 , V_130 ) ;
V_31 = 0 ;
V_56:
return V_31 ;
}
static int F_112 ( struct V_1 * V_8 ,
struct V_2 * V_3 )
{
static const struct V_214 V_156 [] = {
{ V_157 , 0x00000000 } ,
{ V_216 , 0x00200000 } ,
{ V_217 , 0x00400000 } ,
{ V_218 , 0x00500000 } ,
{ V_219 , 0x00600000 } ,
{ - 1 , 0 }
} ;
int V_42 , V_31 = 0 ;
V_42 = F_110 ( V_156 , V_8 -> V_156 ) ;
if ( V_42 >= 0 )
F_4 ( V_220 , V_156 [ V_42 ] . V_13 , V_8 , V_3 , V_130 ) ;
else
V_31 = - V_138 ;
return V_31 ;
}
static int F_113 ( struct V_1 * V_8 ,
struct V_2 * V_3 )
{
T_7 * V_163 = & V_8 -> V_163 ;
T_1 V_10 ;
V_10 = F_8 ( V_8 , V_133 ) ;
if ( V_163 -> V_164 ) {
F_17 ( V_33 L_30 , V_3 -> V_34 ) ;
V_10 |= 0x00000100 ;
} else {
F_17 ( V_33 L_31 , V_3 -> V_34 ) ;
V_10 &= ~ 0x00000100 ;
}
F_7 ( V_10 , V_8 , V_3 , V_133 ) ;
return 0 ;
}
static int F_114 ( struct V_1 * V_8 ,
struct V_2 * V_3 )
{
static const struct V_214 V_221 [] = {
{ V_155 , 0x00000010 } ,
{ V_222 , 0x00000000 } ,
{ V_223 , 0x00000011 } ,
{ V_224 , 0x00000001 }
} ;
int V_42 , V_31 = 0 ;
V_42 = F_110 ( V_221 , V_8 -> V_154 ) ;
if ( V_42 >= 0 )
F_4 ( V_225 , V_221 [ V_42 ] . V_13 , V_8 , V_3 , V_133 ) ;
else
V_31 = - V_138 ;
return V_31 ;
}
static int F_108 ( struct V_1 * V_8 , struct V_2 * V_3 )
{
struct {
int (* F_115)( struct V_1 * , struct V_2 * );
} * V_5 , V_226 [] = {
{ F_112 } ,
{ F_111 } ,
{ F_113 } ,
{ F_114 } ,
{ NULL }
} ;
int V_31 = 0 ;
for ( V_5 = V_226 ; V_5 -> F_115 ; V_5 ++ ) {
if ( ( V_31 = V_5 -> F_115 ( V_8 , V_3 ) ) < 0 )
break;
}
return V_31 ;
}
static T_11 V_106 ( int V_103 , void * V_227 )
{
struct V_1 * V_92 = V_227 ;
struct V_90 * V_4 ;
struct V_2 * V_3 ;
void T_3 * V_58 ;
T_1 V_10 ;
unsigned long V_67 ;
int V_42 , V_228 = 1 ;
V_4 = V_92 -> V_37 ;
V_3 = F_3 ( V_92 ) ;
F_116 ( & V_4 -> V_143 , V_67 ) ;
V_58 = V_92 -> V_12 ;
V_10 = F_10 ( V_58 + V_61 ) ;
if ( ! V_10 ) {
V_228 = 0 ;
goto V_98;
}
if ( V_32 > 3 )
F_17 ( V_33 L_32 , V_108 , V_10 ) ;
F_5 ( V_10 , V_58 + V_61 ) ;
if ( V_10 & V_63 ) {
F_33 ( V_3 , L_33 ) ;
goto V_98;
}
V_10 &= ~ V_62 ;
if ( V_10 & V_229 ) {
if ( V_32 > 0 )
F_17 ( V_33 L_34 , V_108 ) ;
if ( V_4 -> V_113 [ V_4 -> V_230 ++ % V_66 ] & F_28 ( V_63 ) )
F_33 ( V_3 , L_35 ) ;
if ( ! ( V_10 &= ~ V_229 ) )
goto V_98;
}
if ( V_10 & V_231 ) {
V_42 = V_93 - 1 ;
do {
F_117 ( V_4 , V_92 + V_42 ) ;
} while ( -- V_42 >= 0 );
V_10 &= ~ V_231 ;
}
if ( V_10 & V_232 ) {
V_42 = V_93 - 1 ;
do {
F_118 ( V_4 , V_92 + V_42 ) ;
} while ( -- V_42 >= 0 );
V_10 &= ~ V_232 ;
}
V_98:
F_119 ( & V_4 -> V_143 , V_67 ) ;
return F_120 ( V_228 ) ;
}
static void F_118 ( struct V_90 * V_91 ,
struct V_1 * V_8 )
{
struct V_2 * V_3 = F_3 ( V_8 ) ;
T_1 V_10 ;
int V_64 , V_233 = 0 ;
V_234:
V_64 = V_8 -> V_65 % V_66 ;
V_10 = F_22 ( V_8 -> V_70 [ V_64 ] ) ;
if ( ! V_10 ) {
if ( V_32 > 4 )
F_17 ( V_33 L_36 , V_3 -> V_34 ,
V_10 ) ;
if ( ( V_32 > 1 ) && ( V_233 > 1 ) )
F_17 ( V_33 L_37 , V_3 -> V_34 , V_233 ) ;
if ( V_233 && F_121 ( V_3 ) )
if ( ( V_8 -> V_17 - V_8 -> V_28 ) % V_18 )
F_122 ( V_3 ) ;
if ( F_41 ( V_3 ) && F_14 ( V_8 , V_3 ) &&
! F_13 ( V_8 ) )
F_11 ( V_8 , V_3 ) ;
return;
}
V_233 ++ ;
V_8 -> V_70 [ V_64 ] = 0 ;
V_8 -> V_65 ++ ;
if ( F_15 ( V_10 , V_8 , V_3 , L_38 ) < 0 )
return;
if ( V_10 & V_235 ) {
if ( V_10 & V_236 ) {
struct V_40 * V_53 ;
struct V_19 * V_38 ;
if ( V_32 > 2 )
F_18 ( V_3 , V_8 , L_39 ) ;
V_64 = V_8 -> V_28 % V_18 ;
V_38 = V_8 -> V_38 + V_64 ;
V_53 = V_8 -> V_45 [ V_64 ] ;
if ( V_53 ) {
F_21 ( V_91 -> V_36 , F_22 ( V_38 -> V_46 ) ,
V_53 -> V_47 , V_48 ) ;
if ( V_38 -> V_10 & V_185 ) {
V_3 -> V_78 . V_237 ++ ;
V_3 -> V_78 . V_238 += V_53 -> V_47 ;
}
F_43 ( V_53 ) ;
V_8 -> V_45 [ V_64 ] = NULL ;
++ V_8 -> V_28 ;
} else {
if ( V_32 > 1 )
F_33 ( V_3 , L_40 ,
V_64 ) ;
}
V_38 -> V_46 = V_38 -> V_184 ;
V_38 -> V_10 = V_185 | F_93 ( 2 * V_239 ) ;
V_38 -> V_186 = 0x00000000 ;
V_38 -> V_162 = 0 ;
if ( ! ( V_10 &= ~ V_236 ) )
goto V_234;
}
if ( V_10 & V_240 ) {
F_33 ( V_3 , L_41 ) ;
V_8 -> V_67 = V_69 ;
F_5 ( V_241 | V_242 ,
V_8 -> V_12 + 0x0c * V_8 -> V_21 + V_243 ) ;
F_5 ( V_59 , V_8 -> V_12 + V_60 ) ;
return;
}
if ( V_10 & V_244 ) {
F_80 ( V_3 , L_42 ) ;
if ( ! ( V_10 &= ~ V_244 ) )
goto V_234;
}
if ( V_10 & V_245 ) {
F_33 ( V_3 , L_43 ) ;
if ( ! ( V_10 &= ~ V_245 ) )
goto V_234;
}
if ( V_10 & V_71 ) {
void T_3 * V_246 ;
unsigned long V_247 ;
int V_42 ;
for ( V_42 = 1 ; V_42 ; V_42 <<= 1 ) {
if ( ! ( F_9 ( V_8 , V_3 ) & V_55 ) )
break;
}
if ( ! V_42 )
F_80 ( V_3 , L_44 ) ;
V_246 = V_8 -> V_12 + 0x0c * V_8 -> V_21 ;
if ( V_8 -> V_67 & V_69 ) {
if ( V_32 > 2 )
F_18 ( V_3 , V_8 , L_45 ) ;
V_247 = V_8 -> V_16 +
( V_8 -> V_28 % V_18 ) *
sizeof( struct V_19 ) ;
F_5 ( V_247 , V_246 + V_248 ) ;
F_11 ( V_8 , V_3 ) ;
F_5 ( V_241 | V_249 , V_246 + V_243 ) ;
if ( F_34 ( V_3 , L_46 ) < 0 )
goto V_250;
V_8 -> V_67 &= ~ V_69 ;
}
if ( V_8 -> V_67 & V_68 ) {
V_247 = V_8 -> V_23 +
( V_8 -> V_72 % V_25 ) *
sizeof( struct V_26 ) ;
F_5 ( V_247 , V_246 + V_251 ) ;
F_12 ( V_8 , V_3 ) ;
F_5 ( V_241 | V_252 , V_246 + V_243 ) ;
if ( F_34 ( V_3 , L_47 ) < 0 )
goto V_250;
V_8 -> V_67 &= ~ V_68 ;
F_123 () ;
F_7 ( 0x08050008 , V_8 , V_3 , V_135 ) ;
}
V_250:
if ( ! ( V_10 &= ~ V_71 ) )
goto V_234;
}
if ( V_10 & V_253 ) {
if ( V_32 > 0 )
F_80 ( V_3 , L_48 ) ;
if ( ! ( V_10 &= ~ V_253 ) )
goto V_234;
}
} else {
if ( V_10 & V_254 ) {
#ifdef F_95
while ( ! F_92 ( V_8 , V_3 ) ) ;
#endif
F_80 ( V_3 , L_49 ) ;
V_10 &= ~ V_254 ;
}
if ( V_10 & V_255 ) {
F_80 ( V_3 , L_50 ) ;
V_3 -> V_78 . V_256 ++ ;
V_10 &= ~ V_255 ;
}
}
goto V_234;
}
static void F_117 ( struct V_90 * V_4 ,
struct V_1 * V_8 )
{
struct V_2 * V_3 = F_3 ( V_8 ) ;
T_1 V_10 ;
int V_64 ;
V_234:
V_64 = V_8 -> V_257 % V_66 ;
V_10 = F_22 ( V_8 -> V_122 [ V_64 ] ) ;
if ( ! V_10 )
return;
V_8 -> V_122 [ V_64 ] = 0 ;
V_8 -> V_257 ++ ;
if ( F_15 ( V_10 , V_8 , V_3 , L_51 ) < 0 )
return;
if ( ! ( V_10 & V_235 ) ) {
struct V_26 * V_39 ;
if ( V_32 > 4 )
F_17 ( V_33 L_52 , V_3 -> V_34 ,
V_10 ) ;
V_10 &= 0x00ffffff ;
if ( V_10 & V_255 ) {
F_17 ( V_33 L_53 , V_3 -> V_34 ) ;
V_64 = V_8 -> V_72 % V_25 ;
V_39 = V_8 -> V_39 + V_64 ;
while ( ! ( V_39 -> V_258 & V_259 ) ) {
V_39 ++ ;
V_64 ++ ;
if ( ! ( V_64 = V_64 % V_25 ) )
V_39 = V_8 -> V_39 ;
}
F_25 ( V_8 , V_3 ) ;
if ( ! V_39 -> V_46 )
goto V_234;
V_39 -> V_258 &= ~ V_259 ;
V_39 -> V_76 = 0x00000000 ;
V_39 -> V_89 = F_28 ( 0xbabeface ) ;
goto V_234;
}
if ( V_10 & V_260 ) {
F_38 ( V_8 , V_3 ) ;
goto V_234;
}
if ( V_10 & V_254 ) {
F_80 ( V_3 , L_54 ) ;
V_10 &= ~ V_254 ;
goto V_234;
}
} else {
if ( V_32 > 1 ) {
static struct {
T_1 V_6 ;
const char * V_261 ;
} V_262 [] = {
{ 0x00008000 , L_55 } ,
{ 0x00000020 , L_56 } ,
{ 0x00000010 , L_57 } ,
{ 0x00000008 , L_58 } ,
{ 0 , NULL }
} , * V_263 ;
for ( V_263 = V_262 ; V_263 -> V_261 ; V_263 ++ ) {
if ( V_10 & V_263 -> V_6 ) {
F_17 ( V_33 L_59 ,
V_3 -> V_34 , V_263 -> V_261 ) ;
if ( ! ( V_10 &= ~ V_263 -> V_6 ) )
goto V_234;
}
}
} else {
if ( ! ( V_10 &= ~ 0x0000c03c ) )
goto V_234;
}
if ( V_10 & V_244 ) {
F_80 ( V_3 , L_42 ) ;
if ( ! ( V_10 &= ~ V_244 ) )
goto V_234;
}
if ( V_10 & V_264 ) {
struct V_26 * V_39 ;
void T_3 * V_246 ;
int V_64 ;
V_246 = V_8 -> V_12 + 0x0c * V_8 -> V_21 ;
F_4 ( V_134 , 0 , V_8 , V_3 , V_135 ) ;
F_7 ( V_179 , V_8 , V_3 , V_180 ) ;
V_8 -> V_67 |= V_265 ;
do {
V_64 = V_8 -> V_72 ++ % V_25 ;
V_39 = V_8 -> V_39 + V_64 ;
if ( ! ( V_39 -> V_76 & V_266 ) )
break;
if ( V_39 -> V_76 & V_267 ) {
V_3 -> V_78 . V_268 ++ ;
V_39 -> V_258 |= V_259 ;
V_39 -> V_76 = 0x00000000 ;
V_39 -> V_89 = F_28 ( 0xbabeface ) ;
} else
F_38 ( V_8 , V_3 ) ;
} while ( 1 );
if ( V_32 > 0 ) {
if ( V_8 -> V_67 & V_265 )
F_17 ( V_33
L_60 , V_108 ) ;
}
#ifdef F_124
#warning "FIXME: CH0BRDA"
F_5 ( V_8 -> V_23 +
( V_8 -> V_72 % V_25 ) *
sizeof( struct V_26 ) , V_246 + V_251 ) ;
F_5 ( V_241 | V_269 | V_252 , V_246 + V_243 ) ;
if ( F_34 ( V_3 , L_61 ) < 0 ) {
F_33 ( V_3 , L_62 ) ;
goto V_270;
}
F_5 ( V_241 | V_252 , V_246 + V_243 ) ;
if ( F_34 ( V_3 , L_47 ) < 0 ) {
F_33 ( V_3 , L_63 ) ;
goto V_270;
}
V_270:
#endif
F_4 ( 0 , V_134 , V_8 , V_3 , V_135 ) ;
goto V_234;
}
if ( V_10 & V_253 ) {
F_80 ( V_3 , L_48 ) ;
if ( ! ( V_10 &= ~ V_253 ) )
goto V_234;
}
if ( V_10 & V_271 ) {
F_17 ( V_33 L_64 , V_108 ) ;
if ( ! ( V_10 &= ~ V_271 ) )
goto V_234;
}
}
}
static struct V_40 * F_125 ( struct V_1 * V_8 )
{
struct V_40 * V_53 ;
V_53 = F_26 ( V_239 ) ;
if ( V_53 ) {
int V_272 = V_8 -> V_28 % V_18 ;
struct V_19 * V_38 = V_8 -> V_38 + V_272 ;
V_53 -> V_47 = V_239 ;
F_126 ( V_53 , V_97 ,
strlen ( V_97 ) % V_239 ) ;
V_38 -> V_10 = V_185 | F_93 ( V_239 ) ;
V_38 -> V_46 = F_28 ( F_29 ( V_8 -> V_37 -> V_36 ,
V_53 -> V_46 , V_239 ,
V_48 ) ) ;
V_8 -> V_45 [ V_272 ] = V_53 ;
}
return V_53 ;
}
static int F_74 ( struct V_2 * V_3 )
{
struct V_1 * V_8 = F_1 ( V_3 ) ;
struct V_35 * V_36 = V_8 -> V_37 -> V_36 ;
struct V_19 * V_38 ;
struct V_26 * V_39 ;
void * V_247 ;
int V_42 ;
V_247 = F_62 ( V_36 , V_44 , & V_8 -> V_23 ) ;
if ( ! V_247 )
goto V_141;
V_8 -> V_39 = V_39 = (struct V_26 * ) V_247 ;
V_247 = F_62 ( V_36 , V_43 , & V_8 -> V_16 ) ;
if ( ! V_247 )
goto V_273;
V_8 -> V_38 = V_38 = (struct V_19 * ) V_247 ;
memset ( V_8 -> V_45 , 0 , sizeof( struct V_40 * ) * V_18 ) ;
V_8 -> V_28 = 0xffffffff ;
V_42 = V_8 -> V_17 = 0 ;
do {
V_38 -> V_10 = V_185 | F_93 ( 2 * V_239 ) ;
V_38 -> V_186 = 0x00000000 ;
V_38 -> V_46 = F_28 ( V_8 -> V_16 ) ;
( V_38 ++ ) -> V_184 = F_28 ( V_8 -> V_16 +
( ++ V_42 % V_18 ) * sizeof( * V_38 ) ) ;
} while ( V_42 < V_18 );
if ( ! F_125 ( V_8 ) )
goto V_274;
memset ( V_8 -> V_49 , 0 , sizeof( struct V_40 * ) * V_25 ) ;
V_42 = V_8 -> V_24 = V_8 -> V_72 = 0 ;
do {
V_39 -> V_258 = V_275 ;
V_39 -> V_76 = 0x00000000 ;
V_39 -> V_89 = F_28 ( 0xbabeface ) ;
V_39 -> V_258 |= F_127 ( V_50 ) ;
if ( F_25 ( V_8 , V_3 ) >= 0 )
V_8 -> V_24 ++ ;
( V_39 ++ ) -> V_184 = F_28 ( V_8 -> V_23 +
( ++ V_42 % V_25 ) * sizeof( * V_39 ) ) ;
} while ( V_42 < V_25 );
return 0 ;
V_274:
F_20 ( V_36 , V_43 , V_247 , V_8 -> V_16 ) ;
V_273:
F_20 ( V_36 , V_44 , V_39 , V_8 -> V_23 ) ;
V_141:
return - V_118 ;
}
static void T_12 F_128 ( struct V_35 * V_36 )
{
struct V_90 * V_91 ;
struct V_1 * V_92 ;
void T_3 * V_58 ;
int V_42 ;
V_91 = F_45 ( V_36 ) ;
V_92 = V_91 -> V_92 ;
V_58 = V_92 -> V_12 ;
F_81 ( V_36 , V_58 ) ;
F_63 ( V_36 -> V_103 , V_92 ) ;
F_20 ( V_36 , V_66 * sizeof( T_1 ) , V_91 -> V_113 ,
V_91 -> V_115 ) ;
for ( V_42 = 0 ; V_42 < V_93 ; V_42 ++ ) {
struct V_1 * V_8 = V_92 + V_42 ;
F_19 ( V_8 ) ;
F_20 ( V_36 , V_66 * sizeof( T_1 ) ,
V_8 -> V_122 , V_8 -> V_123 ) ;
F_20 ( V_36 , V_66 * sizeof( T_1 ) ,
V_8 -> V_70 , V_8 -> V_119 ) ;
}
F_44 ( V_36 ) ;
F_64 ( V_58 ) ;
F_65 ( V_36 , 1 ) ;
F_65 ( V_36 , 0 ) ;
F_66 ( V_36 ) ;
}
static int V_153 ( struct V_2 * V_3 , unsigned short V_156 ,
unsigned short V_154 )
{
struct V_1 * V_8 = F_1 ( V_3 ) ;
if ( V_156 != V_157 &&
V_156 != V_216 &&
V_156 != V_217 &&
V_156 != V_218 &&
V_156 != V_219 )
return - V_276 ;
if ( V_154 != V_277 &&
V_154 != V_155 &&
V_154 != V_222 &&
V_154 != V_223 &&
V_154 != V_224 )
return - V_276 ;
V_8 -> V_156 = V_156 ;
V_8 -> V_154 = V_154 ;
return 0 ;
}
static int T_13 F_129 ( char * V_278 )
{
int * args [] = { & V_32 , & V_159 , NULL } , * * V_5 = args ;
while ( * V_5 && ( F_130 ( & V_278 , * V_5 ) == 2 ) )
V_5 ++ ;
return 1 ;
}
static int T_13 F_131 ( void )
{
return F_132 ( & V_279 ) ;
}
static void T_14 F_133 ( void )
{
F_134 ( & V_279 ) ;
}
