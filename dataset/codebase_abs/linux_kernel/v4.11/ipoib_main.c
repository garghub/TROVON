int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
F_3 ( V_4 , L_1 ) ;
F_4 ( V_2 ) ;
F_5 ( V_5 , & V_4 -> V_6 ) ;
V_4 -> V_7 = false ;
if ( F_6 ( V_2 ) ) {
if ( ! F_7 ( V_8 , & V_4 -> V_6 ) )
return 0 ;
goto V_9;
}
F_8 ( V_2 ) ;
if ( ! F_7 ( V_10 , & V_4 -> V_6 ) ) {
struct V_3 * V_11 ;
F_9 ( & V_4 -> V_12 ) ;
F_10 (cpriv, &priv->child_intfs, list) {
int V_6 ;
V_6 = V_11 -> V_2 -> V_6 ;
if ( V_6 & V_13 )
continue;
F_11 ( V_11 -> V_2 , V_6 | V_13 ) ;
}
F_12 ( & V_4 -> V_12 ) ;
}
F_13 ( V_2 ) ;
return 0 ;
V_9:
F_14 ( V_5 , & V_4 -> V_6 ) ;
return - V_14 ;
}
static int F_15 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
F_3 ( V_4 , L_2 ) ;
F_14 ( V_5 , & V_4 -> V_6 ) ;
F_16 ( V_2 ) ;
F_17 ( V_2 ) ;
F_18 ( V_2 ) ;
if ( ! F_7 ( V_10 , & V_4 -> V_6 ) ) {
struct V_3 * V_11 ;
F_9 ( & V_4 -> V_12 ) ;
F_10 (cpriv, &priv->child_intfs, list) {
int V_6 ;
V_6 = V_11 -> V_2 -> V_6 ;
if ( ! ( V_6 & V_13 ) )
continue;
F_11 ( V_11 -> V_2 , V_6 & ~ V_13 ) ;
}
F_12 ( & V_4 -> V_12 ) ;
}
return 0 ;
}
static void F_19 ( struct V_1 * V_2 )
{
F_20 ( V_2 ) ;
}
static T_1 F_21 ( struct V_1 * V_2 , T_1 V_15 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
if ( F_7 ( V_16 , & V_4 -> V_6 ) )
V_15 &= ~ ( V_17 | V_18 ) ;
return V_15 ;
}
static int F_22 ( struct V_1 * V_2 , int V_19 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
if ( F_23 ( V_2 ) ) {
if ( V_19 > F_24 ( V_2 ) )
return - V_14 ;
if ( V_19 > V_4 -> V_20 )
F_25 ( V_4 , L_3 ,
V_4 -> V_20 ) ;
V_2 -> V_21 = V_19 ;
return 0 ;
}
if ( V_19 > F_26 ( V_4 -> V_22 ) )
return - V_14 ;
V_4 -> V_23 = V_19 ;
if ( V_4 -> V_20 < V_4 -> V_23 )
F_3 ( V_4 , L_4
L_5 , V_4 -> V_20 ) ;
V_2 -> V_21 = F_27 ( V_4 -> V_20 , V_4 -> V_23 ) ;
return 0 ;
}
static bool F_28 ( const struct V_24 * V_25 ,
struct V_1 * V_2 )
{
struct V_26 * V_26 = F_29 ( V_2 ) ;
struct V_27 * V_28 ;
struct V_29 * V_30 = (struct V_29 * ) V_25 ;
struct V_31 * V_32 = (struct V_31 * ) V_25 ;
T_2 V_33 ;
switch ( V_25 -> V_34 ) {
case V_35 :
V_28 = F_30 ( V_2 ) ;
if ( ! V_28 )
return false ;
V_33 = F_31 ( V_26 , V_28 , 0 ,
V_30 -> V_36 . V_37 ,
V_38 ) ;
F_32 ( V_28 ) ;
if ( V_33 )
return true ;
break;
case V_39 :
if ( F_33 ( V_40 ) &&
F_34 ( V_26 , & V_32 -> V_41 , V_2 , 1 ) )
return true ;
break;
}
return false ;
}
static struct V_1 * F_35 ( struct V_1 * V_2 )
{
struct V_1 * V_42 ;
F_36 () ;
V_42 = F_37 ( V_2 ) ;
if ( V_42 )
F_38 ( V_42 ) ;
F_39 () ;
if ( V_42 )
return V_42 ;
F_38 ( V_2 ) ;
return V_2 ;
}
static int F_40 ( struct V_1 * V_43 , void * V_44 )
{
struct V_45 * V_46 = V_44 ;
int V_47 = 0 ;
if ( F_28 ( V_46 -> V_25 , V_43 ) ) {
F_38 ( V_43 ) ;
V_46 -> V_48 = V_43 ;
V_47 = 1 ;
}
return V_47 ;
}
static struct V_1 * F_41 (
const struct V_24 * V_25 , struct V_1 * V_2 )
{
struct V_45 V_46 = {
. V_25 = V_25 ,
} ;
F_36 () ;
if ( F_28 ( V_25 , V_2 ) ) {
F_38 ( V_2 ) ;
V_46 . V_48 = V_2 ;
goto V_49;
}
F_42 ( V_2 , F_40 , & V_46 ) ;
V_49:
F_39 () ;
return V_46 . V_48 ;
}
static int F_43 ( struct V_3 * V_4 ,
const union V_50 * V_51 ,
T_3 V_52 ,
const struct V_24 * V_25 ,
int V_53 ,
struct V_1 * * V_54 )
{
struct V_3 * V_55 ;
struct V_1 * V_56 = NULL ;
int V_57 = 0 ;
if ( V_4 -> V_52 == V_52 &&
( ! V_51 || ! memcmp ( V_51 , & V_4 -> V_58 , sizeof( * V_51 ) ) ) ) {
if ( ! V_25 ) {
V_56 = F_35 ( V_4 -> V_2 ) ;
} else {
V_56 = F_41 ( V_25 , V_4 -> V_2 ) ;
}
if ( V_56 ) {
if ( ! * V_54 )
* V_54 = V_56 ;
else
F_44 ( V_56 ) ;
++ V_57 ;
}
}
F_45 ( & V_4 -> V_12 , V_53 ) ;
F_10 (child_priv, &priv->child_intfs, list) {
V_57 += F_43 ( V_55 , V_51 ,
V_52 , V_25 ,
V_53 + 1 ,
V_54 ) ;
if ( V_57 > 1 )
break;
}
F_12 ( & V_4 -> V_12 ) ;
return V_57 ;
}
static int F_46 ( struct V_59 * V_60 , T_4 V_61 ,
T_3 V_52 ,
const union V_50 * V_51 ,
const struct V_24 * V_25 ,
struct V_1 * * V_56 )
{
struct V_3 * V_4 ;
int V_57 = 0 ;
* V_56 = NULL ;
F_10 (priv, dev_list, list) {
if ( V_4 -> V_61 != V_61 )
continue;
V_57 += F_43 ( V_4 , V_51 , V_52 ,
V_25 , 0 , V_56 ) ;
if ( V_57 > 1 )
break;
}
return V_57 ;
}
static struct V_1 * F_47 (
struct V_62 * V_2 , T_4 V_61 , T_3 V_63 ,
const union V_50 * V_51 , const struct V_24 * V_25 ,
void * V_64 )
{
struct V_1 * V_56 ;
struct V_59 * V_60 = V_64 ;
T_3 V_52 ;
int V_57 ;
int V_47 ;
if ( ! F_48 ( V_2 , V_61 ) )
return NULL ;
V_47 = F_49 ( V_2 , V_61 , V_63 , & V_52 ) ;
if ( V_47 )
return NULL ;
if ( ! V_60 )
return NULL ;
V_57 = F_46 ( V_60 , V_61 , V_52 ,
V_51 , NULL , & V_56 ) ;
switch ( V_57 ) {
case 0 :
return NULL ;
case 1 :
return V_56 ;
}
F_44 ( V_56 ) ;
V_57 = F_46 ( V_60 , V_61 , V_52 ,
V_51 , V_25 , & V_56 ) ;
switch ( V_57 ) {
case 0 :
return NULL ;
default:
F_50 ( & V_2 -> V_2 ,
L_6 ) ;
case 1 :
return V_56 ;
}
}
int F_51 ( struct V_1 * V_2 , const char * V_65 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
if ( ( F_7 ( V_16 , & V_4 -> V_6 ) &&
! strcmp ( V_65 , L_7 ) ) ||
( ! F_7 ( V_16 , & V_4 -> V_6 ) &&
! strcmp ( V_65 , L_8 ) ) ) {
return 0 ;
}
if ( F_52 ( V_2 -> V_66 ) && ! strcmp ( V_65 , L_7 ) ) {
F_5 ( V_16 , & V_4 -> V_6 ) ;
F_25 ( V_4 , L_9
L_10 ) ;
F_53 ( V_2 ) ;
F_54 ( V_2 , F_24 ( V_2 ) ) ;
F_55 () ;
V_4 -> V_67 . V_68 . V_69 &= ~ V_70 ;
F_56 ( V_2 ) ;
return ( ! F_57 () ) ? - V_71 : 0 ;
}
if ( ! strcmp ( V_65 , L_8 ) ) {
F_14 ( V_16 , & V_4 -> V_6 ) ;
F_53 ( V_2 ) ;
F_54 ( V_2 , F_27 ( V_4 -> V_20 , V_2 -> V_21 ) ) ;
F_55 () ;
F_56 ( V_2 ) ;
return ( ! F_57 () ) ? - V_71 : 0 ;
}
return - V_14 ;
}
struct V_72 * F_58 ( struct V_1 * V_2 , void * V_51 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_73 * V_74 = V_4 -> V_75 . V_73 ;
struct V_72 * V_76 ;
int V_47 ;
while ( V_74 ) {
V_76 = F_59 ( V_74 , struct V_72 , V_73 ) ;
V_47 = memcmp ( V_51 , V_76 -> V_77 . V_78 . V_79 ,
sizeof ( union V_50 ) ) ;
if ( V_47 < 0 )
V_74 = V_74 -> V_80 ;
else if ( V_47 > 0 )
V_74 = V_74 -> V_81 ;
else
return V_76 ;
}
return NULL ;
}
static int F_60 ( struct V_1 * V_2 , struct V_72 * V_76 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_73 * * V_74 = & V_4 -> V_75 . V_73 ;
struct V_73 * V_82 = NULL ;
struct V_72 * V_83 ;
int V_47 ;
while ( * V_74 ) {
V_82 = * V_74 ;
V_83 = F_59 ( V_82 , struct V_72 , V_73 ) ;
V_47 = memcmp ( V_76 -> V_77 . V_78 . V_79 , V_83 -> V_77 . V_78 . V_79 ,
sizeof ( union V_50 ) ) ;
if ( V_47 < 0 )
V_74 = & V_82 -> V_80 ;
else if ( V_47 > 0 )
V_74 = & V_82 -> V_81 ;
else
return - V_84 ;
}
F_61 ( & V_76 -> V_73 , V_82 , V_74 ) ;
F_62 ( & V_76 -> V_73 , & V_4 -> V_75 ) ;
F_63 ( & V_76 -> V_85 , & V_4 -> V_86 ) ;
return 0 ;
}
static void F_64 ( struct V_1 * V_2 , struct V_72 * V_76 )
{
struct V_87 * V_88 ;
while ( ( V_88 = F_65 ( & V_76 -> V_89 ) ) )
F_66 ( V_88 ) ;
F_3 ( F_2 ( V_2 ) , L_11 ) ;
F_67 ( V_2 , V_76 -> V_77 . V_78 . V_79 ) ;
if ( V_76 -> V_90 )
F_68 ( V_76 -> V_90 ) ;
F_69 ( V_76 ) ;
}
struct V_91 * F_70 ( struct V_1 * V_2 )
{
struct V_91 * V_92 ;
V_92 = F_71 ( sizeof *V_92 , V_93 ) ;
if ( ! V_92 )
return NULL ;
V_92 -> V_2 = V_2 ;
memset ( V_92 -> V_76 . V_77 . V_78 . V_79 , 0 , 16 ) ;
if ( F_72 ( V_92 ) ) {
F_69 ( V_92 ) ;
return NULL ;
}
return V_92 ;
}
int F_72 ( struct V_91 * V_92 )
{
struct V_3 * V_4 = F_2 ( V_92 -> V_2 ) ;
struct V_73 * V_74 ;
struct V_72 * V_76 ;
int V_47 = 1 ;
F_73 ( & V_4 -> V_94 ) ;
V_74 = F_74 ( & V_4 -> V_75 ) ;
while ( V_74 ) {
V_76 = F_59 ( V_74 , struct V_72 , V_73 ) ;
if ( memcmp ( V_92 -> V_76 . V_77 . V_78 . V_79 , V_76 -> V_77 . V_78 . V_79 ,
sizeof ( union V_50 ) ) < 0 ) {
V_92 -> V_76 = * V_76 ;
V_47 = 0 ;
break;
}
V_74 = F_75 ( V_74 ) ;
}
F_76 ( & V_4 -> V_94 ) ;
return V_47 ;
}
void F_77 ( struct V_91 * V_92 ,
struct V_72 * V_76 )
{
* V_76 = V_92 -> V_76 ;
}
void F_78 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_72 * V_76 , * V_95 ;
F_73 ( & V_4 -> V_94 ) ;
F_79 (path, tp, &priv->path_list, list) {
F_3 ( V_4 , L_12 ,
F_80 ( V_76 -> V_77 . V_96 ) ,
V_76 -> V_77 . V_78 . V_79 ) ;
V_76 -> V_97 = 0 ;
}
F_76 ( & V_4 -> V_94 ) ;
}
static void F_81 ( int V_98 , struct V_99 * V_100 ,
void * V_101 )
{
struct V_102 * V_103 = V_101 ;
struct V_3 * V_4 ;
F_82 ( ! V_101 ) ;
V_4 = V_103 -> V_4 ;
if ( V_98 || ! V_100 ) {
F_83 ( L_13 ,
V_4 -> V_2 -> V_104 , V_98 ) ;
V_4 -> V_7 = false ;
goto V_49;
}
if ( F_84 ( V_100 ) &
V_105 ) {
F_83 ( L_14 ,
V_4 -> V_2 -> V_104 ) ;
V_4 -> V_7 = true ;
} else {
F_83 ( L_15 ,
V_4 -> V_2 -> V_104 ) ;
V_4 -> V_7 = false ;
}
V_49:
F_85 ( & V_103 -> V_106 ) ;
}
int F_86 ( struct V_3 * V_4 )
{
struct V_102 * V_107 ;
int V_47 ;
V_107 = F_71 ( sizeof( * V_107 ) , V_93 ) ;
if ( ! V_107 )
return - V_108 ;
V_107 -> V_4 = V_4 ;
F_87 ( & V_107 -> V_106 ) ;
V_47 = F_88 ( & V_109 ,
V_4 -> V_110 , V_4 -> V_61 , 3000 ,
V_93 ,
F_81 ,
V_107 ,
& V_107 -> V_111 ) ;
if ( V_47 < 0 ) {
F_89 ( L_16 ,
V_4 -> V_2 -> V_104 , V_47 ) ;
F_69 ( V_107 ) ;
return V_47 ;
}
F_90 ( & V_107 -> V_106 ) ;
F_69 ( V_107 ) ;
return V_47 ;
}
static void F_91 ( struct V_87 * V_88 , const char * V_112 )
{
struct V_113 * V_114 ;
V_114 = (struct V_113 * ) F_92 ( V_88 , sizeof( * V_114 ) ) ;
memcpy ( V_114 -> V_115 , V_112 , V_116 ) ;
}
void F_56 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_72 * V_76 , * V_95 ;
F_93 ( V_117 ) ;
unsigned long V_6 ;
F_94 ( V_2 ) ;
F_95 ( & V_4 -> V_94 , V_6 ) ;
F_96 ( & V_4 -> V_86 , & V_117 ) ;
F_10 (path, &remove_list, list)
F_97 ( & V_76 -> V_73 , & V_4 -> V_75 ) ;
F_79 (path, tp, &remove_list, list) {
if ( V_76 -> V_118 )
F_98 ( V_76 -> V_119 , V_76 -> V_118 ) ;
F_99 ( & V_4 -> V_94 , V_6 ) ;
F_100 ( V_2 ) ;
F_90 ( & V_76 -> V_106 ) ;
F_64 ( V_2 , V_76 ) ;
F_94 ( V_2 ) ;
F_95 ( & V_4 -> V_94 , V_6 ) ;
}
F_99 ( & V_4 -> V_94 , V_6 ) ;
F_100 ( V_2 ) ;
}
static void F_101 ( int V_98 ,
struct V_120 * V_77 ,
void * V_121 )
{
struct V_72 * V_76 = V_121 ;
struct V_1 * V_2 = V_76 -> V_2 ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_122 * V_90 = NULL ;
struct V_122 * V_123 = NULL ;
struct V_124 * V_125 , * V_126 ;
struct V_127 V_128 ;
struct V_87 * V_88 ;
unsigned long V_6 ;
if ( ! V_98 )
F_3 ( V_4 , L_17 ,
F_80 ( V_77 -> V_96 ) , V_77 -> V_78 . V_79 ) ;
else
F_3 ( V_4 , L_18 ,
V_98 , V_76 -> V_77 . V_78 . V_79 ) ;
F_102 ( & V_128 ) ;
if ( ! V_98 ) {
struct V_129 V_130 ;
if ( ! F_103 ( V_4 -> V_110 , V_4 -> V_61 , V_77 , & V_130 ) )
V_90 = F_104 ( V_2 , V_4 -> V_131 , & V_130 ) ;
}
F_95 ( & V_4 -> V_94 , V_6 ) ;
if ( ! F_105 ( V_90 ) ) {
V_76 -> V_77 = * V_77 ;
V_123 = V_76 -> V_90 ;
V_76 -> V_90 = V_90 ;
F_3 ( V_4 , L_19 ,
V_90 , F_80 ( V_77 -> V_96 ) , V_77 -> V_132 ) ;
while ( ( V_88 = F_65 ( & V_76 -> V_89 ) ) )
F_106 ( & V_128 , V_88 ) ;
F_79 (neigh, tn, &path->neigh_list, list) {
if ( V_125 -> V_90 ) {
F_82 ( V_125 -> V_90 != V_123 ) ;
F_68 ( V_125 -> V_90 ) ;
}
F_107 ( & V_76 -> V_90 -> V_133 ) ;
V_125 -> V_90 = V_76 -> V_90 ;
if ( F_108 ( V_2 , V_125 -> V_112 ) ) {
if ( ! F_109 ( V_125 ) )
F_110 ( V_125 , F_111 ( V_2 ,
V_76 ,
V_125 ) ) ;
if ( ! F_109 ( V_125 ) ) {
F_112 ( V_125 ) ;
continue;
}
}
while ( ( V_88 = F_65 ( & V_125 -> V_89 ) ) )
F_106 ( & V_128 , V_88 ) ;
}
V_76 -> V_97 = 1 ;
}
V_76 -> V_118 = NULL ;
F_85 ( & V_76 -> V_106 ) ;
F_99 ( & V_4 -> V_94 , V_6 ) ;
if ( F_105 ( V_90 ) )
F_67 ( V_2 , V_76 -> V_77 . V_78 . V_79 ) ;
if ( V_123 )
F_68 ( V_123 ) ;
while ( ( V_88 = F_65 ( & V_128 ) ) ) {
int V_47 ;
V_88 -> V_2 = V_2 ;
V_47 = F_113 ( V_88 ) ;
if ( V_47 )
F_25 ( V_4 , L_20 ,
V_134 , V_47 ) ;
}
}
static struct V_72 * F_114 ( struct V_1 * V_2 , void * V_51 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_72 * V_76 ;
if ( ! V_4 -> V_135 )
return NULL ;
V_76 = F_115 ( sizeof *V_76 , V_136 ) ;
if ( ! V_76 )
return NULL ;
V_76 -> V_2 = V_2 ;
F_102 ( & V_76 -> V_89 ) ;
F_116 ( & V_76 -> V_137 ) ;
memcpy ( V_76 -> V_77 . V_78 . V_79 , V_51 , sizeof ( union V_50 ) ) ;
V_76 -> V_77 . V_138 = V_4 -> V_58 ;
V_76 -> V_77 . V_63 = F_117 ( V_4 -> V_63 ) ;
V_76 -> V_77 . V_139 = 1 ;
V_76 -> V_77 . V_140 = V_4 -> V_135 -> V_141 . V_140 ;
return V_76 ;
}
static int F_118 ( struct V_1 * V_2 ,
struct V_72 * V_76 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
F_3 ( V_4 , L_21 ,
V_76 -> V_77 . V_78 . V_79 ) ;
F_87 ( & V_76 -> V_106 ) ;
V_76 -> V_119 =
F_119 ( & V_109 , V_4 -> V_110 , V_4 -> V_61 ,
& V_76 -> V_77 ,
V_142 |
V_143 |
V_144 |
V_145 |
V_146 ,
1000 , V_136 ,
F_101 ,
V_76 , & V_76 -> V_118 ) ;
if ( V_76 -> V_119 < 0 ) {
F_25 ( V_4 , L_22 , V_76 -> V_119 ) ;
V_76 -> V_118 = NULL ;
F_85 ( & V_76 -> V_106 ) ;
return V_76 -> V_119 ;
}
return 0 ;
}
static void F_120 ( struct V_87 * V_88 , T_4 * V_112 ,
struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_72 * V_76 ;
struct V_124 * V_125 ;
unsigned long V_6 ;
F_95 ( & V_4 -> V_94 , V_6 ) ;
V_125 = F_121 ( V_112 , V_2 ) ;
if ( ! V_125 ) {
F_99 ( & V_4 -> V_94 , V_6 ) ;
++ V_2 -> V_147 . V_148 ;
F_122 ( V_88 ) ;
return;
}
V_76 = F_58 ( V_2 , V_112 + 4 ) ;
if ( ! V_76 ) {
V_76 = F_114 ( V_2 , V_112 + 4 ) ;
if ( ! V_76 )
goto V_149;
F_60 ( V_2 , V_76 ) ;
}
F_63 ( & V_125 -> V_85 , & V_76 -> V_137 ) ;
if ( V_76 -> V_90 ) {
F_107 ( & V_76 -> V_90 -> V_133 ) ;
V_125 -> V_90 = V_76 -> V_90 ;
if ( F_108 ( V_2 , V_125 -> V_112 ) ) {
if ( ! F_109 ( V_125 ) )
F_110 ( V_125 , F_111 ( V_2 , V_76 , V_125 ) ) ;
if ( ! F_109 ( V_125 ) ) {
F_112 ( V_125 ) ;
goto V_150;
}
if ( F_123 ( & V_125 -> V_89 ) <
V_151 ) {
F_91 ( V_88 , V_125 -> V_112 ) ;
F_106 ( & V_125 -> V_89 , V_88 ) ;
} else {
F_25 ( V_4 , L_23 ,
F_123 ( & V_125 -> V_89 ) ) ;
goto V_150;
}
} else {
F_99 ( & V_4 -> V_94 , V_6 ) ;
F_124 ( V_2 , V_88 , V_76 -> V_90 , F_125 ( V_112 ) ) ;
F_126 ( V_125 ) ;
return;
}
} else {
V_125 -> V_90 = NULL ;
if ( ! V_76 -> V_118 && F_118 ( V_2 , V_76 ) )
goto V_149;
if ( F_123 ( & V_125 -> V_89 ) < V_151 ) {
F_91 ( V_88 , V_125 -> V_112 ) ;
F_106 ( & V_125 -> V_89 , V_88 ) ;
} else {
goto V_150;
}
}
F_99 ( & V_4 -> V_94 , V_6 ) ;
F_126 ( V_125 ) ;
return;
V_149:
F_112 ( V_125 ) ;
V_150:
++ V_2 -> V_147 . V_148 ;
F_122 ( V_88 ) ;
F_99 ( & V_4 -> V_94 , V_6 ) ;
F_126 ( V_125 ) ;
}
static void F_127 ( struct V_87 * V_88 , struct V_1 * V_2 ,
struct V_113 * V_114 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_72 * V_76 ;
unsigned long V_6 ;
F_95 ( & V_4 -> V_94 , V_6 ) ;
V_76 = F_58 ( V_2 , V_114 -> V_115 + 4 ) ;
if ( ! V_76 || ! V_76 -> V_97 ) {
int V_152 = 0 ;
if ( ! V_76 ) {
V_76 = F_114 ( V_2 , V_114 -> V_115 + 4 ) ;
V_152 = 1 ;
}
if ( V_76 ) {
if ( F_123 ( & V_76 -> V_89 ) < V_151 ) {
F_91 ( V_88 , V_114 -> V_115 ) ;
F_106 ( & V_76 -> V_89 , V_88 ) ;
} else {
++ V_2 -> V_147 . V_148 ;
F_122 ( V_88 ) ;
}
if ( ! V_76 -> V_118 && F_118 ( V_2 , V_76 ) ) {
F_99 ( & V_4 -> V_94 , V_6 ) ;
if ( V_152 )
F_64 ( V_2 , V_76 ) ;
return;
} else
F_60 ( V_2 , V_76 ) ;
} else {
++ V_2 -> V_147 . V_148 ;
F_122 ( V_88 ) ;
}
F_99 ( & V_4 -> V_94 , V_6 ) ;
return;
}
if ( V_76 -> V_90 ) {
F_3 ( V_4 , L_24 ,
F_80 ( V_76 -> V_77 . V_96 ) ) ;
F_99 ( & V_4 -> V_94 , V_6 ) ;
F_124 ( V_2 , V_88 , V_76 -> V_90 , F_125 ( V_114 -> V_115 ) ) ;
return;
} else if ( ( V_76 -> V_118 || ! F_118 ( V_2 , V_76 ) ) &&
F_123 ( & V_76 -> V_89 ) < V_151 ) {
F_91 ( V_88 , V_114 -> V_115 ) ;
F_106 ( & V_76 -> V_89 , V_88 ) ;
} else {
++ V_2 -> V_147 . V_148 ;
F_122 ( V_88 ) ;
}
F_99 ( & V_4 -> V_94 , V_6 ) ;
}
static int F_128 ( struct V_87 * V_88 , struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_124 * V_125 ;
struct V_113 * V_114 ;
struct V_153 * V_154 ;
unsigned long V_6 ;
V_114 = (struct V_113 * ) V_88 -> V_46 ;
F_129 ( V_88 , sizeof( * V_114 ) ) ;
V_154 = (struct V_153 * ) V_88 -> V_46 ;
if ( F_130 ( V_114 -> V_115 [ 4 ] == 0xff ) ) {
if ( ( V_154 -> V_155 != F_131 ( V_156 ) ) &&
( V_154 -> V_155 != F_131 ( V_157 ) ) &&
( V_154 -> V_155 != F_131 ( V_158 ) ) &&
( V_154 -> V_155 != F_131 ( V_159 ) ) &&
( V_154 -> V_155 != F_131 ( V_160 ) ) ) {
++ V_2 -> V_147 . V_148 ;
F_122 ( V_88 ) ;
return V_161 ;
}
V_114 -> V_115 [ 8 ] = ( V_4 -> V_63 >> 8 ) & 0xff ;
V_114 -> V_115 [ 9 ] = V_4 -> V_63 & 0xff ;
V_125 = F_132 ( V_2 , V_114 -> V_115 ) ;
if ( F_133 ( V_125 ) )
goto V_162;
F_134 ( V_2 , V_114 -> V_115 , V_88 ) ;
return V_161 ;
}
switch ( V_154 -> V_155 ) {
case F_131 ( V_156 ) :
case F_131 ( V_157 ) :
case F_131 ( V_160 ) :
V_125 = F_132 ( V_2 , V_114 -> V_115 ) ;
if ( F_130 ( ! V_125 ) ) {
F_120 ( V_88 , V_114 -> V_115 , V_2 ) ;
return V_161 ;
}
break;
case F_131 ( V_158 ) :
case F_131 ( V_159 ) :
F_127 ( V_88 , V_2 , V_114 ) ;
return V_161 ;
default:
++ V_2 -> V_147 . V_148 ;
F_122 ( V_88 ) ;
return V_161 ;
}
V_162:
if ( F_109 ( V_125 ) ) {
if ( F_135 ( V_125 ) ) {
F_136 ( V_2 , V_88 , F_109 ( V_125 ) ) ;
goto V_163;
}
} else if ( V_125 -> V_90 ) {
F_124 ( V_2 , V_88 , V_125 -> V_90 , F_125 ( V_114 -> V_115 ) ) ;
goto V_163;
}
if ( F_123 ( & V_125 -> V_89 ) < V_151 ) {
F_91 ( V_88 , V_114 -> V_115 ) ;
F_95 ( & V_4 -> V_94 , V_6 ) ;
F_106 ( & V_125 -> V_89 , V_88 ) ;
F_99 ( & V_4 -> V_94 , V_6 ) ;
} else {
++ V_2 -> V_147 . V_148 ;
F_122 ( V_88 ) ;
}
V_163:
F_126 ( V_125 ) ;
return V_161 ;
}
static void F_137 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
F_25 ( V_4 , L_25 ,
F_138 ( V_164 - F_139 ( V_2 ) ) ) ;
F_25 ( V_4 , L_26 ,
F_140 ( V_2 ) ,
V_4 -> V_165 , V_4 -> V_166 ) ;
}
static int F_141 ( struct V_87 * V_88 ,
struct V_1 * V_2 ,
unsigned short type ,
const void * V_112 , const void * V_167 , unsigned V_168 )
{
struct V_153 * V_154 ;
V_154 = (struct V_153 * ) F_92 ( V_88 , sizeof *V_154 ) ;
V_154 -> V_155 = F_131 ( type ) ;
V_154 -> V_169 = 0 ;
F_91 ( V_88 , V_112 ) ;
return V_170 ;
}
static void F_142 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
if ( ! F_7 ( V_171 , & V_4 -> V_6 ) ) {
F_3 ( V_4 , L_27 ) ;
return;
}
F_143 ( V_4 -> V_172 , & V_4 -> V_173 ) ;
}
static int F_144 ( const struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
if ( ! F_7 ( V_10 , & V_4 -> V_6 ) )
return V_2 -> V_174 ;
return V_4 -> V_175 -> V_174 ;
}
static T_5 F_145 ( struct V_176 * V_177 , T_4 * V_112 )
{
T_5 * V_178 = ( T_5 * ) V_112 ;
T_5 V_179 ;
V_179 = F_146 ( V_178 [ 3 ] , V_178 [ 4 ] , V_180 & V_178 [ 0 ] , 0 ) ;
return V_179 & V_177 -> V_181 ;
}
struct V_124 * F_132 ( struct V_1 * V_2 , T_4 * V_112 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_182 * V_183 = & V_4 -> V_183 ;
struct V_176 * V_177 ;
struct V_124 * V_125 = NULL ;
T_5 V_184 ;
F_147 () ;
V_177 = F_148 ( V_183 -> V_177 ) ;
if ( ! V_177 )
goto V_185;
V_184 = F_145 ( V_177 , V_112 ) ;
for ( V_125 = F_148 ( V_177 -> V_186 [ V_184 ] ) ;
V_125 != NULL ;
V_125 = F_148 ( V_125 -> V_187 ) ) {
if ( memcmp ( V_112 , V_125 -> V_112 , V_116 ) == 0 ) {
if ( ! F_149 ( & V_125 -> V_188 ) ) {
V_125 = NULL ;
goto V_185;
}
if ( F_133 ( F_123 ( & V_125 -> V_89 ) < V_151 ) )
V_125 -> V_189 = V_164 ;
goto V_185;
}
}
V_185:
F_150 () ;
return V_125 ;
}
static void F_151 ( struct V_3 * V_4 )
{
struct V_182 * V_183 = & V_4 -> V_183 ;
struct V_176 * V_177 ;
unsigned long V_190 ;
unsigned long V_191 ;
unsigned long V_6 ;
int V_192 ;
F_93 ( V_117 ) ;
if ( F_7 ( V_193 , & V_4 -> V_6 ) )
return;
F_95 ( & V_4 -> V_94 , V_6 ) ;
V_177 = F_152 ( V_183 -> V_177 ,
F_153 ( & V_4 -> V_94 ) ) ;
if ( ! V_177 )
goto V_185;
V_191 = 2 * V_194 . V_195 ;
V_190 = V_164 - V_191 ;
if ( F_7 ( V_193 , & V_4 -> V_6 ) )
goto V_185;
for ( V_192 = 0 ; V_192 < V_177 -> V_196 ; V_192 ++ ) {
struct V_124 * V_125 ;
struct V_124 T_6 * * V_197 = & V_177 -> V_186 [ V_192 ] ;
while ( ( V_125 = F_152 ( * V_197 ,
F_153 ( & V_4 -> V_94 ) ) ) != NULL ) {
if ( F_154 ( V_190 , V_125 -> V_189 ) ) {
F_155 ( V_4 , V_125 -> V_112 + 4 , & V_117 ) ;
F_156 ( * V_197 ,
F_152 ( V_125 -> V_187 ,
F_153 ( & V_4 -> V_94 ) ) ) ;
F_157 ( & V_125 -> V_85 ) ;
F_158 ( & V_125 -> V_198 , V_199 ) ;
} else {
V_197 = & V_125 -> V_187 ;
}
}
}
V_185:
F_99 ( & V_4 -> V_94 , V_6 ) ;
F_159 ( & V_117 ) ;
}
static void F_160 ( struct V_200 * V_201 )
{
struct V_3 * V_4 =
F_161 ( V_201 , struct V_3 , V_202 . V_201 ) ;
F_151 ( V_4 ) ;
if ( ! F_7 ( V_193 , & V_4 -> V_6 ) )
F_162 ( V_4 -> V_172 , & V_4 -> V_202 ,
V_194 . V_195 ) ;
}
static struct V_124 * F_163 ( T_4 * V_112 ,
struct V_1 * V_2 )
{
struct V_124 * V_125 ;
V_125 = F_115 ( sizeof *V_125 , V_136 ) ;
if ( ! V_125 )
return NULL ;
V_125 -> V_2 = V_2 ;
memcpy ( & V_125 -> V_112 , V_112 , sizeof( V_125 -> V_112 ) ) ;
F_102 ( & V_125 -> V_89 ) ;
F_116 ( & V_125 -> V_85 ) ;
F_110 ( V_125 , NULL ) ;
F_164 ( & V_125 -> V_188 , 1 ) ;
return V_125 ;
}
struct V_124 * F_121 ( T_4 * V_112 ,
struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_182 * V_183 = & V_4 -> V_183 ;
struct V_176 * V_177 ;
struct V_124 * V_125 ;
T_5 V_184 ;
V_177 = F_152 ( V_183 -> V_177 ,
F_153 ( & V_4 -> V_94 ) ) ;
if ( ! V_177 ) {
V_125 = NULL ;
goto V_185;
}
V_184 = F_145 ( V_177 , V_112 ) ;
for ( V_125 = F_152 ( V_177 -> V_186 [ V_184 ] ,
F_153 ( & V_4 -> V_94 ) ) ;
V_125 != NULL ;
V_125 = F_152 ( V_125 -> V_187 ,
F_153 ( & V_4 -> V_94 ) ) ) {
if ( memcmp ( V_112 , V_125 -> V_112 , V_116 ) == 0 ) {
if ( ! F_149 ( & V_125 -> V_188 ) ) {
V_125 = NULL ;
break;
}
V_125 -> V_189 = V_164 ;
goto V_185;
}
}
V_125 = F_163 ( V_112 , V_2 ) ;
if ( ! V_125 )
goto V_185;
F_165 ( & V_125 -> V_188 ) ;
V_125 -> V_189 = V_164 ;
F_156 ( V_125 -> V_187 ,
F_152 ( V_177 -> V_186 [ V_184 ] ,
F_153 ( & V_4 -> V_94 ) ) ) ;
F_156 ( V_177 -> V_186 [ V_184 ] , V_125 ) ;
F_165 ( & V_183 -> V_203 ) ;
V_185:
return V_125 ;
}
void F_166 ( struct V_124 * V_125 )
{
struct V_1 * V_2 = V_125 -> V_2 ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_87 * V_88 ;
if ( V_125 -> V_90 )
F_68 ( V_125 -> V_90 ) ;
while ( ( V_88 = F_65 ( & V_125 -> V_89 ) ) ) {
++ V_2 -> V_147 . V_148 ;
F_122 ( V_88 ) ;
}
if ( F_109 ( V_125 ) )
F_167 ( F_109 ( V_125 ) ) ;
F_3 ( F_2 ( V_2 ) ,
L_28 ,
F_125 ( V_125 -> V_112 ) ,
V_125 -> V_112 + 4 ) ;
F_69 ( V_125 ) ;
if ( F_168 ( & V_4 -> V_183 . V_203 ) ) {
if ( F_7 ( V_204 , & V_4 -> V_6 ) )
F_85 ( & V_4 -> V_183 . V_205 ) ;
}
}
static void V_199 ( struct V_206 * V_207 )
{
struct V_124 * V_125 = F_161 ( V_207 , struct V_124 , V_198 ) ;
F_126 ( V_125 ) ;
}
void F_112 ( struct V_124 * V_125 )
{
struct V_1 * V_2 = V_125 -> V_2 ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_182 * V_183 = & V_4 -> V_183 ;
struct V_176 * V_177 ;
struct V_124 T_6 * * V_197 ;
struct V_124 * V_74 ;
T_5 V_184 ;
V_177 = F_152 ( V_183 -> V_177 ,
F_153 ( & V_4 -> V_94 ) ) ;
if ( ! V_177 )
return;
V_184 = F_145 ( V_177 , V_125 -> V_112 ) ;
V_197 = & V_177 -> V_186 [ V_184 ] ;
for ( V_74 = F_152 ( * V_197 ,
F_153 ( & V_4 -> V_94 ) ) ;
V_74 != NULL ;
V_74 = F_152 ( * V_197 ,
F_153 ( & V_4 -> V_94 ) ) ) {
if ( V_74 == V_125 ) {
F_156 ( * V_197 ,
F_152 ( V_125 -> V_187 ,
F_153 ( & V_4 -> V_94 ) ) ) ;
F_157 ( & V_125 -> V_85 ) ;
F_158 ( & V_125 -> V_198 , V_199 ) ;
return;
} else {
V_197 = & V_74 -> V_187 ;
}
}
}
static int F_169 ( struct V_3 * V_4 )
{
struct V_182 * V_183 = & V_4 -> V_183 ;
struct V_176 * V_177 ;
struct V_124 T_6 * * V_186 ;
T_5 V_196 ;
F_14 ( V_204 , & V_4 -> V_6 ) ;
V_183 -> V_177 = NULL ;
V_177 = F_115 ( sizeof( * V_177 ) , V_93 ) ;
if ( ! V_177 )
return - V_108 ;
F_5 ( V_193 , & V_4 -> V_6 ) ;
V_196 = F_170 ( V_194 . V_208 ) ;
V_186 = F_115 ( V_196 * sizeof( * V_186 ) , V_93 ) ;
if ( ! V_186 ) {
F_69 ( V_177 ) ;
return - V_108 ;
}
V_177 -> V_196 = V_196 ;
V_177 -> V_181 = ( V_196 - 1 ) ;
V_177 -> V_186 = V_186 ;
F_171 ( V_183 -> V_177 , V_177 ) ;
V_177 -> V_183 = V_183 ;
F_164 ( & V_183 -> V_203 , 0 ) ;
F_14 ( V_193 , & V_4 -> V_6 ) ;
F_162 ( V_4 -> V_172 , & V_4 -> V_202 ,
V_194 . V_195 ) ;
return 0 ;
}
static void F_172 ( struct V_206 * V_209 )
{
struct V_176 * V_177 = F_161 ( V_209 ,
struct V_176 ,
V_198 ) ;
struct V_124 T_6 * * V_186 = V_177 -> V_186 ;
struct V_182 * V_183 = V_177 -> V_183 ;
F_69 ( V_186 ) ;
F_69 ( V_177 ) ;
F_85 ( & V_183 -> V_210 ) ;
}
void F_67 ( struct V_1 * V_2 , T_4 * V_51 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_182 * V_183 = & V_4 -> V_183 ;
struct V_176 * V_177 ;
unsigned long V_6 ;
int V_192 ;
F_95 ( & V_4 -> V_94 , V_6 ) ;
V_177 = F_152 ( V_183 -> V_177 ,
F_153 ( & V_4 -> V_94 ) ) ;
if ( ! V_177 )
goto V_185;
for ( V_192 = 0 ; V_192 < V_177 -> V_196 ; V_192 ++ ) {
struct V_124 * V_125 ;
struct V_124 T_6 * * V_197 = & V_177 -> V_186 [ V_192 ] ;
while ( ( V_125 = F_152 ( * V_197 ,
F_153 ( & V_4 -> V_94 ) ) ) != NULL ) {
if ( ! memcmp ( V_51 , V_125 -> V_112 + 4 , sizeof ( union V_50 ) ) ) {
F_156 ( * V_197 ,
F_152 ( V_125 -> V_187 ,
F_153 ( & V_4 -> V_94 ) ) ) ;
F_157 ( & V_125 -> V_85 ) ;
F_158 ( & V_125 -> V_198 , V_199 ) ;
} else {
V_197 = & V_125 -> V_187 ;
}
}
}
V_185:
F_99 ( & V_4 -> V_94 , V_6 ) ;
}
static void F_173 ( struct V_3 * V_4 )
{
struct V_182 * V_183 = & V_4 -> V_183 ;
struct V_176 * V_177 ;
unsigned long V_6 ;
int V_192 , V_211 = 0 ;
F_87 ( & V_4 -> V_183 . V_205 ) ;
F_95 ( & V_4 -> V_94 , V_6 ) ;
V_177 = F_152 ( V_183 -> V_177 ,
F_153 ( & V_4 -> V_94 ) ) ;
if ( ! V_177 )
goto V_185;
V_211 = F_174 ( & V_4 -> V_183 . V_203 ) ;
if ( ! V_211 )
goto V_212;
for ( V_192 = 0 ; V_192 < V_177 -> V_196 ; V_192 ++ ) {
struct V_124 * V_125 ;
struct V_124 T_6 * * V_197 = & V_177 -> V_186 [ V_192 ] ;
while ( ( V_125 = F_152 ( * V_197 ,
F_153 ( & V_4 -> V_94 ) ) ) != NULL ) {
F_156 ( * V_197 ,
F_152 ( V_125 -> V_187 ,
F_153 ( & V_4 -> V_94 ) ) ) ;
F_157 ( & V_125 -> V_85 ) ;
F_158 ( & V_125 -> V_198 , V_199 ) ;
}
}
V_212:
F_156 ( V_183 -> V_177 , NULL ) ;
F_158 ( & V_177 -> V_198 , F_172 ) ;
V_185:
F_99 ( & V_4 -> V_94 , V_6 ) ;
if ( V_211 )
F_90 ( & V_4 -> V_183 . V_205 ) ;
}
static void F_175 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_213 ;
F_3 ( V_4 , L_29 ) ;
F_87 ( & V_4 -> V_183 . V_210 ) ;
F_5 ( V_204 , & V_4 -> V_6 ) ;
V_213 = F_176 ( V_193 , & V_4 -> V_6 ) ;
if ( ! V_213 )
F_177 ( & V_4 -> V_202 ) ;
F_173 ( V_4 ) ;
F_90 ( & V_4 -> V_183 . V_210 ) ;
}
int F_178 ( struct V_1 * V_2 , struct V_62 * V_110 , int V_61 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
V_4 -> V_214 = F_115 ( V_215 * sizeof * V_4 -> V_214 ,
V_93 ) ;
if ( ! V_4 -> V_214 )
goto V_49;
V_4 -> V_216 = F_179 ( V_217 * sizeof * V_4 -> V_216 ) ;
if ( ! V_4 -> V_216 ) {
F_180 ( V_218 L_30 ,
V_110 -> V_104 , V_217 ) ;
goto V_219;
}
if ( F_181 ( V_2 , V_110 , V_61 ) )
goto V_220;
if ( F_169 ( V_4 ) < 0 )
goto V_221;
return 0 ;
V_221:
F_182 ( V_2 ) ;
V_220:
F_183 ( V_4 -> V_216 ) ;
V_219:
F_69 ( V_4 -> V_214 ) ;
V_49:
return - V_108 ;
}
void F_20 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) , * V_11 , * V_222 ;
F_93 ( V_209 ) ;
F_184 () ;
F_185 ( V_2 ) ;
F_79 (cpriv, tcpriv, &priv->child_intfs, list) {
F_5 ( V_193 , & V_11 -> V_6 ) ;
F_177 ( & V_11 -> V_202 ) ;
F_186 ( V_11 -> V_2 , & V_209 ) ;
}
F_187 ( & V_209 ) ;
F_175 ( V_2 ) ;
F_182 ( V_2 ) ;
F_69 ( V_4 -> V_214 ) ;
F_183 ( V_4 -> V_216 ) ;
V_4 -> V_214 = NULL ;
V_4 -> V_216 = NULL ;
}
static int F_188 ( struct V_1 * V_2 , int V_223 , int V_224 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
return F_189 ( V_4 -> V_110 , V_223 , V_4 -> V_61 , V_224 ) ;
}
static int F_190 ( struct V_1 * V_2 , int V_223 ,
struct V_225 * V_226 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_227 ;
V_227 = F_191 ( V_4 -> V_110 , V_223 , V_4 -> V_61 , V_226 ) ;
if ( V_227 )
return V_227 ;
V_226 -> V_223 = V_223 ;
return 0 ;
}
static int F_192 ( struct V_1 * V_2 , int V_223 , T_7 V_228 , int type )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
if ( type != V_229 && type != V_230 )
return - V_14 ;
return F_193 ( V_4 -> V_110 , V_223 , V_4 -> V_61 , V_228 , type ) ;
}
static int F_194 ( struct V_1 * V_2 , int V_223 ,
struct V_231 * V_232 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
return F_195 ( V_4 -> V_110 , V_223 , V_4 -> V_61 , V_232 ) ;
}
void F_196 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
if ( V_4 -> V_233 & V_234 )
V_2 -> V_235 = & V_236 ;
else
V_2 -> V_235 = & V_237 ;
V_2 -> V_238 = & V_239 ;
F_197 ( V_2 ) ;
F_198 ( V_2 , & V_4 -> V_240 , V_241 , V_242 ) ;
V_2 -> V_243 = V_244 ;
V_2 -> V_6 |= V_245 | V_246 ;
V_2 -> V_247 = V_170 ;
V_2 -> V_248 = V_116 ;
V_2 -> type = V_249 ;
V_2 -> V_250 = V_217 * 2 ;
V_2 -> V_15 = ( V_251 |
V_252 ) ;
F_199 ( V_2 ) ;
memcpy ( V_2 -> V_135 , V_253 , V_116 ) ;
V_4 -> V_2 = V_2 ;
F_200 ( & V_4 -> V_94 ) ;
F_201 ( & V_4 -> V_12 ) ;
F_116 ( & V_4 -> V_86 ) ;
F_116 ( & V_4 -> V_254 ) ;
F_116 ( & V_4 -> V_255 ) ;
F_116 ( & V_4 -> V_256 ) ;
F_202 ( & V_4 -> V_257 , V_258 ) ;
F_203 ( & V_4 -> V_259 , V_260 ) ;
F_203 ( & V_4 -> V_261 , V_262 ) ;
F_203 ( & V_4 -> V_263 , V_264 ) ;
F_203 ( & V_4 -> V_265 , V_266 ) ;
F_203 ( & V_4 -> V_173 , V_267 ) ;
F_202 ( & V_4 -> V_268 , V_269 ) ;
F_202 ( & V_4 -> V_202 , F_160 ) ;
}
struct V_3 * F_204 ( const char * V_104 )
{
struct V_1 * V_2 ;
V_2 = F_205 ( ( int ) sizeof( struct V_3 ) , V_104 ,
V_270 , F_196 ) ;
if ( ! V_2 )
return NULL ;
return F_2 ( V_2 ) ;
}
static T_8 F_206 ( struct V_271 * V_2 ,
struct V_272 * V_273 , char * V_65 )
{
struct V_3 * V_4 = F_2 ( F_207 ( V_2 ) ) ;
return sprintf ( V_65 , L_31 , V_4 -> V_63 ) ;
}
static T_8 F_208 ( struct V_271 * V_2 ,
struct V_272 * V_273 , char * V_65 )
{
struct V_3 * V_4 = F_2 ( F_207 ( V_2 ) ) ;
return sprintf ( V_65 , L_32 , F_7 ( V_274 , & V_4 -> V_6 ) ) ;
}
void F_209 ( struct V_1 * V_275 , int V_276 )
{
struct V_3 * V_4 = F_2 ( V_275 ) ;
if ( V_276 > 0 ) {
F_5 ( V_274 , & V_4 -> V_6 ) ;
F_25 ( V_4 , L_33
L_34 ) ;
} else
F_14 ( V_274 , & V_4 -> V_6 ) ;
}
static T_8 F_210 ( struct V_271 * V_2 ,
struct V_272 * V_273 ,
const char * V_65 , T_9 V_277 )
{
unsigned long V_276 = F_211 ( V_65 , NULL , 0 ) ;
F_209 ( F_207 ( V_2 ) , V_276 ) ;
return V_277 ;
}
int F_212 ( struct V_1 * V_2 )
{
return F_213 ( & V_2 -> V_2 , & V_278 ) ;
}
static void F_214 ( struct V_3 * V_4 , union V_50 * V_51 )
{
struct V_3 * V_55 ;
struct V_1 * V_279 = V_4 -> V_2 ;
F_215 ( V_279 ) ;
memcpy ( & V_4 -> V_58 . V_280 . V_281 ,
& V_51 -> V_280 . V_281 ,
sizeof( V_51 -> V_280 . V_281 ) ) ;
memcpy ( V_279 -> V_66 + 4 , & V_4 -> V_58 , sizeof( V_4 -> V_58 ) ) ;
F_14 ( V_282 , & V_4 -> V_6 ) ;
F_216 ( V_279 ) ;
if ( ! F_7 ( V_10 , & V_4 -> V_6 ) ) {
F_9 ( & V_4 -> V_12 ) ;
F_10 (child_priv, &priv->child_intfs, list)
F_214 ( V_55 , V_51 ) ;
F_12 ( & V_4 -> V_12 ) ;
}
}
static int F_217 ( struct V_1 * V_2 ,
struct V_283 * V_284 )
{
union V_50 * V_51 = (union V_50 * ) ( V_284 -> V_285 + 4 ) ;
int V_47 = 0 ;
F_215 ( V_2 ) ;
if ( memcmp ( V_2 -> V_66 , V_284 -> V_285 ,
4 + sizeof( V_51 -> V_280 . V_286 ) ) ||
V_51 -> V_280 . V_281 == 0 )
V_47 = - V_14 ;
F_216 ( V_2 ) ;
return V_47 ;
}
static int F_218 ( struct V_1 * V_2 , void * V_25 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_283 * V_284 = V_25 ;
int V_47 ;
if ( ! ( V_2 -> V_287 & V_288 ) && F_219 ( V_2 ) )
return - V_71 ;
V_47 = F_217 ( V_2 , V_284 ) ;
if ( V_47 )
return V_47 ;
F_214 ( V_4 , (union V_50 * ) ( V_284 -> V_285 + 4 ) ) ;
F_143 ( V_289 , & V_4 -> V_261 ) ;
return 0 ;
}
static T_8 F_220 ( struct V_271 * V_2 ,
struct V_272 * V_273 ,
const char * V_65 , T_9 V_277 )
{
int V_63 ;
int V_47 ;
if ( sscanf ( V_65 , L_35 , & V_63 ) != 1 )
return - V_14 ;
if ( V_63 <= 0 || V_63 > 0xffff || V_63 == 0x8000 )
return - V_14 ;
V_63 |= 0x8000 ;
V_47 = F_221 ( F_207 ( V_2 ) , V_63 ) ;
return V_47 ? V_47 : V_277 ;
}
static T_8 F_222 ( struct V_271 * V_2 ,
struct V_272 * V_273 ,
const char * V_65 , T_9 V_277 )
{
int V_63 ;
int V_47 ;
if ( sscanf ( V_65 , L_35 , & V_63 ) != 1 )
return - V_14 ;
if ( V_63 < 0 || V_63 > 0xffff )
return - V_14 ;
V_47 = F_223 ( F_207 ( V_2 ) , V_63 ) ;
return V_47 ? V_47 : V_277 ;
}
int F_224 ( struct V_1 * V_2 )
{
return F_213 ( & V_2 -> V_2 , & V_290 ) ;
}
void F_225 ( struct V_3 * V_4 , struct V_62 * V_291 )
{
V_4 -> V_233 = V_291 -> V_292 . V_293 ;
if ( V_4 -> V_233 & V_294 ) {
V_4 -> V_2 -> V_295 = V_17 | V_296 ;
if ( V_4 -> V_233 & V_297 )
V_4 -> V_2 -> V_295 |= V_18 ;
V_4 -> V_2 -> V_15 |= V_4 -> V_2 -> V_295 ;
}
}
static struct V_1 * F_226 ( const char * V_298 ,
struct V_62 * V_291 , T_4 V_61 )
{
struct V_3 * V_4 ;
struct V_299 V_273 ;
int V_48 = - V_108 ;
V_4 = F_204 ( V_298 ) ;
if ( ! V_4 )
goto V_300;
F_227 ( V_4 -> V_2 , V_291 -> V_2 . V_175 ) ;
V_4 -> V_2 -> V_301 = V_61 - 1 ;
V_48 = F_228 ( V_291 , V_61 , & V_273 ) ;
if ( ! V_48 )
V_4 -> V_22 = F_229 ( V_273 . V_302 ) ;
else {
F_180 ( V_218 L_36 ,
V_291 -> V_104 , V_61 ) ;
goto V_303;
}
V_4 -> V_2 -> V_21 = F_26 ( V_4 -> V_22 ) ;
V_4 -> V_20 = V_4 -> V_23 = V_4 -> V_2 -> V_21 ;
V_4 -> V_2 -> V_302 = V_304 ;
V_4 -> V_2 -> V_305 = sizeof( struct V_124 ) ;
V_48 = F_230 ( V_291 , V_61 , 0 , & V_4 -> V_63 ) ;
if ( V_48 ) {
F_180 ( V_218 L_37 ,
V_291 -> V_104 , V_61 , V_48 ) ;
goto V_303;
}
F_225 ( V_4 , V_291 ) ;
V_4 -> V_63 |= 0x8000 ;
V_4 -> V_2 -> V_135 [ 8 ] = V_4 -> V_63 >> 8 ;
V_4 -> V_2 -> V_135 [ 9 ] = V_4 -> V_63 & 0xff ;
V_48 = F_231 ( V_291 , V_61 , 0 , & V_4 -> V_58 , NULL ) ;
if ( V_48 ) {
F_180 ( V_218 L_38 ,
V_291 -> V_104 , V_61 , V_48 ) ;
goto V_303;
} else
memcpy ( V_4 -> V_2 -> V_66 + 4 , V_4 -> V_58 . V_79 , sizeof ( union V_50 ) ) ;
F_5 ( V_282 , & V_4 -> V_6 ) ;
V_48 = F_178 ( V_4 -> V_2 , V_291 , V_61 ) ;
if ( V_48 < 0 ) {
F_180 ( V_218 L_39 ,
V_291 -> V_104 , V_61 , V_48 ) ;
goto V_303;
}
F_232 ( & V_4 -> V_306 ,
V_4 -> V_110 , V_307 ) ;
V_48 = F_233 ( & V_4 -> V_306 ) ;
if ( V_48 < 0 ) {
F_180 ( V_218 L_40
L_41 ,
V_291 -> V_104 , V_61 , V_48 ) ;
goto V_308;
}
V_48 = F_234 ( V_4 -> V_2 ) ;
if ( V_48 ) {
F_180 ( V_218 L_42 ,
V_291 -> V_104 , V_61 , V_48 ) ;
goto V_309;
}
F_235 ( V_4 -> V_2 ) ;
if ( F_236 ( V_4 -> V_2 ) )
goto V_310;
if ( F_224 ( V_4 -> V_2 ) )
goto V_310;
if ( F_212 ( V_4 -> V_2 ) )
goto V_310;
if ( F_213 ( & V_4 -> V_2 -> V_2 , & V_311 ) )
goto V_310;
if ( F_213 ( & V_4 -> V_2 -> V_2 , & V_312 ) )
goto V_310;
return V_4 -> V_2 ;
V_310:
F_185 ( V_4 -> V_2 ) ;
F_237 ( V_4 -> V_2 ) ;
V_309:
F_238 ( & V_4 -> V_306 ) ;
F_239 ( V_289 ) ;
F_5 ( V_193 , & V_4 -> V_6 ) ;
F_177 ( & V_4 -> V_202 ) ;
F_239 ( V_4 -> V_172 ) ;
V_308:
F_20 ( V_4 -> V_2 ) ;
V_303:
F_240 ( V_4 -> V_2 ) ;
V_300:
return F_241 ( V_48 ) ;
}
static void F_242 ( struct V_62 * V_271 )
{
struct V_59 * V_60 ;
struct V_1 * V_2 ;
struct V_3 * V_4 ;
int V_313 ;
int V_277 = 0 ;
V_60 = F_71 ( sizeof *V_60 , V_93 ) ;
if ( ! V_60 )
return;
F_116 ( V_60 ) ;
for ( V_313 = F_243 ( V_271 ) ; V_313 <= F_244 ( V_271 ) ; ++ V_313 ) {
if ( ! F_48 ( V_271 , V_313 ) )
continue;
V_2 = F_226 ( L_43 , V_271 , V_313 ) ;
if ( ! F_245 ( V_2 ) ) {
V_4 = F_2 ( V_2 ) ;
F_63 ( & V_4 -> V_85 , V_60 ) ;
V_277 ++ ;
}
}
if ( ! V_277 ) {
F_69 ( V_60 ) ;
return;
}
F_246 ( V_271 , & V_314 , V_60 ) ;
}
static void F_247 ( struct V_62 * V_271 , void * V_64 )
{
struct V_3 * V_4 , * V_315 ;
struct V_59 * V_60 = V_64 ;
if ( ! V_60 )
return;
F_79 (priv, tmp, dev_list, list) {
F_238 ( & V_4 -> V_306 ) ;
F_239 ( V_289 ) ;
F_5 ( V_316 , & V_4 -> V_6 ) ;
F_248 () ;
F_11 ( V_4 -> V_2 , V_4 -> V_2 -> V_6 & ~ V_13 ) ;
F_55 () ;
F_5 ( V_193 , & V_4 -> V_6 ) ;
F_177 ( & V_4 -> V_202 ) ;
F_239 ( V_4 -> V_172 ) ;
F_237 ( V_4 -> V_2 ) ;
F_240 ( V_4 -> V_2 ) ;
}
F_69 ( V_60 ) ;
}
static int T_10 F_249 ( void )
{
int V_47 ;
V_215 = F_170 ( V_215 ) ;
V_215 = F_27 ( V_215 , V_317 ) ;
V_215 = F_250 ( V_215 , V_318 ) ;
V_217 = F_170 ( V_217 ) ;
V_217 = F_27 ( V_217 , V_317 ) ;
V_217 = F_251 ( V_217 , 2 * V_319 , V_318 ) ;
#ifdef F_252
V_320 = F_27 ( V_320 , V_321 ) ;
#endif
F_253 ( V_322 > V_323 ) ;
V_47 = F_254 () ;
if ( V_47 )
return V_47 ;
V_289 = F_255 ( L_44 ,
V_324 ) ;
if ( ! V_289 ) {
V_47 = - V_108 ;
goto V_325;
}
F_256 ( & V_109 ) ;
V_47 = F_257 ( & V_314 ) ;
if ( V_47 )
goto V_326;
V_47 = F_258 () ;
if ( V_47 )
goto V_327;
return 0 ;
V_327:
F_259 ( & V_314 ) ;
V_326:
F_260 ( & V_109 ) ;
F_261 ( V_289 ) ;
V_325:
F_262 () ;
return V_47 ;
}
static void T_11 F_263 ( void )
{
F_264 () ;
F_259 ( & V_314 ) ;
F_260 ( & V_109 ) ;
F_262 () ;
F_261 ( V_289 ) ;
}
