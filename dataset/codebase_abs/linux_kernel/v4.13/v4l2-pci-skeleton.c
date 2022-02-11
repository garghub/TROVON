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
static int F_10 ( struct V_23 * V_24 ,
unsigned int * V_25 , unsigned int * V_26 ,
unsigned int V_27 [] , struct V_28 * V_29 [] )
{
struct V_7 * V_8 = F_11 ( V_24 ) ;
V_8 -> V_16 = V_8 -> V_17 . V_16 ;
if ( V_8 -> V_16 == V_18 ) {
if ( F_12 ( V_24 ) )
return - V_30 ;
V_8 -> V_16 = V_20 ;
}
if ( V_24 -> V_31 + * V_25 < 3 )
* V_25 = 3 - V_24 -> V_31 ;
if ( * V_26 )
return V_27 [ 0 ] < V_8 -> V_17 . V_32 ? - V_30 : 0 ;
* V_26 = 1 ;
V_27 [ 0 ] = V_8 -> V_17 . V_32 ;
return 0 ;
}
static int F_13 ( struct V_2 * V_4 )
{
struct V_7 * V_8 = F_11 ( V_4 -> V_23 ) ;
unsigned long V_33 = V_8 -> V_17 . V_32 ;
if ( F_14 ( V_4 , 0 ) < V_33 ) {
F_15 ( & V_8 -> V_34 -> V_35 , L_1 ,
F_14 ( V_4 , 0 ) , V_33 ) ;
return - V_30 ;
}
F_16 ( V_4 , 0 , V_33 ) ;
return 0 ;
}
static void F_17 ( struct V_2 * V_4 )
{
struct V_7 * V_8 = F_11 ( V_4 -> V_23 ) ;
struct V_1 * V_36 = F_1 ( V_4 ) ;
unsigned long V_37 ;
F_18 ( & V_8 -> V_10 , V_37 ) ;
F_19 ( & V_36 -> V_12 , & V_8 -> V_38 ) ;
F_20 ( & V_8 -> V_10 , V_37 ) ;
}
static void F_21 ( struct V_7 * V_8 ,
enum V_39 V_40 )
{
struct V_1 * V_36 , * V_41 ;
unsigned long V_37 ;
F_18 ( & V_8 -> V_10 , V_37 ) ;
F_22 (buf, node, &skel->buf_list, list) {
F_9 ( & V_36 -> V_4 , V_40 ) ;
F_6 ( & V_36 -> V_12 ) ;
}
F_20 ( & V_8 -> V_10 , V_37 ) ;
}
static int F_23 ( struct V_23 * V_24 , unsigned int V_42 )
{
struct V_7 * V_8 = F_11 ( V_24 ) ;
int V_43 = 0 ;
V_8 -> V_15 = 0 ;
if ( V_43 ) {
F_21 ( V_8 , V_44 ) ;
}
return V_43 ;
}
static void F_24 ( struct V_23 * V_24 )
{
struct V_7 * V_8 = F_11 ( V_24 ) ;
F_21 ( V_8 , V_45 ) ;
}
static int F_25 ( struct V_46 * V_46 , void * V_47 ,
struct V_48 * V_49 )
{
struct V_7 * V_8 = F_26 ( V_46 ) ;
F_27 ( V_49 -> V_50 , V_51 , sizeof( V_49 -> V_50 ) ) ;
F_27 ( V_49 -> V_52 , L_2 , sizeof( V_49 -> V_52 ) ) ;
snprintf ( V_49 -> V_53 , sizeof( V_49 -> V_53 ) , L_3 ,
F_28 ( V_8 -> V_34 ) ) ;
return 0 ;
}
static void F_29 ( struct V_7 * V_8 ,
struct V_54 * V_55 )
{
V_55 -> V_56 = V_57 ;
if ( V_8 -> V_58 == 0 ) {
V_55 -> V_59 = 720 ;
V_55 -> V_60 = ( V_8 -> V_61 & V_62 ) ? 480 : 576 ;
V_55 -> V_16 = V_63 ;
V_55 -> V_64 = V_65 ;
} else {
V_55 -> V_59 = V_8 -> V_66 . V_67 . V_59 ;
V_55 -> V_60 = V_8 -> V_66 . V_67 . V_60 ;
if ( V_8 -> V_66 . V_67 . V_68 ) {
V_55 -> V_16 = V_18 ;
V_55 -> V_60 /= 2 ;
} else {
V_55 -> V_16 = V_69 ;
}
V_55 -> V_64 = V_70 ;
}
V_55 -> V_71 = V_55 -> V_59 * 2 ;
V_55 -> V_32 = V_55 -> V_71 * V_55 -> V_60 ;
V_55 -> V_47 = 0 ;
}
static int F_30 ( struct V_46 * V_46 , void * V_47 ,
struct V_72 * V_73 )
{
struct V_7 * V_8 = F_26 ( V_46 ) ;
struct V_54 * V_55 = & V_73 -> V_74 . V_55 ;
if ( V_55 -> V_56 != V_57 )
return - V_30 ;
F_29 ( V_8 , V_55 ) ;
return 0 ;
}
static int F_31 ( struct V_46 * V_46 , void * V_47 ,
struct V_72 * V_73 )
{
struct V_7 * V_8 = F_26 ( V_46 ) ;
int V_43 ;
V_43 = F_30 ( V_46 , V_47 , V_73 ) ;
if ( V_43 )
return V_43 ;
if ( F_32 ( & V_8 -> V_75 ) )
return - V_76 ;
V_8 -> V_17 = V_73 -> V_74 . V_55 ;
return 0 ;
}
static int F_33 ( struct V_46 * V_46 , void * V_47 ,
struct V_72 * V_73 )
{
struct V_7 * V_8 = F_26 ( V_46 ) ;
V_73 -> V_74 . V_55 = V_8 -> V_17 ;
return 0 ;
}
static int F_34 ( struct V_46 * V_46 , void * V_47 ,
struct V_77 * V_73 )
{
if ( V_73 -> V_78 != 0 )
return - V_30 ;
V_73 -> V_56 = V_57 ;
return 0 ;
}
static int F_35 ( struct V_46 * V_46 , void * V_47 , T_2 V_61 )
{
struct V_7 * V_8 = F_26 ( V_46 ) ;
if ( V_8 -> V_58 )
return - V_79 ;
if ( V_61 == V_8 -> V_61 )
return 0 ;
if ( F_32 ( & V_8 -> V_75 ) )
return - V_76 ;
V_8 -> V_61 = V_61 ;
F_29 ( V_8 , & V_8 -> V_17 ) ;
return 0 ;
}
static int F_36 ( struct V_46 * V_46 , void * V_47 , T_2 * V_61 )
{
struct V_7 * V_8 = F_26 ( V_46 ) ;
if ( V_8 -> V_58 )
return - V_79 ;
* V_61 = V_8 -> V_61 ;
return 0 ;
}
static int F_37 ( struct V_46 * V_46 , void * V_47 , T_2 * V_61 )
{
struct V_7 * V_8 = F_26 ( V_46 ) ;
if ( V_8 -> V_58 )
return - V_79 ;
#ifdef F_4
F_38 () ;
if ( V_80 ) {
* V_61 = 0 ;
return 0 ;
}
if ( V_81 )
* V_61 &= V_62 ;
else
* V_61 &= V_82 ;
#endif
return 0 ;
}
static int F_39 ( struct V_46 * V_46 , void * V_83 ,
struct V_84 * V_66 )
{
struct V_7 * V_8 = F_26 ( V_46 ) ;
if ( V_8 -> V_58 == 0 )
return - V_79 ;
if ( ! F_40 ( V_66 , & V_85 , NULL , NULL ) )
return - V_30 ;
if ( ! F_41 ( V_66 , & V_85 ,
0 , NULL , NULL ) )
return - V_30 ;
if ( F_42 ( V_66 , & V_8 -> V_66 , 0 , false ) )
return 0 ;
if ( F_32 ( & V_8 -> V_75 ) )
return - V_76 ;
V_8 -> V_66 = * V_66 ;
F_29 ( V_8 , & V_8 -> V_17 ) ;
return 0 ;
}
static int F_43 ( struct V_46 * V_46 , void * V_83 ,
struct V_84 * V_66 )
{
struct V_7 * V_8 = F_26 ( V_46 ) ;
if ( V_8 -> V_58 == 0 )
return - V_79 ;
* V_66 = V_8 -> V_66 ;
return 0 ;
}
static int F_44 ( struct V_46 * V_46 , void * V_83 ,
struct V_86 * V_66 )
{
struct V_7 * V_8 = F_26 ( V_46 ) ;
if ( V_8 -> V_58 == 0 )
return - V_79 ;
return F_45 ( V_66 , & V_85 ,
NULL , NULL ) ;
}
static int F_46 ( struct V_46 * V_46 , void * V_83 ,
struct V_84 * V_66 )
{
struct V_7 * V_8 = F_26 ( V_46 ) ;
if ( V_8 -> V_58 == 0 )
return - V_79 ;
#ifdef F_4
F_47 () ;
if ( V_80 )
return - V_87 ;
if ( V_88 )
return - V_89 ;
if ( V_90 )
return - V_91 ;
F_48 ( V_8 -> V_92 . V_93 , L_4 ,
V_66 , true ) ;
#endif
return 0 ;
}
static int F_49 ( struct V_46 * V_46 , void * V_94 ,
struct V_95 * V_49 )
{
struct V_7 * V_8 = F_26 ( V_46 ) ;
if ( V_8 -> V_58 == 0 )
return - V_79 ;
* V_49 = V_85 ;
return 0 ;
}
static int F_50 ( struct V_46 * V_46 , void * V_47 ,
struct V_96 * V_97 )
{
if ( V_97 -> V_78 > 1 )
return - V_30 ;
V_97 -> type = V_98 ;
if ( V_97 -> V_78 == 0 ) {
V_97 -> V_61 = V_99 ;
F_27 ( V_97 -> V_93 , L_5 , sizeof( V_97 -> V_93 ) ) ;
V_97 -> V_100 = V_101 ;
} else {
V_97 -> V_61 = 0 ;
F_27 ( V_97 -> V_93 , L_6 , sizeof( V_97 -> V_93 ) ) ;
V_97 -> V_100 = V_102 ;
}
return 0 ;
}
static int F_51 ( struct V_46 * V_46 , void * V_47 , unsigned int V_97 )
{
struct V_7 * V_8 = F_26 ( V_46 ) ;
if ( V_97 > 1 )
return - V_30 ;
if ( F_32 ( & V_8 -> V_75 ) )
return - V_76 ;
V_8 -> V_58 = V_97 ;
V_8 -> V_103 . V_104 = V_97 ? 0 : V_99 ;
F_29 ( V_8 , & V_8 -> V_17 ) ;
return 0 ;
}
static int F_52 ( struct V_46 * V_46 , void * V_47 , unsigned int * V_97 )
{
struct V_7 * V_8 = F_26 ( V_46 ) ;
* V_97 = V_8 -> V_58 ;
return 0 ;
}
static int F_53 ( struct V_105 * V_106 )
{
switch ( V_106 -> V_107 ) {
case V_108 :
break;
case V_109 :
break;
case V_110 :
break;
case V_111 :
break;
default:
return - V_30 ;
}
return 0 ;
}
static int F_54 ( struct V_112 * V_34 , const struct V_113 * V_114 )
{
static const struct V_84 V_115 =
V_116 ;
struct V_7 * V_8 ;
struct V_117 * V_103 ;
struct V_118 * V_119 ;
struct V_23 * V_120 ;
int V_43 ;
V_43 = F_55 ( V_34 ) ;
if ( V_43 )
return V_43 ;
V_43 = F_56 ( V_34 , F_57 ( 32 ) ) ;
if ( V_43 ) {
F_15 ( & V_34 -> V_35 , L_7 ) ;
goto V_121;
}
V_8 = F_58 ( & V_34 -> V_35 , sizeof( struct V_7 ) , V_122 ) ;
if ( ! V_8 )
return - V_123 ;
V_43 = F_59 ( & V_34 -> V_35 , V_34 -> V_5 ,
F_3 , 0 , V_51 , V_8 ) ;
if ( V_43 ) {
F_15 ( & V_34 -> V_35 , L_8 ) ;
goto V_121;
}
V_8 -> V_34 = V_34 ;
V_8 -> V_66 = V_115 ;
V_8 -> V_61 = V_82 ;
F_29 ( V_8 , & V_8 -> V_17 ) ;
V_43 = F_60 ( & V_34 -> V_35 , & V_8 -> V_92 ) ;
if ( V_43 )
goto V_121;
F_61 ( & V_8 -> V_124 ) ;
V_119 = & V_8 -> V_125 ;
F_62 ( V_119 , 4 ) ;
F_63 ( V_119 , & V_126 ,
V_108 , 0 , 255 , 1 , 127 ) ;
F_63 ( V_119 , & V_126 ,
V_109 , 0 , 255 , 1 , 16 ) ;
F_63 ( V_119 , & V_126 ,
V_110 , 0 , 255 , 1 , 127 ) ;
F_63 ( V_119 , & V_126 ,
V_111 , - 128 , 127 , 1 , 0 ) ;
if ( V_119 -> error ) {
V_43 = V_119 -> error ;
goto V_127;
}
V_8 -> V_92 . V_125 = V_119 ;
V_120 = & V_8 -> V_75 ;
V_120 -> type = V_128 ;
V_120 -> V_129 = V_130 | V_131 | V_132 ;
V_120 -> V_35 = & V_34 -> V_35 ;
V_120 -> V_133 = V_8 ;
V_120 -> V_134 = sizeof( struct V_1 ) ;
V_120 -> V_135 = & V_136 ;
V_120 -> V_137 = & V_138 ;
V_120 -> V_139 = V_140 ;
V_120 -> V_141 = 2 ;
V_120 -> V_124 = & V_8 -> V_124 ;
V_120 -> V_142 = V_143 ;
V_43 = F_64 ( V_120 ) ;
if ( V_43 )
goto V_127;
F_65 ( & V_8 -> V_38 ) ;
F_66 ( & V_8 -> V_10 ) ;
V_103 = & V_8 -> V_103 ;
F_27 ( V_103 -> V_93 , V_51 , sizeof( V_103 -> V_93 ) ) ;
V_103 -> V_144 = V_145 ;
V_103 -> V_146 = & V_147 ,
V_103 -> V_148 = & V_149 ,
V_103 -> V_150 = V_151 | V_152 |
V_153 ;
V_103 -> V_124 = & V_8 -> V_124 ;
V_103 -> V_75 = V_120 ;
V_103 -> V_92 = & V_8 -> V_92 ;
V_103 -> V_104 = V_99 ;
F_67 ( V_103 , V_8 ) ;
V_43 = F_68 ( V_103 , V_154 , - 1 ) ;
if ( V_43 )
goto V_127;
F_69 ( & V_34 -> V_35 , L_9 ) ;
return 0 ;
V_127:
F_70 ( & V_8 -> V_125 ) ;
F_71 ( & V_8 -> V_92 ) ;
V_121:
F_72 ( V_34 ) ;
return V_43 ;
}
static void F_73 ( struct V_112 * V_34 )
{
struct V_155 * V_92 = F_74 ( V_34 ) ;
struct V_7 * V_8 = F_2 ( V_92 , struct V_7 , V_92 ) ;
F_75 ( & V_8 -> V_103 ) ;
F_70 ( & V_8 -> V_125 ) ;
F_71 ( & V_8 -> V_92 ) ;
F_72 ( V_8 -> V_34 ) ;
}
