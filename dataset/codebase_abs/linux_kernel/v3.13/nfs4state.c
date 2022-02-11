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
F_104 ( struct V_99 * V_100 , T_3 V_128 , T_4 V_129 , unsigned int type )
{
struct V_127 * V_36 ;
F_91 (pos, &state->lock_states, ls_locks) {
if ( type != V_130 && V_36 -> V_131 . V_132 != type )
continue;
switch ( V_36 -> V_131 . V_132 ) {
case V_133 :
if ( V_36 -> V_131 . V_134 . V_135 != V_128 )
continue;
break;
case V_136 :
if ( V_36 -> V_131 . V_134 . V_137 != V_129 )
continue;
}
F_47 ( & V_36 -> V_138 ) ;
return V_36 ;
}
return NULL ;
}
static struct V_127 * F_105 ( struct V_99 * V_100 , T_3 V_128 , T_4 V_129 , unsigned int type )
{
struct V_127 * V_139 ;
struct V_31 * V_32 = V_100 -> V_109 -> V_75 ;
V_139 = F_65 ( sizeof( * V_139 ) , V_101 ) ;
if ( V_139 == NULL )
return NULL ;
F_57 ( & V_139 -> V_140 ) ;
F_66 ( & V_139 -> V_138 , 1 ) ;
V_139 -> V_141 = V_100 ;
V_139 -> V_131 . V_132 = type ;
switch ( V_139 -> V_131 . V_132 ) {
case V_136 :
V_139 -> V_131 . V_134 . V_137 = V_129 ;
break;
case V_133 :
V_139 -> V_131 . V_134 . V_135 = V_128 ;
break;
default:
goto V_142;
}
V_139 -> V_140 . V_79 = F_106 ( & V_32 -> V_143 , 0 , 0 , V_101 ) ;
if ( V_139 -> V_140 . V_79 < 0 )
goto V_142;
F_60 ( & V_139 -> V_144 ) ;
return V_139 ;
V_142:
F_72 ( V_139 ) ;
return NULL ;
}
void F_107 ( struct V_31 * V_32 , struct V_127 * V_139 )
{
F_108 ( & V_32 -> V_143 , V_139 -> V_140 . V_79 ) ;
F_62 ( & V_139 -> V_140 ) ;
F_72 ( V_139 ) ;
}
static struct V_127 * F_109 ( struct V_99 * V_100 , T_3 V_109 , T_4 V_145 , unsigned int type )
{
struct V_127 * V_139 , * V_29 = NULL ;
for(; ; ) {
F_15 ( & V_100 -> V_104 ) ;
V_139 = F_104 ( V_100 , V_109 , V_145 , type ) ;
if ( V_139 != NULL )
break;
if ( V_29 != NULL ) {
F_96 ( & V_29 -> V_144 , & V_100 -> V_103 ) ;
F_5 ( V_146 , & V_100 -> V_83 ) ;
V_139 = V_29 ;
V_29 = NULL ;
break;
}
F_16 ( & V_100 -> V_104 ) ;
V_29 = F_105 ( V_100 , V_109 , V_145 , type ) ;
if ( V_29 == NULL )
return NULL ;
}
F_16 ( & V_100 -> V_104 ) ;
if ( V_29 != NULL )
F_107 ( V_100 -> V_109 -> V_75 , V_29 ) ;
return V_139 ;
}
void F_110 ( struct V_127 * V_139 )
{
struct V_31 * V_32 ;
struct V_99 * V_100 ;
if ( V_139 == NULL )
return;
V_100 = V_139 -> V_141 ;
if ( ! F_82 ( & V_139 -> V_138 , & V_100 -> V_104 ) )
return;
F_78 ( & V_139 -> V_144 ) ;
if ( F_22 ( & V_100 -> V_103 ) )
F_7 ( V_146 , & V_100 -> V_83 ) ;
F_16 ( & V_100 -> V_104 ) ;
V_32 = V_100 -> V_109 -> V_75 ;
if ( F_3 ( V_147 , & V_139 -> V_148 ) ) {
struct V_1 * V_2 = V_32 -> V_1 ;
V_2 -> V_149 -> V_150 ( V_32 , V_139 ) ;
} else
F_107 ( V_32 , V_139 ) ;
}
static void F_111 ( struct V_151 * V_152 , struct V_151 * V_153 )
{
struct V_127 * V_139 = V_153 -> V_154 . V_155 . V_109 ;
V_152 -> V_154 . V_155 . V_109 = V_139 ;
F_47 ( & V_139 -> V_138 ) ;
}
static void F_112 ( struct V_151 * V_156 )
{
F_110 ( V_156 -> V_154 . V_155 . V_109 ) ;
}
int F_113 ( struct V_99 * V_100 , struct V_151 * V_156 )
{
struct V_127 * V_139 ;
if ( V_156 -> V_157 != NULL )
return 0 ;
if ( V_156 -> V_158 & V_159 )
V_139 = F_109 ( V_100 , V_156 -> V_128 , 0 , V_133 ) ;
else if ( V_156 -> V_158 & V_160 )
V_139 = F_109 ( V_100 , NULL , V_156 -> V_129 ,
V_136 ) ;
else
return - V_161 ;
if ( V_139 == NULL )
return - V_162 ;
V_156 -> V_154 . V_155 . V_109 = V_139 ;
V_156 -> V_157 = & V_163 ;
return 0 ;
}
static int F_114 ( T_5 * V_152 ,
struct V_99 * V_100 ,
const struct V_164 * V_165 )
{
struct V_127 * V_139 ;
T_3 V_128 ;
T_4 V_129 ;
int V_55 = - V_166 ;
if ( V_165 == NULL )
goto V_26;
if ( F_3 ( V_146 , & V_100 -> V_83 ) == 0 )
goto V_26;
V_128 = V_165 -> V_167 ;
V_129 = V_165 -> V_168 ;
F_15 ( & V_100 -> V_104 ) ;
V_139 = F_104 ( V_100 , V_128 , V_129 , V_130 ) ;
if ( V_139 && F_3 ( V_169 , & V_139 -> V_148 ) )
V_55 = - V_170 ;
else if ( V_139 != NULL && F_3 ( V_147 , & V_139 -> V_148 ) != 0 ) {
F_115 ( V_152 , & V_139 -> V_171 ) ;
V_55 = 0 ;
F_116 () ;
if ( ! F_22 ( & V_139 -> V_140 . V_86 ) )
V_55 = - V_172 ;
}
F_16 ( & V_100 -> V_104 ) ;
F_110 ( V_139 ) ;
V_26:
return V_55 ;
}
static int F_117 ( T_5 * V_152 , struct V_99 * V_100 )
{
const T_5 * V_153 ;
int V_55 ;
int V_173 ;
do {
V_153 = & V_174 ;
V_173 = F_118 ( & V_100 -> V_105 ) ;
if ( F_3 ( V_175 , & V_100 -> V_83 ) )
V_153 = & V_100 -> V_176 ;
F_115 ( V_152 , V_153 ) ;
V_55 = 0 ;
F_116 () ;
if ( ! F_22 ( & V_100 -> V_109 -> V_78 . V_86 ) )
V_55 = - V_172 ;
} while ( F_119 ( & V_100 -> V_105 , V_173 ) );
return V_55 ;
}
int F_120 ( T_5 * V_152 , struct V_99 * V_100 ,
T_2 V_106 , const struct V_164 * V_165 )
{
int V_55 = F_114 ( V_152 , V_100 , V_165 ) ;
if ( V_55 == - V_170 )
goto V_26;
if ( F_121 ( V_152 , V_100 -> V_110 , V_106 ) )
goto V_26;
if ( V_55 != - V_166 )
goto V_26;
V_55 = F_117 ( V_152 , V_100 ) ;
V_26:
if ( F_122 ( V_100 -> V_110 , V_177 ) )
V_152 -> V_178 = 0 ;
return V_55 ;
}
struct V_179 * F_123 ( struct V_80 * V_84 , T_1 V_115 )
{
struct V_179 * V_29 ;
V_29 = F_124 ( sizeof( * V_29 ) , V_115 ) ;
if ( V_29 != NULL ) {
V_29 -> V_180 = V_84 ;
F_60 ( & V_29 -> V_86 ) ;
V_29 -> V_181 = NULL ;
}
return V_29 ;
}
void F_125 ( struct V_179 * V_178 )
{
struct V_80 * V_180 ;
if ( F_22 ( & V_178 -> V_86 ) )
return;
V_180 = V_178 -> V_180 ;
F_15 ( & V_180 -> V_85 ) ;
F_46 ( & V_178 -> V_86 ) ;
if ( ! F_22 ( & V_180 -> V_86 ) ) {
struct V_179 * V_182 ;
V_182 = F_126 ( & V_180 -> V_86 ,
struct V_179 , V_86 ) ;
F_127 ( & V_180 -> V_87 , V_182 -> V_181 ) ;
}
F_16 ( & V_180 -> V_85 ) ;
}
void F_128 ( struct V_179 * V_178 )
{
F_125 ( V_178 ) ;
F_72 ( V_178 ) ;
}
static void F_129 ( int V_12 , struct V_179 * V_178 )
{
switch ( V_12 ) {
case 0 :
break;
case - V_183 :
if ( V_178 -> V_180 -> V_83 & V_184 )
return;
F_130 ( L_2
L_3
L_4 ,
V_178 -> V_180 ) ;
case - V_185 :
case - V_186 :
case - V_187 :
case - V_188 :
case - V_189 :
case - V_190 :
return;
} ;
V_178 -> V_180 -> V_84 ++ ;
}
void F_131 ( int V_12 , struct V_179 * V_178 )
{
struct V_33 * V_34 = F_132 ( V_178 -> V_180 ,
struct V_33 , V_78 ) ;
struct V_31 * V_32 = V_34 -> V_75 ;
if ( V_12 == - V_183 )
F_69 ( V_34 ) ;
if ( ! F_133 ( V_32 -> V_1 ) )
F_129 ( V_12 , V_178 ) ;
}
void F_134 ( int V_12 , struct V_179 * V_178 )
{
F_129 ( V_12 , V_178 ) ;
}
int F_135 ( struct V_179 * V_178 , struct V_191 * V_181 )
{
struct V_80 * V_180 = V_178 -> V_180 ;
int V_12 = 0 ;
F_15 ( & V_180 -> V_85 ) ;
V_178 -> V_181 = V_181 ;
if ( F_22 ( & V_178 -> V_86 ) )
F_83 ( & V_178 -> V_86 , & V_180 -> V_86 ) ;
if ( F_126 ( & V_180 -> V_86 , struct V_179 , V_86 ) == V_178 )
goto V_192;
F_136 ( & V_180 -> V_87 , V_181 , NULL ) ;
V_12 = - V_97 ;
V_192:
F_16 ( & V_180 -> V_85 ) ;
return V_12 ;
}
static void F_137 ( struct V_1 * V_2 )
{
F_138 () ;
F_7 ( V_193 , & V_2 -> V_18 ) ;
F_139 () ;
F_140 ( & V_2 -> V_18 , V_193 ) ;
F_141 ( & V_2 -> V_194 ) ;
}
void F_142 ( struct V_1 * V_2 )
{
struct V_195 * V_181 ;
char V_196 [ V_197 + sizeof( L_5 ) + 1 ] ;
if ( F_143 ( V_193 , & V_2 -> V_18 ) != 0 )
return;
F_144 ( V_198 ) ;
F_47 ( & V_2 -> V_199 ) ;
F_24 () ;
snprintf ( V_196 , sizeof( V_196 ) , L_6 ,
F_145 ( V_2 -> V_200 , V_201 ) ) ;
F_26 () ;
V_181 = F_146 ( V_202 , V_2 , L_7 , V_196 ) ;
if ( F_147 ( V_181 ) ) {
F_148 ( V_203 L_8 ,
V_204 , F_149 ( V_181 ) ) ;
F_137 ( V_2 ) ;
F_150 ( V_2 ) ;
F_151 ( V_198 ) ;
}
}
void F_152 ( struct V_1 * V_2 )
{
if ( ! V_2 )
return;
if ( ! F_3 ( V_205 , & V_2 -> V_18 ) )
F_5 ( V_206 , & V_2 -> V_18 ) ;
F_153 ( L_9 , V_204 ,
V_2 -> V_207 ) ;
F_142 ( V_2 ) ;
}
int F_154 ( const struct V_31 * V_32 )
{
struct V_1 * V_2 = V_32 -> V_1 ;
if ( V_32 -> V_208 != V_209 ) {
F_155 ( L_10 ,
V_2 -> V_207 ) ;
return - V_210 ;
}
if ( F_3 ( V_211 , & V_32 -> V_212 ) )
return - V_210 ;
F_153 ( L_11 ,
V_204 ,
( unsigned long long ) V_32 -> V_213 . V_214 ,
( unsigned long long ) V_32 -> V_213 . V_215 ,
V_2 -> V_207 ) ;
F_5 ( V_216 ,
& ( (struct V_31 * ) V_32 ) -> V_212 ) ;
F_5 ( V_217 , & V_2 -> V_18 ) ;
F_142 ( V_2 ) ;
return 0 ;
}
void F_156 ( struct V_1 * V_2 )
{
F_153 ( L_12 ,
V_204 , V_2 -> V_8 , V_2 -> V_207 ) ;
F_5 ( V_218 , & V_2 -> V_18 ) ;
F_142 ( V_2 ) ;
}
int F_157 ( struct V_1 * V_2 )
{
int V_219 ;
F_158 () ;
F_47 ( & V_2 -> V_199 ) ;
V_219 = F_159 ( & V_2 -> V_18 , V_193 ,
V_220 , V_221 ) ;
if ( V_219 )
goto V_26;
if ( V_2 -> V_222 < 0 )
V_219 = V_2 -> V_222 ;
V_26:
F_150 ( V_2 ) ;
return V_219 ;
}
int F_160 ( struct V_1 * V_2 )
{
unsigned int V_223 ;
int V_55 ;
for ( V_223 = V_224 ; V_223 != 0 ; V_223 -- ) {
V_55 = F_157 ( V_2 ) ;
if ( V_55 != 0 )
break;
if ( ! F_3 ( V_205 , & V_2 -> V_18 ) &&
! F_3 ( V_206 , & V_2 -> V_18 ) )
break;
F_142 ( V_2 ) ;
V_55 = - V_170 ;
}
return V_55 ;
}
static void F_161 ( struct V_1 * V_2 )
{
F_5 ( V_205 , & V_2 -> V_18 ) ;
F_162 ( V_2 ) ;
F_153 ( L_13 , V_204 ,
V_2 -> V_207 ) ;
}
void F_163 ( struct V_1 * V_2 )
{
F_161 ( V_2 ) ;
F_142 ( V_2 ) ;
}
static int F_164 ( struct V_1 * V_2 , struct V_99 * V_100 )
{
F_5 ( V_225 , & V_100 -> V_83 ) ;
if ( F_3 ( V_226 , & V_100 -> V_83 ) ) {
F_7 ( V_225 , & V_100 -> V_83 ) ;
return 0 ;
}
F_5 ( V_227 , & V_100 -> V_109 -> V_228 ) ;
F_5 ( V_229 , & V_2 -> V_18 ) ;
return 1 ;
}
static int F_165 ( struct V_1 * V_2 , struct V_99 * V_100 )
{
F_5 ( V_226 , & V_100 -> V_83 ) ;
F_7 ( V_225 , & V_100 -> V_83 ) ;
F_5 ( V_230 , & V_100 -> V_109 -> V_228 ) ;
F_5 ( V_231 , & V_2 -> V_18 ) ;
return 1 ;
}
int F_166 ( const struct V_31 * V_32 , struct V_99 * V_100 )
{
struct V_1 * V_2 = V_32 -> V_1 ;
if ( ! F_92 ( V_100 ) )
return - V_232 ;
F_165 ( V_2 , V_100 ) ;
F_153 ( L_14 , V_204 ,
V_2 -> V_207 ) ;
F_142 ( V_2 ) ;
return 0 ;
}
void F_167 ( struct V_110 * V_110 ,
const T_5 * V_233 )
{
struct V_1 * V_2 = F_168 ( V_110 ) -> V_1 ;
struct V_111 * V_112 = F_90 ( V_110 ) ;
struct V_234 * V_235 ;
struct V_99 * V_100 ;
bool V_236 = false ;
F_15 ( & V_110 -> V_113 ) ;
F_91 (ctx, &nfsi->open_files, list) {
V_100 = V_235 -> V_100 ;
if ( V_100 == NULL )
continue;
if ( ! F_3 ( V_125 , & V_100 -> V_83 ) )
continue;
if ( ! F_169 ( & V_100 -> V_233 , V_233 ) )
continue;
F_165 ( V_2 , V_100 ) ;
V_236 = true ;
}
F_16 ( & V_110 -> V_113 ) ;
if ( V_236 )
F_142 ( V_2 ) ;
}
static void F_170 ( struct V_99 * V_100 )
{
struct V_110 * V_110 = V_100 -> V_110 ;
struct V_111 * V_112 = F_90 ( V_110 ) ;
struct V_234 * V_235 ;
F_15 ( & V_110 -> V_113 ) ;
F_91 (ctx, &nfsi->open_files, list) {
if ( V_235 -> V_100 != V_100 )
continue;
F_5 ( V_237 , & V_235 -> V_83 ) ;
}
F_16 ( & V_110 -> V_113 ) ;
}
static void F_171 ( struct V_99 * V_100 , int error )
{
F_5 ( V_238 , & V_100 -> V_83 ) ;
F_170 ( V_100 ) ;
}
static int F_172 ( struct V_99 * V_100 , const struct V_239 * V_240 )
{
struct V_110 * V_110 = V_100 -> V_110 ;
struct V_111 * V_112 = F_90 ( V_110 ) ;
struct V_151 * V_156 ;
int V_12 = 0 ;
if ( V_110 -> V_241 == NULL )
return 0 ;
F_173 ( & V_112 -> V_242 ) ;
F_15 ( & V_110 -> V_113 ) ;
for ( V_156 = V_110 -> V_241 ; V_156 != NULL ; V_156 = V_156 -> V_243 ) {
if ( ! ( V_156 -> V_158 & ( V_159 | V_160 ) ) )
continue;
if ( F_174 ( V_156 -> V_244 ) -> V_100 != V_100 )
continue;
F_16 ( & V_110 -> V_113 ) ;
V_12 = V_240 -> V_245 ( V_100 , V_156 ) ;
switch ( V_12 ) {
case 0 :
break;
case - V_246 :
case - V_247 :
case - V_186 :
case - V_187 :
case - V_248 :
case - V_249 :
case - V_185 :
case - V_250 :
case - V_251 :
case - V_252 :
case - V_253 :
goto V_26;
default:
F_148 ( V_203 L_15 ,
V_204 , V_12 ) ;
case - V_162 :
case - V_254 :
case - V_255 :
case - V_256 :
V_12 = 0 ;
}
F_15 ( & V_110 -> V_113 ) ;
}
F_16 ( & V_110 -> V_113 ) ;
V_26:
F_175 ( & V_112 -> V_242 ) ;
return V_12 ;
}
static int F_176 ( struct V_33 * V_34 , const struct V_239 * V_240 )
{
struct V_99 * V_100 ;
struct V_127 * V_85 ;
int V_12 = 0 ;
F_15 ( & V_34 -> V_89 ) ;
F_177 ( & V_34 -> V_90 ) ;
V_257:
F_91 (state, &sp->so_states, open_states) {
if ( ! F_28 ( V_240 -> V_258 , & V_100 -> V_83 ) )
continue;
if ( ! F_92 ( V_100 ) )
continue;
if ( V_100 -> V_100 == 0 )
continue;
F_47 ( & V_100 -> V_102 ) ;
F_16 ( & V_34 -> V_89 ) ;
V_12 = V_240 -> V_259 ( V_34 , V_100 ) ;
if ( V_12 >= 0 ) {
V_12 = F_172 ( V_100 , V_240 ) ;
if ( V_12 >= 0 ) {
if ( ! F_3 ( V_125 , & V_100 -> V_83 ) ) {
F_15 ( & V_100 -> V_104 ) ;
F_91 (lock, &state->lock_states, ls_locks) {
if ( ! F_3 ( V_147 , & V_85 -> V_148 ) )
F_130 ( L_16
L_17
L_18 , V_204 ) ;
}
F_16 ( & V_100 -> V_104 ) ;
}
F_98 ( V_100 ) ;
F_15 ( & V_34 -> V_89 ) ;
goto V_257;
}
}
switch ( V_12 ) {
default:
F_148 ( V_203 L_15 ,
V_204 , V_12 ) ;
case - V_166 :
case - V_162 :
case - V_246 :
F_171 ( V_100 , V_12 ) ;
break;
case - V_97 :
F_178 ( 1 ) ;
case - V_247 :
case - V_186 :
case - V_187 :
case - V_255 :
case - V_256 :
F_165 ( V_34 -> V_75 -> V_1 , V_100 ) ;
break;
case - V_248 :
case - V_249 :
F_165 ( V_34 -> V_75 -> V_1 , V_100 ) ;
case - V_185 :
case - V_250 :
case - V_251 :
case - V_252 :
case - V_253 :
goto V_260;
}
F_98 ( V_100 ) ;
F_15 ( & V_34 -> V_89 ) ;
goto V_257;
}
F_179 ( & V_34 -> V_90 ) ;
F_16 ( & V_34 -> V_89 ) ;
return 0 ;
V_260:
F_98 ( V_100 ) ;
F_15 ( & V_34 -> V_89 ) ;
F_179 ( & V_34 -> V_90 ) ;
F_16 ( & V_34 -> V_89 ) ;
return V_12 ;
}
static void F_180 ( struct V_99 * V_100 )
{
struct V_127 * V_85 ;
F_7 ( V_125 , & V_100 -> V_83 ) ;
F_7 ( V_122 , & V_100 -> V_83 ) ;
F_7 ( V_124 , & V_100 -> V_83 ) ;
F_7 ( V_123 , & V_100 -> V_83 ) ;
F_15 ( & V_100 -> V_104 ) ;
F_91 (lock, &state->lock_states, ls_locks) {
V_85 -> V_140 . V_83 = 0 ;
F_7 ( V_147 , & V_85 -> V_148 ) ;
}
F_16 ( & V_100 -> V_104 ) ;
}
static void F_181 ( struct V_31 * V_32 ,
int (* F_182)( struct V_1 * V_2 , struct V_99 * V_100 ) )
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
if ( F_182 ( V_2 , V_100 ) )
F_180 ( V_100 ) ;
}
F_16 ( & V_34 -> V_89 ) ;
}
F_16 ( & V_2 -> V_30 ) ;
}
static void F_183 ( struct V_1 * V_2 ,
int (* F_182)( struct V_1 * V_2 , struct V_99 * V_100 ) )
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
const struct V_239 * V_240 ,
struct V_3 * V_4 )
{
if ( V_240 -> V_261 )
( void ) V_240 -> V_261 ( V_2 , V_4 ) ;
}
static void F_187 ( struct V_31 * V_32 )
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
if ( ! F_28 ( V_225 ,
& V_100 -> V_83 ) )
continue;
F_165 ( V_2 , V_100 ) ;
}
F_16 ( & V_34 -> V_89 ) ;
}
F_16 ( & V_2 -> V_30 ) ;
}
static int F_188 ( struct V_1 * V_2 )
{
struct V_31 * V_32 ;
if ( ! F_28 ( V_229 , & V_2 -> V_18 ) )
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
const struct V_239 * V_240 ;
struct V_3 * V_4 ;
if ( ! F_188 ( V_2 ) )
return;
V_240 = V_2 -> V_149 -> V_262 ;
V_4 = F_44 ( V_2 ) ;
F_186 ( V_2 , V_240 , V_4 ) ;
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
case - V_263 :
F_161 ( V_2 ) ;
break;
case - V_249 :
F_190 ( V_2 ) ;
break;
case - V_185 :
F_5 ( V_205 , & V_2 -> V_18 ) ;
F_188 ( V_2 ) ;
F_184 ( V_2 ) ;
break;
case - V_248 :
F_5 ( V_205 , & V_2 -> V_18 ) ;
F_192 ( V_2 ) ;
break;
case - V_250 :
case - V_251 :
case - V_252 :
case - V_264 :
case - V_265 :
case - V_266 :
F_5 ( V_65 , & V_2 -> V_18 ) ;
break;
case - V_253 :
F_5 ( V_66 , & V_2 -> V_18 ) ;
break;
default:
F_153 ( L_19 ,
V_204 , error , V_2 -> V_207 ) ;
return error ;
}
F_153 ( L_20 , V_204 , error ,
V_2 -> V_207 ) ;
return 0 ;
}
static int F_194 ( struct V_1 * V_2 , const struct V_239 * V_240 )
{
struct V_33 * V_34 ;
struct V_31 * V_32 ;
struct V_35 * V_36 ;
int V_12 = 0 ;
V_257:
F_24 () ;
F_25 (server, &clp->cl_superblocks, client_link) {
F_84 ( V_32 ) ;
F_15 ( & V_2 -> V_30 ) ;
for ( V_36 = F_19 ( & V_32 -> V_37 ) ;
V_36 != NULL ;
V_36 = F_20 ( V_36 ) ) {
V_34 = F_21 ( V_36 ,
struct V_33 , V_38 ) ;
if ( ! F_28 ( V_240 -> V_267 ,
& V_34 -> V_228 ) )
continue;
F_47 ( & V_34 -> V_74 ) ;
F_16 ( & V_2 -> V_30 ) ;
F_26 () ;
V_12 = F_176 ( V_34 , V_240 ) ;
if ( V_12 < 0 ) {
F_5 ( V_240 -> V_267 , & V_34 -> V_228 ) ;
F_81 ( V_34 ) ;
return F_193 ( V_2 , V_12 ) ;
}
F_81 ( V_34 ) ;
goto V_257;
}
F_16 ( & V_2 -> V_30 ) ;
}
F_26 () ;
return V_12 ;
}
static int F_195 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
const struct V_268 * V_240 =
V_2 -> V_149 -> V_269 ;
int V_12 ;
if ( F_3 ( V_205 , & V_2 -> V_18 ) )
return 0 ;
F_15 ( & V_2 -> V_30 ) ;
V_4 = V_240 -> V_270 ( V_2 ) ;
F_16 ( & V_2 -> V_30 ) ;
if ( V_4 == NULL ) {
V_4 = F_44 ( V_2 ) ;
V_12 = - V_271 ;
if ( V_4 == NULL )
goto V_26;
}
V_12 = V_240 -> V_272 ( V_2 , V_4 ) ;
F_17 ( V_4 ) ;
if ( V_12 == - V_273 ) {
F_5 ( V_206 , & V_2 -> V_18 ) ;
return 0 ;
}
V_26:
return F_193 ( V_2 , V_12 ) ;
}
static int F_196 ( struct V_1 * V_2 , int V_12 )
{
switch ( V_12 ) {
case - V_266 :
if ( F_143 ( V_274 , & V_2 -> V_18 ) )
return - V_275 ;
F_178 ( 1 ) ;
F_7 ( V_17 , & V_2 -> V_18 ) ;
break;
case - V_185 :
F_7 ( V_17 , & V_2 -> V_18 ) ;
F_188 ( V_2 ) ;
F_184 ( V_2 ) ;
break;
case - V_276 :
F_155 ( L_21 ,
V_2 -> V_207 ) ;
F_41 ( V_2 , - V_277 ) ;
F_7 ( V_17 , & V_2 -> V_18 ) ;
return - V_277 ;
case - V_278 :
case - V_279 :
case - V_273 :
case - V_97 :
F_178 ( 1 ) ;
break;
case - V_280 :
if ( V_2 -> V_222 == V_281 )
F_41 ( V_2 , - V_282 ) ;
F_153 ( L_22 ,
V_204 , - V_282 , V_2 -> V_207 ) ;
return - V_282 ;
case - V_283 :
default:
F_153 ( L_22 , V_204 ,
V_12 , V_2 -> V_207 ) ;
return V_12 ;
}
F_5 ( V_205 , & V_2 -> V_18 ) ;
F_153 ( L_20 , V_204 , V_12 ,
V_2 -> V_207 ) ;
return 0 ;
}
static int F_197 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
const struct V_239 * V_240 =
V_2 -> V_149 -> V_262 ;
int V_12 ;
V_4 = F_44 ( V_2 ) ;
if ( V_4 == NULL )
return - V_166 ;
V_12 = V_240 -> V_284 ( V_2 , V_4 ) ;
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
if ( F_28 ( V_285 , & V_2 -> V_18 ) )
F_192 ( V_2 ) ;
if ( ! F_3 ( V_231 , & V_2 -> V_18 ) )
F_5 ( V_229 , & V_2 -> V_18 ) ;
F_7 ( V_206 , & V_2 -> V_18 ) ;
F_7 ( V_205 , & V_2 -> V_18 ) ;
return 0 ;
}
static int F_200 ( struct V_1 * V_2 )
{
int V_12 ;
V_12 = F_197 ( V_2 ) ;
if ( V_12 < 0 )
return F_196 ( V_2 , V_12 ) ;
F_7 ( V_274 , & V_2 -> V_18 ) ;
F_5 ( V_205 , & V_2 -> V_18 ) ;
F_192 ( V_2 ) ;
return 0 ;
}
static int F_201 ( struct V_31 * V_32 , struct V_3 * V_4 )
{
struct V_1 * V_2 = V_32 -> V_1 ;
struct V_286 * V_287 = NULL ;
struct V_110 * V_110 ;
struct V_288 * V_288 ;
int V_12 , V_27 ;
F_153 ( L_23 , V_204 ,
( unsigned long long ) V_32 -> V_213 . V_214 ,
( unsigned long long ) V_32 -> V_213 . V_215 ,
V_2 -> V_207 ) ;
V_27 = 0 ;
V_288 = F_202 ( V_126 ) ;
V_287 = F_124 ( sizeof( struct V_286 ) , V_126 ) ;
if ( V_288 == NULL || V_287 == NULL ) {
F_153 ( L_24 , V_204 ) ;
goto V_26;
}
V_110 = V_32 -> V_289 -> V_290 -> V_291 ;
V_27 = F_203 ( V_110 , V_287 , V_288 , V_4 ) ;
if ( V_27 ) {
F_153 ( L_25 ,
V_204 , V_27 ) ;
goto V_26;
}
V_27 = - V_292 ;
if ( ! ( V_287 -> V_293 . V_294 & V_295 ) ) {
F_153 ( L_26 ,
V_204 ) ;
goto V_26;
}
F_34 ( V_2 ) ;
V_12 = F_204 ( V_32 , V_287 ) ;
if ( V_12 != 0 ) {
F_153 ( L_27 ,
V_204 , V_12 ) ;
goto V_26;
}
V_27 = 0 ;
F_153 ( L_28 , V_204 ) ;
V_26:
if ( V_288 != NULL )
F_205 ( V_288 ) ;
F_72 ( V_287 ) ;
if ( V_27 ) {
F_155 ( L_29 ,
V_2 -> V_207 ) ;
F_5 ( V_211 , & V_32 -> V_212 ) ;
}
return V_27 ;
}
static int F_206 ( struct V_1 * V_2 )
{
const struct V_268 * V_240 =
V_2 -> V_149 -> V_269 ;
struct V_31 * V_32 ;
struct V_3 * V_4 ;
F_153 ( L_30 , V_204 ,
V_2 -> V_207 ) ;
F_15 ( & V_2 -> V_30 ) ;
V_4 = V_240 -> V_270 ( V_2 ) ;
F_16 ( & V_2 -> V_30 ) ;
if ( V_4 == NULL )
return - V_296 ;
V_2 -> V_297 ++ ;
V_257:
F_24 () ;
F_25 (server, &clp->cl_superblocks, client_link) {
int V_12 ;
if ( V_32 -> V_298 == V_2 -> V_297 )
continue;
V_32 -> V_298 = V_2 -> V_297 ;
if ( ! F_28 ( V_216 ,
& V_32 -> V_212 ) )
continue;
F_26 () ;
V_12 = F_201 ( V_32 , V_4 ) ;
if ( V_12 < 0 ) {
F_17 ( V_4 ) ;
return V_12 ;
}
goto V_257;
}
F_26 () ;
F_17 ( V_4 ) ;
return 0 ;
}
static int F_207 ( struct V_1 * V_2 )
{
const struct V_268 * V_240 =
V_2 -> V_149 -> V_269 ;
struct V_31 * V_32 ;
struct V_3 * V_4 ;
F_153 ( L_31 , V_204 ,
V_2 -> V_207 ) ;
F_15 ( & V_2 -> V_30 ) ;
V_4 = V_240 -> V_270 ( V_2 ) ;
F_16 ( & V_2 -> V_30 ) ;
if ( V_4 == NULL )
return - V_296 ;
V_2 -> V_297 ++ ;
V_257:
F_24 () ;
F_25 (server, &clp->cl_superblocks, client_link) {
struct V_110 * V_110 ;
int V_12 ;
if ( V_32 -> V_298 == V_2 -> V_297 )
continue;
V_32 -> V_298 = V_2 -> V_297 ;
F_26 () ;
V_110 = V_32 -> V_289 -> V_290 -> V_291 ;
V_12 = F_208 ( V_110 , V_4 ) ;
if ( V_12 != - V_299 )
goto V_257;
if ( F_201 ( V_32 , V_4 ) == - V_300 )
goto V_257;
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
const struct V_239 * V_240 =
V_2 -> V_149 -> V_262 ;
struct V_301 * V_302 ;
struct V_3 * V_4 ;
int V_303 , V_12 ;
F_153 ( L_32 , V_204 , V_2 -> V_207 ) ;
V_302 = V_2 -> V_200 ;
V_303 = 0 ;
F_210 ( & V_304 ) ;
V_305:
V_12 = - V_166 ;
V_4 = F_44 ( V_2 ) ;
if ( V_4 == NULL )
goto V_306;
V_12 = V_240 -> V_307 ( V_2 , V_27 , V_4 ) ;
F_17 ( V_4 ) ;
switch ( V_12 ) {
case 0 :
break;
case - V_279 :
case - V_273 :
case - V_97 :
F_178 ( 1 ) ;
case - V_185 :
F_153 ( L_33 ,
V_204 , V_12 ) ;
goto V_305;
case - V_278 :
if ( V_303 ++ == 0 ) {
F_13 ( V_2 ) ;
goto V_305;
}
if ( V_302 -> V_308 -> V_309 == V_310 )
break;
case - V_276 :
case - V_311 :
if ( V_302 -> V_308 -> V_309 == V_310 ) {
V_12 = - V_277 ;
break;
}
V_302 = F_211 ( V_302 , V_310 ) ;
if ( F_147 ( V_302 ) ) {
V_12 = F_149 ( V_302 ) ;
break;
}
V_302 = F_212 ( & V_2 -> V_200 , V_302 ) ;
F_213 ( V_302 ) ;
V_302 = V_2 -> V_200 ;
goto V_305;
case - V_280 :
V_12 = - V_282 ;
break;
case - V_312 :
case - V_283 :
V_12 = - V_312 ;
break;
default:
F_214 ( L_34 ,
V_204 , V_12 ) ;
V_12 = - V_170 ;
}
V_306:
F_215 ( & V_304 ) ;
F_153 ( L_35 , V_204 , V_12 ) ;
return V_12 ;
}
void F_216 ( struct V_46 * V_313 , int V_76 )
{
struct V_1 * V_2 = V_313 -> V_2 ;
switch ( V_76 ) {
default:
F_5 ( V_65 , & V_2 -> V_18 ) ;
break;
case - V_253 :
F_5 ( V_66 , & V_2 -> V_18 ) ;
}
F_152 ( V_2 ) ;
}
static void F_217 ( struct V_1 * V_2 )
{
F_5 ( V_206 , & V_2 -> V_18 ) ;
F_142 ( V_2 ) ;
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
if ( F_143 ( V_205 , & V_2 -> V_18 ) == 0 ) {
F_5 ( V_274 , & V_2 -> V_18 ) ;
F_7 ( V_17 , & V_2 -> V_18 ) ;
F_192 ( V_2 ) ;
F_153 ( L_36 ,
V_204 , V_2 -> V_207 ) ;
F_142 ( V_2 ) ;
}
}
static void F_221 ( struct V_1 * V_2 )
{
if ( F_143 ( V_205 , & V_2 -> V_18 ) == 0 ) {
F_184 ( V_2 ) ;
F_153 ( L_37 , V_204 ,
V_2 -> V_207 ) ;
F_142 ( V_2 ) ;
}
}
static void F_222 ( struct V_1 * V_2 )
{
F_220 ( V_2 ) ;
F_153 ( L_38 , V_204 , V_2 -> V_207 ) ;
}
static void F_223 ( struct V_1 * V_2 )
{
F_162 ( V_2 ) ;
F_153 ( L_39 , V_204 ,
V_2 -> V_207 ) ;
}
static void F_224 ( struct V_1 * V_2 )
{
F_162 ( V_2 ) ;
if ( F_143 ( V_65 , & V_2 -> V_18 ) == 0 )
F_142 ( V_2 ) ;
F_153 ( L_40 , V_204 ,
V_2 -> V_207 ) ;
}
static void F_225 ( struct V_1 * V_2 )
{
if ( F_143 ( V_66 ,
& V_2 -> V_18 ) == 0 )
F_142 ( V_2 ) ;
}
void F_226 ( struct V_1 * V_2 , T_6 V_83 )
{
if ( ! V_83 )
return;
F_153 ( L_41 ,
V_204 , V_2 -> V_207 , V_2 -> V_8 , V_83 ) ;
if ( V_83 & V_314 )
F_221 ( V_2 ) ;
if ( V_83 & ( V_315 |
V_316 |
V_317 ) )
F_222 ( V_2 ) ;
if ( V_83 & V_318 )
F_156 ( V_2 ) ;
if ( V_83 & V_319 )
F_223 ( V_2 ) ;
if ( V_83 & V_320 )
F_224 ( V_2 ) ;
else if ( V_83 & ( V_321 |
V_322 ) )
F_225 ( V_2 ) ;
}
static int F_227 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
int V_12 ;
if ( ! F_133 ( V_2 ) )
return 0 ;
F_34 ( V_2 ) ;
V_4 = F_44 ( V_2 ) ;
V_12 = F_228 ( V_2 -> V_48 , V_4 ) ;
switch ( V_12 ) {
case 0 :
case - V_250 :
case - V_264 :
break;
case - V_323 :
case - V_279 :
F_5 ( V_65 , & V_2 -> V_18 ) ;
V_12 = 0 ;
F_178 ( 1 ) ;
goto V_26;
default:
V_12 = F_193 ( V_2 , V_12 ) ;
goto V_26;
}
memset ( V_2 -> V_48 -> V_324 . V_325 , 0 , V_326 ) ;
V_12 = F_40 ( V_2 , V_4 ) ;
if ( V_12 ) {
F_153 ( L_42 ,
V_204 , V_12 , V_2 -> V_207 ) ;
V_12 = F_196 ( V_2 , V_12 ) ;
goto V_26;
}
F_37 ( V_2 ) ;
F_153 ( L_43 ,
V_204 , V_2 -> V_207 ) ;
V_26:
if ( V_4 )
F_17 ( V_4 ) ;
return V_12 ;
}
static int F_229 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
int V_55 ;
if ( ! F_133 ( V_2 ) )
return 0 ;
F_34 ( V_2 ) ;
V_4 = F_44 ( V_2 ) ;
V_55 = F_230 ( V_2 , V_4 ) ;
if ( V_4 )
F_17 ( V_4 ) ;
F_7 ( V_66 , & V_2 -> V_18 ) ;
switch ( V_55 ) {
case 0 :
F_153 ( L_44 ,
V_204 , V_2 -> V_207 ) ;
break;
case - V_279 :
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
const char * V_327 = L_45 , * V_328 = L_45 ;
do {
if ( F_3 ( V_274 , & V_2 -> V_18 ) ) {
V_327 = L_46 ;
V_12 = F_200 ( V_2 ) ;
if ( V_12 < 0 )
goto V_329;
continue;
}
if ( F_3 ( V_205 , & V_2 -> V_18 ) ) {
V_327 = L_47 ;
V_12 = F_199 ( V_2 ) ;
if ( V_12 < 0 )
goto V_329;
continue;
}
if ( F_28 ( V_65 , & V_2 -> V_18 ) ) {
V_327 = L_48 ;
V_12 = F_227 ( V_2 ) ;
if ( F_3 ( V_205 , & V_2 -> V_18 ) )
continue;
if ( V_12 < 0 )
goto V_329;
}
if ( F_28 ( V_66 ,
& V_2 -> V_18 ) ) {
V_327 = L_49 ;
V_12 = F_229 ( V_2 ) ;
if ( V_12 < 0 )
goto V_329;
continue;
}
if ( F_28 ( V_206 , & V_2 -> V_18 ) ) {
V_327 = L_50 ;
V_12 = F_195 ( V_2 ) ;
if ( V_12 < 0 )
goto V_329;
}
if ( F_28 ( V_217 , & V_2 -> V_18 ) ) {
V_327 = L_51 ;
V_12 = F_206 ( V_2 ) ;
if ( V_12 < 0 )
goto V_329;
}
if ( F_28 ( V_218 , & V_2 -> V_18 ) ) {
V_327 = L_52 ;
V_12 = F_207 ( V_2 ) ;
if ( V_12 < 0 )
goto V_329;
}
if ( F_3 ( V_229 , & V_2 -> V_18 ) ) {
V_327 = L_53 ;
V_12 = F_194 ( V_2 ,
V_2 -> V_149 -> V_262 ) ;
if ( F_3 ( V_205 , & V_2 -> V_18 ) ||
F_3 ( V_65 , & V_2 -> V_18 ) )
continue;
F_190 ( V_2 ) ;
if ( F_3 ( V_231 , & V_2 -> V_18 ) )
continue;
if ( V_12 < 0 )
goto V_329;
}
if ( F_28 ( V_231 , & V_2 -> V_18 ) ) {
V_327 = L_54 ;
V_12 = F_194 ( V_2 ,
V_2 -> V_149 -> V_330 ) ;
if ( F_3 ( V_205 , & V_2 -> V_18 ) ||
F_3 ( V_65 , & V_2 -> V_18 ) ||
F_3 ( V_229 , & V_2 -> V_18 ) )
continue;
if ( V_12 < 0 )
goto V_329;
}
F_30 ( V_2 ) ;
if ( F_28 ( V_331 , & V_2 -> V_18 ) ) {
F_232 ( V_2 ) ;
continue;
}
F_137 ( V_2 ) ;
if ( V_2 -> V_18 == 0 )
break;
if ( F_143 ( V_193 , & V_2 -> V_18 ) != 0 )
break;
} while ( F_233 ( & V_2 -> V_199 ) > 1 );
return;
V_329:
if ( strlen ( V_327 ) )
V_328 = L_55 ;
F_130 ( L_56
L_57 , V_328 , V_327 ,
V_2 -> V_207 , - V_12 ) ;
F_178 ( 1 ) ;
F_30 ( V_2 ) ;
F_137 ( V_2 ) ;
}
static int V_202 ( void * V_332 )
{
struct V_1 * V_2 = V_332 ;
F_234 ( V_333 ) ;
F_231 ( V_2 ) ;
F_150 ( V_2 ) ;
F_235 ( 0 ) ;
return 0 ;
}
