static void T_1 F_1 ( void )
{
if ( ! V_1 )
return;
if ( V_2 -> V_3 )
V_1 -> V_4 |= V_5 ;
if ( V_2 -> V_6 )
V_1 -> V_4 |= V_7 ;
}
static int T_1 F_2 ( const struct V_8 * V_9 )
{
V_2 = V_9 -> V_10 ;
return 1 ;
}
static int T_1
F_3 ( const struct V_8 * V_11 )
{
V_1 -> V_4 &= ~ V_7 ;
F_4 ( L_1 ) ;
return 0 ;
}
static void T_1 F_5 ( void )
{
if ( ! V_12 ) {
F_6 ( V_13 ) ;
F_6 ( V_14 ) ;
} else if ( V_12 == 2490 ) {
V_2 = & V_15 ;
}
if ( V_2 == NULL )
V_2 = & V_16 ;
F_1 () ;
}
static bool F_7 ( T_2 V_17 )
{
if ( ( V_1 -> V_4 & V_17 ) != 0 )
return 1 ;
return 0 ;
}
static T_3 F_8 ( struct V_18 * V_19 ,
struct V_20 * V_21 )
{
struct V_20 V_22 ;
T_3 V_23 ;
V_22 . V_24 = sizeof( struct V_18 ) ;
V_22 . V_25 = ( V_26 * ) V_19 ;
V_23 = F_9 ( V_27 , 1 , 1 , & V_22 , V_21 ) ;
return V_23 ;
}
static T_3 F_10 ( T_2 * V_28 , T_2 V_17 )
{
int V_29 ;
V_26 V_21 ;
switch ( V_17 ) {
case V_5 :
switch ( V_2 -> V_3 ) {
default:
V_29 = F_11 ( 0xA , & V_21 ) ;
if ( V_29 )
return V_30 ;
* V_28 = ( V_21 >> 7 ) & 0x1 ;
return V_31 ;
}
break;
case V_32 :
switch ( V_2 -> V_33 ) {
case 1 :
V_29 = F_11 ( 0x7B , & V_21 ) ;
if ( V_29 )
return V_30 ;
* V_28 = V_21 & 0x1 ;
return V_31 ;
case 2 :
V_29 = F_11 ( 0x71 , & V_21 ) ;
if ( V_29 )
return V_30 ;
* V_28 = V_21 & 0x1 ;
return V_31 ;
case 3 :
V_29 = F_11 ( 0x78 , & V_21 ) ;
if ( V_29 )
return V_30 ;
* V_28 = V_21 & 0x1 ;
return V_31 ;
default:
V_29 = F_11 ( 0xA , & V_21 ) ;
if ( V_29 )
return V_30 ;
* V_28 = ( V_21 >> 2 ) & 0x1 ;
return V_31 ;
}
break;
case V_34 :
switch ( V_2 -> V_35 ) {
default:
V_29 = F_11 ( 0xA , & V_21 ) ;
if ( V_29 )
return V_30 ;
* V_28 = ( V_21 >> 4 ) & 0x1 ;
return V_31 ;
}
break;
case V_7 :
switch ( V_2 -> V_6 ) {
default:
V_29 = F_11 ( 0x83 , & V_21 ) ;
if ( V_29 )
return V_30 ;
* V_28 = V_21 ;
return V_31 ;
}
break;
default:
return V_30 ;
}
return V_31 ;
}
static T_3 F_12 ( T_2 V_28 , T_2 V_17 )
{
struct V_18 args ;
args . V_36 = V_37 ;
args . V_38 = V_28 ? ( 1 << 8 ) : 0 ;
args . V_39 = args . V_40 = 0 ;
switch ( V_17 ) {
case V_5 :
if ( V_28 > 1 )
return V_41 ;
args . V_38 |= V_42 ;
break;
case V_32 :
if ( V_28 > 1 )
return V_41 ;
args . V_38 |= V_43 ;
break;
case V_34 :
if ( V_28 > 1 )
return V_41 ;
args . V_38 |= V_44 ;
break;
case V_7 :
if ( V_28 > V_45 )
return V_41 ;
switch ( V_2 -> V_6 ) {
default:
return F_13 ( 0x83 , V_28 ) ;
break;
}
default:
return V_30 ;
}
return F_8 ( & args , NULL ) ;
}
static T_3 T_1 F_14 ( void )
{
struct V_18 args ;
struct V_46 V_47 ;
T_3 V_23 = V_31 ;
struct V_20 V_48 = { V_49 , NULL } ;
union V_50 * V_51 ;
args . V_36 = 0x86 ;
args . V_38 = args . V_39 = args . V_40 = 0 ;
V_23 = F_8 ( & args , & V_48 ) ;
if ( F_15 ( V_23 ) )
return V_23 ;
V_51 = (union V_50 * ) V_48 . V_25 ;
if ( V_51 && V_51 -> type == V_52 &&
V_51 -> V_53 . V_24 == sizeof( struct V_46 ) ) {
V_47 = * ( (struct V_46 * ) V_51 -> V_53 . V_25 ) ;
} else {
F_16 ( V_48 . V_25 ) ;
return V_30 ;
}
if ( V_47 . V_54 & 0x1 )
V_1 -> V_4 |= V_5 ;
F_16 ( V_48 . V_25 ) ;
return V_31 ;
}
static int T_1 F_17 ( void )
{
const struct V_55 * V_56 ;
for ( V_56 = V_57 ; V_56 -> V_56 [ 0 ] ; V_56 ++ )
if ( F_18 ( V_56 -> V_56 ) )
return true ;
return false ;
}
static T_3 T_1 F_19 ( void )
{
struct V_18 args ;
struct V_46 V_47 ;
T_3 V_23 ;
struct V_20 V_48 = { V_49 , NULL } ;
union V_50 * V_51 ;
if ( F_20 ( V_58 ) ) {
if ( ( V_2 != & V_16 ) ||
! F_17 () )
V_1 -> V_4 |= V_32 ;
return V_31 ;
}
args . V_36 = V_37 ;
args . V_39 = args . V_40 = 0 ;
args . V_38 = 0xa2 << 8 ;
args . V_38 |= V_43 ;
V_23 = F_8 ( & args , & V_48 ) ;
if ( F_15 ( V_23 ) )
return V_23 ;
V_51 = V_48 . V_25 ;
if ( V_51 && V_51 -> type == V_52 &&
V_51 -> V_53 . V_24 == sizeof( struct V_46 ) ) {
V_47 = * ( (struct V_46 * ) V_51 -> V_53 . V_25 ) ;
} else {
V_23 = V_30 ;
goto V_48;
}
if ( V_47 . V_36 & 0x1 )
V_1 -> V_4 |= V_32 ;
args . V_38 = 2 << 8 ;
args . V_38 |= V_44 ;
V_23 = F_8 ( & args , & V_48 ) ;
if ( F_15 ( V_23 ) )
goto V_48;
V_51 = (union V_50 * ) V_48 . V_25 ;
if ( V_51 && V_51 -> type == V_52
&& V_51 -> V_53 . V_24 == sizeof( struct V_46 ) ) {
V_47 = * ( (struct V_46 * ) V_51 -> V_53 . V_25 ) ;
} else {
V_23 = V_30 ;
goto V_48;
}
if ( V_47 . V_36 & 0x1 )
V_1 -> V_4 |= V_34 ;
if ( V_2 -> V_6 >= 0 )
V_1 -> V_4 |= V_7 ;
V_23 = V_31 ;
V_48:
F_16 ( V_48 . V_25 ) ;
return V_23 ;
}
static T_3
F_21 ( T_2 V_59 , T_2 V_60 , T_2 * V_48 )
{
struct V_20 V_22 = { ( V_61 ) sizeof( T_2 ) , ( void * ) ( & V_60 ) } ;
struct V_20 V_21 = { V_49 , NULL } ;
union V_50 * V_51 ;
T_2 V_62 = 0 ;
T_3 V_23 ;
V_23 = F_9 ( V_63 , 1 , V_59 , & V_22 , & V_21 ) ;
if ( F_15 ( V_23 ) )
return V_23 ;
V_51 = (union V_50 * ) V_21 . V_25 ;
if ( V_51 ) {
if ( V_51 -> type == V_52 &&
( V_51 -> V_53 . V_24 == sizeof( T_2 ) ||
V_51 -> V_53 . V_24 == sizeof( V_64 ) ) ) {
V_62 = * ( ( T_2 * ) V_51 -> V_53 . V_25 ) ;
} else if ( V_51 -> type == V_65 ) {
V_62 = ( T_2 ) V_51 -> integer . V_28 ;
}
}
if ( V_48 )
* V_48 = V_62 ;
F_16 ( V_21 . V_25 ) ;
return V_23 ;
}
static T_3 F_22 ( T_2 * V_28 , T_2 V_17 )
{
T_3 V_23 ;
V_26 V_62 ;
T_2 V_21 , V_59 = 0 ;
switch ( V_17 ) {
case V_32 :
V_59 = V_66 ;
break;
case V_34 :
V_59 = V_67 ;
break;
case V_7 :
V_59 = V_68 ;
break;
case V_69 :
V_59 = V_70 ;
break;
case V_5 :
if ( V_2 -> V_3 == 1 ) {
F_11 ( 0x9f , & V_62 ) ;
* V_28 = V_62 & 0x1 ;
return 0 ;
}
default:
return V_30 ;
}
V_23 = F_21 ( V_59 , 0 , & V_21 ) ;
if ( F_23 ( V_23 ) )
* V_28 = ( V_26 ) V_21 ;
return V_23 ;
}
static T_3 F_24 ( T_2 V_28 , T_2 V_17 )
{
T_2 V_59 = 0 ;
char V_71 ;
switch ( V_17 ) {
case V_7 :
if ( V_28 > V_45 )
return V_41 ;
V_59 = V_72 ;
break;
case V_32 :
if ( V_28 > 1 )
return V_41 ;
V_59 = V_73 ;
break;
case V_34 :
if ( V_28 > 1 )
return V_41 ;
V_59 = V_74 ;
break;
case V_69 :
if ( V_28 > 1 )
return V_41 ;
V_59 = V_75 ;
break;
case V_5 :
if ( V_28 > 1 )
return V_41 ;
if ( V_2 -> V_3 == 1 ) {
V_71 = V_28 ? 0x92 : 0x93 ;
F_25 () ;
F_26 ( & V_71 , 0x1059 ) ;
F_27 () ;
return 0 ;
}
break;
default:
return V_30 ;
}
return F_21 ( V_59 , ( T_2 ) V_28 , NULL ) ;
}
static T_3 F_28 ( T_2 * V_28 , T_4 V_76 )
{
struct V_77 V_78 ;
T_3 V_23 ;
union V_50 * V_51 ;
struct V_79 V_80 = {
. V_81 = 0x1 ,
. V_82 = V_83 ,
. V_84 = V_76 ,
} ;
struct V_20 V_22 = {
sizeof( struct V_79 ) ,
& V_80
} ;
struct V_20 V_85 = { V_49 , NULL } ;
V_23 = F_9 ( V_86 , 0 , 0x2 , & V_22 , & V_85 ) ;
if ( F_15 ( V_23 ) )
return V_23 ;
V_51 = V_85 . V_25 ;
if ( ! V_51 )
return V_30 ;
else if ( V_51 -> type != V_52 ) {
F_16 ( V_51 ) ;
return V_30 ;
}
if ( V_51 -> V_53 . V_24 != 8 ) {
F_29 ( L_2 , V_51 -> V_53 . V_24 ) ;
F_16 ( V_51 ) ;
return V_30 ;
}
V_78 = * ( (struct V_77 * ) V_51 -> V_53 . V_25 ) ;
F_16 ( V_51 ) ;
if ( V_78 . V_87 || V_78 . V_88 )
F_29 ( L_3 ,
V_76 ,
V_78 . V_87 ,
V_78 . V_88 ) ;
else
* V_28 = ! ! ( V_78 . V_84 & V_76 ) ;
return V_23 ;
}
static T_3 F_30 ( T_2 * V_28 , T_2 V_17 )
{
T_4 V_76 ;
switch ( V_17 ) {
case V_32 :
V_76 = V_89 ;
break;
case V_34 :
V_76 = V_90 ;
break;
case V_69 :
V_76 = V_91 ;
break;
default:
return V_30 ;
}
return F_28 ( V_28 , V_76 ) ;
}
static T_3 F_31 ( T_2 V_28 , T_4 V_76 )
{
struct V_77 V_78 ;
T_3 V_23 ;
union V_50 * V_51 ;
T_4 V_84 ;
struct V_79 V_92 = {
. V_81 = 0x1 ,
. V_82 = V_83 ,
. V_84 = V_93 ,
} ;
struct V_20 V_94 = {
sizeof( struct V_79 ) ,
& V_92
} ;
struct V_95 V_96 = {
. V_81 = 0x2 ,
. V_82 = V_83 ,
. V_84 = V_93 ,
} ;
struct V_20 V_97 = {
sizeof( struct V_95 ) ,
& V_96
} ;
struct V_20 V_85 = { V_49 , NULL } ;
struct V_20 V_98 = { V_49 , NULL } ;
V_23 = F_9 ( V_86 , 0 , 0x2 , & V_94 , & V_85 ) ;
if ( F_15 ( V_23 ) )
return V_23 ;
V_51 = V_85 . V_25 ;
if ( ! V_51 )
return V_30 ;
else if ( V_51 -> type != V_52 ) {
F_16 ( V_51 ) ;
return V_30 ;
}
if ( V_51 -> V_53 . V_24 != 8 ) {
F_29 ( L_2 , V_51 -> V_53 . V_24 ) ;
F_16 ( V_51 ) ;
return V_30 ;
}
V_78 = * ( (struct V_77 * ) V_51 -> V_53 . V_25 ) ;
F_16 ( V_51 ) ;
if ( V_78 . V_87 || V_78 . V_88 ) {
F_29 ( L_4 ,
V_78 . V_87 ,
V_78 . V_88 ) ;
return V_23 ;
}
V_84 = V_78 . V_84 ;
V_96 . V_84 = ( V_28 ) ? ( V_84 | V_76 ) : ( V_84 & ~ V_76 ) ;
V_23 = F_9 ( V_86 , 0 , 0x1 , & V_97 , & V_98 ) ;
if ( F_15 ( V_23 ) )
return V_23 ;
V_51 = V_98 . V_25 ;
if ( ! V_51 )
return V_30 ;
else if ( V_51 -> type != V_52 ) {
F_16 ( V_51 ) ;
return V_30 ;
}
if ( V_51 -> V_53 . V_24 != 4 ) {
F_29 ( L_2 , V_51 -> V_53 . V_24 ) ;
F_16 ( V_51 ) ;
return V_30 ;
}
V_78 = * ( (struct V_77 * ) V_51 -> V_53 . V_25 ) ;
F_16 ( V_51 ) ;
if ( V_78 . V_87 || V_78 . V_88 )
F_29 ( L_5 ,
V_78 . V_87 ,
V_78 . V_88 ) ;
return V_23 ;
}
static T_3 F_32 ( T_2 V_28 , T_2 V_17 )
{
T_4 V_76 ;
switch ( V_17 ) {
case V_32 :
V_76 = V_89 ;
break;
case V_34 :
V_76 = V_90 ;
break;
case V_69 :
V_76 = V_91 ;
break;
default:
return V_30 ;
}
return F_31 ( V_28 , V_76 ) ;
}
static void T_1 F_33 ( const struct V_99 * V_100 , void * V_11 )
{
struct V_101 * V_102 ;
if ( V_100 -> type != 0xAA )
return;
V_103 = true ;
V_102 = (struct V_101 * ) V_100 ;
F_4 ( L_6 ,
V_102 -> V_93 ) ;
V_93 = V_102 -> V_93 ;
if ( V_102 -> V_93 & V_89 )
V_1 -> V_4 |= V_32 ;
if ( V_102 -> V_93 & V_91 )
V_1 -> V_4 |= V_69 ;
if ( V_102 -> V_93 & V_90 )
V_1 -> V_4 |= V_34 ;
V_83 = V_102 -> V_83 ;
}
static T_3 T_1 F_34 ( void )
{
struct V_20 V_48 = { V_49 , NULL } ;
union V_50 * V_51 ;
T_3 V_23 ;
T_2 V_84 ;
V_23 = F_35 ( V_104 , 1 , & V_48 ) ;
if ( F_15 ( V_23 ) )
return V_23 ;
V_51 = (union V_50 * ) V_48 . V_25 ;
if ( V_51 ) {
if ( V_51 -> type == V_52 &&
( V_51 -> V_53 . V_24 == sizeof( T_2 ) ||
V_51 -> V_53 . V_24 == sizeof( V_64 ) ) ) {
V_84 = * ( ( T_2 * ) V_51 -> V_53 . V_25 ) ;
} else if ( V_51 -> type == V_65 ) {
V_84 = ( T_2 ) V_51 -> integer . V_28 ;
} else {
F_16 ( V_48 . V_25 ) ;
return V_30 ;
}
} else {
F_16 ( V_48 . V_25 ) ;
return V_30 ;
}
F_4 ( L_7 , V_84 ) ;
if ( V_84 & 0x07 )
V_1 -> V_4 |= V_32 ;
if ( V_84 & 0x40 )
V_1 -> V_4 |= V_69 ;
if ( V_84 & 0x10 )
V_1 -> V_4 |= V_34 ;
if ( ! ( V_84 & 0x20 ) )
V_45 = 0x9 ;
F_16 ( V_48 . V_25 ) ;
return V_23 ;
}
static T_3 F_36 ( T_2 * V_28 , T_2 V_17 )
{
T_3 V_23 = V_30 ;
switch ( V_1 -> type ) {
case V_105 :
V_23 = F_10 ( V_28 , V_17 ) ;
break;
case V_106 :
if ( V_17 == V_5 ) {
V_23 = F_10 ( V_28 , V_17 ) ;
break;
}
case V_107 :
V_23 = F_22 ( V_28 , V_17 ) ;
break;
case V_108 :
if ( V_17 & ( V_32 |
V_34 |
V_69 ) )
V_23 = F_30 ( V_28 , V_17 ) ;
else if ( F_20 ( V_104 ) )
V_23 = F_22 ( V_28 , V_17 ) ;
break;
}
return V_23 ;
}
static T_3 F_37 ( T_2 V_28 , T_2 V_17 )
{
T_3 V_23 ;
if ( V_1 -> V_4 & V_17 ) {
switch ( V_1 -> type ) {
case V_105 :
return F_12 ( V_28 , V_17 ) ;
case V_106 :
if ( V_17 == V_5 )
return F_12 ( V_28 , V_17 ) ;
if ( V_17 == V_32 ||
V_17 == V_34 ) {
V_23 = F_24 ( V_28 , V_17 ) ;
if ( F_15 ( V_23 ) )
return V_23 ;
return F_12 ( V_28 , V_17 ) ;
}
case V_107 :
return F_24 ( V_28 , V_17 ) ;
case V_108 :
if ( V_17 & ( V_32 |
V_34 |
V_69 ) )
return F_32 ( V_28 , V_17 ) ;
else if ( F_20 ( V_104 ) )
return F_24 ( V_28 , V_17 ) ;
default:
return V_41 ;
}
}
return V_41 ;
}
static void T_1 F_38 ( void )
{
if ( V_3 >= 0 )
F_37 ( V_3 , V_5 ) ;
if ( ! V_103 && V_109 >= 0 )
F_37 ( V_109 , V_69 ) ;
if ( V_6 >= 0 )
F_37 ( V_6 , V_7 ) ;
}
static void F_39 ( struct V_110 * V_111 ,
enum V_112 V_28 )
{
F_37 ( V_28 , V_5 ) ;
}
static int F_40 ( struct V_76 * V_113 )
{
return F_41 ( V_113 , & V_114 ) ;
}
static void F_42 ( void )
{
F_37 ( V_115 , V_5 ) ;
F_43 ( & V_114 ) ;
}
static int F_44 ( struct V_116 * V_117 )
{
T_2 V_28 ;
F_36 ( & V_28 , V_7 ) ;
return V_28 ;
}
static int F_45 ( struct V_116 * V_117 )
{
int V_118 = V_117 -> V_119 . V_6 ;
if ( V_117 -> V_119 . V_120 != V_121 )
V_118 = 0 ;
if ( V_117 -> V_119 . V_122 != V_121 )
V_118 = 0 ;
F_37 ( V_118 , V_7 ) ;
return 0 ;
}
static int F_46 ( struct V_76 * V_113 )
{
struct V_123 V_119 ;
struct V_116 * V_117 ;
memset ( & V_119 , 0 , sizeof( struct V_123 ) ) ;
V_119 . type = V_124 ;
V_119 . V_45 = V_45 ;
V_117 = F_47 ( L_8 , V_113 , NULL , & V_125 ,
& V_119 ) ;
if ( F_48 ( V_117 ) ) {
F_49 ( L_9 ) ;
V_126 = NULL ;
return F_50 ( V_117 ) ;
}
V_126 = V_117 ;
V_117 -> V_119 . V_120 = V_121 ;
V_117 -> V_119 . V_6 = F_44 ( V_117 ) ;
F_51 ( V_117 ) ;
return 0 ;
}
static void F_52 ( void )
{
F_53 ( V_126 ) ;
}
static int F_54 ( void )
{
T_3 V_23 ;
struct V_20 V_85 ;
union V_50 V_127 ;
V_85 . V_24 = sizeof( V_127 ) ;
V_85 . V_25 = & V_127 ;
V_23 = F_55 ( V_128 , L_10 , NULL , & V_85 ) ;
if ( F_15 ( V_23 ) )
return - 1 ;
return 0 ;
}
static int F_56 ( struct V_129 * V_22 )
{
return F_54 () ;
}
static int F_57 ( void )
{
T_3 V_23 ;
struct V_20 V_85 ;
union V_50 V_127 [ 5 ] ;
if ( ! F_7 ( V_130 ) )
return - 1 ;
V_85 . V_24 = sizeof( V_127 ) ;
V_85 . V_25 = V_127 ;
V_23 = F_55 ( V_128 , L_11 , NULL , & V_85 ) ;
if ( F_15 ( V_23 ) )
return - 1 ;
if ( V_127 -> V_131 . V_132 != 4 )
return - 1 ;
F_58 ( V_133 , V_134 ,
( V_135 ) V_127 -> V_131 . V_136 [ 0 ] . integer . V_28 ) ;
F_58 ( V_133 , V_137 ,
( V_135 ) V_127 -> V_131 . V_136 [ 1 ] . integer . V_28 ) ;
F_58 ( V_133 , V_138 ,
( V_135 ) V_127 -> V_131 . V_136 [ 2 ] . integer . V_28 ) ;
F_59 ( V_133 ) ;
return 0 ;
}
static void F_60 ( struct V_139 * V_140 )
{
T_2 V_141 ;
T_3 V_23 ;
if ( F_7 ( V_32 ) ) {
V_23 = F_36 ( & V_141 , V_32 ) ;
if ( F_23 ( V_23 ) ) {
if ( V_2 -> V_33 == 3 )
F_61 ( V_142 , ! V_141 ) ;
else
F_62 ( V_142 , ! V_141 ) ;
}
}
if ( F_7 ( V_34 ) ) {
V_23 = F_36 ( & V_141 , V_34 ) ;
if ( F_23 ( V_23 ) )
F_62 ( V_143 , ! V_141 ) ;
}
if ( F_7 ( V_69 ) && F_20 ( V_86 ) ) {
V_23 = F_36 ( & V_141 , V_91 ) ;
if ( F_23 ( V_23 ) )
F_62 ( V_144 , ! V_141 ) ;
}
F_63 ( & V_145 , F_64 ( V_146 ) ) ;
}
static int F_65 ( void * V_147 , bool V_148 )
{
T_3 V_23 ;
T_2 V_17 = ( unsigned long ) V_147 ;
if ( V_149 ) {
V_23 = F_37 ( ! V_148 , V_17 ) ;
if ( F_15 ( V_23 ) )
return - V_150 ;
}
return 0 ;
}
static struct V_151 * F_66 ( struct V_76 * V_113 ,
enum V_152 type ,
char * V_153 , T_2 V_17 )
{
int V_29 ;
struct V_151 * V_154 ;
T_2 V_141 ;
T_3 V_23 ;
V_154 = F_67 ( V_153 , V_113 , type ,
& V_155 ,
( void * ) ( unsigned long ) V_17 ) ;
if ( ! V_154 )
return F_68 ( - V_156 ) ;
V_23 = F_36 ( & V_141 , V_17 ) ;
V_29 = F_69 ( V_154 ) ;
if ( V_29 ) {
F_70 ( V_154 ) ;
return F_68 ( V_29 ) ;
}
if ( F_23 ( V_23 ) )
F_62 ( V_154 , ! V_141 ) ;
return V_154 ;
}
static int F_71 ( struct V_76 * V_113 )
{
int V_29 ;
if ( F_7 ( V_32 ) ) {
V_142 = F_66 ( V_113 , V_157 ,
L_12 , V_32 ) ;
if ( F_48 ( V_142 ) ) {
V_29 = F_50 ( V_142 ) ;
goto V_158;
}
}
if ( F_7 ( V_34 ) ) {
V_143 = F_66 ( V_113 ,
V_159 , L_13 ,
V_34 ) ;
if ( F_48 ( V_143 ) ) {
V_29 = F_50 ( V_143 ) ;
goto V_160;
}
}
if ( F_7 ( V_69 ) ) {
V_144 = F_66 ( V_113 ,
V_161 , L_14 ,
V_69 ) ;
if ( F_48 ( V_144 ) ) {
V_29 = F_50 ( V_144 ) ;
goto V_162;
}
}
V_149 = true ;
if ( ( V_163 || ! F_20 ( V_164 ) ) &&
F_7 ( V_32 | V_34 | V_69 ) )
F_63 ( & V_145 ,
F_64 ( V_146 ) ) ;
return 0 ;
V_162:
if ( F_7 ( V_34 ) ) {
F_72 ( V_143 ) ;
F_70 ( V_143 ) ;
}
V_160:
if ( F_7 ( V_32 ) ) {
F_72 ( V_142 ) ;
F_70 ( V_142 ) ;
}
V_158:
return V_29 ;
}
static void F_73 ( void )
{
if ( ( V_163 || ! F_20 ( V_164 ) ) &&
F_7 ( V_32 | V_34 | V_69 ) )
F_74 ( & V_145 ) ;
if ( F_7 ( V_32 ) ) {
F_72 ( V_142 ) ;
F_70 ( V_142 ) ;
}
if ( F_7 ( V_34 ) ) {
F_72 ( V_143 ) ;
F_70 ( V_143 ) ;
}
if ( F_7 ( V_69 ) ) {
F_72 ( V_144 ) ;
F_70 ( V_144 ) ;
}
return;
}
static void F_75 ( T_2 V_28 , void * V_165 )
{
struct V_20 V_166 = { V_49 , NULL } ;
union V_50 * V_51 ;
struct V_167 V_78 ;
T_3 V_23 ;
T_4 V_168 ;
const struct V_169 * V_170 ;
T_2 V_171 ;
V_23 = F_76 ( V_28 , & V_166 ) ;
if ( V_23 != V_31 ) {
F_29 ( L_15 , V_23 ) ;
return;
}
V_51 = (union V_50 * ) V_166 . V_25 ;
if ( ! V_51 )
return;
if ( V_51 -> type != V_52 ) {
F_29 ( L_16 , V_51 -> type ) ;
F_16 ( V_51 ) ;
return;
}
if ( V_51 -> V_53 . V_24 != 8 ) {
F_29 ( L_2 , V_51 -> V_53 . V_24 ) ;
F_16 ( V_51 ) ;
return;
}
V_78 = * ( (struct V_167 * ) V_51 -> V_53 . V_25 ) ;
F_16 ( V_51 ) ;
switch ( V_78 . V_172 ) {
case V_173 :
V_168 = V_78 . V_168 ;
F_77 ( L_17 , V_168 ) ;
V_170 = F_78 ( V_174 ,
V_78 . V_175 ) ;
if ( ! V_170 ) {
F_29 ( L_18 ,
V_78 . V_175 ) ;
} else {
V_171 = V_78 . V_175 ;
switch ( V_170 -> V_176 ) {
case V_177 :
case V_178 :
if ( F_7 ( V_32 ) )
F_62 ( V_142 ,
! ( V_168 & V_89 ) ) ;
if ( F_7 ( V_69 ) )
F_62 ( V_144 ,
! ( V_168 & V_91 ) ) ;
if ( F_7 ( V_34 ) )
F_62 ( V_143 ,
! ( V_168 & V_90 ) ) ;
break;
case V_179 :
V_171 = ( V_168 & V_180 ) ?
V_181 : V_182 ;
}
F_79 ( V_174 , V_171 , 1 , true ) ;
}
break;
case V_183 :
F_57 () ;
break;
default:
F_29 ( L_19 ,
V_78 . V_172 , V_78 . V_175 ) ;
break;
}
}
static T_3 T_1
F_80 ( struct V_184 * V_80 ,
struct V_185 * V_78 )
{
T_3 V_23 ;
union V_50 * V_51 ;
struct V_20 V_22 = { sizeof( struct V_184 ) , V_80 } ;
struct V_20 V_85 = { V_49 , NULL } ;
V_23 = F_9 ( V_86 , 0 , 0x1 , & V_22 , & V_85 ) ;
if ( F_15 ( V_23 ) )
return V_23 ;
V_51 = V_85 . V_25 ;
if ( ! V_51 )
return V_30 ;
else if ( V_51 -> type != V_52 ) {
F_16 ( V_51 ) ;
return V_30 ;
}
if ( V_51 -> V_53 . V_24 != 4 ) {
F_29 ( L_2 , V_51 -> V_53 . V_24 ) ;
F_16 ( V_51 ) ;
return V_30 ;
}
* V_78 = * ( (struct V_185 * ) V_51 -> V_53 . V_25 ) ;
F_16 ( V_51 ) ;
return V_23 ;
}
static int T_1 F_81 ( void )
{
struct V_185 V_78 ;
T_3 V_23 ;
struct V_184 V_80 = {
. V_81 = 0x1 ,
. V_186 = 0xFFFF ,
. V_84 = 0xFFFF ,
. V_187 = 0x00 ,
. V_188 = 0x01 ,
} ;
V_23 = F_80 ( & V_80 , & V_78 ) ;
if ( V_78 . V_87 || V_78 . V_88 )
F_29 ( L_20 ,
V_78 . V_87 ,
V_78 . V_88 ) ;
else
F_4 ( L_21 ) ;
return V_23 ;
}
static int T_1 F_82 ( void )
{
struct V_185 V_78 ;
T_3 V_23 ;
struct V_184 V_80 = {
. V_81 = 0x1 ,
. V_186 = 0xFFFF ,
. V_84 = 0xFFFF ,
. V_187 = 0x01 ,
. V_188 = 0x01 ,
} ;
V_23 = F_80 ( & V_80 , & V_78 ) ;
if ( V_78 . V_87 || V_78 . V_88 )
F_29 ( L_22 ,
V_78 . V_87 ,
V_78 . V_88 ) ;
return V_23 ;
}
static int T_1 F_83 ( void )
{
struct V_185 V_78 ;
T_3 V_23 ;
struct V_184 V_80 = {
. V_81 = 0x1 ,
. V_186 = 0xFFFF ,
. V_84 = 0xFFFF ,
. V_187 = 0x10 ,
. V_188 = 0x10 ,
} ;
V_23 = F_80 ( & V_80 , & V_78 ) ;
if ( V_78 . V_87 || V_78 . V_88 )
F_29 ( L_23 ,
V_78 . V_87 ,
V_78 . V_88 ) ;
return V_23 ;
}
static T_3 T_1 F_84 ( T_5 V_189 , T_2 V_190 ,
void * V_191 , void * * V_192 )
{
struct V_193 * V_113 ;
if ( ! strcmp ( V_191 , L_24 ) ) {
if ( F_85 ( V_189 , & V_113 ) )
return V_31 ;
if ( strcmp ( V_194 , F_86 ( V_113 ) ) )
return V_31 ;
} else
return V_31 ;
* ( T_5 * ) V_192 = V_189 ;
return V_195 ;
}
static int T_1 F_87 ( const char * V_153 , const char * V_196 ,
T_5 * V_189 )
{
T_3 V_23 ;
T_5 V_197 ;
F_88 ( ! V_153 || ! V_189 ) ;
V_197 = NULL ;
V_23 = F_89 ( V_196 , F_84 ,
( void * ) V_153 , & V_197 ) ;
if ( F_23 ( V_23 ) && V_197 ) {
* V_189 = V_197 ;
return 0 ;
} else {
return - V_150 ;
}
}
static int T_1 F_90 ( void )
{
int V_29 ;
V_29 = F_87 ( L_24 , V_194 , & V_128 ) ;
if ( V_29 )
return V_29 ;
V_1 -> V_4 |= V_130 ;
V_133 = F_91 () ;
if ( ! V_133 )
return - V_156 ;
V_133 -> V_198 = F_56 ;
V_133 -> V_153 = L_25 ;
V_133 -> V_199 = L_26 ;
V_133 -> V_56 . V_200 = V_201 ;
V_133 -> V_202 [ 0 ] = F_92 ( V_203 ) ;
F_93 ( V_133 , V_134 , - 16384 , 16384 , 0 , 0 ) ;
F_93 ( V_133 , V_137 , - 16384 , 16384 , 0 , 0 ) ;
F_93 ( V_133 , V_138 , - 16384 , 16384 , 0 , 0 ) ;
V_29 = F_94 ( V_133 ) ;
if ( V_29 )
goto V_204;
return 0 ;
V_204:
F_95 ( V_133 ) ;
return V_29 ;
}
static void F_96 ( void )
{
F_97 ( V_133 ) ;
}
static int T_1 F_98 ( void )
{
T_3 V_23 ;
int V_29 ;
V_174 = F_91 () ;
if ( ! V_174 )
return - V_156 ;
V_174 -> V_153 = L_27 ;
V_174 -> V_199 = L_28 ;
V_174 -> V_56 . V_200 = V_201 ;
V_29 = F_99 ( V_174 , V_205 , NULL ) ;
if ( V_29 )
goto V_204;
V_23 = F_100 ( V_164 ,
F_75 , NULL ) ;
if ( F_15 ( V_23 ) ) {
V_29 = - V_206 ;
goto V_204;
}
V_29 = F_94 ( V_174 ) ;
if ( V_29 )
goto V_207;
return 0 ;
V_207:
F_101 ( V_164 ) ;
V_204:
F_95 ( V_174 ) ;
return V_29 ;
}
static void F_102 ( void )
{
F_101 ( V_164 ) ;
F_97 ( V_174 ) ;
}
static T_2 F_103 ( void )
{
struct V_20 V_48 = { V_49 , NULL } ;
union V_50 * V_51 ;
T_3 V_23 ;
T_2 V_84 = 0 ;
V_23 = F_35 ( V_104 , 1 , & V_48 ) ;
if ( F_15 ( V_23 ) )
return 0 ;
V_51 = (union V_50 * ) V_48 . V_25 ;
if ( V_51 ) {
if ( V_51 -> type == V_52 &&
( V_51 -> V_53 . V_24 == sizeof( T_2 ) ||
V_51 -> V_53 . V_24 == sizeof( V_64 ) ) ) {
V_84 = * ( ( T_2 * ) V_51 -> V_53 . V_25 ) ;
} else if ( V_51 -> type == V_65 ) {
V_84 = ( T_2 ) V_51 -> integer . V_28 ;
}
}
F_16 ( V_48 . V_25 ) ;
return V_84 ;
}
static int F_104 ( struct V_208 * V_76 )
{
int V_29 ;
if ( F_7 ( V_5 ) ) {
V_29 = F_40 ( & V_76 -> V_113 ) ;
if ( V_29 )
goto V_209;
}
if ( F_7 ( V_7 ) ) {
V_29 = F_46 ( & V_76 -> V_113 ) ;
if ( V_29 )
goto V_210;
}
V_29 = F_71 ( & V_76 -> V_113 ) ;
if ( V_29 )
goto V_211;
return V_29 ;
V_211:
if ( F_7 ( V_7 ) )
F_52 () ;
V_210:
if ( F_7 ( V_5 ) )
F_42 () ;
V_209:
return V_29 ;
}
static int F_105 ( struct V_208 * V_76 )
{
if ( F_7 ( V_5 ) )
F_42 () ;
if ( F_7 ( V_7 ) )
F_52 () ;
F_73 () ;
return 0 ;
}
static int F_106 ( struct V_76 * V_113 )
{
T_2 V_28 ;
struct V_212 * V_147 = & V_1 -> V_147 ;
if ( ! V_147 )
return - V_156 ;
if ( F_7 ( V_5 ) ) {
F_36 ( & V_28 , V_5 ) ;
F_37 ( V_115 , V_5 ) ;
V_147 -> V_3 = V_28 ;
}
if ( F_7 ( V_7 ) ) {
F_36 ( & V_28 , V_7 ) ;
V_147 -> V_6 = V_28 ;
}
return 0 ;
}
static int F_107 ( struct V_76 * V_113 )
{
struct V_212 * V_147 = & V_1 -> V_147 ;
if ( ! V_147 )
return - V_156 ;
if ( F_7 ( V_5 ) )
F_37 ( V_147 -> V_3 , V_5 ) ;
if ( F_7 ( V_7 ) )
F_37 ( V_147 -> V_6 , V_7 ) ;
if ( F_7 ( V_130 ) )
F_54 () ;
return 0 ;
}
static void F_108 ( struct V_208 * V_76 )
{
struct V_212 * V_147 = & V_1 -> V_147 ;
if ( ! V_147 )
return;
if ( F_7 ( V_5 ) )
F_37 ( V_115 , V_5 ) ;
}
static void F_109 ( void )
{
F_110 ( V_1 -> V_213 . V_84 ) ;
F_110 ( V_1 -> V_213 . V_214 ) ;
}
static int T_1 F_111 ( void )
{
V_1 -> V_213 . V_214 = F_112 ( L_8 , NULL ) ;
if ( ! V_1 -> V_213 . V_214 ) {
F_49 ( L_29 ) ;
return - V_156 ;
}
V_1 -> V_213 . V_84 = F_113 ( L_30 , V_215 ,
V_1 -> V_213 . V_214 ,
& V_1 -> V_213 . V_216 ) ;
if ( ! V_1 -> V_213 . V_84 )
goto V_217;
return 0 ;
V_217:
F_109 () ;
return - V_156 ;
}
static int T_1 F_114 ( void )
{
int V_29 ;
F_4 ( L_31 ) ;
if ( F_6 ( V_218 ) ) {
F_4 ( L_32 ) ;
return - V_150 ;
}
F_5 () ;
if ( F_20 ( V_27 ) &&
! F_6 ( V_219 ) &&
V_2 == & V_16 ) {
F_49 ( L_33 ) ;
return - V_150 ;
}
if ( F_20 ( V_27 ) && F_20 ( V_63 ) )
V_1 = & V_220 ;
if ( ! F_20 ( V_27 ) && F_20 ( V_63 ) )
V_1 = & V_221 ;
if ( F_20 ( V_86 ) )
V_1 = & V_222 ;
if ( V_1 )
F_115 ( F_33 , NULL ) ;
if ( F_20 ( V_104 ) && V_1 ) {
if ( ! V_103 && F_15 ( F_34 () ) ) {
F_49 ( L_34 ) ;
return - V_150 ;
}
V_1 -> V_4 |= V_7 ;
} else if ( ! F_20 ( V_104 ) && V_1 && ! V_103 ) {
F_49 ( L_35 ) ;
return - V_150 ;
}
if ( F_20 ( V_27 ) && ! F_20 ( V_63 ) ) {
V_1 = & V_223 ;
if ( F_15 ( F_19 () ) ) {
F_49 ( L_36 ) ;
return - V_150 ;
}
}
if ( F_20 ( V_27 ) )
F_14 () ;
if ( ! V_1 ) {
F_49 ( L_37 ) ;
return - V_150 ;
}
F_1 () ;
if ( F_6 ( V_224 ) )
F_116 ( V_225 ) ;
if ( F_117 () != V_225 )
V_1 -> V_4 &= ~ V_7 ;
if ( F_20 ( V_86 ) ) {
if ( F_15 ( F_83 () ) )
F_29 ( L_38 ) ;
if ( V_163 ) {
if ( F_15 ( F_81 () ) ) {
F_49 ( L_39 ) ;
return - V_150 ;
}
} else if ( F_15 ( F_82 () ) ) {
F_49 ( L_40 ) ;
return - V_150 ;
}
} else if ( V_163 ) {
F_4 ( L_41 ) ;
}
if ( F_20 ( V_164 ) ) {
V_29 = F_98 () ;
if ( V_29 )
return V_29 ;
V_29 = F_90 () ;
if ( V_29 && V_29 != - V_150 )
F_29 ( L_42 ) ;
}
V_29 = F_118 ( & V_226 ) ;
if ( V_29 ) {
F_49 ( L_43 ) ;
goto V_227;
}
V_228 = F_119 ( L_8 , - 1 ) ;
if ( ! V_228 ) {
V_29 = - V_156 ;
goto V_229;
}
V_29 = F_120 ( V_228 ) ;
if ( V_29 )
goto V_230;
if ( F_20 ( V_104 ) ) {
V_1 -> V_213 . V_216 = F_103 () ;
V_29 = F_111 () ;
if ( V_29 )
goto V_231;
}
F_38 () ;
return 0 ;
V_231:
F_121 ( V_228 ) ;
V_230:
F_122 ( V_228 ) ;
V_229:
F_123 ( & V_226 ) ;
V_227:
if ( F_20 ( V_164 ) )
F_102 () ;
if ( F_7 ( V_130 ) )
F_96 () ;
return V_29 ;
}
static void T_6 F_124 ( void )
{
if ( F_20 ( V_164 ) )
F_102 () ;
if ( F_7 ( V_130 ) )
F_96 () ;
F_109 () ;
F_125 ( V_228 ) ;
F_123 ( & V_226 ) ;
F_4 ( L_44 ) ;
return;
}
