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
const struct V_62 * V_63 ;
if ( V_2 -> V_37 != V_60 )
return false ;
while ( V_2 -> V_64 < F_26 ( V_65 ) ) {
V_63 = & V_65 [ V_2 -> V_64 ++ ] ;
if ( V_63 -> V_66 != 0 &&
V_63 -> V_66 != V_2 -> V_6 -> V_67 . V_68 )
continue;
if ( V_63 -> V_69 != 0 &&
V_63 -> V_69 != V_2 -> V_6 -> V_67 . V_70 )
continue;
memcpy ( V_2 -> V_71 , V_63 -> V_4 , V_63 -> V_72 ) ;
V_2 -> V_73 -> V_74 = V_63 -> V_72 ;
V_2 -> V_71 [ 2 ] = V_2 -> V_75 ++ ;
return true ;
}
return false ;
}
static bool F_27 ( struct V_1 * V_2 )
{
struct V_76 * V_77 , * V_78 = NULL ;
int V_79 ;
if ( F_25 ( V_2 ) )
return true ;
for ( V_79 = 0 ; V_79 < V_80 ; V_79 ++ ) {
if ( ++ V_2 -> V_81 >= V_80 )
V_2 -> V_81 = 0 ;
V_77 = & V_2 -> V_82 [ V_2 -> V_81 ] ;
if ( V_77 -> V_83 ) {
F_23 ( & V_2 -> V_51 -> V_6 ,
L_5 ,
V_57 , V_2 -> V_81 ) ;
V_78 = V_77 ;
break;
}
}
if ( V_78 ) {
memcpy ( V_2 -> V_71 , V_78 -> V_4 , V_78 -> V_72 ) ;
V_2 -> V_73 -> V_74 = V_78 -> V_72 ;
V_78 -> V_83 = false ;
return true ;
}
return false ;
}
static int F_28 ( struct V_1 * V_2 )
{
int error ;
if ( ! V_2 -> V_84 && F_27 ( V_2 ) ) {
F_29 ( V_2 -> V_73 , & V_2 -> V_85 ) ;
error = F_24 ( V_2 -> V_73 , V_61 ) ;
if ( error ) {
F_10 ( & V_2 -> V_51 -> V_6 ,
L_4 ,
V_57 , error ) ;
F_30 ( V_2 -> V_73 ) ;
return - V_86 ;
}
V_2 -> V_84 = true ;
}
return 0 ;
}
static void F_31 ( struct V_48 * V_48 )
{
struct V_1 * V_2 = V_48 -> V_49 ;
struct V_50 * V_6 = & V_2 -> V_51 -> V_6 ;
int V_53 = V_48 -> V_53 ;
int error ;
unsigned long V_87 ;
F_32 ( & V_2 -> V_88 , V_87 ) ;
switch ( V_53 ) {
case 0 :
V_2 -> V_84 = F_27 ( V_2 ) ;
break;
case - V_54 :
case - V_55 :
case - V_56 :
F_23 ( V_6 , L_2 ,
V_57 , V_53 ) ;
V_2 -> V_84 = false ;
break;
default:
F_23 ( V_6 , L_3 ,
V_57 , V_53 ) ;
break;
}
if ( V_2 -> V_84 ) {
F_29 ( V_48 , & V_2 -> V_85 ) ;
error = F_24 ( V_48 , V_61 ) ;
if ( error ) {
F_10 ( V_6 ,
L_4 ,
V_57 , error ) ;
F_30 ( V_48 ) ;
V_2 -> V_84 = false ;
}
}
F_33 ( & V_2 -> V_88 , V_87 ) ;
}
static int F_34 ( struct V_89 * V_51 , struct V_1 * V_2 ,
struct V_90 * V_91 )
{
int error ;
if ( V_2 -> V_37 == V_92 )
return 0 ;
F_35 ( & V_2 -> V_85 ) ;
V_2 -> V_71 = F_36 ( V_2 -> V_93 , V_94 ,
V_95 , & V_2 -> V_96 ) ;
if ( ! V_2 -> V_71 )
return - V_97 ;
F_37 ( & V_2 -> V_88 ) ;
V_2 -> V_73 = F_38 ( 0 , V_95 ) ;
if ( ! V_2 -> V_73 ) {
error = - V_97 ;
goto V_98;
}
F_39 ( V_2 -> V_73 , V_2 -> V_93 ,
F_40 ( V_2 -> V_93 , V_91 -> V_99 ) ,
V_2 -> V_71 , V_94 ,
F_31 , V_2 , V_91 -> V_100 ) ;
V_2 -> V_73 -> V_101 = V_2 -> V_96 ;
V_2 -> V_73 -> V_102 |= V_103 ;
return 0 ;
V_98:
F_41 ( V_2 -> V_93 , V_94 , V_2 -> V_71 , V_2 -> V_96 ) ;
return error ;
}
static void F_42 ( struct V_1 * V_2 )
{
if ( V_2 -> V_37 != V_92 ) {
if ( ! F_43 ( & V_2 -> V_85 ,
5000 ) ) {
F_44 ( & V_2 -> V_51 -> V_6 ,
L_6 ) ;
F_45 ( & V_2 -> V_85 ) ;
}
}
}
static void F_46 ( struct V_1 * V_2 )
{
if ( V_2 -> V_37 != V_92 ) {
F_47 ( V_2 -> V_73 ) ;
F_41 ( V_2 -> V_93 , V_94 ,
V_2 -> V_71 , V_2 -> V_96 ) ;
}
}
static int F_48 ( struct V_1 * V_2 )
{
struct V_76 * V_78 =
& V_2 -> V_82 [ V_104 ] ;
unsigned long V_87 ;
int V_52 ;
F_32 ( & V_2 -> V_88 , V_87 ) ;
V_78 -> V_4 [ 0 ] = 0x08 ;
V_78 -> V_4 [ 1 ] = 0x00 ;
V_78 -> V_4 [ 2 ] = 0x0F ;
V_78 -> V_4 [ 3 ] = 0xC0 ;
V_78 -> V_4 [ 4 ] = 0x00 ;
V_78 -> V_4 [ 5 ] = 0x00 ;
V_78 -> V_4 [ 6 ] = 0x00 ;
V_78 -> V_4 [ 7 ] = 0x00 ;
V_78 -> V_4 [ 8 ] = 0x00 ;
V_78 -> V_4 [ 9 ] = 0x00 ;
V_78 -> V_4 [ 10 ] = 0x00 ;
V_78 -> V_4 [ 11 ] = 0x00 ;
V_78 -> V_72 = 12 ;
V_78 -> V_83 = true ;
V_2 -> V_81 = - 1 ;
V_52 = F_28 ( V_2 ) ;
F_33 ( & V_2 -> V_88 , V_87 ) ;
return V_52 ;
}
static int F_49 ( struct V_1 * V_2 )
{
unsigned long V_87 ;
int V_52 ;
F_32 ( & V_2 -> V_88 , V_87 ) ;
V_2 -> V_64 = 0 ;
V_52 = F_28 ( V_2 ) ;
F_33 ( & V_2 -> V_88 , V_87 ) ;
return V_52 ;
}
static void F_21 ( struct V_1 * V_2 , T_2 V_105 )
{
unsigned long V_87 ;
struct V_76 * V_78 =
& V_2 -> V_82 [ V_104 ] ;
static const T_2 V_106 [] = {
0x01 , 0x20 , 0x00 , 0x09 , 0x00 , 0x07 , 0x20 , 0x02 ,
0x00 , 0x00 , 0x00 , 0x00 , 0x00
} ;
F_32 ( & V_2 -> V_88 , V_87 ) ;
V_78 -> V_72 = sizeof( V_106 ) ;
memcpy ( V_78 -> V_4 , V_106 , V_78 -> V_72 ) ;
V_78 -> V_4 [ 2 ] = V_105 ;
V_78 -> V_83 = true ;
V_2 -> V_81 = - 1 ;
F_28 ( V_2 ) ;
F_33 ( & V_2 -> V_88 , V_87 ) ;
}
static int F_50 ( struct V_5 * V_6 , void * V_4 , struct V_107 * V_108 )
{
struct V_1 * V_2 = F_51 ( V_6 ) ;
struct V_76 * V_78 = & V_2 -> V_82 [ V_109 ] ;
V_47 V_110 ;
V_47 V_111 ;
int V_52 ;
unsigned long V_87 ;
if ( V_108 -> type != V_112 )
return 0 ;
V_110 = V_108 -> V_113 . V_114 . V_115 ;
V_111 = V_108 -> V_113 . V_114 . V_116 ;
F_32 ( & V_2 -> V_88 , V_87 ) ;
switch ( V_2 -> V_37 ) {
case V_117 :
V_78 -> V_4 [ 0 ] = 0x00 ;
V_78 -> V_4 [ 1 ] = 0x06 ;
V_78 -> V_4 [ 2 ] = 0x00 ;
V_78 -> V_4 [ 3 ] = V_110 / 256 ;
V_78 -> V_4 [ 4 ] = 0x00 ;
V_78 -> V_4 [ 5 ] = V_111 / 256 ;
V_78 -> V_72 = 6 ;
V_78 -> V_83 = true ;
break;
case V_58 :
V_78 -> V_4 [ 0 ] = 0x00 ;
V_78 -> V_4 [ 1 ] = 0x08 ;
V_78 -> V_4 [ 2 ] = 0x00 ;
V_78 -> V_4 [ 3 ] = V_110 / 256 ;
V_78 -> V_4 [ 4 ] = V_111 / 256 ;
V_78 -> V_4 [ 5 ] = 0x00 ;
V_78 -> V_4 [ 6 ] = 0x00 ;
V_78 -> V_4 [ 7 ] = 0x00 ;
V_78 -> V_72 = 8 ;
V_78 -> V_83 = true ;
break;
case V_38 :
V_78 -> V_4 [ 0 ] = 0x00 ;
V_78 -> V_4 [ 1 ] = 0x01 ;
V_78 -> V_4 [ 2 ] = 0x0F ;
V_78 -> V_4 [ 3 ] = 0xC0 ;
V_78 -> V_4 [ 4 ] = 0x00 ;
V_78 -> V_4 [ 5 ] = V_110 / 256 ;
V_78 -> V_4 [ 6 ] = V_111 / 256 ;
V_78 -> V_4 [ 7 ] = 0x00 ;
V_78 -> V_4 [ 8 ] = 0x00 ;
V_78 -> V_4 [ 9 ] = 0x00 ;
V_78 -> V_4 [ 10 ] = 0x00 ;
V_78 -> V_4 [ 11 ] = 0x00 ;
V_78 -> V_72 = 12 ;
V_78 -> V_83 = true ;
break;
case V_60 :
V_78 -> V_4 [ 0 ] = 0x09 ;
V_78 -> V_4 [ 1 ] = 0x00 ;
V_78 -> V_4 [ 2 ] = V_2 -> V_75 ++ ;
V_78 -> V_4 [ 3 ] = 0x09 ;
V_78 -> V_4 [ 4 ] = 0x00 ;
V_78 -> V_4 [ 5 ] = 0x0F ;
V_78 -> V_4 [ 6 ] = 0x00 ;
V_78 -> V_4 [ 7 ] = 0x00 ;
V_78 -> V_4 [ 8 ] = V_110 / 512 ;
V_78 -> V_4 [ 9 ] = V_111 / 512 ;
V_78 -> V_4 [ 10 ] = 0xFF ;
V_78 -> V_4 [ 11 ] = 0x00 ;
V_78 -> V_4 [ 12 ] = 0xFF ;
V_78 -> V_72 = 13 ;
V_78 -> V_83 = true ;
break;
default:
F_23 ( & V_2 -> V_6 -> V_6 ,
L_7 ,
V_57 , V_2 -> V_37 ) ;
V_52 = - V_118 ;
goto V_119;
}
V_52 = F_28 ( V_2 ) ;
V_119:
F_33 ( & V_2 -> V_88 , V_87 ) ;
return V_52 ;
}
static int F_52 ( struct V_1 * V_2 )
{
if ( V_2 -> V_37 == V_92 )
return 0 ;
F_53 ( V_2 -> V_6 , V_120 , V_112 ) ;
return F_54 ( V_2 -> V_6 , NULL , F_50 ) ;
}
static int F_52 ( struct V_1 * V_2 ) { return 0 ; }
static void F_55 ( struct V_1 * V_2 , int V_121 )
{
struct V_76 * V_78 =
& V_2 -> V_82 [ V_122 ] ;
unsigned long V_87 ;
V_121 %= 16 ;
F_32 ( & V_2 -> V_88 , V_87 ) ;
switch ( V_2 -> V_37 ) {
case V_58 :
V_78 -> V_4 [ 0 ] = 0x01 ;
V_78 -> V_4 [ 1 ] = 0x03 ;
V_78 -> V_4 [ 2 ] = V_121 ;
V_78 -> V_72 = 3 ;
V_78 -> V_83 = true ;
break;
case V_38 :
V_78 -> V_4 [ 0 ] = 0x00 ;
V_78 -> V_4 [ 1 ] = 0x00 ;
V_78 -> V_4 [ 2 ] = 0x08 ;
V_78 -> V_4 [ 3 ] = 0x40 + V_121 ;
V_78 -> V_4 [ 4 ] = 0x00 ;
V_78 -> V_4 [ 5 ] = 0x00 ;
V_78 -> V_4 [ 6 ] = 0x00 ;
V_78 -> V_4 [ 7 ] = 0x00 ;
V_78 -> V_4 [ 8 ] = 0x00 ;
V_78 -> V_4 [ 9 ] = 0x00 ;
V_78 -> V_4 [ 10 ] = 0x00 ;
V_78 -> V_4 [ 11 ] = 0x00 ;
V_78 -> V_72 = 12 ;
V_78 -> V_83 = true ;
break;
}
F_28 ( V_2 ) ;
F_33 ( & V_2 -> V_88 , V_87 ) ;
}
static void F_56 ( struct V_1 * V_2 )
{
F_57 ( & V_2 -> V_123 -> V_124 , ( V_2 -> V_125 % 4 ) + 2 ) ;
}
static void F_58 ( struct V_126 * V_124 ,
enum V_127 V_128 )
{
struct V_129 * V_129 = F_8 ( V_124 ,
struct V_129 , V_124 ) ;
F_55 ( V_129 -> V_2 , V_128 ) ;
}
static int F_59 ( struct V_1 * V_2 )
{
struct V_129 * V_123 ;
struct V_126 * V_124 ;
int error ;
if ( V_2 -> V_37 != V_58 && V_2 -> V_37 != V_38 )
return 0 ;
V_2 -> V_123 = V_123 = F_60 ( sizeof( struct V_129 ) , V_95 ) ;
if ( ! V_123 )
return - V_97 ;
V_2 -> V_125 = F_61 ( & V_130 , 0 , 0 , V_95 ) ;
if ( V_2 -> V_125 < 0 ) {
error = V_2 -> V_125 ;
goto V_131;
}
snprintf ( V_123 -> V_132 , sizeof( V_123 -> V_132 ) , L_8 , V_2 -> V_125 ) ;
V_123 -> V_2 = V_2 ;
V_124 = & V_123 -> V_124 ;
V_124 -> V_132 = V_123 -> V_132 ;
V_124 -> V_133 = F_58 ;
V_124 -> V_87 = V_134 ;
error = F_62 ( & V_2 -> V_93 -> V_6 , V_124 ) ;
if ( error )
goto V_135;
F_56 ( V_2 ) ;
return 0 ;
V_135:
F_63 ( & V_130 , V_2 -> V_125 ) ;
V_131:
F_64 ( V_123 ) ;
V_2 -> V_123 = NULL ;
return error ;
}
static void F_65 ( struct V_1 * V_2 )
{
struct V_129 * V_129 = V_2 -> V_123 ;
if ( V_129 ) {
F_66 ( & V_129 -> V_124 ) ;
F_63 ( & V_130 , V_2 -> V_125 ) ;
F_64 ( V_129 ) ;
}
}
static int F_59 ( struct V_1 * V_2 ) { return 0 ; }
static void F_65 ( struct V_1 * V_2 ) { }
static int F_67 ( struct V_1 * V_2 )
{
int error ;
if ( F_24 ( V_2 -> V_136 , V_95 ) )
return - V_86 ;
if ( V_2 -> V_37 == V_60 ) {
error = F_49 ( V_2 ) ;
if ( error ) {
F_68 ( V_2 -> V_136 ) ;
return error ;
}
}
return 0 ;
}
static void F_69 ( struct V_1 * V_2 )
{
F_68 ( V_2 -> V_136 ) ;
}
static void F_70 ( struct V_1 * V_2 )
{
unsigned long V_87 ;
struct V_76 * V_78 =
& V_2 -> V_82 [ V_104 ] ;
F_32 ( & V_2 -> V_88 , V_87 ) ;
V_78 -> V_4 [ 0 ] = 0x00 ;
V_78 -> V_4 [ 1 ] = 0x00 ;
V_78 -> V_4 [ 2 ] = 0x08 ;
V_78 -> V_4 [ 3 ] = 0xC0 ;
V_78 -> V_4 [ 4 ] = 0x00 ;
V_78 -> V_4 [ 5 ] = 0x00 ;
V_78 -> V_4 [ 6 ] = 0x00 ;
V_78 -> V_4 [ 7 ] = 0x00 ;
V_78 -> V_4 [ 8 ] = 0x00 ;
V_78 -> V_4 [ 9 ] = 0x00 ;
V_78 -> V_4 [ 10 ] = 0x00 ;
V_78 -> V_4 [ 11 ] = 0x00 ;
V_78 -> V_72 = 12 ;
V_78 -> V_83 = true ;
V_2 -> V_81 = - 1 ;
F_28 ( V_2 ) ;
F_33 ( & V_2 -> V_88 , V_87 ) ;
}
static int F_71 ( struct V_1 * V_2 )
{
int error ;
error = F_24 ( V_2 -> V_136 , V_95 ) ;
if ( error )
return - V_86 ;
error = F_48 ( V_2 ) ;
if ( error ) {
F_68 ( V_2 -> V_136 ) ;
return error ;
}
return 0 ;
}
static void F_72 ( struct V_1 * V_2 )
{
F_68 ( V_2 -> V_136 ) ;
F_73 ( & V_2 -> V_43 ) ;
}
static int F_74 ( struct V_5 * V_6 )
{
struct V_1 * V_2 = F_51 ( V_6 ) ;
return F_67 ( V_2 ) ;
}
static void F_75 ( struct V_5 * V_6 )
{
struct V_1 * V_2 = F_51 ( V_6 ) ;
F_69 ( V_2 ) ;
}
static void F_76 ( struct V_5 * V_5 , signed short abs )
{
struct V_1 * V_2 = F_51 ( V_5 ) ;
F_77 ( abs , V_5 -> V_137 ) ;
switch ( abs ) {
case V_9 :
case V_12 :
case V_13 :
case V_14 :
F_78 ( V_5 , abs , - 32768 , 32767 , 16 , 128 ) ;
break;
case V_18 :
case V_19 :
if ( V_2 -> V_37 == V_60 )
F_78 ( V_5 , abs , 0 , 1023 , 0 , 0 ) ;
else
F_78 ( V_5 , abs , 0 , 255 , 0 , 0 ) ;
break;
case V_25 :
case V_26 :
F_78 ( V_5 , abs , - 1 , 1 , 0 , 0 ) ;
break;
}
}
static void F_14 ( struct V_1 * V_2 )
{
if ( V_2 -> V_138 ) {
V_2 -> V_138 = false ;
F_65 ( V_2 ) ;
F_79 ( V_2 -> V_6 ) ;
}
}
static int F_9 ( struct V_1 * V_2 )
{
struct V_5 * V_5 ;
int V_79 , error ;
V_5 = F_80 () ;
if ( ! V_5 )
return - V_97 ;
V_2 -> V_6 = V_5 ;
V_5 -> V_132 = V_2 -> V_132 ;
V_5 -> V_139 = V_2 -> V_139 ;
F_81 ( V_2 -> V_93 , & V_5 -> V_67 ) ;
if ( V_2 -> V_37 == V_38 ) {
V_5 -> V_67 . V_70 = 0x02a1 ;
}
V_5 -> V_6 . V_140 = & V_2 -> V_51 -> V_6 ;
F_82 ( V_5 , V_2 ) ;
if ( V_2 -> V_37 != V_38 ) {
V_5 -> V_141 = F_74 ;
V_5 -> V_142 = F_75 ;
}
F_83 ( V_143 , V_5 -> V_144 ) ;
if ( ! ( V_2 -> V_7 & V_8 ) ) {
F_83 ( V_145 , V_5 -> V_144 ) ;
for ( V_79 = 0 ; V_146 [ V_79 ] >= 0 ; V_79 ++ )
F_76 ( V_5 , V_146 [ V_79 ] ) ;
}
for ( V_79 = 0 ; V_147 [ V_79 ] >= 0 ; V_79 ++ )
F_83 ( V_147 [ V_79 ] , V_5 -> V_148 ) ;
if ( V_2 -> V_37 == V_58 || V_2 -> V_37 == V_38 ||
V_2 -> V_37 == V_60 ) {
for ( V_79 = 0 ; V_149 [ V_79 ] >= 0 ; V_79 ++ )
F_83 ( V_149 [ V_79 ] , V_5 -> V_148 ) ;
} else {
for ( V_79 = 0 ; V_150 [ V_79 ] >= 0 ; V_79 ++ )
F_83 ( V_150 [ V_79 ] , V_5 -> V_148 ) ;
}
if ( V_2 -> V_7 & V_20 ) {
for ( V_79 = 0 ; V_151 [ V_79 ] >= 0 ; V_79 ++ )
F_83 ( V_151 [ V_79 ] , V_5 -> V_148 ) ;
}
if ( ! ( V_2 -> V_7 & V_20 ) ||
V_2 -> V_37 == V_38 ) {
for ( V_79 = 0 ; V_152 [ V_79 ] >= 0 ; V_79 ++ )
F_76 ( V_5 , V_152 [ V_79 ] ) ;
}
if ( V_2 -> V_7 & V_15 ) {
for ( V_79 = 0 ; V_153 [ V_79 ] >= 0 ; V_79 ++ )
F_83 ( V_153 [ V_79 ] , V_5 -> V_148 ) ;
} else {
for ( V_79 = 0 ; V_154 [ V_79 ] >= 0 ; V_79 ++ )
F_76 ( V_5 , V_154 [ V_79 ] ) ;
}
error = F_52 ( V_2 ) ;
if ( error )
goto V_155;
error = F_59 ( V_2 ) ;
if ( error )
goto V_156;
error = F_84 ( V_2 -> V_6 ) ;
if ( error )
goto V_157;
V_2 -> V_138 = true ;
return 0 ;
V_157:
F_65 ( V_2 ) ;
V_156:
F_85 ( V_5 ) ;
V_155:
F_86 ( V_5 ) ;
return error ;
}
static int F_87 ( struct V_89 * V_51 , const struct V_158 * V_67 )
{
struct V_159 * V_93 = F_88 ( V_51 ) ;
struct V_1 * V_2 ;
struct V_90 * V_160 , * V_91 ;
int V_79 , error ;
if ( V_51 -> V_161 -> V_162 . V_163 != 2 )
return - V_164 ;
for ( V_79 = 0 ; V_165 [ V_79 ] . V_66 ; V_79 ++ ) {
if ( ( F_89 ( V_93 -> V_166 . V_66 ) == V_165 [ V_79 ] . V_66 ) &&
( F_89 ( V_93 -> V_166 . V_69 ) == V_165 [ V_79 ] . V_69 ) )
break;
}
V_2 = F_60 ( sizeof( struct V_1 ) , V_95 ) ;
if ( ! V_2 )
return - V_97 ;
F_90 ( V_93 , V_2 -> V_139 , sizeof( V_2 -> V_139 ) ) ;
F_91 ( V_2 -> V_139 , L_9 , sizeof( V_2 -> V_139 ) ) ;
V_2 -> V_59 = F_36 ( V_93 , V_94 ,
V_95 , & V_2 -> V_167 ) ;
if ( ! V_2 -> V_59 ) {
error = - V_97 ;
goto V_131;
}
V_2 -> V_136 = F_38 ( 0 , V_95 ) ;
if ( ! V_2 -> V_136 ) {
error = - V_97 ;
goto V_168;
}
V_2 -> V_93 = V_93 ;
V_2 -> V_51 = V_51 ;
V_2 -> V_7 = V_165 [ V_79 ] . V_7 ;
V_2 -> V_37 = V_165 [ V_79 ] . V_37 ;
V_2 -> V_132 = V_165 [ V_79 ] . V_132 ;
F_92 ( & V_2 -> V_43 , F_7 ) ;
if ( V_2 -> V_37 == V_92 ) {
if ( V_51 -> V_161 -> V_162 . V_169 == V_170 ) {
if ( V_51 -> V_161 -> V_162 . V_171 == 129 )
V_2 -> V_37 = V_38 ;
else if ( V_51 -> V_161 -> V_162 . V_171 == 208 )
V_2 -> V_37 = V_60 ;
else
V_2 -> V_37 = V_58 ;
} else {
V_2 -> V_37 = V_117 ;
}
if ( V_172 )
V_2 -> V_7 |= V_20 ;
if ( V_173 )
V_2 -> V_7 |= V_15 ;
if ( V_174 )
V_2 -> V_7 |= V_8 ;
}
if ( V_2 -> V_37 == V_60 &&
V_51 -> V_161 -> V_162 . V_175 != 0 ) {
error = - V_164 ;
goto V_176;
}
V_160 = V_91 = NULL ;
for ( V_79 = 0 ; V_79 < 2 ; V_79 ++ ) {
struct V_90 * V_177 =
& V_51 -> V_161 -> V_178 [ V_79 ] . V_162 ;
if ( F_93 ( V_177 ) )
V_160 = V_177 ;
else
V_91 = V_177 ;
}
if ( ! V_160 || ! V_91 ) {
error = - V_164 ;
goto V_176;
}
error = F_34 ( V_51 , V_2 , V_91 ) ;
if ( error )
goto V_176;
F_39 ( V_2 -> V_136 , V_93 ,
F_94 ( V_93 , V_160 -> V_99 ) ,
V_2 -> V_59 , V_94 , F_22 ,
V_2 , V_160 -> V_100 ) ;
V_2 -> V_136 -> V_101 = V_2 -> V_167 ;
V_2 -> V_136 -> V_102 |= V_103 ;
F_95 ( V_51 , V_2 ) ;
if ( V_2 -> V_37 == V_38 ) {
error = F_71 ( V_2 ) ;
if ( error )
goto V_179;
V_93 -> V_180 |= V_181 ;
} else {
error = F_9 ( V_2 ) ;
if ( error )
goto V_179;
}
return 0 ;
V_179:
F_46 ( V_2 ) ;
V_176:
F_47 ( V_2 -> V_136 ) ;
V_168:
F_41 ( V_93 , V_94 , V_2 -> V_59 , V_2 -> V_167 ) ;
V_131:
F_64 ( V_2 ) ;
return error ;
}
static void F_96 ( struct V_89 * V_51 )
{
struct V_1 * V_2 = F_97 ( V_51 ) ;
if ( V_2 -> V_37 == V_38 )
F_72 ( V_2 ) ;
F_14 ( V_2 ) ;
F_42 ( V_2 ) ;
F_46 ( V_2 ) ;
F_47 ( V_2 -> V_136 ) ;
F_41 ( V_2 -> V_93 , V_94 ,
V_2 -> V_59 , V_2 -> V_167 ) ;
F_64 ( V_2 ) ;
F_95 ( V_51 , NULL ) ;
}
static int F_98 ( struct V_89 * V_51 , T_3 V_182 )
{
struct V_1 * V_2 = F_97 ( V_51 ) ;
struct V_5 * V_183 = V_2 -> V_6 ;
if ( V_2 -> V_37 == V_38 ) {
F_72 ( V_2 ) ;
if ( V_184 && V_2 -> V_44 )
F_70 ( V_2 ) ;
} else {
F_99 ( & V_183 -> V_185 ) ;
if ( V_183 -> V_186 )
F_69 ( V_2 ) ;
F_100 ( & V_183 -> V_185 ) ;
}
F_42 ( V_2 ) ;
return 0 ;
}
static int F_101 ( struct V_89 * V_51 )
{
struct V_1 * V_2 = F_97 ( V_51 ) ;
struct V_5 * V_183 = V_2 -> V_6 ;
int V_52 = 0 ;
if ( V_2 -> V_37 == V_38 ) {
V_52 = F_71 ( V_2 ) ;
} else {
F_99 ( & V_183 -> V_185 ) ;
if ( V_183 -> V_186 ) {
V_52 = F_67 ( V_2 ) ;
} else if ( V_2 -> V_37 == V_60 ) {
V_52 = F_49 ( V_2 ) ;
}
F_100 ( & V_183 -> V_185 ) ;
}
return V_52 ;
}
