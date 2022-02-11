static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
int V_5 ;
T_1 V_6 , V_7 , V_8 , V_9 , V_10 , V_11 ;
T_1 * V_12 ;
T_2 V_13 , V_14 ;
V_6 = ( V_4 -> V_4 [ 0 ] >> 3 ) & 0x03 ;
V_7 = ( V_4 -> V_4 [ 0 ] >> 2 ) & 0x01 ;
V_8 = ( V_4 -> V_4 [ 0 ] >> 1 ) & 0x01 ;
V_9 = V_4 -> V_4 [ 0 ] & 0x01 ;
V_10 = V_4 -> V_4 [ 1 ] ;
V_13 = ( ( T_2 ) ( V_4 -> V_4 [ 2 ] ) << 24 ) | ( ( T_2 ) ( V_4 -> V_4 [ 3 ] ) << 16 ) |
( ( T_2 ) ( V_4 -> V_4 [ 4 ] ) << 8 ) | V_4 -> V_4 [ 5 ] ;
V_14 =
( ( T_2 ) ( V_4 -> V_4 [ 6 ] ) << 16 ) | ( ( T_2 ) ( V_4 -> V_4 [ 7 ] ) << 8 ) |
V_4 -> V_4 [ 8 ] ;
V_11 = V_4 -> V_4 [ 9 ] ;
if ( V_6 ) {
if ( ! V_4 -> V_12 || ( V_4 -> V_15 < V_14 ) )
F_2 ( V_2 , V_16 ) ;
}
switch ( V_6 ) {
case 0 :
V_5 = F_3 ( V_2 , V_2 -> V_17 [ V_18 ] ,
V_10 , V_8 , V_9 ,
V_11 , V_13 ) ;
if ( V_5 != V_19 )
F_2 ( V_2 , V_16 ) ;
break;
case 1 :
V_12 = F_4 ( V_4 -> V_15 , V_20 ) ;
if ( ! V_12 )
F_2 ( V_2 , V_21 ) ;
V_5 = F_5 ( V_2 , V_2 -> V_17 [ V_18 ] ,
V_10 , V_7 , V_8 , V_9 ,
V_11 , V_13 , V_14 , V_12 ,
V_4 -> V_15 , 0 ) ;
if ( V_5 != V_19 ) {
F_6 ( V_12 ) ;
F_2 ( V_2 , V_16 ) ;
}
V_5 =
F_7 ( ( void * ) V_4 -> V_12 , ( void * ) V_12 , V_4 -> V_15 ) ;
if ( V_5 ) {
F_6 ( V_12 ) ;
F_2 ( V_2 , V_21 ) ;
}
F_6 ( V_12 ) ;
break;
case 2 :
V_12 = F_8 ( V_4 -> V_15 , V_20 ) ;
if ( ! V_12 )
F_2 ( V_2 , V_21 ) ;
V_5 =
F_9 ( ( void * ) V_12 , ( void * ) V_4 -> V_12 ,
V_4 -> V_15 ) ;
if ( V_5 ) {
F_6 ( V_12 ) ;
F_2 ( V_2 , V_21 ) ;
}
V_5 =
F_10 ( V_2 , V_2 -> V_17 [ V_18 ] ,
V_10 , V_7 , V_8 , V_9 ,
V_11 , V_13 , V_14 , V_12 ,
V_4 -> V_15 , 0 ) ;
if ( V_5 != V_19 ) {
F_6 ( V_12 ) ;
F_2 ( V_2 , V_16 ) ;
}
F_6 ( V_12 ) ;
break;
default:
F_2 ( V_2 , V_16 ) ;
}
return V_22 ;
}
static int F_11 ( struct V_1 * V_2 , struct V_23 * V_24 )
{
struct V_25 * V_26 = & ( V_2 -> V_26 ) ;
int V_27 = 0 , V_5 ;
if ( V_26 -> V_28 ) {
V_26 -> V_28 = 0 ;
F_2 ( V_2 , V_16 ) ;
}
if ( V_26 -> V_29 == V_30 )
F_2 ( V_2 , V_16 ) ;
else if ( V_26 -> V_29 == V_31 )
V_27 = ( V_24 -> V_32 < 17 ) ? V_24 -> V_32 : 17 ;
else
V_27 = ( V_24 -> V_32 < 6 ) ? V_24 -> V_32 : 6 ;
V_5 = F_7 ( ( void * ) V_24 -> V_24 , ( void * ) V_26 -> V_24 , V_27 ) ;
if ( V_5 )
F_2 ( V_2 , V_21 ) ;
F_12 ( L_1 , V_27 ) ;
F_12 ( L_2 ,
V_26 -> V_24 [ 0 ] , V_26 -> V_24 [ 1 ] , V_26 -> V_24 [ 2 ] ,
V_26 -> V_24 [ 3 ] ) ;
return V_22 ;
}
int F_13 ( struct V_33 * V_33 , struct V_34 * V_35 )
{
struct V_1 * V_2 ;
struct V_36 * V_37 ;
int V_38 ;
int V_5 = 0 ;
V_38 = F_14 ( V_33 ) ;
V_37 = F_15 ( & V_39 , V_38 ) ;
if ( ! V_37 ) {
F_12 ( L_3 ,
V_40 , V_38 ) ;
V_5 = - V_41 ;
goto exit;
}
V_2 = (struct V_1 * ) F_16 ( V_37 ) ;
if ( ! V_2 ) {
F_12 ( L_4 ) ;
V_5 = - V_41 ;
goto exit;
}
F_17 ( F_18 ( V_2 ) ) ;
F_19 ( & ( V_2 -> V_42 -> V_43 ) ) ;
V_35 -> V_44 = V_2 ;
F_20 ( & V_2 -> V_42 -> V_43 ) ;
exit:
return V_5 ;
}
int F_21 ( struct V_33 * V_33 , struct V_34 * V_35 )
{
struct V_1 * V_2 ;
V_2 = (struct V_1 * ) V_35 -> V_44 ;
if ( V_2 == NULL )
return - V_41 ;
F_22 ( F_18 ( V_2 ) ) ;
return 0 ;
}
T_3 F_23 ( struct V_34 * V_35 , char T_4 * V_12 , T_5 V_27 ,
T_6 * V_45 )
{
return 0 ;
}
T_3 F_24 ( struct V_34 * V_35 , const char T_4 * V_12 , T_5 V_27 ,
T_6 * V_45 )
{
return 0 ;
}
long F_25 ( struct V_34 * V_35 , unsigned int V_46 , unsigned long V_13 )
{
struct V_1 * V_2 ;
struct V_3 V_4 ;
struct V_23 V_24 ;
int V_5 = 0 ;
V_2 = (struct V_1 * ) V_35 -> V_44 ;
if ( V_2 == NULL )
return - V_41 ;
F_19 ( & ( V_2 -> V_42 -> V_43 ) ) ;
switch ( V_46 ) {
case V_47 :
V_5 =
F_9 ( ( void * ) & V_4 , ( void * ) V_13 ,
sizeof( struct V_3 ) ) ;
if ( V_5 ) {
V_5 = - V_48 ;
F_26 ( V_2 , exit ) ;
}
V_5 = F_1 ( V_2 , & V_4 ) ;
if ( V_5 != V_22 ) {
V_5 = - V_49 ;
F_26 ( V_2 , exit ) ;
}
break;
case V_50 :
V_5 =
F_9 ( ( void * ) & V_24 , ( void * ) V_13 ,
sizeof( struct V_23 ) ) ;
if ( V_5 ) {
V_5 = - V_48 ;
F_26 ( V_2 , exit ) ;
}
V_5 = F_11 ( V_2 , & V_24 ) ;
if ( V_5 != V_22 ) {
V_5 = - V_49 ;
F_26 ( V_2 , exit ) ;
}
break;
default:
break;
}
exit:
F_20 ( & V_2 -> V_42 -> V_43 ) ;
return V_5 ;
}
