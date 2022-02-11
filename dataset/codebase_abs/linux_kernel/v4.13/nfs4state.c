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
if ( V_2 -> V_68 & V_69 ) {
if ( ! F_3 ( V_70 , & V_2 -> V_71 ) )
F_5 ( V_72 , & V_2 -> V_18 ) ;
else
F_5 ( V_17 , & V_2 -> V_18 ) ;
}
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
struct V_35 * * V_73 = & V_32 -> V_37 . V_35 ,
* V_74 = NULL ;
struct V_33 * V_34 ;
while ( * V_73 != NULL ) {
V_74 = * V_73 ;
V_34 = F_21 ( V_74 , struct V_33 , V_38 ) ;
if ( V_4 < V_34 -> V_40 )
V_73 = & V_74 -> V_75 ;
else if ( V_4 > V_34 -> V_40 )
V_73 = & V_74 -> V_76 ;
else {
if ( ! F_22 ( & V_34 -> V_77 ) )
F_50 ( & V_34 -> V_77 ) ;
F_51 ( & V_34 -> V_78 ) ;
return V_34 ;
}
}
return NULL ;
}
static struct V_33 *
F_52 ( struct V_33 * V_29 )
{
struct V_31 * V_32 = V_29 -> V_79 ;
struct V_35 * * V_73 = & V_32 -> V_37 . V_35 ,
* V_74 = NULL ;
struct V_33 * V_34 ;
int V_80 ;
while ( * V_73 != NULL ) {
V_74 = * V_73 ;
V_34 = F_21 ( V_74 , struct V_33 , V_38 ) ;
if ( V_29 -> V_40 < V_34 -> V_40 )
V_73 = & V_74 -> V_75 ;
else if ( V_29 -> V_40 > V_34 -> V_40 )
V_73 = & V_74 -> V_76 ;
else {
if ( ! F_22 ( & V_34 -> V_77 ) )
F_50 ( & V_34 -> V_77 ) ;
F_51 ( & V_34 -> V_78 ) ;
return V_34 ;
}
}
V_80 = F_53 ( & V_32 -> V_81 , & V_29 -> V_82 . V_83 ) ;
if ( V_80 )
return F_54 ( V_80 ) ;
F_55 ( & V_29 -> V_38 , V_74 , V_73 ) ;
F_56 ( & V_29 -> V_38 , & V_32 -> V_37 ) ;
return V_29 ;
}
static void
F_57 ( struct V_33 * V_34 )
{
struct V_31 * V_32 = V_34 -> V_79 ;
if ( ! F_58 ( & V_34 -> V_38 ) )
F_59 ( & V_34 -> V_38 , & V_32 -> V_37 ) ;
F_60 ( & V_32 -> V_81 , V_34 -> V_82 . V_83 ) ;
}
static void
F_61 ( struct V_84 * V_85 )
{
V_85 -> V_86 = F_62 () ;
V_85 -> V_87 = 0 ;
V_85 -> V_88 = 0 ;
F_63 ( & V_85 -> V_89 ) ;
F_64 ( & V_85 -> V_90 ) ;
F_65 ( & V_85 -> V_91 , L_1 ) ;
}
static void
F_66 ( struct V_84 * V_85 )
{
F_67 ( & V_85 -> V_91 ) ;
}
static struct V_33 *
F_68 ( struct V_31 * V_32 ,
struct V_3 * V_4 ,
T_1 V_92 )
{
struct V_33 * V_34 ;
V_34 = F_69 ( sizeof( * V_34 ) , V_92 ) ;
if ( ! V_34 )
return NULL ;
V_34 -> V_79 = V_32 ;
V_34 -> V_40 = F_12 ( V_4 ) ;
F_63 ( & V_34 -> V_93 ) ;
F_64 ( & V_34 -> V_39 ) ;
F_61 ( & V_34 -> V_82 ) ;
F_70 ( & V_34 -> V_78 , 1 ) ;
F_64 ( & V_34 -> V_77 ) ;
F_71 ( & V_34 -> V_94 ) ;
F_72 ( & V_34 -> V_95 ) ;
return V_34 ;
}
static void
F_73 ( struct V_33 * V_34 )
{
V_34 -> V_82 . V_86 = F_62 () ;
}
static void F_74 ( struct V_33 * V_34 )
{
F_66 ( & V_34 -> V_82 ) ;
F_17 ( V_34 -> V_40 ) ;
F_75 ( V_34 ) ;
}
static void F_76 ( struct V_31 * V_32 )
{
struct V_1 * V_2 = V_32 -> V_1 ;
struct V_33 * V_34 , * V_96 ;
unsigned long V_97 , V_98 ;
F_77 ( V_99 ) ;
F_15 ( & V_2 -> V_30 ) ;
V_98 = V_61 ;
V_97 = ( long ) V_98 - ( long ) V_2 -> V_100 ;
F_78 (sp, tmp, &server->state_owners_lru, so_lru) {
if ( F_79 ( V_34 -> V_101 , V_97 , V_98 ) )
break;
F_80 ( & V_34 -> V_77 , & V_99 ) ;
F_57 ( V_34 ) ;
}
F_16 ( & V_2 -> V_30 ) ;
F_78 (sp, tmp, &doomed, so_lru) {
F_81 ( & V_34 -> V_77 ) ;
F_74 ( V_34 ) ;
}
}
struct V_33 * F_82 ( struct V_31 * V_32 ,
struct V_3 * V_4 ,
T_1 V_92 )
{
struct V_1 * V_2 = V_32 -> V_1 ;
struct V_33 * V_34 , * V_29 ;
F_15 ( & V_2 -> V_30 ) ;
V_34 = F_49 ( V_32 , V_4 ) ;
F_16 ( & V_2 -> V_30 ) ;
if ( V_34 != NULL )
goto V_26;
V_29 = F_68 ( V_32 , V_4 , V_92 ) ;
if ( V_29 == NULL )
goto V_26;
do {
if ( F_83 ( & V_32 -> V_81 , V_92 ) == 0 )
break;
F_15 ( & V_2 -> V_30 ) ;
V_34 = F_52 ( V_29 ) ;
F_16 ( & V_2 -> V_30 ) ;
} while ( V_34 == F_54 ( - V_102 ) );
if ( V_34 != V_29 )
F_74 ( V_29 ) ;
V_26:
F_76 ( V_32 ) ;
return V_34 ;
}
void F_84 ( struct V_33 * V_34 )
{
struct V_31 * V_32 = V_34 -> V_79 ;
struct V_1 * V_2 = V_32 -> V_1 ;
if ( ! F_85 ( & V_34 -> V_78 , & V_2 -> V_30 ) )
return;
V_34 -> V_101 = V_61 ;
F_86 ( & V_34 -> V_77 , & V_32 -> V_103 ) ;
F_16 ( & V_2 -> V_30 ) ;
}
void F_87 ( struct V_31 * V_32 )
{
struct V_1 * V_2 = V_32 -> V_1 ;
struct V_33 * V_34 , * V_96 ;
F_77 ( V_99 ) ;
F_15 ( & V_2 -> V_30 ) ;
F_78 (sp, tmp, &server->state_owners_lru, so_lru) {
F_80 ( & V_34 -> V_77 , & V_99 ) ;
F_57 ( V_34 ) ;
}
F_16 ( & V_2 -> V_30 ) ;
F_78 (sp, tmp, &doomed, so_lru) {
F_81 ( & V_34 -> V_77 ) ;
F_74 ( V_34 ) ;
}
}
static struct V_104 *
F_88 ( void )
{
struct V_104 * V_105 ;
V_105 = F_69 ( sizeof( * V_105 ) , V_106 ) ;
if ( ! V_105 )
return NULL ;
F_70 ( & V_105 -> V_107 , 1 ) ;
F_64 ( & V_105 -> V_108 ) ;
F_63 ( & V_105 -> V_109 ) ;
F_89 ( & V_105 -> V_110 ) ;
return V_105 ;
}
void
F_90 ( struct V_104 * V_105 , T_2 V_111 )
{
if ( V_105 -> V_105 == V_111 )
return;
if ( ( V_111 & V_112 ) != ( V_105 -> V_105 & V_112 ) ) {
if ( V_111 & V_112 )
F_80 ( & V_105 -> V_113 , & V_105 -> V_114 -> V_39 ) ;
else
F_91 ( & V_105 -> V_113 , & V_105 -> V_114 -> V_39 ) ;
}
V_105 -> V_105 = V_111 ;
}
static struct V_104 *
F_92 ( struct V_115 * V_115 , struct V_33 * V_114 )
{
struct V_116 * V_117 = F_93 ( V_115 ) ;
struct V_104 * V_105 ;
F_94 (state, &nfsi->open_states, inode_states) {
if ( V_105 -> V_114 != V_114 )
continue;
if ( ! F_95 ( V_105 ) )
continue;
if ( F_96 ( & V_105 -> V_107 ) )
return V_105 ;
}
return NULL ;
}
static void
F_97 ( struct V_104 * V_105 )
{
F_75 ( V_105 ) ;
}
struct V_104 *
F_98 ( struct V_115 * V_115 , struct V_33 * V_114 )
{
struct V_104 * V_105 , * V_29 ;
struct V_116 * V_117 = F_93 ( V_115 ) ;
F_15 ( & V_115 -> V_118 ) ;
V_105 = F_92 ( V_115 , V_114 ) ;
F_16 ( & V_115 -> V_118 ) ;
if ( V_105 )
goto V_26;
V_29 = F_88 () ;
F_15 ( & V_114 -> V_93 ) ;
F_15 ( & V_115 -> V_118 ) ;
V_105 = F_92 ( V_115 , V_114 ) ;
if ( V_105 == NULL && V_29 != NULL ) {
V_105 = V_29 ;
V_105 -> V_114 = V_114 ;
F_51 ( & V_114 -> V_78 ) ;
F_99 ( & V_105 -> V_119 , & V_117 -> V_113 ) ;
F_100 ( V_115 ) ;
V_105 -> V_115 = V_115 ;
F_16 ( & V_115 -> V_118 ) ;
F_86 ( & V_105 -> V_113 , & V_114 -> V_39 ) ;
F_16 ( & V_114 -> V_93 ) ;
} else {
F_16 ( & V_115 -> V_118 ) ;
F_16 ( & V_114 -> V_93 ) ;
if ( V_29 )
F_97 ( V_29 ) ;
}
V_26:
return V_105 ;
}
void F_101 ( struct V_104 * V_105 )
{
struct V_115 * V_115 = V_105 -> V_115 ;
struct V_33 * V_114 = V_105 -> V_114 ;
if ( ! F_85 ( & V_105 -> V_107 , & V_114 -> V_93 ) )
return;
F_15 ( & V_115 -> V_118 ) ;
F_81 ( & V_105 -> V_119 ) ;
F_81 ( & V_105 -> V_113 ) ;
F_16 ( & V_115 -> V_118 ) ;
F_16 ( & V_114 -> V_93 ) ;
F_102 ( V_115 ) ;
F_97 ( V_105 ) ;
F_84 ( V_114 ) ;
}
static void F_103 ( struct V_104 * V_105 ,
T_2 V_111 , T_1 V_120 , int V_91 )
{
struct V_33 * V_114 = V_105 -> V_114 ;
int V_121 = 0 ;
T_2 V_122 ;
F_51 ( & V_114 -> V_78 ) ;
F_15 ( & V_114 -> V_93 ) ;
switch ( V_111 & ( V_123 | V_112 ) ) {
case V_123 :
V_105 -> V_124 -- ;
break;
case V_112 :
V_105 -> V_125 -- ;
break;
case V_123 | V_112 :
V_105 -> V_126 -- ;
}
V_122 = V_123 | V_112 ;
if ( V_105 -> V_126 == 0 ) {
if ( V_105 -> V_124 == 0 ) {
V_122 &= ~ V_123 ;
V_121 |= F_3 ( V_127 , & V_105 -> V_87 ) ;
V_121 |= F_3 ( V_128 , & V_105 -> V_87 ) ;
}
if ( V_105 -> V_125 == 0 ) {
V_122 &= ~ V_112 ;
V_121 |= F_3 ( V_129 , & V_105 -> V_87 ) ;
V_121 |= F_3 ( V_128 , & V_105 -> V_87 ) ;
}
if ( V_122 == 0 )
F_7 ( V_130 , & V_105 -> V_87 ) ;
}
F_90 ( V_105 , V_122 ) ;
F_16 ( & V_114 -> V_93 ) ;
if ( ! V_121 ) {
F_101 ( V_105 ) ;
F_84 ( V_114 ) ;
} else
F_104 ( V_105 , V_120 , V_91 ) ;
}
void F_105 ( struct V_104 * V_105 , T_2 V_111 )
{
F_103 ( V_105 , V_111 , V_106 , 0 ) ;
}
void F_106 ( struct V_104 * V_105 , T_2 V_111 )
{
F_103 ( V_105 , V_111 , V_131 , 1 ) ;
}
static struct V_132 *
F_107 ( struct V_104 * V_105 ,
T_3 V_133 , T_3 V_134 )
{
struct V_132 * V_36 , * V_55 = NULL ;
F_94 (pos, &state->lock_states, ls_locks) {
if ( V_36 -> V_135 == V_133 ) {
V_55 = V_36 ;
break;
}
if ( V_36 -> V_135 == V_134 )
V_55 = V_36 ;
}
if ( V_55 )
F_51 ( & V_55 -> V_136 ) ;
return V_55 ;
}
static struct V_132 * F_108 ( struct V_104 * V_105 , T_3 V_133 )
{
struct V_132 * V_137 ;
struct V_31 * V_32 = V_105 -> V_114 -> V_79 ;
V_137 = F_69 ( sizeof( * V_137 ) , V_106 ) ;
if ( V_137 == NULL )
return NULL ;
F_61 ( & V_137 -> V_138 ) ;
F_70 ( & V_137 -> V_136 , 1 ) ;
V_137 -> V_139 = V_105 ;
V_137 -> V_135 = V_133 ;
V_137 -> V_138 . V_83 = F_109 ( & V_32 -> V_140 , 0 , 0 , V_106 ) ;
if ( V_137 -> V_138 . V_83 < 0 )
goto V_141;
F_64 ( & V_137 -> V_142 ) ;
return V_137 ;
V_141:
F_75 ( V_137 ) ;
return NULL ;
}
void F_110 ( struct V_31 * V_32 , struct V_132 * V_137 )
{
F_111 ( & V_32 -> V_140 , V_137 -> V_138 . V_83 ) ;
F_66 ( & V_137 -> V_138 ) ;
F_75 ( V_137 ) ;
}
static struct V_132 * F_112 ( struct V_104 * V_105 , T_3 V_114 )
{
struct V_132 * V_137 , * V_29 = NULL ;
for(; ; ) {
F_15 ( & V_105 -> V_109 ) ;
V_137 = F_107 ( V_105 , V_114 , NULL ) ;
if ( V_137 != NULL )
break;
if ( V_29 != NULL ) {
F_99 ( & V_29 -> V_142 , & V_105 -> V_108 ) ;
F_5 ( V_143 , & V_105 -> V_87 ) ;
V_137 = V_29 ;
V_29 = NULL ;
break;
}
F_16 ( & V_105 -> V_109 ) ;
V_29 = F_108 ( V_105 , V_114 ) ;
if ( V_29 == NULL )
return NULL ;
}
F_16 ( & V_105 -> V_109 ) ;
if ( V_29 != NULL )
F_110 ( V_105 -> V_114 -> V_79 , V_29 ) ;
return V_137 ;
}
void F_113 ( struct V_132 * V_137 )
{
struct V_31 * V_32 ;
struct V_104 * V_105 ;
if ( V_137 == NULL )
return;
V_105 = V_137 -> V_139 ;
if ( ! F_85 ( & V_137 -> V_136 , & V_105 -> V_109 ) )
return;
F_81 ( & V_137 -> V_142 ) ;
if ( F_22 ( & V_105 -> V_108 ) )
F_7 ( V_143 , & V_105 -> V_87 ) ;
F_16 ( & V_105 -> V_109 ) ;
V_32 = V_105 -> V_114 -> V_79 ;
if ( F_3 ( V_144 , & V_137 -> V_145 ) ) {
struct V_1 * V_2 = V_32 -> V_1 ;
V_2 -> V_146 -> V_147 ( V_32 , V_137 ) ;
} else
F_110 ( V_32 , V_137 ) ;
}
static void F_114 ( struct V_148 * V_149 , struct V_148 * V_150 )
{
struct V_132 * V_137 = V_150 -> V_151 . V_152 . V_114 ;
V_149 -> V_151 . V_152 . V_114 = V_137 ;
F_51 ( & V_137 -> V_136 ) ;
}
static void F_115 ( struct V_148 * V_153 )
{
F_113 ( V_153 -> V_151 . V_152 . V_114 ) ;
}
int F_116 ( struct V_104 * V_105 , struct V_148 * V_153 )
{
struct V_132 * V_137 ;
if ( V_153 -> V_154 != NULL )
return 0 ;
V_137 = F_112 ( V_105 , V_153 -> V_133 ) ;
if ( V_137 == NULL )
return - V_155 ;
V_153 -> V_151 . V_152 . V_114 = V_137 ;
V_153 -> V_154 = & V_156 ;
return 0 ;
}
static int F_117 ( T_4 * V_149 ,
struct V_104 * V_105 ,
const struct V_157 * V_158 )
{
struct V_132 * V_137 ;
T_3 V_133 , V_159 ;
int V_55 = - V_160 ;
if ( V_158 == NULL )
goto V_26;
if ( F_3 ( V_143 , & V_105 -> V_87 ) == 0 )
goto V_26;
V_133 = V_158 -> V_161 ;
V_159 = V_158 -> V_162 -> V_163 ;
F_15 ( & V_105 -> V_109 ) ;
V_137 = F_107 ( V_105 , V_133 , V_159 ) ;
if ( V_137 && F_3 ( V_164 , & V_137 -> V_145 ) )
V_55 = - V_165 ;
else if ( V_137 != NULL && F_3 ( V_144 , & V_137 -> V_145 ) != 0 ) {
F_118 ( V_149 , & V_137 -> V_166 ) ;
V_55 = 0 ;
}
F_16 ( & V_105 -> V_109 ) ;
F_113 ( V_137 ) ;
V_26:
return V_55 ;
}
static void F_119 ( T_4 * V_149 , struct V_104 * V_105 )
{
const T_4 * V_150 ;
int V_167 ;
do {
V_150 = & V_168 ;
V_167 = F_120 ( & V_105 -> V_110 ) ;
if ( F_3 ( V_169 , & V_105 -> V_87 ) )
V_150 = & V_105 -> V_170 ;
F_118 ( V_149 , V_150 ) ;
} while ( F_121 ( & V_105 -> V_110 , V_167 ) );
}
int F_122 ( struct V_104 * V_105 ,
T_2 V_111 , const struct V_157 * V_158 ,
T_4 * V_149 , struct V_3 * * V_4 )
{
int V_55 ;
if ( ! F_95 ( V_105 ) )
return - V_165 ;
if ( V_4 != NULL )
* V_4 = NULL ;
V_55 = F_117 ( V_149 , V_105 , V_158 ) ;
if ( V_55 == - V_165 )
goto V_26;
if ( F_123 ( V_105 -> V_115 , V_111 , V_149 , V_4 ) ) {
V_55 = 0 ;
goto V_26;
}
if ( V_55 != - V_160 )
goto V_26;
F_119 ( V_149 , V_105 ) ;
V_55 = 0 ;
V_26:
if ( F_124 ( V_105 -> V_115 , V_171 ) )
V_149 -> V_172 = 0 ;
return V_55 ;
}
struct V_173 * F_125 ( struct V_84 * V_88 , T_1 V_120 )
{
struct V_173 * V_29 ;
V_29 = F_126 ( sizeof( * V_29 ) , V_120 ) ;
if ( V_29 == NULL )
return F_54 ( - V_155 ) ;
V_29 -> V_174 = V_88 ;
F_64 ( & V_29 -> V_90 ) ;
V_29 -> V_175 = NULL ;
return V_29 ;
}
void F_127 ( struct V_173 * V_172 )
{
struct V_84 * V_174 ;
if ( V_172 == NULL || F_22 ( & V_172 -> V_90 ) )
return;
V_174 = V_172 -> V_174 ;
F_15 ( & V_174 -> V_89 ) ;
F_50 ( & V_172 -> V_90 ) ;
if ( ! F_22 ( & V_174 -> V_90 ) ) {
struct V_173 * V_176 ;
V_176 = F_128 ( & V_174 -> V_90 ,
struct V_173 , V_90 ) ;
F_129 ( & V_174 -> V_91 , V_176 -> V_175 ) ;
}
F_16 ( & V_174 -> V_89 ) ;
}
void F_130 ( struct V_173 * V_172 )
{
F_127 ( V_172 ) ;
F_75 ( V_172 ) ;
}
static void F_131 ( int V_12 , struct V_173 * V_172 )
{
switch ( V_12 ) {
case 0 :
break;
case - V_177 :
if ( V_172 -> V_174 -> V_87 & V_178 )
return;
F_132 ( L_2
L_3
L_4 ,
V_172 -> V_174 ) ;
case - V_179 :
case - V_180 :
case - V_181 :
case - V_182 :
case - V_183 :
case - V_184 :
case - V_185 :
return;
} ;
V_172 -> V_174 -> V_88 ++ ;
}
void F_133 ( int V_12 , struct V_173 * V_172 )
{
struct V_33 * V_34 ;
if ( V_172 == NULL )
return;
V_34 = F_134 ( V_172 -> V_174 , struct V_33 , V_82 ) ;
if ( V_12 == - V_177 )
F_73 ( V_34 ) ;
if ( ! F_135 ( V_34 -> V_79 -> V_1 ) )
F_131 ( V_12 , V_172 ) ;
}
void F_136 ( int V_12 , struct V_173 * V_172 )
{
if ( V_172 != NULL )
F_131 ( V_12 , V_172 ) ;
}
int F_137 ( struct V_173 * V_172 , struct V_186 * V_175 )
{
struct V_84 * V_174 ;
int V_12 = 0 ;
if ( V_172 == NULL )
goto V_26;
V_174 = V_172 -> V_174 ;
F_15 ( & V_174 -> V_89 ) ;
V_172 -> V_175 = V_175 ;
if ( F_22 ( & V_172 -> V_90 ) )
F_86 ( & V_172 -> V_90 , & V_174 -> V_90 ) ;
if ( F_128 ( & V_174 -> V_90 , struct V_173 , V_90 ) == V_172 )
goto V_187;
F_138 ( & V_174 -> V_91 , V_175 , NULL ) ;
V_12 = - V_102 ;
V_187:
F_16 ( & V_174 -> V_89 ) ;
V_26:
return V_12 ;
}
static void F_139 ( struct V_1 * V_2 )
{
F_140 () ;
F_7 ( V_188 , & V_2 -> V_18 ) ;
F_141 () ;
F_142 ( & V_2 -> V_18 , V_188 ) ;
F_143 ( & V_2 -> V_189 ) ;
}
void F_45 ( struct V_1 * V_2 )
{
struct V_190 * V_175 ;
char V_191 [ V_192 + sizeof( L_5 ) + 1 ] ;
if ( F_144 ( V_188 , & V_2 -> V_18 ) != 0 )
return;
F_145 ( V_193 ) ;
F_51 ( & V_2 -> V_194 ) ;
F_24 () ;
snprintf ( V_191 , sizeof( V_191 ) , L_6 ,
F_146 ( V_2 -> V_195 , V_196 ) ) ;
F_26 () ;
V_175 = F_147 ( V_197 , V_2 , L_7 , V_191 ) ;
if ( F_148 ( V_175 ) ) {
F_149 ( V_198 L_8 ,
V_199 , F_150 ( V_175 ) ) ;
F_139 ( V_2 ) ;
F_47 ( V_2 ) ;
F_151 ( V_193 ) ;
}
}
void F_152 ( struct V_1 * V_2 )
{
if ( ! V_2 )
return;
if ( ! F_3 ( V_200 , & V_2 -> V_18 ) )
F_5 ( V_201 , & V_2 -> V_18 ) ;
F_153 ( L_9 , V_199 ,
V_2 -> V_202 ) ;
F_45 ( V_2 ) ;
}
int F_154 ( const struct V_31 * V_32 )
{
struct V_1 * V_2 = V_32 -> V_1 ;
if ( V_32 -> V_203 != V_204 ) {
F_155 ( L_10 ,
V_2 -> V_202 ) ;
return - V_205 ;
}
if ( F_3 ( V_206 , & V_32 -> V_207 ) )
return - V_205 ;
F_153 ( L_11 ,
V_199 ,
( unsigned long long ) V_32 -> V_208 . V_209 ,
( unsigned long long ) V_32 -> V_208 . V_210 ,
V_2 -> V_202 ) ;
F_5 ( V_211 ,
& ( (struct V_31 * ) V_32 ) -> V_207 ) ;
F_5 ( V_212 , & V_2 -> V_18 ) ;
F_45 ( V_2 ) ;
return 0 ;
}
void F_156 ( struct V_1 * V_2 )
{
F_153 ( L_12 ,
V_199 , V_2 -> V_8 , V_2 -> V_202 ) ;
F_5 ( V_213 , & V_2 -> V_18 ) ;
F_45 ( V_2 ) ;
}
int F_157 ( struct V_1 * V_2 )
{
int V_214 ;
F_158 () ;
F_51 ( & V_2 -> V_194 ) ;
V_214 = F_159 ( & V_2 -> V_18 , V_188 ,
V_215 , V_216 ) ;
if ( V_214 )
goto V_26;
if ( V_2 -> V_217 < 0 )
V_214 = V_2 -> V_217 ;
V_26:
F_47 ( V_2 ) ;
return V_214 ;
}
int F_160 ( struct V_1 * V_2 )
{
unsigned int V_218 ;
int V_55 ;
for ( V_218 = V_219 ; V_218 != 0 ; V_218 -- ) {
V_55 = F_157 ( V_2 ) ;
if ( V_55 != 0 )
break;
if ( ! F_3 ( V_200 , & V_2 -> V_18 ) &&
! F_3 ( V_201 , & V_2 -> V_18 ) )
break;
F_45 ( V_2 ) ;
V_55 = - V_165 ;
}
return V_55 ;
}
static void F_161 ( struct V_1 * V_2 )
{
F_5 ( V_200 , & V_2 -> V_18 ) ;
F_162 ( V_2 ) ;
F_153 ( L_13 , V_199 ,
V_2 -> V_202 ) ;
}
void F_163 ( struct V_1 * V_2 )
{
F_161 ( V_2 ) ;
F_45 ( V_2 ) ;
}
static int F_164 ( struct V_1 * V_2 , struct V_104 * V_105 )
{
if ( ! F_95 ( V_105 ) )
return 0 ;
F_5 ( V_220 , & V_105 -> V_87 ) ;
if ( F_3 ( V_221 , & V_105 -> V_87 ) ) {
F_7 ( V_220 , & V_105 -> V_87 ) ;
return 0 ;
}
F_5 ( V_222 , & V_105 -> V_114 -> V_223 ) ;
F_5 ( V_224 , & V_2 -> V_18 ) ;
return 1 ;
}
int F_165 ( struct V_1 * V_2 , struct V_104 * V_105 )
{
if ( ! F_95 ( V_105 ) )
return 0 ;
F_5 ( V_221 , & V_105 -> V_87 ) ;
F_7 ( V_220 , & V_105 -> V_87 ) ;
F_5 ( V_225 , & V_105 -> V_114 -> V_223 ) ;
F_5 ( V_226 , & V_2 -> V_18 ) ;
return 1 ;
}
int F_166 ( const struct V_31 * V_32 , struct V_104 * V_105 )
{
struct V_1 * V_2 = V_32 -> V_1 ;
if ( ! F_165 ( V_2 , V_105 ) )
return - V_227 ;
F_153 ( L_14 , V_199 ,
V_2 -> V_202 ) ;
F_45 ( V_2 ) ;
return 0 ;
}
static struct V_132 *
F_167 ( struct V_104 * V_105 ,
const T_4 * V_228 )
{
struct V_132 * V_36 ;
F_94 (pos, &state->lock_states, ls_locks) {
if ( ! F_3 ( V_144 , & V_36 -> V_145 ) )
continue;
if ( F_168 ( & V_36 -> V_166 , V_228 ) )
return V_36 ;
}
return NULL ;
}
static bool F_169 ( struct V_104 * V_105 ,
const T_4 * V_228 )
{
bool V_229 = false ;
if ( F_3 ( V_143 , & V_105 -> V_87 ) ) {
F_15 ( & V_105 -> V_109 ) ;
if ( F_167 ( V_105 , V_228 ) )
V_229 = true ;
F_16 ( & V_105 -> V_109 ) ;
}
return V_229 ;
}
void F_170 ( struct V_115 * V_115 ,
const T_4 * V_228 )
{
struct V_1 * V_2 = F_171 ( V_115 ) -> V_1 ;
struct V_116 * V_117 = F_93 ( V_115 ) ;
struct V_230 * V_231 ;
struct V_104 * V_105 ;
bool V_229 = false ;
F_15 ( & V_115 -> V_118 ) ;
F_94 (ctx, &nfsi->open_files, list) {
V_105 = V_231 -> V_105 ;
if ( V_105 == NULL )
continue;
if ( F_168 ( & V_105 -> V_228 , V_228 ) &&
F_165 ( V_2 , V_105 ) ) {
V_229 = true ;
continue;
}
if ( F_169 ( V_105 , V_228 ) &&
F_165 ( V_2 , V_105 ) )
V_229 = true ;
}
F_16 ( & V_115 -> V_118 ) ;
F_172 ( V_115 , V_228 ) ;
if ( V_229 )
F_45 ( V_2 ) ;
}
static void F_173 ( struct V_104 * V_105 )
{
struct V_115 * V_115 = V_105 -> V_115 ;
struct V_116 * V_117 = F_93 ( V_115 ) ;
struct V_230 * V_231 ;
F_15 ( & V_115 -> V_118 ) ;
F_94 (ctx, &nfsi->open_files, list) {
if ( V_231 -> V_105 != V_105 )
continue;
F_5 ( V_232 , & V_231 -> V_87 ) ;
}
F_16 ( & V_115 -> V_118 ) ;
}
static void F_174 ( struct V_104 * V_105 , int error )
{
F_5 ( V_233 , & V_105 -> V_87 ) ;
F_173 ( V_105 ) ;
}
static int F_175 ( struct V_104 * V_105 , const struct V_234 * V_235 )
{
struct V_115 * V_115 = V_105 -> V_115 ;
struct V_116 * V_117 = F_93 ( V_115 ) ;
struct V_148 * V_153 ;
int V_12 = 0 ;
struct V_236 * V_237 = V_115 -> V_238 ;
struct V_239 * V_90 ;
if ( V_237 == NULL )
return 0 ;
V_90 = & V_237 -> V_240 ;
F_176 ( & V_117 -> V_241 ) ;
F_15 ( & V_237 -> V_242 ) ;
V_243:
F_94 (fl, list, fl_list) {
if ( F_177 ( V_153 -> V_244 ) -> V_105 != V_105 )
continue;
F_16 ( & V_237 -> V_242 ) ;
V_12 = V_235 -> V_245 ( V_105 , V_153 ) ;
switch ( V_12 ) {
case 0 :
break;
case - V_246 :
case - V_247 :
case - V_180 :
case - V_181 :
case - V_248 :
case - V_249 :
case - V_179 :
case - V_250 :
case - V_251 :
case - V_252 :
case - V_253 :
goto V_26;
default:
F_155 ( L_15 ,
V_199 , V_12 ) ;
case - V_155 :
case - V_254 :
case - V_255 :
case - V_256 :
V_12 = 0 ;
}
F_15 ( & V_237 -> V_242 ) ;
}
if ( V_90 == & V_237 -> V_240 ) {
V_90 = & V_237 -> V_257 ;
goto V_243;
}
F_16 ( & V_237 -> V_242 ) ;
V_26:
F_178 ( & V_117 -> V_241 ) ;
return V_12 ;
}
static int F_179 ( struct V_33 * V_34 , const struct V_234 * V_235 )
{
struct V_104 * V_105 ;
struct V_132 * V_89 ;
int V_12 = 0 ;
F_15 ( & V_34 -> V_93 ) ;
F_180 ( & V_34 -> V_94 ) ;
V_243:
F_94 (state, &sp->so_states, open_states) {
if ( ! F_28 ( V_235 -> V_258 , & V_105 -> V_87 ) )
continue;
if ( ! F_95 ( V_105 ) )
continue;
if ( V_105 -> V_105 == 0 )
continue;
F_51 ( & V_105 -> V_107 ) ;
F_16 ( & V_34 -> V_93 ) ;
V_12 = V_235 -> V_259 ( V_34 , V_105 ) ;
if ( V_12 >= 0 ) {
V_12 = F_175 ( V_105 , V_235 ) ;
if ( V_12 >= 0 ) {
if ( ! F_3 ( V_130 , & V_105 -> V_87 ) ) {
F_15 ( & V_105 -> V_109 ) ;
F_94 (lock, &state->lock_states, ls_locks) {
if ( ! F_3 ( V_144 , & V_89 -> V_145 ) )
F_132 ( L_16
L_17
L_18 , V_199 ) ;
}
F_16 ( & V_105 -> V_109 ) ;
}
F_7 ( V_221 ,
& V_105 -> V_87 ) ;
F_101 ( V_105 ) ;
F_15 ( & V_34 -> V_93 ) ;
goto V_243;
}
}
switch ( V_12 ) {
default:
F_149 ( V_198 L_15 ,
V_199 , V_12 ) ;
case - V_160 :
case - V_155 :
case - V_260 :
case - V_261 :
case - V_165 :
case - V_246 :
F_174 ( V_105 , V_12 ) ;
break;
case - V_102 :
F_181 ( 1 ) ;
case - V_247 :
case - V_180 :
case - V_262 :
case - V_181 :
case - V_255 :
case - V_256 :
F_165 ( V_34 -> V_79 -> V_1 , V_105 ) ;
break;
case - V_248 :
case - V_249 :
F_165 ( V_34 -> V_79 -> V_1 , V_105 ) ;
case - V_179 :
case - V_250 :
case - V_251 :
case - V_252 :
case - V_253 :
goto V_263;
}
F_101 ( V_105 ) ;
F_15 ( & V_34 -> V_93 ) ;
goto V_243;
}
F_182 ( & V_34 -> V_94 ) ;
F_16 ( & V_34 -> V_93 ) ;
return 0 ;
V_263:
F_101 ( V_105 ) ;
F_15 ( & V_34 -> V_93 ) ;
F_182 ( & V_34 -> V_94 ) ;
F_16 ( & V_34 -> V_93 ) ;
return V_12 ;
}
static void F_183 ( struct V_104 * V_105 )
{
struct V_132 * V_89 ;
F_7 ( V_130 , & V_105 -> V_87 ) ;
F_7 ( V_127 , & V_105 -> V_87 ) ;
F_7 ( V_129 , & V_105 -> V_87 ) ;
F_7 ( V_128 , & V_105 -> V_87 ) ;
F_15 ( & V_105 -> V_109 ) ;
F_94 (lock, &state->lock_states, ls_locks) {
V_89 -> V_138 . V_87 = 0 ;
F_7 ( V_144 , & V_89 -> V_145 ) ;
}
F_16 ( & V_105 -> V_109 ) ;
}
static void F_184 ( struct V_31 * V_32 ,
int (* F_185)( struct V_1 * V_2 , struct V_104 * V_105 ) )
{
struct V_1 * V_2 = V_32 -> V_1 ;
struct V_33 * V_34 ;
struct V_35 * V_36 ;
struct V_104 * V_105 ;
F_15 ( & V_2 -> V_30 ) ;
for ( V_36 = F_19 ( & V_32 -> V_37 ) ;
V_36 != NULL ;
V_36 = F_20 ( V_36 ) ) {
V_34 = F_21 ( V_36 , struct V_33 , V_38 ) ;
V_34 -> V_82 . V_87 = 0 ;
F_15 ( & V_34 -> V_93 ) ;
F_94 (state, &sp->so_states, open_states) {
if ( F_185 ( V_2 , V_105 ) )
F_183 ( V_105 ) ;
}
F_16 ( & V_34 -> V_93 ) ;
}
F_16 ( & V_2 -> V_30 ) ;
}
static void F_186 ( struct V_1 * V_2 ,
int (* F_185)( struct V_1 * V_2 , struct V_104 * V_105 ) )
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
static int F_189 ( struct V_1 * V_2 ,
const struct V_234 * V_235 ,
struct V_3 * V_4 )
{
if ( V_235 -> V_264 )
return V_235 -> V_264 ( V_2 , V_4 ) ;
return 0 ;
}
static void F_190 ( struct V_31 * V_32 )
{
struct V_1 * V_2 = V_32 -> V_1 ;
struct V_33 * V_34 ;
struct V_35 * V_36 ;
struct V_104 * V_105 ;
F_15 ( & V_2 -> V_30 ) ;
for ( V_36 = F_19 ( & V_32 -> V_37 ) ;
V_36 != NULL ;
V_36 = F_20 ( V_36 ) ) {
V_34 = F_21 ( V_36 , struct V_33 , V_38 ) ;
F_15 ( & V_34 -> V_93 ) ;
F_94 (state, &sp->so_states, open_states) {
if ( ! F_28 ( V_220 ,
& V_105 -> V_87 ) )
continue;
F_165 ( V_2 , V_105 ) ;
}
F_16 ( & V_34 -> V_93 ) ;
}
F_16 ( & V_2 -> V_30 ) ;
}
static int F_191 ( struct V_1 * V_2 )
{
struct V_31 * V_32 ;
if ( ! F_28 ( V_224 , & V_2 -> V_18 ) )
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
const struct V_234 * V_235 ;
struct V_3 * V_4 ;
int V_80 ;
if ( ! F_191 ( V_2 ) )
return;
V_235 = V_2 -> V_146 -> V_265 ;
V_4 = F_48 ( V_2 ) ;
V_80 = F_189 ( V_2 , V_235 , V_4 ) ;
F_17 ( V_4 ) ;
if ( V_80 == - V_253 )
F_5 ( V_224 , & V_2 -> V_18 ) ;
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
case - V_266 :
F_161 ( V_2 ) ;
break;
case - V_249 :
F_193 ( V_2 ) ;
break;
case - V_179 :
F_5 ( V_200 , & V_2 -> V_18 ) ;
F_187 ( V_2 ) ;
break;
case - V_248 :
F_5 ( V_200 , & V_2 -> V_18 ) ;
F_194 ( V_2 ) ;
break;
case - V_250 :
case - V_251 :
case - V_252 :
case - V_267 :
case - V_268 :
case - V_269 :
F_5 ( V_64 , & V_2 -> V_18 ) ;
break;
case - V_253 :
F_5 ( V_65 , & V_2 -> V_18 ) ;
break;
default:
F_153 ( L_19 ,
V_199 , error , V_2 -> V_202 ) ;
return error ;
}
F_153 ( L_20 , V_199 , error ,
V_2 -> V_202 ) ;
return 0 ;
}
static int F_197 ( struct V_1 * V_2 , const struct V_234 * V_235 )
{
struct V_33 * V_34 ;
struct V_31 * V_32 ;
struct V_35 * V_36 ;
int V_12 = 0 ;
V_243:
F_24 () ;
F_25 (server, &clp->cl_superblocks, client_link) {
F_87 ( V_32 ) ;
F_15 ( & V_2 -> V_30 ) ;
for ( V_36 = F_19 ( & V_32 -> V_37 ) ;
V_36 != NULL ;
V_36 = F_20 ( V_36 ) ) {
V_34 = F_21 ( V_36 ,
struct V_33 , V_38 ) ;
if ( ! F_28 ( V_235 -> V_270 ,
& V_34 -> V_223 ) )
continue;
if ( ! F_96 ( & V_34 -> V_78 ) )
continue;
F_16 ( & V_2 -> V_30 ) ;
F_26 () ;
V_12 = F_179 ( V_34 , V_235 ) ;
if ( V_12 < 0 ) {
F_5 ( V_235 -> V_270 , & V_34 -> V_223 ) ;
F_84 ( V_34 ) ;
V_12 = F_196 ( V_2 , V_12 ) ;
return ( V_12 != 0 ) ? V_12 : - V_102 ;
}
F_84 ( V_34 ) ;
goto V_243;
}
F_16 ( & V_2 -> V_30 ) ;
}
F_26 () ;
return 0 ;
}
static int F_198 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
const struct V_271 * V_235 =
V_2 -> V_146 -> V_272 ;
int V_12 ;
if ( F_3 ( V_200 , & V_2 -> V_18 ) )
return 0 ;
F_15 ( & V_2 -> V_30 ) ;
V_4 = V_235 -> V_273 ( V_2 ) ;
F_16 ( & V_2 -> V_30 ) ;
if ( V_4 == NULL ) {
V_4 = F_48 ( V_2 ) ;
V_12 = - V_274 ;
if ( V_4 == NULL )
goto V_26;
}
V_12 = V_235 -> V_275 ( V_2 , V_4 ) ;
F_17 ( V_4 ) ;
if ( V_12 == - V_276 ) {
F_5 ( V_201 , & V_2 -> V_18 ) ;
return 0 ;
}
V_26:
return F_196 ( V_2 , V_12 ) ;
}
static int F_199 ( struct V_1 * V_2 , int V_12 )
{
switch ( V_12 ) {
case - V_269 :
if ( F_144 ( V_72 , & V_2 -> V_18 ) )
return - V_277 ;
F_181 ( 1 ) ;
F_7 ( V_17 , & V_2 -> V_18 ) ;
break;
case - V_179 :
F_7 ( V_17 , & V_2 -> V_18 ) ;
F_187 ( V_2 ) ;
break;
case - V_278 :
F_155 ( L_21 ,
V_2 -> V_202 ) ;
F_42 ( V_2 , - V_279 ) ;
F_7 ( V_17 , & V_2 -> V_18 ) ;
return - V_279 ;
case - V_260 :
case - V_280 :
case - V_276 :
case - V_102 :
F_181 ( 1 ) ;
break;
case - V_281 :
if ( V_2 -> V_217 == V_282 )
F_42 ( V_2 , - V_283 ) ;
F_153 ( L_22 ,
V_199 , - V_283 , V_2 -> V_202 ) ;
return - V_283 ;
case - V_284 :
default:
F_153 ( L_22 , V_199 ,
V_12 , V_2 -> V_202 ) ;
return V_12 ;
}
F_5 ( V_200 , & V_2 -> V_18 ) ;
F_153 ( L_20 , V_199 , V_12 ,
V_2 -> V_202 ) ;
return 0 ;
}
static int F_200 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
const struct V_234 * V_235 =
V_2 -> V_146 -> V_265 ;
int V_12 ;
F_34 ( V_2 ) ;
V_4 = F_48 ( V_2 ) ;
if ( V_4 == NULL )
return - V_160 ;
V_12 = V_235 -> V_285 ( V_2 , V_4 ) ;
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
if ( F_28 ( V_286 , & V_2 -> V_18 ) )
F_194 ( V_2 ) ;
if ( ! F_3 ( V_226 , & V_2 -> V_18 ) )
F_5 ( V_224 , & V_2 -> V_18 ) ;
F_7 ( V_201 , & V_2 -> V_18 ) ;
F_7 ( V_200 , & V_2 -> V_18 ) ;
return 0 ;
}
static int F_203 ( struct V_1 * V_2 )
{
int V_12 ;
V_12 = F_200 ( V_2 ) ;
if ( V_12 < 0 )
return F_199 ( V_2 , V_12 ) ;
F_7 ( V_72 , & V_2 -> V_18 ) ;
F_5 ( V_200 , & V_2 -> V_18 ) ;
F_194 ( V_2 ) ;
return 0 ;
}
static int F_204 ( struct V_31 * V_32 , struct V_3 * V_4 )
{
struct V_1 * V_2 = V_32 -> V_1 ;
struct V_287 * V_288 = NULL ;
struct V_115 * V_115 ;
struct V_289 * V_289 ;
int V_12 , V_27 ;
F_153 ( L_23 , V_199 ,
( unsigned long long ) V_32 -> V_208 . V_209 ,
( unsigned long long ) V_32 -> V_208 . V_210 ,
V_2 -> V_202 ) ;
V_27 = 0 ;
V_289 = F_205 ( V_131 ) ;
V_288 = F_126 ( sizeof( struct V_287 ) , V_131 ) ;
if ( V_289 == NULL || V_288 == NULL ) {
F_153 ( L_24 , V_199 ) ;
goto V_26;
}
V_115 = F_206 ( V_32 -> V_290 -> V_291 ) ;
V_27 = F_207 ( V_115 , V_288 , V_289 , V_4 ) ;
if ( V_27 ) {
F_153 ( L_25 ,
V_199 , V_27 ) ;
goto V_26;
}
V_27 = - V_292 ;
if ( ! ( V_288 -> V_293 . V_294 & V_295 ) ) {
F_153 ( L_26 ,
V_199 ) ;
goto V_26;
}
F_34 ( V_2 ) ;
V_12 = F_208 ( V_32 , V_288 ) ;
if ( V_12 != 0 ) {
F_153 ( L_27 ,
V_199 , V_12 ) ;
goto V_26;
}
V_27 = 0 ;
F_153 ( L_28 , V_199 ) ;
V_26:
if ( V_289 != NULL )
F_209 ( V_289 ) ;
F_75 ( V_288 ) ;
if ( V_27 ) {
F_155 ( L_29 ,
V_2 -> V_202 ) ;
F_5 ( V_206 , & V_32 -> V_207 ) ;
}
return V_27 ;
}
static int F_210 ( struct V_1 * V_2 )
{
const struct V_271 * V_235 =
V_2 -> V_146 -> V_272 ;
struct V_31 * V_32 ;
struct V_3 * V_4 ;
F_153 ( L_30 , V_199 ,
V_2 -> V_202 ) ;
F_15 ( & V_2 -> V_30 ) ;
V_4 = V_235 -> V_273 ( V_2 ) ;
F_16 ( & V_2 -> V_30 ) ;
if ( V_4 == NULL )
return - V_296 ;
V_2 -> V_297 ++ ;
V_243:
F_24 () ;
F_25 (server, &clp->cl_superblocks, client_link) {
int V_12 ;
if ( V_32 -> V_298 == V_2 -> V_297 )
continue;
V_32 -> V_298 = V_2 -> V_297 ;
if ( ! F_28 ( V_211 ,
& V_32 -> V_207 ) )
continue;
F_26 () ;
V_12 = F_204 ( V_32 , V_4 ) ;
if ( V_12 < 0 ) {
F_17 ( V_4 ) ;
return V_12 ;
}
goto V_243;
}
F_26 () ;
F_17 ( V_4 ) ;
return 0 ;
}
static int F_211 ( struct V_1 * V_2 )
{
const struct V_271 * V_235 =
V_2 -> V_146 -> V_272 ;
struct V_31 * V_32 ;
struct V_3 * V_4 ;
F_153 ( L_31 , V_199 ,
V_2 -> V_202 ) ;
F_15 ( & V_2 -> V_30 ) ;
V_4 = V_235 -> V_273 ( V_2 ) ;
F_16 ( & V_2 -> V_30 ) ;
if ( V_4 == NULL )
return - V_296 ;
V_2 -> V_297 ++ ;
V_243:
F_24 () ;
F_25 (server, &clp->cl_superblocks, client_link) {
struct V_115 * V_115 ;
int V_12 ;
if ( V_32 -> V_298 == V_2 -> V_297 )
continue;
V_32 -> V_298 = V_2 -> V_297 ;
F_26 () ;
V_115 = F_206 ( V_32 -> V_290 -> V_291 ) ;
V_12 = F_212 ( V_115 , V_4 ) ;
if ( V_12 != - V_185 )
goto V_243;
if ( F_204 ( V_32 , V_4 ) == - V_299 )
goto V_243;
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
const struct V_234 * V_235 =
V_2 -> V_146 -> V_265 ;
struct V_300 * V_301 ;
struct V_3 * V_4 ;
int V_302 , V_12 ;
F_153 ( L_32 , V_199 , V_2 -> V_202 ) ;
V_301 = V_2 -> V_195 ;
V_302 = 0 ;
F_214 ( & V_303 ) ;
V_304:
V_12 = - V_160 ;
V_4 = F_48 ( V_2 ) ;
if ( V_4 == NULL )
goto V_305;
V_12 = V_235 -> V_306 ( V_2 , V_27 , V_4 ) ;
F_17 ( V_4 ) ;
switch ( V_12 ) {
case 0 :
case - V_307 :
case - V_308 :
break;
case - V_276 :
if ( V_301 -> V_309 )
break;
case - V_280 :
case - V_102 :
F_181 ( 1 ) ;
case - V_179 :
F_153 ( L_33 ,
V_199 , V_12 ) ;
goto V_304;
case - V_260 :
if ( V_302 ++ == 0 ) {
F_13 ( V_2 ) ;
goto V_304;
}
if ( V_301 -> V_310 -> V_311 == V_312 )
break;
case - V_278 :
case - V_313 :
if ( V_301 -> V_310 -> V_311 == V_312 ) {
V_12 = - V_279 ;
break;
}
V_301 = F_215 ( V_301 , V_312 ) ;
if ( F_148 ( V_301 ) ) {
V_12 = F_150 ( V_301 ) ;
break;
}
V_301 = F_216 ( & V_2 -> V_195 , V_301 ) ;
F_217 ( V_301 ) ;
V_301 = V_2 -> V_195 ;
goto V_304;
case - V_281 :
V_12 = - V_283 ;
break;
case - V_314 :
case - V_284 :
V_12 = - V_314 ;
break;
default:
F_218 ( L_34 ,
V_199 , V_12 ) ;
V_12 = - V_165 ;
}
V_305:
F_219 ( & V_303 ) ;
F_153 ( L_35 , V_199 , V_12 ) ;
return V_12 ;
}
void F_220 ( struct V_46 * V_315 , int V_80 )
{
struct V_1 * V_2 = V_315 -> V_2 ;
switch ( V_80 ) {
default:
F_5 ( V_64 , & V_2 -> V_18 ) ;
break;
case - V_253 :
F_5 ( V_65 , & V_2 -> V_18 ) ;
}
F_45 ( V_2 ) ;
}
void F_221 ( struct V_1 * V_2 )
{
F_5 ( V_201 , & V_2 -> V_18 ) ;
F_45 ( V_2 ) ;
}
static void F_222 ( struct V_1 * V_2 )
{
if ( F_144 ( V_200 , & V_2 -> V_18 ) == 0 ) {
F_5 ( V_72 , & V_2 -> V_18 ) ;
F_7 ( V_17 , & V_2 -> V_18 ) ;
F_194 ( V_2 ) ;
F_153 ( L_36 ,
V_199 , V_2 -> V_202 ) ;
F_45 ( V_2 ) ;
}
}
static void F_223 ( struct V_1 * V_2 )
{
if ( F_144 ( V_200 , & V_2 -> V_18 ) == 0 ) {
F_187 ( V_2 ) ;
F_153 ( L_37 , V_199 ,
V_2 -> V_202 ) ;
F_45 ( V_2 ) ;
}
}
static void F_224 ( struct V_1 * V_2 )
{
F_222 ( V_2 ) ;
F_153 ( L_38 , V_199 , V_2 -> V_202 ) ;
}
static void F_225 ( struct V_1 * V_2 )
{
F_194 ( V_2 ) ;
F_45 ( V_2 ) ;
F_153 ( L_38 , V_199 , V_2 -> V_202 ) ;
}
static void F_226 ( struct V_1 * V_2 )
{
F_201 ( V_2 ) ;
F_225 ( V_2 ) ;
F_153 ( L_39 , V_199 ,
V_2 -> V_202 ) ;
}
static void F_227 ( struct V_1 * V_2 )
{
F_5 ( V_64 , & V_2 -> V_18 ) ;
F_45 ( V_2 ) ;
F_153 ( L_40 , V_199 ,
V_2 -> V_202 ) ;
}
static void F_228 ( struct V_1 * V_2 )
{
if ( F_144 ( V_65 ,
& V_2 -> V_18 ) == 0 )
F_45 ( V_2 ) ;
}
void F_229 ( struct V_1 * V_2 , T_5 V_87 ,
bool V_316 )
{
if ( ! V_87 )
return;
F_153 ( L_41 ,
V_199 , V_2 -> V_202 , V_2 -> V_8 , V_87 ) ;
if ( V_316 )
goto V_317;
if ( V_87 & V_318 )
F_223 ( V_2 ) ;
if ( V_87 & ( V_319 ) )
F_224 ( V_2 ) ;
if ( V_87 & ( V_320 |
V_321 ) )
F_225 ( V_2 ) ;
if ( V_87 & V_322 )
F_156 ( V_2 ) ;
if ( V_87 & V_323 )
F_226 ( V_2 ) ;
V_317:
if ( V_87 & V_324 )
F_227 ( V_2 ) ;
else if ( V_87 & ( V_325 |
V_326 ) )
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
case - V_250 :
case - V_267 :
break;
case - V_327 :
case - V_280 :
F_5 ( V_64 , & V_2 -> V_18 ) ;
V_12 = 0 ;
F_181 ( 1 ) ;
goto V_26;
default:
V_12 = F_196 ( V_2 , V_12 ) ;
goto V_26;
}
memset ( V_2 -> V_48 -> V_328 . V_329 , 0 , V_330 ) ;
V_12 = F_41 ( V_2 , V_4 ) ;
if ( V_12 ) {
F_153 ( L_42 ,
V_199 , V_12 , V_2 -> V_202 ) ;
V_12 = F_199 ( V_2 , V_12 ) ;
goto V_26;
}
F_38 ( V_2 ) ;
F_153 ( L_43 ,
V_199 , V_2 -> V_202 ) ;
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
V_199 , V_2 -> V_202 ) ;
break;
case - V_280 :
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
const char * V_331 = L_45 , * V_332 = L_45 ;
do {
if ( F_3 ( V_72 , & V_2 -> V_18 ) ) {
V_331 = L_46 ;
V_12 = F_203 ( V_2 ) ;
if ( V_12 < 0 )
goto V_333;
continue;
}
if ( F_3 ( V_200 , & V_2 -> V_18 ) ) {
V_331 = L_47 ;
V_12 = F_202 ( V_2 ) ;
if ( V_12 < 0 )
goto V_333;
continue;
}
if ( F_28 ( V_64 , & V_2 -> V_18 ) ) {
V_331 = L_48 ;
V_12 = F_230 ( V_2 ) ;
if ( F_3 ( V_200 , & V_2 -> V_18 ) )
continue;
if ( V_12 < 0 )
goto V_333;
}
if ( F_28 ( V_65 ,
& V_2 -> V_18 ) ) {
V_331 = L_49 ;
V_12 = F_232 ( V_2 ) ;
if ( V_12 < 0 )
goto V_333;
continue;
}
if ( F_28 ( V_201 , & V_2 -> V_18 ) ) {
V_331 = L_50 ;
V_12 = F_198 ( V_2 ) ;
if ( V_12 < 0 )
goto V_333;
continue;
}
if ( F_28 ( V_212 , & V_2 -> V_18 ) ) {
V_331 = L_51 ;
V_12 = F_210 ( V_2 ) ;
if ( V_12 < 0 )
goto V_333;
}
if ( F_28 ( V_213 , & V_2 -> V_18 ) ) {
V_331 = L_52 ;
V_12 = F_211 ( V_2 ) ;
if ( V_12 < 0 )
goto V_333;
}
if ( F_3 ( V_224 , & V_2 -> V_18 ) ) {
V_331 = L_53 ;
V_12 = F_197 ( V_2 ,
V_2 -> V_146 -> V_265 ) ;
if ( V_12 == - V_102 )
continue;
if ( V_12 < 0 )
goto V_333;
F_193 ( V_2 ) ;
}
if ( F_28 ( V_334 , & V_2 -> V_18 ) ) {
V_331 = L_54 ;
F_235 ( V_2 ) ;
continue;
}
if ( F_28 ( V_226 , & V_2 -> V_18 ) ) {
V_331 = L_55 ;
V_12 = F_197 ( V_2 ,
V_2 -> V_146 -> V_335 ) ;
if ( V_12 == - V_102 )
continue;
if ( V_12 < 0 )
goto V_333;
}
F_30 ( V_2 ) ;
if ( F_28 ( V_336 , & V_2 -> V_18 ) ) {
F_236 ( V_2 ) ;
continue;
}
F_139 ( V_2 ) ;
if ( V_2 -> V_18 == 0 )
break;
if ( F_144 ( V_188 , & V_2 -> V_18 ) != 0 )
break;
} while ( F_237 ( & V_2 -> V_194 ) > 1 );
return;
V_333:
if ( strlen ( V_331 ) )
V_332 = L_56 ;
F_132 ( L_57
L_58 , V_332 , V_331 ,
V_2 -> V_202 , - V_12 ) ;
F_181 ( 1 ) ;
F_30 ( V_2 ) ;
F_139 ( V_2 ) ;
}
static int V_197 ( void * V_337 )
{
struct V_1 * V_2 = V_337 ;
F_238 ( V_338 ) ;
F_234 ( V_2 ) ;
F_47 ( V_2 ) ;
F_239 ( 0 ) ;
return 0 ;
}
