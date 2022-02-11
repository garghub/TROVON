static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_4 ) ;
}
static T_1 F_3 ( int V_5 , void * V_6 )
{
#ifdef F_4
struct V_7 * V_8 = V_6 ;
if ( V_9 ) {
...
F_5 ( & V_8 -> V_10 ) ;
F_6 ( & V_11 -> V_12 ) ;
F_7 ( & V_8 -> V_10 ) ;
F_8 ( & V_11 -> V_4 . V_13 . V_14 ) ;
V_11 -> V_4 . V_13 . V_15 = V_8 -> V_15 ++ ;
V_11 -> V_4 . V_13 . V_16 = V_8 -> V_16 ;
if ( V_8 -> V_17 . V_16 == V_18 ) {
if ( V_8 -> V_16 == V_19 )
V_8 -> V_16 = V_20 ;
else if ( V_8 -> V_16 == V_20 )
V_8 -> V_16 = V_19 ;
}
F_9 ( & V_11 -> V_4 , V_21 ) ;
}
#endif
return V_22 ;
}
static int F_10 ( struct V_23 * V_24 , const void * V_25 ,
unsigned int * V_26 , unsigned int * V_27 ,
unsigned int V_28 [] , void * V_29 [] )
{
const struct V_30 * V_31 = V_25 ;
struct V_7 * V_8 = F_11 ( V_24 ) ;
V_8 -> V_16 = V_8 -> V_17 . V_16 ;
if ( V_8 -> V_16 == V_18 ) {
if ( F_12 ( V_24 ) )
return - V_32 ;
V_8 -> V_16 = V_20 ;
}
if ( V_24 -> V_33 + * V_26 < 3 )
* V_26 = 3 - V_24 -> V_33 ;
if ( V_31 && V_31 -> V_31 . V_34 . V_35 < V_8 -> V_17 . V_35 )
return - V_32 ;
* V_27 = 1 ;
V_28 [ 0 ] = V_31 ? V_31 -> V_31 . V_34 . V_35 : V_8 -> V_17 . V_35 ;
V_29 [ 0 ] = V_8 -> V_36 ;
return 0 ;
}
static int F_13 ( struct V_2 * V_4 )
{
struct V_7 * V_8 = F_11 ( V_4 -> V_23 ) ;
unsigned long V_37 = V_8 -> V_17 . V_35 ;
if ( F_14 ( V_4 , 0 ) < V_37 ) {
F_15 ( & V_8 -> V_38 -> V_39 , L_1 ,
F_14 ( V_4 , 0 ) , V_37 ) ;
return - V_32 ;
}
F_16 ( V_4 , 0 , V_37 ) ;
return 0 ;
}
static void F_17 ( struct V_2 * V_4 )
{
struct V_7 * V_8 = F_11 ( V_4 -> V_23 ) ;
struct V_1 * V_40 = F_1 ( V_4 ) ;
unsigned long V_41 ;
F_18 ( & V_8 -> V_10 , V_41 ) ;
F_19 ( & V_40 -> V_12 , & V_8 -> V_42 ) ;
F_20 ( & V_8 -> V_10 , V_41 ) ;
}
static void F_21 ( struct V_7 * V_8 ,
enum V_43 V_44 )
{
struct V_1 * V_40 , * V_45 ;
unsigned long V_41 ;
F_18 ( & V_8 -> V_10 , V_41 ) ;
F_22 (buf, node, &skel->buf_list, list) {
F_9 ( & V_40 -> V_4 , V_44 ) ;
F_6 ( & V_40 -> V_12 ) ;
}
F_20 ( & V_8 -> V_10 , V_41 ) ;
}
static int F_23 ( struct V_23 * V_24 , unsigned int V_46 )
{
struct V_7 * V_8 = F_11 ( V_24 ) ;
int V_47 = 0 ;
V_8 -> V_15 = 0 ;
if ( V_47 ) {
F_21 ( V_8 , V_48 ) ;
}
return V_47 ;
}
static void F_24 ( struct V_23 * V_24 )
{
struct V_7 * V_8 = F_11 ( V_24 ) ;
F_21 ( V_8 , V_49 ) ;
}
static int F_25 ( struct V_50 * V_50 , void * V_51 ,
struct V_52 * V_53 )
{
struct V_7 * V_8 = F_26 ( V_50 ) ;
F_27 ( V_53 -> V_54 , V_55 , sizeof( V_53 -> V_54 ) ) ;
F_27 ( V_53 -> V_56 , L_2 , sizeof( V_53 -> V_56 ) ) ;
snprintf ( V_53 -> V_57 , sizeof( V_53 -> V_57 ) , L_3 ,
F_28 ( V_8 -> V_38 ) ) ;
V_53 -> V_58 = V_59 | V_60 |
V_61 ;
V_53 -> V_62 = V_53 -> V_58 | V_63 ;
return 0 ;
}
static void F_29 ( struct V_7 * V_8 ,
struct V_64 * V_34 )
{
V_34 -> V_65 = V_66 ;
if ( V_8 -> V_67 == 0 ) {
V_34 -> V_68 = 720 ;
V_34 -> V_69 = ( V_8 -> V_70 & V_71 ) ? 480 : 576 ;
V_34 -> V_16 = V_72 ;
V_34 -> V_73 = V_74 ;
} else {
V_34 -> V_68 = V_8 -> V_75 . V_76 . V_68 ;
V_34 -> V_69 = V_8 -> V_75 . V_76 . V_69 ;
if ( V_8 -> V_75 . V_76 . V_77 ) {
V_34 -> V_16 = V_18 ;
V_34 -> V_69 /= 2 ;
} else {
V_34 -> V_16 = V_78 ;
}
V_34 -> V_73 = V_79 ;
}
V_34 -> V_80 = V_34 -> V_68 * 2 ;
V_34 -> V_35 = V_34 -> V_80 * V_34 -> V_69 ;
V_34 -> V_51 = 0 ;
}
static int F_30 ( struct V_50 * V_50 , void * V_51 ,
struct V_30 * V_81 )
{
struct V_7 * V_8 = F_26 ( V_50 ) ;
struct V_64 * V_34 = & V_81 -> V_31 . V_34 ;
if ( V_34 -> V_65 != V_66 )
return - V_32 ;
F_29 ( V_8 , V_34 ) ;
return 0 ;
}
static int F_31 ( struct V_50 * V_50 , void * V_51 ,
struct V_30 * V_81 )
{
struct V_7 * V_8 = F_26 ( V_50 ) ;
int V_47 ;
V_47 = F_30 ( V_50 , V_51 , V_81 ) ;
if ( V_47 )
return V_47 ;
if ( F_32 ( & V_8 -> V_82 ) )
return - V_83 ;
V_8 -> V_17 = V_81 -> V_31 . V_34 ;
return 0 ;
}
static int F_33 ( struct V_50 * V_50 , void * V_51 ,
struct V_30 * V_81 )
{
struct V_7 * V_8 = F_26 ( V_50 ) ;
V_81 -> V_31 . V_34 = V_8 -> V_17 ;
return 0 ;
}
static int F_34 ( struct V_50 * V_50 , void * V_51 ,
struct V_84 * V_81 )
{
if ( V_81 -> V_85 != 0 )
return - V_32 ;
V_81 -> V_65 = V_66 ;
return 0 ;
}
static int F_35 ( struct V_50 * V_50 , void * V_51 , T_2 V_70 )
{
struct V_7 * V_8 = F_26 ( V_50 ) ;
if ( V_8 -> V_67 )
return - V_86 ;
if ( V_70 == V_8 -> V_70 )
return 0 ;
if ( F_32 ( & V_8 -> V_82 ) )
return - V_83 ;
V_8 -> V_70 = V_70 ;
F_29 ( V_8 , & V_8 -> V_17 ) ;
return 0 ;
}
static int F_36 ( struct V_50 * V_50 , void * V_51 , T_2 * V_70 )
{
struct V_7 * V_8 = F_26 ( V_50 ) ;
if ( V_8 -> V_67 )
return - V_86 ;
* V_70 = V_8 -> V_70 ;
return 0 ;
}
static int F_37 ( struct V_50 * V_50 , void * V_51 , T_2 * V_70 )
{
struct V_7 * V_8 = F_26 ( V_50 ) ;
if ( V_8 -> V_67 )
return - V_86 ;
#ifdef F_4
F_38 () ;
if ( V_87 ) {
* V_70 = 0 ;
return 0 ;
}
if ( V_88 )
* V_70 &= V_71 ;
else
* V_70 &= V_89 ;
#endif
return 0 ;
}
static int F_39 ( struct V_50 * V_50 , void * V_90 ,
struct V_91 * V_75 )
{
struct V_7 * V_8 = F_26 ( V_50 ) ;
if ( V_8 -> V_67 == 0 )
return - V_86 ;
if ( ! F_40 ( V_75 , & V_92 , NULL , NULL ) )
return - V_32 ;
if ( ! F_41 ( V_75 , & V_92 ,
0 , NULL , NULL ) )
return - V_32 ;
if ( F_42 ( V_75 , & V_8 -> V_75 , 0 ) )
return 0 ;
if ( F_32 ( & V_8 -> V_82 ) )
return - V_83 ;
V_8 -> V_75 = * V_75 ;
F_29 ( V_8 , & V_8 -> V_17 ) ;
return 0 ;
}
static int F_43 ( struct V_50 * V_50 , void * V_90 ,
struct V_91 * V_75 )
{
struct V_7 * V_8 = F_26 ( V_50 ) ;
if ( V_8 -> V_67 == 0 )
return - V_86 ;
* V_75 = V_8 -> V_75 ;
return 0 ;
}
static int F_44 ( struct V_50 * V_50 , void * V_90 ,
struct V_93 * V_75 )
{
struct V_7 * V_8 = F_26 ( V_50 ) ;
if ( V_8 -> V_67 == 0 )
return - V_86 ;
return F_45 ( V_75 , & V_92 ,
NULL , NULL ) ;
}
static int F_46 ( struct V_50 * V_50 , void * V_90 ,
struct V_91 * V_75 )
{
struct V_7 * V_8 = F_26 ( V_50 ) ;
if ( V_8 -> V_67 == 0 )
return - V_86 ;
#ifdef F_4
F_47 () ;
if ( V_87 )
return - V_94 ;
if ( V_95 )
return - V_96 ;
if ( V_97 )
return - V_98 ;
F_48 ( V_8 -> V_99 . V_100 , L_4 ,
V_75 , true ) ;
#endif
return 0 ;
}
static int F_49 ( struct V_50 * V_50 , void * V_101 ,
struct V_102 * V_53 )
{
struct V_7 * V_8 = F_26 ( V_50 ) ;
if ( V_8 -> V_67 == 0 )
return - V_86 ;
* V_53 = V_92 ;
return 0 ;
}
static int F_50 ( struct V_50 * V_50 , void * V_51 ,
struct V_103 * V_104 )
{
if ( V_104 -> V_85 > 1 )
return - V_32 ;
V_104 -> type = V_105 ;
if ( V_104 -> V_85 == 0 ) {
V_104 -> V_70 = V_106 ;
F_27 ( V_104 -> V_100 , L_5 , sizeof( V_104 -> V_100 ) ) ;
V_104 -> V_62 = V_107 ;
} else {
V_104 -> V_70 = 0 ;
F_27 ( V_104 -> V_100 , L_6 , sizeof( V_104 -> V_100 ) ) ;
V_104 -> V_62 = V_108 ;
}
return 0 ;
}
static int F_51 ( struct V_50 * V_50 , void * V_51 , unsigned int V_104 )
{
struct V_7 * V_8 = F_26 ( V_50 ) ;
if ( V_104 > 1 )
return - V_32 ;
if ( F_32 ( & V_8 -> V_82 ) )
return - V_83 ;
V_8 -> V_67 = V_104 ;
V_8 -> V_109 . V_110 = V_104 ? 0 : V_106 ;
F_29 ( V_8 , & V_8 -> V_17 ) ;
return 0 ;
}
static int F_52 ( struct V_50 * V_50 , void * V_51 , unsigned int * V_104 )
{
struct V_7 * V_8 = F_26 ( V_50 ) ;
* V_104 = V_8 -> V_67 ;
return 0 ;
}
static int F_53 ( struct V_111 * V_112 )
{
switch ( V_112 -> V_113 ) {
case V_114 :
break;
case V_115 :
break;
case V_116 :
break;
case V_117 :
break;
default:
return - V_32 ;
}
return 0 ;
}
static int F_54 ( struct V_118 * V_38 , const struct V_119 * V_120 )
{
static const struct V_91 V_121 =
V_122 ;
struct V_7 * V_8 ;
struct V_123 * V_109 ;
struct V_124 * V_125 ;
struct V_23 * V_126 ;
int V_47 ;
V_47 = F_55 ( V_38 ) ;
if ( V_47 )
return V_47 ;
V_47 = F_56 ( V_38 , F_57 ( 32 ) ) ;
if ( V_47 ) {
F_15 ( & V_38 -> V_39 , L_7 ) ;
goto V_127;
}
V_8 = F_58 ( & V_38 -> V_39 , sizeof( struct V_7 ) , V_128 ) ;
if ( ! V_8 )
return - V_129 ;
V_47 = F_59 ( & V_38 -> V_39 , V_38 -> V_5 ,
F_3 , 0 , V_55 , V_8 ) ;
if ( V_47 ) {
F_15 ( & V_38 -> V_39 , L_8 ) ;
goto V_127;
}
V_8 -> V_38 = V_38 ;
V_8 -> V_75 = V_121 ;
V_8 -> V_70 = V_89 ;
F_29 ( V_8 , & V_8 -> V_17 ) ;
V_47 = F_60 ( & V_38 -> V_39 , & V_8 -> V_99 ) ;
if ( V_47 )
goto V_127;
F_61 ( & V_8 -> V_130 ) ;
V_125 = & V_8 -> V_131 ;
F_62 ( V_125 , 4 ) ;
F_63 ( V_125 , & V_132 ,
V_114 , 0 , 255 , 1 , 127 ) ;
F_63 ( V_125 , & V_132 ,
V_115 , 0 , 255 , 1 , 16 ) ;
F_63 ( V_125 , & V_132 ,
V_116 , 0 , 255 , 1 , 127 ) ;
F_63 ( V_125 , & V_132 ,
V_117 , - 128 , 127 , 1 , 0 ) ;
if ( V_125 -> error ) {
V_47 = V_125 -> error ;
goto V_133;
}
V_8 -> V_99 . V_131 = V_125 ;
V_126 = & V_8 -> V_82 ;
V_126 -> type = V_134 ;
V_126 -> V_135 = V_136 | V_137 | V_138 ;
V_126 -> V_139 = V_8 ;
V_126 -> V_140 = sizeof( struct V_1 ) ;
V_126 -> V_141 = & V_142 ;
V_126 -> V_143 = & V_144 ;
V_126 -> V_145 = V_146 ;
V_126 -> V_147 = 2 ;
V_126 -> V_130 = & V_8 -> V_130 ;
V_126 -> V_148 = V_149 ;
V_47 = F_64 ( V_126 ) ;
if ( V_47 )
goto V_133;
V_8 -> V_36 = F_65 ( & V_38 -> V_39 ) ;
if ( F_66 ( V_8 -> V_36 ) ) {
F_15 ( & V_38 -> V_39 , L_9 ) ;
V_47 = F_67 ( V_8 -> V_36 ) ;
goto V_133;
}
F_68 ( & V_8 -> V_42 ) ;
F_69 ( & V_8 -> V_10 ) ;
V_109 = & V_8 -> V_109 ;
F_27 ( V_109 -> V_100 , V_55 , sizeof( V_109 -> V_100 ) ) ;
V_109 -> V_150 = V_151 ;
V_109 -> V_152 = & V_153 ,
V_109 -> V_154 = & V_155 ,
V_109 -> V_130 = & V_8 -> V_130 ;
V_109 -> V_82 = V_126 ;
V_109 -> V_99 = & V_8 -> V_99 ;
V_109 -> V_110 = V_106 ;
F_70 ( V_109 , V_8 ) ;
V_47 = F_71 ( V_109 , V_156 , - 1 ) ;
if ( V_47 )
goto V_157;
F_72 ( & V_38 -> V_39 , L_10 ) ;
return 0 ;
V_157:
F_73 ( V_8 -> V_36 ) ;
V_133:
F_74 ( & V_8 -> V_131 ) ;
F_75 ( & V_8 -> V_99 ) ;
V_127:
F_76 ( V_38 ) ;
return V_47 ;
}
static void F_77 ( struct V_118 * V_38 )
{
struct V_158 * V_99 = F_78 ( V_38 ) ;
struct V_7 * V_8 = F_2 ( V_99 , struct V_7 , V_99 ) ;
F_79 ( & V_8 -> V_109 ) ;
F_74 ( & V_8 -> V_131 ) ;
F_73 ( V_8 -> V_36 ) ;
F_75 ( & V_8 -> V_99 ) ;
F_76 ( V_8 -> V_38 ) ;
}
