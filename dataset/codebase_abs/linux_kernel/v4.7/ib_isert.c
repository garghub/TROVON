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
V_1 -> V_46 = V_20 ( V_17 -> V_44 -> V_45 . V_46 ,
V_17 -> V_44 -> V_45 . V_47 ) ;
V_29 . V_36 . V_48 = 1 ;
V_29 . V_49 = V_50 ;
V_29 . V_51 = V_52 ;
if ( V_17 -> V_53 )
V_29 . V_54 |= V_55 ;
V_30 = F_13 ( V_27 , V_17 -> V_56 , & V_29 ) ;
if ( V_30 ) {
F_3 ( L_4 , V_30 ) ;
return F_14 ( V_30 ) ;
}
return V_27 -> V_57 ;
}
static int
F_15 ( struct V_1 * V_1 , struct V_26 * V_27 )
{
struct V_15 * V_18 ;
int V_30 ;
V_18 = F_7 ( V_1 ) ;
V_1 -> V_57 = F_12 ( V_1 , V_18 , V_27 ) ;
if ( F_16 ( V_1 -> V_57 ) ) {
V_30 = F_17 ( V_1 -> V_57 ) ;
goto V_58;
}
return 0 ;
V_58:
F_11 ( V_18 ) ;
return V_30 ;
}
static int
F_18 ( struct V_1 * V_1 )
{
struct V_16 * V_17 = V_1 -> V_17 ;
struct V_44 * V_59 = V_17 -> V_44 ;
struct V_60 * V_61 ;
struct V_62 * V_63 ;
T_1 V_64 ;
int V_19 , V_65 ;
V_1 -> V_66 = F_19 ( V_40 *
sizeof( struct V_60 ) , V_67 ) ;
if ( ! V_1 -> V_66 )
goto V_68;
V_61 = V_1 -> V_66 ;
for ( V_19 = 0 ; V_19 < V_40 ; V_19 ++ , V_61 ++ ) {
V_64 = F_20 ( V_59 , ( void * ) V_61 ,
V_69 , V_70 ) ;
if ( F_21 ( V_59 , V_64 ) )
goto V_71;
V_61 -> V_64 = V_64 ;
V_63 = & V_61 -> V_63 ;
V_63 -> V_72 = V_61 -> V_64 ;
V_63 -> V_73 = V_69 ;
V_63 -> V_74 = V_17 -> V_56 -> V_75 ;
V_61 -> V_76 . V_77 = V_78 ;
}
return 0 ;
V_71:
V_61 = V_1 -> V_66 ;
for ( V_65 = 0 ; V_65 < V_19 ; V_65 ++ , V_61 ++ ) {
F_22 ( V_59 , V_61 -> V_64 ,
V_69 , V_70 ) ;
}
F_23 ( V_1 -> V_66 ) ;
V_1 -> V_66 = NULL ;
V_68:
F_3 ( L_5 , V_1 ) ;
return - V_79 ;
}
static void
F_24 ( struct V_1 * V_1 )
{
struct V_44 * V_59 = V_1 -> V_17 -> V_44 ;
struct V_60 * V_61 ;
int V_19 ;
if ( ! V_1 -> V_66 )
return;
V_61 = V_1 -> V_66 ;
for ( V_19 = 0 ; V_19 < V_40 ; V_19 ++ , V_61 ++ ) {
F_22 ( V_59 , V_61 -> V_64 ,
V_69 , V_70 ) ;
}
F_23 ( V_1 -> V_66 ) ;
V_1 -> V_66 = NULL ;
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
int V_19 , V_80 , V_30 = 0 ;
V_17 -> V_22 = V_20 ( V_81 , F_28 ( int , F_29 () ,
V_17 -> V_44 -> V_82 ) ) ;
F_10 ( L_6
L_7 ,
V_17 -> V_22 , V_17 -> V_44 -> V_83 ,
V_17 -> V_44 -> V_82 ,
V_17 -> V_53 ) ;
V_17 -> V_23 = F_30 ( V_17 -> V_22 , sizeof( struct V_15 ) ,
V_67 ) ;
if ( ! V_17 -> V_23 ) {
F_3 ( L_8 ) ;
return - V_79 ;
}
V_80 = V_20 ( V_84 , V_17 -> V_44 -> V_45 . V_80 ) ;
for ( V_19 = 0 ; V_19 < V_17 -> V_22 ; V_19 ++ ) {
struct V_15 * V_18 = & V_17 -> V_23 [ V_19 ] ;
V_18 -> V_17 = V_17 ;
V_18 -> V_34 = F_31 ( V_17 -> V_44 , V_18 , V_80 , V_19 ,
V_85 ) ;
if ( F_16 ( V_18 -> V_34 ) ) {
F_3 ( L_9 ) ;
V_30 = F_17 ( V_18 -> V_34 ) ;
V_18 -> V_34 = NULL ;
goto V_86;
}
}
return 0 ;
V_86:
F_25 ( V_17 ) ;
return V_30 ;
}
static int
F_32 ( struct V_16 * V_17 )
{
struct V_44 * V_59 = V_17 -> V_44 ;
int V_30 ;
F_33 ( L_10 , V_59 -> V_45 . V_46 ) ;
F_33 ( L_11 , V_59 -> V_45 . V_47 ) ;
V_30 = F_27 ( V_17 ) ;
if ( V_30 )
goto V_87;
V_17 -> V_56 = F_34 ( V_59 ) ;
if ( F_16 ( V_17 -> V_56 ) ) {
V_30 = F_17 ( V_17 -> V_56 ) ;
F_3 ( L_12 ,
V_17 , V_30 ) ;
goto V_86;
}
V_17 -> V_53 = V_59 -> V_45 . V_88 &
V_89 ? true : false ;
return 0 ;
V_86:
F_25 ( V_17 ) ;
V_87:
if ( V_30 > 0 )
V_30 = - V_90 ;
return V_30 ;
}
static void
F_35 ( struct V_16 * V_17 )
{
F_10 ( L_13 , V_17 ) ;
F_36 ( V_17 -> V_56 ) ;
F_25 ( V_17 ) ;
}
static void
F_37 ( struct V_16 * V_17 )
{
F_8 ( & V_21 ) ;
V_17 -> V_91 -- ;
F_10 ( L_14 , V_17 , V_17 -> V_91 ) ;
if ( ! V_17 -> V_91 ) {
F_35 ( V_17 ) ;
F_38 ( & V_17 -> V_92 ) ;
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
if ( V_17 -> V_44 -> V_93 == V_27 -> V_17 -> V_93 ) {
V_17 -> V_91 ++ ;
F_10 ( L_15 ,
V_17 , V_17 -> V_91 ) ;
F_9 ( & V_21 ) ;
return V_17 ;
}
}
V_17 = F_19 ( sizeof( struct V_16 ) , V_67 ) ;
if ( ! V_17 ) {
F_9 ( & V_21 ) ;
return F_14 ( - V_79 ) ;
}
F_41 ( & V_17 -> V_92 ) ;
V_17 -> V_44 = V_27 -> V_17 ;
V_30 = F_32 ( V_17 ) ;
if ( V_30 ) {
F_23 ( V_17 ) ;
F_9 ( & V_21 ) ;
return F_14 ( V_30 ) ;
}
V_17 -> V_91 ++ ;
F_42 ( & V_17 -> V_92 , & V_94 ) ;
F_10 ( L_16 ,
V_17 , V_17 -> V_91 ) ;
F_9 ( & V_21 ) ;
return V_17 ;
}
static void
F_43 ( struct V_1 * V_1 )
{
V_1 -> V_95 = V_96 ;
F_41 ( & V_1 -> V_97 ) ;
F_44 ( & V_1 -> V_98 ) ;
F_44 ( & V_1 -> V_99 ) ;
F_45 ( & V_1 -> V_100 ) ;
F_46 ( & V_1 -> V_101 ) ;
F_47 ( & V_1 -> V_102 , V_103 ) ;
}
static void
F_48 ( struct V_1 * V_1 )
{
struct V_44 * V_59 = V_1 -> V_17 -> V_44 ;
F_22 ( V_59 , V_1 -> V_104 ,
V_69 , V_105 ) ;
F_23 ( V_1 -> V_106 ) ;
F_22 ( V_59 , V_1 -> V_107 ,
V_69 ,
V_70 ) ;
F_23 ( V_1 -> V_108 ) ;
}
static int
F_49 ( struct V_1 * V_1 ,
struct V_44 * V_59 )
{
int V_30 ;
V_1 -> V_108 = F_19 ( sizeof( * V_1 -> V_108 ) ,
V_67 ) ;
if ( ! V_1 -> V_108 ) {
F_3 ( L_17 ) ;
return - V_79 ;
}
V_1 -> V_107 = F_20 ( V_59 ,
V_1 -> V_108 ,
V_69 , V_70 ) ;
V_30 = F_21 ( V_59 , V_1 -> V_107 ) ;
if ( V_30 ) {
F_3 ( L_18 , V_30 ) ;
V_1 -> V_107 = 0 ;
goto V_109;
}
V_1 -> V_106 = F_19 ( V_69 , V_67 ) ;
if ( ! V_1 -> V_106 ) {
F_3 ( L_19 ) ;
goto V_110;
}
V_1 -> V_104 = F_20 ( V_59 ,
V_1 -> V_106 ,
V_69 , V_105 ) ;
V_30 = F_21 ( V_59 , V_1 -> V_104 ) ;
if ( V_30 ) {
F_3 ( L_20 , V_30 ) ;
V_1 -> V_104 = 0 ;
goto V_111;
}
return 0 ;
V_111:
F_23 ( V_1 -> V_106 ) ;
V_110:
F_22 ( V_59 , V_1 -> V_107 ,
V_69 , V_70 ) ;
V_109:
F_23 ( V_1 -> V_108 ) ;
return V_30 ;
}
static void
F_50 ( struct V_1 * V_1 ,
struct V_112 * V_113 )
{
struct V_114 * V_29 = & V_1 -> V_17 -> V_44 -> V_45 ;
V_1 -> V_115 = F_28 ( V_116 , V_113 -> V_115 ,
V_29 -> V_117 ) ;
F_33 ( L_21 , V_1 -> V_115 ) ;
if ( V_113 -> V_118 ) {
V_116 V_119 = * ( V_116 * ) V_113 -> V_118 ;
V_1 -> V_120 = ! ( V_119 & V_121 ) &&
( V_29 -> V_88 &
V_122 ) ;
if ( V_1 -> V_120 )
F_10 ( L_22 ) ;
}
}
static int
F_51 ( struct V_26 * V_27 , struct V_123 * V_11 )
{
struct V_124 * V_124 = V_27 -> V_10 ;
struct V_125 * V_126 = V_124 -> V_126 ;
struct V_1 * V_1 ;
struct V_16 * V_17 ;
int V_30 = 0 ;
F_52 ( & V_126 -> V_127 ) ;
if ( ! V_126 -> V_128 ) {
F_53 ( & V_126 -> V_127 ) ;
F_33 ( L_23 ) ;
return F_54 ( V_27 , NULL , 0 ) ;
}
F_53 ( & V_126 -> V_127 ) ;
F_33 ( L_24 ,
V_27 , V_27 -> V_10 ) ;
V_1 = F_19 ( sizeof( struct V_1 ) , V_67 ) ;
if ( ! V_1 )
return - V_79 ;
F_43 ( V_1 ) ;
V_1 -> V_13 = V_27 ;
V_30 = F_49 ( V_1 , V_27 -> V_17 ) ;
if ( V_30 )
goto V_87;
V_17 = F_39 ( V_27 ) ;
if ( F_16 ( V_17 ) ) {
V_30 = F_17 ( V_17 ) ;
goto V_129;
}
V_1 -> V_17 = V_17 ;
F_50 ( V_1 , & V_11 -> V_113 . V_2 ) ;
V_30 = F_15 ( V_1 , V_27 ) ;
if ( V_30 )
goto V_130;
V_30 = F_55 ( V_1 ) ;
if ( V_30 )
goto V_130;
V_30 = F_56 ( V_1 ) ;
if ( V_30 )
goto V_130;
F_8 ( & V_124 -> V_101 ) ;
F_42 ( & V_1 -> V_97 , & V_124 -> V_131 ) ;
F_9 ( & V_124 -> V_101 ) ;
return 0 ;
V_130:
F_37 ( V_17 ) ;
V_129:
F_48 ( V_1 ) ;
V_87:
F_23 ( V_1 ) ;
F_54 ( V_27 , NULL , 0 ) ;
return V_30 ;
}
static void
F_57 ( struct V_1 * V_1 )
{
struct V_16 * V_17 = V_1 -> V_17 ;
F_33 ( L_25 , V_1 ) ;
F_58 ( ! V_17 ) ;
F_24 ( V_1 ) ;
if ( V_1 -> V_13 )
F_59 ( V_1 -> V_13 ) ;
if ( V_1 -> V_57 ) {
struct V_15 * V_18 = V_1 -> V_57 -> V_35 -> V_132 ;
F_11 ( V_18 ) ;
F_60 ( V_1 -> V_57 ) ;
}
if ( V_1 -> V_108 )
F_48 ( V_1 ) ;
F_37 ( V_17 ) ;
F_23 ( V_1 ) ;
}
static void
F_61 ( struct V_26 * V_27 )
{
struct V_1 * V_1 = V_27 -> V_57 -> V_32 ;
struct V_124 * V_124 = V_27 -> V_10 ;
F_10 ( L_25 , V_1 ) ;
F_8 ( & V_1 -> V_101 ) ;
V_1 -> V_95 = V_133 ;
F_62 ( & V_1 -> V_100 ) ;
F_9 ( & V_1 -> V_101 ) ;
F_8 ( & V_124 -> V_101 ) ;
F_63 ( & V_1 -> V_97 , & V_124 -> V_134 ) ;
F_9 ( & V_124 -> V_101 ) ;
F_10 ( L_26 , V_124 ) ;
F_64 ( & V_124 -> V_135 ) ;
}
static void
F_65 ( struct V_100 * V_100 )
{
struct V_1 * V_1 = F_66 ( V_100 ,
struct V_1 , V_100 ) ;
F_10 ( L_27 , V_1 , V_136 -> V_137 ,
V_136 -> V_138 ) ;
F_57 ( V_1 ) ;
}
static void
F_67 ( struct V_1 * V_1 )
{
F_68 ( & V_1 -> V_100 , F_65 ) ;
}
static void
F_69 ( struct V_1 * V_1 )
{
struct V_124 * V_124 = V_1 -> V_13 -> V_10 ;
F_8 ( & V_124 -> V_101 ) ;
if ( ! F_70 ( & V_1 -> V_97 ) ) {
F_71 ( & V_1 -> V_97 ) ;
F_67 ( V_1 ) ;
F_72 ( V_139 , & V_1 -> V_102 ) ;
}
F_9 ( & V_124 -> V_101 ) ;
}
static void
F_73 ( struct V_1 * V_1 )
{
int V_58 ;
if ( V_1 -> V_95 >= V_140 )
return;
F_10 ( L_28 ,
V_1 , V_1 -> V_95 ) ;
V_1 -> V_95 = V_140 ;
V_58 = F_74 ( V_1 -> V_13 ) ;
if ( V_58 )
F_6 ( L_29 ,
V_1 ) ;
}
static int
F_75 ( struct V_124 * V_124 ,
enum V_141 V_11 )
{
F_33 ( L_30 ,
F_76 ( V_11 ) , V_11 , V_124 ) ;
switch ( V_11 ) {
case V_142 :
V_124 -> V_13 = NULL ;
break;
case V_143 :
V_124 -> V_13 = F_77 ( V_124 ) ;
if ( F_16 ( V_124 -> V_13 ) ) {
F_3 ( L_31 ,
V_124 , F_17 ( V_124 -> V_13 ) ) ;
V_124 -> V_13 = NULL ;
}
break;
default:
F_3 ( L_32 ,
V_124 , V_11 ) ;
}
return - 1 ;
}
static int
F_78 ( struct V_26 * V_27 ,
enum V_141 V_11 )
{
struct V_1 * V_1 = V_27 -> V_57 -> V_32 ;
F_8 ( & V_1 -> V_101 ) ;
switch ( V_1 -> V_95 ) {
case V_140 :
break;
case V_133 :
F_73 ( V_1 ) ;
F_79 ( V_1 -> V_57 ) ;
F_69 ( V_1 ) ;
break;
case V_144 :
case V_145 :
F_80 ( V_1 -> V_2 , 0 ) ;
break;
default:
F_6 ( L_33 ,
V_1 , V_1 -> V_95 ) ;
}
F_9 ( & V_1 -> V_101 ) ;
return 0 ;
}
static int
F_81 ( struct V_26 * V_27 )
{
struct V_1 * V_1 = V_27 -> V_57 -> V_32 ;
F_71 ( & V_1 -> V_97 ) ;
V_1 -> V_13 = NULL ;
F_67 ( V_1 ) ;
return - 1 ;
}
static int
F_82 ( struct V_26 * V_27 , struct V_123 * V_11 )
{
struct V_124 * V_124 = V_27 -> V_10 ;
int V_30 = 0 ;
F_10 ( L_34 ,
F_76 ( V_11 -> V_11 ) , V_11 -> V_11 ,
V_11 -> V_146 , V_27 , V_27 -> V_10 ) ;
if ( V_124 -> V_13 == V_27 )
return F_75 ( V_27 -> V_10 , V_11 -> V_11 ) ;
switch ( V_11 -> V_11 ) {
case V_147 :
V_30 = F_51 ( V_27 , V_11 ) ;
if ( V_30 )
F_3 ( L_35 , V_30 ) ;
break;
case V_148 :
F_61 ( V_27 ) ;
break;
case V_143 :
case V_149 :
case V_142 :
case V_150 :
V_30 = F_78 ( V_27 , V_11 -> V_11 ) ;
break;
case V_151 :
case V_152 :
case V_153 :
V_30 = F_81 ( V_27 ) ;
break;
default:
F_3 ( L_36 , V_11 -> V_11 ) ;
break;
}
return V_30 ;
}
static int
F_83 ( struct V_1 * V_1 , T_2 V_154 )
{
struct V_155 * V_156 , * V_157 ;
int V_19 , V_30 ;
struct V_60 * V_61 ;
for ( V_156 = V_1 -> V_156 , V_19 = 0 ; V_19 < V_154 ; V_19 ++ , V_156 ++ ) {
V_61 = & V_1 -> V_66 [ V_19 ] ;
V_156 -> V_158 = & V_61 -> V_76 ;
V_156 -> V_159 = & V_61 -> V_63 ;
V_156 -> V_160 = 1 ;
V_156 -> V_161 = V_156 + 1 ;
}
V_156 -- ;
V_156 -> V_161 = NULL ;
V_30 = F_84 ( V_1 -> V_57 , V_1 -> V_156 ,
& V_157 ) ;
if ( V_30 )
F_3 ( L_37 , V_30 ) ;
return V_30 ;
}
static int
F_85 ( struct V_1 * V_1 , struct V_60 * V_61 )
{
struct V_155 * V_157 , V_156 ;
int V_30 ;
V_156 . V_158 = & V_61 -> V_76 ;
V_156 . V_159 = & V_61 -> V_63 ;
V_156 . V_160 = 1 ;
V_156 . V_161 = NULL ;
V_30 = F_84 ( V_1 -> V_57 , & V_156 , & V_157 ) ;
if ( V_30 )
F_3 ( L_37 , V_30 ) ;
return V_30 ;
}
static int
F_86 ( struct V_1 * V_1 , struct V_162 * V_163 )
{
struct V_44 * V_59 = V_1 -> V_13 -> V_17 ;
struct V_164 V_165 , * V_166 ;
int V_30 ;
F_87 ( V_59 , V_163 -> V_64 ,
V_167 , V_105 ) ;
V_163 -> V_168 . V_77 = V_169 ;
V_165 . V_161 = NULL ;
V_165 . V_158 = & V_163 -> V_168 ;
V_165 . V_159 = V_163 -> V_170 ;
V_165 . V_160 = V_163 -> V_160 ;
V_165 . V_171 = V_172 ;
V_165 . V_173 = V_174 ;
V_30 = F_88 ( V_1 -> V_57 , & V_165 , & V_166 ) ;
if ( V_30 )
F_3 ( L_38 , V_30 ) ;
return V_30 ;
}
static void
F_89 ( struct V_1 * V_1 ,
struct V_175 * V_175 ,
struct V_162 * V_163 )
{
struct V_16 * V_17 = V_1 -> V_17 ;
struct V_44 * V_59 = V_17 -> V_44 ;
F_90 ( V_59 , V_163 -> V_64 ,
V_167 , V_105 ) ;
memset ( & V_163 -> V_176 , 0 , sizeof( struct V_177 ) ) ;
V_163 -> V_176 . V_119 = V_178 ;
V_163 -> V_160 = 1 ;
if ( V_163 -> V_170 [ 0 ] . V_74 != V_17 -> V_56 -> V_75 ) {
V_163 -> V_170 [ 0 ] . V_74 = V_17 -> V_56 -> V_75 ;
F_33 ( L_39 , V_163 ) ;
}
}
static int
F_91 ( struct V_1 * V_1 ,
struct V_162 * V_163 )
{
struct V_16 * V_17 = V_1 -> V_17 ;
struct V_44 * V_59 = V_17 -> V_44 ;
T_1 V_64 ;
V_64 = F_20 ( V_59 , ( void * ) V_163 ,
V_167 , V_105 ) ;
if ( F_21 ( V_59 , V_64 ) ) {
F_3 ( L_40 ) ;
return - V_79 ;
}
V_163 -> V_64 = V_64 ;
V_163 -> V_170 [ 0 ] . V_72 = V_163 -> V_64 ;
V_163 -> V_170 [ 0 ] . V_73 = V_167 ;
V_163 -> V_170 [ 0 ] . V_74 = V_17 -> V_56 -> V_75 ;
F_33 ( L_41 ,
V_163 -> V_170 [ 0 ] . V_72 , V_163 -> V_170 [ 0 ] . V_73 ,
V_163 -> V_170 [ 0 ] . V_74 ) ;
return 0 ;
}
static void
F_92 ( struct V_1 * V_1 , struct V_175 * V_175 ,
struct V_164 * V_165 )
{
struct V_162 * V_163 = & V_175 -> V_163 ;
V_163 -> V_168 . V_77 = V_179 ;
V_165 -> V_158 = & V_163 -> V_168 ;
if ( V_1 -> V_120 && V_175 -> V_180 ) {
V_165 -> V_171 = V_181 ;
V_165 -> V_182 . V_183 = V_175 -> V_180 ;
} else {
V_165 -> V_171 = V_172 ;
}
V_165 -> V_159 = & V_163 -> V_170 [ 0 ] ;
V_165 -> V_160 = V_175 -> V_163 . V_160 ;
V_165 -> V_173 = V_174 ;
}
static int
F_55 ( struct V_1 * V_1 )
{
struct V_155 V_156 , * V_184 ;
struct V_62 V_185 ;
int V_30 ;
memset ( & V_185 , 0 , sizeof( struct V_62 ) ) ;
V_185 . V_72 = V_1 -> V_107 ;
V_185 . V_73 = V_69 ;
V_185 . V_74 = V_1 -> V_17 -> V_56 -> V_75 ;
F_33 ( L_42 ,
V_185 . V_72 , V_185 . V_73 , V_185 . V_74 ) ;
V_1 -> V_108 -> V_76 . V_77 = V_186 ;
memset ( & V_156 , 0 , sizeof( struct V_155 ) ) ;
V_156 . V_158 = & V_1 -> V_108 -> V_76 ;
V_156 . V_159 = & V_185 ;
V_156 . V_160 = 1 ;
V_30 = F_84 ( V_1 -> V_57 , & V_156 , & V_184 ) ;
if ( V_30 )
F_3 ( L_43 , V_30 ) ;
return V_30 ;
}
static int
F_93 ( struct V_187 * V_2 , struct V_188 * V_189 ,
T_2 V_73 )
{
struct V_1 * V_1 = V_2 -> V_10 ;
struct V_16 * V_17 = V_1 -> V_17 ;
struct V_44 * V_59 = V_17 -> V_44 ;
struct V_162 * V_163 = & V_1 -> V_190 ;
int V_30 ;
F_89 ( V_1 , NULL , V_163 ) ;
memcpy ( & V_163 -> V_191 , & V_189 -> V_192 [ 0 ] ,
sizeof( struct V_193 ) ) ;
F_91 ( V_1 , V_163 ) ;
if ( V_73 > 0 ) {
struct V_62 * V_194 = & V_163 -> V_170 [ 1 ] ;
F_90 ( V_59 , V_1 -> V_104 ,
V_73 , V_105 ) ;
memcpy ( V_1 -> V_106 , V_189 -> V_195 , V_73 ) ;
F_87 ( V_59 , V_1 -> V_104 ,
V_73 , V_105 ) ;
V_194 -> V_72 = V_1 -> V_104 ;
V_194 -> V_73 = V_73 ;
V_194 -> V_74 = V_1 -> V_17 -> V_56 -> V_75 ;
V_163 -> V_160 = 2 ;
}
if ( ! V_189 -> V_196 ) {
if ( V_189 -> V_197 ) {
V_30 = F_18 ( V_1 ) ;
if ( V_30 )
return V_30 ;
V_30 = F_83 ( V_1 ,
V_40 ) ;
if ( V_30 )
return V_30 ;
F_8 ( & V_1 -> V_101 ) ;
V_1 -> V_95 = V_145 ;
F_9 ( & V_1 -> V_101 ) ;
goto V_198;
}
V_30 = F_55 ( V_1 ) ;
if ( V_30 )
return V_30 ;
}
V_198:
V_30 = F_86 ( V_1 , V_163 ) ;
if ( V_30 )
return V_30 ;
return 0 ;
}
static void
F_94 ( struct V_1 * V_1 )
{
struct V_60 * V_61 = V_1 -> V_108 ;
int V_199 = V_1 -> V_200 ;
struct V_187 * V_2 = V_1 -> V_2 ;
struct V_188 * V_189 = V_2 -> V_201 ;
int V_202 ;
F_10 ( L_25 , V_1 ) ;
F_95 ( ! V_189 ) ;
if ( V_189 -> V_203 ) {
struct V_204 * V_205 =
(struct V_204 * ) & V_61 -> V_191 ;
V_189 -> V_206 = ( ! V_205 -> V_207 ) ? 1 : 0 ;
V_189 -> V_208 =
( V_205 -> V_119 & V_209 )
>> 2 ;
V_189 -> V_210 = V_205 -> V_211 ;
V_189 -> V_212 = V_205 -> V_213 ;
memcpy ( V_189 -> V_214 , V_205 -> V_214 , 6 ) ;
V_189 -> V_215 = F_96 ( V_205 -> V_216 ) ;
V_189 -> V_217 = V_205 -> V_218 ;
V_189 -> V_219 = F_96 ( V_205 -> V_220 ) ;
V_189 -> V_221 = F_97 ( V_205 -> V_221 ) ;
V_189 -> V_207 = F_97 ( V_205 -> V_207 ) ;
}
memcpy ( & V_189 -> V_222 [ 0 ] , ( void * ) & V_61 -> V_191 , V_223 ) ;
V_202 = V_20 ( V_199 , V_224 ) ;
F_33 ( L_44
L_45 , V_202 , V_199 ,
V_224 ) ;
memcpy ( V_189 -> V_225 , & V_61 -> V_226 [ 0 ] , V_202 ) ;
if ( V_189 -> V_203 ) {
F_98 ( & V_1 -> V_98 ) ;
return;
}
F_99 ( & V_2 -> V_227 , 0 ) ;
}
static struct V_228
* F_100 ( struct V_187 * V_2 , struct V_60 * V_61 )
{
struct V_1 * V_1 = V_2 -> V_10 ;
struct V_175 * V_175 ;
struct V_228 * V_4 ;
V_4 = F_101 ( V_2 , V_229 ) ;
if ( ! V_4 ) {
F_3 ( L_46 ) ;
return NULL ;
}
V_175 = F_102 ( V_4 ) ;
V_175 -> V_2 = V_1 ;
V_175 -> V_228 = V_4 ;
V_175 -> V_61 = V_61 ;
return V_4 ;
}
static int
F_103 ( struct V_1 * V_1 ,
struct V_175 * V_175 , struct V_228 * V_4 ,
struct V_60 * V_61 , unsigned char * V_230 )
{
struct V_187 * V_2 = V_1 -> V_2 ;
struct V_231 * V_232 = (struct V_231 * ) V_230 ;
int V_233 , V_234 , V_235 , V_236 , V_237 ;
bool V_238 = false ;
unsigned int V_239 ;
V_237 = F_104 ( V_2 , V_4 , V_230 ) ;
if ( V_237 < 0 )
return V_237 ;
V_233 = V_4 -> V_240 ;
V_234 = V_4 -> V_241 ;
V_235 = V_4 -> V_242 ;
V_239 = V_4 -> V_3 . V_243 ;
if ( V_233 && V_234 == V_239 )
V_4 -> V_3 . V_244 |= V_245 ;
V_237 = F_105 ( V_2 , V_4 , V_232 ) ;
if ( V_237 < 0 ) {
return 0 ;
} else if ( V_237 > 0 ) {
V_238 = true ;
goto V_246;
}
if ( ! V_233 )
return 0 ;
if ( V_234 != V_239 ) {
V_236 = F_106 ( 1UL , F_107 ( V_234 , V_247 ) ) ;
F_108 ( V_4 -> V_3 . V_248 , V_236 ,
& V_61 -> V_226 [ 0 ] , V_234 ) ;
F_33 ( L_47 ,
V_236 , V_234 ) ;
} else {
F_109 ( & V_175 -> V_249 , 1 ) ;
V_4 -> V_3 . V_248 = & V_175 -> V_249 ;
V_4 -> V_3 . V_250 = 1 ;
F_110 ( & V_175 -> V_249 , & V_61 -> V_226 [ 0 ] , V_234 ) ;
F_33 ( L_48 ,
V_234 ) ;
}
V_4 -> V_251 += V_234 ;
if ( V_4 -> V_251 == V_4 -> V_3 . V_243 ) {
F_52 ( & V_4 -> V_252 ) ;
V_4 -> V_253 |= V_254 ;
V_4 -> V_255 = V_256 ;
F_53 ( & V_4 -> V_252 ) ;
}
V_246:
V_237 = F_111 ( V_2 , V_4 , V_230 , V_232 -> V_216 ) ;
if ( ! V_237 && V_238 == false && V_235 )
F_112 ( V_4 ) ;
else if ( V_238 && V_233 )
F_113 ( & V_4 -> V_3 ) ;
return 0 ;
}
static int
F_114 ( struct V_1 * V_1 ,
struct V_60 * V_61 , unsigned char * V_230 )
{
struct V_257 * V_258 ;
struct V_187 * V_2 = V_1 -> V_2 ;
struct V_228 * V_4 = NULL ;
struct V_259 * V_232 = (struct V_259 * ) V_230 ;
T_2 V_260 = F_115 ( V_232 -> V_261 ) ;
int V_237 , V_236 , V_262 , V_263 ;
V_237 = F_116 ( V_2 , V_230 , & V_4 ) ;
if ( V_237 < 0 )
return V_237 ;
else if ( ! V_4 )
return 0 ;
if ( ! V_4 -> V_242 ) {
F_3 ( L_49 ) ;
F_117 () ;
return - 1 ;
}
F_33 ( L_50
L_51 ,
V_260 , V_4 -> V_251 ,
V_4 -> V_3 . V_243 ) ;
V_262 = V_4 -> V_251 / V_247 ;
V_258 = & V_4 -> V_3 . V_248 [ V_262 ] ;
V_236 = F_106 ( 1UL , F_107 ( V_260 , V_247 ) ) ;
V_263 = V_4 -> V_251 % V_247 ;
if ( V_263 ) {
F_3 ( L_52 ) ;
F_117 () ;
return - 1 ;
}
F_33 ( L_53
L_54 , V_258 , V_262 ,
V_236 , & V_61 -> V_226 [ 0 ] , V_260 ) ;
F_108 ( V_258 , V_236 , & V_61 -> V_226 [ 0 ] ,
V_260 ) ;
V_237 = F_118 ( V_4 , V_232 , false ) ;
if ( V_237 < 0 )
return V_237 ;
V_237 = F_85 ( V_1 , V_61 ) ;
if ( V_237 ) {
F_3 ( L_55 , V_237 ) ;
return V_237 ;
}
return 0 ;
}
static int
F_119 ( struct V_1 * V_1 , struct V_175 * V_175 ,
struct V_228 * V_4 , struct V_60 * V_61 ,
unsigned char * V_230 )
{
struct V_187 * V_2 = V_1 -> V_2 ;
struct V_264 * V_232 = (struct V_264 * ) V_230 ;
int V_237 ;
V_237 = F_120 ( V_2 , V_4 , V_232 ) ;
if ( V_237 < 0 )
return V_237 ;
return F_121 ( V_2 , V_4 , V_232 ) ;
}
static int
F_122 ( struct V_1 * V_1 , struct V_175 * V_175 ,
struct V_228 * V_4 , struct V_60 * V_61 ,
struct V_265 * V_232 )
{
struct V_187 * V_2 = V_1 -> V_2 ;
T_2 V_266 = F_115 ( V_232 -> V_261 ) ;
int V_237 ;
unsigned char * V_267 = NULL ;
V_237 = F_123 ( V_2 , V_4 , V_232 ) ;
if ( V_237 < 0 )
return V_237 ;
if ( V_266 ) {
V_267 = F_19 ( V_266 , V_67 ) ;
if ( ! V_267 ) {
F_3 ( L_56 ,
V_266 ) ;
return - V_79 ;
}
}
V_4 -> V_268 = V_267 ;
memcpy ( V_4 -> V_268 , & V_61 -> V_226 [ 0 ] , V_266 ) ;
return F_124 ( V_2 , V_4 , V_232 ) ;
}
static int
F_125 ( struct V_1 * V_1 , struct V_60 * V_61 ,
T_3 V_269 , T_4 V_270 ,
T_3 V_271 , T_4 V_272 )
{
struct V_193 * V_232 = & V_61 -> V_191 ;
struct V_187 * V_2 = V_1 -> V_2 ;
struct V_228 * V_4 ;
struct V_175 * V_175 ;
int V_30 = - V_90 ;
V_116 V_171 = ( V_232 -> V_171 & V_273 ) ;
if ( V_2 -> V_274 -> V_275 -> V_276 &&
( ! ( V_171 & V_277 ) || ! ( V_171 & V_278 ) ) ) {
F_3 ( L_57
L_58 , V_171 ) ;
return 0 ;
}
switch ( V_171 ) {
case V_279 :
V_4 = F_100 ( V_2 , V_61 ) ;
if ( ! V_4 )
break;
V_175 = F_102 ( V_4 ) ;
V_175 -> V_269 = V_269 ;
V_175 -> V_270 = V_270 ;
V_175 -> V_271 = V_271 ;
V_175 -> V_272 = V_272 ;
V_175 -> V_180 = V_269 ? V_269 : V_271 ;
V_30 = F_103 ( V_1 , V_175 , V_4 ,
V_61 , ( unsigned char * ) V_232 ) ;
break;
case V_280 :
V_4 = F_100 ( V_2 , V_61 ) ;
if ( ! V_4 )
break;
V_175 = F_102 ( V_4 ) ;
V_30 = F_119 ( V_1 , V_175 , V_4 ,
V_61 , ( unsigned char * ) V_232 ) ;
break;
case V_281 :
V_30 = F_114 ( V_1 , V_61 ,
( unsigned char * ) V_232 ) ;
break;
case V_282 :
V_4 = F_100 ( V_2 , V_61 ) ;
if ( ! V_4 )
break;
V_30 = F_126 ( V_2 , V_4 ,
( unsigned char * ) V_232 ) ;
break;
case V_278 :
V_4 = F_100 ( V_2 , V_61 ) ;
if ( ! V_4 )
break;
V_30 = F_127 ( V_2 , V_4 , ( unsigned char * ) V_232 ) ;
break;
case V_277 :
if ( F_96 ( V_232 -> V_283 ) != 0xFFFFFFFF )
V_4 = F_128 ( V_2 , V_232 -> V_218 ) ;
else
V_4 = F_100 ( V_2 , V_61 ) ;
if ( ! V_4 )
break;
V_175 = F_102 ( V_4 ) ;
V_30 = F_122 ( V_1 , V_175 , V_4 ,
V_61 , (struct V_265 * ) V_232 ) ;
break;
default:
F_3 ( L_59 , V_171 ) ;
F_117 () ;
break;
}
return V_30 ;
}
static void
F_129 ( struct V_284 * V_285 , const char * type )
{
if ( V_285 -> V_146 != V_286 )
F_3 ( L_60 , type ,
F_130 ( V_285 -> V_146 ) , V_285 -> V_146 ,
V_285 -> V_287 ) ;
else
F_33 ( L_61 , type ,
F_130 ( V_285 -> V_146 ) , V_285 -> V_146 ) ;
}
static void
V_78 ( struct V_288 * V_34 , struct V_284 * V_285 )
{
struct V_1 * V_1 = V_285 -> V_57 -> V_32 ;
struct V_44 * V_59 = V_1 -> V_13 -> V_17 ;
struct V_60 * V_61 = F_131 ( V_285 -> V_158 ) ;
struct V_193 * V_232 = & V_61 -> V_191 ;
struct V_177 * V_177 = & V_61 -> V_176 ;
T_4 V_270 = 0 , V_272 = 0 ;
T_3 V_269 = 0 , V_271 = 0 ;
if ( F_132 ( V_285 -> V_146 != V_289 ) ) {
F_129 ( V_285 , L_62 ) ;
if ( V_285 -> V_146 != V_286 )
F_80 ( V_1 -> V_2 , 0 ) ;
return;
}
F_90 ( V_59 , V_61 -> V_64 ,
V_69 , V_70 ) ;
F_33 ( L_63 ,
V_61 -> V_64 , V_232 -> V_171 , V_232 -> V_218 , V_232 -> V_119 ,
( int ) ( V_285 -> V_290 - V_167 ) ) ;
switch ( V_177 -> V_119 & 0xF0 ) {
case V_178 :
if ( V_177 -> V_119 & V_291 ) {
V_269 = F_96 ( V_177 -> V_269 ) ;
V_270 = F_133 ( V_177 -> V_270 ) ;
F_33 ( L_64 ,
V_269 , ( unsigned long long ) V_270 ) ;
}
if ( V_177 -> V_119 & V_292 ) {
V_271 = F_96 ( V_177 -> V_271 ) ;
V_272 = F_133 ( V_177 -> V_272 ) ;
F_33 ( L_65 ,
V_271 , ( unsigned long long ) V_272 ) ;
}
F_33 ( L_66 ) ;
break;
case V_293 :
F_3 ( L_67 ) ;
break;
default:
F_6 ( L_68 , V_177 -> V_119 ) ;
break;
}
F_125 ( V_1 , V_61 ,
V_269 , V_270 , V_271 , V_272 ) ;
F_87 ( V_59 , V_61 -> V_64 ,
V_69 , V_70 ) ;
}
static void
V_186 ( struct V_288 * V_34 , struct V_284 * V_285 )
{
struct V_1 * V_1 = V_285 -> V_57 -> V_32 ;
struct V_44 * V_59 = V_1 -> V_13 -> V_17 ;
if ( F_132 ( V_285 -> V_146 != V_289 ) ) {
F_129 ( V_285 , L_69 ) ;
return;
}
F_90 ( V_59 , V_1 -> V_107 ,
V_69 , V_70 ) ;
V_1 -> V_200 = V_285 -> V_290 - V_167 ;
if ( V_1 -> V_2 ) {
struct V_188 * V_189 = V_1 -> V_2 -> V_201 ;
if ( V_189 && ! V_189 -> V_203 )
F_94 ( V_1 ) ;
}
F_8 ( & V_1 -> V_101 ) ;
F_98 ( & V_1 -> V_99 ) ;
F_9 ( & V_1 -> V_101 ) ;
F_87 ( V_59 , V_1 -> V_107 ,
V_69 , V_70 ) ;
}
static void
F_134 ( struct V_175 * V_4 , struct V_1 * V_2 )
{
struct V_3 * V_3 = & V_4 -> V_228 -> V_3 ;
enum V_294 V_295 = F_135 ( V_3 ) ;
if ( ! V_4 -> V_296 . V_297 )
return;
if ( F_1 ( V_2 , V_3 ) ) {
F_136 ( & V_4 -> V_296 , V_2 -> V_57 ,
V_2 -> V_13 -> V_298 , V_3 -> V_248 ,
V_3 -> V_250 , V_3 -> V_299 ,
V_3 -> V_300 , V_295 ) ;
} else {
F_137 ( & V_4 -> V_296 , V_2 -> V_57 , V_2 -> V_13 -> V_298 ,
V_3 -> V_248 , V_3 -> V_250 , V_295 ) ;
}
V_4 -> V_296 . V_297 = 0 ;
}
static void
F_138 ( struct V_175 * V_175 , bool V_301 )
{
struct V_228 * V_4 = V_175 -> V_228 ;
struct V_1 * V_1 = V_175 -> V_2 ;
struct V_187 * V_2 = V_1 -> V_2 ;
struct V_302 * V_232 ;
F_33 ( L_70 , V_175 ) ;
switch ( V_4 -> V_303 ) {
case V_279 :
F_52 ( & V_2 -> V_304 ) ;
if ( ! F_70 ( & V_4 -> V_305 ) )
F_71 ( & V_4 -> V_305 ) ;
F_53 ( & V_2 -> V_304 ) ;
if ( V_4 -> V_306 == V_105 ) {
F_139 ( V_4 ) ;
if ( V_301 &&
V_4 -> V_3 . V_307 == V_308 ) {
struct V_3 * V_3 = & V_4 -> V_3 ;
F_113 ( V_3 ) ;
}
}
F_134 ( V_175 , V_1 ) ;
F_140 ( & V_4 -> V_3 , 0 ) ;
break;
case V_282 :
F_52 ( & V_2 -> V_304 ) ;
if ( ! F_70 ( & V_4 -> V_305 ) )
F_71 ( & V_4 -> V_305 ) ;
F_53 ( & V_2 -> V_304 ) ;
F_140 ( & V_4 -> V_3 , 0 ) ;
break;
case V_309 :
case V_280 :
case V_277 :
V_232 = (struct V_302 * ) & V_175 -> V_163 . V_191 ;
if ( V_232 -> V_119 & V_310 )
break;
F_52 ( & V_2 -> V_304 ) ;
if ( ! F_70 ( & V_4 -> V_305 ) )
F_71 ( & V_4 -> V_305 ) ;
F_53 ( & V_2 -> V_304 ) ;
if ( V_4 -> V_3 . V_311 != NULL ) {
F_33 ( L_71 ,
V_4 -> V_303 ) ;
F_140 ( & V_4 -> V_3 , 0 ) ;
break;
}
default:
F_141 ( V_4 ) ;
break;
}
}
static void
F_142 ( struct V_162 * V_163 , struct V_44 * V_59 )
{
if ( V_163 -> V_64 != 0 ) {
F_33 ( L_72 ) ;
F_22 ( V_59 , V_163 -> V_64 ,
V_167 , V_105 ) ;
V_163 -> V_64 = 0 ;
}
}
static void
F_143 ( struct V_162 * V_163 , struct V_175 * V_175 ,
struct V_44 * V_59 , bool V_301 )
{
if ( V_175 -> V_312 != 0 ) {
F_33 ( L_73 ) ;
F_22 ( V_59 , V_175 -> V_312 ,
V_175 -> V_313 , V_105 ) ;
V_175 -> V_312 = 0 ;
}
F_142 ( V_163 , V_59 ) ;
F_138 ( V_175 , V_301 ) ;
}
static int
F_144 ( struct V_3 * V_3 , struct V_314 * V_315 )
{
struct V_316 V_317 ;
int V_30 ;
V_30 = F_145 ( V_315 , V_318 , & V_317 ) ;
if ( V_30 ) {
F_3 ( L_74 , V_30 ) ;
goto V_319;
}
if ( V_317 . V_320 & V_318 ) {
T_1 V_321 ;
T_2 V_322 = V_3 -> V_323 -> V_324 . V_322 + 8 ;
switch ( V_317 . V_325 . V_326 ) {
case V_327 :
V_3 -> V_328 = V_329 ;
break;
case V_330 :
V_3 -> V_328 = V_331 ;
break;
case V_332 :
V_3 -> V_328 = V_333 ;
break;
}
V_321 = V_317 . V_325 . V_334 ;
F_146 ( V_321 , V_322 ) ;
V_3 -> V_335 = V_321 + V_3 -> V_336 ;
F_3 ( L_75
L_76 ,
V_317 . V_325 . V_326 ,
( unsigned long long ) V_3 -> V_335 ,
V_317 . V_325 . V_337 ,
V_317 . V_325 . V_338 ) ;
V_30 = 1 ;
}
V_319:
return V_30 ;
}
static void
F_147 ( struct V_288 * V_34 , struct V_284 * V_285 )
{
struct V_1 * V_1 = V_285 -> V_57 -> V_32 ;
struct V_16 * V_17 = V_1 -> V_17 ;
struct V_162 * V_339 = F_148 ( V_285 -> V_158 ) ;
struct V_175 * V_175 = F_149 ( V_339 ) ;
struct V_3 * V_4 = & V_175 -> V_228 -> V_3 ;
int V_30 = 0 ;
if ( F_132 ( V_285 -> V_146 != V_289 ) ) {
F_129 ( V_285 , L_77 ) ;
if ( V_285 -> V_146 != V_286 )
F_80 ( V_1 -> V_2 , 0 ) ;
F_143 ( V_339 , V_175 , V_17 -> V_44 , true ) ;
return;
}
F_33 ( L_70 , V_175 ) ;
V_30 = F_144 ( V_4 , V_175 -> V_296 . V_340 -> V_315 ) ;
F_134 ( V_175 , V_1 ) ;
if ( V_30 )
F_150 ( V_4 , V_4 -> V_328 , 0 ) ;
else
F_151 ( V_1 -> V_2 , V_175 -> V_228 ) ;
}
static void
F_152 ( struct V_288 * V_34 , struct V_284 * V_285 )
{
struct V_1 * V_1 = V_285 -> V_57 -> V_32 ;
struct V_16 * V_17 = V_1 -> V_17 ;
struct V_162 * V_339 = F_148 ( V_285 -> V_158 ) ;
struct V_175 * V_175 = F_149 ( V_339 ) ;
struct V_228 * V_4 = V_175 -> V_228 ;
struct V_3 * V_3 = & V_4 -> V_3 ;
int V_30 = 0 ;
if ( F_132 ( V_285 -> V_146 != V_289 ) ) {
F_129 ( V_285 , L_78 ) ;
if ( V_285 -> V_146 != V_286 )
F_80 ( V_1 -> V_2 , 0 ) ;
F_143 ( V_339 , V_175 , V_17 -> V_44 , true ) ;
return;
}
F_33 ( L_70 , V_175 ) ;
F_139 ( V_4 ) ;
if ( F_1 ( V_1 , V_3 ) )
V_30 = F_144 ( V_3 , V_175 -> V_296 . V_340 -> V_315 ) ;
F_134 ( V_175 , V_1 ) ;
V_4 -> V_251 = 0 ;
F_33 ( L_79 , V_175 ) ;
F_52 ( & V_4 -> V_252 ) ;
V_4 -> V_253 |= V_254 ;
V_4 -> V_255 = V_256 ;
F_53 ( & V_4 -> V_252 ) ;
if ( V_30 ) {
F_113 ( V_3 ) ;
F_150 ( V_3 ,
V_3 -> V_328 , 0 ) ;
} else {
F_153 ( V_3 ) ;
}
}
static void
F_154 ( struct V_341 * V_342 )
{
struct V_175 * V_175 = F_66 ( V_342 ,
struct V_175 , V_343 ) ;
struct V_1 * V_1 = V_175 -> V_2 ;
struct V_44 * V_59 = V_1 -> V_13 -> V_17 ;
struct V_228 * V_4 = V_175 -> V_228 ;
F_33 ( L_80 , V_175 , V_4 -> V_255 ) ;
switch ( V_4 -> V_255 ) {
case V_344 :
F_155 ( V_4 , V_4 -> V_2 ) ;
case V_345 :
case V_346 :
V_4 -> V_255 = V_347 ;
F_143 ( & V_175 -> V_163 , V_175 ,
V_59 , false ) ;
break;
case V_348 :
F_156 ( V_4 , V_4 -> V_2 ) ;
break;
default:
F_3 ( L_81 , V_4 -> V_255 ) ;
F_117 () ;
break;
}
}
static void
V_169 ( struct V_288 * V_34 , struct V_284 * V_285 )
{
struct V_1 * V_1 = V_285 -> V_57 -> V_32 ;
struct V_44 * V_59 = V_1 -> V_13 -> V_17 ;
struct V_162 * V_163 = F_148 ( V_285 -> V_158 ) ;
if ( F_132 ( V_285 -> V_146 != V_289 ) ) {
F_129 ( V_285 , L_82 ) ;
if ( V_285 -> V_146 != V_286 )
F_80 ( V_1 -> V_2 , 0 ) ;
}
F_142 ( V_163 , V_59 ) ;
}
static void
V_179 ( struct V_288 * V_34 , struct V_284 * V_285 )
{
struct V_1 * V_1 = V_285 -> V_57 -> V_32 ;
struct V_44 * V_59 = V_1 -> V_13 -> V_17 ;
struct V_162 * V_163 = F_148 ( V_285 -> V_158 ) ;
struct V_175 * V_175 = F_149 ( V_163 ) ;
if ( F_132 ( V_285 -> V_146 != V_289 ) ) {
F_129 ( V_285 , L_83 ) ;
if ( V_285 -> V_146 != V_286 )
F_80 ( V_1 -> V_2 , 0 ) ;
F_143 ( V_163 , V_175 , V_59 , true ) ;
return;
}
F_33 ( L_70 , V_175 ) ;
switch ( V_175 -> V_228 -> V_255 ) {
case V_344 :
case V_348 :
case V_345 :
case V_346 :
F_142 ( V_163 , V_59 ) ;
F_47 ( & V_175 -> V_343 , F_154 ) ;
F_72 ( V_349 , & V_175 -> V_343 ) ;
return;
default:
V_175 -> V_228 -> V_255 = V_347 ;
F_143 ( V_163 , V_175 , V_59 , false ) ;
break;
}
}
static int
F_157 ( struct V_1 * V_1 , struct V_175 * V_175 )
{
struct V_164 * V_350 ;
int V_30 ;
V_30 = F_85 ( V_1 , V_175 -> V_61 ) ;
if ( V_30 ) {
F_3 ( L_55 , V_30 ) ;
return V_30 ;
}
V_30 = F_88 ( V_1 -> V_57 , & V_175 -> V_163 . V_165 ,
& V_350 ) ;
if ( V_30 ) {
F_3 ( L_84 , V_30 ) ;
return V_30 ;
}
return V_30 ;
}
static int
F_151 ( struct V_187 * V_2 , struct V_228 * V_4 )
{
struct V_175 * V_175 = F_102 ( V_4 ) ;
struct V_1 * V_1 = V_2 -> V_10 ;
struct V_164 * V_165 = & V_175 -> V_163 . V_165 ;
struct V_351 * V_232 = (struct V_351 * )
& V_175 -> V_163 . V_191 ;
F_89 ( V_1 , V_175 , & V_175 -> V_163 ) ;
F_158 ( V_4 , V_2 , true , V_232 ) ;
F_91 ( V_1 , & V_175 -> V_163 ) ;
if ( V_4 -> V_3 . V_352 &&
( ( V_4 -> V_3 . V_244 & V_353 ) ||
( V_4 -> V_3 . V_244 & V_354 ) ) ) {
struct V_16 * V_17 = V_1 -> V_17 ;
struct V_44 * V_59 = V_17 -> V_44 ;
struct V_62 * V_194 = & V_175 -> V_163 . V_170 [ 1 ] ;
T_2 V_355 , V_356 ;
F_159 ( V_4 -> V_3 . V_357 ,
V_4 -> V_352 ) ;
V_4 -> V_3 . V_357 += sizeof( V_358 ) ;
V_355 = - ( V_4 -> V_3 . V_357 ) & 3 ;
F_160 ( V_232 -> V_261 , ( T_2 ) V_4 -> V_3 . V_357 ) ;
V_356 = V_4 -> V_3 . V_357 + V_355 ;
V_175 -> V_312 = F_20 ( V_59 ,
( void * ) V_4 -> V_352 , V_356 ,
V_105 ) ;
V_175 -> V_313 = V_356 ;
V_194 -> V_72 = V_175 -> V_312 ;
V_194 -> V_73 = V_356 ;
V_194 -> V_74 = V_17 -> V_56 -> V_75 ;
V_175 -> V_163 . V_160 = 2 ;
}
F_92 ( V_1 , V_175 , V_165 ) ;
F_33 ( L_85 ) ;
return F_157 ( V_1 , V_175 ) ;
}
static void
F_161 ( struct V_187 * V_2 , struct V_228 * V_4 )
{
struct V_175 * V_175 = F_102 ( V_4 ) ;
struct V_1 * V_1 = V_2 -> V_10 ;
F_52 ( & V_2 -> V_304 ) ;
if ( ! F_70 ( & V_4 -> V_305 ) )
F_71 ( & V_4 -> V_305 ) ;
F_53 ( & V_2 -> V_304 ) ;
if ( V_4 -> V_306 == V_105 )
F_139 ( V_4 ) ;
F_134 ( V_175 , V_1 ) ;
}
static enum V_359
F_162 ( struct V_187 * V_2 )
{
struct V_1 * V_1 = V_2 -> V_10 ;
struct V_16 * V_17 = V_1 -> V_17 ;
if ( V_2 -> V_360 -> V_361 . V_362 ) {
if ( V_17 -> V_53 ) {
F_10 ( L_86 , V_1 ) ;
V_1 -> V_5 = true ;
return V_363 ;
}
}
F_10 ( L_87 , V_1 ) ;
V_1 -> V_5 = false ;
return V_7 ;
}
static int
F_163 ( struct V_228 * V_4 , struct V_187 * V_2 ,
bool V_364 )
{
struct V_175 * V_175 = F_102 ( V_4 ) ;
struct V_1 * V_1 = V_2 -> V_10 ;
struct V_164 * V_165 = & V_175 -> V_163 . V_165 ;
F_89 ( V_1 , V_175 , & V_175 -> V_163 ) ;
F_164 ( V_4 , V_2 , (struct V_365 * )
& V_175 -> V_163 . V_191 ,
V_364 ) ;
F_91 ( V_1 , & V_175 -> V_163 ) ;
F_92 ( V_1 , V_175 , V_165 ) ;
F_33 ( L_88 , V_1 ) ;
return F_157 ( V_1 , V_175 ) ;
}
static int
F_165 ( struct V_228 * V_4 , struct V_187 * V_2 )
{
struct V_175 * V_175 = F_102 ( V_4 ) ;
struct V_1 * V_1 = V_2 -> V_10 ;
struct V_164 * V_165 = & V_175 -> V_163 . V_165 ;
F_89 ( V_1 , V_175 , & V_175 -> V_163 ) ;
F_166 ( V_4 , V_2 , (struct V_366 * )
& V_175 -> V_163 . V_191 ) ;
F_91 ( V_1 , & V_175 -> V_163 ) ;
F_92 ( V_1 , V_175 , V_165 ) ;
F_33 ( L_89 , V_1 ) ;
return F_157 ( V_1 , V_175 ) ;
}
static int
F_167 ( struct V_228 * V_4 , struct V_187 * V_2 )
{
struct V_175 * V_175 = F_102 ( V_4 ) ;
struct V_1 * V_1 = V_2 -> V_10 ;
struct V_164 * V_165 = & V_175 -> V_163 . V_165 ;
F_89 ( V_1 , V_175 , & V_175 -> V_163 ) ;
F_168 ( V_4 , V_2 , (struct V_367 * )
& V_175 -> V_163 . V_191 ) ;
F_91 ( V_1 , & V_175 -> V_163 ) ;
F_92 ( V_1 , V_175 , V_165 ) ;
F_33 ( L_90 , V_1 ) ;
return F_157 ( V_1 , V_175 ) ;
}
static int
F_169 ( struct V_228 * V_4 , struct V_187 * V_2 )
{
struct V_175 * V_175 = F_102 ( V_4 ) ;
struct V_1 * V_1 = V_2 -> V_10 ;
struct V_164 * V_165 = & V_175 -> V_163 . V_165 ;
struct V_16 * V_17 = V_1 -> V_17 ;
struct V_44 * V_59 = V_17 -> V_44 ;
struct V_62 * V_194 = & V_175 -> V_163 . V_170 [ 1 ] ;
struct V_368 * V_232 =
(struct V_368 * ) & V_175 -> V_163 . V_191 ;
F_89 ( V_1 , V_175 , & V_175 -> V_163 ) ;
F_170 ( V_4 , V_2 , V_232 ) ;
F_91 ( V_1 , & V_175 -> V_163 ) ;
F_160 ( V_232 -> V_261 , V_223 ) ;
V_175 -> V_312 = F_20 ( V_59 ,
( void * ) V_4 -> V_369 , V_223 ,
V_105 ) ;
V_175 -> V_313 = V_223 ;
V_194 -> V_72 = V_175 -> V_312 ;
V_194 -> V_73 = V_223 ;
V_194 -> V_74 = V_17 -> V_56 -> V_75 ;
V_175 -> V_163 . V_160 = 2 ;
F_92 ( V_1 , V_175 , V_165 ) ;
F_33 ( L_91 , V_1 ) ;
return F_157 ( V_1 , V_175 ) ;
}
static int
F_171 ( struct V_228 * V_4 , struct V_187 * V_2 )
{
struct V_175 * V_175 = F_102 ( V_4 ) ;
struct V_1 * V_1 = V_2 -> V_10 ;
struct V_164 * V_165 = & V_175 -> V_163 . V_165 ;
struct V_302 * V_232 =
(struct V_302 * ) & V_175 -> V_163 . V_191 ;
T_2 V_370 ;
int V_237 ;
F_89 ( V_1 , V_175 , & V_175 -> V_163 ) ;
V_237 = F_172 ( V_4 , V_2 , V_232 , V_371 ) ;
if ( V_237 < 0 )
return V_237 ;
V_370 = V_237 ;
F_91 ( V_1 , & V_175 -> V_163 ) ;
if ( V_370 ) {
struct V_16 * V_17 = V_1 -> V_17 ;
struct V_44 * V_59 = V_17 -> V_44 ;
struct V_62 * V_194 = & V_175 -> V_163 . V_170 [ 1 ] ;
void * V_372 = V_4 -> V_369 ;
V_175 -> V_312 = F_20 ( V_59 ,
V_372 , V_370 , V_105 ) ;
V_175 -> V_313 = V_370 ;
V_194 -> V_72 = V_175 -> V_312 ;
V_194 -> V_73 = V_370 ;
V_194 -> V_74 = V_17 -> V_56 -> V_75 ;
V_175 -> V_163 . V_160 = 2 ;
}
F_92 ( V_1 , V_175 , V_165 ) ;
F_33 ( L_92 , V_1 ) ;
return F_157 ( V_1 , V_175 ) ;
}
static inline void
F_173 ( struct V_3 * V_3 , struct V_373 * V_374 ,
struct V_375 * V_376 )
{
V_376 -> V_377 = V_378 ;
V_376 -> V_340 . V_379 . V_380 = V_381 ;
V_376 -> V_340 . V_379 . V_382 = V_3 -> V_323 -> V_324 . V_322 ;
V_376 -> V_340 . V_379 . V_383 = V_3 -> V_384 ;
V_376 -> V_340 . V_379 . V_385 = 0xffff ;
V_376 -> V_340 . V_379 . V_386 = true ;
V_376 -> V_340 . V_379 . V_387 = true ;
if ( V_3 -> V_388 == V_389 ||
V_3 -> V_388 == V_390 )
V_376 -> V_340 . V_379 . V_391 = true ;
}
static int
F_174 ( struct V_3 * V_3 , struct V_373 * V_374 )
{
memset ( V_374 , 0 , sizeof( * V_374 ) ) ;
switch ( V_3 -> V_6 ) {
case V_392 :
case V_393 :
V_374 -> V_394 . V_377 = V_395 ;
F_173 ( V_3 , V_374 , & V_374 -> V_396 ) ;
break;
case V_397 :
case V_398 :
V_374 -> V_396 . V_377 = V_395 ;
F_173 ( V_3 , V_374 , & V_374 -> V_394 ) ;
break;
case V_399 :
case V_400 :
F_173 ( V_3 , V_374 , & V_374 -> V_396 ) ;
F_173 ( V_3 , V_374 , & V_374 -> V_394 ) ;
break;
default:
F_3 ( L_93 , V_3 -> V_6 ) ;
return - V_90 ;
}
V_374 -> V_401 =
( V_3 -> V_402 & V_403 ? 0xc0 : 0 ) |
( V_3 -> V_402 & V_404 ? 0x30 : 0 ) |
( V_3 -> V_402 & V_404 ? 0x0f : 0 ) ;
return 0 ;
}
static int
F_175 ( struct V_175 * V_4 , struct V_1 * V_2 ,
struct V_405 * V_406 , struct V_164 * V_407 )
{
struct V_3 * V_3 = & V_4 -> V_228 -> V_3 ;
enum V_294 V_295 = F_135 ( V_3 ) ;
V_116 V_298 = V_2 -> V_13 -> V_298 ;
T_1 V_72 ;
T_2 V_408 , V_409 ;
int V_30 ;
if ( V_295 == V_70 ) {
V_72 = V_4 -> V_272 ;
V_408 = V_4 -> V_271 ;
V_409 = V_4 -> V_228 -> V_251 ;
} else {
V_72 = V_4 -> V_270 ;
V_408 = V_4 -> V_269 ;
V_409 = 0 ;
}
if ( F_1 ( V_2 , V_3 ) ) {
struct V_373 V_374 ;
V_30 = F_174 ( V_3 , & V_374 ) ;
if ( V_30 )
return V_30 ;
F_95 ( V_409 ) ;
V_30 = F_176 ( & V_4 -> V_296 , V_2 -> V_57 , V_298 ,
V_3 -> V_248 , V_3 -> V_250 ,
V_3 -> V_299 , V_3 -> V_300 ,
& V_374 , V_72 , V_408 , V_295 ) ;
} else {
V_30 = F_177 ( & V_4 -> V_296 , V_2 -> V_57 , V_298 ,
V_3 -> V_248 , V_3 -> V_250 ,
V_409 , V_72 , V_408 , V_295 ) ;
}
if ( V_30 < 0 ) {
F_3 ( L_94 , V_4 ) ;
return V_30 ;
}
V_30 = F_178 ( & V_4 -> V_296 , V_2 -> V_57 , V_298 , V_406 , V_407 ) ;
if ( V_30 < 0 )
F_3 ( L_95 , V_4 ) ;
return V_30 ;
}
static int
F_179 ( struct V_187 * V_2 , struct V_228 * V_4 )
{
struct V_3 * V_3 = & V_4 -> V_3 ;
struct V_175 * V_175 = F_102 ( V_4 ) ;
struct V_1 * V_1 = V_2 -> V_10 ;
struct V_405 * V_406 = NULL ;
struct V_164 * V_407 = NULL ;
int V_237 ;
F_33 ( L_96 ,
V_175 , V_3 -> V_243 ) ;
if ( F_1 ( V_1 , V_3 ) ) {
V_175 -> V_163 . V_168 . V_77 = F_147 ;
V_406 = & V_175 -> V_163 . V_168 ;
} else {
F_89 ( V_1 , V_175 ,
& V_175 -> V_163 ) ;
F_158 ( V_4 , V_2 , true , (struct V_351 * )
& V_175 -> V_163 . V_191 ) ;
F_91 ( V_1 , & V_175 -> V_163 ) ;
F_92 ( V_1 , V_175 ,
& V_175 -> V_163 . V_165 ) ;
V_237 = F_85 ( V_1 , V_175 -> V_61 ) ;
if ( V_237 ) {
F_3 ( L_55 , V_237 ) ;
return V_237 ;
}
V_407 = & V_175 -> V_163 . V_165 ;
}
F_175 ( V_175 , V_1 , V_406 , V_407 ) ;
F_33 ( L_97 , V_175 ) ;
return 1 ;
}
static int
F_180 ( struct V_187 * V_2 , struct V_228 * V_4 , bool V_410 )
{
struct V_175 * V_175 = F_102 ( V_4 ) ;
F_33 ( L_98 ,
V_175 , V_4 -> V_3 . V_243 , V_4 -> V_251 ) ;
V_175 -> V_163 . V_168 . V_77 = F_152 ;
F_175 ( V_175 , V_2 -> V_10 ,
& V_175 -> V_163 . V_168 , NULL ) ;
F_33 ( L_99 ,
V_175 ) ;
return 0 ;
}
static int
F_181 ( struct V_187 * V_2 , struct V_228 * V_4 , int V_95 )
{
struct V_175 * V_175 = F_102 ( V_4 ) ;
int V_30 = 0 ;
switch ( V_95 ) {
case V_411 :
F_52 ( & V_2 -> V_304 ) ;
F_71 ( & V_4 -> V_305 ) ;
F_53 ( & V_2 -> V_304 ) ;
F_138 ( V_175 , true ) ;
break;
case V_412 :
V_30 = F_163 ( V_4 , V_2 , false ) ;
break;
default:
F_3 ( L_100 , V_95 ) ;
V_30 = - V_90 ;
break;
}
return V_30 ;
}
static int
F_182 ( struct V_187 * V_2 , struct V_228 * V_4 , int V_95 )
{
struct V_1 * V_1 = V_2 -> V_10 ;
int V_30 ;
switch ( V_95 ) {
case V_348 :
V_30 = F_165 ( V_4 , V_2 ) ;
if ( ! V_30 )
V_1 -> V_413 = true ;
break;
case V_414 :
V_30 = F_163 ( V_4 , V_2 , true ) ;
break;
case V_344 :
V_30 = F_167 ( V_4 , V_2 ) ;
break;
case V_345 :
V_30 = F_169 ( V_4 , V_2 ) ;
break;
case V_346 :
V_30 = F_171 ( V_4 , V_2 ) ;
break;
case V_415 :
V_30 = F_151 ( V_2 , V_4 ) ;
break;
default:
F_3 ( L_101 , V_95 ) ;
V_30 = - V_90 ;
break;
}
return V_30 ;
}
struct V_26 *
F_77 ( struct V_124 * V_124 )
{
struct V_125 * V_126 = V_124 -> V_126 ;
struct V_26 * V_416 ;
struct V_417 * V_418 ;
int V_30 ;
V_418 = (struct V_417 * ) & V_126 -> V_419 ;
F_33 ( L_102 , & V_126 -> V_419 , V_418 ) ;
V_416 = F_183 ( & V_420 , F_82 , V_124 ,
V_421 , V_52 ) ;
if ( F_16 ( V_416 ) ) {
F_3 ( L_103 , F_17 ( V_416 ) ) ;
V_30 = F_17 ( V_416 ) ;
goto V_87;
}
F_33 ( L_104 , V_416 , V_416 -> V_10 ) ;
V_30 = F_184 ( V_416 , V_418 ) ;
if ( V_30 ) {
F_3 ( L_105 , V_30 ) ;
goto V_422;
}
V_30 = F_185 ( V_416 , 0 ) ;
if ( V_30 ) {
F_3 ( L_106 , V_30 ) ;
goto V_422;
}
return V_416 ;
V_422:
F_59 ( V_416 ) ;
V_87:
return F_14 ( V_30 ) ;
}
static int
F_186 ( struct V_125 * V_126 ,
struct V_423 * V_424 )
{
struct V_124 * V_124 ;
struct V_26 * V_425 ;
int V_30 ;
V_124 = F_19 ( sizeof( struct V_124 ) , V_67 ) ;
if ( ! V_124 ) {
F_3 ( L_107 ) ;
return - V_79 ;
}
F_187 ( & V_124 -> V_135 , 0 ) ;
F_46 ( & V_124 -> V_101 ) ;
F_41 ( & V_124 -> V_131 ) ;
F_41 ( & V_124 -> V_134 ) ;
V_124 -> V_126 = V_126 ;
memcpy ( & V_126 -> V_419 , V_424 ,
sizeof( struct V_423 ) ) ;
V_425 = F_77 ( V_124 ) ;
if ( F_16 ( V_425 ) ) {
V_30 = F_17 ( V_425 ) ;
goto V_87;
}
V_124 -> V_13 = V_425 ;
V_126 -> V_426 = V_124 ;
return 0 ;
V_87:
F_23 ( V_124 ) ;
return V_30 ;
}
static int
F_56 ( struct V_1 * V_1 )
{
struct V_26 * V_13 = V_1 -> V_13 ;
struct V_112 V_427 ;
int V_30 ;
struct V_428 V_429 ;
memset ( & V_427 , 0 , sizeof( struct V_112 ) ) ;
V_427 . V_115 = V_1 -> V_115 ;
V_427 . V_430 = 7 ;
V_427 . V_431 = 7 ;
memset ( & V_429 , 0 , sizeof( V_429 ) ) ;
V_429 . V_119 = V_432 ;
if ( ! V_1 -> V_120 )
V_429 . V_119 = V_429 . V_119 | V_433 ;
V_427 . V_118 = ( void * ) & V_429 ;
V_427 . V_434 = sizeof( V_429 ) ;
V_30 = F_188 ( V_13 , & V_427 ) ;
if ( V_30 ) {
F_3 ( L_108 , V_30 ) ;
return V_30 ;
}
return 0 ;
}
static int
F_189 ( struct V_187 * V_2 , struct V_188 * V_189 )
{
struct V_1 * V_1 = V_2 -> V_10 ;
int V_30 ;
F_10 ( L_109 , V_1 ) ;
V_30 = F_190 ( & V_1 -> V_99 ) ;
if ( V_30 ) {
F_3 ( L_110 ,
V_1 ) ;
return V_30 ;
}
F_191 ( & V_1 -> V_99 ) ;
if ( ! V_189 -> V_203 )
return 0 ;
F_94 ( V_1 ) ;
F_10 ( L_111 , V_2 ) ;
V_30 = F_190 ( & V_1 -> V_98 ) ;
if ( V_30 )
return V_30 ;
F_10 ( L_112 , V_189 -> V_222 ) ;
return 0 ;
}
static void
F_192 ( struct V_125 * V_126 , struct V_187 * V_2 ,
struct V_1 * V_1 )
{
struct V_26 * V_13 = V_1 -> V_13 ;
struct V_435 * V_436 = & V_13 -> V_437 ;
V_2 -> V_438 = V_126 -> V_419 . V_439 ;
V_2 -> V_440 = V_436 -> V_72 . V_441 ;
V_2 -> V_442 = V_436 -> V_72 . V_443 ;
}
static int
F_193 ( struct V_125 * V_126 , struct V_187 * V_2 )
{
struct V_124 * V_124 = V_126 -> V_426 ;
struct V_1 * V_1 ;
int V_30 ;
V_444:
V_30 = F_194 ( & V_124 -> V_135 ) ;
if ( V_30 )
return - V_445 ;
F_52 ( & V_126 -> V_127 ) ;
if ( V_126 -> V_446 >= V_447 ) {
F_53 ( & V_126 -> V_127 ) ;
F_33 ( L_113 ,
V_126 -> V_446 ) ;
return - V_445 ;
}
F_53 ( & V_126 -> V_127 ) ;
F_8 ( & V_124 -> V_101 ) ;
if ( F_70 ( & V_124 -> V_134 ) ) {
F_9 ( & V_124 -> V_101 ) ;
goto V_444;
}
V_1 = F_195 ( & V_124 -> V_134 ,
struct V_1 , V_97 ) ;
F_71 ( & V_1 -> V_97 ) ;
F_9 ( & V_124 -> V_101 ) ;
V_2 -> V_10 = V_1 ;
V_1 -> V_2 = V_2 ;
V_1 -> V_95 = V_144 ;
F_192 ( V_126 , V_2 , V_1 ) ;
F_33 ( L_114 , V_1 ) ;
return 0 ;
}
static void
F_196 ( struct V_125 * V_126 )
{
struct V_124 * V_124 = V_126 -> V_426 ;
struct V_1 * V_1 , * V_448 ;
if ( V_124 -> V_13 )
F_59 ( V_124 -> V_13 ) ;
F_8 ( & V_124 -> V_101 ) ;
if ( ! F_70 ( & V_124 -> V_134 ) ) {
F_10 ( L_115 ) ;
F_197 (isert_conn, n,
&isert_np->pending,
node) {
F_10 ( L_116 ,
V_1 , V_1 -> V_95 ) ;
F_57 ( V_1 ) ;
}
}
if ( ! F_70 ( & V_124 -> V_131 ) ) {
F_10 ( L_117 ) ;
F_197 (isert_conn, n,
&isert_np->accepted,
node) {
F_10 ( L_116 ,
V_1 , V_1 -> V_95 ) ;
F_57 ( V_1 ) ;
}
}
F_9 ( & V_124 -> V_101 ) ;
V_126 -> V_426 = NULL ;
F_23 ( V_124 ) ;
}
static void V_103 ( struct V_341 * V_342 )
{
struct V_1 * V_1 = F_66 ( V_342 ,
struct V_1 ,
V_102 ) ;
F_10 ( L_118 , V_1 ) ;
F_8 ( & V_1 -> V_101 ) ;
V_1 -> V_95 = V_449 ;
F_9 ( & V_1 -> V_101 ) ;
F_10 ( L_119 , V_1 ) ;
F_67 ( V_1 ) ;
}
static void
F_198 ( struct V_1 * V_1 )
{
struct V_187 * V_2 = V_1 -> V_2 ;
F_10 ( L_25 , V_1 ) ;
if ( V_1 -> V_413 ) {
F_10 ( L_120 , V_1 ) ;
F_199 ( & V_2 -> V_450 ,
V_451 * V_452 ) ;
}
}
static void
F_200 ( struct V_187 * V_2 )
{
F_10 ( L_121 , V_2 ) ;
if ( V_2 -> V_274 ) {
F_201 ( V_2 -> V_274 -> V_453 ) ;
F_202 ( V_2 -> V_274 -> V_453 ) ;
}
}
static void
F_203 ( struct V_187 * V_2 )
{
struct V_228 * V_4 , * V_454 ;
static F_204 ( V_455 ) ;
F_52 ( & V_2 -> V_304 ) ;
F_197 (cmd, tmp, &conn->conn_cmd_list, i_conn_node) {
if ( ( V_4 -> V_253 & V_456 ) &&
( V_4 -> V_251 < V_2 -> V_274 -> V_275 -> V_457 ) &&
( V_4 -> V_251 < V_4 -> V_3 . V_243 ) )
F_63 ( & V_4 -> V_305 , & V_455 ) ;
}
F_53 ( & V_2 -> V_304 ) ;
F_197 (cmd, tmp, &drop_cmd_list, i_conn_node) {
F_71 ( & V_4 -> V_305 ) ;
if ( V_4 -> V_255 != V_411 ) {
struct V_175 * V_175 = F_102 ( V_4 ) ;
F_10 ( L_122 , V_2 , V_4 ) ;
F_138 ( V_175 , true ) ;
}
}
}
static void F_205 ( struct V_187 * V_2 )
{
struct V_1 * V_1 = V_2 -> V_10 ;
F_10 ( L_123 , V_1 ) ;
F_8 ( & V_1 -> V_101 ) ;
F_73 ( V_1 ) ;
F_9 ( & V_1 -> V_101 ) ;
F_79 ( V_1 -> V_57 ) ;
F_203 ( V_2 ) ;
F_200 ( V_2 ) ;
F_198 ( V_1 ) ;
F_72 ( V_139 , & V_1 -> V_102 ) ;
}
static void F_206 ( struct V_187 * V_2 )
{
struct V_1 * V_1 = V_2 -> V_10 ;
F_79 ( V_1 -> V_57 ) ;
F_67 ( V_1 ) ;
}
static void F_207 ( struct V_187 * V_2 )
{
struct V_458 V_18 ;
F_44 ( & V_18 ) ;
F_190 ( & V_18 ) ;
}
static int T_5 F_208 ( void )
{
int V_30 ;
V_349 = F_209 ( L_124 ,
V_459 | V_460 , 0 ) ;
if ( ! V_349 ) {
F_3 ( L_125 ) ;
V_30 = - V_79 ;
return - V_79 ;
}
V_139 = F_209 ( L_126 , V_459 ,
V_461 ) ;
if ( ! V_139 ) {
F_3 ( L_127 ) ;
V_30 = - V_79 ;
goto V_462;
}
F_210 ( & V_463 ) ;
F_10 ( L_128 ) ;
return 0 ;
V_462:
F_211 ( V_349 ) ;
return V_30 ;
}
static void T_6 F_212 ( void )
{
F_213 () ;
F_211 ( V_139 ) ;
F_211 ( V_349 ) ;
F_214 ( & V_463 ) ;
F_10 ( L_129 ) ;
}
