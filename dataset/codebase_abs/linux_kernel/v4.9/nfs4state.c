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
unsigned long V_58 ;
if ( ! F_3 ( V_59 , & V_2 -> V_60 ) ) {
F_8 ( V_2 ) ;
return 0 ;
}
V_58 = V_61 ;
V_12 = F_36 ( V_2 , & V_57 ) ;
if ( V_12 == 0 ) {
F_37 ( V_2 , V_57 . V_62 * V_63 , V_58 ) ;
F_8 ( V_2 ) ;
}
return V_12 ;
}
static void F_38 ( struct V_1 * V_2 )
{
F_7 ( V_17 , & V_2 -> V_18 ) ;
F_7 ( V_64 , & V_2 -> V_18 ) ;
F_7 ( V_65 , & V_2 -> V_18 ) ;
F_35 ( V_2 ) ;
}
int F_39 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
int V_12 ;
if ( F_3 ( V_17 , & V_2 -> V_18 ) )
goto V_19;
V_12 = F_40 ( V_2 , V_4 ) ;
if ( V_12 != 0 )
goto V_26;
F_5 ( V_17 , & V_2 -> V_18 ) ;
V_19:
V_12 = F_41 ( V_2 , V_4 ) ;
if ( V_12 != 0 )
goto V_26;
F_38 ( V_2 ) ;
F_42 ( V_2 , V_66 ) ;
V_26:
return V_12 ;
}
int F_43 ( struct V_1 * V_2 ,
struct V_1 * * V_27 ,
struct V_3 * V_4 )
{
int V_12 ;
V_12 = F_40 ( V_2 , V_4 ) ;
if ( V_12 != V_67 )
return V_12 ;
V_12 = F_44 ( V_2 , V_27 , V_4 ) ;
if ( V_12 < 0 )
return V_12 ;
if ( V_2 != * V_27 )
return 0 ;
if ( V_2 -> V_68 & V_69 )
F_5 ( V_70 , & V_2 -> V_18 ) ;
else
F_5 ( V_17 , & V_2 -> V_18 ) ;
F_45 ( V_2 ) ;
V_12 = F_46 ( V_2 ) ;
if ( V_12 < 0 )
F_47 ( V_2 ) ;
return V_12 ;
}
struct V_3 * F_48 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
F_15 ( & V_2 -> V_30 ) ;
V_4 = F_11 ( V_2 ) ;
F_16 ( & V_2 -> V_30 ) ;
return V_4 ;
}
static struct V_33 *
F_49 ( struct V_31 * V_32 , struct V_3 * V_4 )
{
struct V_35 * * V_71 = & V_32 -> V_37 . V_35 ,
* V_72 = NULL ;
struct V_33 * V_34 ;
while ( * V_71 != NULL ) {
V_72 = * V_71 ;
V_34 = F_21 ( V_72 , struct V_33 , V_38 ) ;
if ( V_4 < V_34 -> V_40 )
V_71 = & V_72 -> V_73 ;
else if ( V_4 > V_34 -> V_40 )
V_71 = & V_72 -> V_74 ;
else {
if ( ! F_22 ( & V_34 -> V_75 ) )
F_50 ( & V_34 -> V_75 ) ;
F_51 ( & V_34 -> V_76 ) ;
return V_34 ;
}
}
return NULL ;
}
static struct V_33 *
F_52 ( struct V_33 * V_29 )
{
struct V_31 * V_32 = V_29 -> V_77 ;
struct V_35 * * V_71 = & V_32 -> V_37 . V_35 ,
* V_72 = NULL ;
struct V_33 * V_34 ;
int V_78 ;
while ( * V_71 != NULL ) {
V_72 = * V_71 ;
V_34 = F_21 ( V_72 , struct V_33 , V_38 ) ;
if ( V_29 -> V_40 < V_34 -> V_40 )
V_71 = & V_72 -> V_73 ;
else if ( V_29 -> V_40 > V_34 -> V_40 )
V_71 = & V_72 -> V_74 ;
else {
if ( ! F_22 ( & V_34 -> V_75 ) )
F_50 ( & V_34 -> V_75 ) ;
F_51 ( & V_34 -> V_76 ) ;
return V_34 ;
}
}
V_78 = F_53 ( & V_32 -> V_79 , & V_29 -> V_80 . V_81 ) ;
if ( V_78 )
return F_54 ( V_78 ) ;
F_55 ( & V_29 -> V_38 , V_72 , V_71 ) ;
F_56 ( & V_29 -> V_38 , & V_32 -> V_37 ) ;
return V_29 ;
}
static void
F_57 ( struct V_33 * V_34 )
{
struct V_31 * V_32 = V_34 -> V_77 ;
if ( ! F_58 ( & V_34 -> V_38 ) )
F_59 ( & V_34 -> V_38 , & V_32 -> V_37 ) ;
F_60 ( & V_32 -> V_79 , V_34 -> V_80 . V_81 ) ;
}
static void
F_61 ( struct V_82 * V_83 )
{
V_83 -> V_84 = F_62 () ;
V_83 -> V_85 = 0 ;
V_83 -> V_86 = 0 ;
F_63 ( & V_83 -> V_87 ) ;
F_64 ( & V_83 -> V_88 ) ;
F_65 ( & V_83 -> V_89 , L_1 ) ;
}
static void
F_66 ( struct V_82 * V_83 )
{
F_67 ( & V_83 -> V_89 ) ;
}
static struct V_33 *
F_68 ( struct V_31 * V_32 ,
struct V_3 * V_4 ,
T_1 V_90 )
{
struct V_33 * V_34 ;
V_34 = F_69 ( sizeof( * V_34 ) , V_90 ) ;
if ( ! V_34 )
return NULL ;
V_34 -> V_77 = V_32 ;
V_34 -> V_40 = F_12 ( V_4 ) ;
F_63 ( & V_34 -> V_91 ) ;
F_64 ( & V_34 -> V_39 ) ;
F_61 ( & V_34 -> V_80 ) ;
F_70 ( & V_34 -> V_76 , 1 ) ;
F_64 ( & V_34 -> V_75 ) ;
F_71 ( & V_34 -> V_92 ) ;
F_72 ( & V_34 -> V_93 ) ;
return V_34 ;
}
static void
F_73 ( struct V_33 * V_34 )
{
struct V_35 * V_35 = & V_34 -> V_38 ;
if ( ! F_58 ( V_35 ) ) {
struct V_31 * V_32 = V_34 -> V_77 ;
struct V_1 * V_2 = V_32 -> V_1 ;
F_15 ( & V_2 -> V_30 ) ;
if ( ! F_58 ( V_35 ) ) {
F_59 ( V_35 , & V_32 -> V_37 ) ;
F_74 ( V_35 ) ;
}
F_16 ( & V_2 -> V_30 ) ;
}
}
static void F_75 ( struct V_33 * V_34 )
{
F_66 ( & V_34 -> V_80 ) ;
F_17 ( V_34 -> V_40 ) ;
F_76 ( V_34 ) ;
}
static void F_77 ( struct V_31 * V_32 )
{
struct V_1 * V_2 = V_32 -> V_1 ;
struct V_33 * V_34 , * V_94 ;
unsigned long V_95 , V_96 ;
F_78 ( V_97 ) ;
F_15 ( & V_2 -> V_30 ) ;
V_96 = V_61 ;
V_95 = ( long ) V_96 - ( long ) V_2 -> V_98 ;
F_79 (sp, tmp, &server->state_owners_lru, so_lru) {
if ( F_80 ( V_34 -> V_99 , V_95 , V_96 ) )
break;
F_81 ( & V_34 -> V_75 , & V_97 ) ;
F_57 ( V_34 ) ;
}
F_16 ( & V_2 -> V_30 ) ;
F_79 (sp, tmp, &doomed, so_lru) {
F_82 ( & V_34 -> V_75 ) ;
F_75 ( V_34 ) ;
}
}
struct V_33 * F_83 ( struct V_31 * V_32 ,
struct V_3 * V_4 ,
T_1 V_90 )
{
struct V_1 * V_2 = V_32 -> V_1 ;
struct V_33 * V_34 , * V_29 ;
F_15 ( & V_2 -> V_30 ) ;
V_34 = F_49 ( V_32 , V_4 ) ;
F_16 ( & V_2 -> V_30 ) ;
if ( V_34 != NULL )
goto V_26;
V_29 = F_68 ( V_32 , V_4 , V_90 ) ;
if ( V_29 == NULL )
goto V_26;
do {
if ( F_84 ( & V_32 -> V_79 , V_90 ) == 0 )
break;
F_15 ( & V_2 -> V_30 ) ;
V_34 = F_52 ( V_29 ) ;
F_16 ( & V_2 -> V_30 ) ;
} while ( V_34 == F_54 ( - V_100 ) );
if ( V_34 != V_29 )
F_75 ( V_29 ) ;
V_26:
F_77 ( V_32 ) ;
return V_34 ;
}
void F_85 ( struct V_33 * V_34 )
{
struct V_31 * V_32 = V_34 -> V_77 ;
struct V_1 * V_2 = V_32 -> V_1 ;
if ( ! F_86 ( & V_34 -> V_76 , & V_2 -> V_30 ) )
return;
V_34 -> V_99 = V_61 ;
F_87 ( & V_34 -> V_75 , & V_32 -> V_101 ) ;
F_16 ( & V_2 -> V_30 ) ;
}
void F_88 ( struct V_31 * V_32 )
{
struct V_1 * V_2 = V_32 -> V_1 ;
struct V_33 * V_34 , * V_94 ;
F_78 ( V_97 ) ;
F_15 ( & V_2 -> V_30 ) ;
F_79 (sp, tmp, &server->state_owners_lru, so_lru) {
F_81 ( & V_34 -> V_75 , & V_97 ) ;
F_57 ( V_34 ) ;
}
F_16 ( & V_2 -> V_30 ) ;
F_79 (sp, tmp, &doomed, so_lru) {
F_82 ( & V_34 -> V_75 ) ;
F_75 ( V_34 ) ;
}
}
static struct V_102 *
F_89 ( void )
{
struct V_102 * V_103 ;
V_103 = F_69 ( sizeof( * V_103 ) , V_104 ) ;
if ( ! V_103 )
return NULL ;
F_70 ( & V_103 -> V_105 , 1 ) ;
F_64 ( & V_103 -> V_106 ) ;
F_63 ( & V_103 -> V_107 ) ;
F_90 ( & V_103 -> V_108 ) ;
return V_103 ;
}
void
F_91 ( struct V_102 * V_103 , T_2 V_109 )
{
if ( V_103 -> V_103 == V_109 )
return;
if ( ( V_109 & V_110 ) != ( V_103 -> V_103 & V_110 ) ) {
if ( V_109 & V_110 )
F_81 ( & V_103 -> V_111 , & V_103 -> V_112 -> V_39 ) ;
else
F_92 ( & V_103 -> V_111 , & V_103 -> V_112 -> V_39 ) ;
}
V_103 -> V_103 = V_109 ;
}
static struct V_102 *
F_93 ( struct V_113 * V_113 , struct V_33 * V_112 )
{
struct V_114 * V_115 = F_94 ( V_113 ) ;
struct V_102 * V_103 ;
F_95 (state, &nfsi->open_states, inode_states) {
if ( V_103 -> V_112 != V_112 )
continue;
if ( ! F_96 ( V_103 ) )
continue;
if ( F_97 ( & V_103 -> V_105 ) )
return V_103 ;
}
return NULL ;
}
static void
F_98 ( struct V_102 * V_103 )
{
F_76 ( V_103 ) ;
}
struct V_102 *
F_99 ( struct V_113 * V_113 , struct V_33 * V_112 )
{
struct V_102 * V_103 , * V_29 ;
struct V_114 * V_115 = F_94 ( V_113 ) ;
F_15 ( & V_113 -> V_116 ) ;
V_103 = F_93 ( V_113 , V_112 ) ;
F_16 ( & V_113 -> V_116 ) ;
if ( V_103 )
goto V_26;
V_29 = F_89 () ;
F_15 ( & V_112 -> V_91 ) ;
F_15 ( & V_113 -> V_116 ) ;
V_103 = F_93 ( V_113 , V_112 ) ;
if ( V_103 == NULL && V_29 != NULL ) {
V_103 = V_29 ;
V_103 -> V_112 = V_112 ;
F_51 ( & V_112 -> V_76 ) ;
F_100 ( & V_103 -> V_117 , & V_115 -> V_111 ) ;
F_101 ( V_113 ) ;
V_103 -> V_113 = V_113 ;
F_16 ( & V_113 -> V_116 ) ;
F_87 ( & V_103 -> V_111 , & V_112 -> V_39 ) ;
F_16 ( & V_112 -> V_91 ) ;
} else {
F_16 ( & V_113 -> V_116 ) ;
F_16 ( & V_112 -> V_91 ) ;
if ( V_29 )
F_98 ( V_29 ) ;
}
V_26:
return V_103 ;
}
void F_102 ( struct V_102 * V_103 )
{
struct V_113 * V_113 = V_103 -> V_113 ;
struct V_33 * V_112 = V_103 -> V_112 ;
if ( ! F_86 ( & V_103 -> V_105 , & V_112 -> V_91 ) )
return;
F_15 ( & V_113 -> V_116 ) ;
F_82 ( & V_103 -> V_117 ) ;
F_82 ( & V_103 -> V_111 ) ;
F_16 ( & V_113 -> V_116 ) ;
F_16 ( & V_112 -> V_91 ) ;
F_103 ( V_113 ) ;
F_98 ( V_103 ) ;
F_85 ( V_112 ) ;
}
static void F_104 ( struct V_102 * V_103 ,
T_2 V_109 , T_1 V_118 , int V_89 )
{
struct V_33 * V_112 = V_103 -> V_112 ;
int V_119 = 0 ;
T_2 V_120 ;
F_51 ( & V_112 -> V_76 ) ;
F_15 ( & V_112 -> V_91 ) ;
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
V_119 |= F_3 ( V_125 , & V_103 -> V_85 ) ;
V_119 |= F_3 ( V_126 , & V_103 -> V_85 ) ;
}
if ( V_103 -> V_123 == 0 ) {
V_120 &= ~ V_110 ;
V_119 |= F_3 ( V_127 , & V_103 -> V_85 ) ;
V_119 |= F_3 ( V_126 , & V_103 -> V_85 ) ;
}
if ( V_120 == 0 )
F_7 ( V_128 , & V_103 -> V_85 ) ;
}
F_91 ( V_103 , V_120 ) ;
F_16 ( & V_112 -> V_91 ) ;
if ( ! V_119 ) {
F_102 ( V_103 ) ;
F_85 ( V_112 ) ;
} else
F_105 ( V_103 , V_118 , V_89 ) ;
}
void F_106 ( struct V_102 * V_103 , T_2 V_109 )
{
F_104 ( V_103 , V_109 , V_104 , 0 ) ;
}
void F_107 ( struct V_102 * V_103 , T_2 V_109 )
{
F_104 ( V_103 , V_109 , V_129 , 1 ) ;
}
static struct V_130 *
F_108 ( struct V_102 * V_103 , T_3 V_131 )
{
struct V_130 * V_36 ;
F_95 (pos, &state->lock_states, ls_locks) {
if ( V_36 -> V_132 != V_131 )
continue;
F_51 ( & V_36 -> V_133 ) ;
return V_36 ;
}
return NULL ;
}
static struct V_130 * F_109 ( struct V_102 * V_103 , T_3 V_131 )
{
struct V_130 * V_134 ;
struct V_31 * V_32 = V_103 -> V_112 -> V_77 ;
V_134 = F_69 ( sizeof( * V_134 ) , V_104 ) ;
if ( V_134 == NULL )
return NULL ;
F_61 ( & V_134 -> V_135 ) ;
F_70 ( & V_134 -> V_133 , 1 ) ;
V_134 -> V_136 = V_103 ;
V_134 -> V_132 = V_131 ;
V_134 -> V_135 . V_81 = F_110 ( & V_32 -> V_137 , 0 , 0 , V_104 ) ;
if ( V_134 -> V_135 . V_81 < 0 )
goto V_138;
F_64 ( & V_134 -> V_139 ) ;
return V_134 ;
V_138:
F_76 ( V_134 ) ;
return NULL ;
}
void F_111 ( struct V_31 * V_32 , struct V_130 * V_134 )
{
F_112 ( & V_32 -> V_137 , V_134 -> V_135 . V_81 ) ;
F_66 ( & V_134 -> V_135 ) ;
F_76 ( V_134 ) ;
}
static struct V_130 * F_113 ( struct V_102 * V_103 , T_3 V_112 )
{
struct V_130 * V_134 , * V_29 = NULL ;
for(; ; ) {
F_15 ( & V_103 -> V_107 ) ;
V_134 = F_108 ( V_103 , V_112 ) ;
if ( V_134 != NULL )
break;
if ( V_29 != NULL ) {
F_100 ( & V_29 -> V_139 , & V_103 -> V_106 ) ;
F_5 ( V_140 , & V_103 -> V_85 ) ;
V_134 = V_29 ;
V_29 = NULL ;
break;
}
F_16 ( & V_103 -> V_107 ) ;
V_29 = F_109 ( V_103 , V_112 ) ;
if ( V_29 == NULL )
return NULL ;
}
F_16 ( & V_103 -> V_107 ) ;
if ( V_29 != NULL )
F_111 ( V_103 -> V_112 -> V_77 , V_29 ) ;
return V_134 ;
}
void F_114 ( struct V_130 * V_134 )
{
struct V_31 * V_32 ;
struct V_102 * V_103 ;
if ( V_134 == NULL )
return;
V_103 = V_134 -> V_136 ;
if ( ! F_86 ( & V_134 -> V_133 , & V_103 -> V_107 ) )
return;
F_82 ( & V_134 -> V_139 ) ;
if ( F_22 ( & V_103 -> V_106 ) )
F_7 ( V_140 , & V_103 -> V_85 ) ;
F_16 ( & V_103 -> V_107 ) ;
V_32 = V_103 -> V_112 -> V_77 ;
if ( F_3 ( V_141 , & V_134 -> V_142 ) ) {
struct V_1 * V_2 = V_32 -> V_1 ;
V_2 -> V_143 -> V_144 ( V_32 , V_134 ) ;
} else
F_111 ( V_32 , V_134 ) ;
}
static void F_115 ( struct V_145 * V_146 , struct V_145 * V_147 )
{
struct V_130 * V_134 = V_147 -> V_148 . V_149 . V_112 ;
V_146 -> V_148 . V_149 . V_112 = V_134 ;
F_51 ( & V_134 -> V_133 ) ;
}
static void F_116 ( struct V_145 * V_150 )
{
F_114 ( V_150 -> V_148 . V_149 . V_112 ) ;
}
int F_117 ( struct V_102 * V_103 , struct V_145 * V_150 )
{
struct V_130 * V_134 ;
if ( V_150 -> V_151 != NULL )
return 0 ;
V_134 = F_113 ( V_103 , V_150 -> V_131 ) ;
if ( V_134 == NULL )
return - V_152 ;
V_150 -> V_148 . V_149 . V_112 = V_134 ;
V_150 -> V_151 = & V_153 ;
return 0 ;
}
static int F_118 ( T_4 * V_146 ,
struct V_102 * V_103 ,
const struct V_154 * V_155 )
{
struct V_130 * V_134 ;
T_3 V_131 ;
int V_55 = - V_156 ;
if ( V_155 == NULL )
goto V_26;
if ( F_3 ( V_140 , & V_103 -> V_85 ) == 0 )
goto V_26;
V_131 = V_155 -> V_157 ;
F_15 ( & V_103 -> V_107 ) ;
V_134 = F_108 ( V_103 , V_131 ) ;
if ( V_134 && F_3 ( V_158 , & V_134 -> V_142 ) )
V_55 = - V_159 ;
else if ( V_134 != NULL && F_3 ( V_141 , & V_134 -> V_142 ) != 0 ) {
F_119 ( V_146 , & V_134 -> V_160 ) ;
V_55 = 0 ;
}
F_16 ( & V_103 -> V_107 ) ;
F_114 ( V_134 ) ;
V_26:
return V_55 ;
}
static void F_120 ( T_4 * V_146 , struct V_102 * V_103 )
{
const T_4 * V_147 ;
int V_161 ;
do {
V_147 = & V_162 ;
V_161 = F_121 ( & V_103 -> V_108 ) ;
if ( F_3 ( V_163 , & V_103 -> V_85 ) )
V_147 = & V_103 -> V_164 ;
F_119 ( V_146 , V_147 ) ;
} while ( F_122 ( & V_103 -> V_108 , V_161 ) );
}
int F_123 ( struct V_102 * V_103 ,
T_2 V_109 , const struct V_154 * V_155 ,
T_4 * V_146 , struct V_3 * * V_4 )
{
int V_55 ;
if ( ! F_96 ( V_103 ) )
return - V_159 ;
if ( V_4 != NULL )
* V_4 = NULL ;
V_55 = F_118 ( V_146 , V_103 , V_155 ) ;
if ( V_55 == - V_159 )
goto V_26;
if ( F_124 ( V_103 -> V_113 , V_109 , V_146 , V_4 ) ) {
V_55 = 0 ;
goto V_26;
}
if ( V_55 != - V_156 )
goto V_26;
F_120 ( V_146 , V_103 ) ;
V_55 = 0 ;
V_26:
if ( F_125 ( V_103 -> V_113 , V_165 ) )
V_146 -> V_166 = 0 ;
return V_55 ;
}
struct V_167 * F_126 ( struct V_82 * V_86 , T_1 V_118 )
{
struct V_167 * V_29 ;
V_29 = F_127 ( sizeof( * V_29 ) , V_118 ) ;
if ( V_29 == NULL )
return F_54 ( - V_152 ) ;
V_29 -> V_168 = V_86 ;
F_64 ( & V_29 -> V_88 ) ;
V_29 -> V_169 = NULL ;
return V_29 ;
}
void F_128 ( struct V_167 * V_166 )
{
struct V_82 * V_168 ;
if ( V_166 == NULL || F_22 ( & V_166 -> V_88 ) )
return;
V_168 = V_166 -> V_168 ;
F_15 ( & V_168 -> V_87 ) ;
F_50 ( & V_166 -> V_88 ) ;
if ( ! F_22 ( & V_168 -> V_88 ) ) {
struct V_167 * V_170 ;
V_170 = F_129 ( & V_168 -> V_88 ,
struct V_167 , V_88 ) ;
F_130 ( & V_168 -> V_89 , V_170 -> V_169 ) ;
}
F_16 ( & V_168 -> V_87 ) ;
}
void F_131 ( struct V_167 * V_166 )
{
F_128 ( V_166 ) ;
F_76 ( V_166 ) ;
}
static void F_132 ( int V_12 , struct V_167 * V_166 )
{
switch ( V_12 ) {
case 0 :
break;
case - V_171 :
if ( V_166 -> V_168 -> V_85 & V_172 )
return;
F_133 ( L_2
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
V_166 -> V_168 -> V_86 ++ ;
}
void F_134 ( int V_12 , struct V_167 * V_166 )
{
struct V_33 * V_34 ;
if ( V_166 == NULL )
return;
V_34 = F_135 ( V_166 -> V_168 , struct V_33 , V_80 ) ;
if ( V_12 == - V_171 )
F_73 ( V_34 ) ;
if ( ! F_136 ( V_34 -> V_77 -> V_1 ) )
F_132 ( V_12 , V_166 ) ;
}
void F_137 ( int V_12 , struct V_167 * V_166 )
{
if ( V_166 != NULL )
F_132 ( V_12 , V_166 ) ;
}
int F_138 ( struct V_167 * V_166 , struct V_179 * V_169 )
{
struct V_82 * V_168 ;
int V_12 = 0 ;
if ( V_166 == NULL )
goto V_26;
V_168 = V_166 -> V_168 ;
F_15 ( & V_168 -> V_87 ) ;
V_166 -> V_169 = V_169 ;
if ( F_22 ( & V_166 -> V_88 ) )
F_87 ( & V_166 -> V_88 , & V_168 -> V_88 ) ;
if ( F_129 ( & V_168 -> V_88 , struct V_167 , V_88 ) == V_166 )
goto V_180;
F_139 ( & V_168 -> V_89 , V_169 , NULL ) ;
V_12 = - V_100 ;
V_180:
F_16 ( & V_168 -> V_87 ) ;
V_26:
return V_12 ;
}
static void F_140 ( struct V_1 * V_2 )
{
F_141 () ;
F_7 ( V_181 , & V_2 -> V_18 ) ;
F_142 () ;
F_143 ( & V_2 -> V_18 , V_181 ) ;
F_144 ( & V_2 -> V_182 ) ;
}
void F_45 ( struct V_1 * V_2 )
{
struct V_183 * V_169 ;
char V_184 [ V_185 + sizeof( L_5 ) + 1 ] ;
if ( F_145 ( V_181 , & V_2 -> V_18 ) != 0 )
return;
F_146 ( V_186 ) ;
F_51 ( & V_2 -> V_187 ) ;
F_24 () ;
snprintf ( V_184 , sizeof( V_184 ) , L_6 ,
F_147 ( V_2 -> V_188 , V_189 ) ) ;
F_26 () ;
V_169 = F_148 ( V_190 , V_2 , L_7 , V_184 ) ;
if ( F_149 ( V_169 ) ) {
F_150 ( V_191 L_8 ,
V_192 , F_151 ( V_169 ) ) ;
F_140 ( V_2 ) ;
F_47 ( V_2 ) ;
F_152 ( V_186 ) ;
}
}
void F_153 ( struct V_1 * V_2 )
{
if ( ! V_2 )
return;
if ( ! F_3 ( V_193 , & V_2 -> V_18 ) )
F_5 ( V_194 , & V_2 -> V_18 ) ;
F_154 ( L_9 , V_192 ,
V_2 -> V_195 ) ;
F_45 ( V_2 ) ;
}
int F_155 ( const struct V_31 * V_32 )
{
struct V_1 * V_2 = V_32 -> V_1 ;
if ( V_32 -> V_196 != V_197 ) {
F_156 ( L_10 ,
V_2 -> V_195 ) ;
return - V_198 ;
}
if ( F_3 ( V_199 , & V_32 -> V_200 ) )
return - V_198 ;
F_154 ( L_11 ,
V_192 ,
( unsigned long long ) V_32 -> V_201 . V_202 ,
( unsigned long long ) V_32 -> V_201 . V_203 ,
V_2 -> V_195 ) ;
F_5 ( V_204 ,
& ( (struct V_31 * ) V_32 ) -> V_200 ) ;
F_5 ( V_205 , & V_2 -> V_18 ) ;
F_45 ( V_2 ) ;
return 0 ;
}
void F_157 ( struct V_1 * V_2 )
{
F_154 ( L_12 ,
V_192 , V_2 -> V_8 , V_2 -> V_195 ) ;
F_5 ( V_206 , & V_2 -> V_18 ) ;
F_45 ( V_2 ) ;
}
int F_158 ( struct V_1 * V_2 )
{
int V_207 ;
F_159 () ;
F_51 ( & V_2 -> V_187 ) ;
V_207 = F_160 ( & V_2 -> V_18 , V_181 ,
V_208 , V_209 ) ;
if ( V_207 )
goto V_26;
if ( V_2 -> V_210 < 0 )
V_207 = V_2 -> V_210 ;
V_26:
F_47 ( V_2 ) ;
return V_207 ;
}
int F_161 ( struct V_1 * V_2 )
{
unsigned int V_211 ;
int V_55 ;
for ( V_211 = V_212 ; V_211 != 0 ; V_211 -- ) {
V_55 = F_158 ( V_2 ) ;
if ( V_55 != 0 )
break;
if ( ! F_3 ( V_193 , & V_2 -> V_18 ) &&
! F_3 ( V_194 , & V_2 -> V_18 ) )
break;
F_45 ( V_2 ) ;
V_55 = - V_159 ;
}
return V_55 ;
}
static void F_162 ( struct V_1 * V_2 )
{
F_5 ( V_193 , & V_2 -> V_18 ) ;
F_163 ( V_2 ) ;
F_154 ( L_13 , V_192 ,
V_2 -> V_195 ) ;
}
void F_164 ( struct V_1 * V_2 )
{
F_162 ( V_2 ) ;
F_45 ( V_2 ) ;
}
static int F_165 ( struct V_1 * V_2 , struct V_102 * V_103 )
{
if ( ! F_96 ( V_103 ) )
return 0 ;
F_5 ( V_213 , & V_103 -> V_85 ) ;
if ( F_3 ( V_214 , & V_103 -> V_85 ) ) {
F_7 ( V_213 , & V_103 -> V_85 ) ;
return 0 ;
}
F_5 ( V_215 , & V_103 -> V_112 -> V_216 ) ;
F_5 ( V_217 , & V_2 -> V_18 ) ;
return 1 ;
}
int F_166 ( struct V_1 * V_2 , struct V_102 * V_103 )
{
if ( ! F_96 ( V_103 ) )
return 0 ;
F_5 ( V_214 , & V_103 -> V_85 ) ;
F_7 ( V_213 , & V_103 -> V_85 ) ;
F_5 ( V_218 , & V_103 -> V_112 -> V_216 ) ;
F_5 ( V_219 , & V_2 -> V_18 ) ;
return 1 ;
}
int F_167 ( const struct V_31 * V_32 , struct V_102 * V_103 )
{
struct V_1 * V_2 = V_32 -> V_1 ;
if ( ! F_166 ( V_2 , V_103 ) )
return - V_220 ;
F_154 ( L_14 , V_192 ,
V_2 -> V_195 ) ;
F_45 ( V_2 ) ;
return 0 ;
}
static struct V_130 *
F_168 ( struct V_102 * V_103 ,
const T_4 * V_221 )
{
struct V_130 * V_36 ;
F_95 (pos, &state->lock_states, ls_locks) {
if ( ! F_3 ( V_141 , & V_36 -> V_142 ) )
continue;
if ( F_169 ( & V_36 -> V_160 , V_221 ) )
return V_36 ;
}
return NULL ;
}
static bool F_170 ( struct V_102 * V_103 ,
const T_4 * V_221 )
{
bool V_222 = false ;
if ( F_3 ( V_140 , & V_103 -> V_85 ) ) {
F_15 ( & V_103 -> V_107 ) ;
if ( F_168 ( V_103 , V_221 ) )
V_222 = true ;
F_16 ( & V_103 -> V_107 ) ;
}
return V_222 ;
}
void F_171 ( struct V_113 * V_113 ,
const T_4 * V_221 )
{
struct V_1 * V_2 = F_172 ( V_113 ) -> V_1 ;
struct V_114 * V_115 = F_94 ( V_113 ) ;
struct V_223 * V_224 ;
struct V_102 * V_103 ;
bool V_222 = false ;
F_15 ( & V_113 -> V_116 ) ;
F_95 (ctx, &nfsi->open_files, list) {
V_103 = V_224 -> V_103 ;
if ( V_103 == NULL )
continue;
if ( F_169 ( & V_103 -> V_221 , V_221 ) &&
F_166 ( V_2 , V_103 ) ) {
V_222 = true ;
continue;
}
if ( F_170 ( V_103 , V_221 ) &&
F_166 ( V_2 , V_103 ) )
V_222 = true ;
}
F_16 ( & V_113 -> V_116 ) ;
F_173 ( V_113 , V_221 ) ;
if ( V_222 )
F_45 ( V_2 ) ;
}
static void F_174 ( struct V_102 * V_103 )
{
struct V_113 * V_113 = V_103 -> V_113 ;
struct V_114 * V_115 = F_94 ( V_113 ) ;
struct V_223 * V_224 ;
F_15 ( & V_113 -> V_116 ) ;
F_95 (ctx, &nfsi->open_files, list) {
if ( V_224 -> V_103 != V_103 )
continue;
F_5 ( V_225 , & V_224 -> V_85 ) ;
}
F_16 ( & V_113 -> V_116 ) ;
}
static void F_175 ( struct V_102 * V_103 , int error )
{
F_5 ( V_226 , & V_103 -> V_85 ) ;
F_174 ( V_103 ) ;
}
static int F_176 ( struct V_102 * V_103 , const struct V_227 * V_228 )
{
struct V_113 * V_113 = V_103 -> V_113 ;
struct V_114 * V_115 = F_94 ( V_113 ) ;
struct V_145 * V_150 ;
int V_12 = 0 ;
struct V_229 * V_230 = V_113 -> V_231 ;
struct V_232 * V_88 ;
if ( V_230 == NULL )
return 0 ;
V_88 = & V_230 -> V_233 ;
F_177 ( & V_115 -> V_234 ) ;
F_15 ( & V_230 -> V_235 ) ;
V_236:
F_95 (fl, list, fl_list) {
if ( F_178 ( V_150 -> V_237 ) -> V_103 != V_103 )
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
F_156 ( L_15 ,
V_192 , V_12 ) ;
case - V_152 :
case - V_247 :
case - V_248 :
case - V_249 :
V_12 = 0 ;
}
F_15 ( & V_230 -> V_235 ) ;
}
if ( V_88 == & V_230 -> V_233 ) {
V_88 = & V_230 -> V_250 ;
goto V_236;
}
F_16 ( & V_230 -> V_235 ) ;
V_26:
F_179 ( & V_115 -> V_234 ) ;
return V_12 ;
}
static int F_180 ( struct V_33 * V_34 , const struct V_227 * V_228 )
{
struct V_102 * V_103 ;
struct V_130 * V_87 ;
int V_12 = 0 ;
F_15 ( & V_34 -> V_91 ) ;
F_181 ( & V_34 -> V_92 ) ;
V_236:
F_95 (state, &sp->so_states, open_states) {
if ( ! F_28 ( V_228 -> V_251 , & V_103 -> V_85 ) )
continue;
if ( ! F_96 ( V_103 ) )
continue;
if ( V_103 -> V_103 == 0 )
continue;
F_51 ( & V_103 -> V_105 ) ;
F_16 ( & V_34 -> V_91 ) ;
V_12 = V_228 -> V_252 ( V_34 , V_103 ) ;
if ( V_12 >= 0 ) {
V_12 = F_176 ( V_103 , V_228 ) ;
if ( V_12 >= 0 ) {
if ( ! F_3 ( V_128 , & V_103 -> V_85 ) ) {
F_15 ( & V_103 -> V_107 ) ;
F_95 (lock, &state->lock_states, ls_locks) {
if ( ! F_3 ( V_141 , & V_87 -> V_142 ) )
F_133 ( L_16
L_17
L_18 , V_192 ) ;
}
F_16 ( & V_103 -> V_107 ) ;
}
F_7 ( V_214 ,
& V_103 -> V_85 ) ;
F_102 ( V_103 ) ;
F_15 ( & V_34 -> V_91 ) ;
goto V_236;
}
}
switch ( V_12 ) {
default:
F_150 ( V_191 L_15 ,
V_192 , V_12 ) ;
case - V_156 :
case - V_152 :
case - V_253 :
case - V_254 :
case - V_159 :
case - V_239 :
F_175 ( V_103 , V_12 ) ;
break;
case - V_100 :
F_182 ( 1 ) ;
case - V_240 :
case - V_174 :
case - V_255 :
case - V_175 :
case - V_248 :
case - V_249 :
F_166 ( V_34 -> V_77 -> V_1 , V_103 ) ;
break;
case - V_241 :
case - V_242 :
F_166 ( V_34 -> V_77 -> V_1 , V_103 ) ;
case - V_173 :
case - V_243 :
case - V_244 :
case - V_245 :
case - V_246 :
goto V_256;
}
F_102 ( V_103 ) ;
F_15 ( & V_34 -> V_91 ) ;
goto V_236;
}
F_183 ( & V_34 -> V_92 ) ;
F_16 ( & V_34 -> V_91 ) ;
return 0 ;
V_256:
F_102 ( V_103 ) ;
F_15 ( & V_34 -> V_91 ) ;
F_183 ( & V_34 -> V_92 ) ;
F_16 ( & V_34 -> V_91 ) ;
return V_12 ;
}
static void F_184 ( struct V_102 * V_103 )
{
struct V_130 * V_87 ;
F_7 ( V_128 , & V_103 -> V_85 ) ;
F_7 ( V_125 , & V_103 -> V_85 ) ;
F_7 ( V_127 , & V_103 -> V_85 ) ;
F_7 ( V_126 , & V_103 -> V_85 ) ;
F_15 ( & V_103 -> V_107 ) ;
F_95 (lock, &state->lock_states, ls_locks) {
V_87 -> V_135 . V_85 = 0 ;
F_7 ( V_141 , & V_87 -> V_142 ) ;
}
F_16 ( & V_103 -> V_107 ) ;
}
static void F_185 ( struct V_31 * V_32 ,
int (* F_186)( struct V_1 * V_2 , struct V_102 * V_103 ) )
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
V_34 -> V_80 . V_85 = 0 ;
F_15 ( & V_34 -> V_91 ) ;
F_95 (state, &sp->so_states, open_states) {
if ( F_186 ( V_2 , V_103 ) )
F_184 ( V_103 ) ;
}
F_16 ( & V_34 -> V_91 ) ;
}
F_16 ( & V_2 -> V_30 ) ;
}
static void F_187 ( struct V_1 * V_2 ,
int (* F_186)( struct V_1 * V_2 , struct V_102 * V_103 ) )
{
struct V_31 * V_32 ;
F_24 () ;
F_25 (server, &clp->cl_superblocks, client_link)
F_185 ( V_32 , F_186 ) ;
F_26 () ;
}
static void F_188 ( struct V_1 * V_2 )
{
F_189 ( V_2 ) ;
F_187 ( V_2 , F_165 ) ;
}
static void F_190 ( struct V_1 * V_2 ,
const struct V_227 * V_228 ,
struct V_3 * V_4 )
{
if ( V_228 -> V_257 )
( void ) V_228 -> V_257 ( V_2 , V_4 ) ;
}
static void F_191 ( struct V_31 * V_32 )
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
F_15 ( & V_34 -> V_91 ) ;
F_95 (state, &sp->so_states, open_states) {
if ( ! F_28 ( V_213 ,
& V_103 -> V_85 ) )
continue;
F_166 ( V_2 , V_103 ) ;
}
F_16 ( & V_34 -> V_91 ) ;
}
F_16 ( & V_2 -> V_30 ) ;
}
static int F_192 ( struct V_1 * V_2 )
{
struct V_31 * V_32 ;
if ( ! F_28 ( V_217 , & V_2 -> V_18 ) )
return 0 ;
F_24 () ;
F_25 (server, &clp->cl_superblocks, client_link)
F_191 ( V_32 ) ;
F_26 () ;
F_193 ( V_2 ) ;
return 1 ;
}
static void F_194 ( struct V_1 * V_2 )
{
const struct V_227 * V_228 ;
struct V_3 * V_4 ;
if ( ! F_192 ( V_2 ) )
return;
V_228 = V_2 -> V_143 -> V_258 ;
V_4 = F_48 ( V_2 ) ;
F_190 ( V_2 , V_228 , V_4 ) ;
F_17 ( V_4 ) ;
}
static void F_195 ( struct V_1 * V_2 )
{
F_196 ( V_2 ) ;
F_187 ( V_2 , F_166 ) ;
}
static int F_197 ( struct V_1 * V_2 , int error )
{
switch ( error ) {
case 0 :
break;
case - V_259 :
F_162 ( V_2 ) ;
break;
case - V_242 :
F_194 ( V_2 ) ;
break;
case - V_173 :
F_5 ( V_193 , & V_2 -> V_18 ) ;
F_192 ( V_2 ) ;
F_188 ( V_2 ) ;
break;
case - V_241 :
F_5 ( V_193 , & V_2 -> V_18 ) ;
F_195 ( V_2 ) ;
break;
case - V_243 :
case - V_244 :
case - V_245 :
case - V_260 :
case - V_261 :
case - V_262 :
F_5 ( V_64 , & V_2 -> V_18 ) ;
break;
case - V_246 :
F_5 ( V_65 , & V_2 -> V_18 ) ;
break;
default:
F_154 ( L_19 ,
V_192 , error , V_2 -> V_195 ) ;
return error ;
}
F_154 ( L_20 , V_192 , error ,
V_2 -> V_195 ) ;
return 0 ;
}
static int F_198 ( struct V_1 * V_2 , const struct V_227 * V_228 )
{
struct V_33 * V_34 ;
struct V_31 * V_32 ;
struct V_35 * V_36 ;
int V_12 = 0 ;
V_236:
F_24 () ;
F_25 (server, &clp->cl_superblocks, client_link) {
F_88 ( V_32 ) ;
F_15 ( & V_2 -> V_30 ) ;
for ( V_36 = F_19 ( & V_32 -> V_37 ) ;
V_36 != NULL ;
V_36 = F_20 ( V_36 ) ) {
V_34 = F_21 ( V_36 ,
struct V_33 , V_38 ) ;
if ( ! F_28 ( V_228 -> V_263 ,
& V_34 -> V_216 ) )
continue;
if ( ! F_97 ( & V_34 -> V_76 ) )
continue;
F_16 ( & V_2 -> V_30 ) ;
F_26 () ;
V_12 = F_180 ( V_34 , V_228 ) ;
if ( V_12 < 0 ) {
F_5 ( V_228 -> V_263 , & V_34 -> V_216 ) ;
F_85 ( V_34 ) ;
V_12 = F_197 ( V_2 , V_12 ) ;
return ( V_12 != 0 ) ? V_12 : - V_100 ;
}
F_85 ( V_34 ) ;
goto V_236;
}
F_16 ( & V_2 -> V_30 ) ;
}
F_26 () ;
return 0 ;
}
static int F_199 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
const struct V_264 * V_228 =
V_2 -> V_143 -> V_265 ;
int V_12 ;
if ( F_3 ( V_193 , & V_2 -> V_18 ) )
return 0 ;
F_15 ( & V_2 -> V_30 ) ;
V_4 = V_228 -> V_266 ( V_2 ) ;
F_16 ( & V_2 -> V_30 ) ;
if ( V_4 == NULL ) {
V_4 = F_48 ( V_2 ) ;
V_12 = - V_267 ;
if ( V_4 == NULL )
goto V_26;
}
V_12 = V_228 -> V_268 ( V_2 , V_4 ) ;
F_17 ( V_4 ) ;
if ( V_12 == - V_269 ) {
F_5 ( V_194 , & V_2 -> V_18 ) ;
return 0 ;
}
V_26:
return F_197 ( V_2 , V_12 ) ;
}
static int F_200 ( struct V_1 * V_2 , int V_12 )
{
switch ( V_12 ) {
case - V_262 :
if ( F_145 ( V_70 , & V_2 -> V_18 ) )
return - V_270 ;
F_182 ( 1 ) ;
F_7 ( V_17 , & V_2 -> V_18 ) ;
break;
case - V_173 :
F_7 ( V_17 , & V_2 -> V_18 ) ;
F_188 ( V_2 ) ;
break;
case - V_271 :
F_156 ( L_21 ,
V_2 -> V_195 ) ;
F_42 ( V_2 , - V_272 ) ;
F_7 ( V_17 , & V_2 -> V_18 ) ;
return - V_272 ;
case - V_253 :
case - V_273 :
case - V_269 :
case - V_100 :
F_182 ( 1 ) ;
break;
case - V_274 :
if ( V_2 -> V_210 == V_275 )
F_42 ( V_2 , - V_276 ) ;
F_154 ( L_22 ,
V_192 , - V_276 , V_2 -> V_195 ) ;
return - V_276 ;
case - V_277 :
default:
F_154 ( L_22 , V_192 ,
V_12 , V_2 -> V_195 ) ;
return V_12 ;
}
F_5 ( V_193 , & V_2 -> V_18 ) ;
F_154 ( L_20 , V_192 , V_12 ,
V_2 -> V_195 ) ;
return 0 ;
}
static int F_201 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
const struct V_227 * V_228 =
V_2 -> V_143 -> V_258 ;
int V_12 ;
F_34 ( V_2 ) ;
V_4 = F_48 ( V_2 ) ;
if ( V_4 == NULL )
return - V_156 ;
V_12 = V_228 -> V_278 ( V_2 , V_4 ) ;
F_17 ( V_4 ) ;
if ( V_12 != 0 )
return V_12 ;
F_202 ( V_2 ) ;
return 0 ;
}
static int F_203 ( struct V_1 * V_2 )
{
int V_12 ;
V_12 = F_201 ( V_2 ) ;
if ( V_12 < 0 )
return F_200 ( V_2 , V_12 ) ;
if ( F_28 ( V_279 , & V_2 -> V_18 ) )
F_195 ( V_2 ) ;
if ( ! F_3 ( V_219 , & V_2 -> V_18 ) )
F_5 ( V_217 , & V_2 -> V_18 ) ;
F_7 ( V_194 , & V_2 -> V_18 ) ;
F_7 ( V_193 , & V_2 -> V_18 ) ;
return 0 ;
}
static int F_204 ( struct V_1 * V_2 )
{
int V_12 ;
V_12 = F_201 ( V_2 ) ;
if ( V_12 < 0 )
return F_200 ( V_2 , V_12 ) ;
F_7 ( V_70 , & V_2 -> V_18 ) ;
F_5 ( V_193 , & V_2 -> V_18 ) ;
F_195 ( V_2 ) ;
return 0 ;
}
static int F_205 ( struct V_31 * V_32 , struct V_3 * V_4 )
{
struct V_1 * V_2 = V_32 -> V_1 ;
struct V_280 * V_281 = NULL ;
struct V_113 * V_113 ;
struct V_282 * V_282 ;
int V_12 , V_27 ;
F_154 ( L_23 , V_192 ,
( unsigned long long ) V_32 -> V_201 . V_202 ,
( unsigned long long ) V_32 -> V_201 . V_203 ,
V_2 -> V_195 ) ;
V_27 = 0 ;
V_282 = F_206 ( V_129 ) ;
V_281 = F_127 ( sizeof( struct V_280 ) , V_129 ) ;
if ( V_282 == NULL || V_281 == NULL ) {
F_154 ( L_24 , V_192 ) ;
goto V_26;
}
V_113 = F_207 ( V_32 -> V_283 -> V_284 ) ;
V_27 = F_208 ( V_113 , V_281 , V_282 , V_4 ) ;
if ( V_27 ) {
F_154 ( L_25 ,
V_192 , V_27 ) ;
goto V_26;
}
V_27 = - V_285 ;
if ( ! ( V_281 -> V_286 . V_287 & V_288 ) ) {
F_154 ( L_26 ,
V_192 ) ;
goto V_26;
}
F_34 ( V_2 ) ;
V_12 = F_209 ( V_32 , V_281 ) ;
if ( V_12 != 0 ) {
F_154 ( L_27 ,
V_192 , V_12 ) ;
goto V_26;
}
V_27 = 0 ;
F_154 ( L_28 , V_192 ) ;
V_26:
if ( V_282 != NULL )
F_210 ( V_282 ) ;
F_76 ( V_281 ) ;
if ( V_27 ) {
F_156 ( L_29 ,
V_2 -> V_195 ) ;
F_5 ( V_199 , & V_32 -> V_200 ) ;
}
return V_27 ;
}
static int F_211 ( struct V_1 * V_2 )
{
const struct V_264 * V_228 =
V_2 -> V_143 -> V_265 ;
struct V_31 * V_32 ;
struct V_3 * V_4 ;
F_154 ( L_30 , V_192 ,
V_2 -> V_195 ) ;
F_15 ( & V_2 -> V_30 ) ;
V_4 = V_228 -> V_266 ( V_2 ) ;
F_16 ( & V_2 -> V_30 ) ;
if ( V_4 == NULL )
return - V_289 ;
V_2 -> V_290 ++ ;
V_236:
F_24 () ;
F_25 (server, &clp->cl_superblocks, client_link) {
int V_12 ;
if ( V_32 -> V_291 == V_2 -> V_290 )
continue;
V_32 -> V_291 = V_2 -> V_290 ;
if ( ! F_28 ( V_204 ,
& V_32 -> V_200 ) )
continue;
F_26 () ;
V_12 = F_205 ( V_32 , V_4 ) ;
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
static int F_212 ( struct V_1 * V_2 )
{
const struct V_264 * V_228 =
V_2 -> V_143 -> V_265 ;
struct V_31 * V_32 ;
struct V_3 * V_4 ;
F_154 ( L_31 , V_192 ,
V_2 -> V_195 ) ;
F_15 ( & V_2 -> V_30 ) ;
V_4 = V_228 -> V_266 ( V_2 ) ;
F_16 ( & V_2 -> V_30 ) ;
if ( V_4 == NULL )
return - V_289 ;
V_2 -> V_290 ++ ;
V_236:
F_24 () ;
F_25 (server, &clp->cl_superblocks, client_link) {
struct V_113 * V_113 ;
int V_12 ;
if ( V_32 -> V_291 == V_2 -> V_290 )
continue;
V_32 -> V_291 = V_2 -> V_290 ;
F_26 () ;
V_113 = F_207 ( V_32 -> V_283 -> V_284 ) ;
V_12 = F_213 ( V_113 , V_4 ) ;
if ( V_12 != - V_292 )
goto V_236;
if ( F_205 ( V_32 , V_4 ) == - V_293 )
goto V_236;
goto V_26;
}
F_26 () ;
V_26:
F_17 ( V_4 ) ;
return 0 ;
}
int F_214 ( struct V_1 * V_2 ,
struct V_1 * * V_27 )
{
const struct V_227 * V_228 =
V_2 -> V_143 -> V_258 ;
struct V_294 * V_295 ;
struct V_3 * V_4 ;
int V_296 , V_12 ;
F_154 ( L_32 , V_192 , V_2 -> V_195 ) ;
V_295 = V_2 -> V_188 ;
V_296 = 0 ;
F_215 ( & V_297 ) ;
V_298:
V_12 = - V_156 ;
V_4 = F_48 ( V_2 ) ;
if ( V_4 == NULL )
goto V_299;
V_12 = V_228 -> V_300 ( V_2 , V_27 , V_4 ) ;
F_17 ( V_4 ) ;
switch ( V_12 ) {
case 0 :
break;
case - V_269 :
if ( V_295 -> V_301 )
break;
case - V_273 :
case - V_100 :
F_182 ( 1 ) ;
case - V_173 :
F_154 ( L_33 ,
V_192 , V_12 ) ;
goto V_298;
case - V_253 :
if ( V_296 ++ == 0 ) {
F_13 ( V_2 ) ;
goto V_298;
}
if ( V_295 -> V_302 -> V_303 == V_304 )
break;
case - V_271 :
case - V_305 :
if ( V_295 -> V_302 -> V_303 == V_304 ) {
V_12 = - V_272 ;
break;
}
V_295 = F_216 ( V_295 , V_304 ) ;
if ( F_149 ( V_295 ) ) {
V_12 = F_151 ( V_295 ) ;
break;
}
V_295 = F_217 ( & V_2 -> V_188 , V_295 ) ;
F_218 ( V_295 ) ;
V_295 = V_2 -> V_188 ;
goto V_298;
case - V_274 :
V_12 = - V_276 ;
break;
case - V_306 :
case - V_277 :
V_12 = - V_306 ;
break;
default:
F_219 ( L_34 ,
V_192 , V_12 ) ;
V_12 = - V_159 ;
}
V_299:
F_220 ( & V_297 ) ;
F_154 ( L_35 , V_192 , V_12 ) ;
return V_12 ;
}
void F_221 ( struct V_46 * V_307 , int V_78 )
{
struct V_1 * V_2 = V_307 -> V_2 ;
switch ( V_78 ) {
default:
F_5 ( V_64 , & V_2 -> V_18 ) ;
break;
case - V_246 :
F_5 ( V_65 , & V_2 -> V_18 ) ;
}
F_153 ( V_2 ) ;
}
void F_222 ( struct V_1 * V_2 )
{
F_5 ( V_194 , & V_2 -> V_18 ) ;
F_45 ( V_2 ) ;
}
static void F_223 ( struct V_1 * V_2 )
{
if ( F_145 ( V_193 , & V_2 -> V_18 ) == 0 ) {
F_5 ( V_70 , & V_2 -> V_18 ) ;
F_7 ( V_17 , & V_2 -> V_18 ) ;
F_195 ( V_2 ) ;
F_154 ( L_36 ,
V_192 , V_2 -> V_195 ) ;
F_45 ( V_2 ) ;
}
}
static void F_224 ( struct V_1 * V_2 )
{
if ( F_145 ( V_193 , & V_2 -> V_18 ) == 0 ) {
F_188 ( V_2 ) ;
F_154 ( L_37 , V_192 ,
V_2 -> V_195 ) ;
F_45 ( V_2 ) ;
}
}
static void F_225 ( struct V_1 * V_2 )
{
F_223 ( V_2 ) ;
F_154 ( L_38 , V_192 , V_2 -> V_195 ) ;
}
static void F_226 ( struct V_1 * V_2 )
{
F_195 ( V_2 ) ;
F_45 ( V_2 ) ;
F_154 ( L_38 , V_192 , V_2 -> V_195 ) ;
}
static void F_227 ( struct V_1 * V_2 )
{
F_202 ( V_2 ) ;
F_226 ( V_2 ) ;
F_154 ( L_39 , V_192 ,
V_2 -> V_195 ) ;
}
static void F_228 ( struct V_1 * V_2 )
{
F_5 ( V_64 , & V_2 -> V_18 ) ;
F_45 ( V_2 ) ;
F_154 ( L_40 , V_192 ,
V_2 -> V_195 ) ;
}
static void F_229 ( struct V_1 * V_2 )
{
if ( F_145 ( V_65 ,
& V_2 -> V_18 ) == 0 )
F_45 ( V_2 ) ;
}
void F_230 ( struct V_1 * V_2 , T_5 V_85 ,
bool V_308 )
{
if ( ! V_85 )
return;
F_154 ( L_41 ,
V_192 , V_2 -> V_195 , V_2 -> V_8 , V_85 ) ;
if ( V_308 )
goto V_309;
if ( V_85 & V_310 )
F_224 ( V_2 ) ;
if ( V_85 & ( V_311 ) )
F_225 ( V_2 ) ;
if ( V_85 & ( V_312 |
V_313 ) )
F_226 ( V_2 ) ;
if ( V_85 & V_314 )
F_157 ( V_2 ) ;
if ( V_85 & V_315 )
F_227 ( V_2 ) ;
V_309:
if ( V_85 & V_316 )
F_228 ( V_2 ) ;
else if ( V_85 & ( V_317 |
V_318 ) )
F_229 ( V_2 ) ;
}
static int F_231 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
int V_12 ;
if ( ! F_136 ( V_2 ) )
return 0 ;
F_34 ( V_2 ) ;
V_4 = F_48 ( V_2 ) ;
V_12 = F_232 ( V_2 -> V_48 , V_4 ) ;
switch ( V_12 ) {
case 0 :
case - V_243 :
case - V_260 :
break;
case - V_319 :
case - V_273 :
F_5 ( V_64 , & V_2 -> V_18 ) ;
V_12 = 0 ;
F_182 ( 1 ) ;
goto V_26;
default:
V_12 = F_197 ( V_2 , V_12 ) ;
goto V_26;
}
memset ( V_2 -> V_48 -> V_320 . V_321 , 0 , V_322 ) ;
V_12 = F_41 ( V_2 , V_4 ) ;
if ( V_12 ) {
F_154 ( L_42 ,
V_192 , V_12 , V_2 -> V_195 ) ;
V_12 = F_200 ( V_2 , V_12 ) ;
goto V_26;
}
F_38 ( V_2 ) ;
F_154 ( L_43 ,
V_192 , V_2 -> V_195 ) ;
V_26:
if ( V_4 )
F_17 ( V_4 ) ;
return V_12 ;
}
static int F_233 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
int V_55 ;
if ( ! F_136 ( V_2 ) )
return 0 ;
F_34 ( V_2 ) ;
V_4 = F_48 ( V_2 ) ;
V_55 = F_234 ( V_2 , V_4 ) ;
if ( V_4 )
F_17 ( V_4 ) ;
F_7 ( V_65 , & V_2 -> V_18 ) ;
switch ( V_55 ) {
case 0 :
F_154 ( L_44 ,
V_192 , V_2 -> V_195 ) ;
break;
case - V_273 :
F_182 ( 1 ) ;
F_5 ( V_65 , & V_2 -> V_18 ) ;
break;
default:
return F_197 ( V_2 , V_55 ) ;
}
return 0 ;
}
static int F_231 ( struct V_1 * V_2 ) { return 0 ; }
static int F_233 ( struct V_1 * V_2 )
{
return 0 ;
}
static void F_235 ( struct V_1 * V_2 )
{
int V_12 = 0 ;
const char * V_323 = L_45 , * V_324 = L_45 ;
do {
if ( F_3 ( V_70 , & V_2 -> V_18 ) ) {
V_323 = L_46 ;
V_12 = F_204 ( V_2 ) ;
if ( V_12 < 0 )
goto V_325;
continue;
}
if ( F_3 ( V_193 , & V_2 -> V_18 ) ) {
V_323 = L_47 ;
V_12 = F_203 ( V_2 ) ;
if ( V_12 < 0 )
goto V_325;
continue;
}
if ( F_28 ( V_64 , & V_2 -> V_18 ) ) {
V_323 = L_48 ;
V_12 = F_231 ( V_2 ) ;
if ( F_3 ( V_193 , & V_2 -> V_18 ) )
continue;
if ( V_12 < 0 )
goto V_325;
}
if ( F_28 ( V_65 ,
& V_2 -> V_18 ) ) {
V_323 = L_49 ;
V_12 = F_233 ( V_2 ) ;
if ( V_12 < 0 )
goto V_325;
continue;
}
if ( F_28 ( V_194 , & V_2 -> V_18 ) ) {
V_323 = L_50 ;
V_12 = F_199 ( V_2 ) ;
if ( V_12 < 0 )
goto V_325;
continue;
}
if ( F_28 ( V_205 , & V_2 -> V_18 ) ) {
V_323 = L_51 ;
V_12 = F_211 ( V_2 ) ;
if ( V_12 < 0 )
goto V_325;
}
if ( F_28 ( V_206 , & V_2 -> V_18 ) ) {
V_323 = L_52 ;
V_12 = F_212 ( V_2 ) ;
if ( V_12 < 0 )
goto V_325;
}
if ( F_3 ( V_217 , & V_2 -> V_18 ) ) {
V_323 = L_53 ;
V_12 = F_198 ( V_2 ,
V_2 -> V_143 -> V_258 ) ;
if ( V_12 == - V_100 )
continue;
if ( V_12 < 0 )
goto V_325;
F_194 ( V_2 ) ;
}
if ( F_28 ( V_326 , & V_2 -> V_18 ) ) {
V_323 = L_54 ;
F_236 ( V_2 ) ;
continue;
}
if ( F_28 ( V_219 , & V_2 -> V_18 ) ) {
V_323 = L_55 ;
V_12 = F_198 ( V_2 ,
V_2 -> V_143 -> V_327 ) ;
if ( V_12 == - V_100 )
continue;
if ( V_12 < 0 )
goto V_325;
}
F_30 ( V_2 ) ;
if ( F_28 ( V_328 , & V_2 -> V_18 ) ) {
F_237 ( V_2 ) ;
continue;
}
F_140 ( V_2 ) ;
if ( V_2 -> V_18 == 0 )
break;
if ( F_145 ( V_181 , & V_2 -> V_18 ) != 0 )
break;
} while ( F_238 ( & V_2 -> V_187 ) > 1 );
return;
V_325:
if ( strlen ( V_323 ) )
V_324 = L_56 ;
F_133 ( L_57
L_58 , V_324 , V_323 ,
V_2 -> V_195 , - V_12 ) ;
F_182 ( 1 ) ;
F_30 ( V_2 ) ;
F_140 ( V_2 ) ;
}
static int V_190 ( void * V_329 )
{
struct V_1 * V_2 = V_329 ;
F_239 ( V_330 ) ;
F_235 ( V_2 ) ;
F_47 ( V_2 ) ;
F_240 ( 0 ) ;
return 0 ;
}
