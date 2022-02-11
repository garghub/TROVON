static void F_1 ( struct V_1 * V_2 )
{
F_2 ( F_3 ( V_2 , struct V_3 , V_2 ) ) ;
}
int F_4 ( struct V_3 * V_4 , struct V_5 * V_6 ,
const char * V_7 , unsigned int V_8 )
{
struct V_1 * V_2 ;
T_1 V_9 ;
int V_10 ;
V_2 = & V_4 -> V_2 ;
F_5 ( V_2 ) ;
V_2 -> V_11 = V_6 -> V_2 ;
V_2 -> V_6 = & V_12 ;
V_2 -> V_13 = F_1 ;
V_2 -> V_14 = V_15 ;
F_6 ( V_2 , L_1 , V_7 ) ;
F_7 ( V_2 ) ;
V_4 -> V_6 = V_6 ;
V_4 -> V_8 = V_8 ;
V_4 -> type = V_16 ;
F_8 ( & V_4 -> V_2 ) ;
F_9 ( & V_4 -> V_2 ) ;
F_10 ( & V_4 -> V_17 , 0 ) ;
V_10 = F_11 ( V_6 , V_4 ) ;
if ( V_10 < 0 )
goto error;
V_4 -> V_18 = F_12 ( V_4 , V_19 ,
V_20 ) ;
if ( V_4 -> V_18 == - 1 ) {
V_4 -> V_18 = F_12 ( V_4 , V_19 ,
V_20 ) ;
}
V_4 -> V_21 = F_12 ( V_4 , V_19 ,
V_22 ) ;
V_4 -> V_23 = F_12 ( V_4 , V_19 ,
V_24 ) ;
F_13 ( V_4 ) ;
if ( ! V_4 -> V_25 && ! V_4 -> V_26 ) {
F_14 ( V_2 , L_2 ) ;
V_10 = - V_27 ;
goto error;
}
V_9 = V_4 -> V_25 ? V_4 -> V_25 : V_4 -> V_26 ;
V_10 = F_15 ( V_4 ) ;
if ( V_10 < 0 )
goto error;
V_4 -> V_28 = F_12 ( V_4 , V_9 , V_29 ) ;
if ( V_4 -> V_21 == - 1 || V_4 -> V_21 == 0 )
F_16 ( V_4 , V_9 , V_30 , 0 ,
& V_4 -> V_21 ) ;
V_10 = F_17 ( V_4 ) ;
if ( V_10 < 0 )
goto error;
V_4 -> V_31 = F_18 ( V_32 , L_3 ,
V_4 -> V_18 & 0xffff ) ;
if ( ! V_4 -> V_31 ) {
V_10 = - V_33 ;
goto error;
}
return 0 ;
error:
F_19 ( & V_4 -> V_2 ) ;
return V_10 ;
}
void F_2 ( struct V_3 * V_4 )
{
F_20 ( & V_4 -> V_2 ) ;
F_21 ( V_4 -> V_6 , V_4 ) ;
F_22 ( V_4 -> V_34 ) ;
F_22 ( V_4 -> V_31 ) ;
}
int F_23 ( struct V_3 * V_4 )
{
int V_10 ;
V_10 = F_24 ( & V_4 -> V_2 ) ;
if ( V_10 < 0 )
return V_10 ;
V_10 = F_25 ( V_4 ) ;
if ( V_10 < 0 ) {
F_26 ( & V_4 -> V_2 ) ;
return V_10 ;
}
return 0 ;
}
void F_27 ( struct V_3 * V_4 )
{
if ( F_28 ( & V_4 -> V_2 ) ) {
F_29 ( V_4 ) ;
F_26 ( & V_4 -> V_2 ) ;
}
}
unsigned int F_30 ( struct V_3 * V_4 , T_1 V_35 ,
unsigned int V_36 , unsigned int V_37 )
{
T_2 V_38 , V_8 ;
V_8 = V_4 -> V_8 ;
if ( ( V_8 & ~ 0xf ) || ( V_35 & ~ 0x7f ) ||
( V_36 & ~ 0xfff ) || ( V_37 & ~ 0xffff ) ) {
F_14 ( & V_4 -> V_2 , L_4 ,
V_8 , V_35 , V_36 , V_37 ) ;
return - 1 ;
}
V_38 = V_8 << 28 ;
V_38 |= ( T_2 ) V_35 << 20 ;
V_38 |= V_36 << 8 ;
V_38 |= V_37 ;
return V_38 ;
}
int F_31 ( struct V_3 * V_4 , unsigned int V_39 ,
unsigned int V_40 , unsigned int * V_41 )
{
if ( V_4 -> V_42 )
return V_4 -> V_42 ( V_4 , V_39 , V_40 , V_41 ) ;
return F_32 ( V_4 -> V_6 , V_4 -> V_8 , V_39 , V_41 ) ;
}
int F_16 ( struct V_3 * V_4 , T_1 V_35 ,
unsigned int V_36 , unsigned int V_37 , unsigned int * V_41 )
{
unsigned int V_39 = F_30 ( V_4 , V_35 , V_36 , V_37 ) ;
return F_31 ( V_4 , V_39 , 0 , V_41 ) ;
}
int F_33 ( struct V_3 * V_4 , T_1 V_35 , int V_37 ,
unsigned int * V_41 )
{
unsigned int V_39 ;
V_39 = F_34 ( V_35 , V_43 ) | V_37 ;
return F_35 ( V_4 , V_39 , V_41 ) ;
}
int F_36 ( struct V_3 * V_4 , T_1 V_35 ,
int V_37 )
{
int V_38 ;
if ( V_4 -> V_44 )
F_37 ( V_4 -> V_44 , true ) ;
V_38 = F_12 ( V_4 , V_35 , V_37 ) ;
if ( V_4 -> V_44 )
F_37 ( V_4 -> V_44 , false ) ;
return V_38 ;
}
int F_38 ( struct V_3 * V_4 , T_1 V_35 ,
unsigned int V_37 , unsigned int V_38 )
{
unsigned int V_36 = ( V_43 << 8 ) | ( V_35 << 20 ) | V_37 ;
int V_10 ;
if ( ! V_4 -> V_44 )
return - V_45 ;
V_4 -> V_46 = true ;
V_10 = F_39 ( V_4 , V_36 , V_38 ) ;
V_4 -> V_46 = false ;
return V_10 ;
}
int F_40 ( struct V_3 * V_4 , T_1 V_35 ,
T_1 * V_47 )
{
unsigned int V_37 ;
V_37 = F_36 ( V_4 , V_35 , V_48 ) ;
if ( V_37 == - 1 ) {
* V_47 = 0 ;
return 0 ;
}
* V_47 = ( V_37 >> 16 ) & 0x7fff ;
return ( int ) ( V_37 & 0x7fff ) ;
}
static void F_13 ( struct V_3 * V_4 )
{
int V_49 , V_50 , V_51 ;
T_1 V_35 ;
V_50 = F_40 ( V_4 , V_19 , & V_35 ) ;
for ( V_49 = 0 ; V_49 < V_50 ; V_49 ++ , V_35 ++ ) {
V_51 = F_12 ( V_4 , V_35 ,
V_52 ) ;
switch ( V_51 & 0xff ) {
case V_53 :
V_4 -> V_25 = V_35 ;
V_4 -> V_54 = V_51 & 0xff ;
V_4 -> V_55 = ( V_51 >> 8 ) & 1 ;
break;
case V_56 :
V_4 -> V_26 = V_35 ;
V_4 -> V_57 = V_51 & 0xff ;
V_4 -> V_58 = ( V_51 >> 8 ) & 1 ;
break;
default:
break;
}
}
}
int F_15 ( struct V_3 * V_4 )
{
T_1 V_59 ;
int V_60 ;
V_60 = F_40 ( V_4 , V_4 -> V_25 , & V_59 ) ;
if ( ! V_59 || V_60 <= 0 || V_60 >= 0xff ) {
F_14 ( & V_4 -> V_2 , L_5 ,
V_4 -> V_25 ) ;
return - V_45 ;
}
V_4 -> V_61 = V_60 ;
V_4 -> V_59 = V_59 ;
V_4 -> V_62 = V_59 + V_60 ;
return 0 ;
}
static unsigned int F_41 ( struct V_3 * V_4 , T_1 V_35 )
{
unsigned int V_63 = F_42 ( V_4 , V_35 ) ;
unsigned int V_37 ;
if ( ! ( V_63 & V_64 ) &&
F_43 ( V_63 ) != V_65 )
return 0 ;
V_37 = F_12 ( V_4 , V_35 , V_66 ) ;
if ( V_37 == - 1 )
V_37 = 0 ;
return V_37 ;
}
int F_44 ( struct V_3 * V_4 , T_1 V_35 ,
T_1 * V_67 , int V_68 )
{
unsigned int V_37 ;
int V_49 , V_69 , V_70 , V_10 ;
unsigned int V_71 , V_72 , V_73 ;
T_1 V_74 ;
int V_75 = 0 ;
V_37 = F_41 ( V_4 , V_35 ) ;
if ( ! V_37 )
return 0 ;
if ( V_37 & V_76 ) {
V_71 = 16 ;
V_72 = 2 ;
} else {
V_71 = 8 ;
V_72 = 4 ;
}
V_69 = V_37 & V_77 ;
V_73 = ( 1 << ( V_71 - 1 ) ) - 1 ;
if ( ! V_69 )
return 0 ;
if ( V_69 == 1 ) {
V_10 = F_16 ( V_4 , V_35 , V_78 , 0 ,
& V_37 ) ;
if ( V_10 < 0 )
return V_10 ;
if ( V_67 )
V_67 [ 0 ] = V_37 & V_73 ;
return 1 ;
}
V_70 = 0 ;
V_74 = 0 ;
for ( V_49 = 0 ; V_49 < V_69 ; V_49 ++ ) {
int V_79 ;
T_1 V_38 , V_80 ;
if ( V_49 % V_72 == 0 ) {
V_10 = F_16 ( V_4 , V_35 ,
V_78 , V_49 ,
& V_37 ) ;
if ( V_10 < 0 )
return - V_81 ;
}
V_79 = ! ! ( V_37 & ( 1 << ( V_71 - 1 ) ) ) ;
V_38 = V_37 & V_73 ;
if ( V_38 == 0 && V_75 ++ ) {
F_45 ( & V_4 -> V_2 ,
L_6 ,
V_35 , V_49 , V_37 ) ;
return 0 ;
}
V_37 >>= V_71 ;
if ( V_79 ) {
if ( ! V_74 || V_74 >= V_38 ) {
F_46 ( & V_4 -> V_2 ,
L_7 ,
V_74 , V_38 ) ;
continue;
}
for ( V_80 = V_74 + 1 ; V_80 <= V_38 ; V_80 ++ ) {
if ( V_67 ) {
if ( V_70 >= V_68 )
return - V_82 ;
V_67 [ V_70 ] = V_80 ;
}
V_70 ++ ;
}
} else {
if ( V_67 ) {
if ( V_70 >= V_68 )
return - V_82 ;
V_67 [ V_70 ] = V_38 ;
}
V_70 ++ ;
}
V_74 = V_38 ;
}
return V_70 ;
}
void F_47 ( struct V_3 * V_4 )
{
F_48 ( & V_4 -> V_2 ) ;
}
void F_49 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = & V_4 -> V_2 ;
F_50 ( V_2 ) ;
F_51 ( V_2 ) ;
}
void F_52 ( struct V_3 * V_4 )
{
if ( ! F_53 ( & V_4 -> V_17 ) )
F_47 ( V_4 ) ;
}
void F_54 ( struct V_3 * V_4 )
{
if ( F_55 ( & V_4 -> V_17 ) < 0 )
F_49 ( V_4 ) ;
}
int F_56 ( struct V_3 * V_4 , bool V_83 )
{
if ( ! V_4 -> V_84 )
return 0 ;
if ( V_4 -> V_6 -> V_85 -> V_86 )
return V_4 -> V_6 -> V_85 -> V_86 ( V_4 -> V_6 , V_83 ) ;
else
return - V_45 ;
}
static int F_17 ( struct V_3 * V_4 )
{
const struct V_87 * V_88 ;
T_3 V_18 = V_4 -> V_18 >> 16 ;
for ( V_88 = V_89 ; V_88 -> V_90 ; V_88 ++ ) {
if ( V_88 -> V_90 == V_18 ) {
V_4 -> V_34 = F_57 ( V_88 -> V_7 , V_32 ) ;
return V_4 -> V_34 ? 0 : - V_33 ;
}
}
V_4 -> V_34 = F_18 ( V_32 , L_8 , V_18 ) ;
return V_4 -> V_34 ? 0 : - V_33 ;
}
unsigned int F_58 ( unsigned int V_91 ,
unsigned int V_92 ,
unsigned int V_93 ,
unsigned int V_94 ,
unsigned short V_95 )
{
int V_49 ;
unsigned int V_38 = 0 ;
for ( V_49 = 0 ; V_96 [ V_49 ] . V_97 ; V_49 ++ )
if ( V_96 [ V_49 ] . V_97 == V_91 ) {
V_38 = V_96 [ V_49 ] . V_98 ;
break;
}
if ( ! V_96 [ V_49 ] . V_97 )
return 0 ;
if ( V_92 == 0 || V_92 > 8 )
return 0 ;
V_38 |= V_92 - 1 ;
switch ( F_59 ( V_93 ) ) {
case 8 :
V_38 |= V_99 ;
break;
case 16 :
V_38 |= V_100 ;
break;
case 20 :
case 24 :
case 32 :
if ( V_94 >= 32 || V_93 == V_101 )
V_38 |= V_102 ;
else if ( V_94 >= 24 )
V_38 |= V_103 ;
else
V_38 |= V_104 ;
break;
default:
return 0 ;
}
if ( V_95 & V_105 )
V_38 |= V_106 ;
return V_38 ;
}
static unsigned int F_60 ( struct V_3 * V_4 , T_1 V_35 )
{
unsigned int V_38 = 0 ;
if ( V_35 != V_4 -> V_25 &&
( F_42 ( V_4 , V_35 ) & V_107 ) )
V_38 = F_12 ( V_4 , V_35 , V_108 ) ;
if ( ! V_38 || V_38 == - 1 )
V_38 = F_12 ( V_4 , V_4 -> V_25 , V_108 ) ;
if ( ! V_38 || V_38 == - 1 )
return 0 ;
return V_38 ;
}
static unsigned int F_61 ( struct V_3 * V_4 , T_1 V_35 )
{
unsigned int V_109 = F_12 ( V_4 , V_35 , V_110 ) ;
if ( ! V_109 || V_109 == - 1 )
V_109 = F_12 ( V_4 , V_4 -> V_25 , V_110 ) ;
if ( ! V_109 || V_109 == - 1 )
return 0 ;
return V_109 ;
}
int F_62 ( struct V_3 * V_4 , T_1 V_35 ,
T_2 * V_111 , T_4 * V_112 , unsigned int * V_113 )
{
unsigned int V_49 , V_38 , V_63 ;
V_63 = F_42 ( V_4 , V_35 ) ;
V_38 = F_60 ( V_4 , V_35 ) ;
if ( V_111 ) {
T_2 V_114 = 0 ;
for ( V_49 = 0 ; V_49 < V_115 ; V_49 ++ ) {
if ( V_38 & ( 1 << V_49 ) )
V_114 |= V_96 [ V_49 ] . V_116 ;
}
if ( V_114 == 0 ) {
F_14 ( & V_4 -> V_2 ,
L_9 ,
V_35 , V_38 ,
( V_63 & V_107 ) ? 1 : 0 ) ;
return - V_81 ;
}
* V_111 = V_114 ;
}
if ( V_112 || V_113 ) {
T_4 V_117 = 0 ;
unsigned int V_109 , V_118 ;
V_109 = F_61 ( V_4 , V_35 ) ;
if ( ! V_109 )
return - V_81 ;
V_118 = 0 ;
if ( V_109 & V_119 ) {
if ( V_38 & V_120 ) {
V_117 |= V_121 ;
V_118 = 8 ;
}
if ( V_38 & V_122 ) {
V_117 |= V_123 ;
V_118 = 16 ;
}
if ( V_63 & V_124 ) {
if ( V_38 & V_125 )
V_117 |= V_126 ;
if ( V_38 & ( V_127 | V_128 ) )
V_117 |= V_129 ;
if ( V_38 & V_128 )
V_118 = 24 ;
else if ( V_38 & V_127 )
V_118 = 20 ;
} else if ( V_38 & ( V_127 | V_128 |
V_125 ) ) {
V_117 |= V_129 ;
if ( V_38 & V_125 )
V_118 = 32 ;
else if ( V_38 & V_128 )
V_118 = 24 ;
else if ( V_38 & V_127 )
V_118 = 20 ;
}
}
#if 0
if (streams & AC_SUPFMT_FLOAT32) {
formats |= SNDRV_PCM_FMTBIT_FLOAT_LE;
if (!bps)
bps = 32;
}
#endif
if ( V_109 == V_130 ) {
V_117 |= V_121 ;
V_118 = 8 ;
}
if ( V_117 == 0 ) {
F_14 ( & V_4 -> V_2 ,
L_10 ,
V_35 , V_38 ,
( V_63 & V_107 ) ? 1 : 0 ,
V_109 ) ;
return - V_81 ;
}
if ( V_112 )
* V_112 = V_117 ;
if ( V_113 )
* V_113 = V_118 ;
}
return 0 ;
}
bool F_63 ( struct V_3 * V_4 , T_1 V_35 ,
unsigned int V_93 )
{
int V_49 ;
unsigned int V_38 = 0 , V_91 , V_131 ;
V_38 = F_60 ( V_4 , V_35 ) ;
if ( ! V_38 )
return false ;
V_91 = V_93 & 0xff00 ;
for ( V_49 = 0 ; V_49 < V_115 ; V_49 ++ )
if ( V_96 [ V_49 ] . V_98 == V_91 ) {
if ( V_38 & ( 1 << V_49 ) )
break;
return false ;
}
if ( V_49 >= V_115 )
return false ;
V_131 = F_61 ( V_4 , V_35 ) ;
if ( ! V_131 )
return false ;
if ( V_131 & V_119 ) {
switch ( V_93 & 0xf0 ) {
case 0x00 :
if ( ! ( V_38 & V_120 ) )
return false ;
break;
case 0x10 :
if ( ! ( V_38 & V_122 ) )
return false ;
break;
case 0x20 :
if ( ! ( V_38 & V_127 ) )
return false ;
break;
case 0x30 :
if ( ! ( V_38 & V_128 ) )
return false ;
break;
case 0x40 :
if ( ! ( V_38 & V_125 ) )
return false ;
break;
default:
return false ;
}
} else {
}
return true ;
}
