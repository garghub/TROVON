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
struct V_8 * V_9 = F_5 ( V_4 ) ;
V_9 -> V_17 = F_10 ( V_4 ) -> V_17 ;
#ifndef F_11
if ( ! V_16 )
return - V_9 -> V_17 ;
#endif
F_12 ( V_4 , V_4 -> V_18 - F_13 ( V_4 ) ) ;
V_9 -> V_19 = F_14 ( V_4 -> V_20 ) ;
F_15 ( V_9 ) ;
F_16 ( V_21 , V_22 ,
F_17 ( V_4 -> V_13 ) , NULL , V_4 , V_4 -> V_13 , NULL ,
F_3 ) ;
return 0 ;
}
int F_18 ( struct V_6 * V_7 , struct V_3 * V_4 )
{
struct V_23 * V_24 = F_19 ( V_7 ) ;
struct V_25 * V_26 ;
struct V_8 * V_9 ;
int V_27 , V_20 ;
T_1 * V_28 ;
T_2 * V_29 ;
T_3 V_30 = V_24 -> V_30 ;
if ( ! V_30 )
return 1 ;
V_20 = V_4 -> V_20 - sizeof( struct V_25 ) ;
if ( ! F_20 ( V_4 , sizeof( struct V_25 ) + F_21 ( V_20 , 8 ) ) )
return 1 ;
V_26 = F_22 ( V_4 ) ;
V_28 = ( T_1 * ) V_26 + sizeof( struct V_25 ) ;
V_29 = ( T_2 * ) V_28 ;
switch ( V_30 ) {
default:
case V_31 :
if ( V_20 == 1 && V_28 [ 0 ] == 0xff ) {
goto V_14;
} else if ( V_20 > sizeof( struct V_32 ) && V_29 [ 0 ] != 0 ) {
V_20 = sizeof( struct V_25 ) ;
} else
return 1 ;
break;
case V_33 :
if ( V_20 == 1 && V_28 [ 0 ] == 0xff ) {
goto V_14;
} else if ( V_20 > 2 * sizeof( V_34 ) + sizeof( struct V_32 ) &&
V_29 [ 0 ] == 0 && V_29 [ 1 ] == 0 ) {
V_20 = sizeof( struct V_25 ) + 2 * sizeof( V_34 ) ;
} else
return 1 ;
break;
}
if ( F_23 ( V_4 , V_35 ) )
goto V_14;
V_9 = F_5 ( V_4 ) ;
V_27 = V_9 -> V_36 << 2 ;
V_9 -> V_19 = F_14 ( F_24 ( V_9 -> V_19 ) - V_20 ) ;
if ( V_4 -> V_20 < V_27 + V_20 ) {
goto V_14;
}
F_25 ( V_4 , V_20 ) ;
F_26 ( V_4 ) ;
return F_27 ( V_4 , V_37 , 0 , V_30 ) ;
V_14:
F_8 ( V_4 ) ;
return 0 ;
}
int F_28 ( struct V_3 * V_4 )
{
return F_29 ( V_4 , F_5 ( V_4 ) -> V_17 , 0 ) ;
}
