static struct V_1 * F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
struct V_1 * V_1 ;
char V_4 [ 12 ] ;
sprintf ( V_4 , L_1 , V_3 ) ;
F_2 ( L_2 , V_4 ) ;
if ( V_2 ) {
T_2 V_5 ;
V_5 = F_3 ( F_4 ( V_2 , 1 ) ,
& V_6 , V_4 ) ;
if ( F_5 ( V_5 ) )
V_1 = F_6 ( V_5 ) ;
else
V_1 = F_7 ( V_5 ) ;
} else {
V_1 = F_8 ( & V_6 , V_4 , NULL ) ;
}
if ( F_5 ( V_1 ) ) {
F_9 ( L_3 ,
V_4 , F_10 ( V_1 ) ) ;
switch ( F_10 ( V_1 ) ) {
case - V_7 :
case - V_8 :
case - V_9 :
return F_11 ( - V_10 ) ;
default:
return V_1 ;
}
}
F_2 ( L_4 , V_11 , F_12 ( V_1 ) ) ;
return V_1 ;
}
int F_13 ( struct V_1 * V_2 , const char * V_12 ,
int V_13 , const char * V_14 , int V_15 )
{
struct V_16 V_17 ;
struct V_18 * V_19 = (struct V_18 * ) V_12 ;
struct V_1 * V_1 ;
int V_20 = - V_21 ;
if ( V_13 <= sizeof( * V_19 ) )
return - V_22 ;
V_13 -= sizeof( * V_19 ) ;
if ( V_13 != F_14 ( V_19 -> V_23 ) )
return - V_22 ;
if ( V_19 -> V_24 >= V_25 )
return - V_26 ;
V_1 = F_1 ( V_2 , F_15 ( V_19 -> V_3 ) ) ;
if ( F_5 ( V_1 ) )
return F_10 ( V_1 ) ;
memset ( & V_17 , 0 , sizeof( V_17 ) ) ;
V_17 . V_27 = V_19 -> V_24 ;
V_17 . V_28 = ( V_29 * ) V_14 ;
V_17 . V_30 = V_15 ;
V_17 . V_31 = 1 ;
V_17 . V_32 . V_33 = F_16 ( V_19 -> V_12 , V_13 ) ;
if ( V_17 . V_32 . V_33 )
V_20 = F_17 ( V_1 , & V_17 ) ;
F_18 ( V_17 . V_32 . V_33 ) ;
F_19 ( V_1 ) ;
F_2 ( L_5 , V_11 , V_20 ) ;
return V_20 ;
}
