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
if ( F_25 ( V_8 ) ) {
if ( V_32 > F_26 ( V_8 ) )
return - V_27 ;
if ( V_32 > V_17 -> V_33 )
F_27 ( V_17 , L_3 ,
V_17 -> V_33 ) ;
V_8 -> V_34 = V_32 ;
return 0 ;
}
if ( V_32 > F_28 ( V_17 -> V_35 ) )
return - V_27 ;
V_17 -> V_36 = V_32 ;
if ( V_17 -> V_33 < V_17 -> V_36 )
F_5 ( V_17 , L_4
L_5 , V_17 -> V_33 ) ;
V_8 -> V_34 = F_29 ( V_17 -> V_33 , V_17 -> V_36 ) ;
return 0 ;
}
static bool F_30 ( const struct V_37 * V_38 ,
struct V_7 * V_8 )
{
struct V_39 * V_39 = F_31 ( V_8 ) ;
struct V_40 * V_41 ;
struct V_42 * V_43 = (struct V_42 * ) V_38 ;
struct V_44 * V_45 = (struct V_44 * ) V_38 ;
T_2 V_46 ;
switch ( V_38 -> V_47 ) {
case V_48 :
V_41 = F_32 ( V_8 ) ;
if ( ! V_41 )
return false ;
V_46 = F_33 ( V_39 , V_41 , 0 ,
V_43 -> V_49 . V_50 ,
V_51 ) ;
F_34 ( V_41 ) ;
if ( V_46 )
return true ;
break;
case V_52 :
if ( F_35 ( V_53 ) &&
F_36 ( V_39 , & V_45 -> V_54 , V_8 , 1 ) )
return true ;
break;
}
return false ;
}
static struct V_7 * F_37 ( struct V_7 * V_8 )
{
struct V_7 * V_55 ;
F_38 () ;
V_55 = F_39 ( V_8 ) ;
if ( V_55 )
F_40 ( V_55 ) ;
F_41 () ;
if ( V_55 )
return V_55 ;
F_40 ( V_8 ) ;
return V_8 ;
}
static int F_42 ( struct V_7 * V_56 , void * V_57 )
{
struct V_58 * V_59 = V_57 ;
int V_60 = 0 ;
if ( F_30 ( V_59 -> V_38 , V_56 ) ) {
F_40 ( V_56 ) ;
V_59 -> V_61 = V_56 ;
V_60 = 1 ;
}
return V_60 ;
}
static struct V_7 * F_43 (
const struct V_37 * V_38 , struct V_7 * V_8 )
{
struct V_58 V_59 = {
. V_38 = V_38 ,
} ;
F_38 () ;
if ( F_30 ( V_38 , V_8 ) ) {
F_40 ( V_8 ) ;
V_59 . V_61 = V_8 ;
goto V_62;
}
F_44 ( V_8 , F_42 , & V_59 ) ;
V_62:
F_41 () ;
return V_59 . V_61 ;
}
static int F_45 ( struct V_16 * V_17 ,
const union V_63 * V_64 ,
T_3 V_65 ,
const struct V_37 * V_38 ,
int V_66 ,
struct V_7 * * V_67 )
{
struct V_16 * V_68 ;
struct V_7 * V_69 = NULL ;
int V_70 = 0 ;
if ( V_17 -> V_65 == V_65 &&
( ! V_64 || ! memcmp ( V_64 , & V_17 -> V_71 , sizeof( * V_64 ) ) ) ) {
if ( ! V_38 ) {
V_69 = F_37 ( V_17 -> V_8 ) ;
} else {
V_69 = F_43 ( V_38 , V_17 -> V_8 ) ;
}
if ( V_69 ) {
if ( ! * V_67 )
* V_67 = V_69 ;
else
F_46 ( V_69 ) ;
++ V_70 ;
}
}
F_47 ( & V_17 -> V_25 , V_66 ) ;
F_12 (child_priv, &priv->child_intfs, list) {
V_70 += F_45 ( V_68 , V_64 ,
V_65 , V_38 ,
V_66 + 1 ,
V_67 ) ;
if ( V_70 > 1 )
break;
}
F_14 ( & V_17 -> V_25 ) ;
return V_70 ;
}
static int F_48 ( struct V_72 * V_73 , T_4 V_74 ,
T_3 V_65 ,
const union V_63 * V_64 ,
const struct V_37 * V_38 ,
struct V_7 * * V_69 )
{
struct V_16 * V_17 ;
int V_70 = 0 ;
* V_69 = NULL ;
F_12 (priv, dev_list, list) {
if ( V_17 -> V_74 != V_74 )
continue;
V_70 += F_45 ( V_17 , V_64 , V_65 ,
V_38 , 0 , V_69 ) ;
if ( V_70 > 1 )
break;
}
return V_70 ;
}
static struct V_7 * F_49 (
struct V_75 * V_8 , T_4 V_74 , T_3 V_76 ,
const union V_63 * V_64 , const struct V_37 * V_38 ,
void * V_77 )
{
struct V_7 * V_69 ;
struct V_72 * V_73 = V_77 ;
T_3 V_65 ;
int V_70 ;
int V_60 ;
if ( ! F_50 ( V_8 , V_74 ) )
return NULL ;
V_60 = F_51 ( V_8 , V_74 , V_76 , & V_65 ) ;
if ( V_60 )
return NULL ;
if ( ! V_73 )
return NULL ;
V_70 = F_48 ( V_73 , V_74 , V_65 ,
V_64 , NULL , & V_69 ) ;
switch ( V_70 ) {
case 0 :
return NULL ;
case 1 :
return V_69 ;
}
F_46 ( V_69 ) ;
V_70 = F_48 ( V_73 , V_74 , V_65 ,
V_64 , V_38 , & V_69 ) ;
switch ( V_70 ) {
case 0 :
return NULL ;
default:
F_52 ( & V_8 -> V_8 ,
L_6 ) ;
case 1 :
return V_69 ;
}
}
int F_53 ( struct V_7 * V_8 , const char * V_78 )
{
struct V_16 * V_17 = F_4 ( V_8 ) ;
if ( ( F_9 ( V_29 , & V_17 -> V_19 ) &&
! strcmp ( V_78 , L_7 ) ) ||
( ! F_9 ( V_29 , & V_17 -> V_19 ) &&
! strcmp ( V_78 , L_8 ) ) ) {
return 0 ;
}
if ( F_54 ( V_8 -> V_79 ) && ! strcmp ( V_78 , L_7 ) ) {
F_7 ( V_29 , & V_17 -> V_19 ) ;
F_27 ( V_17 , L_9
L_10 ) ;
F_55 ( V_8 ) ;
F_56 ( V_8 , F_26 ( V_8 ) ) ;
F_57 () ;
V_17 -> V_80 . V_81 . V_82 &= ~ V_83 ;
F_58 ( V_8 ) ;
return ( ! F_59 () ) ? - V_84 : 0 ;
}
if ( ! strcmp ( V_78 , L_8 ) ) {
F_16 ( V_29 , & V_17 -> V_19 ) ;
F_55 ( V_8 ) ;
F_56 ( V_8 , F_29 ( V_17 -> V_33 , V_8 -> V_34 ) ) ;
F_57 () ;
F_58 ( V_8 ) ;
return ( ! F_59 () ) ? - V_84 : 0 ;
}
return - V_27 ;
}
struct V_85 * F_60 ( struct V_7 * V_8 , void * V_64 )
{
struct V_16 * V_17 = F_4 ( V_8 ) ;
struct V_86 * V_87 = V_17 -> V_88 . V_86 ;
struct V_85 * V_89 ;
int V_60 ;
while ( V_87 ) {
V_89 = F_61 ( V_87 , struct V_85 , V_86 ) ;
V_60 = memcmp ( V_64 , V_89 -> V_90 . V_91 . V_92 ,
sizeof ( union V_63 ) ) ;
if ( V_60 < 0 )
V_87 = V_87 -> V_93 ;
else if ( V_60 > 0 )
V_87 = V_87 -> V_94 ;
else
return V_89 ;
}
return NULL ;
}
static int F_62 ( struct V_7 * V_8 , struct V_85 * V_89 )
{
struct V_16 * V_17 = F_4 ( V_8 ) ;
struct V_86 * * V_87 = & V_17 -> V_88 . V_86 ;
struct V_86 * V_95 = NULL ;
struct V_85 * V_96 ;
int V_60 ;
while ( * V_87 ) {
V_95 = * V_87 ;
V_96 = F_61 ( V_95 , struct V_85 , V_86 ) ;
V_60 = memcmp ( V_89 -> V_90 . V_91 . V_92 , V_96 -> V_90 . V_91 . V_92 ,
sizeof ( union V_63 ) ) ;
if ( V_60 < 0 )
V_87 = & V_95 -> V_93 ;
else if ( V_60 > 0 )
V_87 = & V_95 -> V_94 ;
else
return - V_97 ;
}
F_63 ( & V_89 -> V_86 , V_95 , V_87 ) ;
F_64 ( & V_89 -> V_86 , & V_17 -> V_88 ) ;
F_65 ( & V_89 -> V_98 , & V_17 -> V_99 ) ;
return 0 ;
}
static void F_66 ( struct V_7 * V_8 , struct V_85 * V_89 )
{
struct V_100 * V_101 ;
while ( ( V_101 = F_67 ( & V_89 -> V_102 ) ) )
F_68 ( V_101 ) ;
F_5 ( F_4 ( V_8 ) , L_11 ) ;
F_69 ( V_8 , V_89 -> V_90 . V_91 . V_92 ) ;
if ( V_89 -> V_103 )
F_70 ( V_89 -> V_103 ) ;
F_71 ( V_89 ) ;
}
struct V_104 * F_72 ( struct V_7 * V_8 )
{
struct V_104 * V_105 ;
V_105 = F_73 ( sizeof *V_105 , V_106 ) ;
if ( ! V_105 )
return NULL ;
V_105 -> V_8 = V_8 ;
memset ( V_105 -> V_89 . V_90 . V_91 . V_92 , 0 , 16 ) ;
if ( F_74 ( V_105 ) ) {
F_71 ( V_105 ) ;
return NULL ;
}
return V_105 ;
}
int F_74 ( struct V_104 * V_105 )
{
struct V_16 * V_17 = F_4 ( V_105 -> V_8 ) ;
struct V_86 * V_87 ;
struct V_85 * V_89 ;
int V_60 = 1 ;
F_75 ( & V_17 -> V_107 ) ;
V_87 = F_76 ( & V_17 -> V_88 ) ;
while ( V_87 ) {
V_89 = F_61 ( V_87 , struct V_85 , V_86 ) ;
if ( memcmp ( V_105 -> V_89 . V_90 . V_91 . V_92 , V_89 -> V_90 . V_91 . V_92 ,
sizeof ( union V_63 ) ) < 0 ) {
V_105 -> V_89 = * V_89 ;
V_60 = 0 ;
break;
}
V_87 = F_77 ( V_87 ) ;
}
F_78 ( & V_17 -> V_107 ) ;
return V_60 ;
}
void F_79 ( struct V_104 * V_105 ,
struct V_85 * V_89 )
{
* V_89 = V_105 -> V_89 ;
}
void F_80 ( struct V_7 * V_8 )
{
struct V_16 * V_17 = F_4 ( V_8 ) ;
struct V_85 * V_89 , * V_108 ;
F_75 ( & V_17 -> V_107 ) ;
F_81 (path, tp, &priv->path_list, list) {
F_5 ( V_17 , L_12 ,
F_82 ( F_83 ( & V_89 -> V_90 ) ) ,
V_89 -> V_90 . V_91 . V_92 ) ;
V_89 -> V_109 = 0 ;
}
F_78 ( & V_17 -> V_107 ) ;
}
static void F_84 ( struct V_100 * V_101 , const char * V_110 )
{
struct V_111 * V_112 ;
V_112 = (struct V_111 * ) F_85 ( V_101 , sizeof( * V_112 ) ) ;
memcpy ( V_112 -> V_113 , V_110 , V_114 ) ;
}
void F_58 ( struct V_7 * V_8 )
{
struct V_16 * V_17 = F_4 ( V_8 ) ;
struct V_85 * V_89 , * V_108 ;
F_86 ( V_115 ) ;
unsigned long V_19 ;
F_87 ( V_8 ) ;
F_88 ( & V_17 -> V_107 , V_19 ) ;
F_89 ( & V_17 -> V_99 , & V_115 ) ;
F_12 (path, &remove_list, list)
F_90 ( & V_89 -> V_86 , & V_17 -> V_88 ) ;
F_81 (path, tp, &remove_list, list) {
if ( V_89 -> V_116 )
F_91 ( V_89 -> V_117 , V_89 -> V_116 ) ;
F_92 ( & V_17 -> V_107 , V_19 ) ;
F_93 ( V_8 ) ;
F_94 ( & V_89 -> V_118 ) ;
F_66 ( V_8 , V_89 ) ;
F_87 ( V_8 ) ;
F_88 ( & V_17 -> V_107 , V_19 ) ;
}
F_92 ( & V_17 -> V_107 , V_19 ) ;
F_93 ( V_8 ) ;
}
static void F_95 ( int V_119 ,
struct V_120 * V_90 ,
void * V_121 )
{
struct V_85 * V_89 = V_121 ;
struct V_7 * V_8 = V_89 -> V_8 ;
struct V_16 * V_17 = F_4 ( V_8 ) ;
struct V_122 * V_103 = NULL ;
struct V_122 * V_123 = NULL ;
struct V_124 * V_125 , * V_126 ;
struct V_127 V_128 ;
struct V_100 * V_101 ;
unsigned long V_19 ;
if ( ! V_119 )
F_5 ( V_17 , L_13 ,
F_82 ( F_83 ( V_90 ) ) ,
V_90 -> V_91 . V_92 ) ;
else
F_5 ( V_17 , L_14 ,
V_119 , V_89 -> V_90 . V_91 . V_92 ) ;
F_96 ( & V_128 ) ;
if ( ! V_119 ) {
struct V_129 V_130 ;
if ( ! F_97 ( V_17 -> V_131 , V_17 -> V_74 , V_90 , & V_130 ) )
V_103 = F_98 ( V_8 , V_17 -> V_132 , & V_130 ) ;
}
F_88 ( & V_17 -> V_107 , V_19 ) ;
if ( ! F_99 ( V_103 ) ) {
V_89 -> V_90 = * V_90 ;
V_123 = V_89 -> V_103 ;
V_89 -> V_103 = V_103 ;
F_5 ( V_17 , L_15 ,
V_103 , F_82 ( F_83 ( V_90 ) ) ,
V_90 -> V_133 ) ;
while ( ( V_101 = F_67 ( & V_89 -> V_102 ) ) )
F_100 ( & V_128 , V_101 ) ;
F_81 (neigh, tn, &path->neigh_list, list) {
if ( V_125 -> V_103 ) {
F_101 ( V_125 -> V_103 != V_123 ) ;
F_70 ( V_125 -> V_103 ) ;
}
F_102 ( & V_89 -> V_103 -> V_134 ) ;
V_125 -> V_103 = V_89 -> V_103 ;
if ( F_103 ( V_8 , V_125 -> V_110 ) ) {
if ( ! F_104 ( V_125 ) )
F_105 ( V_125 , F_106 ( V_8 ,
V_89 ,
V_125 ) ) ;
if ( ! F_104 ( V_125 ) ) {
F_107 ( V_125 ) ;
continue;
}
}
while ( ( V_101 = F_67 ( & V_125 -> V_102 ) ) )
F_100 ( & V_128 , V_101 ) ;
}
V_89 -> V_109 = 1 ;
}
V_89 -> V_116 = NULL ;
F_108 ( & V_89 -> V_118 ) ;
F_92 ( & V_17 -> V_107 , V_19 ) ;
if ( F_99 ( V_103 ) )
F_69 ( V_8 , V_89 -> V_90 . V_91 . V_92 ) ;
if ( V_123 )
F_70 ( V_123 ) ;
while ( ( V_101 = F_67 ( & V_128 ) ) ) {
int V_60 ;
V_101 -> V_8 = V_8 ;
V_60 = F_109 ( V_101 ) ;
if ( V_60 )
F_27 ( V_17 , L_16 ,
V_135 , V_60 ) ;
}
}
static struct V_85 * F_110 ( struct V_7 * V_8 , void * V_64 )
{
struct V_16 * V_17 = F_4 ( V_8 ) ;
struct V_85 * V_89 ;
if ( ! V_17 -> V_136 )
return NULL ;
V_89 = F_111 ( sizeof *V_89 , V_137 ) ;
if ( ! V_89 )
return NULL ;
V_89 -> V_8 = V_8 ;
F_96 ( & V_89 -> V_102 ) ;
F_112 ( & V_89 -> V_138 ) ;
if ( F_113 ( V_17 -> V_131 , V_17 -> V_74 ) )
V_89 -> V_90 . V_139 = V_140 ;
else
V_89 -> V_90 . V_139 = V_141 ;
memcpy ( V_89 -> V_90 . V_91 . V_92 , V_64 , sizeof ( union V_63 ) ) ;
V_89 -> V_90 . V_142 = V_17 -> V_71 ;
V_89 -> V_90 . V_76 = F_114 ( V_17 -> V_76 ) ;
V_89 -> V_90 . V_143 = 1 ;
V_89 -> V_90 . V_144 = V_17 -> V_136 -> V_145 . V_144 ;
return V_89 ;
}
static int F_115 ( struct V_7 * V_8 ,
struct V_85 * V_89 )
{
struct V_16 * V_17 = F_4 ( V_8 ) ;
F_5 ( V_17 , L_17 ,
V_89 -> V_90 . V_91 . V_92 ) ;
F_116 ( & V_89 -> V_118 ) ;
V_89 -> V_117 =
F_117 ( & V_146 , V_17 -> V_131 , V_17 -> V_74 ,
& V_89 -> V_90 ,
V_147 |
V_148 |
V_149 |
V_150 |
V_151 ,
1000 , V_137 ,
F_95 ,
V_89 , & V_89 -> V_116 ) ;
if ( V_89 -> V_117 < 0 ) {
F_27 ( V_17 , L_18 , V_89 -> V_117 ) ;
V_89 -> V_116 = NULL ;
F_108 ( & V_89 -> V_118 ) ;
return V_89 -> V_117 ;
}
return 0 ;
}
static void F_118 ( struct V_100 * V_101 , T_4 * V_110 ,
struct V_7 * V_8 )
{
struct V_16 * V_17 = F_4 ( V_8 ) ;
struct V_152 * V_153 = F_119 ( V_8 ) ;
struct V_85 * V_89 ;
struct V_124 * V_125 ;
unsigned long V_19 ;
F_88 ( & V_17 -> V_107 , V_19 ) ;
V_125 = F_120 ( V_110 , V_8 ) ;
if ( ! V_125 ) {
F_92 ( & V_17 -> V_107 , V_19 ) ;
++ V_8 -> V_154 . V_155 ;
F_121 ( V_101 ) ;
return;
}
V_89 = F_60 ( V_8 , V_110 + 4 ) ;
if ( ! V_89 ) {
V_89 = F_110 ( V_8 , V_110 + 4 ) ;
if ( ! V_89 )
goto V_156;
F_62 ( V_8 , V_89 ) ;
}
F_65 ( & V_125 -> V_98 , & V_89 -> V_138 ) ;
if ( V_89 -> V_103 ) {
F_102 ( & V_89 -> V_103 -> V_134 ) ;
V_125 -> V_103 = V_89 -> V_103 ;
if ( F_103 ( V_8 , V_125 -> V_110 ) ) {
if ( ! F_104 ( V_125 ) )
F_105 ( V_125 , F_106 ( V_8 , V_89 , V_125 ) ) ;
if ( ! F_104 ( V_125 ) ) {
F_107 ( V_125 ) ;
goto V_157;
}
if ( F_122 ( & V_125 -> V_102 ) <
V_158 ) {
F_84 ( V_101 , V_125 -> V_110 ) ;
F_100 ( & V_125 -> V_102 , V_101 ) ;
} else {
F_27 ( V_17 , L_19 ,
F_122 ( & V_125 -> V_102 ) ) ;
goto V_157;
}
} else {
F_92 ( & V_17 -> V_107 , V_19 ) ;
V_89 -> V_103 -> V_159 = V_153 -> V_160 ( V_8 , V_101 , V_89 -> V_103 -> V_103 ,
F_123 ( V_110 ) ) ;
F_124 ( V_125 ) ;
return;
}
} else {
V_125 -> V_103 = NULL ;
if ( ! V_89 -> V_116 && F_115 ( V_8 , V_89 ) )
goto V_156;
if ( F_122 ( & V_125 -> V_102 ) < V_158 ) {
F_84 ( V_101 , V_125 -> V_110 ) ;
F_100 ( & V_125 -> V_102 , V_101 ) ;
} else {
goto V_157;
}
}
F_92 ( & V_17 -> V_107 , V_19 ) ;
F_124 ( V_125 ) ;
return;
V_156:
F_107 ( V_125 ) ;
V_157:
++ V_8 -> V_154 . V_155 ;
F_121 ( V_101 ) ;
F_92 ( & V_17 -> V_107 , V_19 ) ;
F_124 ( V_125 ) ;
}
static void F_125 ( struct V_100 * V_101 , struct V_7 * V_8 ,
struct V_111 * V_112 )
{
struct V_16 * V_17 = F_4 ( V_8 ) ;
struct V_152 * V_153 = F_119 ( V_8 ) ;
struct V_85 * V_89 ;
unsigned long V_19 ;
F_88 ( & V_17 -> V_107 , V_19 ) ;
V_89 = F_60 ( V_8 , V_112 -> V_113 + 4 ) ;
if ( ! V_89 || ! V_89 -> V_109 ) {
int V_161 = 0 ;
if ( ! V_89 ) {
V_89 = F_110 ( V_8 , V_112 -> V_113 + 4 ) ;
V_161 = 1 ;
}
if ( V_89 ) {
if ( F_122 ( & V_89 -> V_102 ) < V_158 ) {
F_84 ( V_101 , V_112 -> V_113 ) ;
F_100 ( & V_89 -> V_102 , V_101 ) ;
} else {
++ V_8 -> V_154 . V_155 ;
F_121 ( V_101 ) ;
}
if ( ! V_89 -> V_116 && F_115 ( V_8 , V_89 ) ) {
F_92 ( & V_17 -> V_107 , V_19 ) ;
if ( V_161 )
F_66 ( V_8 , V_89 ) ;
return;
} else
F_62 ( V_8 , V_89 ) ;
} else {
++ V_8 -> V_154 . V_155 ;
F_121 ( V_101 ) ;
}
F_92 ( & V_17 -> V_107 , V_19 ) ;
return;
}
if ( V_89 -> V_103 ) {
F_5 ( V_17 , L_20 ,
F_82 ( F_83 ( & V_89 -> V_90 ) ) ) ;
F_92 ( & V_17 -> V_107 , V_19 ) ;
V_89 -> V_103 -> V_159 = V_153 -> V_160 ( V_8 , V_101 , V_89 -> V_103 -> V_103 ,
F_123 ( V_112 -> V_113 ) ) ;
return;
} else if ( ( V_89 -> V_116 || ! F_115 ( V_8 , V_89 ) ) &&
F_122 ( & V_89 -> V_102 ) < V_158 ) {
F_84 ( V_101 , V_112 -> V_113 ) ;
F_100 ( & V_89 -> V_102 , V_101 ) ;
} else {
++ V_8 -> V_154 . V_155 ;
F_121 ( V_101 ) ;
}
F_92 ( & V_17 -> V_107 , V_19 ) ;
}
static int F_126 ( struct V_100 * V_101 , struct V_7 * V_8 )
{
struct V_16 * V_17 = F_4 ( V_8 ) ;
struct V_152 * V_153 = F_119 ( V_8 ) ;
struct V_124 * V_125 ;
struct V_111 * V_112 ;
struct V_162 * V_163 ;
unsigned long V_19 ;
V_112 = (struct V_111 * ) V_101 -> V_59 ;
F_127 ( V_101 , sizeof( * V_112 ) ) ;
V_163 = (struct V_162 * ) V_101 -> V_59 ;
if ( F_128 ( V_112 -> V_113 [ 4 ] == 0xff ) ) {
if ( ( V_163 -> V_164 != F_129 ( V_165 ) ) &&
( V_163 -> V_164 != F_129 ( V_166 ) ) &&
( V_163 -> V_164 != F_129 ( V_167 ) ) &&
( V_163 -> V_164 != F_129 ( V_168 ) ) &&
( V_163 -> V_164 != F_129 ( V_169 ) ) ) {
++ V_8 -> V_154 . V_155 ;
F_121 ( V_101 ) ;
return V_170 ;
}
V_112 -> V_113 [ 8 ] = ( V_17 -> V_76 >> 8 ) & 0xff ;
V_112 -> V_113 [ 9 ] = V_17 -> V_76 & 0xff ;
V_125 = F_130 ( V_8 , V_112 -> V_113 ) ;
if ( F_131 ( V_125 ) )
goto V_171;
F_132 ( V_8 , V_112 -> V_113 , V_101 ) ;
return V_170 ;
}
switch ( V_163 -> V_164 ) {
case F_129 ( V_165 ) :
case F_129 ( V_166 ) :
case F_129 ( V_169 ) :
V_125 = F_130 ( V_8 , V_112 -> V_113 ) ;
if ( F_128 ( ! V_125 ) ) {
F_118 ( V_101 , V_112 -> V_113 , V_8 ) ;
return V_170 ;
}
break;
case F_129 ( V_167 ) :
case F_129 ( V_168 ) :
F_125 ( V_101 , V_8 , V_112 ) ;
return V_170 ;
default:
++ V_8 -> V_154 . V_155 ;
F_121 ( V_101 ) ;
return V_170 ;
}
V_171:
if ( F_104 ( V_125 ) ) {
if ( F_133 ( V_125 ) ) {
F_134 ( V_8 , V_101 , F_104 ( V_125 ) ) ;
goto V_172;
}
} else if ( V_125 -> V_103 ) {
V_125 -> V_103 -> V_159 = V_153 -> V_160 ( V_8 , V_101 , V_125 -> V_103 -> V_103 ,
F_123 ( V_112 -> V_113 ) ) ;
goto V_172;
}
if ( F_122 ( & V_125 -> V_102 ) < V_158 ) {
F_84 ( V_101 , V_112 -> V_113 ) ;
F_88 ( & V_17 -> V_107 , V_19 ) ;
F_100 ( & V_125 -> V_102 , V_101 ) ;
F_92 ( & V_17 -> V_107 , V_19 ) ;
} else {
++ V_8 -> V_154 . V_155 ;
F_121 ( V_101 ) ;
}
V_172:
F_124 ( V_125 ) ;
return V_170 ;
}
static void F_135 ( struct V_7 * V_8 )
{
struct V_16 * V_17 = F_4 ( V_8 ) ;
F_27 ( V_17 , L_21 ,
F_136 ( V_173 - F_137 ( V_8 ) ) ) ;
F_27 ( V_17 , L_22 ,
F_138 ( V_8 ) ,
V_17 -> V_174 , V_17 -> V_175 ) ;
}
static int F_139 ( struct V_100 * V_101 ,
struct V_7 * V_8 ,
unsigned short type ,
const void * V_110 , const void * V_176 , unsigned V_177 )
{
struct V_162 * V_163 ;
V_163 = (struct V_162 * ) F_85 ( V_101 , sizeof *V_163 ) ;
V_163 -> V_164 = F_129 ( type ) ;
V_163 -> V_178 = 0 ;
F_84 ( V_101 , V_110 ) ;
return V_179 ;
}
static void F_140 ( struct V_7 * V_8 )
{
struct V_16 * V_17 = F_4 ( V_8 ) ;
if ( ! F_9 ( V_180 , & V_17 -> V_19 ) ) {
F_5 ( V_17 , L_23 ) ;
return;
}
F_141 ( V_17 -> V_181 , & V_17 -> V_182 ) ;
}
static int F_142 ( const struct V_7 * V_8 )
{
struct V_16 * V_17 = F_4 ( V_8 ) ;
if ( ! F_9 ( V_23 , & V_17 -> V_19 ) )
return V_8 -> V_183 ;
return V_17 -> V_184 -> V_183 ;
}
static T_5 F_143 ( struct V_185 * V_186 , T_4 * V_110 )
{
T_5 * V_187 = ( T_5 * ) V_110 ;
T_5 V_188 ;
V_188 = F_144 ( V_187 [ 3 ] , V_187 [ 4 ] , V_189 & V_187 [ 0 ] , 0 ) ;
return V_188 & V_186 -> V_190 ;
}
struct V_124 * F_130 ( struct V_7 * V_8 , T_4 * V_110 )
{
struct V_16 * V_17 = F_4 ( V_8 ) ;
struct V_191 * V_192 = & V_17 -> V_192 ;
struct V_185 * V_186 ;
struct V_124 * V_125 = NULL ;
T_5 V_193 ;
F_145 () ;
V_186 = F_146 ( V_192 -> V_186 ) ;
if ( ! V_186 )
goto V_194;
V_193 = F_143 ( V_186 , V_110 ) ;
for ( V_125 = F_146 ( V_186 -> V_195 [ V_193 ] ) ;
V_125 != NULL ;
V_125 = F_146 ( V_125 -> V_196 ) ) {
if ( memcmp ( V_110 , V_125 -> V_110 , V_114 ) == 0 ) {
if ( ! F_147 ( & V_125 -> V_197 ) ) {
V_125 = NULL ;
goto V_194;
}
if ( F_131 ( F_122 ( & V_125 -> V_102 ) < V_158 ) )
V_125 -> V_198 = V_173 ;
goto V_194;
}
}
V_194:
F_148 () ;
return V_125 ;
}
static void F_149 ( struct V_16 * V_17 )
{
struct V_191 * V_192 = & V_17 -> V_192 ;
struct V_185 * V_186 ;
unsigned long V_199 ;
unsigned long V_200 ;
unsigned long V_19 ;
int V_201 ;
F_86 ( V_115 ) ;
if ( F_9 ( V_202 , & V_17 -> V_19 ) )
return;
F_88 ( & V_17 -> V_107 , V_19 ) ;
V_186 = F_150 ( V_192 -> V_186 ,
F_151 ( & V_17 -> V_107 ) ) ;
if ( ! V_186 )
goto V_194;
V_200 = 2 * V_203 . V_204 ;
V_199 = V_173 - V_200 ;
if ( F_9 ( V_202 , & V_17 -> V_19 ) )
goto V_194;
for ( V_201 = 0 ; V_201 < V_186 -> V_205 ; V_201 ++ ) {
struct V_124 * V_125 ;
struct V_124 T_6 * * V_206 = & V_186 -> V_195 [ V_201 ] ;
while ( ( V_125 = F_150 ( * V_206 ,
F_151 ( & V_17 -> V_107 ) ) ) != NULL ) {
if ( F_152 ( V_199 , V_125 -> V_198 ) ) {
F_153 ( V_17 , V_125 -> V_110 + 4 , & V_115 ) ;
F_154 ( * V_206 ,
F_150 ( V_125 -> V_196 ,
F_151 ( & V_17 -> V_107 ) ) ) ;
F_155 ( & V_125 -> V_98 ) ;
F_156 ( & V_125 -> V_207 , V_208 ) ;
} else {
V_206 = & V_125 -> V_196 ;
}
}
}
V_194:
F_92 ( & V_17 -> V_107 , V_19 ) ;
F_157 ( & V_115 ) ;
}
static void F_158 ( struct V_209 * V_210 )
{
struct V_16 * V_17 =
F_159 ( V_210 , struct V_16 , V_211 . V_210 ) ;
F_149 ( V_17 ) ;
if ( ! F_9 ( V_202 , & V_17 -> V_19 ) )
F_160 ( V_17 -> V_181 , & V_17 -> V_211 ,
V_203 . V_204 ) ;
}
static struct V_124 * F_161 ( T_4 * V_110 ,
struct V_7 * V_8 )
{
struct V_124 * V_125 ;
V_125 = F_111 ( sizeof *V_125 , V_137 ) ;
if ( ! V_125 )
return NULL ;
V_125 -> V_8 = V_8 ;
memcpy ( & V_125 -> V_110 , V_110 , sizeof( V_125 -> V_110 ) ) ;
F_96 ( & V_125 -> V_102 ) ;
F_112 ( & V_125 -> V_98 ) ;
F_105 ( V_125 , NULL ) ;
F_162 ( & V_125 -> V_197 , 1 ) ;
return V_125 ;
}
struct V_124 * F_120 ( T_4 * V_110 ,
struct V_7 * V_8 )
{
struct V_16 * V_17 = F_4 ( V_8 ) ;
struct V_191 * V_192 = & V_17 -> V_192 ;
struct V_185 * V_186 ;
struct V_124 * V_125 ;
T_5 V_193 ;
V_186 = F_150 ( V_192 -> V_186 ,
F_151 ( & V_17 -> V_107 ) ) ;
if ( ! V_186 ) {
V_125 = NULL ;
goto V_194;
}
V_193 = F_143 ( V_186 , V_110 ) ;
for ( V_125 = F_150 ( V_186 -> V_195 [ V_193 ] ,
F_151 ( & V_17 -> V_107 ) ) ;
V_125 != NULL ;
V_125 = F_150 ( V_125 -> V_196 ,
F_151 ( & V_17 -> V_107 ) ) ) {
if ( memcmp ( V_110 , V_125 -> V_110 , V_114 ) == 0 ) {
if ( ! F_147 ( & V_125 -> V_197 ) ) {
V_125 = NULL ;
break;
}
V_125 -> V_198 = V_173 ;
goto V_194;
}
}
V_125 = F_161 ( V_110 , V_8 ) ;
if ( ! V_125 )
goto V_194;
F_163 ( & V_125 -> V_197 ) ;
V_125 -> V_198 = V_173 ;
F_154 ( V_125 -> V_196 ,
F_150 ( V_186 -> V_195 [ V_193 ] ,
F_151 ( & V_17 -> V_107 ) ) ) ;
F_154 ( V_186 -> V_195 [ V_193 ] , V_125 ) ;
F_163 ( & V_192 -> V_212 ) ;
V_194:
return V_125 ;
}
void F_164 ( struct V_124 * V_125 )
{
struct V_7 * V_8 = V_125 -> V_8 ;
struct V_16 * V_17 = F_4 ( V_8 ) ;
struct V_100 * V_101 ;
if ( V_125 -> V_103 )
F_70 ( V_125 -> V_103 ) ;
while ( ( V_101 = F_67 ( & V_125 -> V_102 ) ) ) {
++ V_8 -> V_154 . V_155 ;
F_121 ( V_101 ) ;
}
if ( F_104 ( V_125 ) )
F_165 ( F_104 ( V_125 ) ) ;
F_5 ( F_4 ( V_8 ) ,
L_24 ,
F_123 ( V_125 -> V_110 ) ,
V_125 -> V_110 + 4 ) ;
F_71 ( V_125 ) ;
if ( F_166 ( & V_17 -> V_192 . V_212 ) ) {
if ( F_9 ( V_213 , & V_17 -> V_19 ) )
F_108 ( & V_17 -> V_192 . V_214 ) ;
}
}
static void V_208 ( struct V_215 * V_216 )
{
struct V_124 * V_125 = F_159 ( V_216 , struct V_124 , V_207 ) ;
F_124 ( V_125 ) ;
}
void F_107 ( struct V_124 * V_125 )
{
struct V_7 * V_8 = V_125 -> V_8 ;
struct V_16 * V_17 = F_4 ( V_8 ) ;
struct V_191 * V_192 = & V_17 -> V_192 ;
struct V_185 * V_186 ;
struct V_124 T_6 * * V_206 ;
struct V_124 * V_87 ;
T_5 V_193 ;
V_186 = F_150 ( V_192 -> V_186 ,
F_151 ( & V_17 -> V_107 ) ) ;
if ( ! V_186 )
return;
V_193 = F_143 ( V_186 , V_125 -> V_110 ) ;
V_206 = & V_186 -> V_195 [ V_193 ] ;
for ( V_87 = F_150 ( * V_206 ,
F_151 ( & V_17 -> V_107 ) ) ;
V_87 != NULL ;
V_87 = F_150 ( * V_206 ,
F_151 ( & V_17 -> V_107 ) ) ) {
if ( V_87 == V_125 ) {
F_154 ( * V_206 ,
F_150 ( V_125 -> V_196 ,
F_151 ( & V_17 -> V_107 ) ) ) ;
F_155 ( & V_125 -> V_98 ) ;
F_156 ( & V_125 -> V_207 , V_208 ) ;
return;
} else {
V_206 = & V_87 -> V_196 ;
}
}
}
static int F_167 ( struct V_16 * V_17 )
{
struct V_191 * V_192 = & V_17 -> V_192 ;
struct V_185 * V_186 ;
struct V_124 T_6 * * V_195 ;
T_5 V_205 ;
F_16 ( V_213 , & V_17 -> V_19 ) ;
V_192 -> V_186 = NULL ;
V_186 = F_111 ( sizeof( * V_186 ) , V_106 ) ;
if ( ! V_186 )
return - V_217 ;
F_7 ( V_202 , & V_17 -> V_19 ) ;
V_205 = F_168 ( V_203 . V_218 ) ;
V_195 = F_111 ( V_205 * sizeof( * V_195 ) , V_106 ) ;
if ( ! V_195 ) {
F_71 ( V_186 ) ;
return - V_217 ;
}
V_186 -> V_205 = V_205 ;
V_186 -> V_190 = ( V_205 - 1 ) ;
V_186 -> V_195 = V_195 ;
F_169 ( V_192 -> V_186 , V_186 ) ;
V_186 -> V_192 = V_192 ;
F_162 ( & V_192 -> V_212 , 0 ) ;
F_16 ( V_202 , & V_17 -> V_19 ) ;
F_160 ( V_17 -> V_181 , & V_17 -> V_211 ,
V_203 . V_204 ) ;
return 0 ;
}
static void F_170 ( struct V_215 * V_219 )
{
struct V_185 * V_186 = F_159 ( V_219 ,
struct V_185 ,
V_207 ) ;
struct V_124 T_6 * * V_195 = V_186 -> V_195 ;
struct V_191 * V_192 = V_186 -> V_192 ;
F_71 ( V_195 ) ;
F_71 ( V_186 ) ;
F_108 ( & V_192 -> V_220 ) ;
}
void F_69 ( struct V_7 * V_8 , T_4 * V_64 )
{
struct V_16 * V_17 = F_4 ( V_8 ) ;
struct V_191 * V_192 = & V_17 -> V_192 ;
struct V_185 * V_186 ;
unsigned long V_19 ;
int V_201 ;
F_88 ( & V_17 -> V_107 , V_19 ) ;
V_186 = F_150 ( V_192 -> V_186 ,
F_151 ( & V_17 -> V_107 ) ) ;
if ( ! V_186 )
goto V_194;
for ( V_201 = 0 ; V_201 < V_186 -> V_205 ; V_201 ++ ) {
struct V_124 * V_125 ;
struct V_124 T_6 * * V_206 = & V_186 -> V_195 [ V_201 ] ;
while ( ( V_125 = F_150 ( * V_206 ,
F_151 ( & V_17 -> V_107 ) ) ) != NULL ) {
if ( ! memcmp ( V_64 , V_125 -> V_110 + 4 , sizeof ( union V_63 ) ) ) {
F_154 ( * V_206 ,
F_150 ( V_125 -> V_196 ,
F_151 ( & V_17 -> V_107 ) ) ) ;
F_155 ( & V_125 -> V_98 ) ;
F_156 ( & V_125 -> V_207 , V_208 ) ;
} else {
V_206 = & V_125 -> V_196 ;
}
}
}
V_194:
F_92 ( & V_17 -> V_107 , V_19 ) ;
}
static void F_171 ( struct V_16 * V_17 )
{
struct V_191 * V_192 = & V_17 -> V_192 ;
struct V_185 * V_186 ;
unsigned long V_19 ;
int V_201 , V_221 = 0 ;
F_116 ( & V_17 -> V_192 . V_214 ) ;
F_88 ( & V_17 -> V_107 , V_19 ) ;
V_186 = F_150 ( V_192 -> V_186 ,
F_151 ( & V_17 -> V_107 ) ) ;
if ( ! V_186 )
goto V_194;
V_221 = F_172 ( & V_17 -> V_192 . V_212 ) ;
if ( ! V_221 )
goto V_222;
for ( V_201 = 0 ; V_201 < V_186 -> V_205 ; V_201 ++ ) {
struct V_124 * V_125 ;
struct V_124 T_6 * * V_206 = & V_186 -> V_195 [ V_201 ] ;
while ( ( V_125 = F_150 ( * V_206 ,
F_151 ( & V_17 -> V_107 ) ) ) != NULL ) {
F_154 ( * V_206 ,
F_150 ( V_125 -> V_196 ,
F_151 ( & V_17 -> V_107 ) ) ) ;
F_155 ( & V_125 -> V_98 ) ;
F_156 ( & V_125 -> V_207 , V_208 ) ;
}
}
V_222:
F_154 ( V_192 -> V_186 , NULL ) ;
F_156 ( & V_186 -> V_207 , F_170 ) ;
V_194:
F_92 ( & V_17 -> V_107 , V_19 ) ;
if ( V_221 )
F_94 ( & V_17 -> V_192 . V_214 ) ;
}
static void F_173 ( struct V_7 * V_8 )
{
struct V_16 * V_17 = F_4 ( V_8 ) ;
int V_223 ;
F_5 ( V_17 , L_25 ) ;
F_116 ( & V_17 -> V_192 . V_220 ) ;
F_7 ( V_213 , & V_17 -> V_19 ) ;
V_223 = F_174 ( V_202 , & V_17 -> V_19 ) ;
if ( ! V_223 )
F_175 ( & V_17 -> V_211 ) ;
F_171 ( V_17 ) ;
F_94 ( & V_17 -> V_192 . V_220 ) ;
}
static void F_176 ( struct V_7 * V_8 )
{
struct V_16 * V_17 = F_4 ( V_8 ) ;
F_177 ( V_8 ) ;
F_178 ( & V_17 -> V_224 ) ;
F_179 ( V_8 ) ;
F_71 ( V_17 -> V_225 ) ;
F_180 ( V_17 -> V_226 ) ;
V_17 -> V_225 = NULL ;
V_17 -> V_226 = NULL ;
}
static int F_181 ( struct V_7 * V_8 )
{
struct V_16 * V_17 = F_4 ( V_8 ) ;
F_182 ( V_8 , & V_17 -> V_224 , V_227 , V_228 ) ;
V_17 -> V_225 = F_111 ( V_229 * sizeof * V_17 -> V_225 ,
V_106 ) ;
if ( ! V_17 -> V_225 )
goto V_62;
V_17 -> V_226 = F_183 ( V_230 * sizeof * V_17 -> V_226 ) ;
if ( ! V_17 -> V_226 ) {
F_184 ( V_231 L_26 ,
V_17 -> V_131 -> V_232 , V_230 ) ;
goto V_233;
}
if ( F_185 ( V_8 , V_17 -> V_131 ) ) {
F_186 ( L_27 ,
V_17 -> V_131 -> V_232 ) ;
goto V_234;
}
V_17 -> V_8 -> V_79 [ 1 ] = ( V_17 -> V_235 -> V_236 >> 16 ) & 0xff ;
V_17 -> V_8 -> V_79 [ 2 ] = ( V_17 -> V_235 -> V_236 >> 8 ) & 0xff ;
V_17 -> V_8 -> V_79 [ 3 ] = ( V_17 -> V_235 -> V_236 ) & 0xff ;
F_187 ( & V_17 -> V_237 , V_238 ,
( unsigned long ) V_8 ) ;
return 0 ;
V_234:
F_180 ( V_17 -> V_226 ) ;
V_233:
F_71 ( V_17 -> V_225 ) ;
V_62:
F_178 ( & V_17 -> V_224 ) ;
return - V_217 ;
}
int F_188 ( struct V_7 * V_8 , struct V_75 * V_131 , int V_74 )
{
struct V_16 * V_17 = F_4 ( V_8 ) ;
int V_60 = - V_217 ;
V_17 -> V_131 = V_131 ;
V_17 -> V_74 = V_74 ;
V_17 -> V_235 = NULL ;
V_17 -> V_181 = F_189 ( L_28 , V_239 ) ;
if ( ! V_17 -> V_181 ) {
F_186 ( L_29 , V_8 -> V_232 ) ;
goto V_62;
}
V_17 -> V_132 = F_190 ( V_17 -> V_131 , 0 ) ;
if ( F_191 ( V_17 -> V_132 ) ) {
F_186 ( L_30 , V_131 -> V_232 ) ;
goto V_240;
}
V_60 = V_17 -> V_241 -> V_242 ( V_8 ) ;
if ( V_60 ) {
F_186 ( L_31 , V_8 -> V_232 ) ;
goto V_243;
}
if ( F_167 ( V_17 ) < 0 ) {
F_186 ( L_32 , V_8 -> V_232 ) ;
goto V_244;
}
if ( V_8 -> V_19 & V_26 ) {
if ( F_8 ( V_8 ) ) {
F_186 ( L_33 , V_8 -> V_232 ) ;
V_60 = - V_245 ;
goto V_244;
}
}
return 0 ;
V_244:
F_192 ( V_8 ) ;
V_243:
if ( V_17 -> V_132 ) {
F_193 ( V_17 -> V_132 ) ;
V_17 -> V_132 = NULL ;
}
V_240:
if ( V_17 -> V_181 ) {
F_194 ( V_17 -> V_181 ) ;
V_17 -> V_181 = NULL ;
}
V_62:
return V_60 ;
}
void F_22 ( struct V_7 * V_8 )
{
struct V_16 * V_17 = F_4 ( V_8 ) , * V_24 , * V_246 ;
F_86 ( V_219 ) ;
F_195 () ;
F_81 (cpriv, tcpriv, &priv->child_intfs, list) {
F_7 ( V_202 , & V_24 -> V_19 ) ;
F_175 ( & V_24 -> V_211 ) ;
F_196 ( V_24 -> V_8 , & V_219 ) ;
}
F_197 ( & V_219 ) ;
F_173 ( V_8 ) ;
F_192 ( V_8 ) ;
if ( V_17 -> V_181 ) {
F_198 ( V_17 -> V_181 ) ;
F_194 ( V_17 -> V_181 ) ;
V_17 -> V_181 = NULL ;
}
}
static int F_199 ( struct V_7 * V_8 , int V_247 , int V_248 )
{
struct V_16 * V_17 = F_4 ( V_8 ) ;
return F_200 ( V_17 -> V_131 , V_247 , V_17 -> V_74 , V_248 ) ;
}
static int F_201 ( struct V_7 * V_8 , int V_247 ,
struct V_249 * V_250 )
{
struct V_16 * V_17 = F_4 ( V_8 ) ;
int V_251 ;
V_251 = F_202 ( V_17 -> V_131 , V_247 , V_17 -> V_74 , V_250 ) ;
if ( V_251 )
return V_251 ;
V_250 -> V_247 = V_247 ;
return 0 ;
}
static int F_203 ( struct V_7 * V_8 , int V_247 , T_7 V_252 , int type )
{
struct V_16 * V_17 = F_4 ( V_8 ) ;
if ( type != V_253 && type != V_254 )
return - V_27 ;
return F_204 ( V_17 -> V_131 , V_247 , V_17 -> V_74 , V_252 , type ) ;
}
static int F_205 ( struct V_7 * V_8 , int V_247 ,
struct V_255 * V_256 )
{
struct V_16 * V_17 = F_4 ( V_8 ) ;
return F_206 ( V_17 -> V_131 , V_247 , V_17 -> V_74 , V_256 ) ;
}
void F_207 ( struct V_7 * V_8 )
{
V_8 -> V_257 = & V_258 ;
F_208 ( V_8 ) ;
V_8 -> V_259 = V_260 ;
V_8 -> V_19 |= V_261 | V_262 ;
V_8 -> V_263 = V_179 ;
V_8 -> V_264 = V_114 ;
V_8 -> type = V_265 ;
V_8 -> V_266 = V_230 * 2 ;
V_8 -> V_28 = ( V_267 |
V_268 ) ;
F_209 ( V_8 ) ;
memcpy ( V_8 -> V_136 , V_269 , V_114 ) ;
}
static void F_210 ( struct V_7 * V_8 )
{
struct V_16 * V_17 = F_4 ( V_8 ) ;
V_17 -> V_8 = V_8 ;
F_211 ( & V_17 -> V_107 ) ;
F_212 ( & V_17 -> V_25 ) ;
F_112 ( & V_17 -> V_99 ) ;
F_112 ( & V_17 -> V_270 ) ;
F_112 ( & V_17 -> V_271 ) ;
F_112 ( & V_17 -> V_272 ) ;
F_213 ( & V_17 -> V_273 , V_274 ) ;
F_214 ( & V_17 -> V_275 , V_276 ) ;
F_214 ( & V_17 -> V_277 , V_278 ) ;
F_214 ( & V_17 -> V_279 , V_280 ) ;
F_214 ( & V_17 -> V_281 , V_282 ) ;
F_214 ( & V_17 -> V_182 , V_283 ) ;
F_213 ( & V_17 -> V_284 , V_285 ) ;
F_213 ( & V_17 -> V_211 , F_158 ) ;
}
static struct V_7
* F_215 ( struct V_75 * V_286 ,
const char * V_232 ,
unsigned char V_287 ,
void (* F_216)( struct V_7 * ) )
{
struct V_7 * V_8 ;
struct V_152 * V_153 ;
V_8 = F_217 ( ( int ) sizeof( struct V_152 ) ,
V_232 ,
V_287 , F_216 ) ;
if ( ! V_8 )
return NULL ;
V_153 = F_119 ( V_8 ) ;
V_153 -> V_160 = V_288 ;
V_153 -> V_289 = V_290 ;
V_153 -> V_291 = V_292 ;
V_153 -> V_286 = V_286 ;
V_8 -> V_9 = & V_293 ;
return V_8 ;
}
static struct V_7 * F_218 ( struct V_75 * V_286 , T_4 V_74 ,
const char * V_232 )
{
struct V_7 * V_8 ;
if ( V_286 -> V_294 ) {
V_8 = V_286 -> V_294 ( V_286 , V_74 ,
V_295 , V_232 ,
V_296 ,
F_207 ) ;
if ( F_99 ( V_8 ) && F_219 ( V_8 ) != - V_297 )
return NULL ;
}
if ( ! V_286 -> V_294 || F_219 ( V_8 ) == - V_297 )
V_8 = F_215 ( V_286 , V_232 , V_296 ,
F_207 ) ;
return V_8 ;
}
struct V_16 * F_220 ( struct V_75 * V_286 , T_4 V_74 ,
const char * V_232 )
{
struct V_7 * V_8 ;
struct V_16 * V_17 ;
struct V_152 * V_153 ;
V_17 = F_111 ( sizeof( * V_17 ) , V_106 ) ;
if ( ! V_17 )
return NULL ;
V_8 = F_218 ( V_286 , V_74 , V_232 ) ;
if ( ! V_8 )
goto V_298;
V_17 -> V_241 = V_8 -> V_9 ;
if ( V_17 -> V_299 & V_300 )
V_8 -> V_9 = & V_301 ;
else
V_8 -> V_9 = & V_302 ;
V_153 = F_119 ( V_8 ) ;
V_153 -> V_303 = V_17 ;
F_210 ( V_8 ) ;
return V_17 ;
V_298:
F_71 ( V_17 ) ;
return NULL ;
}
static T_8 F_221 ( struct V_304 * V_8 ,
struct V_305 * V_306 , char * V_78 )
{
struct V_7 * V_307 = F_222 ( V_8 ) ;
struct V_16 * V_17 = F_4 ( V_307 ) ;
return sprintf ( V_78 , L_34 , V_17 -> V_76 ) ;
}
static T_8 F_223 ( struct V_304 * V_8 ,
struct V_305 * V_306 , char * V_78 )
{
struct V_7 * V_307 = F_222 ( V_8 ) ;
struct V_16 * V_17 = F_4 ( V_307 ) ;
return sprintf ( V_78 , L_35 , F_9 ( V_308 , & V_17 -> V_19 ) ) ;
}
void F_224 ( struct V_7 * V_307 , int V_309 )
{
struct V_16 * V_17 = F_4 ( V_307 ) ;
if ( V_309 > 0 ) {
F_7 ( V_308 , & V_17 -> V_19 ) ;
F_27 ( V_17 , L_36
L_37 ) ;
} else
F_16 ( V_308 , & V_17 -> V_19 ) ;
}
static T_8 F_225 ( struct V_304 * V_8 ,
struct V_305 * V_306 ,
const char * V_78 , T_9 V_310 )
{
unsigned long V_309 = F_226 ( V_78 , NULL , 0 ) ;
F_224 ( F_222 ( V_8 ) , V_309 ) ;
return V_310 ;
}
int F_227 ( struct V_7 * V_8 )
{
return F_228 ( & V_8 -> V_8 , & V_311 ) ;
}
static void F_229 ( struct V_16 * V_17 , union V_63 * V_64 )
{
struct V_16 * V_68 ;
struct V_7 * V_312 = V_17 -> V_8 ;
F_230 ( V_312 ) ;
memcpy ( & V_17 -> V_71 . V_313 . V_314 ,
& V_64 -> V_313 . V_314 ,
sizeof( V_64 -> V_313 . V_314 ) ) ;
memcpy ( V_312 -> V_79 + 4 , & V_17 -> V_71 , sizeof( V_17 -> V_71 ) ) ;
F_16 ( V_315 , & V_17 -> V_19 ) ;
F_231 ( V_312 ) ;
if ( ! F_9 ( V_23 , & V_17 -> V_19 ) ) {
F_11 ( & V_17 -> V_25 ) ;
F_12 (child_priv, &priv->child_intfs, list)
F_229 ( V_68 , V_64 ) ;
F_14 ( & V_17 -> V_25 ) ;
}
}
static int F_232 ( struct V_7 * V_8 ,
struct V_316 * V_317 )
{
union V_63 * V_64 = (union V_63 * ) ( V_317 -> V_318 + 4 ) ;
int V_60 = 0 ;
F_230 ( V_8 ) ;
if ( memcmp ( V_8 -> V_79 , V_317 -> V_318 ,
4 + sizeof( V_64 -> V_313 . V_319 ) ) ||
V_64 -> V_313 . V_314 == 0 )
V_60 = - V_27 ;
F_231 ( V_8 ) ;
return V_60 ;
}
static int F_233 ( struct V_7 * V_8 , void * V_38 )
{
struct V_16 * V_17 = F_4 ( V_8 ) ;
struct V_316 * V_317 = V_38 ;
int V_60 ;
if ( ! ( V_8 -> V_320 & V_321 ) && F_234 ( V_8 ) )
return - V_84 ;
V_60 = F_232 ( V_8 , V_317 ) ;
if ( V_60 )
return V_60 ;
F_229 ( V_17 , (union V_63 * ) ( V_317 -> V_318 + 4 ) ) ;
F_141 ( V_322 , & V_17 -> V_277 ) ;
return 0 ;
}
static T_8 F_235 ( struct V_304 * V_8 ,
struct V_305 * V_306 ,
const char * V_78 , T_9 V_310 )
{
int V_76 ;
int V_60 ;
if ( sscanf ( V_78 , L_38 , & V_76 ) != 1 )
return - V_27 ;
if ( V_76 <= 0 || V_76 > 0xffff || V_76 == 0x8000 )
return - V_27 ;
V_76 |= 0x8000 ;
V_60 = F_236 ( F_222 ( V_8 ) , V_76 ) ;
return V_60 ? V_60 : V_310 ;
}
static T_8 F_237 ( struct V_304 * V_8 ,
struct V_305 * V_306 ,
const char * V_78 , T_9 V_310 )
{
int V_76 ;
int V_60 ;
if ( sscanf ( V_78 , L_38 , & V_76 ) != 1 )
return - V_27 ;
if ( V_76 < 0 || V_76 > 0xffff )
return - V_27 ;
V_60 = F_238 ( F_222 ( V_8 ) , V_76 ) ;
return V_60 ? V_60 : V_310 ;
}
int F_239 ( struct V_7 * V_8 )
{
return F_228 ( & V_8 -> V_8 , & V_323 ) ;
}
void F_240 ( struct V_16 * V_17 , struct V_75 * V_286 )
{
V_17 -> V_299 = V_286 -> V_324 . V_325 ;
if ( V_17 -> V_299 & V_326 ) {
V_17 -> V_8 -> V_327 |= V_30 | V_328 ;
if ( V_17 -> V_299 & V_329 )
V_17 -> V_8 -> V_327 |= V_31 ;
V_17 -> V_8 -> V_28 |= V_17 -> V_8 -> V_327 ;
}
}
static struct V_7 * F_241 ( const char * V_330 ,
struct V_75 * V_286 , T_4 V_74 )
{
struct V_16 * V_17 ;
struct V_331 V_306 ;
int V_61 = - V_217 ;
V_17 = F_220 ( V_286 , V_74 , V_330 ) ;
if ( ! V_17 )
goto V_332;
F_242 ( V_17 -> V_8 , V_286 -> V_8 . V_184 ) ;
V_17 -> V_8 -> V_333 = V_74 - 1 ;
V_61 = F_243 ( V_286 , V_74 , & V_306 ) ;
if ( ! V_61 )
V_17 -> V_35 = F_244 ( V_306 . V_334 ) ;
else {
F_184 ( V_231 L_39 ,
V_286 -> V_232 , V_74 ) ;
goto V_335;
}
V_17 -> V_8 -> V_34 = F_28 ( V_17 -> V_35 ) ;
V_17 -> V_33 = V_17 -> V_36 = V_17 -> V_8 -> V_34 ;
V_17 -> V_8 -> V_334 = V_336 ;
V_17 -> V_8 -> V_337 = sizeof( struct V_124 ) ;
V_61 = F_245 ( V_286 , V_74 , 0 , & V_17 -> V_76 ) ;
if ( V_61 ) {
F_184 ( V_231 L_40 ,
V_286 -> V_232 , V_74 , V_61 ) ;
goto V_335;
}
F_240 ( V_17 , V_286 ) ;
V_17 -> V_76 |= 0x8000 ;
V_17 -> V_8 -> V_136 [ 8 ] = V_17 -> V_76 >> 8 ;
V_17 -> V_8 -> V_136 [ 9 ] = V_17 -> V_76 & 0xff ;
V_61 = F_246 ( V_286 , V_74 , 0 , & V_17 -> V_71 , NULL ) ;
if ( V_61 ) {
F_184 ( V_231 L_41 ,
V_286 -> V_232 , V_74 , V_61 ) ;
goto V_335;
} else
memcpy ( V_17 -> V_8 -> V_79 + 4 , V_17 -> V_71 . V_92 , sizeof ( union V_63 ) ) ;
F_7 ( V_315 , & V_17 -> V_19 ) ;
V_61 = F_188 ( V_17 -> V_8 , V_286 , V_74 ) ;
if ( V_61 < 0 ) {
F_184 ( V_231 L_42 ,
V_286 -> V_232 , V_74 , V_61 ) ;
goto V_335;
}
F_247 ( & V_17 -> V_338 ,
V_17 -> V_131 , V_339 ) ;
V_61 = F_248 ( & V_17 -> V_338 ) ;
if ( V_61 < 0 ) {
F_184 ( V_231 L_43
L_44 ,
V_286 -> V_232 , V_74 , V_61 ) ;
goto V_340;
}
V_61 = F_249 ( V_17 -> V_8 ) ;
if ( V_61 ) {
F_184 ( V_231 L_45 ,
V_286 -> V_232 , V_74 , V_61 ) ;
goto V_341;
}
if ( F_250 ( V_17 -> V_8 ) )
goto V_342;
if ( F_239 ( V_17 -> V_8 ) )
goto V_342;
if ( F_227 ( V_17 -> V_8 ) )
goto V_342;
if ( F_228 ( & V_17 -> V_8 -> V_8 , & V_343 ) )
goto V_342;
if ( F_228 ( & V_17 -> V_8 -> V_8 , & V_344 ) )
goto V_342;
return V_17 -> V_8 ;
V_342:
F_251 ( V_17 -> V_8 ) ;
V_341:
F_252 ( & V_17 -> V_338 ) ;
F_198 ( V_322 ) ;
F_7 ( V_202 , & V_17 -> V_19 ) ;
F_175 ( & V_17 -> V_211 ) ;
F_198 ( V_17 -> V_181 ) ;
V_340:
F_22 ( V_17 -> V_8 ) ;
V_335:
F_253 ( V_17 -> V_8 ) ;
F_71 ( V_17 ) ;
V_332:
return F_254 ( V_61 ) ;
}
static void F_255 ( struct V_75 * V_304 )
{
struct V_72 * V_73 ;
struct V_7 * V_8 ;
struct V_16 * V_17 ;
int V_345 ;
int V_310 = 0 ;
V_73 = F_73 ( sizeof *V_73 , V_106 ) ;
if ( ! V_73 )
return;
F_112 ( V_73 ) ;
for ( V_345 = F_256 ( V_304 ) ; V_345 <= F_257 ( V_304 ) ; ++ V_345 ) {
if ( ! F_50 ( V_304 , V_345 ) )
continue;
V_8 = F_241 ( L_46 , V_304 , V_345 ) ;
if ( ! F_191 ( V_8 ) ) {
V_17 = F_4 ( V_8 ) ;
F_65 ( & V_17 -> V_98 , V_73 ) ;
V_310 ++ ;
}
}
if ( ! V_310 ) {
F_71 ( V_73 ) ;
return;
}
F_258 ( V_304 , & V_346 , V_73 ) ;
}
static void F_259 ( struct V_75 * V_304 , void * V_77 )
{
struct V_16 * V_17 , * V_347 , * V_24 , * V_246 ;
struct V_72 * V_73 = V_77 ;
if ( ! V_73 )
return;
F_81 (priv, tmp, dev_list, list) {
F_252 ( & V_17 -> V_338 ) ;
F_198 ( V_322 ) ;
F_7 ( V_348 , & V_17 -> V_19 ) ;
F_260 () ;
F_13 ( V_17 -> V_8 , V_17 -> V_8 -> V_19 & ~ V_26 ) ;
F_57 () ;
F_7 ( V_202 , & V_17 -> V_19 ) ;
F_175 ( & V_17 -> V_211 ) ;
F_198 ( V_17 -> V_181 ) ;
F_251 ( V_17 -> V_8 ) ;
if ( V_304 -> V_349 )
V_304 -> V_349 ( V_17 -> V_8 ) ;
else
F_253 ( V_17 -> V_8 ) ;
F_81 (cpriv, tcpriv, &priv->child_intfs, list)
F_71 ( V_24 ) ;
F_71 ( V_17 ) ;
}
F_71 ( V_73 ) ;
}
static int T_10 F_261 ( void )
{
int V_60 ;
V_229 = F_168 ( V_229 ) ;
V_229 = F_29 ( V_229 , V_350 ) ;
V_229 = F_262 ( V_229 , V_351 ) ;
V_230 = F_168 ( V_230 ) ;
V_230 = F_29 ( V_230 , V_350 ) ;
V_230 = F_263 ( V_230 , 2 * V_352 , V_351 ) ;
#ifdef F_264
V_353 = F_29 ( V_353 , V_354 ) ;
#endif
F_265 ( V_355 > V_356 ) ;
V_60 = F_266 () ;
if ( V_60 )
return V_60 ;
V_322 = F_189 ( L_47 ,
V_239 ) ;
if ( ! V_322 ) {
V_60 = - V_217 ;
goto V_357;
}
F_267 ( & V_146 ) ;
V_60 = F_268 ( & V_346 ) ;
if ( V_60 )
goto V_358;
V_60 = F_269 () ;
if ( V_60 )
goto V_359;
#ifdef F_270
F_271 ( & V_360 ) ;
#endif
return 0 ;
V_359:
F_272 ( & V_346 ) ;
V_358:
F_273 ( & V_146 ) ;
F_194 ( V_322 ) ;
V_357:
F_274 () ;
return V_60 ;
}
static void T_11 F_275 ( void )
{
#ifdef F_270
F_276 ( & V_360 ) ;
#endif
F_277 () ;
F_272 ( & V_346 ) ;
F_273 ( & V_146 ) ;
F_274 () ;
F_194 ( V_322 ) ;
}
