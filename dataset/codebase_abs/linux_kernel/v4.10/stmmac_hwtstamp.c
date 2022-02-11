static void F_1 ( void T_1 * V_1 , T_2 V_2 )
{
F_2 ( V_2 , V_1 + V_3 ) ;
}
static T_2 F_3 ( void T_1 * V_1 ,
T_2 V_4 , int V_5 )
{
T_2 V_6 = F_4 ( V_1 + V_3 ) ;
unsigned long V_2 ;
if ( V_6 & V_7 )
V_2 = ( 1000000000ULL / 50000000 ) ;
else
V_2 = ( 1000000000ULL / V_4 ) ;
if ( ! ( V_6 & V_8 ) )
V_2 = ( V_2 * 1000 ) / 465 ;
V_2 &= V_9 ;
if ( V_5 )
V_2 = V_2 << V_10 ;
F_2 ( V_2 , V_1 + V_11 ) ;
return V_2 ;
}
static int F_5 ( void T_1 * V_1 , T_2 V_12 , T_2 V_13 )
{
int V_14 ;
T_2 V_6 ;
F_2 ( V_12 , V_1 + V_15 ) ;
F_2 ( V_13 , V_1 + V_16 ) ;
V_6 = F_4 ( V_1 + V_3 ) ;
V_6 |= V_17 ;
F_2 ( V_6 , V_1 + V_3 ) ;
V_14 = 10 ;
while ( V_14 -- ) {
if ( ! ( F_4 ( V_1 + V_3 ) & V_17 ) )
break;
F_6 ( 10 ) ;
}
if ( V_14 < 0 )
return - V_18 ;
return 0 ;
}
static int F_7 ( void T_1 * V_1 , T_2 V_19 )
{
T_2 V_6 ;
int V_14 ;
F_2 ( V_19 , V_1 + V_20 ) ;
V_6 = F_4 ( V_1 + V_3 ) ;
V_6 |= V_21 ;
F_2 ( V_6 , V_1 + V_3 ) ;
V_14 = 10 ;
while ( V_14 -- ) {
if ( ! ( F_4 ( V_1 + V_3 ) & V_21 ) )
break;
F_6 ( 10 ) ;
}
if ( V_14 < 0 )
return - V_18 ;
return 0 ;
}
static int F_8 ( void T_1 * V_1 , T_2 V_12 , T_2 V_13 ,
int V_22 , int V_5 )
{
T_2 V_6 ;
int V_14 ;
if ( V_22 ) {
if ( V_5 )
V_12 = ( 100000000ULL - V_12 ) ;
V_6 = F_4 ( V_1 + V_3 ) ;
if ( V_6 & V_8 )
V_13 = ( V_23 - V_13 ) ;
else
V_13 = ( V_24 - V_13 ) ;
}
F_2 ( V_12 , V_1 + V_15 ) ;
V_6 = ( V_22 << V_25 ) | V_13 ;
F_2 ( V_6 , V_1 + V_16 ) ;
V_6 = F_4 ( V_1 + V_3 ) ;
V_6 |= V_26 ;
F_2 ( V_6 , V_1 + V_3 ) ;
V_14 = 10 ;
while ( V_14 -- ) {
if ( ! ( F_4 ( V_1 + V_3 ) & V_26 ) )
break;
F_6 ( 10 ) ;
}
if ( V_14 < 0 )
return - V_18 ;
return 0 ;
}
static T_3 F_9 ( void T_1 * V_1 )
{
T_3 V_27 ;
V_27 = F_4 ( V_1 + V_28 ) ;
V_27 += F_4 ( V_1 + V_29 ) * 1000000000ULL ;
return V_27 ;
}
