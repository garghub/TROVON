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
V_9 = F_20 ( sizeof( struct V_9 ) ,
V_18 ) ;
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
T_1 * V_22 , short V_16 )
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
V_5 = F_20 ( sizeof( struct V_5 ) , V_18 ) ;
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
V_28 = V_9 -> V_5 ;
F_32 ( V_9 -> V_5 , V_27 ) ;
if ( ( V_28 ) && ( ! V_27 ) )
F_33 ( V_29 , V_13 ,
L_1 ,
V_16 , V_28 -> V_22 ) ;
else if ( ( V_28 ) && ( V_27 ) )
F_33 ( V_29 , V_13 ,
L_2
L_3 , V_16 , V_28 -> V_22 , V_27 -> V_22 ) ;
else if ( ( ! V_28 ) && ( V_27 ) )
F_33 ( V_29 , V_13 ,
L_4 ,
V_16 , V_27 -> V_22 ) ;
if ( V_28 )
F_4 ( V_28 ) ;
F_12 ( & V_13 -> V_14 ) ;
V_17:
if ( V_9 )
F_14 ( V_9 ) ;
}
static void F_34 ( struct V_13 * V_13 ,
struct V_9 * V_9 )
{
struct V_5 * V_28 ;
struct V_5 * V_5 = NULL , * V_30 ;
struct V_31 * V_32 = NULL ;
struct V_10 * V_11 ;
V_32 = F_35 ( V_13 ) ;
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
F_36 ( V_32 ) ;
if ( V_5 )
F_4 ( V_5 ) ;
}
int F_37 ( struct V_35 * V_36 , void * V_37 )
{
struct V_38 * V_33 = (struct V_38 * ) V_36 -> V_39 ;
struct V_13 * V_13 = F_38 ( V_33 ) ;
struct V_9 * V_9 ;
struct V_5 * V_5 ;
struct V_31 * V_32 ;
struct V_10 * V_11 , * V_12 ;
struct V_5 * V_40 ;
int V_41 = 0 , V_42 , V_43 ;
V_32 = F_35 ( V_13 ) ;
if ( ! V_32 ) {
V_41 = F_39 ( V_36 , L_5
L_6 ,
V_33 -> V_44 ) ;
goto V_17;
}
if ( V_32 -> V_45 != V_46 ) {
V_41 = F_39 ( V_36 , L_7
L_8 ,
V_33 -> V_44 ) ;
goto V_17;
}
F_39 ( V_36 , L_9 , V_33 -> V_44 ) ;
F_17 () ;
F_18 (softif_neigh_vid, node,
&bat_priv->softif_neigh_vids, list) {
F_39 ( V_36 , L_10 ,
L_11 , L_12 , V_9 -> V_16 ) ;
V_40 = F_28 ( V_9 ) ;
F_18 (softif_neigh, node_tmp,
&softif_neigh_vid->softif_neigh_list,
list) {
V_42 = F_40 ( V_24 -
V_5 -> V_23 ) / 1000 ;
V_43 = F_40 ( V_24 -
V_5 -> V_23 ) % 1000 ;
F_39 ( V_36 , L_13 ,
V_40 == V_5
? L_14 : L_15 , V_5 -> V_22 ,
V_42 , V_43 ) ;
}
if ( V_40 )
F_4 ( V_40 ) ;
F_39 ( V_36 , L_16 ) ;
}
F_25 () ;
V_17:
if ( V_32 )
F_36 ( V_32 ) ;
return V_41 ;
}
void F_41 ( struct V_13 * V_13 )
{
struct V_5 * V_5 , * V_40 ;
struct V_9 * V_9 ;
struct V_10 * V_11 , * V_12 , * V_47 ;
char V_48 ;
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
if ( ( ! F_42 ( V_24 , V_5 -> V_23 +
F_43 ( V_49 ) ) ) &&
( F_44 ( & V_13 -> V_50 ) == V_51 ) )
continue;
if ( V_40 == V_5 ) {
F_33 ( V_29 , V_13 ,
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
F_34 ( V_13 , V_9 ) ;
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
struct V_13 * V_13 = F_38 ( V_52 ) ;
struct V_53 * V_53 = (struct V_53 * ) V_2 -> V_54 ;
struct V_55 * V_55 ;
struct V_5 * V_5 = NULL ;
struct V_31 * V_32 = NULL ;
struct V_5 * V_40 = NULL ;
if ( F_47 ( V_53 -> V_56 ) == V_57 )
V_55 = (struct V_55 * )
( V_2 -> V_54 + V_58 + V_59 ) ;
else
V_55 = (struct V_55 * ) ( V_2 -> V_54 + V_58 ) ;
if ( V_55 -> V_60 != V_61 )
goto V_17;
if ( V_55 -> V_62 != V_63 )
goto V_17;
if ( ! ( V_55 -> V_64 & V_65 ) )
goto V_17;
if ( F_48 ( V_55 -> V_66 ) )
goto V_17;
V_5 = F_26 ( V_13 , V_55 -> V_66 , V_16 ) ;
if ( ! V_5 )
goto V_17;
V_40 = F_30 ( V_13 , V_16 ) ;
if ( V_40 == V_5 )
goto V_17;
V_32 = F_35 ( V_13 ) ;
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
F_36 ( V_32 ) ;
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
static struct V_67 * F_54 ( struct V_38 * V_52 )
{
struct V_13 * V_13 = F_38 ( V_52 ) ;
return & V_13 -> V_68 ;
}
static int F_55 ( struct V_38 * V_52 , void * V_69 )
{
struct V_13 * V_13 = F_38 ( V_52 ) ;
struct V_70 * V_22 = V_69 ;
if ( ! F_56 ( V_22 -> V_71 ) )
return - V_72 ;
if ( F_44 ( & V_13 -> V_50 ) == V_51 ) {
F_57 ( V_13 , V_52 -> V_34 ,
L_19 ) ;
F_58 ( V_52 , V_22 -> V_71 ) ;
}
memcpy ( V_52 -> V_34 , V_22 -> V_71 , V_26 ) ;
return 0 ;
}
static int F_59 ( struct V_38 * V_52 , int V_73 )
{
if ( ( V_73 < 68 ) || ( V_73 > F_60 ( V_52 ) ) )
return - V_74 ;
V_52 -> V_75 = V_73 ;
return 0 ;
}
int F_61 ( struct V_1 * V_2 , struct V_38 * V_76 )
{
struct V_53 * V_53 = (struct V_53 * ) V_2 -> V_54 ;
struct V_13 * V_13 = F_38 ( V_76 ) ;
struct V_31 * V_32 = NULL ;
struct V_77 * V_77 ;
struct V_78 * V_79 ;
struct V_5 * V_40 = NULL ;
int V_80 = V_2 -> V_3 , V_41 ;
short V_16 = - 1 ;
bool V_81 = false ;
if ( F_44 ( & V_13 -> V_50 ) != V_51 )
goto V_82;
V_76 -> V_83 = V_24 ;
switch ( F_47 ( V_53 -> V_56 ) ) {
case V_57 :
V_79 = (struct V_78 * ) V_2 -> V_54 ;
V_16 = F_47 ( V_79 -> V_84 ) & V_85 ;
if ( F_47 ( V_79 -> V_86 ) != V_87 )
break;
case V_87 :
F_46 ( V_2 , V_76 , V_16 ) ;
goto V_88;
}
V_40 = F_30 ( V_13 , V_16 ) ;
if ( V_40 )
goto V_82;
F_58 ( V_76 , V_53 -> V_89 ) ;
if ( F_62 ( V_53 -> V_90 ) ) {
V_41 = F_63 ( V_13 , V_2 ) ;
if ( V_41 < 0 )
goto V_82;
if ( V_41 == 0 )
V_81 = true ;
}
if ( V_81 ) {
V_32 = F_35 ( V_13 ) ;
if ( ! V_32 )
goto V_82;
if ( F_1 ( V_2 , sizeof( struct V_77 ) ) < 0 )
goto V_82;
V_77 = (struct V_77 * ) V_2 -> V_54 ;
V_77 -> V_60 = V_61 ;
V_77 -> V_91 = V_92 ;
V_77 -> V_62 = V_93 ;
memcpy ( V_77 -> V_66 ,
V_32 -> V_33 -> V_34 , V_26 ) ;
V_77 -> V_94 =
F_64 ( F_65 ( & V_13 -> V_95 ) ) ;
F_66 ( V_13 , V_2 ) ;
F_49 ( V_2 ) ;
} else {
V_41 = F_67 ( V_2 , V_13 ) ;
if ( V_41 != 0 )
goto V_96;
}
V_13 -> V_68 . V_97 ++ ;
V_13 -> V_68 . V_98 += V_80 ;
goto V_88;
V_82:
F_49 ( V_2 ) ;
V_96:
V_13 -> V_68 . V_99 ++ ;
V_88:
if ( V_40 )
F_4 ( V_40 ) ;
if ( V_32 )
F_36 ( V_32 ) ;
return V_100 ;
}
void F_68 ( struct V_38 * V_76 ,
struct V_1 * V_2 , struct V_31 * V_101 ,
int V_102 )
{
struct V_13 * V_13 = F_38 ( V_76 ) ;
struct V_103 * V_103 ;
struct V_53 * V_53 ;
struct V_78 * V_79 ;
struct V_5 * V_40 = NULL ;
short V_16 = - 1 ;
int V_41 ;
if ( ! F_69 ( V_2 , V_102 ) )
goto V_82;
F_70 ( V_2 , V_102 ) ;
F_71 ( V_2 ) ;
V_53 = (struct V_53 * ) F_72 ( V_2 ) ;
switch ( F_47 ( V_53 -> V_56 ) ) {
case V_57 :
V_79 = (struct V_78 * ) V_2 -> V_54 ;
V_16 = F_47 ( V_79 -> V_84 ) & V_85 ;
if ( F_47 ( V_79 -> V_86 ) != V_87 )
break;
case V_87 :
goto V_82;
}
V_40 = F_30 ( V_13 , V_16 ) ;
if ( V_40 ) {
F_3 ( V_2 , V_102 ) ;
V_103 = (struct V_103 * ) V_2 -> V_54 ;
if ( ( V_103 -> V_62 != V_104 ) &&
( V_103 -> V_62 != V_105 ) )
goto V_82;
F_71 ( V_2 ) ;
memcpy ( V_103 -> V_106 ,
V_40 -> V_22 , V_26 ) ;
V_41 = F_73 ( V_2 , V_101 ) ;
if ( V_41 == V_107 )
goto V_82;
goto V_17;
}
if ( F_74 ( ! F_69 ( V_2 , V_58 ) ) )
goto V_82;
V_2 -> V_108 = F_75 ( V_2 , V_76 ) ;
V_13 -> V_68 . V_109 ++ ;
V_13 -> V_68 . V_110 += V_2 -> V_3 + sizeof( struct V_53 ) ;
V_76 -> V_111 = V_24 ;
F_76 ( V_2 ) ;
goto V_17;
V_82:
F_49 ( V_2 ) ;
V_17:
if ( V_40 )
F_4 ( V_40 ) ;
return;
}
static void F_77 ( struct V_38 * V_52 )
{
struct V_13 * V_112 = F_38 ( V_52 ) ;
char V_34 [ V_26 ] ;
F_78 ( V_52 ) ;
#ifdef F_79
V_52 -> V_113 = & V_114 ;
#else
V_52 -> V_115 = F_50 ;
V_52 -> V_116 = F_52 ;
V_52 -> V_117 = F_54 ;
V_52 -> V_118 = F_55 ;
V_52 -> V_119 = F_59 ;
V_52 -> V_120 = F_61 ;
#endif
V_52 -> V_121 = V_122 ;
V_52 -> V_123 = 0 ;
V_52 -> V_75 = V_124 ;
V_52 -> V_125 = V_126 ;
F_80 ( V_34 ) ;
memcpy ( V_52 -> V_34 , V_34 , V_26 ) ;
F_81 ( V_52 , & V_127 ) ;
memset ( V_112 , 0 , sizeof( struct V_13 ) ) ;
}
struct V_38 * F_82 ( char * V_44 )
{
struct V_38 * V_76 ;
struct V_13 * V_13 ;
int V_41 ;
V_76 = F_83 ( sizeof( struct V_13 ) , V_44 ,
F_77 ) ;
if ( ! V_76 ) {
F_84 ( L_20 , V_44 ) ;
goto V_17;
}
V_41 = F_85 ( V_76 ) ;
if ( V_41 < 0 ) {
F_84 ( L_21 ,
V_44 , V_41 ) ;
goto V_128;
}
V_13 = F_38 ( V_76 ) ;
F_21 ( & V_13 -> V_129 , 1 ) ;
F_21 ( & V_13 -> V_130 , 0 ) ;
F_21 ( & V_13 -> V_131 , V_132 ) ;
F_21 ( & V_13 -> V_133 , V_134 ) ;
F_21 ( & V_13 -> V_135 , 20 ) ;
F_21 ( & V_13 -> V_136 , 41 ) ;
F_21 ( & V_13 -> V_137 , 1000 ) ;
F_21 ( & V_13 -> V_138 , 10 ) ;
F_21 ( & V_13 -> V_139 , 0 ) ;
F_21 ( & V_13 -> V_140 , 1 ) ;
F_21 ( & V_13 -> V_141 , V_142 ) ;
F_21 ( & V_13 -> V_143 , V_144 ) ;
F_21 ( & V_13 -> V_50 , V_145 ) ;
F_21 ( & V_13 -> V_95 , 1 ) ;
F_21 ( & V_13 -> V_146 , 0 ) ;
V_13 -> V_32 = NULL ;
V_13 -> V_147 = 0 ;
V_41 = F_86 ( V_76 ) ;
if ( V_41 < 0 )
goto V_148;
V_41 = F_87 ( V_76 ) ;
if ( V_41 < 0 )
goto V_149;
V_41 = F_88 ( V_76 ) ;
if ( V_41 < 0 )
goto V_150;
return V_76 ;
V_150:
F_89 ( V_76 ) ;
V_149:
F_90 ( V_76 ) ;
V_148:
F_91 ( V_76 ) ;
return NULL ;
V_128:
V_122 ( V_76 ) ;
V_17:
return NULL ;
}
void F_92 ( struct V_38 * V_76 )
{
F_89 ( V_76 ) ;
F_90 ( V_76 ) ;
F_93 ( V_76 ) ;
F_94 ( V_76 ) ;
}
int F_95 ( struct V_38 * V_33 )
{
#ifdef F_79
if ( V_33 -> V_113 -> V_151 == F_61 )
return 1 ;
#else
if ( V_33 -> V_120 == F_61 )
return 1 ;
#endif
return 0 ;
}
static int F_96 ( struct V_38 * V_52 , struct V_152 * V_153 )
{
V_153 -> V_154 = 0 ;
V_153 -> V_155 = 0 ;
F_97 ( V_153 , V_156 ) ;
V_153 -> V_157 = V_158 ;
V_153 -> V_159 = V_160 ;
V_153 -> V_161 = 0 ;
V_153 -> V_162 = V_163 ;
V_153 -> V_164 = V_165 ;
V_153 -> V_166 = 0 ;
V_153 -> V_167 = 0 ;
return 0 ;
}
static void F_98 ( struct V_38 * V_52 ,
struct V_168 * V_169 )
{
strcpy ( V_169 -> V_170 , L_22 ) ;
strcpy ( V_169 -> V_60 , V_171 ) ;
strcpy ( V_169 -> V_172 , L_23 ) ;
strcpy ( V_169 -> V_173 , L_24 ) ;
}
static T_2 F_99 ( struct V_38 * V_52 )
{
return - V_174 ;
}
static void F_100 ( struct V_38 * V_52 , T_2 V_175 )
{
}
static T_2 F_101 ( struct V_38 * V_52 )
{
return 1 ;
}
