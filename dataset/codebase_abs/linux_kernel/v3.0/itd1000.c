static int F_1 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_4 [] , T_1 V_5 )
{
T_1 V_6 [ 1 + V_5 ] ;
struct V_7 V_8 = {
. V_9 = V_2 -> V_10 -> V_11 , . V_12 = 0 , . V_6 = V_6 , . V_5 = V_5 + 1
} ;
V_6 [ 0 ] = V_3 ;
memcpy ( & V_6 [ 1 ] , V_4 , V_5 ) ;
if ( F_2 ( V_2 -> V_13 , & V_8 , 1 ) != 1 ) {
F_3 ( V_14 L_1 ) ;
return - V_15 ;
}
return 0 ;
}
static int F_4 ( struct V_1 * V_2 , T_1 V_3 )
{
T_1 V_16 ;
struct V_7 V_8 [ 2 ] = {
{ . V_9 = V_2 -> V_10 -> V_11 , . V_12 = 0 , . V_6 = & V_3 , . V_5 = 1 } ,
{ . V_9 = V_2 -> V_10 -> V_11 , . V_12 = V_17 , . V_6 = & V_16 , . V_5 = 1 } ,
} ;
F_1 ( V_2 , ( V_3 - 1 ) & 0xff , & V_2 -> V_18 [ ( V_3 - 1 ) & 0xff ] , 1 ) ;
if ( F_2 ( V_2 -> V_13 , V_8 , 2 ) != 2 ) {
F_5 ( L_2 ) ;
return - V_15 ;
}
return V_16 ;
}
static inline int F_6 ( struct V_1 * V_2 , T_1 V_19 , T_1 V_4 )
{
int V_20 = F_1 ( V_2 , V_19 , & V_4 , 1 ) ;
V_2 -> V_18 [ V_19 ] = V_4 ;
return V_20 ;
}
static void F_7 ( struct V_1 * V_2 , T_2 V_21 )
{
T_1 V_22 ;
T_1 V_23 = F_4 ( V_2 , V_24 ) & 0xfd ;
T_1 V_25 = F_4 ( V_2 , V_26 ) & 0x0f ;
T_1 V_27 = F_4 ( V_2 , V_28 ) & 0xf0 ;
T_1 V_29 = F_4 ( V_2 , V_30 ) & 0xf0 ;
F_8 ( L_3 , V_21 ) ;
F_6 ( V_2 , V_24 , V_23 | ( 1 << 1 ) ) ;
for ( V_22 = 0 ; V_22 < F_9 ( V_31 ) ; V_22 ++ )
if ( V_21 < V_31 [ V_22 ] . V_21 ) {
F_8 ( L_4 , V_22 , V_31 [ V_22 ] . V_32 , V_31 [ V_22 ] . V_27 ) ;
F_6 ( V_2 , V_26 , V_25 | ( V_31 [ V_22 ] . V_32 << 4 ) ) ;
F_6 ( V_2 , V_28 , V_27 | ( V_31 [ V_22 ] . V_27 ) ) ;
F_6 ( V_2 , V_30 , V_29 | ( V_22 & 0x0f ) ) ;
break;
}
F_6 ( V_2 , V_24 , V_23 | ( 0 << 1 ) ) ;
}
static void F_10 ( struct V_1 * V_2 , T_2 V_33 )
{
T_1 V_22 ;
T_1 V_34 = F_4 ( V_2 , V_35 ) & 0xbf ;
T_1 V_36 = F_4 ( V_2 , V_37 ) & 0x0f ;
T_1 V_38 ;
F_6 ( V_2 , V_35 , V_34 | ( 1 << 6 ) ) ;
for ( V_22 = 0 ; V_22 < F_9 ( V_39 ) ; V_22 ++ ) {
if ( V_33 < V_39 [ V_22 ] . V_40 ) {
F_6 ( V_2 , V_37 , V_36 | ( V_39 [ V_22 ] . V_41 << 4 ) ) ;
F_11 ( 1 ) ;
V_38 = F_4 ( V_2 , V_42 ) & 0x0f ;
F_8 ( L_5 , V_33 , V_39 [ V_22 ] . V_41 , V_38 , V_36 ) ;
if ( V_38 > 13 ) {
if ( ! ( V_39 [ V_22 ] . V_41 == 7 || V_39 [ V_22 ] . V_41 == 15 ) )
F_6 ( V_2 , V_37 , V_36 | ( ( V_39 [ V_22 ] . V_41 + 1 ) << 4 ) ) ;
} else if ( V_38 < 2 ) {
if ( ! ( V_39 [ V_22 ] . V_41 == 1 || V_39 [ V_22 ] . V_41 == 9 ) )
F_6 ( V_2 , V_37 , V_36 | ( ( V_39 [ V_22 ] . V_41 - 1 ) << 4 ) ) ;
}
break;
}
}
}
static void F_12 ( struct V_1 * V_2 , T_2 V_33 )
{
int V_22 , V_43 ;
T_2 V_44 , V_45 ;
T_3 V_46 ;
V_44 = ( V_33 * 1000 ) / 2 / V_47 ;
V_46 = V_44 % 1000000 ;
V_44 /= 1000000 ;
V_46 *= 1048576 ;
F_13 ( V_46 , 1000000 ) ;
V_45 = ( T_2 ) V_46 ;
V_2 -> V_48 = ( ( V_44 * 1000 ) + ( V_45 * 1000 ) / 1048576 ) * 2 * V_47 ;
F_8 ( L_6 , V_33 , V_2 -> V_48 , V_45 , V_44 ) ;
F_6 ( V_2 , V_49 , 0x80 ) ; ;
F_6 ( V_2 , V_50 , V_44 & 0xff ) ;
F_6 ( V_2 , V_26 , ( F_4 ( V_2 , V_26 ) & 0xf0 ) | ( ( V_45 >> 16 ) & 0x0f ) ) ;
F_6 ( V_2 , V_51 , ( V_45 >> 8 ) & 0xff ) ;
F_6 ( V_2 , V_52 , ( V_45 >> 0 ) & 0xff ) ;
for ( V_22 = 0 ; V_22 < F_9 ( V_53 ) ; V_22 ++ ) {
if ( V_33 <= V_53 [ V_22 ] . V_54 ) {
F_8 ( L_7 , V_22 ) ;
F_6 ( V_2 , V_55 , V_53 [ V_22 ] . V_56 [ 0 ] ) ;
for ( V_43 = 0 ; V_43 < 9 ; V_43 ++ )
F_6 ( V_2 , V_57 + V_43 , V_53 [ V_22 ] . V_56 [ V_43 + 1 ] ) ;
break;
}
}
F_10 ( V_2 , V_33 ) ;
}
static int F_14 ( struct V_58 * V_59 , struct V_60 * V_61 )
{
struct V_1 * V_2 = V_59 -> V_62 ;
T_1 V_63 ;
F_12 ( V_2 , V_61 -> V_48 ) ;
F_7 ( V_2 , V_61 -> V_64 . V_65 . V_21 ) ;
V_63 = F_4 ( V_2 , V_66 ) & 0x7f ;
F_6 ( V_2 , V_66 , V_63 | ( 1 << 7 ) ) ;
F_6 ( V_2 , V_66 , V_63 ) ;
return 0 ;
}
static int F_15 ( struct V_58 * V_59 , T_2 * V_48 )
{
struct V_1 * V_2 = V_59 -> V_62 ;
* V_48 = V_2 -> V_48 ;
return 0 ;
}
static int F_16 ( struct V_58 * V_59 , T_2 * V_67 )
{
return 0 ;
}
static int F_17 ( struct V_58 * V_59 )
{
struct V_1 * V_2 = V_59 -> V_62 ;
int V_22 ;
for ( V_22 = 0 ; V_22 < F_9 ( V_68 ) ; V_22 ++ )
F_6 ( V_2 , V_68 [ V_22 ] [ 0 ] , V_68 [ V_22 ] [ 1 ] ) ;
for ( V_22 = 0 ; V_22 < F_9 ( V_69 ) ; V_22 ++ )
F_6 ( V_2 , V_69 [ V_22 ] [ 0 ] , V_69 [ V_22 ] [ 1 ] ) ;
return 0 ;
}
static int F_18 ( struct V_58 * V_59 )
{
return 0 ;
}
static int F_19 ( struct V_58 * V_59 )
{
F_20 ( V_59 -> V_62 ) ;
V_59 -> V_62 = NULL ;
return 0 ;
}
struct V_58 * F_21 ( struct V_58 * V_59 , struct V_70 * V_13 , struct V_71 * V_10 )
{
struct V_1 * V_2 = NULL ;
T_1 V_22 = 0 ;
V_2 = F_22 ( sizeof( struct V_1 ) , V_72 ) ;
if ( V_2 == NULL )
return NULL ;
V_2 -> V_10 = V_10 ;
V_2 -> V_13 = V_13 ;
V_22 = F_4 ( V_2 , 0 ) ;
if ( V_22 != 0 ) {
F_20 ( V_2 ) ;
return NULL ;
}
F_23 ( L_8 , V_22 ) ;
memset ( V_2 -> V_18 , 0xff , sizeof( V_2 -> V_18 ) ) ;
for ( V_22 = 0x65 ; V_22 < 0x9c ; V_22 ++ )
V_2 -> V_18 [ V_22 ] = F_4 ( V_2 , V_22 ) ;
memcpy ( & V_59 -> V_73 . V_74 , & V_75 , sizeof( struct V_76 ) ) ;
V_59 -> V_62 = V_2 ;
return V_59 ;
}
