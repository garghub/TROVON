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
int F_32 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
int V_12 ;
if ( F_2 ( V_13 , & V_2 -> V_14 ) )
goto V_15;
F_31 ( V_2 ) ;
V_12 = F_33 ( V_2 , V_4 ) ;
if ( V_12 != 0 )
goto V_22;
F_4 ( V_13 , & V_2 -> V_14 ) ;
V_15:
V_12 = F_34 ( V_2 ) ;
if ( V_12 != 0 )
goto V_22;
F_6 ( V_13 , & V_2 -> V_14 ) ;
F_23 ( V_2 ) ;
F_35 ( V_2 , V_61 ) ;
V_22:
return V_12 ;
}
struct V_3 * F_36 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
F_11 ( & V_2 -> V_24 ) ;
V_4 = F_8 ( V_2 ) ;
F_12 ( & V_2 -> V_24 ) ;
return V_4 ;
}
static struct V_3 *
F_37 ( struct V_25 * V_26 )
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
struct V_3 * F_38 ( struct V_1 * V_2 )
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
V_4 = F_37 ( V_26 ) ;
if ( V_4 != NULL )
break;
}
F_22 () ;
V_22:
return V_4 ;
}
static struct V_27 *
F_39 ( struct V_25 * V_26 , struct V_3 * V_4 )
{
struct V_29 * * V_62 = & V_26 -> V_31 . V_29 ,
* V_63 = NULL ;
struct V_27 * V_28 ;
while ( * V_62 != NULL ) {
V_63 = * V_62 ;
V_28 = F_17 ( V_63 , struct V_27 , V_32 ) ;
if ( V_4 < V_28 -> V_34 )
V_62 = & V_63 -> V_64 ;
else if ( V_4 > V_28 -> V_34 )
V_62 = & V_63 -> V_65 ;
else {
if ( ! F_18 ( & V_28 -> V_66 ) )
F_40 ( & V_28 -> V_66 ) ;
F_41 ( & V_28 -> V_67 ) ;
return V_28 ;
}
}
return NULL ;
}
static struct V_27 *
F_42 ( struct V_27 * V_68 )
{
struct V_25 * V_26 = V_68 -> V_69 ;
struct V_29 * * V_62 = & V_26 -> V_31 . V_29 ,
* V_63 = NULL ;
struct V_27 * V_28 ;
int V_70 ;
while ( * V_62 != NULL ) {
V_63 = * V_62 ;
V_28 = F_17 ( V_63 , struct V_27 , V_32 ) ;
if ( V_68 -> V_34 < V_28 -> V_34 )
V_62 = & V_63 -> V_64 ;
else if ( V_68 -> V_34 > V_28 -> V_34 )
V_62 = & V_63 -> V_65 ;
else {
if ( ! F_18 ( & V_28 -> V_66 ) )
F_40 ( & V_28 -> V_66 ) ;
F_41 ( & V_28 -> V_67 ) ;
return V_28 ;
}
}
V_70 = F_43 ( & V_26 -> V_71 , & V_68 -> V_72 . V_73 ) ;
if ( V_70 )
return F_44 ( V_70 ) ;
F_45 ( & V_68 -> V_32 , V_63 , V_62 ) ;
F_46 ( & V_68 -> V_32 , & V_26 -> V_31 ) ;
return V_68 ;
}
static void
F_47 ( struct V_27 * V_28 )
{
struct V_25 * V_26 = V_28 -> V_69 ;
if ( ! F_48 ( & V_28 -> V_32 ) )
F_49 ( & V_28 -> V_32 , & V_26 -> V_31 ) ;
F_50 ( & V_26 -> V_71 , V_28 -> V_72 . V_73 ) ;
}
static void
F_51 ( struct V_74 * V_75 )
{
V_75 -> V_76 = F_52 () ;
V_75 -> V_77 = 0 ;
V_75 -> V_78 = 0 ;
F_53 ( & V_75 -> V_79 ) ;
F_54 ( & V_75 -> V_80 ) ;
F_55 ( & V_75 -> V_81 , L_1 ) ;
}
static void
F_56 ( struct V_74 * V_75 )
{
F_57 ( & V_75 -> V_81 ) ;
}
static struct V_27 *
F_58 ( struct V_25 * V_26 ,
struct V_3 * V_4 ,
T_1 V_82 )
{
struct V_27 * V_28 ;
V_28 = F_59 ( sizeof( * V_28 ) , V_82 ) ;
if ( ! V_28 )
return NULL ;
V_28 -> V_69 = V_26 ;
V_28 -> V_34 = F_9 ( V_4 ) ;
F_53 ( & V_28 -> V_83 ) ;
F_54 ( & V_28 -> V_33 ) ;
F_51 ( & V_28 -> V_72 ) ;
F_60 ( & V_28 -> V_67 , 1 ) ;
F_54 ( & V_28 -> V_66 ) ;
return V_28 ;
}
static void
F_61 ( struct V_27 * V_28 )
{
struct V_29 * V_29 = & V_28 -> V_32 ;
if ( ! F_48 ( V_29 ) ) {
struct V_25 * V_26 = V_28 -> V_69 ;
struct V_1 * V_2 = V_26 -> V_1 ;
F_11 ( & V_2 -> V_24 ) ;
if ( ! F_48 ( V_29 ) ) {
F_49 ( V_29 , & V_26 -> V_31 ) ;
F_62 ( V_29 ) ;
}
F_12 ( & V_2 -> V_24 ) ;
}
}
static void F_63 ( struct V_27 * V_28 )
{
F_56 ( & V_28 -> V_72 ) ;
F_13 ( V_28 -> V_34 ) ;
F_64 ( V_28 ) ;
}
static void F_65 ( struct V_25 * V_26 )
{
struct V_1 * V_2 = V_26 -> V_1 ;
struct V_27 * V_28 , * V_84 ;
unsigned long V_85 , V_86 ;
F_66 ( V_87 ) ;
F_11 ( & V_2 -> V_24 ) ;
V_86 = V_43 ;
V_85 = ( long ) V_86 - ( long ) V_2 -> V_39 ;
F_67 (sp, tmp, &server->state_owners_lru, so_lru) {
if ( F_68 ( V_28 -> V_88 , V_85 , V_86 ) )
break;
F_69 ( & V_28 -> V_66 , & V_87 ) ;
F_47 ( V_28 ) ;
}
F_12 ( & V_2 -> V_24 ) ;
F_67 (sp, tmp, &doomed, so_lru) {
F_70 ( & V_28 -> V_66 ) ;
F_63 ( V_28 ) ;
}
}
struct V_27 * F_71 ( struct V_25 * V_26 ,
struct V_3 * V_4 ,
T_1 V_82 )
{
struct V_1 * V_2 = V_26 -> V_1 ;
struct V_27 * V_28 , * V_68 ;
F_11 ( & V_2 -> V_24 ) ;
V_28 = F_39 ( V_26 , V_4 ) ;
F_12 ( & V_2 -> V_24 ) ;
if ( V_28 != NULL )
goto V_22;
V_68 = F_58 ( V_26 , V_4 , V_82 ) ;
if ( V_68 == NULL )
goto V_22;
do {
if ( F_72 ( & V_26 -> V_71 , V_82 ) == 0 )
break;
F_11 ( & V_2 -> V_24 ) ;
V_28 = F_42 ( V_68 ) ;
F_12 ( & V_2 -> V_24 ) ;
} while ( V_28 == F_44 ( - V_89 ) );
if ( V_28 != V_68 )
F_63 ( V_68 ) ;
V_22:
F_65 ( V_26 ) ;
return V_28 ;
}
void F_73 ( struct V_27 * V_28 )
{
struct V_25 * V_26 = V_28 -> V_69 ;
struct V_1 * V_2 = V_26 -> V_1 ;
if ( ! F_74 ( & V_28 -> V_67 , & V_2 -> V_24 ) )
return;
V_28 -> V_88 = V_43 ;
F_75 ( & V_28 -> V_66 , & V_26 -> V_90 ) ;
F_12 ( & V_2 -> V_24 ) ;
}
void F_76 ( struct V_25 * V_26 )
{
struct V_1 * V_2 = V_26 -> V_1 ;
struct V_27 * V_28 , * V_84 ;
F_66 ( V_87 ) ;
F_11 ( & V_2 -> V_24 ) ;
F_67 (sp, tmp, &server->state_owners_lru, so_lru) {
F_69 ( & V_28 -> V_66 , & V_87 ) ;
F_47 ( V_28 ) ;
}
F_12 ( & V_2 -> V_24 ) ;
F_67 (sp, tmp, &doomed, so_lru) {
F_70 ( & V_28 -> V_66 ) ;
F_63 ( V_28 ) ;
}
}
static struct V_91 *
F_77 ( void )
{
struct V_91 * V_92 ;
V_92 = F_59 ( sizeof( * V_92 ) , V_93 ) ;
if ( ! V_92 )
return NULL ;
F_60 ( & V_92 -> V_94 , 1 ) ;
F_54 ( & V_92 -> V_95 ) ;
F_53 ( & V_92 -> V_96 ) ;
F_78 ( & V_92 -> V_97 ) ;
return V_92 ;
}
void
F_79 ( struct V_91 * V_92 , T_2 V_98 )
{
if ( V_92 -> V_92 == V_98 )
return;
if ( ( V_98 & V_99 ) != ( V_92 -> V_92 & V_99 ) ) {
if ( V_98 & V_99 )
F_69 ( & V_92 -> V_100 , & V_92 -> V_101 -> V_33 ) ;
else
F_80 ( & V_92 -> V_100 , & V_92 -> V_101 -> V_33 ) ;
}
V_92 -> V_92 = V_98 ;
}
static struct V_91 *
F_81 ( struct V_102 * V_102 , struct V_27 * V_101 )
{
struct V_103 * V_104 = F_82 ( V_102 ) ;
struct V_91 * V_92 ;
F_83 (state, &nfsi->open_states, inode_states) {
if ( V_92 -> V_101 != V_101 )
continue;
if ( F_84 ( & V_92 -> V_94 ) )
return V_92 ;
}
return NULL ;
}
static void
F_85 ( struct V_91 * V_92 )
{
F_64 ( V_92 ) ;
}
struct V_91 *
F_86 ( struct V_102 * V_102 , struct V_27 * V_101 )
{
struct V_91 * V_92 , * V_68 ;
struct V_103 * V_104 = F_82 ( V_102 ) ;
F_11 ( & V_102 -> V_105 ) ;
V_92 = F_81 ( V_102 , V_101 ) ;
F_12 ( & V_102 -> V_105 ) ;
if ( V_92 )
goto V_22;
V_68 = F_77 () ;
F_11 ( & V_101 -> V_83 ) ;
F_11 ( & V_102 -> V_105 ) ;
V_92 = F_81 ( V_102 , V_101 ) ;
if ( V_92 == NULL && V_68 != NULL ) {
V_92 = V_68 ;
V_92 -> V_101 = V_101 ;
F_41 ( & V_101 -> V_67 ) ;
F_87 ( & V_92 -> V_106 , & V_104 -> V_100 ) ;
F_88 ( V_102 ) ;
V_92 -> V_102 = V_102 ;
F_12 ( & V_102 -> V_105 ) ;
F_75 ( & V_92 -> V_100 , & V_101 -> V_33 ) ;
F_12 ( & V_101 -> V_83 ) ;
} else {
F_12 ( & V_102 -> V_105 ) ;
F_12 ( & V_101 -> V_83 ) ;
if ( V_68 )
F_85 ( V_68 ) ;
}
V_22:
return V_92 ;
}
void F_89 ( struct V_91 * V_92 )
{
struct V_102 * V_102 = V_92 -> V_102 ;
struct V_27 * V_101 = V_92 -> V_101 ;
if ( ! F_74 ( & V_92 -> V_94 , & V_101 -> V_83 ) )
return;
F_11 ( & V_102 -> V_105 ) ;
F_70 ( & V_92 -> V_106 ) ;
F_70 ( & V_92 -> V_100 ) ;
F_12 ( & V_102 -> V_105 ) ;
F_12 ( & V_101 -> V_83 ) ;
F_90 ( V_102 ) ;
F_85 ( V_92 ) ;
F_73 ( V_101 ) ;
}
static void F_91 ( struct V_91 * V_92 ,
T_2 V_98 , T_1 V_107 , int V_81 )
{
struct V_27 * V_101 = V_92 -> V_101 ;
int V_108 = 0 ;
T_2 V_109 ;
F_41 ( & V_101 -> V_67 ) ;
F_11 ( & V_101 -> V_83 ) ;
switch ( V_98 & ( V_110 | V_99 ) ) {
case V_110 :
V_92 -> V_111 -- ;
break;
case V_99 :
V_92 -> V_112 -- ;
break;
case V_110 | V_99 :
V_92 -> V_113 -- ;
}
V_109 = V_110 | V_99 ;
if ( V_92 -> V_113 == 0 ) {
if ( V_92 -> V_111 == 0 ) {
V_109 &= ~ V_110 ;
V_108 |= F_2 ( V_114 , & V_92 -> V_77 ) ;
V_108 |= F_2 ( V_115 , & V_92 -> V_77 ) ;
}
if ( V_92 -> V_112 == 0 ) {
V_109 &= ~ V_99 ;
V_108 |= F_2 ( V_116 , & V_92 -> V_77 ) ;
V_108 |= F_2 ( V_115 , & V_92 -> V_77 ) ;
}
if ( V_109 == 0 )
F_6 ( V_117 , & V_92 -> V_77 ) ;
}
F_79 ( V_92 , V_109 ) ;
F_12 ( & V_101 -> V_83 ) ;
if ( ! V_108 ) {
F_89 ( V_92 ) ;
F_73 ( V_101 ) ;
} else {
bool V_118 = F_92 ( V_92 -> V_102 ) ;
F_93 ( V_92 , V_107 , V_81 , V_118 ) ;
}
}
void F_94 ( struct V_91 * V_92 , T_2 V_98 )
{
F_91 ( V_92 , V_98 , V_93 , 0 ) ;
}
void F_95 ( struct V_91 * V_92 , T_2 V_98 )
{
F_91 ( V_92 , V_98 , V_119 , 1 ) ;
}
static struct V_120 *
F_96 ( struct V_91 * V_92 , T_3 V_121 , T_4 V_122 , unsigned int type )
{
struct V_120 * V_30 ;
F_83 (pos, &state->lock_states, ls_locks) {
if ( type != V_123 && V_30 -> V_124 . V_125 != type )
continue;
switch ( V_30 -> V_124 . V_125 ) {
case V_126 :
if ( V_30 -> V_124 . V_127 . V_128 != V_121 )
continue;
break;
case V_129 :
if ( V_30 -> V_124 . V_127 . V_130 != V_122 )
continue;
}
F_41 ( & V_30 -> V_131 ) ;
return V_30 ;
}
return NULL ;
}
static struct V_120 * F_97 ( struct V_91 * V_92 , T_3 V_121 , T_4 V_122 , unsigned int type )
{
struct V_120 * V_132 ;
struct V_25 * V_26 = V_92 -> V_101 -> V_69 ;
V_132 = F_59 ( sizeof( * V_132 ) , V_93 ) ;
if ( V_132 == NULL )
return NULL ;
F_51 ( & V_132 -> V_133 ) ;
F_60 ( & V_132 -> V_131 , 1 ) ;
V_132 -> V_134 = V_92 ;
V_132 -> V_124 . V_125 = type ;
switch ( V_132 -> V_124 . V_125 ) {
case V_129 :
V_132 -> V_124 . V_127 . V_130 = V_122 ;
break;
case V_126 :
V_132 -> V_124 . V_127 . V_128 = V_121 ;
break;
default:
goto V_135;
}
V_132 -> V_133 . V_73 = F_98 ( & V_26 -> V_136 , 0 , 0 , V_93 ) ;
if ( V_132 -> V_133 . V_73 < 0 )
goto V_135;
F_54 ( & V_132 -> V_137 ) ;
return V_132 ;
V_135:
F_64 ( V_132 ) ;
return NULL ;
}
void F_99 ( struct V_25 * V_26 , struct V_120 * V_132 )
{
F_100 ( & V_26 -> V_136 , V_132 -> V_133 . V_73 ) ;
F_56 ( & V_132 -> V_133 ) ;
F_64 ( V_132 ) ;
}
static struct V_120 * F_101 ( struct V_91 * V_92 , T_3 V_101 , T_4 V_138 , unsigned int type )
{
struct V_120 * V_132 , * V_68 = NULL ;
for(; ; ) {
F_11 ( & V_92 -> V_96 ) ;
V_132 = F_96 ( V_92 , V_101 , V_138 , type ) ;
if ( V_132 != NULL )
break;
if ( V_68 != NULL ) {
F_87 ( & V_68 -> V_137 , & V_92 -> V_95 ) ;
F_4 ( V_139 , & V_92 -> V_77 ) ;
V_132 = V_68 ;
V_68 = NULL ;
break;
}
F_12 ( & V_92 -> V_96 ) ;
V_68 = F_97 ( V_92 , V_101 , V_138 , type ) ;
if ( V_68 == NULL )
return NULL ;
}
F_12 ( & V_92 -> V_96 ) ;
if ( V_68 != NULL )
F_99 ( V_92 -> V_101 -> V_69 , V_68 ) ;
return V_132 ;
}
void F_102 ( struct V_120 * V_132 )
{
struct V_91 * V_92 ;
if ( V_132 == NULL )
return;
V_92 = V_132 -> V_134 ;
if ( ! F_74 ( & V_132 -> V_131 , & V_92 -> V_96 ) )
return;
F_70 ( & V_132 -> V_137 ) ;
if ( F_18 ( & V_92 -> V_95 ) )
F_6 ( V_139 , & V_92 -> V_77 ) ;
F_12 ( & V_92 -> V_96 ) ;
if ( V_132 -> V_140 & V_141 ) {
if ( F_103 ( V_132 ) == 0 )
return;
}
F_99 ( V_132 -> V_134 -> V_101 -> V_69 , V_132 ) ;
}
static void F_104 ( struct V_142 * V_143 , struct V_142 * V_144 )
{
struct V_120 * V_132 = V_144 -> V_145 . V_146 . V_101 ;
V_143 -> V_145 . V_146 . V_101 = V_132 ;
F_41 ( & V_132 -> V_131 ) ;
}
static void F_105 ( struct V_142 * V_147 )
{
F_102 ( V_147 -> V_145 . V_146 . V_101 ) ;
}
int F_106 ( struct V_91 * V_92 , struct V_142 * V_147 )
{
struct V_120 * V_132 ;
if ( V_147 -> V_148 != NULL )
return 0 ;
if ( V_147 -> V_149 & V_150 )
V_132 = F_101 ( V_92 , V_147 -> V_121 , 0 , V_126 ) ;
else if ( V_147 -> V_149 & V_151 )
V_132 = F_101 ( V_92 , NULL , V_147 -> V_122 ,
V_129 ) ;
else
return - V_152 ;
if ( V_132 == NULL )
return - V_153 ;
V_147 -> V_145 . V_146 . V_101 = V_132 ;
V_147 -> V_148 = & V_154 ;
return 0 ;
}
static bool F_107 ( T_5 * V_143 , struct V_91 * V_92 ,
T_3 V_121 , T_4 V_122 )
{
struct V_120 * V_132 ;
bool V_59 = false ;
if ( F_2 ( V_139 , & V_92 -> V_77 ) == 0 )
goto V_22;
F_11 ( & V_92 -> V_96 ) ;
V_132 = F_96 ( V_92 , V_121 , V_122 , V_123 ) ;
if ( V_132 != NULL && ( V_132 -> V_140 & V_141 ) != 0 ) {
F_108 ( V_143 , & V_132 -> V_155 ) ;
V_59 = true ;
}
F_12 ( & V_92 -> V_96 ) ;
F_102 ( V_132 ) ;
V_22:
return V_59 ;
}
static void F_109 ( T_5 * V_143 , struct V_91 * V_92 )
{
int V_156 ;
do {
V_156 = F_110 ( & V_92 -> V_97 ) ;
F_108 ( V_143 , & V_92 -> V_157 ) ;
} while ( F_111 ( & V_92 -> V_97 , V_156 ) );
}
void F_112 ( T_5 * V_143 , struct V_91 * V_92 ,
T_2 V_98 , T_3 V_121 , T_4 V_122 )
{
if ( F_113 ( V_143 , V_92 -> V_102 , V_98 ) )
return;
if ( F_107 ( V_143 , V_92 , V_121 , V_122 ) )
return;
F_109 ( V_143 , V_92 ) ;
}
struct V_158 * F_114 ( struct V_74 * V_78 , T_1 V_107 )
{
struct V_158 * V_68 ;
V_68 = F_115 ( sizeof( * V_68 ) , V_107 ) ;
if ( V_68 != NULL ) {
V_68 -> V_159 = V_78 ;
F_54 ( & V_68 -> V_80 ) ;
V_68 -> V_160 = NULL ;
}
return V_68 ;
}
void F_116 ( struct V_158 * V_161 )
{
struct V_74 * V_159 ;
if ( F_18 ( & V_161 -> V_80 ) )
return;
V_159 = V_161 -> V_159 ;
F_11 ( & V_159 -> V_79 ) ;
F_40 ( & V_161 -> V_80 ) ;
if ( ! F_18 ( & V_159 -> V_80 ) ) {
struct V_158 * V_162 ;
V_162 = F_117 ( & V_159 -> V_80 ,
struct V_158 , V_80 ) ;
F_118 ( & V_159 -> V_81 , V_162 -> V_160 ) ;
}
F_12 ( & V_159 -> V_79 ) ;
}
void F_119 ( struct V_158 * V_161 )
{
F_116 ( V_161 ) ;
F_64 ( V_161 ) ;
}
static void F_120 ( int V_12 , struct V_158 * V_161 )
{
F_121 ( F_117 ( & V_161 -> V_159 -> V_80 , struct V_158 , V_80 ) != V_161 ) ;
switch ( V_12 ) {
case 0 :
break;
case - V_163 :
if ( V_161 -> V_159 -> V_77 & V_164 )
return;
F_122 ( L_2
L_3
L_4 ,
V_161 -> V_159 ) ;
case - V_165 :
case - V_166 :
case - V_167 :
case - V_168 :
case - V_169 :
case - V_170 :
return;
} ;
V_161 -> V_159 -> V_78 ++ ;
}
void F_123 ( int V_12 , struct V_158 * V_161 )
{
struct V_27 * V_28 = F_124 ( V_161 -> V_159 ,
struct V_27 , V_72 ) ;
struct V_25 * V_26 = V_28 -> V_69 ;
if ( V_12 == - V_163 )
F_61 ( V_28 ) ;
if ( ! F_125 ( V_26 -> V_1 ) )
F_120 ( V_12 , V_161 ) ;
}
void F_126 ( int V_12 , struct V_158 * V_161 )
{
F_120 ( V_12 , V_161 ) ;
}
int F_127 ( struct V_158 * V_161 , struct V_171 * V_160 )
{
struct V_74 * V_159 = V_161 -> V_159 ;
int V_12 = 0 ;
F_11 ( & V_159 -> V_79 ) ;
V_161 -> V_160 = V_160 ;
if ( F_18 ( & V_161 -> V_80 ) )
F_75 ( & V_161 -> V_80 , & V_159 -> V_80 ) ;
if ( F_117 ( & V_159 -> V_80 , struct V_158 , V_80 ) == V_161 )
goto V_172;
F_128 ( & V_159 -> V_81 , V_160 , NULL ) ;
V_12 = - V_89 ;
V_172:
F_12 ( & V_159 -> V_79 ) ;
return V_12 ;
}
static void F_129 ( struct V_1 * V_2 )
{
F_130 () ;
F_6 ( V_173 , & V_2 -> V_14 ) ;
F_131 () ;
F_132 ( & V_2 -> V_14 , V_173 ) ;
F_133 ( & V_2 -> V_174 ) ;
}
void F_134 ( struct V_1 * V_2 )
{
struct V_175 * V_160 ;
char V_176 [ V_177 + sizeof( L_5 ) + 1 ] ;
if ( F_135 ( V_173 , & V_2 -> V_14 ) != 0 )
return;
F_136 ( V_178 ) ;
F_41 ( & V_2 -> V_179 ) ;
F_20 () ;
snprintf ( V_176 , sizeof( V_176 ) , L_6 ,
F_137 ( V_2 -> V_180 , V_181 ) ) ;
F_22 () ;
V_160 = F_138 ( V_182 , V_2 , V_176 ) ;
if ( F_139 ( V_160 ) ) {
F_140 ( V_183 L_7 ,
V_184 , F_141 ( V_160 ) ) ;
F_129 ( V_2 ) ;
F_142 ( V_2 ) ;
F_143 ( V_178 ) ;
}
}
void F_144 ( struct V_1 * V_2 )
{
if ( ! V_2 )
return;
if ( ! F_2 ( V_185 , & V_2 -> V_14 ) )
F_4 ( V_186 , & V_2 -> V_14 ) ;
F_134 ( V_2 ) ;
}
static void F_145 ( struct V_1 * V_2 )
{
F_4 ( V_185 , & V_2 -> V_14 ) ;
F_146 ( V_2 ) ;
}
void F_147 ( struct V_1 * V_2 )
{
F_145 ( V_2 ) ;
F_134 ( V_2 ) ;
}
static int F_148 ( struct V_1 * V_2 , struct V_91 * V_92 )
{
F_4 ( V_187 , & V_92 -> V_77 ) ;
if ( F_2 ( V_188 , & V_92 -> V_77 ) ) {
F_6 ( V_187 , & V_92 -> V_77 ) ;
return 0 ;
}
F_4 ( V_189 , & V_92 -> V_101 -> V_190 ) ;
F_4 ( V_191 , & V_2 -> V_14 ) ;
return 1 ;
}
static int F_149 ( struct V_1 * V_2 , struct V_91 * V_92 )
{
F_4 ( V_188 , & V_92 -> V_77 ) ;
F_6 ( V_187 , & V_92 -> V_77 ) ;
F_4 ( V_192 , & V_92 -> V_101 -> V_190 ) ;
F_4 ( V_193 , & V_2 -> V_14 ) ;
return 1 ;
}
void F_150 ( const struct V_25 * V_26 , struct V_91 * V_92 )
{
struct V_1 * V_2 = V_26 -> V_1 ;
F_149 ( V_2 , V_92 ) ;
F_134 ( V_2 ) ;
}
void F_151 ( struct V_102 * V_102 ,
const T_5 * V_157 )
{
struct V_1 * V_2 = F_152 ( V_102 ) -> V_1 ;
struct V_103 * V_104 = F_82 ( V_102 ) ;
struct V_194 * V_195 ;
struct V_91 * V_92 ;
bool V_196 = false ;
F_11 ( & V_102 -> V_105 ) ;
F_83 (ctx, &nfsi->open_files, list) {
V_92 = V_195 -> V_92 ;
if ( V_92 == NULL )
continue;
if ( ! F_2 ( V_117 , & V_92 -> V_77 ) )
continue;
if ( ! F_153 ( & V_92 -> V_157 , V_157 ) )
continue;
F_149 ( V_2 , V_92 ) ;
V_196 = true ;
}
F_12 ( & V_102 -> V_105 ) ;
if ( V_196 )
F_134 ( V_2 ) ;
}
static int F_154 ( struct V_91 * V_92 , const struct V_197 * V_198 )
{
struct V_102 * V_102 = V_92 -> V_102 ;
struct V_103 * V_104 = F_82 ( V_102 ) ;
struct V_142 * V_147 ;
int V_12 = 0 ;
if ( V_102 -> V_199 == NULL )
return 0 ;
F_155 ( & V_104 -> V_200 ) ;
F_156 () ;
for ( V_147 = V_102 -> V_199 ; V_147 != NULL ; V_147 = V_147 -> V_201 ) {
if ( ! ( V_147 -> V_149 & ( V_150 | V_151 ) ) )
continue;
if ( F_157 ( V_147 -> V_202 ) -> V_92 != V_92 )
continue;
F_158 () ;
V_12 = V_198 -> V_203 ( V_92 , V_147 ) ;
switch ( V_12 ) {
case 0 :
break;
case - V_204 :
case - V_205 :
case - V_166 :
case - V_167 :
case - V_206 :
case - V_207 :
case - V_165 :
case - V_208 :
case - V_209 :
case - V_210 :
case - V_211 :
goto V_22;
default:
F_140 ( V_183 L_8
L_9 , V_184 , V_12 ) ;
case - V_153 :
case - V_212 :
case - V_213 :
case - V_214 :
V_12 = 0 ;
}
F_156 () ;
}
F_158 () ;
V_22:
F_159 ( & V_104 -> V_200 ) ;
return V_12 ;
}
static int F_160 ( struct V_27 * V_28 , const struct V_197 * V_198 )
{
struct V_91 * V_92 ;
struct V_120 * V_79 ;
int V_12 = 0 ;
V_215:
F_11 ( & V_28 -> V_83 ) ;
F_83 (state, &sp->so_states, open_states) {
if ( ! F_26 ( V_198 -> V_216 , & V_92 -> V_77 ) )
continue;
if ( V_92 -> V_92 == 0 )
continue;
F_41 ( & V_92 -> V_94 ) ;
F_12 ( & V_28 -> V_83 ) ;
V_12 = V_198 -> V_217 ( V_28 , V_92 ) ;
if ( V_12 >= 0 ) {
V_12 = F_154 ( V_92 , V_198 ) ;
if ( V_12 >= 0 ) {
F_11 ( & V_92 -> V_96 ) ;
F_83 (lock, &state->lock_states, ls_locks) {
if ( ! ( V_79 -> V_140 & V_141 ) )
F_122 ( L_10
L_11
L_12 , V_184 ) ;
}
F_12 ( & V_92 -> V_96 ) ;
F_89 ( V_92 ) ;
goto V_215;
}
}
switch ( V_12 ) {
default:
F_140 ( V_183 L_8
L_9 , V_184 , V_12 ) ;
case - V_218 :
case - V_153 :
case - V_204 :
memset ( & V_92 -> V_157 , 0 ,
sizeof( V_92 -> V_157 ) ) ;
V_92 -> V_92 = 0 ;
break;
case - V_219 :
break;
case - V_205 :
case - V_166 :
case - V_167 :
case - V_213 :
case - V_214 :
F_149 ( V_28 -> V_69 -> V_1 , V_92 ) ;
break;
case - V_206 :
case - V_207 :
F_149 ( V_28 -> V_69 -> V_1 , V_92 ) ;
case - V_165 :
case - V_208 :
case - V_209 :
case - V_210 :
case - V_211 :
goto V_220;
}
F_89 ( V_92 ) ;
goto V_215;
}
F_12 ( & V_28 -> V_83 ) ;
return 0 ;
V_220:
F_89 ( V_92 ) ;
return V_12 ;
}
static void F_161 ( struct V_91 * V_92 )
{
struct V_120 * V_79 ;
F_6 ( V_117 , & V_92 -> V_77 ) ;
F_6 ( V_114 , & V_92 -> V_77 ) ;
F_6 ( V_116 , & V_92 -> V_77 ) ;
F_6 ( V_115 , & V_92 -> V_77 ) ;
F_11 ( & V_92 -> V_96 ) ;
F_83 (lock, &state->lock_states, ls_locks) {
V_79 -> V_133 . V_77 = 0 ;
V_79 -> V_140 &= ~ V_141 ;
}
F_12 ( & V_92 -> V_96 ) ;
}
static void F_162 ( struct V_25 * V_26 ,
int (* F_163)( struct V_1 * V_2 , struct V_91 * V_92 ) )
{
struct V_1 * V_2 = V_26 -> V_1 ;
struct V_27 * V_28 ;
struct V_29 * V_30 ;
struct V_91 * V_92 ;
F_11 ( & V_2 -> V_24 ) ;
for ( V_30 = F_15 ( & V_26 -> V_31 ) ;
V_30 != NULL ;
V_30 = F_16 ( V_30 ) ) {
V_28 = F_17 ( V_30 , struct V_27 , V_32 ) ;
V_28 -> V_72 . V_77 = 0 ;
F_11 ( & V_28 -> V_83 ) ;
F_83 (state, &sp->so_states, open_states) {
if ( F_163 ( V_2 , V_92 ) )
F_161 ( V_92 ) ;
}
F_12 ( & V_28 -> V_83 ) ;
}
F_12 ( & V_2 -> V_24 ) ;
}
static void F_164 ( struct V_1 * V_2 ,
int (* F_163)( struct V_1 * V_2 , struct V_91 * V_92 ) )
{
struct V_25 * V_26 ;
F_20 () ;
F_21 (server, &clp->cl_superblocks, client_link)
F_162 ( V_26 , F_163 ) ;
F_22 () ;
}
static void F_165 ( struct V_1 * V_2 )
{
F_166 ( V_2 ) ;
F_164 ( V_2 , F_148 ) ;
}
static void F_167 ( struct V_1 * V_2 ,
const struct V_197 * V_198 )
{
if ( V_198 -> V_221 )
( void ) V_198 -> V_221 ( V_2 ) ;
}
static void F_168 ( struct V_25 * V_26 )
{
struct V_1 * V_2 = V_26 -> V_1 ;
struct V_27 * V_28 ;
struct V_29 * V_30 ;
struct V_91 * V_92 ;
F_11 ( & V_2 -> V_24 ) ;
for ( V_30 = F_15 ( & V_26 -> V_31 ) ;
V_30 != NULL ;
V_30 = F_16 ( V_30 ) ) {
V_28 = F_17 ( V_30 , struct V_27 , V_32 ) ;
F_11 ( & V_28 -> V_83 ) ;
F_83 (state, &sp->so_states, open_states) {
if ( ! F_26 ( V_187 ,
& V_92 -> V_77 ) )
continue;
F_149 ( V_2 , V_92 ) ;
}
F_12 ( & V_28 -> V_83 ) ;
}
F_12 ( & V_2 -> V_24 ) ;
}
static int F_169 ( struct V_1 * V_2 )
{
struct V_25 * V_26 ;
if ( ! F_26 ( V_191 , & V_2 -> V_14 ) )
return 0 ;
F_20 () ;
F_21 (server, &clp->cl_superblocks, client_link)
F_168 ( V_26 ) ;
F_22 () ;
F_170 ( V_2 ) ;
return 1 ;
}
static void F_171 ( struct V_1 * V_2 )
{
if ( ! F_169 ( V_2 ) )
return;
F_167 ( V_2 , V_2 -> V_222 -> V_223 ) ;
}
static void F_172 ( struct V_1 * V_2 )
{
F_166 ( V_2 ) ;
F_170 ( V_2 ) ;
}
static void F_173 ( struct V_1 * V_2 )
{
F_172 ( V_2 ) ;
F_164 ( V_2 , F_149 ) ;
}
static void F_174 ( const char * V_224 )
{
F_175 ( V_225 L_13
L_14
L_15 ,
V_224 ) ;
}
static int F_176 ( struct V_1 * V_2 , int error )
{
switch ( error ) {
case 0 :
break;
case - V_226 :
F_145 ( V_2 ) ;
break;
case - V_207 :
F_171 ( V_2 ) ;
break;
case - V_165 :
case - V_227 :
F_4 ( V_185 , & V_2 -> V_14 ) ;
F_169 ( V_2 ) ;
F_165 ( V_2 ) ;
break;
case - V_206 :
F_4 ( V_185 , & V_2 -> V_14 ) ;
F_173 ( V_2 ) ;
break;
case - V_208 :
case - V_209 :
case - V_210 :
case - V_228 :
case - V_211 :
case - V_229 :
case - V_230 :
F_4 ( V_231 , & V_2 -> V_14 ) ;
break;
case - V_219 :
F_174 ( V_2 -> V_232 ) ;
break;
default:
return error ;
}
return 0 ;
}
static int F_177 ( struct V_1 * V_2 , const struct V_197 * V_198 )
{
struct V_27 * V_28 ;
struct V_25 * V_26 ;
struct V_29 * V_30 ;
int V_12 = 0 ;
V_215:
F_20 () ;
F_21 (server, &clp->cl_superblocks, client_link) {
F_76 ( V_26 ) ;
F_11 ( & V_2 -> V_24 ) ;
for ( V_30 = F_15 ( & V_26 -> V_31 ) ;
V_30 != NULL ;
V_30 = F_16 ( V_30 ) ) {
V_28 = F_17 ( V_30 ,
struct V_27 , V_32 ) ;
if ( ! F_26 ( V_198 -> V_233 ,
& V_28 -> V_190 ) )
continue;
F_41 ( & V_28 -> V_67 ) ;
F_12 ( & V_2 -> V_24 ) ;
F_22 () ;
V_12 = F_160 ( V_28 , V_198 ) ;
if ( V_12 < 0 ) {
F_4 ( V_198 -> V_233 , & V_28 -> V_190 ) ;
F_73 ( V_28 ) ;
return F_176 ( V_2 , V_12 ) ;
}
F_73 ( V_28 ) ;
goto V_215;
}
F_12 ( & V_2 -> V_24 ) ;
}
F_22 () ;
return V_12 ;
}
static int F_178 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
const struct V_234 * V_198 =
V_2 -> V_222 -> V_235 ;
int V_12 ;
if ( F_2 ( V_185 , & V_2 -> V_14 ) )
return 0 ;
F_11 ( & V_2 -> V_24 ) ;
V_4 = V_198 -> V_236 ( V_2 ) ;
F_12 ( & V_2 -> V_24 ) ;
if ( V_4 == NULL ) {
V_4 = F_38 ( V_2 ) ;
V_12 = - V_237 ;
if ( V_4 == NULL )
goto V_22;
}
V_12 = V_198 -> V_238 ( V_2 , V_4 ) ;
F_13 ( V_4 ) ;
V_22:
return F_176 ( V_2 , V_12 ) ;
}
static int F_179 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
const struct V_197 * V_198 =
V_2 -> V_222 -> V_223 ;
int V_12 = - V_218 ;
V_4 = V_198 -> V_239 ( V_2 ) ;
if ( V_4 != NULL ) {
V_12 = V_198 -> V_240 ( V_2 , V_4 ) ;
F_13 ( V_4 ) ;
if ( V_12 == - V_241 && V_4 == V_2 -> V_23 ) {
F_10 ( V_2 ) ;
V_12 = - V_89 ;
}
if ( V_12 == - V_242 )
V_12 = - V_243 ;
}
return V_12 ;
}
void F_180 ( struct V_44 * V_244 )
{
struct V_1 * V_2 = V_244 -> V_2 ;
F_4 ( V_231 , & V_2 -> V_14 ) ;
F_144 ( V_2 ) ;
}
void F_181 ( struct V_1 * V_2 )
{
F_4 ( V_245 , & V_2 -> V_14 ) ;
F_134 ( V_2 ) ;
}
static void F_182 ( struct V_1 * V_2 )
{
if ( F_135 ( V_185 , & V_2 -> V_14 ) == 0 ) {
V_2 -> V_246 = V_247 ;
F_173 ( V_2 ) ;
F_134 ( V_2 ) ;
}
}
static void F_183 ( struct V_1 * V_2 )
{
if ( F_135 ( V_185 , & V_2 -> V_14 ) == 0 ) {
F_165 ( V_2 ) ;
F_134 ( V_2 ) ;
}
}
static void F_184 ( struct V_1 * V_2 )
{
F_182 ( V_2 ) ;
}
static void F_185 ( struct V_1 * V_2 )
{
F_146 ( V_2 ) ;
}
static void F_186 ( struct V_1 * V_2 )
{
F_146 ( V_2 ) ;
if ( F_135 ( V_231 , & V_2 -> V_14 ) == 0 )
F_134 ( V_2 ) ;
}
void F_187 ( struct V_1 * V_2 , T_6 V_77 )
{
if ( ! V_77 )
return;
if ( V_77 & V_248 )
F_183 ( V_2 ) ;
if ( V_77 & ( V_249 |
V_250 |
V_251 |
V_252 ) )
F_184 ( V_2 ) ;
if ( V_77 & V_253 )
F_185 ( V_2 ) ;
if ( V_77 & ( V_254 |
V_255 |
V_256 ) )
F_186 ( V_2 ) ;
}
static int F_188 ( struct V_1 * V_2 )
{
int V_12 ;
F_31 ( V_2 ) ;
V_12 = F_189 ( V_2 -> V_46 ) ;
if ( V_12 && V_12 != - V_208 &&
V_12 != - V_228 ) {
V_12 = F_176 ( V_2 , V_12 ) ;
goto V_22;
}
memset ( V_2 -> V_46 -> V_257 . V_258 , 0 , V_259 ) ;
V_12 = F_34 ( V_2 ) ;
if ( V_12 ) {
V_12 = F_176 ( V_2 , V_12 ) ;
goto V_22;
}
F_6 ( V_231 , & V_2 -> V_14 ) ;
F_6 ( V_245 , & V_2 -> V_14 ) ;
if ( ! F_2 ( V_185 , & V_2 -> V_14 ) )
F_23 ( V_2 ) ;
V_22:
return V_12 ;
}
static int F_190 ( struct V_1 * V_2 )
{
struct V_47 * V_260 = & V_2 -> V_46 -> V_50 ;
struct V_261 * V_262 = & V_2 -> V_46 -> V_262 ;
struct V_263 * V_68 , * V_264 ;
int V_265 ;
F_31 ( V_2 ) ;
V_68 = F_115 ( V_260 -> V_266 * sizeof( struct V_263 ) ,
V_93 ) ;
if ( ! V_68 )
return - V_153 ;
F_11 ( & V_260 -> V_53 ) ;
for ( V_265 = 0 ; V_265 < V_260 -> V_266 ; V_265 ++ )
V_68 [ V_265 ] . V_267 = V_260 -> V_268 [ V_265 ] . V_267 ;
V_264 = V_260 -> V_268 ;
V_260 -> V_268 = V_68 ;
V_260 -> V_49 = V_260 -> V_266 ;
V_260 -> V_266 = 0 ;
V_262 -> V_269 = V_260 -> V_49 ;
F_12 ( & V_260 -> V_53 ) ;
F_64 ( V_264 ) ;
F_25 ( V_2 ) ;
return 0 ;
}
static int F_188 ( struct V_1 * V_2 ) { return 0 ; }
static int F_25 ( struct V_1 * V_2 ) { return 0 ; }
static int F_190 ( struct V_1 * V_2 ) { return 0 ; }
static void F_191 ( struct V_1 * V_2 , int V_12 )
{
switch ( V_12 ) {
case - V_270 :
case - V_165 :
F_6 ( V_13 , & V_2 -> V_14 ) ;
break;
case - V_271 :
case - V_272 :
case - V_89 :
F_192 ( 1 ) ;
break;
case - V_219 :
F_174 ( V_2 -> V_232 ) ;
case - V_273 :
default:
return;
}
F_4 ( V_185 , & V_2 -> V_14 ) ;
}
static void F_193 ( struct V_1 * V_2 )
{
int V_12 = 0 ;
do {
if ( F_26 ( V_185 , & V_2 -> V_14 ) ) {
V_12 = F_179 ( V_2 ) ;
if ( V_12 ) {
F_191 ( V_2 , V_12 ) ;
if ( F_2 ( V_185 ,
& V_2 -> V_14 ) )
continue;
if ( V_2 -> V_274 ==
V_275 )
F_35 ( V_2 , V_12 ) ;
goto V_276;
}
F_6 ( V_186 , & V_2 -> V_14 ) ;
if ( F_26 ( V_277 ,
& V_2 -> V_14 ) )
F_173 ( V_2 ) ;
else
F_4 ( V_191 ,
& V_2 -> V_14 ) ;
F_194 ( V_2 ) ;
}
if ( F_26 ( V_186 , & V_2 -> V_14 ) ) {
V_12 = F_178 ( V_2 ) ;
if ( V_12 < 0 )
goto V_276;
if ( F_2 ( V_185 , & V_2 -> V_14 ) )
continue;
}
if ( F_26 ( V_231 , & V_2 -> V_14 )
&& F_125 ( V_2 ) ) {
V_12 = F_188 ( V_2 ) ;
if ( F_2 ( V_185 , & V_2 -> V_14 ) )
continue;
if ( V_12 < 0 )
goto V_276;
}
if ( F_2 ( V_191 , & V_2 -> V_14 ) ) {
V_12 = F_177 ( V_2 ,
V_2 -> V_222 -> V_223 ) ;
if ( F_2 ( V_185 , & V_2 -> V_14 ) ||
F_2 ( V_231 , & V_2 -> V_14 ) )
continue;
F_171 ( V_2 ) ;
if ( F_2 ( V_193 , & V_2 -> V_14 ) )
continue;
if ( V_12 < 0 )
goto V_276;
}
if ( F_26 ( V_193 , & V_2 -> V_14 ) ) {
V_12 = F_177 ( V_2 ,
V_2 -> V_222 -> V_278 ) ;
if ( F_2 ( V_185 , & V_2 -> V_14 ) ||
F_2 ( V_231 , & V_2 -> V_14 ) ||
F_2 ( V_191 , & V_2 -> V_14 ) )
continue;
if ( V_12 < 0 )
goto V_276;
}
F_25 ( V_2 ) ;
if ( F_26 ( V_279 , & V_2 -> V_14 ) ) {
F_195 ( V_2 ) ;
continue;
}
if ( F_26 ( V_245 , & V_2 -> V_14 )
&& F_125 ( V_2 ) ) {
V_12 = F_190 ( V_2 ) ;
if ( V_12 < 0 )
goto V_276;
continue;
}
F_129 ( V_2 ) ;
if ( V_2 -> V_14 == 0 )
break;
if ( F_135 ( V_173 , & V_2 -> V_14 ) != 0 )
break;
} while ( F_196 ( & V_2 -> V_179 ) > 1 );
return;
V_276:
F_122 ( L_16
L_17 , V_2 -> V_232 , - V_12 ) ;
F_25 ( V_2 ) ;
F_129 ( V_2 ) ;
}
static int V_182 ( void * V_280 )
{
struct V_1 * V_2 = V_280 ;
F_197 ( V_281 ) ;
F_193 ( V_2 ) ;
F_142 ( V_2 ) ;
F_198 ( 0 ) ;
return 0 ;
}
