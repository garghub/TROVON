static int F_1 ( struct V_1 * V_2 )
{
if ( V_2 -> V_3 [ V_4 ] == 0 )
return 1 ;
return ! ! ( V_2 -> V_3 [ V_5 - 1 ] > 0 ) ;
}
static int F_2 ( struct V_1 * V_2 , T_1 V_6 )
{
struct V_7 * V_8 = V_2 -> V_8 ;
struct V_9 V_10 [ 2 ] ;
int V_11 ;
T_1 V_12 [ 3 ] = { V_6 , 0 , 0 } ;
V_10 [ 0 ] . V_13 = V_8 -> V_13 ;
V_10 [ 0 ] . V_14 = V_8 -> V_14 ;
V_10 [ 0 ] . V_15 = 3 ;
V_10 [ 0 ] . V_12 = ( char * ) & V_12 ;
V_10 [ 1 ] . V_13 = V_8 -> V_13 ;
V_10 [ 1 ] . V_14 = V_8 -> V_14 | V_16 ;
V_10 [ 1 ] . V_15 = V_5 ;
V_10 [ 1 ] . V_12 = ( char * ) & V_2 -> V_3 ;
V_11 = F_3 ( V_8 -> V_17 , V_10 , 2 ) ;
return ( V_11 == 2 ) ? 0 : V_11 ;
}
static int F_4 ( struct V_1 * V_2 , T_1 V_6 )
{
struct V_7 * V_8 = V_2 -> V_8 ;
int V_11 ;
int V_18 ;
V_11 = F_5 ( V_8 , V_6 , 0 ) ;
if ( V_11 < 0 )
return V_11 ;
for ( V_18 = 0 ; V_18 < V_5 ; V_18 ++ ) {
V_11 = F_6 ( V_8 ) ;
if ( V_11 < 0 )
return V_11 ;
V_2 -> V_3 [ V_18 ] = V_11 ;
}
return 0 ;
}
static int F_7 ( struct V_1 * V_2 )
{
int V_11 ;
if ( ! F_8 ( V_19 , V_2 -> V_20 + V_21 ) )
return 0 ;
V_11 = V_2 -> V_22 ( V_2 , V_23 ) ;
if ( V_11 < 0 )
return V_11 ;
V_11 = F_1 ( V_2 ) ;
if ( V_11 )
return - V_24 ;
V_2 -> V_20 = V_19 ;
return 0 ;
}
static int F_9 ( struct V_1 * V_2 )
{
T_1 * V_12 = & V_2 -> V_3 [ V_25 ] ;
return V_12 [ 0 ] | ( V_12 [ 1 ] << 8 ) ;
}
static int F_10 ( struct V_26 * V_27 ,
struct V_28 const * V_29 , int * V_30 ,
int * V_31 , long V_32 )
{
struct V_1 * V_2 = F_11 ( V_27 ) ;
int V_11 = - V_33 ;
switch ( V_32 ) {
case V_34 :
F_12 ( & V_2 -> V_35 ) ;
V_11 = F_7 ( V_2 ) ;
F_13 ( & V_2 -> V_35 ) ;
if ( V_11 )
return V_11 ;
switch ( V_29 -> V_36 ) {
case V_37 :
case V_4 :
case V_38 :
* V_30 = V_2 -> V_3 [ V_29 -> V_36 ] ;
return V_39 ;
case V_25 :
* V_30 = F_9 ( V_2 ) ;
return V_39 ;
default:
return - V_33 ;
}
break;
case V_40 :
switch ( V_29 -> type ) {
case V_41 :
* V_30 = 10 ;
return V_39 ;
default:
return - V_33 ;
}
break;
case V_42 :
switch ( V_29 -> V_36 ) {
case V_37 :
* V_30 = 44 ;
* V_31 = 250000 ;
return V_43 ;
case V_38 :
* V_30 = - 13 ;
return V_39 ;
default:
return - V_33 ;
}
}
return V_11 ;
}
static int F_14 ( struct V_7 * V_8 ,
const struct V_44 * V_45 )
{
struct V_26 * V_27 ;
struct V_1 * V_2 ;
V_27 = F_15 ( & V_8 -> V_46 , sizeof( * V_2 ) ) ;
if ( ! V_27 )
return - V_47 ;
V_2 = F_11 ( V_27 ) ;
if ( F_16 ( V_8 -> V_17 , V_48 ) )
V_2 -> V_22 = F_2 ;
else if ( F_16 ( V_8 -> V_17 ,
V_49 | V_50 ) )
V_2 -> V_22 = F_4 ;
else
return - V_51 ;
F_17 ( V_8 , V_27 ) ;
V_2 -> V_8 = V_8 ;
V_2 -> V_20 = V_19 - V_21 ;
F_18 ( & V_2 -> V_35 ) ;
V_27 -> V_46 . V_52 = & V_8 -> V_46 ;
V_27 -> V_53 = & V_54 ,
V_27 -> V_55 = F_19 ( & V_8 -> V_46 ) ;
V_27 -> V_56 = V_57 ;
V_27 -> V_58 = V_59 ;
V_27 -> V_60 = F_20 ( V_59 ) ;
return F_21 ( & V_8 -> V_46 , V_27 ) ;
}
