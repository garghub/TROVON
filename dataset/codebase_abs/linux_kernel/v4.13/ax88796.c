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
F_7 ( V_5 , V_21 , V_3 , L_1 , V_18 ) ;
F_5 ( F_4 ( V_19 + V_22 ) , V_19 + V_22 ) ;
V_5 -> V_23 = 0 ;
V_5 -> V_24 = 0 ;
while ( ( F_4 ( V_19 + V_25 ) & V_26 ) == 0 ) {
if ( F_8 ( V_18 , V_17 + 2 * V_27 / 100 ) ) {
F_9 ( V_3 , L_2 , V_28 ) ;
break;
}
}
F_5 ( V_26 , V_19 + V_25 ) ;
}
static void F_10 ( struct V_2 * V_3 , struct V_29 * V_30 ,
int V_31 )
{
struct V_4 * V_5 = F_2 ( V_3 ) ;
void T_1 * V_32 = V_5 -> V_7 ;
if ( V_5 -> V_24 ) {
F_11 ( V_3 , L_3
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
F_12 ( V_32 + V_42 , V_30 ,
sizeof( struct V_29 ) >> 1 ) ;
else
F_13 ( V_32 + V_42 , V_30 ,
sizeof( struct V_29 ) ) ;
F_5 ( V_43 , V_32 + V_25 ) ;
V_5 -> V_24 &= ~ 0x01 ;
F_14 ( & V_30 -> V_44 ) ;
}
static void F_15 ( struct V_2 * V_3 , int V_44 ,
struct V_45 * V_46 , int V_47 )
{
struct V_4 * V_5 = F_2 ( V_3 ) ;
void T_1 * V_32 = V_5 -> V_7 ;
char * V_48 = V_46 -> V_49 ;
if ( V_5 -> V_24 ) {
F_11 ( V_3 ,
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
F_12 ( V_32 + V_42 , V_48 , V_44 >> 1 ) ;
if ( V_44 & 0x01 )
V_48 [ V_44 - 1 ] = F_4 ( V_32 + V_42 ) ;
} else {
F_13 ( V_32 + V_42 , V_48 , V_44 ) ;
}
V_5 -> V_24 &= ~ 1 ;
}
static void F_16 ( struct V_2 * V_3 , int V_44 ,
const unsigned char * V_48 , const int V_50 )
{
struct V_4 * V_5 = F_2 ( V_3 ) ;
void T_1 * V_32 = V_5 -> V_7 ;
unsigned long V_51 ;
if ( V_5 -> V_41 && ( V_44 & 0x01 ) )
V_44 ++ ;
if ( V_5 -> V_24 ) {
F_11 ( V_3 , L_5
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
F_17 ( V_32 + V_42 , V_48 , V_44 >> 1 ) ;
else
F_18 ( V_32 + V_42 , V_48 , V_44 ) ;
V_51 = V_18 ;
while ( ( F_4 ( V_32 + V_25 ) & V_43 ) == 0 ) {
if ( F_8 ( V_18 , V_51 + 2 * V_27 / 100 ) ) {
F_9 ( V_3 , L_7 ) ;
F_6 ( V_3 ) ;
F_19 ( V_3 , 1 ) ;
break;
}
}
F_5 ( V_43 , V_32 + V_25 ) ;
V_5 -> V_24 &= ~ 0x01 ;
}
static void F_20 ( struct V_2 * V_3 )
{
struct V_1 * V_53 = F_1 ( V_3 ) ;
struct V_54 * V_55 = V_3 -> V_56 ;
int V_57 = 0 ;
if ( V_55 -> V_58 && ( ( V_53 -> V_59 != V_55 -> V_59 ) ||
( V_53 -> V_60 != V_55 -> V_60 ) ) ) {
V_53 -> V_59 = V_55 -> V_59 ;
V_53 -> V_60 = V_55 -> V_60 ;
V_57 = 1 ;
}
if ( V_55 -> V_58 != V_53 -> V_58 ) {
if ( ! V_55 -> V_58 ) {
V_53 -> V_59 = 0 ;
V_53 -> V_60 = - 1 ;
}
V_53 -> V_58 = V_55 -> V_58 ;
V_57 = 1 ;
}
if ( V_57 )
F_21 ( V_55 ) ;
}
static int F_22 ( struct V_2 * V_3 )
{
struct V_1 * V_53 = F_1 ( V_3 ) ;
struct V_54 * V_55 = NULL ;
int V_61 ;
V_55 = F_23 ( V_53 -> V_62 ) ;
if ( ! V_55 ) {
F_11 ( V_3 , L_8 ) ;
return - V_10 ;
}
V_61 = F_24 ( V_3 , V_55 , F_20 ,
V_63 ) ;
if ( V_61 ) {
F_11 ( V_3 , L_9 ) ;
return V_61 ;
}
V_55 -> V_64 &= V_65 ;
V_55 -> V_66 = V_55 -> V_64 ;
F_25 ( V_3 , L_10 ,
V_55 -> V_67 -> V_68 , F_26 ( V_55 ) , V_55 -> V_69 ) ;
return 0 ;
}
static void F_27 ( struct V_2 * V_3 , int V_70 )
{
struct V_4 * V_5 = F_2 ( V_3 ) ;
struct V_1 * V_53 = F_1 ( V_3 ) ;
T_2 V_71 = V_53 -> V_72 -> V_73 ;
if ( ! ! V_70 )
V_71 &= ~ V_74 ;
else
V_71 |= V_74 ;
F_5 ( V_71 , V_5 -> V_7 + F_28 ( 0x17 ) ) ;
}
static int F_29 ( struct V_2 * V_3 )
{
struct V_1 * V_53 = F_1 ( V_3 ) ;
int V_61 ;
F_30 ( V_3 , L_11 ) ;
V_61 = F_31 ( V_3 -> V_69 , V_75 , V_53 -> V_76 ,
V_3 -> V_68 , V_3 ) ;
if ( V_61 )
goto V_77;
F_27 ( V_3 , 1 ) ;
V_61 = F_22 ( V_3 ) ;
if ( V_61 )
goto V_78;
F_32 ( V_3 -> V_56 ) ;
V_61 = F_33 ( V_3 ) ;
if ( V_61 )
goto V_79;
V_53 -> V_80 = 1 ;
return 0 ;
V_79:
F_34 ( V_3 -> V_56 ) ;
V_78:
F_27 ( V_3 , 0 ) ;
F_35 ( V_3 -> V_69 , V_3 ) ;
V_77:
return V_61 ;
}
static int F_36 ( struct V_2 * V_3 )
{
struct V_1 * V_53 = F_1 ( V_3 ) ;
F_30 ( V_3 , L_12 ) ;
V_53 -> V_80 = 0 ;
F_37 () ;
F_38 ( V_3 ) ;
F_27 ( V_3 , 0 ) ;
F_34 ( V_3 -> V_56 ) ;
F_35 ( V_3 -> V_69 , V_3 ) ;
return 0 ;
}
static int F_39 ( struct V_2 * V_3 , struct V_81 * V_82 , int V_83 )
{
struct V_54 * V_55 = V_3 -> V_56 ;
if ( ! F_40 ( V_3 ) )
return - V_84 ;
if ( ! V_55 )
return - V_10 ;
return F_41 ( V_55 , V_82 , V_83 ) ;
}
static void F_42 ( struct V_2 * V_3 ,
struct V_85 * V_86 )
{
struct V_87 * V_88 = F_43 ( V_3 -> V_3 . V_89 ) ;
F_44 ( V_86 -> V_90 , V_91 , sizeof( V_86 -> V_90 ) ) ;
F_44 ( V_86 -> V_92 , V_93 , sizeof( V_86 -> V_92 ) ) ;
F_44 ( V_86 -> V_94 , V_88 -> V_68 , sizeof( V_86 -> V_94 ) ) ;
}
static T_3 F_45 ( struct V_2 * V_3 )
{
struct V_4 * V_5 = F_2 ( V_3 ) ;
return V_5 -> V_95 ;
}
static void F_46 ( struct V_2 * V_3 , T_3 V_96 )
{
struct V_4 * V_5 = F_2 ( V_3 ) ;
V_5 -> V_95 = V_96 ;
}
static void F_47 ( struct V_97 * V_98 )
{
struct V_4 * V_5 = V_98 -> V_49 ;
T_2 V_99 = F_4 ( V_5 -> V_7 + V_100 ) ;
V_98 -> V_101 = V_99 & V_102 ;
V_98 -> V_103 = V_99 & V_104 ;
V_98 -> V_105 = V_99 & V_106 ;
V_98 -> V_107 = V_99 & V_108 ;
}
static void F_48 ( struct V_97 * V_98 )
{
struct V_4 * V_5 = V_98 -> V_49 ;
T_2 V_99 = F_4 ( V_5 -> V_7 + V_100 ) ;
V_99 &= ~ ( V_102 | V_106 | V_108 ) ;
if ( V_98 -> V_101 )
V_99 |= V_102 ;
if ( V_98 -> V_105 )
V_99 |= V_106 ;
if ( V_98 -> V_107 )
V_99 |= V_108 ;
F_5 ( V_99 , V_5 -> V_7 + V_100 ) ;
F_49 ( 10 ) ;
}
static void F_50 ( struct V_109 * V_110 , int V_111 )
{
struct V_1 * V_53 = F_51 ( V_110 , struct V_1 , V_112 ) ;
if ( V_111 )
V_53 -> V_113 |= V_114 ;
else
V_53 -> V_113 &= ~ V_114 ;
F_5 ( V_53 -> V_113 , V_53 -> V_115 ) ;
}
static void F_52 ( struct V_109 * V_110 , int V_116 )
{
struct V_1 * V_53 = F_51 ( V_110 , struct V_1 , V_112 ) ;
if ( V_116 )
V_53 -> V_113 &= ~ V_117 ;
else
V_53 -> V_113 |= V_117 ;
F_5 ( V_53 -> V_113 , V_53 -> V_115 ) ;
}
static void F_53 ( struct V_109 * V_110 , int V_118 )
{
struct V_1 * V_53 = F_51 ( V_110 , struct V_1 , V_112 ) ;
if ( V_118 )
V_53 -> V_113 |= V_119 ;
else
V_53 -> V_113 &= ~ V_119 ;
F_5 ( V_53 -> V_113 , V_53 -> V_115 ) ;
}
static int F_54 ( struct V_109 * V_110 )
{
struct V_1 * V_53 = F_51 ( V_110 , struct V_1 , V_112 ) ;
int V_113 = F_4 ( V_53 -> V_115 ) ;
return V_113 & V_120 ? 1 : 0 ;
}
static int F_55 ( struct V_2 * V_3 )
{
struct V_87 * V_88 = F_43 ( V_3 -> V_3 . V_89 ) ;
struct V_4 * V_5 = F_2 ( V_3 ) ;
struct V_1 * V_53 = F_1 ( V_3 ) ;
int V_121 ;
V_53 -> V_112 . V_122 = & V_123 ;
V_53 -> V_115 = V_5 -> V_7 + V_100 ;
V_53 -> V_62 = F_56 ( & V_53 -> V_112 ) ;
if ( ! V_53 -> V_62 ) {
V_121 = - V_124 ;
goto V_125;
}
V_53 -> V_62 -> V_68 = L_13 ;
V_53 -> V_62 -> V_89 = V_3 -> V_3 . V_89 ;
snprintf ( V_53 -> V_62 -> V_126 , V_127 , L_14 ,
V_88 -> V_68 , V_88 -> V_126 ) ;
V_121 = F_57 ( V_53 -> V_62 ) ;
if ( V_121 )
goto V_128;
return 0 ;
V_128:
F_58 ( V_53 -> V_62 ) ;
V_125:
return V_121 ;
}
static void F_59 ( struct V_2 * V_3 , struct V_4 * V_5 )
{
void T_1 * V_6 = V_5 -> V_7 ;
struct V_1 * V_53 = F_1 ( V_3 ) ;
F_5 ( V_11 + V_15 + V_13 , V_6 + V_14 ) ;
F_5 ( V_53 -> V_72 -> V_129 & ~ 1 , V_6 + V_130 ) ;
F_5 ( V_53 -> V_72 -> V_73 , V_6 + F_28 ( 0x17 ) ) ;
}
static int F_60 ( struct V_2 * V_3 )
{
struct V_4 * V_5 = F_2 ( V_3 ) ;
struct V_1 * V_53 = F_1 ( V_3 ) ;
void T_1 * V_6 = V_5 -> V_7 ;
unsigned int V_50 ;
unsigned int V_131 ;
int V_61 ;
int V_132 ;
V_61 = F_3 ( V_3 ) ;
if ( V_61 )
goto V_133;
F_59 ( V_3 , V_5 ) ;
if ( V_53 -> V_72 -> V_134 & V_135 ) {
unsigned char V_136 [ 32 ] ;
for ( V_132 = 0 ; V_132 < sizeof( V_136 ) ; V_132 += 2 ) {
V_136 [ V_132 ] = F_4 ( V_6 + V_42 ) ;
V_136 [ V_132 + 1 ] = F_4 ( V_6 + V_42 ) ;
}
if ( V_53 -> V_72 -> V_137 == 2 )
for ( V_132 = 0 ; V_132 < 16 ; V_132 ++ )
V_136 [ V_132 ] = V_136 [ V_132 + V_132 ] ;
memcpy ( V_3 -> V_138 , V_136 , V_139 ) ;
}
#ifdef F_61
if ( V_53 -> V_72 -> V_134 & V_140 ) {
unsigned char V_141 [ V_139 ] ;
struct V_97 V_98 ;
V_98 . V_49 = V_5 ;
V_98 . V_142 = F_47 ;
V_98 . V_143 = F_48 ;
V_98 . V_144 = V_145 ;
F_62 ( & V_98 , 0 ,
( V_146 V_147 * ) V_141 ,
sizeof( V_141 ) >> 1 ) ;
memcpy ( V_3 -> V_138 , V_141 , V_139 ) ;
}
#endif
if ( V_53 -> V_72 -> V_137 == 2 ) {
F_5 ( V_53 -> V_72 -> V_129 , V_5 -> V_7 + V_130 ) ;
V_50 = V_148 ;
V_131 = V_149 ;
} else {
V_50 = V_150 ;
V_131 = V_151 ;
}
if ( V_53 -> V_72 -> V_134 & V_152 ) {
F_5 ( V_11 + V_12 + V_13 ,
V_5 -> V_7 + V_14 ) ;
for ( V_132 = 0 ; V_132 < V_139 ; V_132 ++ )
V_3 -> V_138 [ V_132 ] =
F_4 ( V_6 + F_63 ( V_132 ) ) ;
}
if ( ( V_53 -> V_72 -> V_134 & V_153 ) &&
V_53 -> V_72 -> V_141 )
memcpy ( V_3 -> V_138 , V_53 -> V_72 -> V_141 , V_139 ) ;
if ( ! F_64 ( V_3 -> V_138 ) ) {
F_65 ( V_3 ) ;
F_66 ( & V_3 -> V_3 , L_15 ,
V_3 -> V_138 ) ;
}
F_6 ( V_3 ) ;
V_5 -> V_68 = L_16 ;
V_5 -> V_154 = V_50 ;
V_5 -> V_131 = V_131 ;
V_5 -> V_41 = ( V_53 -> V_72 -> V_137 == 2 ) ;
V_5 -> V_155 = V_50 + V_156 ;
#ifdef F_67
V_5 -> V_131 = V_5 -> V_154 + F_67 ;
#endif
V_5 -> V_157 = & F_6 ;
V_5 -> V_158 = & F_15 ;
V_5 -> V_159 = & F_16 ;
V_5 -> V_160 = & F_10 ;
V_5 -> V_161 = 0 ;
V_5 -> V_95 = V_162 ;
V_3 -> V_163 = & V_164 ;
V_3 -> V_165 = & V_166 ;
V_61 = F_55 ( V_3 ) ;
if ( V_61 )
goto V_133;
F_19 ( V_3 , 0 ) ;
V_61 = F_68 ( V_3 ) ;
if ( V_61 )
goto V_133;
F_25 ( V_3 , L_17 ,
V_5 -> V_41 ? 16 : 8 , V_3 -> V_69 , V_3 -> V_20 ,
V_3 -> V_138 ) ;
return 0 ;
V_133:
return V_61 ;
}
static int F_69 ( struct V_87 * V_88 )
{
struct V_2 * V_3 = F_70 ( V_88 ) ;
struct V_4 * V_5 = F_2 ( V_3 ) ;
struct V_1 * V_53 = F_1 ( V_3 ) ;
struct V_167 * V_7 ;
F_71 ( V_3 ) ;
F_35 ( V_3 -> V_69 , V_3 ) ;
F_72 ( V_5 -> V_7 ) ;
V_7 = F_73 ( V_88 , V_168 , 0 ) ;
F_74 ( V_7 -> V_169 , F_75 ( V_7 ) ) ;
if ( V_53 -> V_170 ) {
F_72 ( V_53 -> V_170 ) ;
V_7 = F_73 ( V_88 , V_168 , 1 ) ;
F_74 ( V_7 -> V_169 , F_75 ( V_7 ) ) ;
}
F_76 ( V_3 ) ;
return 0 ;
}
static int F_77 ( struct V_87 * V_88 )
{
struct V_2 * V_3 ;
struct V_4 * V_5 ;
struct V_1 * V_53 ;
struct V_167 * V_69 , * V_7 , * V_171 ;
unsigned long V_172 , V_173 = 0 ;
int V_61 = 0 ;
V_3 = F_78 ( sizeof( struct V_1 ) ) ;
if ( V_3 == NULL )
return - V_124 ;
F_79 ( V_3 , & V_88 -> V_3 ) ;
V_5 = F_2 ( V_3 ) ;
V_53 = F_1 ( V_3 ) ;
V_53 -> V_72 = F_80 ( & V_88 -> V_3 ) ;
F_81 ( V_88 , V_3 ) ;
V_5 -> V_174 = V_53 -> V_72 -> V_175 ;
V_69 = F_73 ( V_88 , V_176 , 0 ) ;
if ( ! V_69 ) {
F_82 ( & V_88 -> V_3 , L_18 ) ;
V_61 = - V_177 ;
goto V_178;
}
V_3 -> V_69 = V_69 -> V_169 ;
V_53 -> V_76 = V_69 -> V_134 & V_179 ;
V_7 = F_73 ( V_88 , V_168 , 0 ) ;
if ( ! V_7 ) {
F_82 ( & V_88 -> V_3 , L_19 ) ;
V_61 = - V_177 ;
goto V_178;
}
V_172 = F_75 ( V_7 ) ;
if ( V_53 -> V_72 -> V_180 )
V_5 -> V_181 = V_53 -> V_72 -> V_180 ;
else {
V_5 -> V_181 = V_53 -> V_180 ;
for ( V_61 = 0 ; V_61 < 0x18 ; V_61 ++ )
V_53 -> V_180 [ V_61 ] = ( V_172 / 0x18 ) * V_61 ;
}
if ( ! F_83 ( V_7 -> V_169 , V_172 , V_88 -> V_68 ) ) {
F_82 ( & V_88 -> V_3 , L_20 ) ;
V_61 = - V_177 ;
goto V_178;
}
V_5 -> V_7 = F_84 ( V_7 -> V_169 , V_172 ) ;
V_3 -> V_20 = ( unsigned long ) V_5 -> V_7 ;
if ( V_5 -> V_7 == NULL ) {
F_82 ( & V_88 -> V_3 , L_21 , V_7 ) ;
V_61 = - V_177 ;
goto V_182;
}
V_171 = F_73 ( V_88 , V_168 , 1 ) ;
if ( ! V_171 ) {
if ( ! V_53 -> V_72 -> V_180 ) {
for ( V_61 = 0 ; V_61 < 0x20 ; V_61 ++ )
V_53 -> V_180 [ V_61 ] = ( V_172 / 0x20 ) * V_61 ;
}
} else {
V_173 = F_75 ( V_171 ) ;
if ( ! F_83 ( V_171 -> V_169 , V_173 , V_88 -> V_68 ) ) {
F_82 ( & V_88 -> V_3 , L_20 ) ;
V_61 = - V_177 ;
goto V_183;
}
V_53 -> V_170 = F_84 ( V_171 -> V_169 , V_173 ) ;
if ( ! V_53 -> V_170 ) {
F_82 ( & V_88 -> V_3 , L_22 ) ;
V_61 = - V_177 ;
goto V_184;
}
V_5 -> V_181 [ 0x1f ] = V_53 -> V_170 - V_5 -> V_7 ;
}
V_61 = F_60 ( V_3 ) ;
if ( ! V_61 )
return 0 ;
if ( ! V_53 -> V_170 )
goto V_183;
F_72 ( V_53 -> V_170 ) ;
V_184:
if ( V_171 )
F_74 ( V_171 -> V_169 , V_173 ) ;
V_183:
F_72 ( V_5 -> V_7 ) ;
V_182:
F_74 ( V_7 -> V_169 , V_172 ) ;
V_178:
F_76 ( V_3 ) ;
return V_61 ;
}
static int F_85 ( struct V_87 * V_3 , T_4 V_185 )
{
struct V_2 * V_186 = F_70 ( V_3 ) ;
struct V_1 * V_53 = F_1 ( V_186 ) ;
V_53 -> V_187 = V_53 -> V_80 ;
F_86 ( V_186 ) ;
F_36 ( V_186 ) ;
return 0 ;
}
static int F_87 ( struct V_87 * V_88 )
{
struct V_2 * V_186 = F_70 ( V_88 ) ;
struct V_1 * V_53 = F_1 ( V_186 ) ;
F_59 ( V_186 , F_2 ( V_186 ) ) ;
F_19 ( V_186 , V_53 -> V_187 ) ;
F_88 ( V_186 ) ;
if ( V_53 -> V_187 )
F_29 ( V_186 ) ;
return 0 ;
}
