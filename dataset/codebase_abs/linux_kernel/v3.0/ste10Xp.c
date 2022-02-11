static int F_1 ( struct V_1 * V_2 )
{
int V_3 , V_4 ;
V_3 = F_2 ( V_2 , V_5 ) ;
if ( V_3 < 0 )
return V_3 ;
V_3 |= V_6 ;
V_4 = F_3 ( V_2 , V_5 , V_3 ) ;
if ( V_4 < 0 )
return V_4 ;
do {
V_3 = F_2 ( V_2 , V_5 ) ;
} while ( V_3 & V_6 );
return 0 ;
}
static int F_4 ( struct V_1 * V_2 )
{
int V_4 , V_3 ;
if ( V_2 -> V_7 == V_8 ) {
V_4 = F_3 ( V_2 , V_9 , V_10 ) ;
if ( V_4 == 0 ) {
V_3 = F_2 ( V_2 , V_11 ) ;
if ( V_3 < 0 )
V_4 = V_3 ;
}
} else
V_4 = F_3 ( V_2 , V_9 , 0 ) ;
return V_4 ;
}
static int F_5 ( struct V_1 * V_2 )
{
int V_4 = F_2 ( V_2 , V_11 ) ;
if ( V_4 < 0 )
return V_4 ;
return 0 ;
}
static int T_1 F_6 ( void )
{
int V_12 ;
V_12 = F_7 ( & V_13 ) ;
if ( V_12 < 0 )
return V_12 ;
return F_7 ( & V_14 ) ;
}
static void T_2 F_8 ( void )
{
F_9 ( & V_13 ) ;
F_9 ( & V_14 ) ;
}
