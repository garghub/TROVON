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
static T_2 F_15 ( void )
{
struct V_16 args ;
struct V_46 V_47 ;
T_2 V_21 ;
struct V_18 V_48 = { V_49 , NULL } ;
union V_50 * V_51 ;
if ( F_16 ( V_55 ) ) {
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
F_17 ( T_1 V_56 , T_1 V_57 , T_1 * V_48 )
{
struct V_18 V_20 = { ( V_58 ) sizeof( T_1 ) , ( void * ) ( & V_57 ) } ;
struct V_18 V_19 = { V_49 , NULL } ;
union V_50 * V_51 ;
T_1 V_59 ;
T_2 V_21 ;
V_21 = F_7 ( V_60 , 1 , V_56 , & V_20 , & V_19 ) ;
if ( F_13 ( V_21 ) )
return V_21 ;
V_51 = (union V_50 * ) V_19 . V_23 ;
if ( V_51 && V_51 -> type == V_52 &&
( V_51 -> V_53 . V_22 == sizeof( T_1 ) ||
V_51 -> V_53 . V_22 == sizeof( V_61 ) ) ) {
V_59 = * ( ( T_1 * ) V_51 -> V_53 . V_23 ) ;
} else if ( V_51 -> type == V_62 ) {
V_59 = ( T_1 ) V_51 -> integer . V_26 ;
} else {
V_59 = 0 ;
}
if ( V_48 )
* V_48 = V_59 ;
F_14 ( V_19 . V_23 ) ;
return V_21 ;
}
static T_2 F_18 ( T_1 * V_26 , T_1 V_15 ,
struct V_27 * V_28 )
{
T_2 V_21 ;
V_24 V_59 ;
T_1 V_19 , V_56 = 0 ;
switch ( V_15 ) {
case V_32 :
V_56 = V_63 ;
break;
case V_34 :
V_56 = V_64 ;
break;
case V_7 :
V_56 = V_65 ;
break;
case V_66 :
V_56 = V_67 ;
break;
case V_5 :
if ( V_2 -> V_3 == 1 ) {
F_9 ( 0x9f , & V_59 ) ;
* V_26 = V_59 & 0x1 ;
return 0 ;
}
default:
return V_30 ;
}
V_21 = F_17 ( V_56 , 0 , & V_19 ) ;
if ( F_19 ( V_21 ) )
* V_26 = ( V_24 ) V_19 ;
return V_21 ;
}
static T_2 F_20 ( T_1 V_26 , T_1 V_15 , struct V_27 * V_28 )
{
T_1 V_56 = 0 ;
char V_68 ;
switch ( V_15 ) {
case V_7 :
if ( V_26 > V_45 )
return V_41 ;
V_56 = V_69 ;
break;
case V_32 :
if ( V_26 > 1 )
return V_41 ;
V_56 = V_70 ;
break;
case V_34 :
if ( V_26 > 1 )
return V_41 ;
V_56 = V_71 ;
break;
case V_66 :
if ( V_26 > 1 )
return V_41 ;
V_56 = V_72 ;
break;
case V_5 :
if ( V_26 > 1 )
return V_41 ;
if ( V_2 -> V_3 == 1 ) {
V_68 = V_26 ? 0x92 : 0x93 ;
F_21 () ;
F_22 ( & V_68 , 0x1059 ) ;
F_23 () ;
return 0 ;
}
break;
default:
return V_30 ;
}
return F_17 ( V_56 , ( T_1 ) V_26 , NULL ) ;
}
static void F_24 ( const struct V_73 * V_74 , void * V_75 )
{
struct V_76 * V_77 ;
if ( V_74 -> type != 0xAA )
return;
V_78 = true ;
V_77 = (struct V_76 * ) V_74 ;
F_25 ( L_1 ,
V_77 -> V_79 ) ;
if ( V_77 -> V_79 & V_80 )
V_1 -> V_4 |= V_32 ;
if ( V_77 -> V_79 & V_81 )
V_1 -> V_4 |= V_66 ;
if ( V_77 -> V_79 & V_82 )
V_1 -> V_4 |= V_34 ;
}
static T_2 F_26 ( void )
{
struct V_18 V_48 = { V_49 , NULL } ;
union V_50 * V_51 ;
T_2 V_21 ;
T_1 V_83 ;
V_21 = F_27 ( V_84 , 1 , & V_48 ) ;
if ( F_13 ( V_21 ) )
return V_21 ;
V_51 = (union V_50 * ) V_48 . V_23 ;
if ( V_51 && V_51 -> type == V_52 &&
( V_51 -> V_53 . V_22 == sizeof( T_1 ) ||
V_51 -> V_53 . V_22 == sizeof( V_61 ) ) ) {
V_83 = * ( ( T_1 * ) V_51 -> V_53 . V_23 ) ;
} else if ( V_51 -> type == V_62 ) {
V_83 = ( T_1 ) V_51 -> integer . V_26 ;
} else {
F_14 ( V_48 . V_23 ) ;
return V_30 ;
}
F_28 ( F_24 , NULL ) ;
if ( ! V_78 ) {
V_1 -> V_4 |= V_32 ;
if ( V_83 & 0x40 )
V_1 -> V_4 |= V_66 ;
if ( V_83 & 0x10 )
V_1 -> V_4 |= V_34 ;
}
V_1 -> V_4 |= V_7 ;
if ( ! ( V_83 & 0x20 ) )
V_45 = 0x9 ;
F_14 ( V_48 . V_23 ) ;
return V_21 ;
}
static T_2 F_29 ( T_1 * V_26 , T_1 V_15 )
{
T_2 V_21 = V_30 ;
switch ( V_1 -> type ) {
case V_85 :
V_21 = F_8 ( V_26 , V_15 , V_1 ) ;
break;
case V_86 :
if ( V_15 == V_5 ) {
V_21 = F_8 ( V_26 , V_15 , V_1 ) ;
break;
}
case V_87 :
V_21 = F_18 ( V_26 , V_15 , V_1 ) ;
break;
}
return V_21 ;
}
static T_2 F_30 ( T_1 V_26 , T_1 V_15 )
{
T_2 V_21 ;
if ( V_1 -> V_4 & V_15 ) {
switch ( V_1 -> type ) {
case V_85 :
return F_10 ( V_26 , V_15 , V_1 ) ;
case V_86 :
if ( V_15 == V_5 )
return F_10 ( V_26 , V_15 , V_1 ) ;
if ( V_15 == V_32 ||
V_15 == V_34 ) {
V_21 = F_20 ( V_26 , V_15 , V_1 ) ;
if ( F_13 ( V_21 ) )
return V_21 ;
return F_10 ( V_26 , V_15 , V_1 ) ;
}
case V_87 :
return F_20 ( V_26 , V_15 , V_1 ) ;
default:
return V_41 ;
}
}
return V_41 ;
}
static void T_3 F_31 ( void )
{
if ( V_3 >= 0 )
F_30 ( V_3 , V_5 ) ;
if ( ! V_78 && V_88 >= 0 )
F_30 ( V_88 , V_66 ) ;
if ( V_6 >= 0 )
F_30 ( V_6 , V_7 ) ;
}
static void F_32 ( struct V_89 * V_90 ,
enum V_91 V_26 )
{
F_30 ( V_26 , V_5 ) ;
}
static int T_4 F_33 ( struct V_92 * V_93 )
{
return F_34 ( V_93 , & V_94 ) ;
}
static void F_35 ( void )
{
F_30 ( V_95 , V_5 ) ;
F_36 ( & V_94 ) ;
}
static int F_37 ( struct V_96 * V_97 )
{
T_1 V_26 ;
F_29 ( & V_26 , V_7 ) ;
return V_26 ;
}
static int F_38 ( struct V_96 * V_97 )
{
int V_98 = V_97 -> V_99 . V_6 ;
if ( V_97 -> V_99 . V_100 != V_101 )
V_98 = 0 ;
if ( V_97 -> V_99 . V_102 != V_101 )
V_98 = 0 ;
F_30 ( V_98 , V_7 ) ;
return 0 ;
}
static int T_4 F_39 ( struct V_92 * V_93 )
{
struct V_103 V_99 ;
struct V_96 * V_97 ;
memset ( & V_99 , 0 , sizeof( struct V_103 ) ) ;
V_99 . type = V_104 ;
V_99 . V_45 = V_45 ;
V_97 = F_40 ( L_2 , V_93 , NULL , & V_105 ,
& V_99 ) ;
if ( F_41 ( V_97 ) ) {
F_42 ( L_3 ) ;
V_106 = NULL ;
return F_43 ( V_97 ) ;
}
V_106 = V_97 ;
V_97 -> V_99 . V_100 = V_101 ;
V_97 -> V_99 . V_6 = F_37 ( V_97 ) ;
F_44 ( V_97 ) ;
return 0 ;
}
static void F_45 ( void )
{
F_46 ( V_106 ) ;
}
static T_2 F_47 ( T_1 * V_26 , T_5 V_92 )
{
struct V_107 V_108 ;
T_2 V_21 ;
union V_50 * V_51 ;
struct V_109 V_110 = {
. V_111 = 0x1 ,
. V_112 = 0x01 ,
. V_83 = V_92 ,
} ;
struct V_18 V_20 = {
sizeof( struct V_109 ) ,
& V_110
} ;
struct V_18 V_113 = { V_49 , NULL } ;
V_21 = F_7 ( V_114 , 0 , 0x2 , & V_20 , & V_113 ) ;
if ( F_13 ( V_21 ) )
return V_21 ;
V_51 = V_113 . V_23 ;
if ( ! V_51 )
return V_30 ;
else if ( V_51 -> type != V_52 ) {
F_14 ( V_51 ) ;
return V_30 ;
}
if ( V_51 -> V_53 . V_22 != 8 ) {
F_48 ( L_4 , V_51 -> V_53 . V_22 ) ;
F_14 ( V_51 ) ;
return V_30 ;
}
V_108 = * ( (struct V_107 * ) V_51 -> V_53 . V_23 ) ;
F_14 ( V_51 ) ;
if ( V_108 . V_115 || V_108 . V_116 )
F_48 ( L_5 ,
V_108 . V_115 ,
V_108 . V_116 ) ;
else
* V_26 = ! ! ( V_108 . V_83 & V_92 ) ;
return V_21 ;
}
static T_2 F_49 ( T_1 * V_26 , T_1 V_15 )
{
if ( F_16 ( V_114 ) ) {
T_5 V_92 ;
switch ( V_15 ) {
case V_32 :
V_92 = V_80 ;
break;
case V_34 :
V_92 = V_82 ;
break;
case V_66 :
V_92 = V_81 ;
break;
default:
return V_30 ;
}
return F_47 ( V_26 , V_92 ) ;
} else {
return F_29 ( V_26 , V_15 ) ;
}
}
static T_2 F_50 ( T_1 V_26 , T_5 V_92 )
{
struct V_107 V_108 ;
T_2 V_21 ;
union V_50 * V_51 ;
T_5 V_83 ;
struct V_109 V_110 = {
. V_111 = 0x1 ,
. V_112 = 0x01 ,
. V_83 = V_80 |
V_81 |
V_117 |
V_82 ,
} ;
struct V_18 V_20 = {
sizeof( struct V_109 ) ,
& V_110
} ;
struct V_18 V_113 = { V_49 , NULL } ;
struct V_18 V_118 = { V_49 , NULL } ;
V_21 = F_7 ( V_114 , 0 , 0x2 , & V_20 , & V_113 ) ;
if ( F_13 ( V_21 ) )
return V_21 ;
V_51 = V_113 . V_23 ;
if ( ! V_51 )
return V_30 ;
else if ( V_51 -> type != V_52 ) {
F_14 ( V_51 ) ;
return V_30 ;
}
if ( V_51 -> V_53 . V_22 != 8 ) {
F_51 ( L_4 , V_51 -> V_53 . V_22 ) ;
F_14 ( V_51 ) ;
return V_30 ;
}
V_108 = * ( (struct V_107 * ) V_51 -> V_53 . V_23 ) ;
F_14 ( V_51 ) ;
if ( V_108 . V_115 || V_108 . V_116 ) {
F_51 ( L_6
L_7 , V_108 . V_115 ,
V_108 . V_116 ) ;
return V_21 ;
}
V_83 = V_108 . V_83 ;
V_110 . V_111 = 0x2 ;
V_110 . V_112 = 0x01 ;
V_110 . V_83 = ( V_26 ) ? ( V_83 | V_92 ) : ( V_83 & ~ V_92 ) ;
V_21 = F_7 ( V_114 , 0 , 0x1 , & V_20 , & V_118 ) ;
if ( F_13 ( V_21 ) )
return V_21 ;
V_51 = V_118 . V_23 ;
if ( ! V_51 )
return V_30 ;
else if ( V_51 -> type != V_52 ) {
F_14 ( V_51 ) ;
return V_30 ;
}
if ( V_51 -> V_53 . V_22 != 4 ) {
F_51 ( L_4 , V_51 -> V_53 . V_22 ) ;
F_14 ( V_51 ) ;
return V_30 ;
}
V_108 = * ( (struct V_107 * ) V_51 -> V_53 . V_23 ) ;
F_14 ( V_51 ) ;
if ( V_108 . V_115 || V_108 . V_116 )
F_51 ( L_8
L_7 , V_108 . V_115 ,
V_108 . V_116 ) ;
return V_21 ;
}
static T_2 F_52 ( T_1 V_26 , T_1 V_15 )
{
if ( F_16 ( V_114 ) ) {
T_5 V_92 ;
switch ( V_15 ) {
case V_32 :
V_92 = V_80 ;
break;
case V_34 :
V_92 = V_82 ;
break;
case V_66 :
V_92 = V_81 ;
break;
default:
return V_30 ;
}
return F_50 ( V_26 , V_92 ) ;
} else {
return F_30 ( V_26 , V_15 ) ;
}
}
static void F_53 ( struct V_119 * V_120 )
{
T_1 V_121 ;
T_2 V_21 ;
V_21 = F_29 ( & V_121 , V_32 ) ;
if ( F_19 ( V_21 ) ) {
if ( V_2 -> V_33 == 3 ) {
F_54 ( V_122 , ! V_121 ) ;
} else {
F_55 ( V_122 , ! V_121 ) ;
}
}
if ( F_5 ( V_34 ) ) {
V_21 = F_29 ( & V_121 , V_34 ) ;
if ( F_19 ( V_21 ) )
F_55 ( V_123 , ! V_121 ) ;
}
if ( F_5 ( V_66 ) && F_16 ( V_114 ) ) {
V_21 = F_47 ( & V_121 ,
V_81 ) ;
if ( F_19 ( V_21 ) )
F_55 ( V_124 , ! V_121 ) ;
}
F_56 ( & V_125 , F_57 ( V_126 ) ) ;
}
static int F_58 ( void * V_127 , bool V_128 )
{
T_2 V_21 ;
T_1 V_15 = ( unsigned long ) V_127 ;
if ( V_129 ) {
V_21 = F_52 ( ! V_128 , V_15 ) ;
if ( F_13 ( V_21 ) )
return - V_130 ;
}
return 0 ;
}
static struct V_131 * F_59 ( struct V_92 * V_93 ,
enum V_132 type ,
char * V_133 , T_1 V_15 )
{
int V_29 ;
struct V_131 * V_134 ;
T_1 V_121 ;
T_2 V_21 ;
V_134 = F_60 ( V_133 , V_93 , type ,
& V_135 ,
( void * ) ( unsigned long ) V_15 ) ;
if ( ! V_134 )
return F_61 ( - V_136 ) ;
V_21 = F_49 ( & V_121 , V_15 ) ;
V_29 = F_62 ( V_134 ) ;
if ( V_29 ) {
F_63 ( V_134 ) ;
return F_61 ( V_29 ) ;
}
if ( F_19 ( V_21 ) )
F_55 ( V_134 , ! V_121 ) ;
return V_134 ;
}
static int F_64 ( struct V_92 * V_93 )
{
V_122 = F_59 ( V_93 , V_137 ,
L_9 , V_32 ) ;
if ( F_41 ( V_122 ) )
return F_43 ( V_122 ) ;
if ( F_5 ( V_34 ) ) {
V_123 = F_59 ( V_93 ,
V_138 , L_10 ,
V_34 ) ;
if ( F_41 ( V_123 ) ) {
F_65 ( V_122 ) ;
F_63 ( V_122 ) ;
return F_43 ( V_123 ) ;
}
}
if ( F_5 ( V_66 ) ) {
V_124 = F_59 ( V_93 ,
V_139 , L_11 ,
V_66 ) ;
if ( F_41 ( V_124 ) ) {
F_65 ( V_122 ) ;
F_63 ( V_122 ) ;
F_65 ( V_123 ) ;
F_63 ( V_123 ) ;
return F_43 ( V_124 ) ;
}
}
V_129 = true ;
if ( V_140 || ! F_16 ( V_141 ) )
F_56 ( & V_125 ,
F_57 ( V_126 ) ) ;
return 0 ;
}
static void F_66 ( void )
{
if ( V_140 || ! F_16 ( V_141 ) )
F_67 ( & V_125 ) ;
F_65 ( V_122 ) ;
F_63 ( V_122 ) ;
if ( F_5 ( V_34 ) ) {
F_65 ( V_123 ) ;
F_63 ( V_123 ) ;
}
if ( F_5 ( V_66 ) ) {
F_65 ( V_124 ) ;
F_63 ( V_124 ) ;
}
return;
}
static T_6 F_68 ( struct V_92 * V_93 ,
struct V_142 * V_143 , char * V_144 )
{
T_1 V_19 ; \
T_2 V_21 ;
F_25 ( L_12
L_13 , V_145 -> V_146 ) ;
if ( F_16 ( V_114 ) )
V_21 = F_47 ( & V_19 ,
V_81 ) ;
else
V_21 = F_29 ( & V_19 , V_66 ) ;
if ( F_19 ( V_21 ) )
return sprintf ( V_144 , L_14 , V_19 ) ;
return sprintf ( V_144 , L_15 ) ;
}
static T_6 F_69 ( struct V_92 * V_93 ,
struct V_142 * V_143 , const char * V_144 , T_7 V_147 )
{
T_1 V_59 = F_70 ( V_144 , NULL , 10 ) ;
T_2 V_21 = F_30 ( V_59 , V_66 ) ;
F_25 ( L_12
L_13 , V_145 -> V_146 ) ;
if ( F_13 ( V_21 ) )
return - V_148 ;
return V_147 ;
}
static T_6 F_71 ( struct V_92 * V_93 , struct V_142 * V_143 ,
char * V_144 )
{
F_25 ( L_16
L_13 , V_145 -> V_146 ) ;
switch ( V_1 -> type ) {
case V_85 :
return sprintf ( V_144 , L_17 ) ;
case V_86 :
return sprintf ( V_144 , L_18 ) ;
case V_87 :
return sprintf ( V_144 , L_19 ) ;
default:
return sprintf ( V_144 , L_20 ) ;
}
}
static void F_72 ( T_1 V_26 , void * V_149 )
{
struct V_18 V_150 = { V_49 , NULL } ;
union V_50 * V_51 ;
struct V_151 V_108 ;
T_2 V_21 ;
T_5 V_152 ;
const struct V_153 * V_154 ;
V_21 = F_73 ( V_26 , & V_150 ) ;
if ( V_21 != V_31 ) {
F_48 ( L_21 , V_21 ) ;
return;
}
V_51 = (union V_50 * ) V_150 . V_23 ;
if ( ! V_51 )
return;
if ( V_51 -> type != V_52 ) {
F_48 ( L_22 , V_51 -> type ) ;
F_14 ( V_51 ) ;
return;
}
if ( V_51 -> V_53 . V_22 != 8 ) {
F_48 ( L_4 , V_51 -> V_53 . V_22 ) ;
F_14 ( V_51 ) ;
return;
}
V_108 = * ( (struct V_151 * ) V_51 -> V_53 . V_23 ) ;
F_14 ( V_51 ) ;
switch ( V_108 . V_155 ) {
case V_156 :
V_152 = V_108 . V_152 ;
F_74 ( L_23 , V_152 ) ;
V_154 = F_75 ( V_157 ,
V_108 . V_158 ) ;
if ( ! V_154 ) {
F_48 ( L_24 ,
V_108 . V_158 ) ;
} else {
switch ( V_154 -> V_159 ) {
case V_160 :
case V_161 :
if ( F_5 ( V_32 ) )
F_55 ( V_122 ,
! ( V_152 & V_80 ) ) ;
if ( F_5 ( V_66 ) )
F_55 ( V_124 ,
! ( V_152 & V_81 ) ) ;
if ( F_5 ( V_34 ) )
F_55 ( V_123 ,
! ( V_152 & V_82 ) ) ;
break;
}
F_76 ( V_157 , V_154 ,
1 , true ) ;
}
break;
default:
F_48 ( L_25 ,
V_108 . V_155 , V_108 . V_158 ) ;
break;
}
}
static T_2
F_77 ( struct V_162 * V_110 ,
struct V_163 * V_108 )
{
T_2 V_21 ;
union V_50 * V_51 ;
struct V_18 V_20 = { sizeof( struct V_162 ) , V_110 } ;
struct V_18 V_113 = { V_49 , NULL } ;
V_21 = F_7 ( V_114 , 0 , 0x1 , & V_20 , & V_113 ) ;
if ( F_13 ( V_21 ) )
return V_21 ;
V_51 = V_113 . V_23 ;
if ( ! V_51 )
return V_30 ;
else if ( V_51 -> type != V_52 ) {
F_14 ( V_51 ) ;
return V_30 ;
}
if ( V_51 -> V_53 . V_22 != 4 ) {
F_48 ( L_4 , V_51 -> V_53 . V_22 ) ;
F_14 ( V_51 ) ;
return V_30 ;
}
* V_108 = * ( (struct V_163 * ) V_51 -> V_53 . V_23 ) ;
F_14 ( V_51 ) ;
return V_21 ;
}
static int F_78 ( void )
{
struct V_163 V_108 ;
T_2 V_21 ;
struct V_162 V_110 = {
. V_111 = 0x1 ,
. V_164 = 0xFFFF ,
. V_83 = 0xFFFF ,
. V_165 = 0x00 ,
} ;
V_21 = F_77 ( & V_110 , & V_108 ) ;
if ( V_108 . V_115 || V_108 . V_116 )
F_48 ( L_26 ,
V_108 . V_115 ,
V_108 . V_116 ) ;
else
F_25 ( L_27 ) ;
return V_21 ;
}
static int F_79 ( void )
{
struct V_163 V_108 ;
T_2 V_21 ;
struct V_162 V_110 = {
. V_111 = 0x1 ,
. V_164 = 0xFFFF ,
. V_83 = 0xFFFF ,
. V_165 = 0x01 ,
} ;
V_21 = F_77 ( & V_110 , & V_108 ) ;
if ( V_108 . V_115 || V_108 . V_116 )
F_48 ( L_28 ,
V_108 . V_115 ,
V_108 . V_116 ) ;
return V_21 ;
}
static int T_3 F_80 ( void )
{
T_2 V_21 ;
int V_29 ;
V_157 = F_81 () ;
if ( ! V_157 )
return - V_136 ;
V_157 -> V_133 = L_29 ;
V_157 -> V_166 = L_30 ;
V_157 -> V_167 . V_168 = V_169 ;
V_29 = F_82 ( V_157 , V_170 , NULL ) ;
if ( V_29 )
goto V_171;
V_21 = F_83 ( V_141 ,
F_72 , NULL ) ;
if ( F_13 ( V_21 ) ) {
V_29 = - V_172 ;
goto V_173;
}
V_29 = F_84 ( V_157 ) ;
if ( V_29 )
goto V_174;
return 0 ;
V_174:
F_85 ( V_141 ) ;
V_173:
F_86 ( V_157 ) ;
V_171:
F_87 ( V_157 ) ;
return V_29 ;
}
static void F_88 ( void )
{
F_85 ( V_141 ) ;
F_86 ( V_157 ) ;
F_89 ( V_157 ) ;
}
static T_1 F_90 ( void )
{
struct V_18 V_48 = { V_49 , NULL } ;
union V_50 * V_51 ;
T_2 V_21 ;
T_1 V_83 = 0 ;
V_21 = F_27 ( V_84 , 1 , & V_48 ) ;
if ( F_13 ( V_21 ) )
return 0 ;
V_51 = (union V_50 * ) V_48 . V_23 ;
if ( V_51 && V_51 -> type == V_52 &&
( V_51 -> V_53 . V_22 == sizeof( T_1 ) ||
V_51 -> V_53 . V_22 == sizeof( V_61 ) ) ) {
V_83 = * ( ( T_1 * ) V_51 -> V_53 . V_23 ) ;
} else if ( V_51 -> type == V_62 ) {
V_83 = ( T_1 ) V_51 -> integer . V_26 ;
}
F_14 ( V_48 . V_23 ) ;
return V_83 ;
}
static int T_4 F_91 ( struct V_175 * V_92 )
{
int V_29 ;
if ( F_5 ( V_5 ) ) {
V_29 = F_33 ( & V_92 -> V_93 ) ;
if ( V_29 )
goto V_176;
}
if ( F_5 ( V_7 ) ) {
V_29 = F_39 ( & V_92 -> V_93 ) ;
if ( V_29 )
goto V_177;
}
V_29 = F_64 ( & V_92 -> V_93 ) ;
if ( V_29 )
goto V_178;
return V_29 ;
V_178:
if ( F_5 ( V_7 ) )
F_45 () ;
V_177:
if ( F_5 ( V_5 ) )
F_35 () ;
V_176:
return V_29 ;
}
static int F_92 ( struct V_175 * V_92 )
{
if ( F_5 ( V_5 ) )
F_35 () ;
if ( F_5 ( V_7 ) )
F_45 () ;
F_66 () ;
return 0 ;
}
static int F_93 ( struct V_175 * V_93 ,
T_8 V_121 )
{
T_1 V_26 ;
struct V_179 * V_127 = & V_1 -> V_127 ;
if ( ! V_127 )
return - V_136 ;
if ( F_5 ( V_5 ) ) {
F_29 ( & V_26 , V_5 ) ;
F_30 ( V_95 , V_5 ) ;
V_127 -> V_3 = V_26 ;
}
if ( F_5 ( V_7 ) ) {
F_29 ( & V_26 , V_7 ) ;
V_127 -> V_6 = V_26 ;
}
return 0 ;
}
static int F_94 ( struct V_175 * V_92 )
{
struct V_179 * V_127 = & V_1 -> V_127 ;
if ( ! V_127 )
return - V_136 ;
if ( F_5 ( V_5 ) )
F_30 ( V_127 -> V_3 , V_5 ) ;
if ( F_5 ( V_7 ) )
F_30 ( V_127 -> V_6 , V_7 ) ;
return 0 ;
}
static void F_95 ( struct V_175 * V_92 )
{
struct V_179 * V_127 = & V_1 -> V_127 ;
if ( ! V_127 )
return;
if ( F_5 ( V_5 ) )
F_30 ( V_95 , V_5 ) ;
}
static int F_96 ( struct V_175 * V_92 )
{
if ( F_5 ( V_66 ) )
F_97 ( & V_92 -> V_93 , & V_180 ) ;
F_97 ( & V_92 -> V_93 , & V_181 ) ;
return 0 ;
}
static int F_98 ( void )
{
int V_182 = - V_136 ;
if ( F_5 ( V_66 ) ) {
V_182 = F_99 ( & V_183 -> V_93 ,
& V_180 ) ;
if ( V_182 )
goto V_184;
}
V_182 = F_99 ( & V_183 -> V_93 ,
& V_181 ) ;
if ( V_182 )
goto V_184;
return 0 ;
V_184:
F_96 ( V_183 ) ;
return V_182 ;
}
static void F_100 ( void )
{
F_101 ( V_1 -> V_185 . V_83 ) ;
F_101 ( V_1 -> V_185 . V_186 ) ;
}
static int F_102 ( void )
{
V_1 -> V_185 . V_186 = F_103 ( L_2 , NULL ) ;
if ( ! V_1 -> V_185 . V_186 ) {
F_42 ( L_31 ) ;
return - V_136 ;
}
V_1 -> V_185 . V_83 = F_104 ( L_32 , V_187 ,
V_1 -> V_185 . V_186 ,
& V_1 -> V_185 . V_188 ) ;
if ( ! V_1 -> V_185 . V_83 )
goto V_189;
return 0 ;
V_189:
F_100 () ;
return - V_136 ;
}
static int T_3 F_105 ( void )
{
int V_29 ;
F_25 ( L_33 ) ;
if ( F_4 ( V_190 ) ) {
F_25 ( L_34 ) ;
return - V_130 ;
}
F_3 () ;
if ( F_16 ( V_25 ) && F_16 ( V_60 ) )
V_1 = & V_191 ;
if ( ! F_16 ( V_25 ) && F_16 ( V_60 ) )
V_1 = & V_192 ;
if ( F_16 ( V_84 ) && V_1 ) {
if ( F_13 ( F_26 () ) ) {
F_42 ( L_35 ) ;
return - V_130 ;
}
} else if ( ! F_16 ( V_84 ) && V_1 ) {
F_42 ( L_36 ) ;
return - V_130 ;
}
if ( F_16 ( V_25 ) && ! F_16 ( V_60 ) ) {
V_1 = & V_193 ;
if ( F_13 ( F_15 () ) ) {
F_42 ( L_37 ) ;
return - V_130 ;
}
}
if ( F_16 ( V_25 ) )
F_12 () ;
if ( ! V_1 ) {
F_42 ( L_38 ) ;
return - V_130 ;
}
F_1 () ;
if ( F_106 () && F_5 ( V_7 ) ) {
V_1 -> V_4 &= ~ V_7 ;
F_25 ( L_39
L_40 ) ;
}
if ( F_16 ( V_114 ) ) {
if ( V_140 ) {
if ( F_13 ( F_78 () ) ) {
F_42 ( L_41 ) ;
return - V_130 ;
}
} else if ( F_13 ( F_79 () ) ) {
F_42 ( L_42 ) ;
return - V_130 ;
}
} else if ( V_140 ) {
F_25 ( L_43 ) ;
}
if ( F_16 ( V_141 ) ) {
V_29 = F_80 () ;
if ( V_29 )
return V_29 ;
}
V_29 = F_107 ( & V_194 ) ;
if ( V_29 ) {
F_42 ( L_44 ) ;
goto V_195;
}
V_183 = F_108 ( L_2 , - 1 ) ;
if ( ! V_183 ) {
V_29 = - V_136 ;
goto V_196;
}
V_29 = F_109 ( V_183 ) ;
if ( V_29 )
goto V_197;
V_29 = F_98 () ;
if ( V_29 )
goto V_198;
if ( F_16 ( V_84 ) ) {
V_1 -> V_185 . V_188 = F_90 () ;
V_29 = F_102 () ;
if ( V_29 )
goto V_199;
}
F_31 () ;
return 0 ;
V_199:
F_96 ( V_183 ) ;
V_198:
F_110 ( V_183 ) ;
V_197:
F_111 ( V_183 ) ;
V_196:
F_112 ( & V_194 ) ;
V_195:
if ( F_16 ( V_141 ) )
F_88 () ;
return V_29 ;
}
static void T_9 F_113 ( void )
{
if ( F_16 ( V_141 ) )
F_88 () ;
F_96 ( V_183 ) ;
F_100 () ;
F_114 ( V_183 ) ;
F_112 ( & V_194 ) ;
F_25 ( L_45 ) ;
return;
}
