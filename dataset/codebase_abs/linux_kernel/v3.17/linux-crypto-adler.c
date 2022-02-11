static T_1 F_1 ( T_1 V_1 , unsigned char const * V_2 , T_2 V_3 )
{
return F_2 ( V_1 , V_2 , V_3 ) ;
}
static int F_3 ( struct V_4 * V_5 )
{
T_1 * V_6 = F_4 ( V_5 ) ;
* V_6 = 1 ;
return 0 ;
}
static int F_5 ( struct V_7 * V_8 , const T_3 * V_6 ,
unsigned int V_9 )
{
T_1 * V_10 = F_6 ( V_8 ) ;
if ( V_9 != sizeof( T_1 ) ) {
F_7 ( V_8 , V_11 ) ;
return - V_12 ;
}
* V_10 = * ( T_1 * ) V_6 ;
return 0 ;
}
static int F_8 ( struct V_13 * V_14 )
{
T_1 * V_10 = F_6 ( V_14 -> V_5 ) ;
T_1 * V_15 = F_9 ( V_14 ) ;
* V_15 = * V_10 ;
return 0 ;
}
static int F_10 ( struct V_13 * V_14 , const T_3 * V_16 ,
unsigned int V_3 )
{
T_1 * V_15 = F_9 ( V_14 ) ;
* V_15 = F_1 ( * V_15 , V_16 , V_3 ) ;
return 0 ;
}
static int F_11 ( T_1 * V_15 , const T_3 * V_16 , unsigned int V_3 ,
T_3 * V_17 )
{
* ( T_1 * ) V_17 = F_1 ( * V_15 , V_16 , V_3 ) ;
return 0 ;
}
static int F_12 ( struct V_13 * V_14 , const T_3 * V_16 ,
unsigned int V_3 , T_3 * V_17 )
{
return F_11 ( F_9 ( V_14 ) , V_16 , V_3 , V_17 ) ;
}
static int F_13 ( struct V_13 * V_14 , T_3 * V_17 )
{
T_1 * V_15 = F_9 ( V_14 ) ;
* ( T_1 * ) V_17 = * V_15 ;
return 0 ;
}
static int F_14 ( struct V_13 * V_14 , const T_3 * V_16 ,
unsigned int V_3 , T_3 * V_17 )
{
return F_11 ( F_6 ( V_14 -> V_5 ) , V_16 , V_3 ,
V_17 ) ;
}
int F_15 ( void )
{
return F_16 ( & V_18 ) ;
}
void F_17 ( void )
{
F_18 ( & V_18 ) ;
}
