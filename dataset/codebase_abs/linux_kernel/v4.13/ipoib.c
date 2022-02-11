static void F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
F_2 ( V_2 , V_4 , V_5 ) ;
V_4 -> V_6 = F_3 () ?
V_7 :
V_8 ;
V_4 -> V_9 = false ;
}
static void F_4 ( struct V_1 * V_2 ,
struct V_10 * V_11 ,
const struct V_12 * V_13 ,
void * V_14 )
{
struct V_15 * V_16 = F_5 ( V_11 ) ;
V_16 -> V_2 = V_2 ;
V_16 -> V_11 = V_11 ;
V_16 -> V_13 = V_13 ;
V_16 -> V_14 = V_14 ;
V_16 -> V_17 = V_18 + V_19 ;
F_6 ( & V_16 -> V_20 ) ;
F_7 ( V_2 , & V_16 -> V_21 . V_4 , V_13 -> V_22 ( V_2 ) ) ;
F_1 ( V_2 , & V_16 -> V_21 . V_4 ) ;
V_11 -> V_23 |= V_24 ;
V_11 -> V_23 |= V_25 ;
V_11 -> V_23 |= V_26 ;
V_11 -> V_23 |= V_27 ;
V_11 -> V_23 |= V_28 ;
V_11 -> V_23 |= V_29 ;
V_11 -> V_23 |= V_30 ;
V_11 -> V_23 |= V_31 ;
V_11 -> V_32 = & V_33 ;
V_11 -> V_34 = & V_35 ;
}
static void F_8 ( struct V_15 * V_16 )
{
}
static int F_9 ( struct V_1 * V_2 , struct V_36 * V_37 )
{
struct V_38 * V_39 = NULL ;
T_1 * V_40 = NULL ;
void * V_41 ;
int V_42 = 0 ;
int V_43 ;
void * V_44 ;
V_43 = F_10 ( V_45 ) ;
V_40 = F_11 ( V_43 , V_46 ) ;
if ( ! V_40 )
return - V_47 ;
V_44 = F_12 ( V_45 , V_40 , V_44 ) ;
F_13 ( V_44 , V_44 , V_48 , V_49 ) ;
F_13 ( V_44 , V_44 , V_50 , V_51 ) ;
F_13 ( V_44 , V_44 , V_52 ,
V_53 ) ;
V_41 = F_12 ( V_44 , V_44 , V_54 ) ;
F_13 ( V_55 , V_41 , V_56 , 1 ) ;
F_13 ( V_55 , V_41 , V_57 , 1 ) ;
V_42 = F_14 ( V_2 , V_37 , V_40 , V_43 ) ;
if ( V_42 ) {
F_15 ( V_2 , L_1 , V_42 ) ;
goto V_58;
}
V_39 = F_16 ( sizeof( * V_39 ) , V_46 ) ;
if ( ! V_39 ) {
V_42 = - V_47 ;
goto V_58;
}
V_39 -> V_59 = F_17 ( V_51 << 11 ) ;
V_39 -> V_60 . V_56 = 1 ;
V_39 -> V_61 = F_17 ( V_62 ) ;
V_42 = F_18 ( V_2 , V_63 , 0 , V_39 , V_37 ) ;
if ( V_42 ) {
F_15 ( V_2 , L_2 , V_42 ) ;
goto V_58;
}
memset ( V_39 , 0 , sizeof( * V_39 ) ) ;
V_42 = F_18 ( V_2 , V_64 , 0 , V_39 , V_37 ) ;
if ( V_42 ) {
F_15 ( V_2 , L_3 , V_42 ) ;
goto V_58;
}
V_42 = F_18 ( V_2 , V_65 , 0 , V_39 , V_37 ) ;
if ( V_42 ) {
F_15 ( V_2 , L_4 , V_42 ) ;
goto V_58;
}
V_58:
F_19 ( V_39 ) ;
F_20 ( V_40 ) ;
return V_42 ;
}
static void F_21 ( struct V_1 * V_2 , struct V_36 * V_37 )
{
F_22 ( V_2 , V_37 ) ;
}
static int F_23 ( struct V_15 * V_16 )
{
struct V_66 * V_67 = V_16 -> V_14 ;
int V_68 ;
V_68 = F_9 ( V_16 -> V_2 , & V_67 -> V_37 ) ;
if ( V_68 ) {
F_24 ( V_16 -> V_2 , L_5 , V_68 ) ;
return V_68 ;
}
V_68 = F_25 ( V_16 -> V_2 , 0 , V_67 -> V_37 . V_69 , & V_16 -> V_70 [ 0 ] ) ;
if ( V_68 ) {
F_24 ( V_16 -> V_2 , L_6 , V_68 ) ;
return V_68 ;
}
return 0 ;
}
static void F_26 ( struct V_15 * V_16 )
{
struct V_66 * V_67 = V_16 -> V_14 ;
F_27 ( V_16 -> V_2 , V_16 -> V_70 [ 0 ] ) ;
F_21 ( V_16 -> V_2 , & V_67 -> V_37 ) ;
}
static int F_28 ( struct V_15 * V_16 )
{
int V_68 ;
V_16 -> V_71 . V_72 = F_29 ( V_16 -> V_2 ,
V_73 ) ;
if ( ! V_16 -> V_71 . V_72 )
return - V_74 ;
V_68 = F_30 ( V_16 ) ;
if ( V_68 ) {
F_31 ( V_16 -> V_11 , L_7 ,
V_68 ) ;
V_16 -> V_11 -> V_23 &= ~ V_75 ;
}
V_68 = F_32 ( V_16 ) ;
if ( V_68 ) {
F_31 ( V_16 -> V_11 , L_8 ,
V_68 ) ;
goto V_76;
}
return 0 ;
V_76:
F_33 ( V_16 ) ;
return V_68 ;
}
static void F_34 ( struct V_15 * V_16 )
{
F_35 ( V_16 ) ;
F_33 ( V_16 ) ;
}
static int F_36 ( struct V_15 * V_16 )
{
struct V_66 * V_67 = V_16 -> V_14 ;
int V_68 ;
V_68 = F_37 ( V_16 ) ;
if ( V_68 )
return V_68 ;
V_68 = F_38 ( V_16 ) ;
if ( V_68 )
goto V_77;
V_68 = F_39 ( V_16 ) ;
if ( V_68 )
goto V_78;
V_68 = F_40 ( V_16 ) ;
if ( V_68 )
goto V_79;
V_68 = F_41 ( V_16 -> V_2 , V_67 -> V_37 . V_69 ) ;
if ( V_68 )
goto V_80;
V_68 = F_28 ( V_16 ) ;
if ( V_68 )
goto V_81;
return 0 ;
V_81:
F_42 ( V_16 -> V_2 , V_67 -> V_37 . V_69 ) ;
V_80:
F_43 ( V_16 ) ;
V_79:
F_44 ( V_16 ) ;
V_78:
F_45 ( V_16 ) ;
V_77:
F_46 ( V_16 , & V_16 -> V_82 ) ;
return V_68 ;
}
static void F_47 ( struct V_15 * V_16 )
{
struct V_66 * V_67 = V_16 -> V_14 ;
F_42 ( V_16 -> V_2 , V_67 -> V_37 . V_69 ) ;
F_34 ( V_16 ) ;
F_43 ( V_16 ) ;
F_44 ( V_16 ) ;
F_45 ( V_16 ) ;
F_46 ( V_16 , & V_16 -> V_82 ) ;
}
static int F_48 ( struct V_10 * V_11 , int V_83 )
{
struct V_15 * V_16 = F_5 ( V_11 ) ;
struct V_84 V_85 = {} ;
int V_86 ;
int V_68 = 0 ;
F_49 ( & V_16 -> V_20 ) ;
V_86 = V_11 -> V_87 ;
V_11 -> V_87 = V_83 ;
if ( ! F_50 ( V_88 , & V_16 -> V_89 ) )
goto V_58;
V_85 . V_4 = V_16 -> V_21 . V_4 ;
V_68 = F_51 ( V_16 , & V_85 ) ;
if ( V_68 ) {
V_11 -> V_87 = V_86 ;
goto V_58;
}
F_52 ( V_16 , & V_85 , NULL ) ;
V_58:
F_53 ( & V_16 -> V_20 ) ;
return V_68 ;
}
static int F_54 ( struct V_10 * V_90 )
{
struct V_15 * V_16 = F_5 ( V_90 ) ;
struct V_66 * V_67 = V_16 -> V_14 ;
V_90 -> V_91 [ 1 ] = ( V_67 -> V_37 . V_69 >> 16 ) & 0xff ;
V_90 -> V_91 [ 2 ] = ( V_67 -> V_37 . V_69 >> 8 ) & 0xff ;
V_90 -> V_91 [ 3 ] = ( V_67 -> V_37 . V_69 ) & 0xff ;
return 0 ;
}
static int F_55 ( struct V_10 * V_90 , struct V_92 * V_93 , int V_94 )
{
struct V_15 * V_16 = F_5 ( V_90 ) ;
switch ( V_94 ) {
case V_95 :
return F_56 ( V_16 , V_93 ) ;
case V_96 :
return F_57 ( V_16 , V_93 ) ;
default:
return - V_97 ;
}
}
static void F_58 ( struct V_10 * V_90 )
{
struct V_15 * V_16 = F_5 ( V_90 ) ;
struct V_1 * V_2 = V_16 -> V_2 ;
struct V_66 * V_67 = V_16 -> V_14 ;
struct V_38 V_39 ;
F_18 ( V_2 , V_98 , 0 , & V_39 , & V_67 -> V_37 ) ;
}
static int F_59 ( struct V_10 * V_11 )
{
struct V_15 * V_16 = F_5 ( V_11 ) ;
int V_68 ;
F_49 ( & V_16 -> V_20 ) ;
F_60 ( V_88 , & V_16 -> V_89 ) ;
V_68 = F_51 ( V_16 , & V_16 -> V_21 ) ;
if ( V_68 )
goto V_99;
F_61 ( V_16 , false ) ;
F_62 ( V_16 ) ;
F_63 ( V_16 ) ;
F_53 ( & V_16 -> V_20 ) ;
return 0 ;
V_99:
F_64 ( V_88 , & V_16 -> V_89 ) ;
F_53 ( & V_16 -> V_20 ) ;
return V_68 ;
}
static int F_65 ( struct V_10 * V_11 )
{
struct V_15 * V_16 = F_5 ( V_11 ) ;
F_49 ( & V_16 -> V_20 ) ;
if ( ! F_50 ( V_88 , & V_16 -> V_89 ) )
goto V_100;
F_64 ( V_88 , & V_16 -> V_89 ) ;
F_66 ( V_16 ) ;
F_67 ( V_16 -> V_11 ) ;
F_68 ( V_16 ) ;
F_69 ( & V_16 -> V_21 ) ;
V_100:
F_53 ( & V_16 -> V_20 ) ;
return 0 ;
}
static int F_70 ( struct V_10 * V_11 , struct V_101 * V_102 ,
union V_103 * V_104 , T_2 V_105 , int V_106 ,
T_1 V_61 )
{
struct V_15 * V_107 = F_5 ( V_11 ) ;
struct V_1 * V_2 = V_107 -> V_2 ;
struct V_66 * V_67 = V_107 -> V_14 ;
int V_68 ;
F_71 ( V_2 , L_9 , V_67 -> V_37 . V_69 , V_104 -> V_108 ) ;
V_68 = F_72 ( V_2 , V_104 , V_67 -> V_37 . V_69 ) ;
if ( V_68 )
F_24 ( V_2 , L_10 ,
V_67 -> V_37 . V_69 , V_104 -> V_108 ) ;
if ( V_106 ) {
F_71 ( V_2 , L_11 ,
V_11 -> V_109 , V_61 ) ;
V_67 -> V_61 = V_61 ;
}
return V_68 ;
}
static int F_73 ( struct V_10 * V_11 , struct V_101 * V_102 ,
union V_103 * V_104 , T_2 V_105 )
{
struct V_15 * V_107 = F_5 ( V_11 ) ;
struct V_1 * V_2 = V_107 -> V_2 ;
struct V_66 * V_67 = V_107 -> V_14 ;
int V_68 ;
F_71 ( V_2 , L_12 , V_67 -> V_37 . V_69 , V_104 -> V_108 ) ;
V_68 = F_74 ( V_2 , V_104 , V_67 -> V_37 . V_69 ) ;
if ( V_68 )
F_71 ( V_2 , L_13 ,
V_67 -> V_37 . V_69 , V_104 -> V_108 ) ;
return V_68 ;
}
static int F_75 ( struct V_10 * V_90 , struct V_110 * V_111 ,
struct V_112 * V_113 , T_1 V_114 )
{
struct V_15 * V_107 = F_5 ( V_90 ) ;
struct V_115 * V_116 = V_107 -> V_117 [ F_76 ( V_111 ) ] ;
struct V_118 * V_119 = F_77 ( V_113 ) ;
struct V_66 * V_67 = V_107 -> V_14 ;
return F_78 ( V_116 , V_111 , & V_119 -> V_120 , V_114 , V_67 -> V_61 ) ;
}
static int F_79 ( struct V_1 * V_2 )
{
if ( F_80 ( V_2 , V_121 ) != V_122 )
return - V_97 ;
if ( ! F_80 ( V_2 , V_123 ) ) {
F_24 ( V_2 , L_14 ) ;
return - V_97 ;
}
return 0 ;
}
struct V_10 * F_81 ( struct V_1 * V_2 ,
struct V_101 * V_124 ,
const char * V_109 ,
void (* F_82)( struct V_10 * ) )
{
const struct V_12 * V_13 = & V_125 ;
int V_126 = V_13 -> V_22 ( V_2 ) ;
struct V_10 * V_11 ;
struct V_66 * V_67 ;
struct V_15 * V_107 ;
struct V_127 * V_128 ;
int V_68 ;
if ( F_79 ( V_2 ) ) {
F_24 ( V_2 , L_15 ) ;
return F_83 ( - V_97 ) ;
}
V_68 = F_84 ( V_2 ) ;
if ( V_68 )
return NULL ;
V_11 = F_85 ( sizeof( struct V_66 ) + sizeof( struct V_15 ) ,
V_109 , V_129 ,
F_82 ,
V_126 * V_130 ,
V_126 ) ;
if ( ! V_11 ) {
F_24 ( V_2 , L_16 ) ;
goto V_131;
}
V_67 = F_86 ( V_11 ) ;
V_107 = F_5 ( V_11 ) ;
V_107 -> V_132 = F_87 ( L_17 ) ;
if ( ! V_107 -> V_132 )
goto V_133;
V_13 -> V_134 ( V_2 , V_11 , V_13 , V_67 ) ;
F_88 ( V_107 ) ;
F_67 ( V_11 ) ;
V_128 = & V_67 -> V_128 ;
V_128 -> V_102 = V_124 ;
V_128 -> V_135 = F_75 ;
V_128 -> V_136 = F_70 ;
V_128 -> V_137 = F_73 ;
return V_11 ;
V_133:
F_89 ( V_11 ) ;
V_131:
F_90 ( V_2 ) ;
return NULL ;
}
void F_91 ( struct V_10 * V_11 )
{
struct V_15 * V_16 = F_5 ( V_11 ) ;
const struct V_12 * V_13 = V_16 -> V_13 ;
F_92 ( V_16 ) ;
V_13 -> V_138 ( V_16 ) ;
F_93 ( V_16 -> V_132 ) ;
F_89 ( V_11 ) ;
F_90 ( V_16 -> V_2 ) ;
}
