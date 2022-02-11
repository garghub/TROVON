static void F_1 ( void T_1 * V_1 , T_2 V_2 )
{
F_2 ( V_2 , V_1 + V_3 ) ;
}
static T_2 F_3 ( void T_1 * V_1 ,
T_2 V_4 )
{
T_2 V_5 = F_4 ( V_1 + V_3 ) ;
unsigned long V_2 ;
V_2 = ( 2000000000ULL / V_4 ) ;
if ( ! ( V_5 & V_6 ) )
V_2 = ( V_2 * 1000 ) / 465 ;
F_2 ( V_2 , V_1 + V_7 ) ;
return V_2 ;
}
static int F_5 ( void T_1 * V_1 , T_2 V_8 , T_2 V_9 )
{
int V_10 ;
T_2 V_5 ;
F_2 ( V_8 , V_1 + V_11 ) ;
F_2 ( V_9 , V_1 + V_12 ) ;
V_5 = F_4 ( V_1 + V_3 ) ;
V_5 |= V_13 ;
F_2 ( V_5 , V_1 + V_3 ) ;
V_10 = 10 ;
while ( V_10 -- ) {
if ( ! ( F_4 ( V_1 + V_3 ) & V_13 ) )
break;
F_6 ( 10 ) ;
}
if ( V_10 < 0 )
return - V_14 ;
return 0 ;
}
static int F_7 ( void T_1 * V_1 , T_2 V_15 )
{
T_2 V_5 ;
int V_10 ;
F_2 ( V_15 , V_1 + V_16 ) ;
V_5 = F_4 ( V_1 + V_3 ) ;
V_5 |= V_17 ;
F_2 ( V_5 , V_1 + V_3 ) ;
V_10 = 10 ;
while ( V_10 -- ) {
if ( ! ( F_4 ( V_1 + V_3 ) & V_17 ) )
break;
F_6 ( 10 ) ;
}
if ( V_10 < 0 )
return - V_14 ;
return 0 ;
}
static int F_8 ( void T_1 * V_1 , T_2 V_8 , T_2 V_9 ,
int V_18 )
{
T_2 V_5 ;
int V_10 ;
F_2 ( V_8 , V_1 + V_11 ) ;
F_2 ( ( ( V_18 << V_19 ) | V_9 ) ,
V_1 + V_12 ) ;
V_5 = F_4 ( V_1 + V_3 ) ;
V_5 |= V_20 ;
F_2 ( V_5 , V_1 + V_3 ) ;
V_10 = 10 ;
while ( V_10 -- ) {
if ( ! ( F_4 ( V_1 + V_3 ) & V_20 ) )
break;
F_6 ( 10 ) ;
}
if ( V_10 < 0 )
return - V_14 ;
return 0 ;
}
static T_3 F_9 ( void T_1 * V_1 )
{
T_3 V_21 ;
V_21 = F_4 ( V_1 + V_22 ) ;
V_21 += F_4 ( V_1 + V_23 ) * 1000000000ULL ;
return V_21 ;
}
