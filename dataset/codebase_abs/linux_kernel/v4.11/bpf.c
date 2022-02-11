static inline T_1 F_1 ( const void * V_1 )
{
return ( T_1 ) ( unsigned long ) V_1 ;
}
static inline int F_2 ( enum V_2 V_3 , union V_4 * V_5 ,
unsigned int V_6 )
{
return F_3 ( V_7 , V_3 , V_5 , V_6 ) ;
}
int F_4 ( enum V_8 V_9 , int V_10 ,
int V_11 , int V_12 , T_2 V_13 )
{
union V_4 V_5 ;
memset ( & V_5 , '\0' , sizeof( V_5 ) ) ;
V_5 . V_9 = V_9 ;
V_5 . V_10 = V_10 ;
V_5 . V_11 = V_11 ;
V_5 . V_12 = V_12 ;
V_5 . V_13 = V_13 ;
return F_2 ( V_14 , & V_5 , sizeof( V_5 ) ) ;
}
int F_5 ( enum V_15 type , const struct V_16 * V_17 ,
T_3 V_18 , const char * V_19 ,
T_2 V_20 , char * V_21 , T_3 V_22 )
{
int V_23 ;
union V_4 V_5 ;
F_6 ( & V_5 , sizeof( V_5 ) ) ;
V_5 . V_24 = type ;
V_5 . V_25 = ( T_2 ) V_18 ;
V_5 . V_17 = F_1 ( V_17 ) ;
V_5 . V_19 = F_1 ( V_19 ) ;
V_5 . V_21 = F_1 ( NULL ) ;
V_5 . V_26 = 0 ;
V_5 . V_27 = 0 ;
V_5 . V_20 = V_20 ;
V_23 = F_2 ( V_28 , & V_5 , sizeof( V_5 ) ) ;
if ( V_23 >= 0 || ! V_21 || ! V_22 )
return V_23 ;
V_5 . V_21 = F_1 ( V_21 ) ;
V_5 . V_26 = V_22 ;
V_5 . V_27 = 1 ;
V_21 [ 0 ] = 0 ;
return F_2 ( V_28 , & V_5 , sizeof( V_5 ) ) ;
}
int F_7 ( int V_23 , const void * V_29 , const void * V_30 ,
T_1 V_31 )
{
union V_4 V_5 ;
F_6 ( & V_5 , sizeof( V_5 ) ) ;
V_5 . V_32 = V_23 ;
V_5 . V_29 = F_1 ( V_29 ) ;
V_5 . V_30 = F_1 ( V_30 ) ;
V_5 . V_31 = V_31 ;
return F_2 ( V_33 , & V_5 , sizeof( V_5 ) ) ;
}
int F_8 ( int V_23 , const void * V_29 , void * V_30 )
{
union V_4 V_5 ;
F_6 ( & V_5 , sizeof( V_5 ) ) ;
V_5 . V_32 = V_23 ;
V_5 . V_29 = F_1 ( V_29 ) ;
V_5 . V_30 = F_1 ( V_30 ) ;
return F_2 ( V_34 , & V_5 , sizeof( V_5 ) ) ;
}
int F_9 ( int V_23 , const void * V_29 )
{
union V_4 V_5 ;
F_6 ( & V_5 , sizeof( V_5 ) ) ;
V_5 . V_32 = V_23 ;
V_5 . V_29 = F_1 ( V_29 ) ;
return F_2 ( V_35 , & V_5 , sizeof( V_5 ) ) ;
}
int F_10 ( int V_23 , const void * V_29 , void * V_36 )
{
union V_4 V_5 ;
F_6 ( & V_5 , sizeof( V_5 ) ) ;
V_5 . V_32 = V_23 ;
V_5 . V_29 = F_1 ( V_29 ) ;
V_5 . V_36 = F_1 ( V_36 ) ;
return F_2 ( V_37 , & V_5 , sizeof( V_5 ) ) ;
}
int F_11 ( int V_23 , const char * V_38 )
{
union V_4 V_5 ;
F_6 ( & V_5 , sizeof( V_5 ) ) ;
V_5 . V_38 = F_1 ( ( void * ) V_38 ) ;
V_5 . V_39 = V_23 ;
return F_2 ( V_40 , & V_5 , sizeof( V_5 ) ) ;
}
int F_12 ( const char * V_38 )
{
union V_4 V_5 ;
F_6 ( & V_5 , sizeof( V_5 ) ) ;
V_5 . V_38 = F_1 ( ( void * ) V_38 ) ;
return F_2 ( V_41 , & V_5 , sizeof( V_5 ) ) ;
}
int F_13 ( int V_42 , int V_43 , enum V_44 type ,
unsigned int V_31 )
{
union V_4 V_5 ;
F_6 ( & V_5 , sizeof( V_5 ) ) ;
V_5 . V_43 = V_43 ;
V_5 . V_45 = V_42 ;
V_5 . V_46 = type ;
V_5 . V_47 = V_31 ;
return F_2 ( V_48 , & V_5 , sizeof( V_5 ) ) ;
}
int F_14 ( int V_43 , enum V_44 type )
{
union V_4 V_5 ;
F_6 ( & V_5 , sizeof( V_5 ) ) ;
V_5 . V_43 = V_43 ;
V_5 . V_46 = type ;
return F_2 ( V_49 , & V_5 , sizeof( V_5 ) ) ;
}
