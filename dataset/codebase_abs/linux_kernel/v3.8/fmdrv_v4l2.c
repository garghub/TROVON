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
if ( F_4 ( & V_7 -> V_10 ) )
return - V_11 ;
V_6 = F_5 ( V_7 , & V_5 ) ;
if ( V_6 < 0 ) {
F_3 ( L_2 ) ;
goto V_12;
}
if ( V_5 == V_13 ) {
V_6 = F_6 ( V_7 , V_14 ) ;
if ( V_6 < 0 ) {
F_3 ( L_3 ) ;
goto V_12;
}
}
V_6 = F_7 ( V_7 , V_1 , V_2 , V_3 ) ;
V_12:
F_8 ( & V_7 -> V_10 ) ;
return V_6 ;
}
static T_1 F_9 ( struct V_1 * V_1 , const char T_2 * V_2 ,
T_3 V_3 , T_4 * V_4 )
{
struct V_15 V_16 ;
int V_6 ;
struct V_7 * V_7 ;
V_6 = F_10 ( & V_16 , V_2 , sizeof( V_16 ) ) ;
V_16 . V_17 [ sizeof( V_16 . V_17 ) - 1 ] = '\0' ;
F_11 ( L_4 ,
V_6 , V_16 . V_18 , V_16 . V_17 , V_16 . V_19 ) ;
if ( V_6 )
return - V_20 ;
V_7 = F_2 ( V_1 ) ;
if ( F_4 ( & V_7 -> V_10 ) )
return - V_11 ;
F_12 ( V_7 , V_16 . V_17 , V_16 . V_18 ) ;
F_13 ( V_7 , V_16 . V_19 ) ;
F_8 ( & V_7 -> V_10 ) ;
return sizeof( V_16 ) ;
}
static T_6 F_14 ( struct V_1 * V_1 , struct V_21 * V_22 )
{
int V_6 ;
struct V_7 * V_7 ;
V_7 = F_2 ( V_1 ) ;
F_15 ( & V_7 -> V_10 ) ;
V_6 = F_16 ( V_7 , V_1 , V_22 ) ;
F_8 ( & V_7 -> V_10 ) ;
if ( V_6 < 0 )
return V_23 | V_24 ;
return 0 ;
}
static int F_17 ( struct V_1 * V_1 )
{
int V_6 ;
struct V_7 * V_7 = NULL ;
if ( V_8 ) {
F_3 ( L_5 ) ;
return - V_25 ;
}
V_7 = F_2 ( V_1 ) ;
if ( F_4 ( & V_7 -> V_10 ) )
return - V_11 ;
V_6 = F_18 ( V_7 ) ;
if ( V_6 < 0 ) {
F_3 ( L_6 ) ;
goto V_26;
}
F_11 ( L_7 ) ;
V_6 = F_19 ( V_7 , V_27 ) ;
if ( V_6 < 0 ) {
F_3 ( L_8 ) ;
goto V_26;
}
V_8 = 1 ;
V_26:
F_8 ( & V_7 -> V_10 ) ;
return V_6 ;
}
static int F_20 ( struct V_1 * V_1 )
{
int V_6 ;
struct V_7 * V_7 ;
V_7 = F_2 ( V_1 ) ;
if ( ! V_8 ) {
F_11 ( L_9 ) ;
return 0 ;
}
F_15 ( & V_7 -> V_10 ) ;
V_6 = F_19 ( V_7 , V_28 ) ;
if ( V_6 < 0 ) {
F_3 ( L_10 ) ;
goto V_29;
}
V_6 = F_21 ( V_7 ) ;
if ( V_6 < 0 ) {
F_3 ( L_11 ) ;
goto V_29;
}
V_8 = 0 ;
V_29:
F_8 ( & V_7 -> V_10 ) ;
return V_6 ;
}
static int F_22 ( struct V_1 * V_1 , void * V_30 ,
struct V_31 * V_32 )
{
F_23 ( V_32 -> V_33 , V_34 , sizeof( V_32 -> V_33 ) ) ;
F_23 ( V_32 -> V_35 , V_36 ,
sizeof( V_32 -> V_35 ) ) ;
sprintf ( V_32 -> V_37 , L_12 ) ;
V_32 -> V_38 = V_39 | V_40 |
V_41 | V_42 |
V_43 | V_44 |
V_45 ;
return 0 ;
}
static int F_24 ( struct V_46 * V_47 )
{
struct V_7 * V_7 = F_25 ( V_47 -> V_48 ,
struct V_7 , V_49 ) ;
switch ( V_47 -> V_50 ) {
case V_51 :
V_47 -> V_52 = F_26 ( V_7 ) ;
break;
default:
F_27 ( L_13 , V_53 , V_47 -> V_50 ) ;
break;
}
return 0 ;
}
static int F_28 ( struct V_46 * V_47 )
{
struct V_7 * V_7 = F_25 ( V_47 -> V_48 ,
struct V_7 , V_49 ) ;
switch ( V_47 -> V_50 ) {
case V_54 :
return F_29 ( V_7 , ( V_55 ) V_47 -> V_52 ) ;
case V_56 :
return F_30 ( V_7 , ( T_5 ) V_47 -> V_52 ) ;
case V_57 :
return F_31 ( V_7 , ( T_5 ) V_47 -> V_52 ) ;
case V_58 :
return F_32 ( V_7 , ( T_5 ) V_47 -> V_52 ) ;
default:
return - V_59 ;
}
}
static int F_33 ( struct V_1 * V_1 , void * V_30 ,
struct V_60 * V_61 )
{
memset ( V_61 , 0 , sizeof( * V_61 ) ) ;
strcpy ( V_61 -> V_62 , L_14 ) ;
V_61 -> V_32 = V_63 ;
return 0 ;
}
static int F_34 ( struct V_1 * V_1 , void * V_30 ,
const struct V_60 * V_61 )
{
if ( V_61 -> V_64 != 0 )
return - V_59 ;
return 0 ;
}
static int F_35 ( struct V_1 * V_1 , void * V_30 ,
struct V_65 * V_66 )
{
struct V_7 * V_7 = F_2 ( V_1 ) ;
T_6 V_67 ;
T_6 V_68 ;
V_55 V_69 ;
V_55 V_70 ;
int V_6 ;
if ( V_66 -> V_64 != 0 )
return - V_59 ;
if ( V_7 -> V_71 != V_27 )
return - V_72 ;
V_6 = F_36 ( V_7 , & V_67 , & V_68 ) ;
if ( V_6 != 0 )
return V_6 ;
V_6 = F_37 ( V_7 , & V_69 ) ;
if ( V_6 != 0 )
return V_6 ;
V_6 = F_38 ( V_7 , & V_70 ) ;
if ( V_6 != 0 )
return V_6 ;
strcpy ( V_66 -> V_62 , L_15 ) ;
V_66 -> type = V_73 ;
V_66 -> V_74 = V_67 * 16 ;
V_66 -> V_75 = V_68 * 16 ;
V_66 -> V_76 = V_77 | V_78 |
( ( V_7 -> V_79 . V_16 . V_80 == V_14 ) ? V_81 : 0 ) ;
V_66 -> V_32 = V_82 | V_83 |
V_84 |
V_85 |
V_86 ;
V_66 -> V_87 = ( V_69 ?
V_88 : V_89 ) ;
V_70 += 128 ;
V_66 -> signal = V_70 * 257 ;
V_66 -> V_90 = 0 ;
return V_6 ;
}
static int F_39 ( struct V_1 * V_1 , void * V_30 ,
struct V_65 * V_66 )
{
struct V_7 * V_7 = F_2 ( V_1 ) ;
V_55 V_91 ;
T_5 V_5 ;
int V_6 ;
if ( V_66 -> V_64 != 0 )
return - V_59 ;
V_91 = ( V_66 -> V_87 == V_89 ) ?
V_92 : V_93 ;
V_5 = ( V_66 -> V_76 & V_81 ) ?
V_14 : V_13 ;
if ( V_7 -> V_71 != V_27 ) {
V_6 = F_19 ( V_7 , V_27 ) ;
if ( V_6 < 0 ) {
F_3 ( L_16 ) ;
return V_6 ;
}
}
V_6 = F_40 ( V_7 , V_91 ) ;
if ( V_6 < 0 ) {
F_3 ( L_17 ) ;
return V_6 ;
}
V_6 = F_6 ( V_7 , V_5 ) ;
if ( V_6 < 0 )
F_3 ( L_18 ) ;
return V_6 ;
}
static int F_41 ( struct V_1 * V_1 , void * V_30 ,
struct V_94 * V_95 )
{
struct V_7 * V_7 = F_2 ( V_1 ) ;
int V_6 ;
V_6 = F_42 ( V_7 , & V_95 -> V_96 ) ;
if ( V_6 < 0 ) {
F_3 ( L_19 ) ;
return V_6 ;
}
V_95 -> V_96 = ( T_6 ) V_95 -> V_96 * 16 ;
return 0 ;
}
static int F_43 ( struct V_1 * V_1 , void * V_30 ,
struct V_94 * V_95 )
{
struct V_7 * V_7 = F_2 ( V_1 ) ;
V_95 -> V_96 = ( T_6 ) ( V_95 -> V_96 / 16 ) ;
return F_44 ( V_7 , V_95 -> V_96 ) ;
}
static int F_45 ( struct V_1 * V_1 , void * V_30 ,
const struct V_97 * V_98 )
{
struct V_7 * V_7 = F_2 ( V_1 ) ;
int V_6 ;
if ( V_1 -> V_99 & V_100 )
return - V_101 ;
if ( V_7 -> V_71 != V_27 ) {
V_6 = F_19 ( V_7 , V_27 ) ;
if ( V_6 != 0 ) {
F_3 ( L_16 ) ;
return V_6 ;
}
}
V_6 = F_46 ( V_7 , V_98 -> V_102 , V_98 -> V_103 ,
V_98 -> V_104 ) ;
if ( V_6 < 0 )
F_3 ( L_20 , V_6 ) ;
return V_6 ;
}
static int F_47 ( struct V_1 * V_1 , void * V_30 ,
struct V_105 * V_106 )
{
struct V_7 * V_7 = F_2 ( V_1 ) ;
if ( V_106 -> V_64 != 0 )
return - V_59 ;
if ( V_7 -> V_71 != V_107 )
return - V_72 ;
V_106 -> V_108 = ( ( V_7 -> V_109 . V_91 == V_92 ) ?
V_78 : V_77 ) |
( ( V_7 -> V_109 . V_16 . V_80 == V_14 ) ?
V_81 : 0 ) ;
V_106 -> V_32 = V_82 | V_83 |
V_84 ;
return 0 ;
}
static int F_48 ( struct V_1 * V_1 , void * V_30 ,
const struct V_105 * V_106 )
{
struct V_7 * V_7 = F_2 ( V_1 ) ;
T_5 V_5 ;
V_55 V_91 ;
int V_6 ;
if ( V_106 -> V_64 != 0 )
return - V_59 ;
if ( V_7 -> V_71 != V_107 ) {
V_6 = F_19 ( V_7 , V_107 ) ;
if ( V_6 != 0 ) {
F_3 ( L_21 ) ;
return V_6 ;
}
}
V_91 = ( V_106 -> V_108 & V_78 ) ?
V_92 : V_93 ;
V_5 = ( V_106 -> V_108 & V_81 ) ?
V_14 : V_13 ;
V_6 = F_49 ( V_7 , V_91 ) ;
if ( V_6 < 0 ) {
F_3 ( L_22 ) ;
return V_6 ;
}
V_6 = F_50 ( V_7 , V_5 ) ;
if ( V_6 < 0 )
F_3 ( L_23 ) ;
return V_6 ;
}
int F_51 ( struct V_7 * V_7 , int V_110 )
{
struct V_46 * V_47 ;
int V_6 ;
F_52 ( & V_7 -> V_10 ) ;
V_111 = F_53 () ;
if ( NULL == V_111 ) {
F_3 ( L_24 ) ;
return - V_112 ;
}
memcpy ( V_111 , & V_113 , sizeof( V_113 ) ) ;
F_54 ( V_111 , V_7 ) ;
V_111 -> V_114 = & V_7 -> V_10 ;
if ( F_55 ( V_111 , V_115 , V_110 ) ) {
F_56 ( V_111 ) ;
F_3 ( L_25 ) ;
return - V_112 ;
}
V_7 -> V_116 = V_111 ;
V_7 -> V_116 -> V_49 = & V_7 -> V_49 ;
V_6 = F_57 ( & V_7 -> V_49 , 5 ) ;
if ( V_6 < 0 ) {
F_3 ( L_26 ) ;
F_58 ( & V_7 -> V_49 ) ;
return - V_25 ;
}
F_59 ( & V_7 -> V_49 , & V_117 ,
V_54 , V_118 ,
V_119 , 1 , V_119 ) ;
F_59 ( & V_7 -> V_49 , & V_117 ,
V_56 , 0 , 1 , 1 , 1 ) ;
F_60 ( & V_7 -> V_49 , & V_117 ,
V_58 , V_120 ,
0 , V_120 ) ;
F_59 ( & V_7 -> V_49 , & V_117 ,
V_57 , V_121 ,
V_122 , 1 , V_122 ) ;
V_47 = F_59 ( & V_7 -> V_49 , & V_117 ,
V_51 , 0 ,
255 , 1 , 255 ) ;
if ( V_47 )
V_47 -> V_123 |= V_124 ;
return 0 ;
}
void * F_61 ( void )
{
struct V_7 * V_7 ;
V_7 = F_62 ( V_111 ) ;
F_58 ( & V_7 -> V_49 ) ;
F_63 ( V_111 ) ;
return V_7 ;
}
