static unsigned int F_1 ( struct V_1 * V_2 ,
unsigned int V_3 ,
unsigned int V_4 )
{
unsigned long V_5 ;
unsigned int V_6 , V_7 ;
V_6 = ( V_3 << 16 ) | V_4 ;
F_2 ( & V_2 -> V_8 , V_5 ) ;
F_3 ( V_6 , V_2 -> V_9 + V_10 ) ;
V_7 = F_4 ( V_2 -> V_9 + V_11 ) ;
F_5 ( & V_2 -> V_8 , V_5 ) ;
return V_7 ;
}
static void F_6 ( struct V_1 * V_2 ,
unsigned int V_3 ,
unsigned int V_4 ,
unsigned int V_12 )
{
unsigned int V_6 ;
unsigned long V_5 ;
V_6 = ( V_3 << 16 ) | V_4 ;
F_2 ( & V_2 -> V_8 , V_5 ) ;
F_3 ( V_6 , V_2 -> V_9 + V_10 ) ;
F_3 ( V_12 , V_2 -> V_9 + V_11 ) ;
F_5 ( & V_2 -> V_8 , V_5 ) ;
}
static void F_7 ( struct V_1 * V_2 , unsigned int V_13 )
{
unsigned long V_5 ;
unsigned int V_14 ;
F_2 ( & V_2 -> V_8 , V_5 ) ;
V_14 = F_4 ( V_2 -> V_9 + V_15 ) | V_13 ;
F_3 ( V_14 , V_2 -> V_9 + V_15 ) ;
F_5 ( & V_2 -> V_8 , V_5 ) ;
}
static void F_8 ( struct V_1 * V_2 , unsigned int V_13 )
{
unsigned long V_5 ;
unsigned int V_14 ;
F_2 ( & V_2 -> V_8 , V_5 ) ;
V_14 = F_4 ( V_2 -> V_9 + V_15 ) & ~ V_13 ;
F_3 ( V_14 , V_2 -> V_9 + V_15 ) ;
F_5 ( & V_2 -> V_8 , V_5 ) ;
}
static void F_9 ( struct V_1 * V_2 , unsigned int V_16 )
{
unsigned long V_5 ;
F_2 ( & V_2 -> V_8 , V_5 ) ;
F_3 ( V_16 , V_2 -> V_9 + V_17 ) ;
F_5 ( & V_2 -> V_8 , V_5 ) ;
}
static void F_10 ( struct V_18 * V_19 )
{
F_11 ( V_19 -> V_20 ) ;
}
static void F_12 ( struct V_1 * V_2 , struct V_21 * V_22 )
{
struct V_23 * V_24 ;
if ( ( V_24 = V_22 -> V_24 ) == NULL )
return;
if ( V_24 -> V_25 == NULL )
return;
#if 0
dev_info(emu->card->dev,
"IRQ: position = 0x%x, period = 0x%x, size = 0x%x\n",
epcm->substream->ops->pointer(epcm->substream),
snd_pcm_lib_period_bytes(epcm->substream),
snd_pcm_lib_buffer_bytes(epcm->substream));
#endif
F_13 ( V_24 -> V_25 ) ;
}
static int F_14 ( struct V_26 * V_25 )
{
struct V_1 * V_27 = F_15 ( V_25 ) ;
struct V_23 * V_24 ;
struct V_18 * V_19 = V_25 -> V_19 ;
int V_28 ;
if ( ( V_28 = F_16 ( V_19 , V_29 ) ) < 0 ) {
return V_28 ;
}
if ( ( V_28 = F_17 ( V_19 , 0 , V_30 , 64 ) ) < 0 )
return V_28 ;
V_24 = F_18 ( sizeof( * V_24 ) , V_31 ) ;
if ( V_24 == NULL )
return - V_32 ;
V_24 -> V_2 = V_27 ;
V_24 -> V_25 = V_25 ;
V_19 -> V_20 = V_24 ;
V_19 -> V_33 = F_10 ;
V_19 -> V_34 = V_35 ;
return 0 ;
}
static int F_19 ( struct V_26 * V_25 )
{
return 0 ;
}
static int F_20 ( struct V_26 * V_25 ,
struct V_36 * V_37 )
{
struct V_18 * V_19 = V_25 -> V_19 ;
struct V_23 * V_24 = V_19 -> V_20 ;
if ( ! V_24 -> V_22 ) {
V_24 -> V_22 = & V_24 -> V_2 -> V_38 [ V_25 -> V_39 -> V_40 ] ;
V_24 -> V_22 -> V_41 = 1 ;
V_24 -> V_22 -> V_24 = V_24 ;
}
return F_21 ( V_25 ,
F_22 ( V_37 ) ) ;
}
static int F_23 ( struct V_26 * V_25 )
{
struct V_18 * V_19 = V_25 -> V_19 ;
struct V_23 * V_24 ;
if ( V_19 -> V_20 == NULL )
return 0 ;
V_24 = V_19 -> V_20 ;
if ( V_24 -> V_22 ) {
V_24 -> V_22 -> V_41 = 0 ;
V_24 -> V_22 -> V_24 = NULL ;
V_24 -> V_22 = NULL ;
}
return F_24 ( V_25 ) ;
}
static int F_25 ( struct V_26 * V_25 )
{
struct V_1 * V_2 = F_15 ( V_25 ) ;
struct V_18 * V_19 = V_25 -> V_19 ;
struct V_23 * V_24 = V_19 -> V_20 ;
int V_22 = V_24 -> V_22 -> V_42 ;
T_1 * V_43 = ( T_1 * ) ( V_2 -> V_44 . V_45 + 1024 * V_22 ) ;
T_1 V_46 = F_26 ( V_19 , V_19 -> V_47 ) ;
int V_48 ;
for( V_48 = 0 ; V_48 < V_19 -> V_49 ; V_48 ++ ) {
* V_43 ++ = V_19 -> V_50 + ( V_48 * V_46 ) ;
* V_43 ++ = V_46 << 16 ;
}
F_6 ( V_2 , V_51 , V_22 , V_2 -> V_44 . V_52 + 1024 * V_22 ) ;
F_6 ( V_2 , V_53 , V_22 , ( V_19 -> V_49 - 1 ) << 19 ) ;
F_6 ( V_2 , V_54 , V_22 , 0 ) ;
F_6 ( V_2 , V_55 , V_22 , 0 ) ;
F_6 ( V_2 , V_56 , V_22 , 0 ) ;
F_6 ( V_2 , V_57 , V_22 , 0 ) ;
F_6 ( V_2 , V_58 , V_22 , V_19 -> V_50 ) ;
F_6 ( V_2 , V_59 , V_22 , F_26 ( V_19 , V_19 -> V_47 ) << 16 ) ;
return 0 ;
}
static int F_27 ( struct V_26 * V_25 ,
int V_60 )
{
struct V_1 * V_2 = F_15 ( V_25 ) ;
struct V_18 * V_19 = V_25 -> V_19 ;
struct V_23 * V_24 = V_19 -> V_20 ;
int V_61 = V_24 -> V_22 -> V_42 ;
int V_62 = 0 ;
switch ( V_60 ) {
case V_63 :
if( V_19 -> V_49 == 2 )
F_7 ( V_2 , ( V_64 | V_65 ) << V_61 ) ;
else
F_7 ( V_2 , V_64 << V_61 ) ;
V_24 -> V_66 = 1 ;
F_6 ( V_2 , V_67 , 0 , F_1 ( V_2 , V_67 , 0 ) | ( V_68 << V_61 ) ) ;
break;
case V_69 :
V_24 -> V_66 = 0 ;
F_8 ( V_2 , ( V_64 | V_65 ) << V_61 ) ;
F_6 ( V_2 , V_67 , 0 , F_1 ( V_2 , V_67 , 0 ) & ~ ( V_68 << V_61 ) ) ;
break;
default:
V_62 = - V_70 ;
break;
}
return V_62 ;
}
static T_2
F_28 ( struct V_26 * V_25 )
{
struct V_1 * V_2 = F_15 ( V_25 ) ;
struct V_18 * V_19 = V_25 -> V_19 ;
struct V_23 * V_24 = V_19 -> V_20 ;
int V_61 = V_24 -> V_22 -> V_42 ;
T_2 V_71 = 0 , V_72 = 0 , V_73 = 0 , V_74 = 0 , V_75 = 0 ;
if ( ! V_24 -> V_66 )
return 0 ;
V_74 = F_1 ( V_2 , V_54 , V_61 ) ;
V_72 = F_1 ( V_2 , V_55 , V_61 ) ;
V_75 = F_1 ( V_2 , V_54 , V_61 ) ;
if( V_75 == 0 && V_72 == F_26 ( V_19 , V_19 -> V_76 ) )
return 0 ;
if ( V_74 != V_75 )
V_72 = F_1 ( V_2 , V_55 , V_61 ) ;
V_73 = F_29 ( V_19 , V_72 ) ;
V_73 += ( V_75 >> 3 ) * V_19 -> V_47 ;
V_71 = V_73 ;
if ( V_71 >= V_19 -> V_76 )
V_71 -= V_19 -> V_76 ;
return V_71 ;
}
static int F_30 ( struct V_26 * V_25 )
{
struct V_1 * V_27 = F_15 ( V_25 ) ;
struct V_23 * V_24 ;
struct V_18 * V_19 = V_25 -> V_19 ;
int V_28 ;
if ( ( V_28 = F_16 ( V_19 , V_29 ) ) < 0 )
return V_28 ;
if ( ( V_28 = F_17 ( V_19 , 0 , V_30 , 64 ) ) < 0 )
return V_28 ;
V_24 = F_18 ( sizeof( * V_24 ) , V_31 ) ;
if ( V_24 == NULL )
return - V_32 ;
V_24 -> V_2 = V_27 ;
V_24 -> V_25 = V_25 ;
V_19 -> V_20 = V_24 ;
V_19 -> V_33 = F_10 ;
V_19 -> V_34 = V_77 ;
return 0 ;
}
static int F_31 ( struct V_26 * V_25 )
{
return 0 ;
}
static int F_32 ( struct V_26 * V_25 ,
struct V_36 * V_37 )
{
struct V_18 * V_19 = V_25 -> V_19 ;
struct V_23 * V_24 = V_19 -> V_20 ;
if ( ! V_24 -> V_22 ) {
if ( V_24 -> V_2 -> V_78 . V_41 )
return - V_79 ;
V_24 -> V_22 = & V_24 -> V_2 -> V_78 ;
V_24 -> V_22 -> V_24 = V_24 ;
V_24 -> V_22 -> V_41 = 1 ;
}
return F_21 ( V_25 ,
F_22 ( V_37 ) ) ;
}
static int F_33 ( struct V_26 * V_25 )
{
struct V_18 * V_19 = V_25 -> V_19 ;
struct V_23 * V_24 ;
if ( V_19 -> V_20 == NULL )
return 0 ;
V_24 = V_19 -> V_20 ;
if ( V_24 -> V_22 ) {
V_24 -> V_22 -> V_41 = 0 ;
V_24 -> V_22 -> V_24 = NULL ;
V_24 -> V_22 = NULL ;
}
return F_24 ( V_25 ) ;
}
static int F_34 ( struct V_26 * V_25 )
{
struct V_1 * V_2 = F_15 ( V_25 ) ;
struct V_18 * V_19 = V_25 -> V_19 ;
F_6 ( V_2 , V_80 , 0 , V_19 -> V_50 ) ;
F_6 ( V_2 , V_81 , 0 , F_26 ( V_19 , V_19 -> V_76 ) << 16 ) ;
F_6 ( V_2 , V_82 , 0 , 0 ) ;
F_6 ( V_2 , V_83 , 0 , 0 ) ;
return 0 ;
}
static int F_35 ( struct V_26 * V_25 ,
int V_60 )
{
struct V_1 * V_2 = F_15 ( V_25 ) ;
struct V_18 * V_19 = V_25 -> V_19 ;
struct V_23 * V_24 = V_19 -> V_20 ;
int V_62 = 0 ;
switch ( V_60 ) {
case V_63 :
F_7 ( V_2 , V_84 |
V_85 ) ;
F_6 ( V_2 , V_67 , 0 , F_1 ( V_2 , V_67 , 0 ) | V_86 ) ;
V_24 -> V_66 = 1 ;
break;
case V_69 :
V_24 -> V_66 = 0 ;
F_8 ( V_2 , V_84 |
V_85 ) ;
F_6 ( V_2 , V_67 , 0 , F_1 ( V_2 , V_67 , 0 ) & ~ ( V_86 ) ) ;
break;
default:
V_62 = - V_70 ;
break;
}
return V_62 ;
}
static T_2
F_36 ( struct V_26 * V_25 )
{
struct V_1 * V_2 = F_15 ( V_25 ) ;
struct V_18 * V_19 = V_25 -> V_19 ;
struct V_23 * V_24 = V_19 -> V_20 ;
T_2 V_71 ;
if ( ! V_24 -> V_66 )
return 0 ;
V_71 = F_29 ( V_19 , F_1 ( V_2 , V_82 , 0 ) ) ;
if ( V_71 >= V_19 -> V_76 )
V_71 -= V_19 -> V_76 ;
return V_71 ;
}
static unsigned short F_37 ( struct V_87 * V_88 ,
unsigned short V_3 )
{
struct V_1 * V_2 = V_88 -> V_20 ;
unsigned long V_5 ;
unsigned short V_7 ;
F_2 ( & V_2 -> V_8 , V_5 ) ;
F_38 ( V_3 , V_2 -> V_9 + V_89 ) ;
V_7 = F_39 ( V_2 -> V_9 + V_90 ) ;
F_5 ( & V_2 -> V_8 , V_5 ) ;
return V_7 ;
}
static void F_40 ( struct V_87 * V_88 ,
unsigned short V_3 , unsigned short V_7 )
{
struct V_1 * V_2 = V_88 -> V_20 ;
unsigned long V_5 ;
F_2 ( & V_2 -> V_8 , V_5 ) ;
F_38 ( V_3 , V_2 -> V_9 + V_89 ) ;
F_41 ( V_7 , V_2 -> V_9 + V_90 ) ;
F_5 ( & V_2 -> V_8 , V_5 ) ;
}
static int F_42 ( struct V_1 * V_27 )
{
struct V_91 * V_92 ;
struct V_93 V_88 ;
int V_28 ;
static struct V_94 V_95 = {
. V_96 = F_40 ,
. V_97 = F_37 ,
} ;
if ( ( V_28 = V_91 ( V_27 -> V_98 , 0 , & V_95 , NULL , & V_92 ) ) < 0 )
return V_28 ;
V_92 -> V_99 = 1 ;
memset ( & V_88 , 0 , sizeof( V_88 ) ) ;
V_88 . V_20 = V_27 ;
V_88 . V_100 = V_101 ;
return F_43 ( V_92 , & V_88 , & V_27 -> V_88 ) ;
}
static int F_44 ( struct V_1 * V_27 )
{
F_6 ( V_27 , V_67 , 0 , 0 ) ;
F_3 ( 0 , V_27 -> V_9 + V_15 ) ;
F_3 ( V_102 , V_27 -> V_9 + V_103 ) ;
if ( V_27 -> V_104 >= 0 )
F_45 ( V_27 -> V_104 , V_27 ) ;
F_46 ( V_27 -> V_105 ) ;
if ( V_27 -> V_44 . V_45 ) {
F_47 ( & V_27 -> V_44 ) ;
}
F_48 ( V_27 -> V_106 ) ;
F_11 ( V_27 ) ;
return 0 ;
}
static int F_49 ( struct V_107 * V_40 )
{
struct V_1 * V_27 = V_40 -> V_108 ;
return F_44 ( V_27 ) ;
}
static T_3 F_50 ( int V_104 , void * V_109 )
{
unsigned int V_110 ;
struct V_1 * V_27 = V_109 ;
struct V_21 * V_111 = V_27 -> V_38 ;
int V_48 ;
int V_112 ;
V_110 = F_4 ( V_27 -> V_9 + V_113 ) ;
if ( ! V_110 )
return V_114 ;
if ( V_110 & ( V_115 | V_116 ) ) {
struct V_21 * V_117 = & V_27 -> V_78 ;
if ( V_117 -> V_41 )
F_12 ( V_27 , V_117 ) ;
else
F_8 ( V_27 ,
V_84 |
V_85 ) ;
}
V_112 = V_118 | V_119 ;
for ( V_48 = 0 ; V_48 < 3 ; V_48 ++ ) {
if ( V_110 & V_112 ) {
if ( V_111 -> V_41 )
F_12 ( V_27 , V_111 ) ;
else
F_8 ( V_27 , V_112 ) ;
}
V_111 ++ ;
V_112 <<= 1 ;
}
if ( V_110 & ( V_120 | V_121 ) ) {
if ( V_27 -> V_122 . V_123 )
V_27 -> V_122 . V_123 ( V_27 , V_110 ) ;
else
F_8 ( V_27 , V_124 | V_125 ) ;
}
F_3 ( V_110 , V_27 -> V_9 + V_113 ) ;
return V_126 ;
}
static int F_51 ( struct V_1 * V_2 , int V_40 )
{
struct V_127 * V_39 ;
const struct V_128 * V_129 = NULL ;
int V_28 ;
int V_130 = 0 ;
if ( V_40 == 0 )
V_130 = 1 ;
if ( ( V_28 = F_52 ( V_2 -> V_98 , L_1 , V_40 , 1 , V_130 , & V_39 ) ) < 0 )
return V_28 ;
V_39 -> V_20 = V_2 ;
switch( V_40 ) {
case 0 :
F_53 ( V_39 , V_131 , & V_132 ) ;
F_53 ( V_39 , V_133 , & V_134 ) ;
break;
case 1 :
case 2 :
F_53 ( V_39 , V_131 , & V_132 ) ;
break;
}
V_39 -> V_135 = 0 ;
switch( V_40 ) {
case 0 :
strcpy ( V_39 -> V_136 , L_2 ) ;
V_129 = V_137 ;
break;
case 1 :
strcpy ( V_39 -> V_136 , L_3 ) ;
V_129 = V_138 ;
break;
case 2 :
strcpy ( V_39 -> V_136 , L_4 ) ;
V_129 = V_139 ;
break;
}
V_2 -> V_39 = V_39 ;
F_54 ( V_39 , V_140 ,
F_55 ( V_2 -> V_106 ) ,
32 * 1024 , 32 * 1024 ) ;
return F_56 ( V_39 , V_131 , V_129 , 2 ,
1 << 2 , NULL ) ;
}
static int F_57 ( struct V_141 * V_98 ,
struct V_142 * V_106 ,
struct V_1 * * V_143 )
{
struct V_1 * V_27 ;
int V_28 ;
int V_144 ;
static struct V_145 V_95 = {
. V_146 = F_49 ,
} ;
* V_143 = NULL ;
if ( ( V_28 = F_58 ( V_106 ) ) < 0 )
return V_28 ;
if ( F_59 ( V_106 , F_60 ( 28 ) ) < 0 ||
F_61 ( V_106 , F_60 ( 28 ) ) < 0 ) {
F_62 ( V_98 -> V_147 , L_5 ) ;
F_48 ( V_106 ) ;
return - V_148 ;
}
V_27 = F_18 ( sizeof( * V_27 ) , V_31 ) ;
if ( V_27 == NULL ) {
F_48 ( V_106 ) ;
return - V_32 ;
}
V_27 -> V_98 = V_98 ;
V_27 -> V_106 = V_106 ;
V_27 -> V_104 = - 1 ;
F_63 ( & V_27 -> V_8 ) ;
F_63 ( & V_27 -> V_149 ) ;
V_27 -> V_9 = F_64 ( V_106 , 0 ) ;
if ( ( V_27 -> V_105 = F_65 ( V_27 -> V_9 , 8 ,
L_6 ) ) == NULL ) {
F_62 ( V_98 -> V_147 , L_7 ,
V_27 -> V_9 ) ;
F_44 ( V_27 ) ;
return - V_79 ;
}
if ( F_66 ( V_106 -> V_104 , F_50 ,
V_150 , V_151 , V_27 ) ) {
F_62 ( V_98 -> V_147 , L_8 , V_106 -> V_104 ) ;
F_44 ( V_27 ) ;
return - V_79 ;
}
V_27 -> V_104 = V_106 -> V_104 ;
if( F_67 ( V_140 , F_55 ( V_106 ) ,
4 * 1024 , & V_27 -> V_44 ) < 0 ) {
F_44 ( V_27 ) ;
return - V_32 ;
}
F_68 ( V_106 ) ;
V_27 -> V_152 = V_106 -> V_152 ;
F_69 ( V_106 , V_153 , & V_27 -> V_154 ) ;
F_70 ( V_106 , V_155 , & V_27 -> V_156 ) ;
F_71 ( V_98 -> V_147 , L_9 , V_27 -> V_156 ,
V_27 -> V_152 , V_27 -> V_154 ) ;
F_3 ( 0 , V_27 -> V_9 + V_15 ) ;
for( V_144 = 0 ; V_144 < 3 ; V_144 ++ ) {
V_27 -> V_38 [ V_144 ] . V_2 = V_27 ;
V_27 -> V_38 [ V_144 ] . V_42 = V_144 ;
}
F_6 ( V_27 , V_157 , 0 ,
V_27 -> V_158 [ 0 ] =
V_159 | V_160 |
V_161 | V_162 |
V_163 | 0x00001200 |
0x00000000 | V_164 | V_165 ) ;
F_6 ( V_27 , V_166 , 0 ,
V_27 -> V_158 [ 1 ] =
V_159 | V_160 |
V_161 | V_162 |
V_163 | 0x00001200 |
0x00000000 | V_164 | V_165 ) ;
F_6 ( V_27 , V_167 , 0 ,
V_27 -> V_158 [ 2 ] =
V_159 | V_160 |
V_161 | V_162 |
V_163 | 0x00001200 |
0x00000000 | V_164 | V_165 ) ;
F_6 ( V_27 , V_168 , 0 , 0x700 ) ;
F_6 ( V_27 , V_169 , 0 , 0x1003F ) ;
F_9 ( V_27 , 0x1080 ) ;
F_3 ( V_102 | V_170 , V_27 -> V_9 + V_103 ) ;
if ( ( V_28 = F_72 ( V_98 , V_171 ,
V_27 , & V_95 ) ) < 0 ) {
F_44 ( V_27 ) ;
return V_28 ;
}
* V_143 = V_27 ;
return 0 ;
}
static void F_73 ( struct V_172 * V_173 ,
struct V_174 * V_175 )
{
struct V_1 * V_2 = V_173 -> V_20 ;
unsigned long V_16 , V_176 , V_177 ;
unsigned long V_5 ;
int V_48 ;
F_74 ( V_175 , L_10 ) ;
for( V_48 = 0 ; V_48 < 0x20 ; V_48 += 4 ) {
F_2 ( & V_2 -> V_8 , V_5 ) ;
V_16 = F_4 ( V_2 -> V_9 + V_48 ) ;
F_5 ( & V_2 -> V_8 , V_5 ) ;
F_74 ( V_175 , L_11 , V_48 , V_16 ) ;
}
F_74 ( V_175 , L_12 ) ;
for( V_48 = 0 ; V_48 <= 0x48 ; V_48 ++ ) {
V_16 = F_1 ( V_2 , V_48 , 0 ) ;
if( V_48 < 0x10 || ( V_48 >= 0x20 && V_48 < 0x40 ) ) {
V_176 = F_1 ( V_2 , V_48 , 1 ) ;
V_177 = F_1 ( V_2 , V_48 , 2 ) ;
F_74 ( V_175 , L_13 , V_48 , V_16 , V_176 , V_177 ) ;
} else {
F_74 ( V_175 , L_14 , V_48 , V_16 ) ;
}
}
}
static void F_75 ( struct V_172 * V_173 ,
struct V_174 * V_175 )
{
struct V_1 * V_2 = V_173 -> V_20 ;
char line [ 64 ] ;
unsigned int V_3 , V_178 , V_7 ;
while ( ! F_76 ( V_175 , line , sizeof( line ) ) ) {
if ( sscanf ( line , L_15 , & V_3 , & V_178 , & V_7 ) != 3 )
continue;
if ( V_3 < 0x49 && V_7 <= 0xffffffff && V_178 <= 2 )
F_6 ( V_2 , V_3 , V_178 , V_7 ) ;
}
}
static int F_77 ( struct V_1 * V_2 )
{
struct V_172 * V_173 ;
if( ! F_78 ( V_2 -> V_98 , L_16 , & V_173 ) ) {
F_79 ( V_173 , V_2 , F_73 ) ;
V_173 -> V_179 . V_180 . V_96 = F_75 ;
V_173 -> V_181 |= V_182 ;
V_173 -> V_20 = V_2 ;
}
return 0 ;
}
static int F_80 ( struct V_183 * V_184 ,
struct V_185 * V_186 )
{
struct V_1 * V_2 = F_81 ( V_184 ) ;
V_186 -> V_16 . integer . V_16 [ 0 ] = ( F_1 ( V_2 , V_168 , 0 ) == 0x700 ) ? 0 : 1 ;
return 0 ;
}
static int F_82 ( struct V_183 * V_184 ,
struct V_185 * V_186 )
{
struct V_1 * V_2 = F_81 ( V_184 ) ;
unsigned int V_7 ;
int V_187 = 0 ;
V_7 = V_186 -> V_16 . integer . V_16 [ 0 ] ;
if ( V_7 ) {
F_6 ( V_2 , V_168 , 0 , 0x000 ) ;
F_6 ( V_2 , V_169 , 0 , 0x700 ) ;
F_9 ( V_2 , 0x1000 ) ;
} else {
F_6 ( V_2 , V_168 , 0 , 0x700 ) ;
F_6 ( V_2 , V_169 , 0 , 0x1003F ) ;
F_9 ( V_2 , 0x1080 ) ;
}
return V_187 ;
}
static int F_83 ( struct V_183 * V_184 , struct V_188 * V_189 )
{
V_189 -> type = V_190 ;
V_189 -> V_191 = 1 ;
return 0 ;
}
static int F_84 ( struct V_183 * V_184 ,
struct V_185 * V_186 )
{
struct V_1 * V_2 = F_81 ( V_184 ) ;
unsigned int V_192 = F_85 ( V_184 , & V_186 -> V_193 ) ;
V_186 -> V_16 . V_194 . V_110 [ 0 ] = ( V_2 -> V_158 [ V_192 ] >> 0 ) & 0xff ;
V_186 -> V_16 . V_194 . V_110 [ 1 ] = ( V_2 -> V_158 [ V_192 ] >> 8 ) & 0xff ;
V_186 -> V_16 . V_194 . V_110 [ 2 ] = ( V_2 -> V_158 [ V_192 ] >> 16 ) & 0xff ;
V_186 -> V_16 . V_194 . V_110 [ 3 ] = ( V_2 -> V_158 [ V_192 ] >> 24 ) & 0xff ;
return 0 ;
}
static int F_86 ( struct V_183 * V_184 ,
struct V_185 * V_186 )
{
V_186 -> V_16 . V_194 . V_110 [ 0 ] = 0xff ;
V_186 -> V_16 . V_194 . V_110 [ 1 ] = 0xff ;
V_186 -> V_16 . V_194 . V_110 [ 2 ] = 0xff ;
V_186 -> V_16 . V_194 . V_110 [ 3 ] = 0xff ;
return 0 ;
}
static int F_87 ( struct V_183 * V_184 ,
struct V_185 * V_186 )
{
struct V_1 * V_2 = F_81 ( V_184 ) ;
unsigned int V_192 = F_85 ( V_184 , & V_186 -> V_193 ) ;
int V_187 ;
unsigned int V_7 ;
V_7 = ( V_186 -> V_16 . V_194 . V_110 [ 0 ] << 0 ) |
( V_186 -> V_16 . V_194 . V_110 [ 1 ] << 8 ) |
( V_186 -> V_16 . V_194 . V_110 [ 2 ] << 16 ) |
( V_186 -> V_16 . V_194 . V_110 [ 3 ] << 24 ) ;
V_187 = V_7 != V_2 -> V_158 [ V_192 ] ;
if ( V_187 ) {
F_6 ( V_2 , V_157 + V_192 , 0 , V_7 ) ;
V_2 -> V_158 [ V_192 ] = V_7 ;
}
return V_187 ;
}
static int F_88 ( struct V_1 * V_2 )
{
int V_28 ;
struct V_183 * V_195 ;
struct V_141 * V_98 = V_2 -> V_98 ;
if ( ( V_195 = F_89 ( & V_196 , V_2 ) ) == NULL )
return - V_32 ;
if ( ( V_28 = F_90 ( V_98 , V_195 ) ) )
return V_28 ;
if ( ( V_195 = F_89 ( & V_197 , V_2 ) ) == NULL )
return - V_32 ;
if ( ( V_28 = F_90 ( V_98 , V_195 ) ) )
return V_28 ;
if ( ( V_195 = F_89 ( & V_198 , V_2 ) ) == NULL )
return - V_32 ;
if ( ( V_28 = F_90 ( V_98 , V_195 ) ) )
return V_28 ;
return 0 ;
}
static inline unsigned char F_91 ( struct V_1 * V_2 , struct V_199 * V_200 , int V_192 )
{
return ( unsigned char ) F_1 ( V_2 , V_200 -> V_9 + V_192 , 0 ) ;
}
static inline void F_92 ( struct V_1 * V_2 , struct V_199 * V_200 , int V_12 , int V_192 )
{
F_6 ( V_2 , V_200 -> V_9 + V_192 , 0 , V_12 ) ;
}
static void F_93 ( struct V_1 * V_2 , struct V_199 * V_200 )
{
int V_201 = 100000 ;
for (; V_201 > 0 && F_94 ( V_2 , V_200 ) ; V_201 -- )
F_95 ( V_2 , V_200 ) ;
#ifdef F_96
if ( V_201 <= 0 )
F_62 ( V_2 -> V_98 -> V_147 ,
L_17 ,
F_97 ( V_2 , V_200 ) ) ;
#endif
}
static void F_98 ( struct V_1 * V_2 ,
struct V_199 * V_122 , unsigned int V_110 )
{
unsigned char V_202 ;
if ( V_122 -> V_203 == NULL ) {
F_8 ( V_2 , V_122 -> V_204 | V_122 -> V_205 ) ;
return;
}
F_99 ( & V_122 -> V_206 ) ;
if ( ( V_110 & V_122 -> V_207 ) && F_94 ( V_2 , V_122 ) ) {
if ( ! ( V_122 -> V_208 & V_209 ) ) {
F_93 ( V_2 , V_122 ) ;
} else {
V_202 = F_95 ( V_2 , V_122 ) ;
if ( V_122 -> V_210 )
F_100 ( V_122 -> V_210 , & V_202 , 1 ) ;
}
}
F_101 ( & V_122 -> V_206 ) ;
F_99 ( & V_122 -> V_211 ) ;
if ( ( V_110 & V_122 -> V_212 ) && F_102 ( V_2 , V_122 ) ) {
if ( V_122 -> V_213 &&
F_103 ( V_122 -> V_213 , & V_202 , 1 ) == 1 ) {
F_104 ( V_2 , V_122 , V_202 ) ;
} else {
F_8 ( V_2 , V_122 -> V_204 ) ;
}
}
F_101 ( & V_122 -> V_211 ) ;
}
static void F_105 ( struct V_1 * V_2 , unsigned int V_110 )
{
F_98 ( V_2 , & V_2 -> V_122 , V_110 ) ;
}
static int F_106 ( struct V_1 * V_2 ,
struct V_199 * V_122 , unsigned char V_60 , int V_214 )
{
unsigned long V_5 ;
int V_201 , V_215 ;
F_2 ( & V_122 -> V_206 , V_5 ) ;
F_104 ( V_2 , V_122 , 0x00 ) ;
F_107 ( V_2 , V_122 , V_60 ) ;
if ( V_214 ) {
V_215 = 0 ;
V_201 = 10000 ;
while ( ! V_215 && V_201 -- > 0 ) {
if ( F_94 ( V_2 , V_122 ) ) {
if ( F_95 ( V_2 , V_122 ) == V_216 )
V_215 = 1 ;
}
}
if ( ! V_215 && F_95 ( V_2 , V_122 ) == V_216 )
V_215 = 1 ;
} else {
V_215 = 1 ;
}
F_5 ( & V_122 -> V_206 , V_5 ) ;
if ( ! V_215 ) {
F_62 ( V_2 -> V_98 -> V_147 ,
L_18 ,
V_60 , V_2 -> V_9 ,
F_97 ( V_2 , V_122 ) ,
F_95 ( V_2 , V_122 ) ) ;
return 1 ;
}
return 0 ;
}
static int F_108 ( struct V_217 * V_25 )
{
struct V_1 * V_2 ;
struct V_199 * V_122 = V_25 -> V_203 -> V_20 ;
unsigned long V_5 ;
V_2 = V_122 -> V_2 ;
if ( F_109 ( ! V_2 ) )
return - V_148 ;
F_2 ( & V_122 -> V_218 , V_5 ) ;
V_122 -> V_208 |= V_209 ;
V_122 -> V_210 = V_25 ;
if ( ! ( V_122 -> V_208 & V_219 ) ) {
F_5 ( & V_122 -> V_218 , V_5 ) ;
if ( F_106 ( V_2 , V_122 , V_220 , 1 ) )
goto V_221;
if ( F_106 ( V_2 , V_122 , V_222 , 1 ) )
goto V_221;
} else {
F_5 ( & V_122 -> V_218 , V_5 ) ;
}
return 0 ;
V_221:
return - V_223 ;
}
static int F_110 ( struct V_217 * V_25 )
{
struct V_1 * V_2 ;
struct V_199 * V_122 = V_25 -> V_203 -> V_20 ;
unsigned long V_5 ;
V_2 = V_122 -> V_2 ;
if ( F_109 ( ! V_2 ) )
return - V_148 ;
F_2 ( & V_122 -> V_218 , V_5 ) ;
V_122 -> V_208 |= V_219 ;
V_122 -> V_213 = V_25 ;
if ( ! ( V_122 -> V_208 & V_209 ) ) {
F_5 ( & V_122 -> V_218 , V_5 ) ;
if ( F_106 ( V_2 , V_122 , V_220 , 1 ) )
goto V_221;
if ( F_106 ( V_2 , V_122 , V_222 , 1 ) )
goto V_221;
} else {
F_5 ( & V_122 -> V_218 , V_5 ) ;
}
return 0 ;
V_221:
return - V_223 ;
}
static int F_111 ( struct V_217 * V_25 )
{
struct V_1 * V_2 ;
struct V_199 * V_122 = V_25 -> V_203 -> V_20 ;
unsigned long V_5 ;
int V_28 = 0 ;
V_2 = V_122 -> V_2 ;
if ( F_109 ( ! V_2 ) )
return - V_148 ;
F_2 ( & V_122 -> V_218 , V_5 ) ;
F_8 ( V_2 , V_122 -> V_205 ) ;
V_122 -> V_208 &= ~ V_209 ;
V_122 -> V_210 = NULL ;
if ( ! ( V_122 -> V_208 & V_219 ) ) {
F_5 ( & V_122 -> V_218 , V_5 ) ;
V_28 = F_106 ( V_2 , V_122 , V_220 , 0 ) ;
} else {
F_5 ( & V_122 -> V_218 , V_5 ) ;
}
return V_28 ;
}
static int F_112 ( struct V_217 * V_25 )
{
struct V_1 * V_2 ;
struct V_199 * V_122 = V_25 -> V_203 -> V_20 ;
unsigned long V_5 ;
int V_28 = 0 ;
V_2 = V_122 -> V_2 ;
if ( F_109 ( ! V_2 ) )
return - V_148 ;
F_2 ( & V_122 -> V_218 , V_5 ) ;
F_8 ( V_2 , V_122 -> V_204 ) ;
V_122 -> V_208 &= ~ V_219 ;
V_122 -> V_213 = NULL ;
if ( ! ( V_122 -> V_208 & V_209 ) ) {
F_5 ( & V_122 -> V_218 , V_5 ) ;
V_28 = F_106 ( V_2 , V_122 , V_220 , 0 ) ;
} else {
F_5 ( & V_122 -> V_218 , V_5 ) ;
}
return V_28 ;
}
static void F_113 ( struct V_217 * V_25 , int V_224 )
{
struct V_1 * V_2 ;
struct V_199 * V_122 = V_25 -> V_203 -> V_20 ;
V_2 = V_122 -> V_2 ;
if ( F_109 ( ! V_2 ) )
return;
if ( V_224 )
F_7 ( V_2 , V_122 -> V_205 ) ;
else
F_8 ( V_2 , V_122 -> V_205 ) ;
}
static void F_114 ( struct V_217 * V_25 , int V_224 )
{
struct V_1 * V_2 ;
struct V_199 * V_122 = V_25 -> V_203 -> V_20 ;
unsigned long V_5 ;
V_2 = V_122 -> V_2 ;
if ( F_109 ( ! V_2 ) )
return;
if ( V_224 ) {
int V_225 = 4 ;
unsigned char V_202 ;
F_2 ( & V_122 -> V_211 , V_5 ) ;
while ( V_225 > 0 ) {
if ( F_102 ( V_2 , V_122 ) ) {
if ( ! ( V_122 -> V_208 & V_219 ) ||
F_103 ( V_25 , & V_202 , 1 ) != 1 ) {
F_5 ( & V_122 -> V_211 , V_5 ) ;
return;
}
F_104 ( V_2 , V_122 , V_202 ) ;
V_225 -- ;
} else {
break;
}
}
F_5 ( & V_122 -> V_211 , V_5 ) ;
F_7 ( V_2 , V_122 -> V_204 ) ;
} else {
F_8 ( V_2 , V_122 -> V_204 ) ;
}
}
static void F_115 ( struct V_226 * V_203 )
{
struct V_199 * V_122 = V_203 -> V_20 ;
V_122 -> V_123 = NULL ;
V_122 -> V_203 = NULL ;
}
static int F_116 ( struct V_1 * V_2 ,
struct V_199 * V_122 , int V_40 ,
char * V_136 )
{
struct V_226 * V_203 ;
int V_28 ;
if ( ( V_28 = F_117 ( V_2 -> V_98 , V_136 , V_40 , 1 , 1 , & V_203 ) ) < 0 )
return V_28 ;
V_122 -> V_2 = V_2 ;
F_63 ( & V_122 -> V_218 ) ;
F_63 ( & V_122 -> V_206 ) ;
F_63 ( & V_122 -> V_211 ) ;
strcpy ( V_203 -> V_136 , V_136 ) ;
F_118 ( V_203 , V_227 , & V_228 ) ;
F_118 ( V_203 , V_229 , & V_230 ) ;
V_203 -> V_135 |= V_231 |
V_232 |
V_233 ;
V_203 -> V_20 = V_122 ;
V_203 -> V_33 = F_115 ;
V_122 -> V_203 = V_203 ;
return 0 ;
}
static int F_119 ( struct V_1 * V_2 )
{
struct V_199 * V_122 = & V_2 -> V_122 ;
int V_28 ;
if ( ( V_28 = F_116 ( V_2 , V_122 , 0 , L_19 ) ) < 0 )
return V_28 ;
V_122 -> V_204 = V_124 ;
V_122 -> V_205 = V_125 ;
V_122 -> V_9 = V_234 ;
V_122 -> V_212 = V_120 ;
V_122 -> V_207 = V_121 ;
V_122 -> V_123 = F_105 ;
return 0 ;
}
static int F_120 ( struct V_142 * V_106 ,
const struct V_235 * V_236 )
{
static int V_147 ;
struct V_141 * V_98 ;
struct V_1 * V_27 ;
int V_28 ;
if ( V_147 >= V_237 )
return - V_238 ;
if ( ! V_239 [ V_147 ] ) {
V_147 ++ ;
return - V_240 ;
}
V_28 = F_121 ( & V_106 -> V_147 , V_241 [ V_147 ] , V_193 [ V_147 ] , V_242 ,
0 , & V_98 ) ;
if ( V_28 < 0 )
return V_28 ;
if ( ( V_28 = F_57 ( V_98 , V_106 , & V_27 ) ) < 0 ) {
F_122 ( V_98 ) ;
return V_28 ;
}
if ( ( V_28 = F_51 ( V_27 , 0 ) ) < 0 ) {
F_122 ( V_98 ) ;
return V_28 ;
}
if ( ( V_28 = F_51 ( V_27 , 1 ) ) < 0 ) {
F_122 ( V_98 ) ;
return V_28 ;
}
if ( ( V_28 = F_51 ( V_27 , 2 ) ) < 0 ) {
F_122 ( V_98 ) ;
return V_28 ;
}
if ( ( V_28 = F_42 ( V_27 ) ) < 0 ) {
F_122 ( V_98 ) ;
return V_28 ;
}
if ( ( V_28 = F_88 ( V_27 ) ) < 0 ) {
F_122 ( V_98 ) ;
return V_28 ;
}
if ( ( V_28 = F_119 ( V_27 ) ) < 0 ) {
F_122 ( V_98 ) ;
return V_28 ;
}
F_77 ( V_27 ) ;
strcpy ( V_98 -> V_243 , L_6 ) ;
strcpy ( V_98 -> V_244 , L_20 ) ;
sprintf ( V_98 -> V_245 , L_21 ,
V_98 -> V_244 , V_27 -> V_9 , V_27 -> V_104 ) ;
if ( ( V_28 = F_123 ( V_98 ) ) < 0 ) {
F_122 ( V_98 ) ;
return V_28 ;
}
F_124 ( V_106 , V_98 ) ;
V_147 ++ ;
return 0 ;
}
static void F_125 ( struct V_142 * V_106 )
{
F_122 ( F_126 ( V_106 ) ) ;
}
