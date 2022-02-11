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
V_40 = F_13 ( V_4 -> V_46 , V_4 -> V_47 + V_36 , & V_38 ) ;
if ( V_40 )
return V_40 ;
V_38 = ( V_38 >> V_37 ) & 1 ;
return ( V_38 == V_39 ) ? 0 : - V_42 ;
}
static int F_14 ( struct V_1 * V_2 ,
const struct V_15 * V_16 ,
T_1 * V_48 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
enum V_49 type =
F_9 ( V_16 -> V_19 ) ;
const unsigned int V_50 [] = { 4 , 8 } ;
const unsigned int V_51 [] = { 8 , 12 , 16 , 20 } ;
const unsigned int V_52 [] = { 4 , 5 , 7 , 9 , 11 , 12 , 14 , 16 } ;
const unsigned int * V_53 ;
unsigned int V_54 , V_36 , V_37 , V_55 , V_56 , V_38 ;
int V_40 ;
switch ( type ) {
case V_25 :
V_53 = V_50 ;
V_36 = V_57 ;
V_56 = 1 ;
break;
case V_26 :
V_53 = V_51 ;
V_36 = V_58 ;
V_56 = 2 ;
break;
case V_27 :
V_53 = V_52 ;
V_36 = V_59 ;
V_56 = 4 ;
break;
case V_28 :
* V_48 = 4 ;
return 0 ;
case V_29 :
* V_48 = 5 ;
return 0 ;
case V_30 :
* V_48 = 8 ;
return 0 ;
default:
return - V_42 ;
}
V_54 = F_15 ( V_16 -> V_19 ) ;
V_54 *= V_56 ;
V_36 += V_54 / 32 * 4 ;
V_37 = V_54 % 32 ;
V_55 = ( 1U << V_56 ) - 1 ;
V_40 = F_13 ( V_4 -> V_46 , V_4 -> V_47 + V_36 , & V_38 ) ;
if ( V_40 )
return V_40 ;
* V_48 = V_53 [ ( V_38 >> V_37 ) & V_55 ] ;
return 0 ;
}
static int F_16 ( struct V_1 * V_2 ,
const struct V_15 * V_16 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
unsigned int V_60 = F_17 ( V_16 -> V_19 ) ;
unsigned int V_38 ;
int V_40 ;
if ( V_60 == V_61 )
return 0 ;
V_40 = F_13 ( V_4 -> V_46 ,
V_4 -> V_47 + V_62 , & V_38 ) ;
if ( V_40 )
return V_40 ;
return V_38 & F_18 ( V_60 ) ? 0 : - V_42 ;
}
static int F_19 ( struct V_1 * V_2 ,
unsigned V_63 ,
unsigned long * V_64 )
{
const struct V_15 * V_16 = F_6 ( V_2 , V_63 ) ;
enum V_32 V_33 = F_20 ( * V_64 ) ;
bool V_65 = false ;
T_1 V_66 ;
int V_40 ;
switch ( V_33 ) {
case V_41 :
case V_43 :
case V_44 :
V_40 = F_11 ( V_2 , V_16 , V_33 ) ;
break;
case V_67 :
V_40 = F_14 ( V_2 , V_16 , & V_66 ) ;
V_65 = true ;
break;
case V_68 :
V_40 = F_16 ( V_2 , V_16 ) ;
break;
default:
V_40 = - V_42 ;
break;
}
if ( V_40 == 0 && V_65 )
* V_64 = F_21 ( V_33 , V_66 ) ;
return V_40 ;
}
static int F_22 ( struct V_1 * V_2 ,
const struct V_15 * V_16 ,
enum V_32 V_33 , T_1 V_66 )
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
F_23 ( V_2 -> V_69 ,
L_13 ,
V_16 -> V_9 ) ;
return - V_42 ;
}
V_38 = 0 ;
break;
case V_43 :
if ( V_17 == V_22 && V_66 != 0 )
return 0 ;
if ( V_17 != V_20 ) {
F_23 ( V_2 -> V_69 ,
L_14 ,
V_16 -> V_9 ) ;
return - V_42 ;
}
if ( V_66 == 0 ) {
F_23 ( V_2 -> V_69 , L_15 ) ;
return - V_42 ;
}
break;
case V_44 :
if ( V_17 == V_23 && V_66 != 0 )
return 0 ;
if ( V_17 != V_21 ) {
F_23 ( V_2 -> V_69 ,
L_16 ,
V_16 -> V_9 ) ;
return - V_42 ;
}
if ( V_66 == 0 ) {
F_23 ( V_2 -> V_69 , L_17 ) ;
return - V_42 ;
}
break;
case V_70 :
if ( V_17 == V_24 ) {
F_23 ( V_2 -> V_69 ,
L_18 ,
V_16 -> V_9 ) ;
return - V_42 ;
}
if ( V_66 == 0 )
return 0 ;
break;
default:
F_8 () ;
}
V_35 = F_12 ( V_16 -> V_19 ) ;
V_36 = V_45 + V_35 / 32 * 4 ;
V_37 = V_35 % 32 ;
return F_24 ( V_4 -> V_46 , V_4 -> V_47 + V_36 ,
1 << V_37 , V_38 << V_37 ) ;
}
static int F_25 ( struct V_1 * V_2 ,
const struct V_15 * V_16 ,
T_1 V_48 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
enum V_49 type =
F_9 ( V_16 -> V_19 ) ;
const unsigned int V_50 [] = { 4 , 8 , - 1 } ;
const unsigned int V_51 [] = { 8 , 12 , 16 , 20 , - 1 } ;
const unsigned int V_52 [] = { 4 , 5 , 7 , 9 , 11 , 12 , 14 , 16 , - 1 } ;
const unsigned int * V_53 ;
unsigned int V_54 , V_36 , V_37 , V_55 , V_56 , V_38 ;
switch ( type ) {
case V_25 :
V_53 = V_50 ;
V_36 = V_57 ;
V_56 = 1 ;
break;
case V_26 :
V_53 = V_51 ;
V_36 = V_58 ;
V_56 = 2 ;
break;
case V_27 :
V_53 = V_52 ;
V_36 = V_59 ;
V_56 = 4 ;
break;
default:
F_23 ( V_2 -> V_69 ,
L_19 ,
V_16 -> V_9 ) ;
return - V_42 ;
}
for ( V_38 = 0 ; V_53 [ V_38 ] > 0 ; V_38 ++ ) {
if ( V_53 [ V_38 ] > V_48 )
break;
}
if ( V_38 == 0 ) {
F_23 ( V_2 -> V_69 ,
L_20 ,
V_48 , V_16 -> V_9 ) ;
return - V_42 ;
}
V_38 -- ;
V_54 = F_15 ( V_16 -> V_19 ) ;
V_54 *= V_56 ;
V_36 += V_54 / 32 * 4 ;
V_37 = V_54 % 32 ;
V_55 = ( 1U << V_56 ) - 1 ;
return F_24 ( V_4 -> V_46 , V_4 -> V_47 + V_36 ,
V_55 << V_37 , V_38 << V_37 ) ;
}
static int F_26 ( struct V_1 * V_2 ,
const struct V_15 * V_16 ,
T_1 V_71 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
unsigned int V_60 = F_17 ( V_16 -> V_19 ) ;
unsigned int V_36 , V_55 ;
if ( ! ( V_4 -> V_5 -> V_72 & V_73 ) &&
! V_71 )
return - V_42 ;
if ( V_60 == V_61 )
return V_71 ? 0 : - V_42 ;
V_36 = V_4 -> V_47 + V_62 + V_60 / 32 * 4 ;
V_55 = F_18 ( V_60 % 32 ) ;
return F_24 ( V_4 -> V_46 , V_36 , V_55 , V_71 ? V_55 : 0 ) ;
}
static int F_27 ( struct V_1 * V_2 ,
unsigned V_63 ,
unsigned long * V_64 ,
unsigned V_74 )
{
const struct V_15 * V_16 = F_6 ( V_2 , V_63 ) ;
int V_75 , V_40 ;
for ( V_75 = 0 ; V_75 < V_74 ; V_75 ++ ) {
enum V_32 V_33 =
F_20 ( V_64 [ V_75 ] ) ;
T_1 V_66 = F_28 ( V_64 [ V_75 ] ) ;
switch ( V_33 ) {
case V_41 :
case V_43 :
case V_44 :
case V_70 :
V_40 = F_22 ( V_2 , V_16 ,
V_33 , V_66 ) ;
break;
case V_67 :
V_40 = F_25 ( V_2 , V_16 , V_66 ) ;
break;
case V_68 :
V_40 = F_26 ( V_2 , V_16 ,
V_66 ) ;
break;
default:
F_23 ( V_2 -> V_69 ,
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
unsigned long * V_64 ,
unsigned V_74 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
const unsigned * V_10 = V_4 -> V_5 -> V_8 [ V_7 ] . V_10 ;
unsigned V_11 = V_4 -> V_5 -> V_8 [ V_7 ] . V_11 ;
int V_75 , V_40 ;
for ( V_75 = 0 ; V_75 < V_11 ; V_75 ++ ) {
V_40 = F_27 ( V_2 , V_10 [ V_75 ] ,
V_64 , V_74 ) ;
if ( V_40 )
return V_40 ;
}
return 0 ;
}
static int F_30 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
return V_4 -> V_5 -> V_76 ;
}
static const char * F_31 ( struct V_1 * V_2 ,
unsigned V_7 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
return V_4 -> V_5 -> V_77 [ V_7 ] . V_9 ;
}
static int F_32 ( struct V_1 * V_2 ,
unsigned V_7 ,
const char * const * * V_8 ,
unsigned * V_78 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
* V_8 = V_4 -> V_5 -> V_77 [ V_7 ] . V_8 ;
* V_78 = V_4 -> V_5 -> V_77 [ V_7 ] . V_78 ;
return 0 ;
}
static int F_33 ( struct V_1 * V_2 , unsigned V_63 ,
int V_79 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
unsigned int V_80 , V_81 , V_36 , V_82 , V_37 , V_55 ;
bool V_83 ;
int V_40 ;
V_40 = F_26 ( V_2 ,
F_6 ( V_2 , V_63 ) , 1 ) ;
if ( V_40 )
return V_40 ;
if ( V_79 < 0 )
return 0 ;
if ( V_4 -> V_5 -> V_72 & V_84 ) {
V_80 = 4 ;
V_81 = 8 ;
V_83 = true ;
} else {
V_80 = 8 ;
V_81 = 4 ;
V_83 = false ;
}
V_36 = V_85 + V_63 * V_80 / 32 * V_81 ;
V_82 = V_36 + V_81 ;
V_37 = V_63 * V_80 % 32 ;
V_55 = ( 1U << V_80 ) - 1 ;
for (; V_36 < V_82 ; V_36 += 4 ) {
V_40 = F_24 ( V_4 -> V_46 , V_4 -> V_47 + V_36 ,
V_55 << V_37 , V_79 << V_37 ) ;
if ( V_40 )
return V_40 ;
V_79 >>= V_80 ;
}
if ( V_83 ) {
V_40 = F_34 ( V_4 -> V_46 ,
V_4 -> V_47 + V_86 ,
1 ) ;
if ( V_40 )
return V_40 ;
}
return 0 ;
}
static int F_35 ( struct V_1 * V_2 ,
unsigned V_87 ,
unsigned V_88 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
const struct V_89 * V_90 =
& V_4 -> V_5 -> V_8 [ V_88 ] ;
int V_75 ;
int V_40 ;
for ( V_75 = 0 ; V_75 < V_90 -> V_11 ; V_75 ++ ) {
V_40 = F_33 ( V_2 , V_90 -> V_10 [ V_75 ] ,
V_90 -> V_91 [ V_75 ] ) ;
if ( V_40 )
return V_40 ;
}
return 0 ;
}
static int F_36 ( struct V_1 * V_2 ,
struct V_92 * V_93 ,
unsigned V_14 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
const struct V_89 * V_8 = V_4 -> V_5 -> V_8 ;
int V_6 = V_4 -> V_5 -> V_6 ;
enum V_94 V_95 ;
int V_75 , V_96 ;
if ( strstr ( V_93 -> V_9 , L_22 ) )
V_95 = V_97 ;
else
V_95 = V_98 ;
for ( V_75 = 0 ; V_75 < V_6 ; V_75 ++ ) {
if ( V_8 [ V_75 ] . V_95 != V_95 )
continue;
for ( V_96 = 0 ; V_96 < V_8 [ V_75 ] . V_11 ; V_96 ++ )
if ( V_8 [ V_75 ] . V_10 [ V_96 ] == V_14 )
goto V_99;
}
F_23 ( V_2 -> V_69 , L_23 , V_14 ) ;
return - V_42 ;
V_99:
return F_33 ( V_2 , V_14 , V_8 [ V_75 ] . V_91 [ V_96 ] ) ;
}
int F_37 ( struct V_100 * V_101 ,
struct V_102 * V_5 )
{
struct V_103 * V_69 = & V_101 -> V_69 ;
struct V_3 * V_4 ;
struct V_104 * V_105 ;
if ( ! V_5 ||
! V_5 -> V_10 || ! V_5 -> V_106 ||
! V_5 -> V_8 || ! V_5 -> V_6 ||
! V_5 -> V_77 || ! V_5 -> V_76 ) {
F_23 ( V_69 , L_24 ) ;
return - V_42 ;
}
V_4 = F_38 ( V_69 , sizeof( * V_4 ) , V_107 ) ;
if ( ! V_4 )
return - V_108 ;
if ( F_39 ( V_69 -> V_109 , L_25 ) ||
F_39 ( V_69 -> V_109 , L_26 ) ||
F_39 ( V_69 -> V_109 , L_27 ) ||
F_39 ( V_69 -> V_109 , L_28 ) ||
F_39 ( V_69 -> V_109 , L_29 ) ||
F_39 ( V_69 -> V_109 , L_30 ) ) {
V_4 -> V_46 = F_40 ( V_69 -> V_109 ) ;
} else {
V_4 -> V_47 = 0x1000 ;
V_105 = F_41 ( V_69 -> V_109 ) ;
V_4 -> V_46 = F_40 ( V_105 ) ;
F_42 ( V_105 ) ;
}
if ( F_43 ( V_4 -> V_46 ) ) {
F_23 ( V_69 , L_31 ) ;
return F_44 ( V_4 -> V_46 ) ;
}
V_4 -> V_5 = V_5 ;
V_4 -> V_110 . V_9 = V_69 -> V_111 -> V_9 ;
V_4 -> V_110 . V_10 = V_5 -> V_10 ;
V_4 -> V_110 . V_106 = V_5 -> V_106 ;
V_4 -> V_110 . V_112 = & V_113 ;
V_4 -> V_110 . V_114 = & V_115 ;
V_4 -> V_110 . V_116 = & V_117 ;
V_4 -> V_110 . V_118 = V_69 -> V_111 -> V_118 ;
V_4 -> V_2 = F_45 ( V_69 , & V_4 -> V_110 , V_4 ) ;
if ( F_43 ( V_4 -> V_2 ) ) {
F_23 ( V_69 , L_32 ) ;
return F_44 ( V_4 -> V_2 ) ;
}
F_46 ( V_101 , V_4 ) ;
return 0 ;
}
