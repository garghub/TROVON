static int F_1 ( struct V_1 * V_2 , void * V_3 , struct V_4 * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_8 * V_9 = & V_7 -> V_10 [ V_11 ] . V_9 ;
struct V_12 * V_13 = F_3 ( V_9 -> V_14 , struct V_12 , V_15 ) ;
int V_16 , V_17 ;
unsigned int V_18 , V_19 ;
#define F_4 ( V_16 ) if (x < 0) x = 0; if (x > 0xff) x = 0xff
switch ( V_5 -> type ) {
case V_20 :
V_16 = V_5 -> V_21 . V_22 . V_23 + 0x7f ;
V_17 = V_5 -> V_21 . V_22 . V_24 + 0x7f ;
F_4 ( V_16 ) ;
F_4 ( V_17 ) ;
V_13 -> V_25 [ 0 ] -> V_26 [ 0 ] = 0x51 ;
V_13 -> V_25 [ 0 ] -> V_26 [ 1 ] = 0x08 ;
V_13 -> V_25 [ 0 ] -> V_26 [ 2 ] = V_16 ;
V_13 -> V_25 [ 0 ] -> V_26 [ 3 ] = V_17 ;
F_5 ( L_1 , V_16 , V_17 ) ;
F_6 ( V_7 , V_13 , V_27 ) ;
break;
case V_28 :
V_19 = V_5 -> V_21 . V_29 . V_30 ;
V_18 = V_5 -> V_21 . V_29 . V_31 ;
V_19 = V_19 * 0xff / 0xffff ;
V_18 = V_18 * 0xff / 0xffff ;
F_4 ( V_18 ) ;
F_4 ( V_19 ) ;
V_13 -> V_25 [ 0 ] -> V_26 [ 0 ] = 0x42 ;
V_13 -> V_25 [ 0 ] -> V_26 [ 1 ] = 0x00 ;
V_13 -> V_25 [ 0 ] -> V_26 [ 2 ] = V_18 ;
V_13 -> V_25 [ 0 ] -> V_26 [ 3 ] = V_19 ;
F_5 ( L_2 , V_18 , V_19 ) ;
F_6 ( V_7 , V_13 , V_27 ) ;
break;
}
return 0 ;
}
static void F_7 ( struct V_1 * V_2 , T_1 V_32 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_8 * V_9 = & V_7 -> V_10 [ V_11 ] . V_9 ;
struct V_12 * V_13 = F_3 ( V_9 -> V_14 , struct V_12 , V_15 ) ;
T_2 * V_26 = V_13 -> V_25 [ 0 ] -> V_26 ;
V_32 = ( V_32 >> 12 ) & 0xf ;
* V_26 ++ = 0xfe ;
* V_26 ++ = 0x0d ;
* V_26 ++ = V_32 ;
* V_26 ++ = V_32 ;
* V_26 ++ = 0x80 ;
* V_26 ++ = 0x00 ;
* V_26 = 0x00 ;
F_6 ( V_7 , V_13 , V_27 ) ;
}
int F_8 ( struct V_6 * V_7 )
{
struct V_33 * V_34 = F_3 ( V_7 -> V_35 . V_14 , struct V_33 , V_15 ) ;
struct V_8 * V_9 = & V_7 -> V_10 [ V_11 ] . V_9 ;
struct V_1 * V_2 = V_34 -> V_36 ;
struct V_12 * V_13 ;
struct V_37 * V_25 ;
const signed short * V_38 = V_39 ;
int error ;
int V_40 ;
if ( F_9 ( V_9 ) ) {
F_10 ( V_7 , L_3 ) ;
return - 1 ;
}
V_13 = F_3 ( V_9 -> V_14 , struct V_12 , V_15 ) ;
V_25 = V_13 -> V_25 [ 0 ] ;
if ( ! V_25 ) {
F_10 ( V_7 , L_4 ) ;
return - 1 ;
}
for ( V_40 = 0 ; V_40 < F_11 ( V_41 ) ; V_40 ++ ) {
if ( V_2 -> V_42 . V_43 == V_41 [ V_40 ] . V_44 &&
V_2 -> V_42 . V_45 == V_41 [ V_40 ] . V_46 ) {
V_38 = V_41 [ V_40 ] . V_47 ;
break;
}
}
for ( V_40 = 0 ; V_38 [ V_40 ] >= 0 ; V_40 ++ )
F_12 ( V_38 [ V_40 ] , V_2 -> V_48 ) ;
error = F_13 ( V_2 , NULL , F_1 ) ;
if ( error )
return error ;
if ( F_14 ( V_49 , V_2 -> V_48 ) )
V_2 -> V_47 -> V_50 = F_7 ;
F_15 ( L_5 ) ;
return 0 ;
}
