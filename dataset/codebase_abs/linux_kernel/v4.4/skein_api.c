int F_1 ( struct V_1 * V_2 , enum V_3 V_4 )
{
F_2 ( V_2 && V_4 , V_5 ) ;
memset ( V_2 , 0 , sizeof( struct V_1 ) ) ;
V_2 -> V_3 = V_4 ;
return V_6 ;
}
int F_3 ( struct V_1 * V_2 , T_1 V_7 )
{
int V_8 = V_5 ;
T_1 V_9 = 0 ;
T_2 * V_10 = NULL ;
T_2 V_11 = V_12 ;
F_2 ( V_2 , V_5 ) ;
V_10 = V_2 -> V_13 . V_14 . V_10 ;
V_9 = V_2 -> V_3 / 8 ;
switch ( V_2 -> V_3 ) {
case V_15 :
V_8 = F_4 ( & V_2 -> V_13 . V_14 , V_7 ,
V_11 , NULL , 0 ) ;
break;
case V_16 :
V_8 = F_5 ( & V_2 -> V_13 . V_17 , V_7 ,
V_11 , NULL , 0 ) ;
break;
case V_18 :
V_8 = F_6 ( & V_2 -> V_13 . V_19 , V_7 ,
V_11 , NULL , 0 ) ;
break;
}
if ( V_8 == V_6 ) {
memcpy ( V_2 -> V_20 , V_10 , V_9 ) ;
}
return V_8 ;
}
int F_7 ( struct V_1 * V_2 , const T_3 * V_21 , T_1 V_22 ,
T_1 V_7 )
{
int V_8 = V_5 ;
T_2 * V_10 = NULL ;
T_1 V_9 = 0 ;
T_2 V_11 = V_12 ;
F_2 ( V_2 , V_5 ) ;
V_10 = V_2 -> V_13 . V_14 . V_10 ;
V_9 = V_2 -> V_3 / 8 ;
F_2 ( V_7 , V_23 ) ;
switch ( V_2 -> V_3 ) {
case V_15 :
V_8 = F_4 ( & V_2 -> V_13 . V_14 , V_7 ,
V_11 ,
( const T_3 * ) V_21 , V_22 ) ;
break;
case V_16 :
V_8 = F_5 ( & V_2 -> V_13 . V_17 , V_7 ,
V_11 ,
( const T_3 * ) V_21 , V_22 ) ;
break;
case V_18 :
V_8 = F_6 ( & V_2 -> V_13 . V_19 , V_7 ,
V_11 ,
( const T_3 * ) V_21 , V_22 ) ;
break;
}
if ( V_8 == V_6 ) {
memcpy ( V_2 -> V_20 , V_10 , V_9 ) ;
}
return V_8 ;
}
void F_8 ( struct V_1 * V_2 )
{
T_1 V_9 = 0 ;
T_2 * V_10 ;
V_10 = V_2 -> V_13 . V_14 . V_10 ;
V_9 = V_2 -> V_3 / 8 ;
memcpy ( V_10 , V_2 -> V_20 , V_9 ) ;
F_9 ( & V_2 -> V_13 , V_24 ) ;
}
int F_10 ( struct V_1 * V_2 , const T_3 * V_25 ,
T_1 V_26 )
{
int V_8 = V_5 ;
F_2 ( V_2 , V_5 ) ;
switch ( V_2 -> V_3 ) {
case V_15 :
V_8 = F_11 ( & V_2 -> V_13 . V_14 , ( const T_3 * ) V_25 ,
V_26 ) ;
break;
case V_16 :
V_8 = F_12 ( & V_2 -> V_13 . V_17 , ( const T_3 * ) V_25 ,
V_26 ) ;
break;
case V_18 :
V_8 = F_13 ( & V_2 -> V_13 . V_19 , ( const T_3 * ) V_25 ,
V_26 ) ;
break;
}
return V_8 ;
}
int F_14 ( struct V_1 * V_2 , const T_3 * V_25 ,
T_1 V_27 )
{
T_1 V_28 ;
T_3 V_29 ;
T_3 * V_30 ;
F_2 ( ( V_2 -> V_13 . V_31 . V_32 [ 1 ] & V_33 ) == 0 ||
V_27 == 0 , V_5 ) ;
if ( ( V_27 & 0x7 ) == 0 )
return F_10 ( V_2 , V_25 , V_27 >> 3 ) ;
F_10 ( V_2 , V_25 , ( V_27 >> 3 ) + 1 ) ;
V_30 = ( T_3 * ) V_2 -> V_13 . V_14 . V_10 + V_2 -> V_3 / 8 ;
F_15 ( V_2 -> V_13 . V_31 ) ;
V_28 = V_2 -> V_13 . V_31 . V_34 ;
F_16 ( V_28 != 0 ) ;
V_29 = ( T_3 ) ( 1u << ( 7 - ( V_27 & 7 ) ) ) ;
V_30 [ V_28 - 1 ] = ( T_3 ) ( ( V_30 [ V_28 - 1 ] & ( 0 - V_29 ) ) | V_29 ) ;
return V_6 ;
}
int F_17 ( struct V_1 * V_2 , T_3 * V_35 )
{
int V_8 = V_5 ;
F_2 ( V_2 , V_5 ) ;
switch ( V_2 -> V_3 ) {
case V_15 :
V_8 = F_18 ( & V_2 -> V_13 . V_14 , ( T_3 * ) V_35 ) ;
break;
case V_16 :
V_8 = F_19 ( & V_2 -> V_13 . V_17 , ( T_3 * ) V_35 ) ;
break;
case V_18 :
V_8 = F_20 ( & V_2 -> V_13 . V_19 , ( T_3 * ) V_35 ) ;
break;
}
return V_8 ;
}
