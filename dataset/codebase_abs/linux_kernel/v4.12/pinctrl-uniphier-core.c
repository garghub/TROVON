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
const struct V_15 * V_16 = F_6 ( V_2 , V_14 ) ;
const char * V_17 , * V_18 ;
switch ( F_7 ( V_16 -> V_19 ) ) {
case V_20 :
V_17 = L_1 ;
break;
case V_21 :
V_17 = L_2 ;
break;
case V_22 :
V_17 = L_3 ;
break;
case V_23 :
V_17 = L_4 ;
break;
case V_24 :
V_17 = L_5 ;
break;
default:
F_8 () ;
}
switch ( F_9 ( V_16 -> V_19 ) ) {
case V_25 :
V_18 = L_6 ;
break;
case V_26 :
V_18 = L_7 ;
break;
case V_27 :
V_18 = L_8 ;
break;
case V_28 :
V_18 = L_9 ;
break;
case V_29 :
V_18 = L_10 ;
break;
case V_30 :
V_18 = L_11 ;
break;
case V_31 :
V_18 = L_5 ;
break;
default:
F_8 () ;
}
F_10 ( V_13 , L_12 , V_17 , V_18 ) ;
}
static int F_11 ( struct V_1 * V_2 ,
const struct V_15 * V_16 ,
enum V_32 V_33 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
enum V_34 V_17 =
F_7 ( V_16 -> V_19 ) ;
unsigned int V_35 , V_36 , V_37 , V_38 ;
unsigned int V_39 = 1 ;
int V_40 ;
switch ( V_33 ) {
case V_41 :
if ( V_17 == V_24 )
return 0 ;
if ( V_17 == V_22 ||
V_17 == V_23 )
return - V_42 ;
V_39 = 0 ;
break;
case V_43 :
if ( V_17 == V_22 )
return 0 ;
if ( V_17 != V_20 )
return - V_42 ;
break;
case V_44 :
if ( V_17 == V_23 )
return 0 ;
if ( V_17 != V_21 )
return - V_42 ;
break;
default:
F_8 () ;
}
V_35 = F_12 ( V_16 -> V_19 ) ;
V_36 = V_45 + V_35 / 32 * 4 ;
V_37 = V_35 % 32 ;
V_40 = F_13 ( V_4 -> V_46 , V_36 , & V_38 ) ;
if ( V_40 )
return V_40 ;
V_38 = ( V_38 >> V_37 ) & 1 ;
return ( V_38 == V_39 ) ? 0 : - V_42 ;
}
static int F_14 ( struct V_1 * V_2 ,
const struct V_15 * V_16 ,
T_1 * V_47 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
enum V_48 type =
F_9 ( V_16 -> V_19 ) ;
const unsigned int V_49 [] = { 4 , 8 } ;
const unsigned int V_50 [] = { 8 , 12 , 16 , 20 } ;
const unsigned int V_51 [] = { 4 , 5 , 7 , 9 , 11 , 12 , 14 , 16 } ;
const unsigned int * V_52 ;
unsigned int V_53 , V_36 , V_37 , V_54 , V_55 , V_38 ;
int V_40 ;
switch ( type ) {
case V_25 :
V_52 = V_49 ;
V_36 = V_56 ;
V_55 = 1 ;
break;
case V_26 :
V_52 = V_50 ;
V_36 = V_57 ;
V_55 = 2 ;
break;
case V_27 :
V_52 = V_51 ;
V_36 = V_58 ;
V_55 = 4 ;
break;
case V_28 :
* V_47 = 4 ;
return 0 ;
case V_29 :
* V_47 = 5 ;
return 0 ;
case V_30 :
* V_47 = 8 ;
return 0 ;
default:
return - V_42 ;
}
V_53 = F_15 ( V_16 -> V_19 ) ;
V_53 *= V_55 ;
V_36 += V_53 / 32 * 4 ;
V_37 = V_53 % 32 ;
V_54 = ( 1U << V_55 ) - 1 ;
V_40 = F_13 ( V_4 -> V_46 , V_36 , & V_38 ) ;
if ( V_40 )
return V_40 ;
* V_47 = V_52 [ ( V_38 >> V_37 ) & V_54 ] ;
return 0 ;
}
static int F_16 ( struct V_1 * V_2 ,
const struct V_15 * V_16 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
unsigned int V_59 = F_17 ( V_16 -> V_19 ) ;
unsigned int V_38 ;
int V_40 ;
if ( V_59 == V_60 )
return 0 ;
V_40 = F_13 ( V_4 -> V_46 , V_61 , & V_38 ) ;
if ( V_40 )
return V_40 ;
return V_38 & F_18 ( V_59 ) ? 0 : - V_42 ;
}
static int F_19 ( struct V_1 * V_2 ,
unsigned V_62 ,
unsigned long * V_63 )
{
const struct V_15 * V_16 = F_6 ( V_2 , V_62 ) ;
enum V_32 V_33 = F_20 ( * V_63 ) ;
bool V_64 = false ;
T_1 V_65 ;
int V_40 ;
switch ( V_33 ) {
case V_41 :
case V_43 :
case V_44 :
V_40 = F_11 ( V_2 , V_16 , V_33 ) ;
break;
case V_66 :
V_40 = F_14 ( V_2 , V_16 , & V_65 ) ;
V_64 = true ;
break;
case V_67 :
V_40 = F_16 ( V_2 , V_16 ) ;
break;
default:
V_40 = - V_42 ;
break;
}
if ( V_40 == 0 && V_64 )
* V_63 = F_21 ( V_33 , V_65 ) ;
return V_40 ;
}
static int F_22 ( struct V_1 * V_2 ,
const struct V_15 * V_16 ,
enum V_32 V_33 , T_2 V_65 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
enum V_34 V_17 =
F_7 ( V_16 -> V_19 ) ;
unsigned int V_35 , V_36 , V_37 ;
unsigned int V_38 = 1 ;
switch ( V_33 ) {
case V_41 :
if ( V_17 == V_24 )
return 0 ;
if ( V_17 == V_22 ||
V_17 == V_23 ) {
F_23 ( V_2 -> V_68 ,
L_13 ,
V_16 -> V_9 ) ;
return - V_42 ;
}
V_38 = 0 ;
break;
case V_43 :
if ( V_17 == V_22 && V_65 != 0 )
return 0 ;
if ( V_17 != V_20 ) {
F_23 ( V_2 -> V_68 ,
L_14 ,
V_16 -> V_9 ) ;
return - V_42 ;
}
if ( V_65 == 0 ) {
F_23 ( V_2 -> V_68 , L_15 ) ;
return - V_42 ;
}
break;
case V_44 :
if ( V_17 == V_23 && V_65 != 0 )
return 0 ;
if ( V_17 != V_21 ) {
F_23 ( V_2 -> V_68 ,
L_16 ,
V_16 -> V_9 ) ;
return - V_42 ;
}
if ( V_65 == 0 ) {
F_23 ( V_2 -> V_68 , L_17 ) ;
return - V_42 ;
}
break;
case V_69 :
if ( V_17 == V_24 ) {
F_23 ( V_2 -> V_68 ,
L_18 ,
V_16 -> V_9 ) ;
return - V_42 ;
}
if ( V_65 == 0 )
return 0 ;
break;
default:
F_8 () ;
}
V_35 = F_12 ( V_16 -> V_19 ) ;
V_36 = V_45 + V_35 / 32 * 4 ;
V_37 = V_35 % 32 ;
return F_24 ( V_4 -> V_46 , V_36 , 1 << V_37 , V_38 << V_37 ) ;
}
static int F_25 ( struct V_1 * V_2 ,
const struct V_15 * V_16 ,
T_1 V_47 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
enum V_48 type =
F_9 ( V_16 -> V_19 ) ;
const unsigned int V_49 [] = { 4 , 8 , - 1 } ;
const unsigned int V_50 [] = { 8 , 12 , 16 , 20 , - 1 } ;
const unsigned int V_51 [] = { 4 , 5 , 7 , 9 , 11 , 12 , 14 , 16 , - 1 } ;
const unsigned int * V_52 ;
unsigned int V_53 , V_36 , V_37 , V_54 , V_55 , V_38 ;
switch ( type ) {
case V_25 :
V_52 = V_49 ;
V_36 = V_56 ;
V_55 = 1 ;
break;
case V_26 :
V_52 = V_50 ;
V_36 = V_57 ;
V_55 = 2 ;
break;
case V_27 :
V_52 = V_51 ;
V_36 = V_58 ;
V_55 = 4 ;
break;
default:
F_23 ( V_2 -> V_68 ,
L_19 ,
V_16 -> V_9 ) ;
return - V_42 ;
}
for ( V_38 = 0 ; V_52 [ V_38 ] > 0 ; V_38 ++ ) {
if ( V_52 [ V_38 ] > V_47 )
break;
}
if ( V_38 == 0 ) {
F_23 ( V_2 -> V_68 ,
L_20 ,
V_47 , V_16 -> V_9 ) ;
return - V_42 ;
}
V_38 -- ;
V_53 = F_15 ( V_16 -> V_19 ) ;
V_53 *= V_55 ;
V_36 += V_53 / 32 * 4 ;
V_37 = V_53 % 32 ;
V_54 = ( 1U << V_55 ) - 1 ;
return F_24 ( V_4 -> V_46 , V_36 ,
V_54 << V_37 , V_38 << V_37 ) ;
}
static int F_26 ( struct V_1 * V_2 ,
const struct V_15 * V_16 ,
T_1 V_70 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
unsigned int V_59 = F_17 ( V_16 -> V_19 ) ;
unsigned int V_36 , V_54 ;
if ( ! ( V_4 -> V_5 -> V_71 & V_72 ) &&
! V_70 )
return - V_42 ;
if ( V_59 == V_60 )
return V_70 ? 0 : - V_42 ;
V_36 = V_61 + V_59 / 32 * 4 ;
V_54 = F_18 ( V_59 % 32 ) ;
return F_24 ( V_4 -> V_46 , V_36 , V_54 , V_70 ? V_54 : 0 ) ;
}
static int F_27 ( struct V_1 * V_2 ,
unsigned V_62 ,
unsigned long * V_63 ,
unsigned V_73 )
{
const struct V_15 * V_16 = F_6 ( V_2 , V_62 ) ;
int V_74 , V_40 ;
for ( V_74 = 0 ; V_74 < V_73 ; V_74 ++ ) {
enum V_32 V_33 =
F_20 ( V_63 [ V_74 ] ) ;
T_2 V_65 = F_28 ( V_63 [ V_74 ] ) ;
switch ( V_33 ) {
case V_41 :
case V_43 :
case V_44 :
case V_69 :
V_40 = F_22 ( V_2 , V_16 ,
V_33 , V_65 ) ;
break;
case V_66 :
V_40 = F_25 ( V_2 , V_16 , V_65 ) ;
break;
case V_67 :
V_40 = F_26 ( V_2 , V_16 ,
V_65 ) ;
break;
default:
F_23 ( V_2 -> V_68 ,
L_21 ,
V_33 ) ;
return - V_42 ;
}
if ( V_40 )
return V_40 ;
}
return 0 ;
}
static int F_29 ( struct V_1 * V_2 ,
unsigned V_7 ,
unsigned long * V_63 ,
unsigned V_73 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
const unsigned * V_10 = V_4 -> V_5 -> V_8 [ V_7 ] . V_10 ;
unsigned V_11 = V_4 -> V_5 -> V_8 [ V_7 ] . V_11 ;
int V_74 , V_40 ;
for ( V_74 = 0 ; V_74 < V_11 ; V_74 ++ ) {
V_40 = F_27 ( V_2 , V_10 [ V_74 ] ,
V_63 , V_73 ) ;
if ( V_40 )
return V_40 ;
}
return 0 ;
}
static int F_30 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
return V_4 -> V_5 -> V_75 ;
}
static const char * F_31 ( struct V_1 * V_2 ,
unsigned V_7 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
return V_4 -> V_5 -> V_76 [ V_7 ] . V_9 ;
}
static int F_32 ( struct V_1 * V_2 ,
unsigned V_7 ,
const char * const * * V_8 ,
unsigned * V_77 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
* V_8 = V_4 -> V_5 -> V_76 [ V_7 ] . V_8 ;
* V_77 = V_4 -> V_5 -> V_76 [ V_7 ] . V_77 ;
return 0 ;
}
static int F_33 ( struct V_1 * V_2 , unsigned V_62 ,
int V_78 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
unsigned int V_79 , V_80 , V_36 , V_81 , V_37 , V_54 ;
bool V_82 ;
int V_40 ;
V_40 = F_26 ( V_2 ,
F_6 ( V_2 , V_62 ) , 1 ) ;
if ( V_40 )
return V_40 ;
if ( V_78 < 0 )
return 0 ;
if ( V_4 -> V_5 -> V_71 & V_83 ) {
V_79 = 4 ;
V_80 = 8 ;
V_82 = true ;
} else {
V_79 = 8 ;
V_80 = 4 ;
V_82 = false ;
}
V_36 = V_84 + V_62 * V_79 / 32 * V_80 ;
V_81 = V_36 + V_80 ;
V_37 = V_62 * V_79 % 32 ;
V_54 = ( 1U << V_79 ) - 1 ;
for (; V_36 < V_81 ; V_36 += 4 ) {
V_40 = F_24 ( V_4 -> V_46 , V_36 ,
V_54 << V_37 , V_78 << V_37 ) ;
if ( V_40 )
return V_40 ;
V_78 >>= V_79 ;
}
if ( V_82 ) {
V_40 = F_34 ( V_4 -> V_46 ,
V_85 , 1 ) ;
if ( V_40 )
return V_40 ;
}
return 0 ;
}
static int F_35 ( struct V_1 * V_2 ,
unsigned V_86 ,
unsigned V_87 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
const struct V_88 * V_89 =
& V_4 -> V_5 -> V_8 [ V_87 ] ;
int V_74 ;
int V_40 ;
for ( V_74 = 0 ; V_74 < V_89 -> V_11 ; V_74 ++ ) {
V_40 = F_33 ( V_2 , V_89 -> V_10 [ V_74 ] ,
V_89 -> V_90 [ V_74 ] ) ;
if ( V_40 )
return V_40 ;
}
return 0 ;
}
static int F_36 ( struct V_1 * V_2 ,
struct V_91 * V_92 ,
unsigned V_14 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
const struct V_88 * V_8 = V_4 -> V_5 -> V_8 ;
int V_6 = V_4 -> V_5 -> V_6 ;
enum V_93 V_94 ;
int V_74 , V_95 ;
if ( strstr ( V_92 -> V_9 , L_22 ) )
V_94 = V_96 ;
else
V_94 = V_97 ;
for ( V_74 = 0 ; V_74 < V_6 ; V_74 ++ ) {
if ( V_8 [ V_74 ] . V_94 != V_94 )
continue;
for ( V_95 = 0 ; V_95 < V_8 [ V_74 ] . V_11 ; V_95 ++ )
if ( V_8 [ V_74 ] . V_10 [ V_95 ] == V_14 )
goto V_98;
}
F_23 ( V_2 -> V_68 , L_23 , V_14 ) ;
return - V_42 ;
V_98:
return F_33 ( V_2 , V_14 , V_8 [ V_74 ] . V_90 [ V_95 ] ) ;
}
int F_37 ( struct V_99 * V_100 ,
struct V_101 * V_5 )
{
struct V_102 * V_68 = & V_100 -> V_68 ;
struct V_3 * V_4 ;
struct V_103 * V_104 ;
if ( ! V_5 ||
! V_5 -> V_10 || ! V_5 -> V_105 ||
! V_5 -> V_8 || ! V_5 -> V_6 ||
! V_5 -> V_76 || ! V_5 -> V_75 ) {
F_23 ( V_68 , L_24 ) ;
return - V_42 ;
}
V_4 = F_38 ( V_68 , sizeof( * V_4 ) , V_106 ) ;
if ( ! V_4 )
return - V_107 ;
V_104 = F_39 ( V_68 -> V_108 ) ;
V_4 -> V_46 = F_40 ( V_104 ) ;
F_41 ( V_104 ) ;
if ( F_42 ( V_4 -> V_46 ) ) {
F_23 ( V_68 , L_25 ) ;
return F_43 ( V_4 -> V_46 ) ;
}
V_4 -> V_5 = V_5 ;
V_4 -> V_109 . V_9 = V_68 -> V_110 -> V_9 ;
V_4 -> V_109 . V_10 = V_5 -> V_10 ;
V_4 -> V_109 . V_105 = V_5 -> V_105 ;
V_4 -> V_109 . V_111 = & V_112 ;
V_4 -> V_109 . V_113 = & V_114 ;
V_4 -> V_109 . V_115 = & V_116 ;
V_4 -> V_109 . V_117 = V_68 -> V_110 -> V_117 ;
V_4 -> V_2 = F_44 ( V_68 , & V_4 -> V_109 , V_4 ) ;
if ( F_42 ( V_4 -> V_2 ) ) {
F_23 ( V_68 , L_26 ) ;
return F_43 ( V_4 -> V_2 ) ;
}
F_45 ( V_100 , V_4 ) ;
return 0 ;
}
