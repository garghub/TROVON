static struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_4 ) ;
}
static int F_3 ( struct V_1 * V_5 , const T_1 * V_6 , int V_7 )
{
int V_8 ;
V_8 = F_4 ( V_5 -> V_9 , V_6 , V_7 ) ;
if ( V_8 >= 0 && V_8 < V_7 )
V_8 = - V_10 ;
return ( V_8 == V_7 ) ? 0 : V_8 ;
}
static int F_5 ( struct V_1 * V_5 , T_1 V_11 , T_1 V_12 )
{
T_1 V_6 [ 2 ] = { V_11 , V_12 } ;
return F_3 ( V_5 , V_6 , 2 ) ;
}
static int F_6 ( struct V_1 * V_5 , T_1 V_11 , T_1 * V_12 )
{
T_1 V_13 [ 2 ] = { 0xfb , V_11 } ;
int V_8 ;
V_8 = F_3 ( V_5 , V_13 , sizeof( V_13 ) ) ;
if ( V_8 == 0 )
V_8 = F_7 ( V_5 -> V_9 , V_12 , 1 ) ;
if ( V_8 >= 0 && V_8 < 1 )
V_8 = - V_10 ;
return ( V_8 == 1 ) ? 0 : V_8 ;
}
static int F_8 ( struct V_14 * V_15 , T_2 * V_16 )
{
struct V_1 * V_5 ;
int V_8 ;
T_1 V_17 , V_18 , V_19 , V_20 ;
T_2 V_21 , V_22 ;
T_3 V_23 ;
struct V_24 * V_25 ;
V_25 = & V_15 -> V_26 . V_27 ;
V_25 -> V_7 = 1 ;
V_25 -> V_28 [ 0 ] . V_29 = V_30 ;
* V_16 = 0 ;
V_5 = V_15 -> V_31 ;
V_8 = F_5 ( V_5 , 0x14 , 0x01 ) ;
if ( V_8 < 0 )
return V_8 ;
F_9 ( 1000 , 2000 ) ;
V_8 = F_6 ( V_5 , 0x18 , & V_17 ) ;
if ( V_8 == 0 )
V_8 = F_6 ( V_5 , 0x19 , & V_18 ) ;
if ( V_8 == 0 )
V_8 = F_6 ( V_5 , 0xd6 , & V_19 ) ;
if ( V_8 == 0 )
V_8 = F_6 ( V_5 , 0xd7 , & V_20 ) ;
if ( V_8 != 0 )
return V_8 ;
V_21 = ( V_18 & 0x07 ) << 8 | V_17 ;
V_22 = ( V_20 & 0x0f ) << 5 | ( V_19 >> 3 ) ;
V_23 = V_21 - V_22 - ( 113 << 3 ) ;
V_23 = V_23 * 1000 / 8 ;
V_25 -> V_28 [ 0 ] . V_32 = V_23 ;
V_25 -> V_28 [ 0 ] . V_29 = V_33 ;
* V_16 = ( V_21 - V_22 + ( 1 << 9 ) - 1 ) * 100 / ( ( 5 << 9 ) - 2 ) ;
return 0 ;
}
static int F_10 ( struct V_14 * V_15 )
{
struct V_34 V_35 [] = {
{ 0x13 , 0x00 } ,
{ 0x3b , 0xc0 } ,
{ 0x3b , 0x80 } ,
{ 0x10 , 0x95 } ,
{ 0x1a , 0x05 } ,
{ 0x61 , 0x00 } ,
{ 0x62 , 0xa0 }
} ;
struct V_34 V_36 [] = {
{ 0x11 , 0x40 } ,
{ 0x12 , 0x0e } ,
{ 0x13 , 0x01 }
} ;
struct V_1 * V_5 ;
T_4 V_37 ;
T_2 V_38 ;
T_4 V_39 , div ;
int V_40 , V_8 ;
V_5 = V_15 -> V_31 ;
V_37 = V_15 -> V_26 . V_41 ;
for ( V_40 = 0 ; V_40 < F_11 ( V_42 ) ; V_40 ++ ) {
if ( V_37 >= ( V_42 [ V_40 ] . V_37 - V_42 [ V_40 ] . V_43 ) * 1000 &&
V_37 <= ( V_42 [ V_40 ] . V_37 + V_42 [ V_40 ] . V_43 ) * 1000 ) {
V_35 [ 5 ] . V_12 = V_42 [ V_40 ] . V_44 ;
V_35 [ 6 ] . V_12 = 0xa0 | V_42 [ V_40 ] . V_45 ;
break;
}
}
V_8 = F_3 ( V_5 , ( T_1 * ) V_35 , sizeof( V_35 ) ) ;
if ( V_8 < 0 )
goto V_46;
F_9 ( 3000 , 4000 ) ;
V_38 = V_37 / 1000000 ;
V_39 = V_37 % 1000000 ;
div = 1000000 ;
for ( V_40 = 0 ; V_40 < 6 ; V_40 ++ ) {
V_38 <<= 1 ;
div >>= 1 ;
if ( V_39 > div ) {
V_39 -= div ;
V_38 |= 1 ;
}
}
if ( V_39 > 7812 )
V_38 ++ ;
V_36 [ 0 ] . V_12 = V_38 & 0xff ;
V_36 [ 1 ] . V_12 = V_38 >> 8 ;
V_8 = F_3 ( V_5 , ( T_1 * ) V_36 , sizeof( V_36 ) ) ;
if ( V_8 < 0 )
goto V_46;
F_12 ( 31 ) ;
V_8 = F_5 ( V_5 , 0x1a , 0x0d ) ;
if ( V_8 < 0 )
goto V_46;
V_8 = F_3 ( V_5 , ( T_1 * ) V_47 , sizeof( V_47 ) ) ;
if ( V_8 < 0 )
goto V_46;
return 0 ;
V_46:
F_13 ( & V_5 -> V_9 -> V_48 , L_1 ,
V_49 , V_15 -> V_50 -> V_51 , V_15 -> V_52 ) ;
return V_8 ;
}
static int F_14 ( struct V_14 * V_15 )
{
struct V_1 * V_5 ;
int V_8 ;
V_5 = V_15 -> V_31 ;
V_8 = F_3 ( V_5 , ( T_1 * ) V_53 , sizeof( V_53 ) ) ;
if ( V_8 < 0 )
F_13 ( & V_5 -> V_9 -> V_48 , L_1 ,
V_49 , V_15 -> V_50 -> V_51 , V_15 -> V_52 ) ;
return V_8 ;
}
static int F_15 ( struct V_14 * V_15 )
{
struct V_1 * V_5 ;
int V_8 ;
V_5 = V_15 -> V_31 ;
V_8 = F_5 ( V_5 , 0x01 , 0x01 ) ;
if ( V_8 < 0 ) {
F_13 ( & V_5 -> V_9 -> V_48 , L_1 ,
V_49 , V_15 -> V_50 -> V_51 , V_15 -> V_52 ) ;
return V_8 ;
}
return 0 ;
}
static int F_16 ( struct V_54 * V_55 ,
const struct V_56 * V_52 )
{
struct V_1 * V_5 ;
struct V_2 * V_4 ;
struct V_14 * V_15 ;
V_5 = F_17 ( sizeof( * V_5 ) , V_57 ) ;
if ( ! V_5 )
return - V_58 ;
V_5 -> V_9 = V_55 ;
V_4 = V_55 -> V_48 . V_59 ;
memcpy ( & V_5 -> V_4 , V_4 , sizeof( V_5 -> V_4 ) ) ;
V_15 = V_4 -> V_15 ;
V_15 -> V_31 = V_5 ;
memcpy ( & V_15 -> V_60 . V_61 , & V_62 , sizeof( V_62 ) ) ;
F_18 ( V_55 , & V_5 -> V_4 ) ;
F_19 ( & V_55 -> V_48 , L_2 ) ;
return 0 ;
}
static int F_20 ( struct V_54 * V_55 )
{
struct V_1 * V_5 ;
V_5 = F_1 ( F_21 ( V_55 ) ) ;
V_5 -> V_4 . V_15 -> V_31 = NULL ;
F_22 ( V_5 ) ;
return 0 ;
}
