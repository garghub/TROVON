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
static void F_3 ( void )
{
if ( ! V_11 ) {
F_4 ( V_12 ) ;
} else if ( V_11 == 2490 ) {
V_2 = & V_13 ;
}
if ( V_2 == NULL )
V_2 = & V_14 ;
F_1 () ;
}
static bool F_5 ( T_1 V_15 )
{
if ( ( V_1 -> V_4 & V_15 ) != 0 )
return 1 ;
return 0 ;
}
static T_2 F_6 ( struct V_16 * V_17 ,
struct V_18 * V_19 )
{
struct V_18 V_20 ;
T_2 V_21 ;
V_20 . V_22 = sizeof( struct V_16 ) ;
V_20 . V_23 = ( V_24 * ) V_17 ;
V_21 = F_7 ( V_25 , 1 , 1 , & V_20 , V_19 ) ;
return V_21 ;
}
static T_2 F_8 ( T_1 * V_26 , T_1 V_15 ,
struct V_27 * V_28 )
{
int V_29 ;
V_24 V_19 ;
switch ( V_15 ) {
case V_5 :
switch ( V_2 -> V_3 ) {
default:
V_29 = F_9 ( 0xA , & V_19 ) ;
if ( V_29 )
return V_30 ;
* V_26 = ( V_19 >> 7 ) & 0x1 ;
return V_31 ;
}
break;
case V_32 :
switch ( V_2 -> V_33 ) {
case 1 :
V_29 = F_9 ( 0x7B , & V_19 ) ;
if ( V_29 )
return V_30 ;
* V_26 = V_19 & 0x1 ;
return V_31 ;
case 2 :
V_29 = F_9 ( 0x71 , & V_19 ) ;
if ( V_29 )
return V_30 ;
* V_26 = V_19 & 0x1 ;
return V_31 ;
case 3 :
V_29 = F_9 ( 0x78 , & V_19 ) ;
if ( V_29 )
return V_30 ;
* V_26 = V_19 & 0x1 ;
return V_31 ;
default:
V_29 = F_9 ( 0xA , & V_19 ) ;
if ( V_29 )
return V_30 ;
* V_26 = ( V_19 >> 2 ) & 0x1 ;
return V_31 ;
}
break;
case V_34 :
switch ( V_2 -> V_35 ) {
default:
V_29 = F_9 ( 0xA , & V_19 ) ;
if ( V_29 )
return V_30 ;
* V_26 = ( V_19 >> 4 ) & 0x1 ;
return V_31 ;
}
break;
case V_7 :
switch ( V_2 -> V_6 ) {
default:
V_29 = F_9 ( 0x83 , & V_19 ) ;
if ( V_29 )
return V_30 ;
* V_26 = V_19 ;
return V_31 ;
}
break;
default:
return V_30 ;
}
return V_31 ;
}
static T_2 F_10 ( T_1 V_26 , T_1 V_15 , struct V_27 * V_28 )
{
struct V_16 args ;
args . V_36 = V_37 ;
args . V_38 = V_26 ? ( 1 << 8 ) : 0 ;
args . V_39 = args . V_40 = 0 ;
switch ( V_15 ) {
case V_5 :
if ( V_26 > 1 )
return V_41 ;
args . V_38 |= V_42 ;
break;
case V_32 :
if ( V_26 > 1 )
return V_41 ;
args . V_38 |= V_43 ;
break;
case V_34 :
if ( V_26 > 1 )
return V_41 ;
args . V_38 |= V_44 ;
break;
case V_7 :
if ( V_26 > V_45 )
return V_41 ;
switch ( V_2 -> V_6 ) {
default:
return F_11 ( 0x83 , V_26 ) ;
break;
}
default:
return V_30 ;
}
return F_6 ( & args , NULL ) ;
}
static T_2 F_12 ( void )
{
struct V_16 args ;
struct V_46 V_47 ;
T_2 V_21 = V_31 ;
struct V_18 V_48 = { V_49 , NULL } ;
union V_50 * V_51 ;
args . V_36 = 0x86 ;
args . V_38 = args . V_39 = args . V_40 = 0 ;
V_21 = F_6 ( & args , & V_48 ) ;
if ( F_13 ( V_21 ) )
return V_21 ;
V_51 = (union V_50 * ) V_48 . V_23 ;
if ( V_51 && V_51 -> type == V_52 &&
V_51 -> V_53 . V_22 == sizeof( struct V_46 ) ) {
V_47 = * ( (struct V_46 * ) V_51 -> V_53 . V_23 ) ;
} else {
F_14 ( V_48 . V_23 ) ;
return V_30 ;
}
if ( V_47 . V_54 & 0x1 )
V_1 -> V_4 |= V_5 ;
F_14 ( V_48 . V_23 ) ;
return V_31 ;
}
static T_2 F_15 ( T_3 V_55 ,
T_1 V_56 , void * V_57 , void * * V_58 )
{
V_59 = 1 ;
return V_31 ;
}
static int F_16 ( void )
{
const struct V_60 * V_61 ;
for ( V_61 = V_62 ; V_61 -> V_61 [ 0 ] ; V_61 ++ )
F_17 ( V_61 -> V_61 , F_15 ,
NULL , NULL ) ;
return V_59 ;
}
static T_2 F_18 ( void )
{
struct V_16 args ;
struct V_46 V_47 ;
T_2 V_21 ;
struct V_18 V_48 = { V_49 , NULL } ;
union V_50 * V_51 ;
if ( F_19 ( V_63 ) ) {
if ( ( V_2 != & V_14 ) ||
! F_16 () )
V_1 -> V_4 |= V_32 ;
return V_31 ;
}
args . V_36 = V_37 ;
args . V_39 = args . V_40 = 0 ;
args . V_38 = 0xa2 << 8 ;
args . V_38 |= V_43 ;
V_21 = F_6 ( & args , & V_48 ) ;
if ( F_13 ( V_21 ) )
return V_21 ;
V_51 = V_48 . V_23 ;
if ( V_51 && V_51 -> type == V_52 &&
V_51 -> V_53 . V_22 == sizeof( struct V_46 ) ) {
V_47 = * ( (struct V_46 * ) V_51 -> V_53 . V_23 ) ;
} else {
V_21 = V_30 ;
goto V_48;
}
if ( V_47 . V_36 & 0x1 )
V_1 -> V_4 |= V_32 ;
args . V_38 = 2 << 8 ;
args . V_38 |= V_44 ;
V_21 = F_6 ( & args , & V_48 ) ;
if ( F_13 ( V_21 ) )
goto V_48;
V_51 = (union V_50 * ) V_48 . V_23 ;
if ( V_51 && V_51 -> type == V_52
&& V_51 -> V_53 . V_22 == sizeof( struct V_46 ) ) {
V_47 = * ( (struct V_46 * ) V_51 -> V_53 . V_23 ) ;
} else {
V_21 = V_30 ;
goto V_48;
}
if ( V_47 . V_36 & 0x1 )
V_1 -> V_4 |= V_34 ;
if ( V_2 -> V_6 >= 0 )
V_1 -> V_4 |= V_7 ;
V_21 = V_31 ;
V_48:
F_14 ( V_48 . V_23 ) ;
return V_21 ;
}
static T_2
F_20 ( T_1 V_64 , T_1 V_65 , T_1 * V_48 )
{
struct V_18 V_20 = { ( V_66 ) sizeof( T_1 ) , ( void * ) ( & V_65 ) } ;
struct V_18 V_19 = { V_49 , NULL } ;
union V_50 * V_51 ;
T_1 V_67 ;
T_2 V_21 ;
V_21 = F_7 ( V_68 , 1 , V_64 , & V_20 , & V_19 ) ;
if ( F_13 ( V_21 ) )
return V_21 ;
V_51 = (union V_50 * ) V_19 . V_23 ;
if ( V_51 && V_51 -> type == V_52 &&
( V_51 -> V_53 . V_22 == sizeof( T_1 ) ||
V_51 -> V_53 . V_22 == sizeof( V_69 ) ) ) {
V_67 = * ( ( T_1 * ) V_51 -> V_53 . V_23 ) ;
} else if ( V_51 -> type == V_70 ) {
V_67 = ( T_1 ) V_51 -> integer . V_26 ;
} else {
V_67 = 0 ;
}
if ( V_48 )
* V_48 = V_67 ;
F_14 ( V_19 . V_23 ) ;
return V_21 ;
}
static T_2 F_21 ( T_1 * V_26 , T_1 V_15 ,
struct V_27 * V_28 )
{
T_2 V_21 ;
V_24 V_67 ;
T_1 V_19 , V_64 = 0 ;
switch ( V_15 ) {
case V_32 :
V_64 = V_71 ;
break;
case V_34 :
V_64 = V_72 ;
break;
case V_7 :
V_64 = V_73 ;
break;
case V_74 :
V_64 = V_75 ;
break;
case V_5 :
if ( V_2 -> V_3 == 1 ) {
F_9 ( 0x9f , & V_67 ) ;
* V_26 = V_67 & 0x1 ;
return 0 ;
}
default:
return V_30 ;
}
V_21 = F_20 ( V_64 , 0 , & V_19 ) ;
if ( F_22 ( V_21 ) )
* V_26 = ( V_24 ) V_19 ;
return V_21 ;
}
static T_2 F_23 ( T_1 V_26 , T_1 V_15 , struct V_27 * V_28 )
{
T_1 V_64 = 0 ;
char V_76 ;
switch ( V_15 ) {
case V_7 :
if ( V_26 > V_45 )
return V_41 ;
V_64 = V_77 ;
break;
case V_32 :
if ( V_26 > 1 )
return V_41 ;
V_64 = V_78 ;
break;
case V_34 :
if ( V_26 > 1 )
return V_41 ;
V_64 = V_79 ;
break;
case V_74 :
if ( V_26 > 1 )
return V_41 ;
V_64 = V_80 ;
break;
case V_5 :
if ( V_26 > 1 )
return V_41 ;
if ( V_2 -> V_3 == 1 ) {
V_76 = V_26 ? 0x92 : 0x93 ;
F_24 () ;
F_25 ( & V_76 , 0x1059 ) ;
F_26 () ;
return 0 ;
}
break;
default:
return V_30 ;
}
return F_20 ( V_64 , ( T_1 ) V_26 , NULL ) ;
}
static T_2 F_27 ( T_1 * V_26 , T_4 V_81 )
{
struct V_82 V_83 ;
T_2 V_21 ;
union V_50 * V_51 ;
struct V_84 V_85 = {
. V_86 = 0x1 ,
. V_87 = 0x01 ,
. V_88 = V_81 ,
} ;
struct V_18 V_20 = {
sizeof( struct V_84 ) ,
& V_85
} ;
struct V_18 V_89 = { V_49 , NULL } ;
V_21 = F_7 ( V_90 , 0 , 0x2 , & V_20 , & V_89 ) ;
if ( F_13 ( V_21 ) )
return V_21 ;
V_51 = V_89 . V_23 ;
if ( ! V_51 )
return V_30 ;
else if ( V_51 -> type != V_52 ) {
F_14 ( V_51 ) ;
return V_30 ;
}
if ( V_51 -> V_53 . V_22 != 8 ) {
F_28 ( L_1 , V_51 -> V_53 . V_22 ) ;
F_14 ( V_51 ) ;
return V_30 ;
}
V_83 = * ( (struct V_82 * ) V_51 -> V_53 . V_23 ) ;
F_14 ( V_51 ) ;
if ( V_83 . V_91 || V_83 . V_92 )
F_28 ( L_2 ,
V_81 ,
V_83 . V_91 ,
V_83 . V_92 ) ;
else
* V_26 = ! ! ( V_83 . V_88 & V_81 ) ;
return V_21 ;
}
static T_2 F_29 ( T_1 * V_26 , T_1 V_15 )
{
T_4 V_81 ;
switch ( V_15 ) {
case V_32 :
V_81 = V_93 ;
break;
case V_34 :
V_81 = V_94 ;
break;
case V_74 :
V_81 = V_95 ;
break;
default:
return V_30 ;
}
return F_27 ( V_26 , V_81 ) ;
}
static T_2 F_30 ( T_1 V_26 , T_4 V_81 )
{
struct V_82 V_83 ;
T_2 V_21 ;
union V_50 * V_51 ;
T_4 V_88 ;
struct V_84 V_85 = {
. V_86 = 0x1 ,
. V_87 = 0x01 ,
. V_88 = V_96 ,
} ;
struct V_18 V_20 = {
sizeof( struct V_84 ) ,
& V_85
} ;
struct V_18 V_89 = { V_49 , NULL } ;
struct V_18 V_97 = { V_49 , NULL } ;
V_21 = F_7 ( V_90 , 0 , 0x2 , & V_20 , & V_89 ) ;
if ( F_13 ( V_21 ) )
return V_21 ;
V_51 = V_89 . V_23 ;
if ( ! V_51 )
return V_30 ;
else if ( V_51 -> type != V_52 ) {
F_14 ( V_51 ) ;
return V_30 ;
}
if ( V_51 -> V_53 . V_22 != 8 ) {
F_31 ( L_1 , V_51 -> V_53 . V_22 ) ;
F_14 ( V_51 ) ;
return V_30 ;
}
V_83 = * ( (struct V_82 * ) V_51 -> V_53 . V_23 ) ;
F_14 ( V_51 ) ;
if ( V_83 . V_91 || V_83 . V_92 ) {
F_31 ( L_3
L_4 , V_83 . V_91 ,
V_83 . V_92 ) ;
return V_21 ;
}
V_88 = V_83 . V_88 ;
V_85 . V_86 = 0x2 ;
V_85 . V_87 = 0x01 ;
V_85 . V_88 = ( V_26 ) ? ( V_88 | V_81 ) : ( V_88 & ~ V_81 ) ;
V_21 = F_7 ( V_90 , 0 , 0x1 , & V_20 , & V_97 ) ;
if ( F_13 ( V_21 ) )
return V_21 ;
V_51 = V_97 . V_23 ;
if ( ! V_51 )
return V_30 ;
else if ( V_51 -> type != V_52 ) {
F_14 ( V_51 ) ;
return V_30 ;
}
if ( V_51 -> V_53 . V_22 != 4 ) {
F_31 ( L_1 , V_51 -> V_53 . V_22 ) ;
F_14 ( V_51 ) ;
return V_30 ;
}
V_83 = * ( (struct V_82 * ) V_51 -> V_53 . V_23 ) ;
F_14 ( V_51 ) ;
if ( V_83 . V_91 || V_83 . V_92 )
F_31 ( L_5
L_4 , V_83 . V_91 ,
V_83 . V_92 ) ;
return V_21 ;
}
static T_2 F_32 ( T_1 V_26 , T_1 V_15 )
{
T_4 V_81 ;
switch ( V_15 ) {
case V_32 :
V_81 = V_93 ;
break;
case V_34 :
V_81 = V_94 ;
break;
case V_74 :
V_81 = V_95 ;
break;
default:
return V_30 ;
}
return F_30 ( V_26 , V_81 ) ;
}
static void F_33 ( const struct V_98 * V_99 , void * V_100 )
{
struct V_101 * V_102 ;
if ( V_99 -> type != 0xAA )
return;
V_103 = true ;
V_102 = (struct V_101 * ) V_99 ;
F_34 ( L_6 ,
V_102 -> V_96 ) ;
V_96 = V_102 -> V_96 ;
if ( V_102 -> V_96 & V_93 )
V_1 -> V_4 |= V_32 ;
if ( V_102 -> V_96 & V_95 )
V_1 -> V_4 |= V_74 ;
if ( V_102 -> V_96 & V_94 )
V_1 -> V_4 |= V_34 ;
}
static T_2 F_35 ( void )
{
struct V_18 V_48 = { V_49 , NULL } ;
union V_50 * V_51 ;
T_2 V_21 ;
T_1 V_88 ;
V_21 = F_36 ( V_104 , 1 , & V_48 ) ;
if ( F_13 ( V_21 ) )
return V_21 ;
V_51 = (union V_50 * ) V_48 . V_23 ;
if ( V_51 && V_51 -> type == V_52 &&
( V_51 -> V_53 . V_22 == sizeof( T_1 ) ||
V_51 -> V_53 . V_22 == sizeof( V_69 ) ) ) {
V_88 = * ( ( T_1 * ) V_51 -> V_53 . V_23 ) ;
} else if ( V_51 -> type == V_70 ) {
V_88 = ( T_1 ) V_51 -> integer . V_26 ;
} else {
F_14 ( V_48 . V_23 ) ;
return V_30 ;
}
F_34 ( L_7 , V_88 ) ;
if ( V_88 & 0x07 )
V_1 -> V_4 |= V_32 ;
if ( V_88 & 0x40 )
V_1 -> V_4 |= V_74 ;
if ( V_88 & 0x10 )
V_1 -> V_4 |= V_34 ;
if ( ! ( V_88 & 0x20 ) )
V_45 = 0x9 ;
F_14 ( V_48 . V_23 ) ;
return V_21 ;
}
static T_2 F_37 ( T_1 * V_26 , T_1 V_15 )
{
T_2 V_21 = V_30 ;
switch ( V_1 -> type ) {
case V_105 :
V_21 = F_8 ( V_26 , V_15 , V_1 ) ;
break;
case V_106 :
if ( V_15 == V_5 ) {
V_21 = F_8 ( V_26 , V_15 , V_1 ) ;
break;
}
case V_107 :
V_21 = F_21 ( V_26 , V_15 , V_1 ) ;
break;
case V_108 :
if ( V_15 & ( V_32 |
V_34 |
V_74 ) )
V_21 = F_29 ( V_26 , V_15 ) ;
else if ( F_19 ( V_104 ) )
V_21 = F_21 ( V_26 , V_15 , V_1 ) ;
break;
}
return V_21 ;
}
static T_2 F_38 ( T_1 V_26 , T_1 V_15 )
{
T_2 V_21 ;
if ( V_1 -> V_4 & V_15 ) {
switch ( V_1 -> type ) {
case V_105 :
return F_10 ( V_26 , V_15 , V_1 ) ;
case V_106 :
if ( V_15 == V_5 )
return F_10 ( V_26 , V_15 , V_1 ) ;
if ( V_15 == V_32 ||
V_15 == V_34 ) {
V_21 = F_23 ( V_26 , V_15 , V_1 ) ;
if ( F_13 ( V_21 ) )
return V_21 ;
return F_10 ( V_26 , V_15 , V_1 ) ;
}
case V_107 :
return F_23 ( V_26 , V_15 , V_1 ) ;
case V_108 :
if ( V_15 & ( V_32 |
V_34 |
V_74 ) )
return F_32 ( V_26 , V_15 ) ;
else if ( F_19 ( V_104 ) )
return F_23 ( V_26 , V_15 , V_1 ) ;
default:
return V_41 ;
}
}
return V_41 ;
}
static void T_5 F_39 ( void )
{
if ( V_3 >= 0 )
F_38 ( V_3 , V_5 ) ;
if ( ! V_103 && V_109 >= 0 )
F_38 ( V_109 , V_74 ) ;
if ( V_6 >= 0 )
F_38 ( V_6 , V_7 ) ;
}
static void F_40 ( struct V_110 * V_111 ,
enum V_112 V_26 )
{
F_38 ( V_26 , V_5 ) ;
}
static int T_6 F_41 ( struct V_81 * V_113 )
{
return F_42 ( V_113 , & V_114 ) ;
}
static void F_43 ( void )
{
F_38 ( V_115 , V_5 ) ;
F_44 ( & V_114 ) ;
}
static int F_45 ( struct V_116 * V_117 )
{
T_1 V_26 ;
F_37 ( & V_26 , V_7 ) ;
return V_26 ;
}
static int F_46 ( struct V_116 * V_117 )
{
int V_118 = V_117 -> V_119 . V_6 ;
if ( V_117 -> V_119 . V_120 != V_121 )
V_118 = 0 ;
if ( V_117 -> V_119 . V_122 != V_121 )
V_118 = 0 ;
F_38 ( V_118 , V_7 ) ;
return 0 ;
}
static int T_6 F_47 ( struct V_81 * V_113 )
{
struct V_123 V_119 ;
struct V_116 * V_117 ;
memset ( & V_119 , 0 , sizeof( struct V_123 ) ) ;
V_119 . type = V_124 ;
V_119 . V_45 = V_45 ;
V_117 = F_48 ( L_8 , V_113 , NULL , & V_125 ,
& V_119 ) ;
if ( F_49 ( V_117 ) ) {
F_50 ( L_9 ) ;
V_126 = NULL ;
return F_51 ( V_117 ) ;
}
V_126 = V_117 ;
V_117 -> V_119 . V_120 = V_121 ;
V_117 -> V_119 . V_6 = F_45 ( V_117 ) ;
F_52 ( V_117 ) ;
return 0 ;
}
static void F_53 ( void )
{
F_54 ( V_126 ) ;
}
static void F_55 ( struct V_127 * V_128 )
{
T_1 V_129 ;
T_2 V_21 ;
if ( F_5 ( V_32 ) ) {
V_21 = F_37 ( & V_129 , V_32 ) ;
if ( F_22 ( V_21 ) ) {
if ( V_2 -> V_33 == 3 )
F_56 ( V_130 , ! V_129 ) ;
else
F_57 ( V_130 , ! V_129 ) ;
}
}
if ( F_5 ( V_34 ) ) {
V_21 = F_37 ( & V_129 , V_34 ) ;
if ( F_22 ( V_21 ) )
F_57 ( V_131 , ! V_129 ) ;
}
if ( F_5 ( V_74 ) && F_19 ( V_90 ) ) {
V_21 = F_37 ( & V_129 , V_95 ) ;
if ( F_22 ( V_21 ) )
F_57 ( V_132 , ! V_129 ) ;
}
F_58 ( & V_133 , F_59 ( V_134 ) ) ;
}
static int F_60 ( void * V_135 , bool V_136 )
{
T_2 V_21 ;
T_1 V_15 = ( unsigned long ) V_135 ;
if ( V_137 ) {
V_21 = F_38 ( ! V_136 , V_15 ) ;
if ( F_13 ( V_21 ) )
return - V_138 ;
}
return 0 ;
}
static struct V_139 * F_61 ( struct V_81 * V_113 ,
enum V_140 type ,
char * V_141 , T_1 V_15 )
{
int V_29 ;
struct V_139 * V_142 ;
T_1 V_129 ;
T_2 V_21 ;
V_142 = F_62 ( V_141 , V_113 , type ,
& V_143 ,
( void * ) ( unsigned long ) V_15 ) ;
if ( ! V_142 )
return F_63 ( - V_144 ) ;
V_21 = F_37 ( & V_129 , V_15 ) ;
V_29 = F_64 ( V_142 ) ;
if ( V_29 ) {
F_65 ( V_142 ) ;
return F_63 ( V_29 ) ;
}
if ( F_22 ( V_21 ) )
F_57 ( V_142 , ! V_129 ) ;
return V_142 ;
}
static int F_66 ( struct V_81 * V_113 )
{
int V_29 ;
if ( F_5 ( V_32 ) ) {
V_130 = F_61 ( V_113 , V_145 ,
L_10 , V_32 ) ;
if ( F_49 ( V_130 ) ) {
V_29 = F_51 ( V_130 ) ;
goto V_146;
}
}
if ( F_5 ( V_34 ) ) {
V_131 = F_61 ( V_113 ,
V_147 , L_11 ,
V_34 ) ;
if ( F_49 ( V_131 ) ) {
V_29 = F_51 ( V_131 ) ;
goto V_148;
}
}
if ( F_5 ( V_74 ) ) {
V_132 = F_61 ( V_113 ,
V_149 , L_12 ,
V_74 ) ;
if ( F_49 ( V_132 ) ) {
V_29 = F_51 ( V_132 ) ;
goto V_150;
}
}
V_137 = true ;
if ( ( V_151 || ! F_19 ( V_152 ) ) &&
F_5 ( V_32 | V_34 | V_74 ) )
F_58 ( & V_133 ,
F_59 ( V_134 ) ) ;
return 0 ;
V_150:
if ( F_5 ( V_34 ) ) {
F_67 ( V_131 ) ;
F_65 ( V_131 ) ;
}
V_148:
if ( F_5 ( V_32 ) ) {
F_67 ( V_130 ) ;
F_65 ( V_130 ) ;
}
V_146:
return V_29 ;
}
static void F_68 ( void )
{
if ( ( V_151 || ! F_19 ( V_152 ) ) &&
F_5 ( V_32 | V_34 | V_74 ) )
F_69 ( & V_133 ) ;
if ( F_5 ( V_32 ) ) {
F_67 ( V_130 ) ;
F_65 ( V_130 ) ;
}
if ( F_5 ( V_34 ) ) {
F_67 ( V_131 ) ;
F_65 ( V_131 ) ;
}
if ( F_5 ( V_74 ) ) {
F_67 ( V_132 ) ;
F_65 ( V_132 ) ;
}
return;
}
static T_7 F_70 ( struct V_81 * V_113 ,
struct V_153 * V_154 , char * V_155 )
{
T_1 V_19 ; \
T_2 V_21 ;
F_34 ( L_13
L_14 , V_156 -> V_157 ) ;
V_21 = F_37 ( & V_19 , V_74 ) ;
if ( F_22 ( V_21 ) )
return sprintf ( V_155 , L_15 , V_19 ) ;
return sprintf ( V_155 , L_16 ) ;
}
static T_7 F_71 ( struct V_81 * V_113 ,
struct V_153 * V_154 , const char * V_155 , T_8 V_158 )
{
T_1 V_67 = F_72 ( V_155 , NULL , 10 ) ;
T_2 V_21 = F_38 ( V_67 , V_74 ) ;
F_34 ( L_13
L_14 , V_156 -> V_157 ) ;
if ( F_13 ( V_21 ) )
return - V_159 ;
return V_158 ;
}
static T_7 F_73 ( struct V_81 * V_113 , struct V_153 * V_154 ,
char * V_155 )
{
F_34 ( L_17
L_14 , V_156 -> V_157 ) ;
switch ( V_1 -> type ) {
case V_105 :
return sprintf ( V_155 , L_18 ) ;
case V_106 :
return sprintf ( V_155 , L_19 ) ;
case V_107 :
return sprintf ( V_155 , L_20 ) ;
case V_108 :
return sprintf ( V_155 , L_21 ) ;
default:
return sprintf ( V_155 , L_22 ) ;
}
}
static void F_74 ( T_1 V_26 , void * V_57 )
{
struct V_18 V_160 = { V_49 , NULL } ;
union V_50 * V_51 ;
struct V_161 V_83 ;
T_2 V_21 ;
T_4 V_162 ;
const struct V_163 * V_164 ;
V_21 = F_75 ( V_26 , & V_160 ) ;
if ( V_21 != V_31 ) {
F_28 ( L_23 , V_21 ) ;
return;
}
V_51 = (union V_50 * ) V_160 . V_23 ;
if ( ! V_51 )
return;
if ( V_51 -> type != V_52 ) {
F_28 ( L_24 , V_51 -> type ) ;
F_14 ( V_51 ) ;
return;
}
if ( V_51 -> V_53 . V_22 != 8 ) {
F_28 ( L_1 , V_51 -> V_53 . V_22 ) ;
F_14 ( V_51 ) ;
return;
}
V_83 = * ( (struct V_161 * ) V_51 -> V_53 . V_23 ) ;
F_14 ( V_51 ) ;
switch ( V_83 . V_165 ) {
case V_166 :
V_162 = V_83 . V_162 ;
F_76 ( L_25 , V_162 ) ;
V_164 = F_77 ( V_167 ,
V_83 . V_168 ) ;
if ( ! V_164 ) {
F_28 ( L_26 ,
V_83 . V_168 ) ;
} else {
switch ( V_164 -> V_169 ) {
case V_170 :
case V_171 :
if ( F_5 ( V_32 ) )
F_57 ( V_130 ,
! ( V_162 & V_93 ) ) ;
if ( F_5 ( V_74 ) )
F_57 ( V_132 ,
! ( V_162 & V_95 ) ) ;
if ( F_5 ( V_34 ) )
F_57 ( V_131 ,
! ( V_162 & V_94 ) ) ;
break;
}
F_78 ( V_167 , V_164 ,
1 , true ) ;
}
break;
default:
F_28 ( L_27 ,
V_83 . V_165 , V_83 . V_168 ) ;
break;
}
}
static T_2
F_79 ( struct V_172 * V_85 ,
struct V_173 * V_83 )
{
T_2 V_21 ;
union V_50 * V_51 ;
struct V_18 V_20 = { sizeof( struct V_172 ) , V_85 } ;
struct V_18 V_89 = { V_49 , NULL } ;
V_21 = F_7 ( V_90 , 0 , 0x1 , & V_20 , & V_89 ) ;
if ( F_13 ( V_21 ) )
return V_21 ;
V_51 = V_89 . V_23 ;
if ( ! V_51 )
return V_30 ;
else if ( V_51 -> type != V_52 ) {
F_14 ( V_51 ) ;
return V_30 ;
}
if ( V_51 -> V_53 . V_22 != 4 ) {
F_28 ( L_1 , V_51 -> V_53 . V_22 ) ;
F_14 ( V_51 ) ;
return V_30 ;
}
* V_83 = * ( (struct V_173 * ) V_51 -> V_53 . V_23 ) ;
F_14 ( V_51 ) ;
return V_21 ;
}
static int F_80 ( void )
{
struct V_173 V_83 ;
T_2 V_21 ;
struct V_172 V_85 = {
. V_86 = 0x1 ,
. V_174 = 0xFFFF ,
. V_88 = 0xFFFF ,
. V_175 = 0x00 ,
} ;
V_21 = F_79 ( & V_85 , & V_83 ) ;
if ( V_83 . V_91 || V_83 . V_92 )
F_28 ( L_28 ,
V_83 . V_91 ,
V_83 . V_92 ) ;
else
F_34 ( L_29 ) ;
return V_21 ;
}
static int F_81 ( void )
{
struct V_173 V_83 ;
T_2 V_21 ;
struct V_172 V_85 = {
. V_86 = 0x1 ,
. V_174 = 0xFFFF ,
. V_88 = 0xFFFF ,
. V_175 = 0x01 ,
} ;
V_21 = F_79 ( & V_85 , & V_83 ) ;
if ( V_83 . V_91 || V_83 . V_92 )
F_28 ( L_30 ,
V_83 . V_91 ,
V_83 . V_92 ) ;
return V_21 ;
}
static int T_5 F_82 ( void )
{
T_2 V_21 ;
int V_29 ;
V_167 = F_83 () ;
if ( ! V_167 )
return - V_144 ;
V_167 -> V_141 = L_31 ;
V_167 -> V_176 = L_32 ;
V_167 -> V_61 . V_177 = V_178 ;
V_29 = F_84 ( V_167 , V_179 , NULL ) ;
if ( V_29 )
goto V_180;
V_21 = F_85 ( V_152 ,
F_74 , NULL ) ;
if ( F_13 ( V_21 ) ) {
V_29 = - V_181 ;
goto V_182;
}
V_29 = F_86 ( V_167 ) ;
if ( V_29 )
goto V_183;
return 0 ;
V_183:
F_87 ( V_152 ) ;
V_182:
F_88 ( V_167 ) ;
V_180:
F_89 ( V_167 ) ;
return V_29 ;
}
static void F_90 ( void )
{
F_87 ( V_152 ) ;
F_88 ( V_167 ) ;
F_91 ( V_167 ) ;
}
static T_1 F_92 ( void )
{
struct V_18 V_48 = { V_49 , NULL } ;
union V_50 * V_51 ;
T_2 V_21 ;
T_1 V_88 = 0 ;
V_21 = F_36 ( V_104 , 1 , & V_48 ) ;
if ( F_13 ( V_21 ) )
return 0 ;
V_51 = (union V_50 * ) V_48 . V_23 ;
if ( V_51 && V_51 -> type == V_52 &&
( V_51 -> V_53 . V_22 == sizeof( T_1 ) ||
V_51 -> V_53 . V_22 == sizeof( V_69 ) ) ) {
V_88 = * ( ( T_1 * ) V_51 -> V_53 . V_23 ) ;
} else if ( V_51 -> type == V_70 ) {
V_88 = ( T_1 ) V_51 -> integer . V_26 ;
}
F_14 ( V_48 . V_23 ) ;
return V_88 ;
}
static int T_6 F_93 ( struct V_184 * V_81 )
{
int V_29 ;
if ( F_5 ( V_5 ) ) {
V_29 = F_41 ( & V_81 -> V_113 ) ;
if ( V_29 )
goto V_185;
}
if ( F_5 ( V_7 ) ) {
V_29 = F_47 ( & V_81 -> V_113 ) ;
if ( V_29 )
goto V_186;
}
V_29 = F_66 ( & V_81 -> V_113 ) ;
if ( V_29 )
goto V_187;
return V_29 ;
V_187:
if ( F_5 ( V_7 ) )
F_53 () ;
V_186:
if ( F_5 ( V_5 ) )
F_43 () ;
V_185:
return V_29 ;
}
static int F_94 ( struct V_184 * V_81 )
{
if ( F_5 ( V_5 ) )
F_43 () ;
if ( F_5 ( V_7 ) )
F_53 () ;
F_68 () ;
return 0 ;
}
static int F_95 ( struct V_184 * V_113 ,
T_9 V_129 )
{
T_1 V_26 ;
struct V_188 * V_135 = & V_1 -> V_135 ;
if ( ! V_135 )
return - V_144 ;
if ( F_5 ( V_5 ) ) {
F_37 ( & V_26 , V_5 ) ;
F_38 ( V_115 , V_5 ) ;
V_135 -> V_3 = V_26 ;
}
if ( F_5 ( V_7 ) ) {
F_37 ( & V_26 , V_7 ) ;
V_135 -> V_6 = V_26 ;
}
return 0 ;
}
static int F_96 ( struct V_184 * V_81 )
{
struct V_188 * V_135 = & V_1 -> V_135 ;
if ( ! V_135 )
return - V_144 ;
if ( F_5 ( V_5 ) )
F_38 ( V_135 -> V_3 , V_5 ) ;
if ( F_5 ( V_7 ) )
F_38 ( V_135 -> V_6 , V_7 ) ;
return 0 ;
}
static void F_97 ( struct V_184 * V_81 )
{
struct V_188 * V_135 = & V_1 -> V_135 ;
if ( ! V_135 )
return;
if ( F_5 ( V_5 ) )
F_38 ( V_115 , V_5 ) ;
}
static int F_98 ( struct V_184 * V_81 )
{
if ( F_5 ( V_74 ) )
F_99 ( & V_81 -> V_113 , & V_189 ) ;
F_99 ( & V_81 -> V_113 , & V_190 ) ;
return 0 ;
}
static int F_100 ( void )
{
int V_58 = - V_144 ;
if ( F_5 ( V_74 ) ) {
V_58 = F_101 ( & V_191 -> V_113 ,
& V_189 ) ;
if ( V_58 )
goto V_192;
}
V_58 = F_101 ( & V_191 -> V_113 ,
& V_190 ) ;
if ( V_58 )
goto V_192;
return 0 ;
V_192:
F_98 ( V_191 ) ;
return V_58 ;
}
static void F_102 ( void )
{
F_103 ( V_1 -> V_193 . V_88 ) ;
F_103 ( V_1 -> V_193 . V_194 ) ;
}
static int F_104 ( void )
{
V_1 -> V_193 . V_194 = F_105 ( L_8 , NULL ) ;
if ( ! V_1 -> V_193 . V_194 ) {
F_50 ( L_33 ) ;
return - V_144 ;
}
V_1 -> V_193 . V_88 = F_106 ( L_34 , V_195 ,
V_1 -> V_193 . V_194 ,
& V_1 -> V_193 . V_196 ) ;
if ( ! V_1 -> V_193 . V_88 )
goto V_197;
return 0 ;
V_197:
F_102 () ;
return - V_144 ;
}
static int T_5 F_107 ( void )
{
int V_29 ;
F_34 ( L_35 ) ;
if ( F_4 ( V_198 ) ) {
F_34 ( L_36 ) ;
return - V_138 ;
}
F_3 () ;
if ( F_19 ( V_25 ) && F_19 ( V_68 ) )
V_1 = & V_199 ;
if ( ! F_19 ( V_25 ) && F_19 ( V_68 ) )
V_1 = & V_200 ;
if ( F_19 ( V_90 ) )
V_1 = & V_201 ;
if ( V_1 )
F_108 ( F_33 , NULL ) ;
if ( F_19 ( V_104 ) && V_1 ) {
if ( ! V_103 && F_13 ( F_35 () ) ) {
F_50 ( L_37 ) ;
return - V_138 ;
}
V_1 -> V_4 |= V_7 ;
} else if ( ! F_19 ( V_104 ) && V_1 && ! V_103 ) {
F_50 ( L_38 ) ;
return - V_138 ;
}
if ( F_19 ( V_25 ) && ! F_19 ( V_68 ) ) {
V_1 = & V_202 ;
if ( F_13 ( F_18 () ) ) {
F_50 ( L_39 ) ;
return - V_138 ;
}
}
if ( F_19 ( V_25 ) )
F_12 () ;
if ( ! V_1 ) {
F_50 ( L_40 ) ;
return - V_138 ;
}
F_1 () ;
if ( F_109 () ) {
V_1 -> V_4 &= ~ V_7 ;
F_34 ( L_41
L_42 ) ;
}
if ( F_19 ( V_90 ) ) {
if ( V_151 ) {
if ( F_13 ( F_80 () ) ) {
F_50 ( L_43 ) ;
return - V_138 ;
}
} else if ( F_13 ( F_81 () ) ) {
F_50 ( L_44 ) ;
return - V_138 ;
}
} else if ( V_151 ) {
F_34 ( L_45 ) ;
}
if ( F_19 ( V_152 ) ) {
V_29 = F_82 () ;
if ( V_29 )
return V_29 ;
}
V_29 = F_110 ( & V_203 ) ;
if ( V_29 ) {
F_50 ( L_46 ) ;
goto V_204;
}
V_191 = F_111 ( L_8 , - 1 ) ;
if ( ! V_191 ) {
V_29 = - V_144 ;
goto V_205;
}
V_29 = F_112 ( V_191 ) ;
if ( V_29 )
goto V_206;
V_29 = F_100 () ;
if ( V_29 )
goto V_207;
if ( F_19 ( V_104 ) ) {
V_1 -> V_193 . V_196 = F_92 () ;
V_29 = F_104 () ;
if ( V_29 )
goto V_208;
}
F_39 () ;
return 0 ;
V_208:
F_98 ( V_191 ) ;
V_207:
F_113 ( V_191 ) ;
V_206:
F_114 ( V_191 ) ;
V_205:
F_115 ( & V_203 ) ;
V_204:
if ( F_19 ( V_152 ) )
F_90 () ;
return V_29 ;
}
static void T_10 F_116 ( void )
{
if ( F_19 ( V_152 ) )
F_90 () ;
F_98 ( V_191 ) ;
F_102 () ;
F_117 ( V_191 ) ;
F_115 ( & V_203 ) ;
F_34 ( L_47 ) ;
return;
}
