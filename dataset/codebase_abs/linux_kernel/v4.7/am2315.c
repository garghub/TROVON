static T_1 F_1 ( T_2 * V_1 , T_2 V_2 )
{
int V_3 ;
T_1 V_4 = 0xffff ;
while ( V_2 -- ) {
V_4 ^= * V_1 ++ ;
for ( V_3 = 0 ; V_3 < 8 ; V_3 ++ ) {
if ( V_4 & 0x01 ) {
V_4 >>= 1 ;
V_4 ^= 0xA001 ;
} else {
V_4 >>= 1 ;
}
}
}
return V_4 ;
}
static void F_2 ( struct V_5 * V_6 )
{
F_3 ( V_6 , V_7 ) ;
}
static int F_4 ( struct V_8 * V_1 ,
struct V_9 * V_10 )
{
int V_11 ;
T_2 V_12 [ 3 ] = { V_13 , V_7 , 4 } ;
T_2 V_14 [ 8 ] ;
T_1 V_4 ;
F_2 ( V_1 -> V_6 ) ;
F_5 ( & V_1 -> V_15 ) ;
V_11 = F_6 ( V_1 -> V_6 , V_12 , sizeof( V_12 ) ) ;
if ( V_11 < 0 ) {
F_7 ( & V_1 -> V_6 -> V_16 , L_1 ) ;
goto V_17;
}
F_8 ( 2000 , 3000 ) ;
V_11 = F_9 ( V_1 -> V_6 , V_14 , sizeof( V_14 ) ) ;
if ( V_11 < 0 ) {
F_7 ( & V_1 -> V_6 -> V_16 , L_2 ) ;
goto V_17;
}
F_10 ( & V_1 -> V_15 ) ;
V_4 = F_1 ( V_14 , sizeof( V_14 ) - 2 ) ;
if ( ( V_4 & 0xff ) != V_14 [ 6 ] || ( V_4 >> 8 ) != V_14 [ 7 ] ) {
F_7 ( & V_1 -> V_6 -> V_16 , L_3 ) ;
return - V_18 ;
}
V_10 -> V_19 = ( V_14 [ V_20 ] << 8 ) |
V_14 [ V_20 + 1 ] ;
V_10 -> V_21 = ( V_14 [ V_22 ] << 8 ) |
V_14 [ V_22 + 1 ] ;
return V_11 ;
V_17:
F_10 ( & V_1 -> V_15 ) ;
return V_11 ;
}
static T_3 F_11 ( int V_23 , void * V_24 )
{
int V_3 ;
int V_11 ;
int V_25 ;
struct V_26 * V_27 = V_24 ;
struct V_28 * V_29 = V_27 -> V_29 ;
struct V_8 * V_1 = F_12 ( V_29 ) ;
struct V_9 V_10 ;
V_11 = F_4 ( V_1 , & V_10 ) ;
if ( V_11 < 0 )
goto V_30;
F_5 ( & V_1 -> V_15 ) ;
if ( * ( V_29 -> V_31 ) == V_32 ) {
V_1 -> V_33 [ 0 ] = V_10 . V_19 ;
V_1 -> V_33 [ 1 ] = V_10 . V_21 ;
} else {
V_3 = 0 ;
F_13 (bit, indio_dev->active_scan_mask,
indio_dev->masklength) {
V_1 -> V_33 [ V_3 ] = ( V_25 ? V_10 . V_21 :
V_10 . V_19 ) ;
V_3 ++ ;
}
}
F_10 ( & V_1 -> V_15 ) ;
F_14 ( V_29 , V_1 -> V_33 ,
V_27 -> V_34 ) ;
V_30:
F_15 ( V_29 -> V_35 ) ;
return V_36 ;
}
static int F_16 ( struct V_28 * V_29 ,
struct V_37 const * V_38 ,
int * V_39 , int * V_40 , long V_41 )
{
int V_11 ;
struct V_9 V_10 ;
struct V_8 * V_1 = F_12 ( V_29 ) ;
switch ( V_41 ) {
case V_42 :
V_11 = F_4 ( V_1 , & V_10 ) ;
if ( V_11 < 0 )
return V_11 ;
* V_39 = ( V_38 -> type == V_43 ) ?
V_10 . V_19 : V_10 . V_21 ;
return V_44 ;
case V_45 :
* V_39 = 100 ;
return V_44 ;
}
return - V_46 ;
}
static int F_17 ( struct V_5 * V_6 ,
const struct V_47 * V_48 )
{
int V_11 ;
struct V_28 * V_29 ;
struct V_8 * V_1 ;
V_29 = F_18 ( & V_6 -> V_16 , sizeof( * V_1 ) ) ;
if ( ! V_29 ) {
F_7 ( & V_6 -> V_16 , L_4 ) ;
return - V_49 ;
}
V_1 = F_12 ( V_29 ) ;
V_1 -> V_6 = V_6 ;
F_19 ( V_6 , V_29 ) ;
F_20 ( & V_1 -> V_15 ) ;
V_29 -> V_16 . V_50 = & V_6 -> V_16 ;
V_29 -> V_51 = & V_52 ;
V_29 -> V_53 = V_54 ;
V_29 -> V_55 = V_56 ;
V_29 -> V_57 = V_58 ;
V_29 -> V_59 = F_21 ( V_58 ) ;
V_11 = F_22 ( V_29 , NULL ,
F_11 , NULL ) ;
if ( V_11 < 0 ) {
F_7 ( & V_6 -> V_16 , L_5 ) ;
return V_11 ;
}
V_11 = F_23 ( V_29 ) ;
if ( V_11 < 0 )
goto V_60;
return 0 ;
V_60:
F_24 ( V_29 ) ;
return V_11 ;
}
static int F_25 ( struct V_5 * V_6 )
{
struct V_28 * V_29 = F_26 ( V_6 ) ;
F_27 ( V_29 ) ;
F_24 ( V_29 ) ;
return 0 ;
}
