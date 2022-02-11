void F_1 ( struct V_1 * V_2 , void * V_3 , int V_4 )
{
T_1 V_5 ;
struct V_6 * V_7 = (struct V_6 * ) V_3 ;
if ( V_4 == 0 )
return;
V_5 = F_2 ( V_3 ) ;
if ( V_5 == 0 )
return;
if ( V_5 > V_4 )
V_5 = V_4 ;
switch ( V_7 -> type ) {
case V_8 :
F_3 ( V_2 , V_3 , V_5 ) ;
break;
case V_9 :
F_4 ( V_2 , V_3 , V_5 ) ;
break;
case V_10 :
F_5 ( V_2 , V_3 , V_5 ) ;
break;
default:
F_6 ( V_2 -> V_11 , L_1 ) ;
}
}
int F_7 ( struct V_1 * V_2 )
{
struct V_12 * V_12 ;
struct V_6 * V_7 ;
T_2 * V_13 ;
T_2 * V_14 ;
int V_15 = 0 ;
V_12 = F_8 ( V_2 , V_16 ) ;
if ( V_12 == NULL )
return - V_17 ;
V_7 = (struct V_6 * ) V_12 -> V_18 ;
V_7 -> type = V_19 ;
V_7 -> V_20 = 4 ;
V_7 -> V_21 = 16 ;
V_7 -> V_22 = 0 ;
V_7 -> V_23 = 0 ;
V_13 = V_12 -> V_18 + sizeof( struct V_6 ) ;
V_13 [ 0 ] = 0x4 ;
V_13 [ 1 ] = 0x3 ;
V_13 [ 2 ] = 0x5 ;
V_13 [ 3 ] = 0xa ;
V_14 = V_13 + V_7 -> V_20 ;
V_14 [ 0 ] = 0 ;
strcat ( V_14 , V_24 ) ;
V_14 [ 10 ] = 0 ;
V_14 [ 15 ] = 0 ;
F_9 ( V_2 , V_12 ) ;
F_10 ( V_12 , V_25 ) ;
if ( V_12 -> V_22 != V_26 )
V_15 = - V_27 ;
F_11 ( V_12 ) ;
return V_15 ;
}
int F_12 ( struct V_1 * V_2 , int V_28 )
{
struct V_12 * V_29 ;
struct V_30 * V_31 ;
int V_15 = 0 ;
V_29 = F_8 ( V_2 , sizeof( struct V_30 ) ) ;
if ( V_29 == NULL )
return - V_17 ;
V_31 = (struct V_30 * ) V_29 -> V_18 ;
V_31 -> V_7 . type = V_19 ;
V_31 -> V_7 . V_20 = 3 ;
V_31 -> V_7 . V_21 = 1 ;
V_31 -> V_7 . V_22 = 0 ;
V_31 -> V_12 [ 0 ] = 4 ;
V_31 -> V_12 [ 1 ] = 3 ;
V_31 -> V_12 [ 2 ] = 6 ;
V_31 -> V_32 = V_28 ;
F_9 ( V_2 , V_29 ) ;
F_10 ( V_29 , V_25 ) ;
if ( V_29 -> V_22 != V_26 )
V_15 = - V_27 ;
F_11 ( V_29 ) ;
return V_15 ;
}
