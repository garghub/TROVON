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
snd_printk(KERN_INFO "IRQ: position = 0x%x, period = 0x%x, size = 0x%x\n",
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
static int F_51 ( struct V_1 * V_2 , int V_40 , struct V_127 * * V_128 )
{
struct V_127 * V_39 ;
const struct V_129 * V_130 = NULL ;
int V_28 ;
int V_131 = 0 ;
if ( V_128 )
* V_128 = NULL ;
if ( V_40 == 0 )
V_131 = 1 ;
if ( ( V_28 = F_52 ( V_2 -> V_98 , L_1 , V_40 , 1 , V_131 , & V_39 ) ) < 0 )
return V_28 ;
V_39 -> V_20 = V_2 ;
switch( V_40 ) {
case 0 :
F_53 ( V_39 , V_132 , & V_133 ) ;
F_53 ( V_39 , V_134 , & V_135 ) ;
break;
case 1 :
case 2 :
F_53 ( V_39 , V_132 , & V_133 ) ;
break;
}
V_39 -> V_136 = 0 ;
switch( V_40 ) {
case 0 :
strcpy ( V_39 -> V_137 , L_2 ) ;
V_130 = V_138 ;
break;
case 1 :
strcpy ( V_39 -> V_137 , L_3 ) ;
V_130 = V_139 ;
break;
case 2 :
strcpy ( V_39 -> V_137 , L_4 ) ;
V_130 = V_140 ;
break;
}
V_2 -> V_39 = V_39 ;
F_54 ( V_39 , V_141 ,
F_55 ( V_2 -> V_106 ) ,
32 * 1024 , 32 * 1024 ) ;
V_28 = F_56 ( V_39 , V_132 , V_130 , 2 ,
1 << 2 , NULL ) ;
if ( V_28 < 0 )
return V_28 ;
if ( V_128 )
* V_128 = V_39 ;
return 0 ;
}
static int F_57 ( struct V_142 * V_98 ,
struct V_143 * V_106 ,
struct V_1 * * V_144 )
{
struct V_1 * V_27 ;
int V_28 ;
int V_145 ;
static struct V_146 V_95 = {
. V_147 = F_49 ,
} ;
* V_144 = NULL ;
if ( ( V_28 = F_58 ( V_106 ) ) < 0 )
return V_28 ;
if ( F_59 ( V_106 , F_60 ( 28 ) ) < 0 ||
F_61 ( V_106 , F_60 ( 28 ) ) < 0 ) {
F_62 ( V_148 L_5 ) ;
F_48 ( V_106 ) ;
return - V_149 ;
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
F_63 ( & V_27 -> V_150 ) ;
V_27 -> V_9 = F_64 ( V_106 , 0 ) ;
if ( ( V_27 -> V_105 = F_65 ( V_27 -> V_9 , 8 ,
L_6 ) ) == NULL ) {
F_62 ( V_148 L_7 , V_27 -> V_9 ) ;
F_44 ( V_27 ) ;
return - V_79 ;
}
if ( F_66 ( V_106 -> V_104 , F_50 ,
V_151 , V_152 , V_27 ) ) {
F_62 ( V_148 L_8 , V_106 -> V_104 ) ;
F_44 ( V_27 ) ;
return - V_79 ;
}
V_27 -> V_104 = V_106 -> V_104 ;
if( F_67 ( V_141 , F_55 ( V_106 ) ,
4 * 1024 , & V_27 -> V_44 ) < 0 ) {
F_44 ( V_27 ) ;
return - V_32 ;
}
F_68 ( V_106 ) ;
V_27 -> V_153 = V_106 -> V_153 ;
F_69 ( V_106 , V_154 , & V_27 -> V_155 ) ;
F_70 ( V_106 , V_156 , & V_27 -> V_157 ) ;
F_62 ( V_158 L_9 , V_27 -> V_157 ,
V_27 -> V_153 , V_27 -> V_155 ) ;
F_3 ( 0 , V_27 -> V_9 + V_15 ) ;
for( V_145 = 0 ; V_145 < 3 ; V_145 ++ ) {
V_27 -> V_38 [ V_145 ] . V_2 = V_27 ;
V_27 -> V_38 [ V_145 ] . V_42 = V_145 ;
}
F_6 ( V_27 , V_159 , 0 ,
V_27 -> V_160 [ 0 ] =
V_161 | V_162 |
V_163 | V_164 |
V_165 | 0x00001200 |
0x00000000 | V_166 | V_167 ) ;
F_6 ( V_27 , V_168 , 0 ,
V_27 -> V_160 [ 1 ] =
V_161 | V_162 |
V_163 | V_164 |
V_165 | 0x00001200 |
0x00000000 | V_166 | V_167 ) ;
F_6 ( V_27 , V_169 , 0 ,
V_27 -> V_160 [ 2 ] =
V_161 | V_162 |
V_163 | V_164 |
V_165 | 0x00001200 |
0x00000000 | V_166 | V_167 ) ;
F_6 ( V_27 , V_170 , 0 , 0x700 ) ;
F_6 ( V_27 , V_171 , 0 , 0x1003F ) ;
F_9 ( V_27 , 0x1080 ) ;
F_3 ( V_102 | V_172 , V_27 -> V_9 + V_103 ) ;
if ( ( V_28 = F_71 ( V_98 , V_173 ,
V_27 , & V_95 ) ) < 0 ) {
F_44 ( V_27 ) ;
return V_28 ;
}
* V_144 = V_27 ;
return 0 ;
}
static void F_72 ( struct V_174 * V_175 ,
struct V_176 * V_177 )
{
struct V_1 * V_2 = V_175 -> V_20 ;
unsigned long V_16 , V_178 , V_179 ;
unsigned long V_5 ;
int V_48 ;
F_73 ( V_177 , L_10 ) ;
for( V_48 = 0 ; V_48 < 0x20 ; V_48 += 4 ) {
F_2 ( & V_2 -> V_8 , V_5 ) ;
V_16 = F_4 ( V_2 -> V_9 + V_48 ) ;
F_5 ( & V_2 -> V_8 , V_5 ) ;
F_73 ( V_177 , L_11 , V_48 , V_16 ) ;
}
F_73 ( V_177 , L_12 ) ;
for( V_48 = 0 ; V_48 <= 0x48 ; V_48 ++ ) {
V_16 = F_1 ( V_2 , V_48 , 0 ) ;
if( V_48 < 0x10 || ( V_48 >= 0x20 && V_48 < 0x40 ) ) {
V_178 = F_1 ( V_2 , V_48 , 1 ) ;
V_179 = F_1 ( V_2 , V_48 , 2 ) ;
F_73 ( V_177 , L_13 , V_48 , V_16 , V_178 , V_179 ) ;
} else {
F_73 ( V_177 , L_14 , V_48 , V_16 ) ;
}
}
}
static void F_74 ( struct V_174 * V_175 ,
struct V_176 * V_177 )
{
struct V_1 * V_2 = V_175 -> V_20 ;
char line [ 64 ] ;
unsigned int V_3 , V_180 , V_7 ;
while ( ! F_75 ( V_177 , line , sizeof( line ) ) ) {
if ( sscanf ( line , L_15 , & V_3 , & V_180 , & V_7 ) != 3 )
continue;
if ( V_3 < 0x49 && V_7 <= 0xffffffff && V_180 <= 2 )
F_6 ( V_2 , V_3 , V_180 , V_7 ) ;
}
}
static int F_76 ( struct V_1 * V_2 )
{
struct V_174 * V_175 ;
if( ! F_77 ( V_2 -> V_98 , L_16 , & V_175 ) ) {
F_78 ( V_175 , V_2 , F_72 ) ;
V_175 -> V_181 . V_182 . V_96 = F_74 ;
V_175 -> V_183 |= V_184 ;
V_175 -> V_20 = V_2 ;
}
return 0 ;
}
static int F_79 ( struct V_185 * V_186 ,
struct V_187 * V_188 )
{
struct V_1 * V_2 = F_80 ( V_186 ) ;
V_188 -> V_16 . integer . V_16 [ 0 ] = ( F_1 ( V_2 , V_170 , 0 ) == 0x700 ) ? 0 : 1 ;
return 0 ;
}
static int F_81 ( struct V_185 * V_186 ,
struct V_187 * V_188 )
{
struct V_1 * V_2 = F_80 ( V_186 ) ;
unsigned int V_7 ;
int V_189 = 0 ;
V_7 = V_188 -> V_16 . integer . V_16 [ 0 ] ;
if ( V_7 ) {
F_6 ( V_2 , V_170 , 0 , 0x000 ) ;
F_6 ( V_2 , V_171 , 0 , 0x700 ) ;
F_9 ( V_2 , 0x1000 ) ;
} else {
F_6 ( V_2 , V_170 , 0 , 0x700 ) ;
F_6 ( V_2 , V_171 , 0 , 0x1003F ) ;
F_9 ( V_2 , 0x1080 ) ;
}
return V_189 ;
}
static int F_82 ( struct V_185 * V_186 , struct V_190 * V_191 )
{
V_191 -> type = V_192 ;
V_191 -> V_193 = 1 ;
return 0 ;
}
static int F_83 ( struct V_185 * V_186 ,
struct V_187 * V_188 )
{
struct V_1 * V_2 = F_80 ( V_186 ) ;
unsigned int V_194 = F_84 ( V_186 , & V_188 -> V_195 ) ;
V_188 -> V_16 . V_196 . V_110 [ 0 ] = ( V_2 -> V_160 [ V_194 ] >> 0 ) & 0xff ;
V_188 -> V_16 . V_196 . V_110 [ 1 ] = ( V_2 -> V_160 [ V_194 ] >> 8 ) & 0xff ;
V_188 -> V_16 . V_196 . V_110 [ 2 ] = ( V_2 -> V_160 [ V_194 ] >> 16 ) & 0xff ;
V_188 -> V_16 . V_196 . V_110 [ 3 ] = ( V_2 -> V_160 [ V_194 ] >> 24 ) & 0xff ;
return 0 ;
}
static int F_85 ( struct V_185 * V_186 ,
struct V_187 * V_188 )
{
V_188 -> V_16 . V_196 . V_110 [ 0 ] = 0xff ;
V_188 -> V_16 . V_196 . V_110 [ 1 ] = 0xff ;
V_188 -> V_16 . V_196 . V_110 [ 2 ] = 0xff ;
V_188 -> V_16 . V_196 . V_110 [ 3 ] = 0xff ;
return 0 ;
}
static int F_86 ( struct V_185 * V_186 ,
struct V_187 * V_188 )
{
struct V_1 * V_2 = F_80 ( V_186 ) ;
unsigned int V_194 = F_84 ( V_186 , & V_188 -> V_195 ) ;
int V_189 ;
unsigned int V_7 ;
V_7 = ( V_188 -> V_16 . V_196 . V_110 [ 0 ] << 0 ) |
( V_188 -> V_16 . V_196 . V_110 [ 1 ] << 8 ) |
( V_188 -> V_16 . V_196 . V_110 [ 2 ] << 16 ) |
( V_188 -> V_16 . V_196 . V_110 [ 3 ] << 24 ) ;
V_189 = V_7 != V_2 -> V_160 [ V_194 ] ;
if ( V_189 ) {
F_6 ( V_2 , V_159 + V_194 , 0 , V_7 ) ;
V_2 -> V_160 [ V_194 ] = V_7 ;
}
return V_189 ;
}
static int F_87 ( struct V_1 * V_2 )
{
int V_28 ;
struct V_185 * V_197 ;
struct V_142 * V_98 = V_2 -> V_98 ;
if ( ( V_197 = F_88 ( & V_198 , V_2 ) ) == NULL )
return - V_32 ;
if ( ( V_28 = F_89 ( V_98 , V_197 ) ) )
return V_28 ;
if ( ( V_197 = F_88 ( & V_199 , V_2 ) ) == NULL )
return - V_32 ;
if ( ( V_28 = F_89 ( V_98 , V_197 ) ) )
return V_28 ;
if ( ( V_197 = F_88 ( & V_200 , V_2 ) ) == NULL )
return - V_32 ;
if ( ( V_28 = F_89 ( V_98 , V_197 ) ) )
return V_28 ;
return 0 ;
}
static inline unsigned char F_90 ( struct V_1 * V_2 , struct V_201 * V_202 , int V_194 )
{
return ( unsigned char ) F_1 ( V_2 , V_202 -> V_9 + V_194 , 0 ) ;
}
static inline void F_91 ( struct V_1 * V_2 , struct V_201 * V_202 , int V_12 , int V_194 )
{
F_6 ( V_2 , V_202 -> V_9 + V_194 , 0 , V_12 ) ;
}
static void F_92 ( struct V_1 * V_2 , struct V_201 * V_202 )
{
int V_203 = 100000 ;
for (; V_203 > 0 && F_93 ( V_2 , V_202 ) ; V_203 -- )
F_94 ( V_2 , V_202 ) ;
#ifdef F_95
if ( V_203 <= 0 )
F_62 ( V_148 L_17 , F_96 ( V_2 , V_202 ) ) ;
#endif
}
static void F_97 ( struct V_1 * V_2 ,
struct V_201 * V_122 , unsigned int V_110 )
{
unsigned char V_204 ;
if ( V_122 -> V_205 == NULL ) {
F_8 ( V_2 , V_122 -> V_206 | V_122 -> V_207 ) ;
return;
}
F_98 ( & V_122 -> V_208 ) ;
if ( ( V_110 & V_122 -> V_209 ) && F_93 ( V_2 , V_122 ) ) {
if ( ! ( V_122 -> V_210 & V_211 ) ) {
F_92 ( V_2 , V_122 ) ;
} else {
V_204 = F_94 ( V_2 , V_122 ) ;
if ( V_122 -> V_212 )
F_99 ( V_122 -> V_212 , & V_204 , 1 ) ;
}
}
F_100 ( & V_122 -> V_208 ) ;
F_98 ( & V_122 -> V_213 ) ;
if ( ( V_110 & V_122 -> V_214 ) && F_101 ( V_2 , V_122 ) ) {
if ( V_122 -> V_215 &&
F_102 ( V_122 -> V_215 , & V_204 , 1 ) == 1 ) {
F_103 ( V_2 , V_122 , V_204 ) ;
} else {
F_8 ( V_2 , V_122 -> V_206 ) ;
}
}
F_100 ( & V_122 -> V_213 ) ;
}
static void F_104 ( struct V_1 * V_2 , unsigned int V_110 )
{
F_97 ( V_2 , & V_2 -> V_122 , V_110 ) ;
}
static int F_105 ( struct V_1 * V_2 ,
struct V_201 * V_122 , unsigned char V_60 , int V_216 )
{
unsigned long V_5 ;
int V_203 , V_217 ;
F_2 ( & V_122 -> V_208 , V_5 ) ;
F_103 ( V_2 , V_122 , 0x00 ) ;
F_106 ( V_2 , V_122 , V_60 ) ;
if ( V_216 ) {
V_217 = 0 ;
V_203 = 10000 ;
while ( ! V_217 && V_203 -- > 0 ) {
if ( F_93 ( V_2 , V_122 ) ) {
if ( F_94 ( V_2 , V_122 ) == V_218 )
V_217 = 1 ;
}
}
if ( ! V_217 && F_94 ( V_2 , V_122 ) == V_218 )
V_217 = 1 ;
} else {
V_217 = 1 ;
}
F_5 ( & V_122 -> V_208 , V_5 ) ;
if ( ! V_217 ) {
F_62 ( V_148 L_18 ,
V_60 , V_2 -> V_9 ,
F_96 ( V_2 , V_122 ) ,
F_94 ( V_2 , V_122 ) ) ;
return 1 ;
}
return 0 ;
}
static int F_107 ( struct V_219 * V_25 )
{
struct V_1 * V_2 ;
struct V_201 * V_122 = V_25 -> V_205 -> V_20 ;
unsigned long V_5 ;
V_2 = V_122 -> V_2 ;
if ( F_108 ( ! V_2 ) )
return - V_149 ;
F_2 ( & V_122 -> V_220 , V_5 ) ;
V_122 -> V_210 |= V_211 ;
V_122 -> V_212 = V_25 ;
if ( ! ( V_122 -> V_210 & V_221 ) ) {
F_5 ( & V_122 -> V_220 , V_5 ) ;
if ( F_105 ( V_2 , V_122 , V_222 , 1 ) )
goto V_223;
if ( F_105 ( V_2 , V_122 , V_224 , 1 ) )
goto V_223;
} else {
F_5 ( & V_122 -> V_220 , V_5 ) ;
}
return 0 ;
V_223:
return - V_225 ;
}
static int F_109 ( struct V_219 * V_25 )
{
struct V_1 * V_2 ;
struct V_201 * V_122 = V_25 -> V_205 -> V_20 ;
unsigned long V_5 ;
V_2 = V_122 -> V_2 ;
if ( F_108 ( ! V_2 ) )
return - V_149 ;
F_2 ( & V_122 -> V_220 , V_5 ) ;
V_122 -> V_210 |= V_221 ;
V_122 -> V_215 = V_25 ;
if ( ! ( V_122 -> V_210 & V_211 ) ) {
F_5 ( & V_122 -> V_220 , V_5 ) ;
if ( F_105 ( V_2 , V_122 , V_222 , 1 ) )
goto V_223;
if ( F_105 ( V_2 , V_122 , V_224 , 1 ) )
goto V_223;
} else {
F_5 ( & V_122 -> V_220 , V_5 ) ;
}
return 0 ;
V_223:
return - V_225 ;
}
static int F_110 ( struct V_219 * V_25 )
{
struct V_1 * V_2 ;
struct V_201 * V_122 = V_25 -> V_205 -> V_20 ;
unsigned long V_5 ;
int V_28 = 0 ;
V_2 = V_122 -> V_2 ;
if ( F_108 ( ! V_2 ) )
return - V_149 ;
F_2 ( & V_122 -> V_220 , V_5 ) ;
F_8 ( V_2 , V_122 -> V_207 ) ;
V_122 -> V_210 &= ~ V_211 ;
V_122 -> V_212 = NULL ;
if ( ! ( V_122 -> V_210 & V_221 ) ) {
F_5 ( & V_122 -> V_220 , V_5 ) ;
V_28 = F_105 ( V_2 , V_122 , V_222 , 0 ) ;
} else {
F_5 ( & V_122 -> V_220 , V_5 ) ;
}
return V_28 ;
}
static int F_111 ( struct V_219 * V_25 )
{
struct V_1 * V_2 ;
struct V_201 * V_122 = V_25 -> V_205 -> V_20 ;
unsigned long V_5 ;
int V_28 = 0 ;
V_2 = V_122 -> V_2 ;
if ( F_108 ( ! V_2 ) )
return - V_149 ;
F_2 ( & V_122 -> V_220 , V_5 ) ;
F_8 ( V_2 , V_122 -> V_206 ) ;
V_122 -> V_210 &= ~ V_221 ;
V_122 -> V_215 = NULL ;
if ( ! ( V_122 -> V_210 & V_211 ) ) {
F_5 ( & V_122 -> V_220 , V_5 ) ;
V_28 = F_105 ( V_2 , V_122 , V_222 , 0 ) ;
} else {
F_5 ( & V_122 -> V_220 , V_5 ) ;
}
return V_28 ;
}
static void F_112 ( struct V_219 * V_25 , int V_226 )
{
struct V_1 * V_2 ;
struct V_201 * V_122 = V_25 -> V_205 -> V_20 ;
V_2 = V_122 -> V_2 ;
if ( F_108 ( ! V_2 ) )
return;
if ( V_226 )
F_7 ( V_2 , V_122 -> V_207 ) ;
else
F_8 ( V_2 , V_122 -> V_207 ) ;
}
static void F_113 ( struct V_219 * V_25 , int V_226 )
{
struct V_1 * V_2 ;
struct V_201 * V_122 = V_25 -> V_205 -> V_20 ;
unsigned long V_5 ;
V_2 = V_122 -> V_2 ;
if ( F_108 ( ! V_2 ) )
return;
if ( V_226 ) {
int V_227 = 4 ;
unsigned char V_204 ;
F_2 ( & V_122 -> V_213 , V_5 ) ;
while ( V_227 > 0 ) {
if ( F_101 ( V_2 , V_122 ) ) {
if ( ! ( V_122 -> V_210 & V_221 ) ||
F_102 ( V_25 , & V_204 , 1 ) != 1 ) {
F_5 ( & V_122 -> V_213 , V_5 ) ;
return;
}
F_103 ( V_2 , V_122 , V_204 ) ;
V_227 -- ;
} else {
break;
}
}
F_5 ( & V_122 -> V_213 , V_5 ) ;
F_7 ( V_2 , V_122 -> V_206 ) ;
} else {
F_8 ( V_2 , V_122 -> V_206 ) ;
}
}
static void F_114 ( struct V_228 * V_205 )
{
struct V_201 * V_122 = V_205 -> V_20 ;
V_122 -> V_123 = NULL ;
V_122 -> V_205 = NULL ;
}
static int F_115 ( struct V_1 * V_2 ,
struct V_201 * V_122 , int V_40 ,
char * V_137 )
{
struct V_228 * V_205 ;
int V_28 ;
if ( ( V_28 = F_116 ( V_2 -> V_98 , V_137 , V_40 , 1 , 1 , & V_205 ) ) < 0 )
return V_28 ;
V_122 -> V_2 = V_2 ;
F_63 ( & V_122 -> V_220 ) ;
F_63 ( & V_122 -> V_208 ) ;
F_63 ( & V_122 -> V_213 ) ;
strcpy ( V_205 -> V_137 , V_137 ) ;
F_117 ( V_205 , V_229 , & V_230 ) ;
F_117 ( V_205 , V_231 , & V_232 ) ;
V_205 -> V_136 |= V_233 |
V_234 |
V_235 ;
V_205 -> V_20 = V_122 ;
V_205 -> V_33 = F_114 ;
V_122 -> V_205 = V_205 ;
return 0 ;
}
static int F_118 ( struct V_1 * V_2 )
{
struct V_201 * V_122 = & V_2 -> V_122 ;
int V_28 ;
if ( ( V_28 = F_115 ( V_2 , V_122 , 0 , L_19 ) ) < 0 )
return V_28 ;
V_122 -> V_206 = V_124 ;
V_122 -> V_207 = V_125 ;
V_122 -> V_9 = V_236 ;
V_122 -> V_214 = V_120 ;
V_122 -> V_209 = V_121 ;
V_122 -> V_123 = F_104 ;
return 0 ;
}
static int F_119 ( struct V_143 * V_106 ,
const struct V_237 * V_238 )
{
static int V_239 ;
struct V_142 * V_98 ;
struct V_1 * V_27 ;
int V_28 ;
if ( V_239 >= V_240 )
return - V_241 ;
if ( ! V_242 [ V_239 ] ) {
V_239 ++ ;
return - V_243 ;
}
V_28 = F_120 ( V_244 [ V_239 ] , V_195 [ V_239 ] , V_245 , 0 , & V_98 ) ;
if ( V_28 < 0 )
return V_28 ;
if ( ( V_28 = F_57 ( V_98 , V_106 , & V_27 ) ) < 0 ) {
F_121 ( V_98 ) ;
return V_28 ;
}
if ( ( V_28 = F_51 ( V_27 , 0 , NULL ) ) < 0 ) {
F_121 ( V_98 ) ;
return V_28 ;
}
if ( ( V_28 = F_51 ( V_27 , 1 , NULL ) ) < 0 ) {
F_121 ( V_98 ) ;
return V_28 ;
}
if ( ( V_28 = F_51 ( V_27 , 2 , NULL ) ) < 0 ) {
F_121 ( V_98 ) ;
return V_28 ;
}
if ( ( V_28 = F_42 ( V_27 ) ) < 0 ) {
F_121 ( V_98 ) ;
return V_28 ;
}
if ( ( V_28 = F_87 ( V_27 ) ) < 0 ) {
F_121 ( V_98 ) ;
return V_28 ;
}
if ( ( V_28 = F_118 ( V_27 ) ) < 0 ) {
F_121 ( V_98 ) ;
return V_28 ;
}
F_76 ( V_27 ) ;
strcpy ( V_98 -> V_246 , L_6 ) ;
strcpy ( V_98 -> V_247 , L_20 ) ;
sprintf ( V_98 -> V_248 , L_21 ,
V_98 -> V_247 , V_27 -> V_9 , V_27 -> V_104 ) ;
F_122 ( V_98 , & V_106 -> V_239 ) ;
if ( ( V_28 = F_123 ( V_98 ) ) < 0 ) {
F_121 ( V_98 ) ;
return V_28 ;
}
F_124 ( V_106 , V_98 ) ;
V_239 ++ ;
return 0 ;
}
static void F_125 ( struct V_143 * V_106 )
{
F_121 ( F_126 ( V_106 ) ) ;
F_124 ( V_106 , NULL ) ;
}
