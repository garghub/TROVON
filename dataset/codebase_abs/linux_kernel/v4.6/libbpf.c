static T_1 F_1 ( void * V_1 )
{
return ( T_1 ) ( unsigned long ) V_1 ;
}
int F_2 ( enum V_2 V_3 , int V_4 , int V_5 ,
int V_6 , int V_7 )
{
union V_8 V_9 = {
. V_3 = V_3 ,
. V_4 = V_4 ,
. V_5 = V_5 ,
. V_6 = V_6 ,
. V_7 = V_7 ,
} ;
return F_3 ( V_10 , V_11 , & V_9 , sizeof( V_9 ) ) ;
}
int F_4 ( int V_12 , void * V_13 , void * V_14 , unsigned long long V_15 )
{
union V_8 V_9 = {
. V_16 = V_12 ,
. V_13 = F_1 ( V_13 ) ,
. V_14 = F_1 ( V_14 ) ,
. V_15 = V_15 ,
} ;
return F_3 ( V_10 , V_17 , & V_9 , sizeof( V_9 ) ) ;
}
int F_5 ( int V_12 , void * V_13 , void * V_14 )
{
union V_8 V_9 = {
. V_16 = V_12 ,
. V_13 = F_1 ( V_13 ) ,
. V_14 = F_1 ( V_14 ) ,
} ;
return F_3 ( V_10 , V_18 , & V_9 , sizeof( V_9 ) ) ;
}
int F_6 ( int V_12 , void * V_13 )
{
union V_8 V_9 = {
. V_16 = V_12 ,
. V_13 = F_1 ( V_13 ) ,
} ;
return F_3 ( V_10 , V_19 , & V_9 , sizeof( V_9 ) ) ;
}
int F_7 ( int V_12 , void * V_13 , void * V_20 )
{
union V_8 V_9 = {
. V_16 = V_12 ,
. V_13 = F_1 ( V_13 ) ,
. V_20 = F_1 ( V_20 ) ,
} ;
return F_3 ( V_10 , V_21 , & V_9 , sizeof( V_9 ) ) ;
}
int F_8 ( enum V_22 V_23 ,
const struct V_24 * V_25 , int V_26 ,
const char * V_27 , int V_28 )
{
union V_8 V_9 = {
. V_23 = V_23 ,
. V_25 = F_1 ( ( void * ) V_25 ) ,
. V_29 = V_26 / sizeof( struct V_24 ) ,
. V_27 = F_1 ( ( void * ) V_27 ) ,
. V_30 = F_1 ( V_31 ) ,
. V_32 = V_33 ,
. V_34 = 1 ,
} ;
V_9 . V_28 = V_28 ;
V_31 [ 0 ] = 0 ;
return F_3 ( V_10 , V_35 , & V_9 , sizeof( V_9 ) ) ;
}
int F_9 ( int V_12 , const char * V_36 )
{
union V_8 V_9 = {
. V_36 = F_1 ( ( void * ) V_36 ) ,
. V_37 = V_12 ,
} ;
return F_3 ( V_10 , V_38 , & V_9 , sizeof( V_9 ) ) ;
}
int F_10 ( const char * V_36 )
{
union V_8 V_9 = {
. V_36 = F_1 ( ( void * ) V_36 ) ,
} ;
return F_3 ( V_10 , V_39 , & V_9 , sizeof( V_9 ) ) ;
}
int F_11 ( const char * V_40 )
{
struct V_41 V_42 ;
int V_43 ;
V_43 = F_12 ( V_44 , V_45 | V_46 | V_47 , F_13 ( V_48 ) ) ;
if ( V_43 < 0 ) {
printf ( L_1 ) ;
return - 1 ;
}
memset ( & V_42 , 0 , sizeof( V_42 ) ) ;
V_42 . V_49 = V_50 ;
V_42 . V_51 = F_14 ( V_40 ) ;
V_42 . V_52 = F_13 ( V_48 ) ;
if ( F_15 ( V_43 , (struct V_53 * ) & V_42 , sizeof( V_42 ) ) < 0 ) {
printf ( L_2 , V_40 , strerror ( V_54 ) ) ;
F_16 ( V_43 ) ;
return - 1 ;
}
return V_43 ;
}
int F_17 ( struct V_55 * V_9 , int V_56 , int V_57 ,
int V_58 , unsigned long V_15 )
{
return F_3 ( V_59 , V_9 , V_56 , V_57 ,
V_58 , V_15 ) ;
}
