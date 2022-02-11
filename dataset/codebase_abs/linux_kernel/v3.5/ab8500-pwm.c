int F_1 ( struct V_1 * V_2 , int V_3 , int V_4 )
{
int V_5 = 0 ;
unsigned int V_6 , V_7 ;
T_1 V_8 ;
V_7 = V_3 & 0x00FF ;
V_6 = ( ( V_3 & 0x0300 ) >> 8 ) ;
V_8 = V_9 + ( ( V_2 -> V_10 - 1 ) * 2 ) ;
V_5 = F_2 ( V_2 -> V_11 , V_12 ,
V_8 , ( T_1 ) V_7 ) ;
if ( V_5 < 0 )
return V_5 ;
V_5 = F_2 ( V_2 -> V_11 , V_12 ,
( V_8 + 1 ) , ( T_1 ) V_6 ) ;
return V_5 ;
}
int F_3 ( struct V_1 * V_2 )
{
int V_5 ;
V_5 = F_4 ( V_2 -> V_11 ,
V_12 , V_13 ,
1 << ( V_2 -> V_10 - 1 ) , V_14 ) ;
if ( V_5 < 0 )
F_5 ( V_2 -> V_11 , L_1 ,
V_2 -> V_15 , V_5 ) ;
return V_5 ;
}
void F_6 ( struct V_1 * V_2 )
{
int V_5 ;
V_5 = F_4 ( V_2 -> V_11 ,
V_12 , V_13 ,
1 << ( V_2 -> V_10 - 1 ) , V_16 ) ;
if ( V_5 < 0 )
F_5 ( V_2 -> V_11 , L_1 ,
V_2 -> V_15 , V_5 ) ;
return;
}
struct V_1 * F_7 ( int V_10 , const char * V_15 )
{
struct V_1 * V_2 ;
F_8 (pwm, &pwm_list, node) {
if ( V_2 -> V_10 == V_10 ) {
V_2 -> V_15 = V_15 ;
V_2 -> V_10 = V_10 ;
return V_2 ;
}
}
return F_9 ( - V_17 ) ;
}
void F_10 ( struct V_1 * V_2 )
{
F_6 ( V_2 ) ;
}
static int T_2 F_11 ( struct V_18 * V_19 )
{
struct V_1 * V_2 ;
V_2 = F_12 ( sizeof( struct V_1 ) , V_20 ) ;
if ( V_2 == NULL ) {
F_5 ( & V_19 -> V_11 , L_2 ) ;
return - V_21 ;
}
V_2 -> V_11 = & V_19 -> V_11 ;
V_2 -> V_10 = V_19 -> V_22 ;
F_13 ( & V_2 -> V_23 , & V_24 ) ;
F_14 ( V_19 , V_2 ) ;
F_15 ( V_2 -> V_11 , L_3 ) ;
return 0 ;
}
static int T_3 F_16 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = F_17 ( V_19 ) ;
F_18 ( & V_2 -> V_23 ) ;
F_15 ( & V_19 -> V_11 , L_4 ) ;
F_19 ( V_2 ) ;
return 0 ;
}
static int T_4 F_20 ( void )
{
return F_21 ( & V_25 ) ;
}
static void T_5 F_22 ( void )
{
F_23 ( & V_25 ) ;
}
