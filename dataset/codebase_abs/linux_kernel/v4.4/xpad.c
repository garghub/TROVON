static void F_1 ( struct V_1 * V_2 , T_1 V_3 , unsigned char * V_4 )
{
struct V_5 * V_6 = V_2 -> V_6 ;
if ( ! ( V_2 -> V_7 & V_8 ) ) {
F_2 ( V_6 , V_9 ,
( V_10 ) F_3 ( ( V_11 * ) ( V_4 + 12 ) ) ) ;
F_2 ( V_6 , V_12 ,
~ ( V_10 ) F_3 ( ( V_11 * ) ( V_4 + 14 ) ) ) ;
F_2 ( V_6 , V_13 ,
( V_10 ) F_3 ( ( V_11 * ) ( V_4 + 16 ) ) ) ;
F_2 ( V_6 , V_14 ,
~ ( V_10 ) F_3 ( ( V_11 * ) ( V_4 + 18 ) ) ) ;
}
if ( V_2 -> V_7 & V_15 ) {
F_4 ( V_6 , V_16 , V_4 [ 10 ] ) ;
F_4 ( V_6 , V_17 , V_4 [ 11 ] ) ;
} else {
F_2 ( V_6 , V_18 , V_4 [ 10 ] ) ;
F_2 ( V_6 , V_19 , V_4 [ 11 ] ) ;
}
if ( V_2 -> V_7 & V_20 ) {
F_4 ( V_6 , V_21 , V_4 [ 2 ] & 0x04 ) ;
F_4 ( V_6 , V_22 , V_4 [ 2 ] & 0x08 ) ;
F_4 ( V_6 , V_23 , V_4 [ 2 ] & 0x01 ) ;
F_4 ( V_6 , V_24 , V_4 [ 2 ] & 0x02 ) ;
} else {
F_2 ( V_6 , V_25 ,
! ! ( V_4 [ 2 ] & 0x08 ) - ! ! ( V_4 [ 2 ] & 0x04 ) ) ;
F_2 ( V_6 , V_26 ,
! ! ( V_4 [ 2 ] & 0x02 ) - ! ! ( V_4 [ 2 ] & 0x01 ) ) ;
}
F_4 ( V_6 , V_27 , V_4 [ 2 ] & 0x10 ) ;
F_4 ( V_6 , V_28 , V_4 [ 2 ] & 0x20 ) ;
F_4 ( V_6 , V_29 , V_4 [ 2 ] & 0x40 ) ;
F_4 ( V_6 , V_30 , V_4 [ 2 ] & 0x80 ) ;
F_4 ( V_6 , V_31 , V_4 [ 4 ] ) ;
F_4 ( V_6 , V_32 , V_4 [ 5 ] ) ;
F_4 ( V_6 , V_33 , V_4 [ 6 ] ) ;
F_4 ( V_6 , V_34 , V_4 [ 7 ] ) ;
F_4 ( V_6 , V_35 , V_4 [ 8 ] ) ;
F_4 ( V_6 , V_36 , V_4 [ 9 ] ) ;
F_5 ( V_6 ) ;
}
static void F_6 ( struct V_1 * V_2 ,
T_1 V_3 , unsigned char * V_4 )
{
struct V_5 * V_6 = V_2 -> V_6 ;
if ( V_2 -> V_7 & V_20 ) {
F_4 ( V_6 , V_21 , V_4 [ 2 ] & 0x04 ) ;
F_4 ( V_6 , V_22 , V_4 [ 2 ] & 0x08 ) ;
F_4 ( V_6 , V_23 , V_4 [ 2 ] & 0x01 ) ;
F_4 ( V_6 , V_24 , V_4 [ 2 ] & 0x02 ) ;
}
if ( ! ( V_2 -> V_7 & V_20 ) ||
V_2 -> V_37 == V_38 ) {
F_2 ( V_6 , V_25 ,
! ! ( V_4 [ 2 ] & 0x08 ) - ! ! ( V_4 [ 2 ] & 0x04 ) ) ;
F_2 ( V_6 , V_26 ,
! ! ( V_4 [ 2 ] & 0x02 ) - ! ! ( V_4 [ 2 ] & 0x01 ) ) ;
}
F_4 ( V_6 , V_27 , V_4 [ 2 ] & 0x10 ) ;
F_4 ( V_6 , V_28 , V_4 [ 2 ] & 0x20 ) ;
F_4 ( V_6 , V_29 , V_4 [ 2 ] & 0x40 ) ;
F_4 ( V_6 , V_30 , V_4 [ 2 ] & 0x80 ) ;
F_4 ( V_6 , V_31 , V_4 [ 3 ] & 0x10 ) ;
F_4 ( V_6 , V_32 , V_4 [ 3 ] & 0x20 ) ;
F_4 ( V_6 , V_33 , V_4 [ 3 ] & 0x40 ) ;
F_4 ( V_6 , V_34 , V_4 [ 3 ] & 0x80 ) ;
F_4 ( V_6 , V_39 , V_4 [ 3 ] & 0x01 ) ;
F_4 ( V_6 , V_40 , V_4 [ 3 ] & 0x02 ) ;
F_4 ( V_6 , V_41 , V_4 [ 3 ] & 0x04 ) ;
if ( ! ( V_2 -> V_7 & V_8 ) ) {
F_2 ( V_6 , V_9 ,
( V_10 ) F_3 ( ( V_11 * ) ( V_4 + 6 ) ) ) ;
F_2 ( V_6 , V_12 ,
~ ( V_10 ) F_3 ( ( V_11 * ) ( V_4 + 8 ) ) ) ;
F_2 ( V_6 , V_13 ,
( V_10 ) F_3 ( ( V_11 * ) ( V_4 + 10 ) ) ) ;
F_2 ( V_6 , V_14 ,
~ ( V_10 ) F_3 ( ( V_11 * ) ( V_4 + 12 ) ) ) ;
}
if ( V_2 -> V_7 & V_15 ) {
F_4 ( V_6 , V_16 , V_4 [ 4 ] ) ;
F_4 ( V_6 , V_17 , V_4 [ 5 ] ) ;
} else {
F_2 ( V_6 , V_18 , V_4 [ 4 ] ) ;
F_2 ( V_6 , V_19 , V_4 [ 5 ] ) ;
}
F_5 ( V_6 ) ;
}
static void F_7 ( struct V_1 * V_2 , T_1 V_3 , unsigned char * V_4 )
{
if ( V_4 [ 0 ] & 0x08 ) {
if ( V_4 [ 1 ] & 0x80 ) {
V_2 -> V_42 = 1 ;
F_8 ( V_2 ) ;
} else
V_2 -> V_42 = 0 ;
}
if ( ! ( V_4 [ 1 ] & 0x1 ) )
return;
F_6 ( V_2 , V_3 , & V_4 [ 4 ] ) ;
}
static void F_9 ( struct V_1 * V_2 ,
struct V_5 * V_6 ,
unsigned char * V_4 )
{
F_4 ( V_6 , V_27 , V_4 [ 4 ] & 0x04 ) ;
F_4 ( V_6 , V_28 , V_4 [ 4 ] & 0x08 ) ;
F_4 ( V_6 , V_31 , V_4 [ 4 ] & 0x10 ) ;
F_4 ( V_6 , V_32 , V_4 [ 4 ] & 0x20 ) ;
F_4 ( V_6 , V_33 , V_4 [ 4 ] & 0x40 ) ;
F_4 ( V_6 , V_34 , V_4 [ 4 ] & 0x80 ) ;
if ( V_2 -> V_7 & V_20 ) {
F_4 ( V_6 , V_21 , V_4 [ 5 ] & 0x04 ) ;
F_4 ( V_6 , V_22 , V_4 [ 5 ] & 0x08 ) ;
F_4 ( V_6 , V_23 , V_4 [ 5 ] & 0x01 ) ;
F_4 ( V_6 , V_24 , V_4 [ 5 ] & 0x02 ) ;
} else {
F_2 ( V_6 , V_25 ,
! ! ( V_4 [ 5 ] & 0x08 ) - ! ! ( V_4 [ 5 ] & 0x04 ) ) ;
F_2 ( V_6 , V_26 ,
! ! ( V_4 [ 5 ] & 0x02 ) - ! ! ( V_4 [ 5 ] & 0x01 ) ) ;
}
F_4 ( V_6 , V_39 , V_4 [ 5 ] & 0x10 ) ;
F_4 ( V_6 , V_40 , V_4 [ 5 ] & 0x20 ) ;
F_4 ( V_6 , V_29 , V_4 [ 5 ] & 0x40 ) ;
F_4 ( V_6 , V_30 , V_4 [ 5 ] & 0x80 ) ;
if ( ! ( V_2 -> V_7 & V_8 ) ) {
F_2 ( V_6 , V_9 ,
( V_10 ) F_3 ( ( V_11 * ) ( V_4 + 10 ) ) ) ;
F_2 ( V_6 , V_12 ,
~ ( V_10 ) F_3 ( ( V_11 * ) ( V_4 + 12 ) ) ) ;
F_2 ( V_6 , V_13 ,
( V_10 ) F_3 ( ( V_11 * ) ( V_4 + 14 ) ) ) ;
F_2 ( V_6 , V_14 ,
~ ( V_10 ) F_3 ( ( V_11 * ) ( V_4 + 16 ) ) ) ;
}
if ( V_2 -> V_7 & V_15 ) {
F_4 ( V_6 , V_16 ,
( V_43 ) F_3 ( ( V_11 * ) ( V_4 + 6 ) ) ) ;
F_4 ( V_6 , V_17 ,
( V_43 ) F_3 ( ( V_11 * ) ( V_4 + 8 ) ) ) ;
} else {
F_2 ( V_6 , V_18 ,
( V_43 ) F_3 ( ( V_11 * ) ( V_4 + 6 ) ) ) ;
F_2 ( V_6 , V_19 ,
( V_43 ) F_3 ( ( V_11 * ) ( V_4 + 8 ) ) ) ;
}
F_5 ( V_6 ) ;
}
static void F_10 ( struct V_1 * V_2 ,
T_1 V_3 , unsigned char * V_4 )
{
struct V_5 * V_6 = V_2 -> V_6 ;
switch ( V_4 [ 0 ] ) {
case 0x20 :
F_9 ( V_2 , V_6 , V_4 ) ;
break;
case 0x07 :
F_4 ( V_6 , V_41 , V_4 [ 4 ] & 0x01 ) ;
F_5 ( V_6 ) ;
break;
}
}
static void F_11 ( struct V_44 * V_44 )
{
struct V_1 * V_2 = V_44 -> V_45 ;
struct V_46 * V_6 = & V_2 -> V_47 -> V_6 ;
int V_48 , V_49 ;
V_49 = V_44 -> V_49 ;
switch ( V_49 ) {
case 0 :
break;
case - V_50 :
case - V_51 :
case - V_52 :
F_12 ( V_6 , L_1 ,
V_53 , V_49 ) ;
return;
default:
F_12 ( V_6 , L_2 ,
V_53 , V_49 ) ;
goto exit;
}
switch ( V_2 -> V_37 ) {
case V_54 :
F_6 ( V_2 , 0 , V_2 -> V_55 ) ;
break;
case V_38 :
F_7 ( V_2 , 0 , V_2 -> V_55 ) ;
break;
case V_56 :
F_10 ( V_2 , 0 , V_2 -> V_55 ) ;
break;
default:
F_1 ( V_2 , 0 , V_2 -> V_55 ) ;
}
exit:
V_48 = F_13 ( V_44 , V_57 ) ;
if ( V_48 )
F_14 ( V_6 , L_3 ,
V_53 , V_48 ) ;
}
static void F_15 ( struct V_44 * V_44 )
{
struct V_1 * V_2 = V_44 -> V_45 ;
struct V_46 * V_6 = & V_2 -> V_47 -> V_6 ;
int V_48 , V_49 ;
V_49 = V_44 -> V_49 ;
switch ( V_49 ) {
case 0 :
return;
case - V_50 :
case - V_51 :
case - V_52 :
F_12 ( V_6 , L_1 ,
V_53 , V_49 ) ;
return;
default:
F_12 ( V_6 , L_2 ,
V_53 , V_49 ) ;
goto exit;
}
exit:
V_48 = F_13 ( V_44 , V_57 ) ;
if ( V_48 )
F_14 ( V_6 , L_3 ,
V_53 , V_48 ) ;
}
static int F_16 ( struct V_58 * V_47 , struct V_1 * V_2 )
{
struct V_59 * V_60 ;
int V_61 ;
int error ;
if ( V_2 -> V_37 == V_62 )
return 0 ;
V_2 -> V_63 = F_17 ( V_2 -> V_64 , V_65 ,
V_66 , & V_2 -> V_67 ) ;
if ( ! V_2 -> V_63 ) {
error = - V_68 ;
goto V_69;
}
F_18 ( & V_2 -> V_70 ) ;
V_2 -> V_71 = F_19 ( 0 , V_66 ) ;
if ( ! V_2 -> V_71 ) {
error = - V_68 ;
goto V_72;
}
V_61 = V_2 -> V_37 == V_56 ? 0 : 1 ;
V_60 = & V_47 -> V_73 -> V_74 [ V_61 ] . V_75 ;
F_20 ( V_2 -> V_71 , V_2 -> V_64 ,
F_21 ( V_2 -> V_64 , V_60 -> V_76 ) ,
V_2 -> V_63 , V_65 ,
F_15 , V_2 , V_60 -> V_77 ) ;
V_2 -> V_71 -> V_78 = V_2 -> V_67 ;
V_2 -> V_71 -> V_79 |= V_80 ;
return 0 ;
V_72: F_22 ( V_2 -> V_64 , V_65 , V_2 -> V_63 , V_2 -> V_67 ) ;
V_69: return error ;
}
static void F_23 ( struct V_1 * V_2 )
{
if ( V_2 -> V_37 != V_62 )
F_24 ( V_2 -> V_71 ) ;
}
static void F_25 ( struct V_1 * V_2 )
{
if ( V_2 -> V_37 != V_62 ) {
F_26 ( V_2 -> V_71 ) ;
F_22 ( V_2 -> V_64 , V_65 ,
V_2 -> V_63 , V_2 -> V_67 ) ;
}
}
static int F_27 ( struct V_1 * V_2 )
{
int V_48 ;
F_28 ( & V_2 -> V_70 ) ;
V_2 -> V_63 [ 0 ] = 0x08 ;
V_2 -> V_63 [ 1 ] = 0x00 ;
V_2 -> V_63 [ 2 ] = 0x0F ;
V_2 -> V_63 [ 3 ] = 0xC0 ;
V_2 -> V_63 [ 4 ] = 0x00 ;
V_2 -> V_63 [ 5 ] = 0x00 ;
V_2 -> V_63 [ 6 ] = 0x00 ;
V_2 -> V_63 [ 7 ] = 0x00 ;
V_2 -> V_63 [ 8 ] = 0x00 ;
V_2 -> V_63 [ 9 ] = 0x00 ;
V_2 -> V_63 [ 10 ] = 0x00 ;
V_2 -> V_63 [ 11 ] = 0x00 ;
V_2 -> V_71 -> V_81 = 12 ;
V_48 = F_13 ( V_2 -> V_71 , V_66 ) ;
F_29 ( & V_2 -> V_70 ) ;
return V_48 ;
}
static int F_30 ( struct V_5 * V_6 , void * V_4 , struct V_82 * V_83 )
{
struct V_1 * V_2 = F_31 ( V_6 ) ;
V_43 V_84 ;
V_43 V_85 ;
if ( V_83 -> type != V_86 )
return 0 ;
V_84 = V_83 -> V_87 . V_88 . V_89 ;
V_85 = V_83 -> V_87 . V_88 . V_90 ;
switch ( V_2 -> V_37 ) {
case V_91 :
V_2 -> V_63 [ 0 ] = 0x00 ;
V_2 -> V_63 [ 1 ] = 0x06 ;
V_2 -> V_63 [ 2 ] = 0x00 ;
V_2 -> V_63 [ 3 ] = V_84 / 256 ;
V_2 -> V_63 [ 4 ] = 0x00 ;
V_2 -> V_63 [ 5 ] = V_85 / 256 ;
V_2 -> V_71 -> V_81 = 6 ;
break;
case V_54 :
V_2 -> V_63 [ 0 ] = 0x00 ;
V_2 -> V_63 [ 1 ] = 0x08 ;
V_2 -> V_63 [ 2 ] = 0x00 ;
V_2 -> V_63 [ 3 ] = V_84 / 256 ;
V_2 -> V_63 [ 4 ] = V_85 / 256 ;
V_2 -> V_63 [ 5 ] = 0x00 ;
V_2 -> V_63 [ 6 ] = 0x00 ;
V_2 -> V_63 [ 7 ] = 0x00 ;
V_2 -> V_71 -> V_81 = 8 ;
break;
case V_38 :
V_2 -> V_63 [ 0 ] = 0x00 ;
V_2 -> V_63 [ 1 ] = 0x01 ;
V_2 -> V_63 [ 2 ] = 0x0F ;
V_2 -> V_63 [ 3 ] = 0xC0 ;
V_2 -> V_63 [ 4 ] = 0x00 ;
V_2 -> V_63 [ 5 ] = V_84 / 256 ;
V_2 -> V_63 [ 6 ] = V_85 / 256 ;
V_2 -> V_63 [ 7 ] = 0x00 ;
V_2 -> V_63 [ 8 ] = 0x00 ;
V_2 -> V_63 [ 9 ] = 0x00 ;
V_2 -> V_63 [ 10 ] = 0x00 ;
V_2 -> V_63 [ 11 ] = 0x00 ;
V_2 -> V_71 -> V_81 = 12 ;
break;
case V_56 :
V_2 -> V_63 [ 0 ] = 0x09 ;
V_2 -> V_63 [ 1 ] = 0x08 ;
V_2 -> V_63 [ 2 ] = 0x00 ;
V_2 -> V_63 [ 3 ] = 0x08 ;
V_2 -> V_63 [ 4 ] = 0x00 ;
V_2 -> V_63 [ 5 ] = 0x03 ;
V_2 -> V_63 [ 6 ] = 0x00 ;
V_2 -> V_63 [ 7 ] = 0x00 ;
V_2 -> V_63 [ 8 ] = V_84 / 256 ;
V_2 -> V_63 [ 9 ] = V_85 / 256 ;
V_2 -> V_63 [ 10 ] = 0x80 ;
V_2 -> V_63 [ 11 ] = 0x00 ;
V_2 -> V_71 -> V_81 = 12 ;
break;
default:
F_12 ( & V_2 -> V_6 -> V_6 ,
L_4 ,
V_53 , V_2 -> V_37 ) ;
return - V_92 ;
}
return F_13 ( V_2 -> V_71 , V_57 ) ;
}
static int F_32 ( struct V_1 * V_2 )
{
if ( V_2 -> V_37 == V_62 )
return 0 ;
F_33 ( V_2 -> V_6 , V_93 , V_86 ) ;
return F_34 ( V_2 -> V_6 , NULL , F_30 ) ;
}
static int F_32 ( struct V_1 * V_2 ) { return 0 ; }
static void F_35 ( struct V_1 * V_2 , int V_94 )
{
V_94 %= 16 ;
F_28 ( & V_2 -> V_70 ) ;
switch ( V_2 -> V_37 ) {
case V_54 :
V_2 -> V_63 [ 0 ] = 0x01 ;
V_2 -> V_63 [ 1 ] = 0x03 ;
V_2 -> V_63 [ 2 ] = V_94 ;
V_2 -> V_71 -> V_81 = 3 ;
break;
case V_38 :
V_2 -> V_63 [ 0 ] = 0x00 ;
V_2 -> V_63 [ 1 ] = 0x00 ;
V_2 -> V_63 [ 2 ] = 0x08 ;
V_2 -> V_63 [ 3 ] = 0x40 + V_94 ;
V_2 -> V_63 [ 4 ] = 0x00 ;
V_2 -> V_63 [ 5 ] = 0x00 ;
V_2 -> V_63 [ 6 ] = 0x00 ;
V_2 -> V_63 [ 7 ] = 0x00 ;
V_2 -> V_63 [ 8 ] = 0x00 ;
V_2 -> V_63 [ 9 ] = 0x00 ;
V_2 -> V_63 [ 10 ] = 0x00 ;
V_2 -> V_63 [ 11 ] = 0x00 ;
V_2 -> V_71 -> V_81 = 12 ;
break;
}
F_13 ( V_2 -> V_71 , V_66 ) ;
F_29 ( & V_2 -> V_70 ) ;
}
static void F_8 ( struct V_1 * V_2 )
{
F_35 ( V_2 , ( V_2 -> V_95 % 4 ) + 2 ) ;
}
static void F_36 ( struct V_96 * V_97 ,
enum V_98 V_99 )
{
struct V_100 * V_100 = F_37 ( V_97 ,
struct V_100 , V_97 ) ;
F_35 ( V_100 -> V_2 , V_99 ) ;
}
static int F_38 ( struct V_1 * V_2 )
{
struct V_100 * V_101 ;
struct V_96 * V_97 ;
int error ;
if ( V_2 -> V_37 != V_54 && V_2 -> V_37 != V_38 )
return 0 ;
V_2 -> V_101 = V_101 = F_39 ( sizeof( struct V_100 ) , V_66 ) ;
if ( ! V_101 )
return - V_68 ;
V_2 -> V_95 = F_40 ( & V_102 , 0 , 0 , V_66 ) ;
if ( V_2 -> V_95 < 0 ) {
error = V_2 -> V_95 ;
goto V_103;
}
snprintf ( V_101 -> V_104 , sizeof( V_101 -> V_104 ) , L_5 , V_2 -> V_95 ) ;
V_101 -> V_2 = V_2 ;
V_97 = & V_101 -> V_97 ;
V_97 -> V_104 = V_101 -> V_104 ;
V_97 -> V_105 = F_36 ;
error = F_41 ( & V_2 -> V_64 -> V_6 , V_97 ) ;
if ( error )
goto V_106;
if ( V_2 -> V_37 == V_54 ) {
F_8 ( V_2 ) ;
}
return 0 ;
V_106:
F_42 ( & V_102 , V_2 -> V_95 ) ;
V_103:
F_43 ( V_101 ) ;
V_2 -> V_101 = NULL ;
return error ;
}
static void F_44 ( struct V_1 * V_2 )
{
struct V_100 * V_100 = V_2 -> V_101 ;
if ( V_100 ) {
F_45 ( & V_100 -> V_97 ) ;
F_42 ( & V_102 , V_2 -> V_95 ) ;
F_43 ( V_100 ) ;
}
}
static int F_38 ( struct V_1 * V_2 ) { return 0 ; }
static void F_44 ( struct V_1 * V_2 ) { }
static void F_8 ( struct V_1 * V_2 ) { }
static int F_46 ( struct V_5 * V_6 )
{
struct V_1 * V_2 = F_31 ( V_6 ) ;
if ( V_2 -> V_37 == V_38 )
return 0 ;
V_2 -> V_107 -> V_6 = V_2 -> V_64 ;
if ( F_13 ( V_2 -> V_107 , V_66 ) )
return - V_108 ;
if ( V_2 -> V_37 == V_56 ) {
V_2 -> V_63 [ 0 ] = 0x05 ;
V_2 -> V_63 [ 1 ] = 0x20 ;
V_2 -> V_71 -> V_81 = 2 ;
return F_13 ( V_2 -> V_71 , V_66 ) ;
}
return 0 ;
}
static void F_47 ( struct V_5 * V_6 )
{
struct V_1 * V_2 = F_31 ( V_6 ) ;
if ( V_2 -> V_37 != V_38 )
F_24 ( V_2 -> V_107 ) ;
F_23 ( V_2 ) ;
}
static void F_48 ( struct V_5 * V_5 , signed short abs )
{
struct V_1 * V_2 = F_31 ( V_5 ) ;
F_49 ( abs , V_5 -> V_109 ) ;
switch ( abs ) {
case V_9 :
case V_12 :
case V_13 :
case V_14 :
F_50 ( V_5 , abs , - 32768 , 32767 , 16 , 128 ) ;
break;
case V_18 :
case V_19 :
if ( V_2 -> V_37 == V_56 )
F_50 ( V_5 , abs , 0 , 1023 , 0 , 0 ) ;
else
F_50 ( V_5 , abs , 0 , 255 , 0 , 0 ) ;
break;
case V_25 :
case V_26 :
F_50 ( V_5 , abs , - 1 , 1 , 0 , 0 ) ;
break;
}
}
static void F_51 ( struct V_1 * V_2 )
{
F_44 ( V_2 ) ;
F_52 ( V_2 -> V_6 ) ;
}
static int F_53 ( struct V_1 * V_2 )
{
struct V_5 * V_5 ;
int V_110 , error ;
V_5 = F_54 () ;
if ( ! V_5 )
return - V_68 ;
V_2 -> V_6 = V_5 ;
V_5 -> V_104 = V_2 -> V_104 ;
V_5 -> V_111 = V_2 -> V_111 ;
F_55 ( V_2 -> V_64 , & V_5 -> V_112 ) ;
V_5 -> V_6 . V_113 = & V_2 -> V_47 -> V_6 ;
F_56 ( V_5 , V_2 ) ;
V_5 -> V_114 = F_46 ;
V_5 -> V_115 = F_47 ;
F_57 ( V_116 , V_5 -> V_117 ) ;
if ( ! ( V_2 -> V_7 & V_8 ) ) {
F_57 ( V_118 , V_5 -> V_117 ) ;
for ( V_110 = 0 ; V_119 [ V_110 ] >= 0 ; V_110 ++ )
F_48 ( V_5 , V_119 [ V_110 ] ) ;
}
for ( V_110 = 0 ; V_120 [ V_110 ] >= 0 ; V_110 ++ )
F_57 ( V_120 [ V_110 ] , V_5 -> V_121 ) ;
if ( V_2 -> V_37 == V_54 || V_2 -> V_37 == V_38 ||
V_2 -> V_37 == V_56 ) {
for ( V_110 = 0 ; V_122 [ V_110 ] >= 0 ; V_110 ++ )
F_57 ( V_122 [ V_110 ] , V_5 -> V_121 ) ;
} else {
for ( V_110 = 0 ; V_123 [ V_110 ] >= 0 ; V_110 ++ )
F_57 ( V_123 [ V_110 ] , V_5 -> V_121 ) ;
}
if ( V_2 -> V_7 & V_20 ) {
for ( V_110 = 0 ; V_124 [ V_110 ] >= 0 ; V_110 ++ )
F_57 ( V_124 [ V_110 ] , V_5 -> V_121 ) ;
}
if ( ! ( V_2 -> V_7 & V_20 ) ||
V_2 -> V_37 == V_38 ) {
for ( V_110 = 0 ; V_125 [ V_110 ] >= 0 ; V_110 ++ )
F_48 ( V_5 , V_125 [ V_110 ] ) ;
}
if ( V_2 -> V_7 & V_15 ) {
for ( V_110 = 0 ; V_126 [ V_110 ] >= 0 ; V_110 ++ )
F_57 ( V_126 [ V_110 ] , V_5 -> V_121 ) ;
} else {
for ( V_110 = 0 ; V_127 [ V_110 ] >= 0 ; V_110 ++ )
F_48 ( V_5 , V_127 [ V_110 ] ) ;
}
error = F_32 ( V_2 ) ;
if ( error )
goto V_128;
error = F_38 ( V_2 ) ;
if ( error )
goto V_129;
error = F_58 ( V_2 -> V_6 ) ;
if ( error )
goto V_130;
return 0 ;
V_130:
F_44 ( V_2 ) ;
V_129:
F_59 ( V_5 ) ;
V_128:
F_60 ( V_5 ) ;
return error ;
}
static int F_61 ( struct V_58 * V_47 , const struct V_131 * V_112 )
{
struct V_132 * V_64 = F_62 ( V_47 ) ;
struct V_1 * V_2 ;
struct V_59 * V_133 ;
int V_134 ;
int V_110 , error ;
for ( V_110 = 0 ; V_135 [ V_110 ] . V_136 ; V_110 ++ ) {
if ( ( F_63 ( V_64 -> V_137 . V_136 ) == V_135 [ V_110 ] . V_136 ) &&
( F_63 ( V_64 -> V_137 . V_138 ) == V_135 [ V_110 ] . V_138 ) )
break;
}
if ( V_135 [ V_110 ] . V_37 == V_56 &&
V_47 -> V_73 -> V_75 . V_139 != 0 ) {
return - V_140 ;
}
V_2 = F_39 ( sizeof( struct V_1 ) , V_66 ) ;
if ( ! V_2 )
return - V_68 ;
F_64 ( V_64 , V_2 -> V_111 , sizeof( V_2 -> V_111 ) ) ;
F_65 ( V_2 -> V_111 , L_6 , sizeof( V_2 -> V_111 ) ) ;
V_2 -> V_55 = F_17 ( V_64 , V_65 ,
V_66 , & V_2 -> V_141 ) ;
if ( ! V_2 -> V_55 ) {
error = - V_68 ;
goto V_103;
}
V_2 -> V_107 = F_19 ( 0 , V_66 ) ;
if ( ! V_2 -> V_107 ) {
error = - V_68 ;
goto V_142;
}
V_2 -> V_64 = V_64 ;
V_2 -> V_47 = V_47 ;
V_2 -> V_7 = V_135 [ V_110 ] . V_7 ;
V_2 -> V_37 = V_135 [ V_110 ] . V_37 ;
V_2 -> V_104 = V_135 [ V_110 ] . V_104 ;
if ( V_2 -> V_37 == V_62 ) {
if ( V_47 -> V_73 -> V_75 . V_143 == V_144 ) {
if ( V_47 -> V_73 -> V_75 . V_145 == 129 )
V_2 -> V_37 = V_38 ;
else
V_2 -> V_37 = V_54 ;
} else {
V_2 -> V_37 = V_91 ;
}
if ( V_146 )
V_2 -> V_7 |= V_20 ;
if ( V_147 )
V_2 -> V_7 |= V_15 ;
if ( V_148 )
V_2 -> V_7 |= V_8 ;
}
error = F_16 ( V_47 , V_2 ) ;
if ( error )
goto V_149;
V_134 = V_2 -> V_37 == V_56 ? 1 : 0 ;
V_133 = & V_47 -> V_73 -> V_74 [ V_134 ] . V_75 ;
F_20 ( V_2 -> V_107 , V_64 ,
F_66 ( V_64 , V_133 -> V_76 ) ,
V_2 -> V_55 , V_65 , F_11 ,
V_2 , V_133 -> V_77 ) ;
V_2 -> V_107 -> V_78 = V_2 -> V_141 ;
V_2 -> V_107 -> V_79 |= V_80 ;
F_67 ( V_47 , V_2 ) ;
error = F_53 ( V_2 ) ;
if ( error )
goto V_150;
if ( V_2 -> V_37 == V_38 ) {
V_2 -> V_107 -> V_6 = V_2 -> V_64 ;
error = F_13 ( V_2 -> V_107 , V_66 ) ;
if ( error )
goto V_151;
error = F_27 ( V_2 ) ;
if ( error )
goto V_152;
}
return 0 ;
V_152:
F_24 ( V_2 -> V_107 ) ;
V_151:
F_51 ( V_2 ) ;
V_150:
F_25 ( V_2 ) ;
V_149:
F_26 ( V_2 -> V_107 ) ;
V_142:
F_22 ( V_64 , V_65 , V_2 -> V_55 , V_2 -> V_141 ) ;
V_103:
F_43 ( V_2 ) ;
return error ;
}
static void F_68 ( struct V_58 * V_47 )
{
struct V_1 * V_2 = F_69 ( V_47 ) ;
F_51 ( V_2 ) ;
F_25 ( V_2 ) ;
if ( V_2 -> V_37 == V_38 ) {
F_24 ( V_2 -> V_107 ) ;
}
F_26 ( V_2 -> V_107 ) ;
F_22 ( V_2 -> V_64 , V_65 ,
V_2 -> V_55 , V_2 -> V_141 ) ;
F_43 ( V_2 ) ;
F_67 ( V_47 , NULL ) ;
}
