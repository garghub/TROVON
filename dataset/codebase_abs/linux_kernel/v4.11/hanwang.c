static void F_1 ( struct V_1 * V_1 )
{
unsigned char * V_2 = V_1 -> V_2 ;
struct V_3 * V_3 = V_1 -> V_4 ;
struct V_5 * V_4 = V_1 -> V_6 ;
enum V_7 type = V_1 -> V_8 -> type ;
int V_9 ;
T_1 V_10 ;
if ( type == V_11 ) {
V_1 -> V_12 = V_13 ;
V_1 -> V_14 = V_15 ;
}
switch ( V_2 [ 0 ] ) {
case 0x02 :
switch ( V_2 [ 1 ] ) {
case 0x80 :
if ( type != V_11 ) {
V_1 -> V_14 = 0 ;
F_2 ( V_3 ,
V_1 -> V_12 , 0 ) ;
}
break;
case 0x00 :
if ( type == V_11 ) {
V_1 -> V_14 = 0 ;
F_2 ( V_3 ,
V_1 -> V_12 , 0 ) ;
}
break;
case 0xc2 :
switch ( V_2 [ 3 ] & 0xf0 ) {
case 0x20 :
case 0x30 :
V_1 -> V_14 = V_15 ;
V_1 -> V_12 = V_13 ;
F_2 ( V_3 , V_13 , 1 ) ;
break;
case 0xa0 :
case 0xb0 :
V_1 -> V_14 = V_16 ;
V_1 -> V_12 = V_17 ;
F_2 ( V_3 , V_17 , 1 ) ;
break;
default:
V_1 -> V_14 = 0 ;
F_3 ( & V_4 -> V_4 ,
L_1 , V_2 [ 0 ] ) ;
break;
}
break;
default:
switch ( type ) {
case V_18 :
V_10 = ( V_2 [ 6 ] << 3 ) |
( ( V_2 [ 7 ] & 0xc0 ) >> 5 ) |
( V_2 [ 1 ] & 0x01 ) ;
break;
case V_19 :
case V_11 :
V_10 = ( V_2 [ 7 ] >> 6 ) | ( V_2 [ 6 ] << 2 ) ;
break;
default:
V_10 = 0 ;
break;
}
F_4 ( V_3 , V_20 ,
F_5 ( ( V_21 * ) & V_2 [ 2 ] ) ) ;
F_4 ( V_3 , V_22 ,
F_5 ( ( V_21 * ) & V_2 [ 4 ] ) ) ;
F_4 ( V_3 , V_23 , V_10 ) ;
F_4 ( V_3 , V_24 , V_2 [ 7 ] & 0x3f ) ;
F_4 ( V_3 , V_25 , V_2 [ 8 ] & 0x7f ) ;
F_2 ( V_3 , V_26 , V_2 [ 1 ] & 0x02 ) ;
if ( type != V_11 )
F_2 ( V_3 , V_27 ,
V_2 [ 1 ] & 0x04 ) ;
else
F_2 ( V_3 , V_13 , 1 ) ;
break;
}
F_4 ( V_3 , V_28 , V_1 -> V_14 ) ;
F_6 ( V_3 , V_29 , V_30 ,
V_1 -> V_8 -> V_31 ) ;
break;
case 0x0c :
V_1 -> V_14 = V_32 ;
switch ( type ) {
case V_18 :
F_2 ( V_3 , V_33 ,
V_2 [ 1 ] || V_2 [ 2 ] || V_2 [ 3 ] ) ;
F_4 ( V_3 , V_34 , V_2 [ 1 ] ) ;
F_2 ( V_3 , V_35 , V_2 [ 2 ] ) ;
for ( V_9 = 0 ; V_9 < 8 ; V_9 ++ )
F_2 ( V_3 ,
V_36 + V_9 , V_2 [ 3 ] & ( 1 << V_9 ) ) ;
break;
case V_19 :
F_2 ( V_3 , V_33 , V_2 [ 1 ] ||
V_2 [ 2 ] || V_2 [ 3 ] || V_2 [ 4 ] ||
V_2 [ 5 ] || V_2 [ 6 ] ) ;
F_4 ( V_3 , V_37 ,
( ( V_2 [ 1 ] & 0x1f ) << 8 ) | V_2 [ 2 ] ) ;
F_4 ( V_3 , V_38 ,
( ( V_2 [ 3 ] & 0x1f ) << 8 ) | V_2 [ 4 ] ) ;
F_2 ( V_3 , V_35 , V_2 [ 5 ] & 0x01 ) ;
for ( V_9 = 0 ; V_9 < 4 ; V_9 ++ ) {
F_2 ( V_3 ,
V_36 + V_9 , V_2 [ 5 ] & ( 1 << V_9 ) ) ;
F_2 ( V_3 ,
V_39 + V_9 , V_2 [ 6 ] & ( 1 << V_9 ) ) ;
}
break;
case V_11 :
F_3 ( & V_4 -> V_4 , L_2 , V_2 [ 0 ] ) ;
return;
}
F_4 ( V_3 , V_28 , V_1 -> V_14 ) ;
F_6 ( V_3 , V_29 , V_30 , 0xffffffff ) ;
break;
default:
F_3 ( & V_4 -> V_4 , L_2 , V_2 [ 0 ] ) ;
break;
}
F_7 ( V_3 ) ;
}
static void F_8 ( struct V_40 * V_40 )
{
struct V_1 * V_1 = V_40 -> V_41 ;
struct V_5 * V_4 = V_1 -> V_6 ;
int V_42 ;
switch ( V_40 -> V_43 ) {
case 0 :
;
F_1 ( V_1 ) ;
break;
case - V_44 :
case - V_45 :
case - V_46 :
F_9 ( & V_4 -> V_4 , L_3 ,
V_47 , V_40 -> V_43 ) ;
return;
default:
F_9 ( & V_4 -> V_4 , L_4 ,
V_47 , V_40 -> V_43 ) ;
break;
}
V_42 = F_10 ( V_40 , V_48 ) ;
if ( V_42 )
F_9 ( & V_4 -> V_4 , L_5 ,
V_47 , V_42 ) ;
}
static int F_11 ( struct V_3 * V_4 )
{
struct V_1 * V_1 = F_12 ( V_4 ) ;
V_1 -> V_49 -> V_4 = V_1 -> V_6 ;
if ( F_10 ( V_1 -> V_49 , V_50 ) )
return - V_51 ;
return 0 ;
}
static void F_13 ( struct V_3 * V_4 )
{
struct V_1 * V_1 = F_12 ( V_4 ) ;
F_14 ( V_1 -> V_49 ) ;
}
static bool F_15 ( struct V_5 * V_4 , struct V_1 * V_1 )
{
int V_9 ;
for ( V_9 = 0 ; V_9 < F_16 ( V_52 ) ; V_9 ++ ) {
if ( F_17 ( V_4 -> V_53 . V_54 ) ==
V_52 [ V_9 ] . V_31 ) {
V_1 -> V_8 = & V_52 [ V_9 ] ;
return true ;
}
}
return false ;
}
static int F_18 ( struct V_55 * V_56 , const struct V_57 * V_58 )
{
struct V_5 * V_4 = F_19 ( V_56 ) ;
struct V_59 * V_60 ;
struct V_1 * V_1 ;
struct V_3 * V_3 ;
int error ;
int V_9 ;
if ( V_56 -> V_61 -> V_62 . V_63 < 1 )
return - V_64 ;
V_1 = F_20 ( sizeof( struct V_1 ) , V_50 ) ;
V_3 = F_21 () ;
if ( ! V_1 || ! V_3 ) {
error = - V_65 ;
goto V_66;
}
if ( ! F_15 ( V_4 , V_1 ) ) {
error = - V_67 ;
goto V_66;
}
V_1 -> V_2 = F_22 ( V_4 , V_1 -> V_8 -> V_68 ,
V_50 , & V_1 -> V_69 ) ;
if ( ! V_1 -> V_2 ) {
error = - V_65 ;
goto V_66;
}
V_1 -> V_49 = F_23 ( 0 , V_50 ) ;
if ( ! V_1 -> V_49 ) {
error = - V_65 ;
goto V_70;
}
V_1 -> V_6 = V_4 ;
V_1 -> V_4 = V_3 ;
F_24 ( V_4 , V_1 -> V_71 , sizeof( V_1 -> V_71 ) ) ;
F_25 ( V_1 -> V_71 , L_6 , sizeof( V_1 -> V_71 ) ) ;
F_26 ( V_1 -> V_72 , V_1 -> V_8 -> V_72 , sizeof( V_1 -> V_72 ) ) ;
V_3 -> V_72 = V_1 -> V_72 ;
V_3 -> V_71 = V_1 -> V_71 ;
F_27 ( V_4 , & V_3 -> V_58 ) ;
V_3 -> V_4 . V_73 = & V_56 -> V_4 ;
F_28 ( V_3 , V_1 ) ;
V_3 -> V_74 = F_11 ;
V_3 -> V_75 = F_13 ;
for ( V_9 = 0 ; V_9 < F_16 ( V_76 ) ; ++ V_9 )
F_29 ( V_76 [ V_9 ] , V_3 -> V_77 ) ;
for ( V_9 = 0 ; V_9 < F_16 ( V_78 ) ; ++ V_9 )
F_29 ( V_78 [ V_9 ] , V_3 -> V_79 ) ;
for ( V_9 = 0 ; V_9 < F_16 ( V_80 ) ; ++ V_9 )
F_29 ( V_80 [ V_9 ] , V_3 -> V_81 ) ;
for ( V_9 = 0 ; V_9 < F_16 ( V_82 ) ; ++ V_9 )
F_29 ( V_82 [ V_9 ] , V_3 -> V_83 ) ;
F_30 ( V_3 , V_20 ,
0 , V_1 -> V_8 -> V_84 , 4 , 0 ) ;
F_30 ( V_3 , V_22 ,
0 , V_1 -> V_8 -> V_85 , 4 , 0 ) ;
F_30 ( V_3 , V_24 ,
0 , V_1 -> V_8 -> V_86 , 0 , 0 ) ;
F_30 ( V_3 , V_25 ,
0 , V_1 -> V_8 -> V_87 , 0 , 0 ) ;
F_30 ( V_3 , V_23 ,
0 , V_1 -> V_8 -> V_88 , 0 , 0 ) ;
V_60 = & V_56 -> V_61 -> V_60 [ 0 ] . V_62 ;
F_31 ( V_1 -> V_49 , V_4 ,
F_32 ( V_4 , V_60 -> V_89 ) ,
V_1 -> V_2 , V_1 -> V_8 -> V_68 ,
F_8 , V_1 , V_60 -> V_90 ) ;
V_1 -> V_49 -> V_91 = V_1 -> V_69 ;
V_1 -> V_49 -> V_92 |= V_93 ;
error = F_33 ( V_1 -> V_4 ) ;
if ( error )
goto V_94;
F_34 ( V_56 , V_1 ) ;
return 0 ;
V_94: F_35 ( V_1 -> V_49 ) ;
V_70: F_36 ( V_4 , V_1 -> V_8 -> V_68 ,
V_1 -> V_2 , V_1 -> V_69 ) ;
V_66: F_37 ( V_3 ) ;
F_38 ( V_1 ) ;
return error ;
}
static void F_39 ( struct V_55 * V_56 )
{
struct V_1 * V_1 = F_40 ( V_56 ) ;
F_41 ( V_1 -> V_4 ) ;
F_35 ( V_1 -> V_49 ) ;
F_36 ( F_19 ( V_56 ) ,
V_1 -> V_8 -> V_68 , V_1 -> V_2 ,
V_1 -> V_69 ) ;
F_38 ( V_1 ) ;
F_34 ( V_56 , NULL ) ;
}
