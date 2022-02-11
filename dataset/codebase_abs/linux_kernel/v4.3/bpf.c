static T_1 F_1 ( void * V_1 )
{
return ( T_1 ) ( unsigned long ) V_1 ;
}
static int F_2 ( enum V_2 V_3 , union V_4 * V_5 ,
unsigned int V_6 )
{
return F_3 ( V_7 , V_3 , V_5 , V_6 ) ;
}
int F_4 ( enum V_8 V_9 , int V_10 ,
int V_11 , int V_12 )
{
union V_4 V_5 ;
memset ( & V_5 , '\0' , sizeof( V_5 ) ) ;
V_5 . V_9 = V_9 ;
V_5 . V_10 = V_10 ;
V_5 . V_11 = V_11 ;
V_5 . V_12 = V_12 ;
return F_2 ( V_13 , & V_5 , sizeof( V_5 ) ) ;
}
int F_5 ( enum V_14 type , struct V_15 * V_16 ,
T_2 V_17 , char * V_18 ,
T_3 V_19 , char * V_20 , T_2 V_21 )
{
int V_22 ;
union V_4 V_5 ;
F_6 ( & V_5 , sizeof( V_5 ) ) ;
V_5 . V_23 = type ;
V_5 . V_24 = ( V_25 ) V_17 ;
V_5 . V_16 = F_1 ( V_16 ) ;
V_5 . V_18 = F_1 ( V_18 ) ;
V_5 . V_20 = F_1 ( NULL ) ;
V_5 . V_26 = 0 ;
V_5 . V_27 = 0 ;
V_5 . V_19 = V_19 ;
V_22 = F_2 ( V_28 , & V_5 , sizeof( V_5 ) ) ;
if ( V_22 >= 0 || ! V_20 || ! V_21 )
return V_22 ;
V_5 . V_20 = F_1 ( V_20 ) ;
V_5 . V_26 = V_21 ;
V_5 . V_27 = 1 ;
V_20 [ 0 ] = 0 ;
return F_2 ( V_28 , & V_5 , sizeof( V_5 ) ) ;
}
