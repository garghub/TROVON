int F_1 ( struct V_1 * V_2 , unsigned int V_3 )
{
int V_4 ;
V_4 = F_2 ( V_2 , V_3 ) ;
if ( V_4 < 0 )
return V_4 ;
F_3 ( V_2 , V_3 ) ;
return 0 ;
}
static void F_4 ( struct V_5 * V_5 )
{
if ( F_5 ( & V_5 -> V_6 ) )
F_6 ( V_5 , V_7 ) ;
}
static void F_7 ( struct V_8 * V_7 )
{
struct V_9 * V_9 ;
struct V_5 * V_5 ;
struct V_10 * V_11 , * V_12 ;
struct V_13 * V_13 ;
V_9 = F_8 ( V_7 , struct V_9 , V_7 ) ;
V_13 = V_9 -> V_13 ;
F_9 ( & V_13 -> V_14 ) ;
F_10 (softif_neigh, node, node_tmp,
&softif_neigh_vid->softif_neigh_list, list) {
F_11 ( & V_5 -> V_15 ) ;
F_4 ( V_5 ) ;
}
F_12 ( & V_13 -> V_14 ) ;
F_13 ( V_9 ) ;
}
static void F_14 ( struct V_9 * V_9 )
{
if ( F_5 ( & V_9 -> V_6 ) )
F_15 ( & V_9 -> V_7 , F_7 ) ;
}
static struct V_9 * F_16 ( struct V_13 * V_13 ,
short V_16 )
{
struct V_9 * V_9 ;
struct V_10 * V_11 ;
F_17 () ;
F_18 (softif_neigh_vid, node,
&bat_priv->softif_neigh_vids, list) {
if ( V_9 -> V_16 != V_16 )
continue;
if ( ! F_19 ( & V_9 -> V_6 ) )
continue;
goto V_17;
}
V_9 = F_20 ( sizeof( * V_9 ) , V_18 ) ;
if ( ! V_9 )
goto V_17;
V_9 -> V_16 = V_16 ;
V_9 -> V_13 = V_13 ;
F_21 ( & V_9 -> V_6 , 2 ) ;
F_22 ( & V_9 -> V_19 ) ;
F_23 ( & V_9 -> V_15 ) ;
F_9 ( & V_13 -> V_20 ) ;
F_24 ( & V_9 -> V_15 ,
& V_13 -> V_21 ) ;
F_12 ( & V_13 -> V_20 ) ;
V_17:
F_25 () ;
return V_9 ;
}
static struct V_5 * F_26 ( struct V_13 * V_13 ,
const T_1 * V_22 , short V_16 )
{
struct V_9 * V_9 ;
struct V_5 * V_5 = NULL ;
struct V_10 * V_11 ;
V_9 = F_16 ( V_13 , V_16 ) ;
if ( ! V_9 )
goto V_17;
F_17 () ;
F_18 (softif_neigh, node,
&softif_neigh_vid->softif_neigh_list,
list) {
if ( ! F_27 ( V_5 -> V_22 , V_22 ) )
continue;
if ( ! F_19 ( & V_5 -> V_6 ) )
continue;
V_5 -> V_23 = V_24 ;
goto V_25;
}
V_5 = F_20 ( sizeof( * V_5 ) , V_18 ) ;
if ( ! V_5 )
goto V_25;
memcpy ( V_5 -> V_22 , V_22 , V_26 ) ;
V_5 -> V_23 = V_24 ;
F_21 ( & V_5 -> V_6 , 2 ) ;
F_23 ( & V_5 -> V_15 ) ;
F_9 ( & V_13 -> V_14 ) ;
F_24 ( & V_5 -> V_15 ,
& V_9 -> V_19 ) ;
F_12 ( & V_13 -> V_14 ) ;
V_25:
F_25 () ;
V_17:
if ( V_9 )
F_14 ( V_9 ) ;
return V_5 ;
}
static struct V_5 * F_28 (
struct V_9 * V_9 )
{
struct V_5 * V_5 ;
F_17 () ;
V_5 = F_29 ( V_9 -> V_5 ) ;
if ( V_5 && ! F_19 ( & V_5 -> V_6 ) )
V_5 = NULL ;
F_25 () ;
return V_5 ;
}
static struct V_5 * F_30 (
struct V_13 * V_13 ,
short V_16 )
{
struct V_9 * V_9 ;
struct V_5 * V_5 = NULL ;
V_9 = F_16 ( V_13 , V_16 ) ;
if ( ! V_9 )
goto V_17;
V_5 = F_28 ( V_9 ) ;
V_17:
if ( V_9 )
F_14 ( V_9 ) ;
return V_5 ;
}
static void F_31 ( struct V_13 * V_13 ,
struct V_5 * V_27 ,
short V_16 )
{
struct V_9 * V_9 ;
struct V_5 * V_28 ;
V_9 = F_16 ( V_13 , V_16 ) ;
if ( ! V_9 )
goto V_17;
F_9 ( & V_13 -> V_14 ) ;
if ( V_27 && ! F_19 ( & V_27 -> V_6 ) )
V_27 = NULL ;
V_28 = F_32 ( V_9 -> V_5 ,
1 ) ;
F_33 ( V_9 -> V_5 , V_27 ) ;
if ( ( V_28 ) && ( ! V_27 ) )
F_34 ( V_29 , V_13 ,
L_1 ,
V_16 , V_28 -> V_22 ) ;
else if ( ( V_28 ) && ( V_27 ) )
F_34 ( V_29 , V_13 ,
L_2 ,
V_16 , V_28 -> V_22 , V_27 -> V_22 ) ;
else if ( ( ! V_28 ) && ( V_27 ) )
F_34 ( V_29 , V_13 ,
L_3 ,
V_16 , V_27 -> V_22 ) ;
if ( V_28 )
F_4 ( V_28 ) ;
F_12 ( & V_13 -> V_14 ) ;
V_17:
if ( V_9 )
F_14 ( V_9 ) ;
}
static void F_35 ( struct V_13 * V_13 ,
struct V_9 * V_9 )
{
struct V_5 * V_28 ;
struct V_5 * V_5 = NULL , * V_30 ;
struct V_31 * V_32 = NULL ;
struct V_10 * V_11 ;
V_32 = F_36 ( V_13 ) ;
if ( ! V_32 )
goto V_17;
F_17 () ;
V_28 = F_29 ( V_9 -> V_5 ) ;
F_18 (softif_neigh_tmp, node,
&softif_neigh_vid->softif_neigh_list,
list) {
if ( V_30 == V_28 )
continue;
if ( memcmp ( V_32 -> V_33 -> V_34 ,
V_30 -> V_22 , V_26 ) < 0 )
continue;
if ( ! F_19 ( & V_30 -> V_6 ) )
continue;
V_5 = V_30 ;
goto V_25;
}
V_25:
F_25 () ;
V_17:
F_31 ( V_13 , V_5 , V_9 -> V_16 ) ;
if ( V_32 )
F_37 ( V_32 ) ;
if ( V_5 )
F_4 ( V_5 ) ;
}
int F_38 ( struct V_35 * V_36 , void * V_37 )
{
struct V_38 * V_33 = (struct V_38 * ) V_36 -> V_39 ;
struct V_13 * V_13 = F_39 ( V_33 ) ;
struct V_9 * V_9 ;
struct V_5 * V_5 ;
struct V_31 * V_32 ;
struct V_10 * V_11 , * V_12 ;
struct V_5 * V_40 ;
int V_41 = 0 , V_42 , V_43 ;
V_32 = F_36 ( V_13 ) ;
if ( ! V_32 ) {
V_41 = F_40 ( V_36 ,
L_4 ,
V_33 -> V_44 ) ;
goto V_17;
}
if ( V_32 -> V_45 != V_46 ) {
V_41 = F_40 ( V_36 ,
L_5 ,
V_33 -> V_44 ) ;
goto V_17;
}
F_40 ( V_36 , L_6 , V_33 -> V_44 ) ;
F_17 () ;
F_18 (softif_neigh_vid, node,
&bat_priv->softif_neigh_vids, list) {
F_40 ( V_36 , L_7 ,
L_8 , L_9 , V_9 -> V_16 ) ;
V_40 = F_28 ( V_9 ) ;
F_18 (softif_neigh, node_tmp,
&softif_neigh_vid->softif_neigh_list,
list) {
V_42 = F_41 ( V_24 -
V_5 -> V_23 ) / 1000 ;
V_43 = F_41 ( V_24 -
V_5 -> V_23 ) % 1000 ;
F_40 ( V_36 , L_10 ,
V_40 == V_5
? L_11 : L_12 , V_5 -> V_22 ,
V_42 , V_43 ) ;
}
if ( V_40 )
F_4 ( V_40 ) ;
F_40 ( V_36 , L_13 ) ;
}
F_25 () ;
V_17:
if ( V_32 )
F_37 ( V_32 ) ;
return V_41 ;
}
void F_42 ( struct V_13 * V_13 )
{
struct V_5 * V_5 , * V_40 ;
struct V_9 * V_9 ;
struct V_10 * V_11 , * V_12 , * V_47 ;
int V_48 ;
F_17 () ;
F_18 (softif_neigh_vid, node,
&bat_priv->softif_neigh_vids, list) {
if ( ! F_19 ( & V_9 -> V_6 ) )
continue;
V_40 = F_28 ( V_9 ) ;
V_48 = 0 ;
F_9 ( & V_13 -> V_14 ) ;
F_10 (softif_neigh, node_tmp, node_tmp2,
&softif_neigh_vid->softif_neigh_list,
list) {
if ( ( ! F_43 ( V_5 -> V_23 ,
V_49 ) ) &&
( F_44 ( & V_13 -> V_50 ) == V_51 ) )
continue;
if ( V_40 == V_5 ) {
F_34 ( V_29 , V_13 ,
L_14 ,
V_9 -> V_16 ,
V_5 -> V_22 ) ;
V_48 = 1 ;
}
F_11 ( & V_5 -> V_15 ) ;
F_4 ( V_5 ) ;
}
F_12 ( & V_13 -> V_14 ) ;
if ( V_48 )
F_35 ( V_13 , V_9 ) ;
if ( V_40 )
F_4 ( V_40 ) ;
F_14 ( V_9 ) ;
}
F_25 () ;
F_9 ( & V_13 -> V_20 ) ;
F_10 (softif_neigh_vid, node, node_tmp,
&bat_priv->softif_neigh_vids, list) {
if ( ! F_45 ( & V_9 -> V_19 ) )
continue;
F_11 ( & V_9 -> V_15 ) ;
F_14 ( V_9 ) ;
}
F_12 ( & V_13 -> V_20 ) ;
}
static void F_46 ( struct V_1 * V_2 , struct V_38 * V_52 ,
short V_16 )
{
struct V_13 * V_13 = F_39 ( V_52 ) ;
struct V_53 * V_53 = (struct V_53 * ) V_2 -> V_54 ;
struct V_55 * V_55 ;
struct V_5 * V_5 = NULL ;
struct V_31 * V_32 = NULL ;
struct V_5 * V_40 = NULL ;
if ( F_47 ( V_53 -> V_56 ) == V_57 )
V_55 = (struct V_55 * )
( V_2 -> V_54 + V_58 + V_59 ) ;
else
V_55 = (struct V_55 * )
( V_2 -> V_54 + V_58 ) ;
if ( V_55 -> V_60 . V_61 != V_62 )
goto V_17;
if ( V_55 -> V_60 . V_63 != V_64 )
goto V_17;
if ( ! ( V_55 -> V_65 & V_66 ) )
goto V_17;
if ( F_48 ( V_55 -> V_67 ) )
goto V_17;
V_5 = F_26 ( V_13 , V_55 -> V_67 , V_16 ) ;
if ( ! V_5 )
goto V_17;
V_40 = F_30 ( V_13 , V_16 ) ;
if ( V_40 == V_5 )
goto V_17;
V_32 = F_36 ( V_13 ) ;
if ( ! V_32 )
goto V_17;
if ( memcmp ( V_32 -> V_33 -> V_34 ,
V_5 -> V_22 , V_26 ) < 0 )
goto V_17;
if ( ! V_40 ) {
F_31 ( V_13 , V_5 , V_16 ) ;
goto V_17;
}
if ( memcmp ( V_5 -> V_22 , V_40 -> V_22 , V_26 ) < 0 )
F_31 ( V_13 , V_5 , V_16 ) ;
V_17:
F_49 ( V_2 ) ;
if ( V_5 )
F_4 ( V_5 ) ;
if ( V_40 )
F_4 ( V_40 ) ;
if ( V_32 )
F_37 ( V_32 ) ;
return;
}
static int F_50 ( struct V_38 * V_52 )
{
F_51 ( V_52 ) ;
return 0 ;
}
static int F_52 ( struct V_38 * V_52 )
{
F_53 ( V_52 ) ;
return 0 ;
}
static struct V_68 * F_54 ( struct V_38 * V_52 )
{
struct V_13 * V_13 = F_39 ( V_52 ) ;
return & V_13 -> V_69 ;
}
static int F_55 ( struct V_38 * V_52 , void * V_70 )
{
struct V_13 * V_13 = F_39 ( V_52 ) ;
struct V_71 * V_22 = V_70 ;
if ( ! F_56 ( V_22 -> V_72 ) )
return - V_73 ;
if ( F_44 ( & V_13 -> V_50 ) == V_51 ) {
F_57 ( V_13 , V_52 -> V_34 ,
L_15 , false ) ;
F_58 ( V_52 , V_22 -> V_72 , V_74 ) ;
}
memcpy ( V_52 -> V_34 , V_22 -> V_72 , V_26 ) ;
V_52 -> V_75 &= ~ V_76 ;
return 0 ;
}
static int F_59 ( struct V_38 * V_52 , int V_77 )
{
if ( ( V_77 < 68 ) || ( V_77 > F_60 ( V_52 ) ) )
return - V_78 ;
V_52 -> V_79 = V_77 ;
return 0 ;
}
static int F_61 ( struct V_1 * V_2 , struct V_38 * V_80 )
{
struct V_53 * V_53 = (struct V_53 * ) V_2 -> V_54 ;
struct V_13 * V_13 = F_39 ( V_80 ) ;
struct V_31 * V_32 = NULL ;
struct V_81 * V_81 ;
struct V_82 * V_83 ;
struct V_5 * V_40 = NULL ;
unsigned int V_84 = 0 ;
int V_85 = V_2 -> V_3 , V_41 ;
short V_16 = - 1 ;
bool V_86 = false ;
if ( F_44 ( & V_13 -> V_50 ) != V_51 )
goto V_87;
V_80 -> V_88 = V_24 ;
switch ( F_47 ( V_53 -> V_56 ) ) {
case V_57 :
V_83 = (struct V_82 * ) V_2 -> V_54 ;
V_16 = F_47 ( V_83 -> V_89 ) & V_90 ;
if ( F_47 ( V_83 -> V_91 ) != V_92 )
break;
case V_92 :
F_46 ( V_2 , V_80 , V_16 ) ;
goto V_93;
}
V_40 = F_30 ( V_13 , V_16 ) ;
if ( V_40 )
goto V_87;
F_58 ( V_80 , V_53 -> V_94 , V_2 -> V_95 ) ;
if ( F_62 ( V_53 -> V_96 ) ) {
V_86 = true ;
switch ( F_44 ( & V_13 -> V_97 ) ) {
case V_98 :
V_41 = F_63 ( V_2 , & V_84 ) ;
if ( V_41 )
goto V_87;
break;
case V_99 :
V_41 = F_63 ( V_2 , & V_84 ) ;
if ( V_41 )
V_86 = false ;
break;
case V_100 :
default:
break;
}
}
if ( V_86 ) {
V_32 = F_36 ( V_13 ) ;
if ( ! V_32 )
goto V_87;
if ( F_1 ( V_2 , sizeof( * V_81 ) ) < 0 )
goto V_87;
V_81 = (struct V_81 * ) V_2 -> V_54 ;
V_81 -> V_60 . V_61 = V_62 ;
V_81 -> V_60 . V_101 = V_102 ;
V_81 -> V_60 . V_63 = V_103 ;
memcpy ( V_81 -> V_67 ,
V_32 -> V_33 -> V_34 , V_26 ) ;
V_81 -> V_104 =
F_64 ( F_65 ( & V_13 -> V_105 ) ) ;
F_66 ( V_13 , V_2 , 1 ) ;
F_49 ( V_2 ) ;
} else {
if ( F_44 ( & V_13 -> V_97 ) != V_100 ) {
V_41 = F_67 ( V_13 , V_2 , V_53 ) ;
if ( V_41 )
goto V_87;
}
V_41 = F_68 ( V_2 , V_13 ) ;
if ( V_41 != 0 )
goto V_106;
}
V_13 -> V_69 . V_107 ++ ;
V_13 -> V_69 . V_108 += V_85 ;
goto V_93;
V_87:
F_49 ( V_2 ) ;
V_106:
V_13 -> V_69 . V_109 ++ ;
V_93:
if ( V_40 )
F_4 ( V_40 ) ;
if ( V_32 )
F_37 ( V_32 ) ;
return V_110 ;
}
void F_69 ( struct V_38 * V_80 ,
struct V_1 * V_2 , struct V_31 * V_111 ,
int V_112 )
{
struct V_13 * V_13 = F_39 ( V_80 ) ;
struct V_113 * V_113 ;
struct V_53 * V_53 ;
struct V_82 * V_83 ;
struct V_5 * V_40 = NULL ;
short V_16 = - 1 ;
int V_41 ;
if ( ! F_70 ( V_2 , V_112 ) )
goto V_87;
F_71 ( V_2 , V_112 ) ;
F_72 ( V_2 ) ;
V_53 = (struct V_53 * ) F_73 ( V_2 ) ;
switch ( F_47 ( V_53 -> V_56 ) ) {
case V_57 :
V_83 = (struct V_82 * ) V_2 -> V_54 ;
V_16 = F_47 ( V_83 -> V_89 ) & V_90 ;
if ( F_47 ( V_83 -> V_91 ) != V_92 )
break;
case V_92 :
goto V_87;
}
V_40 = F_30 ( V_13 , V_16 ) ;
if ( V_40 ) {
F_3 ( V_2 , V_112 ) ;
V_113 = (struct V_113 * ) V_2 -> V_54 ;
if ( ( V_113 -> V_60 . V_63 != V_114 ) &&
( V_113 -> V_60 . V_63 != V_115 ) )
goto V_87;
F_72 ( V_2 ) ;
memcpy ( V_113 -> V_116 ,
V_40 -> V_22 , V_26 ) ;
V_41 = F_74 ( V_2 , V_111 ) ;
if ( V_41 == V_117 )
goto V_87;
goto V_17;
}
if ( F_75 ( ! F_70 ( V_2 , V_58 ) ) )
goto V_87;
V_2 -> V_118 = F_76 ( V_2 , V_80 ) ;
V_13 -> V_69 . V_119 ++ ;
V_13 -> V_69 . V_120 += V_2 -> V_3 + sizeof( struct V_53 ) ;
V_80 -> V_121 = V_24 ;
if ( F_77 ( V_13 , V_53 -> V_94 , V_53 -> V_96 ) )
goto V_87;
F_78 ( V_2 ) ;
goto V_17;
V_87:
F_49 ( V_2 ) ;
V_17:
if ( V_40 )
F_4 ( V_40 ) ;
return;
}
static void F_79 ( struct V_38 * V_52 )
{
struct V_13 * V_122 = F_39 ( V_52 ) ;
F_80 ( V_52 ) ;
V_52 -> V_123 = & V_124 ;
V_52 -> V_125 = V_126 ;
V_52 -> V_127 = 0 ;
V_52 -> V_79 = V_128 ;
V_52 -> V_129 = V_130 ;
F_81 ( V_52 ) ;
F_82 ( V_52 , & V_131 ) ;
memset ( V_122 , 0 , sizeof( * V_122 ) ) ;
}
struct V_38 * F_83 ( const char * V_44 )
{
struct V_38 * V_80 ;
struct V_13 * V_13 ;
int V_41 ;
V_80 = F_84 ( sizeof( * V_13 ) , V_44 , F_79 ) ;
if ( ! V_80 )
goto V_17;
V_41 = F_85 ( V_80 ) ;
if ( V_41 < 0 ) {
F_86 ( L_16 ,
V_44 , V_41 ) ;
goto V_132;
}
V_13 = F_39 ( V_80 ) ;
F_21 ( & V_13 -> V_133 , 1 ) ;
F_21 ( & V_13 -> V_134 , 0 ) ;
F_21 ( & V_13 -> V_135 , 0 ) ;
F_21 ( & V_13 -> V_136 , V_137 ) ;
F_21 ( & V_13 -> V_97 , V_100 ) ;
F_21 ( & V_13 -> V_138 , 20 ) ;
F_21 ( & V_13 -> V_139 , 41 ) ;
F_21 ( & V_13 -> V_140 , 1000 ) ;
F_21 ( & V_13 -> V_141 , 10 ) ;
F_21 ( & V_13 -> V_142 , 0 ) ;
F_21 ( & V_13 -> V_143 , 1 ) ;
F_21 ( & V_13 -> V_144 , V_145 ) ;
F_21 ( & V_13 -> V_146 , V_147 ) ;
F_21 ( & V_13 -> V_50 , V_148 ) ;
F_21 ( & V_13 -> V_105 , 1 ) ;
F_21 ( & V_13 -> V_149 , 0 ) ;
F_21 ( & V_13 -> V_150 , 0 ) ;
F_21 ( & V_13 -> V_151 , 0 ) ;
V_13 -> V_152 = NULL ;
V_13 -> V_153 = 0 ;
V_13 -> V_154 = false ;
V_13 -> V_32 = NULL ;
V_13 -> V_155 = 0 ;
V_41 = F_87 ( V_13 , V_156 ) ;
if ( V_41 < 0 )
goto V_157;
V_41 = F_88 ( V_80 ) ;
if ( V_41 < 0 )
goto V_157;
V_41 = F_89 ( V_80 ) ;
if ( V_41 < 0 )
goto V_158;
V_41 = F_90 ( V_80 ) ;
if ( V_41 < 0 )
goto V_159;
return V_80 ;
V_159:
F_91 ( V_80 ) ;
V_158:
F_92 ( V_80 ) ;
V_157:
F_93 ( V_80 ) ;
return NULL ;
V_132:
V_126 ( V_80 ) ;
V_17:
return NULL ;
}
void F_94 ( struct V_38 * V_80 )
{
F_91 ( V_80 ) ;
F_92 ( V_80 ) ;
F_95 ( V_80 ) ;
F_93 ( V_80 ) ;
}
int F_96 ( const struct V_38 * V_33 )
{
if ( V_33 -> V_123 -> V_160 == F_61 )
return 1 ;
return 0 ;
}
static int F_97 ( struct V_38 * V_52 , struct V_161 * V_162 )
{
V_162 -> V_163 = 0 ;
V_162 -> V_164 = 0 ;
F_98 ( V_162 , V_165 ) ;
V_162 -> V_166 = V_167 ;
V_162 -> V_168 = V_169 ;
V_162 -> V_170 = 0 ;
V_162 -> V_171 = V_172 ;
V_162 -> V_173 = V_174 ;
V_162 -> V_175 = 0 ;
V_162 -> V_176 = 0 ;
return 0 ;
}
static void F_99 ( struct V_38 * V_52 ,
struct V_177 * V_178 )
{
strcpy ( V_178 -> V_179 , L_17 ) ;
strcpy ( V_178 -> V_61 , V_180 ) ;
strcpy ( V_178 -> V_181 , L_18 ) ;
strcpy ( V_178 -> V_182 , L_19 ) ;
}
static T_2 F_100 ( struct V_38 * V_52 )
{
return - V_183 ;
}
static void F_101 ( struct V_38 * V_52 , T_2 V_184 )
{
}
static T_2 F_102 ( struct V_38 * V_52 )
{
return 1 ;
}
