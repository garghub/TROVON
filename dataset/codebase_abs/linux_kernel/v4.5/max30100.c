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
while ( V_29 -- || ( V_29 = F_9 ( V_13 ) > 0 ) ) {
V_17 = F_11 ( V_13 ) ;
if ( V_17 )
break;
F_15 ( V_13 -> V_19 , V_13 -> V_26 ) ;
}
F_16 ( & V_13 -> V_30 ) ;
return V_31 ;
}
static int F_17 ( struct V_12 * V_13 )
{
int V_17 ;
V_17 = F_5 ( V_13 -> V_15 , V_32 ,
( V_33 <<
V_34 ) |
V_35 ) ;
if ( V_17 )
return V_17 ;
V_17 = F_5 ( V_13 -> V_15 , V_36 ,
V_37 |
V_38 ) ;
if ( V_17 )
return V_17 ;
V_17 = F_3 ( V_13 -> V_15 , V_5 ,
V_39 ,
V_40 |
V_41 ) ;
if ( V_17 )
return V_17 ;
return F_3 ( V_13 -> V_15 , V_42 ,
V_43 ,
V_44
<< V_45 ) ;
}
static int F_18 ( struct V_12 * V_13 , int * V_20 )
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
* V_20 = F_19 ( * V_20 , 11 ) ;
return 0 ;
}
static int F_20 ( struct V_12 * V_13 , int * V_20 )
{
int V_17 ;
V_17 = F_3 ( V_13 -> V_15 , V_5 ,
V_46 ,
V_46 ) ;
if ( V_17 )
return V_17 ;
F_21 ( 35000 , 50000 ) ;
return F_18 ( V_13 , V_20 ) ;
}
static int F_22 ( struct V_18 * V_19 ,
struct V_47 const * V_48 ,
int * V_20 , int * V_49 , long V_50 )
{
struct V_12 * V_13 = F_7 ( V_19 ) ;
int V_17 = - V_51 ;
switch ( V_50 ) {
case V_52 :
F_14 ( & V_19 -> V_53 ) ;
if ( ! F_23 ( V_19 ) )
V_17 = - V_54 ;
else {
V_17 = F_20 ( V_13 , V_20 ) ;
if ( ! V_17 )
V_17 = V_55 ;
}
F_16 ( & V_19 -> V_53 ) ;
break;
case V_56 :
* V_20 = 1 ;
* V_49 = 16 ;
V_17 = V_57 ;
break;
}
return V_17 ;
}
static int F_24 ( struct V_58 * V_23 ,
const struct V_59 * V_60 )
{
struct V_12 * V_13 ;
struct V_61 * V_26 ;
struct V_18 * V_19 ;
int V_17 ;
V_19 = F_25 ( & V_23 -> V_2 , sizeof( * V_13 ) ) ;
if ( ! V_19 )
return - V_62 ;
V_26 = F_26 ( & V_23 -> V_2 ) ;
if ( ! V_26 )
return - V_62 ;
F_27 ( V_19 , V_26 ) ;
V_19 -> V_63 = V_64 ;
V_19 -> V_65 = V_66 ;
V_19 -> V_67 = & V_68 ;
V_19 -> V_69 = F_28 ( V_66 ) ;
V_19 -> V_70 = V_71 ;
V_19 -> V_72 = ( V_73 | V_74 ) ;
V_19 -> V_75 = & V_76 ;
V_13 = F_7 ( V_19 ) ;
V_13 -> V_19 = V_19 ;
V_13 -> V_23 = V_23 ;
F_29 ( & V_13 -> V_30 ) ;
F_30 ( V_23 , V_19 ) ;
V_13 -> V_15 = F_31 ( V_23 , & V_77 ) ;
if ( F_32 ( V_13 -> V_15 ) ) {
F_33 ( & V_23 -> V_2 , L_1 ) ;
return F_34 ( V_13 -> V_15 ) ;
}
F_2 ( V_13 , false ) ;
V_17 = F_17 ( V_13 ) ;
if ( V_17 )
return V_17 ;
if ( V_23 -> V_27 <= 0 ) {
F_33 ( & V_23 -> V_2 , L_2 ) ;
return - V_51 ;
}
V_17 = F_35 ( & V_23 -> V_2 , V_23 -> V_27 ,
NULL , F_13 ,
V_78 | V_79 ,
L_3 , V_19 ) ;
if ( V_17 ) {
F_33 ( & V_23 -> V_2 , L_4 , V_23 -> V_27 ) ;
return V_17 ;
}
return F_36 ( V_19 ) ;
}
static int F_37 ( struct V_58 * V_23 )
{
struct V_18 * V_19 = F_38 ( V_23 ) ;
struct V_12 * V_13 = F_7 ( V_19 ) ;
F_39 ( V_19 ) ;
F_2 ( V_13 , false ) ;
return 0 ;
}
