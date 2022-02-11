static struct V_1 *
F_1 ( struct V_2 * V_3 , const char * V_4 )
{
int V_5 ;
for ( V_5 = 0 ; V_5 < V_3 -> V_6 ; V_5 ++ ) {
struct V_1 * V_7 = V_3 -> V_8 + V_5 ;
if ( ! strcmp ( V_7 -> V_9 , V_4 ) )
return V_7 ;
}
return NULL ;
}
static struct V_10 *
F_2 ( struct V_2 * V_3 ,
const char * V_9 )
{
struct V_10 * V_11 = V_3 -> V_12 ;
int V_5 ;
for ( V_5 = 0 ; V_5 < V_3 -> V_13 ; V_5 ++ ) {
if ( ! V_11 [ V_5 ] . V_9 )
break;
if ( ! strcmp ( V_11 [ V_5 ] . V_9 , V_9 ) )
return V_11 + V_5 ;
}
return NULL ;
}
static struct V_14 *
F_3 ( struct V_2 * V_3 ,
const char * V_15 ,
const char * V_16 )
{
int V_5 ;
for ( V_5 = 0 ; V_5 < V_3 -> V_17 -> V_18 ; V_5 ++ ) {
const struct V_19 * V_20 = V_3 -> V_17 -> V_21 + V_5 ;
if ( ! strcmp ( V_20 -> V_20 . V_9 , V_15 ) ) {
struct V_14 * V_11 = V_20 -> V_12 ;
while ( V_11 -> V_9 ) {
if ( ! strcmp ( V_11 -> V_9 , V_16 ) )
return V_11 ;
V_11 ++ ;
}
}
}
return NULL ;
}
static struct V_14 *
F_4 ( struct V_2 * V_3 ,
const T_1 V_22 ,
const char * V_16 )
{
int V_5 ;
for ( V_5 = 0 ; V_5 < V_3 -> V_17 -> V_18 ; V_5 ++ ) {
const struct V_19 * V_20 = V_3 -> V_17 -> V_21 + V_5 ;
if ( V_20 -> V_20 . V_23 == V_22 ) {
struct V_14 * V_11 = V_20 -> V_12 ;
while ( V_11 -> V_9 ) {
if ( ! strcmp ( V_11 -> V_9 , V_16 ) )
return V_11 ;
V_11 ++ ;
}
}
}
return NULL ;
}
static int F_5 ( struct V_24 * V_25 )
{
struct V_2 * V_3 = F_6 ( V_25 ) ;
return V_3 -> V_6 ;
}
static const char * F_7 ( struct V_24 * V_25 ,
unsigned V_4 )
{
struct V_2 * V_3 = F_6 ( V_25 ) ;
return V_3 -> V_8 [ V_4 ] . V_9 ;
}
static int F_8 ( struct V_24 * V_25 ,
unsigned V_4 ,
const unsigned * * V_21 ,
unsigned * V_26 )
{
struct V_2 * V_3 = F_6 ( V_25 ) ;
* V_21 = ( unsigned * ) & V_3 -> V_8 [ V_4 ] . V_20 ;
* V_26 = 1 ;
return 0 ;
}
static int F_9 ( struct V_24 * V_25 ,
struct V_27 * V_28 ,
struct V_29 * * V_30 ,
unsigned * V_31 )
{
struct V_2 * V_3 = F_6 ( V_25 ) ;
unsigned long * V_32 ;
struct V_33 * V_34 ;
const char * V_35 ;
const char * V_4 ;
int V_36 , V_37 , V_5 = 0 ;
T_2 V_38 ;
* V_30 = NULL ;
* V_31 = 0 ;
V_36 = F_10 ( V_28 , L_1 , & V_35 ) ;
if ( V_36 ) {
F_11 ( V_3 -> V_39 ,
L_2 ,
V_28 -> V_9 ) ;
return - V_40 ;
}
V_37 = F_12 ( V_28 , L_3 ) * 2 ;
if ( V_37 < 0 ) {
F_11 ( V_3 -> V_39 ,
L_4 ,
V_28 -> V_9 ) ;
return - V_40 ;
}
* V_30 = F_13 ( V_37 * sizeof( struct V_29 ) , V_41 ) ;
if ( ! V_30 )
return - V_42 ;
F_14 (node, L_3 , prop, group) {
struct V_1 * V_7 =
F_1 ( V_3 , V_4 ) ;
int V_43 = 0 , V_44 = 0 ;
if ( ! V_7 ) {
F_11 ( V_3 -> V_39 , L_5 , V_4 ) ;
continue;
}
if ( ! F_3 ( V_3 ,
V_7 -> V_9 ,
V_35 ) ) {
F_11 ( V_3 -> V_39 , L_6 ,
V_35 , V_4 ) ;
continue;
}
( * V_30 ) [ V_5 ] . type = V_45 ;
( * V_30 ) [ V_5 ] . V_46 . V_47 . V_4 = V_4 ;
( * V_30 ) [ V_5 ] . V_46 . V_47 . V_35 = V_35 ;
V_5 ++ ;
( * V_30 ) [ V_5 ] . type = V_48 ;
( * V_30 ) [ V_5 ] . V_46 . V_49 . V_50 = V_4 ;
if ( F_15 ( V_28 , L_7 , NULL ) )
V_44 ++ ;
if ( F_15 ( V_28 , L_8 , NULL ) )
V_44 ++ ;
V_32 = F_16 ( V_44 * sizeof( * V_32 ) , V_41 ) ;
if ( ! F_17 ( V_28 , L_7 , & V_38 ) ) {
T_1 V_51 = ( V_38 + 1 ) * 10 ;
V_32 [ V_43 ++ ] =
F_18 ( V_52 ,
V_51 ) ;
}
if ( ! F_17 ( V_28 , L_8 , & V_38 ) ) {
enum V_53 V_54 = V_55 ;
if ( V_38 == 1 )
V_54 = V_56 ;
else if ( V_38 == 2 )
V_54 = V_57 ;
V_32 [ V_43 ++ ] = F_18 ( V_54 , 0 ) ;
}
( * V_30 ) [ V_5 ] . V_46 . V_49 . V_49 = V_32 ;
( * V_30 ) [ V_5 ] . V_46 . V_49 . V_58 = V_44 ;
V_5 ++ ;
}
* V_31 = V_37 ;
return 0 ;
}
static void F_19 ( struct V_24 * V_25 ,
struct V_29 * V_30 ,
unsigned V_31 )
{
int V_5 ;
for ( V_5 = 0 ; V_5 < V_31 ; V_5 ++ ) {
if ( V_30 [ V_5 ] . type == V_48 )
F_20 ( V_30 [ V_5 ] . V_46 . V_49 . V_49 ) ;
}
F_20 ( V_30 ) ;
}
static int F_21 ( struct V_24 * V_25 ,
unsigned V_4 ,
unsigned long * V_59 )
{
struct V_2 * V_3 = F_6 ( V_25 ) ;
* V_59 = V_3 -> V_8 [ V_4 ] . V_59 ;
return 0 ;
}
static int F_22 ( struct V_24 * V_25 ,
unsigned V_4 ,
unsigned long V_59 )
{
struct V_2 * V_3 = F_6 ( V_25 ) ;
struct V_1 * V_60 = & V_3 -> V_8 [ V_4 ] ;
unsigned long V_61 ;
T_2 V_38 , V_62 ;
T_1 V_51 ;
T_3 V_63 ;
switch ( F_23 ( V_59 ) ) {
case V_52 :
V_51 = F_24 ( V_59 ) ;
if ( V_51 > 40 )
return - V_40 ;
V_63 = V_51 / 10 - 1 ;
F_25 ( & V_3 -> V_64 , V_61 ) ;
V_38 = F_26 ( V_3 -> V_65 + F_27 ( V_60 -> V_20 ) ) ;
V_62 = V_66 << F_28 ( V_60 -> V_20 ) ;
F_29 ( ( V_38 & ~ V_62 ) | V_63 << F_28 ( V_60 -> V_20 ) ,
V_3 -> V_65 + F_27 ( V_60 -> V_20 ) ) ;
F_30 ( & V_3 -> V_64 , V_61 ) ;
break;
case V_56 :
F_25 ( & V_3 -> V_64 , V_61 ) ;
V_38 = F_26 ( V_3 -> V_65 + F_31 ( V_60 -> V_20 ) ) ;
V_62 = V_67 << F_32 ( V_60 -> V_20 ) ;
F_29 ( ( V_38 & ~ V_62 ) | 1 << F_32 ( V_60 -> V_20 ) ,
V_3 -> V_65 + F_31 ( V_60 -> V_20 ) ) ;
F_30 ( & V_3 -> V_64 , V_61 ) ;
break;
case V_57 :
F_25 ( & V_3 -> V_64 , V_61 ) ;
V_38 = F_26 ( V_3 -> V_65 + F_31 ( V_60 -> V_20 ) ) ;
V_62 = V_67 << F_32 ( V_60 -> V_20 ) ;
F_29 ( ( V_38 & ~ V_62 ) | 2 << F_32 ( V_60 -> V_20 ) ,
V_3 -> V_65 + F_31 ( V_60 -> V_20 ) ) ;
F_30 ( & V_3 -> V_64 , V_61 ) ;
break;
default:
break;
}
V_60 -> V_59 = V_59 ;
return 0 ;
}
static int F_33 ( struct V_24 * V_25 )
{
struct V_2 * V_3 = F_6 ( V_25 ) ;
return V_3 -> V_13 ;
}
static const char * F_34 ( struct V_24 * V_25 ,
unsigned V_35 )
{
struct V_2 * V_3 = F_6 ( V_25 ) ;
return V_3 -> V_12 [ V_35 ] . V_9 ;
}
static int F_35 ( struct V_24 * V_25 ,
unsigned V_35 ,
const char * const * * V_8 ,
unsigned * const V_68 )
{
struct V_2 * V_3 = F_6 ( V_25 ) ;
* V_8 = V_3 -> V_12 [ V_35 ] . V_8 ;
* V_68 = V_3 -> V_12 [ V_35 ] . V_6 ;
return 0 ;
}
static void F_36 ( struct V_24 * V_25 ,
unsigned V_20 ,
T_3 V_59 )
{
struct V_2 * V_3 = F_6 ( V_25 ) ;
unsigned long V_61 ;
T_2 V_38 , V_62 ;
F_25 ( & V_3 -> V_64 , V_61 ) ;
V_38 = F_26 ( V_3 -> V_65 + F_37 ( V_20 ) ) ;
V_62 = V_69 << F_38 ( V_20 ) ;
F_29 ( ( V_38 & ~ V_62 ) | V_59 << F_38 ( V_20 ) ,
V_3 -> V_65 + F_37 ( V_20 ) ) ;
F_30 ( & V_3 -> V_64 , V_61 ) ;
}
static int F_39 ( struct V_24 * V_25 ,
unsigned V_35 ,
unsigned V_4 )
{
struct V_2 * V_3 = F_6 ( V_25 ) ;
struct V_1 * V_60 = V_3 -> V_8 + V_4 ;
struct V_10 * V_11 = V_3 -> V_12 + V_35 ;
struct V_14 * V_17 =
F_3 ( V_3 ,
V_60 -> V_9 ,
V_11 -> V_9 ) ;
if ( ! V_17 )
return - V_40 ;
F_36 ( V_25 , V_60 -> V_20 , V_17 -> V_70 ) ;
return 0 ;
}
static int
F_40 ( struct V_24 * V_25 ,
struct V_71 * V_72 ,
unsigned V_73 ,
bool V_74 )
{
struct V_2 * V_3 = F_6 ( V_25 ) ;
struct V_14 * V_17 ;
const char * V_11 ;
if ( V_74 )
V_11 = L_9 ;
else
V_11 = L_10 ;
V_17 = F_4 ( V_3 , V_73 , V_11 ) ;
if ( ! V_17 )
return - V_40 ;
F_36 ( V_25 , V_73 , V_17 -> V_70 ) ;
return 0 ;
}
static int F_41 ( struct V_75 * V_76 , unsigned V_73 )
{
return F_42 ( V_76 -> V_77 + V_73 ) ;
}
static void F_43 ( struct V_75 * V_76 , unsigned V_73 )
{
F_44 ( V_76 -> V_77 + V_73 ) ;
}
static int F_45 ( struct V_75 * V_76 ,
unsigned V_73 )
{
return F_46 ( V_76 -> V_77 + V_73 ) ;
}
static int F_47 ( struct V_75 * V_76 , unsigned V_73 )
{
struct V_2 * V_3 = F_48 ( V_76 -> V_39 ) ;
T_2 V_78 = F_49 ( V_73 ) ;
T_3 V_79 = F_50 ( V_73 ) ;
T_2 V_38 = ( F_26 ( V_3 -> V_65 + V_78 ) >> V_79 ) & V_80 ;
return V_38 ;
}
static int F_51 ( struct V_75 * V_76 ,
unsigned V_73 , int V_81 )
{
return F_52 ( V_76 -> V_77 + V_73 ) ;
}
static void F_53 ( struct V_75 * V_76 ,
unsigned V_73 , int V_81 )
{
struct V_2 * V_3 = F_48 ( V_76 -> V_39 ) ;
T_2 V_78 = F_49 ( V_73 ) ;
T_3 V_79 = F_50 ( V_73 ) ;
unsigned long V_61 ;
T_2 V_82 ;
F_25 ( & V_3 -> V_64 , V_61 ) ;
V_82 = F_26 ( V_3 -> V_65 + V_78 ) ;
if ( V_81 )
V_82 |= F_54 ( V_79 ) ;
else
V_82 &= ~ ( F_54 ( V_79 ) ) ;
F_29 ( V_82 , V_3 -> V_65 + V_78 ) ;
F_30 ( & V_3 -> V_64 , V_61 ) ;
}
static int F_55 ( struct V_75 * V_83 ,
const struct V_84 * V_85 ,
T_2 * V_61 )
{
int V_20 , V_77 ;
V_77 = V_86 * V_85 -> args [ 0 ] ;
V_20 = V_77 + V_85 -> args [ 1 ] ;
if ( V_20 > ( V_83 -> V_77 + V_83 -> V_87 ) )
return - V_40 ;
if ( V_61 )
* V_61 = V_85 -> args [ 2 ] ;
return V_20 ;
}
static int F_56 ( struct V_75 * V_76 , unsigned V_73 )
{
struct V_2 * V_3 = F_48 ( V_76 -> V_39 ) ;
struct V_14 * V_17 ;
if ( V_73 > V_76 -> V_87 )
return - V_88 ;
V_17 = F_4 ( V_3 , V_73 , L_11 ) ;
if ( ! V_17 )
return - V_40 ;
V_3 -> V_89 [ V_17 -> V_90 ] = V_73 ;
F_57 ( V_76 -> V_39 , L_12 ,
V_76 -> V_91 , V_73 + V_76 -> V_77 , V_17 -> V_90 ) ;
return F_58 ( V_3 -> V_92 , V_17 -> V_90 ) ;
}
static int F_59 ( struct V_93 * V_94 ,
unsigned int type )
{
struct V_2 * V_3 = F_60 ( V_94 ) ;
T_2 V_78 = F_61 ( V_94 -> V_95 ) ;
T_3 V_79 = F_62 ( V_94 -> V_95 ) ;
unsigned long V_61 ;
T_2 V_82 ;
T_3 V_96 ;
switch ( type ) {
case V_97 :
V_96 = V_98 ;
break;
case V_99 :
V_96 = V_100 ;
break;
case V_101 :
V_96 = V_102 ;
break;
case V_103 :
V_96 = V_104 ;
break;
case V_105 :
V_96 = V_106 ;
break;
default:
return - V_40 ;
}
F_25 ( & V_3 -> V_64 , V_61 ) ;
V_82 = F_26 ( V_3 -> V_65 + V_78 ) ;
V_82 &= ~ V_107 ;
F_29 ( V_82 | ( V_96 << V_79 ) , V_3 -> V_65 + V_78 ) ;
F_30 ( & V_3 -> V_64 , V_61 ) ;
return 0 ;
}
static void F_63 ( struct V_93 * V_94 )
{
struct V_2 * V_3 = F_60 ( V_94 ) ;
T_2 V_108 = F_64 ( V_94 -> V_95 ) ;
T_3 V_109 = F_65 ( V_94 -> V_95 ) ;
T_2 V_110 = F_66 ( V_94 -> V_95 ) ;
T_3 V_111 = F_67 ( V_94 -> V_95 ) ;
unsigned long V_61 ;
T_2 V_38 ;
F_25 ( & V_3 -> V_64 , V_61 ) ;
V_38 = F_26 ( V_3 -> V_65 + V_108 ) ;
F_29 ( V_38 & ~ ( 1 << V_109 ) , V_3 -> V_65 + V_108 ) ;
F_29 ( 1 << V_111 , V_3 -> V_65 + V_110 ) ;
F_30 ( & V_3 -> V_64 , V_61 ) ;
}
static void F_68 ( struct V_93 * V_94 )
{
struct V_2 * V_3 = F_60 ( V_94 ) ;
T_2 V_78 = F_64 ( V_94 -> V_95 ) ;
T_3 V_112 = F_65 ( V_94 -> V_95 ) ;
unsigned long V_61 ;
T_2 V_38 ;
F_25 ( & V_3 -> V_64 , V_61 ) ;
V_38 = F_26 ( V_3 -> V_65 + V_78 ) ;
F_29 ( V_38 & ~ ( 1 << V_112 ) , V_3 -> V_65 + V_78 ) ;
F_30 ( & V_3 -> V_64 , V_61 ) ;
}
static void F_69 ( struct V_93 * V_94 )
{
struct V_2 * V_3 = F_60 ( V_94 ) ;
struct V_14 * V_11 ;
T_2 V_78 = F_64 ( V_94 -> V_95 ) ;
T_3 V_112 = F_65 ( V_94 -> V_95 ) ;
unsigned long V_61 ;
T_2 V_38 ;
V_11 = F_4 ( V_3 ,
V_3 -> V_89 [ V_94 -> V_95 ] ,
L_11 ) ;
F_36 ( V_3 -> V_113 , V_3 -> V_89 [ V_94 -> V_95 ] , V_11 -> V_70 ) ;
F_25 ( & V_3 -> V_64 , V_61 ) ;
V_38 = F_26 ( V_3 -> V_65 + V_78 ) ;
F_29 ( V_38 | ( 1 << V_112 ) , V_3 -> V_65 + V_78 ) ;
F_30 ( & V_3 -> V_64 , V_61 ) ;
}
static void F_70 ( unsigned V_114 , struct V_115 * V_17 )
{
struct V_2 * V_3 = F_71 ( V_114 ) ;
const unsigned long V_78 = F_26 ( V_3 -> V_65 + V_116 ) ;
F_29 ( V_78 , V_3 -> V_65 + V_116 ) ;
if ( V_78 ) {
int V_117 ;
F_72 (irqoffset, &reg, SUNXI_IRQ_NUMBER) {
int V_118 = F_58 ( V_3 -> V_92 , V_117 ) ;
F_73 ( V_118 ) ;
}
}
}
static int F_74 ( struct V_2 * V_3 ,
const char * V_9 )
{
struct V_10 * V_11 = V_3 -> V_12 ;
while ( V_11 -> V_9 ) {
if ( strcmp ( V_11 -> V_9 , V_9 ) == 0 ) {
V_11 -> V_6 ++ ;
return - V_119 ;
}
V_11 ++ ;
}
V_11 -> V_9 = V_9 ;
V_11 -> V_6 = 1 ;
V_3 -> V_13 ++ ;
return 0 ;
}
static int F_75 ( struct V_120 * V_121 )
{
struct V_2 * V_3 = F_76 ( V_121 ) ;
int V_5 ;
V_3 -> V_6 = V_3 -> V_17 -> V_18 ;
V_3 -> V_8 = F_77 ( & V_121 -> V_39 ,
V_3 -> V_6 * sizeof( * V_3 -> V_8 ) ,
V_41 ) ;
if ( ! V_3 -> V_8 )
return - V_42 ;
for ( V_5 = 0 ; V_5 < V_3 -> V_17 -> V_18 ; V_5 ++ ) {
const struct V_19 * V_20 = V_3 -> V_17 -> V_21 + V_5 ;
struct V_1 * V_4 = V_3 -> V_8 + V_5 ;
V_4 -> V_9 = V_20 -> V_20 . V_9 ;
V_4 -> V_20 = V_20 -> V_20 . V_23 ;
}
V_3 -> V_12 = F_77 ( & V_121 -> V_39 ,
V_3 -> V_17 -> V_18 * sizeof( * V_3 -> V_12 ) ,
V_41 ) ;
if ( ! V_3 -> V_12 )
return - V_42 ;
for ( V_5 = 0 ; V_5 < V_3 -> V_17 -> V_18 ; V_5 ++ ) {
const struct V_19 * V_20 = V_3 -> V_17 -> V_21 + V_5 ;
struct V_14 * V_11 = V_20 -> V_12 ;
while ( V_11 -> V_9 ) {
F_74 ( V_3 , V_11 -> V_9 ) ;
V_11 ++ ;
}
}
V_3 -> V_12 = F_78 ( V_3 -> V_12 ,
V_3 -> V_13 * sizeof( * V_3 -> V_12 ) ,
V_41 ) ;
for ( V_5 = 0 ; V_5 < V_3 -> V_17 -> V_18 ; V_5 ++ ) {
const struct V_19 * V_20 = V_3 -> V_17 -> V_21 + V_5 ;
struct V_14 * V_11 = V_20 -> V_12 ;
while ( V_11 -> V_9 ) {
struct V_10 * V_122 ;
const char * * V_123 ;
V_122 = F_2 ( V_3 ,
V_11 -> V_9 ) ;
if ( ! V_122 )
return - V_40 ;
if ( ! V_122 -> V_8 ) {
V_122 -> V_8 =
F_77 ( & V_121 -> V_39 ,
V_122 -> V_6 * sizeof( * V_122 -> V_8 ) ,
V_41 ) ;
if ( ! V_122 -> V_8 )
return - V_42 ;
}
V_123 = V_122 -> V_8 ;
while ( * V_123 )
V_123 ++ ;
* V_123 = V_20 -> V_20 . V_9 ;
V_11 ++ ;
}
}
return 0 ;
}
static int F_79 ( struct V_120 * V_121 )
{
struct V_27 * V_28 = V_121 -> V_39 . V_124 ;
const struct V_125 * V_126 ;
struct V_127 * V_21 ;
struct V_2 * V_3 ;
int V_5 , V_36 , V_128 ;
struct V_129 * V_129 ;
V_3 = F_77 ( & V_121 -> V_39 , sizeof( * V_3 ) , V_41 ) ;
if ( ! V_3 )
return - V_42 ;
F_80 ( V_121 , V_3 ) ;
F_81 ( & V_3 -> V_64 ) ;
V_3 -> V_65 = F_82 ( V_28 , 0 ) ;
if ( ! V_3 -> V_65 )
return - V_42 ;
V_126 = F_83 ( V_130 , & V_121 -> V_39 ) ;
if ( ! V_126 )
return - V_131 ;
V_3 -> V_17 = (struct V_132 * ) V_126 -> V_46 ;
V_36 = F_75 ( V_121 ) ;
if ( V_36 ) {
F_11 ( & V_121 -> V_39 , L_13 , V_36 ) ;
return V_36 ;
}
V_21 = F_77 ( & V_121 -> V_39 ,
V_3 -> V_17 -> V_18 * sizeof( * V_21 ) ,
V_41 ) ;
if ( ! V_21 )
return - V_42 ;
for ( V_5 = 0 ; V_5 < V_3 -> V_17 -> V_18 ; V_5 ++ )
V_21 [ V_5 ] = V_3 -> V_17 -> V_21 [ V_5 ] . V_20 ;
V_133 . V_9 = F_84 ( & V_121 -> V_39 ) ;
V_133 . V_134 = V_135 ;
V_133 . V_21 = V_21 ;
V_133 . V_18 = V_3 -> V_17 -> V_18 ;
V_3 -> V_39 = & V_121 -> V_39 ;
V_3 -> V_113 = F_85 ( & V_133 ,
& V_121 -> V_39 , V_3 ) ;
if ( ! V_3 -> V_113 ) {
F_11 ( & V_121 -> V_39 , L_14 ) ;
return - V_40 ;
}
V_3 -> V_76 = F_77 ( & V_121 -> V_39 , sizeof( * V_3 -> V_76 ) , V_41 ) ;
if ( ! V_3 -> V_76 ) {
V_36 = - V_42 ;
goto V_136;
}
V_128 = V_3 -> V_17 -> V_21 [ V_3 -> V_17 -> V_18 - 1 ] . V_20 . V_23 ;
V_3 -> V_76 = & V_137 ;
V_3 -> V_76 -> V_87 = F_86 ( V_128 , V_86 ) ;
V_3 -> V_76 -> V_91 = F_84 ( & V_121 -> V_39 ) ;
V_3 -> V_76 -> V_39 = & V_121 -> V_39 ;
V_3 -> V_76 -> V_77 = 0 ;
V_36 = F_87 ( V_3 -> V_76 ) ;
if ( V_36 )
goto V_136;
for ( V_5 = 0 ; V_5 < V_3 -> V_17 -> V_18 ; V_5 ++ ) {
const struct V_19 * V_20 = V_3 -> V_17 -> V_21 + V_5 ;
V_36 = F_88 ( V_3 -> V_76 , F_84 ( & V_121 -> V_39 ) ,
V_20 -> V_20 . V_23 ,
V_20 -> V_20 . V_23 , 1 ) ;
if ( V_36 )
goto V_138;
}
V_129 = F_89 ( & V_121 -> V_39 , NULL ) ;
if ( F_90 ( V_129 ) ) {
V_36 = F_91 ( V_129 ) ;
goto V_138;
}
F_92 ( V_129 ) ;
V_3 -> V_114 = F_93 ( V_28 , 0 ) ;
if ( ! V_3 -> V_114 ) {
V_36 = - V_40 ;
goto V_138;
}
V_3 -> V_92 = F_94 ( V_28 , V_139 ,
& V_140 , NULL ) ;
if ( ! V_3 -> V_92 ) {
F_11 ( & V_121 -> V_39 , L_15 ) ;
V_36 = - V_42 ;
goto V_138;
}
for ( V_5 = 0 ; V_5 < V_139 ; V_5 ++ ) {
int V_141 = F_95 ( V_3 -> V_92 , V_5 ) ;
F_96 ( V_141 , & V_142 ,
V_143 ) ;
F_97 ( V_141 , V_3 ) ;
} ;
F_98 ( V_3 -> V_114 , F_70 ) ;
F_99 ( V_3 -> V_114 , V_3 ) ;
F_100 ( & V_121 -> V_39 , L_16 ) ;
return 0 ;
V_138:
if ( F_101 ( V_3 -> V_76 ) )
F_11 ( & V_121 -> V_39 , L_17 ) ;
V_136:
F_102 ( V_3 -> V_113 ) ;
return V_36 ;
}
