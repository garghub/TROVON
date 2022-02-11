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
F_7 ( V_16 , L_2 ,
V_1 -> V_15 [ 0 ] , V_1 -> V_15 [ 1 ] ) ;
return V_6 ;
}
static int F_8 ( struct V_1 * V_1 )
{
memset ( V_1 -> V_15 , 0 , 8 ) ;
V_1 -> V_15 [ 0 ] = 0x0f ;
if ( F_1 ( V_1 , 0 , 0x87 , 0 , 0x08 ) != 0x08 ) {
F_7 ( V_16 , L_3 ) ;
return F_6 ( V_1 , - V_17 ) ;
}
return V_1 -> V_15 [ 0 ] ;
}
static int F_9 ( struct V_1 * V_1 , T_1 V_18 )
{
struct V_19 * V_19 = (struct V_19 * ) V_1 ;
if ( V_19 -> V_20 == V_18 )
return 0 ;
memset ( V_1 -> V_15 , 0 , 8 ) ;
V_1 -> V_15 [ 0 ] = V_18 ;
if ( F_1 ( V_1 , 3 , 0x07 , 0x0100 , 0x08 ) != 0x08 ) {
F_7 ( V_16 , L_4 ) ;
return F_6 ( V_1 , - V_17 ) ;
}
if ( F_8 ( V_1 ) != V_18 ) {
F_7 ( V_16 , L_5 ) ;
return - V_17 ;
}
V_19 -> V_20 = V_18 ;
return 0 ;
}
static int F_10 ( struct V_1 * V_1 ,
const struct V_21 * V_22 )
{
int V_6 ;
struct V_19 * V_19 = (struct V_19 * ) V_1 ;
struct V_23 * V_23 = & V_1 -> V_23 ;
F_11 ( 1000 ) ;
if ( F_1 ( V_1 , 0 , 0x88 , 0x5678 , 0x02 ) != 0x02 ||
V_1 -> V_15 [ 0 ] != 0x56 || V_1 -> V_15 [ 1 ] != 0x78 ) {
F_7 ( V_16 , L_6 ) ;
return F_6 ( V_1 , - V_24 ) ;
}
if ( F_1 ( V_1 , 2 , 0x06 , 0x0200 , 0x09 ) != 0x09 )
return F_6 ( V_1 , - V_24 ) ;
if ( F_1 ( V_1 , 2 , 0x06 , 0x0200 , 0x22 ) != 0x22 ||
V_1 -> V_15 [ 7 ] != 0xa0 || V_1 -> V_15 [ 8 ] != 0x23 ) {
F_7 ( V_16 , L_7 ) ;
return F_6 ( V_1 , - V_24 ) ;
}
if ( F_1 ( V_1 , 0 , 0x8a , 0 , 0x02 ) != 0x02 )
return F_6 ( V_1 , - V_24 ) ;
if ( F_1 ( V_1 , 0 , 0x8b , 0 , 0x24 ) != 0x24 )
return F_6 ( V_1 , - V_24 ) ;
if ( F_1 ( V_1 , 0 , 0x85 , 0 , 0x10 ) != 0x10 )
return F_6 ( V_1 , - V_24 ) ;
if ( ! ( V_1 -> V_15 [ 7 ] & 0x09 ) ) {
F_7 ( V_16 , L_8 ) ;
return - V_24 ;
}
if ( V_1 -> V_15 [ 7 ] & 0x01 )
F_7 ( V_25 , L_9 ) ;
if ( V_1 -> V_15 [ 7 ] & 0x02 )
F_7 ( V_25 , L_10 ) ;
if ( V_1 -> V_15 [ 7 ] & 0x04 )
F_7 ( V_25 , L_11 ) ;
if ( V_1 -> V_15 [ 7 ] & 0x08 )
F_7 ( V_25 , L_12 ) ;
if ( V_1 -> V_15 [ 7 ] & 0x01 )
V_19 -> V_26 = 0x00 ;
else
V_19 -> V_26 = 0x03 ;
F_7 ( V_25 , L_13 ,
V_1 -> V_15 [ 0 ] , V_1 -> V_15 [ 1 ] ) ;
F_7 ( V_25 , L_14 ,
V_1 -> V_15 [ 2 ] , V_1 -> V_15 [ 3 ] ) ;
F_7 ( V_25 , L_15 ,
( V_1 -> V_15 [ 4 ] * 16 ) + ( V_1 -> V_15 [ 5 ] >> 4 ) ) ;
V_6 = F_8 ( V_1 ) ;
if ( V_6 < 0 )
return V_6 ;
V_19 -> V_20 = V_19 -> V_27 = V_6 ;
V_6 = F_9 ( V_1 , V_19 -> V_26 ) ;
if ( V_6 < 0 )
return V_6 ;
if ( F_1 ( V_1 , 0 , 0x8f , 0 , 0x10 ) != 0x10 )
return F_6 ( V_1 , - V_17 ) ;
V_23 -> V_28 = 1 ;
V_23 -> V_29 = 1 ;
V_23 -> V_30 = ( V_1 -> V_15 [ 0 ] << 24 ) |
( V_1 -> V_15 [ 1 ] << 16 ) |
( V_1 -> V_15 [ 2 ] << 8 ) |
( V_1 -> V_15 [ 3 ] ) ;
V_19 -> V_18 . V_31 = ( V_1 -> V_15 [ 4 ] << 8 ) |
( V_1 -> V_15 [ 5 ] ) ;
V_19 -> V_18 . V_32 = ( V_1 -> V_15 [ 6 ] << 8 ) |
( V_1 -> V_15 [ 7 ] ) ;
V_19 -> V_18 . V_33 = V_34 ;
V_19 -> V_18 . V_35 = V_36 ;
V_19 -> V_18 . V_37 = V_19 -> V_18 . V_31 ;
V_19 -> V_18 . V_38 = V_23 -> V_30 ;
V_19 -> V_18 . V_39 = V_40 ;
V_23 -> V_41 = & V_19 -> V_18 ;
V_23 -> V_42 = 1 ;
V_6 = F_9 ( V_1 , V_19 -> V_27 ) ;
if ( V_6 < 0 )
return V_6 ;
if ( F_1 ( V_1 , 2 , 0x06 , 0x0100 , 0x12 ) != 0x12 ||
V_1 -> V_15 [ 8 ] != 0x53 || V_1 -> V_15 [ 9 ] != 0x05 ) {
F_5 ( L_16 ) ;
return F_6 ( V_1 , - V_17 ) ;
}
return 0 ;
}
static int F_12 ( struct V_1 * V_1 )
{
return 0 ;
}
static int F_13 ( struct V_1 * V_1 )
{
int V_6 ;
struct V_19 * V_19 = (struct V_19 * ) V_1 ;
V_6 = F_9 ( V_1 , V_19 -> V_26 ) ;
if ( V_6 < 0 )
return V_6 ;
if ( F_1 ( V_1 , 0 , 0x85 , 0 , 0x10 ) != 0x10 )
return F_6 ( V_1 , - V_17 ) ;
if ( F_1 ( V_1 , 1 , 0x09 , V_19 -> V_26 << 8 , 0x0 ) != 0x0 )
return F_6 ( V_1 , - V_17 ) ;
return 0 ;
}
static void F_14 ( struct V_1 * V_1 )
{
if ( F_1 ( V_1 , 1 , 0x04 , 0x0000 , 0x0 ) != 0x0 )
F_6 ( V_1 , - V_17 ) ;
}
static void F_15 ( struct V_1 * V_1 )
{
struct V_19 * V_19 = (struct V_19 * ) V_1 ;
if ( ! V_19 -> V_1 . V_43 )
return;
F_9 ( V_1 , V_19 -> V_27 ) ;
}
static void F_16 ( struct V_1 * V_1 ,
T_1 * V_44 ,
int V_45 )
{
struct V_19 * V_19 = (struct V_19 * ) V_1 ;
if ( V_45 != V_19 -> V_18 . V_38 ) {
V_1 -> V_46 = V_47 ;
return;
}
F_17 ( V_1 , V_48 , NULL , 0 ) ;
F_17 ( V_1 , V_49 , V_44 , V_45 ) ;
}
static int F_18 ( struct V_50 * V_51 ,
const struct V_21 * V_22 )
{
return F_19 ( V_51 , V_22 , & V_52 , sizeof( struct V_19 ) ,
V_53 ) ;
}
