static int F_1 ( T_1 V_1 , struct V_2 * V_3 )
{
int V_4 = V_3 -> V_4 ;
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
if ( V_1 == V_19 ) {
T_3 * V_20 = F_7 ( V_21 , V_22 ) ;
if ( V_20 == NULL )
return - V_23 ;
if ( F_8 ( V_20 , ( T_3 * ) V_14 , V_21 ) ) {
F_9 ( V_20 ) ;
return - V_24 ;
}
V_15 = F_10 ( V_20 , V_21 ) ;
F_9 ( V_20 ) ;
return V_15 ;
} else {
if ( F_8 ( & V_3 , V_16 , sizeof( struct V_2 ) ) )
return - V_24 ;
V_15 = F_1 ( V_1 , & V_3 ) ;
if ( V_15 < 0 )
return V_15 ;
if ( F_11 ( V_16 , & V_3 , sizeof( struct V_2 ) ) )
return - V_24 ;
return 0 ;
}
}
static int T_4 F_12 ( void )
{
V_25 = F_13 ( 0 , L_1 , & V_26 ) ;
if ( V_25 < 0 )
return V_25 ;
return 0 ;
}
static void T_5 F_14 ( void )
{
F_15 ( V_25 , L_1 ) ;
}
