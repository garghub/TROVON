void * F_1 ( struct V_1 * V_2 , T_1 V_3 ,
T_2 * V_4 , T_3 V_5 )
{
void * V_6 ;
V_6 = F_2 ( V_3 , V_5 ) ;
if ( ! V_6 )
return NULL ;
* V_4 = F_3 ( V_2 , V_6 ) ;
return V_6 ;
}
void F_4 ( struct V_1 * V_2 , T_1 V_3 , void * V_7 ,
T_2 V_4 )
{
F_5 ( ( void * ) F_6 ( V_2 , V_4 ) ,
V_3 ) ;
}
void * F_7 ( struct V_1 * V_2 , T_1 V_3 ,
T_2 * V_4 , T_3 V_5 )
{
void * V_6 , * V_8 ;
V_6 = F_2 ( V_3 , V_5 ) ;
if ( ! V_6 )
return NULL ;
V_8 = F_8 ( ( unsigned long ) V_6 , V_3 ) ;
if ( V_8 != NULL )
memset ( V_8 , 0 , V_3 ) ;
* V_4 = F_3 ( V_2 , V_6 ) ;
return V_8 ;
}
void F_9 ( struct V_1 * V_2 , T_1 V_3 , void * V_8 ,
T_2 V_4 )
{
F_10 ( ( void V_9 V_10 * ) V_8 ) ;
F_5 ( ( void * ) F_6 ( V_2 , V_4 ) ,
V_3 ) ;
}
void F_11 ( unsigned long V_6 , T_1 V_3 ,
enum V_11 V_12 )
{
F_12 ( V_6 , V_3 , V_12 ) ;
}
