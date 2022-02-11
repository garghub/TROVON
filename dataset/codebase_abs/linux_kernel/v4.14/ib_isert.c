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
V_60 -> V_164 = false ;
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
if ( ! V_60 -> V_164 ) {
return 0 ;
}
V_60 -> V_164 = false ;
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
F_90 ( struct V_1 * V_1 , struct V_165 * V_166 )
{
struct V_44 * V_58 = V_1 -> V_13 -> V_17 ;
struct V_167 V_168 , * V_169 ;
int V_30 ;
F_91 ( V_58 , V_166 -> V_63 ,
V_170 , V_105 ) ;
V_166 -> V_171 . V_76 = V_172 ;
V_168 . V_163 = NULL ;
V_168 . V_160 = & V_166 -> V_171 ;
V_168 . V_161 = V_166 -> V_173 ;
V_168 . V_162 = V_166 -> V_162 ;
V_168 . V_174 = V_175 ;
V_168 . V_176 = V_177 ;
V_30 = F_92 ( V_1 -> V_56 , & V_168 , & V_169 ) ;
if ( V_30 )
F_3 ( L_36 , V_30 ) ;
return V_30 ;
}
static void
F_93 ( struct V_1 * V_1 ,
struct V_178 * V_178 ,
struct V_165 * V_166 )
{
struct V_16 * V_17 = V_1 -> V_17 ;
struct V_44 * V_58 = V_17 -> V_44 ;
F_94 ( V_58 , V_166 -> V_63 ,
V_170 , V_105 ) ;
memset ( & V_166 -> V_179 , 0 , sizeof( struct V_180 ) ) ;
V_166 -> V_179 . V_119 = V_181 ;
V_166 -> V_162 = 1 ;
if ( V_166 -> V_173 [ 0 ] . V_73 != V_17 -> V_55 -> V_74 ) {
V_166 -> V_173 [ 0 ] . V_73 = V_17 -> V_55 -> V_74 ;
F_33 ( L_37 , V_166 ) ;
}
}
static int
F_95 ( struct V_1 * V_1 ,
struct V_165 * V_166 )
{
struct V_16 * V_17 = V_1 -> V_17 ;
struct V_44 * V_58 = V_17 -> V_44 ;
T_1 V_63 ;
V_63 = F_20 ( V_58 , ( void * ) V_166 ,
V_170 , V_105 ) ;
if ( F_21 ( V_58 , V_63 ) ) {
F_3 ( L_38 ) ;
return - V_67 ;
}
V_166 -> V_63 = V_63 ;
V_166 -> V_173 [ 0 ] . V_71 = V_166 -> V_63 ;
V_166 -> V_173 [ 0 ] . V_72 = V_170 ;
V_166 -> V_173 [ 0 ] . V_73 = V_17 -> V_55 -> V_74 ;
F_33 ( L_39 ,
V_166 -> V_173 [ 0 ] . V_71 , V_166 -> V_173 [ 0 ] . V_72 ,
V_166 -> V_173 [ 0 ] . V_73 ) ;
return 0 ;
}
static void
F_96 ( struct V_1 * V_1 , struct V_178 * V_178 ,
struct V_167 * V_168 )
{
struct V_165 * V_166 = & V_178 -> V_166 ;
V_166 -> V_171 . V_76 = V_182 ;
V_168 -> V_160 = & V_166 -> V_171 ;
if ( V_1 -> V_120 && V_178 -> V_183 ) {
V_168 -> V_174 = V_184 ;
V_168 -> V_185 . V_186 = V_178 -> V_183 ;
} else {
V_168 -> V_174 = V_175 ;
}
V_168 -> V_161 = & V_166 -> V_173 [ 0 ] ;
V_168 -> V_162 = V_178 -> V_166 . V_162 ;
V_168 -> V_176 = V_177 ;
}
static int
F_56 ( struct V_1 * V_1 )
{
struct V_157 V_158 , * V_187 ;
struct V_61 V_188 ;
int V_30 ;
memset ( & V_188 , 0 , sizeof( struct V_61 ) ) ;
V_188 . V_71 = V_1 -> V_107 ;
V_188 . V_72 = V_68 ;
V_188 . V_73 = V_1 -> V_17 -> V_55 -> V_74 ;
F_33 ( L_40 ,
V_188 . V_71 , V_188 . V_72 , V_188 . V_73 ) ;
V_1 -> V_108 -> V_75 . V_76 = V_189 ;
memset ( & V_158 , 0 , sizeof( struct V_157 ) ) ;
V_158 . V_160 = & V_1 -> V_108 -> V_75 ;
V_158 . V_161 = & V_188 ;
V_158 . V_162 = 1 ;
V_30 = F_88 ( V_1 -> V_56 , & V_158 , & V_187 ) ;
if ( V_30 )
F_3 ( L_41 , V_30 ) ;
return V_30 ;
}
static int
F_97 ( struct V_190 * V_2 , struct V_191 * V_192 ,
T_2 V_72 )
{
struct V_1 * V_1 = V_2 -> V_10 ;
struct V_16 * V_17 = V_1 -> V_17 ;
struct V_44 * V_58 = V_17 -> V_44 ;
struct V_165 * V_166 = & V_1 -> V_193 ;
int V_30 ;
F_93 ( V_1 , NULL , V_166 ) ;
memcpy ( & V_166 -> V_194 , & V_192 -> V_195 [ 0 ] ,
sizeof( struct V_196 ) ) ;
F_95 ( V_1 , V_166 ) ;
if ( V_72 > 0 ) {
struct V_61 * V_197 = & V_166 -> V_173 [ 1 ] ;
F_94 ( V_58 , V_1 -> V_104 ,
V_72 , V_105 ) ;
memcpy ( V_1 -> V_106 , V_192 -> V_198 , V_72 ) ;
F_91 ( V_58 , V_1 -> V_104 ,
V_72 , V_105 ) ;
V_197 -> V_71 = V_1 -> V_104 ;
V_197 -> V_72 = V_72 ;
V_197 -> V_73 = V_1 -> V_17 -> V_55 -> V_74 ;
V_166 -> V_162 = 2 ;
}
if ( ! V_192 -> V_199 ) {
if ( V_192 -> V_200 ) {
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
goto V_201;
}
V_30 = F_56 ( V_1 ) ;
if ( V_30 )
return V_30 ;
}
V_201:
V_30 = F_90 ( V_1 , V_166 ) ;
if ( V_30 )
return V_30 ;
return 0 ;
}
static void
F_98 ( struct V_1 * V_1 )
{
struct V_59 * V_60 = V_1 -> V_108 ;
int V_202 = V_1 -> V_203 ;
struct V_190 * V_2 = V_1 -> V_2 ;
struct V_191 * V_192 = V_2 -> V_204 ;
int V_205 ;
F_10 ( L_22 , V_1 ) ;
F_99 ( ! V_192 ) ;
if ( V_192 -> V_206 ) {
struct V_207 * V_208 =
(struct V_207 * ) & V_60 -> V_194 ;
V_192 -> V_209 = ( ! V_208 -> V_210 ) ? 1 : 0 ;
V_192 -> V_211 =
( V_208 -> V_119 & V_212 )
>> 2 ;
V_192 -> V_213 = V_208 -> V_214 ;
V_192 -> V_215 = V_208 -> V_216 ;
memcpy ( V_192 -> V_217 , V_208 -> V_217 , 6 ) ;
V_192 -> V_218 = F_100 ( V_208 -> V_219 ) ;
V_192 -> V_220 = V_208 -> V_221 ;
V_192 -> V_222 = F_100 ( V_208 -> V_223 ) ;
V_192 -> V_224 = F_101 ( V_208 -> V_224 ) ;
V_192 -> V_210 = F_101 ( V_208 -> V_210 ) ;
}
memcpy ( & V_192 -> V_225 [ 0 ] , ( void * ) & V_60 -> V_194 , V_226 ) ;
V_205 = V_20 ( V_202 , V_227 ) ;
F_33 ( L_42
L_43 , V_205 , V_202 ,
V_227 ) ;
memcpy ( V_192 -> V_228 , & V_60 -> V_229 [ 0 ] , V_205 ) ;
if ( V_192 -> V_206 ) {
F_102 ( & V_1 -> V_97 ) ;
return;
}
F_103 ( & V_2 -> V_230 , 0 ) ;
}
static struct V_231
* F_104 ( struct V_190 * V_2 , struct V_59 * V_60 )
{
struct V_1 * V_1 = V_2 -> V_10 ;
struct V_178 * V_178 ;
struct V_231 * V_4 ;
V_4 = F_105 ( V_2 , V_232 ) ;
if ( ! V_4 ) {
F_3 ( L_44 ) ;
return NULL ;
}
V_178 = F_106 ( V_4 ) ;
V_178 -> V_2 = V_1 ;
V_178 -> V_231 = V_4 ;
V_178 -> V_60 = V_60 ;
return V_4 ;
}
static int
F_107 ( struct V_1 * V_1 ,
struct V_178 * V_178 , struct V_231 * V_4 ,
struct V_59 * V_60 , unsigned char * V_233 )
{
struct V_190 * V_2 = V_1 -> V_2 ;
struct V_234 * V_235 = (struct V_234 * ) V_233 ;
int V_236 , V_237 , V_238 , V_239 , V_240 ;
bool V_241 = false ;
unsigned int V_242 ;
V_240 = F_108 ( V_2 , V_4 , V_233 ) ;
if ( V_240 < 0 )
return V_240 ;
V_236 = V_4 -> V_243 ;
V_237 = V_4 -> V_244 ;
V_238 = V_4 -> V_245 ;
V_242 = V_4 -> V_3 . V_246 ;
if ( V_236 && V_237 == V_242 )
V_4 -> V_3 . V_247 |= V_248 ;
V_240 = F_109 ( V_2 , V_4 , V_235 ) ;
if ( V_240 < 0 ) {
return 0 ;
} else if ( V_240 > 0 ) {
V_241 = true ;
goto V_249;
}
if ( ! V_236 )
return 0 ;
if ( V_237 != V_242 ) {
V_239 = F_110 ( 1UL , F_111 ( V_237 , V_250 ) ) ;
F_112 ( V_4 -> V_3 . V_251 , V_239 ,
& V_60 -> V_229 [ 0 ] , V_237 ) ;
F_33 ( L_45 ,
V_239 , V_237 ) ;
} else {
F_113 ( & V_178 -> V_252 , 1 ) ;
V_4 -> V_3 . V_251 = & V_178 -> V_252 ;
V_4 -> V_3 . V_253 = 1 ;
F_114 ( & V_178 -> V_252 , & V_60 -> V_229 [ 0 ] , V_237 ) ;
F_33 ( L_46 ,
V_237 ) ;
}
V_4 -> V_254 += V_237 ;
if ( V_4 -> V_254 == V_4 -> V_3 . V_246 ) {
F_53 ( & V_4 -> V_255 ) ;
V_4 -> V_256 |= V_257 ;
V_4 -> V_258 = V_259 ;
F_54 ( & V_4 -> V_255 ) ;
}
V_249:
V_240 = F_115 ( V_2 , V_4 , V_233 , V_235 -> V_219 ) ;
if ( ! V_240 && V_241 == false && V_238 )
F_116 ( V_4 ) ;
else if ( V_241 && V_236 )
F_117 ( & V_4 -> V_3 ) ;
return 0 ;
}
static int
F_118 ( struct V_1 * V_1 ,
struct V_59 * V_60 , unsigned char * V_233 )
{
struct V_260 * V_261 ;
struct V_190 * V_2 = V_1 -> V_2 ;
struct V_231 * V_4 = NULL ;
struct V_262 * V_235 = (struct V_262 * ) V_233 ;
T_2 V_263 = F_119 ( V_235 -> V_264 ) ;
int V_240 , V_239 , V_265 , V_266 ;
V_240 = F_120 ( V_2 , V_233 , & V_4 ) ;
if ( V_240 < 0 )
return V_240 ;
else if ( ! V_4 )
return 0 ;
if ( ! V_4 -> V_245 ) {
F_3 ( L_47 ) ;
F_121 () ;
return - 1 ;
}
F_33 ( L_48
L_49 ,
V_263 , V_4 -> V_254 ,
V_4 -> V_3 . V_246 ) ;
V_265 = V_4 -> V_254 / V_250 ;
V_261 = & V_4 -> V_3 . V_251 [ V_265 ] ;
V_239 = F_110 ( 1UL , F_111 ( V_263 , V_250 ) ) ;
V_266 = V_4 -> V_254 % V_250 ;
if ( V_266 ) {
F_3 ( L_50 ) ;
F_121 () ;
return - 1 ;
}
F_33 ( L_51
L_52 , V_261 , V_265 ,
V_239 , & V_60 -> V_229 [ 0 ] , V_263 ) ;
F_112 ( V_261 , V_239 , & V_60 -> V_229 [ 0 ] ,
V_263 ) ;
V_240 = F_122 ( V_4 , V_235 , false ) ;
if ( V_240 < 0 )
return V_240 ;
V_240 = F_89 ( V_1 , V_60 ) ;
if ( V_240 ) {
F_3 ( L_53 , V_240 ) ;
return V_240 ;
}
return 0 ;
}
static int
F_123 ( struct V_1 * V_1 , struct V_178 * V_178 ,
struct V_231 * V_4 , struct V_59 * V_60 ,
unsigned char * V_233 )
{
struct V_190 * V_2 = V_1 -> V_2 ;
struct V_267 * V_235 = (struct V_267 * ) V_233 ;
int V_240 ;
V_240 = F_124 ( V_2 , V_4 , V_235 ) ;
if ( V_240 < 0 )
return V_240 ;
return F_125 ( V_2 , V_4 , V_235 ) ;
}
static int
F_126 ( struct V_1 * V_1 , struct V_178 * V_178 ,
struct V_231 * V_4 , struct V_59 * V_60 ,
struct V_268 * V_235 )
{
struct V_190 * V_2 = V_1 -> V_2 ;
T_2 V_269 = F_119 ( V_235 -> V_264 ) ;
int V_240 ;
unsigned char * V_270 = NULL ;
V_240 = F_127 ( V_2 , V_4 , V_235 ) ;
if ( V_240 < 0 )
return V_240 ;
if ( V_269 ) {
V_270 = F_19 ( V_269 , V_66 ) ;
if ( ! V_270 )
return - V_67 ;
}
V_4 -> V_271 = V_270 ;
memcpy ( V_4 -> V_271 , & V_60 -> V_229 [ 0 ] , V_269 ) ;
return F_128 ( V_2 , V_4 , V_235 ) ;
}
static int
F_129 ( struct V_1 * V_1 , struct V_59 * V_60 ,
T_3 V_272 , T_4 V_273 ,
T_3 V_274 , T_4 V_275 )
{
struct V_196 * V_235 = & V_60 -> V_194 ;
struct V_190 * V_2 = V_1 -> V_2 ;
struct V_231 * V_4 ;
struct V_178 * V_178 ;
int V_30 = - V_89 ;
V_116 V_174 = ( V_235 -> V_174 & V_276 ) ;
if ( V_2 -> V_277 -> V_278 -> V_279 &&
( ! ( V_174 & V_280 ) || ! ( V_174 & V_281 ) ) ) {
F_3 ( L_54
L_55 , V_174 ) ;
return 0 ;
}
switch ( V_174 ) {
case V_282 :
V_4 = F_104 ( V_2 , V_60 ) ;
if ( ! V_4 )
break;
V_178 = F_106 ( V_4 ) ;
V_178 -> V_272 = V_272 ;
V_178 -> V_273 = V_273 ;
V_178 -> V_274 = V_274 ;
V_178 -> V_275 = V_275 ;
V_178 -> V_183 = V_272 ? V_272 : V_274 ;
V_30 = F_107 ( V_1 , V_178 , V_4 ,
V_60 , ( unsigned char * ) V_235 ) ;
break;
case V_283 :
V_4 = F_104 ( V_2 , V_60 ) ;
if ( ! V_4 )
break;
V_178 = F_106 ( V_4 ) ;
V_30 = F_123 ( V_1 , V_178 , V_4 ,
V_60 , ( unsigned char * ) V_235 ) ;
break;
case V_284 :
V_30 = F_118 ( V_1 , V_60 ,
( unsigned char * ) V_235 ) ;
break;
case V_285 :
V_4 = F_104 ( V_2 , V_60 ) ;
if ( ! V_4 )
break;
V_30 = F_130 ( V_2 , V_4 ,
( unsigned char * ) V_235 ) ;
break;
case V_281 :
V_4 = F_104 ( V_2 , V_60 ) ;
if ( ! V_4 )
break;
V_30 = F_131 ( V_2 , V_4 , ( unsigned char * ) V_235 ) ;
break;
case V_280 :
if ( F_100 ( V_235 -> V_286 ) != 0xFFFFFFFF )
V_4 = F_132 ( V_2 , V_235 -> V_221 ) ;
else
V_4 = F_104 ( V_2 , V_60 ) ;
if ( ! V_4 )
break;
V_178 = F_106 ( V_4 ) ;
V_30 = F_126 ( V_1 , V_178 , V_4 ,
V_60 , (struct V_268 * ) V_235 ) ;
break;
default:
F_3 ( L_56 , V_174 ) ;
F_121 () ;
break;
}
return V_30 ;
}
static void
F_133 ( struct V_287 * V_288 , const char * type )
{
if ( V_288 -> V_147 != V_289 )
F_3 ( L_57 , type ,
F_134 ( V_288 -> V_147 ) , V_288 -> V_147 ,
V_288 -> V_290 ) ;
else
F_33 ( L_58 , type ,
F_134 ( V_288 -> V_147 ) , V_288 -> V_147 ) ;
}
static void
V_77 ( struct V_291 * V_34 , struct V_287 * V_288 )
{
struct V_1 * V_1 = V_288 -> V_56 -> V_32 ;
struct V_44 * V_58 = V_1 -> V_13 -> V_17 ;
struct V_59 * V_60 = F_135 ( V_288 -> V_160 ) ;
struct V_196 * V_235 = & V_60 -> V_194 ;
struct V_180 * V_180 = & V_60 -> V_179 ;
T_4 V_273 = 0 , V_275 = 0 ;
T_3 V_272 = 0 , V_274 = 0 ;
if ( F_136 ( V_288 -> V_147 != V_292 ) ) {
F_133 ( V_288 , L_59 ) ;
if ( V_288 -> V_147 != V_289 )
F_82 ( V_1 -> V_2 , 0 ) ;
return;
}
V_60 -> V_164 = true ;
F_94 ( V_58 , V_60 -> V_63 ,
V_68 , V_69 ) ;
F_33 ( L_60 ,
V_60 -> V_63 , V_235 -> V_174 , V_235 -> V_221 , V_235 -> V_119 ,
( int ) ( V_288 -> V_293 - V_170 ) ) ;
switch ( V_180 -> V_119 & 0xF0 ) {
case V_181 :
if ( V_180 -> V_119 & V_294 ) {
V_272 = F_100 ( V_180 -> V_272 ) ;
V_273 = F_137 ( V_180 -> V_273 ) ;
F_33 ( L_61 ,
V_272 , ( unsigned long long ) V_273 ) ;
}
if ( V_180 -> V_119 & V_295 ) {
V_274 = F_100 ( V_180 -> V_274 ) ;
V_275 = F_137 ( V_180 -> V_275 ) ;
F_33 ( L_62 ,
V_274 , ( unsigned long long ) V_275 ) ;
}
F_33 ( L_63 ) ;
break;
case V_296 :
F_3 ( L_64 ) ;
break;
default:
F_6 ( L_65 , V_180 -> V_119 ) ;
break;
}
F_129 ( V_1 , V_60 ,
V_272 , V_273 , V_274 , V_275 ) ;
F_91 ( V_58 , V_60 -> V_63 ,
V_68 , V_69 ) ;
}
static void
V_189 ( struct V_291 * V_34 , struct V_287 * V_288 )
{
struct V_1 * V_1 = V_288 -> V_56 -> V_32 ;
struct V_44 * V_58 = V_1 -> V_17 -> V_44 ;
if ( F_136 ( V_288 -> V_147 != V_292 ) ) {
F_133 ( V_288 , L_66 ) ;
return;
}
F_94 ( V_58 , V_1 -> V_107 ,
V_68 , V_69 ) ;
V_1 -> V_203 = V_288 -> V_293 - V_170 ;
if ( V_1 -> V_2 ) {
struct V_191 * V_192 = V_1 -> V_2 -> V_204 ;
if ( V_192 && ! V_192 -> V_206 )
F_98 ( V_1 ) ;
}
F_8 ( & V_1 -> V_101 ) ;
F_102 ( & V_1 -> V_98 ) ;
F_9 ( & V_1 -> V_101 ) ;
F_91 ( V_58 , V_1 -> V_107 ,
V_68 , V_69 ) ;
}
static void
F_138 ( struct V_178 * V_4 , struct V_1 * V_2 )
{
struct V_3 * V_3 = & V_4 -> V_231 -> V_3 ;
enum V_297 V_298 = F_139 ( V_3 ) ;
if ( ! V_4 -> V_299 . V_300 )
return;
if ( F_1 ( V_2 , V_3 ) ) {
F_140 ( & V_4 -> V_299 , V_2 -> V_56 ,
V_2 -> V_13 -> V_301 , V_3 -> V_251 ,
V_3 -> V_253 , V_3 -> V_302 ,
V_3 -> V_303 , V_298 ) ;
} else {
F_141 ( & V_4 -> V_299 , V_2 -> V_56 , V_2 -> V_13 -> V_301 ,
V_3 -> V_251 , V_3 -> V_253 , V_298 ) ;
}
V_4 -> V_299 . V_300 = 0 ;
}
static void
F_142 ( struct V_178 * V_178 , bool V_304 )
{
struct V_231 * V_4 = V_178 -> V_231 ;
struct V_1 * V_1 = V_178 -> V_2 ;
struct V_190 * V_2 = V_1 -> V_2 ;
struct V_305 * V_235 ;
F_33 ( L_67 , V_178 ) ;
switch ( V_4 -> V_306 ) {
case V_282 :
F_53 ( & V_2 -> V_307 ) ;
if ( ! F_72 ( & V_4 -> V_308 ) )
F_73 ( & V_4 -> V_308 ) ;
F_54 ( & V_2 -> V_307 ) ;
if ( V_4 -> V_309 == V_105 ) {
F_143 ( V_4 ) ;
if ( V_304 &&
V_4 -> V_3 . V_310 == V_311 ) {
struct V_3 * V_3 = & V_4 -> V_3 ;
F_117 ( V_3 ) ;
}
}
F_138 ( V_178 , V_1 ) ;
F_144 ( & V_4 -> V_3 , 0 ) ;
break;
case V_285 :
F_53 ( & V_2 -> V_307 ) ;
if ( ! F_72 ( & V_4 -> V_308 ) )
F_73 ( & V_4 -> V_308 ) ;
F_54 ( & V_2 -> V_307 ) ;
F_144 ( & V_4 -> V_3 , 0 ) ;
break;
case V_312 :
case V_283 :
case V_280 :
V_235 = (struct V_305 * ) & V_178 -> V_166 . V_194 ;
if ( V_235 -> V_119 & V_313 )
break;
F_53 ( & V_2 -> V_307 ) ;
if ( ! F_72 ( & V_4 -> V_308 ) )
F_73 ( & V_4 -> V_308 ) ;
F_54 ( & V_2 -> V_307 ) ;
if ( V_4 -> V_3 . V_314 != NULL ) {
F_33 ( L_68 ,
V_4 -> V_306 ) ;
F_144 ( & V_4 -> V_3 , 0 ) ;
break;
}
default:
F_145 ( V_4 ) ;
break;
}
}
static void
F_146 ( struct V_165 * V_166 , struct V_44 * V_58 )
{
if ( V_166 -> V_63 != 0 ) {
F_33 ( L_69 ) ;
F_22 ( V_58 , V_166 -> V_63 ,
V_170 , V_105 ) ;
V_166 -> V_63 = 0 ;
}
}
static void
F_147 ( struct V_165 * V_166 , struct V_178 * V_178 ,
struct V_44 * V_58 , bool V_304 )
{
if ( V_178 -> V_315 != 0 ) {
F_33 ( L_70 ) ;
F_22 ( V_58 , V_178 -> V_315 ,
V_178 -> V_316 , V_105 ) ;
V_178 -> V_315 = 0 ;
}
F_146 ( V_166 , V_58 ) ;
F_142 ( V_178 , V_304 ) ;
}
static int
F_148 ( struct V_3 * V_3 , struct V_317 * V_318 )
{
struct V_319 V_320 ;
int V_30 ;
V_30 = F_149 ( V_318 , V_321 , & V_320 ) ;
if ( V_30 ) {
F_3 ( L_71 , V_30 ) ;
goto V_322;
}
if ( V_320 . V_323 & V_321 ) {
T_1 V_324 ;
T_2 V_325 = V_3 -> V_326 -> V_327 . V_325 + 8 ;
switch ( V_320 . V_328 . V_329 ) {
case V_330 :
V_3 -> V_331 = V_332 ;
break;
case V_333 :
V_3 -> V_331 = V_334 ;
break;
case V_335 :
V_3 -> V_331 = V_336 ;
break;
}
V_324 = V_320 . V_328 . V_337 ;
F_150 ( V_324 , V_325 ) ;
V_3 -> V_338 = V_324 + V_3 -> V_339 ;
F_3 ( L_72
L_73 ,
V_320 . V_328 . V_329 ,
( unsigned long long ) V_3 -> V_338 ,
V_320 . V_328 . V_340 ,
V_320 . V_328 . V_341 ) ;
V_30 = 1 ;
}
V_322:
return V_30 ;
}
static void
F_151 ( struct V_291 * V_34 , struct V_287 * V_288 )
{
struct V_1 * V_1 = V_288 -> V_56 -> V_32 ;
struct V_16 * V_17 = V_1 -> V_17 ;
struct V_165 * V_342 = F_152 ( V_288 -> V_160 ) ;
struct V_178 * V_178 = F_153 ( V_342 ) ;
struct V_3 * V_4 = & V_178 -> V_231 -> V_3 ;
int V_30 = 0 ;
if ( F_136 ( V_288 -> V_147 != V_292 ) ) {
F_133 ( V_288 , L_74 ) ;
if ( V_288 -> V_147 != V_289 )
F_82 ( V_1 -> V_2 , 0 ) ;
F_147 ( V_342 , V_178 , V_17 -> V_44 , true ) ;
return;
}
F_33 ( L_67 , V_178 ) ;
V_30 = F_148 ( V_4 , V_178 -> V_299 . V_343 -> V_318 ) ;
F_138 ( V_178 , V_1 ) ;
if ( V_30 ) {
F_64 ( & V_4 -> V_344 ) ;
F_154 ( V_4 , V_4 -> V_331 ) ;
} else {
V_30 = F_155 ( V_1 -> V_2 , V_178 -> V_231 ) ;
if ( V_30 )
F_156 ( L_75 , V_30 ) ;
}
}
static void
F_157 ( struct V_291 * V_34 , struct V_287 * V_288 )
{
struct V_1 * V_1 = V_288 -> V_56 -> V_32 ;
struct V_16 * V_17 = V_1 -> V_17 ;
struct V_165 * V_342 = F_152 ( V_288 -> V_160 ) ;
struct V_178 * V_178 = F_153 ( V_342 ) ;
struct V_231 * V_4 = V_178 -> V_231 ;
struct V_3 * V_3 = & V_4 -> V_3 ;
int V_30 = 0 ;
if ( F_136 ( V_288 -> V_147 != V_292 ) ) {
F_133 ( V_288 , L_76 ) ;
if ( V_288 -> V_147 != V_289 )
F_82 ( V_1 -> V_2 , 0 ) ;
F_147 ( V_342 , V_178 , V_17 -> V_44 , true ) ;
return;
}
F_33 ( L_67 , V_178 ) ;
F_143 ( V_4 ) ;
if ( F_1 ( V_1 , V_3 ) )
V_30 = F_148 ( V_3 , V_178 -> V_299 . V_343 -> V_318 ) ;
F_138 ( V_178 , V_1 ) ;
V_4 -> V_254 = 0 ;
F_33 ( L_77 , V_178 ) ;
F_53 ( & V_4 -> V_255 ) ;
V_4 -> V_256 |= V_257 ;
V_4 -> V_258 = V_259 ;
F_54 ( & V_4 -> V_255 ) ;
if ( V_30 )
F_154 ( V_3 , V_3 -> V_331 ) ;
else
F_158 ( V_3 ) ;
}
static void
F_159 ( struct V_345 * V_346 )
{
struct V_178 * V_178 = F_68 ( V_346 ,
struct V_178 , V_347 ) ;
struct V_1 * V_1 = V_178 -> V_2 ;
struct V_44 * V_58 = V_1 -> V_13 -> V_17 ;
struct V_231 * V_4 = V_178 -> V_231 ;
F_33 ( L_78 , V_178 , V_4 -> V_258 ) ;
switch ( V_4 -> V_258 ) {
case V_348 :
F_160 ( V_4 , V_4 -> V_2 ) ;
case V_349 :
case V_350 :
V_4 -> V_258 = V_351 ;
F_147 ( & V_178 -> V_166 , V_178 ,
V_58 , false ) ;
break;
case V_352 :
F_161 ( V_4 , V_4 -> V_2 ) ;
break;
default:
F_3 ( L_79 , V_4 -> V_258 ) ;
F_121 () ;
break;
}
}
static void
V_172 ( struct V_291 * V_34 , struct V_287 * V_288 )
{
struct V_1 * V_1 = V_288 -> V_56 -> V_32 ;
struct V_44 * V_58 = V_1 -> V_13 -> V_17 ;
struct V_165 * V_166 = F_152 ( V_288 -> V_160 ) ;
if ( F_136 ( V_288 -> V_147 != V_292 ) ) {
F_133 ( V_288 , L_80 ) ;
if ( V_288 -> V_147 != V_289 )
F_82 ( V_1 -> V_2 , 0 ) ;
}
F_146 ( V_166 , V_58 ) ;
}
static void
V_182 ( struct V_291 * V_34 , struct V_287 * V_288 )
{
struct V_1 * V_1 = V_288 -> V_56 -> V_32 ;
struct V_44 * V_58 = V_1 -> V_13 -> V_17 ;
struct V_165 * V_166 = F_152 ( V_288 -> V_160 ) ;
struct V_178 * V_178 = F_153 ( V_166 ) ;
if ( F_136 ( V_288 -> V_147 != V_292 ) ) {
F_133 ( V_288 , L_81 ) ;
if ( V_288 -> V_147 != V_289 )
F_82 ( V_1 -> V_2 , 0 ) ;
F_147 ( V_166 , V_178 , V_58 , true ) ;
return;
}
F_33 ( L_67 , V_178 ) ;
switch ( V_178 -> V_231 -> V_258 ) {
case V_348 :
case V_352 :
case V_349 :
case V_350 :
F_146 ( V_166 , V_58 ) ;
F_48 ( & V_178 -> V_347 , F_159 ) ;
F_74 ( V_353 , & V_178 -> V_347 ) ;
return;
default:
V_178 -> V_231 -> V_258 = V_351 ;
F_147 ( V_166 , V_178 , V_58 , false ) ;
break;
}
}
static int
F_162 ( struct V_1 * V_1 , struct V_178 * V_178 )
{
struct V_167 * V_354 ;
int V_30 ;
V_30 = F_89 ( V_1 , V_178 -> V_60 ) ;
if ( V_30 ) {
F_3 ( L_53 , V_30 ) ;
return V_30 ;
}
V_30 = F_92 ( V_1 -> V_56 , & V_178 -> V_166 . V_168 ,
& V_354 ) ;
if ( V_30 ) {
F_3 ( L_82 , V_30 ) ;
return V_30 ;
}
return V_30 ;
}
static int
F_155 ( struct V_190 * V_2 , struct V_231 * V_4 )
{
struct V_178 * V_178 = F_106 ( V_4 ) ;
struct V_1 * V_1 = V_2 -> V_10 ;
struct V_167 * V_168 = & V_178 -> V_166 . V_168 ;
struct V_355 * V_235 = (struct V_355 * )
& V_178 -> V_166 . V_194 ;
F_93 ( V_1 , V_178 , & V_178 -> V_166 ) ;
F_163 ( V_4 , V_2 , true , V_235 ) ;
F_95 ( V_1 , & V_178 -> V_166 ) ;
if ( V_4 -> V_3 . V_356 &&
( ( V_4 -> V_3 . V_247 & V_357 ) ||
( V_4 -> V_3 . V_247 & V_358 ) ) ) {
struct V_16 * V_17 = V_1 -> V_17 ;
struct V_44 * V_58 = V_17 -> V_44 ;
struct V_61 * V_197 = & V_178 -> V_166 . V_173 [ 1 ] ;
T_2 V_359 , V_360 ;
F_164 ( V_4 -> V_3 . V_361 ,
V_4 -> V_356 ) ;
V_4 -> V_3 . V_361 += sizeof( V_362 ) ;
V_359 = - ( V_4 -> V_3 . V_361 ) & 3 ;
F_165 ( V_235 -> V_264 , ( T_2 ) V_4 -> V_3 . V_361 ) ;
V_360 = V_4 -> V_3 . V_361 + V_359 ;
V_178 -> V_315 = F_20 ( V_58 ,
( void * ) V_4 -> V_356 , V_360 ,
V_105 ) ;
if ( F_21 ( V_58 , V_178 -> V_315 ) )
return - V_67 ;
V_178 -> V_316 = V_360 ;
V_197 -> V_71 = V_178 -> V_315 ;
V_197 -> V_72 = V_360 ;
V_197 -> V_73 = V_17 -> V_55 -> V_74 ;
V_178 -> V_166 . V_162 = 2 ;
}
F_96 ( V_1 , V_178 , V_168 ) ;
F_33 ( L_83 ) ;
return F_162 ( V_1 , V_178 ) ;
}
static void
F_166 ( struct V_190 * V_2 , struct V_231 * V_4 )
{
struct V_178 * V_178 = F_106 ( V_4 ) ;
struct V_1 * V_1 = V_2 -> V_10 ;
F_53 ( & V_2 -> V_307 ) ;
if ( ! F_72 ( & V_4 -> V_308 ) )
F_73 ( & V_4 -> V_308 ) ;
F_54 ( & V_2 -> V_307 ) ;
if ( V_4 -> V_309 == V_105 )
F_143 ( V_4 ) ;
F_138 ( V_178 , V_1 ) ;
}
static enum V_363
F_167 ( struct V_190 * V_2 )
{
struct V_1 * V_1 = V_2 -> V_10 ;
struct V_16 * V_17 = V_1 -> V_17 ;
if ( V_2 -> V_364 -> V_365 . V_366 ) {
if ( V_17 -> V_52 ) {
F_10 ( L_84 , V_1 ) ;
V_1 -> V_5 = true ;
return V_367 ;
}
}
F_10 ( L_85 , V_1 ) ;
V_1 -> V_5 = false ;
return V_7 ;
}
static int
F_168 ( struct V_231 * V_4 , struct V_190 * V_2 ,
bool V_368 )
{
struct V_178 * V_178 = F_106 ( V_4 ) ;
struct V_1 * V_1 = V_2 -> V_10 ;
struct V_167 * V_168 = & V_178 -> V_166 . V_168 ;
F_93 ( V_1 , V_178 , & V_178 -> V_166 ) ;
F_169 ( V_4 , V_2 , (struct V_369 * )
& V_178 -> V_166 . V_194 ,
V_368 ) ;
F_95 ( V_1 , & V_178 -> V_166 ) ;
F_96 ( V_1 , V_178 , V_168 ) ;
F_33 ( L_86 , V_1 ) ;
return F_162 ( V_1 , V_178 ) ;
}
static int
F_170 ( struct V_231 * V_4 , struct V_190 * V_2 )
{
struct V_178 * V_178 = F_106 ( V_4 ) ;
struct V_1 * V_1 = V_2 -> V_10 ;
struct V_167 * V_168 = & V_178 -> V_166 . V_168 ;
F_93 ( V_1 , V_178 , & V_178 -> V_166 ) ;
F_171 ( V_4 , V_2 , (struct V_370 * )
& V_178 -> V_166 . V_194 ) ;
F_95 ( V_1 , & V_178 -> V_166 ) ;
F_96 ( V_1 , V_178 , V_168 ) ;
F_33 ( L_87 , V_1 ) ;
return F_162 ( V_1 , V_178 ) ;
}
static int
F_172 ( struct V_231 * V_4 , struct V_190 * V_2 )
{
struct V_178 * V_178 = F_106 ( V_4 ) ;
struct V_1 * V_1 = V_2 -> V_10 ;
struct V_167 * V_168 = & V_178 -> V_166 . V_168 ;
F_93 ( V_1 , V_178 , & V_178 -> V_166 ) ;
F_173 ( V_4 , V_2 , (struct V_371 * )
& V_178 -> V_166 . V_194 ) ;
F_95 ( V_1 , & V_178 -> V_166 ) ;
F_96 ( V_1 , V_178 , V_168 ) ;
F_33 ( L_88 , V_1 ) ;
return F_162 ( V_1 , V_178 ) ;
}
static int
F_174 ( struct V_231 * V_4 , struct V_190 * V_2 )
{
struct V_178 * V_178 = F_106 ( V_4 ) ;
struct V_1 * V_1 = V_2 -> V_10 ;
struct V_167 * V_168 = & V_178 -> V_166 . V_168 ;
struct V_16 * V_17 = V_1 -> V_17 ;
struct V_44 * V_58 = V_17 -> V_44 ;
struct V_61 * V_197 = & V_178 -> V_166 . V_173 [ 1 ] ;
struct V_372 * V_235 =
(struct V_372 * ) & V_178 -> V_166 . V_194 ;
F_93 ( V_1 , V_178 , & V_178 -> V_166 ) ;
F_175 ( V_4 , V_2 , V_235 ) ;
F_95 ( V_1 , & V_178 -> V_166 ) ;
F_165 ( V_235 -> V_264 , V_226 ) ;
V_178 -> V_315 = F_20 ( V_58 ,
( void * ) V_4 -> V_373 , V_226 ,
V_105 ) ;
if ( F_21 ( V_58 , V_178 -> V_315 ) )
return - V_67 ;
V_178 -> V_316 = V_226 ;
V_197 -> V_71 = V_178 -> V_315 ;
V_197 -> V_72 = V_226 ;
V_197 -> V_73 = V_17 -> V_55 -> V_74 ;
V_178 -> V_166 . V_162 = 2 ;
F_96 ( V_1 , V_178 , V_168 ) ;
F_33 ( L_89 , V_1 ) ;
return F_162 ( V_1 , V_178 ) ;
}
static int
F_176 ( struct V_231 * V_4 , struct V_190 * V_2 )
{
struct V_178 * V_178 = F_106 ( V_4 ) ;
struct V_1 * V_1 = V_2 -> V_10 ;
struct V_167 * V_168 = & V_178 -> V_166 . V_168 ;
struct V_305 * V_235 =
(struct V_305 * ) & V_178 -> V_166 . V_194 ;
T_2 V_374 ;
int V_240 ;
F_93 ( V_1 , V_178 , & V_178 -> V_166 ) ;
V_240 = F_177 ( V_4 , V_2 , V_235 , V_375 ) ;
if ( V_240 < 0 )
return V_240 ;
V_374 = V_240 ;
F_95 ( V_1 , & V_178 -> V_166 ) ;
if ( V_374 ) {
struct V_16 * V_17 = V_1 -> V_17 ;
struct V_44 * V_58 = V_17 -> V_44 ;
struct V_61 * V_197 = & V_178 -> V_166 . V_173 [ 1 ] ;
void * V_376 = V_4 -> V_373 ;
V_178 -> V_315 = F_20 ( V_58 ,
V_376 , V_374 , V_105 ) ;
if ( F_21 ( V_58 , V_178 -> V_315 ) )
return - V_67 ;
V_178 -> V_316 = V_374 ;
V_197 -> V_71 = V_178 -> V_315 ;
V_197 -> V_72 = V_374 ;
V_197 -> V_73 = V_17 -> V_55 -> V_74 ;
V_178 -> V_166 . V_162 = 2 ;
}
F_96 ( V_1 , V_178 , V_168 ) ;
F_33 ( L_90 , V_1 ) ;
return F_162 ( V_1 , V_178 ) ;
}
static inline void
F_178 ( struct V_3 * V_3 , struct V_377 * V_378 ,
struct V_379 * V_380 )
{
V_380 -> V_381 = V_382 ;
V_380 -> V_343 . V_383 . V_384 = V_385 ;
V_380 -> V_343 . V_383 . V_386 = V_3 -> V_326 -> V_327 . V_325 ;
V_380 -> V_343 . V_383 . V_387 = V_3 -> V_388 ;
V_380 -> V_343 . V_383 . V_389 = 0xffff ;
V_380 -> V_343 . V_383 . V_390 = true ;
V_380 -> V_343 . V_383 . V_391 = true ;
if ( V_3 -> V_392 == V_393 ||
V_3 -> V_392 == V_394 )
V_380 -> V_343 . V_383 . V_395 = true ;
}
static int
F_179 ( struct V_3 * V_3 , struct V_377 * V_378 )
{
memset ( V_378 , 0 , sizeof( * V_378 ) ) ;
switch ( V_3 -> V_6 ) {
case V_396 :
case V_397 :
V_378 -> V_398 . V_381 = V_399 ;
F_178 ( V_3 , V_378 , & V_378 -> V_400 ) ;
break;
case V_401 :
case V_402 :
V_378 -> V_400 . V_381 = V_399 ;
F_178 ( V_3 , V_378 , & V_378 -> V_398 ) ;
break;
case V_403 :
case V_404 :
F_178 ( V_3 , V_378 , & V_378 -> V_400 ) ;
F_178 ( V_3 , V_378 , & V_378 -> V_398 ) ;
break;
default:
F_3 ( L_91 , V_3 -> V_6 ) ;
return - V_89 ;
}
V_378 -> V_405 =
( V_3 -> V_406 & V_407 ? 0xc0 : 0 ) |
( V_3 -> V_406 & V_408 ? 0x30 : 0 ) |
( V_3 -> V_406 & V_408 ? 0x0f : 0 ) ;
return 0 ;
}
static int
F_180 ( struct V_178 * V_4 , struct V_1 * V_2 ,
struct V_409 * V_410 , struct V_167 * V_411 )
{
struct V_3 * V_3 = & V_4 -> V_231 -> V_3 ;
enum V_297 V_298 = F_139 ( V_3 ) ;
V_116 V_301 = V_2 -> V_13 -> V_301 ;
T_1 V_71 ;
T_2 V_412 , V_413 ;
int V_30 ;
if ( V_298 == V_69 ) {
V_71 = V_4 -> V_275 ;
V_412 = V_4 -> V_274 ;
V_413 = V_4 -> V_231 -> V_254 ;
} else {
V_71 = V_4 -> V_273 ;
V_412 = V_4 -> V_272 ;
V_413 = 0 ;
}
if ( F_1 ( V_2 , V_3 ) ) {
struct V_377 V_378 ;
V_30 = F_179 ( V_3 , & V_378 ) ;
if ( V_30 )
return V_30 ;
F_99 ( V_413 ) ;
V_30 = F_181 ( & V_4 -> V_299 , V_2 -> V_56 , V_301 ,
V_3 -> V_251 , V_3 -> V_253 ,
V_3 -> V_302 , V_3 -> V_303 ,
& V_378 , V_71 , V_412 , V_298 ) ;
} else {
V_30 = F_182 ( & V_4 -> V_299 , V_2 -> V_56 , V_301 ,
V_3 -> V_251 , V_3 -> V_253 ,
V_413 , V_71 , V_412 , V_298 ) ;
}
if ( V_30 < 0 ) {
F_3 ( L_92 , V_4 ) ;
return V_30 ;
}
V_30 = F_183 ( & V_4 -> V_299 , V_2 -> V_56 , V_301 , V_410 , V_411 ) ;
if ( V_30 < 0 )
F_3 ( L_93 , V_4 ) ;
return V_30 ;
}
static int
F_184 ( struct V_190 * V_2 , struct V_231 * V_4 )
{
struct V_3 * V_3 = & V_4 -> V_3 ;
struct V_178 * V_178 = F_106 ( V_4 ) ;
struct V_1 * V_1 = V_2 -> V_10 ;
struct V_409 * V_410 = NULL ;
struct V_167 * V_411 = NULL ;
int V_240 ;
F_33 ( L_94 ,
V_178 , V_3 -> V_246 ) ;
if ( F_1 ( V_1 , V_3 ) ) {
V_178 -> V_166 . V_171 . V_76 = F_151 ;
V_410 = & V_178 -> V_166 . V_171 ;
} else {
F_93 ( V_1 , V_178 ,
& V_178 -> V_166 ) ;
F_163 ( V_4 , V_2 , true , (struct V_355 * )
& V_178 -> V_166 . V_194 ) ;
F_95 ( V_1 , & V_178 -> V_166 ) ;
F_96 ( V_1 , V_178 ,
& V_178 -> V_166 . V_168 ) ;
V_240 = F_89 ( V_1 , V_178 -> V_60 ) ;
if ( V_240 ) {
F_3 ( L_53 , V_240 ) ;
return V_240 ;
}
V_411 = & V_178 -> V_166 . V_168 ;
}
V_240 = F_180 ( V_178 , V_1 , V_410 , V_411 ) ;
F_33 ( L_95 ,
V_178 , V_240 ) ;
return V_240 ;
}
static int
F_185 ( struct V_190 * V_2 , struct V_231 * V_4 , bool V_414 )
{
struct V_178 * V_178 = F_106 ( V_4 ) ;
int V_30 ;
F_33 ( L_96 ,
V_178 , V_4 -> V_3 . V_246 , V_4 -> V_254 ) ;
V_178 -> V_166 . V_171 . V_76 = F_157 ;
V_30 = F_180 ( V_178 , V_2 -> V_10 ,
& V_178 -> V_166 . V_171 , NULL ) ;
F_33 ( L_97 ,
V_178 , V_30 ) ;
return V_30 ;
}
static int
F_186 ( struct V_190 * V_2 , struct V_231 * V_4 , int V_94 )
{
struct V_178 * V_178 = F_106 ( V_4 ) ;
int V_30 = 0 ;
switch ( V_94 ) {
case V_415 :
F_53 ( & V_2 -> V_307 ) ;
F_73 ( & V_4 -> V_308 ) ;
F_54 ( & V_2 -> V_307 ) ;
F_142 ( V_178 , true ) ;
break;
case V_416 :
V_30 = F_168 ( V_4 , V_2 , false ) ;
break;
default:
F_3 ( L_98 , V_94 ) ;
V_30 = - V_89 ;
break;
}
return V_30 ;
}
static int
F_187 ( struct V_190 * V_2 , struct V_231 * V_4 , int V_94 )
{
struct V_1 * V_1 = V_2 -> V_10 ;
int V_30 ;
switch ( V_94 ) {
case V_352 :
V_30 = F_170 ( V_4 , V_2 ) ;
if ( ! V_30 )
V_1 -> V_417 = true ;
break;
case V_418 :
V_30 = F_168 ( V_4 , V_2 , true ) ;
break;
case V_348 :
V_30 = F_172 ( V_4 , V_2 ) ;
break;
case V_349 :
V_30 = F_174 ( V_4 , V_2 ) ;
break;
case V_350 :
V_30 = F_176 ( V_4 , V_2 ) ;
break;
case V_419 :
V_30 = F_155 ( V_2 , V_4 ) ;
break;
default:
F_3 ( L_99 , V_94 ) ;
V_30 = - V_89 ;
break;
}
return V_30 ;
}
struct V_26 *
F_79 ( struct V_124 * V_124 )
{
struct V_125 * V_126 = V_124 -> V_126 ;
struct V_26 * V_420 ;
struct V_421 * V_422 ;
int V_30 ;
V_422 = (struct V_421 * ) & V_126 -> V_423 ;
F_33 ( L_100 , & V_126 -> V_423 , V_422 ) ;
V_420 = F_188 ( & V_424 , F_84 , V_124 ,
V_425 , V_51 ) ;
if ( F_16 ( V_420 ) ) {
F_3 ( L_101 , F_17 ( V_420 ) ) ;
V_30 = F_17 ( V_420 ) ;
goto V_86;
}
F_33 ( L_102 , V_420 , V_420 -> V_10 ) ;
V_30 = F_189 ( V_420 , V_422 ) ;
if ( V_30 ) {
F_3 ( L_103 , V_30 ) ;
goto V_426;
}
V_30 = F_190 ( V_420 , 0 ) ;
if ( V_30 ) {
F_3 ( L_104 , V_30 ) ;
goto V_426;
}
return V_420 ;
V_426:
F_60 ( V_420 ) ;
V_86:
return F_14 ( V_30 ) ;
}
static int
F_191 ( struct V_125 * V_126 ,
struct V_427 * V_428 )
{
struct V_124 * V_124 ;
struct V_26 * V_429 ;
int V_30 ;
V_124 = F_19 ( sizeof( struct V_124 ) , V_66 ) ;
if ( ! V_124 )
return - V_67 ;
F_192 ( & V_124 -> V_136 , 0 ) ;
F_47 ( & V_124 -> V_101 ) ;
F_41 ( & V_124 -> V_131 ) ;
F_41 ( & V_124 -> V_135 ) ;
V_124 -> V_126 = V_126 ;
memcpy ( & V_126 -> V_423 , V_428 ,
sizeof( struct V_427 ) ) ;
V_429 = F_79 ( V_124 ) ;
if ( F_16 ( V_429 ) ) {
V_30 = F_17 ( V_429 ) ;
goto V_86;
}
V_124 -> V_13 = V_429 ;
V_126 -> V_430 = V_124 ;
return 0 ;
V_86:
F_23 ( V_124 ) ;
return V_30 ;
}
static int
F_57 ( struct V_1 * V_1 )
{
struct V_26 * V_13 = V_1 -> V_13 ;
struct V_112 V_431 ;
int V_30 ;
struct V_432 V_433 ;
memset ( & V_431 , 0 , sizeof( struct V_112 ) ) ;
V_431 . V_115 = V_1 -> V_115 ;
V_431 . V_434 = 7 ;
V_431 . V_435 = 7 ;
memset ( & V_433 , 0 , sizeof( V_433 ) ) ;
V_433 . V_119 = V_436 ;
if ( ! V_1 -> V_120 )
V_433 . V_119 = V_433 . V_119 | V_437 ;
V_431 . V_118 = ( void * ) & V_433 ;
V_431 . V_438 = sizeof( V_433 ) ;
V_30 = F_193 ( V_13 , & V_431 ) ;
if ( V_30 ) {
F_3 ( L_105 , V_30 ) ;
return V_30 ;
}
return 0 ;
}
static int
F_194 ( struct V_190 * V_2 , struct V_191 * V_192 )
{
struct V_1 * V_1 = V_2 -> V_10 ;
int V_30 ;
F_10 ( L_106 , V_1 ) ;
V_30 = F_195 ( & V_1 -> V_98 ) ;
if ( V_30 ) {
F_3 ( L_107 ,
V_1 ) ;
return V_30 ;
}
F_196 ( & V_1 -> V_98 ) ;
if ( ! V_192 -> V_206 )
return 0 ;
F_98 ( V_1 ) ;
F_10 ( L_108 , V_2 ) ;
V_30 = F_195 ( & V_1 -> V_97 ) ;
if ( V_30 )
return V_30 ;
F_10 ( L_109 , V_192 -> V_225 ) ;
return 0 ;
}
static void
F_197 ( struct V_125 * V_126 , struct V_190 * V_2 ,
struct V_1 * V_1 )
{
struct V_26 * V_13 = V_1 -> V_13 ;
struct V_439 * V_440 = & V_13 -> V_441 ;
V_2 -> V_442 = V_126 -> V_423 . V_443 ;
V_2 -> V_444 = V_440 -> V_71 . V_445 ;
V_2 -> V_446 = V_440 -> V_71 . V_447 ;
}
static int
F_198 ( struct V_125 * V_126 , struct V_190 * V_2 )
{
struct V_124 * V_124 = V_126 -> V_430 ;
struct V_1 * V_1 ;
int V_30 ;
V_448:
V_30 = F_199 ( & V_124 -> V_136 ) ;
if ( V_30 )
return - V_449 ;
F_53 ( & V_126 -> V_127 ) ;
if ( V_126 -> V_450 >= V_451 ) {
F_54 ( & V_126 -> V_127 ) ;
F_33 ( L_110 ,
V_126 -> V_450 ) ;
return - V_449 ;
}
F_54 ( & V_126 -> V_127 ) ;
F_8 ( & V_124 -> V_101 ) ;
if ( F_72 ( & V_124 -> V_135 ) ) {
F_9 ( & V_124 -> V_101 ) ;
goto V_448;
}
V_1 = F_200 ( & V_124 -> V_135 ,
struct V_1 , V_96 ) ;
F_73 ( & V_1 -> V_96 ) ;
F_9 ( & V_124 -> V_101 ) ;
V_2 -> V_10 = V_1 ;
V_1 -> V_2 = V_2 ;
V_1 -> V_94 = V_145 ;
F_197 ( V_126 , V_2 , V_1 ) ;
F_33 ( L_111 , V_1 ) ;
return 0 ;
}
static void
F_201 ( struct V_125 * V_126 )
{
struct V_124 * V_124 = V_126 -> V_430 ;
struct V_1 * V_1 , * V_452 ;
if ( V_124 -> V_13 )
F_60 ( V_124 -> V_13 ) ;
F_8 ( & V_124 -> V_101 ) ;
if ( ! F_72 ( & V_124 -> V_135 ) ) {
F_10 ( L_112 ) ;
F_202 (isert_conn, n,
&isert_np->pending,
node) {
F_10 ( L_113 ,
V_1 , V_1 -> V_94 ) ;
F_58 ( V_1 ) ;
}
}
if ( ! F_72 ( & V_124 -> V_131 ) ) {
F_10 ( L_114 ) ;
F_202 (isert_conn, n,
&isert_np->accepted,
node) {
F_10 ( L_113 ,
V_1 , V_1 -> V_94 ) ;
F_58 ( V_1 ) ;
}
}
F_9 ( & V_124 -> V_101 ) ;
V_126 -> V_430 = NULL ;
F_23 ( V_124 ) ;
}
static void V_103 ( struct V_345 * V_346 )
{
struct V_1 * V_1 = F_68 ( V_346 ,
struct V_1 ,
V_102 ) ;
F_10 ( L_115 , V_1 ) ;
F_8 ( & V_1 -> V_101 ) ;
V_1 -> V_94 = V_152 ;
F_9 ( & V_1 -> V_101 ) ;
F_10 ( L_116 , V_1 ) ;
F_69 ( V_1 ) ;
}
static void
F_203 ( struct V_1 * V_1 )
{
struct V_190 * V_2 = V_1 -> V_2 ;
F_10 ( L_22 , V_1 ) ;
if ( V_1 -> V_417 ) {
F_10 ( L_117 , V_1 ) ;
F_204 ( & V_2 -> V_453 ,
V_454 * V_455 ) ;
}
}
static void
F_205 ( struct V_190 * V_2 )
{
F_10 ( L_118 , V_2 ) ;
if ( V_2 -> V_277 ) {
F_206 ( V_2 -> V_277 -> V_456 ) ;
F_207 ( V_2 -> V_277 -> V_456 ) ;
}
}
static void
F_208 ( struct V_190 * V_2 )
{
struct V_231 * V_4 , * V_457 ;
static F_209 ( V_458 ) ;
F_53 ( & V_2 -> V_307 ) ;
F_202 (cmd, tmp, &conn->conn_cmd_list, i_conn_node) {
if ( ( V_4 -> V_256 & V_459 ) &&
( V_4 -> V_254 < V_2 -> V_277 -> V_278 -> V_460 ) &&
( V_4 -> V_254 < V_4 -> V_3 . V_246 ) )
F_65 ( & V_4 -> V_308 , & V_458 ) ;
}
F_54 ( & V_2 -> V_307 ) ;
F_202 (cmd, tmp, &drop_cmd_list, i_conn_node) {
F_73 ( & V_4 -> V_308 ) ;
if ( V_4 -> V_258 != V_415 ) {
struct V_178 * V_178 = F_106 ( V_4 ) ;
F_10 ( L_119 , V_2 , V_4 ) ;
F_142 ( V_178 , true ) ;
}
}
}
static void F_210 ( struct V_190 * V_2 )
{
struct V_1 * V_1 = V_2 -> V_10 ;
F_10 ( L_120 , V_1 ) ;
F_8 ( & V_1 -> V_101 ) ;
F_75 ( V_1 ) ;
F_9 ( & V_1 -> V_101 ) ;
F_81 ( V_1 -> V_56 ) ;
F_208 ( V_2 ) ;
F_205 ( V_2 ) ;
F_203 ( V_1 ) ;
F_74 ( V_140 , & V_1 -> V_102 ) ;
}
static void F_211 ( struct V_190 * V_2 )
{
struct V_1 * V_1 = V_2 -> V_10 ;
F_81 ( V_1 -> V_56 ) ;
F_69 ( V_1 ) ;
}
static void F_212 ( struct V_190 * V_2 )
{
struct V_461 V_18 ;
F_44 ( & V_18 ) ;
F_195 ( & V_18 ) ;
}
static int T_5 F_213 ( void )
{
int V_30 ;
V_353 = F_214 ( L_121 ,
V_462 | V_463 , 0 ) ;
if ( ! V_353 ) {
F_3 ( L_122 ) ;
return - V_67 ;
}
V_140 = F_214 ( L_123 , V_462 ,
V_464 ) ;
if ( ! V_140 ) {
F_3 ( L_124 ) ;
V_30 = - V_67 ;
goto V_465;
}
F_215 ( & V_466 ) ;
F_10 ( L_125 ) ;
return 0 ;
V_465:
F_216 ( V_353 ) ;
return V_30 ;
}
static void T_6 F_217 ( void )
{
F_218 () ;
F_216 ( V_140 ) ;
F_216 ( V_353 ) ;
F_219 ( & V_466 ) ;
F_10 ( L_126 ) ;
}
