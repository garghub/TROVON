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
V_12 = F_2 ( V_6 | V_13 |
V_14 | V_2 -> V_7 ) ;
V_4 = F_7 ( V_2 -> V_8 , ( V_15 * ) & V_12 , 2 ) ;
if ( V_4 )
return V_4 ;
V_12 = 0 ;
V_4 = F_7 ( V_2 -> V_8 , ( V_15 * ) & V_12 , 2 ) ;
if ( V_4 )
return V_4 ;
F_8 ( 101 , 1000 ) ;
V_4 = F_9 ( V_2 -> V_8 , ( V_15 * ) & V_12 , 2 ) ;
if ( V_4 )
return V_4 ;
V_12 = F_5 ( V_12 ) & F_10 ( V_16 ) ;
if ( V_12 & ( 1 << ( V_16 - 1 ) ) ) {
V_12 = ( 4096 - V_12 ) * 250 ;
V_12 -= ( 2 * V_12 ) ;
} else {
V_12 *= 250 ;
}
* V_11 = V_12 ;
return 0 ;
}
static int F_11 ( struct V_17 * V_18 ,
struct V_19 const * V_20 ,
int * V_11 ,
int * V_21 ,
long V_22 )
{
int V_4 ;
struct V_1 * V_2 = F_12 ( V_18 ) ;
unsigned int V_23 ;
switch ( V_22 ) {
case 0 :
F_13 ( & V_18 -> V_24 ) ;
if ( F_14 ( V_18 ) ) {
if ( V_20 -> V_25 == V_26 )
V_4 = - V_27 ;
else
V_4 = F_15 ( V_18 ,
V_20 -> V_25 ) ;
} else {
if ( V_20 -> V_25 == V_26 )
V_4 = F_6 ( V_2 , V_11 ) ;
else
V_4 = F_1 ( V_2 , V_20 -> V_25 ) ;
}
F_16 ( & V_18 -> V_24 ) ;
if ( V_4 < 0 )
return V_4 ;
if ( V_20 -> V_25 != V_26 )
* V_11 = V_4 & F_10 ( V_16 ) ;
return V_28 ;
case ( 1 << V_29 ) :
V_23 = ( V_2 -> V_30 * 1000 ) >> V_16 ;
* V_11 = V_23 / 1000 ;
* V_21 = ( V_23 % 1000 ) * 1000 ;
return V_31 ;
case ( 1 << V_32 ) :
* V_11 = 1 ;
* V_21 = 0 ;
return V_31 ;
}
return - V_33 ;
}
static int T_1 F_17 ( struct V_34 * V_8 )
{
struct V_35 * V_36 = V_8 -> V_37 . V_38 ;
struct V_1 * V_2 ;
int V_4 , V_39 = 0 ;
struct V_17 * V_40 = F_18 ( sizeof( * V_2 ) ) ;
if ( V_40 == NULL )
return - V_41 ;
V_2 = F_12 ( V_40 ) ;
V_2 -> V_42 = F_19 ( & V_8 -> V_37 , L_1 ) ;
if ( ! F_20 ( V_2 -> V_42 ) ) {
V_4 = F_21 ( V_2 -> V_42 ) ;
if ( V_4 )
goto V_43;
}
F_22 ( V_8 , V_40 ) ;
V_2 -> V_8 = V_8 ;
V_40 -> V_44 = F_23 ( V_8 ) -> V_44 ;
V_40 -> V_37 . V_45 = & V_8 -> V_37 ;
V_40 -> V_46 = V_47 ;
V_40 -> V_48 = V_49 ;
V_40 -> V_50 = F_24 ( V_49 ) ;
V_40 -> V_51 = & V_52 ;
V_2 -> V_53 [ 0 ] . V_5 = & V_2 -> V_5 [ 0 ] ;
V_2 -> V_53 [ 0 ] . V_54 = 2 ;
V_2 -> V_53 [ 0 ] . V_55 = 1 ;
V_2 -> V_53 [ 1 ] . V_5 = & V_2 -> V_5 [ 1 ] ;
V_2 -> V_53 [ 1 ] . V_54 = 2 ;
V_2 -> V_53 [ 1 ] . V_55 = 1 ;
V_2 -> V_53 [ 2 ] . V_10 = & V_2 -> V_10 [ 0 ] ;
V_2 -> V_53 [ 2 ] . V_54 = 2 ;
F_25 ( & V_2 -> V_9 ) ;
F_26 ( & V_2 -> V_53 [ 0 ] , & V_2 -> V_9 ) ;
F_26 ( & V_2 -> V_53 [ 1 ] , & V_2 -> V_9 ) ;
F_26 ( & V_2 -> V_53 [ 2 ] , & V_2 -> V_9 ) ;
if ( V_36 && V_36 -> V_56 ) {
V_2 -> V_30 = V_36 -> V_56 ;
V_2 -> V_7 = V_57 ;
} else {
V_2 -> V_30 = V_58 ;
}
V_4 = F_27 ( V_40 ) ;
if ( V_4 )
goto V_59;
V_4 = F_28 ( V_40 ) ;
if ( V_4 )
goto V_59;
V_39 = 1 ;
V_4 = F_29 ( V_40 -> V_60 , 0 ,
& V_49 [ 1 ] ,
F_24 ( V_49 ) - 1 ) ;
if ( V_4 )
goto V_61;
return 0 ;
V_61:
F_30 ( V_40 ) ;
V_59:
if ( ! F_20 ( V_2 -> V_42 ) )
F_31 ( V_2 -> V_42 ) ;
V_43:
if ( ! F_20 ( V_2 -> V_42 ) )
F_32 ( V_2 -> V_42 ) ;
if ( V_39 )
F_33 ( V_40 ) ;
else
F_34 ( V_40 ) ;
return V_4 ;
}
static int T_2 F_35 ( struct V_34 * V_8 )
{
struct V_17 * V_40 = F_36 ( V_8 ) ;
struct V_1 * V_2 = F_12 ( V_40 ) ;
F_37 ( V_40 -> V_60 ) ;
F_30 ( V_40 ) ;
F_33 ( V_40 ) ;
if ( ! F_20 ( V_2 -> V_42 ) ) {
F_31 ( V_2 -> V_42 ) ;
F_32 ( V_2 -> V_42 ) ;
}
F_33 ( V_40 ) ;
return 0 ;
}
static int T_3 F_38 ( void )
{
return F_39 ( & V_62 ) ;
}
static void T_4 F_40 ( void )
{
F_41 ( & V_62 ) ;
}
