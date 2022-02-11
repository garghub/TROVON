static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_8 * V_9 = V_6 -> V_9 ;
struct V_8 * V_10 = V_6 -> V_10 ;
unsigned int V_11 = 0 ;
unsigned int V_12 [] = { 0 , 1 , 2 , 3 , 4 , 5 , 6 , 7 } ;
int V_13 = 0 ;
switch ( F_2 ( V_4 ) ) {
case 48000 :
V_11 = 24576000 ;
break;
}
V_13 = F_3 ( V_10 , 0 , V_11 ,
V_14 ) ;
if ( V_13 < 0 )
return V_13 ;
V_13 = F_4 ( V_10 , 0xFF , 0xFF , 8 , 32 ) ;
if ( V_13 < 0 )
return V_13 ;
V_13 = F_5 ( V_9 , F_6 ( V_12 ) ,
V_12 , F_6 ( V_12 ) , V_12 ) ;
if ( V_13 < 0 )
return V_13 ;
return 0 ;
}
static int T_1 F_7 ( void )
{
int V_13 ;
V_15 = F_8 ( L_1 , - 1 ) ;
if ( ! V_15 )
return - V_16 ;
F_9 ( V_15 , & V_17 ) ;
V_13 = F_10 ( V_15 ) ;
if ( V_13 )
F_11 ( V_15 ) ;
return V_13 ;
}
static void T_2 F_12 ( void )
{
F_13 ( V_15 ) ;
}
