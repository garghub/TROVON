static int F_1 ( struct V_1 * V_2 )
{
T_1 * V_3 = F_2 ( V_2 ) ;
* V_3 = 1 ;
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
* V_7 = * ( T_1 * ) V_3 ;
return 0 ;
}
static int F_6 ( struct V_10 * V_11 )
{
T_1 * V_7 = F_4 ( V_11 -> V_2 ) ;
T_1 * V_12 = F_7 ( V_11 ) ;
* V_12 = * V_7 ;
return 0 ;
}
static int F_8 ( struct V_10 * V_11 , const T_2 * V_13 ,
unsigned int V_14 )
{
T_1 * V_12 = F_7 ( V_11 ) ;
* V_12 = F_9 ( * V_12 , V_13 , V_14 ) ;
return 0 ;
}
static int F_10 ( T_1 * V_12 , const T_2 * V_13 , unsigned int V_14 ,
T_2 * V_15 )
{
* ( T_1 * ) V_15 = F_9 ( * V_12 , V_13 , V_14 ) ;
return 0 ;
}
static int F_11 ( struct V_10 * V_11 , const T_2 * V_13 ,
unsigned int V_14 , T_2 * V_15 )
{
return F_10 ( F_7 ( V_11 ) , V_13 , V_14 , V_15 ) ;
}
static int F_12 ( struct V_10 * V_11 , T_2 * V_15 )
{
T_1 * V_12 = F_7 ( V_11 ) ;
* ( T_1 * ) V_15 = * V_12 ;
return 0 ;
}
static int F_13 ( struct V_10 * V_11 , const T_2 * V_13 ,
unsigned int V_14 , T_2 * V_15 )
{
return F_10 ( F_4 ( V_11 -> V_2 ) , V_13 , V_14 ,
V_15 ) ;
}
int F_14 ( void )
{
return F_15 ( & V_16 ) ;
}
void F_16 ( void )
{
F_17 ( & V_16 ) ;
}
