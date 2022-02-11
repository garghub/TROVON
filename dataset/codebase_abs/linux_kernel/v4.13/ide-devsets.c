static int F_1 ( T_1 * V_1 , int V_2 )
{
if ( V_1 -> V_3 & V_4 )
return - V_5 ;
if ( V_2 < 0 || V_2 > 1 + ( V_6 << 1 ) )
return - V_7 ;
V_1 -> V_8 = V_2 ;
return 0 ;
}
static int F_2 ( T_1 * V_1 , int V_2 )
{
if ( V_2 < 0 || V_2 > 1 )
return - V_7 ;
if ( V_2 )
V_1 -> V_3 |= V_9 ;
else
V_1 -> V_3 &= ~ V_9 ;
return 0 ;
}
static int F_3 ( T_1 * V_1 , int V_2 )
{
#ifdef F_4
int V_10 = - V_5 ;
if ( V_2 < 0 || V_2 > 1 )
return - V_7 ;
if ( F_5 ( V_1 -> V_11 ) == 0 )
goto V_12;
if ( V_1 -> V_13 -> V_14 == NULL )
goto V_12;
V_10 = 0 ;
if ( V_2 ) {
if ( F_6 ( V_1 ) )
V_10 = - V_15 ;
} else
F_7 ( V_1 ) ;
V_12:
return V_10 ;
#else
if ( V_2 < 0 || V_2 > 1 )
return - V_7 ;
return - V_5 ;
#endif
}
static int F_8 ( T_2 * V_13 , T_3 V_16 )
{
switch ( V_16 ) {
case 202 :
case 201 :
case 200 :
case 102 :
case 101 :
case 100 :
return ( V_13 -> V_17 & V_18 ) ? 1 : 0 ;
case 9 :
case 8 :
return ( V_13 -> V_17 & V_19 ) ? 1 : 0 ;
case 7 :
case 6 :
return ( V_13 -> V_17 & V_20 ) ? 1 : 0 ;
default:
return 0 ;
}
}
static int F_9 ( T_1 * V_1 , int V_2 )
{
T_2 * V_13 = V_1 -> V_13 ;
const struct V_21 * V_22 = V_13 -> V_22 ;
if ( V_2 < 0 || V_2 > 255 )
return - V_7 ;
if ( V_22 == NULL || V_22 -> F_9 == NULL ||
( V_13 -> V_17 & V_23 ) )
return - V_24 ;
if ( F_8 ( V_1 -> V_13 , V_2 ) ) {
V_1 -> V_25 = V_2 + V_26 ;
if ( V_2 == 8 || V_2 == 9 ) {
unsigned long V_27 ;
F_10 ( & V_13 -> V_28 , V_27 ) ;
V_22 -> F_9 ( V_13 , V_1 ) ;
F_11 ( & V_13 -> V_28 , V_27 ) ;
} else
V_22 -> F_9 ( V_13 , V_1 ) ;
} else {
int V_29 = ! ! ( V_1 -> V_3 & V_30 ) ;
F_12 ( V_1 , V_2 ) ;
if ( V_13 -> V_17 & V_31 ) {
if ( V_29 )
F_13 ( V_1 ) ;
}
}
return 0 ;
}
static int F_14 ( T_1 * V_1 , int V_2 )
{
if ( V_1 -> V_3 & V_32 )
return - V_5 ;
if ( V_2 < 0 || V_2 > 1 )
return - V_7 ;
if ( V_2 )
V_1 -> V_3 |= V_33 ;
else
V_1 -> V_3 &= ~ V_33 ;
return 0 ;
}
int F_15 ( T_1 * V_1 , const struct V_34 * V_35 ,
int V_2 )
{
struct V_36 * V_37 = V_1 -> V_38 ;
struct V_39 * V_40 ;
int V_41 = 0 ;
if ( ! ( V_35 -> V_27 & V_42 ) )
return V_35 -> V_43 ( V_1 , V_2 ) ;
V_40 = F_16 ( V_37 , V_44 , V_45 ) ;
F_17 ( V_40 ) -> type = V_46 ;
F_18 ( V_40 ) -> V_47 = 5 ;
F_18 ( V_40 ) -> V_48 [ 0 ] = V_49 ;
* ( int * ) & F_18 ( V_40 ) -> V_48 [ 1 ] = V_2 ;
V_40 -> V_50 = V_35 -> V_43 ;
F_19 ( V_37 , NULL , V_40 , 0 ) ;
V_41 = F_18 ( V_40 ) -> V_51 ;
F_20 ( V_40 ) ;
return V_41 ;
}
T_4 F_21 ( T_1 * V_1 , struct V_39 * V_40 )
{
int V_10 , ( * V_52 ) ( T_1 * , int ) = V_40 -> V_50 ;
V_10 = V_52 ( V_1 , * ( int * ) & F_18 ( V_40 ) -> V_48 [ 1 ] ) ;
if ( V_10 )
F_18 ( V_40 ) -> V_51 = V_10 ;
F_22 ( V_1 , 0 , F_23 ( V_40 ) ) ;
return V_53 ;
}
