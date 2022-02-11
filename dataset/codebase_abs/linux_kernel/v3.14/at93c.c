static void F_1 ( T_1 V_1 )
{
* V_2 -> V_3 = V_1 ;
}
static T_1 F_2 ( void )
{
T_1 V_4 = * V_2 -> V_3 ;
return V_4 ;
}
static T_1 F_3 ( void )
{
T_1 V_4 = * V_2 -> V_5 ;
return V_4 ;
}
static void F_4 ( T_1 V_6 )
{
F_1 ( V_6 | V_2 -> V_7 ) ;
F_5 ( 250 ) ;
F_1 ( V_6 & ~ V_2 -> V_7 ) ;
F_5 ( 250 ) ;
}
static void F_6 ( T_2 V_8 )
{
T_1 V_6 = F_2 () ;
if ( V_8 )
V_6 |= 1 << V_2 -> V_9 ;
else
V_6 &= ~ ( 1 << V_2 -> V_9 ) ;
F_1 ( V_6 ) ;
F_5 ( 100 ) ;
F_4 ( V_6 ) ;
}
static unsigned int F_7 ( void )
{
T_1 V_6 ;
F_4 ( F_2 () ) ;
V_6 = ( F_3 () >> V_2 -> V_10 ) & 1 ;
return V_6 ;
}
static T_2 F_8 ( void )
{
int V_11 ;
T_2 V_6 = 0 ;
for ( V_11 = 0 ; V_11 <= 7 ; V_11 ++ ) {
V_6 <<= 1 ;
V_6 |= F_7 () ;
}
return V_6 ;
}
static void F_9 ( T_1 V_6 , int V_12 )
{
int V_11 ;
int V_13 = V_12 - 1 ;
T_1 V_14 = ( 1 << V_13 ) ;
for ( V_11 = 0 ; V_11 < V_12 ; V_11 ++ ) {
F_6 ( ( V_6 & V_14 ) >> V_13 ) ;
V_6 <<= 1 ;
}
}
static void F_10 ( void )
{
F_1 ( ( F_2 () | V_2 -> V_15 ) &
~ V_2 -> V_7 & ~ ( 1 << V_2 -> V_10 ) ) ;
F_5 ( 50 ) ;
}
static void F_11 ( void )
{
F_1 ( F_2 () & ~ V_2 -> V_15 ) ;
F_5 ( 250 ) ;
}
static void F_12 ( void )
{
F_10 () ;
while ( ! F_7 () )
;
F_11 () ;
}
static void F_13 ( void )
{
F_10 () ;
F_9 ( V_16 , 10 ) ;
F_11 () ;
}
static void F_14 ( void )
{
F_10 () ;
F_9 ( V_17 , 10 ) ;
F_11 () ;
}
T_2 F_15 ( T_2 V_18 )
{
T_2 V_19 ;
F_10 () ;
F_9 ( ( V_18 & V_20 ) | V_21 , 10 ) ;
V_19 = F_8 () ;
F_11 () ;
return V_19 ;
}
void F_16 ( T_2 V_18 , T_2 V_6 )
{
F_13 () ;
F_10 () ;
F_9 ( ( V_18 & V_20 ) | V_22 , 10 ) ;
F_9 ( V_6 , 8 ) ;
F_11 () ;
F_12 () ;
F_14 () ;
}
