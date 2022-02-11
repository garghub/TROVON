static int F_1 ( unsigned int V_1 )
{
int V_2 ;
for ( V_2 = 0 ; V_2 < F_2 ( V_3 ) ; V_2 ++ ) {
if ( V_1 == V_3 [ V_2 ] )
return 1 ;
}
return 0 ;
}
static void T_1 * F_3 ( T_2 V_4 )
{
if ( F_4 () )
return F_5 ( V_4 ) ;
else
return ( void T_1 * ) ( unsigned long ) V_4 ;
}
static int F_6 ( void T_1 * V_5 )
{
struct V_6 V_7 ;
struct V_8 * V_9 ;
int V_10 ;
if ( F_7 ( & V_7 , V_5 , sizeof( V_7 ) ) )
return - V_11 ;
if ( ! F_1 ( V_7 . V_1 ) )
return - V_12 ;
V_9 = ( void * ) F_8 ( V_13 | V_14 ) ;
if ( ! V_9 )
return - V_15 ;
if ( F_7 ( V_9 , F_3 ( V_7 . V_9 ) , sizeof( * V_9 ) ) ) {
V_10 = - V_11 ;
goto V_16;
}
if ( V_9 -> V_17 > V_18 || V_9 -> V_17 < 8 )
return - V_19 ;
if ( F_7 ( V_9 , F_3 ( V_7 . V_9 ) , V_9 -> V_17 ) ) {
V_10 = - V_11 ;
goto V_16;
}
V_10 = F_9 ( V_7 . V_1 , V_9 ) ;
if ( V_10 )
goto V_16;
if ( F_10 ( F_3 ( V_7 . V_9 ) , V_9 , V_9 -> V_17 ) )
V_10 = - V_11 ;
V_16:
F_11 ( ( unsigned long ) V_9 ) ;
return V_10 ;
}
static long F_12 ( struct V_20 * V_21 , unsigned int V_22 ,
unsigned long V_23 )
{
void T_1 * V_24 ;
if ( F_4 () )
V_24 = F_5 ( V_23 ) ;
else
V_24 = ( void T_1 * ) V_23 ;
switch ( V_22 ) {
case V_25 :
return F_6 ( V_24 ) ;
default:
return - V_26 ;
}
}
static int T_3 F_13 ( void )
{
return F_14 ( & V_27 ) ;
}
static void T_4 F_15 ( void )
{
F_16 ( & V_27 ) ;
}
