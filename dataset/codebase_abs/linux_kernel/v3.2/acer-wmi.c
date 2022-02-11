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
static T_2 F_24 ( T_1 * V_26 , T_3 V_73 )
{
struct V_74 V_75 ;
T_2 V_21 ;
union V_50 * V_51 ;
struct V_76 V_77 = {
. V_78 = 0x1 ,
. V_79 = 0x01 ,
. V_80 = V_73 ,
} ;
struct V_18 V_20 = {
sizeof( struct V_76 ) ,
& V_77
} ;
struct V_18 V_81 = { V_49 , NULL } ;
V_21 = F_7 ( V_82 , 0 , 0x2 , & V_20 , & V_81 ) ;
if ( F_13 ( V_21 ) )
return V_21 ;
V_51 = V_81 . V_23 ;
if ( ! V_51 )
return V_30 ;
else if ( V_51 -> type != V_52 ) {
F_14 ( V_51 ) ;
return V_30 ;
}
if ( V_51 -> V_53 . V_22 != 8 ) {
F_25 ( L_1 , V_51 -> V_53 . V_22 ) ;
F_14 ( V_51 ) ;
return V_30 ;
}
V_75 = * ( (struct V_74 * ) V_51 -> V_53 . V_23 ) ;
F_14 ( V_51 ) ;
if ( V_75 . V_83 || V_75 . V_84 )
F_25 ( L_2 ,
V_73 ,
V_75 . V_83 ,
V_75 . V_84 ) ;
else
* V_26 = ! ! ( V_75 . V_80 & V_73 ) ;
return V_21 ;
}
static T_2 F_26 ( T_1 * V_26 , T_1 V_15 )
{
T_3 V_73 ;
switch ( V_15 ) {
case V_32 :
V_73 = V_85 ;
break;
case V_34 :
V_73 = V_86 ;
break;
case V_66 :
V_73 = V_87 ;
break;
default:
return V_30 ;
}
return F_24 ( V_26 , V_73 ) ;
}
static T_2 F_27 ( T_1 V_26 , T_3 V_73 )
{
struct V_74 V_75 ;
T_2 V_21 ;
union V_50 * V_51 ;
T_3 V_80 ;
struct V_76 V_77 = {
. V_78 = 0x1 ,
. V_79 = 0x01 ,
. V_80 = V_88 ,
} ;
struct V_18 V_20 = {
sizeof( struct V_76 ) ,
& V_77
} ;
struct V_18 V_81 = { V_49 , NULL } ;
struct V_18 V_89 = { V_49 , NULL } ;
V_21 = F_7 ( V_82 , 0 , 0x2 , & V_20 , & V_81 ) ;
if ( F_13 ( V_21 ) )
return V_21 ;
V_51 = V_81 . V_23 ;
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
V_75 = * ( (struct V_74 * ) V_51 -> V_53 . V_23 ) ;
F_14 ( V_51 ) ;
if ( V_75 . V_83 || V_75 . V_84 ) {
F_28 ( L_3
L_4 , V_75 . V_83 ,
V_75 . V_84 ) ;
return V_21 ;
}
V_80 = V_75 . V_80 ;
V_77 . V_78 = 0x2 ;
V_77 . V_79 = 0x01 ;
V_77 . V_80 = ( V_26 ) ? ( V_80 | V_73 ) : ( V_80 & ~ V_73 ) ;
V_21 = F_7 ( V_82 , 0 , 0x1 , & V_20 , & V_89 ) ;
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
V_75 = * ( (struct V_74 * ) V_51 -> V_53 . V_23 ) ;
F_14 ( V_51 ) ;
if ( V_75 . V_83 || V_75 . V_84 )
F_28 ( L_5
L_4 , V_75 . V_83 ,
V_75 . V_84 ) ;
return V_21 ;
}
static T_2 F_29 ( T_1 V_26 , T_1 V_15 )
{
T_3 V_73 ;
switch ( V_15 ) {
case V_32 :
V_73 = V_85 ;
break;
case V_34 :
V_73 = V_86 ;
break;
case V_66 :
V_73 = V_87 ;
break;
default:
return V_30 ;
}
return F_27 ( V_26 , V_73 ) ;
}
static void F_30 ( const struct V_90 * V_91 , void * V_92 )
{
struct V_93 * V_94 ;
if ( V_91 -> type != 0xAA )
return;
V_95 = true ;
V_94 = (struct V_93 * ) V_91 ;
F_31 ( L_6 ,
V_94 -> V_88 ) ;
V_88 = V_94 -> V_88 ;
if ( V_94 -> V_88 & V_85 )
V_1 -> V_4 |= V_32 ;
if ( V_94 -> V_88 & V_87 )
V_1 -> V_4 |= V_66 ;
if ( V_94 -> V_88 & V_86 )
V_1 -> V_4 |= V_34 ;
}
static T_2 F_32 ( void )
{
struct V_18 V_48 = { V_49 , NULL } ;
union V_50 * V_51 ;
T_2 V_21 ;
T_1 V_80 ;
V_21 = F_33 ( V_96 , 1 , & V_48 ) ;
if ( F_13 ( V_21 ) )
return V_21 ;
V_51 = (union V_50 * ) V_48 . V_23 ;
if ( V_51 && V_51 -> type == V_52 &&
( V_51 -> V_53 . V_22 == sizeof( T_1 ) ||
V_51 -> V_53 . V_22 == sizeof( V_61 ) ) ) {
V_80 = * ( ( T_1 * ) V_51 -> V_53 . V_23 ) ;
} else if ( V_51 -> type == V_62 ) {
V_80 = ( T_1 ) V_51 -> integer . V_26 ;
} else {
F_14 ( V_48 . V_23 ) ;
return V_30 ;
}
F_31 ( L_7 , V_80 ) ;
if ( V_80 & 0x07 )
V_1 -> V_4 |= V_32 ;
if ( V_80 & 0x40 )
V_1 -> V_4 |= V_66 ;
if ( V_80 & 0x10 )
V_1 -> V_4 |= V_34 ;
if ( ! ( V_80 & 0x20 ) )
V_45 = 0x9 ;
F_14 ( V_48 . V_23 ) ;
return V_21 ;
}
static T_2 F_34 ( T_1 * V_26 , T_1 V_15 )
{
T_2 V_21 = V_30 ;
switch ( V_1 -> type ) {
case V_97 :
V_21 = F_8 ( V_26 , V_15 , V_1 ) ;
break;
case V_98 :
if ( V_15 == V_5 ) {
V_21 = F_8 ( V_26 , V_15 , V_1 ) ;
break;
}
case V_99 :
V_21 = F_18 ( V_26 , V_15 , V_1 ) ;
break;
case V_100 :
if ( V_15 & ( V_32 |
V_34 |
V_66 ) )
V_21 = F_26 ( V_26 , V_15 ) ;
else if ( F_16 ( V_96 ) )
V_21 = F_18 ( V_26 , V_15 , V_1 ) ;
break;
}
return V_21 ;
}
static T_2 F_35 ( T_1 V_26 , T_1 V_15 )
{
T_2 V_21 ;
if ( V_1 -> V_4 & V_15 ) {
switch ( V_1 -> type ) {
case V_97 :
return F_10 ( V_26 , V_15 , V_1 ) ;
case V_98 :
if ( V_15 == V_5 )
return F_10 ( V_26 , V_15 , V_1 ) ;
if ( V_15 == V_32 ||
V_15 == V_34 ) {
V_21 = F_20 ( V_26 , V_15 , V_1 ) ;
if ( F_13 ( V_21 ) )
return V_21 ;
return F_10 ( V_26 , V_15 , V_1 ) ;
}
case V_99 :
return F_20 ( V_26 , V_15 , V_1 ) ;
case V_100 :
if ( V_15 & ( V_32 |
V_34 |
V_66 ) )
return F_29 ( V_26 , V_15 ) ;
else if ( F_16 ( V_96 ) )
return F_20 ( V_26 , V_15 , V_1 ) ;
default:
return V_41 ;
}
}
return V_41 ;
}
static void T_4 F_36 ( void )
{
if ( V_3 >= 0 )
F_35 ( V_3 , V_5 ) ;
if ( ! V_95 && V_101 >= 0 )
F_35 ( V_101 , V_66 ) ;
if ( V_6 >= 0 )
F_35 ( V_6 , V_7 ) ;
}
static void F_37 ( struct V_102 * V_103 ,
enum V_104 V_26 )
{
F_35 ( V_26 , V_5 ) ;
}
static int T_5 F_38 ( struct V_73 * V_105 )
{
return F_39 ( V_105 , & V_106 ) ;
}
static void F_40 ( void )
{
F_35 ( V_107 , V_5 ) ;
F_41 ( & V_106 ) ;
}
static int F_42 ( struct V_108 * V_109 )
{
T_1 V_26 ;
F_34 ( & V_26 , V_7 ) ;
return V_26 ;
}
static int F_43 ( struct V_108 * V_109 )
{
int V_110 = V_109 -> V_111 . V_6 ;
if ( V_109 -> V_111 . V_112 != V_113 )
V_110 = 0 ;
if ( V_109 -> V_111 . V_114 != V_113 )
V_110 = 0 ;
F_35 ( V_110 , V_7 ) ;
return 0 ;
}
static int T_5 F_44 ( struct V_73 * V_105 )
{
struct V_115 V_111 ;
struct V_108 * V_109 ;
memset ( & V_111 , 0 , sizeof( struct V_115 ) ) ;
V_111 . type = V_116 ;
V_111 . V_45 = V_45 ;
V_109 = F_45 ( L_8 , V_105 , NULL , & V_117 ,
& V_111 ) ;
if ( F_46 ( V_109 ) ) {
F_47 ( L_9 ) ;
V_118 = NULL ;
return F_48 ( V_109 ) ;
}
V_118 = V_109 ;
V_109 -> V_111 . V_112 = V_113 ;
V_109 -> V_111 . V_6 = F_42 ( V_109 ) ;
F_49 ( V_109 ) ;
return 0 ;
}
static void F_50 ( void )
{
F_51 ( V_118 ) ;
}
static void F_52 ( struct V_119 * V_120 )
{
T_1 V_121 ;
T_2 V_21 ;
if ( F_5 ( V_32 ) ) {
V_21 = F_34 ( & V_121 , V_32 ) ;
if ( F_19 ( V_21 ) ) {
if ( V_2 -> V_33 == 3 )
F_53 ( V_122 , ! V_121 ) ;
else
F_54 ( V_122 , ! V_121 ) ;
}
}
if ( F_5 ( V_34 ) ) {
V_21 = F_34 ( & V_121 , V_34 ) ;
if ( F_19 ( V_21 ) )
F_54 ( V_123 , ! V_121 ) ;
}
if ( F_5 ( V_66 ) && F_16 ( V_82 ) ) {
V_21 = F_34 ( & V_121 , V_87 ) ;
if ( F_19 ( V_21 ) )
F_54 ( V_124 , ! V_121 ) ;
}
F_55 ( & V_125 , F_56 ( V_126 ) ) ;
}
static int F_57 ( void * V_127 , bool V_128 )
{
T_2 V_21 ;
T_1 V_15 = ( unsigned long ) V_127 ;
if ( V_129 ) {
V_21 = F_35 ( ! V_128 , V_15 ) ;
if ( F_13 ( V_21 ) )
return - V_130 ;
}
return 0 ;
}
static struct V_131 * F_58 ( struct V_73 * V_105 ,
enum V_132 type ,
char * V_133 , T_1 V_15 )
{
int V_29 ;
struct V_131 * V_134 ;
T_1 V_121 ;
T_2 V_21 ;
V_134 = F_59 ( V_133 , V_105 , type ,
& V_135 ,
( void * ) ( unsigned long ) V_15 ) ;
if ( ! V_134 )
return F_60 ( - V_136 ) ;
V_21 = F_34 ( & V_121 , V_15 ) ;
V_29 = F_61 ( V_134 ) ;
if ( V_29 ) {
F_62 ( V_134 ) ;
return F_60 ( V_29 ) ;
}
if ( F_19 ( V_21 ) )
F_54 ( V_134 , ! V_121 ) ;
return V_134 ;
}
static int F_63 ( struct V_73 * V_105 )
{
int V_29 ;
if ( F_5 ( V_32 ) ) {
V_122 = F_58 ( V_105 , V_137 ,
L_10 , V_32 ) ;
if ( F_46 ( V_122 ) ) {
V_29 = F_48 ( V_122 ) ;
goto V_138;
}
}
if ( F_5 ( V_34 ) ) {
V_123 = F_58 ( V_105 ,
V_139 , L_11 ,
V_34 ) ;
if ( F_46 ( V_123 ) ) {
V_29 = F_48 ( V_123 ) ;
goto V_140;
}
}
if ( F_5 ( V_66 ) ) {
V_124 = F_58 ( V_105 ,
V_141 , L_12 ,
V_66 ) ;
if ( F_46 ( V_124 ) ) {
V_29 = F_48 ( V_124 ) ;
goto V_142;
}
}
V_129 = true ;
if ( ( V_143 || ! F_16 ( V_144 ) ) &&
F_5 ( V_32 | V_34 | V_66 ) )
F_55 ( & V_125 ,
F_56 ( V_126 ) ) ;
return 0 ;
V_142:
if ( F_5 ( V_34 ) ) {
F_64 ( V_123 ) ;
F_62 ( V_123 ) ;
}
V_140:
if ( F_5 ( V_32 ) ) {
F_64 ( V_122 ) ;
F_62 ( V_122 ) ;
}
V_138:
return V_29 ;
}
static void F_65 ( void )
{
if ( ( V_143 || ! F_16 ( V_144 ) ) &&
F_5 ( V_32 | V_34 | V_66 ) )
F_66 ( & V_125 ) ;
if ( F_5 ( V_32 ) ) {
F_64 ( V_122 ) ;
F_62 ( V_122 ) ;
}
if ( F_5 ( V_34 ) ) {
F_64 ( V_123 ) ;
F_62 ( V_123 ) ;
}
if ( F_5 ( V_66 ) ) {
F_64 ( V_124 ) ;
F_62 ( V_124 ) ;
}
return;
}
static T_6 F_67 ( struct V_73 * V_105 ,
struct V_145 * V_146 , char * V_147 )
{
T_1 V_19 ; \
T_2 V_21 ;
F_31 ( L_13
L_14 , V_148 -> V_149 ) ;
V_21 = F_34 ( & V_19 , V_66 ) ;
if ( F_19 ( V_21 ) )
return sprintf ( V_147 , L_15 , V_19 ) ;
return sprintf ( V_147 , L_16 ) ;
}
static T_6 F_68 ( struct V_73 * V_105 ,
struct V_145 * V_146 , const char * V_147 , T_7 V_150 )
{
T_1 V_59 = F_69 ( V_147 , NULL , 10 ) ;
T_2 V_21 = F_35 ( V_59 , V_66 ) ;
F_31 ( L_13
L_14 , V_148 -> V_149 ) ;
if ( F_13 ( V_21 ) )
return - V_151 ;
return V_150 ;
}
static T_6 F_70 ( struct V_73 * V_105 , struct V_145 * V_146 ,
char * V_147 )
{
F_31 ( L_17
L_14 , V_148 -> V_149 ) ;
switch ( V_1 -> type ) {
case V_97 :
return sprintf ( V_147 , L_18 ) ;
case V_98 :
return sprintf ( V_147 , L_19 ) ;
case V_99 :
return sprintf ( V_147 , L_20 ) ;
case V_100 :
return sprintf ( V_147 , L_21 ) ;
default:
return sprintf ( V_147 , L_22 ) ;
}
}
static void F_71 ( T_1 V_26 , void * V_152 )
{
struct V_18 V_153 = { V_49 , NULL } ;
union V_50 * V_51 ;
struct V_154 V_75 ;
T_2 V_21 ;
T_3 V_155 ;
const struct V_156 * V_157 ;
V_21 = F_72 ( V_26 , & V_153 ) ;
if ( V_21 != V_31 ) {
F_25 ( L_23 , V_21 ) ;
return;
}
V_51 = (union V_50 * ) V_153 . V_23 ;
if ( ! V_51 )
return;
if ( V_51 -> type != V_52 ) {
F_25 ( L_24 , V_51 -> type ) ;
F_14 ( V_51 ) ;
return;
}
if ( V_51 -> V_53 . V_22 != 8 ) {
F_25 ( L_1 , V_51 -> V_53 . V_22 ) ;
F_14 ( V_51 ) ;
return;
}
V_75 = * ( (struct V_154 * ) V_51 -> V_53 . V_23 ) ;
F_14 ( V_51 ) ;
switch ( V_75 . V_158 ) {
case V_159 :
V_155 = V_75 . V_155 ;
F_73 ( L_25 , V_155 ) ;
V_157 = F_74 ( V_160 ,
V_75 . V_161 ) ;
if ( ! V_157 ) {
F_25 ( L_26 ,
V_75 . V_161 ) ;
} else {
switch ( V_157 -> V_162 ) {
case V_163 :
case V_164 :
if ( F_5 ( V_32 ) )
F_54 ( V_122 ,
! ( V_155 & V_85 ) ) ;
if ( F_5 ( V_66 ) )
F_54 ( V_124 ,
! ( V_155 & V_87 ) ) ;
if ( F_5 ( V_34 ) )
F_54 ( V_123 ,
! ( V_155 & V_86 ) ) ;
break;
}
F_75 ( V_160 , V_157 ,
1 , true ) ;
}
break;
default:
F_25 ( L_27 ,
V_75 . V_158 , V_75 . V_161 ) ;
break;
}
}
static T_2
F_76 ( struct V_165 * V_77 ,
struct V_166 * V_75 )
{
T_2 V_21 ;
union V_50 * V_51 ;
struct V_18 V_20 = { sizeof( struct V_165 ) , V_77 } ;
struct V_18 V_81 = { V_49 , NULL } ;
V_21 = F_7 ( V_82 , 0 , 0x1 , & V_20 , & V_81 ) ;
if ( F_13 ( V_21 ) )
return V_21 ;
V_51 = V_81 . V_23 ;
if ( ! V_51 )
return V_30 ;
else if ( V_51 -> type != V_52 ) {
F_14 ( V_51 ) ;
return V_30 ;
}
if ( V_51 -> V_53 . V_22 != 4 ) {
F_25 ( L_1 , V_51 -> V_53 . V_22 ) ;
F_14 ( V_51 ) ;
return V_30 ;
}
* V_75 = * ( (struct V_166 * ) V_51 -> V_53 . V_23 ) ;
F_14 ( V_51 ) ;
return V_21 ;
}
static int F_77 ( void )
{
struct V_166 V_75 ;
T_2 V_21 ;
struct V_165 V_77 = {
. V_78 = 0x1 ,
. V_167 = 0xFFFF ,
. V_80 = 0xFFFF ,
. V_168 = 0x00 ,
} ;
V_21 = F_76 ( & V_77 , & V_75 ) ;
if ( V_75 . V_83 || V_75 . V_84 )
F_25 ( L_28 ,
V_75 . V_83 ,
V_75 . V_84 ) ;
else
F_31 ( L_29 ) ;
return V_21 ;
}
static int F_78 ( void )
{
struct V_166 V_75 ;
T_2 V_21 ;
struct V_165 V_77 = {
. V_78 = 0x1 ,
. V_167 = 0xFFFF ,
. V_80 = 0xFFFF ,
. V_168 = 0x01 ,
} ;
V_21 = F_76 ( & V_77 , & V_75 ) ;
if ( V_75 . V_83 || V_75 . V_84 )
F_25 ( L_30 ,
V_75 . V_83 ,
V_75 . V_84 ) ;
return V_21 ;
}
static int T_4 F_79 ( void )
{
T_2 V_21 ;
int V_29 ;
V_160 = F_80 () ;
if ( ! V_160 )
return - V_136 ;
V_160 -> V_133 = L_31 ;
V_160 -> V_169 = L_32 ;
V_160 -> V_170 . V_171 = V_172 ;
V_29 = F_81 ( V_160 , V_173 , NULL ) ;
if ( V_29 )
goto V_174;
V_21 = F_82 ( V_144 ,
F_71 , NULL ) ;
if ( F_13 ( V_21 ) ) {
V_29 = - V_175 ;
goto V_176;
}
V_29 = F_83 ( V_160 ) ;
if ( V_29 )
goto V_177;
return 0 ;
V_177:
F_84 ( V_144 ) ;
V_176:
F_85 ( V_160 ) ;
V_174:
F_86 ( V_160 ) ;
return V_29 ;
}
static void F_87 ( void )
{
F_84 ( V_144 ) ;
F_85 ( V_160 ) ;
F_88 ( V_160 ) ;
}
static T_1 F_89 ( void )
{
struct V_18 V_48 = { V_49 , NULL } ;
union V_50 * V_51 ;
T_2 V_21 ;
T_1 V_80 = 0 ;
V_21 = F_33 ( V_96 , 1 , & V_48 ) ;
if ( F_13 ( V_21 ) )
return 0 ;
V_51 = (union V_50 * ) V_48 . V_23 ;
if ( V_51 && V_51 -> type == V_52 &&
( V_51 -> V_53 . V_22 == sizeof( T_1 ) ||
V_51 -> V_53 . V_22 == sizeof( V_61 ) ) ) {
V_80 = * ( ( T_1 * ) V_51 -> V_53 . V_23 ) ;
} else if ( V_51 -> type == V_62 ) {
V_80 = ( T_1 ) V_51 -> integer . V_26 ;
}
F_14 ( V_48 . V_23 ) ;
return V_80 ;
}
static int T_5 F_90 ( struct V_178 * V_73 )
{
int V_29 ;
if ( F_5 ( V_5 ) ) {
V_29 = F_38 ( & V_73 -> V_105 ) ;
if ( V_29 )
goto V_179;
}
if ( F_5 ( V_7 ) ) {
V_29 = F_44 ( & V_73 -> V_105 ) ;
if ( V_29 )
goto V_180;
}
V_29 = F_63 ( & V_73 -> V_105 ) ;
if ( V_29 )
goto V_181;
return V_29 ;
V_181:
if ( F_5 ( V_7 ) )
F_50 () ;
V_180:
if ( F_5 ( V_5 ) )
F_40 () ;
V_179:
return V_29 ;
}
static int F_91 ( struct V_178 * V_73 )
{
if ( F_5 ( V_5 ) )
F_40 () ;
if ( F_5 ( V_7 ) )
F_50 () ;
F_65 () ;
return 0 ;
}
static int F_92 ( struct V_178 * V_105 ,
T_8 V_121 )
{
T_1 V_26 ;
struct V_182 * V_127 = & V_1 -> V_127 ;
if ( ! V_127 )
return - V_136 ;
if ( F_5 ( V_5 ) ) {
F_34 ( & V_26 , V_5 ) ;
F_35 ( V_107 , V_5 ) ;
V_127 -> V_3 = V_26 ;
}
if ( F_5 ( V_7 ) ) {
F_34 ( & V_26 , V_7 ) ;
V_127 -> V_6 = V_26 ;
}
return 0 ;
}
static int F_93 ( struct V_178 * V_73 )
{
struct V_182 * V_127 = & V_1 -> V_127 ;
if ( ! V_127 )
return - V_136 ;
if ( F_5 ( V_5 ) )
F_35 ( V_127 -> V_3 , V_5 ) ;
if ( F_5 ( V_7 ) )
F_35 ( V_127 -> V_6 , V_7 ) ;
return 0 ;
}
static void F_94 ( struct V_178 * V_73 )
{
struct V_182 * V_127 = & V_1 -> V_127 ;
if ( ! V_127 )
return;
if ( F_5 ( V_5 ) )
F_35 ( V_107 , V_5 ) ;
}
static int F_95 ( struct V_178 * V_73 )
{
if ( F_5 ( V_66 ) )
F_96 ( & V_73 -> V_105 , & V_183 ) ;
F_96 ( & V_73 -> V_105 , & V_184 ) ;
return 0 ;
}
static int F_97 ( void )
{
int V_185 = - V_136 ;
if ( F_5 ( V_66 ) ) {
V_185 = F_98 ( & V_186 -> V_105 ,
& V_183 ) ;
if ( V_185 )
goto V_187;
}
V_185 = F_98 ( & V_186 -> V_105 ,
& V_184 ) ;
if ( V_185 )
goto V_187;
return 0 ;
V_187:
F_95 ( V_186 ) ;
return V_185 ;
}
static void F_99 ( void )
{
F_100 ( V_1 -> V_188 . V_80 ) ;
F_100 ( V_1 -> V_188 . V_189 ) ;
}
static int F_101 ( void )
{
V_1 -> V_188 . V_189 = F_102 ( L_8 , NULL ) ;
if ( ! V_1 -> V_188 . V_189 ) {
F_47 ( L_33 ) ;
return - V_136 ;
}
V_1 -> V_188 . V_80 = F_103 ( L_34 , V_190 ,
V_1 -> V_188 . V_189 ,
& V_1 -> V_188 . V_191 ) ;
if ( ! V_1 -> V_188 . V_80 )
goto V_192;
return 0 ;
V_192:
F_99 () ;
return - V_136 ;
}
static int T_4 F_104 ( void )
{
int V_29 ;
F_31 ( L_35 ) ;
if ( F_4 ( V_193 ) ) {
F_31 ( L_36 ) ;
return - V_130 ;
}
F_3 () ;
if ( F_16 ( V_25 ) && F_16 ( V_60 ) )
V_1 = & V_194 ;
if ( ! F_16 ( V_25 ) && F_16 ( V_60 ) )
V_1 = & V_195 ;
if ( F_16 ( V_82 ) )
V_1 = & V_196 ;
if ( V_1 )
F_105 ( F_30 , NULL ) ;
if ( F_16 ( V_96 ) && V_1 ) {
if ( ! V_95 && F_13 ( F_32 () ) ) {
F_47 ( L_37 ) ;
return - V_130 ;
}
V_1 -> V_4 |= V_7 ;
} else if ( ! F_16 ( V_96 ) && V_1 && ! V_95 ) {
F_47 ( L_38 ) ;
return - V_130 ;
}
if ( F_16 ( V_25 ) && ! F_16 ( V_60 ) ) {
V_1 = & V_197 ;
if ( F_13 ( F_15 () ) ) {
F_47 ( L_39 ) ;
return - V_130 ;
}
}
if ( F_16 ( V_25 ) )
F_12 () ;
if ( ! V_1 ) {
F_47 ( L_40 ) ;
return - V_130 ;
}
F_1 () ;
if ( F_106 () ) {
V_1 -> V_4 &= ~ V_7 ;
F_31 ( L_41
L_42 ) ;
}
if ( F_16 ( V_82 ) ) {
if ( V_143 ) {
if ( F_13 ( F_77 () ) ) {
F_47 ( L_43 ) ;
return - V_130 ;
}
} else if ( F_13 ( F_78 () ) ) {
F_47 ( L_44 ) ;
return - V_130 ;
}
} else if ( V_143 ) {
F_31 ( L_45 ) ;
}
if ( F_16 ( V_144 ) ) {
V_29 = F_79 () ;
if ( V_29 )
return V_29 ;
}
V_29 = F_107 ( & V_198 ) ;
if ( V_29 ) {
F_47 ( L_46 ) ;
goto V_199;
}
V_186 = F_108 ( L_8 , - 1 ) ;
if ( ! V_186 ) {
V_29 = - V_136 ;
goto V_200;
}
V_29 = F_109 ( V_186 ) ;
if ( V_29 )
goto V_201;
V_29 = F_97 () ;
if ( V_29 )
goto V_202;
if ( F_16 ( V_96 ) ) {
V_1 -> V_188 . V_191 = F_89 () ;
V_29 = F_101 () ;
if ( V_29 )
goto V_203;
}
F_36 () ;
return 0 ;
V_203:
F_95 ( V_186 ) ;
V_202:
F_110 ( V_186 ) ;
V_201:
F_111 ( V_186 ) ;
V_200:
F_112 ( & V_198 ) ;
V_199:
if ( F_16 ( V_144 ) )
F_87 () ;
return V_29 ;
}
static void T_9 F_113 ( void )
{
if ( F_16 ( V_144 ) )
F_87 () ;
F_95 ( V_186 ) ;
F_99 () ;
F_114 ( V_186 ) ;
F_112 ( & V_198 ) ;
F_31 ( L_47 ) ;
return;
}
