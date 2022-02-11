static inline bool
F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
return ( V_2 -> V_5 &&
V_4 -> V_6 != V_7 ) ;
}
static void
F_2 ( struct V_8 * V_9 , void * V_10 )
{
struct V_1 * V_1 = V_10 ;
F_3 ( L_1 ,
F_4 ( V_9 -> V_11 ) , V_9 -> V_11 , V_1 ) ;
switch ( V_9 -> V_11 ) {
case V_12 :
F_5 ( V_1 -> V_13 , V_12 ) ;
break;
case V_14 :
F_6 ( L_2 ) ;
break;
default:
break;
}
}
static struct V_15 *
F_7 ( struct V_1 * V_1 )
{
struct V_16 * V_17 = V_1 -> V_17 ;
struct V_15 * V_18 ;
int V_19 , V_20 = 0 ;
F_8 ( & V_21 ) ;
for ( V_19 = 0 ; V_19 < V_17 -> V_22 ; V_19 ++ )
if ( V_17 -> V_23 [ V_19 ] . V_24 <
V_17 -> V_23 [ V_20 ] . V_24 )
V_20 = V_19 ;
V_18 = & V_17 -> V_23 [ V_20 ] ;
V_18 -> V_24 ++ ;
F_9 ( & V_21 ) ;
F_10 ( L_3 ,
V_1 , V_18 , V_20 ) ;
return V_18 ;
}
static void
F_11 ( struct V_15 * V_18 )
{
F_8 ( & V_21 ) ;
V_18 -> V_24 -- ;
F_9 ( & V_21 ) ;
}
static struct V_25 *
F_12 ( struct V_1 * V_1 ,
struct V_15 * V_18 ,
struct V_26 * V_27 )
{
struct V_16 * V_17 = V_1 -> V_17 ;
struct V_28 V_29 ;
int V_30 ;
memset ( & V_29 , 0 , sizeof( struct V_28 ) ) ;
V_29 . V_31 = F_2 ;
V_29 . V_32 = V_1 ;
V_29 . V_33 = V_18 -> V_34 ;
V_29 . V_35 = V_18 -> V_34 ;
V_29 . V_36 . V_37 = V_38 + 1 ;
V_29 . V_36 . V_39 = V_40 + 1 ;
V_29 . V_36 . V_41 = V_42 ;
V_29 . V_36 . V_43 = V_17 -> V_44 -> V_45 . V_46 ;
V_29 . V_36 . V_47 = 1 ;
V_29 . V_48 = V_49 ;
V_29 . V_50 = V_51 ;
if ( V_17 -> V_52 )
V_29 . V_53 |= V_54 ;
V_30 = F_13 ( V_27 , V_17 -> V_55 , & V_29 ) ;
if ( V_30 ) {
F_3 ( L_4 , V_30 ) ;
return F_14 ( V_30 ) ;
}
return V_27 -> V_56 ;
}
static int
F_15 ( struct V_1 * V_1 , struct V_26 * V_27 )
{
struct V_15 * V_18 ;
int V_30 ;
V_18 = F_7 ( V_1 ) ;
V_1 -> V_56 = F_12 ( V_1 , V_18 , V_27 ) ;
if ( F_16 ( V_1 -> V_56 ) ) {
V_30 = F_17 ( V_1 -> V_56 ) ;
goto V_57;
}
return 0 ;
V_57:
F_11 ( V_18 ) ;
return V_30 ;
}
static int
F_18 ( struct V_1 * V_1 )
{
struct V_16 * V_17 = V_1 -> V_17 ;
struct V_44 * V_58 = V_17 -> V_44 ;
struct V_59 * V_60 ;
struct V_61 * V_62 ;
T_1 V_63 ;
int V_19 , V_64 ;
V_1 -> V_65 = F_19 ( V_40 *
sizeof( struct V_59 ) , V_66 ) ;
if ( ! V_1 -> V_65 )
return - V_67 ;
V_60 = V_1 -> V_65 ;
for ( V_19 = 0 ; V_19 < V_40 ; V_19 ++ , V_60 ++ ) {
V_63 = F_20 ( V_58 , ( void * ) V_60 ,
V_68 , V_69 ) ;
if ( F_21 ( V_58 , V_63 ) )
goto V_70;
V_60 -> V_63 = V_63 ;
V_62 = & V_60 -> V_62 ;
V_62 -> V_71 = V_60 -> V_63 ;
V_62 -> V_72 = V_68 ;
V_62 -> V_73 = V_17 -> V_55 -> V_74 ;
V_60 -> V_75 . V_76 = V_77 ;
}
return 0 ;
V_70:
V_60 = V_1 -> V_65 ;
for ( V_64 = 0 ; V_64 < V_19 ; V_64 ++ , V_60 ++ ) {
F_22 ( V_58 , V_60 -> V_63 ,
V_68 , V_69 ) ;
}
F_23 ( V_1 -> V_65 ) ;
V_1 -> V_65 = NULL ;
F_3 ( L_5 , V_1 ) ;
return - V_67 ;
}
static void
F_24 ( struct V_1 * V_1 )
{
struct V_44 * V_58 = V_1 -> V_17 -> V_44 ;
struct V_59 * V_60 ;
int V_19 ;
if ( ! V_1 -> V_65 )
return;
V_60 = V_1 -> V_65 ;
for ( V_19 = 0 ; V_19 < V_40 ; V_19 ++ , V_60 ++ ) {
F_22 ( V_58 , V_60 -> V_63 ,
V_68 , V_69 ) ;
}
F_23 ( V_1 -> V_65 ) ;
V_1 -> V_65 = NULL ;
}
static void
F_25 ( struct V_16 * V_17 )
{
int V_19 ;
for ( V_19 = 0 ; V_19 < V_17 -> V_22 ; V_19 ++ ) {
struct V_15 * V_18 = & V_17 -> V_23 [ V_19 ] ;
if ( V_18 -> V_34 )
F_26 ( V_18 -> V_34 ) ;
}
F_23 ( V_17 -> V_23 ) ;
}
static int
F_27 ( struct V_16 * V_17 )
{
int V_19 , V_78 , V_30 = 0 ;
V_17 -> V_22 = V_20 ( V_79 , F_28 ( int , F_29 () ,
V_17 -> V_44 -> V_80 ) ) ;
F_10 ( L_6
L_7 ,
V_17 -> V_22 , V_17 -> V_44 -> V_81 ,
V_17 -> V_44 -> V_80 ,
V_17 -> V_52 ) ;
V_17 -> V_23 = F_30 ( V_17 -> V_22 , sizeof( struct V_15 ) ,
V_66 ) ;
if ( ! V_17 -> V_23 )
return - V_67 ;
V_78 = V_20 ( V_82 , V_17 -> V_44 -> V_45 . V_78 ) ;
for ( V_19 = 0 ; V_19 < V_17 -> V_22 ; V_19 ++ ) {
struct V_15 * V_18 = & V_17 -> V_23 [ V_19 ] ;
V_18 -> V_17 = V_17 ;
V_18 -> V_34 = F_31 ( V_17 -> V_44 , V_18 , V_78 , V_19 ,
V_83 ) ;
if ( F_16 ( V_18 -> V_34 ) ) {
F_3 ( L_8 ) ;
V_30 = F_17 ( V_18 -> V_34 ) ;
V_18 -> V_34 = NULL ;
goto V_84;
}
}
return 0 ;
V_84:
F_25 ( V_17 ) ;
return V_30 ;
}
static int
F_32 ( struct V_16 * V_17 )
{
struct V_44 * V_58 = V_17 -> V_44 ;
int V_30 ;
F_33 ( L_9 , V_58 -> V_45 . V_46 ) ;
F_33 ( L_10 , V_58 -> V_45 . V_85 ) ;
V_30 = F_27 ( V_17 ) ;
if ( V_30 )
goto V_86;
V_17 -> V_55 = F_34 ( V_58 , 0 ) ;
if ( F_16 ( V_17 -> V_55 ) ) {
V_30 = F_17 ( V_17 -> V_55 ) ;
F_3 ( L_11 ,
V_17 , V_30 ) ;
goto V_84;
}
V_17 -> V_52 = V_58 -> V_45 . V_87 &
V_88 ? true : false ;
return 0 ;
V_84:
F_25 ( V_17 ) ;
V_86:
if ( V_30 > 0 )
V_30 = - V_89 ;
return V_30 ;
}
static void
F_35 ( struct V_16 * V_17 )
{
F_10 ( L_12 , V_17 ) ;
F_36 ( V_17 -> V_55 ) ;
F_25 ( V_17 ) ;
}
static void
F_37 ( struct V_16 * V_17 )
{
F_8 ( & V_21 ) ;
V_17 -> V_90 -- ;
F_10 ( L_13 , V_17 , V_17 -> V_90 ) ;
if ( ! V_17 -> V_90 ) {
F_35 ( V_17 ) ;
F_38 ( & V_17 -> V_91 ) ;
F_23 ( V_17 ) ;
}
F_9 ( & V_21 ) ;
}
static struct V_16 *
F_39 ( struct V_26 * V_27 )
{
struct V_16 * V_17 ;
int V_30 ;
F_8 ( & V_21 ) ;
F_40 (device, &device_list, dev_node) {
if ( V_17 -> V_44 -> V_92 == V_27 -> V_17 -> V_92 ) {
V_17 -> V_90 ++ ;
F_10 ( L_14 ,
V_17 , V_17 -> V_90 ) ;
F_9 ( & V_21 ) ;
return V_17 ;
}
}
V_17 = F_19 ( sizeof( struct V_16 ) , V_66 ) ;
if ( ! V_17 ) {
F_9 ( & V_21 ) ;
return F_14 ( - V_67 ) ;
}
F_41 ( & V_17 -> V_91 ) ;
V_17 -> V_44 = V_27 -> V_17 ;
V_30 = F_32 ( V_17 ) ;
if ( V_30 ) {
F_23 ( V_17 ) ;
F_9 ( & V_21 ) ;
return F_14 ( V_30 ) ;
}
V_17 -> V_90 ++ ;
F_42 ( & V_17 -> V_91 , & V_93 ) ;
F_10 ( L_15 ,
V_17 , V_17 -> V_90 ) ;
F_9 ( & V_21 ) ;
return V_17 ;
}
static void
F_43 ( struct V_1 * V_1 )
{
V_1 -> V_94 = V_95 ;
F_41 ( & V_1 -> V_96 ) ;
F_44 ( & V_1 -> V_97 ) ;
F_44 ( & V_1 -> V_98 ) ;
F_45 ( & V_1 -> V_99 ) ;
F_46 ( & V_1 -> V_100 ) ;
F_47 ( & V_1 -> V_101 ) ;
F_48 ( & V_1 -> V_102 , V_103 ) ;
}
static void
F_49 ( struct V_1 * V_1 )
{
struct V_44 * V_58 = V_1 -> V_17 -> V_44 ;
F_22 ( V_58 , V_1 -> V_104 ,
V_68 , V_105 ) ;
F_23 ( V_1 -> V_106 ) ;
F_22 ( V_58 , V_1 -> V_107 ,
V_68 ,
V_69 ) ;
F_23 ( V_1 -> V_108 ) ;
}
static int
F_50 ( struct V_1 * V_1 ,
struct V_44 * V_58 )
{
int V_30 ;
V_1 -> V_108 = F_19 ( sizeof( * V_1 -> V_108 ) ,
V_66 ) ;
if ( ! V_1 -> V_108 )
return - V_67 ;
V_1 -> V_107 = F_20 ( V_58 ,
V_1 -> V_108 ,
V_68 , V_69 ) ;
V_30 = F_21 ( V_58 , V_1 -> V_107 ) ;
if ( V_30 ) {
F_3 ( L_16 , V_30 ) ;
V_1 -> V_107 = 0 ;
goto V_109;
}
V_1 -> V_106 = F_19 ( V_68 , V_66 ) ;
if ( ! V_1 -> V_106 ) {
V_30 = - V_67 ;
goto V_110;
}
V_1 -> V_104 = F_20 ( V_58 ,
V_1 -> V_106 ,
V_68 , V_105 ) ;
V_30 = F_21 ( V_58 , V_1 -> V_104 ) ;
if ( V_30 ) {
F_3 ( L_17 , V_30 ) ;
V_1 -> V_104 = 0 ;
goto V_111;
}
return 0 ;
V_111:
F_23 ( V_1 -> V_106 ) ;
V_110:
F_22 ( V_58 , V_1 -> V_107 ,
V_68 , V_69 ) ;
V_109:
F_23 ( V_1 -> V_108 ) ;
return V_30 ;
}
static void
F_51 ( struct V_1 * V_1 ,
struct V_112 * V_113 )
{
struct V_114 * V_29 = & V_1 -> V_17 -> V_44 -> V_45 ;
V_1 -> V_115 = F_28 ( V_116 , V_113 -> V_115 ,
V_29 -> V_117 ) ;
F_33 ( L_18 , V_1 -> V_115 ) ;
if ( V_113 -> V_118 ) {
V_116 V_119 = * ( V_116 * ) V_113 -> V_118 ;
V_1 -> V_120 = ! ( V_119 & V_121 ) &&
( V_29 -> V_87 &
V_122 ) ;
if ( V_1 -> V_120 )
F_10 ( L_19 ) ;
}
}
static int
F_52 ( struct V_26 * V_27 , struct V_123 * V_11 )
{
struct V_124 * V_124 = V_27 -> V_10 ;
struct V_125 * V_126 = V_124 -> V_126 ;
struct V_1 * V_1 ;
struct V_16 * V_17 ;
int V_30 = 0 ;
F_53 ( & V_126 -> V_127 ) ;
if ( ! V_126 -> V_128 ) {
F_54 ( & V_126 -> V_127 ) ;
F_33 ( L_20 ) ;
return F_55 ( V_27 , NULL , 0 ) ;
}
F_54 ( & V_126 -> V_127 ) ;
F_33 ( L_21 ,
V_27 , V_27 -> V_10 ) ;
V_1 = F_19 ( sizeof( struct V_1 ) , V_66 ) ;
if ( ! V_1 )
return - V_67 ;
F_43 ( V_1 ) ;
V_1 -> V_13 = V_27 ;
V_30 = F_50 ( V_1 , V_27 -> V_17 ) ;
if ( V_30 )
goto V_86;
V_17 = F_39 ( V_27 ) ;
if ( F_16 ( V_17 ) ) {
V_30 = F_17 ( V_17 ) ;
goto V_129;
}
V_1 -> V_17 = V_17 ;
F_51 ( V_1 , & V_11 -> V_113 . V_2 ) ;
V_30 = F_15 ( V_1 , V_27 ) ;
if ( V_30 )
goto V_130;
V_30 = F_56 ( V_1 ) ;
if ( V_30 )
goto V_130;
V_30 = F_57 ( V_1 ) ;
if ( V_30 )
goto V_130;
F_8 ( & V_124 -> V_101 ) ;
F_42 ( & V_1 -> V_96 , & V_124 -> V_131 ) ;
F_9 ( & V_124 -> V_101 ) ;
return 0 ;
V_130:
F_37 ( V_17 ) ;
V_129:
F_49 ( V_1 ) ;
V_86:
F_23 ( V_1 ) ;
F_55 ( V_27 , NULL , 0 ) ;
return V_30 ;
}
static void
F_58 ( struct V_1 * V_1 )
{
struct V_16 * V_17 = V_1 -> V_17 ;
F_33 ( L_22 , V_1 ) ;
F_59 ( ! V_17 ) ;
F_24 ( V_1 ) ;
if ( V_1 -> V_13 &&
! V_1 -> V_132 )
F_60 ( V_1 -> V_13 ) ;
if ( V_1 -> V_56 ) {
struct V_15 * V_18 = V_1 -> V_56 -> V_35 -> V_133 ;
F_11 ( V_18 ) ;
F_61 ( V_1 -> V_56 ) ;
}
if ( V_1 -> V_108 )
F_49 ( V_1 ) ;
F_37 ( V_17 ) ;
if ( V_1 -> V_132 )
F_62 ( & V_1 -> V_99 ) ;
else
F_23 ( V_1 ) ;
}
static void
F_63 ( struct V_26 * V_27 )
{
struct V_1 * V_1 = V_27 -> V_56 -> V_32 ;
struct V_124 * V_124 = V_27 -> V_10 ;
F_10 ( L_22 , V_1 ) ;
F_8 ( & V_1 -> V_101 ) ;
V_1 -> V_94 = V_134 ;
F_64 ( & V_1 -> V_100 ) ;
F_9 ( & V_1 -> V_101 ) ;
F_8 ( & V_124 -> V_101 ) ;
F_65 ( & V_1 -> V_96 , & V_124 -> V_135 ) ;
F_9 ( & V_124 -> V_101 ) ;
F_10 ( L_23 , V_124 ) ;
F_66 ( & V_124 -> V_136 ) ;
}
static void
F_67 ( struct V_100 * V_100 )
{
struct V_1 * V_1 = F_68 ( V_100 ,
struct V_1 , V_100 ) ;
F_10 ( L_24 , V_1 , V_137 -> V_138 ,
V_137 -> V_139 ) ;
F_58 ( V_1 ) ;
}
static void
F_69 ( struct V_1 * V_1 )
{
F_70 ( & V_1 -> V_100 , F_67 ) ;
}
static void
F_71 ( struct V_1 * V_1 )
{
struct V_124 * V_124 = V_1 -> V_13 -> V_10 ;
F_8 ( & V_124 -> V_101 ) ;
if ( ! F_72 ( & V_1 -> V_96 ) ) {
F_73 ( & V_1 -> V_96 ) ;
F_69 ( V_1 ) ;
F_74 ( V_140 , & V_1 -> V_102 ) ;
}
F_9 ( & V_124 -> V_101 ) ;
}
static void
F_75 ( struct V_1 * V_1 )
{
int V_57 ;
if ( V_1 -> V_94 >= V_141 )
return;
F_10 ( L_25 ,
V_1 , V_1 -> V_94 ) ;
V_1 -> V_94 = V_141 ;
V_57 = F_76 ( V_1 -> V_13 ) ;
if ( V_57 )
F_6 ( L_26 ,
V_1 ) ;
}
static int
F_77 ( struct V_124 * V_124 ,
enum V_142 V_11 )
{
F_33 ( L_27 ,
F_78 ( V_11 ) , V_11 , V_124 ) ;
switch ( V_11 ) {
case V_143 :
V_124 -> V_13 = NULL ;
break;
case V_144 :
V_124 -> V_13 = F_79 ( V_124 ) ;
if ( F_16 ( V_124 -> V_13 ) ) {
F_3 ( L_28 ,
V_124 , F_17 ( V_124 -> V_13 ) ) ;
V_124 -> V_13 = NULL ;
}
break;
default:
F_3 ( L_29 ,
V_124 , V_11 ) ;
}
return - 1 ;
}
static int
F_80 ( struct V_26 * V_27 ,
enum V_142 V_11 )
{
struct V_1 * V_1 = V_27 -> V_56 -> V_32 ;
F_8 ( & V_1 -> V_101 ) ;
switch ( V_1 -> V_94 ) {
case V_141 :
break;
case V_134 :
F_75 ( V_1 ) ;
F_81 ( V_1 -> V_56 ) ;
F_71 ( V_1 ) ;
break;
case V_145 :
case V_146 :
F_82 ( V_1 -> V_2 , 0 ) ;
break;
default:
F_6 ( L_30 ,
V_1 , V_1 -> V_94 ) ;
}
F_9 ( & V_1 -> V_101 ) ;
return 0 ;
}
static int
F_83 ( struct V_26 * V_27 )
{
struct V_1 * V_1 = V_27 -> V_56 -> V_32 ;
F_73 ( & V_1 -> V_96 ) ;
V_1 -> V_13 = NULL ;
F_69 ( V_1 ) ;
return - 1 ;
}
static int
F_84 ( struct V_26 * V_27 , struct V_123 * V_11 )
{
struct V_124 * V_124 = V_27 -> V_10 ;
struct V_1 * V_1 ;
int V_30 = 0 ;
F_10 ( L_31 ,
F_78 ( V_11 -> V_11 ) , V_11 -> V_11 ,
V_11 -> V_147 , V_27 , V_27 -> V_10 ) ;
if ( V_124 -> V_13 == V_27 )
return F_77 ( V_27 -> V_10 , V_11 -> V_11 ) ;
switch ( V_11 -> V_11 ) {
case V_148 :
V_30 = F_52 ( V_27 , V_11 ) ;
if ( V_30 )
F_3 ( L_32 , V_30 ) ;
break;
case V_149 :
F_63 ( V_27 ) ;
break;
case V_144 :
case V_150 :
case V_151 :
V_30 = F_80 ( V_27 , V_11 -> V_11 ) ;
break;
case V_143 :
V_1 = V_27 -> V_56 -> V_32 ;
V_1 -> V_132 = true ;
F_80 ( V_27 , V_11 -> V_11 ) ;
F_85 ( V_1 -> V_99 ,
V_1 -> V_94 == V_152 ) ;
F_23 ( V_1 ) ;
return 1 ;
case V_153 :
F_10 ( L_33 ,
F_86 ( V_27 , V_11 -> V_147 ) ) ;
case V_154 :
case V_155 :
V_30 = F_83 ( V_27 ) ;
break;
default:
F_3 ( L_34 , V_11 -> V_11 ) ;
break;
}
return V_30 ;
}
static int
F_87 ( struct V_1 * V_1 , T_2 V_156 )
{
struct V_157 * V_158 , * V_159 ;
int V_19 , V_30 ;
struct V_59 * V_60 ;
for ( V_158 = V_1 -> V_158 , V_19 = 0 ; V_19 < V_156 ; V_19 ++ , V_158 ++ ) {
V_60 = & V_1 -> V_65 [ V_19 ] ;
V_158 -> V_160 = & V_60 -> V_75 ;
V_158 -> V_161 = & V_60 -> V_62 ;
V_158 -> V_162 = 1 ;
V_158 -> V_163 = V_158 + 1 ;
}
V_158 -- ;
V_158 -> V_163 = NULL ;
V_30 = F_88 ( V_1 -> V_56 , V_1 -> V_158 ,
& V_159 ) ;
if ( V_30 )
F_3 ( L_35 , V_30 ) ;
return V_30 ;
}
static int
F_89 ( struct V_1 * V_1 , struct V_59 * V_60 )
{
struct V_157 * V_159 , V_158 ;
int V_30 ;
V_158 . V_160 = & V_60 -> V_75 ;
V_158 . V_161 = & V_60 -> V_62 ;
V_158 . V_162 = 1 ;
V_158 . V_163 = NULL ;
V_30 = F_88 ( V_1 -> V_56 , & V_158 , & V_159 ) ;
if ( V_30 )
F_3 ( L_35 , V_30 ) ;
return V_30 ;
}
static int
F_90 ( struct V_1 * V_1 , struct V_164 * V_165 )
{
struct V_44 * V_58 = V_1 -> V_13 -> V_17 ;
struct V_166 V_167 , * V_168 ;
int V_30 ;
F_91 ( V_58 , V_165 -> V_63 ,
V_169 , V_105 ) ;
V_165 -> V_170 . V_76 = V_171 ;
V_167 . V_163 = NULL ;
V_167 . V_160 = & V_165 -> V_170 ;
V_167 . V_161 = V_165 -> V_172 ;
V_167 . V_162 = V_165 -> V_162 ;
V_167 . V_173 = V_174 ;
V_167 . V_175 = V_176 ;
V_30 = F_92 ( V_1 -> V_56 , & V_167 , & V_168 ) ;
if ( V_30 )
F_3 ( L_36 , V_30 ) ;
return V_30 ;
}
static void
F_93 ( struct V_1 * V_1 ,
struct V_177 * V_177 ,
struct V_164 * V_165 )
{
struct V_16 * V_17 = V_1 -> V_17 ;
struct V_44 * V_58 = V_17 -> V_44 ;
F_94 ( V_58 , V_165 -> V_63 ,
V_169 , V_105 ) ;
memset ( & V_165 -> V_178 , 0 , sizeof( struct V_179 ) ) ;
V_165 -> V_178 . V_119 = V_180 ;
V_165 -> V_162 = 1 ;
if ( V_165 -> V_172 [ 0 ] . V_73 != V_17 -> V_55 -> V_74 ) {
V_165 -> V_172 [ 0 ] . V_73 = V_17 -> V_55 -> V_74 ;
F_33 ( L_37 , V_165 ) ;
}
}
static int
F_95 ( struct V_1 * V_1 ,
struct V_164 * V_165 )
{
struct V_16 * V_17 = V_1 -> V_17 ;
struct V_44 * V_58 = V_17 -> V_44 ;
T_1 V_63 ;
V_63 = F_20 ( V_58 , ( void * ) V_165 ,
V_169 , V_105 ) ;
if ( F_21 ( V_58 , V_63 ) ) {
F_3 ( L_38 ) ;
return - V_67 ;
}
V_165 -> V_63 = V_63 ;
V_165 -> V_172 [ 0 ] . V_71 = V_165 -> V_63 ;
V_165 -> V_172 [ 0 ] . V_72 = V_169 ;
V_165 -> V_172 [ 0 ] . V_73 = V_17 -> V_55 -> V_74 ;
F_33 ( L_39 ,
V_165 -> V_172 [ 0 ] . V_71 , V_165 -> V_172 [ 0 ] . V_72 ,
V_165 -> V_172 [ 0 ] . V_73 ) ;
return 0 ;
}
static void
F_96 ( struct V_1 * V_1 , struct V_177 * V_177 ,
struct V_166 * V_167 )
{
struct V_164 * V_165 = & V_177 -> V_165 ;
V_165 -> V_170 . V_76 = V_181 ;
V_167 -> V_160 = & V_165 -> V_170 ;
if ( V_1 -> V_120 && V_177 -> V_182 ) {
V_167 -> V_173 = V_183 ;
V_167 -> V_184 . V_185 = V_177 -> V_182 ;
} else {
V_167 -> V_173 = V_174 ;
}
V_167 -> V_161 = & V_165 -> V_172 [ 0 ] ;
V_167 -> V_162 = V_177 -> V_165 . V_162 ;
V_167 -> V_175 = V_176 ;
}
static int
F_56 ( struct V_1 * V_1 )
{
struct V_157 V_158 , * V_186 ;
struct V_61 V_187 ;
int V_30 ;
memset ( & V_187 , 0 , sizeof( struct V_61 ) ) ;
V_187 . V_71 = V_1 -> V_107 ;
V_187 . V_72 = V_68 ;
V_187 . V_73 = V_1 -> V_17 -> V_55 -> V_74 ;
F_33 ( L_40 ,
V_187 . V_71 , V_187 . V_72 , V_187 . V_73 ) ;
V_1 -> V_108 -> V_75 . V_76 = V_188 ;
memset ( & V_158 , 0 , sizeof( struct V_157 ) ) ;
V_158 . V_160 = & V_1 -> V_108 -> V_75 ;
V_158 . V_161 = & V_187 ;
V_158 . V_162 = 1 ;
V_30 = F_88 ( V_1 -> V_56 , & V_158 , & V_186 ) ;
if ( V_30 )
F_3 ( L_41 , V_30 ) ;
return V_30 ;
}
static int
F_97 ( struct V_189 * V_2 , struct V_190 * V_191 ,
T_2 V_72 )
{
struct V_1 * V_1 = V_2 -> V_10 ;
struct V_16 * V_17 = V_1 -> V_17 ;
struct V_44 * V_58 = V_17 -> V_44 ;
struct V_164 * V_165 = & V_1 -> V_192 ;
int V_30 ;
F_93 ( V_1 , NULL , V_165 ) ;
memcpy ( & V_165 -> V_193 , & V_191 -> V_194 [ 0 ] ,
sizeof( struct V_195 ) ) ;
F_95 ( V_1 , V_165 ) ;
if ( V_72 > 0 ) {
struct V_61 * V_196 = & V_165 -> V_172 [ 1 ] ;
F_94 ( V_58 , V_1 -> V_104 ,
V_72 , V_105 ) ;
memcpy ( V_1 -> V_106 , V_191 -> V_197 , V_72 ) ;
F_91 ( V_58 , V_1 -> V_104 ,
V_72 , V_105 ) ;
V_196 -> V_71 = V_1 -> V_104 ;
V_196 -> V_72 = V_72 ;
V_196 -> V_73 = V_1 -> V_17 -> V_55 -> V_74 ;
V_165 -> V_162 = 2 ;
}
if ( ! V_191 -> V_198 ) {
if ( V_191 -> V_199 ) {
V_30 = F_18 ( V_1 ) ;
if ( V_30 )
return V_30 ;
V_30 = F_87 ( V_1 ,
V_40 ) ;
if ( V_30 )
return V_30 ;
F_8 ( & V_1 -> V_101 ) ;
V_1 -> V_94 = V_146 ;
F_9 ( & V_1 -> V_101 ) ;
goto V_200;
}
V_30 = F_56 ( V_1 ) ;
if ( V_30 )
return V_30 ;
}
V_200:
V_30 = F_90 ( V_1 , V_165 ) ;
if ( V_30 )
return V_30 ;
return 0 ;
}
static void
F_98 ( struct V_1 * V_1 )
{
struct V_59 * V_60 = V_1 -> V_108 ;
int V_201 = V_1 -> V_202 ;
struct V_189 * V_2 = V_1 -> V_2 ;
struct V_190 * V_191 = V_2 -> V_203 ;
int V_204 ;
F_10 ( L_22 , V_1 ) ;
F_99 ( ! V_191 ) ;
if ( V_191 -> V_205 ) {
struct V_206 * V_207 =
(struct V_206 * ) & V_60 -> V_193 ;
V_191 -> V_208 = ( ! V_207 -> V_209 ) ? 1 : 0 ;
V_191 -> V_210 =
( V_207 -> V_119 & V_211 )
>> 2 ;
V_191 -> V_212 = V_207 -> V_213 ;
V_191 -> V_214 = V_207 -> V_215 ;
memcpy ( V_191 -> V_216 , V_207 -> V_216 , 6 ) ;
V_191 -> V_217 = F_100 ( V_207 -> V_218 ) ;
V_191 -> V_219 = V_207 -> V_220 ;
V_191 -> V_221 = F_100 ( V_207 -> V_222 ) ;
V_191 -> V_223 = F_101 ( V_207 -> V_223 ) ;
V_191 -> V_209 = F_101 ( V_207 -> V_209 ) ;
}
memcpy ( & V_191 -> V_224 [ 0 ] , ( void * ) & V_60 -> V_193 , V_225 ) ;
V_204 = V_20 ( V_201 , V_226 ) ;
F_33 ( L_42
L_43 , V_204 , V_201 ,
V_226 ) ;
memcpy ( V_191 -> V_227 , & V_60 -> V_228 [ 0 ] , V_204 ) ;
if ( V_191 -> V_205 ) {
F_102 ( & V_1 -> V_97 ) ;
return;
}
F_103 ( & V_2 -> V_229 , 0 ) ;
}
static struct V_230
* F_104 ( struct V_189 * V_2 , struct V_59 * V_60 )
{
struct V_1 * V_1 = V_2 -> V_10 ;
struct V_177 * V_177 ;
struct V_230 * V_4 ;
V_4 = F_105 ( V_2 , V_231 ) ;
if ( ! V_4 ) {
F_3 ( L_44 ) ;
return NULL ;
}
V_177 = F_106 ( V_4 ) ;
V_177 -> V_2 = V_1 ;
V_177 -> V_230 = V_4 ;
V_177 -> V_60 = V_60 ;
return V_4 ;
}
static int
F_107 ( struct V_1 * V_1 ,
struct V_177 * V_177 , struct V_230 * V_4 ,
struct V_59 * V_60 , unsigned char * V_232 )
{
struct V_189 * V_2 = V_1 -> V_2 ;
struct V_233 * V_234 = (struct V_233 * ) V_232 ;
int V_235 , V_236 , V_237 , V_238 , V_239 ;
bool V_240 = false ;
unsigned int V_241 ;
V_239 = F_108 ( V_2 , V_4 , V_232 ) ;
if ( V_239 < 0 )
return V_239 ;
V_235 = V_4 -> V_242 ;
V_236 = V_4 -> V_243 ;
V_237 = V_4 -> V_244 ;
V_241 = V_4 -> V_3 . V_245 ;
if ( V_235 && V_236 == V_241 )
V_4 -> V_3 . V_246 |= V_247 ;
V_239 = F_109 ( V_2 , V_4 , V_234 ) ;
if ( V_239 < 0 ) {
return 0 ;
} else if ( V_239 > 0 ) {
V_240 = true ;
goto V_248;
}
if ( ! V_235 )
return 0 ;
if ( V_236 != V_241 ) {
V_238 = F_110 ( 1UL , F_111 ( V_236 , V_249 ) ) ;
F_112 ( V_4 -> V_3 . V_250 , V_238 ,
& V_60 -> V_228 [ 0 ] , V_236 ) ;
F_33 ( L_45 ,
V_238 , V_236 ) ;
} else {
F_113 ( & V_177 -> V_251 , 1 ) ;
V_4 -> V_3 . V_250 = & V_177 -> V_251 ;
V_4 -> V_3 . V_252 = 1 ;
F_114 ( & V_177 -> V_251 , & V_60 -> V_228 [ 0 ] , V_236 ) ;
F_33 ( L_46 ,
V_236 ) ;
}
V_4 -> V_253 += V_236 ;
if ( V_4 -> V_253 == V_4 -> V_3 . V_245 ) {
F_53 ( & V_4 -> V_254 ) ;
V_4 -> V_255 |= V_256 ;
V_4 -> V_257 = V_258 ;
F_54 ( & V_4 -> V_254 ) ;
}
V_248:
V_239 = F_115 ( V_2 , V_4 , V_232 , V_234 -> V_218 ) ;
if ( ! V_239 && V_240 == false && V_237 )
F_116 ( V_4 ) ;
else if ( V_240 && V_235 )
F_117 ( & V_4 -> V_3 ) ;
return 0 ;
}
static int
F_118 ( struct V_1 * V_1 ,
struct V_59 * V_60 , unsigned char * V_232 )
{
struct V_259 * V_260 ;
struct V_189 * V_2 = V_1 -> V_2 ;
struct V_230 * V_4 = NULL ;
struct V_261 * V_234 = (struct V_261 * ) V_232 ;
T_2 V_262 = F_119 ( V_234 -> V_263 ) ;
int V_239 , V_238 , V_264 , V_265 ;
V_239 = F_120 ( V_2 , V_232 , & V_4 ) ;
if ( V_239 < 0 )
return V_239 ;
else if ( ! V_4 )
return 0 ;
if ( ! V_4 -> V_244 ) {
F_3 ( L_47 ) ;
F_121 () ;
return - 1 ;
}
F_33 ( L_48
L_49 ,
V_262 , V_4 -> V_253 ,
V_4 -> V_3 . V_245 ) ;
V_264 = V_4 -> V_253 / V_249 ;
V_260 = & V_4 -> V_3 . V_250 [ V_264 ] ;
V_238 = F_110 ( 1UL , F_111 ( V_262 , V_249 ) ) ;
V_265 = V_4 -> V_253 % V_249 ;
if ( V_265 ) {
F_3 ( L_50 ) ;
F_121 () ;
return - 1 ;
}
F_33 ( L_51
L_52 , V_260 , V_264 ,
V_238 , & V_60 -> V_228 [ 0 ] , V_262 ) ;
F_112 ( V_260 , V_238 , & V_60 -> V_228 [ 0 ] ,
V_262 ) ;
V_239 = F_122 ( V_4 , V_234 , false ) ;
if ( V_239 < 0 )
return V_239 ;
V_239 = F_89 ( V_1 , V_60 ) ;
if ( V_239 ) {
F_3 ( L_53 , V_239 ) ;
return V_239 ;
}
return 0 ;
}
static int
F_123 ( struct V_1 * V_1 , struct V_177 * V_177 ,
struct V_230 * V_4 , struct V_59 * V_60 ,
unsigned char * V_232 )
{
struct V_189 * V_2 = V_1 -> V_2 ;
struct V_266 * V_234 = (struct V_266 * ) V_232 ;
int V_239 ;
V_239 = F_124 ( V_2 , V_4 , V_234 ) ;
if ( V_239 < 0 )
return V_239 ;
return F_125 ( V_2 , V_4 , V_234 ) ;
}
static int
F_126 ( struct V_1 * V_1 , struct V_177 * V_177 ,
struct V_230 * V_4 , struct V_59 * V_60 ,
struct V_267 * V_234 )
{
struct V_189 * V_2 = V_1 -> V_2 ;
T_2 V_268 = F_119 ( V_234 -> V_263 ) ;
int V_239 ;
unsigned char * V_269 = NULL ;
V_239 = F_127 ( V_2 , V_4 , V_234 ) ;
if ( V_239 < 0 )
return V_239 ;
if ( V_268 ) {
V_269 = F_19 ( V_268 , V_66 ) ;
if ( ! V_269 )
return - V_67 ;
}
V_4 -> V_270 = V_269 ;
memcpy ( V_4 -> V_270 , & V_60 -> V_228 [ 0 ] , V_268 ) ;
return F_128 ( V_2 , V_4 , V_234 ) ;
}
static int
F_129 ( struct V_1 * V_1 , struct V_59 * V_60 ,
T_3 V_271 , T_4 V_272 ,
T_3 V_273 , T_4 V_274 )
{
struct V_195 * V_234 = & V_60 -> V_193 ;
struct V_189 * V_2 = V_1 -> V_2 ;
struct V_230 * V_4 ;
struct V_177 * V_177 ;
int V_30 = - V_89 ;
V_116 V_173 = ( V_234 -> V_173 & V_275 ) ;
if ( V_2 -> V_276 -> V_277 -> V_278 &&
( ! ( V_173 & V_279 ) || ! ( V_173 & V_280 ) ) ) {
F_3 ( L_54
L_55 , V_173 ) ;
return 0 ;
}
switch ( V_173 ) {
case V_281 :
V_4 = F_104 ( V_2 , V_60 ) ;
if ( ! V_4 )
break;
V_177 = F_106 ( V_4 ) ;
V_177 -> V_271 = V_271 ;
V_177 -> V_272 = V_272 ;
V_177 -> V_273 = V_273 ;
V_177 -> V_274 = V_274 ;
V_177 -> V_182 = V_271 ? V_271 : V_273 ;
V_30 = F_107 ( V_1 , V_177 , V_4 ,
V_60 , ( unsigned char * ) V_234 ) ;
break;
case V_282 :
V_4 = F_104 ( V_2 , V_60 ) ;
if ( ! V_4 )
break;
V_177 = F_106 ( V_4 ) ;
V_30 = F_123 ( V_1 , V_177 , V_4 ,
V_60 , ( unsigned char * ) V_234 ) ;
break;
case V_283 :
V_30 = F_118 ( V_1 , V_60 ,
( unsigned char * ) V_234 ) ;
break;
case V_284 :
V_4 = F_104 ( V_2 , V_60 ) ;
if ( ! V_4 )
break;
V_30 = F_130 ( V_2 , V_4 ,
( unsigned char * ) V_234 ) ;
break;
case V_280 :
V_4 = F_104 ( V_2 , V_60 ) ;
if ( ! V_4 )
break;
V_30 = F_131 ( V_2 , V_4 , ( unsigned char * ) V_234 ) ;
break;
case V_279 :
if ( F_100 ( V_234 -> V_285 ) != 0xFFFFFFFF )
V_4 = F_132 ( V_2 , V_234 -> V_220 ) ;
else
V_4 = F_104 ( V_2 , V_60 ) ;
if ( ! V_4 )
break;
V_177 = F_106 ( V_4 ) ;
V_30 = F_126 ( V_1 , V_177 , V_4 ,
V_60 , (struct V_267 * ) V_234 ) ;
break;
default:
F_3 ( L_56 , V_173 ) ;
F_121 () ;
break;
}
return V_30 ;
}
static void
F_133 ( struct V_286 * V_287 , const char * type )
{
if ( V_287 -> V_147 != V_288 )
F_3 ( L_57 , type ,
F_134 ( V_287 -> V_147 ) , V_287 -> V_147 ,
V_287 -> V_289 ) ;
else
F_33 ( L_58 , type ,
F_134 ( V_287 -> V_147 ) , V_287 -> V_147 ) ;
}
static void
V_77 ( struct V_290 * V_34 , struct V_286 * V_287 )
{
struct V_1 * V_1 = V_287 -> V_56 -> V_32 ;
struct V_44 * V_58 = V_1 -> V_13 -> V_17 ;
struct V_59 * V_60 = F_135 ( V_287 -> V_160 ) ;
struct V_195 * V_234 = & V_60 -> V_193 ;
struct V_179 * V_179 = & V_60 -> V_178 ;
T_4 V_272 = 0 , V_274 = 0 ;
T_3 V_271 = 0 , V_273 = 0 ;
if ( F_136 ( V_287 -> V_147 != V_291 ) ) {
F_133 ( V_287 , L_59 ) ;
if ( V_287 -> V_147 != V_288 )
F_82 ( V_1 -> V_2 , 0 ) ;
return;
}
F_94 ( V_58 , V_60 -> V_63 ,
V_68 , V_69 ) ;
F_33 ( L_60 ,
V_60 -> V_63 , V_234 -> V_173 , V_234 -> V_220 , V_234 -> V_119 ,
( int ) ( V_287 -> V_292 - V_169 ) ) ;
switch ( V_179 -> V_119 & 0xF0 ) {
case V_180 :
if ( V_179 -> V_119 & V_293 ) {
V_271 = F_100 ( V_179 -> V_271 ) ;
V_272 = F_137 ( V_179 -> V_272 ) ;
F_33 ( L_61 ,
V_271 , ( unsigned long long ) V_272 ) ;
}
if ( V_179 -> V_119 & V_294 ) {
V_273 = F_100 ( V_179 -> V_273 ) ;
V_274 = F_137 ( V_179 -> V_274 ) ;
F_33 ( L_62 ,
V_273 , ( unsigned long long ) V_274 ) ;
}
F_33 ( L_63 ) ;
break;
case V_295 :
F_3 ( L_64 ) ;
break;
default:
F_6 ( L_65 , V_179 -> V_119 ) ;
break;
}
F_129 ( V_1 , V_60 ,
V_271 , V_272 , V_273 , V_274 ) ;
F_91 ( V_58 , V_60 -> V_63 ,
V_68 , V_69 ) ;
}
static void
V_188 ( struct V_290 * V_34 , struct V_286 * V_287 )
{
struct V_1 * V_1 = V_287 -> V_56 -> V_32 ;
struct V_44 * V_58 = V_1 -> V_13 -> V_17 ;
if ( F_136 ( V_287 -> V_147 != V_291 ) ) {
F_133 ( V_287 , L_66 ) ;
return;
}
F_94 ( V_58 , V_1 -> V_107 ,
V_68 , V_69 ) ;
V_1 -> V_202 = V_287 -> V_292 - V_169 ;
if ( V_1 -> V_2 ) {
struct V_190 * V_191 = V_1 -> V_2 -> V_203 ;
if ( V_191 && ! V_191 -> V_205 )
F_98 ( V_1 ) ;
}
F_8 ( & V_1 -> V_101 ) ;
F_102 ( & V_1 -> V_98 ) ;
F_9 ( & V_1 -> V_101 ) ;
F_91 ( V_58 , V_1 -> V_107 ,
V_68 , V_69 ) ;
}
static void
F_138 ( struct V_177 * V_4 , struct V_1 * V_2 )
{
struct V_3 * V_3 = & V_4 -> V_230 -> V_3 ;
enum V_296 V_297 = F_139 ( V_3 ) ;
if ( ! V_4 -> V_298 . V_299 )
return;
if ( F_1 ( V_2 , V_3 ) ) {
F_140 ( & V_4 -> V_298 , V_2 -> V_56 ,
V_2 -> V_13 -> V_300 , V_3 -> V_250 ,
V_3 -> V_252 , V_3 -> V_301 ,
V_3 -> V_302 , V_297 ) ;
} else {
F_141 ( & V_4 -> V_298 , V_2 -> V_56 , V_2 -> V_13 -> V_300 ,
V_3 -> V_250 , V_3 -> V_252 , V_297 ) ;
}
V_4 -> V_298 . V_299 = 0 ;
}
static void
F_142 ( struct V_177 * V_177 , bool V_303 )
{
struct V_230 * V_4 = V_177 -> V_230 ;
struct V_1 * V_1 = V_177 -> V_2 ;
struct V_189 * V_2 = V_1 -> V_2 ;
struct V_304 * V_234 ;
F_33 ( L_67 , V_177 ) ;
switch ( V_4 -> V_305 ) {
case V_281 :
F_53 ( & V_2 -> V_306 ) ;
if ( ! F_72 ( & V_4 -> V_307 ) )
F_73 ( & V_4 -> V_307 ) ;
F_54 ( & V_2 -> V_306 ) ;
if ( V_4 -> V_308 == V_105 ) {
F_143 ( V_4 ) ;
if ( V_303 &&
V_4 -> V_3 . V_309 == V_310 ) {
struct V_3 * V_3 = & V_4 -> V_3 ;
F_117 ( V_3 ) ;
}
}
F_138 ( V_177 , V_1 ) ;
F_144 ( & V_4 -> V_3 , 0 ) ;
break;
case V_284 :
F_53 ( & V_2 -> V_306 ) ;
if ( ! F_72 ( & V_4 -> V_307 ) )
F_73 ( & V_4 -> V_307 ) ;
F_54 ( & V_2 -> V_306 ) ;
F_144 ( & V_4 -> V_3 , 0 ) ;
break;
case V_311 :
case V_282 :
case V_279 :
V_234 = (struct V_304 * ) & V_177 -> V_165 . V_193 ;
if ( V_234 -> V_119 & V_312 )
break;
F_53 ( & V_2 -> V_306 ) ;
if ( ! F_72 ( & V_4 -> V_307 ) )
F_73 ( & V_4 -> V_307 ) ;
F_54 ( & V_2 -> V_306 ) ;
if ( V_4 -> V_3 . V_313 != NULL ) {
F_33 ( L_68 ,
V_4 -> V_305 ) ;
F_144 ( & V_4 -> V_3 , 0 ) ;
break;
}
default:
F_145 ( V_4 ) ;
break;
}
}
static void
F_146 ( struct V_164 * V_165 , struct V_44 * V_58 )
{
if ( V_165 -> V_63 != 0 ) {
F_33 ( L_69 ) ;
F_22 ( V_58 , V_165 -> V_63 ,
V_169 , V_105 ) ;
V_165 -> V_63 = 0 ;
}
}
static void
F_147 ( struct V_164 * V_165 , struct V_177 * V_177 ,
struct V_44 * V_58 , bool V_303 )
{
if ( V_177 -> V_314 != 0 ) {
F_33 ( L_70 ) ;
F_22 ( V_58 , V_177 -> V_314 ,
V_177 -> V_315 , V_105 ) ;
V_177 -> V_314 = 0 ;
}
F_146 ( V_165 , V_58 ) ;
F_142 ( V_177 , V_303 ) ;
}
static int
F_148 ( struct V_3 * V_3 , struct V_316 * V_317 )
{
struct V_318 V_319 ;
int V_30 ;
V_30 = F_149 ( V_317 , V_320 , & V_319 ) ;
if ( V_30 ) {
F_3 ( L_71 , V_30 ) ;
goto V_321;
}
if ( V_319 . V_322 & V_320 ) {
T_1 V_323 ;
T_2 V_324 = V_3 -> V_325 -> V_326 . V_324 + 8 ;
switch ( V_319 . V_327 . V_328 ) {
case V_329 :
V_3 -> V_330 = V_331 ;
break;
case V_332 :
V_3 -> V_330 = V_333 ;
break;
case V_334 :
V_3 -> V_330 = V_335 ;
break;
}
V_323 = V_319 . V_327 . V_336 ;
F_150 ( V_323 , V_324 ) ;
V_3 -> V_337 = V_323 + V_3 -> V_338 ;
F_3 ( L_72
L_73 ,
V_319 . V_327 . V_328 ,
( unsigned long long ) V_3 -> V_337 ,
V_319 . V_327 . V_339 ,
V_319 . V_327 . V_340 ) ;
V_30 = 1 ;
}
V_321:
return V_30 ;
}
static void
F_151 ( struct V_290 * V_34 , struct V_286 * V_287 )
{
struct V_1 * V_1 = V_287 -> V_56 -> V_32 ;
struct V_16 * V_17 = V_1 -> V_17 ;
struct V_164 * V_341 = F_152 ( V_287 -> V_160 ) ;
struct V_177 * V_177 = F_153 ( V_341 ) ;
struct V_3 * V_4 = & V_177 -> V_230 -> V_3 ;
int V_30 = 0 ;
if ( F_136 ( V_287 -> V_147 != V_291 ) ) {
F_133 ( V_287 , L_74 ) ;
if ( V_287 -> V_147 != V_288 )
F_82 ( V_1 -> V_2 , 0 ) ;
F_147 ( V_341 , V_177 , V_17 -> V_44 , true ) ;
return;
}
F_33 ( L_67 , V_177 ) ;
V_30 = F_148 ( V_4 , V_177 -> V_298 . V_342 -> V_317 ) ;
F_138 ( V_177 , V_1 ) ;
if ( V_30 )
F_154 ( V_4 , V_4 -> V_330 , 0 ) ;
else
F_155 ( V_1 -> V_2 , V_177 -> V_230 ) ;
}
static void
F_156 ( struct V_290 * V_34 , struct V_286 * V_287 )
{
struct V_1 * V_1 = V_287 -> V_56 -> V_32 ;
struct V_16 * V_17 = V_1 -> V_17 ;
struct V_164 * V_341 = F_152 ( V_287 -> V_160 ) ;
struct V_177 * V_177 = F_153 ( V_341 ) ;
struct V_230 * V_4 = V_177 -> V_230 ;
struct V_3 * V_3 = & V_4 -> V_3 ;
int V_30 = 0 ;
if ( F_136 ( V_287 -> V_147 != V_291 ) ) {
F_133 ( V_287 , L_75 ) ;
if ( V_287 -> V_147 != V_288 )
F_82 ( V_1 -> V_2 , 0 ) ;
F_147 ( V_341 , V_177 , V_17 -> V_44 , true ) ;
return;
}
F_33 ( L_67 , V_177 ) ;
F_143 ( V_4 ) ;
if ( F_1 ( V_1 , V_3 ) )
V_30 = F_148 ( V_3 , V_177 -> V_298 . V_342 -> V_317 ) ;
F_138 ( V_177 , V_1 ) ;
V_4 -> V_253 = 0 ;
F_33 ( L_76 , V_177 ) ;
F_53 ( & V_4 -> V_254 ) ;
V_4 -> V_255 |= V_256 ;
V_4 -> V_257 = V_258 ;
F_54 ( & V_4 -> V_254 ) ;
if ( V_30 ) {
F_117 ( V_3 ) ;
F_154 ( V_3 ,
V_3 -> V_330 , 0 ) ;
} else {
F_157 ( V_3 ) ;
}
}
static void
F_158 ( struct V_343 * V_344 )
{
struct V_177 * V_177 = F_68 ( V_344 ,
struct V_177 , V_345 ) ;
struct V_1 * V_1 = V_177 -> V_2 ;
struct V_44 * V_58 = V_1 -> V_13 -> V_17 ;
struct V_230 * V_4 = V_177 -> V_230 ;
F_33 ( L_77 , V_177 , V_4 -> V_257 ) ;
switch ( V_4 -> V_257 ) {
case V_346 :
F_159 ( V_4 , V_4 -> V_2 ) ;
case V_347 :
case V_348 :
V_4 -> V_257 = V_349 ;
F_147 ( & V_177 -> V_165 , V_177 ,
V_58 , false ) ;
break;
case V_350 :
F_160 ( V_4 , V_4 -> V_2 ) ;
break;
default:
F_3 ( L_78 , V_4 -> V_257 ) ;
F_121 () ;
break;
}
}
static void
V_171 ( struct V_290 * V_34 , struct V_286 * V_287 )
{
struct V_1 * V_1 = V_287 -> V_56 -> V_32 ;
struct V_44 * V_58 = V_1 -> V_13 -> V_17 ;
struct V_164 * V_165 = F_152 ( V_287 -> V_160 ) ;
if ( F_136 ( V_287 -> V_147 != V_291 ) ) {
F_133 ( V_287 , L_79 ) ;
if ( V_287 -> V_147 != V_288 )
F_82 ( V_1 -> V_2 , 0 ) ;
}
F_146 ( V_165 , V_58 ) ;
}
static void
V_181 ( struct V_290 * V_34 , struct V_286 * V_287 )
{
struct V_1 * V_1 = V_287 -> V_56 -> V_32 ;
struct V_44 * V_58 = V_1 -> V_13 -> V_17 ;
struct V_164 * V_165 = F_152 ( V_287 -> V_160 ) ;
struct V_177 * V_177 = F_153 ( V_165 ) ;
if ( F_136 ( V_287 -> V_147 != V_291 ) ) {
F_133 ( V_287 , L_80 ) ;
if ( V_287 -> V_147 != V_288 )
F_82 ( V_1 -> V_2 , 0 ) ;
F_147 ( V_165 , V_177 , V_58 , true ) ;
return;
}
F_33 ( L_67 , V_177 ) ;
switch ( V_177 -> V_230 -> V_257 ) {
case V_346 :
case V_350 :
case V_347 :
case V_348 :
F_146 ( V_165 , V_58 ) ;
F_48 ( & V_177 -> V_345 , F_158 ) ;
F_74 ( V_351 , & V_177 -> V_345 ) ;
return;
default:
V_177 -> V_230 -> V_257 = V_349 ;
F_147 ( V_165 , V_177 , V_58 , false ) ;
break;
}
}
static int
F_161 ( struct V_1 * V_1 , struct V_177 * V_177 )
{
struct V_166 * V_352 ;
int V_30 ;
V_30 = F_89 ( V_1 , V_177 -> V_60 ) ;
if ( V_30 ) {
F_3 ( L_53 , V_30 ) ;
return V_30 ;
}
V_30 = F_92 ( V_1 -> V_56 , & V_177 -> V_165 . V_167 ,
& V_352 ) ;
if ( V_30 ) {
F_3 ( L_81 , V_30 ) ;
return V_30 ;
}
return V_30 ;
}
static int
F_155 ( struct V_189 * V_2 , struct V_230 * V_4 )
{
struct V_177 * V_177 = F_106 ( V_4 ) ;
struct V_1 * V_1 = V_2 -> V_10 ;
struct V_166 * V_167 = & V_177 -> V_165 . V_167 ;
struct V_353 * V_234 = (struct V_353 * )
& V_177 -> V_165 . V_193 ;
F_93 ( V_1 , V_177 , & V_177 -> V_165 ) ;
F_162 ( V_4 , V_2 , true , V_234 ) ;
F_95 ( V_1 , & V_177 -> V_165 ) ;
if ( V_4 -> V_3 . V_354 &&
( ( V_4 -> V_3 . V_246 & V_355 ) ||
( V_4 -> V_3 . V_246 & V_356 ) ) ) {
struct V_16 * V_17 = V_1 -> V_17 ;
struct V_44 * V_58 = V_17 -> V_44 ;
struct V_61 * V_196 = & V_177 -> V_165 . V_172 [ 1 ] ;
T_2 V_357 , V_358 ;
F_163 ( V_4 -> V_3 . V_359 ,
V_4 -> V_354 ) ;
V_4 -> V_3 . V_359 += sizeof( V_360 ) ;
V_357 = - ( V_4 -> V_3 . V_359 ) & 3 ;
F_164 ( V_234 -> V_263 , ( T_2 ) V_4 -> V_3 . V_359 ) ;
V_358 = V_4 -> V_3 . V_359 + V_357 ;
V_177 -> V_314 = F_20 ( V_58 ,
( void * ) V_4 -> V_354 , V_358 ,
V_105 ) ;
if ( F_21 ( V_58 , V_177 -> V_314 ) )
return - V_67 ;
V_177 -> V_315 = V_358 ;
V_196 -> V_71 = V_177 -> V_314 ;
V_196 -> V_72 = V_358 ;
V_196 -> V_73 = V_17 -> V_55 -> V_74 ;
V_177 -> V_165 . V_162 = 2 ;
}
F_96 ( V_1 , V_177 , V_167 ) ;
F_33 ( L_82 ) ;
return F_161 ( V_1 , V_177 ) ;
}
static void
F_165 ( struct V_189 * V_2 , struct V_230 * V_4 )
{
struct V_177 * V_177 = F_106 ( V_4 ) ;
struct V_1 * V_1 = V_2 -> V_10 ;
F_53 ( & V_2 -> V_306 ) ;
if ( ! F_72 ( & V_4 -> V_307 ) )
F_73 ( & V_4 -> V_307 ) ;
F_54 ( & V_2 -> V_306 ) ;
if ( V_4 -> V_308 == V_105 )
F_143 ( V_4 ) ;
F_138 ( V_177 , V_1 ) ;
}
static enum V_361
F_166 ( struct V_189 * V_2 )
{
struct V_1 * V_1 = V_2 -> V_10 ;
struct V_16 * V_17 = V_1 -> V_17 ;
if ( V_2 -> V_362 -> V_363 . V_364 ) {
if ( V_17 -> V_52 ) {
F_10 ( L_83 , V_1 ) ;
V_1 -> V_5 = true ;
return V_365 ;
}
}
F_10 ( L_84 , V_1 ) ;
V_1 -> V_5 = false ;
return V_7 ;
}
static int
F_167 ( struct V_230 * V_4 , struct V_189 * V_2 ,
bool V_366 )
{
struct V_177 * V_177 = F_106 ( V_4 ) ;
struct V_1 * V_1 = V_2 -> V_10 ;
struct V_166 * V_167 = & V_177 -> V_165 . V_167 ;
F_93 ( V_1 , V_177 , & V_177 -> V_165 ) ;
F_168 ( V_4 , V_2 , (struct V_367 * )
& V_177 -> V_165 . V_193 ,
V_366 ) ;
F_95 ( V_1 , & V_177 -> V_165 ) ;
F_96 ( V_1 , V_177 , V_167 ) ;
F_33 ( L_85 , V_1 ) ;
return F_161 ( V_1 , V_177 ) ;
}
static int
F_169 ( struct V_230 * V_4 , struct V_189 * V_2 )
{
struct V_177 * V_177 = F_106 ( V_4 ) ;
struct V_1 * V_1 = V_2 -> V_10 ;
struct V_166 * V_167 = & V_177 -> V_165 . V_167 ;
F_93 ( V_1 , V_177 , & V_177 -> V_165 ) ;
F_170 ( V_4 , V_2 , (struct V_368 * )
& V_177 -> V_165 . V_193 ) ;
F_95 ( V_1 , & V_177 -> V_165 ) ;
F_96 ( V_1 , V_177 , V_167 ) ;
F_33 ( L_86 , V_1 ) ;
return F_161 ( V_1 , V_177 ) ;
}
static int
F_171 ( struct V_230 * V_4 , struct V_189 * V_2 )
{
struct V_177 * V_177 = F_106 ( V_4 ) ;
struct V_1 * V_1 = V_2 -> V_10 ;
struct V_166 * V_167 = & V_177 -> V_165 . V_167 ;
F_93 ( V_1 , V_177 , & V_177 -> V_165 ) ;
F_172 ( V_4 , V_2 , (struct V_369 * )
& V_177 -> V_165 . V_193 ) ;
F_95 ( V_1 , & V_177 -> V_165 ) ;
F_96 ( V_1 , V_177 , V_167 ) ;
F_33 ( L_87 , V_1 ) ;
return F_161 ( V_1 , V_177 ) ;
}
static int
F_173 ( struct V_230 * V_4 , struct V_189 * V_2 )
{
struct V_177 * V_177 = F_106 ( V_4 ) ;
struct V_1 * V_1 = V_2 -> V_10 ;
struct V_166 * V_167 = & V_177 -> V_165 . V_167 ;
struct V_16 * V_17 = V_1 -> V_17 ;
struct V_44 * V_58 = V_17 -> V_44 ;
struct V_61 * V_196 = & V_177 -> V_165 . V_172 [ 1 ] ;
struct V_370 * V_234 =
(struct V_370 * ) & V_177 -> V_165 . V_193 ;
F_93 ( V_1 , V_177 , & V_177 -> V_165 ) ;
F_174 ( V_4 , V_2 , V_234 ) ;
F_95 ( V_1 , & V_177 -> V_165 ) ;
F_164 ( V_234 -> V_263 , V_225 ) ;
V_177 -> V_314 = F_20 ( V_58 ,
( void * ) V_4 -> V_371 , V_225 ,
V_105 ) ;
if ( F_21 ( V_58 , V_177 -> V_314 ) )
return - V_67 ;
V_177 -> V_315 = V_225 ;
V_196 -> V_71 = V_177 -> V_314 ;
V_196 -> V_72 = V_225 ;
V_196 -> V_73 = V_17 -> V_55 -> V_74 ;
V_177 -> V_165 . V_162 = 2 ;
F_96 ( V_1 , V_177 , V_167 ) ;
F_33 ( L_88 , V_1 ) ;
return F_161 ( V_1 , V_177 ) ;
}
static int
F_175 ( struct V_230 * V_4 , struct V_189 * V_2 )
{
struct V_177 * V_177 = F_106 ( V_4 ) ;
struct V_1 * V_1 = V_2 -> V_10 ;
struct V_166 * V_167 = & V_177 -> V_165 . V_167 ;
struct V_304 * V_234 =
(struct V_304 * ) & V_177 -> V_165 . V_193 ;
T_2 V_372 ;
int V_239 ;
F_93 ( V_1 , V_177 , & V_177 -> V_165 ) ;
V_239 = F_176 ( V_4 , V_2 , V_234 , V_373 ) ;
if ( V_239 < 0 )
return V_239 ;
V_372 = V_239 ;
F_95 ( V_1 , & V_177 -> V_165 ) ;
if ( V_372 ) {
struct V_16 * V_17 = V_1 -> V_17 ;
struct V_44 * V_58 = V_17 -> V_44 ;
struct V_61 * V_196 = & V_177 -> V_165 . V_172 [ 1 ] ;
void * V_374 = V_4 -> V_371 ;
V_177 -> V_314 = F_20 ( V_58 ,
V_374 , V_372 , V_105 ) ;
if ( F_21 ( V_58 , V_177 -> V_314 ) )
return - V_67 ;
V_177 -> V_315 = V_372 ;
V_196 -> V_71 = V_177 -> V_314 ;
V_196 -> V_72 = V_372 ;
V_196 -> V_73 = V_17 -> V_55 -> V_74 ;
V_177 -> V_165 . V_162 = 2 ;
}
F_96 ( V_1 , V_177 , V_167 ) ;
F_33 ( L_89 , V_1 ) ;
return F_161 ( V_1 , V_177 ) ;
}
static inline void
F_177 ( struct V_3 * V_3 , struct V_375 * V_376 ,
struct V_377 * V_378 )
{
V_378 -> V_379 = V_380 ;
V_378 -> V_342 . V_381 . V_382 = V_383 ;
V_378 -> V_342 . V_381 . V_384 = V_3 -> V_325 -> V_326 . V_324 ;
V_378 -> V_342 . V_381 . V_385 = V_3 -> V_386 ;
V_378 -> V_342 . V_381 . V_387 = 0xffff ;
V_378 -> V_342 . V_381 . V_388 = true ;
V_378 -> V_342 . V_381 . V_389 = true ;
if ( V_3 -> V_390 == V_391 ||
V_3 -> V_390 == V_392 )
V_378 -> V_342 . V_381 . V_393 = true ;
}
static int
F_178 ( struct V_3 * V_3 , struct V_375 * V_376 )
{
memset ( V_376 , 0 , sizeof( * V_376 ) ) ;
switch ( V_3 -> V_6 ) {
case V_394 :
case V_395 :
V_376 -> V_396 . V_379 = V_397 ;
F_177 ( V_3 , V_376 , & V_376 -> V_398 ) ;
break;
case V_399 :
case V_400 :
V_376 -> V_398 . V_379 = V_397 ;
F_177 ( V_3 , V_376 , & V_376 -> V_396 ) ;
break;
case V_401 :
case V_402 :
F_177 ( V_3 , V_376 , & V_376 -> V_398 ) ;
F_177 ( V_3 , V_376 , & V_376 -> V_396 ) ;
break;
default:
F_3 ( L_90 , V_3 -> V_6 ) ;
return - V_89 ;
}
V_376 -> V_403 =
( V_3 -> V_404 & V_405 ? 0xc0 : 0 ) |
( V_3 -> V_404 & V_406 ? 0x30 : 0 ) |
( V_3 -> V_404 & V_406 ? 0x0f : 0 ) ;
return 0 ;
}
static int
F_179 ( struct V_177 * V_4 , struct V_1 * V_2 ,
struct V_407 * V_408 , struct V_166 * V_409 )
{
struct V_3 * V_3 = & V_4 -> V_230 -> V_3 ;
enum V_296 V_297 = F_139 ( V_3 ) ;
V_116 V_300 = V_2 -> V_13 -> V_300 ;
T_1 V_71 ;
T_2 V_410 , V_411 ;
int V_30 ;
if ( V_297 == V_69 ) {
V_71 = V_4 -> V_274 ;
V_410 = V_4 -> V_273 ;
V_411 = V_4 -> V_230 -> V_253 ;
} else {
V_71 = V_4 -> V_272 ;
V_410 = V_4 -> V_271 ;
V_411 = 0 ;
}
if ( F_1 ( V_2 , V_3 ) ) {
struct V_375 V_376 ;
V_30 = F_178 ( V_3 , & V_376 ) ;
if ( V_30 )
return V_30 ;
F_99 ( V_411 ) ;
V_30 = F_180 ( & V_4 -> V_298 , V_2 -> V_56 , V_300 ,
V_3 -> V_250 , V_3 -> V_252 ,
V_3 -> V_301 , V_3 -> V_302 ,
& V_376 , V_71 , V_410 , V_297 ) ;
} else {
V_30 = F_181 ( & V_4 -> V_298 , V_2 -> V_56 , V_300 ,
V_3 -> V_250 , V_3 -> V_252 ,
V_411 , V_71 , V_410 , V_297 ) ;
}
if ( V_30 < 0 ) {
F_3 ( L_91 , V_4 ) ;
return V_30 ;
}
V_30 = F_182 ( & V_4 -> V_298 , V_2 -> V_56 , V_300 , V_408 , V_409 ) ;
if ( V_30 < 0 )
F_3 ( L_92 , V_4 ) ;
return V_30 ;
}
static int
F_183 ( struct V_189 * V_2 , struct V_230 * V_4 )
{
struct V_3 * V_3 = & V_4 -> V_3 ;
struct V_177 * V_177 = F_106 ( V_4 ) ;
struct V_1 * V_1 = V_2 -> V_10 ;
struct V_407 * V_408 = NULL ;
struct V_166 * V_409 = NULL ;
int V_239 ;
F_33 ( L_93 ,
V_177 , V_3 -> V_245 ) ;
if ( F_1 ( V_1 , V_3 ) ) {
V_177 -> V_165 . V_170 . V_76 = F_151 ;
V_408 = & V_177 -> V_165 . V_170 ;
} else {
F_93 ( V_1 , V_177 ,
& V_177 -> V_165 ) ;
F_162 ( V_4 , V_2 , true , (struct V_353 * )
& V_177 -> V_165 . V_193 ) ;
F_95 ( V_1 , & V_177 -> V_165 ) ;
F_96 ( V_1 , V_177 ,
& V_177 -> V_165 . V_167 ) ;
V_239 = F_89 ( V_1 , V_177 -> V_60 ) ;
if ( V_239 ) {
F_3 ( L_53 , V_239 ) ;
return V_239 ;
}
V_409 = & V_177 -> V_165 . V_167 ;
}
F_179 ( V_177 , V_1 , V_408 , V_409 ) ;
F_33 ( L_94 , V_177 ) ;
return 1 ;
}
static int
F_184 ( struct V_189 * V_2 , struct V_230 * V_4 , bool V_412 )
{
struct V_177 * V_177 = F_106 ( V_4 ) ;
F_33 ( L_95 ,
V_177 , V_4 -> V_3 . V_245 , V_4 -> V_253 ) ;
V_177 -> V_165 . V_170 . V_76 = F_156 ;
F_179 ( V_177 , V_2 -> V_10 ,
& V_177 -> V_165 . V_170 , NULL ) ;
F_33 ( L_96 ,
V_177 ) ;
return 0 ;
}
static int
F_185 ( struct V_189 * V_2 , struct V_230 * V_4 , int V_94 )
{
struct V_177 * V_177 = F_106 ( V_4 ) ;
int V_30 = 0 ;
switch ( V_94 ) {
case V_413 :
F_53 ( & V_2 -> V_306 ) ;
F_73 ( & V_4 -> V_307 ) ;
F_54 ( & V_2 -> V_306 ) ;
F_142 ( V_177 , true ) ;
break;
case V_414 :
V_30 = F_167 ( V_4 , V_2 , false ) ;
break;
default:
F_3 ( L_97 , V_94 ) ;
V_30 = - V_89 ;
break;
}
return V_30 ;
}
static int
F_186 ( struct V_189 * V_2 , struct V_230 * V_4 , int V_94 )
{
struct V_1 * V_1 = V_2 -> V_10 ;
int V_30 ;
switch ( V_94 ) {
case V_350 :
V_30 = F_169 ( V_4 , V_2 ) ;
if ( ! V_30 )
V_1 -> V_415 = true ;
break;
case V_416 :
V_30 = F_167 ( V_4 , V_2 , true ) ;
break;
case V_346 :
V_30 = F_171 ( V_4 , V_2 ) ;
break;
case V_347 :
V_30 = F_173 ( V_4 , V_2 ) ;
break;
case V_348 :
V_30 = F_175 ( V_4 , V_2 ) ;
break;
case V_417 :
V_30 = F_155 ( V_2 , V_4 ) ;
break;
default:
F_3 ( L_98 , V_94 ) ;
V_30 = - V_89 ;
break;
}
return V_30 ;
}
struct V_26 *
F_79 ( struct V_124 * V_124 )
{
struct V_125 * V_126 = V_124 -> V_126 ;
struct V_26 * V_418 ;
struct V_419 * V_420 ;
int V_30 ;
V_420 = (struct V_419 * ) & V_126 -> V_421 ;
F_33 ( L_99 , & V_126 -> V_421 , V_420 ) ;
V_418 = F_187 ( & V_422 , F_84 , V_124 ,
V_423 , V_51 ) ;
if ( F_16 ( V_418 ) ) {
F_3 ( L_100 , F_17 ( V_418 ) ) ;
V_30 = F_17 ( V_418 ) ;
goto V_86;
}
F_33 ( L_101 , V_418 , V_418 -> V_10 ) ;
V_30 = F_188 ( V_418 , V_420 ) ;
if ( V_30 ) {
F_3 ( L_102 , V_30 ) ;
goto V_424;
}
V_30 = F_189 ( V_418 , 0 ) ;
if ( V_30 ) {
F_3 ( L_103 , V_30 ) ;
goto V_424;
}
return V_418 ;
V_424:
F_60 ( V_418 ) ;
V_86:
return F_14 ( V_30 ) ;
}
static int
F_190 ( struct V_125 * V_126 ,
struct V_425 * V_426 )
{
struct V_124 * V_124 ;
struct V_26 * V_427 ;
int V_30 ;
V_124 = F_19 ( sizeof( struct V_124 ) , V_66 ) ;
if ( ! V_124 )
return - V_67 ;
F_191 ( & V_124 -> V_136 , 0 ) ;
F_47 ( & V_124 -> V_101 ) ;
F_41 ( & V_124 -> V_131 ) ;
F_41 ( & V_124 -> V_135 ) ;
V_124 -> V_126 = V_126 ;
memcpy ( & V_126 -> V_421 , V_426 ,
sizeof( struct V_425 ) ) ;
V_427 = F_79 ( V_124 ) ;
if ( F_16 ( V_427 ) ) {
V_30 = F_17 ( V_427 ) ;
goto V_86;
}
V_124 -> V_13 = V_427 ;
V_126 -> V_428 = V_124 ;
return 0 ;
V_86:
F_23 ( V_124 ) ;
return V_30 ;
}
static int
F_57 ( struct V_1 * V_1 )
{
struct V_26 * V_13 = V_1 -> V_13 ;
struct V_112 V_429 ;
int V_30 ;
struct V_430 V_431 ;
memset ( & V_429 , 0 , sizeof( struct V_112 ) ) ;
V_429 . V_115 = V_1 -> V_115 ;
V_429 . V_432 = 7 ;
V_429 . V_433 = 7 ;
memset ( & V_431 , 0 , sizeof( V_431 ) ) ;
V_431 . V_119 = V_434 ;
if ( ! V_1 -> V_120 )
V_431 . V_119 = V_431 . V_119 | V_435 ;
V_429 . V_118 = ( void * ) & V_431 ;
V_429 . V_436 = sizeof( V_431 ) ;
V_30 = F_192 ( V_13 , & V_429 ) ;
if ( V_30 ) {
F_3 ( L_104 , V_30 ) ;
return V_30 ;
}
return 0 ;
}
static int
F_193 ( struct V_189 * V_2 , struct V_190 * V_191 )
{
struct V_1 * V_1 = V_2 -> V_10 ;
int V_30 ;
F_10 ( L_105 , V_1 ) ;
V_30 = F_194 ( & V_1 -> V_98 ) ;
if ( V_30 ) {
F_3 ( L_106 ,
V_1 ) ;
return V_30 ;
}
F_195 ( & V_1 -> V_98 ) ;
if ( ! V_191 -> V_205 )
return 0 ;
F_98 ( V_1 ) ;
F_10 ( L_107 , V_2 ) ;
V_30 = F_194 ( & V_1 -> V_97 ) ;
if ( V_30 )
return V_30 ;
F_10 ( L_108 , V_191 -> V_224 ) ;
return 0 ;
}
static void
F_196 ( struct V_125 * V_126 , struct V_189 * V_2 ,
struct V_1 * V_1 )
{
struct V_26 * V_13 = V_1 -> V_13 ;
struct V_437 * V_438 = & V_13 -> V_439 ;
V_2 -> V_440 = V_126 -> V_421 . V_441 ;
V_2 -> V_442 = V_438 -> V_71 . V_443 ;
V_2 -> V_444 = V_438 -> V_71 . V_445 ;
}
static int
F_197 ( struct V_125 * V_126 , struct V_189 * V_2 )
{
struct V_124 * V_124 = V_126 -> V_428 ;
struct V_1 * V_1 ;
int V_30 ;
V_446:
V_30 = F_198 ( & V_124 -> V_136 ) ;
if ( V_30 )
return - V_447 ;
F_53 ( & V_126 -> V_127 ) ;
if ( V_126 -> V_448 >= V_449 ) {
F_54 ( & V_126 -> V_127 ) ;
F_33 ( L_109 ,
V_126 -> V_448 ) ;
return - V_447 ;
}
F_54 ( & V_126 -> V_127 ) ;
F_8 ( & V_124 -> V_101 ) ;
if ( F_72 ( & V_124 -> V_135 ) ) {
F_9 ( & V_124 -> V_101 ) ;
goto V_446;
}
V_1 = F_199 ( & V_124 -> V_135 ,
struct V_1 , V_96 ) ;
F_73 ( & V_1 -> V_96 ) ;
F_9 ( & V_124 -> V_101 ) ;
V_2 -> V_10 = V_1 ;
V_1 -> V_2 = V_2 ;
V_1 -> V_94 = V_145 ;
F_196 ( V_126 , V_2 , V_1 ) ;
F_33 ( L_110 , V_1 ) ;
return 0 ;
}
static void
F_200 ( struct V_125 * V_126 )
{
struct V_124 * V_124 = V_126 -> V_428 ;
struct V_1 * V_1 , * V_450 ;
if ( V_124 -> V_13 )
F_60 ( V_124 -> V_13 ) ;
F_8 ( & V_124 -> V_101 ) ;
if ( ! F_72 ( & V_124 -> V_135 ) ) {
F_10 ( L_111 ) ;
F_201 (isert_conn, n,
&isert_np->pending,
node) {
F_10 ( L_112 ,
V_1 , V_1 -> V_94 ) ;
F_58 ( V_1 ) ;
}
}
if ( ! F_72 ( & V_124 -> V_131 ) ) {
F_10 ( L_113 ) ;
F_201 (isert_conn, n,
&isert_np->accepted,
node) {
F_10 ( L_112 ,
V_1 , V_1 -> V_94 ) ;
F_58 ( V_1 ) ;
}
}
F_9 ( & V_124 -> V_101 ) ;
V_126 -> V_428 = NULL ;
F_23 ( V_124 ) ;
}
static void V_103 ( struct V_343 * V_344 )
{
struct V_1 * V_1 = F_68 ( V_344 ,
struct V_1 ,
V_102 ) ;
F_10 ( L_114 , V_1 ) ;
F_8 ( & V_1 -> V_101 ) ;
V_1 -> V_94 = V_152 ;
F_9 ( & V_1 -> V_101 ) ;
F_10 ( L_115 , V_1 ) ;
F_69 ( V_1 ) ;
}
static void
F_202 ( struct V_1 * V_1 )
{
struct V_189 * V_2 = V_1 -> V_2 ;
F_10 ( L_22 , V_1 ) ;
if ( V_1 -> V_415 ) {
F_10 ( L_116 , V_1 ) ;
F_203 ( & V_2 -> V_451 ,
V_452 * V_453 ) ;
}
}
static void
F_204 ( struct V_189 * V_2 )
{
F_10 ( L_117 , V_2 ) ;
if ( V_2 -> V_276 ) {
F_205 ( V_2 -> V_276 -> V_454 ) ;
F_206 ( V_2 -> V_276 -> V_454 ) ;
}
}
static void
F_207 ( struct V_189 * V_2 )
{
struct V_230 * V_4 , * V_455 ;
static F_208 ( V_456 ) ;
F_53 ( & V_2 -> V_306 ) ;
F_201 (cmd, tmp, &conn->conn_cmd_list, i_conn_node) {
if ( ( V_4 -> V_255 & V_457 ) &&
( V_4 -> V_253 < V_2 -> V_276 -> V_277 -> V_458 ) &&
( V_4 -> V_253 < V_4 -> V_3 . V_245 ) )
F_65 ( & V_4 -> V_307 , & V_456 ) ;
}
F_54 ( & V_2 -> V_306 ) ;
F_201 (cmd, tmp, &drop_cmd_list, i_conn_node) {
F_73 ( & V_4 -> V_307 ) ;
if ( V_4 -> V_257 != V_413 ) {
struct V_177 * V_177 = F_106 ( V_4 ) ;
F_10 ( L_118 , V_2 , V_4 ) ;
F_142 ( V_177 , true ) ;
}
}
}
static void F_209 ( struct V_189 * V_2 )
{
struct V_1 * V_1 = V_2 -> V_10 ;
F_10 ( L_119 , V_1 ) ;
F_8 ( & V_1 -> V_101 ) ;
F_75 ( V_1 ) ;
F_9 ( & V_1 -> V_101 ) ;
F_81 ( V_1 -> V_56 ) ;
F_207 ( V_2 ) ;
F_204 ( V_2 ) ;
F_202 ( V_1 ) ;
F_74 ( V_140 , & V_1 -> V_102 ) ;
}
static void F_210 ( struct V_189 * V_2 )
{
struct V_1 * V_1 = V_2 -> V_10 ;
F_81 ( V_1 -> V_56 ) ;
F_69 ( V_1 ) ;
}
static void F_211 ( struct V_189 * V_2 )
{
struct V_459 V_18 ;
F_44 ( & V_18 ) ;
F_194 ( & V_18 ) ;
}
static int T_5 F_212 ( void )
{
int V_30 ;
V_351 = F_213 ( L_120 ,
V_460 | V_461 , 0 ) ;
if ( ! V_351 ) {
F_3 ( L_121 ) ;
return - V_67 ;
}
V_140 = F_213 ( L_122 , V_460 ,
V_462 ) ;
if ( ! V_140 ) {
F_3 ( L_123 ) ;
V_30 = - V_67 ;
goto V_463;
}
F_214 ( & V_464 ) ;
F_10 ( L_124 ) ;
return 0 ;
V_463:
F_215 ( V_351 ) ;
return V_30 ;
}
static void T_6 F_216 ( void )
{
F_217 () ;
F_215 ( V_140 ) ;
F_215 ( V_351 ) ;
F_218 ( & V_464 ) ;
F_10 ( L_125 ) ;
}
