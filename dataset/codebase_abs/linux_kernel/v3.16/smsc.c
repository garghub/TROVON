static int F_1 ( struct V_1 * V_2 )
{
int V_3 = F_2 ( V_2 , V_4 ,
( ( V_5 == V_2 -> V_6 )
? V_7
: 0 ) ) ;
return V_3 < 0 ? V_3 : 0 ;
}
static int F_3 ( struct V_1 * V_2 )
{
int V_3 = F_4 ( V_2 , V_8 ) ;
return V_3 < 0 ? V_3 : 0 ;
}
static int F_5 ( struct V_1 * V_2 )
{
int V_3 = F_4 ( V_2 , V_9 ) ;
if ( V_3 < 0 )
return V_3 ;
if ( ( V_3 & V_10 ) == V_11 ) {
int V_12 = 50000 ;
V_3 |= V_13 ;
F_2 ( V_2 , V_9 , V_3 ) ;
F_2 ( V_2 , V_14 , V_15 ) ;
do {
F_6 ( 10 ) ;
if ( V_12 -- == 0 )
return - 1 ;
V_3 = F_4 ( V_2 , V_14 ) ;
} while ( V_3 & V_15 );
}
V_3 = F_4 ( V_2 , V_16 ) ;
if ( V_3 < 0 )
return V_3 ;
V_3 = F_2 ( V_2 , V_16 ,
V_3 | V_17 ) ;
if ( V_3 < 0 )
return V_3 ;
return F_3 ( V_2 ) ;
}
static int F_7 ( struct V_1 * V_2 )
{
return F_3 ( V_2 ) ;
}
static int F_8 ( struct V_1 * V_2 )
{
int V_18 = F_9 ( V_2 ) ;
if ( ! V_2 -> V_19 ) {
int V_3 = F_4 ( V_2 , V_16 ) ;
if ( V_3 < 0 )
return V_3 ;
V_3 = F_2 ( V_2 , V_16 ,
V_3 & ~ V_17 ) ;
if ( V_3 < 0 )
return V_3 ;
F_10 ( 64 ) ;
V_3 = F_4 ( V_2 , V_16 ) ;
if ( V_3 < 0 )
return V_3 ;
V_3 = F_2 ( V_2 , V_16 ,
V_3 | V_17 ) ;
if ( V_3 < 0 )
return V_3 ;
}
return V_18 ;
}
static int T_1 F_11 ( void )
{
return F_12 ( V_20 ,
F_13 ( V_20 ) ) ;
}
static void T_2 F_14 ( void )
{
F_15 ( V_20 , F_13 ( V_20 ) ) ;
}
