static T_1 F_1 ( struct V_1 * V_1 , char T_2 * V_2 ,
T_3 V_3 , T_4 * V_4 )
{
T_5 V_5 ;
int V_6 ;
struct V_7 * V_7 ;
V_7 = F_2 ( V_1 ) ;
if ( ! V_8 ) {
F_3 ( L_1 ) ;
return - V_9 ;
}
V_6 = F_4 ( V_7 , & V_5 ) ;
if ( V_6 < 0 ) {
F_3 ( L_2 ) ;
return V_6 ;
}
if ( V_5 == V_10 ) {
V_6 = F_5 ( V_7 , V_11 ) ;
if ( V_6 < 0 ) {
F_3 ( L_3 ) ;
return V_6 ;
}
}
return F_6 ( V_7 , V_1 , V_2 , V_3 ) ;
}
static T_1 F_7 ( struct V_1 * V_1 , const char T_2 * V_2 ,
T_3 V_3 , T_4 * V_4 )
{
struct V_12 V_13 ;
int V_6 ;
struct V_7 * V_7 ;
V_6 = F_8 ( & V_13 , V_2 , sizeof( V_13 ) ) ;
V_13 . V_14 [ sizeof( V_13 . V_14 ) - 1 ] = '\0' ;
F_9 ( L_4 ,
V_6 , V_13 . V_15 , V_13 . V_14 , V_13 . V_16 ) ;
if ( V_6 )
return - V_17 ;
V_7 = F_2 ( V_1 ) ;
F_10 ( V_7 , V_13 . V_14 , V_13 . V_15 ) ;
F_11 ( V_7 , V_13 . V_16 ) ;
return sizeof( V_13 ) ;
}
static T_6 F_12 ( struct V_1 * V_1 , struct V_18 * V_19 )
{
int V_6 ;
struct V_7 * V_7 ;
V_7 = F_2 ( V_1 ) ;
V_6 = F_13 ( V_7 , V_1 , V_19 ) ;
if ( V_6 < 0 )
return V_20 | V_21 ;
return 0 ;
}
static int F_14 ( struct V_1 * V_1 )
{
int V_6 ;
struct V_7 * V_7 = NULL ;
if ( V_8 ) {
F_3 ( L_5 ) ;
return - V_22 ;
}
V_7 = F_2 ( V_1 ) ;
V_6 = F_15 ( V_7 ) ;
if ( V_6 < 0 ) {
F_3 ( L_6 ) ;
return V_6 ;
}
F_9 ( L_7 ) ;
V_6 = F_16 ( V_7 , V_23 ) ;
if ( V_6 < 0 ) {
F_3 ( L_8 ) ;
return V_6 ;
}
V_8 = 1 ;
return V_6 ;
}
static int F_17 ( struct V_1 * V_1 )
{
int V_6 ;
struct V_7 * V_7 ;
V_7 = F_2 ( V_1 ) ;
if ( ! V_8 ) {
F_9 ( L_9 ) ;
return 0 ;
}
V_6 = F_16 ( V_7 , V_24 ) ;
if ( V_6 < 0 ) {
F_3 ( L_10 ) ;
return V_6 ;
}
V_6 = F_18 ( V_7 ) ;
if ( V_6 < 0 ) {
F_3 ( L_11 ) ;
return V_6 ;
}
V_8 = 0 ;
return V_6 ;
}
static int F_19 ( struct V_1 * V_1 , void * V_25 ,
struct V_26 * V_27 )
{
F_20 ( V_27 -> V_28 , V_29 , sizeof( V_27 -> V_28 ) ) ;
F_20 ( V_27 -> V_30 , V_31 ,
sizeof( V_27 -> V_30 ) ) ;
sprintf ( V_27 -> V_32 , L_12 ) ;
V_27 -> V_33 = V_34 | V_35 |
V_36 | V_37 |
V_38 | V_39 |
V_40 ;
return 0 ;
}
static int F_21 ( struct V_41 * V_42 )
{
struct V_7 * V_7 = F_22 ( V_42 -> V_43 ,
struct V_7 , V_44 ) ;
switch ( V_42 -> V_45 ) {
case V_46 :
V_42 -> V_47 = F_23 ( V_7 ) ;
break;
default:
F_24 ( L_13 , V_48 , V_42 -> V_45 ) ;
break;
}
return 0 ;
}
static int F_25 ( struct V_41 * V_42 )
{
struct V_7 * V_7 = F_22 ( V_42 -> V_43 ,
struct V_7 , V_44 ) ;
switch ( V_42 -> V_45 ) {
case V_49 :
return F_26 ( V_7 , ( V_50 ) V_42 -> V_47 ) ;
case V_51 :
return F_27 ( V_7 , ( T_5 ) V_42 -> V_47 ) ;
case V_52 :
return F_28 ( V_7 , ( T_5 ) V_42 -> V_47 ) ;
case V_53 :
return F_29 ( V_7 , ( T_5 ) V_42 -> V_47 ) ;
default:
return - V_54 ;
}
}
static int F_30 ( struct V_1 * V_1 , void * V_25 ,
struct V_55 * V_56 )
{
memset ( V_56 , 0 , sizeof( * V_56 ) ) ;
strcpy ( V_56 -> V_57 , L_14 ) ;
V_56 -> V_27 = V_58 ;
return 0 ;
}
static int F_31 ( struct V_1 * V_1 , void * V_25 ,
struct V_55 * V_56 )
{
if ( V_56 -> V_59 != 0 )
return - V_54 ;
return 0 ;
}
static int F_32 ( struct V_1 * V_1 , void * V_25 ,
struct V_60 * V_61 )
{
struct V_7 * V_7 = F_2 ( V_1 ) ;
T_6 V_62 ;
T_6 V_63 ;
V_50 V_64 ;
V_50 V_65 ;
int V_6 ;
if ( V_61 -> V_59 != 0 )
return - V_54 ;
if ( V_7 -> V_66 != V_23 )
return - V_67 ;
V_6 = F_33 ( V_7 , & V_62 , & V_63 ) ;
if ( V_6 != 0 )
return V_6 ;
V_6 = F_34 ( V_7 , & V_64 ) ;
if ( V_6 != 0 )
return V_6 ;
V_6 = F_35 ( V_7 , & V_65 ) ;
if ( V_6 != 0 )
return V_6 ;
strcpy ( V_61 -> V_57 , L_15 ) ;
V_61 -> type = V_68 ;
V_61 -> V_69 = V_62 * 16 ;
V_61 -> V_70 = V_63 * 16 ;
V_61 -> V_71 = V_72 | V_73 |
( ( V_7 -> V_74 . V_13 . V_75 == V_11 ) ? V_76 : 0 ) ;
V_61 -> V_27 = V_77 | V_78 |
V_79 ;
V_61 -> V_80 = ( V_64 ?
V_81 : V_82 ) ;
V_65 += 128 ;
V_61 -> signal = V_65 * 257 ;
V_61 -> V_83 = 0 ;
return V_6 ;
}
static int F_36 ( struct V_1 * V_1 , void * V_25 ,
struct V_60 * V_61 )
{
struct V_7 * V_7 = F_2 ( V_1 ) ;
V_50 V_84 ;
T_5 V_5 ;
int V_6 ;
if ( V_61 -> V_59 != 0 )
return - V_54 ;
V_84 = ( V_61 -> V_80 == V_82 ) ?
V_85 : V_86 ;
V_5 = ( V_61 -> V_71 & V_76 ) ?
V_11 : V_10 ;
if ( V_7 -> V_66 != V_23 ) {
V_6 = F_16 ( V_7 , V_23 ) ;
if ( V_6 < 0 ) {
F_3 ( L_16 ) ;
return V_6 ;
}
}
V_6 = F_37 ( V_7 , V_84 ) ;
if ( V_6 < 0 ) {
F_3 ( L_17 ) ;
return V_6 ;
}
V_6 = F_5 ( V_7 , V_5 ) ;
if ( V_6 < 0 )
F_3 ( L_18 ) ;
return V_6 ;
}
static int F_38 ( struct V_1 * V_1 , void * V_25 ,
struct V_87 * V_88 )
{
struct V_7 * V_7 = F_2 ( V_1 ) ;
int V_6 ;
V_6 = F_39 ( V_7 , & V_88 -> V_89 ) ;
if ( V_6 < 0 ) {
F_3 ( L_19 ) ;
return V_6 ;
}
V_88 -> V_89 = ( T_6 ) V_88 -> V_89 * 16 ;
return 0 ;
}
static int F_40 ( struct V_1 * V_1 , void * V_25 ,
struct V_87 * V_88 )
{
struct V_7 * V_7 = F_2 ( V_1 ) ;
V_88 -> V_89 = ( T_6 ) ( V_88 -> V_89 / 16 ) ;
return F_41 ( V_7 , V_88 -> V_89 ) ;
}
static int F_42 ( struct V_1 * V_1 , void * V_25 ,
struct V_90 * V_91 )
{
struct V_7 * V_7 = F_2 ( V_1 ) ;
int V_6 ;
if ( V_7 -> V_66 != V_23 ) {
V_6 = F_16 ( V_7 , V_23 ) ;
if ( V_6 != 0 ) {
F_3 ( L_16 ) ;
return V_6 ;
}
}
V_6 = F_43 ( V_7 , V_91 -> V_92 , V_91 -> V_93 ,
V_91 -> V_94 ) ;
if ( V_6 < 0 )
F_3 ( L_20 , V_6 ) ;
return V_6 ;
}
static int F_44 ( struct V_1 * V_1 , void * V_25 ,
struct V_95 * V_96 )
{
struct V_7 * V_7 = F_2 ( V_1 ) ;
if ( V_96 -> V_59 != 0 )
return - V_54 ;
if ( V_7 -> V_66 != V_97 )
return - V_67 ;
V_96 -> V_98 = ( ( V_7 -> V_99 . V_84 == V_85 ) ?
V_73 : V_72 ) |
( ( V_7 -> V_99 . V_13 . V_75 == V_11 ) ?
V_76 : 0 ) ;
V_96 -> V_27 = V_77 | V_78 |
V_79 ;
return 0 ;
}
static int F_45 ( struct V_1 * V_1 , void * V_25 ,
struct V_95 * V_96 )
{
struct V_7 * V_7 = F_2 ( V_1 ) ;
T_5 V_5 ;
V_50 V_84 ;
int V_6 ;
if ( V_96 -> V_59 != 0 )
return - V_54 ;
if ( V_7 -> V_66 != V_97 ) {
V_6 = F_16 ( V_7 , V_97 ) ;
if ( V_6 != 0 ) {
F_3 ( L_21 ) ;
return V_6 ;
}
}
V_84 = ( V_96 -> V_98 & V_73 ) ?
V_85 : V_86 ;
V_5 = ( V_96 -> V_98 & V_76 ) ?
V_11 : V_10 ;
V_6 = F_46 ( V_7 , V_84 ) ;
if ( V_6 < 0 ) {
F_3 ( L_22 ) ;
return V_6 ;
}
V_6 = F_47 ( V_7 , V_5 ) ;
if ( V_6 < 0 )
F_3 ( L_23 ) ;
return V_6 ;
}
int F_48 ( struct V_7 * V_7 , int V_100 )
{
struct V_41 * V_42 ;
int V_6 ;
F_49 ( & V_7 -> V_101 ) ;
V_102 = F_50 () ;
if ( NULL == V_102 ) {
F_3 ( L_24 ) ;
return - V_103 ;
}
memcpy ( V_102 , & V_104 , sizeof( V_104 ) ) ;
F_51 ( V_102 , V_7 ) ;
V_102 -> V_105 = & V_7 -> V_101 ;
F_52 ( V_106 , & V_102 -> V_107 ) ;
if ( F_53 ( V_102 , V_108 , V_100 ) ) {
F_54 ( V_102 ) ;
F_3 ( L_25 ) ;
return - V_103 ;
}
V_7 -> V_109 = V_102 ;
V_7 -> V_109 -> V_44 = & V_7 -> V_44 ;
V_6 = F_55 ( & V_7 -> V_44 , 5 ) ;
if ( V_6 < 0 ) {
F_3 ( L_26 ) ;
F_56 ( & V_7 -> V_44 ) ;
return - V_22 ;
}
F_57 ( & V_7 -> V_44 , & V_110 ,
V_49 , V_111 ,
V_112 , 1 , V_112 ) ;
F_57 ( & V_7 -> V_44 , & V_110 ,
V_51 , 0 , 1 , 1 , 1 ) ;
F_58 ( & V_7 -> V_44 , & V_110 ,
V_53 , V_113 ,
0 , V_113 ) ;
F_57 ( & V_7 -> V_44 , & V_110 ,
V_52 , V_114 ,
V_115 , 1 , V_115 ) ;
V_42 = F_57 ( & V_7 -> V_44 , & V_110 ,
V_46 , 0 ,
255 , 1 , 255 ) ;
if ( V_42 )
V_42 -> V_107 |= V_116 ;
return 0 ;
}
void * F_59 ( void )
{
struct V_7 * V_7 ;
V_7 = F_60 ( V_102 ) ;
F_56 ( & V_7 -> V_44 ) ;
F_61 ( V_102 ) ;
return V_7 ;
}
