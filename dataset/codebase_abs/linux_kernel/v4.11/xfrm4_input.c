int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
return F_2 ( V_4 ) ;
}
static inline int F_3 ( struct V_5 * V_5 , struct V_6 * V_7 ,
struct V_3 * V_4 )
{
if ( ! F_4 ( V_4 ) ) {
const struct V_8 * V_9 = F_5 ( V_4 ) ;
if ( F_6 ( V_4 , V_9 -> V_10 , V_9 -> V_11 ,
V_9 -> V_12 , V_4 -> V_13 ) )
goto V_14;
}
return F_7 ( V_4 ) ;
V_14:
F_8 ( V_4 ) ;
return V_15 ;
}
int F_9 ( struct V_3 * V_4 , int V_16 )
{
struct V_17 * V_18 = V_17 ( V_4 ) ;
struct V_8 * V_9 = F_5 ( V_4 ) ;
V_9 -> V_19 = F_10 ( V_4 ) -> V_19 ;
#ifndef F_11
if ( ! V_16 )
return - V_9 -> V_19 ;
#endif
F_12 ( V_4 , V_4 -> V_20 - F_13 ( V_4 ) ) ;
V_9 -> V_21 = F_14 ( V_4 -> V_22 ) ;
F_15 ( V_9 ) ;
if ( V_18 && ( V_18 -> V_23 & V_24 ) ) {
F_16 ( V_4 ) ;
return 0 ;
}
F_17 ( V_25 , V_26 ,
F_18 ( V_4 -> V_13 ) , NULL , V_4 , V_4 -> V_13 , NULL ,
F_3 ) ;
return 0 ;
}
int F_19 ( struct V_6 * V_7 , struct V_3 * V_4 )
{
struct V_27 * V_28 = F_20 ( V_7 ) ;
struct V_29 * V_30 ;
struct V_8 * V_9 ;
int V_31 , V_22 ;
T_1 * V_32 ;
T_2 * V_33 ;
T_3 V_34 = V_28 -> V_34 ;
if ( ! V_34 )
return 1 ;
V_22 = V_4 -> V_22 - sizeof( struct V_29 ) ;
if ( ! F_21 ( V_4 , sizeof( struct V_29 ) + F_22 ( V_22 , 8 ) ) )
return 1 ;
V_30 = F_23 ( V_4 ) ;
V_32 = ( T_1 * ) V_30 + sizeof( struct V_29 ) ;
V_33 = ( T_2 * ) V_32 ;
switch ( V_34 ) {
default:
case V_35 :
if ( V_22 == 1 && V_32 [ 0 ] == 0xff ) {
goto V_14;
} else if ( V_22 > sizeof( struct V_36 ) && V_33 [ 0 ] != 0 ) {
V_22 = sizeof( struct V_29 ) ;
} else
return 1 ;
break;
case V_37 :
if ( V_22 == 1 && V_32 [ 0 ] == 0xff ) {
goto V_14;
} else if ( V_22 > 2 * sizeof( V_38 ) + sizeof( struct V_36 ) &&
V_33 [ 0 ] == 0 && V_33 [ 1 ] == 0 ) {
V_22 = sizeof( struct V_29 ) + 2 * sizeof( V_38 ) ;
} else
return 1 ;
break;
}
if ( F_24 ( V_4 , V_39 ) )
goto V_14;
V_9 = F_5 ( V_4 ) ;
V_31 = V_9 -> V_40 << 2 ;
V_9 -> V_21 = F_14 ( F_25 ( V_9 -> V_21 ) - V_22 ) ;
if ( V_4 -> V_22 < V_31 + V_22 ) {
goto V_14;
}
F_26 ( V_4 , V_22 ) ;
F_27 ( V_4 ) ;
return F_28 ( V_4 , V_41 , 0 , V_34 ) ;
V_14:
F_8 ( V_4 ) ;
return 0 ;
}
int F_29 ( struct V_3 * V_4 )
{
return F_30 ( V_4 , F_5 ( V_4 ) -> V_19 , 0 ) ;
}
