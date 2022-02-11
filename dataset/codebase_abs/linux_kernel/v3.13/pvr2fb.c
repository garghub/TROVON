static inline void F_1 ( unsigned int type )
{
struct V_1 * V_2 = (struct V_1 * ) V_3 -> V_2 ;
F_2 ( type , V_2 -> V_4 + 0x108 ) ;
}
static inline void F_3 ( struct V_1 * V_2 ,
unsigned int V_5 ,
unsigned int V_6 )
{
F_2 ( V_6 , V_2 -> V_4 + 0x1000 + ( 4 * V_5 ) ) ;
}
static int F_4 ( int V_7 , struct V_3 * V_8 )
{
V_9 = V_7 ? V_7 : - 1 ;
return 0 ;
}
static inline unsigned long F_5 ( int V_10 , int V_11 )
{
return ( unsigned long ) ( ( ( ( V_10 * V_11 ) + 31 ) & ~ 31 ) >> 3 ) ;
}
static void F_6 ( struct V_12 * V_13 )
{
switch ( V_13 -> V_14 ) {
case 16 :
F_1 ( V_15 ) ;
V_13 -> V_16 . V_17 = 11 ; V_13 -> V_16 . V_18 = 5 ;
V_13 -> V_19 . V_17 = 5 ; V_13 -> V_19 . V_18 = 6 ;
V_13 -> V_20 . V_17 = 0 ; V_13 -> V_20 . V_18 = 5 ;
V_13 -> V_21 . V_17 = 0 ; V_13 -> V_21 . V_18 = 0 ;
break;
case 24 :
V_13 -> V_16 . V_17 = 16 ; V_13 -> V_16 . V_18 = 8 ;
V_13 -> V_19 . V_17 = 8 ; V_13 -> V_19 . V_18 = 8 ;
V_13 -> V_20 . V_17 = 0 ; V_13 -> V_20 . V_18 = 8 ;
V_13 -> V_21 . V_17 = 0 ; V_13 -> V_21 . V_18 = 0 ;
break;
case 32 :
F_1 ( V_22 ) ;
V_13 -> V_16 . V_17 = 16 ; V_13 -> V_16 . V_18 = 8 ;
V_13 -> V_19 . V_17 = 8 ; V_13 -> V_19 . V_18 = 8 ;
V_13 -> V_20 . V_17 = 0 ; V_13 -> V_20 . V_18 = 8 ;
V_13 -> V_21 . V_17 = 24 ; V_13 -> V_21 . V_18 = 8 ;
break;
}
}
static int F_7 ( unsigned int V_5 , unsigned int V_16 ,
unsigned int V_19 , unsigned int V_20 ,
unsigned int V_21 , struct V_3 * V_8 )
{
struct V_1 * V_2 = (struct V_1 * ) V_8 -> V_2 ;
unsigned int V_23 ;
if ( V_5 > V_8 -> V_24 . V_25 )
return 1 ;
switch ( V_8 -> V_13 . V_14 ) {
case 16 :
V_23 = ( V_16 & 0xf800 ) |
( ( V_19 & 0xfc00 ) >> 5 ) |
( ( V_20 & 0xf800 ) >> 11 ) ;
F_3 ( V_2 , V_5 , V_23 ) ;
break;
case 24 :
V_16 >>= 8 ; V_19 >>= 8 ; V_20 >>= 8 ;
V_23 = ( V_16 << 16 ) | ( V_19 << 8 ) | V_20 ;
break;
case 32 :
V_16 >>= 8 ; V_19 >>= 8 ; V_20 >>= 8 ;
V_23 = ( V_21 << 24 ) | ( V_16 << 16 ) | ( V_19 << 8 ) | V_20 ;
F_3 ( V_2 , V_5 , V_23 ) ;
break;
default:
F_8 ( L_1 , V_8 -> V_13 . V_14 ) ;
return 1 ;
}
if ( V_5 < 16 )
( ( V_26 * ) ( V_8 -> V_27 ) ) [ V_5 ] = V_23 ;
return 0 ;
}
static int F_9 ( struct V_3 * V_8 )
{
struct V_1 * V_2 = (struct V_1 * ) V_8 -> V_2 ;
struct V_12 * V_13 = & V_8 -> V_13 ;
unsigned long V_28 ;
unsigned int V_29 ;
V_30 = F_10 () ;
if ( V_30 == V_31 && V_32 != V_33 )
V_32 = V_33 ;
V_13 -> V_34 &= V_35 ;
if ( V_13 -> V_34 & V_36 && V_32 != V_33 )
V_2 -> V_37 = 1 ;
if ( V_13 -> V_34 & V_38 && V_32 == V_33 )
V_2 -> V_39 = 1 ;
V_2 -> V_40 = V_13 -> V_41 + V_13 -> V_42 + V_13 -> V_43 +
V_13 -> V_44 ;
V_2 -> V_45 = V_13 -> V_46 + V_13 -> V_47 + V_13 -> V_48 +
V_13 -> V_49 ;
if ( V_13 -> V_50 & V_51 ) {
V_29 = V_2 -> V_45 ;
if ( V_2 -> V_37 )
V_29 /= 2 ;
if ( V_29 > ( V_52 + V_53 ) / 2 ) {
V_2 -> V_54 = 116 ;
V_2 -> V_55 = 44 ;
} else {
V_2 -> V_54 = 126 ;
V_2 -> V_55 = 18 ;
}
} else {
V_2 -> V_54 = 126 ;
V_2 -> V_55 = 40 ;
}
V_2 -> V_56 = V_2 -> V_54 + V_13 -> V_41 ;
V_2 -> V_57 = V_2 -> V_55 + V_13 -> V_46 ;
V_2 -> V_58 = V_2 -> V_56 + V_13 -> V_42 +
V_13 -> V_43 ;
V_2 -> V_59 = V_2 -> V_57 + V_13 -> V_47 +
V_13 -> V_48 ;
if ( ! V_2 -> V_37 )
V_2 -> V_59 /= 2 ;
if ( V_8 -> V_13 . V_42 < 640 )
V_2 -> V_60 = 1 ;
V_28 = F_5 ( V_13 -> V_10 , V_13 -> V_14 ) ;
V_2 -> V_61 = V_8 -> V_62 . V_63 + ( V_28 * V_13 -> V_64 ) * V_28 ;
V_8 -> V_62 . V_28 = V_28 ;
return 0 ;
}
static int F_11 ( struct V_12 * V_13 , struct V_3 * V_8 )
{
struct V_1 * V_2 = (struct V_1 * ) V_8 -> V_2 ;
unsigned int V_29 , V_40 ;
unsigned long V_28 ;
if ( V_13 -> V_65 != V_66 && V_13 -> V_65 != V_67 ) {
F_8 ( L_2 , V_13 -> V_65 ) ;
return - V_68 ;
}
if ( V_13 -> V_42 < 320 )
V_13 -> V_42 = 320 ;
if ( V_13 -> V_47 < 240 )
V_13 -> V_47 = 240 ;
if ( V_13 -> V_10 < V_13 -> V_42 )
V_13 -> V_10 = V_13 -> V_42 ;
if ( V_13 -> V_69 < V_13 -> V_47 )
V_13 -> V_69 = V_13 -> V_47 ;
if ( V_13 -> V_14 <= 16 )
V_13 -> V_14 = 16 ;
else if ( V_13 -> V_14 <= 24 )
V_13 -> V_14 = 24 ;
else if ( V_13 -> V_14 <= 32 )
V_13 -> V_14 = 32 ;
F_6 ( V_13 ) ;
if ( V_13 -> V_34 & V_70 ) {
if ( V_13 -> V_71 || V_13 -> V_64 < 0 ||
V_13 -> V_64 >= V_13 -> V_69 ) {
V_13 -> V_71 = V_13 -> V_64 = 0 ;
} else {
if ( V_13 -> V_71 > V_13 -> V_10 - V_13 -> V_42 ||
V_13 -> V_64 > V_13 -> V_69 - V_13 -> V_47 ||
V_13 -> V_71 < 0 || V_13 -> V_64 < 0 )
V_13 -> V_71 = V_13 -> V_64 = 0 ;
}
} else {
V_13 -> V_71 = V_13 -> V_64 = 0 ;
}
if ( V_13 -> V_47 < 480 && V_32 == V_33 )
V_13 -> V_34 |= V_38 ;
if ( V_32 != V_33 ) {
V_13 -> V_50 |= V_51 ;
V_13 -> V_34 |= V_36 ;
} else {
V_13 -> V_50 &= ~ V_51 ;
V_13 -> V_34 &= ~ V_36 ;
V_13 -> V_34 |= V_72 ;
}
if ( ( V_13 -> V_73 & V_74 ) != V_75 ) {
V_13 -> V_43 = V_2 -> V_58 -
( V_2 -> V_56 + V_13 -> V_42 ) ;
V_13 -> V_41 = V_2 -> V_56 - V_2 -> V_54 ;
V_13 -> V_44 = V_2 -> V_54 +
( V_2 -> V_40 - V_2 -> V_58 ) ;
V_13 -> V_46 = V_2 -> V_57 - V_2 -> V_55 ;
V_13 -> V_48 = V_2 -> V_59 -
( V_2 -> V_57 + V_13 -> V_47 ) ;
V_13 -> V_49 = V_2 -> V_59 +
( V_2 -> V_45 - V_2 -> V_59 ) ;
}
V_40 = V_13 -> V_41 + V_13 -> V_42 + V_13 -> V_43 +
V_13 -> V_44 ;
V_29 = V_13 -> V_46 + V_13 -> V_47 + V_13 -> V_48 +
V_13 -> V_49 ;
if ( V_13 -> V_50 & V_51 ) {
if ( V_13 -> V_34 & V_36 )
V_29 /= 2 ;
if ( V_29 > ( V_52 + V_53 ) / 2 ) {
if ( V_40 != V_76 ) {
F_8 ( L_3 ) ;
return - V_68 ;
}
} else {
if ( V_40 != V_77 ) {
F_8 ( L_4 ) ;
return - V_68 ;
}
}
}
V_28 = F_5 ( V_13 -> V_10 , V_13 -> V_14 ) ;
if ( V_28 * V_13 -> V_69 > V_8 -> V_62 . V_78 )
return - V_79 ;
return 0 ;
}
static void F_12 ( struct V_3 * V_8 )
{
struct V_1 * V_2 = (struct V_1 * ) V_8 -> V_2 ;
struct V_12 * V_13 = & V_8 -> V_13 ;
F_2 ( V_2 -> V_61 , V_80 ) ;
F_2 ( V_2 -> V_61 +
F_5 ( V_13 -> V_71 + V_13 -> V_42 , V_13 -> V_14 ) ,
V_81 ) ;
}
static void F_13 ( struct V_3 * V_8 )
{
struct V_1 * V_2 = (struct V_1 * ) V_8 -> V_2 ;
struct V_12 * V_13 = & V_8 -> V_13 ;
unsigned int V_82 , V_83 , V_84 = 1 ;
unsigned int V_85 = V_13 -> V_14 >> 3 ;
F_2 ( ( V_2 -> V_45 << 16 ) | V_2 -> V_40 , V_86 ) ;
if ( V_32 != V_33 && V_2 -> V_37 )
V_84 += V_8 -> V_62 . V_28 / 4 ;
V_82 = ( V_2 -> V_37 ? V_13 -> V_47 / 2 : V_13 -> V_47 ) ;
V_83 = F_5 ( V_13 -> V_42 , V_13 -> V_14 ) / 4 ;
F_2 ( ( V_84 << 20 ) | ( -- V_82 << 10 ) | -- V_83 ,
V_87 ) ;
F_2 ( V_2 -> V_61 , V_80 ) ;
F_2 ( V_2 -> V_61 +
F_5 ( V_13 -> V_71 + V_13 -> V_42 , V_13 -> V_14 ) ,
V_81 ) ;
F_2 ( ( V_2 -> V_54 << 16 ) | V_2 -> V_58 , V_88 ) ;
F_2 ( ( V_2 -> V_55 << 16 ) | V_2 -> V_59 , V_89 ) ;
F_2 ( 0 , V_90 ) ;
F_2 ( V_2 -> V_56 , V_91 ) ;
F_2 ( ( V_2 -> V_57 << 16 ) | V_2 -> V_57 , V_92 ) ;
F_2 ( ( 0x16 << 16 ) | V_2 -> V_60 , V_93 ) ;
F_2 ( ( ( V_32 == V_33 ) << 23 ) |
( V_2 -> V_39 << 1 ) | 1 , V_94 ) ;
F_2 ( F_14 ( V_94 ) | ( -- V_85 << 2 ) , V_94 ) ;
F_2 ( V_85 << 2 , V_95 ) ;
F_2 ( 0x100 | ( ( V_2 -> V_37 ) << 4 ) , V_96 ) ;
}
static void F_15 ( void )
{
struct V_1 * V_2 = V_97 ;
unsigned long V_98 ;
V_98 = F_14 ( V_93 ) ;
if ( V_9 > 0 )
F_2 ( V_98 | V_99 , V_93 ) ;
else
F_2 ( V_98 & ~ V_99 , V_93 ) ;
V_100 = V_9 > 0 ? V_9 : 0 ;
}
static T_1 F_16 ( int V_101 , void * V_102 )
{
struct V_3 * V_8 = V_102 ;
if ( V_103 || V_104 )
F_12 ( V_8 ) ;
if ( V_104 )
F_13 ( V_8 ) ;
if ( V_103 )
V_103 = 0 ;
if ( V_104 )
V_104 = 0 ;
if ( V_9 ) {
F_15 () ;
V_9 = 0 ;
}
return V_105 ;
}
static int F_10 ( void )
{
if ( V_30 < 0 ) {
F_2 ( ( F_14 ( V_106 ) & 0xfff0ffff ) | 0x000a0000 ,
V_106 ) ;
V_30 = ( F_17 ( V_107 ) >> 8 ) & 3 ;
}
if ( V_30 == V_108 )
F_2 ( 3 << 8 , V_109 ) ;
else if ( V_30 == V_110 )
F_2 ( 1 << 9 , V_109 ) ;
else
F_2 ( 0 , V_109 ) ;
return V_30 ;
}
static T_2 F_18 ( struct V_3 * V_8 , const char * V_111 ,
T_3 V_112 , T_4 * V_113 )
{
unsigned long V_114 , V_115 , V_116 , V_25 ;
unsigned int V_117 ;
struct V_118 * * V_119 ;
int V_120 , V_121 ;
V_117 = ( V_112 + V_122 - 1 ) >> V_123 ;
V_119 = F_19 ( V_117 * sizeof( struct V_118 * ) , V_124 ) ;
if ( ! V_119 )
return - V_79 ;
F_20 ( & V_125 -> V_126 -> V_127 ) ;
V_120 = F_21 ( V_125 , V_125 -> V_126 , ( unsigned long ) V_111 ,
V_117 , V_128 , 0 , V_119 , NULL ) ;
F_22 ( & V_125 -> V_126 -> V_127 ) ;
if ( V_120 < V_117 ) {
V_117 = V_120 ;
V_120 = - V_68 ;
goto V_129;
}
F_23 ( V_130 , 0x12c1 ) ;
V_114 = ( unsigned long ) V_3 -> V_131 + * V_113 ;
V_115 = ( unsigned long ) F_24 ( V_119 [ 0 ] ) ;
V_116 = ( unsigned long ) F_24 ( V_119 [ V_117 ] ) ;
V_25 = V_117 << V_123 ;
if ( V_115 + V_25 == V_116 ) {
if ( ( * V_113 + V_25 ) > V_3 -> V_62 . V_78 ) {
V_120 = - V_132 ;
goto V_129;
}
F_25 ( V_130 , V_115 , 0 , V_25 ) ;
F_25 ( V_133 , 0 , V_114 , V_25 ) ;
F_26 ( V_133 ) ;
goto V_134;
}
for ( V_121 = 0 ; V_121 < V_117 ; V_121 ++ , V_114 += V_122 ) {
if ( ( * V_113 + ( V_121 << V_123 ) ) > V_3 -> V_62 . V_78 ) {
V_120 = - V_132 ;
goto V_129;
}
F_27 ( V_130 , ( unsigned long ) F_24 ( V_119 [ V_121 ] ) , 0 ) ;
F_27 ( V_133 , 0 , V_114 ) ;
F_26 ( V_133 ) ;
}
V_134:
* V_113 += V_112 ;
V_120 = V_112 ;
V_129:
for ( V_121 = 0 ; V_121 < V_117 ; V_121 ++ )
F_28 ( V_119 [ V_121 ] ) ;
F_29 ( V_119 ) ;
return V_120 ;
}
static int F_30 ( void )
{
struct V_1 * V_2 = V_97 ;
unsigned long V_135 , V_136 ;
V_3 -> V_131 = F_31 ( V_137 . V_63 ,
V_137 . V_78 ) ;
if ( ! V_3 -> V_131 ) {
F_32 ( V_138 L_5 ) ;
goto V_139;
}
V_2 -> V_4 = ( unsigned long ) F_31 ( V_137 . V_140 ,
V_137 . V_141 ) ;
if ( ! V_2 -> V_4 ) {
F_32 ( V_138 L_6 ) ;
goto V_139;
}
F_33 ( V_3 -> V_131 , 0 , V_137 . V_78 ) ;
V_137 . V_142 = V_143 ? 0 : 1 ;
V_137 . V_144 = V_145 ? 0 : 1 ;
V_3 -> V_146 = & V_147 ;
V_3 -> V_62 = V_137 ;
V_3 -> V_2 = V_97 ;
V_3 -> V_27 = V_97 -> V_148 ;
V_3 -> V_149 = V_150 | V_151 ;
if ( V_32 == V_33 )
V_152 = V_153 ;
if ( ! V_154 )
V_154 = L_7 ;
if ( ! F_34 ( & V_3 -> V_13 , V_3 , V_154 , V_155 ,
V_156 , & V_155 [ V_152 ] , 16 ) )
V_3 -> V_13 = V_157 ;
F_35 ( & V_3 -> V_24 , 256 , 0 ) ;
if ( F_36 ( V_3 ) < 0 )
goto V_139;
F_13 ( V_3 ) ;
V_135 = F_5 ( V_3 -> V_13 . V_10 ,
V_3 -> V_13 . V_14 ) ;
V_135 *= V_3 -> V_13 . V_69 ;
V_136 = F_14 ( V_2 -> V_4 + 0x04 ) ;
V_3 ( V_3 , L_8 ,
V_3 -> V_62 . V_158 , ( V_136 >> 4 ) & 0x0f , V_136 & 0x0f ,
V_135 >> 10 ,
( unsigned long ) ( V_3 -> V_62 . V_78 >> 10 ) ) ;
V_3 ( V_3 , L_9 ,
V_3 -> V_13 . V_42 , V_3 -> V_13 . V_47 ,
V_3 -> V_13 . V_14 ,
F_5 ( V_3 -> V_13 . V_42 , V_3 -> V_13 . V_14 ) ,
( char * ) F_37 ( V_159 , NULL , V_30 , 3 ) ,
( char * ) F_37 ( V_160 , NULL , V_32 , 3 ) ) ;
#ifdef F_38
F_39 ( V_3 , L_10 ) ;
V_161 = F_40 ( V_3 -> V_62 . V_63 , V_3 -> V_62 . V_78 ,
V_3 -> V_62 . V_158 , V_162 ) ;
F_39 ( V_3 , L_11 ,
V_161 ) ;
#endif
return 0 ;
V_139:
if ( V_3 -> V_131 )
F_41 ( V_3 -> V_131 ) ;
if ( V_2 -> V_4 )
F_41 ( ( void * ) V_2 -> V_4 ) ;
return - V_163 ;
}
static int T_5 F_42 ( void )
{
if ( ! F_43 () )
return - V_163 ;
if ( F_10 () == V_31 ) {
V_3 -> V_164 . V_165 = 30000 ;
V_3 -> V_164 . V_166 = 70000 ;
V_3 -> V_164 . V_167 = 60 ;
V_3 -> V_164 . V_168 = 60 ;
} else {
V_3 -> V_164 . V_165 = 15469 ;
V_3 -> V_164 . V_166 = 15781 ;
V_3 -> V_164 . V_167 = 49 ;
V_3 -> V_164 . V_168 = 51 ;
}
if ( V_32 < 0 ) {
if ( V_30 == V_31 ) {
V_32 = V_33 ;
} else {
V_32 = V_169 ;
}
}
V_137 . V_63 = 0xa5000000 ;
V_137 . V_78 = 8 << 20 ;
V_137 . V_140 = 0xa05f8000 ;
V_137 . V_141 = 0x2000 ;
if ( F_44 ( V_170 , F_16 , V_171 ,
L_12 , V_3 ) ) {
return - V_172 ;
}
#ifdef F_45
if ( F_46 ( V_133 , L_13 ) != 0 ) {
F_47 ( V_170 , V_3 ) ;
return - V_172 ;
}
#endif
return F_30 () ;
}
static void T_6 F_48 ( void )
{
if ( V_3 -> V_131 ) {
F_41 ( V_3 -> V_131 ) ;
V_3 -> V_131 = NULL ;
}
if ( V_97 -> V_4 ) {
F_41 ( ( void * ) V_97 -> V_4 ) ;
V_97 -> V_4 = 0 ;
}
F_47 ( V_170 , V_3 ) ;
#ifdef F_45
F_49 ( V_133 ) ;
#endif
}
static int F_50 ( struct V_173 * V_174 ,
const struct V_175 * V_176 )
{
int V_120 ;
V_120 = F_51 ( V_174 ) ;
if ( V_120 ) {
F_32 ( V_138 L_14 ) ;
return V_120 ;
}
V_120 = F_52 ( V_174 , L_15 ) ;
if ( V_120 ) {
F_32 ( V_138 L_16 ) ;
return V_120 ;
}
V_137 . V_63 = F_53 ( V_174 , 0 ) ;
V_137 . V_78 = F_54 ( V_174 , 0 ) ;
V_137 . V_140 = F_53 ( V_174 , 1 ) ;
V_137 . V_141 = F_54 ( V_174 , 1 ) ;
V_3 -> V_177 = & V_174 -> V_178 ;
return F_30 () ;
}
static void F_55 ( struct V_173 * V_174 )
{
if ( V_3 -> V_131 ) {
F_41 ( V_3 -> V_131 ) ;
V_3 -> V_131 = NULL ;
}
if ( V_97 -> V_4 ) {
F_41 ( ( void * ) V_97 -> V_4 ) ;
V_97 -> V_4 = 0 ;
}
F_56 ( V_174 ) ;
}
static int T_5 F_57 ( void )
{
return F_58 ( & V_179 ) ;
}
static void T_6 F_59 ( void )
{
F_60 ( & V_179 ) ;
}
static int F_37 ( const struct V_180 * V_181 , const char * V_182 , int V_6 ,
int V_183 )
{
int V_121 ;
for ( V_121 = 0 ; V_121 < V_183 ; V_121 ++ ) {
if ( V_182 != NULL ) {
if ( ! F_61 ( V_181 [ V_121 ] . V_184 , V_182 , strlen ( V_182 ) ) )
return V_181 [ V_121 ] . V_6 ;
} else {
if ( V_181 [ V_121 ] . V_6 == V_6 )
return ( int ) V_181 [ V_121 ] . V_184 ;
}
}
return - 1 ;
}
static int T_5 F_62 ( char * V_185 )
{
char * V_186 ;
char V_187 [ 80 ] ;
char V_188 [ 80 ] ;
if ( ! V_185 || ! * V_185 )
return 0 ;
while ( ( V_186 = F_63 ( & V_185 , L_17 ) ) ) {
if ( ! * V_186 )
continue;
if ( ! strcmp ( V_186 , L_18 ) ) {
F_64 () ;
} else if ( ! strncmp ( V_186 , L_19 , 6 ) ) {
strcpy ( V_187 , V_186 + 6 ) ;
} else if ( ! strncmp ( V_186 , L_20 , 7 ) ) {
strcpy ( V_188 , V_186 + 7 ) ;
} else if ( ! strncmp ( V_186 , L_21 , 5 ) ) {
V_143 = 1 ;
} else if ( ! strncmp ( V_186 , L_22 , 6 ) ) {
V_145 = 1 ;
} else {
V_154 = V_186 ;
}
}
if ( * V_187 )
V_30 = F_37 ( V_159 , V_187 , 0 , 3 ) ;
if ( * V_188 )
V_32 = F_37 ( V_160 , V_188 , 0 , 3 ) ;
return 0 ;
}
static int T_5 F_65 ( void )
{
int V_121 , V_120 = - V_189 ;
int V_183 ;
#ifndef F_66
char * V_190 = NULL ;
if ( F_67 ( L_15 , & V_190 ) )
return - V_189 ;
F_62 ( V_190 ) ;
#endif
V_183 = sizeof( struct V_3 ) + sizeof( struct V_1 ) + 16 * sizeof( V_26 ) ;
V_3 = F_68 ( sizeof( struct V_1 ) , NULL ) ;
if ( ! V_3 ) {
F_32 ( V_138 L_23 ) ;
return - V_79 ;
}
V_97 = V_3 -> V_2 ;
for ( V_121 = 0 ; V_121 < F_69 ( V_191 ) ; V_121 ++ ) {
struct V_192 * V_193 = V_191 + V_121 ;
if ( ! V_193 -> V_194 )
continue;
V_120 = V_193 -> V_194 () ;
if ( V_120 != 0 ) {
F_32 ( V_138 L_24 ,
V_193 -> V_184 ) ;
F_70 ( V_3 ) ;
break;
}
}
return V_120 ;
}
static void T_6 F_71 ( void )
{
int V_121 ;
for ( V_121 = 0 ; V_121 < F_69 ( V_191 ) ; V_121 ++ ) {
struct V_192 * V_193 = V_191 + V_121 ;
if ( V_193 -> exit )
V_193 -> exit () ;
}
#ifdef F_38
F_72 ( V_161 ) ;
#endif
F_73 ( V_3 ) ;
F_70 ( V_3 ) ;
}
