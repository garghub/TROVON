static int F_1 ( struct V_1 * V_2 , void * V_3 )
{
int V_4 = ( V_2 -> V_5 . V_6 >> 1 ) - 1 ;
int V_7 , V_8 = 0 ;
T_1 * V_9 = V_3 ;
V_7 = F_2 ( V_2 -> V_10 , & V_2 -> V_11 ) ;
if ( V_7 < 0 )
return V_7 ;
for (; V_8 < V_4 ; V_8 ++ )
* ( V_9 + V_8 ) = V_2 -> V_12 [ V_8 + 1 ] ;
return V_7 ;
}
static int F_3 ( struct V_13 * V_14 ,
struct V_15 const * V_16 , int * V_17 ,
int * V_18 , long V_19 )
{
struct V_1 * V_2 = F_4 ( V_14 ) ;
int V_7 ;
switch ( V_19 ) {
case V_20 :
V_7 = F_5 ( V_14 ) ;
if ( V_7 < 0 )
return V_7 ;
V_7 = F_6 ( V_2 -> V_21 ) ;
if ( V_7 ) {
F_7 ( V_14 ) ;
return V_7 ;
}
V_2 -> V_22 [ 0 ] = V_16 -> V_16 << 3 ;
V_7 = F_1 ( V_2 , V_17 ) ;
F_7 ( V_14 ) ;
F_8 ( V_2 -> V_21 ) ;
if ( V_7 < 0 )
return V_7 ;
* V_17 = F_9 ( * V_17 ) ;
* V_17 = ( * V_17 >> V_16 -> V_23 . V_24 ) & 0xff ;
return V_25 ;
case V_26 :
V_7 = F_6 ( V_2 -> V_21 ) ;
if ( V_7 )
return V_7 ;
V_7 = F_10 ( V_2 -> V_21 ) ;
F_8 ( V_2 -> V_21 ) ;
if ( V_7 < 0 )
return V_7 ;
* V_17 = V_7 / 1000 ;
return V_25 ;
default:
return - V_27 ;
}
}
static T_2 F_11 ( int V_28 , void * V_29 )
{
struct V_30 * V_31 = V_29 ;
struct V_13 * V_14 = V_31 -> V_14 ;
struct V_1 * V_2 = F_4 ( V_14 ) ;
T_3 V_3 [ 8 ] = { 0 } ;
F_12 ( & V_2 -> V_32 ) ;
if ( F_1 ( V_2 , & V_3 ) < 0 )
F_13 ( & V_2 -> V_10 -> V_33 , L_1 ) ;
F_14 ( V_14 , V_3 ,
F_15 ( V_14 ) ) ;
F_16 ( & V_2 -> V_32 ) ;
F_17 ( V_14 -> V_34 ) ;
return V_35 ;
}
static int F_18 ( struct V_13 * V_14 )
{
struct V_1 * V_2 = F_4 ( V_14 ) ;
int V_36 ;
int V_8 = 0 ;
F_19 (scan_index, indio_dev->active_scan_mask,
indio_dev->masklength) {
const struct V_15 * V_16 =
& V_14 -> V_37 [ V_36 ] ;
V_2 -> V_22 [ V_8 ++ ] = V_16 -> V_16 << 3 ;
}
V_2 -> V_5 . V_6 = 2 + ( V_8 * sizeof( T_3 ) ) ;
return F_6 ( V_2 -> V_21 ) ;
}
static int F_20 ( struct V_13 * V_14 )
{
struct V_1 * V_2 = F_4 ( V_14 ) ;
V_2 -> V_5 . V_6 = 4 ;
return F_8 ( V_2 -> V_21 ) ;
}
static int F_21 ( struct V_38 * V_10 )
{
struct V_13 * V_14 ;
struct V_1 * V_2 ;
int V_7 ;
V_14 = F_22 ( & V_10 -> V_33 , sizeof( * V_2 ) ) ;
if ( ! V_14 ) {
F_13 ( & V_10 -> V_33 , L_2 ) ;
return - V_39 ;
}
V_2 = F_4 ( V_14 ) ;
V_2 -> V_10 = V_10 ;
F_23 ( V_10 , V_14 ) ;
V_14 -> V_33 . V_40 = & V_10 -> V_33 ;
V_14 -> V_33 . V_41 = V_10 -> V_33 . V_41 ;
V_14 -> V_42 = F_24 ( V_10 ) -> V_42 ;
V_14 -> V_43 = V_44 ;
V_14 -> V_45 = & V_46 ;
V_14 -> V_37 = V_47 ;
V_14 -> V_48 = F_25 ( V_47 ) ;
V_2 -> V_5 . V_22 = V_2 -> V_22 ;
V_2 -> V_5 . V_12 = V_2 -> V_12 ;
V_2 -> V_5 . V_6 = 4 ;
F_26 ( & V_2 -> V_11 , & V_2 -> V_5 , 1 ) ;
V_2 -> V_21 = F_27 ( & V_10 -> V_33 , L_3 ) ;
if ( F_28 ( V_2 -> V_21 ) )
return F_29 ( V_2 -> V_21 ) ;
F_30 ( & V_2 -> V_32 ) ;
V_7 = F_31 ( & V_10 -> V_33 , V_14 , NULL ,
F_11 ,
& V_49 ) ;
if ( V_7 ) {
F_13 ( & V_10 -> V_33 , L_4 ) ;
return V_7 ;
}
return F_32 ( & V_10 -> V_33 , V_14 ) ;
}
