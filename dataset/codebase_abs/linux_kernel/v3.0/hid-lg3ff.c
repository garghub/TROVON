static int F_1 ( struct V_1 * V_2 , void * V_3 ,
struct V_4 * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_8 * V_9 = & V_7 -> V_10 [ V_11 ] . V_9 ;
struct V_12 * V_13 = F_3 ( V_9 -> V_14 , struct V_12 , V_15 ) ;
int V_16 , V_17 ;
memset ( V_13 -> V_18 [ 0 ] -> V_19 , 0 , sizeof( V_20 ) * V_13 -> V_18 [ 0 ] -> V_21 ) ;
switch ( V_5 -> type ) {
case V_22 :
V_16 = V_5 -> V_23 . V_24 . V_25 ;
V_17 = V_5 -> V_23 . V_24 . V_26 ;
V_13 -> V_18 [ 0 ] -> V_19 [ 0 ] = 0x51 ;
V_13 -> V_18 [ 0 ] -> V_19 [ 1 ] = ( unsigned char ) ( - V_16 ) ;
V_13 -> V_18 [ 0 ] -> V_19 [ 31 ] = ( unsigned char ) ( - V_17 ) ;
F_4 ( V_7 , V_13 , V_27 ) ;
break;
}
return 0 ;
}
static void F_5 ( struct V_1 * V_2 , T_1 V_28 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_8 * V_9 = & V_7 -> V_10 [ V_11 ] . V_9 ;
struct V_12 * V_13 = F_3 ( V_9 -> V_14 , struct V_12 , V_15 ) ;
V_13 -> V_18 [ 0 ] -> V_19 [ 0 ] = 0x51 ;
V_13 -> V_18 [ 0 ] -> V_19 [ 1 ] = 0x00 ;
V_13 -> V_18 [ 0 ] -> V_19 [ 2 ] = 0x00 ;
V_13 -> V_18 [ 0 ] -> V_19 [ 3 ] = 0x7F ;
V_13 -> V_18 [ 0 ] -> V_19 [ 4 ] = 0x7F ;
V_13 -> V_18 [ 0 ] -> V_19 [ 31 ] = 0x00 ;
V_13 -> V_18 [ 0 ] -> V_19 [ 32 ] = 0x00 ;
V_13 -> V_18 [ 0 ] -> V_19 [ 33 ] = 0x7F ;
V_13 -> V_18 [ 0 ] -> V_19 [ 34 ] = 0x7F ;
F_4 ( V_7 , V_13 , V_27 ) ;
}
int F_6 ( struct V_6 * V_7 )
{
struct V_29 * V_30 = F_3 ( V_7 -> V_31 . V_14 , struct V_29 , V_15 ) ;
struct V_8 * V_9 = & V_7 -> V_10 [ V_11 ] . V_9 ;
struct V_1 * V_2 = V_30 -> V_32 ;
struct V_12 * V_13 ;
struct V_33 * V_18 ;
const signed short * V_34 = V_35 ;
int error ;
int V_36 ;
if ( F_7 ( V_9 ) ) {
F_8 ( V_7 , L_1 ) ;
return - 1 ;
}
V_13 = F_3 ( V_9 -> V_14 , struct V_12 , V_15 ) ;
if ( ! V_13 ) {
F_8 ( V_7 , L_2 ) ;
return - 1 ;
}
V_18 = V_13 -> V_18 [ 0 ] ;
if ( ! V_18 ) {
F_8 ( V_7 , L_3 ) ;
return - 1 ;
}
for ( V_36 = 0 ; V_34 [ V_36 ] >= 0 ; V_36 ++ )
F_9 ( V_34 [ V_36 ] , V_2 -> V_37 ) ;
error = F_10 ( V_2 , NULL , F_1 ) ;
if ( error )
return error ;
if ( F_11 ( V_38 , V_2 -> V_37 ) )
V_2 -> V_39 -> V_40 = F_5 ;
F_12 ( V_7 , L_4 ) ;
return 0 ;
}
