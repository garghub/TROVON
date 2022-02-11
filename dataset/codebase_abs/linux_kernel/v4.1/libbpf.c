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
const char * V_26 , int V_27 )
{
union V_7 V_8 = {
. V_22 = V_22 ,
. V_24 = F_1 ( ( void * ) V_24 ) ,
. V_28 = V_25 / sizeof( struct V_23 ) ,
. V_26 = F_1 ( ( void * ) V_26 ) ,
. V_29 = F_1 ( V_30 ) ,
. V_31 = V_32 ,
. V_33 = 1 ,
} ;
V_8 . V_27 = V_27 ;
V_30 [ 0 ] = 0 ;
return F_3 ( V_9 , V_34 , & V_8 , sizeof( V_8 ) ) ;
}
int F_9 ( const char * V_35 )
{
struct V_36 V_37 ;
int V_38 ;
V_38 = F_10 ( V_39 , V_40 | V_41 | V_42 , F_11 ( V_43 ) ) ;
if ( V_38 < 0 ) {
printf ( L_1 ) ;
return - 1 ;
}
memset ( & V_37 , 0 , sizeof( V_37 ) ) ;
V_37 . V_44 = V_45 ;
V_37 . V_46 = F_12 ( V_35 ) ;
V_37 . V_47 = F_11 ( V_43 ) ;
if ( F_13 ( V_38 , (struct V_48 * ) & V_37 , sizeof( V_37 ) ) < 0 ) {
printf ( L_2 , V_35 , strerror ( V_49 ) ) ;
F_14 ( V_38 ) ;
return - 1 ;
}
return V_38 ;
}
int F_15 ( struct V_50 * V_8 , int V_51 , int V_52 ,
int V_53 , unsigned long V_14 )
{
return F_3 ( V_54 , V_8 , V_51 , V_52 ,
V_53 , V_14 ) ;
}
