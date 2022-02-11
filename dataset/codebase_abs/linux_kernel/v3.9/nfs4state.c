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
F_70 ( & V_33 -> V_89 ) ;
F_71 ( & V_33 -> V_90 ) ;
return V_33 ;
}
static void
F_72 ( struct V_32 * V_33 )
{
struct V_34 * V_34 = & V_33 -> V_37 ;
if ( ! F_57 ( V_34 ) ) {
struct V_30 * V_31 = V_33 -> V_74 ;
struct V_1 * V_2 = V_31 -> V_1 ;
F_14 ( & V_2 -> V_29 ) ;
if ( ! F_57 ( V_34 ) ) {
F_58 ( V_34 , & V_31 -> V_36 ) ;
F_73 ( V_34 ) ;
}
F_15 ( & V_2 -> V_29 ) ;
}
}
static void F_74 ( struct V_32 * V_33 )
{
F_65 ( & V_33 -> V_77 ) ;
F_16 ( V_33 -> V_39 ) ;
F_75 ( V_33 ) ;
}
static void F_76 ( struct V_30 * V_31 )
{
struct V_1 * V_2 = V_31 -> V_1 ;
struct V_32 * V_33 , * V_91 ;
unsigned long V_92 , V_93 ;
F_77 ( V_94 ) ;
F_14 ( & V_2 -> V_29 ) ;
V_93 = V_48 ;
V_92 = ( long ) V_93 - ( long ) V_2 -> V_44 ;
F_78 (sp, tmp, &server->state_owners_lru, so_lru) {
if ( F_79 ( V_33 -> V_95 , V_92 , V_93 ) )
break;
F_80 ( & V_33 -> V_71 , & V_94 ) ;
F_56 ( V_33 ) ;
}
F_15 ( & V_2 -> V_29 ) ;
F_78 (sp, tmp, &doomed, so_lru) {
F_81 ( & V_33 -> V_71 ) ;
F_74 ( V_33 ) ;
}
}
struct V_32 * F_82 ( struct V_30 * V_31 ,
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
if ( F_83 ( & V_31 -> V_76 , V_87 ) == 0 )
break;
F_14 ( & V_2 -> V_29 ) ;
V_33 = F_51 ( V_73 ) ;
F_15 ( & V_2 -> V_29 ) ;
} while ( V_33 == F_53 ( - V_96 ) );
if ( V_33 != V_73 )
F_74 ( V_73 ) ;
V_26:
F_76 ( V_31 ) ;
return V_33 ;
}
void F_84 ( struct V_32 * V_33 )
{
struct V_30 * V_31 = V_33 -> V_74 ;
struct V_1 * V_2 = V_31 -> V_1 ;
if ( ! F_85 ( & V_33 -> V_72 , & V_2 -> V_29 ) )
return;
V_33 -> V_95 = V_48 ;
F_86 ( & V_33 -> V_71 , & V_31 -> V_97 ) ;
F_15 ( & V_2 -> V_29 ) ;
}
void F_87 ( struct V_30 * V_31 )
{
struct V_1 * V_2 = V_31 -> V_1 ;
struct V_32 * V_33 , * V_91 ;
F_77 ( V_94 ) ;
F_14 ( & V_2 -> V_29 ) ;
F_78 (sp, tmp, &server->state_owners_lru, so_lru) {
F_80 ( & V_33 -> V_71 , & V_94 ) ;
F_56 ( V_33 ) ;
}
F_15 ( & V_2 -> V_29 ) ;
F_78 (sp, tmp, &doomed, so_lru) {
F_81 ( & V_33 -> V_71 ) ;
F_74 ( V_33 ) ;
}
}
static struct V_98 *
F_88 ( void )
{
struct V_98 * V_99 ;
V_99 = F_68 ( sizeof( * V_99 ) , V_100 ) ;
if ( ! V_99 )
return NULL ;
F_69 ( & V_99 -> V_101 , 1 ) ;
F_63 ( & V_99 -> V_102 ) ;
F_62 ( & V_99 -> V_103 ) ;
F_89 ( & V_99 -> V_104 ) ;
return V_99 ;
}
void
F_90 ( struct V_98 * V_99 , T_2 V_105 )
{
if ( V_99 -> V_99 == V_105 )
return;
if ( ( V_105 & V_106 ) != ( V_99 -> V_99 & V_106 ) ) {
if ( V_105 & V_106 )
F_80 ( & V_99 -> V_107 , & V_99 -> V_108 -> V_38 ) ;
else
F_91 ( & V_99 -> V_107 , & V_99 -> V_108 -> V_38 ) ;
}
V_99 -> V_99 = V_105 ;
}
static struct V_98 *
F_92 ( struct V_109 * V_109 , struct V_32 * V_108 )
{
struct V_110 * V_111 = F_93 ( V_109 ) ;
struct V_98 * V_99 ;
F_94 (state, &nfsi->open_states, inode_states) {
if ( V_99 -> V_108 != V_108 )
continue;
if ( F_95 ( & V_99 -> V_101 ) )
return V_99 ;
}
return NULL ;
}
static void
F_96 ( struct V_98 * V_99 )
{
F_75 ( V_99 ) ;
}
struct V_98 *
F_97 ( struct V_109 * V_109 , struct V_32 * V_108 )
{
struct V_98 * V_99 , * V_73 ;
struct V_110 * V_111 = F_93 ( V_109 ) ;
F_14 ( & V_109 -> V_112 ) ;
V_99 = F_92 ( V_109 , V_108 ) ;
F_15 ( & V_109 -> V_112 ) ;
if ( V_99 )
goto V_26;
V_73 = F_88 () ;
F_14 ( & V_108 -> V_88 ) ;
F_14 ( & V_109 -> V_112 ) ;
V_99 = F_92 ( V_109 , V_108 ) ;
if ( V_99 == NULL && V_73 != NULL ) {
V_99 = V_73 ;
V_99 -> V_108 = V_108 ;
F_50 ( & V_108 -> V_72 ) ;
F_98 ( & V_99 -> V_113 , & V_111 -> V_107 ) ;
F_99 ( V_109 ) ;
V_99 -> V_109 = V_109 ;
F_15 ( & V_109 -> V_112 ) ;
F_86 ( & V_99 -> V_107 , & V_108 -> V_38 ) ;
F_15 ( & V_108 -> V_88 ) ;
} else {
F_15 ( & V_109 -> V_112 ) ;
F_15 ( & V_108 -> V_88 ) ;
if ( V_73 )
F_96 ( V_73 ) ;
}
V_26:
return V_99 ;
}
void F_100 ( struct V_98 * V_99 )
{
struct V_109 * V_109 = V_99 -> V_109 ;
struct V_32 * V_108 = V_99 -> V_108 ;
if ( ! F_85 ( & V_99 -> V_101 , & V_108 -> V_88 ) )
return;
F_14 ( & V_109 -> V_112 ) ;
F_81 ( & V_99 -> V_113 ) ;
F_81 ( & V_99 -> V_107 ) ;
F_15 ( & V_109 -> V_112 ) ;
F_15 ( & V_108 -> V_88 ) ;
F_101 ( V_109 ) ;
F_96 ( V_99 ) ;
F_84 ( V_108 ) ;
}
static void F_102 ( struct V_98 * V_99 ,
T_2 V_105 , T_1 V_114 , int V_86 )
{
struct V_32 * V_108 = V_99 -> V_108 ;
int V_115 = 0 ;
T_2 V_116 ;
F_50 ( & V_108 -> V_72 ) ;
F_14 ( & V_108 -> V_88 ) ;
switch ( V_105 & ( V_117 | V_106 ) ) {
case V_117 :
V_99 -> V_118 -- ;
break;
case V_106 :
V_99 -> V_119 -- ;
break;
case V_117 | V_106 :
V_99 -> V_120 -- ;
}
V_116 = V_117 | V_106 ;
if ( V_99 -> V_120 == 0 ) {
if ( V_99 -> V_118 == 0 ) {
V_116 &= ~ V_117 ;
V_115 |= F_3 ( V_121 , & V_99 -> V_82 ) ;
V_115 |= F_3 ( V_122 , & V_99 -> V_82 ) ;
}
if ( V_99 -> V_119 == 0 ) {
V_116 &= ~ V_106 ;
V_115 |= F_3 ( V_123 , & V_99 -> V_82 ) ;
V_115 |= F_3 ( V_122 , & V_99 -> V_82 ) ;
}
if ( V_116 == 0 )
F_7 ( V_124 , & V_99 -> V_82 ) ;
}
F_90 ( V_99 , V_116 ) ;
F_15 ( & V_108 -> V_88 ) ;
if ( ! V_115 ) {
F_100 ( V_99 ) ;
F_84 ( V_108 ) ;
} else
F_103 ( V_99 , V_114 , V_86 ) ;
}
void F_104 ( struct V_98 * V_99 , T_2 V_105 )
{
F_102 ( V_99 , V_105 , V_100 , 0 ) ;
}
void F_105 ( struct V_98 * V_99 , T_2 V_105 )
{
F_102 ( V_99 , V_105 , V_125 , 1 ) ;
}
static struct V_126 *
F_106 ( struct V_98 * V_99 , T_3 V_127 , T_4 V_128 , unsigned int type )
{
struct V_126 * V_35 ;
F_94 (pos, &state->lock_states, ls_locks) {
if ( type != V_129 && V_35 -> V_130 . V_131 != type )
continue;
switch ( V_35 -> V_130 . V_131 ) {
case V_132 :
if ( V_35 -> V_130 . V_133 . V_134 != V_127 )
continue;
break;
case V_135 :
if ( V_35 -> V_130 . V_133 . V_136 != V_128 )
continue;
}
F_50 ( & V_35 -> V_137 ) ;
return V_35 ;
}
return NULL ;
}
static struct V_126 * F_107 ( struct V_98 * V_99 , T_3 V_127 , T_4 V_128 , unsigned int type )
{
struct V_126 * V_138 ;
struct V_30 * V_31 = V_99 -> V_108 -> V_74 ;
V_138 = F_68 ( sizeof( * V_138 ) , V_100 ) ;
if ( V_138 == NULL )
return NULL ;
F_60 ( & V_138 -> V_139 ) ;
F_69 ( & V_138 -> V_137 , 1 ) ;
V_138 -> V_140 = V_99 ;
V_138 -> V_130 . V_131 = type ;
switch ( V_138 -> V_130 . V_131 ) {
case V_135 :
V_138 -> V_130 . V_133 . V_136 = V_128 ;
break;
case V_132 :
V_138 -> V_130 . V_133 . V_134 = V_127 ;
break;
default:
goto V_141;
}
V_138 -> V_139 . V_78 = F_108 ( & V_31 -> V_142 , 0 , 0 , V_100 ) ;
if ( V_138 -> V_139 . V_78 < 0 )
goto V_141;
F_63 ( & V_138 -> V_143 ) ;
return V_138 ;
V_141:
F_75 ( V_138 ) ;
return NULL ;
}
void F_109 ( struct V_30 * V_31 , struct V_126 * V_138 )
{
F_110 ( & V_31 -> V_142 , V_138 -> V_139 . V_78 ) ;
F_65 ( & V_138 -> V_139 ) ;
F_75 ( V_138 ) ;
}
static struct V_126 * F_111 ( struct V_98 * V_99 , T_3 V_108 , T_4 V_144 , unsigned int type )
{
struct V_126 * V_138 , * V_73 = NULL ;
for(; ; ) {
F_14 ( & V_99 -> V_103 ) ;
V_138 = F_106 ( V_99 , V_108 , V_144 , type ) ;
if ( V_138 != NULL )
break;
if ( V_73 != NULL ) {
F_98 ( & V_73 -> V_143 , & V_99 -> V_102 ) ;
F_5 ( V_145 , & V_99 -> V_82 ) ;
V_138 = V_73 ;
V_73 = NULL ;
break;
}
F_15 ( & V_99 -> V_103 ) ;
V_73 = F_107 ( V_99 , V_108 , V_144 , type ) ;
if ( V_73 == NULL )
return NULL ;
}
F_15 ( & V_99 -> V_103 ) ;
if ( V_73 != NULL )
F_109 ( V_99 -> V_108 -> V_74 , V_73 ) ;
return V_138 ;
}
void F_112 ( struct V_126 * V_138 )
{
struct V_98 * V_99 ;
if ( V_138 == NULL )
return;
V_99 = V_138 -> V_140 ;
if ( ! F_85 ( & V_138 -> V_137 , & V_99 -> V_103 ) )
return;
F_81 ( & V_138 -> V_143 ) ;
if ( F_21 ( & V_99 -> V_102 ) )
F_7 ( V_145 , & V_99 -> V_82 ) ;
F_15 ( & V_99 -> V_103 ) ;
if ( F_3 ( V_146 , & V_138 -> V_147 ) ) {
if ( F_113 ( V_138 ) == 0 )
return;
}
F_109 ( V_138 -> V_140 -> V_108 -> V_74 , V_138 ) ;
}
static void F_114 ( struct V_148 * V_149 , struct V_148 * V_150 )
{
struct V_126 * V_138 = V_150 -> V_151 . V_152 . V_108 ;
V_149 -> V_151 . V_152 . V_108 = V_138 ;
F_50 ( & V_138 -> V_137 ) ;
}
static void F_115 ( struct V_148 * V_153 )
{
F_112 ( V_153 -> V_151 . V_152 . V_108 ) ;
}
int F_116 ( struct V_98 * V_99 , struct V_148 * V_153 )
{
struct V_126 * V_138 ;
if ( V_153 -> V_154 != NULL )
return 0 ;
if ( V_153 -> V_155 & V_156 )
V_138 = F_111 ( V_99 , V_153 -> V_127 , 0 , V_132 ) ;
else if ( V_153 -> V_155 & V_157 )
V_138 = F_111 ( V_99 , NULL , V_153 -> V_128 ,
V_135 ) ;
else
return - V_158 ;
if ( V_138 == NULL )
return - V_159 ;
V_153 -> V_151 . V_152 . V_108 = V_138 ;
V_153 -> V_154 = & V_160 ;
return 0 ;
}
static bool F_117 ( T_5 * V_149 , struct V_98 * V_99 ,
const struct V_161 * V_162 )
{
struct V_126 * V_138 ;
T_3 V_127 ;
T_4 V_128 ;
bool V_61 = false ;
if ( V_162 == NULL )
goto V_26;
if ( F_3 ( V_145 , & V_99 -> V_82 ) == 0 )
goto V_26;
V_127 = V_162 -> V_163 ;
V_128 = V_162 -> V_164 ;
F_14 ( & V_99 -> V_103 ) ;
V_138 = F_106 ( V_99 , V_127 , V_128 , V_129 ) ;
if ( V_138 != NULL && F_3 ( V_146 , & V_138 -> V_147 ) != 0 ) {
F_118 ( V_149 , & V_138 -> V_165 ) ;
V_61 = true ;
}
F_15 ( & V_99 -> V_103 ) ;
F_112 ( V_138 ) ;
V_26:
return V_61 ;
}
static void F_119 ( T_5 * V_149 , struct V_98 * V_99 )
{
int V_166 ;
do {
V_166 = F_120 ( & V_99 -> V_104 ) ;
F_118 ( V_149 , & V_99 -> V_167 ) ;
} while ( F_121 ( & V_99 -> V_104 , V_166 ) );
}
void F_122 ( T_5 * V_149 , struct V_98 * V_99 ,
T_2 V_105 , const struct V_161 * V_162 )
{
if ( F_123 ( V_149 , V_99 -> V_109 , V_105 ) )
return;
if ( F_117 ( V_149 , V_99 , V_162 ) )
return;
F_119 ( V_149 , V_99 ) ;
}
struct V_168 * F_124 ( struct V_79 * V_83 , T_1 V_114 )
{
struct V_168 * V_73 ;
V_73 = F_125 ( sizeof( * V_73 ) , V_114 ) ;
if ( V_73 != NULL ) {
V_73 -> V_169 = V_83 ;
F_63 ( & V_73 -> V_85 ) ;
V_73 -> V_170 = NULL ;
}
return V_73 ;
}
void F_126 ( struct V_168 * V_171 )
{
struct V_79 * V_169 ;
if ( F_21 ( & V_171 -> V_85 ) )
return;
V_169 = V_171 -> V_169 ;
F_14 ( & V_169 -> V_84 ) ;
F_49 ( & V_171 -> V_85 ) ;
if ( ! F_21 ( & V_169 -> V_85 ) ) {
struct V_168 * V_172 ;
V_172 = F_127 ( & V_169 -> V_85 ,
struct V_168 , V_85 ) ;
F_128 ( & V_169 -> V_86 , V_172 -> V_170 ) ;
}
F_15 ( & V_169 -> V_84 ) ;
}
void F_129 ( struct V_168 * V_171 )
{
F_126 ( V_171 ) ;
F_75 ( V_171 ) ;
}
static void F_130 ( int V_12 , struct V_168 * V_171 )
{
switch ( V_12 ) {
case 0 :
break;
case - V_173 :
if ( V_171 -> V_169 -> V_82 & V_174 )
return;
F_131 ( L_2
L_3
L_4 ,
V_171 -> V_169 ) ;
case - V_175 :
case - V_176 :
case - V_177 :
case - V_178 :
case - V_179 :
case - V_180 :
return;
} ;
V_171 -> V_169 -> V_83 ++ ;
}
void F_132 ( int V_12 , struct V_168 * V_171 )
{
struct V_32 * V_33 = F_133 ( V_171 -> V_169 ,
struct V_32 , V_77 ) ;
struct V_30 * V_31 = V_33 -> V_74 ;
if ( V_12 == - V_173 )
F_72 ( V_33 ) ;
if ( ! F_134 ( V_31 -> V_1 ) )
F_130 ( V_12 , V_171 ) ;
}
void F_135 ( int V_12 , struct V_168 * V_171 )
{
F_130 ( V_12 , V_171 ) ;
}
int F_136 ( struct V_168 * V_171 , struct V_181 * V_170 )
{
struct V_79 * V_169 = V_171 -> V_169 ;
int V_12 = 0 ;
F_14 ( & V_169 -> V_84 ) ;
V_171 -> V_170 = V_170 ;
if ( F_21 ( & V_171 -> V_85 ) )
F_86 ( & V_171 -> V_85 , & V_169 -> V_85 ) ;
if ( F_127 ( & V_169 -> V_85 , struct V_168 , V_85 ) == V_171 )
goto V_182;
F_137 ( & V_169 -> V_86 , V_170 , NULL ) ;
V_12 = - V_96 ;
V_182:
F_15 ( & V_169 -> V_84 ) ;
return V_12 ;
}
static void F_138 ( struct V_1 * V_2 )
{
F_139 () ;
F_7 ( V_183 , & V_2 -> V_18 ) ;
F_140 () ;
F_141 ( & V_2 -> V_18 , V_183 ) ;
F_142 ( & V_2 -> V_184 ) ;
}
void F_143 ( struct V_1 * V_2 )
{
struct V_185 * V_170 ;
char V_186 [ V_187 + sizeof( L_5 ) + 1 ] ;
if ( F_144 ( V_183 , & V_2 -> V_18 ) != 0 )
return;
F_145 ( V_188 ) ;
F_50 ( & V_2 -> V_189 ) ;
F_23 () ;
snprintf ( V_186 , sizeof( V_186 ) , L_6 ,
F_146 ( V_2 -> V_190 , V_191 ) ) ;
F_25 () ;
V_170 = F_147 ( V_192 , V_2 , V_186 ) ;
if ( F_148 ( V_170 ) ) {
F_149 ( V_193 L_7 ,
V_194 , F_150 ( V_170 ) ) ;
F_138 ( V_2 ) ;
F_151 ( V_2 ) ;
F_152 ( V_188 ) ;
}
}
void F_153 ( struct V_1 * V_2 )
{
if ( ! V_2 )
return;
if ( ! F_3 ( V_195 , & V_2 -> V_18 ) )
F_5 ( V_196 , & V_2 -> V_18 ) ;
F_154 ( L_8 , V_194 ,
V_2 -> V_197 ) ;
F_143 ( V_2 ) ;
}
int F_155 ( struct V_1 * V_2 )
{
int V_198 ;
F_156 () ;
V_198 = F_157 ( & V_2 -> V_18 , V_183 ,
V_199 , V_200 ) ;
if ( V_198 )
return V_198 ;
if ( V_2 -> V_201 < 0 )
return V_2 -> V_201 ;
return 0 ;
}
int F_158 ( struct V_1 * V_2 )
{
unsigned int V_202 ;
int V_61 ;
for ( V_202 = V_203 ; V_202 != 0 ; V_202 -- ) {
V_61 = F_155 ( V_2 ) ;
if ( V_61 != 0 )
break;
if ( ! F_3 ( V_195 , & V_2 -> V_18 ) &&
! F_3 ( V_196 , & V_2 -> V_18 ) )
break;
F_143 ( V_2 ) ;
V_61 = - V_204 ;
}
return V_61 ;
}
static void F_159 ( struct V_1 * V_2 )
{
F_5 ( V_195 , & V_2 -> V_18 ) ;
F_160 ( V_2 ) ;
F_154 ( L_9 , V_194 ,
V_2 -> V_197 ) ;
}
void F_161 ( struct V_1 * V_2 )
{
F_159 ( V_2 ) ;
F_143 ( V_2 ) ;
}
static int F_162 ( struct V_1 * V_2 , struct V_98 * V_99 )
{
F_5 ( V_205 , & V_99 -> V_82 ) ;
if ( F_3 ( V_206 , & V_99 -> V_82 ) ) {
F_7 ( V_205 , & V_99 -> V_82 ) ;
return 0 ;
}
F_5 ( V_207 , & V_99 -> V_108 -> V_208 ) ;
F_5 ( V_209 , & V_2 -> V_18 ) ;
return 1 ;
}
static int F_163 ( struct V_1 * V_2 , struct V_98 * V_99 )
{
F_5 ( V_206 , & V_99 -> V_82 ) ;
F_7 ( V_205 , & V_99 -> V_82 ) ;
F_5 ( V_210 , & V_99 -> V_108 -> V_208 ) ;
F_5 ( V_211 , & V_2 -> V_18 ) ;
return 1 ;
}
void F_164 ( const struct V_30 * V_31 , struct V_98 * V_99 )
{
struct V_1 * V_2 = V_31 -> V_1 ;
F_163 ( V_2 , V_99 ) ;
F_154 ( L_10 , V_194 ,
V_2 -> V_197 ) ;
F_143 ( V_2 ) ;
}
void F_165 ( struct V_109 * V_109 ,
const T_5 * V_167 )
{
struct V_1 * V_2 = F_166 ( V_109 ) -> V_1 ;
struct V_110 * V_111 = F_93 ( V_109 ) ;
struct V_212 * V_213 ;
struct V_98 * V_99 ;
bool V_214 = false ;
F_14 ( & V_109 -> V_112 ) ;
F_94 (ctx, &nfsi->open_files, list) {
V_99 = V_213 -> V_99 ;
if ( V_99 == NULL )
continue;
if ( ! F_3 ( V_124 , & V_99 -> V_82 ) )
continue;
if ( ! F_167 ( & V_99 -> V_167 , V_167 ) )
continue;
F_163 ( V_2 , V_99 ) ;
V_214 = true ;
}
F_15 ( & V_109 -> V_112 ) ;
if ( V_214 )
F_143 ( V_2 ) ;
}
static int F_168 ( struct V_98 * V_99 , const struct V_215 * V_216 )
{
struct V_109 * V_109 = V_99 -> V_109 ;
struct V_110 * V_111 = F_93 ( V_109 ) ;
struct V_148 * V_153 ;
int V_12 = 0 ;
if ( V_109 -> V_217 == NULL )
return 0 ;
F_169 ( & V_111 -> V_218 ) ;
F_170 () ;
for ( V_153 = V_109 -> V_217 ; V_153 != NULL ; V_153 = V_153 -> V_219 ) {
if ( ! ( V_153 -> V_155 & ( V_156 | V_157 ) ) )
continue;
if ( F_171 ( V_153 -> V_220 ) -> V_99 != V_99 )
continue;
F_172 () ;
V_12 = V_216 -> V_221 ( V_99 , V_153 ) ;
switch ( V_12 ) {
case 0 :
break;
case - V_222 :
case - V_223 :
case - V_176 :
case - V_177 :
case - V_224 :
case - V_225 :
case - V_175 :
case - V_226 :
case - V_227 :
case - V_228 :
case - V_229 :
goto V_26;
default:
F_149 ( V_193 L_11
L_12 , V_194 , V_12 ) ;
case - V_159 :
case - V_230 :
case - V_231 :
case - V_232 :
V_12 = 0 ;
}
F_170 () ;
}
F_172 () ;
V_26:
F_173 ( & V_111 -> V_218 ) ;
return V_12 ;
}
static int F_174 ( struct V_32 * V_33 , const struct V_215 * V_216 )
{
struct V_98 * V_99 ;
struct V_126 * V_84 ;
int V_12 = 0 ;
F_14 ( & V_33 -> V_88 ) ;
F_175 ( & V_33 -> V_89 ) ;
V_233:
F_94 (state, &sp->so_states, open_states) {
if ( ! F_29 ( V_216 -> V_234 , & V_99 -> V_82 ) )
continue;
if ( V_99 -> V_99 == 0 )
continue;
F_50 ( & V_99 -> V_101 ) ;
F_15 ( & V_33 -> V_88 ) ;
V_12 = V_216 -> V_235 ( V_33 , V_99 ) ;
if ( V_12 >= 0 ) {
V_12 = F_168 ( V_99 , V_216 ) ;
if ( V_12 >= 0 ) {
F_14 ( & V_99 -> V_103 ) ;
F_94 (lock, &state->lock_states, ls_locks) {
if ( ! F_3 ( V_146 , & V_84 -> V_147 ) )
F_131 ( L_13
L_14
L_15 , V_194 ) ;
}
F_15 ( & V_99 -> V_103 ) ;
F_100 ( V_99 ) ;
F_14 ( & V_33 -> V_88 ) ;
goto V_233;
}
}
switch ( V_12 ) {
default:
F_149 ( V_193 L_11
L_12 , V_194 , V_12 ) ;
case - V_236 :
case - V_159 :
case - V_222 :
memset ( & V_99 -> V_167 , 0 ,
sizeof( V_99 -> V_167 ) ) ;
V_99 -> V_99 = 0 ;
break;
case - V_223 :
case - V_176 :
case - V_177 :
case - V_231 :
case - V_232 :
F_163 ( V_33 -> V_74 -> V_1 , V_99 ) ;
break;
case - V_224 :
case - V_225 :
F_163 ( V_33 -> V_74 -> V_1 , V_99 ) ;
case - V_175 :
case - V_226 :
case - V_227 :
case - V_228 :
case - V_229 :
goto V_237;
}
F_100 ( V_99 ) ;
F_14 ( & V_33 -> V_88 ) ;
goto V_233;
}
F_176 ( & V_33 -> V_89 ) ;
F_15 ( & V_33 -> V_88 ) ;
return 0 ;
V_237:
F_100 ( V_99 ) ;
F_14 ( & V_33 -> V_88 ) ;
F_176 ( & V_33 -> V_89 ) ;
F_15 ( & V_33 -> V_88 ) ;
return V_12 ;
}
static void F_177 ( struct V_98 * V_99 )
{
struct V_126 * V_84 ;
F_7 ( V_124 , & V_99 -> V_82 ) ;
F_7 ( V_121 , & V_99 -> V_82 ) ;
F_7 ( V_123 , & V_99 -> V_82 ) ;
F_7 ( V_122 , & V_99 -> V_82 ) ;
F_14 ( & V_99 -> V_103 ) ;
F_94 (lock, &state->lock_states, ls_locks) {
V_84 -> V_139 . V_82 = 0 ;
F_7 ( V_146 , & V_84 -> V_147 ) ;
}
F_15 ( & V_99 -> V_103 ) ;
}
static void F_178 ( struct V_30 * V_31 ,
int (* F_179)( struct V_1 * V_2 , struct V_98 * V_99 ) )
{
struct V_1 * V_2 = V_31 -> V_1 ;
struct V_32 * V_33 ;
struct V_34 * V_35 ;
struct V_98 * V_99 ;
F_14 ( & V_2 -> V_29 ) ;
for ( V_35 = F_18 ( & V_31 -> V_36 ) ;
V_35 != NULL ;
V_35 = F_19 ( V_35 ) ) {
V_33 = F_20 ( V_35 , struct V_32 , V_37 ) ;
V_33 -> V_77 . V_82 = 0 ;
F_14 ( & V_33 -> V_88 ) ;
F_94 (state, &sp->so_states, open_states) {
if ( F_179 ( V_2 , V_99 ) )
F_177 ( V_99 ) ;
}
F_15 ( & V_33 -> V_88 ) ;
}
F_15 ( & V_2 -> V_29 ) ;
}
static void F_180 ( struct V_1 * V_2 ,
int (* F_179)( struct V_1 * V_2 , struct V_98 * V_99 ) )
{
struct V_30 * V_31 ;
F_23 () ;
F_24 (server, &clp->cl_superblocks, client_link)
F_178 ( V_31 , F_179 ) ;
F_25 () ;
}
static void F_181 ( struct V_1 * V_2 )
{
F_182 ( V_2 ) ;
F_180 ( V_2 , F_162 ) ;
}
static void F_183 ( struct V_1 * V_2 ,
const struct V_215 * V_216 )
{
if ( V_216 -> V_238 )
( void ) V_216 -> V_238 ( V_2 ) ;
}
static void F_184 ( struct V_30 * V_31 )
{
struct V_1 * V_2 = V_31 -> V_1 ;
struct V_32 * V_33 ;
struct V_34 * V_35 ;
struct V_98 * V_99 ;
F_14 ( & V_2 -> V_29 ) ;
for ( V_35 = F_18 ( & V_31 -> V_36 ) ;
V_35 != NULL ;
V_35 = F_19 ( V_35 ) ) {
V_33 = F_20 ( V_35 , struct V_32 , V_37 ) ;
F_14 ( & V_33 -> V_88 ) ;
F_94 (state, &sp->so_states, open_states) {
if ( ! F_29 ( V_205 ,
& V_99 -> V_82 ) )
continue;
F_163 ( V_2 , V_99 ) ;
}
F_15 ( & V_33 -> V_88 ) ;
}
F_15 ( & V_2 -> V_29 ) ;
}
static int F_185 ( struct V_1 * V_2 )
{
struct V_30 * V_31 ;
if ( ! F_29 ( V_209 , & V_2 -> V_18 ) )
return 0 ;
F_23 () ;
F_24 (server, &clp->cl_superblocks, client_link)
F_184 ( V_31 ) ;
F_25 () ;
F_186 ( V_2 ) ;
return 1 ;
}
static void F_187 ( struct V_1 * V_2 )
{
if ( ! F_185 ( V_2 ) )
return;
F_183 ( V_2 , V_2 -> V_239 -> V_240 ) ;
}
static void F_188 ( struct V_1 * V_2 )
{
F_182 ( V_2 ) ;
F_186 ( V_2 ) ;
}
static void F_189 ( struct V_1 * V_2 )
{
F_188 ( V_2 ) ;
F_180 ( V_2 , F_163 ) ;
}
static int F_190 ( struct V_1 * V_2 , int error )
{
switch ( error ) {
case 0 :
break;
case - V_241 :
F_159 ( V_2 ) ;
break;
case - V_225 :
F_187 ( V_2 ) ;
break;
case - V_175 :
case - V_242 :
F_5 ( V_195 , & V_2 -> V_18 ) ;
F_185 ( V_2 ) ;
F_181 ( V_2 ) ;
break;
case - V_224 :
F_5 ( V_195 , & V_2 -> V_18 ) ;
F_189 ( V_2 ) ;
break;
case - V_226 :
case - V_227 :
case - V_228 :
case - V_243 :
case - V_244 :
case - V_245 :
F_5 ( V_63 , & V_2 -> V_18 ) ;
break;
case - V_229 :
F_5 ( V_64 , & V_2 -> V_18 ) ;
break;
default:
F_154 ( L_16 ,
V_194 , error , V_2 -> V_197 ) ;
return error ;
}
F_154 ( L_17 , V_194 , error ,
V_2 -> V_197 ) ;
return 0 ;
}
static int F_191 ( struct V_1 * V_2 , const struct V_215 * V_216 )
{
struct V_32 * V_33 ;
struct V_30 * V_31 ;
struct V_34 * V_35 ;
int V_12 = 0 ;
V_233:
F_23 () ;
F_24 (server, &clp->cl_superblocks, client_link) {
F_87 ( V_31 ) ;
F_14 ( & V_2 -> V_29 ) ;
for ( V_35 = F_18 ( & V_31 -> V_36 ) ;
V_35 != NULL ;
V_35 = F_19 ( V_35 ) ) {
V_33 = F_20 ( V_35 ,
struct V_32 , V_37 ) ;
if ( ! F_29 ( V_216 -> V_246 ,
& V_33 -> V_208 ) )
continue;
F_50 ( & V_33 -> V_72 ) ;
F_15 ( & V_2 -> V_29 ) ;
F_25 () ;
V_12 = F_174 ( V_33 , V_216 ) ;
if ( V_12 < 0 ) {
F_5 ( V_216 -> V_246 , & V_33 -> V_208 ) ;
F_84 ( V_33 ) ;
return F_190 ( V_2 , V_12 ) ;
}
F_84 ( V_33 ) ;
goto V_233;
}
F_15 ( & V_2 -> V_29 ) ;
}
F_25 () ;
return V_12 ;
}
static int F_192 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
const struct V_247 * V_216 =
V_2 -> V_239 -> V_248 ;
int V_12 ;
if ( F_3 ( V_195 , & V_2 -> V_18 ) )
return 0 ;
F_14 ( & V_2 -> V_29 ) ;
V_4 = V_216 -> V_249 ( V_2 ) ;
F_15 ( & V_2 -> V_29 ) ;
if ( V_4 == NULL ) {
V_4 = F_47 ( V_2 ) ;
V_12 = - V_250 ;
if ( V_4 == NULL )
goto V_26;
}
V_12 = V_216 -> V_251 ( V_2 , V_4 ) ;
F_16 ( V_4 ) ;
V_26:
return F_190 ( V_2 , V_12 ) ;
}
static int F_193 ( struct V_1 * V_2 , int V_12 )
{
switch ( V_12 ) {
case - V_245 :
if ( F_144 ( V_252 , & V_2 -> V_18 ) )
return - V_253 ;
F_194 ( 1 ) ;
F_7 ( V_17 , & V_2 -> V_18 ) ;
break;
case - V_175 :
F_7 ( V_17 , & V_2 -> V_18 ) ;
F_185 ( V_2 ) ;
F_181 ( V_2 ) ;
break;
case - V_254 :
F_195 ( L_18 ,
V_2 -> V_197 ) ;
F_42 ( V_2 , - V_255 ) ;
F_7 ( V_17 , & V_2 -> V_18 ) ;
return - V_255 ;
case - V_256 :
if ( V_2 -> V_28 == NULL )
return - V_256 ;
F_13 ( V_2 ) ;
case - V_257 :
case - V_258 :
case - V_96 :
F_194 ( 1 ) ;
break;
case - V_259 :
if ( V_2 -> V_201 == V_260 )
F_42 ( V_2 , - V_261 ) ;
F_154 ( L_19 ,
V_194 , - V_261 , V_2 -> V_197 ) ;
return - V_261 ;
case - V_262 :
default:
F_154 ( L_19 , V_194 ,
V_12 , V_2 -> V_197 ) ;
return V_12 ;
}
F_5 ( V_195 , & V_2 -> V_18 ) ;
F_154 ( L_17 , V_194 , V_12 ,
V_2 -> V_197 ) ;
return 0 ;
}
static int F_196 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
const struct V_215 * V_216 =
V_2 -> V_239 -> V_240 ;
int V_12 ;
V_4 = V_216 -> V_263 ( V_2 ) ;
if ( V_4 == NULL )
return - V_236 ;
V_12 = V_216 -> V_264 ( V_2 , V_4 ) ;
F_16 ( V_4 ) ;
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
return F_193 ( V_2 , V_12 ) ;
if ( F_29 ( V_265 , & V_2 -> V_18 ) )
F_189 ( V_2 ) ;
if ( ! F_3 ( V_211 , & V_2 -> V_18 ) )
F_5 ( V_209 , & V_2 -> V_18 ) ;
F_7 ( V_196 , & V_2 -> V_18 ) ;
F_7 ( V_195 , & V_2 -> V_18 ) ;
return 0 ;
}
static int F_199 ( struct V_1 * V_2 )
{
int V_12 ;
V_12 = F_196 ( V_2 ) ;
if ( V_12 < 0 )
return F_193 ( V_2 , V_12 ) ;
F_7 ( V_252 , & V_2 -> V_18 ) ;
F_5 ( V_195 , & V_2 -> V_18 ) ;
F_189 ( V_2 ) ;
return 0 ;
}
int F_200 ( struct V_1 * V_2 ,
struct V_1 * * V_27 )
{
const struct V_215 * V_216 =
V_2 -> V_239 -> V_240 ;
T_6 * V_266 , V_267 , V_268 ;
struct V_269 * V_270 ;
struct V_3 * V_4 ;
int V_271 , V_272 , V_12 ;
F_154 ( L_20 , V_194 , V_2 -> V_197 ) ;
V_272 = V_273 ;
V_266 = F_201 ( V_272 , sizeof( * V_266 ) , V_125 ) ;
if ( V_266 == NULL ) {
V_12 = - V_159 ;
goto V_26;
}
V_272 = F_202 ( V_266 , V_272 ) ;
if ( V_272 < 0 ) {
V_12 = V_272 ;
goto V_141;
}
V_270 = V_2 -> V_190 ;
V_268 = V_270 -> V_274 -> V_275 ;
V_271 = 0 ;
F_203 ( & V_276 ) ;
V_12 = - V_236 ;
V_277:
V_4 = V_216 -> V_263 ( V_2 ) ;
if ( V_4 == NULL )
goto V_278;
V_12 = V_216 -> V_279 ( V_2 , V_27 , V_4 ) ;
F_16 ( V_4 ) ;
switch ( V_12 ) {
case 0 :
break;
case - V_256 :
if ( V_2 -> V_28 == NULL )
break;
F_13 ( V_2 ) ;
case - V_257 :
case - V_258 :
case - V_96 :
F_194 ( 1 ) ;
case - V_175 :
F_154 ( L_21 ,
V_194 , V_12 ) ;
goto V_277;
case - V_254 :
case - V_280 :
V_12 = - V_255 ;
if ( V_271 >= V_272 )
break;
V_267 = V_266 [ V_271 ++ ] ;
if ( V_267 == V_268 )
V_267 = V_266 [ V_271 ++ ] ;
V_270 = F_204 ( V_270 , V_267 ) ;
if ( F_148 ( V_270 ) ) {
V_12 = F_150 ( V_270 ) ;
break;
}
V_270 = F_205 ( & V_2 -> V_190 , V_270 ) ;
F_206 ( V_270 ) ;
V_270 = V_2 -> V_190 ;
goto V_277;
case - V_259 :
V_12 = - V_261 ;
break;
case - V_281 :
case - V_262 :
V_12 = - V_281 ;
}
V_278:
F_207 ( & V_276 ) ;
V_141:
F_75 ( V_266 ) ;
V_26:
F_154 ( L_22 , V_194 , V_12 ) ;
return V_12 ;
}
void F_208 ( struct V_49 * V_58 , int V_75 )
{
struct V_1 * V_2 = V_58 -> V_2 ;
switch ( V_75 ) {
default:
F_5 ( V_63 , & V_2 -> V_18 ) ;
break;
case - V_229 :
F_5 ( V_64 , & V_2 -> V_18 ) ;
}
F_153 ( V_2 ) ;
}
static void F_209 ( struct V_1 * V_2 )
{
F_5 ( V_196 , & V_2 -> V_18 ) ;
F_143 ( V_2 ) ;
}
void F_210 ( struct V_1 * V_2 )
{
F_209 ( V_2 ) ;
}
void F_211 ( struct V_1 * V_2 )
{
F_209 ( V_2 ) ;
}
static void F_212 ( struct V_1 * V_2 )
{
if ( F_144 ( V_195 , & V_2 -> V_18 ) == 0 ) {
F_5 ( V_252 , & V_2 -> V_18 ) ;
F_7 ( V_17 , & V_2 -> V_18 ) ;
F_189 ( V_2 ) ;
F_154 ( L_23 ,
V_194 , V_2 -> V_197 ) ;
F_143 ( V_2 ) ;
}
}
static void F_213 ( struct V_1 * V_2 )
{
if ( F_144 ( V_195 , & V_2 -> V_18 ) == 0 ) {
F_181 ( V_2 ) ;
F_154 ( L_24 , V_194 ,
V_2 -> V_197 ) ;
F_143 ( V_2 ) ;
}
}
static void F_214 ( struct V_1 * V_2 )
{
F_212 ( V_2 ) ;
F_154 ( L_25 , V_194 , V_2 -> V_197 ) ;
}
static void F_215 ( struct V_1 * V_2 )
{
F_160 ( V_2 ) ;
F_154 ( L_26 , V_194 ,
V_2 -> V_197 ) ;
}
static void F_216 ( struct V_1 * V_2 )
{
F_160 ( V_2 ) ;
if ( F_144 ( V_63 , & V_2 -> V_18 ) == 0 )
F_143 ( V_2 ) ;
F_154 ( L_27 , V_194 ,
V_2 -> V_197 ) ;
}
static void F_217 ( struct V_1 * V_2 )
{
if ( F_144 ( V_64 ,
& V_2 -> V_18 ) == 0 )
F_143 ( V_2 ) ;
}
void F_218 ( struct V_1 * V_2 , T_7 V_82 )
{
if ( ! V_82 )
return;
F_154 ( L_28 ,
V_194 , V_2 -> V_197 , V_2 -> V_8 , V_82 ) ;
if ( V_82 & V_282 )
F_213 ( V_2 ) ;
if ( V_82 & ( V_283 |
V_284 |
V_285 |
V_286 ) )
F_214 ( V_2 ) ;
if ( V_82 & V_287 )
F_215 ( V_2 ) ;
if ( V_82 & V_288 )
F_216 ( V_2 ) ;
else if ( V_82 & ( V_289 |
V_290 ) )
F_217 ( V_2 ) ;
}
static int F_219 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
int V_12 ;
if ( ! F_134 ( V_2 ) )
return 0 ;
F_37 ( V_2 ) ;
V_4 = F_45 ( V_2 ) ;
V_12 = F_220 ( V_2 -> V_51 , V_4 ) ;
switch ( V_12 ) {
case 0 :
case - V_226 :
case - V_243 :
break;
case - V_291 :
case - V_257 :
F_5 ( V_63 , & V_2 -> V_18 ) ;
V_12 = 0 ;
F_194 ( 1 ) ;
goto V_26;
default:
V_12 = F_190 ( V_2 , V_12 ) ;
goto V_26;
}
memset ( V_2 -> V_51 -> V_292 . V_293 , 0 , V_294 ) ;
V_12 = F_41 ( V_2 , V_4 ) ;
if ( V_12 ) {
F_154 ( L_29 ,
V_194 , V_12 , V_2 -> V_197 ) ;
V_12 = F_193 ( V_2 , V_12 ) ;
goto V_26;
}
F_38 ( V_2 ) ;
F_154 ( L_30 ,
V_194 , V_2 -> V_197 ) ;
V_26:
if ( V_4 )
F_16 ( V_4 ) ;
return V_12 ;
}
static int F_221 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
int V_61 ;
if ( ! F_134 ( V_2 ) )
return 0 ;
F_37 ( V_2 ) ;
V_4 = F_45 ( V_2 ) ;
V_61 = F_222 ( V_2 , V_4 ) ;
if ( V_4 )
F_16 ( V_4 ) ;
F_7 ( V_64 , & V_2 -> V_18 ) ;
switch ( V_61 ) {
case 0 :
F_154 ( L_31 ,
V_194 , V_2 -> V_197 ) ;
break;
case - V_257 :
F_194 ( 1 ) ;
F_5 ( V_64 , & V_2 -> V_18 ) ;
break;
default:
return F_190 ( V_2 , V_61 ) ;
}
return 0 ;
}
static int F_219 ( struct V_1 * V_2 ) { return 0 ; }
static int F_28 ( struct V_1 * V_2 ) { return 0 ; }
static int F_221 ( struct V_1 * V_2 )
{
return 0 ;
}
static void F_223 ( struct V_1 * V_2 )
{
int V_12 = 0 ;
const char * V_295 = L_32 , * V_296 = L_32 ;
do {
if ( F_3 ( V_252 , & V_2 -> V_18 ) ) {
V_295 = L_33 ;
V_12 = F_199 ( V_2 ) ;
if ( V_12 < 0 )
goto V_297;
continue;
}
if ( F_3 ( V_195 , & V_2 -> V_18 ) ) {
V_295 = L_34 ;
V_12 = F_198 ( V_2 ) ;
if ( V_12 < 0 )
goto V_297;
continue;
}
if ( F_29 ( V_63 , & V_2 -> V_18 ) ) {
V_295 = L_35 ;
V_12 = F_219 ( V_2 ) ;
if ( F_3 ( V_195 , & V_2 -> V_18 ) )
continue;
if ( V_12 < 0 )
goto V_297;
}
if ( F_29 ( V_64 ,
& V_2 -> V_18 ) ) {
V_295 = L_36 ;
V_12 = F_221 ( V_2 ) ;
if ( V_12 < 0 )
goto V_297;
continue;
}
if ( F_29 ( V_196 , & V_2 -> V_18 ) ) {
V_295 = L_37 ;
V_12 = F_192 ( V_2 ) ;
if ( V_12 < 0 )
goto V_297;
continue;
}
if ( F_3 ( V_209 , & V_2 -> V_18 ) ) {
V_295 = L_38 ;
V_12 = F_191 ( V_2 ,
V_2 -> V_239 -> V_240 ) ;
if ( F_3 ( V_195 , & V_2 -> V_18 ) ||
F_3 ( V_63 , & V_2 -> V_18 ) )
continue;
F_187 ( V_2 ) ;
if ( F_3 ( V_211 , & V_2 -> V_18 ) )
continue;
if ( V_12 < 0 )
goto V_297;
}
if ( F_29 ( V_211 , & V_2 -> V_18 ) ) {
V_295 = L_39 ;
V_12 = F_191 ( V_2 ,
V_2 -> V_239 -> V_298 ) ;
if ( F_3 ( V_195 , & V_2 -> V_18 ) ||
F_3 ( V_63 , & V_2 -> V_18 ) ||
F_3 ( V_209 , & V_2 -> V_18 ) )
continue;
if ( V_12 < 0 )
goto V_297;
}
F_28 ( V_2 ) ;
if ( F_29 ( V_299 , & V_2 -> V_18 ) ) {
F_224 ( V_2 ) ;
continue;
}
F_138 ( V_2 ) ;
if ( V_2 -> V_18 == 0 )
break;
if ( F_144 ( V_183 , & V_2 -> V_18 ) != 0 )
break;
} while ( F_225 ( & V_2 -> V_189 ) > 1 );
return;
V_297:
if ( strlen ( V_295 ) )
V_296 = L_40 ;
F_131 ( L_41
L_42 , V_296 , V_295 ,
V_2 -> V_197 , - V_12 ) ;
F_194 ( 1 ) ;
F_28 ( V_2 ) ;
F_138 ( V_2 ) ;
}
static int V_192 ( void * V_300 )
{
struct V_1 * V_2 = V_300 ;
F_226 ( V_301 ) ;
F_223 ( V_2 ) ;
F_151 ( V_2 ) ;
F_227 ( 0 ) ;
return 0 ;
}
