static int F_1 ( struct V_1 * V_2 ,
const char * V_3 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
int V_6 ;
for ( V_6 = 0 ; V_6 < V_5 -> V_7 ; V_6 ++ ) {
if ( ! strcmp ( V_5 -> V_8 [ V_6 ] . V_3 , V_3 ) )
return V_5 -> V_8 [ V_6 ] . V_9 ;
}
return - V_10 ;
}
static struct V_11 *
F_2 ( struct V_1 * V_2 , unsigned int V_12 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
struct V_11 * V_13 = NULL ;
int V_6 ;
for ( V_6 = 0 ; V_6 < V_5 -> V_7 ; V_6 ++ ) {
if ( V_5 -> V_8 [ V_6 ] . V_9 == V_12 ) {
V_13 = & V_5 -> V_8 [ V_6 ] ;
break;
}
}
return V_13 ;
}
static const struct V_14 *
F_3 ( struct V_1 * V_2 ,
const char * V_3 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
const struct V_14 * V_15 = NULL ;
int V_6 ;
for ( V_6 = 0 ; V_6 < V_5 -> V_16 ; V_6 ++ ) {
if ( ! strcmp ( V_5 -> V_17 [ V_6 ] . V_3 , V_3 ) ) {
V_15 = & V_5 -> V_17 [ V_6 ] ;
break;
}
}
return V_15 ;
}
static int F_4 ( struct V_18 * V_19 )
{
struct V_1 * V_20 = F_5 ( V_19 ) ;
struct V_4 * V_5 = V_20 -> V_5 ;
return V_5 -> V_16 ;
}
static const char * F_6 ( struct V_18 * V_19 ,
unsigned int V_21 )
{
struct V_1 * V_20 = F_5 ( V_19 ) ;
struct V_4 * V_5 = V_20 -> V_5 ;
return V_5 -> V_17 [ V_21 ] . V_3 ;
}
static int F_7 ( struct V_18 * V_19 ,
unsigned int V_21 ,
const unsigned int * * V_8 ,
unsigned int * V_7 )
{
struct V_1 * V_20 = F_5 ( V_19 ) ;
struct V_4 * V_5 = V_20 -> V_5 ;
if ( V_21 >= V_5 -> V_16 )
return - V_22 ;
* V_8 = V_5 -> V_17 [ V_21 ] . V_8 ;
* V_7 = V_5 -> V_17 [ V_21 ] . V_7 ;
return 0 ;
}
static int F_8 ( struct V_18 * V_19 ,
struct V_23 * V_24 ,
struct V_25 * * V_26 ,
unsigned int * V_27 )
{
struct V_1 * V_20 = F_5 ( V_19 ) ;
const struct V_14 * V_15 ;
unsigned long * V_28 = NULL ;
unsigned int V_29 = 0 ;
unsigned int V_30 = 0 ;
unsigned int V_31 = 0 ;
const char * V_32 ;
enum V_33 type ;
int V_34 ;
V_15 = F_3 ( V_20 , V_24 -> V_3 ) ;
if ( ! V_15 ) {
F_9 ( V_20 -> V_35 , L_1 ,
F_10 ( V_24 ) ) ;
return - V_22 ;
}
V_34 = F_11 ( V_24 , L_2 ) ;
if ( V_34 < 0 )
return V_34 ;
if ( V_34 == 1 )
type = V_36 ;
else
type = V_37 ;
V_34 = F_12 ( V_24 , L_3 , & V_32 ) ;
if ( V_34 < 0 ) {
if ( V_34 != - V_22 )
F_9 ( V_20 -> V_35 ,
L_4 ,
F_10 ( V_24 ) ) ;
V_32 = NULL ;
}
V_34 = F_13 ( V_24 , V_19 , & V_28 ,
& V_29 ) ;
if ( V_34 < 0 ) {
F_9 ( V_20 -> V_35 , L_5 ,
F_10 ( V_24 ) ) ;
return V_34 ;
}
* V_26 = NULL ;
* V_27 = 0 ;
if ( V_32 != NULL )
V_31 ++ ;
if ( V_29 )
V_31 ++ ;
V_34 = F_14 ( V_19 , V_26 , & V_30 ,
V_27 , V_31 ) ;
if ( V_34 < 0 )
goto V_38;
if ( V_32 ) {
V_34 = F_15 ( V_19 , V_26 ,
& V_30 , V_27 ,
V_15 -> V_3 , V_32 ) ;
if ( V_34 < 0 )
goto V_38;
}
if ( V_29 ) {
const char * V_39 ;
unsigned int V_40 ;
if ( type == V_36 ) {
V_40 = V_15 -> V_8 [ 0 ] ;
V_39 = F_16 ( V_19 , V_40 ) ;
} else {
V_39 = V_15 -> V_3 ;
}
V_34 = F_17 ( V_19 , V_26 ,
& V_30 , V_27 ,
V_39 , V_28 ,
V_29 , type ) ;
}
V_38:
F_18 ( V_28 ) ;
return V_34 ;
}
static void F_19 ( struct V_18 * V_19 , struct V_41 * V_42 ,
unsigned int V_43 )
{
F_20 ( V_42 , L_6 , F_21 ( V_19 -> V_35 ) ) ;
}
static int F_22 ( struct V_18 * V_19 )
{
return V_44 ;
}
static const char * F_23 ( struct V_18 * V_19 ,
unsigned int V_21 )
{
switch ( V_21 ) {
case V_45 :
return L_7 ;
case V_46 :
return L_8 ;
case V_47 :
return L_9 ;
case V_48 :
return L_10 ;
default:
return L_11 ;
}
}
static int F_24 ( struct V_18 * V_19 ,
unsigned int V_21 ,
const char * const * * V_17 ,
unsigned int * const V_49 )
{
struct V_1 * V_20 = F_5 ( V_19 ) ;
struct V_4 * V_5 = V_20 -> V_5 ;
* V_17 = V_5 -> V_50 ;
* V_49 = V_5 -> V_16 ;
return 0 ;
}
static int F_25 ( struct V_18 * V_19 ,
unsigned int V_51 ,
unsigned int V_52 )
{
struct V_1 * V_20 = F_5 ( V_19 ) ;
struct V_4 * V_5 = V_20 -> V_5 ;
struct V_14 * V_15 = & V_5 -> V_17 [ V_52 ] ;
unsigned int V_6 , V_53 = V_15 -> V_7 ;
unsigned long V_54 ;
unsigned int V_55 = 0 ;
if ( V_52 >= V_5 -> V_16 )
return - V_22 ;
switch ( V_51 ) {
case V_45 :
V_55 &= V_56 ;
break;
case V_46 :
V_55 |= V_57 ;
break;
case V_47 :
V_55 |= V_58 ;
break;
case V_48 :
V_55 |= V_59 ;
break;
default:
break;
}
for ( V_6 = 0 ; V_6 < V_53 ; V_6 ++ ) {
unsigned int V_40 = V_15 -> V_8 [ V_6 ] ;
struct V_11 * V_13 = F_2 ( V_20 , V_40 ) ;
if ( ! V_13 || V_13 -> type != V_60 )
continue;
V_54 = F_26 ( ( void V_61 * ) V_13 -> V_54 ) ;
V_54 &= ~ V_62 ;
V_54 |= V_55 ;
F_27 ( V_54 , ( void V_61 * ) V_13 -> V_54 ) ;
}
return 0 ;
}
static int F_28 ( struct V_18 * V_19 , unsigned int V_40 ,
unsigned long * V_63 )
{
struct V_1 * V_20 = F_5 ( V_19 ) ;
struct V_11 * V_13 = F_2 ( V_20 , V_40 ) ;
unsigned int V_64 = F_29 ( * V_63 ) ;
unsigned int V_54 , V_65 ;
if ( ! V_13 )
return - V_22 ;
if ( V_13 -> type == V_66 ) {
V_54 = ( F_26 ( ( void V_61 * ) V_13 -> V_54 ) >>
V_13 -> V_67 ) & F_30 ( V_13 -> V_68 ) ;
} else {
V_54 = F_26 ( ( void V_61 * ) V_13 -> V_54 ) ;
}
if ( V_13 -> type == V_66 &&
V_64 == V_69 ) {
V_65 = V_54 ;
} else if ( V_13 -> type == V_60 ) {
switch ( V_64 ) {
case V_70 :
V_65 = ( V_54 >> V_71 ) & V_72 ;
break;
case V_73 :
V_65 = ( V_54 >> V_74 ) & V_75 ;
break;
case V_76 :
V_65 = V_54 & V_77 ;
break;
case V_78 :
V_65 = 0 ;
break;
default:
return - V_79 ;
}
} else if ( V_13 -> type == V_80 ) {
switch ( V_64 ) {
case V_81 :
V_65 = ( V_54 >> V_82 ) &
V_83 ;
break;
case V_84 :
V_65 = ( ( V_54 >> V_85 ) &
V_86 ) << 16 ;
V_65 |= ( V_54 >> V_87 ) & V_88 ;
break;
case V_89 :
V_65 = ( V_54 >> V_90 ) & V_91 ;
break;
case V_92 :
V_65 = ( ( V_54 >> V_93 ) &
V_94 ) << 16 ;
V_65 |= ( V_54 >> V_95 ) & V_96 ;
break;
case V_78 :
V_65 = 0 ;
break;
default:
return - V_79 ;
}
} else {
return - V_79 ;
}
* V_63 = F_31 ( V_64 , V_65 ) ;
return 0 ;
}
static unsigned int F_32 ( unsigned int V_97 )
{
unsigned int V_55 = 0 ;
switch ( V_97 ) {
case 2 :
break;
case 4 :
V_55 |= F_33 ( 19 ) ;
break;
case 6 :
V_55 |= F_33 ( 20 ) ;
break;
case 8 :
V_55 |= F_33 ( 19 ) | F_33 ( 20 ) ;
break;
case 10 :
V_55 |= F_33 ( 21 ) ;
break;
case 12 :
V_55 |= F_33 ( 21 ) | F_33 ( 19 ) ;
break;
case 14 :
V_55 |= F_33 ( 21 ) | F_33 ( 20 ) ;
break;
case 16 :
V_55 |= F_33 ( 19 ) | F_33 ( 20 ) | F_33 ( 21 ) ;
break;
case 20 :
V_55 |= F_33 ( 22 ) ;
break;
case 21 :
V_55 |= F_33 ( 22 ) | F_33 ( 19 ) ;
break;
case 24 :
V_55 |= F_33 ( 22 ) | F_33 ( 20 ) ;
break;
case 25 :
V_55 |= F_33 ( 22 ) | F_33 ( 20 ) | F_33 ( 19 ) ;
break;
case 27 :
V_55 |= F_33 ( 22 ) | F_33 ( 21 ) ;
break;
case 29 :
V_55 |= F_33 ( 22 ) | F_33 ( 21 ) | F_33 ( 19 ) ;
break;
case 31 :
V_55 |= F_33 ( 22 ) | F_33 ( 21 ) | F_33 ( 20 ) ;
break;
case 33 :
V_55 |= F_33 ( 22 ) | F_33 ( 21 ) | F_33 ( 20 ) | F_33 ( 19 ) ;
break;
default:
break;
}
return V_55 ;
}
static bool F_34 ( unsigned long * V_28 ,
unsigned int V_29 )
{
unsigned int V_64 ;
int V_6 ;
for ( V_6 = 0 ; V_6 < V_29 ; V_6 ++ ) {
V_64 = F_29 ( V_28 [ V_6 ] ) ;
if ( V_64 == V_78 )
return true ;
}
return false ;
}
static int F_35 ( struct V_18 * V_19 , unsigned int V_40 ,
unsigned long * V_28 , unsigned int V_29 )
{
struct V_1 * V_20 = F_5 ( V_19 ) ;
struct V_11 * V_13 = F_2 ( V_20 , V_40 ) ;
bool V_98 ;
unsigned long V_54 ;
int V_6 ;
if ( ! V_13 )
return - V_22 ;
V_98 = F_34 ( V_28 , V_29 ) ;
for ( V_6 = 0 ; V_6 < V_29 ; V_6 ++ ) {
unsigned int V_64 , V_65 , V_99 , V_100 , V_55 ;
V_64 = F_29 ( V_28 [ V_6 ] ) ;
V_65 = F_36 ( V_28 [ V_6 ] ) ;
V_55 = 0 ;
V_99 = 0 ;
V_100 = 0 ;
if ( V_13 -> type == V_66 &&
V_64 == V_69 ) {
V_55 = V_65 ;
} else if ( V_13 -> type == V_60 ) {
switch ( V_64 ) {
case V_70 :
if ( V_65 & V_101 )
V_55 |= V_102 ;
if ( V_65 & V_103 )
V_55 |= V_104 ;
if ( V_65 & V_105 )
V_55 |= V_106 ;
if ( V_65 & V_107 )
V_55 |= V_108 ;
V_100 = V_72 ;
V_99 = V_71 ;
break;
case V_73 :
if ( V_98 == true ) {
if ( V_65 > 0 )
V_55 |= V_109 ;
else
V_55 &= ~ V_109 ;
V_100 = V_75 ;
V_99 = V_74 ;
}
break;
case V_76 :
if ( V_98 == true ) {
V_55 |= V_110 ;
V_100 = V_77 ;
V_99 = V_111 ;
}
break;
case V_78 :
continue;
default:
return - V_79 ;
}
} else if ( V_13 -> type == V_80 ) {
switch ( V_64 ) {
case V_81 :
if ( V_65 < 2 || V_65 > 60 )
return - V_22 ;
V_55 = F_32 ( V_65 ) ;
V_100 = V_83 ;
V_99 = V_82 ;
break;
case V_84 :
if ( V_98 == true ) {
V_55 |= V_112 ;
V_100 = V_86 ;
V_99 = V_85 ;
} else {
V_55 |= V_113 ;
V_100 = V_88 ;
V_99 = V_87 ;
}
break;
case V_89 :
if ( V_65 > 0 )
V_55 |= V_114 ;
else
V_55 &= ~ V_114 ;
V_100 = V_91 ;
V_99 = V_90 ;
break;
case V_92 :
if ( V_98 == true ) {
V_55 |= V_115 ;
V_100 = V_94 ;
V_99 = V_93 ;
} else {
if ( V_65 == 20000 )
V_55 |= V_116 ;
else if ( V_65 == 4700 )
V_55 |= V_117 ;
V_100 = V_96 ;
V_99 = V_95 ;
}
break;
case V_78 :
continue;
default:
return - V_79 ;
}
} else {
return - V_79 ;
}
if ( V_13 -> type == V_66 ) {
V_54 = F_26 ( ( void V_61 * ) V_13 -> V_54 ) ;
V_54 &= ~ ( F_30 ( V_13 -> V_68 )
<< V_13 -> V_67 ) ;
V_54 |= ( V_55 & F_30 ( V_13 -> V_68 ) )
<< V_13 -> V_67 ;
F_27 ( V_54 , ( void V_61 * ) V_13 -> V_54 ) ;
} else {
V_54 = F_26 ( ( void V_61 * ) V_13 -> V_54 ) ;
V_54 &= ~ ( V_100 << V_99 ) ;
V_54 |= V_55 ;
F_27 ( V_54 , ( void V_61 * ) V_13 -> V_54 ) ;
}
}
return 0 ;
}
static int F_37 ( struct V_18 * V_19 ,
unsigned int V_21 , unsigned long * V_63 )
{
struct V_1 * V_20 = F_5 ( V_19 ) ;
struct V_4 * V_5 = V_20 -> V_5 ;
struct V_14 * V_15 ;
unsigned int V_40 ;
if ( V_21 >= V_5 -> V_16 )
return - V_22 ;
V_15 = & V_5 -> V_17 [ V_21 ] ;
V_40 = V_15 -> V_8 [ 0 ] ;
return F_28 ( V_19 , V_40 , V_63 ) ;
}
static int F_38 ( struct V_18 * V_19 ,
unsigned int V_21 ,
unsigned long * V_28 ,
unsigned int V_29 )
{
struct V_1 * V_20 = F_5 ( V_19 ) ;
struct V_4 * V_5 = V_20 -> V_5 ;
struct V_14 * V_15 ;
int V_34 , V_6 ;
if ( V_21 >= V_5 -> V_16 )
return - V_22 ;
V_15 = & V_5 -> V_17 [ V_21 ] ;
for ( V_6 = 0 ; V_6 < V_15 -> V_7 ; V_6 ++ ) {
unsigned int V_40 = V_15 -> V_8 [ V_6 ] ;
V_34 = F_35 ( V_19 , V_40 , V_28 , V_29 ) ;
if ( V_34 )
return V_34 ;
}
return 0 ;
}
static int F_39 ( struct V_18 * V_19 ,
unsigned int V_40 ,
unsigned long * V_63 )
{
struct V_1 * V_20 = F_5 ( V_19 ) ;
struct V_11 * V_13 = F_2 ( V_20 , V_40 ) ;
if ( ! V_13 )
return - V_22 ;
if ( V_13 -> type == V_66 ) {
* V_63 = ( F_26 ( ( void V_61 * ) V_13 -> V_54 ) >>
V_13 -> V_67 ) & F_30 ( V_13 -> V_68 ) ;
} else {
* V_63 = F_26 ( ( void V_61 * ) V_13 -> V_54 ) ;
}
return 0 ;
}
static void F_40 ( struct V_18 * V_19 ,
struct V_41 * V_42 , unsigned int V_40 )
{
unsigned long V_63 ;
int V_34 ;
V_34 = F_39 ( V_19 , V_40 , & V_63 ) ;
if ( V_34 )
return;
F_20 ( V_42 , L_12 , V_63 ) ;
}
static void F_41 ( struct V_18 * V_19 ,
struct V_41 * V_42 ,
unsigned int V_21 )
{
struct V_1 * V_20 = F_5 ( V_19 ) ;
struct V_4 * V_5 = V_20 -> V_5 ;
struct V_14 * V_15 ;
unsigned long V_63 ;
const char * V_3 ;
int V_6 , V_34 ;
if ( V_21 >= V_5 -> V_16 )
return;
V_15 = & V_5 -> V_17 [ V_21 ] ;
F_20 ( V_42 , L_13 ) ;
for ( V_6 = 0 ; V_6 < V_15 -> V_7 ; V_6 ++ , V_63 ++ ) {
unsigned int V_40 = V_15 -> V_8 [ V_6 ] ;
V_3 = F_16 ( V_19 , V_40 ) ;
V_34 = F_39 ( V_19 , V_40 , & V_63 ) ;
if ( V_34 )
return;
F_20 ( V_42 , L_14 , V_3 , V_63 ) ;
}
}
static int F_42 ( struct V_23 * V_24 ,
struct V_1 * V_2 ,
struct V_14 * V_15 )
{
struct V_118 * V_119 ;
const char * V_120 ;
int V_34 , V_6 = 0 ;
V_34 = F_11 ( V_24 , L_2 ) ;
if ( V_34 < 0 )
return V_34 ;
V_15 -> V_3 = V_24 -> V_3 ;
V_15 -> V_7 = V_34 ;
V_15 -> V_8 = F_43 ( V_2 -> V_35 , V_15 -> V_7 *
sizeof( unsigned int ) , V_121 ) ;
if ( ! V_15 -> V_8 )
return - V_122 ;
F_44 (np, L_2 , prop, pin_name) {
V_34 = F_1 ( V_2 , V_120 ) ;
if ( V_34 >= 0 )
V_15 -> V_8 [ V_6 ++ ] = V_34 ;
}
for ( V_6 = 0 ; V_6 < V_15 -> V_7 ; V_6 ++ ) {
F_45 ( V_2 -> V_35 ,
L_15 ,
V_15 -> V_3 , V_15 -> V_7 , V_15 -> V_8 [ V_6 ] ) ;
}
return 0 ;
}
static unsigned int F_46 ( struct V_23 * V_24 )
{
struct V_23 * V_123 ;
unsigned int V_124 , V_125 ;
V_124 = F_47 ( V_24 ) ;
F_48 (np, child) {
V_125 = F_47 ( V_123 ) ;
if ( V_125 > 0 )
V_124 += V_125 ;
}
return V_124 ;
}
static int F_49 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
struct V_23 * V_24 = V_2 -> V_35 -> V_126 ;
struct V_23 * V_123 , * V_127 ;
struct V_14 * V_15 ;
const char * * V_128 ;
int V_34 ;
if ( ! V_24 )
return - V_10 ;
V_5 -> V_16 = F_46 ( V_24 ) ;
if ( ! V_5 -> V_16 )
return 0 ;
V_5 -> V_17 = F_43 ( V_2 -> V_35 , V_5 -> V_16 *
sizeof( struct V_14 ) ,
V_121 ) ;
if ( ! V_5 -> V_17 )
return - V_122 ;
V_5 -> V_50 = F_43 ( V_2 -> V_35 ,
V_5 -> V_16 * sizeof( char * ) ,
V_121 ) ;
if ( ! V_5 -> V_50 )
return - V_122 ;
V_128 = V_5 -> V_50 ;
V_15 = V_5 -> V_17 ;
F_48 (np, child) {
V_34 = F_42 ( V_123 , V_2 , V_15 ) ;
if ( V_34 )
return V_34 ;
* V_128 ++ = V_15 -> V_3 ;
V_15 ++ ;
if ( F_47 ( V_123 ) > 0 ) {
F_48 (child, sub_child) {
V_34 = F_42 ( V_127 ,
V_2 , V_15 ) ;
if ( V_34 )
return V_34 ;
* V_128 ++ = V_15 -> V_3 ;
V_15 ++ ;
}
}
}
return 0 ;
}
static int F_50 ( struct V_1 * V_2 ,
struct V_129 * V_130 ,
int V_131 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
unsigned int V_132 = 0 , V_133 = 0 ;
struct V_11 * V_13 ;
int V_6 ;
V_5 -> V_7 = V_131 ;
V_5 -> V_8 = F_43 ( V_2 -> V_35 ,
V_5 -> V_7 * sizeof( struct V_11 ) ,
V_121 ) ;
if ( ! V_5 -> V_8 )
return - V_122 ;
for ( V_6 = 0 , V_13 = V_5 -> V_8 ; V_6 < V_5 -> V_7 ; V_6 ++ , V_13 ++ ) {
unsigned int V_54 ;
V_13 -> V_3 = V_130 [ V_6 ] . V_3 ;
V_13 -> type = V_130 [ V_6 ] . type ;
V_13 -> V_9 = V_130 [ V_6 ] . V_134 ;
V_54 = V_130 [ V_6 ] . V_54 ;
if ( V_13 -> type == V_66 ) {
V_13 -> V_54 = ( unsigned long ) V_2 -> V_135 +
V_136 * V_54 ;
V_13 -> V_67 = V_130 [ V_6 ] . V_67 ;
V_13 -> V_68 = V_130 [ V_6 ] . V_68 ;
V_132 ++ ;
} else if ( V_13 -> type == V_60 ) {
V_13 -> V_54 = ( unsigned long ) V_2 -> V_135 +
V_137 + V_136 *
( V_6 - V_132 ) ;
V_133 ++ ;
} else if ( V_13 -> type == V_80 ) {
V_13 -> V_54 = ( unsigned long ) V_2 -> V_135 +
V_138 + V_136 *
( V_6 - V_132 - V_133 ) ;
}
}
for ( V_6 = 0 , V_13 = V_5 -> V_8 ; V_6 < V_5 -> V_7 ; V_13 ++ , V_6 ++ ) {
F_45 ( V_2 -> V_35 , L_16
L_17 ,
V_13 -> V_3 , V_13 -> V_9 , V_13 -> type ,
V_13 -> V_67 , V_13 -> V_68 , V_13 -> V_54 ) ;
}
return 0 ;
}
int F_51 ( struct V_139 * V_140 ,
struct V_129 * V_130 ,
int V_131 )
{
struct V_1 * V_2 ;
struct V_4 * V_141 ;
struct V_142 * V_143 ;
struct V_144 * V_145 ;
int V_34 , V_6 ;
V_2 = F_43 ( & V_140 -> V_35 , sizeof( struct V_1 ) ,
V_121 ) ;
if ( ! V_2 )
return - V_122 ;
V_145 = F_52 ( V_140 , V_146 , 0 ) ;
V_2 -> V_135 = F_53 ( & V_140 -> V_35 , V_145 ) ;
if ( F_54 ( V_2 -> V_135 ) )
return F_55 ( V_2 -> V_135 ) ;
V_141 = F_43 ( & V_140 -> V_35 ,
sizeof( struct V_4 ) ,
V_121 ) ;
if ( ! V_141 )
return - V_122 ;
V_2 -> V_5 = V_141 ;
V_2 -> V_35 = & V_140 -> V_35 ;
F_56 ( V_140 , V_2 ) ;
V_34 = F_50 ( V_2 , V_130 , V_131 ) ;
if ( V_34 ) {
F_9 ( & V_140 -> V_35 , L_18 ) ;
return V_34 ;
}
V_143 = F_43 ( & V_140 -> V_35 , V_141 -> V_7 *
sizeof( struct V_142 ) ,
V_121 ) ;
if ( ! V_143 )
return - V_122 ;
for ( V_6 = 0 ; V_6 < V_141 -> V_7 ; V_6 ++ ) {
V_143 [ V_6 ] . V_9 = V_141 -> V_8 [ V_6 ] . V_9 ;
V_143 [ V_6 ] . V_3 = V_141 -> V_8 [ V_6 ] . V_3 ;
V_143 [ V_6 ] . V_147 = V_141 ;
}
V_148 . V_8 = V_143 ;
V_148 . V_3 = F_21 ( & V_140 -> V_35 ) ;
V_148 . V_7 = V_141 -> V_7 ;
V_2 -> V_20 = F_57 ( & V_148 ,
& V_140 -> V_35 , ( void * ) V_2 ) ;
if ( F_54 ( V_2 -> V_20 ) ) {
F_9 ( & V_140 -> V_35 , L_19 ) ;
return F_55 ( V_2 -> V_20 ) ;
}
V_34 = F_49 ( V_2 ) ;
if ( V_34 ) {
F_9 ( & V_140 -> V_35 , L_20 ) ;
F_58 ( V_2 -> V_20 ) ;
return V_34 ;
}
return 0 ;
}
int F_59 ( struct V_139 * V_140 )
{
struct V_1 * V_2 = F_60 ( V_140 ) ;
F_58 ( V_2 -> V_20 ) ;
return 0 ;
}
void F_61 ( struct V_139 * V_140 )
{
struct V_149 * V_150 ;
struct V_151 * V_152 ;
V_150 = F_62 ( & V_140 -> V_35 ) ;
if ( F_54 ( V_150 ) )
return;
V_152 = F_63 ( V_150 , L_21 ) ;
if ( F_54 ( V_152 ) )
return;
F_64 ( V_150 , V_152 ) ;
}
