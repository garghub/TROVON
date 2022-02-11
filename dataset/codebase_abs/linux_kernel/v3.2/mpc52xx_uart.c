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
if ( V_4 > 0xffff ) {
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
if ( V_58 == V_59 ) {
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
unsigned long V_60 ;
int V_61 ;
V_60 = F_34 ( & V_57 -> V_60 ) ;
V_61 = ( V_9 -> V_62 & 0xf00 ) >> 8 ;
if ( F_57 ( V_61 , & V_60 ) ||
F_57 ( V_61 + 16 , & V_60 ) )
return F_29 ( V_9 ) ;
return V_63 ;
}
static int F_58 ( struct V_8 * V_9 , int V_64 )
{
struct V_65 * V_66 ;
int V_61 ;
char V_67 [ 10 ] ;
if ( F_59 ( V_9 ) )
return 0 ;
V_61 = ( V_9 -> V_62 & 0xf00 ) >> 8 ;
snprintf ( V_67 , sizeof( V_67 ) , L_5 , V_61 ) ;
V_66 = F_60 ( V_9 -> V_68 , V_67 ) ;
if ( F_61 ( V_66 ) ) {
F_62 ( V_9 -> V_68 , L_6 ) ;
return - V_56 ;
}
F_63 ( V_9 -> V_68 , L_7 , V_67 , V_64 ? L_8 : L_9 ) ;
if ( V_64 )
F_64 ( V_66 ) ;
else
F_65 ( V_66 ) ;
return 0 ;
}
static void F_66 ( struct V_8 * V_9 , struct V_32 * V_33 )
{
V_9 -> V_34 = V_69 ;
V_9 -> V_35 = V_58 ;
}
static unsigned int
F_67 ( struct V_8 * V_9 )
{
return V_70 -> V_71 ( V_9 ) ? V_72 : 0 ;
}
static void
F_68 ( struct V_8 * V_9 , unsigned int V_73 )
{
if ( V_73 & V_74 )
F_3 ( & F_5 ( V_9 ) -> V_75 , V_76 ) ;
else
F_3 ( & F_5 ( V_9 ) -> V_77 , V_76 ) ;
}
static unsigned int
F_69 ( struct V_8 * V_9 )
{
unsigned int V_78 = V_79 ;
T_6 V_80 = F_20 ( & F_5 ( V_9 ) -> V_81 ) ;
if ( ! ( V_80 & V_82 ) )
V_78 |= V_83 ;
if ( ! ( V_80 & V_84 ) )
V_78 |= V_85 ;
return V_78 ;
}
static void
F_70 ( struct V_8 * V_9 )
{
V_70 -> V_86 ( V_9 ) ;
}
static void
F_71 ( struct V_8 * V_9 )
{
V_70 -> V_87 ( V_9 ) ;
}
static void
F_72 ( struct V_8 * V_9 , char V_88 )
{
unsigned long V_89 ;
F_73 ( & V_9 -> V_90 , V_89 ) ;
V_9 -> V_91 = V_88 ;
if ( V_88 ) {
V_70 -> V_87 ( V_9 ) ;
}
F_74 ( & V_9 -> V_90 , V_89 ) ;
}
static void
F_75 ( struct V_8 * V_9 )
{
V_70 -> V_92 ( V_9 ) ;
}
static void
F_76 ( struct V_8 * V_9 )
{
struct V_1 T_1 * V_2 = F_5 ( V_9 ) ;
F_20 ( & V_2 -> V_81 ) ;
F_3 ( & V_2 -> V_93 , V_94 | V_95 ) ;
V_9 -> V_16 |= V_96 ;
F_2 ( & V_2 -> V_19 , V_9 -> V_16 ) ;
}
static void
F_77 ( struct V_8 * V_9 , int V_97 )
{
unsigned long V_89 ;
F_73 ( & V_9 -> V_90 , V_89 ) ;
if ( V_97 == - 1 )
F_3 ( & F_5 ( V_9 ) -> V_98 , V_99 ) ;
else
F_3 ( & F_5 ( V_9 ) -> V_98 , V_100 ) ;
F_74 ( & V_9 -> V_90 , V_89 ) ;
}
static int
F_78 ( struct V_8 * V_9 )
{
struct V_1 T_1 * V_2 = F_5 ( V_9 ) ;
int V_78 ;
if ( V_70 -> clock ) {
V_78 = V_70 -> clock ( V_9 , 1 ) ;
if ( V_78 )
return V_78 ;
}
V_78 = F_79 ( V_9 -> V_35 , V_101 ,
V_9 -> V_34 , L_10 , V_9 ) ;
if ( V_78 )
return V_78 ;
F_3 ( & V_2 -> V_98 , V_102 ) ;
F_3 ( & V_2 -> V_98 , V_103 ) ;
F_31 ( & V_2 -> V_104 , 0 ) ;
V_70 -> V_105 ( V_9 ) ;
F_3 ( & V_2 -> V_98 , V_106 ) ;
F_3 ( & V_2 -> V_98 , V_107 ) ;
return 0 ;
}
static void
F_80 ( struct V_8 * V_9 )
{
struct V_1 T_1 * V_2 = F_5 ( V_9 ) ;
F_3 ( & V_2 -> V_98 , V_102 ) ;
if ( ! F_59 ( V_9 ) )
F_3 ( & V_2 -> V_98 , V_103 ) ;
V_9 -> V_16 = 0 ;
F_2 ( & V_2 -> V_19 , V_9 -> V_16 ) ;
if ( V_70 -> clock )
V_70 -> clock ( V_9 , 0 ) ;
F_81 ( V_9 -> V_35 , V_9 ) ;
}
static void
F_82 ( struct V_8 * V_9 , struct V_27 * V_28 ,
struct V_27 * V_29 )
{
struct V_1 T_1 * V_2 = F_5 ( V_9 ) ;
unsigned long V_89 ;
unsigned char V_108 , V_109 ;
unsigned int V_110 ;
unsigned int V_30 ;
V_108 = 0 ;
switch ( V_28 -> V_111 & V_112 ) {
case V_113 : V_108 |= V_114 ;
break;
case V_115 : V_108 |= V_116 ;
break;
case V_117 : V_108 |= V_118 ;
break;
case V_119 :
default: V_108 |= V_120 ;
}
if ( V_28 -> V_111 & V_121 ) {
V_108 |= ( V_28 -> V_111 & V_122 ) ?
V_123 : V_124 ;
} else
V_108 |= V_125 ;
V_109 = 0 ;
if ( V_28 -> V_111 & V_126 )
V_109 |= V_127 ;
else
V_109 |= ( ( V_28 -> V_111 & V_112 ) == V_113 ) ?
V_128 :
V_129 ;
if ( V_28 -> V_111 & V_130 ) {
V_108 |= V_131 ;
V_109 |= V_132 ;
}
F_73 ( & V_9 -> V_90 , V_89 ) ;
V_110 = 5000000 ;
while ( ! F_67 ( V_9 ) && -- V_110 )
F_83 ( 1 ) ;
if ( ! V_110 )
F_84 ( V_133 L_11
L_12
L_13 ) ;
F_3 ( & V_2 -> V_98 , V_102 ) ;
F_3 ( & V_2 -> V_98 , V_103 ) ;
F_3 ( & V_2 -> V_98 , V_134 ) ;
F_3 ( & V_2 -> V_135 , V_108 ) ;
F_3 ( & V_2 -> V_135 , V_109 ) ;
V_30 = V_70 -> V_136 ( V_9 , V_28 , V_29 ) ;
F_85 ( V_9 , V_28 -> V_111 , V_30 ) ;
if ( F_86 ( V_9 , V_28 -> V_111 ) )
F_76 ( V_9 ) ;
F_3 ( & V_2 -> V_98 , V_106 ) ;
F_3 ( & V_2 -> V_98 , V_107 ) ;
F_74 ( & V_9 -> V_90 , V_89 ) ;
}
static const char *
F_87 ( struct V_8 * V_9 )
{
return V_9 -> type == V_137 ? L_14 : NULL ;
}
static void
F_88 ( struct V_8 * V_9 )
{
if ( V_9 -> V_89 & V_138 ) {
F_54 ( V_9 -> V_139 ) ;
V_9 -> V_139 = NULL ;
}
F_89 ( V_9 -> V_62 , sizeof( struct V_1 ) ) ;
}
static int
F_90 ( struct V_8 * V_9 )
{
int V_140 ;
if ( V_9 -> V_89 & V_138 )
V_9 -> V_139 = F_91 ( V_9 -> V_62 ,
sizeof( struct V_1 ) ) ;
if ( ! V_9 -> V_139 )
return - V_141 ;
V_140 = F_92 ( V_9 -> V_62 , sizeof( struct V_1 ) ,
L_10 ) != NULL ? 0 : - V_142 ;
if ( V_140 && ( V_9 -> V_89 & V_138 ) ) {
F_54 ( V_9 -> V_139 ) ;
V_9 -> V_139 = NULL ;
}
return V_140 ;
}
static void
F_93 ( struct V_8 * V_9 , int V_89 )
{
if ( ( V_89 & V_143 )
&& ( F_90 ( V_9 ) == 0 ) )
V_9 -> type = V_137 ;
}
static int
F_94 ( struct V_8 * V_9 , struct V_144 * V_145 )
{
if ( V_145 -> type != V_146 && V_145 -> type != V_137 )
return - V_141 ;
if ( ( V_145 -> V_35 != V_9 -> V_35 ) ||
( V_145 -> V_147 != V_148 ) ||
( V_145 -> V_149 != V_9 -> V_31 ) ||
( V_145 -> V_150 != ( void * ) V_9 -> V_62 ) ||
( V_145 -> V_151 != 0 ) )
return - V_141 ;
return 0 ;
}
static inline int
F_95 ( struct V_8 * V_9 )
{
struct V_152 * V_153 = V_9 -> V_154 -> V_9 . V_153 ;
unsigned char V_88 , V_155 ;
unsigned short V_80 ;
while ( V_70 -> V_156 ( V_9 ) ) {
V_88 = V_70 -> V_157 ( V_9 ) ;
#ifdef F_96
if ( F_97 ( V_9 , V_88 ) ) {
V_9 -> V_158 = 0 ;
continue;
}
#endif
V_155 = V_159 ;
V_9 -> V_160 . V_161 ++ ;
V_80 = F_8 ( & F_5 ( V_9 ) -> V_20 ) ;
if ( V_80 & ( V_162 |
V_163 |
V_164 ) ) {
if ( V_80 & V_164 ) {
V_155 = V_165 ;
F_98 ( V_9 ) ;
V_9 -> V_160 . V_166 ++ ;
} else if ( V_80 & V_162 ) {
V_155 = V_167 ;
V_9 -> V_160 . V_168 ++ ;
}
else if ( V_80 & V_163 ) {
V_155 = V_169 ;
V_9 -> V_160 . V_170 ++ ;
}
F_3 ( & F_5 ( V_9 ) -> V_98 , V_171 ) ;
}
F_99 ( V_153 , V_88 , V_155 ) ;
if ( V_80 & V_172 ) {
F_99 ( V_153 , 0 , V_173 ) ;
V_9 -> V_160 . V_174 ++ ;
}
}
F_100 ( & V_9 -> V_90 ) ;
F_101 ( V_153 ) ;
F_102 ( & V_9 -> V_90 ) ;
return V_70 -> V_156 ( V_9 ) ;
}
static inline int
F_103 ( struct V_8 * V_9 )
{
struct V_175 * V_176 = & V_9 -> V_154 -> V_176 ;
if ( V_9 -> V_91 ) {
V_70 -> V_177 ( V_9 , V_9 -> V_91 ) ;
V_9 -> V_160 . V_178 ++ ;
V_9 -> V_91 = 0 ;
return 1 ;
}
if ( F_104 ( V_176 ) || F_105 ( V_9 ) ) {
F_70 ( V_9 ) ;
return 0 ;
}
while ( V_70 -> V_179 ( V_9 ) ) {
V_70 -> V_177 ( V_9 , V_176 -> V_180 [ V_176 -> V_181 ] ) ;
V_176 -> V_181 = ( V_176 -> V_181 + 1 ) & ( V_182 - 1 ) ;
V_9 -> V_160 . V_178 ++ ;
if ( F_104 ( V_176 ) )
break;
}
if ( F_106 ( V_176 ) < V_183 )
F_107 ( V_9 ) ;
if ( F_104 ( V_176 ) ) {
F_70 ( V_9 ) ;
return 0 ;
}
return 1 ;
}
static T_3
F_29 ( struct V_8 * V_9 )
{
unsigned long V_184 = V_185 ;
unsigned int V_186 ;
T_6 V_80 ;
do {
V_186 = 0 ;
V_70 -> V_187 ( V_9 ) ;
if ( V_70 -> V_188 ( V_9 ) )
V_186 |= F_95 ( V_9 ) ;
V_70 -> V_189 ( V_9 ) ;
if ( V_70 -> V_190 ( V_9 ) )
V_186 |= F_103 ( V_9 ) ;
V_80 = F_20 ( & F_5 ( V_9 ) -> V_81 ) ;
if ( V_80 & V_191 )
F_108 ( V_9 , ! ( V_80 & V_84 ) ) ;
if ( V_80 & V_192 )
F_109 ( V_9 , ! ( V_80 & V_82 ) ) ;
if ( ! ( -- V_184 ) )
V_186 = 0 ;
} while ( V_186 );
return V_193 ;
}
static T_3
V_101 ( int V_35 , void * V_194 )
{
struct V_8 * V_9 = V_194 ;
T_3 V_78 ;
F_102 ( & V_9 -> V_90 ) ;
V_78 = V_70 -> V_195 ( V_9 ) ;
F_100 ( & V_9 -> V_90 ) ;
return V_78 ;
}
static void T_4
F_110 ( struct V_8 * V_9 ,
int * V_30 , int * V_168 , int * V_196 , int * V_197 )
{
struct V_1 T_1 * V_2 = F_5 ( V_9 ) ;
unsigned char V_108 ;
F_111 ( L_15 , V_9 ) ;
F_3 ( & V_2 -> V_98 , V_134 ) ;
V_108 = F_20 ( & V_2 -> V_135 ) ;
* V_30 = V_198 ;
switch ( V_108 & V_199 ) {
case V_114 :
* V_196 = 5 ;
break;
case V_116 :
* V_196 = 6 ;
break;
case V_118 :
* V_196 = 7 ;
break;
case V_120 :
default:
* V_196 = 8 ;
}
if ( V_108 & V_125 )
* V_168 = 'n' ;
else
* V_168 = V_108 & V_123 ? 'o' : 'e' ;
}
static void
F_112 ( struct V_200 * V_201 , const char * V_202 , unsigned int V_203 )
{
struct V_8 * V_9 = & V_204 [ V_201 -> V_205 ] ;
unsigned int V_206 , V_110 ;
V_70 -> V_207 ( V_9 ) ;
V_110 = 5000000 ;
while ( ! F_67 ( V_9 ) && -- V_110 )
F_83 ( 1 ) ;
for ( V_206 = 0 ; V_206 < V_203 ; V_206 ++ , V_202 ++ ) {
if ( * V_202 == '\n' )
V_70 -> V_177 ( V_9 , '\r' ) ;
V_70 -> V_177 ( V_9 , * V_202 ) ;
V_110 = 20000 ;
while ( ! F_67 ( V_9 ) && -- V_110 )
F_83 ( 1 ) ;
}
V_70 -> V_208 ( V_9 ) ;
}
static int T_4
F_113 ( struct V_200 * V_201 , char * V_209 )
{
struct V_8 * V_9 = & V_204 [ V_201 -> V_205 ] ;
struct V_32 * V_33 = V_210 [ V_201 -> V_205 ] ;
unsigned int V_31 ;
struct V_211 V_212 ;
int V_78 ;
int V_30 = V_198 ;
int V_196 = 8 ;
int V_168 = 'n' ;
int V_197 = 'n' ;
F_111 ( L_16 ,
V_201 , V_201 -> V_205 , V_209 ) ;
if ( ( V_201 -> V_205 < 0 ) || ( V_201 -> V_205 >= V_213 ) ) {
F_111 ( L_17 , V_201 -> V_205 ) ;
return - V_141 ;
}
if ( ! V_33 ) {
F_111 ( L_18 , V_201 -> V_205 ) ;
return - V_141 ;
}
F_111 ( L_19 ,
V_201 -> V_205 , V_210 [ V_201 -> V_205 ] -> V_214 ) ;
V_78 = F_114 ( V_33 , 0 , & V_212 ) ;
if ( V_78 ) {
F_111 ( L_20 , V_201 -> V_205 ) ;
return V_78 ;
}
V_31 = F_115 ( V_33 ) ;
if ( V_31 == 0 ) {
F_111 ( L_21 ) ;
return - V_141 ;
}
F_116 ( & V_9 -> V_90 ) ;
V_9 -> V_31 = V_31 ;
V_9 -> V_215 = & V_216 ;
V_9 -> V_62 = V_212 . V_217 ;
V_9 -> V_139 = F_91 ( V_212 . V_217 , sizeof( struct V_1 ) ) ;
V_9 -> V_35 = F_27 ( V_33 , 0 ) ;
if ( V_9 -> V_139 == NULL )
return - V_141 ;
F_111 ( L_22 ,
( void * ) V_9 -> V_62 , V_9 -> V_139 ,
V_9 -> V_35 , V_9 -> V_31 ) ;
if ( V_209 )
F_117 ( V_209 , & V_30 , & V_168 , & V_196 , & V_197 ) ;
else
F_110 ( V_9 , & V_30 , & V_168 , & V_196 , & V_197 ) ;
F_111 ( L_23 ,
V_30 , V_196 , V_168 , V_197 ) ;
return F_118 ( V_9 , V_201 , V_30 , V_168 , V_196 , V_197 ) ;
}
static int T_4
F_119 ( void )
{
F_120 () ;
F_121 ( & V_218 ) ;
return 0 ;
}
static int T_7 F_122 ( struct V_219 * V_220 )
{
int V_221 = - 1 ;
unsigned int V_31 ;
struct V_8 * V_9 = NULL ;
struct V_211 V_212 ;
int V_78 ;
for ( V_221 = 0 ; V_221 < V_213 ; V_221 ++ )
if ( V_210 [ V_221 ] == V_220 -> V_68 . V_222 )
break;
if ( V_221 >= V_213 )
return - V_141 ;
F_111 ( L_24 ,
V_210 [ V_221 ] -> V_214 , V_221 ) ;
V_31 = F_115 ( V_220 -> V_68 . V_222 ) ;
if ( V_31 == 0 ) {
F_63 ( & V_220 -> V_68 , L_21 ) ;
return - V_141 ;
}
V_9 = & V_204 [ V_221 ] ;
F_116 ( & V_9 -> V_90 ) ;
V_9 -> V_31 = V_31 ;
V_9 -> V_223 = 512 ;
V_9 -> V_224 = V_148 ;
V_9 -> V_89 = V_225 |
( F_59 ( V_9 ) ? 0 : V_138 ) ;
V_9 -> line = V_221 ;
V_9 -> V_215 = & V_216 ;
V_9 -> V_68 = & V_220 -> V_68 ;
V_78 = F_114 ( V_220 -> V_68 . V_222 , 0 , & V_212 ) ;
if ( V_78 )
return V_78 ;
V_9 -> V_62 = V_212 . V_217 ;
if ( ! V_9 -> V_62 ) {
F_63 ( & V_220 -> V_68 , L_25 ) ;
return - V_141 ;
}
V_70 -> V_226 ( V_9 , V_220 -> V_68 . V_222 ) ;
if ( V_9 -> V_35 == V_59 ) {
F_63 ( & V_220 -> V_68 , L_26 ) ;
return - V_141 ;
}
F_63 ( & V_220 -> V_68 , L_27 ,
( void * ) V_9 -> V_62 , V_9 -> V_35 , V_9 -> V_31 ) ;
V_78 = F_123 ( & V_227 , V_9 ) ;
if ( V_78 )
return V_78 ;
F_124 ( & V_220 -> V_68 , ( void * ) V_9 ) ;
return 0 ;
}
static int
F_125 ( struct V_219 * V_220 )
{
struct V_8 * V_9 = F_126 ( & V_220 -> V_68 ) ;
F_124 ( & V_220 -> V_68 , NULL ) ;
if ( V_9 )
F_127 ( & V_227 , V_9 ) ;
return 0 ;
}
static int
F_128 ( struct V_219 * V_220 , T_8 V_154 )
{
struct V_8 * V_9 = (struct V_8 * ) F_126 ( & V_220 -> V_68 ) ;
if ( V_9 )
F_129 ( & V_227 , V_9 ) ;
return 0 ;
}
static int
F_130 ( struct V_219 * V_220 )
{
struct V_8 * V_9 = (struct V_8 * ) F_126 ( & V_220 -> V_68 ) ;
if ( V_9 )
F_131 ( & V_227 , V_9 ) ;
return 0 ;
}
static void
F_132 ( struct V_32 * V_33 )
{
int V_206 ;
for ( V_206 = 0 ; V_206 < V_213 ; V_206 ++ ) {
if ( V_210 [ V_206 ] == NULL ) {
F_133 ( V_33 ) ;
V_210 [ V_206 ] = V_33 ;
return;
}
}
}
static void
F_120 ( void )
{
static int V_228 ;
struct V_32 * V_33 ;
const struct V_229 * V_230 ;
int V_206 ;
if ( V_228 )
return;
F_134 (np, mpc52xx_uart_of_match) {
V_230 = F_135 ( V_231 , V_33 ) ;
V_70 = V_230 -> V_232 ;
F_132 ( V_33 ) ;
}
V_228 = 1 ;
for ( V_206 = 0 ; V_206 < V_213 ; V_206 ++ ) {
if ( V_210 [ V_206 ] )
F_111 ( L_28 ,
V_210 [ V_206 ] -> V_214 , V_206 ) ;
}
}
static int T_4
F_136 ( void )
{
int V_78 ;
F_84 ( V_233 L_29 ) ;
V_78 = F_137 ( & V_227 ) ;
if ( V_78 ) {
F_84 ( V_133 L_30 ,
__FILE__ , V_78 ) ;
return V_78 ;
}
F_120 () ;
if ( V_70 && V_70 -> V_234 ) {
V_78 = V_70 -> V_234 () ;
if ( V_78 )
return V_78 ;
}
V_78 = F_138 ( & V_235 ) ;
if ( V_78 ) {
F_84 ( V_133 L_31 ,
__FILE__ , V_78 ) ;
F_139 ( & V_227 ) ;
return V_78 ;
}
return 0 ;
}
static void T_5
F_140 ( void )
{
if ( V_70 -> V_236 )
V_70 -> V_236 () ;
F_141 ( & V_235 ) ;
F_139 ( & V_227 ) ;
}
