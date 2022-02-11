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
static bool F_9 ( struct V_27 * V_28 )
{
return F_10 ( V_28 , L_1 , NULL ) ||
F_10 ( V_28 , L_2 , NULL ) ||
F_10 ( V_28 , L_3 , NULL ) ||
F_10 ( V_28 , L_4 , NULL ) ;
}
static bool F_11 ( struct V_27 * V_28 )
{
return F_10 ( V_28 , L_5 , NULL ) ||
F_10 ( V_28 , L_6 , NULL ) ;
}
static int F_12 ( struct V_27 * V_28 )
{
T_2 V_29 ;
if ( F_10 ( V_28 , L_1 , NULL ) )
return V_30 ;
if ( F_10 ( V_28 , L_2 , NULL ) )
return V_31 ;
if ( F_10 ( V_28 , L_3 , NULL ) )
return V_32 ;
if ( F_13 ( V_28 , L_4 , & V_29 ) )
return - V_33 ;
switch ( V_29 ) {
case V_34 :
return V_32 ;
case V_35 :
return V_30 ;
case V_36 :
return V_31 ;
}
return - V_33 ;
}
static int F_14 ( struct V_27 * V_28 )
{
T_2 V_29 ;
if ( ! F_13 ( V_28 , L_5 , & V_29 ) ) {
if ( V_29 < 10 )
return - V_33 ;
if ( V_29 > 40 )
V_29 = 40 ;
return F_15 ( V_29 , 10 ) ;
}
if ( F_13 ( V_28 , L_6 , & V_29 ) )
return - V_33 ;
return ( V_29 + 1 ) * 10 ;
}
static const char * F_16 ( struct V_27 * V_28 )
{
const char * V_37 ;
int V_38 ;
V_38 = F_17 ( V_28 , L_7 , & V_37 ) ;
if ( ! V_38 )
return V_37 ;
V_38 = F_17 ( V_28 , L_8 , & V_37 ) ;
if ( ! V_38 )
return V_37 ;
return NULL ;
}
static const char * F_18 ( struct V_27 * V_28 ,
int * V_18 )
{
int V_39 ;
V_39 = F_19 ( V_28 , L_9 ) ;
if ( V_39 > 0 ) {
* V_18 = V_39 ;
return L_9 ;
}
V_39 = F_19 ( V_28 , L_10 ) ;
if ( V_39 > 0 ) {
* V_18 = V_39 ;
return L_10 ;
}
return NULL ;
}
static unsigned long * F_20 ( struct V_27 * V_28 ,
unsigned int * V_40 )
{
unsigned long * V_41 ;
unsigned int V_42 = 0 , V_43 = 0 ;
int V_38 ;
if ( F_11 ( V_28 ) )
V_42 ++ ;
if ( F_9 ( V_28 ) )
V_42 ++ ;
if ( ! V_42 )
return NULL ;
V_41 = F_21 ( V_42 * sizeof( * V_41 ) , V_44 ) ;
if ( ! V_41 )
return F_22 ( - V_45 ) ;
if ( F_11 ( V_28 ) ) {
int V_46 = F_14 ( V_28 ) ;
if ( V_46 < 0 ) {
V_38 = V_46 ;
goto V_47;
}
V_41 [ V_43 ++ ] = F_23 ( V_48 ,
V_46 ) ;
}
if ( F_9 ( V_28 ) ) {
int V_49 = F_12 ( V_28 ) ;
int V_50 = 0 ;
if ( V_49 < 0 ) {
V_38 = V_49 ;
goto V_47;
}
if ( V_49 != V_32 )
V_50 = 1 ;
V_41 [ V_43 ++ ] = F_23 ( V_49 , V_50 ) ;
}
* V_40 = V_42 ;
return V_41 ;
V_47:
F_24 ( V_41 ) ;
return F_22 ( V_38 ) ;
}
static int F_25 ( struct V_24 * V_25 ,
struct V_27 * V_28 ,
struct V_51 * * V_52 ,
unsigned * V_53 )
{
struct V_2 * V_3 = F_6 ( V_25 ) ;
unsigned long * V_41 ;
struct V_54 * V_55 ;
const char * V_37 , * V_56 ;
const char * V_4 ;
int V_38 , V_18 , V_57 , V_42 = 0 , V_5 = 0 ;
* V_52 = NULL ;
* V_53 = 0 ;
V_37 = F_16 ( V_28 ) ;
if ( ! V_37 ) {
F_26 ( V_3 -> V_58 , L_11 ,
V_28 -> V_9 ) ;
return - V_33 ;
}
V_56 = F_18 ( V_28 , & V_18 ) ;
if ( ! V_56 ) {
F_26 ( V_3 -> V_58 , L_12 ,
V_28 -> V_9 ) ;
return - V_33 ;
}
V_57 = V_18 * 2 ;
* V_52 = F_27 ( V_57 * sizeof( struct V_51 ) , V_44 ) ;
if ( ! * V_52 )
return - V_45 ;
V_41 = F_20 ( V_28 , & V_42 ) ;
if ( F_28 ( V_41 ) ) {
V_38 = F_29 ( V_41 ) ;
goto V_59;
}
F_30 (node, pin_prop, prop, group) {
struct V_1 * V_7 =
F_1 ( V_3 , V_4 ) ;
if ( ! V_7 ) {
F_26 ( V_3 -> V_58 , L_13 , V_4 ) ;
continue;
}
if ( ! F_3 ( V_3 ,
V_7 -> V_9 ,
V_37 ) ) {
F_26 ( V_3 -> V_58 , L_14 ,
V_37 , V_4 ) ;
continue;
}
( * V_52 ) [ V_5 ] . type = V_60 ;
( * V_52 ) [ V_5 ] . V_61 . V_62 . V_4 = V_4 ;
( * V_52 ) [ V_5 ] . V_61 . V_62 . V_37 = V_37 ;
V_5 ++ ;
if ( V_41 ) {
( * V_52 ) [ V_5 ] . type = V_63 ;
( * V_52 ) [ V_5 ] . V_61 . V_64 . V_65 = V_4 ;
( * V_52 ) [ V_5 ] . V_61 . V_64 . V_64 = V_41 ;
( * V_52 ) [ V_5 ] . V_61 . V_64 . V_66 = V_42 ;
V_5 ++ ;
}
}
* V_53 = V_5 ;
* V_52 = F_31 ( * V_52 , V_5 * sizeof( struct V_51 ) , V_44 ) ;
if ( ! * V_52 )
return - V_45 ;
return 0 ;
V_59:
F_24 ( * V_52 ) ;
* V_52 = NULL ;
return V_38 ;
}
static void F_32 ( struct V_24 * V_25 ,
struct V_51 * V_52 ,
unsigned V_53 )
{
int V_5 ;
for ( V_5 = 1 ; V_5 < V_53 ; V_5 ++ ) {
if ( V_52 [ V_5 ] . type != V_63 )
continue;
F_24 ( V_52 [ V_5 ] . V_61 . V_64 . V_64 ) ;
break;
}
F_24 ( V_52 ) ;
}
static int F_33 ( unsigned V_20 , enum V_67 V_68 ,
T_2 * V_69 , T_2 * V_70 , T_2 * V_71 )
{
switch ( V_68 ) {
case V_48 :
* V_69 = F_34 ( V_20 ) ;
* V_70 = F_35 ( V_20 ) ;
* V_71 = V_72 ;
break;
case V_30 :
case V_31 :
case V_32 :
* V_69 = F_36 ( V_20 ) ;
* V_70 = F_37 ( V_20 ) ;
* V_71 = V_73 ;
break;
default:
return - V_74 ;
}
return 0 ;
}
static int F_38 ( struct V_24 * V_25 , unsigned V_20 ,
unsigned long * V_75 )
{
struct V_2 * V_3 = F_6 ( V_25 ) ;
enum V_67 V_68 = F_39 ( * V_75 ) ;
T_2 V_69 , V_70 , V_71 , V_29 ;
T_1 V_50 ;
int V_38 ;
V_20 -= V_3 -> V_17 -> V_76 ;
V_38 = F_33 ( V_20 , V_68 , & V_69 , & V_70 , & V_71 ) ;
if ( V_38 < 0 )
return V_38 ;
V_29 = ( F_40 ( V_3 -> V_77 + V_69 ) >> V_70 ) & V_71 ;
switch ( F_39 ( * V_75 ) ) {
case V_48 :
V_50 = ( V_29 + 1 ) * 10 ;
break;
case V_30 :
if ( V_29 != V_35 )
return - V_33 ;
V_50 = 1 ;
break;
case V_31 :
if ( V_29 != V_36 )
return - V_33 ;
V_50 = 1 ;
break;
case V_32 :
if ( V_29 != V_34 )
return - V_33 ;
V_50 = 0 ;
break;
default:
F_41 ( 1 ) ;
return - V_74 ;
}
* V_75 = F_23 ( V_68 , V_50 ) ;
return 0 ;
}
static int F_42 ( struct V_24 * V_25 ,
unsigned V_4 ,
unsigned long * V_75 )
{
struct V_2 * V_3 = F_6 ( V_25 ) ;
struct V_1 * V_78 = & V_3 -> V_8 [ V_4 ] ;
return F_38 ( V_25 , V_78 -> V_20 , V_75 ) ;
}
static int F_43 ( struct V_24 * V_25 ,
unsigned V_4 ,
unsigned long * V_64 ,
unsigned V_66 )
{
struct V_2 * V_3 = F_6 ( V_25 ) ;
struct V_1 * V_78 = & V_3 -> V_8 [ V_4 ] ;
unsigned V_20 = V_78 -> V_20 - V_3 -> V_17 -> V_76 ;
int V_5 ;
for ( V_5 = 0 ; V_5 < V_66 ; V_5 ++ ) {
enum V_67 V_68 ;
unsigned long V_79 ;
T_2 V_69 , V_70 , V_71 , V_80 ;
T_2 V_50 , V_29 ;
int V_38 ;
V_68 = F_39 ( V_64 [ V_5 ] ) ;
V_50 = F_44 ( V_64 [ V_5 ] ) ;
V_38 = F_33 ( V_20 , V_68 , & V_69 , & V_70 , & V_71 ) ;
if ( V_38 < 0 )
return V_38 ;
switch ( V_68 ) {
case V_48 :
if ( V_50 < 10 || V_50 > 40 )
return - V_33 ;
V_29 = V_50 / 10 - 1 ;
break;
case V_32 :
continue;
case V_30 :
if ( V_50 == 0 )
return - V_33 ;
V_29 = 1 ;
break;
case V_31 :
if ( V_50 == 0 )
return - V_33 ;
V_29 = 2 ;
break;
default:
F_41 ( 1 ) ;
return - V_74 ;
}
F_45 ( & V_3 -> V_81 , V_79 ) ;
V_80 = F_40 ( V_3 -> V_77 + V_69 ) ;
V_80 &= ~ ( V_71 << V_70 ) ;
F_46 ( V_80 | V_29 << V_70 , V_3 -> V_77 + V_69 ) ;
F_47 ( & V_3 -> V_81 , V_79 ) ;
}
return 0 ;
}
static int F_48 ( struct V_24 * V_25 )
{
struct V_2 * V_3 = F_6 ( V_25 ) ;
return V_3 -> V_13 ;
}
static const char * F_49 ( struct V_24 * V_25 ,
unsigned V_37 )
{
struct V_2 * V_3 = F_6 ( V_25 ) ;
return V_3 -> V_12 [ V_37 ] . V_9 ;
}
static int F_50 ( struct V_24 * V_25 ,
unsigned V_37 ,
const char * const * * V_8 ,
unsigned * const V_82 )
{
struct V_2 * V_3 = F_6 ( V_25 ) ;
* V_8 = V_3 -> V_12 [ V_37 ] . V_8 ;
* V_82 = V_3 -> V_12 [ V_37 ] . V_6 ;
return 0 ;
}
static void F_51 ( struct V_24 * V_25 ,
unsigned V_20 ,
T_3 V_75 )
{
struct V_2 * V_3 = F_6 ( V_25 ) ;
unsigned long V_79 ;
T_2 V_29 , V_71 ;
F_45 ( & V_3 -> V_81 , V_79 ) ;
V_20 -= V_3 -> V_17 -> V_76 ;
V_29 = F_40 ( V_3 -> V_77 + F_52 ( V_20 ) ) ;
V_71 = V_83 << F_53 ( V_20 ) ;
F_46 ( ( V_29 & ~ V_71 ) | V_75 << F_53 ( V_20 ) ,
V_3 -> V_77 + F_52 ( V_20 ) ) ;
F_47 ( & V_3 -> V_81 , V_79 ) ;
}
static int F_54 ( struct V_24 * V_25 ,
unsigned V_37 ,
unsigned V_4 )
{
struct V_2 * V_3 = F_6 ( V_25 ) ;
struct V_1 * V_78 = V_3 -> V_8 + V_4 ;
struct V_10 * V_11 = V_3 -> V_12 + V_37 ;
struct V_14 * V_17 =
F_3 ( V_3 ,
V_78 -> V_9 ,
V_11 -> V_9 ) ;
if ( ! V_17 )
return - V_33 ;
F_51 ( V_25 , V_78 -> V_20 , V_17 -> V_84 ) ;
return 0 ;
}
static int
F_55 ( struct V_24 * V_25 ,
struct V_85 * V_86 ,
unsigned V_69 ,
bool V_87 )
{
struct V_2 * V_3 = F_6 ( V_25 ) ;
struct V_14 * V_17 ;
const char * V_11 ;
if ( V_87 )
V_11 = L_15 ;
else
V_11 = L_16 ;
V_17 = F_4 ( V_3 , V_69 , V_11 ) ;
if ( ! V_17 )
return - V_33 ;
F_51 ( V_25 , V_69 , V_17 -> V_84 ) ;
return 0 ;
}
static int F_56 ( struct V_88 * V_89 ,
unsigned V_69 )
{
return F_57 ( V_89 -> V_90 + V_69 ) ;
}
static int F_58 ( struct V_88 * V_89 , unsigned V_69 )
{
struct V_2 * V_3 = F_59 ( V_89 ) ;
T_2 V_80 = F_60 ( V_69 ) ;
T_3 V_91 = F_61 ( V_69 ) ;
bool V_92 = V_3 -> V_17 -> V_93 &&
F_62 ( V_89 , V_69 ) ;
T_2 V_20 = V_69 + V_89 -> V_90 ;
T_2 V_29 ;
if ( V_92 )
F_51 ( V_3 -> V_94 , V_20 , V_95 ) ;
V_29 = ( F_40 ( V_3 -> V_77 + V_80 ) >> V_91 ) & V_96 ;
if ( V_92 )
F_51 ( V_3 -> V_94 , V_20 , V_97 ) ;
return ! ! V_29 ;
}
static void F_63 ( struct V_88 * V_89 ,
unsigned V_69 , int V_98 )
{
struct V_2 * V_3 = F_59 ( V_89 ) ;
T_2 V_80 = F_60 ( V_69 ) ;
T_3 V_91 = F_61 ( V_69 ) ;
unsigned long V_79 ;
T_2 V_99 ;
F_45 ( & V_3 -> V_81 , V_79 ) ;
V_99 = F_40 ( V_3 -> V_77 + V_80 ) ;
if ( V_98 )
V_99 |= F_64 ( V_91 ) ;
else
V_99 &= ~ ( F_64 ( V_91 ) ) ;
F_46 ( V_99 , V_3 -> V_77 + V_80 ) ;
F_47 ( & V_3 -> V_81 , V_79 ) ;
}
static int F_65 ( struct V_88 * V_89 ,
unsigned V_69 , int V_98 )
{
F_63 ( V_89 , V_69 , V_98 ) ;
return F_66 ( V_89 -> V_90 + V_69 ) ;
}
static int F_67 ( struct V_88 * V_100 ,
const struct V_101 * V_102 ,
T_2 * V_79 )
{
int V_20 , V_90 ;
V_90 = V_103 * V_102 -> args [ 0 ] ;
V_20 = V_90 + V_102 -> args [ 1 ] ;
if ( V_20 > V_100 -> V_104 )
return - V_33 ;
if ( V_79 )
* V_79 = V_102 -> args [ 2 ] ;
return V_20 ;
}
static int F_68 ( struct V_88 * V_89 , unsigned V_69 )
{
struct V_2 * V_3 = F_59 ( V_89 ) ;
struct V_14 * V_17 ;
unsigned V_105 = V_3 -> V_17 -> V_76 + V_69 ;
unsigned V_106 ;
if ( V_69 >= V_89 -> V_104 )
return - V_107 ;
V_17 = F_4 ( V_3 , V_105 , L_17 ) ;
if ( ! V_17 )
return - V_33 ;
V_106 = V_17 -> V_108 * V_109 + V_17 -> V_106 ;
F_69 ( V_89 -> V_110 , L_18 ,
V_89 -> V_111 , V_69 + V_89 -> V_90 , V_106 ) ;
return F_70 ( V_3 -> V_112 , V_106 ) ;
}
static int F_71 ( struct V_113 * V_114 )
{
struct V_2 * V_3 = F_72 ( V_114 ) ;
struct V_14 * V_11 ;
int V_38 ;
V_11 = F_4 ( V_3 ,
V_3 -> V_115 [ V_114 -> V_116 ] , L_17 ) ;
if ( ! V_11 )
return - V_33 ;
V_38 = F_73 ( V_3 -> V_89 ,
V_3 -> V_115 [ V_114 -> V_116 ] - V_3 -> V_17 -> V_76 ) ;
if ( V_38 ) {
F_26 ( V_3 -> V_58 , L_19 ,
F_74 ( V_114 ) ) ;
return V_38 ;
}
F_51 ( V_3 -> V_94 , V_3 -> V_115 [ V_114 -> V_116 ] , V_11 -> V_84 ) ;
return 0 ;
}
static void F_75 ( struct V_113 * V_114 )
{
struct V_2 * V_3 = F_72 ( V_114 ) ;
F_76 ( V_3 -> V_89 ,
V_3 -> V_115 [ V_114 -> V_116 ] - V_3 -> V_17 -> V_76 ) ;
}
static int F_77 ( struct V_113 * V_114 , unsigned int type )
{
struct V_2 * V_3 = F_72 ( V_114 ) ;
T_2 V_80 = F_78 ( V_114 -> V_116 , V_3 -> V_17 -> V_117 ) ;
T_3 V_91 = F_79 ( V_114 -> V_116 ) ;
unsigned long V_79 ;
T_2 V_99 ;
T_3 V_118 ;
switch ( type ) {
case V_119 :
V_118 = V_120 ;
break;
case V_121 :
V_118 = V_122 ;
break;
case V_123 :
V_118 = V_124 ;
break;
case V_125 :
V_118 = V_126 ;
break;
case V_127 :
V_118 = V_128 ;
break;
default:
return - V_33 ;
}
F_45 ( & V_3 -> V_81 , V_79 ) ;
if ( type & V_129 )
F_80 ( V_114 , & V_130 ,
V_131 , NULL ) ;
else
F_80 ( V_114 , & V_132 ,
V_133 , NULL ) ;
V_99 = F_40 ( V_3 -> V_77 + V_80 ) ;
V_99 &= ~ ( V_134 << V_91 ) ;
F_46 ( V_99 | ( V_118 << V_91 ) , V_3 -> V_77 + V_80 ) ;
F_47 ( & V_3 -> V_81 , V_79 ) ;
return 0 ;
}
static void F_81 ( struct V_113 * V_114 )
{
struct V_2 * V_3 = F_72 ( V_114 ) ;
T_2 V_135 = F_82 ( V_114 -> V_116 ,
V_3 -> V_17 -> V_117 ) ;
T_3 V_136 = F_83 ( V_114 -> V_116 ) ;
F_46 ( 1 << V_136 , V_3 -> V_77 + V_135 ) ;
}
static void F_84 ( struct V_113 * V_114 )
{
struct V_2 * V_3 = F_72 ( V_114 ) ;
T_2 V_80 = F_85 ( V_114 -> V_116 , V_3 -> V_17 -> V_117 ) ;
T_3 V_43 = F_86 ( V_114 -> V_116 ) ;
unsigned long V_79 ;
T_2 V_29 ;
F_45 ( & V_3 -> V_81 , V_79 ) ;
V_29 = F_40 ( V_3 -> V_77 + V_80 ) ;
F_46 ( V_29 & ~ ( 1 << V_43 ) , V_3 -> V_77 + V_80 ) ;
F_47 ( & V_3 -> V_81 , V_79 ) ;
}
static void F_87 ( struct V_113 * V_114 )
{
struct V_2 * V_3 = F_72 ( V_114 ) ;
T_2 V_80 = F_85 ( V_114 -> V_116 , V_3 -> V_17 -> V_117 ) ;
T_3 V_43 = F_86 ( V_114 -> V_116 ) ;
unsigned long V_79 ;
T_2 V_29 ;
F_45 ( & V_3 -> V_81 , V_79 ) ;
V_29 = F_40 ( V_3 -> V_77 + V_80 ) ;
F_46 ( V_29 | ( 1 << V_43 ) , V_3 -> V_77 + V_80 ) ;
F_47 ( & V_3 -> V_81 , V_79 ) ;
}
static void F_88 ( struct V_113 * V_114 )
{
F_81 ( V_114 ) ;
F_87 ( V_114 ) ;
}
static int F_89 ( struct V_137 * V_114 ,
struct V_27 * V_28 ,
const T_2 * V_138 ,
unsigned int V_139 ,
unsigned long * V_140 ,
unsigned int * V_141 )
{
struct V_2 * V_3 = V_114 -> V_142 ;
struct V_14 * V_17 ;
int V_20 , V_90 ;
if ( V_139 < 3 )
return - V_33 ;
V_90 = V_103 * V_138 [ 0 ] ;
V_20 = V_3 -> V_17 -> V_76 + V_90 + V_138 [ 1 ] ;
V_17 = F_4 ( V_3 , V_20 , L_17 ) ;
if ( ! V_17 )
return - V_33 ;
* V_140 = V_17 -> V_108 * V_103 + V_17 -> V_106 ;
* V_141 = V_138 [ 2 ] ;
return 0 ;
}
static void F_90 ( struct V_143 * V_17 )
{
unsigned int V_144 = F_91 ( V_17 ) ;
struct V_145 * V_89 = F_92 ( V_17 ) ;
struct V_2 * V_3 = F_93 ( V_17 ) ;
unsigned long V_146 , V_80 , V_29 ;
for ( V_146 = 0 ; V_146 < V_3 -> V_17 -> V_147 ; V_146 ++ )
if ( V_144 == V_3 -> V_144 [ V_146 ] )
break;
if ( V_146 == V_3 -> V_17 -> V_147 )
return;
V_80 = F_94 ( V_146 , V_3 -> V_17 -> V_117 ) ;
V_29 = F_40 ( V_3 -> V_77 + V_80 ) ;
if ( V_29 ) {
int V_148 ;
F_95 ( V_89 , V_17 ) ;
F_96 (irqoffset, &val, IRQ_PER_BANK) {
int V_149 = F_70 ( V_3 -> V_112 ,
V_146 * V_109 + V_148 ) ;
F_97 ( V_149 ) ;
}
F_98 ( V_89 , V_17 ) ;
}
}
static int F_99 ( struct V_2 * V_3 ,
const char * V_9 )
{
struct V_10 * V_11 = V_3 -> V_12 ;
while ( V_11 -> V_9 ) {
if ( strcmp ( V_11 -> V_9 , V_9 ) == 0 ) {
V_11 -> V_6 ++ ;
return - V_150 ;
}
V_11 ++ ;
}
V_11 -> V_9 = V_9 ;
V_11 -> V_6 = 1 ;
V_3 -> V_13 ++ ;
return 0 ;
}
static int F_100 ( struct V_151 * V_152 )
{
struct V_2 * V_3 = F_101 ( V_152 ) ;
int V_5 ;
V_3 -> V_8 = F_102 ( & V_152 -> V_58 ,
V_3 -> V_17 -> V_18 * sizeof( * V_3 -> V_8 ) ,
V_44 ) ;
if ( ! V_3 -> V_8 )
return - V_45 ;
for ( V_5 = 0 ; V_5 < V_3 -> V_17 -> V_18 ; V_5 ++ ) {
const struct V_19 * V_20 = V_3 -> V_17 -> V_21 + V_5 ;
struct V_1 * V_4 = V_3 -> V_8 + V_3 -> V_6 ;
if ( V_20 -> V_153 && ! ( V_3 -> V_153 & V_20 -> V_153 ) )
continue;
V_4 -> V_9 = V_20 -> V_20 . V_9 ;
V_4 -> V_20 = V_20 -> V_20 . V_23 ;
V_3 -> V_6 ++ ;
}
V_3 -> V_12 = F_102 ( & V_152 -> V_58 ,
V_3 -> V_6 * sizeof( * V_3 -> V_12 ) ,
V_44 ) ;
if ( ! V_3 -> V_12 )
return - V_45 ;
for ( V_5 = 0 ; V_5 < V_3 -> V_17 -> V_18 ; V_5 ++ ) {
const struct V_19 * V_20 = V_3 -> V_17 -> V_21 + V_5 ;
struct V_14 * V_11 ;
if ( V_20 -> V_153 && ! ( V_3 -> V_153 & V_20 -> V_153 ) )
continue;
for ( V_11 = V_20 -> V_12 ; V_11 -> V_9 ; V_11 ++ ) {
if ( V_11 -> V_153 && ! ( V_3 -> V_153 & V_11 -> V_153 ) )
continue;
if ( ! strcmp ( V_11 -> V_9 , L_17 ) ) {
int V_106 = V_11 -> V_106 + V_11 -> V_108 * V_109 ;
V_3 -> V_115 [ V_106 ] = V_20 -> V_20 . V_23 ;
}
F_99 ( V_3 , V_11 -> V_9 ) ;
}
}
V_3 -> V_12 = F_31 ( V_3 -> V_12 ,
V_3 -> V_13 * sizeof( * V_3 -> V_12 ) ,
V_44 ) ;
if ( ! V_3 -> V_12 ) {
F_24 ( V_3 -> V_12 ) ;
return - V_45 ;
}
for ( V_5 = 0 ; V_5 < V_3 -> V_17 -> V_18 ; V_5 ++ ) {
const struct V_19 * V_20 = V_3 -> V_17 -> V_21 + V_5 ;
struct V_14 * V_11 ;
if ( V_20 -> V_153 && ! ( V_3 -> V_153 & V_20 -> V_153 ) )
continue;
for ( V_11 = V_20 -> V_12 ; V_11 -> V_9 ; V_11 ++ ) {
struct V_10 * V_154 ;
const char * * V_155 ;
if ( V_11 -> V_153 && ! ( V_3 -> V_153 & V_11 -> V_153 ) )
continue;
V_154 = F_2 ( V_3 ,
V_11 -> V_9 ) ;
if ( ! V_154 )
return - V_33 ;
if ( ! V_154 -> V_8 ) {
V_154 -> V_8 =
F_102 ( & V_152 -> V_58 ,
V_154 -> V_6 * sizeof( * V_154 -> V_8 ) ,
V_44 ) ;
if ( ! V_154 -> V_8 )
return - V_45 ;
}
V_155 = V_154 -> V_8 ;
while ( * V_155 )
V_155 ++ ;
* V_155 = V_20 -> V_20 . V_9 ;
}
}
return 0 ;
}
static int F_103 ( struct V_156 * V_156 , int V_157 , int * V_158 )
{
unsigned long clock = F_104 ( V_156 ) ;
unsigned int V_159 , V_160 ;
int V_5 ;
V_159 = abs ( V_157 - clock ) ;
V_160 = 0 ;
for ( V_5 = 1 ; V_5 < 8 ; V_5 ++ ) {
int V_161 = abs ( V_157 - ( clock >> V_5 ) ) ;
if ( V_161 < V_159 ) {
V_159 = V_161 ;
V_160 = V_5 ;
}
}
* V_158 = V_159 ;
return V_160 ;
}
static int F_105 ( struct V_2 * V_3 ,
struct V_27 * V_28 )
{
unsigned int V_162 , V_163 ;
unsigned int V_164 , V_165 ;
struct V_156 * V_166 , * V_167 ;
T_3 div , V_168 ;
int V_5 , V_38 ;
if ( F_106 ( V_28 , L_20 , L_21 ) != 3 )
return 0 ;
if ( ! F_10 ( V_28 , L_22 , NULL ) )
return 0 ;
V_167 = F_107 ( V_3 -> V_58 , L_23 ) ;
if ( F_28 ( V_167 ) )
return F_29 ( V_167 ) ;
V_166 = F_107 ( V_3 -> V_58 , L_24 ) ;
if ( F_28 ( V_166 ) )
return F_29 ( V_166 ) ;
for ( V_5 = 0 ; V_5 < V_3 -> V_17 -> V_147 ; V_5 ++ ) {
unsigned long V_169 ;
T_2 V_170 ;
V_38 = F_108 ( V_28 , L_22 ,
V_5 , & V_170 ) ;
if ( V_38 )
return V_38 ;
if ( ! V_170 )
continue;
V_169 = F_109 ( V_171 , V_170 ) ;
V_165 = F_103 ( V_167 ,
V_169 ,
& V_163 ) ;
V_164 = F_103 ( V_166 ,
V_169 ,
& V_162 ) ;
if ( V_162 < V_163 ) {
div = V_164 ;
V_168 = 1 ;
} else {
div = V_165 ;
V_168 = 0 ;
}
F_46 ( V_168 | div << 4 ,
V_3 -> V_77 +
F_110 ( V_5 ,
V_3 -> V_17 -> V_117 ) ) ;
}
return 0 ;
}
int F_111 ( struct V_151 * V_152 ,
const struct V_172 * V_17 ,
unsigned long V_153 )
{
struct V_27 * V_28 = V_152 -> V_58 . V_173 ;
struct V_174 * V_175 ;
struct V_176 * V_21 ;
struct V_2 * V_3 ;
struct V_177 * V_178 ;
int V_5 , V_38 , V_179 , V_180 ;
struct V_156 * V_156 ;
V_3 = F_102 ( & V_152 -> V_58 , sizeof( * V_3 ) , V_44 ) ;
if ( ! V_3 )
return - V_45 ;
F_112 ( V_152 , V_3 ) ;
F_113 ( & V_3 -> V_81 ) ;
V_178 = F_114 ( V_152 , V_181 , 0 ) ;
V_3 -> V_77 = F_115 ( & V_152 -> V_58 , V_178 ) ;
if ( F_28 ( V_3 -> V_77 ) )
return F_29 ( V_3 -> V_77 ) ;
V_3 -> V_58 = & V_152 -> V_58 ;
V_3 -> V_17 = V_17 ;
V_3 -> V_153 = V_153 ;
V_3 -> V_115 = F_116 ( & V_152 -> V_58 ,
V_109 * V_3 -> V_17 -> V_147 ,
sizeof( * V_3 -> V_115 ) ,
V_44 ) ;
if ( ! V_3 -> V_115 )
return - V_45 ;
V_38 = F_100 ( V_152 ) ;
if ( V_38 ) {
F_26 ( & V_152 -> V_58 , L_25 , V_38 ) ;
return V_38 ;
}
V_21 = F_102 ( & V_152 -> V_58 ,
V_3 -> V_17 -> V_18 * sizeof( * V_21 ) ,
V_44 ) ;
if ( ! V_21 )
return - V_45 ;
for ( V_5 = 0 , V_180 = 0 ; V_5 < V_3 -> V_17 -> V_18 ; V_5 ++ ) {
const struct V_19 * V_20 = V_3 -> V_17 -> V_21 + V_5 ;
if ( V_20 -> V_153 && ! ( V_3 -> V_153 & V_20 -> V_153 ) )
continue;
V_21 [ V_180 ++ ] = V_20 -> V_20 ;
}
V_175 = F_102 ( & V_152 -> V_58 ,
sizeof( * V_175 ) ,
V_44 ) ;
if ( ! V_175 )
return - V_45 ;
V_175 -> V_9 = F_117 ( & V_152 -> V_58 ) ;
V_175 -> V_182 = V_183 ;
V_175 -> V_21 = V_21 ;
V_175 -> V_18 = V_3 -> V_6 ;
V_175 -> V_184 = & V_185 ;
V_175 -> V_186 = & V_187 ;
V_175 -> V_188 = & V_189 ;
V_3 -> V_94 = F_118 ( & V_152 -> V_58 , V_175 , V_3 ) ;
if ( F_28 ( V_3 -> V_94 ) ) {
F_26 ( & V_152 -> V_58 , L_26 ) ;
return F_29 ( V_3 -> V_94 ) ;
}
V_3 -> V_89 = F_102 ( & V_152 -> V_58 , sizeof( * V_3 -> V_89 ) , V_44 ) ;
if ( ! V_3 -> V_89 )
return - V_45 ;
V_179 = V_3 -> V_17 -> V_21 [ V_3 -> V_17 -> V_18 - 1 ] . V_20 . V_23 ;
V_3 -> V_89 -> V_182 = V_183 ;
V_3 -> V_89 -> V_190 = V_191 ,
V_3 -> V_89 -> free = V_192 ,
V_3 -> V_89 -> V_193 = F_56 ,
V_3 -> V_89 -> V_194 = F_65 ,
V_3 -> V_89 -> V_195 = F_58 ,
V_3 -> V_89 -> V_196 = F_63 ,
V_3 -> V_89 -> V_197 = F_67 ,
V_3 -> V_89 -> V_198 = F_68 ,
V_3 -> V_89 -> V_199 = 3 ,
V_3 -> V_89 -> V_200 = false ,
V_3 -> V_89 -> V_104 = F_119 ( V_179 , V_103 ) -
V_3 -> V_17 -> V_76 ;
V_3 -> V_89 -> V_111 = F_117 ( & V_152 -> V_58 ) ;
V_3 -> V_89 -> V_110 = & V_152 -> V_58 ;
V_3 -> V_89 -> V_90 = V_3 -> V_17 -> V_76 ;
V_38 = F_120 ( V_3 -> V_89 , V_3 ) ;
if ( V_38 )
return V_38 ;
for ( V_5 = 0 ; V_5 < V_3 -> V_17 -> V_18 ; V_5 ++ ) {
const struct V_19 * V_20 = V_3 -> V_17 -> V_21 + V_5 ;
V_38 = F_121 ( V_3 -> V_89 , F_117 ( & V_152 -> V_58 ) ,
V_20 -> V_20 . V_23 - V_3 -> V_17 -> V_76 ,
V_20 -> V_20 . V_23 , 1 ) ;
if ( V_38 )
goto V_201;
}
V_156 = F_107 ( & V_152 -> V_58 , NULL ) ;
if ( F_28 ( V_156 ) ) {
V_38 = F_29 ( V_156 ) ;
goto V_201;
}
V_38 = F_122 ( V_156 ) ;
if ( V_38 )
goto V_201;
V_3 -> V_144 = F_116 ( & V_152 -> V_58 ,
V_3 -> V_17 -> V_147 ,
sizeof( * V_3 -> V_144 ) ,
V_44 ) ;
if ( ! V_3 -> V_144 ) {
V_38 = - V_45 ;
goto V_202;
}
for ( V_5 = 0 ; V_5 < V_3 -> V_17 -> V_147 ; V_5 ++ ) {
V_3 -> V_144 [ V_5 ] = F_123 ( V_152 , V_5 ) ;
if ( V_3 -> V_144 [ V_5 ] < 0 ) {
V_38 = V_3 -> V_144 [ V_5 ] ;
goto V_202;
}
}
V_3 -> V_112 = F_124 ( V_28 ,
V_3 -> V_17 -> V_147 * V_109 ,
& V_203 ,
V_3 ) ;
if ( ! V_3 -> V_112 ) {
F_26 ( & V_152 -> V_58 , L_27 ) ;
V_38 = - V_45 ;
goto V_202;
}
for ( V_5 = 0 ; V_5 < ( V_3 -> V_17 -> V_147 * V_109 ) ; V_5 ++ ) {
int V_204 = F_125 ( V_3 -> V_112 , V_5 ) ;
F_126 ( V_204 , & V_132 ,
V_133 ) ;
F_127 ( V_204 , V_3 ) ;
}
for ( V_5 = 0 ; V_5 < V_3 -> V_17 -> V_147 ; V_5 ++ ) {
F_46 ( 0 , V_3 -> V_77 + F_128 ( V_5 ,
V_3 -> V_17 -> V_117 ) ) ;
F_46 ( 0xffffffff ,
V_3 -> V_77 + F_94 ( V_5 ,
V_3 -> V_17 -> V_117 ) ) ;
F_129 ( V_3 -> V_144 [ V_5 ] ,
F_90 ,
V_3 ) ;
}
F_105 ( V_3 , V_28 ) ;
F_130 ( & V_152 -> V_58 , L_28 ) ;
return 0 ;
V_202:
F_131 ( V_156 ) ;
V_201:
F_132 ( V_3 -> V_89 ) ;
return V_38 ;
}
