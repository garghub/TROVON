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
V_32 -> V_46 = V_32 -> V_38 |
V_47 ;
return 0 ;
}
static int F_24 ( struct V_48 * V_49 )
{
struct V_7 * V_7 = F_25 ( V_49 -> V_50 ,
struct V_7 , V_51 ) ;
switch ( V_49 -> V_52 ) {
case V_53 :
V_49 -> V_54 = F_26 ( V_7 ) ;
break;
default:
F_27 ( L_13 , V_55 , V_49 -> V_52 ) ;
break;
}
return 0 ;
}
static int F_28 ( struct V_48 * V_49 )
{
struct V_7 * V_7 = F_25 ( V_49 -> V_50 ,
struct V_7 , V_51 ) ;
switch ( V_49 -> V_52 ) {
case V_56 :
return F_29 ( V_7 , ( V_57 ) V_49 -> V_54 ) ;
case V_58 :
return F_30 ( V_7 , ( T_5 ) V_49 -> V_54 ) ;
case V_59 :
return F_31 ( V_7 , ( T_5 ) V_49 -> V_54 ) ;
case V_60 :
return F_32 ( V_7 , ( T_5 ) V_49 -> V_54 ) ;
default:
return - V_61 ;
}
}
static int F_33 ( struct V_1 * V_1 , void * V_30 ,
struct V_62 * V_63 )
{
memset ( V_63 , 0 , sizeof( * V_63 ) ) ;
strcpy ( V_63 -> V_64 , L_14 ) ;
V_63 -> V_32 = V_65 ;
return 0 ;
}
static int F_34 ( struct V_1 * V_1 , void * V_30 ,
const struct V_62 * V_63 )
{
if ( V_63 -> V_66 != 0 )
return - V_61 ;
return 0 ;
}
static int F_35 ( struct V_1 * V_1 , void * V_30 ,
struct V_67 * V_68 )
{
struct V_7 * V_7 = F_2 ( V_1 ) ;
T_6 V_69 ;
T_6 V_70 ;
V_57 V_71 ;
V_57 V_72 ;
int V_6 ;
if ( V_68 -> V_66 != 0 )
return - V_61 ;
if ( V_7 -> V_73 != V_27 )
return - V_74 ;
V_6 = F_36 ( V_7 , & V_69 , & V_70 ) ;
if ( V_6 != 0 )
return V_6 ;
V_6 = F_37 ( V_7 , & V_71 ) ;
if ( V_6 != 0 )
return V_6 ;
V_6 = F_38 ( V_7 , & V_72 ) ;
if ( V_6 != 0 )
return V_6 ;
strcpy ( V_68 -> V_64 , L_15 ) ;
V_68 -> type = V_75 ;
V_68 -> V_76 = V_69 * 16 ;
V_68 -> V_77 = V_70 * 16 ;
V_68 -> V_78 = V_79 | V_80 |
( ( V_7 -> V_81 . V_16 . V_82 == V_14 ) ? V_83 : 0 ) ;
V_68 -> V_32 = V_84 | V_85 |
V_86 |
V_87 |
V_88 ;
V_68 -> V_89 = ( V_71 ?
V_90 : V_91 ) ;
V_72 += 128 ;
V_68 -> signal = V_72 * 257 ;
V_68 -> V_92 = 0 ;
return V_6 ;
}
static int F_39 ( struct V_1 * V_1 , void * V_30 ,
const struct V_67 * V_68 )
{
struct V_7 * V_7 = F_2 ( V_1 ) ;
V_57 V_93 ;
T_5 V_5 ;
int V_6 ;
if ( V_68 -> V_66 != 0 )
return - V_61 ;
V_93 = ( V_68 -> V_89 == V_91 ) ?
V_94 : V_95 ;
V_5 = ( V_68 -> V_78 & V_83 ) ?
V_14 : V_13 ;
if ( V_7 -> V_73 != V_27 ) {
V_6 = F_19 ( V_7 , V_27 ) ;
if ( V_6 < 0 ) {
F_3 ( L_16 ) ;
return V_6 ;
}
}
V_6 = F_40 ( V_7 , V_93 ) ;
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
struct V_96 * V_97 )
{
struct V_7 * V_7 = F_2 ( V_1 ) ;
int V_6 ;
V_6 = F_42 ( V_7 , & V_97 -> V_98 ) ;
if ( V_6 < 0 ) {
F_3 ( L_19 ) ;
return V_6 ;
}
V_97 -> V_98 = ( T_6 ) V_97 -> V_98 * 16 ;
return 0 ;
}
static int F_43 ( struct V_1 * V_1 , void * V_30 ,
const struct V_96 * V_97 )
{
struct V_7 * V_7 = F_2 ( V_1 ) ;
return F_44 ( V_7 , V_97 -> V_98 / 16 ) ;
}
static int F_45 ( struct V_1 * V_1 , void * V_30 ,
const struct V_99 * V_100 )
{
struct V_7 * V_7 = F_2 ( V_1 ) ;
int V_6 ;
if ( V_1 -> V_101 & V_102 )
return - V_103 ;
if ( V_7 -> V_73 != V_27 ) {
V_6 = F_19 ( V_7 , V_27 ) ;
if ( V_6 != 0 ) {
F_3 ( L_16 ) ;
return V_6 ;
}
}
V_6 = F_46 ( V_7 , V_100 -> V_104 , V_100 -> V_105 ,
V_100 -> V_106 ) ;
if ( V_6 < 0 )
F_3 ( L_20 , V_6 ) ;
return V_6 ;
}
static int F_47 ( struct V_1 * V_1 , void * V_30 ,
struct V_107 * V_108 )
{
struct V_7 * V_7 = F_2 ( V_1 ) ;
if ( V_108 -> V_66 != 0 )
return - V_61 ;
if ( V_7 -> V_73 != V_109 )
return - V_74 ;
V_108 -> V_110 = ( ( V_7 -> V_111 . V_93 == V_94 ) ?
V_80 : V_79 ) |
( ( V_7 -> V_111 . V_16 . V_82 == V_14 ) ?
V_83 : 0 ) ;
V_108 -> V_32 = V_84 | V_85 |
V_86 ;
return 0 ;
}
static int F_48 ( struct V_1 * V_1 , void * V_30 ,
const struct V_107 * V_108 )
{
struct V_7 * V_7 = F_2 ( V_1 ) ;
T_5 V_5 ;
V_57 V_93 ;
int V_6 ;
if ( V_108 -> V_66 != 0 )
return - V_61 ;
if ( V_7 -> V_73 != V_109 ) {
V_6 = F_19 ( V_7 , V_109 ) ;
if ( V_6 != 0 ) {
F_3 ( L_21 ) ;
return V_6 ;
}
}
V_93 = ( V_108 -> V_110 & V_80 ) ?
V_94 : V_95 ;
V_5 = ( V_108 -> V_110 & V_83 ) ?
V_14 : V_13 ;
V_6 = F_49 ( V_7 , V_93 ) ;
if ( V_6 < 0 ) {
F_3 ( L_22 ) ;
return V_6 ;
}
V_6 = F_50 ( V_7 , V_5 ) ;
if ( V_6 < 0 )
F_3 ( L_23 ) ;
return V_6 ;
}
int F_51 ( struct V_7 * V_7 , int V_112 )
{
struct V_48 * V_49 ;
int V_6 ;
F_23 ( V_7 -> V_113 . V_64 , V_34 , sizeof( V_7 -> V_113 . V_64 ) ) ;
V_6 = F_52 ( NULL , & V_7 -> V_113 ) ;
if ( V_6 < 0 )
return V_6 ;
F_53 ( & V_7 -> V_10 ) ;
V_114 = V_115 ;
F_54 ( & V_114 , V_7 ) ;
V_114 . V_116 = & V_7 -> V_10 ;
V_114 . V_113 = & V_7 -> V_113 ;
if ( F_55 ( & V_114 , V_117 , V_112 ) ) {
F_3 ( L_24 ) ;
return - V_118 ;
}
V_7 -> V_119 = & V_114 ;
V_7 -> V_119 -> V_51 = & V_7 -> V_51 ;
V_6 = F_56 ( & V_7 -> V_51 , 5 ) ;
if ( V_6 < 0 ) {
F_3 ( L_25 ) ;
F_57 ( & V_7 -> V_51 ) ;
return - V_25 ;
}
F_58 ( & V_7 -> V_51 , & V_120 ,
V_56 , V_121 ,
V_122 , 1 , V_122 ) ;
F_58 ( & V_7 -> V_51 , & V_120 ,
V_58 , 0 , 1 , 1 , 1 ) ;
F_59 ( & V_7 -> V_51 , & V_120 ,
V_60 , V_123 ,
0 , V_123 ) ;
F_58 ( & V_7 -> V_51 , & V_120 ,
V_59 , V_124 ,
V_125 , 1 , V_125 ) ;
V_49 = F_58 ( & V_7 -> V_51 , & V_120 ,
V_53 , 0 ,
255 , 1 , 255 ) ;
if ( V_49 )
V_49 -> V_126 |= V_127 ;
return 0 ;
}
void * F_60 ( void )
{
struct V_7 * V_7 ;
V_7 = F_61 ( & V_114 ) ;
F_57 ( & V_7 -> V_51 ) ;
F_62 ( & V_114 ) ;
F_63 ( & V_7 -> V_113 ) ;
return V_7 ;
}
