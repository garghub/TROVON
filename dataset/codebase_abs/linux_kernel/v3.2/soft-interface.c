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
L_2
L_3 , V_16 , V_28 -> V_22 , V_27 -> V_22 ) ;
else if ( ( ! V_28 ) && ( V_27 ) )
F_34 ( V_29 , V_13 ,
L_4 ,
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
V_41 = F_40 ( V_36 , L_5
L_6 ,
V_33 -> V_44 ) ;
goto V_17;
}
if ( V_32 -> V_45 != V_46 ) {
V_41 = F_40 ( V_36 , L_7
L_8 ,
V_33 -> V_44 ) ;
goto V_17;
}
F_40 ( V_36 , L_9 , V_33 -> V_44 ) ;
F_17 () ;
F_18 (softif_neigh_vid, node,
&bat_priv->softif_neigh_vids, list) {
F_40 ( V_36 , L_10 ,
L_11 , L_12 , V_9 -> V_16 ) ;
V_40 = F_28 ( V_9 ) ;
F_18 (softif_neigh, node_tmp,
&softif_neigh_vid->softif_neigh_list,
list) {
V_42 = F_41 ( V_24 -
V_5 -> V_23 ) / 1000 ;
V_43 = F_41 ( V_24 -
V_5 -> V_23 ) % 1000 ;
F_40 ( V_36 , L_13 ,
V_40 == V_5
? L_14 : L_15 , V_5 -> V_22 ,
V_42 , V_43 ) ;
}
if ( V_40 )
F_4 ( V_40 ) ;
F_40 ( V_36 , L_16 ) ;
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
if ( ( ! F_43 ( V_24 , V_5 -> V_23 +
F_44 ( V_49 ) ) ) &&
( F_45 ( & V_13 -> V_50 ) == V_51 ) )
continue;
if ( V_40 == V_5 ) {
F_34 ( V_29 , V_13 ,
L_17
L_18 ,
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
if ( ! F_46 ( & V_9 -> V_19 ) )
continue;
F_11 ( & V_9 -> V_15 ) ;
F_14 ( V_9 ) ;
}
F_12 ( & V_13 -> V_20 ) ;
}
static void F_47 ( struct V_1 * V_2 , struct V_38 * V_52 ,
short V_16 )
{
struct V_13 * V_13 = F_39 ( V_52 ) ;
struct V_53 * V_53 = (struct V_53 * ) V_2 -> V_54 ;
struct V_55 * V_55 ;
struct V_5 * V_5 = NULL ;
struct V_31 * V_32 = NULL ;
struct V_5 * V_40 = NULL ;
if ( F_48 ( V_53 -> V_56 ) == V_57 )
V_55 = (struct V_55 * )
( V_2 -> V_54 + V_58 + V_59 ) ;
else
V_55 = (struct V_55 * )
( V_2 -> V_54 + V_58 ) ;
if ( V_55 -> V_60 != V_61 )
goto V_17;
if ( V_55 -> V_62 != V_63 )
goto V_17;
if ( ! ( V_55 -> V_64 & V_65 ) )
goto V_17;
if ( F_49 ( V_55 -> V_66 ) )
goto V_17;
V_5 = F_26 ( V_13 , V_55 -> V_66 , V_16 ) ;
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
F_50 ( V_2 ) ;
if ( V_5 )
F_4 ( V_5 ) ;
if ( V_40 )
F_4 ( V_40 ) ;
if ( V_32 )
F_37 ( V_32 ) ;
return;
}
static int F_51 ( struct V_38 * V_52 )
{
F_52 ( V_52 ) ;
return 0 ;
}
static int F_53 ( struct V_38 * V_52 )
{
F_54 ( V_52 ) ;
return 0 ;
}
static struct V_67 * F_55 ( struct V_38 * V_52 )
{
struct V_13 * V_13 = F_39 ( V_52 ) ;
return & V_13 -> V_68 ;
}
static int F_56 ( struct V_38 * V_52 , void * V_69 )
{
struct V_13 * V_13 = F_39 ( V_52 ) ;
struct V_70 * V_22 = V_69 ;
if ( ! F_57 ( V_22 -> V_71 ) )
return - V_72 ;
if ( F_45 ( & V_13 -> V_50 ) == V_51 ) {
F_58 ( V_13 , V_52 -> V_34 ,
L_19 , false ) ;
F_59 ( V_52 , V_22 -> V_71 , V_73 ) ;
}
memcpy ( V_52 -> V_34 , V_22 -> V_71 , V_26 ) ;
return 0 ;
}
static int F_60 ( struct V_38 * V_52 , int V_74 )
{
if ( ( V_74 < 68 ) || ( V_74 > F_61 ( V_52 ) ) )
return - V_75 ;
V_52 -> V_76 = V_74 ;
return 0 ;
}
static int F_62 ( struct V_1 * V_2 , struct V_38 * V_77 )
{
struct V_53 * V_53 = (struct V_53 * ) V_2 -> V_54 ;
struct V_13 * V_13 = F_39 ( V_77 ) ;
struct V_31 * V_32 = NULL ;
struct V_78 * V_78 ;
struct V_79 * V_80 ;
struct V_5 * V_40 = NULL ;
struct V_81 * V_81 = NULL ;
int V_82 = V_2 -> V_3 , V_41 ;
short V_16 = - 1 ;
bool V_83 ;
if ( F_45 ( & V_13 -> V_50 ) != V_51 )
goto V_84;
V_77 -> V_85 = V_24 ;
switch ( F_48 ( V_53 -> V_56 ) ) {
case V_57 :
V_80 = (struct V_79 * ) V_2 -> V_54 ;
V_16 = F_48 ( V_80 -> V_86 ) & V_87 ;
if ( F_48 ( V_80 -> V_88 ) != V_89 )
break;
case V_89 :
F_47 ( V_2 , V_77 , V_16 ) ;
goto V_90;
}
V_40 = F_30 ( V_13 , V_16 ) ;
if ( V_40 )
goto V_84;
F_59 ( V_77 , V_53 -> V_91 , V_2 -> V_92 ) ;
V_81 = F_63 ( V_13 , V_53 -> V_91 ,
V_53 -> V_93 ) ;
V_83 = F_64 ( V_53 -> V_93 ) ;
if ( V_83 || ( V_81 && V_81 -> V_94 ) ) {
V_41 = F_65 ( V_13 , V_2 , V_81 ) ;
if ( V_41 < 0 )
goto V_84;
if ( V_41 )
V_83 = false ;
}
if ( V_83 ) {
V_32 = F_36 ( V_13 ) ;
if ( ! V_32 )
goto V_84;
if ( F_1 ( V_2 , sizeof( * V_78 ) ) < 0 )
goto V_84;
V_78 = (struct V_78 * ) V_2 -> V_54 ;
V_78 -> V_60 = V_61 ;
V_78 -> V_95 = V_96 ;
V_78 -> V_62 = V_97 ;
memcpy ( V_78 -> V_66 ,
V_32 -> V_33 -> V_34 , V_26 ) ;
V_78 -> V_98 =
F_66 ( F_67 ( & V_13 -> V_99 ) ) ;
F_68 ( V_13 , V_2 , 1 ) ;
F_50 ( V_2 ) ;
} else {
V_41 = F_69 ( V_2 , V_13 ) ;
if ( V_41 != 0 )
goto V_100;
}
V_13 -> V_68 . V_101 ++ ;
V_13 -> V_68 . V_102 += V_82 ;
goto V_90;
V_84:
F_50 ( V_2 ) ;
V_100:
V_13 -> V_68 . V_103 ++ ;
V_90:
if ( V_40 )
F_4 ( V_40 ) ;
if ( V_32 )
F_37 ( V_32 ) ;
if ( V_81 )
F_70 ( V_81 ) ;
return V_104 ;
}
void F_71 ( struct V_38 * V_77 ,
struct V_1 * V_2 , struct V_31 * V_105 ,
int V_106 )
{
struct V_13 * V_13 = F_39 ( V_77 ) ;
struct V_107 * V_107 ;
struct V_53 * V_53 ;
struct V_79 * V_80 ;
struct V_5 * V_40 = NULL ;
short V_16 = - 1 ;
int V_41 ;
if ( ! F_72 ( V_2 , V_106 ) )
goto V_84;
F_73 ( V_2 , V_106 ) ;
F_74 ( V_2 ) ;
V_53 = (struct V_53 * ) F_75 ( V_2 ) ;
switch ( F_48 ( V_53 -> V_56 ) ) {
case V_57 :
V_80 = (struct V_79 * ) V_2 -> V_54 ;
V_16 = F_48 ( V_80 -> V_86 ) & V_87 ;
if ( F_48 ( V_80 -> V_88 ) != V_89 )
break;
case V_89 :
goto V_84;
}
V_40 = F_30 ( V_13 , V_16 ) ;
if ( V_40 ) {
F_3 ( V_2 , V_106 ) ;
V_107 = (struct V_107 * ) V_2 -> V_54 ;
if ( ( V_107 -> V_62 != V_108 ) &&
( V_107 -> V_62 != V_109 ) )
goto V_84;
F_74 ( V_2 ) ;
memcpy ( V_107 -> V_110 ,
V_40 -> V_22 , V_26 ) ;
V_41 = F_76 ( V_2 , V_105 ) ;
if ( V_41 == V_111 )
goto V_84;
goto V_17;
}
if ( F_77 ( ! F_72 ( V_2 , V_58 ) ) )
goto V_84;
V_2 -> V_112 = F_78 ( V_2 , V_77 ) ;
V_13 -> V_68 . V_113 ++ ;
V_13 -> V_68 . V_114 += V_2 -> V_3 + sizeof( struct V_53 ) ;
V_77 -> V_115 = V_24 ;
if ( F_79 ( V_13 , V_53 -> V_91 , V_53 -> V_93 ) )
goto V_84;
F_80 ( V_2 ) ;
goto V_17;
V_84:
F_50 ( V_2 ) ;
V_17:
if ( V_40 )
F_4 ( V_40 ) ;
return;
}
static void F_81 ( struct V_38 * V_52 )
{
struct V_13 * V_116 = F_39 ( V_52 ) ;
char V_34 [ V_26 ] ;
F_82 ( V_52 ) ;
V_52 -> V_117 = & V_118 ;
V_52 -> V_119 = V_120 ;
V_52 -> V_121 = 0 ;
V_52 -> V_76 = V_122 ;
V_52 -> V_123 = V_124 ;
F_83 ( V_34 ) ;
memcpy ( V_52 -> V_34 , V_34 , V_26 ) ;
F_84 ( V_52 , & V_125 ) ;
memset ( V_116 , 0 , sizeof( * V_116 ) ) ;
}
struct V_38 * F_85 ( const char * V_44 )
{
struct V_38 * V_77 ;
struct V_13 * V_13 ;
int V_41 ;
V_77 = F_86 ( sizeof( * V_13 ) , V_44 , F_81 ) ;
if ( ! V_77 )
goto V_17;
V_41 = F_87 ( V_77 ) ;
if ( V_41 < 0 ) {
F_88 ( L_20 ,
V_44 , V_41 ) ;
goto V_126;
}
V_13 = F_39 ( V_77 ) ;
F_21 ( & V_13 -> V_127 , 1 ) ;
F_21 ( & V_13 -> V_128 , 0 ) ;
F_21 ( & V_13 -> V_129 , 0 ) ;
F_21 ( & V_13 -> V_130 , V_131 ) ;
F_21 ( & V_13 -> V_132 , V_133 ) ;
F_21 ( & V_13 -> V_134 , 20 ) ;
F_21 ( & V_13 -> V_135 , 41 ) ;
F_21 ( & V_13 -> V_136 , 1000 ) ;
F_21 ( & V_13 -> V_137 , 10 ) ;
F_21 ( & V_13 -> V_138 , 0 ) ;
F_21 ( & V_13 -> V_139 , 1 ) ;
F_21 ( & V_13 -> V_140 , V_141 ) ;
F_21 ( & V_13 -> V_142 , V_143 ) ;
F_21 ( & V_13 -> V_50 , V_144 ) ;
F_21 ( & V_13 -> V_99 , 1 ) ;
F_21 ( & V_13 -> V_145 , 0 ) ;
F_21 ( & V_13 -> V_146 , 0 ) ;
F_21 ( & V_13 -> V_147 , 0 ) ;
V_13 -> V_148 = NULL ;
V_13 -> V_149 = 0 ;
V_13 -> V_150 = false ;
V_13 -> V_32 = NULL ;
V_13 -> V_151 = 0 ;
V_41 = F_89 ( V_77 ) ;
if ( V_41 < 0 )
goto V_152;
V_41 = F_90 ( V_77 ) ;
if ( V_41 < 0 )
goto V_153;
V_41 = F_91 ( V_77 ) ;
if ( V_41 < 0 )
goto V_154;
return V_77 ;
V_154:
F_92 ( V_77 ) ;
V_153:
F_93 ( V_77 ) ;
V_152:
F_94 ( V_77 ) ;
return NULL ;
V_126:
V_120 ( V_77 ) ;
V_17:
return NULL ;
}
void F_95 ( struct V_38 * V_77 )
{
F_92 ( V_77 ) ;
F_93 ( V_77 ) ;
F_96 ( V_77 ) ;
F_97 ( V_77 ) ;
}
int F_98 ( const struct V_38 * V_33 )
{
if ( V_33 -> V_117 -> V_155 == F_62 )
return 1 ;
return 0 ;
}
static int F_99 ( struct V_38 * V_52 , struct V_156 * V_157 )
{
V_157 -> V_158 = 0 ;
V_157 -> V_159 = 0 ;
F_100 ( V_157 , V_160 ) ;
V_157 -> V_161 = V_162 ;
V_157 -> V_163 = V_164 ;
V_157 -> V_165 = 0 ;
V_157 -> V_166 = V_167 ;
V_157 -> V_168 = V_169 ;
V_157 -> V_170 = 0 ;
V_157 -> V_171 = 0 ;
return 0 ;
}
static void F_101 ( struct V_38 * V_52 ,
struct V_172 * V_173 )
{
strcpy ( V_173 -> V_174 , L_21 ) ;
strcpy ( V_173 -> V_60 , V_175 ) ;
strcpy ( V_173 -> V_176 , L_22 ) ;
strcpy ( V_173 -> V_177 , L_23 ) ;
}
static T_2 F_102 ( struct V_38 * V_52 )
{
return - V_178 ;
}
static void F_103 ( struct V_38 * V_52 , T_2 V_179 )
{
}
static T_2 F_104 ( struct V_38 * V_52 )
{
return 1 ;
}
