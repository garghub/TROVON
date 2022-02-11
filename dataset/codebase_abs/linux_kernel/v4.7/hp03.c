static bool F_1 ( struct V_1 * V_2 , unsigned int V_3 )
{
return false ;
}
static bool F_2 ( struct V_1 * V_2 , unsigned int V_3 )
{
return false ;
}
static int F_3 ( struct V_4 * V_5 , const T_1 V_3 )
{
int V_6 ;
V_6 = F_4 ( V_5 -> V_7 , V_8 , V_3 ) ;
if ( V_6 < 0 )
return V_6 ;
F_5 ( 50 ) ;
return F_6 ( V_5 -> V_7 , V_9 ) ;
}
static int F_7 ( struct V_4 * V_5 )
{
struct V_1 * V_2 = & V_5 -> V_7 -> V_2 ;
T_1 V_10 [ 18 ] ;
T_2 V_11 [ 7 ] ;
int V_12 , V_13 , V_14 , V_15 , V_16 , V_17 , V_18 , V_19 ;
int V_20 , V_6 ;
V_6 = F_8 ( V_5 -> V_21 , V_22 ,
V_10 , sizeof( V_10 ) ) ;
if ( V_6 < 0 ) {
F_9 ( V_2 , L_1 ,
V_22 ) ;
return V_6 ;
}
F_10 ( V_5 -> V_23 , 1 ) ;
V_6 = F_3 ( V_5 , V_24 ) ;
if ( V_6 < 0 ) {
F_9 ( V_2 , L_2 ) ;
goto V_25;
}
V_13 = V_6 ;
V_6 = F_3 ( V_5 , V_26 ) ;
if ( V_6 < 0 ) {
F_9 ( V_2 , L_3 ) ;
goto V_25;
}
V_14 = V_6 ;
F_10 ( V_5 -> V_23 , 0 ) ;
for ( V_20 = 0 ; V_20 < 7 ; V_20 ++ )
V_11 [ V_20 ] = ( V_10 [ 2 * V_20 ] << 8 ) | ( V_10 [ ( 2 * V_20 ) + 1 ] << 0 ) ;
V_13 = ( ( V_13 >> 8 ) & 0xff ) | ( ( V_13 & 0xff ) << 8 ) ;
V_14 = ( ( V_14 >> 8 ) & 0xff ) | ( ( V_14 & 0xff ) << 8 ) ;
if ( V_14 >= V_11 [ 4 ] )
V_12 = V_10 [ 14 ] ;
else
V_12 = V_10 [ 15 ] ;
V_15 = V_14 - V_11 [ 4 ] ;
V_16 = ( V_12 * ( V_15 >> 7 ) * ( V_15 >> 7 ) ) >> V_10 [ 16 ] ;
V_16 = V_15 - V_16 ;
V_17 = ( V_11 [ 1 ] + ( ( ( V_11 [ 3 ] - 1024 ) * V_16 ) >> 14 ) ) * 4 ;
V_18 = V_11 [ 0 ] + ( ( V_11 [ 2 ] * V_16 ) >> 10 ) ;
V_19 = ( ( V_18 * ( V_13 - 7168 ) ) >> 14 ) - V_17 ;
V_5 -> V_27 = ( ( V_19 * 100 ) >> 5 ) + ( V_11 [ 6 ] * 10 ) ;
V_5 -> V_28 = 250 + ( ( V_16 * V_11 [ 5 ] ) >> 16 ) - ( V_16 >> V_10 [ 17 ] ) ;
return 0 ;
V_25:
F_10 ( V_5 -> V_23 , 0 ) ;
return V_6 ;
}
static int F_11 ( struct V_29 * V_30 ,
struct V_31 const * V_32 ,
int * V_33 , int * V_34 , long V_35 )
{
struct V_4 * V_5 = F_12 ( V_30 ) ;
int V_6 ;
F_13 ( & V_5 -> V_36 ) ;
V_6 = F_7 ( V_5 ) ;
F_14 ( & V_5 -> V_36 ) ;
if ( V_6 )
return V_6 ;
switch ( V_35 ) {
case V_37 :
switch ( V_32 -> type ) {
case V_38 :
* V_33 = V_5 -> V_27 ;
return V_39 ;
case V_40 :
* V_33 = V_5 -> V_28 ;
return V_39 ;
default:
return - V_41 ;
}
break;
case V_42 :
switch ( V_32 -> type ) {
case V_38 :
* V_33 = 0 ;
* V_34 = 1000 ;
return V_43 ;
case V_40 :
* V_33 = 10 ;
return V_39 ;
default:
return - V_41 ;
}
break;
default:
return - V_41 ;
}
return - V_41 ;
}
static int F_15 ( struct V_44 * V_7 ,
const struct V_45 * V_46 )
{
struct V_1 * V_2 = & V_7 -> V_2 ;
struct V_29 * V_30 ;
struct V_4 * V_5 ;
int V_6 ;
V_30 = F_16 ( V_2 , sizeof( * V_5 ) ) ;
if ( ! V_30 )
return - V_47 ;
V_5 = F_12 ( V_30 ) ;
V_5 -> V_7 = V_7 ;
F_17 ( & V_5 -> V_36 ) ;
V_30 -> V_2 . V_48 = V_2 ;
V_30 -> V_49 = V_46 -> V_49 ;
V_30 -> V_50 = V_51 ;
V_30 -> V_52 = F_18 ( V_51 ) ;
V_30 -> V_53 = & V_54 ;
V_30 -> V_55 = V_56 ;
V_5 -> V_23 = F_19 ( V_2 , L_4 , 0 , V_57 ) ;
if ( F_20 ( V_5 -> V_23 ) ) {
F_9 ( V_2 , L_5 ) ;
V_6 = F_21 ( V_5 -> V_23 ) ;
return V_6 ;
}
V_5 -> V_58 = F_22 ( V_7 -> V_59 , V_60 ) ;
if ( ! V_5 -> V_58 ) {
F_9 ( V_2 , L_6 ) ;
return - V_61 ;
}
V_5 -> V_21 = F_23 ( V_5 -> V_58 ,
& V_62 ) ;
if ( F_20 ( V_5 -> V_21 ) ) {
F_9 ( V_2 , L_7 ) ;
V_6 = F_21 ( V_5 -> V_21 ) ;
goto V_63;
}
V_6 = F_24 ( V_30 ) ;
if ( V_6 ) {
F_9 ( V_2 , L_8 ) ;
goto V_64;
}
F_25 ( V_7 , V_30 ) ;
return 0 ;
V_64:
F_26 ( V_5 -> V_21 ) ;
V_63:
F_27 ( V_5 -> V_58 ) ;
return V_6 ;
}
static int F_28 ( struct V_44 * V_7 )
{
struct V_29 * V_30 = F_29 ( V_7 ) ;
struct V_4 * V_5 = F_12 ( V_30 ) ;
F_30 ( V_30 ) ;
F_26 ( V_5 -> V_21 ) ;
F_27 ( V_5 -> V_58 ) ;
return 0 ;
}
