static int F_1 ( struct V_1 * V_1 , int V_2 , T_1 V_3 , T_2 V_4 ,
int V_5 )
{
int V_6 = - 1 ;
T_1 V_7 = 0 ;
unsigned int V_8 = 0 ;
switch ( V_2 ) {
case 0 :
V_7 = V_9 | V_10 | V_11 ;
V_8 = F_2 ( V_1 -> V_12 , 0 ) ;
break;
case 1 :
V_7 = V_13 | V_10 | V_11 ;
V_8 = F_3 ( V_1 -> V_12 , 0 ) ;
break;
case 2 :
V_7 = V_9 | V_14 ;
V_8 = F_2 ( V_1 -> V_12 , 0 ) ;
break;
case 3 :
V_7 = V_13 | V_10 | V_14 ;
V_8 = F_3 ( V_1 -> V_12 , 0 ) ;
break;
}
V_6 = F_4 ( V_1 -> V_12 , V_8 ,
V_3 , V_7 ,
V_4 , 0 , V_1 -> V_15 , V_5 , 500 ) ;
if ( ( V_6 < 0 ) && ( V_3 != 0x0a ) )
F_5 ( L_1 ,
V_2 , V_3 , V_6 ) ;
return V_6 ;
}
static int F_6 ( struct V_1 * V_1 , int V_6 )
{
F_1 ( V_1 , 0 , 0x80 , 0 , 0x02 ) ;
F_7 ( L_2 ,
V_1 -> V_15 [ 0 ] , V_1 -> V_15 [ 1 ] ) ;
return V_6 ;
}
static int F_8 ( struct V_1 * V_1 )
{
memset ( V_1 -> V_15 , 0 , 8 ) ;
V_1 -> V_15 [ 0 ] = 0x0f ;
if ( F_1 ( V_1 , 0 , 0x87 , 0 , 0x08 ) != 0x08 ) {
F_7 ( L_3 ) ;
return F_6 ( V_1 , - V_16 ) ;
}
return V_1 -> V_15 [ 0 ] ;
}
static int F_9 ( struct V_1 * V_1 , T_1 V_17 )
{
struct V_18 * V_18 = (struct V_18 * ) V_1 ;
if ( V_18 -> V_19 == V_17 )
return 0 ;
memset ( V_1 -> V_15 , 0 , 8 ) ;
V_1 -> V_15 [ 0 ] = V_17 ;
if ( F_1 ( V_1 , 3 , 0x07 , 0x0100 , 0x08 ) != 0x08 ) {
F_7 ( L_4 ) ;
return F_6 ( V_1 , - V_16 ) ;
}
if ( F_8 ( V_1 ) != V_17 ) {
F_7 ( L_5 ) ;
return - V_16 ;
}
V_18 -> V_19 = V_17 ;
return 0 ;
}
static int F_10 ( struct V_1 * V_1 ,
const struct V_20 * V_21 )
{
int V_6 ;
struct V_18 * V_18 = (struct V_18 * ) V_1 ;
struct V_22 * V_22 = & V_1 -> V_22 ;
F_11 ( 1000 ) ;
if ( F_1 ( V_1 , 0 , 0x88 , 0x5678 , 0x02 ) != 0x02 ||
V_1 -> V_15 [ 0 ] != 0x56 || V_1 -> V_15 [ 1 ] != 0x78 ) {
F_7 ( L_6 ) ;
return F_6 ( V_1 , - V_23 ) ;
}
if ( F_1 ( V_1 , 2 , 0x06 , 0x0200 , 0x09 ) != 0x09 )
return F_6 ( V_1 , - V_23 ) ;
if ( F_1 ( V_1 , 2 , 0x06 , 0x0200 , 0x22 ) != 0x22 ||
V_1 -> V_15 [ 7 ] != 0xa0 || V_1 -> V_15 [ 8 ] != 0x23 ) {
F_7 ( L_7 ) ;
return F_6 ( V_1 , - V_23 ) ;
}
if ( F_1 ( V_1 , 0 , 0x8a , 0 , 0x02 ) != 0x02 )
return F_6 ( V_1 , - V_23 ) ;
if ( F_1 ( V_1 , 0 , 0x8b , 0 , 0x24 ) != 0x24 )
return F_6 ( V_1 , - V_23 ) ;
if ( F_1 ( V_1 , 0 , 0x85 , 0 , 0x10 ) != 0x10 )
return F_6 ( V_1 , - V_23 ) ;
if ( ! ( V_1 -> V_15 [ 7 ] & 0x09 ) ) {
F_7 ( L_8 ) ;
return - V_23 ;
}
if ( V_1 -> V_15 [ 7 ] & 0x01 )
F_12 ( V_24 , L_9 ) ;
if ( V_1 -> V_15 [ 7 ] & 0x02 )
F_12 ( V_24 , L_10 ) ;
if ( V_1 -> V_15 [ 7 ] & 0x04 )
F_12 ( V_24 , L_11 ) ;
if ( V_1 -> V_15 [ 7 ] & 0x08 )
F_12 ( V_24 , L_12 ) ;
if ( V_1 -> V_15 [ 7 ] & 0x01 )
V_18 -> V_25 = 0x00 ;
else
V_18 -> V_25 = 0x03 ;
F_12 ( V_24 , L_13 ,
V_1 -> V_15 [ 0 ] , V_1 -> V_15 [ 1 ] ) ;
F_12 ( V_24 , L_14 ,
V_1 -> V_15 [ 2 ] , V_1 -> V_15 [ 3 ] ) ;
F_12 ( V_24 , L_15 ,
( V_1 -> V_15 [ 4 ] * 16 ) + ( V_1 -> V_15 [ 5 ] >> 4 ) ) ;
V_6 = F_8 ( V_1 ) ;
if ( V_6 < 0 )
return V_6 ;
V_18 -> V_19 = V_18 -> V_26 = V_6 ;
V_6 = F_9 ( V_1 , V_18 -> V_25 ) ;
if ( V_6 < 0 )
return V_6 ;
if ( F_1 ( V_1 , 0 , 0x8f , 0 , 0x10 ) != 0x10 )
return F_6 ( V_1 , - V_16 ) ;
V_22 -> V_27 = 1 ;
V_22 -> V_28 = 1 ;
V_22 -> V_29 = ( V_1 -> V_15 [ 0 ] << 24 ) |
( V_1 -> V_15 [ 1 ] << 16 ) |
( V_1 -> V_15 [ 2 ] << 8 ) |
( V_1 -> V_15 [ 3 ] ) ;
V_18 -> V_17 . V_30 = ( V_1 -> V_15 [ 4 ] << 8 ) |
( V_1 -> V_15 [ 5 ] ) ;
V_18 -> V_17 . V_31 = ( V_1 -> V_15 [ 6 ] << 8 ) |
( V_1 -> V_15 [ 7 ] ) ;
V_18 -> V_17 . V_32 = V_33 ;
V_18 -> V_17 . V_34 = V_35 ;
V_18 -> V_17 . V_36 = V_18 -> V_17 . V_30 ;
V_18 -> V_17 . V_37 = V_22 -> V_29 ;
V_18 -> V_17 . V_38 = V_39 ;
V_22 -> V_40 = & V_18 -> V_17 ;
V_22 -> V_41 = 1 ;
V_6 = F_9 ( V_1 , V_18 -> V_26 ) ;
if ( V_6 < 0 )
return V_6 ;
if ( F_1 ( V_1 , 2 , 0x06 , 0x0100 , 0x12 ) != 0x12 ||
V_1 -> V_15 [ 8 ] != 0x53 || V_1 -> V_15 [ 9 ] != 0x05 ) {
F_5 ( L_16 ) ;
return F_6 ( V_1 , - V_16 ) ;
}
return 0 ;
}
static int F_13 ( struct V_1 * V_1 )
{
return 0 ;
}
static int F_14 ( struct V_1 * V_1 )
{
int V_6 ;
struct V_18 * V_18 = (struct V_18 * ) V_1 ;
V_6 = F_9 ( V_1 , V_18 -> V_25 ) ;
if ( V_6 < 0 )
return V_6 ;
if ( F_1 ( V_1 , 0 , 0x85 , 0 , 0x10 ) != 0x10 )
return F_6 ( V_1 , - V_16 ) ;
if ( F_1 ( V_1 , 1 , 0x09 , V_18 -> V_25 << 8 , 0x0 ) != 0x0 )
return F_6 ( V_1 , - V_16 ) ;
return 0 ;
}
static void F_15 ( struct V_1 * V_1 )
{
if ( F_1 ( V_1 , 1 , 0x04 , 0x0000 , 0x0 ) != 0x0 )
F_6 ( V_1 , - V_16 ) ;
}
static void F_16 ( struct V_1 * V_1 )
{
struct V_18 * V_18 = (struct V_18 * ) V_1 ;
if ( ! V_18 -> V_1 . V_42 )
return;
F_9 ( V_1 , V_18 -> V_26 ) ;
}
static void F_17 ( struct V_1 * V_1 ,
T_1 * V_43 ,
int V_44 )
{
struct V_18 * V_18 = (struct V_18 * ) V_1 ;
if ( V_44 != V_18 -> V_17 . V_37 ) {
V_1 -> V_45 = V_46 ;
return;
}
F_18 ( V_1 , V_47 , NULL , 0 ) ;
F_18 ( V_1 , V_48 , V_43 , V_44 ) ;
}
static int F_19 ( struct V_49 * V_50 ,
const struct V_20 * V_21 )
{
return F_20 ( V_50 , V_21 , & V_51 , sizeof( struct V_18 ) ,
V_52 ) ;
}
