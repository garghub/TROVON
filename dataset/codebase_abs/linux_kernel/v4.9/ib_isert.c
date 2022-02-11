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
goto V_67;
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
V_67:
F_3 ( L_5 , V_1 ) ;
return - V_78 ;
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
int V_19 , V_79 , V_30 = 0 ;
V_17 -> V_22 = V_20 ( V_80 , F_28 ( int , F_29 () ,
V_17 -> V_44 -> V_81 ) ) ;
F_10 ( L_6
L_7 ,
V_17 -> V_22 , V_17 -> V_44 -> V_82 ,
V_17 -> V_44 -> V_81 ,
V_17 -> V_52 ) ;
V_17 -> V_23 = F_30 ( V_17 -> V_22 , sizeof( struct V_15 ) ,
V_66 ) ;
if ( ! V_17 -> V_23 ) {
F_3 ( L_8 ) ;
return - V_78 ;
}
V_79 = V_20 ( V_83 , V_17 -> V_44 -> V_45 . V_79 ) ;
for ( V_19 = 0 ; V_19 < V_17 -> V_22 ; V_19 ++ ) {
struct V_15 * V_18 = & V_17 -> V_23 [ V_19 ] ;
V_18 -> V_17 = V_17 ;
V_18 -> V_34 = F_31 ( V_17 -> V_44 , V_18 , V_79 , V_19 ,
V_84 ) ;
if ( F_16 ( V_18 -> V_34 ) ) {
F_3 ( L_9 ) ;
V_30 = F_17 ( V_18 -> V_34 ) ;
V_18 -> V_34 = NULL ;
goto V_85;
}
}
return 0 ;
V_85:
F_25 ( V_17 ) ;
return V_30 ;
}
static int
F_32 ( struct V_16 * V_17 )
{
struct V_44 * V_58 = V_17 -> V_44 ;
int V_30 ;
F_33 ( L_10 , V_58 -> V_45 . V_46 ) ;
F_33 ( L_11 , V_58 -> V_45 . V_86 ) ;
V_30 = F_27 ( V_17 ) ;
if ( V_30 )
goto V_87;
V_17 -> V_55 = F_34 ( V_58 , 0 ) ;
if ( F_16 ( V_17 -> V_55 ) ) {
V_30 = F_17 ( V_17 -> V_55 ) ;
F_3 ( L_12 ,
V_17 , V_30 ) ;
goto V_85;
}
V_17 -> V_52 = V_58 -> V_45 . V_88 &
V_89 ? true : false ;
return 0 ;
V_85:
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
F_36 ( V_17 -> V_55 ) ;
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
V_17 = F_19 ( sizeof( struct V_16 ) , V_66 ) ;
if ( ! V_17 ) {
F_9 ( & V_21 ) ;
return F_14 ( - V_78 ) ;
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
F_47 ( & V_1 -> V_102 ) ;
F_48 ( & V_1 -> V_103 , V_104 ) ;
}
static void
F_49 ( struct V_1 * V_1 )
{
struct V_44 * V_58 = V_1 -> V_17 -> V_44 ;
F_22 ( V_58 , V_1 -> V_105 ,
V_68 , V_106 ) ;
F_23 ( V_1 -> V_107 ) ;
F_22 ( V_58 , V_1 -> V_108 ,
V_68 ,
V_69 ) ;
F_23 ( V_1 -> V_109 ) ;
}
static int
F_50 ( struct V_1 * V_1 ,
struct V_44 * V_58 )
{
int V_30 ;
V_1 -> V_109 = F_19 ( sizeof( * V_1 -> V_109 ) ,
V_66 ) ;
if ( ! V_1 -> V_109 ) {
F_3 ( L_17 ) ;
return - V_78 ;
}
V_1 -> V_108 = F_20 ( V_58 ,
V_1 -> V_109 ,
V_68 , V_69 ) ;
V_30 = F_21 ( V_58 , V_1 -> V_108 ) ;
if ( V_30 ) {
F_3 ( L_18 , V_30 ) ;
V_1 -> V_108 = 0 ;
goto V_110;
}
V_1 -> V_107 = F_19 ( V_68 , V_66 ) ;
if ( ! V_1 -> V_107 ) {
V_30 = - V_78 ;
goto V_111;
}
V_1 -> V_105 = F_20 ( V_58 ,
V_1 -> V_107 ,
V_68 , V_106 ) ;
V_30 = F_21 ( V_58 , V_1 -> V_105 ) ;
if ( V_30 ) {
F_3 ( L_19 , V_30 ) ;
V_1 -> V_105 = 0 ;
goto V_112;
}
return 0 ;
V_112:
F_23 ( V_1 -> V_107 ) ;
V_111:
F_22 ( V_58 , V_1 -> V_108 ,
V_68 , V_69 ) ;
V_110:
F_23 ( V_1 -> V_109 ) ;
return V_30 ;
}
static void
F_51 ( struct V_1 * V_1 ,
struct V_113 * V_114 )
{
struct V_115 * V_29 = & V_1 -> V_17 -> V_44 -> V_45 ;
V_1 -> V_116 = F_28 ( V_117 , V_114 -> V_116 ,
V_29 -> V_118 ) ;
F_33 ( L_20 , V_1 -> V_116 ) ;
if ( V_114 -> V_119 ) {
V_117 V_120 = * ( V_117 * ) V_114 -> V_119 ;
V_1 -> V_121 = ! ( V_120 & V_122 ) &&
( V_29 -> V_88 &
V_123 ) ;
if ( V_1 -> V_121 )
F_10 ( L_21 ) ;
}
}
static int
F_52 ( struct V_26 * V_27 , struct V_124 * V_11 )
{
struct V_125 * V_125 = V_27 -> V_10 ;
struct V_126 * V_127 = V_125 -> V_127 ;
struct V_1 * V_1 ;
struct V_16 * V_17 ;
int V_30 = 0 ;
F_53 ( & V_127 -> V_128 ) ;
if ( ! V_127 -> V_129 ) {
F_54 ( & V_127 -> V_128 ) ;
F_33 ( L_22 ) ;
return F_55 ( V_27 , NULL , 0 ) ;
}
F_54 ( & V_127 -> V_128 ) ;
F_33 ( L_23 ,
V_27 , V_27 -> V_10 ) ;
V_1 = F_19 ( sizeof( struct V_1 ) , V_66 ) ;
if ( ! V_1 )
return - V_78 ;
F_43 ( V_1 ) ;
V_1 -> V_13 = V_27 ;
V_30 = F_50 ( V_1 , V_27 -> V_17 ) ;
if ( V_30 )
goto V_87;
V_17 = F_39 ( V_27 ) ;
if ( F_16 ( V_17 ) ) {
V_30 = F_17 ( V_17 ) ;
goto V_130;
}
V_1 -> V_17 = V_17 ;
F_51 ( V_1 , & V_11 -> V_114 . V_2 ) ;
V_30 = F_15 ( V_1 , V_27 ) ;
if ( V_30 )
goto V_131;
V_30 = F_56 ( V_1 ) ;
if ( V_30 )
goto V_131;
V_30 = F_57 ( V_1 ) ;
if ( V_30 )
goto V_131;
F_8 ( & V_125 -> V_102 ) ;
F_42 ( & V_1 -> V_97 , & V_125 -> V_132 ) ;
F_9 ( & V_125 -> V_102 ) ;
return 0 ;
V_131:
F_37 ( V_17 ) ;
V_130:
F_49 ( V_1 ) ;
V_87:
F_23 ( V_1 ) ;
F_55 ( V_27 , NULL , 0 ) ;
return V_30 ;
}
static void
F_58 ( struct V_1 * V_1 )
{
struct V_16 * V_17 = V_1 -> V_17 ;
F_33 ( L_24 , V_1 ) ;
F_59 ( ! V_17 ) ;
F_24 ( V_1 ) ;
if ( V_1 -> V_13 &&
! V_1 -> V_133 )
F_60 ( V_1 -> V_13 ) ;
if ( V_1 -> V_56 ) {
struct V_15 * V_18 = V_1 -> V_56 -> V_35 -> V_134 ;
F_11 ( V_18 ) ;
F_61 ( V_1 -> V_56 ) ;
}
if ( V_1 -> V_109 )
F_49 ( V_1 ) ;
F_37 ( V_17 ) ;
if ( V_1 -> V_133 )
F_62 ( & V_1 -> V_100 ) ;
else
F_23 ( V_1 ) ;
}
static void
F_63 ( struct V_26 * V_27 )
{
struct V_1 * V_1 = V_27 -> V_56 -> V_32 ;
struct V_125 * V_125 = V_27 -> V_10 ;
F_10 ( L_24 , V_1 ) ;
F_8 ( & V_1 -> V_102 ) ;
V_1 -> V_95 = V_135 ;
F_64 ( & V_1 -> V_101 ) ;
F_9 ( & V_1 -> V_102 ) ;
F_8 ( & V_125 -> V_102 ) ;
F_65 ( & V_1 -> V_97 , & V_125 -> V_136 ) ;
F_9 ( & V_125 -> V_102 ) ;
F_10 ( L_25 , V_125 ) ;
F_66 ( & V_125 -> V_137 ) ;
}
static void
F_67 ( struct V_101 * V_101 )
{
struct V_1 * V_1 = F_68 ( V_101 ,
struct V_1 , V_101 ) ;
F_10 ( L_26 , V_1 , V_138 -> V_139 ,
V_138 -> V_140 ) ;
F_58 ( V_1 ) ;
}
static void
F_69 ( struct V_1 * V_1 )
{
F_70 ( & V_1 -> V_101 , F_67 ) ;
}
static void
F_71 ( struct V_1 * V_1 )
{
struct V_125 * V_125 = V_1 -> V_13 -> V_10 ;
F_8 ( & V_125 -> V_102 ) ;
if ( ! F_72 ( & V_1 -> V_97 ) ) {
F_73 ( & V_1 -> V_97 ) ;
F_69 ( V_1 ) ;
F_74 ( V_141 , & V_1 -> V_103 ) ;
}
F_9 ( & V_125 -> V_102 ) ;
}
static void
F_75 ( struct V_1 * V_1 )
{
int V_57 ;
if ( V_1 -> V_95 >= V_142 )
return;
F_10 ( L_27 ,
V_1 , V_1 -> V_95 ) ;
V_1 -> V_95 = V_142 ;
V_57 = F_76 ( V_1 -> V_13 ) ;
if ( V_57 )
F_6 ( L_28 ,
V_1 ) ;
}
static int
F_77 ( struct V_125 * V_125 ,
enum V_143 V_11 )
{
F_33 ( L_29 ,
F_78 ( V_11 ) , V_11 , V_125 ) ;
switch ( V_11 ) {
case V_144 :
V_125 -> V_13 = NULL ;
break;
case V_145 :
V_125 -> V_13 = F_79 ( V_125 ) ;
if ( F_16 ( V_125 -> V_13 ) ) {
F_3 ( L_30 ,
V_125 , F_17 ( V_125 -> V_13 ) ) ;
V_125 -> V_13 = NULL ;
}
break;
default:
F_3 ( L_31 ,
V_125 , V_11 ) ;
}
return - 1 ;
}
static int
F_80 ( struct V_26 * V_27 ,
enum V_143 V_11 )
{
struct V_1 * V_1 = V_27 -> V_56 -> V_32 ;
F_8 ( & V_1 -> V_102 ) ;
switch ( V_1 -> V_95 ) {
case V_142 :
break;
case V_135 :
F_75 ( V_1 ) ;
F_81 ( V_1 -> V_56 ) ;
F_71 ( V_1 ) ;
break;
case V_146 :
case V_147 :
F_82 ( V_1 -> V_2 , 0 ) ;
break;
default:
F_6 ( L_32 ,
V_1 , V_1 -> V_95 ) ;
}
F_9 ( & V_1 -> V_102 ) ;
return 0 ;
}
static int
F_83 ( struct V_26 * V_27 )
{
struct V_1 * V_1 = V_27 -> V_56 -> V_32 ;
F_73 ( & V_1 -> V_97 ) ;
V_1 -> V_13 = NULL ;
F_69 ( V_1 ) ;
return - 1 ;
}
static int
F_84 ( struct V_26 * V_27 , struct V_124 * V_11 )
{
struct V_125 * V_125 = V_27 -> V_10 ;
struct V_1 * V_1 ;
int V_30 = 0 ;
F_10 ( L_33 ,
F_78 ( V_11 -> V_11 ) , V_11 -> V_11 ,
V_11 -> V_148 , V_27 , V_27 -> V_10 ) ;
if ( V_125 -> V_13 == V_27 )
return F_77 ( V_27 -> V_10 , V_11 -> V_11 ) ;
switch ( V_11 -> V_11 ) {
case V_149 :
V_30 = F_52 ( V_27 , V_11 ) ;
if ( V_30 )
F_3 ( L_34 , V_30 ) ;
break;
case V_150 :
F_63 ( V_27 ) ;
break;
case V_145 :
case V_151 :
case V_152 :
V_30 = F_80 ( V_27 , V_11 -> V_11 ) ;
break;
case V_144 :
V_1 = V_27 -> V_56 -> V_32 ;
V_1 -> V_133 = true ;
F_80 ( V_27 , V_11 -> V_11 ) ;
F_85 ( V_1 -> V_100 ,
V_1 -> V_95 == V_153 ) ;
F_23 ( V_1 ) ;
return 1 ;
case V_154 :
case V_155 :
case V_156 :
V_30 = F_83 ( V_27 ) ;
break;
default:
F_3 ( L_35 , V_11 -> V_11 ) ;
break;
}
return V_30 ;
}
static int
F_86 ( struct V_1 * V_1 , T_2 V_157 )
{
struct V_158 * V_159 , * V_160 ;
int V_19 , V_30 ;
struct V_59 * V_60 ;
for ( V_159 = V_1 -> V_159 , V_19 = 0 ; V_19 < V_157 ; V_19 ++ , V_159 ++ ) {
V_60 = & V_1 -> V_65 [ V_19 ] ;
V_159 -> V_161 = & V_60 -> V_75 ;
V_159 -> V_162 = & V_60 -> V_62 ;
V_159 -> V_163 = 1 ;
V_159 -> V_164 = V_159 + 1 ;
}
V_159 -- ;
V_159 -> V_164 = NULL ;
V_30 = F_87 ( V_1 -> V_56 , V_1 -> V_159 ,
& V_160 ) ;
if ( V_30 )
F_3 ( L_36 , V_30 ) ;
return V_30 ;
}
static int
F_88 ( struct V_1 * V_1 , struct V_59 * V_60 )
{
struct V_158 * V_160 , V_159 ;
int V_30 ;
V_159 . V_161 = & V_60 -> V_75 ;
V_159 . V_162 = & V_60 -> V_62 ;
V_159 . V_163 = 1 ;
V_159 . V_164 = NULL ;
V_30 = F_87 ( V_1 -> V_56 , & V_159 , & V_160 ) ;
if ( V_30 )
F_3 ( L_36 , V_30 ) ;
return V_30 ;
}
static int
F_89 ( struct V_1 * V_1 , struct V_165 * V_166 )
{
struct V_44 * V_58 = V_1 -> V_13 -> V_17 ;
struct V_167 V_168 , * V_169 ;
int V_30 ;
F_90 ( V_58 , V_166 -> V_63 ,
V_170 , V_106 ) ;
V_166 -> V_171 . V_76 = V_172 ;
V_168 . V_164 = NULL ;
V_168 . V_161 = & V_166 -> V_171 ;
V_168 . V_162 = V_166 -> V_173 ;
V_168 . V_163 = V_166 -> V_163 ;
V_168 . V_174 = V_175 ;
V_168 . V_176 = V_177 ;
V_30 = F_91 ( V_1 -> V_56 , & V_168 , & V_169 ) ;
if ( V_30 )
F_3 ( L_37 , V_30 ) ;
return V_30 ;
}
static void
F_92 ( struct V_1 * V_1 ,
struct V_178 * V_178 ,
struct V_165 * V_166 )
{
struct V_16 * V_17 = V_1 -> V_17 ;
struct V_44 * V_58 = V_17 -> V_44 ;
F_93 ( V_58 , V_166 -> V_63 ,
V_170 , V_106 ) ;
memset ( & V_166 -> V_179 , 0 , sizeof( struct V_180 ) ) ;
V_166 -> V_179 . V_120 = V_181 ;
V_166 -> V_163 = 1 ;
if ( V_166 -> V_173 [ 0 ] . V_73 != V_17 -> V_55 -> V_74 ) {
V_166 -> V_173 [ 0 ] . V_73 = V_17 -> V_55 -> V_74 ;
F_33 ( L_38 , V_166 ) ;
}
}
static int
F_94 ( struct V_1 * V_1 ,
struct V_165 * V_166 )
{
struct V_16 * V_17 = V_1 -> V_17 ;
struct V_44 * V_58 = V_17 -> V_44 ;
T_1 V_63 ;
V_63 = F_20 ( V_58 , ( void * ) V_166 ,
V_170 , V_106 ) ;
if ( F_21 ( V_58 , V_63 ) ) {
F_3 ( L_39 ) ;
return - V_78 ;
}
V_166 -> V_63 = V_63 ;
V_166 -> V_173 [ 0 ] . V_71 = V_166 -> V_63 ;
V_166 -> V_173 [ 0 ] . V_72 = V_170 ;
V_166 -> V_173 [ 0 ] . V_73 = V_17 -> V_55 -> V_74 ;
F_33 ( L_40 ,
V_166 -> V_173 [ 0 ] . V_71 , V_166 -> V_173 [ 0 ] . V_72 ,
V_166 -> V_173 [ 0 ] . V_73 ) ;
return 0 ;
}
static void
F_95 ( struct V_1 * V_1 , struct V_178 * V_178 ,
struct V_167 * V_168 )
{
struct V_165 * V_166 = & V_178 -> V_166 ;
V_166 -> V_171 . V_76 = V_182 ;
V_168 -> V_161 = & V_166 -> V_171 ;
if ( V_1 -> V_121 && V_178 -> V_183 ) {
V_168 -> V_174 = V_184 ;
V_168 -> V_185 . V_186 = V_178 -> V_183 ;
} else {
V_168 -> V_174 = V_175 ;
}
V_168 -> V_162 = & V_166 -> V_173 [ 0 ] ;
V_168 -> V_163 = V_178 -> V_166 . V_163 ;
V_168 -> V_176 = V_177 ;
}
static int
F_56 ( struct V_1 * V_1 )
{
struct V_158 V_159 , * V_187 ;
struct V_61 V_188 ;
int V_30 ;
memset ( & V_188 , 0 , sizeof( struct V_61 ) ) ;
V_188 . V_71 = V_1 -> V_108 ;
V_188 . V_72 = V_68 ;
V_188 . V_73 = V_1 -> V_17 -> V_55 -> V_74 ;
F_33 ( L_41 ,
V_188 . V_71 , V_188 . V_72 , V_188 . V_73 ) ;
V_1 -> V_109 -> V_75 . V_76 = V_189 ;
memset ( & V_159 , 0 , sizeof( struct V_158 ) ) ;
V_159 . V_161 = & V_1 -> V_109 -> V_75 ;
V_159 . V_162 = & V_188 ;
V_159 . V_163 = 1 ;
V_30 = F_87 ( V_1 -> V_56 , & V_159 , & V_187 ) ;
if ( V_30 )
F_3 ( L_42 , V_30 ) ;
return V_30 ;
}
static int
F_96 ( struct V_190 * V_2 , struct V_191 * V_192 ,
T_2 V_72 )
{
struct V_1 * V_1 = V_2 -> V_10 ;
struct V_16 * V_17 = V_1 -> V_17 ;
struct V_44 * V_58 = V_17 -> V_44 ;
struct V_165 * V_166 = & V_1 -> V_193 ;
int V_30 ;
F_92 ( V_1 , NULL , V_166 ) ;
memcpy ( & V_166 -> V_194 , & V_192 -> V_195 [ 0 ] ,
sizeof( struct V_196 ) ) ;
F_94 ( V_1 , V_166 ) ;
if ( V_72 > 0 ) {
struct V_61 * V_197 = & V_166 -> V_173 [ 1 ] ;
F_93 ( V_58 , V_1 -> V_105 ,
V_72 , V_106 ) ;
memcpy ( V_1 -> V_107 , V_192 -> V_198 , V_72 ) ;
F_90 ( V_58 , V_1 -> V_105 ,
V_72 , V_106 ) ;
V_197 -> V_71 = V_1 -> V_105 ;
V_197 -> V_72 = V_72 ;
V_197 -> V_73 = V_1 -> V_17 -> V_55 -> V_74 ;
V_166 -> V_163 = 2 ;
}
if ( ! V_192 -> V_199 ) {
if ( V_192 -> V_200 ) {
V_30 = F_18 ( V_1 ) ;
if ( V_30 )
return V_30 ;
V_30 = F_86 ( V_1 ,
V_40 ) ;
if ( V_30 )
return V_30 ;
F_8 ( & V_1 -> V_102 ) ;
V_1 -> V_95 = V_147 ;
F_9 ( & V_1 -> V_102 ) ;
goto V_201;
}
V_30 = F_56 ( V_1 ) ;
if ( V_30 )
return V_30 ;
}
V_201:
V_30 = F_89 ( V_1 , V_166 ) ;
if ( V_30 )
return V_30 ;
return 0 ;
}
static void
F_97 ( struct V_1 * V_1 )
{
struct V_59 * V_60 = V_1 -> V_109 ;
int V_202 = V_1 -> V_203 ;
struct V_190 * V_2 = V_1 -> V_2 ;
struct V_191 * V_192 = V_2 -> V_204 ;
int V_205 ;
F_10 ( L_24 , V_1 ) ;
F_98 ( ! V_192 ) ;
if ( V_192 -> V_206 ) {
struct V_207 * V_208 =
(struct V_207 * ) & V_60 -> V_194 ;
V_192 -> V_209 = ( ! V_208 -> V_210 ) ? 1 : 0 ;
V_192 -> V_211 =
( V_208 -> V_120 & V_212 )
>> 2 ;
V_192 -> V_213 = V_208 -> V_214 ;
V_192 -> V_215 = V_208 -> V_216 ;
memcpy ( V_192 -> V_217 , V_208 -> V_217 , 6 ) ;
V_192 -> V_218 = F_99 ( V_208 -> V_219 ) ;
V_192 -> V_220 = V_208 -> V_221 ;
V_192 -> V_222 = F_99 ( V_208 -> V_223 ) ;
V_192 -> V_224 = F_100 ( V_208 -> V_224 ) ;
V_192 -> V_210 = F_100 ( V_208 -> V_210 ) ;
}
memcpy ( & V_192 -> V_225 [ 0 ] , ( void * ) & V_60 -> V_194 , V_226 ) ;
V_205 = V_20 ( V_202 , V_227 ) ;
F_33 ( L_43
L_44 , V_205 , V_202 ,
V_227 ) ;
memcpy ( V_192 -> V_228 , & V_60 -> V_229 [ 0 ] , V_205 ) ;
if ( V_192 -> V_206 ) {
F_101 ( & V_1 -> V_98 ) ;
return;
}
F_102 ( & V_2 -> V_230 , 0 ) ;
}
static struct V_231
* F_103 ( struct V_190 * V_2 , struct V_59 * V_60 )
{
struct V_1 * V_1 = V_2 -> V_10 ;
struct V_178 * V_178 ;
struct V_231 * V_4 ;
V_4 = F_104 ( V_2 , V_232 ) ;
if ( ! V_4 ) {
F_3 ( L_45 ) ;
return NULL ;
}
V_178 = F_105 ( V_4 ) ;
V_178 -> V_2 = V_1 ;
V_178 -> V_231 = V_4 ;
V_178 -> V_60 = V_60 ;
return V_4 ;
}
static int
F_106 ( struct V_1 * V_1 ,
struct V_178 * V_178 , struct V_231 * V_4 ,
struct V_59 * V_60 , unsigned char * V_233 )
{
struct V_190 * V_2 = V_1 -> V_2 ;
struct V_234 * V_235 = (struct V_234 * ) V_233 ;
int V_236 , V_237 , V_238 , V_239 , V_240 ;
bool V_241 = false ;
unsigned int V_242 ;
V_240 = F_107 ( V_2 , V_4 , V_233 ) ;
if ( V_240 < 0 )
return V_240 ;
V_236 = V_4 -> V_243 ;
V_237 = V_4 -> V_244 ;
V_238 = V_4 -> V_245 ;
V_242 = V_4 -> V_3 . V_246 ;
if ( V_236 && V_237 == V_242 )
V_4 -> V_3 . V_247 |= V_248 ;
V_240 = F_108 ( V_2 , V_4 , V_235 ) ;
if ( V_240 < 0 ) {
return 0 ;
} else if ( V_240 > 0 ) {
V_241 = true ;
goto V_249;
}
if ( ! V_236 )
return 0 ;
if ( V_237 != V_242 ) {
V_239 = F_109 ( 1UL , F_110 ( V_237 , V_250 ) ) ;
F_111 ( V_4 -> V_3 . V_251 , V_239 ,
& V_60 -> V_229 [ 0 ] , V_237 ) ;
F_33 ( L_46 ,
V_239 , V_237 ) ;
} else {
F_112 ( & V_178 -> V_252 , 1 ) ;
V_4 -> V_3 . V_251 = & V_178 -> V_252 ;
V_4 -> V_3 . V_253 = 1 ;
F_113 ( & V_178 -> V_252 , & V_60 -> V_229 [ 0 ] , V_237 ) ;
F_33 ( L_47 ,
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
V_240 = F_114 ( V_2 , V_4 , V_233 , V_235 -> V_219 ) ;
if ( ! V_240 && V_241 == false && V_238 )
F_115 ( V_4 ) ;
else if ( V_241 && V_236 )
F_116 ( & V_4 -> V_3 ) ;
return 0 ;
}
static int
F_117 ( struct V_1 * V_1 ,
struct V_59 * V_60 , unsigned char * V_233 )
{
struct V_260 * V_261 ;
struct V_190 * V_2 = V_1 -> V_2 ;
struct V_231 * V_4 = NULL ;
struct V_262 * V_235 = (struct V_262 * ) V_233 ;
T_2 V_263 = F_118 ( V_235 -> V_264 ) ;
int V_240 , V_239 , V_265 , V_266 ;
V_240 = F_119 ( V_2 , V_233 , & V_4 ) ;
if ( V_240 < 0 )
return V_240 ;
else if ( ! V_4 )
return 0 ;
if ( ! V_4 -> V_245 ) {
F_3 ( L_48 ) ;
F_120 () ;
return - 1 ;
}
F_33 ( L_49
L_50 ,
V_263 , V_4 -> V_254 ,
V_4 -> V_3 . V_246 ) ;
V_265 = V_4 -> V_254 / V_250 ;
V_261 = & V_4 -> V_3 . V_251 [ V_265 ] ;
V_239 = F_109 ( 1UL , F_110 ( V_263 , V_250 ) ) ;
V_266 = V_4 -> V_254 % V_250 ;
if ( V_266 ) {
F_3 ( L_51 ) ;
F_120 () ;
return - 1 ;
}
F_33 ( L_52
L_53 , V_261 , V_265 ,
V_239 , & V_60 -> V_229 [ 0 ] , V_263 ) ;
F_111 ( V_261 , V_239 , & V_60 -> V_229 [ 0 ] ,
V_263 ) ;
V_240 = F_121 ( V_4 , V_235 , false ) ;
if ( V_240 < 0 )
return V_240 ;
V_240 = F_88 ( V_1 , V_60 ) ;
if ( V_240 ) {
F_3 ( L_54 , V_240 ) ;
return V_240 ;
}
return 0 ;
}
static int
F_122 ( struct V_1 * V_1 , struct V_178 * V_178 ,
struct V_231 * V_4 , struct V_59 * V_60 ,
unsigned char * V_233 )
{
struct V_190 * V_2 = V_1 -> V_2 ;
struct V_267 * V_235 = (struct V_267 * ) V_233 ;
int V_240 ;
V_240 = F_123 ( V_2 , V_4 , V_235 ) ;
if ( V_240 < 0 )
return V_240 ;
return F_124 ( V_2 , V_4 , V_235 ) ;
}
static int
F_125 ( struct V_1 * V_1 , struct V_178 * V_178 ,
struct V_231 * V_4 , struct V_59 * V_60 ,
struct V_268 * V_235 )
{
struct V_190 * V_2 = V_1 -> V_2 ;
T_2 V_269 = F_118 ( V_235 -> V_264 ) ;
int V_240 ;
unsigned char * V_270 = NULL ;
V_240 = F_126 ( V_2 , V_4 , V_235 ) ;
if ( V_240 < 0 )
return V_240 ;
if ( V_269 ) {
V_270 = F_19 ( V_269 , V_66 ) ;
if ( ! V_270 ) {
F_3 ( L_55 ,
V_269 ) ;
return - V_78 ;
}
}
V_4 -> V_271 = V_270 ;
memcpy ( V_4 -> V_271 , & V_60 -> V_229 [ 0 ] , V_269 ) ;
return F_127 ( V_2 , V_4 , V_235 ) ;
}
static int
F_128 ( struct V_1 * V_1 , struct V_59 * V_60 ,
T_3 V_272 , T_4 V_273 ,
T_3 V_274 , T_4 V_275 )
{
struct V_196 * V_235 = & V_60 -> V_194 ;
struct V_190 * V_2 = V_1 -> V_2 ;
struct V_231 * V_4 ;
struct V_178 * V_178 ;
int V_30 = - V_90 ;
V_117 V_174 = ( V_235 -> V_174 & V_276 ) ;
if ( V_2 -> V_277 -> V_278 -> V_279 &&
( ! ( V_174 & V_280 ) || ! ( V_174 & V_281 ) ) ) {
F_3 ( L_56
L_57 , V_174 ) ;
return 0 ;
}
switch ( V_174 ) {
case V_282 :
V_4 = F_103 ( V_2 , V_60 ) ;
if ( ! V_4 )
break;
V_178 = F_105 ( V_4 ) ;
V_178 -> V_272 = V_272 ;
V_178 -> V_273 = V_273 ;
V_178 -> V_274 = V_274 ;
V_178 -> V_275 = V_275 ;
V_178 -> V_183 = V_272 ? V_272 : V_274 ;
V_30 = F_106 ( V_1 , V_178 , V_4 ,
V_60 , ( unsigned char * ) V_235 ) ;
break;
case V_283 :
V_4 = F_103 ( V_2 , V_60 ) ;
if ( ! V_4 )
break;
V_178 = F_105 ( V_4 ) ;
V_30 = F_122 ( V_1 , V_178 , V_4 ,
V_60 , ( unsigned char * ) V_235 ) ;
break;
case V_284 :
V_30 = F_117 ( V_1 , V_60 ,
( unsigned char * ) V_235 ) ;
break;
case V_285 :
V_4 = F_103 ( V_2 , V_60 ) ;
if ( ! V_4 )
break;
V_30 = F_129 ( V_2 , V_4 ,
( unsigned char * ) V_235 ) ;
break;
case V_281 :
V_4 = F_103 ( V_2 , V_60 ) ;
if ( ! V_4 )
break;
V_30 = F_130 ( V_2 , V_4 , ( unsigned char * ) V_235 ) ;
break;
case V_280 :
if ( F_99 ( V_235 -> V_286 ) != 0xFFFFFFFF )
V_4 = F_131 ( V_2 , V_235 -> V_221 ) ;
else
V_4 = F_103 ( V_2 , V_60 ) ;
if ( ! V_4 )
break;
V_178 = F_105 ( V_4 ) ;
V_30 = F_125 ( V_1 , V_178 , V_4 ,
V_60 , (struct V_268 * ) V_235 ) ;
break;
default:
F_3 ( L_58 , V_174 ) ;
F_120 () ;
break;
}
return V_30 ;
}
static void
F_132 ( struct V_287 * V_288 , const char * type )
{
if ( V_288 -> V_148 != V_289 )
F_3 ( L_59 , type ,
F_133 ( V_288 -> V_148 ) , V_288 -> V_148 ,
V_288 -> V_290 ) ;
else
F_33 ( L_60 , type ,
F_133 ( V_288 -> V_148 ) , V_288 -> V_148 ) ;
}
static void
V_77 ( struct V_291 * V_34 , struct V_287 * V_288 )
{
struct V_1 * V_1 = V_288 -> V_56 -> V_32 ;
struct V_44 * V_58 = V_1 -> V_13 -> V_17 ;
struct V_59 * V_60 = F_134 ( V_288 -> V_161 ) ;
struct V_196 * V_235 = & V_60 -> V_194 ;
struct V_180 * V_180 = & V_60 -> V_179 ;
T_4 V_273 = 0 , V_275 = 0 ;
T_3 V_272 = 0 , V_274 = 0 ;
if ( F_135 ( V_288 -> V_148 != V_292 ) ) {
F_132 ( V_288 , L_61 ) ;
if ( V_288 -> V_148 != V_289 )
F_82 ( V_1 -> V_2 , 0 ) ;
return;
}
F_93 ( V_58 , V_60 -> V_63 ,
V_68 , V_69 ) ;
F_33 ( L_62 ,
V_60 -> V_63 , V_235 -> V_174 , V_235 -> V_221 , V_235 -> V_120 ,
( int ) ( V_288 -> V_293 - V_170 ) ) ;
switch ( V_180 -> V_120 & 0xF0 ) {
case V_181 :
if ( V_180 -> V_120 & V_294 ) {
V_272 = F_99 ( V_180 -> V_272 ) ;
V_273 = F_136 ( V_180 -> V_273 ) ;
F_33 ( L_63 ,
V_272 , ( unsigned long long ) V_273 ) ;
}
if ( V_180 -> V_120 & V_295 ) {
V_274 = F_99 ( V_180 -> V_274 ) ;
V_275 = F_136 ( V_180 -> V_275 ) ;
F_33 ( L_64 ,
V_274 , ( unsigned long long ) V_275 ) ;
}
F_33 ( L_65 ) ;
break;
case V_296 :
F_3 ( L_66 ) ;
break;
default:
F_6 ( L_67 , V_180 -> V_120 ) ;
break;
}
F_128 ( V_1 , V_60 ,
V_272 , V_273 , V_274 , V_275 ) ;
F_90 ( V_58 , V_60 -> V_63 ,
V_68 , V_69 ) ;
}
static void
V_189 ( struct V_291 * V_34 , struct V_287 * V_288 )
{
struct V_1 * V_1 = V_288 -> V_56 -> V_32 ;
struct V_44 * V_58 = V_1 -> V_13 -> V_17 ;
if ( F_135 ( V_288 -> V_148 != V_292 ) ) {
F_132 ( V_288 , L_68 ) ;
return;
}
F_93 ( V_58 , V_1 -> V_108 ,
V_68 , V_69 ) ;
V_1 -> V_203 = V_288 -> V_293 - V_170 ;
if ( V_1 -> V_2 ) {
struct V_191 * V_192 = V_1 -> V_2 -> V_204 ;
if ( V_192 && ! V_192 -> V_206 )
F_97 ( V_1 ) ;
}
F_8 ( & V_1 -> V_102 ) ;
F_101 ( & V_1 -> V_99 ) ;
F_9 ( & V_1 -> V_102 ) ;
F_90 ( V_58 , V_1 -> V_108 ,
V_68 , V_69 ) ;
}
static void
F_137 ( struct V_178 * V_4 , struct V_1 * V_2 )
{
struct V_3 * V_3 = & V_4 -> V_231 -> V_3 ;
enum V_297 V_298 = F_138 ( V_3 ) ;
if ( ! V_4 -> V_299 . V_300 )
return;
if ( F_1 ( V_2 , V_3 ) ) {
F_139 ( & V_4 -> V_299 , V_2 -> V_56 ,
V_2 -> V_13 -> V_301 , V_3 -> V_251 ,
V_3 -> V_253 , V_3 -> V_302 ,
V_3 -> V_303 , V_298 ) ;
} else {
F_140 ( & V_4 -> V_299 , V_2 -> V_56 , V_2 -> V_13 -> V_301 ,
V_3 -> V_251 , V_3 -> V_253 , V_298 ) ;
}
V_4 -> V_299 . V_300 = 0 ;
}
static void
F_141 ( struct V_178 * V_178 , bool V_304 )
{
struct V_231 * V_4 = V_178 -> V_231 ;
struct V_1 * V_1 = V_178 -> V_2 ;
struct V_190 * V_2 = V_1 -> V_2 ;
struct V_305 * V_235 ;
F_33 ( L_69 , V_178 ) ;
switch ( V_4 -> V_306 ) {
case V_282 :
F_53 ( & V_2 -> V_307 ) ;
if ( ! F_72 ( & V_4 -> V_308 ) )
F_73 ( & V_4 -> V_308 ) ;
F_54 ( & V_2 -> V_307 ) ;
if ( V_4 -> V_309 == V_106 ) {
F_142 ( V_4 ) ;
if ( V_304 &&
V_4 -> V_3 . V_310 == V_311 ) {
struct V_3 * V_3 = & V_4 -> V_3 ;
F_116 ( V_3 ) ;
}
}
F_137 ( V_178 , V_1 ) ;
F_143 ( & V_4 -> V_3 , 0 ) ;
break;
case V_285 :
F_53 ( & V_2 -> V_307 ) ;
if ( ! F_72 ( & V_4 -> V_308 ) )
F_73 ( & V_4 -> V_308 ) ;
F_54 ( & V_2 -> V_307 ) ;
F_143 ( & V_4 -> V_3 , 0 ) ;
break;
case V_312 :
case V_283 :
case V_280 :
V_235 = (struct V_305 * ) & V_178 -> V_166 . V_194 ;
if ( V_235 -> V_120 & V_313 )
break;
F_53 ( & V_2 -> V_307 ) ;
if ( ! F_72 ( & V_4 -> V_308 ) )
F_73 ( & V_4 -> V_308 ) ;
F_54 ( & V_2 -> V_307 ) ;
if ( V_4 -> V_3 . V_314 != NULL ) {
F_33 ( L_70 ,
V_4 -> V_306 ) ;
F_143 ( & V_4 -> V_3 , 0 ) ;
break;
}
default:
F_144 ( V_4 ) ;
break;
}
}
static void
F_145 ( struct V_165 * V_166 , struct V_44 * V_58 )
{
if ( V_166 -> V_63 != 0 ) {
F_33 ( L_71 ) ;
F_22 ( V_58 , V_166 -> V_63 ,
V_170 , V_106 ) ;
V_166 -> V_63 = 0 ;
}
}
static void
F_146 ( struct V_165 * V_166 , struct V_178 * V_178 ,
struct V_44 * V_58 , bool V_304 )
{
if ( V_178 -> V_315 != 0 ) {
F_33 ( L_72 ) ;
F_22 ( V_58 , V_178 -> V_315 ,
V_178 -> V_316 , V_106 ) ;
V_178 -> V_315 = 0 ;
}
F_145 ( V_166 , V_58 ) ;
F_141 ( V_178 , V_304 ) ;
}
static int
F_147 ( struct V_3 * V_3 , struct V_317 * V_318 )
{
struct V_319 V_320 ;
int V_30 ;
V_30 = F_148 ( V_318 , V_321 , & V_320 ) ;
if ( V_30 ) {
F_3 ( L_73 , V_30 ) ;
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
F_149 ( V_324 , V_325 ) ;
V_3 -> V_338 = V_324 + V_3 -> V_339 ;
F_3 ( L_74
L_75 ,
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
F_150 ( struct V_291 * V_34 , struct V_287 * V_288 )
{
struct V_1 * V_1 = V_288 -> V_56 -> V_32 ;
struct V_16 * V_17 = V_1 -> V_17 ;
struct V_165 * V_342 = F_151 ( V_288 -> V_161 ) ;
struct V_178 * V_178 = F_152 ( V_342 ) ;
struct V_3 * V_4 = & V_178 -> V_231 -> V_3 ;
int V_30 = 0 ;
if ( F_135 ( V_288 -> V_148 != V_292 ) ) {
F_132 ( V_288 , L_76 ) ;
if ( V_288 -> V_148 != V_289 )
F_82 ( V_1 -> V_2 , 0 ) ;
F_146 ( V_342 , V_178 , V_17 -> V_44 , true ) ;
return;
}
F_33 ( L_69 , V_178 ) ;
V_30 = F_147 ( V_4 , V_178 -> V_299 . V_343 -> V_318 ) ;
F_137 ( V_178 , V_1 ) ;
if ( V_30 )
F_153 ( V_4 , V_4 -> V_331 , 0 ) ;
else
F_154 ( V_1 -> V_2 , V_178 -> V_231 ) ;
}
static void
F_155 ( struct V_291 * V_34 , struct V_287 * V_288 )
{
struct V_1 * V_1 = V_288 -> V_56 -> V_32 ;
struct V_16 * V_17 = V_1 -> V_17 ;
struct V_165 * V_342 = F_151 ( V_288 -> V_161 ) ;
struct V_178 * V_178 = F_152 ( V_342 ) ;
struct V_231 * V_4 = V_178 -> V_231 ;
struct V_3 * V_3 = & V_4 -> V_3 ;
int V_30 = 0 ;
if ( F_135 ( V_288 -> V_148 != V_292 ) ) {
F_132 ( V_288 , L_77 ) ;
if ( V_288 -> V_148 != V_289 )
F_82 ( V_1 -> V_2 , 0 ) ;
F_146 ( V_342 , V_178 , V_17 -> V_44 , true ) ;
return;
}
F_33 ( L_69 , V_178 ) ;
F_142 ( V_4 ) ;
if ( F_1 ( V_1 , V_3 ) )
V_30 = F_147 ( V_3 , V_178 -> V_299 . V_343 -> V_318 ) ;
F_137 ( V_178 , V_1 ) ;
V_4 -> V_254 = 0 ;
F_33 ( L_78 , V_178 ) ;
F_53 ( & V_4 -> V_255 ) ;
V_4 -> V_256 |= V_257 ;
V_4 -> V_258 = V_259 ;
F_54 ( & V_4 -> V_255 ) ;
if ( V_30 ) {
F_116 ( V_3 ) ;
F_153 ( V_3 ,
V_3 -> V_331 , 0 ) ;
} else {
F_156 ( V_3 ) ;
}
}
static void
F_157 ( struct V_344 * V_345 )
{
struct V_178 * V_178 = F_68 ( V_345 ,
struct V_178 , V_346 ) ;
struct V_1 * V_1 = V_178 -> V_2 ;
struct V_44 * V_58 = V_1 -> V_13 -> V_17 ;
struct V_231 * V_4 = V_178 -> V_231 ;
F_33 ( L_79 , V_178 , V_4 -> V_258 ) ;
switch ( V_4 -> V_258 ) {
case V_347 :
F_158 ( V_4 , V_4 -> V_2 ) ;
case V_348 :
case V_349 :
V_4 -> V_258 = V_350 ;
F_146 ( & V_178 -> V_166 , V_178 ,
V_58 , false ) ;
break;
case V_351 :
F_159 ( V_4 , V_4 -> V_2 ) ;
break;
default:
F_3 ( L_80 , V_4 -> V_258 ) ;
F_120 () ;
break;
}
}
static void
V_172 ( struct V_291 * V_34 , struct V_287 * V_288 )
{
struct V_1 * V_1 = V_288 -> V_56 -> V_32 ;
struct V_44 * V_58 = V_1 -> V_13 -> V_17 ;
struct V_165 * V_166 = F_151 ( V_288 -> V_161 ) ;
if ( F_135 ( V_288 -> V_148 != V_292 ) ) {
F_132 ( V_288 , L_81 ) ;
if ( V_288 -> V_148 != V_289 )
F_82 ( V_1 -> V_2 , 0 ) ;
}
F_145 ( V_166 , V_58 ) ;
}
static void
V_182 ( struct V_291 * V_34 , struct V_287 * V_288 )
{
struct V_1 * V_1 = V_288 -> V_56 -> V_32 ;
struct V_44 * V_58 = V_1 -> V_13 -> V_17 ;
struct V_165 * V_166 = F_151 ( V_288 -> V_161 ) ;
struct V_178 * V_178 = F_152 ( V_166 ) ;
if ( F_135 ( V_288 -> V_148 != V_292 ) ) {
F_132 ( V_288 , L_82 ) ;
if ( V_288 -> V_148 != V_289 )
F_82 ( V_1 -> V_2 , 0 ) ;
F_146 ( V_166 , V_178 , V_58 , true ) ;
return;
}
F_33 ( L_69 , V_178 ) ;
switch ( V_178 -> V_231 -> V_258 ) {
case V_347 :
case V_351 :
case V_348 :
case V_349 :
F_145 ( V_166 , V_58 ) ;
F_48 ( & V_178 -> V_346 , F_157 ) ;
F_74 ( V_352 , & V_178 -> V_346 ) ;
return;
default:
V_178 -> V_231 -> V_258 = V_350 ;
F_146 ( V_166 , V_178 , V_58 , false ) ;
break;
}
}
static int
F_160 ( struct V_1 * V_1 , struct V_178 * V_178 )
{
struct V_167 * V_353 ;
int V_30 ;
V_30 = F_88 ( V_1 , V_178 -> V_60 ) ;
if ( V_30 ) {
F_3 ( L_54 , V_30 ) ;
return V_30 ;
}
V_30 = F_91 ( V_1 -> V_56 , & V_178 -> V_166 . V_168 ,
& V_353 ) ;
if ( V_30 ) {
F_3 ( L_83 , V_30 ) ;
return V_30 ;
}
return V_30 ;
}
static int
F_154 ( struct V_190 * V_2 , struct V_231 * V_4 )
{
struct V_178 * V_178 = F_105 ( V_4 ) ;
struct V_1 * V_1 = V_2 -> V_10 ;
struct V_167 * V_168 = & V_178 -> V_166 . V_168 ;
struct V_354 * V_235 = (struct V_354 * )
& V_178 -> V_166 . V_194 ;
F_92 ( V_1 , V_178 , & V_178 -> V_166 ) ;
F_161 ( V_4 , V_2 , true , V_235 ) ;
F_94 ( V_1 , & V_178 -> V_166 ) ;
if ( V_4 -> V_3 . V_355 &&
( ( V_4 -> V_3 . V_247 & V_356 ) ||
( V_4 -> V_3 . V_247 & V_357 ) ) ) {
struct V_16 * V_17 = V_1 -> V_17 ;
struct V_44 * V_58 = V_17 -> V_44 ;
struct V_61 * V_197 = & V_178 -> V_166 . V_173 [ 1 ] ;
T_2 V_358 , V_359 ;
F_162 ( V_4 -> V_3 . V_360 ,
V_4 -> V_355 ) ;
V_4 -> V_3 . V_360 += sizeof( V_361 ) ;
V_358 = - ( V_4 -> V_3 . V_360 ) & 3 ;
F_163 ( V_235 -> V_264 , ( T_2 ) V_4 -> V_3 . V_360 ) ;
V_359 = V_4 -> V_3 . V_360 + V_358 ;
V_178 -> V_315 = F_20 ( V_58 ,
( void * ) V_4 -> V_355 , V_359 ,
V_106 ) ;
V_178 -> V_316 = V_359 ;
V_197 -> V_71 = V_178 -> V_315 ;
V_197 -> V_72 = V_359 ;
V_197 -> V_73 = V_17 -> V_55 -> V_74 ;
V_178 -> V_166 . V_163 = 2 ;
}
F_95 ( V_1 , V_178 , V_168 ) ;
F_33 ( L_84 ) ;
return F_160 ( V_1 , V_178 ) ;
}
static void
F_164 ( struct V_190 * V_2 , struct V_231 * V_4 )
{
struct V_178 * V_178 = F_105 ( V_4 ) ;
struct V_1 * V_1 = V_2 -> V_10 ;
F_53 ( & V_2 -> V_307 ) ;
if ( ! F_72 ( & V_4 -> V_308 ) )
F_73 ( & V_4 -> V_308 ) ;
F_54 ( & V_2 -> V_307 ) ;
if ( V_4 -> V_309 == V_106 )
F_142 ( V_4 ) ;
F_137 ( V_178 , V_1 ) ;
}
static enum V_362
F_165 ( struct V_190 * V_2 )
{
struct V_1 * V_1 = V_2 -> V_10 ;
struct V_16 * V_17 = V_1 -> V_17 ;
if ( V_2 -> V_363 -> V_364 . V_365 ) {
if ( V_17 -> V_52 ) {
F_10 ( L_85 , V_1 ) ;
V_1 -> V_5 = true ;
return V_366 ;
}
}
F_10 ( L_86 , V_1 ) ;
V_1 -> V_5 = false ;
return V_7 ;
}
static int
F_166 ( struct V_231 * V_4 , struct V_190 * V_2 ,
bool V_367 )
{
struct V_178 * V_178 = F_105 ( V_4 ) ;
struct V_1 * V_1 = V_2 -> V_10 ;
struct V_167 * V_168 = & V_178 -> V_166 . V_168 ;
F_92 ( V_1 , V_178 , & V_178 -> V_166 ) ;
F_167 ( V_4 , V_2 , (struct V_368 * )
& V_178 -> V_166 . V_194 ,
V_367 ) ;
F_94 ( V_1 , & V_178 -> V_166 ) ;
F_95 ( V_1 , V_178 , V_168 ) ;
F_33 ( L_87 , V_1 ) ;
return F_160 ( V_1 , V_178 ) ;
}
static int
F_168 ( struct V_231 * V_4 , struct V_190 * V_2 )
{
struct V_178 * V_178 = F_105 ( V_4 ) ;
struct V_1 * V_1 = V_2 -> V_10 ;
struct V_167 * V_168 = & V_178 -> V_166 . V_168 ;
F_92 ( V_1 , V_178 , & V_178 -> V_166 ) ;
F_169 ( V_4 , V_2 , (struct V_369 * )
& V_178 -> V_166 . V_194 ) ;
F_94 ( V_1 , & V_178 -> V_166 ) ;
F_95 ( V_1 , V_178 , V_168 ) ;
F_33 ( L_88 , V_1 ) ;
return F_160 ( V_1 , V_178 ) ;
}
static int
F_170 ( struct V_231 * V_4 , struct V_190 * V_2 )
{
struct V_178 * V_178 = F_105 ( V_4 ) ;
struct V_1 * V_1 = V_2 -> V_10 ;
struct V_167 * V_168 = & V_178 -> V_166 . V_168 ;
F_92 ( V_1 , V_178 , & V_178 -> V_166 ) ;
F_171 ( V_4 , V_2 , (struct V_370 * )
& V_178 -> V_166 . V_194 ) ;
F_94 ( V_1 , & V_178 -> V_166 ) ;
F_95 ( V_1 , V_178 , V_168 ) ;
F_33 ( L_89 , V_1 ) ;
return F_160 ( V_1 , V_178 ) ;
}
static int
F_172 ( struct V_231 * V_4 , struct V_190 * V_2 )
{
struct V_178 * V_178 = F_105 ( V_4 ) ;
struct V_1 * V_1 = V_2 -> V_10 ;
struct V_167 * V_168 = & V_178 -> V_166 . V_168 ;
struct V_16 * V_17 = V_1 -> V_17 ;
struct V_44 * V_58 = V_17 -> V_44 ;
struct V_61 * V_197 = & V_178 -> V_166 . V_173 [ 1 ] ;
struct V_371 * V_235 =
(struct V_371 * ) & V_178 -> V_166 . V_194 ;
F_92 ( V_1 , V_178 , & V_178 -> V_166 ) ;
F_173 ( V_4 , V_2 , V_235 ) ;
F_94 ( V_1 , & V_178 -> V_166 ) ;
F_163 ( V_235 -> V_264 , V_226 ) ;
V_178 -> V_315 = F_20 ( V_58 ,
( void * ) V_4 -> V_372 , V_226 ,
V_106 ) ;
V_178 -> V_316 = V_226 ;
V_197 -> V_71 = V_178 -> V_315 ;
V_197 -> V_72 = V_226 ;
V_197 -> V_73 = V_17 -> V_55 -> V_74 ;
V_178 -> V_166 . V_163 = 2 ;
F_95 ( V_1 , V_178 , V_168 ) ;
F_33 ( L_90 , V_1 ) ;
return F_160 ( V_1 , V_178 ) ;
}
static int
F_174 ( struct V_231 * V_4 , struct V_190 * V_2 )
{
struct V_178 * V_178 = F_105 ( V_4 ) ;
struct V_1 * V_1 = V_2 -> V_10 ;
struct V_167 * V_168 = & V_178 -> V_166 . V_168 ;
struct V_305 * V_235 =
(struct V_305 * ) & V_178 -> V_166 . V_194 ;
T_2 V_373 ;
int V_240 ;
F_92 ( V_1 , V_178 , & V_178 -> V_166 ) ;
V_240 = F_175 ( V_4 , V_2 , V_235 , V_374 ) ;
if ( V_240 < 0 )
return V_240 ;
V_373 = V_240 ;
F_94 ( V_1 , & V_178 -> V_166 ) ;
if ( V_373 ) {
struct V_16 * V_17 = V_1 -> V_17 ;
struct V_44 * V_58 = V_17 -> V_44 ;
struct V_61 * V_197 = & V_178 -> V_166 . V_173 [ 1 ] ;
void * V_375 = V_4 -> V_372 ;
V_178 -> V_315 = F_20 ( V_58 ,
V_375 , V_373 , V_106 ) ;
V_178 -> V_316 = V_373 ;
V_197 -> V_71 = V_178 -> V_315 ;
V_197 -> V_72 = V_373 ;
V_197 -> V_73 = V_17 -> V_55 -> V_74 ;
V_178 -> V_166 . V_163 = 2 ;
}
F_95 ( V_1 , V_178 , V_168 ) ;
F_33 ( L_91 , V_1 ) ;
return F_160 ( V_1 , V_178 ) ;
}
static inline void
F_176 ( struct V_3 * V_3 , struct V_376 * V_377 ,
struct V_378 * V_379 )
{
V_379 -> V_380 = V_381 ;
V_379 -> V_343 . V_382 . V_383 = V_384 ;
V_379 -> V_343 . V_382 . V_385 = V_3 -> V_326 -> V_327 . V_325 ;
V_379 -> V_343 . V_382 . V_386 = V_3 -> V_387 ;
V_379 -> V_343 . V_382 . V_388 = 0xffff ;
V_379 -> V_343 . V_382 . V_389 = true ;
V_379 -> V_343 . V_382 . V_390 = true ;
if ( V_3 -> V_391 == V_392 ||
V_3 -> V_391 == V_393 )
V_379 -> V_343 . V_382 . V_394 = true ;
}
static int
F_177 ( struct V_3 * V_3 , struct V_376 * V_377 )
{
memset ( V_377 , 0 , sizeof( * V_377 ) ) ;
switch ( V_3 -> V_6 ) {
case V_395 :
case V_396 :
V_377 -> V_397 . V_380 = V_398 ;
F_176 ( V_3 , V_377 , & V_377 -> V_399 ) ;
break;
case V_400 :
case V_401 :
V_377 -> V_399 . V_380 = V_398 ;
F_176 ( V_3 , V_377 , & V_377 -> V_397 ) ;
break;
case V_402 :
case V_403 :
F_176 ( V_3 , V_377 , & V_377 -> V_399 ) ;
F_176 ( V_3 , V_377 , & V_377 -> V_397 ) ;
break;
default:
F_3 ( L_92 , V_3 -> V_6 ) ;
return - V_90 ;
}
V_377 -> V_404 =
( V_3 -> V_405 & V_406 ? 0xc0 : 0 ) |
( V_3 -> V_405 & V_407 ? 0x30 : 0 ) |
( V_3 -> V_405 & V_407 ? 0x0f : 0 ) ;
return 0 ;
}
static int
F_178 ( struct V_178 * V_4 , struct V_1 * V_2 ,
struct V_408 * V_409 , struct V_167 * V_410 )
{
struct V_3 * V_3 = & V_4 -> V_231 -> V_3 ;
enum V_297 V_298 = F_138 ( V_3 ) ;
V_117 V_301 = V_2 -> V_13 -> V_301 ;
T_1 V_71 ;
T_2 V_411 , V_412 ;
int V_30 ;
if ( V_298 == V_69 ) {
V_71 = V_4 -> V_275 ;
V_411 = V_4 -> V_274 ;
V_412 = V_4 -> V_231 -> V_254 ;
} else {
V_71 = V_4 -> V_273 ;
V_411 = V_4 -> V_272 ;
V_412 = 0 ;
}
if ( F_1 ( V_2 , V_3 ) ) {
struct V_376 V_377 ;
V_30 = F_177 ( V_3 , & V_377 ) ;
if ( V_30 )
return V_30 ;
F_98 ( V_412 ) ;
V_30 = F_179 ( & V_4 -> V_299 , V_2 -> V_56 , V_301 ,
V_3 -> V_251 , V_3 -> V_253 ,
V_3 -> V_302 , V_3 -> V_303 ,
& V_377 , V_71 , V_411 , V_298 ) ;
} else {
V_30 = F_180 ( & V_4 -> V_299 , V_2 -> V_56 , V_301 ,
V_3 -> V_251 , V_3 -> V_253 ,
V_412 , V_71 , V_411 , V_298 ) ;
}
if ( V_30 < 0 ) {
F_3 ( L_93 , V_4 ) ;
return V_30 ;
}
V_30 = F_181 ( & V_4 -> V_299 , V_2 -> V_56 , V_301 , V_409 , V_410 ) ;
if ( V_30 < 0 )
F_3 ( L_94 , V_4 ) ;
return V_30 ;
}
static int
F_182 ( struct V_190 * V_2 , struct V_231 * V_4 )
{
struct V_3 * V_3 = & V_4 -> V_3 ;
struct V_178 * V_178 = F_105 ( V_4 ) ;
struct V_1 * V_1 = V_2 -> V_10 ;
struct V_408 * V_409 = NULL ;
struct V_167 * V_410 = NULL ;
int V_240 ;
F_33 ( L_95 ,
V_178 , V_3 -> V_246 ) ;
if ( F_1 ( V_1 , V_3 ) ) {
V_178 -> V_166 . V_171 . V_76 = F_150 ;
V_409 = & V_178 -> V_166 . V_171 ;
} else {
F_92 ( V_1 , V_178 ,
& V_178 -> V_166 ) ;
F_161 ( V_4 , V_2 , true , (struct V_354 * )
& V_178 -> V_166 . V_194 ) ;
F_94 ( V_1 , & V_178 -> V_166 ) ;
F_95 ( V_1 , V_178 ,
& V_178 -> V_166 . V_168 ) ;
V_240 = F_88 ( V_1 , V_178 -> V_60 ) ;
if ( V_240 ) {
F_3 ( L_54 , V_240 ) ;
return V_240 ;
}
V_410 = & V_178 -> V_166 . V_168 ;
}
F_178 ( V_178 , V_1 , V_409 , V_410 ) ;
F_33 ( L_96 , V_178 ) ;
return 1 ;
}
static int
F_183 ( struct V_190 * V_2 , struct V_231 * V_4 , bool V_413 )
{
struct V_178 * V_178 = F_105 ( V_4 ) ;
F_33 ( L_97 ,
V_178 , V_4 -> V_3 . V_246 , V_4 -> V_254 ) ;
V_178 -> V_166 . V_171 . V_76 = F_155 ;
F_178 ( V_178 , V_2 -> V_10 ,
& V_178 -> V_166 . V_171 , NULL ) ;
F_33 ( L_98 ,
V_178 ) ;
return 0 ;
}
static int
F_184 ( struct V_190 * V_2 , struct V_231 * V_4 , int V_95 )
{
struct V_178 * V_178 = F_105 ( V_4 ) ;
int V_30 = 0 ;
switch ( V_95 ) {
case V_414 :
F_53 ( & V_2 -> V_307 ) ;
F_73 ( & V_4 -> V_308 ) ;
F_54 ( & V_2 -> V_307 ) ;
F_141 ( V_178 , true ) ;
break;
case V_415 :
V_30 = F_166 ( V_4 , V_2 , false ) ;
break;
default:
F_3 ( L_99 , V_95 ) ;
V_30 = - V_90 ;
break;
}
return V_30 ;
}
static int
F_185 ( struct V_190 * V_2 , struct V_231 * V_4 , int V_95 )
{
struct V_1 * V_1 = V_2 -> V_10 ;
int V_30 ;
switch ( V_95 ) {
case V_351 :
V_30 = F_168 ( V_4 , V_2 ) ;
if ( ! V_30 )
V_1 -> V_416 = true ;
break;
case V_417 :
V_30 = F_166 ( V_4 , V_2 , true ) ;
break;
case V_347 :
V_30 = F_170 ( V_4 , V_2 ) ;
break;
case V_348 :
V_30 = F_172 ( V_4 , V_2 ) ;
break;
case V_349 :
V_30 = F_174 ( V_4 , V_2 ) ;
break;
case V_418 :
V_30 = F_154 ( V_2 , V_4 ) ;
break;
default:
F_3 ( L_100 , V_95 ) ;
V_30 = - V_90 ;
break;
}
return V_30 ;
}
struct V_26 *
F_79 ( struct V_125 * V_125 )
{
struct V_126 * V_127 = V_125 -> V_127 ;
struct V_26 * V_419 ;
struct V_420 * V_421 ;
int V_30 ;
V_421 = (struct V_420 * ) & V_127 -> V_422 ;
F_33 ( L_101 , & V_127 -> V_422 , V_421 ) ;
V_419 = F_186 ( & V_423 , F_84 , V_125 ,
V_424 , V_51 ) ;
if ( F_16 ( V_419 ) ) {
F_3 ( L_102 , F_17 ( V_419 ) ) ;
V_30 = F_17 ( V_419 ) ;
goto V_87;
}
F_33 ( L_103 , V_419 , V_419 -> V_10 ) ;
V_30 = F_187 ( V_419 , V_421 ) ;
if ( V_30 ) {
F_3 ( L_104 , V_30 ) ;
goto V_425;
}
V_30 = F_188 ( V_419 , 0 ) ;
if ( V_30 ) {
F_3 ( L_105 , V_30 ) ;
goto V_425;
}
return V_419 ;
V_425:
F_60 ( V_419 ) ;
V_87:
return F_14 ( V_30 ) ;
}
static int
F_189 ( struct V_126 * V_127 ,
struct V_426 * V_427 )
{
struct V_125 * V_125 ;
struct V_26 * V_428 ;
int V_30 ;
V_125 = F_19 ( sizeof( struct V_125 ) , V_66 ) ;
if ( ! V_125 ) {
F_3 ( L_106 ) ;
return - V_78 ;
}
F_190 ( & V_125 -> V_137 , 0 ) ;
F_47 ( & V_125 -> V_102 ) ;
F_41 ( & V_125 -> V_132 ) ;
F_41 ( & V_125 -> V_136 ) ;
V_125 -> V_127 = V_127 ;
memcpy ( & V_127 -> V_422 , V_427 ,
sizeof( struct V_426 ) ) ;
V_428 = F_79 ( V_125 ) ;
if ( F_16 ( V_428 ) ) {
V_30 = F_17 ( V_428 ) ;
goto V_87;
}
V_125 -> V_13 = V_428 ;
V_127 -> V_429 = V_125 ;
return 0 ;
V_87:
F_23 ( V_125 ) ;
return V_30 ;
}
static int
F_57 ( struct V_1 * V_1 )
{
struct V_26 * V_13 = V_1 -> V_13 ;
struct V_113 V_430 ;
int V_30 ;
struct V_431 V_432 ;
memset ( & V_430 , 0 , sizeof( struct V_113 ) ) ;
V_430 . V_116 = V_1 -> V_116 ;
V_430 . V_433 = 7 ;
V_430 . V_434 = 7 ;
memset ( & V_432 , 0 , sizeof( V_432 ) ) ;
V_432 . V_120 = V_435 ;
if ( ! V_1 -> V_121 )
V_432 . V_120 = V_432 . V_120 | V_436 ;
V_430 . V_119 = ( void * ) & V_432 ;
V_430 . V_437 = sizeof( V_432 ) ;
V_30 = F_191 ( V_13 , & V_430 ) ;
if ( V_30 ) {
F_3 ( L_107 , V_30 ) ;
return V_30 ;
}
return 0 ;
}
static int
F_192 ( struct V_190 * V_2 , struct V_191 * V_192 )
{
struct V_1 * V_1 = V_2 -> V_10 ;
int V_30 ;
F_10 ( L_108 , V_1 ) ;
V_30 = F_193 ( & V_1 -> V_99 ) ;
if ( V_30 ) {
F_3 ( L_109 ,
V_1 ) ;
return V_30 ;
}
F_194 ( & V_1 -> V_99 ) ;
if ( ! V_192 -> V_206 )
return 0 ;
F_97 ( V_1 ) ;
F_10 ( L_110 , V_2 ) ;
V_30 = F_193 ( & V_1 -> V_98 ) ;
if ( V_30 )
return V_30 ;
F_10 ( L_111 , V_192 -> V_225 ) ;
return 0 ;
}
static void
F_195 ( struct V_126 * V_127 , struct V_190 * V_2 ,
struct V_1 * V_1 )
{
struct V_26 * V_13 = V_1 -> V_13 ;
struct V_438 * V_439 = & V_13 -> V_440 ;
V_2 -> V_441 = V_127 -> V_422 . V_442 ;
V_2 -> V_443 = V_439 -> V_71 . V_444 ;
V_2 -> V_445 = V_439 -> V_71 . V_446 ;
}
static int
F_196 ( struct V_126 * V_127 , struct V_190 * V_2 )
{
struct V_125 * V_125 = V_127 -> V_429 ;
struct V_1 * V_1 ;
int V_30 ;
V_447:
V_30 = F_197 ( & V_125 -> V_137 ) ;
if ( V_30 )
return - V_448 ;
F_53 ( & V_127 -> V_128 ) ;
if ( V_127 -> V_449 >= V_450 ) {
F_54 ( & V_127 -> V_128 ) ;
F_33 ( L_112 ,
V_127 -> V_449 ) ;
return - V_448 ;
}
F_54 ( & V_127 -> V_128 ) ;
F_8 ( & V_125 -> V_102 ) ;
if ( F_72 ( & V_125 -> V_136 ) ) {
F_9 ( & V_125 -> V_102 ) ;
goto V_447;
}
V_1 = F_198 ( & V_125 -> V_136 ,
struct V_1 , V_97 ) ;
F_73 ( & V_1 -> V_97 ) ;
F_9 ( & V_125 -> V_102 ) ;
V_2 -> V_10 = V_1 ;
V_1 -> V_2 = V_2 ;
V_1 -> V_95 = V_146 ;
F_195 ( V_127 , V_2 , V_1 ) ;
F_33 ( L_113 , V_1 ) ;
return 0 ;
}
static void
F_199 ( struct V_126 * V_127 )
{
struct V_125 * V_125 = V_127 -> V_429 ;
struct V_1 * V_1 , * V_451 ;
if ( V_125 -> V_13 )
F_60 ( V_125 -> V_13 ) ;
F_8 ( & V_125 -> V_102 ) ;
if ( ! F_72 ( & V_125 -> V_136 ) ) {
F_10 ( L_114 ) ;
F_200 (isert_conn, n,
&isert_np->pending,
node) {
F_10 ( L_115 ,
V_1 , V_1 -> V_95 ) ;
F_58 ( V_1 ) ;
}
}
if ( ! F_72 ( & V_125 -> V_132 ) ) {
F_10 ( L_116 ) ;
F_200 (isert_conn, n,
&isert_np->accepted,
node) {
F_10 ( L_115 ,
V_1 , V_1 -> V_95 ) ;
F_58 ( V_1 ) ;
}
}
F_9 ( & V_125 -> V_102 ) ;
V_127 -> V_429 = NULL ;
F_23 ( V_125 ) ;
}
static void V_104 ( struct V_344 * V_345 )
{
struct V_1 * V_1 = F_68 ( V_345 ,
struct V_1 ,
V_103 ) ;
F_10 ( L_117 , V_1 ) ;
F_8 ( & V_1 -> V_102 ) ;
V_1 -> V_95 = V_153 ;
F_9 ( & V_1 -> V_102 ) ;
F_10 ( L_118 , V_1 ) ;
F_69 ( V_1 ) ;
}
static void
F_201 ( struct V_1 * V_1 )
{
struct V_190 * V_2 = V_1 -> V_2 ;
F_10 ( L_24 , V_1 ) ;
if ( V_1 -> V_416 ) {
F_10 ( L_119 , V_1 ) ;
F_202 ( & V_2 -> V_452 ,
V_453 * V_454 ) ;
}
}
static void
F_203 ( struct V_190 * V_2 )
{
F_10 ( L_120 , V_2 ) ;
if ( V_2 -> V_277 ) {
F_204 ( V_2 -> V_277 -> V_455 ) ;
F_205 ( V_2 -> V_277 -> V_455 ) ;
}
}
static void
F_206 ( struct V_190 * V_2 )
{
struct V_231 * V_4 , * V_456 ;
static F_207 ( V_457 ) ;
F_53 ( & V_2 -> V_307 ) ;
F_200 (cmd, tmp, &conn->conn_cmd_list, i_conn_node) {
if ( ( V_4 -> V_256 & V_458 ) &&
( V_4 -> V_254 < V_2 -> V_277 -> V_278 -> V_459 ) &&
( V_4 -> V_254 < V_4 -> V_3 . V_246 ) )
F_65 ( & V_4 -> V_308 , & V_457 ) ;
}
F_54 ( & V_2 -> V_307 ) ;
F_200 (cmd, tmp, &drop_cmd_list, i_conn_node) {
F_73 ( & V_4 -> V_308 ) ;
if ( V_4 -> V_258 != V_414 ) {
struct V_178 * V_178 = F_105 ( V_4 ) ;
F_10 ( L_121 , V_2 , V_4 ) ;
F_141 ( V_178 , true ) ;
}
}
}
static void F_208 ( struct V_190 * V_2 )
{
struct V_1 * V_1 = V_2 -> V_10 ;
F_10 ( L_122 , V_1 ) ;
F_8 ( & V_1 -> V_102 ) ;
F_75 ( V_1 ) ;
F_9 ( & V_1 -> V_102 ) ;
F_81 ( V_1 -> V_56 ) ;
F_206 ( V_2 ) ;
F_203 ( V_2 ) ;
F_201 ( V_1 ) ;
F_74 ( V_141 , & V_1 -> V_103 ) ;
}
static void F_209 ( struct V_190 * V_2 )
{
struct V_1 * V_1 = V_2 -> V_10 ;
F_81 ( V_1 -> V_56 ) ;
F_69 ( V_1 ) ;
}
static void F_210 ( struct V_190 * V_2 )
{
struct V_460 V_18 ;
F_44 ( & V_18 ) ;
F_193 ( & V_18 ) ;
}
static int T_5 F_211 ( void )
{
int V_30 ;
V_352 = F_212 ( L_123 ,
V_461 | V_462 , 0 ) ;
if ( ! V_352 ) {
F_3 ( L_124 ) ;
V_30 = - V_78 ;
return - V_78 ;
}
V_141 = F_212 ( L_125 , V_461 ,
V_463 ) ;
if ( ! V_141 ) {
F_3 ( L_126 ) ;
V_30 = - V_78 ;
goto V_464;
}
F_213 ( & V_465 ) ;
F_10 ( L_127 ) ;
return 0 ;
V_464:
F_214 ( V_352 ) ;
return V_30 ;
}
static void T_6 F_215 ( void )
{
F_216 () ;
F_214 ( V_141 ) ;
F_214 ( V_352 ) ;
F_217 ( & V_465 ) ;
F_10 ( L_128 ) ;
}
