static int F_1 ( struct V_1 * V_2 , unsigned V_3 )
{
int V_4 ;
V_2 -> V_5 [ 0 ] = F_2 ( V_6 | V_2 -> V_7 |
( F_3 ( 0 ) >> V_3 ) ) ;
V_4 = F_4 ( V_2 -> V_8 , & V_2 -> V_9 ) ;
if ( V_4 )
return V_4 ;
return F_5 ( V_2 -> V_10 [ 0 ] ) ;
}
static int F_6 ( struct V_1 * V_2 , int * V_11 )
{
int V_12 , V_4 ;
T_1 V_13 ;
V_13 = F_2 ( V_6 | V_14 |
V_15 | V_2 -> V_7 ) ;
V_4 = F_7 ( V_2 -> V_8 , ( V_16 * ) & V_13 , 2 ) ;
if ( V_4 )
return V_4 ;
V_13 = F_2 ( 0 ) ;
V_4 = F_7 ( V_2 -> V_8 , ( V_16 * ) & V_13 , 2 ) ;
if ( V_4 )
return V_4 ;
F_8 ( 101 , 1000 ) ;
V_4 = F_9 ( V_2 -> V_8 , ( V_16 * ) & V_13 , 2 ) ;
if ( V_4 )
return V_4 ;
V_12 = F_5 ( V_13 ) & F_10 ( V_17 ) ;
if ( V_12 & ( 1 << ( V_17 - 1 ) ) ) {
V_12 = ( 4096 - V_12 ) * 250 ;
V_12 -= ( 2 * V_12 ) ;
} else {
V_12 *= 250 ;
}
* V_11 = V_12 ;
return 0 ;
}
static int F_11 ( struct V_18 * V_19 ,
struct V_20 const * V_21 ,
int * V_11 ,
int * V_22 ,
long V_23 )
{
int V_4 ;
struct V_1 * V_2 = F_12 ( V_19 ) ;
unsigned int V_24 ;
switch ( V_23 ) {
case 0 :
F_13 ( & V_19 -> V_25 ) ;
if ( V_19 -> V_26 == V_27 ) {
V_4 = - V_28 ;
} else {
if ( V_21 -> V_29 == V_30 )
V_4 = F_6 ( V_2 , V_11 ) ;
else
V_4 = F_1 ( V_2 , V_21 -> V_29 ) ;
}
F_14 ( & V_19 -> V_25 ) ;
if ( V_4 < 0 )
return V_4 ;
if ( V_21 -> V_29 != V_30 )
* V_11 = V_4 & F_10 ( V_17 ) ;
return V_31 ;
case V_32 :
switch ( V_21 -> type ) {
case V_33 :
V_24 = ( V_2 -> V_34 * 1000 ) >> V_17 ;
* V_11 = V_24 / 1000 ;
* V_22 = ( V_24 % 1000 ) * 1000 ;
return V_35 ;
case V_36 :
* V_11 = 1 ;
* V_22 = 0 ;
return V_35 ;
default:
return - V_37 ;
}
}
return - V_37 ;
}
static int T_2 F_15 ( struct V_38 * V_8 )
{
struct V_39 * V_40 = V_8 -> V_41 . V_42 ;
struct V_1 * V_2 ;
int V_4 ;
struct V_18 * V_19 = F_16 ( sizeof( * V_2 ) ) ;
if ( V_19 == NULL )
return - V_43 ;
V_2 = F_12 ( V_19 ) ;
V_2 -> V_44 = F_17 ( & V_8 -> V_41 , L_1 ) ;
if ( ! F_18 ( V_2 -> V_44 ) ) {
V_4 = F_19 ( V_2 -> V_44 ) ;
if ( V_4 )
goto V_45;
}
F_20 ( V_8 , V_19 ) ;
V_2 -> V_8 = V_8 ;
V_19 -> V_46 = F_21 ( V_8 ) -> V_46 ;
V_19 -> V_41 . V_47 = & V_8 -> V_41 ;
V_19 -> V_48 = V_49 ;
V_19 -> V_50 = V_51 ;
V_19 -> V_52 = F_22 ( V_51 ) ;
V_19 -> V_53 = & V_54 ;
V_2 -> V_55 [ 0 ] . V_5 = & V_2 -> V_5 [ 0 ] ;
V_2 -> V_55 [ 0 ] . V_56 = 2 ;
V_2 -> V_55 [ 0 ] . V_57 = 1 ;
V_2 -> V_55 [ 1 ] . V_5 = & V_2 -> V_5 [ 1 ] ;
V_2 -> V_55 [ 1 ] . V_56 = 2 ;
V_2 -> V_55 [ 1 ] . V_57 = 1 ;
V_2 -> V_55 [ 2 ] . V_10 = & V_2 -> V_10 [ 0 ] ;
V_2 -> V_55 [ 2 ] . V_56 = 2 ;
F_23 ( & V_2 -> V_9 ) ;
F_24 ( & V_2 -> V_55 [ 0 ] , & V_2 -> V_9 ) ;
F_24 ( & V_2 -> V_55 [ 1 ] , & V_2 -> V_9 ) ;
F_24 ( & V_2 -> V_55 [ 2 ] , & V_2 -> V_9 ) ;
if ( V_40 && V_40 -> V_58 ) {
V_2 -> V_34 = V_40 -> V_58 ;
V_2 -> V_7 = V_59 ;
} else {
V_2 -> V_34 = V_60 ;
}
V_4 = F_25 ( V_19 ) ;
if ( V_4 )
goto V_61;
V_4 = F_26 ( V_19 ,
& V_51 [ 1 ] ,
F_22 ( V_51 ) - 1 ) ;
if ( V_4 )
goto V_62;
V_4 = F_27 ( V_19 ) ;
if ( V_4 )
goto V_63;
return 0 ;
V_63:
F_28 ( V_19 ) ;
V_62:
F_29 ( V_19 ) ;
V_61:
if ( ! F_18 ( V_2 -> V_44 ) )
F_30 ( V_2 -> V_44 ) ;
V_45:
if ( ! F_18 ( V_2 -> V_44 ) )
F_31 ( V_2 -> V_44 ) ;
F_32 ( V_19 ) ;
return V_4 ;
}
static int T_3 F_33 ( struct V_38 * V_8 )
{
struct V_18 * V_19 = F_34 ( V_8 ) ;
struct V_1 * V_2 = F_12 ( V_19 ) ;
F_35 ( V_19 ) ;
F_28 ( V_19 ) ;
F_29 ( V_19 ) ;
if ( ! F_18 ( V_2 -> V_44 ) ) {
F_30 ( V_2 -> V_44 ) ;
F_31 ( V_2 -> V_44 ) ;
}
F_32 ( V_19 ) ;
return 0 ;
}
