static inline T_1 F_1 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_4 )
{
return F_2 ( V_2 -> V_5 [ V_3 ] + V_4 ) ;
}
static inline void F_3 ( struct V_1 * V_2 , T_1 V_6 , T_1 V_3 , T_1 V_4 )
{
F_4 ( V_6 , V_2 -> V_5 [ V_3 ] + V_4 ) ;
}
static int F_5 ( struct V_7 * V_8 ,
unsigned V_9 )
{
struct V_1 * V_2 = F_6 ( V_8 ) ;
if ( V_9 >= V_2 -> V_10 -> V_11 )
return - V_12 ;
return 0 ;
}
static const char * F_7 ( struct V_7 * V_8 ,
unsigned V_9 )
{
struct V_1 * V_2 = F_6 ( V_8 ) ;
if ( V_9 >= V_2 -> V_10 -> V_11 )
return NULL ;
return V_2 -> V_10 -> V_13 [ V_9 ] . V_14 ;
}
static int F_8 ( struct V_7 * V_8 ,
unsigned V_9 ,
const unsigned * * V_15 ,
unsigned * V_16 )
{
struct V_1 * V_2 = F_6 ( V_8 ) ;
if ( V_9 >= V_2 -> V_10 -> V_11 )
return - V_12 ;
* V_15 = V_2 -> V_10 -> V_13 [ V_9 ] . V_15 ;
* V_16 = V_2 -> V_10 -> V_13 [ V_9 ] . V_17 ;
return 0 ;
}
static void F_9 ( struct V_7 * V_8 ,
struct V_18 * V_19 ,
unsigned V_20 )
{
F_10 ( V_19 , L_1 V_21 ) ;
}
static int F_11 ( struct V_7 * V_8 ,
unsigned V_22 )
{
struct V_1 * V_2 = F_6 ( V_8 ) ;
if ( V_22 >= V_2 -> V_10 -> V_23 )
return - V_12 ;
return 0 ;
}
static const char * F_12 ( struct V_7 * V_8 ,
unsigned V_22 )
{
struct V_1 * V_2 = F_6 ( V_8 ) ;
if ( V_22 >= V_2 -> V_10 -> V_23 )
return NULL ;
return V_2 -> V_10 -> V_24 [ V_22 ] . V_14 ;
}
static int F_13 ( struct V_7 * V_8 ,
unsigned V_22 ,
const char * const * * V_13 ,
unsigned * const V_25 )
{
struct V_1 * V_2 = F_6 ( V_8 ) ;
if ( V_22 >= V_2 -> V_10 -> V_23 )
return - V_12 ;
* V_13 = V_2 -> V_10 -> V_24 [ V_22 ] . V_13 ;
* V_25 = V_2 -> V_10 -> V_24 [ V_22 ] . V_11 ;
return 0 ;
}
static int F_14 ( struct V_7 * V_8 , unsigned V_22 ,
unsigned V_9 )
{
struct V_1 * V_2 = F_6 ( V_8 ) ;
const struct V_26 * V_27 ;
int V_28 ;
T_1 V_6 ;
if ( V_9 >= V_2 -> V_10 -> V_11 )
return - V_12 ;
V_27 = & V_2 -> V_10 -> V_13 [ V_9 ] ;
if ( V_27 -> V_29 < 0 )
return - V_12 ;
for ( V_28 = 0 ; V_28 < F_15 ( V_27 -> V_30 ) ; V_28 ++ ) {
if ( V_27 -> V_30 [ V_28 ] == V_22 )
break;
}
if ( V_28 == F_15 ( V_27 -> V_30 ) )
return - V_12 ;
V_6 = F_1 ( V_2 , V_27 -> V_31 , V_27 -> V_29 ) ;
V_6 &= ~ ( 0x3 << V_27 -> V_32 ) ;
V_6 |= V_28 << V_27 -> V_32 ;
F_3 ( V_2 , V_6 , V_27 -> V_31 , V_27 -> V_29 ) ;
return 0 ;
}
static void F_16 ( struct V_7 * V_8 ,
unsigned V_22 , unsigned V_9 )
{
struct V_1 * V_2 = F_6 ( V_8 ) ;
const struct V_26 * V_27 ;
T_1 V_6 ;
if ( V_9 >= V_2 -> V_10 -> V_11 )
return;
V_27 = & V_2 -> V_10 -> V_13 [ V_9 ] ;
if ( V_27 -> V_29 < 0 )
return;
V_6 = F_1 ( V_2 , V_27 -> V_31 , V_27 -> V_29 ) ;
V_6 &= ~ ( 0x3 << V_27 -> V_32 ) ;
V_6 |= V_27 -> V_33 << V_27 -> V_32 ;
F_3 ( V_2 , V_6 , V_27 -> V_31 , V_27 -> V_29 ) ;
}
static int F_17 ( struct V_1 * V_2 ,
const struct V_26 * V_27 ,
enum V_34 V_35 ,
T_2 * V_3 , T_3 * V_4 , T_2 * V_36 , T_2 * V_37 )
{
switch ( V_35 ) {
case V_38 :
* V_3 = V_27 -> V_39 ;
* V_4 = V_27 -> V_40 ;
* V_36 = V_27 -> V_41 ;
* V_37 = 2 ;
break;
case V_42 :
* V_3 = V_27 -> V_43 ;
* V_4 = V_27 -> V_44 ;
* V_36 = V_27 -> V_45 ;
* V_37 = 1 ;
break;
case V_46 :
* V_3 = V_27 -> V_47 ;
* V_4 = V_27 -> V_48 ;
* V_36 = V_27 -> V_49 ;
* V_37 = 1 ;
break;
case V_50 :
* V_3 = V_27 -> V_51 ;
* V_4 = V_27 -> V_52 ;
* V_36 = V_27 -> V_53 ;
* V_37 = 1 ;
break;
case V_54 :
* V_3 = V_27 -> V_55 ;
* V_4 = V_27 -> V_56 ;
* V_36 = V_27 -> V_57 ;
* V_37 = 1 ;
break;
case V_58 :
* V_3 = V_27 -> V_59 ;
* V_4 = V_27 -> V_60 ;
* V_36 = V_27 -> V_61 ;
* V_37 = 1 ;
break;
case V_62 :
* V_3 = V_27 -> V_63 ;
* V_4 = V_27 -> V_64 ;
* V_36 = V_27 -> V_65 ;
* V_37 = 1 ;
break;
case V_66 :
* V_3 = V_27 -> V_63 ;
* V_4 = V_27 -> V_64 ;
* V_36 = V_27 -> V_67 ;
* V_37 = 1 ;
break;
case V_68 :
* V_3 = V_27 -> V_63 ;
* V_4 = V_27 -> V_64 ;
* V_36 = V_27 -> V_69 ;
* V_37 = 1 ;
break;
case V_70 :
* V_3 = V_27 -> V_63 ;
* V_4 = V_27 -> V_64 ;
* V_36 = V_27 -> V_71 ;
* V_37 = V_27 -> V_72 ;
break;
case V_73 :
* V_3 = V_27 -> V_63 ;
* V_4 = V_27 -> V_64 ;
* V_36 = V_27 -> V_74 ;
* V_37 = V_27 -> V_75 ;
break;
case V_76 :
* V_3 = V_27 -> V_63 ;
* V_4 = V_27 -> V_64 ;
* V_36 = V_27 -> V_77 ;
* V_37 = V_27 -> V_78 ;
break;
case V_79 :
* V_3 = V_27 -> V_63 ;
* V_4 = V_27 -> V_64 ;
* V_36 = V_27 -> V_80 ;
* V_37 = V_27 -> V_81 ;
break;
default:
F_18 ( V_2 -> V_82 , L_2 , V_35 ) ;
return - V_83 ;
}
if ( * V_4 < 0 ) {
F_18 ( V_2 -> V_82 ,
L_3 ,
V_35 , V_27 -> V_14 ) ;
return - V_83 ;
}
return 0 ;
}
static int F_19 ( struct V_7 * V_8 ,
unsigned V_84 , unsigned long * V_85 )
{
return - V_83 ;
}
static int F_20 ( struct V_7 * V_8 ,
unsigned V_84 , unsigned long V_85 )
{
return - V_83 ;
}
static int F_21 ( struct V_7 * V_8 ,
unsigned V_9 , unsigned long * V_85 )
{
struct V_1 * V_2 = F_6 ( V_8 ) ;
enum V_34 V_35 = F_22 ( * V_85 ) ;
T_4 V_86 ;
const struct V_26 * V_27 ;
int V_87 ;
T_2 V_3 , V_36 , V_37 ;
T_3 V_4 ;
T_1 V_6 , V_88 ;
if ( V_9 >= V_2 -> V_10 -> V_11 )
return - V_12 ;
V_27 = & V_2 -> V_10 -> V_13 [ V_9 ] ;
V_87 = F_17 ( V_2 , V_27 , V_35 , & V_3 , & V_4 , & V_36 , & V_37 ) ;
if ( V_87 < 0 )
return V_87 ;
V_6 = F_1 ( V_2 , V_3 , V_4 ) ;
V_88 = ( 1 << V_37 ) - 1 ;
V_86 = ( V_6 >> V_36 ) & V_88 ;
* V_85 = F_23 ( V_35 , V_86 ) ;
return 0 ;
}
static int F_24 ( struct V_7 * V_8 ,
unsigned V_9 , unsigned long V_85 )
{
struct V_1 * V_2 = F_6 ( V_8 ) ;
enum V_34 V_35 = F_22 ( V_85 ) ;
T_4 V_86 = F_25 ( V_85 ) ;
const struct V_26 * V_27 ;
int V_87 ;
T_2 V_3 , V_36 , V_37 ;
T_3 V_4 ;
T_1 V_6 , V_88 ;
if ( V_9 >= V_2 -> V_10 -> V_11 )
return - V_12 ;
V_27 = & V_2 -> V_10 -> V_13 [ V_9 ] ;
V_87 = F_17 ( V_2 , V_27 , V_35 , & V_3 , & V_4 , & V_36 , & V_37 ) ;
if ( V_87 < 0 )
return V_87 ;
V_6 = F_1 ( V_2 , V_3 , V_4 ) ;
if ( V_35 == V_54 ) {
if ( ( V_6 & F_26 ( V_36 ) ) && ! V_86 )
return - V_12 ;
}
if ( V_37 == 1 )
V_86 = ! ! V_86 ;
V_88 = ( 1 << V_37 ) - 1 ;
if ( V_86 & ~ V_88 )
return - V_12 ;
V_6 &= ~ ( V_88 << V_36 ) ;
V_6 |= V_86 << V_36 ;
F_3 ( V_2 , V_6 , V_3 , V_4 ) ;
return 0 ;
}
static void F_27 ( struct V_7 * V_8 ,
struct V_18 * V_19 , unsigned V_20 )
{
}
static void F_28 ( struct V_7 * V_8 ,
struct V_18 * V_19 , unsigned V_89 )
{
}
static int T_5 F_29 ( struct V_90 * V_91 )
{
const struct V_92 * V_93 ;
T_6 V_94 = NULL ;
struct V_1 * V_2 ;
struct V_95 * V_96 ;
int V_28 ;
V_93 = F_30 ( V_97 , & V_91 -> V_82 ) ;
if ( V_93 )
V_94 = ( T_6 ) V_93 -> V_98 ;
#ifdef F_31
if ( ! V_94 )
V_94 = V_99 ;
#endif
if ( ! V_94 ) {
F_18 ( & V_91 -> V_82 ,
L_4 ) ;
return - V_12 ;
}
V_2 = F_32 ( & V_91 -> V_82 , sizeof( * V_2 ) , V_100 ) ;
if ( ! V_2 ) {
F_18 ( & V_91 -> V_82 , L_5 ) ;
return - V_101 ;
}
V_2 -> V_82 = & V_91 -> V_82 ;
(* V_94)( & V_2 -> V_10 ) ;
V_102 . V_17 = V_2 -> V_10 -> V_103 ;
V_104 . V_15 = V_2 -> V_10 -> V_15 ;
V_104 . V_17 = V_2 -> V_10 -> V_17 ;
for ( V_28 = 0 ; ; V_28 ++ ) {
V_96 = F_33 ( V_91 , V_105 , V_28 ) ;
if ( ! V_96 )
break;
}
V_2 -> V_106 = V_28 ;
V_2 -> V_5 = F_32 ( & V_91 -> V_82 , V_2 -> V_106 * sizeof( * V_2 -> V_5 ) ,
V_100 ) ;
if ( ! V_2 -> V_5 ) {
F_18 ( & V_91 -> V_82 , L_6 ) ;
return - V_107 ;
}
for ( V_28 = 0 ; V_28 < V_2 -> V_106 ; V_28 ++ ) {
V_96 = F_33 ( V_91 , V_105 , V_28 ) ;
if ( ! V_96 ) {
F_18 ( & V_91 -> V_82 , L_7 ) ;
return - V_107 ;
}
if ( ! F_34 ( & V_91 -> V_82 , V_96 -> V_108 ,
F_35 ( V_96 ) ,
F_36 ( & V_91 -> V_82 ) ) ) {
F_18 ( & V_91 -> V_82 ,
L_8 , V_28 ) ;
return - V_107 ;
}
V_2 -> V_5 [ V_28 ] = F_37 ( & V_91 -> V_82 , V_96 -> V_108 ,
F_35 ( V_96 ) ) ;
if ( ! V_2 -> V_5 [ V_28 ] ) {
F_18 ( & V_91 -> V_82 , L_9 , V_28 ) ;
return - V_107 ;
}
}
V_2 -> V_109 = F_38 ( & V_104 , & V_91 -> V_82 , V_2 ) ;
if ( F_39 ( V_2 -> V_109 ) ) {
F_18 ( & V_91 -> V_82 , L_10 ) ;
return F_40 ( V_2 -> V_109 ) ;
}
F_41 ( V_2 -> V_109 , & V_102 ) ;
F_42 ( V_91 , V_2 ) ;
F_43 ( & V_91 -> V_82 , L_11 ) ;
return 0 ;
}
static int T_7 F_44 ( struct V_90 * V_91 )
{
struct V_1 * V_2 = F_45 ( V_91 ) ;
F_46 ( V_2 -> V_109 , & V_102 ) ;
F_47 ( V_2 -> V_109 ) ;
return 0 ;
}
static int T_8 F_48 ( void )
{
return F_49 ( & V_110 ) ;
}
static void T_9 F_50 ( void )
{
F_51 ( & V_110 ) ;
}
