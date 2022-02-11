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
}
F_16 ( & V_100 -> V_104 ) ;
F_110 ( V_139 ) ;
V_26:
return V_55 ;
}
static void F_116 ( T_5 * V_152 , struct V_99 * V_100 )
{
const T_5 * V_153 ;
int V_172 ;
do {
V_153 = & V_173 ;
V_172 = F_117 ( & V_100 -> V_105 ) ;
if ( F_3 ( V_174 , & V_100 -> V_83 ) )
V_153 = & V_100 -> V_175 ;
F_115 ( V_152 , V_153 ) ;
} while ( F_118 ( & V_100 -> V_105 , V_172 ) );
}
int F_119 ( T_5 * V_152 , struct V_99 * V_100 ,
T_2 V_106 , const struct V_164 * V_165 )
{
int V_55 = F_114 ( V_152 , V_100 , V_165 ) ;
if ( V_55 == - V_170 )
goto V_26;
if ( F_120 ( V_152 , V_100 -> V_110 , V_106 ) ) {
V_55 = 0 ;
goto V_26;
}
if ( V_55 != - V_166 )
goto V_26;
F_116 ( V_152 , V_100 ) ;
V_55 = 0 ;
V_26:
if ( F_121 ( V_100 -> V_110 , V_176 ) )
V_152 -> V_177 = 0 ;
return V_55 ;
}
struct V_178 * F_122 ( struct V_80 * V_84 , T_1 V_115 )
{
struct V_178 * V_29 ;
V_29 = F_123 ( sizeof( * V_29 ) , V_115 ) ;
if ( V_29 != NULL ) {
V_29 -> V_179 = V_84 ;
F_60 ( & V_29 -> V_86 ) ;
V_29 -> V_180 = NULL ;
}
return V_29 ;
}
void F_124 ( struct V_178 * V_177 )
{
struct V_80 * V_179 ;
if ( F_22 ( & V_177 -> V_86 ) )
return;
V_179 = V_177 -> V_179 ;
F_15 ( & V_179 -> V_85 ) ;
F_46 ( & V_177 -> V_86 ) ;
if ( ! F_22 ( & V_179 -> V_86 ) ) {
struct V_178 * V_181 ;
V_181 = F_125 ( & V_179 -> V_86 ,
struct V_178 , V_86 ) ;
F_126 ( & V_179 -> V_87 , V_181 -> V_180 ) ;
}
F_16 ( & V_179 -> V_85 ) ;
}
void F_127 ( struct V_178 * V_177 )
{
F_124 ( V_177 ) ;
F_72 ( V_177 ) ;
}
static void F_128 ( int V_12 , struct V_178 * V_177 )
{
switch ( V_12 ) {
case 0 :
break;
case - V_182 :
if ( V_177 -> V_179 -> V_83 & V_183 )
return;
F_129 ( L_2
L_3
L_4 ,
V_177 -> V_179 ) ;
case - V_184 :
case - V_185 :
case - V_186 :
case - V_187 :
case - V_188 :
case - V_189 :
return;
} ;
V_177 -> V_179 -> V_84 ++ ;
}
void F_130 ( int V_12 , struct V_178 * V_177 )
{
struct V_33 * V_34 = F_131 ( V_177 -> V_179 ,
struct V_33 , V_78 ) ;
struct V_31 * V_32 = V_34 -> V_75 ;
if ( V_12 == - V_182 )
F_69 ( V_34 ) ;
if ( ! F_132 ( V_32 -> V_1 ) )
F_128 ( V_12 , V_177 ) ;
}
void F_133 ( int V_12 , struct V_178 * V_177 )
{
F_128 ( V_12 , V_177 ) ;
}
int F_134 ( struct V_178 * V_177 , struct V_190 * V_180 )
{
struct V_80 * V_179 = V_177 -> V_179 ;
int V_12 = 0 ;
F_15 ( & V_179 -> V_85 ) ;
V_177 -> V_180 = V_180 ;
if ( F_22 ( & V_177 -> V_86 ) )
F_83 ( & V_177 -> V_86 , & V_179 -> V_86 ) ;
if ( F_125 ( & V_179 -> V_86 , struct V_178 , V_86 ) == V_177 )
goto V_191;
F_135 ( & V_179 -> V_87 , V_180 , NULL ) ;
V_12 = - V_97 ;
V_191:
F_16 ( & V_179 -> V_85 ) ;
return V_12 ;
}
static void F_136 ( struct V_1 * V_2 )
{
F_137 () ;
F_7 ( V_192 , & V_2 -> V_18 ) ;
F_138 () ;
F_139 ( & V_2 -> V_18 , V_192 ) ;
F_140 ( & V_2 -> V_193 ) ;
}
void F_141 ( struct V_1 * V_2 )
{
struct V_194 * V_180 ;
char V_195 [ V_196 + sizeof( L_5 ) + 1 ] ;
if ( F_142 ( V_192 , & V_2 -> V_18 ) != 0 )
return;
F_143 ( V_197 ) ;
F_47 ( & V_2 -> V_198 ) ;
F_24 () ;
snprintf ( V_195 , sizeof( V_195 ) , L_6 ,
F_144 ( V_2 -> V_199 , V_200 ) ) ;
F_26 () ;
V_180 = F_145 ( V_201 , V_2 , L_7 , V_195 ) ;
if ( F_146 ( V_180 ) ) {
F_147 ( V_202 L_8 ,
V_203 , F_148 ( V_180 ) ) ;
F_136 ( V_2 ) ;
F_149 ( V_2 ) ;
F_150 ( V_197 ) ;
}
}
void F_151 ( struct V_1 * V_2 )
{
if ( ! V_2 )
return;
if ( ! F_3 ( V_204 , & V_2 -> V_18 ) )
F_5 ( V_205 , & V_2 -> V_18 ) ;
F_152 ( L_9 , V_203 ,
V_2 -> V_206 ) ;
F_141 ( V_2 ) ;
}
int F_153 ( const struct V_31 * V_32 )
{
struct V_1 * V_2 = V_32 -> V_1 ;
if ( V_32 -> V_207 != V_208 ) {
F_154 ( L_10 ,
V_2 -> V_206 ) ;
return - V_209 ;
}
if ( F_3 ( V_210 , & V_32 -> V_211 ) )
return - V_209 ;
F_152 ( L_11 ,
V_203 ,
( unsigned long long ) V_32 -> V_212 . V_213 ,
( unsigned long long ) V_32 -> V_212 . V_214 ,
V_2 -> V_206 ) ;
F_5 ( V_215 ,
& ( (struct V_31 * ) V_32 ) -> V_211 ) ;
F_5 ( V_216 , & V_2 -> V_18 ) ;
F_141 ( V_2 ) ;
return 0 ;
}
void F_155 ( struct V_1 * V_2 )
{
F_152 ( L_12 ,
V_203 , V_2 -> V_8 , V_2 -> V_206 ) ;
F_5 ( V_217 , & V_2 -> V_18 ) ;
F_141 ( V_2 ) ;
}
int F_156 ( struct V_1 * V_2 )
{
int V_218 ;
F_157 () ;
F_47 ( & V_2 -> V_198 ) ;
V_218 = F_158 ( & V_2 -> V_18 , V_192 ,
V_219 , V_220 ) ;
if ( V_218 )
goto V_26;
if ( V_2 -> V_221 < 0 )
V_218 = V_2 -> V_221 ;
V_26:
F_149 ( V_2 ) ;
return V_218 ;
}
int F_159 ( struct V_1 * V_2 )
{
unsigned int V_222 ;
int V_55 ;
for ( V_222 = V_223 ; V_222 != 0 ; V_222 -- ) {
V_55 = F_156 ( V_2 ) ;
if ( V_55 != 0 )
break;
if ( ! F_3 ( V_204 , & V_2 -> V_18 ) &&
! F_3 ( V_205 , & V_2 -> V_18 ) )
break;
F_141 ( V_2 ) ;
V_55 = - V_170 ;
}
return V_55 ;
}
static void F_160 ( struct V_1 * V_2 )
{
F_5 ( V_204 , & V_2 -> V_18 ) ;
F_161 ( V_2 ) ;
F_152 ( L_13 , V_203 ,
V_2 -> V_206 ) ;
}
void F_162 ( struct V_1 * V_2 )
{
F_160 ( V_2 ) ;
F_141 ( V_2 ) ;
}
static int F_163 ( struct V_1 * V_2 , struct V_99 * V_100 )
{
F_5 ( V_224 , & V_100 -> V_83 ) ;
if ( F_3 ( V_225 , & V_100 -> V_83 ) ) {
F_7 ( V_224 , & V_100 -> V_83 ) ;
return 0 ;
}
F_5 ( V_226 , & V_100 -> V_109 -> V_227 ) ;
F_5 ( V_228 , & V_2 -> V_18 ) ;
return 1 ;
}
static int F_164 ( struct V_1 * V_2 , struct V_99 * V_100 )
{
F_5 ( V_225 , & V_100 -> V_83 ) ;
F_7 ( V_224 , & V_100 -> V_83 ) ;
F_5 ( V_229 , & V_100 -> V_109 -> V_227 ) ;
F_5 ( V_230 , & V_2 -> V_18 ) ;
return 1 ;
}
int F_165 ( const struct V_31 * V_32 , struct V_99 * V_100 )
{
struct V_1 * V_2 = V_32 -> V_1 ;
if ( ! F_92 ( V_100 ) )
return - V_231 ;
F_164 ( V_2 , V_100 ) ;
F_152 ( L_14 , V_203 ,
V_2 -> V_206 ) ;
F_141 ( V_2 ) ;
return 0 ;
}
void F_166 ( struct V_110 * V_110 ,
const T_5 * V_232 )
{
struct V_1 * V_2 = F_167 ( V_110 ) -> V_1 ;
struct V_111 * V_112 = F_90 ( V_110 ) ;
struct V_233 * V_234 ;
struct V_99 * V_100 ;
bool V_235 = false ;
F_15 ( & V_110 -> V_113 ) ;
F_91 (ctx, &nfsi->open_files, list) {
V_100 = V_234 -> V_100 ;
if ( V_100 == NULL )
continue;
if ( ! F_3 ( V_125 , & V_100 -> V_83 ) )
continue;
if ( ! F_168 ( & V_100 -> V_232 , V_232 ) )
continue;
F_164 ( V_2 , V_100 ) ;
V_235 = true ;
}
F_16 ( & V_110 -> V_113 ) ;
if ( V_235 )
F_141 ( V_2 ) ;
}
static void F_169 ( struct V_99 * V_100 )
{
struct V_110 * V_110 = V_100 -> V_110 ;
struct V_111 * V_112 = F_90 ( V_110 ) ;
struct V_233 * V_234 ;
F_15 ( & V_110 -> V_113 ) ;
F_91 (ctx, &nfsi->open_files, list) {
if ( V_234 -> V_100 != V_100 )
continue;
F_5 ( V_236 , & V_234 -> V_83 ) ;
}
F_16 ( & V_110 -> V_113 ) ;
}
static void F_170 ( struct V_99 * V_100 , int error )
{
F_5 ( V_237 , & V_100 -> V_83 ) ;
F_169 ( V_100 ) ;
}
static int F_171 ( struct V_99 * V_100 , const struct V_238 * V_239 )
{
struct V_110 * V_110 = V_100 -> V_110 ;
struct V_111 * V_112 = F_90 ( V_110 ) ;
struct V_151 * V_156 ;
int V_12 = 0 ;
if ( V_110 -> V_240 == NULL )
return 0 ;
F_172 ( & V_112 -> V_241 ) ;
F_15 ( & V_110 -> V_113 ) ;
for ( V_156 = V_110 -> V_240 ; V_156 != NULL ; V_156 = V_156 -> V_242 ) {
if ( ! ( V_156 -> V_158 & ( V_159 | V_160 ) ) )
continue;
if ( F_173 ( V_156 -> V_243 ) -> V_100 != V_100 )
continue;
F_16 ( & V_110 -> V_113 ) ;
V_12 = V_239 -> V_244 ( V_100 , V_156 ) ;
switch ( V_12 ) {
case 0 :
break;
case - V_245 :
case - V_246 :
case - V_185 :
case - V_186 :
case - V_247 :
case - V_248 :
case - V_184 :
case - V_249 :
case - V_250 :
case - V_251 :
case - V_252 :
goto V_26;
default:
F_147 ( V_202 L_15 ,
V_203 , V_12 ) ;
case - V_162 :
case - V_253 :
case - V_254 :
case - V_255 :
V_12 = 0 ;
}
F_15 ( & V_110 -> V_113 ) ;
}
F_16 ( & V_110 -> V_113 ) ;
V_26:
F_174 ( & V_112 -> V_241 ) ;
return V_12 ;
}
static int F_175 ( struct V_33 * V_34 , const struct V_238 * V_239 )
{
struct V_99 * V_100 ;
struct V_127 * V_85 ;
int V_12 = 0 ;
F_15 ( & V_34 -> V_89 ) ;
F_176 ( & V_34 -> V_90 ) ;
V_256:
F_91 (state, &sp->so_states, open_states) {
if ( ! F_28 ( V_239 -> V_257 , & V_100 -> V_83 ) )
continue;
if ( ! F_92 ( V_100 ) )
continue;
if ( V_100 -> V_100 == 0 )
continue;
F_47 ( & V_100 -> V_102 ) ;
F_16 ( & V_34 -> V_89 ) ;
V_12 = V_239 -> V_258 ( V_34 , V_100 ) ;
if ( V_12 >= 0 ) {
V_12 = F_171 ( V_100 , V_239 ) ;
if ( V_12 >= 0 ) {
if ( ! F_3 ( V_125 , & V_100 -> V_83 ) ) {
F_15 ( & V_100 -> V_104 ) ;
F_91 (lock, &state->lock_states, ls_locks) {
if ( ! F_3 ( V_147 , & V_85 -> V_148 ) )
F_129 ( L_16
L_17
L_18 , V_203 ) ;
}
F_16 ( & V_100 -> V_104 ) ;
}
F_98 ( V_100 ) ;
F_15 ( & V_34 -> V_89 ) ;
goto V_256;
}
}
switch ( V_12 ) {
default:
F_147 ( V_202 L_15 ,
V_203 , V_12 ) ;
case - V_166 :
case - V_162 :
case - V_245 :
F_170 ( V_100 , V_12 ) ;
break;
case - V_97 :
F_177 ( 1 ) ;
case - V_246 :
case - V_185 :
case - V_186 :
case - V_254 :
case - V_255 :
F_164 ( V_34 -> V_75 -> V_1 , V_100 ) ;
break;
case - V_247 :
case - V_248 :
F_164 ( V_34 -> V_75 -> V_1 , V_100 ) ;
case - V_184 :
case - V_249 :
case - V_250 :
case - V_251 :
case - V_252 :
goto V_259;
}
F_98 ( V_100 ) ;
F_15 ( & V_34 -> V_89 ) ;
goto V_256;
}
F_178 ( & V_34 -> V_90 ) ;
F_16 ( & V_34 -> V_89 ) ;
return 0 ;
V_259:
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
V_85 -> V_140 . V_83 = 0 ;
F_7 ( V_147 , & V_85 -> V_148 ) ;
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
const struct V_238 * V_239 ,
struct V_3 * V_4 )
{
if ( V_239 -> V_260 )
( void ) V_239 -> V_260 ( V_2 , V_4 ) ;
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
if ( ! F_28 ( V_224 ,
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
if ( ! F_28 ( V_228 , & V_2 -> V_18 ) )
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
const struct V_238 * V_239 ;
struct V_3 * V_4 ;
if ( ! F_187 ( V_2 ) )
return;
V_239 = V_2 -> V_149 -> V_261 ;
V_4 = F_44 ( V_2 ) ;
F_185 ( V_2 , V_239 , V_4 ) ;
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
case - V_262 :
F_160 ( V_2 ) ;
break;
case - V_248 :
F_189 ( V_2 ) ;
break;
case - V_184 :
F_5 ( V_204 , & V_2 -> V_18 ) ;
F_187 ( V_2 ) ;
F_183 ( V_2 ) ;
break;
case - V_247 :
F_5 ( V_204 , & V_2 -> V_18 ) ;
F_191 ( V_2 ) ;
break;
case - V_249 :
case - V_250 :
case - V_251 :
case - V_263 :
case - V_264 :
case - V_265 :
F_5 ( V_65 , & V_2 -> V_18 ) ;
break;
case - V_252 :
F_5 ( V_66 , & V_2 -> V_18 ) ;
break;
default:
F_152 ( L_19 ,
V_203 , error , V_2 -> V_206 ) ;
return error ;
}
F_152 ( L_20 , V_203 , error ,
V_2 -> V_206 ) ;
return 0 ;
}
static int F_193 ( struct V_1 * V_2 , const struct V_238 * V_239 )
{
struct V_33 * V_34 ;
struct V_31 * V_32 ;
struct V_35 * V_36 ;
int V_12 = 0 ;
V_256:
F_24 () ;
F_25 (server, &clp->cl_superblocks, client_link) {
F_84 ( V_32 ) ;
F_15 ( & V_2 -> V_30 ) ;
for ( V_36 = F_19 ( & V_32 -> V_37 ) ;
V_36 != NULL ;
V_36 = F_20 ( V_36 ) ) {
V_34 = F_21 ( V_36 ,
struct V_33 , V_38 ) ;
if ( ! F_28 ( V_239 -> V_266 ,
& V_34 -> V_227 ) )
continue;
F_47 ( & V_34 -> V_74 ) ;
F_16 ( & V_2 -> V_30 ) ;
F_26 () ;
V_12 = F_175 ( V_34 , V_239 ) ;
if ( V_12 < 0 ) {
F_5 ( V_239 -> V_266 , & V_34 -> V_227 ) ;
F_81 ( V_34 ) ;
return F_192 ( V_2 , V_12 ) ;
}
F_81 ( V_34 ) ;
goto V_256;
}
F_16 ( & V_2 -> V_30 ) ;
}
F_26 () ;
return V_12 ;
}
static int F_194 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
const struct V_267 * V_239 =
V_2 -> V_149 -> V_268 ;
int V_12 ;
if ( F_3 ( V_204 , & V_2 -> V_18 ) )
return 0 ;
F_15 ( & V_2 -> V_30 ) ;
V_4 = V_239 -> V_269 ( V_2 ) ;
F_16 ( & V_2 -> V_30 ) ;
if ( V_4 == NULL ) {
V_4 = F_44 ( V_2 ) ;
V_12 = - V_270 ;
if ( V_4 == NULL )
goto V_26;
}
V_12 = V_239 -> V_271 ( V_2 , V_4 ) ;
F_17 ( V_4 ) ;
if ( V_12 == - V_272 ) {
F_5 ( V_205 , & V_2 -> V_18 ) ;
return 0 ;
}
V_26:
return F_192 ( V_2 , V_12 ) ;
}
static int F_195 ( struct V_1 * V_2 , int V_12 )
{
switch ( V_12 ) {
case - V_265 :
if ( F_142 ( V_273 , & V_2 -> V_18 ) )
return - V_274 ;
F_177 ( 1 ) ;
F_7 ( V_17 , & V_2 -> V_18 ) ;
break;
case - V_184 :
F_7 ( V_17 , & V_2 -> V_18 ) ;
F_187 ( V_2 ) ;
F_183 ( V_2 ) ;
break;
case - V_275 :
F_154 ( L_21 ,
V_2 -> V_206 ) ;
F_41 ( V_2 , - V_276 ) ;
F_7 ( V_17 , & V_2 -> V_18 ) ;
return - V_276 ;
case - V_277 :
case - V_278 :
case - V_272 :
case - V_97 :
F_177 ( 1 ) ;
break;
case - V_279 :
if ( V_2 -> V_221 == V_280 )
F_41 ( V_2 , - V_281 ) ;
F_152 ( L_22 ,
V_203 , - V_281 , V_2 -> V_206 ) ;
return - V_281 ;
case - V_282 :
default:
F_152 ( L_22 , V_203 ,
V_12 , V_2 -> V_206 ) ;
return V_12 ;
}
F_5 ( V_204 , & V_2 -> V_18 ) ;
F_152 ( L_20 , V_203 , V_12 ,
V_2 -> V_206 ) ;
return 0 ;
}
static int F_196 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
const struct V_238 * V_239 =
V_2 -> V_149 -> V_261 ;
int V_12 ;
V_4 = F_44 ( V_2 ) ;
if ( V_4 == NULL )
return - V_166 ;
V_12 = V_239 -> V_283 ( V_2 , V_4 ) ;
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
if ( F_28 ( V_284 , & V_2 -> V_18 ) )
F_191 ( V_2 ) ;
if ( ! F_3 ( V_230 , & V_2 -> V_18 ) )
F_5 ( V_228 , & V_2 -> V_18 ) ;
F_7 ( V_205 , & V_2 -> V_18 ) ;
F_7 ( V_204 , & V_2 -> V_18 ) ;
return 0 ;
}
static int F_199 ( struct V_1 * V_2 )
{
int V_12 ;
V_12 = F_196 ( V_2 ) ;
if ( V_12 < 0 )
return F_195 ( V_2 , V_12 ) ;
F_7 ( V_273 , & V_2 -> V_18 ) ;
F_5 ( V_204 , & V_2 -> V_18 ) ;
F_191 ( V_2 ) ;
return 0 ;
}
static int F_200 ( struct V_31 * V_32 , struct V_3 * V_4 )
{
struct V_1 * V_2 = V_32 -> V_1 ;
struct V_285 * V_286 = NULL ;
struct V_110 * V_110 ;
struct V_287 * V_287 ;
int V_12 , V_27 ;
F_152 ( L_23 , V_203 ,
( unsigned long long ) V_32 -> V_212 . V_213 ,
( unsigned long long ) V_32 -> V_212 . V_214 ,
V_2 -> V_206 ) ;
V_27 = 0 ;
V_287 = F_201 ( V_126 ) ;
V_286 = F_123 ( sizeof( struct V_285 ) , V_126 ) ;
if ( V_287 == NULL || V_286 == NULL ) {
F_152 ( L_24 , V_203 ) ;
goto V_26;
}
V_110 = V_32 -> V_288 -> V_289 -> V_290 ;
V_27 = F_202 ( V_110 , V_286 , V_287 , V_4 ) ;
if ( V_27 ) {
F_152 ( L_25 ,
V_203 , V_27 ) ;
goto V_26;
}
V_27 = - V_291 ;
if ( ! ( V_286 -> V_292 . V_293 & V_294 ) ) {
F_152 ( L_26 ,
V_203 ) ;
goto V_26;
}
F_34 ( V_2 ) ;
V_12 = F_203 ( V_32 , V_286 ) ;
if ( V_12 != 0 ) {
F_152 ( L_27 ,
V_203 , V_12 ) ;
goto V_26;
}
V_27 = 0 ;
F_152 ( L_28 , V_203 ) ;
V_26:
if ( V_287 != NULL )
F_204 ( V_287 ) ;
F_72 ( V_286 ) ;
if ( V_27 ) {
F_154 ( L_29 ,
V_2 -> V_206 ) ;
F_5 ( V_210 , & V_32 -> V_211 ) ;
}
return V_27 ;
}
static int F_205 ( struct V_1 * V_2 )
{
const struct V_267 * V_239 =
V_2 -> V_149 -> V_268 ;
struct V_31 * V_32 ;
struct V_3 * V_4 ;
F_152 ( L_30 , V_203 ,
V_2 -> V_206 ) ;
F_15 ( & V_2 -> V_30 ) ;
V_4 = V_239 -> V_269 ( V_2 ) ;
F_16 ( & V_2 -> V_30 ) ;
if ( V_4 == NULL )
return - V_295 ;
V_2 -> V_296 ++ ;
V_256:
F_24 () ;
F_25 (server, &clp->cl_superblocks, client_link) {
int V_12 ;
if ( V_32 -> V_297 == V_2 -> V_296 )
continue;
V_32 -> V_297 = V_2 -> V_296 ;
if ( ! F_28 ( V_215 ,
& V_32 -> V_211 ) )
continue;
F_26 () ;
V_12 = F_200 ( V_32 , V_4 ) ;
if ( V_12 < 0 ) {
F_17 ( V_4 ) ;
return V_12 ;
}
goto V_256;
}
F_26 () ;
F_17 ( V_4 ) ;
return 0 ;
}
static int F_206 ( struct V_1 * V_2 )
{
const struct V_267 * V_239 =
V_2 -> V_149 -> V_268 ;
struct V_31 * V_32 ;
struct V_3 * V_4 ;
F_152 ( L_31 , V_203 ,
V_2 -> V_206 ) ;
F_15 ( & V_2 -> V_30 ) ;
V_4 = V_239 -> V_269 ( V_2 ) ;
F_16 ( & V_2 -> V_30 ) ;
if ( V_4 == NULL )
return - V_295 ;
V_2 -> V_296 ++ ;
V_256:
F_24 () ;
F_25 (server, &clp->cl_superblocks, client_link) {
struct V_110 * V_110 ;
int V_12 ;
if ( V_32 -> V_297 == V_2 -> V_296 )
continue;
V_32 -> V_297 = V_2 -> V_296 ;
F_26 () ;
V_110 = V_32 -> V_288 -> V_289 -> V_290 ;
V_12 = F_207 ( V_110 , V_4 ) ;
if ( V_12 != - V_298 )
goto V_256;
if ( F_200 ( V_32 , V_4 ) == - V_299 )
goto V_256;
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
const struct V_238 * V_239 =
V_2 -> V_149 -> V_261 ;
struct V_300 * V_301 ;
struct V_3 * V_4 ;
int V_302 , V_12 ;
F_152 ( L_32 , V_203 , V_2 -> V_206 ) ;
V_301 = V_2 -> V_199 ;
V_302 = 0 ;
F_209 ( & V_303 ) ;
V_304:
V_12 = - V_166 ;
V_4 = F_44 ( V_2 ) ;
if ( V_4 == NULL )
goto V_305;
V_12 = V_239 -> V_306 ( V_2 , V_27 , V_4 ) ;
F_17 ( V_4 ) ;
switch ( V_12 ) {
case 0 :
break;
case - V_278 :
case - V_272 :
case - V_97 :
F_177 ( 1 ) ;
case - V_184 :
F_152 ( L_33 ,
V_203 , V_12 ) ;
goto V_304;
case - V_277 :
if ( V_302 ++ == 0 ) {
F_13 ( V_2 ) ;
goto V_304;
}
if ( V_301 -> V_307 -> V_308 == V_309 )
break;
case - V_275 :
case - V_310 :
if ( V_301 -> V_307 -> V_308 == V_309 ) {
V_12 = - V_276 ;
break;
}
V_301 = F_210 ( V_301 , V_309 ) ;
if ( F_146 ( V_301 ) ) {
V_12 = F_148 ( V_301 ) ;
break;
}
V_301 = F_211 ( & V_2 -> V_199 , V_301 ) ;
F_212 ( V_301 ) ;
V_301 = V_2 -> V_199 ;
goto V_304;
case - V_279 :
V_12 = - V_281 ;
break;
case - V_311 :
case - V_282 :
V_12 = - V_311 ;
break;
default:
F_213 ( L_34 ,
V_203 , V_12 ) ;
V_12 = - V_170 ;
}
V_305:
F_214 ( & V_303 ) ;
F_152 ( L_35 , V_203 , V_12 ) ;
return V_12 ;
}
void F_215 ( struct V_46 * V_312 , int V_76 )
{
struct V_1 * V_2 = V_312 -> V_2 ;
switch ( V_76 ) {
default:
F_5 ( V_65 , & V_2 -> V_18 ) ;
break;
case - V_252 :
F_5 ( V_66 , & V_2 -> V_18 ) ;
}
F_151 ( V_2 ) ;
}
static void F_216 ( struct V_1 * V_2 )
{
F_5 ( V_205 , & V_2 -> V_18 ) ;
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
if ( F_142 ( V_204 , & V_2 -> V_18 ) == 0 ) {
F_5 ( V_273 , & V_2 -> V_18 ) ;
F_7 ( V_17 , & V_2 -> V_18 ) ;
F_191 ( V_2 ) ;
F_152 ( L_36 ,
V_203 , V_2 -> V_206 ) ;
F_141 ( V_2 ) ;
}
}
static void F_220 ( struct V_1 * V_2 )
{
if ( F_142 ( V_204 , & V_2 -> V_18 ) == 0 ) {
F_183 ( V_2 ) ;
F_152 ( L_37 , V_203 ,
V_2 -> V_206 ) ;
F_141 ( V_2 ) ;
}
}
static void F_221 ( struct V_1 * V_2 )
{
F_219 ( V_2 ) ;
F_152 ( L_38 , V_203 , V_2 -> V_206 ) ;
}
static void F_222 ( struct V_1 * V_2 )
{
F_161 ( V_2 ) ;
F_152 ( L_39 , V_203 ,
V_2 -> V_206 ) ;
}
static void F_223 ( struct V_1 * V_2 )
{
F_161 ( V_2 ) ;
if ( F_142 ( V_65 , & V_2 -> V_18 ) == 0 )
F_141 ( V_2 ) ;
F_152 ( L_40 , V_203 ,
V_2 -> V_206 ) ;
}
static void F_224 ( struct V_1 * V_2 )
{
if ( F_142 ( V_66 ,
& V_2 -> V_18 ) == 0 )
F_141 ( V_2 ) ;
}
void F_225 ( struct V_1 * V_2 , T_6 V_83 )
{
if ( ! V_83 )
return;
F_152 ( L_41 ,
V_203 , V_2 -> V_206 , V_2 -> V_8 , V_83 ) ;
if ( V_83 & V_313 )
F_220 ( V_2 ) ;
if ( V_83 & ( V_314 |
V_315 |
V_316 ) )
F_221 ( V_2 ) ;
if ( V_83 & V_317 )
F_155 ( V_2 ) ;
if ( V_83 & V_318 )
F_222 ( V_2 ) ;
if ( V_83 & V_319 )
F_223 ( V_2 ) ;
else if ( V_83 & ( V_320 |
V_321 ) )
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
case - V_249 :
case - V_263 :
break;
case - V_322 :
case - V_278 :
F_5 ( V_65 , & V_2 -> V_18 ) ;
V_12 = 0 ;
F_177 ( 1 ) ;
goto V_26;
default:
V_12 = F_192 ( V_2 , V_12 ) ;
goto V_26;
}
memset ( V_2 -> V_48 -> V_323 . V_324 , 0 , V_325 ) ;
V_12 = F_40 ( V_2 , V_4 ) ;
if ( V_12 ) {
F_152 ( L_42 ,
V_203 , V_12 , V_2 -> V_206 ) ;
V_12 = F_195 ( V_2 , V_12 ) ;
goto V_26;
}
F_37 ( V_2 ) ;
F_152 ( L_43 ,
V_203 , V_2 -> V_206 ) ;
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
V_203 , V_2 -> V_206 ) ;
break;
case - V_278 :
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
const char * V_326 = L_45 , * V_327 = L_45 ;
do {
if ( F_3 ( V_273 , & V_2 -> V_18 ) ) {
V_326 = L_46 ;
V_12 = F_199 ( V_2 ) ;
if ( V_12 < 0 )
goto V_328;
continue;
}
if ( F_3 ( V_204 , & V_2 -> V_18 ) ) {
V_326 = L_47 ;
V_12 = F_198 ( V_2 ) ;
if ( V_12 < 0 )
goto V_328;
continue;
}
if ( F_28 ( V_65 , & V_2 -> V_18 ) ) {
V_326 = L_48 ;
V_12 = F_226 ( V_2 ) ;
if ( F_3 ( V_204 , & V_2 -> V_18 ) )
continue;
if ( V_12 < 0 )
goto V_328;
}
if ( F_28 ( V_66 ,
& V_2 -> V_18 ) ) {
V_326 = L_49 ;
V_12 = F_228 ( V_2 ) ;
if ( V_12 < 0 )
goto V_328;
continue;
}
if ( F_28 ( V_205 , & V_2 -> V_18 ) ) {
V_326 = L_50 ;
V_12 = F_194 ( V_2 ) ;
if ( V_12 < 0 )
goto V_328;
}
if ( F_28 ( V_216 , & V_2 -> V_18 ) ) {
V_326 = L_51 ;
V_12 = F_205 ( V_2 ) ;
if ( V_12 < 0 )
goto V_328;
}
if ( F_28 ( V_217 , & V_2 -> V_18 ) ) {
V_326 = L_52 ;
V_12 = F_206 ( V_2 ) ;
if ( V_12 < 0 )
goto V_328;
}
if ( F_3 ( V_228 , & V_2 -> V_18 ) ) {
V_326 = L_53 ;
V_12 = F_193 ( V_2 ,
V_2 -> V_149 -> V_261 ) ;
if ( F_3 ( V_204 , & V_2 -> V_18 ) ||
F_3 ( V_65 , & V_2 -> V_18 ) )
continue;
F_189 ( V_2 ) ;
if ( F_3 ( V_230 , & V_2 -> V_18 ) )
continue;
if ( V_12 < 0 )
goto V_328;
}
if ( F_28 ( V_230 , & V_2 -> V_18 ) ) {
V_326 = L_54 ;
V_12 = F_193 ( V_2 ,
V_2 -> V_149 -> V_329 ) ;
if ( F_3 ( V_204 , & V_2 -> V_18 ) ||
F_3 ( V_65 , & V_2 -> V_18 ) ||
F_3 ( V_228 , & V_2 -> V_18 ) )
continue;
if ( V_12 < 0 )
goto V_328;
}
F_30 ( V_2 ) ;
if ( F_28 ( V_330 , & V_2 -> V_18 ) ) {
F_231 ( V_2 ) ;
continue;
}
F_136 ( V_2 ) ;
if ( V_2 -> V_18 == 0 )
break;
if ( F_142 ( V_192 , & V_2 -> V_18 ) != 0 )
break;
} while ( F_232 ( & V_2 -> V_198 ) > 1 );
return;
V_328:
if ( strlen ( V_326 ) )
V_327 = L_55 ;
F_129 ( L_56
L_57 , V_327 , V_326 ,
V_2 -> V_206 , - V_12 ) ;
F_177 ( 1 ) ;
F_30 ( V_2 ) ;
F_136 ( V_2 ) ;
}
static int V_201 ( void * V_331 )
{
struct V_1 * V_2 = V_331 ;
F_233 ( V_332 ) ;
F_230 ( V_2 ) ;
F_149 ( V_2 ) ;
F_234 ( 0 ) ;
return 0 ;
}
