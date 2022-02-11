static void F_1 ( void T_1 * V_1 , T_2 V_2 )
{
F_2 ( V_2 , V_1 + V_3 ) ;
}
static void F_3 ( void T_1 * V_1 )
{
T_2 V_4 = F_4 ( V_1 + V_3 ) ;
unsigned long V_2 ;
V_2 = ( 1000000000ULL / 50000000 ) ;
if ( V_4 & V_5 )
V_2 = ( V_2 * 100 ) / 465 ;
F_2 ( V_2 , V_1 + V_6 ) ;
}
static int F_5 ( void T_1 * V_1 , T_2 V_7 , T_2 V_8 )
{
int V_9 ;
T_2 V_4 ;
F_2 ( V_7 , V_1 + V_10 ) ;
F_2 ( V_8 , V_1 + V_11 ) ;
V_4 = F_4 ( V_1 + V_3 ) ;
V_4 |= V_12 ;
F_2 ( V_4 , V_1 + V_3 ) ;
V_9 = 10 ;
while ( V_9 -- ) {
if ( ! ( F_4 ( V_1 + V_3 ) & V_12 ) )
break;
F_6 ( 10 ) ;
}
if ( V_9 < 0 )
return - V_13 ;
return 0 ;
}
static int F_7 ( void T_1 * V_1 , T_2 V_14 )
{
T_2 V_4 ;
int V_9 ;
F_2 ( V_14 , V_1 + V_15 ) ;
V_4 = F_4 ( V_1 + V_3 ) ;
V_4 |= V_16 ;
F_2 ( V_4 , V_1 + V_3 ) ;
V_9 = 10 ;
while ( V_9 -- ) {
if ( ! ( F_4 ( V_1 + V_3 ) & V_16 ) )
break;
F_6 ( 10 ) ;
}
if ( V_9 < 0 )
return - V_13 ;
return 0 ;
}
static int F_8 ( void T_1 * V_1 , T_2 V_7 , T_2 V_8 ,
int V_17 )
{
T_2 V_4 ;
int V_9 ;
F_2 ( V_7 , V_1 + V_10 ) ;
F_2 ( ( ( V_17 << V_18 ) | V_8 ) ,
V_1 + V_11 ) ;
V_4 = F_4 ( V_1 + V_3 ) ;
V_4 |= V_19 ;
F_2 ( V_4 , V_1 + V_3 ) ;
V_9 = 10 ;
while ( V_9 -- ) {
if ( ! ( F_4 ( V_1 + V_3 ) & V_19 ) )
break;
F_6 ( 10 ) ;
}
if ( V_9 < 0 )
return - V_13 ;
return 0 ;
}
static T_3 F_9 ( void T_1 * V_1 )
{
T_3 V_20 ;
V_20 = F_4 ( V_1 + V_21 ) ;
V_20 += F_4 ( V_1 + V_22 ) * 1000000000ULL ;
return V_20 ;
}
