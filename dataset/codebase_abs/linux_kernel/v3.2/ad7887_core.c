static int F_1 ( struct V_1 * V_2 , unsigned V_3 )
{
int V_4 = F_2 ( V_2 -> V_5 , & V_2 -> V_6 [ V_3 ] ) ;
if ( V_4 )
return V_4 ;
return ( V_2 -> V_7 [ ( V_3 * 2 ) ] << 8 ) | V_2 -> V_7 [ ( V_3 * 2 ) + 1 ] ;
}
static int F_3 ( struct V_8 * V_9 ,
struct V_10 const * V_11 ,
int * V_12 ,
int * V_13 ,
long V_14 )
{
int V_4 ;
struct V_1 * V_2 = F_4 ( V_9 ) ;
unsigned int V_15 ;
switch ( V_14 ) {
case 0 :
F_5 ( & V_9 -> V_16 ) ;
if ( F_6 ( V_9 ) )
V_4 = F_7 ( V_2 , 1 << V_11 -> V_17 ) ;
else
V_4 = F_1 ( V_2 , V_11 -> V_17 ) ;
F_8 ( & V_9 -> V_16 ) ;
if ( V_4 < 0 )
return V_4 ;
* V_12 = ( V_4 >> V_2 -> V_18 -> V_19 [ 0 ] . V_20 . V_21 ) &
F_9 ( V_2 -> V_18 -> V_19 [ 0 ] . V_20 . V_22 ) ;
return V_23 ;
case ( 1 << V_24 ) :
V_15 = ( V_2 -> V_25 * 1000 )
>> V_2 -> V_18 -> V_19 [ 0 ] . V_20 . V_22 ;
* V_12 = V_15 / 1000 ;
* V_13 = ( V_15 % 1000 ) * 1000 ;
return V_26 ;
}
return - V_27 ;
}
static int T_1 F_10 ( struct V_28 * V_5 )
{
struct V_29 * V_30 = V_5 -> V_31 . V_32 ;
struct V_1 * V_2 ;
int V_4 , V_33 = 0 ;
struct V_8 * V_9 = F_11 ( sizeof( * V_2 ) ) ;
if ( V_9 == NULL )
return - V_34 ;
V_2 = F_4 ( V_9 ) ;
V_2 -> V_35 = F_12 ( & V_5 -> V_31 , L_1 ) ;
if ( ! F_13 ( V_2 -> V_35 ) ) {
V_4 = F_14 ( V_2 -> V_35 ) ;
if ( V_4 )
goto V_36;
V_33 = F_15 ( V_2 -> V_35 ) ;
}
V_2 -> V_18 =
& V_37 [ F_16 ( V_5 ) -> V_38 ] ;
F_17 ( V_5 , V_9 ) ;
V_2 -> V_5 = V_5 ;
V_9 -> V_31 . V_39 = & V_5 -> V_31 ;
V_9 -> V_40 = F_16 ( V_5 ) -> V_40 ;
V_9 -> V_41 = & V_42 ;
V_9 -> V_43 = V_44 ;
V_2 -> V_45 [ 0 ] = V_46 | V_47 |
( ( V_30 && V_30 -> V_48 ) ?
0 : V_49 ) ;
V_2 -> V_50 [ 0 ] . V_51 = & V_2 -> V_7 [ 0 ] ;
V_2 -> V_50 [ 0 ] . V_52 = & V_2 -> V_45 [ 0 ] ;
V_2 -> V_50 [ 0 ] . V_53 = 2 ;
F_18 ( & V_2 -> V_6 [ V_54 ] ) ;
F_19 ( & V_2 -> V_50 [ 0 ] , & V_2 -> V_6 [ V_54 ] ) ;
if ( V_30 && V_30 -> V_55 ) {
V_2 -> V_45 [ 0 ] |= V_56 | V_49 ;
V_2 -> V_45 [ 2 ] = V_57 | V_56 |
V_49 | V_47 ;
V_2 -> V_45 [ 4 ] = V_46 | V_56 |
V_49 | V_47 ;
V_2 -> V_45 [ 6 ] = V_57 | V_56 |
V_49 | V_47 ;
V_2 -> V_50 [ 1 ] . V_51 = & V_2 -> V_7 [ 0 ] ;
V_2 -> V_50 [ 1 ] . V_52 = & V_2 -> V_45 [ 2 ] ;
V_2 -> V_50 [ 1 ] . V_53 = 2 ;
V_2 -> V_50 [ 2 ] . V_51 = & V_2 -> V_7 [ 2 ] ;
V_2 -> V_50 [ 2 ] . V_52 = & V_2 -> V_45 [ 4 ] ;
V_2 -> V_50 [ 2 ] . V_53 = 2 ;
F_18 ( & V_2 -> V_6 [ V_58 ] ) ;
F_19 ( & V_2 -> V_50 [ 1 ] , & V_2 -> V_6 [ V_58 ] ) ;
F_19 ( & V_2 -> V_50 [ 2 ] , & V_2 -> V_6 [ V_58 ] ) ;
V_2 -> V_50 [ 3 ] . V_51 = & V_2 -> V_7 [ 0 ] ;
V_2 -> V_50 [ 3 ] . V_52 = & V_2 -> V_45 [ 6 ] ;
V_2 -> V_50 [ 3 ] . V_53 = 2 ;
F_18 ( & V_2 -> V_6 [ V_59 ] ) ;
F_19 ( & V_2 -> V_50 [ 3 ] , & V_2 -> V_6 [ V_59 ] ) ;
if ( V_30 && V_30 -> V_60 )
V_2 -> V_25 = V_30 -> V_60 ;
else if ( V_33 )
V_2 -> V_25 = V_33 / 1000 ;
else
F_20 ( & V_5 -> V_31 , L_2 ) ;
V_9 -> V_61 = V_2 -> V_18 -> V_19 ;
V_9 -> V_62 = 3 ;
} else {
if ( V_30 && V_30 -> V_60 )
V_2 -> V_25 = V_30 -> V_60 ;
else if ( V_30 && V_30 -> V_48 )
V_2 -> V_25 = V_2 -> V_18 -> V_25 ;
else
F_20 ( & V_5 -> V_31 , L_2 ) ;
V_9 -> V_61 = & V_2 -> V_18 -> V_19 [ 1 ] ;
V_9 -> V_62 = 2 ;
}
V_4 = F_21 ( V_9 ) ;
if ( V_4 )
goto V_63;
V_4 = F_22 ( V_9 ,
V_9 -> V_61 ,
V_9 -> V_62 ) ;
if ( V_4 )
goto V_64;
V_4 = F_23 ( V_9 ) ;
if ( V_4 )
goto V_65;
return 0 ;
V_65:
F_24 ( V_9 ) ;
V_64:
F_25 ( V_9 ) ;
V_63:
if ( ! F_13 ( V_2 -> V_35 ) )
F_26 ( V_2 -> V_35 ) ;
V_36:
if ( ! F_13 ( V_2 -> V_35 ) )
F_27 ( V_2 -> V_35 ) ;
F_28 ( V_9 ) ;
return V_4 ;
}
static int F_29 ( struct V_28 * V_5 )
{
struct V_8 * V_9 = F_30 ( V_5 ) ;
struct V_1 * V_2 = F_4 ( V_9 ) ;
F_31 ( V_9 ) ;
F_24 ( V_9 ) ;
F_25 ( V_9 ) ;
if ( ! F_13 ( V_2 -> V_35 ) ) {
F_26 ( V_2 -> V_35 ) ;
F_27 ( V_2 -> V_35 ) ;
}
F_28 ( V_9 ) ;
return 0 ;
}
static int T_2 F_32 ( void )
{
return F_33 ( & V_66 ) ;
}
static void T_3 F_34 ( void )
{
F_35 ( & V_66 ) ;
}
