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
int F_9 ( int V_11 , const char * V_35 )
{
union V_7 V_8 = {
. V_35 = F_1 ( ( void * ) V_35 ) ,
. V_36 = V_11 ,
} ;
return F_3 ( V_9 , V_37 , & V_8 , sizeof( V_8 ) ) ;
}
int F_10 ( const char * V_35 )
{
union V_7 V_8 = {
. V_35 = F_1 ( ( void * ) V_35 ) ,
} ;
return F_3 ( V_9 , V_38 , & V_8 , sizeof( V_8 ) ) ;
}
int F_11 ( const char * V_39 )
{
struct V_40 V_41 ;
int V_42 ;
V_42 = F_12 ( V_43 , V_44 | V_45 | V_46 , F_13 ( V_47 ) ) ;
if ( V_42 < 0 ) {
printf ( L_1 ) ;
return - 1 ;
}
memset ( & V_41 , 0 , sizeof( V_41 ) ) ;
V_41 . V_48 = V_49 ;
V_41 . V_50 = F_14 ( V_39 ) ;
V_41 . V_51 = F_13 ( V_47 ) ;
if ( F_15 ( V_42 , (struct V_52 * ) & V_41 , sizeof( V_41 ) ) < 0 ) {
printf ( L_2 , V_39 , strerror ( V_53 ) ) ;
F_16 ( V_42 ) ;
return - 1 ;
}
return V_42 ;
}
int F_17 ( struct V_54 * V_8 , int V_55 , int V_56 ,
int V_57 , unsigned long V_14 )
{
return F_3 ( V_58 , V_8 , V_55 , V_56 ,
V_57 , V_14 ) ;
}
