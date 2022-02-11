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
F_23 ( V_2 , L_3 , V_26 -> V_31 ) ;
return F_15 ( - V_32 ) ;
}
V_29 = F_24 ( V_26 , L_4 , & V_30 ) ;
if ( V_29 ) {
F_23 ( V_2 , L_5 ,
V_26 -> V_31 , V_29 ) ;
return F_15 ( - V_32 ) ;
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
return F_15 ( - V_32 ) ;
}
if ( V_28 -> V_25 > 3 ) {
F_23 ( V_2 , L_7 , V_28 -> V_25 ) ;
return F_15 ( - V_32 ) ;
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
F_33 ( & V_33 ) ;
F_34 (host, &host_list, list) {
if ( V_19 -> V_2 -> V_14 == V_26 ) {
F_35 ( & V_33 ) ;
return V_19 ;
}
}
F_35 ( & V_33 ) ;
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
F_33 ( & V_33 ) ;
F_39 ( & V_19 -> V_34 , & V_35 ) ;
F_35 ( & V_33 ) ;
return 0 ;
}
static int F_40 ( struct V_1 * V_2 , void * V_36 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
F_30 ( V_6 ) ;
return 0 ;
}
void F_41 ( struct V_18 * V_19 )
{
F_42 ( V_19 -> V_2 , NULL , F_40 ) ;
F_33 ( & V_33 ) ;
F_43 ( & V_19 -> V_34 ) ;
F_35 ( & V_33 ) ;
}
int F_44 ( struct V_5 * V_6 )
{
const struct V_37 * V_38 = V_6 -> V_19 -> V_38 ;
if ( ! V_38 || ! V_38 -> V_39 )
return - V_40 ;
return V_38 -> V_39 ( V_6 -> V_19 , V_6 ) ;
}
int F_45 ( struct V_5 * V_6 )
{
const struct V_37 * V_38 = V_6 -> V_19 -> V_38 ;
if ( ! V_38 || ! V_38 -> V_41 )
return - V_40 ;
return V_38 -> V_41 ( V_6 -> V_19 , V_6 ) ;
}
static T_2 F_46 ( struct V_5 * V_6 ,
struct V_42 * V_43 )
{
const struct V_37 * V_38 = V_6 -> V_19 -> V_38 ;
if ( ! V_38 || ! V_38 -> V_44 )
return - V_40 ;
if ( V_6 -> V_45 & V_46 )
V_43 -> V_47 |= V_48 ;
return V_38 -> V_44 ( V_6 -> V_19 , V_43 ) ;
}
bool F_47 ( T_3 type )
{
switch ( type ) {
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
case V_67 :
return true ;
}
return false ;
}
bool F_48 ( T_3 type )
{
switch ( type ) {
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
case V_81 :
return true ;
}
return false ;
}
int F_49 ( struct V_82 * V_83 ,
const struct V_42 * V_43 )
{
if ( ! V_83 || ! V_43 )
return - V_32 ;
if ( ! F_47 ( V_43 -> type ) &&
! F_48 ( V_43 -> type ) )
return - V_32 ;
if ( V_43 -> V_25 > 3 )
return - V_32 ;
memset ( V_83 , 0 , sizeof( * V_83 ) ) ;
V_83 -> V_84 [ 0 ] = ( ( V_43 -> V_25 & 0x3 ) << 6 ) | ( V_43 -> type & 0x3f ) ;
if ( F_48 ( V_43 -> type ) ) {
V_83 -> V_84 [ 1 ] = ( V_43 -> V_85 >> 0 ) & 0xff ;
V_83 -> V_84 [ 2 ] = ( V_43 -> V_85 >> 8 ) & 0xff ;
V_83 -> V_86 = V_43 -> V_85 ;
V_83 -> V_87 = V_43 -> V_88 ;
} else {
const T_3 * V_89 = V_43 -> V_88 ;
V_83 -> V_84 [ 1 ] = ( V_43 -> V_85 > 0 ) ? V_89 [ 0 ] : 0 ;
V_83 -> V_84 [ 2 ] = ( V_43 -> V_85 > 1 ) ? V_89 [ 1 ] : 0 ;
}
V_83 -> V_90 = sizeof( V_83 -> V_84 ) + V_83 -> V_86 ;
return 0 ;
}
int F_50 ( struct V_5 * V_6 )
{
struct V_42 V_43 = {
. V_25 = V_6 -> V_25 ,
. type = V_56 ,
. V_88 = ( T_3 [ 2 ] ) { 0 , 0 } ,
. V_85 = 2 ,
} ;
return F_46 ( V_6 , & V_43 ) ;
}
int F_51 ( struct V_5 * V_6 )
{
struct V_42 V_43 = {
. V_25 = V_6 -> V_25 ,
. type = V_57 ,
. V_88 = ( T_3 [ 2 ] ) { 0 , 0 } ,
. V_85 = 2 ,
} ;
return F_46 ( V_6 , & V_43 ) ;
}
int F_52 ( struct V_5 * V_6 ,
T_4 V_91 )
{
T_3 V_89 [ 2 ] = { V_91 & 0xff , V_91 >> 8 } ;
struct V_42 V_43 = {
. V_25 = V_6 -> V_25 ,
. type = V_67 ,
. V_85 = sizeof( V_89 ) ,
. V_88 = V_89 ,
} ;
return F_46 ( V_6 , & V_43 ) ;
}
T_2 F_53 ( struct V_5 * V_6 , const void * V_87 ,
T_5 V_90 )
{
struct V_42 V_43 = {
. V_25 = V_6 -> V_25 ,
. V_88 = V_87 ,
. V_85 = V_90
} ;
switch ( V_90 ) {
case 0 :
V_43 . type = V_58 ;
break;
case 1 :
V_43 . type = V_59 ;
break;
case 2 :
V_43 . type = V_60 ;
break;
default:
V_43 . type = V_70 ;
break;
}
return F_46 ( V_6 , & V_43 ) ;
}
T_2 F_54 ( struct V_5 * V_6 , const void * V_92 ,
T_5 V_93 , void * V_13 , T_5 V_90 )
{
struct V_42 V_43 = {
. V_25 = V_6 -> V_25 ,
. V_85 = V_93 ,
. V_88 = V_92 ,
. V_94 = V_90 ,
. V_95 = V_13
} ;
switch ( V_93 ) {
case 0 :
V_43 . type = V_61 ;
break;
case 1 :
V_43 . type = V_62 ;
break;
case 2 :
V_43 . type = V_63 ;
break;
default:
return - V_32 ;
}
return F_46 ( V_6 , & V_43 ) ;
}
T_2 F_55 ( struct V_5 * V_6 ,
const void * V_13 , T_5 V_96 )
{
struct V_42 V_43 = {
. V_25 = V_6 -> V_25 ,
. V_88 = V_13 ,
. V_85 = V_96
} ;
switch ( V_96 ) {
case 0 :
return - V_32 ;
case 1 :
V_43 . type = V_64 ;
break;
case 2 :
V_43 . type = V_65 ;
break;
default:
V_43 . type = V_71 ;
break;
}
return F_46 ( V_6 , & V_43 ) ;
}
T_2 F_56 ( struct V_5 * V_6 , T_3 V_97 ,
const void * V_13 , T_5 V_96 )
{
T_2 V_10 ;
T_5 V_90 ;
T_3 * V_89 ;
if ( V_96 > 0 ) {
V_90 = 1 + V_96 ;
V_89 = F_57 ( V_90 , V_20 ) ;
if ( ! V_89 )
return - V_21 ;
V_89 [ 0 ] = V_97 ;
memcpy ( & V_89 [ 1 ] , V_13 , V_96 ) ;
} else {
V_89 = & V_97 ;
V_90 = 1 ;
}
V_10 = F_55 ( V_6 , V_89 , V_90 ) ;
if ( V_96 > 0 )
F_12 ( V_89 ) ;
return V_10 ;
}
T_2 F_58 ( struct V_5 * V_6 , T_3 V_97 , void * V_13 ,
T_5 V_96 )
{
struct V_42 V_43 = {
. V_25 = V_6 -> V_25 ,
. type = V_66 ,
. V_88 = & V_97 ,
. V_85 = 1 ,
. V_95 = V_13 ,
. V_94 = V_96
} ;
return F_46 ( V_6 , & V_43 ) ;
}
int F_59 ( struct V_5 * V_6 )
{
T_2 V_10 ;
V_10 = F_56 ( V_6 , V_98 , NULL , 0 ) ;
if ( V_10 < 0 )
return V_10 ;
return 0 ;
}
int F_60 ( struct V_5 * V_6 )
{
T_2 V_10 ;
V_10 = F_56 ( V_6 , V_99 , NULL , 0 ) ;
if ( V_10 < 0 )
return V_10 ;
return 0 ;
}
int F_61 ( struct V_5 * V_6 , T_3 * V_100 )
{
T_2 V_10 ;
V_10 = F_58 ( V_6 , V_101 , V_100 ,
sizeof( * V_100 ) ) ;
if ( V_10 <= 0 ) {
if ( V_10 == 0 )
V_10 = - V_102 ;
return V_10 ;
}
return 0 ;
}
int F_62 ( struct V_5 * V_6 , T_3 * V_103 )
{
T_2 V_10 ;
V_10 = F_58 ( V_6 , V_104 , V_103 ,
sizeof( * V_103 ) ) ;
if ( V_10 <= 0 ) {
if ( V_10 == 0 )
V_10 = - V_102 ;
return V_10 ;
}
return 0 ;
}
int F_63 ( struct V_5 * V_6 )
{
T_2 V_10 ;
V_10 = F_56 ( V_6 , V_105 , NULL , 0 ) ;
if ( V_10 < 0 )
return V_10 ;
return 0 ;
}
int F_64 ( struct V_5 * V_6 )
{
T_2 V_10 ;
V_10 = F_56 ( V_6 , V_106 , NULL , 0 ) ;
if ( V_10 < 0 )
return V_10 ;
return 0 ;
}
int F_65 ( struct V_5 * V_6 )
{
T_2 V_10 ;
V_10 = F_56 ( V_6 , V_107 , NULL , 0 ) ;
if ( V_10 < 0 )
return V_10 ;
return 0 ;
}
int F_66 ( struct V_5 * V_6 )
{
T_2 V_10 ;
V_10 = F_56 ( V_6 , V_108 , NULL , 0 ) ;
if ( V_10 < 0 )
return V_10 ;
return 0 ;
}
int F_67 ( struct V_5 * V_6 , T_4 V_109 ,
T_4 V_110 )
{
T_3 V_87 [ 4 ] = { V_109 >> 8 , V_109 & 0xff , V_110 >> 8 , V_110 & 0xff } ;
T_2 V_10 ;
V_10 = F_56 ( V_6 , V_111 , V_87 ,
sizeof( V_87 ) ) ;
if ( V_10 < 0 )
return V_10 ;
return 0 ;
}
int F_68 ( struct V_5 * V_6 , T_4 V_109 ,
T_4 V_110 )
{
T_3 V_87 [ 4 ] = { V_109 >> 8 , V_109 & 0xff , V_110 >> 8 , V_110 & 0xff } ;
T_2 V_10 ;
V_10 = F_56 ( V_6 , V_112 , V_87 ,
sizeof( V_87 ) ) ;
if ( V_10 < 0 )
return V_10 ;
return 0 ;
}
int F_69 ( struct V_5 * V_6 )
{
T_2 V_10 ;
V_10 = F_56 ( V_6 , V_113 , NULL , 0 ) ;
if ( V_10 < 0 )
return V_10 ;
return 0 ;
}
int F_70 ( struct V_5 * V_6 ,
enum V_114 V_100 )
{
T_3 V_91 = V_100 ;
T_2 V_10 ;
V_10 = F_56 ( V_6 , V_115 , & V_91 ,
sizeof( V_91 ) ) ;
if ( V_10 < 0 )
return V_10 ;
return 0 ;
}
int F_71 ( struct V_5 * V_6 , T_3 V_103 )
{
T_2 V_10 ;
V_10 = F_56 ( V_6 , V_116 , & V_103 ,
sizeof( V_103 ) ) ;
if ( V_10 < 0 )
return V_10 ;
return 0 ;
}
int F_72 ( struct V_5 * V_6 , T_4 V_117 )
{
T_3 V_87 [ 3 ] = { V_118 , V_117 >> 8 ,
V_117 & 0xff } ;
T_2 V_10 ;
V_10 = F_53 ( V_6 , V_87 , sizeof( V_87 ) ) ;
if ( V_10 < 0 )
return V_10 ;
return 0 ;
}
int F_73 ( struct V_5 * V_6 ,
T_4 V_119 )
{
T_3 V_87 [ 2 ] = { V_119 & 0xff , V_119 >> 8 } ;
T_2 V_10 ;
V_10 = F_56 ( V_6 , V_120 ,
V_87 , sizeof( V_87 ) ) ;
if ( V_10 < 0 )
return V_10 ;
return 0 ;
}
int F_74 ( struct V_5 * V_6 ,
T_4 * V_119 )
{
T_2 V_10 ;
V_10 = F_58 ( V_6 , V_121 ,
V_119 , sizeof( * V_119 ) ) ;
if ( V_10 <= 0 ) {
if ( V_10 == 0 )
V_10 = - V_102 ;
return V_10 ;
}
return 0 ;
}
static int F_75 ( struct V_1 * V_2 )
{
struct V_122 * V_4 = F_76 ( V_2 -> V_123 ) ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
return V_4 -> V_124 ( V_6 ) ;
}
static int F_77 ( struct V_1 * V_2 )
{
struct V_122 * V_4 = F_76 ( V_2 -> V_123 ) ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
return V_4 -> remove ( V_6 ) ;
}
static void F_78 ( struct V_1 * V_2 )
{
struct V_122 * V_4 = F_76 ( V_2 -> V_123 ) ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
V_4 -> V_125 ( V_6 ) ;
}
int F_79 ( struct V_122 * V_4 ,
struct V_126 * V_127 )
{
V_4 -> V_123 . V_22 = & V_17 ;
V_4 -> V_123 . V_127 = V_127 ;
if ( V_4 -> V_124 )
V_4 -> V_123 . V_124 = F_75 ;
if ( V_4 -> remove )
V_4 -> V_123 . remove = F_77 ;
if ( V_4 -> V_125 )
V_4 -> V_123 . V_125 = F_78 ;
return F_80 ( & V_4 -> V_123 ) ;
}
void F_81 ( struct V_122 * V_4 )
{
F_82 ( & V_4 -> V_123 ) ;
}
static int T_6 F_83 ( void )
{
return F_84 ( & V_17 ) ;
}
