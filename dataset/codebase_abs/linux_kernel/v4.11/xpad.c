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
static void F_6 ( struct V_1 * V_2 , struct V_5 * V_6 ,
T_1 V_3 , unsigned char * V_4 )
{
if ( V_4 [ 0 ] != 0x00 )
return;
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
static void F_7 ( struct V_42 * V_43 )
{
struct V_1 * V_2 = F_8 ( V_43 , struct V_1 , V_43 ) ;
int error ;
if ( V_2 -> V_44 ) {
error = F_9 ( V_2 ) ;
if ( error ) {
F_10 ( & V_2 -> V_6 -> V_6 ,
L_1 , error ) ;
} else {
F_11 ( V_2 -> V_45 , V_2 -> V_6 ) ;
}
} else {
F_12 ( V_2 -> V_45 , NULL ) ;
F_13 () ;
F_14 ( V_2 ) ;
}
}
static void F_15 ( struct V_1 * V_2 , T_1 V_3 , unsigned char * V_4 )
{
struct V_5 * V_6 ;
bool V_46 ;
if ( V_4 [ 0 ] & 0x08 ) {
V_46 = ( V_4 [ 1 ] & 0x80 ) != 0 ;
if ( V_2 -> V_44 != V_46 ) {
V_2 -> V_44 = V_46 ;
F_16 ( & V_2 -> V_43 ) ;
}
}
if ( V_4 [ 1 ] != 0x1 )
return;
F_17 () ;
V_6 = F_18 ( V_2 -> V_45 ) ;
if ( V_6 )
F_6 ( V_2 , V_6 , V_3 , & V_4 [ 4 ] ) ;
F_19 () ;
}
static void F_20 ( struct V_1 * V_2 , T_1 V_3 , unsigned char * V_4 )
{
struct V_5 * V_6 = V_2 -> V_6 ;
if ( V_4 [ 0 ] == 0X07 ) {
if ( V_4 [ 1 ] == 0x30 )
F_21 ( V_2 , V_4 [ 2 ] ) ;
F_4 ( V_6 , V_41 , V_4 [ 4 ] & 0x01 ) ;
F_5 ( V_6 ) ;
return;
}
else if ( V_4 [ 0 ] != 0X20 )
return;
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
( V_47 ) F_3 ( ( V_11 * ) ( V_4 + 6 ) ) ) ;
F_4 ( V_6 , V_17 ,
( V_47 ) F_3 ( ( V_11 * ) ( V_4 + 8 ) ) ) ;
} else {
F_2 ( V_6 , V_18 ,
( V_47 ) F_3 ( ( V_11 * ) ( V_4 + 6 ) ) ) ;
F_2 ( V_6 , V_19 ,
( V_47 ) F_3 ( ( V_11 * ) ( V_4 + 8 ) ) ) ;
}
F_5 ( V_6 ) ;
}
static void F_22 ( struct V_48 * V_48 )
{
struct V_1 * V_2 = V_48 -> V_49 ;
struct V_50 * V_6 = & V_2 -> V_51 -> V_6 ;
int V_52 , V_53 ;
V_53 = V_48 -> V_53 ;
switch ( V_53 ) {
case 0 :
break;
case - V_54 :
case - V_55 :
case - V_56 :
F_23 ( V_6 , L_2 ,
V_57 , V_53 ) ;
return;
default:
F_23 ( V_6 , L_3 ,
V_57 , V_53 ) ;
goto exit;
}
switch ( V_2 -> V_37 ) {
case V_58 :
F_6 ( V_2 , V_2 -> V_6 , 0 , V_2 -> V_59 ) ;
break;
case V_38 :
F_15 ( V_2 , 0 , V_2 -> V_59 ) ;
break;
case V_60 :
F_20 ( V_2 , 0 , V_2 -> V_59 ) ;
break;
default:
F_1 ( V_2 , 0 , V_2 -> V_59 ) ;
}
exit:
V_52 = F_24 ( V_48 , V_61 ) ;
if ( V_52 )
F_10 ( V_6 , L_4 ,
V_57 , V_52 ) ;
}
static bool F_25 ( struct V_1 * V_2 )
{
struct V_62 * V_63 , * V_64 = NULL ;
int V_65 ;
for ( V_65 = 0 ; V_65 < V_66 ; V_65 ++ ) {
if ( ++ V_2 -> V_67 >= V_66 )
V_2 -> V_67 = 0 ;
V_63 = & V_2 -> V_68 [ V_2 -> V_67 ] ;
if ( V_63 -> V_69 ) {
F_23 ( & V_2 -> V_51 -> V_6 ,
L_5 ,
V_57 , V_2 -> V_67 ) ;
V_64 = V_63 ;
break;
}
}
if ( V_64 ) {
memcpy ( V_2 -> V_70 , V_64 -> V_4 , V_64 -> V_71 ) ;
V_2 -> V_72 -> V_73 = V_64 -> V_71 ;
V_64 -> V_69 = false ;
return true ;
}
return false ;
}
static int F_26 ( struct V_1 * V_2 )
{
int error ;
if ( ! V_2 -> V_74 && F_25 ( V_2 ) ) {
F_27 ( V_2 -> V_72 , & V_2 -> V_75 ) ;
error = F_24 ( V_2 -> V_72 , V_61 ) ;
if ( error ) {
F_10 ( & V_2 -> V_51 -> V_6 ,
L_4 ,
V_57 , error ) ;
F_28 ( V_2 -> V_72 ) ;
return - V_76 ;
}
V_2 -> V_74 = true ;
}
return 0 ;
}
static void F_29 ( struct V_48 * V_48 )
{
struct V_1 * V_2 = V_48 -> V_49 ;
struct V_50 * V_6 = & V_2 -> V_51 -> V_6 ;
int V_53 = V_48 -> V_53 ;
int error ;
unsigned long V_77 ;
F_30 ( & V_2 -> V_78 , V_77 ) ;
switch ( V_53 ) {
case 0 :
V_2 -> V_74 = F_25 ( V_2 ) ;
break;
case - V_54 :
case - V_55 :
case - V_56 :
F_23 ( V_6 , L_2 ,
V_57 , V_53 ) ;
V_2 -> V_74 = false ;
break;
default:
F_23 ( V_6 , L_3 ,
V_57 , V_53 ) ;
break;
}
if ( V_2 -> V_74 ) {
F_27 ( V_48 , & V_2 -> V_75 ) ;
error = F_24 ( V_48 , V_61 ) ;
if ( error ) {
F_10 ( V_6 ,
L_4 ,
V_57 , error ) ;
F_28 ( V_48 ) ;
V_2 -> V_74 = false ;
}
}
F_31 ( & V_2 -> V_78 , V_77 ) ;
}
static int F_32 ( struct V_79 * V_51 , struct V_1 * V_2 ,
struct V_80 * V_81 )
{
int error ;
if ( V_2 -> V_37 == V_82 )
return 0 ;
F_33 ( & V_2 -> V_75 ) ;
V_2 -> V_70 = F_34 ( V_2 -> V_83 , V_84 ,
V_85 , & V_2 -> V_86 ) ;
if ( ! V_2 -> V_70 )
return - V_87 ;
F_35 ( & V_2 -> V_78 ) ;
V_2 -> V_72 = F_36 ( 0 , V_85 ) ;
if ( ! V_2 -> V_72 ) {
error = - V_87 ;
goto V_88;
}
F_37 ( V_2 -> V_72 , V_2 -> V_83 ,
F_38 ( V_2 -> V_83 , V_81 -> V_89 ) ,
V_2 -> V_70 , V_84 ,
F_29 , V_2 , V_81 -> V_90 ) ;
V_2 -> V_72 -> V_91 = V_2 -> V_86 ;
V_2 -> V_72 -> V_92 |= V_93 ;
return 0 ;
V_88:
F_39 ( V_2 -> V_83 , V_84 , V_2 -> V_70 , V_2 -> V_86 ) ;
return error ;
}
static void F_40 ( struct V_1 * V_2 )
{
if ( V_2 -> V_37 != V_82 ) {
if ( ! F_41 ( & V_2 -> V_75 ,
5000 ) ) {
F_42 ( & V_2 -> V_51 -> V_6 ,
L_6 ) ;
F_43 ( & V_2 -> V_75 ) ;
}
}
}
static void F_44 ( struct V_1 * V_2 )
{
if ( V_2 -> V_37 != V_82 ) {
F_45 ( V_2 -> V_72 ) ;
F_39 ( V_2 -> V_83 , V_84 ,
V_2 -> V_70 , V_2 -> V_86 ) ;
}
}
static int F_46 ( struct V_1 * V_2 )
{
struct V_62 * V_64 =
& V_2 -> V_68 [ V_94 ] ;
unsigned long V_77 ;
int V_52 ;
F_30 ( & V_2 -> V_78 , V_77 ) ;
V_64 -> V_4 [ 0 ] = 0x08 ;
V_64 -> V_4 [ 1 ] = 0x00 ;
V_64 -> V_4 [ 2 ] = 0x0F ;
V_64 -> V_4 [ 3 ] = 0xC0 ;
V_64 -> V_4 [ 4 ] = 0x00 ;
V_64 -> V_4 [ 5 ] = 0x00 ;
V_64 -> V_4 [ 6 ] = 0x00 ;
V_64 -> V_4 [ 7 ] = 0x00 ;
V_64 -> V_4 [ 8 ] = 0x00 ;
V_64 -> V_4 [ 9 ] = 0x00 ;
V_64 -> V_4 [ 10 ] = 0x00 ;
V_64 -> V_4 [ 11 ] = 0x00 ;
V_64 -> V_71 = 12 ;
V_64 -> V_69 = true ;
V_2 -> V_67 = - 1 ;
V_52 = F_26 ( V_2 ) ;
F_31 ( & V_2 -> V_78 , V_77 ) ;
return V_52 ;
}
static int F_47 ( struct V_1 * V_2 )
{
struct V_62 * V_64 =
& V_2 -> V_68 [ V_94 ] ;
unsigned long V_77 ;
int V_52 ;
F_30 ( & V_2 -> V_78 , V_77 ) ;
V_64 -> V_4 [ 0 ] = 0x05 ;
V_64 -> V_4 [ 1 ] = 0x20 ;
V_64 -> V_4 [ 2 ] = V_2 -> V_95 ++ ;
V_64 -> V_4 [ 3 ] = 0x01 ;
V_64 -> V_4 [ 4 ] = 0x00 ;
V_64 -> V_71 = 5 ;
V_64 -> V_69 = true ;
V_2 -> V_67 = - 1 ;
V_52 = F_26 ( V_2 ) ;
F_31 ( & V_2 -> V_78 , V_77 ) ;
return V_52 ;
}
static void F_21 ( struct V_1 * V_2 , T_2 V_96 )
{
unsigned long V_77 ;
struct V_62 * V_64 =
& V_2 -> V_68 [ V_94 ] ;
static const T_2 V_97 [] = {
0x01 , 0x20 , 0x00 , 0x09 , 0x00 , 0x07 , 0x20 , 0x02 ,
0x00 , 0x00 , 0x00 , 0x00 , 0x00
} ;
F_30 ( & V_2 -> V_78 , V_77 ) ;
V_64 -> V_71 = sizeof( V_97 ) ;
memcpy ( V_64 -> V_4 , V_97 , V_64 -> V_71 ) ;
V_64 -> V_4 [ 2 ] = V_96 ;
V_64 -> V_69 = true ;
V_2 -> V_67 = - 1 ;
F_26 ( V_2 ) ;
F_31 ( & V_2 -> V_78 , V_77 ) ;
}
static int F_48 ( struct V_5 * V_6 , void * V_4 , struct V_98 * V_99 )
{
struct V_1 * V_2 = F_49 ( V_6 ) ;
struct V_62 * V_64 = & V_2 -> V_68 [ V_100 ] ;
V_47 V_101 ;
V_47 V_102 ;
int V_52 ;
unsigned long V_77 ;
if ( V_99 -> type != V_103 )
return 0 ;
V_101 = V_99 -> V_104 . V_105 . V_106 ;
V_102 = V_99 -> V_104 . V_105 . V_107 ;
F_30 ( & V_2 -> V_78 , V_77 ) ;
switch ( V_2 -> V_37 ) {
case V_108 :
V_64 -> V_4 [ 0 ] = 0x00 ;
V_64 -> V_4 [ 1 ] = 0x06 ;
V_64 -> V_4 [ 2 ] = 0x00 ;
V_64 -> V_4 [ 3 ] = V_101 / 256 ;
V_64 -> V_4 [ 4 ] = 0x00 ;
V_64 -> V_4 [ 5 ] = V_102 / 256 ;
V_64 -> V_71 = 6 ;
V_64 -> V_69 = true ;
break;
case V_58 :
V_64 -> V_4 [ 0 ] = 0x00 ;
V_64 -> V_4 [ 1 ] = 0x08 ;
V_64 -> V_4 [ 2 ] = 0x00 ;
V_64 -> V_4 [ 3 ] = V_101 / 256 ;
V_64 -> V_4 [ 4 ] = V_102 / 256 ;
V_64 -> V_4 [ 5 ] = 0x00 ;
V_64 -> V_4 [ 6 ] = 0x00 ;
V_64 -> V_4 [ 7 ] = 0x00 ;
V_64 -> V_71 = 8 ;
V_64 -> V_69 = true ;
break;
case V_38 :
V_64 -> V_4 [ 0 ] = 0x00 ;
V_64 -> V_4 [ 1 ] = 0x01 ;
V_64 -> V_4 [ 2 ] = 0x0F ;
V_64 -> V_4 [ 3 ] = 0xC0 ;
V_64 -> V_4 [ 4 ] = 0x00 ;
V_64 -> V_4 [ 5 ] = V_101 / 256 ;
V_64 -> V_4 [ 6 ] = V_102 / 256 ;
V_64 -> V_4 [ 7 ] = 0x00 ;
V_64 -> V_4 [ 8 ] = 0x00 ;
V_64 -> V_4 [ 9 ] = 0x00 ;
V_64 -> V_4 [ 10 ] = 0x00 ;
V_64 -> V_4 [ 11 ] = 0x00 ;
V_64 -> V_71 = 12 ;
V_64 -> V_69 = true ;
break;
case V_60 :
V_64 -> V_4 [ 0 ] = 0x09 ;
V_64 -> V_4 [ 1 ] = 0x00 ;
V_64 -> V_4 [ 2 ] = V_2 -> V_95 ++ ;
V_64 -> V_4 [ 3 ] = 0x09 ;
V_64 -> V_4 [ 4 ] = 0x00 ;
V_64 -> V_4 [ 5 ] = 0x0F ;
V_64 -> V_4 [ 6 ] = 0x00 ;
V_64 -> V_4 [ 7 ] = 0x00 ;
V_64 -> V_4 [ 8 ] = V_101 / 512 ;
V_64 -> V_4 [ 9 ] = V_102 / 512 ;
V_64 -> V_4 [ 10 ] = 0xFF ;
V_64 -> V_4 [ 11 ] = 0x00 ;
V_64 -> V_4 [ 12 ] = 0xFF ;
V_64 -> V_71 = 13 ;
V_64 -> V_69 = true ;
break;
default:
F_23 ( & V_2 -> V_6 -> V_6 ,
L_7 ,
V_57 , V_2 -> V_37 ) ;
V_52 = - V_109 ;
goto V_110;
}
V_52 = F_26 ( V_2 ) ;
V_110:
F_31 ( & V_2 -> V_78 , V_77 ) ;
return V_52 ;
}
static int F_50 ( struct V_1 * V_2 )
{
if ( V_2 -> V_37 == V_82 )
return 0 ;
F_51 ( V_2 -> V_6 , V_111 , V_103 ) ;
return F_52 ( V_2 -> V_6 , NULL , F_48 ) ;
}
static int F_50 ( struct V_1 * V_2 ) { return 0 ; }
static void F_53 ( struct V_1 * V_2 , int V_112 )
{
struct V_62 * V_64 =
& V_2 -> V_68 [ V_113 ] ;
unsigned long V_77 ;
V_112 %= 16 ;
F_30 ( & V_2 -> V_78 , V_77 ) ;
switch ( V_2 -> V_37 ) {
case V_58 :
V_64 -> V_4 [ 0 ] = 0x01 ;
V_64 -> V_4 [ 1 ] = 0x03 ;
V_64 -> V_4 [ 2 ] = V_112 ;
V_64 -> V_71 = 3 ;
V_64 -> V_69 = true ;
break;
case V_38 :
V_64 -> V_4 [ 0 ] = 0x00 ;
V_64 -> V_4 [ 1 ] = 0x00 ;
V_64 -> V_4 [ 2 ] = 0x08 ;
V_64 -> V_4 [ 3 ] = 0x40 + V_112 ;
V_64 -> V_4 [ 4 ] = 0x00 ;
V_64 -> V_4 [ 5 ] = 0x00 ;
V_64 -> V_4 [ 6 ] = 0x00 ;
V_64 -> V_4 [ 7 ] = 0x00 ;
V_64 -> V_4 [ 8 ] = 0x00 ;
V_64 -> V_4 [ 9 ] = 0x00 ;
V_64 -> V_4 [ 10 ] = 0x00 ;
V_64 -> V_4 [ 11 ] = 0x00 ;
V_64 -> V_71 = 12 ;
V_64 -> V_69 = true ;
break;
}
F_26 ( V_2 ) ;
F_31 ( & V_2 -> V_78 , V_77 ) ;
}
static void F_54 ( struct V_1 * V_2 )
{
F_55 ( & V_2 -> V_114 -> V_115 , ( V_2 -> V_116 % 4 ) + 2 ) ;
}
static void F_56 ( struct V_117 * V_115 ,
enum V_118 V_119 )
{
struct V_120 * V_120 = F_8 ( V_115 ,
struct V_120 , V_115 ) ;
F_53 ( V_120 -> V_2 , V_119 ) ;
}
static int F_57 ( struct V_1 * V_2 )
{
struct V_120 * V_114 ;
struct V_117 * V_115 ;
int error ;
if ( V_2 -> V_37 != V_58 && V_2 -> V_37 != V_38 )
return 0 ;
V_2 -> V_114 = V_114 = F_58 ( sizeof( struct V_120 ) , V_85 ) ;
if ( ! V_114 )
return - V_87 ;
V_2 -> V_116 = F_59 ( & V_121 , 0 , 0 , V_85 ) ;
if ( V_2 -> V_116 < 0 ) {
error = V_2 -> V_116 ;
goto V_122;
}
snprintf ( V_114 -> V_123 , sizeof( V_114 -> V_123 ) , L_8 , V_2 -> V_116 ) ;
V_114 -> V_2 = V_2 ;
V_115 = & V_114 -> V_115 ;
V_115 -> V_123 = V_114 -> V_123 ;
V_115 -> V_124 = F_56 ;
V_115 -> V_77 = V_125 ;
error = F_60 ( & V_2 -> V_83 -> V_6 , V_115 ) ;
if ( error )
goto V_126;
F_54 ( V_2 ) ;
return 0 ;
V_126:
F_61 ( & V_121 , V_2 -> V_116 ) ;
V_122:
F_62 ( V_114 ) ;
V_2 -> V_114 = NULL ;
return error ;
}
static void F_63 ( struct V_1 * V_2 )
{
struct V_120 * V_120 = V_2 -> V_114 ;
if ( V_120 ) {
F_64 ( & V_120 -> V_115 ) ;
F_61 ( & V_121 , V_2 -> V_116 ) ;
F_62 ( V_120 ) ;
}
}
static int F_57 ( struct V_1 * V_2 ) { return 0 ; }
static void F_63 ( struct V_1 * V_2 ) { }
static int F_65 ( struct V_1 * V_2 )
{
int error ;
if ( F_24 ( V_2 -> V_127 , V_85 ) )
return - V_76 ;
if ( V_2 -> V_37 == V_60 ) {
error = F_47 ( V_2 ) ;
if ( error ) {
F_66 ( V_2 -> V_127 ) ;
return error ;
}
}
return 0 ;
}
static void F_67 ( struct V_1 * V_2 )
{
F_66 ( V_2 -> V_127 ) ;
}
static void F_68 ( struct V_1 * V_2 )
{
unsigned long V_77 ;
struct V_62 * V_64 =
& V_2 -> V_68 [ V_94 ] ;
F_30 ( & V_2 -> V_78 , V_77 ) ;
V_64 -> V_4 [ 0 ] = 0x00 ;
V_64 -> V_4 [ 1 ] = 0x00 ;
V_64 -> V_4 [ 2 ] = 0x08 ;
V_64 -> V_4 [ 3 ] = 0xC0 ;
V_64 -> V_4 [ 4 ] = 0x00 ;
V_64 -> V_4 [ 5 ] = 0x00 ;
V_64 -> V_4 [ 6 ] = 0x00 ;
V_64 -> V_4 [ 7 ] = 0x00 ;
V_64 -> V_4 [ 8 ] = 0x00 ;
V_64 -> V_4 [ 9 ] = 0x00 ;
V_64 -> V_4 [ 10 ] = 0x00 ;
V_64 -> V_4 [ 11 ] = 0x00 ;
V_64 -> V_71 = 12 ;
V_64 -> V_69 = true ;
V_2 -> V_67 = - 1 ;
F_26 ( V_2 ) ;
F_31 ( & V_2 -> V_78 , V_77 ) ;
}
static int F_69 ( struct V_1 * V_2 )
{
int error ;
error = F_24 ( V_2 -> V_127 , V_85 ) ;
if ( error )
return - V_76 ;
error = F_46 ( V_2 ) ;
if ( error ) {
F_66 ( V_2 -> V_127 ) ;
return error ;
}
return 0 ;
}
static void F_70 ( struct V_1 * V_2 )
{
F_66 ( V_2 -> V_127 ) ;
F_71 ( & V_2 -> V_43 ) ;
}
static int F_72 ( struct V_5 * V_6 )
{
struct V_1 * V_2 = F_49 ( V_6 ) ;
return F_65 ( V_2 ) ;
}
static void F_73 ( struct V_5 * V_6 )
{
struct V_1 * V_2 = F_49 ( V_6 ) ;
F_67 ( V_2 ) ;
}
static void F_74 ( struct V_5 * V_5 , signed short abs )
{
struct V_1 * V_2 = F_49 ( V_5 ) ;
F_75 ( abs , V_5 -> V_128 ) ;
switch ( abs ) {
case V_9 :
case V_12 :
case V_13 :
case V_14 :
F_76 ( V_5 , abs , - 32768 , 32767 , 16 , 128 ) ;
break;
case V_18 :
case V_19 :
if ( V_2 -> V_37 == V_60 )
F_76 ( V_5 , abs , 0 , 1023 , 0 , 0 ) ;
else
F_76 ( V_5 , abs , 0 , 255 , 0 , 0 ) ;
break;
case V_25 :
case V_26 :
F_76 ( V_5 , abs , - 1 , 1 , 0 , 0 ) ;
break;
}
}
static void F_14 ( struct V_1 * V_2 )
{
if ( V_2 -> V_129 ) {
V_2 -> V_129 = false ;
F_63 ( V_2 ) ;
F_77 ( V_2 -> V_6 ) ;
}
}
static int F_9 ( struct V_1 * V_2 )
{
struct V_5 * V_5 ;
int V_65 , error ;
V_5 = F_78 () ;
if ( ! V_5 )
return - V_87 ;
V_2 -> V_6 = V_5 ;
V_5 -> V_123 = V_2 -> V_123 ;
V_5 -> V_130 = V_2 -> V_130 ;
F_79 ( V_2 -> V_83 , & V_5 -> V_131 ) ;
if ( V_2 -> V_37 == V_38 ) {
V_5 -> V_131 . V_132 = 0x02a1 ;
}
V_5 -> V_6 . V_133 = & V_2 -> V_51 -> V_6 ;
F_80 ( V_5 , V_2 ) ;
if ( V_2 -> V_37 != V_38 ) {
V_5 -> V_134 = F_72 ;
V_5 -> V_135 = F_73 ;
}
F_81 ( V_136 , V_5 -> V_137 ) ;
if ( ! ( V_2 -> V_7 & V_8 ) ) {
F_81 ( V_138 , V_5 -> V_137 ) ;
for ( V_65 = 0 ; V_139 [ V_65 ] >= 0 ; V_65 ++ )
F_74 ( V_5 , V_139 [ V_65 ] ) ;
}
for ( V_65 = 0 ; V_140 [ V_65 ] >= 0 ; V_65 ++ )
F_81 ( V_140 [ V_65 ] , V_5 -> V_141 ) ;
if ( V_2 -> V_37 == V_58 || V_2 -> V_37 == V_38 ||
V_2 -> V_37 == V_60 ) {
for ( V_65 = 0 ; V_142 [ V_65 ] >= 0 ; V_65 ++ )
F_81 ( V_142 [ V_65 ] , V_5 -> V_141 ) ;
} else {
for ( V_65 = 0 ; V_143 [ V_65 ] >= 0 ; V_65 ++ )
F_81 ( V_143 [ V_65 ] , V_5 -> V_141 ) ;
}
if ( V_2 -> V_7 & V_20 ) {
for ( V_65 = 0 ; V_144 [ V_65 ] >= 0 ; V_65 ++ )
F_81 ( V_144 [ V_65 ] , V_5 -> V_141 ) ;
}
if ( ! ( V_2 -> V_7 & V_20 ) ||
V_2 -> V_37 == V_38 ) {
for ( V_65 = 0 ; V_145 [ V_65 ] >= 0 ; V_65 ++ )
F_74 ( V_5 , V_145 [ V_65 ] ) ;
}
if ( V_2 -> V_7 & V_15 ) {
for ( V_65 = 0 ; V_146 [ V_65 ] >= 0 ; V_65 ++ )
F_81 ( V_146 [ V_65 ] , V_5 -> V_141 ) ;
} else {
for ( V_65 = 0 ; V_147 [ V_65 ] >= 0 ; V_65 ++ )
F_74 ( V_5 , V_147 [ V_65 ] ) ;
}
error = F_50 ( V_2 ) ;
if ( error )
goto V_148;
error = F_57 ( V_2 ) ;
if ( error )
goto V_149;
error = F_82 ( V_2 -> V_6 ) ;
if ( error )
goto V_150;
V_2 -> V_129 = true ;
return 0 ;
V_150:
F_63 ( V_2 ) ;
V_149:
F_83 ( V_5 ) ;
V_148:
F_84 ( V_5 ) ;
return error ;
}
static int F_85 ( struct V_79 * V_51 , const struct V_151 * V_131 )
{
struct V_152 * V_83 = F_86 ( V_51 ) ;
struct V_1 * V_2 ;
struct V_80 * V_153 , * V_81 ;
int V_65 , error ;
if ( V_51 -> V_154 -> V_155 . V_156 != 2 )
return - V_157 ;
for ( V_65 = 0 ; V_158 [ V_65 ] . V_159 ; V_65 ++ ) {
if ( ( F_87 ( V_83 -> V_160 . V_159 ) == V_158 [ V_65 ] . V_159 ) &&
( F_87 ( V_83 -> V_160 . V_161 ) == V_158 [ V_65 ] . V_161 ) )
break;
}
V_2 = F_58 ( sizeof( struct V_1 ) , V_85 ) ;
if ( ! V_2 )
return - V_87 ;
F_88 ( V_83 , V_2 -> V_130 , sizeof( V_2 -> V_130 ) ) ;
F_89 ( V_2 -> V_130 , L_9 , sizeof( V_2 -> V_130 ) ) ;
V_2 -> V_59 = F_34 ( V_83 , V_84 ,
V_85 , & V_2 -> V_162 ) ;
if ( ! V_2 -> V_59 ) {
error = - V_87 ;
goto V_122;
}
V_2 -> V_127 = F_36 ( 0 , V_85 ) ;
if ( ! V_2 -> V_127 ) {
error = - V_87 ;
goto V_163;
}
V_2 -> V_83 = V_83 ;
V_2 -> V_51 = V_51 ;
V_2 -> V_7 = V_158 [ V_65 ] . V_7 ;
V_2 -> V_37 = V_158 [ V_65 ] . V_37 ;
V_2 -> V_123 = V_158 [ V_65 ] . V_123 ;
F_90 ( & V_2 -> V_43 , F_7 ) ;
if ( V_2 -> V_37 == V_82 ) {
if ( V_51 -> V_154 -> V_155 . V_164 == V_165 ) {
if ( V_51 -> V_154 -> V_155 . V_166 == 129 )
V_2 -> V_37 = V_38 ;
else if ( V_51 -> V_154 -> V_155 . V_166 == 208 )
V_2 -> V_37 = V_60 ;
else
V_2 -> V_37 = V_58 ;
} else {
V_2 -> V_37 = V_108 ;
}
if ( V_167 )
V_2 -> V_7 |= V_20 ;
if ( V_168 )
V_2 -> V_7 |= V_15 ;
if ( V_169 )
V_2 -> V_7 |= V_8 ;
}
if ( V_2 -> V_37 == V_60 &&
V_51 -> V_154 -> V_155 . V_170 != 0 ) {
error = - V_157 ;
goto V_171;
}
V_153 = V_81 = NULL ;
for ( V_65 = 0 ; V_65 < 2 ; V_65 ++ ) {
struct V_80 * V_172 =
& V_51 -> V_154 -> V_173 [ V_65 ] . V_155 ;
if ( F_91 ( V_172 ) )
V_153 = V_172 ;
else
V_81 = V_172 ;
}
if ( ! V_153 || ! V_81 ) {
error = - V_157 ;
goto V_171;
}
error = F_32 ( V_51 , V_2 , V_81 ) ;
if ( error )
goto V_171;
F_37 ( V_2 -> V_127 , V_83 ,
F_92 ( V_83 , V_153 -> V_89 ) ,
V_2 -> V_59 , V_84 , F_22 ,
V_2 , V_153 -> V_90 ) ;
V_2 -> V_127 -> V_91 = V_2 -> V_162 ;
V_2 -> V_127 -> V_92 |= V_93 ;
F_93 ( V_51 , V_2 ) ;
if ( V_2 -> V_37 == V_38 ) {
error = F_69 ( V_2 ) ;
if ( error )
goto V_174;
V_83 -> V_175 |= V_176 ;
} else {
error = F_9 ( V_2 ) ;
if ( error )
goto V_174;
}
return 0 ;
V_174:
F_44 ( V_2 ) ;
V_171:
F_45 ( V_2 -> V_127 ) ;
V_163:
F_39 ( V_83 , V_84 , V_2 -> V_59 , V_2 -> V_162 ) ;
V_122:
F_62 ( V_2 ) ;
return error ;
}
static void F_94 ( struct V_79 * V_51 )
{
struct V_1 * V_2 = F_95 ( V_51 ) ;
if ( V_2 -> V_37 == V_38 )
F_70 ( V_2 ) ;
F_14 ( V_2 ) ;
F_40 ( V_2 ) ;
F_44 ( V_2 ) ;
F_45 ( V_2 -> V_127 ) ;
F_39 ( V_2 -> V_83 , V_84 ,
V_2 -> V_59 , V_2 -> V_162 ) ;
F_62 ( V_2 ) ;
F_93 ( V_51 , NULL ) ;
}
static int F_96 ( struct V_79 * V_51 , T_3 V_177 )
{
struct V_1 * V_2 = F_95 ( V_51 ) ;
struct V_5 * V_178 = V_2 -> V_6 ;
if ( V_2 -> V_37 == V_38 ) {
F_70 ( V_2 ) ;
if ( V_179 && V_2 -> V_44 )
F_68 ( V_2 ) ;
} else {
F_97 ( & V_178 -> V_180 ) ;
if ( V_178 -> V_181 )
F_67 ( V_2 ) ;
F_98 ( & V_178 -> V_180 ) ;
}
F_40 ( V_2 ) ;
return 0 ;
}
static int F_99 ( struct V_79 * V_51 )
{
struct V_1 * V_2 = F_95 ( V_51 ) ;
struct V_5 * V_178 = V_2 -> V_6 ;
int V_52 = 0 ;
if ( V_2 -> V_37 == V_38 ) {
V_52 = F_69 ( V_2 ) ;
} else {
F_97 ( & V_178 -> V_180 ) ;
if ( V_178 -> V_181 ) {
V_52 = F_65 ( V_2 ) ;
} else if ( V_2 -> V_37 == V_60 ) {
V_52 = F_47 ( V_2 ) ;
}
F_98 ( & V_178 -> V_180 ) ;
}
return V_52 ;
}
