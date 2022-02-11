static int F_1 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_4 )
{
int V_5 ;
T_1 V_6 [] = { V_3 , V_4 } ;
struct V_7 V_8 = { . V_9 = V_2 -> V_10 -> V_11 , . V_12 = 0 , . V_6 = V_6 , . V_13 = 2 } ;
F_2 ( L_1 , V_14 ) ;
V_5 = F_3 ( V_2 -> V_15 , & V_8 , 1 ) ;
if ( V_5 != 1 )
F_4 ( L_2 ,
V_14 , V_3 , V_4 , V_5 ) ;
return ( V_5 != 1 ) ? - 1 : 0 ;
}
static int F_5 ( struct V_1 * V_2 , T_1 V_3 )
{
int V_5 ;
T_1 V_16 [] = { V_3 } ;
T_1 V_17 [] = { 0 } ;
struct V_7 V_8 [] = { { . V_9 = V_2 -> V_10 -> V_11 , . V_12 = 0 , . V_6 = V_16 , . V_13 = 1 } ,
{ . V_9 = V_2 -> V_10 -> V_11 , . V_12 = V_18 , . V_6 = V_17 , . V_13 = 1 } } ;
F_2 ( L_1 , V_14 ) ;
V_5 = F_3 ( V_2 -> V_15 , V_8 , 2 ) ;
if ( V_5 != 2 ) return - V_19 ;
return V_17 [ 0 ] ;
}
static int F_6 ( struct V_1 * V_2 , int V_20 )
{
T_1 V_21 ;
F_2 ( L_1 , V_14 ) ;
switch ( V_20 ) {
case V_22 :
return - V_23 ;
case V_24 :
V_21 = F_5 ( V_2 , 0x09 ) ;
return F_1 ( V_2 , 0x09 , V_21 | 0x01 ) ;
case V_25 :
V_21 = F_5 ( V_2 , 0x09 ) ;
return F_1 ( V_2 , 0x09 , V_21 & 0xfe ) ;
default:
return - V_26 ;
}
}
static int F_7 ( struct V_1 * V_2 ,
struct V_27 * V_28 )
{
static const T_1 V_29 [ 4 ] = { 0 , 1 , 0 , 2 } ;
static const T_1 V_30 [ 6 ] = { 0 , 1 , 2 , 0 , 3 , 4 } ;
T_1 V_21 ;
F_2 ( L_1 , V_14 ) ;
if ( V_28 -> V_31 < V_32 || V_28 -> V_31 > V_33 )
return - V_26 ;
if ( V_28 -> V_34 < V_32 || V_28 -> V_34 > V_33 )
return - V_26 ;
if ( V_28 -> V_31 == V_35 || V_28 -> V_34 == V_35 )
return - V_26 ;
if ( ( int ) V_28 -> V_36 < V_37 ||
V_28 -> V_36 > V_38 )
return - V_26 ;
if ( V_28 -> V_39 != V_40 &&
V_28 -> V_39 != V_41 )
return - V_26 ;
if ( V_28 -> V_42 != V_43 &&
V_28 -> V_42 != V_44 &&
V_28 -> V_42 != V_45 )
return - V_26 ;
if ( ( int ) V_28 -> V_46 < V_47 ||
V_28 -> V_46 > V_48 )
return - V_26 ;
if ( V_28 -> V_49 > 8000000 || V_28 -> V_49 < 6000000 )
return - V_26 ;
if ( V_28 -> V_49 == 7000000 )
F_1 ( V_2 , 0x09 , F_5 ( V_2 , 0x09 | 0x10 ) ) ;
else
F_1 ( V_2 , 0x09 , F_5 ( V_2 , 0x09 & ~ 0x10 ) ) ;
V_21 = V_29 [ V_28 -> V_42 - V_43 ] ;
V_21 |= V_28 -> V_46 - V_47 ;
F_1 ( V_2 , 0x04 , V_21 ) ;
V_21 = V_30 [ V_28 -> V_31 - V_32 ] << 3 ;
V_21 |= V_30 [ V_28 -> V_34 - V_32 ] ;
F_1 ( V_2 , 0x05 , V_21 ) ;
V_21 = ( V_28 -> V_36 - V_37 ) << 2 ;
V_21 |= V_28 -> V_39 - V_40 ;
F_1 ( V_2 , 0x06 , V_21 ) ;
F_1 ( V_2 , 0x08 , 0x04 | 0x02 ) ;
F_1 ( V_2 , 0x08 , 0x04 ) ;
return 0 ;
}
static int F_8 ( struct V_1 * V_2 ,
struct V_27 * V_28 )
{
static const T_2 V_29 [ 3 ] = { V_43 , V_44 , V_45 } ;
static const T_3 V_30 [ 5 ] = { V_32 , V_50 , V_51 ,
V_52 , V_33 } ;
T_1 V_21 ;
F_2 ( L_1 , V_14 ) ;
if ( ! ( F_5 ( V_2 , 0x07 ) & 0x20 ) )
return - V_53 ;
V_21 = F_5 ( V_2 , 0x01 ) ;
if ( ( V_21 & 0x7 ) > 4 )
V_28 -> V_46 = V_54 ;
else
V_28 -> V_46 = V_47 + ( V_21 & 0x7 ) ;
if ( ( ( V_21 >> 3 ) & 0x3 ) > 2 )
V_28 -> V_42 = V_55 ;
else
V_28 -> V_42 = V_29 [ ( V_21 >> 3 ) & 0x3 ] ;
V_21 = F_5 ( V_2 , 0x02 ) ;
if ( ( ( V_21 >> 3 ) & 0x07 ) > 4 )
V_28 -> V_31 = V_56 ;
else
V_28 -> V_31 = V_30 [ ( V_21 >> 3 ) & 0x07 ] ;
if ( ( V_21 & 0x07 ) > 4 )
V_28 -> V_34 = V_56 ;
else
V_28 -> V_34 = V_30 [ V_21 & 0x07 ] ;
V_21 = F_5 ( V_2 , 0x03 ) ;
V_28 -> V_36 = V_37 + ( ( V_21 >> 6 ) & 0x3 ) ;
V_28 -> V_39 = V_40 + ( ( V_21 >> 5 ) & 0x1 ) ;
return 0 ;
}
static int F_9 ( struct V_57 * V_58 )
{ struct V_1 * V_2 = V_58 -> V_59 ;
int V_60 ;
F_2 ( L_3 ) ;
F_1 ( V_2 , 0x00 , 0x02 ) ;
F_1 ( V_2 , 0x00 , 0x00 ) ;
F_10 ( 10 ) ;
for ( V_60 = 0 ; V_60 < sizeof( V_61 ) ; V_60 += 2 )
F_1 ( V_2 , V_61 [ V_60 ] , V_61 [ V_60 + 1 ] ) ;
F_1 ( V_2 , 0x00 , 0x01 ) ;
return 0 ;
}
static int F_11 ( struct V_57 * V_58 , T_4 * V_62 )
{
struct V_1 * V_2 = V_58 -> V_59 ;
T_5 V_63 = ( F_5 ( V_2 , 0x0d ) << 9 )
| ( F_5 ( V_2 , 0x0e ) << 1 ) ;
T_1 V_64 = F_5 ( V_2 , 0x07 ) ;
* V_62 = 0 ;
if ( V_63 < 0xff00 )
* V_62 |= V_65 ;
if ( V_64 & 0x20 )
* V_62 |= V_66 ;
if ( V_64 & 0x10 )
* V_62 |= V_67 ;
if ( V_64 & 0x10 )
* V_62 |= V_68 ;
if ( * V_62 == 0x0f )
* V_62 |= V_69 ;
return 0 ;
}
static int F_12 ( struct V_57 * V_58 , T_6 * V_70 )
{
struct V_1 * V_2 = V_58 -> V_59 ;
* V_70 = F_5 ( V_2 , 0x0c ) & 0x7f ;
F_1 ( V_2 , 0x0c , 0x00 ) ;
return 0 ;
}
static int F_13 ( struct V_57 * V_58 , T_5 * V_71 )
{
struct V_1 * V_2 = V_58 -> V_59 ;
T_5 V_63 = ( F_5 ( V_2 , 0x0d ) << 9 )
| ( F_5 ( V_2 , 0x0e ) << 1 ) ;
* V_71 = ~ V_63 ;
return 0 ;
}
static int F_14 ( struct V_57 * V_58 , T_5 * V_72 )
{
struct V_1 * V_2 = V_58 -> V_59 ;
T_5 V_63 = ( F_5 ( V_2 , 0x0d ) << 9 )
| ( F_5 ( V_2 , 0x0e ) << 1 ) ;
* V_72 = ~ V_63 ;
return 0 ;
}
static int F_15 ( struct V_57 * V_58 , T_6 * V_73 )
{
struct V_1 * V_2 = V_58 -> V_59 ;
* V_73 = F_5 ( V_2 , 0x0f ) ;
F_1 ( V_2 , 0x0f , 0x00 ) ;
return 0 ;
}
static int F_16 ( struct V_57 * V_58 )
{
struct V_27 * V_74 = & V_58 -> V_75 ;
struct V_1 * V_2 = V_58 -> V_59 ;
F_1 ( V_2 , 0x00 , 0x02 ) ;
F_1 ( V_2 , 0x00 , 0x00 ) ;
if ( V_58 -> V_76 . V_77 . V_78 ) {
V_58 -> V_76 . V_77 . V_78 ( V_58 ) ;
if ( V_58 -> V_76 . V_79 ) V_58 -> V_76 . V_79 ( V_58 , 0 ) ;
}
F_6 ( V_2 , V_74 -> V_20 ) ;
F_7 ( V_2 , V_74 ) ;
F_1 ( V_2 , 0x37 , 0x01 ) ;
F_1 ( V_2 , 0x00 , 0x01 ) ;
return 0 ;
}
static int F_17 ( struct V_57 * V_58 )
{
struct V_27 * V_74 = & V_58 -> V_75 ;
struct V_1 * V_2 = V_58 -> V_59 ;
T_1 V_80 = F_5 ( V_2 , 0x09 ) ;
V_74 -> V_20 = V_80 & 0x1 ? V_24 : V_25 ;
return F_8 ( V_2 , V_74 ) ;
}
static int F_18 ( struct V_57 * V_58 , int V_81 )
{
struct V_1 * V_2 = V_58 -> V_59 ;
if ( V_81 ) {
return F_1 ( V_2 , 0x0a , 0x00 ) ;
} else {
return F_1 ( V_2 , 0x0a , 0x01 ) ;
}
}
static int F_19 ( struct V_57 * V_58 , struct V_82 * V_83 )
{
V_83 -> V_84 = 150 ;
V_83 -> V_85 = 166667 ;
V_83 -> V_86 = 166667 * 2 ;
return 0 ;
}
static void F_20 ( struct V_57 * V_58 )
{
struct V_1 * V_2 = V_58 -> V_59 ;
F_21 ( V_2 ) ;
}
struct V_57 * F_22 ( const struct V_87 * V_10 ,
struct V_88 * V_15 )
{
struct V_1 * V_2 = NULL ;
V_2 = F_23 ( sizeof( struct V_1 ) , V_89 ) ;
if ( V_2 == NULL ) goto error;
V_2 -> V_10 = V_10 ;
V_2 -> V_15 = V_15 ;
if ( F_5 ( V_2 , 0x07 ) < 0 ) goto error;
memcpy ( & V_2 -> V_90 . V_76 , & V_91 , sizeof( struct V_92 ) ) ;
V_2 -> V_90 . V_59 = V_2 ;
return & V_2 -> V_90 ;
error:
F_21 ( V_2 ) ;
return NULL ;
}
