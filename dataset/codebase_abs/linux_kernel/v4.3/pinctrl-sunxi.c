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
static int F_41 ( struct V_76 * V_77 , unsigned V_74 )
{
return F_42 ( V_77 -> V_78 + V_74 ) ;
}
static void F_43 ( struct V_76 * V_77 , unsigned V_74 )
{
F_44 ( V_77 -> V_78 + V_74 ) ;
}
static int F_45 ( struct V_76 * V_77 ,
unsigned V_74 )
{
return F_46 ( V_77 -> V_78 + V_74 ) ;
}
static int F_47 ( struct V_76 * V_77 , unsigned V_74 )
{
struct V_2 * V_3 = F_48 ( V_77 -> V_39 ) ;
T_2 V_79 = F_49 ( V_74 ) ;
T_3 V_80 = F_50 ( V_74 ) ;
T_2 V_81 = V_3 -> V_17 -> V_82 &&
F_51 ( V_83 , & V_77 -> V_17 [ V_74 ] . V_61 ) ;
T_2 V_38 ;
if ( V_81 )
F_36 ( V_3 -> V_84 , V_74 , V_85 ) ;
V_38 = ( F_27 ( V_3 -> V_66 + V_79 ) >> V_80 ) & V_86 ;
if ( V_81 )
F_36 ( V_3 -> V_84 , V_74 , V_87 ) ;
return V_38 ;
}
static void F_52 ( struct V_76 * V_77 ,
unsigned V_74 , int V_88 )
{
struct V_2 * V_3 = F_48 ( V_77 -> V_39 ) ;
T_2 V_79 = F_49 ( V_74 ) ;
T_3 V_80 = F_50 ( V_74 ) ;
unsigned long V_61 ;
T_2 V_89 ;
F_23 ( & V_3 -> V_65 , V_61 ) ;
V_89 = F_27 ( V_3 -> V_66 + V_79 ) ;
if ( V_88 )
V_89 |= F_53 ( V_80 ) ;
else
V_89 &= ~ ( F_53 ( V_80 ) ) ;
F_30 ( V_89 , V_3 -> V_66 + V_79 ) ;
F_26 ( & V_3 -> V_65 , V_61 ) ;
}
static int F_54 ( struct V_76 * V_77 ,
unsigned V_74 , int V_88 )
{
F_52 ( V_77 , V_74 , V_88 ) ;
return F_55 ( V_77 -> V_78 + V_74 ) ;
}
static int F_56 ( struct V_76 * V_90 ,
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
static int F_57 ( struct V_76 * V_77 , unsigned V_74 )
{
struct V_2 * V_3 = F_48 ( V_77 -> V_39 ) ;
struct V_14 * V_17 ;
unsigned V_95 = V_3 -> V_17 -> V_62 + V_74 ;
unsigned V_96 ;
if ( V_74 >= V_77 -> V_94 )
return - V_97 ;
V_17 = F_4 ( V_3 , V_95 , L_11 ) ;
if ( ! V_17 )
return - V_40 ;
V_96 = V_17 -> V_98 * V_99 + V_17 -> V_96 ;
F_58 ( V_77 -> V_39 , L_12 ,
V_77 -> V_100 , V_74 + V_77 -> V_78 , V_96 ) ;
return F_59 ( V_3 -> V_101 , V_96 ) ;
}
static int F_60 ( struct V_102 * V_103 )
{
struct V_2 * V_3 = F_61 ( V_103 ) ;
struct V_14 * V_11 ;
int V_36 ;
V_11 = F_4 ( V_3 ,
V_3 -> V_104 [ V_103 -> V_105 ] , L_11 ) ;
if ( ! V_11 )
return - V_40 ;
V_36 = F_62 ( V_3 -> V_77 ,
V_3 -> V_104 [ V_103 -> V_105 ] - V_3 -> V_17 -> V_62 ) ;
if ( V_36 ) {
F_11 ( V_3 -> V_39 , L_13 ,
F_63 ( V_103 ) ) ;
return V_36 ;
}
F_36 ( V_3 -> V_84 , V_3 -> V_104 [ V_103 -> V_105 ] , V_11 -> V_71 ) ;
return 0 ;
}
static void F_64 ( struct V_102 * V_103 )
{
struct V_2 * V_3 = F_61 ( V_103 ) ;
F_65 ( V_3 -> V_77 ,
V_3 -> V_104 [ V_103 -> V_105 ] - V_3 -> V_17 -> V_62 ) ;
}
static int F_66 ( struct V_102 * V_103 , unsigned int type )
{
struct V_2 * V_3 = F_61 ( V_103 ) ;
T_2 V_79 = F_67 ( V_103 -> V_105 ) ;
T_3 V_80 = F_68 ( V_103 -> V_105 ) ;
unsigned long V_61 ;
T_2 V_89 ;
T_3 V_106 ;
switch ( type ) {
case V_107 :
V_106 = V_108 ;
break;
case V_109 :
V_106 = V_110 ;
break;
case V_111 :
V_106 = V_112 ;
break;
case V_113 :
V_106 = V_114 ;
break;
case V_115 :
V_106 = V_116 ;
break;
default:
return - V_40 ;
}
F_23 ( & V_3 -> V_65 , V_61 ) ;
if ( type & V_117 )
F_69 ( V_103 , & V_118 ,
V_119 , NULL ) ;
else
F_69 ( V_103 , & V_120 ,
V_121 , NULL ) ;
V_89 = F_27 ( V_3 -> V_66 + V_79 ) ;
V_89 &= ~ ( V_122 << V_80 ) ;
F_30 ( V_89 | ( V_106 << V_80 ) , V_3 -> V_66 + V_79 ) ;
F_26 ( & V_3 -> V_65 , V_61 ) ;
return 0 ;
}
static void F_70 ( struct V_102 * V_103 )
{
struct V_2 * V_3 = F_61 ( V_103 ) ;
T_2 V_123 = F_71 ( V_103 -> V_105 ) ;
T_3 V_124 = F_72 ( V_103 -> V_105 ) ;
F_30 ( 1 << V_124 , V_3 -> V_66 + V_123 ) ;
}
static void F_73 ( struct V_102 * V_103 )
{
struct V_2 * V_3 = F_61 ( V_103 ) ;
T_2 V_79 = F_74 ( V_103 -> V_105 ) ;
T_3 V_125 = F_75 ( V_103 -> V_105 ) ;
unsigned long V_61 ;
T_2 V_38 ;
F_23 ( & V_3 -> V_65 , V_61 ) ;
V_38 = F_27 ( V_3 -> V_66 + V_79 ) ;
F_30 ( V_38 & ~ ( 1 << V_125 ) , V_3 -> V_66 + V_79 ) ;
F_26 ( & V_3 -> V_65 , V_61 ) ;
}
static void F_76 ( struct V_102 * V_103 )
{
struct V_2 * V_3 = F_61 ( V_103 ) ;
T_2 V_79 = F_74 ( V_103 -> V_105 ) ;
T_3 V_125 = F_75 ( V_103 -> V_105 ) ;
unsigned long V_61 ;
T_2 V_38 ;
F_23 ( & V_3 -> V_65 , V_61 ) ;
V_38 = F_27 ( V_3 -> V_66 + V_79 ) ;
F_30 ( V_38 | ( 1 << V_125 ) , V_3 -> V_66 + V_79 ) ;
F_26 ( & V_3 -> V_65 , V_61 ) ;
}
static void F_77 ( struct V_102 * V_103 )
{
F_70 ( V_103 ) ;
F_76 ( V_103 ) ;
}
static int F_78 ( struct V_126 * V_103 ,
struct V_27 * V_28 ,
const T_2 * V_127 ,
unsigned int V_128 ,
unsigned long * V_129 ,
unsigned int * V_130 )
{
struct V_14 * V_17 ;
int V_20 , V_78 ;
if ( V_128 < 3 )
return - V_40 ;
V_78 = V_93 * V_127 [ 0 ] ;
V_20 = V_78 + V_127 [ 1 ] ;
V_17 = F_4 ( V_103 -> V_131 ,
V_20 , L_11 ) ;
if ( ! V_17 )
return - V_40 ;
* V_129 = V_17 -> V_98 * V_93 + V_17 -> V_96 ;
* V_130 = V_127 [ 2 ] ;
return 0 ;
}
static void F_79 ( struct V_132 * V_17 )
{
unsigned int V_133 = F_80 ( V_17 ) ;
struct V_134 * V_77 = F_81 ( V_17 ) ;
struct V_2 * V_3 = F_82 ( V_17 ) ;
unsigned long V_135 , V_79 , V_38 ;
for ( V_135 = 0 ; V_135 < V_3 -> V_17 -> V_136 ; V_135 ++ )
if ( V_133 == V_3 -> V_133 [ V_135 ] )
break;
if ( V_135 == V_3 -> V_17 -> V_136 )
return;
V_79 = F_83 ( V_135 ) ;
V_38 = F_27 ( V_3 -> V_66 + V_79 ) ;
if ( V_38 ) {
int V_137 ;
F_84 ( V_77 , V_17 ) ;
F_85 (irqoffset, &val, IRQ_PER_BANK) {
int V_138 = F_59 ( V_3 -> V_101 ,
V_135 * V_99 + V_137 ) ;
F_86 ( V_138 ) ;
}
F_87 ( V_77 , V_17 ) ;
}
}
static int F_88 ( struct V_2 * V_3 ,
const char * V_9 )
{
struct V_10 * V_11 = V_3 -> V_12 ;
while ( V_11 -> V_9 ) {
if ( strcmp ( V_11 -> V_9 , V_9 ) == 0 ) {
V_11 -> V_6 ++ ;
return - V_139 ;
}
V_11 ++ ;
}
V_11 -> V_9 = V_9 ;
V_11 -> V_6 = 1 ;
V_3 -> V_13 ++ ;
return 0 ;
}
static int F_89 ( struct V_140 * V_141 )
{
struct V_2 * V_3 = F_90 ( V_141 ) ;
int V_5 ;
V_3 -> V_6 = V_3 -> V_17 -> V_18 ;
V_3 -> V_8 = F_91 ( & V_141 -> V_39 ,
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
V_3 -> V_12 = F_91 ( & V_141 -> V_39 ,
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
V_3 -> V_104 [ V_96 ] = V_20 -> V_20 . V_23 ;
}
F_88 ( V_3 , V_11 -> V_9 ) ;
V_11 ++ ;
}
}
V_3 -> V_12 = F_92 ( V_3 -> V_12 ,
V_3 -> V_13 * sizeof( * V_3 -> V_12 ) ,
V_41 ) ;
for ( V_5 = 0 ; V_5 < V_3 -> V_17 -> V_18 ; V_5 ++ ) {
const struct V_19 * V_20 = V_3 -> V_17 -> V_21 + V_5 ;
struct V_14 * V_11 = V_20 -> V_12 ;
while ( V_11 -> V_9 ) {
struct V_10 * V_142 ;
const char * * V_143 ;
V_142 = F_2 ( V_3 ,
V_11 -> V_9 ) ;
if ( ! V_142 )
return - V_40 ;
if ( ! V_142 -> V_8 ) {
V_142 -> V_8 =
F_91 ( & V_141 -> V_39 ,
V_142 -> V_6 * sizeof( * V_142 -> V_8 ) ,
V_41 ) ;
if ( ! V_142 -> V_8 )
return - V_42 ;
}
V_143 = V_142 -> V_8 ;
while ( * V_143 )
V_143 ++ ;
* V_143 = V_20 -> V_20 . V_9 ;
V_11 ++ ;
}
}
return 0 ;
}
int F_93 ( struct V_140 * V_141 ,
const struct V_144 * V_17 )
{
struct V_27 * V_28 = V_141 -> V_39 . V_145 ;
struct V_146 * V_147 ;
struct V_148 * V_21 ;
struct V_2 * V_3 ;
struct V_149 * V_150 ;
int V_5 , V_36 , V_151 ;
struct V_152 * V_152 ;
V_3 = F_91 ( & V_141 -> V_39 , sizeof( * V_3 ) , V_41 ) ;
if ( ! V_3 )
return - V_42 ;
F_94 ( V_141 , V_3 ) ;
F_95 ( & V_3 -> V_65 ) ;
V_150 = F_96 ( V_141 , V_153 , 0 ) ;
V_3 -> V_66 = F_97 ( & V_141 -> V_39 , V_150 ) ;
if ( F_98 ( V_3 -> V_66 ) )
return F_99 ( V_3 -> V_66 ) ;
V_3 -> V_39 = & V_141 -> V_39 ;
V_3 -> V_17 = V_17 ;
V_3 -> V_104 = F_100 ( & V_141 -> V_39 ,
V_99 * V_3 -> V_17 -> V_136 ,
sizeof( * V_3 -> V_104 ) ,
V_41 ) ;
if ( ! V_3 -> V_104 )
return - V_42 ;
V_36 = F_89 ( V_141 ) ;
if ( V_36 ) {
F_11 ( & V_141 -> V_39 , L_14 , V_36 ) ;
return V_36 ;
}
V_21 = F_91 ( & V_141 -> V_39 ,
V_3 -> V_17 -> V_18 * sizeof( * V_21 ) ,
V_41 ) ;
if ( ! V_21 )
return - V_42 ;
for ( V_5 = 0 ; V_5 < V_3 -> V_17 -> V_18 ; V_5 ++ )
V_21 [ V_5 ] = V_3 -> V_17 -> V_21 [ V_5 ] . V_20 ;
V_147 = F_91 ( & V_141 -> V_39 ,
sizeof( * V_147 ) ,
V_41 ) ;
if ( ! V_147 )
return - V_42 ;
V_147 -> V_9 = F_101 ( & V_141 -> V_39 ) ;
V_147 -> V_154 = V_155 ;
V_147 -> V_21 = V_21 ;
V_147 -> V_18 = V_3 -> V_17 -> V_18 ;
V_147 -> V_156 = & V_157 ;
V_147 -> V_158 = & V_159 ;
V_147 -> V_160 = & V_161 ;
V_3 -> V_84 = F_102 ( V_147 ,
& V_141 -> V_39 , V_3 ) ;
if ( F_98 ( V_3 -> V_84 ) ) {
F_11 ( & V_141 -> V_39 , L_15 ) ;
return F_99 ( V_3 -> V_84 ) ;
}
V_3 -> V_77 = F_91 ( & V_141 -> V_39 , sizeof( * V_3 -> V_77 ) , V_41 ) ;
if ( ! V_3 -> V_77 ) {
V_36 = - V_42 ;
goto V_162;
}
V_151 = V_3 -> V_17 -> V_21 [ V_3 -> V_17 -> V_18 - 1 ] . V_20 . V_23 ;
V_3 -> V_77 -> V_154 = V_155 ;
V_3 -> V_77 -> V_163 = F_41 ,
V_3 -> V_77 -> free = F_43 ,
V_3 -> V_77 -> V_164 = F_45 ,
V_3 -> V_77 -> V_165 = F_54 ,
V_3 -> V_77 -> V_166 = F_47 ,
V_3 -> V_77 -> V_167 = F_52 ,
V_3 -> V_77 -> V_168 = F_56 ,
V_3 -> V_77 -> V_169 = F_57 ,
V_3 -> V_77 -> V_170 = 3 ,
V_3 -> V_77 -> V_171 = false ,
V_3 -> V_77 -> V_94 = F_103 ( V_151 , V_93 ) -
V_3 -> V_17 -> V_62 ;
V_3 -> V_77 -> V_100 = F_101 ( & V_141 -> V_39 ) ;
V_3 -> V_77 -> V_39 = & V_141 -> V_39 ;
V_3 -> V_77 -> V_78 = V_3 -> V_17 -> V_62 ;
V_36 = F_104 ( V_3 -> V_77 ) ;
if ( V_36 )
goto V_162;
for ( V_5 = 0 ; V_5 < V_3 -> V_17 -> V_18 ; V_5 ++ ) {
const struct V_19 * V_20 = V_3 -> V_17 -> V_21 + V_5 ;
V_36 = F_105 ( V_3 -> V_77 , F_101 ( & V_141 -> V_39 ) ,
V_20 -> V_20 . V_23 - V_3 -> V_17 -> V_62 ,
V_20 -> V_20 . V_23 , 1 ) ;
if ( V_36 )
goto V_172;
}
V_152 = F_106 ( & V_141 -> V_39 , NULL ) ;
if ( F_98 ( V_152 ) ) {
V_36 = F_99 ( V_152 ) ;
goto V_172;
}
V_36 = F_107 ( V_152 ) ;
if ( V_36 )
goto V_172;
V_3 -> V_133 = F_100 ( & V_141 -> V_39 ,
V_3 -> V_17 -> V_136 ,
sizeof( * V_3 -> V_133 ) ,
V_41 ) ;
if ( ! V_3 -> V_133 ) {
V_36 = - V_42 ;
goto V_173;
}
for ( V_5 = 0 ; V_5 < V_3 -> V_17 -> V_136 ; V_5 ++ ) {
V_3 -> V_133 [ V_5 ] = F_108 ( V_141 , V_5 ) ;
if ( V_3 -> V_133 [ V_5 ] < 0 ) {
V_36 = V_3 -> V_133 [ V_5 ] ;
goto V_173;
}
}
V_3 -> V_101 = F_109 ( V_28 ,
V_3 -> V_17 -> V_136 * V_99 ,
& V_174 ,
V_3 ) ;
if ( ! V_3 -> V_101 ) {
F_11 ( & V_141 -> V_39 , L_16 ) ;
V_36 = - V_42 ;
goto V_173;
}
for ( V_5 = 0 ; V_5 < ( V_3 -> V_17 -> V_136 * V_99 ) ; V_5 ++ ) {
int V_175 = F_110 ( V_3 -> V_101 , V_5 ) ;
F_111 ( V_175 , & V_120 ,
V_121 ) ;
F_112 ( V_175 , V_3 ) ;
} ;
for ( V_5 = 0 ; V_5 < V_3 -> V_17 -> V_136 ; V_5 ++ ) {
F_30 ( 0 , V_3 -> V_66 + F_113 ( V_5 ) ) ;
F_30 ( 0xffffffff ,
V_3 -> V_66 + F_83 ( V_5 ) ) ;
F_114 ( V_3 -> V_133 [ V_5 ] ,
F_79 ,
V_3 ) ;
}
F_115 ( & V_141 -> V_39 , L_17 ) ;
return 0 ;
V_173:
F_116 ( V_152 ) ;
V_172:
F_117 ( V_3 -> V_77 ) ;
V_162:
F_118 ( V_3 -> V_84 ) ;
return V_36 ;
}
