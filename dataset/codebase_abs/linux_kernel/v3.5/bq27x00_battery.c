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
F_3 ( V_2 -> V_12 , L_2 ,
V_3 , V_13 ) ;
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
if ( V_20 < 0 ) {
F_3 ( V_2 -> V_12 , L_4 ) ;
return V_20 ;
}
if ( V_2 -> V_8 == V_9 )
V_20 *= 1000 ;
else
V_20 = V_20 * 29200 / V_14 ;
return V_20 ;
}
static int F_9 ( struct V_1 * V_2 )
{
int V_22 ;
V_22 = F_1 ( V_2 , V_23 , false ) ;
if ( V_22 < 0 ) {
F_10 ( V_2 -> V_12 , L_5 ) ;
return V_22 ;
}
if ( V_2 -> V_8 == V_9 )
V_22 -= 2731 ;
else
V_22 = ( ( V_22 * 5 ) - 5463 ) / 2 ;
return V_22 ;
}
static int F_11 ( struct V_1 * V_2 )
{
int V_24 ;
V_24 = F_1 ( V_2 , V_25 , false ) ;
if ( V_24 < 0 )
F_10 ( V_2 -> V_12 , L_6 ) ;
return V_24 ;
}
static int F_12 ( struct V_1 * V_2 , T_1 V_3 )
{
int V_26 ;
V_26 = F_1 ( V_2 , V_3 , false ) ;
if ( V_26 < 0 ) {
F_3 ( V_2 -> V_12 , L_7 ,
V_3 , V_26 ) ;
return V_26 ;
}
if ( V_26 == 65535 )
return - V_27 ;
return V_26 * 60 ;
}
static void F_13 ( struct V_1 * V_2 )
{
struct V_28 V_29 = { 0 , } ;
bool V_30 = V_2 -> V_8 == V_9 ;
V_29 . V_31 = F_1 ( V_2 , V_32 , ! V_30 ) ;
if ( V_29 . V_31 >= 0 ) {
if ( ! V_30 && ( V_29 . V_31 & V_33 ) ) {
F_14 ( V_2 -> V_12 , L_8 ) ;
V_29 . V_34 = - V_27 ;
V_29 . V_35 = - V_27 ;
V_29 . V_36 = - V_27 ;
V_29 . V_37 = - V_27 ;
V_29 . V_38 = - V_27 ;
V_29 . V_39 = - V_27 ;
} else {
V_29 . V_34 = F_2 ( V_2 ) ;
V_29 . V_35 = F_8 ( V_2 ) ;
V_29 . V_36 = F_12 ( V_2 , V_40 ) ;
V_29 . V_37 = F_12 ( V_2 , V_41 ) ;
V_29 . V_38 = F_12 ( V_2 , V_42 ) ;
V_29 . V_39 = F_6 ( V_2 ) ;
}
V_29 . V_43 = F_9 ( V_2 ) ;
V_29 . V_44 = F_11 ( V_2 ) ;
if ( V_2 -> V_45 <= 0 )
V_2 -> V_45 = F_7 ( V_2 ) ;
}
if ( memcmp ( & V_2 -> V_29 , & V_29 , sizeof( V_29 ) ) != 0 ) {
V_2 -> V_29 = V_29 ;
F_15 ( & V_2 -> V_46 ) ;
}
V_2 -> V_47 = V_48 ;
}
static void F_16 ( struct V_49 * V_50 )
{
struct V_1 * V_2 =
F_17 ( V_50 , struct V_1 , V_50 . V_50 ) ;
F_13 ( V_2 ) ;
if ( V_51 > 0 ) {
F_18 ( & V_2 -> V_50 . V_52 , V_51 * V_53 / 4 ) ;
F_19 ( & V_2 -> V_50 , V_51 * V_53 ) ;
}
}
static int F_20 ( struct V_1 * V_2 ,
union V_54 * V_55 )
{
int V_56 ;
int V_31 ;
V_56 = F_1 ( V_2 , V_57 , false ) ;
if ( V_56 < 0 ) {
F_10 ( V_2 -> V_12 , L_9 ) ;
return V_56 ;
}
if ( V_2 -> V_8 == V_9 ) {
V_55 -> V_58 = ( int ) ( ( V_59 ) V_56 ) * 1000 ;
} else {
V_31 = F_1 ( V_2 , V_32 , false ) ;
if ( V_31 & V_60 ) {
F_3 ( V_2 -> V_12 , L_10 ) ;
V_56 = - V_56 ;
}
V_55 -> V_58 = V_56 * 3570 / V_14 ;
}
return 0 ;
}
static int F_21 ( struct V_1 * V_2 ,
union V_54 * V_55 )
{
int V_61 ;
if ( V_2 -> V_8 == V_9 ) {
if ( V_2 -> V_29 . V_31 & V_62 )
V_61 = V_63 ;
else if ( V_2 -> V_29 . V_31 & V_64 )
V_61 = V_65 ;
else
V_61 = V_66 ;
} else {
if ( V_2 -> V_29 . V_31 & V_67 )
V_61 = V_63 ;
else if ( V_2 -> V_29 . V_31 & V_60 )
V_61 = V_66 ;
else if ( F_22 ( & V_2 -> V_46 ) )
V_61 = V_68 ;
else
V_61 = V_65 ;
}
V_55 -> V_58 = V_61 ;
return 0 ;
}
static int F_23 ( struct V_1 * V_2 ,
union V_54 * V_55 )
{
int V_69 ;
if ( V_2 -> V_8 == V_9 ) {
if ( V_2 -> V_29 . V_31 & V_62 )
V_69 = V_70 ;
else if ( V_2 -> V_29 . V_31 & V_71 )
V_69 = V_72 ;
else if ( V_2 -> V_29 . V_31 & V_73 )
V_69 = V_74 ;
else
V_69 = V_75 ;
} else {
if ( V_2 -> V_29 . V_31 & V_67 )
V_69 = V_70 ;
else if ( V_2 -> V_29 . V_31 & V_76 )
V_69 = V_72 ;
else if ( V_2 -> V_29 . V_31 & V_77 )
V_69 = V_74 ;
else
V_69 = V_75 ;
}
V_55 -> V_58 = V_69 ;
return 0 ;
}
static int F_24 ( struct V_1 * V_2 ,
union V_54 * V_55 )
{
int V_78 ;
V_78 = F_1 ( V_2 , V_79 , false ) ;
if ( V_78 < 0 ) {
F_10 ( V_2 -> V_12 , L_11 ) ;
return V_78 ;
}
V_55 -> V_58 = V_78 * 1000 ;
return 0 ;
}
static int F_25 ( int V_80 ,
union V_54 * V_55 )
{
if ( V_80 < 0 )
return V_80 ;
V_55 -> V_58 = V_80 ;
return 0 ;
}
static int F_26 ( struct V_81 * V_82 ,
enum V_83 V_84 ,
union V_54 * V_55 )
{
int V_85 = 0 ;
struct V_1 * V_2 = F_27 ( V_82 ) ;
F_28 ( & V_2 -> V_86 ) ;
if ( F_29 ( V_2 -> V_47 + 5 * V_53 ) ) {
F_30 ( & V_2 -> V_50 ) ;
F_16 ( & V_2 -> V_50 . V_50 ) ;
}
F_31 ( & V_2 -> V_86 ) ;
if ( V_84 != V_87 && V_2 -> V_29 . V_31 < 0 )
return - V_88 ;
switch ( V_84 ) {
case V_89 :
V_85 = F_21 ( V_2 , V_55 ) ;
break;
case V_90 :
V_85 = F_24 ( V_2 , V_55 ) ;
break;
case V_87 :
V_55 -> V_58 = V_2 -> V_29 . V_31 < 0 ? 0 : 1 ;
break;
case V_91 :
V_85 = F_20 ( V_2 , V_55 ) ;
break;
case V_92 :
V_85 = F_25 ( V_2 -> V_29 . V_34 , V_55 ) ;
break;
case V_93 :
V_85 = F_23 ( V_2 , V_55 ) ;
break;
case V_94 :
V_85 = F_25 ( V_2 -> V_29 . V_43 , V_55 ) ;
break;
case V_95 :
V_85 = F_25 ( V_2 -> V_29 . V_36 , V_55 ) ;
break;
case V_96 :
V_85 = F_25 ( V_2 -> V_29 . V_37 , V_55 ) ;
break;
case V_97 :
V_85 = F_25 ( V_2 -> V_29 . V_38 , V_55 ) ;
break;
case V_98 :
V_55 -> V_58 = V_99 ;
break;
case V_100 :
V_85 = F_25 ( F_5 ( V_2 ) , V_55 ) ;
break;
case V_101 :
V_85 = F_25 ( V_2 -> V_29 . V_39 , V_55 ) ;
break;
case V_102 :
V_85 = F_25 ( V_2 -> V_45 , V_55 ) ;
break;
case V_103 :
V_85 = F_25 ( V_2 -> V_29 . V_44 , V_55 ) ;
break;
case V_104 :
V_85 = F_25 ( V_2 -> V_29 . V_35 , V_55 ) ;
break;
default:
return - V_105 ;
}
return V_85 ;
}
static void F_32 ( struct V_81 * V_82 )
{
struct V_1 * V_2 = F_27 ( V_82 ) ;
F_30 ( & V_2 -> V_50 ) ;
F_19 ( & V_2 -> V_50 , 0 ) ;
}
static int F_33 ( struct V_1 * V_2 )
{
int V_85 ;
V_2 -> V_46 . type = V_106 ;
V_2 -> V_46 . V_107 = V_108 ;
V_2 -> V_46 . V_109 = F_34 ( V_108 ) ;
V_2 -> V_46 . V_110 = F_26 ;
V_2 -> V_46 . V_111 = F_32 ;
F_35 ( & V_2 -> V_50 , F_16 ) ;
F_36 ( & V_2 -> V_86 ) ;
V_85 = F_37 ( V_2 -> V_12 , & V_2 -> V_46 ) ;
if ( V_85 ) {
F_10 ( V_2 -> V_12 , L_12 , V_85 ) ;
return V_85 ;
}
F_14 ( V_2 -> V_12 , L_13 , V_112 ) ;
F_13 ( V_2 ) ;
return 0 ;
}
static void F_38 ( struct V_1 * V_2 )
{
V_51 = 0 ;
F_30 ( & V_2 -> V_50 ) ;
F_39 ( & V_2 -> V_46 ) ;
F_40 ( & V_2 -> V_86 ) ;
}
static int F_41 ( struct V_1 * V_2 , T_1 V_3 , bool V_4 )
{
struct V_113 * V_114 = F_42 ( V_2 -> V_12 ) ;
struct V_115 V_116 [ 2 ] ;
unsigned char V_117 [ 2 ] ;
int V_85 ;
if ( ! V_114 -> V_118 )
return - V_88 ;
V_116 [ 0 ] . V_119 = V_114 -> V_119 ;
V_116 [ 0 ] . V_31 = 0 ;
V_116 [ 0 ] . V_120 = & V_3 ;
V_116 [ 0 ] . V_121 = sizeof( V_3 ) ;
V_116 [ 1 ] . V_119 = V_114 -> V_119 ;
V_116 [ 1 ] . V_31 = V_122 ;
V_116 [ 1 ] . V_120 = V_117 ;
if ( V_4 )
V_116 [ 1 ] . V_121 = 1 ;
else
V_116 [ 1 ] . V_121 = 2 ;
V_85 = F_43 ( V_114 -> V_118 , V_116 , F_34 ( V_116 ) ) ;
if ( V_85 < 0 )
return V_85 ;
if ( ! V_4 )
V_85 = F_44 ( V_117 ) ;
else
V_85 = V_117 [ 0 ] ;
return V_85 ;
}
static int F_45 ( struct V_113 * V_114 ,
const struct V_123 * V_124 )
{
char * V_125 ;
struct V_1 * V_2 ;
int V_126 ;
int V_127 = 0 ;
V_127 = F_46 ( & V_128 , V_129 ) ;
if ( V_127 == 0 )
return - V_130 ;
F_28 ( & V_131 ) ;
V_127 = F_47 ( & V_128 , V_114 , & V_126 ) ;
F_31 ( & V_131 ) ;
if ( V_127 < 0 )
return V_127 ;
V_125 = F_48 ( V_129 , L_14 , V_124 -> V_125 , V_126 ) ;
if ( ! V_125 ) {
F_10 ( & V_114 -> V_12 , L_15 ) ;
V_127 = - V_130 ;
goto V_132;
}
V_2 = F_49 ( sizeof( * V_2 ) , V_129 ) ;
if ( ! V_2 ) {
F_10 ( & V_114 -> V_12 , L_16 ) ;
V_127 = - V_130 ;
goto V_133;
}
V_2 -> V_124 = V_126 ;
V_2 -> V_12 = & V_114 -> V_12 ;
V_2 -> V_8 = V_124 -> V_134 ;
V_2 -> V_46 . V_125 = V_125 ;
V_2 -> V_5 . V_6 = & F_41 ;
if ( F_33 ( V_2 ) )
goto V_135;
F_50 ( V_114 , V_2 ) ;
return 0 ;
V_135:
F_51 ( V_2 ) ;
V_133:
F_51 ( V_125 ) ;
V_132:
F_28 ( & V_131 ) ;
F_52 ( & V_128 , V_126 ) ;
F_31 ( & V_131 ) ;
return V_127 ;
}
static int F_53 ( struct V_113 * V_114 )
{
struct V_1 * V_2 = F_54 ( V_114 ) ;
F_38 ( V_2 ) ;
F_51 ( V_2 -> V_46 . V_125 ) ;
F_28 ( & V_131 ) ;
F_52 ( & V_128 , V_2 -> V_124 ) ;
F_31 ( & V_131 ) ;
F_51 ( V_2 ) ;
return 0 ;
}
static inline int F_55 ( void )
{
int V_85 = F_56 ( & V_136 ) ;
if ( V_85 )
F_57 ( V_137 L_17 ) ;
return V_85 ;
}
static inline void F_58 ( void )
{
F_59 ( & V_136 ) ;
}
static inline int F_55 ( void ) { return 0 ; }
static inline void F_58 ( void ) {}
static int F_60 ( struct V_1 * V_2 , T_1 V_3 ,
bool V_4 )
{
struct V_138 * V_12 = V_2 -> V_12 ;
struct V_139 * V_140 = V_12 -> V_141 ;
unsigned int V_142 = 3 ;
int V_143 , V_144 ;
int V_22 ;
if ( ! V_4 ) {
V_143 = V_140 -> V_6 ( V_12 , V_3 + 1 ) ;
do {
V_22 = V_143 ;
if ( V_143 < 0 )
return V_143 ;
V_144 = V_140 -> V_6 ( V_12 , V_3 ) ;
if ( V_144 < 0 )
return V_144 ;
V_143 = V_140 -> V_6 ( V_12 , V_3 + 1 ) ;
} while ( V_22 != V_143 && -- V_142 );
if ( V_142 == 0 )
return - V_145 ;
return ( V_143 << 8 ) | V_144 ;
}
return V_140 -> V_6 ( V_12 , V_3 ) ;
}
static int T_2 F_61 ( struct V_146 * V_147 )
{
struct V_1 * V_2 ;
struct V_139 * V_140 = V_147 -> V_12 . V_141 ;
int V_85 ;
if ( ! V_140 ) {
F_10 ( & V_147 -> V_12 , L_18 ) ;
return - V_105 ;
}
if ( ! V_140 -> V_6 ) {
F_10 ( & V_147 -> V_12 , L_19 ) ;
return - V_105 ;
}
V_2 = F_49 ( sizeof( * V_2 ) , V_129 ) ;
if ( ! V_2 ) {
F_10 ( & V_147 -> V_12 , L_16 ) ;
return - V_130 ;
}
F_62 ( V_147 , V_2 ) ;
V_2 -> V_12 = & V_147 -> V_12 ;
V_2 -> V_8 = V_148 ;
V_2 -> V_46 . V_125 = V_140 -> V_125 ? : F_63 ( & V_147 -> V_12 ) ;
V_2 -> V_5 . V_6 = & F_60 ;
V_85 = F_33 ( V_2 ) ;
if ( V_85 )
goto V_149;
return 0 ;
V_149:
F_62 ( V_147 , NULL ) ;
F_51 ( V_2 ) ;
return V_85 ;
}
static int T_3 F_64 ( struct V_146 * V_147 )
{
struct V_1 * V_2 = F_65 ( V_147 ) ;
F_38 ( V_2 ) ;
F_62 ( V_147 , NULL ) ;
F_51 ( V_2 ) ;
return 0 ;
}
static inline int F_66 ( void )
{
int V_85 = F_67 ( & V_150 ) ;
if ( V_85 )
F_57 ( V_137 L_20 ) ;
return V_85 ;
}
static inline void F_68 ( void )
{
F_69 ( & V_150 ) ;
}
static inline int F_66 ( void ) { return 0 ; }
static inline void F_68 ( void ) {}
static int T_4 F_70 ( void )
{
int V_85 ;
V_85 = F_55 () ;
if ( V_85 )
return V_85 ;
V_85 = F_66 () ;
if ( V_85 )
F_58 () ;
return V_85 ;
}
static void T_5 F_71 ( void )
{
F_68 () ;
F_58 () ;
}
