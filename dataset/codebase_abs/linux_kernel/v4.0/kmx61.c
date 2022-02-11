static void F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_3 * * V_5 = F_2 ( V_2 ) ;
* V_5 = V_4 ;
}
static struct V_3 * F_3 ( struct V_1 * V_2 )
{
return * (struct V_3 * * ) F_2 ( V_2 ) ;
}
static int F_4 ( int V_6 , int V_7 )
{
int V_8 ;
for ( V_8 = 0 ; V_8 < F_5 ( V_9 ) ; V_8 ++ )
if ( V_6 == V_9 [ V_8 ] . V_6 &&
V_7 == V_9 [ V_8 ] . V_7 )
return V_9 [ V_8 ] . V_10 ;
return - V_11 ;
}
static int F_6 ( T_1 V_10 , int * V_6 , int * V_7 )
{
int V_8 ;
for ( V_8 = 0 ; V_8 < F_5 ( V_9 ) ; V_8 ++ )
if ( V_10 == V_9 [ V_8 ] . V_10 ) {
* V_6 = V_9 [ V_8 ] . V_6 ;
* V_7 = V_9 [ V_8 ] . V_7 ;
return 0 ;
}
return - V_11 ;
}
static int F_7 ( int V_6 , int V_7 )
{
int V_8 ;
for ( V_8 = 0 ; V_8 < F_5 ( V_12 ) ; ++ V_8 )
if ( V_12 [ V_8 ] . V_6 == V_6 &&
V_12 [ V_8 ] . V_7 == V_7 )
return V_12 [ V_8 ] . V_10 ;
return - V_11 ;
}
static int F_8 ( struct V_3 * V_4 , T_1 V_13 , T_1 V_14 ,
bool V_15 )
{
int V_16 ;
int V_17 = - 1 , V_18 = - 1 ;
V_16 = F_9 ( V_4 -> V_19 , V_20 ) ;
if ( V_16 < 0 ) {
F_10 ( & V_4 -> V_19 -> V_21 , L_1 ) ;
return V_16 ;
}
if ( V_14 & V_22 ) {
if ( V_13 & V_23 ) {
V_16 |= V_23 ;
V_17 = 1 ;
} else {
V_16 &= ~ V_23 ;
V_17 = 0 ;
}
}
if ( V_14 & V_24 ) {
if ( V_13 & V_25 ) {
V_16 |= V_25 ;
V_18 = 1 ;
} else {
V_16 &= ~ V_25 ;
V_18 = 0 ;
}
}
if ( V_13 & V_26 )
V_16 |= V_26 ;
V_16 = F_11 ( V_4 -> V_19 , V_20 , V_16 ) ;
if ( V_16 < 0 ) {
F_10 ( & V_4 -> V_19 -> V_21 , L_2 ) ;
return V_16 ;
}
if ( V_17 != - 1 && V_15 )
V_4 -> V_17 = V_17 ;
if ( V_18 != - 1 && V_15 )
V_4 -> V_18 = V_18 ;
return 0 ;
}
static int F_12 ( struct V_3 * V_4 , T_1 * V_13 , T_1 V_14 )
{
int V_16 ;
V_16 = F_9 ( V_4 -> V_19 , V_20 ) ;
if ( V_16 < 0 ) {
F_10 ( & V_4 -> V_19 -> V_21 , L_1 ) ;
return V_16 ;
}
* V_13 = 0 ;
if ( V_14 & V_22 ) {
if ( V_16 & V_23 )
* V_13 |= V_23 ;
else
* V_13 &= ~ V_23 ;
}
if ( V_14 & V_24 ) {
if ( V_16 & V_25 )
* V_13 |= V_25 ;
else
* V_13 &= ~ V_25 ;
}
return 0 ;
}
static int F_13 ( struct V_3 * V_4 , int V_6 , int V_7 )
{
int V_16 , V_10 ;
V_10 = F_7 ( V_6 , V_7 ) ;
if ( V_10 < 0 )
return V_10 ;
V_16 = F_11 ( V_4 -> V_19 , V_27 ,
V_10 ) ;
if ( V_16 < 0 )
F_10 ( & V_4 -> V_19 -> V_21 , L_3 ) ;
return V_16 ;
}
static int F_14 ( struct V_3 * V_4 , int V_6 , int V_7 , T_1 V_14 )
{
int V_16 ;
T_1 V_13 ;
int V_28 , V_10 ;
V_16 = F_12 ( V_4 , & V_13 , V_22 | V_24 ) ;
if ( V_16 < 0 )
return V_16 ;
V_28 = F_4 ( V_6 , V_7 ) ;
if ( V_28 < 0 )
return V_28 ;
V_16 = F_8 ( V_4 , V_29 , V_22 | V_24 ,
true ) ;
if ( V_16 < 0 )
return V_16 ;
V_10 = 0 ;
if ( V_14 & V_22 )
V_10 |= V_28 << V_30 ;
if ( V_14 & V_24 )
V_10 |= V_28 << V_31 ;
V_16 = F_11 ( V_4 -> V_19 , V_32 ,
V_10 ) ;
if ( V_16 < 0 )
return V_16 ;
V_4 -> V_10 = V_10 ;
if ( V_14 & V_22 ) {
V_16 = F_13 ( V_4 , V_6 , V_7 ) ;
if ( V_16 )
return V_16 ;
}
return F_8 ( V_4 , V_13 , V_22 | V_24 , true ) ;
}
static int F_15 ( struct V_3 * V_4 , int * V_6 , int * V_7 ,
T_1 V_14 )
{ int V_8 ;
T_1 V_28 ;
if ( V_14 & V_22 )
V_28 = ( V_4 -> V_10 >> V_30 ) &
V_33 ;
else if ( V_14 & V_24 )
V_28 = ( V_4 -> V_10 >> V_31 ) &
V_34 ;
else
return - V_11 ;
for ( V_8 = 0 ; V_8 < F_5 ( V_9 ) ; V_8 ++ )
if ( V_28 == V_9 [ V_8 ] . V_10 ) {
* V_6 = V_9 [ V_8 ] . V_6 ;
* V_7 = V_9 [ V_8 ] . V_7 ;
return 0 ;
}
return - V_11 ;
}
static int F_16 ( struct V_3 * V_4 , T_1 V_35 )
{
int V_16 ;
V_16 = F_9 ( V_4 -> V_19 , V_36 ) ;
if ( V_16 < 0 ) {
F_10 ( & V_4 -> V_19 -> V_21 , L_4 ) ;
return V_16 ;
}
V_16 &= ~ V_37 ;
V_16 |= V_35 & V_37 ;
V_16 = F_11 ( V_4 -> V_19 , V_36 , V_16 ) ;
if ( V_16 < 0 ) {
F_10 ( & V_4 -> V_19 -> V_21 , L_5 ) ;
return V_16 ;
}
V_4 -> V_35 = V_35 ;
return 0 ;
}
static int F_17 ( struct V_3 * V_4 , T_2 V_38 )
{
int V_16 , V_8 ;
T_1 V_13 ;
for ( V_8 = 0 ; V_8 < F_5 ( V_39 ) ; V_8 ++ ) {
if ( V_39 [ V_8 ] == V_38 ) {
V_16 = F_12 ( V_4 , & V_13 ,
V_22 | V_24 ) ;
if ( V_16 < 0 )
return V_16 ;
V_16 = F_8 ( V_4 , V_29 ,
V_22 | V_24 , true ) ;
if ( V_16 < 0 )
return V_16 ;
V_16 = F_16 ( V_4 , V_8 ) ;
if ( V_16 < 0 )
return V_16 ;
return F_8 ( V_4 , V_13 ,
V_22 | V_24 , true ) ;
}
}
return - V_11 ;
}
static int F_18 ( struct V_3 * V_4 )
{
int V_16 , V_6 , V_7 ;
V_16 = F_9 ( V_4 -> V_19 , V_40 ) ;
if ( V_16 < 0 ) {
F_10 ( & V_4 -> V_19 -> V_21 , L_6 ) ;
return V_16 ;
}
if ( V_16 != V_41 ) {
F_10 ( & V_4 -> V_19 -> V_21 ,
L_7 ,
V_16 , V_41 ) ;
return - V_11 ;
}
V_16 = F_16 ( V_4 , V_42 ) ;
if ( V_16 < 0 )
return V_16 ;
V_16 = F_9 ( V_4 -> V_19 , V_32 ) ;
if ( V_16 < 0 ) {
F_10 ( & V_4 -> V_19 -> V_21 , L_8 ) ;
return V_16 ;
}
V_4 -> V_10 = V_16 ;
V_16 = F_6 ( V_4 -> V_10 , & V_6 , & V_7 ) ;
if ( V_16 < 0 )
return V_16 ;
V_16 = F_13 ( V_4 , V_6 , V_7 ) ;
if ( V_16 < 0 )
return V_16 ;
V_16 = F_8 ( V_4 , 0 , V_22 | V_24 , true ) ;
if ( V_16 < 0 )
return V_16 ;
V_4 -> V_43 = V_44 ;
V_4 -> V_45 = V_46 ;
return 0 ;
}
static int F_19 ( struct V_3 * V_4 ,
bool V_47 , T_1 V_14 )
{
T_1 V_13 ;
int V_16 ;
V_16 = F_12 ( V_4 , & V_13 , V_22 | V_24 ) ;
if ( V_16 < 0 )
return V_16 ;
V_16 = F_8 ( V_4 , V_29 , V_22 | V_24 , true ) ;
if ( V_16 < 0 )
return V_16 ;
V_16 = F_9 ( V_4 -> V_19 , V_48 ) ;
if ( V_16 < 0 ) {
F_10 ( & V_4 -> V_19 -> V_21 , L_4 ) ;
return V_16 ;
}
if ( V_47 ) {
V_16 |= V_49 ;
if ( V_14 & V_22 )
V_16 |= V_50 ;
if ( V_14 & V_24 )
V_16 |= V_51 ;
} else {
V_16 &= ~ V_49 ;
if ( V_14 & V_22 )
V_16 &= ~ V_50 ;
if ( V_14 & V_24 )
V_16 &= ~ V_51 ;
}
V_16 = F_11 ( V_4 -> V_19 , V_48 , V_16 ) ;
if ( V_16 < 0 ) {
F_10 ( & V_4 -> V_19 -> V_21 , L_9 ) ;
return V_16 ;
}
V_16 = F_9 ( V_4 -> V_19 , V_36 ) ;
if ( V_16 < 0 ) {
F_10 ( & V_4 -> V_19 -> V_21 , L_4 ) ;
return V_16 ;
}
if ( V_47 )
V_16 |= V_52 ;
else
V_16 &= ~ V_52 ;
V_16 = F_11 ( V_4 -> V_19 , V_36 , V_16 ) ;
if ( V_16 < 0 ) {
F_10 ( & V_4 -> V_19 -> V_21 , L_5 ) ;
return V_16 ;
}
return F_8 ( V_4 , V_13 , V_22 | V_24 , true ) ;
}
static int F_20 ( struct V_3 * V_4 )
{
int V_16 ;
V_16 = F_11 ( V_4 -> V_19 ,
V_53 ,
V_4 -> V_45 ) ;
if ( V_16 < 0 ) {
F_10 ( & V_4 -> V_19 -> V_21 , L_10 ) ;
return V_16 ;
}
V_16 = F_11 ( V_4 -> V_19 ,
V_54 ,
V_4 -> V_43 ) ;
if ( V_16 < 0 )
F_10 ( & V_4 -> V_19 -> V_21 , L_11 ) ;
return V_16 ;
}
static int F_21 ( struct V_3 * V_4 ,
bool V_47 )
{
T_1 V_13 ;
int V_16 ;
V_16 = F_12 ( V_4 , & V_13 , V_22 | V_24 ) ;
if ( V_16 < 0 )
return V_16 ;
V_16 = F_8 ( V_4 , V_29 , V_22 | V_24 , true ) ;
if ( V_16 < 0 )
return V_16 ;
V_16 = F_20 ( V_4 ) ;
if ( V_16 < 0 )
return V_16 ;
V_16 = F_9 ( V_4 -> V_19 , V_48 ) ;
if ( V_16 < 0 ) {
F_10 ( & V_4 -> V_19 -> V_21 , L_12 ) ;
return V_16 ;
}
if ( V_47 )
V_16 |= ( V_49 | V_55 ) ;
else
V_16 &= ~ ( V_49 | V_55 ) ;
V_16 = F_11 ( V_4 -> V_19 , V_48 , V_16 ) ;
if ( V_16 < 0 ) {
F_10 ( & V_4 -> V_19 -> V_21 , L_13 ) ;
return V_16 ;
}
V_16 = F_9 ( V_4 -> V_19 , V_36 ) ;
if ( V_16 < 0 ) {
F_10 ( & V_4 -> V_19 -> V_21 , L_4 ) ;
return V_16 ;
}
if ( V_47 )
V_16 |= V_56 | V_57 ;
else
V_16 &= ~ ( V_56 | V_57 ) ;
V_16 = F_11 ( V_4 -> V_19 , V_36 , V_16 ) ;
if ( V_16 < 0 ) {
F_10 ( & V_4 -> V_19 -> V_21 , L_5 ) ;
return V_16 ;
}
V_13 |= V_26 ;
return F_8 ( V_4 , V_13 , V_22 | V_24 , true ) ;
}
static int F_22 ( struct V_3 * V_4 , bool V_58 , T_1 V_14 )
{
#ifdef F_23
int V_16 ;
if ( V_14 & V_22 ) {
if ( V_58 && ! V_4 -> V_59 && ! V_4 -> V_18 ) {
V_16 = F_8 ( V_4 , 0 , V_22 , true ) ;
if ( V_16 < 0 )
return V_16 ;
}
V_4 -> V_59 = V_58 ;
}
if ( V_14 & V_24 ) {
if ( V_58 && ! V_4 -> V_60 && ! V_4 -> V_17 ) {
V_16 = F_8 ( V_4 , 0 , V_24 , true ) ;
if ( V_16 < 0 )
return V_16 ;
}
V_4 -> V_60 = V_58 ;
}
if ( V_58 ) {
V_16 = F_24 ( & V_4 -> V_19 -> V_21 ) ;
} else {
F_25 ( & V_4 -> V_19 -> V_21 ) ;
V_16 = F_26 ( & V_4 -> V_19 -> V_21 ) ;
}
if ( V_16 < 0 ) {
F_10 ( & V_4 -> V_19 -> V_21 ,
L_14 ,
V_58 , V_16 ) ;
if ( V_58 )
F_27 ( & V_4 -> V_19 -> V_21 ) ;
return V_16 ;
}
#endif
return 0 ;
}
static int F_28 ( struct V_3 * V_4 , T_1 V_61 , T_1 V_62 )
{
int V_16 ;
T_1 V_63 = V_61 + V_62 * 2 ;
V_16 = F_29 ( V_4 -> V_19 , V_63 ) ;
if ( V_16 < 0 )
F_10 ( & V_4 -> V_19 -> V_21 , L_15 , V_63 ) ;
return V_16 ;
}
static int F_30 ( struct V_1 * V_2 ,
struct V_64 const * V_65 , int * V_6 ,
int * V_7 , long V_66 )
{
int V_16 ;
T_1 V_67 ;
struct V_3 * V_4 = F_3 ( V_2 ) ;
switch ( V_66 ) {
case V_68 :
switch ( V_65 -> type ) {
case V_69 :
V_67 = V_70 ;
break;
case V_71 :
V_67 = V_72 ;
break;
default:
return - V_11 ;
}
F_31 ( & V_4 -> V_73 ) ;
V_16 = F_22 ( V_4 , true , V_65 -> V_74 ) ;
if ( V_16 ) {
F_32 ( & V_4 -> V_73 ) ;
return V_16 ;
}
V_16 = F_28 ( V_4 , V_67 , V_65 -> V_75 ) ;
if ( V_16 < 0 ) {
F_22 ( V_4 , false , V_65 -> V_74 ) ;
F_32 ( & V_4 -> V_73 ) ;
return V_16 ;
}
* V_6 = F_33 ( V_16 >> V_65 -> V_76 . V_77 ,
V_65 -> V_76 . V_78 - 1 ) ;
V_16 = F_22 ( V_4 , false , V_65 -> V_74 ) ;
F_32 ( & V_4 -> V_73 ) ;
if ( V_16 )
return V_16 ;
return V_79 ;
case V_80 :
switch ( V_65 -> type ) {
case V_69 :
* V_6 = 0 ;
* V_7 = V_39 [ V_4 -> V_35 ] ;
return V_81 ;
case V_71 :
* V_6 = 0 ;
* V_7 = 1465 ;
return V_81 ;
default:
return - V_11 ;
}
case V_82 :
if ( V_65 -> type != V_69 && V_65 -> type != V_71 )
return - V_11 ;
F_31 ( & V_4 -> V_73 ) ;
V_16 = F_15 ( V_4 , V_6 , V_7 , V_65 -> V_74 ) ;
F_32 ( & V_4 -> V_73 ) ;
if ( V_16 )
return - V_11 ;
return V_81 ;
}
return - V_11 ;
}
static int F_34 ( struct V_1 * V_2 ,
struct V_64 const * V_65 , int V_6 ,
int V_7 , long V_66 )
{
int V_16 ;
struct V_3 * V_4 = F_3 ( V_2 ) ;
switch ( V_66 ) {
case V_82 :
if ( V_65 -> type != V_69 && V_65 -> type != V_71 )
return - V_11 ;
F_31 ( & V_4 -> V_73 ) ;
V_16 = F_14 ( V_4 , V_6 , V_7 , V_65 -> V_74 ) ;
F_32 ( & V_4 -> V_73 ) ;
return V_16 ;
case V_80 :
switch ( V_65 -> type ) {
case V_69 :
if ( V_6 != 0 )
return - V_11 ;
F_31 ( & V_4 -> V_73 ) ;
V_16 = F_17 ( V_4 , V_7 ) ;
F_32 ( & V_4 -> V_73 ) ;
return V_16 ;
default:
return - V_11 ;
}
default:
return - V_11 ;
}
}
static int F_35 ( struct V_1 * V_2 ,
const struct V_64 * V_65 ,
enum V_83 type ,
enum V_84 V_85 ,
enum V_86 V_87 ,
int * V_6 , int * V_7 )
{
struct V_3 * V_4 = F_3 ( V_2 ) ;
* V_7 = 0 ;
switch ( V_87 ) {
case V_88 :
* V_6 = V_4 -> V_43 ;
return V_79 ;
case V_89 :
* V_6 = V_4 -> V_45 ;
return V_79 ;
default:
return - V_11 ;
}
}
static int F_36 ( struct V_1 * V_2 ,
const struct V_64 * V_65 ,
enum V_83 type ,
enum V_84 V_85 ,
enum V_86 V_87 ,
int V_6 , int V_7 )
{
struct V_3 * V_4 = F_3 ( V_2 ) ;
if ( V_4 -> V_90 )
return - V_91 ;
switch ( V_87 ) {
case V_88 :
V_4 -> V_43 = V_6 ;
return V_79 ;
case V_89 :
V_4 -> V_45 = V_6 ;
return V_79 ;
default:
return - V_11 ;
}
}
static int F_37 ( struct V_1 * V_2 ,
const struct V_64 * V_65 ,
enum V_83 type ,
enum V_84 V_85 )
{
struct V_3 * V_4 = F_3 ( V_2 ) ;
return V_4 -> V_90 ;
}
static int F_38 ( struct V_1 * V_2 ,
const struct V_64 * V_65 ,
enum V_83 type ,
enum V_84 V_85 ,
int V_92 )
{
struct V_3 * V_4 = F_3 ( V_2 ) ;
int V_16 = 0 ;
if ( V_92 && V_4 -> V_90 )
return 0 ;
F_31 ( & V_4 -> V_73 ) ;
if ( ! V_92 && V_4 -> V_93 ) {
V_4 -> V_90 = false ;
goto V_94;
}
V_16 = F_22 ( V_4 , V_92 , V_22 ) ;
if ( V_16 < 0 )
goto V_94;
V_16 = F_21 ( V_4 , V_92 ) ;
if ( V_16 < 0 ) {
F_22 ( V_4 , false , V_22 ) ;
goto V_94;
}
V_4 -> V_90 = V_92 ;
V_94:
F_32 ( & V_4 -> V_73 ) ;
return V_16 ;
}
static int F_39 ( struct V_1 * V_2 ,
struct V_95 * V_96 )
{
struct V_3 * V_4 = F_3 ( V_2 ) ;
if ( V_4 -> V_97 != V_96 && V_4 -> V_98 != V_96 )
return - V_11 ;
return 0 ;
}
static int F_40 ( struct V_1 * V_2 ,
struct V_95 * V_96 )
{
struct V_3 * V_4 = F_3 ( V_2 ) ;
if ( V_4 -> V_99 != V_96 )
return - V_11 ;
return 0 ;
}
static int F_41 ( struct V_95 * V_96 ,
bool V_92 )
{
int V_16 = 0 ;
T_1 V_14 ;
struct V_1 * V_2 = F_42 ( V_96 ) ;
struct V_3 * V_4 = F_3 ( V_2 ) ;
F_31 ( & V_4 -> V_73 ) ;
if ( ! V_92 && V_4 -> V_90 && V_4 -> V_93 ) {
V_4 -> V_93 = false ;
goto V_94;
}
if ( V_4 -> V_97 == V_96 || V_4 -> V_98 == V_96 )
V_14 = V_22 ;
else
V_14 = V_24 ;
V_16 = F_22 ( V_4 , V_92 , V_14 ) ;
if ( V_16 < 0 )
goto V_94;
if ( V_4 -> V_97 == V_96 || V_4 -> V_99 == V_96 )
V_16 = F_19 ( V_4 , V_92 , V_14 ) ;
else
V_16 = F_21 ( V_4 , V_92 ) ;
if ( V_16 < 0 ) {
F_22 ( V_4 , false , V_14 ) ;
goto V_94;
}
if ( V_4 -> V_97 == V_96 )
V_4 -> V_100 = V_92 ;
else if ( V_4 -> V_99 == V_96 )
V_4 -> V_101 = V_92 ;
else
V_4 -> V_93 = V_92 ;
V_94:
F_32 ( & V_4 -> V_73 ) ;
return V_16 ;
}
static int F_43 ( struct V_95 * V_96 )
{
struct V_1 * V_2 = F_42 ( V_96 ) ;
struct V_3 * V_4 = F_3 ( V_2 ) ;
int V_16 ;
V_16 = F_9 ( V_4 -> V_19 , V_102 ) ;
if ( V_16 < 0 ) {
F_10 ( & V_4 -> V_19 -> V_21 , L_16 ) ;
return V_16 ;
}
return 0 ;
}
static T_3 F_44 ( int V_103 , void * V_104 )
{
struct V_3 * V_4 = V_104 ;
struct V_1 * V_2 = V_4 -> V_105 ;
int V_16 ;
V_16 = F_9 ( V_4 -> V_19 , V_106 ) ;
if ( V_16 < 0 ) {
F_10 ( & V_4 -> V_19 -> V_21 , L_17 ) ;
goto V_107;
}
if ( V_16 & V_108 ) {
V_16 = F_9 ( V_4 -> V_19 , V_109 ) ;
if ( V_16 < 0 ) {
F_10 ( & V_4 -> V_19 -> V_21 , L_18 ) ;
goto V_107;
}
if ( V_16 & V_110 )
F_45 ( V_2 ,
F_46 ( V_69 ,
0 ,
V_111 ,
V_112 ,
V_113 ) ,
0 ) ;
if ( V_16 & V_114 )
F_45 ( V_2 ,
F_46 ( V_69 ,
0 ,
V_111 ,
V_112 ,
V_115 ) ,
0 ) ;
if ( V_16 & V_116 )
F_45 ( V_2 ,
F_46 ( V_69 ,
0 ,
V_117 ,
V_112 ,
V_113 ) ,
0 ) ;
if ( V_16 & V_118 )
F_45 ( V_2 ,
F_46 ( V_69 ,
0 ,
V_117 ,
V_112 ,
V_115 ) ,
0 ) ;
if ( V_16 & V_119 )
F_45 ( V_2 ,
F_46 ( V_69 ,
0 ,
V_120 ,
V_112 ,
V_113 ) ,
0 ) ;
if ( V_16 & V_121 )
F_45 ( V_2 ,
F_46 ( V_69 ,
0 ,
V_120 ,
V_112 ,
V_115 ) ,
0 ) ;
}
V_107:
V_16 = F_9 ( V_4 -> V_19 , V_36 ) ;
if ( V_16 < 0 )
F_10 ( & V_4 -> V_19 -> V_21 , L_4 ) ;
V_16 |= V_122 ;
V_16 = F_11 ( V_4 -> V_19 , V_36 , V_16 ) ;
if ( V_16 < 0 )
F_10 ( & V_4 -> V_19 -> V_21 , L_5 ) ;
V_16 = F_9 ( V_4 -> V_19 , V_102 ) ;
if ( V_16 < 0 )
F_10 ( & V_4 -> V_19 -> V_21 , L_16 ) ;
return V_123 ;
}
static T_3 F_47 ( int V_103 , void * V_104 )
{
struct V_3 * V_4 = V_104 ;
if ( V_4 -> V_100 )
F_48 ( V_4 -> V_97 ) ;
if ( V_4 -> V_101 )
F_48 ( V_4 -> V_99 ) ;
if ( V_4 -> V_93 )
F_48 ( V_4 -> V_98 ) ;
if ( V_4 -> V_90 )
return V_124 ;
return V_123 ;
}
static T_3 F_49 ( int V_103 , void * V_125 )
{
struct V_126 * V_127 = V_125 ;
struct V_1 * V_2 = V_127 -> V_2 ;
struct V_3 * V_4 = F_3 ( V_2 ) ;
int V_128 , V_16 , V_8 = 0 ;
T_1 V_61 ;
T_4 V_129 [ 8 ] ;
if ( V_2 == V_4 -> V_105 )
V_61 = V_70 ;
else
V_61 = V_72 ;
F_31 ( & V_4 -> V_73 ) ;
F_50 (bit, indio_dev->active_scan_mask,
indio_dev->masklength) {
V_16 = F_28 ( V_4 , V_61 , V_128 ) ;
if ( V_16 < 0 ) {
F_32 ( & V_4 -> V_73 ) ;
goto V_130;
}
V_129 [ V_8 ++ ] = V_16 ;
}
F_32 ( & V_4 -> V_73 ) ;
F_51 ( V_2 , V_129 ) ;
V_130:
F_52 ( V_2 -> V_96 ) ;
return V_123 ;
}
static const char * F_53 ( struct V_14 * V_21 )
{
const struct V_131 * V_132 ;
V_132 = F_54 ( V_21 -> V_133 -> V_134 , V_21 ) ;
if ( ! V_132 )
return NULL ;
return F_55 ( V_21 ) ;
}
static int F_56 ( struct V_135 * V_19 , struct V_3 * V_4 )
{
struct V_14 * V_21 ;
struct V_136 * V_137 ;
int V_16 ;
if ( ! V_19 )
return - V_11 ;
V_21 = & V_19 -> V_21 ;
V_137 = F_57 ( V_21 , V_138 , 0 ) ;
if ( F_58 ( V_137 ) ) {
F_10 ( V_21 , L_19 ) ;
return F_59 ( V_137 ) ;
}
V_16 = F_60 ( V_137 ) ;
if ( V_16 )
return V_16 ;
V_16 = F_61 ( V_137 ) ;
F_62 ( V_21 , L_20 , F_63 ( V_137 ) , V_16 ) ;
return V_16 ;
}
static struct V_1 * F_64 ( struct V_3 * V_4 ,
const struct V_139 * V_87 ,
const struct V_64 * V_65 ,
int V_140 ,
const char * V_141 )
{
struct V_1 * V_2 ;
V_2 = F_65 ( & V_4 -> V_19 -> V_21 , sizeof( V_4 ) ) ;
if ( ! V_2 )
return F_66 ( - V_142 ) ;
F_1 ( V_2 , V_4 ) ;
V_2 -> V_21 . V_143 = & V_4 -> V_19 -> V_21 ;
V_2 -> V_144 = V_65 ;
V_2 -> V_140 = V_140 ;
V_2 -> V_141 = V_141 ;
V_2 -> V_145 = V_146 ;
V_2 -> V_87 = V_87 ;
return V_2 ;
}
static struct V_95 * F_67 ( struct V_3 * V_4 ,
struct V_1 * V_2 ,
const char * V_147 )
{
struct V_95 * V_96 ;
int V_16 ;
V_96 = F_68 ( & V_4 -> V_19 -> V_21 ,
L_21 ,
V_2 -> V_141 ,
V_147 ,
V_2 -> V_132 ) ;
if ( ! V_96 )
return F_66 ( - V_142 ) ;
V_96 -> V_21 . V_143 = & V_4 -> V_19 -> V_21 ;
V_96 -> V_148 = & V_149 ;
F_69 ( V_96 , V_2 ) ;
V_16 = F_70 ( V_96 ) ;
if ( V_16 )
return F_66 ( V_16 ) ;
return V_96 ;
}
static int F_71 ( struct V_135 * V_19 ,
const struct V_150 * V_132 )
{
int V_16 ;
struct V_3 * V_4 ;
const char * V_141 = NULL ;
V_4 = F_72 ( & V_19 -> V_21 , sizeof( * V_4 ) , V_151 ) ;
if ( ! V_4 )
return - V_142 ;
F_73 ( V_19 , V_4 ) ;
V_4 -> V_19 = V_19 ;
F_74 ( & V_4 -> V_73 ) ;
if ( V_132 )
V_141 = V_132 -> V_141 ;
else if ( F_75 ( & V_19 -> V_21 ) )
V_141 = F_53 ( & V_19 -> V_21 ) ;
else
return - V_152 ;
V_4 -> V_105 =
F_64 ( V_4 , & V_153 ,
V_154 ,
F_5 ( V_154 ) ,
V_141 ) ;
if ( F_58 ( V_4 -> V_105 ) )
return F_59 ( V_4 -> V_105 ) ;
V_4 -> V_155 =
F_64 ( V_4 , & V_156 ,
V_157 ,
F_5 ( V_157 ) ,
V_141 ) ;
if ( F_58 ( V_4 -> V_155 ) )
return F_59 ( V_4 -> V_155 ) ;
V_16 = F_18 ( V_4 ) ;
if ( V_16 < 0 )
return V_16 ;
if ( V_19 -> V_103 < 0 )
V_19 -> V_103 = F_56 ( V_19 , V_4 ) ;
if ( V_19 -> V_103 >= 0 ) {
V_16 = F_76 ( & V_19 -> V_21 , V_19 -> V_103 ,
F_47 ,
F_44 ,
V_158 ,
V_159 ,
V_4 ) ;
if ( V_16 )
goto V_160;
V_4 -> V_97 =
F_67 ( V_4 , V_4 -> V_105 ,
L_22 ) ;
if ( F_58 ( V_4 -> V_97 ) ) {
V_16 = F_59 ( V_4 -> V_97 ) ;
goto V_160;
}
V_4 -> V_99 =
F_67 ( V_4 , V_4 -> V_155 ,
L_22 ) ;
if ( F_58 ( V_4 -> V_99 ) ) {
V_16 = F_59 ( V_4 -> V_99 ) ;
goto V_161;
}
V_4 -> V_98 =
F_67 ( V_4 , V_4 -> V_105 ,
L_23 ) ;
if ( F_58 ( V_4 -> V_98 ) ) {
V_16 = F_59 ( V_4 -> V_98 ) ;
goto V_162;
}
V_16 = F_77 ( V_4 -> V_105 ,
& V_163 ,
F_49 ,
NULL ) ;
if ( V_16 < 0 ) {
F_10 ( & V_4 -> V_19 -> V_21 ,
L_24 ) ;
goto V_164;
}
V_16 = F_77 ( V_4 -> V_155 ,
& V_163 ,
F_49 ,
NULL ) ;
if ( V_16 < 0 ) {
F_10 ( & V_4 -> V_19 -> V_21 ,
L_25 ) ;
goto V_165;
}
}
V_16 = F_78 ( V_4 -> V_105 ) ;
if ( V_16 < 0 ) {
F_10 ( & V_19 -> V_21 , L_26 ) ;
goto V_166;
}
V_16 = F_78 ( V_4 -> V_155 ) ;
if ( V_16 < 0 ) {
F_10 ( & V_19 -> V_21 , L_27 ) ;
goto V_167;
}
V_16 = F_79 ( & V_19 -> V_21 ) ;
if ( V_16 < 0 )
goto V_168;
F_80 ( & V_19 -> V_21 ) ;
F_81 ( & V_19 -> V_21 , V_169 ) ;
F_82 ( & V_19 -> V_21 ) ;
return 0 ;
V_168:
F_83 ( V_4 -> V_155 ) ;
V_167:
F_83 ( V_4 -> V_105 ) ;
V_166:
if ( V_19 -> V_103 >= 0 )
F_84 ( V_4 -> V_155 ) ;
V_165:
if ( V_19 -> V_103 >= 0 )
F_84 ( V_4 -> V_105 ) ;
V_164:
F_85 ( V_4 -> V_98 ) ;
V_162:
F_85 ( V_4 -> V_99 ) ;
V_161:
F_85 ( V_4 -> V_97 ) ;
V_160:
F_8 ( V_4 , V_29 , V_22 | V_24 , true ) ;
return V_16 ;
}
static int F_86 ( struct V_135 * V_19 )
{
struct V_3 * V_4 = F_87 ( V_19 ) ;
F_88 ( & V_19 -> V_21 ) ;
F_89 ( & V_19 -> V_21 ) ;
F_27 ( & V_19 -> V_21 ) ;
F_83 ( V_4 -> V_105 ) ;
F_83 ( V_4 -> V_155 ) ;
if ( V_19 -> V_103 >= 0 ) {
F_84 ( V_4 -> V_105 ) ;
F_84 ( V_4 -> V_155 ) ;
F_85 ( V_4 -> V_97 ) ;
F_85 ( V_4 -> V_99 ) ;
F_85 ( V_4 -> V_98 ) ;
}
F_31 ( & V_4 -> V_73 ) ;
F_8 ( V_4 , V_29 , V_22 | V_24 , true ) ;
F_32 ( & V_4 -> V_73 ) ;
return 0 ;
}
static int F_90 ( struct V_14 * V_21 )
{
int V_16 ;
struct V_3 * V_4 = F_87 ( F_91 ( V_21 ) ) ;
F_31 ( & V_4 -> V_73 ) ;
V_16 = F_8 ( V_4 , V_29 , V_22 | V_24 ,
false ) ;
F_32 ( & V_4 -> V_73 ) ;
return V_16 ;
}
static int F_92 ( struct V_14 * V_21 )
{
T_1 V_170 = 0 ;
struct V_3 * V_4 = F_87 ( F_91 ( V_21 ) ) ;
if ( V_4 -> V_17 )
V_170 |= V_23 ;
if ( V_4 -> V_18 )
V_170 |= V_25 ;
return F_8 ( V_4 , V_170 , V_22 | V_24 , true ) ;
}
static int F_93 ( struct V_14 * V_21 )
{
struct V_3 * V_4 = F_87 ( F_91 ( V_21 ) ) ;
int V_16 ;
F_31 ( & V_4 -> V_73 ) ;
V_16 = F_8 ( V_4 , V_29 , V_22 | V_24 , true ) ;
F_32 ( & V_4 -> V_73 ) ;
return V_16 ;
}
static int F_94 ( struct V_14 * V_21 )
{
struct V_3 * V_4 = F_87 ( F_91 ( V_21 ) ) ;
T_1 V_170 = 0 ;
if ( ! V_4 -> V_59 )
V_170 |= V_23 ;
if ( ! V_4 -> V_60 )
V_170 |= V_25 ;
return F_8 ( V_4 , V_170 , V_22 | V_24 , true ) ;
}
