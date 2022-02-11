static int F_1 ( struct V_1 * V_2 , bool V_3 )
{
return F_2 ( V_2 -> V_4 , V_5 ,
V_6 ,
V_3 ? 0 : V_6 ) ;
}
static int F_3 ( struct V_7 * V_8 )
{
struct V_1 * V_2 = F_4 ( V_8 ) ;
return F_1 ( V_2 , true ) ;
}
static int F_5 ( struct V_7 * V_8 )
{
struct V_1 * V_2 = F_4 ( V_8 ) ;
return F_1 ( V_2 , false ) ;
}
static inline int F_6 ( struct V_1 * V_2 )
{
unsigned int V_9 ;
int V_10 ;
V_10 = F_7 ( V_2 -> V_4 , V_11 , & V_9 ) ;
if ( V_10 )
return V_10 ;
if ( V_9 & V_12 )
return 1 ;
return 0 ;
}
static int F_8 ( struct V_1 * V_2 )
{
int V_10 ;
T_1 * V_13 = ( T_1 * ) & V_2 -> V_13 ;
V_10 = F_9 ( V_2 -> V_14 ,
V_15 ,
V_16 ,
V_13 ) ;
memcpy ( & V_2 -> V_17 [ 0 ] , & V_13 [ 0 ] , 3 ) ;
memcpy ( & V_2 -> V_17 [ 1 ] , & V_13 [ 3 ] , 3 ) ;
return ( V_10 == V_16 ) ? 0 : - V_18 ;
}
static T_2 F_10 ( int V_19 , void * V_20 )
{
struct V_7 * V_8 = V_20 ;
struct V_1 * V_2 = F_4 ( V_8 ) ;
int V_10 , V_21 = 0 ;
F_11 ( & V_2 -> V_22 ) ;
while ( V_21 || ( V_21 = F_6 ( V_2 ) ) > 0 ) {
V_10 = F_8 ( V_2 ) ;
if ( V_10 )
break;
F_12 ( V_2 -> V_8 , V_2 -> V_17 ) ;
V_21 -- ;
}
F_13 ( & V_2 -> V_22 ) ;
return V_23 ;
}
static int F_14 ( unsigned int V_9 , int * V_24 )
{
* V_24 = V_9 / 200 ;
return * V_24 > 0xff ? - V_18 : 0 ;
}
static int F_15 ( struct V_1 * V_2 )
{
struct V_25 * V_26 = & V_2 -> V_14 -> V_26 ;
struct V_27 * V_28 = V_26 -> V_29 ;
unsigned int V_9 ;
int V_24 , V_10 ;
V_10 = F_16 ( V_28 , L_1 , & V_9 ) ;
if ( V_10 ) {
F_17 ( V_26 , L_2 ) ;
V_9 = 7000 ;
}
V_10 = F_14 ( V_9 , & V_24 ) ;
if ( V_10 ) {
F_18 ( V_26 , L_3 , V_9 ) ;
return V_10 ;
}
V_10 = F_19 ( V_2 -> V_4 , V_30 , V_24 ) ;
if ( V_10 )
return V_10 ;
V_10 = F_16 ( V_28 , L_4 , & V_9 ) ;
if ( V_10 ) {
F_17 ( V_26 , L_5 ) ;
V_9 = 7000 ;
}
V_10 = F_14 ( V_9 , & V_24 ) ;
if ( V_10 ) {
F_18 ( V_26 , L_6 , V_9 ) ;
return V_10 ;
}
return F_19 ( V_2 -> V_4 , V_31 , V_24 ) ;
}
static int F_20 ( struct V_1 * V_2 )
{
int V_10 ;
V_10 = F_15 ( V_2 ) ;
if ( V_10 )
return V_10 ;
V_10 = F_19 ( V_2 -> V_4 , V_32 ,
( V_33
<< V_34 ) |
( V_35
<< V_36 ) |
V_37 ) ;
if ( V_10 )
return V_10 ;
V_10 = F_2 ( V_2 -> V_4 , V_5 ,
V_38 ,
V_39 |
V_40 ) ;
if ( V_10 )
return V_10 ;
V_10 = F_19 ( V_2 -> V_4 , V_41 ,
( V_42
<< V_43 ) |
V_44 ) ;
if ( V_10 )
return V_10 ;
return F_2 ( V_2 -> V_4 , V_45 ,
V_46 ,
V_47 ) ;
}
static int F_21 ( struct V_1 * V_2 , int * V_9 )
{
int V_10 ;
unsigned int V_24 ;
V_10 = F_7 ( V_2 -> V_4 , V_48 , & V_24 ) ;
if ( V_10 < 0 )
return V_10 ;
* V_9 = V_24 << 4 ;
V_10 = F_7 ( V_2 -> V_4 , V_49 , & V_24 ) ;
if ( V_10 < 0 )
return V_10 ;
* V_9 |= V_24 & 0xf ;
* V_9 = F_22 ( * V_9 , 11 ) ;
return 0 ;
}
static int F_23 ( struct V_1 * V_2 , int * V_9 )
{
int V_10 ;
V_10 = F_2 ( V_2 -> V_4 , V_50 ,
V_51 ,
V_51 ) ;
if ( V_10 )
return V_10 ;
F_24 ( 35 ) ;
return F_21 ( V_2 , V_9 ) ;
}
static int F_25 ( struct V_7 * V_8 ,
struct V_52 const * V_53 ,
int * V_9 , int * V_54 , long V_55 )
{
struct V_1 * V_2 = F_4 ( V_8 ) ;
int V_10 = - V_18 ;
switch ( V_55 ) {
case V_56 :
F_11 ( & V_8 -> V_57 ) ;
if ( ! F_26 ( V_8 ) )
V_10 = - V_58 ;
else {
V_10 = F_23 ( V_2 , V_9 ) ;
if ( ! V_10 )
V_10 = V_59 ;
}
F_13 ( & V_8 -> V_57 ) ;
break;
case V_60 :
* V_9 = 1 ;
* V_54 = 16 ;
V_10 = V_61 ;
break;
}
return V_10 ;
}
static int F_27 ( struct V_62 * V_14 ,
const struct V_63 * V_64 )
{
struct V_1 * V_2 ;
struct V_65 * V_13 ;
struct V_7 * V_8 ;
int V_10 ;
V_8 = F_28 ( & V_14 -> V_26 , sizeof( * V_2 ) ) ;
if ( ! V_8 )
return - V_66 ;
V_13 = F_29 ( & V_14 -> V_26 ) ;
if ( ! V_13 )
return - V_66 ;
F_30 ( V_8 , V_13 ) ;
V_8 -> V_67 = V_68 ;
V_8 -> V_69 = V_70 ;
V_8 -> V_71 = & V_72 ;
V_8 -> V_73 = F_31 ( V_70 ) ;
V_8 -> V_74 = V_75 ;
V_8 -> V_76 = ( V_77 | V_78 ) ;
V_8 -> V_79 = & V_80 ;
V_8 -> V_26 . V_81 = & V_14 -> V_26 ;
V_2 = F_4 ( V_8 ) ;
V_2 -> V_8 = V_8 ;
V_2 -> V_14 = V_14 ;
F_32 ( & V_2 -> V_22 ) ;
F_33 ( V_14 , V_8 ) ;
V_2 -> V_4 = F_34 ( V_14 , & V_82 ) ;
if ( F_35 ( V_2 -> V_4 ) ) {
F_18 ( & V_14 -> V_26 , L_7 ) ;
return F_36 ( V_2 -> V_4 ) ;
}
F_1 ( V_2 , false ) ;
V_10 = F_20 ( V_2 ) ;
if ( V_10 )
return V_10 ;
if ( V_14 -> V_19 <= 0 ) {
F_18 ( & V_14 -> V_26 , L_8 ) ;
return - V_18 ;
}
V_10 = F_37 ( & V_14 -> V_26 , V_14 -> V_19 ,
NULL , F_10 ,
V_83 | V_84 ,
L_9 , V_8 ) ;
if ( V_10 ) {
F_18 ( & V_14 -> V_26 , L_10 , V_14 -> V_19 ) ;
return V_10 ;
}
return F_38 ( V_8 ) ;
}
static int F_39 ( struct V_62 * V_14 )
{
struct V_7 * V_8 = F_40 ( V_14 ) ;
struct V_1 * V_2 = F_4 ( V_8 ) ;
F_41 ( V_8 ) ;
F_1 ( V_2 , false ) ;
return 0 ;
}
