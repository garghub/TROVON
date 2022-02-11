int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
F_3 ( V_4 , L_1 ) ;
F_4 ( V_2 ) ;
F_5 ( V_5 , & V_4 -> V_6 ) ;
if ( F_6 ( V_2 ) ) {
if ( ! F_7 ( V_7 , & V_4 -> V_6 ) )
return 0 ;
goto V_8;
}
if ( F_8 ( V_2 ) )
goto V_9;
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
F_14 ( V_2 ) ;
V_8:
F_15 ( V_5 , & V_4 -> V_6 ) ;
return - V_14 ;
}
static int F_16 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
F_3 ( V_4 , L_2 ) ;
F_15 ( V_5 , & V_4 -> V_6 ) ;
F_17 ( V_2 ) ;
F_18 ( V_2 ) ;
F_14 ( V_2 ) ;
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
static struct V_1 * F_40 (
const struct V_24 * V_25 , struct V_1 * V_2 )
{
struct V_1 * V_43 ,
* V_44 = NULL ;
struct V_45 * V_46 ;
F_36 () ;
if ( F_28 ( V_25 , V_2 ) ) {
F_38 ( V_2 ) ;
V_44 = V_2 ;
goto V_47;
}
F_41 (dev, upper, iter) {
if ( F_28 ( V_25 , V_43 ) ) {
F_38 ( V_43 ) ;
V_44 = V_43 ;
break;
}
}
V_47:
F_39 () ;
return V_44 ;
}
static int F_42 ( struct V_3 * V_4 ,
const union V_48 * V_49 ,
T_3 V_50 ,
const struct V_24 * V_25 ,
int V_51 ,
struct V_1 * * V_52 )
{
struct V_3 * V_53 ;
struct V_1 * V_54 = NULL ;
int V_55 = 0 ;
if ( V_4 -> V_50 == V_50 &&
( ! V_49 || ! memcmp ( V_49 , & V_4 -> V_56 , sizeof( * V_49 ) ) ) ) {
if ( ! V_25 ) {
V_54 = F_35 ( V_4 -> V_2 ) ;
} else {
V_54 = F_40 ( V_25 , V_4 -> V_2 ) ;
}
if ( V_54 ) {
if ( ! * V_52 )
* V_52 = V_54 ;
else
F_43 ( V_54 ) ;
++ V_55 ;
}
}
F_44 ( & V_4 -> V_12 , V_51 ) ;
F_10 (child_priv, &priv->child_intfs, list) {
V_55 += F_42 ( V_53 , V_49 ,
V_50 , V_25 ,
V_51 + 1 ,
V_52 ) ;
if ( V_55 > 1 )
break;
}
F_12 ( & V_4 -> V_12 ) ;
return V_55 ;
}
static int F_45 ( struct V_45 * V_57 , T_4 V_58 ,
T_3 V_50 ,
const union V_48 * V_49 ,
const struct V_24 * V_25 ,
struct V_1 * * V_54 )
{
struct V_3 * V_4 ;
int V_55 = 0 ;
* V_54 = NULL ;
F_10 (priv, dev_list, list) {
if ( V_4 -> V_58 != V_58 )
continue;
V_55 += F_42 ( V_4 , V_49 , V_50 ,
V_25 , 0 , V_54 ) ;
if ( V_55 > 1 )
break;
}
return V_55 ;
}
static struct V_1 * F_46 (
struct V_59 * V_2 , T_4 V_58 , T_3 V_60 ,
const union V_48 * V_49 , const struct V_24 * V_25 ,
void * V_61 )
{
struct V_1 * V_54 ;
struct V_45 * V_57 = V_61 ;
T_3 V_50 ;
int V_55 ;
int V_62 ;
if ( ! F_47 ( V_2 , V_58 ) )
return NULL ;
V_62 = F_48 ( V_2 , V_58 , V_60 , & V_50 ) ;
if ( V_62 )
return NULL ;
if ( ! V_57 )
return NULL ;
V_55 = F_45 ( V_57 , V_58 , V_50 ,
V_49 , NULL , & V_54 ) ;
switch ( V_55 ) {
case 0 :
return NULL ;
case 1 :
return V_54 ;
}
F_43 ( V_54 ) ;
V_55 = F_45 ( V_57 , V_58 , V_50 ,
V_49 , V_25 , & V_54 ) ;
switch ( V_55 ) {
case 0 :
return NULL ;
default:
F_49 ( & V_2 -> V_2 ,
L_4 ) ;
case 1 :
return V_54 ;
}
}
int F_50 ( struct V_1 * V_2 , const char * V_63 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
if ( F_51 ( V_2 -> V_64 ) && ! strcmp ( V_63 , L_5 ) ) {
F_5 ( V_16 , & V_4 -> V_6 ) ;
F_25 ( V_4 , L_6
L_7 ) ;
F_52 ( V_2 ) ;
F_53 ( V_2 , F_24 ( V_2 ) ) ;
F_54 () ;
V_4 -> V_65 . V_66 . V_67 &= ~ V_68 ;
F_55 ( V_2 ) ;
F_56 () ;
return 0 ;
}
if ( ! strcmp ( V_63 , L_8 ) ) {
F_15 ( V_16 , & V_4 -> V_6 ) ;
F_52 ( V_2 ) ;
F_53 ( V_2 , F_27 ( V_4 -> V_20 , V_2 -> V_21 ) ) ;
F_54 () ;
F_55 ( V_2 ) ;
F_56 () ;
return 0 ;
}
return - V_14 ;
}
static struct V_69 * F_57 ( struct V_1 * V_2 , void * V_49 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_70 * V_71 = V_4 -> V_72 . V_70 ;
struct V_69 * V_73 ;
int V_62 ;
while ( V_71 ) {
V_73 = F_58 ( V_71 , struct V_69 , V_70 ) ;
V_62 = memcmp ( V_49 , V_73 -> V_74 . V_75 . V_76 ,
sizeof ( union V_48 ) ) ;
if ( V_62 < 0 )
V_71 = V_71 -> V_77 ;
else if ( V_62 > 0 )
V_71 = V_71 -> V_78 ;
else
return V_73 ;
}
return NULL ;
}
static int F_59 ( struct V_1 * V_2 , struct V_69 * V_73 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_70 * * V_71 = & V_4 -> V_72 . V_70 ;
struct V_70 * V_79 = NULL ;
struct V_69 * V_80 ;
int V_62 ;
while ( * V_71 ) {
V_79 = * V_71 ;
V_80 = F_58 ( V_79 , struct V_69 , V_70 ) ;
V_62 = memcmp ( V_73 -> V_74 . V_75 . V_76 , V_80 -> V_74 . V_75 . V_76 ,
sizeof ( union V_48 ) ) ;
if ( V_62 < 0 )
V_71 = & V_79 -> V_77 ;
else if ( V_62 > 0 )
V_71 = & V_79 -> V_78 ;
else
return - V_81 ;
}
F_60 ( & V_73 -> V_70 , V_79 , V_71 ) ;
F_61 ( & V_73 -> V_70 , & V_4 -> V_72 ) ;
F_62 ( & V_73 -> V_82 , & V_4 -> V_83 ) ;
return 0 ;
}
static void F_63 ( struct V_1 * V_2 , struct V_69 * V_73 )
{
struct V_84 * V_85 ;
while ( ( V_85 = F_64 ( & V_73 -> V_86 ) ) )
F_65 ( V_85 ) ;
F_3 ( F_2 ( V_2 ) , L_9 ) ;
F_66 ( V_2 , V_73 -> V_74 . V_75 . V_76 ) ;
if ( V_73 -> V_87 )
F_67 ( V_73 -> V_87 ) ;
F_68 ( V_73 ) ;
}
struct V_88 * F_69 ( struct V_1 * V_2 )
{
struct V_88 * V_46 ;
V_46 = F_70 ( sizeof *V_46 , V_89 ) ;
if ( ! V_46 )
return NULL ;
V_46 -> V_2 = V_2 ;
memset ( V_46 -> V_73 . V_74 . V_75 . V_76 , 0 , 16 ) ;
if ( F_71 ( V_46 ) ) {
F_68 ( V_46 ) ;
return NULL ;
}
return V_46 ;
}
int F_71 ( struct V_88 * V_46 )
{
struct V_3 * V_4 = F_2 ( V_46 -> V_2 ) ;
struct V_70 * V_71 ;
struct V_69 * V_73 ;
int V_62 = 1 ;
F_72 ( & V_4 -> V_90 ) ;
V_71 = F_73 ( & V_4 -> V_72 ) ;
while ( V_71 ) {
V_73 = F_58 ( V_71 , struct V_69 , V_70 ) ;
if ( memcmp ( V_46 -> V_73 . V_74 . V_75 . V_76 , V_73 -> V_74 . V_75 . V_76 ,
sizeof ( union V_48 ) ) < 0 ) {
V_46 -> V_73 = * V_73 ;
V_62 = 0 ;
break;
}
V_71 = F_74 ( V_71 ) ;
}
F_75 ( & V_4 -> V_90 ) ;
return V_62 ;
}
void F_76 ( struct V_88 * V_46 ,
struct V_69 * V_73 )
{
* V_73 = V_46 -> V_73 ;
}
void F_77 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_69 * V_73 , * V_91 ;
F_72 ( & V_4 -> V_90 ) ;
F_78 (path, tp, &priv->path_list, list) {
F_3 ( V_4 , L_10 ,
F_79 ( V_73 -> V_74 . V_92 ) ,
V_73 -> V_74 . V_75 . V_76 ) ;
V_73 -> V_93 = 0 ;
}
F_75 ( & V_4 -> V_90 ) ;
}
void F_55 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_69 * V_73 , * V_91 ;
F_80 ( V_94 ) ;
unsigned long V_6 ;
F_81 ( V_2 ) ;
F_82 ( & V_4 -> V_90 , V_6 ) ;
F_83 ( & V_4 -> V_83 , & V_94 ) ;
F_10 (path, &remove_list, list)
F_84 ( & V_73 -> V_70 , & V_4 -> V_72 ) ;
F_78 (path, tp, &remove_list, list) {
if ( V_73 -> V_95 )
F_85 ( V_73 -> V_96 , V_73 -> V_95 ) ;
F_86 ( & V_4 -> V_90 , V_6 ) ;
F_87 ( V_2 ) ;
F_88 ( & V_73 -> V_97 ) ;
F_63 ( V_2 , V_73 ) ;
F_81 ( V_2 ) ;
F_82 ( & V_4 -> V_90 , V_6 ) ;
}
F_86 ( & V_4 -> V_90 , V_6 ) ;
F_87 ( V_2 ) ;
}
static void F_89 ( int V_98 ,
struct V_99 * V_74 ,
void * V_100 )
{
struct V_69 * V_73 = V_100 ;
struct V_1 * V_2 = V_73 -> V_2 ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_101 * V_87 = NULL ;
struct V_101 * V_102 = NULL ;
struct V_103 * V_104 , * V_105 ;
struct V_106 V_107 ;
struct V_84 * V_85 ;
unsigned long V_6 ;
if ( ! V_98 )
F_3 ( V_4 , L_11 ,
F_79 ( V_74 -> V_92 ) , V_74 -> V_75 . V_76 ) ;
else
F_3 ( V_4 , L_12 ,
V_98 , V_73 -> V_74 . V_75 . V_76 ) ;
F_90 ( & V_107 ) ;
if ( ! V_98 ) {
struct V_108 V_109 ;
if ( ! F_91 ( V_4 -> V_110 , V_4 -> V_58 , V_74 , & V_109 ) )
V_87 = F_92 ( V_2 , V_4 -> V_111 , & V_109 ) ;
}
F_82 ( & V_4 -> V_90 , V_6 ) ;
if ( ! F_93 ( V_87 ) ) {
V_73 -> V_74 = * V_74 ;
V_102 = V_73 -> V_87 ;
V_73 -> V_87 = V_87 ;
F_3 ( V_4 , L_13 ,
V_87 , F_79 ( V_74 -> V_92 ) , V_74 -> V_112 ) ;
while ( ( V_85 = F_64 ( & V_73 -> V_86 ) ) )
F_94 ( & V_107 , V_85 ) ;
F_78 (neigh, tn, &path->neigh_list, list) {
if ( V_104 -> V_87 ) {
F_95 ( V_104 -> V_87 != V_102 ) ;
F_67 ( V_104 -> V_87 ) ;
}
F_96 ( & V_73 -> V_87 -> V_113 ) ;
V_104 -> V_87 = V_73 -> V_87 ;
if ( F_97 ( V_2 , V_104 -> V_114 ) ) {
if ( ! F_98 ( V_104 ) )
F_99 ( V_104 , F_100 ( V_2 ,
V_73 ,
V_104 ) ) ;
if ( ! F_98 ( V_104 ) ) {
F_101 ( V_104 ) ;
continue;
}
}
while ( ( V_85 = F_64 ( & V_104 -> V_86 ) ) )
F_94 ( & V_107 , V_85 ) ;
}
V_73 -> V_93 = 1 ;
}
V_73 -> V_95 = NULL ;
F_102 ( & V_73 -> V_97 ) ;
F_86 ( & V_4 -> V_90 , V_6 ) ;
if ( F_93 ( V_87 ) )
F_66 ( V_2 , V_73 -> V_74 . V_75 . V_76 ) ;
if ( V_102 )
F_67 ( V_102 ) ;
while ( ( V_85 = F_64 ( & V_107 ) ) ) {
V_85 -> V_2 = V_2 ;
if ( F_103 ( V_85 ) )
F_25 ( V_4 , L_14
L_15 ) ;
}
}
static struct V_69 * F_104 ( struct V_1 * V_2 , void * V_49 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_69 * V_73 ;
if ( ! V_4 -> V_115 )
return NULL ;
V_73 = F_105 ( sizeof *V_73 , V_116 ) ;
if ( ! V_73 )
return NULL ;
V_73 -> V_2 = V_2 ;
F_90 ( & V_73 -> V_86 ) ;
F_106 ( & V_73 -> V_117 ) ;
memcpy ( V_73 -> V_74 . V_75 . V_76 , V_49 , sizeof ( union V_48 ) ) ;
V_73 -> V_74 . V_118 = V_4 -> V_56 ;
V_73 -> V_74 . V_60 = F_107 ( V_4 -> V_60 ) ;
V_73 -> V_74 . V_119 = 1 ;
V_73 -> V_74 . V_120 = V_4 -> V_115 -> V_121 . V_120 ;
return V_73 ;
}
static int F_108 ( struct V_1 * V_2 ,
struct V_69 * V_73 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
F_3 ( V_4 , L_16 ,
V_73 -> V_74 . V_75 . V_76 ) ;
F_109 ( & V_73 -> V_97 ) ;
V_73 -> V_96 =
F_110 ( & V_122 , V_4 -> V_110 , V_4 -> V_58 ,
& V_73 -> V_74 ,
V_123 |
V_124 |
V_125 |
V_126 |
V_127 ,
1000 , V_116 ,
F_89 ,
V_73 , & V_73 -> V_95 ) ;
if ( V_73 -> V_96 < 0 ) {
F_25 ( V_4 , L_17 , V_73 -> V_96 ) ;
V_73 -> V_95 = NULL ;
F_102 ( & V_73 -> V_97 ) ;
return V_73 -> V_96 ;
}
return 0 ;
}
static void F_111 ( struct V_84 * V_85 , T_4 * V_114 ,
struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_69 * V_73 ;
struct V_103 * V_104 ;
unsigned long V_6 ;
F_82 ( & V_4 -> V_90 , V_6 ) ;
V_104 = F_112 ( V_114 , V_2 ) ;
if ( ! V_104 ) {
F_86 ( & V_4 -> V_90 , V_6 ) ;
++ V_2 -> V_128 . V_129 ;
F_113 ( V_85 ) ;
return;
}
V_73 = F_57 ( V_2 , V_114 + 4 ) ;
if ( ! V_73 ) {
V_73 = F_104 ( V_2 , V_114 + 4 ) ;
if ( ! V_73 )
goto V_130;
F_59 ( V_2 , V_73 ) ;
}
F_62 ( & V_104 -> V_82 , & V_73 -> V_117 ) ;
if ( V_73 -> V_87 ) {
F_96 ( & V_73 -> V_87 -> V_113 ) ;
V_104 -> V_87 = V_73 -> V_87 ;
if ( F_97 ( V_2 , V_104 -> V_114 ) ) {
if ( ! F_98 ( V_104 ) )
F_99 ( V_104 , F_100 ( V_2 , V_73 , V_104 ) ) ;
if ( ! F_98 ( V_104 ) ) {
F_101 ( V_104 ) ;
goto V_131;
}
if ( F_114 ( & V_104 -> V_86 ) < V_132 )
F_94 ( & V_104 -> V_86 , V_85 ) ;
else {
F_25 ( V_4 , L_18 ,
F_114 ( & V_104 -> V_86 ) ) ;
goto V_131;
}
} else {
F_86 ( & V_4 -> V_90 , V_6 ) ;
F_115 ( V_2 , V_85 , V_73 -> V_87 , F_116 ( V_114 ) ) ;
F_117 ( V_104 ) ;
return;
}
} else {
V_104 -> V_87 = NULL ;
if ( ! V_73 -> V_95 && F_108 ( V_2 , V_73 ) )
goto V_130;
if ( F_114 ( & V_104 -> V_86 ) < V_132 )
F_94 ( & V_104 -> V_86 , V_85 ) ;
else
goto V_131;
}
F_86 ( & V_4 -> V_90 , V_6 ) ;
F_117 ( V_104 ) ;
return;
V_130:
F_101 ( V_104 ) ;
V_131:
++ V_2 -> V_128 . V_129 ;
F_113 ( V_85 ) ;
F_86 ( & V_4 -> V_90 , V_6 ) ;
F_117 ( V_104 ) ;
}
static void F_118 ( struct V_84 * V_85 , struct V_1 * V_2 ,
struct V_133 * V_134 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_69 * V_73 ;
unsigned long V_6 ;
F_82 ( & V_4 -> V_90 , V_6 ) ;
V_73 = F_57 ( V_2 , V_134 -> V_135 + 4 ) ;
if ( ! V_73 || ! V_73 -> V_93 ) {
int V_136 = 0 ;
if ( ! V_73 ) {
V_73 = F_104 ( V_2 , V_134 -> V_135 + 4 ) ;
V_136 = 1 ;
}
if ( V_73 ) {
if ( F_114 ( & V_73 -> V_86 ) < V_132 ) {
F_94 ( & V_73 -> V_86 , V_85 ) ;
} else {
++ V_2 -> V_128 . V_129 ;
F_113 ( V_85 ) ;
}
if ( ! V_73 -> V_95 && F_108 ( V_2 , V_73 ) ) {
F_86 ( & V_4 -> V_90 , V_6 ) ;
if ( V_136 )
F_63 ( V_2 , V_73 ) ;
return;
} else
F_59 ( V_2 , V_73 ) ;
} else {
++ V_2 -> V_128 . V_129 ;
F_113 ( V_85 ) ;
}
F_86 ( & V_4 -> V_90 , V_6 ) ;
return;
}
if ( V_73 -> V_87 ) {
F_3 ( V_4 , L_19 ,
F_79 ( V_73 -> V_74 . V_92 ) ) ;
F_86 ( & V_4 -> V_90 , V_6 ) ;
F_115 ( V_2 , V_85 , V_73 -> V_87 , F_116 ( V_134 -> V_135 ) ) ;
return;
} else if ( ( V_73 -> V_95 || ! F_108 ( V_2 , V_73 ) ) &&
F_114 ( & V_73 -> V_86 ) < V_132 ) {
F_94 ( & V_73 -> V_86 , V_85 ) ;
} else {
++ V_2 -> V_128 . V_129 ;
F_113 ( V_85 ) ;
}
F_86 ( & V_4 -> V_90 , V_6 ) ;
}
static int F_119 ( struct V_84 * V_85 , struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_103 * V_104 ;
struct V_133 * V_134 = F_120 ( V_85 ) ;
struct V_137 * V_138 ;
unsigned long V_6 ;
V_138 = (struct V_137 * ) V_85 -> V_139 ;
if ( F_121 ( V_134 -> V_135 [ 4 ] == 0xff ) ) {
if ( ( V_138 -> V_140 != F_122 ( V_141 ) ) &&
( V_138 -> V_140 != F_122 ( V_142 ) ) &&
( V_138 -> V_140 != F_122 ( V_143 ) ) &&
( V_138 -> V_140 != F_122 ( V_144 ) ) &&
( V_138 -> V_140 != F_122 ( V_145 ) ) ) {
++ V_2 -> V_128 . V_129 ;
F_113 ( V_85 ) ;
return V_146 ;
}
V_134 -> V_135 [ 8 ] = ( V_4 -> V_60 >> 8 ) & 0xff ;
V_134 -> V_135 [ 9 ] = V_4 -> V_60 & 0xff ;
V_104 = F_123 ( V_2 , V_134 -> V_135 ) ;
if ( F_124 ( V_104 ) )
goto V_147;
F_125 ( V_2 , V_134 -> V_135 , V_85 ) ;
return V_146 ;
}
switch ( V_138 -> V_140 ) {
case F_122 ( V_141 ) :
case F_122 ( V_142 ) :
case F_122 ( V_145 ) :
V_104 = F_123 ( V_2 , V_134 -> V_135 ) ;
if ( F_121 ( ! V_104 ) ) {
F_111 ( V_85 , V_134 -> V_135 , V_2 ) ;
return V_146 ;
}
break;
case F_122 ( V_143 ) :
case F_122 ( V_144 ) :
F_118 ( V_85 , V_2 , V_134 ) ;
return V_146 ;
default:
++ V_2 -> V_128 . V_129 ;
F_113 ( V_85 ) ;
return V_146 ;
}
V_147:
if ( F_98 ( V_104 ) ) {
if ( F_126 ( V_104 ) ) {
F_127 ( V_2 , V_85 , F_98 ( V_104 ) ) ;
goto V_148;
}
} else if ( V_104 -> V_87 ) {
F_115 ( V_2 , V_85 , V_104 -> V_87 , F_116 ( V_134 -> V_135 ) ) ;
goto V_148;
}
if ( F_114 ( & V_104 -> V_86 ) < V_132 ) {
F_82 ( & V_4 -> V_90 , V_6 ) ;
F_94 ( & V_104 -> V_86 , V_85 ) ;
F_86 ( & V_4 -> V_90 , V_6 ) ;
} else {
++ V_2 -> V_128 . V_129 ;
F_113 ( V_85 ) ;
}
V_148:
F_117 ( V_104 ) ;
return V_146 ;
}
static void F_128 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
F_25 ( V_4 , L_20 ,
F_129 ( V_149 - V_2 -> V_150 ) ) ;
F_25 ( V_4 , L_21 ,
F_130 ( V_2 ) ,
V_4 -> V_151 , V_4 -> V_152 ) ;
}
static int F_131 ( struct V_84 * V_85 ,
struct V_1 * V_2 ,
unsigned short type ,
const void * V_114 , const void * V_153 , unsigned V_154 )
{
struct V_137 * V_138 ;
struct V_133 * V_134 = F_120 ( V_85 ) ;
V_138 = (struct V_137 * ) F_132 ( V_85 , sizeof *V_138 ) ;
V_138 -> V_140 = F_122 ( type ) ;
V_138 -> V_155 = 0 ;
memcpy ( V_134 -> V_135 , V_114 , V_156 ) ;
return sizeof *V_138 ;
}
static void F_133 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
if ( ! F_7 ( V_157 , & V_4 -> V_6 ) ) {
F_3 ( V_4 , L_22 ) ;
return;
}
F_134 ( V_4 -> V_158 , & V_4 -> V_159 ) ;
}
static int F_135 ( const struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
if ( ! F_7 ( V_10 , & V_4 -> V_6 ) )
return V_2 -> V_160 ;
return V_4 -> V_161 -> V_160 ;
}
static T_5 F_136 ( struct V_162 * V_163 , T_4 * V_114 )
{
T_5 * V_164 = ( T_5 * ) V_114 ;
T_5 V_165 ;
V_165 = F_137 ( V_164 [ 3 ] , V_164 [ 4 ] , V_166 & V_164 [ 0 ] , 0 ) ;
return V_165 & V_163 -> V_167 ;
}
struct V_103 * F_123 ( struct V_1 * V_2 , T_4 * V_114 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_168 * V_169 = & V_4 -> V_169 ;
struct V_162 * V_163 ;
struct V_103 * V_104 = NULL ;
T_5 V_170 ;
F_138 () ;
V_163 = F_139 ( V_169 -> V_163 ) ;
if ( ! V_163 )
goto V_171;
V_170 = F_136 ( V_163 , V_114 ) ;
for ( V_104 = F_139 ( V_163 -> V_172 [ V_170 ] ) ;
V_104 != NULL ;
V_104 = F_139 ( V_104 -> V_173 ) ) {
if ( memcmp ( V_114 , V_104 -> V_114 , V_156 ) == 0 ) {
if ( ! F_140 ( & V_104 -> V_174 ) ) {
V_104 = NULL ;
goto V_171;
}
V_104 -> V_175 = V_149 ;
goto V_171;
}
}
V_171:
F_141 () ;
return V_104 ;
}
static void F_142 ( struct V_3 * V_4 )
{
struct V_168 * V_169 = & V_4 -> V_169 ;
struct V_162 * V_163 ;
unsigned long V_176 ;
unsigned long V_177 ;
unsigned long V_6 ;
int V_178 ;
F_80 ( V_94 ) ;
if ( F_7 ( V_179 , & V_4 -> V_6 ) )
return;
F_82 ( & V_4 -> V_90 , V_6 ) ;
V_163 = F_143 ( V_169 -> V_163 ,
F_144 ( & V_4 -> V_90 ) ) ;
if ( ! V_163 )
goto V_171;
V_177 = 2 * V_180 . V_181 ;
V_176 = V_149 - V_177 ;
if ( F_7 ( V_179 , & V_4 -> V_6 ) )
goto V_171;
for ( V_178 = 0 ; V_178 < V_163 -> V_182 ; V_178 ++ ) {
struct V_103 * V_104 ;
struct V_103 T_6 * * V_183 = & V_163 -> V_172 [ V_178 ] ;
while ( ( V_104 = F_143 ( * V_183 ,
F_144 ( & V_4 -> V_90 ) ) ) != NULL ) {
if ( F_145 ( V_176 , V_104 -> V_175 ) ) {
F_146 ( V_4 , V_104 -> V_114 + 4 , & V_94 ) ;
F_147 ( * V_183 ,
F_143 ( V_104 -> V_173 ,
F_144 ( & V_4 -> V_90 ) ) ) ;
F_148 ( & V_104 -> V_82 ) ;
F_149 ( & V_104 -> V_184 , V_185 ) ;
} else {
V_183 = & V_104 -> V_173 ;
}
}
}
V_171:
F_86 ( & V_4 -> V_90 , V_6 ) ;
F_150 ( & V_94 ) ;
}
static void F_151 ( struct V_186 * V_187 )
{
struct V_3 * V_4 =
F_152 ( V_187 , struct V_3 , V_188 . V_187 ) ;
F_142 ( V_4 ) ;
if ( ! F_7 ( V_179 , & V_4 -> V_6 ) )
F_153 ( V_4 -> V_158 , & V_4 -> V_188 ,
V_180 . V_181 ) ;
}
static struct V_103 * F_154 ( T_4 * V_114 ,
struct V_1 * V_2 )
{
struct V_103 * V_104 ;
V_104 = F_105 ( sizeof *V_104 , V_116 ) ;
if ( ! V_104 )
return NULL ;
V_104 -> V_2 = V_2 ;
memcpy ( & V_104 -> V_114 , V_114 , sizeof( V_104 -> V_114 ) ) ;
F_90 ( & V_104 -> V_86 ) ;
F_106 ( & V_104 -> V_82 ) ;
F_99 ( V_104 , NULL ) ;
F_155 ( & V_104 -> V_174 , 1 ) ;
return V_104 ;
}
struct V_103 * F_112 ( T_4 * V_114 ,
struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_168 * V_169 = & V_4 -> V_169 ;
struct V_162 * V_163 ;
struct V_103 * V_104 ;
T_5 V_170 ;
V_163 = F_143 ( V_169 -> V_163 ,
F_144 ( & V_4 -> V_90 ) ) ;
if ( ! V_163 ) {
V_104 = NULL ;
goto V_171;
}
V_170 = F_136 ( V_163 , V_114 ) ;
for ( V_104 = F_143 ( V_163 -> V_172 [ V_170 ] ,
F_144 ( & V_4 -> V_90 ) ) ;
V_104 != NULL ;
V_104 = F_143 ( V_104 -> V_173 ,
F_144 ( & V_4 -> V_90 ) ) ) {
if ( memcmp ( V_114 , V_104 -> V_114 , V_156 ) == 0 ) {
if ( ! F_140 ( & V_104 -> V_174 ) ) {
V_104 = NULL ;
break;
}
V_104 -> V_175 = V_149 ;
goto V_171;
}
}
V_104 = F_154 ( V_114 , V_2 ) ;
if ( ! V_104 )
goto V_171;
F_156 ( & V_104 -> V_174 ) ;
V_104 -> V_175 = V_149 ;
F_147 ( V_104 -> V_173 ,
F_143 ( V_163 -> V_172 [ V_170 ] ,
F_144 ( & V_4 -> V_90 ) ) ) ;
F_147 ( V_163 -> V_172 [ V_170 ] , V_104 ) ;
F_156 ( & V_169 -> V_189 ) ;
V_171:
return V_104 ;
}
void F_157 ( struct V_103 * V_104 )
{
struct V_1 * V_2 = V_104 -> V_2 ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_84 * V_85 ;
if ( V_104 -> V_87 )
F_67 ( V_104 -> V_87 ) ;
while ( ( V_85 = F_64 ( & V_104 -> V_86 ) ) ) {
++ V_2 -> V_128 . V_129 ;
F_113 ( V_85 ) ;
}
if ( F_98 ( V_104 ) )
F_158 ( F_98 ( V_104 ) ) ;
F_3 ( F_2 ( V_2 ) ,
L_23 ,
F_116 ( V_104 -> V_114 ) ,
V_104 -> V_114 + 4 ) ;
F_68 ( V_104 ) ;
if ( F_159 ( & V_4 -> V_169 . V_189 ) ) {
if ( F_7 ( V_190 , & V_4 -> V_6 ) )
F_102 ( & V_4 -> V_169 . V_191 ) ;
}
}
static void V_185 ( struct V_192 * V_193 )
{
struct V_103 * V_104 = F_152 ( V_193 , struct V_103 , V_184 ) ;
F_117 ( V_104 ) ;
}
void F_101 ( struct V_103 * V_104 )
{
struct V_1 * V_2 = V_104 -> V_2 ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_168 * V_169 = & V_4 -> V_169 ;
struct V_162 * V_163 ;
struct V_103 T_6 * * V_183 ;
struct V_103 * V_71 ;
T_5 V_170 ;
V_163 = F_143 ( V_169 -> V_163 ,
F_144 ( & V_4 -> V_90 ) ) ;
if ( ! V_163 )
return;
V_170 = F_136 ( V_163 , V_104 -> V_114 ) ;
V_183 = & V_163 -> V_172 [ V_170 ] ;
for ( V_71 = F_143 ( * V_183 ,
F_144 ( & V_4 -> V_90 ) ) ;
V_71 != NULL ;
V_71 = F_143 ( * V_183 ,
F_144 ( & V_4 -> V_90 ) ) ) {
if ( V_71 == V_104 ) {
F_147 ( * V_183 ,
F_143 ( V_104 -> V_173 ,
F_144 ( & V_4 -> V_90 ) ) ) ;
F_148 ( & V_104 -> V_82 ) ;
F_149 ( & V_104 -> V_184 , V_185 ) ;
return;
} else {
V_183 = & V_71 -> V_173 ;
}
}
}
static int F_160 ( struct V_3 * V_4 )
{
struct V_168 * V_169 = & V_4 -> V_169 ;
struct V_162 * V_163 ;
struct V_103 T_6 * * V_172 ;
T_5 V_182 ;
F_15 ( V_190 , & V_4 -> V_6 ) ;
V_169 -> V_163 = NULL ;
V_163 = F_105 ( sizeof( * V_163 ) , V_89 ) ;
if ( ! V_163 )
return - V_194 ;
F_5 ( V_179 , & V_4 -> V_6 ) ;
V_182 = F_161 ( V_180 . V_195 ) ;
V_172 = F_105 ( V_182 * sizeof( * V_172 ) , V_89 ) ;
if ( ! V_172 ) {
F_68 ( V_163 ) ;
return - V_194 ;
}
V_163 -> V_182 = V_182 ;
V_163 -> V_167 = ( V_182 - 1 ) ;
V_163 -> V_172 = V_172 ;
F_162 ( V_169 -> V_163 , V_163 ) ;
V_163 -> V_169 = V_169 ;
F_155 ( & V_169 -> V_189 , 0 ) ;
F_15 ( V_179 , & V_4 -> V_6 ) ;
F_153 ( V_4 -> V_158 , & V_4 -> V_188 ,
V_180 . V_181 ) ;
return 0 ;
}
static void F_163 ( struct V_192 * V_196 )
{
struct V_162 * V_163 = F_152 ( V_196 ,
struct V_162 ,
V_184 ) ;
struct V_103 T_6 * * V_172 = V_163 -> V_172 ;
struct V_168 * V_169 = V_163 -> V_169 ;
F_68 ( V_172 ) ;
F_68 ( V_163 ) ;
F_102 ( & V_169 -> V_197 ) ;
}
void F_66 ( struct V_1 * V_2 , T_4 * V_49 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_168 * V_169 = & V_4 -> V_169 ;
struct V_162 * V_163 ;
unsigned long V_6 ;
int V_178 ;
F_82 ( & V_4 -> V_90 , V_6 ) ;
V_163 = F_143 ( V_169 -> V_163 ,
F_144 ( & V_4 -> V_90 ) ) ;
if ( ! V_163 )
goto V_171;
for ( V_178 = 0 ; V_178 < V_163 -> V_182 ; V_178 ++ ) {
struct V_103 * V_104 ;
struct V_103 T_6 * * V_183 = & V_163 -> V_172 [ V_178 ] ;
while ( ( V_104 = F_143 ( * V_183 ,
F_144 ( & V_4 -> V_90 ) ) ) != NULL ) {
if ( ! memcmp ( V_49 , V_104 -> V_114 + 4 , sizeof ( union V_48 ) ) ) {
F_147 ( * V_183 ,
F_143 ( V_104 -> V_173 ,
F_144 ( & V_4 -> V_90 ) ) ) ;
F_148 ( & V_104 -> V_82 ) ;
F_149 ( & V_104 -> V_184 , V_185 ) ;
} else {
V_183 = & V_104 -> V_173 ;
}
}
}
V_171:
F_86 ( & V_4 -> V_90 , V_6 ) ;
}
static void F_164 ( struct V_3 * V_4 )
{
struct V_168 * V_169 = & V_4 -> V_169 ;
struct V_162 * V_163 ;
unsigned long V_6 ;
int V_178 , V_198 = 0 ;
F_109 ( & V_4 -> V_169 . V_191 ) ;
F_82 ( & V_4 -> V_90 , V_6 ) ;
V_163 = F_143 ( V_169 -> V_163 ,
F_144 ( & V_4 -> V_90 ) ) ;
if ( ! V_163 )
goto V_171;
V_198 = F_165 ( & V_4 -> V_169 . V_189 ) ;
if ( ! V_198 )
goto V_199;
for ( V_178 = 0 ; V_178 < V_163 -> V_182 ; V_178 ++ ) {
struct V_103 * V_104 ;
struct V_103 T_6 * * V_183 = & V_163 -> V_172 [ V_178 ] ;
while ( ( V_104 = F_143 ( * V_183 ,
F_144 ( & V_4 -> V_90 ) ) ) != NULL ) {
F_147 ( * V_183 ,
F_143 ( V_104 -> V_173 ,
F_144 ( & V_4 -> V_90 ) ) ) ;
F_148 ( & V_104 -> V_82 ) ;
F_149 ( & V_104 -> V_184 , V_185 ) ;
}
}
V_199:
F_147 ( V_169 -> V_163 , NULL ) ;
F_149 ( & V_163 -> V_184 , F_163 ) ;
V_171:
F_86 ( & V_4 -> V_90 , V_6 ) ;
if ( V_198 )
F_88 ( & V_4 -> V_169 . V_191 ) ;
}
static void F_166 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_200 ;
F_3 ( V_4 , L_24 ) ;
F_109 ( & V_4 -> V_169 . V_197 ) ;
F_5 ( V_190 , & V_4 -> V_6 ) ;
V_200 = F_167 ( V_179 , & V_4 -> V_6 ) ;
if ( ! V_200 )
F_168 ( & V_4 -> V_188 ) ;
F_164 ( V_4 ) ;
F_88 ( & V_4 -> V_169 . V_197 ) ;
}
int F_169 ( struct V_1 * V_2 , struct V_59 * V_110 , int V_58 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
V_4 -> V_201 = F_105 ( V_202 * sizeof * V_4 -> V_201 ,
V_89 ) ;
if ( ! V_4 -> V_201 ) {
F_170 ( V_203 L_25 ,
V_110 -> V_204 , V_202 ) ;
goto V_47;
}
V_4 -> V_205 = F_171 ( V_206 * sizeof * V_4 -> V_205 ) ;
if ( ! V_4 -> V_205 ) {
F_170 ( V_203 L_26 ,
V_110 -> V_204 , V_206 ) ;
goto V_207;
}
if ( F_172 ( V_2 , V_110 , V_58 ) )
goto V_208;
if ( F_160 ( V_4 ) < 0 )
goto V_209;
return 0 ;
V_209:
F_173 ( V_2 ) ;
V_208:
F_174 ( V_4 -> V_205 ) ;
V_207:
F_68 ( V_4 -> V_201 ) ;
V_47:
return - V_194 ;
}
void F_20 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) , * V_11 , * V_210 ;
F_80 ( V_196 ) ;
F_175 () ;
F_176 ( V_2 ) ;
F_78 (cpriv, tcpriv, &priv->child_intfs, list) {
F_5 ( V_179 , & V_11 -> V_6 ) ;
F_168 ( & V_11 -> V_188 ) ;
F_177 ( V_11 -> V_2 , & V_196 ) ;
}
F_178 ( & V_196 ) ;
F_166 ( V_2 ) ;
F_173 ( V_2 ) ;
F_68 ( V_4 -> V_201 ) ;
F_174 ( V_4 -> V_205 ) ;
V_4 -> V_201 = NULL ;
V_4 -> V_205 = NULL ;
}
static int F_179 ( struct V_1 * V_2 , int V_211 , int V_212 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
return F_180 ( V_4 -> V_110 , V_211 , V_4 -> V_58 , V_212 ) ;
}
static int F_181 ( struct V_1 * V_2 , int V_211 ,
struct V_213 * V_214 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_215 ;
V_215 = F_182 ( V_4 -> V_110 , V_211 , V_4 -> V_58 , V_214 ) ;
if ( V_215 )
return V_215 ;
V_214 -> V_211 = V_211 ;
return 0 ;
}
static int F_183 ( struct V_1 * V_2 , int V_211 , T_7 V_216 , int type )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
if ( type != V_217 && type != V_218 )
return - V_14 ;
return F_184 ( V_4 -> V_110 , V_211 , V_4 -> V_58 , V_216 , type ) ;
}
static int F_185 ( struct V_1 * V_2 , int V_211 ,
struct V_219 * V_220 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
return F_186 ( V_4 -> V_110 , V_211 , V_4 -> V_58 , V_220 ) ;
}
void F_187 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
if ( V_4 -> V_221 & V_222 )
V_2 -> V_223 = & V_224 ;
else
V_2 -> V_223 = & V_225 ;
V_2 -> V_226 = & V_227 ;
F_188 ( V_2 ) ;
F_189 ( V_2 , & V_4 -> V_228 , V_229 , V_230 ) ;
V_2 -> V_231 = V_232 ;
V_2 -> V_6 |= V_233 | V_234 ;
V_2 -> V_235 = V_236 ;
V_2 -> V_237 = V_156 ;
V_2 -> type = V_238 ;
V_2 -> V_239 = V_206 * 2 ;
V_2 -> V_15 = ( V_240 |
V_241 ) ;
F_190 ( V_2 ) ;
memcpy ( V_2 -> V_115 , V_242 , V_156 ) ;
V_4 -> V_2 = V_2 ;
F_191 ( & V_4 -> V_90 ) ;
F_192 ( & V_4 -> V_12 ) ;
F_106 ( & V_4 -> V_83 ) ;
F_106 ( & V_4 -> V_243 ) ;
F_106 ( & V_4 -> V_244 ) ;
F_106 ( & V_4 -> V_245 ) ;
F_193 ( & V_4 -> V_246 , V_247 ) ;
F_194 ( & V_4 -> V_248 , V_249 ) ;
F_194 ( & V_4 -> V_250 , V_251 ) ;
F_194 ( & V_4 -> V_252 , V_253 ) ;
F_194 ( & V_4 -> V_254 , V_255 ) ;
F_194 ( & V_4 -> V_159 , V_256 ) ;
F_193 ( & V_4 -> V_257 , V_258 ) ;
F_193 ( & V_4 -> V_188 , F_151 ) ;
}
struct V_3 * F_195 ( const char * V_204 )
{
struct V_1 * V_2 ;
V_2 = F_196 ( ( int ) sizeof( struct V_3 ) , V_204 ,
V_259 , F_187 ) ;
if ( ! V_2 )
return NULL ;
return F_2 ( V_2 ) ;
}
static T_8 F_197 ( struct V_260 * V_2 ,
struct V_261 * V_262 , char * V_63 )
{
struct V_3 * V_4 = F_2 ( F_198 ( V_2 ) ) ;
return sprintf ( V_63 , L_27 , V_4 -> V_60 ) ;
}
static T_8 F_199 ( struct V_260 * V_2 ,
struct V_261 * V_262 , char * V_63 )
{
struct V_3 * V_4 = F_2 ( F_198 ( V_2 ) ) ;
return sprintf ( V_63 , L_28 , F_7 ( V_263 , & V_4 -> V_6 ) ) ;
}
void F_200 ( struct V_1 * V_264 , int V_265 )
{
struct V_3 * V_4 = F_2 ( V_264 ) ;
if ( V_265 > 0 ) {
F_5 ( V_263 , & V_4 -> V_6 ) ;
F_25 ( V_4 , L_29
L_30 ) ;
} else
F_15 ( V_263 , & V_4 -> V_6 ) ;
}
static T_8 F_201 ( struct V_260 * V_2 ,
struct V_261 * V_262 ,
const char * V_63 , T_9 V_266 )
{
unsigned long V_265 = F_202 ( V_63 , NULL , 0 ) ;
F_200 ( F_198 ( V_2 ) , V_265 ) ;
return V_266 ;
}
int F_203 ( struct V_1 * V_2 )
{
return F_204 ( & V_2 -> V_2 , & V_267 ) ;
}
static T_8 F_205 ( struct V_260 * V_2 ,
struct V_261 * V_262 ,
const char * V_63 , T_9 V_266 )
{
int V_60 ;
int V_62 ;
if ( sscanf ( V_63 , L_31 , & V_60 ) != 1 )
return - V_14 ;
if ( V_60 <= 0 || V_60 > 0xffff || V_60 == 0x8000 )
return - V_14 ;
V_60 |= 0x8000 ;
V_62 = F_206 ( F_198 ( V_2 ) , V_60 ) ;
return V_62 ? V_62 : V_266 ;
}
static T_8 F_207 ( struct V_260 * V_2 ,
struct V_261 * V_262 ,
const char * V_63 , T_9 V_266 )
{
int V_60 ;
int V_62 ;
if ( sscanf ( V_63 , L_31 , & V_60 ) != 1 )
return - V_14 ;
if ( V_60 < 0 || V_60 > 0xffff )
return - V_14 ;
V_62 = F_208 ( F_198 ( V_2 ) , V_60 ) ;
return V_62 ? V_62 : V_266 ;
}
int F_209 ( struct V_1 * V_2 )
{
return F_204 ( & V_2 -> V_2 , & V_268 ) ;
}
int F_210 ( struct V_3 * V_4 , struct V_59 * V_269 )
{
V_4 -> V_221 = V_269 -> V_270 . V_271 ;
if ( V_4 -> V_221 & V_272 ) {
V_4 -> V_2 -> V_273 = V_274 |
V_17 | V_275 ;
if ( V_4 -> V_221 & V_276 )
V_4 -> V_2 -> V_273 |= V_18 ;
V_4 -> V_2 -> V_15 |= V_4 -> V_2 -> V_273 ;
}
return 0 ;
}
static struct V_1 * F_211 ( const char * V_277 ,
struct V_59 * V_269 , T_4 V_58 )
{
struct V_3 * V_4 ;
struct V_278 V_262 ;
int V_44 = - V_194 ;
V_4 = F_195 ( V_277 ) ;
if ( ! V_4 )
goto V_279;
F_212 ( V_4 -> V_2 , V_269 -> V_280 ) ;
V_4 -> V_2 -> V_281 = V_58 - 1 ;
V_44 = F_213 ( V_269 , V_58 , & V_262 ) ;
if ( ! V_44 )
V_4 -> V_22 = F_214 ( V_262 . V_282 ) ;
else {
F_170 ( V_203 L_32 ,
V_269 -> V_204 , V_58 ) ;
goto V_283;
}
V_4 -> V_2 -> V_21 = F_26 ( V_4 -> V_22 ) ;
V_4 -> V_20 = V_4 -> V_23 = V_4 -> V_2 -> V_21 ;
V_4 -> V_2 -> V_284 = sizeof( struct V_103 ) ;
V_44 = F_215 ( V_269 , V_58 , 0 , & V_4 -> V_60 ) ;
if ( V_44 ) {
F_170 ( V_203 L_33 ,
V_269 -> V_204 , V_58 , V_44 ) ;
goto V_283;
}
V_44 = F_210 ( V_4 , V_269 ) ;
if ( V_44 )
goto V_283;
V_4 -> V_60 |= 0x8000 ;
V_4 -> V_2 -> V_115 [ 8 ] = V_4 -> V_60 >> 8 ;
V_4 -> V_2 -> V_115 [ 9 ] = V_4 -> V_60 & 0xff ;
V_44 = F_216 ( V_269 , V_58 , 0 , & V_4 -> V_56 , NULL ) ;
if ( V_44 ) {
F_170 ( V_203 L_34 ,
V_269 -> V_204 , V_58 , V_44 ) ;
goto V_283;
} else
memcpy ( V_4 -> V_2 -> V_64 + 4 , V_4 -> V_56 . V_76 , sizeof ( union V_48 ) ) ;
V_44 = F_169 ( V_4 -> V_2 , V_269 , V_58 ) ;
if ( V_44 < 0 ) {
F_170 ( V_203 L_35 ,
V_269 -> V_204 , V_58 , V_44 ) ;
goto V_283;
}
F_217 ( & V_4 -> V_285 ,
V_4 -> V_110 , V_286 ) ;
V_44 = F_218 ( & V_4 -> V_285 ) ;
if ( V_44 < 0 ) {
F_170 ( V_203 L_36
L_37 ,
V_269 -> V_204 , V_58 , V_44 ) ;
goto V_287;
}
V_44 = F_219 ( V_4 -> V_2 ) ;
if ( V_44 ) {
F_170 ( V_203 L_38 ,
V_269 -> V_204 , V_58 , V_44 ) ;
goto V_288;
}
F_220 ( V_4 -> V_2 ) ;
if ( F_221 ( V_4 -> V_2 ) )
goto V_289;
if ( F_209 ( V_4 -> V_2 ) )
goto V_289;
if ( F_203 ( V_4 -> V_2 ) )
goto V_289;
if ( F_204 ( & V_4 -> V_2 -> V_2 , & V_290 ) )
goto V_289;
if ( F_204 ( & V_4 -> V_2 -> V_2 , & V_291 ) )
goto V_289;
return V_4 -> V_2 ;
V_289:
F_176 ( V_4 -> V_2 ) ;
F_222 ( V_4 -> V_2 ) ;
V_288:
F_223 ( & V_4 -> V_285 ) ;
F_224 ( V_292 ) ;
F_5 ( V_179 , & V_4 -> V_6 ) ;
F_168 ( & V_4 -> V_188 ) ;
F_224 ( V_4 -> V_158 ) ;
V_287:
F_20 ( V_4 -> V_2 ) ;
V_283:
F_225 ( V_4 -> V_2 ) ;
V_279:
return F_226 ( V_44 ) ;
}
static void F_227 ( struct V_59 * V_260 )
{
struct V_45 * V_57 ;
struct V_1 * V_2 ;
struct V_3 * V_4 ;
int V_293 ;
int V_266 = 0 ;
V_57 = F_70 ( sizeof *V_57 , V_89 ) ;
if ( ! V_57 )
return;
F_106 ( V_57 ) ;
for ( V_293 = F_228 ( V_260 ) ; V_293 <= F_229 ( V_260 ) ; ++ V_293 ) {
if ( ! F_47 ( V_260 , V_293 ) )
continue;
V_2 = F_211 ( L_39 , V_260 , V_293 ) ;
if ( ! F_230 ( V_2 ) ) {
V_4 = F_2 ( V_2 ) ;
F_62 ( & V_4 -> V_82 , V_57 ) ;
V_266 ++ ;
}
}
if ( ! V_266 ) {
F_68 ( V_57 ) ;
return;
}
F_231 ( V_260 , & V_294 , V_57 ) ;
}
static void F_232 ( struct V_59 * V_260 , void * V_61 )
{
struct V_3 * V_4 , * V_295 ;
struct V_45 * V_57 = V_61 ;
if ( ! V_57 )
return;
F_78 (priv, tmp, dev_list, list) {
F_223 ( & V_4 -> V_285 ) ;
F_224 ( V_292 ) ;
F_56 () ;
F_11 ( V_4 -> V_2 , V_4 -> V_2 -> V_6 & ~ V_13 ) ;
F_54 () ;
F_5 ( V_179 , & V_4 -> V_6 ) ;
F_168 ( & V_4 -> V_188 ) ;
F_224 ( V_4 -> V_158 ) ;
F_222 ( V_4 -> V_2 ) ;
F_225 ( V_4 -> V_2 ) ;
}
F_68 ( V_57 ) ;
}
static int T_10 F_233 ( void )
{
int V_62 ;
V_202 = F_161 ( V_202 ) ;
V_202 = F_27 ( V_202 , V_296 ) ;
V_202 = F_234 ( V_202 , V_297 ) ;
V_206 = F_161 ( V_206 ) ;
V_206 = F_27 ( V_206 , V_296 ) ;
V_206 = F_235 ( V_206 , 2 * V_298 , V_297 ) ;
#ifdef F_236
V_299 = F_27 ( V_299 , V_300 ) ;
#endif
F_237 ( V_301 > V_302 ) ;
V_62 = F_238 () ;
if ( V_62 )
return V_62 ;
V_292 = F_239 ( L_40 ) ;
if ( ! V_292 ) {
V_62 = - V_194 ;
goto V_303;
}
F_240 ( & V_122 ) ;
V_62 = F_241 ( & V_294 ) ;
if ( V_62 )
goto V_304;
V_62 = F_242 () ;
if ( V_62 )
goto V_305;
return 0 ;
V_305:
F_243 ( & V_294 ) ;
V_304:
F_244 ( & V_122 ) ;
F_245 ( V_292 ) ;
V_303:
F_246 () ;
return V_62 ;
}
static void T_11 F_247 ( void )
{
F_248 () ;
F_243 ( & V_294 ) ;
F_244 ( & V_122 ) ;
F_246 () ;
F_245 ( V_292 ) ;
}
