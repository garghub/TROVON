static int F_1 ( struct V_1 * V_2 , void * V_3 ,
struct V_4 * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_8 * V_9 = & V_7 -> V_10 [ V_11 ] . V_9 ;
struct V_12 * V_13 = F_3 ( V_9 -> V_14 , struct V_12 , V_15 ) ;
int V_16 ;
#define F_4 ( V_16 ) if (x < 0) x = 0; if (x > 0xff) x = 0xff
switch ( V_5 -> type ) {
case V_17 :
V_16 = V_5 -> V_18 . V_19 . V_20 + 0x80 ;
F_4 ( V_16 ) ;
V_13 -> V_21 [ 0 ] -> V_22 [ 0 ] = 0x11 ;
V_13 -> V_21 [ 0 ] -> V_22 [ 1 ] = 0x10 ;
V_13 -> V_21 [ 0 ] -> V_22 [ 2 ] = V_16 ;
V_13 -> V_21 [ 0 ] -> V_22 [ 3 ] = 0x00 ;
V_13 -> V_21 [ 0 ] -> V_22 [ 4 ] = 0x00 ;
V_13 -> V_21 [ 0 ] -> V_22 [ 5 ] = 0x08 ;
V_13 -> V_21 [ 0 ] -> V_22 [ 6 ] = 0x00 ;
F_5 ( L_1 , V_16 ) ;
F_6 ( V_7 , V_13 , V_23 ) ;
break;
}
return 0 ;
}
static void F_7 ( struct V_1 * V_2 , T_1 V_24 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_8 * V_9 = & V_7 -> V_10 [ V_11 ] . V_9 ;
struct V_12 * V_13 = F_3 ( V_9 -> V_14 , struct V_12 , V_15 ) ;
T_2 * V_22 = V_13 -> V_21 [ 0 ] -> V_22 ;
* V_22 ++ = 0xfe ;
* V_22 ++ = 0x0d ;
* V_22 ++ = 0x07 ;
* V_22 ++ = 0x07 ;
* V_22 ++ = ( V_24 >> 8 ) & 0xff ;
* V_22 ++ = 0x00 ;
* V_22 = 0x00 ;
F_6 ( V_7 , V_13 , V_23 ) ;
}
int F_8 ( struct V_6 * V_7 )
{
struct V_25 * V_26 = F_3 ( V_7 -> V_27 . V_14 , struct V_25 , V_15 ) ;
struct V_8 * V_9 = & V_7 -> V_10 [ V_11 ] . V_9 ;
struct V_1 * V_2 = V_26 -> V_28 ;
struct V_12 * V_13 ;
struct V_29 * V_21 ;
const signed short * V_30 = V_31 ;
int error ;
int V_32 ;
if ( F_9 ( V_9 ) ) {
F_10 ( V_7 , L_2 ) ;
return - 1 ;
}
V_13 = F_3 ( V_9 -> V_14 , struct V_12 , V_15 ) ;
if ( ! V_13 ) {
F_10 ( V_7 , L_3 ) ;
return - 1 ;
}
V_21 = V_13 -> V_21 [ 0 ] ;
if ( ! V_21 ) {
F_10 ( V_7 , L_4 ) ;
return - 1 ;
}
for ( V_32 = 0 ; V_30 [ V_32 ] >= 0 ; V_32 ++ )
F_11 ( V_30 [ V_32 ] , V_2 -> V_33 ) ;
error = F_12 ( V_2 , NULL , F_1 ) ;
if ( error )
return error ;
if ( F_13 ( V_34 , V_2 -> V_33 ) )
V_2 -> V_35 -> V_36 = F_7 ;
F_14 ( V_7 , L_5 ) ;
return 0 ;
}
