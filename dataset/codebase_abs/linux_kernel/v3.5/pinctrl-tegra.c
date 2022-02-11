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
static int F_12 ( struct V_21 * V_20 , struct V_22 * * V_23 ,
unsigned * V_24 , unsigned * V_25 ,
unsigned V_26 )
{
unsigned V_27 = * V_24 ;
unsigned V_28 = * V_25 + V_26 ;
struct V_22 * V_29 ;
if ( V_27 >= V_28 )
return 0 ;
V_29 = F_13 ( * V_23 , sizeof( * V_29 ) * V_28 , V_30 ) ;
if ( ! V_29 ) {
F_14 ( V_20 , L_2 ) ;
return - V_31 ;
}
memset ( V_29 + V_27 , 0 , ( V_28 - V_27 ) * sizeof( * V_29 ) ) ;
* V_23 = V_29 ;
* V_24 = V_28 ;
return 0 ;
}
static int F_15 ( struct V_22 * * V_23 , unsigned * V_24 ,
unsigned * V_25 , const char * V_11 ,
const char * V_32 )
{
if ( F_16 ( * V_25 == * V_24 ) )
return - V_33 ;
( * V_23 ) [ * V_25 ] . type = V_34 ;
( * V_23 ) [ * V_25 ] . V_35 . V_36 . V_11 = V_11 ;
( * V_23 ) [ * V_25 ] . V_35 . V_36 . V_32 = V_32 ;
( * V_25 ) ++ ;
return 0 ;
}
static int F_17 ( struct V_21 * V_20 , struct V_22 * * V_23 ,
unsigned * V_24 , unsigned * V_25 ,
const char * V_11 , unsigned long * V_37 ,
unsigned V_38 )
{
unsigned long * V_39 ;
if ( F_16 ( * V_25 == * V_24 ) )
return - V_33 ;
V_39 = F_18 ( V_37 , V_38 * sizeof( * V_39 ) ,
V_30 ) ;
if ( ! V_39 ) {
F_14 ( V_20 , L_3 ) ;
return - V_31 ;
}
( * V_23 ) [ * V_25 ] . type = V_40 ;
( * V_23 ) [ * V_25 ] . V_35 . V_37 . V_41 = V_11 ;
( * V_23 ) [ * V_25 ] . V_35 . V_37 . V_37 = V_39 ;
( * V_23 ) [ * V_25 ] . V_35 . V_37 . V_38 = V_38 ;
( * V_25 ) ++ ;
return 0 ;
}
static int F_19 ( struct V_21 * V_20 , unsigned long * * V_37 ,
unsigned * V_38 , unsigned long V_42 )
{
unsigned V_27 = * V_38 ;
unsigned V_28 = V_27 + 1 ;
unsigned long * V_43 ;
V_43 = F_13 ( * V_37 , sizeof( * V_43 ) * V_28 ,
V_30 ) ;
if ( ! V_43 ) {
F_14 ( V_20 , L_4 ) ;
return - V_31 ;
}
V_43 [ V_27 ] = V_42 ;
* V_37 = V_43 ;
* V_38 = V_28 ;
return 0 ;
}
void F_20 ( struct V_7 * V_8 ,
struct V_22 * V_23 , unsigned V_25 )
{
int V_44 ;
for ( V_44 = 0 ; V_44 < V_25 ; V_44 ++ )
if ( V_23 [ V_44 ] . type == V_40 )
F_21 ( V_23 [ V_44 ] . V_35 . V_37 . V_37 ) ;
F_21 ( V_23 ) ;
}
int F_22 ( struct V_21 * V_20 ,
struct V_45 * V_46 ,
struct V_22 * * V_23 ,
unsigned * V_24 ,
unsigned * V_25 )
{
int V_47 , V_44 ;
const char * V_32 ;
T_1 V_6 ;
unsigned long V_42 ;
unsigned long * V_37 = NULL ;
unsigned V_38 = 0 ;
unsigned V_26 ;
struct V_48 * V_49 ;
const char * V_11 ;
V_47 = F_23 ( V_46 , L_5 , & V_32 ) ;
if ( V_47 < 0 ) {
if ( V_47 != - V_50 )
F_14 ( V_20 ,
L_6 ) ;
V_32 = NULL ;
}
for ( V_44 = 0 ; V_44 < F_24 ( V_51 ) ; V_44 ++ ) {
V_47 = F_25 ( V_46 , V_51 [ V_44 ] . V_48 , & V_6 ) ;
if ( ! V_47 ) {
V_42 = F_26 ( V_51 [ V_44 ] . V_52 , V_6 ) ;
V_47 = F_19 ( V_20 , & V_37 , & V_38 , V_42 ) ;
if ( V_47 < 0 )
goto exit;
} else if ( V_47 != - V_50 ) {
F_14 ( V_20 , L_7 ,
V_51 [ V_44 ] . V_48 ) ;
}
}
V_26 = 0 ;
if ( V_32 != NULL )
V_26 ++ ;
if ( V_38 )
V_26 ++ ;
V_47 = F_27 ( V_46 , L_8 ) ;
if ( V_47 < 0 ) {
F_14 ( V_20 , L_9 ) ;
goto exit;
}
V_26 *= V_47 ;
V_47 = F_12 ( V_20 , V_23 , V_24 , V_25 , V_26 ) ;
if ( V_47 < 0 )
goto exit;
F_28 (np, L_8 , prop, group) {
if ( V_32 ) {
V_47 = F_15 ( V_23 , V_24 , V_25 ,
V_11 , V_32 ) ;
if ( V_47 < 0 )
goto exit;
}
if ( V_38 ) {
V_47 = F_17 ( V_20 , V_23 , V_24 ,
V_25 , V_11 , V_37 ,
V_38 ) ;
if ( V_47 < 0 )
goto exit;
}
}
V_47 = 0 ;
exit:
F_21 ( V_37 ) ;
return V_47 ;
}
int F_29 ( struct V_7 * V_8 ,
struct V_45 * V_53 ,
struct V_22 * * V_23 , unsigned * V_25 )
{
unsigned V_24 ;
struct V_45 * V_46 ;
int V_47 ;
V_24 = 0 ;
* V_23 = NULL ;
* V_25 = 0 ;
F_30 (np_config, np) {
V_47 = F_22 ( V_8 -> V_20 , V_46 , V_23 ,
& V_24 , V_25 ) ;
if ( V_47 < 0 ) {
F_20 ( V_8 , * V_23 , * V_25 ) ;
return V_47 ;
}
}
return 0 ;
}
static int F_31 ( struct V_7 * V_8 )
{
struct V_1 * V_2 = F_6 ( V_8 ) ;
return V_2 -> V_9 -> V_54 ;
}
static const char * F_32 ( struct V_7 * V_8 ,
unsigned V_32 )
{
struct V_1 * V_2 = F_6 ( V_8 ) ;
return V_2 -> V_9 -> V_55 [ V_32 ] . V_13 ;
}
static int F_33 ( struct V_7 * V_8 ,
unsigned V_32 ,
const char * const * * V_12 ,
unsigned * const V_56 )
{
struct V_1 * V_2 = F_6 ( V_8 ) ;
* V_12 = V_2 -> V_9 -> V_55 [ V_32 ] . V_12 ;
* V_56 = V_2 -> V_9 -> V_55 [ V_32 ] . V_10 ;
return 0 ;
}
static int F_34 ( struct V_7 * V_8 , unsigned V_32 ,
unsigned V_11 )
{
struct V_1 * V_2 = F_6 ( V_8 ) ;
const struct V_57 * V_58 ;
int V_44 ;
T_1 V_6 ;
V_58 = & V_2 -> V_9 -> V_12 [ V_11 ] ;
if ( F_16 ( V_58 -> V_59 < 0 ) )
return - V_50 ;
for ( V_44 = 0 ; V_44 < F_24 ( V_58 -> V_60 ) ; V_44 ++ ) {
if ( V_58 -> V_60 [ V_44 ] == V_32 )
break;
}
if ( F_16 ( V_44 == F_24 ( V_58 -> V_60 ) ) )
return - V_50 ;
V_6 = F_1 ( V_2 , V_58 -> V_61 , V_58 -> V_59 ) ;
V_6 &= ~ ( 0x3 << V_58 -> V_62 ) ;
V_6 |= V_44 << V_58 -> V_62 ;
F_3 ( V_2 , V_6 , V_58 -> V_61 , V_58 -> V_59 ) ;
return 0 ;
}
static void F_35 ( struct V_7 * V_8 ,
unsigned V_32 , unsigned V_11 )
{
struct V_1 * V_2 = F_6 ( V_8 ) ;
const struct V_57 * V_58 ;
T_1 V_6 ;
V_58 = & V_2 -> V_9 -> V_12 [ V_11 ] ;
if ( F_16 ( V_58 -> V_59 < 0 ) )
return;
V_6 = F_1 ( V_2 , V_58 -> V_61 , V_58 -> V_59 ) ;
V_6 &= ~ ( 0x3 << V_58 -> V_62 ) ;
V_6 |= V_58 -> V_63 << V_58 -> V_62 ;
F_3 ( V_2 , V_6 , V_58 -> V_61 , V_58 -> V_59 ) ;
}
static int F_36 ( struct V_1 * V_2 ,
const struct V_57 * V_58 ,
enum V_64 V_52 ,
bool V_65 ,
T_2 * V_3 , T_3 * V_4 , T_2 * V_66 , T_2 * V_67 )
{
switch ( V_52 ) {
case V_68 :
* V_3 = V_58 -> V_69 ;
* V_4 = V_58 -> V_70 ;
* V_66 = V_58 -> V_71 ;
* V_67 = 2 ;
break;
case V_72 :
* V_3 = V_58 -> V_73 ;
* V_4 = V_58 -> V_74 ;
* V_66 = V_58 -> V_75 ;
* V_67 = 1 ;
break;
case V_76 :
* V_3 = V_58 -> V_77 ;
* V_4 = V_58 -> V_78 ;
* V_66 = V_58 -> V_79 ;
* V_67 = 1 ;
break;
case V_80 :
* V_3 = V_58 -> V_81 ;
* V_4 = V_58 -> V_82 ;
* V_66 = V_58 -> V_83 ;
* V_67 = 1 ;
break;
case V_84 :
* V_3 = V_58 -> V_85 ;
* V_4 = V_58 -> V_86 ;
* V_66 = V_58 -> V_87 ;
* V_67 = 1 ;
break;
case V_88 :
* V_3 = V_58 -> V_89 ;
* V_4 = V_58 -> V_90 ;
* V_66 = V_58 -> V_91 ;
* V_67 = 1 ;
break;
case V_92 :
* V_3 = V_58 -> V_93 ;
* V_4 = V_58 -> V_94 ;
* V_66 = V_58 -> V_95 ;
* V_67 = 1 ;
break;
case V_96 :
* V_3 = V_58 -> V_93 ;
* V_4 = V_58 -> V_94 ;
* V_66 = V_58 -> V_97 ;
* V_67 = 1 ;
break;
case V_98 :
* V_3 = V_58 -> V_93 ;
* V_4 = V_58 -> V_94 ;
* V_66 = V_58 -> V_99 ;
* V_67 = 1 ;
break;
case V_100 :
* V_3 = V_58 -> V_93 ;
* V_4 = V_58 -> V_94 ;
* V_66 = V_58 -> V_101 ;
* V_67 = V_58 -> V_102 ;
break;
case V_103 :
* V_3 = V_58 -> V_93 ;
* V_4 = V_58 -> V_94 ;
* V_66 = V_58 -> V_104 ;
* V_67 = V_58 -> V_105 ;
break;
case V_106 :
* V_3 = V_58 -> V_93 ;
* V_4 = V_58 -> V_94 ;
* V_66 = V_58 -> V_107 ;
* V_67 = V_58 -> V_108 ;
break;
case V_109 :
* V_3 = V_58 -> V_93 ;
* V_4 = V_58 -> V_94 ;
* V_66 = V_58 -> V_110 ;
* V_67 = V_58 -> V_111 ;
break;
default:
F_14 ( V_2 -> V_20 , L_10 , V_52 ) ;
return - V_112 ;
}
if ( * V_4 < 0 ) {
if ( V_65 )
F_14 ( V_2 -> V_20 ,
L_11 ,
V_52 , V_58 -> V_13 ) ;
return - V_112 ;
}
return 0 ;
}
static int F_37 ( struct V_7 * V_8 ,
unsigned V_113 , unsigned long * V_42 )
{
F_14 ( V_8 -> V_20 , L_12 ) ;
return - V_112 ;
}
static int F_38 ( struct V_7 * V_8 ,
unsigned V_113 , unsigned long V_42 )
{
F_14 ( V_8 -> V_20 , L_13 ) ;
return - V_112 ;
}
static int F_39 ( struct V_7 * V_8 ,
unsigned V_11 , unsigned long * V_42 )
{
struct V_1 * V_2 = F_6 ( V_8 ) ;
enum V_64 V_52 = F_40 ( * V_42 ) ;
T_4 V_114 ;
const struct V_57 * V_58 ;
int V_47 ;
T_2 V_3 , V_66 , V_67 ;
T_3 V_4 ;
T_1 V_6 , V_115 ;
V_58 = & V_2 -> V_9 -> V_12 [ V_11 ] ;
V_47 = F_36 ( V_2 , V_58 , V_52 , true , & V_3 , & V_4 , & V_66 ,
& V_67 ) ;
if ( V_47 < 0 )
return V_47 ;
V_6 = F_1 ( V_2 , V_3 , V_4 ) ;
V_115 = ( 1 << V_67 ) - 1 ;
V_114 = ( V_6 >> V_66 ) & V_115 ;
* V_42 = F_26 ( V_52 , V_114 ) ;
return 0 ;
}
static int F_41 ( struct V_7 * V_8 ,
unsigned V_11 , unsigned long V_42 )
{
struct V_1 * V_2 = F_6 ( V_8 ) ;
enum V_64 V_52 = F_40 ( V_42 ) ;
T_4 V_114 = F_42 ( V_42 ) ;
const struct V_57 * V_58 ;
int V_47 ;
T_2 V_3 , V_66 , V_67 ;
T_3 V_4 ;
T_1 V_6 , V_115 ;
V_58 = & V_2 -> V_9 -> V_12 [ V_11 ] ;
V_47 = F_36 ( V_2 , V_58 , V_52 , true , & V_3 , & V_4 , & V_66 ,
& V_67 ) ;
if ( V_47 < 0 )
return V_47 ;
V_6 = F_1 ( V_2 , V_3 , V_4 ) ;
if ( V_52 == V_84 ) {
if ( ( V_6 & F_43 ( V_66 ) ) && ! V_114 ) {
F_14 ( V_8 -> V_20 , L_14 ) ;
return - V_50 ;
}
}
if ( V_67 == 1 )
V_114 = ! ! V_114 ;
V_115 = ( 1 << V_67 ) - 1 ;
if ( V_114 & ~ V_115 ) {
F_14 ( V_8 -> V_20 ,
L_15 ,
V_42 , V_114 , V_67 ) ;
return - V_50 ;
}
V_6 &= ~ ( V_115 << V_66 ) ;
V_6 |= V_114 << V_66 ;
F_3 ( V_2 , V_6 , V_3 , V_4 ) ;
return 0 ;
}
static void F_44 ( struct V_7 * V_8 ,
struct V_17 * V_18 , unsigned V_19 )
{
}
static const char * F_45 ( const char * V_18 )
{
const char * V_116 = strchr ( V_18 , ',' ) ;
if ( ! V_116 )
return V_18 ;
return V_116 + 1 ;
}
static void F_46 ( struct V_7 * V_8 ,
struct V_17 * V_18 , unsigned V_11 )
{
struct V_1 * V_2 = F_6 ( V_8 ) ;
const struct V_57 * V_58 ;
int V_44 , V_47 ;
T_2 V_3 , V_66 , V_67 ;
T_3 V_4 ;
T_1 V_6 ;
V_58 = & V_2 -> V_9 -> V_12 [ V_11 ] ;
for ( V_44 = 0 ; V_44 < F_24 ( V_51 ) ; V_44 ++ ) {
V_47 = F_36 ( V_2 , V_58 , V_51 [ V_44 ] . V_52 , false ,
& V_3 , & V_4 , & V_66 , & V_67 ) ;
if ( V_47 < 0 )
continue;
V_6 = F_1 ( V_2 , V_3 , V_4 ) ;
V_6 >>= V_66 ;
V_6 &= ( 1 << V_67 ) - 1 ;
F_10 ( V_18 , L_16 ,
F_45 ( V_51 [ V_44 ] . V_48 ) , V_6 ) ;
}
}
static void F_47 ( struct V_7 * V_8 ,
struct V_17 * V_18 ,
unsigned long V_42 )
{
enum V_64 V_52 = F_40 ( V_42 ) ;
T_4 V_114 = F_42 ( V_42 ) ;
const char * V_117 = L_17 ;
int V_44 ;
for ( V_44 = 0 ; V_44 < F_24 ( V_51 ) ; V_44 ++ ) {
if ( V_51 [ V_44 ] . V_52 == V_52 ) {
V_117 = V_51 [ V_44 ] . V_48 ;
break;
}
}
F_10 ( V_18 , L_18 , F_45 ( V_117 ) , V_114 ) ;
}
int T_5 F_48 ( struct V_118 * V_119 ,
const struct V_120 * V_121 )
{
struct V_1 * V_2 ;
struct V_122 * V_123 ;
int V_44 ;
V_2 = F_49 ( & V_119 -> V_20 , sizeof( * V_2 ) , V_30 ) ;
if ( ! V_2 ) {
F_14 ( & V_119 -> V_20 , L_19 ) ;
return - V_31 ;
}
V_2 -> V_20 = & V_119 -> V_20 ;
V_2 -> V_9 = V_121 ;
V_124 . V_16 = V_2 -> V_9 -> V_125 ;
V_126 . V_13 = F_11 ( & V_119 -> V_20 ) ;
V_126 . V_14 = V_2 -> V_9 -> V_14 ;
V_126 . V_16 = V_2 -> V_9 -> V_16 ;
for ( V_44 = 0 ; ; V_44 ++ ) {
V_123 = F_50 ( V_119 , V_127 , V_44 ) ;
if ( ! V_123 )
break;
}
V_2 -> V_128 = V_44 ;
V_2 -> V_5 = F_49 ( & V_119 -> V_20 , V_2 -> V_128 * sizeof( * V_2 -> V_5 ) ,
V_30 ) ;
if ( ! V_2 -> V_5 ) {
F_14 ( & V_119 -> V_20 , L_20 ) ;
return - V_129 ;
}
for ( V_44 = 0 ; V_44 < V_2 -> V_128 ; V_44 ++ ) {
V_123 = F_50 ( V_119 , V_127 , V_44 ) ;
if ( ! V_123 ) {
F_14 ( & V_119 -> V_20 , L_21 ) ;
return - V_129 ;
}
if ( ! F_51 ( & V_119 -> V_20 , V_123 -> V_130 ,
F_52 ( V_123 ) ,
F_11 ( & V_119 -> V_20 ) ) ) {
F_14 ( & V_119 -> V_20 ,
L_22 , V_44 ) ;
return - V_129 ;
}
V_2 -> V_5 [ V_44 ] = F_53 ( & V_119 -> V_20 , V_123 -> V_130 ,
F_52 ( V_123 ) ) ;
if ( ! V_2 -> V_5 [ V_44 ] ) {
F_14 ( & V_119 -> V_20 , L_23 , V_44 ) ;
return - V_129 ;
}
}
V_2 -> V_131 = F_54 ( & V_126 , & V_119 -> V_20 , V_2 ) ;
if ( F_55 ( V_2 -> V_131 ) ) {
F_14 ( & V_119 -> V_20 , L_24 ) ;
return F_56 ( V_2 -> V_131 ) ;
}
F_57 ( V_2 -> V_131 , & V_124 ) ;
F_58 ( V_119 , V_2 ) ;
F_59 ( & V_119 -> V_20 , L_25 ) ;
return 0 ;
}
int T_6 F_60 ( struct V_118 * V_119 )
{
struct V_1 * V_2 = F_61 ( V_119 ) ;
F_62 ( V_2 -> V_131 , & V_124 ) ;
F_63 ( V_2 -> V_131 ) ;
return 0 ;
}
