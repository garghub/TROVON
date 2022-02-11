static int F_1 ( struct V_1 * V_2 )
{
int V_3 ;
V_3 = F_2 ( V_2 -> V_4 , & V_2 -> V_5 ) ;
if ( V_3 )
return V_3 ;
return ( V_2 -> V_6 [ 0 ] << 8 ) | V_2 -> V_6 [ 1 ] ;
}
static int F_3 ( struct V_7 * V_8 ,
struct V_9 const * V_10 ,
int * V_11 ,
int * V_12 ,
long V_13 )
{
int V_3 ;
struct V_1 * V_2 = V_8 -> V_14 ;
unsigned int V_15 ;
switch ( V_13 ) {
case 0 :
F_4 ( & V_8 -> V_16 ) ;
if ( F_5 ( V_8 ) )
V_3 = F_6 ( V_2 ) ;
else
V_3 = F_1 ( V_2 ) ;
F_7 ( & V_8 -> V_16 ) ;
if ( V_3 < 0 )
return V_3 ;
* V_11 = ( V_3 >> V_2 -> V_17 -> V_18 [ 0 ] . V_19 . V_20 ) &
F_8 ( V_2 -> V_17 -> V_18 [ 0 ] . V_19 . V_21 ) ;
return V_22 ;
case ( 1 << V_23 ) :
V_15 = ( V_2 -> V_24 * 1000 )
>> V_2 -> V_17 -> V_18 [ 0 ] . V_19 . V_21 ;
* V_11 = V_15 / 1000 ;
* V_12 = ( V_15 % 1000 ) * 1000 ;
return V_25 ;
}
return - V_26 ;
}
static int T_1 F_9 ( struct V_27 * V_4 )
{
struct V_28 * V_29 = V_4 -> V_30 . V_31 ;
struct V_1 * V_2 ;
int V_3 , V_32 = 0 ;
V_2 = F_10 ( sizeof( * V_2 ) , V_33 ) ;
if ( V_2 == NULL ) {
V_3 = - V_34 ;
goto V_35;
}
V_2 -> V_36 = F_11 ( & V_4 -> V_30 , L_1 ) ;
if ( ! F_12 ( V_2 -> V_36 ) ) {
V_3 = F_13 ( V_2 -> V_36 ) ;
if ( V_3 )
goto V_37;
V_32 = F_14 ( V_2 -> V_36 ) ;
}
V_2 -> V_17 =
& V_38 [ F_15 ( V_4 ) -> V_39 ] ;
if ( V_2 -> V_17 -> V_24 )
V_2 -> V_24 = V_2 -> V_17 -> V_24 ;
else if ( V_29 && V_29 -> V_40 )
V_2 -> V_24 = V_29 -> V_40 ;
else if ( V_32 )
V_2 -> V_24 = V_32 / 1000 ;
else
F_16 ( & V_4 -> V_30 , L_2 ) ;
F_17 ( V_4 , V_2 ) ;
V_2 -> V_4 = V_4 ;
V_2 -> V_41 = F_18 ( 0 ) ;
if ( V_2 -> V_41 == NULL ) {
V_3 = - V_34 ;
goto V_42;
}
V_2 -> V_41 -> V_30 . V_43 = & V_4 -> V_30 ;
V_2 -> V_41 -> V_44 = F_15 ( V_4 ) -> V_44 ;
V_2 -> V_41 -> V_14 = ( void * ) ( V_2 ) ;
V_2 -> V_41 -> V_45 = V_46 ;
V_2 -> V_41 -> V_47 = V_2 -> V_17 -> V_18 ;
V_2 -> V_41 -> V_48 = 2 ;
V_2 -> V_41 -> V_49 = & V_50 ;
V_2 -> V_51 . V_52 = & V_2 -> V_6 ;
V_2 -> V_51 . V_53 = V_2 -> V_17 -> V_18 [ 0 ] . V_19 . V_54 / 8 ;
F_19 ( & V_2 -> V_5 ) ;
F_20 ( & V_2 -> V_51 , & V_2 -> V_5 ) ;
V_3 = F_21 ( V_2 -> V_41 ) ;
if ( V_3 )
goto V_55;
V_3 = F_22 ( V_2 -> V_41 ) ;
if ( V_3 )
goto V_55;
V_3 = F_23 ( V_2 -> V_41 -> V_56 , 0 ,
V_2 -> V_17 -> V_18 ,
F_24 ( V_2 -> V_17 -> V_18 ) ) ;
if ( V_3 )
goto V_57;
return 0 ;
V_57:
F_25 ( V_2 -> V_41 ) ;
F_26 ( V_2 -> V_41 ) ;
V_55:
F_27 ( V_2 -> V_41 ) ;
V_42:
if ( ! F_12 ( V_2 -> V_36 ) )
F_28 ( V_2 -> V_36 ) ;
V_37:
if ( ! F_12 ( V_2 -> V_36 ) )
F_29 ( V_2 -> V_36 ) ;
F_30 ( V_2 ) ;
V_35:
return V_3 ;
}
static int F_31 ( struct V_27 * V_4 )
{
struct V_1 * V_2 = F_32 ( V_4 ) ;
struct V_7 * V_41 = V_2 -> V_41 ;
F_33 ( V_41 -> V_56 ) ;
F_25 ( V_41 ) ;
F_26 ( V_41 ) ;
if ( ! F_12 ( V_2 -> V_36 ) ) {
F_28 ( V_2 -> V_36 ) ;
F_29 ( V_2 -> V_36 ) ;
}
F_30 ( V_2 ) ;
return 0 ;
}
static int T_2 F_34 ( void )
{
return F_35 ( & V_58 ) ;
}
static void T_3 F_36 ( void )
{
F_37 ( & V_58 ) ;
}
