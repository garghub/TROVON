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
if ( F_8 ( V_2 ) )
goto V_10;
if ( ! F_7 ( V_11 , & V_4 -> V_6 ) ) {
struct V_3 * V_12 ;
F_9 ( & V_4 -> V_13 ) ;
F_10 (cpriv, &priv->child_intfs, list) {
int V_6 ;
V_6 = V_12 -> V_2 -> V_6 ;
if ( V_6 & V_14 )
continue;
F_11 ( V_12 -> V_2 , V_6 | V_14 ) ;
}
F_12 ( & V_4 -> V_13 ) ;
}
F_13 ( V_2 ) ;
return 0 ;
V_10:
F_14 ( V_2 ) ;
V_9:
F_15 ( V_5 , & V_4 -> V_6 ) ;
return - V_15 ;
}
static int F_16 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
F_3 ( V_4 , L_2 ) ;
F_15 ( V_5 , & V_4 -> V_6 ) ;
F_17 ( V_2 ) ;
F_18 ( V_2 ) ;
F_14 ( V_2 ) ;
if ( ! F_7 ( V_11 , & V_4 -> V_6 ) ) {
struct V_3 * V_12 ;
F_9 ( & V_4 -> V_13 ) ;
F_10 (cpriv, &priv->child_intfs, list) {
int V_6 ;
V_6 = V_12 -> V_2 -> V_6 ;
if ( ! ( V_6 & V_14 ) )
continue;
F_11 ( V_12 -> V_2 , V_6 & ~ V_14 ) ;
}
F_12 ( & V_4 -> V_13 ) ;
}
return 0 ;
}
static void F_19 ( struct V_1 * V_2 )
{
F_20 ( V_2 ) ;
}
static T_1 F_21 ( struct V_1 * V_2 , T_1 V_16 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
if ( F_7 ( V_17 , & V_4 -> V_6 ) )
V_16 &= ~ ( V_18 | V_19 ) ;
return V_16 ;
}
static int F_22 ( struct V_1 * V_2 , int V_20 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
if ( F_23 ( V_2 ) ) {
if ( V_20 > F_24 ( V_2 ) )
return - V_15 ;
if ( V_20 > V_4 -> V_21 )
F_25 ( V_4 , L_3 ,
V_4 -> V_21 ) ;
V_2 -> V_22 = V_20 ;
return 0 ;
}
if ( V_20 > F_26 ( V_4 -> V_23 ) )
return - V_15 ;
V_4 -> V_24 = V_20 ;
V_2 -> V_22 = F_27 ( V_4 -> V_21 , V_4 -> V_24 ) ;
return 0 ;
}
static bool F_28 ( const struct V_25 * V_26 ,
struct V_1 * V_2 )
{
struct V_27 * V_27 = F_29 ( V_2 ) ;
struct V_28 * V_29 ;
struct V_30 * V_31 = (struct V_30 * ) V_26 ;
struct V_32 * V_33 = (struct V_32 * ) V_26 ;
T_2 V_34 ;
switch ( V_26 -> V_35 ) {
case V_36 :
V_29 = F_30 ( V_2 ) ;
if ( ! V_29 )
return false ;
V_34 = F_31 ( V_27 , V_29 , 0 ,
V_31 -> V_37 . V_38 ,
V_39 ) ;
F_32 ( V_29 ) ;
if ( V_34 )
return true ;
break;
case V_40 :
if ( F_33 ( V_41 ) &&
F_34 ( V_27 , & V_33 -> V_42 , V_2 , 1 ) )
return true ;
break;
}
return false ;
}
static struct V_1 * F_35 ( struct V_1 * V_2 )
{
struct V_1 * V_43 ;
F_36 () ;
V_43 = F_37 ( V_2 ) ;
if ( V_43 )
F_38 ( V_43 ) ;
F_39 () ;
if ( V_43 )
return V_43 ;
F_38 ( V_2 ) ;
return V_2 ;
}
static struct V_1 * F_40 (
const struct V_25 * V_26 , struct V_1 * V_2 )
{
struct V_1 * V_44 ,
* V_45 = NULL ;
struct V_46 * V_47 ;
F_36 () ;
if ( F_28 ( V_26 , V_2 ) ) {
F_38 ( V_2 ) ;
V_45 = V_2 ;
goto V_48;
}
F_41 (dev, upper, iter) {
if ( F_28 ( V_26 , V_44 ) ) {
F_38 ( V_44 ) ;
V_45 = V_44 ;
break;
}
}
V_48:
F_39 () ;
return V_45 ;
}
static int F_42 ( struct V_3 * V_4 ,
const union V_49 * V_50 ,
T_3 V_51 ,
const struct V_25 * V_26 ,
int V_52 ,
struct V_1 * * V_53 )
{
struct V_3 * V_54 ;
struct V_1 * V_55 = NULL ;
int V_56 = 0 ;
if ( V_4 -> V_51 == V_51 &&
( ! V_50 || ! memcmp ( V_50 , & V_4 -> V_57 , sizeof( * V_50 ) ) ) ) {
if ( ! V_26 ) {
V_55 = F_35 ( V_4 -> V_2 ) ;
} else {
V_55 = F_40 ( V_26 , V_4 -> V_2 ) ;
}
if ( V_55 ) {
if ( ! * V_53 )
* V_53 = V_55 ;
else
F_43 ( V_55 ) ;
++ V_56 ;
}
}
F_44 ( & V_4 -> V_13 , V_52 ) ;
F_10 (child_priv, &priv->child_intfs, list) {
V_56 += F_42 ( V_54 , V_50 ,
V_51 , V_26 ,
V_52 + 1 ,
V_53 ) ;
if ( V_56 > 1 )
break;
}
F_12 ( & V_4 -> V_13 ) ;
return V_56 ;
}
static int F_45 ( struct V_46 * V_58 , T_4 V_59 ,
T_3 V_51 ,
const union V_49 * V_50 ,
const struct V_25 * V_26 ,
struct V_1 * * V_55 )
{
struct V_3 * V_4 ;
int V_56 = 0 ;
* V_55 = NULL ;
F_10 (priv, dev_list, list) {
if ( V_4 -> V_59 != V_59 )
continue;
V_56 += F_42 ( V_4 , V_50 , V_51 ,
V_26 , 0 , V_55 ) ;
if ( V_56 > 1 )
break;
}
return V_56 ;
}
static struct V_1 * F_46 (
struct V_60 * V_2 , T_4 V_59 , T_3 V_61 ,
const union V_49 * V_50 , const struct V_25 * V_26 ,
void * V_62 )
{
struct V_1 * V_55 ;
struct V_46 * V_58 = V_62 ;
T_3 V_51 ;
int V_56 ;
int V_63 ;
if ( ! F_47 ( V_2 , V_59 ) )
return NULL ;
V_63 = F_48 ( V_2 , V_59 , V_61 , & V_51 ) ;
if ( V_63 )
return NULL ;
if ( ! V_58 )
return NULL ;
V_56 = F_45 ( V_58 , V_59 , V_51 ,
V_50 , NULL , & V_55 ) ;
switch ( V_56 ) {
case 0 :
return NULL ;
case 1 :
return V_55 ;
}
F_43 ( V_55 ) ;
V_56 = F_45 ( V_58 , V_59 , V_51 ,
V_50 , V_26 , & V_55 ) ;
switch ( V_56 ) {
case 0 :
return NULL ;
default:
F_49 ( & V_2 -> V_2 ,
L_4 ) ;
case 1 :
return V_55 ;
}
}
int F_50 ( struct V_1 * V_2 , const char * V_64 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
if ( F_51 ( V_2 -> V_65 ) && ! strcmp ( V_64 , L_5 ) ) {
F_5 ( V_17 , & V_4 -> V_6 ) ;
F_25 ( V_4 , L_6
L_7 ) ;
F_52 ( V_2 ) ;
F_53 ( V_2 , F_24 ( V_2 ) ) ;
F_54 () ;
V_4 -> V_66 . V_67 . V_68 &= ~ V_69 ;
F_55 ( V_2 ) ;
F_56 () ;
return 0 ;
}
if ( ! strcmp ( V_64 , L_8 ) ) {
F_15 ( V_17 , & V_4 -> V_6 ) ;
F_52 ( V_2 ) ;
F_53 ( V_2 , F_27 ( V_4 -> V_21 , V_2 -> V_22 ) ) ;
F_54 () ;
F_55 ( V_2 ) ;
F_56 () ;
return 0 ;
}
return - V_15 ;
}
static struct V_70 * F_57 ( struct V_1 * V_2 , void * V_50 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_71 * V_72 = V_4 -> V_73 . V_71 ;
struct V_70 * V_74 ;
int V_63 ;
while ( V_72 ) {
V_74 = F_58 ( V_72 , struct V_70 , V_71 ) ;
V_63 = memcmp ( V_50 , V_74 -> V_75 . V_76 . V_77 ,
sizeof ( union V_49 ) ) ;
if ( V_63 < 0 )
V_72 = V_72 -> V_78 ;
else if ( V_63 > 0 )
V_72 = V_72 -> V_79 ;
else
return V_74 ;
}
return NULL ;
}
static int F_59 ( struct V_1 * V_2 , struct V_70 * V_74 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_71 * * V_72 = & V_4 -> V_73 . V_71 ;
struct V_71 * V_80 = NULL ;
struct V_70 * V_81 ;
int V_63 ;
while ( * V_72 ) {
V_80 = * V_72 ;
V_81 = F_58 ( V_80 , struct V_70 , V_71 ) ;
V_63 = memcmp ( V_74 -> V_75 . V_76 . V_77 , V_81 -> V_75 . V_76 . V_77 ,
sizeof ( union V_49 ) ) ;
if ( V_63 < 0 )
V_72 = & V_80 -> V_78 ;
else if ( V_63 > 0 )
V_72 = & V_80 -> V_79 ;
else
return - V_82 ;
}
F_60 ( & V_74 -> V_71 , V_80 , V_72 ) ;
F_61 ( & V_74 -> V_71 , & V_4 -> V_73 ) ;
F_62 ( & V_74 -> V_83 , & V_4 -> V_84 ) ;
return 0 ;
}
static void F_63 ( struct V_1 * V_2 , struct V_70 * V_74 )
{
struct V_85 * V_86 ;
while ( ( V_86 = F_64 ( & V_74 -> V_87 ) ) )
F_65 ( V_86 ) ;
F_3 ( F_2 ( V_2 ) , L_9 ) ;
F_66 ( V_2 , V_74 -> V_75 . V_76 . V_77 ) ;
if ( V_74 -> V_88 )
F_67 ( V_74 -> V_88 ) ;
F_68 ( V_74 ) ;
}
struct V_89 * F_69 ( struct V_1 * V_2 )
{
struct V_89 * V_47 ;
V_47 = F_70 ( sizeof *V_47 , V_90 ) ;
if ( ! V_47 )
return NULL ;
V_47 -> V_2 = V_2 ;
memset ( V_47 -> V_74 . V_75 . V_76 . V_77 , 0 , 16 ) ;
if ( F_71 ( V_47 ) ) {
F_68 ( V_47 ) ;
return NULL ;
}
return V_47 ;
}
int F_71 ( struct V_89 * V_47 )
{
struct V_3 * V_4 = F_2 ( V_47 -> V_2 ) ;
struct V_71 * V_72 ;
struct V_70 * V_74 ;
int V_63 = 1 ;
F_72 ( & V_4 -> V_91 ) ;
V_72 = F_73 ( & V_4 -> V_73 ) ;
while ( V_72 ) {
V_74 = F_58 ( V_72 , struct V_70 , V_71 ) ;
if ( memcmp ( V_47 -> V_74 . V_75 . V_76 . V_77 , V_74 -> V_75 . V_76 . V_77 ,
sizeof ( union V_49 ) ) < 0 ) {
V_47 -> V_74 = * V_74 ;
V_63 = 0 ;
break;
}
V_72 = F_74 ( V_72 ) ;
}
F_75 ( & V_4 -> V_91 ) ;
return V_63 ;
}
void F_76 ( struct V_89 * V_47 ,
struct V_70 * V_74 )
{
* V_74 = V_47 -> V_74 ;
}
void F_77 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_70 * V_74 , * V_92 ;
F_72 ( & V_4 -> V_91 ) ;
F_78 (path, tp, &priv->path_list, list) {
F_3 ( V_4 , L_10 ,
F_79 ( V_74 -> V_75 . V_93 ) ,
V_74 -> V_75 . V_76 . V_77 ) ;
V_74 -> V_94 = 0 ;
}
F_75 ( & V_4 -> V_91 ) ;
}
static void F_80 ( int V_95 , struct V_96 * V_97 ,
void * V_98 )
{
struct V_99 * V_100 = V_98 ;
struct V_3 * V_4 ;
F_81 ( ! V_98 ) ;
V_4 = V_100 -> V_4 ;
if ( V_95 || ! V_97 ) {
F_82 ( L_11 ,
V_4 -> V_2 -> V_101 , V_95 ) ;
V_4 -> V_7 = false ;
goto V_48;
}
if ( F_83 ( V_97 ) &
V_102 ) {
F_82 ( L_12 ,
V_4 -> V_2 -> V_101 ) ;
V_4 -> V_7 = true ;
} else {
F_82 ( L_13 ,
V_4 -> V_2 -> V_101 ) ;
V_4 -> V_7 = false ;
}
V_48:
F_84 ( & V_100 -> V_103 ) ;
}
int F_85 ( struct V_3 * V_4 )
{
struct V_99 * V_104 ;
int V_63 ;
V_104 = F_70 ( sizeof( * V_104 ) , V_90 ) ;
if ( ! V_104 )
return - V_105 ;
V_104 -> V_4 = V_4 ;
F_86 ( & V_104 -> V_103 ) ;
V_63 = F_87 ( & V_106 ,
V_4 -> V_107 , V_4 -> V_59 , 3000 ,
V_90 ,
F_80 ,
V_104 ,
& V_104 -> V_108 ) ;
if ( V_63 < 0 ) {
F_88 ( L_14 ,
V_4 -> V_2 -> V_101 , V_63 ) ;
F_68 ( V_104 ) ;
return V_63 ;
}
F_89 ( & V_104 -> V_103 ) ;
F_68 ( V_104 ) ;
return V_63 ;
}
void F_55 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_70 * V_74 , * V_92 ;
F_90 ( V_109 ) ;
unsigned long V_6 ;
F_91 ( V_2 ) ;
F_92 ( & V_4 -> V_91 , V_6 ) ;
F_93 ( & V_4 -> V_84 , & V_109 ) ;
F_10 (path, &remove_list, list)
F_94 ( & V_74 -> V_71 , & V_4 -> V_73 ) ;
F_78 (path, tp, &remove_list, list) {
if ( V_74 -> V_110 )
F_95 ( V_74 -> V_111 , V_74 -> V_110 ) ;
F_96 ( & V_4 -> V_91 , V_6 ) ;
F_97 ( V_2 ) ;
F_89 ( & V_74 -> V_103 ) ;
F_63 ( V_2 , V_74 ) ;
F_91 ( V_2 ) ;
F_92 ( & V_4 -> V_91 , V_6 ) ;
}
F_96 ( & V_4 -> V_91 , V_6 ) ;
F_97 ( V_2 ) ;
}
static void F_98 ( int V_95 ,
struct V_112 * V_75 ,
void * V_113 )
{
struct V_70 * V_74 = V_113 ;
struct V_1 * V_2 = V_74 -> V_2 ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_114 * V_88 = NULL ;
struct V_114 * V_115 = NULL ;
struct V_116 * V_117 , * V_118 ;
struct V_119 V_120 ;
struct V_85 * V_86 ;
unsigned long V_6 ;
if ( ! V_95 )
F_3 ( V_4 , L_15 ,
F_79 ( V_75 -> V_93 ) , V_75 -> V_76 . V_77 ) ;
else
F_3 ( V_4 , L_16 ,
V_95 , V_74 -> V_75 . V_76 . V_77 ) ;
F_99 ( & V_120 ) ;
if ( ! V_95 ) {
struct V_121 V_122 ;
if ( ! F_100 ( V_4 -> V_107 , V_4 -> V_59 , V_75 , & V_122 ) )
V_88 = F_101 ( V_2 , V_4 -> V_123 , & V_122 ) ;
}
F_92 ( & V_4 -> V_91 , V_6 ) ;
if ( ! F_102 ( V_88 ) ) {
V_74 -> V_75 = * V_75 ;
V_115 = V_74 -> V_88 ;
V_74 -> V_88 = V_88 ;
F_3 ( V_4 , L_17 ,
V_88 , F_79 ( V_75 -> V_93 ) , V_75 -> V_124 ) ;
while ( ( V_86 = F_64 ( & V_74 -> V_87 ) ) )
F_103 ( & V_120 , V_86 ) ;
F_78 (neigh, tn, &path->neigh_list, list) {
if ( V_117 -> V_88 ) {
F_81 ( V_117 -> V_88 != V_115 ) ;
F_67 ( V_117 -> V_88 ) ;
}
F_104 ( & V_74 -> V_88 -> V_125 ) ;
V_117 -> V_88 = V_74 -> V_88 ;
if ( F_105 ( V_2 , V_117 -> V_126 ) ) {
if ( ! F_106 ( V_117 ) )
F_107 ( V_117 , F_108 ( V_2 ,
V_74 ,
V_117 ) ) ;
if ( ! F_106 ( V_117 ) ) {
F_109 ( V_117 ) ;
continue;
}
}
while ( ( V_86 = F_64 ( & V_117 -> V_87 ) ) )
F_103 ( & V_120 , V_86 ) ;
}
V_74 -> V_94 = 1 ;
}
V_74 -> V_110 = NULL ;
F_84 ( & V_74 -> V_103 ) ;
F_96 ( & V_4 -> V_91 , V_6 ) ;
if ( F_102 ( V_88 ) )
F_66 ( V_2 , V_74 -> V_75 . V_76 . V_77 ) ;
if ( V_115 )
F_67 ( V_115 ) ;
while ( ( V_86 = F_64 ( & V_120 ) ) ) {
V_86 -> V_2 = V_2 ;
if ( F_110 ( V_86 ) )
F_25 ( V_4 , L_18
L_19 ) ;
}
}
static struct V_70 * F_111 ( struct V_1 * V_2 , void * V_50 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_70 * V_74 ;
if ( ! V_4 -> V_127 )
return NULL ;
V_74 = F_112 ( sizeof *V_74 , V_128 ) ;
if ( ! V_74 )
return NULL ;
V_74 -> V_2 = V_2 ;
F_99 ( & V_74 -> V_87 ) ;
F_113 ( & V_74 -> V_129 ) ;
memcpy ( V_74 -> V_75 . V_76 . V_77 , V_50 , sizeof ( union V_49 ) ) ;
V_74 -> V_75 . V_130 = V_4 -> V_57 ;
V_74 -> V_75 . V_61 = F_114 ( V_4 -> V_61 ) ;
V_74 -> V_75 . V_131 = 1 ;
V_74 -> V_75 . V_132 = V_4 -> V_127 -> V_133 . V_132 ;
return V_74 ;
}
static int F_115 ( struct V_1 * V_2 ,
struct V_70 * V_74 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
F_3 ( V_4 , L_20 ,
V_74 -> V_75 . V_76 . V_77 ) ;
F_86 ( & V_74 -> V_103 ) ;
V_74 -> V_111 =
F_116 ( & V_106 , V_4 -> V_107 , V_4 -> V_59 ,
& V_74 -> V_75 ,
V_134 |
V_135 |
V_136 |
V_137 |
V_138 ,
1000 , V_128 ,
F_98 ,
V_74 , & V_74 -> V_110 ) ;
if ( V_74 -> V_111 < 0 ) {
F_25 ( V_4 , L_21 , V_74 -> V_111 ) ;
V_74 -> V_110 = NULL ;
F_84 ( & V_74 -> V_103 ) ;
return V_74 -> V_111 ;
}
return 0 ;
}
static void F_117 ( struct V_85 * V_86 , T_4 * V_126 ,
struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_70 * V_74 ;
struct V_116 * V_117 ;
unsigned long V_6 ;
F_92 ( & V_4 -> V_91 , V_6 ) ;
V_117 = F_118 ( V_126 , V_2 ) ;
if ( ! V_117 ) {
F_96 ( & V_4 -> V_91 , V_6 ) ;
++ V_2 -> V_139 . V_140 ;
F_119 ( V_86 ) ;
return;
}
V_74 = F_57 ( V_2 , V_126 + 4 ) ;
if ( ! V_74 ) {
V_74 = F_111 ( V_2 , V_126 + 4 ) ;
if ( ! V_74 )
goto V_141;
F_59 ( V_2 , V_74 ) ;
}
F_62 ( & V_117 -> V_83 , & V_74 -> V_129 ) ;
if ( V_74 -> V_88 ) {
F_104 ( & V_74 -> V_88 -> V_125 ) ;
V_117 -> V_88 = V_74 -> V_88 ;
if ( F_105 ( V_2 , V_117 -> V_126 ) ) {
if ( ! F_106 ( V_117 ) )
F_107 ( V_117 , F_108 ( V_2 , V_74 , V_117 ) ) ;
if ( ! F_106 ( V_117 ) ) {
F_109 ( V_117 ) ;
goto V_142;
}
if ( F_120 ( & V_117 -> V_87 ) < V_143 )
F_103 ( & V_117 -> V_87 , V_86 ) ;
else {
F_25 ( V_4 , L_22 ,
F_120 ( & V_117 -> V_87 ) ) ;
goto V_142;
}
} else {
F_96 ( & V_4 -> V_91 , V_6 ) ;
F_121 ( V_2 , V_86 , V_74 -> V_88 , F_122 ( V_126 ) ) ;
F_123 ( V_117 ) ;
return;
}
} else {
V_117 -> V_88 = NULL ;
if ( ! V_74 -> V_110 && F_115 ( V_2 , V_74 ) )
goto V_141;
if ( F_120 ( & V_117 -> V_87 ) < V_143 )
F_103 ( & V_117 -> V_87 , V_86 ) ;
else
goto V_142;
}
F_96 ( & V_4 -> V_91 , V_6 ) ;
F_123 ( V_117 ) ;
return;
V_141:
F_109 ( V_117 ) ;
V_142:
++ V_2 -> V_139 . V_140 ;
F_119 ( V_86 ) ;
F_96 ( & V_4 -> V_91 , V_6 ) ;
F_123 ( V_117 ) ;
}
static void F_124 ( struct V_85 * V_86 , struct V_1 * V_2 ,
struct V_144 * V_145 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_70 * V_74 ;
unsigned long V_6 ;
F_92 ( & V_4 -> V_91 , V_6 ) ;
V_74 = F_57 ( V_2 , V_145 -> V_146 + 4 ) ;
if ( ! V_74 || ! V_74 -> V_94 ) {
int V_147 = 0 ;
if ( ! V_74 ) {
V_74 = F_111 ( V_2 , V_145 -> V_146 + 4 ) ;
V_147 = 1 ;
}
if ( V_74 ) {
if ( F_120 ( & V_74 -> V_87 ) < V_143 ) {
F_103 ( & V_74 -> V_87 , V_86 ) ;
} else {
++ V_2 -> V_139 . V_140 ;
F_119 ( V_86 ) ;
}
if ( ! V_74 -> V_110 && F_115 ( V_2 , V_74 ) ) {
F_96 ( & V_4 -> V_91 , V_6 ) ;
if ( V_147 )
F_63 ( V_2 , V_74 ) ;
return;
} else
F_59 ( V_2 , V_74 ) ;
} else {
++ V_2 -> V_139 . V_140 ;
F_119 ( V_86 ) ;
}
F_96 ( & V_4 -> V_91 , V_6 ) ;
return;
}
if ( V_74 -> V_88 ) {
F_3 ( V_4 , L_23 ,
F_79 ( V_74 -> V_75 . V_93 ) ) ;
F_96 ( & V_4 -> V_91 , V_6 ) ;
F_121 ( V_2 , V_86 , V_74 -> V_88 , F_122 ( V_145 -> V_146 ) ) ;
return;
} else if ( ( V_74 -> V_110 || ! F_115 ( V_2 , V_74 ) ) &&
F_120 ( & V_74 -> V_87 ) < V_143 ) {
F_103 ( & V_74 -> V_87 , V_86 ) ;
} else {
++ V_2 -> V_139 . V_140 ;
F_119 ( V_86 ) ;
}
F_96 ( & V_4 -> V_91 , V_6 ) ;
}
static int F_125 ( struct V_85 * V_86 , struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_116 * V_117 ;
struct V_144 * V_145 = F_126 ( V_86 ) ;
struct V_148 * V_149 ;
unsigned long V_6 ;
V_149 = (struct V_148 * ) V_86 -> V_150 ;
if ( F_127 ( V_145 -> V_146 [ 4 ] == 0xff ) ) {
if ( ( V_149 -> V_151 != F_128 ( V_152 ) ) &&
( V_149 -> V_151 != F_128 ( V_153 ) ) &&
( V_149 -> V_151 != F_128 ( V_154 ) ) &&
( V_149 -> V_151 != F_128 ( V_155 ) ) &&
( V_149 -> V_151 != F_128 ( V_156 ) ) ) {
++ V_2 -> V_139 . V_140 ;
F_119 ( V_86 ) ;
return V_157 ;
}
V_145 -> V_146 [ 8 ] = ( V_4 -> V_61 >> 8 ) & 0xff ;
V_145 -> V_146 [ 9 ] = V_4 -> V_61 & 0xff ;
V_117 = F_129 ( V_2 , V_145 -> V_146 ) ;
if ( F_130 ( V_117 ) )
goto V_158;
F_131 ( V_2 , V_145 -> V_146 , V_86 ) ;
return V_157 ;
}
switch ( V_149 -> V_151 ) {
case F_128 ( V_152 ) :
case F_128 ( V_153 ) :
case F_128 ( V_156 ) :
V_117 = F_129 ( V_2 , V_145 -> V_146 ) ;
if ( F_127 ( ! V_117 ) ) {
F_117 ( V_86 , V_145 -> V_146 , V_2 ) ;
return V_157 ;
}
break;
case F_128 ( V_154 ) :
case F_128 ( V_155 ) :
F_124 ( V_86 , V_2 , V_145 ) ;
return V_157 ;
default:
++ V_2 -> V_139 . V_140 ;
F_119 ( V_86 ) ;
return V_157 ;
}
V_158:
if ( F_106 ( V_117 ) ) {
if ( F_132 ( V_117 ) ) {
F_133 ( V_2 , V_86 , F_106 ( V_117 ) ) ;
goto V_159;
}
} else if ( V_117 -> V_88 ) {
F_121 ( V_2 , V_86 , V_117 -> V_88 , F_122 ( V_145 -> V_146 ) ) ;
goto V_159;
}
if ( F_120 ( & V_117 -> V_87 ) < V_143 ) {
F_92 ( & V_4 -> V_91 , V_6 ) ;
F_103 ( & V_117 -> V_87 , V_86 ) ;
F_96 ( & V_4 -> V_91 , V_6 ) ;
} else {
++ V_2 -> V_139 . V_140 ;
F_119 ( V_86 ) ;
}
V_159:
F_123 ( V_117 ) ;
return V_157 ;
}
static void F_134 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
F_25 ( V_4 , L_24 ,
F_135 ( V_160 - F_136 ( V_2 ) ) ) ;
F_25 ( V_4 , L_25 ,
F_137 ( V_2 ) ,
V_4 -> V_161 , V_4 -> V_162 ) ;
}
static int F_138 ( struct V_85 * V_86 ,
struct V_1 * V_2 ,
unsigned short type ,
const void * V_126 , const void * V_163 , unsigned V_164 )
{
struct V_148 * V_149 ;
struct V_144 * V_145 = F_126 ( V_86 ) ;
V_149 = (struct V_148 * ) F_139 ( V_86 , sizeof *V_149 ) ;
V_149 -> V_151 = F_128 ( type ) ;
V_149 -> V_165 = 0 ;
memcpy ( V_145 -> V_146 , V_126 , V_166 ) ;
return sizeof *V_149 ;
}
static void F_140 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
if ( ! F_7 ( V_167 , & V_4 -> V_6 ) ) {
F_3 ( V_4 , L_26 ) ;
return;
}
F_141 ( V_4 -> V_168 , & V_4 -> V_169 ) ;
}
static int F_142 ( const struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
if ( ! F_7 ( V_11 , & V_4 -> V_6 ) )
return V_2 -> V_170 ;
return V_4 -> V_171 -> V_170 ;
}
static T_5 F_143 ( struct V_172 * V_173 , T_4 * V_126 )
{
T_5 * V_174 = ( T_5 * ) V_126 ;
T_5 V_175 ;
V_175 = F_144 ( V_174 [ 3 ] , V_174 [ 4 ] , V_176 & V_174 [ 0 ] , 0 ) ;
return V_175 & V_173 -> V_177 ;
}
struct V_116 * F_129 ( struct V_1 * V_2 , T_4 * V_126 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_178 * V_179 = & V_4 -> V_179 ;
struct V_172 * V_173 ;
struct V_116 * V_117 = NULL ;
T_5 V_180 ;
F_145 () ;
V_173 = F_146 ( V_179 -> V_173 ) ;
if ( ! V_173 )
goto V_181;
V_180 = F_143 ( V_173 , V_126 ) ;
for ( V_117 = F_146 ( V_173 -> V_182 [ V_180 ] ) ;
V_117 != NULL ;
V_117 = F_146 ( V_117 -> V_183 ) ) {
if ( memcmp ( V_126 , V_117 -> V_126 , V_166 ) == 0 ) {
if ( ! F_147 ( & V_117 -> V_184 ) ) {
V_117 = NULL ;
goto V_181;
}
if ( F_130 ( F_120 ( & V_117 -> V_87 ) < V_143 ) )
V_117 -> V_185 = V_160 ;
goto V_181;
}
}
V_181:
F_148 () ;
return V_117 ;
}
static void F_149 ( struct V_3 * V_4 )
{
struct V_178 * V_179 = & V_4 -> V_179 ;
struct V_172 * V_173 ;
unsigned long V_186 ;
unsigned long V_187 ;
unsigned long V_6 ;
int V_188 ;
F_90 ( V_109 ) ;
if ( F_7 ( V_189 , & V_4 -> V_6 ) )
return;
F_92 ( & V_4 -> V_91 , V_6 ) ;
V_173 = F_150 ( V_179 -> V_173 ,
F_151 ( & V_4 -> V_91 ) ) ;
if ( ! V_173 )
goto V_181;
V_187 = 2 * V_190 . V_191 ;
V_186 = V_160 - V_187 ;
if ( F_7 ( V_189 , & V_4 -> V_6 ) )
goto V_181;
for ( V_188 = 0 ; V_188 < V_173 -> V_192 ; V_188 ++ ) {
struct V_116 * V_117 ;
struct V_116 T_6 * * V_193 = & V_173 -> V_182 [ V_188 ] ;
while ( ( V_117 = F_150 ( * V_193 ,
F_151 ( & V_4 -> V_91 ) ) ) != NULL ) {
if ( F_152 ( V_186 , V_117 -> V_185 ) ) {
F_153 ( V_4 , V_117 -> V_126 + 4 , & V_109 ) ;
F_154 ( * V_193 ,
F_150 ( V_117 -> V_183 ,
F_151 ( & V_4 -> V_91 ) ) ) ;
F_155 ( & V_117 -> V_83 ) ;
F_156 ( & V_117 -> V_194 , V_195 ) ;
} else {
V_193 = & V_117 -> V_183 ;
}
}
}
V_181:
F_96 ( & V_4 -> V_91 , V_6 ) ;
F_157 ( & V_109 ) ;
}
static void F_158 ( struct V_196 * V_197 )
{
struct V_3 * V_4 =
F_159 ( V_197 , struct V_3 , V_198 . V_197 ) ;
F_149 ( V_4 ) ;
if ( ! F_7 ( V_189 , & V_4 -> V_6 ) )
F_160 ( V_4 -> V_168 , & V_4 -> V_198 ,
V_190 . V_191 ) ;
}
static struct V_116 * F_161 ( T_4 * V_126 ,
struct V_1 * V_2 )
{
struct V_116 * V_117 ;
V_117 = F_112 ( sizeof *V_117 , V_128 ) ;
if ( ! V_117 )
return NULL ;
V_117 -> V_2 = V_2 ;
memcpy ( & V_117 -> V_126 , V_126 , sizeof( V_117 -> V_126 ) ) ;
F_99 ( & V_117 -> V_87 ) ;
F_113 ( & V_117 -> V_83 ) ;
F_107 ( V_117 , NULL ) ;
F_162 ( & V_117 -> V_184 , 1 ) ;
return V_117 ;
}
struct V_116 * F_118 ( T_4 * V_126 ,
struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_178 * V_179 = & V_4 -> V_179 ;
struct V_172 * V_173 ;
struct V_116 * V_117 ;
T_5 V_180 ;
V_173 = F_150 ( V_179 -> V_173 ,
F_151 ( & V_4 -> V_91 ) ) ;
if ( ! V_173 ) {
V_117 = NULL ;
goto V_181;
}
V_180 = F_143 ( V_173 , V_126 ) ;
for ( V_117 = F_150 ( V_173 -> V_182 [ V_180 ] ,
F_151 ( & V_4 -> V_91 ) ) ;
V_117 != NULL ;
V_117 = F_150 ( V_117 -> V_183 ,
F_151 ( & V_4 -> V_91 ) ) ) {
if ( memcmp ( V_126 , V_117 -> V_126 , V_166 ) == 0 ) {
if ( ! F_147 ( & V_117 -> V_184 ) ) {
V_117 = NULL ;
break;
}
V_117 -> V_185 = V_160 ;
goto V_181;
}
}
V_117 = F_161 ( V_126 , V_2 ) ;
if ( ! V_117 )
goto V_181;
F_163 ( & V_117 -> V_184 ) ;
V_117 -> V_185 = V_160 ;
F_154 ( V_117 -> V_183 ,
F_150 ( V_173 -> V_182 [ V_180 ] ,
F_151 ( & V_4 -> V_91 ) ) ) ;
F_154 ( V_173 -> V_182 [ V_180 ] , V_117 ) ;
F_163 ( & V_179 -> V_199 ) ;
V_181:
return V_117 ;
}
void F_164 ( struct V_116 * V_117 )
{
struct V_1 * V_2 = V_117 -> V_2 ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_85 * V_86 ;
if ( V_117 -> V_88 )
F_67 ( V_117 -> V_88 ) ;
while ( ( V_86 = F_64 ( & V_117 -> V_87 ) ) ) {
++ V_2 -> V_139 . V_140 ;
F_119 ( V_86 ) ;
}
if ( F_106 ( V_117 ) )
F_165 ( F_106 ( V_117 ) ) ;
F_3 ( F_2 ( V_2 ) ,
L_27 ,
F_122 ( V_117 -> V_126 ) ,
V_117 -> V_126 + 4 ) ;
F_68 ( V_117 ) ;
if ( F_166 ( & V_4 -> V_179 . V_199 ) ) {
if ( F_7 ( V_200 , & V_4 -> V_6 ) )
F_84 ( & V_4 -> V_179 . V_201 ) ;
}
}
static void V_195 ( struct V_202 * V_203 )
{
struct V_116 * V_117 = F_159 ( V_203 , struct V_116 , V_194 ) ;
F_123 ( V_117 ) ;
}
void F_109 ( struct V_116 * V_117 )
{
struct V_1 * V_2 = V_117 -> V_2 ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_178 * V_179 = & V_4 -> V_179 ;
struct V_172 * V_173 ;
struct V_116 T_6 * * V_193 ;
struct V_116 * V_72 ;
T_5 V_180 ;
V_173 = F_150 ( V_179 -> V_173 ,
F_151 ( & V_4 -> V_91 ) ) ;
if ( ! V_173 )
return;
V_180 = F_143 ( V_173 , V_117 -> V_126 ) ;
V_193 = & V_173 -> V_182 [ V_180 ] ;
for ( V_72 = F_150 ( * V_193 ,
F_151 ( & V_4 -> V_91 ) ) ;
V_72 != NULL ;
V_72 = F_150 ( * V_193 ,
F_151 ( & V_4 -> V_91 ) ) ) {
if ( V_72 == V_117 ) {
F_154 ( * V_193 ,
F_150 ( V_117 -> V_183 ,
F_151 ( & V_4 -> V_91 ) ) ) ;
F_155 ( & V_117 -> V_83 ) ;
F_156 ( & V_117 -> V_194 , V_195 ) ;
return;
} else {
V_193 = & V_72 -> V_183 ;
}
}
}
static int F_167 ( struct V_3 * V_4 )
{
struct V_178 * V_179 = & V_4 -> V_179 ;
struct V_172 * V_173 ;
struct V_116 T_6 * * V_182 ;
T_5 V_192 ;
F_15 ( V_200 , & V_4 -> V_6 ) ;
V_179 -> V_173 = NULL ;
V_173 = F_112 ( sizeof( * V_173 ) , V_90 ) ;
if ( ! V_173 )
return - V_105 ;
F_5 ( V_189 , & V_4 -> V_6 ) ;
V_192 = F_168 ( V_190 . V_204 ) ;
V_182 = F_112 ( V_192 * sizeof( * V_182 ) , V_90 ) ;
if ( ! V_182 ) {
F_68 ( V_173 ) ;
return - V_105 ;
}
V_173 -> V_192 = V_192 ;
V_173 -> V_177 = ( V_192 - 1 ) ;
V_173 -> V_182 = V_182 ;
F_169 ( V_179 -> V_173 , V_173 ) ;
V_173 -> V_179 = V_179 ;
F_162 ( & V_179 -> V_199 , 0 ) ;
F_15 ( V_189 , & V_4 -> V_6 ) ;
F_160 ( V_4 -> V_168 , & V_4 -> V_198 ,
V_190 . V_191 ) ;
return 0 ;
}
static void F_170 ( struct V_202 * V_205 )
{
struct V_172 * V_173 = F_159 ( V_205 ,
struct V_172 ,
V_194 ) ;
struct V_116 T_6 * * V_182 = V_173 -> V_182 ;
struct V_178 * V_179 = V_173 -> V_179 ;
F_68 ( V_182 ) ;
F_68 ( V_173 ) ;
F_84 ( & V_179 -> V_206 ) ;
}
void F_66 ( struct V_1 * V_2 , T_4 * V_50 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_178 * V_179 = & V_4 -> V_179 ;
struct V_172 * V_173 ;
unsigned long V_6 ;
int V_188 ;
F_92 ( & V_4 -> V_91 , V_6 ) ;
V_173 = F_150 ( V_179 -> V_173 ,
F_151 ( & V_4 -> V_91 ) ) ;
if ( ! V_173 )
goto V_181;
for ( V_188 = 0 ; V_188 < V_173 -> V_192 ; V_188 ++ ) {
struct V_116 * V_117 ;
struct V_116 T_6 * * V_193 = & V_173 -> V_182 [ V_188 ] ;
while ( ( V_117 = F_150 ( * V_193 ,
F_151 ( & V_4 -> V_91 ) ) ) != NULL ) {
if ( ! memcmp ( V_50 , V_117 -> V_126 + 4 , sizeof ( union V_49 ) ) ) {
F_154 ( * V_193 ,
F_150 ( V_117 -> V_183 ,
F_151 ( & V_4 -> V_91 ) ) ) ;
F_155 ( & V_117 -> V_83 ) ;
F_156 ( & V_117 -> V_194 , V_195 ) ;
} else {
V_193 = & V_117 -> V_183 ;
}
}
}
V_181:
F_96 ( & V_4 -> V_91 , V_6 ) ;
}
static void F_171 ( struct V_3 * V_4 )
{
struct V_178 * V_179 = & V_4 -> V_179 ;
struct V_172 * V_173 ;
unsigned long V_6 ;
int V_188 , V_207 = 0 ;
F_86 ( & V_4 -> V_179 . V_201 ) ;
F_92 ( & V_4 -> V_91 , V_6 ) ;
V_173 = F_150 ( V_179 -> V_173 ,
F_151 ( & V_4 -> V_91 ) ) ;
if ( ! V_173 )
goto V_181;
V_207 = F_172 ( & V_4 -> V_179 . V_199 ) ;
if ( ! V_207 )
goto V_208;
for ( V_188 = 0 ; V_188 < V_173 -> V_192 ; V_188 ++ ) {
struct V_116 * V_117 ;
struct V_116 T_6 * * V_193 = & V_173 -> V_182 [ V_188 ] ;
while ( ( V_117 = F_150 ( * V_193 ,
F_151 ( & V_4 -> V_91 ) ) ) != NULL ) {
F_154 ( * V_193 ,
F_150 ( V_117 -> V_183 ,
F_151 ( & V_4 -> V_91 ) ) ) ;
F_155 ( & V_117 -> V_83 ) ;
F_156 ( & V_117 -> V_194 , V_195 ) ;
}
}
V_208:
F_154 ( V_179 -> V_173 , NULL ) ;
F_156 ( & V_173 -> V_194 , F_170 ) ;
V_181:
F_96 ( & V_4 -> V_91 , V_6 ) ;
if ( V_207 )
F_89 ( & V_4 -> V_179 . V_201 ) ;
}
static void F_173 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_209 ;
F_3 ( V_4 , L_28 ) ;
F_86 ( & V_4 -> V_179 . V_206 ) ;
F_5 ( V_200 , & V_4 -> V_6 ) ;
V_209 = F_174 ( V_189 , & V_4 -> V_6 ) ;
if ( ! V_209 )
F_175 ( & V_4 -> V_198 ) ;
F_171 ( V_4 ) ;
F_89 ( & V_4 -> V_179 . V_206 ) ;
}
int F_176 ( struct V_1 * V_2 , struct V_60 * V_107 , int V_59 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
V_4 -> V_210 = F_112 ( V_211 * sizeof * V_4 -> V_210 ,
V_90 ) ;
if ( ! V_4 -> V_210 ) {
F_177 ( V_212 L_29 ,
V_107 -> V_101 , V_211 ) ;
goto V_48;
}
V_4 -> V_213 = F_178 ( V_214 * sizeof * V_4 -> V_213 ) ;
if ( ! V_4 -> V_213 ) {
F_177 ( V_212 L_30 ,
V_107 -> V_101 , V_214 ) ;
goto V_215;
}
if ( F_179 ( V_2 , V_107 , V_59 ) )
goto V_216;
if ( F_167 ( V_4 ) < 0 )
goto V_217;
return 0 ;
V_217:
F_180 ( V_2 ) ;
V_216:
F_181 ( V_4 -> V_213 ) ;
V_215:
F_68 ( V_4 -> V_210 ) ;
V_48:
return - V_105 ;
}
void F_20 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) , * V_12 , * V_218 ;
F_90 ( V_205 ) ;
F_182 () ;
F_183 ( V_2 ) ;
F_78 (cpriv, tcpriv, &priv->child_intfs, list) {
F_5 ( V_189 , & V_12 -> V_6 ) ;
F_175 ( & V_12 -> V_198 ) ;
F_184 ( V_12 -> V_2 , & V_205 ) ;
}
F_185 ( & V_205 ) ;
F_173 ( V_2 ) ;
F_180 ( V_2 ) ;
F_68 ( V_4 -> V_210 ) ;
F_181 ( V_4 -> V_213 ) ;
V_4 -> V_210 = NULL ;
V_4 -> V_213 = NULL ;
}
static int F_186 ( struct V_1 * V_2 , int V_219 , int V_220 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
return F_187 ( V_4 -> V_107 , V_219 , V_4 -> V_59 , V_220 ) ;
}
static int F_188 ( struct V_1 * V_2 , int V_219 ,
struct V_221 * V_222 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_223 ;
V_223 = F_189 ( V_4 -> V_107 , V_219 , V_4 -> V_59 , V_222 ) ;
if ( V_223 )
return V_223 ;
V_222 -> V_219 = V_219 ;
return 0 ;
}
static int F_190 ( struct V_1 * V_2 , int V_219 , T_7 V_224 , int type )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
if ( type != V_225 && type != V_226 )
return - V_15 ;
return F_191 ( V_4 -> V_107 , V_219 , V_4 -> V_59 , V_224 , type ) ;
}
static int F_192 ( struct V_1 * V_2 , int V_219 ,
struct V_227 * V_228 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
return F_193 ( V_4 -> V_107 , V_219 , V_4 -> V_59 , V_228 ) ;
}
void F_194 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
if ( V_4 -> V_229 & V_230 )
V_2 -> V_231 = & V_232 ;
else
V_2 -> V_231 = & V_233 ;
V_2 -> V_234 = & V_235 ;
F_195 ( V_2 ) ;
F_196 ( V_2 , & V_4 -> V_236 , V_237 , V_238 ) ;
V_2 -> V_239 = V_240 ;
V_2 -> V_6 |= V_241 | V_242 ;
V_2 -> V_243 = V_244 ;
V_2 -> V_245 = V_166 ;
V_2 -> type = V_246 ;
V_2 -> V_247 = V_214 * 2 ;
V_2 -> V_16 = ( V_248 |
V_249 ) ;
F_197 ( V_2 ) ;
memcpy ( V_2 -> V_127 , V_250 , V_166 ) ;
V_4 -> V_2 = V_2 ;
F_198 ( & V_4 -> V_91 ) ;
F_199 ( & V_4 -> V_13 ) ;
F_113 ( & V_4 -> V_84 ) ;
F_113 ( & V_4 -> V_251 ) ;
F_113 ( & V_4 -> V_252 ) ;
F_113 ( & V_4 -> V_253 ) ;
F_200 ( & V_4 -> V_254 , V_255 ) ;
F_201 ( & V_4 -> V_256 , V_257 ) ;
F_201 ( & V_4 -> V_258 , V_259 ) ;
F_201 ( & V_4 -> V_260 , V_261 ) ;
F_201 ( & V_4 -> V_262 , V_263 ) ;
F_201 ( & V_4 -> V_169 , V_264 ) ;
F_200 ( & V_4 -> V_265 , V_266 ) ;
F_200 ( & V_4 -> V_198 , F_158 ) ;
}
struct V_3 * F_202 ( const char * V_101 )
{
struct V_1 * V_2 ;
V_2 = F_203 ( ( int ) sizeof( struct V_3 ) , V_101 ,
V_267 , F_194 ) ;
if ( ! V_2 )
return NULL ;
return F_2 ( V_2 ) ;
}
static T_8 F_204 ( struct V_268 * V_2 ,
struct V_269 * V_270 , char * V_64 )
{
struct V_3 * V_4 = F_2 ( F_205 ( V_2 ) ) ;
return sprintf ( V_64 , L_31 , V_4 -> V_61 ) ;
}
static T_8 F_206 ( struct V_268 * V_2 ,
struct V_269 * V_270 , char * V_64 )
{
struct V_3 * V_4 = F_2 ( F_205 ( V_2 ) ) ;
return sprintf ( V_64 , L_32 , F_7 ( V_271 , & V_4 -> V_6 ) ) ;
}
void F_207 ( struct V_1 * V_272 , int V_273 )
{
struct V_3 * V_4 = F_2 ( V_272 ) ;
if ( V_273 > 0 ) {
F_5 ( V_271 , & V_4 -> V_6 ) ;
F_25 ( V_4 , L_33
L_34 ) ;
} else
F_15 ( V_271 , & V_4 -> V_6 ) ;
}
static T_8 F_208 ( struct V_268 * V_2 ,
struct V_269 * V_270 ,
const char * V_64 , T_9 V_274 )
{
unsigned long V_273 = F_209 ( V_64 , NULL , 0 ) ;
F_207 ( F_205 ( V_2 ) , V_273 ) ;
return V_274 ;
}
int F_210 ( struct V_1 * V_2 )
{
return F_211 ( & V_2 -> V_2 , & V_275 ) ;
}
static void F_212 ( struct V_3 * V_4 , union V_49 * V_50 )
{
struct V_3 * V_54 ;
struct V_1 * V_276 = V_4 -> V_2 ;
F_213 ( V_276 ) ;
memcpy ( & V_4 -> V_57 . V_277 . V_278 ,
& V_50 -> V_277 . V_278 ,
sizeof( V_50 -> V_277 . V_278 ) ) ;
memcpy ( V_276 -> V_65 + 4 , & V_4 -> V_57 , sizeof( V_4 -> V_57 ) ) ;
F_15 ( V_279 , & V_4 -> V_6 ) ;
F_214 ( V_276 ) ;
if ( ! F_7 ( V_11 , & V_4 -> V_6 ) ) {
F_9 ( & V_4 -> V_13 ) ;
F_10 (child_priv, &priv->child_intfs, list)
F_212 ( V_54 , V_50 ) ;
F_12 ( & V_4 -> V_13 ) ;
}
}
static int F_215 ( struct V_1 * V_2 ,
struct V_280 * V_281 )
{
union V_49 * V_50 = (union V_49 * ) ( V_281 -> V_282 + 4 ) ;
int V_63 = 0 ;
F_213 ( V_2 ) ;
if ( memcmp ( V_2 -> V_65 , V_281 -> V_282 ,
4 + sizeof( V_50 -> V_277 . V_283 ) ) ||
V_50 -> V_277 . V_278 == 0 )
V_63 = - V_15 ;
F_214 ( V_2 ) ;
return V_63 ;
}
static int F_216 ( struct V_1 * V_2 , void * V_26 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_280 * V_281 = V_26 ;
int V_63 ;
if ( ! ( V_2 -> V_284 & V_285 ) && F_217 ( V_2 ) )
return - V_286 ;
V_63 = F_215 ( V_2 , V_281 ) ;
if ( V_63 )
return V_63 ;
F_212 ( V_4 , (union V_49 * ) ( V_281 -> V_282 + 4 ) ) ;
F_141 ( V_287 , & V_4 -> V_258 ) ;
return 0 ;
}
static T_8 F_218 ( struct V_268 * V_2 ,
struct V_269 * V_270 ,
const char * V_64 , T_9 V_274 )
{
int V_61 ;
int V_63 ;
if ( sscanf ( V_64 , L_35 , & V_61 ) != 1 )
return - V_15 ;
if ( V_61 <= 0 || V_61 > 0xffff || V_61 == 0x8000 )
return - V_15 ;
V_61 |= 0x8000 ;
V_63 = F_219 ( F_205 ( V_2 ) , V_61 ) ;
return V_63 ? V_63 : V_274 ;
}
static T_8 F_220 ( struct V_268 * V_2 ,
struct V_269 * V_270 ,
const char * V_64 , T_9 V_274 )
{
int V_61 ;
int V_63 ;
if ( sscanf ( V_64 , L_35 , & V_61 ) != 1 )
return - V_15 ;
if ( V_61 < 0 || V_61 > 0xffff )
return - V_15 ;
V_63 = F_221 ( F_205 ( V_2 ) , V_61 ) ;
return V_63 ? V_63 : V_274 ;
}
int F_222 ( struct V_1 * V_2 )
{
return F_211 ( & V_2 -> V_2 , & V_288 ) ;
}
int F_223 ( struct V_3 * V_4 , struct V_60 * V_289 )
{
V_4 -> V_229 = V_289 -> V_290 . V_291 ;
if ( V_4 -> V_229 & V_292 ) {
V_4 -> V_2 -> V_293 = V_294 |
V_18 | V_295 ;
if ( V_4 -> V_229 & V_296 )
V_4 -> V_2 -> V_293 |= V_19 ;
V_4 -> V_2 -> V_16 |= V_4 -> V_2 -> V_293 ;
}
return 0 ;
}
static struct V_1 * F_224 ( const char * V_297 ,
struct V_60 * V_289 , T_4 V_59 )
{
struct V_3 * V_4 ;
struct V_298 V_270 ;
int V_45 = - V_105 ;
V_4 = F_202 ( V_297 ) ;
if ( ! V_4 )
goto V_299;
F_225 ( V_4 -> V_2 , V_289 -> V_300 ) ;
V_4 -> V_2 -> V_301 = V_59 - 1 ;
V_45 = F_226 ( V_289 , V_59 , & V_270 ) ;
if ( ! V_45 )
V_4 -> V_23 = F_227 ( V_270 . V_302 ) ;
else {
F_177 ( V_212 L_36 ,
V_289 -> V_101 , V_59 ) ;
goto V_303;
}
V_4 -> V_2 -> V_22 = F_26 ( V_4 -> V_23 ) ;
V_4 -> V_21 = V_4 -> V_24 = V_4 -> V_2 -> V_22 ;
V_4 -> V_2 -> V_304 = sizeof( struct V_116 ) ;
V_45 = F_228 ( V_289 , V_59 , 0 , & V_4 -> V_61 ) ;
if ( V_45 ) {
F_177 ( V_212 L_37 ,
V_289 -> V_101 , V_59 , V_45 ) ;
goto V_303;
}
V_45 = F_223 ( V_4 , V_289 ) ;
if ( V_45 )
goto V_303;
V_4 -> V_61 |= 0x8000 ;
V_4 -> V_2 -> V_127 [ 8 ] = V_4 -> V_61 >> 8 ;
V_4 -> V_2 -> V_127 [ 9 ] = V_4 -> V_61 & 0xff ;
V_45 = F_229 ( V_289 , V_59 , 0 , & V_4 -> V_57 , NULL ) ;
if ( V_45 ) {
F_177 ( V_212 L_38 ,
V_289 -> V_101 , V_59 , V_45 ) ;
goto V_303;
} else
memcpy ( V_4 -> V_2 -> V_65 + 4 , V_4 -> V_57 . V_77 , sizeof ( union V_49 ) ) ;
F_5 ( V_279 , & V_4 -> V_6 ) ;
V_45 = F_176 ( V_4 -> V_2 , V_289 , V_59 ) ;
if ( V_45 < 0 ) {
F_177 ( V_212 L_39 ,
V_289 -> V_101 , V_59 , V_45 ) ;
goto V_303;
}
F_230 ( & V_4 -> V_305 ,
V_4 -> V_107 , V_306 ) ;
V_45 = F_231 ( & V_4 -> V_305 ) ;
if ( V_45 < 0 ) {
F_177 ( V_212 L_40
L_41 ,
V_289 -> V_101 , V_59 , V_45 ) ;
goto V_307;
}
V_45 = F_232 ( V_4 -> V_2 ) ;
if ( V_45 ) {
F_177 ( V_212 L_42 ,
V_289 -> V_101 , V_59 , V_45 ) ;
goto V_308;
}
F_233 ( V_4 -> V_2 ) ;
if ( F_234 ( V_4 -> V_2 ) )
goto V_309;
if ( F_222 ( V_4 -> V_2 ) )
goto V_309;
if ( F_210 ( V_4 -> V_2 ) )
goto V_309;
if ( F_211 ( & V_4 -> V_2 -> V_2 , & V_310 ) )
goto V_309;
if ( F_211 ( & V_4 -> V_2 -> V_2 , & V_311 ) )
goto V_309;
return V_4 -> V_2 ;
V_309:
F_183 ( V_4 -> V_2 ) ;
F_235 ( V_4 -> V_2 ) ;
V_308:
F_236 ( & V_4 -> V_305 ) ;
F_237 ( V_287 ) ;
F_5 ( V_189 , & V_4 -> V_6 ) ;
F_175 ( & V_4 -> V_198 ) ;
F_237 ( V_4 -> V_168 ) ;
V_307:
F_20 ( V_4 -> V_2 ) ;
V_303:
F_238 ( V_4 -> V_2 ) ;
V_299:
return F_239 ( V_45 ) ;
}
static void F_240 ( struct V_60 * V_268 )
{
struct V_46 * V_58 ;
struct V_1 * V_2 ;
struct V_3 * V_4 ;
int V_312 ;
int V_274 = 0 ;
V_58 = F_70 ( sizeof *V_58 , V_90 ) ;
if ( ! V_58 )
return;
F_113 ( V_58 ) ;
for ( V_312 = F_241 ( V_268 ) ; V_312 <= F_242 ( V_268 ) ; ++ V_312 ) {
if ( ! F_47 ( V_268 , V_312 ) )
continue;
V_2 = F_224 ( L_43 , V_268 , V_312 ) ;
if ( ! F_243 ( V_2 ) ) {
V_4 = F_2 ( V_2 ) ;
F_62 ( & V_4 -> V_83 , V_58 ) ;
V_274 ++ ;
}
}
if ( ! V_274 ) {
F_68 ( V_58 ) ;
return;
}
F_244 ( V_268 , & V_313 , V_58 ) ;
}
static void F_245 ( struct V_60 * V_268 , void * V_62 )
{
struct V_3 * V_4 , * V_314 ;
struct V_46 * V_58 = V_62 ;
if ( ! V_58 )
return;
F_78 (priv, tmp, dev_list, list) {
F_236 ( & V_4 -> V_305 ) ;
F_237 ( V_287 ) ;
F_5 ( V_315 , & V_4 -> V_6 ) ;
F_56 () ;
F_11 ( V_4 -> V_2 , V_4 -> V_2 -> V_6 & ~ V_14 ) ;
F_54 () ;
F_5 ( V_189 , & V_4 -> V_6 ) ;
F_175 ( & V_4 -> V_198 ) ;
F_237 ( V_4 -> V_168 ) ;
F_235 ( V_4 -> V_2 ) ;
F_238 ( V_4 -> V_2 ) ;
}
F_68 ( V_58 ) ;
}
static int T_10 F_246 ( void )
{
int V_63 ;
V_211 = F_168 ( V_211 ) ;
V_211 = F_27 ( V_211 , V_316 ) ;
V_211 = F_247 ( V_211 , V_317 ) ;
V_214 = F_168 ( V_214 ) ;
V_214 = F_27 ( V_214 , V_316 ) ;
V_214 = F_248 ( V_214 , 2 * V_318 , V_317 ) ;
#ifdef F_249
V_319 = F_27 ( V_319 , V_320 ) ;
#endif
F_250 ( V_321 > V_322 ) ;
V_63 = F_251 () ;
if ( V_63 )
return V_63 ;
V_287 = F_252 ( L_44 ) ;
if ( ! V_287 ) {
V_63 = - V_105 ;
goto V_323;
}
F_253 ( & V_106 ) ;
V_63 = F_254 ( & V_313 ) ;
if ( V_63 )
goto V_324;
V_63 = F_255 () ;
if ( V_63 )
goto V_325;
return 0 ;
V_325:
F_256 ( & V_313 ) ;
V_324:
F_257 ( & V_106 ) ;
F_258 ( V_287 ) ;
V_323:
F_259 () ;
return V_63 ;
}
static void T_11 F_260 ( void )
{
F_261 () ;
F_256 ( & V_313 ) ;
F_257 ( & V_106 ) ;
F_259 () ;
F_258 ( V_287 ) ;
}
