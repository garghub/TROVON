static struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_4 ) ;
}
static int F_3 ( struct V_1 * V_5 , T_1 V_6 , T_1 V_7 )
{
T_1 V_8 [ 2 ] = { V_6 , V_7 } ;
int V_9 ;
V_9 = F_4 ( V_5 -> V_10 , V_8 , sizeof( V_8 ) ) ;
if ( V_9 >= 0 && V_9 < sizeof( V_8 ) )
V_9 = - V_11 ;
return ( V_9 == sizeof( V_8 ) ) ? 0 : V_9 ;
}
static int F_5 ( struct V_1 * V_5 , T_1 V_6 , T_1 * V_7 )
{
struct V_12 V_13 [ 2 ] = {
{
. V_14 = V_5 -> V_10 -> V_14 ,
. V_15 = 0 ,
. V_16 = & V_6 ,
. V_17 = 1 ,
} ,
{
. V_14 = V_5 -> V_10 -> V_14 ,
. V_15 = V_18 ,
. V_16 = V_7 ,
. V_17 = 1 ,
} ,
} ;
int V_9 ;
V_9 = F_6 ( V_5 -> V_10 -> V_19 , V_13 , F_7 ( V_13 ) ) ;
if ( V_9 >= 0 && V_9 < F_7 ( V_13 ) )
V_9 = - V_11 ;
return ( V_9 == F_7 ( V_13 ) ) ? 0 : V_9 ;
}
static int F_8 ( struct V_1 * V_5 , bool V_20 )
{
if ( V_20 )
V_5 -> V_21 [ 0x03 ] |= 0x01 ;
else
V_5 -> V_21 [ 0x03 ] &= ~ 0x01 & 0xff ;
return F_3 ( V_5 , 0x03 , V_5 -> V_21 [ 0x03 ] ) ;
}
static int F_9 ( struct V_1 * V_5 )
{
int V_9 ;
V_5 -> V_21 [ 0x01 ] |= 1 << 3 ;
V_5 -> V_21 [ 0x01 ] &= ( ~ ( 1 << 0 ) ) & 0xff ;
V_5 -> V_21 [ 0x05 ] &= ( ~ ( 1 << 3 ) ) & 0xff ;
V_9 = F_3 ( V_5 , 0x01 , V_5 -> V_21 [ 0x01 ] ) ;
if ( V_9 == 0 )
V_9 = F_3 ( V_5 , 0x05 , V_5 -> V_21 [ 0x05 ] ) ;
if ( V_9 < 0 )
F_10 ( & V_5 -> V_10 -> V_22 , L_1 ,
V_23 , V_5 -> V_4 . V_24 -> V_25 -> V_26 , V_5 -> V_4 . V_24 -> V_27 ) ;
return V_9 ;
}
static int F_11 ( struct V_28 * V_24 , void * V_29 )
{
struct V_1 * V_5 ;
struct V_2 * V_4 ;
V_5 = V_24 -> V_30 ;
V_4 = V_29 ;
if ( V_4 -> V_24 )
V_5 -> V_4 . V_24 = V_4 -> V_24 ;
if ( V_4 -> V_31 != V_32 )
F_10 ( & V_5 -> V_10 -> V_22 ,
L_2 , V_23 ) ;
V_5 -> V_4 . V_31 = V_33 . V_31 ;
V_5 -> V_4 . V_34 = V_4 -> V_34 ;
V_5 -> V_4 . V_35 = V_4 -> V_35 ;
if ( V_4 -> V_36 != V_37 )
V_5 -> V_4 . V_36 = V_4 -> V_36 ;
else
V_5 -> V_4 . V_36 = V_33 . V_36 ;
if ( V_4 -> V_38 != V_37 )
V_5 -> V_4 . V_38 = V_4 -> V_38 ;
else
V_5 -> V_4 . V_38 = V_33 . V_38 ;
if ( V_4 -> V_39 != V_37 )
V_5 -> V_4 . V_39 = V_4 -> V_39 ;
else
V_5 -> V_4 . V_39 = V_33 . V_39 ;
return 0 ;
}
static int F_12 ( struct V_28 * V_24 )
{
struct V_1 * V_5 ;
T_2 V_40 ;
int V_41 , V_9 ;
T_1 V_7 , V_42 ;
T_2 V_43 , V_44 ;
T_3 V_45 ;
V_5 = V_24 -> V_30 ;
V_40 = V_24 -> V_46 . V_47 ;
V_5 -> V_21 [ 0x08 ] &= 0xf0 ;
V_5 -> V_21 [ 0x08 ] |= 0x09 ;
V_5 -> V_21 [ 0x13 ] &= 0x9f ;
V_5 -> V_21 [ 0x13 ] |= 0x20 ;
V_7 = V_5 -> V_21 [ 0x02 ] & 0x0f ;
for ( V_41 = 0 ; V_41 < 8 ; V_41 ++ )
if ( V_40 < V_48 [ V_41 ] [ 0 ] && V_40 >= V_48 [ V_41 + 1 ] [ 0 ] ) {
V_7 |= V_48 [ V_41 ] [ 1 ] << 7 ;
V_7 |= V_48 [ V_41 ] [ 2 ] << 4 ;
break;
}
V_9 = F_3 ( V_5 , 0x02 , V_7 ) ;
if ( V_9 < 0 )
return V_9 ;
V_43 = ( V_40 + V_5 -> V_4 . V_31 / 2 ) / V_5 -> V_4 . V_31 ;
V_5 -> V_21 [ 0x06 ] &= 0x40 ;
V_5 -> V_21 [ 0x06 ] |= ( V_43 - 12 ) / 4 ;
V_9 = F_3 ( V_5 , 0x06 , V_5 -> V_21 [ 0x06 ] ) ;
if ( V_9 < 0 )
return V_9 ;
V_5 -> V_21 [ 0x07 ] &= 0xf0 ;
V_5 -> V_21 [ 0x07 ] |= ( V_43 - 4 * ( ( V_43 - 12 ) / 4 + 1 ) - 5 ) & 0x0f ;
V_9 = F_3 ( V_5 , 0x07 , V_5 -> V_21 [ 0x07 ] ) ;
if ( V_9 < 0 )
return V_9 ;
V_7 = V_5 -> V_21 [ 0x08 ] ;
if ( V_5 -> V_4 . V_34 ) {
V_7 &= 0xf0 ;
V_7 |= 0x02 ;
}
V_9 = F_3 ( V_5 , 0x08 , V_7 ) ;
if ( V_9 < 0 )
return V_9 ;
V_45 = ( T_3 ) F_13 ( ( ( V_49 ) V_40 ) << 20 , V_5 -> V_4 . V_31 )
- ( ( ( V_49 ) V_43 ) << 20 ) ;
if ( V_45 >= 0 )
V_44 = V_45 ;
else
V_44 = ( 1 << 22 ) + V_45 ;
V_5 -> V_21 [ 0x09 ] &= 0xc0 ;
V_5 -> V_21 [ 0x09 ] |= ( V_44 >> 16 ) & 0x3f ;
V_5 -> V_21 [ 0x0a ] = ( V_44 >> 8 ) & 0xff ;
V_5 -> V_21 [ 0x0b ] = V_44 & 0xff ;
V_9 = F_3 ( V_5 , 0x09 , V_5 -> V_21 [ 0x09 ] ) ;
if ( V_9 == 0 )
V_9 = F_3 ( V_5 , 0x0a , V_5 -> V_21 [ 0x0a ] ) ;
if ( V_9 == 0 )
V_9 = F_3 ( V_5 , 0x0b , V_5 -> V_21 [ 0x0b ] ) ;
if ( V_9 != 0 )
return V_9 ;
if ( ! V_5 -> V_4 . V_34 ) {
V_9 = F_3 ( V_5 , 0x13 , V_5 -> V_21 [ 0x13 ] ) ;
if ( V_9 < 0 )
return V_9 ;
}
V_42 = V_5 -> V_4 . V_34 ? 0x3f : 0x7f ;
V_7 = V_5 -> V_21 [ 0x0c ] & V_42 ;
V_9 = F_3 ( V_5 , 0x0c , V_7 ) ;
if ( V_9 < 0 )
return V_9 ;
F_14 ( 2000 , 3000 ) ;
V_7 = V_5 -> V_21 [ 0x0c ] | ~ V_42 ;
V_9 = F_3 ( V_5 , 0x0c , V_7 ) ;
if ( V_9 < 0 )
return V_9 ;
if ( V_5 -> V_4 . V_34 )
F_15 ( V_5 -> V_4 . V_36 ) ;
else if ( V_5 -> V_21 [ 0x03 ] & 0x01 )
F_15 ( V_5 -> V_4 . V_38 ) ;
else
F_15 ( V_5 -> V_4 . V_39 ) ;
if ( V_5 -> V_4 . V_34 ) {
V_9 = F_3 ( V_5 , 0x08 , 0x09 ) ;
if ( V_9 < 0 )
return V_9 ;
V_9 = F_3 ( V_5 , 0x13 , V_5 -> V_21 [ 0x13 ] ) ;
if ( V_9 < 0 )
return V_9 ;
}
return 0 ;
}
static int F_16 ( struct V_28 * V_24 )
{
struct V_1 * V_5 ;
int V_9 ;
V_5 = V_24 -> V_30 ;
V_5 -> V_21 [ 0x01 ] &= ( ~ ( 1 << 3 ) ) & 0xff ;
V_5 -> V_21 [ 0x01 ] |= 1 << 0 ;
V_5 -> V_21 [ 0x05 ] |= 1 << 3 ;
V_9 = F_3 ( V_5 , 0x05 , V_5 -> V_21 [ 0x05 ] ) ;
if ( V_9 == 0 )
V_9 = F_3 ( V_5 , 0x01 , V_5 -> V_21 [ 0x01 ] ) ;
if ( V_9 < 0 )
F_10 ( & V_5 -> V_10 -> V_22 , L_1 ,
V_23 , V_24 -> V_25 -> V_26 , V_24 -> V_27 ) ;
return V_9 ;
}
static int F_17 ( struct V_28 * V_24 )
{
struct V_1 * V_5 ;
T_1 V_7 ;
int V_41 , V_9 ;
V_5 = V_24 -> V_30 ;
memcpy ( V_5 -> V_21 , V_50 , sizeof( V_50 ) ) ;
F_3 ( V_5 , 0x01 , 0x0c ) ;
F_3 ( V_5 , 0x01 , 0x0c ) ;
V_9 = F_3 ( V_5 , 0x01 , 0x0c ) ;
if ( V_9 < 0 )
goto V_51;
F_14 ( 2000 , 3000 ) ;
V_7 = V_5 -> V_21 [ 0x01 ] | 0x10 ;
V_9 = F_3 ( V_5 , 0x01 , V_7 ) ;
if ( V_9 < 0 )
goto V_51;
V_9 = F_5 ( V_5 , 0x00 , & V_7 ) ;
if ( V_9 < 0 || V_7 != 0x48 )
goto V_51;
F_14 ( 2000 , 3000 ) ;
V_5 -> V_21 [ 0x0c ] |= 0x40 ;
V_9 = F_3 ( V_5 , 0x0c , V_5 -> V_21 [ 0x0c ] ) ;
if ( V_9 < 0 )
goto V_51;
F_15 ( V_5 -> V_4 . V_36 ) ;
for ( V_41 = 1 ; V_41 <= 0x0c ; V_41 ++ ) {
V_9 = F_3 ( V_5 , V_41 , V_5 -> V_21 [ V_41 ] ) ;
if ( V_9 < 0 )
goto V_51;
}
for ( V_41 = 0x11 ; V_41 < V_52 ; V_41 ++ ) {
V_9 = F_3 ( V_5 , V_41 , V_5 -> V_21 [ V_41 ] ) ;
if ( V_9 < 0 )
goto V_51;
}
V_9 = F_9 ( V_5 ) ;
if ( V_9 < 0 )
goto V_51;
V_9 = F_8 ( V_5 , V_5 -> V_4 . V_35 ) ;
if ( V_9 < 0 )
goto V_51;
return V_9 ;
V_51:
F_10 ( & V_5 -> V_10 -> V_22 , L_1 ,
V_23 , V_24 -> V_25 -> V_26 , V_24 -> V_27 ) ;
return V_9 ;
}
static int F_18 ( struct V_53 * V_54 ,
const struct V_55 * V_27 )
{
struct V_1 * V_5 ;
struct V_2 * V_4 ;
struct V_28 * V_24 ;
V_5 = F_19 ( sizeof( * V_5 ) , V_56 ) ;
if ( ! V_5 )
return - V_57 ;
V_5 -> V_10 = V_54 ;
V_4 = V_54 -> V_22 . V_58 ;
V_24 = V_4 -> V_24 ;
V_24 -> V_30 = V_5 ;
F_11 ( V_24 , V_4 ) ;
memcpy ( & V_24 -> V_59 . V_60 , & V_61 , sizeof( V_61 ) ) ;
F_20 ( V_54 , & V_5 -> V_4 ) ;
F_21 ( & V_54 -> V_22 , L_3 ) ;
return 0 ;
}
static int F_22 ( struct V_53 * V_54 )
{
struct V_1 * V_5 ;
V_5 = F_1 ( F_23 ( V_54 ) ) ;
V_5 -> V_4 . V_24 -> V_30 = NULL ;
F_24 ( V_5 ) ;
return 0 ;
}
