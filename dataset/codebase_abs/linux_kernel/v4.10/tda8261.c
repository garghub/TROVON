static int F_1 ( struct V_1 * V_2 , T_1 * V_3 )
{
const struct V_4 * V_5 = V_2 -> V_5 ;
int V_6 = 0 ;
struct V_7 V_8 = { . V_9 = V_5 -> V_9 , . V_10 = V_11 , . V_3 = V_3 , . V_12 = 1 } ;
if ( ( V_6 = F_2 ( V_2 -> V_13 , & V_8 , 1 ) ) != 1 )
F_3 ( L_1 , V_14 , V_6 ) ;
return V_6 ;
}
static int F_4 ( struct V_1 * V_2 , T_1 * V_3 )
{
const struct V_4 * V_5 = V_2 -> V_5 ;
int V_6 = 0 ;
struct V_7 V_8 = { . V_9 = V_5 -> V_9 , . V_10 = 0 , . V_3 = V_3 , . V_12 = 4 } ;
if ( ( V_6 = F_2 ( V_2 -> V_13 , & V_8 , 1 ) ) != 1 )
F_3 ( L_2 , V_14 , V_6 ) ;
return V_6 ;
}
static int F_5 ( struct V_15 * V_16 , T_2 * V_17 )
{
struct V_1 * V_2 = V_16 -> V_18 ;
T_1 V_19 = 0 ;
int V_6 = 0 ;
* V_17 = 0 ;
if ( ( V_6 = F_1 ( V_2 , & V_19 ) ) < 0 ) {
F_3 ( L_3 , V_14 ) ;
return V_6 ;
}
if ( ( V_19 >> 6 ) & 0x01 ) {
F_6 ( L_4 , V_14 ) ;
* V_17 = 1 ;
}
return V_6 ;
}
static int F_7 ( struct V_15 * V_16 , T_2 * V_20 )
{
struct V_1 * V_2 = V_16 -> V_18 ;
* V_20 = V_2 -> V_20 ;
return 0 ;
}
static int F_8 ( struct V_15 * V_16 )
{
struct V_21 * V_22 = & V_16 -> V_23 ;
struct V_1 * V_2 = V_16 -> V_18 ;
const struct V_4 * V_5 = V_2 -> V_5 ;
T_2 V_20 , V_24 , V_17 = 0 ;
T_1 V_3 [ 4 ] ;
int V_6 = 0 ;
V_20 = V_22 -> V_20 ;
if ( ( V_20 < 950000 ) || ( V_20 > 2150000 ) ) {
F_9 ( L_5 ,
V_14 , V_20 ) ;
return - V_25 ;
}
V_24 = ( V_20 + ( V_26 [ V_5 -> V_27 ] - 1 ) ) / V_26 [ V_5 -> V_27 ] ;
F_6 ( L_6 ,
V_14 , V_5 -> V_27 , V_26 [ V_5 -> V_27 ] , V_24 , V_24 ) ;
V_3 [ 0 ] = ( V_24 >> 8 ) & 0xff ;
V_3 [ 1 ] = V_24 & 0xff ;
V_3 [ 2 ] = ( 0x01 << 7 ) | ( ( V_28 [ V_5 -> V_27 ] & 0x07 ) << 1 ) ;
if ( V_20 < 1450000 )
V_3 [ 3 ] = 0x00 ;
else if ( V_20 < 2000000 )
V_3 [ 3 ] = 0x40 ;
else if ( V_20 < 2150000 )
V_3 [ 3 ] = 0x80 ;
V_6 = F_4 ( V_2 , V_3 ) ;
if ( V_6 < 0 ) {
F_3 ( L_3 , V_14 ) ;
return V_6 ;
}
F_6 ( L_7 , V_14 ) ;
F_10 ( 20 ) ;
if ( ( V_6 = F_5 ( V_16 , & V_17 ) ) < 0 ) {
F_3 ( L_3 , V_14 ) ;
return V_6 ;
}
if ( V_17 == 1 ) {
F_6 ( L_8 , V_14 ,
V_17 ) ;
V_2 -> V_20 = V_20 ;
} else {
F_6 ( L_9 , V_14 , V_17 ) ;
}
return 0 ;
}
static void F_11 ( struct V_15 * V_16 )
{
struct V_1 * V_2 = V_16 -> V_18 ;
V_16 -> V_18 = NULL ;
F_12 ( V_2 ) ;
}
struct V_15 * F_13 ( struct V_15 * V_16 ,
const struct V_4 * V_5 ,
struct V_29 * V_13 )
{
struct V_1 * V_2 = NULL ;
if ( ( V_2 = F_14 ( sizeof ( struct V_1 ) , V_30 ) ) == NULL )
goto exit;
V_2 -> V_5 = V_5 ;
V_2 -> V_13 = V_13 ;
V_2 -> V_16 = V_16 ;
V_16 -> V_18 = V_2 ;
V_16 -> V_31 . V_32 = V_33 ;
V_16 -> V_31 . V_32 . V_34 . V_35 = V_26 [ V_5 -> V_27 ] ;
F_15 ( L_10 , V_14 ) ;
return V_16 ;
exit:
F_12 ( V_2 ) ;
return NULL ;
}
