static T_1 F_1 ( int V_1 , void * V_2 )
{
struct V_3 * V_4 = V_2 ;
F_2 ( & V_4 -> F_2 ) ;
return V_5 ;
}
static int F_3 ( struct V_3 * V_4 , int V_6 )
{
T_2 V_7 [ 2 ] ;
int V_8 ;
F_4 ( & V_4 -> V_9 ) ;
F_5 ( V_4 -> V_10 , V_11 ,
( V_12 |
V_6 << V_13 ) ) ;
F_6 ( & V_4 -> F_2 ) ;
F_7 ( & V_4 -> F_2 , F_8 ( 5 ) ) ;
F_9 ( V_4 -> V_10 , V_14 , 2 , V_7 ) ;
F_10 ( & V_4 -> V_9 ) ;
if ( V_7 [ 1 ] & V_15 ) {
F_11 ( V_4 -> V_16 , L_1 ,
V_6 ) ;
return - V_17 ;
}
V_8 = ( V_7 [ 1 ] & V_18 ) >>
V_19 ;
V_8 |= V_7 [ 0 ] << V_20 ;
return V_8 ;
}
static inline int F_12 ( int V_21 )
{
return ( 6 * ( ( V_21 * 1000 ) + 500 ) ) / 1024 ;
}
static inline int F_13 ( int V_21 )
{
return ( 4 * ( ( V_21 * 1000 ) + 500 ) ) / 2048 ;
}
static inline int F_14 ( int V_21 )
{
return ( 21 * ( ( V_21 * 1000 ) + 500 ) ) / 1024 ;
}
static inline int F_15 ( int V_21 )
{
return ( 3 * ( ( V_21 * 1000 ) + 500 ) ) / 512 ;
}
static int F_16 ( struct V_3 * V_4 , int V_22 ,
int V_6 , int * V_23 )
{
int V_21 ;
V_21 = F_3 ( V_4 , V_6 ) ;
if ( V_21 < 0 )
return V_21 ;
switch ( V_22 ) {
case V_24 :
case V_25 :
case V_26 :
case V_27 :
* V_23 = F_12 ( V_21 ) ;
break;
case V_28 :
* V_23 = F_13 ( V_21 ) ;
break;
case V_29 :
* V_23 = F_14 ( V_21 ) ;
break;
case V_30 :
* V_23 = F_15 ( V_21 ) ;
break;
default:
* V_23 = V_21 ;
break;
}
return V_31 ;
}
static int F_17 ( int V_22 , int * V_23 , int * V_32 )
{
switch ( V_22 ) {
case V_33 :
* V_23 = 2932 ;
* V_32 = 1000 ;
return V_34 ;
case V_35 :
case V_36 :
* V_23 = 1000000 ;
* V_32 = 4420 ;
return V_34 ;
default:
return - V_37 ;
}
}
static int F_18 ( int V_22 , int * V_23 )
{
switch ( V_22 ) {
case V_33 :
* V_23 = 1500000 / 2932 ;
return V_31 ;
case V_35 :
case V_36 :
* V_23 = - 144 ;
return V_31 ;
default:
return - V_37 ;
}
}
static int F_19 ( struct V_38 * V_39 ,
struct V_40 const * V_41 ,
int * V_23 , int * V_32 , long V_42 )
{
struct V_3 * V_4 = F_20 ( V_39 ) ;
if ( ( V_41 -> V_22 < V_24 ) ||
( V_41 -> V_22 > V_36 ) )
return - V_37 ;
switch ( V_42 ) {
case V_43 :
case V_44 :
return F_16 ( V_4 , V_41 -> V_22 ,
V_41 -> V_45 , V_23 ) ;
case V_46 :
return F_17 ( V_41 -> V_22 , V_23 , V_32 ) ;
case V_47 :
return F_18 ( V_41 -> V_22 , V_23 ) ;
default:
return - V_37 ;
}
}
static int F_21 ( struct V_48 * V_49 )
{
struct V_50 * V_16 = & V_49 -> V_16 ;
struct V_10 * V_10 = F_22 ( V_16 -> V_51 ) ;
struct V_3 * V_4 ;
struct V_38 * V_39 ;
int V_1 , V_52 ;
V_39 = F_23 ( V_16 , sizeof( * V_4 ) ) ;
if ( ! V_39 ) {
F_11 ( & V_49 -> V_16 , L_2 ) ;
return - V_53 ;
}
V_4 = F_20 ( V_39 ) ;
F_24 ( V_49 , V_39 ) ;
V_4 -> V_10 = V_10 ;
V_4 -> V_16 = V_16 ;
F_25 ( & V_4 -> V_9 ) ;
F_26 ( & V_4 -> F_2 ) ;
V_1 = F_27 ( V_49 , L_3 ) ;
if ( V_1 < 0 ) {
F_11 ( V_16 , L_4 , V_1 ) ;
return V_1 ;
}
V_52 = F_28 ( V_16 , V_1 , NULL , F_1 ,
V_54 , L_3 , V_4 ) ;
if ( V_52 ) {
F_11 ( V_16 , L_5 , V_1 , V_52 ) ;
return V_52 ;
}
V_52 = F_29 ( V_39 , V_55 ) ;
if ( V_52 ) {
F_11 ( V_16 , L_6 , V_52 ) ;
return V_52 ;
}
V_39 -> V_56 = F_30 ( V_16 ) ;
V_39 -> V_16 . V_51 = V_16 ;
V_39 -> V_16 . V_57 = V_49 -> V_16 . V_57 ;
V_39 -> V_58 = & V_59 ;
V_39 -> V_60 = V_61 ;
V_39 -> V_62 = V_63 ;
V_39 -> V_64 = F_31 ( V_63 ) ;
V_52 = F_32 ( V_39 ) ;
if ( V_52 ) {
F_11 ( V_16 , L_7 , V_52 ) ;
goto V_65;
}
return 0 ;
V_65:
F_33 ( V_39 ) ;
return V_52 ;
}
static int F_34 ( struct V_48 * V_49 )
{
struct V_38 * V_39 = F_35 ( V_49 ) ;
F_36 ( V_39 ) ;
F_33 ( V_39 ) ;
return 0 ;
}
