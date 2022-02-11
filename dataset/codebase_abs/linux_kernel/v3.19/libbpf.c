static T_1 F_1 ( void * V_1 )
{
return ( T_1 ) ( unsigned long ) V_1 ;
}
int F_2 ( enum V_2 V_3 , int V_4 , int V_5 ,
int V_6 )
{
union V_7 V_8 = {
. V_3 = V_3 ,
. V_4 = V_4 ,
. V_5 = V_5 ,
. V_6 = V_6
} ;
return F_3 ( V_9 , V_10 , & V_8 , sizeof( V_8 ) ) ;
}
int F_4 ( int V_11 , void * V_12 , void * V_13 , unsigned long long V_14 )
{
union V_7 V_8 = {
. V_15 = V_11 ,
. V_12 = F_1 ( V_12 ) ,
. V_13 = F_1 ( V_13 ) ,
. V_14 = V_14 ,
} ;
return F_3 ( V_9 , V_16 , & V_8 , sizeof( V_8 ) ) ;
}
int F_5 ( int V_11 , void * V_12 , void * V_13 )
{
union V_7 V_8 = {
. V_15 = V_11 ,
. V_12 = F_1 ( V_12 ) ,
. V_13 = F_1 ( V_13 ) ,
} ;
return F_3 ( V_9 , V_17 , & V_8 , sizeof( V_8 ) ) ;
}
int F_6 ( int V_11 , void * V_12 )
{
union V_7 V_8 = {
. V_15 = V_11 ,
. V_12 = F_1 ( V_12 ) ,
} ;
return F_3 ( V_9 , V_18 , & V_8 , sizeof( V_8 ) ) ;
}
int F_7 ( int V_11 , void * V_12 , void * V_19 )
{
union V_7 V_8 = {
. V_15 = V_11 ,
. V_12 = F_1 ( V_12 ) ,
. V_19 = F_1 ( V_19 ) ,
} ;
return F_3 ( V_9 , V_20 , & V_8 , sizeof( V_8 ) ) ;
}
int F_8 ( enum V_21 V_22 ,
const struct V_23 * V_24 , int V_25 ,
const char * V_26 )
{
union V_7 V_8 = {
. V_22 = V_22 ,
. V_24 = F_1 ( ( void * ) V_24 ) ,
. V_27 = V_25 / sizeof( struct V_23 ) ,
. V_26 = F_1 ( ( void * ) V_26 ) ,
. V_28 = F_1 ( V_29 ) ,
. V_30 = V_31 ,
. V_32 = 1 ,
} ;
V_29 [ 0 ] = 0 ;
return F_3 ( V_9 , V_33 , & V_8 , sizeof( V_8 ) ) ;
}
int F_9 ( const char * V_34 )
{
struct V_35 V_36 ;
int V_37 ;
V_37 = F_10 ( V_38 , V_39 | V_40 | V_41 , F_11 ( V_42 ) ) ;
if ( V_37 < 0 ) {
printf ( L_1 ) ;
return - 1 ;
}
memset ( & V_36 , 0 , sizeof( V_36 ) ) ;
V_36 . V_43 = V_44 ;
V_36 . V_45 = F_12 ( V_34 ) ;
V_36 . V_46 = F_11 ( V_42 ) ;
if ( F_13 ( V_37 , (struct V_47 * ) & V_36 , sizeof( V_36 ) ) < 0 ) {
printf ( L_2 , V_34 , strerror ( V_48 ) ) ;
F_14 ( V_37 ) ;
return - 1 ;
}
return V_37 ;
}
