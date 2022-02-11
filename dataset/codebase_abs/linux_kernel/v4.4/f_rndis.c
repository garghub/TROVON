static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_4 . V_5 ) ;
}
static unsigned int F_3 ( struct V_6 * V_7 )
{
if ( F_4 ( V_7 ) && V_7 -> V_8 == V_9 )
return 13 * 1024 * 8 * 1000 * 8 ;
else if ( F_5 ( V_7 ) && V_7 -> V_8 == V_10 )
return 13 * 512 * 8 * 1000 * 8 ;
else
return 19 * 64 * 1 * 1000 * 8 ;
}
static struct V_11 * F_6 ( struct V_12 * V_4 ,
struct V_11 * V_13 )
{
struct V_11 * V_14 ;
V_14 = F_7 ( V_13 , sizeof( struct V_15 ) ) ;
F_8 ( V_14 ) ;
F_9 ( V_13 ) ;
return V_14 ;
}
static void F_10 ( void * V_16 )
{
struct V_1 * V_17 = V_16 ;
struct V_18 * V_19 = V_17 -> V_20 ;
struct V_21 * V_22 = V_17 -> V_4 . V_5 . V_23 -> V_22 ;
T_1 * V_24 = V_19 -> V_25 ;
int V_26 ;
if ( F_11 ( & V_17 -> V_27 ) != 1 )
return;
V_24 [ 0 ] = F_12 ( 1 ) ;
V_24 [ 1 ] = F_12 ( 0 ) ;
V_26 = F_13 ( V_17 -> V_28 , V_19 , V_29 ) ;
if ( V_26 ) {
F_14 ( & V_17 -> V_27 ) ;
F_15 ( V_22 , L_1 , V_26 ) ;
}
}
static void F_16 ( struct V_30 * V_31 , struct V_18 * V_19 )
{
struct V_1 * V_17 = V_19 -> V_32 ;
struct V_21 * V_22 = V_17 -> V_4 . V_5 . V_23 -> V_22 ;
int V_26 = V_19 -> V_26 ;
switch ( V_26 ) {
case - V_33 :
case - V_34 :
F_17 ( & V_17 -> V_27 , 0 ) ;
break;
default:
F_15 ( V_22 , L_2 ,
V_31 -> V_35 , V_26 ,
V_19 -> V_36 , V_19 -> V_37 ) ;
case 0 :
if ( V_31 != V_17 -> V_28 )
break;
if ( F_18 ( & V_17 -> V_27 ) )
break;
V_26 = F_13 ( V_17 -> V_28 , V_19 , V_29 ) ;
if ( V_26 ) {
F_14 ( & V_17 -> V_27 ) ;
F_15 ( V_22 , L_3 , V_26 ) ;
}
break;
}
}
static void F_19 ( struct V_30 * V_31 , struct V_18 * V_19 )
{
struct V_1 * V_17 = V_19 -> V_32 ;
int V_26 ;
V_26 = F_20 ( V_17 -> V_38 , ( V_39 * ) V_19 -> V_25 ) ;
if ( V_26 < 0 )
F_21 ( L_4 ,
V_26 , V_19 -> V_36 , V_19 -> V_37 ) ;
}
static int
F_22 ( struct V_2 * V_3 , const struct V_40 * V_41 )
{
struct V_1 * V_17 = F_1 ( V_3 ) ;
struct V_21 * V_22 = V_3 -> V_23 -> V_22 ;
struct V_18 * V_19 = V_22 -> V_19 ;
int V_42 = - V_43 ;
T_2 V_44 = F_23 ( V_41 -> V_45 ) ;
T_2 V_46 = F_23 ( V_41 -> V_47 ) ;
T_2 V_48 = F_23 ( V_41 -> V_49 ) ;
switch ( ( V_41 -> V_50 << 8 ) | V_41 -> V_51 ) {
case ( ( V_52 | V_53 | V_54 ) << 8 )
| V_55 :
if ( V_46 || V_44 != V_17 -> V_56 )
goto V_57;
V_42 = V_48 ;
V_19 -> V_58 = F_19 ;
V_19 -> V_32 = V_17 ;
break;
case ( ( V_59 | V_53 | V_54 ) << 8 )
| V_60 :
if ( V_46 || V_44 != V_17 -> V_56 )
goto V_57;
else {
V_39 * V_25 ;
T_3 V_61 ;
V_25 = F_24 ( V_17 -> V_38 , & V_61 ) ;
if ( V_25 ) {
memcpy ( V_19 -> V_25 , V_25 , V_61 ) ;
V_19 -> V_58 = F_16 ;
V_19 -> V_32 = V_17 ;
F_25 ( V_17 -> V_38 , V_25 ) ;
V_42 = V_61 ;
}
}
break;
default:
V_57:
F_26 ( V_22 , L_5 ,
V_41 -> V_50 , V_41 -> V_51 ,
V_46 , V_44 , V_48 ) ;
}
if ( V_42 >= 0 ) {
F_15 ( V_22 , L_6 ,
V_41 -> V_50 , V_41 -> V_51 ,
V_46 , V_44 , V_48 ) ;
V_19 -> V_62 = ( V_42 < V_48 ) ;
V_19 -> V_37 = V_42 ;
V_42 = F_13 ( V_22 -> V_63 -> V_64 , V_19 , V_29 ) ;
if ( V_42 < 0 )
ERROR ( V_22 , L_7 , V_42 ) ;
}
return V_42 ;
}
static int F_27 ( struct V_2 * V_3 , unsigned V_65 , unsigned V_66 )
{
struct V_1 * V_17 = F_1 ( V_3 ) ;
struct V_21 * V_22 = V_3 -> V_23 -> V_22 ;
if ( V_65 == V_17 -> V_56 ) {
F_26 ( V_22 , L_8 , V_65 ) ;
F_28 ( V_17 -> V_28 ) ;
if ( ! V_17 -> V_28 -> V_67 ) {
F_26 ( V_22 , L_9 , V_65 ) ;
if ( F_29 ( V_22 -> V_63 , V_3 , V_17 -> V_28 ) )
goto V_68;
}
F_30 ( V_17 -> V_28 ) ;
} else if ( V_65 == V_17 -> V_69 ) {
struct V_70 * V_71 ;
if ( V_17 -> V_4 . V_72 -> V_73 ) {
F_15 ( V_22 , L_10 ) ;
F_31 ( & V_17 -> V_4 ) ;
}
if ( ! V_17 -> V_4 . V_72 -> V_67 || ! V_17 -> V_4 . V_74 -> V_67 ) {
F_15 ( V_22 , L_11 ) ;
if ( F_29 ( V_22 -> V_63 , V_3 ,
V_17 -> V_4 . V_72 ) ||
F_29 ( V_22 -> V_63 , V_3 ,
V_17 -> V_4 . V_74 ) ) {
V_17 -> V_4 . V_72 -> V_67 = NULL ;
V_17 -> V_4 . V_74 -> V_67 = NULL ;
goto V_68;
}
}
V_17 -> V_4 . V_75 = false ;
V_17 -> V_4 . V_76 = 0 ;
F_15 ( V_22 , L_12 ) ;
V_71 = F_32 ( & V_17 -> V_4 ) ;
if ( F_33 ( V_71 ) )
return F_34 ( V_71 ) ;
F_35 ( V_17 -> V_38 , V_71 ,
& V_17 -> V_4 . V_76 ) ;
} else
goto V_68;
return 0 ;
V_68:
return - V_77 ;
}
static void F_36 ( struct V_2 * V_3 )
{
struct V_1 * V_17 = F_1 ( V_3 ) ;
struct V_21 * V_22 = V_3 -> V_23 -> V_22 ;
if ( ! V_17 -> V_28 -> V_73 )
return;
F_15 ( V_22 , L_13 ) ;
F_37 ( V_17 -> V_38 ) ;
F_31 ( & V_17 -> V_4 ) ;
F_28 ( V_17 -> V_28 ) ;
}
static void F_38 ( struct V_12 * V_78 )
{
struct V_1 * V_17 = F_1 ( & V_78 -> V_5 ) ;
struct V_21 * V_22 = V_78 -> V_5 . V_23 -> V_22 ;
F_15 ( V_22 , L_14 , V_79 ) ;
F_39 ( V_17 -> V_38 , V_80 ,
F_3 ( V_22 -> V_63 ) / 100 ) ;
F_40 ( V_17 -> V_38 ) ;
}
static void F_41 ( struct V_12 * V_78 )
{
struct V_1 * V_17 = F_1 ( & V_78 -> V_5 ) ;
F_15 ( V_78 -> V_5 . V_23 -> V_22 , L_14 , V_79 ) ;
F_39 ( V_17 -> V_38 , V_80 , 0 ) ;
F_42 ( V_17 -> V_38 ) ;
}
static inline bool F_43 ( struct V_81 * V_82 )
{
return true ;
}
static int
F_44 ( struct V_81 * V_82 , struct V_2 * V_3 )
{
struct V_21 * V_22 = V_82 -> V_22 ;
struct V_1 * V_17 = F_1 ( V_3 ) ;
struct V_83 * V_84 ;
int V_26 ;
struct V_30 * V_31 ;
struct V_85 * V_86 ;
if ( ! F_43 ( V_82 ) )
return - V_77 ;
V_86 = F_2 ( V_3 -> V_87 , struct V_85 , V_88 ) ;
if ( V_22 -> V_89 ) {
V_3 -> V_90 = F_45 ( sizeof( * V_3 -> V_90 ) ,
V_91 ) ;
if ( ! V_3 -> V_90 )
return - V_92 ;
V_3 -> V_93 = 1 ;
V_3 -> V_90 [ 0 ] . V_94 = & V_86 -> V_95 ;
}
if ( ! V_86 -> V_96 ) {
F_46 ( V_86 -> V_71 , V_22 -> V_63 ) ;
V_26 = F_47 ( V_86 -> V_71 ) ;
if ( V_26 )
goto V_68;
V_86 -> V_96 = true ;
}
V_84 = F_48 ( V_22 , V_97 ,
F_49 ( V_98 ) ) ;
if ( F_33 ( V_84 ) ) {
V_26 = F_34 ( V_84 ) ;
goto V_68;
}
V_99 . V_100 = V_84 [ 0 ] . V_101 ;
V_102 . V_100 = V_84 [ 1 ] . V_101 ;
V_103 . V_104 = V_84 [ 2 ] . V_101 ;
V_26 = F_50 ( V_82 , V_3 ) ;
if ( V_26 < 0 )
goto V_68;
V_17 -> V_56 = V_26 ;
V_103 . V_105 = V_26 ;
V_99 . V_106 = V_26 ;
V_107 . V_108 = V_26 ;
if ( V_22 -> V_89 )
V_3 -> V_90 [ 0 ] . V_109 =
V_103 . V_105 ;
V_26 = F_50 ( V_82 , V_3 ) ;
if ( V_26 < 0 )
goto V_68;
V_17 -> V_69 = V_26 ;
V_102 . V_106 = V_26 ;
V_107 . V_110 = V_26 ;
V_26 = - V_111 ;
V_31 = F_51 ( V_22 -> V_63 , & V_112 ) ;
if ( ! V_31 )
goto V_68;
V_17 -> V_4 . V_72 = V_31 ;
V_31 = F_51 ( V_22 -> V_63 , & V_113 ) ;
if ( ! V_31 )
goto V_68;
V_17 -> V_4 . V_74 = V_31 ;
V_31 = F_51 ( V_22 -> V_63 , & V_114 ) ;
if ( ! V_31 )
goto V_68;
V_17 -> V_28 = V_31 ;
V_26 = - V_92 ;
V_17 -> V_20 = F_52 ( V_31 , V_91 ) ;
if ( ! V_17 -> V_20 )
goto V_68;
V_17 -> V_20 -> V_25 = F_53 ( V_115 , V_91 ) ;
if ( ! V_17 -> V_20 -> V_25 )
goto V_68;
V_17 -> V_20 -> V_37 = V_115 ;
V_17 -> V_20 -> V_32 = V_17 ;
V_17 -> V_20 -> V_58 = F_16 ;
V_116 . V_117 = V_112 . V_117 ;
V_118 . V_117 = V_113 . V_117 ;
V_119 . V_117 = V_114 . V_117 ;
V_120 . V_117 = V_112 . V_117 ;
V_121 . V_117 = V_113 . V_117 ;
V_122 . V_117 = V_114 . V_117 ;
V_26 = F_54 ( V_3 , V_123 , V_124 ,
V_125 ) ;
if ( V_26 )
goto V_68;
V_17 -> V_4 . V_126 = F_38 ;
V_17 -> V_4 . V_127 = F_41 ;
F_39 ( V_17 -> V_38 , V_80 , 0 ) ;
F_55 ( V_17 -> V_38 , V_17 -> V_128 ) ;
if ( V_17 -> V_129 && V_17 -> V_130 &&
F_56 ( V_17 -> V_38 , V_17 -> V_130 ,
V_17 -> V_129 ) ) {
V_26 = - V_77 ;
goto V_131;
}
F_15 ( V_22 , L_15 ,
F_4 ( V_82 -> V_22 -> V_63 ) ? L_16 :
F_5 ( V_82 -> V_22 -> V_63 ) ? L_17 : L_18 ,
V_17 -> V_4 . V_72 -> V_35 , V_17 -> V_4 . V_74 -> V_35 ,
V_17 -> V_28 -> V_35 ) ;
return 0 ;
V_131:
F_57 ( V_3 ) ;
V_68:
F_58 ( V_3 -> V_90 ) ;
V_3 -> V_93 = 0 ;
if ( V_17 -> V_20 ) {
F_58 ( V_17 -> V_20 -> V_25 ) ;
F_59 ( V_17 -> V_28 , V_17 -> V_20 ) ;
}
ERROR ( V_22 , L_19 , V_3 -> V_35 , V_26 ) ;
return V_26 ;
}
void F_60 ( struct V_132 * V_3 , struct V_70 * V_71 )
{
struct V_85 * V_133 ;
V_133 = F_2 ( V_3 , struct V_85 , V_88 ) ;
if ( V_133 -> V_96 )
F_61 ( F_62 ( V_133 -> V_71 ) ) ;
else
F_63 ( V_133 -> V_71 ) ;
V_133 -> V_134 = V_133 -> V_96 = true ;
V_133 -> V_71 = V_71 ;
}
static inline struct V_85 * F_64 ( struct V_135 * V_136 )
{
return F_2 ( F_65 ( V_136 ) , struct V_85 ,
V_88 . V_137 ) ;
}
static void F_66 ( struct V_132 * V_3 )
{
struct V_85 * V_133 ;
V_133 = F_2 ( V_3 , struct V_85 , V_88 ) ;
if ( ! V_133 -> V_134 ) {
if ( V_133 -> V_96 )
F_61 ( F_62 ( V_133 -> V_71 ) ) ;
else
F_63 ( V_133 -> V_71 ) ;
}
F_58 ( V_133 -> V_95 . V_137 . V_138 ) ;
F_58 ( V_133 ) ;
}
static struct V_132 * F_67 ( void )
{
struct V_85 * V_133 ;
struct V_139 * V_140 [ 1 ] ;
char * V_141 [ 1 ] ;
V_133 = F_45 ( sizeof( * V_133 ) , V_91 ) ;
if ( ! V_133 )
return F_68 ( - V_92 ) ;
V_133 -> V_95 . V_142 = V_133 -> V_143 ;
F_69 ( & V_133 -> V_144 ) ;
V_133 -> V_88 . V_145 = F_66 ;
V_133 -> V_71 = F_70 () ;
if ( F_33 ( V_133 -> V_71 ) ) {
struct V_70 * V_71 = V_133 -> V_71 ;
F_58 ( V_133 ) ;
return F_71 ( V_71 ) ;
}
F_72 ( & V_133 -> V_95 . V_146 ) ;
V_140 [ 0 ] = & V_133 -> V_95 ;
V_141 [ 0 ] = L_20 ;
F_73 ( & V_133 -> V_88 . V_137 , 1 , V_140 ,
V_141 , V_147 ) ;
F_74 ( & V_133 -> V_88 . V_137 , L_21 ,
& V_148 ) ;
return & V_133 -> V_88 ;
}
static void F_75 ( struct V_2 * V_3 )
{
struct V_1 * V_17 ;
struct V_85 * V_133 ;
V_17 = F_1 ( V_3 ) ;
F_76 ( V_17 -> V_38 ) ;
V_133 = F_2 ( V_3 -> V_87 , struct V_85 , V_88 ) ;
F_58 ( V_17 ) ;
F_77 ( & V_133 -> V_144 ) ;
V_133 -> V_149 -- ;
F_78 ( & V_133 -> V_144 ) ;
}
static void F_79 ( struct V_81 * V_82 , struct V_2 * V_3 )
{
struct V_1 * V_17 = F_1 ( V_3 ) ;
F_58 ( V_3 -> V_90 ) ;
V_3 -> V_93 = 0 ;
F_57 ( V_3 ) ;
F_58 ( V_17 -> V_20 -> V_25 ) ;
F_59 ( V_17 -> V_28 , V_17 -> V_20 ) ;
}
static struct V_2 * F_80 ( struct V_132 * V_87 )
{
struct V_1 * V_17 ;
struct V_85 * V_133 ;
struct V_150 * V_38 ;
V_17 = F_45 ( sizeof( * V_17 ) , V_91 ) ;
if ( ! V_17 )
return F_68 ( - V_92 ) ;
V_133 = F_2 ( V_87 , struct V_85 , V_88 ) ;
F_77 ( & V_133 -> V_144 ) ;
V_133 -> V_149 ++ ;
F_81 ( V_133 -> V_71 , V_17 -> V_128 ) ;
V_17 -> V_130 = V_133 -> V_151 ;
V_17 -> V_129 = V_133 -> V_129 ;
V_17 -> V_4 . V_152 = F_62 ( V_133 -> V_71 ) ;
F_78 ( & V_133 -> V_144 ) ;
V_17 -> V_4 . V_76 = 0 ;
V_17 -> V_4 . V_153 = sizeof( struct V_15 ) ;
V_17 -> V_4 . V_154 = F_6 ;
V_17 -> V_4 . V_155 = V_156 ;
V_17 -> V_4 . V_5 . V_35 = L_20 ;
V_17 -> V_4 . V_5 . V_157 = F_44 ;
V_17 -> V_4 . V_5 . V_158 = F_79 ;
V_17 -> V_4 . V_5 . V_159 = F_27 ;
V_17 -> V_4 . V_5 . V_160 = F_22 ;
V_17 -> V_4 . V_5 . V_161 = F_36 ;
V_17 -> V_4 . V_5 . V_162 = F_75 ;
V_38 = F_82 ( F_10 , V_17 ) ;
if ( F_33 ( V_38 ) ) {
F_58 ( V_17 ) ;
return F_71 ( V_38 ) ;
}
V_17 -> V_38 = V_38 ;
return & V_17 -> V_4 . V_5 ;
}
