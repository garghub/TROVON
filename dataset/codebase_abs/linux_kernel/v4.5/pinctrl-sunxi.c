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
if ( ! * V_30 )
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
if ( ! V_32 ) {
F_17 ( * V_30 ) ;
return - V_42 ;
}
if ( ! F_18 ( V_28 , L_7 , & V_38 ) ) {
T_1 V_51 = ( V_38 + 1 ) * 10 ;
V_32 [ V_43 ++ ] =
F_19 ( V_52 ,
V_51 ) ;
}
if ( ! F_18 ( V_28 , L_8 , & V_38 ) ) {
enum V_53 V_54 = V_55 ;
if ( V_38 == 1 )
V_54 = V_56 ;
else if ( V_38 == 2 )
V_54 = V_57 ;
V_32 [ V_43 ++ ] = F_19 ( V_54 , 0 ) ;
}
( * V_30 ) [ V_5 ] . V_46 . V_49 . V_49 = V_32 ;
( * V_30 ) [ V_5 ] . V_46 . V_49 . V_58 = V_44 ;
V_5 ++ ;
}
* V_31 = V_37 ;
return 0 ;
}
static void F_20 ( struct V_24 * V_25 ,
struct V_29 * V_30 ,
unsigned V_31 )
{
int V_5 ;
for ( V_5 = 0 ; V_5 < V_31 ; V_5 ++ ) {
if ( V_30 [ V_5 ] . type == V_48 )
F_17 ( V_30 [ V_5 ] . V_46 . V_49 . V_49 ) ;
}
F_17 ( V_30 ) ;
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
unsigned long * V_49 ,
unsigned V_58 )
{
struct V_2 * V_3 = F_6 ( V_25 ) ;
struct V_1 * V_60 = & V_3 -> V_8 [ V_4 ] ;
unsigned long V_61 ;
unsigned V_20 = V_60 -> V_20 - V_3 -> V_17 -> V_62 ;
T_2 V_38 , V_63 ;
T_1 V_51 ;
T_3 V_64 ;
int V_5 ;
F_23 ( & V_3 -> V_65 , V_61 ) ;
for ( V_5 = 0 ; V_5 < V_58 ; V_5 ++ ) {
switch ( F_24 ( V_49 [ V_5 ] ) ) {
case V_52 :
V_51 = F_25 ( V_49 [ V_5 ] ) ;
if ( V_51 > 40 ) {
F_26 ( & V_3 -> V_65 , V_61 ) ;
return - V_40 ;
}
V_64 = V_51 / 10 - 1 ;
V_38 = F_27 ( V_3 -> V_66 + F_28 ( V_20 ) ) ;
V_63 = V_67 << F_29 ( V_20 ) ;
F_30 ( ( V_38 & ~ V_63 )
| V_64 << F_29 ( V_20 ) ,
V_3 -> V_66 + F_28 ( V_20 ) ) ;
break;
case V_56 :
V_38 = F_27 ( V_3 -> V_66 + F_31 ( V_20 ) ) ;
V_63 = V_68 << F_32 ( V_20 ) ;
F_30 ( ( V_38 & ~ V_63 ) | 1 << F_32 ( V_20 ) ,
V_3 -> V_66 + F_31 ( V_20 ) ) ;
break;
case V_57 :
V_38 = F_27 ( V_3 -> V_66 + F_31 ( V_20 ) ) ;
V_63 = V_68 << F_32 ( V_20 ) ;
F_30 ( ( V_38 & ~ V_63 ) | 2 << F_32 ( V_20 ) ,
V_3 -> V_66 + F_31 ( V_20 ) ) ;
break;
default:
break;
}
V_60 -> V_59 = V_49 [ V_5 ] ;
}
F_26 ( & V_3 -> V_65 , V_61 ) ;
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
unsigned * const V_69 )
{
struct V_2 * V_3 = F_6 ( V_25 ) ;
* V_8 = V_3 -> V_12 [ V_35 ] . V_8 ;
* V_69 = V_3 -> V_12 [ V_35 ] . V_6 ;
return 0 ;
}
static void F_36 ( struct V_24 * V_25 ,
unsigned V_20 ,
T_3 V_59 )
{
struct V_2 * V_3 = F_6 ( V_25 ) ;
unsigned long V_61 ;
T_2 V_38 , V_63 ;
F_23 ( & V_3 -> V_65 , V_61 ) ;
V_20 -= V_3 -> V_17 -> V_62 ;
V_38 = F_27 ( V_3 -> V_66 + F_37 ( V_20 ) ) ;
V_63 = V_70 << F_38 ( V_20 ) ;
F_30 ( ( V_38 & ~ V_63 ) | V_59 << F_38 ( V_20 ) ,
V_3 -> V_66 + F_37 ( V_20 ) ) ;
F_26 ( & V_3 -> V_65 , V_61 ) ;
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
F_36 ( V_25 , V_60 -> V_20 , V_17 -> V_71 ) ;
return 0 ;
}
static int
F_40 ( struct V_24 * V_25 ,
struct V_72 * V_73 ,
unsigned V_74 ,
bool V_75 )
{
struct V_2 * V_3 = F_6 ( V_25 ) ;
struct V_14 * V_17 ;
const char * V_11 ;
if ( V_75 )
V_11 = L_9 ;
else
V_11 = L_10 ;
V_17 = F_4 ( V_3 , V_74 , V_11 ) ;
if ( ! V_17 )
return - V_40 ;
F_36 ( V_25 , V_74 , V_17 -> V_71 ) ;
return 0 ;
}
static int F_41 ( struct V_76 * V_77 ,
unsigned V_74 )
{
return F_42 ( V_77 -> V_78 + V_74 ) ;
}
static int F_43 ( struct V_76 * V_77 , unsigned V_74 )
{
struct V_2 * V_3 = F_44 ( V_77 ) ;
T_2 V_79 = F_45 ( V_74 ) ;
T_3 V_80 = F_46 ( V_74 ) ;
T_2 V_81 = V_3 -> V_17 -> V_82 &&
F_47 ( V_83 , & V_77 -> V_17 [ V_74 ] . V_61 ) ;
T_2 V_38 ;
if ( V_81 )
F_36 ( V_3 -> V_84 , V_74 , V_85 ) ;
V_38 = ( F_27 ( V_3 -> V_66 + V_79 ) >> V_80 ) & V_86 ;
if ( V_81 )
F_36 ( V_3 -> V_84 , V_74 , V_87 ) ;
return ! ! V_38 ;
}
static void F_48 ( struct V_76 * V_77 ,
unsigned V_74 , int V_88 )
{
struct V_2 * V_3 = F_44 ( V_77 ) ;
T_2 V_79 = F_45 ( V_74 ) ;
T_3 V_80 = F_46 ( V_74 ) ;
unsigned long V_61 ;
T_2 V_89 ;
F_23 ( & V_3 -> V_65 , V_61 ) ;
V_89 = F_27 ( V_3 -> V_66 + V_79 ) ;
if ( V_88 )
V_89 |= F_49 ( V_80 ) ;
else
V_89 &= ~ ( F_49 ( V_80 ) ) ;
F_30 ( V_89 , V_3 -> V_66 + V_79 ) ;
F_26 ( & V_3 -> V_65 , V_61 ) ;
}
static int F_50 ( struct V_76 * V_77 ,
unsigned V_74 , int V_88 )
{
F_48 ( V_77 , V_74 , V_88 ) ;
return F_51 ( V_77 -> V_78 + V_74 ) ;
}
static int F_52 ( struct V_76 * V_90 ,
const struct V_91 * V_92 ,
T_2 * V_61 )
{
int V_20 , V_78 ;
V_78 = V_93 * V_92 -> args [ 0 ] ;
V_20 = V_78 + V_92 -> args [ 1 ] ;
if ( V_20 > V_90 -> V_94 )
return - V_40 ;
if ( V_61 )
* V_61 = V_92 -> args [ 2 ] ;
return V_20 ;
}
static int F_53 ( struct V_76 * V_77 , unsigned V_74 )
{
struct V_2 * V_3 = F_44 ( V_77 ) ;
struct V_14 * V_17 ;
unsigned V_95 = V_3 -> V_17 -> V_62 + V_74 ;
unsigned V_96 ;
if ( V_74 >= V_77 -> V_94 )
return - V_97 ;
V_17 = F_4 ( V_3 , V_95 , L_11 ) ;
if ( ! V_17 )
return - V_40 ;
V_96 = V_17 -> V_98 * V_99 + V_17 -> V_96 ;
F_54 ( V_77 -> V_100 , L_12 ,
V_77 -> V_101 , V_74 + V_77 -> V_78 , V_96 ) ;
return F_55 ( V_3 -> V_102 , V_96 ) ;
}
static int F_56 ( struct V_103 * V_104 )
{
struct V_2 * V_3 = F_57 ( V_104 ) ;
struct V_14 * V_11 ;
int V_36 ;
V_11 = F_4 ( V_3 ,
V_3 -> V_105 [ V_104 -> V_106 ] , L_11 ) ;
if ( ! V_11 )
return - V_40 ;
V_36 = F_58 ( V_3 -> V_77 ,
V_3 -> V_105 [ V_104 -> V_106 ] - V_3 -> V_17 -> V_62 ) ;
if ( V_36 ) {
F_11 ( V_3 -> V_39 , L_13 ,
F_59 ( V_104 ) ) ;
return V_36 ;
}
F_36 ( V_3 -> V_84 , V_3 -> V_105 [ V_104 -> V_106 ] , V_11 -> V_71 ) ;
return 0 ;
}
static void F_60 ( struct V_103 * V_104 )
{
struct V_2 * V_3 = F_57 ( V_104 ) ;
F_61 ( V_3 -> V_77 ,
V_3 -> V_105 [ V_104 -> V_106 ] - V_3 -> V_17 -> V_62 ) ;
}
static int F_62 ( struct V_103 * V_104 , unsigned int type )
{
struct V_2 * V_3 = F_57 ( V_104 ) ;
T_2 V_79 = F_63 ( V_104 -> V_106 ) ;
T_3 V_80 = F_64 ( V_104 -> V_106 ) ;
unsigned long V_61 ;
T_2 V_89 ;
T_3 V_107 ;
switch ( type ) {
case V_108 :
V_107 = V_109 ;
break;
case V_110 :
V_107 = V_111 ;
break;
case V_112 :
V_107 = V_113 ;
break;
case V_114 :
V_107 = V_115 ;
break;
case V_116 :
V_107 = V_117 ;
break;
default:
return - V_40 ;
}
F_23 ( & V_3 -> V_65 , V_61 ) ;
if ( type & V_118 )
F_65 ( V_104 , & V_119 ,
V_120 , NULL ) ;
else
F_65 ( V_104 , & V_121 ,
V_122 , NULL ) ;
V_89 = F_27 ( V_3 -> V_66 + V_79 ) ;
V_89 &= ~ ( V_123 << V_80 ) ;
F_30 ( V_89 | ( V_107 << V_80 ) , V_3 -> V_66 + V_79 ) ;
F_26 ( & V_3 -> V_65 , V_61 ) ;
return 0 ;
}
static void F_66 ( struct V_103 * V_104 )
{
struct V_2 * V_3 = F_57 ( V_104 ) ;
T_2 V_124 = F_67 ( V_104 -> V_106 ) ;
T_3 V_125 = F_68 ( V_104 -> V_106 ) ;
F_30 ( 1 << V_125 , V_3 -> V_66 + V_124 ) ;
}
static void F_69 ( struct V_103 * V_104 )
{
struct V_2 * V_3 = F_57 ( V_104 ) ;
T_2 V_79 = F_70 ( V_104 -> V_106 ) ;
T_3 V_126 = F_71 ( V_104 -> V_106 ) ;
unsigned long V_61 ;
T_2 V_38 ;
F_23 ( & V_3 -> V_65 , V_61 ) ;
V_38 = F_27 ( V_3 -> V_66 + V_79 ) ;
F_30 ( V_38 & ~ ( 1 << V_126 ) , V_3 -> V_66 + V_79 ) ;
F_26 ( & V_3 -> V_65 , V_61 ) ;
}
static void F_72 ( struct V_103 * V_104 )
{
struct V_2 * V_3 = F_57 ( V_104 ) ;
T_2 V_79 = F_70 ( V_104 -> V_106 ) ;
T_3 V_126 = F_71 ( V_104 -> V_106 ) ;
unsigned long V_61 ;
T_2 V_38 ;
F_23 ( & V_3 -> V_65 , V_61 ) ;
V_38 = F_27 ( V_3 -> V_66 + V_79 ) ;
F_30 ( V_38 | ( 1 << V_126 ) , V_3 -> V_66 + V_79 ) ;
F_26 ( & V_3 -> V_65 , V_61 ) ;
}
static void F_73 ( struct V_103 * V_104 )
{
F_66 ( V_104 ) ;
F_72 ( V_104 ) ;
}
static int F_74 ( struct V_127 * V_104 ,
struct V_27 * V_28 ,
const T_2 * V_128 ,
unsigned int V_129 ,
unsigned long * V_130 ,
unsigned int * V_131 )
{
struct V_2 * V_3 = V_104 -> V_132 ;
struct V_14 * V_17 ;
int V_20 , V_78 ;
if ( V_129 < 3 )
return - V_40 ;
V_78 = V_93 * V_128 [ 0 ] ;
V_20 = V_3 -> V_17 -> V_62 + V_78 + V_128 [ 1 ] ;
V_17 = F_4 ( V_3 , V_20 , L_11 ) ;
if ( ! V_17 )
return - V_40 ;
* V_130 = V_17 -> V_98 * V_93 + V_17 -> V_96 ;
* V_131 = V_128 [ 2 ] ;
return 0 ;
}
static void F_75 ( struct V_133 * V_17 )
{
unsigned int V_134 = F_76 ( V_17 ) ;
struct V_135 * V_77 = F_77 ( V_17 ) ;
struct V_2 * V_3 = F_78 ( V_17 ) ;
unsigned long V_136 , V_79 , V_38 ;
for ( V_136 = 0 ; V_136 < V_3 -> V_17 -> V_137 ; V_136 ++ )
if ( V_134 == V_3 -> V_134 [ V_136 ] )
break;
if ( V_136 == V_3 -> V_17 -> V_137 )
return;
V_79 = F_79 ( V_136 ) ;
V_38 = F_27 ( V_3 -> V_66 + V_79 ) ;
if ( V_38 ) {
int V_138 ;
F_80 ( V_77 , V_17 ) ;
F_81 (irqoffset, &val, IRQ_PER_BANK) {
int V_139 = F_55 ( V_3 -> V_102 ,
V_136 * V_99 + V_138 ) ;
F_82 ( V_139 ) ;
}
F_83 ( V_77 , V_17 ) ;
}
}
static int F_84 ( struct V_2 * V_3 ,
const char * V_9 )
{
struct V_10 * V_11 = V_3 -> V_12 ;
while ( V_11 -> V_9 ) {
if ( strcmp ( V_11 -> V_9 , V_9 ) == 0 ) {
V_11 -> V_6 ++ ;
return - V_140 ;
}
V_11 ++ ;
}
V_11 -> V_9 = V_9 ;
V_11 -> V_6 = 1 ;
V_3 -> V_13 ++ ;
return 0 ;
}
static int F_85 ( struct V_141 * V_142 )
{
struct V_2 * V_3 = F_86 ( V_142 ) ;
int V_5 ;
V_3 -> V_6 = V_3 -> V_17 -> V_18 ;
V_3 -> V_8 = F_87 ( & V_142 -> V_39 ,
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
V_3 -> V_12 = F_87 ( & V_142 -> V_39 ,
V_3 -> V_17 -> V_18 * sizeof( * V_3 -> V_12 ) ,
V_41 ) ;
if ( ! V_3 -> V_12 )
return - V_42 ;
for ( V_5 = 0 ; V_5 < V_3 -> V_17 -> V_18 ; V_5 ++ ) {
const struct V_19 * V_20 = V_3 -> V_17 -> V_21 + V_5 ;
struct V_14 * V_11 = V_20 -> V_12 ;
while ( V_11 -> V_9 ) {
if ( ! strcmp ( V_11 -> V_9 , L_11 ) ) {
int V_96 = V_11 -> V_96 + V_11 -> V_98 * V_99 ;
V_3 -> V_105 [ V_96 ] = V_20 -> V_20 . V_23 ;
}
F_84 ( V_3 , V_11 -> V_9 ) ;
V_11 ++ ;
}
}
V_3 -> V_12 = F_88 ( V_3 -> V_12 ,
V_3 -> V_13 * sizeof( * V_3 -> V_12 ) ,
V_41 ) ;
for ( V_5 = 0 ; V_5 < V_3 -> V_17 -> V_18 ; V_5 ++ ) {
const struct V_19 * V_20 = V_3 -> V_17 -> V_21 + V_5 ;
struct V_14 * V_11 = V_20 -> V_12 ;
while ( V_11 -> V_9 ) {
struct V_10 * V_143 ;
const char * * V_144 ;
V_143 = F_2 ( V_3 ,
V_11 -> V_9 ) ;
if ( ! V_143 )
return - V_40 ;
if ( ! V_143 -> V_8 ) {
V_143 -> V_8 =
F_87 ( & V_142 -> V_39 ,
V_143 -> V_6 * sizeof( * V_143 -> V_8 ) ,
V_41 ) ;
if ( ! V_143 -> V_8 )
return - V_42 ;
}
V_144 = V_143 -> V_8 ;
while ( * V_144 )
V_144 ++ ;
* V_144 = V_20 -> V_20 . V_9 ;
V_11 ++ ;
}
}
return 0 ;
}
int F_89 ( struct V_141 * V_142 ,
const struct V_145 * V_17 )
{
struct V_27 * V_28 = V_142 -> V_39 . V_146 ;
struct V_147 * V_148 ;
struct V_149 * V_21 ;
struct V_2 * V_3 ;
struct V_150 * V_151 ;
int V_5 , V_36 , V_152 ;
struct V_153 * V_153 ;
V_3 = F_87 ( & V_142 -> V_39 , sizeof( * V_3 ) , V_41 ) ;
if ( ! V_3 )
return - V_42 ;
F_90 ( V_142 , V_3 ) ;
F_91 ( & V_3 -> V_65 ) ;
V_151 = F_92 ( V_142 , V_154 , 0 ) ;
V_3 -> V_66 = F_93 ( & V_142 -> V_39 , V_151 ) ;
if ( F_94 ( V_3 -> V_66 ) )
return F_95 ( V_3 -> V_66 ) ;
V_3 -> V_39 = & V_142 -> V_39 ;
V_3 -> V_17 = V_17 ;
V_3 -> V_105 = F_96 ( & V_142 -> V_39 ,
V_99 * V_3 -> V_17 -> V_137 ,
sizeof( * V_3 -> V_105 ) ,
V_41 ) ;
if ( ! V_3 -> V_105 )
return - V_42 ;
V_36 = F_85 ( V_142 ) ;
if ( V_36 ) {
F_11 ( & V_142 -> V_39 , L_14 , V_36 ) ;
return V_36 ;
}
V_21 = F_87 ( & V_142 -> V_39 ,
V_3 -> V_17 -> V_18 * sizeof( * V_21 ) ,
V_41 ) ;
if ( ! V_21 )
return - V_42 ;
for ( V_5 = 0 ; V_5 < V_3 -> V_17 -> V_18 ; V_5 ++ )
V_21 [ V_5 ] = V_3 -> V_17 -> V_21 [ V_5 ] . V_20 ;
V_148 = F_87 ( & V_142 -> V_39 ,
sizeof( * V_148 ) ,
V_41 ) ;
if ( ! V_148 )
return - V_42 ;
V_148 -> V_9 = F_97 ( & V_142 -> V_39 ) ;
V_148 -> V_155 = V_156 ;
V_148 -> V_21 = V_21 ;
V_148 -> V_18 = V_3 -> V_17 -> V_18 ;
V_148 -> V_157 = & V_158 ;
V_148 -> V_159 = & V_160 ;
V_148 -> V_161 = & V_162 ;
V_3 -> V_84 = F_98 ( V_148 ,
& V_142 -> V_39 , V_3 ) ;
if ( F_94 ( V_3 -> V_84 ) ) {
F_11 ( & V_142 -> V_39 , L_15 ) ;
return F_95 ( V_3 -> V_84 ) ;
}
V_3 -> V_77 = F_87 ( & V_142 -> V_39 , sizeof( * V_3 -> V_77 ) , V_41 ) ;
if ( ! V_3 -> V_77 ) {
V_36 = - V_42 ;
goto V_163;
}
V_152 = V_3 -> V_17 -> V_21 [ V_3 -> V_17 -> V_18 - 1 ] . V_20 . V_23 ;
V_3 -> V_77 -> V_155 = V_156 ;
V_3 -> V_77 -> V_164 = V_165 ,
V_3 -> V_77 -> free = V_166 ,
V_3 -> V_77 -> V_167 = F_41 ,
V_3 -> V_77 -> V_168 = F_50 ,
V_3 -> V_77 -> V_169 = F_43 ,
V_3 -> V_77 -> V_170 = F_48 ,
V_3 -> V_77 -> V_171 = F_52 ,
V_3 -> V_77 -> V_172 = F_53 ,
V_3 -> V_77 -> V_173 = 3 ,
V_3 -> V_77 -> V_174 = false ,
V_3 -> V_77 -> V_94 = F_99 ( V_152 , V_93 ) -
V_3 -> V_17 -> V_62 ;
V_3 -> V_77 -> V_101 = F_97 ( & V_142 -> V_39 ) ;
V_3 -> V_77 -> V_100 = & V_142 -> V_39 ;
V_3 -> V_77 -> V_78 = V_3 -> V_17 -> V_62 ;
V_36 = F_100 ( V_3 -> V_77 , V_3 ) ;
if ( V_36 )
goto V_163;
for ( V_5 = 0 ; V_5 < V_3 -> V_17 -> V_18 ; V_5 ++ ) {
const struct V_19 * V_20 = V_3 -> V_17 -> V_21 + V_5 ;
V_36 = F_101 ( V_3 -> V_77 , F_97 ( & V_142 -> V_39 ) ,
V_20 -> V_20 . V_23 - V_3 -> V_17 -> V_62 ,
V_20 -> V_20 . V_23 , 1 ) ;
if ( V_36 )
goto V_175;
}
V_153 = F_102 ( & V_142 -> V_39 , NULL ) ;
if ( F_94 ( V_153 ) ) {
V_36 = F_95 ( V_153 ) ;
goto V_175;
}
V_36 = F_103 ( V_153 ) ;
if ( V_36 )
goto V_175;
V_3 -> V_134 = F_96 ( & V_142 -> V_39 ,
V_3 -> V_17 -> V_137 ,
sizeof( * V_3 -> V_134 ) ,
V_41 ) ;
if ( ! V_3 -> V_134 ) {
V_36 = - V_42 ;
goto V_176;
}
for ( V_5 = 0 ; V_5 < V_3 -> V_17 -> V_137 ; V_5 ++ ) {
V_3 -> V_134 [ V_5 ] = F_104 ( V_142 , V_5 ) ;
if ( V_3 -> V_134 [ V_5 ] < 0 ) {
V_36 = V_3 -> V_134 [ V_5 ] ;
goto V_176;
}
}
V_3 -> V_102 = F_105 ( V_28 ,
V_3 -> V_17 -> V_137 * V_99 ,
& V_177 ,
V_3 ) ;
if ( ! V_3 -> V_102 ) {
F_11 ( & V_142 -> V_39 , L_16 ) ;
V_36 = - V_42 ;
goto V_176;
}
for ( V_5 = 0 ; V_5 < ( V_3 -> V_17 -> V_137 * V_99 ) ; V_5 ++ ) {
int V_178 = F_106 ( V_3 -> V_102 , V_5 ) ;
F_107 ( V_178 , & V_121 ,
V_122 ) ;
F_108 ( V_178 , V_3 ) ;
}
for ( V_5 = 0 ; V_5 < V_3 -> V_17 -> V_137 ; V_5 ++ ) {
F_30 ( 0 , V_3 -> V_66 + F_109 ( V_5 ) ) ;
F_30 ( 0xffffffff ,
V_3 -> V_66 + F_79 ( V_5 ) ) ;
F_110 ( V_3 -> V_134 [ V_5 ] ,
F_75 ,
V_3 ) ;
}
F_111 ( & V_142 -> V_39 , L_17 ) ;
return 0 ;
V_176:
F_112 ( V_153 ) ;
V_175:
F_113 ( V_3 -> V_77 ) ;
V_163:
F_114 ( V_3 -> V_84 ) ;
return V_36 ;
}
