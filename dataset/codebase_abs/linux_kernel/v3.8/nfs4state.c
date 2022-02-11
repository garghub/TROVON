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
struct V_3 * V_4 ;
F_14 ( & V_2 -> V_29 ) ;
V_4 = V_2 -> V_28 ;
V_2 -> V_28 = NULL ;
F_15 ( & V_2 -> V_29 ) ;
if ( V_4 != NULL )
F_16 ( V_4 ) ;
}
static struct V_3 *
F_17 ( struct V_30 * V_31 )
{
struct V_3 * V_4 = NULL ;
struct V_32 * V_33 ;
struct V_34 * V_35 ;
for ( V_35 = F_18 ( & V_31 -> V_36 ) ;
V_35 != NULL ;
V_35 = F_19 ( V_35 ) ) {
V_33 = F_20 ( V_35 , struct V_32 , V_37 ) ;
if ( F_21 ( & V_33 -> V_38 ) )
continue;
V_4 = F_12 ( V_33 -> V_39 ) ;
break;
}
return V_4 ;
}
struct V_3 * F_22 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = NULL ;
struct V_30 * V_31 ;
V_4 = F_11 ( V_2 ) ;
if ( V_4 != NULL )
goto V_26;
F_23 () ;
F_24 (server, &clp->cl_superblocks, client_link) {
V_4 = F_17 ( V_31 ) ;
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
struct V_40 V_41 ;
if ( ! F_3 ( V_42 , & V_2 -> V_43 ) ) {
F_8 ( V_2 ) ;
return 0 ;
}
V_12 = F_27 ( V_2 , & V_41 ) ;
if ( V_12 == 0 ) {
F_14 ( & V_2 -> V_29 ) ;
V_2 -> V_44 = V_41 . V_45 * V_46 ;
V_2 -> V_47 = V_48 ;
F_15 ( & V_2 -> V_29 ) ;
F_8 ( V_2 ) ;
}
return V_12 ;
}
static void F_28 ( struct V_1 * V_2 )
{
struct V_49 * V_50 = V_2 -> V_51 ;
struct V_52 * V_53 ;
if ( V_50 == NULL )
return;
V_53 = & V_50 -> V_54 ;
if ( F_29 ( V_55 , & V_50 -> V_56 ) ) {
F_14 ( & V_53 -> V_57 ) ;
F_30 ( V_53 ) ;
F_15 ( & V_53 -> V_57 ) ;
}
}
void F_31 ( struct V_49 * V_58 ,
struct V_52 * V_53 )
{
if ( F_32 ( V_58 ) )
F_33 ( & V_53 -> F_33 ) ;
}
static int F_34 ( struct V_52 * V_53 )
{
F_14 ( & V_53 -> V_57 ) ;
if ( V_53 -> V_59 != V_60 ) {
F_35 ( V_53 -> F_33 ) ;
F_15 ( & V_53 -> V_57 ) ;
return F_36 ( & V_53 -> F_33 ) ;
}
F_15 ( & V_53 -> V_57 ) ;
return 0 ;
}
static int F_37 ( struct V_1 * V_2 )
{
struct V_49 * V_50 = V_2 -> V_51 ;
int V_61 = 0 ;
F_5 ( V_55 , & V_50 -> V_56 ) ;
V_61 = F_34 ( & V_50 -> V_62 ) ;
if ( V_61 )
return V_61 ;
return F_34 ( & V_50 -> V_54 ) ;
}
static void F_38 ( struct V_1 * V_2 )
{
F_7 ( V_17 , & V_2 -> V_18 ) ;
F_7 ( V_63 , & V_2 -> V_18 ) ;
F_7 ( V_64 , & V_2 -> V_18 ) ;
F_26 ( V_2 ) ;
}
int F_39 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
int V_12 ;
if ( F_3 ( V_17 , & V_2 -> V_18 ) )
goto V_19;
F_37 ( V_2 ) ;
V_12 = F_40 ( V_2 , V_4 ) ;
if ( V_12 != 0 )
goto V_26;
F_5 ( V_17 , & V_2 -> V_18 ) ;
V_19:
V_12 = F_41 ( V_2 , V_4 ) ;
if ( V_12 != 0 )
goto V_26;
F_38 ( V_2 ) ;
F_42 ( V_2 , V_65 ) ;
V_26:
return V_12 ;
}
int F_43 ( struct V_1 * V_2 ,
struct V_1 * * V_27 ,
struct V_3 * V_4 )
{
int V_12 ;
V_12 = F_40 ( V_2 , V_4 ) ;
if ( V_12 != V_66 )
return V_12 ;
F_5 ( V_17 , & V_2 -> V_18 ) ;
return F_44 ( V_2 , V_27 , V_4 ) ;
}
struct V_3 * F_45 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
F_14 ( & V_2 -> V_29 ) ;
V_4 = F_11 ( V_2 ) ;
F_15 ( & V_2 -> V_29 ) ;
return V_4 ;
}
static struct V_3 *
F_46 ( struct V_30 * V_31 )
{
struct V_1 * V_2 = V_31 -> V_1 ;
struct V_3 * V_4 = NULL ;
struct V_32 * V_33 ;
struct V_34 * V_35 ;
F_14 ( & V_2 -> V_29 ) ;
V_35 = F_18 ( & V_31 -> V_36 ) ;
if ( V_35 != NULL ) {
V_33 = F_20 ( V_35 , struct V_32 , V_37 ) ;
V_4 = F_12 ( V_33 -> V_39 ) ;
}
F_15 ( & V_2 -> V_29 ) ;
return V_4 ;
}
struct V_3 * F_47 ( struct V_1 * V_2 )
{
struct V_30 * V_31 ;
struct V_3 * V_4 ;
F_14 ( & V_2 -> V_29 ) ;
V_4 = F_11 ( V_2 ) ;
F_15 ( & V_2 -> V_29 ) ;
if ( V_4 != NULL )
goto V_26;
F_23 () ;
F_24 (server, &clp->cl_superblocks, client_link) {
V_4 = F_46 ( V_31 ) ;
if ( V_4 != NULL )
break;
}
F_25 () ;
V_26:
return V_4 ;
}
static struct V_32 *
F_48 ( struct V_30 * V_31 , struct V_3 * V_4 )
{
struct V_34 * * V_67 = & V_31 -> V_36 . V_34 ,
* V_68 = NULL ;
struct V_32 * V_33 ;
while ( * V_67 != NULL ) {
V_68 = * V_67 ;
V_33 = F_20 ( V_68 , struct V_32 , V_37 ) ;
if ( V_4 < V_33 -> V_39 )
V_67 = & V_68 -> V_69 ;
else if ( V_4 > V_33 -> V_39 )
V_67 = & V_68 -> V_70 ;
else {
if ( ! F_21 ( & V_33 -> V_71 ) )
F_49 ( & V_33 -> V_71 ) ;
F_50 ( & V_33 -> V_72 ) ;
return V_33 ;
}
}
return NULL ;
}
static struct V_32 *
F_51 ( struct V_32 * V_73 )
{
struct V_30 * V_31 = V_73 -> V_74 ;
struct V_34 * * V_67 = & V_31 -> V_36 . V_34 ,
* V_68 = NULL ;
struct V_32 * V_33 ;
int V_75 ;
while ( * V_67 != NULL ) {
V_68 = * V_67 ;
V_33 = F_20 ( V_68 , struct V_32 , V_37 ) ;
if ( V_73 -> V_39 < V_33 -> V_39 )
V_67 = & V_68 -> V_69 ;
else if ( V_73 -> V_39 > V_33 -> V_39 )
V_67 = & V_68 -> V_70 ;
else {
if ( ! F_21 ( & V_33 -> V_71 ) )
F_49 ( & V_33 -> V_71 ) ;
F_50 ( & V_33 -> V_72 ) ;
return V_33 ;
}
}
V_75 = F_52 ( & V_31 -> V_76 , & V_73 -> V_77 . V_78 ) ;
if ( V_75 )
return F_53 ( V_75 ) ;
F_54 ( & V_73 -> V_37 , V_68 , V_67 ) ;
F_55 ( & V_73 -> V_37 , & V_31 -> V_36 ) ;
return V_73 ;
}
static void
F_56 ( struct V_32 * V_33 )
{
struct V_30 * V_31 = V_33 -> V_74 ;
if ( ! F_57 ( & V_33 -> V_37 ) )
F_58 ( & V_33 -> V_37 , & V_31 -> V_36 ) ;
F_59 ( & V_31 -> V_76 , V_33 -> V_77 . V_78 ) ;
}
static void
F_60 ( struct V_79 * V_80 )
{
V_80 -> V_81 = F_61 () ;
V_80 -> V_82 = 0 ;
V_80 -> V_83 = 0 ;
F_62 ( & V_80 -> V_84 ) ;
F_63 ( & V_80 -> V_85 ) ;
F_64 ( & V_80 -> V_86 , L_1 ) ;
}
static void
F_65 ( struct V_79 * V_80 )
{
F_66 ( & V_80 -> V_86 ) ;
}
static struct V_32 *
F_67 ( struct V_30 * V_31 ,
struct V_3 * V_4 ,
T_1 V_87 )
{
struct V_32 * V_33 ;
V_33 = F_68 ( sizeof( * V_33 ) , V_87 ) ;
if ( ! V_33 )
return NULL ;
V_33 -> V_74 = V_31 ;
V_33 -> V_39 = F_12 ( V_4 ) ;
F_62 ( & V_33 -> V_88 ) ;
F_63 ( & V_33 -> V_38 ) ;
F_60 ( & V_33 -> V_77 ) ;
F_69 ( & V_33 -> V_72 , 1 ) ;
F_63 ( & V_33 -> V_71 ) ;
return V_33 ;
}
static void
F_70 ( struct V_32 * V_33 )
{
struct V_34 * V_34 = & V_33 -> V_37 ;
if ( ! F_57 ( V_34 ) ) {
struct V_30 * V_31 = V_33 -> V_74 ;
struct V_1 * V_2 = V_31 -> V_1 ;
F_14 ( & V_2 -> V_29 ) ;
if ( ! F_57 ( V_34 ) ) {
F_58 ( V_34 , & V_31 -> V_36 ) ;
F_71 ( V_34 ) ;
}
F_15 ( & V_2 -> V_29 ) ;
}
}
static void F_72 ( struct V_32 * V_33 )
{
F_65 ( & V_33 -> V_77 ) ;
F_16 ( V_33 -> V_39 ) ;
F_73 ( V_33 ) ;
}
static void F_74 ( struct V_30 * V_31 )
{
struct V_1 * V_2 = V_31 -> V_1 ;
struct V_32 * V_33 , * V_89 ;
unsigned long V_90 , V_91 ;
F_75 ( V_92 ) ;
F_14 ( & V_2 -> V_29 ) ;
V_91 = V_48 ;
V_90 = ( long ) V_91 - ( long ) V_2 -> V_44 ;
F_76 (sp, tmp, &server->state_owners_lru, so_lru) {
if ( F_77 ( V_33 -> V_93 , V_90 , V_91 ) )
break;
F_78 ( & V_33 -> V_71 , & V_92 ) ;
F_56 ( V_33 ) ;
}
F_15 ( & V_2 -> V_29 ) ;
F_76 (sp, tmp, &doomed, so_lru) {
F_79 ( & V_33 -> V_71 ) ;
F_72 ( V_33 ) ;
}
}
struct V_32 * F_80 ( struct V_30 * V_31 ,
struct V_3 * V_4 ,
T_1 V_87 )
{
struct V_1 * V_2 = V_31 -> V_1 ;
struct V_32 * V_33 , * V_73 ;
F_14 ( & V_2 -> V_29 ) ;
V_33 = F_48 ( V_31 , V_4 ) ;
F_15 ( & V_2 -> V_29 ) ;
if ( V_33 != NULL )
goto V_26;
V_73 = F_67 ( V_31 , V_4 , V_87 ) ;
if ( V_73 == NULL )
goto V_26;
do {
if ( F_81 ( & V_31 -> V_76 , V_87 ) == 0 )
break;
F_14 ( & V_2 -> V_29 ) ;
V_33 = F_51 ( V_73 ) ;
F_15 ( & V_2 -> V_29 ) ;
} while ( V_33 == F_53 ( - V_94 ) );
if ( V_33 != V_73 )
F_72 ( V_73 ) ;
V_26:
F_74 ( V_31 ) ;
return V_33 ;
}
void F_82 ( struct V_32 * V_33 )
{
struct V_30 * V_31 = V_33 -> V_74 ;
struct V_1 * V_2 = V_31 -> V_1 ;
if ( ! F_83 ( & V_33 -> V_72 , & V_2 -> V_29 ) )
return;
V_33 -> V_93 = V_48 ;
F_84 ( & V_33 -> V_71 , & V_31 -> V_95 ) ;
F_15 ( & V_2 -> V_29 ) ;
}
void F_85 ( struct V_30 * V_31 )
{
struct V_1 * V_2 = V_31 -> V_1 ;
struct V_32 * V_33 , * V_89 ;
F_75 ( V_92 ) ;
F_14 ( & V_2 -> V_29 ) ;
F_76 (sp, tmp, &server->state_owners_lru, so_lru) {
F_78 ( & V_33 -> V_71 , & V_92 ) ;
F_56 ( V_33 ) ;
}
F_15 ( & V_2 -> V_29 ) ;
F_76 (sp, tmp, &doomed, so_lru) {
F_79 ( & V_33 -> V_71 ) ;
F_72 ( V_33 ) ;
}
}
static struct V_96 *
F_86 ( void )
{
struct V_96 * V_97 ;
V_97 = F_68 ( sizeof( * V_97 ) , V_98 ) ;
if ( ! V_97 )
return NULL ;
F_69 ( & V_97 -> V_99 , 1 ) ;
F_63 ( & V_97 -> V_100 ) ;
F_62 ( & V_97 -> V_101 ) ;
F_87 ( & V_97 -> V_102 ) ;
return V_97 ;
}
void
F_88 ( struct V_96 * V_97 , T_2 V_103 )
{
if ( V_97 -> V_97 == V_103 )
return;
if ( ( V_103 & V_104 ) != ( V_97 -> V_97 & V_104 ) ) {
if ( V_103 & V_104 )
F_78 ( & V_97 -> V_105 , & V_97 -> V_106 -> V_38 ) ;
else
F_89 ( & V_97 -> V_105 , & V_97 -> V_106 -> V_38 ) ;
}
V_97 -> V_97 = V_103 ;
}
static struct V_96 *
F_90 ( struct V_107 * V_107 , struct V_32 * V_106 )
{
struct V_108 * V_109 = F_91 ( V_107 ) ;
struct V_96 * V_97 ;
F_92 (state, &nfsi->open_states, inode_states) {
if ( V_97 -> V_106 != V_106 )
continue;
if ( F_93 ( & V_97 -> V_99 ) )
return V_97 ;
}
return NULL ;
}
static void
F_94 ( struct V_96 * V_97 )
{
F_73 ( V_97 ) ;
}
struct V_96 *
F_95 ( struct V_107 * V_107 , struct V_32 * V_106 )
{
struct V_96 * V_97 , * V_73 ;
struct V_108 * V_109 = F_91 ( V_107 ) ;
F_14 ( & V_107 -> V_110 ) ;
V_97 = F_90 ( V_107 , V_106 ) ;
F_15 ( & V_107 -> V_110 ) ;
if ( V_97 )
goto V_26;
V_73 = F_86 () ;
F_14 ( & V_106 -> V_88 ) ;
F_14 ( & V_107 -> V_110 ) ;
V_97 = F_90 ( V_107 , V_106 ) ;
if ( V_97 == NULL && V_73 != NULL ) {
V_97 = V_73 ;
V_97 -> V_106 = V_106 ;
F_50 ( & V_106 -> V_72 ) ;
F_96 ( & V_97 -> V_111 , & V_109 -> V_105 ) ;
F_97 ( V_107 ) ;
V_97 -> V_107 = V_107 ;
F_15 ( & V_107 -> V_110 ) ;
F_84 ( & V_97 -> V_105 , & V_106 -> V_38 ) ;
F_15 ( & V_106 -> V_88 ) ;
} else {
F_15 ( & V_107 -> V_110 ) ;
F_15 ( & V_106 -> V_88 ) ;
if ( V_73 )
F_94 ( V_73 ) ;
}
V_26:
return V_97 ;
}
void F_98 ( struct V_96 * V_97 )
{
struct V_107 * V_107 = V_97 -> V_107 ;
struct V_32 * V_106 = V_97 -> V_106 ;
if ( ! F_83 ( & V_97 -> V_99 , & V_106 -> V_88 ) )
return;
F_14 ( & V_107 -> V_110 ) ;
F_79 ( & V_97 -> V_111 ) ;
F_79 ( & V_97 -> V_105 ) ;
F_15 ( & V_107 -> V_110 ) ;
F_15 ( & V_106 -> V_88 ) ;
F_99 ( V_107 ) ;
F_94 ( V_97 ) ;
F_82 ( V_106 ) ;
}
static void F_100 ( struct V_96 * V_97 ,
T_2 V_103 , T_1 V_112 , int V_86 )
{
struct V_32 * V_106 = V_97 -> V_106 ;
int V_113 = 0 ;
T_2 V_114 ;
F_50 ( & V_106 -> V_72 ) ;
F_14 ( & V_106 -> V_88 ) ;
switch ( V_103 & ( V_115 | V_104 ) ) {
case V_115 :
V_97 -> V_116 -- ;
break;
case V_104 :
V_97 -> V_117 -- ;
break;
case V_115 | V_104 :
V_97 -> V_118 -- ;
}
V_114 = V_115 | V_104 ;
if ( V_97 -> V_118 == 0 ) {
if ( V_97 -> V_116 == 0 ) {
V_114 &= ~ V_115 ;
V_113 |= F_3 ( V_119 , & V_97 -> V_82 ) ;
V_113 |= F_3 ( V_120 , & V_97 -> V_82 ) ;
}
if ( V_97 -> V_117 == 0 ) {
V_114 &= ~ V_104 ;
V_113 |= F_3 ( V_121 , & V_97 -> V_82 ) ;
V_113 |= F_3 ( V_120 , & V_97 -> V_82 ) ;
}
if ( V_114 == 0 )
F_7 ( V_122 , & V_97 -> V_82 ) ;
}
F_88 ( V_97 , V_114 ) ;
F_15 ( & V_106 -> V_88 ) ;
if ( ! V_113 ) {
F_98 ( V_97 ) ;
F_82 ( V_106 ) ;
} else
F_101 ( V_97 , V_112 , V_86 ) ;
}
void F_102 ( struct V_96 * V_97 , T_2 V_103 )
{
F_100 ( V_97 , V_103 , V_98 , 0 ) ;
}
void F_103 ( struct V_96 * V_97 , T_2 V_103 )
{
F_100 ( V_97 , V_103 , V_123 , 1 ) ;
}
static struct V_124 *
F_104 ( struct V_96 * V_97 , T_3 V_125 , T_4 V_126 , unsigned int type )
{
struct V_124 * V_35 ;
F_92 (pos, &state->lock_states, ls_locks) {
if ( type != V_127 && V_35 -> V_128 . V_129 != type )
continue;
switch ( V_35 -> V_128 . V_129 ) {
case V_130 :
if ( V_35 -> V_128 . V_131 . V_132 != V_125 )
continue;
break;
case V_133 :
if ( V_35 -> V_128 . V_131 . V_134 != V_126 )
continue;
}
F_50 ( & V_35 -> V_135 ) ;
return V_35 ;
}
return NULL ;
}
static struct V_124 * F_105 ( struct V_96 * V_97 , T_3 V_125 , T_4 V_126 , unsigned int type )
{
struct V_124 * V_136 ;
struct V_30 * V_31 = V_97 -> V_106 -> V_74 ;
V_136 = F_68 ( sizeof( * V_136 ) , V_98 ) ;
if ( V_136 == NULL )
return NULL ;
F_60 ( & V_136 -> V_137 ) ;
F_69 ( & V_136 -> V_135 , 1 ) ;
V_136 -> V_138 = V_97 ;
V_136 -> V_128 . V_129 = type ;
switch ( V_136 -> V_128 . V_129 ) {
case V_133 :
V_136 -> V_128 . V_131 . V_134 = V_126 ;
break;
case V_130 :
V_136 -> V_128 . V_131 . V_132 = V_125 ;
break;
default:
goto V_139;
}
V_136 -> V_137 . V_78 = F_106 ( & V_31 -> V_140 , 0 , 0 , V_98 ) ;
if ( V_136 -> V_137 . V_78 < 0 )
goto V_139;
F_63 ( & V_136 -> V_141 ) ;
return V_136 ;
V_139:
F_73 ( V_136 ) ;
return NULL ;
}
void F_107 ( struct V_30 * V_31 , struct V_124 * V_136 )
{
F_108 ( & V_31 -> V_140 , V_136 -> V_137 . V_78 ) ;
F_65 ( & V_136 -> V_137 ) ;
F_73 ( V_136 ) ;
}
static struct V_124 * F_109 ( struct V_96 * V_97 , T_3 V_106 , T_4 V_142 , unsigned int type )
{
struct V_124 * V_136 , * V_73 = NULL ;
for(; ; ) {
F_14 ( & V_97 -> V_101 ) ;
V_136 = F_104 ( V_97 , V_106 , V_142 , type ) ;
if ( V_136 != NULL )
break;
if ( V_73 != NULL ) {
F_96 ( & V_73 -> V_141 , & V_97 -> V_100 ) ;
F_5 ( V_143 , & V_97 -> V_82 ) ;
V_136 = V_73 ;
V_73 = NULL ;
break;
}
F_15 ( & V_97 -> V_101 ) ;
V_73 = F_105 ( V_97 , V_106 , V_142 , type ) ;
if ( V_73 == NULL )
return NULL ;
}
F_15 ( & V_97 -> V_101 ) ;
if ( V_73 != NULL )
F_107 ( V_97 -> V_106 -> V_74 , V_73 ) ;
return V_136 ;
}
void F_110 ( struct V_124 * V_136 )
{
struct V_96 * V_97 ;
if ( V_136 == NULL )
return;
V_97 = V_136 -> V_138 ;
if ( ! F_83 ( & V_136 -> V_135 , & V_97 -> V_101 ) )
return;
F_79 ( & V_136 -> V_141 ) ;
if ( F_21 ( & V_97 -> V_100 ) )
F_7 ( V_143 , & V_97 -> V_82 ) ;
F_15 ( & V_97 -> V_101 ) ;
if ( F_3 ( V_144 , & V_136 -> V_145 ) ) {
if ( F_111 ( V_136 ) == 0 )
return;
}
F_107 ( V_136 -> V_138 -> V_106 -> V_74 , V_136 ) ;
}
static void F_112 ( struct V_146 * V_147 , struct V_146 * V_148 )
{
struct V_124 * V_136 = V_148 -> V_149 . V_150 . V_106 ;
V_147 -> V_149 . V_150 . V_106 = V_136 ;
F_50 ( & V_136 -> V_135 ) ;
}
static void F_113 ( struct V_146 * V_151 )
{
F_110 ( V_151 -> V_149 . V_150 . V_106 ) ;
}
int F_114 ( struct V_96 * V_97 , struct V_146 * V_151 )
{
struct V_124 * V_136 ;
if ( V_151 -> V_152 != NULL )
return 0 ;
if ( V_151 -> V_153 & V_154 )
V_136 = F_109 ( V_97 , V_151 -> V_125 , 0 , V_130 ) ;
else if ( V_151 -> V_153 & V_155 )
V_136 = F_109 ( V_97 , NULL , V_151 -> V_126 ,
V_133 ) ;
else
return - V_156 ;
if ( V_136 == NULL )
return - V_157 ;
V_151 -> V_149 . V_150 . V_106 = V_136 ;
V_151 -> V_152 = & V_158 ;
return 0 ;
}
static bool F_115 ( T_5 * V_147 , struct V_96 * V_97 ,
const struct V_159 * V_160 )
{
struct V_124 * V_136 ;
T_3 V_125 ;
T_4 V_126 ;
bool V_61 = false ;
if ( V_160 == NULL )
goto V_26;
if ( F_3 ( V_143 , & V_97 -> V_82 ) == 0 )
goto V_26;
V_125 = V_160 -> V_161 ;
V_126 = V_160 -> V_162 ;
F_14 ( & V_97 -> V_101 ) ;
V_136 = F_104 ( V_97 , V_125 , V_126 , V_127 ) ;
if ( V_136 != NULL && F_3 ( V_144 , & V_136 -> V_145 ) != 0 ) {
F_116 ( V_147 , & V_136 -> V_163 ) ;
V_61 = true ;
}
F_15 ( & V_97 -> V_101 ) ;
F_110 ( V_136 ) ;
V_26:
return V_61 ;
}
static void F_117 ( T_5 * V_147 , struct V_96 * V_97 )
{
int V_164 ;
do {
V_164 = F_118 ( & V_97 -> V_102 ) ;
F_116 ( V_147 , & V_97 -> V_165 ) ;
} while ( F_119 ( & V_97 -> V_102 , V_164 ) );
}
void F_120 ( T_5 * V_147 , struct V_96 * V_97 ,
T_2 V_103 , const struct V_159 * V_160 )
{
if ( F_121 ( V_147 , V_97 -> V_107 , V_103 ) )
return;
if ( F_115 ( V_147 , V_97 , V_160 ) )
return;
F_117 ( V_147 , V_97 ) ;
}
struct V_166 * F_122 ( struct V_79 * V_83 , T_1 V_112 )
{
struct V_166 * V_73 ;
V_73 = F_123 ( sizeof( * V_73 ) , V_112 ) ;
if ( V_73 != NULL ) {
V_73 -> V_167 = V_83 ;
F_63 ( & V_73 -> V_85 ) ;
V_73 -> V_168 = NULL ;
}
return V_73 ;
}
void F_124 ( struct V_166 * V_169 )
{
struct V_79 * V_167 ;
if ( F_21 ( & V_169 -> V_85 ) )
return;
V_167 = V_169 -> V_167 ;
F_14 ( & V_167 -> V_84 ) ;
F_49 ( & V_169 -> V_85 ) ;
if ( ! F_21 ( & V_167 -> V_85 ) ) {
struct V_166 * V_170 ;
V_170 = F_125 ( & V_167 -> V_85 ,
struct V_166 , V_85 ) ;
F_126 ( & V_167 -> V_86 , V_170 -> V_168 ) ;
}
F_15 ( & V_167 -> V_84 ) ;
}
void F_127 ( struct V_166 * V_169 )
{
F_124 ( V_169 ) ;
F_73 ( V_169 ) ;
}
static void F_128 ( int V_12 , struct V_166 * V_169 )
{
switch ( V_12 ) {
case 0 :
break;
case - V_171 :
if ( V_169 -> V_167 -> V_82 & V_172 )
return;
F_129 ( L_2
L_3
L_4 ,
V_169 -> V_167 ) ;
case - V_173 :
case - V_174 :
case - V_175 :
case - V_176 :
case - V_177 :
case - V_178 :
return;
} ;
V_169 -> V_167 -> V_83 ++ ;
}
void F_130 ( int V_12 , struct V_166 * V_169 )
{
struct V_32 * V_33 = F_131 ( V_169 -> V_167 ,
struct V_32 , V_77 ) ;
struct V_30 * V_31 = V_33 -> V_74 ;
if ( V_12 == - V_171 )
F_70 ( V_33 ) ;
if ( ! F_132 ( V_31 -> V_1 ) )
F_128 ( V_12 , V_169 ) ;
}
void F_133 ( int V_12 , struct V_166 * V_169 )
{
F_128 ( V_12 , V_169 ) ;
}
int F_134 ( struct V_166 * V_169 , struct V_179 * V_168 )
{
struct V_79 * V_167 = V_169 -> V_167 ;
int V_12 = 0 ;
F_14 ( & V_167 -> V_84 ) ;
V_169 -> V_168 = V_168 ;
if ( F_21 ( & V_169 -> V_85 ) )
F_84 ( & V_169 -> V_85 , & V_167 -> V_85 ) ;
if ( F_125 ( & V_167 -> V_85 , struct V_166 , V_85 ) == V_169 )
goto V_180;
F_135 ( & V_167 -> V_86 , V_168 , NULL ) ;
V_12 = - V_94 ;
V_180:
F_15 ( & V_167 -> V_84 ) ;
return V_12 ;
}
static void F_136 ( struct V_1 * V_2 )
{
F_137 () ;
F_7 ( V_181 , & V_2 -> V_18 ) ;
F_138 () ;
F_139 ( & V_2 -> V_18 , V_181 ) ;
F_140 ( & V_2 -> V_182 ) ;
}
void F_141 ( struct V_1 * V_2 )
{
struct V_183 * V_168 ;
char V_184 [ V_185 + sizeof( L_5 ) + 1 ] ;
if ( F_142 ( V_181 , & V_2 -> V_18 ) != 0 )
return;
F_143 ( V_186 ) ;
F_50 ( & V_2 -> V_187 ) ;
F_23 () ;
snprintf ( V_184 , sizeof( V_184 ) , L_6 ,
F_144 ( V_2 -> V_188 , V_189 ) ) ;
F_25 () ;
V_168 = F_145 ( V_190 , V_2 , V_184 ) ;
if ( F_146 ( V_168 ) ) {
F_147 ( V_191 L_7 ,
V_192 , F_148 ( V_168 ) ) ;
F_136 ( V_2 ) ;
F_149 ( V_2 ) ;
F_150 ( V_186 ) ;
}
}
void F_151 ( struct V_1 * V_2 )
{
if ( ! V_2 )
return;
if ( ! F_3 ( V_193 , & V_2 -> V_18 ) )
F_5 ( V_194 , & V_2 -> V_18 ) ;
F_152 ( L_8 , V_192 ,
V_2 -> V_195 ) ;
F_141 ( V_2 ) ;
}
int F_153 ( struct V_1 * V_2 )
{
int V_196 ;
F_154 () ;
V_196 = F_155 ( & V_2 -> V_18 , V_181 ,
V_197 , V_198 ) ;
if ( V_196 )
return V_196 ;
if ( V_2 -> V_199 < 0 )
return V_2 -> V_199 ;
return 0 ;
}
int F_156 ( struct V_1 * V_2 )
{
unsigned int V_200 ;
int V_61 ;
for ( V_200 = V_201 ; V_200 != 0 ; V_200 -- ) {
V_61 = F_153 ( V_2 ) ;
if ( V_61 != 0 )
break;
if ( ! F_3 ( V_193 , & V_2 -> V_18 ) &&
! F_3 ( V_194 , & V_2 -> V_18 ) )
break;
F_141 ( V_2 ) ;
V_61 = - V_202 ;
}
return V_61 ;
}
static void F_157 ( struct V_1 * V_2 )
{
F_5 ( V_193 , & V_2 -> V_18 ) ;
F_158 ( V_2 ) ;
F_152 ( L_9 , V_192 ,
V_2 -> V_195 ) ;
}
void F_159 ( struct V_1 * V_2 )
{
F_157 ( V_2 ) ;
F_141 ( V_2 ) ;
}
static int F_160 ( struct V_1 * V_2 , struct V_96 * V_97 )
{
F_5 ( V_203 , & V_97 -> V_82 ) ;
if ( F_3 ( V_204 , & V_97 -> V_82 ) ) {
F_7 ( V_203 , & V_97 -> V_82 ) ;
return 0 ;
}
F_5 ( V_205 , & V_97 -> V_106 -> V_206 ) ;
F_5 ( V_207 , & V_2 -> V_18 ) ;
return 1 ;
}
static int F_161 ( struct V_1 * V_2 , struct V_96 * V_97 )
{
F_5 ( V_204 , & V_97 -> V_82 ) ;
F_7 ( V_203 , & V_97 -> V_82 ) ;
F_5 ( V_208 , & V_97 -> V_106 -> V_206 ) ;
F_5 ( V_209 , & V_2 -> V_18 ) ;
return 1 ;
}
void F_162 ( const struct V_30 * V_31 , struct V_96 * V_97 )
{
struct V_1 * V_2 = V_31 -> V_1 ;
F_161 ( V_2 , V_97 ) ;
F_152 ( L_10 , V_192 ,
V_2 -> V_195 ) ;
F_141 ( V_2 ) ;
}
void F_163 ( struct V_107 * V_107 ,
const T_5 * V_165 )
{
struct V_1 * V_2 = F_164 ( V_107 ) -> V_1 ;
struct V_108 * V_109 = F_91 ( V_107 ) ;
struct V_210 * V_211 ;
struct V_96 * V_97 ;
bool V_212 = false ;
F_14 ( & V_107 -> V_110 ) ;
F_92 (ctx, &nfsi->open_files, list) {
V_97 = V_211 -> V_97 ;
if ( V_97 == NULL )
continue;
if ( ! F_3 ( V_122 , & V_97 -> V_82 ) )
continue;
if ( ! F_165 ( & V_97 -> V_165 , V_165 ) )
continue;
F_161 ( V_2 , V_97 ) ;
V_212 = true ;
}
F_15 ( & V_107 -> V_110 ) ;
if ( V_212 )
F_141 ( V_2 ) ;
}
static int F_166 ( struct V_96 * V_97 , const struct V_213 * V_214 )
{
struct V_107 * V_107 = V_97 -> V_107 ;
struct V_108 * V_109 = F_91 ( V_107 ) ;
struct V_146 * V_151 ;
int V_12 = 0 ;
if ( V_107 -> V_215 == NULL )
return 0 ;
F_167 ( & V_109 -> V_216 ) ;
F_168 () ;
for ( V_151 = V_107 -> V_215 ; V_151 != NULL ; V_151 = V_151 -> V_217 ) {
if ( ! ( V_151 -> V_153 & ( V_154 | V_155 ) ) )
continue;
if ( F_169 ( V_151 -> V_218 ) -> V_97 != V_97 )
continue;
F_170 () ;
V_12 = V_214 -> V_219 ( V_97 , V_151 ) ;
switch ( V_12 ) {
case 0 :
break;
case - V_220 :
case - V_221 :
case - V_174 :
case - V_175 :
case - V_222 :
case - V_223 :
case - V_173 :
case - V_224 :
case - V_225 :
case - V_226 :
case - V_227 :
goto V_26;
default:
F_147 ( V_191 L_11
L_12 , V_192 , V_12 ) ;
case - V_157 :
case - V_228 :
case - V_229 :
case - V_230 :
V_12 = 0 ;
}
F_168 () ;
}
F_170 () ;
V_26:
F_171 ( & V_109 -> V_216 ) ;
return V_12 ;
}
static int F_172 ( struct V_32 * V_33 , const struct V_213 * V_214 )
{
struct V_96 * V_97 ;
struct V_124 * V_84 ;
int V_12 = 0 ;
V_231:
F_14 ( & V_33 -> V_88 ) ;
F_92 (state, &sp->so_states, open_states) {
if ( ! F_29 ( V_214 -> V_232 , & V_97 -> V_82 ) )
continue;
if ( V_97 -> V_97 == 0 )
continue;
F_50 ( & V_97 -> V_99 ) ;
F_15 ( & V_33 -> V_88 ) ;
V_12 = V_214 -> V_233 ( V_33 , V_97 ) ;
if ( V_12 >= 0 ) {
V_12 = F_166 ( V_97 , V_214 ) ;
if ( V_12 >= 0 ) {
F_14 ( & V_97 -> V_101 ) ;
F_92 (lock, &state->lock_states, ls_locks) {
if ( ! F_3 ( V_144 , & V_84 -> V_145 ) )
F_129 ( L_13
L_14
L_15 , V_192 ) ;
}
F_15 ( & V_97 -> V_101 ) ;
F_98 ( V_97 ) ;
goto V_231;
}
}
switch ( V_12 ) {
default:
F_147 ( V_191 L_11
L_12 , V_192 , V_12 ) ;
case - V_234 :
case - V_157 :
case - V_220 :
memset ( & V_97 -> V_165 , 0 ,
sizeof( V_97 -> V_165 ) ) ;
V_97 -> V_97 = 0 ;
break;
case - V_221 :
case - V_174 :
case - V_175 :
case - V_229 :
case - V_230 :
F_161 ( V_33 -> V_74 -> V_1 , V_97 ) ;
break;
case - V_222 :
case - V_223 :
F_161 ( V_33 -> V_74 -> V_1 , V_97 ) ;
case - V_173 :
case - V_224 :
case - V_225 :
case - V_226 :
case - V_227 :
goto V_235;
}
F_98 ( V_97 ) ;
goto V_231;
}
F_15 ( & V_33 -> V_88 ) ;
return 0 ;
V_235:
F_98 ( V_97 ) ;
return V_12 ;
}
static void F_173 ( struct V_96 * V_97 )
{
struct V_124 * V_84 ;
F_7 ( V_122 , & V_97 -> V_82 ) ;
F_7 ( V_119 , & V_97 -> V_82 ) ;
F_7 ( V_121 , & V_97 -> V_82 ) ;
F_7 ( V_120 , & V_97 -> V_82 ) ;
F_14 ( & V_97 -> V_101 ) ;
F_92 (lock, &state->lock_states, ls_locks) {
V_84 -> V_137 . V_82 = 0 ;
F_7 ( V_144 , & V_84 -> V_145 ) ;
}
F_15 ( & V_97 -> V_101 ) ;
}
static void F_174 ( struct V_30 * V_31 ,
int (* F_175)( struct V_1 * V_2 , struct V_96 * V_97 ) )
{
struct V_1 * V_2 = V_31 -> V_1 ;
struct V_32 * V_33 ;
struct V_34 * V_35 ;
struct V_96 * V_97 ;
F_14 ( & V_2 -> V_29 ) ;
for ( V_35 = F_18 ( & V_31 -> V_36 ) ;
V_35 != NULL ;
V_35 = F_19 ( V_35 ) ) {
V_33 = F_20 ( V_35 , struct V_32 , V_37 ) ;
V_33 -> V_77 . V_82 = 0 ;
F_14 ( & V_33 -> V_88 ) ;
F_92 (state, &sp->so_states, open_states) {
if ( F_175 ( V_2 , V_97 ) )
F_173 ( V_97 ) ;
}
F_15 ( & V_33 -> V_88 ) ;
}
F_15 ( & V_2 -> V_29 ) ;
}
static void F_176 ( struct V_1 * V_2 ,
int (* F_175)( struct V_1 * V_2 , struct V_96 * V_97 ) )
{
struct V_30 * V_31 ;
F_23 () ;
F_24 (server, &clp->cl_superblocks, client_link)
F_174 ( V_31 , F_175 ) ;
F_25 () ;
}
static void F_177 ( struct V_1 * V_2 )
{
F_178 ( V_2 ) ;
F_176 ( V_2 , F_160 ) ;
}
static void F_179 ( struct V_1 * V_2 ,
const struct V_213 * V_214 )
{
if ( V_214 -> V_236 )
( void ) V_214 -> V_236 ( V_2 ) ;
}
static void F_180 ( struct V_30 * V_31 )
{
struct V_1 * V_2 = V_31 -> V_1 ;
struct V_32 * V_33 ;
struct V_34 * V_35 ;
struct V_96 * V_97 ;
F_14 ( & V_2 -> V_29 ) ;
for ( V_35 = F_18 ( & V_31 -> V_36 ) ;
V_35 != NULL ;
V_35 = F_19 ( V_35 ) ) {
V_33 = F_20 ( V_35 , struct V_32 , V_37 ) ;
F_14 ( & V_33 -> V_88 ) ;
F_92 (state, &sp->so_states, open_states) {
if ( ! F_29 ( V_203 ,
& V_97 -> V_82 ) )
continue;
F_161 ( V_2 , V_97 ) ;
}
F_15 ( & V_33 -> V_88 ) ;
}
F_15 ( & V_2 -> V_29 ) ;
}
static int F_181 ( struct V_1 * V_2 )
{
struct V_30 * V_31 ;
if ( ! F_29 ( V_207 , & V_2 -> V_18 ) )
return 0 ;
F_23 () ;
F_24 (server, &clp->cl_superblocks, client_link)
F_180 ( V_31 ) ;
F_25 () ;
F_182 ( V_2 ) ;
return 1 ;
}
static void F_183 ( struct V_1 * V_2 )
{
if ( ! F_181 ( V_2 ) )
return;
F_179 ( V_2 , V_2 -> V_237 -> V_238 ) ;
}
static void F_184 ( struct V_1 * V_2 )
{
F_178 ( V_2 ) ;
F_182 ( V_2 ) ;
}
static void F_185 ( struct V_1 * V_2 )
{
F_184 ( V_2 ) ;
F_176 ( V_2 , F_161 ) ;
}
static int F_186 ( struct V_1 * V_2 , int error )
{
switch ( error ) {
case 0 :
break;
case - V_239 :
F_157 ( V_2 ) ;
break;
case - V_223 :
F_183 ( V_2 ) ;
break;
case - V_173 :
case - V_240 :
F_5 ( V_193 , & V_2 -> V_18 ) ;
F_181 ( V_2 ) ;
F_177 ( V_2 ) ;
break;
case - V_222 :
F_5 ( V_193 , & V_2 -> V_18 ) ;
F_185 ( V_2 ) ;
break;
case - V_224 :
case - V_225 :
case - V_226 :
case - V_241 :
case - V_242 :
case - V_243 :
F_5 ( V_63 , & V_2 -> V_18 ) ;
break;
case - V_227 :
F_5 ( V_64 , & V_2 -> V_18 ) ;
break;
default:
F_152 ( L_16 ,
V_192 , error , V_2 -> V_195 ) ;
return error ;
}
F_152 ( L_17 , V_192 , error ,
V_2 -> V_195 ) ;
return 0 ;
}
static int F_187 ( struct V_1 * V_2 , const struct V_213 * V_214 )
{
struct V_32 * V_33 ;
struct V_30 * V_31 ;
struct V_34 * V_35 ;
int V_12 = 0 ;
V_231:
F_23 () ;
F_24 (server, &clp->cl_superblocks, client_link) {
F_85 ( V_31 ) ;
F_14 ( & V_2 -> V_29 ) ;
for ( V_35 = F_18 ( & V_31 -> V_36 ) ;
V_35 != NULL ;
V_35 = F_19 ( V_35 ) ) {
V_33 = F_20 ( V_35 ,
struct V_32 , V_37 ) ;
if ( ! F_29 ( V_214 -> V_244 ,
& V_33 -> V_206 ) )
continue;
F_50 ( & V_33 -> V_72 ) ;
F_15 ( & V_2 -> V_29 ) ;
F_25 () ;
V_12 = F_172 ( V_33 , V_214 ) ;
if ( V_12 < 0 ) {
F_5 ( V_214 -> V_244 , & V_33 -> V_206 ) ;
F_82 ( V_33 ) ;
return F_186 ( V_2 , V_12 ) ;
}
F_82 ( V_33 ) ;
goto V_231;
}
F_15 ( & V_2 -> V_29 ) ;
}
F_25 () ;
return V_12 ;
}
static int F_188 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
const struct V_245 * V_214 =
V_2 -> V_237 -> V_246 ;
int V_12 ;
if ( F_3 ( V_193 , & V_2 -> V_18 ) )
return 0 ;
F_14 ( & V_2 -> V_29 ) ;
V_4 = V_214 -> V_247 ( V_2 ) ;
F_15 ( & V_2 -> V_29 ) ;
if ( V_4 == NULL ) {
V_4 = F_47 ( V_2 ) ;
V_12 = - V_248 ;
if ( V_4 == NULL )
goto V_26;
}
V_12 = V_214 -> V_249 ( V_2 , V_4 ) ;
F_16 ( V_4 ) ;
V_26:
return F_186 ( V_2 , V_12 ) ;
}
static int F_189 ( struct V_1 * V_2 , int V_12 )
{
switch ( V_12 ) {
case - V_243 :
if ( F_142 ( V_250 , & V_2 -> V_18 ) )
return - V_251 ;
F_190 ( 1 ) ;
F_7 ( V_17 , & V_2 -> V_18 ) ;
break;
case - V_173 :
F_7 ( V_17 , & V_2 -> V_18 ) ;
F_181 ( V_2 ) ;
F_177 ( V_2 ) ;
break;
case - V_252 :
F_191 ( L_18 ,
V_2 -> V_195 ) ;
F_42 ( V_2 , - V_253 ) ;
F_7 ( V_17 , & V_2 -> V_18 ) ;
return - V_253 ;
case - V_254 :
if ( V_2 -> V_28 == NULL )
return - V_254 ;
F_13 ( V_2 ) ;
case - V_255 :
case - V_256 :
case - V_94 :
F_190 ( 1 ) ;
break;
case - V_257 :
if ( V_2 -> V_199 == V_258 )
F_42 ( V_2 , - V_259 ) ;
F_152 ( L_19 ,
V_192 , - V_259 , V_2 -> V_195 ) ;
return - V_259 ;
case - V_260 :
default:
F_152 ( L_19 , V_192 ,
V_12 , V_2 -> V_195 ) ;
return V_12 ;
}
F_5 ( V_193 , & V_2 -> V_18 ) ;
F_152 ( L_17 , V_192 , V_12 ,
V_2 -> V_195 ) ;
return 0 ;
}
static int F_192 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
const struct V_213 * V_214 =
V_2 -> V_237 -> V_238 ;
int V_12 ;
V_4 = V_214 -> V_261 ( V_2 ) ;
if ( V_4 == NULL )
return - V_234 ;
V_12 = V_214 -> V_262 ( V_2 , V_4 ) ;
F_16 ( V_4 ) ;
if ( V_12 != 0 )
return V_12 ;
F_193 ( V_2 ) ;
return 0 ;
}
static int F_194 ( struct V_1 * V_2 )
{
int V_12 ;
V_12 = F_192 ( V_2 ) ;
if ( V_12 < 0 )
return F_189 ( V_2 , V_12 ) ;
if ( F_29 ( V_263 , & V_2 -> V_18 ) )
F_185 ( V_2 ) ;
if ( ! F_3 ( V_209 , & V_2 -> V_18 ) )
F_5 ( V_207 , & V_2 -> V_18 ) ;
F_7 ( V_194 , & V_2 -> V_18 ) ;
F_7 ( V_193 , & V_2 -> V_18 ) ;
return 0 ;
}
static int F_195 ( struct V_1 * V_2 )
{
int V_12 ;
V_12 = F_192 ( V_2 ) ;
if ( V_12 < 0 )
return F_189 ( V_2 , V_12 ) ;
F_7 ( V_250 , & V_2 -> V_18 ) ;
F_5 ( V_193 , & V_2 -> V_18 ) ;
F_185 ( V_2 ) ;
return 0 ;
}
int F_196 ( struct V_1 * V_2 ,
struct V_1 * * V_27 )
{
const struct V_213 * V_214 =
V_2 -> V_237 -> V_238 ;
T_6 * V_264 , V_265 , V_266 ;
struct V_267 * V_268 ;
struct V_3 * V_4 ;
int V_269 , V_270 , V_12 ;
F_152 ( L_20 , V_192 , V_2 -> V_195 ) ;
V_270 = V_271 ;
V_264 = F_197 ( V_270 , sizeof( * V_264 ) , V_123 ) ;
if ( V_264 == NULL ) {
V_12 = - V_157 ;
goto V_26;
}
V_270 = F_198 ( V_264 , V_270 ) ;
if ( V_270 < 0 ) {
V_12 = V_270 ;
goto V_139;
}
V_268 = V_2 -> V_188 ;
V_266 = V_268 -> V_272 -> V_273 ;
V_269 = 0 ;
F_199 ( & V_274 ) ;
V_12 = - V_234 ;
V_275:
V_4 = V_214 -> V_261 ( V_2 ) ;
if ( V_4 == NULL )
goto V_276;
V_12 = V_214 -> V_277 ( V_2 , V_27 , V_4 ) ;
F_16 ( V_4 ) ;
switch ( V_12 ) {
case 0 :
break;
case - V_254 :
if ( V_2 -> V_28 == NULL )
break;
F_13 ( V_2 ) ;
case - V_255 :
case - V_256 :
case - V_94 :
F_190 ( 1 ) ;
case - V_173 :
F_152 ( L_21 ,
V_192 , V_12 ) ;
goto V_275;
case - V_252 :
case - V_278 :
V_12 = - V_253 ;
if ( V_269 >= V_270 )
break;
V_265 = V_264 [ V_269 ++ ] ;
if ( V_265 == V_266 )
V_265 = V_264 [ V_269 ++ ] ;
V_268 = F_200 ( V_268 , V_265 ) ;
if ( F_146 ( V_268 ) ) {
V_12 = F_148 ( V_268 ) ;
break;
}
V_2 -> V_188 = V_268 ;
goto V_275;
case - V_257 :
V_12 = - V_259 ;
break;
case - V_279 :
case - V_260 :
V_12 = - V_279 ;
}
V_276:
F_201 ( & V_274 ) ;
V_139:
F_73 ( V_264 ) ;
V_26:
F_152 ( L_22 , V_192 , V_12 ) ;
return V_12 ;
}
void F_202 ( struct V_49 * V_58 , int V_75 )
{
struct V_1 * V_2 = V_58 -> V_2 ;
switch ( V_75 ) {
default:
F_5 ( V_63 , & V_2 -> V_18 ) ;
break;
case - V_227 :
F_5 ( V_64 , & V_2 -> V_18 ) ;
}
F_151 ( V_2 ) ;
}
static void F_203 ( struct V_1 * V_2 )
{
F_5 ( V_194 , & V_2 -> V_18 ) ;
F_141 ( V_2 ) ;
}
void F_204 ( struct V_1 * V_2 )
{
F_203 ( V_2 ) ;
}
void F_205 ( struct V_1 * V_2 )
{
F_203 ( V_2 ) ;
}
static void F_206 ( struct V_1 * V_2 )
{
if ( F_142 ( V_193 , & V_2 -> V_18 ) == 0 ) {
F_5 ( V_250 , & V_2 -> V_18 ) ;
F_7 ( V_17 , & V_2 -> V_18 ) ;
F_185 ( V_2 ) ;
F_152 ( L_23 ,
V_192 , V_2 -> V_195 ) ;
F_141 ( V_2 ) ;
}
}
static void F_207 ( struct V_1 * V_2 )
{
if ( F_142 ( V_193 , & V_2 -> V_18 ) == 0 ) {
F_177 ( V_2 ) ;
F_152 ( L_24 , V_192 ,
V_2 -> V_195 ) ;
F_141 ( V_2 ) ;
}
}
static void F_208 ( struct V_1 * V_2 )
{
F_206 ( V_2 ) ;
F_152 ( L_25 , V_192 , V_2 -> V_195 ) ;
}
static void F_209 ( struct V_1 * V_2 )
{
F_158 ( V_2 ) ;
F_152 ( L_26 , V_192 ,
V_2 -> V_195 ) ;
}
static void F_210 ( struct V_1 * V_2 )
{
F_158 ( V_2 ) ;
if ( F_142 ( V_63 , & V_2 -> V_18 ) == 0 )
F_141 ( V_2 ) ;
F_152 ( L_27 , V_192 ,
V_2 -> V_195 ) ;
}
static void F_211 ( struct V_1 * V_2 )
{
if ( F_142 ( V_64 ,
& V_2 -> V_18 ) == 0 )
F_141 ( V_2 ) ;
}
void F_212 ( struct V_1 * V_2 , T_7 V_82 )
{
if ( ! V_82 )
return;
F_152 ( L_28 ,
V_192 , V_2 -> V_195 , V_2 -> V_8 , V_82 ) ;
if ( V_82 & V_280 )
F_207 ( V_2 ) ;
if ( V_82 & ( V_281 |
V_282 |
V_283 |
V_284 ) )
F_208 ( V_2 ) ;
if ( V_82 & V_285 )
F_209 ( V_2 ) ;
if ( V_82 & V_286 )
F_210 ( V_2 ) ;
else if ( V_82 & ( V_287 |
V_288 ) )
F_211 ( V_2 ) ;
}
static int F_213 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
int V_12 ;
if ( ! F_132 ( V_2 ) )
return 0 ;
F_37 ( V_2 ) ;
V_4 = F_45 ( V_2 ) ;
V_12 = F_214 ( V_2 -> V_51 , V_4 ) ;
switch ( V_12 ) {
case 0 :
case - V_224 :
case - V_241 :
break;
case - V_289 :
case - V_255 :
F_5 ( V_63 , & V_2 -> V_18 ) ;
V_12 = 0 ;
F_190 ( 1 ) ;
goto V_26;
default:
V_12 = F_186 ( V_2 , V_12 ) ;
goto V_26;
}
memset ( V_2 -> V_51 -> V_290 . V_291 , 0 , V_292 ) ;
V_12 = F_41 ( V_2 , V_4 ) ;
if ( V_12 ) {
F_152 ( L_29 ,
V_192 , V_12 , V_2 -> V_195 ) ;
V_12 = F_189 ( V_2 , V_12 ) ;
goto V_26;
}
F_38 ( V_2 ) ;
F_152 ( L_30 ,
V_192 , V_2 -> V_195 ) ;
V_26:
if ( V_4 )
F_16 ( V_4 ) ;
return V_12 ;
}
static int F_215 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
int V_61 ;
if ( ! F_132 ( V_2 ) )
return 0 ;
F_37 ( V_2 ) ;
V_4 = F_45 ( V_2 ) ;
V_61 = F_216 ( V_2 , V_4 ) ;
if ( V_4 )
F_16 ( V_4 ) ;
F_7 ( V_64 , & V_2 -> V_18 ) ;
switch ( V_61 ) {
case 0 :
F_152 ( L_31 ,
V_192 , V_2 -> V_195 ) ;
break;
case - V_255 :
F_190 ( 1 ) ;
F_5 ( V_64 , & V_2 -> V_18 ) ;
break;
default:
return F_186 ( V_2 , V_61 ) ;
}
return 0 ;
}
static int F_213 ( struct V_1 * V_2 ) { return 0 ; }
static int F_28 ( struct V_1 * V_2 ) { return 0 ; }
static int F_215 ( struct V_1 * V_2 )
{
return 0 ;
}
static void F_217 ( struct V_1 * V_2 )
{
int V_12 = 0 ;
const char * V_293 = L_32 , * V_294 = L_32 ;
do {
if ( F_3 ( V_250 , & V_2 -> V_18 ) ) {
V_293 = L_33 ;
V_12 = F_195 ( V_2 ) ;
if ( V_12 < 0 )
goto V_295;
continue;
}
if ( F_3 ( V_193 , & V_2 -> V_18 ) ) {
V_293 = L_34 ;
V_12 = F_194 ( V_2 ) ;
if ( V_12 < 0 )
goto V_295;
continue;
}
if ( F_29 ( V_63 , & V_2 -> V_18 ) ) {
V_293 = L_35 ;
V_12 = F_213 ( V_2 ) ;
if ( F_3 ( V_193 , & V_2 -> V_18 ) )
continue;
if ( V_12 < 0 )
goto V_295;
}
if ( F_29 ( V_64 ,
& V_2 -> V_18 ) ) {
V_293 = L_36 ;
V_12 = F_215 ( V_2 ) ;
if ( V_12 < 0 )
goto V_295;
continue;
}
if ( F_29 ( V_194 , & V_2 -> V_18 ) ) {
V_293 = L_37 ;
V_12 = F_188 ( V_2 ) ;
if ( V_12 < 0 )
goto V_295;
continue;
}
if ( F_3 ( V_207 , & V_2 -> V_18 ) ) {
V_293 = L_38 ;
V_12 = F_187 ( V_2 ,
V_2 -> V_237 -> V_238 ) ;
if ( F_3 ( V_193 , & V_2 -> V_18 ) ||
F_3 ( V_63 , & V_2 -> V_18 ) )
continue;
F_183 ( V_2 ) ;
if ( F_3 ( V_209 , & V_2 -> V_18 ) )
continue;
if ( V_12 < 0 )
goto V_295;
}
if ( F_29 ( V_209 , & V_2 -> V_18 ) ) {
V_293 = L_39 ;
V_12 = F_187 ( V_2 ,
V_2 -> V_237 -> V_296 ) ;
if ( F_3 ( V_193 , & V_2 -> V_18 ) ||
F_3 ( V_63 , & V_2 -> V_18 ) ||
F_3 ( V_207 , & V_2 -> V_18 ) )
continue;
if ( V_12 < 0 )
goto V_295;
}
F_28 ( V_2 ) ;
if ( F_29 ( V_297 , & V_2 -> V_18 ) ) {
F_218 ( V_2 ) ;
continue;
}
F_136 ( V_2 ) ;
if ( V_2 -> V_18 == 0 )
break;
if ( F_142 ( V_181 , & V_2 -> V_18 ) != 0 )
break;
} while ( F_219 ( & V_2 -> V_187 ) > 1 );
return;
V_295:
if ( strlen ( V_293 ) )
V_294 = L_40 ;
F_129 ( L_41
L_42 , V_294 , V_293 ,
V_2 -> V_195 , - V_12 ) ;
F_190 ( 1 ) ;
F_28 ( V_2 ) ;
F_136 ( V_2 ) ;
}
static int V_190 ( void * V_298 )
{
struct V_1 * V_2 = V_298 ;
F_220 ( V_299 ) ;
F_217 ( V_2 ) ;
F_149 ( V_2 ) ;
F_221 ( 0 ) ;
return 0 ;
}
