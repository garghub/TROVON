static inline void F_1 ( struct V_1 T_1 * V_2 ,
T_2 V_3 , unsigned int V_4 )
{
F_2 ( & V_2 -> V_5 , V_3 ) ;
F_3 ( & V_2 -> V_6 , V_4 >> 8 ) ;
F_3 ( & V_2 -> V_7 , V_4 & 0xff ) ;
}
static void F_4 ( struct V_8 * V_9 )
{
struct V_1 T_1 * V_2 = F_5 ( V_9 ) ;
struct V_10 T_1 * V_11 = F_6 ( V_9 ) ;
F_3 ( & V_11 -> V_12 , 0x00 ) ;
F_2 ( & V_11 -> V_13 , 0x1ff ) ;
F_3 ( & V_11 -> V_14 , 0x07 ) ;
F_2 ( & V_11 -> V_15 , 0x80 ) ;
V_9 -> V_16 |= V_17 | V_18 ;
F_2 ( & V_2 -> V_19 , V_9 -> V_16 ) ;
}
static int F_7 ( struct V_8 * V_9 )
{
return F_8 ( & F_5 ( V_9 ) -> V_20 )
& V_21 ;
}
static int F_9 ( struct V_8 * V_9 )
{
return F_8 ( & F_5 ( V_9 ) -> V_20 )
& V_22 ;
}
static int F_10 ( struct V_8 * V_9 )
{
return F_8 ( & F_5 ( V_9 ) -> V_23 )
& V_9 -> V_16
& V_17 ;
}
static int F_11 ( struct V_8 * V_9 )
{
return F_8 ( & F_5 ( V_9 ) -> V_23 )
& V_9 -> V_16
& V_18 ;
}
static int F_12 ( struct V_8 * V_9 )
{
return F_8 ( & F_5 ( V_9 ) -> V_20 )
& V_24 ;
}
static void F_13 ( struct V_8 * V_9 )
{
V_9 -> V_16 |= V_18 ;
F_2 ( & F_5 ( V_9 ) -> V_19 , V_9 -> V_16 ) ;
}
static void F_14 ( struct V_8 * V_9 )
{
V_9 -> V_16 &= ~ V_18 ;
F_2 ( & F_5 ( V_9 ) -> V_19 , V_9 -> V_16 ) ;
}
static void F_15 ( struct V_8 * V_9 )
{
V_9 -> V_16 &= ~ V_17 ;
F_2 ( & F_5 ( V_9 ) -> V_19 , V_9 -> V_16 ) ;
}
static void F_16 ( struct V_8 * V_9 )
{
}
static void F_17 ( struct V_8 * V_9 )
{
}
static void F_18 ( struct V_8 * V_9 , unsigned char V_25 )
{
F_3 ( & F_5 ( V_9 ) -> V_26 , V_25 ) ;
}
static unsigned char F_19 ( struct V_8 * V_9 )
{
return F_20 ( & F_5 ( V_9 ) -> V_26 ) ;
}
static void F_21 ( struct V_8 * V_9 )
{
F_2 ( & F_5 ( V_9 ) -> V_19 , 0 ) ;
}
static void F_22 ( struct V_8 * V_9 )
{
F_2 ( & F_5 ( V_9 ) -> V_19 , V_9 -> V_16 ) ;
}
static unsigned int F_23 ( struct V_8 * V_9 ,
struct V_27 * V_28 ,
struct V_27 * V_29 )
{
unsigned int V_30 ;
unsigned int V_4 ;
V_30 = F_24 ( V_9 , V_28 , V_29 ,
V_9 -> V_31 / ( 32 * 0xffff ) + 1 ,
V_9 -> V_31 / 32 ) ;
V_4 = ( V_9 -> V_31 + 16 * V_30 ) / ( 32 * V_30 ) ;
F_1 ( F_5 ( V_9 ) , 0xdd00 , V_4 ) ;
return V_30 ;
}
static unsigned int F_25 ( struct V_8 * V_9 ,
struct V_27 * V_28 ,
struct V_27 * V_29 )
{
unsigned int V_30 ;
unsigned int V_4 ;
T_2 V_3 ;
V_30 = F_24 ( V_9 , V_28 , V_29 ,
V_9 -> V_31 / ( 32 * 0xffff ) + 1 ,
V_9 -> V_31 / 4 ) ;
V_4 = ( V_9 -> V_31 + 2 * V_30 ) / ( 4 * V_30 ) ;
if ( V_4 > 0xffff || V_30 <= 115200 ) {
V_4 = ( V_4 + 4 ) / 8 ;
V_3 = 0xdd00 ;
} else
V_3 = 0xff00 ;
F_1 ( F_5 ( V_9 ) , V_3 , V_4 ) ;
return V_30 ;
}
static void F_26 ( struct V_8 * V_9 , struct V_32 * V_33 )
{
V_9 -> V_34 = 0 ;
V_9 -> V_35 = F_27 ( V_33 , 0 ) ;
}
static T_3 F_28 ( struct V_8 * V_9 )
{
return F_29 ( V_9 ) ;
}
static void F_30 ( struct V_8 * V_9 )
{
F_2 ( & F_5 ( V_9 ) -> V_5 , 0xdd00 ) ;
F_31 ( & F_32 ( V_9 ) -> V_36 , V_37 ) ;
F_31 ( & F_32 ( V_9 ) -> V_36 , V_38 ) ;
F_31 ( & F_32 ( V_9 ) -> V_39 , 1 ) ;
F_31 ( & F_32 ( V_9 ) -> V_40 , 0 ) ;
F_31 ( & F_32 ( V_9 ) -> V_41 , V_37 ) ;
F_31 ( & F_32 ( V_9 ) -> V_41 , V_38 ) ;
F_31 ( & F_32 ( V_9 ) -> V_42 , 1 ) ;
F_31 ( & F_32 ( V_9 ) -> V_43 , 0 ) ;
F_31 ( & F_32 ( V_9 ) -> V_40 , V_44 ) ;
F_31 ( & F_32 ( V_9 ) -> V_43 , V_44 ) ;
}
static int F_33 ( struct V_8 * V_9 )
{
return ! ( F_34 ( & F_32 ( V_9 ) -> V_45 ) & V_46 ) ;
}
static int F_35 ( struct V_8 * V_9 )
{
return ! ( F_34 ( & F_32 ( V_9 ) -> V_47 ) & V_48 ) ;
}
static int F_36 ( struct V_8 * V_9 )
{
return F_34 ( & F_32 ( V_9 ) -> V_45 )
& F_34 ( & F_32 ( V_9 ) -> V_43 )
& V_44 ;
}
static int F_37 ( struct V_8 * V_9 )
{
return F_34 ( & F_32 ( V_9 ) -> V_47 )
& F_34 ( & F_32 ( V_9 ) -> V_40 )
& V_44 ;
}
static int F_38 ( struct V_8 * V_9 )
{
return F_34 ( & F_32 ( V_9 ) -> V_47 )
& V_46 ;
}
static void F_39 ( struct V_8 * V_9 )
{
unsigned long V_49 ;
V_49 = F_34 ( & F_32 ( V_9 ) -> V_43 ) ;
V_49 &= ~ V_44 ;
F_31 ( & F_32 ( V_9 ) -> V_43 , V_49 ) ;
}
static void F_40 ( struct V_8 * V_9 )
{
unsigned long V_50 ;
V_50 = F_34 ( & F_32 ( V_9 ) -> V_40 ) ;
V_50 |= V_44 ;
F_31 ( & F_32 ( V_9 ) -> V_40 , V_50 ) ;
}
static void F_41 ( struct V_8 * V_9 )
{
unsigned long V_50 ;
V_50 = F_34 ( & F_32 ( V_9 ) -> V_40 ) ;
V_50 &= ~ V_44 ;
F_31 ( & F_32 ( V_9 ) -> V_40 , V_50 ) ;
}
static void F_42 ( struct V_8 * V_9 )
{
F_31 ( & F_32 ( V_9 ) -> V_51 , F_34 ( & F_32 ( V_9 ) -> V_51 ) ) ;
}
static void F_43 ( struct V_8 * V_9 )
{
F_31 ( & F_32 ( V_9 ) -> V_52 , F_34 ( & F_32 ( V_9 ) -> V_52 ) ) ;
}
static void F_44 ( struct V_8 * V_9 , unsigned char V_25 )
{
F_3 ( & F_32 ( V_9 ) -> V_53 , V_25 ) ;
}
static unsigned char F_45 ( struct V_8 * V_9 )
{
return F_20 ( & F_32 ( V_9 ) -> V_54 ) ;
}
static void F_46 ( struct V_8 * V_9 )
{
V_9 -> V_16 =
F_34 ( & F_32 ( V_9 ) -> V_40 ) << 16 |
F_34 ( & F_32 ( V_9 ) -> V_43 ) ;
F_31 ( & F_32 ( V_9 ) -> V_40 , 0 ) ;
F_31 ( & F_32 ( V_9 ) -> V_43 , 0 ) ;
}
static void F_47 ( struct V_8 * V_9 )
{
F_31 ( & F_32 ( V_9 ) -> V_40 ,
( V_9 -> V_16 >> 16 ) & 0x7f ) ;
F_31 ( & F_32 ( V_9 ) -> V_43 , V_9 -> V_16 & 0x7f ) ;
}
static unsigned int F_48 ( struct V_8 * V_9 ,
struct V_27 * V_28 ,
struct V_27 * V_29 )
{
unsigned int V_30 ;
unsigned int V_4 ;
V_30 = F_24 ( V_9 , V_28 , V_29 ,
V_9 -> V_31 / ( 16 * 0xffff ) + 1 ,
V_9 -> V_31 / 16 ) ;
V_4 = ( V_9 -> V_31 + 8 * V_30 ) / ( 16 * V_30 ) ;
F_1 ( F_5 ( V_9 ) , 0xdd00 , V_4 ) ;
return V_30 ;
}
static int T_4 F_49 ( void )
{
struct V_32 * V_33 ;
V_33 = F_50 ( NULL , NULL ,
L_1 ) ;
if ( ! V_33 ) {
F_51 ( L_2 , V_55 ) ;
return - V_56 ;
}
V_57 = F_52 ( V_33 , 0 ) ;
if ( ! V_57 ) {
F_51 ( L_3 , V_55 ) ;
F_53 ( V_33 ) ;
return - V_56 ;
}
V_58 = F_27 ( V_33 , 0 ) ;
F_53 ( V_33 ) ;
if ( V_58 == 0 ) {
F_51 ( L_4 , V_55 ) ;
F_54 ( V_57 ) ;
return - V_56 ;
}
return 0 ;
}
static void T_5 F_55 ( void )
{
F_54 ( V_57 ) ;
}
static T_3 F_56 ( struct V_8 * V_9 )
{
unsigned long V_59 ;
int V_60 ;
V_59 = F_34 ( & V_57 -> V_59 ) ;
V_60 = ( V_9 -> V_61 & 0xf00 ) >> 8 ;
if ( F_57 ( V_60 , & V_59 ) ||
F_57 ( V_60 + 16 , & V_59 ) )
return F_29 ( V_9 ) ;
return V_62 ;
}
static int F_58 ( struct V_8 * V_9 , int V_63 )
{
struct V_64 * V_65 ;
int V_60 ;
char V_66 [ 10 ] ;
if ( F_59 ( V_9 ) )
return 0 ;
V_60 = ( V_9 -> V_61 & 0xf00 ) >> 8 ;
snprintf ( V_66 , sizeof( V_66 ) , L_5 , V_60 ) ;
V_65 = F_60 ( V_9 -> V_67 , V_66 ) ;
if ( F_61 ( V_65 ) ) {
F_62 ( V_9 -> V_67 , L_6 ) ;
return - V_56 ;
}
F_63 ( V_9 -> V_67 , L_7 , V_66 , V_63 ? L_8 : L_9 ) ;
if ( V_63 )
F_64 ( V_65 ) ;
else
F_65 ( V_65 ) ;
return 0 ;
}
static void F_66 ( struct V_8 * V_9 , struct V_32 * V_33 )
{
V_9 -> V_34 = V_68 ;
V_9 -> V_35 = V_58 ;
}
static unsigned int
F_67 ( struct V_8 * V_9 )
{
return V_69 -> V_70 ( V_9 ) ? V_71 : 0 ;
}
static void
F_68 ( struct V_8 * V_9 , unsigned int V_72 )
{
if ( V_72 & V_73 )
F_3 ( & F_5 ( V_9 ) -> V_74 , V_75 ) ;
else
F_3 ( & F_5 ( V_9 ) -> V_76 , V_75 ) ;
}
static unsigned int
F_69 ( struct V_8 * V_9 )
{
unsigned int V_77 = V_78 ;
T_6 V_79 = F_20 ( & F_5 ( V_9 ) -> V_80 ) ;
if ( ! ( V_79 & V_81 ) )
V_77 |= V_82 ;
if ( ! ( V_79 & V_83 ) )
V_77 |= V_84 ;
return V_77 ;
}
static void
F_70 ( struct V_8 * V_9 )
{
V_69 -> V_85 ( V_9 ) ;
}
static void
F_71 ( struct V_8 * V_9 )
{
V_69 -> V_86 ( V_9 ) ;
}
static void
F_72 ( struct V_8 * V_9 , char V_87 )
{
unsigned long V_88 ;
F_73 ( & V_9 -> V_89 , V_88 ) ;
V_9 -> V_90 = V_87 ;
if ( V_87 ) {
V_69 -> V_86 ( V_9 ) ;
}
F_74 ( & V_9 -> V_89 , V_88 ) ;
}
static void
F_75 ( struct V_8 * V_9 )
{
V_69 -> V_91 ( V_9 ) ;
}
static void
F_76 ( struct V_8 * V_9 )
{
struct V_1 T_1 * V_2 = F_5 ( V_9 ) ;
F_20 ( & V_2 -> V_80 ) ;
F_3 ( & V_2 -> V_92 , V_93 | V_94 ) ;
V_9 -> V_16 |= V_95 ;
F_2 ( & V_2 -> V_19 , V_9 -> V_16 ) ;
}
static void
F_77 ( struct V_8 * V_9 , int V_96 )
{
unsigned long V_88 ;
F_73 ( & V_9 -> V_89 , V_88 ) ;
if ( V_96 == - 1 )
F_3 ( & F_5 ( V_9 ) -> V_97 , V_98 ) ;
else
F_3 ( & F_5 ( V_9 ) -> V_97 , V_99 ) ;
F_74 ( & V_9 -> V_89 , V_88 ) ;
}
static int
F_78 ( struct V_8 * V_9 )
{
struct V_1 T_1 * V_2 = F_5 ( V_9 ) ;
int V_77 ;
if ( V_69 -> clock ) {
V_77 = V_69 -> clock ( V_9 , 1 ) ;
if ( V_77 )
return V_77 ;
}
V_77 = F_79 ( V_9 -> V_35 , V_100 ,
V_9 -> V_34 , L_10 , V_9 ) ;
if ( V_77 )
return V_77 ;
F_3 ( & V_2 -> V_97 , V_101 ) ;
F_3 ( & V_2 -> V_97 , V_102 ) ;
F_31 ( & V_2 -> V_103 , 0 ) ;
V_69 -> V_104 ( V_9 ) ;
F_3 ( & V_2 -> V_97 , V_105 ) ;
F_3 ( & V_2 -> V_97 , V_106 ) ;
return 0 ;
}
static void
F_80 ( struct V_8 * V_9 )
{
struct V_1 T_1 * V_2 = F_5 ( V_9 ) ;
F_3 ( & V_2 -> V_97 , V_101 ) ;
if ( ! F_59 ( V_9 ) )
F_3 ( & V_2 -> V_97 , V_102 ) ;
V_9 -> V_16 = 0 ;
F_2 ( & V_2 -> V_19 , V_9 -> V_16 ) ;
if ( V_69 -> clock )
V_69 -> clock ( V_9 , 0 ) ;
F_81 ( V_9 -> V_35 , V_9 ) ;
}
static void
F_82 ( struct V_8 * V_9 , struct V_27 * V_28 ,
struct V_27 * V_29 )
{
struct V_1 T_1 * V_2 = F_5 ( V_9 ) ;
unsigned long V_88 ;
unsigned char V_107 , V_108 ;
unsigned int V_109 ;
unsigned int V_30 ;
V_107 = 0 ;
switch ( V_28 -> V_110 & V_111 ) {
case V_112 : V_107 |= V_113 ;
break;
case V_114 : V_107 |= V_115 ;
break;
case V_116 : V_107 |= V_117 ;
break;
case V_118 :
default: V_107 |= V_119 ;
}
if ( V_28 -> V_110 & V_120 ) {
if ( V_28 -> V_110 & V_121 )
V_107 |= V_122 ;
V_107 |= ( V_28 -> V_110 & V_123 ) ?
V_124 : V_125 ;
} else {
V_107 |= V_126 ;
}
V_108 = 0 ;
if ( V_28 -> V_110 & V_127 )
V_108 |= V_128 ;
else
V_108 |= ( ( V_28 -> V_110 & V_111 ) == V_112 ) ?
V_129 :
V_130 ;
if ( V_28 -> V_110 & V_131 ) {
V_107 |= V_132 ;
V_108 |= V_133 ;
}
F_73 ( & V_9 -> V_89 , V_88 ) ;
V_109 = 5000000 ;
while ( ! F_67 ( V_9 ) && -- V_109 )
F_83 ( 1 ) ;
if ( ! V_109 )
F_84 ( V_134 L_11
L_12
L_13 ) ;
F_3 ( & V_2 -> V_97 , V_101 ) ;
F_3 ( & V_2 -> V_97 , V_102 ) ;
F_3 ( & V_2 -> V_97 , V_135 ) ;
F_3 ( & V_2 -> V_136 , V_107 ) ;
F_3 ( & V_2 -> V_136 , V_108 ) ;
V_30 = V_69 -> V_137 ( V_9 , V_28 , V_29 ) ;
F_85 ( V_9 , V_28 -> V_110 , V_30 ) ;
if ( F_86 ( V_9 , V_28 -> V_110 ) )
F_76 ( V_9 ) ;
F_3 ( & V_2 -> V_97 , V_105 ) ;
F_3 ( & V_2 -> V_97 , V_106 ) ;
F_74 ( & V_9 -> V_89 , V_88 ) ;
}
static const char *
F_87 ( struct V_8 * V_9 )
{
return V_9 -> type == V_138 ? L_14 : NULL ;
}
static void
F_88 ( struct V_8 * V_9 )
{
if ( V_9 -> V_88 & V_139 ) {
F_54 ( V_9 -> V_140 ) ;
V_9 -> V_140 = NULL ;
}
F_89 ( V_9 -> V_61 , sizeof( struct V_1 ) ) ;
}
static int
F_90 ( struct V_8 * V_9 )
{
int V_141 ;
if ( V_9 -> V_88 & V_139 )
V_9 -> V_140 = F_91 ( V_9 -> V_61 ,
sizeof( struct V_1 ) ) ;
if ( ! V_9 -> V_140 )
return - V_142 ;
V_141 = F_92 ( V_9 -> V_61 , sizeof( struct V_1 ) ,
L_10 ) != NULL ? 0 : - V_143 ;
if ( V_141 && ( V_9 -> V_88 & V_139 ) ) {
F_54 ( V_9 -> V_140 ) ;
V_9 -> V_140 = NULL ;
}
return V_141 ;
}
static void
F_93 ( struct V_8 * V_9 , int V_88 )
{
if ( ( V_88 & V_144 )
&& ( F_90 ( V_9 ) == 0 ) )
V_9 -> type = V_138 ;
}
static int
F_94 ( struct V_8 * V_9 , struct V_145 * V_146 )
{
if ( V_146 -> type != V_147 && V_146 -> type != V_138 )
return - V_142 ;
if ( ( V_146 -> V_35 != V_9 -> V_35 ) ||
( V_146 -> V_148 != V_149 ) ||
( V_146 -> V_150 != V_9 -> V_31 ) ||
( V_146 -> V_151 != ( void * ) V_9 -> V_61 ) ||
( V_146 -> V_152 != 0 ) )
return - V_142 ;
return 0 ;
}
static inline int
F_95 ( struct V_8 * V_9 )
{
struct V_153 * V_154 = & V_9 -> V_155 -> V_9 ;
unsigned char V_87 , V_156 ;
unsigned short V_79 ;
while ( V_69 -> V_157 ( V_9 ) ) {
V_87 = V_69 -> V_158 ( V_9 ) ;
#ifdef F_96
if ( F_97 ( V_9 , V_87 ) ) {
V_9 -> V_159 = 0 ;
continue;
}
#endif
V_156 = V_160 ;
V_9 -> V_161 . V_162 ++ ;
V_79 = F_8 ( & F_5 ( V_9 ) -> V_20 ) ;
if ( V_79 & ( V_163 |
V_164 |
V_165 ) ) {
if ( V_79 & V_165 ) {
V_156 = V_166 ;
F_98 ( V_9 ) ;
V_9 -> V_161 . V_167 ++ ;
} else if ( V_79 & V_163 ) {
V_156 = V_168 ;
V_9 -> V_161 . V_169 ++ ;
}
else if ( V_79 & V_164 ) {
V_156 = V_170 ;
V_9 -> V_161 . V_171 ++ ;
}
F_3 ( & F_5 ( V_9 ) -> V_97 , V_172 ) ;
}
F_99 ( V_154 , V_87 , V_156 ) ;
if ( V_79 & V_173 ) {
F_99 ( V_154 , 0 , V_174 ) ;
V_9 -> V_161 . V_175 ++ ;
}
}
F_100 ( & V_9 -> V_89 ) ;
F_101 ( V_154 ) ;
F_102 ( & V_9 -> V_89 ) ;
return V_69 -> V_157 ( V_9 ) ;
}
static inline int
F_103 ( struct V_8 * V_9 )
{
struct V_176 * V_177 = & V_9 -> V_155 -> V_177 ;
if ( V_9 -> V_90 ) {
V_69 -> V_178 ( V_9 , V_9 -> V_90 ) ;
V_9 -> V_161 . V_179 ++ ;
V_9 -> V_90 = 0 ;
return 1 ;
}
if ( F_104 ( V_177 ) || F_105 ( V_9 ) ) {
F_70 ( V_9 ) ;
return 0 ;
}
while ( V_69 -> V_180 ( V_9 ) ) {
V_69 -> V_178 ( V_9 , V_177 -> V_181 [ V_177 -> V_182 ] ) ;
V_177 -> V_182 = ( V_177 -> V_182 + 1 ) & ( V_183 - 1 ) ;
V_9 -> V_161 . V_179 ++ ;
if ( F_104 ( V_177 ) )
break;
}
if ( F_106 ( V_177 ) < V_184 )
F_107 ( V_9 ) ;
if ( F_104 ( V_177 ) ) {
F_70 ( V_9 ) ;
return 0 ;
}
return 1 ;
}
static T_3
F_29 ( struct V_8 * V_9 )
{
unsigned long V_185 = V_186 ;
unsigned int V_187 ;
T_6 V_79 ;
do {
V_187 = 0 ;
V_69 -> V_188 ( V_9 ) ;
if ( V_69 -> V_189 ( V_9 ) )
V_187 |= F_95 ( V_9 ) ;
V_69 -> V_190 ( V_9 ) ;
if ( V_69 -> V_191 ( V_9 ) )
V_187 |= F_103 ( V_9 ) ;
V_79 = F_20 ( & F_5 ( V_9 ) -> V_80 ) ;
if ( V_79 & V_192 )
F_108 ( V_9 , ! ( V_79 & V_83 ) ) ;
if ( V_79 & V_193 )
F_109 ( V_9 , ! ( V_79 & V_81 ) ) ;
if ( ! ( -- V_185 ) )
V_187 = 0 ;
} while ( V_187 );
return V_194 ;
}
static T_3
V_100 ( int V_35 , void * V_195 )
{
struct V_8 * V_9 = V_195 ;
T_3 V_77 ;
F_102 ( & V_9 -> V_89 ) ;
V_77 = V_69 -> V_196 ( V_9 ) ;
F_100 ( & V_9 -> V_89 ) ;
return V_77 ;
}
static void T_4
F_110 ( struct V_8 * V_9 ,
int * V_30 , int * V_169 , int * V_197 , int * V_198 )
{
struct V_1 T_1 * V_2 = F_5 ( V_9 ) ;
unsigned char V_107 ;
F_111 ( L_15 , V_9 ) ;
F_3 ( & V_2 -> V_97 , V_135 ) ;
V_107 = F_20 ( & V_2 -> V_136 ) ;
* V_30 = V_199 ;
switch ( V_107 & V_200 ) {
case V_113 :
* V_197 = 5 ;
break;
case V_115 :
* V_197 = 6 ;
break;
case V_117 :
* V_197 = 7 ;
break;
case V_119 :
default:
* V_197 = 8 ;
}
if ( V_107 & V_126 )
* V_169 = 'n' ;
else
* V_169 = V_107 & V_124 ? 'o' : 'e' ;
}
static void
F_112 ( struct V_201 * V_202 , const char * V_203 , unsigned int V_204 )
{
struct V_8 * V_9 = & V_205 [ V_202 -> V_206 ] ;
unsigned int V_207 , V_109 ;
V_69 -> V_208 ( V_9 ) ;
V_109 = 5000000 ;
while ( ! F_67 ( V_9 ) && -- V_109 )
F_83 ( 1 ) ;
for ( V_207 = 0 ; V_207 < V_204 ; V_207 ++ , V_203 ++ ) {
if ( * V_203 == '\n' )
V_69 -> V_178 ( V_9 , '\r' ) ;
V_69 -> V_178 ( V_9 , * V_203 ) ;
V_109 = 20000 ;
while ( ! F_67 ( V_9 ) && -- V_109 )
F_83 ( 1 ) ;
}
V_69 -> V_209 ( V_9 ) ;
}
static int T_4
F_113 ( struct V_201 * V_202 , char * V_210 )
{
struct V_8 * V_9 = & V_205 [ V_202 -> V_206 ] ;
struct V_32 * V_33 = V_211 [ V_202 -> V_206 ] ;
unsigned int V_31 ;
struct V_212 V_213 ;
int V_77 ;
int V_30 = V_199 ;
int V_197 = 8 ;
int V_169 = 'n' ;
int V_198 = 'n' ;
F_111 ( L_16 ,
V_202 , V_202 -> V_206 , V_210 ) ;
if ( ( V_202 -> V_206 < 0 ) || ( V_202 -> V_206 >= V_214 ) ) {
F_111 ( L_17 , V_202 -> V_206 ) ;
return - V_142 ;
}
if ( ! V_33 ) {
F_111 ( L_18 , V_202 -> V_206 ) ;
return - V_142 ;
}
F_111 ( L_19 ,
V_202 -> V_206 , V_211 [ V_202 -> V_206 ] -> V_215 ) ;
V_77 = F_114 ( V_33 , 0 , & V_213 ) ;
if ( V_77 ) {
F_111 ( L_20 , V_202 -> V_206 ) ;
return V_77 ;
}
V_31 = F_115 ( V_33 ) ;
if ( V_31 == 0 ) {
F_111 ( L_21 ) ;
return - V_142 ;
}
F_116 ( & V_9 -> V_89 ) ;
V_9 -> V_31 = V_31 ;
V_9 -> V_216 = & V_217 ;
V_9 -> V_61 = V_213 . V_218 ;
V_9 -> V_140 = F_91 ( V_213 . V_218 , sizeof( struct V_1 ) ) ;
V_9 -> V_35 = F_27 ( V_33 , 0 ) ;
if ( V_9 -> V_140 == NULL )
return - V_142 ;
F_111 ( L_22 ,
( void * ) V_9 -> V_61 , V_9 -> V_140 ,
V_9 -> V_35 , V_9 -> V_31 ) ;
if ( V_210 )
F_117 ( V_210 , & V_30 , & V_169 , & V_197 , & V_198 ) ;
else
F_110 ( V_9 , & V_30 , & V_169 , & V_197 , & V_198 ) ;
F_111 ( L_23 ,
V_30 , V_197 , V_169 , V_198 ) ;
return F_118 ( V_9 , V_202 , V_30 , V_169 , V_197 , V_198 ) ;
}
static int T_4
F_119 ( void )
{
F_120 () ;
F_121 ( & V_219 ) ;
return 0 ;
}
static int F_122 ( struct V_220 * V_221 )
{
int V_222 = - 1 ;
unsigned int V_31 ;
struct V_8 * V_9 = NULL ;
struct V_212 V_213 ;
int V_77 ;
for ( V_222 = 0 ; V_222 < V_214 ; V_222 ++ )
if ( V_211 [ V_222 ] == V_221 -> V_67 . V_223 )
break;
if ( V_222 >= V_214 )
return - V_142 ;
F_111 ( L_24 ,
V_211 [ V_222 ] -> V_215 , V_222 ) ;
V_31 = F_115 ( V_221 -> V_67 . V_223 ) ;
if ( V_31 == 0 ) {
F_63 ( & V_221 -> V_67 , L_21 ) ;
return - V_142 ;
}
V_9 = & V_205 [ V_222 ] ;
F_116 ( & V_9 -> V_89 ) ;
V_9 -> V_31 = V_31 ;
V_9 -> V_224 = 512 ;
V_9 -> V_225 = V_149 ;
V_9 -> V_88 = V_226 |
( F_59 ( V_9 ) ? 0 : V_139 ) ;
V_9 -> line = V_222 ;
V_9 -> V_216 = & V_217 ;
V_9 -> V_67 = & V_221 -> V_67 ;
V_77 = F_114 ( V_221 -> V_67 . V_223 , 0 , & V_213 ) ;
if ( V_77 )
return V_77 ;
V_9 -> V_61 = V_213 . V_218 ;
if ( ! V_9 -> V_61 ) {
F_63 ( & V_221 -> V_67 , L_25 ) ;
return - V_142 ;
}
V_69 -> V_227 ( V_9 , V_221 -> V_67 . V_223 ) ;
if ( V_9 -> V_35 == 0 ) {
F_63 ( & V_221 -> V_67 , L_26 ) ;
return - V_142 ;
}
F_63 ( & V_221 -> V_67 , L_27 ,
( void * ) V_9 -> V_61 , V_9 -> V_35 , V_9 -> V_31 ) ;
V_77 = F_123 ( & V_228 , V_9 ) ;
if ( V_77 )
return V_77 ;
F_124 ( & V_221 -> V_67 , ( void * ) V_9 ) ;
return 0 ;
}
static int
F_125 ( struct V_220 * V_221 )
{
struct V_8 * V_9 = F_126 ( & V_221 -> V_67 ) ;
F_124 ( & V_221 -> V_67 , NULL ) ;
if ( V_9 )
F_127 ( & V_228 , V_9 ) ;
return 0 ;
}
static int
F_128 ( struct V_220 * V_221 , T_7 V_155 )
{
struct V_8 * V_9 = (struct V_8 * ) F_126 ( & V_221 -> V_67 ) ;
if ( V_9 )
F_129 ( & V_228 , V_9 ) ;
return 0 ;
}
static int
F_130 ( struct V_220 * V_221 )
{
struct V_8 * V_9 = (struct V_8 * ) F_126 ( & V_221 -> V_67 ) ;
if ( V_9 )
F_131 ( & V_228 , V_9 ) ;
return 0 ;
}
static void
F_132 ( struct V_32 * V_33 )
{
int V_207 ;
for ( V_207 = 0 ; V_207 < V_214 ; V_207 ++ ) {
if ( V_211 [ V_207 ] == NULL ) {
F_133 ( V_33 ) ;
V_211 [ V_207 ] = V_33 ;
return;
}
}
}
static void
F_120 ( void )
{
static int V_229 ;
struct V_32 * V_33 ;
const struct V_230 * V_231 ;
int V_207 ;
if ( V_229 )
return;
F_134 (np, mpc52xx_uart_of_match) {
V_231 = F_135 ( V_232 , V_33 ) ;
V_69 = V_231 -> V_233 ;
F_132 ( V_33 ) ;
}
V_229 = 1 ;
for ( V_207 = 0 ; V_207 < V_214 ; V_207 ++ ) {
if ( V_211 [ V_207 ] )
F_111 ( L_28 ,
V_211 [ V_207 ] -> V_215 , V_207 ) ;
}
}
static int T_4
F_136 ( void )
{
int V_77 ;
F_84 ( V_234 L_29 ) ;
V_77 = F_137 ( & V_228 ) ;
if ( V_77 ) {
F_84 ( V_134 L_30 ,
__FILE__ , V_77 ) ;
return V_77 ;
}
F_120 () ;
if ( V_69 && V_69 -> V_235 ) {
V_77 = V_69 -> V_235 () ;
if ( V_77 )
return V_77 ;
}
V_77 = F_138 ( & V_236 ) ;
if ( V_77 ) {
F_84 ( V_134 L_31 ,
__FILE__ , V_77 ) ;
F_139 ( & V_228 ) ;
return V_77 ;
}
return 0 ;
}
static void T_5
F_140 ( void )
{
if ( V_69 -> V_237 )
V_69 -> V_237 () ;
F_141 ( & V_236 ) ;
F_139 ( & V_228 ) ;
}
