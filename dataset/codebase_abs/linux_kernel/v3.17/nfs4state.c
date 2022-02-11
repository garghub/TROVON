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
F_5 ( V_17 , & V_2 -> V_18 ) ;
return F_43 ( V_2 , V_27 , V_4 ) ;
}
struct V_3 * F_44 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
F_15 ( & V_2 -> V_30 ) ;
V_4 = F_11 ( V_2 ) ;
F_16 ( & V_2 -> V_30 ) ;
return V_4 ;
}
static struct V_33 *
F_45 ( struct V_31 * V_32 , struct V_3 * V_4 )
{
struct V_35 * * V_69 = & V_32 -> V_37 . V_35 ,
* V_70 = NULL ;
struct V_33 * V_34 ;
while ( * V_69 != NULL ) {
V_70 = * V_69 ;
V_34 = F_21 ( V_70 , struct V_33 , V_38 ) ;
if ( V_4 < V_34 -> V_40 )
V_69 = & V_70 -> V_71 ;
else if ( V_4 > V_34 -> V_40 )
V_69 = & V_70 -> V_72 ;
else {
if ( ! F_22 ( & V_34 -> V_73 ) )
F_46 ( & V_34 -> V_73 ) ;
F_47 ( & V_34 -> V_74 ) ;
return V_34 ;
}
}
return NULL ;
}
static struct V_33 *
F_48 ( struct V_33 * V_29 )
{
struct V_31 * V_32 = V_29 -> V_75 ;
struct V_35 * * V_69 = & V_32 -> V_37 . V_35 ,
* V_70 = NULL ;
struct V_33 * V_34 ;
int V_76 ;
while ( * V_69 != NULL ) {
V_70 = * V_69 ;
V_34 = F_21 ( V_70 , struct V_33 , V_38 ) ;
if ( V_29 -> V_40 < V_34 -> V_40 )
V_69 = & V_70 -> V_71 ;
else if ( V_29 -> V_40 > V_34 -> V_40 )
V_69 = & V_70 -> V_72 ;
else {
if ( ! F_22 ( & V_34 -> V_73 ) )
F_46 ( & V_34 -> V_73 ) ;
F_47 ( & V_34 -> V_74 ) ;
return V_34 ;
}
}
V_76 = F_49 ( & V_32 -> V_77 , & V_29 -> V_78 . V_79 ) ;
if ( V_76 )
return F_50 ( V_76 ) ;
F_51 ( & V_29 -> V_38 , V_70 , V_69 ) ;
F_52 ( & V_29 -> V_38 , & V_32 -> V_37 ) ;
return V_29 ;
}
static void
F_53 ( struct V_33 * V_34 )
{
struct V_31 * V_32 = V_34 -> V_75 ;
if ( ! F_54 ( & V_34 -> V_38 ) )
F_55 ( & V_34 -> V_38 , & V_32 -> V_37 ) ;
F_56 ( & V_32 -> V_77 , V_34 -> V_78 . V_79 ) ;
}
static void
F_57 ( struct V_80 * V_81 )
{
V_81 -> V_82 = F_58 () ;
V_81 -> V_83 = 0 ;
V_81 -> V_84 = 0 ;
F_59 ( & V_81 -> V_85 ) ;
F_60 ( & V_81 -> V_86 ) ;
F_61 ( & V_81 -> V_87 , L_1 ) ;
}
static void
F_62 ( struct V_80 * V_81 )
{
F_63 ( & V_81 -> V_87 ) ;
}
static struct V_33 *
F_64 ( struct V_31 * V_32 ,
struct V_3 * V_4 ,
T_1 V_88 )
{
struct V_33 * V_34 ;
V_34 = F_65 ( sizeof( * V_34 ) , V_88 ) ;
if ( ! V_34 )
return NULL ;
V_34 -> V_75 = V_32 ;
V_34 -> V_40 = F_12 ( V_4 ) ;
F_59 ( & V_34 -> V_89 ) ;
F_60 ( & V_34 -> V_39 ) ;
F_57 ( & V_34 -> V_78 ) ;
F_66 ( & V_34 -> V_74 , 1 ) ;
F_60 ( & V_34 -> V_73 ) ;
F_67 ( & V_34 -> V_90 ) ;
F_68 ( & V_34 -> V_91 ) ;
return V_34 ;
}
static void
F_69 ( struct V_33 * V_34 )
{
struct V_35 * V_35 = & V_34 -> V_38 ;
if ( ! F_54 ( V_35 ) ) {
struct V_31 * V_32 = V_34 -> V_75 ;
struct V_1 * V_2 = V_32 -> V_1 ;
F_15 ( & V_2 -> V_30 ) ;
if ( ! F_54 ( V_35 ) ) {
F_55 ( V_35 , & V_32 -> V_37 ) ;
F_70 ( V_35 ) ;
}
F_16 ( & V_2 -> V_30 ) ;
}
}
static void F_71 ( struct V_33 * V_34 )
{
F_62 ( & V_34 -> V_78 ) ;
F_17 ( V_34 -> V_40 ) ;
F_72 ( V_34 ) ;
}
static void F_73 ( struct V_31 * V_32 )
{
struct V_1 * V_2 = V_32 -> V_1 ;
struct V_33 * V_34 , * V_92 ;
unsigned long V_93 , V_94 ;
F_74 ( V_95 ) ;
F_15 ( & V_2 -> V_30 ) ;
V_94 = V_64 ;
V_93 = ( long ) V_94 - ( long ) V_2 -> V_60 ;
F_75 (sp, tmp, &server->state_owners_lru, so_lru) {
if ( F_76 ( V_34 -> V_96 , V_93 , V_94 ) )
break;
F_77 ( & V_34 -> V_73 , & V_95 ) ;
F_53 ( V_34 ) ;
}
F_16 ( & V_2 -> V_30 ) ;
F_75 (sp, tmp, &doomed, so_lru) {
F_78 ( & V_34 -> V_73 ) ;
F_71 ( V_34 ) ;
}
}
struct V_33 * F_79 ( struct V_31 * V_32 ,
struct V_3 * V_4 ,
T_1 V_88 )
{
struct V_1 * V_2 = V_32 -> V_1 ;
struct V_33 * V_34 , * V_29 ;
F_15 ( & V_2 -> V_30 ) ;
V_34 = F_45 ( V_32 , V_4 ) ;
F_16 ( & V_2 -> V_30 ) ;
if ( V_34 != NULL )
goto V_26;
V_29 = F_64 ( V_32 , V_4 , V_88 ) ;
if ( V_29 == NULL )
goto V_26;
do {
if ( F_80 ( & V_32 -> V_77 , V_88 ) == 0 )
break;
F_15 ( & V_2 -> V_30 ) ;
V_34 = F_48 ( V_29 ) ;
F_16 ( & V_2 -> V_30 ) ;
} while ( V_34 == F_50 ( - V_97 ) );
if ( V_34 != V_29 )
F_71 ( V_29 ) ;
V_26:
F_73 ( V_32 ) ;
return V_34 ;
}
void F_81 ( struct V_33 * V_34 )
{
struct V_31 * V_32 = V_34 -> V_75 ;
struct V_1 * V_2 = V_32 -> V_1 ;
if ( ! F_82 ( & V_34 -> V_74 , & V_2 -> V_30 ) )
return;
V_34 -> V_96 = V_64 ;
F_83 ( & V_34 -> V_73 , & V_32 -> V_98 ) ;
F_16 ( & V_2 -> V_30 ) ;
}
void F_84 ( struct V_31 * V_32 )
{
struct V_1 * V_2 = V_32 -> V_1 ;
struct V_33 * V_34 , * V_92 ;
F_74 ( V_95 ) ;
F_15 ( & V_2 -> V_30 ) ;
F_75 (sp, tmp, &server->state_owners_lru, so_lru) {
F_77 ( & V_34 -> V_73 , & V_95 ) ;
F_53 ( V_34 ) ;
}
F_16 ( & V_2 -> V_30 ) ;
F_75 (sp, tmp, &doomed, so_lru) {
F_78 ( & V_34 -> V_73 ) ;
F_71 ( V_34 ) ;
}
}
static struct V_99 *
F_85 ( void )
{
struct V_99 * V_100 ;
V_100 = F_65 ( sizeof( * V_100 ) , V_101 ) ;
if ( ! V_100 )
return NULL ;
F_66 ( & V_100 -> V_102 , 1 ) ;
F_60 ( & V_100 -> V_103 ) ;
F_59 ( & V_100 -> V_104 ) ;
F_86 ( & V_100 -> V_105 ) ;
return V_100 ;
}
void
F_87 ( struct V_99 * V_100 , T_2 V_106 )
{
if ( V_100 -> V_100 == V_106 )
return;
if ( ( V_106 & V_107 ) != ( V_100 -> V_100 & V_107 ) ) {
if ( V_106 & V_107 )
F_77 ( & V_100 -> V_108 , & V_100 -> V_109 -> V_39 ) ;
else
F_88 ( & V_100 -> V_108 , & V_100 -> V_109 -> V_39 ) ;
}
V_100 -> V_100 = V_106 ;
}
static struct V_99 *
F_89 ( struct V_110 * V_110 , struct V_33 * V_109 )
{
struct V_111 * V_112 = F_90 ( V_110 ) ;
struct V_99 * V_100 ;
F_91 (state, &nfsi->open_states, inode_states) {
if ( V_100 -> V_109 != V_109 )
continue;
if ( ! F_92 ( V_100 ) )
continue;
if ( F_93 ( & V_100 -> V_102 ) )
return V_100 ;
}
return NULL ;
}
static void
F_94 ( struct V_99 * V_100 )
{
F_72 ( V_100 ) ;
}
struct V_99 *
F_95 ( struct V_110 * V_110 , struct V_33 * V_109 )
{
struct V_99 * V_100 , * V_29 ;
struct V_111 * V_112 = F_90 ( V_110 ) ;
F_15 ( & V_110 -> V_113 ) ;
V_100 = F_89 ( V_110 , V_109 ) ;
F_16 ( & V_110 -> V_113 ) ;
if ( V_100 )
goto V_26;
V_29 = F_85 () ;
F_15 ( & V_109 -> V_89 ) ;
F_15 ( & V_110 -> V_113 ) ;
V_100 = F_89 ( V_110 , V_109 ) ;
if ( V_100 == NULL && V_29 != NULL ) {
V_100 = V_29 ;
V_100 -> V_109 = V_109 ;
F_47 ( & V_109 -> V_74 ) ;
F_96 ( & V_100 -> V_114 , & V_112 -> V_108 ) ;
F_97 ( V_110 ) ;
V_100 -> V_110 = V_110 ;
F_16 ( & V_110 -> V_113 ) ;
F_83 ( & V_100 -> V_108 , & V_109 -> V_39 ) ;
F_16 ( & V_109 -> V_89 ) ;
} else {
F_16 ( & V_110 -> V_113 ) ;
F_16 ( & V_109 -> V_89 ) ;
if ( V_29 )
F_94 ( V_29 ) ;
}
V_26:
return V_100 ;
}
void F_98 ( struct V_99 * V_100 )
{
struct V_110 * V_110 = V_100 -> V_110 ;
struct V_33 * V_109 = V_100 -> V_109 ;
if ( ! F_82 ( & V_100 -> V_102 , & V_109 -> V_89 ) )
return;
F_15 ( & V_110 -> V_113 ) ;
F_78 ( & V_100 -> V_114 ) ;
F_78 ( & V_100 -> V_108 ) ;
F_16 ( & V_110 -> V_113 ) ;
F_16 ( & V_109 -> V_89 ) ;
F_99 ( V_110 ) ;
F_94 ( V_100 ) ;
F_81 ( V_109 ) ;
}
static void F_100 ( struct V_99 * V_100 ,
T_2 V_106 , T_1 V_115 , int V_87 )
{
struct V_33 * V_109 = V_100 -> V_109 ;
int V_116 = 0 ;
T_2 V_117 ;
F_47 ( & V_109 -> V_74 ) ;
F_15 ( & V_109 -> V_89 ) ;
switch ( V_106 & ( V_118 | V_107 ) ) {
case V_118 :
V_100 -> V_119 -- ;
break;
case V_107 :
V_100 -> V_120 -- ;
break;
case V_118 | V_107 :
V_100 -> V_121 -- ;
}
V_117 = V_118 | V_107 ;
if ( V_100 -> V_121 == 0 ) {
if ( V_100 -> V_119 == 0 ) {
V_117 &= ~ V_118 ;
V_116 |= F_3 ( V_122 , & V_100 -> V_83 ) ;
V_116 |= F_3 ( V_123 , & V_100 -> V_83 ) ;
}
if ( V_100 -> V_120 == 0 ) {
V_117 &= ~ V_107 ;
V_116 |= F_3 ( V_124 , & V_100 -> V_83 ) ;
V_116 |= F_3 ( V_123 , & V_100 -> V_83 ) ;
}
if ( V_117 == 0 )
F_7 ( V_125 , & V_100 -> V_83 ) ;
}
F_87 ( V_100 , V_117 ) ;
F_16 ( & V_109 -> V_89 ) ;
if ( ! V_116 ) {
F_98 ( V_100 ) ;
F_81 ( V_109 ) ;
} else
F_101 ( V_100 , V_115 , V_87 ) ;
}
void F_102 ( struct V_99 * V_100 , T_2 V_106 )
{
F_100 ( V_100 , V_106 , V_101 , 0 ) ;
}
void F_103 ( struct V_99 * V_100 , T_2 V_106 )
{
F_100 ( V_100 , V_106 , V_126 , 1 ) ;
}
static struct V_127 *
F_104 ( struct V_99 * V_100 , T_3 V_128 )
{
struct V_127 * V_36 ;
F_91 (pos, &state->lock_states, ls_locks) {
if ( V_36 -> V_129 != V_128 )
continue;
F_47 ( & V_36 -> V_130 ) ;
return V_36 ;
}
return NULL ;
}
static struct V_127 * F_105 ( struct V_99 * V_100 , T_3 V_128 )
{
struct V_127 * V_131 ;
struct V_31 * V_32 = V_100 -> V_109 -> V_75 ;
V_131 = F_65 ( sizeof( * V_131 ) , V_101 ) ;
if ( V_131 == NULL )
return NULL ;
F_57 ( & V_131 -> V_132 ) ;
F_66 ( & V_131 -> V_130 , 1 ) ;
V_131 -> V_133 = V_100 ;
V_131 -> V_129 = V_128 ;
V_131 -> V_132 . V_79 = F_106 ( & V_32 -> V_134 , 0 , 0 , V_101 ) ;
if ( V_131 -> V_132 . V_79 < 0 )
goto V_135;
F_60 ( & V_131 -> V_136 ) ;
return V_131 ;
V_135:
F_72 ( V_131 ) ;
return NULL ;
}
void F_107 ( struct V_31 * V_32 , struct V_127 * V_131 )
{
F_108 ( & V_32 -> V_134 , V_131 -> V_132 . V_79 ) ;
F_62 ( & V_131 -> V_132 ) ;
F_72 ( V_131 ) ;
}
static struct V_127 * F_109 ( struct V_99 * V_100 , T_3 V_109 )
{
struct V_127 * V_131 , * V_29 = NULL ;
for(; ; ) {
F_15 ( & V_100 -> V_104 ) ;
V_131 = F_104 ( V_100 , V_109 ) ;
if ( V_131 != NULL )
break;
if ( V_29 != NULL ) {
F_96 ( & V_29 -> V_136 , & V_100 -> V_103 ) ;
F_5 ( V_137 , & V_100 -> V_83 ) ;
V_131 = V_29 ;
V_29 = NULL ;
break;
}
F_16 ( & V_100 -> V_104 ) ;
V_29 = F_105 ( V_100 , V_109 ) ;
if ( V_29 == NULL )
return NULL ;
}
F_16 ( & V_100 -> V_104 ) ;
if ( V_29 != NULL )
F_107 ( V_100 -> V_109 -> V_75 , V_29 ) ;
return V_131 ;
}
void F_110 ( struct V_127 * V_131 )
{
struct V_31 * V_32 ;
struct V_99 * V_100 ;
if ( V_131 == NULL )
return;
V_100 = V_131 -> V_133 ;
if ( ! F_82 ( & V_131 -> V_130 , & V_100 -> V_104 ) )
return;
F_78 ( & V_131 -> V_136 ) ;
if ( F_22 ( & V_100 -> V_103 ) )
F_7 ( V_137 , & V_100 -> V_83 ) ;
F_16 ( & V_100 -> V_104 ) ;
V_32 = V_100 -> V_109 -> V_75 ;
if ( F_3 ( V_138 , & V_131 -> V_139 ) ) {
struct V_1 * V_2 = V_32 -> V_1 ;
V_2 -> V_140 -> V_141 ( V_32 , V_131 ) ;
} else
F_107 ( V_32 , V_131 ) ;
}
static void F_111 ( struct V_142 * V_143 , struct V_142 * V_144 )
{
struct V_127 * V_131 = V_144 -> V_145 . V_146 . V_109 ;
V_143 -> V_145 . V_146 . V_109 = V_131 ;
F_47 ( & V_131 -> V_130 ) ;
}
static void F_112 ( struct V_142 * V_147 )
{
F_110 ( V_147 -> V_145 . V_146 . V_109 ) ;
}
int F_113 ( struct V_99 * V_100 , struct V_142 * V_147 )
{
struct V_127 * V_131 ;
if ( V_147 -> V_148 != NULL )
return 0 ;
V_131 = F_109 ( V_100 , V_147 -> V_128 ) ;
if ( V_131 == NULL )
return - V_149 ;
V_147 -> V_145 . V_146 . V_109 = V_131 ;
V_147 -> V_148 = & V_150 ;
return 0 ;
}
static int F_114 ( T_4 * V_143 ,
struct V_99 * V_100 ,
const struct V_151 * V_152 )
{
struct V_127 * V_131 ;
T_3 V_128 ;
int V_55 = - V_153 ;
if ( V_152 == NULL )
goto V_26;
if ( F_3 ( V_137 , & V_100 -> V_83 ) == 0 )
goto V_26;
V_128 = V_152 -> V_154 ;
F_15 ( & V_100 -> V_104 ) ;
V_131 = F_104 ( V_100 , V_128 ) ;
if ( V_131 && F_3 ( V_155 , & V_131 -> V_139 ) )
V_55 = - V_156 ;
else if ( V_131 != NULL && F_3 ( V_138 , & V_131 -> V_139 ) != 0 ) {
F_115 ( V_143 , & V_131 -> V_157 ) ;
V_55 = 0 ;
}
F_16 ( & V_100 -> V_104 ) ;
F_110 ( V_131 ) ;
V_26:
return V_55 ;
}
static void F_116 ( T_4 * V_143 , struct V_99 * V_100 )
{
const T_4 * V_144 ;
int V_158 ;
do {
V_144 = & V_159 ;
V_158 = F_117 ( & V_100 -> V_105 ) ;
if ( F_3 ( V_160 , & V_100 -> V_83 ) )
V_144 = & V_100 -> V_161 ;
F_115 ( V_143 , V_144 ) ;
} while ( F_118 ( & V_100 -> V_105 , V_158 ) );
}
int F_119 ( T_4 * V_143 , struct V_99 * V_100 ,
T_2 V_106 , const struct V_151 * V_152 )
{
int V_55 = F_114 ( V_143 , V_100 , V_152 ) ;
if ( V_55 == - V_156 )
goto V_26;
if ( F_120 ( V_143 , V_100 -> V_110 , V_106 ) ) {
V_55 = 0 ;
goto V_26;
}
if ( V_55 != - V_153 )
goto V_26;
F_116 ( V_143 , V_100 ) ;
V_55 = 0 ;
V_26:
if ( F_121 ( V_100 -> V_110 , V_162 ) )
V_143 -> V_163 = 0 ;
return V_55 ;
}
struct V_164 * F_122 ( struct V_80 * V_84 , T_1 V_115 )
{
struct V_164 * V_29 ;
V_29 = F_123 ( sizeof( * V_29 ) , V_115 ) ;
if ( V_29 != NULL ) {
V_29 -> V_165 = V_84 ;
F_60 ( & V_29 -> V_86 ) ;
V_29 -> V_166 = NULL ;
}
return V_29 ;
}
void F_124 ( struct V_164 * V_163 )
{
struct V_80 * V_165 ;
if ( F_22 ( & V_163 -> V_86 ) )
return;
V_165 = V_163 -> V_165 ;
F_15 ( & V_165 -> V_85 ) ;
F_46 ( & V_163 -> V_86 ) ;
if ( ! F_22 ( & V_165 -> V_86 ) ) {
struct V_164 * V_167 ;
V_167 = F_125 ( & V_165 -> V_86 ,
struct V_164 , V_86 ) ;
F_126 ( & V_165 -> V_87 , V_167 -> V_166 ) ;
}
F_16 ( & V_165 -> V_85 ) ;
}
void F_127 ( struct V_164 * V_163 )
{
F_124 ( V_163 ) ;
F_72 ( V_163 ) ;
}
static void F_128 ( int V_12 , struct V_164 * V_163 )
{
switch ( V_12 ) {
case 0 :
break;
case - V_168 :
if ( V_163 -> V_165 -> V_83 & V_169 )
return;
F_129 ( L_2
L_3
L_4 ,
V_163 -> V_165 ) ;
case - V_170 :
case - V_171 :
case - V_172 :
case - V_173 :
case - V_174 :
case - V_175 :
return;
} ;
V_163 -> V_165 -> V_84 ++ ;
}
void F_130 ( int V_12 , struct V_164 * V_163 )
{
struct V_33 * V_34 = F_131 ( V_163 -> V_165 ,
struct V_33 , V_78 ) ;
struct V_31 * V_32 = V_34 -> V_75 ;
if ( V_12 == - V_168 )
F_69 ( V_34 ) ;
if ( ! F_132 ( V_32 -> V_1 ) )
F_128 ( V_12 , V_163 ) ;
}
void F_133 ( int V_12 , struct V_164 * V_163 )
{
F_128 ( V_12 , V_163 ) ;
}
int F_134 ( struct V_164 * V_163 , struct V_176 * V_166 )
{
struct V_80 * V_165 = V_163 -> V_165 ;
int V_12 = 0 ;
F_15 ( & V_165 -> V_85 ) ;
V_163 -> V_166 = V_166 ;
if ( F_22 ( & V_163 -> V_86 ) )
F_83 ( & V_163 -> V_86 , & V_165 -> V_86 ) ;
if ( F_125 ( & V_165 -> V_86 , struct V_164 , V_86 ) == V_163 )
goto V_177;
F_135 ( & V_165 -> V_87 , V_166 , NULL ) ;
V_12 = - V_97 ;
V_177:
F_16 ( & V_165 -> V_85 ) ;
return V_12 ;
}
static void F_136 ( struct V_1 * V_2 )
{
F_137 () ;
F_7 ( V_178 , & V_2 -> V_18 ) ;
F_138 () ;
F_139 ( & V_2 -> V_18 , V_178 ) ;
F_140 ( & V_2 -> V_179 ) ;
}
void F_141 ( struct V_1 * V_2 )
{
struct V_180 * V_166 ;
char V_181 [ V_182 + sizeof( L_5 ) + 1 ] ;
if ( F_142 ( V_178 , & V_2 -> V_18 ) != 0 )
return;
F_143 ( V_183 ) ;
F_47 ( & V_2 -> V_184 ) ;
F_24 () ;
snprintf ( V_181 , sizeof( V_181 ) , L_6 ,
F_144 ( V_2 -> V_185 , V_186 ) ) ;
F_26 () ;
V_166 = F_145 ( V_187 , V_2 , L_7 , V_181 ) ;
if ( F_146 ( V_166 ) ) {
F_147 ( V_188 L_8 ,
V_189 , F_148 ( V_166 ) ) ;
F_136 ( V_2 ) ;
F_149 ( V_2 ) ;
F_150 ( V_183 ) ;
}
}
void F_151 ( struct V_1 * V_2 )
{
if ( ! V_2 )
return;
if ( ! F_3 ( V_190 , & V_2 -> V_18 ) )
F_5 ( V_191 , & V_2 -> V_18 ) ;
F_152 ( L_9 , V_189 ,
V_2 -> V_192 ) ;
F_141 ( V_2 ) ;
}
int F_153 ( const struct V_31 * V_32 )
{
struct V_1 * V_2 = V_32 -> V_1 ;
if ( V_32 -> V_193 != V_194 ) {
F_154 ( L_10 ,
V_2 -> V_192 ) ;
return - V_195 ;
}
if ( F_3 ( V_196 , & V_32 -> V_197 ) )
return - V_195 ;
F_152 ( L_11 ,
V_189 ,
( unsigned long long ) V_32 -> V_198 . V_199 ,
( unsigned long long ) V_32 -> V_198 . V_200 ,
V_2 -> V_192 ) ;
F_5 ( V_201 ,
& ( (struct V_31 * ) V_32 ) -> V_197 ) ;
F_5 ( V_202 , & V_2 -> V_18 ) ;
F_141 ( V_2 ) ;
return 0 ;
}
void F_155 ( struct V_1 * V_2 )
{
F_152 ( L_12 ,
V_189 , V_2 -> V_8 , V_2 -> V_192 ) ;
F_5 ( V_203 , & V_2 -> V_18 ) ;
F_141 ( V_2 ) ;
}
int F_156 ( struct V_1 * V_2 )
{
int V_204 ;
F_157 () ;
F_47 ( & V_2 -> V_184 ) ;
V_204 = F_158 ( & V_2 -> V_18 , V_178 ,
V_205 , V_206 ) ;
if ( V_204 )
goto V_26;
if ( V_2 -> V_207 < 0 )
V_204 = V_2 -> V_207 ;
V_26:
F_149 ( V_2 ) ;
return V_204 ;
}
int F_159 ( struct V_1 * V_2 )
{
unsigned int V_208 ;
int V_55 ;
for ( V_208 = V_209 ; V_208 != 0 ; V_208 -- ) {
V_55 = F_156 ( V_2 ) ;
if ( V_55 != 0 )
break;
if ( ! F_3 ( V_190 , & V_2 -> V_18 ) &&
! F_3 ( V_191 , & V_2 -> V_18 ) )
break;
F_141 ( V_2 ) ;
V_55 = - V_156 ;
}
return V_55 ;
}
static void F_160 ( struct V_1 * V_2 )
{
F_5 ( V_190 , & V_2 -> V_18 ) ;
F_161 ( V_2 ) ;
F_152 ( L_13 , V_189 ,
V_2 -> V_192 ) ;
}
void F_162 ( struct V_1 * V_2 )
{
F_160 ( V_2 ) ;
F_141 ( V_2 ) ;
}
static int F_163 ( struct V_1 * V_2 , struct V_99 * V_100 )
{
F_5 ( V_210 , & V_100 -> V_83 ) ;
if ( F_3 ( V_211 , & V_100 -> V_83 ) ) {
F_7 ( V_210 , & V_100 -> V_83 ) ;
return 0 ;
}
F_5 ( V_212 , & V_100 -> V_109 -> V_213 ) ;
F_5 ( V_214 , & V_2 -> V_18 ) ;
return 1 ;
}
int F_164 ( struct V_1 * V_2 , struct V_99 * V_100 )
{
F_5 ( V_211 , & V_100 -> V_83 ) ;
F_7 ( V_210 , & V_100 -> V_83 ) ;
F_5 ( V_215 , & V_100 -> V_109 -> V_213 ) ;
F_5 ( V_216 , & V_2 -> V_18 ) ;
return 1 ;
}
int F_165 ( const struct V_31 * V_32 , struct V_99 * V_100 )
{
struct V_1 * V_2 = V_32 -> V_1 ;
if ( ! F_92 ( V_100 ) )
return - V_217 ;
F_164 ( V_2 , V_100 ) ;
F_152 ( L_14 , V_189 ,
V_2 -> V_192 ) ;
F_141 ( V_2 ) ;
return 0 ;
}
void F_166 ( struct V_110 * V_110 ,
const T_4 * V_218 )
{
struct V_1 * V_2 = F_167 ( V_110 ) -> V_1 ;
struct V_111 * V_112 = F_90 ( V_110 ) ;
struct V_219 * V_220 ;
struct V_99 * V_100 ;
bool V_221 = false ;
F_15 ( & V_110 -> V_113 ) ;
F_91 (ctx, &nfsi->open_files, list) {
V_100 = V_220 -> V_100 ;
if ( V_100 == NULL )
continue;
if ( ! F_3 ( V_125 , & V_100 -> V_83 ) )
continue;
if ( ! F_168 ( & V_100 -> V_218 , V_218 ) )
continue;
F_164 ( V_2 , V_100 ) ;
V_221 = true ;
}
F_16 ( & V_110 -> V_113 ) ;
if ( V_221 )
F_141 ( V_2 ) ;
}
static void F_169 ( struct V_99 * V_100 )
{
struct V_110 * V_110 = V_100 -> V_110 ;
struct V_111 * V_112 = F_90 ( V_110 ) ;
struct V_219 * V_220 ;
F_15 ( & V_110 -> V_113 ) ;
F_91 (ctx, &nfsi->open_files, list) {
if ( V_220 -> V_100 != V_100 )
continue;
F_5 ( V_222 , & V_220 -> V_83 ) ;
}
F_16 ( & V_110 -> V_113 ) ;
}
static void F_170 ( struct V_99 * V_100 , int error )
{
F_5 ( V_223 , & V_100 -> V_83 ) ;
F_169 ( V_100 ) ;
}
static int F_171 ( struct V_99 * V_100 , const struct V_224 * V_225 )
{
struct V_110 * V_110 = V_100 -> V_110 ;
struct V_111 * V_112 = F_90 ( V_110 ) ;
struct V_142 * V_147 ;
int V_12 = 0 ;
if ( V_110 -> V_226 == NULL )
return 0 ;
F_172 ( & V_112 -> V_227 ) ;
F_15 ( & V_110 -> V_113 ) ;
for ( V_147 = V_110 -> V_226 ; V_147 != NULL ; V_147 = V_147 -> V_228 ) {
if ( ! ( V_147 -> V_229 & ( V_230 | V_231 ) ) )
continue;
if ( F_173 ( V_147 -> V_232 ) -> V_100 != V_100 )
continue;
F_16 ( & V_110 -> V_113 ) ;
V_12 = V_225 -> V_233 ( V_100 , V_147 ) ;
switch ( V_12 ) {
case 0 :
break;
case - V_234 :
case - V_235 :
case - V_171 :
case - V_172 :
case - V_236 :
case - V_237 :
case - V_170 :
case - V_238 :
case - V_239 :
case - V_240 :
case - V_241 :
goto V_26;
default:
F_147 ( V_188 L_15 ,
V_189 , V_12 ) ;
case - V_149 :
case - V_242 :
case - V_243 :
case - V_244 :
V_12 = 0 ;
}
F_15 ( & V_110 -> V_113 ) ;
}
F_16 ( & V_110 -> V_113 ) ;
V_26:
F_174 ( & V_112 -> V_227 ) ;
return V_12 ;
}
static int F_175 ( struct V_33 * V_34 , const struct V_224 * V_225 )
{
struct V_99 * V_100 ;
struct V_127 * V_85 ;
int V_12 = 0 ;
F_15 ( & V_34 -> V_89 ) ;
F_176 ( & V_34 -> V_90 ) ;
V_245:
F_91 (state, &sp->so_states, open_states) {
if ( ! F_28 ( V_225 -> V_246 , & V_100 -> V_83 ) )
continue;
if ( ! F_92 ( V_100 ) )
continue;
if ( V_100 -> V_100 == 0 )
continue;
F_47 ( & V_100 -> V_102 ) ;
F_16 ( & V_34 -> V_89 ) ;
V_12 = V_225 -> V_247 ( V_34 , V_100 ) ;
if ( V_12 >= 0 ) {
V_12 = F_171 ( V_100 , V_225 ) ;
if ( V_12 >= 0 ) {
if ( ! F_3 ( V_125 , & V_100 -> V_83 ) ) {
F_15 ( & V_100 -> V_104 ) ;
F_91 (lock, &state->lock_states, ls_locks) {
if ( ! F_3 ( V_138 , & V_85 -> V_139 ) )
F_129 ( L_16
L_17
L_18 , V_189 ) ;
}
F_16 ( & V_100 -> V_104 ) ;
}
F_98 ( V_100 ) ;
F_15 ( & V_34 -> V_89 ) ;
goto V_245;
}
}
switch ( V_12 ) {
default:
F_147 ( V_188 L_15 ,
V_189 , V_12 ) ;
case - V_153 :
case - V_149 :
case - V_234 :
F_170 ( V_100 , V_12 ) ;
break;
case - V_97 :
F_177 ( 1 ) ;
case - V_235 :
case - V_171 :
case - V_172 :
case - V_243 :
case - V_244 :
F_164 ( V_34 -> V_75 -> V_1 , V_100 ) ;
break;
case - V_236 :
case - V_237 :
F_164 ( V_34 -> V_75 -> V_1 , V_100 ) ;
case - V_170 :
case - V_238 :
case - V_239 :
case - V_240 :
case - V_241 :
goto V_248;
}
F_98 ( V_100 ) ;
F_15 ( & V_34 -> V_89 ) ;
goto V_245;
}
F_178 ( & V_34 -> V_90 ) ;
F_16 ( & V_34 -> V_89 ) ;
return 0 ;
V_248:
F_98 ( V_100 ) ;
F_15 ( & V_34 -> V_89 ) ;
F_178 ( & V_34 -> V_90 ) ;
F_16 ( & V_34 -> V_89 ) ;
return V_12 ;
}
static void F_179 ( struct V_99 * V_100 )
{
struct V_127 * V_85 ;
F_7 ( V_125 , & V_100 -> V_83 ) ;
F_7 ( V_122 , & V_100 -> V_83 ) ;
F_7 ( V_124 , & V_100 -> V_83 ) ;
F_7 ( V_123 , & V_100 -> V_83 ) ;
F_15 ( & V_100 -> V_104 ) ;
F_91 (lock, &state->lock_states, ls_locks) {
V_85 -> V_132 . V_83 = 0 ;
F_7 ( V_138 , & V_85 -> V_139 ) ;
}
F_16 ( & V_100 -> V_104 ) ;
}
static void F_180 ( struct V_31 * V_32 ,
int (* F_181)( struct V_1 * V_2 , struct V_99 * V_100 ) )
{
struct V_1 * V_2 = V_32 -> V_1 ;
struct V_33 * V_34 ;
struct V_35 * V_36 ;
struct V_99 * V_100 ;
F_15 ( & V_2 -> V_30 ) ;
for ( V_36 = F_19 ( & V_32 -> V_37 ) ;
V_36 != NULL ;
V_36 = F_20 ( V_36 ) ) {
V_34 = F_21 ( V_36 , struct V_33 , V_38 ) ;
V_34 -> V_78 . V_83 = 0 ;
F_15 ( & V_34 -> V_89 ) ;
F_91 (state, &sp->so_states, open_states) {
if ( F_181 ( V_2 , V_100 ) )
F_179 ( V_100 ) ;
}
F_16 ( & V_34 -> V_89 ) ;
}
F_16 ( & V_2 -> V_30 ) ;
}
static void F_182 ( struct V_1 * V_2 ,
int (* F_181)( struct V_1 * V_2 , struct V_99 * V_100 ) )
{
struct V_31 * V_32 ;
F_24 () ;
F_25 (server, &clp->cl_superblocks, client_link)
F_180 ( V_32 , F_181 ) ;
F_26 () ;
}
static void F_183 ( struct V_1 * V_2 )
{
F_184 ( V_2 ) ;
F_182 ( V_2 , F_163 ) ;
}
static void F_185 ( struct V_1 * V_2 ,
const struct V_224 * V_225 ,
struct V_3 * V_4 )
{
if ( V_225 -> V_249 )
( void ) V_225 -> V_249 ( V_2 , V_4 ) ;
}
static void F_186 ( struct V_31 * V_32 )
{
struct V_1 * V_2 = V_32 -> V_1 ;
struct V_33 * V_34 ;
struct V_35 * V_36 ;
struct V_99 * V_100 ;
F_15 ( & V_2 -> V_30 ) ;
for ( V_36 = F_19 ( & V_32 -> V_37 ) ;
V_36 != NULL ;
V_36 = F_20 ( V_36 ) ) {
V_34 = F_21 ( V_36 , struct V_33 , V_38 ) ;
F_15 ( & V_34 -> V_89 ) ;
F_91 (state, &sp->so_states, open_states) {
if ( ! F_28 ( V_210 ,
& V_100 -> V_83 ) )
continue;
F_164 ( V_2 , V_100 ) ;
}
F_16 ( & V_34 -> V_89 ) ;
}
F_16 ( & V_2 -> V_30 ) ;
}
static int F_187 ( struct V_1 * V_2 )
{
struct V_31 * V_32 ;
if ( ! F_28 ( V_214 , & V_2 -> V_18 ) )
return 0 ;
F_24 () ;
F_25 (server, &clp->cl_superblocks, client_link)
F_186 ( V_32 ) ;
F_26 () ;
F_188 ( V_2 ) ;
return 1 ;
}
static void F_189 ( struct V_1 * V_2 )
{
const struct V_224 * V_225 ;
struct V_3 * V_4 ;
if ( ! F_187 ( V_2 ) )
return;
V_225 = V_2 -> V_140 -> V_250 ;
V_4 = F_44 ( V_2 ) ;
F_185 ( V_2 , V_225 , V_4 ) ;
F_17 ( V_4 ) ;
}
static void F_190 ( struct V_1 * V_2 )
{
F_184 ( V_2 ) ;
F_188 ( V_2 ) ;
}
static void F_191 ( struct V_1 * V_2 )
{
F_190 ( V_2 ) ;
F_182 ( V_2 , F_164 ) ;
}
static int F_192 ( struct V_1 * V_2 , int error )
{
switch ( error ) {
case 0 :
break;
case - V_251 :
F_160 ( V_2 ) ;
break;
case - V_237 :
F_189 ( V_2 ) ;
break;
case - V_170 :
F_5 ( V_190 , & V_2 -> V_18 ) ;
F_187 ( V_2 ) ;
F_183 ( V_2 ) ;
break;
case - V_236 :
F_5 ( V_190 , & V_2 -> V_18 ) ;
F_191 ( V_2 ) ;
break;
case - V_238 :
case - V_239 :
case - V_240 :
case - V_252 :
case - V_253 :
case - V_254 :
F_5 ( V_65 , & V_2 -> V_18 ) ;
break;
case - V_241 :
F_5 ( V_66 , & V_2 -> V_18 ) ;
break;
default:
F_152 ( L_19 ,
V_189 , error , V_2 -> V_192 ) ;
return error ;
}
F_152 ( L_20 , V_189 , error ,
V_2 -> V_192 ) ;
return 0 ;
}
static int F_193 ( struct V_1 * V_2 , const struct V_224 * V_225 )
{
struct V_33 * V_34 ;
struct V_31 * V_32 ;
struct V_35 * V_36 ;
int V_12 = 0 ;
V_245:
F_24 () ;
F_25 (server, &clp->cl_superblocks, client_link) {
F_84 ( V_32 ) ;
F_15 ( & V_2 -> V_30 ) ;
for ( V_36 = F_19 ( & V_32 -> V_37 ) ;
V_36 != NULL ;
V_36 = F_20 ( V_36 ) ) {
V_34 = F_21 ( V_36 ,
struct V_33 , V_38 ) ;
if ( ! F_28 ( V_225 -> V_255 ,
& V_34 -> V_213 ) )
continue;
F_47 ( & V_34 -> V_74 ) ;
F_16 ( & V_2 -> V_30 ) ;
F_26 () ;
V_12 = F_175 ( V_34 , V_225 ) ;
if ( V_12 < 0 ) {
F_5 ( V_225 -> V_255 , & V_34 -> V_213 ) ;
F_81 ( V_34 ) ;
return F_192 ( V_2 , V_12 ) ;
}
F_81 ( V_34 ) ;
goto V_245;
}
F_16 ( & V_2 -> V_30 ) ;
}
F_26 () ;
return V_12 ;
}
static int F_194 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
const struct V_256 * V_225 =
V_2 -> V_140 -> V_257 ;
int V_12 ;
if ( F_3 ( V_190 , & V_2 -> V_18 ) )
return 0 ;
F_15 ( & V_2 -> V_30 ) ;
V_4 = V_225 -> V_258 ( V_2 ) ;
F_16 ( & V_2 -> V_30 ) ;
if ( V_4 == NULL ) {
V_4 = F_44 ( V_2 ) ;
V_12 = - V_259 ;
if ( V_4 == NULL )
goto V_26;
}
V_12 = V_225 -> V_260 ( V_2 , V_4 ) ;
F_17 ( V_4 ) ;
if ( V_12 == - V_261 ) {
F_5 ( V_191 , & V_2 -> V_18 ) ;
return 0 ;
}
V_26:
return F_192 ( V_2 , V_12 ) ;
}
static int F_195 ( struct V_1 * V_2 , int V_12 )
{
switch ( V_12 ) {
case - V_254 :
if ( F_142 ( V_262 , & V_2 -> V_18 ) )
return - V_263 ;
F_177 ( 1 ) ;
F_7 ( V_17 , & V_2 -> V_18 ) ;
break;
case - V_170 :
F_7 ( V_17 , & V_2 -> V_18 ) ;
F_187 ( V_2 ) ;
F_183 ( V_2 ) ;
break;
case - V_264 :
F_154 ( L_21 ,
V_2 -> V_192 ) ;
F_41 ( V_2 , - V_265 ) ;
F_7 ( V_17 , & V_2 -> V_18 ) ;
return - V_265 ;
case - V_266 :
case - V_267 :
case - V_261 :
case - V_97 :
F_177 ( 1 ) ;
break;
case - V_268 :
if ( V_2 -> V_207 == V_269 )
F_41 ( V_2 , - V_270 ) ;
F_152 ( L_22 ,
V_189 , - V_270 , V_2 -> V_192 ) ;
return - V_270 ;
case - V_271 :
default:
F_152 ( L_22 , V_189 ,
V_12 , V_2 -> V_192 ) ;
return V_12 ;
}
F_5 ( V_190 , & V_2 -> V_18 ) ;
F_152 ( L_20 , V_189 , V_12 ,
V_2 -> V_192 ) ;
return 0 ;
}
static int F_196 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
const struct V_224 * V_225 =
V_2 -> V_140 -> V_250 ;
int V_12 ;
V_4 = F_44 ( V_2 ) ;
if ( V_4 == NULL )
return - V_153 ;
V_12 = V_225 -> V_272 ( V_2 , V_4 ) ;
F_17 ( V_4 ) ;
if ( V_12 != 0 )
return V_12 ;
F_197 ( V_2 ) ;
return 0 ;
}
static int F_198 ( struct V_1 * V_2 )
{
int V_12 ;
V_12 = F_196 ( V_2 ) ;
if ( V_12 < 0 )
return F_195 ( V_2 , V_12 ) ;
if ( F_28 ( V_273 , & V_2 -> V_18 ) )
F_191 ( V_2 ) ;
if ( ! F_3 ( V_216 , & V_2 -> V_18 ) )
F_5 ( V_214 , & V_2 -> V_18 ) ;
F_7 ( V_191 , & V_2 -> V_18 ) ;
F_7 ( V_190 , & V_2 -> V_18 ) ;
return 0 ;
}
static int F_199 ( struct V_1 * V_2 )
{
int V_12 ;
V_12 = F_196 ( V_2 ) ;
if ( V_12 < 0 )
return F_195 ( V_2 , V_12 ) ;
F_7 ( V_262 , & V_2 -> V_18 ) ;
F_5 ( V_190 , & V_2 -> V_18 ) ;
F_191 ( V_2 ) ;
return 0 ;
}
static int F_200 ( struct V_31 * V_32 , struct V_3 * V_4 )
{
struct V_1 * V_2 = V_32 -> V_1 ;
struct V_274 * V_275 = NULL ;
struct V_110 * V_110 ;
struct V_276 * V_276 ;
int V_12 , V_27 ;
F_152 ( L_23 , V_189 ,
( unsigned long long ) V_32 -> V_198 . V_199 ,
( unsigned long long ) V_32 -> V_198 . V_200 ,
V_2 -> V_192 ) ;
V_27 = 0 ;
V_276 = F_201 ( V_126 ) ;
V_275 = F_123 ( sizeof( struct V_274 ) , V_126 ) ;
if ( V_276 == NULL || V_275 == NULL ) {
F_152 ( L_24 , V_189 ) ;
goto V_26;
}
V_110 = V_32 -> V_277 -> V_278 -> V_279 ;
V_27 = F_202 ( V_110 , V_275 , V_276 , V_4 ) ;
if ( V_27 ) {
F_152 ( L_25 ,
V_189 , V_27 ) ;
goto V_26;
}
V_27 = - V_280 ;
if ( ! ( V_275 -> V_281 . V_282 & V_283 ) ) {
F_152 ( L_26 ,
V_189 ) ;
goto V_26;
}
F_34 ( V_2 ) ;
V_12 = F_203 ( V_32 , V_275 ) ;
if ( V_12 != 0 ) {
F_152 ( L_27 ,
V_189 , V_12 ) ;
goto V_26;
}
V_27 = 0 ;
F_152 ( L_28 , V_189 ) ;
V_26:
if ( V_276 != NULL )
F_204 ( V_276 ) ;
F_72 ( V_275 ) ;
if ( V_27 ) {
F_154 ( L_29 ,
V_2 -> V_192 ) ;
F_5 ( V_196 , & V_32 -> V_197 ) ;
}
return V_27 ;
}
static int F_205 ( struct V_1 * V_2 )
{
const struct V_256 * V_225 =
V_2 -> V_140 -> V_257 ;
struct V_31 * V_32 ;
struct V_3 * V_4 ;
F_152 ( L_30 , V_189 ,
V_2 -> V_192 ) ;
F_15 ( & V_2 -> V_30 ) ;
V_4 = V_225 -> V_258 ( V_2 ) ;
F_16 ( & V_2 -> V_30 ) ;
if ( V_4 == NULL )
return - V_284 ;
V_2 -> V_285 ++ ;
V_245:
F_24 () ;
F_25 (server, &clp->cl_superblocks, client_link) {
int V_12 ;
if ( V_32 -> V_286 == V_2 -> V_285 )
continue;
V_32 -> V_286 = V_2 -> V_285 ;
if ( ! F_28 ( V_201 ,
& V_32 -> V_197 ) )
continue;
F_26 () ;
V_12 = F_200 ( V_32 , V_4 ) ;
if ( V_12 < 0 ) {
F_17 ( V_4 ) ;
return V_12 ;
}
goto V_245;
}
F_26 () ;
F_17 ( V_4 ) ;
return 0 ;
}
static int F_206 ( struct V_1 * V_2 )
{
const struct V_256 * V_225 =
V_2 -> V_140 -> V_257 ;
struct V_31 * V_32 ;
struct V_3 * V_4 ;
F_152 ( L_31 , V_189 ,
V_2 -> V_192 ) ;
F_15 ( & V_2 -> V_30 ) ;
V_4 = V_225 -> V_258 ( V_2 ) ;
F_16 ( & V_2 -> V_30 ) ;
if ( V_4 == NULL )
return - V_284 ;
V_2 -> V_285 ++ ;
V_245:
F_24 () ;
F_25 (server, &clp->cl_superblocks, client_link) {
struct V_110 * V_110 ;
int V_12 ;
if ( V_32 -> V_286 == V_2 -> V_285 )
continue;
V_32 -> V_286 = V_2 -> V_285 ;
F_26 () ;
V_110 = V_32 -> V_277 -> V_278 -> V_279 ;
V_12 = F_207 ( V_110 , V_4 ) ;
if ( V_12 != - V_287 )
goto V_245;
if ( F_200 ( V_32 , V_4 ) == - V_288 )
goto V_245;
goto V_26;
}
F_26 () ;
V_26:
F_17 ( V_4 ) ;
return 0 ;
}
int F_208 ( struct V_1 * V_2 ,
struct V_1 * * V_27 )
{
const struct V_224 * V_225 =
V_2 -> V_140 -> V_250 ;
struct V_289 * V_290 ;
struct V_3 * V_4 ;
int V_291 , V_12 ;
F_152 ( L_32 , V_189 , V_2 -> V_192 ) ;
V_290 = V_2 -> V_185 ;
V_291 = 0 ;
F_209 ( & V_292 ) ;
V_293:
V_12 = - V_153 ;
V_4 = F_44 ( V_2 ) ;
if ( V_4 == NULL )
goto V_294;
V_12 = V_225 -> V_295 ( V_2 , V_27 , V_4 ) ;
F_17 ( V_4 ) ;
switch ( V_12 ) {
case 0 :
break;
case - V_261 :
if ( V_290 -> V_296 )
break;
case - V_267 :
case - V_97 :
F_177 ( 1 ) ;
case - V_170 :
F_152 ( L_33 ,
V_189 , V_12 ) ;
goto V_293;
case - V_266 :
if ( V_291 ++ == 0 ) {
F_13 ( V_2 ) ;
goto V_293;
}
if ( V_290 -> V_297 -> V_298 == V_299 )
break;
case - V_264 :
case - V_300 :
if ( V_290 -> V_297 -> V_298 == V_299 ) {
V_12 = - V_265 ;
break;
}
V_290 = F_210 ( V_290 , V_299 ) ;
if ( F_146 ( V_290 ) ) {
V_12 = F_148 ( V_290 ) ;
break;
}
V_290 = F_211 ( & V_2 -> V_185 , V_290 ) ;
F_212 ( V_290 ) ;
V_290 = V_2 -> V_185 ;
goto V_293;
case - V_268 :
V_12 = - V_270 ;
break;
case - V_301 :
case - V_271 :
V_12 = - V_301 ;
break;
default:
F_213 ( L_34 ,
V_189 , V_12 ) ;
V_12 = - V_156 ;
}
V_294:
F_214 ( & V_292 ) ;
F_152 ( L_35 , V_189 , V_12 ) ;
return V_12 ;
}
void F_215 ( struct V_46 * V_302 , int V_76 )
{
struct V_1 * V_2 = V_302 -> V_2 ;
switch ( V_76 ) {
default:
F_5 ( V_65 , & V_2 -> V_18 ) ;
break;
case - V_241 :
F_5 ( V_66 , & V_2 -> V_18 ) ;
}
F_151 ( V_2 ) ;
}
static void F_216 ( struct V_1 * V_2 )
{
F_5 ( V_191 , & V_2 -> V_18 ) ;
F_141 ( V_2 ) ;
}
void F_217 ( struct V_1 * V_2 )
{
F_216 ( V_2 ) ;
}
void F_218 ( struct V_1 * V_2 )
{
F_216 ( V_2 ) ;
}
static void F_219 ( struct V_1 * V_2 )
{
if ( F_142 ( V_190 , & V_2 -> V_18 ) == 0 ) {
F_5 ( V_262 , & V_2 -> V_18 ) ;
F_7 ( V_17 , & V_2 -> V_18 ) ;
F_191 ( V_2 ) ;
F_152 ( L_36 ,
V_189 , V_2 -> V_192 ) ;
F_141 ( V_2 ) ;
}
}
static void F_220 ( struct V_1 * V_2 )
{
if ( F_142 ( V_190 , & V_2 -> V_18 ) == 0 ) {
F_183 ( V_2 ) ;
F_152 ( L_37 , V_189 ,
V_2 -> V_192 ) ;
F_141 ( V_2 ) ;
}
}
static void F_221 ( struct V_1 * V_2 )
{
F_219 ( V_2 ) ;
F_152 ( L_38 , V_189 , V_2 -> V_192 ) ;
}
static void F_222 ( struct V_1 * V_2 )
{
F_161 ( V_2 ) ;
F_152 ( L_39 , V_189 ,
V_2 -> V_192 ) ;
}
static void F_223 ( struct V_1 * V_2 )
{
F_161 ( V_2 ) ;
if ( F_142 ( V_65 , & V_2 -> V_18 ) == 0 )
F_141 ( V_2 ) ;
F_152 ( L_40 , V_189 ,
V_2 -> V_192 ) ;
}
static void F_224 ( struct V_1 * V_2 )
{
if ( F_142 ( V_66 ,
& V_2 -> V_18 ) == 0 )
F_141 ( V_2 ) ;
}
void F_225 ( struct V_1 * V_2 , T_5 V_83 )
{
if ( ! V_83 )
return;
F_152 ( L_41 ,
V_189 , V_2 -> V_192 , V_2 -> V_8 , V_83 ) ;
if ( V_83 & V_303 )
F_220 ( V_2 ) ;
if ( V_83 & ( V_304 |
V_305 |
V_306 ) )
F_221 ( V_2 ) ;
if ( V_83 & V_307 )
F_155 ( V_2 ) ;
if ( V_83 & V_308 )
F_222 ( V_2 ) ;
if ( V_83 & V_309 )
F_223 ( V_2 ) ;
else if ( V_83 & ( V_310 |
V_311 ) )
F_224 ( V_2 ) ;
}
static int F_226 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
int V_12 ;
if ( ! F_132 ( V_2 ) )
return 0 ;
F_34 ( V_2 ) ;
V_4 = F_44 ( V_2 ) ;
V_12 = F_227 ( V_2 -> V_48 , V_4 ) ;
switch ( V_12 ) {
case 0 :
case - V_238 :
case - V_252 :
break;
case - V_312 :
case - V_267 :
F_5 ( V_65 , & V_2 -> V_18 ) ;
V_12 = 0 ;
F_177 ( 1 ) ;
goto V_26;
default:
V_12 = F_192 ( V_2 , V_12 ) ;
goto V_26;
}
memset ( V_2 -> V_48 -> V_313 . V_314 , 0 , V_315 ) ;
V_12 = F_40 ( V_2 , V_4 ) ;
if ( V_12 ) {
F_152 ( L_42 ,
V_189 , V_12 , V_2 -> V_192 ) ;
V_12 = F_195 ( V_2 , V_12 ) ;
goto V_26;
}
F_37 ( V_2 ) ;
F_152 ( L_43 ,
V_189 , V_2 -> V_192 ) ;
V_26:
if ( V_4 )
F_17 ( V_4 ) ;
return V_12 ;
}
static int F_228 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
int V_55 ;
if ( ! F_132 ( V_2 ) )
return 0 ;
F_34 ( V_2 ) ;
V_4 = F_44 ( V_2 ) ;
V_55 = F_229 ( V_2 , V_4 ) ;
if ( V_4 )
F_17 ( V_4 ) ;
F_7 ( V_66 , & V_2 -> V_18 ) ;
switch ( V_55 ) {
case 0 :
F_152 ( L_44 ,
V_189 , V_2 -> V_192 ) ;
break;
case - V_267 :
F_177 ( 1 ) ;
F_5 ( V_66 , & V_2 -> V_18 ) ;
break;
default:
return F_192 ( V_2 , V_55 ) ;
}
return 0 ;
}
static int F_226 ( struct V_1 * V_2 ) { return 0 ; }
static int F_228 ( struct V_1 * V_2 )
{
return 0 ;
}
static void F_230 ( struct V_1 * V_2 )
{
int V_12 = 0 ;
const char * V_316 = L_45 , * V_317 = L_45 ;
do {
if ( F_3 ( V_262 , & V_2 -> V_18 ) ) {
V_316 = L_46 ;
V_12 = F_199 ( V_2 ) ;
if ( V_12 < 0 )
goto V_318;
continue;
}
if ( F_3 ( V_190 , & V_2 -> V_18 ) ) {
V_316 = L_47 ;
V_12 = F_198 ( V_2 ) ;
if ( V_12 < 0 )
goto V_318;
continue;
}
if ( F_28 ( V_65 , & V_2 -> V_18 ) ) {
V_316 = L_48 ;
V_12 = F_226 ( V_2 ) ;
if ( F_3 ( V_190 , & V_2 -> V_18 ) )
continue;
if ( V_12 < 0 )
goto V_318;
}
if ( F_28 ( V_66 ,
& V_2 -> V_18 ) ) {
V_316 = L_49 ;
V_12 = F_228 ( V_2 ) ;
if ( V_12 < 0 )
goto V_318;
continue;
}
if ( F_28 ( V_191 , & V_2 -> V_18 ) ) {
V_316 = L_50 ;
V_12 = F_194 ( V_2 ) ;
if ( V_12 < 0 )
goto V_318;
}
if ( F_28 ( V_202 , & V_2 -> V_18 ) ) {
V_316 = L_51 ;
V_12 = F_205 ( V_2 ) ;
if ( V_12 < 0 )
goto V_318;
}
if ( F_28 ( V_203 , & V_2 -> V_18 ) ) {
V_316 = L_52 ;
V_12 = F_206 ( V_2 ) ;
if ( V_12 < 0 )
goto V_318;
}
if ( F_3 ( V_214 , & V_2 -> V_18 ) ) {
V_316 = L_53 ;
V_12 = F_193 ( V_2 ,
V_2 -> V_140 -> V_250 ) ;
if ( F_3 ( V_190 , & V_2 -> V_18 ) ||
F_3 ( V_65 , & V_2 -> V_18 ) )
continue;
F_189 ( V_2 ) ;
if ( F_3 ( V_216 , & V_2 -> V_18 ) )
continue;
if ( V_12 < 0 )
goto V_318;
}
if ( F_28 ( V_216 , & V_2 -> V_18 ) ) {
V_316 = L_54 ;
V_12 = F_193 ( V_2 ,
V_2 -> V_140 -> V_319 ) ;
if ( F_3 ( V_190 , & V_2 -> V_18 ) ||
F_3 ( V_65 , & V_2 -> V_18 ) ||
F_3 ( V_214 , & V_2 -> V_18 ) )
continue;
if ( V_12 < 0 )
goto V_318;
}
F_30 ( V_2 ) ;
if ( F_28 ( V_320 , & V_2 -> V_18 ) ) {
F_231 ( V_2 ) ;
continue;
}
F_136 ( V_2 ) ;
if ( V_2 -> V_18 == 0 )
break;
if ( F_142 ( V_178 , & V_2 -> V_18 ) != 0 )
break;
} while ( F_232 ( & V_2 -> V_184 ) > 1 );
return;
V_318:
if ( strlen ( V_316 ) )
V_317 = L_55 ;
F_129 ( L_56
L_57 , V_317 , V_316 ,
V_2 -> V_192 , - V_12 ) ;
F_177 ( 1 ) ;
F_30 ( V_2 ) ;
F_136 ( V_2 ) ;
}
static int V_187 ( void * V_321 )
{
struct V_1 * V_2 = V_321 ;
F_233 ( V_322 ) ;
F_230 ( V_2 ) ;
F_149 ( V_2 ) ;
F_234 ( 0 ) ;
return 0 ;
}
