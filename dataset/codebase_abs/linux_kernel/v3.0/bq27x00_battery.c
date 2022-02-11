static inline int F_1 ( struct V_1 * V_2 , T_1 V_3 ,
bool V_4 )
{
return V_2 -> V_5 . V_6 ( V_2 , V_3 , V_4 ) ;
}
static int F_2 ( struct V_1 * V_2 )
{
int V_7 ;
if ( V_2 -> V_8 == V_9 )
V_7 = F_1 ( V_2 , V_10 , false ) ;
else
V_7 = F_1 ( V_2 , V_11 , true ) ;
if ( V_7 < 0 )
F_3 ( V_2 -> V_12 , L_1 ) ;
return V_7 ;
}
static int F_4 ( struct V_1 * V_2 , T_1 V_3 )
{
int V_13 ;
V_13 = F_1 ( V_2 , V_3 , false ) ;
if ( V_13 < 0 ) {
F_3 ( V_2 -> V_12 , L_2 ) ;
return V_13 ;
}
if ( V_2 -> V_8 == V_9 )
V_13 *= 1000 ;
else
V_13 = V_13 * 3570 / V_14 ;
return V_13 ;
}
static inline int F_5 ( struct V_1 * V_2 )
{
return F_4 ( V_2 , V_15 ) ;
}
static inline int F_6 ( struct V_1 * V_2 )
{
return F_4 ( V_2 , V_16 ) ;
}
static int F_7 ( struct V_1 * V_2 )
{
int V_17 ;
if ( V_2 -> V_8 == V_9 )
V_17 = F_1 ( V_2 , V_18 , false ) ;
else
V_17 = F_1 ( V_2 , V_19 , true ) ;
if ( V_17 < 0 ) {
F_3 ( V_2 -> V_12 , L_3 ) ;
return V_17 ;
}
if ( V_2 -> V_8 == V_9 )
V_17 *= 1000 ;
else
V_17 = V_17 * 256 * 3570 / V_14 ;
return V_17 ;
}
static int F_8 ( struct V_1 * V_2 )
{
int V_20 ;
V_20 = F_1 ( V_2 , V_21 , false ) ;
if ( V_20 < 0 )
F_3 ( V_2 -> V_12 , L_4 ) ;
return V_20 ;
}
static int F_9 ( struct V_1 * V_2 , T_1 V_3 )
{
int V_22 ;
V_22 = F_1 ( V_2 , V_3 , false ) ;
if ( V_22 < 0 ) {
F_3 ( V_2 -> V_12 , L_5 , V_3 , V_22 ) ;
return V_22 ;
}
if ( V_22 == 65535 )
return - V_23 ;
return V_22 * 60 ;
}
static void F_10 ( struct V_1 * V_2 )
{
struct V_24 V_25 = { 0 , } ;
bool V_26 = V_2 -> V_8 == V_9 ;
V_25 . V_27 = F_1 ( V_2 , V_28 , V_26 ) ;
if ( V_25 . V_27 >= 0 ) {
V_25 . V_29 = F_2 ( V_2 ) ;
V_25 . V_30 = F_1 ( V_2 , V_31 , false ) ;
V_25 . V_32 = F_9 ( V_2 , V_33 ) ;
V_25 . V_34 = F_9 ( V_2 , V_35 ) ;
V_25 . V_36 = F_9 ( V_2 , V_37 ) ;
V_25 . V_38 = F_6 ( V_2 ) ;
V_25 . V_39 = F_8 ( V_2 ) ;
if ( ! V_26 )
V_25 . V_40 = F_1 ( V_2 , V_41 , false ) ;
if ( V_2 -> V_42 <= 0 )
V_2 -> V_42 = F_7 ( V_2 ) ;
}
if ( memcmp ( & V_2 -> V_25 , & V_25 , sizeof( V_25 ) - sizeof( int ) ) != 0 ) {
V_2 -> V_25 = V_25 ;
F_11 ( & V_2 -> V_43 ) ;
}
V_2 -> V_44 = V_45 ;
}
static void F_12 ( struct V_46 * V_47 )
{
struct V_1 * V_2 =
F_13 ( V_47 , struct V_1 , V_47 . V_47 ) ;
F_10 ( V_2 ) ;
if ( V_48 > 0 ) {
F_14 ( & V_2 -> V_47 . V_49 , V_48 * V_50 / 4 ) ;
F_15 ( & V_2 -> V_47 , V_48 * V_50 ) ;
}
}
static int F_16 ( struct V_1 * V_2 ,
union V_51 * V_52 )
{
if ( V_2 -> V_25 . V_30 < 0 )
return V_2 -> V_25 . V_30 ;
if ( V_2 -> V_8 == V_9 )
V_52 -> V_53 = V_2 -> V_25 . V_30 - 2731 ;
else
V_52 -> V_53 = ( ( V_2 -> V_25 . V_30 * 5 ) - 5463 ) / 2 ;
return 0 ;
}
static int F_17 ( struct V_1 * V_2 ,
union V_51 * V_52 )
{
int V_54 ;
if ( V_2 -> V_8 == V_9 )
V_54 = F_1 ( V_2 , V_41 , false ) ;
else
V_54 = V_2 -> V_25 . V_40 ;
if ( V_54 < 0 )
return V_54 ;
if ( V_2 -> V_8 == V_9 ) {
V_52 -> V_53 = ( int ) ( ( V_55 ) V_54 ) * 1000 ;
} else {
if ( V_2 -> V_25 . V_27 & V_56 ) {
F_18 ( V_2 -> V_12 , L_6 ) ;
V_54 = - V_54 ;
}
V_52 -> V_53 = V_54 * 3570 / V_14 ;
}
return 0 ;
}
static int F_19 ( struct V_1 * V_2 ,
union V_51 * V_52 )
{
int V_57 ;
if ( V_2 -> V_8 == V_9 ) {
if ( V_2 -> V_25 . V_27 & V_58 )
V_57 = V_59 ;
else if ( V_2 -> V_25 . V_27 & V_60 )
V_57 = V_61 ;
else
V_57 = V_62 ;
} else {
if ( V_2 -> V_25 . V_27 & V_63 )
V_57 = V_59 ;
else if ( V_2 -> V_25 . V_27 & V_56 )
V_57 = V_62 ;
else if ( F_20 ( & V_2 -> V_43 ) )
V_57 = V_64 ;
else
V_57 = V_61 ;
}
V_52 -> V_53 = V_57 ;
return 0 ;
}
static int F_21 ( struct V_1 * V_2 ,
union V_51 * V_52 )
{
int V_65 ;
V_65 = F_1 ( V_2 , V_66 , false ) ;
if ( V_65 < 0 )
return V_65 ;
V_52 -> V_53 = V_65 * 1000 ;
return 0 ;
}
static int F_22 ( struct V_1 * V_2 ,
union V_51 * V_52 )
{
int V_67 ;
V_67 = F_1 ( V_2 , V_68 , false ) ;
if ( V_67 < 0 ) {
F_3 ( V_2 -> V_12 , L_7 ) ;
return V_67 ;
}
if ( V_2 -> V_8 == V_9 )
V_67 *= 1000 ;
else
V_67 = V_67 * 29200 / V_14 ;
V_52 -> V_53 = V_67 ;
return 0 ;
}
static int F_23 ( int V_69 ,
union V_51 * V_52 )
{
if ( V_69 < 0 )
return V_69 ;
V_52 -> V_53 = V_69 ;
return 0 ;
}
static int F_24 ( struct V_70 * V_71 ,
enum V_72 V_73 ,
union V_51 * V_52 )
{
int V_74 = 0 ;
struct V_1 * V_2 = F_25 ( V_71 ) ;
F_26 ( & V_2 -> V_75 ) ;
if ( F_27 ( V_2 -> V_44 + 5 * V_50 ) ) {
F_28 ( & V_2 -> V_47 ) ;
F_12 ( & V_2 -> V_47 . V_47 ) ;
}
F_29 ( & V_2 -> V_75 ) ;
if ( V_73 != V_76 && V_2 -> V_25 . V_27 < 0 )
return - V_77 ;
switch ( V_73 ) {
case V_78 :
V_74 = F_19 ( V_2 , V_52 ) ;
break;
case V_79 :
V_74 = F_21 ( V_2 , V_52 ) ;
break;
case V_76 :
V_52 -> V_53 = V_2 -> V_25 . V_27 < 0 ? 0 : 1 ;
break;
case V_80 :
V_74 = F_17 ( V_2 , V_52 ) ;
break;
case V_81 :
V_74 = F_23 ( V_2 -> V_25 . V_29 , V_52 ) ;
break;
case V_82 :
V_74 = F_16 ( V_2 , V_52 ) ;
break;
case V_83 :
V_74 = F_23 ( V_2 -> V_25 . V_32 , V_52 ) ;
break;
case V_84 :
V_74 = F_23 ( V_2 -> V_25 . V_34 , V_52 ) ;
break;
case V_85 :
V_74 = F_23 ( V_2 -> V_25 . V_36 , V_52 ) ;
break;
case V_86 :
V_52 -> V_53 = V_87 ;
break;
case V_88 :
V_74 = F_23 ( F_5 ( V_2 ) , V_52 ) ;
break;
case V_89 :
V_74 = F_23 ( V_2 -> V_25 . V_38 , V_52 ) ;
break;
case V_90 :
V_74 = F_23 ( V_2 -> V_42 , V_52 ) ;
break;
case V_91 :
V_74 = F_23 ( V_2 -> V_25 . V_39 , V_52 ) ;
break;
case V_92 :
V_74 = F_22 ( V_2 , V_52 ) ;
break;
default:
return - V_93 ;
}
return V_74 ;
}
static void F_30 ( struct V_70 * V_71 )
{
struct V_1 * V_2 = F_25 ( V_71 ) ;
F_28 ( & V_2 -> V_47 ) ;
F_15 ( & V_2 -> V_47 , 0 ) ;
}
static int F_31 ( struct V_1 * V_2 )
{
int V_74 ;
V_2 -> V_43 . type = V_94 ;
V_2 -> V_43 . V_95 = V_96 ;
V_2 -> V_43 . V_97 = F_32 ( V_96 ) ;
V_2 -> V_43 . V_98 = F_24 ;
V_2 -> V_43 . V_99 = F_30 ;
F_33 ( & V_2 -> V_47 , F_12 ) ;
F_34 ( & V_2 -> V_75 ) ;
V_74 = F_35 ( V_2 -> V_12 , & V_2 -> V_43 ) ;
if ( V_74 ) {
F_3 ( V_2 -> V_12 , L_8 , V_74 ) ;
return V_74 ;
}
F_36 ( V_2 -> V_12 , L_9 , V_100 ) ;
F_10 ( V_2 ) ;
return 0 ;
}
static void F_37 ( struct V_1 * V_2 )
{
F_28 ( & V_2 -> V_47 ) ;
F_38 ( & V_2 -> V_43 ) ;
F_39 ( & V_2 -> V_75 ) ;
}
static int F_40 ( struct V_1 * V_2 , T_1 V_3 , bool V_4 )
{
struct V_101 * V_102 = F_41 ( V_2 -> V_12 ) ;
struct V_103 V_104 [ 2 ] ;
unsigned char V_105 [ 2 ] ;
int V_74 ;
if ( ! V_102 -> V_106 )
return - V_77 ;
V_104 [ 0 ] . V_107 = V_102 -> V_107 ;
V_104 [ 0 ] . V_27 = 0 ;
V_104 [ 0 ] . V_108 = & V_3 ;
V_104 [ 0 ] . V_109 = sizeof( V_3 ) ;
V_104 [ 1 ] . V_107 = V_102 -> V_107 ;
V_104 [ 1 ] . V_27 = V_110 ;
V_104 [ 1 ] . V_108 = V_105 ;
if ( V_4 )
V_104 [ 1 ] . V_109 = 1 ;
else
V_104 [ 1 ] . V_109 = 2 ;
V_74 = F_42 ( V_102 -> V_106 , V_104 , F_32 ( V_104 ) ) ;
if ( V_74 < 0 )
return V_74 ;
if ( ! V_4 )
V_74 = F_43 ( V_105 ) ;
else
V_74 = V_105 [ 0 ] ;
return V_74 ;
}
static int F_44 ( struct V_101 * V_102 ,
const struct V_111 * V_112 )
{
char * V_113 ;
struct V_1 * V_2 ;
int V_114 ;
int V_115 = 0 ;
V_115 = F_45 ( & V_116 , V_117 ) ;
if ( V_115 == 0 )
return - V_118 ;
F_26 ( & V_119 ) ;
V_115 = F_46 ( & V_116 , V_102 , & V_114 ) ;
F_29 ( & V_119 ) ;
if ( V_115 < 0 )
return V_115 ;
V_113 = F_47 ( V_117 , L_10 , V_112 -> V_113 , V_114 ) ;
if ( ! V_113 ) {
F_3 ( & V_102 -> V_12 , L_11 ) ;
V_115 = - V_118 ;
goto V_120;
}
V_2 = F_48 ( sizeof( * V_2 ) , V_117 ) ;
if ( ! V_2 ) {
F_3 ( & V_102 -> V_12 , L_12 ) ;
V_115 = - V_118 ;
goto V_121;
}
V_2 -> V_112 = V_114 ;
V_2 -> V_12 = & V_102 -> V_12 ;
V_2 -> V_8 = V_112 -> V_122 ;
V_2 -> V_43 . V_113 = V_113 ;
V_2 -> V_5 . V_6 = & F_40 ;
if ( F_31 ( V_2 ) )
goto V_123;
F_49 ( V_102 , V_2 ) ;
return 0 ;
V_123:
F_50 ( V_2 ) ;
V_121:
F_50 ( V_113 ) ;
V_120:
F_26 ( & V_119 ) ;
F_51 ( & V_116 , V_114 ) ;
F_29 ( & V_119 ) ;
return V_115 ;
}
static int F_52 ( struct V_101 * V_102 )
{
struct V_1 * V_2 = F_53 ( V_102 ) ;
F_37 ( V_2 ) ;
F_50 ( V_2 -> V_43 . V_113 ) ;
F_26 ( & V_119 ) ;
F_51 ( & V_116 , V_2 -> V_112 ) ;
F_29 ( & V_119 ) ;
F_50 ( V_2 ) ;
return 0 ;
}
static inline int F_54 ( void )
{
int V_74 = F_55 ( & V_124 ) ;
if ( V_74 )
F_56 ( V_125 L_13 ) ;
return V_74 ;
}
static inline void F_57 ( void )
{
F_58 ( & V_124 ) ;
}
static inline int F_54 ( void ) { return 0 ; }
static inline void F_57 ( void ) {}
static int F_59 ( struct V_1 * V_2 , T_1 V_3 ,
bool V_4 )
{
struct V_126 * V_12 = V_2 -> V_12 ;
struct V_127 * V_128 = V_12 -> V_129 ;
unsigned int V_130 = 3 ;
int V_131 , V_132 ;
int V_133 ;
if ( ! V_4 ) {
V_131 = V_128 -> V_6 ( V_12 , V_3 + 1 ) ;
do {
V_133 = V_131 ;
if ( V_131 < 0 )
return V_131 ;
V_132 = V_128 -> V_6 ( V_12 , V_3 ) ;
if ( V_132 < 0 )
return V_132 ;
V_131 = V_128 -> V_6 ( V_12 , V_3 + 1 ) ;
} while ( V_133 != V_131 && -- V_130 );
if ( V_130 == 0 )
return - V_134 ;
return ( V_131 << 8 ) | V_132 ;
}
return V_128 -> V_6 ( V_12 , V_3 ) ;
}
static int T_2 F_60 ( struct V_135 * V_136 )
{
struct V_1 * V_2 ;
struct V_127 * V_128 = V_136 -> V_12 . V_129 ;
int V_74 ;
if ( ! V_128 ) {
F_3 ( & V_136 -> V_12 , L_14 ) ;
return - V_93 ;
}
if ( ! V_128 -> V_6 ) {
F_3 ( & V_136 -> V_12 , L_15 ) ;
return - V_93 ;
}
V_2 = F_48 ( sizeof( * V_2 ) , V_117 ) ;
if ( ! V_2 ) {
F_3 ( & V_136 -> V_12 , L_12 ) ;
return - V_118 ;
}
F_61 ( V_136 , V_2 ) ;
V_2 -> V_12 = & V_136 -> V_12 ;
V_2 -> V_8 = V_137 ;
V_2 -> V_43 . V_113 = V_128 -> V_113 ? : F_62 ( & V_136 -> V_12 ) ;
V_2 -> V_5 . V_6 = & F_59 ;
V_74 = F_31 ( V_2 ) ;
if ( V_74 )
goto V_138;
return 0 ;
V_138:
F_61 ( V_136 , NULL ) ;
F_50 ( V_2 ) ;
return V_74 ;
}
static int T_3 F_63 ( struct V_135 * V_136 )
{
struct V_1 * V_2 = F_64 ( V_136 ) ;
F_37 ( V_2 ) ;
F_61 ( V_136 , NULL ) ;
F_50 ( V_2 ) ;
return 0 ;
}
static inline int F_65 ( void )
{
int V_74 = F_66 ( & V_139 ) ;
if ( V_74 )
F_56 ( V_125 L_16 ) ;
return V_74 ;
}
static inline void F_67 ( void )
{
F_68 ( & V_139 ) ;
}
static inline int F_65 ( void ) { return 0 ; }
static inline void F_67 ( void ) {}
static int T_4 F_69 ( void )
{
int V_74 ;
V_74 = F_54 () ;
if ( V_74 )
return V_74 ;
V_74 = F_65 () ;
if ( V_74 )
F_57 () ;
return V_74 ;
}
static void T_5 F_70 ( void )
{
F_67 () ;
F_57 () ;
}
