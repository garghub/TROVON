int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
return F_2 ( V_4 ) ;
}
static inline int F_3 ( struct V_5 * V_6 , struct V_3 * V_4 )
{
if ( ! F_4 ( V_4 ) ) {
const struct V_7 * V_8 = F_5 ( V_4 ) ;
if ( F_6 ( V_4 , V_8 -> V_9 , V_8 -> V_10 ,
V_8 -> V_11 , V_4 -> V_12 ) )
goto V_13;
}
return F_7 ( V_4 ) ;
V_13:
F_8 ( V_4 ) ;
return V_14 ;
}
int F_9 ( struct V_3 * V_4 , int V_15 )
{
struct V_7 * V_8 = F_5 ( V_4 ) ;
V_8 -> V_16 = F_10 ( V_4 ) -> V_16 ;
#ifndef F_11
if ( ! V_15 )
return - V_8 -> V_16 ;
#endif
F_12 ( V_4 , V_4 -> V_17 - F_13 ( V_4 ) ) ;
V_8 -> V_18 = F_14 ( V_4 -> V_19 ) ;
F_15 ( V_8 ) ;
F_16 ( V_20 , V_21 , NULL , V_4 ,
V_4 -> V_12 , NULL ,
F_3 ) ;
return 0 ;
}
int F_17 ( struct V_5 * V_6 , struct V_3 * V_4 )
{
struct V_22 * V_23 = F_18 ( V_6 ) ;
struct V_24 * V_25 ;
struct V_7 * V_8 ;
int V_26 , V_19 ;
T_1 * V_27 ;
T_2 * V_28 ;
T_3 V_29 = V_23 -> V_29 ;
if ( ! V_29 )
return 1 ;
V_19 = V_4 -> V_19 - sizeof( struct V_24 ) ;
if ( ! F_19 ( V_4 , sizeof( struct V_24 ) + F_20 ( V_19 , 8 ) ) )
return 1 ;
V_25 = F_21 ( V_4 ) ;
V_27 = ( T_1 * ) V_25 + sizeof( struct V_24 ) ;
V_28 = ( T_2 * ) V_27 ;
switch ( V_29 ) {
default:
case V_30 :
if ( V_19 == 1 && V_27 [ 0 ] == 0xff ) {
goto V_13;
} else if ( V_19 > sizeof( struct V_31 ) && V_28 [ 0 ] != 0 ) {
V_19 = sizeof( struct V_24 ) ;
} else
return 1 ;
break;
case V_32 :
if ( V_19 == 1 && V_27 [ 0 ] == 0xff ) {
goto V_13;
} else if ( V_19 > 2 * sizeof( V_33 ) + sizeof( struct V_31 ) &&
V_28 [ 0 ] == 0 && V_28 [ 1 ] == 0 ) {
V_19 = sizeof( struct V_24 ) + 2 * sizeof( V_33 ) ;
} else
return 1 ;
break;
}
if ( F_22 ( V_4 , V_34 ) )
goto V_13;
V_8 = F_5 ( V_4 ) ;
V_26 = V_8 -> V_35 << 2 ;
V_8 -> V_18 = F_14 ( F_23 ( V_8 -> V_18 ) - V_19 ) ;
if ( V_4 -> V_19 < V_26 + V_19 ) {
goto V_13;
}
F_24 ( V_4 , V_19 ) ;
F_25 ( V_4 ) ;
return F_26 ( V_4 , V_36 , 0 , V_29 ) ;
V_13:
F_8 ( V_4 ) ;
return 0 ;
}
int F_27 ( struct V_3 * V_4 )
{
return F_28 ( V_4 , F_5 ( V_4 ) -> V_16 , 0 ) ;
}
