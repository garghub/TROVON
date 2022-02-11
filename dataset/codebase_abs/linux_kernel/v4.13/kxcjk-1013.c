static int F_1 ( struct V_1 * V_2 ,
enum V_3 V_4 )
{
int V_5 ;
V_5 = F_2 ( V_2 -> V_6 , V_7 ) ;
if ( V_5 < 0 ) {
F_3 ( & V_2 -> V_6 -> V_8 , L_1 ) ;
return V_5 ;
}
if ( V_4 == V_9 )
V_5 &= ~ V_10 ;
else
V_5 |= V_10 ;
V_5 = F_4 ( V_2 -> V_6 ,
V_7 , V_5 ) ;
if ( V_5 < 0 ) {
F_3 ( & V_2 -> V_6 -> V_8 , L_2 ) ;
return V_5 ;
}
return 0 ;
}
static int F_5 ( struct V_1 * V_2 ,
enum V_3 * V_4 )
{
int V_5 ;
V_5 = F_2 ( V_2 -> V_6 , V_7 ) ;
if ( V_5 < 0 ) {
F_3 ( & V_2 -> V_6 -> V_8 , L_1 ) ;
return V_5 ;
}
if ( V_5 & V_10 )
* V_4 = V_11 ;
else
* V_4 = V_9 ;
return 0 ;
}
static int F_6 ( struct V_1 * V_2 , int V_12 )
{
int V_5 ;
V_5 = F_2 ( V_2 -> V_6 , V_7 ) ;
if ( V_5 < 0 ) {
F_3 ( & V_2 -> V_6 -> V_8 , L_1 ) ;
return V_5 ;
}
V_5 &= ~ ( V_13 |
V_14 ) ;
V_5 |= ( V_15 [ V_12 ] . V_16 << 3 ) ;
V_5 |= ( V_15 [ V_12 ] . V_17 << 4 ) ;
V_5 = F_4 ( V_2 -> V_6 ,
V_7 ,
V_5 ) ;
if ( V_5 < 0 ) {
F_3 ( & V_2 -> V_6 -> V_8 , L_2 ) ;
return V_5 ;
}
V_2 -> V_18 = V_12 ;
return 0 ;
}
static int F_7 ( struct V_1 * V_2 )
{
int V_5 ;
V_5 = F_2 ( V_2 -> V_6 , V_19 ) ;
if ( V_5 < 0 ) {
F_3 ( & V_2 -> V_6 -> V_8 , L_3 ) ;
return V_5 ;
}
F_8 ( & V_2 -> V_6 -> V_8 , L_4 , V_5 ) ;
V_5 = F_1 ( V_2 , V_9 ) ;
if ( V_5 < 0 )
return V_5 ;
V_5 = F_2 ( V_2 -> V_6 , V_7 ) ;
if ( V_5 < 0 ) {
F_3 ( & V_2 -> V_6 -> V_8 , L_1 ) ;
return V_5 ;
}
V_5 |= V_20 ;
V_5 = F_4 ( V_2 -> V_6 , V_7 ,
V_5 ) ;
if ( V_5 < 0 ) {
F_3 ( & V_2 -> V_6 -> V_8 , L_5 ) ;
return V_5 ;
}
V_5 = F_6 ( V_2 , V_21 ) ;
if ( V_5 < 0 )
return V_5 ;
V_5 = F_2 ( V_2 -> V_6 , V_22 ) ;
if ( V_5 < 0 ) {
F_3 ( & V_2 -> V_6 -> V_8 , L_6 ) ;
return V_5 ;
}
V_2 -> V_23 = V_5 ;
V_5 = F_2 ( V_2 -> V_6 , V_24 ) ;
if ( V_5 < 0 ) {
F_3 ( & V_2 -> V_6 -> V_8 , L_7 ) ;
return V_5 ;
}
if ( V_2 -> V_25 )
V_5 |= V_26 ;
else
V_5 &= ~ V_26 ;
V_5 = F_4 ( V_2 -> V_6 , V_24 ,
V_5 ) ;
if ( V_5 < 0 ) {
F_3 ( & V_2 -> V_6 -> V_8 , L_8 ) ;
return V_5 ;
}
V_5 = F_1 ( V_2 , V_11 ) ;
if ( V_5 < 0 )
return V_5 ;
V_2 -> V_27 = V_28 ;
return 0 ;
}
static int F_9 ( struct V_1 * V_2 )
{
int V_29 ;
int V_30 = V_2 -> V_31 ;
for ( V_29 = 0 ; V_29 < F_10 ( V_32 [ V_30 ] ) ; ++ V_29 ) {
if ( V_32 [ V_30 ] [ V_29 ] . V_23 == V_2 -> V_23 )
return V_32 [ V_30 ] [ V_29 ] . V_33 ;
}
return V_34 ;
}
static int F_11 ( struct V_1 * V_2 , bool V_35 )
{
#ifdef F_12
int V_5 ;
if ( V_35 )
V_5 = F_13 ( & V_2 -> V_6 -> V_8 ) ;
else {
F_14 ( & V_2 -> V_6 -> V_8 ) ;
V_5 = F_15 ( & V_2 -> V_6 -> V_8 ) ;
}
if ( V_5 < 0 ) {
F_3 ( & V_2 -> V_6 -> V_8 ,
L_9 , V_35 ) ;
if ( V_35 )
F_16 ( & V_2 -> V_6 -> V_8 ) ;
return V_5 ;
}
#endif
return 0 ;
}
static int F_17 ( struct V_1 * V_2 )
{
int V_5 ;
V_5 = F_4 ( V_2 -> V_6 ,
V_36 ,
V_2 -> V_37 ) ;
if ( V_5 < 0 ) {
F_3 ( & V_2 -> V_6 -> V_8 ,
L_10 ) ;
return V_5 ;
}
V_5 = F_4 ( V_2 -> V_6 ,
V_38 ,
V_2 -> V_27 ) ;
if ( V_5 < 0 ) {
F_3 ( & V_2 -> V_6 -> V_8 , L_11 ) ;
return V_5 ;
}
return 0 ;
}
static int F_18 ( struct V_1 * V_2 ,
bool V_39 )
{
int V_5 ;
enum V_3 V_40 ;
V_5 = F_5 ( V_2 , & V_40 ) ;
if ( V_5 < 0 )
return V_5 ;
V_5 = F_1 ( V_2 , V_9 ) ;
if ( V_5 < 0 )
return V_5 ;
V_5 = F_17 ( V_2 ) ;
if ( V_5 < 0 )
return V_5 ;
V_5 = F_2 ( V_2 -> V_6 , V_24 ) ;
if ( V_5 < 0 ) {
F_3 ( & V_2 -> V_6 -> V_8 , L_7 ) ;
return V_5 ;
}
if ( V_39 )
V_5 |= V_41 ;
else
V_5 &= ~ V_41 ;
V_5 = F_4 ( V_2 -> V_6 , V_24 ,
V_5 ) ;
if ( V_5 < 0 ) {
F_3 ( & V_2 -> V_6 -> V_8 , L_8 ) ;
return V_5 ;
}
V_5 = F_2 ( V_2 -> V_6 , V_7 ) ;
if ( V_5 < 0 ) {
F_3 ( & V_2 -> V_6 -> V_8 , L_1 ) ;
return V_5 ;
}
if ( V_39 )
V_5 |= V_42 ;
else
V_5 &= ~ V_42 ;
V_5 = F_4 ( V_2 -> V_6 ,
V_7 , V_5 ) ;
if ( V_5 < 0 ) {
F_3 ( & V_2 -> V_6 -> V_8 , L_2 ) ;
return V_5 ;
}
if ( V_40 == V_11 ) {
V_5 = F_1 ( V_2 , V_11 ) ;
if ( V_5 < 0 )
return V_5 ;
}
return 0 ;
}
static int F_19 ( struct V_1 * V_2 ,
bool V_39 )
{
int V_5 ;
enum V_3 V_40 ;
V_5 = F_5 ( V_2 , & V_40 ) ;
if ( V_5 < 0 )
return V_5 ;
V_5 = F_1 ( V_2 , V_9 ) ;
if ( V_5 < 0 )
return V_5 ;
V_5 = F_2 ( V_2 -> V_6 , V_24 ) ;
if ( V_5 < 0 ) {
F_3 ( & V_2 -> V_6 -> V_8 , L_7 ) ;
return V_5 ;
}
if ( V_39 )
V_5 |= V_41 ;
else
V_5 &= ~ V_41 ;
V_5 = F_4 ( V_2 -> V_6 , V_24 ,
V_5 ) ;
if ( V_5 < 0 ) {
F_3 ( & V_2 -> V_6 -> V_8 , L_8 ) ;
return V_5 ;
}
V_5 = F_2 ( V_2 -> V_6 , V_7 ) ;
if ( V_5 < 0 ) {
F_3 ( & V_2 -> V_6 -> V_8 , L_1 ) ;
return V_5 ;
}
if ( V_39 )
V_5 |= V_43 ;
else
V_5 &= ~ V_43 ;
V_5 = F_4 ( V_2 -> V_6 ,
V_7 , V_5 ) ;
if ( V_5 < 0 ) {
F_3 ( & V_2 -> V_6 -> V_8 , L_2 ) ;
return V_5 ;
}
if ( V_40 == V_11 ) {
V_5 = F_1 ( V_2 , V_11 ) ;
if ( V_5 < 0 )
return V_5 ;
}
return 0 ;
}
static int F_20 ( int V_44 , int V_45 )
{
int V_29 ;
for ( V_29 = 0 ; V_29 < F_10 ( V_46 ) ; ++ V_29 ) {
if ( V_46 [ V_29 ] . V_44 == V_44 &&
V_46 [ V_29 ] . V_45 == V_45 ) {
return V_46 [ V_29 ] . V_23 ;
}
}
return - V_47 ;
}
static int F_21 ( int V_44 , int V_45 )
{
int V_29 ;
for ( V_29 = 0 ; V_29 < F_10 ( V_48 ) ; ++ V_29 ) {
if ( V_48 [ V_29 ] . V_44 == V_44 &&
V_48 [ V_29 ] . V_45 == V_45 ) {
return V_48 [ V_29 ] . V_23 ;
}
}
return - V_47 ;
}
static int F_22 ( struct V_1 * V_2 , int V_44 , int V_45 )
{
int V_5 ;
int V_23 ;
enum V_3 V_40 ;
V_5 = F_5 ( V_2 , & V_40 ) ;
if ( V_5 < 0 )
return V_5 ;
V_23 = F_20 ( V_44 , V_45 ) ;
if ( V_23 < 0 )
return V_23 ;
V_5 = F_1 ( V_2 , V_9 ) ;
if ( V_5 < 0 )
return V_5 ;
V_5 = F_4 ( V_2 -> V_6 , V_22 ,
V_23 ) ;
if ( V_5 < 0 ) {
F_3 ( & V_2 -> V_6 -> V_8 , L_12 ) ;
return V_5 ;
}
V_2 -> V_23 = V_23 ;
V_23 = F_21 ( V_44 , V_45 ) ;
if ( V_23 < 0 )
return V_23 ;
V_5 = F_4 ( V_2 -> V_6 , V_49 ,
V_23 ) ;
if ( V_5 < 0 ) {
F_3 ( & V_2 -> V_6 -> V_8 , L_13 ) ;
return V_5 ;
}
if ( V_40 == V_11 ) {
V_5 = F_1 ( V_2 , V_11 ) ;
if ( V_5 < 0 )
return V_5 ;
}
return 0 ;
}
static int F_23 ( struct V_1 * V_2 , int * V_44 , int * V_45 )
{
int V_29 ;
for ( V_29 = 0 ; V_29 < F_10 ( V_46 ) ; ++ V_29 ) {
if ( V_46 [ V_29 ] . V_23 == V_2 -> V_23 ) {
* V_44 = V_46 [ V_29 ] . V_44 ;
* V_45 = V_46 [ V_29 ] . V_45 ;
return V_50 ;
}
}
return - V_47 ;
}
static int F_24 ( struct V_1 * V_2 , int V_51 )
{
T_1 V_52 = V_53 + V_51 * 2 ;
int V_5 ;
V_5 = F_25 ( V_2 -> V_6 , V_52 ) ;
if ( V_5 < 0 ) {
F_3 ( & V_2 -> V_6 -> V_8 ,
L_14 , 'x' + V_51 ) ;
return V_5 ;
}
return V_5 ;
}
static int F_26 ( struct V_1 * V_2 , int V_44 )
{
int V_5 , V_29 ;
enum V_3 V_40 ;
for ( V_29 = 0 ; V_29 < F_10 ( V_15 ) ; ++ V_29 ) {
if ( V_15 [ V_29 ] . V_54 == V_44 ) {
V_5 = F_5 ( V_2 , & V_40 ) ;
if ( V_5 < 0 )
return V_5 ;
V_5 = F_1 ( V_2 , V_9 ) ;
if ( V_5 < 0 )
return V_5 ;
V_5 = F_6 ( V_2 , V_29 ) ;
if ( V_5 < 0 )
return V_5 ;
if ( V_40 == V_11 ) {
V_5 = F_1 ( V_2 , V_11 ) ;
if ( V_5 )
return V_5 ;
}
return 0 ;
}
}
return - V_47 ;
}
static int F_27 ( struct V_55 * V_56 ,
struct V_57 const * V_58 , int * V_44 ,
int * V_45 , long V_59 )
{
struct V_1 * V_2 = F_28 ( V_56 ) ;
int V_5 ;
switch ( V_59 ) {
case V_60 :
F_29 ( & V_2 -> V_61 ) ;
if ( F_30 ( V_56 ) )
V_5 = - V_62 ;
else {
V_5 = F_11 ( V_2 , true ) ;
if ( V_5 < 0 ) {
F_31 ( & V_2 -> V_61 ) ;
return V_5 ;
}
V_5 = F_24 ( V_2 , V_58 -> V_63 ) ;
if ( V_5 < 0 ) {
F_11 ( V_2 , false ) ;
F_31 ( & V_2 -> V_61 ) ;
return V_5 ;
}
* V_44 = F_32 ( V_5 >> 4 , 11 ) ;
V_5 = F_11 ( V_2 , false ) ;
}
F_31 ( & V_2 -> V_61 ) ;
if ( V_5 < 0 )
return V_5 ;
return V_64 ;
case V_65 :
* V_44 = 0 ;
* V_45 = V_15 [ V_2 -> V_18 ] . V_54 ;
return V_50 ;
case V_66 :
F_29 ( & V_2 -> V_61 ) ;
V_5 = F_23 ( V_2 , V_44 , V_45 ) ;
F_31 ( & V_2 -> V_61 ) ;
return V_5 ;
default:
return - V_47 ;
}
}
static int F_33 ( struct V_55 * V_56 ,
struct V_57 const * V_58 , int V_44 ,
int V_45 , long V_59 )
{
struct V_1 * V_2 = F_28 ( V_56 ) ;
int V_5 ;
switch ( V_59 ) {
case V_66 :
F_29 ( & V_2 -> V_61 ) ;
V_5 = F_22 ( V_2 , V_44 , V_45 ) ;
F_31 ( & V_2 -> V_61 ) ;
break;
case V_65 :
if ( V_44 )
return - V_47 ;
F_29 ( & V_2 -> V_61 ) ;
V_5 = F_26 ( V_2 , V_45 ) ;
F_31 ( & V_2 -> V_61 ) ;
break;
default:
V_5 = - V_47 ;
}
return V_5 ;
}
static int F_34 ( struct V_55 * V_56 ,
const struct V_57 * V_58 ,
enum V_67 type ,
enum V_68 V_69 ,
enum V_70 V_71 ,
int * V_44 , int * V_45 )
{
struct V_1 * V_2 = F_28 ( V_56 ) ;
* V_45 = 0 ;
switch ( V_71 ) {
case V_72 :
* V_44 = V_2 -> V_27 ;
break;
case V_73 :
* V_44 = V_2 -> V_37 ;
break;
default:
return - V_47 ;
}
return V_64 ;
}
static int F_35 ( struct V_55 * V_56 ,
const struct V_57 * V_58 ,
enum V_67 type ,
enum V_68 V_69 ,
enum V_70 V_71 ,
int V_44 , int V_45 )
{
struct V_1 * V_2 = F_28 ( V_56 ) ;
if ( V_2 -> V_74 )
return - V_62 ;
switch ( V_71 ) {
case V_72 :
V_2 -> V_27 = V_44 ;
break;
case V_73 :
V_2 -> V_37 = V_44 ;
break;
default:
return - V_47 ;
}
return 0 ;
}
static int F_36 ( struct V_55 * V_56 ,
const struct V_57 * V_58 ,
enum V_67 type ,
enum V_68 V_69 )
{
struct V_1 * V_2 = F_28 ( V_56 ) ;
return V_2 -> V_74 ;
}
static int F_37 ( struct V_55 * V_56 ,
const struct V_57 * V_58 ,
enum V_67 type ,
enum V_68 V_69 ,
int V_75 )
{
struct V_1 * V_2 = F_28 ( V_56 ) ;
int V_5 ;
if ( V_75 && V_2 -> V_74 )
return 0 ;
F_29 ( & V_2 -> V_61 ) ;
if ( ! V_75 && V_2 -> V_76 ) {
V_2 -> V_74 = 0 ;
F_31 ( & V_2 -> V_61 ) ;
return 0 ;
}
V_5 = F_11 ( V_2 , V_75 ) ;
if ( V_5 < 0 ) {
F_31 ( & V_2 -> V_61 ) ;
return V_5 ;
}
V_5 = F_18 ( V_2 , V_75 ) ;
if ( V_5 < 0 ) {
F_11 ( V_2 , false ) ;
V_2 -> V_74 = 0 ;
F_31 ( & V_2 -> V_61 ) ;
return V_5 ;
}
V_2 -> V_74 = V_75 ;
F_31 ( & V_2 -> V_61 ) ;
return 0 ;
}
static int F_38 ( struct V_55 * V_56 )
{
struct V_1 * V_2 = F_28 ( V_56 ) ;
return F_11 ( V_2 , true ) ;
}
static int F_39 ( struct V_55 * V_56 )
{
struct V_1 * V_2 = F_28 ( V_56 ) ;
return F_11 ( V_2 , false ) ;
}
static T_2 F_40 ( int V_77 , void * V_78 )
{
struct V_79 * V_80 = V_78 ;
struct V_55 * V_56 = V_80 -> V_56 ;
struct V_1 * V_2 = F_28 ( V_56 ) ;
int V_5 ;
F_29 ( & V_2 -> V_61 ) ;
V_5 = F_41 ( V_2 -> V_6 ,
V_53 ,
V_81 * 2 ,
( T_1 * ) V_2 -> V_82 ) ;
F_31 ( & V_2 -> V_61 ) ;
if ( V_5 < 0 )
goto V_83;
F_42 ( V_56 , V_2 -> V_82 ,
V_2 -> V_84 ) ;
V_83:
F_43 ( V_56 -> V_85 ) ;
return V_86 ;
}
static int F_44 ( struct V_87 * V_85 )
{
struct V_55 * V_56 = F_45 ( V_85 ) ;
struct V_1 * V_2 = F_28 ( V_56 ) ;
int V_5 ;
V_5 = F_2 ( V_2 -> V_6 , V_88 ) ;
if ( V_5 < 0 ) {
F_3 ( & V_2 -> V_6 -> V_8 , L_15 ) ;
return V_5 ;
}
return 0 ;
}
static int F_46 ( struct V_87 * V_85 ,
bool V_75 )
{
struct V_55 * V_56 = F_45 ( V_85 ) ;
struct V_1 * V_2 = F_28 ( V_56 ) ;
int V_5 ;
F_29 ( & V_2 -> V_61 ) ;
if ( ! V_75 && V_2 -> V_74 && V_2 -> V_76 ) {
V_2 -> V_76 = false ;
F_31 ( & V_2 -> V_61 ) ;
return 0 ;
}
V_5 = F_11 ( V_2 , V_75 ) ;
if ( V_5 < 0 ) {
F_31 ( & V_2 -> V_61 ) ;
return V_5 ;
}
if ( V_2 -> V_89 == V_85 )
V_5 = F_18 ( V_2 , V_75 ) ;
else
V_5 = F_19 ( V_2 , V_75 ) ;
if ( V_5 < 0 ) {
F_11 ( V_2 , false ) ;
F_31 ( & V_2 -> V_61 ) ;
return V_5 ;
}
if ( V_2 -> V_89 == V_85 )
V_2 -> V_76 = V_75 ;
else
V_2 -> V_90 = V_75 ;
F_31 ( & V_2 -> V_61 ) ;
return 0 ;
}
static T_2 F_47 ( int V_77 , void * V_91 )
{
struct V_55 * V_56 = V_91 ;
struct V_1 * V_2 = F_28 ( V_56 ) ;
int V_5 ;
V_5 = F_2 ( V_2 -> V_6 , V_92 ) ;
if ( V_5 < 0 ) {
F_3 ( & V_2 -> V_6 -> V_8 , L_16 ) ;
goto V_93;
}
if ( V_5 & 0x02 ) {
V_5 = F_2 ( V_2 -> V_6 ,
V_94 ) ;
if ( V_5 < 0 ) {
F_3 ( & V_2 -> V_6 -> V_8 ,
L_17 ) ;
goto V_93;
}
if ( V_5 & V_95 )
F_48 ( V_56 ,
F_49 ( V_96 ,
0 ,
V_97 ,
V_98 ,
V_99 ) ,
V_2 -> V_84 ) ;
if ( V_5 & V_100 )
F_48 ( V_56 ,
F_49 ( V_96 ,
0 ,
V_97 ,
V_98 ,
V_101 ) ,
V_2 -> V_84 ) ;
if ( V_5 & V_102 )
F_48 ( V_56 ,
F_49 ( V_96 ,
0 ,
V_103 ,
V_98 ,
V_99 ) ,
V_2 -> V_84 ) ;
if ( V_5 & V_104 )
F_48 ( V_56 ,
F_49 ( V_96 ,
0 ,
V_103 ,
V_98 ,
V_101 ) ,
V_2 -> V_84 ) ;
if ( V_5 & V_105 )
F_48 ( V_56 ,
F_49 ( V_96 ,
0 ,
V_106 ,
V_98 ,
V_99 ) ,
V_2 -> V_84 ) ;
if ( V_5 & V_107 )
F_48 ( V_56 ,
F_49 ( V_96 ,
0 ,
V_106 ,
V_98 ,
V_101 ) ,
V_2 -> V_84 ) ;
}
V_93:
if ( V_2 -> V_90 )
return V_86 ;
V_5 = F_2 ( V_2 -> V_6 , V_88 ) ;
if ( V_5 < 0 )
F_3 ( & V_2 -> V_6 -> V_8 , L_15 ) ;
return V_86 ;
}
static T_2 F_50 ( int V_77 , void * V_91 )
{
struct V_55 * V_56 = V_91 ;
struct V_1 * V_2 = F_28 ( V_56 ) ;
V_2 -> V_84 = F_51 ( V_56 ) ;
if ( V_2 -> V_90 )
F_52 ( V_2 -> V_108 ) ;
else if ( V_2 -> V_76 )
F_52 ( V_2 -> V_89 ) ;
if ( V_2 -> V_74 )
return V_109 ;
else
return V_86 ;
}
static const char * F_53 ( struct V_110 * V_8 ,
enum V_111 * V_31 ,
bool * V_112 )
{
const struct V_113 * V_114 ;
V_114 = F_54 ( V_8 -> V_115 -> V_116 , V_8 ) ;
if ( ! V_114 )
return NULL ;
if ( strcmp ( V_114 -> V_114 , L_18 ) == 0 )
* V_112 = true ;
* V_31 = (enum V_111 ) V_114 -> V_117 ;
return F_55 ( V_8 ) ;
}
static int F_56 ( struct V_118 * V_6 ,
const struct V_119 * V_114 )
{
struct V_1 * V_2 ;
struct V_55 * V_56 ;
struct V_120 * V_121 ;
const char * V_122 ;
int V_5 ;
V_56 = F_57 ( & V_6 -> V_8 , sizeof( * V_2 ) ) ;
if ( ! V_56 )
return - V_123 ;
V_2 = F_28 ( V_56 ) ;
F_58 ( V_6 , V_56 ) ;
V_2 -> V_6 = V_6 ;
V_121 = F_59 ( & V_6 -> V_8 ) ;
if ( V_121 )
V_2 -> V_25 = V_121 -> V_25 ;
else
V_2 -> V_25 = true ;
if ( V_114 ) {
V_2 -> V_31 = (enum V_111 ) ( V_114 -> V_117 ) ;
V_122 = V_114 -> V_122 ;
} else if ( F_60 ( & V_6 -> V_8 ) ) {
V_122 = F_53 ( & V_6 -> V_8 ,
& V_2 -> V_31 ,
& V_2 -> V_112 ) ;
} else
return - V_124 ;
V_5 = F_7 ( V_2 ) ;
if ( V_5 < 0 )
return V_5 ;
F_61 ( & V_2 -> V_61 ) ;
V_56 -> V_8 . V_125 = & V_6 -> V_8 ;
V_56 -> V_126 = V_127 ;
V_56 -> V_128 = F_10 ( V_127 ) ;
V_56 -> V_129 = V_130 ;
V_56 -> V_122 = V_122 ;
V_56 -> V_131 = V_132 ;
V_56 -> V_71 = & V_133 ;
if ( V_6 -> V_77 > 0 && ! V_2 -> V_112 ) {
V_5 = F_62 ( & V_6 -> V_8 , V_6 -> V_77 ,
F_50 ,
F_47 ,
V_134 ,
V_135 ,
V_56 ) ;
if ( V_5 )
goto V_136;
V_2 -> V_108 = F_63 ( & V_6 -> V_8 ,
L_19 ,
V_56 -> V_122 ,
V_56 -> V_114 ) ;
if ( ! V_2 -> V_108 ) {
V_5 = - V_123 ;
goto V_136;
}
V_2 -> V_89 = F_63 ( & V_6 -> V_8 ,
L_20 ,
V_56 -> V_122 ,
V_56 -> V_114 ) ;
if ( ! V_2 -> V_89 ) {
V_5 = - V_123 ;
goto V_136;
}
V_2 -> V_108 -> V_8 . V_125 = & V_6 -> V_8 ;
V_2 -> V_108 -> V_137 = & V_138 ;
F_64 ( V_2 -> V_108 , V_56 ) ;
V_56 -> V_85 = V_2 -> V_108 ;
F_65 ( V_56 -> V_85 ) ;
V_5 = F_66 ( V_2 -> V_108 ) ;
if ( V_5 )
goto V_136;
V_2 -> V_89 -> V_8 . V_125 = & V_6 -> V_8 ;
V_2 -> V_89 -> V_137 = & V_138 ;
F_64 ( V_2 -> V_89 , V_56 ) ;
V_5 = F_66 ( V_2 -> V_89 ) ;
if ( V_5 ) {
V_2 -> V_89 = NULL ;
goto V_139;
}
}
V_5 = F_67 ( V_56 ,
& V_140 ,
F_40 ,
& V_141 ) ;
if ( V_5 < 0 ) {
F_3 ( & V_6 -> V_8 , L_21 ) ;
goto V_139;
}
V_5 = F_68 ( & V_6 -> V_8 ) ;
if ( V_5 )
goto V_142;
F_69 ( & V_6 -> V_8 ) ;
F_70 ( & V_6 -> V_8 ,
V_143 ) ;
F_71 ( & V_6 -> V_8 ) ;
V_5 = F_72 ( V_56 ) ;
if ( V_5 < 0 ) {
F_3 ( & V_6 -> V_8 , L_22 ) ;
goto V_142;
}
return 0 ;
V_142:
if ( V_2 -> V_108 )
F_73 ( V_56 ) ;
V_139:
if ( V_2 -> V_108 )
F_74 ( V_2 -> V_108 ) ;
if ( V_2 -> V_89 )
F_74 ( V_2 -> V_89 ) ;
V_136:
F_1 ( V_2 , V_9 ) ;
return V_5 ;
}
static int F_75 ( struct V_118 * V_6 )
{
struct V_55 * V_56 = F_76 ( V_6 ) ;
struct V_1 * V_2 = F_28 ( V_56 ) ;
F_77 ( V_56 ) ;
F_78 ( & V_6 -> V_8 ) ;
F_79 ( & V_6 -> V_8 ) ;
F_16 ( & V_6 -> V_8 ) ;
if ( V_2 -> V_108 ) {
F_73 ( V_56 ) ;
F_74 ( V_2 -> V_108 ) ;
F_74 ( V_2 -> V_89 ) ;
}
F_29 ( & V_2 -> V_61 ) ;
F_1 ( V_2 , V_9 ) ;
F_31 ( & V_2 -> V_61 ) ;
return 0 ;
}
static int F_80 ( struct V_110 * V_8 )
{
struct V_55 * V_56 = F_76 ( F_81 ( V_8 ) ) ;
struct V_1 * V_2 = F_28 ( V_56 ) ;
int V_5 ;
F_29 ( & V_2 -> V_61 ) ;
V_5 = F_1 ( V_2 , V_9 ) ;
F_31 ( & V_2 -> V_61 ) ;
return V_5 ;
}
static int F_82 ( struct V_110 * V_8 )
{
struct V_55 * V_56 = F_76 ( F_81 ( V_8 ) ) ;
struct V_1 * V_2 = F_28 ( V_56 ) ;
int V_5 = 0 ;
F_29 ( & V_2 -> V_61 ) ;
V_5 = F_1 ( V_2 , V_11 ) ;
F_31 ( & V_2 -> V_61 ) ;
return V_5 ;
}
static int F_83 ( struct V_110 * V_8 )
{
struct V_55 * V_56 = F_76 ( F_81 ( V_8 ) ) ;
struct V_1 * V_2 = F_28 ( V_56 ) ;
int V_5 ;
V_5 = F_1 ( V_2 , V_9 ) ;
if ( V_5 < 0 ) {
F_3 ( & V_2 -> V_6 -> V_8 , L_23 ) ;
return - V_144 ;
}
return 0 ;
}
static int F_84 ( struct V_110 * V_8 )
{
struct V_55 * V_56 = F_76 ( F_81 ( V_8 ) ) ;
struct V_1 * V_2 = F_28 ( V_56 ) ;
int V_5 ;
int V_145 ;
V_5 = F_1 ( V_2 , V_11 ) ;
if ( V_5 < 0 )
return V_5 ;
V_145 = F_9 ( V_2 ) ;
if ( V_145 < 20000 )
F_85 ( V_145 , 20000 ) ;
else
F_86 ( V_145 / 1000 ) ;
return 0 ;
}
