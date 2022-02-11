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
unsigned long V_10 ;
int V_11 ;
if ( F_7 ( & V_7 , V_5 , sizeof( V_7 ) ) )
return - V_12 ;
if ( ! F_1 ( V_7 . V_1 ) )
return - V_13 ;
V_9 = ( void * ) F_8 ( V_14 | V_15 ) ;
if ( ! V_9 )
return - V_16 ;
V_10 = V_17 -
F_7 ( V_9 , F_3 ( V_7 . V_9 ) , V_17 ) ;
if ( F_9 ( struct V_8 , V_18 ) +
sizeof( V_9 -> V_18 ) > V_10 || V_9 -> V_18 > V_10 ) {
V_11 = - V_12 ;
goto V_19;
}
if ( V_9 -> V_18 < 8 ) {
V_11 = - V_20 ;
goto V_19;
}
V_11 = F_10 ( V_7 . V_1 , V_9 ) ;
if ( V_11 )
goto V_19;
if ( F_11 ( F_3 ( V_7 . V_9 ) , V_9 , V_9 -> V_18 ) )
V_11 = - V_12 ;
V_19:
F_12 ( ( unsigned long ) V_9 ) ;
return V_11 ;
}
static long F_13 ( struct V_21 * V_22 , unsigned int V_23 ,
unsigned long V_24 )
{
void T_1 * V_25 ;
if ( F_4 () )
V_25 = F_5 ( V_24 ) ;
else
V_25 = ( void T_1 * ) V_24 ;
switch ( V_23 ) {
case V_26 :
return F_6 ( V_25 ) ;
default:
return - V_27 ;
}
}
static int T_3 F_14 ( void )
{
return F_15 ( & V_28 ) ;
}
static void T_4 F_16 ( void )
{
F_17 ( & V_28 ) ;
}
