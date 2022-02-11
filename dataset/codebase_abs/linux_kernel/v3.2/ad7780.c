static int F_1 ( struct V_1 * V_2 , int * V_3 )
{
int V_4 ;
F_2 ( V_2 -> V_5 -> V_6 ) ;
F_3 ( V_2 -> V_5 -> V_7 ) ;
V_2 -> V_8 = false ;
F_4 ( V_2 -> V_9 -> V_10 , 1 ) ;
V_4 = F_5 ( V_2 -> V_11 , V_2 -> V_8 ) ;
F_6 ( V_2 -> V_5 -> V_7 ) ;
if ( V_4 )
goto V_12;
V_4 = F_7 ( V_2 -> V_5 , & V_2 -> V_13 ) ;
* V_3 = F_8 ( V_2 -> V_14 ) ;
V_12:
F_4 ( V_2 -> V_9 -> V_10 , 0 ) ;
F_9 ( V_2 -> V_5 -> V_6 ) ;
return V_4 ;
}
static int F_10 ( struct V_15 * V_16 ,
struct V_17 const * V_18 ,
int * V_3 ,
int * V_19 ,
long V_20 )
{
struct V_1 * V_2 = F_11 ( V_16 ) ;
struct V_17 V_21 = V_2 -> V_22 -> V_21 ;
int V_4 , V_23 = 0 ;
unsigned long V_24 ;
switch ( V_20 ) {
case 0 :
F_12 ( & V_16 -> V_25 ) ;
V_4 = F_1 ( V_2 , & V_23 ) ;
F_13 ( & V_16 -> V_25 ) ;
if ( V_4 < 0 )
return V_4 ;
if ( ( V_23 & V_26 ) ||
! ( ( V_23 & V_27 ) && ! ( V_23 & V_28 ) ) )
return - V_29 ;
* V_3 = ( V_23 >> V_21 . V_30 . V_31 ) &
( ( 1 << ( V_21 . V_30 . V_32 ) ) - 1 ) ;
* V_3 -= ( 1 << ( V_21 . V_30 . V_32 - 1 ) ) ;
if ( ! ( V_23 & V_33 ) )
* V_3 *= 128 ;
return V_34 ;
case ( 1 << V_35 ) :
V_24 = ( V_2 -> V_36 * 100000 )
>> ( V_21 . V_30 . V_32 - 1 ) ;
* V_3 = V_24 / 100000 ;
* V_19 = ( V_24 % 100000 ) * 10 ;
return V_37 ;
}
return - V_38 ;
}
static T_1 F_14 ( int V_7 , void * V_39 )
{
struct V_1 * V_2 = V_39 ;
V_2 -> V_8 = true ;
F_15 ( & V_2 -> V_11 ) ;
return V_40 ;
}
static int T_2 F_16 ( struct V_41 * V_5 )
{
struct V_42 * V_9 = V_5 -> V_43 . V_44 ;
struct V_1 * V_2 ;
struct V_15 * V_16 ;
int V_4 , V_45 = 0 ;
if ( ! V_9 ) {
F_17 ( & V_5 -> V_43 , L_1 ) ;
return - V_46 ;
}
V_16 = F_18 ( sizeof( * V_2 ) ) ;
if ( V_16 == NULL )
return - V_47 ;
V_2 = F_11 ( V_16 ) ;
V_2 -> V_48 = F_19 ( & V_5 -> V_43 , L_2 ) ;
if ( ! F_20 ( V_2 -> V_48 ) ) {
V_4 = F_21 ( V_2 -> V_48 ) ;
if ( V_4 )
goto V_49;
V_45 = F_22 ( V_2 -> V_48 ) ;
}
V_2 -> V_22 =
& V_50 [ F_23 ( V_5 ) -> V_51 ] ;
V_2 -> V_9 = V_9 ;
if ( V_9 && V_9 -> V_52 )
V_2 -> V_36 = V_9 -> V_52 ;
else if ( V_45 )
V_2 -> V_36 = V_45 / 1000 ;
else
F_24 ( & V_5 -> V_43 , L_3 ) ;
F_25 ( V_5 , V_16 ) ;
V_2 -> V_5 = V_5 ;
V_16 -> V_43 . V_53 = & V_5 -> V_43 ;
V_16 -> V_54 = F_23 ( V_5 ) -> V_54 ;
V_16 -> V_55 = V_56 ;
V_16 -> V_57 = & V_2 -> V_22 -> V_21 ;
V_16 -> V_58 = 1 ;
V_16 -> V_59 = & V_60 ;
F_26 ( & V_2 -> V_11 ) ;
V_2 -> V_61 . V_62 = & V_2 -> V_14 ;
V_2 -> V_61 . V_63 = V_2 -> V_22 -> V_21 . V_30 . V_64 / 8 ;
F_27 ( & V_2 -> V_13 ) ;
F_28 ( & V_2 -> V_61 , & V_2 -> V_13 ) ;
V_4 = F_29 ( V_2 -> V_9 -> V_10 , V_65 ,
L_4 ) ;
if ( V_4 ) {
F_30 ( & V_5 -> V_43 , L_5 ) ;
goto V_66;
}
V_4 = F_31 ( V_5 -> V_7 , F_14 ,
V_67 , F_23 ( V_5 ) -> V_54 , V_2 ) ;
if ( V_4 )
goto V_68;
F_32 ( V_5 -> V_7 ) ;
V_4 = F_33 ( V_16 ) ;
if ( V_4 )
goto V_69;
return 0 ;
V_69:
F_34 ( V_5 -> V_7 , V_2 ) ;
V_68:
F_35 ( V_2 -> V_9 -> V_10 ) ;
V_66:
if ( ! F_20 ( V_2 -> V_48 ) )
F_36 ( V_2 -> V_48 ) ;
V_49:
if ( ! F_20 ( V_2 -> V_48 ) )
F_37 ( V_2 -> V_48 ) ;
F_38 ( V_16 ) ;
return V_4 ;
}
static int F_39 ( struct V_41 * V_5 )
{
struct V_15 * V_16 = F_40 ( V_5 ) ;
struct V_1 * V_2 = F_11 ( V_16 ) ;
F_41 ( V_16 ) ;
F_34 ( V_5 -> V_7 , V_2 ) ;
F_35 ( V_2 -> V_9 -> V_10 ) ;
if ( ! F_20 ( V_2 -> V_48 ) ) {
F_36 ( V_2 -> V_48 ) ;
F_37 ( V_2 -> V_48 ) ;
}
F_38 ( V_16 ) ;
return 0 ;
}
static int T_3 F_42 ( void )
{
return F_43 ( & V_70 ) ;
}
static void T_4 F_44 ( void )
{
F_45 ( & V_70 ) ;
}
