static int F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
int V_4 ;
V_4 = F_2 ( V_2 -> V_5 , V_6 ,
V_7 ,
V_3 ) ;
if ( V_4 < 0 )
return V_4 ;
V_2 -> V_8 = true ;
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
V_2 -> V_10 = true ;
return 0 ;
}
static int F_4 ( struct V_1 * V_2 , bool V_11 ,
T_1 V_12 )
{
#ifdef F_5
int V_4 ;
T_1 V_13 = 0 ;
if ( V_12 & V_7 ) {
if ( V_11 && ! V_2 -> V_14 && V_2 -> V_10 )
V_13 |= V_7 ;
else
V_2 -> V_14 = V_11 ;
}
if ( V_12 & V_9 ) {
if ( V_11 && ! V_2 -> V_15 && V_2 -> V_8 )
V_13 |= V_9 ;
else
V_2 -> V_15 = V_11 ;
}
if ( V_13 ) {
V_4 = F_2 ( V_2 -> V_5 , V_6 ,
V_13 , V_13 ) ;
if ( V_4 < 0 )
return V_4 ;
}
if ( V_11 ) {
V_4 = F_6 ( & V_2 -> V_16 -> V_17 ) ;
} else {
F_7 ( & V_2 -> V_16 -> V_17 ) ;
V_4 = F_8 ( & V_2 -> V_16 -> V_17 ) ;
}
if ( V_4 < 0 ) {
F_9 ( & V_2 -> V_16 -> V_17 ,
L_1 ,
V_11 , V_4 ) ;
if ( V_11 )
F_10 ( & V_2 -> V_16 -> V_17 ) ;
return V_4 ;
}
#endif
return 0 ;
}
static int F_11 ( struct V_1 * V_2 , int V_18 ,
int * V_19 , int * V_20 )
{
int V_4 , V_21 , V_22 ;
V_4 = F_12 ( V_2 -> V_5 , V_23 [ V_18 ] . V_21 , & V_21 ) ;
if ( V_4 < 0 )
return V_4 ;
V_22 = ( V_23 [ V_18 ] . V_24 & V_21 ) >> V_23 [ V_18 ] . V_25 ;
* V_19 = V_23 [ V_18 ] . V_26 [ V_22 ] . V_27 ;
* V_20 = V_23 [ V_18 ] . V_26 [ V_22 ] . V_28 ;
return 0 ;
}
static int F_13 ( struct V_1 * V_2 , int V_18 ,
int V_19 , int V_20 )
{
int V_29 , V_22 = - V_30 ;
for ( V_29 = 0 ; V_29 < V_23 [ V_18 ] . V_31 ; V_29 ++ )
if ( V_19 == V_23 [ V_18 ] . V_26 [ V_29 ] . V_27 &&
V_20 == V_23 [ V_18 ] . V_26 [ V_29 ] . V_28 ) {
V_22 = V_29 ;
break;
}
if ( V_22 < 0 )
return V_22 ;
return F_2 ( V_2 -> V_5 , V_23 [ V_18 ] . V_21 ,
V_23 [ V_18 ] . V_24 ,
V_22 << V_23 [ V_18 ] . V_25 ) ;
}
static int F_14 ( struct V_32 * V_33 ,
struct V_34 const * V_18 , int * V_19 ,
int * V_20 , long V_24 )
{
struct V_1 * V_2 = F_15 ( V_33 ) ;
int V_4 ;
T_1 V_12 ;
T_2 V_35 ;
switch ( V_24 ) {
case V_36 :
if ( V_18 -> type != V_37 && V_18 -> type != V_38 )
return - V_30 ;
V_12 = V_39 [ V_18 -> V_40 ] . V_12 ;
F_16 ( & V_2 -> V_41 ) ;
V_4 = F_4 ( V_2 , true , V_12 ) ;
if ( V_4 < 0 ) {
F_17 ( & V_2 -> V_41 ) ;
return V_4 ;
}
V_4 = F_18 ( V_2 -> V_5 ,
V_39 [ V_18 -> V_40 ] . V_40 ,
& V_35 , 2 ) ;
if ( V_4 < 0 ) {
F_4 ( V_2 , false , V_12 ) ;
F_17 ( & V_2 -> V_41 ) ;
return V_4 ;
}
V_4 = F_4 ( V_2 , false , V_12 ) ;
F_17 ( & V_2 -> V_41 ) ;
if ( V_4 < 0 )
return V_4 ;
* V_19 = F_19 ( V_35 ) ;
return V_42 ;
case V_43 :
F_16 ( & V_2 -> V_41 ) ;
V_4 = F_11 ( V_2 , V_18 -> V_40 , V_19 , V_20 ) ;
F_17 ( & V_2 -> V_41 ) ;
if ( V_4 < 0 )
return V_4 ;
return V_44 ;
default:
return - V_30 ;
}
}
static int F_20 ( struct V_32 * V_33 ,
struct V_34 const * V_18 , int V_19 ,
int V_20 , long V_24 )
{
struct V_1 * V_2 = F_15 ( V_33 ) ;
int V_4 ;
switch ( V_24 ) {
case V_43 :
F_16 ( & V_2 -> V_41 ) ;
V_4 = F_13 ( V_2 , V_18 -> V_40 , V_19 , V_20 ) ;
F_17 ( & V_2 -> V_41 ) ;
return V_4 ;
default:
return - V_30 ;
}
}
static int F_21 ( struct V_1 * V_2 )
{
int V_4 ;
int V_45 ;
V_4 = F_12 ( V_2 -> V_5 , V_46 , & V_45 ) ;
if ( V_4 < 0 ) {
F_9 ( & V_2 -> V_16 -> V_17 , L_2 ) ;
return V_4 ;
}
if ( V_45 != V_47 ) {
F_9 ( & V_2 -> V_16 -> V_17 , L_3 ,
V_45 , V_47 ) ;
return - V_48 ;
}
V_4 = F_2 ( V_2 -> V_5 , V_6 ,
V_49 ,
V_50 ) ;
if ( V_4 ) {
F_22 ( L_4 , V_4 ) ;
return V_4 ;
}
V_4 = F_1 ( V_2 , V_51 ) ;
if ( V_4 < 0 )
return V_4 ;
V_4 = F_3 ( V_2 , V_52 ) ;
if ( V_4 < 0 )
return V_4 ;
return 0 ;
}
static int F_23 ( struct V_1 * V_2 )
{
int V_4 ;
V_4 = F_2 ( V_2 -> V_5 , V_6 ,
V_7 |
V_9 ,
V_53 |
V_54 ) ;
if ( V_4 < 0 )
return V_4 ;
V_2 -> V_8 = false ;
V_2 -> V_10 = false ;
return 0 ;
}
static bool F_24 ( struct V_55 * V_17 , unsigned int V_21 )
{
switch ( V_21 ) {
case V_6 :
case V_56 :
case V_57 :
return false ;
default:
return true ;
}
}
static int F_25 ( struct V_58 * V_16 ,
const struct V_59 * V_45 )
{
struct V_1 * V_2 ;
struct V_32 * V_33 ;
struct V_5 * V_5 ;
int V_4 ;
V_33 = F_26 ( & V_16 -> V_17 , sizeof( * V_2 ) ) ;
if ( ! V_33 )
return - V_60 ;
V_5 = F_27 ( V_16 , & V_61 ) ;
if ( F_28 ( V_5 ) ) {
F_9 ( & V_16 -> V_17 , L_5 ) ;
return F_29 ( V_5 ) ;
}
V_2 = F_15 ( V_33 ) ;
F_30 ( V_16 , V_33 ) ;
V_2 -> V_16 = V_16 ;
V_2 -> V_5 = V_5 ;
F_31 ( & V_2 -> V_41 ) ;
V_33 -> V_17 . V_62 = & V_16 -> V_17 ;
V_33 -> V_63 = & V_64 ;
V_33 -> V_65 = V_66 ;
V_33 -> V_67 = V_68 ;
V_33 -> V_69 = F_32 ( V_68 ) ;
V_33 -> V_70 = V_71 ;
V_4 = F_21 ( V_2 ) ;
if ( V_4 < 0 ) {
F_9 ( & V_16 -> V_17 , L_6 ) ;
return V_4 ;
}
V_4 = F_33 ( & V_16 -> V_17 ) ;
if ( V_4 < 0 )
return V_4 ;
F_34 ( & V_16 -> V_17 ) ;
F_35 ( & V_16 -> V_17 , V_72 ) ;
F_36 ( & V_16 -> V_17 ) ;
return F_37 ( V_33 ) ;
}
static int F_38 ( struct V_58 * V_16 )
{
struct V_32 * V_33 = F_39 ( V_16 ) ;
F_40 ( V_33 ) ;
F_41 ( & V_16 -> V_17 ) ;
F_42 ( & V_16 -> V_17 ) ;
F_10 ( & V_16 -> V_17 ) ;
F_23 ( F_15 ( V_33 ) ) ;
return 0 ;
}
static int F_43 ( struct V_55 * V_17 )
{
struct V_32 * V_33 = F_39 ( F_44 ( V_17 ) ) ;
struct V_1 * V_2 = F_15 ( V_33 ) ;
int V_4 ;
F_16 ( & V_2 -> V_41 ) ;
V_4 = F_23 ( V_2 ) ;
F_17 ( & V_2 -> V_41 ) ;
return V_4 ;
}
static int F_45 ( struct V_55 * V_17 )
{
struct V_32 * V_33 = F_39 ( F_44 ( V_17 ) ) ;
struct V_1 * V_2 = F_15 ( V_33 ) ;
int V_4 ;
if ( V_2 -> V_14 ) {
V_4 = F_1 ( V_2 , V_51 ) ;
if ( V_4 < 0 )
return V_4 ;
V_2 -> V_14 = false ;
}
if ( V_2 -> V_15 ) {
V_4 = F_3 ( V_2 , V_52 ) ;
if ( V_4 < 0 )
return V_4 ;
V_2 -> V_15 = false ;
}
return 0 ;
}
