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
struct V_7 * V_31 ;
int V_3 , V_32 = 0 ;
bool V_33 = false ;
struct V_34 * V_35 ;
V_31 = F_11 ( sizeof( * V_2 ) ) ;
if ( V_31 == NULL ) {
V_3 = - V_36 ;
goto V_37;
}
V_2 = F_4 ( V_31 ) ;
V_35 = F_12 ( & V_4 -> V_29 , L_1 ) ;
if ( ! F_13 ( V_35 ) ) {
V_3 = F_14 ( V_35 ) ;
if ( V_3 )
goto V_38;
V_32 = F_15 ( V_35 ) ;
}
V_2 -> V_35 = V_35 ;
V_2 -> V_16 =
& V_39 [ F_16 ( V_4 ) -> V_40 ] ;
if ( V_2 -> V_16 -> V_23 )
V_2 -> V_23 = V_2 -> V_16 -> V_23 ;
else if ( V_28 && V_28 -> V_41 )
V_2 -> V_23 = V_28 -> V_41 ;
else if ( V_32 )
V_2 -> V_23 = V_32 / 1000 ;
else
F_17 ( & V_4 -> V_29 , L_2 ) ;
F_18 ( V_4 , V_31 ) ;
V_2 -> V_4 = V_4 ;
V_31 -> V_29 . V_42 = & V_4 -> V_29 ;
V_31 -> V_43 = F_16 ( V_4 ) -> V_43 ;
V_31 -> V_44 = V_45 ;
V_31 -> V_46 = V_2 -> V_16 -> V_17 ;
V_31 -> V_47 = 2 ;
V_31 -> V_48 = & V_49 ;
V_2 -> V_50 . V_51 = & V_2 -> V_6 ;
V_2 -> V_50 . V_52 = V_2 -> V_16 -> V_17 [ 0 ] . V_18 . V_53 / 8 ;
F_19 ( & V_2 -> V_5 ) ;
F_20 ( & V_2 -> V_50 , & V_2 -> V_5 ) ;
V_3 = F_21 ( V_31 ) ;
if ( V_3 )
goto V_54;
V_3 = F_22 ( V_31 ) ;
if ( V_3 )
goto V_54;
V_3 = F_23 ( V_31 -> V_55 , 0 ,
V_2 -> V_16 -> V_17 ,
F_24 ( V_2 -> V_16 -> V_17 ) ) ;
if ( V_3 )
goto V_56;
return 0 ;
V_56:
F_25 ( V_31 ) ;
F_26 ( V_31 ) ;
V_54:
if ( ! F_13 ( V_35 ) )
F_27 ( V_2 -> V_35 ) ;
V_38:
if ( ! F_13 ( V_35 ) )
F_28 ( V_35 ) ;
if ( ! V_33 )
F_29 ( V_31 ) ;
V_37:
return V_3 ;
}
static int F_30 ( struct V_26 * V_4 )
{
struct V_7 * V_31 = F_31 ( V_4 ) ;
struct V_1 * V_2 = F_4 ( V_31 ) ;
struct V_34 * V_35 = V_2 -> V_35 ;
F_32 ( V_31 -> V_55 ) ;
F_25 ( V_31 ) ;
F_26 ( V_31 ) ;
if ( ! F_13 ( V_35 ) ) {
F_27 ( V_35 ) ;
F_28 ( V_35 ) ;
}
return 0 ;
}
static int T_2 F_33 ( void )
{
return F_34 ( & V_57 ) ;
}
static void T_3 F_35 ( void )
{
F_36 ( & V_57 ) ;
}
