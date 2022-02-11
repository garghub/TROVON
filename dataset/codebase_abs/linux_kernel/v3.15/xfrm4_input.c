int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
return F_2 ( V_4 ) ;
}
static inline int F_3 ( struct V_3 * V_4 )
{
if ( F_4 ( V_4 ) == NULL ) {
const struct V_5 * V_6 = F_5 ( V_4 ) ;
if ( F_6 ( V_4 , V_6 -> V_7 , V_6 -> V_8 ,
V_6 -> V_9 , V_4 -> V_10 ) )
goto V_11;
}
return F_7 ( V_4 ) ;
V_11:
F_8 ( V_4 ) ;
return V_12 ;
}
int F_9 ( struct V_3 * V_4 , int V_13 )
{
struct V_5 * V_6 = F_5 ( V_4 ) ;
V_6 -> V_14 = F_10 ( V_4 ) -> V_14 ;
#ifndef F_11
if ( ! V_13 )
return - V_6 -> V_14 ;
#endif
F_12 ( V_4 , V_4 -> V_15 - F_13 ( V_4 ) ) ;
V_6 -> V_16 = F_14 ( V_4 -> V_17 ) ;
F_15 ( V_6 ) ;
F_16 ( V_18 , V_19 , V_4 , V_4 -> V_10 , NULL ,
F_3 ) ;
return 0 ;
}
int F_17 ( struct V_20 * V_21 , struct V_3 * V_4 )
{
struct V_22 * V_23 = F_18 ( V_21 ) ;
struct V_24 * V_25 ;
struct V_5 * V_6 ;
int V_26 , V_17 ;
T_1 * V_27 ;
T_2 * V_28 ;
T_3 V_29 = V_23 -> V_29 ;
if ( ! V_29 )
return 1 ;
V_17 = V_4 -> V_17 - sizeof( struct V_24 ) ;
if ( ! F_19 ( V_4 , sizeof( struct V_24 ) + F_20 ( V_17 , 8 ) ) )
return 1 ;
V_25 = F_21 ( V_4 ) ;
V_27 = ( T_1 * ) V_25 + sizeof( struct V_24 ) ;
V_28 = ( T_2 * ) V_27 ;
switch ( V_29 ) {
default:
case V_30 :
if ( V_17 == 1 && V_27 [ 0 ] == 0xff ) {
goto V_11;
} else if ( V_17 > sizeof( struct V_31 ) && V_28 [ 0 ] != 0 ) {
V_17 = sizeof( struct V_24 ) ;
} else
return 1 ;
break;
case V_32 :
if ( V_17 == 1 && V_27 [ 0 ] == 0xff ) {
goto V_11;
} else if ( V_17 > 2 * sizeof( V_33 ) + sizeof( struct V_31 ) &&
V_28 [ 0 ] == 0 && V_28 [ 1 ] == 0 ) {
V_17 = sizeof( struct V_24 ) + 2 * sizeof( V_33 ) ;
} else
return 1 ;
break;
}
if ( F_22 ( V_4 , V_34 ) )
goto V_11;
V_6 = F_5 ( V_4 ) ;
V_26 = V_6 -> V_35 << 2 ;
V_6 -> V_16 = F_14 ( F_23 ( V_6 -> V_16 ) - V_17 ) ;
if ( V_4 -> V_17 < V_26 + V_17 ) {
goto V_11;
}
F_24 ( V_4 , V_17 ) ;
F_25 ( V_4 ) ;
return F_26 ( V_4 , V_36 , 0 , V_29 ) ;
V_11:
F_8 ( V_4 ) ;
return 0 ;
}
int F_27 ( struct V_3 * V_4 )
{
return F_28 ( V_4 , F_5 ( V_4 ) -> V_14 , 0 ) ;
}
