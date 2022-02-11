static int F_1 ( struct V_1 * V_2 ,
const T_1 V_3 , T_2 * V_4 , const T_3 V_5 )
{
int V_6 ;
T_2 V_7 [ 3 ] ;
struct V_8 V_9 [ 2 ] ;
V_7 [ 0 ] = V_3 & 0xFF ;
V_7 [ 1 ] = 0 ;
V_7 [ 2 ] = V_3 >> 8 ;
V_9 [ 0 ] . V_10 = V_2 -> V_11 . V_12 ;
V_9 [ 0 ] . V_13 = 0 ;
V_9 [ 0 ] . V_4 = V_7 ;
V_9 [ 0 ] . V_14 = sizeof( V_7 ) ;
V_9 [ 1 ] . V_10 = V_9 [ 0 ] . V_10 ;
V_9 [ 1 ] . V_13 = V_15 ;
V_9 [ 1 ] . V_4 = V_4 ;
V_9 [ 1 ] . V_14 = V_5 ;
V_6 = F_2 ( V_2 -> V_16 , V_9 , 2 ) ;
if ( V_6 != 2 ) {
F_3 ( L_1 ) ;
return - V_17 ;
}
return 0 ;
}
static int F_4 ( struct V_1 * V_2 ,
const T_2 V_3 , const T_2 V_18 )
{
struct V_8 V_9 ;
T_2 V_7 [ 2 ] ;
V_7 [ 0 ] = V_3 ;
V_7 [ 1 ] = V_18 ;
V_9 . V_10 = V_2 -> V_11 . V_12 ;
V_9 . V_13 = 0 ;
V_9 . V_4 = V_7 ;
V_9 . V_14 = sizeof( V_7 ) ;
if ( F_2 ( V_2 -> V_16 , & V_9 , 1 ) != 1 ) {
F_3 ( L_2 ) ;
return - V_17 ;
}
return 0 ;
}
static int F_5 ( struct V_19 * V_20 , const T_2 V_4 [] , int V_14 )
{
struct V_1 * V_2 = V_20 -> V_21 ;
int V_22 , V_23 ;
for ( V_23 = 0 ; V_23 < V_14 - 1 ; V_23 ++ ) {
V_22 = F_4 ( V_2 ,
V_4 [ 0 ] + V_23 , V_4 [ V_23 + 1 ] ) ;
if ( V_22 )
return V_22 ;
}
return 0 ;
}
static int F_6 ( struct V_1 * V_2 , T_2 * V_24 )
{
int V_6 ;
T_2 V_25 = ( V_2 -> V_11 . V_26 << 1 ) + 1 ;
* V_24 = 0 ;
V_6 = F_4 ( V_2 , V_27 ,
V_25 ) ;
if ( V_6 )
goto error;
V_6 = F_1 ( V_2 , 0x0100 , V_24 , 1 ) ;
if ( V_6 )
goto error;
F_3 ( L_3 , * V_24 ) ;
return 0 ;
error:
F_3 ( L_4 , V_28 , V_6 ) ;
return - V_17 ;
}
static int F_7 ( struct V_1 * V_2 , T_4 V_29 )
{
int V_6 ;
int V_30 ;
T_2 V_31 ;
T_2 V_32 [ 9 ] ;
T_2 V_33 [ V_34 ] ;
T_2 V_35 [ V_34 ] ;
struct V_8 V_9 [ 2 ] ;
T_4 V_36 ;
F_3 ( L_5 , V_28 , V_29 ,
V_2 -> V_37 . V_38 . V_39 . V_40 ) ;
V_36 = V_29 / V_2 -> V_37 . V_38 . V_39 . V_40 ;
V_36 += 399 ;
if ( V_36 % 7 == 0 )
V_36 ++ ;
V_33 [ V_41 ] = V_27 ;
V_33 [ V_42 ] = V_2 -> V_11 . V_26 << 1 ;
V_33 [ V_43 ] = ( V_36 >> 8 ) & 0x7F ;
V_33 [ V_44 ] = V_36 & 0xFF ;
V_33 [ V_45 ] = 0xB2 ;
V_33 [ V_46 ] = 0x08 ;
V_9 [ 0 ] . V_10 = V_2 -> V_11 . V_12 ;
V_9 [ 0 ] . V_13 = 0 ;
V_9 [ 0 ] . V_4 = V_33 ;
V_9 [ 0 ] . V_14 = sizeof( V_33 ) ;
V_6 = F_2 ( V_2 -> V_16 , & V_9 [ 0 ] , 1 ) ;
if ( V_6 != 1 )
goto error;
F_8 ( 50 ) ;
V_35 [ V_41 ] = V_33 [ V_41 ] ;
V_35 [ V_42 ] = V_33 [ V_42 ] ;
V_35 [ V_43 ] = V_33 [ V_43 ] ;
V_35 [ V_44 ] = V_33 [ V_44 ] ;
V_35 [ V_45 ] = 0x9A ;
V_35 [ V_47 ] = 0x50 ;
V_9 [ 1 ] . V_10 = V_9 [ 0 ] . V_10 ;
V_9 [ 1 ] . V_13 = 0 ;
V_9 [ 1 ] . V_4 = V_35 ;
V_9 [ 1 ] . V_14 = sizeof( V_35 ) ;
V_6 = F_2 ( V_2 -> V_16 , & V_9 [ 1 ] , 1 ) ;
if ( V_6 != 1 )
goto error;
V_6 = F_4 ( V_2 , 0x01 , 0x40 ) ;
V_6 |= F_4 ( V_2 , 0x01 , 0x00 ) ;
if ( V_6 )
goto error;
F_8 ( 100 ) ;
#define F_9 5
for ( V_30 = 0 ; V_30 < F_9 ; V_30 ++ ) {
V_6 = F_1 ( V_2 , 0x0096 , & V_31 , 1 ) ;
if ( V_6 )
goto error;
V_6 = F_1 ( V_2 , 0x00B0 , V_32 , sizeof( V_32 ) ) ;
if ( V_6 )
goto error;
if ( V_32 [ 0 ] >= 0xA7 )
break;
F_10 ( 100 ) ;
}
if ( V_30 >= F_9 ) {
F_3 ( L_6 ,
V_28 ) ;
return - V_17 ;
}
return 0 ;
error:
F_3 ( L_4 , V_28 , V_6 ) ;
return - V_17 ;
}
static int F_11 ( struct V_19 * V_20 , T_5 * V_2 )
{
T_2 V_24 ;
int V_6 ;
* V_2 = V_48 ;
V_6 = F_6 ( V_20 -> V_21 , & V_24 ) ;
if ( V_6 ) {
F_3 ( L_4 , V_28 , V_6 ) ;
return - V_17 ;
}
* V_2 = V_48
| V_49
| V_50
| V_51 ;
if ( V_24 & V_52 )
* V_2 |= V_53 ;
return 0 ;
}
static int F_12 ( struct V_19 * V_20 ,
T_1 * V_54 )
{
int V_6 ;
T_2 V_55 [ 37 ] ;
* V_54 = 0 ;
V_6 = F_1 ( V_20 -> V_21 , 0x0089 ,
V_55 , sizeof( V_55 ) ) ;
if ( V_6 ) {
F_3 ( L_4 , V_28 , V_6 ) ;
return - V_17 ;
}
* V_54 = ( V_55 [ 3 ] << 8 ) + V_55 [ 4 ] ;
if ( V_55 [ 2 ] )
* V_54 = 0xffff ;
return 0 ;
}
static int F_13 ( struct V_19 * V_20 ,
struct V_56 * V_57 )
{
int V_58 = 0 ;
switch ( V_57 -> V_59 ) {
case V_60 :
if ( V_57 -> V_61 . V_62 != V_63 )
V_58 = - V_64 ;
break;
case V_65 :
case V_66 :
case V_67 :
break;
default:
V_58 = - V_64 ;
}
return V_58 ;
}
static int F_14 ( struct V_19 * V_20 ,
struct V_68 * V_69 )
{
V_69 -> V_70 = V_71 ;
V_69 -> V_61 . V_72 . V_73 = V_74 ;
V_69 -> V_61 . V_72 . V_75 = V_76 ;
V_69 -> V_61 . V_72 . V_77 = V_76 ;
V_69 -> V_61 . V_72 . V_78 = V_79 ;
V_69 -> V_61 . V_72 . V_80 = V_81 ;
V_69 -> V_61 . V_72 . V_82 = V_83 ;
V_69 -> V_61 . V_72 . V_84 = V_85 ;
return 0 ;
}
static int F_15 ( struct V_19 * V_20 ,
struct V_68 * V_69 )
{
struct V_1 * V_2 = V_20 -> V_21 ;
int V_6 ;
F_3 ( L_7 , V_28 , V_69 -> V_86 ) ;
V_20 -> V_87 . V_88 = V_63 ;
V_6 = F_7 ( V_2 , V_69 -> V_86 ) ;
if ( V_6 ) {
F_3 ( L_4 , V_28 , V_6 ) ;
return - V_17 ;
}
return 0 ;
}
static int F_16 ( struct V_19 * V_20 )
{
int V_23 = - 1 ;
int V_6 ;
struct V_8 V_9 ;
struct V_1 * V_2 = V_20 -> V_21 ;
F_3 ( L_8 , V_28 ) ;
V_9 . V_10 = V_2 -> V_11 . V_12 ;
V_9 . V_13 = 0 ;
V_9 . V_14 = 2 ;
for ( V_23 = 0 ; V_23 < V_89 ; V_23 ++ ) {
V_9 . V_4 = V_90 [ V_23 ] ;
V_6 = F_2 ( V_2 -> V_16 , & V_9 , 1 ) ;
if ( V_6 != 1 )
goto error;
}
V_20 -> V_87 . V_88 = V_63 ;
F_10 ( 100 ) ;
return 0 ;
error:
F_3 ( L_9 , V_28 , V_23 , V_6 ) ;
return - V_17 ;
}
static void F_17 ( struct V_19 * V_20 )
{
struct V_1 * V_2 = V_20 -> V_21 ;
F_18 ( V_2 ) ;
}
struct V_19 * F_19 ( struct V_91 * V_92 )
{
struct V_1 * V_2 = NULL ;
F_20 ( L_8 , V_28 ) ;
V_2 = F_21 ( sizeof( struct V_1 ) , V_93 ) ;
if ( V_2 == NULL )
goto error;
V_2 -> V_16 = & V_92 -> V_94 ;
memcpy ( & V_2 -> V_11 , & V_95 , sizeof( V_95 ) ) ;
memcpy ( & V_2 -> V_37 . V_38 , & V_96 ,
sizeof( V_96 ) ) ;
V_2 -> V_37 . V_21 = V_2 ;
if ( F_16 ( & V_2 -> V_37 ) < 0 )
goto error;
return & V_2 -> V_37 ;
error:
F_18 ( V_2 ) ;
return NULL ;
}
