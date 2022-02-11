static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
return V_4 -> V_5 -> V_6 ;
}
static const char * F_3 ( struct V_1 * V_2 ,
unsigned V_7 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
return V_4 -> V_5 -> V_8 [ V_7 ] . V_9 ;
}
static int F_4 ( struct V_1 * V_2 ,
unsigned V_7 ,
const unsigned * * V_10 ,
unsigned * V_11 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
* V_10 = V_4 -> V_5 -> V_8 [ V_7 ] . V_10 ;
* V_11 = V_4 -> V_5 -> V_8 [ V_7 ] . V_11 ;
return 0 ;
}
static void F_5 ( struct V_1 * V_2 ,
struct V_12 * V_13 , unsigned V_14 )
{
const struct V_15 * V_16 = & V_2 -> V_17 -> V_10 [ V_14 ] ;
const char * V_18 , * V_19 ;
switch ( F_6 ( V_16 -> V_20 ) ) {
case V_21 :
V_18 = L_1 ;
break;
case V_22 :
V_18 = L_2 ;
break;
case V_23 :
V_18 = L_3 ;
break;
default:
F_7 () ;
}
switch ( F_8 ( V_16 -> V_20 ) ) {
case V_24 :
V_19 = L_4 ;
break;
case V_25 :
V_19 = L_5 ;
break;
case V_26 :
V_19 = L_6 ;
break;
case V_27 :
V_19 = L_7 ;
break;
case V_28 :
V_19 = L_8 ;
break;
case V_29 :
V_19 = L_3 ;
break;
default:
F_7 () ;
}
F_9 ( V_13 , L_9 , V_18 , V_19 ) ;
}
static int F_10 ( struct V_1 * V_2 ,
const struct V_15 * V_16 ,
enum V_30 V_31 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
enum V_32 V_18 =
F_6 ( V_16 -> V_20 ) ;
unsigned int V_33 , V_34 , V_35 , V_36 ;
unsigned int V_37 = 1 ;
int V_38 ;
switch ( V_31 ) {
case V_39 :
if ( V_18 == V_23 )
return 0 ;
if ( V_18 == V_40 ||
V_18 == V_41 )
return - V_42 ;
V_37 = 0 ;
break;
case V_43 :
if ( V_18 == V_40 )
return 0 ;
if ( V_18 != V_21 )
return - V_42 ;
break;
case V_44 :
if ( V_18 == V_41 )
return 0 ;
if ( V_18 != V_22 )
return - V_42 ;
break;
default:
F_7 () ;
}
V_33 = F_11 ( V_16 -> V_20 ) ;
V_34 = V_45 + V_33 / 32 * 4 ;
V_35 = V_33 % 32 ;
V_38 = F_12 ( V_4 -> V_46 , V_34 , & V_36 ) ;
if ( V_38 )
return V_38 ;
V_36 = ( V_36 >> V_35 ) & 1 ;
return ( V_36 == V_37 ) ? 0 : - V_42 ;
}
static int F_13 ( struct V_1 * V_2 ,
const struct V_15 * V_16 ,
T_1 * V_47 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
enum V_48 V_19 =
F_8 ( V_16 -> V_20 ) ;
const unsigned int V_49 [] = { 4 , 8 } ;
const unsigned int V_50 [] = { 8 , 12 , 16 , 20 } ;
const unsigned int * V_51 ;
unsigned int V_52 , V_34 , V_35 , V_53 , V_54 , V_36 ;
int V_38 ;
switch ( V_19 ) {
case V_24 :
V_51 = V_49 ;
V_54 = 1 ;
break;
case V_25 :
V_51 = V_50 ;
V_54 = 2 ;
break;
case V_26 :
* V_47 = 4 ;
return 0 ;
case V_27 :
* V_47 = 5 ;
return 0 ;
case V_28 :
* V_47 = 8 ;
return 0 ;
default:
return - V_42 ;
}
V_52 = F_14 ( V_16 -> V_20 ) ;
V_52 *= V_54 ;
V_34 = ( V_54 == 2 ) ? V_55 :
V_56 ;
V_34 += V_52 / 32 * 4 ;
V_35 = V_52 % 32 ;
V_53 = ( 1U << V_54 ) - 1 ;
V_38 = F_12 ( V_4 -> V_46 , V_34 , & V_36 ) ;
if ( V_38 )
return V_38 ;
* V_47 = V_51 [ ( V_36 >> V_35 ) & V_53 ] ;
return 0 ;
}
static int F_15 ( struct V_1 * V_2 ,
const struct V_15 * V_16 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
unsigned int V_57 = F_16 ( V_16 -> V_20 ) ;
unsigned int V_36 ;
int V_38 ;
if ( V_57 == V_58 )
return 0 ;
V_38 = F_12 ( V_4 -> V_46 , V_59 , & V_36 ) ;
if ( V_38 )
return V_38 ;
return V_36 & F_17 ( V_57 ) ? 0 : - V_42 ;
}
static int F_18 ( struct V_1 * V_2 ,
unsigned V_16 ,
unsigned long * V_60 )
{
const struct V_15 * V_61 = & V_2 -> V_17 -> V_10 [ V_16 ] ;
enum V_30 V_31 = F_19 ( * V_60 ) ;
bool V_62 = false ;
T_1 V_63 ;
int V_38 ;
switch ( V_31 ) {
case V_39 :
case V_43 :
case V_44 :
V_38 = F_10 ( V_2 , V_61 , V_31 ) ;
break;
case V_64 :
V_38 = F_13 ( V_2 , V_61 , & V_63 ) ;
V_62 = true ;
break;
case V_65 :
V_38 = F_15 ( V_2 , V_61 ) ;
break;
default:
V_38 = - V_42 ;
break;
}
if ( V_38 == 0 && V_62 )
* V_60 = F_20 ( V_31 , V_63 ) ;
return V_38 ;
}
static int F_21 ( struct V_1 * V_2 ,
const struct V_15 * V_16 ,
enum V_30 V_31 ,
T_1 V_63 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
enum V_32 V_18 =
F_6 ( V_16 -> V_20 ) ;
unsigned int V_33 , V_34 , V_35 ;
unsigned int V_36 = 1 ;
switch ( V_31 ) {
case V_39 :
if ( V_18 == V_23 )
return 0 ;
if ( V_18 == V_40 ||
V_18 == V_41 ) {
F_22 ( V_2 -> V_66 ,
L_10 ,
V_16 -> V_67 , V_16 -> V_9 ) ;
return - V_42 ;
}
V_36 = 0 ;
break;
case V_43 :
if ( V_18 == V_40 && V_63 != 0 )
return 0 ;
if ( V_18 != V_21 ) {
F_22 ( V_2 -> V_66 ,
L_11 ,
V_16 -> V_67 , V_16 -> V_9 ) ;
return - V_42 ;
}
if ( V_63 == 0 ) {
F_22 ( V_2 -> V_66 , L_12 ) ;
return - V_42 ;
}
break;
case V_44 :
if ( V_18 == V_41 && V_63 != 0 )
return 0 ;
if ( V_18 != V_22 ) {
F_22 ( V_2 -> V_66 ,
L_13 ,
V_16 -> V_67 , V_16 -> V_9 ) ;
return - V_42 ;
}
if ( V_63 == 0 ) {
F_22 ( V_2 -> V_66 , L_14 ) ;
return - V_42 ;
}
break;
case V_68 :
if ( V_18 == V_23 ) {
F_22 ( V_2 -> V_66 ,
L_15 ,
V_16 -> V_67 , V_16 -> V_9 ) ;
return - V_42 ;
}
if ( V_63 == 0 )
return 0 ;
break;
default:
F_7 () ;
}
V_33 = F_11 ( V_16 -> V_20 ) ;
V_34 = V_45 + V_33 / 32 * 4 ;
V_35 = V_33 % 32 ;
return F_23 ( V_4 -> V_46 , V_34 , 1 << V_35 , V_36 << V_35 ) ;
}
static int F_24 ( struct V_1 * V_2 ,
const struct V_15 * V_16 ,
T_1 V_47 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
enum V_48 V_19 =
F_8 ( V_16 -> V_20 ) ;
const unsigned int V_49 [] = { 4 , 8 , - 1 } ;
const unsigned int V_50 [] = { 8 , 12 , 16 , 20 , - 1 } ;
const unsigned int * V_51 ;
unsigned int V_52 , V_34 , V_35 , V_53 , V_54 , V_36 ;
switch ( V_19 ) {
case V_24 :
V_51 = V_49 ;
V_54 = 1 ;
break;
case V_25 :
V_51 = V_50 ;
V_54 = 2 ;
break;
default:
F_22 ( V_2 -> V_66 ,
L_16 ,
V_16 -> V_67 , V_16 -> V_9 ) ;
return - V_42 ;
}
for ( V_36 = 0 ; V_51 [ V_36 ] > 0 ; V_36 ++ ) {
if ( V_51 [ V_36 ] > V_47 )
break;
}
if ( V_36 == 0 ) {
F_22 ( V_2 -> V_66 ,
L_17 ,
V_47 , V_16 -> V_67 , V_16 -> V_9 ) ;
return - V_42 ;
}
V_36 -- ;
V_52 = F_14 ( V_16 -> V_20 ) ;
V_52 *= V_54 ;
V_34 = ( V_54 == 2 ) ? V_55 :
V_56 ;
V_34 += V_52 / 32 * 4 ;
V_35 = V_52 % 32 ;
V_53 = ( 1U << V_54 ) - 1 ;
return F_23 ( V_4 -> V_46 , V_34 ,
V_53 << V_35 , V_36 << V_35 ) ;
}
static int F_25 ( struct V_1 * V_2 ,
const struct V_15 * V_16 ,
T_1 V_69 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
unsigned int V_57 = F_16 ( V_16 -> V_20 ) ;
if ( V_69 == 0 ) {
F_22 ( V_2 -> V_66 , L_18 ) ;
return - V_42 ;
}
if ( V_57 == V_58 )
return 0 ;
return F_23 ( V_4 -> V_46 , V_59 ,
F_17 ( V_57 ) , F_17 ( V_57 ) ) ;
}
static int F_26 ( struct V_1 * V_2 ,
unsigned V_16 ,
unsigned long * V_60 ,
unsigned V_70 )
{
const struct V_15 * V_61 = & V_2 -> V_17 -> V_10 [ V_16 ] ;
int V_71 , V_38 ;
for ( V_71 = 0 ; V_71 < V_70 ; V_71 ++ ) {
enum V_30 V_31 =
F_19 ( V_60 [ V_71 ] ) ;
T_1 V_63 = F_27 ( V_60 [ V_71 ] ) ;
switch ( V_31 ) {
case V_39 :
case V_43 :
case V_44 :
case V_68 :
V_38 = F_21 ( V_2 , V_61 ,
V_31 , V_63 ) ;
break;
case V_64 :
V_38 = F_24 ( V_2 , V_61 ,
V_63 ) ;
break;
case V_65 :
V_38 = F_25 ( V_2 ,
V_61 , V_63 ) ;
break;
default:
F_22 ( V_2 -> V_66 ,
L_19 ,
V_31 ) ;
return - V_42 ;
}
if ( V_38 )
return V_38 ;
}
return 0 ;
}
static int F_28 ( struct V_1 * V_2 ,
unsigned V_7 ,
unsigned long * V_60 ,
unsigned V_70 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
const unsigned * V_10 = V_4 -> V_5 -> V_8 [ V_7 ] . V_10 ;
unsigned V_11 = V_4 -> V_5 -> V_8 [ V_7 ] . V_11 ;
int V_71 , V_38 ;
for ( V_71 = 0 ; V_71 < V_11 ; V_71 ++ ) {
V_38 = F_26 ( V_2 , V_10 [ V_71 ] ,
V_60 , V_70 ) ;
if ( V_38 )
return V_38 ;
}
return 0 ;
}
static int F_29 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
return V_4 -> V_5 -> V_72 ;
}
static const char * F_30 ( struct V_1 * V_2 ,
unsigned V_7 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
return V_4 -> V_5 -> V_73 [ V_7 ] . V_9 ;
}
static int F_31 ( struct V_1 * V_2 ,
unsigned V_7 ,
const char * const * * V_8 ,
unsigned * V_74 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
* V_8 = V_4 -> V_5 -> V_73 [ V_7 ] . V_8 ;
* V_74 = V_4 -> V_5 -> V_73 [ V_7 ] . V_74 ;
return 0 ;
}
static int F_32 ( struct V_1 * V_2 , unsigned V_16 ,
unsigned V_75 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
unsigned V_76 = V_4 -> V_5 -> V_76 ;
unsigned V_77 = V_4 -> V_5 -> V_77 ;
unsigned V_34 , V_78 , V_35 , V_53 ;
int V_38 ;
V_38 = F_25 ( V_2 ,
& V_2 -> V_17 -> V_10 [ V_16 ] , 1 ) ;
if ( V_38 )
return V_38 ;
V_34 = V_79 + V_16 * V_76 / 32 * V_77 ;
V_78 = V_34 + V_77 ;
V_35 = V_16 * V_76 % 32 ;
V_53 = ( 1U << V_76 ) - 1 ;
for (; V_34 < V_78 ; V_34 += 4 ) {
V_38 = F_23 ( V_4 -> V_46 , V_34 ,
V_53 << V_35 , V_75 << V_35 ) ;
if ( V_38 )
return V_38 ;
V_75 >>= V_76 ;
}
if ( V_4 -> V_5 -> V_80 ) {
V_38 = F_33 ( V_4 -> V_46 ,
V_81 , 1 ) ;
if ( V_38 )
return V_38 ;
}
return 0 ;
}
static int F_34 ( struct V_1 * V_2 ,
unsigned V_82 ,
unsigned V_83 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
const struct V_84 * V_85 =
& V_4 -> V_5 -> V_8 [ V_83 ] ;
int V_71 ;
int V_38 ;
for ( V_71 = 0 ; V_71 < V_85 -> V_11 ; V_71 ++ ) {
V_38 = F_32 ( V_2 , V_85 -> V_10 [ V_71 ] ,
V_85 -> V_86 [ V_71 ] ) ;
if ( V_38 )
return V_38 ;
}
return 0 ;
}
static int F_35 ( struct V_1 * V_2 ,
struct V_87 * V_88 ,
unsigned V_14 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
const struct V_84 * V_8 = V_4 -> V_5 -> V_8 ;
int V_6 = V_4 -> V_5 -> V_6 ;
enum V_89 V_90 ;
int V_71 , V_91 ;
if ( strstr ( V_88 -> V_9 , L_20 ) )
V_90 = V_92 ;
else
V_90 = V_93 ;
for ( V_71 = 0 ; V_71 < V_6 ; V_71 ++ ) {
if ( V_8 [ V_71 ] . V_90 != V_90 )
continue;
for ( V_91 = 0 ; V_91 < V_8 [ V_71 ] . V_11 ; V_91 ++ )
if ( V_8 [ V_71 ] . V_10 [ V_91 ] == V_14 )
goto V_94;
}
F_22 ( V_2 -> V_66 , L_21 , V_14 ) ;
return - V_42 ;
V_94:
return F_32 ( V_2 , V_14 , V_8 [ V_71 ] . V_86 [ V_91 ] ) ;
}
int F_36 ( struct V_95 * V_96 ,
struct V_97 * V_17 ,
struct V_98 * V_5 )
{
struct V_99 * V_66 = & V_96 -> V_66 ;
struct V_3 * V_4 ;
if ( ! V_5 ||
! V_5 -> V_8 ||
! V_5 -> V_6 ||
! V_5 -> V_73 ||
! V_5 -> V_72 ||
! V_5 -> V_76 ||
! V_5 -> V_77 ) {
F_22 ( V_66 , L_22 ) ;
return - V_42 ;
}
V_4 = F_37 ( V_66 , sizeof( * V_4 ) , V_100 ) ;
if ( ! V_4 )
return - V_101 ;
V_4 -> V_46 = F_38 ( V_66 -> V_102 ) ;
if ( F_39 ( V_4 -> V_46 ) ) {
F_22 ( V_66 , L_23 ) ;
return F_40 ( V_4 -> V_46 ) ;
}
V_4 -> V_5 = V_5 ;
V_17 -> V_103 = & V_104 ;
V_17 -> V_105 = & V_106 ;
V_17 -> V_107 = & V_108 ;
V_4 -> V_2 = F_41 ( V_17 , V_66 , V_4 ) ;
if ( F_39 ( V_4 -> V_2 ) ) {
F_22 ( V_66 , L_24 ) ;
return F_40 ( V_4 -> V_2 ) ;
}
F_42 ( V_96 , V_4 ) ;
return 0 ;
}
int F_43 ( struct V_95 * V_96 )
{
struct V_3 * V_4 = F_44 ( V_96 ) ;
F_45 ( V_4 -> V_2 ) ;
return 0 ;
}
