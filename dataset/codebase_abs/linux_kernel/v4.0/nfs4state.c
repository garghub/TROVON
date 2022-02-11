int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_5 V_6 = {
. V_7 = V_2 -> V_8 ,
. V_9 = V_2 -> V_10 ,
} ;
unsigned short V_11 ;
int V_12 ;
struct V_13 * V_14 = F_2 ( V_2 -> V_15 , V_16 ) ;
if ( F_3 ( V_17 , & V_2 -> V_18 ) )
goto V_19;
V_11 = V_14 -> V_20 ;
if ( V_2 -> V_21 . V_22 == V_23 )
V_11 = V_14 -> V_24 ;
V_12 = F_4 ( V_2 , V_25 , V_11 , V_4 , & V_6 ) ;
if ( V_12 != 0 )
goto V_26;
V_2 -> V_8 = V_6 . V_7 ;
V_2 -> V_10 = V_6 . V_9 ;
F_5 ( V_17 , & V_2 -> V_18 ) ;
V_19:
V_12 = F_6 ( V_2 , & V_6 , V_4 ) ;
if ( V_12 != 0 )
goto V_26;
F_7 ( V_17 , & V_2 -> V_18 ) ;
F_8 ( V_2 ) ;
V_26:
return V_12 ;
}
int F_9 ( struct V_1 * V_2 ,
struct V_1 * * V_27 ,
struct V_3 * V_4 )
{
struct V_5 V_6 = {
. V_7 = V_2 -> V_8 ,
. V_9 = V_2 -> V_10 ,
} ;
struct V_13 * V_14 = F_2 ( V_2 -> V_15 , V_16 ) ;
unsigned short V_11 ;
int V_12 ;
V_11 = V_14 -> V_20 ;
if ( V_2 -> V_21 . V_22 == V_23 )
V_11 = V_14 -> V_24 ;
V_12 = F_4 ( V_2 , V_25 , V_11 , V_4 , & V_6 ) ;
if ( V_12 != 0 )
goto V_26;
V_2 -> V_8 = V_6 . V_7 ;
V_2 -> V_10 = V_6 . V_9 ;
V_12 = F_10 ( V_2 , V_27 , V_4 ) ;
if ( V_12 == 0 ) {
F_8 ( * V_27 ) ;
}
V_26:
return V_12 ;
}
struct V_3 * F_11 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = NULL ;
if ( V_2 -> V_28 != NULL )
V_4 = F_12 ( V_2 -> V_28 ) ;
return V_4 ;
}
static void F_13 ( struct V_1 * V_2 )
{
struct V_3 * V_4 , * V_29 ;
V_29 = F_14 ( NULL ) ;
F_15 ( & V_2 -> V_30 ) ;
V_4 = V_2 -> V_28 ;
V_2 -> V_28 = V_29 ;
F_16 ( & V_2 -> V_30 ) ;
if ( V_4 != NULL )
F_17 ( V_4 ) ;
}
static struct V_3 *
F_18 ( struct V_31 * V_32 )
{
struct V_3 * V_4 = NULL ;
struct V_33 * V_34 ;
struct V_35 * V_36 ;
for ( V_36 = F_19 ( & V_32 -> V_37 ) ;
V_36 != NULL ;
V_36 = F_20 ( V_36 ) ) {
V_34 = F_21 ( V_36 , struct V_33 , V_38 ) ;
if ( F_22 ( & V_34 -> V_39 ) )
continue;
V_4 = F_12 ( V_34 -> V_40 ) ;
break;
}
return V_4 ;
}
struct V_3 * F_23 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = NULL ;
struct V_31 * V_32 ;
V_4 = F_11 ( V_2 ) ;
if ( V_4 != NULL )
goto V_26;
F_24 () ;
F_25 (server, &clp->cl_superblocks, client_link) {
V_4 = F_18 ( V_32 ) ;
if ( V_4 != NULL )
break;
}
F_26 () ;
V_26:
return V_4 ;
}
static void F_27 ( struct V_41 * V_42 )
{
if ( F_28 ( V_43 , & V_42 -> V_44 ) ) {
F_15 ( & V_42 -> V_45 ) ;
F_29 ( V_42 ) ;
F_16 ( & V_42 -> V_45 ) ;
}
}
static void F_30 ( struct V_1 * V_2 )
{
struct V_46 * V_47 = V_2 -> V_48 ;
if ( V_2 -> V_49 ) {
F_27 ( V_2 -> V_49 ) ;
return;
}
if ( V_47 != NULL ) {
F_27 ( & V_47 -> V_50 ) ;
F_27 ( & V_47 -> V_51 ) ;
}
}
static int F_31 ( struct V_41 * V_42 )
{
F_5 ( V_43 , & V_42 -> V_44 ) ;
F_15 ( & V_42 -> V_45 ) ;
if ( V_42 -> V_52 != V_53 ) {
F_32 ( & V_42 -> V_54 ) ;
F_16 ( & V_42 -> V_45 ) ;
return F_33 ( & V_42 -> V_54 ) ;
}
F_16 ( & V_42 -> V_45 ) ;
return 0 ;
}
static int F_34 ( struct V_1 * V_2 )
{
struct V_46 * V_47 = V_2 -> V_48 ;
int V_55 = 0 ;
if ( V_2 -> V_49 )
return F_31 ( V_2 -> V_49 ) ;
V_55 = F_31 ( & V_47 -> V_50 ) ;
if ( V_55 )
return V_55 ;
return F_31 ( & V_47 -> V_51 ) ;
}
static int F_35 ( struct V_1 * V_2 )
{
int V_12 ;
struct V_56 V_57 ;
if ( ! F_3 ( V_58 , & V_2 -> V_59 ) ) {
F_8 ( V_2 ) ;
return 0 ;
}
V_12 = F_36 ( V_2 , & V_57 ) ;
if ( V_12 == 0 ) {
F_15 ( & V_2 -> V_30 ) ;
V_2 -> V_60 = V_57 . V_61 * V_62 ;
V_2 -> V_63 = V_64 ;
F_16 ( & V_2 -> V_30 ) ;
F_8 ( V_2 ) ;
}
return V_12 ;
}
static void F_37 ( struct V_1 * V_2 )
{
F_7 ( V_17 , & V_2 -> V_18 ) ;
F_7 ( V_65 , & V_2 -> V_18 ) ;
F_7 ( V_66 , & V_2 -> V_18 ) ;
F_35 ( V_2 ) ;
}
int F_38 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
int V_12 ;
if ( F_3 ( V_17 , & V_2 -> V_18 ) )
goto V_19;
F_34 ( V_2 ) ;
V_12 = F_39 ( V_2 , V_4 ) ;
if ( V_12 != 0 )
goto V_26;
F_5 ( V_17 , & V_2 -> V_18 ) ;
V_19:
V_12 = F_40 ( V_2 , V_4 ) ;
if ( V_12 != 0 )
goto V_26;
F_37 ( V_2 ) ;
F_41 ( V_2 , V_67 ) ;
V_26:
return V_12 ;
}
int F_42 ( struct V_1 * V_2 ,
struct V_1 * * V_27 ,
struct V_3 * V_4 )
{
int V_12 ;
V_12 = F_39 ( V_2 , V_4 ) ;
if ( V_12 != V_68 )
return V_12 ;
V_12 = F_43 ( V_2 , V_27 , V_4 ) ;
if ( V_12 < 0 )
return V_12 ;
if ( V_2 != * V_27 )
return 0 ;
if ( V_2 -> V_69 & V_70 )
F_5 ( V_71 , & V_2 -> V_18 ) ;
else
F_5 ( V_17 , & V_2 -> V_18 ) ;
F_44 ( V_2 ) ;
V_12 = F_45 ( V_2 ) ;
if ( V_12 < 0 )
F_46 ( V_2 ) ;
return V_12 ;
}
struct V_3 * F_47 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
F_15 ( & V_2 -> V_30 ) ;
V_4 = F_11 ( V_2 ) ;
F_16 ( & V_2 -> V_30 ) ;
return V_4 ;
}
static struct V_33 *
F_48 ( struct V_31 * V_32 , struct V_3 * V_4 )
{
struct V_35 * * V_72 = & V_32 -> V_37 . V_35 ,
* V_73 = NULL ;
struct V_33 * V_34 ;
while ( * V_72 != NULL ) {
V_73 = * V_72 ;
V_34 = F_21 ( V_73 , struct V_33 , V_38 ) ;
if ( V_4 < V_34 -> V_40 )
V_72 = & V_73 -> V_74 ;
else if ( V_4 > V_34 -> V_40 )
V_72 = & V_73 -> V_75 ;
else {
if ( ! F_22 ( & V_34 -> V_76 ) )
F_49 ( & V_34 -> V_76 ) ;
F_50 ( & V_34 -> V_77 ) ;
return V_34 ;
}
}
return NULL ;
}
static struct V_33 *
F_51 ( struct V_33 * V_29 )
{
struct V_31 * V_32 = V_29 -> V_78 ;
struct V_35 * * V_72 = & V_32 -> V_37 . V_35 ,
* V_73 = NULL ;
struct V_33 * V_34 ;
int V_79 ;
while ( * V_72 != NULL ) {
V_73 = * V_72 ;
V_34 = F_21 ( V_73 , struct V_33 , V_38 ) ;
if ( V_29 -> V_40 < V_34 -> V_40 )
V_72 = & V_73 -> V_74 ;
else if ( V_29 -> V_40 > V_34 -> V_40 )
V_72 = & V_73 -> V_75 ;
else {
if ( ! F_22 ( & V_34 -> V_76 ) )
F_49 ( & V_34 -> V_76 ) ;
F_50 ( & V_34 -> V_77 ) ;
return V_34 ;
}
}
V_79 = F_52 ( & V_32 -> V_80 , & V_29 -> V_81 . V_82 ) ;
if ( V_79 )
return F_53 ( V_79 ) ;
F_54 ( & V_29 -> V_38 , V_73 , V_72 ) ;
F_55 ( & V_29 -> V_38 , & V_32 -> V_37 ) ;
return V_29 ;
}
static void
F_56 ( struct V_33 * V_34 )
{
struct V_31 * V_32 = V_34 -> V_78 ;
if ( ! F_57 ( & V_34 -> V_38 ) )
F_58 ( & V_34 -> V_38 , & V_32 -> V_37 ) ;
F_59 ( & V_32 -> V_80 , V_34 -> V_81 . V_82 ) ;
}
static void
F_60 ( struct V_83 * V_84 )
{
V_84 -> V_85 = F_61 () ;
V_84 -> V_86 = 0 ;
V_84 -> V_87 = 0 ;
F_62 ( & V_84 -> V_88 ) ;
F_63 ( & V_84 -> V_89 ) ;
F_64 ( & V_84 -> V_90 , L_1 ) ;
}
static void
F_65 ( struct V_83 * V_84 )
{
F_66 ( & V_84 -> V_90 ) ;
}
static struct V_33 *
F_67 ( struct V_31 * V_32 ,
struct V_3 * V_4 ,
T_1 V_91 )
{
struct V_33 * V_34 ;
V_34 = F_68 ( sizeof( * V_34 ) , V_91 ) ;
if ( ! V_34 )
return NULL ;
V_34 -> V_78 = V_32 ;
V_34 -> V_40 = F_12 ( V_4 ) ;
F_62 ( & V_34 -> V_92 ) ;
F_63 ( & V_34 -> V_39 ) ;
F_60 ( & V_34 -> V_81 ) ;
F_69 ( & V_34 -> V_77 , 1 ) ;
F_63 ( & V_34 -> V_76 ) ;
F_70 ( & V_34 -> V_93 ) ;
F_71 ( & V_34 -> V_94 ) ;
return V_34 ;
}
static void
F_72 ( struct V_33 * V_34 )
{
struct V_35 * V_35 = & V_34 -> V_38 ;
if ( ! F_57 ( V_35 ) ) {
struct V_31 * V_32 = V_34 -> V_78 ;
struct V_1 * V_2 = V_32 -> V_1 ;
F_15 ( & V_2 -> V_30 ) ;
if ( ! F_57 ( V_35 ) ) {
F_58 ( V_35 , & V_32 -> V_37 ) ;
F_73 ( V_35 ) ;
}
F_16 ( & V_2 -> V_30 ) ;
}
}
static void F_74 ( struct V_33 * V_34 )
{
F_65 ( & V_34 -> V_81 ) ;
F_17 ( V_34 -> V_40 ) ;
F_75 ( V_34 ) ;
}
static void F_76 ( struct V_31 * V_32 )
{
struct V_1 * V_2 = V_32 -> V_1 ;
struct V_33 * V_34 , * V_95 ;
unsigned long V_96 , V_97 ;
F_77 ( V_98 ) ;
F_15 ( & V_2 -> V_30 ) ;
V_97 = V_64 ;
V_96 = ( long ) V_97 - ( long ) V_2 -> V_60 ;
F_78 (sp, tmp, &server->state_owners_lru, so_lru) {
if ( F_79 ( V_34 -> V_99 , V_96 , V_97 ) )
break;
F_80 ( & V_34 -> V_76 , & V_98 ) ;
F_56 ( V_34 ) ;
}
F_16 ( & V_2 -> V_30 ) ;
F_78 (sp, tmp, &doomed, so_lru) {
F_81 ( & V_34 -> V_76 ) ;
F_74 ( V_34 ) ;
}
}
struct V_33 * F_82 ( struct V_31 * V_32 ,
struct V_3 * V_4 ,
T_1 V_91 )
{
struct V_1 * V_2 = V_32 -> V_1 ;
struct V_33 * V_34 , * V_29 ;
F_15 ( & V_2 -> V_30 ) ;
V_34 = F_48 ( V_32 , V_4 ) ;
F_16 ( & V_2 -> V_30 ) ;
if ( V_34 != NULL )
goto V_26;
V_29 = F_67 ( V_32 , V_4 , V_91 ) ;
if ( V_29 == NULL )
goto V_26;
do {
if ( F_83 ( & V_32 -> V_80 , V_91 ) == 0 )
break;
F_15 ( & V_2 -> V_30 ) ;
V_34 = F_51 ( V_29 ) ;
F_16 ( & V_2 -> V_30 ) ;
} while ( V_34 == F_53 ( - V_100 ) );
if ( V_34 != V_29 )
F_74 ( V_29 ) ;
V_26:
F_76 ( V_32 ) ;
return V_34 ;
}
void F_84 ( struct V_33 * V_34 )
{
struct V_31 * V_32 = V_34 -> V_78 ;
struct V_1 * V_2 = V_32 -> V_1 ;
if ( ! F_85 ( & V_34 -> V_77 , & V_2 -> V_30 ) )
return;
V_34 -> V_99 = V_64 ;
F_86 ( & V_34 -> V_76 , & V_32 -> V_101 ) ;
F_16 ( & V_2 -> V_30 ) ;
}
void F_87 ( struct V_31 * V_32 )
{
struct V_1 * V_2 = V_32 -> V_1 ;
struct V_33 * V_34 , * V_95 ;
F_77 ( V_98 ) ;
F_15 ( & V_2 -> V_30 ) ;
F_78 (sp, tmp, &server->state_owners_lru, so_lru) {
F_80 ( & V_34 -> V_76 , & V_98 ) ;
F_56 ( V_34 ) ;
}
F_16 ( & V_2 -> V_30 ) ;
F_78 (sp, tmp, &doomed, so_lru) {
F_81 ( & V_34 -> V_76 ) ;
F_74 ( V_34 ) ;
}
}
static struct V_102 *
F_88 ( void )
{
struct V_102 * V_103 ;
V_103 = F_68 ( sizeof( * V_103 ) , V_104 ) ;
if ( ! V_103 )
return NULL ;
F_69 ( & V_103 -> V_105 , 1 ) ;
F_63 ( & V_103 -> V_106 ) ;
F_62 ( & V_103 -> V_107 ) ;
F_89 ( & V_103 -> V_108 ) ;
return V_103 ;
}
void
F_90 ( struct V_102 * V_103 , T_2 V_109 )
{
if ( V_103 -> V_103 == V_109 )
return;
if ( ( V_109 & V_110 ) != ( V_103 -> V_103 & V_110 ) ) {
if ( V_109 & V_110 )
F_80 ( & V_103 -> V_111 , & V_103 -> V_112 -> V_39 ) ;
else
F_91 ( & V_103 -> V_111 , & V_103 -> V_112 -> V_39 ) ;
}
V_103 -> V_103 = V_109 ;
}
static struct V_102 *
F_92 ( struct V_113 * V_113 , struct V_33 * V_112 )
{
struct V_114 * V_115 = F_93 ( V_113 ) ;
struct V_102 * V_103 ;
F_94 (state, &nfsi->open_states, inode_states) {
if ( V_103 -> V_112 != V_112 )
continue;
if ( ! F_95 ( V_103 ) )
continue;
if ( F_96 ( & V_103 -> V_105 ) )
return V_103 ;
}
return NULL ;
}
static void
F_97 ( struct V_102 * V_103 )
{
F_75 ( V_103 ) ;
}
struct V_102 *
F_98 ( struct V_113 * V_113 , struct V_33 * V_112 )
{
struct V_102 * V_103 , * V_29 ;
struct V_114 * V_115 = F_93 ( V_113 ) ;
F_15 ( & V_113 -> V_116 ) ;
V_103 = F_92 ( V_113 , V_112 ) ;
F_16 ( & V_113 -> V_116 ) ;
if ( V_103 )
goto V_26;
V_29 = F_88 () ;
F_15 ( & V_112 -> V_92 ) ;
F_15 ( & V_113 -> V_116 ) ;
V_103 = F_92 ( V_113 , V_112 ) ;
if ( V_103 == NULL && V_29 != NULL ) {
V_103 = V_29 ;
V_103 -> V_112 = V_112 ;
F_50 ( & V_112 -> V_77 ) ;
F_99 ( & V_103 -> V_117 , & V_115 -> V_111 ) ;
F_100 ( V_113 ) ;
V_103 -> V_113 = V_113 ;
F_16 ( & V_113 -> V_116 ) ;
F_86 ( & V_103 -> V_111 , & V_112 -> V_39 ) ;
F_16 ( & V_112 -> V_92 ) ;
} else {
F_16 ( & V_113 -> V_116 ) ;
F_16 ( & V_112 -> V_92 ) ;
if ( V_29 )
F_97 ( V_29 ) ;
}
V_26:
return V_103 ;
}
void F_101 ( struct V_102 * V_103 )
{
struct V_113 * V_113 = V_103 -> V_113 ;
struct V_33 * V_112 = V_103 -> V_112 ;
if ( ! F_85 ( & V_103 -> V_105 , & V_112 -> V_92 ) )
return;
F_15 ( & V_113 -> V_116 ) ;
F_81 ( & V_103 -> V_117 ) ;
F_81 ( & V_103 -> V_111 ) ;
F_16 ( & V_113 -> V_116 ) ;
F_16 ( & V_112 -> V_92 ) ;
F_102 ( V_113 ) ;
F_97 ( V_103 ) ;
F_84 ( V_112 ) ;
}
static void F_103 ( struct V_102 * V_103 ,
T_2 V_109 , T_1 V_118 , int V_90 )
{
struct V_33 * V_112 = V_103 -> V_112 ;
int V_119 = 0 ;
T_2 V_120 ;
F_50 ( & V_112 -> V_77 ) ;
F_15 ( & V_112 -> V_92 ) ;
switch ( V_109 & ( V_121 | V_110 ) ) {
case V_121 :
V_103 -> V_122 -- ;
break;
case V_110 :
V_103 -> V_123 -- ;
break;
case V_121 | V_110 :
V_103 -> V_124 -- ;
}
V_120 = V_121 | V_110 ;
if ( V_103 -> V_124 == 0 ) {
if ( V_103 -> V_122 == 0 ) {
V_120 &= ~ V_121 ;
V_119 |= F_3 ( V_125 , & V_103 -> V_86 ) ;
V_119 |= F_3 ( V_126 , & V_103 -> V_86 ) ;
}
if ( V_103 -> V_123 == 0 ) {
V_120 &= ~ V_110 ;
V_119 |= F_3 ( V_127 , & V_103 -> V_86 ) ;
V_119 |= F_3 ( V_126 , & V_103 -> V_86 ) ;
}
if ( V_120 == 0 )
F_7 ( V_128 , & V_103 -> V_86 ) ;
}
F_90 ( V_103 , V_120 ) ;
F_16 ( & V_112 -> V_92 ) ;
if ( ! V_119 ) {
F_101 ( V_103 ) ;
F_84 ( V_112 ) ;
} else
F_104 ( V_103 , V_118 , V_90 ) ;
}
void F_105 ( struct V_102 * V_103 , T_2 V_109 )
{
F_103 ( V_103 , V_109 , V_104 , 0 ) ;
}
void F_106 ( struct V_102 * V_103 , T_2 V_109 )
{
F_103 ( V_103 , V_109 , V_129 , 1 ) ;
}
static struct V_130 *
F_107 ( struct V_102 * V_103 , T_3 V_131 )
{
struct V_130 * V_36 ;
F_94 (pos, &state->lock_states, ls_locks) {
if ( V_36 -> V_132 != V_131 )
continue;
F_50 ( & V_36 -> V_133 ) ;
return V_36 ;
}
return NULL ;
}
static struct V_130 * F_108 ( struct V_102 * V_103 , T_3 V_131 )
{
struct V_130 * V_134 ;
struct V_31 * V_32 = V_103 -> V_112 -> V_78 ;
V_134 = F_68 ( sizeof( * V_134 ) , V_104 ) ;
if ( V_134 == NULL )
return NULL ;
F_60 ( & V_134 -> V_135 ) ;
F_69 ( & V_134 -> V_133 , 1 ) ;
V_134 -> V_136 = V_103 ;
V_134 -> V_132 = V_131 ;
V_134 -> V_135 . V_82 = F_109 ( & V_32 -> V_137 , 0 , 0 , V_104 ) ;
if ( V_134 -> V_135 . V_82 < 0 )
goto V_138;
F_63 ( & V_134 -> V_139 ) ;
return V_134 ;
V_138:
F_75 ( V_134 ) ;
return NULL ;
}
void F_110 ( struct V_31 * V_32 , struct V_130 * V_134 )
{
F_111 ( & V_32 -> V_137 , V_134 -> V_135 . V_82 ) ;
F_65 ( & V_134 -> V_135 ) ;
F_75 ( V_134 ) ;
}
static struct V_130 * F_112 ( struct V_102 * V_103 , T_3 V_112 )
{
struct V_130 * V_134 , * V_29 = NULL ;
for(; ; ) {
F_15 ( & V_103 -> V_107 ) ;
V_134 = F_107 ( V_103 , V_112 ) ;
if ( V_134 != NULL )
break;
if ( V_29 != NULL ) {
F_99 ( & V_29 -> V_139 , & V_103 -> V_106 ) ;
F_5 ( V_140 , & V_103 -> V_86 ) ;
V_134 = V_29 ;
V_29 = NULL ;
break;
}
F_16 ( & V_103 -> V_107 ) ;
V_29 = F_108 ( V_103 , V_112 ) ;
if ( V_29 == NULL )
return NULL ;
}
F_16 ( & V_103 -> V_107 ) ;
if ( V_29 != NULL )
F_110 ( V_103 -> V_112 -> V_78 , V_29 ) ;
return V_134 ;
}
void F_113 ( struct V_130 * V_134 )
{
struct V_31 * V_32 ;
struct V_102 * V_103 ;
if ( V_134 == NULL )
return;
V_103 = V_134 -> V_136 ;
if ( ! F_85 ( & V_134 -> V_133 , & V_103 -> V_107 ) )
return;
F_81 ( & V_134 -> V_139 ) ;
if ( F_22 ( & V_103 -> V_106 ) )
F_7 ( V_140 , & V_103 -> V_86 ) ;
F_16 ( & V_103 -> V_107 ) ;
V_32 = V_103 -> V_112 -> V_78 ;
if ( F_3 ( V_141 , & V_134 -> V_142 ) ) {
struct V_1 * V_2 = V_32 -> V_1 ;
V_2 -> V_143 -> V_144 ( V_32 , V_134 ) ;
} else
F_110 ( V_32 , V_134 ) ;
}
static void F_114 ( struct V_145 * V_146 , struct V_145 * V_147 )
{
struct V_130 * V_134 = V_147 -> V_148 . V_149 . V_112 ;
V_146 -> V_148 . V_149 . V_112 = V_134 ;
F_50 ( & V_134 -> V_133 ) ;
}
static void F_115 ( struct V_145 * V_150 )
{
F_113 ( V_150 -> V_148 . V_149 . V_112 ) ;
}
int F_116 ( struct V_102 * V_103 , struct V_145 * V_150 )
{
struct V_130 * V_134 ;
if ( V_150 -> V_151 != NULL )
return 0 ;
V_134 = F_112 ( V_103 , V_150 -> V_131 ) ;
if ( V_134 == NULL )
return - V_152 ;
V_150 -> V_148 . V_149 . V_112 = V_134 ;
V_150 -> V_151 = & V_153 ;
return 0 ;
}
static int F_117 ( T_4 * V_146 ,
struct V_102 * V_103 ,
const struct V_154 * V_155 )
{
struct V_130 * V_134 ;
T_3 V_131 ;
int V_55 = - V_156 ;
if ( V_155 == NULL )
goto V_26;
if ( F_3 ( V_140 , & V_103 -> V_86 ) == 0 )
goto V_26;
V_131 = V_155 -> V_157 ;
F_15 ( & V_103 -> V_107 ) ;
V_134 = F_107 ( V_103 , V_131 ) ;
if ( V_134 && F_3 ( V_158 , & V_134 -> V_142 ) )
V_55 = - V_159 ;
else if ( V_134 != NULL && F_3 ( V_141 , & V_134 -> V_142 ) != 0 ) {
F_118 ( V_146 , & V_134 -> V_160 ) ;
V_55 = 0 ;
}
F_16 ( & V_103 -> V_107 ) ;
F_113 ( V_134 ) ;
V_26:
return V_55 ;
}
static void F_119 ( T_4 * V_146 , struct V_102 * V_103 )
{
const T_4 * V_147 ;
int V_161 ;
do {
V_147 = & V_162 ;
V_161 = F_120 ( & V_103 -> V_108 ) ;
if ( F_3 ( V_163 , & V_103 -> V_86 ) )
V_147 = & V_103 -> V_164 ;
F_118 ( V_146 , V_147 ) ;
} while ( F_121 ( & V_103 -> V_108 , V_161 ) );
}
int F_122 ( T_4 * V_146 , struct V_102 * V_103 ,
T_2 V_109 , const struct V_154 * V_155 )
{
int V_55 = F_117 ( V_146 , V_103 , V_155 ) ;
if ( V_55 == - V_159 )
goto V_26;
if ( F_123 ( V_146 , V_103 -> V_113 , V_109 ) ) {
V_55 = 0 ;
goto V_26;
}
if ( V_55 != - V_156 )
goto V_26;
F_119 ( V_146 , V_103 ) ;
V_55 = 0 ;
V_26:
if ( F_124 ( V_103 -> V_113 , V_165 ) )
V_146 -> V_166 = 0 ;
return V_55 ;
}
struct V_167 * F_125 ( struct V_83 * V_87 , T_1 V_118 )
{
struct V_167 * V_29 ;
V_29 = F_126 ( sizeof( * V_29 ) , V_118 ) ;
if ( V_29 == NULL )
return F_53 ( - V_152 ) ;
V_29 -> V_168 = V_87 ;
F_63 ( & V_29 -> V_89 ) ;
V_29 -> V_169 = NULL ;
return V_29 ;
}
void F_127 ( struct V_167 * V_166 )
{
struct V_83 * V_168 ;
if ( V_166 == NULL || F_22 ( & V_166 -> V_89 ) )
return;
V_168 = V_166 -> V_168 ;
F_15 ( & V_168 -> V_88 ) ;
F_49 ( & V_166 -> V_89 ) ;
if ( ! F_22 ( & V_168 -> V_89 ) ) {
struct V_167 * V_170 ;
V_170 = F_128 ( & V_168 -> V_89 ,
struct V_167 , V_89 ) ;
F_129 ( & V_168 -> V_90 , V_170 -> V_169 ) ;
}
F_16 ( & V_168 -> V_88 ) ;
}
void F_130 ( struct V_167 * V_166 )
{
F_127 ( V_166 ) ;
F_75 ( V_166 ) ;
}
static void F_131 ( int V_12 , struct V_167 * V_166 )
{
switch ( V_12 ) {
case 0 :
break;
case - V_171 :
if ( V_166 -> V_168 -> V_86 & V_172 )
return;
F_132 ( L_2
L_3
L_4 ,
V_166 -> V_168 ) ;
case - V_173 :
case - V_174 :
case - V_175 :
case - V_176 :
case - V_177 :
case - V_178 :
return;
} ;
V_166 -> V_168 -> V_87 ++ ;
}
void F_133 ( int V_12 , struct V_167 * V_166 )
{
struct V_33 * V_34 ;
if ( V_166 == NULL )
return;
V_34 = F_134 ( V_166 -> V_168 , struct V_33 , V_81 ) ;
if ( V_12 == - V_171 )
F_72 ( V_34 ) ;
if ( ! F_135 ( V_34 -> V_78 -> V_1 ) )
F_131 ( V_12 , V_166 ) ;
}
void F_136 ( int V_12 , struct V_167 * V_166 )
{
if ( V_166 != NULL )
F_131 ( V_12 , V_166 ) ;
}
int F_137 ( struct V_167 * V_166 , struct V_179 * V_169 )
{
struct V_83 * V_168 ;
int V_12 = 0 ;
if ( V_166 == NULL )
goto V_26;
V_168 = V_166 -> V_168 ;
F_15 ( & V_168 -> V_88 ) ;
V_166 -> V_169 = V_169 ;
if ( F_22 ( & V_166 -> V_89 ) )
F_86 ( & V_166 -> V_89 , & V_168 -> V_89 ) ;
if ( F_128 ( & V_168 -> V_89 , struct V_167 , V_89 ) == V_166 )
goto V_180;
F_138 ( & V_168 -> V_90 , V_169 , NULL ) ;
V_12 = - V_100 ;
V_180:
F_16 ( & V_168 -> V_88 ) ;
V_26:
return V_12 ;
}
static void F_139 ( struct V_1 * V_2 )
{
F_140 () ;
F_7 ( V_181 , & V_2 -> V_18 ) ;
F_141 () ;
F_142 ( & V_2 -> V_18 , V_181 ) ;
F_143 ( & V_2 -> V_182 ) ;
}
void F_44 ( struct V_1 * V_2 )
{
struct V_183 * V_169 ;
char V_184 [ V_185 + sizeof( L_5 ) + 1 ] ;
if ( F_144 ( V_181 , & V_2 -> V_18 ) != 0 )
return;
F_145 ( V_186 ) ;
F_50 ( & V_2 -> V_187 ) ;
F_24 () ;
snprintf ( V_184 , sizeof( V_184 ) , L_6 ,
F_146 ( V_2 -> V_188 , V_189 ) ) ;
F_26 () ;
V_169 = F_147 ( V_190 , V_2 , L_7 , V_184 ) ;
if ( F_148 ( V_169 ) ) {
F_149 ( V_191 L_8 ,
V_192 , F_150 ( V_169 ) ) ;
F_139 ( V_2 ) ;
F_46 ( V_2 ) ;
F_151 ( V_186 ) ;
}
}
void F_152 ( struct V_1 * V_2 )
{
if ( ! V_2 )
return;
if ( ! F_3 ( V_193 , & V_2 -> V_18 ) )
F_5 ( V_194 , & V_2 -> V_18 ) ;
F_153 ( L_9 , V_192 ,
V_2 -> V_195 ) ;
F_44 ( V_2 ) ;
}
int F_154 ( const struct V_31 * V_32 )
{
struct V_1 * V_2 = V_32 -> V_1 ;
if ( V_32 -> V_196 != V_197 ) {
F_155 ( L_10 ,
V_2 -> V_195 ) ;
return - V_198 ;
}
if ( F_3 ( V_199 , & V_32 -> V_200 ) )
return - V_198 ;
F_153 ( L_11 ,
V_192 ,
( unsigned long long ) V_32 -> V_201 . V_202 ,
( unsigned long long ) V_32 -> V_201 . V_203 ,
V_2 -> V_195 ) ;
F_5 ( V_204 ,
& ( (struct V_31 * ) V_32 ) -> V_200 ) ;
F_5 ( V_205 , & V_2 -> V_18 ) ;
F_44 ( V_2 ) ;
return 0 ;
}
void F_156 ( struct V_1 * V_2 )
{
F_153 ( L_12 ,
V_192 , V_2 -> V_8 , V_2 -> V_195 ) ;
F_5 ( V_206 , & V_2 -> V_18 ) ;
F_44 ( V_2 ) ;
}
int F_157 ( struct V_1 * V_2 )
{
int V_207 ;
F_158 () ;
F_50 ( & V_2 -> V_187 ) ;
V_207 = F_159 ( & V_2 -> V_18 , V_181 ,
V_208 , V_209 ) ;
if ( V_207 )
goto V_26;
if ( V_2 -> V_210 < 0 )
V_207 = V_2 -> V_210 ;
V_26:
F_46 ( V_2 ) ;
return V_207 ;
}
int F_160 ( struct V_1 * V_2 )
{
unsigned int V_211 ;
int V_55 ;
for ( V_211 = V_212 ; V_211 != 0 ; V_211 -- ) {
V_55 = F_157 ( V_2 ) ;
if ( V_55 != 0 )
break;
if ( ! F_3 ( V_193 , & V_2 -> V_18 ) &&
! F_3 ( V_194 , & V_2 -> V_18 ) )
break;
F_44 ( V_2 ) ;
V_55 = - V_159 ;
}
return V_55 ;
}
static void F_161 ( struct V_1 * V_2 )
{
F_5 ( V_193 , & V_2 -> V_18 ) ;
F_162 ( V_2 ) ;
F_153 ( L_13 , V_192 ,
V_2 -> V_195 ) ;
}
void F_163 ( struct V_1 * V_2 )
{
F_161 ( V_2 ) ;
F_44 ( V_2 ) ;
}
static int F_164 ( struct V_1 * V_2 , struct V_102 * V_103 )
{
F_5 ( V_213 , & V_103 -> V_86 ) ;
if ( F_3 ( V_214 , & V_103 -> V_86 ) ) {
F_7 ( V_213 , & V_103 -> V_86 ) ;
return 0 ;
}
F_5 ( V_215 , & V_103 -> V_112 -> V_216 ) ;
F_5 ( V_217 , & V_2 -> V_18 ) ;
return 1 ;
}
int F_165 ( struct V_1 * V_2 , struct V_102 * V_103 )
{
F_5 ( V_214 , & V_103 -> V_86 ) ;
F_7 ( V_213 , & V_103 -> V_86 ) ;
F_5 ( V_218 , & V_103 -> V_112 -> V_216 ) ;
F_5 ( V_219 , & V_2 -> V_18 ) ;
return 1 ;
}
int F_166 ( const struct V_31 * V_32 , struct V_102 * V_103 )
{
struct V_1 * V_2 = V_32 -> V_1 ;
if ( ! F_95 ( V_103 ) )
return - V_220 ;
F_165 ( V_2 , V_103 ) ;
F_153 ( L_14 , V_192 ,
V_2 -> V_195 ) ;
F_44 ( V_2 ) ;
return 0 ;
}
void F_167 ( struct V_113 * V_113 ,
const T_4 * V_221 )
{
struct V_1 * V_2 = F_168 ( V_113 ) -> V_1 ;
struct V_114 * V_115 = F_93 ( V_113 ) ;
struct V_222 * V_223 ;
struct V_102 * V_103 ;
bool V_224 = false ;
F_15 ( & V_113 -> V_116 ) ;
F_94 (ctx, &nfsi->open_files, list) {
V_103 = V_223 -> V_103 ;
if ( V_103 == NULL )
continue;
if ( ! F_3 ( V_128 , & V_103 -> V_86 ) )
continue;
if ( ! F_169 ( & V_103 -> V_221 , V_221 ) )
continue;
F_165 ( V_2 , V_103 ) ;
V_224 = true ;
}
F_16 ( & V_113 -> V_116 ) ;
if ( V_224 )
F_44 ( V_2 ) ;
}
static void F_170 ( struct V_102 * V_103 )
{
struct V_113 * V_113 = V_103 -> V_113 ;
struct V_114 * V_115 = F_93 ( V_113 ) ;
struct V_222 * V_223 ;
F_15 ( & V_113 -> V_116 ) ;
F_94 (ctx, &nfsi->open_files, list) {
if ( V_223 -> V_103 != V_103 )
continue;
F_5 ( V_225 , & V_223 -> V_86 ) ;
}
F_16 ( & V_113 -> V_116 ) ;
}
static void F_171 ( struct V_102 * V_103 , int error )
{
F_5 ( V_226 , & V_103 -> V_86 ) ;
F_170 ( V_103 ) ;
}
static int F_172 ( struct V_102 * V_103 , const struct V_227 * V_228 )
{
struct V_113 * V_113 = V_103 -> V_113 ;
struct V_114 * V_115 = F_93 ( V_113 ) ;
struct V_145 * V_150 ;
int V_12 = 0 ;
struct V_229 * V_230 = V_113 -> V_231 ;
struct V_232 * V_89 ;
if ( V_230 == NULL )
return 0 ;
V_89 = & V_230 -> V_233 ;
F_173 ( & V_115 -> V_234 ) ;
F_15 ( & V_230 -> V_235 ) ;
V_236:
F_94 (fl, list, fl_list) {
if ( F_174 ( V_150 -> V_237 ) -> V_103 != V_103 )
continue;
F_16 ( & V_230 -> V_235 ) ;
V_12 = V_228 -> V_238 ( V_103 , V_150 ) ;
switch ( V_12 ) {
case 0 :
break;
case - V_239 :
case - V_240 :
case - V_174 :
case - V_175 :
case - V_241 :
case - V_242 :
case - V_173 :
case - V_243 :
case - V_244 :
case - V_245 :
case - V_246 :
goto V_26;
default:
F_155 ( L_15 ,
V_192 , V_12 ) ;
case - V_152 :
case - V_247 :
case - V_248 :
case - V_249 :
V_12 = 0 ;
}
F_15 ( & V_230 -> V_235 ) ;
}
if ( V_89 == & V_230 -> V_233 ) {
V_89 = & V_230 -> V_250 ;
goto V_236;
}
F_16 ( & V_230 -> V_235 ) ;
V_26:
F_175 ( & V_115 -> V_234 ) ;
return V_12 ;
}
static int F_176 ( struct V_33 * V_34 , const struct V_227 * V_228 )
{
struct V_102 * V_103 ;
struct V_130 * V_88 ;
int V_12 = 0 ;
F_15 ( & V_34 -> V_92 ) ;
F_177 ( & V_34 -> V_93 ) ;
V_236:
F_94 (state, &sp->so_states, open_states) {
if ( ! F_28 ( V_228 -> V_251 , & V_103 -> V_86 ) )
continue;
if ( ! F_95 ( V_103 ) )
continue;
if ( V_103 -> V_103 == 0 )
continue;
F_50 ( & V_103 -> V_105 ) ;
F_16 ( & V_34 -> V_92 ) ;
V_12 = V_228 -> V_252 ( V_34 , V_103 ) ;
if ( V_12 >= 0 ) {
V_12 = F_172 ( V_103 , V_228 ) ;
if ( V_12 >= 0 ) {
if ( ! F_3 ( V_128 , & V_103 -> V_86 ) ) {
F_15 ( & V_103 -> V_107 ) ;
F_94 (lock, &state->lock_states, ls_locks) {
if ( ! F_3 ( V_141 , & V_88 -> V_142 ) )
F_132 ( L_16
L_17
L_18 , V_192 ) ;
}
F_16 ( & V_103 -> V_107 ) ;
}
F_101 ( V_103 ) ;
F_15 ( & V_34 -> V_92 ) ;
goto V_236;
}
}
switch ( V_12 ) {
default:
F_149 ( V_191 L_15 ,
V_192 , V_12 ) ;
case - V_156 :
case - V_152 :
case - V_239 :
F_171 ( V_103 , V_12 ) ;
break;
case - V_100 :
F_178 ( 1 ) ;
case - V_240 :
case - V_174 :
case - V_175 :
case - V_248 :
case - V_249 :
F_165 ( V_34 -> V_78 -> V_1 , V_103 ) ;
break;
case - V_241 :
case - V_242 :
F_165 ( V_34 -> V_78 -> V_1 , V_103 ) ;
case - V_173 :
case - V_243 :
case - V_244 :
case - V_245 :
case - V_246 :
goto V_253;
}
F_101 ( V_103 ) ;
F_15 ( & V_34 -> V_92 ) ;
goto V_236;
}
F_179 ( & V_34 -> V_93 ) ;
F_16 ( & V_34 -> V_92 ) ;
return 0 ;
V_253:
F_101 ( V_103 ) ;
F_15 ( & V_34 -> V_92 ) ;
F_179 ( & V_34 -> V_93 ) ;
F_16 ( & V_34 -> V_92 ) ;
return V_12 ;
}
static void F_180 ( struct V_102 * V_103 )
{
struct V_130 * V_88 ;
F_7 ( V_128 , & V_103 -> V_86 ) ;
F_7 ( V_125 , & V_103 -> V_86 ) ;
F_7 ( V_127 , & V_103 -> V_86 ) ;
F_7 ( V_126 , & V_103 -> V_86 ) ;
F_15 ( & V_103 -> V_107 ) ;
F_94 (lock, &state->lock_states, ls_locks) {
V_88 -> V_135 . V_86 = 0 ;
F_7 ( V_141 , & V_88 -> V_142 ) ;
}
F_16 ( & V_103 -> V_107 ) ;
}
static void F_181 ( struct V_31 * V_32 ,
int (* F_182)( struct V_1 * V_2 , struct V_102 * V_103 ) )
{
struct V_1 * V_2 = V_32 -> V_1 ;
struct V_33 * V_34 ;
struct V_35 * V_36 ;
struct V_102 * V_103 ;
F_15 ( & V_2 -> V_30 ) ;
for ( V_36 = F_19 ( & V_32 -> V_37 ) ;
V_36 != NULL ;
V_36 = F_20 ( V_36 ) ) {
V_34 = F_21 ( V_36 , struct V_33 , V_38 ) ;
V_34 -> V_81 . V_86 = 0 ;
F_15 ( & V_34 -> V_92 ) ;
F_94 (state, &sp->so_states, open_states) {
if ( F_182 ( V_2 , V_103 ) )
F_180 ( V_103 ) ;
}
F_16 ( & V_34 -> V_92 ) ;
}
F_16 ( & V_2 -> V_30 ) ;
}
static void F_183 ( struct V_1 * V_2 ,
int (* F_182)( struct V_1 * V_2 , struct V_102 * V_103 ) )
{
struct V_31 * V_32 ;
F_24 () ;
F_25 (server, &clp->cl_superblocks, client_link)
F_181 ( V_32 , F_182 ) ;
F_26 () ;
}
static void F_184 ( struct V_1 * V_2 )
{
F_185 ( V_2 ) ;
F_183 ( V_2 , F_164 ) ;
}
static void F_186 ( struct V_1 * V_2 ,
const struct V_227 * V_228 ,
struct V_3 * V_4 )
{
if ( V_228 -> V_254 )
( void ) V_228 -> V_254 ( V_2 , V_4 ) ;
}
static void F_187 ( struct V_31 * V_32 )
{
struct V_1 * V_2 = V_32 -> V_1 ;
struct V_33 * V_34 ;
struct V_35 * V_36 ;
struct V_102 * V_103 ;
F_15 ( & V_2 -> V_30 ) ;
for ( V_36 = F_19 ( & V_32 -> V_37 ) ;
V_36 != NULL ;
V_36 = F_20 ( V_36 ) ) {
V_34 = F_21 ( V_36 , struct V_33 , V_38 ) ;
F_15 ( & V_34 -> V_92 ) ;
F_94 (state, &sp->so_states, open_states) {
if ( ! F_28 ( V_213 ,
& V_103 -> V_86 ) )
continue;
F_165 ( V_2 , V_103 ) ;
}
F_16 ( & V_34 -> V_92 ) ;
}
F_16 ( & V_2 -> V_30 ) ;
}
static int F_188 ( struct V_1 * V_2 )
{
struct V_31 * V_32 ;
if ( ! F_28 ( V_217 , & V_2 -> V_18 ) )
return 0 ;
F_24 () ;
F_25 (server, &clp->cl_superblocks, client_link)
F_187 ( V_32 ) ;
F_26 () ;
F_189 ( V_2 ) ;
return 1 ;
}
static void F_190 ( struct V_1 * V_2 )
{
const struct V_227 * V_228 ;
struct V_3 * V_4 ;
if ( ! F_188 ( V_2 ) )
return;
V_228 = V_2 -> V_143 -> V_255 ;
V_4 = F_47 ( V_2 ) ;
F_186 ( V_2 , V_228 , V_4 ) ;
F_17 ( V_4 ) ;
}
static void F_191 ( struct V_1 * V_2 )
{
F_185 ( V_2 ) ;
F_189 ( V_2 ) ;
}
static void F_192 ( struct V_1 * V_2 )
{
F_191 ( V_2 ) ;
F_183 ( V_2 , F_165 ) ;
}
static int F_193 ( struct V_1 * V_2 , int error )
{
switch ( error ) {
case 0 :
break;
case - V_256 :
F_161 ( V_2 ) ;
break;
case - V_242 :
F_190 ( V_2 ) ;
break;
case - V_173 :
F_5 ( V_193 , & V_2 -> V_18 ) ;
F_188 ( V_2 ) ;
F_184 ( V_2 ) ;
break;
case - V_241 :
F_5 ( V_193 , & V_2 -> V_18 ) ;
F_192 ( V_2 ) ;
break;
case - V_243 :
case - V_244 :
case - V_245 :
case - V_257 :
case - V_258 :
case - V_259 :
F_5 ( V_65 , & V_2 -> V_18 ) ;
break;
case - V_246 :
F_5 ( V_66 , & V_2 -> V_18 ) ;
break;
default:
F_153 ( L_19 ,
V_192 , error , V_2 -> V_195 ) ;
return error ;
}
F_153 ( L_20 , V_192 , error ,
V_2 -> V_195 ) ;
return 0 ;
}
static int F_194 ( struct V_1 * V_2 , const struct V_227 * V_228 )
{
struct V_33 * V_34 ;
struct V_31 * V_32 ;
struct V_35 * V_36 ;
int V_12 = 0 ;
V_236:
F_24 () ;
F_25 (server, &clp->cl_superblocks, client_link) {
F_87 ( V_32 ) ;
F_15 ( & V_2 -> V_30 ) ;
for ( V_36 = F_19 ( & V_32 -> V_37 ) ;
V_36 != NULL ;
V_36 = F_20 ( V_36 ) ) {
V_34 = F_21 ( V_36 ,
struct V_33 , V_38 ) ;
if ( ! F_28 ( V_228 -> V_260 ,
& V_34 -> V_216 ) )
continue;
F_50 ( & V_34 -> V_77 ) ;
F_16 ( & V_2 -> V_30 ) ;
F_26 () ;
V_12 = F_176 ( V_34 , V_228 ) ;
if ( V_12 < 0 ) {
F_5 ( V_228 -> V_260 , & V_34 -> V_216 ) ;
F_84 ( V_34 ) ;
V_12 = F_193 ( V_2 , V_12 ) ;
return ( V_12 != 0 ) ? V_12 : - V_100 ;
}
F_84 ( V_34 ) ;
goto V_236;
}
F_16 ( & V_2 -> V_30 ) ;
}
F_26 () ;
return 0 ;
}
static int F_195 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
const struct V_261 * V_228 =
V_2 -> V_143 -> V_262 ;
int V_12 ;
if ( F_3 ( V_193 , & V_2 -> V_18 ) )
return 0 ;
F_15 ( & V_2 -> V_30 ) ;
V_4 = V_228 -> V_263 ( V_2 ) ;
F_16 ( & V_2 -> V_30 ) ;
if ( V_4 == NULL ) {
V_4 = F_47 ( V_2 ) ;
V_12 = - V_264 ;
if ( V_4 == NULL )
goto V_26;
}
V_12 = V_228 -> V_265 ( V_2 , V_4 ) ;
F_17 ( V_4 ) ;
if ( V_12 == - V_266 ) {
F_5 ( V_194 , & V_2 -> V_18 ) ;
return 0 ;
}
V_26:
return F_193 ( V_2 , V_12 ) ;
}
static int F_196 ( struct V_1 * V_2 , int V_12 )
{
switch ( V_12 ) {
case - V_259 :
if ( F_144 ( V_71 , & V_2 -> V_18 ) )
return - V_267 ;
F_178 ( 1 ) ;
F_7 ( V_17 , & V_2 -> V_18 ) ;
break;
case - V_173 :
F_7 ( V_17 , & V_2 -> V_18 ) ;
F_184 ( V_2 ) ;
break;
case - V_268 :
F_155 ( L_21 ,
V_2 -> V_195 ) ;
F_41 ( V_2 , - V_269 ) ;
F_7 ( V_17 , & V_2 -> V_18 ) ;
return - V_269 ;
case - V_270 :
case - V_271 :
case - V_266 :
case - V_100 :
F_178 ( 1 ) ;
break;
case - V_272 :
if ( V_2 -> V_210 == V_273 )
F_41 ( V_2 , - V_274 ) ;
F_153 ( L_22 ,
V_192 , - V_274 , V_2 -> V_195 ) ;
return - V_274 ;
case - V_275 :
default:
F_153 ( L_22 , V_192 ,
V_12 , V_2 -> V_195 ) ;
return V_12 ;
}
F_5 ( V_193 , & V_2 -> V_18 ) ;
F_153 ( L_20 , V_192 , V_12 ,
V_2 -> V_195 ) ;
return 0 ;
}
static int F_197 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
const struct V_227 * V_228 =
V_2 -> V_143 -> V_255 ;
int V_12 ;
V_4 = F_47 ( V_2 ) ;
if ( V_4 == NULL )
return - V_156 ;
V_12 = V_228 -> V_276 ( V_2 , V_4 ) ;
F_17 ( V_4 ) ;
if ( V_12 != 0 )
return V_12 ;
F_198 ( V_2 ) ;
return 0 ;
}
static int F_199 ( struct V_1 * V_2 )
{
int V_12 ;
V_12 = F_197 ( V_2 ) ;
if ( V_12 < 0 )
return F_196 ( V_2 , V_12 ) ;
if ( F_28 ( V_277 , & V_2 -> V_18 ) )
F_192 ( V_2 ) ;
if ( ! F_3 ( V_219 , & V_2 -> V_18 ) )
F_5 ( V_217 , & V_2 -> V_18 ) ;
F_7 ( V_194 , & V_2 -> V_18 ) ;
F_7 ( V_193 , & V_2 -> V_18 ) ;
return 0 ;
}
static int F_200 ( struct V_1 * V_2 )
{
int V_12 ;
V_12 = F_197 ( V_2 ) ;
if ( V_12 < 0 )
return F_196 ( V_2 , V_12 ) ;
F_7 ( V_71 , & V_2 -> V_18 ) ;
F_5 ( V_193 , & V_2 -> V_18 ) ;
F_192 ( V_2 ) ;
return 0 ;
}
static int F_201 ( struct V_31 * V_32 , struct V_3 * V_4 )
{
struct V_1 * V_2 = V_32 -> V_1 ;
struct V_278 * V_279 = NULL ;
struct V_113 * V_113 ;
struct V_280 * V_280 ;
int V_12 , V_27 ;
F_153 ( L_23 , V_192 ,
( unsigned long long ) V_32 -> V_201 . V_202 ,
( unsigned long long ) V_32 -> V_201 . V_203 ,
V_2 -> V_195 ) ;
V_27 = 0 ;
V_280 = F_202 ( V_129 ) ;
V_279 = F_126 ( sizeof( struct V_278 ) , V_129 ) ;
if ( V_280 == NULL || V_279 == NULL ) {
F_153 ( L_24 , V_192 ) ;
goto V_26;
}
V_113 = V_32 -> V_281 -> V_282 -> V_283 ;
V_27 = F_203 ( V_113 , V_279 , V_280 , V_4 ) ;
if ( V_27 ) {
F_153 ( L_25 ,
V_192 , V_27 ) ;
goto V_26;
}
V_27 = - V_284 ;
if ( ! ( V_279 -> V_285 . V_286 & V_287 ) ) {
F_153 ( L_26 ,
V_192 ) ;
goto V_26;
}
F_34 ( V_2 ) ;
V_12 = F_204 ( V_32 , V_279 ) ;
if ( V_12 != 0 ) {
F_153 ( L_27 ,
V_192 , V_12 ) ;
goto V_26;
}
V_27 = 0 ;
F_153 ( L_28 , V_192 ) ;
V_26:
if ( V_280 != NULL )
F_205 ( V_280 ) ;
F_75 ( V_279 ) ;
if ( V_27 ) {
F_155 ( L_29 ,
V_2 -> V_195 ) ;
F_5 ( V_199 , & V_32 -> V_200 ) ;
}
return V_27 ;
}
static int F_206 ( struct V_1 * V_2 )
{
const struct V_261 * V_228 =
V_2 -> V_143 -> V_262 ;
struct V_31 * V_32 ;
struct V_3 * V_4 ;
F_153 ( L_30 , V_192 ,
V_2 -> V_195 ) ;
F_15 ( & V_2 -> V_30 ) ;
V_4 = V_228 -> V_263 ( V_2 ) ;
F_16 ( & V_2 -> V_30 ) ;
if ( V_4 == NULL )
return - V_288 ;
V_2 -> V_289 ++ ;
V_236:
F_24 () ;
F_25 (server, &clp->cl_superblocks, client_link) {
int V_12 ;
if ( V_32 -> V_290 == V_2 -> V_289 )
continue;
V_32 -> V_290 = V_2 -> V_289 ;
if ( ! F_28 ( V_204 ,
& V_32 -> V_200 ) )
continue;
F_26 () ;
V_12 = F_201 ( V_32 , V_4 ) ;
if ( V_12 < 0 ) {
F_17 ( V_4 ) ;
return V_12 ;
}
goto V_236;
}
F_26 () ;
F_17 ( V_4 ) ;
return 0 ;
}
static int F_207 ( struct V_1 * V_2 )
{
const struct V_261 * V_228 =
V_2 -> V_143 -> V_262 ;
struct V_31 * V_32 ;
struct V_3 * V_4 ;
F_153 ( L_31 , V_192 ,
V_2 -> V_195 ) ;
F_15 ( & V_2 -> V_30 ) ;
V_4 = V_228 -> V_263 ( V_2 ) ;
F_16 ( & V_2 -> V_30 ) ;
if ( V_4 == NULL )
return - V_288 ;
V_2 -> V_289 ++ ;
V_236:
F_24 () ;
F_25 (server, &clp->cl_superblocks, client_link) {
struct V_113 * V_113 ;
int V_12 ;
if ( V_32 -> V_290 == V_2 -> V_289 )
continue;
V_32 -> V_290 = V_2 -> V_289 ;
F_26 () ;
V_113 = V_32 -> V_281 -> V_282 -> V_283 ;
V_12 = F_208 ( V_113 , V_4 ) ;
if ( V_12 != - V_291 )
goto V_236;
if ( F_201 ( V_32 , V_4 ) == - V_292 )
goto V_236;
goto V_26;
}
F_26 () ;
V_26:
F_17 ( V_4 ) ;
return 0 ;
}
int F_209 ( struct V_1 * V_2 ,
struct V_1 * * V_27 )
{
const struct V_227 * V_228 =
V_2 -> V_143 -> V_255 ;
struct V_293 * V_294 ;
struct V_3 * V_4 ;
int V_295 , V_12 ;
F_153 ( L_32 , V_192 , V_2 -> V_195 ) ;
V_294 = V_2 -> V_188 ;
V_295 = 0 ;
F_210 ( & V_296 ) ;
V_297:
V_12 = - V_156 ;
V_4 = F_47 ( V_2 ) ;
if ( V_4 == NULL )
goto V_298;
V_12 = V_228 -> V_299 ( V_2 , V_27 , V_4 ) ;
F_17 ( V_4 ) ;
switch ( V_12 ) {
case 0 :
break;
case - V_266 :
if ( V_294 -> V_300 )
break;
case - V_271 :
case - V_100 :
F_178 ( 1 ) ;
case - V_173 :
F_153 ( L_33 ,
V_192 , V_12 ) ;
goto V_297;
case - V_270 :
if ( V_295 ++ == 0 ) {
F_13 ( V_2 ) ;
goto V_297;
}
if ( V_294 -> V_301 -> V_302 == V_303 )
break;
case - V_268 :
case - V_304 :
if ( V_294 -> V_301 -> V_302 == V_303 ) {
V_12 = - V_269 ;
break;
}
V_294 = F_211 ( V_294 , V_303 ) ;
if ( F_148 ( V_294 ) ) {
V_12 = F_150 ( V_294 ) ;
break;
}
V_294 = F_212 ( & V_2 -> V_188 , V_294 ) ;
F_213 ( V_294 ) ;
V_294 = V_2 -> V_188 ;
goto V_297;
case - V_272 :
V_12 = - V_274 ;
break;
case - V_305 :
case - V_275 :
V_12 = - V_305 ;
break;
default:
F_214 ( L_34 ,
V_192 , V_12 ) ;
V_12 = - V_159 ;
}
V_298:
F_215 ( & V_296 ) ;
F_153 ( L_35 , V_192 , V_12 ) ;
return V_12 ;
}
void F_216 ( struct V_46 * V_306 , int V_79 )
{
struct V_1 * V_2 = V_306 -> V_2 ;
switch ( V_79 ) {
default:
F_5 ( V_65 , & V_2 -> V_18 ) ;
break;
case - V_246 :
F_5 ( V_66 , & V_2 -> V_18 ) ;
}
F_152 ( V_2 ) ;
}
static void F_217 ( struct V_1 * V_2 )
{
F_5 ( V_194 , & V_2 -> V_18 ) ;
F_44 ( V_2 ) ;
}
void F_218 ( struct V_1 * V_2 )
{
F_217 ( V_2 ) ;
}
void F_219 ( struct V_1 * V_2 )
{
F_217 ( V_2 ) ;
}
static void F_220 ( struct V_1 * V_2 )
{
if ( F_144 ( V_193 , & V_2 -> V_18 ) == 0 ) {
F_5 ( V_71 , & V_2 -> V_18 ) ;
F_7 ( V_17 , & V_2 -> V_18 ) ;
F_192 ( V_2 ) ;
F_153 ( L_36 ,
V_192 , V_2 -> V_195 ) ;
F_44 ( V_2 ) ;
}
}
static void F_221 ( struct V_1 * V_2 )
{
if ( F_144 ( V_193 , & V_2 -> V_18 ) == 0 ) {
F_184 ( V_2 ) ;
F_153 ( L_37 , V_192 ,
V_2 -> V_195 ) ;
F_44 ( V_2 ) ;
}
}
static void F_222 ( struct V_1 * V_2 )
{
F_220 ( V_2 ) ;
F_153 ( L_38 , V_192 , V_2 -> V_195 ) ;
}
static void F_223 ( struct V_1 * V_2 )
{
F_162 ( V_2 ) ;
F_153 ( L_39 , V_192 ,
V_2 -> V_195 ) ;
}
static void F_224 ( struct V_1 * V_2 )
{
F_162 ( V_2 ) ;
if ( F_144 ( V_65 , & V_2 -> V_18 ) == 0 )
F_44 ( V_2 ) ;
F_153 ( L_40 , V_192 ,
V_2 -> V_195 ) ;
}
static void F_225 ( struct V_1 * V_2 )
{
if ( F_144 ( V_66 ,
& V_2 -> V_18 ) == 0 )
F_44 ( V_2 ) ;
}
void F_226 ( struct V_1 * V_2 , T_5 V_86 )
{
if ( ! V_86 )
return;
F_153 ( L_41 ,
V_192 , V_2 -> V_195 , V_2 -> V_8 , V_86 ) ;
if ( V_86 & V_307 )
F_221 ( V_2 ) ;
if ( V_86 & ( V_308 |
V_309 |
V_310 ) )
F_222 ( V_2 ) ;
if ( V_86 & V_311 )
F_156 ( V_2 ) ;
if ( V_86 & V_312 )
F_223 ( V_2 ) ;
if ( V_86 & V_313 )
F_224 ( V_2 ) ;
else if ( V_86 & ( V_314 |
V_315 ) )
F_225 ( V_2 ) ;
}
static int F_227 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
int V_12 ;
if ( ! F_135 ( V_2 ) )
return 0 ;
F_34 ( V_2 ) ;
V_4 = F_47 ( V_2 ) ;
V_12 = F_228 ( V_2 -> V_48 , V_4 ) ;
switch ( V_12 ) {
case 0 :
case - V_243 :
case - V_257 :
break;
case - V_316 :
case - V_271 :
F_5 ( V_65 , & V_2 -> V_18 ) ;
V_12 = 0 ;
F_178 ( 1 ) ;
goto V_26;
default:
V_12 = F_193 ( V_2 , V_12 ) ;
goto V_26;
}
memset ( V_2 -> V_48 -> V_317 . V_318 , 0 , V_319 ) ;
V_12 = F_40 ( V_2 , V_4 ) ;
if ( V_12 ) {
F_153 ( L_42 ,
V_192 , V_12 , V_2 -> V_195 ) ;
V_12 = F_196 ( V_2 , V_12 ) ;
goto V_26;
}
F_37 ( V_2 ) ;
F_153 ( L_43 ,
V_192 , V_2 -> V_195 ) ;
V_26:
if ( V_4 )
F_17 ( V_4 ) ;
return V_12 ;
}
static int F_229 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
int V_55 ;
if ( ! F_135 ( V_2 ) )
return 0 ;
F_34 ( V_2 ) ;
V_4 = F_47 ( V_2 ) ;
V_55 = F_230 ( V_2 , V_4 ) ;
if ( V_4 )
F_17 ( V_4 ) ;
F_7 ( V_66 , & V_2 -> V_18 ) ;
switch ( V_55 ) {
case 0 :
F_153 ( L_44 ,
V_192 , V_2 -> V_195 ) ;
break;
case - V_271 :
F_178 ( 1 ) ;
F_5 ( V_66 , & V_2 -> V_18 ) ;
break;
default:
return F_193 ( V_2 , V_55 ) ;
}
return 0 ;
}
static int F_227 ( struct V_1 * V_2 ) { return 0 ; }
static int F_229 ( struct V_1 * V_2 )
{
return 0 ;
}
static void F_231 ( struct V_1 * V_2 )
{
int V_12 = 0 ;
const char * V_320 = L_45 , * V_321 = L_45 ;
do {
if ( F_3 ( V_71 , & V_2 -> V_18 ) ) {
V_320 = L_46 ;
V_12 = F_200 ( V_2 ) ;
if ( V_12 < 0 )
goto V_322;
continue;
}
if ( F_3 ( V_193 , & V_2 -> V_18 ) ) {
V_320 = L_47 ;
V_12 = F_199 ( V_2 ) ;
if ( V_12 < 0 )
goto V_322;
continue;
}
if ( F_28 ( V_65 , & V_2 -> V_18 ) ) {
V_320 = L_48 ;
V_12 = F_227 ( V_2 ) ;
if ( F_3 ( V_193 , & V_2 -> V_18 ) )
continue;
if ( V_12 < 0 )
goto V_322;
}
if ( F_28 ( V_66 ,
& V_2 -> V_18 ) ) {
V_320 = L_49 ;
V_12 = F_229 ( V_2 ) ;
if ( V_12 < 0 )
goto V_322;
continue;
}
if ( F_28 ( V_194 , & V_2 -> V_18 ) ) {
V_320 = L_50 ;
V_12 = F_195 ( V_2 ) ;
if ( V_12 < 0 )
goto V_322;
continue;
}
if ( F_28 ( V_205 , & V_2 -> V_18 ) ) {
V_320 = L_51 ;
V_12 = F_206 ( V_2 ) ;
if ( V_12 < 0 )
goto V_322;
}
if ( F_28 ( V_206 , & V_2 -> V_18 ) ) {
V_320 = L_52 ;
V_12 = F_207 ( V_2 ) ;
if ( V_12 < 0 )
goto V_322;
}
if ( F_3 ( V_217 , & V_2 -> V_18 ) ) {
V_320 = L_53 ;
V_12 = F_194 ( V_2 ,
V_2 -> V_143 -> V_255 ) ;
if ( V_12 == - V_100 )
continue;
if ( V_12 < 0 )
goto V_322;
F_190 ( V_2 ) ;
}
if ( F_28 ( V_219 , & V_2 -> V_18 ) ) {
V_320 = L_54 ;
V_12 = F_194 ( V_2 ,
V_2 -> V_143 -> V_323 ) ;
if ( V_12 == - V_100 )
continue;
if ( V_12 < 0 )
goto V_322;
}
F_30 ( V_2 ) ;
if ( F_28 ( V_324 , & V_2 -> V_18 ) ) {
F_232 ( V_2 ) ;
continue;
}
F_139 ( V_2 ) ;
if ( V_2 -> V_18 == 0 )
break;
if ( F_144 ( V_181 , & V_2 -> V_18 ) != 0 )
break;
} while ( F_233 ( & V_2 -> V_187 ) > 1 );
return;
V_322:
if ( strlen ( V_320 ) )
V_321 = L_55 ;
F_132 ( L_56
L_57 , V_321 , V_320 ,
V_2 -> V_195 , - V_12 ) ;
F_178 ( 1 ) ;
F_30 ( V_2 ) ;
F_139 ( V_2 ) ;
}
static int V_190 ( void * V_325 )
{
struct V_1 * V_2 = V_325 ;
F_234 ( V_326 ) ;
F_231 ( V_2 ) ;
F_46 ( V_2 ) ;
F_235 ( 0 ) ;
return 0 ;
}
