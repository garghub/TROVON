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
static int F_40 ( struct V_1 * V_44 , void * V_45 )
{
struct V_46 * V_47 = V_45 ;
int V_48 = 0 ;
if ( F_28 ( V_47 -> V_26 , V_44 ) ) {
F_38 ( V_44 ) ;
V_47 -> V_49 = V_44 ;
V_48 = 1 ;
}
return V_48 ;
}
static struct V_1 * F_41 (
const struct V_25 * V_26 , struct V_1 * V_2 )
{
struct V_46 V_47 = {
. V_26 = V_26 ,
} ;
F_36 () ;
if ( F_28 ( V_26 , V_2 ) ) {
F_38 ( V_2 ) ;
V_47 . V_49 = V_2 ;
goto V_50;
}
F_42 ( V_2 , F_40 , & V_47 ) ;
V_50:
F_39 () ;
return V_47 . V_49 ;
}
static int F_43 ( struct V_3 * V_4 ,
const union V_51 * V_52 ,
T_3 V_53 ,
const struct V_25 * V_26 ,
int V_54 ,
struct V_1 * * V_55 )
{
struct V_3 * V_56 ;
struct V_1 * V_57 = NULL ;
int V_58 = 0 ;
if ( V_4 -> V_53 == V_53 &&
( ! V_52 || ! memcmp ( V_52 , & V_4 -> V_59 , sizeof( * V_52 ) ) ) ) {
if ( ! V_26 ) {
V_57 = F_35 ( V_4 -> V_2 ) ;
} else {
V_57 = F_41 ( V_26 , V_4 -> V_2 ) ;
}
if ( V_57 ) {
if ( ! * V_55 )
* V_55 = V_57 ;
else
F_44 ( V_57 ) ;
++ V_58 ;
}
}
F_45 ( & V_4 -> V_13 , V_54 ) ;
F_10 (child_priv, &priv->child_intfs, list) {
V_58 += F_43 ( V_56 , V_52 ,
V_53 , V_26 ,
V_54 + 1 ,
V_55 ) ;
if ( V_58 > 1 )
break;
}
F_12 ( & V_4 -> V_13 ) ;
return V_58 ;
}
static int F_46 ( struct V_60 * V_61 , T_4 V_62 ,
T_3 V_53 ,
const union V_51 * V_52 ,
const struct V_25 * V_26 ,
struct V_1 * * V_57 )
{
struct V_3 * V_4 ;
int V_58 = 0 ;
* V_57 = NULL ;
F_10 (priv, dev_list, list) {
if ( V_4 -> V_62 != V_62 )
continue;
V_58 += F_43 ( V_4 , V_52 , V_53 ,
V_26 , 0 , V_57 ) ;
if ( V_58 > 1 )
break;
}
return V_58 ;
}
static struct V_1 * F_47 (
struct V_63 * V_2 , T_4 V_62 , T_3 V_64 ,
const union V_51 * V_52 , const struct V_25 * V_26 ,
void * V_65 )
{
struct V_1 * V_57 ;
struct V_60 * V_61 = V_65 ;
T_3 V_53 ;
int V_58 ;
int V_48 ;
if ( ! F_48 ( V_2 , V_62 ) )
return NULL ;
V_48 = F_49 ( V_2 , V_62 , V_64 , & V_53 ) ;
if ( V_48 )
return NULL ;
if ( ! V_61 )
return NULL ;
V_58 = F_46 ( V_61 , V_62 , V_53 ,
V_52 , NULL , & V_57 ) ;
switch ( V_58 ) {
case 0 :
return NULL ;
case 1 :
return V_57 ;
}
F_44 ( V_57 ) ;
V_58 = F_46 ( V_61 , V_62 , V_53 ,
V_52 , V_26 , & V_57 ) ;
switch ( V_58 ) {
case 0 :
return NULL ;
default:
F_50 ( & V_2 -> V_2 ,
L_4 ) ;
case 1 :
return V_57 ;
}
}
int F_51 ( struct V_1 * V_2 , const char * V_66 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
if ( F_52 ( V_2 -> V_67 ) && ! strcmp ( V_66 , L_5 ) ) {
F_5 ( V_17 , & V_4 -> V_6 ) ;
F_25 ( V_4 , L_6
L_7 ) ;
F_53 ( V_2 ) ;
F_54 ( V_2 , F_24 ( V_2 ) ) ;
F_55 () ;
V_4 -> V_68 . V_69 . V_70 &= ~ V_71 ;
F_56 ( V_2 ) ;
F_57 () ;
return 0 ;
}
if ( ! strcmp ( V_66 , L_8 ) ) {
F_15 ( V_17 , & V_4 -> V_6 ) ;
F_53 ( V_2 ) ;
F_54 ( V_2 , F_27 ( V_4 -> V_21 , V_2 -> V_22 ) ) ;
F_55 () ;
F_56 ( V_2 ) ;
F_57 () ;
return 0 ;
}
return - V_15 ;
}
struct V_72 * F_58 ( struct V_1 * V_2 , void * V_52 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_73 * V_74 = V_4 -> V_75 . V_73 ;
struct V_72 * V_76 ;
int V_48 ;
while ( V_74 ) {
V_76 = F_59 ( V_74 , struct V_72 , V_73 ) ;
V_48 = memcmp ( V_52 , V_76 -> V_77 . V_78 . V_79 ,
sizeof ( union V_51 ) ) ;
if ( V_48 < 0 )
V_74 = V_74 -> V_80 ;
else if ( V_48 > 0 )
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
int V_48 ;
while ( * V_74 ) {
V_82 = * V_74 ;
V_83 = F_59 ( V_82 , struct V_72 , V_73 ) ;
V_48 = memcmp ( V_76 -> V_77 . V_78 . V_79 , V_83 -> V_77 . V_78 . V_79 ,
sizeof ( union V_51 ) ) ;
if ( V_48 < 0 )
V_74 = & V_82 -> V_80 ;
else if ( V_48 > 0 )
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
F_3 ( F_2 ( V_2 ) , L_9 ) ;
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
int V_48 = 1 ;
F_73 ( & V_4 -> V_94 ) ;
V_74 = F_74 ( & V_4 -> V_75 ) ;
while ( V_74 ) {
V_76 = F_59 ( V_74 , struct V_72 , V_73 ) ;
if ( memcmp ( V_92 -> V_76 . V_77 . V_78 . V_79 , V_76 -> V_77 . V_78 . V_79 ,
sizeof ( union V_51 ) ) < 0 ) {
V_92 -> V_76 = * V_76 ;
V_48 = 0 ;
break;
}
V_74 = F_75 ( V_74 ) ;
}
F_76 ( & V_4 -> V_94 ) ;
return V_48 ;
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
F_3 ( V_4 , L_10 ,
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
F_83 ( L_11 ,
V_4 -> V_2 -> V_104 , V_98 ) ;
V_4 -> V_7 = false ;
goto V_50;
}
if ( F_84 ( V_100 ) &
V_105 ) {
F_83 ( L_12 ,
V_4 -> V_2 -> V_104 ) ;
V_4 -> V_7 = true ;
} else {
F_83 ( L_13 ,
V_4 -> V_2 -> V_104 ) ;
V_4 -> V_7 = false ;
}
V_50:
F_85 ( & V_103 -> V_106 ) ;
}
int F_86 ( struct V_3 * V_4 )
{
struct V_102 * V_107 ;
int V_48 ;
V_107 = F_71 ( sizeof( * V_107 ) , V_93 ) ;
if ( ! V_107 )
return - V_108 ;
V_107 -> V_4 = V_4 ;
F_87 ( & V_107 -> V_106 ) ;
V_48 = F_88 ( & V_109 ,
V_4 -> V_110 , V_4 -> V_62 , 3000 ,
V_93 ,
F_81 ,
V_107 ,
& V_107 -> V_111 ) ;
if ( V_48 < 0 ) {
F_89 ( L_14 ,
V_4 -> V_2 -> V_104 , V_48 ) ;
F_69 ( V_107 ) ;
return V_48 ;
}
F_90 ( & V_107 -> V_106 ) ;
F_69 ( V_107 ) ;
return V_48 ;
}
void F_56 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_72 * V_76 , * V_95 ;
F_91 ( V_112 ) ;
unsigned long V_6 ;
F_92 ( V_2 ) ;
F_93 ( & V_4 -> V_94 , V_6 ) ;
F_94 ( & V_4 -> V_86 , & V_112 ) ;
F_10 (path, &remove_list, list)
F_95 ( & V_76 -> V_73 , & V_4 -> V_75 ) ;
F_79 (path, tp, &remove_list, list) {
if ( V_76 -> V_113 )
F_96 ( V_76 -> V_114 , V_76 -> V_113 ) ;
F_97 ( & V_4 -> V_94 , V_6 ) ;
F_98 ( V_2 ) ;
F_90 ( & V_76 -> V_106 ) ;
F_64 ( V_2 , V_76 ) ;
F_92 ( V_2 ) ;
F_93 ( & V_4 -> V_94 , V_6 ) ;
}
F_97 ( & V_4 -> V_94 , V_6 ) ;
F_98 ( V_2 ) ;
}
static void F_99 ( int V_98 ,
struct V_115 * V_77 ,
void * V_116 )
{
struct V_72 * V_76 = V_116 ;
struct V_1 * V_2 = V_76 -> V_2 ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_117 * V_90 = NULL ;
struct V_117 * V_118 = NULL ;
struct V_119 * V_120 , * V_121 ;
struct V_122 V_123 ;
struct V_87 * V_88 ;
unsigned long V_6 ;
if ( ! V_98 )
F_3 ( V_4 , L_15 ,
F_80 ( V_77 -> V_96 ) , V_77 -> V_78 . V_79 ) ;
else
F_3 ( V_4 , L_16 ,
V_98 , V_76 -> V_77 . V_78 . V_79 ) ;
F_100 ( & V_123 ) ;
if ( ! V_98 ) {
struct V_124 V_125 ;
if ( ! F_101 ( V_4 -> V_110 , V_4 -> V_62 , V_77 , & V_125 ) )
V_90 = F_102 ( V_2 , V_4 -> V_126 , & V_125 ) ;
}
F_93 ( & V_4 -> V_94 , V_6 ) ;
if ( ! F_103 ( V_90 ) ) {
V_76 -> V_77 = * V_77 ;
V_118 = V_76 -> V_90 ;
V_76 -> V_90 = V_90 ;
F_3 ( V_4 , L_17 ,
V_90 , F_80 ( V_77 -> V_96 ) , V_77 -> V_127 ) ;
while ( ( V_88 = F_65 ( & V_76 -> V_89 ) ) )
F_104 ( & V_123 , V_88 ) ;
F_79 (neigh, tn, &path->neigh_list, list) {
if ( V_120 -> V_90 ) {
F_82 ( V_120 -> V_90 != V_118 ) ;
F_68 ( V_120 -> V_90 ) ;
}
F_105 ( & V_76 -> V_90 -> V_128 ) ;
V_120 -> V_90 = V_76 -> V_90 ;
if ( F_106 ( V_2 , V_120 -> V_129 ) ) {
if ( ! F_107 ( V_120 ) )
F_108 ( V_120 , F_109 ( V_2 ,
V_76 ,
V_120 ) ) ;
if ( ! F_107 ( V_120 ) ) {
F_110 ( V_120 ) ;
continue;
}
}
while ( ( V_88 = F_65 ( & V_120 -> V_89 ) ) )
F_104 ( & V_123 , V_88 ) ;
}
V_76 -> V_97 = 1 ;
}
V_76 -> V_113 = NULL ;
F_85 ( & V_76 -> V_106 ) ;
F_97 ( & V_4 -> V_94 , V_6 ) ;
if ( F_103 ( V_90 ) )
F_67 ( V_2 , V_76 -> V_77 . V_78 . V_79 ) ;
if ( V_118 )
F_68 ( V_118 ) ;
while ( ( V_88 = F_65 ( & V_123 ) ) ) {
V_88 -> V_2 = V_2 ;
if ( F_111 ( V_88 ) )
F_25 ( V_4 , L_18
L_19 ) ;
}
}
static struct V_72 * F_112 ( struct V_1 * V_2 , void * V_52 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_72 * V_76 ;
if ( ! V_4 -> V_130 )
return NULL ;
V_76 = F_113 ( sizeof *V_76 , V_131 ) ;
if ( ! V_76 )
return NULL ;
V_76 -> V_2 = V_2 ;
F_100 ( & V_76 -> V_89 ) ;
F_114 ( & V_76 -> V_132 ) ;
memcpy ( V_76 -> V_77 . V_78 . V_79 , V_52 , sizeof ( union V_51 ) ) ;
V_76 -> V_77 . V_133 = V_4 -> V_59 ;
V_76 -> V_77 . V_64 = F_115 ( V_4 -> V_64 ) ;
V_76 -> V_77 . V_134 = 1 ;
V_76 -> V_77 . V_135 = V_4 -> V_130 -> V_136 . V_135 ;
return V_76 ;
}
static int F_116 ( struct V_1 * V_2 ,
struct V_72 * V_76 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
F_3 ( V_4 , L_20 ,
V_76 -> V_77 . V_78 . V_79 ) ;
F_87 ( & V_76 -> V_106 ) ;
V_76 -> V_114 =
F_117 ( & V_109 , V_4 -> V_110 , V_4 -> V_62 ,
& V_76 -> V_77 ,
V_137 |
V_138 |
V_139 |
V_140 |
V_141 ,
1000 , V_131 ,
F_99 ,
V_76 , & V_76 -> V_113 ) ;
if ( V_76 -> V_114 < 0 ) {
F_25 ( V_4 , L_21 , V_76 -> V_114 ) ;
V_76 -> V_113 = NULL ;
F_85 ( & V_76 -> V_106 ) ;
return V_76 -> V_114 ;
}
return 0 ;
}
static void F_118 ( struct V_87 * V_88 , T_4 * V_129 ,
struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_72 * V_76 ;
struct V_119 * V_120 ;
unsigned long V_6 ;
F_93 ( & V_4 -> V_94 , V_6 ) ;
V_120 = F_119 ( V_129 , V_2 ) ;
if ( ! V_120 ) {
F_97 ( & V_4 -> V_94 , V_6 ) ;
++ V_2 -> V_142 . V_143 ;
F_120 ( V_88 ) ;
return;
}
V_76 = F_58 ( V_2 , V_129 + 4 ) ;
if ( ! V_76 ) {
V_76 = F_112 ( V_2 , V_129 + 4 ) ;
if ( ! V_76 )
goto V_144;
F_60 ( V_2 , V_76 ) ;
}
F_63 ( & V_120 -> V_85 , & V_76 -> V_132 ) ;
if ( V_76 -> V_90 ) {
F_105 ( & V_76 -> V_90 -> V_128 ) ;
V_120 -> V_90 = V_76 -> V_90 ;
if ( F_106 ( V_2 , V_120 -> V_129 ) ) {
if ( ! F_107 ( V_120 ) )
F_108 ( V_120 , F_109 ( V_2 , V_76 , V_120 ) ) ;
if ( ! F_107 ( V_120 ) ) {
F_110 ( V_120 ) ;
goto V_145;
}
if ( F_121 ( & V_120 -> V_89 ) <
V_146 ) {
F_122 ( V_88 , V_147 ) ;
F_104 ( & V_120 -> V_89 , V_88 ) ;
} else {
F_25 ( V_4 , L_22 ,
F_121 ( & V_120 -> V_89 ) ) ;
goto V_145;
}
} else {
F_97 ( & V_4 -> V_94 , V_6 ) ;
F_123 ( V_2 , V_88 , V_76 -> V_90 , F_124 ( V_129 ) ) ;
F_125 ( V_120 ) ;
return;
}
} else {
V_120 -> V_90 = NULL ;
if ( ! V_76 -> V_113 && F_116 ( V_2 , V_76 ) )
goto V_144;
if ( F_121 ( & V_120 -> V_89 ) < V_146 )
F_104 ( & V_120 -> V_89 , V_88 ) ;
else
goto V_145;
}
F_97 ( & V_4 -> V_94 , V_6 ) ;
F_125 ( V_120 ) ;
return;
V_144:
F_110 ( V_120 ) ;
V_145:
++ V_2 -> V_142 . V_143 ;
F_120 ( V_88 ) ;
F_97 ( & V_4 -> V_94 , V_6 ) ;
F_125 ( V_120 ) ;
}
static void F_126 ( struct V_87 * V_88 , struct V_1 * V_2 ,
struct V_148 * V_149 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_72 * V_76 ;
unsigned long V_6 ;
F_93 ( & V_4 -> V_94 , V_6 ) ;
V_76 = F_58 ( V_2 , V_149 -> V_150 + 4 ) ;
if ( ! V_76 || ! V_76 -> V_97 ) {
int V_151 = 0 ;
if ( ! V_76 ) {
V_76 = F_112 ( V_2 , V_149 -> V_150 + 4 ) ;
V_151 = 1 ;
}
if ( V_76 ) {
if ( F_121 ( & V_76 -> V_89 ) < V_146 ) {
F_122 ( V_88 , V_147 ) ;
F_104 ( & V_76 -> V_89 , V_88 ) ;
} else {
++ V_2 -> V_142 . V_143 ;
F_120 ( V_88 ) ;
}
if ( ! V_76 -> V_113 && F_116 ( V_2 , V_76 ) ) {
F_97 ( & V_4 -> V_94 , V_6 ) ;
if ( V_151 )
F_64 ( V_2 , V_76 ) ;
return;
} else
F_60 ( V_2 , V_76 ) ;
} else {
++ V_2 -> V_142 . V_143 ;
F_120 ( V_88 ) ;
}
F_97 ( & V_4 -> V_94 , V_6 ) ;
return;
}
if ( V_76 -> V_90 ) {
F_3 ( V_4 , L_23 ,
F_80 ( V_76 -> V_77 . V_96 ) ) ;
F_97 ( & V_4 -> V_94 , V_6 ) ;
F_123 ( V_2 , V_88 , V_76 -> V_90 , F_124 ( V_149 -> V_150 ) ) ;
return;
} else if ( ( V_76 -> V_113 || ! F_116 ( V_2 , V_76 ) ) &&
F_121 ( & V_76 -> V_89 ) < V_146 ) {
F_122 ( V_88 , V_147 ) ;
F_104 ( & V_76 -> V_89 , V_88 ) ;
} else {
++ V_2 -> V_142 . V_143 ;
F_120 ( V_88 ) ;
}
F_97 ( & V_4 -> V_94 , V_6 ) ;
}
static int F_127 ( struct V_87 * V_88 , struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_119 * V_120 ;
struct V_148 * V_149 ;
struct V_152 * V_153 ;
unsigned long V_6 ;
V_149 = (struct V_148 * ) V_88 -> V_47 ;
F_128 ( V_88 , sizeof( * V_149 ) ) ;
V_153 = (struct V_152 * ) V_88 -> V_47 ;
if ( F_129 ( V_149 -> V_150 [ 4 ] == 0xff ) ) {
if ( ( V_153 -> V_154 != F_130 ( V_155 ) ) &&
( V_153 -> V_154 != F_130 ( V_156 ) ) &&
( V_153 -> V_154 != F_130 ( V_157 ) ) &&
( V_153 -> V_154 != F_130 ( V_158 ) ) &&
( V_153 -> V_154 != F_130 ( V_159 ) ) ) {
++ V_2 -> V_142 . V_143 ;
F_120 ( V_88 ) ;
return V_160 ;
}
V_149 -> V_150 [ 8 ] = ( V_4 -> V_64 >> 8 ) & 0xff ;
V_149 -> V_150 [ 9 ] = V_4 -> V_64 & 0xff ;
V_120 = F_131 ( V_2 , V_149 -> V_150 ) ;
if ( F_132 ( V_120 ) )
goto V_161;
F_133 ( V_2 , V_149 -> V_150 , V_88 ) ;
return V_160 ;
}
switch ( V_153 -> V_154 ) {
case F_130 ( V_155 ) :
case F_130 ( V_156 ) :
case F_130 ( V_159 ) :
V_120 = F_131 ( V_2 , V_149 -> V_150 ) ;
if ( F_129 ( ! V_120 ) ) {
F_118 ( V_88 , V_149 -> V_150 , V_2 ) ;
return V_160 ;
}
break;
case F_130 ( V_157 ) :
case F_130 ( V_158 ) :
F_126 ( V_88 , V_2 , V_149 ) ;
return V_160 ;
default:
++ V_2 -> V_142 . V_143 ;
F_120 ( V_88 ) ;
return V_160 ;
}
V_161:
if ( F_107 ( V_120 ) ) {
if ( F_134 ( V_120 ) ) {
F_135 ( V_2 , V_88 , F_107 ( V_120 ) ) ;
goto V_162;
}
} else if ( V_120 -> V_90 ) {
F_123 ( V_2 , V_88 , V_120 -> V_90 , F_124 ( V_149 -> V_150 ) ) ;
goto V_162;
}
if ( F_121 ( & V_120 -> V_89 ) < V_146 ) {
F_122 ( V_88 , sizeof( * V_149 ) ) ;
F_93 ( & V_4 -> V_94 , V_6 ) ;
F_104 ( & V_120 -> V_89 , V_88 ) ;
F_97 ( & V_4 -> V_94 , V_6 ) ;
} else {
++ V_2 -> V_142 . V_143 ;
F_120 ( V_88 ) ;
}
V_162:
F_125 ( V_120 ) ;
return V_160 ;
}
static void F_136 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
F_25 ( V_4 , L_24 ,
F_137 ( V_163 - F_138 ( V_2 ) ) ) ;
F_25 ( V_4 , L_25 ,
F_139 ( V_2 ) ,
V_4 -> V_164 , V_4 -> V_165 ) ;
}
static int F_140 ( struct V_87 * V_88 ,
struct V_1 * V_2 ,
unsigned short type ,
const void * V_129 , const void * V_166 , unsigned V_167 )
{
struct V_148 * V_149 ;
struct V_152 * V_153 ;
V_153 = (struct V_152 * ) F_122 ( V_88 , sizeof *V_153 ) ;
V_153 -> V_154 = F_130 ( type ) ;
V_153 -> V_168 = 0 ;
V_149 = (struct V_148 * ) F_122 ( V_88 , sizeof( * V_149 ) ) ;
memcpy ( V_149 -> V_150 , V_129 , V_169 ) ;
return V_170 ;
}
static void F_141 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
if ( ! F_7 ( V_171 , & V_4 -> V_6 ) ) {
F_3 ( V_4 , L_26 ) ;
return;
}
F_142 ( V_4 -> V_172 , & V_4 -> V_173 ) ;
}
static int F_143 ( const struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
if ( ! F_7 ( V_11 , & V_4 -> V_6 ) )
return V_2 -> V_174 ;
return V_4 -> V_175 -> V_174 ;
}
static T_5 F_144 ( struct V_176 * V_177 , T_4 * V_129 )
{
T_5 * V_178 = ( T_5 * ) V_129 ;
T_5 V_179 ;
V_179 = F_145 ( V_178 [ 3 ] , V_178 [ 4 ] , V_180 & V_178 [ 0 ] , 0 ) ;
return V_179 & V_177 -> V_181 ;
}
struct V_119 * F_131 ( struct V_1 * V_2 , T_4 * V_129 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_182 * V_183 = & V_4 -> V_183 ;
struct V_176 * V_177 ;
struct V_119 * V_120 = NULL ;
T_5 V_184 ;
F_146 () ;
V_177 = F_147 ( V_183 -> V_177 ) ;
if ( ! V_177 )
goto V_185;
V_184 = F_144 ( V_177 , V_129 ) ;
for ( V_120 = F_147 ( V_177 -> V_186 [ V_184 ] ) ;
V_120 != NULL ;
V_120 = F_147 ( V_120 -> V_187 ) ) {
if ( memcmp ( V_129 , V_120 -> V_129 , V_169 ) == 0 ) {
if ( ! F_148 ( & V_120 -> V_188 ) ) {
V_120 = NULL ;
goto V_185;
}
if ( F_132 ( F_121 ( & V_120 -> V_89 ) < V_146 ) )
V_120 -> V_189 = V_163 ;
goto V_185;
}
}
V_185:
F_149 () ;
return V_120 ;
}
static void F_150 ( struct V_3 * V_4 )
{
struct V_182 * V_183 = & V_4 -> V_183 ;
struct V_176 * V_177 ;
unsigned long V_190 ;
unsigned long V_191 ;
unsigned long V_6 ;
int V_192 ;
F_91 ( V_112 ) ;
if ( F_7 ( V_193 , & V_4 -> V_6 ) )
return;
F_93 ( & V_4 -> V_94 , V_6 ) ;
V_177 = F_151 ( V_183 -> V_177 ,
F_152 ( & V_4 -> V_94 ) ) ;
if ( ! V_177 )
goto V_185;
V_191 = 2 * V_194 . V_195 ;
V_190 = V_163 - V_191 ;
if ( F_7 ( V_193 , & V_4 -> V_6 ) )
goto V_185;
for ( V_192 = 0 ; V_192 < V_177 -> V_196 ; V_192 ++ ) {
struct V_119 * V_120 ;
struct V_119 T_6 * * V_197 = & V_177 -> V_186 [ V_192 ] ;
while ( ( V_120 = F_151 ( * V_197 ,
F_152 ( & V_4 -> V_94 ) ) ) != NULL ) {
if ( F_153 ( V_190 , V_120 -> V_189 ) ) {
F_154 ( V_4 , V_120 -> V_129 + 4 , & V_112 ) ;
F_155 ( * V_197 ,
F_151 ( V_120 -> V_187 ,
F_152 ( & V_4 -> V_94 ) ) ) ;
F_156 ( & V_120 -> V_85 ) ;
F_157 ( & V_120 -> V_198 , V_199 ) ;
} else {
V_197 = & V_120 -> V_187 ;
}
}
}
V_185:
F_97 ( & V_4 -> V_94 , V_6 ) ;
F_158 ( & V_112 ) ;
}
static void F_159 ( struct V_200 * V_201 )
{
struct V_3 * V_4 =
F_160 ( V_201 , struct V_3 , V_202 . V_201 ) ;
F_150 ( V_4 ) ;
if ( ! F_7 ( V_193 , & V_4 -> V_6 ) )
F_161 ( V_4 -> V_172 , & V_4 -> V_202 ,
V_194 . V_195 ) ;
}
static struct V_119 * F_162 ( T_4 * V_129 ,
struct V_1 * V_2 )
{
struct V_119 * V_120 ;
V_120 = F_113 ( sizeof *V_120 , V_131 ) ;
if ( ! V_120 )
return NULL ;
V_120 -> V_2 = V_2 ;
memcpy ( & V_120 -> V_129 , V_129 , sizeof( V_120 -> V_129 ) ) ;
F_100 ( & V_120 -> V_89 ) ;
F_114 ( & V_120 -> V_85 ) ;
F_108 ( V_120 , NULL ) ;
F_163 ( & V_120 -> V_188 , 1 ) ;
return V_120 ;
}
struct V_119 * F_119 ( T_4 * V_129 ,
struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_182 * V_183 = & V_4 -> V_183 ;
struct V_176 * V_177 ;
struct V_119 * V_120 ;
T_5 V_184 ;
V_177 = F_151 ( V_183 -> V_177 ,
F_152 ( & V_4 -> V_94 ) ) ;
if ( ! V_177 ) {
V_120 = NULL ;
goto V_185;
}
V_184 = F_144 ( V_177 , V_129 ) ;
for ( V_120 = F_151 ( V_177 -> V_186 [ V_184 ] ,
F_152 ( & V_4 -> V_94 ) ) ;
V_120 != NULL ;
V_120 = F_151 ( V_120 -> V_187 ,
F_152 ( & V_4 -> V_94 ) ) ) {
if ( memcmp ( V_129 , V_120 -> V_129 , V_169 ) == 0 ) {
if ( ! F_148 ( & V_120 -> V_188 ) ) {
V_120 = NULL ;
break;
}
V_120 -> V_189 = V_163 ;
goto V_185;
}
}
V_120 = F_162 ( V_129 , V_2 ) ;
if ( ! V_120 )
goto V_185;
F_164 ( & V_120 -> V_188 ) ;
V_120 -> V_189 = V_163 ;
F_155 ( V_120 -> V_187 ,
F_151 ( V_177 -> V_186 [ V_184 ] ,
F_152 ( & V_4 -> V_94 ) ) ) ;
F_155 ( V_177 -> V_186 [ V_184 ] , V_120 ) ;
F_164 ( & V_183 -> V_203 ) ;
V_185:
return V_120 ;
}
void F_165 ( struct V_119 * V_120 )
{
struct V_1 * V_2 = V_120 -> V_2 ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_87 * V_88 ;
if ( V_120 -> V_90 )
F_68 ( V_120 -> V_90 ) ;
while ( ( V_88 = F_65 ( & V_120 -> V_89 ) ) ) {
++ V_2 -> V_142 . V_143 ;
F_120 ( V_88 ) ;
}
if ( F_107 ( V_120 ) )
F_166 ( F_107 ( V_120 ) ) ;
F_3 ( F_2 ( V_2 ) ,
L_27 ,
F_124 ( V_120 -> V_129 ) ,
V_120 -> V_129 + 4 ) ;
F_69 ( V_120 ) ;
if ( F_167 ( & V_4 -> V_183 . V_203 ) ) {
if ( F_7 ( V_204 , & V_4 -> V_6 ) )
F_85 ( & V_4 -> V_183 . V_205 ) ;
}
}
static void V_199 ( struct V_206 * V_207 )
{
struct V_119 * V_120 = F_160 ( V_207 , struct V_119 , V_198 ) ;
F_125 ( V_120 ) ;
}
void F_110 ( struct V_119 * V_120 )
{
struct V_1 * V_2 = V_120 -> V_2 ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_182 * V_183 = & V_4 -> V_183 ;
struct V_176 * V_177 ;
struct V_119 T_6 * * V_197 ;
struct V_119 * V_74 ;
T_5 V_184 ;
V_177 = F_151 ( V_183 -> V_177 ,
F_152 ( & V_4 -> V_94 ) ) ;
if ( ! V_177 )
return;
V_184 = F_144 ( V_177 , V_120 -> V_129 ) ;
V_197 = & V_177 -> V_186 [ V_184 ] ;
for ( V_74 = F_151 ( * V_197 ,
F_152 ( & V_4 -> V_94 ) ) ;
V_74 != NULL ;
V_74 = F_151 ( * V_197 ,
F_152 ( & V_4 -> V_94 ) ) ) {
if ( V_74 == V_120 ) {
F_155 ( * V_197 ,
F_151 ( V_120 -> V_187 ,
F_152 ( & V_4 -> V_94 ) ) ) ;
F_156 ( & V_120 -> V_85 ) ;
F_157 ( & V_120 -> V_198 , V_199 ) ;
return;
} else {
V_197 = & V_74 -> V_187 ;
}
}
}
static int F_168 ( struct V_3 * V_4 )
{
struct V_182 * V_183 = & V_4 -> V_183 ;
struct V_176 * V_177 ;
struct V_119 T_6 * * V_186 ;
T_5 V_196 ;
F_15 ( V_204 , & V_4 -> V_6 ) ;
V_183 -> V_177 = NULL ;
V_177 = F_113 ( sizeof( * V_177 ) , V_93 ) ;
if ( ! V_177 )
return - V_108 ;
F_5 ( V_193 , & V_4 -> V_6 ) ;
V_196 = F_169 ( V_194 . V_208 ) ;
V_186 = F_113 ( V_196 * sizeof( * V_186 ) , V_93 ) ;
if ( ! V_186 ) {
F_69 ( V_177 ) ;
return - V_108 ;
}
V_177 -> V_196 = V_196 ;
V_177 -> V_181 = ( V_196 - 1 ) ;
V_177 -> V_186 = V_186 ;
F_170 ( V_183 -> V_177 , V_177 ) ;
V_177 -> V_183 = V_183 ;
F_163 ( & V_183 -> V_203 , 0 ) ;
F_15 ( V_193 , & V_4 -> V_6 ) ;
F_161 ( V_4 -> V_172 , & V_4 -> V_202 ,
V_194 . V_195 ) ;
return 0 ;
}
static void F_171 ( struct V_206 * V_209 )
{
struct V_176 * V_177 = F_160 ( V_209 ,
struct V_176 ,
V_198 ) ;
struct V_119 T_6 * * V_186 = V_177 -> V_186 ;
struct V_182 * V_183 = V_177 -> V_183 ;
F_69 ( V_186 ) ;
F_69 ( V_177 ) ;
F_85 ( & V_183 -> V_210 ) ;
}
void F_67 ( struct V_1 * V_2 , T_4 * V_52 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_182 * V_183 = & V_4 -> V_183 ;
struct V_176 * V_177 ;
unsigned long V_6 ;
int V_192 ;
F_93 ( & V_4 -> V_94 , V_6 ) ;
V_177 = F_151 ( V_183 -> V_177 ,
F_152 ( & V_4 -> V_94 ) ) ;
if ( ! V_177 )
goto V_185;
for ( V_192 = 0 ; V_192 < V_177 -> V_196 ; V_192 ++ ) {
struct V_119 * V_120 ;
struct V_119 T_6 * * V_197 = & V_177 -> V_186 [ V_192 ] ;
while ( ( V_120 = F_151 ( * V_197 ,
F_152 ( & V_4 -> V_94 ) ) ) != NULL ) {
if ( ! memcmp ( V_52 , V_120 -> V_129 + 4 , sizeof ( union V_51 ) ) ) {
F_155 ( * V_197 ,
F_151 ( V_120 -> V_187 ,
F_152 ( & V_4 -> V_94 ) ) ) ;
F_156 ( & V_120 -> V_85 ) ;
F_157 ( & V_120 -> V_198 , V_199 ) ;
} else {
V_197 = & V_120 -> V_187 ;
}
}
}
V_185:
F_97 ( & V_4 -> V_94 , V_6 ) ;
}
static void F_172 ( struct V_3 * V_4 )
{
struct V_182 * V_183 = & V_4 -> V_183 ;
struct V_176 * V_177 ;
unsigned long V_6 ;
int V_192 , V_211 = 0 ;
F_87 ( & V_4 -> V_183 . V_205 ) ;
F_93 ( & V_4 -> V_94 , V_6 ) ;
V_177 = F_151 ( V_183 -> V_177 ,
F_152 ( & V_4 -> V_94 ) ) ;
if ( ! V_177 )
goto V_185;
V_211 = F_173 ( & V_4 -> V_183 . V_203 ) ;
if ( ! V_211 )
goto V_212;
for ( V_192 = 0 ; V_192 < V_177 -> V_196 ; V_192 ++ ) {
struct V_119 * V_120 ;
struct V_119 T_6 * * V_197 = & V_177 -> V_186 [ V_192 ] ;
while ( ( V_120 = F_151 ( * V_197 ,
F_152 ( & V_4 -> V_94 ) ) ) != NULL ) {
F_155 ( * V_197 ,
F_151 ( V_120 -> V_187 ,
F_152 ( & V_4 -> V_94 ) ) ) ;
F_156 ( & V_120 -> V_85 ) ;
F_157 ( & V_120 -> V_198 , V_199 ) ;
}
}
V_212:
F_155 ( V_183 -> V_177 , NULL ) ;
F_157 ( & V_177 -> V_198 , F_171 ) ;
V_185:
F_97 ( & V_4 -> V_94 , V_6 ) ;
if ( V_211 )
F_90 ( & V_4 -> V_183 . V_205 ) ;
}
static void F_174 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_213 ;
F_3 ( V_4 , L_28 ) ;
F_87 ( & V_4 -> V_183 . V_210 ) ;
F_5 ( V_204 , & V_4 -> V_6 ) ;
V_213 = F_175 ( V_193 , & V_4 -> V_6 ) ;
if ( ! V_213 )
F_176 ( & V_4 -> V_202 ) ;
F_172 ( V_4 ) ;
F_90 ( & V_4 -> V_183 . V_210 ) ;
}
int F_177 ( struct V_1 * V_2 , struct V_63 * V_110 , int V_62 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
V_4 -> V_214 = F_113 ( V_215 * sizeof * V_4 -> V_214 ,
V_93 ) ;
if ( ! V_4 -> V_214 )
goto V_50;
V_4 -> V_216 = F_178 ( V_217 * sizeof * V_4 -> V_216 ) ;
if ( ! V_4 -> V_216 ) {
F_179 ( V_218 L_29 ,
V_110 -> V_104 , V_217 ) ;
goto V_219;
}
if ( F_180 ( V_2 , V_110 , V_62 ) )
goto V_220;
if ( F_168 ( V_4 ) < 0 )
goto V_221;
return 0 ;
V_221:
F_181 ( V_2 ) ;
V_220:
F_182 ( V_4 -> V_216 ) ;
V_219:
F_69 ( V_4 -> V_214 ) ;
V_50:
return - V_108 ;
}
void F_20 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) , * V_12 , * V_222 ;
F_91 ( V_209 ) ;
F_183 () ;
F_184 ( V_2 ) ;
F_79 (cpriv, tcpriv, &priv->child_intfs, list) {
F_5 ( V_193 , & V_12 -> V_6 ) ;
F_176 ( & V_12 -> V_202 ) ;
F_185 ( V_12 -> V_2 , & V_209 ) ;
}
F_186 ( & V_209 ) ;
F_174 ( V_2 ) ;
F_181 ( V_2 ) ;
F_69 ( V_4 -> V_214 ) ;
F_182 ( V_4 -> V_216 ) ;
V_4 -> V_214 = NULL ;
V_4 -> V_216 = NULL ;
}
static int F_187 ( struct V_1 * V_2 , int V_223 , int V_224 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
return F_188 ( V_4 -> V_110 , V_223 , V_4 -> V_62 , V_224 ) ;
}
static int F_189 ( struct V_1 * V_2 , int V_223 ,
struct V_225 * V_226 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_227 ;
V_227 = F_190 ( V_4 -> V_110 , V_223 , V_4 -> V_62 , V_226 ) ;
if ( V_227 )
return V_227 ;
V_226 -> V_223 = V_223 ;
return 0 ;
}
static int F_191 ( struct V_1 * V_2 , int V_223 , T_7 V_228 , int type )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
if ( type != V_229 && type != V_230 )
return - V_15 ;
return F_192 ( V_4 -> V_110 , V_223 , V_4 -> V_62 , V_228 , type ) ;
}
static int F_193 ( struct V_1 * V_2 , int V_223 ,
struct V_231 * V_232 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
return F_194 ( V_4 -> V_110 , V_223 , V_4 -> V_62 , V_232 ) ;
}
void F_195 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
if ( V_4 -> V_233 & V_234 )
V_2 -> V_235 = & V_236 ;
else
V_2 -> V_235 = & V_237 ;
V_2 -> V_238 = & V_239 ;
F_196 ( V_2 ) ;
F_197 ( V_2 , & V_4 -> V_240 , V_241 , V_242 ) ;
V_2 -> V_243 = V_244 ;
V_2 -> V_6 |= V_245 | V_246 ;
V_2 -> V_247 = V_170 ;
V_2 -> V_248 = V_169 ;
V_2 -> type = V_249 ;
V_2 -> V_250 = V_217 * 2 ;
V_2 -> V_16 = ( V_251 |
V_252 ) ;
F_198 ( V_2 ) ;
memcpy ( V_2 -> V_130 , V_253 , V_169 ) ;
V_4 -> V_2 = V_2 ;
F_199 ( & V_4 -> V_94 ) ;
F_200 ( & V_4 -> V_13 ) ;
F_114 ( & V_4 -> V_86 ) ;
F_114 ( & V_4 -> V_254 ) ;
F_114 ( & V_4 -> V_255 ) ;
F_114 ( & V_4 -> V_256 ) ;
F_201 ( & V_4 -> V_257 , V_258 ) ;
F_202 ( & V_4 -> V_259 , V_260 ) ;
F_202 ( & V_4 -> V_261 , V_262 ) ;
F_202 ( & V_4 -> V_263 , V_264 ) ;
F_202 ( & V_4 -> V_265 , V_266 ) ;
F_202 ( & V_4 -> V_173 , V_267 ) ;
F_201 ( & V_4 -> V_268 , V_269 ) ;
F_201 ( & V_4 -> V_202 , F_159 ) ;
}
struct V_3 * F_203 ( const char * V_104 )
{
struct V_1 * V_2 ;
V_2 = F_204 ( ( int ) sizeof( struct V_3 ) , V_104 ,
V_270 , F_195 ) ;
if ( ! V_2 )
return NULL ;
return F_2 ( V_2 ) ;
}
static T_8 F_205 ( struct V_271 * V_2 ,
struct V_272 * V_273 , char * V_66 )
{
struct V_3 * V_4 = F_2 ( F_206 ( V_2 ) ) ;
return sprintf ( V_66 , L_30 , V_4 -> V_64 ) ;
}
static T_8 F_207 ( struct V_271 * V_2 ,
struct V_272 * V_273 , char * V_66 )
{
struct V_3 * V_4 = F_2 ( F_206 ( V_2 ) ) ;
return sprintf ( V_66 , L_31 , F_7 ( V_274 , & V_4 -> V_6 ) ) ;
}
void F_208 ( struct V_1 * V_275 , int V_276 )
{
struct V_3 * V_4 = F_2 ( V_275 ) ;
if ( V_276 > 0 ) {
F_5 ( V_274 , & V_4 -> V_6 ) ;
F_25 ( V_4 , L_32
L_33 ) ;
} else
F_15 ( V_274 , & V_4 -> V_6 ) ;
}
static T_8 F_209 ( struct V_271 * V_2 ,
struct V_272 * V_273 ,
const char * V_66 , T_9 V_277 )
{
unsigned long V_276 = F_210 ( V_66 , NULL , 0 ) ;
F_208 ( F_206 ( V_2 ) , V_276 ) ;
return V_277 ;
}
int F_211 ( struct V_1 * V_2 )
{
return F_212 ( & V_2 -> V_2 , & V_278 ) ;
}
static void F_213 ( struct V_3 * V_4 , union V_51 * V_52 )
{
struct V_3 * V_56 ;
struct V_1 * V_279 = V_4 -> V_2 ;
F_214 ( V_279 ) ;
memcpy ( & V_4 -> V_59 . V_280 . V_281 ,
& V_52 -> V_280 . V_281 ,
sizeof( V_52 -> V_280 . V_281 ) ) ;
memcpy ( V_279 -> V_67 + 4 , & V_4 -> V_59 , sizeof( V_4 -> V_59 ) ) ;
F_15 ( V_282 , & V_4 -> V_6 ) ;
F_215 ( V_279 ) ;
if ( ! F_7 ( V_11 , & V_4 -> V_6 ) ) {
F_9 ( & V_4 -> V_13 ) ;
F_10 (child_priv, &priv->child_intfs, list)
F_213 ( V_56 , V_52 ) ;
F_12 ( & V_4 -> V_13 ) ;
}
}
static int F_216 ( struct V_1 * V_2 ,
struct V_283 * V_284 )
{
union V_51 * V_52 = (union V_51 * ) ( V_284 -> V_285 + 4 ) ;
int V_48 = 0 ;
F_214 ( V_2 ) ;
if ( memcmp ( V_2 -> V_67 , V_284 -> V_285 ,
4 + sizeof( V_52 -> V_280 . V_286 ) ) ||
V_52 -> V_280 . V_281 == 0 )
V_48 = - V_15 ;
F_215 ( V_2 ) ;
return V_48 ;
}
static int F_217 ( struct V_1 * V_2 , void * V_26 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_283 * V_284 = V_26 ;
int V_48 ;
if ( ! ( V_2 -> V_287 & V_288 ) && F_218 ( V_2 ) )
return - V_289 ;
V_48 = F_216 ( V_2 , V_284 ) ;
if ( V_48 )
return V_48 ;
F_213 ( V_4 , (union V_51 * ) ( V_284 -> V_285 + 4 ) ) ;
F_142 ( V_290 , & V_4 -> V_261 ) ;
return 0 ;
}
static T_8 F_219 ( struct V_271 * V_2 ,
struct V_272 * V_273 ,
const char * V_66 , T_9 V_277 )
{
int V_64 ;
int V_48 ;
if ( sscanf ( V_66 , L_34 , & V_64 ) != 1 )
return - V_15 ;
if ( V_64 <= 0 || V_64 > 0xffff || V_64 == 0x8000 )
return - V_15 ;
V_64 |= 0x8000 ;
V_48 = F_220 ( F_206 ( V_2 ) , V_64 ) ;
return V_48 ? V_48 : V_277 ;
}
static T_8 F_221 ( struct V_271 * V_2 ,
struct V_272 * V_273 ,
const char * V_66 , T_9 V_277 )
{
int V_64 ;
int V_48 ;
if ( sscanf ( V_66 , L_34 , & V_64 ) != 1 )
return - V_15 ;
if ( V_64 < 0 || V_64 > 0xffff )
return - V_15 ;
V_48 = F_222 ( F_206 ( V_2 ) , V_64 ) ;
return V_48 ? V_48 : V_277 ;
}
int F_223 ( struct V_1 * V_2 )
{
return F_212 ( & V_2 -> V_2 , & V_291 ) ;
}
int F_224 ( struct V_3 * V_4 , struct V_63 * V_292 )
{
V_4 -> V_233 = V_292 -> V_293 . V_294 ;
if ( V_4 -> V_233 & V_295 ) {
V_4 -> V_2 -> V_296 = V_18 | V_297 ;
if ( V_4 -> V_233 & V_298 )
V_4 -> V_2 -> V_296 |= V_19 ;
V_4 -> V_2 -> V_16 |= V_4 -> V_2 -> V_296 ;
}
return 0 ;
}
static struct V_1 * F_225 ( const char * V_299 ,
struct V_63 * V_292 , T_4 V_62 )
{
struct V_3 * V_4 ;
struct V_300 V_273 ;
int V_49 = - V_108 ;
V_4 = F_203 ( V_299 ) ;
if ( ! V_4 )
goto V_301;
F_226 ( V_4 -> V_2 , V_292 -> V_302 ) ;
V_4 -> V_2 -> V_303 = V_62 - 1 ;
V_49 = F_227 ( V_292 , V_62 , & V_273 ) ;
if ( ! V_49 )
V_4 -> V_23 = F_228 ( V_273 . V_304 ) ;
else {
F_179 ( V_218 L_35 ,
V_292 -> V_104 , V_62 ) ;
goto V_305;
}
V_4 -> V_2 -> V_22 = F_26 ( V_4 -> V_23 ) ;
V_4 -> V_21 = V_4 -> V_24 = V_4 -> V_2 -> V_22 ;
V_4 -> V_2 -> V_304 = V_306 ;
V_4 -> V_2 -> V_307 = sizeof( struct V_119 ) ;
V_49 = F_229 ( V_292 , V_62 , 0 , & V_4 -> V_64 ) ;
if ( V_49 ) {
F_179 ( V_218 L_36 ,
V_292 -> V_104 , V_62 , V_49 ) ;
goto V_305;
}
V_49 = F_224 ( V_4 , V_292 ) ;
if ( V_49 )
goto V_305;
V_4 -> V_64 |= 0x8000 ;
V_4 -> V_2 -> V_130 [ 8 ] = V_4 -> V_64 >> 8 ;
V_4 -> V_2 -> V_130 [ 9 ] = V_4 -> V_64 & 0xff ;
V_49 = F_230 ( V_292 , V_62 , 0 , & V_4 -> V_59 , NULL ) ;
if ( V_49 ) {
F_179 ( V_218 L_37 ,
V_292 -> V_104 , V_62 , V_49 ) ;
goto V_305;
} else
memcpy ( V_4 -> V_2 -> V_67 + 4 , V_4 -> V_59 . V_79 , sizeof ( union V_51 ) ) ;
F_5 ( V_282 , & V_4 -> V_6 ) ;
V_49 = F_177 ( V_4 -> V_2 , V_292 , V_62 ) ;
if ( V_49 < 0 ) {
F_179 ( V_218 L_38 ,
V_292 -> V_104 , V_62 , V_49 ) ;
goto V_305;
}
F_231 ( & V_4 -> V_308 ,
V_4 -> V_110 , V_309 ) ;
V_49 = F_232 ( & V_4 -> V_308 ) ;
if ( V_49 < 0 ) {
F_179 ( V_218 L_39
L_40 ,
V_292 -> V_104 , V_62 , V_49 ) ;
goto V_310;
}
V_49 = F_233 ( V_4 -> V_2 ) ;
if ( V_49 ) {
F_179 ( V_218 L_41 ,
V_292 -> V_104 , V_62 , V_49 ) ;
goto V_311;
}
F_234 ( V_4 -> V_2 ) ;
if ( F_235 ( V_4 -> V_2 ) )
goto V_312;
if ( F_223 ( V_4 -> V_2 ) )
goto V_312;
if ( F_211 ( V_4 -> V_2 ) )
goto V_312;
if ( F_212 ( & V_4 -> V_2 -> V_2 , & V_313 ) )
goto V_312;
if ( F_212 ( & V_4 -> V_2 -> V_2 , & V_314 ) )
goto V_312;
return V_4 -> V_2 ;
V_312:
F_184 ( V_4 -> V_2 ) ;
F_236 ( V_4 -> V_2 ) ;
V_311:
F_237 ( & V_4 -> V_308 ) ;
F_238 ( V_290 ) ;
F_5 ( V_193 , & V_4 -> V_6 ) ;
F_176 ( & V_4 -> V_202 ) ;
F_238 ( V_4 -> V_172 ) ;
V_310:
F_20 ( V_4 -> V_2 ) ;
V_305:
F_239 ( V_4 -> V_2 ) ;
V_301:
return F_240 ( V_49 ) ;
}
static void F_241 ( struct V_63 * V_271 )
{
struct V_60 * V_61 ;
struct V_1 * V_2 ;
struct V_3 * V_4 ;
int V_315 ;
int V_277 = 0 ;
V_61 = F_71 ( sizeof *V_61 , V_93 ) ;
if ( ! V_61 )
return;
F_114 ( V_61 ) ;
for ( V_315 = F_242 ( V_271 ) ; V_315 <= F_243 ( V_271 ) ; ++ V_315 ) {
if ( ! F_48 ( V_271 , V_315 ) )
continue;
V_2 = F_225 ( L_42 , V_271 , V_315 ) ;
if ( ! F_244 ( V_2 ) ) {
V_4 = F_2 ( V_2 ) ;
F_63 ( & V_4 -> V_85 , V_61 ) ;
V_277 ++ ;
}
}
if ( ! V_277 ) {
F_69 ( V_61 ) ;
return;
}
F_245 ( V_271 , & V_316 , V_61 ) ;
}
static void F_246 ( struct V_63 * V_271 , void * V_65 )
{
struct V_3 * V_4 , * V_317 ;
struct V_60 * V_61 = V_65 ;
if ( ! V_61 )
return;
F_79 (priv, tmp, dev_list, list) {
F_237 ( & V_4 -> V_308 ) ;
F_238 ( V_290 ) ;
F_5 ( V_318 , & V_4 -> V_6 ) ;
F_57 () ;
F_11 ( V_4 -> V_2 , V_4 -> V_2 -> V_6 & ~ V_14 ) ;
F_55 () ;
F_5 ( V_193 , & V_4 -> V_6 ) ;
F_176 ( & V_4 -> V_202 ) ;
F_238 ( V_4 -> V_172 ) ;
F_236 ( V_4 -> V_2 ) ;
F_239 ( V_4 -> V_2 ) ;
}
F_69 ( V_61 ) ;
}
static int T_10 F_247 ( void )
{
int V_48 ;
V_215 = F_169 ( V_215 ) ;
V_215 = F_27 ( V_215 , V_319 ) ;
V_215 = F_248 ( V_215 , V_320 ) ;
V_217 = F_169 ( V_217 ) ;
V_217 = F_27 ( V_217 , V_319 ) ;
V_217 = F_249 ( V_217 , 2 * V_321 , V_320 ) ;
#ifdef F_250
V_322 = F_27 ( V_322 , V_323 ) ;
#endif
F_251 ( V_324 > V_325 ) ;
V_48 = F_252 () ;
if ( V_48 )
return V_48 ;
V_290 = F_253 ( L_43 ,
V_326 ) ;
if ( ! V_290 ) {
V_48 = - V_108 ;
goto V_327;
}
F_254 ( & V_109 ) ;
V_48 = F_255 ( & V_316 ) ;
if ( V_48 )
goto V_328;
V_48 = F_256 () ;
if ( V_48 )
goto V_329;
return 0 ;
V_329:
F_257 ( & V_316 ) ;
V_328:
F_258 ( & V_109 ) ;
F_259 ( V_290 ) ;
V_327:
F_260 () ;
return V_48 ;
}
static void T_11 F_261 ( void )
{
F_262 () ;
F_257 ( & V_316 ) ;
F_258 ( & V_109 ) ;
F_260 () ;
F_259 ( V_290 ) ;
}
