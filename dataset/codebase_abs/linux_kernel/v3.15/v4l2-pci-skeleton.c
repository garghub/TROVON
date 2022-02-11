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
V_11 -> V_4 . V_13 . V_14 = V_8 -> V_14 ++ ;
F_8 ( & V_11 -> V_4 . V_13 . V_15 ) ;
F_9 ( & V_11 -> V_4 , V_16 ) ;
}
#endif
return V_17 ;
}
static int F_10 ( struct V_18 * V_19 , const struct V_20 * V_21 ,
unsigned int * V_22 , unsigned int * V_23 ,
unsigned int V_24 [] , void * V_25 [] )
{
struct V_7 * V_8 = F_11 ( V_19 ) ;
if ( V_19 -> V_26 + * V_22 < 3 )
* V_22 = 3 - V_19 -> V_26 ;
if ( V_21 && V_21 -> V_21 . V_27 . V_28 < V_8 -> V_29 . V_28 )
return - V_30 ;
* V_23 = 1 ;
V_24 [ 0 ] = V_21 ? V_21 -> V_21 . V_27 . V_28 : V_8 -> V_29 . V_28 ;
V_25 [ 0 ] = V_8 -> V_31 ;
return 0 ;
}
static int F_12 ( struct V_2 * V_4 )
{
struct V_7 * V_8 = F_11 ( V_4 -> V_18 ) ;
unsigned long V_32 = V_8 -> V_29 . V_28 ;
if ( F_13 ( V_4 , 0 ) < V_32 ) {
F_14 ( & V_8 -> V_33 -> V_34 , L_1 ,
F_13 ( V_4 , 0 ) , V_32 ) ;
return - V_30 ;
}
F_15 ( V_4 , 0 , V_32 ) ;
V_4 -> V_13 . V_35 = V_8 -> V_29 . V_35 ;
return 0 ;
}
static void F_16 ( struct V_2 * V_4 )
{
struct V_7 * V_8 = F_11 ( V_4 -> V_18 ) ;
struct V_1 * V_36 = F_1 ( V_4 ) ;
unsigned long V_37 ;
F_17 ( & V_8 -> V_10 , V_37 ) ;
F_18 ( & V_36 -> V_12 , & V_8 -> V_38 ) ;
F_19 ( & V_8 -> V_10 , V_37 ) ;
}
static void F_20 ( struct V_7 * V_8 ,
enum V_39 V_40 )
{
struct V_1 * V_36 , * V_41 ;
unsigned long V_37 ;
F_17 ( & V_8 -> V_10 , V_37 ) ;
F_21 (buf, node, &skel->buf_list, list) {
F_9 ( & V_36 -> V_4 , V_40 ) ;
F_6 ( & V_36 -> V_12 ) ;
}
F_19 ( & V_8 -> V_10 , V_37 ) ;
}
static int F_22 ( struct V_18 * V_19 , unsigned int V_42 )
{
struct V_7 * V_8 = F_11 ( V_19 ) ;
int V_43 = 0 ;
V_8 -> V_14 = 0 ;
if ( V_43 ) {
F_20 ( V_8 , V_44 ) ;
}
return V_43 ;
}
static int F_23 ( struct V_18 * V_19 )
{
struct V_7 * V_8 = F_11 ( V_19 ) ;
F_20 ( V_8 , V_45 ) ;
return 0 ;
}
static int F_24 ( struct V_46 * V_46 , void * V_47 ,
struct V_48 * V_49 )
{
struct V_7 * V_8 = F_25 ( V_46 ) ;
F_26 ( V_49 -> V_50 , V_51 , sizeof( V_49 -> V_50 ) ) ;
F_26 ( V_49 -> V_52 , L_2 , sizeof( V_49 -> V_52 ) ) ;
snprintf ( V_49 -> V_53 , sizeof( V_49 -> V_53 ) , L_3 ,
F_27 ( V_8 -> V_33 ) ) ;
V_49 -> V_54 = V_55 | V_56 |
V_57 ;
V_49 -> V_58 = V_49 -> V_54 | V_59 ;
return 0 ;
}
static void F_28 ( struct V_7 * V_8 ,
struct V_60 * V_27 )
{
V_27 -> V_61 = V_62 ;
if ( V_8 -> V_63 == 0 ) {
V_27 -> V_64 = 720 ;
V_27 -> V_65 = ( V_8 -> V_66 & V_67 ) ? 480 : 576 ;
V_27 -> V_35 = V_68 ;
V_27 -> V_69 = V_70 ;
} else {
V_27 -> V_64 = V_8 -> V_71 . V_72 . V_64 ;
V_27 -> V_65 = V_8 -> V_71 . V_72 . V_65 ;
if ( V_8 -> V_71 . V_72 . V_73 )
V_27 -> V_35 = V_68 ;
else
V_27 -> V_35 = V_74 ;
V_27 -> V_69 = V_75 ;
}
V_27 -> V_76 = V_27 -> V_64 * 2 ;
V_27 -> V_28 = V_27 -> V_76 * V_27 -> V_65 ;
V_27 -> V_47 = 0 ;
}
static int F_29 ( struct V_46 * V_46 , void * V_47 ,
struct V_20 * V_77 )
{
struct V_7 * V_8 = F_25 ( V_46 ) ;
struct V_60 * V_27 = & V_77 -> V_21 . V_27 ;
if ( V_27 -> V_61 != V_62 )
return - V_30 ;
F_28 ( V_8 , V_27 ) ;
return 0 ;
}
static int F_30 ( struct V_46 * V_46 , void * V_47 ,
struct V_20 * V_77 )
{
struct V_7 * V_8 = F_25 ( V_46 ) ;
int V_43 ;
V_43 = F_29 ( V_46 , V_47 , V_77 ) ;
if ( V_43 )
return V_43 ;
if ( F_31 ( & V_8 -> V_78 ) )
return - V_79 ;
V_8 -> V_29 = V_77 -> V_21 . V_27 ;
return 0 ;
}
static int F_32 ( struct V_46 * V_46 , void * V_47 ,
struct V_20 * V_77 )
{
struct V_7 * V_8 = F_25 ( V_46 ) ;
V_77 -> V_21 . V_27 = V_8 -> V_29 ;
return 0 ;
}
static int F_33 ( struct V_46 * V_46 , void * V_47 ,
struct V_80 * V_77 )
{
if ( V_77 -> V_81 != 0 )
return - V_30 ;
F_26 ( V_77 -> V_82 , L_4 , sizeof( V_77 -> V_82 ) ) ;
V_77 -> V_61 = V_62 ;
V_77 -> V_37 = 0 ;
return 0 ;
}
static int F_34 ( struct V_46 * V_46 , void * V_47 , T_2 V_66 )
{
struct V_7 * V_8 = F_25 ( V_46 ) ;
if ( V_8 -> V_63 )
return - V_83 ;
if ( V_66 == V_8 -> V_66 )
return 0 ;
if ( F_31 ( & V_8 -> V_78 ) )
return - V_79 ;
V_8 -> V_66 = V_66 ;
F_28 ( V_8 , & V_8 -> V_29 ) ;
return 0 ;
}
static int F_35 ( struct V_46 * V_46 , void * V_47 , T_2 * V_66 )
{
struct V_7 * V_8 = F_25 ( V_46 ) ;
if ( V_8 -> V_63 )
return - V_83 ;
* V_66 = V_8 -> V_66 ;
return 0 ;
}
static int F_36 ( struct V_46 * V_46 , void * V_47 , T_2 * V_66 )
{
struct V_7 * V_8 = F_25 ( V_46 ) ;
if ( V_8 -> V_63 )
return - V_83 ;
#ifdef F_4
F_37 () ;
if ( V_84 ) {
* V_66 = 0 ;
return 0 ;
}
if ( V_85 )
* V_66 &= V_67 ;
else
* V_66 &= V_86 ;
#endif
return 0 ;
}
static int F_38 ( struct V_46 * V_46 , void * V_87 ,
struct V_88 * V_71 )
{
struct V_7 * V_8 = F_25 ( V_46 ) ;
if ( V_8 -> V_63 == 0 )
return - V_83 ;
if ( ! F_39 ( V_71 , & V_89 , NULL , NULL ) )
return - V_30 ;
if ( ! F_40 ( V_71 , & V_89 ,
0 , NULL , NULL ) )
return - V_30 ;
if ( F_41 ( V_71 , & V_8 -> V_71 , 0 ) )
return 0 ;
if ( F_31 ( & V_8 -> V_78 ) )
return - V_79 ;
V_8 -> V_71 = * V_71 ;
F_28 ( V_8 , & V_8 -> V_29 ) ;
return 0 ;
}
static int F_42 ( struct V_46 * V_46 , void * V_87 ,
struct V_88 * V_71 )
{
struct V_7 * V_8 = F_25 ( V_46 ) ;
if ( V_8 -> V_63 == 0 )
return - V_83 ;
* V_71 = V_8 -> V_71 ;
return 0 ;
}
static int F_43 ( struct V_46 * V_46 , void * V_87 ,
struct V_90 * V_71 )
{
struct V_7 * V_8 = F_25 ( V_46 ) ;
if ( V_8 -> V_63 == 0 )
return - V_83 ;
return F_44 ( V_71 , & V_89 ,
NULL , NULL ) ;
}
static int F_45 ( struct V_46 * V_46 , void * V_87 ,
struct V_88 * V_71 )
{
struct V_7 * V_8 = F_25 ( V_46 ) ;
if ( V_8 -> V_63 == 0 )
return - V_83 ;
#ifdef F_4
F_46 () ;
if ( V_84 )
return - V_91 ;
if ( V_92 )
return - V_93 ;
if ( V_94 )
return - V_95 ;
F_47 ( V_8 -> V_96 . V_97 , L_5 ,
V_71 , true ) ;
#endif
return 0 ;
}
static int F_48 ( struct V_46 * V_46 , void * V_98 ,
struct V_99 * V_49 )
{
struct V_7 * V_8 = F_25 ( V_46 ) ;
if ( V_8 -> V_63 == 0 )
return - V_83 ;
* V_49 = V_89 ;
return 0 ;
}
static int F_49 ( struct V_46 * V_46 , void * V_47 ,
struct V_100 * V_101 )
{
if ( V_101 -> V_81 > 1 )
return - V_30 ;
V_101 -> type = V_102 ;
if ( V_101 -> V_81 == 0 ) {
V_101 -> V_66 = V_103 ;
F_26 ( V_101 -> V_97 , L_6 , sizeof( V_101 -> V_97 ) ) ;
V_101 -> V_58 = V_104 ;
} else {
V_101 -> V_66 = 0 ;
F_26 ( V_101 -> V_97 , L_7 , sizeof( V_101 -> V_97 ) ) ;
V_101 -> V_58 = V_105 ;
}
return 0 ;
}
static int F_50 ( struct V_46 * V_46 , void * V_47 , unsigned int V_101 )
{
struct V_7 * V_8 = F_25 ( V_46 ) ;
if ( V_101 > 1 )
return - V_30 ;
if ( F_31 ( & V_8 -> V_78 ) )
return - V_79 ;
V_8 -> V_63 = V_101 ;
V_8 -> V_106 . V_107 = V_101 ? 0 : V_103 ;
F_28 ( V_8 , & V_8 -> V_29 ) ;
return 0 ;
}
static int F_51 ( struct V_46 * V_46 , void * V_47 , unsigned int * V_101 )
{
struct V_7 * V_8 = F_25 ( V_46 ) ;
* V_101 = V_8 -> V_63 ;
return 0 ;
}
static int F_52 ( struct V_108 * V_109 )
{
switch ( V_109 -> V_110 ) {
case V_111 :
break;
case V_112 :
break;
case V_113 :
break;
case V_114 :
break;
default:
return - V_30 ;
}
return 0 ;
}
static int F_53 ( struct V_115 * V_33 , const struct V_116 * V_117 )
{
static const struct V_88 V_118 =
V_119 ;
struct V_7 * V_8 ;
struct V_120 * V_106 ;
struct V_121 * V_122 ;
struct V_18 * V_123 ;
int V_43 ;
V_43 = F_54 ( V_33 ) ;
if ( V_43 )
return V_43 ;
V_43 = F_55 ( V_33 , F_56 ( 32 ) ) ;
if ( V_43 ) {
F_14 ( & V_33 -> V_34 , L_8 ) ;
goto V_124;
}
V_8 = F_57 ( & V_33 -> V_34 , sizeof( struct V_7 ) , V_125 ) ;
if ( ! V_8 )
return - V_126 ;
V_43 = F_58 ( & V_33 -> V_34 , V_33 -> V_5 ,
F_3 , 0 , V_51 , V_8 ) ;
if ( V_43 ) {
F_14 ( & V_33 -> V_34 , L_9 ) ;
goto V_124;
}
V_8 -> V_33 = V_33 ;
V_8 -> V_71 = V_118 ;
V_8 -> V_66 = V_86 ;
F_28 ( V_8 , & V_8 -> V_29 ) ;
V_43 = F_59 ( & V_33 -> V_34 , & V_8 -> V_96 ) ;
if ( V_43 )
goto V_124;
F_60 ( & V_8 -> V_127 ) ;
V_122 = & V_8 -> V_128 ;
F_61 ( V_122 , 4 ) ;
F_62 ( V_122 , & V_129 ,
V_111 , 0 , 255 , 1 , 127 ) ;
F_62 ( V_122 , & V_129 ,
V_112 , 0 , 255 , 1 , 16 ) ;
F_62 ( V_122 , & V_129 ,
V_113 , 0 , 255 , 1 , 127 ) ;
F_62 ( V_122 , & V_129 ,
V_114 , - 128 , 127 , 1 , 0 ) ;
if ( V_122 -> error ) {
V_43 = V_122 -> error ;
goto V_130;
}
V_8 -> V_96 . V_128 = V_122 ;
V_123 = & V_8 -> V_78 ;
V_123 -> type = V_131 ;
V_123 -> V_132 = V_133 | V_134 | V_135 ;
V_123 -> V_136 = V_8 ;
V_123 -> V_137 = sizeof( struct V_1 ) ;
V_123 -> V_138 = & V_139 ;
V_123 -> V_140 = & V_141 ;
V_123 -> V_142 = V_143 ;
V_123 -> V_144 = 2 ;
V_123 -> V_127 = & V_8 -> V_127 ;
V_123 -> V_145 = V_146 ;
V_43 = F_63 ( V_123 ) ;
if ( V_43 )
goto V_130;
V_8 -> V_31 = F_64 ( & V_33 -> V_34 ) ;
if ( F_65 ( V_8 -> V_31 ) ) {
F_14 ( & V_33 -> V_34 , L_10 ) ;
V_43 = F_66 ( V_8 -> V_31 ) ;
goto V_130;
}
F_67 ( & V_8 -> V_38 ) ;
F_68 ( & V_8 -> V_10 ) ;
V_106 = & V_8 -> V_106 ;
F_26 ( V_106 -> V_97 , V_51 , sizeof( V_106 -> V_97 ) ) ;
V_106 -> V_147 = V_148 ;
V_106 -> V_149 = & V_150 ,
V_106 -> V_151 = & V_152 ,
V_106 -> V_127 = & V_8 -> V_127 ;
V_106 -> V_78 = V_123 ;
V_106 -> V_96 = & V_8 -> V_96 ;
V_106 -> V_107 = V_103 ;
F_69 ( V_153 , & V_106 -> V_37 ) ;
F_70 ( V_106 , V_8 ) ;
V_43 = F_71 ( V_106 , V_154 , - 1 ) ;
if ( V_43 )
goto V_155;
F_72 ( & V_33 -> V_34 , L_11 ) ;
return 0 ;
V_155:
F_73 ( V_8 -> V_31 ) ;
V_130:
F_74 ( & V_8 -> V_128 ) ;
F_75 ( & V_8 -> V_96 ) ;
V_124:
F_76 ( V_33 ) ;
return V_43 ;
}
static void F_77 ( struct V_115 * V_33 )
{
struct V_156 * V_96 = F_78 ( V_33 ) ;
struct V_7 * V_8 = F_2 ( V_96 , struct V_7 , V_96 ) ;
F_79 ( & V_8 -> V_106 ) ;
F_74 ( & V_8 -> V_128 ) ;
F_73 ( V_8 -> V_31 ) ;
F_75 ( & V_8 -> V_96 ) ;
F_76 ( V_8 -> V_33 ) ;
}
