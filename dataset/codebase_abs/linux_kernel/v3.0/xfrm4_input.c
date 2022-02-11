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
int F_9 ( struct V_3 * V_4 , int V_13 , T_1 V_14 ,
int V_15 )
{
F_10 ( V_4 ) -> V_16 = V_17 ;
F_10 ( V_4 ) -> V_18 = F_11 ( struct V_5 , V_7 ) ;
return F_12 ( V_4 , V_13 , V_14 , V_15 ) ;
}
int F_13 ( struct V_3 * V_4 , int V_19 )
{
struct V_5 * V_6 = F_5 ( V_4 ) ;
V_6 -> V_20 = F_14 ( V_4 ) -> V_20 ;
#ifndef F_15
if ( ! V_19 )
return - V_6 -> V_20 ;
#endif
F_16 ( V_4 , V_4 -> V_21 - F_17 ( V_4 ) ) ;
V_6 -> V_22 = F_18 ( V_4 -> V_23 ) ;
F_19 ( V_6 ) ;
F_20 ( V_24 , V_25 , V_4 , V_4 -> V_10 , NULL ,
F_3 ) ;
return 0 ;
}
int F_21 ( struct V_26 * V_27 , struct V_3 * V_4 )
{
struct V_28 * V_29 = F_22 ( V_27 ) ;
struct V_30 * V_31 ;
struct V_5 * V_6 ;
int V_32 , V_23 ;
T_2 * V_33 ;
T_1 * V_34 ;
T_3 V_15 = V_29 -> V_15 ;
if ( ! V_15 )
return 1 ;
V_23 = V_4 -> V_23 - sizeof( struct V_30 ) ;
if ( ! F_23 ( V_4 , sizeof( struct V_30 ) + F_24 ( V_23 , 8 ) ) )
return 1 ;
V_31 = F_25 ( V_4 ) ;
V_33 = ( T_2 * ) V_31 + sizeof( struct V_30 ) ;
V_34 = ( T_1 * ) V_33 ;
switch ( V_15 ) {
default:
case V_35 :
if ( V_23 == 1 && V_33 [ 0 ] == 0xff ) {
goto V_11;
} else if ( V_23 > sizeof( struct V_36 ) && V_34 [ 0 ] != 0 ) {
V_23 = sizeof( struct V_30 ) ;
} else
return 1 ;
break;
case V_37 :
if ( V_23 == 1 && V_33 [ 0 ] == 0xff ) {
goto V_11;
} else if ( V_23 > 2 * sizeof( V_38 ) + sizeof( struct V_36 ) &&
V_34 [ 0 ] == 0 && V_34 [ 1 ] == 0 ) {
V_23 = sizeof( struct V_30 ) + 2 * sizeof( V_38 ) ;
} else
return 1 ;
break;
}
if ( F_26 ( V_4 ) && F_27 ( V_4 , 0 , 0 , V_39 ) )
goto V_11;
V_6 = F_5 ( V_4 ) ;
V_32 = V_6 -> V_40 << 2 ;
V_6 -> V_22 = F_18 ( F_28 ( V_6 -> V_22 ) - V_23 ) ;
if ( V_4 -> V_23 < V_32 + V_23 ) {
goto V_11;
}
F_29 ( V_4 , V_23 ) ;
F_30 ( V_4 ) ;
return F_9 ( V_4 , V_41 , 0 , V_15 ) ;
V_11:
F_8 ( V_4 ) ;
return 0 ;
}
int F_31 ( struct V_3 * V_4 )
{
return F_32 ( V_4 , F_5 ( V_4 ) -> V_20 , 0 ) ;
}
