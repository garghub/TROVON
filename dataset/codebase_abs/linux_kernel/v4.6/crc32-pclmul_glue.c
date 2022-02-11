static int F_1 ( struct V_1 * V_2 )
{
T_1 * V_3 = F_2 ( V_2 ) ;
* V_3 = 0 ;
return 0 ;
}
static int F_3 ( struct V_4 * V_5 , const T_2 * V_3 ,
unsigned int V_6 )
{
T_1 * V_7 = F_4 ( V_5 ) ;
if ( V_6 != sizeof( T_1 ) ) {
F_5 ( V_5 , V_8 ) ;
return - V_9 ;
}
* V_7 = F_6 ( ( V_10 * ) V_3 ) ;
return 0 ;
}
static int F_7 ( struct V_11 * V_12 )
{
T_1 * V_7 = F_4 ( V_12 -> V_2 ) ;
T_1 * V_13 = F_8 ( V_12 ) ;
* V_13 = * V_7 ;
return 0 ;
}
static int F_9 ( struct V_11 * V_12 , const T_2 * V_14 ,
unsigned int V_15 )
{
T_1 * V_13 = F_8 ( V_12 ) ;
* V_13 = F_10 ( * V_13 , V_14 , V_15 ) ;
return 0 ;
}
static int F_11 ( T_1 * V_13 , const T_2 * V_14 , unsigned int V_15 ,
T_2 * V_16 )
{
* ( V_10 * ) V_16 = F_12 ( F_10 ( * V_13 , V_14 , V_15 ) ) ;
return 0 ;
}
static int F_13 ( struct V_11 * V_12 , const T_2 * V_14 ,
unsigned int V_15 , T_2 * V_16 )
{
return F_11 ( F_8 ( V_12 ) , V_14 , V_15 , V_16 ) ;
}
static int F_14 ( struct V_11 * V_12 , T_2 * V_16 )
{
T_1 * V_13 = F_8 ( V_12 ) ;
* ( V_10 * ) V_16 = F_15 ( V_13 ) ;
return 0 ;
}
static int F_16 ( struct V_11 * V_12 , const T_2 * V_14 ,
unsigned int V_15 , T_2 * V_16 )
{
return F_11 ( F_4 ( V_12 -> V_2 ) , V_14 , V_15 ,
V_16 ) ;
}
static int T_3 F_17 ( void )
{
if ( ! F_18 ( V_17 ) ) {
F_19 ( L_1 ) ;
return - V_18 ;
}
return F_20 ( & V_19 ) ;
}
static void T_4 F_21 ( void )
{
F_22 ( & V_19 ) ;
}
