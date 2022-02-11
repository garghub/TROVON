static inline int F_1 ( struct V_1 * V_2 )
{
return F_2 ( V_2 -> V_3 ) ;
}
static inline int F_3 ( struct V_1 * V_2 )
{
return F_4 ( V_2 -> V_3 ) ;
}
static inline void F_5 ( struct V_1 * V_2 , int V_4 )
{
F_6 ( V_2 -> V_3 , V_4 ) ;
}
static void F_7 ( struct V_1 * V_2 , int V_4 )
{
if ( V_4 & 0x20 ) {
F_8 ( V_2 -> V_3 ) ;
} else {
F_9 ( V_2 -> V_3 ) ;
}
V_4 &= ~ 0x20 ;
F_10 ( V_2 -> V_3 , V_4 ) ;
}
static int F_11 ( struct V_1 * V_2 , int V_5 )
{
int V_6 ;
int V_7 = 0 ;
if ( V_5 ) {
while ( ! ( ( V_6 = F_1 ( V_2 ) ) & 8 ) ) {
if ( V_7 ++ > V_8 )
F_12 ( 5 ) ;
if ( V_7 > ( V_8 + 1000 ) )
return - 1 ;
}
} else {
while ( ( ( V_6 = F_1 ( V_2 ) ) & 8 ) ) {
if ( V_7 ++ > V_8 )
F_12 ( 5 ) ;
if ( V_7 ++ > ( V_8 + 1000 ) )
return - 1 ;
}
}
return V_6 ;
}
static unsigned int F_13 ( struct V_1 * V_2 , int V_5 )
{
unsigned int V_6 ;
int V_7 = 0 ;
do {
V_6 = F_3 ( V_2 ) ;
if ( V_7 ++ > V_8 )
F_12 ( 5 ) ;
if ( V_7 ++ > ( V_8 + 1000 ) )
return 0 ;
} while ( ( V_6 & 1 ) != V_5 );
return V_6 ;
}
static int F_14 ( struct V_1 * V_2 , int V_9 )
{
int V_10 , V_11 ;
int V_12 ;
F_5 ( V_2 , V_9 ) ;
F_7 ( V_2 , 6 ) ;
V_10 = F_11 ( V_2 , 1 ) ;
F_7 ( V_2 , 0xe ) ;
V_11 = F_11 ( V_2 , 0 ) ;
V_12 = ( V_10 & 0xf0 ) | ( ( V_11 & 0xf0 ) >> 4 ) ;
return V_12 ;
}
static int F_15 ( struct V_1 * V_2 )
{
int V_10 , V_11 ;
int V_12 ;
F_7 ( V_2 , 6 ) ;
V_10 = F_11 ( V_2 , 1 ) ;
F_7 ( V_2 , 0xe ) ;
V_11 = F_11 ( V_2 , 0 ) ;
V_12 = ( V_10 & 0xf0 ) | ( ( V_11 & 0xf0 ) >> 4 ) ;
return V_12 ;
}
static int F_16 ( struct V_1 * V_2 )
{
int V_13 , V_14 ;
int V_15 = 0 ;
int V_16 ;
if ( V_17 )
return 1 ;
V_14 = V_13 = F_1 ( V_2 ) & 0xf0 ;
for ( V_16 = 0 ; V_16 < 500 ; V_16 ++ ) {
V_13 = F_1 ( V_2 ) & 0xf0 ;
if ( V_13 != V_14 )
V_15 ++ ;
V_14 = V_13 ;
F_17 ( 2 ) ;
}
#if 0
printk(KERN_DEBUG "Debugging: QCam detection counter <30-200 counts as detected>: %d\n", count);
return 1;
#endif
if ( V_15 > 20 && V_15 < 400 ) {
return 1 ;
} else {
F_18 ( V_18 L_1 ,
V_2 -> V_3 -> V_19 ) ;
F_18 ( V_20 L_2 , V_15 ) ;
return 0 ;
}
}
static int F_19 ( struct V_1 * V_2 )
{
int V_21 = V_2 -> V_22 ;
switch ( V_2 -> V_23 ) {
case 1 :
V_2 -> V_22 = 0 ;
break;
case 2 :
V_2 -> V_22 = 4 ;
break;
case 4 :
V_2 -> V_22 = 8 ;
break;
}
switch ( V_2 -> V_24 ) {
case 4 :
break;
case 6 :
V_2 -> V_22 += 2 ;
break;
}
switch ( V_2 -> V_25 & V_26 ) {
case V_27 :
V_2 -> V_22 += 1 ;
break;
case V_28 :
case V_29 :
break;
}
if ( V_2 -> V_22 != V_21 )
V_2 -> V_6 |= V_30 ;
return 0 ;
}
static void F_20 ( struct V_1 * V_2 )
{
switch ( V_2 -> V_25 & V_31 ) {
case V_32 :
V_2 -> V_25 = ( V_2 -> V_25 & ~ V_26 ) | V_29 ;
break;
case V_33 :
V_2 -> V_25 = ( V_2 -> V_25 & ~ V_26 ) | V_27 ;
break;
case V_34 :
F_7 ( V_2 , 0x20 ) ;
F_5 ( V_2 , 0x75 ) ;
if ( F_3 ( V_2 ) != 0x75 )
V_2 -> V_25 = ( V_2 -> V_25 & ~ V_26 ) | V_27 ;
else
V_2 -> V_25 = ( V_2 -> V_25 & ~ V_26 ) | V_29 ;
break;
}
F_7 ( V_2 , 0xb ) ;
F_21 ( 250 ) ;
F_7 ( V_2 , 0xe ) ;
F_19 ( V_2 ) ;
}
static void F_22 ( struct V_1 * V_2 )
{
int V_5 ;
int V_35 ;
F_14 ( V_2 , 0xb ) ;
F_14 ( V_2 , V_2 -> V_36 ) ;
V_5 = V_2 -> V_37 / V_2 -> V_23 ;
F_14 ( V_2 , 0x11 ) ;
F_14 ( V_2 , V_5 ) ;
if ( ( V_2 -> V_25 & V_26 ) == V_29 && V_2 -> V_24 == 6 ) {
V_5 = V_2 -> V_38 ;
V_35 = V_2 -> V_23 * 4 ;
} else {
V_5 = V_2 -> V_38 * V_2 -> V_24 ;
V_35 = ( ( ( V_2 -> V_25 & V_26 ) == V_27 ) ? 24 : 8 ) *
V_2 -> V_23 ;
}
V_5 = F_23 ( V_5 , V_35 ) ;
F_14 ( V_2 , 0x13 ) ;
F_14 ( V_2 , V_5 ) ;
F_14 ( V_2 , 0xd ) ;
F_14 ( V_2 , V_2 -> V_39 ) ;
F_14 ( V_2 , 0xf ) ;
F_14 ( V_2 , V_2 -> V_40 / 2 ) ;
F_14 ( V_2 , 0x19 ) ;
F_14 ( V_2 , V_2 -> V_41 ) ;
F_14 ( V_2 , 0x1f ) ;
F_14 ( V_2 , V_2 -> V_42 ) ;
V_2 -> V_6 &= ( ~ V_30 ) ;
}
static inline int F_24 ( struct V_1 * V_2 , char V_43 [] )
{
int V_44 = 1 ;
unsigned int V_45 , V_46 ;
unsigned int V_47 , V_48 ;
static int V_49 ;
if ( V_43 == NULL ) {
V_49 = 0 ;
return 0 ;
}
switch ( V_2 -> V_25 & V_26 ) {
case V_27 :
F_7 ( V_2 , 0x26 ) ;
V_46 = ( F_13 ( V_2 , 1 ) >> 1 ) ;
V_45 = ( F_1 ( V_2 ) >> 3 ) & 0x1f ;
F_7 ( V_2 , 0x2e ) ;
V_48 = ( F_13 ( V_2 , 0 ) >> 1 ) ;
V_47 = ( F_1 ( V_2 ) >> 3 ) & 0x1f ;
switch ( V_2 -> V_24 ) {
case 4 :
V_43 [ 0 ] = V_46 & 0xf ;
V_43 [ 1 ] = ( ( V_46 & 0x70 ) >> 4 ) | ( ( V_45 & 1 ) << 3 ) ;
V_43 [ 2 ] = ( V_45 & 0x1e ) >> 1 ;
V_43 [ 3 ] = V_48 & 0xf ;
V_43 [ 4 ] = ( ( V_48 & 0x70 ) >> 4 ) | ( ( V_47 & 1 ) << 3 ) ;
V_43 [ 5 ] = ( V_47 & 0x1e ) >> 1 ;
V_44 = 6 ;
break;
case 6 :
V_43 [ 0 ] = V_46 & 0x3f ;
V_43 [ 1 ] = ( ( V_46 & 0x40 ) >> 6 ) | ( V_45 << 1 ) ;
V_43 [ 2 ] = V_48 & 0x3f ;
V_43 [ 3 ] = ( ( V_48 & 0x40 ) >> 6 ) | ( V_47 << 1 ) ;
V_44 = 4 ;
break;
}
break;
case V_29 :
F_7 ( V_2 , 6 ) ;
V_46 = ( F_11 ( V_2 , 1 ) & 0xf0 ) >> 4 ;
F_7 ( V_2 , 0xe ) ;
V_45 = ( F_11 ( V_2 , 0 ) & 0xf0 ) >> 4 ;
switch ( V_2 -> V_24 ) {
case 4 :
V_43 [ 0 ] = V_46 ;
V_43 [ 1 ] = V_45 ;
V_44 = 2 ;
break;
case 6 :
switch ( V_49 ) {
case 0 :
V_43 [ 0 ] = ( V_46 << 2 ) | ( ( V_45 & 0xc ) >> 2 ) ;
V_2 -> V_50 = ( V_45 & 3 ) << 4 ;
V_49 = 1 ;
V_44 = 1 ;
break;
case 1 :
V_43 [ 0 ] = V_46 | V_2 -> V_50 ;
V_2 -> V_50 = V_45 << 2 ;
V_49 = 2 ;
V_44 = 1 ;
break;
case 2 :
V_43 [ 0 ] = ( ( V_46 & 0xc ) >> 2 ) | V_2 -> V_50 ;
V_43 [ 1 ] = ( ( V_46 & 3 ) << 4 ) | V_45 ;
V_49 = 0 ;
V_44 = 2 ;
break;
}
break;
}
break;
}
return V_44 ;
}
static long F_25 ( struct V_1 * V_2 , T_1 * V_51 , unsigned long V_52 )
{
int V_16 , V_53 , V_54 , V_55 ;
int V_56 ;
int V_57 , V_58 ;
int V_59 ;
int V_60 ;
int V_61 = 0 ;
int V_62 = 0 ;
char V_43 [ 6 ] ;
int V_63 = 8 - V_2 -> V_24 ;
char V_64 ;
if ( V_2 -> V_22 == - 1 )
return - V_65 ;
F_14 ( V_2 , 0x7 ) ;
F_14 ( V_2 , V_2 -> V_22 ) ;
if ( ( V_2 -> V_25 & V_26 ) == V_27 ) {
F_7 ( V_2 , 0x2e ) ;
F_7 ( V_2 , 0x26 ) ;
F_11 ( V_2 , 1 ) ;
F_7 ( V_2 , 0x2e ) ;
F_11 ( V_2 , 0 ) ;
}
V_64 = ( V_2 -> V_24 == 4 ) ? 16 : 63 ;
V_57 = V_2 -> V_37 / V_2 -> V_23 ;
V_60 = V_2 -> V_38 / V_2 -> V_23 ;
V_58 = V_2 -> V_38 * V_2 -> V_24 ;
V_59 = ( ( ( V_2 -> V_25 & V_26 ) == V_27 ) ? 24 : 8 ) *
V_2 -> V_23 ;
V_58 = F_23 ( V_58 , V_59 ) ;
for ( V_16 = 0 , V_55 = V_66 ; V_16 < V_57 ; V_16 ++ ) {
for ( V_61 = V_53 = 0 ; V_53 < V_58 ; V_53 ++ ) {
V_56 = F_24 ( V_2 , V_43 ) ;
for ( V_54 = 0 ; V_54 < V_56 && ( V_61 + V_54 ) < V_60 ; V_54 ++ ) {
int V_67 ;
if ( V_43 [ V_54 ] == 0 && V_64 == 16 ) {
V_43 [ V_54 ] = 16 ;
}
V_67 = V_16 * V_60 + V_61 + V_54 ;
if ( V_67 < V_52 ) {
T_1 V_68 = V_64 - V_43 [ V_54 ] ;
V_62 ++ ;
V_51 [ V_67 ] = V_68 << V_63 ;
}
}
V_61 += V_56 ;
}
F_24 ( V_2 , NULL ) ;
if ( V_16 >= V_55 ) {
F_12 ( 5 ) ;
V_55 = V_16 + V_66 ;
}
}
if ( ( V_2 -> V_25 & V_26 ) == V_27 ) {
F_7 ( V_2 , 2 ) ;
F_7 ( V_2 , 6 ) ;
F_21 ( 3 ) ;
F_7 ( V_2 , 0xe ) ;
}
if ( V_62 < V_52 )
return V_62 ;
return V_52 ;
}
static int F_26 ( struct V_69 * V_70 , const struct V_71 * V_72 ,
unsigned int * V_73 , unsigned int * V_74 ,
unsigned int V_75 [] , void * V_76 [] )
{
struct V_1 * V_77 = F_27 ( V_70 ) ;
if ( 0 == * V_73 )
* V_73 = 3 ;
* V_74 = 1 ;
F_28 ( & V_77 -> V_78 ) ;
if ( V_72 )
V_75 [ 0 ] = V_72 -> V_72 . V_79 . V_38 * V_72 -> V_72 . V_79 . V_37 ;
else
V_75 [ 0 ] = ( V_77 -> V_38 / V_77 -> V_23 ) *
( V_77 -> V_37 / V_77 -> V_23 ) ;
F_29 ( & V_77 -> V_78 ) ;
return 0 ;
}
static void F_30 ( struct V_80 * V_81 )
{
F_31 ( V_81 , V_82 ) ;
}
static void F_32 ( struct V_80 * V_81 )
{
struct V_1 * V_1 = F_27 ( V_81 -> V_69 ) ;
void * V_83 = F_33 ( V_81 , 0 ) ;
int V_84 = V_81 -> V_69 -> V_85 [ 0 ] ;
int V_52 ;
if ( ! F_34 ( V_81 -> V_69 ) )
return;
F_28 ( & V_1 -> V_78 ) ;
F_35 ( V_1 -> V_86 ) ;
F_20 ( V_1 ) ;
if ( V_1 -> V_6 & V_30 )
F_22 ( V_1 ) ;
V_52 = F_25 ( V_1 , V_83 , V_84 ) ;
F_36 ( V_1 -> V_86 ) ;
F_29 ( & V_1 -> V_78 ) ;
F_37 ( & V_81 -> V_87 . V_88 ) ;
if ( V_52 != V_84 )
V_81 -> V_49 = V_89 ;
F_38 ( V_81 , 0 , V_52 ) ;
}
static int F_39 ( struct V_90 * V_90 , void * V_91 ,
struct V_92 * V_93 )
{
struct V_1 * V_1 = F_40 ( V_90 ) ;
F_41 ( V_93 -> V_94 , V_1 -> V_95 . V_19 , sizeof( V_93 -> V_94 ) ) ;
F_41 ( V_93 -> V_96 , L_3 , sizeof( V_93 -> V_96 ) ) ;
F_41 ( V_93 -> V_97 , V_1 -> V_3 -> V_19 , sizeof( V_93 -> V_97 ) ) ;
V_93 -> V_98 = V_99 | V_100 |
V_101 ;
V_93 -> V_102 = V_93 -> V_98 | V_103 ;
return 0 ;
}
static int F_42 ( struct V_90 * V_90 , void * V_104 , struct V_105 * V_106 )
{
if ( V_106 -> V_107 > 0 )
return - V_108 ;
F_41 ( V_106 -> V_19 , L_4 , sizeof( V_106 -> V_19 ) ) ;
V_106 -> type = V_109 ;
V_106 -> V_110 = 0 ;
V_106 -> V_111 = 0 ;
V_106 -> V_112 = 0 ;
V_106 -> V_6 = 0 ;
return 0 ;
}
static int F_43 ( struct V_90 * V_90 , void * V_104 , unsigned int * V_113 )
{
* V_113 = 0 ;
return 0 ;
}
static int F_44 ( struct V_90 * V_90 , void * V_104 , unsigned int V_113 )
{
return ( V_113 > 0 ) ? - V_108 : 0 ;
}
static int F_45 ( struct V_90 * V_90 , void * V_104 , struct V_71 * V_72 )
{
struct V_1 * V_1 = F_40 ( V_90 ) ;
struct V_114 * V_79 = & V_72 -> V_72 . V_79 ;
V_79 -> V_38 = V_1 -> V_38 / V_1 -> V_23 ;
V_79 -> V_37 = V_1 -> V_37 / V_1 -> V_23 ;
V_79 -> V_115 = ( V_1 -> V_24 == 4 ) ? V_116 : V_117 ;
V_79 -> V_118 = V_119 ;
V_79 -> V_120 = V_79 -> V_38 ;
V_79 -> V_121 = V_79 -> V_38 * V_79 -> V_37 ;
V_79 -> V_122 = V_123 ;
V_79 -> V_91 = 0 ;
return 0 ;
}
static int F_46 ( struct V_90 * V_90 , void * V_104 , struct V_71 * V_72 )
{
struct V_114 * V_79 = & V_72 -> V_72 . V_79 ;
if ( V_79 -> V_37 <= 60 || V_79 -> V_38 <= 80 ) {
V_79 -> V_37 = 60 ;
V_79 -> V_38 = 80 ;
} else if ( V_79 -> V_37 <= 120 || V_79 -> V_38 <= 160 ) {
V_79 -> V_37 = 120 ;
V_79 -> V_38 = 160 ;
} else {
V_79 -> V_37 = 240 ;
V_79 -> V_38 = 320 ;
}
if ( V_79 -> V_115 != V_116 &&
V_79 -> V_115 != V_117 )
V_79 -> V_115 = V_116 ;
V_79 -> V_118 = V_119 ;
V_79 -> V_120 = V_79 -> V_38 ;
V_79 -> V_121 = V_79 -> V_38 * V_79 -> V_37 ;
V_79 -> V_122 = V_123 ;
V_79 -> V_91 = 0 ;
return 0 ;
}
static int F_47 ( struct V_90 * V_90 , void * V_104 , struct V_71 * V_72 )
{
struct V_1 * V_1 = F_40 ( V_90 ) ;
struct V_114 * V_79 = & V_72 -> V_72 . V_79 ;
int V_44 = F_46 ( V_90 , V_104 , V_72 ) ;
if ( V_44 )
return V_44 ;
if ( F_48 ( & V_1 -> V_124 ) )
return - V_125 ;
V_1 -> V_38 = 320 ;
V_1 -> V_37 = 240 ;
if ( V_79 -> V_37 == 60 )
V_1 -> V_23 = 4 ;
else if ( V_79 -> V_37 == 120 )
V_1 -> V_23 = 2 ;
else
V_1 -> V_23 = 1 ;
if ( V_79 -> V_115 == V_117 )
V_1 -> V_24 = 6 ;
else
V_1 -> V_24 = 4 ;
F_19 ( V_1 ) ;
V_1 -> V_6 |= V_30 ;
return 0 ;
}
static int F_49 ( struct V_90 * V_90 , void * V_104 , struct V_126 * V_72 )
{
static struct V_126 V_127 [] = {
{ 0 , 0 , 0 ,
L_5 , V_116 ,
{ 0 , 0 , 0 , 0 }
} ,
{ 1 , 0 , 0 ,
L_6 , V_117 ,
{ 0 , 0 , 0 , 0 }
} ,
} ;
enum V_128 type = V_72 -> type ;
if ( V_72 -> V_107 > 1 )
return - V_108 ;
* V_72 = V_127 [ V_72 -> V_107 ] ;
V_72 -> type = type ;
return 0 ;
}
static int F_50 ( struct V_90 * V_90 , void * V_104 ,
struct V_129 * V_130 )
{
static const struct V_131 V_75 [] = {
{ 80 , 60 } ,
{ 160 , 120 } ,
{ 320 , 240 } ,
} ;
if ( V_130 -> V_107 > 2 )
return - V_108 ;
if ( V_130 -> V_132 != V_116 &&
V_130 -> V_132 != V_117 )
return - V_108 ;
V_130 -> type = V_133 ;
V_130 -> V_134 = V_75 [ V_130 -> V_107 ] ;
return 0 ;
}
static int F_51 ( struct V_135 * V_136 )
{
struct V_1 * V_1 =
F_52 ( V_136 -> V_137 , struct V_1 , V_138 ) ;
int V_44 = 0 ;
switch ( V_136 -> V_139 ) {
case V_140 :
V_1 -> V_36 = V_136 -> V_5 ;
break;
case V_141 :
V_1 -> V_41 = V_136 -> V_5 ;
break;
case V_142 :
V_1 -> V_42 = V_136 -> V_5 ;
break;
default:
V_44 = - V_108 ;
break;
}
if ( V_44 == 0 )
V_1 -> V_6 |= V_30 ;
return V_44 ;
}
static struct V_1 * F_53 ( struct V_143 * V_144 )
{
struct V_1 * V_1 ;
struct V_145 * V_95 ;
struct V_69 * V_2 ;
int V_146 ;
V_1 = F_54 ( sizeof( struct V_1 ) , V_147 ) ;
if ( V_1 == NULL )
return NULL ;
V_95 = & V_1 -> V_95 ;
snprintf ( V_95 -> V_19 , sizeof( V_95 -> V_19 ) , L_7 , V_148 ) ;
if ( F_55 ( V_144 -> V_77 , V_95 ) < 0 ) {
F_56 ( V_95 , L_8 ) ;
F_57 ( V_1 ) ;
return NULL ;
}
F_58 ( & V_1 -> V_138 , 3 ) ;
F_59 ( & V_1 -> V_138 , & V_149 ,
V_140 , 0 , 255 , 1 , 180 ) ;
F_59 ( & V_1 -> V_138 , & V_149 ,
V_141 , 0 , 255 , 1 , 192 ) ;
F_59 ( & V_1 -> V_138 , & V_149 ,
V_142 , 0 , 255 , 1 , 105 ) ;
if ( V_1 -> V_138 . error ) {
F_56 ( V_95 , L_9 ) ;
goto exit;
}
F_60 ( & V_1 -> V_78 ) ;
F_60 ( & V_1 -> V_150 ) ;
V_2 = & V_1 -> V_124 ;
V_2 -> type = V_151 ;
V_2 -> V_152 = V_153 | V_154 | V_155 ;
V_2 -> V_156 = V_1 ;
V_2 -> V_157 = & V_158 ;
V_2 -> V_159 = & V_160 ;
V_2 -> V_161 = V_162 ;
V_146 = F_61 ( V_2 ) ;
if ( V_146 < 0 ) {
F_56 ( V_95 , L_10 , V_144 -> V_19 ) ;
goto exit;
}
V_1 -> V_163 . V_164 = V_2 ;
V_1 -> V_163 . V_164 -> V_78 = & V_1 -> V_150 ;
V_1 -> V_3 = V_144 ;
V_1 -> V_86 = F_62 ( V_144 , V_95 -> V_19 , NULL , NULL ,
NULL , 0 , NULL ) ;
if ( V_1 -> V_86 == NULL ) {
F_56 ( V_95 , L_11 , V_144 -> V_19 ) ;
goto exit;
}
F_41 ( V_1 -> V_163 . V_19 , L_12 , sizeof( V_1 -> V_163 . V_19 ) ) ;
V_1 -> V_163 . V_95 = V_95 ;
V_1 -> V_163 . V_165 = & V_1 -> V_138 ;
V_1 -> V_163 . V_166 = & V_167 ;
V_1 -> V_163 . V_78 = & V_1 -> V_78 ;
V_1 -> V_163 . V_168 = & V_169 ;
F_63 ( V_170 , & V_1 -> V_163 . V_171 ) ;
V_1 -> V_163 . V_172 = V_173 ;
F_64 ( & V_1 -> V_163 , V_1 ) ;
V_1 -> V_25 = ( V_34 | V_28 ) ;
V_1 -> V_38 = 320 ;
V_1 -> V_37 = 240 ;
V_1 -> V_24 = 4 ;
V_1 -> V_23 = 2 ;
V_1 -> V_41 = 192 ;
V_1 -> V_36 = 180 ;
V_1 -> V_42 = 105 ;
V_1 -> V_39 = 1 ;
V_1 -> V_40 = 14 ;
V_1 -> V_22 = - 1 ;
V_1 -> V_6 = V_30 ;
return V_1 ;
exit:
F_65 ( & V_1 -> V_138 ) ;
F_57 ( V_1 ) ;
return NULL ;
}
static int F_66 ( struct V_1 * V_2 )
{
int V_174 ;
int V_15 = 0 ;
F_14 ( V_2 , 27 ) ;
F_14 ( V_2 , 0 ) ;
do {
F_14 ( V_2 , 33 ) ;
V_174 = F_15 ( V_2 ) ;
F_17 ( 1 ) ;
F_67 () ;
V_15 ++ ;
} while ( V_174 == 0xff && V_15 < 2048 );
V_2 -> V_42 = V_174 ;
return V_174 ;
}
static int F_68 ( struct V_143 * V_144 )
{
struct V_1 * V_1 ;
if ( V_148 == V_175 ) {
F_18 ( V_18 L_13 , V_175 ) ;
return - V_176 ;
}
V_1 = F_53 ( V_144 ) ;
if ( V_1 == NULL )
return - V_177 ;
F_35 ( V_1 -> V_86 ) ;
F_20 ( V_1 ) ;
if ( F_16 ( V_1 ) == 0 ) {
F_36 ( V_1 -> V_86 ) ;
F_69 ( V_1 -> V_86 ) ;
F_57 ( V_1 ) ;
return - V_177 ;
}
F_66 ( V_1 ) ;
F_70 ( & V_1 -> V_138 ) ;
F_36 ( V_1 -> V_86 ) ;
F_71 ( & V_1 -> V_95 , L_14 , V_1 -> V_3 -> V_19 ) ;
if ( F_72 ( & V_1 -> V_163 , V_178 , V_179 ) < 0 ) {
F_69 ( V_1 -> V_86 ) ;
F_57 ( V_1 ) ;
return - V_177 ;
}
V_180 [ V_148 ++ ] = V_1 ;
return 0 ;
}
static void F_73 ( struct V_1 * V_1 )
{
F_74 ( & V_1 -> V_163 ) ;
F_65 ( & V_1 -> V_138 ) ;
F_69 ( V_1 -> V_86 ) ;
F_57 ( V_1 ) ;
}
static int F_75 ( struct V_143 * V_144 )
{
#ifdef F_76
int V_181 ;
if ( V_143 [ 0 ] && strncmp ( V_143 [ 0 ] , L_15 , 4 ) != 0 ) {
for ( V_181 = 0 ; V_181 < V_175 && V_143 [ V_181 ] ; V_181 ++ ) {
char * V_182 ;
unsigned long V_183 ;
V_183 = F_77 ( V_143 [ V_181 ] , & V_182 , 0 ) ;
if ( V_182 == V_143 [ V_181 ] ) {
F_18 ( V_18
L_16 ,
V_143 [ V_181 ] ) ;
continue;
}
if ( V_183 == V_144 -> V_184 )
return 1 ;
}
return 0 ;
}
#endif
return 1 ;
}
static void F_78 ( struct V_143 * V_144 )
{
if ( F_75 ( V_144 ) )
F_68 ( V_144 ) ;
}
static void F_79 ( struct V_143 * V_144 )
{
int V_16 ;
for ( V_16 = 0 ; V_16 < V_148 ; V_16 ++ ) {
struct V_1 * V_1 = V_180 [ V_16 ] ;
if ( V_1 && V_1 -> V_86 -> V_144 == V_144 ) {
V_180 [ V_16 ] = NULL ;
F_73 ( V_1 ) ;
}
}
}
static void T_2 F_80 ( void )
{
F_81 ( & V_185 ) ;
}
static int T_3 F_82 ( void )
{
#ifdef F_76
if ( V_8 > 5000 ) {
F_18 ( V_186 L_17 ) ;
V_8 = 5000 ;
}
if ( V_66 < 1 ) {
F_18 ( V_186 L_18 ) ;
V_66 = 1 ;
}
#endif
return F_83 ( & V_185 ) ;
}
