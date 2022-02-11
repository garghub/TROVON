struct V_1 * F_1 ( void )
{
return V_2 ;
}
void * F_2 ( T_1 V_3 , T_2 * V_4 )
{
unsigned long V_5 ;
T_2 V_6 = V_7 . V_8 ;
if ( V_4 )
* V_4 = 0 ;
if ( ! V_2 || ( V_4 && ! V_6 ) )
return NULL ;
V_5 = F_3 ( V_2 , V_3 ) ;
if ( ! V_5 )
return NULL ;
if ( V_4 )
* V_4 = F_4 ( V_2 , V_5 ) ;
return ( void * ) V_5 ;
}
void F_5 ( void * V_9 , T_1 V_3 )
{
F_6 ( V_2 , ( unsigned long ) V_9 , V_3 ) ;
}
static int T_3 F_7 ( void )
{
T_4 V_10 = V_7 . V_8 ;
unsigned V_3 = V_7 . V_11 ;
int V_12 = 0 ;
void * V_9 ;
if ( V_3 ) {
V_3 = F_8 ( unsigned , V_3 , V_13 ) ;
V_2 = F_9 ( F_10 ( V_14 ) , - 1 ) ;
if ( ! V_2 )
V_12 = - V_15 ;
}
if ( V_2 ) {
V_9 = F_11 ( V_10 , V_3 ) ;
if ( ! V_9 )
return - V_15 ;
V_12 = F_12 ( V_2 , ( unsigned ) V_9 ,
V_10 , V_3 , - 1 ) ;
if ( V_12 < 0 )
F_13 ( V_9 ) ;
}
F_14 ( V_12 < 0 ) ;
return V_12 ;
}
