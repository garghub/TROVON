static int F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
int V_4 ;
V_4 = F_2 ( V_2 -> V_5 , V_6 ,
V_7 ,
V_3 ) ;
if ( V_4 < 0 )
return V_4 ;
if ( V_3 & V_7 )
V_2 -> V_8 = true ;
else
V_2 -> V_8 = false ;
return 0 ;
}
static int F_3 ( struct V_1 * V_2 , T_1 V_3 )
{
int V_4 ;
V_4 = F_2 ( V_2 -> V_5 , V_6 ,
V_9 ,
V_3 ) ;
if ( V_4 < 0 )
return V_4 ;
if ( V_3 & V_9 )
V_2 -> V_10 = true ;
else
V_2 -> V_10 = false ;
return 0 ;
}
static int F_4 ( struct V_1 * V_2 , bool V_11 ,
T_1 V_12 )
{
#ifdef F_5
int V_4 ;
if ( V_12 & V_7 ) {
V_2 -> V_13 = V_11 ;
V_2 -> V_14 = ! V_11 ;
}
if ( V_12 & V_9 ) {
V_2 -> V_15 = V_11 ;
V_2 -> V_16 = ! V_11 ;
}
if ( V_11 ) {
V_4 = F_6 ( & V_2 -> V_17 -> V_18 ) ;
} else {
F_7 ( & V_2 -> V_17 -> V_18 ) ;
V_4 = F_8 ( & V_2 -> V_17 -> V_18 ) ;
}
if ( V_4 < 0 ) {
F_9 ( & V_2 -> V_17 -> V_18 ,
L_1 ,
V_11 , V_4 ) ;
if ( V_11 )
F_10 ( & V_2 -> V_17 -> V_18 ) ;
return V_4 ;
}
if ( V_11 ) {
if ( V_2 -> V_13 ) {
V_4 = F_1 ( V_2 , V_19 ) ;
if ( V_4 )
return V_4 ;
V_2 -> V_13 = false ;
}
if ( V_2 -> V_15 ) {
V_4 = F_3 ( V_2 , V_20 ) ;
if ( V_4 )
return V_4 ;
V_2 -> V_15 = false ;
}
}
#endif
return 0 ;
}
static int F_11 ( struct V_1 * V_2 , int V_21 ,
int * V_22 , int * V_23 )
{
int V_4 , V_24 , V_25 ;
V_4 = F_12 ( V_2 -> V_5 , V_26 [ V_21 ] . V_24 , & V_24 ) ;
if ( V_4 < 0 )
return V_4 ;
V_25 = ( V_26 [ V_21 ] . V_27 & V_24 ) >> V_26 [ V_21 ] . V_28 ;
* V_22 = V_26 [ V_21 ] . V_29 [ V_25 ] . V_30 ;
* V_23 = V_26 [ V_21 ] . V_29 [ V_25 ] . V_31 ;
return 0 ;
}
static int F_13 ( struct V_1 * V_2 , int V_21 ,
int V_22 , int V_23 )
{
int V_32 , V_25 = - V_33 ;
for ( V_32 = 0 ; V_32 < V_26 [ V_21 ] . V_34 ; V_32 ++ )
if ( V_22 == V_26 [ V_21 ] . V_29 [ V_32 ] . V_30 &&
V_23 == V_26 [ V_21 ] . V_29 [ V_32 ] . V_31 ) {
V_25 = V_32 ;
break;
}
if ( V_25 < 0 )
return V_25 ;
return F_2 ( V_2 -> V_5 , V_26 [ V_21 ] . V_24 ,
V_26 [ V_21 ] . V_27 ,
V_25 << V_26 [ V_21 ] . V_28 ) ;
}
static int F_14 ( struct V_1 * V_2 ,
enum V_35 V_36 ,
int * V_22 , int * V_23 )
{
int V_24 , V_4 ;
V_4 = F_12 ( V_2 -> V_5 , V_6 , & V_24 ) ;
if ( V_4 < 0 )
return V_4 ;
V_24 &= V_37 ;
if ( V_24 >= F_15 ( V_38 ) )
return - V_33 ;
switch ( V_36 ) {
case V_39 :
* V_22 = V_38 [ V_24 ] . V_40 ;
* V_23 = V_38 [ V_24 ] . V_41 ;
return 0 ;
case V_42 :
* V_22 = V_38 [ V_24 ] . V_43 ;
* V_23 = V_38 [ V_24 ] . V_44 ;
return 0 ;
default:
return - V_33 ;
}
}
static int F_16 ( struct V_1 * V_2 ,
enum V_35 V_36 ,
int V_22 , int V_23 )
{
int V_32 ;
switch ( V_22 ) {
case 0 :
V_32 = 0 ;
break;
case 2 :
if ( V_23 != 500000 )
return - V_33 ;
V_32 = 11 ;
break;
case 10 :
V_32 = 6 ;
break;
default:
return - V_33 ;
}
return F_2 ( V_2 -> V_5 ,
V_6 ,
V_37 ,
V_32 ) ;
}
static int F_17 ( struct V_1 * V_2 , int * V_45 )
{
int V_4 ;
T_2 V_46 ;
V_4 = F_18 ( V_2 -> V_5 ,
V_47 , & V_46 , sizeof( V_46 ) ) ;
if ( V_4 < 0 ) {
F_9 ( & V_2 -> V_17 -> V_18 , L_2 ) ;
return V_4 ;
}
* V_45 = F_19 ( V_46 ) ;
return V_4 ;
}
static int F_20 ( struct V_1 * V_2 , int V_45 )
{
int V_4 ;
T_2 V_46 ;
V_46 = F_21 ( V_45 & 0x3ff ) ;
V_4 = F_22 ( V_2 -> V_5 ,
V_47 , & V_46 , sizeof( V_46 ) ) ;
if ( V_4 < 0 ) {
F_9 ( & V_2 -> V_17 -> V_18 , L_3 ) ;
return V_4 ;
}
return V_4 ;
}
static int F_23 ( struct V_48 * V_49 ,
struct V_50 const * V_21 , int * V_22 ,
int * V_23 , long V_27 )
{
struct V_1 * V_2 = F_24 ( V_49 ) ;
int V_4 ;
T_1 V_12 ;
T_2 V_51 ;
switch ( V_27 ) {
case V_52 :
if ( V_21 -> type != V_39 && V_21 -> type != V_42 )
return - V_33 ;
V_12 = V_53 [ V_21 -> V_54 ] . V_12 ;
F_25 ( & V_2 -> V_55 ) ;
V_4 = F_4 ( V_2 , true , V_12 ) ;
if ( V_4 < 0 ) {
F_26 ( & V_2 -> V_55 ) ;
return V_4 ;
}
V_4 = F_18 ( V_2 -> V_5 ,
V_53 [ V_21 -> V_54 ] . V_54 ,
& V_51 , sizeof( V_51 ) ) ;
if ( V_4 < 0 ) {
F_4 ( V_2 , false , V_12 ) ;
F_26 ( & V_2 -> V_55 ) ;
return V_4 ;
}
V_4 = F_4 ( V_2 , false , V_12 ) ;
F_26 ( & V_2 -> V_55 ) ;
if ( V_4 < 0 )
return V_4 ;
* V_22 = F_19 ( V_51 ) ;
return V_56 ;
case V_57 :
F_25 ( & V_2 -> V_55 ) ;
V_4 = F_11 ( V_2 , V_21 -> V_54 , V_22 , V_23 ) ;
F_26 ( & V_2 -> V_55 ) ;
if ( V_4 < 0 )
return V_4 ;
return V_58 ;
case V_59 :
F_25 ( & V_2 -> V_55 ) ;
V_4 = F_14 ( V_2 , V_21 -> type , V_22 , V_23 ) ;
F_26 ( & V_2 -> V_55 ) ;
if ( V_4 < 0 )
return V_4 ;
return V_58 ;
case V_60 :
F_25 ( & V_2 -> V_55 ) ;
V_4 = F_17 ( V_2 , V_22 ) ;
F_26 ( & V_2 -> V_55 ) ;
if ( V_4 < 0 )
return V_4 ;
return V_56 ;
default:
return - V_33 ;
}
}
static int F_27 ( struct V_48 * V_49 ,
struct V_50 const * V_21 , int V_22 ,
int V_23 , long V_27 )
{
struct V_1 * V_2 = F_24 ( V_49 ) ;
int V_4 ;
switch ( V_27 ) {
case V_57 :
F_25 ( & V_2 -> V_55 ) ;
V_4 = F_13 ( V_2 , V_21 -> V_54 , V_22 , V_23 ) ;
F_26 ( & V_2 -> V_55 ) ;
return V_4 ;
case V_59 :
F_25 ( & V_2 -> V_55 ) ;
V_4 = F_16 ( V_2 , V_21 -> type ,
V_22 , V_23 ) ;
F_26 ( & V_2 -> V_55 ) ;
return V_4 ;
case V_60 :
F_25 ( & V_2 -> V_55 ) ;
V_4 = F_20 ( V_2 , V_22 ) ;
F_26 ( & V_2 -> V_55 ) ;
return V_4 ;
default:
return - V_33 ;
}
}
static int F_28 ( struct V_1 * V_2 )
{
int V_4 ;
int V_61 ;
V_4 = F_12 ( V_2 -> V_5 , V_62 , & V_61 ) ;
if ( V_4 < 0 ) {
F_9 ( & V_2 -> V_17 -> V_18 , L_4 ) ;
return V_4 ;
}
if ( V_61 != V_63 ) {
F_9 ( & V_2 -> V_17 -> V_18 , L_5 ,
V_61 , V_63 ) ;
return - V_64 ;
}
V_4 = F_2 ( V_2 -> V_5 , V_6 ,
V_37 ,
V_65 ) ;
if ( V_4 ) {
F_29 ( L_6 , V_4 ) ;
return V_4 ;
}
#ifndef F_5
V_4 = F_1 ( V_2 , V_19 ) ;
if ( V_4 < 0 )
return V_4 ;
V_4 = F_3 ( V_2 , V_20 ) ;
if ( V_4 < 0 )
return V_4 ;
#endif
return 0 ;
}
static int F_30 ( struct V_1 * V_2 )
{
int V_4 ;
V_4 = F_2 ( V_2 -> V_5 , V_6 ,
V_7 |
V_9 ,
V_66 |
V_67 ) ;
if ( V_4 < 0 )
return V_4 ;
V_2 -> V_8 = false ;
V_2 -> V_10 = false ;
return 0 ;
}
static bool F_31 ( struct V_68 * V_18 , unsigned int V_24 )
{
switch ( V_24 ) {
case V_6 :
case V_69 :
case V_70 :
return false ;
default:
return true ;
}
}
static int F_32 ( struct V_71 * V_17 ,
const struct V_72 * V_61 )
{
struct V_1 * V_2 ;
struct V_48 * V_49 ;
struct V_5 * V_5 ;
int V_4 ;
V_49 = F_33 ( & V_17 -> V_18 , sizeof( * V_2 ) ) ;
if ( ! V_49 )
return - V_73 ;
V_5 = F_34 ( V_17 , & V_74 ) ;
if ( F_35 ( V_5 ) ) {
F_9 ( & V_17 -> V_18 , L_7 ) ;
return F_36 ( V_5 ) ;
}
V_2 = F_24 ( V_49 ) ;
F_37 ( V_17 , V_49 ) ;
V_2 -> V_17 = V_17 ;
V_2 -> V_5 = V_5 ;
F_38 ( & V_2 -> V_55 ) ;
V_49 -> V_18 . V_75 = & V_17 -> V_18 ;
V_49 -> V_76 = & V_77 ;
V_49 -> V_78 = V_79 ;
V_49 -> V_80 = V_81 ;
V_49 -> V_82 = F_15 ( V_81 ) ;
V_49 -> V_83 = V_84 ;
V_4 = F_28 ( V_2 ) ;
if ( V_4 < 0 ) {
F_9 ( & V_17 -> V_18 , L_8 ) ;
return V_4 ;
}
V_4 = F_39 ( & V_17 -> V_18 ) ;
if ( V_4 < 0 )
goto V_85;
F_40 ( & V_17 -> V_18 ) ;
F_41 ( & V_17 -> V_18 , V_86 ) ;
F_42 ( & V_17 -> V_18 ) ;
V_4 = F_43 ( V_49 ) ;
if ( V_4 )
goto V_87;
return 0 ;
V_87:
F_44 ( & V_17 -> V_18 ) ;
F_45 ( & V_17 -> V_18 ) ;
F_10 ( & V_17 -> V_18 ) ;
V_85:
F_30 ( V_2 ) ;
return V_4 ;
}
static int F_46 ( struct V_71 * V_17 )
{
struct V_48 * V_49 = F_47 ( V_17 ) ;
F_48 ( V_49 ) ;
F_44 ( & V_17 -> V_18 ) ;
F_45 ( & V_17 -> V_18 ) ;
F_10 ( & V_17 -> V_18 ) ;
F_30 ( F_24 ( V_49 ) ) ;
return 0 ;
}
static int F_49 ( struct V_68 * V_18 )
{
struct V_48 * V_49 = F_47 ( F_50 ( V_18 ) ) ;
struct V_1 * V_2 = F_24 ( V_49 ) ;
int V_4 ;
F_25 ( & V_2 -> V_55 ) ;
if ( ! V_2 -> V_14 )
V_2 -> V_13 = V_2 -> V_8 ;
if ( ! V_2 -> V_16 )
V_2 -> V_15 = V_2 -> V_10 ;
V_4 = F_30 ( V_2 ) ;
F_51 ( V_2 -> V_5 ) ;
F_26 ( & V_2 -> V_55 ) ;
return V_4 ;
}
static int F_52 ( struct V_68 * V_18 )
{
struct V_48 * V_49 = F_47 ( F_50 ( V_18 ) ) ;
struct V_1 * V_2 = F_24 ( V_49 ) ;
int V_4 ;
F_53 ( V_2 -> V_5 ) ;
if ( V_2 -> V_13 ) {
V_4 = F_1 ( V_2 , V_19 ) ;
if ( V_4 < 0 )
return V_4 ;
V_2 -> V_13 = false ;
}
if ( V_2 -> V_15 ) {
V_4 = F_3 ( V_2 , V_20 ) ;
if ( V_4 < 0 )
return V_4 ;
V_2 -> V_15 = false ;
}
F_54 ( 100 ) ;
return 0 ;
}
