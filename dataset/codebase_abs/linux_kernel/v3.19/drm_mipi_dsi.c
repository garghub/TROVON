static int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
return F_2 ( V_2 , V_4 ) ;
}
static int F_3 ( struct V_1 * V_2 , void * V_5 )
{
return V_2 -> V_6 == V_5 ;
}
struct V_7 * F_4 ( struct V_8 * V_9 )
{
struct V_1 * V_2 ;
V_2 = F_5 ( & V_10 , NULL , V_9 , F_3 ) ;
return V_2 ? F_6 ( V_2 ) : NULL ;
}
static void F_7 ( struct V_1 * V_2 )
{
struct V_7 * V_11 = F_6 ( V_2 ) ;
F_8 ( V_2 -> V_6 ) ;
F_9 ( V_11 ) ;
}
static struct V_7 * F_10 ( struct V_12 * V_13 )
{
struct V_7 * V_11 ;
V_11 = F_11 ( sizeof( * V_11 ) , V_14 ) ;
if ( ! V_11 )
return F_12 ( - V_15 ) ;
V_11 -> V_13 = V_13 ;
V_11 -> V_2 . V_16 = & V_10 ;
V_11 -> V_2 . V_17 = V_13 -> V_2 ;
V_11 -> V_2 . type = & V_18 ;
F_13 ( & V_11 -> V_2 ) ;
return V_11 ;
}
static int F_14 ( struct V_7 * V_11 )
{
struct V_12 * V_13 = V_11 -> V_13 ;
F_15 ( & V_11 -> V_2 , L_1 , F_16 ( V_13 -> V_2 ) , V_11 -> V_19 ) ;
return F_17 ( & V_11 -> V_2 ) ;
}
static struct V_7 *
F_18 ( struct V_12 * V_13 , struct V_8 * V_20 )
{
struct V_7 * V_11 ;
struct V_1 * V_2 = V_13 -> V_2 ;
int V_21 ;
T_1 V_22 ;
V_21 = F_19 ( V_20 , L_2 , & V_22 ) ;
if ( V_21 ) {
F_20 ( V_2 , L_3 ,
V_20 -> V_23 , V_21 ) ;
return F_12 ( - V_24 ) ;
}
if ( V_22 > 3 ) {
F_20 ( V_2 , L_4 ,
V_20 -> V_23 , V_22 ) ;
return F_12 ( - V_24 ) ;
}
V_11 = F_10 ( V_13 ) ;
if ( F_21 ( V_11 ) ) {
F_20 ( V_2 , L_5 ,
V_20 -> V_23 , F_22 ( V_11 ) ) ;
return V_11 ;
}
V_11 -> V_2 . V_6 = F_23 ( V_20 ) ;
V_11 -> V_19 = V_22 ;
V_21 = F_14 ( V_11 ) ;
if ( V_21 ) {
F_20 ( V_2 , L_6 ,
V_20 -> V_23 , V_21 ) ;
F_9 ( V_11 ) ;
return F_12 ( V_21 ) ;
}
return V_11 ;
}
int F_24 ( struct V_12 * V_13 )
{
struct V_8 * V_20 ;
F_25 (host->dev->of_node, node) {
if ( ! F_26 ( V_20 , L_2 , NULL ) )
continue;
F_18 ( V_13 , V_20 ) ;
}
return 0 ;
}
static int F_27 ( struct V_1 * V_2 , void * V_25 )
{
struct V_7 * V_11 = F_6 ( V_2 ) ;
F_28 ( & V_11 -> V_2 ) ;
return 0 ;
}
void F_29 ( struct V_12 * V_13 )
{
F_30 ( V_13 -> V_2 , NULL , F_27 ) ;
}
int F_31 ( struct V_7 * V_11 )
{
const struct V_26 * V_27 = V_11 -> V_13 -> V_27 ;
if ( ! V_27 || ! V_27 -> V_28 )
return - V_29 ;
return V_27 -> V_28 ( V_11 -> V_13 , V_11 ) ;
}
int F_32 ( struct V_7 * V_11 )
{
const struct V_26 * V_27 = V_11 -> V_13 -> V_27 ;
if ( ! V_27 || ! V_27 -> V_30 )
return - V_29 ;
return V_27 -> V_30 ( V_11 -> V_13 , V_11 ) ;
}
static T_2 F_33 ( struct V_7 * V_11 ,
struct V_31 * V_32 )
{
const struct V_26 * V_27 = V_11 -> V_13 -> V_27 ;
if ( ! V_27 || ! V_27 -> V_33 )
return - V_29 ;
if ( V_11 -> V_34 & V_35 )
V_32 -> V_36 |= V_37 ;
return V_27 -> V_33 ( V_11 -> V_13 , V_32 ) ;
}
bool F_34 ( T_3 type )
{
switch ( type ) {
case V_38 :
case V_39 :
case V_40 :
case V_41 :
case V_42 :
case V_43 :
case V_44 :
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
return true ;
}
return false ;
}
bool F_35 ( T_3 type )
{
switch ( type ) {
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
case V_68 :
case V_69 :
case V_70 :
return true ;
}
return false ;
}
int F_36 ( struct V_71 * V_72 ,
const struct V_31 * V_32 )
{
const T_3 * V_73 = V_32 -> V_74 ;
if ( ! V_72 || ! V_32 )
return - V_24 ;
if ( ! F_34 ( V_32 -> type ) &&
! F_35 ( V_32 -> type ) )
return - V_24 ;
if ( V_32 -> V_19 > 3 )
return - V_24 ;
memset ( V_72 , 0 , sizeof( * V_72 ) ) ;
V_72 -> V_75 [ 0 ] = ( ( V_32 -> V_19 & 0x3 ) << 6 ) | ( V_32 -> type & 0x3f ) ;
if ( F_35 ( V_32 -> type ) ) {
V_72 -> V_75 [ 1 ] = ( V_32 -> V_76 >> 0 ) & 0xff ;
V_72 -> V_75 [ 2 ] = ( V_32 -> V_76 >> 8 ) & 0xff ;
V_72 -> V_77 = V_32 -> V_76 ;
V_72 -> V_78 = V_73 ;
} else {
V_72 -> V_75 [ 1 ] = ( V_32 -> V_76 > 0 ) ? V_73 [ 0 ] : 0 ;
V_72 -> V_75 [ 2 ] = ( V_32 -> V_76 > 1 ) ? V_73 [ 1 ] : 0 ;
}
V_72 -> V_79 = sizeof( V_72 -> V_75 ) + V_72 -> V_77 ;
return 0 ;
}
int F_37 ( struct V_7 * V_11 ,
T_4 V_80 )
{
T_3 V_73 [ 2 ] = { V_80 & 0xff , V_80 >> 8 } ;
struct V_31 V_32 = {
. V_19 = V_11 -> V_19 ,
. type = V_56 ,
. V_76 = sizeof( V_73 ) ,
. V_74 = V_73 ,
} ;
return F_33 ( V_11 , & V_32 ) ;
}
T_2 F_38 ( struct V_7 * V_11 , const void * V_78 ,
T_5 V_79 )
{
struct V_31 V_32 = {
. V_19 = V_11 -> V_19 ,
. V_74 = V_78 ,
. V_76 = V_79
} ;
switch ( V_79 ) {
case 0 :
V_32 . type = V_47 ;
break;
case 1 :
V_32 . type = V_48 ;
break;
case 2 :
V_32 . type = V_49 ;
break;
default:
V_32 . type = V_59 ;
break;
}
return F_33 ( V_11 , & V_32 ) ;
}
T_2 F_39 ( struct V_7 * V_11 , const void * V_81 ,
T_5 V_82 , void * V_5 , T_5 V_79 )
{
struct V_31 V_32 = {
. V_19 = V_11 -> V_19 ,
. V_76 = V_82 ,
. V_74 = V_81 ,
. V_83 = V_79 ,
. V_84 = V_5
} ;
switch ( V_82 ) {
case 0 :
V_32 . type = V_50 ;
break;
case 1 :
V_32 . type = V_51 ;
break;
case 2 :
V_32 . type = V_52 ;
break;
default:
return - V_24 ;
}
return F_33 ( V_11 , & V_32 ) ;
}
T_2 F_40 ( struct V_7 * V_11 ,
const void * V_5 , T_5 V_85 )
{
struct V_31 V_32 = {
. V_19 = V_11 -> V_19 ,
. V_74 = V_5 ,
. V_76 = V_85
} ;
switch ( V_85 ) {
case 0 :
return - V_24 ;
case 1 :
V_32 . type = V_53 ;
break;
case 2 :
V_32 . type = V_54 ;
break;
default:
V_32 . type = V_60 ;
break;
}
return F_33 ( V_11 , & V_32 ) ;
}
T_2 F_41 ( struct V_7 * V_11 , T_3 V_86 ,
const void * V_5 , T_5 V_85 )
{
T_2 V_87 ;
T_5 V_79 ;
T_3 * V_73 ;
if ( V_85 > 0 ) {
V_79 = 1 + V_85 ;
V_73 = F_42 ( V_79 , V_14 ) ;
if ( ! V_73 )
return - V_15 ;
V_73 [ 0 ] = V_86 ;
memcpy ( & V_73 [ 1 ] , V_5 , V_85 ) ;
} else {
V_73 = & V_86 ;
V_79 = 1 ;
}
V_87 = F_40 ( V_11 , V_73 , V_79 ) ;
if ( V_85 > 0 )
F_9 ( V_73 ) ;
return V_87 ;
}
T_2 F_43 ( struct V_7 * V_11 , T_3 V_86 , void * V_5 ,
T_5 V_85 )
{
struct V_31 V_32 = {
. V_19 = V_11 -> V_19 ,
. type = V_55 ,
. V_74 = & V_86 ,
. V_76 = 1 ,
. V_84 = V_5 ,
. V_83 = V_85
} ;
return F_33 ( V_11 , & V_32 ) ;
}
int F_44 ( struct V_7 * V_11 )
{
T_2 V_87 ;
V_87 = F_41 ( V_11 , V_88 , NULL , 0 ) ;
if ( V_87 < 0 )
return V_87 ;
return 0 ;
}
int F_45 ( struct V_7 * V_11 )
{
T_2 V_87 ;
V_87 = F_41 ( V_11 , V_89 , NULL , 0 ) ;
if ( V_87 < 0 )
return V_87 ;
return 0 ;
}
int F_46 ( struct V_7 * V_11 , T_3 * V_90 )
{
T_2 V_87 ;
V_87 = F_43 ( V_11 , V_91 , V_90 ,
sizeof( * V_90 ) ) ;
if ( V_87 <= 0 ) {
if ( V_87 == 0 )
V_87 = - V_92 ;
return V_87 ;
}
return 0 ;
}
int F_47 ( struct V_7 * V_11 , T_3 * V_93 )
{
T_2 V_87 ;
V_87 = F_43 ( V_11 , V_94 , V_93 ,
sizeof( * V_93 ) ) ;
if ( V_87 <= 0 ) {
if ( V_87 == 0 )
V_87 = - V_92 ;
return V_87 ;
}
return 0 ;
}
int F_48 ( struct V_7 * V_11 )
{
T_2 V_87 ;
V_87 = F_41 ( V_11 , V_95 , NULL , 0 ) ;
if ( V_87 < 0 )
return V_87 ;
return 0 ;
}
int F_49 ( struct V_7 * V_11 )
{
T_2 V_87 ;
V_87 = F_41 ( V_11 , V_96 , NULL , 0 ) ;
if ( V_87 < 0 )
return V_87 ;
return 0 ;
}
int F_50 ( struct V_7 * V_11 )
{
T_2 V_87 ;
V_87 = F_41 ( V_11 , V_97 , NULL , 0 ) ;
if ( V_87 < 0 )
return V_87 ;
return 0 ;
}
int F_51 ( struct V_7 * V_11 )
{
T_2 V_87 ;
V_87 = F_41 ( V_11 , V_98 , NULL , 0 ) ;
if ( V_87 < 0 )
return V_87 ;
return 0 ;
}
int F_52 ( struct V_7 * V_11 , T_4 V_99 ,
T_4 V_100 )
{
T_3 V_78 [ 4 ] = { V_99 >> 8 , V_99 & 0xff , V_100 >> 8 , V_100 & 0xff } ;
T_2 V_87 ;
V_87 = F_41 ( V_11 , V_101 , V_78 ,
sizeof( V_78 ) ) ;
if ( V_87 < 0 )
return V_87 ;
return 0 ;
}
int F_53 ( struct V_7 * V_11 , T_4 V_99 ,
T_4 V_100 )
{
T_3 V_78 [ 4 ] = { V_99 >> 8 , V_99 & 0xff , V_100 >> 8 , V_100 & 0xff } ;
T_2 V_87 ;
V_87 = F_41 ( V_11 , V_102 , V_78 ,
sizeof( V_78 ) ) ;
if ( V_87 < 0 )
return V_87 ;
return 0 ;
}
int F_54 ( struct V_7 * V_11 )
{
T_2 V_87 ;
V_87 = F_41 ( V_11 , V_103 , NULL , 0 ) ;
if ( V_87 < 0 )
return V_87 ;
return 0 ;
}
int F_55 ( struct V_7 * V_11 ,
enum V_104 V_90 )
{
T_3 V_80 = V_90 ;
T_2 V_87 ;
V_87 = F_41 ( V_11 , V_105 , & V_80 ,
sizeof( V_80 ) ) ;
if ( V_87 < 0 )
return V_87 ;
return 0 ;
}
int F_56 ( struct V_7 * V_11 , T_3 V_93 )
{
T_2 V_87 ;
V_87 = F_41 ( V_11 , V_106 , & V_93 ,
sizeof( V_93 ) ) ;
if ( V_87 < 0 )
return V_87 ;
return 0 ;
}
static int F_57 ( struct V_1 * V_2 )
{
struct V_107 * V_4 = F_58 ( V_2 -> V_108 ) ;
struct V_7 * V_11 = F_6 ( V_2 ) ;
return V_4 -> V_109 ( V_11 ) ;
}
static int F_59 ( struct V_1 * V_2 )
{
struct V_107 * V_4 = F_58 ( V_2 -> V_108 ) ;
struct V_7 * V_11 = F_6 ( V_2 ) ;
return V_4 -> remove ( V_11 ) ;
}
static void F_60 ( struct V_1 * V_2 )
{
struct V_107 * V_4 = F_58 ( V_2 -> V_108 ) ;
struct V_7 * V_11 = F_6 ( V_2 ) ;
V_4 -> V_110 ( V_11 ) ;
}
int F_61 ( struct V_107 * V_4 ,
struct V_111 * V_112 )
{
V_4 -> V_108 . V_16 = & V_10 ;
V_4 -> V_108 . V_112 = V_112 ;
if ( V_4 -> V_109 )
V_4 -> V_108 . V_109 = F_57 ;
if ( V_4 -> remove )
V_4 -> V_108 . remove = F_59 ;
if ( V_4 -> V_110 )
V_4 -> V_108 . V_110 = F_60 ;
return F_62 ( & V_4 -> V_108 ) ;
}
void F_63 ( struct V_107 * V_4 )
{
F_64 ( & V_4 -> V_108 ) ;
}
static int T_6 F_65 ( void )
{
return F_66 ( & V_10 ) ;
}
