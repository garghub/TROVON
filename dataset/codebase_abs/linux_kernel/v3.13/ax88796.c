static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
struct V_4 * V_5 = F_2 ( V_3 ) ;
return (struct V_1 * ) ( V_5 + 1 ) ;
}
static int F_3 ( struct V_2 * V_3 )
{
struct V_4 * V_5 = F_2 ( V_3 ) ;
void T_1 * V_6 = V_5 -> V_7 ;
int V_8 ;
int V_9 ;
V_8 = F_4 ( V_6 ) ;
if ( V_8 == 0xFF )
return - V_10 ;
F_5 ( V_11 + V_12 + V_13 , V_6 + V_14 ) ;
V_9 = F_4 ( V_6 + 0x0d ) ;
F_5 ( 0xff , V_6 + 0x0d ) ;
F_5 ( V_11 + V_15 , V_6 + V_14 ) ;
F_4 ( V_6 + V_16 ) ;
if ( F_4 ( V_6 + V_16 ) != 0 ) {
F_5 ( V_8 , V_6 ) ;
F_5 ( V_9 , V_6 + 0x0d ) ;
return - V_10 ;
}
return 0 ;
}
static void F_6 ( struct V_2 * V_3 )
{
struct V_4 * V_5 = F_2 ( V_3 ) ;
unsigned long V_17 = V_18 ;
void T_1 * V_19 = ( void T_1 * ) V_3 -> V_20 ;
if ( V_21 > 1 )
F_7 ( V_3 , L_1 , V_18 ) ;
F_5 ( F_4 ( V_19 + V_22 ) , V_19 + V_22 ) ;
V_5 -> V_23 = 0 ;
V_5 -> V_24 = 0 ;
while ( ( F_4 ( V_19 + V_25 ) & V_26 ) == 0 ) {
if ( V_18 - V_17 > 2 * V_27 / 100 ) {
F_8 ( V_3 , L_2 , V_28 ) ;
break;
}
}
F_5 ( V_26 , V_19 + V_25 ) ;
}
static void F_9 ( struct V_2 * V_3 , struct V_29 * V_30 ,
int V_31 )
{
struct V_4 * V_5 = F_2 ( V_3 ) ;
void T_1 * V_32 = V_5 -> V_7 ;
if ( V_5 -> V_24 ) {
F_10 ( V_3 , L_3
L_4 ,
V_28 ,
V_5 -> V_24 , V_5 -> V_33 ) ;
return;
}
V_5 -> V_24 |= 0x01 ;
F_5 ( V_11 + V_15 + V_34 , V_32 + V_35 ) ;
F_5 ( sizeof( struct V_29 ) , V_32 + V_36 ) ;
F_5 ( 0 , V_32 + V_37 ) ;
F_5 ( 0 , V_32 + V_38 ) ;
F_5 ( V_31 , V_32 + V_39 ) ;
F_5 ( V_40 + V_34 , V_32 + V_35 ) ;
if ( V_5 -> V_41 )
F_11 ( V_32 + V_42 , V_30 ,
sizeof( struct V_29 ) >> 1 ) ;
else
F_12 ( V_32 + V_42 , V_30 ,
sizeof( struct V_29 ) ) ;
F_5 ( V_43 , V_32 + V_25 ) ;
V_5 -> V_24 &= ~ 0x01 ;
F_13 ( & V_30 -> V_44 ) ;
}
static void F_14 ( struct V_2 * V_3 , int V_44 ,
struct V_45 * V_46 , int V_47 )
{
struct V_4 * V_5 = F_2 ( V_3 ) ;
void T_1 * V_32 = V_5 -> V_7 ;
char * V_48 = V_46 -> V_49 ;
if ( V_5 -> V_24 ) {
F_10 ( V_3 ,
L_3
L_4 ,
V_28 ,
V_5 -> V_24 , V_5 -> V_33 ) ;
return;
}
V_5 -> V_24 |= 0x01 ;
F_5 ( V_11 + V_15 + V_34 , V_32 + V_35 ) ;
F_5 ( V_44 & 0xff , V_32 + V_36 ) ;
F_5 ( V_44 >> 8 , V_32 + V_37 ) ;
F_5 ( V_47 & 0xff , V_32 + V_38 ) ;
F_5 ( V_47 >> 8 , V_32 + V_39 ) ;
F_5 ( V_40 + V_34 , V_32 + V_35 ) ;
if ( V_5 -> V_41 ) {
F_11 ( V_32 + V_42 , V_48 , V_44 >> 1 ) ;
if ( V_44 & 0x01 )
V_48 [ V_44 - 1 ] = F_4 ( V_32 + V_42 ) ;
} else {
F_12 ( V_32 + V_42 , V_48 , V_44 ) ;
}
V_5 -> V_24 &= ~ 1 ;
}
static void F_15 ( struct V_2 * V_3 , int V_44 ,
const unsigned char * V_48 , const int V_50 )
{
struct V_4 * V_5 = F_2 ( V_3 ) ;
void T_1 * V_32 = V_5 -> V_7 ;
unsigned long V_51 ;
if ( V_5 -> V_41 && ( V_44 & 0x01 ) )
V_44 ++ ;
if ( V_5 -> V_24 ) {
F_10 ( V_3 , L_5
L_6 ,
V_28 ,
V_5 -> V_24 , V_5 -> V_33 ) ;
return;
}
V_5 -> V_24 |= 0x01 ;
F_5 ( V_15 + V_34 + V_11 , V_32 + V_35 ) ;
F_5 ( V_43 , V_32 + V_25 ) ;
F_5 ( V_44 & 0xff , V_32 + V_36 ) ;
F_5 ( V_44 >> 8 , V_32 + V_37 ) ;
F_5 ( 0x00 , V_32 + V_38 ) ;
F_5 ( V_50 , V_32 + V_39 ) ;
F_5 ( V_52 + V_34 , V_32 + V_35 ) ;
if ( V_5 -> V_41 )
F_16 ( V_32 + V_42 , V_48 , V_44 >> 1 ) ;
else
F_17 ( V_32 + V_42 , V_48 , V_44 ) ;
V_51 = V_18 ;
while ( ( F_4 ( V_32 + V_25 ) & V_43 ) == 0 ) {
if ( V_18 - V_51 > 2 * V_27 / 100 ) {
F_8 ( V_3 , L_7 ) ;
F_6 ( V_3 ) ;
F_18 ( V_3 , 1 ) ;
break;
}
}
F_5 ( V_43 , V_32 + V_25 ) ;
V_5 -> V_24 &= ~ 0x01 ;
}
static void F_19 ( struct V_2 * V_3 )
{
struct V_1 * V_53 = F_1 ( V_3 ) ;
struct V_54 * V_55 = V_53 -> V_55 ;
int V_56 = 0 ;
if ( V_55 -> V_57 && ( ( V_53 -> V_58 != V_55 -> V_58 ) ||
( V_53 -> V_59 != V_55 -> V_59 ) ) ) {
V_53 -> V_58 = V_55 -> V_58 ;
V_53 -> V_59 = V_55 -> V_59 ;
V_56 = 1 ;
}
if ( V_55 -> V_57 != V_53 -> V_57 ) {
if ( ! V_55 -> V_57 ) {
V_53 -> V_58 = 0 ;
V_53 -> V_59 = - 1 ;
}
V_53 -> V_57 = V_55 -> V_57 ;
V_56 = 1 ;
}
if ( V_56 )
F_20 ( V_55 ) ;
}
static int F_21 ( struct V_2 * V_3 )
{
struct V_1 * V_53 = F_1 ( V_3 ) ;
struct V_54 * V_55 = NULL ;
int V_60 ;
V_55 = F_22 ( V_53 -> V_61 ) ;
if ( ! V_55 ) {
F_10 ( V_3 , L_8 ) ;
return - V_10 ;
}
V_60 = F_23 ( V_3 , V_55 , F_19 ,
V_62 ) ;
if ( V_60 ) {
F_10 ( V_3 , L_9 ) ;
return V_60 ;
}
V_55 -> V_63 &= V_64 ;
V_55 -> V_65 = V_55 -> V_63 ;
V_53 -> V_55 = V_55 ;
F_24 ( V_3 , L_10 ,
V_55 -> V_66 -> V_67 , F_25 ( & V_55 -> V_3 ) , V_55 -> V_68 ) ;
return 0 ;
}
static void F_26 ( struct V_2 * V_3 , int V_69 )
{
struct V_4 * V_5 = F_2 ( V_3 ) ;
struct V_1 * V_53 = F_1 ( V_3 ) ;
T_2 V_70 = V_53 -> V_71 -> V_72 ;
if ( ! ! V_69 )
V_70 &= ~ V_73 ;
else
V_70 |= V_73 ;
F_5 ( V_70 , V_5 -> V_7 + F_27 ( 0x17 ) ) ;
}
static int F_28 ( struct V_2 * V_3 )
{
struct V_1 * V_53 = F_1 ( V_3 ) ;
int V_60 ;
F_7 ( V_3 , L_11 ) ;
V_60 = F_29 ( V_3 -> V_68 , V_74 , V_53 -> V_75 ,
V_3 -> V_67 , V_3 ) ;
if ( V_60 )
goto V_76;
F_26 ( V_3 , 1 ) ;
V_60 = F_21 ( V_3 ) ;
if ( V_60 )
goto V_77;
F_30 ( V_53 -> V_55 ) ;
V_60 = F_31 ( V_3 ) ;
if ( V_60 )
goto V_78;
V_53 -> V_79 = 1 ;
return 0 ;
V_78:
F_32 ( V_53 -> V_55 ) ;
V_77:
F_26 ( V_3 , 0 ) ;
F_33 ( V_3 -> V_68 , V_3 ) ;
V_76:
return V_60 ;
}
static int F_34 ( struct V_2 * V_3 )
{
struct V_1 * V_53 = F_1 ( V_3 ) ;
F_7 ( V_3 , L_12 ) ;
V_53 -> V_79 = 0 ;
F_35 () ;
F_36 ( V_3 ) ;
F_26 ( V_3 , 0 ) ;
F_32 ( V_53 -> V_55 ) ;
F_33 ( V_3 -> V_68 , V_3 ) ;
return 0 ;
}
static int F_37 ( struct V_2 * V_3 , struct V_80 * V_81 , int V_82 )
{
struct V_1 * V_53 = F_1 ( V_3 ) ;
struct V_54 * V_55 = V_53 -> V_55 ;
if ( ! F_38 ( V_3 ) )
return - V_83 ;
if ( ! V_55 )
return - V_10 ;
return F_39 ( V_55 , V_81 , V_82 ) ;
}
static void F_40 ( struct V_2 * V_3 ,
struct V_84 * V_85 )
{
struct V_86 * V_87 = F_41 ( V_3 -> V_3 . V_88 ) ;
F_42 ( V_85 -> V_89 , V_90 , sizeof( V_85 -> V_89 ) ) ;
F_42 ( V_85 -> V_91 , V_92 , sizeof( V_85 -> V_91 ) ) ;
F_42 ( V_85 -> V_93 , V_87 -> V_67 , sizeof( V_85 -> V_93 ) ) ;
}
static int F_43 ( struct V_2 * V_3 , struct V_94 * V_82 )
{
struct V_1 * V_53 = F_1 ( V_3 ) ;
struct V_54 * V_55 = V_53 -> V_55 ;
if ( ! V_55 )
return - V_10 ;
return F_44 ( V_55 , V_82 ) ;
}
static int F_45 ( struct V_2 * V_3 , struct V_94 * V_82 )
{
struct V_1 * V_53 = F_1 ( V_3 ) ;
struct V_54 * V_55 = V_53 -> V_55 ;
if ( ! V_55 )
return - V_10 ;
return F_46 ( V_55 , V_82 ) ;
}
static void F_47 ( struct V_95 * V_96 )
{
struct V_4 * V_5 = V_96 -> V_49 ;
T_2 V_97 = F_4 ( V_5 -> V_7 + V_98 ) ;
V_96 -> V_99 = V_97 & V_100 ;
V_96 -> V_101 = V_97 & V_102 ;
V_96 -> V_103 = V_97 & V_104 ;
V_96 -> V_105 = V_97 & V_106 ;
}
static void F_48 ( struct V_95 * V_96 )
{
struct V_4 * V_5 = V_96 -> V_49 ;
T_2 V_97 = F_4 ( V_5 -> V_7 + V_98 ) ;
V_97 &= ~ ( V_100 | V_104 | V_106 ) ;
if ( V_96 -> V_99 )
V_97 |= V_100 ;
if ( V_96 -> V_103 )
V_97 |= V_104 ;
if ( V_96 -> V_105 )
V_97 |= V_106 ;
F_5 ( V_97 , V_5 -> V_7 + V_98 ) ;
F_49 ( 10 ) ;
}
static void F_50 ( struct V_107 * V_108 , int V_109 )
{
struct V_1 * V_53 = F_51 ( V_108 , struct V_1 , V_110 ) ;
if ( V_109 )
V_53 -> V_111 |= V_112 ;
else
V_53 -> V_111 &= ~ V_112 ;
F_5 ( V_53 -> V_111 , V_53 -> V_113 ) ;
}
static void F_52 ( struct V_107 * V_108 , int V_114 )
{
struct V_1 * V_53 = F_51 ( V_108 , struct V_1 , V_110 ) ;
if ( V_114 )
V_53 -> V_111 &= ~ V_115 ;
else
V_53 -> V_111 |= V_115 ;
F_5 ( V_53 -> V_111 , V_53 -> V_113 ) ;
}
static void F_53 ( struct V_107 * V_108 , int V_116 )
{
struct V_1 * V_53 = F_51 ( V_108 , struct V_1 , V_110 ) ;
if ( V_116 )
V_53 -> V_111 |= V_117 ;
else
V_53 -> V_111 &= ~ V_117 ;
F_5 ( V_53 -> V_111 , V_53 -> V_113 ) ;
}
static int F_54 ( struct V_107 * V_108 )
{
struct V_1 * V_53 = F_51 ( V_108 , struct V_1 , V_110 ) ;
int V_111 = F_4 ( V_53 -> V_113 ) ;
return V_111 & V_118 ? 1 : 0 ;
}
static int F_55 ( struct V_2 * V_3 )
{
struct V_86 * V_87 = F_41 ( V_3 -> V_3 . V_88 ) ;
struct V_4 * V_5 = F_2 ( V_3 ) ;
struct V_1 * V_53 = F_1 ( V_3 ) ;
int V_119 , V_120 ;
V_53 -> V_110 . V_121 = & V_122 ;
V_53 -> V_113 = V_5 -> V_7 + V_98 ;
V_53 -> V_61 = F_56 ( & V_53 -> V_110 ) ;
if ( ! V_53 -> V_61 ) {
V_119 = - V_123 ;
goto V_124;
}
V_53 -> V_61 -> V_67 = L_13 ;
V_53 -> V_61 -> V_88 = V_3 -> V_3 . V_88 ;
snprintf ( V_53 -> V_61 -> V_125 , V_126 , L_14 ,
V_87 -> V_67 , V_87 -> V_125 ) ;
V_53 -> V_61 -> V_68 = F_57 ( sizeof( int ) * V_127 , V_128 ) ;
if ( ! V_53 -> V_61 -> V_68 ) {
V_119 = - V_123 ;
goto V_129;
}
for ( V_120 = 0 ; V_120 < V_127 ; V_120 ++ )
V_53 -> V_61 -> V_68 [ V_120 ] = V_130 ;
V_119 = F_58 ( V_53 -> V_61 ) ;
if ( V_119 )
goto V_131;
return 0 ;
V_131:
F_59 ( V_53 -> V_61 -> V_68 ) ;
V_129:
F_60 ( V_53 -> V_61 ) ;
V_124:
return V_119 ;
}
static void F_61 ( struct V_2 * V_3 , struct V_4 * V_5 )
{
void T_1 * V_6 = V_5 -> V_7 ;
struct V_1 * V_53 = F_1 ( V_3 ) ;
F_5 ( V_11 + V_15 + V_13 , V_6 + V_14 ) ;
F_5 ( V_53 -> V_71 -> V_132 & ~ 1 , V_6 + V_133 ) ;
F_5 ( V_53 -> V_71 -> V_72 , V_6 + F_27 ( 0x17 ) ) ;
}
static int F_62 ( struct V_2 * V_3 )
{
struct V_4 * V_5 = F_2 ( V_3 ) ;
struct V_1 * V_53 = F_1 ( V_3 ) ;
void T_1 * V_6 = V_5 -> V_7 ;
unsigned int V_50 ;
unsigned int V_134 ;
int V_60 ;
int V_120 ;
V_60 = F_3 ( V_3 ) ;
if ( V_60 )
goto V_135;
F_61 ( V_3 , V_5 ) ;
if ( V_53 -> V_71 -> V_136 & V_137 ) {
unsigned char V_138 [ 32 ] ;
for ( V_120 = 0 ; V_120 < sizeof( V_138 ) ; V_120 += 2 ) {
V_138 [ V_120 ] = F_4 ( V_6 + V_42 ) ;
V_138 [ V_120 + 1 ] = F_4 ( V_6 + V_42 ) ;
}
if ( V_53 -> V_71 -> V_139 == 2 )
for ( V_120 = 0 ; V_120 < 16 ; V_120 ++ )
V_138 [ V_120 ] = V_138 [ V_120 + V_120 ] ;
memcpy ( V_3 -> V_140 , V_138 , V_141 ) ;
}
#ifdef F_63
if ( V_53 -> V_71 -> V_136 & V_142 ) {
unsigned char V_143 [ V_141 ] ;
struct V_95 V_96 ;
V_96 . V_49 = V_5 ;
V_96 . V_144 = F_47 ;
V_96 . V_145 = F_48 ;
V_96 . V_146 = V_147 ;
F_64 ( & V_96 , 0 ,
( V_148 V_149 * ) V_143 ,
sizeof( V_143 ) >> 1 ) ;
memcpy ( V_3 -> V_140 , V_143 , V_141 ) ;
}
#endif
if ( V_53 -> V_71 -> V_139 == 2 ) {
F_5 ( V_53 -> V_71 -> V_132 , V_5 -> V_7 + V_133 ) ;
V_50 = V_150 ;
V_134 = V_151 ;
} else {
V_50 = V_152 ;
V_134 = V_153 ;
}
if ( V_53 -> V_71 -> V_136 & V_154 ) {
F_5 ( V_11 + V_12 + V_13 ,
V_5 -> V_7 + V_14 ) ;
for ( V_120 = 0 ; V_120 < V_141 ; V_120 ++ )
V_3 -> V_140 [ V_120 ] =
F_4 ( V_6 + F_65 ( V_120 ) ) ;
}
if ( ( V_53 -> V_71 -> V_136 & V_155 ) &&
V_53 -> V_71 -> V_143 )
memcpy ( V_3 -> V_140 , V_53 -> V_71 -> V_143 , V_141 ) ;
F_6 ( V_3 ) ;
V_5 -> V_67 = L_15 ;
V_5 -> V_156 = V_50 ;
V_5 -> V_134 = V_134 ;
V_5 -> V_41 = ( V_53 -> V_71 -> V_139 == 2 ) ;
V_5 -> V_157 = V_50 + V_158 ;
#ifdef F_66
V_5 -> V_134 = V_5 -> V_156 + F_66 ;
#endif
V_5 -> V_159 = & F_6 ;
V_5 -> V_160 = & F_14 ;
V_5 -> V_161 = & F_15 ;
V_5 -> V_162 = & F_9 ;
V_5 -> V_163 = 0 ;
V_3 -> V_164 = & V_165 ;
V_3 -> V_166 = & V_167 ;
V_60 = F_55 ( V_3 ) ;
if ( V_60 )
goto V_168;
F_18 ( V_3 , 0 ) ;
V_60 = F_67 ( V_3 ) ;
if ( V_60 )
goto V_168;
F_24 ( V_3 , L_16 ,
V_5 -> V_41 ? 16 : 8 , V_3 -> V_68 , V_3 -> V_20 ,
V_3 -> V_140 ) ;
return 0 ;
V_168:
F_33 ( V_3 -> V_68 , V_3 ) ;
V_135:
return V_60 ;
}
static int F_68 ( struct V_86 * V_87 )
{
struct V_2 * V_3 = F_69 ( V_87 ) ;
struct V_4 * V_5 = F_2 ( V_3 ) ;
struct V_1 * V_53 = F_1 ( V_3 ) ;
struct V_169 * V_7 ;
F_70 ( V_3 ) ;
F_33 ( V_3 -> V_68 , V_3 ) ;
F_71 ( V_5 -> V_7 ) ;
V_7 = F_72 ( V_87 , V_170 , 0 ) ;
F_73 ( V_7 -> V_171 , F_74 ( V_7 ) ) ;
if ( V_53 -> V_172 ) {
F_71 ( V_53 -> V_172 ) ;
V_7 = F_72 ( V_87 , V_170 , 1 ) ;
F_73 ( V_7 -> V_171 , F_74 ( V_7 ) ) ;
}
F_75 ( V_3 ) ;
return 0 ;
}
static int F_76 ( struct V_86 * V_87 )
{
struct V_2 * V_3 ;
struct V_4 * V_5 ;
struct V_1 * V_53 ;
struct V_169 * V_68 , * V_7 , * V_173 ;
unsigned long V_174 , V_175 = 0 ;
int V_60 = 0 ;
V_3 = F_77 ( sizeof( struct V_1 ) ) ;
if ( V_3 == NULL )
return - V_123 ;
F_78 ( V_3 , & V_87 -> V_3 ) ;
V_5 = F_2 ( V_3 ) ;
V_53 = F_1 ( V_3 ) ;
V_53 -> V_71 = F_79 ( & V_87 -> V_3 ) ;
F_80 ( V_87 , V_3 ) ;
V_5 -> V_176 = V_53 -> V_71 -> V_177 ;
V_68 = F_72 ( V_87 , V_178 , 0 ) ;
if ( ! V_68 ) {
F_81 ( & V_87 -> V_3 , L_17 ) ;
V_60 = - V_179 ;
goto V_180;
}
V_3 -> V_68 = V_68 -> V_171 ;
V_53 -> V_75 = V_68 -> V_136 & V_181 ;
V_7 = F_72 ( V_87 , V_170 , 0 ) ;
if ( ! V_7 ) {
F_81 ( & V_87 -> V_3 , L_18 ) ;
V_60 = - V_179 ;
goto V_180;
}
V_174 = F_74 ( V_7 ) ;
if ( V_53 -> V_71 -> V_182 )
V_5 -> V_183 = V_53 -> V_71 -> V_182 ;
else {
V_5 -> V_183 = V_53 -> V_182 ;
for ( V_60 = 0 ; V_60 < 0x18 ; V_60 ++ )
V_53 -> V_182 [ V_60 ] = ( V_174 / 0x18 ) * V_60 ;
}
if ( ! F_82 ( V_7 -> V_171 , V_174 , V_87 -> V_67 ) ) {
F_81 ( & V_87 -> V_3 , L_19 ) ;
V_60 = - V_179 ;
goto V_180;
}
V_5 -> V_7 = F_83 ( V_7 -> V_171 , V_174 ) ;
V_3 -> V_20 = ( unsigned long ) V_5 -> V_7 ;
if ( V_5 -> V_7 == NULL ) {
F_81 ( & V_87 -> V_3 , L_20 , V_7 ) ;
V_60 = - V_179 ;
goto V_184;
}
V_173 = F_72 ( V_87 , V_170 , 1 ) ;
if ( ! V_173 ) {
if ( ! V_53 -> V_71 -> V_182 ) {
for ( V_60 = 0 ; V_60 < 0x20 ; V_60 ++ )
V_53 -> V_182 [ V_60 ] = ( V_174 / 0x20 ) * V_60 ;
}
} else {
V_175 = F_74 ( V_173 ) ;
if ( ! F_82 ( V_173 -> V_171 , V_175 , V_87 -> V_67 ) ) {
F_81 ( & V_87 -> V_3 , L_19 ) ;
V_60 = - V_179 ;
goto V_185;
}
V_53 -> V_172 = F_83 ( V_173 -> V_171 , V_175 ) ;
if ( ! V_53 -> V_172 ) {
F_81 ( & V_87 -> V_3 , L_21 ) ;
V_60 = - V_179 ;
goto V_186;
}
V_5 -> V_183 [ 0x1f ] = V_53 -> V_172 - V_5 -> V_7 ;
}
V_60 = F_62 ( V_3 ) ;
if ( ! V_60 )
return 0 ;
if ( ! V_53 -> V_172 )
goto V_185;
F_71 ( V_53 -> V_172 ) ;
V_186:
F_73 ( V_173 -> V_171 , V_175 ) ;
V_185:
F_71 ( V_5 -> V_7 ) ;
V_184:
F_73 ( V_7 -> V_171 , V_174 ) ;
V_180:
F_75 ( V_3 ) ;
return V_60 ;
}
static int F_84 ( struct V_86 * V_3 , T_3 V_187 )
{
struct V_2 * V_188 = F_69 ( V_3 ) ;
struct V_1 * V_53 = F_1 ( V_188 ) ;
V_53 -> V_189 = V_53 -> V_79 ;
F_85 ( V_188 ) ;
F_34 ( V_188 ) ;
return 0 ;
}
static int F_86 ( struct V_86 * V_87 )
{
struct V_2 * V_188 = F_69 ( V_87 ) ;
struct V_1 * V_53 = F_1 ( V_188 ) ;
F_61 ( V_188 , F_2 ( V_188 ) ) ;
F_18 ( V_188 , V_53 -> V_189 ) ;
F_87 ( V_188 ) ;
if ( V_53 -> V_189 )
F_28 ( V_188 ) ;
return 0 ;
}
