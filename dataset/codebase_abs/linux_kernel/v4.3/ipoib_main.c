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
V_4 -> V_65 . V_66 &= ~ V_67 ;
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
static struct V_68 * F_57 ( struct V_1 * V_2 , void * V_49 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_69 * V_70 = V_4 -> V_71 . V_69 ;
struct V_68 * V_72 ;
int V_62 ;
while ( V_70 ) {
V_72 = F_58 ( V_70 , struct V_68 , V_69 ) ;
V_62 = memcmp ( V_49 , V_72 -> V_73 . V_74 . V_75 ,
sizeof ( union V_48 ) ) ;
if ( V_62 < 0 )
V_70 = V_70 -> V_76 ;
else if ( V_62 > 0 )
V_70 = V_70 -> V_77 ;
else
return V_72 ;
}
return NULL ;
}
static int F_59 ( struct V_1 * V_2 , struct V_68 * V_72 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_69 * * V_70 = & V_4 -> V_71 . V_69 ;
struct V_69 * V_78 = NULL ;
struct V_68 * V_79 ;
int V_62 ;
while ( * V_70 ) {
V_78 = * V_70 ;
V_79 = F_58 ( V_78 , struct V_68 , V_69 ) ;
V_62 = memcmp ( V_72 -> V_73 . V_74 . V_75 , V_79 -> V_73 . V_74 . V_75 ,
sizeof ( union V_48 ) ) ;
if ( V_62 < 0 )
V_70 = & V_78 -> V_76 ;
else if ( V_62 > 0 )
V_70 = & V_78 -> V_77 ;
else
return - V_80 ;
}
F_60 ( & V_72 -> V_69 , V_78 , V_70 ) ;
F_61 ( & V_72 -> V_69 , & V_4 -> V_71 ) ;
F_62 ( & V_72 -> V_81 , & V_4 -> V_82 ) ;
return 0 ;
}
static void F_63 ( struct V_1 * V_2 , struct V_68 * V_72 )
{
struct V_83 * V_84 ;
while ( ( V_84 = F_64 ( & V_72 -> V_85 ) ) )
F_65 ( V_84 ) ;
F_3 ( F_2 ( V_2 ) , L_9 ) ;
F_66 ( V_2 , V_72 -> V_73 . V_74 . V_75 ) ;
if ( V_72 -> V_86 )
F_67 ( V_72 -> V_86 ) ;
F_68 ( V_72 ) ;
}
struct V_87 * F_69 ( struct V_1 * V_2 )
{
struct V_87 * V_46 ;
V_46 = F_70 ( sizeof *V_46 , V_88 ) ;
if ( ! V_46 )
return NULL ;
V_46 -> V_2 = V_2 ;
memset ( V_46 -> V_72 . V_73 . V_74 . V_75 , 0 , 16 ) ;
if ( F_71 ( V_46 ) ) {
F_68 ( V_46 ) ;
return NULL ;
}
return V_46 ;
}
int F_71 ( struct V_87 * V_46 )
{
struct V_3 * V_4 = F_2 ( V_46 -> V_2 ) ;
struct V_69 * V_70 ;
struct V_68 * V_72 ;
int V_62 = 1 ;
F_72 ( & V_4 -> V_89 ) ;
V_70 = F_73 ( & V_4 -> V_71 ) ;
while ( V_70 ) {
V_72 = F_58 ( V_70 , struct V_68 , V_69 ) ;
if ( memcmp ( V_46 -> V_72 . V_73 . V_74 . V_75 , V_72 -> V_73 . V_74 . V_75 ,
sizeof ( union V_48 ) ) < 0 ) {
V_46 -> V_72 = * V_72 ;
V_62 = 0 ;
break;
}
V_70 = F_74 ( V_70 ) ;
}
F_75 ( & V_4 -> V_89 ) ;
return V_62 ;
}
void F_76 ( struct V_87 * V_46 ,
struct V_68 * V_72 )
{
* V_72 = V_46 -> V_72 ;
}
void F_77 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_68 * V_72 , * V_90 ;
F_72 ( & V_4 -> V_89 ) ;
F_78 (path, tp, &priv->path_list, list) {
F_3 ( V_4 , L_10 ,
F_79 ( V_72 -> V_73 . V_91 ) ,
V_72 -> V_73 . V_74 . V_75 ) ;
V_72 -> V_92 = 0 ;
}
F_75 ( & V_4 -> V_89 ) ;
}
void F_55 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_68 * V_72 , * V_90 ;
F_80 ( V_93 ) ;
unsigned long V_6 ;
F_81 ( V_2 ) ;
F_82 ( & V_4 -> V_89 , V_6 ) ;
F_83 ( & V_4 -> V_82 , & V_93 ) ;
F_10 (path, &remove_list, list)
F_84 ( & V_72 -> V_69 , & V_4 -> V_71 ) ;
F_78 (path, tp, &remove_list, list) {
if ( V_72 -> V_94 )
F_85 ( V_72 -> V_95 , V_72 -> V_94 ) ;
F_86 ( & V_4 -> V_89 , V_6 ) ;
F_87 ( V_2 ) ;
F_88 ( & V_72 -> V_96 ) ;
F_63 ( V_2 , V_72 ) ;
F_81 ( V_2 ) ;
F_82 ( & V_4 -> V_89 , V_6 ) ;
}
F_86 ( & V_4 -> V_89 , V_6 ) ;
F_87 ( V_2 ) ;
}
static void F_89 ( int V_97 ,
struct V_98 * V_73 ,
void * V_99 )
{
struct V_68 * V_72 = V_99 ;
struct V_1 * V_2 = V_72 -> V_2 ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_100 * V_86 = NULL ;
struct V_100 * V_101 = NULL ;
struct V_102 * V_103 , * V_104 ;
struct V_105 V_106 ;
struct V_83 * V_84 ;
unsigned long V_6 ;
if ( ! V_97 )
F_3 ( V_4 , L_11 ,
F_79 ( V_73 -> V_91 ) , V_73 -> V_74 . V_75 ) ;
else
F_3 ( V_4 , L_12 ,
V_97 , V_72 -> V_73 . V_74 . V_75 ) ;
F_90 ( & V_106 ) ;
if ( ! V_97 ) {
struct V_107 V_108 ;
if ( ! F_91 ( V_4 -> V_109 , V_4 -> V_58 , V_73 , & V_108 ) )
V_86 = F_92 ( V_2 , V_4 -> V_110 , & V_108 ) ;
}
F_82 ( & V_4 -> V_89 , V_6 ) ;
if ( ! F_93 ( V_86 ) ) {
V_72 -> V_73 = * V_73 ;
V_101 = V_72 -> V_86 ;
V_72 -> V_86 = V_86 ;
F_3 ( V_4 , L_13 ,
V_86 , F_79 ( V_73 -> V_91 ) , V_73 -> V_111 ) ;
while ( ( V_84 = F_64 ( & V_72 -> V_85 ) ) )
F_94 ( & V_106 , V_84 ) ;
F_78 (neigh, tn, &path->neigh_list, list) {
if ( V_103 -> V_86 ) {
F_95 ( V_103 -> V_86 != V_101 ) ;
F_67 ( V_103 -> V_86 ) ;
}
F_96 ( & V_72 -> V_86 -> V_112 ) ;
V_103 -> V_86 = V_72 -> V_86 ;
if ( F_97 ( V_2 , V_103 -> V_113 ) ) {
if ( ! F_98 ( V_103 ) )
F_99 ( V_103 , F_100 ( V_2 ,
V_72 ,
V_103 ) ) ;
if ( ! F_98 ( V_103 ) ) {
F_101 ( V_103 ) ;
continue;
}
}
while ( ( V_84 = F_64 ( & V_103 -> V_85 ) ) )
F_94 ( & V_106 , V_84 ) ;
}
V_72 -> V_92 = 1 ;
}
V_72 -> V_94 = NULL ;
F_102 ( & V_72 -> V_96 ) ;
F_86 ( & V_4 -> V_89 , V_6 ) ;
if ( F_93 ( V_86 ) )
F_66 ( V_2 , V_72 -> V_73 . V_74 . V_75 ) ;
if ( V_101 )
F_67 ( V_101 ) ;
while ( ( V_84 = F_64 ( & V_106 ) ) ) {
V_84 -> V_2 = V_2 ;
if ( F_103 ( V_84 ) )
F_25 ( V_4 , L_14
L_15 ) ;
}
}
static struct V_68 * F_104 ( struct V_1 * V_2 , void * V_49 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_68 * V_72 ;
if ( ! V_4 -> V_114 )
return NULL ;
V_72 = F_105 ( sizeof *V_72 , V_115 ) ;
if ( ! V_72 )
return NULL ;
V_72 -> V_2 = V_2 ;
F_90 ( & V_72 -> V_85 ) ;
F_106 ( & V_72 -> V_116 ) ;
memcpy ( V_72 -> V_73 . V_74 . V_75 , V_49 , sizeof ( union V_48 ) ) ;
V_72 -> V_73 . V_117 = V_4 -> V_56 ;
V_72 -> V_73 . V_60 = F_107 ( V_4 -> V_60 ) ;
V_72 -> V_73 . V_118 = 1 ;
V_72 -> V_73 . V_119 = V_4 -> V_114 -> V_120 . V_119 ;
return V_72 ;
}
static int F_108 ( struct V_1 * V_2 ,
struct V_68 * V_72 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
F_3 ( V_4 , L_16 ,
V_72 -> V_73 . V_74 . V_75 ) ;
F_109 ( & V_72 -> V_96 ) ;
V_72 -> V_95 =
F_110 ( & V_121 , V_4 -> V_109 , V_4 -> V_58 ,
& V_72 -> V_73 ,
V_122 |
V_123 |
V_124 |
V_125 |
V_126 ,
1000 , V_115 ,
F_89 ,
V_72 , & V_72 -> V_94 ) ;
if ( V_72 -> V_95 < 0 ) {
F_25 ( V_4 , L_17 , V_72 -> V_95 ) ;
V_72 -> V_94 = NULL ;
F_102 ( & V_72 -> V_96 ) ;
return V_72 -> V_95 ;
}
return 0 ;
}
static void F_111 ( struct V_83 * V_84 , T_4 * V_113 ,
struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_68 * V_72 ;
struct V_102 * V_103 ;
unsigned long V_6 ;
F_82 ( & V_4 -> V_89 , V_6 ) ;
V_103 = F_112 ( V_113 , V_2 ) ;
if ( ! V_103 ) {
F_86 ( & V_4 -> V_89 , V_6 ) ;
++ V_2 -> V_127 . V_128 ;
F_113 ( V_84 ) ;
return;
}
V_72 = F_57 ( V_2 , V_113 + 4 ) ;
if ( ! V_72 ) {
V_72 = F_104 ( V_2 , V_113 + 4 ) ;
if ( ! V_72 )
goto V_129;
F_59 ( V_2 , V_72 ) ;
}
F_62 ( & V_103 -> V_81 , & V_72 -> V_116 ) ;
if ( V_72 -> V_86 ) {
F_96 ( & V_72 -> V_86 -> V_112 ) ;
V_103 -> V_86 = V_72 -> V_86 ;
if ( F_97 ( V_2 , V_103 -> V_113 ) ) {
if ( ! F_98 ( V_103 ) )
F_99 ( V_103 , F_100 ( V_2 , V_72 , V_103 ) ) ;
if ( ! F_98 ( V_103 ) ) {
F_101 ( V_103 ) ;
goto V_130;
}
if ( F_114 ( & V_103 -> V_85 ) < V_131 )
F_94 ( & V_103 -> V_85 , V_84 ) ;
else {
F_25 ( V_4 , L_18 ,
F_114 ( & V_103 -> V_85 ) ) ;
goto V_130;
}
} else {
F_86 ( & V_4 -> V_89 , V_6 ) ;
F_115 ( V_2 , V_84 , V_72 -> V_86 , F_116 ( V_113 ) ) ;
F_117 ( V_103 ) ;
return;
}
} else {
V_103 -> V_86 = NULL ;
if ( ! V_72 -> V_94 && F_108 ( V_2 , V_72 ) )
goto V_129;
if ( F_114 ( & V_103 -> V_85 ) < V_131 )
F_94 ( & V_103 -> V_85 , V_84 ) ;
else
goto V_130;
}
F_86 ( & V_4 -> V_89 , V_6 ) ;
F_117 ( V_103 ) ;
return;
V_129:
F_101 ( V_103 ) ;
V_130:
++ V_2 -> V_127 . V_128 ;
F_113 ( V_84 ) ;
F_86 ( & V_4 -> V_89 , V_6 ) ;
F_117 ( V_103 ) ;
}
static void F_118 ( struct V_83 * V_84 , struct V_1 * V_2 ,
struct V_132 * V_133 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_68 * V_72 ;
unsigned long V_6 ;
F_82 ( & V_4 -> V_89 , V_6 ) ;
V_72 = F_57 ( V_2 , V_133 -> V_134 + 4 ) ;
if ( ! V_72 || ! V_72 -> V_92 ) {
int V_135 = 0 ;
if ( ! V_72 ) {
V_72 = F_104 ( V_2 , V_133 -> V_134 + 4 ) ;
V_135 = 1 ;
}
if ( V_72 ) {
if ( F_114 ( & V_72 -> V_85 ) < V_131 ) {
F_94 ( & V_72 -> V_85 , V_84 ) ;
} else {
++ V_2 -> V_127 . V_128 ;
F_113 ( V_84 ) ;
}
if ( ! V_72 -> V_94 && F_108 ( V_2 , V_72 ) ) {
F_86 ( & V_4 -> V_89 , V_6 ) ;
if ( V_135 )
F_63 ( V_2 , V_72 ) ;
return;
} else
F_59 ( V_2 , V_72 ) ;
} else {
++ V_2 -> V_127 . V_128 ;
F_113 ( V_84 ) ;
}
F_86 ( & V_4 -> V_89 , V_6 ) ;
return;
}
if ( V_72 -> V_86 ) {
F_3 ( V_4 , L_19 ,
F_79 ( V_72 -> V_73 . V_91 ) ) ;
F_86 ( & V_4 -> V_89 , V_6 ) ;
F_115 ( V_2 , V_84 , V_72 -> V_86 , F_116 ( V_133 -> V_134 ) ) ;
return;
} else if ( ( V_72 -> V_94 || ! F_108 ( V_2 , V_72 ) ) &&
F_114 ( & V_72 -> V_85 ) < V_131 ) {
F_94 ( & V_72 -> V_85 , V_84 ) ;
} else {
++ V_2 -> V_127 . V_128 ;
F_113 ( V_84 ) ;
}
F_86 ( & V_4 -> V_89 , V_6 ) ;
}
static int F_119 ( struct V_83 * V_84 , struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_102 * V_103 ;
struct V_132 * V_133 = F_120 ( V_84 ) ;
struct V_136 * V_137 ;
unsigned long V_6 ;
V_137 = (struct V_136 * ) V_84 -> V_138 ;
if ( F_121 ( V_133 -> V_134 [ 4 ] == 0xff ) ) {
if ( ( V_137 -> V_139 != F_122 ( V_140 ) ) &&
( V_137 -> V_139 != F_122 ( V_141 ) ) &&
( V_137 -> V_139 != F_122 ( V_142 ) ) &&
( V_137 -> V_139 != F_122 ( V_143 ) ) &&
( V_137 -> V_139 != F_122 ( V_144 ) ) ) {
++ V_2 -> V_127 . V_128 ;
F_113 ( V_84 ) ;
return V_145 ;
}
V_133 -> V_134 [ 8 ] = ( V_4 -> V_60 >> 8 ) & 0xff ;
V_133 -> V_134 [ 9 ] = V_4 -> V_60 & 0xff ;
V_103 = F_123 ( V_2 , V_133 -> V_134 ) ;
if ( F_124 ( V_103 ) )
goto V_146;
F_125 ( V_2 , V_133 -> V_134 , V_84 ) ;
return V_145 ;
}
switch ( V_137 -> V_139 ) {
case F_122 ( V_140 ) :
case F_122 ( V_141 ) :
case F_122 ( V_144 ) :
V_103 = F_123 ( V_2 , V_133 -> V_134 ) ;
if ( F_121 ( ! V_103 ) ) {
F_111 ( V_84 , V_133 -> V_134 , V_2 ) ;
return V_145 ;
}
break;
case F_122 ( V_142 ) :
case F_122 ( V_143 ) :
F_118 ( V_84 , V_2 , V_133 ) ;
return V_145 ;
default:
++ V_2 -> V_127 . V_128 ;
F_113 ( V_84 ) ;
return V_145 ;
}
V_146:
if ( F_98 ( V_103 ) ) {
if ( F_126 ( V_103 ) ) {
F_127 ( V_2 , V_84 , F_98 ( V_103 ) ) ;
goto V_147;
}
} else if ( V_103 -> V_86 ) {
F_115 ( V_2 , V_84 , V_103 -> V_86 , F_116 ( V_133 -> V_134 ) ) ;
goto V_147;
}
if ( F_114 ( & V_103 -> V_85 ) < V_131 ) {
F_82 ( & V_4 -> V_89 , V_6 ) ;
F_94 ( & V_103 -> V_85 , V_84 ) ;
F_86 ( & V_4 -> V_89 , V_6 ) ;
} else {
++ V_2 -> V_127 . V_128 ;
F_113 ( V_84 ) ;
}
V_147:
F_117 ( V_103 ) ;
return V_145 ;
}
static void F_128 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
F_25 ( V_4 , L_20 ,
F_129 ( V_148 - V_2 -> V_149 ) ) ;
F_25 ( V_4 , L_21 ,
F_130 ( V_2 ) ,
V_4 -> V_150 , V_4 -> V_151 ) ;
}
static int F_131 ( struct V_83 * V_84 ,
struct V_1 * V_2 ,
unsigned short type ,
const void * V_113 , const void * V_152 , unsigned V_153 )
{
struct V_136 * V_137 ;
struct V_132 * V_133 = F_120 ( V_84 ) ;
V_137 = (struct V_136 * ) F_132 ( V_84 , sizeof *V_137 ) ;
V_137 -> V_139 = F_122 ( type ) ;
V_137 -> V_154 = 0 ;
memcpy ( V_133 -> V_134 , V_113 , V_155 ) ;
return sizeof *V_137 ;
}
static void F_133 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
if ( ! F_7 ( V_156 , & V_4 -> V_6 ) ) {
F_3 ( V_4 , L_22 ) ;
return;
}
F_134 ( V_4 -> V_157 , & V_4 -> V_158 ) ;
}
static int F_135 ( const struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
if ( ! F_7 ( V_10 , & V_4 -> V_6 ) )
return V_2 -> V_159 ;
return V_4 -> V_160 -> V_159 ;
}
static T_5 F_136 ( struct V_161 * V_162 , T_4 * V_113 )
{
T_5 * V_163 = ( T_5 * ) V_113 ;
T_5 V_164 ;
V_164 = F_137 ( V_163 [ 3 ] , V_163 [ 4 ] , V_165 & V_163 [ 0 ] , 0 ) ;
return V_164 & V_162 -> V_166 ;
}
struct V_102 * F_123 ( struct V_1 * V_2 , T_4 * V_113 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_167 * V_168 = & V_4 -> V_168 ;
struct V_161 * V_162 ;
struct V_102 * V_103 = NULL ;
T_5 V_169 ;
F_138 () ;
V_162 = F_139 ( V_168 -> V_162 ) ;
if ( ! V_162 )
goto V_170;
V_169 = F_136 ( V_162 , V_113 ) ;
for ( V_103 = F_139 ( V_162 -> V_171 [ V_169 ] ) ;
V_103 != NULL ;
V_103 = F_139 ( V_103 -> V_172 ) ) {
if ( memcmp ( V_113 , V_103 -> V_113 , V_155 ) == 0 ) {
if ( ! F_140 ( & V_103 -> V_173 ) ) {
V_103 = NULL ;
goto V_170;
}
V_103 -> V_174 = V_148 ;
goto V_170;
}
}
V_170:
F_141 () ;
return V_103 ;
}
static void F_142 ( struct V_3 * V_4 )
{
struct V_167 * V_168 = & V_4 -> V_168 ;
struct V_161 * V_162 ;
unsigned long V_175 ;
unsigned long V_176 ;
unsigned long V_6 ;
int V_177 ;
F_80 ( V_93 ) ;
struct V_178 * V_179 , * V_180 ;
struct V_1 * V_2 = V_4 -> V_2 ;
if ( F_7 ( V_181 , & V_4 -> V_6 ) )
return;
F_82 ( & V_4 -> V_89 , V_6 ) ;
V_162 = F_143 ( V_168 -> V_162 ,
F_144 ( & V_4 -> V_89 ) ) ;
if ( ! V_162 )
goto V_170;
V_176 = 2 * V_182 . V_183 ;
V_175 = V_148 - V_176 ;
if ( F_7 ( V_181 , & V_4 -> V_6 ) )
goto V_170;
for ( V_177 = 0 ; V_177 < V_162 -> V_184 ; V_177 ++ ) {
struct V_102 * V_103 ;
struct V_102 T_6 * * V_185 = & V_162 -> V_171 [ V_177 ] ;
while ( ( V_103 = F_143 ( * V_185 ,
F_144 ( & V_4 -> V_89 ) ) ) != NULL ) {
if ( F_145 ( V_175 , V_103 -> V_174 ) ) {
T_4 * V_186 = V_103 -> V_113 + 4 ;
if ( * V_186 == 0xff ) {
V_179 = F_146 ( V_2 , V_186 ) ;
if ( V_179 && F_7 ( V_187 , & V_179 -> V_6 ) ) {
F_147 ( & V_179 -> V_81 ) ;
F_84 ( & V_179 -> V_69 , & V_4 -> V_188 ) ;
F_62 ( & V_179 -> V_81 , & V_93 ) ;
}
}
F_148 ( * V_185 ,
F_143 ( V_103 -> V_172 ,
F_144 ( & V_4 -> V_89 ) ) ) ;
F_147 ( & V_103 -> V_81 ) ;
F_149 ( & V_103 -> V_189 , V_190 ) ;
} else {
V_185 = & V_103 -> V_172 ;
}
}
}
V_170:
F_86 ( & V_4 -> V_89 , V_6 ) ;
F_78 (mcast, tmcast, &remove_list, list) {
F_150 ( V_2 , V_179 ) ;
F_151 ( V_179 ) ;
}
}
static void F_152 ( struct V_191 * V_192 )
{
struct V_3 * V_4 =
F_153 ( V_192 , struct V_3 , V_193 . V_192 ) ;
F_142 ( V_4 ) ;
if ( ! F_7 ( V_181 , & V_4 -> V_6 ) )
F_154 ( V_4 -> V_157 , & V_4 -> V_193 ,
V_182 . V_183 ) ;
}
static struct V_102 * F_155 ( T_4 * V_113 ,
struct V_1 * V_2 )
{
struct V_102 * V_103 ;
V_103 = F_105 ( sizeof *V_103 , V_115 ) ;
if ( ! V_103 )
return NULL ;
V_103 -> V_2 = V_2 ;
memcpy ( & V_103 -> V_113 , V_113 , sizeof( V_103 -> V_113 ) ) ;
F_90 ( & V_103 -> V_85 ) ;
F_106 ( & V_103 -> V_81 ) ;
F_99 ( V_103 , NULL ) ;
F_156 ( & V_103 -> V_173 , 1 ) ;
return V_103 ;
}
struct V_102 * F_112 ( T_4 * V_113 ,
struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_167 * V_168 = & V_4 -> V_168 ;
struct V_161 * V_162 ;
struct V_102 * V_103 ;
T_5 V_169 ;
V_162 = F_143 ( V_168 -> V_162 ,
F_144 ( & V_4 -> V_89 ) ) ;
if ( ! V_162 ) {
V_103 = NULL ;
goto V_170;
}
V_169 = F_136 ( V_162 , V_113 ) ;
for ( V_103 = F_143 ( V_162 -> V_171 [ V_169 ] ,
F_144 ( & V_4 -> V_89 ) ) ;
V_103 != NULL ;
V_103 = F_143 ( V_103 -> V_172 ,
F_144 ( & V_4 -> V_89 ) ) ) {
if ( memcmp ( V_113 , V_103 -> V_113 , V_155 ) == 0 ) {
if ( ! F_140 ( & V_103 -> V_173 ) ) {
V_103 = NULL ;
break;
}
V_103 -> V_174 = V_148 ;
goto V_170;
}
}
V_103 = F_155 ( V_113 , V_2 ) ;
if ( ! V_103 )
goto V_170;
F_157 ( & V_103 -> V_173 ) ;
V_103 -> V_174 = V_148 ;
F_148 ( V_103 -> V_172 ,
F_143 ( V_162 -> V_171 [ V_169 ] ,
F_144 ( & V_4 -> V_89 ) ) ) ;
F_148 ( V_162 -> V_171 [ V_169 ] , V_103 ) ;
F_157 ( & V_168 -> V_194 ) ;
V_170:
return V_103 ;
}
void F_158 ( struct V_102 * V_103 )
{
struct V_1 * V_2 = V_103 -> V_2 ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_83 * V_84 ;
if ( V_103 -> V_86 )
F_67 ( V_103 -> V_86 ) ;
while ( ( V_84 = F_64 ( & V_103 -> V_85 ) ) ) {
++ V_2 -> V_127 . V_128 ;
F_113 ( V_84 ) ;
}
if ( F_98 ( V_103 ) )
F_159 ( F_98 ( V_103 ) ) ;
F_3 ( F_2 ( V_2 ) ,
L_23 ,
F_116 ( V_103 -> V_113 ) ,
V_103 -> V_113 + 4 ) ;
F_68 ( V_103 ) ;
if ( F_160 ( & V_4 -> V_168 . V_194 ) ) {
if ( F_7 ( V_195 , & V_4 -> V_6 ) )
F_102 ( & V_4 -> V_168 . V_196 ) ;
}
}
static void V_190 ( struct V_197 * V_198 )
{
struct V_102 * V_103 = F_153 ( V_198 , struct V_102 , V_189 ) ;
F_117 ( V_103 ) ;
}
void F_101 ( struct V_102 * V_103 )
{
struct V_1 * V_2 = V_103 -> V_2 ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_167 * V_168 = & V_4 -> V_168 ;
struct V_161 * V_162 ;
struct V_102 T_6 * * V_185 ;
struct V_102 * V_70 ;
T_5 V_169 ;
V_162 = F_143 ( V_168 -> V_162 ,
F_144 ( & V_4 -> V_89 ) ) ;
if ( ! V_162 )
return;
V_169 = F_136 ( V_162 , V_103 -> V_113 ) ;
V_185 = & V_162 -> V_171 [ V_169 ] ;
for ( V_70 = F_143 ( * V_185 ,
F_144 ( & V_4 -> V_89 ) ) ;
V_70 != NULL ;
V_70 = F_143 ( * V_185 ,
F_144 ( & V_4 -> V_89 ) ) ) {
if ( V_70 == V_103 ) {
F_148 ( * V_185 ,
F_143 ( V_103 -> V_172 ,
F_144 ( & V_4 -> V_89 ) ) ) ;
F_147 ( & V_103 -> V_81 ) ;
F_149 ( & V_103 -> V_189 , V_190 ) ;
return;
} else {
V_185 = & V_70 -> V_172 ;
}
}
}
static int F_161 ( struct V_3 * V_4 )
{
struct V_167 * V_168 = & V_4 -> V_168 ;
struct V_161 * V_162 ;
struct V_102 T_6 * * V_171 ;
T_5 V_184 ;
F_15 ( V_195 , & V_4 -> V_6 ) ;
V_168 -> V_162 = NULL ;
V_162 = F_105 ( sizeof( * V_162 ) , V_88 ) ;
if ( ! V_162 )
return - V_199 ;
F_5 ( V_181 , & V_4 -> V_6 ) ;
V_184 = F_162 ( V_182 . V_200 ) ;
V_171 = F_105 ( V_184 * sizeof( * V_171 ) , V_88 ) ;
if ( ! V_171 ) {
F_68 ( V_162 ) ;
return - V_199 ;
}
V_162 -> V_184 = V_184 ;
V_162 -> V_166 = ( V_184 - 1 ) ;
V_162 -> V_171 = V_171 ;
F_163 ( V_168 -> V_162 , V_162 ) ;
V_162 -> V_168 = V_168 ;
F_156 ( & V_168 -> V_194 , 0 ) ;
F_15 ( V_181 , & V_4 -> V_6 ) ;
F_154 ( V_4 -> V_157 , & V_4 -> V_193 ,
V_182 . V_183 ) ;
return 0 ;
}
static void F_164 ( struct V_197 * V_201 )
{
struct V_161 * V_162 = F_153 ( V_201 ,
struct V_161 ,
V_189 ) ;
struct V_102 T_6 * * V_171 = V_162 -> V_171 ;
struct V_167 * V_168 = V_162 -> V_168 ;
F_68 ( V_171 ) ;
F_68 ( V_162 ) ;
F_102 ( & V_168 -> V_202 ) ;
}
void F_66 ( struct V_1 * V_2 , T_4 * V_49 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_167 * V_168 = & V_4 -> V_168 ;
struct V_161 * V_162 ;
unsigned long V_6 ;
int V_177 ;
F_82 ( & V_4 -> V_89 , V_6 ) ;
V_162 = F_143 ( V_168 -> V_162 ,
F_144 ( & V_4 -> V_89 ) ) ;
if ( ! V_162 )
goto V_170;
for ( V_177 = 0 ; V_177 < V_162 -> V_184 ; V_177 ++ ) {
struct V_102 * V_103 ;
struct V_102 T_6 * * V_185 = & V_162 -> V_171 [ V_177 ] ;
while ( ( V_103 = F_143 ( * V_185 ,
F_144 ( & V_4 -> V_89 ) ) ) != NULL ) {
if ( ! memcmp ( V_49 , V_103 -> V_113 + 4 , sizeof ( union V_48 ) ) ) {
F_148 ( * V_185 ,
F_143 ( V_103 -> V_172 ,
F_144 ( & V_4 -> V_89 ) ) ) ;
F_147 ( & V_103 -> V_81 ) ;
F_149 ( & V_103 -> V_189 , V_190 ) ;
} else {
V_185 = & V_103 -> V_172 ;
}
}
}
V_170:
F_86 ( & V_4 -> V_89 , V_6 ) ;
}
static void F_165 ( struct V_3 * V_4 )
{
struct V_167 * V_168 = & V_4 -> V_168 ;
struct V_161 * V_162 ;
unsigned long V_6 ;
int V_177 , V_203 = 0 ;
F_109 ( & V_4 -> V_168 . V_196 ) ;
F_82 ( & V_4 -> V_89 , V_6 ) ;
V_162 = F_143 ( V_168 -> V_162 ,
F_144 ( & V_4 -> V_89 ) ) ;
if ( ! V_162 )
goto V_170;
V_203 = F_166 ( & V_4 -> V_168 . V_194 ) ;
if ( ! V_203 )
goto V_204;
for ( V_177 = 0 ; V_177 < V_162 -> V_184 ; V_177 ++ ) {
struct V_102 * V_103 ;
struct V_102 T_6 * * V_185 = & V_162 -> V_171 [ V_177 ] ;
while ( ( V_103 = F_143 ( * V_185 ,
F_144 ( & V_4 -> V_89 ) ) ) != NULL ) {
F_148 ( * V_185 ,
F_143 ( V_103 -> V_172 ,
F_144 ( & V_4 -> V_89 ) ) ) ;
F_147 ( & V_103 -> V_81 ) ;
F_149 ( & V_103 -> V_189 , V_190 ) ;
}
}
V_204:
F_148 ( V_168 -> V_162 , NULL ) ;
F_149 ( & V_162 -> V_189 , F_164 ) ;
V_170:
F_86 ( & V_4 -> V_89 , V_6 ) ;
if ( V_203 )
F_88 ( & V_4 -> V_168 . V_196 ) ;
}
static void F_167 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_205 ;
F_3 ( V_4 , L_24 ) ;
F_109 ( & V_4 -> V_168 . V_202 ) ;
F_5 ( V_195 , & V_4 -> V_6 ) ;
V_205 = F_168 ( V_181 , & V_4 -> V_6 ) ;
if ( ! V_205 )
F_169 ( & V_4 -> V_193 ) ;
F_165 ( V_4 ) ;
F_88 ( & V_4 -> V_168 . V_202 ) ;
}
int F_170 ( struct V_1 * V_2 , struct V_59 * V_109 , int V_58 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
V_4 -> V_206 = F_105 ( V_207 * sizeof * V_4 -> V_206 ,
V_88 ) ;
if ( ! V_4 -> V_206 ) {
F_171 ( V_208 L_25 ,
V_109 -> V_209 , V_207 ) ;
goto V_47;
}
V_4 -> V_210 = F_172 ( V_211 * sizeof * V_4 -> V_210 ) ;
if ( ! V_4 -> V_210 ) {
F_171 ( V_208 L_26 ,
V_109 -> V_209 , V_211 ) ;
goto V_212;
}
if ( F_173 ( V_2 , V_109 , V_58 ) )
goto V_213;
if ( F_161 ( V_4 ) < 0 )
goto V_214;
return 0 ;
V_214:
F_174 ( V_2 ) ;
V_213:
F_175 ( V_4 -> V_210 ) ;
V_212:
F_68 ( V_4 -> V_206 ) ;
V_47:
return - V_199 ;
}
void F_20 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) , * V_11 , * V_215 ;
F_80 ( V_201 ) ;
F_176 () ;
F_177 ( V_2 ) ;
F_78 (cpriv, tcpriv, &priv->child_intfs, list) {
F_5 ( V_181 , & V_11 -> V_6 ) ;
F_169 ( & V_11 -> V_193 ) ;
F_178 ( V_11 -> V_2 , & V_201 ) ;
}
F_179 ( & V_201 ) ;
F_167 ( V_2 ) ;
F_174 ( V_2 ) ;
F_68 ( V_4 -> V_206 ) ;
F_175 ( V_4 -> V_210 ) ;
V_4 -> V_206 = NULL ;
V_4 -> V_210 = NULL ;
}
void F_180 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
V_2 -> V_216 = & V_217 ;
V_2 -> V_218 = & V_219 ;
F_181 ( V_2 ) ;
F_182 ( V_2 , & V_4 -> V_220 , V_221 , V_222 ) ;
V_2 -> V_223 = V_224 ;
V_2 -> V_6 |= V_225 | V_226 ;
V_2 -> V_227 = V_228 ;
V_2 -> V_229 = V_155 ;
V_2 -> type = V_230 ;
V_2 -> V_231 = V_211 * 2 ;
V_2 -> V_15 = ( V_232 |
V_233 ) ;
F_183 ( V_2 ) ;
memcpy ( V_2 -> V_114 , V_234 , V_155 ) ;
V_4 -> V_2 = V_2 ;
F_184 ( & V_4 -> V_89 ) ;
F_185 ( & V_4 -> V_12 ) ;
F_106 ( & V_4 -> V_82 ) ;
F_106 ( & V_4 -> V_235 ) ;
F_106 ( & V_4 -> V_236 ) ;
F_106 ( & V_4 -> V_237 ) ;
F_186 ( & V_4 -> V_238 , V_239 ) ;
F_187 ( & V_4 -> V_240 , V_241 ) ;
F_187 ( & V_4 -> V_242 , V_243 ) ;
F_187 ( & V_4 -> V_244 , V_245 ) ;
F_187 ( & V_4 -> V_246 , V_247 ) ;
F_187 ( & V_4 -> V_158 , V_248 ) ;
F_186 ( & V_4 -> V_249 , V_250 ) ;
F_186 ( & V_4 -> V_193 , F_152 ) ;
}
struct V_3 * F_188 ( const char * V_209 )
{
struct V_1 * V_2 ;
V_2 = F_189 ( ( int ) sizeof( struct V_3 ) , V_209 ,
V_251 , F_180 ) ;
if ( ! V_2 )
return NULL ;
return F_2 ( V_2 ) ;
}
static T_7 F_190 ( struct V_252 * V_2 ,
struct V_253 * V_254 , char * V_63 )
{
struct V_3 * V_4 = F_2 ( F_191 ( V_2 ) ) ;
return sprintf ( V_63 , L_27 , V_4 -> V_60 ) ;
}
static T_7 F_192 ( struct V_252 * V_2 ,
struct V_253 * V_254 , char * V_63 )
{
struct V_3 * V_4 = F_2 ( F_191 ( V_2 ) ) ;
return sprintf ( V_63 , L_28 , F_7 ( V_255 , & V_4 -> V_6 ) ) ;
}
void F_193 ( struct V_1 * V_256 , int V_257 )
{
struct V_3 * V_4 = F_2 ( V_256 ) ;
if ( V_257 > 0 ) {
F_5 ( V_255 , & V_4 -> V_6 ) ;
F_25 ( V_4 , L_29
L_30 ) ;
} else
F_15 ( V_255 , & V_4 -> V_6 ) ;
}
static T_7 F_194 ( struct V_252 * V_2 ,
struct V_253 * V_254 ,
const char * V_63 , T_8 V_258 )
{
unsigned long V_257 = F_195 ( V_63 , NULL , 0 ) ;
F_193 ( F_191 ( V_2 ) , V_257 ) ;
return V_258 ;
}
int F_196 ( struct V_1 * V_2 )
{
return F_197 ( & V_2 -> V_2 , & V_259 ) ;
}
static T_7 F_198 ( struct V_252 * V_2 ,
struct V_253 * V_254 ,
const char * V_63 , T_8 V_258 )
{
int V_60 ;
int V_62 ;
if ( sscanf ( V_63 , L_31 , & V_60 ) != 1 )
return - V_14 ;
if ( V_60 <= 0 || V_60 > 0xffff || V_60 == 0x8000 )
return - V_14 ;
V_60 |= 0x8000 ;
V_62 = F_199 ( F_191 ( V_2 ) , V_60 ) ;
return V_62 ? V_62 : V_258 ;
}
static T_7 F_200 ( struct V_252 * V_2 ,
struct V_253 * V_254 ,
const char * V_63 , T_8 V_258 )
{
int V_60 ;
int V_62 ;
if ( sscanf ( V_63 , L_31 , & V_60 ) != 1 )
return - V_14 ;
if ( V_60 < 0 || V_60 > 0xffff )
return - V_14 ;
V_62 = F_201 ( F_191 ( V_2 ) , V_60 ) ;
return V_62 ? V_62 : V_258 ;
}
int F_202 ( struct V_1 * V_2 )
{
return F_197 ( & V_2 -> V_2 , & V_260 ) ;
}
int F_203 ( struct V_3 * V_4 , struct V_59 * V_261 )
{
struct V_262 * V_263 ;
int V_44 = - V_199 ;
V_263 = F_70 ( sizeof *V_263 , V_88 ) ;
if ( ! V_263 ) {
F_171 ( V_208 L_32 ,
V_261 -> V_209 , sizeof *V_263 ) ;
return V_44 ;
}
V_44 = F_204 ( V_261 , V_263 ) ;
if ( V_44 ) {
F_171 ( V_208 L_33 ,
V_261 -> V_209 , V_44 ) ;
F_68 ( V_263 ) ;
return V_44 ;
}
V_4 -> V_264 = V_263 -> V_265 ;
F_68 ( V_263 ) ;
if ( V_4 -> V_264 & V_266 ) {
V_4 -> V_2 -> V_267 = V_268 |
V_17 | V_269 ;
if ( V_4 -> V_264 & V_270 )
V_4 -> V_2 -> V_267 |= V_18 ;
V_4 -> V_2 -> V_15 |= V_4 -> V_2 -> V_267 ;
}
return 0 ;
}
static struct V_1 * F_205 ( const char * V_271 ,
struct V_59 * V_261 , T_4 V_58 )
{
struct V_3 * V_4 ;
struct V_272 V_254 ;
int V_44 = - V_199 ;
V_4 = F_188 ( V_271 ) ;
if ( ! V_4 )
goto V_273;
F_206 ( V_4 -> V_2 , V_261 -> V_274 ) ;
V_4 -> V_2 -> V_275 = V_58 - 1 ;
V_44 = F_207 ( V_261 , V_58 , & V_254 ) ;
if ( ! V_44 )
V_4 -> V_22 = F_208 ( V_254 . V_276 ) ;
else {
F_171 ( V_208 L_34 ,
V_261 -> V_209 , V_58 ) ;
goto V_277;
}
V_4 -> V_2 -> V_21 = F_26 ( V_4 -> V_22 ) ;
V_4 -> V_20 = V_4 -> V_23 = V_4 -> V_2 -> V_21 ;
V_4 -> V_2 -> V_278 = sizeof( struct V_102 ) ;
V_44 = F_209 ( V_261 , V_58 , 0 , & V_4 -> V_60 ) ;
if ( V_44 ) {
F_171 ( V_208 L_35 ,
V_261 -> V_209 , V_58 , V_44 ) ;
goto V_277;
}
V_44 = F_203 ( V_4 , V_261 ) ;
if ( V_44 )
goto V_277;
V_4 -> V_60 |= 0x8000 ;
V_4 -> V_2 -> V_114 [ 8 ] = V_4 -> V_60 >> 8 ;
V_4 -> V_2 -> V_114 [ 9 ] = V_4 -> V_60 & 0xff ;
V_44 = F_210 ( V_261 , V_58 , 0 , & V_4 -> V_56 ) ;
if ( V_44 ) {
F_171 ( V_208 L_36 ,
V_261 -> V_209 , V_58 , V_44 ) ;
goto V_277;
} else
memcpy ( V_4 -> V_2 -> V_64 + 4 , V_4 -> V_56 . V_75 , sizeof ( union V_48 ) ) ;
V_44 = F_170 ( V_4 -> V_2 , V_261 , V_58 ) ;
if ( V_44 < 0 ) {
F_171 ( V_208 L_37 ,
V_261 -> V_209 , V_58 , V_44 ) ;
goto V_277;
}
F_211 ( & V_4 -> V_279 ,
V_4 -> V_109 , V_280 ) ;
V_44 = F_212 ( & V_4 -> V_279 ) ;
if ( V_44 < 0 ) {
F_171 ( V_208 L_38
L_39 ,
V_261 -> V_209 , V_58 , V_44 ) ;
goto V_281;
}
V_44 = F_213 ( V_4 -> V_2 ) ;
if ( V_44 ) {
F_171 ( V_208 L_40 ,
V_261 -> V_209 , V_58 , V_44 ) ;
goto V_282;
}
F_214 ( V_4 -> V_2 ) ;
if ( F_215 ( V_4 -> V_2 ) )
goto V_283;
if ( F_202 ( V_4 -> V_2 ) )
goto V_283;
if ( F_196 ( V_4 -> V_2 ) )
goto V_283;
if ( F_197 ( & V_4 -> V_2 -> V_2 , & V_284 ) )
goto V_283;
if ( F_197 ( & V_4 -> V_2 -> V_2 , & V_285 ) )
goto V_283;
return V_4 -> V_2 ;
V_283:
F_177 ( V_4 -> V_2 ) ;
F_216 ( V_4 -> V_2 ) ;
V_282:
F_217 ( & V_4 -> V_279 ) ;
F_218 ( V_286 ) ;
F_5 ( V_181 , & V_4 -> V_6 ) ;
F_169 ( & V_4 -> V_193 ) ;
F_218 ( V_4 -> V_157 ) ;
V_281:
F_20 ( V_4 -> V_2 ) ;
V_277:
F_219 ( V_4 -> V_2 ) ;
V_273:
return F_220 ( V_44 ) ;
}
static void F_221 ( struct V_59 * V_252 )
{
struct V_45 * V_57 ;
struct V_1 * V_2 ;
struct V_3 * V_4 ;
int V_287 ;
int V_258 = 0 ;
V_57 = F_70 ( sizeof *V_57 , V_88 ) ;
if ( ! V_57 )
return;
F_106 ( V_57 ) ;
for ( V_287 = F_222 ( V_252 ) ; V_287 <= F_223 ( V_252 ) ; ++ V_287 ) {
if ( ! F_47 ( V_252 , V_287 ) )
continue;
V_2 = F_205 ( L_41 , V_252 , V_287 ) ;
if ( ! F_224 ( V_2 ) ) {
V_4 = F_2 ( V_2 ) ;
F_62 ( & V_4 -> V_81 , V_57 ) ;
V_258 ++ ;
}
}
if ( ! V_258 ) {
F_68 ( V_57 ) ;
return;
}
F_225 ( V_252 , & V_288 , V_57 ) ;
}
static void F_226 ( struct V_59 * V_252 , void * V_61 )
{
struct V_3 * V_4 , * V_289 ;
struct V_45 * V_57 = V_61 ;
if ( ! V_57 )
return;
F_78 (priv, tmp, dev_list, list) {
F_217 ( & V_4 -> V_279 ) ;
F_218 ( V_286 ) ;
F_56 () ;
F_11 ( V_4 -> V_2 , V_4 -> V_2 -> V_6 & ~ V_13 ) ;
F_54 () ;
F_5 ( V_181 , & V_4 -> V_6 ) ;
F_169 ( & V_4 -> V_193 ) ;
F_218 ( V_4 -> V_157 ) ;
F_216 ( V_4 -> V_2 ) ;
F_219 ( V_4 -> V_2 ) ;
}
F_68 ( V_57 ) ;
}
static int T_9 F_227 ( void )
{
int V_62 ;
V_207 = F_162 ( V_207 ) ;
V_207 = F_27 ( V_207 , V_290 ) ;
V_207 = F_228 ( V_207 , V_291 ) ;
V_211 = F_162 ( V_211 ) ;
V_211 = F_27 ( V_211 , V_290 ) ;
V_211 = F_229 ( V_211 , 2 * V_292 , V_291 ) ;
#ifdef F_230
V_293 = F_27 ( V_293 , V_294 ) ;
#endif
F_231 ( V_295 > V_296 ) ;
V_62 = F_232 () ;
if ( V_62 )
return V_62 ;
V_286 = F_233 ( L_42 ) ;
if ( ! V_286 ) {
V_62 = - V_199 ;
goto V_297;
}
F_234 ( & V_121 ) ;
V_62 = F_235 ( & V_288 ) ;
if ( V_62 )
goto V_298;
V_62 = F_236 () ;
if ( V_62 )
goto V_299;
return 0 ;
V_299:
F_237 ( & V_288 ) ;
V_298:
F_238 ( & V_121 ) ;
F_239 ( V_286 ) ;
V_297:
F_240 () ;
return V_62 ;
}
static void T_10 F_241 ( void )
{
F_242 () ;
F_237 ( & V_288 ) ;
F_238 ( & V_121 ) ;
F_240 () ;
F_239 ( V_286 ) ;
}
