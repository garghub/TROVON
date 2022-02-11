unsigned int F_1 ( void )
{
return V_1 ;
}
void F_2 ( unsigned int V_2 )
{
V_1 = V_2 ;
}
static unsigned long F_3 ( const T_1 * V_3 )
{
return V_3 -> V_4 ;
}
static int F_4 ( const T_1 * V_5 , const T_1 * V_6 )
{
return V_5 -> V_4 - V_6 -> V_4 ;
}
static void F_5 ( T_1 * V_7 , T_2 * V_8 )
{
int V_9 ;
while( ( V_9 = F_6 ( V_7 -> V_10 , V_8 ) ) >= 0 )
{
F_7 ( V_7 -> V_10 , V_9 ) ;
V_7 -> V_11 = 1 ;
}
if( V_7 -> V_12 == V_8 )
{
F_8 ( V_8 , 0 ) ;
V_7 -> V_12 = NULL ;
}
}
void F_9 ( T_1 * V_13 )
{
F_10 ( V_13 -> V_10 ) ;
if( V_13 -> V_12 )
F_8 ( V_13 -> V_12 , 0 ) ;
F_11 ( V_13 ) ;
}
