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
static int F_10 ( struct V_23 * V_24 , const struct V_25 * V_26 ,
unsigned int * V_27 , unsigned int * V_28 ,
unsigned int V_29 [] , void * V_30 [] )
{
struct V_7 * V_8 = F_11 ( V_24 ) ;
V_8 -> V_16 = V_8 -> V_17 . V_16 ;
if ( V_8 -> V_16 == V_18 ) {
if ( F_12 ( V_24 ) )
return - V_31 ;
V_8 -> V_16 = V_20 ;
}
if ( V_24 -> V_32 + * V_27 < 3 )
* V_27 = 3 - V_24 -> V_32 ;
if ( V_26 && V_26 -> V_26 . V_33 . V_34 < V_8 -> V_17 . V_34 )
return - V_31 ;
* V_28 = 1 ;
V_29 [ 0 ] = V_26 ? V_26 -> V_26 . V_33 . V_34 : V_8 -> V_17 . V_34 ;
V_30 [ 0 ] = V_8 -> V_35 ;
return 0 ;
}
static int F_13 ( struct V_2 * V_4 )
{
struct V_7 * V_8 = F_11 ( V_4 -> V_23 ) ;
unsigned long V_36 = V_8 -> V_17 . V_34 ;
if ( F_14 ( V_4 , 0 ) < V_36 ) {
F_15 ( & V_8 -> V_37 -> V_38 , L_1 ,
F_14 ( V_4 , 0 ) , V_36 ) ;
return - V_31 ;
}
F_16 ( V_4 , 0 , V_36 ) ;
return 0 ;
}
static void F_17 ( struct V_2 * V_4 )
{
struct V_7 * V_8 = F_11 ( V_4 -> V_23 ) ;
struct V_1 * V_39 = F_1 ( V_4 ) ;
unsigned long V_40 ;
F_18 ( & V_8 -> V_10 , V_40 ) ;
F_19 ( & V_39 -> V_12 , & V_8 -> V_41 ) ;
F_20 ( & V_8 -> V_10 , V_40 ) ;
}
static void F_21 ( struct V_7 * V_8 ,
enum V_42 V_43 )
{
struct V_1 * V_39 , * V_44 ;
unsigned long V_40 ;
F_18 ( & V_8 -> V_10 , V_40 ) ;
F_22 (buf, node, &skel->buf_list, list) {
F_9 ( & V_39 -> V_4 , V_43 ) ;
F_6 ( & V_39 -> V_12 ) ;
}
F_20 ( & V_8 -> V_10 , V_40 ) ;
}
static int F_23 ( struct V_23 * V_24 , unsigned int V_45 )
{
struct V_7 * V_8 = F_11 ( V_24 ) ;
int V_46 = 0 ;
V_8 -> V_15 = 0 ;
if ( V_46 ) {
F_21 ( V_8 , V_47 ) ;
}
return V_46 ;
}
static void F_24 ( struct V_23 * V_24 )
{
struct V_7 * V_8 = F_11 ( V_24 ) ;
F_21 ( V_8 , V_48 ) ;
}
static int F_25 ( struct V_49 * V_49 , void * V_50 ,
struct V_51 * V_52 )
{
struct V_7 * V_8 = F_26 ( V_49 ) ;
F_27 ( V_52 -> V_53 , V_54 , sizeof( V_52 -> V_53 ) ) ;
F_27 ( V_52 -> V_55 , L_2 , sizeof( V_52 -> V_55 ) ) ;
snprintf ( V_52 -> V_56 , sizeof( V_52 -> V_56 ) , L_3 ,
F_28 ( V_8 -> V_37 ) ) ;
V_52 -> V_57 = V_58 | V_59 |
V_60 ;
V_52 -> V_61 = V_52 -> V_57 | V_62 ;
return 0 ;
}
static void F_29 ( struct V_7 * V_8 ,
struct V_63 * V_33 )
{
V_33 -> V_64 = V_65 ;
if ( V_8 -> V_66 == 0 ) {
V_33 -> V_67 = 720 ;
V_33 -> V_68 = ( V_8 -> V_69 & V_70 ) ? 480 : 576 ;
V_33 -> V_16 = V_71 ;
V_33 -> V_72 = V_73 ;
} else {
V_33 -> V_67 = V_8 -> V_74 . V_75 . V_67 ;
V_33 -> V_68 = V_8 -> V_74 . V_75 . V_68 ;
if ( V_8 -> V_74 . V_75 . V_76 ) {
V_33 -> V_16 = V_18 ;
V_33 -> V_68 /= 2 ;
} else {
V_33 -> V_16 = V_77 ;
}
V_33 -> V_72 = V_78 ;
}
V_33 -> V_79 = V_33 -> V_67 * 2 ;
V_33 -> V_34 = V_33 -> V_79 * V_33 -> V_68 ;
V_33 -> V_50 = 0 ;
}
static int F_30 ( struct V_49 * V_49 , void * V_50 ,
struct V_25 * V_80 )
{
struct V_7 * V_8 = F_26 ( V_49 ) ;
struct V_63 * V_33 = & V_80 -> V_26 . V_33 ;
if ( V_33 -> V_64 != V_65 )
return - V_31 ;
F_29 ( V_8 , V_33 ) ;
return 0 ;
}
static int F_31 ( struct V_49 * V_49 , void * V_50 ,
struct V_25 * V_80 )
{
struct V_7 * V_8 = F_26 ( V_49 ) ;
int V_46 ;
V_46 = F_30 ( V_49 , V_50 , V_80 ) ;
if ( V_46 )
return V_46 ;
if ( F_32 ( & V_8 -> V_81 ) )
return - V_82 ;
V_8 -> V_17 = V_80 -> V_26 . V_33 ;
return 0 ;
}
static int F_33 ( struct V_49 * V_49 , void * V_50 ,
struct V_25 * V_80 )
{
struct V_7 * V_8 = F_26 ( V_49 ) ;
V_80 -> V_26 . V_33 = V_8 -> V_17 ;
return 0 ;
}
static int F_34 ( struct V_49 * V_49 , void * V_50 ,
struct V_83 * V_80 )
{
if ( V_80 -> V_84 != 0 )
return - V_31 ;
F_27 ( V_80 -> V_85 , L_4 , sizeof( V_80 -> V_85 ) ) ;
V_80 -> V_64 = V_65 ;
V_80 -> V_40 = 0 ;
return 0 ;
}
static int F_35 ( struct V_49 * V_49 , void * V_50 , T_2 V_69 )
{
struct V_7 * V_8 = F_26 ( V_49 ) ;
if ( V_8 -> V_66 )
return - V_86 ;
if ( V_69 == V_8 -> V_69 )
return 0 ;
if ( F_32 ( & V_8 -> V_81 ) )
return - V_82 ;
V_8 -> V_69 = V_69 ;
F_29 ( V_8 , & V_8 -> V_17 ) ;
return 0 ;
}
static int F_36 ( struct V_49 * V_49 , void * V_50 , T_2 * V_69 )
{
struct V_7 * V_8 = F_26 ( V_49 ) ;
if ( V_8 -> V_66 )
return - V_86 ;
* V_69 = V_8 -> V_69 ;
return 0 ;
}
static int F_37 ( struct V_49 * V_49 , void * V_50 , T_2 * V_69 )
{
struct V_7 * V_8 = F_26 ( V_49 ) ;
if ( V_8 -> V_66 )
return - V_86 ;
#ifdef F_4
F_38 () ;
if ( V_87 ) {
* V_69 = 0 ;
return 0 ;
}
if ( V_88 )
* V_69 &= V_70 ;
else
* V_69 &= V_89 ;
#endif
return 0 ;
}
static int F_39 ( struct V_49 * V_49 , void * V_90 ,
struct V_91 * V_74 )
{
struct V_7 * V_8 = F_26 ( V_49 ) ;
if ( V_8 -> V_66 == 0 )
return - V_86 ;
if ( ! F_40 ( V_74 , & V_92 , NULL , NULL ) )
return - V_31 ;
if ( ! F_41 ( V_74 , & V_92 ,
0 , NULL , NULL ) )
return - V_31 ;
if ( F_42 ( V_74 , & V_8 -> V_74 , 0 ) )
return 0 ;
if ( F_32 ( & V_8 -> V_81 ) )
return - V_82 ;
V_8 -> V_74 = * V_74 ;
F_29 ( V_8 , & V_8 -> V_17 ) ;
return 0 ;
}
static int F_43 ( struct V_49 * V_49 , void * V_90 ,
struct V_91 * V_74 )
{
struct V_7 * V_8 = F_26 ( V_49 ) ;
if ( V_8 -> V_66 == 0 )
return - V_86 ;
* V_74 = V_8 -> V_74 ;
return 0 ;
}
static int F_44 ( struct V_49 * V_49 , void * V_90 ,
struct V_93 * V_74 )
{
struct V_7 * V_8 = F_26 ( V_49 ) ;
if ( V_8 -> V_66 == 0 )
return - V_86 ;
return F_45 ( V_74 , & V_92 ,
NULL , NULL ) ;
}
static int F_46 ( struct V_49 * V_49 , void * V_90 ,
struct V_91 * V_74 )
{
struct V_7 * V_8 = F_26 ( V_49 ) ;
if ( V_8 -> V_66 == 0 )
return - V_86 ;
#ifdef F_4
F_47 () ;
if ( V_87 )
return - V_94 ;
if ( V_95 )
return - V_96 ;
if ( V_97 )
return - V_98 ;
F_48 ( V_8 -> V_99 . V_100 , L_5 ,
V_74 , true ) ;
#endif
return 0 ;
}
static int F_49 ( struct V_49 * V_49 , void * V_101 ,
struct V_102 * V_52 )
{
struct V_7 * V_8 = F_26 ( V_49 ) ;
if ( V_8 -> V_66 == 0 )
return - V_86 ;
* V_52 = V_92 ;
return 0 ;
}
static int F_50 ( struct V_49 * V_49 , void * V_50 ,
struct V_103 * V_104 )
{
if ( V_104 -> V_84 > 1 )
return - V_31 ;
V_104 -> type = V_105 ;
if ( V_104 -> V_84 == 0 ) {
V_104 -> V_69 = V_106 ;
F_27 ( V_104 -> V_100 , L_6 , sizeof( V_104 -> V_100 ) ) ;
V_104 -> V_61 = V_107 ;
} else {
V_104 -> V_69 = 0 ;
F_27 ( V_104 -> V_100 , L_7 , sizeof( V_104 -> V_100 ) ) ;
V_104 -> V_61 = V_108 ;
}
return 0 ;
}
static int F_51 ( struct V_49 * V_49 , void * V_50 , unsigned int V_104 )
{
struct V_7 * V_8 = F_26 ( V_49 ) ;
if ( V_104 > 1 )
return - V_31 ;
if ( F_32 ( & V_8 -> V_81 ) )
return - V_82 ;
V_8 -> V_66 = V_104 ;
V_8 -> V_109 . V_110 = V_104 ? 0 : V_106 ;
F_29 ( V_8 , & V_8 -> V_17 ) ;
return 0 ;
}
static int F_52 ( struct V_49 * V_49 , void * V_50 , unsigned int * V_104 )
{
struct V_7 * V_8 = F_26 ( V_49 ) ;
* V_104 = V_8 -> V_66 ;
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
return - V_31 ;
}
return 0 ;
}
static int F_54 ( struct V_118 * V_37 , const struct V_119 * V_120 )
{
static const struct V_91 V_121 =
V_122 ;
struct V_7 * V_8 ;
struct V_123 * V_109 ;
struct V_124 * V_125 ;
struct V_23 * V_126 ;
int V_46 ;
V_46 = F_55 ( V_37 ) ;
if ( V_46 )
return V_46 ;
V_46 = F_56 ( V_37 , F_57 ( 32 ) ) ;
if ( V_46 ) {
F_15 ( & V_37 -> V_38 , L_8 ) ;
goto V_127;
}
V_8 = F_58 ( & V_37 -> V_38 , sizeof( struct V_7 ) , V_128 ) ;
if ( ! V_8 )
return - V_129 ;
V_46 = F_59 ( & V_37 -> V_38 , V_37 -> V_5 ,
F_3 , 0 , V_54 , V_8 ) ;
if ( V_46 ) {
F_15 ( & V_37 -> V_38 , L_9 ) ;
goto V_127;
}
V_8 -> V_37 = V_37 ;
V_8 -> V_74 = V_121 ;
V_8 -> V_69 = V_89 ;
F_29 ( V_8 , & V_8 -> V_17 ) ;
V_46 = F_60 ( & V_37 -> V_38 , & V_8 -> V_99 ) ;
if ( V_46 )
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
V_46 = V_125 -> error ;
goto V_133;
}
V_8 -> V_99 . V_131 = V_125 ;
V_126 = & V_8 -> V_81 ;
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
V_46 = F_64 ( V_126 ) ;
if ( V_46 )
goto V_133;
V_8 -> V_35 = F_65 ( & V_37 -> V_38 ) ;
if ( F_66 ( V_8 -> V_35 ) ) {
F_15 ( & V_37 -> V_38 , L_10 ) ;
V_46 = F_67 ( V_8 -> V_35 ) ;
goto V_133;
}
F_68 ( & V_8 -> V_41 ) ;
F_69 ( & V_8 -> V_10 ) ;
V_109 = & V_8 -> V_109 ;
F_27 ( V_109 -> V_100 , V_54 , sizeof( V_109 -> V_100 ) ) ;
V_109 -> V_150 = V_151 ;
V_109 -> V_152 = & V_153 ,
V_109 -> V_154 = & V_155 ,
V_109 -> V_130 = & V_8 -> V_130 ;
V_109 -> V_81 = V_126 ;
V_109 -> V_99 = & V_8 -> V_99 ;
V_109 -> V_110 = V_106 ;
F_70 ( V_156 , & V_109 -> V_40 ) ;
F_71 ( V_109 , V_8 ) ;
V_46 = F_72 ( V_109 , V_157 , - 1 ) ;
if ( V_46 )
goto V_158;
F_73 ( & V_37 -> V_38 , L_11 ) ;
return 0 ;
V_158:
F_74 ( V_8 -> V_35 ) ;
V_133:
F_75 ( & V_8 -> V_131 ) ;
F_76 ( & V_8 -> V_99 ) ;
V_127:
F_77 ( V_37 ) ;
return V_46 ;
}
static void F_78 ( struct V_118 * V_37 )
{
struct V_159 * V_99 = F_79 ( V_37 ) ;
struct V_7 * V_8 = F_2 ( V_99 , struct V_7 , V_99 ) ;
F_80 ( & V_8 -> V_109 ) ;
F_75 ( & V_8 -> V_131 ) ;
F_74 ( V_8 -> V_35 ) ;
F_76 ( & V_8 -> V_99 ) ;
F_77 ( V_8 -> V_37 ) ;
}
