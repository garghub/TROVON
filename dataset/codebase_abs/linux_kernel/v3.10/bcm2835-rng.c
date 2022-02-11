static int F_1 ( struct V_1 * V_2 , void * V_3 , T_1 V_4 ,
bool V_5 )
{
void T_2 * V_6 = ( void T_2 * ) V_2 -> V_7 ;
while ( ( F_2 ( V_6 + V_8 ) >> 24 ) == 0 ) {
if ( ! V_5 )
return 0 ;
F_3 () ;
}
* ( V_9 * ) V_3 = F_2 ( V_6 + V_10 ) ;
return sizeof( V_9 ) ;
}
static int F_4 ( struct V_11 * V_12 )
{
struct V_13 * V_14 = & V_12 -> V_14 ;
struct V_15 * V_16 = V_14 -> V_17 ;
void T_2 * V_6 ;
int V_18 ;
V_6 = F_5 ( V_16 , 0 ) ;
if ( ! V_6 ) {
F_6 ( V_14 , L_1 ) ;
return - V_19 ;
}
V_20 . V_7 = ( unsigned long ) V_6 ;
V_18 = F_7 ( & V_20 ) ;
if ( V_18 ) {
F_6 ( V_14 , L_2 ) ;
F_8 ( V_6 ) ;
} else {
F_9 ( V_14 , L_3 ) ;
F_10 ( V_21 , V_6 + V_8 ) ;
F_10 ( V_22 , V_6 + V_23 ) ;
}
return V_18 ;
}
static int F_11 ( struct V_11 * V_12 )
{
void T_2 * V_6 = ( void T_2 * ) V_20 . V_7 ;
F_10 ( 0 , V_6 + V_23 ) ;
F_12 ( & V_20 ) ;
F_8 ( V_6 ) ;
return 0 ;
}
