static int F_1 ( struct V_1 * V_2 ,
unsigned long V_3 , void * V_4 )
{
struct V_5 * V_6 = V_4 ;
struct V_7 * V_8 = V_6 -> V_8 ;
if ( V_8 -> V_9 -> V_10 != V_11 )
return V_12 ;
switch ( V_3 ) {
case V_13 :
F_2 ( V_8 ) ;
break;
case V_14 :
F_3 ( V_8 ) ;
F_2 ( V_8 ) ;
break;
case V_15 :
F_3 ( V_8 ) ;
break;
}
return V_12 ;
}
int V_11 ( struct V_7 * V_8 )
{
struct V_16 * V_17 = F_4 ( V_8 ) ;
F_5 ( V_17 , L_1 ) ;
F_6 ( V_8 ) ;
F_7 ( V_18 , & V_17 -> V_19 ) ;
V_17 -> V_20 = false ;
if ( F_8 ( V_8 ) ) {
if ( ! F_9 ( V_21 , & V_17 -> V_19 ) )
return 0 ;
goto V_22;
}
F_10 ( V_8 ) ;
if ( ! F_9 ( V_23 , & V_17 -> V_19 ) ) {
struct V_16 * V_24 ;
F_11 ( & V_17 -> V_25 ) ;
F_12 (cpriv, &priv->child_intfs, list) {
int V_19 ;
V_19 = V_24 -> V_8 -> V_19 ;
if ( V_19 & V_26 )
continue;
F_13 ( V_24 -> V_8 , V_19 | V_26 ) ;
}
F_14 ( & V_17 -> V_25 ) ;
}
F_15 ( V_8 ) ;
return 0 ;
V_22:
F_16 ( V_18 , & V_17 -> V_19 ) ;
return - V_27 ;
}
static int F_17 ( struct V_7 * V_8 )
{
struct V_16 * V_17 = F_4 ( V_8 ) ;
F_5 ( V_17 , L_2 ) ;
F_16 ( V_18 , & V_17 -> V_19 ) ;
F_18 ( V_8 ) ;
F_19 ( V_8 ) ;
F_20 ( V_8 ) ;
if ( ! F_9 ( V_23 , & V_17 -> V_19 ) ) {
struct V_16 * V_24 ;
F_11 ( & V_17 -> V_25 ) ;
F_12 (cpriv, &priv->child_intfs, list) {
int V_19 ;
V_19 = V_24 -> V_8 -> V_19 ;
if ( ! ( V_19 & V_26 ) )
continue;
F_13 ( V_24 -> V_8 , V_19 & ~ V_26 ) ;
}
F_14 ( & V_17 -> V_25 ) ;
}
return 0 ;
}
static void F_21 ( struct V_7 * V_8 )
{
F_22 ( V_8 ) ;
}
static T_1 F_23 ( struct V_7 * V_8 , T_1 V_28 )
{
struct V_16 * V_17 = F_4 ( V_8 ) ;
if ( F_9 ( V_29 , & V_17 -> V_19 ) )
V_28 &= ~ ( V_30 | V_31 ) ;
return V_28 ;
}
static int F_24 ( struct V_7 * V_8 , int V_32 )
{
struct V_16 * V_17 = F_4 ( V_8 ) ;
int V_33 = 0 ;
if ( F_25 ( V_8 ) ) {
if ( V_32 > F_26 ( V_8 ) )
return - V_27 ;
if ( V_32 > V_17 -> V_34 )
F_27 ( V_17 , L_3 ,
V_17 -> V_34 ) ;
V_8 -> V_35 = V_32 ;
return 0 ;
}
if ( V_32 > F_28 ( V_17 -> V_36 ) )
return - V_27 ;
V_17 -> V_37 = V_32 ;
if ( V_17 -> V_34 < V_17 -> V_37 )
F_5 ( V_17 , L_4
L_5 , V_17 -> V_34 ) ;
V_32 = F_29 ( V_17 -> V_34 , V_17 -> V_37 ) ;
if ( V_17 -> V_38 -> V_39 ) {
bool V_40 = F_30 ( V_8 ) ;
F_6 ( V_8 ) ;
V_33 = V_17 -> V_38 -> V_39 ( V_8 , V_32 ) ;
if ( V_40 )
F_31 ( V_8 ) ;
} else {
V_8 -> V_35 = V_32 ;
}
return V_33 ;
}
static void F_32 ( struct V_7 * V_8 ,
struct V_41 * V_42 )
{
struct V_16 * V_17 = F_4 ( V_8 ) ;
if ( V_17 -> V_38 -> V_43 )
V_17 -> V_38 -> V_43 ( V_8 , V_42 ) ;
else
F_33 ( V_42 , & V_8 -> V_42 ) ;
}
static bool F_34 ( const struct V_44 * V_45 ,
struct V_7 * V_8 )
{
struct V_46 * V_46 = F_35 ( V_8 ) ;
struct V_47 * V_48 ;
struct V_49 * V_50 = (struct V_49 * ) V_45 ;
struct V_51 * V_52 = (struct V_51 * ) V_45 ;
T_2 V_53 ;
switch ( V_45 -> V_54 ) {
case V_55 :
V_48 = F_36 ( V_8 ) ;
if ( ! V_48 )
return false ;
V_53 = F_37 ( V_46 , V_48 , 0 ,
V_50 -> V_56 . V_57 ,
V_58 ) ;
F_38 ( V_48 ) ;
if ( V_53 )
return true ;
break;
case V_59 :
if ( F_39 ( V_60 ) &&
F_40 ( V_46 , & V_52 -> V_61 , V_8 , 1 ) )
return true ;
break;
}
return false ;
}
static struct V_7 * F_41 ( struct V_7 * V_8 )
{
struct V_7 * V_62 ;
F_42 () ;
V_62 = F_43 ( V_8 ) ;
if ( V_62 )
F_44 ( V_62 ) ;
F_45 () ;
if ( V_62 )
return V_62 ;
F_44 ( V_8 ) ;
return V_8 ;
}
static int F_46 ( struct V_7 * V_63 , void * V_64 )
{
struct V_65 * V_66 = V_64 ;
int V_33 = 0 ;
if ( F_34 ( V_66 -> V_45 , V_63 ) ) {
F_44 ( V_63 ) ;
V_66 -> V_67 = V_63 ;
V_33 = 1 ;
}
return V_33 ;
}
static struct V_7 * F_47 (
const struct V_44 * V_45 , struct V_7 * V_8 )
{
struct V_65 V_66 = {
. V_45 = V_45 ,
} ;
F_42 () ;
if ( F_34 ( V_45 , V_8 ) ) {
F_44 ( V_8 ) ;
V_66 . V_67 = V_8 ;
goto V_68;
}
F_48 ( V_8 , F_46 , & V_66 ) ;
V_68:
F_45 () ;
return V_66 . V_67 ;
}
static int F_49 ( struct V_16 * V_17 ,
const union V_69 * V_70 ,
T_3 V_71 ,
const struct V_44 * V_45 ,
int V_72 ,
struct V_7 * * V_73 )
{
struct V_16 * V_74 ;
struct V_7 * V_75 = NULL ;
int V_76 = 0 ;
if ( V_17 -> V_71 == V_71 &&
( ! V_70 || ! memcmp ( V_70 , & V_17 -> V_77 , sizeof( * V_70 ) ) ) ) {
if ( ! V_45 ) {
V_75 = F_41 ( V_17 -> V_8 ) ;
} else {
V_75 = F_47 ( V_45 , V_17 -> V_8 ) ;
}
if ( V_75 ) {
if ( ! * V_73 )
* V_73 = V_75 ;
else
F_50 ( V_75 ) ;
++ V_76 ;
}
}
F_51 ( & V_17 -> V_25 , V_72 ) ;
F_12 (child_priv, &priv->child_intfs, list) {
V_76 += F_49 ( V_74 , V_70 ,
V_71 , V_45 ,
V_72 + 1 ,
V_73 ) ;
if ( V_76 > 1 )
break;
}
F_14 ( & V_17 -> V_25 ) ;
return V_76 ;
}
static int F_52 ( struct V_78 * V_79 , T_4 V_80 ,
T_3 V_71 ,
const union V_69 * V_70 ,
const struct V_44 * V_45 ,
struct V_7 * * V_75 )
{
struct V_16 * V_17 ;
int V_76 = 0 ;
* V_75 = NULL ;
F_12 (priv, dev_list, list) {
if ( V_17 -> V_80 != V_80 )
continue;
V_76 += F_49 ( V_17 , V_70 , V_71 ,
V_45 , 0 , V_75 ) ;
if ( V_76 > 1 )
break;
}
return V_76 ;
}
static struct V_7 * F_53 (
struct V_81 * V_8 , T_4 V_80 , T_3 V_82 ,
const union V_69 * V_70 , const struct V_44 * V_45 ,
void * V_83 )
{
struct V_7 * V_75 ;
struct V_78 * V_79 = V_83 ;
T_3 V_71 ;
int V_76 ;
int V_33 ;
if ( ! F_54 ( V_8 , V_80 ) )
return NULL ;
V_33 = F_55 ( V_8 , V_80 , V_82 , & V_71 ) ;
if ( V_33 )
return NULL ;
if ( ! V_79 )
return NULL ;
V_76 = F_52 ( V_79 , V_80 , V_71 ,
V_70 , NULL , & V_75 ) ;
switch ( V_76 ) {
case 0 :
return NULL ;
case 1 :
return V_75 ;
}
F_50 ( V_75 ) ;
V_76 = F_52 ( V_79 , V_80 , V_71 ,
V_70 , V_45 , & V_75 ) ;
switch ( V_76 ) {
case 0 :
return NULL ;
default:
F_56 ( & V_8 -> V_8 ,
L_6 ) ;
case 1 :
return V_75 ;
}
}
int F_57 ( struct V_7 * V_8 , const char * V_84 )
{
struct V_16 * V_17 = F_4 ( V_8 ) ;
if ( ( F_9 ( V_29 , & V_17 -> V_19 ) &&
! strcmp ( V_84 , L_7 ) ) ||
( ! F_9 ( V_29 , & V_17 -> V_19 ) &&
! strcmp ( V_84 , L_8 ) ) ) {
return 0 ;
}
if ( F_58 ( V_8 -> V_85 ) && ! strcmp ( V_84 , L_7 ) ) {
F_7 ( V_29 , & V_17 -> V_19 ) ;
F_27 ( V_17 , L_9
L_10 ) ;
F_59 ( V_8 ) ;
F_60 ( V_8 , F_26 ( V_8 ) ) ;
F_61 () ;
V_17 -> V_86 . V_87 . V_88 &= ~ V_89 ;
F_62 ( V_8 ) ;
return ( ! F_63 () ) ? - V_90 : 0 ;
}
if ( ! strcmp ( V_84 , L_8 ) ) {
F_16 ( V_29 , & V_17 -> V_19 ) ;
F_59 ( V_8 ) ;
F_60 ( V_8 , F_29 ( V_17 -> V_34 , V_8 -> V_35 ) ) ;
F_61 () ;
F_62 ( V_8 ) ;
return ( ! F_63 () ) ? - V_90 : 0 ;
}
return - V_27 ;
}
struct V_91 * F_64 ( struct V_7 * V_8 , void * V_70 )
{
struct V_16 * V_17 = F_4 ( V_8 ) ;
struct V_92 * V_93 = V_17 -> V_94 . V_92 ;
struct V_91 * V_95 ;
int V_33 ;
while ( V_93 ) {
V_95 = F_65 ( V_93 , struct V_91 , V_92 ) ;
V_33 = memcmp ( V_70 , V_95 -> V_96 . V_97 . V_98 ,
sizeof ( union V_69 ) ) ;
if ( V_33 < 0 )
V_93 = V_93 -> V_99 ;
else if ( V_33 > 0 )
V_93 = V_93 -> V_100 ;
else
return V_95 ;
}
return NULL ;
}
static int F_66 ( struct V_7 * V_8 , struct V_91 * V_95 )
{
struct V_16 * V_17 = F_4 ( V_8 ) ;
struct V_92 * * V_93 = & V_17 -> V_94 . V_92 ;
struct V_92 * V_101 = NULL ;
struct V_91 * V_102 ;
int V_33 ;
while ( * V_93 ) {
V_101 = * V_93 ;
V_102 = F_65 ( V_101 , struct V_91 , V_92 ) ;
V_33 = memcmp ( V_95 -> V_96 . V_97 . V_98 , V_102 -> V_96 . V_97 . V_98 ,
sizeof ( union V_69 ) ) ;
if ( V_33 < 0 )
V_93 = & V_101 -> V_99 ;
else if ( V_33 > 0 )
V_93 = & V_101 -> V_100 ;
else
return - V_103 ;
}
F_67 ( & V_95 -> V_92 , V_101 , V_93 ) ;
F_68 ( & V_95 -> V_92 , & V_17 -> V_94 ) ;
F_69 ( & V_95 -> V_104 , & V_17 -> V_105 ) ;
return 0 ;
}
static void F_70 ( struct V_7 * V_8 , struct V_91 * V_95 )
{
struct V_106 * V_107 ;
while ( ( V_107 = F_71 ( & V_95 -> V_108 ) ) )
F_72 ( V_107 ) ;
F_5 ( F_4 ( V_8 ) , L_11 ) ;
F_73 ( V_8 , V_95 -> V_96 . V_97 . V_98 ) ;
if ( V_95 -> V_109 )
F_74 ( V_95 -> V_109 ) ;
F_75 ( V_95 ) ;
}
struct V_110 * F_76 ( struct V_7 * V_8 )
{
struct V_110 * V_111 ;
V_111 = F_77 ( sizeof *V_111 , V_112 ) ;
if ( ! V_111 )
return NULL ;
V_111 -> V_8 = V_8 ;
memset ( V_111 -> V_95 . V_96 . V_97 . V_98 , 0 , 16 ) ;
if ( F_78 ( V_111 ) ) {
F_75 ( V_111 ) ;
return NULL ;
}
return V_111 ;
}
int F_78 ( struct V_110 * V_111 )
{
struct V_16 * V_17 = F_4 ( V_111 -> V_8 ) ;
struct V_92 * V_93 ;
struct V_91 * V_95 ;
int V_33 = 1 ;
F_79 ( & V_17 -> V_113 ) ;
V_93 = F_80 ( & V_17 -> V_94 ) ;
while ( V_93 ) {
V_95 = F_65 ( V_93 , struct V_91 , V_92 ) ;
if ( memcmp ( V_111 -> V_95 . V_96 . V_97 . V_98 , V_95 -> V_96 . V_97 . V_98 ,
sizeof ( union V_69 ) ) < 0 ) {
V_111 -> V_95 = * V_95 ;
V_33 = 0 ;
break;
}
V_93 = F_81 ( V_93 ) ;
}
F_82 ( & V_17 -> V_113 ) ;
return V_33 ;
}
void F_83 ( struct V_110 * V_111 ,
struct V_91 * V_95 )
{
* V_95 = V_111 -> V_95 ;
}
void F_84 ( struct V_7 * V_8 )
{
struct V_16 * V_17 = F_4 ( V_8 ) ;
struct V_91 * V_95 , * V_114 ;
F_79 ( & V_17 -> V_113 ) ;
F_85 (path, tp, &priv->path_list, list) {
F_5 ( V_17 , L_12 ,
F_86 ( F_87 ( & V_95 -> V_96 ) ) ,
V_95 -> V_96 . V_97 . V_98 ) ;
V_95 -> V_115 = 0 ;
}
F_82 ( & V_17 -> V_113 ) ;
}
static void F_88 ( struct V_106 * V_107 , const char * V_116 )
{
struct V_117 * V_118 ;
V_118 = F_89 ( V_107 , sizeof( * V_118 ) ) ;
memcpy ( V_118 -> V_119 , V_116 , V_120 ) ;
}
void F_62 ( struct V_7 * V_8 )
{
struct V_16 * V_17 = F_4 ( V_8 ) ;
struct V_91 * V_95 , * V_114 ;
F_90 ( V_121 ) ;
unsigned long V_19 ;
F_91 ( V_8 ) ;
F_92 ( & V_17 -> V_113 , V_19 ) ;
F_93 ( & V_17 -> V_105 , & V_121 ) ;
F_12 (path, &remove_list, list)
F_94 ( & V_95 -> V_92 , & V_17 -> V_94 ) ;
F_85 (path, tp, &remove_list, list) {
if ( V_95 -> V_122 )
F_95 ( V_95 -> V_123 , V_95 -> V_122 ) ;
F_96 ( & V_17 -> V_113 , V_19 ) ;
F_97 ( V_8 ) ;
F_98 ( & V_95 -> V_124 ) ;
F_70 ( V_8 , V_95 ) ;
F_91 ( V_8 ) ;
F_92 ( & V_17 -> V_113 , V_19 ) ;
}
F_96 ( & V_17 -> V_113 , V_19 ) ;
F_97 ( V_8 ) ;
}
static void F_99 ( int V_125 ,
struct V_126 * V_96 ,
void * V_127 )
{
struct V_91 * V_95 = V_127 ;
struct V_7 * V_8 = V_95 -> V_8 ;
struct V_16 * V_17 = F_4 ( V_8 ) ;
struct V_128 * V_109 = NULL ;
struct V_128 * V_129 = NULL ;
struct V_130 * V_131 , * V_132 ;
struct V_133 V_134 ;
struct V_106 * V_107 ;
unsigned long V_19 ;
if ( ! V_125 )
F_5 ( V_17 , L_13 ,
F_86 ( F_87 ( V_96 ) ) ,
V_96 -> V_97 . V_98 ) ;
else
F_5 ( V_17 , L_14 ,
V_125 , V_95 -> V_96 . V_97 . V_98 ) ;
F_100 ( & V_134 ) ;
if ( ! V_125 ) {
struct V_135 V_136 ;
if ( ! F_101 ( V_17 -> V_137 , V_17 -> V_80 , V_96 , & V_136 ) )
V_109 = F_102 ( V_8 , V_17 -> V_138 , & V_136 ) ;
}
F_92 ( & V_17 -> V_113 , V_19 ) ;
if ( ! F_103 ( V_109 ) ) {
V_95 -> V_96 = * V_96 ;
V_129 = V_95 -> V_109 ;
V_95 -> V_109 = V_109 ;
F_5 ( V_17 , L_15 ,
V_109 , F_86 ( F_87 ( V_96 ) ) ,
V_96 -> V_139 ) ;
while ( ( V_107 = F_71 ( & V_95 -> V_108 ) ) )
F_104 ( & V_134 , V_107 ) ;
F_85 (neigh, tn, &path->neigh_list, list) {
if ( V_131 -> V_109 ) {
F_105 ( V_131 -> V_109 != V_129 ) ;
F_74 ( V_131 -> V_109 ) ;
}
F_106 ( & V_95 -> V_109 -> V_140 ) ;
V_131 -> V_109 = V_95 -> V_109 ;
if ( F_107 ( V_8 , V_131 -> V_116 ) ) {
if ( ! F_108 ( V_131 ) )
F_109 ( V_131 , F_110 ( V_8 ,
V_95 ,
V_131 ) ) ;
if ( ! F_108 ( V_131 ) ) {
F_111 ( V_131 ) ;
continue;
}
}
while ( ( V_107 = F_71 ( & V_131 -> V_108 ) ) )
F_104 ( & V_134 , V_107 ) ;
}
V_95 -> V_115 = 1 ;
}
V_95 -> V_122 = NULL ;
F_112 ( & V_95 -> V_124 ) ;
F_96 ( & V_17 -> V_113 , V_19 ) ;
if ( F_103 ( V_109 ) )
F_73 ( V_8 , V_95 -> V_96 . V_97 . V_98 ) ;
if ( V_129 )
F_74 ( V_129 ) ;
while ( ( V_107 = F_71 ( & V_134 ) ) ) {
int V_33 ;
V_107 -> V_8 = V_8 ;
V_33 = F_113 ( V_107 ) ;
if ( V_33 )
F_27 ( V_17 , L_16 ,
V_141 , V_33 ) ;
}
}
static struct V_91 * F_114 ( struct V_7 * V_8 , void * V_70 )
{
struct V_16 * V_17 = F_4 ( V_8 ) ;
struct V_91 * V_95 ;
if ( ! V_17 -> V_142 )
return NULL ;
V_95 = F_115 ( sizeof *V_95 , V_143 ) ;
if ( ! V_95 )
return NULL ;
V_95 -> V_8 = V_8 ;
F_100 ( & V_95 -> V_108 ) ;
F_116 ( & V_95 -> V_144 ) ;
if ( F_117 ( V_17 -> V_137 , V_17 -> V_80 ) )
V_95 -> V_96 . V_145 = V_146 ;
else
V_95 -> V_96 . V_145 = V_147 ;
memcpy ( V_95 -> V_96 . V_97 . V_98 , V_70 , sizeof ( union V_69 ) ) ;
V_95 -> V_96 . V_148 = V_17 -> V_77 ;
V_95 -> V_96 . V_82 = F_118 ( V_17 -> V_82 ) ;
V_95 -> V_96 . V_149 = 1 ;
V_95 -> V_96 . V_150 = V_17 -> V_142 -> V_151 . V_150 ;
return V_95 ;
}
static int F_119 ( struct V_7 * V_8 ,
struct V_91 * V_95 )
{
struct V_16 * V_17 = F_4 ( V_8 ) ;
F_5 ( V_17 , L_17 ,
V_95 -> V_96 . V_97 . V_98 ) ;
F_120 ( & V_95 -> V_124 ) ;
V_95 -> V_123 =
F_121 ( & V_152 , V_17 -> V_137 , V_17 -> V_80 ,
& V_95 -> V_96 ,
V_153 |
V_154 |
V_155 |
V_156 |
V_157 ,
1000 , V_143 ,
F_99 ,
V_95 , & V_95 -> V_122 ) ;
if ( V_95 -> V_123 < 0 ) {
F_27 ( V_17 , L_18 , V_95 -> V_123 ) ;
V_95 -> V_122 = NULL ;
F_112 ( & V_95 -> V_124 ) ;
return V_95 -> V_123 ;
}
return 0 ;
}
static void F_122 ( struct V_106 * V_107 , T_4 * V_116 ,
struct V_7 * V_8 )
{
struct V_16 * V_17 = F_4 ( V_8 ) ;
struct V_158 * V_159 = F_123 ( V_8 ) ;
struct V_91 * V_95 ;
struct V_130 * V_131 ;
unsigned long V_19 ;
F_92 ( & V_17 -> V_113 , V_19 ) ;
V_131 = F_124 ( V_116 , V_8 ) ;
if ( ! V_131 ) {
F_96 ( & V_17 -> V_113 , V_19 ) ;
++ V_8 -> V_42 . V_160 ;
F_125 ( V_107 ) ;
return;
}
V_95 = F_64 ( V_8 , V_116 + 4 ) ;
if ( ! V_95 ) {
V_95 = F_114 ( V_8 , V_116 + 4 ) ;
if ( ! V_95 )
goto V_161;
F_66 ( V_8 , V_95 ) ;
}
F_69 ( & V_131 -> V_104 , & V_95 -> V_144 ) ;
if ( V_95 -> V_109 ) {
F_106 ( & V_95 -> V_109 -> V_140 ) ;
V_131 -> V_109 = V_95 -> V_109 ;
if ( F_107 ( V_8 , V_131 -> V_116 ) ) {
if ( ! F_108 ( V_131 ) )
F_109 ( V_131 , F_110 ( V_8 , V_95 , V_131 ) ) ;
if ( ! F_108 ( V_131 ) ) {
F_111 ( V_131 ) ;
goto V_162;
}
if ( F_126 ( & V_131 -> V_108 ) <
V_163 ) {
F_88 ( V_107 , V_131 -> V_116 ) ;
F_104 ( & V_131 -> V_108 , V_107 ) ;
} else {
F_27 ( V_17 , L_19 ,
F_126 ( & V_131 -> V_108 ) ) ;
goto V_162;
}
} else {
F_96 ( & V_17 -> V_113 , V_19 ) ;
V_95 -> V_109 -> V_164 = V_159 -> V_165 ( V_8 , V_107 , V_95 -> V_109 -> V_109 ,
F_127 ( V_116 ) ) ;
F_128 ( V_131 ) ;
return;
}
} else {
V_131 -> V_109 = NULL ;
if ( ! V_95 -> V_122 && F_119 ( V_8 , V_95 ) )
goto V_161;
if ( F_126 ( & V_131 -> V_108 ) < V_163 ) {
F_88 ( V_107 , V_131 -> V_116 ) ;
F_104 ( & V_131 -> V_108 , V_107 ) ;
} else {
goto V_162;
}
}
F_96 ( & V_17 -> V_113 , V_19 ) ;
F_128 ( V_131 ) ;
return;
V_161:
F_111 ( V_131 ) ;
V_162:
++ V_8 -> V_42 . V_160 ;
F_125 ( V_107 ) ;
F_96 ( & V_17 -> V_113 , V_19 ) ;
F_128 ( V_131 ) ;
}
static void F_129 ( struct V_106 * V_107 , struct V_7 * V_8 ,
struct V_117 * V_118 )
{
struct V_16 * V_17 = F_4 ( V_8 ) ;
struct V_158 * V_159 = F_123 ( V_8 ) ;
struct V_91 * V_95 ;
unsigned long V_19 ;
F_92 ( & V_17 -> V_113 , V_19 ) ;
V_95 = F_64 ( V_8 , V_118 -> V_119 + 4 ) ;
if ( ! V_95 || ! V_95 -> V_115 ) {
int V_166 = 0 ;
if ( ! V_95 ) {
V_95 = F_114 ( V_8 , V_118 -> V_119 + 4 ) ;
V_166 = 1 ;
}
if ( V_95 ) {
if ( F_126 ( & V_95 -> V_108 ) < V_163 ) {
F_88 ( V_107 , V_118 -> V_119 ) ;
F_104 ( & V_95 -> V_108 , V_107 ) ;
} else {
++ V_8 -> V_42 . V_160 ;
F_125 ( V_107 ) ;
}
if ( ! V_95 -> V_122 && F_119 ( V_8 , V_95 ) ) {
F_96 ( & V_17 -> V_113 , V_19 ) ;
if ( V_166 )
F_70 ( V_8 , V_95 ) ;
return;
} else
F_66 ( V_8 , V_95 ) ;
} else {
++ V_8 -> V_42 . V_160 ;
F_125 ( V_107 ) ;
}
F_96 ( & V_17 -> V_113 , V_19 ) ;
return;
}
if ( V_95 -> V_109 ) {
F_5 ( V_17 , L_20 ,
F_86 ( F_87 ( & V_95 -> V_96 ) ) ) ;
F_96 ( & V_17 -> V_113 , V_19 ) ;
V_95 -> V_109 -> V_164 = V_159 -> V_165 ( V_8 , V_107 , V_95 -> V_109 -> V_109 ,
F_127 ( V_118 -> V_119 ) ) ;
return;
} else if ( ( V_95 -> V_122 || ! F_119 ( V_8 , V_95 ) ) &&
F_126 ( & V_95 -> V_108 ) < V_163 ) {
F_88 ( V_107 , V_118 -> V_119 ) ;
F_104 ( & V_95 -> V_108 , V_107 ) ;
} else {
++ V_8 -> V_42 . V_160 ;
F_125 ( V_107 ) ;
}
F_96 ( & V_17 -> V_113 , V_19 ) ;
}
static int F_130 ( struct V_106 * V_107 , struct V_7 * V_8 )
{
struct V_16 * V_17 = F_4 ( V_8 ) ;
struct V_158 * V_159 = F_123 ( V_8 ) ;
struct V_130 * V_131 ;
struct V_117 * V_118 ;
struct V_167 * V_168 ;
unsigned long V_19 ;
V_118 = (struct V_117 * ) V_107 -> V_66 ;
F_131 ( V_107 , sizeof( * V_118 ) ) ;
V_168 = (struct V_167 * ) V_107 -> V_66 ;
if ( F_132 ( V_118 -> V_119 [ 4 ] == 0xff ) ) {
if ( ( V_168 -> V_169 != F_133 ( V_170 ) ) &&
( V_168 -> V_169 != F_133 ( V_171 ) ) &&
( V_168 -> V_169 != F_133 ( V_172 ) ) &&
( V_168 -> V_169 != F_133 ( V_173 ) ) &&
( V_168 -> V_169 != F_133 ( V_174 ) ) ) {
++ V_8 -> V_42 . V_160 ;
F_125 ( V_107 ) ;
return V_175 ;
}
V_118 -> V_119 [ 8 ] = ( V_17 -> V_82 >> 8 ) & 0xff ;
V_118 -> V_119 [ 9 ] = V_17 -> V_82 & 0xff ;
V_131 = F_134 ( V_8 , V_118 -> V_119 ) ;
if ( F_135 ( V_131 ) )
goto V_176;
F_136 ( V_8 , V_118 -> V_119 , V_107 ) ;
return V_175 ;
}
switch ( V_168 -> V_169 ) {
case F_133 ( V_170 ) :
case F_133 ( V_171 ) :
case F_133 ( V_174 ) :
V_131 = F_134 ( V_8 , V_118 -> V_119 ) ;
if ( F_132 ( ! V_131 ) ) {
F_122 ( V_107 , V_118 -> V_119 , V_8 ) ;
return V_175 ;
}
break;
case F_133 ( V_172 ) :
case F_133 ( V_173 ) :
F_129 ( V_107 , V_8 , V_118 ) ;
return V_175 ;
default:
++ V_8 -> V_42 . V_160 ;
F_125 ( V_107 ) ;
return V_175 ;
}
V_176:
if ( F_108 ( V_131 ) ) {
if ( F_137 ( V_131 ) ) {
F_138 ( V_8 , V_107 , F_108 ( V_131 ) ) ;
goto V_177;
}
} else if ( V_131 -> V_109 ) {
V_131 -> V_109 -> V_164 = V_159 -> V_165 ( V_8 , V_107 , V_131 -> V_109 -> V_109 ,
F_127 ( V_118 -> V_119 ) ) ;
goto V_177;
}
if ( F_126 ( & V_131 -> V_108 ) < V_163 ) {
F_88 ( V_107 , V_118 -> V_119 ) ;
F_92 ( & V_17 -> V_113 , V_19 ) ;
F_104 ( & V_131 -> V_108 , V_107 ) ;
F_96 ( & V_17 -> V_113 , V_19 ) ;
} else {
++ V_8 -> V_42 . V_160 ;
F_125 ( V_107 ) ;
}
V_177:
F_128 ( V_131 ) ;
return V_175 ;
}
static void F_139 ( struct V_7 * V_8 )
{
struct V_16 * V_17 = F_4 ( V_8 ) ;
F_27 ( V_17 , L_21 ,
F_140 ( V_178 - F_141 ( V_8 ) ) ) ;
F_27 ( V_17 , L_22 ,
F_142 ( V_8 ) ,
V_17 -> V_179 , V_17 -> V_180 ) ;
}
static int F_143 ( struct V_106 * V_107 ,
struct V_7 * V_8 ,
unsigned short type ,
const void * V_116 , const void * V_181 , unsigned V_182 )
{
struct V_167 * V_168 ;
V_168 = F_89 ( V_107 , sizeof *V_168 ) ;
V_168 -> V_169 = F_133 ( type ) ;
V_168 -> V_183 = 0 ;
F_88 ( V_107 , V_116 ) ;
return V_184 ;
}
static void F_144 ( struct V_7 * V_8 )
{
struct V_16 * V_17 = F_4 ( V_8 ) ;
if ( ! F_9 ( V_185 , & V_17 -> V_19 ) ) {
F_5 ( V_17 , L_23 ) ;
return;
}
F_145 ( V_17 -> V_186 , & V_17 -> V_187 ) ;
}
static int F_146 ( const struct V_7 * V_8 )
{
struct V_16 * V_17 = F_4 ( V_8 ) ;
if ( ! F_9 ( V_23 , & V_17 -> V_19 ) )
return V_8 -> V_188 ;
return V_17 -> V_189 -> V_188 ;
}
static T_5 F_147 ( struct V_190 * V_191 , T_4 * V_116 )
{
T_5 * V_192 = ( T_5 * ) V_116 ;
T_5 V_193 ;
V_193 = F_148 ( V_192 [ 3 ] , V_192 [ 4 ] , V_194 & V_192 [ 0 ] , 0 ) ;
return V_193 & V_191 -> V_195 ;
}
struct V_130 * F_134 ( struct V_7 * V_8 , T_4 * V_116 )
{
struct V_16 * V_17 = F_4 ( V_8 ) ;
struct V_196 * V_197 = & V_17 -> V_197 ;
struct V_190 * V_191 ;
struct V_130 * V_131 = NULL ;
T_5 V_198 ;
F_149 () ;
V_191 = F_150 ( V_197 -> V_191 ) ;
if ( ! V_191 )
goto V_199;
V_198 = F_147 ( V_191 , V_116 ) ;
for ( V_131 = F_150 ( V_191 -> V_200 [ V_198 ] ) ;
V_131 != NULL ;
V_131 = F_150 ( V_131 -> V_201 ) ) {
if ( memcmp ( V_116 , V_131 -> V_116 , V_120 ) == 0 ) {
if ( ! F_151 ( & V_131 -> V_202 ) ) {
V_131 = NULL ;
goto V_199;
}
if ( F_135 ( F_126 ( & V_131 -> V_108 ) < V_163 ) )
V_131 -> V_203 = V_178 ;
goto V_199;
}
}
V_199:
F_152 () ;
return V_131 ;
}
static void F_153 ( struct V_16 * V_17 )
{
struct V_196 * V_197 = & V_17 -> V_197 ;
struct V_190 * V_191 ;
unsigned long V_204 ;
unsigned long V_205 ;
unsigned long V_19 ;
int V_206 ;
F_90 ( V_121 ) ;
if ( F_9 ( V_207 , & V_17 -> V_19 ) )
return;
F_92 ( & V_17 -> V_113 , V_19 ) ;
V_191 = F_154 ( V_197 -> V_191 ,
F_155 ( & V_17 -> V_113 ) ) ;
if ( ! V_191 )
goto V_199;
V_205 = 2 * V_208 . V_209 ;
V_204 = V_178 - V_205 ;
if ( F_9 ( V_207 , & V_17 -> V_19 ) )
goto V_199;
for ( V_206 = 0 ; V_206 < V_191 -> V_210 ; V_206 ++ ) {
struct V_130 * V_131 ;
struct V_130 T_6 * * V_211 = & V_191 -> V_200 [ V_206 ] ;
while ( ( V_131 = F_154 ( * V_211 ,
F_155 ( & V_17 -> V_113 ) ) ) != NULL ) {
if ( F_156 ( V_204 , V_131 -> V_203 ) ) {
F_157 ( V_17 , V_131 -> V_116 + 4 , & V_121 ) ;
F_158 ( * V_211 ,
F_154 ( V_131 -> V_201 ,
F_155 ( & V_17 -> V_113 ) ) ) ;
F_159 ( & V_131 -> V_104 ) ;
F_160 ( & V_131 -> V_212 , V_213 ) ;
} else {
V_211 = & V_131 -> V_201 ;
}
}
}
V_199:
F_96 ( & V_17 -> V_113 , V_19 ) ;
F_161 ( & V_121 ) ;
}
static void F_162 ( struct V_214 * V_215 )
{
struct V_16 * V_17 =
F_163 ( V_215 , struct V_16 , V_216 . V_215 ) ;
F_153 ( V_17 ) ;
if ( ! F_9 ( V_207 , & V_17 -> V_19 ) )
F_164 ( V_17 -> V_186 , & V_17 -> V_216 ,
V_208 . V_209 ) ;
}
static struct V_130 * F_165 ( T_4 * V_116 ,
struct V_7 * V_8 )
{
struct V_130 * V_131 ;
V_131 = F_115 ( sizeof *V_131 , V_143 ) ;
if ( ! V_131 )
return NULL ;
V_131 -> V_8 = V_8 ;
memcpy ( & V_131 -> V_116 , V_116 , sizeof( V_131 -> V_116 ) ) ;
F_100 ( & V_131 -> V_108 ) ;
F_116 ( & V_131 -> V_104 ) ;
F_109 ( V_131 , NULL ) ;
F_166 ( & V_131 -> V_202 , 1 ) ;
return V_131 ;
}
struct V_130 * F_124 ( T_4 * V_116 ,
struct V_7 * V_8 )
{
struct V_16 * V_17 = F_4 ( V_8 ) ;
struct V_196 * V_197 = & V_17 -> V_197 ;
struct V_190 * V_191 ;
struct V_130 * V_131 ;
T_5 V_198 ;
V_191 = F_154 ( V_197 -> V_191 ,
F_155 ( & V_17 -> V_113 ) ) ;
if ( ! V_191 ) {
V_131 = NULL ;
goto V_199;
}
V_198 = F_147 ( V_191 , V_116 ) ;
for ( V_131 = F_154 ( V_191 -> V_200 [ V_198 ] ,
F_155 ( & V_17 -> V_113 ) ) ;
V_131 != NULL ;
V_131 = F_154 ( V_131 -> V_201 ,
F_155 ( & V_17 -> V_113 ) ) ) {
if ( memcmp ( V_116 , V_131 -> V_116 , V_120 ) == 0 ) {
if ( ! F_151 ( & V_131 -> V_202 ) ) {
V_131 = NULL ;
break;
}
V_131 -> V_203 = V_178 ;
goto V_199;
}
}
V_131 = F_165 ( V_116 , V_8 ) ;
if ( ! V_131 )
goto V_199;
F_167 ( & V_131 -> V_202 ) ;
V_131 -> V_203 = V_178 ;
F_158 ( V_131 -> V_201 ,
F_154 ( V_191 -> V_200 [ V_198 ] ,
F_155 ( & V_17 -> V_113 ) ) ) ;
F_158 ( V_191 -> V_200 [ V_198 ] , V_131 ) ;
F_167 ( & V_197 -> V_217 ) ;
V_199:
return V_131 ;
}
void F_168 ( struct V_130 * V_131 )
{
struct V_7 * V_8 = V_131 -> V_8 ;
struct V_16 * V_17 = F_4 ( V_8 ) ;
struct V_106 * V_107 ;
if ( V_131 -> V_109 )
F_74 ( V_131 -> V_109 ) ;
while ( ( V_107 = F_71 ( & V_131 -> V_108 ) ) ) {
++ V_8 -> V_42 . V_160 ;
F_125 ( V_107 ) ;
}
if ( F_108 ( V_131 ) )
F_169 ( F_108 ( V_131 ) ) ;
F_5 ( F_4 ( V_8 ) ,
L_24 ,
F_127 ( V_131 -> V_116 ) ,
V_131 -> V_116 + 4 ) ;
F_75 ( V_131 ) ;
if ( F_170 ( & V_17 -> V_197 . V_217 ) ) {
if ( F_9 ( V_218 , & V_17 -> V_19 ) )
F_112 ( & V_17 -> V_197 . V_219 ) ;
}
}
static void V_213 ( struct V_220 * V_221 )
{
struct V_130 * V_131 = F_163 ( V_221 , struct V_130 , V_212 ) ;
F_128 ( V_131 ) ;
}
void F_111 ( struct V_130 * V_131 )
{
struct V_7 * V_8 = V_131 -> V_8 ;
struct V_16 * V_17 = F_4 ( V_8 ) ;
struct V_196 * V_197 = & V_17 -> V_197 ;
struct V_190 * V_191 ;
struct V_130 T_6 * * V_211 ;
struct V_130 * V_93 ;
T_5 V_198 ;
V_191 = F_154 ( V_197 -> V_191 ,
F_155 ( & V_17 -> V_113 ) ) ;
if ( ! V_191 )
return;
V_198 = F_147 ( V_191 , V_131 -> V_116 ) ;
V_211 = & V_191 -> V_200 [ V_198 ] ;
for ( V_93 = F_154 ( * V_211 ,
F_155 ( & V_17 -> V_113 ) ) ;
V_93 != NULL ;
V_93 = F_154 ( * V_211 ,
F_155 ( & V_17 -> V_113 ) ) ) {
if ( V_93 == V_131 ) {
F_158 ( * V_211 ,
F_154 ( V_131 -> V_201 ,
F_155 ( & V_17 -> V_113 ) ) ) ;
F_159 ( & V_131 -> V_104 ) ;
F_160 ( & V_131 -> V_212 , V_213 ) ;
return;
} else {
V_211 = & V_93 -> V_201 ;
}
}
}
static int F_171 ( struct V_16 * V_17 )
{
struct V_196 * V_197 = & V_17 -> V_197 ;
struct V_190 * V_191 ;
struct V_130 T_6 * * V_200 ;
T_5 V_210 ;
F_16 ( V_218 , & V_17 -> V_19 ) ;
V_197 -> V_191 = NULL ;
V_191 = F_115 ( sizeof( * V_191 ) , V_112 ) ;
if ( ! V_191 )
return - V_222 ;
F_7 ( V_207 , & V_17 -> V_19 ) ;
V_210 = F_172 ( V_208 . V_223 ) ;
V_200 = F_115 ( V_210 * sizeof( * V_200 ) , V_112 ) ;
if ( ! V_200 ) {
F_75 ( V_191 ) ;
return - V_222 ;
}
V_191 -> V_210 = V_210 ;
V_191 -> V_195 = ( V_210 - 1 ) ;
V_191 -> V_200 = V_200 ;
F_173 ( V_197 -> V_191 , V_191 ) ;
V_191 -> V_197 = V_197 ;
F_166 ( & V_197 -> V_217 , 0 ) ;
F_16 ( V_207 , & V_17 -> V_19 ) ;
F_164 ( V_17 -> V_186 , & V_17 -> V_216 ,
V_208 . V_209 ) ;
return 0 ;
}
static void F_174 ( struct V_220 * V_224 )
{
struct V_190 * V_191 = F_163 ( V_224 ,
struct V_190 ,
V_212 ) ;
struct V_130 T_6 * * V_200 = V_191 -> V_200 ;
struct V_196 * V_197 = V_191 -> V_197 ;
F_75 ( V_200 ) ;
F_75 ( V_191 ) ;
F_112 ( & V_197 -> V_225 ) ;
}
void F_73 ( struct V_7 * V_8 , T_4 * V_70 )
{
struct V_16 * V_17 = F_4 ( V_8 ) ;
struct V_196 * V_197 = & V_17 -> V_197 ;
struct V_190 * V_191 ;
unsigned long V_19 ;
int V_206 ;
F_92 ( & V_17 -> V_113 , V_19 ) ;
V_191 = F_154 ( V_197 -> V_191 ,
F_155 ( & V_17 -> V_113 ) ) ;
if ( ! V_191 )
goto V_199;
for ( V_206 = 0 ; V_206 < V_191 -> V_210 ; V_206 ++ ) {
struct V_130 * V_131 ;
struct V_130 T_6 * * V_211 = & V_191 -> V_200 [ V_206 ] ;
while ( ( V_131 = F_154 ( * V_211 ,
F_155 ( & V_17 -> V_113 ) ) ) != NULL ) {
if ( ! memcmp ( V_70 , V_131 -> V_116 + 4 , sizeof ( union V_69 ) ) ) {
F_158 ( * V_211 ,
F_154 ( V_131 -> V_201 ,
F_155 ( & V_17 -> V_113 ) ) ) ;
F_159 ( & V_131 -> V_104 ) ;
F_160 ( & V_131 -> V_212 , V_213 ) ;
} else {
V_211 = & V_131 -> V_201 ;
}
}
}
V_199:
F_96 ( & V_17 -> V_113 , V_19 ) ;
}
static void F_175 ( struct V_16 * V_17 )
{
struct V_196 * V_197 = & V_17 -> V_197 ;
struct V_190 * V_191 ;
unsigned long V_19 ;
int V_206 , V_226 = 0 ;
F_120 ( & V_17 -> V_197 . V_219 ) ;
F_7 ( V_218 , & V_17 -> V_19 ) ;
F_92 ( & V_17 -> V_113 , V_19 ) ;
V_191 = F_154 ( V_197 -> V_191 ,
F_155 ( & V_17 -> V_113 ) ) ;
if ( ! V_191 )
goto V_199;
V_226 = F_176 ( & V_17 -> V_197 . V_217 ) ;
if ( ! V_226 )
goto V_227;
for ( V_206 = 0 ; V_206 < V_191 -> V_210 ; V_206 ++ ) {
struct V_130 * V_131 ;
struct V_130 T_6 * * V_211 = & V_191 -> V_200 [ V_206 ] ;
while ( ( V_131 = F_154 ( * V_211 ,
F_155 ( & V_17 -> V_113 ) ) ) != NULL ) {
F_158 ( * V_211 ,
F_154 ( V_131 -> V_201 ,
F_155 ( & V_17 -> V_113 ) ) ) ;
F_159 ( & V_131 -> V_104 ) ;
F_160 ( & V_131 -> V_212 , V_213 ) ;
}
}
V_227:
F_158 ( V_197 -> V_191 , NULL ) ;
F_160 ( & V_191 -> V_212 , F_174 ) ;
V_199:
F_96 ( & V_17 -> V_113 , V_19 ) ;
if ( V_226 )
F_98 ( & V_17 -> V_197 . V_219 ) ;
}
static void F_177 ( struct V_7 * V_8 )
{
struct V_16 * V_17 = F_4 ( V_8 ) ;
int V_228 ;
F_5 ( V_17 , L_25 ) ;
F_120 ( & V_17 -> V_197 . V_225 ) ;
V_228 = F_178 ( V_207 , & V_17 -> V_19 ) ;
if ( ! V_228 )
F_179 ( & V_17 -> V_216 ) ;
F_175 ( V_17 ) ;
F_98 ( & V_17 -> V_197 . V_225 ) ;
}
static void F_180 ( struct V_7 * V_8 )
{
struct V_16 * V_17 = F_4 ( V_8 ) ;
F_181 ( V_8 ) ;
F_182 ( & V_17 -> V_229 ) ;
F_183 ( V_8 ) ;
F_75 ( V_17 -> V_230 ) ;
F_184 ( V_17 -> V_231 ) ;
V_17 -> V_230 = NULL ;
V_17 -> V_231 = NULL ;
}
static int F_185 ( struct V_7 * V_8 )
{
struct V_16 * V_17 = F_4 ( V_8 ) ;
F_186 ( V_8 , & V_17 -> V_229 , V_232 , V_233 ) ;
V_17 -> V_230 = F_115 ( V_234 * sizeof * V_17 -> V_230 ,
V_112 ) ;
if ( ! V_17 -> V_230 )
goto V_68;
V_17 -> V_231 = F_187 ( V_235 * sizeof * V_17 -> V_231 ) ;
if ( ! V_17 -> V_231 ) {
F_188 ( V_236 L_26 ,
V_17 -> V_137 -> V_237 , V_235 ) ;
goto V_238;
}
if ( F_189 ( V_8 , V_17 -> V_137 ) ) {
F_190 ( L_27 ,
V_17 -> V_137 -> V_237 ) ;
goto V_239;
}
V_17 -> V_8 -> V_85 [ 1 ] = ( V_17 -> V_240 -> V_241 >> 16 ) & 0xff ;
V_17 -> V_8 -> V_85 [ 2 ] = ( V_17 -> V_240 -> V_241 >> 8 ) & 0xff ;
V_17 -> V_8 -> V_85 [ 3 ] = ( V_17 -> V_240 -> V_241 ) & 0xff ;
F_191 ( & V_17 -> V_242 , V_243 ,
( unsigned long ) V_8 ) ;
return 0 ;
V_239:
F_184 ( V_17 -> V_231 ) ;
V_238:
F_75 ( V_17 -> V_230 ) ;
V_68:
F_182 ( & V_17 -> V_229 ) ;
return - V_222 ;
}
static int F_192 ( struct V_7 * V_8 , struct V_244 * V_245 ,
int V_246 )
{
struct V_16 * V_17 = F_4 ( V_8 ) ;
if ( ! V_17 -> V_38 -> V_247 )
return - V_248 ;
return V_17 -> V_38 -> V_247 ( V_8 , V_245 , V_246 ) ;
}
int F_193 ( struct V_7 * V_8 , struct V_81 * V_137 , int V_80 )
{
struct V_16 * V_17 = F_4 ( V_8 ) ;
int V_33 = - V_222 ;
V_17 -> V_137 = V_137 ;
V_17 -> V_80 = V_80 ;
V_17 -> V_240 = NULL ;
V_17 -> V_186 = F_194 ( L_28 , V_249 ) ;
if ( ! V_17 -> V_186 ) {
F_190 ( L_29 , V_8 -> V_237 ) ;
goto V_68;
}
V_17 -> V_138 = F_195 ( V_17 -> V_137 , 0 ) ;
if ( F_196 ( V_17 -> V_138 ) ) {
F_190 ( L_30 , V_137 -> V_237 ) ;
goto V_250;
}
V_33 = V_17 -> V_38 -> V_251 ( V_8 ) ;
if ( V_33 ) {
F_190 ( L_31 , V_8 -> V_237 ) ;
goto V_252;
}
if ( F_171 ( V_17 ) < 0 ) {
F_190 ( L_32 , V_8 -> V_237 ) ;
goto V_253;
}
if ( V_8 -> V_19 & V_26 ) {
if ( F_8 ( V_8 ) ) {
F_190 ( L_33 , V_8 -> V_237 ) ;
V_33 = - V_254 ;
goto V_253;
}
}
return 0 ;
V_253:
F_197 ( V_8 ) ;
V_252:
if ( V_17 -> V_138 ) {
F_198 ( V_17 -> V_138 ) ;
V_17 -> V_138 = NULL ;
}
V_250:
if ( V_17 -> V_186 ) {
F_199 ( V_17 -> V_186 ) ;
V_17 -> V_186 = NULL ;
}
V_68:
return V_33 ;
}
void F_22 ( struct V_7 * V_8 )
{
struct V_16 * V_17 = F_4 ( V_8 ) , * V_24 , * V_255 ;
F_90 ( V_224 ) ;
F_200 () ;
F_85 (cpriv, tcpriv, &priv->child_intfs, list) {
F_7 ( V_207 , & V_24 -> V_19 ) ;
F_179 ( & V_24 -> V_216 ) ;
F_201 ( V_24 -> V_8 , & V_224 ) ;
}
F_202 ( & V_224 ) ;
F_177 ( V_8 ) ;
F_197 ( V_8 ) ;
if ( V_17 -> V_186 ) {
F_203 ( V_17 -> V_186 ) ;
F_199 ( V_17 -> V_186 ) ;
V_17 -> V_186 = NULL ;
}
}
static int F_204 ( struct V_7 * V_8 , int V_256 , int V_257 )
{
struct V_16 * V_17 = F_4 ( V_8 ) ;
return F_205 ( V_17 -> V_137 , V_256 , V_17 -> V_80 , V_257 ) ;
}
static int F_206 ( struct V_7 * V_8 , int V_256 ,
struct V_258 * V_259 )
{
struct V_16 * V_17 = F_4 ( V_8 ) ;
int V_260 ;
V_260 = F_207 ( V_17 -> V_137 , V_256 , V_17 -> V_80 , V_259 ) ;
if ( V_260 )
return V_260 ;
V_259 -> V_256 = V_256 ;
return 0 ;
}
static int F_208 ( struct V_7 * V_8 , int V_256 , T_7 V_261 , int type )
{
struct V_16 * V_17 = F_4 ( V_8 ) ;
if ( type != V_262 && type != V_263 )
return - V_27 ;
return F_209 ( V_17 -> V_137 , V_256 , V_17 -> V_80 , V_261 , type ) ;
}
static int F_210 ( struct V_7 * V_8 , int V_256 ,
struct V_264 * V_265 )
{
struct V_16 * V_17 = F_4 ( V_8 ) ;
return F_211 ( V_17 -> V_137 , V_256 , V_17 -> V_80 , V_265 ) ;
}
void F_212 ( struct V_7 * V_8 )
{
V_8 -> V_266 = & V_267 ;
F_213 ( V_8 ) ;
V_8 -> V_268 = V_269 ;
V_8 -> V_19 |= V_270 | V_271 ;
V_8 -> V_272 = V_184 ;
V_8 -> V_273 = V_120 ;
V_8 -> type = V_274 ;
V_8 -> V_275 = V_235 * 2 ;
V_8 -> V_28 = ( V_276 |
V_277 ) ;
F_214 ( V_8 ) ;
memcpy ( V_8 -> V_142 , V_278 , V_120 ) ;
}
static void F_215 ( struct V_7 * V_8 )
{
struct V_16 * V_17 = F_4 ( V_8 ) ;
V_17 -> V_8 = V_8 ;
F_216 ( & V_17 -> V_113 ) ;
F_217 ( & V_17 -> V_25 ) ;
F_218 ( & V_17 -> V_279 ) ;
F_218 ( & V_17 -> V_280 ) ;
F_116 ( & V_17 -> V_105 ) ;
F_116 ( & V_17 -> V_281 ) ;
F_116 ( & V_17 -> V_282 ) ;
F_116 ( & V_17 -> V_283 ) ;
F_219 ( & V_17 -> V_284 , V_285 ) ;
F_220 ( & V_17 -> V_286 , V_287 ) ;
F_220 ( & V_17 -> V_288 , V_289 ) ;
F_220 ( & V_17 -> V_290 , V_291 ) ;
F_220 ( & V_17 -> V_292 , V_293 ) ;
F_220 ( & V_17 -> V_187 , V_294 ) ;
F_219 ( & V_17 -> V_295 , V_296 ) ;
F_219 ( & V_17 -> V_216 , F_162 ) ;
}
static struct V_7
* F_221 ( struct V_81 * V_297 ,
const char * V_237 ,
unsigned char V_298 ,
void (* F_222)( struct V_7 * ) )
{
struct V_7 * V_8 ;
struct V_158 * V_159 ;
V_8 = F_223 ( ( int ) sizeof( struct V_158 ) ,
V_237 ,
V_298 , F_222 ) ;
if ( ! V_8 )
return NULL ;
V_159 = F_123 ( V_8 ) ;
V_159 -> V_165 = V_299 ;
V_159 -> V_300 = V_301 ;
V_159 -> V_302 = V_303 ;
V_159 -> V_304 = V_305 ;
V_159 -> V_297 = V_297 ;
V_8 -> V_9 = & V_306 ;
return V_8 ;
}
static struct V_7 * F_224 ( struct V_81 * V_297 , T_4 V_80 ,
const char * V_237 )
{
struct V_7 * V_8 ;
if ( V_297 -> V_307 ) {
V_8 = V_297 -> V_307 ( V_297 , V_80 ,
V_308 , V_237 ,
V_309 ,
F_212 ) ;
if ( F_103 ( V_8 ) && F_225 ( V_8 ) != - V_248 )
return NULL ;
}
if ( ! V_297 -> V_307 || F_225 ( V_8 ) == - V_248 )
V_8 = F_221 ( V_297 , V_237 , V_309 ,
F_212 ) ;
return V_8 ;
}
struct V_16 * F_226 ( struct V_81 * V_297 , T_4 V_80 ,
const char * V_237 )
{
struct V_7 * V_8 ;
struct V_16 * V_17 ;
struct V_158 * V_159 ;
V_17 = F_115 ( sizeof( * V_17 ) , V_112 ) ;
if ( ! V_17 )
return NULL ;
V_8 = F_224 ( V_297 , V_80 , V_237 ) ;
if ( ! V_8 )
goto V_310;
V_17 -> V_38 = V_8 -> V_9 ;
if ( V_17 -> V_311 & V_312 )
V_8 -> V_9 = & V_313 ;
else
V_8 -> V_9 = & V_314 ;
V_159 = F_123 ( V_8 ) ;
V_159 -> V_315 = V_17 ;
F_215 ( V_8 ) ;
return V_17 ;
V_310:
F_75 ( V_17 ) ;
return NULL ;
}
static T_8 F_227 ( struct V_316 * V_8 ,
struct V_317 * V_318 , char * V_84 )
{
struct V_7 * V_319 = F_228 ( V_8 ) ;
struct V_16 * V_17 = F_4 ( V_319 ) ;
return sprintf ( V_84 , L_34 , V_17 -> V_82 ) ;
}
static T_8 F_229 ( struct V_316 * V_8 ,
struct V_317 * V_318 , char * V_84 )
{
struct V_7 * V_319 = F_228 ( V_8 ) ;
struct V_16 * V_17 = F_4 ( V_319 ) ;
return sprintf ( V_84 , L_35 , F_9 ( V_320 , & V_17 -> V_19 ) ) ;
}
void F_230 ( struct V_7 * V_319 , int V_321 )
{
struct V_16 * V_17 = F_4 ( V_319 ) ;
if ( V_321 > 0 ) {
F_7 ( V_320 , & V_17 -> V_19 ) ;
F_27 ( V_17 , L_36
L_37 ) ;
} else
F_16 ( V_320 , & V_17 -> V_19 ) ;
}
static T_8 F_231 ( struct V_316 * V_8 ,
struct V_317 * V_318 ,
const char * V_84 , T_9 V_322 )
{
unsigned long V_321 = F_232 ( V_84 , NULL , 0 ) ;
F_230 ( F_228 ( V_8 ) , V_321 ) ;
return V_322 ;
}
int F_233 ( struct V_7 * V_8 )
{
return F_234 ( & V_8 -> V_8 , & V_323 ) ;
}
static void F_235 ( struct V_16 * V_17 , union V_69 * V_70 )
{
struct V_16 * V_74 ;
struct V_7 * V_324 = V_17 -> V_8 ;
F_236 ( V_324 ) ;
memcpy ( & V_17 -> V_77 . V_325 . V_326 ,
& V_70 -> V_325 . V_326 ,
sizeof( V_70 -> V_325 . V_326 ) ) ;
memcpy ( V_324 -> V_85 + 4 , & V_17 -> V_77 , sizeof( V_17 -> V_77 ) ) ;
F_16 ( V_327 , & V_17 -> V_19 ) ;
F_237 ( V_324 ) ;
if ( ! F_9 ( V_23 , & V_17 -> V_19 ) ) {
F_11 ( & V_17 -> V_25 ) ;
F_12 (child_priv, &priv->child_intfs, list)
F_235 ( V_74 , V_70 ) ;
F_14 ( & V_17 -> V_25 ) ;
}
}
static int F_238 ( struct V_7 * V_8 ,
struct V_328 * V_329 )
{
union V_69 * V_70 = (union V_69 * ) ( V_329 -> V_330 + 4 ) ;
int V_33 = 0 ;
F_236 ( V_8 ) ;
if ( memcmp ( V_8 -> V_85 , V_329 -> V_330 ,
4 + sizeof( V_70 -> V_325 . V_331 ) ) ||
V_70 -> V_325 . V_326 == 0 )
V_33 = - V_27 ;
F_237 ( V_8 ) ;
return V_33 ;
}
static int F_239 ( struct V_7 * V_8 , void * V_45 )
{
struct V_16 * V_17 = F_4 ( V_8 ) ;
struct V_328 * V_329 = V_45 ;
int V_33 ;
if ( ! ( V_8 -> V_332 & V_333 ) && F_240 ( V_8 ) )
return - V_90 ;
V_33 = F_238 ( V_8 , V_329 ) ;
if ( V_33 )
return V_33 ;
F_235 ( V_17 , (union V_69 * ) ( V_329 -> V_330 + 4 ) ) ;
F_145 ( V_334 , & V_17 -> V_288 ) ;
return 0 ;
}
static T_8 F_241 ( struct V_316 * V_8 ,
struct V_317 * V_318 ,
const char * V_84 , T_9 V_322 )
{
int V_82 ;
int V_33 ;
if ( sscanf ( V_84 , L_38 , & V_82 ) != 1 )
return - V_27 ;
if ( V_82 <= 0 || V_82 > 0xffff || V_82 == 0x8000 )
return - V_27 ;
V_82 |= 0x8000 ;
V_33 = F_242 ( F_228 ( V_8 ) , V_82 ) ;
return V_33 ? V_33 : V_322 ;
}
static T_8 F_243 ( struct V_316 * V_8 ,
struct V_317 * V_318 ,
const char * V_84 , T_9 V_322 )
{
int V_82 ;
int V_33 ;
if ( sscanf ( V_84 , L_38 , & V_82 ) != 1 )
return - V_27 ;
if ( V_82 < 0 || V_82 > 0xffff )
return - V_27 ;
V_33 = F_244 ( F_228 ( V_8 ) , V_82 ) ;
return V_33 ? V_33 : V_322 ;
}
int F_245 ( struct V_7 * V_8 )
{
return F_234 ( & V_8 -> V_8 , & V_335 ) ;
}
void F_246 ( struct V_16 * V_17 , struct V_81 * V_297 )
{
V_17 -> V_311 = V_297 -> V_336 . V_337 ;
if ( V_17 -> V_311 & V_338 ) {
V_17 -> V_8 -> V_339 |= V_30 | V_340 ;
if ( V_17 -> V_311 & V_341 )
V_17 -> V_8 -> V_339 |= V_31 ;
V_17 -> V_8 -> V_28 |= V_17 -> V_8 -> V_339 ;
}
}
static struct V_7 * F_247 ( const char * V_342 ,
struct V_81 * V_297 , T_4 V_80 )
{
struct V_16 * V_17 ;
struct V_343 V_318 ;
struct V_158 * V_159 ;
int V_67 = - V_222 ;
V_17 = F_226 ( V_297 , V_80 , V_342 ) ;
if ( ! V_17 )
goto V_344;
F_248 ( V_17 -> V_8 , V_297 -> V_8 . V_189 ) ;
V_17 -> V_8 -> V_345 = V_80 - 1 ;
V_67 = F_249 ( V_297 , V_80 , & V_318 ) ;
if ( V_67 ) {
F_188 ( V_236 L_39 ,
V_297 -> V_237 , V_80 ) ;
goto V_346;
}
V_17 -> V_36 = F_250 ( V_318 . V_347 ) ;
V_17 -> V_8 -> V_35 = F_28 ( V_17 -> V_36 ) ;
V_17 -> V_34 = V_17 -> V_37 = V_17 -> V_8 -> V_35 ;
V_17 -> V_8 -> V_347 = V_348 ;
V_17 -> V_8 -> V_349 = sizeof( struct V_130 ) ;
V_67 = F_251 ( V_297 , V_80 , 0 , & V_17 -> V_82 ) ;
if ( V_67 ) {
F_188 ( V_236 L_40 ,
V_297 -> V_237 , V_80 , V_67 ) ;
goto V_346;
}
F_246 ( V_17 , V_297 ) ;
V_17 -> V_82 |= 0x8000 ;
V_17 -> V_8 -> V_142 [ 8 ] = V_17 -> V_82 >> 8 ;
V_17 -> V_8 -> V_142 [ 9 ] = V_17 -> V_82 & 0xff ;
V_67 = F_252 ( V_297 , V_80 , 0 , & V_17 -> V_77 , NULL ) ;
if ( V_67 ) {
F_188 ( V_236 L_41 ,
V_297 -> V_237 , V_80 , V_67 ) ;
goto V_346;
}
memcpy ( V_17 -> V_8 -> V_85 + 4 , V_17 -> V_77 . V_98 ,
sizeof( union V_69 ) ) ;
F_7 ( V_327 , & V_17 -> V_19 ) ;
V_67 = F_193 ( V_17 -> V_8 , V_297 , V_80 ) ;
if ( V_67 ) {
F_188 ( V_236 L_42 ,
V_297 -> V_237 , V_80 , V_67 ) ;
goto V_346;
}
F_253 ( & V_17 -> V_350 ,
V_17 -> V_137 , V_351 ) ;
F_254 ( & V_17 -> V_350 ) ;
V_67 = F_255 ( V_17 -> V_8 ) ;
if ( V_67 ) {
F_188 ( V_236 L_43 ,
V_297 -> V_237 , V_80 , V_67 ) ;
goto V_352;
}
V_67 = - V_222 ;
if ( F_256 ( V_17 -> V_8 ) )
goto V_353;
if ( F_245 ( V_17 -> V_8 ) )
goto V_353;
if ( F_233 ( V_17 -> V_8 ) )
goto V_353;
if ( F_234 ( & V_17 -> V_8 -> V_8 , & V_354 ) )
goto V_353;
if ( F_234 ( & V_17 -> V_8 -> V_8 , & V_355 ) )
goto V_353;
return V_17 -> V_8 ;
V_353:
F_257 ( V_17 -> V_8 ) ;
V_352:
F_258 ( & V_17 -> V_350 ) ;
F_203 ( V_334 ) ;
F_7 ( V_207 , & V_17 -> V_19 ) ;
F_179 ( & V_17 -> V_216 ) ;
F_203 ( V_17 -> V_186 ) ;
F_22 ( V_17 -> V_8 ) ;
V_346:
V_159 = F_123 ( V_17 -> V_8 ) ;
V_159 -> V_304 ( V_17 -> V_8 ) ;
F_75 ( V_17 ) ;
V_344:
return F_259 ( V_67 ) ;
}
static void F_260 ( struct V_81 * V_316 )
{
struct V_78 * V_79 ;
struct V_7 * V_8 ;
struct V_16 * V_17 ;
int V_356 ;
int V_322 = 0 ;
V_79 = F_77 ( sizeof *V_79 , V_112 ) ;
if ( ! V_79 )
return;
F_116 ( V_79 ) ;
for ( V_356 = F_261 ( V_316 ) ; V_356 <= F_262 ( V_316 ) ; ++ V_356 ) {
if ( ! F_54 ( V_316 , V_356 ) )
continue;
V_8 = F_247 ( L_44 , V_316 , V_356 ) ;
if ( ! F_196 ( V_8 ) ) {
V_17 = F_4 ( V_8 ) ;
F_69 ( & V_17 -> V_104 , V_79 ) ;
V_322 ++ ;
}
}
if ( ! V_322 ) {
F_75 ( V_79 ) ;
return;
}
F_263 ( V_316 , & V_357 , V_79 ) ;
}
static void F_264 ( struct V_81 * V_316 , void * V_83 )
{
struct V_16 * V_17 , * V_358 , * V_24 , * V_255 ;
struct V_78 * V_79 = V_83 ;
if ( ! V_79 )
return;
F_85 (priv, tmp, dev_list, list) {
struct V_158 * V_359 = F_123 ( V_17 -> V_8 ) ;
F_258 ( & V_17 -> V_350 ) ;
F_203 ( V_334 ) ;
F_7 ( V_360 , & V_17 -> V_19 ) ;
F_265 () ;
F_13 ( V_17 -> V_8 , V_17 -> V_8 -> V_19 & ~ V_26 ) ;
F_61 () ;
F_7 ( V_207 , & V_17 -> V_19 ) ;
F_179 ( & V_17 -> V_216 ) ;
F_203 ( V_17 -> V_186 ) ;
F_266 ( & V_17 -> V_280 ) ;
F_257 ( V_17 -> V_8 ) ;
F_267 ( & V_17 -> V_280 ) ;
V_359 -> V_304 ( V_17 -> V_8 ) ;
F_85 (cpriv, tcpriv, &priv->child_intfs, list) {
struct V_158 * V_361 ;
V_361 = F_123 ( V_24 -> V_8 ) ;
V_361 -> V_304 ( V_24 -> V_8 ) ;
F_75 ( V_24 ) ;
}
F_75 ( V_17 ) ;
}
F_75 ( V_79 ) ;
}
static int T_10 F_268 ( void )
{
int V_33 ;
V_234 = F_172 ( V_234 ) ;
V_234 = F_29 ( V_234 , V_362 ) ;
V_234 = F_269 ( V_234 , V_363 ) ;
V_235 = F_172 ( V_235 ) ;
V_235 = F_29 ( V_235 , V_362 ) ;
V_235 = F_270 ( V_235 , 2 * V_364 , V_363 ) ;
#ifdef F_271
V_365 = F_29 ( V_365 , V_366 ) ;
V_365 = F_269 ( V_365 , 0 ) ;
#endif
F_272 ( V_367 > V_368 ) ;
V_33 = F_273 () ;
if ( V_33 )
return V_33 ;
V_334 = F_194 ( L_45 ,
V_249 ) ;
if ( ! V_334 ) {
V_33 = - V_222 ;
goto V_369;
}
F_274 ( & V_152 ) ;
V_33 = F_275 ( & V_357 ) ;
if ( V_33 )
goto V_370;
V_33 = F_276 () ;
if ( V_33 )
goto V_371;
#ifdef F_277
F_278 ( & V_372 ) ;
#endif
return 0 ;
V_371:
F_279 ( & V_357 ) ;
V_370:
F_280 ( & V_152 ) ;
F_199 ( V_334 ) ;
V_369:
F_281 () ;
return V_33 ;
}
static void T_11 F_282 ( void )
{
#ifdef F_277
F_283 ( & V_372 ) ;
#endif
F_284 () ;
F_279 ( & V_357 ) ;
F_280 ( & V_152 ) ;
F_281 () ;
F_199 ( V_334 ) ;
}
