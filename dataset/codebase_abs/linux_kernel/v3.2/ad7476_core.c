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
struct V_1 * V_2 = F_4 ( V_8 ) ;
unsigned int V_14 ;
switch ( V_13 ) {
case 0 :
F_5 ( & V_8 -> V_15 ) ;
if ( F_6 ( V_8 ) )
V_3 = F_7 ( V_8 ) ;
else
V_3 = F_1 ( V_2 ) ;
F_8 ( & V_8 -> V_15 ) ;
if ( V_3 < 0 )
return V_3 ;
* V_11 = ( V_3 >> V_2 -> V_16 -> V_17 [ 0 ] . V_18 . V_19 ) &
F_9 ( V_2 -> V_16 -> V_17 [ 0 ] . V_18 . V_20 ) ;
return V_21 ;
case ( 1 << V_22 ) :
V_14 = ( V_2 -> V_23 * 1000 )
>> V_2 -> V_16 -> V_17 [ 0 ] . V_18 . V_20 ;
* V_11 = V_14 / 1000 ;
* V_12 = ( V_14 % 1000 ) * 1000 ;
return V_24 ;
}
return - V_25 ;
}
static int T_1 F_10 ( struct V_26 * V_4 )
{
struct V_27 * V_28 = V_4 -> V_29 . V_30 ;
struct V_1 * V_2 ;
struct V_7 * V_8 ;
int V_3 , V_31 = 0 ;
V_8 = F_11 ( sizeof( * V_2 ) ) ;
if ( V_8 == NULL ) {
V_3 = - V_32 ;
goto V_33;
}
V_2 = F_4 ( V_8 ) ;
V_2 -> V_34 = F_12 ( & V_4 -> V_29 , L_1 ) ;
if ( ! F_13 ( V_2 -> V_34 ) ) {
V_3 = F_14 ( V_2 -> V_34 ) ;
if ( V_3 )
goto V_35;
V_31 = F_15 ( V_2 -> V_34 ) ;
}
V_2 -> V_16 =
& V_36 [ F_16 ( V_4 ) -> V_37 ] ;
if ( V_2 -> V_16 -> V_23 )
V_2 -> V_23 = V_2 -> V_16 -> V_23 ;
else if ( V_28 && V_28 -> V_38 )
V_2 -> V_23 = V_28 -> V_38 ;
else if ( V_31 )
V_2 -> V_23 = V_31 / 1000 ;
else
F_17 ( & V_4 -> V_29 , L_2 ) ;
F_18 ( V_4 , V_8 ) ;
V_2 -> V_4 = V_4 ;
V_8 -> V_29 . V_39 = & V_4 -> V_29 ;
V_8 -> V_40 = F_16 ( V_4 ) -> V_40 ;
V_8 -> V_41 = V_42 ;
V_8 -> V_43 = V_2 -> V_16 -> V_17 ;
V_8 -> V_44 = 2 ;
V_8 -> V_45 = & V_46 ;
V_2 -> V_47 . V_48 = & V_2 -> V_6 ;
V_2 -> V_47 . V_49 = V_2 -> V_16 -> V_17 [ 0 ] . V_18 . V_50 / 8 ;
F_19 ( & V_2 -> V_5 ) ;
F_20 ( & V_2 -> V_47 , & V_2 -> V_5 ) ;
V_3 = F_21 ( V_8 ) ;
if ( V_3 )
goto V_51;
V_3 = F_22 ( V_8 ,
V_2 -> V_16 -> V_17 ,
F_23 ( V_2 -> V_16 -> V_17 ) ) ;
if ( V_3 )
goto V_52;
V_3 = F_24 ( V_8 ) ;
if ( V_3 )
goto V_53;
return 0 ;
V_53:
F_25 ( V_8 ) ;
V_52:
F_26 ( V_8 ) ;
V_51:
if ( ! F_13 ( V_2 -> V_34 ) )
F_27 ( V_2 -> V_34 ) ;
V_35:
if ( ! F_13 ( V_2 -> V_34 ) )
F_28 ( V_2 -> V_34 ) ;
F_29 ( V_8 ) ;
V_33:
return V_3 ;
}
static int F_30 ( struct V_26 * V_4 )
{
struct V_7 * V_8 = F_31 ( V_4 ) ;
struct V_1 * V_2 = F_4 ( V_8 ) ;
F_32 ( V_8 ) ;
F_25 ( V_8 ) ;
F_26 ( V_8 ) ;
if ( ! F_13 ( V_2 -> V_34 ) ) {
F_27 ( V_2 -> V_34 ) ;
F_28 ( V_2 -> V_34 ) ;
}
F_29 ( V_8 ) ;
return 0 ;
}
static int T_2 F_33 ( void )
{
return F_34 ( & V_54 ) ;
}
static void T_3 F_35 ( void )
{
F_36 ( & V_54 ) ;
}
