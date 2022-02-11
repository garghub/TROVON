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
struct V_35 * V_36 = & V_8 -> V_37 -> V_38 -> V_3 ;
struct V_19 * V_39 = V_8 -> V_39 ;
struct V_26 * V_40 = V_8 -> V_40 ;
struct V_41 * * V_42 ;
int V_43 ;
F_20 ( V_36 , V_44 , V_39 , V_8 -> V_16 ) ;
F_20 ( V_36 , V_45 , V_40 , V_8 -> V_23 ) ;
V_42 = V_8 -> V_46 ;
for ( V_43 = 0 ; V_43 < V_18 ; V_43 ++ ) {
if ( * V_42 ) {
F_21 ( V_36 , F_22 ( V_39 -> V_47 ) ,
( * V_42 ) -> V_48 , V_49 ) ;
F_23 ( * V_42 ) ;
}
V_42 ++ ;
V_39 ++ ;
}
V_42 = V_8 -> V_50 ;
for ( V_43 = 0 ; V_43 < V_25 ; V_43 ++ ) {
if ( * V_42 ) {
F_21 ( V_36 , F_22 ( V_40 -> V_47 ) ,
F_24 ( V_51 ) ,
V_52 ) ;
F_23 ( * V_42 ) ;
}
V_42 ++ ;
V_40 ++ ;
}
}
static inline int F_25 ( struct V_1 * V_8 ,
struct V_2 * V_3 )
{
unsigned int V_53 = V_8 -> V_24 % V_25 ;
struct V_35 * V_36 = & V_8 -> V_37 -> V_38 -> V_3 ;
struct V_26 * V_40 = V_8 -> V_40 + V_53 ;
const int V_48 = F_24 ( V_51 ) ;
struct V_41 * V_54 ;
T_2 V_55 ;
V_54 = F_26 ( V_48 ) ;
if ( ! V_54 )
goto V_56;
V_54 -> V_57 = F_27 ( V_54 , V_3 ) ;
V_55 = F_28 ( V_36 , V_54 -> V_47 , V_48 , V_52 ) ;
if ( F_29 ( V_36 , V_55 ) )
goto V_58;
V_8 -> V_50 [ V_53 ] = V_54 ;
V_40 -> V_47 = F_30 ( V_55 ) ;
return 0 ;
V_58:
F_31 ( V_54 ) ;
V_56:
V_40 -> V_47 = 0 ;
return - 1 ;
}
static int F_32 ( struct V_1 * V_8 ,
struct V_2 * V_3 , char * V_30 )
{
T_3 V_43 = 0 ;
do {
if ( ! ( F_9 ( V_8 , V_3 ) & V_59 ) ) {
F_17 ( V_33 L_4 , V_3 -> V_34 ,
V_30 , V_43 ) ;
goto V_60;
}
F_33 ( F_34 ( 100 ) ) ;
F_35 () ;
} while ( ++ V_43 > 0 );
F_36 ( V_3 , L_5 , V_30 ) ;
V_60:
return ( V_43 >= 0 ) ? V_43 : - V_61 ;
}
static int F_37 ( struct V_2 * V_3 , char * V_30 )
{
void T_4 * V_62 = F_1 ( V_3 ) -> V_12 ;
T_5 V_43 = 0 ;
F_5 ( V_63 , V_62 + V_64 ) ;
V_62 += V_65 ;
do {
T_1 V_10 = F_10 ( V_62 ) ;
if ( V_10 & V_66 ) {
F_38 ( V_3 , L_6 , V_30 ) ;
F_5 ( V_66 , V_62 ) ;
goto V_60;
} else if ( V_10 & V_67 ) {
F_36 ( V_3 , L_7 , V_30 ) ;
F_5 ( V_67 , V_62 ) ;
V_43 = - 1 ;
goto V_60;
}
F_35 () ;
} while ( ++ V_43 > 0 );
F_36 ( V_3 , L_5 , V_30 ) ;
V_60:
return V_43 ;
}
static inline int F_39 ( struct V_1 * V_8 )
{
int V_68 = V_8 -> V_69 % V_70 ;
T_3 V_43 = 0 ;
do {
if ( ! ( V_8 -> V_71 & ( V_72 | V_73 ) ) ||
( V_8 -> V_74 [ V_68 ] & F_30 ( V_75 ) ) )
break;
F_40 () ;
F_33 ( F_34 ( 100 ) ) ;
} while ( ++ V_43 > 0 );
return ( V_43 >= 0 ) ? V_43 : - V_61 ;
}
static inline void F_41 ( struct V_1 * V_8 ,
struct V_2 * V_3 )
{
struct V_26 * V_40 = V_8 -> V_40 + V_8 -> V_76 % V_25 ;
struct V_35 * V_36 = & V_8 -> V_37 -> V_38 -> V_3 ;
struct V_41 * V_54 ;
int V_77 ;
V_54 = V_8 -> V_50 [ V_8 -> V_76 ++ % V_25 ] ;
if ( ! V_54 ) {
F_17 ( V_33 L_8 , V_3 -> V_34 , V_78 ) ;
goto V_79;
}
V_77 = F_42 ( F_22 ( V_40 -> V_80 ) ) ;
F_21 ( V_36 , F_22 ( V_40 -> V_47 ) ,
F_24 ( V_51 ) , V_52 ) ;
if ( ( V_54 -> V_47 [ -- V_77 ] & V_81 ) == V_81 ) {
V_3 -> V_82 . V_83 ++ ;
V_3 -> V_82 . V_84 += V_77 ;
F_43 ( V_54 , V_77 ) ;
if ( F_44 ( V_3 ) )
V_54 -> V_57 = F_27 ( V_54 , V_3 ) ;
F_45 ( V_54 ) ;
} else {
if ( V_54 -> V_47 [ V_77 ] & V_85 )
V_3 -> V_82 . V_86 ++ ;
else if ( ! ( V_54 -> V_47 [ V_77 ] & V_87 ) )
V_3 -> V_82 . V_88 ++ ;
else if ( ( V_54 -> V_47 [ V_77 ] & ( V_89 | V_90 ) ) !=
( V_89 | V_90 ) )
V_3 -> V_82 . V_91 ++ ;
V_3 -> V_82 . V_92 ++ ;
F_46 ( V_54 ) ;
}
V_79:
while ( ( V_8 -> V_24 - V_8 -> V_76 ) % V_25 ) {
if ( F_25 ( V_8 , V_3 ) < 0 )
break;
V_8 -> V_24 ++ ;
}
F_12 ( V_8 , V_3 ) ;
V_40 -> V_80 = 0x00000000 ;
V_40 -> V_93 = F_30 ( 0xbabeface ) ;
}
static void F_47 ( struct V_94 * V_38 )
{
struct V_95 * V_96 ;
struct V_1 * V_97 ;
int V_43 ;
V_96 = F_48 ( V_38 ) ;
V_97 = V_96 -> V_97 ;
for ( V_43 = 0 ; V_43 < V_98 ; V_43 ++ )
F_49 ( F_3 ( V_97 + V_43 ) ) ;
for ( V_43 = 0 ; V_43 < V_98 ; V_43 ++ )
F_50 ( V_97 [ V_43 ] . V_3 ) ;
F_51 ( V_97 ) ;
F_51 ( V_96 ) ;
}
static int F_52 ( struct V_94 * V_38 , const struct V_99 * V_100 )
{
struct V_95 * V_4 ;
struct V_1 * V_8 ;
void T_4 * V_62 ;
int V_43 , V_101 ;
F_17 ( V_33 L_9 , V_102 ) ;
V_101 = F_53 ( V_38 ) ;
if ( V_101 < 0 )
goto V_103;
V_101 = F_54 ( V_38 , 0 , L_10 ) ;
if ( V_101 < 0 ) {
F_55 ( L_11 ) ;
goto V_104;
}
V_101 = F_54 ( V_38 , 1 , L_12 ) ;
if ( V_101 < 0 ) {
F_55 ( L_13 ) ;
goto V_105;
}
V_62 = F_56 ( V_38 , 0 ) ;
if ( ! V_62 ) {
F_55 ( L_14 ,
( unsigned long long ) F_57 ( V_38 , 0 ) ,
( unsigned long long ) F_58 ( V_38 , 0 ) ) ;
V_101 = - V_106 ;
goto V_107;
}
F_17 ( V_33 L_15 ,
( unsigned long long ) F_58 ( V_38 , 0 ) ,
( unsigned long long ) F_58 ( V_38 , 1 ) , V_38 -> V_108 ) ;
F_59 ( V_38 , V_109 , 0xf8 ) ;
F_60 ( V_38 ) ;
V_101 = F_61 ( V_38 , V_62 ) ;
if ( V_101 < 0 )
goto V_110;
V_4 = F_48 ( V_38 ) ;
V_101 = F_62 ( V_38 -> V_108 , V_111 , V_112 , V_113 , V_4 -> V_97 ) ;
if ( V_101 < 0 ) {
F_63 ( L_16 , V_38 -> V_108 ) ;
goto V_114;
}
F_5 ( 0x00000001 , V_62 + V_115 ) ;
{
T_1 V_13 ;
V_13 = ( V_70 >> 5 ) - 1 ;
V_13 |= V_13 << 4 ;
V_13 |= V_13 << 8 ;
V_13 |= V_13 << 16 ;
F_5 ( V_13 , V_62 + V_116 ) ;
}
F_5 ( ( T_1 ) ( ( ( V_70 >> 5 ) - 1 ) << 20 ) , V_62 + V_117 ) ;
V_101 = - V_118 ;
V_4 -> V_119 = ( V_120 * ) F_64 ( & V_38 -> V_3 ,
V_70 * sizeof( V_120 ) , & V_4 -> V_121 , V_122 ) ;
if ( ! V_4 -> V_119 )
goto V_123;
F_5 ( V_4 -> V_121 , V_62 + V_124 ) ;
for ( V_43 = 0 ; V_43 < V_98 ; V_43 ++ ) {
V_8 = V_4 -> V_97 + V_43 ;
V_8 -> V_74 = ( V_120 * ) F_64 ( & V_38 -> V_3 ,
V_70 * sizeof( T_1 ) , & V_8 -> V_125 ,
V_122 ) ;
if ( ! V_8 -> V_74 )
goto V_126;
F_5 ( V_8 -> V_125 , V_62 + V_127 + V_43 * 4 ) ;
}
for ( V_43 = 0 ; V_43 < V_98 ; V_43 ++ ) {
V_8 = V_4 -> V_97 + V_43 ;
V_8 -> V_128 = ( V_120 * ) F_64 ( & V_38 -> V_3 ,
V_70 * sizeof( T_1 ) , & V_8 -> V_129 ,
V_122 ) ;
if ( ! V_8 -> V_128 )
goto V_130;
F_5 ( V_8 -> V_129 , V_62 + V_131 + V_43 * 4 ) ;
}
F_5 ( 0x42104000 , V_62 + V_132 ) ;
F_5 ( 0xdef6d800 , V_62 + V_133 ) ;
F_5 ( 0x18181818 , V_62 + V_134 ) ;
F_5 ( 0x0000000e , V_62 + V_135 ) ;
F_5 ( 0xff200001 , V_62 + V_64 ) ;
V_101 = 0 ;
V_103:
return V_101 ;
V_130:
while ( -- V_43 >= 0 ) {
V_8 = V_4 -> V_97 + V_43 ;
F_20 ( & V_38 -> V_3 , V_70 * sizeof( T_1 ) ,
V_8 -> V_128 , V_8 -> V_129 ) ;
}
V_43 = V_98 ;
V_126:
while ( -- V_43 >= 0 ) {
V_8 = V_4 -> V_97 + V_43 ;
F_20 ( & V_38 -> V_3 , V_70 * sizeof( T_1 ) ,
V_8 -> V_74 , V_8 -> V_125 ) ;
}
F_20 ( & V_38 -> V_3 , V_70 * sizeof( T_1 ) , V_4 -> V_119 ,
V_4 -> V_121 ) ;
V_123:
F_65 ( V_38 -> V_108 , V_4 -> V_97 ) ;
V_114:
F_47 ( V_38 ) ;
V_110:
F_66 ( V_62 ) ;
V_107:
F_67 ( V_38 , 1 ) ;
V_105:
F_67 ( V_38 , 0 ) ;
V_104:
F_68 ( V_38 ) ;
goto V_103;
}
static void F_69 ( struct V_1 * V_8 ,
struct V_2 * V_3 )
{
F_7 ( 0x00000000 , V_8 , V_3 , V_136 ) ;
F_7 ( V_137 | ( V_51 >> 5 ) , V_8 , V_3 , V_138 ) ;
F_7 ( 0x02408000 , V_8 , V_3 , V_139 ) ;
F_7 ( 0x00050008 & ~ V_140 , V_8 , V_3 , V_141 ) ;
}
static inline int F_70 ( struct V_1 * V_8 , int V_142 )
{
int V_31 = 0 ;
if ( ( V_142 < 0 ) || ( V_142 > V_143 ) )
V_31 = - V_144 ;
else
V_8 -> V_37 -> V_145 = V_142 ;
return V_31 ;
}
static int F_61 ( struct V_94 * V_38 , void T_4 * V_62 )
{
struct V_95 * V_96 ;
struct V_1 * V_97 ;
int V_43 , V_31 = - V_118 ;
V_97 = F_71 ( V_98 , sizeof( * V_97 ) , V_122 ) ;
if ( ! V_97 )
goto V_56;
for ( V_43 = 0 ; V_43 < V_98 ; V_43 ++ ) {
V_97 [ V_43 ] . V_3 = F_72 ( V_97 + V_43 ) ;
if ( ! V_97 [ V_43 ] . V_3 )
goto V_146;
}
V_96 = F_73 ( sizeof( * V_96 ) , V_122 ) ;
if ( ! V_96 )
goto V_146;
V_96 -> V_97 = V_97 ;
F_74 ( & V_96 -> V_147 ) ;
for ( V_43 = 0 ; V_43 < V_98 ; V_43 ++ ) {
struct V_1 * V_8 = V_97 + V_43 ;
struct V_2 * V_36 = F_3 ( V_8 ) ;
T_6 * V_148 = F_2 ( V_36 ) ;
V_36 -> V_12 = ( unsigned long ) V_62 ;
V_36 -> V_108 = V_38 -> V_108 ;
V_36 -> V_149 = & V_150 ;
V_36 -> V_151 = V_152 ;
F_75 ( V_36 , & V_38 -> V_3 ) ;
V_8 -> V_21 = V_43 ;
V_8 -> V_37 = V_96 ;
V_8 -> V_12 = V_62 ;
F_74 ( & V_8 -> V_147 ) ;
V_148 -> V_153 = V_154 ;
V_148 -> V_155 = V_156 ;
F_69 ( V_8 , V_36 ) ;
V_8 -> V_157 = V_158 ;
V_8 -> V_159 = V_160 ;
V_31 = F_76 ( V_36 ) ;
if ( V_31 < 0 )
goto V_161;
V_31 = F_77 ( V_36 ) ;
if ( V_31 < 0 ) {
F_55 ( L_17 ) ;
F_19 ( V_8 ) ;
goto V_161;
}
}
V_31 = F_70 ( V_97 , V_162 ) ;
if ( V_31 < 0 )
goto V_161;
F_78 ( V_38 , V_96 ) ;
return V_31 ;
V_161:
while ( V_43 -- > 0 ) {
F_19 ( V_97 + V_43 ) ;
F_49 ( F_3 ( V_97 + V_43 ) ) ;
}
F_51 ( V_96 ) ;
V_43 = V_98 ;
V_146:
while ( V_43 -- > 0 )
F_50 ( V_97 [ V_43 ] . V_3 ) ;
F_51 ( V_97 ) ;
V_56:
return V_31 ;
}
static void F_79 ( unsigned long V_47 )
{
struct V_2 * V_3 = (struct V_2 * ) V_47 ;
struct V_1 * V_8 = F_1 ( V_3 ) ;
goto V_60;
V_60:
V_8 -> V_163 . V_164 = V_165 + V_152 ;
F_80 ( & V_8 -> V_163 ) ;
}
static void F_81 ( struct V_2 * V_3 )
{
}
static int F_82 ( struct V_1 * V_8 )
{
T_7 * V_166 = & V_8 -> V_166 ;
if ( V_166 -> V_167 && ( V_166 -> V_168 != V_169 ) ) {
struct V_2 * V_3 = F_3 ( V_8 ) ;
F_83 ( V_3 , L_18 ) ;
return - 1 ;
}
return 0 ;
}
static void F_84 ( struct V_94 * V_38 , void T_4 * V_62 )
{
int V_43 ;
F_85 ( & V_170 ) ;
for ( V_43 = 0 ; V_43 < 16 ; V_43 ++ )
F_86 ( V_38 , V_43 << 2 , V_171 + V_43 ) ;
F_5 ( 0x001c0000 , V_62 + V_115 ) ;
F_5 ( 0x0000ffff , V_62 + V_172 ) ;
F_5 ( 0x0000ffff , V_62 + V_173 ) ;
F_5 ( 0x0000ffff , V_62 + V_174 ) ;
F_5 ( 0x00000000 , V_62 + V_174 ) ;
F_10 ( V_62 + V_65 ) ;
F_33 ( F_34 ( 100 ) ) ;
for ( V_43 = 0 ; V_43 < 16 ; V_43 ++ )
F_87 ( V_38 , V_43 << 2 , V_171 [ V_43 ] ) ;
F_88 ( & V_170 ) ;
}
static int F_89 ( struct V_2 * V_3 )
{
struct V_1 * V_8 = F_1 ( V_3 ) ;
int V_31 = - V_61 ;
if ( ( F_82 ( V_8 ) < 0 ) )
goto V_175;
if ( ( V_31 = F_90 ( V_3 ) ) )
goto V_175;
if ( V_8 -> V_71 & V_176 ) {
V_8 -> V_71 &= ~ V_176 ;
F_4 ( 0 , V_177 , V_8 , V_3 , V_136 ) ;
F_4 ( 0 , 0x00050000 , V_8 , V_3 , V_141 ) ;
F_7 ( V_178 , V_8 , V_3 , V_179 ) ;
F_83 ( V_3 , L_19 ) ;
goto V_60;
}
V_8 -> V_71 = V_72 | V_73 ;
F_4 ( 0 , V_177 | V_180 , V_8 , V_3 , V_136 ) ;
if ( F_9 ( V_8 , V_3 ) & V_59 ) {
F_36 ( V_3 , L_20 ) ;
V_31 = - V_61 ;
goto V_56;
} else
F_83 ( V_3 , L_21 ) ;
F_7 ( V_178 , V_8 , V_3 , V_179 ) ;
F_7 ( V_181 | V_182 , V_8 , V_3 , V_183 ) ;
if ( ( V_31 = F_32 ( V_8 , V_3 , L_22 ) ) < 0 )
goto V_184;
if ( ( V_31 = F_39 ( V_8 ) ) < 0 ) {
F_55 ( L_23 ) ;
goto V_184;
}
if ( V_32 > 2 )
F_18 ( V_3 , V_8 , L_24 ) ;
V_60:
F_91 ( V_3 ) ;
F_92 ( & V_8 -> V_163 ) ;
V_8 -> V_163 . V_164 = V_165 + 10 * V_185 ;
V_8 -> V_163 . V_47 = ( unsigned long ) V_3 ;
V_8 -> V_163 . V_186 = F_79 ;
F_80 ( & V_8 -> V_163 ) ;
F_93 ( V_3 ) ;
return 0 ;
V_184:
F_7 ( 0xffffffff , V_8 , V_3 , V_179 ) ;
F_4 ( V_177 | V_180 , 0 , V_8 , V_3 , V_136 ) ;
V_56:
F_94 ( V_3 ) ;
V_175:
return V_31 ;
}
static int F_95 ( struct V_1 * V_8 , struct V_2 * V_3 )
{
}
static T_8 V_154 ( struct V_41 * V_54 ,
struct V_2 * V_3 )
{
struct V_1 * V_8 = F_1 ( V_3 ) ;
struct V_35 * V_36 = & V_8 -> V_37 -> V_38 -> V_3 ;
struct V_19 * V_39 ;
T_2 V_55 ;
int V_187 ;
V_55 = F_28 ( V_36 , V_54 -> V_47 , V_54 -> V_48 , V_49 ) ;
if ( F_29 ( V_36 , V_55 ) ) {
F_31 ( V_54 ) ;
V_3 -> V_82 . V_188 ++ ;
return V_189 ;
}
V_187 = V_8 -> V_17 % V_18 ;
V_8 -> V_46 [ V_187 ] = V_54 ;
V_39 = V_8 -> V_39 + V_187 ;
V_39 -> V_10 = V_190 | F_96 ( V_54 -> V_48 ) ;
V_39 -> V_47 = F_30 ( V_55 ) ;
V_39 -> V_191 = 0x00000000 ;
V_39 -> V_165 = V_165 ;
F_97 () ;
#ifdef F_98
F_99 ( & V_8 -> V_147 ) ;
while ( F_95 ( V_8 , V_3 ) ) ;
F_100 ( & V_8 -> V_147 ) ;
#endif
if ( V_32 > 2 )
F_18 ( V_3 , V_8 , L_25 ) ;
if ( ! ( ( ++ V_8 -> V_17 - V_8 -> V_28 ) % V_18 ) )
F_101 ( V_3 ) ;
if ( F_14 ( V_8 , V_3 ) )
F_11 ( V_8 , V_3 ) ;
return V_189 ;
}
static int F_102 ( struct V_2 * V_3 )
{
struct V_1 * V_8 = F_1 ( V_3 ) ;
F_103 ( & V_8 -> V_163 ) ;
F_101 ( V_3 ) ;
F_4 ( V_177 | V_180 , 0 , V_8 , V_3 , V_136 ) ;
F_4 ( 0x00050000 , 0 , V_8 , V_3 , V_141 ) ;
F_7 ( 0xffffffff , V_8 , V_3 , V_179 ) ;
V_8 -> V_71 |= V_176 ;
F_94 ( V_3 ) ;
return 0 ;
}
static inline int F_104 ( int V_192 )
{
int V_31 = 0 ;
#ifdef F_105
if ( V_192 >= 2 )
V_31 = - 1 ;
#endif
return V_31 ;
}
static int F_106 ( struct V_2 * V_3 , T_1 * V_193 , T_1 * V_10 )
{
struct V_1 * V_8 = F_1 ( V_3 ) ;
int V_31 = - 1 ;
T_1 V_194 ;
* V_10 &= ~ V_195 ;
if ( * V_193 ) {
T_1 V_196 = 0 , V_197 = 0 , V_198 ;
int V_199 ;
V_199 = V_8 -> V_37 -> V_145 ;
if ( ! V_199 )
goto V_60;
if ( F_104 ( V_8 -> V_21 ) < 0 )
goto V_60;
V_198 = V_199 / * V_193 ;
if ( V_198 > V_200 ) {
V_198 >>= 4 ;
* V_10 |= 0x00000036 ;
} else
* V_10 |= 0x00000037 ;
if ( V_198 >> 22 ) {
V_196 = 63 ;
V_197 = 15 ;
} else if ( V_198 ) {
V_197 = 0 ;
while ( 0xffffffc0 & V_198 ) {
V_197 ++ ;
V_198 >>= 1 ;
}
V_196 = V_198 ;
}
V_194 = ( V_197 << 8 ) | V_196 ;
V_198 = V_196 << V_197 ;
if ( ! ( * V_10 & 0x00000001 ) )
V_198 <<= 4 ;
* V_193 = V_199 / V_198 ;
} else {
V_194 = 0 ;
}
F_7 ( V_194 , V_8 , V_3 , V_201 ) ;
V_31 = 0 ;
V_60:
return V_31 ;
}
static int F_107 ( struct V_2 * V_3 , struct V_202 * V_203 , int V_204 )
{
T_7 T_9 * line = V_203 -> V_205 . V_206 . V_207 ;
struct V_1 * V_8 = F_1 ( V_3 ) ;
const T_10 V_208 = sizeof( V_8 -> V_166 ) ;
int V_31 = 0 ;
if ( V_3 -> V_71 & V_209 )
return - V_210 ;
if ( V_204 != V_211 )
return - V_144 ;
switch( V_203 -> V_205 . type ) {
case V_212 :
V_203 -> V_205 . type = V_213 ;
if ( V_203 -> V_205 . V_208 < V_208 ) {
V_203 -> V_205 . V_208 = V_208 ;
return - V_214 ;
}
if ( F_108 ( line , & V_8 -> V_166 , V_208 ) )
return - V_215 ;
break;
case V_213 :
if ( ! F_109 ( V_216 ) )
return - V_217 ;
if ( V_8 -> V_71 & V_176 ) {
F_83 ( V_3 , L_26 ) ;
return - V_217 ;
}
if ( F_110 ( & V_8 -> V_166 , line , V_208 ) )
return - V_215 ;
V_31 = F_111 ( V_8 , V_3 ) ;
break;
default:
V_31 = F_112 ( V_3 , V_203 , V_204 ) ;
break;
}
return V_31 ;
}
static int F_113 ( const struct V_218 * V_5 , int V_7 )
{
int V_43 ;
for ( V_43 = 0 ; V_5 [ V_43 ] . define != - 1 ; V_43 ++ ) {
if ( V_7 == V_5 [ V_43 ] . define )
break;
}
if ( V_5 [ V_43 ] . define == - 1 )
return - 1 ;
else
return V_43 ;
}
static int F_114 ( struct V_1 * V_8 ,
struct V_2 * V_3 )
{
T_7 * V_166 = & V_8 -> V_166 ;
int V_31 = - V_144 ;
T_1 V_193 , V_10 ;
V_193 = V_166 -> V_219 ;
V_10 = F_8 ( V_8 , V_136 ) ;
if ( F_106 ( V_3 , & V_193 , & V_10 ) < 0 )
goto V_60;
if ( V_193 ) {
F_17 ( V_33 L_27 , V_3 -> V_34 ) ;
if ( V_166 -> V_219 != V_193 ) {
F_17 ( V_33 L_28 ,
V_3 -> V_34 , V_166 -> V_219 , V_193 ) ;
V_166 -> V_219 = V_193 ;
}
} else {
V_10 |= V_177 | V_180 ;
F_17 ( V_33 L_29 , V_3 -> V_34 ) ;
}
F_7 ( V_10 , V_8 , V_3 , V_136 ) ;
V_31 = 0 ;
V_60:
return V_31 ;
}
static int F_115 ( struct V_1 * V_8 ,
struct V_2 * V_3 )
{
static const struct V_218 V_159 [] = {
{ V_160 , 0x00000000 } ,
{ V_220 , 0x00200000 } ,
{ V_221 , 0x00400000 } ,
{ V_222 , 0x00500000 } ,
{ V_223 , 0x00600000 } ,
{ - 1 , 0 }
} ;
int V_43 , V_31 = 0 ;
V_43 = F_113 ( V_159 , V_8 -> V_159 ) ;
if ( V_43 >= 0 )
F_4 ( V_224 , V_159 [ V_43 ] . V_13 , V_8 , V_3 , V_136 ) ;
else
V_31 = - V_144 ;
return V_31 ;
}
static int F_116 ( struct V_1 * V_8 ,
struct V_2 * V_3 )
{
T_7 * V_166 = & V_8 -> V_166 ;
T_1 V_10 ;
V_10 = F_8 ( V_8 , V_139 ) ;
if ( V_166 -> V_167 ) {
F_17 ( V_33 L_30 , V_3 -> V_34 ) ;
V_10 |= 0x00000100 ;
} else {
F_17 ( V_33 L_31 , V_3 -> V_34 ) ;
V_10 &= ~ 0x00000100 ;
}
F_7 ( V_10 , V_8 , V_3 , V_139 ) ;
return 0 ;
}
static int F_117 ( struct V_1 * V_8 ,
struct V_2 * V_3 )
{
static const struct V_218 V_225 [] = {
{ V_158 , 0x00000010 } ,
{ V_226 , 0x00000000 } ,
{ V_227 , 0x00000011 } ,
{ V_228 , 0x00000001 }
} ;
int V_43 , V_31 = 0 ;
V_43 = F_113 ( V_225 , V_8 -> V_157 ) ;
if ( V_43 >= 0 )
F_4 ( V_229 , V_225 [ V_43 ] . V_13 , V_8 , V_3 , V_139 ) ;
else
V_31 = - V_144 ;
return V_31 ;
}
static int F_111 ( struct V_1 * V_8 , struct V_2 * V_3 )
{
struct {
int (* F_118)( struct V_1 * , struct V_2 * );
} * V_5 , V_230 [] = {
{ F_115 } ,
{ F_114 } ,
{ F_116 } ,
{ F_117 } ,
{ NULL }
} ;
int V_31 = 0 ;
for ( V_5 = V_230 ; V_5 -> F_118 ; V_5 ++ ) {
if ( ( V_31 = V_5 -> F_118 ( V_8 , V_3 ) ) < 0 )
break;
}
return V_31 ;
}
static T_11 V_111 ( int V_108 , void * V_231 )
{
struct V_1 * V_97 = V_231 ;
struct V_95 * V_4 ;
struct V_2 * V_3 ;
void T_4 * V_62 ;
T_1 V_10 ;
unsigned long V_71 ;
int V_43 , V_232 = 1 ;
V_4 = V_97 -> V_37 ;
V_3 = F_3 ( V_97 ) ;
F_119 ( & V_4 -> V_147 , V_71 ) ;
V_62 = V_97 -> V_12 ;
V_10 = F_10 ( V_62 + V_65 ) ;
if ( ! V_10 ) {
V_232 = 0 ;
goto V_103;
}
if ( V_32 > 3 )
F_17 ( V_33 L_32 , V_113 , V_10 ) ;
F_5 ( V_10 , V_62 + V_65 ) ;
if ( V_10 & V_67 ) {
F_36 ( V_3 , L_33 ) ;
goto V_103;
}
V_10 &= ~ V_66 ;
if ( V_10 & V_233 ) {
if ( V_32 > 0 )
F_17 ( V_33 L_34 , V_113 ) ;
if ( V_4 -> V_119 [ V_4 -> V_234 ++ % V_70 ] & F_30 ( V_67 ) )
F_36 ( V_3 , L_35 ) ;
if ( ! ( V_10 &= ~ V_233 ) )
goto V_103;
}
if ( V_10 & V_235 ) {
V_43 = V_98 - 1 ;
do {
F_120 ( V_4 , V_97 + V_43 ) ;
} while ( -- V_43 >= 0 );
V_10 &= ~ V_235 ;
}
if ( V_10 & V_236 ) {
V_43 = V_98 - 1 ;
do {
F_121 ( V_4 , V_97 + V_43 ) ;
} while ( -- V_43 >= 0 );
V_10 &= ~ V_236 ;
}
V_103:
F_122 ( & V_4 -> V_147 , V_71 ) ;
return F_123 ( V_232 ) ;
}
static void F_121 ( struct V_95 * V_96 ,
struct V_1 * V_8 )
{
struct V_2 * V_3 = F_3 ( V_8 ) ;
T_1 V_10 ;
int V_68 , V_237 = 0 ;
V_238:
V_68 = V_8 -> V_69 % V_70 ;
V_10 = F_22 ( V_8 -> V_74 [ V_68 ] ) ;
if ( ! V_10 ) {
if ( V_32 > 4 )
F_17 ( V_33 L_36 , V_3 -> V_34 ,
V_10 ) ;
if ( ( V_32 > 1 ) && ( V_237 > 1 ) )
F_17 ( V_33 L_37 , V_3 -> V_34 , V_237 ) ;
if ( V_237 && F_124 ( V_3 ) )
if ( ( V_8 -> V_17 - V_8 -> V_28 ) % V_18 )
F_125 ( V_3 ) ;
if ( F_44 ( V_3 ) && F_14 ( V_8 , V_3 ) &&
! F_13 ( V_8 ) )
F_11 ( V_8 , V_3 ) ;
return;
}
V_237 ++ ;
V_8 -> V_74 [ V_68 ] = 0 ;
V_8 -> V_69 ++ ;
if ( F_15 ( V_10 , V_8 , V_3 , L_38 ) < 0 )
return;
if ( V_10 & V_239 ) {
if ( V_10 & V_240 ) {
struct V_41 * V_54 ;
struct V_19 * V_39 ;
if ( V_32 > 2 )
F_18 ( V_3 , V_8 , L_39 ) ;
V_68 = V_8 -> V_28 % V_18 ;
V_39 = V_8 -> V_39 + V_68 ;
V_54 = V_8 -> V_46 [ V_68 ] ;
if ( V_54 ) {
F_21 ( & V_96 -> V_38 -> V_3 ,
F_22 ( V_39 -> V_47 ) ,
V_54 -> V_48 , V_49 ) ;
if ( V_39 -> V_10 & V_190 ) {
V_3 -> V_82 . V_241 ++ ;
V_3 -> V_82 . V_242 += V_54 -> V_48 ;
}
F_46 ( V_54 ) ;
V_8 -> V_46 [ V_68 ] = NULL ;
++ V_8 -> V_28 ;
} else {
if ( V_32 > 1 )
F_36 ( V_3 , L_40 ,
V_68 ) ;
}
V_39 -> V_47 = V_39 -> V_187 ;
V_39 -> V_10 = V_190 | F_96 ( 2 * V_243 ) ;
V_39 -> V_191 = 0x00000000 ;
V_39 -> V_165 = 0 ;
if ( ! ( V_10 &= ~ V_240 ) )
goto V_238;
}
if ( V_10 & V_244 ) {
F_36 ( V_3 , L_41 ) ;
V_8 -> V_71 = V_73 ;
F_5 ( V_245 | V_246 ,
V_8 -> V_12 + 0x0c * V_8 -> V_21 + V_247 ) ;
F_5 ( V_63 , V_8 -> V_12 + V_64 ) ;
return;
}
if ( V_10 & V_248 ) {
F_83 ( V_3 , L_42 ) ;
if ( ! ( V_10 &= ~ V_248 ) )
goto V_238;
}
if ( V_10 & V_249 ) {
F_36 ( V_3 , L_43 ) ;
if ( ! ( V_10 &= ~ V_249 ) )
goto V_238;
}
if ( V_10 & V_75 ) {
void T_4 * V_250 ;
unsigned long V_251 ;
unsigned int V_43 ;
for ( V_43 = 1 ; V_43 ; V_43 <<= 1 ) {
if ( ! ( F_9 ( V_8 , V_3 ) & V_59 ) )
break;
}
if ( ! V_43 )
F_83 ( V_3 , L_44 ) ;
V_250 = V_8 -> V_12 + 0x0c * V_8 -> V_21 ;
if ( V_8 -> V_71 & V_73 ) {
if ( V_32 > 2 )
F_18 ( V_3 , V_8 , L_45 ) ;
V_251 = V_8 -> V_16 +
( V_8 -> V_28 % V_18 ) *
sizeof( struct V_19 ) ;
F_5 ( V_251 , V_250 + V_252 ) ;
F_11 ( V_8 , V_3 ) ;
F_5 ( V_245 | V_253 , V_250 + V_247 ) ;
if ( F_37 ( V_3 , L_46 ) < 0 )
goto V_254;
V_8 -> V_71 &= ~ V_73 ;
}
if ( V_8 -> V_71 & V_72 ) {
V_251 = V_8 -> V_23 +
( V_8 -> V_76 % V_25 ) *
sizeof( struct V_26 ) ;
F_5 ( V_251 , V_250 + V_255 ) ;
F_12 ( V_8 , V_3 ) ;
F_5 ( V_245 | V_256 , V_250 + V_247 ) ;
if ( F_37 ( V_3 , L_47 ) < 0 )
goto V_254;
V_8 -> V_71 &= ~ V_72 ;
F_126 () ;
F_7 ( 0x08050008 , V_8 , V_3 , V_141 ) ;
}
V_254:
if ( ! ( V_10 &= ~ V_75 ) )
goto V_238;
}
if ( V_10 & V_257 ) {
if ( V_32 > 0 )
F_83 ( V_3 , L_48 ) ;
if ( ! ( V_10 &= ~ V_257 ) )
goto V_238;
}
} else {
if ( V_10 & V_258 ) {
#ifdef F_98
while ( ! F_95 ( V_8 , V_3 ) ) ;
#endif
F_83 ( V_3 , L_49 ) ;
V_10 &= ~ V_258 ;
}
if ( V_10 & V_259 ) {
F_83 ( V_3 , L_50 ) ;
V_3 -> V_82 . V_260 ++ ;
V_10 &= ~ V_259 ;
}
}
goto V_238;
}
static void F_120 ( struct V_95 * V_4 ,
struct V_1 * V_8 )
{
struct V_2 * V_3 = F_3 ( V_8 ) ;
T_1 V_10 ;
int V_68 ;
V_238:
V_68 = V_8 -> V_261 % V_70 ;
V_10 = F_22 ( V_8 -> V_128 [ V_68 ] ) ;
if ( ! V_10 )
return;
V_8 -> V_128 [ V_68 ] = 0 ;
V_8 -> V_261 ++ ;
if ( F_15 ( V_10 , V_8 , V_3 , L_51 ) < 0 )
return;
if ( ! ( V_10 & V_239 ) ) {
struct V_26 * V_40 ;
if ( V_32 > 4 )
F_17 ( V_33 L_52 , V_3 -> V_34 ,
V_10 ) ;
V_10 &= 0x00ffffff ;
if ( V_10 & V_259 ) {
F_17 ( V_33 L_53 , V_3 -> V_34 ) ;
V_68 = V_8 -> V_76 % V_25 ;
V_40 = V_8 -> V_40 + V_68 ;
while ( ! ( V_40 -> V_262 & V_263 ) ) {
V_40 ++ ;
V_68 ++ ;
if ( ! ( V_68 = V_68 % V_25 ) )
V_40 = V_8 -> V_40 ;
}
F_25 ( V_8 , V_3 ) ;
if ( ! V_40 -> V_47 )
goto V_238;
V_40 -> V_262 &= ~ V_263 ;
V_40 -> V_80 = 0x00000000 ;
V_40 -> V_93 = F_30 ( 0xbabeface ) ;
goto V_238;
}
if ( V_10 & V_264 ) {
F_41 ( V_8 , V_3 ) ;
goto V_238;
}
if ( V_10 & V_258 ) {
F_83 ( V_3 , L_54 ) ;
V_10 &= ~ V_258 ;
goto V_238;
}
} else {
if ( V_32 > 1 ) {
static struct {
T_1 V_6 ;
const char * V_265 ;
} V_266 [] = {
{ 0x00008000 , L_55 } ,
{ 0x00000020 , L_56 } ,
{ 0x00000010 , L_57 } ,
{ 0x00000008 , L_58 } ,
{ 0 , NULL }
} , * V_267 ;
for ( V_267 = V_266 ; V_267 -> V_265 ; V_267 ++ ) {
if ( V_10 & V_267 -> V_6 ) {
F_17 ( V_33 L_59 ,
V_3 -> V_34 , V_267 -> V_265 ) ;
if ( ! ( V_10 &= ~ V_267 -> V_6 ) )
goto V_238;
}
}
} else {
if ( ! ( V_10 &= ~ 0x0000c03c ) )
goto V_238;
}
if ( V_10 & V_248 ) {
F_83 ( V_3 , L_42 ) ;
if ( ! ( V_10 &= ~ V_248 ) )
goto V_238;
}
if ( V_10 & V_268 ) {
struct V_26 * V_40 ;
void T_4 * V_250 ;
int V_68 ;
V_250 = V_8 -> V_12 + 0x0c * V_8 -> V_21 ;
F_4 ( V_140 , 0 , V_8 , V_3 , V_141 ) ;
F_7 ( V_182 , V_8 , V_3 , V_183 ) ;
V_8 -> V_71 |= V_269 ;
do {
V_68 = V_8 -> V_76 ++ % V_25 ;
V_40 = V_8 -> V_40 + V_68 ;
if ( ! ( V_40 -> V_80 & V_270 ) )
break;
if ( V_40 -> V_80 & V_271 ) {
V_3 -> V_82 . V_272 ++ ;
V_40 -> V_262 |= V_263 ;
V_40 -> V_80 = 0x00000000 ;
V_40 -> V_93 = F_30 ( 0xbabeface ) ;
} else
F_41 ( V_8 , V_3 ) ;
} while ( 1 );
if ( V_32 > 0 ) {
if ( V_8 -> V_71 & V_269 )
F_17 ( V_33
L_60 , V_113 ) ;
}
#ifdef F_127
#warning "FIXME: CH0BRDA"
F_5 ( V_8 -> V_23 +
( V_8 -> V_76 % V_25 ) *
sizeof( struct V_26 ) , V_250 + V_255 ) ;
F_5 ( V_245 | V_273 | V_256 , V_250 + V_247 ) ;
if ( F_37 ( V_3 , L_61 ) < 0 ) {
F_36 ( V_3 , L_62 ) ;
goto V_274;
}
F_5 ( V_245 | V_256 , V_250 + V_247 ) ;
if ( F_37 ( V_3 , L_47 ) < 0 ) {
F_36 ( V_3 , L_63 ) ;
goto V_274;
}
V_274:
#endif
F_4 ( 0 , V_140 , V_8 , V_3 , V_141 ) ;
goto V_238;
}
if ( V_10 & V_257 ) {
F_83 ( V_3 , L_48 ) ;
if ( ! ( V_10 &= ~ V_257 ) )
goto V_238;
}
if ( V_10 & V_275 ) {
F_17 ( V_33 L_64 , V_113 ) ;
if ( ! ( V_10 &= ~ V_275 ) )
goto V_238;
}
}
}
static struct V_41 * F_128 ( struct V_1 * V_8 )
{
struct V_41 * V_54 ;
V_54 = F_26 ( V_243 ) ;
if ( V_54 ) {
struct V_35 * V_36 = & V_8 -> V_37 -> V_38 -> V_3 ;
int V_276 = V_8 -> V_28 % V_18 ;
struct V_19 * V_39 = V_8 -> V_39 + V_276 ;
T_2 V_55 ;
V_54 -> V_48 = V_243 ;
F_129 ( V_54 , V_102 ,
strlen ( V_102 ) % V_243 ) ;
V_55 = F_28 ( V_36 , V_54 -> V_47 , V_243 ,
V_49 ) ;
if ( F_29 ( V_36 , V_55 ) ) {
F_31 ( V_54 ) ;
return NULL ;
}
V_39 -> V_10 = V_190 | F_96 ( V_243 ) ;
V_39 -> V_47 = F_30 ( V_55 ) ;
V_8 -> V_46 [ V_276 ] = V_54 ;
}
return V_54 ;
}
static int F_76 ( struct V_2 * V_3 )
{
struct V_1 * V_8 = F_1 ( V_3 ) ;
struct V_35 * V_36 = & V_8 -> V_37 -> V_38 -> V_3 ;
struct V_19 * V_39 ;
struct V_26 * V_40 ;
void * V_251 ;
int V_43 ;
V_251 = F_64 ( V_36 , V_45 , & V_8 -> V_23 ,
V_122 ) ;
if ( ! V_251 )
goto V_56;
V_8 -> V_40 = V_40 = (struct V_26 * ) V_251 ;
V_251 = F_64 ( V_36 , V_44 , & V_8 -> V_16 ,
V_122 ) ;
if ( ! V_251 )
goto V_277;
V_8 -> V_39 = V_39 = (struct V_19 * ) V_251 ;
memset ( V_8 -> V_46 , 0 , sizeof( struct V_41 * ) * V_18 ) ;
V_8 -> V_28 = 0xffffffff ;
V_43 = V_8 -> V_17 = 0 ;
do {
V_39 -> V_10 = V_190 | F_96 ( 2 * V_243 ) ;
V_39 -> V_191 = 0x00000000 ;
V_39 -> V_47 = F_30 ( V_8 -> V_16 ) ;
( V_39 ++ ) -> V_187 = F_30 ( V_8 -> V_16 +
( ++ V_43 % V_18 ) * sizeof( * V_39 ) ) ;
} while ( V_43 < V_18 );
if ( ! F_128 ( V_8 ) )
goto V_278;
memset ( V_8 -> V_50 , 0 , sizeof( struct V_41 * ) * V_25 ) ;
V_43 = V_8 -> V_24 = V_8 -> V_76 = 0 ;
do {
V_40 -> V_262 = V_279 ;
V_40 -> V_80 = 0x00000000 ;
V_40 -> V_93 = F_30 ( 0xbabeface ) ;
V_40 -> V_262 |= F_130 ( V_51 ) ;
if ( F_25 ( V_8 , V_3 ) >= 0 )
V_8 -> V_24 ++ ;
( V_40 ++ ) -> V_187 = F_30 ( V_8 -> V_23 +
( ++ V_43 % V_25 ) * sizeof( * V_40 ) ) ;
} while ( V_43 < V_25 );
return 0 ;
V_278:
F_20 ( V_36 , V_44 , V_251 , V_8 -> V_16 ) ;
V_277:
F_20 ( V_36 , V_45 , V_40 , V_8 -> V_23 ) ;
V_56:
return - V_118 ;
}
static void F_131 ( struct V_94 * V_38 )
{
struct V_95 * V_96 ;
struct V_1 * V_97 ;
void T_4 * V_62 ;
int V_43 ;
V_96 = F_48 ( V_38 ) ;
V_97 = V_96 -> V_97 ;
V_62 = V_97 -> V_12 ;
F_84 ( V_38 , V_62 ) ;
F_65 ( V_38 -> V_108 , V_97 ) ;
F_20 ( & V_38 -> V_3 , V_70 * sizeof( T_1 ) , V_96 -> V_119 ,
V_96 -> V_121 ) ;
for ( V_43 = 0 ; V_43 < V_98 ; V_43 ++ ) {
struct V_1 * V_8 = V_97 + V_43 ;
F_19 ( V_8 ) ;
F_20 ( & V_38 -> V_3 , V_70 * sizeof( T_1 ) ,
V_8 -> V_128 , V_8 -> V_129 ) ;
F_20 ( & V_38 -> V_3 , V_70 * sizeof( T_1 ) ,
V_8 -> V_74 , V_8 -> V_125 ) ;
}
F_47 ( V_38 ) ;
F_66 ( V_62 ) ;
F_67 ( V_38 , 1 ) ;
F_67 ( V_38 , 0 ) ;
F_68 ( V_38 ) ;
}
static int V_156 ( struct V_2 * V_3 , unsigned short V_159 ,
unsigned short V_157 )
{
struct V_1 * V_8 = F_1 ( V_3 ) ;
if ( V_159 != V_160 &&
V_159 != V_220 &&
V_159 != V_221 &&
V_159 != V_222 &&
V_159 != V_223 )
return - V_280 ;
if ( V_157 != V_281 &&
V_157 != V_158 &&
V_157 != V_226 &&
V_157 != V_227 &&
V_157 != V_228 )
return - V_280 ;
V_8 -> V_159 = V_159 ;
V_8 -> V_157 = V_157 ;
return 0 ;
}
static int T_12 F_132 ( char * V_282 )
{
int * args [] = { & V_32 , & V_162 , NULL } , * * V_5 = args ;
while ( * V_5 && ( F_133 ( & V_282 , * V_5 ) == 2 ) )
V_5 ++ ;
return 1 ;
}
