static int F_1 ( enum V_1 V_2 , int * V_3 , T_1 V_4 )
{
switch ( V_2 ) {
case V_5 :
if ( V_4 & V_6 )
* V_3 = 0 ;
else
* V_3 = 1 ;
break;
case V_7 :
if ( V_4 & V_8 )
return - V_9 ;
break;
case V_10 :
if ( V_4 & V_8 )
* V_3 = 1 ;
else
return - V_9 ;
break;
default:
return - V_11 ;
}
return 0 ;
}
static int F_2 ( enum V_1 V_2 , int * V_3 , T_1 V_4 ,
unsigned V_12 )
{
T_2 V_13 ;
if ( V_12 == V_14 )
V_13 = V_15 ;
else
V_13 = V_16 ;
switch ( V_2 ) {
case V_17 :
if ( V_4 & ( V_18 << V_13 ) )
* V_3 = 1 ;
else
return - V_9 ;
break;
case V_19 :
if ( V_4 & ( V_20 << V_13 ) )
* V_3 = 1 ;
else
* V_3 = 0 ;
break;
case V_21 :
if ( V_4 & ( V_22 << V_13 ) )
* V_3 = 3 ;
else
* V_3 = 50 ;
break;
case V_23 :
if ( V_4 & ( V_24 << V_13 ) )
return - V_9 ;
else
* V_3 = 1 ;
break;
default:
return - V_11 ;
}
return 0 ;
}
static int F_3 ( struct V_25 * V_26 , unsigned V_12 )
{
struct V_27 * V_28 ;
V_28 = F_4 ( V_26 , V_12 ) ;
if ( ! V_28 )
return - V_9 ;
return V_12 - V_28 -> V_29 + V_28 -> V_30 ;
}
static int F_5 ( void T_3 * V_31 , T_1 V_32 , int * V_3 )
{
T_1 V_33 ;
int V_34 ;
V_33 = F_6 ( V_31 ) ;
for ( V_34 = 0 ; V_34 < V_35 ; V_34 ++ ) {
if ( ( V_33 & V_36 ) == V_32 )
return 0 ;
V_33 >>= V_37 ;
* V_3 += 1 ;
}
return - V_9 ;
}
static T_1 F_7 ( int V_38 )
{
unsigned int V_39 , V_40 ;
V_39 = V_38 / V_41 ;
V_40 = V_38 % V_41 ;
return V_40 | ( V_39 << V_42 ) ;
}
static int F_8 ( struct V_25 * V_26 ,
int * V_3 , unsigned V_12 )
{
struct V_43 * V_44 = F_9 ( V_26 ) ;
int V_38 , V_45 ;
T_1 V_32 ;
V_38 = F_3 ( V_26 , V_12 ) ;
if ( V_38 < 0 )
return - V_11 ;
V_32 = F_7 ( V_38 ) ;
* V_3 = 0 ;
V_45 = F_5 ( V_44 -> V_30 + V_46 , V_32 , V_3 ) ;
if ( V_45 == 0 )
return V_45 ;
return F_5 ( V_44 -> V_30 + V_47 , V_32 , V_3 ) ;
}
static int F_10 ( struct V_25 * V_26 , unsigned V_2 ,
int * V_3 , T_1 V_4 , unsigned V_12 ,
struct V_48 * V_49 )
{
switch ( V_2 ) {
case V_7 :
if ( ( ! ( V_4 & V_50 ) ) && ( V_4 & V_51 ) )
;
else
return - V_9 ;
break;
case V_52 :
if ( V_4 & V_51 )
return - V_9 ;
else
* V_3 = 1 ;
break;
case V_10 :
if ( V_4 & V_50 )
* V_3 = 1 ;
else
return - V_9 ;
break;
case V_17 :
if ( V_4 & V_53 )
* V_3 = 1 ;
else
return - V_9 ;
break;
case V_19 :
if ( V_49 -> type == V_54 )
return - V_11 ;
if ( V_4 & V_55 )
* V_3 = 1 ;
else
* V_3 = 0 ;
break;
case V_23 :
if ( V_4 & V_56 )
return - V_9 ;
else
* V_3 = 1 ;
break;
case V_57 :
if ( V_49 -> type != V_54 )
return - V_11 ;
* V_3 = ( V_4 & V_58 ) >> V_59 ;
switch ( * V_3 ) {
case 3 : * V_3 += 5 ;
case 2 : * V_3 += 5 ;
case 1 : * V_3 += 3 ;
case 0 : * V_3 += 4 ;
}
break;
case V_60 :
return F_8 ( V_26 , V_3 , V_12 ) ;
default:
return - V_11 ;
}
return 0 ;
}
static struct V_48 * F_11 ( unsigned V_12 )
{
int V_34 ;
for ( V_34 = 0 ; V_34 < F_12 ( V_61 ) ; V_34 ++ ) {
if ( V_61 [ V_34 ] . V_62 == V_12 )
return V_61 [ V_34 ] . V_63 ;
}
return NULL ;
}
static int F_13 ( struct V_25 * V_26 , unsigned V_12 ,
unsigned long * V_64 )
{
struct V_43 * V_44 = F_9 ( V_26 ) ;
enum V_1 V_2 = F_14 ( * V_64 ) ;
struct V_48 * V_49 ;
int V_45 , V_3 = 0 ;
T_1 V_4 ;
V_49 = F_11 ( V_12 ) ;
if ( ! V_49 )
return - V_9 ;
V_4 = F_6 ( V_44 -> V_30 + V_49 -> V_65 ) ;
if ( V_49 -> type == V_66 )
V_45 = F_2 ( V_2 , & V_3 , V_4 , V_12 ) ;
else if ( V_49 -> type == V_67 )
V_45 = F_1 ( V_2 , & V_3 , V_4 ) ;
else
V_45 = F_10 ( V_26 , V_2 , & V_3 , V_4 , V_12 , V_49 ) ;
if ( V_45 < 0 )
return V_45 ;
* V_64 = F_15 ( V_2 , ( V_68 ) V_3 ) ;
return 0 ;
}
static int F_16 ( struct V_25 * V_26 ,
enum V_1 V_2 ,
T_1 V_69 , T_1 * V_4 )
{
switch ( V_2 ) {
case V_5 :
if ( V_69 )
* V_4 &= ~ V_6 ;
else
* V_4 |= V_6 ;
break;
case V_7 :
* V_4 &= ~ V_8 ;
break;
case V_10 :
* V_4 |= V_8 ;
break;
default:
F_17 ( V_26 -> V_70 , L_1 ) ;
return - V_11 ;
}
return 0 ;
}
static int F_18 ( struct V_25 * V_26 ,
enum V_1 V_2 ,
T_1 V_69 , T_1 * V_4 ,
unsigned V_12 )
{
T_2 V_13 ;
if ( V_12 == V_14 )
V_13 = V_15 ;
else
V_13 = V_16 ;
switch ( V_2 ) {
case V_17 :
if ( V_69 )
* V_4 |= ( V_18 << V_13 ) ;
else
* V_4 &= ~ ( V_18 << V_13 ) ;
break;
case V_19 :
if ( V_69 )
* V_4 |= ( V_20 << V_13 ) ;
else
* V_4 &= ~ ( V_20 << V_13 ) ;
break;
case V_21 :
if ( V_69 == 3 )
* V_4 |= ( V_22 << V_13 ) ;
else if ( V_69 == 50 )
* V_4 &= ~ ( V_22 << V_13 ) ;
else
return - V_11 ;
break;
case V_23 :
if ( V_69 )
* V_4 &= ~ ( V_24 << V_13 ) ;
else
* V_4 |= ( V_24 << V_13 ) ;
break;
default:
F_17 ( V_26 -> V_70 , L_1 ) ;
return - V_11 ;
}
return 0 ;
}
static int F_19 ( struct V_25 * V_26 ,
T_1 V_69 , unsigned V_12 )
{
struct V_43 * V_44 = F_9 ( V_26 ) ;
T_1 V_32 , V_33 , V_71 = V_46 ;
int V_38 ;
if ( V_69 >= V_72 )
return - V_9 ;
V_38 = F_3 ( V_26 , V_12 ) ;
if ( V_38 < 0 )
return - V_11 ;
V_32 = F_7 ( V_38 ) ;
V_71 += ( V_69 / V_35 ) * sizeof( T_1 ) ;
V_33 = F_6 ( V_44 -> V_30 + V_71 ) ;
V_33 &= ~ F_20 ( V_36 , V_69 ) ;
V_33 |= F_20 ( V_32 , V_69 ) ;
F_21 ( V_33 , V_44 -> V_30 + V_71 ) ;
return 0 ;
}
static int F_22 ( struct V_25 * V_26 , unsigned V_2 ,
T_1 V_69 , T_1 * V_4 , unsigned V_12 ,
struct V_48 * V_49 )
{
switch ( V_2 ) {
case V_7 :
* V_4 &= ~ V_50 ;
* V_4 |= V_51 ;
break;
case V_52 :
* V_4 &= ~ V_51 ;
break;
case V_10 :
* V_4 |= V_50 ;
break;
case V_17 :
if ( V_69 )
* V_4 |= V_53 ;
else
* V_4 &= ~ V_53 ;
break;
case V_19 :
if ( V_49 -> type == V_54 ) {
F_17 ( V_26 -> V_70 , L_2 ) ;
return - V_11 ;
}
if ( V_69 == 0 )
* V_4 &= ~ V_55 ;
else
* V_4 |= V_55 ;
break;
case V_23 :
if ( V_69 )
* V_4 &= ~ V_56 ;
else
* V_4 |= V_56 ;
break;
case V_57 :
if ( V_49 -> type != V_54 ) {
F_17 ( V_26 -> V_70 , L_3 ) ;
return - V_11 ;
}
* V_4 &= ~ V_58 ;
switch ( V_69 ) {
case 20 : V_69 -= 5 ;
case 14 : V_69 -= 5 ;
case 8 : V_69 -= 3 ;
case 4 : V_69 -= 4 ;
break;
default:
F_17 ( V_26 -> V_70 , L_4 , V_69 ) ;
return - V_11 ;
}
* V_4 |= V_69 << V_59 ;
break;
case V_60 :
return F_19 ( V_26 , V_69 , V_12 ) ;
default:
F_17 ( V_26 -> V_70 , L_1 ) ;
return - V_11 ;
}
return 0 ;
}
static int F_23 ( struct V_25 * V_26 , unsigned V_12 ,
unsigned long * V_73 , unsigned V_74 )
{
struct V_43 * V_44 = F_9 ( V_26 ) ;
struct V_48 * V_49 ;
enum V_1 V_2 ;
T_1 V_69 ;
T_1 V_4 ;
int V_45 ;
int V_34 ;
V_49 = F_11 ( V_12 ) ;
if ( ! V_49 )
return - V_9 ;
V_4 = F_6 ( V_44 -> V_30 + V_49 -> V_65 ) ;
for ( V_34 = 0 ; V_34 < V_74 ; V_34 ++ ) {
V_2 = F_14 ( V_73 [ V_34 ] ) ;
V_69 = F_24 ( V_73 [ V_34 ] ) ;
if ( V_49 -> type == V_66 )
V_45 = F_18 ( V_26 , V_2 , V_69 , & V_4 , V_12 ) ;
else if ( V_49 -> type == V_67 )
V_45 = F_16 ( V_26 , V_2 , V_69 , & V_4 ) ;
else
V_45 = F_22 ( V_26 , V_2 , V_69 , & V_4 , V_12 , V_49 ) ;
if ( V_45 )
return V_45 ;
}
F_21 ( V_4 , V_44 -> V_30 + V_49 -> V_65 ) ;
return 0 ;
}
static int F_25 ( struct V_25 * V_26 )
{
return F_12 ( V_75 ) ;
}
static const char * F_26 ( struct V_25 * V_26 ,
unsigned V_76 )
{
return V_75 [ V_76 ] ;
}
static int F_27 ( struct V_25 * V_26 ,
unsigned V_76 ,
const char * const * * V_77 ,
unsigned * const V_78 )
{
struct V_43 * V_44 = F_9 ( V_26 ) ;
* V_77 = V_44 -> V_79 [ V_76 ] . V_77 ;
* V_78 = V_44 -> V_79 [ V_76 ] . V_80 ;
return 0 ;
}
static int F_28 ( struct V_25 * V_26 , unsigned V_76 ,
unsigned V_81 )
{
struct V_43 * V_44 = F_9 ( V_26 ) ;
struct V_48 * V_12 = V_61 [ V_81 ] . V_63 ;
int V_79 ;
T_1 V_4 ;
if ( V_12 -> type == V_67 ) {
if ( V_76 == V_82 )
return 0 ;
goto V_83;
}
if ( V_12 -> type == V_66 ) {
if ( V_76 == V_84 )
return 0 ;
goto V_83;
}
if ( V_76 == V_85 && ( V_12 -> V_86 & V_87 ) ) {
T_1 V_65 ;
F_21 ( V_88 , V_44 -> V_30 + V_12 -> V_65 ) ;
if ( F_29 ( V_12 -> V_86 ) == 0 )
V_65 = V_89 ;
else
V_65 = V_90 ;
V_4 = F_6 ( V_44 -> V_30 + V_65 ) ;
V_4 |= V_12 -> V_86 & V_91 ;
F_21 ( V_4 , V_44 -> V_30 + V_65 ) ;
return 0 ;
}
if ( V_76 == V_92 && ( V_12 -> V_86 & V_87 ) ) {
F_21 ( V_88 , V_44 -> V_30 + V_12 -> V_65 ) ;
V_4 = F_6 ( V_44 -> V_30 + V_93 ) ;
V_4 |= V_94 ;
F_21 ( V_4 , V_44 -> V_30 + V_93 ) ;
return 0 ;
}
for ( V_79 = 0 ; V_79 < V_95 ; V_79 ++ ) {
if ( V_76 == V_12 -> V_96 [ V_79 ] )
break;
}
if ( V_79 >= V_95 )
goto V_83;
V_4 = F_6 ( V_44 -> V_30 + V_12 -> V_65 ) ;
V_4 &= ~ V_97 ;
F_21 ( V_4 | V_79 , V_44 -> V_30 + V_12 -> V_65 ) ;
return 0 ;
V_83:
F_17 ( V_26 -> V_70 , L_5 , V_61 [ V_81 ] . V_98 ,
V_75 [ V_76 ] ) ;
return - V_9 ;
}
static int F_30 ( struct V_25 * V_26 )
{
return F_12 ( V_61 ) ;
}
static const char * F_31 ( struct V_25 * V_26 ,
unsigned V_81 )
{
return V_61 [ V_81 ] . V_98 ;
}
static int F_32 ( struct V_25 * V_26 ,
unsigned V_81 ,
const unsigned * * V_99 ,
unsigned * V_100 )
{
* V_99 = & V_61 [ V_81 ] . V_62 ;
* V_100 = 1 ;
return 0 ;
}
static bool F_33 ( unsigned V_12 , unsigned V_76 )
{
struct V_48 * V_101 = V_61 [ V_12 ] . V_63 ;
int V_34 ;
if ( V_76 == V_92 && V_101 -> V_86 == V_102 )
return true ;
if ( V_76 == V_85 && V_101 -> V_86 )
return true ;
if ( V_76 == V_84 && V_101 -> type == V_66 )
return true ;
if ( V_76 == V_82 && V_101 -> type == V_67 )
return true ;
for ( V_34 = 0 ; V_34 < V_95 ; V_34 ++ ) {
if ( V_76 == V_101 -> V_96 [ V_34 ] )
return true ;
}
return false ;
}
static int F_34 ( struct V_103 * V_70 ,
struct V_43 * V_44 )
{
V_68 V_99 [ F_12 ( V_61 ) ] ;
int V_79 , V_80 , V_34 ;
for ( V_79 = 0 ; V_79 < V_104 ; V_79 ++ ) {
for ( V_80 = 0 , V_34 = 0 ; V_34 < F_12 ( V_61 ) ; V_34 ++ ) {
if ( F_33 ( V_34 , V_79 ) )
V_99 [ V_80 ++ ] = V_34 ;
}
V_44 -> V_79 [ V_79 ] . V_80 = V_80 ;
V_44 -> V_79 [ V_79 ] . V_77 = F_35 ( V_70 , V_80 *
sizeof( char * ) , V_105 ) ;
if ( ! V_44 -> V_79 [ V_79 ] . V_77 )
return - V_106 ;
for ( V_34 = 0 ; V_34 < V_80 ; V_34 ++ )
V_44 -> V_79 [ V_79 ] . V_77 [ V_34 ] = V_61 [ V_99 [ V_34 ] ] . V_98 ;
}
return 0 ;
}
static int F_36 ( struct V_107 * V_108 )
{
struct V_43 * V_44 ;
struct V_109 * V_110 ;
int V_45 ;
V_44 = F_35 ( & V_108 -> V_70 , sizeof( * V_44 ) , V_105 ) ;
if ( ! V_44 )
return - V_106 ;
V_110 = F_37 ( V_108 , V_111 , 0 ) ;
V_44 -> V_30 = F_38 ( & V_108 -> V_70 , V_110 ) ;
if ( F_39 ( V_44 -> V_30 ) )
return F_40 ( V_44 -> V_30 ) ;
V_44 -> V_112 = F_41 ( & V_108 -> V_70 , NULL ) ;
if ( F_39 ( V_44 -> V_112 ) ) {
F_17 ( & V_108 -> V_70 , L_6 ) ;
return F_40 ( V_44 -> V_112 ) ;
}
V_45 = F_34 ( & V_108 -> V_70 , V_44 ) ;
if ( V_45 ) {
F_17 ( & V_108 -> V_70 , L_7 ) ;
return V_45 ;
}
V_45 = F_42 ( V_44 -> V_112 ) ;
if ( V_45 ) {
F_17 ( & V_108 -> V_70 , L_8 ) ;
return V_45 ;
}
F_43 ( V_108 , V_44 ) ;
V_44 -> V_113 = F_44 ( & V_108 -> V_70 , & V_114 , V_44 ) ;
if ( F_39 ( V_44 -> V_113 ) ) {
F_17 ( & V_108 -> V_70 , L_9 ) ;
F_45 ( V_44 -> V_112 ) ;
return F_40 ( V_44 -> V_113 ) ;
}
return 0 ;
}
