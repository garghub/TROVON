static int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
if ( F_3 ( V_2 , V_4 ) )
return 1 ;
if ( ! strcmp ( V_6 -> V_7 , V_4 -> V_7 ) )
return 1 ;
return 0 ;
}
static int F_4 ( struct V_1 * V_2 , struct V_8 * V_9 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_10 ;
V_10 = F_5 ( V_2 , V_9 ) ;
if ( V_10 != - V_11 )
return V_10 ;
F_6 ( V_9 , L_1 , V_12 ,
V_6 -> V_7 ) ;
return 0 ;
}
static int F_7 ( struct V_1 * V_2 , void * V_13 )
{
return V_2 -> V_14 == V_13 ;
}
struct V_5 * F_8 ( struct V_15 * V_16 )
{
struct V_1 * V_2 ;
V_2 = F_9 ( & V_17 , NULL , V_16 , F_7 ) ;
return V_2 ? F_2 ( V_2 ) : NULL ;
}
static void F_10 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
F_11 ( V_2 -> V_14 ) ;
F_12 ( V_6 ) ;
}
static struct V_5 * F_13 ( struct V_18 * V_19 )
{
struct V_5 * V_6 ;
V_6 = F_14 ( sizeof( * V_6 ) , V_20 ) ;
if ( ! V_6 )
return F_15 ( - V_21 ) ;
V_6 -> V_19 = V_19 ;
V_6 -> V_2 . V_22 = & V_17 ;
V_6 -> V_2 . V_23 = V_19 -> V_2 ;
V_6 -> V_2 . type = & V_24 ;
F_16 ( & V_6 -> V_2 ) ;
return V_6 ;
}
static int F_17 ( struct V_5 * V_6 )
{
struct V_18 * V_19 = V_6 -> V_19 ;
F_18 ( & V_6 -> V_2 , L_2 , F_19 ( V_19 -> V_2 ) , V_6 -> V_25 ) ;
return F_20 ( & V_6 -> V_2 ) ;
}
static struct V_5 *
F_21 ( struct V_18 * V_19 , struct V_15 * V_26 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
struct V_27 V_28 = { } ;
int V_29 ;
T_1 V_30 ;
if ( F_22 ( V_26 , V_28 . type , sizeof( V_28 . type ) ) < 0 ) {
F_23 ( V_2 , L_3 , V_26 ) ;
return F_15 ( - V_31 ) ;
}
V_29 = F_24 ( V_26 , L_4 , & V_30 ) ;
if ( V_29 ) {
F_23 ( V_2 , L_5 ,
V_26 , V_29 ) ;
return F_15 ( - V_31 ) ;
}
V_28 . V_25 = V_30 ;
V_28 . V_26 = F_25 ( V_26 ) ;
return F_26 ( V_19 , & V_28 ) ;
}
static struct V_5 *
F_21 ( struct V_18 * V_19 , struct V_15 * V_26 )
{
return F_15 ( - V_11 ) ;
}
struct V_5 *
F_26 ( struct V_18 * V_19 ,
const struct V_27 * V_28 )
{
struct V_5 * V_6 ;
struct V_1 * V_2 = V_19 -> V_2 ;
int V_29 ;
if ( ! V_28 ) {
F_23 ( V_2 , L_6 ) ;
return F_15 ( - V_31 ) ;
}
if ( V_28 -> V_25 > 3 ) {
F_23 ( V_2 , L_7 , V_28 -> V_25 ) ;
return F_15 ( - V_31 ) ;
}
V_6 = F_13 ( V_19 ) ;
if ( F_27 ( V_6 ) ) {
F_23 ( V_2 , L_8 ,
F_28 ( V_6 ) ) ;
return V_6 ;
}
V_6 -> V_2 . V_14 = V_28 -> V_26 ;
V_6 -> V_25 = V_28 -> V_25 ;
F_29 ( V_6 -> V_7 , V_28 -> type , sizeof( V_6 -> V_7 ) ) ;
V_29 = F_17 ( V_6 ) ;
if ( V_29 ) {
F_23 ( V_2 , L_9 , V_29 ) ;
F_12 ( V_6 ) ;
return F_15 ( V_29 ) ;
}
return V_6 ;
}
void F_30 ( struct V_5 * V_6 )
{
F_31 ( & V_6 -> V_2 ) ;
}
struct V_18 * F_32 ( struct V_15 * V_26 )
{
struct V_18 * V_19 ;
F_33 ( & V_32 ) ;
F_34 (host, &host_list, list) {
if ( V_19 -> V_2 -> V_14 == V_26 ) {
F_35 ( & V_32 ) ;
return V_19 ;
}
}
F_35 ( & V_32 ) ;
return NULL ;
}
int F_36 ( struct V_18 * V_19 )
{
struct V_15 * V_26 ;
F_37 (host->dev->of_node, node) {
if ( ! F_38 ( V_26 , L_4 , NULL ) )
continue;
F_21 ( V_19 , V_26 ) ;
}
F_33 ( & V_32 ) ;
F_39 ( & V_19 -> V_33 , & V_34 ) ;
F_35 ( & V_32 ) ;
return 0 ;
}
static int F_40 ( struct V_1 * V_2 , void * V_35 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
F_30 ( V_6 ) ;
return 0 ;
}
void F_41 ( struct V_18 * V_19 )
{
F_42 ( V_19 -> V_2 , NULL , F_40 ) ;
F_33 ( & V_32 ) ;
F_43 ( & V_19 -> V_33 ) ;
F_35 ( & V_32 ) ;
}
int F_44 ( struct V_5 * V_6 )
{
const struct V_36 * V_37 = V_6 -> V_19 -> V_37 ;
if ( ! V_37 || ! V_37 -> V_38 )
return - V_39 ;
return V_37 -> V_38 ( V_6 -> V_19 , V_6 ) ;
}
int F_45 ( struct V_5 * V_6 )
{
const struct V_36 * V_37 = V_6 -> V_19 -> V_37 ;
if ( ! V_37 || ! V_37 -> V_40 )
return - V_39 ;
return V_37 -> V_40 ( V_6 -> V_19 , V_6 ) ;
}
static T_2 F_46 ( struct V_5 * V_6 ,
struct V_41 * V_42 )
{
const struct V_36 * V_37 = V_6 -> V_19 -> V_37 ;
if ( ! V_37 || ! V_37 -> V_43 )
return - V_39 ;
if ( V_6 -> V_44 & V_45 )
V_42 -> V_46 |= V_47 ;
return V_37 -> V_43 ( V_6 -> V_19 , V_42 ) ;
}
bool F_47 ( T_3 type )
{
switch ( type ) {
case V_48 :
case V_49 :
case V_50 :
case V_51 :
case V_52 :
case V_53 :
case V_54 :
case V_55 :
case V_56 :
case V_57 :
case V_58 :
case V_59 :
case V_60 :
case V_61 :
case V_62 :
case V_63 :
case V_64 :
case V_65 :
case V_66 :
return true ;
}
return false ;
}
bool F_48 ( T_3 type )
{
switch ( type ) {
case V_67 :
case V_68 :
case V_69 :
case V_70 :
case V_71 :
case V_72 :
case V_73 :
case V_74 :
case V_75 :
case V_76 :
case V_77 :
case V_78 :
case V_79 :
case V_80 :
return true ;
}
return false ;
}
int F_49 ( struct V_81 * V_82 ,
const struct V_41 * V_42 )
{
if ( ! V_82 || ! V_42 )
return - V_31 ;
if ( ! F_47 ( V_42 -> type ) &&
! F_48 ( V_42 -> type ) )
return - V_31 ;
if ( V_42 -> V_25 > 3 )
return - V_31 ;
memset ( V_82 , 0 , sizeof( * V_82 ) ) ;
V_82 -> V_83 [ 0 ] = ( ( V_42 -> V_25 & 0x3 ) << 6 ) | ( V_42 -> type & 0x3f ) ;
if ( F_48 ( V_42 -> type ) ) {
V_82 -> V_83 [ 1 ] = ( V_42 -> V_84 >> 0 ) & 0xff ;
V_82 -> V_83 [ 2 ] = ( V_42 -> V_84 >> 8 ) & 0xff ;
V_82 -> V_85 = V_42 -> V_84 ;
V_82 -> V_86 = V_42 -> V_87 ;
} else {
const T_3 * V_88 = V_42 -> V_87 ;
V_82 -> V_83 [ 1 ] = ( V_42 -> V_84 > 0 ) ? V_88 [ 0 ] : 0 ;
V_82 -> V_83 [ 2 ] = ( V_42 -> V_84 > 1 ) ? V_88 [ 1 ] : 0 ;
}
V_82 -> V_89 = sizeof( V_82 -> V_83 ) + V_82 -> V_85 ;
return 0 ;
}
int F_50 ( struct V_5 * V_6 )
{
struct V_41 V_42 = {
. V_25 = V_6 -> V_25 ,
. type = V_55 ,
. V_87 = ( T_3 [ 2 ] ) { 0 , 0 } ,
. V_84 = 2 ,
} ;
return F_46 ( V_6 , & V_42 ) ;
}
int F_51 ( struct V_5 * V_6 )
{
struct V_41 V_42 = {
. V_25 = V_6 -> V_25 ,
. type = V_56 ,
. V_87 = ( T_3 [ 2 ] ) { 0 , 0 } ,
. V_84 = 2 ,
} ;
return F_46 ( V_6 , & V_42 ) ;
}
int F_52 ( struct V_5 * V_6 ,
T_4 V_90 )
{
T_3 V_88 [ 2 ] = { V_90 & 0xff , V_90 >> 8 } ;
struct V_41 V_42 = {
. V_25 = V_6 -> V_25 ,
. type = V_66 ,
. V_84 = sizeof( V_88 ) ,
. V_87 = V_88 ,
} ;
return F_46 ( V_6 , & V_42 ) ;
}
T_2 F_53 ( struct V_5 * V_6 , const void * V_86 ,
T_5 V_89 )
{
struct V_41 V_42 = {
. V_25 = V_6 -> V_25 ,
. V_87 = V_86 ,
. V_84 = V_89
} ;
switch ( V_89 ) {
case 0 :
V_42 . type = V_57 ;
break;
case 1 :
V_42 . type = V_58 ;
break;
case 2 :
V_42 . type = V_59 ;
break;
default:
V_42 . type = V_69 ;
break;
}
return F_46 ( V_6 , & V_42 ) ;
}
T_2 F_54 ( struct V_5 * V_6 , const void * V_91 ,
T_5 V_92 , void * V_13 , T_5 V_89 )
{
struct V_41 V_42 = {
. V_25 = V_6 -> V_25 ,
. V_84 = V_92 ,
. V_87 = V_91 ,
. V_93 = V_89 ,
. V_94 = V_13
} ;
switch ( V_92 ) {
case 0 :
V_42 . type = V_60 ;
break;
case 1 :
V_42 . type = V_61 ;
break;
case 2 :
V_42 . type = V_62 ;
break;
default:
return - V_31 ;
}
return F_46 ( V_6 , & V_42 ) ;
}
T_2 F_55 ( struct V_5 * V_6 ,
const void * V_13 , T_5 V_95 )
{
struct V_41 V_42 = {
. V_25 = V_6 -> V_25 ,
. V_87 = V_13 ,
. V_84 = V_95
} ;
switch ( V_95 ) {
case 0 :
return - V_31 ;
case 1 :
V_42 . type = V_63 ;
break;
case 2 :
V_42 . type = V_64 ;
break;
default:
V_42 . type = V_70 ;
break;
}
return F_46 ( V_6 , & V_42 ) ;
}
T_2 F_56 ( struct V_5 * V_6 , T_3 V_96 ,
const void * V_13 , T_5 V_95 )
{
T_2 V_10 ;
T_5 V_89 ;
T_3 * V_88 ;
if ( V_95 > 0 ) {
V_89 = 1 + V_95 ;
V_88 = F_57 ( V_89 , V_20 ) ;
if ( ! V_88 )
return - V_21 ;
V_88 [ 0 ] = V_96 ;
memcpy ( & V_88 [ 1 ] , V_13 , V_95 ) ;
} else {
V_88 = & V_96 ;
V_89 = 1 ;
}
V_10 = F_55 ( V_6 , V_88 , V_89 ) ;
if ( V_95 > 0 )
F_12 ( V_88 ) ;
return V_10 ;
}
T_2 F_58 ( struct V_5 * V_6 , T_3 V_96 , void * V_13 ,
T_5 V_95 )
{
struct V_41 V_42 = {
. V_25 = V_6 -> V_25 ,
. type = V_65 ,
. V_87 = & V_96 ,
. V_84 = 1 ,
. V_94 = V_13 ,
. V_93 = V_95
} ;
return F_46 ( V_6 , & V_42 ) ;
}
int F_59 ( struct V_5 * V_6 )
{
T_2 V_10 ;
V_10 = F_56 ( V_6 , V_97 , NULL , 0 ) ;
if ( V_10 < 0 )
return V_10 ;
return 0 ;
}
int F_60 ( struct V_5 * V_6 )
{
T_2 V_10 ;
V_10 = F_56 ( V_6 , V_98 , NULL , 0 ) ;
if ( V_10 < 0 )
return V_10 ;
return 0 ;
}
int F_61 ( struct V_5 * V_6 , T_3 * V_99 )
{
T_2 V_10 ;
V_10 = F_58 ( V_6 , V_100 , V_99 ,
sizeof( * V_99 ) ) ;
if ( V_10 <= 0 ) {
if ( V_10 == 0 )
V_10 = - V_101 ;
return V_10 ;
}
return 0 ;
}
int F_62 ( struct V_5 * V_6 , T_3 * V_102 )
{
T_2 V_10 ;
V_10 = F_58 ( V_6 , V_103 , V_102 ,
sizeof( * V_102 ) ) ;
if ( V_10 <= 0 ) {
if ( V_10 == 0 )
V_10 = - V_101 ;
return V_10 ;
}
return 0 ;
}
int F_63 ( struct V_5 * V_6 )
{
T_2 V_10 ;
V_10 = F_56 ( V_6 , V_104 , NULL , 0 ) ;
if ( V_10 < 0 )
return V_10 ;
return 0 ;
}
int F_64 ( struct V_5 * V_6 )
{
T_2 V_10 ;
V_10 = F_56 ( V_6 , V_105 , NULL , 0 ) ;
if ( V_10 < 0 )
return V_10 ;
return 0 ;
}
int F_65 ( struct V_5 * V_6 )
{
T_2 V_10 ;
V_10 = F_56 ( V_6 , V_106 , NULL , 0 ) ;
if ( V_10 < 0 )
return V_10 ;
return 0 ;
}
int F_66 ( struct V_5 * V_6 )
{
T_2 V_10 ;
V_10 = F_56 ( V_6 , V_107 , NULL , 0 ) ;
if ( V_10 < 0 )
return V_10 ;
return 0 ;
}
int F_67 ( struct V_5 * V_6 , T_4 V_108 ,
T_4 V_109 )
{
T_3 V_86 [ 4 ] = { V_108 >> 8 , V_108 & 0xff , V_109 >> 8 , V_109 & 0xff } ;
T_2 V_10 ;
V_10 = F_56 ( V_6 , V_110 , V_86 ,
sizeof( V_86 ) ) ;
if ( V_10 < 0 )
return V_10 ;
return 0 ;
}
int F_68 ( struct V_5 * V_6 , T_4 V_108 ,
T_4 V_109 )
{
T_3 V_86 [ 4 ] = { V_108 >> 8 , V_108 & 0xff , V_109 >> 8 , V_109 & 0xff } ;
T_2 V_10 ;
V_10 = F_56 ( V_6 , V_111 , V_86 ,
sizeof( V_86 ) ) ;
if ( V_10 < 0 )
return V_10 ;
return 0 ;
}
int F_69 ( struct V_5 * V_6 )
{
T_2 V_10 ;
V_10 = F_56 ( V_6 , V_112 , NULL , 0 ) ;
if ( V_10 < 0 )
return V_10 ;
return 0 ;
}
int F_70 ( struct V_5 * V_6 ,
enum V_113 V_99 )
{
T_3 V_90 = V_99 ;
T_2 V_10 ;
V_10 = F_56 ( V_6 , V_114 , & V_90 ,
sizeof( V_90 ) ) ;
if ( V_10 < 0 )
return V_10 ;
return 0 ;
}
int F_71 ( struct V_5 * V_6 , T_3 V_102 )
{
T_2 V_10 ;
V_10 = F_56 ( V_6 , V_115 , & V_102 ,
sizeof( V_102 ) ) ;
if ( V_10 < 0 )
return V_10 ;
return 0 ;
}
int F_72 ( struct V_5 * V_6 , T_4 V_116 )
{
T_3 V_86 [ 3 ] = { V_117 , V_116 >> 8 ,
V_116 & 0xff } ;
T_2 V_10 ;
V_10 = F_53 ( V_6 , V_86 , sizeof( V_86 ) ) ;
if ( V_10 < 0 )
return V_10 ;
return 0 ;
}
int F_73 ( struct V_5 * V_6 ,
T_4 V_118 )
{
T_3 V_86 [ 2 ] = { V_118 & 0xff , V_118 >> 8 } ;
T_2 V_10 ;
V_10 = F_56 ( V_6 , V_119 ,
V_86 , sizeof( V_86 ) ) ;
if ( V_10 < 0 )
return V_10 ;
return 0 ;
}
int F_74 ( struct V_5 * V_6 ,
T_4 * V_118 )
{
T_2 V_10 ;
V_10 = F_58 ( V_6 , V_120 ,
V_118 , sizeof( * V_118 ) ) ;
if ( V_10 <= 0 ) {
if ( V_10 == 0 )
V_10 = - V_101 ;
return V_10 ;
}
return 0 ;
}
static int F_75 ( struct V_1 * V_2 )
{
struct V_121 * V_4 = F_76 ( V_2 -> V_122 ) ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
return V_4 -> V_123 ( V_6 ) ;
}
static int F_77 ( struct V_1 * V_2 )
{
struct V_121 * V_4 = F_76 ( V_2 -> V_122 ) ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
return V_4 -> remove ( V_6 ) ;
}
static void F_78 ( struct V_1 * V_2 )
{
struct V_121 * V_4 = F_76 ( V_2 -> V_122 ) ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
V_4 -> V_124 ( V_6 ) ;
}
int F_79 ( struct V_121 * V_4 ,
struct V_125 * V_126 )
{
V_4 -> V_122 . V_22 = & V_17 ;
V_4 -> V_122 . V_126 = V_126 ;
if ( V_4 -> V_123 )
V_4 -> V_122 . V_123 = F_75 ;
if ( V_4 -> remove )
V_4 -> V_122 . remove = F_77 ;
if ( V_4 -> V_124 )
V_4 -> V_122 . V_124 = F_78 ;
return F_80 ( & V_4 -> V_122 ) ;
}
void F_81 ( struct V_121 * V_4 )
{
F_82 ( & V_4 -> V_122 ) ;
}
static int T_6 F_83 ( void )
{
return F_84 ( & V_17 ) ;
}
