static inline T_1 F_1 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_4 )
{
return F_2 ( V_2 -> V_5 [ V_3 ] + V_4 ) ;
}
static inline void F_3 ( struct V_1 * V_2 , T_1 V_6 , T_1 V_3 , T_1 V_4 )
{
F_4 ( V_6 , V_2 -> V_5 [ V_3 ] + V_4 ) ;
}
static int F_5 ( struct V_7 * V_8 )
{
struct V_1 * V_2 = F_6 ( V_8 ) ;
return V_2 -> V_9 -> V_10 ;
}
static const char * F_7 ( struct V_7 * V_8 ,
unsigned V_11 )
{
struct V_1 * V_2 = F_6 ( V_8 ) ;
return V_2 -> V_9 -> V_12 [ V_11 ] . V_13 ;
}
static int F_8 ( struct V_7 * V_8 ,
unsigned V_11 ,
const unsigned * * V_14 ,
unsigned * V_15 )
{
struct V_1 * V_2 = F_6 ( V_8 ) ;
* V_14 = V_2 -> V_9 -> V_12 [ V_11 ] . V_14 ;
* V_15 = V_2 -> V_9 -> V_12 [ V_11 ] . V_16 ;
return 0 ;
}
static void F_9 ( struct V_7 * V_8 ,
struct V_17 * V_18 ,
unsigned V_19 )
{
F_10 ( V_18 , L_1 , F_11 ( V_8 -> V_20 ) ) ;
}
static int F_12 ( struct V_7 * V_8 ,
struct V_21 * V_22 ,
struct V_23 * * V_24 ,
unsigned * V_25 ,
unsigned * V_26 )
{
struct V_27 * V_20 = V_8 -> V_20 ;
int V_28 , V_29 ;
const char * V_30 ;
T_1 V_6 ;
unsigned long V_31 ;
unsigned long * V_32 = NULL ;
unsigned V_33 = 0 ;
unsigned V_34 ;
struct V_35 * V_36 ;
const char * V_11 ;
V_28 = F_13 ( V_22 , L_2 , & V_30 ) ;
if ( V_28 < 0 ) {
if ( V_28 != - V_37 )
F_14 ( V_20 ,
L_3 ) ;
V_30 = NULL ;
}
for ( V_29 = 0 ; V_29 < F_15 ( V_38 ) ; V_29 ++ ) {
V_28 = F_16 ( V_22 , V_38 [ V_29 ] . V_35 , & V_6 ) ;
if ( ! V_28 ) {
V_31 = F_17 ( V_38 [ V_29 ] . V_39 , V_6 ) ;
V_28 = F_18 ( V_8 , & V_32 ,
& V_33 , V_31 ) ;
if ( V_28 < 0 )
goto exit;
} else if ( V_28 != - V_37 ) {
F_14 ( V_20 , L_4 ,
V_38 [ V_29 ] . V_35 ) ;
}
}
V_34 = 0 ;
if ( V_30 != NULL )
V_34 ++ ;
if ( V_33 )
V_34 ++ ;
V_28 = F_19 ( V_22 , L_5 ) ;
if ( V_28 < 0 ) {
F_14 ( V_20 , L_6 ) ;
goto exit;
}
V_34 *= V_28 ;
V_28 = F_20 ( V_8 , V_24 , V_25 ,
V_26 , V_34 ) ;
if ( V_28 < 0 )
goto exit;
F_21 (np, L_5 , prop, group) {
if ( V_30 ) {
V_28 = F_22 ( V_8 , V_24 ,
V_25 , V_26 , V_11 ,
V_30 ) ;
if ( V_28 < 0 )
goto exit;
}
if ( V_33 ) {
V_28 = F_23 ( V_8 , V_24 ,
V_25 , V_26 , V_11 ,
V_32 , V_33 ,
V_40 ) ;
if ( V_28 < 0 )
goto exit;
}
}
V_28 = 0 ;
exit:
F_24 ( V_32 ) ;
return V_28 ;
}
static int F_25 ( struct V_7 * V_8 ,
struct V_21 * V_41 ,
struct V_23 * * V_24 ,
unsigned * V_26 )
{
unsigned V_25 ;
struct V_21 * V_22 ;
int V_28 ;
V_25 = 0 ;
* V_24 = NULL ;
* V_26 = 0 ;
F_26 (np_config, np) {
V_28 = F_12 ( V_8 , V_22 , V_24 ,
& V_25 , V_26 ) ;
if ( V_28 < 0 ) {
F_27 ( V_8 , * V_24 ,
* V_26 ) ;
return V_28 ;
}
}
return 0 ;
}
static int F_28 ( struct V_7 * V_8 )
{
struct V_1 * V_2 = F_6 ( V_8 ) ;
return V_2 -> V_9 -> V_42 ;
}
static const char * F_29 ( struct V_7 * V_8 ,
unsigned V_30 )
{
struct V_1 * V_2 = F_6 ( V_8 ) ;
return V_2 -> V_9 -> V_43 [ V_30 ] . V_13 ;
}
static int F_30 ( struct V_7 * V_8 ,
unsigned V_30 ,
const char * const * * V_12 ,
unsigned * const V_44 )
{
struct V_1 * V_2 = F_6 ( V_8 ) ;
* V_12 = V_2 -> V_9 -> V_43 [ V_30 ] . V_12 ;
* V_44 = V_2 -> V_9 -> V_43 [ V_30 ] . V_10 ;
return 0 ;
}
static int F_31 ( struct V_7 * V_8 , unsigned V_30 ,
unsigned V_11 )
{
struct V_1 * V_2 = F_6 ( V_8 ) ;
const struct V_45 * V_46 ;
int V_29 ;
T_1 V_6 ;
V_46 = & V_2 -> V_9 -> V_12 [ V_11 ] ;
if ( F_32 ( V_46 -> V_47 < 0 ) )
return - V_37 ;
for ( V_29 = 0 ; V_29 < F_15 ( V_46 -> V_48 ) ; V_29 ++ ) {
if ( V_46 -> V_48 [ V_29 ] == V_30 )
break;
}
if ( F_32 ( V_29 == F_15 ( V_46 -> V_48 ) ) )
return - V_37 ;
V_6 = F_1 ( V_2 , V_46 -> V_49 , V_46 -> V_47 ) ;
V_6 &= ~ ( 0x3 << V_46 -> V_50 ) ;
V_6 |= V_29 << V_46 -> V_50 ;
F_3 ( V_2 , V_6 , V_46 -> V_49 , V_46 -> V_47 ) ;
return 0 ;
}
static void F_33 ( struct V_7 * V_8 ,
unsigned V_30 , unsigned V_11 )
{
struct V_1 * V_2 = F_6 ( V_8 ) ;
const struct V_45 * V_46 ;
T_1 V_6 ;
V_46 = & V_2 -> V_9 -> V_12 [ V_11 ] ;
if ( F_32 ( V_46 -> V_47 < 0 ) )
return;
V_6 = F_1 ( V_2 , V_46 -> V_49 , V_46 -> V_47 ) ;
V_6 &= ~ ( 0x3 << V_46 -> V_50 ) ;
V_6 |= V_46 -> V_51 << V_46 -> V_50 ;
F_3 ( V_2 , V_6 , V_46 -> V_49 , V_46 -> V_47 ) ;
}
static int F_34 ( struct V_1 * V_2 ,
const struct V_45 * V_46 ,
enum V_52 V_39 ,
bool V_53 ,
T_2 * V_3 , T_3 * V_4 , T_2 * V_54 , T_2 * V_55 )
{
switch ( V_39 ) {
case V_56 :
* V_3 = V_46 -> V_57 ;
* V_4 = V_46 -> V_58 ;
* V_54 = V_46 -> V_59 ;
* V_55 = 2 ;
break;
case V_60 :
* V_3 = V_46 -> V_61 ;
* V_4 = V_46 -> V_62 ;
* V_54 = V_46 -> V_63 ;
* V_55 = 1 ;
break;
case V_64 :
* V_3 = V_46 -> V_65 ;
* V_4 = V_46 -> V_66 ;
* V_54 = V_46 -> V_67 ;
* V_55 = 1 ;
break;
case V_68 :
* V_3 = V_46 -> V_69 ;
* V_4 = V_46 -> V_70 ;
* V_54 = V_46 -> V_71 ;
* V_55 = 1 ;
break;
case V_72 :
* V_3 = V_46 -> V_73 ;
* V_4 = V_46 -> V_74 ;
* V_54 = V_46 -> V_75 ;
* V_55 = 1 ;
break;
case V_76 :
* V_3 = V_46 -> V_77 ;
* V_4 = V_46 -> V_78 ;
* V_54 = V_46 -> V_79 ;
* V_55 = 1 ;
break;
case V_80 :
* V_3 = V_46 -> V_81 ;
* V_4 = V_46 -> V_82 ;
* V_54 = V_46 -> V_83 ;
* V_55 = 1 ;
break;
case V_84 :
* V_3 = V_46 -> V_85 ;
* V_4 = V_46 -> V_86 ;
* V_54 = V_46 -> V_87 ;
* V_55 = 1 ;
break;
case V_88 :
* V_3 = V_46 -> V_85 ;
* V_4 = V_46 -> V_86 ;
* V_54 = V_46 -> V_89 ;
* V_55 = 1 ;
break;
case V_90 :
* V_3 = V_46 -> V_85 ;
* V_4 = V_46 -> V_86 ;
* V_54 = V_46 -> V_91 ;
* V_55 = 2 ;
break;
case V_92 :
* V_3 = V_46 -> V_85 ;
* V_4 = V_46 -> V_86 ;
* V_54 = V_46 -> V_93 ;
* V_55 = V_46 -> V_94 ;
break;
case V_95 :
* V_3 = V_46 -> V_85 ;
* V_4 = V_46 -> V_86 ;
* V_54 = V_46 -> V_96 ;
* V_55 = V_46 -> V_97 ;
break;
case V_98 :
* V_3 = V_46 -> V_85 ;
* V_4 = V_46 -> V_86 ;
* V_54 = V_46 -> V_99 ;
* V_55 = V_46 -> V_100 ;
break;
case V_101 :
* V_3 = V_46 -> V_85 ;
* V_4 = V_46 -> V_86 ;
* V_54 = V_46 -> V_102 ;
* V_55 = V_46 -> V_103 ;
break;
case V_104 :
* V_3 = V_46 -> V_105 ;
* V_4 = V_46 -> V_106 ;
* V_54 = V_46 -> V_107 ;
* V_55 = 2 ;
break;
default:
F_14 ( V_2 -> V_20 , L_7 , V_39 ) ;
return - V_108 ;
}
if ( * V_4 < 0 ) {
if ( V_53 )
F_14 ( V_2 -> V_20 ,
L_8 ,
V_39 , V_46 -> V_13 ) ;
return - V_108 ;
}
return 0 ;
}
static int F_35 ( struct V_7 * V_8 ,
unsigned V_109 , unsigned long * V_31 )
{
F_14 ( V_8 -> V_20 , L_9 ) ;
return - V_108 ;
}
static int F_36 ( struct V_7 * V_8 ,
unsigned V_109 , unsigned long * V_32 ,
unsigned V_33 )
{
F_14 ( V_8 -> V_20 , L_10 ) ;
return - V_108 ;
}
static int F_37 ( struct V_7 * V_8 ,
unsigned V_11 , unsigned long * V_31 )
{
struct V_1 * V_2 = F_6 ( V_8 ) ;
enum V_52 V_39 = F_38 ( * V_31 ) ;
T_4 V_110 ;
const struct V_45 * V_46 ;
int V_28 ;
T_2 V_3 , V_54 , V_55 ;
T_3 V_4 ;
T_1 V_6 , V_111 ;
V_46 = & V_2 -> V_9 -> V_12 [ V_11 ] ;
V_28 = F_34 ( V_2 , V_46 , V_39 , true , & V_3 , & V_4 , & V_54 ,
& V_55 ) ;
if ( V_28 < 0 )
return V_28 ;
V_6 = F_1 ( V_2 , V_3 , V_4 ) ;
V_111 = ( 1 << V_55 ) - 1 ;
V_110 = ( V_6 >> V_54 ) & V_111 ;
* V_31 = F_17 ( V_39 , V_110 ) ;
return 0 ;
}
static int F_39 ( struct V_7 * V_8 ,
unsigned V_11 , unsigned long * V_32 ,
unsigned V_33 )
{
struct V_1 * V_2 = F_6 ( V_8 ) ;
enum V_52 V_39 ;
T_4 V_110 ;
const struct V_45 * V_46 ;
int V_28 , V_29 ;
T_2 V_3 , V_54 , V_55 ;
T_3 V_4 ;
T_1 V_6 , V_111 ;
V_46 = & V_2 -> V_9 -> V_12 [ V_11 ] ;
for ( V_29 = 0 ; V_29 < V_33 ; V_29 ++ ) {
V_39 = F_38 ( V_32 [ V_29 ] ) ;
V_110 = F_40 ( V_32 [ V_29 ] ) ;
V_28 = F_34 ( V_2 , V_46 , V_39 , true , & V_3 , & V_4 , & V_54 ,
& V_55 ) ;
if ( V_28 < 0 )
return V_28 ;
V_6 = F_1 ( V_2 , V_3 , V_4 ) ;
if ( V_39 == V_72 ) {
if ( ( V_6 & F_41 ( V_54 ) ) && ! V_110 ) {
F_14 ( V_8 -> V_20 , L_11 ) ;
return - V_37 ;
}
}
if ( V_55 == 1 )
V_110 = ! ! V_110 ;
V_111 = ( 1 << V_55 ) - 1 ;
if ( V_110 & ~ V_111 ) {
F_14 ( V_8 -> V_20 ,
L_12 ,
V_32 [ V_29 ] , V_110 , V_55 ) ;
return - V_37 ;
}
V_6 &= ~ ( V_111 << V_54 ) ;
V_6 |= V_110 << V_54 ;
F_3 ( V_2 , V_6 , V_3 , V_4 ) ;
}
return 0 ;
}
static void F_42 ( struct V_7 * V_8 ,
struct V_17 * V_18 , unsigned V_19 )
{
}
static const char * F_43 ( const char * V_18 )
{
const char * V_112 = strchr ( V_18 , ',' ) ;
if ( ! V_112 )
return V_18 ;
return V_112 + 1 ;
}
static void F_44 ( struct V_7 * V_8 ,
struct V_17 * V_18 , unsigned V_11 )
{
struct V_1 * V_2 = F_6 ( V_8 ) ;
const struct V_45 * V_46 ;
int V_29 , V_28 ;
T_2 V_3 , V_54 , V_55 ;
T_3 V_4 ;
T_1 V_6 ;
V_46 = & V_2 -> V_9 -> V_12 [ V_11 ] ;
for ( V_29 = 0 ; V_29 < F_15 ( V_38 ) ; V_29 ++ ) {
V_28 = F_34 ( V_2 , V_46 , V_38 [ V_29 ] . V_39 , false ,
& V_3 , & V_4 , & V_54 , & V_55 ) ;
if ( V_28 < 0 )
continue;
V_6 = F_1 ( V_2 , V_3 , V_4 ) ;
V_6 >>= V_54 ;
V_6 &= ( 1 << V_55 ) - 1 ;
F_10 ( V_18 , L_13 ,
F_43 ( V_38 [ V_29 ] . V_35 ) , V_6 ) ;
}
}
static void F_45 ( struct V_7 * V_8 ,
struct V_17 * V_18 ,
unsigned long V_31 )
{
enum V_52 V_39 = F_38 ( V_31 ) ;
T_4 V_110 = F_40 ( V_31 ) ;
const char * V_113 = L_14 ;
int V_29 ;
for ( V_29 = 0 ; V_29 < F_15 ( V_38 ) ; V_29 ++ ) {
if ( V_38 [ V_29 ] . V_39 == V_39 ) {
V_113 = V_38 [ V_29 ] . V_35 ;
break;
}
}
F_10 ( V_18 , L_15 , F_43 ( V_113 ) , V_110 ) ;
}
int F_46 ( struct V_114 * V_115 ,
const struct V_116 * V_117 )
{
struct V_1 * V_2 ;
struct V_118 * V_119 ;
int V_29 ;
const char * * V_120 ;
int V_121 , V_122 , V_123 ;
V_2 = F_47 ( & V_115 -> V_20 , sizeof( * V_2 ) , V_124 ) ;
if ( ! V_2 ) {
F_14 ( & V_115 -> V_20 , L_16 ) ;
return - V_125 ;
}
V_2 -> V_20 = & V_115 -> V_20 ;
V_2 -> V_9 = V_117 ;
V_2 -> V_120 = F_47 ( & V_115 -> V_20 ,
V_117 -> V_10 * 4 * sizeof( * V_2 -> V_120 ) ,
V_124 ) ;
if ( ! V_2 -> V_120 )
return - V_125 ;
V_120 = V_2 -> V_120 ;
for ( V_121 = 0 ; V_121 < V_117 -> V_42 ; V_121 ++ ) {
struct V_126 * V_127 = & V_117 -> V_43 [ V_121 ] ;
V_127 -> V_12 = V_120 ;
for ( V_122 = 0 ; V_122 < V_117 -> V_10 ; V_122 ++ ) {
const struct V_45 * V_46 = & V_117 -> V_12 [ V_122 ] ;
if ( V_46 -> V_47 == - 1 )
continue;
for ( V_123 = 0 ; V_123 < 4 ; V_123 ++ )
if ( V_46 -> V_48 [ V_123 ] == V_121 )
break;
if ( V_123 == 4 )
continue;
F_48 ( V_120 - V_2 -> V_120 >=
V_117 -> V_10 * 4 ) ;
* V_120 ++ = V_46 -> V_13 ;
V_127 -> V_10 ++ ;
}
}
V_128 . V_16 = V_2 -> V_9 -> V_129 ;
V_130 . V_13 = F_11 ( & V_115 -> V_20 ) ;
V_130 . V_14 = V_2 -> V_9 -> V_14 ;
V_130 . V_16 = V_2 -> V_9 -> V_16 ;
for ( V_29 = 0 ; ; V_29 ++ ) {
V_119 = F_49 ( V_115 , V_131 , V_29 ) ;
if ( ! V_119 )
break;
}
V_2 -> V_132 = V_29 ;
V_2 -> V_5 = F_47 ( & V_115 -> V_20 , V_2 -> V_132 * sizeof( * V_2 -> V_5 ) ,
V_124 ) ;
if ( ! V_2 -> V_5 ) {
F_14 ( & V_115 -> V_20 , L_17 ) ;
return - V_125 ;
}
for ( V_29 = 0 ; V_29 < V_2 -> V_132 ; V_29 ++ ) {
V_119 = F_49 ( V_115 , V_131 , V_29 ) ;
V_2 -> V_5 [ V_29 ] = F_50 ( & V_115 -> V_20 , V_119 ) ;
if ( F_51 ( V_2 -> V_5 [ V_29 ] ) )
return F_52 ( V_2 -> V_5 [ V_29 ] ) ;
}
V_2 -> V_133 = F_53 ( & V_130 , & V_115 -> V_20 , V_2 ) ;
if ( ! V_2 -> V_133 ) {
F_14 ( & V_115 -> V_20 , L_18 ) ;
return - V_134 ;
}
F_54 ( V_2 -> V_133 , & V_128 ) ;
F_55 ( V_115 , V_2 ) ;
F_56 ( & V_115 -> V_20 , L_19 ) ;
return 0 ;
}
int F_57 ( struct V_114 * V_115 )
{
struct V_1 * V_2 = F_58 ( V_115 ) ;
F_59 ( V_2 -> V_133 ) ;
return 0 ;
}
