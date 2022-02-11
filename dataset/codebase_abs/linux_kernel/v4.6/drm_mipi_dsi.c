static int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
if ( F_3 ( V_2 , V_4 ) )
return 1 ;
if ( ! strcmp ( V_6 -> V_7 , V_4 -> V_7 ) )
return 1 ;
return 0 ;
}
static int F_4 ( struct V_1 * V_2 , void * V_8 )
{
return V_2 -> V_9 == V_8 ;
}
struct V_5 * F_5 ( struct V_10 * V_11 )
{
struct V_1 * V_2 ;
V_2 = F_6 ( & V_12 , NULL , V_11 , F_4 ) ;
return V_2 ? F_2 ( V_2 ) : NULL ;
}
static void F_7 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
F_8 ( V_2 -> V_9 ) ;
F_9 ( V_6 ) ;
}
static struct V_5 * F_10 ( struct V_13 * V_14 )
{
struct V_5 * V_6 ;
V_6 = F_11 ( sizeof( * V_6 ) , V_15 ) ;
if ( ! V_6 )
return F_12 ( - V_16 ) ;
V_6 -> V_14 = V_14 ;
V_6 -> V_2 . V_17 = & V_12 ;
V_6 -> V_2 . V_18 = V_14 -> V_2 ;
V_6 -> V_2 . type = & V_19 ;
F_13 ( & V_6 -> V_2 ) ;
return V_6 ;
}
static int F_14 ( struct V_5 * V_6 )
{
struct V_13 * V_14 = V_6 -> V_14 ;
F_15 ( & V_6 -> V_2 , L_1 , F_16 ( V_14 -> V_2 ) , V_6 -> V_20 ) ;
return F_17 ( & V_6 -> V_2 ) ;
}
static struct V_5 *
F_18 ( struct V_13 * V_14 , struct V_10 * V_21 )
{
struct V_1 * V_2 = V_14 -> V_2 ;
struct V_22 V_23 = { } ;
int V_24 ;
T_1 V_25 ;
if ( F_19 ( V_21 , V_23 . type , sizeof( V_23 . type ) ) < 0 ) {
F_20 ( V_2 , L_2 , V_21 -> V_26 ) ;
return F_12 ( - V_27 ) ;
}
V_24 = F_21 ( V_21 , L_3 , & V_25 ) ;
if ( V_24 ) {
F_20 ( V_2 , L_4 ,
V_21 -> V_26 , V_24 ) ;
return F_12 ( - V_27 ) ;
}
V_23 . V_20 = V_25 ;
V_23 . V_21 = F_22 ( V_21 ) ;
return F_23 ( V_14 , & V_23 ) ;
}
static struct V_5 *
F_18 ( struct V_13 * V_14 , struct V_10 * V_21 )
{
return F_12 ( - V_28 ) ;
}
struct V_5 *
F_23 ( struct V_13 * V_14 ,
const struct V_22 * V_23 )
{
struct V_5 * V_6 ;
struct V_1 * V_2 = V_14 -> V_2 ;
int V_24 ;
if ( ! V_23 ) {
F_20 ( V_2 , L_5 ) ;
return F_12 ( - V_27 ) ;
}
if ( V_23 -> V_20 > 3 ) {
F_20 ( V_2 , L_6 , V_23 -> V_20 ) ;
return F_12 ( - V_27 ) ;
}
V_6 = F_10 ( V_14 ) ;
if ( F_24 ( V_6 ) ) {
F_20 ( V_2 , L_7 ,
F_25 ( V_6 ) ) ;
return V_6 ;
}
V_6 -> V_2 . V_9 = V_23 -> V_21 ;
V_6 -> V_20 = V_23 -> V_20 ;
F_26 ( V_6 -> V_7 , V_23 -> type , sizeof( V_6 -> V_7 ) ) ;
V_24 = F_14 ( V_6 ) ;
if ( V_24 ) {
F_20 ( V_2 , L_8 , V_24 ) ;
F_9 ( V_6 ) ;
return F_12 ( V_24 ) ;
}
return V_6 ;
}
void F_27 ( struct V_5 * V_6 )
{
F_28 ( & V_6 -> V_2 ) ;
}
struct V_13 * F_29 ( struct V_10 * V_21 )
{
struct V_13 * V_14 ;
F_30 ( & V_29 ) ;
F_31 (host, &host_list, list) {
if ( V_14 -> V_2 -> V_9 == V_21 ) {
F_32 ( & V_29 ) ;
return V_14 ;
}
}
F_32 ( & V_29 ) ;
return NULL ;
}
int F_33 ( struct V_13 * V_14 )
{
struct V_10 * V_21 ;
F_34 (host->dev->of_node, node) {
if ( ! F_35 ( V_21 , L_3 , NULL ) )
continue;
F_18 ( V_14 , V_21 ) ;
}
F_30 ( & V_29 ) ;
F_36 ( & V_14 -> V_30 , & V_31 ) ;
F_32 ( & V_29 ) ;
return 0 ;
}
static int F_37 ( struct V_1 * V_2 , void * V_32 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
F_27 ( V_6 ) ;
return 0 ;
}
void F_38 ( struct V_13 * V_14 )
{
F_39 ( V_14 -> V_2 , NULL , F_37 ) ;
F_30 ( & V_29 ) ;
F_40 ( & V_14 -> V_30 ) ;
F_32 ( & V_29 ) ;
}
int F_41 ( struct V_5 * V_6 )
{
const struct V_33 * V_34 = V_6 -> V_14 -> V_34 ;
if ( ! V_34 || ! V_34 -> V_35 )
return - V_36 ;
return V_34 -> V_35 ( V_6 -> V_14 , V_6 ) ;
}
int F_42 ( struct V_5 * V_6 )
{
const struct V_33 * V_34 = V_6 -> V_14 -> V_34 ;
if ( ! V_34 || ! V_34 -> V_37 )
return - V_36 ;
return V_34 -> V_37 ( V_6 -> V_14 , V_6 ) ;
}
static T_2 F_43 ( struct V_5 * V_6 ,
struct V_38 * V_39 )
{
const struct V_33 * V_34 = V_6 -> V_14 -> V_34 ;
if ( ! V_34 || ! V_34 -> V_40 )
return - V_36 ;
if ( V_6 -> V_41 & V_42 )
V_39 -> V_43 |= V_44 ;
return V_34 -> V_40 ( V_6 -> V_14 , V_39 ) ;
}
bool F_44 ( T_3 type )
{
switch ( type ) {
case V_45 :
case V_46 :
case V_47 :
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
return true ;
}
return false ;
}
bool F_45 ( T_3 type )
{
switch ( type ) {
case V_64 :
case V_65 :
case V_66 :
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
return true ;
}
return false ;
}
int F_46 ( struct V_78 * V_79 ,
const struct V_38 * V_39 )
{
if ( ! V_79 || ! V_39 )
return - V_27 ;
if ( ! F_44 ( V_39 -> type ) &&
! F_45 ( V_39 -> type ) )
return - V_27 ;
if ( V_39 -> V_20 > 3 )
return - V_27 ;
memset ( V_79 , 0 , sizeof( * V_79 ) ) ;
V_79 -> V_80 [ 0 ] = ( ( V_39 -> V_20 & 0x3 ) << 6 ) | ( V_39 -> type & 0x3f ) ;
if ( F_45 ( V_39 -> type ) ) {
V_79 -> V_80 [ 1 ] = ( V_39 -> V_81 >> 0 ) & 0xff ;
V_79 -> V_80 [ 2 ] = ( V_39 -> V_81 >> 8 ) & 0xff ;
V_79 -> V_82 = V_39 -> V_81 ;
V_79 -> V_83 = V_39 -> V_84 ;
} else {
const T_3 * V_85 = V_39 -> V_84 ;
V_79 -> V_80 [ 1 ] = ( V_39 -> V_81 > 0 ) ? V_85 [ 0 ] : 0 ;
V_79 -> V_80 [ 2 ] = ( V_39 -> V_81 > 1 ) ? V_85 [ 1 ] : 0 ;
}
V_79 -> V_86 = sizeof( V_79 -> V_80 ) + V_79 -> V_82 ;
return 0 ;
}
int F_47 ( struct V_5 * V_6 )
{
struct V_38 V_39 = {
. V_20 = V_6 -> V_20 ,
. type = V_52 ,
. V_84 = ( T_3 [ 2 ] ) { 0 , 0 } ,
. V_81 = 2 ,
} ;
return F_43 ( V_6 , & V_39 ) ;
}
int F_48 ( struct V_5 * V_6 )
{
struct V_38 V_39 = {
. V_20 = V_6 -> V_20 ,
. type = V_53 ,
. V_84 = ( T_3 [ 2 ] ) { 0 , 0 } ,
. V_81 = 2 ,
} ;
return F_43 ( V_6 , & V_39 ) ;
}
int F_49 ( struct V_5 * V_6 ,
T_4 V_87 )
{
T_3 V_85 [ 2 ] = { V_87 & 0xff , V_87 >> 8 } ;
struct V_38 V_39 = {
. V_20 = V_6 -> V_20 ,
. type = V_63 ,
. V_81 = sizeof( V_85 ) ,
. V_84 = V_85 ,
} ;
return F_43 ( V_6 , & V_39 ) ;
}
T_2 F_50 ( struct V_5 * V_6 , const void * V_83 ,
T_5 V_86 )
{
struct V_38 V_39 = {
. V_20 = V_6 -> V_20 ,
. V_84 = V_83 ,
. V_81 = V_86
} ;
switch ( V_86 ) {
case 0 :
V_39 . type = V_54 ;
break;
case 1 :
V_39 . type = V_55 ;
break;
case 2 :
V_39 . type = V_56 ;
break;
default:
V_39 . type = V_66 ;
break;
}
return F_43 ( V_6 , & V_39 ) ;
}
T_2 F_51 ( struct V_5 * V_6 , const void * V_88 ,
T_5 V_89 , void * V_8 , T_5 V_86 )
{
struct V_38 V_39 = {
. V_20 = V_6 -> V_20 ,
. V_81 = V_89 ,
. V_84 = V_88 ,
. V_90 = V_86 ,
. V_91 = V_8
} ;
switch ( V_89 ) {
case 0 :
V_39 . type = V_57 ;
break;
case 1 :
V_39 . type = V_58 ;
break;
case 2 :
V_39 . type = V_59 ;
break;
default:
return - V_27 ;
}
return F_43 ( V_6 , & V_39 ) ;
}
T_2 F_52 ( struct V_5 * V_6 ,
const void * V_8 , T_5 V_92 )
{
struct V_38 V_39 = {
. V_20 = V_6 -> V_20 ,
. V_84 = V_8 ,
. V_81 = V_92
} ;
switch ( V_92 ) {
case 0 :
return - V_27 ;
case 1 :
V_39 . type = V_60 ;
break;
case 2 :
V_39 . type = V_61 ;
break;
default:
V_39 . type = V_67 ;
break;
}
return F_43 ( V_6 , & V_39 ) ;
}
T_2 F_53 ( struct V_5 * V_6 , T_3 V_93 ,
const void * V_8 , T_5 V_92 )
{
T_2 V_94 ;
T_5 V_86 ;
T_3 * V_85 ;
if ( V_92 > 0 ) {
V_86 = 1 + V_92 ;
V_85 = F_54 ( V_86 , V_15 ) ;
if ( ! V_85 )
return - V_16 ;
V_85 [ 0 ] = V_93 ;
memcpy ( & V_85 [ 1 ] , V_8 , V_92 ) ;
} else {
V_85 = & V_93 ;
V_86 = 1 ;
}
V_94 = F_52 ( V_6 , V_85 , V_86 ) ;
if ( V_92 > 0 )
F_9 ( V_85 ) ;
return V_94 ;
}
T_2 F_55 ( struct V_5 * V_6 , T_3 V_93 , void * V_8 ,
T_5 V_92 )
{
struct V_38 V_39 = {
. V_20 = V_6 -> V_20 ,
. type = V_62 ,
. V_84 = & V_93 ,
. V_81 = 1 ,
. V_91 = V_8 ,
. V_90 = V_92
} ;
return F_43 ( V_6 , & V_39 ) ;
}
int F_56 ( struct V_5 * V_6 )
{
T_2 V_94 ;
V_94 = F_53 ( V_6 , V_95 , NULL , 0 ) ;
if ( V_94 < 0 )
return V_94 ;
return 0 ;
}
int F_57 ( struct V_5 * V_6 )
{
T_2 V_94 ;
V_94 = F_53 ( V_6 , V_96 , NULL , 0 ) ;
if ( V_94 < 0 )
return V_94 ;
return 0 ;
}
int F_58 ( struct V_5 * V_6 , T_3 * V_97 )
{
T_2 V_94 ;
V_94 = F_55 ( V_6 , V_98 , V_97 ,
sizeof( * V_97 ) ) ;
if ( V_94 <= 0 ) {
if ( V_94 == 0 )
V_94 = - V_99 ;
return V_94 ;
}
return 0 ;
}
int F_59 ( struct V_5 * V_6 , T_3 * V_100 )
{
T_2 V_94 ;
V_94 = F_55 ( V_6 , V_101 , V_100 ,
sizeof( * V_100 ) ) ;
if ( V_94 <= 0 ) {
if ( V_94 == 0 )
V_94 = - V_99 ;
return V_94 ;
}
return 0 ;
}
int F_60 ( struct V_5 * V_6 )
{
T_2 V_94 ;
V_94 = F_53 ( V_6 , V_102 , NULL , 0 ) ;
if ( V_94 < 0 )
return V_94 ;
return 0 ;
}
int F_61 ( struct V_5 * V_6 )
{
T_2 V_94 ;
V_94 = F_53 ( V_6 , V_103 , NULL , 0 ) ;
if ( V_94 < 0 )
return V_94 ;
return 0 ;
}
int F_62 ( struct V_5 * V_6 )
{
T_2 V_94 ;
V_94 = F_53 ( V_6 , V_104 , NULL , 0 ) ;
if ( V_94 < 0 )
return V_94 ;
return 0 ;
}
int F_63 ( struct V_5 * V_6 )
{
T_2 V_94 ;
V_94 = F_53 ( V_6 , V_105 , NULL , 0 ) ;
if ( V_94 < 0 )
return V_94 ;
return 0 ;
}
int F_64 ( struct V_5 * V_6 , T_4 V_106 ,
T_4 V_107 )
{
T_3 V_83 [ 4 ] = { V_106 >> 8 , V_106 & 0xff , V_107 >> 8 , V_107 & 0xff } ;
T_2 V_94 ;
V_94 = F_53 ( V_6 , V_108 , V_83 ,
sizeof( V_83 ) ) ;
if ( V_94 < 0 )
return V_94 ;
return 0 ;
}
int F_65 ( struct V_5 * V_6 , T_4 V_106 ,
T_4 V_107 )
{
T_3 V_83 [ 4 ] = { V_106 >> 8 , V_106 & 0xff , V_107 >> 8 , V_107 & 0xff } ;
T_2 V_94 ;
V_94 = F_53 ( V_6 , V_109 , V_83 ,
sizeof( V_83 ) ) ;
if ( V_94 < 0 )
return V_94 ;
return 0 ;
}
int F_66 ( struct V_5 * V_6 )
{
T_2 V_94 ;
V_94 = F_53 ( V_6 , V_110 , NULL , 0 ) ;
if ( V_94 < 0 )
return V_94 ;
return 0 ;
}
int F_67 ( struct V_5 * V_6 ,
enum V_111 V_97 )
{
T_3 V_87 = V_97 ;
T_2 V_94 ;
V_94 = F_53 ( V_6 , V_112 , & V_87 ,
sizeof( V_87 ) ) ;
if ( V_94 < 0 )
return V_94 ;
return 0 ;
}
int F_68 ( struct V_5 * V_6 , T_3 V_100 )
{
T_2 V_94 ;
V_94 = F_53 ( V_6 , V_113 , & V_100 ,
sizeof( V_100 ) ) ;
if ( V_94 < 0 )
return V_94 ;
return 0 ;
}
static int F_69 ( struct V_1 * V_2 )
{
struct V_114 * V_4 = F_70 ( V_2 -> V_115 ) ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
return V_4 -> V_116 ( V_6 ) ;
}
static int F_71 ( struct V_1 * V_2 )
{
struct V_114 * V_4 = F_70 ( V_2 -> V_115 ) ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
return V_4 -> remove ( V_6 ) ;
}
static void F_72 ( struct V_1 * V_2 )
{
struct V_114 * V_4 = F_70 ( V_2 -> V_115 ) ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
V_4 -> V_117 ( V_6 ) ;
}
int F_73 ( struct V_114 * V_4 ,
struct V_118 * V_119 )
{
V_4 -> V_115 . V_17 = & V_12 ;
V_4 -> V_115 . V_119 = V_119 ;
if ( V_4 -> V_116 )
V_4 -> V_115 . V_116 = F_69 ;
if ( V_4 -> remove )
V_4 -> V_115 . remove = F_71 ;
if ( V_4 -> V_117 )
V_4 -> V_115 . V_117 = F_72 ;
return F_74 ( & V_4 -> V_115 ) ;
}
void F_75 ( struct V_114 * V_4 )
{
F_76 ( & V_4 -> V_115 ) ;
}
static int T_6 F_77 ( void )
{
return F_78 ( & V_12 ) ;
}
