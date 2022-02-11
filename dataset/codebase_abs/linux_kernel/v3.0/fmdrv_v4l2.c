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
V_26 -> V_32 = V_33 ;
V_26 -> V_34 = V_35 | V_36 |
V_37 | V_38 |
V_39 | V_40 |
V_41 ;
return 0 ;
}
static int F_21 ( struct V_42 * V_43 )
{
struct V_7 * V_7 = F_22 ( V_43 -> V_44 ,
struct V_7 , V_45 ) ;
switch ( V_43 -> V_46 ) {
case V_47 :
V_43 -> V_48 . V_49 = F_23 ( V_7 ) ;
break;
default:
F_24 ( L_13 , V_50 , V_43 -> V_46 ) ;
break;
}
return 0 ;
}
static int F_25 ( struct V_42 * V_43 )
{
struct V_7 * V_7 = F_22 ( V_43 -> V_44 ,
struct V_7 , V_45 ) ;
switch ( V_43 -> V_46 ) {
case V_51 :
return F_26 ( V_7 , ( V_52 ) V_43 -> V_49 ) ;
case V_53 :
return F_27 ( V_7 , ( T_5 ) V_43 -> V_49 ) ;
case V_54 :
return F_28 ( V_7 , ( T_5 ) V_43 -> V_49 ) ;
case V_55 :
return F_29 ( V_7 , ( T_5 ) V_43 -> V_49 ) ;
default:
return - V_56 ;
}
}
static int F_30 ( struct V_1 * V_1 , void * V_24 ,
struct V_57 * V_58 )
{
memset ( V_58 , 0 , sizeof( * V_58 ) ) ;
strcpy ( V_58 -> V_59 , L_14 ) ;
V_58 -> V_26 = V_60 ;
return 0 ;
}
static int F_31 ( struct V_1 * V_1 , void * V_24 ,
struct V_57 * V_58 )
{
if ( V_58 -> V_61 != 0 )
return - V_56 ;
return 0 ;
}
static int F_32 ( struct V_1 * V_1 , void * V_24 ,
struct V_62 * V_63 )
{
struct V_7 * V_7 = F_2 ( V_1 ) ;
T_6 V_64 ;
T_6 V_65 ;
V_52 V_66 ;
V_52 V_67 ;
int V_6 ;
if ( V_63 -> V_61 != 0 )
return - V_56 ;
if ( V_7 -> V_68 != V_22 )
return - V_69 ;
V_6 = F_33 ( V_7 , & V_64 , & V_65 ) ;
if ( V_6 != 0 )
return V_6 ;
V_6 = F_34 ( V_7 , & V_66 ) ;
if ( V_6 != 0 )
return V_6 ;
V_6 = F_35 ( V_7 , & V_67 ) ;
if ( V_6 != 0 )
return V_6 ;
strcpy ( V_63 -> V_59 , L_15 ) ;
V_63 -> type = V_70 ;
V_63 -> V_71 = V_64 * 16 ;
V_63 -> V_72 = V_65 * 16 ;
V_63 -> V_73 = V_74 | V_75 |
( ( V_7 -> V_76 . V_13 . V_77 == V_11 ) ? V_78 : 0 ) ;
V_63 -> V_26 = V_79 | V_80 |
V_81 ;
V_63 -> V_82 = ( V_66 ?
V_83 : V_84 ) ;
V_67 += 128 ;
V_63 -> signal = V_67 * 257 ;
V_63 -> V_85 = 0 ;
return V_6 ;
}
static int F_36 ( struct V_1 * V_1 , void * V_24 ,
struct V_62 * V_63 )
{
struct V_7 * V_7 = F_2 ( V_1 ) ;
V_52 V_86 ;
T_5 V_5 ;
int V_6 ;
if ( V_63 -> V_61 != 0 )
return - V_56 ;
V_86 = ( V_63 -> V_82 == V_84 ) ?
V_87 : V_88 ;
V_5 = ( V_63 -> V_73 & V_78 ) ?
V_11 : V_10 ;
if ( V_7 -> V_68 != V_22 ) {
V_6 = F_16 ( V_7 , V_22 ) ;
if ( V_6 < 0 ) {
F_3 ( L_16 ) ;
return V_6 ;
}
}
V_6 = F_37 ( V_7 , V_86 ) ;
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
struct V_89 * V_90 )
{
struct V_7 * V_7 = F_2 ( V_1 ) ;
int V_6 ;
V_6 = F_39 ( V_7 , & V_90 -> V_91 ) ;
if ( V_6 < 0 ) {
F_3 ( L_19 ) ;
return V_6 ;
}
V_90 -> V_91 = ( T_6 ) V_90 -> V_91 * 16 ;
return 0 ;
}
static int F_40 ( struct V_1 * V_1 , void * V_24 ,
struct V_89 * V_90 )
{
struct V_7 * V_7 = F_2 ( V_1 ) ;
V_90 -> V_91 = ( T_6 ) ( V_90 -> V_91 / 16 ) ;
return F_41 ( V_7 , V_90 -> V_91 ) ;
}
static int F_42 ( struct V_1 * V_1 , void * V_24 ,
struct V_92 * V_93 )
{
struct V_7 * V_7 = F_2 ( V_1 ) ;
int V_6 ;
if ( V_7 -> V_68 != V_22 ) {
V_6 = F_16 ( V_7 , V_22 ) ;
if ( V_6 != 0 ) {
F_3 ( L_16 ) ;
return V_6 ;
}
}
V_6 = F_43 ( V_7 , V_93 -> V_94 , V_93 -> V_95 ,
V_93 -> V_96 ) ;
if ( V_6 < 0 )
F_3 ( L_20 , V_6 ) ;
return V_6 ;
}
static int F_44 ( struct V_1 * V_1 , void * V_24 ,
struct V_97 * V_98 )
{
struct V_7 * V_7 = F_2 ( V_1 ) ; ;
if ( V_98 -> V_61 != 0 )
return - V_56 ;
if ( V_7 -> V_68 != V_99 )
return - V_69 ;
V_98 -> V_100 = ( ( V_7 -> V_101 . V_86 == V_87 ) ?
V_75 : V_74 ) |
( ( V_7 -> V_101 . V_13 . V_77 == V_11 ) ?
V_78 : 0 ) ;
V_98 -> V_26 = V_79 | V_80 |
V_81 ;
return 0 ;
}
static int F_45 ( struct V_1 * V_1 , void * V_24 ,
struct V_97 * V_98 )
{
struct V_7 * V_7 = F_2 ( V_1 ) ;
T_5 V_5 ;
V_52 V_86 ;
int V_6 ;
if ( V_98 -> V_61 != 0 )
return - V_56 ;
if ( V_7 -> V_68 != V_99 ) {
V_6 = F_16 ( V_7 , V_99 ) ;
if ( V_6 != 0 ) {
F_3 ( L_21 ) ;
return V_6 ;
}
}
V_86 = ( V_98 -> V_100 & V_75 ) ?
V_87 : V_88 ;
V_5 = ( V_98 -> V_100 & V_78 ) ?
V_11 : V_10 ;
V_6 = F_46 ( V_7 , V_86 ) ;
if ( V_6 < 0 ) {
F_3 ( L_22 ) ;
return V_6 ;
}
V_6 = F_47 ( V_7 , V_5 ) ;
if ( V_6 < 0 )
F_3 ( L_23 ) ;
return V_6 ;
}
int F_48 ( struct V_7 * V_7 , int V_102 )
{
struct V_42 * V_43 ;
int V_6 ;
F_49 ( & V_7 -> V_103 ) ;
V_104 = F_50 () ;
if ( NULL == V_104 ) {
F_3 ( L_24 ) ;
return - V_105 ;
}
memcpy ( V_104 , & V_106 , sizeof( V_106 ) ) ;
F_51 ( V_104 , V_7 ) ;
V_104 -> V_107 = & V_7 -> V_103 ;
if ( F_52 ( V_104 , V_108 , V_102 ) ) {
F_53 ( V_104 ) ;
F_3 ( L_25 ) ;
return - V_105 ;
}
V_7 -> V_109 = V_104 ;
V_7 -> V_109 -> V_45 = & V_7 -> V_45 ;
V_6 = F_54 ( & V_7 -> V_45 , 5 ) ;
if ( V_6 < 0 ) {
F_3 ( L_26 ) ;
F_55 ( & V_7 -> V_45 ) ;
return - V_21 ;
}
F_56 ( & V_7 -> V_45 , & V_110 ,
V_51 , V_111 ,
V_112 , 1 , V_112 ) ;
F_56 ( & V_7 -> V_45 , & V_110 ,
V_53 , 0 , 1 , 1 , 1 ) ;
F_57 ( & V_7 -> V_45 , & V_110 ,
V_55 , V_113 ,
0 , V_113 ) ;
F_56 ( & V_7 -> V_45 , & V_110 ,
V_54 , V_114 ,
V_115 , 1 , V_115 ) ;
V_43 = F_56 ( & V_7 -> V_45 , & V_110 ,
V_47 , 0 ,
255 , 1 , 255 ) ;
if ( V_43 )
V_43 -> V_116 = 1 ;
return 0 ;
}
void * F_58 ( void )
{
struct V_7 * V_7 ;
V_7 = F_59 ( V_104 ) ;
F_55 ( & V_7 -> V_45 ) ;
F_60 ( V_104 ) ;
return V_7 ;
}
