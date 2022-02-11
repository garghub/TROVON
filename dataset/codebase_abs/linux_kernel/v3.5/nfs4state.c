int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_5 V_6 = {
. V_7 = V_2 -> V_8 ,
. V_9 = V_2 -> V_10 ,
} ;
unsigned short V_11 ;
int V_12 ;
if ( F_2 ( V_13 , & V_2 -> V_14 ) )
goto V_15;
V_11 = V_16 ;
if ( V_2 -> V_17 . V_18 == V_19 )
V_11 = V_20 ;
V_12 = F_3 ( V_2 , V_21 , V_11 , V_4 , & V_6 ) ;
if ( V_12 != 0 )
goto V_22;
V_2 -> V_8 = V_6 . V_7 ;
V_2 -> V_10 = V_6 . V_9 ;
F_4 ( V_13 , & V_2 -> V_14 ) ;
V_15:
V_12 = F_5 ( V_2 , & V_6 , V_4 ) ;
if ( V_12 != 0 )
goto V_22;
F_6 ( V_13 , & V_2 -> V_14 ) ;
F_7 ( V_2 ) ;
V_22:
return V_12 ;
}
struct V_3 * F_8 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = NULL ;
if ( V_2 -> V_23 != NULL )
V_4 = F_9 ( V_2 -> V_23 ) ;
return V_4 ;
}
static void F_10 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
F_11 ( & V_2 -> V_24 ) ;
V_4 = V_2 -> V_23 ;
V_2 -> V_23 = NULL ;
F_12 ( & V_2 -> V_24 ) ;
if ( V_4 != NULL )
F_13 ( V_4 ) ;
}
static struct V_3 *
F_14 ( struct V_25 * V_26 )
{
struct V_3 * V_4 = NULL ;
struct V_27 * V_28 ;
struct V_29 * V_30 ;
for ( V_30 = F_15 ( & V_26 -> V_31 ) ;
V_30 != NULL ;
V_30 = F_16 ( V_30 ) ) {
V_28 = F_17 ( V_30 , struct V_27 , V_32 ) ;
if ( F_18 ( & V_28 -> V_33 ) )
continue;
V_4 = F_9 ( V_28 -> V_34 ) ;
break;
}
return V_4 ;
}
struct V_3 * F_19 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = NULL ;
struct V_25 * V_26 ;
V_4 = F_8 ( V_2 ) ;
if ( V_4 != NULL )
goto V_22;
F_20 () ;
F_21 (server, &clp->cl_superblocks, client_link) {
V_4 = F_14 ( V_26 ) ;
if ( V_4 != NULL )
break;
}
F_22 () ;
V_22:
return V_4 ;
}
static int F_23 ( struct V_1 * V_2 )
{
int V_12 ;
struct V_35 V_36 ;
if ( ! F_2 ( V_37 , & V_2 -> V_38 ) ) {
F_7 ( V_2 ) ;
return 0 ;
}
V_12 = F_24 ( V_2 , & V_36 ) ;
if ( V_12 == 0 ) {
F_11 ( & V_2 -> V_24 ) ;
V_2 -> V_39 = V_36 . V_40 * V_41 ;
V_2 -> V_42 = V_43 ;
F_12 ( & V_2 -> V_24 ) ;
F_7 ( V_2 ) ;
}
return V_12 ;
}
static void F_25 ( struct V_1 * V_2 )
{
struct V_44 * V_45 = V_2 -> V_46 ;
struct V_47 * V_48 ;
int V_49 ;
if ( V_45 == NULL )
return;
V_48 = & V_45 -> V_50 ;
if ( F_26 ( V_51 , & V_45 -> V_52 ) ) {
F_11 ( & V_48 -> V_53 ) ;
V_49 = V_48 -> V_49 ;
while ( V_49 -- ) {
if ( F_27 ( & V_48 -> V_54 ,
V_55 ,
NULL ) == NULL )
break;
}
F_12 ( & V_48 -> V_53 ) ;
}
}
static int F_28 ( struct V_47 * V_48 )
{
F_11 ( & V_48 -> V_53 ) ;
if ( V_48 -> V_56 != V_57 ) {
F_29 ( V_48 -> V_58 ) ;
F_12 ( & V_48 -> V_53 ) ;
return F_30 ( & V_48 -> V_58 ) ;
}
F_12 ( & V_48 -> V_53 ) ;
return 0 ;
}
static int F_31 ( struct V_1 * V_2 )
{
struct V_44 * V_45 = V_2 -> V_46 ;
int V_59 = 0 ;
F_4 ( V_51 , & V_45 -> V_52 ) ;
V_59 = F_28 ( & V_45 -> V_60 ) ;
if ( V_59 )
return V_59 ;
return F_28 ( & V_45 -> V_50 ) ;
}
static void F_32 ( struct V_1 * V_2 )
{
F_6 ( V_13 , & V_2 -> V_14 ) ;
F_6 ( V_61 , & V_2 -> V_14 ) ;
F_6 ( V_62 , & V_2 -> V_14 ) ;
F_6 ( V_63 , & V_2 -> V_14 ) ;
F_23 ( V_2 ) ;
}
int F_33 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
int V_12 ;
if ( F_2 ( V_13 , & V_2 -> V_14 ) )
goto V_15;
F_31 ( V_2 ) ;
V_12 = F_34 ( V_2 , V_4 ) ;
if ( V_12 != 0 )
goto V_22;
F_4 ( V_13 , & V_2 -> V_14 ) ;
V_15:
V_12 = F_35 ( V_2 , V_4 ) ;
if ( V_12 != 0 )
goto V_22;
F_32 ( V_2 ) ;
F_36 ( V_2 , V_64 ) ;
V_22:
return V_12 ;
}
struct V_3 * F_37 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
F_11 ( & V_2 -> V_24 ) ;
V_4 = F_8 ( V_2 ) ;
F_12 ( & V_2 -> V_24 ) ;
return V_4 ;
}
static struct V_3 *
F_38 ( struct V_25 * V_26 )
{
struct V_1 * V_2 = V_26 -> V_1 ;
struct V_3 * V_4 = NULL ;
struct V_27 * V_28 ;
struct V_29 * V_30 ;
F_11 ( & V_2 -> V_24 ) ;
V_30 = F_15 ( & V_26 -> V_31 ) ;
if ( V_30 != NULL ) {
V_28 = F_17 ( V_30 , struct V_27 , V_32 ) ;
V_4 = F_9 ( V_28 -> V_34 ) ;
}
F_12 ( & V_2 -> V_24 ) ;
return V_4 ;
}
struct V_3 * F_39 ( struct V_1 * V_2 )
{
struct V_25 * V_26 ;
struct V_3 * V_4 ;
F_11 ( & V_2 -> V_24 ) ;
V_4 = F_8 ( V_2 ) ;
F_12 ( & V_2 -> V_24 ) ;
if ( V_4 != NULL )
goto V_22;
F_20 () ;
F_21 (server, &clp->cl_superblocks, client_link) {
V_4 = F_38 ( V_26 ) ;
if ( V_4 != NULL )
break;
}
F_22 () ;
V_22:
return V_4 ;
}
static struct V_27 *
F_40 ( struct V_25 * V_26 , struct V_3 * V_4 )
{
struct V_29 * * V_65 = & V_26 -> V_31 . V_29 ,
* V_66 = NULL ;
struct V_27 * V_28 ;
while ( * V_65 != NULL ) {
V_66 = * V_65 ;
V_28 = F_17 ( V_66 , struct V_27 , V_32 ) ;
if ( V_4 < V_28 -> V_34 )
V_65 = & V_66 -> V_67 ;
else if ( V_4 > V_28 -> V_34 )
V_65 = & V_66 -> V_68 ;
else {
if ( ! F_18 ( & V_28 -> V_69 ) )
F_41 ( & V_28 -> V_69 ) ;
F_42 ( & V_28 -> V_70 ) ;
return V_28 ;
}
}
return NULL ;
}
static struct V_27 *
F_43 ( struct V_27 * V_71 )
{
struct V_25 * V_26 = V_71 -> V_72 ;
struct V_29 * * V_65 = & V_26 -> V_31 . V_29 ,
* V_66 = NULL ;
struct V_27 * V_28 ;
int V_73 ;
while ( * V_65 != NULL ) {
V_66 = * V_65 ;
V_28 = F_17 ( V_66 , struct V_27 , V_32 ) ;
if ( V_71 -> V_34 < V_28 -> V_34 )
V_65 = & V_66 -> V_67 ;
else if ( V_71 -> V_34 > V_28 -> V_34 )
V_65 = & V_66 -> V_68 ;
else {
if ( ! F_18 ( & V_28 -> V_69 ) )
F_41 ( & V_28 -> V_69 ) ;
F_42 ( & V_28 -> V_70 ) ;
return V_28 ;
}
}
V_73 = F_44 ( & V_26 -> V_74 , & V_71 -> V_75 . V_76 ) ;
if ( V_73 )
return F_45 ( V_73 ) ;
F_46 ( & V_71 -> V_32 , V_66 , V_65 ) ;
F_47 ( & V_71 -> V_32 , & V_26 -> V_31 ) ;
return V_71 ;
}
static void
F_48 ( struct V_27 * V_28 )
{
struct V_25 * V_26 = V_28 -> V_72 ;
if ( ! F_49 ( & V_28 -> V_32 ) )
F_50 ( & V_28 -> V_32 , & V_26 -> V_31 ) ;
F_51 ( & V_26 -> V_74 , V_28 -> V_75 . V_76 ) ;
}
static void
F_52 ( struct V_77 * V_78 )
{
V_78 -> V_79 = F_53 () ;
V_78 -> V_80 = 0 ;
V_78 -> V_81 = 0 ;
F_54 ( & V_78 -> V_82 ) ;
F_55 ( & V_78 -> V_83 ) ;
F_56 ( & V_78 -> V_84 , L_1 ) ;
}
static void
F_57 ( struct V_77 * V_78 )
{
F_58 ( & V_78 -> V_84 ) ;
}
static struct V_27 *
F_59 ( struct V_25 * V_26 ,
struct V_3 * V_4 ,
T_1 V_85 )
{
struct V_27 * V_28 ;
V_28 = F_60 ( sizeof( * V_28 ) , V_85 ) ;
if ( ! V_28 )
return NULL ;
V_28 -> V_72 = V_26 ;
V_28 -> V_34 = F_9 ( V_4 ) ;
F_54 ( & V_28 -> V_86 ) ;
F_55 ( & V_28 -> V_33 ) ;
F_52 ( & V_28 -> V_75 ) ;
F_61 ( & V_28 -> V_70 , 1 ) ;
F_55 ( & V_28 -> V_69 ) ;
return V_28 ;
}
static void
F_62 ( struct V_27 * V_28 )
{
struct V_29 * V_29 = & V_28 -> V_32 ;
if ( ! F_49 ( V_29 ) ) {
struct V_25 * V_26 = V_28 -> V_72 ;
struct V_1 * V_2 = V_26 -> V_1 ;
F_11 ( & V_2 -> V_24 ) ;
if ( ! F_49 ( V_29 ) ) {
F_50 ( V_29 , & V_26 -> V_31 ) ;
F_63 ( V_29 ) ;
}
F_12 ( & V_2 -> V_24 ) ;
}
}
static void F_64 ( struct V_27 * V_28 )
{
F_57 ( & V_28 -> V_75 ) ;
F_13 ( V_28 -> V_34 ) ;
F_65 ( V_28 ) ;
}
static void F_66 ( struct V_25 * V_26 )
{
struct V_1 * V_2 = V_26 -> V_1 ;
struct V_27 * V_28 , * V_87 ;
unsigned long V_88 , V_89 ;
F_67 ( V_90 ) ;
F_11 ( & V_2 -> V_24 ) ;
V_89 = V_43 ;
V_88 = ( long ) V_89 - ( long ) V_2 -> V_39 ;
F_68 (sp, tmp, &server->state_owners_lru, so_lru) {
if ( F_69 ( V_28 -> V_91 , V_88 , V_89 ) )
break;
F_70 ( & V_28 -> V_69 , & V_90 ) ;
F_48 ( V_28 ) ;
}
F_12 ( & V_2 -> V_24 ) ;
F_68 (sp, tmp, &doomed, so_lru) {
F_71 ( & V_28 -> V_69 ) ;
F_64 ( V_28 ) ;
}
}
struct V_27 * F_72 ( struct V_25 * V_26 ,
struct V_3 * V_4 ,
T_1 V_85 )
{
struct V_1 * V_2 = V_26 -> V_1 ;
struct V_27 * V_28 , * V_71 ;
F_11 ( & V_2 -> V_24 ) ;
V_28 = F_40 ( V_26 , V_4 ) ;
F_12 ( & V_2 -> V_24 ) ;
if ( V_28 != NULL )
goto V_22;
V_71 = F_59 ( V_26 , V_4 , V_85 ) ;
if ( V_71 == NULL )
goto V_22;
do {
if ( F_73 ( & V_26 -> V_74 , V_85 ) == 0 )
break;
F_11 ( & V_2 -> V_24 ) ;
V_28 = F_43 ( V_71 ) ;
F_12 ( & V_2 -> V_24 ) ;
} while ( V_28 == F_45 ( - V_92 ) );
if ( V_28 != V_71 )
F_64 ( V_71 ) ;
V_22:
F_66 ( V_26 ) ;
return V_28 ;
}
void F_74 ( struct V_27 * V_28 )
{
struct V_25 * V_26 = V_28 -> V_72 ;
struct V_1 * V_2 = V_26 -> V_1 ;
if ( ! F_75 ( & V_28 -> V_70 , & V_2 -> V_24 ) )
return;
V_28 -> V_91 = V_43 ;
F_76 ( & V_28 -> V_69 , & V_26 -> V_93 ) ;
F_12 ( & V_2 -> V_24 ) ;
}
void F_77 ( struct V_25 * V_26 )
{
struct V_1 * V_2 = V_26 -> V_1 ;
struct V_27 * V_28 , * V_87 ;
F_67 ( V_90 ) ;
F_11 ( & V_2 -> V_24 ) ;
F_68 (sp, tmp, &server->state_owners_lru, so_lru) {
F_70 ( & V_28 -> V_69 , & V_90 ) ;
F_48 ( V_28 ) ;
}
F_12 ( & V_2 -> V_24 ) ;
F_68 (sp, tmp, &doomed, so_lru) {
F_71 ( & V_28 -> V_69 ) ;
F_64 ( V_28 ) ;
}
}
static struct V_94 *
F_78 ( void )
{
struct V_94 * V_95 ;
V_95 = F_60 ( sizeof( * V_95 ) , V_96 ) ;
if ( ! V_95 )
return NULL ;
F_61 ( & V_95 -> V_97 , 1 ) ;
F_55 ( & V_95 -> V_98 ) ;
F_54 ( & V_95 -> V_99 ) ;
F_79 ( & V_95 -> V_100 ) ;
return V_95 ;
}
void
F_80 ( struct V_94 * V_95 , T_2 V_101 )
{
if ( V_95 -> V_95 == V_101 )
return;
if ( ( V_101 & V_102 ) != ( V_95 -> V_95 & V_102 ) ) {
if ( V_101 & V_102 )
F_70 ( & V_95 -> V_103 , & V_95 -> V_104 -> V_33 ) ;
else
F_81 ( & V_95 -> V_103 , & V_95 -> V_104 -> V_33 ) ;
}
V_95 -> V_95 = V_101 ;
}
static struct V_94 *
F_82 ( struct V_105 * V_105 , struct V_27 * V_104 )
{
struct V_106 * V_107 = F_83 ( V_105 ) ;
struct V_94 * V_95 ;
F_84 (state, &nfsi->open_states, inode_states) {
if ( V_95 -> V_104 != V_104 )
continue;
if ( F_85 ( & V_95 -> V_97 ) )
return V_95 ;
}
return NULL ;
}
static void
F_86 ( struct V_94 * V_95 )
{
F_65 ( V_95 ) ;
}
struct V_94 *
F_87 ( struct V_105 * V_105 , struct V_27 * V_104 )
{
struct V_94 * V_95 , * V_71 ;
struct V_106 * V_107 = F_83 ( V_105 ) ;
F_11 ( & V_105 -> V_108 ) ;
V_95 = F_82 ( V_105 , V_104 ) ;
F_12 ( & V_105 -> V_108 ) ;
if ( V_95 )
goto V_22;
V_71 = F_78 () ;
F_11 ( & V_104 -> V_86 ) ;
F_11 ( & V_105 -> V_108 ) ;
V_95 = F_82 ( V_105 , V_104 ) ;
if ( V_95 == NULL && V_71 != NULL ) {
V_95 = V_71 ;
V_95 -> V_104 = V_104 ;
F_42 ( & V_104 -> V_70 ) ;
F_88 ( & V_95 -> V_109 , & V_107 -> V_103 ) ;
F_89 ( V_105 ) ;
V_95 -> V_105 = V_105 ;
F_12 ( & V_105 -> V_108 ) ;
F_76 ( & V_95 -> V_103 , & V_104 -> V_33 ) ;
F_12 ( & V_104 -> V_86 ) ;
} else {
F_12 ( & V_105 -> V_108 ) ;
F_12 ( & V_104 -> V_86 ) ;
if ( V_71 )
F_86 ( V_71 ) ;
}
V_22:
return V_95 ;
}
void F_90 ( struct V_94 * V_95 )
{
struct V_105 * V_105 = V_95 -> V_105 ;
struct V_27 * V_104 = V_95 -> V_104 ;
if ( ! F_75 ( & V_95 -> V_97 , & V_104 -> V_86 ) )
return;
F_11 ( & V_105 -> V_108 ) ;
F_71 ( & V_95 -> V_109 ) ;
F_71 ( & V_95 -> V_103 ) ;
F_12 ( & V_105 -> V_108 ) ;
F_12 ( & V_104 -> V_86 ) ;
F_91 ( V_105 ) ;
F_86 ( V_95 ) ;
F_74 ( V_104 ) ;
}
static void F_92 ( struct V_94 * V_95 ,
T_2 V_101 , T_1 V_110 , int V_84 )
{
struct V_27 * V_104 = V_95 -> V_104 ;
int V_111 = 0 ;
T_2 V_112 ;
F_42 ( & V_104 -> V_70 ) ;
F_11 ( & V_104 -> V_86 ) ;
switch ( V_101 & ( V_113 | V_102 ) ) {
case V_113 :
V_95 -> V_114 -- ;
break;
case V_102 :
V_95 -> V_115 -- ;
break;
case V_113 | V_102 :
V_95 -> V_116 -- ;
}
V_112 = V_113 | V_102 ;
if ( V_95 -> V_116 == 0 ) {
if ( V_95 -> V_114 == 0 ) {
V_112 &= ~ V_113 ;
V_111 |= F_2 ( V_117 , & V_95 -> V_80 ) ;
V_111 |= F_2 ( V_118 , & V_95 -> V_80 ) ;
}
if ( V_95 -> V_115 == 0 ) {
V_112 &= ~ V_102 ;
V_111 |= F_2 ( V_119 , & V_95 -> V_80 ) ;
V_111 |= F_2 ( V_118 , & V_95 -> V_80 ) ;
}
if ( V_112 == 0 )
F_6 ( V_120 , & V_95 -> V_80 ) ;
}
F_80 ( V_95 , V_112 ) ;
F_12 ( & V_104 -> V_86 ) ;
if ( ! V_111 ) {
F_90 ( V_95 ) ;
F_74 ( V_104 ) ;
} else {
bool V_121 = F_93 ( V_95 -> V_105 ) ;
F_94 ( V_95 , V_110 , V_84 , V_121 ) ;
}
}
void F_95 ( struct V_94 * V_95 , T_2 V_101 )
{
F_92 ( V_95 , V_101 , V_96 , 0 ) ;
}
void F_96 ( struct V_94 * V_95 , T_2 V_101 )
{
F_92 ( V_95 , V_101 , V_122 , 1 ) ;
}
static struct V_123 *
F_97 ( struct V_94 * V_95 , T_3 V_124 , T_4 V_125 , unsigned int type )
{
struct V_123 * V_30 ;
F_84 (pos, &state->lock_states, ls_locks) {
if ( type != V_126 && V_30 -> V_127 . V_128 != type )
continue;
switch ( V_30 -> V_127 . V_128 ) {
case V_129 :
if ( V_30 -> V_127 . V_130 . V_131 != V_124 )
continue;
break;
case V_132 :
if ( V_30 -> V_127 . V_130 . V_133 != V_125 )
continue;
}
F_42 ( & V_30 -> V_134 ) ;
return V_30 ;
}
return NULL ;
}
static struct V_123 * F_98 ( struct V_94 * V_95 , T_3 V_124 , T_4 V_125 , unsigned int type )
{
struct V_123 * V_135 ;
struct V_25 * V_26 = V_95 -> V_104 -> V_72 ;
V_135 = F_60 ( sizeof( * V_135 ) , V_96 ) ;
if ( V_135 == NULL )
return NULL ;
F_52 ( & V_135 -> V_136 ) ;
F_61 ( & V_135 -> V_134 , 1 ) ;
V_135 -> V_137 = V_95 ;
V_135 -> V_127 . V_128 = type ;
switch ( V_135 -> V_127 . V_128 ) {
case V_132 :
V_135 -> V_127 . V_130 . V_133 = V_125 ;
break;
case V_129 :
V_135 -> V_127 . V_130 . V_131 = V_124 ;
break;
default:
goto V_138;
}
V_135 -> V_136 . V_76 = F_99 ( & V_26 -> V_139 , 0 , 0 , V_96 ) ;
if ( V_135 -> V_136 . V_76 < 0 )
goto V_138;
F_55 ( & V_135 -> V_140 ) ;
return V_135 ;
V_138:
F_65 ( V_135 ) ;
return NULL ;
}
void F_100 ( struct V_25 * V_26 , struct V_123 * V_135 )
{
F_101 ( & V_26 -> V_139 , V_135 -> V_136 . V_76 ) ;
F_57 ( & V_135 -> V_136 ) ;
F_65 ( V_135 ) ;
}
static struct V_123 * F_102 ( struct V_94 * V_95 , T_3 V_104 , T_4 V_141 , unsigned int type )
{
struct V_123 * V_135 , * V_71 = NULL ;
for(; ; ) {
F_11 ( & V_95 -> V_99 ) ;
V_135 = F_97 ( V_95 , V_104 , V_141 , type ) ;
if ( V_135 != NULL )
break;
if ( V_71 != NULL ) {
F_88 ( & V_71 -> V_140 , & V_95 -> V_98 ) ;
F_4 ( V_142 , & V_95 -> V_80 ) ;
V_135 = V_71 ;
V_71 = NULL ;
break;
}
F_12 ( & V_95 -> V_99 ) ;
V_71 = F_98 ( V_95 , V_104 , V_141 , type ) ;
if ( V_71 == NULL )
return NULL ;
}
F_12 ( & V_95 -> V_99 ) ;
if ( V_71 != NULL )
F_100 ( V_95 -> V_104 -> V_72 , V_71 ) ;
return V_135 ;
}
void F_103 ( struct V_123 * V_135 )
{
struct V_94 * V_95 ;
if ( V_135 == NULL )
return;
V_95 = V_135 -> V_137 ;
if ( ! F_75 ( & V_135 -> V_134 , & V_95 -> V_99 ) )
return;
F_71 ( & V_135 -> V_140 ) ;
if ( F_18 ( & V_95 -> V_98 ) )
F_6 ( V_142 , & V_95 -> V_80 ) ;
F_12 ( & V_95 -> V_99 ) ;
if ( V_135 -> V_143 & V_144 ) {
if ( F_104 ( V_135 ) == 0 )
return;
}
F_100 ( V_135 -> V_137 -> V_104 -> V_72 , V_135 ) ;
}
static void F_105 ( struct V_145 * V_146 , struct V_145 * V_147 )
{
struct V_123 * V_135 = V_147 -> V_148 . V_149 . V_104 ;
V_146 -> V_148 . V_149 . V_104 = V_135 ;
F_42 ( & V_135 -> V_134 ) ;
}
static void F_106 ( struct V_145 * V_150 )
{
F_103 ( V_150 -> V_148 . V_149 . V_104 ) ;
}
int F_107 ( struct V_94 * V_95 , struct V_145 * V_150 )
{
struct V_123 * V_135 ;
if ( V_150 -> V_151 != NULL )
return 0 ;
if ( V_150 -> V_152 & V_153 )
V_135 = F_102 ( V_95 , V_150 -> V_124 , 0 , V_129 ) ;
else if ( V_150 -> V_152 & V_154 )
V_135 = F_102 ( V_95 , NULL , V_150 -> V_125 ,
V_132 ) ;
else
return - V_155 ;
if ( V_135 == NULL )
return - V_156 ;
V_150 -> V_148 . V_149 . V_104 = V_135 ;
V_150 -> V_151 = & V_157 ;
return 0 ;
}
static bool F_108 ( T_5 * V_146 , struct V_94 * V_95 ,
T_3 V_124 , T_4 V_125 )
{
struct V_123 * V_135 ;
bool V_59 = false ;
if ( F_2 ( V_142 , & V_95 -> V_80 ) == 0 )
goto V_22;
F_11 ( & V_95 -> V_99 ) ;
V_135 = F_97 ( V_95 , V_124 , V_125 , V_126 ) ;
if ( V_135 != NULL && ( V_135 -> V_143 & V_144 ) != 0 ) {
F_109 ( V_146 , & V_135 -> V_158 ) ;
V_59 = true ;
}
F_12 ( & V_95 -> V_99 ) ;
F_103 ( V_135 ) ;
V_22:
return V_59 ;
}
static void F_110 ( T_5 * V_146 , struct V_94 * V_95 )
{
int V_159 ;
do {
V_159 = F_111 ( & V_95 -> V_100 ) ;
F_109 ( V_146 , & V_95 -> V_160 ) ;
} while ( F_112 ( & V_95 -> V_100 , V_159 ) );
}
void F_113 ( T_5 * V_146 , struct V_94 * V_95 ,
T_2 V_101 , T_3 V_124 , T_4 V_125 )
{
if ( F_114 ( V_146 , V_95 -> V_105 , V_101 ) )
return;
if ( F_108 ( V_146 , V_95 , V_124 , V_125 ) )
return;
F_110 ( V_146 , V_95 ) ;
}
struct V_161 * F_115 ( struct V_77 * V_81 , T_1 V_110 )
{
struct V_161 * V_71 ;
V_71 = F_116 ( sizeof( * V_71 ) , V_110 ) ;
if ( V_71 != NULL ) {
V_71 -> V_162 = V_81 ;
F_55 ( & V_71 -> V_83 ) ;
V_71 -> V_163 = NULL ;
}
return V_71 ;
}
void F_117 ( struct V_161 * V_164 )
{
struct V_77 * V_162 ;
if ( F_18 ( & V_164 -> V_83 ) )
return;
V_162 = V_164 -> V_162 ;
F_11 ( & V_162 -> V_82 ) ;
F_41 ( & V_164 -> V_83 ) ;
if ( ! F_18 ( & V_162 -> V_83 ) ) {
struct V_161 * V_165 ;
V_165 = F_118 ( & V_162 -> V_83 ,
struct V_161 , V_83 ) ;
F_119 ( & V_162 -> V_84 , V_165 -> V_163 ) ;
}
F_12 ( & V_162 -> V_82 ) ;
}
void F_120 ( struct V_161 * V_164 )
{
F_117 ( V_164 ) ;
F_65 ( V_164 ) ;
}
static void F_121 ( int V_12 , struct V_161 * V_164 )
{
F_122 ( F_118 ( & V_164 -> V_162 -> V_83 , struct V_161 , V_83 ) != V_164 ) ;
switch ( V_12 ) {
case 0 :
break;
case - V_166 :
if ( V_164 -> V_162 -> V_80 & V_167 )
return;
F_123 ( L_2
L_3
L_4 ,
V_164 -> V_162 ) ;
case - V_168 :
case - V_169 :
case - V_170 :
case - V_171 :
case - V_172 :
case - V_173 :
return;
} ;
V_164 -> V_162 -> V_81 ++ ;
}
void F_124 ( int V_12 , struct V_161 * V_164 )
{
struct V_27 * V_28 = F_125 ( V_164 -> V_162 ,
struct V_27 , V_75 ) ;
struct V_25 * V_26 = V_28 -> V_72 ;
if ( V_12 == - V_166 )
F_62 ( V_28 ) ;
if ( ! F_126 ( V_26 -> V_1 ) )
F_121 ( V_12 , V_164 ) ;
}
void F_127 ( int V_12 , struct V_161 * V_164 )
{
F_121 ( V_12 , V_164 ) ;
}
int F_128 ( struct V_161 * V_164 , struct V_174 * V_163 )
{
struct V_77 * V_162 = V_164 -> V_162 ;
int V_12 = 0 ;
F_11 ( & V_162 -> V_82 ) ;
V_164 -> V_163 = V_163 ;
if ( F_18 ( & V_164 -> V_83 ) )
F_76 ( & V_164 -> V_83 , & V_162 -> V_83 ) ;
if ( F_118 ( & V_162 -> V_83 , struct V_161 , V_83 ) == V_164 )
goto V_175;
F_129 ( & V_162 -> V_84 , V_163 , NULL ) ;
V_12 = - V_92 ;
V_175:
F_12 ( & V_162 -> V_82 ) ;
return V_12 ;
}
static void F_130 ( struct V_1 * V_2 )
{
F_131 () ;
F_6 ( V_176 , & V_2 -> V_14 ) ;
F_132 () ;
F_133 ( & V_2 -> V_14 , V_176 ) ;
F_134 ( & V_2 -> V_177 ) ;
}
void F_135 ( struct V_1 * V_2 )
{
struct V_178 * V_163 ;
char V_179 [ V_180 + sizeof( L_5 ) + 1 ] ;
if ( F_136 ( V_176 , & V_2 -> V_14 ) != 0 )
return;
F_137 ( V_181 ) ;
F_42 ( & V_2 -> V_182 ) ;
F_20 () ;
snprintf ( V_179 , sizeof( V_179 ) , L_6 ,
F_138 ( V_2 -> V_183 , V_184 ) ) ;
F_22 () ;
V_163 = F_139 ( V_185 , V_2 , V_179 ) ;
if ( F_140 ( V_163 ) ) {
F_141 ( V_186 L_7 ,
V_187 , F_142 ( V_163 ) ) ;
F_130 ( V_2 ) ;
F_143 ( V_2 ) ;
F_144 ( V_181 ) ;
}
}
void F_145 ( struct V_1 * V_2 )
{
if ( ! V_2 )
return;
if ( ! F_2 ( V_188 , & V_2 -> V_14 ) )
F_4 ( V_189 , & V_2 -> V_14 ) ;
F_146 ( L_8 , V_187 ,
V_2 -> V_190 ) ;
F_135 ( V_2 ) ;
}
static void F_147 ( struct V_1 * V_2 )
{
F_4 ( V_188 , & V_2 -> V_14 ) ;
F_148 ( V_2 ) ;
F_146 ( L_9 , V_187 ,
V_2 -> V_190 ) ;
}
void F_149 ( struct V_1 * V_2 )
{
F_147 ( V_2 ) ;
F_135 ( V_2 ) ;
}
static int F_150 ( struct V_1 * V_2 , struct V_94 * V_95 )
{
F_4 ( V_191 , & V_95 -> V_80 ) ;
if ( F_2 ( V_192 , & V_95 -> V_80 ) ) {
F_6 ( V_191 , & V_95 -> V_80 ) ;
return 0 ;
}
F_4 ( V_193 , & V_95 -> V_104 -> V_194 ) ;
F_4 ( V_195 , & V_2 -> V_14 ) ;
return 1 ;
}
static int F_151 ( struct V_1 * V_2 , struct V_94 * V_95 )
{
F_4 ( V_192 , & V_95 -> V_80 ) ;
F_6 ( V_191 , & V_95 -> V_80 ) ;
F_4 ( V_196 , & V_95 -> V_104 -> V_194 ) ;
F_4 ( V_197 , & V_2 -> V_14 ) ;
return 1 ;
}
void F_152 ( const struct V_25 * V_26 , struct V_94 * V_95 )
{
struct V_1 * V_2 = V_26 -> V_1 ;
F_151 ( V_2 , V_95 ) ;
F_146 ( L_10 , V_187 ,
V_2 -> V_190 ) ;
F_135 ( V_2 ) ;
}
void F_153 ( struct V_105 * V_105 ,
const T_5 * V_160 )
{
struct V_1 * V_2 = F_154 ( V_105 ) -> V_1 ;
struct V_106 * V_107 = F_83 ( V_105 ) ;
struct V_198 * V_199 ;
struct V_94 * V_95 ;
bool V_200 = false ;
F_11 ( & V_105 -> V_108 ) ;
F_84 (ctx, &nfsi->open_files, list) {
V_95 = V_199 -> V_95 ;
if ( V_95 == NULL )
continue;
if ( ! F_2 ( V_120 , & V_95 -> V_80 ) )
continue;
if ( ! F_155 ( & V_95 -> V_160 , V_160 ) )
continue;
F_151 ( V_2 , V_95 ) ;
V_200 = true ;
}
F_12 ( & V_105 -> V_108 ) ;
if ( V_200 )
F_135 ( V_2 ) ;
}
static int F_156 ( struct V_94 * V_95 , const struct V_201 * V_202 )
{
struct V_105 * V_105 = V_95 -> V_105 ;
struct V_106 * V_107 = F_83 ( V_105 ) ;
struct V_145 * V_150 ;
int V_12 = 0 ;
if ( V_105 -> V_203 == NULL )
return 0 ;
F_157 ( & V_107 -> V_204 ) ;
F_158 () ;
for ( V_150 = V_105 -> V_203 ; V_150 != NULL ; V_150 = V_150 -> V_205 ) {
if ( ! ( V_150 -> V_152 & ( V_153 | V_154 ) ) )
continue;
if ( F_159 ( V_150 -> V_206 ) -> V_95 != V_95 )
continue;
F_160 () ;
V_12 = V_202 -> V_207 ( V_95 , V_150 ) ;
switch ( V_12 ) {
case 0 :
break;
case - V_208 :
case - V_209 :
case - V_169 :
case - V_170 :
case - V_210 :
case - V_211 :
case - V_168 :
case - V_212 :
case - V_213 :
case - V_214 :
case - V_215 :
goto V_22;
default:
F_141 ( V_186 L_11
L_12 , V_187 , V_12 ) ;
case - V_156 :
case - V_216 :
case - V_217 :
case - V_218 :
V_12 = 0 ;
}
F_158 () ;
}
F_160 () ;
V_22:
F_161 ( & V_107 -> V_204 ) ;
return V_12 ;
}
static int F_162 ( struct V_27 * V_28 , const struct V_201 * V_202 )
{
struct V_94 * V_95 ;
struct V_123 * V_82 ;
int V_12 = 0 ;
V_219:
F_11 ( & V_28 -> V_86 ) ;
F_84 (state, &sp->so_states, open_states) {
if ( ! F_26 ( V_202 -> V_220 , & V_95 -> V_80 ) )
continue;
if ( V_95 -> V_95 == 0 )
continue;
F_42 ( & V_95 -> V_97 ) ;
F_12 ( & V_28 -> V_86 ) ;
V_12 = V_202 -> V_221 ( V_28 , V_95 ) ;
if ( V_12 >= 0 ) {
V_12 = F_156 ( V_95 , V_202 ) ;
if ( V_12 >= 0 ) {
F_11 ( & V_95 -> V_99 ) ;
F_84 (lock, &state->lock_states, ls_locks) {
if ( ! ( V_82 -> V_143 & V_144 ) )
F_123 ( L_13
L_14
L_15 , V_187 ) ;
}
F_12 ( & V_95 -> V_99 ) ;
F_90 ( V_95 ) ;
goto V_219;
}
}
switch ( V_12 ) {
default:
F_141 ( V_186 L_11
L_12 , V_187 , V_12 ) ;
case - V_222 :
case - V_156 :
case - V_208 :
memset ( & V_95 -> V_160 , 0 ,
sizeof( V_95 -> V_160 ) ) ;
V_95 -> V_95 = 0 ;
break;
case - V_223 :
break;
case - V_209 :
case - V_169 :
case - V_170 :
case - V_217 :
case - V_218 :
F_151 ( V_28 -> V_72 -> V_1 , V_95 ) ;
break;
case - V_210 :
case - V_211 :
F_151 ( V_28 -> V_72 -> V_1 , V_95 ) ;
case - V_168 :
case - V_212 :
case - V_213 :
case - V_214 :
case - V_215 :
goto V_224;
}
F_90 ( V_95 ) ;
goto V_219;
}
F_12 ( & V_28 -> V_86 ) ;
return 0 ;
V_224:
F_90 ( V_95 ) ;
return V_12 ;
}
static void F_163 ( struct V_94 * V_95 )
{
struct V_123 * V_82 ;
F_6 ( V_120 , & V_95 -> V_80 ) ;
F_6 ( V_117 , & V_95 -> V_80 ) ;
F_6 ( V_119 , & V_95 -> V_80 ) ;
F_6 ( V_118 , & V_95 -> V_80 ) ;
F_11 ( & V_95 -> V_99 ) ;
F_84 (lock, &state->lock_states, ls_locks) {
V_82 -> V_136 . V_80 = 0 ;
V_82 -> V_143 &= ~ V_144 ;
}
F_12 ( & V_95 -> V_99 ) ;
}
static void F_164 ( struct V_25 * V_26 ,
int (* F_165)( struct V_1 * V_2 , struct V_94 * V_95 ) )
{
struct V_1 * V_2 = V_26 -> V_1 ;
struct V_27 * V_28 ;
struct V_29 * V_30 ;
struct V_94 * V_95 ;
F_11 ( & V_2 -> V_24 ) ;
for ( V_30 = F_15 ( & V_26 -> V_31 ) ;
V_30 != NULL ;
V_30 = F_16 ( V_30 ) ) {
V_28 = F_17 ( V_30 , struct V_27 , V_32 ) ;
V_28 -> V_75 . V_80 = 0 ;
F_11 ( & V_28 -> V_86 ) ;
F_84 (state, &sp->so_states, open_states) {
if ( F_165 ( V_2 , V_95 ) )
F_163 ( V_95 ) ;
}
F_12 ( & V_28 -> V_86 ) ;
}
F_12 ( & V_2 -> V_24 ) ;
}
static void F_166 ( struct V_1 * V_2 ,
int (* F_165)( struct V_1 * V_2 , struct V_94 * V_95 ) )
{
struct V_25 * V_26 ;
F_20 () ;
F_21 (server, &clp->cl_superblocks, client_link)
F_164 ( V_26 , F_165 ) ;
F_22 () ;
}
static void F_167 ( struct V_1 * V_2 )
{
F_168 ( V_2 ) ;
F_166 ( V_2 , F_150 ) ;
}
static void F_169 ( struct V_1 * V_2 ,
const struct V_201 * V_202 )
{
if ( V_202 -> V_225 )
( void ) V_202 -> V_225 ( V_2 ) ;
}
static void F_170 ( struct V_25 * V_26 )
{
struct V_1 * V_2 = V_26 -> V_1 ;
struct V_27 * V_28 ;
struct V_29 * V_30 ;
struct V_94 * V_95 ;
F_11 ( & V_2 -> V_24 ) ;
for ( V_30 = F_15 ( & V_26 -> V_31 ) ;
V_30 != NULL ;
V_30 = F_16 ( V_30 ) ) {
V_28 = F_17 ( V_30 , struct V_27 , V_32 ) ;
F_11 ( & V_28 -> V_86 ) ;
F_84 (state, &sp->so_states, open_states) {
if ( ! F_26 ( V_191 ,
& V_95 -> V_80 ) )
continue;
F_151 ( V_2 , V_95 ) ;
}
F_12 ( & V_28 -> V_86 ) ;
}
F_12 ( & V_2 -> V_24 ) ;
}
static int F_171 ( struct V_1 * V_2 )
{
struct V_25 * V_26 ;
if ( ! F_26 ( V_195 , & V_2 -> V_14 ) )
return 0 ;
F_20 () ;
F_21 (server, &clp->cl_superblocks, client_link)
F_170 ( V_26 ) ;
F_22 () ;
F_172 ( V_2 ) ;
return 1 ;
}
static void F_173 ( struct V_1 * V_2 )
{
if ( ! F_171 ( V_2 ) )
return;
F_169 ( V_2 , V_2 -> V_226 -> V_227 ) ;
}
static void F_174 ( struct V_1 * V_2 )
{
F_168 ( V_2 ) ;
F_172 ( V_2 ) ;
}
static void F_175 ( struct V_1 * V_2 )
{
F_174 ( V_2 ) ;
F_166 ( V_2 , F_151 ) ;
}
static void F_176 ( const char * V_228 )
{
F_177 ( V_229 L_16
L_17
L_18 ,
V_228 ) ;
}
static int F_178 ( struct V_1 * V_2 , int error )
{
switch ( error ) {
case 0 :
break;
case - V_230 :
F_147 ( V_2 ) ;
break;
case - V_211 :
F_173 ( V_2 ) ;
break;
case - V_168 :
case - V_231 :
F_4 ( V_188 , & V_2 -> V_14 ) ;
F_171 ( V_2 ) ;
F_167 ( V_2 ) ;
break;
case - V_210 :
F_4 ( V_188 , & V_2 -> V_14 ) ;
F_175 ( V_2 ) ;
break;
case - V_212 :
case - V_213 :
case - V_214 :
case - V_232 :
case - V_233 :
case - V_234 :
F_4 ( V_61 , & V_2 -> V_14 ) ;
break;
case - V_215 :
F_4 ( V_63 , & V_2 -> V_14 ) ;
break;
case - V_223 :
F_176 ( V_2 -> V_190 ) ;
break;
default:
F_146 ( L_19 ,
V_187 , error , V_2 -> V_190 ) ;
return error ;
}
F_146 ( L_20 , V_187 , error ,
V_2 -> V_190 ) ;
return 0 ;
}
static int F_179 ( struct V_1 * V_2 , const struct V_201 * V_202 )
{
struct V_27 * V_28 ;
struct V_25 * V_26 ;
struct V_29 * V_30 ;
int V_12 = 0 ;
V_219:
F_20 () ;
F_21 (server, &clp->cl_superblocks, client_link) {
F_77 ( V_26 ) ;
F_11 ( & V_2 -> V_24 ) ;
for ( V_30 = F_15 ( & V_26 -> V_31 ) ;
V_30 != NULL ;
V_30 = F_16 ( V_30 ) ) {
V_28 = F_17 ( V_30 ,
struct V_27 , V_32 ) ;
if ( ! F_26 ( V_202 -> V_235 ,
& V_28 -> V_194 ) )
continue;
F_42 ( & V_28 -> V_70 ) ;
F_12 ( & V_2 -> V_24 ) ;
F_22 () ;
V_12 = F_162 ( V_28 , V_202 ) ;
if ( V_12 < 0 ) {
F_4 ( V_202 -> V_235 , & V_28 -> V_194 ) ;
F_74 ( V_28 ) ;
return F_178 ( V_2 , V_12 ) ;
}
F_74 ( V_28 ) ;
goto V_219;
}
F_12 ( & V_2 -> V_24 ) ;
}
F_22 () ;
return V_12 ;
}
static int F_180 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
const struct V_236 * V_202 =
V_2 -> V_226 -> V_237 ;
int V_12 ;
if ( F_2 ( V_188 , & V_2 -> V_14 ) )
return 0 ;
F_11 ( & V_2 -> V_24 ) ;
V_4 = V_202 -> V_238 ( V_2 ) ;
F_12 ( & V_2 -> V_24 ) ;
if ( V_4 == NULL ) {
V_4 = F_39 ( V_2 ) ;
V_12 = - V_239 ;
if ( V_4 == NULL )
goto V_22;
}
V_12 = V_202 -> V_240 ( V_2 , V_4 ) ;
F_13 ( V_4 ) ;
V_22:
return F_178 ( V_2 , V_12 ) ;
}
static int F_181 ( struct V_1 * V_2 , int V_12 )
{
switch ( V_12 ) {
case - V_234 :
if ( F_136 ( V_241 , & V_2 -> V_14 ) )
return - V_242 ;
F_182 ( 1 ) ;
case - V_243 :
case - V_168 :
F_6 ( V_13 , & V_2 -> V_14 ) ;
break;
case - V_244 :
if ( V_2 -> V_23 == NULL )
return - V_244 ;
F_10 ( V_2 ) ;
case - V_245 :
case - V_246 :
case - V_92 :
F_182 ( 1 ) ;
break;
case - V_247 :
if ( V_2 -> V_248 == V_249 )
F_36 ( V_2 , - V_250 ) ;
F_146 ( L_21 ,
V_187 , - V_250 , V_2 -> V_190 ) ;
return - V_250 ;
case - V_223 :
F_176 ( V_2 -> V_190 ) ;
case - V_251 :
default:
F_146 ( L_21 , V_187 ,
V_12 , V_2 -> V_190 ) ;
return V_12 ;
}
F_4 ( V_188 , & V_2 -> V_14 ) ;
F_146 ( L_20 , V_187 , V_12 ,
V_2 -> V_190 ) ;
return 0 ;
}
static int F_183 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
const struct V_201 * V_202 =
V_2 -> V_226 -> V_227 ;
int V_12 ;
V_4 = V_202 -> V_252 ( V_2 ) ;
if ( V_4 == NULL )
return - V_222 ;
V_12 = V_202 -> V_253 ( V_2 , V_4 ) ;
F_13 ( V_4 ) ;
if ( V_12 != 0 )
return F_181 ( V_2 , V_12 ) ;
return 0 ;
}
void F_184 ( struct V_44 * V_254 , int V_73 )
{
struct V_1 * V_2 = V_254 -> V_2 ;
switch ( V_73 ) {
default:
F_4 ( V_61 , & V_2 -> V_14 ) ;
break;
case - V_215 :
F_4 ( V_63 , & V_2 -> V_14 ) ;
}
F_145 ( V_2 ) ;
}
void F_185 ( struct V_1 * V_2 )
{
F_4 ( V_62 , & V_2 -> V_14 ) ;
F_146 ( L_22 , V_187 ,
V_2 -> V_190 ) ;
F_135 ( V_2 ) ;
}
static void F_186 ( struct V_1 * V_2 )
{
if ( F_136 ( V_188 , & V_2 -> V_14 ) == 0 ) {
F_4 ( V_241 , & V_2 -> V_14 ) ;
F_6 ( V_13 , & V_2 -> V_14 ) ;
F_175 ( V_2 ) ;
F_146 ( L_23 ,
V_187 , V_2 -> V_190 ) ;
F_135 ( V_2 ) ;
}
}
static void F_187 ( struct V_1 * V_2 )
{
if ( F_136 ( V_188 , & V_2 -> V_14 ) == 0 ) {
F_167 ( V_2 ) ;
F_146 ( L_24 , V_187 ,
V_2 -> V_190 ) ;
F_135 ( V_2 ) ;
}
}
static void F_188 ( struct V_1 * V_2 )
{
F_186 ( V_2 ) ;
F_146 ( L_25 , V_187 , V_2 -> V_190 ) ;
}
static void F_189 ( struct V_1 * V_2 )
{
F_148 ( V_2 ) ;
F_146 ( L_26 , V_187 ,
V_2 -> V_190 ) ;
}
static void F_190 ( struct V_1 * V_2 )
{
F_148 ( V_2 ) ;
if ( F_136 ( V_61 , & V_2 -> V_14 ) == 0 )
F_135 ( V_2 ) ;
F_146 ( L_27 , V_187 ,
V_2 -> V_190 ) ;
}
static void F_191 ( struct V_1 * V_2 )
{
if ( F_136 ( V_63 ,
& V_2 -> V_14 ) == 0 )
F_135 ( V_2 ) ;
}
void F_192 ( struct V_1 * V_2 , T_6 V_80 )
{
if ( ! V_80 )
return;
F_146 ( L_28 ,
V_187 , V_2 -> V_190 , V_2 -> V_8 , V_80 ) ;
if ( V_80 & V_255 )
F_187 ( V_2 ) ;
if ( V_80 & ( V_256 |
V_257 |
V_258 |
V_259 ) )
F_188 ( V_2 ) ;
if ( V_80 & V_260 )
F_189 ( V_2 ) ;
if ( V_80 & V_261 )
F_190 ( V_2 ) ;
else if ( V_80 & ( V_262 |
V_263 ) )
F_191 ( V_2 ) ;
}
static int F_193 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
int V_12 ;
F_31 ( V_2 ) ;
V_4 = F_37 ( V_2 ) ;
V_12 = F_194 ( V_2 -> V_46 , V_4 ) ;
if ( V_12 && V_12 != - V_212 &&
V_12 != - V_232 ) {
V_12 = F_178 ( V_2 , V_12 ) ;
goto V_22;
}
memset ( V_2 -> V_46 -> V_264 . V_265 , 0 , V_266 ) ;
V_12 = F_35 ( V_2 , V_4 ) ;
if ( V_12 ) {
F_146 ( L_29 ,
V_187 , V_12 , V_2 -> V_190 ) ;
V_12 = F_181 ( V_2 , V_12 ) ;
goto V_22;
}
F_32 ( V_2 ) ;
F_146 ( L_30 ,
V_187 , V_2 -> V_190 ) ;
V_22:
if ( V_4 )
F_13 ( V_4 ) ;
return V_12 ;
}
static int F_195 ( struct V_1 * V_2 )
{
struct V_47 * V_267 = & V_2 -> V_46 -> V_50 ;
struct V_268 * V_269 = & V_2 -> V_46 -> V_269 ;
struct V_270 * V_71 , * V_271 ;
int V_272 ;
F_31 ( V_2 ) ;
V_71 = F_116 ( V_267 -> V_273 * sizeof( struct V_270 ) ,
V_96 ) ;
if ( ! V_71 )
return - V_156 ;
F_11 ( & V_267 -> V_53 ) ;
for ( V_272 = 0 ; V_272 < V_267 -> V_273 ; V_272 ++ )
V_71 [ V_272 ] . V_274 = V_267 -> V_275 [ V_272 ] . V_274 ;
V_271 = V_267 -> V_275 ;
V_267 -> V_275 = V_71 ;
V_267 -> V_49 = V_267 -> V_273 ;
V_267 -> V_273 = 0 ;
V_269 -> V_276 = V_267 -> V_49 ;
F_12 ( & V_267 -> V_53 ) ;
F_65 ( V_271 ) ;
F_25 ( V_2 ) ;
return 0 ;
}
static int F_196 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
int V_59 ;
F_31 ( V_2 ) ;
V_4 = F_37 ( V_2 ) ;
V_59 = F_197 ( V_2 , V_4 ) ;
if ( V_4 )
F_13 ( V_4 ) ;
F_6 ( V_63 , & V_2 -> V_14 ) ;
switch ( V_59 ) {
case 0 :
F_146 ( L_31 ,
V_187 , V_2 -> V_190 ) ;
break;
case - V_245 :
F_182 ( 1 ) ;
F_4 ( V_63 , & V_2 -> V_14 ) ;
break;
default:
return F_178 ( V_2 , V_59 ) ;
}
return 0 ;
}
static int F_193 ( struct V_1 * V_2 ) { return 0 ; }
static int F_25 ( struct V_1 * V_2 ) { return 0 ; }
static int F_195 ( struct V_1 * V_2 ) { return 0 ; }
static int F_196 ( struct V_1 * V_2 )
{
return 0 ;
}
static void F_198 ( struct V_1 * V_2 )
{
int V_12 = 0 ;
do {
if ( F_2 ( V_241 , & V_2 -> V_14 ) ) {
V_12 = F_183 ( V_2 ) ;
if ( V_12 < 0 )
goto V_277;
F_6 ( V_241 , & V_2 -> V_14 ) ;
F_4 ( V_188 , & V_2 -> V_14 ) ;
}
if ( F_26 ( V_188 , & V_2 -> V_14 ) ) {
V_12 = F_183 ( V_2 ) ;
if ( V_12 < 0 )
goto V_277;
if ( F_2 ( V_188 , & V_2 -> V_14 ) )
continue;
F_6 ( V_189 , & V_2 -> V_14 ) ;
if ( F_26 ( V_278 ,
& V_2 -> V_14 ) )
F_175 ( V_2 ) ;
else
F_4 ( V_195 ,
& V_2 -> V_14 ) ;
F_199 ( V_2 ) ;
}
if ( F_26 ( V_189 , & V_2 -> V_14 ) ) {
V_12 = F_180 ( V_2 ) ;
if ( V_12 < 0 )
goto V_277;
if ( F_2 ( V_188 , & V_2 -> V_14 ) )
continue;
}
if ( F_26 ( V_61 , & V_2 -> V_14 )
&& F_126 ( V_2 ) ) {
V_12 = F_193 ( V_2 ) ;
if ( F_2 ( V_188 , & V_2 -> V_14 ) )
continue;
if ( V_12 < 0 )
goto V_277;
}
if ( F_26 ( V_63 ,
& V_2 -> V_14 ) && F_126 ( V_2 ) ) {
V_12 = F_196 ( V_2 ) ;
if ( V_12 < 0 )
goto V_277;
continue;
}
if ( F_2 ( V_195 , & V_2 -> V_14 ) ) {
V_12 = F_179 ( V_2 ,
V_2 -> V_226 -> V_227 ) ;
if ( F_2 ( V_188 , & V_2 -> V_14 ) ||
F_2 ( V_61 , & V_2 -> V_14 ) )
continue;
F_173 ( V_2 ) ;
if ( F_2 ( V_197 , & V_2 -> V_14 ) )
continue;
if ( V_12 < 0 )
goto V_277;
}
if ( F_26 ( V_197 , & V_2 -> V_14 ) ) {
V_12 = F_179 ( V_2 ,
V_2 -> V_226 -> V_279 ) ;
if ( F_2 ( V_188 , & V_2 -> V_14 ) ||
F_2 ( V_61 , & V_2 -> V_14 ) ||
F_2 ( V_195 , & V_2 -> V_14 ) )
continue;
if ( V_12 < 0 )
goto V_277;
}
F_25 ( V_2 ) ;
if ( F_26 ( V_280 , & V_2 -> V_14 ) ) {
F_200 ( V_2 ) ;
continue;
}
if ( F_26 ( V_62 , & V_2 -> V_14 )
&& F_126 ( V_2 ) ) {
V_12 = F_195 ( V_2 ) ;
if ( V_12 < 0 )
goto V_277;
continue;
}
F_130 ( V_2 ) ;
if ( V_2 -> V_14 == 0 )
break;
if ( F_136 ( V_176 , & V_2 -> V_14 ) != 0 )
break;
} while ( F_201 ( & V_2 -> V_182 ) > 1 );
return;
V_277:
F_123 ( L_32
L_33 , V_2 -> V_190 , - V_12 ) ;
F_25 ( V_2 ) ;
F_130 ( V_2 ) ;
}
static int V_185 ( void * V_281 )
{
struct V_1 * V_2 = V_281 ;
F_202 ( V_282 ) ;
F_198 ( V_2 ) ;
F_143 ( V_2 ) ;
F_203 ( 0 ) ;
return 0 ;
}
