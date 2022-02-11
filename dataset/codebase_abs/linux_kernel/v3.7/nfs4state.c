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
switch ( V_12 ) {
case - V_28 :
F_5 ( V_17 , & V_2 -> V_18 ) ;
case 0 :
F_8 ( * V_27 ) ;
break;
}
V_26:
return V_12 ;
}
struct V_3 * F_11 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = NULL ;
if ( V_2 -> V_29 != NULL )
V_4 = F_12 ( V_2 -> V_29 ) ;
return V_4 ;
}
static void F_13 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
F_14 ( & V_2 -> V_30 ) ;
V_4 = V_2 -> V_29 ;
V_2 -> V_29 = NULL ;
F_15 ( & V_2 -> V_30 ) ;
if ( V_4 != NULL )
F_16 ( V_4 ) ;
}
static struct V_3 *
F_17 ( struct V_31 * V_32 )
{
struct V_3 * V_4 = NULL ;
struct V_33 * V_34 ;
struct V_35 * V_36 ;
for ( V_36 = F_18 ( & V_32 -> V_37 ) ;
V_36 != NULL ;
V_36 = F_19 ( V_36 ) ) {
V_34 = F_20 ( V_36 , struct V_33 , V_38 ) ;
if ( F_21 ( & V_34 -> V_39 ) )
continue;
V_4 = F_12 ( V_34 -> V_40 ) ;
break;
}
return V_4 ;
}
struct V_3 * F_22 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = NULL ;
struct V_31 * V_32 ;
V_4 = F_11 ( V_2 ) ;
if ( V_4 != NULL )
goto V_26;
F_23 () ;
F_24 (server, &clp->cl_superblocks, client_link) {
V_4 = F_17 ( V_32 ) ;
if ( V_4 != NULL )
break;
}
F_25 () ;
V_26:
return V_4 ;
}
static int F_26 ( struct V_1 * V_2 )
{
int V_12 ;
struct V_41 V_42 ;
if ( ! F_3 ( V_43 , & V_2 -> V_44 ) ) {
F_8 ( V_2 ) ;
return 0 ;
}
V_12 = F_27 ( V_2 , & V_42 ) ;
if ( V_12 == 0 ) {
F_14 ( & V_2 -> V_30 ) ;
V_2 -> V_45 = V_42 . V_46 * V_47 ;
V_2 -> V_48 = V_49 ;
F_15 ( & V_2 -> V_30 ) ;
F_8 ( V_2 ) ;
}
return V_12 ;
}
static void F_28 ( struct V_1 * V_2 )
{
struct V_50 * V_51 = V_2 -> V_52 ;
struct V_53 * V_54 ;
int V_55 ;
if ( V_51 == NULL )
return;
V_54 = & V_51 -> V_56 ;
if ( F_29 ( V_57 , & V_51 -> V_58 ) ) {
F_14 ( & V_54 -> V_59 ) ;
V_55 = V_54 -> V_55 ;
while ( V_55 -- ) {
if ( F_30 ( & V_54 -> V_60 ,
V_61 ,
NULL ) == NULL )
break;
}
F_15 ( & V_54 -> V_59 ) ;
}
}
static int F_31 ( struct V_53 * V_54 )
{
F_14 ( & V_54 -> V_59 ) ;
if ( V_54 -> V_62 != V_63 ) {
F_32 ( V_54 -> V_64 ) ;
F_15 ( & V_54 -> V_59 ) ;
return F_33 ( & V_54 -> V_64 ) ;
}
F_15 ( & V_54 -> V_59 ) ;
return 0 ;
}
static int F_34 ( struct V_1 * V_2 )
{
struct V_50 * V_51 = V_2 -> V_52 ;
int V_65 = 0 ;
F_5 ( V_57 , & V_51 -> V_58 ) ;
V_65 = F_31 ( & V_51 -> V_66 ) ;
if ( V_65 )
return V_65 ;
return F_31 ( & V_51 -> V_56 ) ;
}
static void F_35 ( struct V_1 * V_2 )
{
F_7 ( V_17 , & V_2 -> V_18 ) ;
F_7 ( V_67 , & V_2 -> V_18 ) ;
F_7 ( V_68 , & V_2 -> V_18 ) ;
F_7 ( V_69 , & V_2 -> V_18 ) ;
F_26 ( V_2 ) ;
}
int F_36 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
int V_12 ;
if ( F_3 ( V_17 , & V_2 -> V_18 ) )
goto V_19;
F_34 ( V_2 ) ;
V_12 = F_37 ( V_2 , V_4 ) ;
if ( V_12 != 0 )
goto V_26;
F_5 ( V_17 , & V_2 -> V_18 ) ;
V_19:
V_12 = F_38 ( V_2 , V_4 ) ;
if ( V_12 != 0 )
goto V_26;
F_35 ( V_2 ) ;
F_39 ( V_2 , V_70 ) ;
V_26:
return V_12 ;
}
int F_40 ( struct V_1 * V_2 ,
struct V_1 * * V_27 ,
struct V_3 * V_4 )
{
int V_12 ;
V_12 = F_37 ( V_2 , V_4 ) ;
if ( V_12 != V_71 )
return V_12 ;
F_5 ( V_17 , & V_2 -> V_18 ) ;
return F_41 ( V_2 , V_27 , V_4 ) ;
}
struct V_3 * F_42 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
F_14 ( & V_2 -> V_30 ) ;
V_4 = F_11 ( V_2 ) ;
F_15 ( & V_2 -> V_30 ) ;
return V_4 ;
}
static struct V_3 *
F_43 ( struct V_31 * V_32 )
{
struct V_1 * V_2 = V_32 -> V_1 ;
struct V_3 * V_4 = NULL ;
struct V_33 * V_34 ;
struct V_35 * V_36 ;
F_14 ( & V_2 -> V_30 ) ;
V_36 = F_18 ( & V_32 -> V_37 ) ;
if ( V_36 != NULL ) {
V_34 = F_20 ( V_36 , struct V_33 , V_38 ) ;
V_4 = F_12 ( V_34 -> V_40 ) ;
}
F_15 ( & V_2 -> V_30 ) ;
return V_4 ;
}
struct V_3 * F_44 ( struct V_1 * V_2 )
{
struct V_31 * V_32 ;
struct V_3 * V_4 ;
F_14 ( & V_2 -> V_30 ) ;
V_4 = F_11 ( V_2 ) ;
F_15 ( & V_2 -> V_30 ) ;
if ( V_4 != NULL )
goto V_26;
F_23 () ;
F_24 (server, &clp->cl_superblocks, client_link) {
V_4 = F_43 ( V_32 ) ;
if ( V_4 != NULL )
break;
}
F_25 () ;
V_26:
return V_4 ;
}
static struct V_33 *
F_45 ( struct V_31 * V_32 , struct V_3 * V_4 )
{
struct V_35 * * V_72 = & V_32 -> V_37 . V_35 ,
* V_73 = NULL ;
struct V_33 * V_34 ;
while ( * V_72 != NULL ) {
V_73 = * V_72 ;
V_34 = F_20 ( V_73 , struct V_33 , V_38 ) ;
if ( V_4 < V_34 -> V_40 )
V_72 = & V_73 -> V_74 ;
else if ( V_4 > V_34 -> V_40 )
V_72 = & V_73 -> V_75 ;
else {
if ( ! F_21 ( & V_34 -> V_76 ) )
F_46 ( & V_34 -> V_76 ) ;
F_47 ( & V_34 -> V_77 ) ;
return V_34 ;
}
}
return NULL ;
}
static struct V_33 *
F_48 ( struct V_33 * V_78 )
{
struct V_31 * V_32 = V_78 -> V_79 ;
struct V_35 * * V_72 = & V_32 -> V_37 . V_35 ,
* V_73 = NULL ;
struct V_33 * V_34 ;
int V_80 ;
while ( * V_72 != NULL ) {
V_73 = * V_72 ;
V_34 = F_20 ( V_73 , struct V_33 , V_38 ) ;
if ( V_78 -> V_40 < V_34 -> V_40 )
V_72 = & V_73 -> V_74 ;
else if ( V_78 -> V_40 > V_34 -> V_40 )
V_72 = & V_73 -> V_75 ;
else {
if ( ! F_21 ( & V_34 -> V_76 ) )
F_46 ( & V_34 -> V_76 ) ;
F_47 ( & V_34 -> V_77 ) ;
return V_34 ;
}
}
V_80 = F_49 ( & V_32 -> V_81 , & V_78 -> V_82 . V_83 ) ;
if ( V_80 )
return F_50 ( V_80 ) ;
F_51 ( & V_78 -> V_38 , V_73 , V_72 ) ;
F_52 ( & V_78 -> V_38 , & V_32 -> V_37 ) ;
return V_78 ;
}
static void
F_53 ( struct V_33 * V_34 )
{
struct V_31 * V_32 = V_34 -> V_79 ;
if ( ! F_54 ( & V_34 -> V_38 ) )
F_55 ( & V_34 -> V_38 , & V_32 -> V_37 ) ;
F_56 ( & V_32 -> V_81 , V_34 -> V_82 . V_83 ) ;
}
static void
F_57 ( struct V_84 * V_85 )
{
V_85 -> V_86 = F_58 () ;
V_85 -> V_87 = 0 ;
V_85 -> V_88 = 0 ;
F_59 ( & V_85 -> V_89 ) ;
F_60 ( & V_85 -> V_90 ) ;
F_61 ( & V_85 -> V_91 , L_1 ) ;
}
static void
F_62 ( struct V_84 * V_85 )
{
F_63 ( & V_85 -> V_91 ) ;
}
static struct V_33 *
F_64 ( struct V_31 * V_32 ,
struct V_3 * V_4 ,
T_1 V_92 )
{
struct V_33 * V_34 ;
V_34 = F_65 ( sizeof( * V_34 ) , V_92 ) ;
if ( ! V_34 )
return NULL ;
V_34 -> V_79 = V_32 ;
V_34 -> V_40 = F_12 ( V_4 ) ;
F_59 ( & V_34 -> V_93 ) ;
F_60 ( & V_34 -> V_39 ) ;
F_57 ( & V_34 -> V_82 ) ;
F_66 ( & V_34 -> V_77 , 1 ) ;
F_60 ( & V_34 -> V_76 ) ;
return V_34 ;
}
static void
F_67 ( struct V_33 * V_34 )
{
struct V_35 * V_35 = & V_34 -> V_38 ;
if ( ! F_54 ( V_35 ) ) {
struct V_31 * V_32 = V_34 -> V_79 ;
struct V_1 * V_2 = V_32 -> V_1 ;
F_14 ( & V_2 -> V_30 ) ;
if ( ! F_54 ( V_35 ) ) {
F_55 ( V_35 , & V_32 -> V_37 ) ;
F_68 ( V_35 ) ;
}
F_15 ( & V_2 -> V_30 ) ;
}
}
static void F_69 ( struct V_33 * V_34 )
{
F_62 ( & V_34 -> V_82 ) ;
F_16 ( V_34 -> V_40 ) ;
F_70 ( V_34 ) ;
}
static void F_71 ( struct V_31 * V_32 )
{
struct V_1 * V_2 = V_32 -> V_1 ;
struct V_33 * V_34 , * V_94 ;
unsigned long V_95 , V_96 ;
F_72 ( V_97 ) ;
F_14 ( & V_2 -> V_30 ) ;
V_96 = V_49 ;
V_95 = ( long ) V_96 - ( long ) V_2 -> V_45 ;
F_73 (sp, tmp, &server->state_owners_lru, so_lru) {
if ( F_74 ( V_34 -> V_98 , V_95 , V_96 ) )
break;
F_75 ( & V_34 -> V_76 , & V_97 ) ;
F_53 ( V_34 ) ;
}
F_15 ( & V_2 -> V_30 ) ;
F_73 (sp, tmp, &doomed, so_lru) {
F_76 ( & V_34 -> V_76 ) ;
F_69 ( V_34 ) ;
}
}
struct V_33 * F_77 ( struct V_31 * V_32 ,
struct V_3 * V_4 ,
T_1 V_92 )
{
struct V_1 * V_2 = V_32 -> V_1 ;
struct V_33 * V_34 , * V_78 ;
F_14 ( & V_2 -> V_30 ) ;
V_34 = F_45 ( V_32 , V_4 ) ;
F_15 ( & V_2 -> V_30 ) ;
if ( V_34 != NULL )
goto V_26;
V_78 = F_64 ( V_32 , V_4 , V_92 ) ;
if ( V_78 == NULL )
goto V_26;
do {
if ( F_78 ( & V_32 -> V_81 , V_92 ) == 0 )
break;
F_14 ( & V_2 -> V_30 ) ;
V_34 = F_48 ( V_78 ) ;
F_15 ( & V_2 -> V_30 ) ;
} while ( V_34 == F_50 ( - V_99 ) );
if ( V_34 != V_78 )
F_69 ( V_78 ) ;
V_26:
F_71 ( V_32 ) ;
return V_34 ;
}
void F_79 ( struct V_33 * V_34 )
{
struct V_31 * V_32 = V_34 -> V_79 ;
struct V_1 * V_2 = V_32 -> V_1 ;
if ( ! F_80 ( & V_34 -> V_77 , & V_2 -> V_30 ) )
return;
V_34 -> V_98 = V_49 ;
F_81 ( & V_34 -> V_76 , & V_32 -> V_100 ) ;
F_15 ( & V_2 -> V_30 ) ;
}
void F_82 ( struct V_31 * V_32 )
{
struct V_1 * V_2 = V_32 -> V_1 ;
struct V_33 * V_34 , * V_94 ;
F_72 ( V_97 ) ;
F_14 ( & V_2 -> V_30 ) ;
F_73 (sp, tmp, &server->state_owners_lru, so_lru) {
F_75 ( & V_34 -> V_76 , & V_97 ) ;
F_53 ( V_34 ) ;
}
F_15 ( & V_2 -> V_30 ) ;
F_73 (sp, tmp, &doomed, so_lru) {
F_76 ( & V_34 -> V_76 ) ;
F_69 ( V_34 ) ;
}
}
static struct V_101 *
F_83 ( void )
{
struct V_101 * V_102 ;
V_102 = F_65 ( sizeof( * V_102 ) , V_103 ) ;
if ( ! V_102 )
return NULL ;
F_66 ( & V_102 -> V_104 , 1 ) ;
F_60 ( & V_102 -> V_105 ) ;
F_59 ( & V_102 -> V_106 ) ;
F_84 ( & V_102 -> V_107 ) ;
return V_102 ;
}
void
F_85 ( struct V_101 * V_102 , T_2 V_108 )
{
if ( V_102 -> V_102 == V_108 )
return;
if ( ( V_108 & V_109 ) != ( V_102 -> V_102 & V_109 ) ) {
if ( V_108 & V_109 )
F_75 ( & V_102 -> V_110 , & V_102 -> V_111 -> V_39 ) ;
else
F_86 ( & V_102 -> V_110 , & V_102 -> V_111 -> V_39 ) ;
}
V_102 -> V_102 = V_108 ;
}
static struct V_101 *
F_87 ( struct V_112 * V_112 , struct V_33 * V_111 )
{
struct V_113 * V_114 = F_88 ( V_112 ) ;
struct V_101 * V_102 ;
F_89 (state, &nfsi->open_states, inode_states) {
if ( V_102 -> V_111 != V_111 )
continue;
if ( F_90 ( & V_102 -> V_104 ) )
return V_102 ;
}
return NULL ;
}
static void
F_91 ( struct V_101 * V_102 )
{
F_70 ( V_102 ) ;
}
struct V_101 *
F_92 ( struct V_112 * V_112 , struct V_33 * V_111 )
{
struct V_101 * V_102 , * V_78 ;
struct V_113 * V_114 = F_88 ( V_112 ) ;
F_14 ( & V_112 -> V_115 ) ;
V_102 = F_87 ( V_112 , V_111 ) ;
F_15 ( & V_112 -> V_115 ) ;
if ( V_102 )
goto V_26;
V_78 = F_83 () ;
F_14 ( & V_111 -> V_93 ) ;
F_14 ( & V_112 -> V_115 ) ;
V_102 = F_87 ( V_112 , V_111 ) ;
if ( V_102 == NULL && V_78 != NULL ) {
V_102 = V_78 ;
V_102 -> V_111 = V_111 ;
F_47 ( & V_111 -> V_77 ) ;
F_93 ( & V_102 -> V_116 , & V_114 -> V_110 ) ;
F_94 ( V_112 ) ;
V_102 -> V_112 = V_112 ;
F_15 ( & V_112 -> V_115 ) ;
F_81 ( & V_102 -> V_110 , & V_111 -> V_39 ) ;
F_15 ( & V_111 -> V_93 ) ;
} else {
F_15 ( & V_112 -> V_115 ) ;
F_15 ( & V_111 -> V_93 ) ;
if ( V_78 )
F_91 ( V_78 ) ;
}
V_26:
return V_102 ;
}
void F_95 ( struct V_101 * V_102 )
{
struct V_112 * V_112 = V_102 -> V_112 ;
struct V_33 * V_111 = V_102 -> V_111 ;
if ( ! F_80 ( & V_102 -> V_104 , & V_111 -> V_93 ) )
return;
F_14 ( & V_112 -> V_115 ) ;
F_76 ( & V_102 -> V_116 ) ;
F_76 ( & V_102 -> V_110 ) ;
F_15 ( & V_112 -> V_115 ) ;
F_15 ( & V_111 -> V_93 ) ;
F_96 ( V_112 ) ;
F_91 ( V_102 ) ;
F_79 ( V_111 ) ;
}
static void F_97 ( struct V_101 * V_102 ,
T_2 V_108 , T_1 V_117 , int V_91 )
{
struct V_33 * V_111 = V_102 -> V_111 ;
int V_118 = 0 ;
T_2 V_119 ;
F_47 ( & V_111 -> V_77 ) ;
F_14 ( & V_111 -> V_93 ) ;
switch ( V_108 & ( V_120 | V_109 ) ) {
case V_120 :
V_102 -> V_121 -- ;
break;
case V_109 :
V_102 -> V_122 -- ;
break;
case V_120 | V_109 :
V_102 -> V_123 -- ;
}
V_119 = V_120 | V_109 ;
if ( V_102 -> V_123 == 0 ) {
if ( V_102 -> V_121 == 0 ) {
V_119 &= ~ V_120 ;
V_118 |= F_3 ( V_124 , & V_102 -> V_87 ) ;
V_118 |= F_3 ( V_125 , & V_102 -> V_87 ) ;
}
if ( V_102 -> V_122 == 0 ) {
V_119 &= ~ V_109 ;
V_118 |= F_3 ( V_126 , & V_102 -> V_87 ) ;
V_118 |= F_3 ( V_125 , & V_102 -> V_87 ) ;
}
if ( V_119 == 0 )
F_7 ( V_127 , & V_102 -> V_87 ) ;
}
F_85 ( V_102 , V_119 ) ;
F_15 ( & V_111 -> V_93 ) ;
if ( ! V_118 ) {
F_95 ( V_102 ) ;
F_79 ( V_111 ) ;
} else
F_98 ( V_102 , V_117 , V_91 ) ;
}
void F_99 ( struct V_101 * V_102 , T_2 V_108 )
{
F_97 ( V_102 , V_108 , V_103 , 0 ) ;
}
void F_100 ( struct V_101 * V_102 , T_2 V_108 )
{
F_97 ( V_102 , V_108 , V_128 , 1 ) ;
}
static struct V_129 *
F_101 ( struct V_101 * V_102 , T_3 V_130 , T_4 V_131 , unsigned int type )
{
struct V_129 * V_36 ;
F_89 (pos, &state->lock_states, ls_locks) {
if ( type != V_132 && V_36 -> V_133 . V_134 != type )
continue;
switch ( V_36 -> V_133 . V_134 ) {
case V_135 :
if ( V_36 -> V_133 . V_136 . V_137 != V_130 )
continue;
break;
case V_138 :
if ( V_36 -> V_133 . V_136 . V_139 != V_131 )
continue;
}
F_47 ( & V_36 -> V_140 ) ;
return V_36 ;
}
return NULL ;
}
static struct V_129 * F_102 ( struct V_101 * V_102 , T_3 V_130 , T_4 V_131 , unsigned int type )
{
struct V_129 * V_141 ;
struct V_31 * V_32 = V_102 -> V_111 -> V_79 ;
V_141 = F_65 ( sizeof( * V_141 ) , V_103 ) ;
if ( V_141 == NULL )
return NULL ;
F_57 ( & V_141 -> V_142 ) ;
F_66 ( & V_141 -> V_140 , 1 ) ;
V_141 -> V_143 = V_102 ;
V_141 -> V_133 . V_134 = type ;
switch ( V_141 -> V_133 . V_134 ) {
case V_138 :
V_141 -> V_133 . V_136 . V_139 = V_131 ;
break;
case V_135 :
V_141 -> V_133 . V_136 . V_137 = V_130 ;
break;
default:
goto V_144;
}
V_141 -> V_142 . V_83 = F_103 ( & V_32 -> V_145 , 0 , 0 , V_103 ) ;
if ( V_141 -> V_142 . V_83 < 0 )
goto V_144;
F_60 ( & V_141 -> V_146 ) ;
return V_141 ;
V_144:
F_70 ( V_141 ) ;
return NULL ;
}
void F_104 ( struct V_31 * V_32 , struct V_129 * V_141 )
{
F_105 ( & V_32 -> V_145 , V_141 -> V_142 . V_83 ) ;
F_62 ( & V_141 -> V_142 ) ;
F_70 ( V_141 ) ;
}
static struct V_129 * F_106 ( struct V_101 * V_102 , T_3 V_111 , T_4 V_147 , unsigned int type )
{
struct V_129 * V_141 , * V_78 = NULL ;
for(; ; ) {
F_14 ( & V_102 -> V_106 ) ;
V_141 = F_101 ( V_102 , V_111 , V_147 , type ) ;
if ( V_141 != NULL )
break;
if ( V_78 != NULL ) {
F_93 ( & V_78 -> V_146 , & V_102 -> V_105 ) ;
F_5 ( V_148 , & V_102 -> V_87 ) ;
V_141 = V_78 ;
V_78 = NULL ;
break;
}
F_15 ( & V_102 -> V_106 ) ;
V_78 = F_102 ( V_102 , V_111 , V_147 , type ) ;
if ( V_78 == NULL )
return NULL ;
}
F_15 ( & V_102 -> V_106 ) ;
if ( V_78 != NULL )
F_104 ( V_102 -> V_111 -> V_79 , V_78 ) ;
return V_141 ;
}
void F_107 ( struct V_129 * V_141 )
{
struct V_101 * V_102 ;
if ( V_141 == NULL )
return;
V_102 = V_141 -> V_143 ;
if ( ! F_80 ( & V_141 -> V_140 , & V_102 -> V_106 ) )
return;
F_76 ( & V_141 -> V_146 ) ;
if ( F_21 ( & V_102 -> V_105 ) )
F_7 ( V_148 , & V_102 -> V_87 ) ;
F_15 ( & V_102 -> V_106 ) ;
if ( F_3 ( V_149 , & V_141 -> V_150 ) ) {
if ( F_108 ( V_141 ) == 0 )
return;
}
F_104 ( V_141 -> V_143 -> V_111 -> V_79 , V_141 ) ;
}
static void F_109 ( struct V_151 * V_152 , struct V_151 * V_153 )
{
struct V_129 * V_141 = V_153 -> V_154 . V_155 . V_111 ;
V_152 -> V_154 . V_155 . V_111 = V_141 ;
F_47 ( & V_141 -> V_140 ) ;
}
static void F_110 ( struct V_151 * V_156 )
{
F_107 ( V_156 -> V_154 . V_155 . V_111 ) ;
}
int F_111 ( struct V_101 * V_102 , struct V_151 * V_156 )
{
struct V_129 * V_141 ;
if ( V_156 -> V_157 != NULL )
return 0 ;
if ( V_156 -> V_158 & V_159 )
V_141 = F_106 ( V_102 , V_156 -> V_130 , 0 , V_135 ) ;
else if ( V_156 -> V_158 & V_160 )
V_141 = F_106 ( V_102 , NULL , V_156 -> V_131 ,
V_138 ) ;
else
return - V_161 ;
if ( V_141 == NULL )
return - V_162 ;
V_156 -> V_154 . V_155 . V_111 = V_141 ;
V_156 -> V_157 = & V_163 ;
return 0 ;
}
static bool F_112 ( T_5 * V_152 , struct V_101 * V_102 ,
const struct V_164 * V_165 )
{
struct V_129 * V_141 ;
T_3 V_130 ;
T_4 V_131 ;
bool V_65 = false ;
if ( V_165 == NULL )
goto V_26;
if ( F_3 ( V_148 , & V_102 -> V_87 ) == 0 )
goto V_26;
V_130 = V_165 -> V_166 ;
V_131 = V_165 -> V_167 ;
F_14 ( & V_102 -> V_106 ) ;
V_141 = F_101 ( V_102 , V_130 , V_131 , V_132 ) ;
if ( V_141 != NULL && F_3 ( V_149 , & V_141 -> V_150 ) != 0 ) {
F_113 ( V_152 , & V_141 -> V_168 ) ;
V_65 = true ;
}
F_15 ( & V_102 -> V_106 ) ;
F_107 ( V_141 ) ;
V_26:
return V_65 ;
}
static void F_114 ( T_5 * V_152 , struct V_101 * V_102 )
{
int V_169 ;
do {
V_169 = F_115 ( & V_102 -> V_107 ) ;
F_113 ( V_152 , & V_102 -> V_170 ) ;
} while ( F_116 ( & V_102 -> V_107 , V_169 ) );
}
void F_117 ( T_5 * V_152 , struct V_101 * V_102 ,
T_2 V_108 , const struct V_164 * V_165 )
{
if ( F_118 ( V_152 , V_102 -> V_112 , V_108 ) )
return;
if ( F_112 ( V_152 , V_102 , V_165 ) )
return;
F_114 ( V_152 , V_102 ) ;
}
struct V_171 * F_119 ( struct V_84 * V_88 , T_1 V_117 )
{
struct V_171 * V_78 ;
V_78 = F_120 ( sizeof( * V_78 ) , V_117 ) ;
if ( V_78 != NULL ) {
V_78 -> V_172 = V_88 ;
F_60 ( & V_78 -> V_90 ) ;
V_78 -> V_173 = NULL ;
}
return V_78 ;
}
void F_121 ( struct V_171 * V_174 )
{
struct V_84 * V_172 ;
if ( F_21 ( & V_174 -> V_90 ) )
return;
V_172 = V_174 -> V_172 ;
F_14 ( & V_172 -> V_89 ) ;
F_46 ( & V_174 -> V_90 ) ;
if ( ! F_21 ( & V_172 -> V_90 ) ) {
struct V_171 * V_175 ;
V_175 = F_122 ( & V_172 -> V_90 ,
struct V_171 , V_90 ) ;
F_123 ( & V_172 -> V_91 , V_175 -> V_173 ) ;
}
F_15 ( & V_172 -> V_89 ) ;
}
void F_124 ( struct V_171 * V_174 )
{
F_121 ( V_174 ) ;
F_70 ( V_174 ) ;
}
static void F_125 ( int V_12 , struct V_171 * V_174 )
{
F_126 ( F_122 ( & V_174 -> V_172 -> V_90 , struct V_171 , V_90 ) != V_174 ) ;
switch ( V_12 ) {
case 0 :
break;
case - V_176 :
if ( V_174 -> V_172 -> V_87 & V_177 )
return;
F_127 ( L_2
L_3
L_4 ,
V_174 -> V_172 ) ;
case - V_28 :
case - V_178 :
case - V_179 :
case - V_180 :
case - V_181 :
case - V_182 :
return;
} ;
V_174 -> V_172 -> V_88 ++ ;
}
void F_128 ( int V_12 , struct V_171 * V_174 )
{
struct V_33 * V_34 = F_129 ( V_174 -> V_172 ,
struct V_33 , V_82 ) ;
struct V_31 * V_32 = V_34 -> V_79 ;
if ( V_12 == - V_176 )
F_67 ( V_34 ) ;
if ( ! F_130 ( V_32 -> V_1 ) )
F_125 ( V_12 , V_174 ) ;
}
void F_131 ( int V_12 , struct V_171 * V_174 )
{
F_125 ( V_12 , V_174 ) ;
}
int F_132 ( struct V_171 * V_174 , struct V_183 * V_173 )
{
struct V_84 * V_172 = V_174 -> V_172 ;
int V_12 = 0 ;
F_14 ( & V_172 -> V_89 ) ;
V_174 -> V_173 = V_173 ;
if ( F_21 ( & V_174 -> V_90 ) )
F_81 ( & V_174 -> V_90 , & V_172 -> V_90 ) ;
if ( F_122 ( & V_172 -> V_90 , struct V_171 , V_90 ) == V_174 )
goto V_184;
F_133 ( & V_172 -> V_91 , V_173 , NULL ) ;
V_12 = - V_99 ;
V_184:
F_15 ( & V_172 -> V_89 ) ;
return V_12 ;
}
static void F_134 ( struct V_1 * V_2 )
{
F_135 () ;
F_7 ( V_185 , & V_2 -> V_18 ) ;
F_136 () ;
F_137 ( & V_2 -> V_18 , V_185 ) ;
F_138 ( & V_2 -> V_186 ) ;
}
void F_139 ( struct V_1 * V_2 )
{
struct V_187 * V_173 ;
char V_188 [ V_189 + sizeof( L_5 ) + 1 ] ;
if ( F_140 ( V_185 , & V_2 -> V_18 ) != 0 )
return;
F_141 ( V_190 ) ;
F_47 ( & V_2 -> V_191 ) ;
F_23 () ;
snprintf ( V_188 , sizeof( V_188 ) , L_6 ,
F_142 ( V_2 -> V_192 , V_193 ) ) ;
F_25 () ;
V_173 = F_143 ( V_194 , V_2 , V_188 ) ;
if ( F_144 ( V_173 ) ) {
F_145 ( V_195 L_7 ,
V_196 , F_146 ( V_173 ) ) ;
F_134 ( V_2 ) ;
F_147 ( V_2 ) ;
F_148 ( V_190 ) ;
}
}
void F_149 ( struct V_1 * V_2 )
{
if ( ! V_2 )
return;
if ( ! F_3 ( V_197 , & V_2 -> V_18 ) )
F_5 ( V_198 , & V_2 -> V_18 ) ;
F_150 ( L_8 , V_196 ,
V_2 -> V_199 ) ;
F_139 ( V_2 ) ;
}
static void F_151 ( struct V_1 * V_2 )
{
F_5 ( V_197 , & V_2 -> V_18 ) ;
F_152 ( V_2 ) ;
F_150 ( L_9 , V_196 ,
V_2 -> V_199 ) ;
}
void F_153 ( struct V_1 * V_2 )
{
F_151 ( V_2 ) ;
F_139 ( V_2 ) ;
}
static int F_154 ( struct V_1 * V_2 , struct V_101 * V_102 )
{
F_5 ( V_200 , & V_102 -> V_87 ) ;
if ( F_3 ( V_201 , & V_102 -> V_87 ) ) {
F_7 ( V_200 , & V_102 -> V_87 ) ;
return 0 ;
}
F_5 ( V_202 , & V_102 -> V_111 -> V_203 ) ;
F_5 ( V_204 , & V_2 -> V_18 ) ;
return 1 ;
}
static int F_155 ( struct V_1 * V_2 , struct V_101 * V_102 )
{
F_5 ( V_201 , & V_102 -> V_87 ) ;
F_7 ( V_200 , & V_102 -> V_87 ) ;
F_5 ( V_205 , & V_102 -> V_111 -> V_203 ) ;
F_5 ( V_206 , & V_2 -> V_18 ) ;
return 1 ;
}
void F_156 ( const struct V_31 * V_32 , struct V_101 * V_102 )
{
struct V_1 * V_2 = V_32 -> V_1 ;
F_155 ( V_2 , V_102 ) ;
F_150 ( L_10 , V_196 ,
V_2 -> V_199 ) ;
F_139 ( V_2 ) ;
}
void F_157 ( struct V_112 * V_112 ,
const T_5 * V_170 )
{
struct V_1 * V_2 = F_158 ( V_112 ) -> V_1 ;
struct V_113 * V_114 = F_88 ( V_112 ) ;
struct V_207 * V_208 ;
struct V_101 * V_102 ;
bool V_209 = false ;
F_14 ( & V_112 -> V_115 ) ;
F_89 (ctx, &nfsi->open_files, list) {
V_102 = V_208 -> V_102 ;
if ( V_102 == NULL )
continue;
if ( ! F_3 ( V_127 , & V_102 -> V_87 ) )
continue;
if ( ! F_159 ( & V_102 -> V_170 , V_170 ) )
continue;
F_155 ( V_2 , V_102 ) ;
V_209 = true ;
}
F_15 ( & V_112 -> V_115 ) ;
if ( V_209 )
F_139 ( V_2 ) ;
}
static int F_160 ( struct V_101 * V_102 , const struct V_210 * V_211 )
{
struct V_112 * V_112 = V_102 -> V_112 ;
struct V_113 * V_114 = F_88 ( V_112 ) ;
struct V_151 * V_156 ;
int V_12 = 0 ;
if ( V_112 -> V_212 == NULL )
return 0 ;
F_161 ( & V_114 -> V_213 ) ;
F_162 () ;
for ( V_156 = V_112 -> V_212 ; V_156 != NULL ; V_156 = V_156 -> V_214 ) {
if ( ! ( V_156 -> V_158 & ( V_159 | V_160 ) ) )
continue;
if ( F_163 ( V_156 -> V_215 ) -> V_102 != V_102 )
continue;
F_164 () ;
V_12 = V_211 -> V_216 ( V_102 , V_156 ) ;
switch ( V_12 ) {
case 0 :
break;
case - V_217 :
case - V_218 :
case - V_178 :
case - V_179 :
case - V_219 :
case - V_220 :
case - V_28 :
case - V_221 :
case - V_222 :
case - V_223 :
case - V_224 :
goto V_26;
default:
F_145 ( V_195 L_11
L_12 , V_196 , V_12 ) ;
case - V_162 :
case - V_225 :
case - V_226 :
case - V_227 :
V_12 = 0 ;
}
F_162 () ;
}
F_164 () ;
V_26:
F_165 ( & V_114 -> V_213 ) ;
return V_12 ;
}
static int F_166 ( struct V_33 * V_34 , const struct V_210 * V_211 )
{
struct V_101 * V_102 ;
struct V_129 * V_89 ;
int V_12 = 0 ;
V_228:
F_14 ( & V_34 -> V_93 ) ;
F_89 (state, &sp->so_states, open_states) {
if ( ! F_29 ( V_211 -> V_229 , & V_102 -> V_87 ) )
continue;
if ( V_102 -> V_102 == 0 )
continue;
F_47 ( & V_102 -> V_104 ) ;
F_15 ( & V_34 -> V_93 ) ;
V_12 = V_211 -> V_230 ( V_34 , V_102 ) ;
if ( V_12 >= 0 ) {
V_12 = F_160 ( V_102 , V_211 ) ;
if ( V_12 >= 0 ) {
F_14 ( & V_102 -> V_106 ) ;
F_89 (lock, &state->lock_states, ls_locks) {
if ( ! F_3 ( V_149 , & V_89 -> V_150 ) )
F_127 ( L_13
L_14
L_15 , V_196 ) ;
}
F_15 ( & V_102 -> V_106 ) ;
F_95 ( V_102 ) ;
goto V_228;
}
}
switch ( V_12 ) {
default:
F_145 ( V_195 L_11
L_12 , V_196 , V_12 ) ;
case - V_231 :
case - V_162 :
case - V_217 :
memset ( & V_102 -> V_170 , 0 ,
sizeof( V_102 -> V_170 ) ) ;
V_102 -> V_102 = 0 ;
break;
case - V_232 :
break;
case - V_218 :
case - V_178 :
case - V_179 :
case - V_226 :
case - V_227 :
F_155 ( V_34 -> V_79 -> V_1 , V_102 ) ;
break;
case - V_219 :
case - V_220 :
F_155 ( V_34 -> V_79 -> V_1 , V_102 ) ;
case - V_28 :
case - V_221 :
case - V_222 :
case - V_223 :
case - V_224 :
goto V_233;
}
F_95 ( V_102 ) ;
goto V_228;
}
F_15 ( & V_34 -> V_93 ) ;
return 0 ;
V_233:
F_95 ( V_102 ) ;
return V_12 ;
}
static void F_167 ( struct V_101 * V_102 )
{
struct V_129 * V_89 ;
F_7 ( V_127 , & V_102 -> V_87 ) ;
F_7 ( V_124 , & V_102 -> V_87 ) ;
F_7 ( V_126 , & V_102 -> V_87 ) ;
F_7 ( V_125 , & V_102 -> V_87 ) ;
F_14 ( & V_102 -> V_106 ) ;
F_89 (lock, &state->lock_states, ls_locks) {
V_89 -> V_142 . V_87 = 0 ;
F_7 ( V_149 , & V_89 -> V_150 ) ;
}
F_15 ( & V_102 -> V_106 ) ;
}
static void F_168 ( struct V_31 * V_32 ,
int (* F_169)( struct V_1 * V_2 , struct V_101 * V_102 ) )
{
struct V_1 * V_2 = V_32 -> V_1 ;
struct V_33 * V_34 ;
struct V_35 * V_36 ;
struct V_101 * V_102 ;
F_14 ( & V_2 -> V_30 ) ;
for ( V_36 = F_18 ( & V_32 -> V_37 ) ;
V_36 != NULL ;
V_36 = F_19 ( V_36 ) ) {
V_34 = F_20 ( V_36 , struct V_33 , V_38 ) ;
V_34 -> V_82 . V_87 = 0 ;
F_14 ( & V_34 -> V_93 ) ;
F_89 (state, &sp->so_states, open_states) {
if ( F_169 ( V_2 , V_102 ) )
F_167 ( V_102 ) ;
}
F_15 ( & V_34 -> V_93 ) ;
}
F_15 ( & V_2 -> V_30 ) ;
}
static void F_170 ( struct V_1 * V_2 ,
int (* F_169)( struct V_1 * V_2 , struct V_101 * V_102 ) )
{
struct V_31 * V_32 ;
F_23 () ;
F_24 (server, &clp->cl_superblocks, client_link)
F_168 ( V_32 , F_169 ) ;
F_25 () ;
}
static void F_171 ( struct V_1 * V_2 )
{
F_172 ( V_2 ) ;
F_170 ( V_2 , F_154 ) ;
}
static void F_173 ( struct V_1 * V_2 ,
const struct V_210 * V_211 )
{
if ( V_211 -> V_234 )
( void ) V_211 -> V_234 ( V_2 ) ;
}
static void F_174 ( struct V_31 * V_32 )
{
struct V_1 * V_2 = V_32 -> V_1 ;
struct V_33 * V_34 ;
struct V_35 * V_36 ;
struct V_101 * V_102 ;
F_14 ( & V_2 -> V_30 ) ;
for ( V_36 = F_18 ( & V_32 -> V_37 ) ;
V_36 != NULL ;
V_36 = F_19 ( V_36 ) ) {
V_34 = F_20 ( V_36 , struct V_33 , V_38 ) ;
F_14 ( & V_34 -> V_93 ) ;
F_89 (state, &sp->so_states, open_states) {
if ( ! F_29 ( V_200 ,
& V_102 -> V_87 ) )
continue;
F_155 ( V_2 , V_102 ) ;
}
F_15 ( & V_34 -> V_93 ) ;
}
F_15 ( & V_2 -> V_30 ) ;
}
static int F_175 ( struct V_1 * V_2 )
{
struct V_31 * V_32 ;
if ( ! F_29 ( V_204 , & V_2 -> V_18 ) )
return 0 ;
F_23 () ;
F_24 (server, &clp->cl_superblocks, client_link)
F_174 ( V_32 ) ;
F_25 () ;
F_176 ( V_2 ) ;
return 1 ;
}
static void F_177 ( struct V_1 * V_2 )
{
if ( ! F_175 ( V_2 ) )
return;
F_173 ( V_2 , V_2 -> V_235 -> V_236 ) ;
}
static void F_178 ( struct V_1 * V_2 )
{
F_172 ( V_2 ) ;
F_176 ( V_2 ) ;
}
static void F_179 ( struct V_1 * V_2 )
{
F_178 ( V_2 ) ;
F_170 ( V_2 , F_155 ) ;
}
static void F_180 ( const char * V_237 )
{
F_181 ( V_238 L_16
L_17
L_18 ,
V_237 ) ;
}
static int F_182 ( struct V_1 * V_2 , int error )
{
switch ( error ) {
case 0 :
break;
case - V_239 :
F_151 ( V_2 ) ;
break;
case - V_220 :
F_177 ( V_2 ) ;
break;
case - V_28 :
case - V_240 :
F_5 ( V_197 , & V_2 -> V_18 ) ;
F_175 ( V_2 ) ;
F_171 ( V_2 ) ;
break;
case - V_219 :
F_5 ( V_197 , & V_2 -> V_18 ) ;
F_179 ( V_2 ) ;
break;
case - V_221 :
case - V_222 :
case - V_223 :
case - V_241 :
case - V_242 :
case - V_243 :
F_5 ( V_67 , & V_2 -> V_18 ) ;
break;
case - V_224 :
F_5 ( V_69 , & V_2 -> V_18 ) ;
break;
case - V_232 :
F_180 ( V_2 -> V_199 ) ;
break;
default:
F_150 ( L_19 ,
V_196 , error , V_2 -> V_199 ) ;
return error ;
}
F_150 ( L_20 , V_196 , error ,
V_2 -> V_199 ) ;
return 0 ;
}
static int F_183 ( struct V_1 * V_2 , const struct V_210 * V_211 )
{
struct V_33 * V_34 ;
struct V_31 * V_32 ;
struct V_35 * V_36 ;
int V_12 = 0 ;
V_228:
F_23 () ;
F_24 (server, &clp->cl_superblocks, client_link) {
F_82 ( V_32 ) ;
F_14 ( & V_2 -> V_30 ) ;
for ( V_36 = F_18 ( & V_32 -> V_37 ) ;
V_36 != NULL ;
V_36 = F_19 ( V_36 ) ) {
V_34 = F_20 ( V_36 ,
struct V_33 , V_38 ) ;
if ( ! F_29 ( V_211 -> V_244 ,
& V_34 -> V_203 ) )
continue;
F_47 ( & V_34 -> V_77 ) ;
F_15 ( & V_2 -> V_30 ) ;
F_25 () ;
V_12 = F_166 ( V_34 , V_211 ) ;
if ( V_12 < 0 ) {
F_5 ( V_211 -> V_244 , & V_34 -> V_203 ) ;
F_79 ( V_34 ) ;
return F_182 ( V_2 , V_12 ) ;
}
F_79 ( V_34 ) ;
goto V_228;
}
F_15 ( & V_2 -> V_30 ) ;
}
F_25 () ;
return V_12 ;
}
static int F_184 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
const struct V_245 * V_211 =
V_2 -> V_235 -> V_246 ;
int V_12 ;
if ( F_3 ( V_197 , & V_2 -> V_18 ) )
return 0 ;
F_14 ( & V_2 -> V_30 ) ;
V_4 = V_211 -> V_247 ( V_2 ) ;
F_15 ( & V_2 -> V_30 ) ;
if ( V_4 == NULL ) {
V_4 = F_44 ( V_2 ) ;
V_12 = - V_248 ;
if ( V_4 == NULL )
goto V_26;
}
V_12 = V_211 -> V_249 ( V_2 , V_4 ) ;
F_16 ( V_4 ) ;
V_26:
return F_182 ( V_2 , V_12 ) ;
}
static int F_185 ( struct V_1 * V_2 , int V_12 )
{
switch ( V_12 ) {
case - V_243 :
if ( F_140 ( V_250 , & V_2 -> V_18 ) )
return - V_251 ;
F_186 ( 1 ) ;
F_7 ( V_17 , & V_2 -> V_18 ) ;
break;
case - V_28 :
F_7 ( V_17 , & V_2 -> V_18 ) ;
F_175 ( V_2 ) ;
F_171 ( V_2 ) ;
break;
case - V_252 :
F_187 ( L_21 ,
V_2 -> V_199 ) ;
F_39 ( V_2 , - V_253 ) ;
F_7 ( V_17 , & V_2 -> V_18 ) ;
return - V_253 ;
case - V_254 :
if ( V_2 -> V_29 == NULL )
return - V_254 ;
F_13 ( V_2 ) ;
case - V_255 :
case - V_256 :
case - V_99 :
F_186 ( 1 ) ;
break;
case - V_257 :
if ( V_2 -> V_258 == V_259 )
F_39 ( V_2 , - V_260 ) ;
F_150 ( L_22 ,
V_196 , - V_260 , V_2 -> V_199 ) ;
return - V_260 ;
case - V_232 :
F_180 ( V_2 -> V_199 ) ;
case - V_261 :
default:
F_150 ( L_22 , V_196 ,
V_12 , V_2 -> V_199 ) ;
return V_12 ;
}
F_5 ( V_197 , & V_2 -> V_18 ) ;
F_150 ( L_20 , V_196 , V_12 ,
V_2 -> V_199 ) ;
return 0 ;
}
static int F_188 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
const struct V_210 * V_211 =
V_2 -> V_235 -> V_236 ;
int V_12 ;
V_4 = V_211 -> V_262 ( V_2 ) ;
if ( V_4 == NULL )
return - V_231 ;
V_12 = V_211 -> V_263 ( V_2 , V_4 ) ;
F_16 ( V_4 ) ;
if ( V_12 != 0 )
return V_12 ;
F_189 ( V_2 ) ;
return 0 ;
}
static int F_190 ( struct V_1 * V_2 )
{
int V_12 ;
V_12 = F_188 ( V_2 ) ;
if ( V_12 < 0 )
return F_185 ( V_2 , V_12 ) ;
if ( F_29 ( V_264 , & V_2 -> V_18 ) )
F_179 ( V_2 ) ;
if ( ! F_3 ( V_206 , & V_2 -> V_18 ) )
F_5 ( V_204 , & V_2 -> V_18 ) ;
F_7 ( V_198 , & V_2 -> V_18 ) ;
F_7 ( V_197 , & V_2 -> V_18 ) ;
return 0 ;
}
static int F_191 ( struct V_1 * V_2 )
{
int V_12 ;
V_12 = F_188 ( V_2 ) ;
if ( V_12 < 0 )
return F_185 ( V_2 , V_12 ) ;
F_7 ( V_250 , & V_2 -> V_18 ) ;
F_5 ( V_197 , & V_2 -> V_18 ) ;
F_179 ( V_2 ) ;
return 0 ;
}
int F_192 ( struct V_1 * V_2 ,
struct V_1 * * V_27 )
{
const struct V_210 * V_211 =
V_2 -> V_235 -> V_236 ;
T_6 * V_265 , V_266 , V_267 ;
struct V_268 * V_269 ;
struct V_3 * V_4 ;
int V_270 , V_271 , V_12 ;
F_150 ( L_23 , V_196 , V_2 -> V_199 ) ;
V_271 = V_272 ;
V_265 = F_193 ( V_271 , sizeof( * V_265 ) , V_128 ) ;
if ( V_265 == NULL ) {
V_12 = - V_162 ;
goto V_26;
}
V_271 = F_194 ( V_265 , V_271 ) ;
if ( V_271 < 0 ) {
V_12 = V_271 ;
goto V_144;
}
V_269 = V_2 -> V_192 ;
V_267 = V_269 -> V_273 -> V_274 ;
V_270 = 0 ;
F_195 ( & V_275 ) ;
V_12 = - V_231 ;
V_276:
V_4 = V_211 -> V_262 ( V_2 ) ;
if ( V_4 == NULL )
goto V_277;
V_12 = V_211 -> V_278 ( V_2 , V_27 , V_4 ) ;
F_16 ( V_4 ) ;
switch ( V_12 ) {
case 0 :
break;
case - V_254 :
if ( V_2 -> V_29 == NULL )
break;
F_13 ( V_2 ) ;
case - V_255 :
case - V_256 :
case - V_99 :
F_186 ( 1 ) ;
F_150 ( L_24 ,
V_196 , V_12 ) ;
goto V_276;
case - V_252 :
case - V_279 :
V_12 = - V_253 ;
if ( V_270 >= V_271 )
break;
V_266 = V_265 [ V_270 ++ ] ;
if ( V_266 == V_267 )
V_266 = V_265 [ V_270 ++ ] ;
V_269 = F_196 ( V_269 , V_266 ) ;
if ( F_144 ( V_269 ) ) {
V_12 = F_146 ( V_269 ) ;
break;
}
V_2 -> V_192 = V_269 ;
goto V_276;
case - V_257 :
V_12 = - V_260 ;
break;
case - V_232 :
F_180 ( V_2 -> V_199 ) ;
case - V_261 :
V_12 = - V_232 ;
}
V_277:
F_197 ( & V_275 ) ;
V_144:
F_70 ( V_265 ) ;
V_26:
F_150 ( L_25 , V_196 , V_12 ) ;
return V_12 ;
}
void F_198 ( struct V_50 * V_280 , int V_80 )
{
struct V_1 * V_2 = V_280 -> V_2 ;
switch ( V_80 ) {
default:
F_5 ( V_67 , & V_2 -> V_18 ) ;
break;
case - V_224 :
F_5 ( V_69 , & V_2 -> V_18 ) ;
}
F_149 ( V_2 ) ;
}
void F_199 ( struct V_1 * V_2 )
{
F_5 ( V_68 , & V_2 -> V_18 ) ;
F_150 ( L_26 , V_196 ,
V_2 -> V_199 ) ;
F_139 ( V_2 ) ;
}
static void F_200 ( struct V_1 * V_2 )
{
if ( F_140 ( V_197 , & V_2 -> V_18 ) == 0 ) {
F_5 ( V_250 , & V_2 -> V_18 ) ;
F_7 ( V_17 , & V_2 -> V_18 ) ;
F_179 ( V_2 ) ;
F_150 ( L_27 ,
V_196 , V_2 -> V_199 ) ;
F_139 ( V_2 ) ;
}
}
static void F_201 ( struct V_1 * V_2 )
{
if ( F_140 ( V_197 , & V_2 -> V_18 ) == 0 ) {
F_171 ( V_2 ) ;
F_150 ( L_28 , V_196 ,
V_2 -> V_199 ) ;
F_139 ( V_2 ) ;
}
}
static void F_202 ( struct V_1 * V_2 )
{
F_200 ( V_2 ) ;
F_150 ( L_29 , V_196 , V_2 -> V_199 ) ;
}
static void F_203 ( struct V_1 * V_2 )
{
F_152 ( V_2 ) ;
F_150 ( L_30 , V_196 ,
V_2 -> V_199 ) ;
}
static void F_204 ( struct V_1 * V_2 )
{
F_152 ( V_2 ) ;
if ( F_140 ( V_67 , & V_2 -> V_18 ) == 0 )
F_139 ( V_2 ) ;
F_150 ( L_31 , V_196 ,
V_2 -> V_199 ) ;
}
static void F_205 ( struct V_1 * V_2 )
{
if ( F_140 ( V_69 ,
& V_2 -> V_18 ) == 0 )
F_139 ( V_2 ) ;
}
void F_206 ( struct V_1 * V_2 , T_7 V_87 )
{
if ( ! V_87 )
return;
F_150 ( L_32 ,
V_196 , V_2 -> V_199 , V_2 -> V_8 , V_87 ) ;
if ( V_87 & V_281 )
F_201 ( V_2 ) ;
if ( V_87 & ( V_282 |
V_283 |
V_284 |
V_285 ) )
F_202 ( V_2 ) ;
if ( V_87 & V_286 )
F_203 ( V_2 ) ;
if ( V_87 & V_287 )
F_204 ( V_2 ) ;
else if ( V_87 & ( V_288 |
V_289 ) )
F_205 ( V_2 ) ;
}
static int F_207 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
int V_12 ;
if ( ! F_130 ( V_2 ) )
return 0 ;
F_34 ( V_2 ) ;
V_4 = F_42 ( V_2 ) ;
V_12 = F_208 ( V_2 -> V_52 , V_4 ) ;
if ( V_12 && V_12 != - V_221 &&
V_12 != - V_241 ) {
V_12 = F_182 ( V_2 , V_12 ) ;
goto V_26;
}
memset ( V_2 -> V_52 -> V_290 . V_291 , 0 , V_292 ) ;
V_12 = F_38 ( V_2 , V_4 ) ;
if ( V_12 ) {
F_150 ( L_33 ,
V_196 , V_12 , V_2 -> V_199 ) ;
V_12 = F_185 ( V_2 , V_12 ) ;
goto V_26;
}
F_35 ( V_2 ) ;
F_150 ( L_34 ,
V_196 , V_2 -> V_199 ) ;
V_26:
if ( V_4 )
F_16 ( V_4 ) ;
return V_12 ;
}
static int F_209 ( struct V_1 * V_2 )
{
struct V_53 * V_293 ;
struct V_294 * V_78 , * V_295 ;
int V_270 ;
if ( ! F_130 ( V_2 ) )
return 0 ;
F_34 ( V_2 ) ;
V_293 = & V_2 -> V_52 -> V_56 ;
V_78 = F_120 ( V_293 -> V_296 * sizeof( struct V_294 ) ,
V_103 ) ;
if ( ! V_78 )
return - V_162 ;
F_14 ( & V_293 -> V_59 ) ;
for ( V_270 = 0 ; V_270 < V_293 -> V_296 ; V_270 ++ )
V_78 [ V_270 ] . V_297 = V_293 -> V_298 [ V_270 ] . V_297 ;
V_295 = V_293 -> V_298 ;
V_293 -> V_298 = V_78 ;
V_293 -> V_55 = V_293 -> V_296 ;
V_293 -> V_296 = 0 ;
V_2 -> V_52 -> V_299 . V_300 = V_293 -> V_55 ;
F_15 ( & V_293 -> V_59 ) ;
F_70 ( V_295 ) ;
return 0 ;
}
static int F_210 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
int V_65 ;
if ( ! F_130 ( V_2 ) )
return 0 ;
F_34 ( V_2 ) ;
V_4 = F_42 ( V_2 ) ;
V_65 = F_211 ( V_2 , V_4 ) ;
if ( V_4 )
F_16 ( V_4 ) ;
F_7 ( V_69 , & V_2 -> V_18 ) ;
switch ( V_65 ) {
case 0 :
F_150 ( L_35 ,
V_196 , V_2 -> V_199 ) ;
break;
case - V_255 :
F_186 ( 1 ) ;
F_5 ( V_69 , & V_2 -> V_18 ) ;
break;
default:
return F_182 ( V_2 , V_65 ) ;
}
return 0 ;
}
static int F_207 ( struct V_1 * V_2 ) { return 0 ; }
static int F_28 ( struct V_1 * V_2 ) { return 0 ; }
static int F_209 ( struct V_1 * V_2 ) { return 0 ; }
static int F_210 ( struct V_1 * V_2 )
{
return 0 ;
}
static void F_212 ( struct V_1 * V_2 )
{
int V_12 = 0 ;
const char * V_301 = L_36 , * V_302 = L_36 ;
do {
if ( F_3 ( V_250 , & V_2 -> V_18 ) ) {
V_301 = L_37 ;
V_12 = F_191 ( V_2 ) ;
if ( V_12 < 0 )
goto V_303;
continue;
}
if ( F_3 ( V_197 , & V_2 -> V_18 ) ) {
V_301 = L_38 ;
V_12 = F_190 ( V_2 ) ;
if ( V_12 < 0 )
goto V_303;
continue;
}
if ( F_29 ( V_198 , & V_2 -> V_18 ) ) {
V_301 = L_39 ;
V_12 = F_184 ( V_2 ) ;
if ( V_12 < 0 )
goto V_303;
if ( F_3 ( V_197 , & V_2 -> V_18 ) )
continue;
}
if ( F_29 ( V_67 , & V_2 -> V_18 ) ) {
V_301 = L_40 ;
V_12 = F_207 ( V_2 ) ;
if ( F_3 ( V_197 , & V_2 -> V_18 ) )
continue;
if ( V_12 < 0 )
goto V_303;
}
if ( F_29 ( V_69 ,
& V_2 -> V_18 ) ) {
V_301 = L_41 ;
V_12 = F_210 ( V_2 ) ;
if ( V_12 < 0 )
goto V_303;
continue;
}
if ( F_29 ( V_68 , & V_2 -> V_18 ) ) {
V_301 = L_42 ;
V_12 = F_209 ( V_2 ) ;
if ( V_12 < 0 )
goto V_303;
continue;
}
if ( F_3 ( V_204 , & V_2 -> V_18 ) ) {
V_301 = L_43 ;
V_12 = F_183 ( V_2 ,
V_2 -> V_235 -> V_236 ) ;
if ( F_3 ( V_197 , & V_2 -> V_18 ) ||
F_3 ( V_67 , & V_2 -> V_18 ) )
continue;
F_177 ( V_2 ) ;
if ( F_3 ( V_206 , & V_2 -> V_18 ) )
continue;
if ( V_12 < 0 )
goto V_303;
}
if ( F_29 ( V_206 , & V_2 -> V_18 ) ) {
V_301 = L_44 ;
V_12 = F_183 ( V_2 ,
V_2 -> V_235 -> V_304 ) ;
if ( F_3 ( V_197 , & V_2 -> V_18 ) ||
F_3 ( V_67 , & V_2 -> V_18 ) ||
F_3 ( V_204 , & V_2 -> V_18 ) )
continue;
if ( V_12 < 0 )
goto V_303;
}
F_28 ( V_2 ) ;
if ( F_29 ( V_305 , & V_2 -> V_18 ) ) {
F_213 ( V_2 ) ;
continue;
}
F_134 ( V_2 ) ;
if ( V_2 -> V_18 == 0 )
break;
if ( F_140 ( V_185 , & V_2 -> V_18 ) != 0 )
break;
} while ( F_214 ( & V_2 -> V_191 ) > 1 );
return;
V_303:
if ( strlen ( V_301 ) )
V_302 = L_45 ;
F_127 ( L_46
L_47 , V_302 , V_301 ,
V_2 -> V_199 , - V_12 ) ;
F_186 ( 1 ) ;
F_28 ( V_2 ) ;
F_134 ( V_2 ) ;
}
static int V_194 ( void * V_306 )
{
struct V_1 * V_2 = V_306 ;
F_215 ( V_307 ) ;
F_212 ( V_2 ) ;
F_147 ( V_2 ) ;
F_216 ( 0 ) ;
return 0 ;
}
