static bool F_1 ( struct V_1 * V_2 , unsigned int V_3 )
{
switch ( V_3 ) {
case V_4 :
case V_5 :
case V_6 :
case V_7 :
case V_8 :
case V_9 :
case V_10 :
case V_11 :
return true ;
default:
return false ;
}
}
static int F_2 ( struct V_12 * V_13 , bool V_14 )
{
return F_3 ( V_13 -> V_15 , V_5 ,
V_16 ,
V_14 ? 0 : V_16 ) ;
}
static int F_4 ( struct V_12 * V_13 )
{
int V_17 ;
V_17 = F_5 ( V_13 -> V_15 , V_6 , 0 ) ;
if ( V_17 )
return V_17 ;
V_17 = F_5 ( V_13 -> V_15 , V_7 , 0 ) ;
if ( V_17 )
return V_17 ;
return F_5 ( V_13 -> V_15 , V_8 , 0 ) ;
}
static int F_6 ( struct V_18 * V_19 )
{
struct V_12 * V_13 = F_7 ( V_19 ) ;
int V_17 ;
V_17 = F_2 ( V_13 , true ) ;
if ( V_17 )
return V_17 ;
return F_4 ( V_13 ) ;
}
static int F_8 ( struct V_18 * V_19 )
{
struct V_12 * V_13 = F_7 ( V_19 ) ;
return F_2 ( V_13 , false ) ;
}
static inline int F_9 ( struct V_12 * V_13 )
{
unsigned int V_20 ;
int V_17 ;
V_17 = F_10 ( V_13 -> V_15 , V_4 , & V_20 ) ;
if ( V_17 )
return V_17 ;
if ( V_20 & V_21 )
return V_22 - 1 ;
return 0 ;
}
static int F_11 ( struct V_12 * V_13 )
{
int V_17 ;
V_17 = F_12 ( V_13 -> V_23 ,
V_9 ,
V_24 ,
( V_25 * ) & V_13 -> V_26 ) ;
return ( V_17 == V_24 ) ? 0 : V_17 ;
}
static T_1 F_13 ( int V_27 , void * V_28 )
{
struct V_18 * V_19 = V_28 ;
struct V_12 * V_13 = F_7 ( V_19 ) ;
int V_17 , V_29 = 0 ;
F_14 ( & V_13 -> V_30 ) ;
while ( V_29 || ( V_29 = F_9 ( V_13 ) ) > 0 ) {
V_17 = F_11 ( V_13 ) ;
if ( V_17 )
break;
F_15 ( V_13 -> V_19 , V_13 -> V_26 ) ;
V_29 -- ;
}
F_16 ( & V_13 -> V_30 ) ;
return V_31 ;
}
static int F_17 ( unsigned int V_20 , int * V_3 )
{
int V_32 ;
if ( V_20 == 0 ) {
* V_3 = 0 ;
return 0 ;
}
for ( V_32 = 0 ; V_32 < F_18 ( V_33 ) ; V_32 ++ ) {
if ( V_33 [ V_32 ] == V_20 ) {
* V_3 = V_32 + 1 ;
return 0 ;
}
}
return - V_34 ;
}
static int F_19 ( struct V_12 * V_13 )
{
struct V_1 * V_2 = & V_13 -> V_23 -> V_2 ;
struct V_35 * V_36 = V_2 -> V_37 ;
unsigned int V_20 [ 2 ] ;
int V_3 , V_17 ;
V_17 = F_20 ( V_36 , L_1 ,
( unsigned int * ) & V_20 , 2 ) ;
if ( V_17 ) {
V_3 = ( V_38 <<
V_39 ) |
V_40 ;
F_21 ( V_2 , L_2 ) ;
return F_5 ( V_13 -> V_15 , V_41 , V_3 ) ;
}
V_17 = F_17 ( V_20 [ 0 ] , & V_3 ) ;
if ( V_17 ) {
F_22 ( V_2 , L_3 , V_20 [ 0 ] ) ;
return V_17 ;
}
V_17 = F_3 ( V_13 -> V_15 , V_41 ,
V_42 <<
V_39 ,
V_3 << V_39 ) ;
if ( V_17 )
return V_17 ;
V_17 = F_17 ( V_20 [ 1 ] , & V_3 ) ;
if ( V_17 ) {
F_22 ( V_2 , L_4 , V_20 [ 1 ] ) ;
return V_17 ;
}
return F_3 ( V_13 -> V_15 , V_41 ,
V_42 , V_3 ) ;
}
static int F_23 ( struct V_12 * V_13 )
{
int V_17 ;
V_17 = F_19 ( V_13 ) ;
if ( V_17 )
return V_17 ;
V_17 = F_5 ( V_13 -> V_15 , V_43 ,
V_44 |
V_45 ) ;
if ( V_17 )
return V_17 ;
V_17 = F_3 ( V_13 -> V_15 , V_5 ,
V_46 ,
V_47 |
V_48 ) ;
if ( V_17 )
return V_17 ;
return F_3 ( V_13 -> V_15 , V_49 ,
V_50 ,
V_51
<< V_52 ) ;
}
static int F_24 ( struct V_12 * V_13 , int * V_20 )
{
int V_17 ;
unsigned int V_3 ;
V_17 = F_10 ( V_13 -> V_15 , V_10 , & V_3 ) ;
if ( V_17 < 0 )
return V_17 ;
* V_20 = V_3 << 4 ;
V_17 = F_10 ( V_13 -> V_15 , V_11 , & V_3 ) ;
if ( V_17 < 0 )
return V_17 ;
* V_20 |= V_3 & 0xf ;
* V_20 = F_25 ( * V_20 , 11 ) ;
return 0 ;
}
static int F_26 ( struct V_12 * V_13 , int * V_20 )
{
int V_17 ;
V_17 = F_3 ( V_13 -> V_15 , V_5 ,
V_53 ,
V_53 ) ;
if ( V_17 )
return V_17 ;
F_27 ( 35 ) ;
return F_24 ( V_13 , V_20 ) ;
}
static int F_28 ( struct V_18 * V_19 ,
struct V_54 const * V_55 ,
int * V_20 , int * V_56 , long V_57 )
{
struct V_12 * V_13 = F_7 ( V_19 ) ;
int V_17 = - V_34 ;
switch ( V_57 ) {
case V_58 :
F_14 ( & V_19 -> V_59 ) ;
if ( ! F_29 ( V_19 ) )
V_17 = - V_60 ;
else {
V_17 = F_26 ( V_13 , V_20 ) ;
if ( ! V_17 )
V_17 = V_61 ;
}
F_16 ( & V_19 -> V_59 ) ;
break;
case V_62 :
* V_20 = 1 ;
* V_56 = 16 ;
V_17 = V_63 ;
break;
}
return V_17 ;
}
static int F_30 ( struct V_64 * V_23 ,
const struct V_65 * V_66 )
{
struct V_12 * V_13 ;
struct V_67 * V_26 ;
struct V_18 * V_19 ;
int V_17 ;
V_19 = F_31 ( & V_23 -> V_2 , sizeof( * V_13 ) ) ;
if ( ! V_19 )
return - V_68 ;
V_26 = F_32 ( & V_23 -> V_2 ) ;
if ( ! V_26 )
return - V_68 ;
F_33 ( V_19 , V_26 ) ;
V_19 -> V_69 = V_70 ;
V_19 -> V_71 = V_72 ;
V_19 -> V_73 = & V_74 ;
V_19 -> V_75 = F_18 ( V_72 ) ;
V_19 -> V_76 = V_77 ;
V_19 -> V_78 = ( V_79 | V_80 ) ;
V_19 -> V_81 = & V_82 ;
V_13 = F_7 ( V_19 ) ;
V_13 -> V_19 = V_19 ;
V_13 -> V_23 = V_23 ;
F_34 ( & V_13 -> V_30 ) ;
F_35 ( V_23 , V_19 ) ;
V_13 -> V_15 = F_36 ( V_23 , & V_83 ) ;
if ( F_37 ( V_13 -> V_15 ) ) {
F_22 ( & V_23 -> V_2 , L_5 ) ;
return F_38 ( V_13 -> V_15 ) ;
}
F_2 ( V_13 , false ) ;
V_17 = F_23 ( V_13 ) ;
if ( V_17 )
return V_17 ;
if ( V_23 -> V_27 <= 0 ) {
F_22 ( & V_23 -> V_2 , L_6 ) ;
return - V_34 ;
}
V_17 = F_39 ( & V_23 -> V_2 , V_23 -> V_27 ,
NULL , F_13 ,
V_84 | V_85 ,
L_7 , V_19 ) ;
if ( V_17 ) {
F_22 ( & V_23 -> V_2 , L_8 , V_23 -> V_27 ) ;
return V_17 ;
}
return F_40 ( V_19 ) ;
}
static int F_41 ( struct V_64 * V_23 )
{
struct V_18 * V_19 = F_42 ( V_23 ) ;
struct V_12 * V_13 = F_7 ( V_19 ) ;
F_43 ( V_19 ) ;
F_2 ( V_13 , false ) ;
return 0 ;
}
