static struct V_1 * F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
struct V_1 * V_1 ;
char V_4 [ 12 ] ;
sprintf ( V_4 , L_1 , V_3 ) ;
F_2 ( L_2 , V_4 ) ;
V_1 = F_3 () ;
if ( V_1 ) {
T_2 V_5 ;
V_5 = F_4 ( F_5 ( V_1 , 1 ) ,
& V_6 , V_4 ) ;
if ( ! F_6 ( V_5 ) ) {
F_7 ( L_3 , V_4 ) ;
return F_8 ( - V_7 ) ;
}
}
if ( V_2 ) {
T_2 V_5 ;
V_5 = F_4 ( F_5 ( V_2 , 1 ) ,
& V_6 , V_4 ) ;
if ( F_6 ( V_5 ) )
V_1 = F_9 ( V_5 ) ;
else
V_1 = F_10 ( V_5 ) ;
} else {
V_1 = F_11 ( & V_6 , V_4 , NULL ) ;
}
if ( F_6 ( V_1 ) ) {
F_12 ( L_4 ,
V_4 , F_13 ( V_1 ) ) ;
switch ( F_13 ( V_1 ) ) {
case - V_8 :
case - V_9 :
case - V_10 :
return F_8 ( - V_11 ) ;
default:
return V_1 ;
}
}
F_2 ( L_5 , V_12 , F_14 ( V_1 ) ) ;
return V_1 ;
}
int F_15 ( struct V_1 * V_2 , const char * V_13 ,
int V_14 , const char * V_15 , int V_16 )
{
struct V_17 V_18 ;
struct V_19 * V_20 = (struct V_19 * ) V_13 ;
struct V_1 * V_1 ;
int V_21 = - V_22 ;
if ( V_14 <= sizeof( * V_20 ) )
return - V_23 ;
V_14 -= sizeof( * V_20 ) ;
if ( V_14 != F_16 ( V_20 -> V_24 ) )
return - V_23 ;
if ( V_20 -> V_25 >= V_26 )
return - V_27 ;
V_1 = F_1 ( V_2 , F_17 ( V_20 -> V_3 ) ) ;
if ( F_6 ( V_1 ) )
return F_13 ( V_1 ) ;
memset ( & V_18 , 0 , sizeof( V_18 ) ) ;
V_18 . V_28 = V_20 -> V_25 ;
V_18 . V_29 = ( V_30 * ) V_15 ;
V_18 . V_31 = V_16 ;
V_18 . V_32 = 1 ;
V_18 . V_33 . V_34 = F_18 ( V_20 -> V_13 , V_14 ) ;
if ( V_18 . V_33 . V_34 )
V_21 = F_19 ( V_1 , & V_18 ) ;
F_20 ( V_18 . V_33 . V_34 ) ;
F_21 ( V_1 ) ;
F_2 ( L_6 , V_12 , V_21 ) ;
return V_21 ;
}
