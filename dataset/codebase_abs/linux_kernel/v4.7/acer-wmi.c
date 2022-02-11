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
} else if ( V_12 == 2490 ) {
V_2 = & V_14 ;
}
if ( V_2 == NULL )
V_2 = & V_15 ;
F_1 () ;
}
static bool F_7 ( T_2 V_16 )
{
if ( ( V_1 -> V_4 & V_16 ) != 0 )
return 1 ;
return 0 ;
}
static T_3 F_8 ( struct V_17 * V_18 ,
struct V_19 * V_20 )
{
struct V_19 V_21 ;
T_3 V_22 ;
V_21 . V_23 = sizeof( struct V_17 ) ;
V_21 . V_24 = ( V_25 * ) V_18 ;
V_22 = F_9 ( V_26 , 1 , 1 , & V_21 , V_20 ) ;
return V_22 ;
}
static T_3 F_10 ( T_2 * V_27 , T_2 V_16 )
{
int V_28 ;
V_25 V_20 ;
switch ( V_16 ) {
case V_5 :
switch ( V_2 -> V_3 ) {
default:
V_28 = F_11 ( 0xA , & V_20 ) ;
if ( V_28 )
return V_29 ;
* V_27 = ( V_20 >> 7 ) & 0x1 ;
return V_30 ;
}
break;
case V_31 :
switch ( V_2 -> V_32 ) {
case 1 :
V_28 = F_11 ( 0x7B , & V_20 ) ;
if ( V_28 )
return V_29 ;
* V_27 = V_20 & 0x1 ;
return V_30 ;
case 2 :
V_28 = F_11 ( 0x71 , & V_20 ) ;
if ( V_28 )
return V_29 ;
* V_27 = V_20 & 0x1 ;
return V_30 ;
case 3 :
V_28 = F_11 ( 0x78 , & V_20 ) ;
if ( V_28 )
return V_29 ;
* V_27 = V_20 & 0x1 ;
return V_30 ;
default:
V_28 = F_11 ( 0xA , & V_20 ) ;
if ( V_28 )
return V_29 ;
* V_27 = ( V_20 >> 2 ) & 0x1 ;
return V_30 ;
}
break;
case V_33 :
switch ( V_2 -> V_34 ) {
default:
V_28 = F_11 ( 0xA , & V_20 ) ;
if ( V_28 )
return V_29 ;
* V_27 = ( V_20 >> 4 ) & 0x1 ;
return V_30 ;
}
break;
case V_7 :
switch ( V_2 -> V_6 ) {
default:
V_28 = F_11 ( 0x83 , & V_20 ) ;
if ( V_28 )
return V_29 ;
* V_27 = V_20 ;
return V_30 ;
}
break;
default:
return V_29 ;
}
return V_30 ;
}
static T_3 F_12 ( T_2 V_27 , T_2 V_16 )
{
struct V_17 args ;
args . V_35 = V_36 ;
args . V_37 = V_27 ? ( 1 << 8 ) : 0 ;
args . V_38 = args . V_39 = 0 ;
switch ( V_16 ) {
case V_5 :
if ( V_27 > 1 )
return V_40 ;
args . V_37 |= V_41 ;
break;
case V_31 :
if ( V_27 > 1 )
return V_40 ;
args . V_37 |= V_42 ;
break;
case V_33 :
if ( V_27 > 1 )
return V_40 ;
args . V_37 |= V_43 ;
break;
case V_7 :
if ( V_27 > V_44 )
return V_40 ;
switch ( V_2 -> V_6 ) {
default:
return F_13 ( 0x83 , V_27 ) ;
break;
}
default:
return V_29 ;
}
return F_8 ( & args , NULL ) ;
}
static T_3 T_1 F_14 ( void )
{
struct V_17 args ;
struct V_45 V_46 ;
T_3 V_22 = V_30 ;
struct V_19 V_47 = { V_48 , NULL } ;
union V_49 * V_50 ;
args . V_35 = 0x86 ;
args . V_37 = args . V_38 = args . V_39 = 0 ;
V_22 = F_8 ( & args , & V_47 ) ;
if ( F_15 ( V_22 ) )
return V_22 ;
V_50 = (union V_49 * ) V_47 . V_24 ;
if ( V_50 && V_50 -> type == V_51 &&
V_50 -> V_52 . V_23 == sizeof( struct V_45 ) ) {
V_46 = * ( (struct V_45 * ) V_50 -> V_52 . V_24 ) ;
} else {
F_16 ( V_47 . V_24 ) ;
return V_29 ;
}
if ( V_46 . V_53 & 0x1 )
V_1 -> V_4 |= V_5 ;
F_16 ( V_47 . V_24 ) ;
return V_30 ;
}
static int T_1 F_17 ( void )
{
const struct V_54 * V_55 ;
for ( V_55 = V_56 ; V_55 -> V_55 [ 0 ] ; V_55 ++ )
if ( F_18 ( V_55 -> V_55 ) )
return true ;
return false ;
}
static T_3 T_1 F_19 ( void )
{
struct V_17 args ;
struct V_45 V_46 ;
T_3 V_22 ;
struct V_19 V_47 = { V_48 , NULL } ;
union V_49 * V_50 ;
if ( F_20 ( V_57 ) ) {
if ( ( V_2 != & V_15 ) ||
! F_17 () )
V_1 -> V_4 |= V_31 ;
return V_30 ;
}
args . V_35 = V_36 ;
args . V_38 = args . V_39 = 0 ;
args . V_37 = 0xa2 << 8 ;
args . V_37 |= V_42 ;
V_22 = F_8 ( & args , & V_47 ) ;
if ( F_15 ( V_22 ) )
return V_22 ;
V_50 = V_47 . V_24 ;
if ( V_50 && V_50 -> type == V_51 &&
V_50 -> V_52 . V_23 == sizeof( struct V_45 ) ) {
V_46 = * ( (struct V_45 * ) V_50 -> V_52 . V_24 ) ;
} else {
V_22 = V_29 ;
goto V_47;
}
if ( V_46 . V_35 & 0x1 )
V_1 -> V_4 |= V_31 ;
args . V_37 = 2 << 8 ;
args . V_37 |= V_43 ;
V_22 = F_8 ( & args , & V_47 ) ;
if ( F_15 ( V_22 ) )
goto V_47;
V_50 = (union V_49 * ) V_47 . V_24 ;
if ( V_50 && V_50 -> type == V_51
&& V_50 -> V_52 . V_23 == sizeof( struct V_45 ) ) {
V_46 = * ( (struct V_45 * ) V_50 -> V_52 . V_24 ) ;
} else {
V_22 = V_29 ;
goto V_47;
}
if ( V_46 . V_35 & 0x1 )
V_1 -> V_4 |= V_33 ;
if ( V_2 -> V_6 >= 0 )
V_1 -> V_4 |= V_7 ;
V_22 = V_30 ;
V_47:
F_16 ( V_47 . V_24 ) ;
return V_22 ;
}
static T_3
F_21 ( T_2 V_58 , T_2 V_59 , T_2 * V_47 )
{
struct V_19 V_21 = { ( V_60 ) sizeof( T_2 ) , ( void * ) ( & V_59 ) } ;
struct V_19 V_20 = { V_48 , NULL } ;
union V_49 * V_50 ;
T_2 V_61 = 0 ;
T_3 V_22 ;
V_22 = F_9 ( V_62 , 1 , V_58 , & V_21 , & V_20 ) ;
if ( F_15 ( V_22 ) )
return V_22 ;
V_50 = (union V_49 * ) V_20 . V_24 ;
if ( V_50 ) {
if ( V_50 -> type == V_51 &&
( V_50 -> V_52 . V_23 == sizeof( T_2 ) ||
V_50 -> V_52 . V_23 == sizeof( V_63 ) ) ) {
V_61 = * ( ( T_2 * ) V_50 -> V_52 . V_24 ) ;
} else if ( V_50 -> type == V_64 ) {
V_61 = ( T_2 ) V_50 -> integer . V_27 ;
}
}
if ( V_47 )
* V_47 = V_61 ;
F_16 ( V_20 . V_24 ) ;
return V_22 ;
}
static T_3 F_22 ( T_2 * V_27 , T_2 V_16 )
{
T_3 V_22 ;
V_25 V_61 ;
T_2 V_20 , V_58 = 0 ;
switch ( V_16 ) {
case V_31 :
V_58 = V_65 ;
break;
case V_33 :
V_58 = V_66 ;
break;
case V_7 :
V_58 = V_67 ;
break;
case V_68 :
V_58 = V_69 ;
break;
case V_5 :
if ( V_2 -> V_3 == 1 ) {
F_11 ( 0x9f , & V_61 ) ;
* V_27 = V_61 & 0x1 ;
return 0 ;
}
default:
return V_29 ;
}
V_22 = F_21 ( V_58 , 0 , & V_20 ) ;
if ( F_23 ( V_22 ) )
* V_27 = ( V_25 ) V_20 ;
return V_22 ;
}
static T_3 F_24 ( T_2 V_27 , T_2 V_16 )
{
T_2 V_58 = 0 ;
char V_70 ;
switch ( V_16 ) {
case V_7 :
if ( V_27 > V_44 )
return V_40 ;
V_58 = V_71 ;
break;
case V_31 :
if ( V_27 > 1 )
return V_40 ;
V_58 = V_72 ;
break;
case V_33 :
if ( V_27 > 1 )
return V_40 ;
V_58 = V_73 ;
break;
case V_68 :
if ( V_27 > 1 )
return V_40 ;
V_58 = V_74 ;
break;
case V_5 :
if ( V_27 > 1 )
return V_40 ;
if ( V_2 -> V_3 == 1 ) {
V_70 = V_27 ? 0x92 : 0x93 ;
F_25 () ;
F_26 ( & V_70 , 0x1059 ) ;
F_27 () ;
return 0 ;
}
break;
default:
return V_29 ;
}
return F_21 ( V_58 , ( T_2 ) V_27 , NULL ) ;
}
static T_3 F_28 ( T_2 * V_27 , T_4 V_75 )
{
struct V_76 V_77 ;
T_3 V_22 ;
union V_49 * V_50 ;
struct V_78 V_79 = {
. V_80 = 0x1 ,
. V_81 = V_82 ,
. V_83 = V_75 ,
} ;
struct V_19 V_21 = {
sizeof( struct V_78 ) ,
& V_79
} ;
struct V_19 V_84 = { V_48 , NULL } ;
V_22 = F_9 ( V_85 , 0 , 0x2 , & V_21 , & V_84 ) ;
if ( F_15 ( V_22 ) )
return V_22 ;
V_50 = V_84 . V_24 ;
if ( ! V_50 )
return V_29 ;
else if ( V_50 -> type != V_51 ) {
F_16 ( V_50 ) ;
return V_29 ;
}
if ( V_50 -> V_52 . V_23 != 8 ) {
F_29 ( L_2 , V_50 -> V_52 . V_23 ) ;
F_16 ( V_50 ) ;
return V_29 ;
}
V_77 = * ( (struct V_76 * ) V_50 -> V_52 . V_24 ) ;
F_16 ( V_50 ) ;
if ( V_77 . V_86 || V_77 . V_87 )
F_29 ( L_3 ,
V_75 ,
V_77 . V_86 ,
V_77 . V_87 ) ;
else
* V_27 = ! ! ( V_77 . V_83 & V_75 ) ;
return V_22 ;
}
static T_3 F_30 ( T_2 * V_27 , T_2 V_16 )
{
T_4 V_75 ;
switch ( V_16 ) {
case V_31 :
V_75 = V_88 ;
break;
case V_33 :
V_75 = V_89 ;
break;
case V_68 :
V_75 = V_90 ;
break;
default:
return V_29 ;
}
return F_28 ( V_27 , V_75 ) ;
}
static T_3 F_31 ( T_2 V_27 , T_4 V_75 )
{
struct V_76 V_77 ;
T_3 V_22 ;
union V_49 * V_50 ;
T_4 V_83 ;
struct V_78 V_91 = {
. V_80 = 0x1 ,
. V_81 = V_82 ,
. V_83 = V_92 ,
} ;
struct V_19 V_93 = {
sizeof( struct V_78 ) ,
& V_91
} ;
struct V_94 V_95 = {
. V_80 = 0x2 ,
. V_81 = V_82 ,
. V_83 = V_92 ,
} ;
struct V_19 V_96 = {
sizeof( struct V_94 ) ,
& V_95
} ;
struct V_19 V_84 = { V_48 , NULL } ;
struct V_19 V_97 = { V_48 , NULL } ;
V_22 = F_9 ( V_85 , 0 , 0x2 , & V_93 , & V_84 ) ;
if ( F_15 ( V_22 ) )
return V_22 ;
V_50 = V_84 . V_24 ;
if ( ! V_50 )
return V_29 ;
else if ( V_50 -> type != V_51 ) {
F_16 ( V_50 ) ;
return V_29 ;
}
if ( V_50 -> V_52 . V_23 != 8 ) {
F_29 ( L_2 , V_50 -> V_52 . V_23 ) ;
F_16 ( V_50 ) ;
return V_29 ;
}
V_77 = * ( (struct V_76 * ) V_50 -> V_52 . V_24 ) ;
F_16 ( V_50 ) ;
if ( V_77 . V_86 || V_77 . V_87 ) {
F_29 ( L_4 ,
V_77 . V_86 ,
V_77 . V_87 ) ;
return V_22 ;
}
V_83 = V_77 . V_83 ;
V_95 . V_83 = ( V_27 ) ? ( V_83 | V_75 ) : ( V_83 & ~ V_75 ) ;
V_22 = F_9 ( V_85 , 0 , 0x1 , & V_96 , & V_97 ) ;
if ( F_15 ( V_22 ) )
return V_22 ;
V_50 = V_97 . V_24 ;
if ( ! V_50 )
return V_29 ;
else if ( V_50 -> type != V_51 ) {
F_16 ( V_50 ) ;
return V_29 ;
}
if ( V_50 -> V_52 . V_23 != 4 ) {
F_29 ( L_2 , V_50 -> V_52 . V_23 ) ;
F_16 ( V_50 ) ;
return V_29 ;
}
V_77 = * ( (struct V_76 * ) V_50 -> V_52 . V_24 ) ;
F_16 ( V_50 ) ;
if ( V_77 . V_86 || V_77 . V_87 )
F_29 ( L_5 ,
V_77 . V_86 ,
V_77 . V_87 ) ;
return V_22 ;
}
static T_3 F_32 ( T_2 V_27 , T_2 V_16 )
{
T_4 V_75 ;
switch ( V_16 ) {
case V_31 :
V_75 = V_88 ;
break;
case V_33 :
V_75 = V_89 ;
break;
case V_68 :
V_75 = V_90 ;
break;
default:
return V_29 ;
}
return F_31 ( V_27 , V_75 ) ;
}
static void T_1 F_33 ( const struct V_98 * V_99 , void * V_11 )
{
struct V_100 * V_101 ;
if ( V_99 -> type != 0xAA )
return;
V_102 = true ;
V_101 = (struct V_100 * ) V_99 ;
F_4 ( L_6 ,
V_101 -> V_92 ) ;
V_92 = V_101 -> V_92 ;
if ( V_101 -> V_92 & V_88 )
V_1 -> V_4 |= V_31 ;
if ( V_101 -> V_92 & V_90 )
V_1 -> V_4 |= V_68 ;
if ( V_101 -> V_92 & V_89 )
V_1 -> V_4 |= V_33 ;
V_82 = V_101 -> V_82 ;
}
static T_3 T_1 F_34 ( void )
{
struct V_19 V_47 = { V_48 , NULL } ;
union V_49 * V_50 ;
T_3 V_22 ;
T_2 V_83 ;
V_22 = F_35 ( V_103 , 1 , & V_47 ) ;
if ( F_15 ( V_22 ) )
return V_22 ;
V_50 = (union V_49 * ) V_47 . V_24 ;
if ( V_50 ) {
if ( V_50 -> type == V_51 &&
( V_50 -> V_52 . V_23 == sizeof( T_2 ) ||
V_50 -> V_52 . V_23 == sizeof( V_63 ) ) ) {
V_83 = * ( ( T_2 * ) V_50 -> V_52 . V_24 ) ;
} else if ( V_50 -> type == V_64 ) {
V_83 = ( T_2 ) V_50 -> integer . V_27 ;
} else {
F_16 ( V_47 . V_24 ) ;
return V_29 ;
}
} else {
F_16 ( V_47 . V_24 ) ;
return V_29 ;
}
F_4 ( L_7 , V_83 ) ;
if ( V_83 & 0x07 )
V_1 -> V_4 |= V_31 ;
if ( V_83 & 0x40 )
V_1 -> V_4 |= V_68 ;
if ( V_83 & 0x10 )
V_1 -> V_4 |= V_33 ;
if ( ! ( V_83 & 0x20 ) )
V_44 = 0x9 ;
F_16 ( V_47 . V_24 ) ;
return V_22 ;
}
static T_3 F_36 ( T_2 * V_27 , T_2 V_16 )
{
T_3 V_22 = V_29 ;
switch ( V_1 -> type ) {
case V_104 :
V_22 = F_10 ( V_27 , V_16 ) ;
break;
case V_105 :
if ( V_16 == V_5 ) {
V_22 = F_10 ( V_27 , V_16 ) ;
break;
}
case V_106 :
V_22 = F_22 ( V_27 , V_16 ) ;
break;
case V_107 :
if ( V_16 & ( V_31 |
V_33 |
V_68 ) )
V_22 = F_30 ( V_27 , V_16 ) ;
else if ( F_20 ( V_103 ) )
V_22 = F_22 ( V_27 , V_16 ) ;
break;
}
return V_22 ;
}
static T_3 F_37 ( T_2 V_27 , T_2 V_16 )
{
T_3 V_22 ;
if ( V_1 -> V_4 & V_16 ) {
switch ( V_1 -> type ) {
case V_104 :
return F_12 ( V_27 , V_16 ) ;
case V_105 :
if ( V_16 == V_5 )
return F_12 ( V_27 , V_16 ) ;
if ( V_16 == V_31 ||
V_16 == V_33 ) {
V_22 = F_24 ( V_27 , V_16 ) ;
if ( F_15 ( V_22 ) )
return V_22 ;
return F_12 ( V_27 , V_16 ) ;
}
case V_106 :
return F_24 ( V_27 , V_16 ) ;
case V_107 :
if ( V_16 & ( V_31 |
V_33 |
V_68 ) )
return F_32 ( V_27 , V_16 ) ;
else if ( F_20 ( V_103 ) )
return F_24 ( V_27 , V_16 ) ;
default:
return V_40 ;
}
}
return V_40 ;
}
static void T_1 F_38 ( void )
{
if ( V_3 >= 0 )
F_37 ( V_3 , V_5 ) ;
if ( ! V_102 && V_108 >= 0 )
F_37 ( V_108 , V_68 ) ;
if ( V_6 >= 0 )
F_37 ( V_6 , V_7 ) ;
}
static void F_39 ( struct V_109 * V_110 ,
enum V_111 V_27 )
{
F_37 ( V_27 , V_5 ) ;
}
static int F_40 ( struct V_75 * V_112 )
{
return F_41 ( V_112 , & V_113 ) ;
}
static void F_42 ( void )
{
F_37 ( V_114 , V_5 ) ;
F_43 ( & V_113 ) ;
}
static int F_44 ( struct V_115 * V_116 )
{
T_2 V_27 ;
F_36 ( & V_27 , V_7 ) ;
return V_27 ;
}
static int F_45 ( struct V_115 * V_116 )
{
int V_117 = V_116 -> V_118 . V_6 ;
if ( V_116 -> V_118 . V_119 != V_120 )
V_117 = 0 ;
if ( V_116 -> V_118 . V_121 != V_120 )
V_117 = 0 ;
F_37 ( V_117 , V_7 ) ;
return 0 ;
}
static int F_46 ( struct V_75 * V_112 )
{
struct V_122 V_118 ;
struct V_115 * V_116 ;
memset ( & V_118 , 0 , sizeof( struct V_122 ) ) ;
V_118 . type = V_123 ;
V_118 . V_44 = V_44 ;
V_116 = F_47 ( L_8 , V_112 , NULL , & V_124 ,
& V_118 ) ;
if ( F_48 ( V_116 ) ) {
F_49 ( L_9 ) ;
V_125 = NULL ;
return F_50 ( V_116 ) ;
}
V_125 = V_116 ;
V_116 -> V_118 . V_119 = V_120 ;
V_116 -> V_118 . V_6 = F_44 ( V_116 ) ;
F_51 ( V_116 ) ;
return 0 ;
}
static void F_52 ( void )
{
F_53 ( V_125 ) ;
}
static int F_54 ( void )
{
T_3 V_22 ;
struct V_19 V_84 ;
union V_49 V_126 ;
V_84 . V_23 = sizeof( V_126 ) ;
V_84 . V_24 = & V_126 ;
V_22 = F_55 ( V_127 , L_10 , NULL , & V_84 ) ;
if ( F_15 ( V_22 ) )
return - 1 ;
return 0 ;
}
static int F_56 ( struct V_128 * V_21 )
{
return F_54 () ;
}
static int F_57 ( void )
{
T_3 V_22 ;
struct V_19 V_84 ;
union V_49 V_126 [ 5 ] ;
if ( ! F_7 ( V_129 ) )
return - 1 ;
V_84 . V_23 = sizeof( V_126 ) ;
V_84 . V_24 = V_126 ;
V_22 = F_55 ( V_127 , L_11 , NULL , & V_84 ) ;
if ( F_15 ( V_22 ) )
return - 1 ;
if ( V_126 -> V_130 . V_131 != 4 )
return - 1 ;
F_58 ( V_132 , V_133 ,
( V_134 ) V_126 -> V_130 . V_135 [ 0 ] . integer . V_27 ) ;
F_58 ( V_132 , V_136 ,
( V_134 ) V_126 -> V_130 . V_135 [ 1 ] . integer . V_27 ) ;
F_58 ( V_132 , V_137 ,
( V_134 ) V_126 -> V_130 . V_135 [ 2 ] . integer . V_27 ) ;
F_59 ( V_132 ) ;
return 0 ;
}
static void F_60 ( struct V_138 * V_139 )
{
T_2 V_140 ;
T_3 V_22 ;
if ( F_7 ( V_31 ) ) {
V_22 = F_36 ( & V_140 , V_31 ) ;
if ( F_23 ( V_22 ) ) {
if ( V_2 -> V_32 == 3 )
F_61 ( V_141 , ! V_140 ) ;
else
F_62 ( V_141 , ! V_140 ) ;
}
}
if ( F_7 ( V_33 ) ) {
V_22 = F_36 ( & V_140 , V_33 ) ;
if ( F_23 ( V_22 ) )
F_62 ( V_142 , ! V_140 ) ;
}
if ( F_7 ( V_68 ) && F_20 ( V_85 ) ) {
V_22 = F_36 ( & V_140 , V_90 ) ;
if ( F_23 ( V_22 ) )
F_62 ( V_143 , ! V_140 ) ;
}
F_63 ( & V_144 , F_64 ( V_145 ) ) ;
}
static int F_65 ( void * V_146 , bool V_147 )
{
T_3 V_22 ;
T_2 V_16 = ( unsigned long ) V_146 ;
if ( V_148 ) {
V_22 = F_37 ( ! V_147 , V_16 ) ;
if ( F_15 ( V_22 ) )
return - V_149 ;
}
return 0 ;
}
static struct V_150 * F_66 ( struct V_75 * V_112 ,
enum V_151 type ,
char * V_152 , T_2 V_16 )
{
int V_28 ;
struct V_150 * V_153 ;
T_2 V_140 ;
T_3 V_22 ;
V_153 = F_67 ( V_152 , V_112 , type ,
& V_154 ,
( void * ) ( unsigned long ) V_16 ) ;
if ( ! V_153 )
return F_68 ( - V_155 ) ;
V_22 = F_36 ( & V_140 , V_16 ) ;
V_28 = F_69 ( V_153 ) ;
if ( V_28 ) {
F_70 ( V_153 ) ;
return F_68 ( V_28 ) ;
}
if ( F_23 ( V_22 ) )
F_62 ( V_153 , ! V_140 ) ;
return V_153 ;
}
static int F_71 ( struct V_75 * V_112 )
{
int V_28 ;
if ( F_7 ( V_31 ) ) {
V_141 = F_66 ( V_112 , V_156 ,
L_12 , V_31 ) ;
if ( F_48 ( V_141 ) ) {
V_28 = F_50 ( V_141 ) ;
goto V_157;
}
}
if ( F_7 ( V_33 ) ) {
V_142 = F_66 ( V_112 ,
V_158 , L_13 ,
V_33 ) ;
if ( F_48 ( V_142 ) ) {
V_28 = F_50 ( V_142 ) ;
goto V_159;
}
}
if ( F_7 ( V_68 ) ) {
V_143 = F_66 ( V_112 ,
V_160 , L_14 ,
V_68 ) ;
if ( F_48 ( V_143 ) ) {
V_28 = F_50 ( V_143 ) ;
goto V_161;
}
}
V_148 = true ;
if ( ( V_162 || ! F_20 ( V_163 ) ) &&
F_7 ( V_31 | V_33 | V_68 ) )
F_63 ( & V_144 ,
F_64 ( V_145 ) ) ;
return 0 ;
V_161:
if ( F_7 ( V_33 ) ) {
F_72 ( V_142 ) ;
F_70 ( V_142 ) ;
}
V_159:
if ( F_7 ( V_31 ) ) {
F_72 ( V_141 ) ;
F_70 ( V_141 ) ;
}
V_157:
return V_28 ;
}
static void F_73 ( void )
{
if ( ( V_162 || ! F_20 ( V_163 ) ) &&
F_7 ( V_31 | V_33 | V_68 ) )
F_74 ( & V_144 ) ;
if ( F_7 ( V_31 ) ) {
F_72 ( V_141 ) ;
F_70 ( V_141 ) ;
}
if ( F_7 ( V_33 ) ) {
F_72 ( V_142 ) ;
F_70 ( V_142 ) ;
}
if ( F_7 ( V_68 ) ) {
F_72 ( V_143 ) ;
F_70 ( V_143 ) ;
}
return;
}
static void F_75 ( T_2 V_27 , void * V_164 )
{
struct V_19 V_165 = { V_48 , NULL } ;
union V_49 * V_50 ;
struct V_166 V_77 ;
T_3 V_22 ;
T_4 V_167 ;
const struct V_168 * V_169 ;
T_2 V_170 ;
V_22 = F_76 ( V_27 , & V_165 ) ;
if ( V_22 != V_30 ) {
F_29 ( L_15 , V_22 ) ;
return;
}
V_50 = (union V_49 * ) V_165 . V_24 ;
if ( ! V_50 )
return;
if ( V_50 -> type != V_51 ) {
F_29 ( L_16 , V_50 -> type ) ;
F_16 ( V_50 ) ;
return;
}
if ( V_50 -> V_52 . V_23 != 8 ) {
F_29 ( L_2 , V_50 -> V_52 . V_23 ) ;
F_16 ( V_50 ) ;
return;
}
V_77 = * ( (struct V_166 * ) V_50 -> V_52 . V_24 ) ;
F_16 ( V_50 ) ;
switch ( V_77 . V_171 ) {
case V_172 :
V_167 = V_77 . V_167 ;
F_77 ( L_17 , V_167 ) ;
V_169 = F_78 ( V_173 ,
V_77 . V_174 ) ;
if ( ! V_169 ) {
F_29 ( L_18 ,
V_77 . V_174 ) ;
} else {
V_170 = V_77 . V_174 ;
switch ( V_169 -> V_175 ) {
case V_176 :
case V_177 :
if ( F_7 ( V_31 ) )
F_62 ( V_141 ,
! ( V_167 & V_88 ) ) ;
if ( F_7 ( V_68 ) )
F_62 ( V_143 ,
! ( V_167 & V_90 ) ) ;
if ( F_7 ( V_33 ) )
F_62 ( V_142 ,
! ( V_167 & V_89 ) ) ;
break;
case V_178 :
V_170 = ( V_167 & V_179 ) ?
V_180 : V_181 ;
}
F_79 ( V_173 , V_170 , 1 , true ) ;
}
break;
case V_182 :
F_57 () ;
break;
default:
F_29 ( L_19 ,
V_77 . V_171 , V_77 . V_174 ) ;
break;
}
}
static T_3 T_1
F_80 ( struct V_183 * V_79 ,
struct V_184 * V_77 )
{
T_3 V_22 ;
union V_49 * V_50 ;
struct V_19 V_21 = { sizeof( struct V_183 ) , V_79 } ;
struct V_19 V_84 = { V_48 , NULL } ;
V_22 = F_9 ( V_85 , 0 , 0x1 , & V_21 , & V_84 ) ;
if ( F_15 ( V_22 ) )
return V_22 ;
V_50 = V_84 . V_24 ;
if ( ! V_50 )
return V_29 ;
else if ( V_50 -> type != V_51 ) {
F_16 ( V_50 ) ;
return V_29 ;
}
if ( V_50 -> V_52 . V_23 != 4 ) {
F_29 ( L_2 , V_50 -> V_52 . V_23 ) ;
F_16 ( V_50 ) ;
return V_29 ;
}
* V_77 = * ( (struct V_184 * ) V_50 -> V_52 . V_24 ) ;
F_16 ( V_50 ) ;
return V_22 ;
}
static int T_1 F_81 ( void )
{
struct V_184 V_77 ;
T_3 V_22 ;
struct V_183 V_79 = {
. V_80 = 0x1 ,
. V_185 = 0xFFFF ,
. V_83 = 0xFFFF ,
. V_186 = 0x00 ,
} ;
V_22 = F_80 ( & V_79 , & V_77 ) ;
if ( V_77 . V_86 || V_77 . V_87 )
F_29 ( L_20 ,
V_77 . V_86 ,
V_77 . V_87 ) ;
else
F_4 ( L_21 ) ;
return V_22 ;
}
static int T_1 F_82 ( void )
{
struct V_184 V_77 ;
T_3 V_22 ;
struct V_183 V_79 = {
. V_80 = 0x1 ,
. V_185 = 0xFFFF ,
. V_83 = 0xFFFF ,
. V_186 = 0x01 ,
} ;
V_22 = F_80 ( & V_79 , & V_77 ) ;
if ( V_77 . V_86 || V_77 . V_87 )
F_29 ( L_22 ,
V_77 . V_86 ,
V_77 . V_87 ) ;
return V_22 ;
}
static T_3 T_1 F_83 ( T_5 V_187 , T_2 V_188 ,
void * V_189 , void * * V_190 )
{
* ( T_5 * ) V_190 = V_187 ;
return V_30 ;
}
static int T_1 F_84 ( const char * V_152 , const char * V_191 ,
T_5 * V_187 )
{
T_3 V_22 ;
T_5 V_192 ;
F_85 ( ! V_152 || ! V_187 ) ;
V_192 = NULL ;
V_22 = F_86 ( V_191 , F_83 ,
( void * ) V_152 , & V_192 ) ;
if ( F_23 ( V_22 ) ) {
* V_187 = V_192 ;
return 0 ;
} else {
return - V_149 ;
}
}
static int T_1 F_87 ( void )
{
int V_28 ;
V_28 = F_84 ( L_23 , L_24 , & V_127 ) ;
if ( V_28 )
return V_28 ;
V_1 -> V_4 |= V_129 ;
V_132 = F_88 () ;
if ( ! V_132 )
return - V_155 ;
V_132 -> V_193 = F_56 ;
V_132 -> V_152 = L_25 ;
V_132 -> V_194 = L_26 ;
V_132 -> V_55 . V_195 = V_196 ;
V_132 -> V_197 [ 0 ] = F_89 ( V_198 ) ;
F_90 ( V_132 , V_133 , - 16384 , 16384 , 0 , 0 ) ;
F_90 ( V_132 , V_136 , - 16384 , 16384 , 0 , 0 ) ;
F_90 ( V_132 , V_137 , - 16384 , 16384 , 0 , 0 ) ;
V_28 = F_91 ( V_132 ) ;
if ( V_28 )
goto V_199;
return 0 ;
V_199:
F_92 ( V_132 ) ;
return V_28 ;
}
static void F_93 ( void )
{
F_94 ( V_132 ) ;
}
static int T_1 F_95 ( void )
{
T_3 V_22 ;
int V_28 ;
V_173 = F_88 () ;
if ( ! V_173 )
return - V_155 ;
V_173 -> V_152 = L_27 ;
V_173 -> V_194 = L_28 ;
V_173 -> V_55 . V_195 = V_196 ;
V_28 = F_96 ( V_173 , V_200 , NULL ) ;
if ( V_28 )
goto V_199;
V_22 = F_97 ( V_163 ,
F_75 , NULL ) ;
if ( F_15 ( V_22 ) ) {
V_28 = - V_201 ;
goto V_202;
}
V_28 = F_91 ( V_173 ) ;
if ( V_28 )
goto V_203;
return 0 ;
V_203:
F_98 ( V_163 ) ;
V_202:
F_99 ( V_173 ) ;
V_199:
F_92 ( V_173 ) ;
return V_28 ;
}
static void F_100 ( void )
{
F_98 ( V_163 ) ;
F_99 ( V_173 ) ;
F_94 ( V_173 ) ;
}
static T_2 F_101 ( void )
{
struct V_19 V_47 = { V_48 , NULL } ;
union V_49 * V_50 ;
T_3 V_22 ;
T_2 V_83 = 0 ;
V_22 = F_35 ( V_103 , 1 , & V_47 ) ;
if ( F_15 ( V_22 ) )
return 0 ;
V_50 = (union V_49 * ) V_47 . V_24 ;
if ( V_50 ) {
if ( V_50 -> type == V_51 &&
( V_50 -> V_52 . V_23 == sizeof( T_2 ) ||
V_50 -> V_52 . V_23 == sizeof( V_63 ) ) ) {
V_83 = * ( ( T_2 * ) V_50 -> V_52 . V_24 ) ;
} else if ( V_50 -> type == V_64 ) {
V_83 = ( T_2 ) V_50 -> integer . V_27 ;
}
}
F_16 ( V_47 . V_24 ) ;
return V_83 ;
}
static int F_102 ( struct V_204 * V_75 )
{
int V_28 ;
if ( F_7 ( V_5 ) ) {
V_28 = F_40 ( & V_75 -> V_112 ) ;
if ( V_28 )
goto V_205;
}
if ( F_7 ( V_7 ) ) {
V_28 = F_46 ( & V_75 -> V_112 ) ;
if ( V_28 )
goto V_206;
}
V_28 = F_71 ( & V_75 -> V_112 ) ;
if ( V_28 )
goto V_207;
return V_28 ;
V_207:
if ( F_7 ( V_7 ) )
F_52 () ;
V_206:
if ( F_7 ( V_5 ) )
F_42 () ;
V_205:
return V_28 ;
}
static int F_103 ( struct V_204 * V_75 )
{
if ( F_7 ( V_5 ) )
F_42 () ;
if ( F_7 ( V_7 ) )
F_52 () ;
F_73 () ;
return 0 ;
}
static int F_104 ( struct V_75 * V_112 )
{
T_2 V_27 ;
struct V_208 * V_146 = & V_1 -> V_146 ;
if ( ! V_146 )
return - V_155 ;
if ( F_7 ( V_5 ) ) {
F_36 ( & V_27 , V_5 ) ;
F_37 ( V_114 , V_5 ) ;
V_146 -> V_3 = V_27 ;
}
if ( F_7 ( V_7 ) ) {
F_36 ( & V_27 , V_7 ) ;
V_146 -> V_6 = V_27 ;
}
return 0 ;
}
static int F_105 ( struct V_75 * V_112 )
{
struct V_208 * V_146 = & V_1 -> V_146 ;
if ( ! V_146 )
return - V_155 ;
if ( F_7 ( V_5 ) )
F_37 ( V_146 -> V_3 , V_5 ) ;
if ( F_7 ( V_7 ) )
F_37 ( V_146 -> V_6 , V_7 ) ;
if ( F_7 ( V_129 ) )
F_54 () ;
return 0 ;
}
static void F_106 ( struct V_204 * V_75 )
{
struct V_208 * V_146 = & V_1 -> V_146 ;
if ( ! V_146 )
return;
if ( F_7 ( V_5 ) )
F_37 ( V_114 , V_5 ) ;
}
static void F_107 ( void )
{
F_108 ( V_1 -> V_209 . V_83 ) ;
F_108 ( V_1 -> V_209 . V_210 ) ;
}
static int T_1 F_109 ( void )
{
V_1 -> V_209 . V_210 = F_110 ( L_8 , NULL ) ;
if ( ! V_1 -> V_209 . V_210 ) {
F_49 ( L_29 ) ;
return - V_155 ;
}
V_1 -> V_209 . V_83 = F_111 ( L_30 , V_211 ,
V_1 -> V_209 . V_210 ,
& V_1 -> V_209 . V_212 ) ;
if ( ! V_1 -> V_209 . V_83 )
goto V_213;
return 0 ;
V_213:
F_107 () ;
return - V_155 ;
}
static int T_1 F_112 ( void )
{
int V_28 ;
F_4 ( L_31 ) ;
if ( F_6 ( V_214 ) ) {
F_4 ( L_32 ) ;
return - V_149 ;
}
F_5 () ;
if ( F_20 ( V_26 ) && F_20 ( V_62 ) )
V_1 = & V_215 ;
if ( ! F_20 ( V_26 ) && F_20 ( V_62 ) )
V_1 = & V_216 ;
if ( F_20 ( V_85 ) )
V_1 = & V_217 ;
if ( V_1 )
F_113 ( F_33 , NULL ) ;
if ( F_20 ( V_103 ) && V_1 ) {
if ( ! V_102 && F_15 ( F_34 () ) ) {
F_49 ( L_33 ) ;
return - V_149 ;
}
V_1 -> V_4 |= V_7 ;
} else if ( ! F_20 ( V_103 ) && V_1 && ! V_102 ) {
F_49 ( L_34 ) ;
return - V_149 ;
}
if ( F_20 ( V_26 ) && ! F_20 ( V_62 ) ) {
V_1 = & V_218 ;
if ( F_15 ( F_19 () ) ) {
F_49 ( L_35 ) ;
return - V_149 ;
}
}
if ( F_20 ( V_26 ) )
F_14 () ;
if ( ! V_1 ) {
F_49 ( L_36 ) ;
return - V_149 ;
}
F_1 () ;
if ( F_6 ( V_219 ) )
F_114 ( V_220 ) ;
if ( F_115 () != V_220 )
V_1 -> V_4 &= ~ V_7 ;
if ( F_20 ( V_85 ) ) {
if ( V_162 ) {
if ( F_15 ( F_81 () ) ) {
F_49 ( L_37 ) ;
return - V_149 ;
}
} else if ( F_15 ( F_82 () ) ) {
F_49 ( L_38 ) ;
return - V_149 ;
}
} else if ( V_162 ) {
F_4 ( L_39 ) ;
}
if ( F_20 ( V_163 ) ) {
V_28 = F_95 () ;
if ( V_28 )
return V_28 ;
}
F_87 () ;
V_28 = F_116 ( & V_221 ) ;
if ( V_28 ) {
F_49 ( L_40 ) ;
goto V_222;
}
V_223 = F_117 ( L_8 , - 1 ) ;
if ( ! V_223 ) {
V_28 = - V_155 ;
goto V_224;
}
V_28 = F_118 ( V_223 ) ;
if ( V_28 )
goto V_225;
if ( F_20 ( V_103 ) ) {
V_1 -> V_209 . V_212 = F_101 () ;
V_28 = F_109 () ;
if ( V_28 )
goto V_226;
}
F_38 () ;
return 0 ;
V_226:
F_119 ( V_223 ) ;
V_225:
F_120 ( V_223 ) ;
V_224:
F_121 ( & V_221 ) ;
V_222:
if ( F_20 ( V_163 ) )
F_100 () ;
if ( F_7 ( V_129 ) )
F_93 () ;
return V_28 ;
}
static void T_6 F_122 ( void )
{
if ( F_20 ( V_163 ) )
F_100 () ;
if ( F_7 ( V_129 ) )
F_93 () ;
F_107 () ;
F_123 ( V_223 ) ;
F_121 ( & V_221 ) ;
F_4 ( L_41 ) ;
return;
}
