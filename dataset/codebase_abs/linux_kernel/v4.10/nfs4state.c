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
V_34 -> V_80 . V_84 = F_62 () ;
}
static void F_74 ( struct V_33 * V_34 )
{
F_66 ( & V_34 -> V_80 ) ;
F_17 ( V_34 -> V_40 ) ;
F_75 ( V_34 ) ;
}
static void F_76 ( struct V_31 * V_32 )
{
struct V_1 * V_2 = V_32 -> V_1 ;
struct V_33 * V_34 , * V_94 ;
unsigned long V_95 , V_96 ;
F_77 ( V_97 ) ;
F_15 ( & V_2 -> V_30 ) ;
V_96 = V_61 ;
V_95 = ( long ) V_96 - ( long ) V_2 -> V_98 ;
F_78 (sp, tmp, &server->state_owners_lru, so_lru) {
if ( F_79 ( V_34 -> V_99 , V_95 , V_96 ) )
break;
F_80 ( & V_34 -> V_75 , & V_97 ) ;
F_57 ( V_34 ) ;
}
F_16 ( & V_2 -> V_30 ) ;
F_78 (sp, tmp, &doomed, so_lru) {
F_81 ( & V_34 -> V_75 ) ;
F_74 ( V_34 ) ;
}
}
struct V_33 * F_82 ( struct V_31 * V_32 ,
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
if ( F_83 ( & V_32 -> V_79 , V_90 ) == 0 )
break;
F_15 ( & V_2 -> V_30 ) ;
V_34 = F_52 ( V_29 ) ;
F_16 ( & V_2 -> V_30 ) ;
} while ( V_34 == F_54 ( - V_100 ) );
if ( V_34 != V_29 )
F_74 ( V_29 ) ;
V_26:
F_76 ( V_32 ) ;
return V_34 ;
}
void F_84 ( struct V_33 * V_34 )
{
struct V_31 * V_32 = V_34 -> V_77 ;
struct V_1 * V_2 = V_32 -> V_1 ;
if ( ! F_85 ( & V_34 -> V_76 , & V_2 -> V_30 ) )
return;
V_34 -> V_99 = V_61 ;
F_86 ( & V_34 -> V_75 , & V_32 -> V_101 ) ;
F_16 ( & V_2 -> V_30 ) ;
}
void F_87 ( struct V_31 * V_32 )
{
struct V_1 * V_2 = V_32 -> V_1 ;
struct V_33 * V_34 , * V_94 ;
F_77 ( V_97 ) ;
F_15 ( & V_2 -> V_30 ) ;
F_78 (sp, tmp, &server->state_owners_lru, so_lru) {
F_80 ( & V_34 -> V_75 , & V_97 ) ;
F_57 ( V_34 ) ;
}
F_16 ( & V_2 -> V_30 ) ;
F_78 (sp, tmp, &doomed, so_lru) {
F_81 ( & V_34 -> V_75 ) ;
F_74 ( V_34 ) ;
}
}
static struct V_102 *
F_88 ( void )
{
struct V_102 * V_103 ;
V_103 = F_69 ( sizeof( * V_103 ) , V_104 ) ;
if ( ! V_103 )
return NULL ;
F_70 ( & V_103 -> V_105 , 1 ) ;
F_64 ( & V_103 -> V_106 ) ;
F_63 ( & V_103 -> V_107 ) ;
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
F_15 ( & V_112 -> V_91 ) ;
F_15 ( & V_113 -> V_116 ) ;
V_103 = F_92 ( V_113 , V_112 ) ;
if ( V_103 == NULL && V_29 != NULL ) {
V_103 = V_29 ;
V_103 -> V_112 = V_112 ;
F_51 ( & V_112 -> V_76 ) ;
F_99 ( & V_103 -> V_117 , & V_115 -> V_111 ) ;
F_100 ( V_113 ) ;
V_103 -> V_113 = V_113 ;
F_16 ( & V_113 -> V_116 ) ;
F_86 ( & V_103 -> V_111 , & V_112 -> V_39 ) ;
F_16 ( & V_112 -> V_91 ) ;
} else {
F_16 ( & V_113 -> V_116 ) ;
F_16 ( & V_112 -> V_91 ) ;
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
if ( ! F_85 ( & V_103 -> V_105 , & V_112 -> V_91 ) )
return;
F_15 ( & V_113 -> V_116 ) ;
F_81 ( & V_103 -> V_117 ) ;
F_81 ( & V_103 -> V_111 ) ;
F_16 ( & V_113 -> V_116 ) ;
F_16 ( & V_112 -> V_91 ) ;
F_102 ( V_113 ) ;
F_97 ( V_103 ) ;
F_84 ( V_112 ) ;
}
static void F_103 ( struct V_102 * V_103 ,
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
F_90 ( V_103 , V_120 ) ;
F_16 ( & V_112 -> V_91 ) ;
if ( ! V_119 ) {
F_101 ( V_103 ) ;
F_84 ( V_112 ) ;
} else
F_104 ( V_103 , V_118 , V_89 ) ;
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
F_107 ( struct V_102 * V_103 ,
T_3 V_131 , T_3 V_132 )
{
struct V_130 * V_36 , * V_55 = NULL ;
F_94 (pos, &state->lock_states, ls_locks) {
if ( V_36 -> V_133 == V_131 ) {
V_55 = V_36 ;
break;
}
if ( V_36 -> V_133 == V_132 )
V_55 = V_36 ;
}
if ( V_55 )
F_51 ( & V_55 -> V_134 ) ;
return V_55 ;
}
static struct V_130 * F_108 ( struct V_102 * V_103 , T_3 V_131 )
{
struct V_130 * V_135 ;
struct V_31 * V_32 = V_103 -> V_112 -> V_77 ;
V_135 = F_69 ( sizeof( * V_135 ) , V_104 ) ;
if ( V_135 == NULL )
return NULL ;
F_61 ( & V_135 -> V_136 ) ;
F_70 ( & V_135 -> V_134 , 1 ) ;
V_135 -> V_137 = V_103 ;
V_135 -> V_133 = V_131 ;
V_135 -> V_136 . V_81 = F_109 ( & V_32 -> V_138 , 0 , 0 , V_104 ) ;
if ( V_135 -> V_136 . V_81 < 0 )
goto V_139;
F_64 ( & V_135 -> V_140 ) ;
return V_135 ;
V_139:
F_75 ( V_135 ) ;
return NULL ;
}
void F_110 ( struct V_31 * V_32 , struct V_130 * V_135 )
{
F_111 ( & V_32 -> V_138 , V_135 -> V_136 . V_81 ) ;
F_66 ( & V_135 -> V_136 ) ;
F_75 ( V_135 ) ;
}
static struct V_130 * F_112 ( struct V_102 * V_103 , T_3 V_112 )
{
struct V_130 * V_135 , * V_29 = NULL ;
for(; ; ) {
F_15 ( & V_103 -> V_107 ) ;
V_135 = F_107 ( V_103 , V_112 , 0 ) ;
if ( V_135 != NULL )
break;
if ( V_29 != NULL ) {
F_99 ( & V_29 -> V_140 , & V_103 -> V_106 ) ;
F_5 ( V_141 , & V_103 -> V_85 ) ;
V_135 = V_29 ;
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
F_110 ( V_103 -> V_112 -> V_77 , V_29 ) ;
return V_135 ;
}
void F_113 ( struct V_130 * V_135 )
{
struct V_31 * V_32 ;
struct V_102 * V_103 ;
if ( V_135 == NULL )
return;
V_103 = V_135 -> V_137 ;
if ( ! F_85 ( & V_135 -> V_134 , & V_103 -> V_107 ) )
return;
F_81 ( & V_135 -> V_140 ) ;
if ( F_22 ( & V_103 -> V_106 ) )
F_7 ( V_141 , & V_103 -> V_85 ) ;
F_16 ( & V_103 -> V_107 ) ;
V_32 = V_103 -> V_112 -> V_77 ;
if ( F_3 ( V_142 , & V_135 -> V_143 ) ) {
struct V_1 * V_2 = V_32 -> V_1 ;
V_2 -> V_144 -> V_145 ( V_32 , V_135 ) ;
} else
F_110 ( V_32 , V_135 ) ;
}
static void F_114 ( struct V_146 * V_147 , struct V_146 * V_148 )
{
struct V_130 * V_135 = V_148 -> V_149 . V_150 . V_112 ;
V_147 -> V_149 . V_150 . V_112 = V_135 ;
F_51 ( & V_135 -> V_134 ) ;
}
static void F_115 ( struct V_146 * V_151 )
{
F_113 ( V_151 -> V_149 . V_150 . V_112 ) ;
}
int F_116 ( struct V_102 * V_103 , struct V_146 * V_151 )
{
struct V_130 * V_135 ;
if ( V_151 -> V_152 != NULL )
return 0 ;
V_135 = F_112 ( V_103 , V_151 -> V_131 ) ;
if ( V_135 == NULL )
return - V_153 ;
V_151 -> V_149 . V_150 . V_112 = V_135 ;
V_151 -> V_152 = & V_154 ;
return 0 ;
}
static int F_117 ( T_4 * V_147 ,
struct V_102 * V_103 ,
const struct V_155 * V_156 )
{
struct V_130 * V_135 ;
T_3 V_131 , V_157 ;
int V_55 = - V_158 ;
if ( V_156 == NULL )
goto V_26;
if ( F_3 ( V_141 , & V_103 -> V_85 ) == 0 )
goto V_26;
V_131 = V_156 -> V_159 ;
V_157 = V_156 -> V_160 -> V_161 ;
F_15 ( & V_103 -> V_107 ) ;
V_135 = F_107 ( V_103 , V_131 , V_157 ) ;
if ( V_135 && F_3 ( V_162 , & V_135 -> V_143 ) )
V_55 = - V_163 ;
else if ( V_135 != NULL && F_3 ( V_142 , & V_135 -> V_143 ) != 0 ) {
F_118 ( V_147 , & V_135 -> V_164 ) ;
V_55 = 0 ;
}
F_16 ( & V_103 -> V_107 ) ;
F_113 ( V_135 ) ;
V_26:
return V_55 ;
}
static void F_119 ( T_4 * V_147 , struct V_102 * V_103 )
{
const T_4 * V_148 ;
int V_165 ;
do {
V_148 = & V_166 ;
V_165 = F_120 ( & V_103 -> V_108 ) ;
if ( F_3 ( V_167 , & V_103 -> V_85 ) )
V_148 = & V_103 -> V_168 ;
F_118 ( V_147 , V_148 ) ;
} while ( F_121 ( & V_103 -> V_108 , V_165 ) );
}
int F_122 ( struct V_102 * V_103 ,
T_2 V_109 , const struct V_155 * V_156 ,
T_4 * V_147 , struct V_3 * * V_4 )
{
int V_55 ;
if ( ! F_95 ( V_103 ) )
return - V_163 ;
if ( V_4 != NULL )
* V_4 = NULL ;
V_55 = F_117 ( V_147 , V_103 , V_156 ) ;
if ( V_55 == - V_163 )
goto V_26;
if ( F_123 ( V_103 -> V_113 , V_109 , V_147 , V_4 ) ) {
V_55 = 0 ;
goto V_26;
}
if ( V_55 != - V_158 )
goto V_26;
F_119 ( V_147 , V_103 ) ;
V_55 = 0 ;
V_26:
if ( F_124 ( V_103 -> V_113 , V_169 ) )
V_147 -> V_170 = 0 ;
return V_55 ;
}
struct V_171 * F_125 ( struct V_82 * V_86 , T_1 V_118 )
{
struct V_171 * V_29 ;
V_29 = F_126 ( sizeof( * V_29 ) , V_118 ) ;
if ( V_29 == NULL )
return F_54 ( - V_153 ) ;
V_29 -> V_172 = V_86 ;
F_64 ( & V_29 -> V_88 ) ;
V_29 -> V_173 = NULL ;
return V_29 ;
}
void F_127 ( struct V_171 * V_170 )
{
struct V_82 * V_172 ;
if ( V_170 == NULL || F_22 ( & V_170 -> V_88 ) )
return;
V_172 = V_170 -> V_172 ;
F_15 ( & V_172 -> V_87 ) ;
F_50 ( & V_170 -> V_88 ) ;
if ( ! F_22 ( & V_172 -> V_88 ) ) {
struct V_171 * V_174 ;
V_174 = F_128 ( & V_172 -> V_88 ,
struct V_171 , V_88 ) ;
F_129 ( & V_172 -> V_89 , V_174 -> V_173 ) ;
}
F_16 ( & V_172 -> V_87 ) ;
}
void F_130 ( struct V_171 * V_170 )
{
F_127 ( V_170 ) ;
F_75 ( V_170 ) ;
}
static void F_131 ( int V_12 , struct V_171 * V_170 )
{
switch ( V_12 ) {
case 0 :
break;
case - V_175 :
if ( V_170 -> V_172 -> V_85 & V_176 )
return;
F_132 ( L_2
L_3
L_4 ,
V_170 -> V_172 ) ;
case - V_177 :
case - V_178 :
case - V_179 :
case - V_180 :
case - V_181 :
case - V_182 :
case - V_183 :
return;
} ;
V_170 -> V_172 -> V_86 ++ ;
}
void F_133 ( int V_12 , struct V_171 * V_170 )
{
struct V_33 * V_34 ;
if ( V_170 == NULL )
return;
V_34 = F_134 ( V_170 -> V_172 , struct V_33 , V_80 ) ;
if ( V_12 == - V_175 )
F_73 ( V_34 ) ;
if ( ! F_135 ( V_34 -> V_77 -> V_1 ) )
F_131 ( V_12 , V_170 ) ;
}
void F_136 ( int V_12 , struct V_171 * V_170 )
{
if ( V_170 != NULL )
F_131 ( V_12 , V_170 ) ;
}
int F_137 ( struct V_171 * V_170 , struct V_184 * V_173 )
{
struct V_82 * V_172 ;
int V_12 = 0 ;
if ( V_170 == NULL )
goto V_26;
V_172 = V_170 -> V_172 ;
F_15 ( & V_172 -> V_87 ) ;
V_170 -> V_173 = V_173 ;
if ( F_22 ( & V_170 -> V_88 ) )
F_86 ( & V_170 -> V_88 , & V_172 -> V_88 ) ;
if ( F_128 ( & V_172 -> V_88 , struct V_171 , V_88 ) == V_170 )
goto V_185;
F_138 ( & V_172 -> V_89 , V_173 , NULL ) ;
V_12 = - V_100 ;
V_185:
F_16 ( & V_172 -> V_87 ) ;
V_26:
return V_12 ;
}
static void F_139 ( struct V_1 * V_2 )
{
F_140 () ;
F_7 ( V_186 , & V_2 -> V_18 ) ;
F_141 () ;
F_142 ( & V_2 -> V_18 , V_186 ) ;
F_143 ( & V_2 -> V_187 ) ;
}
void F_45 ( struct V_1 * V_2 )
{
struct V_188 * V_173 ;
char V_189 [ V_190 + sizeof( L_5 ) + 1 ] ;
if ( F_144 ( V_186 , & V_2 -> V_18 ) != 0 )
return;
F_145 ( V_191 ) ;
F_51 ( & V_2 -> V_192 ) ;
F_24 () ;
snprintf ( V_189 , sizeof( V_189 ) , L_6 ,
F_146 ( V_2 -> V_193 , V_194 ) ) ;
F_26 () ;
V_173 = F_147 ( V_195 , V_2 , L_7 , V_189 ) ;
if ( F_148 ( V_173 ) ) {
F_149 ( V_196 L_8 ,
V_197 , F_150 ( V_173 ) ) ;
F_139 ( V_2 ) ;
F_47 ( V_2 ) ;
F_151 ( V_191 ) ;
}
}
void F_152 ( struct V_1 * V_2 )
{
if ( ! V_2 )
return;
if ( ! F_3 ( V_198 , & V_2 -> V_18 ) )
F_5 ( V_199 , & V_2 -> V_18 ) ;
F_153 ( L_9 , V_197 ,
V_2 -> V_200 ) ;
F_45 ( V_2 ) ;
}
int F_154 ( const struct V_31 * V_32 )
{
struct V_1 * V_2 = V_32 -> V_1 ;
if ( V_32 -> V_201 != V_202 ) {
F_155 ( L_10 ,
V_2 -> V_200 ) ;
return - V_203 ;
}
if ( F_3 ( V_204 , & V_32 -> V_205 ) )
return - V_203 ;
F_153 ( L_11 ,
V_197 ,
( unsigned long long ) V_32 -> V_206 . V_207 ,
( unsigned long long ) V_32 -> V_206 . V_208 ,
V_2 -> V_200 ) ;
F_5 ( V_209 ,
& ( (struct V_31 * ) V_32 ) -> V_205 ) ;
F_5 ( V_210 , & V_2 -> V_18 ) ;
F_45 ( V_2 ) ;
return 0 ;
}
void F_156 ( struct V_1 * V_2 )
{
F_153 ( L_12 ,
V_197 , V_2 -> V_8 , V_2 -> V_200 ) ;
F_5 ( V_211 , & V_2 -> V_18 ) ;
F_45 ( V_2 ) ;
}
int F_157 ( struct V_1 * V_2 )
{
int V_212 ;
F_158 () ;
F_51 ( & V_2 -> V_192 ) ;
V_212 = F_159 ( & V_2 -> V_18 , V_186 ,
V_213 , V_214 ) ;
if ( V_212 )
goto V_26;
if ( V_2 -> V_215 < 0 )
V_212 = V_2 -> V_215 ;
V_26:
F_47 ( V_2 ) ;
return V_212 ;
}
int F_160 ( struct V_1 * V_2 )
{
unsigned int V_216 ;
int V_55 ;
for ( V_216 = V_217 ; V_216 != 0 ; V_216 -- ) {
V_55 = F_157 ( V_2 ) ;
if ( V_55 != 0 )
break;
if ( ! F_3 ( V_198 , & V_2 -> V_18 ) &&
! F_3 ( V_199 , & V_2 -> V_18 ) )
break;
F_45 ( V_2 ) ;
V_55 = - V_163 ;
}
return V_55 ;
}
static void F_161 ( struct V_1 * V_2 )
{
F_5 ( V_198 , & V_2 -> V_18 ) ;
F_162 ( V_2 ) ;
F_153 ( L_13 , V_197 ,
V_2 -> V_200 ) ;
}
void F_163 ( struct V_1 * V_2 )
{
F_161 ( V_2 ) ;
F_45 ( V_2 ) ;
}
static int F_164 ( struct V_1 * V_2 , struct V_102 * V_103 )
{
if ( ! F_95 ( V_103 ) )
return 0 ;
F_5 ( V_218 , & V_103 -> V_85 ) ;
if ( F_3 ( V_219 , & V_103 -> V_85 ) ) {
F_7 ( V_218 , & V_103 -> V_85 ) ;
return 0 ;
}
F_5 ( V_220 , & V_103 -> V_112 -> V_221 ) ;
F_5 ( V_222 , & V_2 -> V_18 ) ;
return 1 ;
}
int F_165 ( struct V_1 * V_2 , struct V_102 * V_103 )
{
if ( ! F_95 ( V_103 ) )
return 0 ;
F_5 ( V_219 , & V_103 -> V_85 ) ;
F_7 ( V_218 , & V_103 -> V_85 ) ;
F_5 ( V_223 , & V_103 -> V_112 -> V_221 ) ;
F_5 ( V_224 , & V_2 -> V_18 ) ;
return 1 ;
}
int F_166 ( const struct V_31 * V_32 , struct V_102 * V_103 )
{
struct V_1 * V_2 = V_32 -> V_1 ;
if ( ! F_165 ( V_2 , V_103 ) )
return - V_225 ;
F_153 ( L_14 , V_197 ,
V_2 -> V_200 ) ;
F_45 ( V_2 ) ;
return 0 ;
}
static struct V_130 *
F_167 ( struct V_102 * V_103 ,
const T_4 * V_226 )
{
struct V_130 * V_36 ;
F_94 (pos, &state->lock_states, ls_locks) {
if ( ! F_3 ( V_142 , & V_36 -> V_143 ) )
continue;
if ( F_168 ( & V_36 -> V_164 , V_226 ) )
return V_36 ;
}
return NULL ;
}
static bool F_169 ( struct V_102 * V_103 ,
const T_4 * V_226 )
{
bool V_227 = false ;
if ( F_3 ( V_141 , & V_103 -> V_85 ) ) {
F_15 ( & V_103 -> V_107 ) ;
if ( F_167 ( V_103 , V_226 ) )
V_227 = true ;
F_16 ( & V_103 -> V_107 ) ;
}
return V_227 ;
}
void F_170 ( struct V_113 * V_113 ,
const T_4 * V_226 )
{
struct V_1 * V_2 = F_171 ( V_113 ) -> V_1 ;
struct V_114 * V_115 = F_93 ( V_113 ) ;
struct V_228 * V_229 ;
struct V_102 * V_103 ;
bool V_227 = false ;
F_15 ( & V_113 -> V_116 ) ;
F_94 (ctx, &nfsi->open_files, list) {
V_103 = V_229 -> V_103 ;
if ( V_103 == NULL )
continue;
if ( F_168 ( & V_103 -> V_226 , V_226 ) &&
F_165 ( V_2 , V_103 ) ) {
V_227 = true ;
continue;
}
if ( F_169 ( V_103 , V_226 ) &&
F_165 ( V_2 , V_103 ) )
V_227 = true ;
}
F_16 ( & V_113 -> V_116 ) ;
F_172 ( V_113 , V_226 ) ;
if ( V_227 )
F_45 ( V_2 ) ;
}
static void F_173 ( struct V_102 * V_103 )
{
struct V_113 * V_113 = V_103 -> V_113 ;
struct V_114 * V_115 = F_93 ( V_113 ) ;
struct V_228 * V_229 ;
F_15 ( & V_113 -> V_116 ) ;
F_94 (ctx, &nfsi->open_files, list) {
if ( V_229 -> V_103 != V_103 )
continue;
F_5 ( V_230 , & V_229 -> V_85 ) ;
}
F_16 ( & V_113 -> V_116 ) ;
}
static void F_174 ( struct V_102 * V_103 , int error )
{
F_5 ( V_231 , & V_103 -> V_85 ) ;
F_173 ( V_103 ) ;
}
static int F_175 ( struct V_102 * V_103 , const struct V_232 * V_233 )
{
struct V_113 * V_113 = V_103 -> V_113 ;
struct V_114 * V_115 = F_93 ( V_113 ) ;
struct V_146 * V_151 ;
int V_12 = 0 ;
struct V_234 * V_235 = V_113 -> V_236 ;
struct V_237 * V_88 ;
if ( V_235 == NULL )
return 0 ;
V_88 = & V_235 -> V_238 ;
F_176 ( & V_115 -> V_239 ) ;
F_15 ( & V_235 -> V_240 ) ;
V_241:
F_94 (fl, list, fl_list) {
if ( F_177 ( V_151 -> V_242 ) -> V_103 != V_103 )
continue;
F_16 ( & V_235 -> V_240 ) ;
V_12 = V_233 -> V_243 ( V_103 , V_151 ) ;
switch ( V_12 ) {
case 0 :
break;
case - V_244 :
case - V_245 :
case - V_178 :
case - V_179 :
case - V_246 :
case - V_247 :
case - V_177 :
case - V_248 :
case - V_249 :
case - V_250 :
case - V_251 :
goto V_26;
default:
F_155 ( L_15 ,
V_197 , V_12 ) ;
case - V_153 :
case - V_252 :
case - V_253 :
case - V_254 :
V_12 = 0 ;
}
F_15 ( & V_235 -> V_240 ) ;
}
if ( V_88 == & V_235 -> V_238 ) {
V_88 = & V_235 -> V_255 ;
goto V_241;
}
F_16 ( & V_235 -> V_240 ) ;
V_26:
F_178 ( & V_115 -> V_239 ) ;
return V_12 ;
}
static int F_179 ( struct V_33 * V_34 , const struct V_232 * V_233 )
{
struct V_102 * V_103 ;
struct V_130 * V_87 ;
int V_12 = 0 ;
F_15 ( & V_34 -> V_91 ) ;
F_180 ( & V_34 -> V_92 ) ;
V_241:
F_94 (state, &sp->so_states, open_states) {
if ( ! F_28 ( V_233 -> V_256 , & V_103 -> V_85 ) )
continue;
if ( ! F_95 ( V_103 ) )
continue;
if ( V_103 -> V_103 == 0 )
continue;
F_51 ( & V_103 -> V_105 ) ;
F_16 ( & V_34 -> V_91 ) ;
V_12 = V_233 -> V_257 ( V_34 , V_103 ) ;
if ( V_12 >= 0 ) {
V_12 = F_175 ( V_103 , V_233 ) ;
if ( V_12 >= 0 ) {
if ( ! F_3 ( V_128 , & V_103 -> V_85 ) ) {
F_15 ( & V_103 -> V_107 ) ;
F_94 (lock, &state->lock_states, ls_locks) {
if ( ! F_3 ( V_142 , & V_87 -> V_143 ) )
F_132 ( L_16
L_17
L_18 , V_197 ) ;
}
F_16 ( & V_103 -> V_107 ) ;
}
F_7 ( V_219 ,
& V_103 -> V_85 ) ;
F_101 ( V_103 ) ;
F_15 ( & V_34 -> V_91 ) ;
goto V_241;
}
}
switch ( V_12 ) {
default:
F_149 ( V_196 L_15 ,
V_197 , V_12 ) ;
case - V_158 :
case - V_153 :
case - V_258 :
case - V_259 :
case - V_163 :
case - V_244 :
F_174 ( V_103 , V_12 ) ;
break;
case - V_100 :
F_181 ( 1 ) ;
case - V_245 :
case - V_178 :
case - V_260 :
case - V_179 :
case - V_253 :
case - V_254 :
F_165 ( V_34 -> V_77 -> V_1 , V_103 ) ;
break;
case - V_246 :
case - V_247 :
F_165 ( V_34 -> V_77 -> V_1 , V_103 ) ;
case - V_177 :
case - V_248 :
case - V_249 :
case - V_250 :
case - V_251 :
goto V_261;
}
F_101 ( V_103 ) ;
F_15 ( & V_34 -> V_91 ) ;
goto V_241;
}
F_182 ( & V_34 -> V_92 ) ;
F_16 ( & V_34 -> V_91 ) ;
return 0 ;
V_261:
F_101 ( V_103 ) ;
F_15 ( & V_34 -> V_91 ) ;
F_182 ( & V_34 -> V_92 ) ;
F_16 ( & V_34 -> V_91 ) ;
return V_12 ;
}
static void F_183 ( struct V_102 * V_103 )
{
struct V_130 * V_87 ;
F_7 ( V_128 , & V_103 -> V_85 ) ;
F_7 ( V_125 , & V_103 -> V_85 ) ;
F_7 ( V_127 , & V_103 -> V_85 ) ;
F_7 ( V_126 , & V_103 -> V_85 ) ;
F_15 ( & V_103 -> V_107 ) ;
F_94 (lock, &state->lock_states, ls_locks) {
V_87 -> V_136 . V_85 = 0 ;
F_7 ( V_142 , & V_87 -> V_143 ) ;
}
F_16 ( & V_103 -> V_107 ) ;
}
static void F_184 ( struct V_31 * V_32 ,
int (* F_185)( struct V_1 * V_2 , struct V_102 * V_103 ) )
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
F_94 (state, &sp->so_states, open_states) {
if ( F_185 ( V_2 , V_103 ) )
F_183 ( V_103 ) ;
}
F_16 ( & V_34 -> V_91 ) ;
}
F_16 ( & V_2 -> V_30 ) ;
}
static void F_186 ( struct V_1 * V_2 ,
int (* F_185)( struct V_1 * V_2 , struct V_102 * V_103 ) )
{
struct V_31 * V_32 ;
F_24 () ;
F_25 (server, &clp->cl_superblocks, client_link)
F_184 ( V_32 , F_185 ) ;
F_26 () ;
}
static void F_187 ( struct V_1 * V_2 )
{
F_188 ( V_2 ) ;
F_186 ( V_2 , F_164 ) ;
}
static void F_189 ( struct V_1 * V_2 ,
const struct V_232 * V_233 ,
struct V_3 * V_4 )
{
if ( V_233 -> V_262 )
( void ) V_233 -> V_262 ( V_2 , V_4 ) ;
}
static void F_190 ( struct V_31 * V_32 )
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
F_94 (state, &sp->so_states, open_states) {
if ( ! F_28 ( V_218 ,
& V_103 -> V_85 ) )
continue;
F_165 ( V_2 , V_103 ) ;
}
F_16 ( & V_34 -> V_91 ) ;
}
F_16 ( & V_2 -> V_30 ) ;
}
static int F_191 ( struct V_1 * V_2 )
{
struct V_31 * V_32 ;
if ( ! F_28 ( V_222 , & V_2 -> V_18 ) )
return 0 ;
F_24 () ;
F_25 (server, &clp->cl_superblocks, client_link)
F_190 ( V_32 ) ;
F_26 () ;
F_192 ( V_2 ) ;
return 1 ;
}
static void F_193 ( struct V_1 * V_2 )
{
const struct V_232 * V_233 ;
struct V_3 * V_4 ;
if ( ! F_191 ( V_2 ) )
return;
V_233 = V_2 -> V_144 -> V_263 ;
V_4 = F_48 ( V_2 ) ;
F_189 ( V_2 , V_233 , V_4 ) ;
F_17 ( V_4 ) ;
}
static void F_194 ( struct V_1 * V_2 )
{
F_195 ( V_2 ) ;
F_186 ( V_2 , F_165 ) ;
}
static int F_196 ( struct V_1 * V_2 , int error )
{
switch ( error ) {
case 0 :
break;
case - V_264 :
F_161 ( V_2 ) ;
break;
case - V_247 :
F_193 ( V_2 ) ;
break;
case - V_177 :
F_5 ( V_198 , & V_2 -> V_18 ) ;
F_187 ( V_2 ) ;
break;
case - V_246 :
F_5 ( V_198 , & V_2 -> V_18 ) ;
F_194 ( V_2 ) ;
break;
case - V_248 :
case - V_249 :
case - V_250 :
case - V_265 :
case - V_266 :
case - V_267 :
F_5 ( V_64 , & V_2 -> V_18 ) ;
break;
case - V_251 :
F_5 ( V_65 , & V_2 -> V_18 ) ;
break;
default:
F_153 ( L_19 ,
V_197 , error , V_2 -> V_200 ) ;
return error ;
}
F_153 ( L_20 , V_197 , error ,
V_2 -> V_200 ) ;
return 0 ;
}
static int F_197 ( struct V_1 * V_2 , const struct V_232 * V_233 )
{
struct V_33 * V_34 ;
struct V_31 * V_32 ;
struct V_35 * V_36 ;
int V_12 = 0 ;
V_241:
F_24 () ;
F_25 (server, &clp->cl_superblocks, client_link) {
F_87 ( V_32 ) ;
F_15 ( & V_2 -> V_30 ) ;
for ( V_36 = F_19 ( & V_32 -> V_37 ) ;
V_36 != NULL ;
V_36 = F_20 ( V_36 ) ) {
V_34 = F_21 ( V_36 ,
struct V_33 , V_38 ) ;
if ( ! F_28 ( V_233 -> V_268 ,
& V_34 -> V_221 ) )
continue;
if ( ! F_96 ( & V_34 -> V_76 ) )
continue;
F_16 ( & V_2 -> V_30 ) ;
F_26 () ;
V_12 = F_179 ( V_34 , V_233 ) ;
if ( V_12 < 0 ) {
F_5 ( V_233 -> V_268 , & V_34 -> V_221 ) ;
F_84 ( V_34 ) ;
V_12 = F_196 ( V_2 , V_12 ) ;
return ( V_12 != 0 ) ? V_12 : - V_100 ;
}
F_84 ( V_34 ) ;
goto V_241;
}
F_16 ( & V_2 -> V_30 ) ;
}
F_26 () ;
return 0 ;
}
static int F_198 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
const struct V_269 * V_233 =
V_2 -> V_144 -> V_270 ;
int V_12 ;
if ( F_3 ( V_198 , & V_2 -> V_18 ) )
return 0 ;
F_15 ( & V_2 -> V_30 ) ;
V_4 = V_233 -> V_271 ( V_2 ) ;
F_16 ( & V_2 -> V_30 ) ;
if ( V_4 == NULL ) {
V_4 = F_48 ( V_2 ) ;
V_12 = - V_272 ;
if ( V_4 == NULL )
goto V_26;
}
V_12 = V_233 -> V_273 ( V_2 , V_4 ) ;
F_17 ( V_4 ) ;
if ( V_12 == - V_274 ) {
F_5 ( V_199 , & V_2 -> V_18 ) ;
return 0 ;
}
V_26:
return F_196 ( V_2 , V_12 ) ;
}
static int F_199 ( struct V_1 * V_2 , int V_12 )
{
switch ( V_12 ) {
case - V_267 :
if ( F_144 ( V_70 , & V_2 -> V_18 ) )
return - V_275 ;
F_181 ( 1 ) ;
F_7 ( V_17 , & V_2 -> V_18 ) ;
break;
case - V_177 :
F_7 ( V_17 , & V_2 -> V_18 ) ;
F_187 ( V_2 ) ;
break;
case - V_276 :
F_155 ( L_21 ,
V_2 -> V_200 ) ;
F_42 ( V_2 , - V_277 ) ;
F_7 ( V_17 , & V_2 -> V_18 ) ;
return - V_277 ;
case - V_258 :
case - V_278 :
case - V_274 :
case - V_100 :
F_181 ( 1 ) ;
break;
case - V_279 :
if ( V_2 -> V_215 == V_280 )
F_42 ( V_2 , - V_281 ) ;
F_153 ( L_22 ,
V_197 , - V_281 , V_2 -> V_200 ) ;
return - V_281 ;
case - V_282 :
default:
F_153 ( L_22 , V_197 ,
V_12 , V_2 -> V_200 ) ;
return V_12 ;
}
F_5 ( V_198 , & V_2 -> V_18 ) ;
F_153 ( L_20 , V_197 , V_12 ,
V_2 -> V_200 ) ;
return 0 ;
}
static int F_200 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
const struct V_232 * V_233 =
V_2 -> V_144 -> V_263 ;
int V_12 ;
F_34 ( V_2 ) ;
V_4 = F_48 ( V_2 ) ;
if ( V_4 == NULL )
return - V_158 ;
V_12 = V_233 -> V_283 ( V_2 , V_4 ) ;
F_17 ( V_4 ) ;
if ( V_12 != 0 )
return V_12 ;
F_201 ( V_2 ) ;
return 0 ;
}
static int F_202 ( struct V_1 * V_2 )
{
int V_12 ;
V_12 = F_200 ( V_2 ) ;
if ( V_12 < 0 )
return F_199 ( V_2 , V_12 ) ;
if ( F_28 ( V_284 , & V_2 -> V_18 ) )
F_194 ( V_2 ) ;
if ( ! F_3 ( V_224 , & V_2 -> V_18 ) )
F_5 ( V_222 , & V_2 -> V_18 ) ;
F_7 ( V_199 , & V_2 -> V_18 ) ;
F_7 ( V_198 , & V_2 -> V_18 ) ;
return 0 ;
}
static int F_203 ( struct V_1 * V_2 )
{
int V_12 ;
V_12 = F_200 ( V_2 ) ;
if ( V_12 < 0 )
return F_199 ( V_2 , V_12 ) ;
F_7 ( V_70 , & V_2 -> V_18 ) ;
F_5 ( V_198 , & V_2 -> V_18 ) ;
F_194 ( V_2 ) ;
return 0 ;
}
static int F_204 ( struct V_31 * V_32 , struct V_3 * V_4 )
{
struct V_1 * V_2 = V_32 -> V_1 ;
struct V_285 * V_286 = NULL ;
struct V_113 * V_113 ;
struct V_287 * V_287 ;
int V_12 , V_27 ;
F_153 ( L_23 , V_197 ,
( unsigned long long ) V_32 -> V_206 . V_207 ,
( unsigned long long ) V_32 -> V_206 . V_208 ,
V_2 -> V_200 ) ;
V_27 = 0 ;
V_287 = F_205 ( V_129 ) ;
V_286 = F_126 ( sizeof( struct V_285 ) , V_129 ) ;
if ( V_287 == NULL || V_286 == NULL ) {
F_153 ( L_24 , V_197 ) ;
goto V_26;
}
V_113 = F_206 ( V_32 -> V_288 -> V_289 ) ;
V_27 = F_207 ( V_113 , V_286 , V_287 , V_4 ) ;
if ( V_27 ) {
F_153 ( L_25 ,
V_197 , V_27 ) ;
goto V_26;
}
V_27 = - V_290 ;
if ( ! ( V_286 -> V_291 . V_292 & V_293 ) ) {
F_153 ( L_26 ,
V_197 ) ;
goto V_26;
}
F_34 ( V_2 ) ;
V_12 = F_208 ( V_32 , V_286 ) ;
if ( V_12 != 0 ) {
F_153 ( L_27 ,
V_197 , V_12 ) ;
goto V_26;
}
V_27 = 0 ;
F_153 ( L_28 , V_197 ) ;
V_26:
if ( V_287 != NULL )
F_209 ( V_287 ) ;
F_75 ( V_286 ) ;
if ( V_27 ) {
F_155 ( L_29 ,
V_2 -> V_200 ) ;
F_5 ( V_204 , & V_32 -> V_205 ) ;
}
return V_27 ;
}
static int F_210 ( struct V_1 * V_2 )
{
const struct V_269 * V_233 =
V_2 -> V_144 -> V_270 ;
struct V_31 * V_32 ;
struct V_3 * V_4 ;
F_153 ( L_30 , V_197 ,
V_2 -> V_200 ) ;
F_15 ( & V_2 -> V_30 ) ;
V_4 = V_233 -> V_271 ( V_2 ) ;
F_16 ( & V_2 -> V_30 ) ;
if ( V_4 == NULL )
return - V_294 ;
V_2 -> V_295 ++ ;
V_241:
F_24 () ;
F_25 (server, &clp->cl_superblocks, client_link) {
int V_12 ;
if ( V_32 -> V_296 == V_2 -> V_295 )
continue;
V_32 -> V_296 = V_2 -> V_295 ;
if ( ! F_28 ( V_209 ,
& V_32 -> V_205 ) )
continue;
F_26 () ;
V_12 = F_204 ( V_32 , V_4 ) ;
if ( V_12 < 0 ) {
F_17 ( V_4 ) ;
return V_12 ;
}
goto V_241;
}
F_26 () ;
F_17 ( V_4 ) ;
return 0 ;
}
static int F_211 ( struct V_1 * V_2 )
{
const struct V_269 * V_233 =
V_2 -> V_144 -> V_270 ;
struct V_31 * V_32 ;
struct V_3 * V_4 ;
F_153 ( L_31 , V_197 ,
V_2 -> V_200 ) ;
F_15 ( & V_2 -> V_30 ) ;
V_4 = V_233 -> V_271 ( V_2 ) ;
F_16 ( & V_2 -> V_30 ) ;
if ( V_4 == NULL )
return - V_294 ;
V_2 -> V_295 ++ ;
V_241:
F_24 () ;
F_25 (server, &clp->cl_superblocks, client_link) {
struct V_113 * V_113 ;
int V_12 ;
if ( V_32 -> V_296 == V_2 -> V_295 )
continue;
V_32 -> V_296 = V_2 -> V_295 ;
F_26 () ;
V_113 = F_206 ( V_32 -> V_288 -> V_289 ) ;
V_12 = F_212 ( V_113 , V_4 ) ;
if ( V_12 != - V_183 )
goto V_241;
if ( F_204 ( V_32 , V_4 ) == - V_297 )
goto V_241;
goto V_26;
}
F_26 () ;
V_26:
F_17 ( V_4 ) ;
return 0 ;
}
int F_213 ( struct V_1 * V_2 ,
struct V_1 * * V_27 )
{
const struct V_232 * V_233 =
V_2 -> V_144 -> V_263 ;
struct V_298 * V_299 ;
struct V_3 * V_4 ;
int V_300 , V_12 ;
F_153 ( L_32 , V_197 , V_2 -> V_200 ) ;
V_299 = V_2 -> V_193 ;
V_300 = 0 ;
F_214 ( & V_301 ) ;
V_302:
V_12 = - V_158 ;
V_4 = F_48 ( V_2 ) ;
if ( V_4 == NULL )
goto V_303;
V_12 = V_233 -> V_304 ( V_2 , V_27 , V_4 ) ;
F_17 ( V_4 ) ;
switch ( V_12 ) {
case 0 :
break;
case - V_274 :
if ( V_299 -> V_305 )
break;
case - V_278 :
case - V_100 :
F_181 ( 1 ) ;
case - V_177 :
F_153 ( L_33 ,
V_197 , V_12 ) ;
goto V_302;
case - V_258 :
if ( V_300 ++ == 0 ) {
F_13 ( V_2 ) ;
goto V_302;
}
if ( V_299 -> V_306 -> V_307 == V_308 )
break;
case - V_276 :
case - V_309 :
if ( V_299 -> V_306 -> V_307 == V_308 ) {
V_12 = - V_277 ;
break;
}
V_299 = F_215 ( V_299 , V_308 ) ;
if ( F_148 ( V_299 ) ) {
V_12 = F_150 ( V_299 ) ;
break;
}
V_299 = F_216 ( & V_2 -> V_193 , V_299 ) ;
F_217 ( V_299 ) ;
V_299 = V_2 -> V_193 ;
goto V_302;
case - V_279 :
V_12 = - V_281 ;
break;
case - V_310 :
case - V_282 :
V_12 = - V_310 ;
break;
default:
F_218 ( L_34 ,
V_197 , V_12 ) ;
V_12 = - V_163 ;
}
V_303:
F_219 ( & V_301 ) ;
F_153 ( L_35 , V_197 , V_12 ) ;
return V_12 ;
}
void F_220 ( struct V_46 * V_311 , int V_78 )
{
struct V_1 * V_2 = V_311 -> V_2 ;
switch ( V_78 ) {
default:
F_5 ( V_64 , & V_2 -> V_18 ) ;
break;
case - V_251 :
F_5 ( V_65 , & V_2 -> V_18 ) ;
}
F_45 ( V_2 ) ;
}
void F_221 ( struct V_1 * V_2 )
{
F_5 ( V_199 , & V_2 -> V_18 ) ;
F_45 ( V_2 ) ;
}
static void F_222 ( struct V_1 * V_2 )
{
if ( F_144 ( V_198 , & V_2 -> V_18 ) == 0 ) {
F_5 ( V_70 , & V_2 -> V_18 ) ;
F_7 ( V_17 , & V_2 -> V_18 ) ;
F_194 ( V_2 ) ;
F_153 ( L_36 ,
V_197 , V_2 -> V_200 ) ;
F_45 ( V_2 ) ;
}
}
static void F_223 ( struct V_1 * V_2 )
{
if ( F_144 ( V_198 , & V_2 -> V_18 ) == 0 ) {
F_187 ( V_2 ) ;
F_153 ( L_37 , V_197 ,
V_2 -> V_200 ) ;
F_45 ( V_2 ) ;
}
}
static void F_224 ( struct V_1 * V_2 )
{
F_222 ( V_2 ) ;
F_153 ( L_38 , V_197 , V_2 -> V_200 ) ;
}
static void F_225 ( struct V_1 * V_2 )
{
F_194 ( V_2 ) ;
F_45 ( V_2 ) ;
F_153 ( L_38 , V_197 , V_2 -> V_200 ) ;
}
static void F_226 ( struct V_1 * V_2 )
{
F_201 ( V_2 ) ;
F_225 ( V_2 ) ;
F_153 ( L_39 , V_197 ,
V_2 -> V_200 ) ;
}
static void F_227 ( struct V_1 * V_2 )
{
F_5 ( V_64 , & V_2 -> V_18 ) ;
F_45 ( V_2 ) ;
F_153 ( L_40 , V_197 ,
V_2 -> V_200 ) ;
}
static void F_228 ( struct V_1 * V_2 )
{
if ( F_144 ( V_65 ,
& V_2 -> V_18 ) == 0 )
F_45 ( V_2 ) ;
}
void F_229 ( struct V_1 * V_2 , T_5 V_85 ,
bool V_312 )
{
if ( ! V_85 )
return;
F_153 ( L_41 ,
V_197 , V_2 -> V_200 , V_2 -> V_8 , V_85 ) ;
if ( V_312 )
goto V_313;
if ( V_85 & V_314 )
F_223 ( V_2 ) ;
if ( V_85 & ( V_315 ) )
F_224 ( V_2 ) ;
if ( V_85 & ( V_316 |
V_317 ) )
F_225 ( V_2 ) ;
if ( V_85 & V_318 )
F_156 ( V_2 ) ;
if ( V_85 & V_319 )
F_226 ( V_2 ) ;
V_313:
if ( V_85 & V_320 )
F_227 ( V_2 ) ;
else if ( V_85 & ( V_321 |
V_322 ) )
F_228 ( V_2 ) ;
}
static int F_230 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
int V_12 ;
if ( ! F_135 ( V_2 ) )
return 0 ;
F_34 ( V_2 ) ;
V_4 = F_48 ( V_2 ) ;
V_12 = F_231 ( V_2 -> V_48 , V_4 ) ;
switch ( V_12 ) {
case 0 :
case - V_248 :
case - V_265 :
break;
case - V_323 :
case - V_278 :
F_5 ( V_64 , & V_2 -> V_18 ) ;
V_12 = 0 ;
F_181 ( 1 ) ;
goto V_26;
default:
V_12 = F_196 ( V_2 , V_12 ) ;
goto V_26;
}
memset ( V_2 -> V_48 -> V_324 . V_325 , 0 , V_326 ) ;
V_12 = F_41 ( V_2 , V_4 ) ;
if ( V_12 ) {
F_153 ( L_42 ,
V_197 , V_12 , V_2 -> V_200 ) ;
V_12 = F_199 ( V_2 , V_12 ) ;
goto V_26;
}
F_38 ( V_2 ) ;
F_153 ( L_43 ,
V_197 , V_2 -> V_200 ) ;
V_26:
if ( V_4 )
F_17 ( V_4 ) ;
return V_12 ;
}
static int F_232 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
int V_55 ;
if ( ! F_135 ( V_2 ) )
return 0 ;
F_34 ( V_2 ) ;
V_4 = F_48 ( V_2 ) ;
V_55 = F_233 ( V_2 , V_4 ) ;
if ( V_4 )
F_17 ( V_4 ) ;
F_7 ( V_65 , & V_2 -> V_18 ) ;
switch ( V_55 ) {
case 0 :
F_153 ( L_44 ,
V_197 , V_2 -> V_200 ) ;
break;
case - V_278 :
F_181 ( 1 ) ;
F_5 ( V_65 , & V_2 -> V_18 ) ;
break;
default:
return F_196 ( V_2 , V_55 ) ;
}
return 0 ;
}
static int F_230 ( struct V_1 * V_2 ) { return 0 ; }
static int F_232 ( struct V_1 * V_2 )
{
return 0 ;
}
static void F_234 ( struct V_1 * V_2 )
{
int V_12 = 0 ;
const char * V_327 = L_45 , * V_328 = L_45 ;
do {
if ( F_3 ( V_70 , & V_2 -> V_18 ) ) {
V_327 = L_46 ;
V_12 = F_203 ( V_2 ) ;
if ( V_12 < 0 )
goto V_329;
continue;
}
if ( F_3 ( V_198 , & V_2 -> V_18 ) ) {
V_327 = L_47 ;
V_12 = F_202 ( V_2 ) ;
if ( V_12 < 0 )
goto V_329;
continue;
}
if ( F_28 ( V_64 , & V_2 -> V_18 ) ) {
V_327 = L_48 ;
V_12 = F_230 ( V_2 ) ;
if ( F_3 ( V_198 , & V_2 -> V_18 ) )
continue;
if ( V_12 < 0 )
goto V_329;
}
if ( F_28 ( V_65 ,
& V_2 -> V_18 ) ) {
V_327 = L_49 ;
V_12 = F_232 ( V_2 ) ;
if ( V_12 < 0 )
goto V_329;
continue;
}
if ( F_28 ( V_199 , & V_2 -> V_18 ) ) {
V_327 = L_50 ;
V_12 = F_198 ( V_2 ) ;
if ( V_12 < 0 )
goto V_329;
continue;
}
if ( F_28 ( V_210 , & V_2 -> V_18 ) ) {
V_327 = L_51 ;
V_12 = F_210 ( V_2 ) ;
if ( V_12 < 0 )
goto V_329;
}
if ( F_28 ( V_211 , & V_2 -> V_18 ) ) {
V_327 = L_52 ;
V_12 = F_211 ( V_2 ) ;
if ( V_12 < 0 )
goto V_329;
}
if ( F_3 ( V_222 , & V_2 -> V_18 ) ) {
V_327 = L_53 ;
V_12 = F_197 ( V_2 ,
V_2 -> V_144 -> V_263 ) ;
if ( V_12 == - V_100 )
continue;
if ( V_12 < 0 )
goto V_329;
F_193 ( V_2 ) ;
}
if ( F_28 ( V_330 , & V_2 -> V_18 ) ) {
V_327 = L_54 ;
F_235 ( V_2 ) ;
continue;
}
if ( F_28 ( V_224 , & V_2 -> V_18 ) ) {
V_327 = L_55 ;
V_12 = F_197 ( V_2 ,
V_2 -> V_144 -> V_331 ) ;
if ( V_12 == - V_100 )
continue;
if ( V_12 < 0 )
goto V_329;
}
F_30 ( V_2 ) ;
if ( F_28 ( V_332 , & V_2 -> V_18 ) ) {
F_236 ( V_2 ) ;
continue;
}
F_139 ( V_2 ) ;
if ( V_2 -> V_18 == 0 )
break;
if ( F_144 ( V_186 , & V_2 -> V_18 ) != 0 )
break;
} while ( F_237 ( & V_2 -> V_192 ) > 1 );
return;
V_329:
if ( strlen ( V_327 ) )
V_328 = L_56 ;
F_132 ( L_57
L_58 , V_328 , V_327 ,
V_2 -> V_200 , - V_12 ) ;
F_181 ( 1 ) ;
F_30 ( V_2 ) ;
F_139 ( V_2 ) ;
}
static int V_195 ( void * V_333 )
{
struct V_1 * V_2 = V_333 ;
F_238 ( V_334 ) ;
F_234 ( V_2 ) ;
F_47 ( V_2 ) ;
F_239 ( 0 ) ;
return 0 ;
}
