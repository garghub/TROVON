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
F_9 ( L_4 ,
V_6 , V_13 . V_14 , V_13 . V_15 , V_13 . V_16 ) ;
V_7 = F_2 ( V_1 ) ;
F_10 ( V_7 , V_13 . V_15 , V_13 . V_14 ) ;
F_11 ( V_7 , V_13 . V_16 ) ;
return 0 ;
}
static T_6 F_12 ( struct V_1 * V_1 , struct V_17 * V_18 )
{
int V_6 ;
struct V_7 * V_7 ;
V_7 = F_2 ( V_1 ) ;
V_6 = F_13 ( V_7 , V_1 , V_18 ) ;
if ( V_6 < 0 )
return V_19 | V_20 ;
return 0 ;
}
static int F_14 ( struct V_1 * V_1 )
{
int V_6 ;
struct V_7 * V_7 = NULL ;
if ( V_8 ) {
F_3 ( L_5 ) ;
return - V_21 ;
}
V_7 = F_2 ( V_1 ) ;
V_6 = F_15 ( V_7 ) ;
if ( V_6 < 0 ) {
F_3 ( L_6 ) ;
return V_6 ;
}
F_9 ( L_7 ) ;
V_6 = F_16 ( V_7 , V_22 ) ;
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
V_6 = F_16 ( V_7 , V_23 ) ;
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
static int F_19 ( struct V_1 * V_1 , void * V_24 ,
struct V_25 * V_26 )
{
F_20 ( V_26 -> V_27 , V_28 , sizeof( V_26 -> V_27 ) ) ;
F_20 ( V_26 -> V_29 , V_30 ,
sizeof( V_26 -> V_29 ) ) ;
sprintf ( V_26 -> V_31 , L_12 ) ;
V_26 -> V_32 = V_33 | V_34 |
V_35 | V_36 |
V_37 | V_38 |
V_39 ;
return 0 ;
}
static int F_21 ( struct V_40 * V_41 )
{
struct V_7 * V_7 = F_22 ( V_41 -> V_42 ,
struct V_7 , V_43 ) ;
switch ( V_41 -> V_44 ) {
case V_45 :
V_41 -> V_46 = F_23 ( V_7 ) ;
break;
default:
F_24 ( L_13 , V_47 , V_41 -> V_44 ) ;
break;
}
return 0 ;
}
static int F_25 ( struct V_40 * V_41 )
{
struct V_7 * V_7 = F_22 ( V_41 -> V_42 ,
struct V_7 , V_43 ) ;
switch ( V_41 -> V_44 ) {
case V_48 :
return F_26 ( V_7 , ( V_49 ) V_41 -> V_46 ) ;
case V_50 :
return F_27 ( V_7 , ( T_5 ) V_41 -> V_46 ) ;
case V_51 :
return F_28 ( V_7 , ( T_5 ) V_41 -> V_46 ) ;
case V_52 :
return F_29 ( V_7 , ( T_5 ) V_41 -> V_46 ) ;
default:
return - V_53 ;
}
}
static int F_30 ( struct V_1 * V_1 , void * V_24 ,
struct V_54 * V_55 )
{
memset ( V_55 , 0 , sizeof( * V_55 ) ) ;
strcpy ( V_55 -> V_56 , L_14 ) ;
V_55 -> V_26 = V_57 ;
return 0 ;
}
static int F_31 ( struct V_1 * V_1 , void * V_24 ,
struct V_54 * V_55 )
{
if ( V_55 -> V_58 != 0 )
return - V_53 ;
return 0 ;
}
static int F_32 ( struct V_1 * V_1 , void * V_24 ,
struct V_59 * V_60 )
{
struct V_7 * V_7 = F_2 ( V_1 ) ;
T_6 V_61 ;
T_6 V_62 ;
V_49 V_63 ;
V_49 V_64 ;
int V_6 ;
if ( V_60 -> V_58 != 0 )
return - V_53 ;
if ( V_7 -> V_65 != V_22 )
return - V_66 ;
V_6 = F_33 ( V_7 , & V_61 , & V_62 ) ;
if ( V_6 != 0 )
return V_6 ;
V_6 = F_34 ( V_7 , & V_63 ) ;
if ( V_6 != 0 )
return V_6 ;
V_6 = F_35 ( V_7 , & V_64 ) ;
if ( V_6 != 0 )
return V_6 ;
strcpy ( V_60 -> V_56 , L_15 ) ;
V_60 -> type = V_67 ;
V_60 -> V_68 = V_61 * 16 ;
V_60 -> V_69 = V_62 * 16 ;
V_60 -> V_70 = V_71 | V_72 |
( ( V_7 -> V_73 . V_13 . V_74 == V_11 ) ? V_75 : 0 ) ;
V_60 -> V_26 = V_76 | V_77 |
V_78 ;
V_60 -> V_79 = ( V_63 ?
V_80 : V_81 ) ;
V_64 += 128 ;
V_60 -> signal = V_64 * 257 ;
V_60 -> V_82 = 0 ;
return V_6 ;
}
static int F_36 ( struct V_1 * V_1 , void * V_24 ,
struct V_59 * V_60 )
{
struct V_7 * V_7 = F_2 ( V_1 ) ;
V_49 V_83 ;
T_5 V_5 ;
int V_6 ;
if ( V_60 -> V_58 != 0 )
return - V_53 ;
V_83 = ( V_60 -> V_79 == V_81 ) ?
V_84 : V_85 ;
V_5 = ( V_60 -> V_70 & V_75 ) ?
V_11 : V_10 ;
if ( V_7 -> V_65 != V_22 ) {
V_6 = F_16 ( V_7 , V_22 ) ;
if ( V_6 < 0 ) {
F_3 ( L_16 ) ;
return V_6 ;
}
}
V_6 = F_37 ( V_7 , V_83 ) ;
if ( V_6 < 0 ) {
F_3 ( L_17 ) ;
return V_6 ;
}
V_6 = F_5 ( V_7 , V_5 ) ;
if ( V_6 < 0 )
F_3 ( L_18 ) ;
return V_6 ;
}
static int F_38 ( struct V_1 * V_1 , void * V_24 ,
struct V_86 * V_87 )
{
struct V_7 * V_7 = F_2 ( V_1 ) ;
int V_6 ;
V_6 = F_39 ( V_7 , & V_87 -> V_88 ) ;
if ( V_6 < 0 ) {
F_3 ( L_19 ) ;
return V_6 ;
}
V_87 -> V_88 = ( T_6 ) V_87 -> V_88 * 16 ;
return 0 ;
}
static int F_40 ( struct V_1 * V_1 , void * V_24 ,
struct V_86 * V_87 )
{
struct V_7 * V_7 = F_2 ( V_1 ) ;
V_87 -> V_88 = ( T_6 ) ( V_87 -> V_88 / 16 ) ;
return F_41 ( V_7 , V_87 -> V_88 ) ;
}
static int F_42 ( struct V_1 * V_1 , void * V_24 ,
struct V_89 * V_90 )
{
struct V_7 * V_7 = F_2 ( V_1 ) ;
int V_6 ;
if ( V_7 -> V_65 != V_22 ) {
V_6 = F_16 ( V_7 , V_22 ) ;
if ( V_6 != 0 ) {
F_3 ( L_16 ) ;
return V_6 ;
}
}
V_6 = F_43 ( V_7 , V_90 -> V_91 , V_90 -> V_92 ,
V_90 -> V_93 ) ;
if ( V_6 < 0 )
F_3 ( L_20 , V_6 ) ;
return V_6 ;
}
static int F_44 ( struct V_1 * V_1 , void * V_24 ,
struct V_94 * V_95 )
{
struct V_7 * V_7 = F_2 ( V_1 ) ; ;
if ( V_95 -> V_58 != 0 )
return - V_53 ;
if ( V_7 -> V_65 != V_96 )
return - V_66 ;
V_95 -> V_97 = ( ( V_7 -> V_98 . V_83 == V_84 ) ?
V_72 : V_71 ) |
( ( V_7 -> V_98 . V_13 . V_74 == V_11 ) ?
V_75 : 0 ) ;
V_95 -> V_26 = V_76 | V_77 |
V_78 ;
return 0 ;
}
static int F_45 ( struct V_1 * V_1 , void * V_24 ,
struct V_94 * V_95 )
{
struct V_7 * V_7 = F_2 ( V_1 ) ;
T_5 V_5 ;
V_49 V_83 ;
int V_6 ;
if ( V_95 -> V_58 != 0 )
return - V_53 ;
if ( V_7 -> V_65 != V_96 ) {
V_6 = F_16 ( V_7 , V_96 ) ;
if ( V_6 != 0 ) {
F_3 ( L_21 ) ;
return V_6 ;
}
}
V_83 = ( V_95 -> V_97 & V_72 ) ?
V_84 : V_85 ;
V_5 = ( V_95 -> V_97 & V_75 ) ?
V_11 : V_10 ;
V_6 = F_46 ( V_7 , V_83 ) ;
if ( V_6 < 0 ) {
F_3 ( L_22 ) ;
return V_6 ;
}
V_6 = F_47 ( V_7 , V_5 ) ;
if ( V_6 < 0 )
F_3 ( L_23 ) ;
return V_6 ;
}
int F_48 ( struct V_7 * V_7 , int V_99 )
{
struct V_40 * V_41 ;
int V_6 ;
F_49 ( & V_7 -> V_100 ) ;
V_101 = F_50 () ;
if ( NULL == V_101 ) {
F_3 ( L_24 ) ;
return - V_102 ;
}
memcpy ( V_101 , & V_103 , sizeof( V_103 ) ) ;
F_51 ( V_101 , V_7 ) ;
V_101 -> V_104 = & V_7 -> V_100 ;
if ( F_52 ( V_101 , V_105 , V_99 ) ) {
F_53 ( V_101 ) ;
F_3 ( L_25 ) ;
return - V_102 ;
}
V_7 -> V_106 = V_101 ;
V_7 -> V_106 -> V_43 = & V_7 -> V_43 ;
V_6 = F_54 ( & V_7 -> V_43 , 5 ) ;
if ( V_6 < 0 ) {
F_3 ( L_26 ) ;
F_55 ( & V_7 -> V_43 ) ;
return - V_21 ;
}
F_56 ( & V_7 -> V_43 , & V_107 ,
V_48 , V_108 ,
V_109 , 1 , V_109 ) ;
F_56 ( & V_7 -> V_43 , & V_107 ,
V_50 , 0 , 1 , 1 , 1 ) ;
F_57 ( & V_7 -> V_43 , & V_107 ,
V_52 , V_110 ,
0 , V_110 ) ;
F_56 ( & V_7 -> V_43 , & V_107 ,
V_51 , V_111 ,
V_112 , 1 , V_112 ) ;
V_41 = F_56 ( & V_7 -> V_43 , & V_107 ,
V_45 , 0 ,
255 , 1 , 255 ) ;
if ( V_41 )
V_41 -> V_113 = 1 ;
return 0 ;
}
void * F_58 ( void )
{
struct V_7 * V_7 ;
V_7 = F_59 ( V_101 ) ;
F_55 ( & V_7 -> V_43 ) ;
F_60 ( V_101 ) ;
return V_7 ;
}
