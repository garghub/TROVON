static void F_1 ( void )
{
if ( ! V_1 )
return;
if ( V_2 -> V_3 )
V_1 -> V_4 |= V_5 ;
if ( V_2 -> V_6 )
V_1 -> V_4 |= V_7 ;
}
static int F_2 ( const struct V_8 * V_9 )
{
V_2 = V_9 -> V_10 ;
return 1 ;
}
static int F_3 ( const struct V_8 * V_11 )
{
V_1 -> V_4 &= ~ V_7 ;
F_4 ( L_1 ) ;
return 0 ;
}
static void F_5 ( void )
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
static bool F_7 ( T_1 V_16 )
{
if ( ( V_1 -> V_4 & V_16 ) != 0 )
return 1 ;
return 0 ;
}
static T_2 F_8 ( struct V_17 * V_18 ,
struct V_19 * V_20 )
{
struct V_19 V_21 ;
T_2 V_22 ;
V_21 . V_23 = sizeof( struct V_17 ) ;
V_21 . V_24 = ( V_25 * ) V_18 ;
V_22 = F_9 ( V_26 , 1 , 1 , & V_21 , V_20 ) ;
return V_22 ;
}
static T_2 F_10 ( T_1 * V_27 , T_1 V_16 )
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
static T_2 F_12 ( T_1 V_27 , T_1 V_16 )
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
static T_2 F_14 ( void )
{
struct V_17 args ;
struct V_45 V_46 ;
T_2 V_22 = V_30 ;
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
static T_2 F_17 ( T_3 V_54 ,
T_1 V_55 , void * V_56 , void * * V_57 )
{
V_58 = 1 ;
return V_30 ;
}
static int F_18 ( void )
{
const struct V_59 * V_60 ;
for ( V_60 = V_61 ; V_60 -> V_60 [ 0 ] ; V_60 ++ )
F_19 ( V_60 -> V_60 , F_17 ,
NULL , NULL ) ;
return V_58 ;
}
static T_2 F_20 ( void )
{
struct V_17 args ;
struct V_45 V_46 ;
T_2 V_22 ;
struct V_19 V_47 = { V_48 , NULL } ;
union V_49 * V_50 ;
if ( F_21 ( V_62 ) ) {
if ( ( V_2 != & V_15 ) ||
! F_18 () )
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
static T_2
F_22 ( T_1 V_63 , T_1 V_64 , T_1 * V_47 )
{
struct V_19 V_21 = { ( V_65 ) sizeof( T_1 ) , ( void * ) ( & V_64 ) } ;
struct V_19 V_20 = { V_48 , NULL } ;
union V_49 * V_50 ;
T_1 V_66 ;
T_2 V_22 ;
V_22 = F_9 ( V_67 , 1 , V_63 , & V_21 , & V_20 ) ;
if ( F_15 ( V_22 ) )
return V_22 ;
V_50 = (union V_49 * ) V_20 . V_24 ;
if ( V_50 && V_50 -> type == V_51 &&
( V_50 -> V_52 . V_23 == sizeof( T_1 ) ||
V_50 -> V_52 . V_23 == sizeof( V_68 ) ) ) {
V_66 = * ( ( T_1 * ) V_50 -> V_52 . V_24 ) ;
} else if ( V_50 -> type == V_69 ) {
V_66 = ( T_1 ) V_50 -> integer . V_27 ;
} else {
V_66 = 0 ;
}
if ( V_47 )
* V_47 = V_66 ;
F_16 ( V_20 . V_24 ) ;
return V_22 ;
}
static T_2 F_23 ( T_1 * V_27 , T_1 V_16 )
{
T_2 V_22 ;
V_25 V_66 ;
T_1 V_20 , V_63 = 0 ;
switch ( V_16 ) {
case V_31 :
V_63 = V_70 ;
break;
case V_33 :
V_63 = V_71 ;
break;
case V_7 :
V_63 = V_72 ;
break;
case V_73 :
V_63 = V_74 ;
break;
case V_5 :
if ( V_2 -> V_3 == 1 ) {
F_11 ( 0x9f , & V_66 ) ;
* V_27 = V_66 & 0x1 ;
return 0 ;
}
default:
return V_29 ;
}
V_22 = F_22 ( V_63 , 0 , & V_20 ) ;
if ( F_24 ( V_22 ) )
* V_27 = ( V_25 ) V_20 ;
return V_22 ;
}
static T_2 F_25 ( T_1 V_27 , T_1 V_16 )
{
T_1 V_63 = 0 ;
char V_75 ;
switch ( V_16 ) {
case V_7 :
if ( V_27 > V_44 )
return V_40 ;
V_63 = V_76 ;
break;
case V_31 :
if ( V_27 > 1 )
return V_40 ;
V_63 = V_77 ;
break;
case V_33 :
if ( V_27 > 1 )
return V_40 ;
V_63 = V_78 ;
break;
case V_73 :
if ( V_27 > 1 )
return V_40 ;
V_63 = V_79 ;
break;
case V_5 :
if ( V_27 > 1 )
return V_40 ;
if ( V_2 -> V_3 == 1 ) {
V_75 = V_27 ? 0x92 : 0x93 ;
F_26 () ;
F_27 ( & V_75 , 0x1059 ) ;
F_28 () ;
return 0 ;
}
break;
default:
return V_29 ;
}
return F_22 ( V_63 , ( T_1 ) V_27 , NULL ) ;
}
static T_2 F_29 ( T_1 * V_27 , T_4 V_80 )
{
struct V_81 V_82 ;
T_2 V_22 ;
union V_49 * V_50 ;
struct V_83 V_84 = {
. V_85 = 0x1 ,
. V_86 = V_87 ,
. V_88 = V_80 ,
} ;
struct V_19 V_21 = {
sizeof( struct V_83 ) ,
& V_84
} ;
struct V_19 V_89 = { V_48 , NULL } ;
V_22 = F_9 ( V_90 , 0 , 0x2 , & V_21 , & V_89 ) ;
if ( F_15 ( V_22 ) )
return V_22 ;
V_50 = V_89 . V_24 ;
if ( ! V_50 )
return V_29 ;
else if ( V_50 -> type != V_51 ) {
F_16 ( V_50 ) ;
return V_29 ;
}
if ( V_50 -> V_52 . V_23 != 8 ) {
F_30 ( L_2 , V_50 -> V_52 . V_23 ) ;
F_16 ( V_50 ) ;
return V_29 ;
}
V_82 = * ( (struct V_81 * ) V_50 -> V_52 . V_24 ) ;
F_16 ( V_50 ) ;
if ( V_82 . V_91 || V_82 . V_92 )
F_30 ( L_3 ,
V_80 ,
V_82 . V_91 ,
V_82 . V_92 ) ;
else
* V_27 = ! ! ( V_82 . V_88 & V_80 ) ;
return V_22 ;
}
static T_2 F_31 ( T_1 * V_27 , T_1 V_16 )
{
T_4 V_80 ;
switch ( V_16 ) {
case V_31 :
V_80 = V_93 ;
break;
case V_33 :
V_80 = V_94 ;
break;
case V_73 :
V_80 = V_95 ;
break;
default:
return V_29 ;
}
return F_29 ( V_27 , V_80 ) ;
}
static T_2 F_32 ( T_1 V_27 , T_4 V_80 )
{
struct V_81 V_82 ;
T_2 V_22 ;
union V_49 * V_50 ;
T_4 V_88 ;
struct V_83 V_96 = {
. V_85 = 0x1 ,
. V_86 = V_87 ,
. V_88 = V_97 ,
} ;
struct V_19 V_98 = {
sizeof( struct V_83 ) ,
& V_96
} ;
struct V_99 V_100 = {
. V_85 = 0x2 ,
. V_86 = V_87 ,
. V_88 = V_97 ,
} ;
struct V_19 V_101 = {
sizeof( struct V_99 ) ,
& V_100
} ;
struct V_19 V_89 = { V_48 , NULL } ;
struct V_19 V_102 = { V_48 , NULL } ;
V_22 = F_9 ( V_90 , 0 , 0x2 , & V_98 , & V_89 ) ;
if ( F_15 ( V_22 ) )
return V_22 ;
V_50 = V_89 . V_24 ;
if ( ! V_50 )
return V_29 ;
else if ( V_50 -> type != V_51 ) {
F_16 ( V_50 ) ;
return V_29 ;
}
if ( V_50 -> V_52 . V_23 != 8 ) {
F_30 ( L_2 , V_50 -> V_52 . V_23 ) ;
F_16 ( V_50 ) ;
return V_29 ;
}
V_82 = * ( (struct V_81 * ) V_50 -> V_52 . V_24 ) ;
F_16 ( V_50 ) ;
if ( V_82 . V_91 || V_82 . V_92 ) {
F_30 ( L_4 ,
V_82 . V_91 ,
V_82 . V_92 ) ;
return V_22 ;
}
V_88 = V_82 . V_88 ;
V_100 . V_88 = ( V_27 ) ? ( V_88 | V_80 ) : ( V_88 & ~ V_80 ) ;
V_22 = F_9 ( V_90 , 0 , 0x1 , & V_101 , & V_102 ) ;
if ( F_15 ( V_22 ) )
return V_22 ;
V_50 = V_102 . V_24 ;
if ( ! V_50 )
return V_29 ;
else if ( V_50 -> type != V_51 ) {
F_16 ( V_50 ) ;
return V_29 ;
}
if ( V_50 -> V_52 . V_23 != 4 ) {
F_30 ( L_2 , V_50 -> V_52 . V_23 ) ;
F_16 ( V_50 ) ;
return V_29 ;
}
V_82 = * ( (struct V_81 * ) V_50 -> V_52 . V_24 ) ;
F_16 ( V_50 ) ;
if ( V_82 . V_91 || V_82 . V_92 )
F_30 ( L_5 ,
V_82 . V_91 ,
V_82 . V_92 ) ;
return V_22 ;
}
static T_2 F_33 ( T_1 V_27 , T_1 V_16 )
{
T_4 V_80 ;
switch ( V_16 ) {
case V_31 :
V_80 = V_93 ;
break;
case V_33 :
V_80 = V_94 ;
break;
case V_73 :
V_80 = V_95 ;
break;
default:
return V_29 ;
}
return F_32 ( V_27 , V_80 ) ;
}
static void F_34 ( const struct V_103 * V_104 , void * V_105 )
{
struct V_106 * V_107 ;
if ( V_104 -> type != 0xAA )
return;
V_108 = true ;
V_107 = (struct V_106 * ) V_104 ;
F_4 ( L_6 ,
V_107 -> V_97 ) ;
V_97 = V_107 -> V_97 ;
if ( V_107 -> V_97 & V_93 )
V_1 -> V_4 |= V_31 ;
if ( V_107 -> V_97 & V_95 )
V_1 -> V_4 |= V_73 ;
if ( V_107 -> V_97 & V_94 )
V_1 -> V_4 |= V_33 ;
V_87 = V_107 -> V_87 ;
}
static T_2 F_35 ( void )
{
struct V_19 V_47 = { V_48 , NULL } ;
union V_49 * V_50 ;
T_2 V_22 ;
T_1 V_88 ;
V_22 = F_36 ( V_109 , 1 , & V_47 ) ;
if ( F_15 ( V_22 ) )
return V_22 ;
V_50 = (union V_49 * ) V_47 . V_24 ;
if ( V_50 && V_50 -> type == V_51 &&
( V_50 -> V_52 . V_23 == sizeof( T_1 ) ||
V_50 -> V_52 . V_23 == sizeof( V_68 ) ) ) {
V_88 = * ( ( T_1 * ) V_50 -> V_52 . V_24 ) ;
} else if ( V_50 -> type == V_69 ) {
V_88 = ( T_1 ) V_50 -> integer . V_27 ;
} else {
F_16 ( V_47 . V_24 ) ;
return V_29 ;
}
F_4 ( L_7 , V_88 ) ;
if ( V_88 & 0x07 )
V_1 -> V_4 |= V_31 ;
if ( V_88 & 0x40 )
V_1 -> V_4 |= V_73 ;
if ( V_88 & 0x10 )
V_1 -> V_4 |= V_33 ;
if ( ! ( V_88 & 0x20 ) )
V_44 = 0x9 ;
F_16 ( V_47 . V_24 ) ;
return V_22 ;
}
static T_2 F_37 ( T_1 * V_27 , T_1 V_16 )
{
T_2 V_22 = V_29 ;
switch ( V_1 -> type ) {
case V_110 :
V_22 = F_10 ( V_27 , V_16 ) ;
break;
case V_111 :
if ( V_16 == V_5 ) {
V_22 = F_10 ( V_27 , V_16 ) ;
break;
}
case V_112 :
V_22 = F_23 ( V_27 , V_16 ) ;
break;
case V_113 :
if ( V_16 & ( V_31 |
V_33 |
V_73 ) )
V_22 = F_31 ( V_27 , V_16 ) ;
else if ( F_21 ( V_109 ) )
V_22 = F_23 ( V_27 , V_16 ) ;
break;
}
return V_22 ;
}
static T_2 F_38 ( T_1 V_27 , T_1 V_16 )
{
T_2 V_22 ;
if ( V_1 -> V_4 & V_16 ) {
switch ( V_1 -> type ) {
case V_110 :
return F_12 ( V_27 , V_16 ) ;
case V_111 :
if ( V_16 == V_5 )
return F_12 ( V_27 , V_16 ) ;
if ( V_16 == V_31 ||
V_16 == V_33 ) {
V_22 = F_25 ( V_27 , V_16 ) ;
if ( F_15 ( V_22 ) )
return V_22 ;
return F_12 ( V_27 , V_16 ) ;
}
case V_112 :
return F_25 ( V_27 , V_16 ) ;
case V_113 :
if ( V_16 & ( V_31 |
V_33 |
V_73 ) )
return F_33 ( V_27 , V_16 ) ;
else if ( F_21 ( V_109 ) )
return F_25 ( V_27 , V_16 ) ;
default:
return V_40 ;
}
}
return V_40 ;
}
static void T_5 F_39 ( void )
{
if ( V_3 >= 0 )
F_38 ( V_3 , V_5 ) ;
if ( ! V_108 && V_114 >= 0 )
F_38 ( V_114 , V_73 ) ;
if ( V_6 >= 0 )
F_38 ( V_6 , V_7 ) ;
}
static void F_40 ( struct V_115 * V_116 ,
enum V_117 V_27 )
{
F_38 ( V_27 , V_5 ) ;
}
static int T_6 F_41 ( struct V_80 * V_118 )
{
return F_42 ( V_118 , & V_119 ) ;
}
static void F_43 ( void )
{
F_38 ( V_120 , V_5 ) ;
F_44 ( & V_119 ) ;
}
static int F_45 ( struct V_121 * V_122 )
{
T_1 V_27 ;
F_37 ( & V_27 , V_7 ) ;
return V_27 ;
}
static int F_46 ( struct V_121 * V_122 )
{
int V_123 = V_122 -> V_124 . V_6 ;
if ( V_122 -> V_124 . V_125 != V_126 )
V_123 = 0 ;
if ( V_122 -> V_124 . V_127 != V_126 )
V_123 = 0 ;
F_38 ( V_123 , V_7 ) ;
return 0 ;
}
static int T_6 F_47 ( struct V_80 * V_118 )
{
struct V_128 V_124 ;
struct V_121 * V_122 ;
memset ( & V_124 , 0 , sizeof( struct V_128 ) ) ;
V_124 . type = V_129 ;
V_124 . V_44 = V_44 ;
V_122 = F_48 ( L_8 , V_118 , NULL , & V_130 ,
& V_124 ) ;
if ( F_49 ( V_122 ) ) {
F_50 ( L_9 ) ;
V_131 = NULL ;
return F_51 ( V_122 ) ;
}
V_131 = V_122 ;
V_122 -> V_124 . V_125 = V_126 ;
V_122 -> V_124 . V_6 = F_45 ( V_122 ) ;
F_52 ( V_122 ) ;
return 0 ;
}
static void F_53 ( void )
{
F_54 ( V_131 ) ;
}
static int F_55 ( void )
{
T_2 V_22 ;
struct V_19 V_89 ;
union V_49 V_132 ;
V_89 . V_23 = sizeof( V_132 ) ;
V_89 . V_24 = & V_132 ;
V_22 = F_56 ( V_133 , L_10 , NULL , & V_89 ) ;
if ( F_15 ( V_22 ) )
return - 1 ;
return 0 ;
}
static int F_57 ( struct V_134 * V_21 )
{
return F_55 () ;
}
static int F_58 ( void )
{
T_2 V_22 ;
struct V_19 V_89 ;
union V_49 V_132 [ 5 ] ;
if ( ! F_7 ( V_135 ) )
return - 1 ;
V_89 . V_23 = sizeof( V_132 ) ;
V_89 . V_24 = V_132 ;
V_22 = F_56 ( V_133 , L_11 , NULL , & V_89 ) ;
if ( F_15 ( V_22 ) )
return - 1 ;
if ( V_132 -> V_136 . V_137 != 4 )
return - 1 ;
F_59 ( V_138 , V_139 ,
( V_140 ) V_132 -> V_136 . V_141 [ 0 ] . integer . V_27 ) ;
F_59 ( V_138 , V_142 ,
( V_140 ) V_132 -> V_136 . V_141 [ 1 ] . integer . V_27 ) ;
F_59 ( V_138 , V_143 ,
( V_140 ) V_132 -> V_136 . V_141 [ 2 ] . integer . V_27 ) ;
F_60 ( V_138 ) ;
return 0 ;
}
static void F_61 ( struct V_144 * V_145 )
{
T_1 V_146 ;
T_2 V_22 ;
if ( F_7 ( V_31 ) ) {
V_22 = F_37 ( & V_146 , V_31 ) ;
if ( F_24 ( V_22 ) ) {
if ( V_2 -> V_32 == 3 )
F_62 ( V_147 , ! V_146 ) ;
else
F_63 ( V_147 , ! V_146 ) ;
}
}
if ( F_7 ( V_33 ) ) {
V_22 = F_37 ( & V_146 , V_33 ) ;
if ( F_24 ( V_22 ) )
F_63 ( V_148 , ! V_146 ) ;
}
if ( F_7 ( V_73 ) && F_21 ( V_90 ) ) {
V_22 = F_37 ( & V_146 , V_95 ) ;
if ( F_24 ( V_22 ) )
F_63 ( V_149 , ! V_146 ) ;
}
F_64 ( & V_150 , F_65 ( V_151 ) ) ;
}
static int F_66 ( void * V_152 , bool V_153 )
{
T_2 V_22 ;
T_1 V_16 = ( unsigned long ) V_152 ;
if ( V_154 ) {
V_22 = F_38 ( ! V_153 , V_16 ) ;
if ( F_15 ( V_22 ) )
return - V_155 ;
}
return 0 ;
}
static struct V_156 * F_67 ( struct V_80 * V_118 ,
enum V_157 type ,
char * V_158 , T_1 V_16 )
{
int V_28 ;
struct V_156 * V_159 ;
T_1 V_146 ;
T_2 V_22 ;
V_159 = F_68 ( V_158 , V_118 , type ,
& V_160 ,
( void * ) ( unsigned long ) V_16 ) ;
if ( ! V_159 )
return F_69 ( - V_161 ) ;
V_22 = F_37 ( & V_146 , V_16 ) ;
V_28 = F_70 ( V_159 ) ;
if ( V_28 ) {
F_71 ( V_159 ) ;
return F_69 ( V_28 ) ;
}
if ( F_24 ( V_22 ) )
F_63 ( V_159 , ! V_146 ) ;
return V_159 ;
}
static int F_72 ( struct V_80 * V_118 )
{
int V_28 ;
if ( F_7 ( V_31 ) ) {
V_147 = F_67 ( V_118 , V_162 ,
L_12 , V_31 ) ;
if ( F_49 ( V_147 ) ) {
V_28 = F_51 ( V_147 ) ;
goto V_163;
}
}
if ( F_7 ( V_33 ) ) {
V_148 = F_67 ( V_118 ,
V_164 , L_13 ,
V_33 ) ;
if ( F_49 ( V_148 ) ) {
V_28 = F_51 ( V_148 ) ;
goto V_165;
}
}
if ( F_7 ( V_73 ) ) {
V_149 = F_67 ( V_118 ,
V_166 , L_14 ,
V_73 ) ;
if ( F_49 ( V_149 ) ) {
V_28 = F_51 ( V_149 ) ;
goto V_167;
}
}
V_154 = true ;
if ( ( V_168 || ! F_21 ( V_169 ) ) &&
F_7 ( V_31 | V_33 | V_73 ) )
F_64 ( & V_150 ,
F_65 ( V_151 ) ) ;
return 0 ;
V_167:
if ( F_7 ( V_33 ) ) {
F_73 ( V_148 ) ;
F_71 ( V_148 ) ;
}
V_165:
if ( F_7 ( V_31 ) ) {
F_73 ( V_147 ) ;
F_71 ( V_147 ) ;
}
V_163:
return V_28 ;
}
static void F_74 ( void )
{
if ( ( V_168 || ! F_21 ( V_169 ) ) &&
F_7 ( V_31 | V_33 | V_73 ) )
F_75 ( & V_150 ) ;
if ( F_7 ( V_31 ) ) {
F_73 ( V_147 ) ;
F_71 ( V_147 ) ;
}
if ( F_7 ( V_33 ) ) {
F_73 ( V_148 ) ;
F_71 ( V_148 ) ;
}
if ( F_7 ( V_73 ) ) {
F_73 ( V_149 ) ;
F_71 ( V_149 ) ;
}
return;
}
static T_7 F_76 ( struct V_80 * V_118 ,
struct V_170 * V_171 , char * V_172 )
{
T_1 V_20 ; \
T_2 V_22 ;
F_4 ( L_15 ,
V_173 -> V_174 ) ;
V_22 = F_37 ( & V_20 , V_73 ) ;
if ( F_24 ( V_22 ) )
return sprintf ( V_172 , L_16 , V_20 ) ;
return sprintf ( V_172 , L_17 ) ;
}
static T_7 F_77 ( struct V_80 * V_118 ,
struct V_170 * V_171 , const char * V_172 , T_8 V_137 )
{
T_1 V_66 = F_78 ( V_172 , NULL , 10 ) ;
T_2 V_22 = F_38 ( V_66 , V_73 ) ;
F_4 ( L_15 ,
V_173 -> V_174 ) ;
if ( F_15 ( V_22 ) )
return - V_175 ;
return V_137 ;
}
static T_7 F_79 ( struct V_80 * V_118 , struct V_170 * V_171 ,
char * V_172 )
{
F_4 ( L_18 ,
V_173 -> V_174 ) ;
switch ( V_1 -> type ) {
case V_110 :
return sprintf ( V_172 , L_19 ) ;
case V_111 :
return sprintf ( V_172 , L_20 ) ;
case V_112 :
return sprintf ( V_172 , L_21 ) ;
case V_113 :
return sprintf ( V_172 , L_22 ) ;
default:
return sprintf ( V_172 , L_23 ) ;
}
}
static void F_80 ( T_1 V_27 , void * V_56 )
{
struct V_19 V_176 = { V_48 , NULL } ;
union V_49 * V_50 ;
struct V_177 V_82 ;
T_2 V_22 ;
T_4 V_178 ;
const struct V_179 * V_180 ;
V_22 = F_81 ( V_27 , & V_176 ) ;
if ( V_22 != V_30 ) {
F_30 ( L_24 , V_22 ) ;
return;
}
V_50 = (union V_49 * ) V_176 . V_24 ;
if ( ! V_50 )
return;
if ( V_50 -> type != V_51 ) {
F_30 ( L_25 , V_50 -> type ) ;
F_16 ( V_50 ) ;
return;
}
if ( V_50 -> V_52 . V_23 != 8 ) {
F_30 ( L_2 , V_50 -> V_52 . V_23 ) ;
F_16 ( V_50 ) ;
return;
}
V_82 = * ( (struct V_177 * ) V_50 -> V_52 . V_24 ) ;
F_16 ( V_50 ) ;
switch ( V_82 . V_181 ) {
case V_182 :
V_178 = V_82 . V_178 ;
F_82 ( L_26 , V_178 ) ;
V_180 = F_83 ( V_183 ,
V_82 . V_184 ) ;
if ( ! V_180 ) {
F_30 ( L_27 ,
V_82 . V_184 ) ;
} else {
switch ( V_180 -> V_185 ) {
case V_186 :
case V_187 :
if ( F_7 ( V_31 ) )
F_63 ( V_147 ,
! ( V_178 & V_93 ) ) ;
if ( F_7 ( V_73 ) )
F_63 ( V_149 ,
! ( V_178 & V_95 ) ) ;
if ( F_7 ( V_33 ) )
F_63 ( V_148 ,
! ( V_178 & V_94 ) ) ;
break;
}
F_84 ( V_183 , V_180 ,
1 , true ) ;
}
break;
case V_188 :
F_58 () ;
break;
default:
F_30 ( L_28 ,
V_82 . V_181 , V_82 . V_184 ) ;
break;
}
}
static T_2
F_85 ( struct V_189 * V_84 ,
struct V_190 * V_82 )
{
T_2 V_22 ;
union V_49 * V_50 ;
struct V_19 V_21 = { sizeof( struct V_189 ) , V_84 } ;
struct V_19 V_89 = { V_48 , NULL } ;
V_22 = F_9 ( V_90 , 0 , 0x1 , & V_21 , & V_89 ) ;
if ( F_15 ( V_22 ) )
return V_22 ;
V_50 = V_89 . V_24 ;
if ( ! V_50 )
return V_29 ;
else if ( V_50 -> type != V_51 ) {
F_16 ( V_50 ) ;
return V_29 ;
}
if ( V_50 -> V_52 . V_23 != 4 ) {
F_30 ( L_2 , V_50 -> V_52 . V_23 ) ;
F_16 ( V_50 ) ;
return V_29 ;
}
* V_82 = * ( (struct V_190 * ) V_50 -> V_52 . V_24 ) ;
F_16 ( V_50 ) ;
return V_22 ;
}
static int F_86 ( void )
{
struct V_190 V_82 ;
T_2 V_22 ;
struct V_189 V_84 = {
. V_85 = 0x1 ,
. V_191 = 0xFFFF ,
. V_88 = 0xFFFF ,
. V_192 = 0x00 ,
} ;
V_22 = F_85 ( & V_84 , & V_82 ) ;
if ( V_82 . V_91 || V_82 . V_92 )
F_30 ( L_29 ,
V_82 . V_91 ,
V_82 . V_92 ) ;
else
F_4 ( L_30 ) ;
return V_22 ;
}
static int F_87 ( void )
{
struct V_190 V_82 ;
T_2 V_22 ;
struct V_189 V_84 = {
. V_85 = 0x1 ,
. V_191 = 0xFFFF ,
. V_88 = 0xFFFF ,
. V_192 = 0x01 ,
} ;
V_22 = F_85 ( & V_84 , & V_82 ) ;
if ( V_82 . V_91 || V_82 . V_92 )
F_30 ( L_31 ,
V_82 . V_91 ,
V_82 . V_92 ) ;
return V_22 ;
}
static T_2 T_5 F_88 ( T_3 V_193 , T_1 V_55 ,
void * V_194 , void * * V_57 )
{
* ( T_3 * ) V_57 = V_193 ;
return V_30 ;
}
static int T_5 F_89 ( const char * V_158 , const char * V_195 ,
T_3 * V_193 )
{
T_2 V_22 ;
T_3 V_54 ;
F_90 ( ! V_158 || ! V_193 ) ;
V_54 = NULL ;
V_22 = F_19 ( V_195 , F_88 ,
( void * ) V_158 , & V_54 ) ;
if ( F_24 ( V_22 ) ) {
* V_193 = V_54 ;
return 0 ;
} else {
return - V_155 ;
}
}
static int T_5 F_91 ( void )
{
int V_28 ;
V_28 = F_89 ( L_32 , L_33 , & V_133 ) ;
if ( V_28 )
return V_28 ;
V_1 -> V_4 |= V_135 ;
V_138 = F_92 () ;
if ( ! V_138 )
return - V_161 ;
V_138 -> V_196 = F_57 ;
V_138 -> V_158 = L_34 ;
V_138 -> V_197 = L_35 ;
V_138 -> V_60 . V_198 = V_199 ;
V_138 -> V_200 [ 0 ] = F_93 ( V_201 ) ;
F_94 ( V_138 , V_139 , - 16384 , 16384 , 0 , 0 ) ;
F_94 ( V_138 , V_142 , - 16384 , 16384 , 0 , 0 ) ;
F_94 ( V_138 , V_143 , - 16384 , 16384 , 0 , 0 ) ;
V_28 = F_95 ( V_138 ) ;
if ( V_28 )
goto V_202;
return 0 ;
V_202:
F_96 ( V_138 ) ;
return V_28 ;
}
static void F_97 ( void )
{
F_98 ( V_138 ) ;
}
static int T_5 F_99 ( void )
{
T_2 V_22 ;
int V_28 ;
V_183 = F_92 () ;
if ( ! V_183 )
return - V_161 ;
V_183 -> V_158 = L_36 ;
V_183 -> V_197 = L_37 ;
V_183 -> V_60 . V_198 = V_199 ;
V_28 = F_100 ( V_183 , V_203 , NULL ) ;
if ( V_28 )
goto V_202;
V_22 = F_101 ( V_169 ,
F_80 , NULL ) ;
if ( F_15 ( V_22 ) ) {
V_28 = - V_204 ;
goto V_205;
}
V_28 = F_95 ( V_183 ) ;
if ( V_28 )
goto V_206;
return 0 ;
V_206:
F_102 ( V_169 ) ;
V_205:
F_103 ( V_183 ) ;
V_202:
F_96 ( V_183 ) ;
return V_28 ;
}
static void F_104 ( void )
{
F_102 ( V_169 ) ;
F_103 ( V_183 ) ;
F_98 ( V_183 ) ;
}
static T_1 F_105 ( void )
{
struct V_19 V_47 = { V_48 , NULL } ;
union V_49 * V_50 ;
T_2 V_22 ;
T_1 V_88 = 0 ;
V_22 = F_36 ( V_109 , 1 , & V_47 ) ;
if ( F_15 ( V_22 ) )
return 0 ;
V_50 = (union V_49 * ) V_47 . V_24 ;
if ( V_50 && V_50 -> type == V_51 &&
( V_50 -> V_52 . V_23 == sizeof( T_1 ) ||
V_50 -> V_52 . V_23 == sizeof( V_68 ) ) ) {
V_88 = * ( ( T_1 * ) V_50 -> V_52 . V_24 ) ;
} else if ( V_50 -> type == V_69 ) {
V_88 = ( T_1 ) V_50 -> integer . V_27 ;
}
F_16 ( V_47 . V_24 ) ;
return V_88 ;
}
static int T_6 F_106 ( struct V_207 * V_80 )
{
int V_28 ;
if ( F_7 ( V_5 ) ) {
V_28 = F_41 ( & V_80 -> V_118 ) ;
if ( V_28 )
goto V_208;
}
if ( F_7 ( V_7 ) ) {
V_28 = F_47 ( & V_80 -> V_118 ) ;
if ( V_28 )
goto V_209;
}
V_28 = F_72 ( & V_80 -> V_118 ) ;
if ( V_28 )
goto V_210;
return V_28 ;
V_210:
if ( F_7 ( V_7 ) )
F_53 () ;
V_209:
if ( F_7 ( V_5 ) )
F_43 () ;
V_208:
return V_28 ;
}
static int F_107 ( struct V_207 * V_80 )
{
if ( F_7 ( V_5 ) )
F_43 () ;
if ( F_7 ( V_7 ) )
F_53 () ;
F_74 () ;
return 0 ;
}
static int F_108 ( struct V_80 * V_118 )
{
T_1 V_27 ;
struct V_211 * V_152 = & V_1 -> V_152 ;
if ( ! V_152 )
return - V_161 ;
if ( F_7 ( V_5 ) ) {
F_37 ( & V_27 , V_5 ) ;
F_38 ( V_120 , V_5 ) ;
V_152 -> V_3 = V_27 ;
}
if ( F_7 ( V_7 ) ) {
F_37 ( & V_27 , V_7 ) ;
V_152 -> V_6 = V_27 ;
}
return 0 ;
}
static int F_109 ( struct V_80 * V_118 )
{
struct V_211 * V_152 = & V_1 -> V_152 ;
if ( ! V_152 )
return - V_161 ;
if ( F_7 ( V_5 ) )
F_38 ( V_152 -> V_3 , V_5 ) ;
if ( F_7 ( V_7 ) )
F_38 ( V_152 -> V_6 , V_7 ) ;
if ( F_7 ( V_135 ) )
F_55 () ;
return 0 ;
}
static void F_110 ( struct V_207 * V_80 )
{
struct V_211 * V_152 = & V_1 -> V_152 ;
if ( ! V_152 )
return;
if ( F_7 ( V_5 ) )
F_38 ( V_120 , V_5 ) ;
}
static int F_111 ( struct V_207 * V_80 )
{
if ( F_7 ( V_73 ) )
F_112 ( & V_80 -> V_118 , & V_212 ) ;
F_112 ( & V_80 -> V_118 , & V_213 ) ;
return 0 ;
}
static int F_113 ( void )
{
int V_57 = - V_161 ;
if ( F_7 ( V_73 ) ) {
V_57 = F_114 ( & V_214 -> V_118 ,
& V_212 ) ;
if ( V_57 )
goto V_215;
}
V_57 = F_114 ( & V_214 -> V_118 ,
& V_213 ) ;
if ( V_57 )
goto V_215;
return 0 ;
V_215:
F_111 ( V_214 ) ;
return V_57 ;
}
static void F_115 ( void )
{
F_116 ( V_1 -> V_216 . V_88 ) ;
F_116 ( V_1 -> V_216 . V_217 ) ;
}
static int F_117 ( void )
{
V_1 -> V_216 . V_217 = F_118 ( L_8 , NULL ) ;
if ( ! V_1 -> V_216 . V_217 ) {
F_50 ( L_38 ) ;
return - V_161 ;
}
V_1 -> V_216 . V_88 = F_119 ( L_39 , V_218 ,
V_1 -> V_216 . V_217 ,
& V_1 -> V_216 . V_219 ) ;
if ( ! V_1 -> V_216 . V_88 )
goto V_220;
return 0 ;
V_220:
F_115 () ;
return - V_161 ;
}
static int T_5 F_120 ( void )
{
int V_28 ;
F_4 ( L_40 ) ;
if ( F_6 ( V_221 ) ) {
F_4 ( L_41 ) ;
return - V_155 ;
}
F_5 () ;
if ( F_21 ( V_26 ) && F_21 ( V_67 ) )
V_1 = & V_222 ;
if ( ! F_21 ( V_26 ) && F_21 ( V_67 ) )
V_1 = & V_223 ;
if ( F_21 ( V_90 ) )
V_1 = & V_224 ;
if ( V_1 )
F_121 ( F_34 , NULL ) ;
if ( F_21 ( V_109 ) && V_1 ) {
if ( ! V_108 && F_15 ( F_35 () ) ) {
F_50 ( L_42 ) ;
return - V_155 ;
}
V_1 -> V_4 |= V_7 ;
} else if ( ! F_21 ( V_109 ) && V_1 && ! V_108 ) {
F_50 ( L_43 ) ;
return - V_155 ;
}
if ( F_21 ( V_26 ) && ! F_21 ( V_67 ) ) {
V_1 = & V_225 ;
if ( F_15 ( F_20 () ) ) {
F_50 ( L_44 ) ;
return - V_155 ;
}
}
if ( F_21 ( V_26 ) )
F_14 () ;
if ( ! V_1 ) {
F_50 ( L_45 ) ;
return - V_155 ;
}
F_1 () ;
if ( F_6 ( V_226 ) )
F_122 () ;
if ( F_123 () ) {
V_1 -> V_4 &= ~ V_7 ;
F_4 ( L_46 ) ;
} else {
F_4 ( L_47 ) ;
F_124 () ;
}
if ( F_21 ( V_90 ) ) {
if ( V_168 ) {
if ( F_15 ( F_86 () ) ) {
F_50 ( L_48 ) ;
return - V_155 ;
}
} else if ( F_15 ( F_87 () ) ) {
F_50 ( L_49 ) ;
return - V_155 ;
}
} else if ( V_168 ) {
F_4 ( L_50 ) ;
}
if ( F_21 ( V_169 ) ) {
V_28 = F_99 () ;
if ( V_28 )
return V_28 ;
}
F_91 () ;
V_28 = F_125 ( & V_227 ) ;
if ( V_28 ) {
F_50 ( L_51 ) ;
goto V_228;
}
V_214 = F_126 ( L_8 , - 1 ) ;
if ( ! V_214 ) {
V_28 = - V_161 ;
goto V_229;
}
V_28 = F_127 ( V_214 ) ;
if ( V_28 )
goto V_230;
V_28 = F_113 () ;
if ( V_28 )
goto V_231;
if ( F_21 ( V_109 ) ) {
V_1 -> V_216 . V_219 = F_105 () ;
V_28 = F_117 () ;
if ( V_28 )
goto V_232;
}
F_39 () ;
return 0 ;
V_232:
F_111 ( V_214 ) ;
V_231:
F_128 ( V_214 ) ;
V_230:
F_129 ( V_214 ) ;
V_229:
F_130 ( & V_227 ) ;
V_228:
if ( F_21 ( V_169 ) )
F_104 () ;
if ( F_7 ( V_135 ) )
F_97 () ;
return V_28 ;
}
static void T_9 F_131 ( void )
{
if ( F_21 ( V_169 ) )
F_104 () ;
if ( F_7 ( V_135 ) )
F_97 () ;
F_111 ( V_214 ) ;
F_115 () ;
F_132 ( V_214 ) ;
F_130 ( & V_227 ) ;
F_4 ( L_52 ) ;
return;
}
