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
int F_30 ( struct V_3 * V_4 , const char * V_7 )
{
char * V_35 ;
if ( ! V_7 )
return 0 ;
V_35 = F_31 ( V_7 , V_32 ) ;
if ( ! V_35 )
return - V_33 ;
F_22 ( V_4 -> V_31 ) ;
V_4 -> V_31 = V_35 ;
return 0 ;
}
int F_32 ( struct V_3 * V_4 , char * V_36 , T_2 V_37 )
{
return snprintf ( V_36 , V_37 , L_4 ,
V_4 -> V_18 , V_4 -> V_23 , V_4 -> type ) ;
}
unsigned int F_33 ( struct V_3 * V_4 , T_1 V_38 ,
unsigned int V_39 , unsigned int V_40 )
{
T_3 V_41 , V_8 ;
V_8 = V_4 -> V_8 ;
if ( ( V_8 & ~ 0xf ) || ( V_38 & ~ 0x7f ) ||
( V_39 & ~ 0xfff ) || ( V_40 & ~ 0xffff ) ) {
F_14 ( & V_4 -> V_2 , L_5 ,
V_8 , V_38 , V_39 , V_40 ) ;
return - 1 ;
}
V_41 = V_8 << 28 ;
V_41 |= ( T_3 ) V_38 << 20 ;
V_41 |= V_39 << 8 ;
V_41 |= V_40 ;
return V_41 ;
}
int F_34 ( struct V_3 * V_4 , unsigned int V_42 ,
unsigned int V_43 , unsigned int * V_44 )
{
if ( V_4 -> V_45 )
return V_4 -> V_45 ( V_4 , V_42 , V_43 , V_44 ) ;
return F_35 ( V_4 -> V_6 , V_4 -> V_8 , V_42 , V_44 ) ;
}
int F_16 ( struct V_3 * V_4 , T_1 V_38 ,
unsigned int V_39 , unsigned int V_40 , unsigned int * V_44 )
{
unsigned int V_42 = F_33 ( V_4 , V_38 , V_39 , V_40 ) ;
return F_34 ( V_4 , V_42 , 0 , V_44 ) ;
}
int F_36 ( struct V_3 * V_4 , T_1 V_38 , int V_40 ,
unsigned int * V_44 )
{
unsigned int V_42 ;
V_42 = F_37 ( V_38 , V_46 ) | V_40 ;
return F_38 ( V_4 , V_42 , V_44 ) ;
}
int F_39 ( struct V_3 * V_4 , T_1 V_38 ,
int V_40 )
{
int V_41 ;
if ( V_4 -> V_47 )
F_40 ( V_4 -> V_47 , true ) ;
V_41 = F_12 ( V_4 , V_38 , V_40 ) ;
if ( V_4 -> V_47 )
F_40 ( V_4 -> V_47 , false ) ;
return V_41 ;
}
int F_41 ( struct V_3 * V_4 , T_1 V_38 ,
unsigned int V_40 , unsigned int V_41 )
{
unsigned int V_39 = ( V_46 << 8 ) | ( V_38 << 20 ) | V_40 ;
int V_10 ;
if ( ! V_4 -> V_47 )
return - V_48 ;
V_4 -> V_49 = true ;
V_10 = F_42 ( V_4 , V_39 , V_41 ) ;
V_4 -> V_49 = false ;
return V_10 ;
}
int F_43 ( struct V_3 * V_4 , T_1 V_38 ,
T_1 * V_50 )
{
unsigned int V_40 ;
V_40 = F_39 ( V_4 , V_38 , V_51 ) ;
if ( V_40 == - 1 ) {
* V_50 = 0 ;
return 0 ;
}
* V_50 = ( V_40 >> 16 ) & 0x7fff ;
return ( int ) ( V_40 & 0x7fff ) ;
}
static void F_13 ( struct V_3 * V_4 )
{
int V_52 , V_53 , V_54 ;
T_1 V_38 ;
V_53 = F_43 ( V_4 , V_19 , & V_38 ) ;
for ( V_52 = 0 ; V_52 < V_53 ; V_52 ++ , V_38 ++ ) {
V_54 = F_12 ( V_4 , V_38 ,
V_55 ) ;
switch ( V_54 & 0xff ) {
case V_56 :
V_4 -> V_25 = V_38 ;
V_4 -> V_57 = V_54 & 0xff ;
V_4 -> V_58 = ( V_54 >> 8 ) & 1 ;
break;
case V_59 :
V_4 -> V_26 = V_38 ;
V_4 -> V_60 = V_54 & 0xff ;
V_4 -> V_61 = ( V_54 >> 8 ) & 1 ;
break;
default:
break;
}
}
}
int F_15 ( struct V_3 * V_4 )
{
T_1 V_62 ;
int V_63 ;
V_63 = F_43 ( V_4 , V_4 -> V_25 , & V_62 ) ;
if ( ! V_62 || V_63 <= 0 || V_63 >= 0xff ) {
F_14 ( & V_4 -> V_2 , L_6 ,
V_4 -> V_25 ) ;
return - V_48 ;
}
V_4 -> V_64 = V_63 ;
V_4 -> V_62 = V_62 ;
V_4 -> V_65 = V_62 + V_63 ;
return 0 ;
}
int F_44 ( struct V_3 * V_4 )
{
int V_66 ;
if ( F_28 ( & V_4 -> V_2 ) )
F_29 ( V_4 ) ;
V_66 = F_15 ( V_4 ) ;
if ( V_66 ) {
F_14 ( & V_4 -> V_2 , L_7 , V_66 ) ;
return V_66 ;
}
if ( F_28 ( & V_4 -> V_2 ) ) {
V_66 = F_25 ( V_4 ) ;
if ( V_66 ) {
F_14 ( & V_4 -> V_2 , L_8 , V_66 ) ;
return V_66 ;
}
}
return V_66 ;
}
static unsigned int F_45 ( struct V_3 * V_4 , T_1 V_38 )
{
unsigned int V_67 = F_46 ( V_4 , V_38 ) ;
unsigned int V_40 ;
if ( ! ( V_67 & V_68 ) &&
F_47 ( V_67 ) != V_69 )
return 0 ;
V_40 = F_12 ( V_4 , V_38 , V_70 ) ;
if ( V_40 == - 1 )
V_40 = 0 ;
return V_40 ;
}
int F_48 ( struct V_3 * V_4 , T_1 V_38 ,
T_1 * V_71 , int V_72 )
{
unsigned int V_40 ;
int V_52 , V_73 , V_74 , V_10 ;
unsigned int V_75 , V_76 , V_77 ;
T_1 V_78 ;
int V_79 = 0 ;
V_40 = F_45 ( V_4 , V_38 ) ;
if ( ! V_40 )
return 0 ;
if ( V_40 & V_80 ) {
V_75 = 16 ;
V_76 = 2 ;
} else {
V_75 = 8 ;
V_76 = 4 ;
}
V_73 = V_40 & V_81 ;
V_77 = ( 1 << ( V_75 - 1 ) ) - 1 ;
if ( ! V_73 )
return 0 ;
if ( V_73 == 1 ) {
V_10 = F_16 ( V_4 , V_38 , V_82 , 0 ,
& V_40 ) ;
if ( V_10 < 0 )
return V_10 ;
if ( V_71 )
V_71 [ 0 ] = V_40 & V_77 ;
return 1 ;
}
V_74 = 0 ;
V_78 = 0 ;
for ( V_52 = 0 ; V_52 < V_73 ; V_52 ++ ) {
int V_83 ;
T_1 V_41 , V_84 ;
if ( V_52 % V_76 == 0 ) {
V_10 = F_16 ( V_4 , V_38 ,
V_82 , V_52 ,
& V_40 ) ;
if ( V_10 < 0 )
return - V_85 ;
}
V_83 = ! ! ( V_40 & ( 1 << ( V_75 - 1 ) ) ) ;
V_41 = V_40 & V_77 ;
if ( V_41 == 0 && V_79 ++ ) {
F_49 ( & V_4 -> V_2 ,
L_9 ,
V_38 , V_52 , V_40 ) ;
return 0 ;
}
V_40 >>= V_75 ;
if ( V_83 ) {
if ( ! V_78 || V_78 >= V_41 ) {
F_50 ( & V_4 -> V_2 ,
L_10 ,
V_78 , V_41 ) ;
continue;
}
for ( V_84 = V_78 + 1 ; V_84 <= V_41 ; V_84 ++ ) {
if ( V_71 ) {
if ( V_74 >= V_72 )
return - V_86 ;
V_71 [ V_74 ] = V_84 ;
}
V_74 ++ ;
}
} else {
if ( V_71 ) {
if ( V_74 >= V_72 )
return - V_86 ;
V_71 [ V_74 ] = V_41 ;
}
V_74 ++ ;
}
V_78 = V_41 ;
}
return V_74 ;
}
int F_51 ( struct V_3 * V_4 )
{
return F_52 ( & V_4 -> V_2 ) ;
}
int F_53 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = & V_4 -> V_2 ;
F_54 ( V_2 ) ;
return F_55 ( V_2 ) ;
}
int F_56 ( struct V_3 * V_4 )
{
if ( ! F_57 ( & V_4 -> V_17 ) )
return F_51 ( V_4 ) ;
return 0 ;
}
int F_58 ( struct V_3 * V_4 )
{
if ( F_59 ( & V_4 -> V_17 ) < 0 )
return F_53 ( V_4 ) ;
return 0 ;
}
int F_60 ( struct V_3 * V_4 , bool V_87 )
{
if ( ! V_4 -> V_88 )
return 0 ;
if ( V_4 -> V_6 -> V_89 -> V_90 )
return V_4 -> V_6 -> V_89 -> V_90 ( V_4 -> V_6 , V_87 ) ;
else
return - V_48 ;
}
static int F_17 ( struct V_3 * V_4 )
{
const struct V_91 * V_92 ;
T_4 V_18 = V_4 -> V_18 >> 16 ;
for ( V_92 = V_93 ; V_92 -> V_94 ; V_92 ++ ) {
if ( V_92 -> V_94 == V_18 ) {
V_4 -> V_34 = F_31 ( V_92 -> V_7 , V_32 ) ;
return V_4 -> V_34 ? 0 : - V_33 ;
}
}
V_4 -> V_34 = F_18 ( V_32 , L_11 , V_18 ) ;
return V_4 -> V_34 ? 0 : - V_33 ;
}
unsigned int F_61 ( unsigned int V_95 ,
unsigned int V_96 ,
unsigned int V_97 ,
unsigned int V_98 ,
unsigned short V_99 )
{
int V_52 ;
unsigned int V_41 = 0 ;
for ( V_52 = 0 ; V_100 [ V_52 ] . V_101 ; V_52 ++ )
if ( V_100 [ V_52 ] . V_101 == V_95 ) {
V_41 = V_100 [ V_52 ] . V_102 ;
break;
}
if ( ! V_100 [ V_52 ] . V_101 )
return 0 ;
if ( V_96 == 0 || V_96 > 8 )
return 0 ;
V_41 |= V_96 - 1 ;
switch ( F_62 ( V_97 ) ) {
case 8 :
V_41 |= V_103 ;
break;
case 16 :
V_41 |= V_104 ;
break;
case 20 :
case 24 :
case 32 :
if ( V_98 >= 32 || V_97 == V_105 )
V_41 |= V_106 ;
else if ( V_98 >= 24 )
V_41 |= V_107 ;
else
V_41 |= V_108 ;
break;
default:
return 0 ;
}
if ( V_99 & V_109 )
V_41 |= V_110 ;
return V_41 ;
}
static unsigned int F_63 ( struct V_3 * V_4 , T_1 V_38 )
{
unsigned int V_41 = 0 ;
if ( V_38 != V_4 -> V_25 &&
( F_46 ( V_4 , V_38 ) & V_111 ) )
V_41 = F_12 ( V_4 , V_38 , V_112 ) ;
if ( ! V_41 || V_41 == - 1 )
V_41 = F_12 ( V_4 , V_4 -> V_25 , V_112 ) ;
if ( ! V_41 || V_41 == - 1 )
return 0 ;
return V_41 ;
}
static unsigned int F_64 ( struct V_3 * V_4 , T_1 V_38 )
{
unsigned int V_113 = F_12 ( V_4 , V_38 , V_114 ) ;
if ( ! V_113 || V_113 == - 1 )
V_113 = F_12 ( V_4 , V_4 -> V_25 , V_114 ) ;
if ( ! V_113 || V_113 == - 1 )
return 0 ;
return V_113 ;
}
int F_65 ( struct V_3 * V_4 , T_1 V_38 ,
T_3 * V_115 , T_5 * V_116 , unsigned int * V_117 )
{
unsigned int V_52 , V_41 , V_67 ;
V_67 = F_46 ( V_4 , V_38 ) ;
V_41 = F_63 ( V_4 , V_38 ) ;
if ( V_115 ) {
T_3 V_118 = 0 ;
for ( V_52 = 0 ; V_52 < V_119 ; V_52 ++ ) {
if ( V_41 & ( 1 << V_52 ) )
V_118 |= V_100 [ V_52 ] . V_120 ;
}
if ( V_118 == 0 ) {
F_14 ( & V_4 -> V_2 ,
L_12 ,
V_38 , V_41 ,
( V_67 & V_111 ) ? 1 : 0 ) ;
return - V_85 ;
}
* V_115 = V_118 ;
}
if ( V_116 || V_117 ) {
T_5 V_121 = 0 ;
unsigned int V_113 , V_122 ;
V_113 = F_64 ( V_4 , V_38 ) ;
if ( ! V_113 )
return - V_85 ;
V_122 = 0 ;
if ( V_113 & V_123 ) {
if ( V_41 & V_124 ) {
V_121 |= V_125 ;
V_122 = 8 ;
}
if ( V_41 & V_126 ) {
V_121 |= V_127 ;
V_122 = 16 ;
}
if ( V_67 & V_128 ) {
if ( V_41 & V_129 )
V_121 |= V_130 ;
if ( V_41 & ( V_131 | V_132 ) )
V_121 |= V_133 ;
if ( V_41 & V_132 )
V_122 = 24 ;
else if ( V_41 & V_131 )
V_122 = 20 ;
} else if ( V_41 & ( V_131 | V_132 |
V_129 ) ) {
V_121 |= V_133 ;
if ( V_41 & V_129 )
V_122 = 32 ;
else if ( V_41 & V_132 )
V_122 = 24 ;
else if ( V_41 & V_131 )
V_122 = 20 ;
}
}
#if 0
if (streams & AC_SUPFMT_FLOAT32) {
formats |= SNDRV_PCM_FMTBIT_FLOAT_LE;
if (!bps)
bps = 32;
}
#endif
if ( V_113 == V_134 ) {
V_121 |= V_125 ;
V_122 = 8 ;
}
if ( V_121 == 0 ) {
F_14 ( & V_4 -> V_2 ,
L_13 ,
V_38 , V_41 ,
( V_67 & V_111 ) ? 1 : 0 ,
V_113 ) ;
return - V_85 ;
}
if ( V_116 )
* V_116 = V_121 ;
if ( V_117 )
* V_117 = V_122 ;
}
return 0 ;
}
bool F_66 ( struct V_3 * V_4 , T_1 V_38 ,
unsigned int V_97 )
{
int V_52 ;
unsigned int V_41 = 0 , V_95 , V_135 ;
V_41 = F_63 ( V_4 , V_38 ) ;
if ( ! V_41 )
return false ;
V_95 = V_97 & 0xff00 ;
for ( V_52 = 0 ; V_52 < V_119 ; V_52 ++ )
if ( V_100 [ V_52 ] . V_102 == V_95 ) {
if ( V_41 & ( 1 << V_52 ) )
break;
return false ;
}
if ( V_52 >= V_119 )
return false ;
V_135 = F_64 ( V_4 , V_38 ) ;
if ( ! V_135 )
return false ;
if ( V_135 & V_123 ) {
switch ( V_97 & 0xf0 ) {
case 0x00 :
if ( ! ( V_41 & V_124 ) )
return false ;
break;
case 0x10 :
if ( ! ( V_41 & V_126 ) )
return false ;
break;
case 0x20 :
if ( ! ( V_41 & V_131 ) )
return false ;
break;
case 0x30 :
if ( ! ( V_41 & V_132 ) )
return false ;
break;
case 0x40 :
if ( ! ( V_41 & V_129 ) )
return false ;
break;
default:
return false ;
}
} else {
}
return true ;
}
static unsigned int F_67 ( struct V_3 * V_136 , T_1 V_38 ,
int V_43 , unsigned int V_39 , unsigned int V_40 )
{
unsigned int V_42 = F_33 ( V_136 , V_38 , V_39 , V_40 ) ;
unsigned int V_44 ;
if ( F_34 ( V_136 , V_42 , V_43 , & V_44 ) )
return - 1 ;
return V_44 ;
}
static int F_68 ( struct V_3 * V_136 , T_1 V_38 ,
int V_43 , unsigned int V_39 , unsigned int V_40 )
{
unsigned int V_42 = F_33 ( V_136 , V_38 , V_39 , V_40 ) ;
return F_34 ( V_136 , V_42 , V_43 , NULL ) ;
}
int F_69 ( struct V_3 * V_136 , T_1 V_38 ,
int V_43 , unsigned int V_39 , unsigned int V_40 )
{
return F_67 ( V_136 , V_38 , V_43 , V_39 , V_40 ) ;
}
int F_70 ( struct V_3 * V_136 , T_1 V_38 ,
int V_43 , unsigned int V_39 , unsigned int V_40 )
{
return F_68 ( V_136 , V_38 , V_43 , V_39 , V_40 ) ;
}
bool F_71 ( struct V_3 * V_136 ,
T_1 V_38 , unsigned int V_137 )
{
unsigned int V_138 = F_67 ( V_136 , V_38 , 0 ,
V_139 , 0 ) ;
if ( V_138 & V_140 )
return true ;
V_138 = ( V_138 >> 4 ) & 0x0f ;
return ( V_138 == V_137 ) ;
}
