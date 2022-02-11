static T_1 unsigned int F_1 ( struct V_1 * V_2 , int V_3 )
{
return F_2 ( V_2 -> V_4 . V_5 + V_3 ) ;
}
static T_1 void F_3 ( struct V_1 * V_2 , int V_3 , int V_6 )
{
F_4 ( V_6 , V_2 -> V_4 . V_5 + V_3 ) ;
}
static T_1 unsigned int F_5 ( struct V_1 * V_2 , int V_3 )
{
return F_2 ( V_2 -> V_7 + V_3 ) ;
}
static int F_6 ( struct V_1 * V_2 , int V_8 )
{
unsigned long V_7 = V_2 -> V_7 ;
unsigned int V_9 = 0 ;
switch ( V_8 )
{
case 0 :
case 1 :
F_4 ( 0x00 , V_7 + V_10 ) ;
break;
case 2 :
case 3 :
F_4 ( 0x01 , V_7 + V_10 ) ;
break;
case 4 :
case 5 :
F_4 ( 0x02 , V_7 + V_10 ) ;
break;
default:
break;
}
V_8 &= 0x1 ;
V_9 = F_2 ( V_7 + V_11 + V_8 ) ;
F_4 ( 0x03 , V_7 + V_10 ) ;
return ( V_9 ) ;
}
static int F_7 ( struct V_12 * V_4 , int V_13 , int V_14 )
{
int V_15 = 0 ;
unsigned int V_16 = 0 ;
unsigned int V_17 = 0 ;
unsigned int V_18 = 0 ;
if( V_13 <= 0 )
{
F_8 ( L_1 ) ;
return - 1 ;
}
switch( V_13 )
{
case 1 :
V_16 = F_9 ( V_4 ) ;
V_18 = V_16 | V_19 ;
F_10 ( V_4 , V_18 ) ;
V_18 = F_9 ( V_4 ) ;
V_15 = F_11 ( V_4 , V_14 ) ;
F_10 ( V_4 , V_16 ) ;
break;
case 2 :
V_17 = F_12 ( V_4 ) ;
V_18 = V_17 | V_20 ;
F_13 ( V_4 , V_18 ) ;
V_15 = F_11 ( V_4 , V_14 ) ;
F_13 ( V_4 , V_17 ) ;
break;
case 3 :
V_16 = F_9 ( V_4 ) ;
V_18 = V_16 | V_21 ;
F_10 ( V_4 , V_18 ) ;
F_14 ( V_4 , V_22 , V_23 ) ;
V_15 = F_11 ( V_4 , V_14 ) ;
F_10 ( V_4 , V_16 ) ;
break;
case 4 :
V_16 = F_9 ( V_4 ) ;
V_18 = V_16 | V_21 ;
F_10 ( V_4 , V_18 ) ;
F_14 ( V_4 , V_22 , V_24 ) ;
V_15 = F_11 ( V_4 , V_14 ) ;
F_10 ( V_4 , V_16 ) ;
break;
default:
F_8 ( L_2 ) ;
return - 1 ;
}
return V_15 ;
}
static int F_15 ( struct V_12 * V_4 , int V_13 , int V_14 , int V_6 )
{
int V_16 = 0 ;
int V_17 = 0 ;
int V_15 = 0 ;
if( V_13 <= 0 )
{
F_8 ( L_1 ) ;
return - 1 ;
}
switch( V_13 )
{
case 1 :
V_16 = F_9 ( V_4 ) ;
F_10 ( V_4 , V_16 | V_19 ) ;
F_14 ( V_4 , V_14 , V_6 ) ;
F_10 ( V_4 , V_16 ) ;
V_15 = 1 ;
break;
case 2 :
V_17 = F_12 ( V_4 ) ;
F_13 ( V_4 , V_17 | V_20 ) ;
F_14 ( V_4 , V_14 , V_6 ) ;
F_13 ( V_4 , V_17 ) ;
V_15 = 1 ;
break;
case 3 :
V_16 = F_9 ( V_4 ) ;
F_10 ( V_4 , V_16 | V_21 ) ;
F_16 ( V_4 , V_23 ) ;
F_14 ( V_4 , V_14 , V_6 ) ;
F_10 ( V_4 , V_16 ) ;
V_15 = 1 ;
break;
case 4 :
V_16 = F_9 ( V_4 ) ;
F_10 ( V_4 , V_16 | V_21 ) ;
F_16 ( V_4 , V_24 ) ;
F_14 ( V_4 , V_14 , V_6 ) ;
F_10 ( V_4 , V_16 ) ;
V_15 = 1 ;
break;
default:
F_8 ( L_2 ) ;
return - 1 ;
}
return V_15 ;
}
static int F_17 ( struct V_12 * V_4 , unsigned int V_25 )
{
int V_26 = V_27 ;
if ( V_25 & V_28 )
{
V_26 |= V_29 ;
}
if ( 1 )
{
int V_30 = 0 ;
V_26 |= V_31 ;
V_30 = F_7 ( V_4 , V_32 , V_33 ) ;
V_30 |= V_34 ;
F_15 ( V_4 , V_32 , V_33 , V_30 ) ;
}
F_15 ( V_4 , V_35 , V_36 , V_26 ) ;
V_4 -> V_37 &= ~ 0x6 ;
V_4 -> V_37 |= V_25 ;
F_8 ( L_3 , V_4 -> line , V_4 -> V_37 ) ;
return 0 ;
}
static int F_18 ( struct V_12 * V_4 )
{
return F_7 ( V_4 , V_32 , V_38 ) ;
}
static int F_19 ( struct V_12 * V_4 , unsigned int V_39 )
{
F_15 ( V_4 , V_32 , V_38 , V_39 ) ;
return 0 ;
}
static void F_20 ( struct V_1 * V_2 )
{
unsigned char V_40 [] = { 0x61 , 0x74 , 0x0d , 0x0a , 0x0 } ;
unsigned char V_41 ;
unsigned char V_42 = 0 ;
unsigned char V_43 = 0xc ;
V_41 = F_21 ( V_2 , V_44 ) ;
F_22 ( V_2 , V_44 , ( V_41 | V_45 ) ) ;
F_22 ( V_2 , V_46 , ( V_43 & 0xff ) ) ;
F_22 ( V_2 , V_47 , ( V_43 & 0xff00 ) >> 8 ) ;
F_22 ( V_2 , V_44 , V_41 ) ;
F_22 ( V_2 , V_44 , 0x03 ) ;
F_22 ( V_2 , V_48 , 7 ) ;
F_22 ( V_2 , V_49 , 0x3 ) ;
while( V_40 [ V_42 ] ) {
while( ( F_21 ( V_2 , V_50 ) & 0x60 ) != 0x60 ) {
;
}
F_22 ( V_2 , 0 , V_40 [ V_42 ++ ] ) ;
}
}
static int F_23 ( struct V_12 * V_4 , int V_51 )
{
int V_52 = 0 ;
V_52 = F_7 ( V_4 , V_53 , V_54 ) ;
if( V_51 == V_55 )
{
V_52 |= V_56 ;
}
else
{
V_52 &= ~ V_56 ;
}
F_15 ( V_4 , V_53 , V_54 , V_52 ) ;
F_15 ( V_4 , V_53 , V_57 , V_58 [ V_4 -> line ] ) ;
F_15 ( V_4 , V_53 , V_59 , V_60 [ V_4 -> line ] ) ;
V_52 = F_7 ( V_4 , V_53 , V_54 ) ;
return V_52 ;
}
static int F_24 ( int V_61 )
{
int V_15 ;
V_15 = F_2 ( V_62 [ V_61 ] . V_63 + V_64 ) ;
V_15 = ( V_15 & 0xf0 ) >> 4 ;
switch ( V_15 )
{
case V_65 :
return V_66 ;
case V_67 :
return V_68 ;
case V_69 :
return V_70 ;
default:
return V_71 ;
}
}
static int F_25 ( struct V_12 * V_4 )
{
int V_52 = 0 ;
V_52 = F_7 ( V_4 , V_53 , V_54 ) ;
return V_52 ;
}
static int F_26 ( struct V_12 * V_4 , int V_51 )
{
int V_72 = 0 ;
#if 0
int efr_status = 0;
efr_status = sb1054_get_register(port, PAGE_3, SB105X_EFR);
if(status == ENABLE)
efr_status |= SB105X_EFR_ARTS;
else
efr_status &= ~SB105X_EFR_ARTS;
sb1054_set_register(port,PAGE_3,SB105X_EFR,efr_status);
efr_status = sb1054_get_register(port, PAGE_3, SB105X_EFR);
#endif
V_72 = F_7 ( V_4 , V_32 , V_73 ) ;
switch( V_51 )
{
case V_74 :
V_72 = ( V_75 ) | ( V_76 ) ;
break;
case V_77 :
V_72 = ( V_75 ) | ( V_78 ) | ( V_76 ) ;
break;
case V_79 :
V_72 = ( V_80 ) | ( V_75 ) | ( V_78 ) | ( V_76 ) ;
break;
case V_81 :
V_72 = ( V_75 ) | ( V_78 ) | ( V_76 ) ;
break;
}
F_15 ( V_4 , V_32 , V_73 , V_72 ) ;
V_72 = F_7 ( V_4 , V_32 , V_73 ) ;
return V_72 ;
}
static void F_27 ( struct V_82 * V_83 )
{
struct V_84 * V_85 = V_83 -> V_86 ;
struct V_12 * V_4 = V_85 -> V_4 ;
unsigned long V_87 ;
F_28 ( & V_4 -> V_88 , V_87 ) ;
V_4 -> V_89 -> V_90 ( V_4 ) ;
F_29 ( & V_4 -> V_88 , V_87 ) ;
}
static void F_30 ( struct V_82 * V_83 )
{
struct V_84 * V_85 = V_83 -> V_86 ;
struct V_12 * V_4 = V_85 -> V_4 ;
if ( ! F_31 ( & V_85 -> V_91 -> V_92 ) && V_85 -> V_91 -> V_92 . V_93 &&
! V_83 -> V_94 && ! V_83 -> V_95 )
V_4 -> V_89 -> V_96 ( V_4 ) ;
}
static void F_32 ( struct V_82 * V_83 )
{
F_30 ( V_83 ) ;
}
static void F_33 ( unsigned long V_97 )
{
struct V_84 * V_85 = (struct V_84 * ) V_97 ;
struct V_82 * V_83 ;
F_8 ( L_4 ) ;
V_83 = V_85 -> V_91 -> V_83 ;
F_34 ( V_83 ) ;
}
static inline void F_35 ( struct V_12 * V_4 , unsigned int V_98 , unsigned int V_99 )
{
unsigned int V_100 ;
V_100 = V_4 -> V_101 ;
V_4 -> V_101 = ( V_100 & ~ V_99 ) | V_98 ;
if ( V_100 != V_4 -> V_101 )
V_4 -> V_89 -> V_102 ( V_4 , V_4 -> V_101 ) ;
}
static int F_36 ( struct V_84 * V_85 , int V_103 )
{
struct V_104 * V_91 = V_85 -> V_91 ;
struct V_12 * V_4 = V_85 -> V_4 ;
unsigned long V_13 ;
int V_105 = 0 ;
if ( V_91 -> V_87 & V_106 )
return 0 ;
if ( V_91 -> V_83 )
F_37 ( V_107 , & V_91 -> V_83 -> V_87 ) ;
if ( V_4 -> type == V_71 )
return 0 ;
if ( ! V_91 -> V_92 . V_93 ) {
V_13 = F_38 ( V_108 ) ;
if ( ! V_13 )
return - V_109 ;
V_91 -> V_92 . V_93 = ( unsigned char * ) V_13 ;
F_39 ( & V_91 -> V_92 ) ;
}
V_105 = V_4 -> V_89 -> V_110 ( V_4 ) ;
if ( V_105 == 0 ) {
if ( V_103 ) {
F_40 ( V_85 , NULL ) ;
if ( V_91 -> V_83 -> V_111 . V_112 & V_113 )
F_41 ( V_4 , V_114 | V_115 ) ;
}
V_91 -> V_87 |= V_106 ;
F_42 ( V_107 , & V_91 -> V_83 -> V_87 ) ;
}
if ( V_105 && F_43 ( V_116 ) )
V_105 = 0 ;
return V_105 ;
}
static void F_44 ( struct V_84 * V_85 )
{
struct V_104 * V_91 = V_85 -> V_91 ;
struct V_12 * V_4 = V_85 -> V_4 ;
if ( V_91 -> V_83 )
F_37 ( V_107 , & V_91 -> V_83 -> V_87 ) ;
if ( V_91 -> V_87 & V_106 ) {
V_91 -> V_87 &= ~ V_106 ;
if ( ! V_91 -> V_83 || ( V_91 -> V_83 -> V_111 . V_112 & V_117 ) )
F_45 ( V_4 , V_115 | V_114 ) ;
F_46 ( & V_91 -> V_118 ) ;
V_4 -> V_89 -> V_119 ( V_4 ) ;
F_47 ( V_4 -> V_120 ) ;
}
F_48 ( & V_91 -> V_121 ) ;
if ( V_91 -> V_92 . V_93 ) {
F_49 ( ( unsigned long ) V_91 -> V_92 . V_93 ) ;
V_91 -> V_92 . V_93 = NULL ;
}
}
static void F_40 ( struct V_84 * V_85 , struct V_122 * V_123 )
{
struct V_82 * V_83 = V_85 -> V_91 -> V_83 ;
struct V_12 * V_4 = V_85 -> V_4 ;
if ( ! V_83 || V_4 -> type == V_71 )
return;
if ( V_83 -> V_111 . V_112 & V_124 )
V_85 -> V_91 -> V_87 |= V_125 ;
else
V_85 -> V_91 -> V_87 &= ~ V_125 ;
if ( V_83 -> V_111 . V_112 & V_126 )
V_85 -> V_91 -> V_87 &= ~ V_127 ;
else
V_85 -> V_91 -> V_87 |= V_127 ;
V_4 -> V_89 -> V_128 ( V_4 , & V_83 -> V_111 , V_123 ) ;
}
static inline int F_50 ( struct V_12 * V_4 , struct V_129 * V_130 , unsigned char V_131 )
{
unsigned long V_87 ;
int V_15 = 0 ;
if ( ! V_130 -> V_93 )
return 0 ;
F_28 ( & V_4 -> V_88 , V_87 ) ;
if ( F_51 ( V_130 ) != 0 ) {
V_130 -> V_93 [ V_130 -> V_132 ] = V_131 ;
V_130 -> V_132 = ( V_130 -> V_132 + 1 ) & ( V_133 - 1 ) ;
V_15 = 1 ;
}
F_29 ( & V_4 -> V_88 , V_87 ) ;
return V_15 ;
}
static int F_52 ( struct V_82 * V_83 , unsigned char V_40 )
{
struct V_84 * V_85 = V_83 -> V_86 ;
return F_50 ( V_85 -> V_4 , & V_85 -> V_91 -> V_92 , V_40 ) ;
}
static void F_53 ( struct V_82 * V_83 )
{
F_32 ( V_83 ) ;
}
static int F_54 ( struct V_82 * V_83 , const unsigned char * V_93 , int V_134 )
{
struct V_84 * V_85 = V_83 -> V_86 ;
struct V_12 * V_4 ;
struct V_129 * V_130 ;
int V_131 , V_15 = 0 ;
if ( ! V_85 || ! V_85 -> V_91 ) {
return - V_135 ;
}
V_4 = V_85 -> V_4 ;
V_130 = & V_85 -> V_91 -> V_92 ;
if ( ! V_130 -> V_93 )
return 0 ;
while ( 1 ) {
V_131 = F_55 ( V_130 -> V_132 , V_130 -> V_136 , V_133 ) ;
if ( V_134 < V_131 )
V_131 = V_134 ;
if ( V_131 <= 0 )
break;
memcpy ( V_130 -> V_93 + V_130 -> V_132 , V_93 , V_131 ) ;
V_130 -> V_132 = ( V_130 -> V_132 + V_131 ) & ( V_133 - 1 ) ;
V_93 += V_131 ;
V_134 -= V_131 ;
V_15 += V_131 ;
}
F_32 ( V_83 ) ;
return V_15 ;
}
static int F_56 ( struct V_82 * V_83 )
{
struct V_84 * V_85 = V_83 -> V_86 ;
return F_51 ( & V_85 -> V_91 -> V_92 ) ;
}
static int F_57 ( struct V_82 * V_83 )
{
struct V_84 * V_85 = V_83 -> V_86 ;
return F_58 ( & V_85 -> V_91 -> V_92 ) ;
}
static void F_59 ( struct V_82 * V_83 )
{
struct V_84 * V_85 = V_83 -> V_86 ;
struct V_12 * V_4 ;
unsigned long V_87 ;
if ( ! V_85 || ! V_85 -> V_91 ) {
return;
}
V_4 = V_85 -> V_4 ;
F_28 ( & V_4 -> V_88 , V_87 ) ;
F_39 ( & V_85 -> V_91 -> V_92 ) ;
F_29 ( & V_4 -> V_88 , V_87 ) ;
F_46 ( & V_83 -> V_137 ) ;
F_34 ( V_83 ) ;
}
static void F_60 ( struct V_82 * V_83 , char V_40 )
{
struct V_84 * V_85 = V_83 -> V_86 ;
struct V_12 * V_4 = V_85 -> V_4 ;
unsigned long V_87 ;
if ( V_4 -> V_89 -> V_138 )
V_4 -> V_89 -> V_138 ( V_4 , V_40 ) ;
else {
V_4 -> V_139 = V_40 ;
if ( V_40 ) {
F_28 ( & V_4 -> V_88 , V_87 ) ;
V_4 -> V_89 -> V_96 ( V_4 ) ;
F_29 ( & V_4 -> V_88 , V_87 ) ;
}
}
}
static void F_61 ( struct V_82 * V_83 )
{
struct V_84 * V_85 = V_83 -> V_86 ;
if ( F_62 ( V_83 ) )
F_60 ( V_83 , F_63 ( V_83 ) ) ;
if ( V_83 -> V_111 . V_112 & V_124 )
F_45 ( V_85 -> V_4 , V_114 ) ;
}
static void F_64 ( struct V_82 * V_83 )
{
struct V_84 * V_85 = V_83 -> V_86 ;
struct V_12 * V_4 = V_85 -> V_4 ;
if ( F_62 ( V_83 ) ) {
if ( V_4 -> V_139 )
V_4 -> V_139 = 0 ;
else
F_60 ( V_83 , F_65 ( V_83 ) ) ;
}
if ( V_83 -> V_111 . V_112 & V_124 )
F_41 ( V_4 , V_114 ) ;
}
static int F_66 ( struct V_84 * V_85 , struct V_140 * V_141 )
{
struct V_12 * V_4 = V_85 -> V_4 ;
struct V_140 V_18 ;
memset ( & V_18 , 0 , sizeof( V_18 ) ) ;
V_18 . type = V_4 -> type ;
V_18 . line = V_4 -> line ;
V_18 . V_4 = V_4 -> V_5 ;
if ( V_142 )
V_18 . V_143 = ( long ) V_4 -> V_5 >> V_142 ;
V_18 . V_120 = V_4 -> V_120 ;
V_18 . V_87 = V_4 -> V_87 ;
V_18 . V_144 = V_4 -> V_145 ;
V_18 . V_146 = V_4 -> V_147 / 16 ;
V_18 . V_148 = V_85 -> V_148 ;
V_18 . V_149 = V_85 -> V_149 == V_150 ?
V_151 :
V_85 -> V_149 ;
V_18 . V_152 = V_4 -> V_152 ;
V_18 . V_153 = V_4 -> V_153 ;
V_18 . V_154 = V_4 -> V_155 ;
V_18 . V_156 = V_4 -> V_157 ;
V_18 . V_158 = ( void * ) V_4 -> V_159 ;
if ( F_67 ( V_141 , & V_18 , sizeof( * V_141 ) ) )
return - V_160 ;
return 0 ;
}
static int F_68 ( struct V_84 * V_85 , struct V_140 * V_161 )
{
struct V_140 V_162 ;
struct V_12 * V_4 = V_85 -> V_4 ;
unsigned long V_163 ;
unsigned int V_164 , V_165 , V_149 ;
unsigned int V_166 ;
unsigned int V_167 , V_168 ;
int V_105 = 0 ;
if ( F_69 ( & V_162 , V_161 , sizeof( V_162 ) ) )
return - V_160 ;
V_163 = V_162 . V_4 ;
if ( V_142 )
V_163 += ( unsigned long ) V_162 . V_143 << V_142 ;
V_162 . V_120 = F_70 ( V_162 . V_120 ) ;
V_149 = V_162 . V_149 == V_151 ?
V_150 : V_162 . V_149 ;
F_71 ( V_85 ) ;
V_164 = V_162 . V_120 != V_4 -> V_120 ;
V_165 = V_163 != V_4 -> V_5 ||
( unsigned long ) V_162 . V_158 != V_4 -> V_159 ||
V_162 . V_153 != V_4 -> V_153 ||
V_162 . V_154 != V_4 -> V_155 ||
V_162 . V_156 != V_4 -> V_157 ||
V_162 . type != V_4 -> type ;
V_167 = V_4 -> V_87 ;
V_168 = V_162 . V_87 ;
V_166 = V_4 -> V_152 ;
if ( ! F_43 ( V_116 ) ) {
V_105 = - V_169 ;
if ( V_164 || V_165 ||
( V_162 . V_146 != V_4 -> V_147 / 16 ) ||
( V_162 . V_148 != V_85 -> V_148 ) ||
( V_149 != V_85 -> V_149 ) ||
( V_162 . V_144 != V_4 -> V_145 ) ||
( ( ( V_168 ^ V_167 ) & ~ V_170 ) != 0 ) )
goto exit;
V_4 -> V_87 = ( ( V_4 -> V_87 & ~ V_170 ) |
( V_168 & V_170 ) ) ;
V_4 -> V_152 = V_162 . V_152 ;
goto V_171;
}
if ( V_4 -> V_89 -> V_172 )
V_105 = V_4 -> V_89 -> V_172 ( V_4 , & V_162 ) ;
if ( ( V_162 . V_120 >= V_173 ) || ( V_162 . V_120 < 0 ) ||
( V_162 . V_146 < 9600 ) )
V_105 = - V_174 ;
if ( V_105 )
goto exit;
if ( V_165 || V_164 ) {
V_105 = - V_175 ;
if ( F_72 ( V_85 ) > 1 )
goto exit;
F_44 ( V_85 ) ;
}
if ( V_165 ) {
unsigned long V_176 , V_177 ;
unsigned int V_178 , V_179 , V_180 , V_181 ;
V_176 = V_4 -> V_5 ;
V_177 = V_4 -> V_159 ;
V_178 = V_4 -> type ;
V_180 = V_4 -> V_153 ;
V_179 = V_4 -> V_155 ;
V_181 = V_4 -> V_157 ;
if ( V_178 != V_71 )
V_4 -> V_89 -> V_182 ( V_4 ) ;
V_4 -> V_5 = V_163 ;
V_4 -> type = V_162 . type ;
V_4 -> V_153 = V_162 . V_153 ;
V_4 -> V_155 = V_162 . V_154 ;
V_4 -> V_157 = V_162 . V_156 ;
V_4 -> V_159 = ( unsigned long ) V_162 . V_158 ;
if ( V_4 -> type != V_71 ) {
V_105 = V_4 -> V_89 -> V_183 ( V_4 ) ;
} else {
V_105 = 0 ;
}
if ( V_105 && V_178 != V_71 ) {
V_4 -> V_5 = V_176 ;
V_4 -> type = V_178 ;
V_4 -> V_153 = V_180 ;
V_4 -> V_155 = V_179 ;
V_4 -> V_157 = V_181 ;
V_4 -> V_159 = V_177 ;
V_105 = V_4 -> V_89 -> V_183 ( V_4 ) ;
if ( V_105 )
V_4 -> type = V_71 ;
V_105 = - V_175 ;
}
}
V_4 -> V_120 = V_162 . V_120 ;
V_4 -> V_147 = V_162 . V_146 * 16 ;
V_4 -> V_87 = ( V_4 -> V_87 & ~ V_184 ) |
( V_168 & V_184 ) ;
V_4 -> V_152 = V_162 . V_152 ;
V_85 -> V_148 = V_162 . V_148 ;
V_85 -> V_149 = V_149 ;
V_4 -> V_145 = V_162 . V_144 ;
if ( V_85 -> V_91 -> V_83 )
V_85 -> V_91 -> V_83 -> V_185 =
( V_4 -> V_87 & V_186 ) ? 1 : 0 ;
V_171:
V_105 = 0 ;
if ( V_4 -> type == V_71 )
goto exit;
if ( V_85 -> V_91 -> V_87 & V_106 ) {
if ( ( ( V_167 ^ V_4 -> V_87 ) & V_187 ) ||
V_166 != V_4 -> V_152 ) {
if ( V_4 -> V_87 & V_187 ) {
F_8 ( V_188
L_5
L_6 , V_189 -> V_190 ,
V_4 -> line ) ;
}
F_40 ( V_85 , NULL ) ;
}
} else
V_105 = F_36 ( V_85 , 1 ) ;
exit:
F_73 ( V_85 ) ;
return V_105 ;
}
static int F_74 ( struct V_84 * V_85 , unsigned int * V_6 )
{
struct V_12 * V_4 = V_85 -> V_4 ;
unsigned int V_191 ;
V_191 = V_4 -> V_89 -> V_192 ( V_4 ) ;
if ( V_4 -> V_139 ||
( ( F_58 ( & V_85 -> V_91 -> V_92 ) > 0 ) &&
! V_85 -> V_91 -> V_83 -> V_94 && ! V_85 -> V_91 -> V_83 -> V_95 ) )
V_191 &= ~ V_193 ;
return F_75 ( V_191 , V_6 ) ;
}
static int F_76 ( struct V_82 * V_83 )
{
struct V_84 * V_85 = V_83 -> V_86 ;
struct V_12 * V_4 = V_85 -> V_4 ;
int V_191 = - V_194 ;
F_71 ( V_85 ) ;
if ( ! ( V_83 -> V_87 & ( 1 << V_107 ) ) ) {
V_191 = V_4 -> V_101 ;
F_77 ( & V_4 -> V_88 ) ;
V_191 |= V_4 -> V_89 -> V_195 ( V_4 ) ;
F_78 ( & V_4 -> V_88 ) ;
}
F_73 ( V_85 ) ;
return V_191 ;
}
static int F_79 ( struct V_82 * V_83 , unsigned int V_98 , unsigned int V_99 )
{
struct V_84 * V_85 = V_83 -> V_86 ;
struct V_12 * V_4 = V_85 -> V_4 ;
int V_15 = - V_194 ;
F_71 ( V_85 ) ;
if ( ! ( V_83 -> V_87 & ( 1 << V_107 ) ) ) {
F_35 ( V_4 , V_98 , V_99 ) ;
V_15 = 0 ;
}
F_73 ( V_85 ) ;
return V_15 ;
}
static int F_80 ( struct V_82 * V_83 , int V_196 )
{
struct V_84 * V_85 = V_83 -> V_86 ;
struct V_12 * V_4 = V_85 -> V_4 ;
F_71 ( V_85 ) ;
if ( V_4 -> type != V_71 )
V_4 -> V_89 -> V_197 ( V_4 , V_196 ) ;
F_73 ( V_85 ) ;
return 0 ;
}
static int F_81 ( struct V_84 * V_85 )
{
struct V_12 * V_4 = V_85 -> V_4 ;
int V_87 , V_15 ;
if ( ! F_43 ( V_116 ) )
return - V_169 ;
if ( F_82 ( & V_85 -> V_198 ) )
return - V_199 ;
V_15 = - V_175 ;
if ( F_72 ( V_85 ) == 1 ) {
F_44 ( V_85 ) ;
if ( V_4 -> type != V_71 )
V_4 -> V_89 -> V_182 ( V_4 ) ;
V_87 = V_200 ;
if ( V_4 -> V_87 & V_201 )
V_87 |= V_202 ;
V_4 -> V_89 -> V_203 ( V_4 , V_87 ) ;
V_15 = F_36 ( V_85 , 1 ) ;
}
F_73 ( V_85 ) ;
return V_15 ;
}
static int F_83 ( struct V_84 * V_85 , unsigned long V_61 )
{
struct V_12 * V_4 = V_85 -> V_4 ;
F_84 ( V_204 , V_189 ) ;
struct V_205 V_206 , V_207 ;
int V_15 ;
F_77 ( & V_4 -> V_88 ) ;
memcpy ( & V_206 , & V_4 -> V_208 , sizeof( struct V_205 ) ) ;
V_4 -> V_89 -> V_209 ( V_4 ) ;
F_78 ( & V_4 -> V_88 ) ;
F_85 ( & V_85 -> V_91 -> V_118 , & V_204 ) ;
for (; ; ) {
F_77 ( & V_4 -> V_88 ) ;
memcpy ( & V_207 , & V_4 -> V_208 , sizeof( struct V_205 ) ) ;
F_78 ( & V_4 -> V_88 ) ;
F_86 ( V_210 ) ;
if ( ( ( V_61 & V_211 ) && ( V_207 . V_212 != V_206 . V_212 ) ) ||
( ( V_61 & V_213 ) && ( V_207 . V_214 != V_206 . V_214 ) ) ||
( ( V_61 & V_215 ) && ( V_207 . V_216 != V_206 . V_216 ) ) ||
( ( V_61 & V_217 ) && ( V_207 . V_218 != V_206 . V_218 ) ) ) {
V_15 = 0 ;
break;
}
F_87 () ;
if ( F_88 ( V_189 ) ) {
V_15 = - V_199 ;
break;
}
V_206 = V_207 ;
}
V_189 -> V_85 = V_219 ;
F_89 ( & V_85 -> V_91 -> V_118 , & V_204 ) ;
return V_15 ;
}
static int F_90 ( struct V_84 * V_85 , struct V_220 * V_221 )
{
struct V_220 V_208 ;
struct V_205 V_207 ;
struct V_12 * V_4 = V_85 -> V_4 ;
F_77 ( & V_4 -> V_88 ) ;
memcpy ( & V_207 , & V_4 -> V_208 , sizeof( struct V_205 ) ) ;
F_78 ( & V_4 -> V_88 ) ;
V_208 . V_218 = V_207 . V_218 ;
V_208 . V_214 = V_207 . V_214 ;
V_208 . V_212 = V_207 . V_212 ;
V_208 . V_216 = V_207 . V_216 ;
V_208 . V_222 = V_207 . V_222 ;
V_208 . V_223 = V_207 . V_223 ;
V_208 . V_224 = V_207 . V_224 ;
V_208 . V_225 = V_207 . V_225 ;
V_208 . V_226 = V_207 . V_226 ;
V_208 . V_227 = V_207 . V_227 ;
V_208 . V_228 = V_207 . V_228 ;
return F_67 ( V_221 , & V_208 , sizeof( V_208 ) ) ? - V_160 : 0 ;
}
static int F_91 ( struct V_82 * V_83 , unsigned int V_229 , unsigned long V_61 )
{
struct V_84 * V_85 = V_83 -> V_86 ;
struct V_1 * V_91 = (struct V_1 * ) V_85 -> V_4 ;
int V_15 = - V_230 ;
switch ( V_229 ) {
case V_231 :
if ( V_91 -> V_4 . type == V_70 )
{
return F_17 ( (struct V_12 * ) V_91 , ( unsigned int ) V_61 ) ;
}
V_15 = - V_232 ;
break;
case V_233 :
V_15 = F_25 ( V_85 -> V_4 ) ;
return V_15 ;
case V_234 :
V_15 = F_23 ( V_85 -> V_4 , V_61 ) ;
V_235 [ V_85 -> V_4 -> line ] = V_61 ;
return V_15 ;
case V_236 :
if ( V_91 -> V_4 . type == V_68 || V_91 -> V_4 . type == V_70 ) {
V_15 = F_15 ( V_85 -> V_4 , V_53 , V_57 , V_61 ) ;
V_58 [ V_85 -> V_4 -> line ] = V_61 ;
}
return V_15 ;
case V_237 :
if ( V_91 -> V_4 . type == V_68 || V_91 -> V_4 . type == V_70 ) {
V_15 = F_15 ( V_85 -> V_4 , V_53 , V_59 , V_61 ) ;
V_60 [ V_85 -> V_4 -> line ] = V_61 ;
}
return V_15 ;
case V_238 :
if ( V_91 -> V_4 . type == V_68 || V_91 -> V_4 . type == V_70 ) {
V_15 = F_7 ( V_85 -> V_4 , V_53 , V_57 ) ;
}
return V_15 ;
case V_239 :
if ( V_91 -> V_4 . type == V_68 || V_91 -> V_4 . type == V_70 ) {
V_15 = F_7 ( V_85 -> V_4 , V_53 , V_59 ) ;
}
return V_15 ;
case V_240 :
if ( V_91 -> V_4 . type == V_68 || V_91 -> V_4 . type == V_70 ) {
V_15 = F_15 ( V_85 -> V_4 , V_35 , V_241 , V_61 ) ;
}
else{
F_3 ( V_91 , 2 , V_61 ) ;
}
return V_15 ;
case V_242 :
if ( V_91 -> V_4 . type == V_70 )
{
V_85 -> V_4 -> V_37 |= V_243 ;
return F_19 ( (struct V_12 * ) V_91 , ( unsigned int ) V_61 ) ;
}
V_15 = - V_232 ;
break;
case V_244 :
if ( ( V_91 -> V_4 . type == V_70 ) && ( V_85 -> V_4 -> V_37 & V_243 ) )
{
return F_18 ( (struct V_12 * ) V_91 ) ;
}
V_15 = - V_232 ;
break;
case V_245 :
if ( ( V_91 -> V_4 . type == V_70 )
&& ( V_85 -> V_4 -> V_37 & ( V_28 ) ) )
{
if ( F_57 ( V_83 ) > 0 )
{
F_92 ( V_83 , 0 ) ;
}
while ( ( F_1 ( V_91 , V_50 ) & 0x60 ) != 0x60 ) ;
F_3 ( V_91 , V_246 , ( int ) V_61 ) ;
}
break;
case V_247 :
V_15 = F_66 ( V_85 , (struct V_140 * ) V_61 ) ;
break;
case V_248 :
V_15 = F_68 ( V_85 , (struct V_140 * ) V_61 ) ;
break;
case V_249 :
V_15 = F_81 ( V_85 ) ;
break;
case V_250 :
case V_251 :
V_15 = 0 ;
break;
case V_252 :
return V_253 ;
case V_254 :
return V_62 [ V_61 ] . V_255 ;
case V_256 :
return V_62 [ V_61 ] . V_257 ;
case V_258 :
return V_62 [ V_61 ] . V_259 ;
case V_260 :
return V_261 ;
case V_262 :
if ( V_62 [ V_61 ] . V_257 == 0xc0 )
{
return ( F_6 ( V_91 , V_91 -> V_4 . line ) ) ;
}
else
{
return ( F_2 ( V_62 [ V_61 ] . V_63 + V_11 + ( V_85 -> V_4 -> line / 8 ) ) ) ;
}
case V_263 :
V_15 = F_24 ( V_61 ) ; ;
return V_15 ;
case V_264 :
F_4 ( ( F_2 ( V_91 -> V_265 ) & ~ 0x03 ) | 0x01 ,
V_91 -> V_265 ) ;
return 0 ;
case V_266 :
F_4 ( ( F_2 ( V_91 -> V_265 ) & ~ 0x03 ) ,
V_91 -> V_265 ) ;
return 0 ;
}
if ( V_15 != - V_230 )
goto V_267;
if ( V_83 -> V_87 & ( 1 << V_107 ) ) {
V_15 = - V_194 ;
goto V_267;
}
switch ( V_229 ) {
case V_268 :
V_15 = F_83 ( V_85 , V_61 ) ;
break;
case V_269 :
V_15 = F_90 ( V_85 , (struct V_220 * ) V_61 ) ;
break;
}
if ( V_15 != - V_230 )
goto V_267;
F_71 ( V_85 ) ;
switch ( V_229 ) {
case V_270 :
V_15 = F_74 ( V_85 , ( unsigned int * ) V_61 ) ;
break;
default: {
struct V_12 * V_4 = V_85 -> V_4 ;
if ( V_4 -> V_89 -> V_271 )
V_15 = V_4 -> V_89 -> V_271 ( V_4 , V_229 , V_61 ) ;
break;
}
}
F_73 ( V_85 ) ;
V_267:
return V_15 ;
}
static void F_93 ( struct V_82 * V_83 , struct V_122 * V_123 )
{
struct V_84 * V_85 = V_83 -> V_86 ;
unsigned long V_87 ;
unsigned int V_272 = V_83 -> V_111 . V_112 ;
#define F_94 ( T_2 ) ((iflag) & (IGNBRK|BRKINT|IGNPAR|PARMRK|INPCK))
if ( ( V_272 ^ V_123 -> V_112 ) == 0 &&
F_94 ( V_83 -> V_111 . V_273 ^ V_123 -> V_273 ) == 0 )
return;
F_40 ( V_85 , V_123 ) ;
if ( ( V_123 -> V_112 & V_113 ) && ! ( V_272 & V_113 ) )
F_45 ( V_85 -> V_4 , V_114 | V_115 ) ;
if ( ! ( V_123 -> V_112 & V_113 ) && ( V_272 & V_113 ) ) {
unsigned int V_274 = V_115 ;
if ( ! ( V_272 & V_124 ) ||
! F_95 ( V_275 , & V_83 -> V_87 ) )
V_274 |= V_114 ;
F_41 ( V_85 -> V_4 , V_274 ) ;
}
if ( ( V_123 -> V_112 & V_124 ) && ! ( V_272 & V_124 ) ) {
F_28 ( & V_85 -> V_4 -> V_88 , V_87 ) ;
V_83 -> V_95 = 0 ;
F_30 ( V_83 ) ;
F_29 ( & V_85 -> V_4 -> V_88 , V_87 ) ;
}
if ( ! ( V_123 -> V_112 & V_124 ) && ( V_272 & V_124 ) ) {
F_28 ( & V_85 -> V_4 -> V_88 , V_87 ) ;
if ( ! ( V_85 -> V_4 -> V_89 -> V_195 ( V_85 -> V_4 ) & V_217 ) ) {
V_83 -> V_95 = 1 ;
V_85 -> V_4 -> V_89 -> V_90 ( V_85 -> V_4 ) ;
}
F_29 ( & V_85 -> V_4 -> V_88 , V_87 ) ;
}
}
static void F_96 ( struct V_82 * V_83 , struct V_276 * V_277 )
{
struct V_84 * V_85 = V_83 -> V_86 ;
struct V_12 * V_4 ;
F_8 ( L_7 ) ;
if ( ! V_85 || ! V_85 -> V_4 )
return;
V_4 = V_85 -> V_4 ;
F_8 ( L_8 , __LINE__ ) ;
F_71 ( V_85 ) ;
F_8 ( L_9 , __LINE__ ) ;
if ( F_97 ( V_277 ) )
goto V_278;
F_8 ( L_10 , __LINE__ ) ;
if ( ( V_83 -> V_134 == 1 ) && ( V_85 -> V_134 != 1 ) ) {
F_8 ( L_11
L_12 , V_85 -> V_134 ) ;
V_85 -> V_134 = 1 ;
}
F_8 ( L_13 , __LINE__ ) ;
if ( -- V_85 -> V_134 < 0 ) {
F_8 ( L_14 ,
V_4 -> line , V_85 -> V_134 ) ;
V_85 -> V_134 = 0 ;
}
if ( V_85 -> V_134 )
goto V_278;
V_83 -> V_279 = 1 ;
F_8 ( L_15 , __LINE__ ) ;
if ( V_85 -> V_149 != V_150 )
F_92 ( V_83 , V_85 -> V_149 ) ;
F_8 ( L_16 , __LINE__ ) ;
if ( V_85 -> V_91 -> V_87 & V_106 ) {
unsigned long V_87 ;
F_28 ( & V_4 -> V_88 , V_87 ) ;
V_4 -> V_89 -> V_280 ( V_4 ) ;
F_29 ( & V_4 -> V_88 , V_87 ) ;
F_98 ( V_83 , V_4 -> V_281 ) ;
}
F_8 ( L_17 , __LINE__ ) ;
F_44 ( V_85 ) ;
F_8 ( L_18 , __LINE__ ) ;
F_59 ( V_83 ) ;
F_99 ( V_83 ) ;
V_83 -> V_279 = 0 ;
V_85 -> V_91 -> V_83 = NULL ;
if ( V_85 -> V_91 -> V_282 )
{
if ( V_85 -> V_148 )
{
F_86 ( V_210 ) ;
F_100 ( V_85 -> V_148 ) ;
}
}
else
{
F_101 ( V_85 , 3 ) ;
}
F_8 ( L_18 , __LINE__ ) ;
V_85 -> V_91 -> V_87 &= ~ V_283 ;
F_46 ( & V_85 -> V_91 -> V_284 ) ;
V_278:
F_8 ( L_19 ) ;
F_73 ( V_85 ) ;
F_102 ( V_285 ) ;
}
static void F_98 ( struct V_82 * V_83 , int V_281 )
{
struct V_84 * V_85 = V_83 -> V_86 ;
struct V_12 * V_4 = V_85 -> V_4 ;
unsigned long V_286 , V_287 ;
if ( V_4 -> type == V_71 || V_4 -> V_145 == 0 )
return;
V_286 = ( V_4 -> V_281 - V_288 / 50 ) / V_4 -> V_145 ;
V_286 = V_286 / 5 ;
if ( V_286 == 0 )
V_286 = 1 ;
if ( V_281 && V_281 < V_286 )
V_286 = V_281 ;
if ( V_281 == 0 || V_281 > 2 * V_4 -> V_281 )
V_281 = 2 * V_4 -> V_281 ;
V_287 = V_289 + V_281 ;
while ( ! V_4 -> V_89 -> V_192 ( V_4 ) ) {
F_86 ( V_210 ) ;
F_100 ( V_286 ) ;
if ( F_88 ( V_189 ) )
break;
if ( F_103 ( V_289 , V_287 ) )
break;
}
F_86 ( V_219 ) ;
}
static void F_104 ( struct V_82 * V_83 )
{
struct V_84 * V_85 = V_83 -> V_86 ;
F_71 ( V_85 ) ;
if ( V_85 -> V_91 && V_85 -> V_91 -> V_87 & V_283 ) {
F_59 ( V_83 ) ;
F_44 ( V_85 ) ;
V_85 -> V_134 = 0 ;
V_85 -> V_91 -> V_87 &= ~ V_283 ;
V_85 -> V_91 -> V_83 = NULL ;
F_46 ( & V_85 -> V_91 -> V_284 ) ;
F_46 ( & V_85 -> V_91 -> V_118 ) ;
}
F_73 ( V_85 ) ;
}
static void F_105 ( struct V_84 * V_85 )
{
struct V_82 * V_83 = V_85 -> V_91 -> V_83 ;
struct V_12 * V_4 = V_85 -> V_4 ;
if ( ! ( V_83 -> V_87 & ( 1 << V_107 ) ) ) {
F_40 ( V_85 , NULL ) ;
if ( V_83 -> V_111 . V_112 & V_113 )
F_41 ( V_4 , V_115 | V_114 ) ;
}
}
static int F_106 ( struct V_276 * V_277 , struct V_84 * V_85 )
{
F_84 ( V_204 , V_189 ) ;
struct V_104 * V_91 = V_85 -> V_91 ;
struct V_12 * V_4 = V_85 -> V_4 ;
unsigned int V_101 ;
V_91 -> V_282 ++ ;
V_85 -> V_134 -- ;
F_85 ( & V_91 -> V_284 , & V_204 ) ;
while ( 1 ) {
F_86 ( V_210 ) ;
if ( F_97 ( V_277 ) || V_91 -> V_83 == NULL )
break;
if ( ! ( V_91 -> V_87 & V_106 ) )
break;
if ( ( V_277 -> V_290 & V_291 ) ||
( V_91 -> V_83 -> V_111 . V_112 & V_126 ) ||
( V_91 -> V_83 -> V_87 & ( 1 << V_107 ) ) ) {
break;
}
if ( V_91 -> V_83 -> V_111 . V_112 & V_113 )
F_41 ( V_4 , V_115 ) ;
F_77 ( & V_4 -> V_88 ) ;
V_4 -> V_89 -> V_209 ( V_4 ) ;
V_101 = V_4 -> V_89 -> V_195 ( V_4 ) ;
F_78 ( & V_4 -> V_88 ) ;
if ( V_101 & V_292 )
break;
F_73 ( V_85 ) ;
F_87 () ;
F_71 ( V_85 ) ;
if ( F_88 ( V_189 ) )
break;
}
F_86 ( V_219 ) ;
F_89 ( & V_91 -> V_284 , & V_204 ) ;
V_85 -> V_134 ++ ;
V_91 -> V_282 -- ;
if ( F_88 ( V_189 ) )
return - V_199 ;
if ( ! V_91 -> V_83 || F_97 ( V_277 ) )
return - V_293 ;
return 0 ;
}
static struct V_84 * F_107 ( struct V_294 * V_295 , int line )
{
struct V_84 * V_85 ;
F_108 ( V_296 ) ;
V_85 = V_295 -> V_85 + line ;
if ( F_82 ( & V_85 -> V_198 ) ) {
V_85 = F_109 ( - V_199 ) ;
goto V_267;
}
V_85 -> V_134 ++ ;
if ( ! V_85 -> V_4 ) {
V_85 -> V_134 -- ;
F_73 ( V_85 ) ;
V_85 = F_109 ( - V_297 ) ;
goto V_267;
}
if ( ! V_85 -> V_91 ) {
V_85 -> V_91 = F_110 ( sizeof( struct V_104 ) , V_108 ) ;
if ( V_85 -> V_91 ) {
memset ( V_85 -> V_91 , 0 , sizeof( struct V_104 ) ) ;
F_111 ( & V_85 -> V_91 -> V_284 ) ;
F_111 ( & V_85 -> V_91 -> V_118 ) ;
V_85 -> V_4 -> V_91 = V_85 -> V_91 ;
F_112 ( & V_85 -> V_91 -> V_121 , F_33 ,
( unsigned long ) V_85 ) ;
} else {
V_85 -> V_134 -- ;
F_73 ( V_85 ) ;
V_85 = F_109 ( - V_109 ) ;
}
}
V_267:
F_113 ( V_296 ) ;
return V_85 ;
}
static int F_114 ( struct V_82 * V_83 , struct V_276 * V_277 )
{
struct V_294 * V_295 = (struct V_294 * ) V_83 -> V_298 -> V_299 ;
struct V_84 * V_85 ;
int V_105 ;
int line = V_83 -> V_300 ;
struct V_1 * V_2 ;
V_105 = - V_301 ;
if ( line >= V_83 -> V_298 -> V_302 )
goto V_303;
V_85 = F_107 ( V_295 , line ) ;
if ( F_115 ( V_85 ) ) {
V_105 = F_116 ( V_85 ) ;
goto V_303;
}
V_2 = (struct V_1 * ) V_85 -> V_4 ;
V_83 -> V_86 = V_85 ;
V_83 -> V_185 = ( V_85 -> V_4 -> V_87 & V_186 ) ? 1 : 0 ;
V_83 -> V_304 = 0 ;
V_85 -> V_91 -> V_83 = V_83 ;
if ( F_97 ( V_277 ) ) {
V_105 = - V_293 ;
V_85 -> V_134 -- ;
F_73 ( V_85 ) ;
goto V_303;
}
if ( V_85 -> V_134 == 1 )
F_101 ( V_85 , 0 ) ;
V_105 = F_36 ( V_85 , 0 ) ;
if ( V_105 == 0 )
V_105 = F_106 ( V_277 , V_85 ) ;
F_73 ( V_85 ) ;
if ( V_105 == 0 && ! ( V_85 -> V_91 -> V_87 & V_283 ) ) {
V_85 -> V_91 -> V_87 |= V_283 ;
F_105 ( V_85 ) ;
}
F_45 ( V_85 -> V_4 , V_114 ) ;
F_117 ( V_285 ) ;
V_303:
return V_105 ;
}
static const char * F_118 ( struct V_12 * V_4 )
{
const char * V_305 = NULL ;
if ( V_4 -> V_89 -> type )
V_305 = V_4 -> V_89 -> type ( V_4 ) ;
if ( ! V_305 )
V_305 = L_20 ;
return V_305 ;
}
static void F_101 ( struct V_84 * V_85 , int V_306 )
{
struct V_12 * V_4 = V_85 -> V_4 ;
if ( V_4 -> V_89 -> V_307 )
V_4 -> V_89 -> V_307 ( V_4 , V_306 , V_85 -> V_306 ) ;
V_85 -> V_306 = V_306 ;
}
static inline void F_119 ( struct V_294 * V_295 , struct V_12 * V_4 )
{
char V_308 [ 64 ] ;
switch ( V_4 -> V_155 ) {
case V_309 :
snprintf ( V_308 , sizeof( V_308 ) , L_21 , V_4 -> V_5 ) ;
break;
case V_310 :
snprintf ( V_308 , sizeof( V_308 ) , L_22 , V_4 -> V_5 , V_4 -> V_153 ) ;
break;
case V_311 :
snprintf ( V_308 , sizeof( V_308 ) , L_23 , V_4 -> V_159 ) ;
break;
default:
snprintf ( V_308 , sizeof( V_308 ) , L_24 ) ;
F_120 ( V_308 , L_24 , sizeof( V_308 ) ) ;
break;
}
F_8 ( L_25 ,
V_295 -> V_312 , V_4 -> line , V_308 , V_4 -> V_120 , F_118 ( V_4 ) ) ;
}
static void F_121 ( struct V_294 * V_295 , struct V_84 * V_85 , struct V_12 * V_4 )
{
unsigned int V_87 ;
if ( ! V_4 -> V_5 && ! V_4 -> V_159 && ! V_4 -> V_313 )
{
F_122 ( L_26 , V_314 ) ;
return;
}
V_87 = V_200 ;
if ( V_4 -> V_87 & V_201 )
V_87 |= V_202 ;
if ( V_4 -> V_87 & V_315 ) {
V_4 -> type = V_71 ;
V_4 -> V_89 -> V_203 ( V_4 , V_87 ) ;
}
if ( V_4 -> type != V_71 ) {
unsigned long V_87 ;
F_119 ( V_295 , V_4 ) ;
F_28 ( & V_4 -> V_88 , V_87 ) ;
V_4 -> V_89 -> V_102 ( V_4 , 0 ) ;
F_29 ( & V_4 -> V_88 , V_87 ) ;
F_101 ( V_85 , 3 ) ;
}
}
static void F_123 ( struct V_294 * V_295 , struct V_84 * V_85 )
{
struct V_12 * V_4 = V_85 -> V_4 ;
struct V_104 * V_91 = V_85 -> V_91 ;
if ( V_91 && V_91 -> V_83 )
F_124 ( V_91 -> V_83 ) ;
F_71 ( V_85 ) ;
V_85 -> V_91 = NULL ;
if ( V_4 -> type != V_71 )
V_4 -> V_89 -> V_182 ( V_4 ) ;
V_4 -> type = V_71 ;
if ( V_91 ) {
F_48 ( & V_91 -> V_121 ) ;
F_125 ( V_91 ) ;
}
F_73 ( V_85 ) ;
}
static int F_126 ( struct V_294 * V_295 )
{
struct V_316 * V_317 = NULL ;
int V_42 , V_105 ;
V_295 -> V_85 = F_110 ( sizeof( struct V_84 ) * V_295 -> V_318 , V_108 ) ;
V_105 = - V_109 ;
if ( ! V_295 -> V_85 )
{
F_8 ( L_27 ) ;
goto V_267;
}
memset ( V_295 -> V_85 , 0 , sizeof( struct V_84 ) * V_295 -> V_318 ) ;
V_317 = F_127 ( V_295 -> V_318 ) ;
if ( ! V_317 )
{
F_8 ( L_28 ) ;
goto V_267;
}
V_295 -> V_316 = V_317 ;
V_317 -> V_319 = V_295 -> V_319 ;
V_317 -> V_320 = V_321 ;
V_317 -> V_322 = V_295 -> V_322 ;
V_317 -> V_323 = V_295 -> V_312 ;
V_317 -> V_324 = V_295 -> V_324 ;
V_317 -> V_325 = V_295 -> V_326 ;
V_317 -> V_302 = V_327 ;
V_317 -> type = V_328 ;
V_317 -> V_329 = V_330 ;
V_317 -> V_331 = V_332 ;
V_317 -> V_331 . V_112 = V_333 | V_334 | V_335 | V_117 | V_126 ;
V_317 -> V_87 = V_336 | V_337 ;
V_317 -> V_299 = V_295 ;
F_128 ( V_317 , & V_338 ) ;
for ( V_42 = 0 ; V_42 < V_295 -> V_318 ; V_42 ++ ) {
struct V_84 * V_85 = V_295 -> V_85 + V_42 ;
V_85 -> V_148 = 500 ;
V_85 -> V_149 = 30000 ;
F_129 ( & V_85 -> V_198 ) ;
}
V_105 = F_130 ( V_317 ) ;
V_267:
if ( V_105 < 0 ) {
F_8 ( L_29 ) ;
F_131 ( V_317 ) ;
F_125 ( V_295 -> V_85 ) ;
}
return V_105 ;
}
void F_132 ( struct V_294 * V_295 )
{
struct V_316 * V_317 = NULL ;
V_317 = V_295 -> V_316 ;
if ( ! V_317 )
{
return;
}
F_133 ( V_317 ) ;
F_131 ( V_317 ) ;
V_295 -> V_316 = NULL ;
if ( V_295 -> V_85 )
{
F_125 ( V_295 -> V_85 ) ;
}
}
static int F_134 ( struct V_294 * V_295 , struct V_12 * V_4 )
{
struct V_84 * V_85 ;
int V_15 = 0 ;
if ( V_4 -> line >= V_295 -> V_318 )
return - V_174 ;
V_85 = V_295 -> V_85 + V_4 -> line ;
F_108 ( V_296 ) ;
if ( V_85 -> V_4 ) {
V_15 = - V_174 ;
goto V_267;
}
V_85 -> V_4 = V_4 ;
F_135 ( & V_4 -> V_88 ) ;
V_4 -> V_339 = V_295 -> V_339 ;
V_4 -> V_91 = V_85 -> V_91 ;
F_121 ( V_295 , V_85 , V_4 ) ;
F_136 ( V_295 -> V_316 , V_4 -> line , V_4 -> V_340 ) ;
V_267:
F_113 ( V_296 ) ;
return V_15 ;
}
static int F_137 ( struct V_294 * V_295 , struct V_12 * V_4 )
{
struct V_84 * V_85 = V_295 -> V_85 + V_4 -> line ;
if ( V_85 -> V_4 != V_4 )
F_8 ( V_341 L_30 ,
V_85 -> V_4 , V_4 ) ;
F_108 ( V_296 ) ;
F_138 ( V_295 -> V_316 , V_4 -> line ) ;
F_123 ( V_295 , V_85 ) ;
V_85 -> V_4 = NULL ;
F_113 ( V_296 ) ;
return 0 ;
}
static void F_139 ( struct V_1 * V_2 , unsigned int V_342 )
{
unsigned char V_343 , V_344 , V_345 , V_346 ;
unsigned char V_347 , V_348 ;
unsigned long V_87 ;
unsigned char V_349 ;
unsigned char V_350 = 0 ;
if ( ! V_2 -> V_4 . V_5 && ! V_2 -> V_4 . V_159 && ! V_2 -> V_4 . V_313 )
return;
F_140 ( L_31 ,
V_2 -> V_4 . line , V_2 -> V_4 . V_5 , V_2 -> V_4 . V_313 ) ;
F_28 ( & V_2 -> V_4 . V_88 , V_87 ) ;
if ( ! ( V_2 -> V_4 . V_87 & V_351 ) ) {
V_344 = F_21 ( V_2 , V_352 ) ;
F_22 ( V_2 , V_352 , 0 ) ;
#ifdef F_141
F_4 ( 0xff , 0x080 ) ;
#endif
V_345 = F_21 ( V_2 , V_352 ) & 0x0f ;
F_22 ( V_2 , V_352 , 0x0F ) ;
#ifdef F_141
F_4 ( 0 , 0x080 ) ;
#endif
V_346 = F_21 ( V_2 , V_352 ) & 0x0F ;
F_22 ( V_2 , V_352 , V_344 ) ;
if ( V_345 != 0 || V_346 != 0x0F ) {
F_140 ( L_32 ,
V_345 , V_346 ) ;
goto V_267;
}
}
V_348 = F_1 ( V_2 , V_49 ) ;
V_347 = F_1 ( V_2 , V_44 ) ;
if ( ! ( V_2 -> V_4 . V_87 & V_353 ) ) {
F_22 ( V_2 , V_49 , V_354 | 0x0A ) ;
V_343 = F_21 ( V_2 , V_355 ) & 0xF0 ;
F_22 ( V_2 , V_49 , V_348 ) ;
if ( V_343 != 0x90 ) {
F_140 ( L_33 ,
V_343 ) ;
goto V_267;
}
}
F_22 ( V_2 , V_44 , 0xBF ) ;
F_22 ( V_2 , V_356 , 0 ) ;
F_22 ( V_2 , V_44 , 0 ) ;
F_22 ( V_2 , V_48 , V_357 ) ;
V_344 = F_1 ( V_2 , V_358 ) >> 6 ;
F_140 ( L_34 , V_344 ) ;
if( V_2 -> V_359 -> V_259 >= 8 )
V_350 = F_5 ( V_2 , ( V_64 + ( ( V_2 -> V_4 . line ) / 8 ) ) ) ;
else
V_350 = F_5 ( V_2 , V_64 ) ;
V_349 = ( V_350 & 0xf0 ) >> 4 ;
if( V_2 -> V_4 . type == V_71 )
{
switch ( V_349 )
{
case V_65 :
V_2 -> V_4 . type = V_66 ;
break;
case V_67 :
V_2 -> V_4 . type = V_68 ;
break;
case V_69 :
if ( V_2 -> V_4 . line < 2 )
{
V_2 -> V_4 . type = V_70 ;
}
else
{
if ( V_2 -> V_359 -> V_255 & 0x50 )
{
V_2 -> V_4 . type = V_66 ;
}
else
{
V_2 -> V_4 . type = V_68 ;
}
}
break;
default:
V_2 -> V_4 . type = V_71 ;
break;
}
}
if( V_2 -> V_4 . type == V_71 )
{
F_8 ( L_35 ) ;
switch ( V_344 ) {
case 0 :
case 1 :
V_2 -> V_4 . type = V_71 ;
break;
case 2 :
case 3 :
V_2 -> V_4 . type = V_66 ;
break;
}
}
F_22 ( V_2 , V_44 , V_347 ) ;
V_2 -> V_4 . V_145 = V_360 [ V_2 -> V_4 . type ] . V_361 ;
V_2 -> V_362 = V_360 [ V_2 -> V_4 . type ] . V_87 ;
if ( V_2 -> V_4 . type == V_71 )
goto V_267;
F_22 ( V_2 , V_49 , V_348 ) ;
F_22 ( V_2 , V_48 , ( V_357 |
V_363 |
V_364 ) ) ;
F_22 ( V_2 , V_48 , 0 ) ;
( void ) F_1 ( V_2 , V_365 ) ;
F_22 ( V_2 , V_352 , 0 ) ;
V_267:
F_29 ( & V_2 -> V_4 . V_88 , V_87 ) ;
F_140 ( L_36 , V_360 [ V_2 -> V_4 . type ] . V_323 ) ;
}
static void F_142 ( struct V_1 * V_2 )
{
unsigned char V_348 , V_366 ;
unsigned long V_367 ;
int V_120 ;
F_143 ( F_144 () ) ;
V_348 = F_21 ( V_2 , V_49 ) ;
V_366 = F_21 ( V_2 , V_352 ) ;
F_22 ( V_2 , V_49 , V_368 | V_369 ) ;
V_367 = F_144 () ;
F_22 ( V_2 , V_49 , 0 ) ;
F_22 ( V_2 , V_49 ,
V_370 | V_371 | V_369 ) ;
F_22 ( V_2 , V_352 , 0x0f ) ;
( void ) F_21 ( V_2 , V_50 ) ;
( void ) F_21 ( V_2 , V_365 ) ;
( void ) F_21 ( V_2 , V_358 ) ;
( void ) F_21 ( V_2 , V_355 ) ;
F_22 ( V_2 , V_372 , 0xFF ) ;
V_120 = F_143 ( V_367 ) ;
F_22 ( V_2 , V_49 , V_348 ) ;
F_22 ( V_2 , V_352 , V_366 ) ;
V_2 -> V_4 . V_120 = ( V_120 > 0 ) ? V_120 : 0 ;
}
static void F_145 ( struct V_12 * V_4 )
{
struct V_1 * V_2 = (struct V_1 * ) V_4 ;
if ( V_2 -> V_373 & V_374 ) {
V_2 -> V_373 &= ~ V_374 ;
F_3 ( V_2 , V_352 , V_2 -> V_373 ) ;
}
F_146 ( & V_4 -> V_91 -> V_121 ) ;
}
static void F_147 ( struct V_12 * V_4 )
{
struct V_1 * V_2 = (struct V_1 * ) V_4 ;
if ( ! ( V_2 -> V_373 & V_374 ) ) {
V_2 -> V_373 |= V_374 ;
F_3 ( V_2 , V_352 , V_2 -> V_373 ) ;
}
}
static void F_148 ( struct V_12 * V_4 )
{
struct V_1 * V_2 = (struct V_1 * ) V_4 ;
V_2 -> V_373 &= ~ V_375 ;
V_2 -> V_4 . V_376 &= ~ V_377 ;
F_3 ( V_2 , V_352 , V_2 -> V_373 ) ;
}
static void F_149 ( struct V_12 * V_4 )
{
struct V_1 * V_2 = (struct V_1 * ) V_4 ;
V_2 -> V_373 |= V_378 ;
F_3 ( V_2 , V_352 , V_2 -> V_373 ) ;
}
static T_1 void F_150 ( struct V_1 * V_2 , int * V_51 )
{
struct V_82 * V_83 = V_2 -> V_4 . V_91 -> V_83 ;
unsigned char V_379 = * V_51 ;
int V_380 = 256 ;
unsigned char V_40 ;
char V_381 ;
do {
if ( ( V_379 & V_382 ) && ( V_2 -> V_4 . V_37 & V_28 ) )
{
V_40 = F_21 ( V_2 , V_365 ) ;
}
else if ( V_379 & V_383 )
{
V_381 = 0 ;
V_40 = F_21 ( V_2 , V_365 ) ;
if ( V_379 & V_384 )
{
V_2 -> V_4 . V_208 . V_227 ++ ;
V_381 = V_385 ;
if ( F_151 ( & V_2 -> V_4 ) )
goto V_386;
}
if ( V_379 & V_382 )
{
V_2 -> V_4 . V_208 . V_226 ++ ;
V_381 = V_387 ;
}
if ( V_379 & V_388 )
{
V_2 -> V_4 . V_208 . V_224 ++ ;
V_381 = V_389 ;
}
if ( V_379 & V_390 )
{
V_2 -> V_4 . V_208 . V_225 ++ ;
V_381 = V_391 ;
}
F_152 ( V_83 , V_40 , V_381 ) ;
}
else
{
V_40 = F_21 ( V_2 , V_365 ) ;
F_152 ( V_83 , V_40 , 0 ) ;
}
V_386:
V_379 = F_21 ( V_2 , V_50 ) ;
} while ( ( V_379 & V_377 ) && ( V_380 -- > 0 ) );
F_153 ( V_83 ) ;
}
static T_1 void F_154 ( struct V_1 * V_2 )
{
struct V_129 * V_92 = & V_2 -> V_4 . V_91 -> V_92 ;
int V_134 ;
if ( V_2 -> V_4 . V_139 ) {
F_22 ( V_2 , V_372 , V_2 -> V_4 . V_139 ) ;
V_2 -> V_4 . V_208 . V_223 ++ ;
V_2 -> V_4 . V_139 = 0 ;
return;
}
if ( F_31 ( V_92 ) || F_155 ( & V_2 -> V_4 ) ) {
F_145 ( & V_2 -> V_4 ) ;
return;
}
V_134 = F_58 ( V_92 ) ;
if( V_134 > V_2 -> V_4 . V_145 )
{
V_134 = V_2 -> V_4 . V_145 ;
}
F_8 ( L_37 , V_2 -> V_4 . line , V_2 -> V_4 . V_37 ) ;
do {
#if 0
if ((mtpt->port.mdmode & (MDMODE_ENABLE | MDMODE_ADDR)) == (MDMODE_ENABLE | MDMODE_ADDR))
{
printk("send address\n");
serial_out(mtpt, UART_SCR, xmit->buf[xmit->tail]);
}
else
#endif
{
F_3 ( V_2 , V_372 , V_92 -> V_93 [ V_92 -> V_136 ] ) ;
}
V_92 -> V_136 = ( V_92 -> V_136 + 1 ) & ( V_133 - 1 ) ;
V_2 -> V_4 . V_208 . V_223 ++ ;
} while ( -- V_134 > 0 );
}
static T_1 void F_156 ( struct V_1 * V_2 )
{
int V_51 ;
V_51 = F_1 ( V_2 , V_355 ) ;
if ( ( V_51 & V_392 ) == 0 )
return;
if ( V_51 & V_393 )
V_2 -> V_4 . V_208 . V_212 ++ ;
if ( V_51 & V_394 )
V_2 -> V_4 . V_208 . V_214 ++ ;
if ( V_51 & V_395 )
F_157 ( & V_2 -> V_4 , V_51 & V_396 ) ;
if ( V_51 & V_397 )
F_158 ( & V_2 -> V_4 , V_51 & V_398 ) ;
F_46 ( & V_2 -> V_4 . V_91 -> V_118 ) ;
}
static inline void F_159 ( struct V_1 * V_2 )
{
unsigned int V_51 = F_21 ( V_2 , V_50 ) ;
if ( ( V_51 & V_377 ) || ( V_51 & V_383 ) )
F_150 ( V_2 , & V_51 ) ;
F_156 ( V_2 ) ;
if ( V_51 & V_399 )
{
if ( ( V_2 -> V_4 . type == V_68 )
|| ( V_2 -> V_4 . type == V_70 ) )
F_154 ( V_2 ) ;
else
{
if ( V_2 -> V_9 >= V_79 )
F_41 ( & V_2 -> V_4 , V_114 ) ;
F_154 ( V_2 ) ;
if ( V_2 -> V_9 >= V_79 )
{
while( ( V_51 = F_1 ( V_2 , V_50 ) & 0x60 ) != 0x60 ) ;
F_45 ( & V_2 -> V_4 , V_114 ) ;
}
}
}
}
static T_3 F_160 ( int V_120 , void * V_400 )
{
struct V_401 * V_402 = V_400 ;
struct V_403 * V_404 , * V_405 = NULL ;
int V_406 = 0 ;
F_161 ( & V_402 -> V_88 ) ;
V_404 = V_402 -> V_132 ;
do {
struct V_1 * V_2 ;
unsigned int V_407 ;
V_2 = F_162 ( V_404 , struct V_1 , V_408 ) ;
V_407 = F_1 ( V_2 , V_358 ) ;
F_8 ( L_38 , V_2 -> V_4 . line , V_407 ) ;
if ( ! ( V_407 & V_409 ) )
{
F_8 ( L_39 ) ;
F_161 ( & V_2 -> V_4 . V_88 ) ;
F_159 ( V_2 ) ;
F_163 ( & V_2 -> V_4 . V_88 ) ;
V_405 = NULL ;
} else if ( V_405 == NULL )
V_405 = V_404 ;
V_404 = V_404 -> V_410 ;
if ( V_404 == V_402 -> V_132 && V_406 ++ > V_411 )
{
F_8 ( V_412 L_40
L_41 , V_120 ) ;
F_8 ( L_40
L_41 , V_120 ) ;
break;
}
} while ( V_404 != V_405 );
F_163 ( & V_402 -> V_88 ) ;
return V_413 ;
}
static void F_164 ( struct V_401 * V_42 , struct V_1 * V_2 )
{
F_77 ( & V_42 -> V_88 ) ;
if ( ! F_165 ( V_42 -> V_132 ) ) {
if ( V_42 -> V_132 == & V_2 -> V_408 )
V_42 -> V_132 = V_42 -> V_132 -> V_410 ;
F_166 ( & V_2 -> V_408 ) ;
} else {
V_42 -> V_132 = NULL ;
}
F_78 ( & V_42 -> V_88 ) ;
}
static int F_167 ( struct V_1 * V_2 )
{
struct V_401 * V_42 = V_414 + V_2 -> V_4 . V_120 ;
int V_15 , V_415 = V_2 -> V_4 . V_87 & V_416 ? V_417 : 0 ;
F_77 ( & V_42 -> V_88 ) ;
if ( V_42 -> V_132 ) {
F_168 ( & V_2 -> V_408 , V_42 -> V_132 ) ;
F_78 ( & V_42 -> V_88 ) ;
V_15 = 0 ;
} else {
F_169 ( & V_2 -> V_408 ) ;
V_42 -> V_132 = & V_2 -> V_408 ;
F_78 ( & V_42 -> V_88 ) ;
V_15 = F_170 ( V_2 -> V_4 . V_120 , F_160 ,
V_415 , L_42 , V_42 ) ;
if ( V_15 < 0 )
F_164 ( V_42 , V_2 ) ;
}
return V_15 ;
}
static void F_171 ( struct V_1 * V_2 )
{
struct V_401 * V_42 = V_414 + V_2 -> V_4 . V_120 ;
if ( F_165 ( V_42 -> V_132 ) )
{
F_172 ( V_2 -> V_4 . V_120 , V_42 ) ;
}
F_164 ( V_42 , V_2 ) ;
}
static void F_173 ( unsigned long V_97 )
{
struct V_1 * V_2 = (struct V_1 * ) V_97 ;
F_161 ( & V_2 -> V_4 . V_88 ) ;
F_159 ( V_2 ) ;
F_163 ( & V_2 -> V_4 . V_88 ) ;
F_174 ( & V_2 -> V_418 , V_289 + 1 ) ;
}
static unsigned int F_175 ( struct V_12 * V_4 )
{
struct V_1 * V_2 = (struct V_1 * ) V_4 ;
unsigned long V_87 ;
unsigned int V_15 ;
F_28 ( & V_2 -> V_4 . V_88 , V_87 ) ;
V_15 = F_1 ( V_2 , V_50 ) & V_419 ? V_193 : 0 ;
F_29 ( & V_2 -> V_4 . V_88 , V_87 ) ;
return V_15 ;
}
static unsigned int F_176 ( struct V_12 * V_4 )
{
struct V_1 * V_2 = (struct V_1 * ) V_4 ;
unsigned char V_51 ;
unsigned int V_15 ;
V_51 = F_1 ( V_2 , V_355 ) ;
V_15 = 0 ;
if ( V_51 & V_396 )
V_15 |= V_292 ;
if ( V_51 & V_420 )
V_15 |= V_211 ;
if ( V_51 & V_421 )
V_15 |= V_213 ;
if ( V_51 & V_398 )
V_15 |= V_217 ;
return V_15 ;
}
static void F_177 ( struct V_12 * V_4 , unsigned int V_101 )
{
struct V_1 * V_2 = (struct V_1 * ) V_4 ;
unsigned char V_17 = 0 ;
V_101 &= 0xff ;
if ( V_101 & V_114 )
V_17 |= V_371 ;
if ( V_101 & V_115 )
V_17 |= V_370 ;
if ( V_101 & V_422 )
V_17 |= V_368 ;
if ( V_101 & V_423 )
V_17 |= V_369 ;
if ( V_101 & V_424 )
V_17 |= V_354 ;
F_3 ( V_2 , V_49 , V_17 ) ;
}
static void F_178 ( struct V_12 * V_4 , int V_196 )
{
struct V_1 * V_2 = (struct V_1 * ) V_4 ;
unsigned long V_87 ;
F_28 ( & V_2 -> V_4 . V_88 , V_87 ) ;
if ( V_196 == - 1 )
V_2 -> V_16 |= V_425 ;
else
V_2 -> V_16 &= ~ V_425 ;
F_3 ( V_2 , V_44 , V_2 -> V_16 ) ;
F_29 ( & V_2 -> V_4 . V_88 , V_87 ) ;
}
static int F_179 ( struct V_12 * V_4 )
{
struct V_1 * V_2 = (struct V_1 * ) V_4 ;
unsigned long V_87 ;
int V_105 ;
V_2 -> V_362 = V_360 [ V_2 -> V_4 . type ] . V_87 ;
V_2 -> V_17 = 0 ;
if ( V_2 -> V_362 & V_426 ) {
F_22 ( V_2 , V_48 , V_357 ) ;
F_22 ( V_2 , V_48 , V_357 |
V_363 | V_364 ) ;
F_22 ( V_2 , V_48 , 0 ) ;
}
( void ) F_21 ( V_2 , V_50 ) ;
( void ) F_21 ( V_2 , V_365 ) ;
( void ) F_21 ( V_2 , V_358 ) ;
( void ) F_21 ( V_2 , V_355 ) ;
F_22 ( V_2 , V_355 , 0 ) ;
if ( ! ( V_2 -> V_4 . V_87 & V_351 ) &&
( F_21 ( V_2 , V_50 ) == 0xff ) ) {
F_8 ( L_43 , V_2 -> V_4 . line ) ;
}
if ( ( ! F_180 ( V_2 -> V_4 . V_120 ) ) || ( V_2 -> V_427 == V_428 ) ) {
unsigned int V_281 = V_2 -> V_4 . V_281 ;
V_281 = V_281 > 6 ? ( V_281 / 2 - 2 ) : 1 ;
V_2 -> V_418 . V_97 = ( unsigned long ) V_2 ;
F_174 ( & V_2 -> V_418 , V_289 + V_281 ) ;
}
else
{
V_105 = F_167 ( V_2 ) ;
if ( V_105 )
return V_105 ;
}
F_22 ( V_2 , V_44 , V_429 ) ;
F_28 ( & V_2 -> V_4 . V_88 , V_87 ) ;
if ( ( F_180 ( V_2 -> V_4 . V_120 ) ) || ( V_2 -> V_427 == V_430 ) )
V_2 -> V_4 . V_101 |= V_423 ;
F_177 ( & V_2 -> V_4 , V_2 -> V_4 . V_101 ) ;
F_29 ( & V_2 -> V_4 . V_88 , V_87 ) ;
V_2 -> V_373 = V_375 | V_431 ;
F_22 ( V_2 , V_352 , V_2 -> V_373 ) ;
( void ) F_21 ( V_2 , V_50 ) ;
( void ) F_21 ( V_2 , V_365 ) ;
( void ) F_21 ( V_2 , V_358 ) ;
( void ) F_21 ( V_2 , V_355 ) ;
return 0 ;
}
static void F_181 ( struct V_12 * V_4 )
{
struct V_1 * V_2 = (struct V_1 * ) V_4 ;
unsigned long V_87 ;
V_2 -> V_373 = 0 ;
F_22 ( V_2 , V_352 , 0 ) ;
F_28 ( & V_2 -> V_4 . V_88 , V_87 ) ;
V_2 -> V_4 . V_101 &= ~ V_423 ;
F_177 ( & V_2 -> V_4 , V_2 -> V_4 . V_101 ) ;
F_29 ( & V_2 -> V_4 . V_88 , V_87 ) ;
F_3 ( V_2 , V_44 , F_21 ( V_2 , V_44 ) & ~ V_425 ) ;
F_22 ( V_2 , V_48 , V_357 |
V_363 |
V_364 ) ;
F_22 ( V_2 , V_48 , 0 ) ;
( void ) F_1 ( V_2 , V_365 ) ;
if ( ( ! F_180 ( V_2 -> V_4 . V_120 ) ) || ( V_2 -> V_427 == V_428 ) )
{
F_182 ( & V_2 -> V_418 ) ;
}
else
{
F_171 ( V_2 ) ;
}
}
static unsigned int F_183 ( struct V_12 * V_4 , unsigned int V_432 )
{
unsigned int V_433 ;
if ( ( V_4 -> V_87 & V_434 ) &&
V_432 == ( V_4 -> V_147 / 4 ) )
V_433 = 0x8001 ;
else if ( ( V_4 -> V_87 & V_434 ) &&
V_432 == ( V_4 -> V_147 / 8 ) )
V_433 = 0x8002 ;
else
V_433 = F_184 ( V_4 , V_432 ) ;
return V_433 ;
}
static void F_185 ( struct V_12 * V_4 , struct V_122 * V_111 , struct V_122 * V_100 )
{
struct V_1 * V_2 = (struct V_1 * ) V_4 ;
unsigned char V_435 , V_436 = 0 ;
unsigned long V_87 ;
unsigned int V_432 , V_433 ;
switch ( V_111 -> V_112 & V_437 ) {
case V_438 :
V_435 = 0x00 ;
break;
case V_439 :
V_435 = 0x01 ;
break;
case V_440 :
V_435 = 0x02 ;
break;
default:
case V_334 :
V_435 = 0x03 ;
break;
}
if ( V_111 -> V_112 & V_441 )
V_435 |= 0x04 ;
if ( V_111 -> V_112 & V_442 )
V_435 |= V_443 ;
if ( ! ( V_111 -> V_112 & V_444 ) )
V_435 |= V_445 ;
#ifdef F_186
if ( V_111 -> V_112 & F_186 )
V_435 |= V_446 ;
#endif
V_432 = F_187 ( V_4 , V_111 , V_100 , 0 , V_4 -> V_147 / 16 ) ;
V_433 = F_183 ( V_4 , V_432 ) ;
if ( V_2 -> V_362 & V_447 ) {
V_436 = V_448 [ V_2 -> V_4 . line ] ;
}
F_28 ( & V_2 -> V_4 . V_88 , V_87 ) ;
F_188 ( V_4 , V_111 -> V_112 , V_432 ) ;
V_2 -> V_4 . V_376 = V_390 | V_399 | V_377 ;
if ( V_111 -> V_273 & V_449 )
V_2 -> V_4 . V_376 |= V_388 | V_382 ;
if ( V_111 -> V_273 & ( V_450 | V_451 ) )
V_2 -> V_4 . V_376 |= V_384 ;
V_2 -> V_4 . V_452 = 0 ;
if ( V_111 -> V_273 & V_453 )
V_2 -> V_4 . V_452 |= V_382 | V_388 ;
if ( V_111 -> V_273 & V_454 ) {
V_2 -> V_4 . V_452 |= V_384 ;
if ( V_111 -> V_273 & V_453 )
V_2 -> V_4 . V_452 |= V_390 ;
}
if ( ( V_111 -> V_112 & V_335 ) == 0 )
V_2 -> V_4 . V_452 |= V_377 ;
V_2 -> V_373 &= ~ V_378 ;
if ( F_189 ( & V_2 -> V_4 , V_111 -> V_112 ) )
V_2 -> V_373 |= V_378 ;
F_3 ( V_2 , V_352 , V_2 -> V_373 ) ;
if ( V_2 -> V_362 & V_455 ) {
F_22 ( V_2 , V_44 , 0xBF ) ;
F_22 ( V_2 , V_356 ,
V_111 -> V_112 & V_124 ? V_456 : 0 ) ;
}
F_22 ( V_2 , V_44 , V_435 | V_45 ) ;
F_22 ( V_2 , V_46 , V_433 & 0xff ) ;
F_22 ( V_2 , V_47 , V_433 >> 8 ) ;
F_22 ( V_2 , V_44 , V_435 ) ;
V_2 -> V_16 = V_435 ;
if ( V_436 & V_357 ) {
F_22 ( V_2 , V_48 , V_357 ) ;
}
F_22 ( V_2 , V_48 , V_436 ) ;
if ( ( V_2 -> V_4 . type == V_68 )
|| ( V_2 -> V_4 . type == V_70 ) )
{
if( V_235 [ V_2 -> V_4 . line ] != 0 )
F_23 ( V_4 , V_55 ) ;
if ( V_2 -> V_9 != V_457 )
F_26 ( V_4 , V_2 -> V_9 ) ;
}
else
{
if ( V_2 -> V_9 >= V_79 )
{
F_45 ( & V_2 -> V_4 , V_114 ) ;
}
}
if( V_2 -> V_359 -> V_255 == V_458 )
{
F_20 ( V_2 ) ;
F_8 ( L_44 ) ;
}
F_177 ( & V_2 -> V_4 , V_2 -> V_4 . V_101 ) ;
F_29 ( & V_2 -> V_4 . V_88 , V_87 ) ;
}
static void F_190 ( struct V_12 * V_4 , unsigned int V_85 , unsigned int V_459 )
{
struct V_1 * V_2 = (struct V_1 * ) V_4 ;
if ( V_85 ) {
if ( V_2 -> V_362 & V_455 ) {
F_22 ( V_2 , V_44 , 0xBF ) ;
F_22 ( V_2 , V_356 , V_460 ) ;
F_22 ( V_2 , V_44 , 0 ) ;
F_22 ( V_2 , V_352 , V_461 ) ;
F_22 ( V_2 , V_44 , 0xBF ) ;
F_22 ( V_2 , V_356 , 0 ) ;
F_22 ( V_2 , V_44 , 0 ) ;
}
if ( V_2 -> V_307 )
V_2 -> V_307 ( V_4 , V_85 , V_459 ) ;
}
else
{
if ( V_2 -> V_362 & V_455 ) {
F_22 ( V_2 , V_44 , 0xBF ) ;
F_22 ( V_2 , V_356 , V_460 ) ;
F_22 ( V_2 , V_44 , 0 ) ;
F_22 ( V_2 , V_352 , 0 ) ;
F_22 ( V_2 , V_44 , 0xBF ) ;
F_22 ( V_2 , V_356 , 0 ) ;
F_22 ( V_2 , V_44 , 0 ) ;
}
if ( V_2 -> V_307 )
V_2 -> V_307 ( V_4 , V_85 , V_459 ) ;
}
}
static void F_191 ( struct V_1 * V_2 )
{
unsigned int V_462 = 8 << V_2 -> V_4 . V_157 ;
switch ( V_2 -> V_4 . V_155 ) {
case V_311 :
if ( ! V_2 -> V_4 . V_159 )
break;
if ( V_2 -> V_4 . V_87 & V_463 ) {
F_192 ( V_2 -> V_4 . V_313 ) ;
V_2 -> V_4 . V_313 = NULL ;
}
F_193 ( V_2 -> V_4 . V_159 , V_462 ) ;
break;
case V_310 :
case V_309 :
F_194 ( V_2 -> V_4 . V_5 , V_462 ) ;
break;
}
}
static void F_195 ( struct V_12 * V_4 )
{
}
static int F_196 ( struct V_12 * V_4 )
{
return 0 ;
}
static void F_197 ( struct V_12 * V_4 , int V_87 )
{
struct V_1 * V_2 = (struct V_1 * ) V_4 ;
int V_342 = V_464 ;
if ( V_87 & V_200 )
F_139 ( V_2 , V_342 ) ;
if ( V_2 -> V_4 . type != V_71 && V_87 & V_202 )
F_142 ( V_2 ) ;
if ( V_2 -> V_4 . type == V_71 )
F_191 ( V_2 ) ;
}
static int F_198 ( struct V_12 * V_4 , struct V_140 * V_465 )
{
if ( V_465 -> V_120 >= V_173 || V_465 -> V_120 < 0 ||
V_465 -> V_146 < 9600 || V_465 -> type < V_71 ||
V_465 -> type == V_466 )
return - V_174 ;
return 0 ;
}
static const char * F_199 ( struct V_12 * V_4 )
{
int type = V_4 -> type ;
if ( type >= F_200 ( V_360 ) )
type = 0 ;
return V_360 [ type ] . V_323 ;
}
static void T_4 F_201 ( void )
{
struct V_1 * V_2 ;
static int V_467 = 1 ;
int V_42 , V_468 , V_469 ;
unsigned char V_470 ;
unsigned char V_350 = 0 ;
static struct V_471 * V_472 ;
if ( ! V_467 )
return;
V_467 = 0 ;
V_2 = V_473 ;
for ( V_469 = 0 ; V_469 < V_261 ; V_469 ++ )
{
V_472 = & V_62 [ V_469 ] ;
for ( V_42 = 0 ; V_42 < V_472 -> V_259 ; V_42 ++ , V_2 ++ )
{
V_2 -> V_359 = V_472 ;
V_2 -> V_4 . V_5 = V_472 -> V_474 + 8 * V_42 ;
V_2 -> V_4 . V_120 = V_472 -> V_120 ;
if ( ( ( V_472 -> V_255 == V_475 ) && ( V_472 -> V_257 == 0x91 ) ) )
V_2 -> V_265 = V_472 -> V_63 + 0x08 + V_42 ;
else if ( V_472 -> V_257 == 0xc0 )
V_2 -> V_265 = V_472 -> V_63 + 0x08 + ( V_42 & 0x1 ) ;
else
V_2 -> V_265 = V_472 -> V_63 + 0x08 + V_42 / 8 ;
V_2 -> V_7 = V_472 -> V_63 ;
V_2 -> V_427 = V_472 -> V_427 ;
V_2 -> V_4 . V_147 = V_476 * 16 ;
V_470 = F_2 ( V_472 -> V_63 + V_64 + V_42 / 8 ) & 0x0F ;
if ( V_470 == 0x0f )
V_470 = 0 ;
for( V_468 = 0 ; V_468 < V_470 ; V_468 ++ )
V_2 -> V_4 . V_147 *= 2 ;
V_2 -> V_4 . V_87 |= V_477 | V_416 ;
V_2 -> V_4 . V_155 = V_309 ;
V_2 -> V_4 . V_89 = & V_478 ;
if ( V_472 -> V_257 == 0xc0 )
{
V_350 = F_6 ( V_2 , V_42 ) ;
}
else
{
V_350 = F_5 ( V_2 , ( V_11 + V_42 / 8 ) ) ;
F_8 ( L_45 , V_350 ) ;
}
V_2 -> V_9 = V_457 ;
if ( V_479 == ( V_350 & V_480 ) )
V_2 -> V_9 = V_74 ;
if ( V_481 == ( V_350 & V_480 ) )
V_2 -> V_9 = V_79 ;
}
}
}
static void T_4 F_202 ( struct V_294 * V_295 )
{
int V_42 ;
F_201 () ;
for ( V_42 = 0 ; V_42 < V_253 ; V_42 ++ ) {
struct V_1 * V_2 = & V_473 [ V_42 ] ;
V_2 -> V_4 . line = V_42 ;
V_2 -> V_4 . V_89 = & V_478 ;
F_203 ( & V_2 -> V_418 ) ;
V_2 -> V_418 . V_482 = F_173 ;
F_134 ( V_295 , & V_2 -> V_4 ) ;
}
}
static int F_204 ( struct V_483 * V_484 , unsigned int V_3 ,
unsigned int V_308 , unsigned int V_462 )
{
#if 0
struct resource *root;
unsigned index = (offset - 0x10) >> 2;
#endif
F_205 ( V_484 , V_3 , V_308 ) ;
#if 0
root = pcidev->resource[index].parent;
release_resource(&pcidev->resource[index]);
address &= ~0x1;
pcidev->resource[index].start = address;
pcidev->resource[index].end = address + size - 1;
if (request_resource(root, &pcidev->resource[index]) != NULL)
{
printk(KERN_ERR "pci remap conflict!! 0x%x\n", address);
return (-1);
}
#endif
return ( 0 ) ;
}
static int F_206 ( struct V_483 * V_484 , T_5 V_485 )
{
static struct V_471 * V_472 = V_62 ;
unsigned long V_39 = 0 ;
int V_468 ;
struct V_486 * V_15 = NULL ;
V_472 -> V_255 = V_485 . V_255 ;
F_207 ( V_484 , V_487 , & ( V_472 -> V_257 ) ) ;
V_472 -> V_323 = V_485 . V_323 ;
V_472 -> V_474 = V_484 -> V_486 [ 0 ] . V_488 & V_489 ;
if ( V_472 -> V_257 == 0xc0 )
{
V_472 -> V_63 = V_484 -> V_486 [ 4 ] . V_488 & V_489 ;
}
else
{
V_472 -> V_63 = V_484 -> V_486 [ 1 ] . V_488 & V_489 ;
}
#if 1
if ( V_472 -> V_257 == 0xc0 )
{
F_4 ( 0x00 , V_472 -> V_63 + V_490 ) ;
F_2 ( V_472 -> V_63 + V_490 ) ;
F_4 ( 0x83 , V_472 -> V_63 + V_490 ) ;
}
#endif
V_472 -> V_120 = V_484 -> V_120 ;
if ( ( V_485 . V_255 & 0x0800 ) || ! ( V_485 . V_255 & 0xff00 ) )
{
V_472 -> V_427 = V_430 ;
}
else
{
V_472 -> V_427 = V_428 ;
}
switch( V_485 . V_255 ) {
case V_491 :
case V_492 :
case V_493 :
case V_494 :
V_472 -> V_259 = 1 ;
break;
case V_495 :
case V_496 :
case V_497 :
case V_498 :
case V_499 :
V_472 -> V_259 = 2 ;
if ( V_472 -> V_257 == 0xc0 )
{
int V_500 = 0 ;
F_208 ( V_484 , V_501 , & V_500 ) ;
F_204 ( V_484 , V_502 , V_500 + 8 , 8 ) ;
}
break;
case V_475 :
case V_503 :
case V_504 :
case V_505 :
case V_506 :
case V_507 :
case V_458 :
case V_508 :
V_472 -> V_259 = 4 ;
if( V_472 -> V_257 == 0x91 ) {
V_472 -> V_509 [ 0 ] = V_484 -> V_486 [ 0 ] . V_488 & V_489 ;
F_4 ( 0x03 , V_472 -> V_509 [ 0 ] + 0x01 ) ;
F_4 ( 0x03 , V_472 -> V_509 [ 0 ] + 0x02 ) ;
F_4 ( 0x01 , V_472 -> V_509 [ 0 ] + 0x20 ) ;
F_4 ( 0x00 , V_472 -> V_509 [ 0 ] + 0x21 ) ;
F_209 ( V_472 -> V_509 [ 0 ] , 32 , V_472 -> V_323 ) ;
V_472 -> V_474 = V_484 -> V_486 [ 1 ] . V_488 & V_489 ;
V_472 -> V_63 = V_484 -> V_486 [ 2 ] . V_488 & V_489 ;
}
if ( V_472 -> V_257 == 0xc0 )
{
int V_500 = 0 ;
F_208 ( V_484 , V_501 , & V_500 ) ;
F_204 ( V_484 , V_502 , V_500 + 8 , 8 ) ;
F_204 ( V_484 , V_510 , V_500 + 16 , 8 ) ;
F_204 ( V_484 , V_511 , V_500 + 24 , 8 ) ;
}
break;
case V_512 :
case V_513 :
case V_514 :
case V_515 :
V_472 -> V_259 = 6 ;
if ( V_472 -> V_257 == 0xc0 )
{
int V_500 = 0 ;
F_208 ( V_484 , V_501 , & V_500 ) ;
F_204 ( V_484 , V_502 , V_500 + 8 , 8 ) ;
F_204 ( V_484 , V_510 , V_500 + 16 , 16 ) ;
F_204 ( V_484 , V_511 , V_500 + 32 , 16 ) ;
}
break;
case V_516 :
case V_517 :
case V_518 :
case V_519 :
case V_520 :
V_472 -> V_259 = 8 ;
break;
case V_521 :
case V_522 :
case V_523 :
case V_524 :
{
int V_525 = 0 ;
V_525 = F_2 ( V_472 -> V_63 ) ;
V_472 -> V_259 = ( ( V_525 / 16 ) * 10 ) + ( V_525 % 16 ) ;
}
break;
#ifdef F_210
case V_526 :
V_472 -> V_259 = 2 ;
if ( V_472 -> V_257 == 0xc0 )
{
int V_500 = 0 ;
F_208 ( V_484 , V_501 , & V_500 ) ;
F_204 ( V_484 , V_502 , V_500 + 8 , 8 ) ;
}
F_211 ( V_484 -> V_486 [ 2 ] . V_488 , V_484 -> V_486 [ 3 ] . V_488 , V_527 , V_528 , & V_484 -> V_340 , 0 ) ;
break;
case V_529 :
F_211 ( V_484 -> V_486 [ 2 ] . V_488 , V_484 -> V_486 [ 3 ] . V_488 , V_527 , V_528 , & V_484 -> V_340 , 0 ) ;
break;
#endif
}
V_15 = F_209 ( V_472 -> V_474 , ( 8 * V_472 -> V_259 ) , V_472 -> V_323 ) ;
if ( V_472 -> V_257 == 0xc0 )
{
V_15 = F_209 ( V_472 -> V_63 , 0x40 , V_472 -> V_323 ) ;
}
else
{
V_15 = F_209 ( V_472 -> V_63 , 0x20 , V_472 -> V_323 ) ;
}
V_261 ++ ;
V_253 += V_472 -> V_259 ;
V_39 = V_472 -> V_63 + V_530 ;
for( V_468 = 0 ; V_468 < ( V_472 -> V_259 / 8 ) + 1 ; V_468 ++ )
{
if ( V_472 -> V_427 == V_430 )
{
F_4 ( 0xff , V_39 + V_468 ) ;
}
}
V_472 ++ ;
return 0 ;
}
static int T_4 F_212 ( void )
{
int V_15 , V_42 ;
struct V_483 * V_340 = NULL ;
if( V_531 == 0 )
{
for( V_42 = 0 ; V_42 < 256 ; V_42 ++ )
{
V_448 [ V_42 ] = 0x01 ;
}
}
if( V_532 == 0 )
{
for( V_42 = 0 ; V_42 < 256 ; V_42 ++ )
{
V_235 [ V_42 ] = 1 ;
}
}
if( V_533 == 0 )
{
for( V_42 = 0 ; V_42 < 256 ; V_42 ++ )
{
V_60 [ V_42 ] = 0x10 ;
}
}
if( V_534 == 0 )
{
for( V_42 = 0 ; V_42 < 256 ; V_42 ++ )
{
V_58 [ V_42 ] = 0x38 ;
}
}
F_8 ( L_46 ) ;
for( V_42 = 0 ; V_42 < V_535 ; V_42 ++ )
{
while( ( V_340 = F_213 ( V_536 [ V_42 ] . V_537 , V_536 [ V_42 ] . V_255 , V_340 ) ) )
{
F_8 ( L_47 ) ;
{
int V_51 ;
F_214 ( V_340 ) ;
V_51 = F_215 ( V_340 ) ;
if ( V_51 != 0 )
{
F_8 ( L_48 ) ;
V_51 = - V_297 ;
return V_51 ;
}
}
F_206 ( V_340 , V_536 [ V_42 ] ) ;
}
}
for ( V_42 = 0 ; V_42 < V_173 ; V_42 ++ )
F_135 ( & V_414 [ V_42 ] . V_88 ) ;
V_15 = F_126 ( & V_538 ) ;
if ( V_15 >= 0 )
F_202 ( & V_538 ) ;
return V_15 ;
}
static void T_6 F_216 ( void )
{
int V_42 ;
for ( V_42 = 0 ; V_42 < V_253 ; V_42 ++ )
F_137 ( & V_538 , & V_473 [ V_42 ] . V_4 ) ;
F_132 ( & V_538 ) ;
}
