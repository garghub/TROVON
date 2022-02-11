static void F_1 ( struct V_1 * V_1 )
{
unsigned char * V_2 = V_1 -> V_2 ;
struct V_3 * V_3 = V_1 -> V_4 ;
struct V_5 * V_4 = V_1 -> V_6 ;
enum V_7 type = V_1 -> V_8 -> type ;
int V_9 ;
T_1 V_10 , V_11 , V_12 ;
switch ( V_2 [ 0 ] ) {
case 0x02 :
switch ( V_2 [ 1 ] ) {
case 0x80 :
V_1 -> V_13 = 0 ;
F_2 ( V_3 , V_1 -> V_14 , 0 ) ;
break;
case 0xc2 :
switch ( V_2 [ 3 ] & 0xf0 ) {
case 0x20 :
case 0x30 :
V_1 -> V_13 = V_15 ;
V_1 -> V_14 = V_16 ;
F_2 ( V_3 , V_16 , 1 ) ;
break;
case 0xa0 :
case 0xb0 :
V_1 -> V_13 = V_17 ;
V_1 -> V_14 = V_18 ;
F_2 ( V_3 , V_18 , 1 ) ;
break;
default:
V_1 -> V_13 = 0 ;
F_3 ( & V_4 -> V_4 ,
L_1 , V_2 [ 0 ] ) ;
break;
}
break;
default:
V_10 = ( V_2 [ 2 ] << 8 ) | V_2 [ 3 ] ;
V_11 = ( V_2 [ 4 ] << 8 ) | V_2 [ 5 ] ;
switch ( type ) {
case V_19 :
V_12 = ( V_2 [ 6 ] << 3 ) |
( ( V_2 [ 7 ] & 0xc0 ) >> 5 ) |
( V_2 [ 1 ] & 0x01 ) ;
break;
case V_20 :
V_12 = ( V_2 [ 7 ] >> 6 ) | ( V_2 [ 6 ] << 2 ) ;
break;
default:
V_12 = 0 ;
break;
}
F_4 ( V_3 , V_21 ,
F_5 ( ( V_22 * ) & V_10 ) ) ;
F_4 ( V_3 , V_23 ,
F_5 ( ( V_22 * ) & V_11 ) ) ;
F_4 ( V_3 , V_24 ,
F_5 ( ( V_22 * ) & V_12 ) ) ;
F_4 ( V_3 , V_25 , V_2 [ 7 ] & 0x3f ) ;
F_4 ( V_3 , V_26 , V_2 [ 8 ] & 0x7f ) ;
F_2 ( V_3 , V_27 , V_2 [ 1 ] & 0x02 ) ;
F_2 ( V_3 , V_28 , V_2 [ 1 ] & 0x04 ) ;
break;
}
F_4 ( V_3 , V_29 , V_1 -> V_13 ) ;
F_6 ( V_3 , V_30 , V_31 ,
V_1 -> V_8 -> V_32 ) ;
break;
case 0x0c :
V_1 -> V_13 = V_33 ;
switch ( type ) {
case V_19 :
F_2 ( V_3 , V_34 , V_2 [ 1 ] ||
V_2 [ 2 ] || V_2 [ 3 ] ) ;
F_4 ( V_3 , V_35 , V_2 [ 1 ] ) ;
F_2 ( V_3 , V_36 , V_2 [ 2 ] ) ;
for ( V_9 = 0 ; V_9 < 8 ; V_9 ++ )
F_2 ( V_3 ,
V_37 + V_9 , V_2 [ 3 ] & ( 1 << V_9 ) ) ;
break;
case V_20 :
F_2 ( V_3 , V_34 , V_2 [ 1 ] ||
V_2 [ 2 ] || V_2 [ 3 ] || V_2 [ 4 ] ||
V_2 [ 5 ] || V_2 [ 6 ] ) ;
F_4 ( V_3 , V_38 ,
( ( V_2 [ 1 ] & 0x1f ) << 8 ) | V_2 [ 2 ] ) ;
F_4 ( V_3 , V_39 ,
( ( V_2 [ 3 ] & 0x1f ) << 8 ) | V_2 [ 4 ] ) ;
F_2 ( V_3 , V_36 , V_2 [ 5 ] & 0x01 ) ;
for ( V_9 = 0 ; V_9 < 4 ; V_9 ++ ) {
F_2 ( V_3 ,
V_37 + V_9 , V_2 [ 5 ] & ( 1 << V_9 ) ) ;
F_2 ( V_3 ,
V_40 + V_9 , V_2 [ 6 ] & ( 1 << V_9 ) ) ;
}
break;
}
F_4 ( V_3 , V_29 , V_1 -> V_13 ) ;
F_6 ( V_3 , V_30 , V_31 , 0xffffffff ) ;
break;
default:
F_3 ( & V_4 -> V_4 , L_2 , V_2 [ 0 ] ) ;
break;
}
F_7 ( V_3 ) ;
}
static void F_8 ( struct V_41 * V_41 )
{
struct V_1 * V_1 = V_41 -> V_42 ;
struct V_5 * V_4 = V_1 -> V_6 ;
int V_43 ;
switch ( V_41 -> V_44 ) {
case 0 :
;
F_1 ( V_1 ) ;
break;
case - V_45 :
case - V_46 :
case - V_47 :
F_9 ( & V_4 -> V_4 , L_3 ,
V_48 , V_41 -> V_44 ) ;
return;
default:
F_9 ( & V_4 -> V_4 , L_4 ,
V_48 , V_41 -> V_44 ) ;
break;
}
V_43 = F_10 ( V_41 , V_49 ) ;
if ( V_43 )
F_9 ( & V_4 -> V_4 , L_5 ,
V_48 , V_43 ) ;
}
static int F_11 ( struct V_3 * V_4 )
{
struct V_1 * V_1 = F_12 ( V_4 ) ;
V_1 -> V_50 -> V_4 = V_1 -> V_6 ;
if ( F_10 ( V_1 -> V_50 , V_51 ) )
return - V_52 ;
return 0 ;
}
static void F_13 ( struct V_3 * V_4 )
{
struct V_1 * V_1 = F_12 ( V_4 ) ;
F_14 ( V_1 -> V_50 ) ;
}
static bool F_15 ( struct V_5 * V_4 , struct V_1 * V_1 )
{
int V_9 ;
for ( V_9 = 0 ; V_9 < F_16 ( V_53 ) ; V_9 ++ ) {
if ( F_17 ( V_4 -> V_54 . V_55 ) ==
V_53 [ V_9 ] . V_32 ) {
V_1 -> V_8 = & V_53 [ V_9 ] ;
return true ;
}
}
return false ;
}
static int F_18 ( struct V_56 * V_57 , const struct V_58 * V_59 )
{
struct V_5 * V_4 = F_19 ( V_57 ) ;
struct V_60 * V_61 ;
struct V_1 * V_1 ;
struct V_3 * V_3 ;
int error ;
int V_9 ;
V_1 = F_20 ( sizeof( struct V_1 ) , V_51 ) ;
V_3 = F_21 () ;
if ( ! V_1 || ! V_3 ) {
error = - V_62 ;
goto V_63;
}
if ( ! F_15 ( V_4 , V_1 ) ) {
error = - V_64 ;
goto V_63;
}
V_1 -> V_2 = F_22 ( V_4 , V_1 -> V_8 -> V_65 ,
V_51 , & V_1 -> V_66 ) ;
if ( ! V_1 -> V_2 ) {
error = - V_62 ;
goto V_63;
}
V_1 -> V_50 = F_23 ( 0 , V_51 ) ;
if ( ! V_1 -> V_50 ) {
error = - V_62 ;
goto V_67;
}
V_1 -> V_6 = V_4 ;
V_1 -> V_4 = V_3 ;
F_24 ( V_4 , V_1 -> V_68 , sizeof( V_1 -> V_68 ) ) ;
F_25 ( V_1 -> V_68 , L_6 , sizeof( V_1 -> V_68 ) ) ;
F_26 ( V_1 -> V_69 , V_1 -> V_8 -> V_69 , sizeof( V_1 -> V_69 ) ) ;
V_3 -> V_69 = V_1 -> V_69 ;
V_3 -> V_68 = V_1 -> V_68 ;
F_27 ( V_4 , & V_3 -> V_59 ) ;
V_3 -> V_4 . V_70 = & V_57 -> V_4 ;
F_28 ( V_3 , V_1 ) ;
V_3 -> V_71 = F_11 ;
V_3 -> V_72 = F_13 ;
for ( V_9 = 0 ; V_9 < F_16 ( V_73 ) ; ++ V_9 )
F_29 ( V_73 [ V_9 ] , V_3 -> V_74 ) ;
for ( V_9 = 0 ; V_9 < F_16 ( V_75 ) ; ++ V_9 )
F_29 ( V_75 [ V_9 ] , V_3 -> V_76 ) ;
for ( V_9 = 0 ; V_9 < F_16 ( V_77 ) ; ++ V_9 )
F_29 ( V_77 [ V_9 ] , V_3 -> V_78 ) ;
for ( V_9 = 0 ; V_9 < F_16 ( V_79 ) ; ++ V_9 )
F_29 ( V_79 [ V_9 ] , V_3 -> V_80 ) ;
F_30 ( V_3 , V_21 ,
0 , V_1 -> V_8 -> V_81 , 4 , 0 ) ;
F_30 ( V_3 , V_23 ,
0 , V_1 -> V_8 -> V_82 , 4 , 0 ) ;
F_30 ( V_3 , V_25 ,
0 , V_1 -> V_8 -> V_83 , 0 , 0 ) ;
F_30 ( V_3 , V_26 ,
0 , V_1 -> V_8 -> V_84 , 0 , 0 ) ;
F_30 ( V_3 , V_24 ,
0 , V_1 -> V_8 -> V_85 , 0 , 0 ) ;
V_61 = & V_57 -> V_86 -> V_61 [ 0 ] . V_87 ;
F_31 ( V_1 -> V_50 , V_4 ,
F_32 ( V_4 , V_61 -> V_88 ) ,
V_1 -> V_2 , V_1 -> V_8 -> V_65 ,
F_8 , V_1 , V_61 -> V_89 ) ;
V_1 -> V_50 -> V_90 = V_1 -> V_66 ;
V_1 -> V_50 -> V_91 |= V_92 ;
error = F_33 ( V_1 -> V_4 ) ;
if ( error )
goto V_93;
F_34 ( V_57 , V_1 ) ;
return 0 ;
V_93: F_35 ( V_1 -> V_50 ) ;
V_67: F_36 ( V_4 , V_1 -> V_8 -> V_65 ,
V_1 -> V_2 , V_1 -> V_66 ) ;
V_63: F_37 ( V_3 ) ;
F_38 ( V_1 ) ;
return error ;
}
static void F_39 ( struct V_56 * V_57 )
{
struct V_1 * V_1 = F_40 ( V_57 ) ;
F_41 ( V_1 -> V_4 ) ;
F_35 ( V_1 -> V_50 ) ;
F_36 ( F_19 ( V_57 ) ,
V_1 -> V_8 -> V_65 , V_1 -> V_2 ,
V_1 -> V_66 ) ;
F_38 ( V_1 ) ;
F_34 ( V_57 , NULL ) ;
}
