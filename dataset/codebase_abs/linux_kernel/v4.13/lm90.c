static inline T_1 F_1 ( struct V_1 * V_2 , T_2 V_3 )
{
return F_2 ( V_2 -> V_4 , V_2 -> V_5 ,
V_2 -> V_6 & ~ V_7 ,
V_8 , V_3 , V_9 , NULL ) ;
}
static int F_3 ( struct V_1 * V_2 , T_2 V_10 )
{
int V_11 ;
if ( V_2 -> V_6 & V_7 ) {
V_11 = F_1 ( V_2 , V_10 ) ;
if ( V_11 >= 0 )
V_11 = F_4 ( V_2 ) ;
} else
V_11 = F_5 ( V_2 , V_10 ) ;
return V_11 ;
}
static int F_6 ( struct V_1 * V_2 , T_2 V_12 , T_2 V_13 )
{
int V_14 , V_15 , V_16 ;
V_14 = F_3 ( V_2 , V_12 ) ;
if ( V_14 < 0 )
return V_14 ;
V_16 = F_3 ( V_2 , V_13 ) ;
if ( V_16 < 0 )
return V_16 ;
V_15 = F_3 ( V_2 , V_12 ) ;
if ( V_15 < 0 )
return V_15 ;
if ( V_14 != V_15 ) {
V_16 = F_3 ( V_2 , V_13 ) ;
if ( V_16 < 0 )
return V_16 ;
}
return ( V_15 << 8 ) | V_16 ;
}
static inline int F_7 ( struct V_1 * V_2 ,
struct V_17 * V_18 ,
int V_19 )
{
int V_20 ;
if ( V_18 -> V_21 == V_22 ) {
V_20 = F_3 ( V_2 , V_23 ) ;
if ( V_20 < 0 )
return V_20 ;
V_20 &= ~ 0x08 ;
if ( V_19 )
V_20 |= 0x08 ;
F_8 ( V_2 , V_24 ,
V_20 ) ;
}
return 0 ;
}
static int F_9 ( struct V_1 * V_2 , struct V_17 * V_18 ,
unsigned int V_25 )
{
unsigned int V_26 ;
int V_27 , V_11 ;
V_25 <<= 6 ;
for ( V_27 = 0 , V_26 = V_28 << 6 ;
V_27 < V_18 -> V_29 ; V_27 ++ , V_26 >>= 1 )
if ( V_25 >= V_26 * 3 / 4 )
break;
V_11 = F_8 ( V_2 , V_30 , V_27 ) ;
V_18 -> V_26 = F_10 ( V_26 , 64 ) ;
return V_11 ;
}
static int F_11 ( struct V_31 * V_32 )
{
struct V_17 * V_18 = F_12 ( V_32 ) ;
struct V_1 * V_2 = V_18 -> V_2 ;
int V_33 ;
V_33 = F_3 ( V_2 , V_34 ) ;
if ( V_33 < 0 )
return V_33 ;
V_18 -> V_35 [ V_36 ] = V_33 ;
V_33 = F_3 ( V_2 , V_37 ) ;
if ( V_33 < 0 )
return V_33 ;
V_18 -> V_35 [ V_38 ] = V_33 ;
V_33 = F_3 ( V_2 , V_39 ) ;
if ( V_33 < 0 )
return V_33 ;
V_18 -> V_40 = V_33 ;
V_33 = F_3 ( V_2 , V_41 ) ;
if ( V_33 < 0 )
return V_33 ;
V_18 -> V_42 [ V_43 ] = V_33 << 8 ;
if ( V_18 -> V_6 & V_44 ) {
V_33 = F_3 ( V_2 , V_45 ) ;
if ( V_33 < 0 )
return V_33 ;
V_18 -> V_42 [ V_43 ] |= V_33 ;
}
V_33 = F_3 ( V_2 , V_46 ) ;
if ( V_33 < 0 )
return V_33 ;
V_18 -> V_42 [ V_47 ] = V_33 << 8 ;
if ( V_18 -> V_6 & V_44 ) {
V_33 = F_3 ( V_2 , V_48 ) ;
if ( V_33 < 0 )
return V_33 ;
V_18 -> V_42 [ V_47 ] |= V_33 ;
}
if ( V_18 -> V_6 & V_49 ) {
V_33 = F_6 ( V_2 , V_50 ,
V_51 ) ;
if ( V_33 < 0 )
return V_33 ;
V_18 -> V_42 [ V_52 ] = V_33 ;
}
if ( V_18 -> V_6 & V_53 ) {
V_33 = F_3 ( V_2 , V_54 ) ;
if ( V_33 < 0 )
return V_33 ;
V_18 -> V_35 [ V_55 ] = V_33 ;
V_33 = F_3 ( V_2 , V_56 ) ;
if ( V_33 < 0 )
return V_33 ;
V_18 -> V_35 [ V_57 ] = V_33 ;
}
if ( V_18 -> V_21 == V_22 ) {
V_33 = F_7 ( V_2 , V_18 , 1 ) ;
if ( V_33 < 0 )
return V_33 ;
V_33 = F_3 ( V_2 , V_37 ) ;
if ( V_33 < 0 )
return V_33 ;
V_18 -> V_35 [ V_58 ] = V_33 ;
V_33 = F_3 ( V_2 , V_56 ) ;
if ( V_33 < 0 )
return V_33 ;
V_18 -> V_35 [ V_59 ] = V_33 ;
V_33 = F_3 ( V_2 , V_41 ) ;
if ( V_33 < 0 )
return V_33 ;
V_18 -> V_42 [ V_60 ] = V_33 << 8 ;
V_33 = F_3 ( V_2 , V_46 ) ;
if ( V_33 < 0 )
return V_33 ;
V_18 -> V_42 [ V_61 ] = V_33 << 8 ;
F_7 ( V_2 , V_18 , 0 ) ;
}
return 0 ;
}
static int F_13 ( struct V_31 * V_32 )
{
struct V_17 * V_18 = F_12 ( V_32 ) ;
struct V_1 * V_2 = V_18 -> V_2 ;
unsigned long V_62 ;
int V_33 ;
if ( ! V_18 -> V_63 ) {
V_33 = F_11 ( V_32 ) ;
if ( V_33 < 0 )
return V_33 ;
}
V_62 = V_18 -> V_64 +
F_14 ( V_18 -> V_26 ) ;
if ( F_15 ( V_65 , V_62 ) || ! V_18 -> V_63 ) {
F_16 ( & V_2 -> V_32 , L_1 ) ;
V_18 -> V_63 = false ;
V_33 = F_3 ( V_2 , V_66 ) ;
if ( V_33 < 0 )
return V_33 ;
V_18 -> V_35 [ V_67 ] = V_33 ;
V_33 = F_3 ( V_2 , V_68 ) ;
if ( V_33 < 0 )
return V_33 ;
V_18 -> V_35 [ V_69 ] = V_33 ;
if ( V_18 -> V_70 ) {
V_33 = F_6 ( V_2 , V_71 ,
V_18 -> V_70 ) ;
if ( V_33 < 0 )
return V_33 ;
V_18 -> V_42 [ V_72 ] = V_33 ;
} else {
V_33 = F_3 ( V_2 , V_71 ) ;
if ( V_33 < 0 )
return V_33 ;
V_18 -> V_42 [ V_72 ] = V_33 << 8 ;
}
V_33 = F_6 ( V_2 , V_73 ,
V_74 ) ;
if ( V_33 < 0 )
return V_33 ;
V_18 -> V_42 [ V_75 ] = V_33 ;
V_33 = F_3 ( V_2 , V_76 ) ;
if ( V_33 < 0 )
return V_33 ;
V_18 -> V_77 = V_33 ;
if ( V_18 -> V_21 == V_22 ) {
V_33 = F_7 ( V_2 , V_18 , 1 ) ;
if ( V_33 < 0 )
return V_33 ;
V_33 = F_6 ( V_2 , V_73 ,
V_74 ) ;
if ( V_33 < 0 ) {
F_7 ( V_2 , V_18 , 0 ) ;
return V_33 ;
}
V_18 -> V_42 [ V_78 ] = V_33 ;
F_7 ( V_2 , V_18 , 0 ) ;
V_33 = F_3 ( V_2 , V_79 ) ;
if ( V_33 < 0 )
return V_33 ;
V_18 -> V_77 |= V_33 << 8 ;
}
if ( ! ( V_18 -> V_80 & 0x80 ) &&
! ( V_18 -> V_77 & V_18 -> V_81 ) ) {
V_33 = F_3 ( V_2 , V_23 ) ;
if ( V_33 < 0 )
return V_33 ;
if ( V_33 & 0x80 ) {
F_16 ( & V_2 -> V_32 , L_2 ) ;
F_8 ( V_2 ,
V_24 ,
V_33 & ~ 0x80 ) ;
}
}
V_18 -> V_64 = V_65 ;
V_18 -> V_63 = true ;
}
return 0 ;
}
static inline int F_17 ( T_3 V_33 )
{
return V_33 * 1000 ;
}
static inline int F_18 ( T_2 V_33 )
{
return V_33 * 1000 ;
}
static inline int F_19 ( T_4 V_33 )
{
return V_33 / 32 * 125 ;
}
static inline int F_20 ( T_5 V_33 )
{
return V_33 / 32 * 125 ;
}
static T_3 F_21 ( long V_33 )
{
if ( V_33 <= - 128000 )
return - 128 ;
if ( V_33 >= 127000 )
return 127 ;
if ( V_33 < 0 )
return ( V_33 - 500 ) / 1000 ;
return ( V_33 + 500 ) / 1000 ;
}
static T_2 F_22 ( long V_33 )
{
if ( V_33 <= 0 )
return 0 ;
if ( V_33 >= 255000 )
return 255 ;
return ( V_33 + 500 ) / 1000 ;
}
static T_4 F_23 ( long V_33 )
{
if ( V_33 <= - 128000 )
return 0x8000 ;
if ( V_33 >= 127875 )
return 0x7FE0 ;
if ( V_33 < 0 )
return ( V_33 - 62 ) / 125 * 32 ;
return ( V_33 + 62 ) / 125 * 32 ;
}
static T_2 F_24 ( long V_33 )
{
if ( V_33 <= 0 )
return 0 ;
if ( V_33 >= 30500 )
return 31 ;
return ( V_33 + 500 ) / 1000 ;
}
static inline int F_25 ( struct V_17 * V_18 , T_2 V_33 )
{
if ( V_18 -> V_6 & V_82 )
return ( V_33 - 64 ) * 1000 ;
return F_17 ( V_33 ) ;
}
static inline int F_26 ( struct V_17 * V_18 , T_5 V_33 )
{
if ( V_18 -> V_6 & V_82 )
return ( V_33 - 0x4000 ) / 64 * 250 ;
return F_19 ( V_33 ) ;
}
static T_2 F_27 ( struct V_17 * V_18 , long V_33 )
{
if ( V_18 -> V_6 & V_82 ) {
if ( V_33 <= - 64000 )
return 0 ;
if ( V_33 >= 191000 )
return 0xFF ;
return ( V_33 + 500 + 64000 ) / 1000 ;
}
if ( V_33 <= 0 )
return 0 ;
if ( V_33 >= 127000 )
return 127 ;
return ( V_33 + 500 ) / 1000 ;
}
static T_5 F_28 ( struct V_17 * V_18 , long V_33 )
{
if ( V_18 -> V_6 & V_82 ) {
if ( V_33 <= - 64000 )
return 0 ;
if ( V_33 >= 191750 )
return 0xFFC0 ;
return ( V_33 + 64000 + 125 ) / 250 * 64 ;
}
if ( V_33 <= 0 )
return 0 ;
if ( V_33 >= 127750 )
return 0x7FC0 ;
return ( V_33 + 125 ) / 250 * 64 ;
}
static T_6 F_29 ( struct V_31 * V_32 , struct V_83 * V_84 ,
char * V_85 )
{
struct V_1 * V_2 = F_30 ( V_32 ) ;
return sprintf ( V_85 , L_3 , ! ! ( V_2 -> V_6 & V_7 ) ) ;
}
static T_6 F_31 ( struct V_31 * V_32 , struct V_83 * V_84 ,
const char * V_85 , T_7 V_86 )
{
struct V_1 * V_2 = F_30 ( V_32 ) ;
long V_33 ;
int V_11 ;
V_11 = F_32 ( V_85 , 10 , & V_33 ) ;
if ( V_11 < 0 )
return V_11 ;
switch ( V_33 ) {
case 0 :
V_2 -> V_6 &= ~ V_7 ;
break;
case 1 :
V_2 -> V_6 |= V_7 ;
break;
default:
return - V_87 ;
}
return V_86 ;
}
static int F_33 ( struct V_17 * V_18 , int V_88 )
{
T_4 V_42 = V_18 -> V_42 [ V_88 ] ;
int V_89 ;
if ( V_18 -> V_21 == V_90 || V_18 -> V_21 == V_91 )
V_89 = F_26 ( V_18 , V_42 ) ;
else if ( V_18 -> V_21 == V_92 )
V_89 = F_20 ( V_42 ) ;
else
V_89 = F_19 ( V_42 ) ;
if ( V_18 -> V_21 == V_93 && V_88 <= 2 )
V_89 += 16000 ;
return V_89 ;
}
static int F_34 ( struct V_17 * V_18 , int V_88 , long V_33 )
{
static struct V_10 {
T_2 V_94 ;
T_2 V_95 ;
} V_10 [] = {
[ V_43 ] = { V_96 , V_97 } ,
[ V_47 ] = { V_98 , V_99 } ,
[ V_52 ] = { V_100 , V_101 } ,
[ V_60 ] = { V_96 , V_97 } ,
[ V_61 ] = { V_98 , V_99 }
} ;
struct V_1 * V_2 = V_18 -> V_2 ;
struct V_10 * V_102 = & V_10 [ V_88 ] ;
int V_11 ;
if ( V_18 -> V_21 == V_93 && V_88 <= 2 )
V_33 -= 16000 ;
if ( V_18 -> V_21 == V_90 || V_18 -> V_21 == V_91 )
V_18 -> V_42 [ V_88 ] = F_28 ( V_18 , V_33 ) ;
else if ( V_18 -> V_21 == V_92 )
V_18 -> V_42 [ V_88 ] = F_22 ( V_33 ) << 8 ;
else if ( V_18 -> V_6 & V_44 )
V_18 -> V_42 [ V_88 ] = F_23 ( V_33 ) ;
else
V_18 -> V_42 [ V_88 ] = F_21 ( V_33 ) << 8 ;
F_7 ( V_2 , V_18 , V_88 >= 3 ) ;
V_11 = F_8 ( V_2 , V_102 -> V_94 ,
V_18 -> V_42 [ V_88 ] >> 8 ) ;
if ( V_11 < 0 )
return V_11 ;
if ( V_18 -> V_6 & V_44 )
V_11 = F_8 ( V_2 , V_102 -> V_95 ,
V_18 -> V_42 [ V_88 ] & 0xff ) ;
F_7 ( V_2 , V_18 , 0 ) ;
return V_11 ;
}
static int F_35 ( struct V_17 * V_18 , int V_88 )
{
T_3 V_35 = V_18 -> V_35 [ V_88 ] ;
int V_89 ;
if ( V_18 -> V_21 == V_90 || V_18 -> V_21 == V_91 )
V_89 = F_25 ( V_18 , V_35 ) ;
else if ( V_18 -> V_21 == V_92 )
V_89 = F_18 ( V_35 ) ;
else
V_89 = F_17 ( V_35 ) ;
if ( V_18 -> V_21 == V_93 && V_88 == 3 )
V_89 += 16000 ;
return V_89 ;
}
static int F_36 ( struct V_17 * V_18 , int V_88 , long V_33 )
{
static const T_2 V_10 [ V_103 ] = {
V_104 ,
V_105 ,
V_106 ,
V_107 ,
V_108 ,
V_109 ,
V_107 ,
V_109 ,
} ;
struct V_1 * V_2 = V_18 -> V_2 ;
int V_11 ;
if ( V_18 -> V_21 == V_93 && V_88 == 3 )
V_33 -= 16000 ;
if ( V_18 -> V_21 == V_90 || V_18 -> V_21 == V_91 )
V_18 -> V_35 [ V_88 ] = F_27 ( V_18 , V_33 ) ;
else if ( V_18 -> V_21 == V_92 )
V_18 -> V_35 [ V_88 ] = F_22 ( V_33 ) ;
else
V_18 -> V_35 [ V_88 ] = F_21 ( V_33 ) ;
F_7 ( V_2 , V_18 , V_88 >= 6 ) ;
V_11 = F_8 ( V_2 , V_10 [ V_88 ] , V_18 -> V_35 [ V_88 ] ) ;
F_7 ( V_2 , V_18 , 0 ) ;
return V_11 ;
}
static int F_37 ( struct V_17 * V_18 , int V_88 )
{
int V_89 ;
if ( V_18 -> V_21 == V_90 || V_18 -> V_21 == V_91 )
V_89 = F_25 ( V_18 , V_18 -> V_35 [ V_88 ] ) ;
else if ( V_18 -> V_21 == V_92 )
V_89 = F_18 ( V_18 -> V_35 [ V_88 ] ) ;
else
V_89 = F_17 ( V_18 -> V_35 [ V_88 ] ) ;
if ( V_18 -> V_21 == V_93 && V_88 == 3 )
V_89 += 16000 ;
return V_89 - F_17 ( V_18 -> V_40 ) ;
}
static int F_38 ( struct V_17 * V_18 , long V_33 )
{
struct V_1 * V_2 = V_18 -> V_2 ;
int V_89 ;
int V_11 ;
if ( V_18 -> V_21 == V_90 || V_18 -> V_21 == V_91 )
V_89 = F_25 ( V_18 , V_18 -> V_35 [ V_36 ] ) ;
else if ( V_18 -> V_21 == V_92 )
V_89 = F_18 ( V_18 -> V_35 [ V_36 ] ) ;
else
V_89 = F_17 ( V_18 -> V_35 [ V_36 ] ) ;
V_18 -> V_40 = F_24 ( V_89 - V_33 ) ;
V_11 = F_8 ( V_2 , V_110 ,
V_18 -> V_40 ) ;
return V_11 ;
}
static int F_39 ( struct V_31 * V_32 , T_8 V_111 , int V_19 , long * V_33 )
{
struct V_17 * V_18 = F_12 ( V_32 ) ;
int V_11 ;
F_40 ( & V_18 -> V_112 ) ;
V_11 = F_13 ( V_32 ) ;
F_41 ( & V_18 -> V_112 ) ;
if ( V_11 )
return V_11 ;
switch ( V_111 ) {
case V_113 :
* V_33 = F_33 ( V_18 , V_114 [ V_19 ] ) ;
break;
case V_115 :
* V_33 = ( V_18 -> V_77 >> V_116 [ V_19 ] ) & 1 ;
break;
case V_117 :
* V_33 = ( V_18 -> V_77 >> V_118 [ V_19 ] ) & 1 ;
break;
case V_119 :
* V_33 = ( V_18 -> V_77 >> V_120 [ V_19 ] ) & 1 ;
break;
case V_121 :
* V_33 = ( V_18 -> V_77 >> V_122 [ V_19 ] ) & 1 ;
break;
case V_123 :
* V_33 = ( V_18 -> V_77 >> V_124 [ V_19 ] ) & 1 ;
break;
case V_125 :
if ( V_19 == 0 )
* V_33 = F_35 ( V_18 ,
V_126 [ V_19 ] ) ;
else
* V_33 = F_33 ( V_18 ,
V_126 [ V_19 ] ) ;
break;
case V_127 :
if ( V_19 == 0 )
* V_33 = F_35 ( V_18 ,
V_128 [ V_19 ] ) ;
else
* V_33 = F_33 ( V_18 ,
V_128 [ V_19 ] ) ;
break;
case V_129 :
* V_33 = F_35 ( V_18 , V_130 [ V_19 ] ) ;
break;
case V_131 :
* V_33 = F_37 ( V_18 , V_130 [ V_19 ] ) ;
break;
case V_132 :
* V_33 = F_35 ( V_18 , V_133 [ V_19 ] ) ;
break;
case V_134 :
* V_33 = F_37 ( V_18 , V_133 [ V_19 ] ) ;
break;
case V_135 :
* V_33 = F_33 ( V_18 , V_52 ) ;
break;
default:
return - V_136 ;
}
return 0 ;
}
static int F_42 ( struct V_31 * V_32 , T_8 V_111 , int V_19 , long V_33 )
{
struct V_17 * V_18 = F_12 ( V_32 ) ;
int V_11 ;
F_40 ( & V_18 -> V_112 ) ;
V_11 = F_13 ( V_32 ) ;
if ( V_11 )
goto error;
switch ( V_111 ) {
case V_125 :
if ( V_19 == 0 )
V_11 = F_36 ( V_18 ,
V_126 [ V_19 ] ,
V_33 ) ;
else
V_11 = F_34 ( V_18 ,
V_126 [ V_19 ] ,
V_33 ) ;
break;
case V_127 :
if ( V_19 == 0 )
V_11 = F_36 ( V_18 ,
V_128 [ V_19 ] ,
V_33 ) ;
else
V_11 = F_34 ( V_18 ,
V_128 [ V_19 ] ,
V_33 ) ;
break;
case V_129 :
V_11 = F_36 ( V_18 , V_130 [ V_19 ] , V_33 ) ;
break;
case V_131 :
V_11 = F_38 ( V_18 , V_33 ) ;
break;
case V_132 :
V_11 = F_36 ( V_18 , V_133 [ V_19 ] , V_33 ) ;
break;
case V_135 :
V_11 = F_34 ( V_18 , V_52 , V_33 ) ;
break;
default:
V_11 = - V_136 ;
break;
}
error:
F_41 ( & V_18 -> V_112 ) ;
return V_11 ;
}
static T_9 F_43 ( const void * V_18 , T_8 V_111 , int V_19 )
{
switch ( V_111 ) {
case V_113 :
case V_115 :
case V_117 :
case V_119 :
case V_121 :
case V_134 :
case V_123 :
return V_137 ;
case V_125 :
case V_127 :
case V_129 :
case V_132 :
case V_135 :
return V_137 | V_138 ;
case V_131 :
if ( V_19 == 0 )
return V_137 | V_138 ;
return V_137 ;
default:
return 0 ;
}
}
static int F_44 ( struct V_31 * V_32 , T_8 V_111 , int V_19 , long * V_33 )
{
struct V_17 * V_18 = F_12 ( V_32 ) ;
int V_11 ;
F_40 ( & V_18 -> V_112 ) ;
V_11 = F_13 ( V_32 ) ;
F_41 ( & V_18 -> V_112 ) ;
if ( V_11 )
return V_11 ;
switch ( V_111 ) {
case V_139 :
* V_33 = V_18 -> V_26 ;
break;
case V_140 :
* V_33 = V_18 -> V_77 ;
break;
default:
return - V_136 ;
}
return 0 ;
}
static int F_45 ( struct V_31 * V_32 , T_8 V_111 , int V_19 , long V_33 )
{
struct V_17 * V_18 = F_12 ( V_32 ) ;
struct V_1 * V_2 = V_18 -> V_2 ;
int V_11 ;
F_40 ( & V_18 -> V_112 ) ;
V_11 = F_13 ( V_32 ) ;
if ( V_11 )
goto error;
switch ( V_111 ) {
case V_139 :
V_11 = F_9 ( V_2 , V_18 ,
F_46 ( V_33 , 0 , 100000 ) ) ;
break;
default:
V_11 = - V_136 ;
break;
}
error:
F_41 ( & V_18 -> V_112 ) ;
return V_11 ;
}
static T_9 F_47 ( const void * V_18 , T_8 V_111 , int V_19 )
{
switch ( V_111 ) {
case V_139 :
return V_137 | V_138 ;
case V_140 :
return V_137 ;
default:
return 0 ;
}
}
static int F_48 ( struct V_31 * V_32 , enum V_141 type ,
T_8 V_111 , int V_19 , long * V_33 )
{
switch ( type ) {
case V_142 :
return F_44 ( V_32 , V_111 , V_19 , V_33 ) ;
case V_143 :
return F_39 ( V_32 , V_111 , V_19 , V_33 ) ;
default:
return - V_136 ;
}
}
static int F_49 ( struct V_31 * V_32 , enum V_141 type ,
T_8 V_111 , int V_19 , long V_33 )
{
switch ( type ) {
case V_142 :
return F_45 ( V_32 , V_111 , V_19 , V_33 ) ;
case V_143 :
return F_42 ( V_32 , V_111 , V_19 , V_33 ) ;
default:
return - V_136 ;
}
}
static T_9 F_50 ( const void * V_18 , enum V_141 type ,
T_8 V_111 , int V_19 )
{
switch ( type ) {
case V_142 :
return F_47 ( V_18 , V_111 , V_19 ) ;
case V_143 :
return F_43 ( V_18 , V_111 , V_19 ) ;
default:
return 0 ;
}
}
static int F_51 ( struct V_1 * V_2 ,
struct V_144 * V_145 )
{
struct V_146 * V_4 = V_2 -> V_4 ;
int V_147 = V_2 -> V_5 ;
const char * V_148 = NULL ;
int V_149 , V_150 , V_151 , V_152 , V_153 ;
if ( ! F_52 ( V_4 , V_154 ) )
return - V_155 ;
V_149 = F_5 ( V_2 , V_156 ) ;
V_150 = F_5 ( V_2 , V_157 ) ;
V_151 = F_5 ( V_2 , V_23 ) ;
V_153 = F_5 ( V_2 , V_158 ) ;
if ( V_149 < 0 || V_150 < 0 || V_151 < 0 || V_153 < 0 )
return - V_155 ;
if ( V_149 == 0x01 || V_149 == 0x5C || V_149 == 0x41 ) {
V_152 = F_5 ( V_2 , V_159 ) ;
if ( V_152 < 0 )
return - V_155 ;
} else
V_152 = 0 ;
if ( ( V_147 == 0x4C || V_147 == 0x4D )
&& V_149 == 0x01 ) {
if ( ( V_151 & 0x2A ) == 0x00
&& ( V_152 & 0xF8 ) == 0x00
&& V_153 <= 0x09 ) {
if ( V_147 == 0x4C
&& ( V_150 & 0xF0 ) == 0x20 ) {
V_148 = L_4 ;
} else
if ( ( V_150 & 0xF0 ) == 0x30 ) {
V_148 = L_5 ;
F_53 ( & V_4 -> V_32 ,
L_6 ,
V_147 ) ;
F_53 ( & V_4 -> V_32 ,
L_7
L_8
L_9 ) ;
} else
if ( V_147 == 0x4C
&& ( V_150 & 0xF0 ) == 0x10 ) {
V_148 = L_10 ;
}
}
} else
if ( ( V_147 == 0x4C || V_147 == 0x4D )
&& V_149 == 0x41 ) {
if ( ( V_150 & 0xF0 ) == 0x40
&& ( V_151 & 0x3F ) == 0x00
&& V_153 <= 0x0A ) {
V_148 = L_11 ;
if ( F_52 ( V_4 ,
V_160 ) )
V_145 -> V_6 |= V_7 ;
} else
if ( V_150 == 0x51
&& ( V_151 & 0x1B ) == 0x00
&& V_153 <= 0x0A ) {
V_148 = L_12 ;
} else
if ( V_150 == 0x57
&& ( V_151 & 0x1B ) == 0x00
&& V_153 <= 0x0A ) {
V_148 = L_13 ;
}
} else
if ( V_149 == 0x4D ) {
int V_161 , V_162 , V_163 ;
V_161 = F_5 ( V_2 ,
V_56 ) ;
V_149 = F_5 ( V_2 ,
V_156 ) ;
V_162 = F_5 ( V_2 ,
V_56 ) ;
V_163 = F_5 ( V_2 ,
V_79 ) ;
if ( V_161 < 0 || V_149 < 0 || V_162 < 0 || V_163 < 0 )
return - V_155 ;
if ( V_150 == V_149
&& ( V_147 == 0x4C || V_147 == 0x4D || V_147 == 0x4E )
&& ( V_151 & 0x1F ) == ( V_149 & 0x0F )
&& V_153 <= 0x09 ) {
if ( V_147 == 0x4C )
V_148 = L_14 ;
else
V_148 = L_15 ;
} else
if ( V_150 == 0x01
&& ( V_151 & 0x10 ) == 0x00
&& ( V_163 & 0x01 ) == 0x00
&& V_161 == V_162
&& V_153 <= 0x07 ) {
V_148 = L_16 ;
} else
if ( V_150 == 0x01
&& ( V_151 & 0x03 ) == 0x00
&& V_153 <= 0x07 ) {
V_148 = L_17 ;
} else
if ( V_150 == 0x59
&& ( V_151 & 0x3f ) == 0x00
&& V_153 <= 0x07 ) {
V_148 = L_18 ;
}
} else
if ( V_147 == 0x4C
&& V_149 == 0x5C ) {
if ( ( V_151 & 0x2A ) == 0x00
&& ( V_152 & 0xF8 ) == 0x00 ) {
if ( V_150 == 0x01
&& V_153 <= 0x09 ) {
V_148 = L_19 ;
} else
if ( ( V_150 & 0xFE ) == 0x10
&& V_153 <= 0x08 ) {
V_148 = L_19 ;
}
}
} else
if ( V_147 >= 0x48 && V_147 <= 0x4F
&& V_149 == 0xA1 ) {
if ( V_150 == 0x00
&& ( V_151 & 0x2A ) == 0x00
&& ( V_152 & 0xFE ) == 0x00
&& V_153 <= 0x09 ) {
V_148 = L_20 ;
}
} else
if ( ( V_147 == 0x4C || V_147 == 0x4D )
&& V_149 == 0x47 ) {
if ( V_150 == 0x01
&& ( V_151 & 0x3F ) == 0x00
&& V_153 <= 0x08 )
V_148 = L_21 ;
} else
if ( V_147 == 0x4C
&& V_149 == 0x55 ) {
int V_164 ;
V_164 = F_5 ( V_2 ,
V_165 ) ;
if ( V_150 == 0x00
&& ( V_151 & 0x1B ) == 0x00
&& V_153 <= 0x09
&& ( V_164 & 0x0F ) == 0x00 )
V_148 = L_22 ;
}
if ( ! V_148 ) {
F_16 ( & V_4 -> V_32 ,
L_23
L_24 , V_147 , V_149 , V_150 ) ;
return - V_155 ;
}
F_54 ( V_145 -> type , V_148 , V_166 ) ;
return 0 ;
}
static void F_55 ( void * V_167 )
{
struct V_17 * V_18 = V_167 ;
struct V_1 * V_2 = V_18 -> V_2 ;
F_8 ( V_2 , V_30 ,
V_18 -> V_168 ) ;
F_8 ( V_2 , V_24 ,
V_18 -> V_80 ) ;
}
static int F_56 ( struct V_1 * V_2 , struct V_17 * V_18 )
{
int V_20 , V_153 ;
V_153 = F_3 ( V_2 , V_158 ) ;
if ( V_153 < 0 )
return V_153 ;
V_18 -> V_168 = V_153 ;
F_9 ( V_2 , V_18 , 500 ) ;
V_20 = F_3 ( V_2 , V_23 ) ;
if ( V_20 < 0 )
return V_20 ;
V_18 -> V_80 = V_20 ;
if ( V_18 -> V_21 == V_90 || V_18 -> V_21 == V_91 ) {
if ( V_20 & 0x04 )
V_18 -> V_6 |= V_82 ;
}
if ( V_18 -> V_21 == V_169 )
V_20 |= 0x18 ;
if ( V_18 -> V_21 == V_22 )
V_20 &= ~ 0x08 ;
V_20 &= 0xBF ;
if ( V_20 != V_18 -> V_80 )
F_8 ( V_2 , V_24 , V_20 ) ;
return F_57 ( & V_2 -> V_32 , F_55 , V_18 ) ;
}
static bool F_58 ( struct V_1 * V_2 , T_5 * V_170 )
{
struct V_17 * V_18 = F_59 ( V_2 ) ;
int V_171 , V_172 = 0 ;
V_171 = F_3 ( V_2 , V_76 ) ;
if ( V_171 < 0 )
return false ;
if ( V_18 -> V_21 == V_22 ) {
V_172 = F_3 ( V_2 , V_79 ) ;
if ( V_172 < 0 )
return false ;
}
* V_170 = V_171 | ( V_172 << 8 ) ;
if ( ( V_171 & 0x7f ) == 0 && ( V_172 & 0xfe ) == 0 )
return false ;
if ( ( V_171 & ( V_173 | V_174 | V_175 ) ) ||
( V_172 & V_176 ) )
F_60 ( & V_2 -> V_32 ,
L_25 , 1 ) ;
if ( ( V_171 & ( V_177 | V_178 | V_179 ) ) ||
( V_172 & V_180 ) )
F_60 ( & V_2 -> V_32 ,
L_25 , 2 ) ;
if ( V_171 & V_181 )
F_60 ( & V_2 -> V_32 ,
L_26 , 2 ) ;
if ( V_172 & ( V_182 | V_183 |
V_184 | V_185 ) )
F_60 ( & V_2 -> V_32 ,
L_25 , 3 ) ;
if ( V_172 & V_186 )
F_60 ( & V_2 -> V_32 ,
L_26 , 3 ) ;
return true ;
}
static T_10 F_61 ( int V_187 , void * V_188 )
{
struct V_1 * V_2 = V_188 ;
T_5 V_170 ;
if ( F_58 ( V_2 , & V_170 ) )
return V_189 ;
else
return V_190 ;
}
static void F_62 ( void * V_32 )
{
F_63 ( V_32 , & V_191 ) ;
}
static void F_64 ( void * V_192 )
{
F_65 ( V_192 ) ;
}
static int F_66 ( struct V_1 * V_2 ,
const struct V_193 * V_194 )
{
struct V_31 * V_32 = & V_2 -> V_32 ;
struct V_146 * V_4 = F_67 ( V_32 -> V_195 ) ;
struct V_196 * V_145 ;
struct V_192 * V_192 ;
struct V_31 * V_197 ;
struct V_17 * V_18 ;
int V_11 ;
V_192 = F_68 ( V_32 , L_27 ) ;
if ( F_69 ( V_192 ) )
return F_70 ( V_192 ) ;
V_11 = F_71 ( V_192 ) ;
if ( V_11 < 0 ) {
F_72 ( V_32 , L_28 , V_11 ) ;
return V_11 ;
}
V_11 = F_57 ( V_32 , F_64 , V_192 ) ;
if ( V_11 )
return V_11 ;
V_18 = F_73 ( V_32 , sizeof( struct V_17 ) , V_198 ) ;
if ( ! V_18 )
return - V_199 ;
V_18 -> V_2 = V_2 ;
F_74 ( V_2 , V_18 ) ;
F_75 ( & V_18 -> V_112 ) ;
if ( V_2 -> V_32 . V_200 )
V_18 -> V_21 = (enum V_201 ) F_76 ( & V_2 -> V_32 ) ;
else
V_18 -> V_21 = V_194 -> V_202 ;
if ( V_18 -> V_21 == V_203 ) {
if ( ! F_52 ( V_4 , V_160 ) )
V_2 -> V_6 &= ~ V_7 ;
}
V_18 -> V_81 = V_204 [ V_18 -> V_21 ] . V_81 ;
V_18 -> V_6 = V_204 [ V_18 -> V_21 ] . V_6 ;
V_18 -> V_205 . V_206 = & V_207 ;
V_18 -> V_205 . V_145 = V_18 -> V_145 ;
V_18 -> V_145 [ 0 ] = & V_208 ;
V_18 -> V_145 [ 1 ] = & V_18 -> V_209 ;
V_145 = & V_18 -> V_209 ;
V_145 -> type = V_143 ;
V_145 -> V_20 = V_18 -> V_210 ;
V_18 -> V_210 [ 0 ] = V_211 | V_212 | V_213 |
V_214 | V_215 | V_216 |
V_217 | V_218 ;
V_18 -> V_210 [ 1 ] = V_211 | V_212 | V_213 |
V_214 | V_215 | V_216 |
V_217 | V_218 | V_219 ;
if ( V_18 -> V_6 & V_49 )
V_18 -> V_210 [ 1 ] |= V_220 ;
if ( V_18 -> V_6 & V_53 ) {
V_18 -> V_210 [ 0 ] |= V_221 |
V_222 ;
V_18 -> V_210 [ 1 ] |= V_221 |
V_222 ;
}
if ( V_18 -> V_6 & V_223 ) {
V_18 -> V_210 [ 0 ] |= V_224 ;
V_18 -> V_210 [ 1 ] |= V_224 ;
}
if ( V_18 -> V_6 & V_225 ) {
V_18 -> V_210 [ 2 ] = V_211 |
V_212 | V_213 |
V_214 | V_215 |
V_221 | V_222 |
V_216 | V_217 |
V_218 | V_224 |
V_219 ;
}
V_18 -> V_70 = V_204 [ V_18 -> V_21 ] . V_70 ;
V_18 -> V_29 = V_204 [ V_18 -> V_21 ] . V_29 ;
V_11 = F_56 ( V_2 , V_18 ) ;
if ( V_11 < 0 ) {
F_72 ( V_32 , L_29 ) ;
return V_11 ;
}
if ( V_2 -> V_6 & V_7 ) {
V_11 = F_77 ( V_32 , & V_191 ) ;
if ( V_11 )
return V_11 ;
V_11 = F_57 ( V_32 , F_62 , V_32 ) ;
if ( V_11 )
return V_11 ;
}
V_197 = F_78 ( V_32 , V_2 -> V_148 ,
V_18 , & V_18 -> V_205 ,
NULL ) ;
if ( F_69 ( V_197 ) )
return F_70 ( V_197 ) ;
if ( V_2 -> V_187 ) {
F_16 ( V_32 , L_30 , V_2 -> V_187 ) ;
V_11 = F_79 ( V_32 , V_2 -> V_187 ,
NULL , F_61 ,
V_226 | V_227 ,
L_4 , V_2 ) ;
if ( V_11 < 0 ) {
F_72 ( V_32 , L_31 , V_2 -> V_187 ) ;
return V_11 ;
}
}
return 0 ;
}
static void F_80 ( struct V_1 * V_2 , enum V_228 type ,
unsigned int V_229 )
{
T_5 V_77 ;
if ( type != V_230 )
return;
if ( F_58 ( V_2 , & V_77 ) ) {
struct V_17 * V_18 = F_59 ( V_2 ) ;
if ( ( V_18 -> V_6 & V_231 ) &&
( V_77 & V_18 -> V_81 ) ) {
int V_20 ;
F_16 ( & V_2 -> V_32 , L_32 ) ;
V_20 = F_3 ( V_2 , V_23 ) ;
if ( V_20 >= 0 )
F_8 ( V_2 ,
V_24 ,
V_20 | 0x80 ) ;
}
} else {
F_53 ( & V_2 -> V_32 , L_33 ) ;
}
}
