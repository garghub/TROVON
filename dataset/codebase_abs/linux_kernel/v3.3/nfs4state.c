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
F_20 () ;
F_21 (server, &clp->cl_superblocks, client_link) {
V_4 = F_14 ( V_26 ) ;
if ( V_4 != NULL )
break;
}
F_22 () ;
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
int V_47 ;
if ( V_45 == NULL )
return;
if ( F_26 ( V_48 , & V_45 -> V_49 ) ) {
F_11 ( & V_45 -> V_50 . V_51 ) ;
V_47 = V_45 -> V_50 . V_47 ;
while ( V_47 -- ) {
struct V_52 * V_53 ;
V_53 = F_27 ( & V_45 -> V_50 .
V_54 ) ;
if ( ! V_53 )
break;
F_28 ( V_53 , V_55 ) ;
}
F_12 ( & V_45 -> V_50 . V_51 ) ;
}
}
static int F_29 ( struct V_56 * V_57 )
{
F_11 ( & V_57 -> V_51 ) ;
if ( V_57 -> V_58 != - 1 ) {
F_30 ( V_57 -> V_59 ) ;
F_12 ( & V_57 -> V_51 ) ;
return F_31 ( & V_57 -> V_59 ) ;
}
F_12 ( & V_57 -> V_51 ) ;
return 0 ;
}
static int F_32 ( struct V_1 * V_2 )
{
struct V_44 * V_45 = V_2 -> V_46 ;
int V_60 = 0 ;
F_4 ( V_48 , & V_45 -> V_49 ) ;
V_60 = F_29 ( & V_45 -> V_61 ) ;
if ( V_60 )
return V_60 ;
return F_29 ( & V_45 -> V_50 ) ;
}
int F_33 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
int V_12 ;
if ( F_2 ( V_13 , & V_2 -> V_14 ) )
goto V_15;
F_32 ( V_2 ) ;
V_12 = F_34 ( V_2 , V_4 ) ;
if ( V_12 != 0 )
goto V_22;
F_4 ( V_13 , & V_2 -> V_14 ) ;
V_15:
V_12 = F_35 ( V_2 ) ;
if ( V_12 != 0 )
goto V_22;
F_6 ( V_13 , & V_2 -> V_14 ) ;
F_23 ( V_2 ) ;
F_36 ( V_2 , V_62 ) ;
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
static void F_40 ( struct V_63 * V_64 ,
struct V_65 * V_66 ,
T_1 V_67 , int V_68 )
{
struct V_29 * * V_69 , * V_70 ;
struct V_65 * V_30 ;
T_1 V_71 = ~ 0ULL ;
if ( V_68 < 64 )
V_71 = ( 1ULL << V_68 ) - 1ULL ;
F_41 ( & V_66 -> V_72 , sizeof( V_66 -> V_72 ) ) ;
V_66 -> V_72 &= V_71 ;
if ( V_66 -> V_72 < V_67 )
V_66 -> V_72 += V_67 ;
V_73:
V_69 = & V_64 -> V_29 ;
V_70 = NULL ;
while ( * V_69 != NULL ) {
V_70 = * V_69 ;
V_30 = F_17 ( V_70 , struct V_65 , V_29 ) ;
if ( V_66 -> V_72 < V_30 -> V_72 )
V_69 = & ( * V_69 ) -> V_74 ;
else if ( V_66 -> V_72 > V_30 -> V_72 )
V_69 = & ( * V_69 ) -> V_75 ;
else
goto V_76;
}
F_42 ( & V_66 -> V_29 , V_70 , V_69 ) ;
F_43 ( & V_66 -> V_29 , V_64 ) ;
return;
V_76:
for (; ; ) {
V_66 -> V_72 ++ ;
if ( V_66 -> V_72 < V_67 || ( V_66 -> V_72 & V_71 ) != V_66 -> V_72 ) {
V_66 -> V_72 = V_67 ;
break;
}
V_70 = F_16 ( V_70 ) ;
if ( V_70 == NULL )
break;
V_30 = F_17 ( V_70 , struct V_65 , V_29 ) ;
if ( V_66 -> V_72 < V_30 -> V_72 )
break;
}
goto V_73;
}
static void F_44 ( struct V_63 * V_64 , struct V_65 * V_72 )
{
F_45 ( & V_72 -> V_29 , V_64 ) ;
}
static struct V_27 *
F_46 ( struct V_25 * V_26 , struct V_3 * V_4 )
{
struct V_29 * * V_69 = & V_26 -> V_31 . V_29 ,
* V_70 = NULL ;
struct V_27 * V_28 ;
while ( * V_69 != NULL ) {
V_70 = * V_69 ;
V_28 = F_17 ( V_70 , struct V_27 , V_32 ) ;
if ( V_4 < V_28 -> V_34 )
V_69 = & V_70 -> V_74 ;
else if ( V_4 > V_28 -> V_34 )
V_69 = & V_70 -> V_75 ;
else {
if ( ! F_18 ( & V_28 -> V_77 ) )
F_47 ( & V_28 -> V_77 ) ;
F_48 ( & V_28 -> V_78 ) ;
return V_28 ;
}
}
return NULL ;
}
static struct V_27 *
F_49 ( struct V_27 * V_66 )
{
struct V_25 * V_26 = V_66 -> V_79 ;
struct V_29 * * V_69 = & V_26 -> V_31 . V_29 ,
* V_70 = NULL ;
struct V_27 * V_28 ;
while ( * V_69 != NULL ) {
V_70 = * V_69 ;
V_28 = F_17 ( V_70 , struct V_27 , V_32 ) ;
if ( V_66 -> V_34 < V_28 -> V_34 )
V_69 = & V_70 -> V_74 ;
else if ( V_66 -> V_34 > V_28 -> V_34 )
V_69 = & V_70 -> V_75 ;
else {
if ( ! F_18 ( & V_28 -> V_77 ) )
F_47 ( & V_28 -> V_77 ) ;
F_48 ( & V_28 -> V_78 ) ;
return V_28 ;
}
}
F_40 ( & V_26 -> V_80 ,
& V_66 -> V_81 , 1 , 64 ) ;
F_42 ( & V_66 -> V_32 , V_70 , V_69 ) ;
F_43 ( & V_66 -> V_32 , & V_26 -> V_31 ) ;
return V_66 ;
}
static void
F_50 ( struct V_27 * V_28 )
{
struct V_25 * V_26 = V_28 -> V_79 ;
if ( ! F_51 ( & V_28 -> V_32 ) )
F_45 ( & V_28 -> V_32 , & V_26 -> V_31 ) ;
F_44 ( & V_26 -> V_80 , & V_28 -> V_81 ) ;
}
static struct V_27 *
F_52 ( void )
{
struct V_27 * V_28 ;
V_28 = F_53 ( sizeof( * V_28 ) , V_82 ) ;
if ( ! V_28 )
return NULL ;
F_54 ( & V_28 -> V_83 ) ;
F_55 ( & V_28 -> V_33 ) ;
F_56 ( & V_28 -> V_84 . V_85 , L_1 ) ;
V_28 -> V_86 . V_87 = & V_28 -> V_84 ;
F_54 ( & V_28 -> V_84 . V_88 ) ;
F_55 ( & V_28 -> V_84 . V_89 ) ;
F_57 ( & V_28 -> V_78 , 1 ) ;
F_55 ( & V_28 -> V_77 ) ;
return V_28 ;
}
static void
F_58 ( struct V_27 * V_28 )
{
if ( ! F_51 ( & V_28 -> V_32 ) ) {
struct V_25 * V_26 = V_28 -> V_79 ;
struct V_1 * V_2 = V_26 -> V_1 ;
F_11 ( & V_2 -> V_24 ) ;
F_45 ( & V_28 -> V_32 , & V_26 -> V_31 ) ;
F_59 ( & V_28 -> V_32 ) ;
F_12 ( & V_2 -> V_24 ) ;
}
}
static void F_60 ( struct V_27 * V_28 )
{
F_61 ( & V_28 -> V_84 . V_85 ) ;
F_13 ( V_28 -> V_34 ) ;
F_62 ( V_28 ) ;
}
static void F_63 ( struct V_25 * V_26 )
{
struct V_1 * V_2 = V_26 -> V_1 ;
struct V_27 * V_28 , * V_90 ;
unsigned long V_91 , V_92 ;
F_64 ( V_93 ) ;
F_11 ( & V_2 -> V_24 ) ;
V_92 = V_43 ;
V_91 = ( long ) V_92 - ( long ) V_2 -> V_39 ;
F_65 (sp, tmp, &server->state_owners_lru, so_lru) {
if ( F_66 ( V_28 -> V_94 , V_91 , V_92 ) )
break;
F_67 ( & V_28 -> V_77 , & V_93 ) ;
F_50 ( V_28 ) ;
}
F_12 ( & V_2 -> V_24 ) ;
F_65 (sp, tmp, &doomed, so_lru) {
F_68 ( & V_28 -> V_77 ) ;
F_60 ( V_28 ) ;
}
}
struct V_27 * F_69 ( struct V_25 * V_26 ,
struct V_3 * V_4 )
{
struct V_1 * V_2 = V_26 -> V_1 ;
struct V_27 * V_28 , * V_66 ;
F_11 ( & V_2 -> V_24 ) ;
V_28 = F_46 ( V_26 , V_4 ) ;
F_12 ( & V_2 -> V_24 ) ;
if ( V_28 != NULL )
goto V_22;
V_66 = F_52 () ;
if ( V_66 == NULL )
goto V_22;
V_66 -> V_79 = V_26 ;
V_66 -> V_34 = V_4 ;
F_11 ( & V_2 -> V_24 ) ;
V_28 = F_49 ( V_66 ) ;
F_12 ( & V_2 -> V_24 ) ;
if ( V_28 == V_66 )
F_9 ( V_4 ) ;
else {
F_61 ( & V_66 -> V_84 . V_85 ) ;
F_62 ( V_66 ) ;
}
V_22:
F_63 ( V_26 ) ;
return V_28 ;
}
void F_70 ( struct V_27 * V_28 )
{
struct V_25 * V_26 = V_28 -> V_79 ;
struct V_1 * V_2 = V_26 -> V_1 ;
if ( ! F_71 ( & V_28 -> V_78 , & V_2 -> V_24 ) )
return;
if ( ! F_51 ( & V_28 -> V_32 ) ) {
V_28 -> V_94 = V_43 ;
F_72 ( & V_28 -> V_77 , & V_26 -> V_95 ) ;
F_12 ( & V_2 -> V_24 ) ;
} else {
F_50 ( V_28 ) ;
F_12 ( & V_2 -> V_24 ) ;
F_60 ( V_28 ) ;
}
}
void F_73 ( struct V_25 * V_26 )
{
struct V_1 * V_2 = V_26 -> V_1 ;
struct V_27 * V_28 , * V_90 ;
F_64 ( V_93 ) ;
F_11 ( & V_2 -> V_24 ) ;
F_65 (sp, tmp, &server->state_owners_lru, so_lru) {
F_67 ( & V_28 -> V_77 , & V_93 ) ;
F_50 ( V_28 ) ;
}
F_12 ( & V_2 -> V_24 ) ;
F_65 (sp, tmp, &doomed, so_lru) {
F_68 ( & V_28 -> V_77 ) ;
F_60 ( V_28 ) ;
}
}
static struct V_96 *
F_74 ( void )
{
struct V_96 * V_97 ;
V_97 = F_53 ( sizeof( * V_97 ) , V_82 ) ;
if ( ! V_97 )
return NULL ;
F_57 ( & V_97 -> V_98 , 1 ) ;
F_55 ( & V_97 -> V_99 ) ;
F_54 ( & V_97 -> V_100 ) ;
F_75 ( & V_97 -> V_101 ) ;
return V_97 ;
}
void
F_76 ( struct V_96 * V_97 , T_2 V_102 )
{
if ( V_97 -> V_97 == V_102 )
return;
if ( ( V_102 & V_103 ) != ( V_97 -> V_97 & V_103 ) ) {
if ( V_102 & V_103 )
F_67 ( & V_97 -> V_104 , & V_97 -> V_105 -> V_33 ) ;
else
F_77 ( & V_97 -> V_104 , & V_97 -> V_105 -> V_33 ) ;
}
V_97 -> V_97 = V_102 ;
}
static struct V_96 *
F_78 ( struct V_106 * V_106 , struct V_27 * V_105 )
{
struct V_107 * V_108 = F_79 ( V_106 ) ;
struct V_96 * V_97 ;
F_80 (state, &nfsi->open_states, inode_states) {
if ( V_97 -> V_105 != V_105 )
continue;
if ( F_81 ( & V_97 -> V_98 ) )
return V_97 ;
}
return NULL ;
}
static void
F_82 ( struct V_96 * V_97 )
{
F_62 ( V_97 ) ;
}
struct V_96 *
F_83 ( struct V_106 * V_106 , struct V_27 * V_105 )
{
struct V_96 * V_97 , * V_66 ;
struct V_107 * V_108 = F_79 ( V_106 ) ;
F_11 ( & V_106 -> V_109 ) ;
V_97 = F_78 ( V_106 , V_105 ) ;
F_12 ( & V_106 -> V_109 ) ;
if ( V_97 )
goto V_22;
V_66 = F_74 () ;
F_11 ( & V_105 -> V_83 ) ;
F_11 ( & V_106 -> V_109 ) ;
V_97 = F_78 ( V_106 , V_105 ) ;
if ( V_97 == NULL && V_66 != NULL ) {
V_97 = V_66 ;
V_97 -> V_105 = V_105 ;
F_48 ( & V_105 -> V_78 ) ;
F_84 ( & V_97 -> V_110 , & V_108 -> V_104 ) ;
F_85 ( V_106 ) ;
V_97 -> V_106 = V_106 ;
F_12 ( & V_106 -> V_109 ) ;
F_72 ( & V_97 -> V_104 , & V_105 -> V_33 ) ;
F_12 ( & V_105 -> V_83 ) ;
} else {
F_12 ( & V_106 -> V_109 ) ;
F_12 ( & V_105 -> V_83 ) ;
if ( V_66 )
F_82 ( V_66 ) ;
}
V_22:
return V_97 ;
}
void F_86 ( struct V_96 * V_97 )
{
struct V_106 * V_106 = V_97 -> V_106 ;
struct V_27 * V_105 = V_97 -> V_105 ;
if ( ! F_71 ( & V_97 -> V_98 , & V_105 -> V_83 ) )
return;
F_11 ( & V_106 -> V_109 ) ;
F_68 ( & V_97 -> V_110 ) ;
F_68 ( & V_97 -> V_104 ) ;
F_12 ( & V_106 -> V_109 ) ;
F_12 ( & V_105 -> V_83 ) ;
F_87 ( V_106 ) ;
F_82 ( V_97 ) ;
F_70 ( V_105 ) ;
}
static void F_88 ( struct V_96 * V_97 ,
T_2 V_102 , T_3 V_111 , int V_85 )
{
struct V_27 * V_105 = V_97 -> V_105 ;
int V_112 = 0 ;
T_2 V_113 ;
F_48 ( & V_105 -> V_78 ) ;
F_11 ( & V_105 -> V_83 ) ;
switch ( V_102 & ( V_114 | V_103 ) ) {
case V_114 :
V_97 -> V_115 -- ;
break;
case V_103 :
V_97 -> V_116 -- ;
break;
case V_114 | V_103 :
V_97 -> V_117 -- ;
}
V_113 = V_114 | V_103 ;
if ( V_97 -> V_117 == 0 ) {
if ( V_97 -> V_115 == 0 ) {
V_113 &= ~ V_114 ;
V_112 |= F_2 ( V_118 , & V_97 -> V_119 ) ;
V_112 |= F_2 ( V_120 , & V_97 -> V_119 ) ;
}
if ( V_97 -> V_116 == 0 ) {
V_113 &= ~ V_103 ;
V_112 |= F_2 ( V_121 , & V_97 -> V_119 ) ;
V_112 |= F_2 ( V_120 , & V_97 -> V_119 ) ;
}
if ( V_113 == 0 )
F_6 ( V_122 , & V_97 -> V_119 ) ;
}
F_76 ( V_97 , V_113 ) ;
F_12 ( & V_105 -> V_83 ) ;
if ( ! V_112 ) {
F_86 ( V_97 ) ;
F_70 ( V_105 ) ;
} else {
bool V_123 = F_89 ( V_97 -> V_106 ) ;
F_90 ( V_97 , V_111 , V_85 , V_123 ) ;
}
}
void F_91 ( struct V_96 * V_97 , T_2 V_102 )
{
F_88 ( V_97 , V_102 , V_82 , 0 ) ;
}
void F_92 ( struct V_96 * V_97 , T_2 V_102 )
{
F_88 ( V_97 , V_102 , V_124 , 1 ) ;
}
static struct V_125 *
F_93 ( struct V_96 * V_97 , T_4 V_126 , T_5 V_127 , unsigned int type )
{
struct V_125 * V_30 ;
F_80 (pos, &state->lock_states, ls_locks) {
if ( type != V_128 && V_30 -> V_129 . V_130 != type )
continue;
switch ( V_30 -> V_129 . V_130 ) {
case V_131 :
if ( V_30 -> V_129 . V_132 . V_133 != V_126 )
continue;
break;
case V_134 :
if ( V_30 -> V_129 . V_132 . V_135 != V_127 )
continue;
}
F_48 ( & V_30 -> V_136 ) ;
return V_30 ;
}
return NULL ;
}
static struct V_125 * F_94 ( struct V_96 * V_97 , T_4 V_126 , T_5 V_127 , unsigned int type )
{
struct V_125 * V_137 ;
struct V_25 * V_26 = V_97 -> V_105 -> V_79 ;
struct V_1 * V_2 = V_26 -> V_1 ;
V_137 = F_53 ( sizeof( * V_137 ) , V_82 ) ;
if ( V_137 == NULL )
return NULL ;
F_56 ( & V_137 -> V_138 . V_85 , L_2 ) ;
F_54 ( & V_137 -> V_138 . V_88 ) ;
F_55 ( & V_137 -> V_138 . V_89 ) ;
V_137 -> V_139 . V_87 = & V_137 -> V_138 ;
F_57 ( & V_137 -> V_136 , 1 ) ;
V_137 -> V_140 = V_97 ;
V_137 -> V_129 . V_130 = type ;
switch ( V_137 -> V_129 . V_130 ) {
case V_134 :
V_137 -> V_129 . V_132 . V_135 = V_127 ;
break;
case V_131 :
V_137 -> V_129 . V_132 . V_133 = V_126 ;
break;
default:
F_62 ( V_137 ) ;
return NULL ;
}
F_11 ( & V_2 -> V_24 ) ;
F_40 ( & V_26 -> V_141 , & V_137 -> V_142 , 1 , 64 ) ;
F_12 ( & V_2 -> V_24 ) ;
F_55 ( & V_137 -> V_143 ) ;
return V_137 ;
}
static void F_95 ( struct V_125 * V_137 )
{
struct V_25 * V_26 = V_137 -> V_140 -> V_105 -> V_79 ;
struct V_1 * V_2 = V_26 -> V_1 ;
F_11 ( & V_2 -> V_24 ) ;
F_44 ( & V_26 -> V_141 , & V_137 -> V_142 ) ;
F_12 ( & V_2 -> V_24 ) ;
F_61 ( & V_137 -> V_138 . V_85 ) ;
F_62 ( V_137 ) ;
}
static struct V_125 * F_96 ( struct V_96 * V_97 , T_4 V_105 , T_5 V_144 , unsigned int type )
{
struct V_125 * V_137 , * V_66 = NULL ;
for(; ; ) {
F_11 ( & V_97 -> V_100 ) ;
V_137 = F_93 ( V_97 , V_105 , V_144 , type ) ;
if ( V_137 != NULL )
break;
if ( V_66 != NULL ) {
F_84 ( & V_66 -> V_143 , & V_97 -> V_99 ) ;
F_4 ( V_145 , & V_97 -> V_119 ) ;
V_137 = V_66 ;
V_66 = NULL ;
break;
}
F_12 ( & V_97 -> V_100 ) ;
V_66 = F_94 ( V_97 , V_105 , V_144 , type ) ;
if ( V_66 == NULL )
return NULL ;
}
F_12 ( & V_97 -> V_100 ) ;
if ( V_66 != NULL )
F_95 ( V_66 ) ;
return V_137 ;
}
void F_97 ( struct V_125 * V_137 )
{
struct V_96 * V_97 ;
if ( V_137 == NULL )
return;
V_97 = V_137 -> V_140 ;
if ( ! F_71 ( & V_137 -> V_136 , & V_97 -> V_100 ) )
return;
F_68 ( & V_137 -> V_143 ) ;
if ( F_18 ( & V_97 -> V_99 ) )
F_6 ( V_145 , & V_97 -> V_119 ) ;
F_12 ( & V_97 -> V_100 ) ;
if ( V_137 -> V_146 & V_147 )
F_98 ( V_137 ) ;
F_95 ( V_137 ) ;
}
static void F_99 ( struct V_148 * V_149 , struct V_148 * V_150 )
{
struct V_125 * V_137 = V_150 -> V_151 . V_152 . V_105 ;
V_149 -> V_151 . V_152 . V_105 = V_137 ;
F_48 ( & V_137 -> V_136 ) ;
}
static void F_100 ( struct V_148 * V_153 )
{
F_97 ( V_153 -> V_151 . V_152 . V_105 ) ;
}
int F_101 ( struct V_96 * V_97 , struct V_148 * V_153 )
{
struct V_125 * V_137 ;
if ( V_153 -> V_154 != NULL )
return 0 ;
if ( V_153 -> V_155 & V_156 )
V_137 = F_96 ( V_97 , V_153 -> V_126 , 0 , V_131 ) ;
else if ( V_153 -> V_155 & V_157 )
V_137 = F_96 ( V_97 , 0 , V_153 -> V_127 , V_134 ) ;
else
return - V_158 ;
if ( V_137 == NULL )
return - V_159 ;
V_153 -> V_151 . V_152 . V_105 = V_137 ;
V_153 -> V_154 = & V_160 ;
return 0 ;
}
void F_102 ( T_6 * V_149 , struct V_96 * V_97 , T_4 V_126 , T_5 V_127 )
{
struct V_125 * V_137 ;
int V_161 ;
do {
V_161 = F_103 ( & V_97 -> V_101 ) ;
memcpy ( V_149 , & V_97 -> V_162 , sizeof( * V_149 ) ) ;
} while ( F_104 ( & V_97 -> V_101 , V_161 ) );
if ( F_2 ( V_145 , & V_97 -> V_119 ) == 0 )
return;
F_11 ( & V_97 -> V_100 ) ;
V_137 = F_93 ( V_97 , V_126 , V_127 , V_128 ) ;
if ( V_137 != NULL && ( V_137 -> V_146 & V_147 ) != 0 )
memcpy ( V_149 , & V_137 -> V_163 , sizeof( * V_149 ) ) ;
F_12 ( & V_97 -> V_100 ) ;
F_97 ( V_137 ) ;
}
struct V_164 * F_105 ( struct V_165 * V_166 , T_3 V_111 )
{
struct V_164 * V_66 ;
V_66 = F_106 ( sizeof( * V_66 ) , V_111 ) ;
if ( V_66 != NULL ) {
V_66 -> V_87 = V_166 ;
F_55 ( & V_66 -> V_89 ) ;
}
return V_66 ;
}
void F_107 ( struct V_164 * V_167 )
{
if ( ! F_18 ( & V_167 -> V_89 ) ) {
struct V_168 * V_87 = V_167 -> V_87 -> V_87 ;
F_11 ( & V_87 -> V_88 ) ;
F_47 ( & V_167 -> V_89 ) ;
F_12 ( & V_87 -> V_88 ) ;
F_108 ( & V_87 -> V_85 ) ;
}
}
void F_109 ( struct V_164 * V_167 )
{
F_107 ( V_167 ) ;
F_62 ( V_167 ) ;
}
static void F_110 ( int V_12 , struct V_164 * V_167 )
{
F_111 ( F_112 ( & V_167 -> V_87 -> V_87 -> V_89 , struct V_164 , V_89 ) != V_167 ) ;
switch ( V_12 ) {
case 0 :
break;
case - V_169 :
if ( V_167 -> V_87 -> V_119 & V_170 )
return;
F_113 ( V_171 L_3
L_4
L_5 ,
V_167 -> V_87 ) ;
case - V_172 :
case - V_173 :
case - V_174 :
case - V_175 :
case - V_176 :
case - V_177 :
return;
} ;
V_167 -> V_87 -> V_166 ++ ;
}
void F_114 ( int V_12 , struct V_164 * V_167 )
{
struct V_27 * V_28 = F_115 ( V_167 -> V_87 ,
struct V_27 , V_86 ) ;
struct V_25 * V_26 = V_28 -> V_79 ;
if ( V_12 == - V_169 )
F_58 ( V_28 ) ;
if ( ! F_116 ( V_26 -> V_1 ) )
F_110 ( V_12 , V_167 ) ;
}
void F_117 ( int V_12 , struct V_164 * V_167 )
{
F_110 ( V_12 , V_167 ) ;
}
int F_118 ( struct V_164 * V_167 , struct V_52 * V_53 )
{
struct V_168 * V_87 = V_167 -> V_87 -> V_87 ;
int V_12 = 0 ;
F_11 ( & V_87 -> V_88 ) ;
if ( F_18 ( & V_167 -> V_89 ) )
F_72 ( & V_167 -> V_89 , & V_87 -> V_89 ) ;
if ( F_112 ( & V_87 -> V_89 , struct V_164 , V_89 ) == V_167 )
goto V_178;
F_119 ( & V_87 -> V_85 , V_53 , NULL ) ;
V_12 = - V_179 ;
V_178:
F_12 ( & V_87 -> V_88 ) ;
return V_12 ;
}
static void F_120 ( struct V_1 * V_2 )
{
F_121 () ;
F_6 ( V_180 , & V_2 -> V_14 ) ;
F_122 () ;
F_123 ( & V_2 -> V_14 , V_180 ) ;
F_108 ( & V_2 -> V_181 ) ;
}
void F_124 ( struct V_1 * V_2 )
{
struct V_182 * V_53 ;
if ( F_125 ( V_180 , & V_2 -> V_14 ) != 0 )
return;
F_126 ( V_183 ) ;
F_48 ( & V_2 -> V_184 ) ;
V_53 = F_127 ( V_185 , V_2 , L_6 ,
F_128 ( V_2 -> V_186 ,
V_187 ) ) ;
if ( ! F_129 ( V_53 ) )
return;
F_120 ( V_2 ) ;
F_130 ( V_2 ) ;
F_131 ( V_183 ) ;
}
void F_132 ( struct V_1 * V_2 )
{
if ( ! V_2 )
return;
if ( ! F_2 ( V_188 , & V_2 -> V_14 ) )
F_4 ( V_189 , & V_2 -> V_14 ) ;
F_124 ( V_2 ) ;
}
void F_133 ( struct V_1 * V_2 )
{
F_134 ( V_2 ) ;
F_124 ( V_2 ) ;
}
static int F_135 ( struct V_1 * V_2 , struct V_96 * V_97 )
{
F_4 ( V_190 , & V_97 -> V_119 ) ;
if ( F_2 ( V_191 , & V_97 -> V_119 ) ) {
F_6 ( V_190 , & V_97 -> V_119 ) ;
return 0 ;
}
F_4 ( V_192 , & V_97 -> V_105 -> V_193 ) ;
F_4 ( V_194 , & V_2 -> V_14 ) ;
return 1 ;
}
static int F_136 ( struct V_1 * V_2 , struct V_96 * V_97 )
{
F_4 ( V_191 , & V_97 -> V_119 ) ;
F_6 ( V_190 , & V_97 -> V_119 ) ;
F_4 ( V_195 , & V_97 -> V_105 -> V_193 ) ;
F_4 ( V_196 , & V_2 -> V_14 ) ;
return 1 ;
}
void F_137 ( const struct V_25 * V_26 , struct V_96 * V_97 )
{
struct V_1 * V_2 = V_26 -> V_1 ;
if ( F_26 ( V_122 , & V_97 -> V_119 ) )
F_138 ( V_97 -> V_106 , & V_97 -> V_162 ) ;
F_136 ( V_2 , V_97 ) ;
F_124 ( V_2 ) ;
}
static int F_139 ( struct V_96 * V_97 , const struct V_197 * V_198 )
{
struct V_106 * V_106 = V_97 -> V_106 ;
struct V_107 * V_108 = F_79 ( V_106 ) ;
struct V_148 * V_153 ;
int V_12 = 0 ;
if ( V_106 -> V_199 == NULL )
return 0 ;
F_140 ( & V_108 -> V_200 ) ;
F_141 () ;
for ( V_153 = V_106 -> V_199 ; V_153 != NULL ; V_153 = V_153 -> V_201 ) {
if ( ! ( V_153 -> V_155 & ( V_156 | V_157 ) ) )
continue;
if ( F_142 ( V_153 -> V_202 ) -> V_97 != V_97 )
continue;
F_143 () ;
V_12 = V_198 -> V_203 ( V_97 , V_153 ) ;
switch ( V_12 ) {
case 0 :
break;
case - V_204 :
case - V_205 :
case - V_173 :
case - V_174 :
case - V_206 :
case - V_207 :
case - V_172 :
case - V_208 :
case - V_209 :
case - V_210 :
case - V_211 :
goto V_22;
default:
F_113 ( V_212 L_7 ,
V_213 , V_12 ) ;
case - V_159 :
case - V_214 :
case - V_215 :
case - V_216 :
V_12 = 0 ;
}
F_141 () ;
}
F_143 () ;
V_22:
F_144 ( & V_108 -> V_200 ) ;
return V_12 ;
}
static int F_145 ( struct V_27 * V_28 , const struct V_197 * V_198 )
{
struct V_96 * V_97 ;
struct V_125 * V_88 ;
int V_12 = 0 ;
V_217:
F_11 ( & V_28 -> V_83 ) ;
F_80 (state, &sp->so_states, open_states) {
if ( ! F_26 ( V_198 -> V_218 , & V_97 -> V_119 ) )
continue;
if ( V_97 -> V_97 == 0 )
continue;
F_48 ( & V_97 -> V_98 ) ;
F_12 ( & V_28 -> V_83 ) ;
V_12 = V_198 -> V_219 ( V_28 , V_97 ) ;
if ( V_12 >= 0 ) {
V_12 = F_139 ( V_97 , V_198 ) ;
if ( V_12 >= 0 ) {
F_11 ( & V_97 -> V_100 ) ;
F_80 (lock, &state->lock_states, ls_locks) {
if ( ! ( V_88 -> V_146 & V_147 ) )
F_113 ( L_8 ,
V_213 ) ;
}
F_12 ( & V_97 -> V_100 ) ;
F_86 ( V_97 ) ;
goto V_217;
}
}
switch ( V_12 ) {
default:
F_113 ( V_212 L_7 ,
V_213 , V_12 ) ;
case - V_220 :
case - V_159 :
case - V_204 :
memset ( V_97 -> V_162 . V_221 , 0 ,
sizeof( V_97 -> V_162 . V_221 ) ) ;
V_97 -> V_97 = 0 ;
break;
case - V_222 :
break;
case - V_205 :
case - V_173 :
case - V_174 :
case - V_215 :
case - V_216 :
F_136 ( V_28 -> V_79 -> V_1 , V_97 ) ;
break;
case - V_206 :
case - V_207 :
F_136 ( V_28 -> V_79 -> V_1 , V_97 ) ;
case - V_172 :
case - V_208 :
case - V_209 :
case - V_210 :
case - V_211 :
goto V_223;
}
F_86 ( V_97 ) ;
goto V_217;
}
F_12 ( & V_28 -> V_83 ) ;
return 0 ;
V_223:
F_86 ( V_97 ) ;
return V_12 ;
}
static void F_146 ( struct V_96 * V_97 )
{
struct V_125 * V_88 ;
F_6 ( V_122 , & V_97 -> V_119 ) ;
F_6 ( V_118 , & V_97 -> V_119 ) ;
F_6 ( V_121 , & V_97 -> V_119 ) ;
F_6 ( V_120 , & V_97 -> V_119 ) ;
F_11 ( & V_97 -> V_100 ) ;
F_80 (lock, &state->lock_states, ls_locks) {
V_88 -> V_139 . V_119 = 0 ;
V_88 -> V_146 &= ~ V_147 ;
}
F_12 ( & V_97 -> V_100 ) ;
}
static void F_147 ( struct V_25 * V_26 ,
int (* F_148)( struct V_1 * V_2 , struct V_96 * V_97 ) )
{
struct V_1 * V_2 = V_26 -> V_1 ;
struct V_27 * V_28 ;
struct V_29 * V_30 ;
struct V_96 * V_97 ;
F_11 ( & V_2 -> V_24 ) ;
for ( V_30 = F_15 ( & V_26 -> V_31 ) ;
V_30 != NULL ;
V_30 = F_16 ( V_30 ) ) {
V_28 = F_17 ( V_30 , struct V_27 , V_32 ) ;
V_28 -> V_86 . V_119 = 0 ;
F_11 ( & V_28 -> V_83 ) ;
F_80 (state, &sp->so_states, open_states) {
if ( F_148 ( V_2 , V_97 ) )
F_146 ( V_97 ) ;
}
F_12 ( & V_28 -> V_83 ) ;
}
F_12 ( & V_2 -> V_24 ) ;
}
static void F_149 ( struct V_1 * V_2 ,
int (* F_148)( struct V_1 * V_2 , struct V_96 * V_97 ) )
{
struct V_25 * V_26 ;
F_20 () ;
F_21 (server, &clp->cl_superblocks, client_link)
F_147 ( V_26 , F_148 ) ;
F_22 () ;
}
static void F_150 ( struct V_1 * V_2 )
{
F_151 ( V_2 ) ;
F_149 ( V_2 , F_135 ) ;
}
static void F_152 ( struct V_1 * V_2 ,
const struct V_197 * V_198 )
{
if ( V_198 -> V_224 )
( void ) V_198 -> V_224 ( V_2 ) ;
}
static void F_153 ( struct V_25 * V_26 )
{
struct V_1 * V_2 = V_26 -> V_1 ;
struct V_27 * V_28 ;
struct V_29 * V_30 ;
struct V_96 * V_97 ;
F_11 ( & V_2 -> V_24 ) ;
for ( V_30 = F_15 ( & V_26 -> V_31 ) ;
V_30 != NULL ;
V_30 = F_16 ( V_30 ) ) {
V_28 = F_17 ( V_30 , struct V_27 , V_32 ) ;
F_11 ( & V_28 -> V_83 ) ;
F_80 (state, &sp->so_states, open_states) {
if ( ! F_26 ( V_190 ,
& V_97 -> V_119 ) )
continue;
F_136 ( V_2 , V_97 ) ;
}
F_12 ( & V_28 -> V_83 ) ;
}
F_12 ( & V_2 -> V_24 ) ;
}
static int F_154 ( struct V_1 * V_2 )
{
struct V_25 * V_26 ;
if ( ! F_26 ( V_194 , & V_2 -> V_14 ) )
return 0 ;
F_20 () ;
F_21 (server, &clp->cl_superblocks, client_link)
F_153 ( V_26 ) ;
F_22 () ;
F_155 ( V_2 ) ;
return 1 ;
}
static void F_156 ( struct V_1 * V_2 )
{
if ( ! F_154 ( V_2 ) )
return;
F_152 ( V_2 , V_2 -> V_225 -> V_226 ) ;
}
static void F_157 ( struct V_1 * V_2 )
{
F_151 ( V_2 ) ;
F_155 ( V_2 ) ;
}
static void F_158 ( struct V_1 * V_2 )
{
F_157 ( V_2 ) ;
F_149 ( V_2 , F_136 ) ;
}
static void F_159 ( const char * V_227 )
{
F_160 ( V_171 L_9
L_10
L_11 ,
V_227 ) ;
}
static int F_161 ( struct V_1 * V_2 , int error )
{
switch ( error ) {
case 0 :
break;
case - V_228 :
F_134 ( V_2 ) ;
break;
case - V_207 :
F_156 ( V_2 ) ;
break;
case - V_172 :
case - V_229 :
F_4 ( V_188 , & V_2 -> V_14 ) ;
F_154 ( V_2 ) ;
F_150 ( V_2 ) ;
break;
case - V_206 :
F_4 ( V_188 , & V_2 -> V_14 ) ;
F_158 ( V_2 ) ;
break;
case - V_208 :
case - V_209 :
case - V_210 :
case - V_230 :
case - V_211 :
case - V_231 :
case - V_232 :
F_4 ( V_233 , & V_2 -> V_14 ) ;
break;
case - V_222 :
F_159 ( V_2 -> V_234 ) ;
break;
default:
return error ;
}
return 0 ;
}
static int F_162 ( struct V_1 * V_2 , const struct V_197 * V_198 )
{
struct V_27 * V_28 ;
struct V_25 * V_26 ;
struct V_29 * V_30 ;
int V_12 = 0 ;
V_217:
F_20 () ;
F_21 (server, &clp->cl_superblocks, client_link) {
F_73 ( V_26 ) ;
F_11 ( & V_2 -> V_24 ) ;
for ( V_30 = F_15 ( & V_26 -> V_31 ) ;
V_30 != NULL ;
V_30 = F_16 ( V_30 ) ) {
V_28 = F_17 ( V_30 ,
struct V_27 , V_32 ) ;
if ( ! F_26 ( V_198 -> V_235 ,
& V_28 -> V_193 ) )
continue;
F_48 ( & V_28 -> V_78 ) ;
F_12 ( & V_2 -> V_24 ) ;
F_22 () ;
V_12 = F_145 ( V_28 , V_198 ) ;
if ( V_12 < 0 ) {
F_4 ( V_198 -> V_235 , & V_28 -> V_193 ) ;
F_70 ( V_28 ) ;
return F_161 ( V_2 , V_12 ) ;
}
F_70 ( V_28 ) ;
goto V_217;
}
F_12 ( & V_2 -> V_24 ) ;
}
F_22 () ;
return V_12 ;
}
static int F_163 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
const struct V_236 * V_198 =
V_2 -> V_225 -> V_237 ;
int V_12 ;
if ( F_2 ( V_188 , & V_2 -> V_14 ) )
return 0 ;
F_11 ( & V_2 -> V_24 ) ;
V_4 = V_198 -> V_238 ( V_2 ) ;
F_12 ( & V_2 -> V_24 ) ;
if ( V_4 == NULL ) {
V_4 = F_39 ( V_2 ) ;
V_12 = - V_239 ;
if ( V_4 == NULL )
goto V_22;
}
V_12 = V_198 -> V_240 ( V_2 , V_4 ) ;
F_13 ( V_4 ) ;
V_22:
return F_161 ( V_2 , V_12 ) ;
}
static int F_164 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
const struct V_197 * V_198 =
V_2 -> V_225 -> V_226 ;
int V_12 = - V_220 ;
V_4 = V_198 -> V_241 ( V_2 ) ;
if ( V_4 != NULL ) {
V_12 = V_198 -> V_242 ( V_2 , V_4 ) ;
F_13 ( V_4 ) ;
if ( V_12 == - V_243 && V_4 == V_2 -> V_23 ) {
F_10 ( V_2 ) ;
V_12 = - V_179 ;
}
if ( V_12 == - V_244 )
V_12 = - V_245 ;
}
return V_12 ;
}
void F_165 ( struct V_44 * V_246 )
{
struct V_1 * V_2 = V_246 -> V_2 ;
F_4 ( V_233 , & V_2 -> V_14 ) ;
F_132 ( V_2 ) ;
}
void F_166 ( struct V_1 * V_2 )
{
F_4 ( V_247 , & V_2 -> V_14 ) ;
F_124 ( V_2 ) ;
}
static void F_167 ( struct V_1 * V_2 )
{
if ( F_125 ( V_188 , & V_2 -> V_14 ) == 0 ) {
V_2 -> V_248 = V_249 ;
F_158 ( V_2 ) ;
F_124 ( V_2 ) ;
}
}
static void F_168 ( struct V_1 * V_2 )
{
if ( F_125 ( V_188 , & V_2 -> V_14 ) == 0 ) {
F_150 ( V_2 ) ;
F_124 ( V_2 ) ;
}
}
static void F_169 ( struct V_1 * V_2 )
{
F_167 ( V_2 ) ;
}
static void F_170 ( struct V_1 * V_2 )
{
F_171 ( V_2 ) ;
}
static void F_172 ( struct V_1 * V_2 )
{
F_171 ( V_2 ) ;
if ( F_125 ( V_233 , & V_2 -> V_14 ) == 0 )
F_124 ( V_2 ) ;
}
void F_173 ( struct V_1 * V_2 , T_7 V_119 )
{
if ( ! V_119 )
return;
if ( V_119 & V_250 )
F_168 ( V_2 ) ;
if ( V_119 & ( V_251 |
V_252 |
V_253 |
V_254 ) )
F_169 ( V_2 ) ;
if ( V_119 & V_255 )
F_170 ( V_2 ) ;
if ( V_119 & ( V_256 |
V_257 |
V_258 ) )
F_172 ( V_2 ) ;
}
static int F_174 ( struct V_1 * V_2 )
{
int V_12 ;
F_32 ( V_2 ) ;
V_12 = F_175 ( V_2 -> V_46 ) ;
if ( V_12 && V_12 != - V_208 &&
V_12 != - V_230 ) {
V_12 = F_161 ( V_2 , V_12 ) ;
goto V_22;
}
memset ( V_2 -> V_46 -> V_259 . V_221 , 0 , V_260 ) ;
V_12 = F_35 ( V_2 ) ;
if ( V_12 ) {
V_12 = F_161 ( V_2 , V_12 ) ;
goto V_22;
}
F_6 ( V_233 , & V_2 -> V_14 ) ;
F_6 ( V_247 , & V_2 -> V_14 ) ;
if ( ! F_2 ( V_188 , & V_2 -> V_14 ) )
F_23 ( V_2 ) ;
V_22:
return V_12 ;
}
static int F_176 ( struct V_1 * V_2 )
{
struct V_56 * V_261 = & V_2 -> V_46 -> V_50 ;
struct V_262 * V_263 = & V_2 -> V_46 -> V_263 ;
struct V_264 * V_66 , * V_265 ;
int V_266 ;
F_32 ( V_2 ) ;
V_66 = F_106 ( V_261 -> V_267 * sizeof( struct V_264 ) ,
V_82 ) ;
if ( ! V_66 )
return - V_159 ;
F_11 ( & V_261 -> V_51 ) ;
for ( V_266 = 0 ; V_266 < V_261 -> V_267 ; V_266 ++ )
V_66 [ V_266 ] . V_268 = V_261 -> V_269 [ V_266 ] . V_268 ;
V_265 = V_261 -> V_269 ;
V_261 -> V_269 = V_66 ;
V_261 -> V_47 = V_261 -> V_267 ;
V_261 -> V_267 = 0 ;
V_263 -> V_270 = V_261 -> V_47 ;
F_12 ( & V_261 -> V_51 ) ;
F_62 ( V_265 ) ;
F_25 ( V_2 ) ;
return 0 ;
}
static int F_174 ( struct V_1 * V_2 ) { return 0 ; }
static int F_25 ( struct V_1 * V_2 ) { return 0 ; }
static int F_176 ( struct V_1 * V_2 ) { return 0 ; }
static void F_177 ( struct V_1 * V_2 , int V_12 )
{
switch ( V_12 ) {
case - V_271 :
case - V_172 :
F_6 ( V_13 , & V_2 -> V_14 ) ;
break;
case - V_272 :
case - V_273 :
case - V_179 :
F_178 ( 1 ) ;
break;
case - V_222 :
F_159 ( V_2 -> V_234 ) ;
case - V_274 :
default:
return;
}
F_4 ( V_188 , & V_2 -> V_14 ) ;
}
static void F_179 ( struct V_1 * V_2 )
{
int V_12 = 0 ;
do {
if ( F_26 ( V_188 , & V_2 -> V_14 ) ) {
V_12 = F_164 ( V_2 ) ;
if ( V_12 ) {
F_177 ( V_2 , V_12 ) ;
if ( F_2 ( V_188 ,
& V_2 -> V_14 ) )
continue;
if ( V_2 -> V_275 ==
V_276 )
F_36 ( V_2 , V_12 ) ;
goto V_277;
}
F_6 ( V_189 , & V_2 -> V_14 ) ;
if ( F_26 ( V_278 ,
& V_2 -> V_14 ) )
F_158 ( V_2 ) ;
else
F_4 ( V_194 ,
& V_2 -> V_14 ) ;
F_180 ( V_2 ) ;
}
if ( F_26 ( V_189 , & V_2 -> V_14 ) ) {
V_12 = F_163 ( V_2 ) ;
if ( V_12 < 0 )
goto V_277;
if ( F_2 ( V_188 , & V_2 -> V_14 ) )
continue;
}
if ( F_26 ( V_233 , & V_2 -> V_14 )
&& F_116 ( V_2 ) ) {
V_12 = F_174 ( V_2 ) ;
if ( F_2 ( V_188 , & V_2 -> V_14 ) )
continue;
if ( V_12 < 0 )
goto V_277;
}
if ( F_2 ( V_194 , & V_2 -> V_14 ) ) {
V_12 = F_162 ( V_2 ,
V_2 -> V_225 -> V_226 ) ;
if ( F_2 ( V_188 , & V_2 -> V_14 ) ||
F_2 ( V_233 , & V_2 -> V_14 ) )
continue;
F_156 ( V_2 ) ;
if ( F_2 ( V_196 , & V_2 -> V_14 ) )
continue;
if ( V_12 < 0 )
goto V_277;
}
if ( F_26 ( V_196 , & V_2 -> V_14 ) ) {
V_12 = F_162 ( V_2 ,
V_2 -> V_225 -> V_279 ) ;
if ( F_2 ( V_188 , & V_2 -> V_14 ) ||
F_2 ( V_233 , & V_2 -> V_14 ) ||
F_2 ( V_194 , & V_2 -> V_14 ) )
continue;
if ( V_12 < 0 )
goto V_277;
}
F_25 ( V_2 ) ;
if ( F_26 ( V_280 , & V_2 -> V_14 ) ) {
F_181 ( V_2 ) ;
continue;
}
if ( F_26 ( V_247 , & V_2 -> V_14 )
&& F_116 ( V_2 ) ) {
V_12 = F_176 ( V_2 ) ;
if ( V_12 < 0 )
goto V_277;
continue;
}
F_120 ( V_2 ) ;
if ( V_2 -> V_14 == 0 )
break;
if ( F_125 ( V_180 , & V_2 -> V_14 ) != 0 )
break;
} while ( F_182 ( & V_2 -> V_184 ) > 1 );
return;
V_277:
F_113 ( V_171 L_12
L_13 , V_2 -> V_234 , - V_12 ) ;
F_25 ( V_2 ) ;
F_120 ( V_2 ) ;
}
static int V_185 ( void * V_281 )
{
struct V_1 * V_2 = V_281 ;
F_183 ( V_282 ) ;
F_179 ( V_2 ) ;
F_130 ( V_2 ) ;
F_184 ( 0 ) ;
return 0 ;
}
