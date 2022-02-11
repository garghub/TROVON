static int F_1 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_4 [] , T_1 V_5 )
{
T_1 V_6 [ V_7 ] ;
struct V_8 V_9 = {
. V_10 = V_2 -> V_11 -> V_12 , . V_13 = 0 , . V_6 = V_6 , . V_5 = V_5 + 1
} ;
if ( 1 + V_5 > sizeof( V_6 ) ) {
F_2 ( V_14
L_1 ,
V_3 , V_5 ) ;
return - V_15 ;
}
V_6 [ 0 ] = V_3 ;
memcpy ( & V_6 [ 1 ] , V_4 , V_5 ) ;
if ( F_3 ( V_2 -> V_16 , & V_9 , 1 ) != 1 ) {
F_2 ( V_14 L_2 ) ;
return - V_17 ;
}
return 0 ;
}
static int F_4 ( struct V_1 * V_2 , T_1 V_3 )
{
T_1 V_18 ;
struct V_8 V_9 [ 2 ] = {
{ . V_10 = V_2 -> V_11 -> V_12 , . V_13 = 0 , . V_6 = & V_3 , . V_5 = 1 } ,
{ . V_10 = V_2 -> V_11 -> V_12 , . V_13 = V_19 , . V_6 = & V_18 , . V_5 = 1 } ,
} ;
F_1 ( V_2 , ( V_3 - 1 ) & 0xff , & V_2 -> V_20 [ ( V_3 - 1 ) & 0xff ] , 1 ) ;
if ( F_3 ( V_2 -> V_16 , V_9 , 2 ) != 2 ) {
F_5 ( L_3 ) ;
return - V_17 ;
}
return V_18 ;
}
static inline int F_6 ( struct V_1 * V_2 , T_1 V_21 , T_1 V_4 )
{
int V_22 = F_1 ( V_2 , V_21 , & V_4 , 1 ) ;
V_2 -> V_20 [ V_21 ] = V_4 ;
return V_22 ;
}
static void F_7 ( struct V_1 * V_2 , T_2 V_23 )
{
T_1 V_24 ;
T_1 V_25 = F_4 ( V_2 , V_26 ) & 0xfd ;
T_1 V_27 = F_4 ( V_2 , V_28 ) & 0x0f ;
T_1 V_29 = F_4 ( V_2 , V_30 ) & 0xf0 ;
T_1 V_31 = F_4 ( V_2 , V_32 ) & 0xf0 ;
F_8 ( L_4 , V_23 ) ;
F_6 ( V_2 , V_26 , V_25 | ( 1 << 1 ) ) ;
for ( V_24 = 0 ; V_24 < F_9 ( V_33 ) ; V_24 ++ )
if ( V_23 < V_33 [ V_24 ] . V_23 ) {
F_8 ( L_5 , V_24 , V_33 [ V_24 ] . V_34 , V_33 [ V_24 ] . V_29 ) ;
F_6 ( V_2 , V_28 , V_27 | ( V_33 [ V_24 ] . V_34 << 4 ) ) ;
F_6 ( V_2 , V_30 , V_29 | ( V_33 [ V_24 ] . V_29 ) ) ;
F_6 ( V_2 , V_32 , V_31 | ( V_24 & 0x0f ) ) ;
break;
}
F_6 ( V_2 , V_26 , V_25 | ( 0 << 1 ) ) ;
}
static void F_10 ( struct V_1 * V_2 , T_2 V_35 )
{
T_1 V_24 ;
T_1 V_36 = F_4 ( V_2 , V_37 ) & 0xbf ;
T_1 V_38 = F_4 ( V_2 , V_39 ) & 0x0f ;
T_1 V_40 ;
F_6 ( V_2 , V_37 , V_36 | ( 1 << 6 ) ) ;
for ( V_24 = 0 ; V_24 < F_9 ( V_41 ) ; V_24 ++ ) {
if ( V_35 < V_41 [ V_24 ] . V_42 ) {
F_6 ( V_2 , V_39 , V_38 | ( V_41 [ V_24 ] . V_43 << 4 ) ) ;
F_11 ( 1 ) ;
V_40 = F_4 ( V_2 , V_44 ) & 0x0f ;
F_8 ( L_6 , V_35 , V_41 [ V_24 ] . V_43 , V_40 , V_38 ) ;
if ( V_40 > 13 ) {
if ( ! ( V_41 [ V_24 ] . V_43 == 7 || V_41 [ V_24 ] . V_43 == 15 ) )
F_6 ( V_2 , V_39 , V_38 | ( ( V_41 [ V_24 ] . V_43 + 1 ) << 4 ) ) ;
} else if ( V_40 < 2 ) {
if ( ! ( V_41 [ V_24 ] . V_43 == 1 || V_41 [ V_24 ] . V_43 == 9 ) )
F_6 ( V_2 , V_39 , V_38 | ( ( V_41 [ V_24 ] . V_43 - 1 ) << 4 ) ) ;
}
break;
}
}
}
static void F_12 ( struct V_1 * V_2 , T_2 V_35 )
{
int V_24 , V_45 ;
T_2 V_46 , V_47 ;
T_3 V_48 ;
V_46 = ( V_35 * 1000 ) / 2 / V_49 ;
V_48 = V_46 % 1000000 ;
V_46 /= 1000000 ;
V_48 *= 1048576 ;
F_13 ( V_48 , 1000000 ) ;
V_47 = ( T_2 ) V_48 ;
V_2 -> V_50 = ( ( V_46 * 1000 ) + ( V_47 * 1000 ) / 1048576 ) * 2 * V_49 ;
F_8 ( L_7 , V_35 , V_2 -> V_50 , V_47 , V_46 ) ;
F_6 ( V_2 , V_51 , 0x80 ) ;
F_6 ( V_2 , V_52 , V_46 & 0xff ) ;
F_6 ( V_2 , V_28 , ( F_4 ( V_2 , V_28 ) & 0xf0 ) | ( ( V_47 >> 16 ) & 0x0f ) ) ;
F_6 ( V_2 , V_53 , ( V_47 >> 8 ) & 0xff ) ;
F_6 ( V_2 , V_54 , ( V_47 >> 0 ) & 0xff ) ;
for ( V_24 = 0 ; V_24 < F_9 ( V_55 ) ; V_24 ++ ) {
if ( V_35 <= V_55 [ V_24 ] . V_56 ) {
F_8 ( L_8 , V_24 ) ;
F_6 ( V_2 , V_57 , V_55 [ V_24 ] . V_58 [ 0 ] ) ;
for ( V_45 = 0 ; V_45 < 9 ; V_45 ++ )
F_6 ( V_2 , V_59 + V_45 , V_55 [ V_24 ] . V_58 [ V_45 + 1 ] ) ;
break;
}
}
F_10 ( V_2 , V_35 ) ;
}
static int F_14 ( struct V_60 * V_61 )
{
struct V_62 * V_63 = & V_61 -> V_64 ;
struct V_1 * V_2 = V_61 -> V_65 ;
T_1 V_66 ;
F_12 ( V_2 , V_63 -> V_50 ) ;
F_7 ( V_2 , V_63 -> V_23 ) ;
V_66 = F_4 ( V_2 , V_67 ) & 0x7f ;
F_6 ( V_2 , V_67 , V_66 | ( 1 << 7 ) ) ;
F_6 ( V_2 , V_67 , V_66 ) ;
return 0 ;
}
static int F_15 ( struct V_60 * V_61 , T_2 * V_50 )
{
struct V_1 * V_2 = V_61 -> V_65 ;
* V_50 = V_2 -> V_50 ;
return 0 ;
}
static int F_16 ( struct V_60 * V_61 , T_2 * V_68 )
{
return 0 ;
}
static int F_17 ( struct V_60 * V_61 )
{
struct V_1 * V_2 = V_61 -> V_65 ;
int V_24 ;
for ( V_24 = 0 ; V_24 < F_9 ( V_69 ) ; V_24 ++ )
F_6 ( V_2 , V_69 [ V_24 ] [ 0 ] , V_69 [ V_24 ] [ 1 ] ) ;
for ( V_24 = 0 ; V_24 < F_9 ( V_70 ) ; V_24 ++ )
F_6 ( V_2 , V_70 [ V_24 ] [ 0 ] , V_70 [ V_24 ] [ 1 ] ) ;
return 0 ;
}
static int F_18 ( struct V_60 * V_61 )
{
return 0 ;
}
static int F_19 ( struct V_60 * V_61 )
{
F_20 ( V_61 -> V_65 ) ;
V_61 -> V_65 = NULL ;
return 0 ;
}
struct V_60 * F_21 ( struct V_60 * V_61 , struct V_71 * V_16 , struct V_72 * V_11 )
{
struct V_1 * V_2 = NULL ;
T_1 V_24 = 0 ;
V_2 = F_22 ( sizeof( struct V_1 ) , V_73 ) ;
if ( V_2 == NULL )
return NULL ;
V_2 -> V_11 = V_11 ;
V_2 -> V_16 = V_16 ;
V_24 = F_4 ( V_2 , 0 ) ;
if ( V_24 != 0 ) {
F_20 ( V_2 ) ;
return NULL ;
}
F_23 ( L_9 , V_24 ) ;
memset ( V_2 -> V_20 , 0xff , sizeof( V_2 -> V_20 ) ) ;
for ( V_24 = 0x65 ; V_24 < 0x9c ; V_24 ++ )
V_2 -> V_20 [ V_24 ] = F_4 ( V_2 , V_24 ) ;
memcpy ( & V_61 -> V_74 . V_75 , & V_76 , sizeof( struct V_77 ) ) ;
V_61 -> V_65 = V_2 ;
return V_61 ;
}
