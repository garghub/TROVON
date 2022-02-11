static int F_1 ( T_1 V_1 , struct V_2 * V_3 )
{
unsigned int V_4 = V_3 -> V_4 ;
if ( V_4 == 0 || V_4 == 3 || V_4 > 4 )
return - V_5 ;
switch ( V_1 ) {
case V_6 :
return F_2 ( V_3 -> V_7 , V_3 -> V_3 , V_4 ) ;
case V_8 :
return F_3 ( V_3 -> V_7 , V_3 -> V_3 , V_4 ) ;
case V_9 :
return F_4 ( V_3 -> V_7 [ 0 ] ,
V_3 -> V_3 [ 0 ] , V_3 -> V_10 ) ;
default:
return - V_11 ;
}
}
static long F_5 ( struct V_12 * V_13 , unsigned int V_1 ,
unsigned long V_14 )
{
int V_15 ;
struct V_2 V_3 ;
void T_2 * V_16 = ( void T_2 * ) V_14 ;
if ( ! F_6 ( V_17 ) )
return - V_18 ;
if ( F_7 ( & V_3 , V_16 , sizeof( struct V_2 ) ) )
return - V_19 ;
V_15 = F_1 ( V_1 , & V_3 ) ;
if ( V_15 < 0 )
return V_15 ;
if ( F_8 ( V_16 , & V_3 , sizeof( struct V_2 ) ) )
return - V_19 ;
return 0 ;
}
static int T_3 F_9 ( void )
{
V_20 = F_10 ( 0 , L_1 , & V_21 ) ;
if ( V_20 < 0 )
return V_20 ;
return 0 ;
}
static void T_4 F_11 ( void )
{
F_12 ( V_20 , L_1 ) ;
}
