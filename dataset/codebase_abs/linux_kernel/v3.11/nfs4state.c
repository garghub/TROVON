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
static struct V_3 *
F_13 ( struct V_29 * V_30 )
{
struct V_3 * V_4 = NULL ;
struct V_31 * V_32 ;
struct V_33 * V_34 ;
for ( V_34 = F_14 ( & V_30 -> V_35 ) ;
V_34 != NULL ;
V_34 = F_15 ( V_34 ) ) {
V_32 = F_16 ( V_34 , struct V_31 , V_36 ) ;
if ( F_17 ( & V_32 -> V_37 ) )
continue;
V_4 = F_12 ( V_32 -> V_38 ) ;
break;
}
return V_4 ;
}
struct V_3 * F_18 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = NULL ;
struct V_29 * V_30 ;
V_4 = F_11 ( V_2 ) ;
if ( V_4 != NULL )
goto V_26;
F_19 () ;
F_20 (server, &clp->cl_superblocks, client_link) {
V_4 = F_13 ( V_30 ) ;
if ( V_4 != NULL )
break;
}
F_21 () ;
V_26:
return V_4 ;
}
static int F_22 ( struct V_1 * V_2 )
{
int V_12 ;
struct V_39 V_40 ;
if ( ! F_3 ( V_41 , & V_2 -> V_42 ) ) {
F_8 ( V_2 ) ;
return 0 ;
}
V_12 = F_23 ( V_2 , & V_40 ) ;
if ( V_12 == 0 ) {
F_24 ( & V_2 -> V_43 ) ;
V_2 -> V_44 = V_40 . V_45 * V_46 ;
V_2 -> V_47 = V_48 ;
F_25 ( & V_2 -> V_43 ) ;
F_8 ( V_2 ) ;
}
return V_12 ;
}
static void F_26 ( struct V_49 * V_50 )
{
if ( F_27 ( V_51 , & V_50 -> V_52 ) ) {
F_24 ( & V_50 -> V_53 ) ;
F_28 ( V_50 ) ;
F_25 ( & V_50 -> V_53 ) ;
}
}
static void F_29 ( struct V_1 * V_2 )
{
struct V_54 * V_55 = V_2 -> V_56 ;
if ( V_55 != NULL ) {
F_26 ( & V_55 -> V_57 ) ;
F_26 ( & V_55 -> V_58 ) ;
}
}
void F_30 ( struct V_49 * V_50 )
{
if ( F_31 ( V_50 ) )
F_32 ( & V_50 -> F_32 ) ;
}
static int F_33 ( struct V_49 * V_50 )
{
F_5 ( V_51 , & V_50 -> V_52 ) ;
F_24 ( & V_50 -> V_53 ) ;
if ( V_50 -> V_59 != V_60 ) {
F_34 ( V_50 -> F_32 ) ;
F_25 ( & V_50 -> V_53 ) ;
return F_35 ( & V_50 -> F_32 ) ;
}
F_25 ( & V_50 -> V_53 ) ;
return 0 ;
}
static int F_36 ( struct V_1 * V_2 )
{
struct V_54 * V_55 = V_2 -> V_56 ;
int V_61 = 0 ;
V_61 = F_33 ( & V_55 -> V_57 ) ;
if ( V_61 )
return V_61 ;
return F_33 ( & V_55 -> V_58 ) ;
}
static void F_37 ( struct V_1 * V_2 )
{
F_7 ( V_17 , & V_2 -> V_18 ) ;
F_7 ( V_62 , & V_2 -> V_18 ) ;
F_7 ( V_63 , & V_2 -> V_18 ) ;
F_22 ( V_2 ) ;
}
int F_38 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
int V_12 ;
if ( F_3 ( V_17 , & V_2 -> V_18 ) )
goto V_19;
F_36 ( V_2 ) ;
V_12 = F_39 ( V_2 , V_4 ) ;
if ( V_12 != 0 )
goto V_26;
F_5 ( V_17 , & V_2 -> V_18 ) ;
V_19:
V_12 = F_40 ( V_2 , V_4 ) ;
if ( V_12 != 0 )
goto V_26;
F_37 ( V_2 ) ;
F_41 ( V_2 , V_64 ) ;
V_26:
return V_12 ;
}
int F_42 ( struct V_1 * V_2 ,
struct V_1 * * V_27 ,
struct V_3 * V_4 )
{
int V_12 ;
V_12 = F_39 ( V_2 , V_4 ) ;
if ( V_12 != V_65 )
return V_12 ;
F_5 ( V_17 , & V_2 -> V_18 ) ;
return F_43 ( V_2 , V_27 , V_4 ) ;
}
struct V_3 * F_44 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
F_24 ( & V_2 -> V_43 ) ;
V_4 = F_11 ( V_2 ) ;
F_25 ( & V_2 -> V_43 ) ;
return V_4 ;
}
static struct V_3 *
F_45 ( struct V_29 * V_30 )
{
struct V_1 * V_2 = V_30 -> V_1 ;
struct V_3 * V_4 = NULL ;
struct V_31 * V_32 ;
struct V_33 * V_34 ;
F_24 ( & V_2 -> V_43 ) ;
V_34 = F_14 ( & V_30 -> V_35 ) ;
if ( V_34 != NULL ) {
V_32 = F_16 ( V_34 , struct V_31 , V_36 ) ;
V_4 = F_12 ( V_32 -> V_38 ) ;
}
F_25 ( & V_2 -> V_43 ) ;
return V_4 ;
}
struct V_3 * F_46 ( struct V_1 * V_2 )
{
struct V_29 * V_30 ;
struct V_3 * V_4 ;
F_24 ( & V_2 -> V_43 ) ;
V_4 = F_11 ( V_2 ) ;
F_25 ( & V_2 -> V_43 ) ;
if ( V_4 != NULL )
goto V_26;
F_19 () ;
F_20 (server, &clp->cl_superblocks, client_link) {
V_4 = F_45 ( V_30 ) ;
if ( V_4 != NULL )
break;
}
F_21 () ;
V_26:
return V_4 ;
}
static struct V_31 *
F_47 ( struct V_29 * V_30 , struct V_3 * V_4 )
{
struct V_33 * * V_66 = & V_30 -> V_35 . V_33 ,
* V_67 = NULL ;
struct V_31 * V_32 ;
while ( * V_66 != NULL ) {
V_67 = * V_66 ;
V_32 = F_16 ( V_67 , struct V_31 , V_36 ) ;
if ( V_4 < V_32 -> V_38 )
V_66 = & V_67 -> V_68 ;
else if ( V_4 > V_32 -> V_38 )
V_66 = & V_67 -> V_69 ;
else {
if ( ! F_17 ( & V_32 -> V_70 ) )
F_48 ( & V_32 -> V_70 ) ;
F_49 ( & V_32 -> V_71 ) ;
return V_32 ;
}
}
return NULL ;
}
static struct V_31 *
F_50 ( struct V_31 * V_72 )
{
struct V_29 * V_30 = V_72 -> V_73 ;
struct V_33 * * V_66 = & V_30 -> V_35 . V_33 ,
* V_67 = NULL ;
struct V_31 * V_32 ;
int V_74 ;
while ( * V_66 != NULL ) {
V_67 = * V_66 ;
V_32 = F_16 ( V_67 , struct V_31 , V_36 ) ;
if ( V_72 -> V_38 < V_32 -> V_38 )
V_66 = & V_67 -> V_68 ;
else if ( V_72 -> V_38 > V_32 -> V_38 )
V_66 = & V_67 -> V_69 ;
else {
if ( ! F_17 ( & V_32 -> V_70 ) )
F_48 ( & V_32 -> V_70 ) ;
F_49 ( & V_32 -> V_71 ) ;
return V_32 ;
}
}
V_74 = F_51 ( & V_30 -> V_75 , & V_72 -> V_76 . V_77 ) ;
if ( V_74 )
return F_52 ( V_74 ) ;
F_53 ( & V_72 -> V_36 , V_67 , V_66 ) ;
F_54 ( & V_72 -> V_36 , & V_30 -> V_35 ) ;
return V_72 ;
}
static void
F_55 ( struct V_31 * V_32 )
{
struct V_29 * V_30 = V_32 -> V_73 ;
if ( ! F_56 ( & V_32 -> V_36 ) )
F_57 ( & V_32 -> V_36 , & V_30 -> V_35 ) ;
F_58 ( & V_30 -> V_75 , V_32 -> V_76 . V_77 ) ;
}
static void
F_59 ( struct V_78 * V_79 )
{
V_79 -> V_80 = F_60 () ;
V_79 -> V_81 = 0 ;
V_79 -> V_82 = 0 ;
F_61 ( & V_79 -> V_83 ) ;
F_62 ( & V_79 -> V_84 ) ;
F_63 ( & V_79 -> V_85 , L_1 ) ;
}
static void
F_64 ( struct V_78 * V_79 )
{
F_65 ( & V_79 -> V_85 ) ;
}
static struct V_31 *
F_66 ( struct V_29 * V_30 ,
struct V_3 * V_4 ,
T_1 V_86 )
{
struct V_31 * V_32 ;
V_32 = F_67 ( sizeof( * V_32 ) , V_86 ) ;
if ( ! V_32 )
return NULL ;
V_32 -> V_73 = V_30 ;
V_32 -> V_38 = F_12 ( V_4 ) ;
F_61 ( & V_32 -> V_87 ) ;
F_62 ( & V_32 -> V_37 ) ;
F_59 ( & V_32 -> V_76 ) ;
F_68 ( & V_32 -> V_71 , 1 ) ;
F_62 ( & V_32 -> V_70 ) ;
F_69 ( & V_32 -> V_88 ) ;
F_70 ( & V_32 -> V_89 ) ;
return V_32 ;
}
static void
F_71 ( struct V_31 * V_32 )
{
struct V_33 * V_33 = & V_32 -> V_36 ;
if ( ! F_56 ( V_33 ) ) {
struct V_29 * V_30 = V_32 -> V_73 ;
struct V_1 * V_2 = V_30 -> V_1 ;
F_24 ( & V_2 -> V_43 ) ;
if ( ! F_56 ( V_33 ) ) {
F_57 ( V_33 , & V_30 -> V_35 ) ;
F_72 ( V_33 ) ;
}
F_25 ( & V_2 -> V_43 ) ;
}
}
static void F_73 ( struct V_31 * V_32 )
{
F_64 ( & V_32 -> V_76 ) ;
F_74 ( V_32 -> V_38 ) ;
F_75 ( V_32 ) ;
}
static void F_76 ( struct V_29 * V_30 )
{
struct V_1 * V_2 = V_30 -> V_1 ;
struct V_31 * V_32 , * V_90 ;
unsigned long V_91 , V_92 ;
F_77 ( V_93 ) ;
F_24 ( & V_2 -> V_43 ) ;
V_92 = V_48 ;
V_91 = ( long ) V_92 - ( long ) V_2 -> V_44 ;
F_78 (sp, tmp, &server->state_owners_lru, so_lru) {
if ( F_79 ( V_32 -> V_94 , V_91 , V_92 ) )
break;
F_80 ( & V_32 -> V_70 , & V_93 ) ;
F_55 ( V_32 ) ;
}
F_25 ( & V_2 -> V_43 ) ;
F_78 (sp, tmp, &doomed, so_lru) {
F_81 ( & V_32 -> V_70 ) ;
F_73 ( V_32 ) ;
}
}
struct V_31 * F_82 ( struct V_29 * V_30 ,
struct V_3 * V_4 ,
T_1 V_86 )
{
struct V_1 * V_2 = V_30 -> V_1 ;
struct V_31 * V_32 , * V_72 ;
F_24 ( & V_2 -> V_43 ) ;
V_32 = F_47 ( V_30 , V_4 ) ;
F_25 ( & V_2 -> V_43 ) ;
if ( V_32 != NULL )
goto V_26;
V_72 = F_66 ( V_30 , V_4 , V_86 ) ;
if ( V_72 == NULL )
goto V_26;
do {
if ( F_83 ( & V_30 -> V_75 , V_86 ) == 0 )
break;
F_24 ( & V_2 -> V_43 ) ;
V_32 = F_50 ( V_72 ) ;
F_25 ( & V_2 -> V_43 ) ;
} while ( V_32 == F_52 ( - V_95 ) );
if ( V_32 != V_72 )
F_73 ( V_72 ) ;
V_26:
F_76 ( V_30 ) ;
return V_32 ;
}
void F_84 ( struct V_31 * V_32 )
{
struct V_29 * V_30 = V_32 -> V_73 ;
struct V_1 * V_2 = V_30 -> V_1 ;
if ( ! F_85 ( & V_32 -> V_71 , & V_2 -> V_43 ) )
return;
V_32 -> V_94 = V_48 ;
F_86 ( & V_32 -> V_70 , & V_30 -> V_96 ) ;
F_25 ( & V_2 -> V_43 ) ;
}
void F_87 ( struct V_29 * V_30 )
{
struct V_1 * V_2 = V_30 -> V_1 ;
struct V_31 * V_32 , * V_90 ;
F_77 ( V_93 ) ;
F_24 ( & V_2 -> V_43 ) ;
F_78 (sp, tmp, &server->state_owners_lru, so_lru) {
F_80 ( & V_32 -> V_70 , & V_93 ) ;
F_55 ( V_32 ) ;
}
F_25 ( & V_2 -> V_43 ) ;
F_78 (sp, tmp, &doomed, so_lru) {
F_81 ( & V_32 -> V_70 ) ;
F_73 ( V_32 ) ;
}
}
static struct V_97 *
F_88 ( void )
{
struct V_97 * V_98 ;
V_98 = F_67 ( sizeof( * V_98 ) , V_99 ) ;
if ( ! V_98 )
return NULL ;
F_68 ( & V_98 -> V_100 , 1 ) ;
F_62 ( & V_98 -> V_101 ) ;
F_61 ( & V_98 -> V_102 ) ;
F_89 ( & V_98 -> V_103 ) ;
return V_98 ;
}
void
F_90 ( struct V_97 * V_98 , T_2 V_104 )
{
if ( V_98 -> V_98 == V_104 )
return;
if ( ( V_104 & V_105 ) != ( V_98 -> V_98 & V_105 ) ) {
if ( V_104 & V_105 )
F_80 ( & V_98 -> V_106 , & V_98 -> V_107 -> V_37 ) ;
else
F_91 ( & V_98 -> V_106 , & V_98 -> V_107 -> V_37 ) ;
}
V_98 -> V_98 = V_104 ;
}
static struct V_97 *
F_92 ( struct V_108 * V_108 , struct V_31 * V_107 )
{
struct V_109 * V_110 = F_93 ( V_108 ) ;
struct V_97 * V_98 ;
F_94 (state, &nfsi->open_states, inode_states) {
if ( V_98 -> V_107 != V_107 )
continue;
if ( ! F_95 ( V_98 ) )
continue;
if ( F_96 ( & V_98 -> V_100 ) )
return V_98 ;
}
return NULL ;
}
static void
F_97 ( struct V_97 * V_98 )
{
F_75 ( V_98 ) ;
}
struct V_97 *
F_98 ( struct V_108 * V_108 , struct V_31 * V_107 )
{
struct V_97 * V_98 , * V_72 ;
struct V_109 * V_110 = F_93 ( V_108 ) ;
F_24 ( & V_108 -> V_111 ) ;
V_98 = F_92 ( V_108 , V_107 ) ;
F_25 ( & V_108 -> V_111 ) ;
if ( V_98 )
goto V_26;
V_72 = F_88 () ;
F_24 ( & V_107 -> V_87 ) ;
F_24 ( & V_108 -> V_111 ) ;
V_98 = F_92 ( V_108 , V_107 ) ;
if ( V_98 == NULL && V_72 != NULL ) {
V_98 = V_72 ;
V_98 -> V_107 = V_107 ;
F_49 ( & V_107 -> V_71 ) ;
F_99 ( & V_98 -> V_112 , & V_110 -> V_106 ) ;
F_100 ( V_108 ) ;
V_98 -> V_108 = V_108 ;
F_25 ( & V_108 -> V_111 ) ;
F_86 ( & V_98 -> V_106 , & V_107 -> V_37 ) ;
F_25 ( & V_107 -> V_87 ) ;
} else {
F_25 ( & V_108 -> V_111 ) ;
F_25 ( & V_107 -> V_87 ) ;
if ( V_72 )
F_97 ( V_72 ) ;
}
V_26:
return V_98 ;
}
void F_101 ( struct V_97 * V_98 )
{
struct V_108 * V_108 = V_98 -> V_108 ;
struct V_31 * V_107 = V_98 -> V_107 ;
if ( ! F_85 ( & V_98 -> V_100 , & V_107 -> V_87 ) )
return;
F_24 ( & V_108 -> V_111 ) ;
F_81 ( & V_98 -> V_112 ) ;
F_81 ( & V_98 -> V_106 ) ;
F_25 ( & V_108 -> V_111 ) ;
F_25 ( & V_107 -> V_87 ) ;
F_102 ( V_108 ) ;
F_97 ( V_98 ) ;
F_84 ( V_107 ) ;
}
static void F_103 ( struct V_97 * V_98 ,
T_2 V_104 , T_1 V_113 , int V_85 )
{
struct V_31 * V_107 = V_98 -> V_107 ;
int V_114 = 0 ;
T_2 V_115 ;
F_49 ( & V_107 -> V_71 ) ;
F_24 ( & V_107 -> V_87 ) ;
switch ( V_104 & ( V_116 | V_105 ) ) {
case V_116 :
V_98 -> V_117 -- ;
break;
case V_105 :
V_98 -> V_118 -- ;
break;
case V_116 | V_105 :
V_98 -> V_119 -- ;
}
V_115 = V_116 | V_105 ;
if ( V_98 -> V_119 == 0 ) {
if ( V_98 -> V_117 == 0 ) {
V_115 &= ~ V_116 ;
V_114 |= F_3 ( V_120 , & V_98 -> V_81 ) ;
V_114 |= F_3 ( V_121 , & V_98 -> V_81 ) ;
}
if ( V_98 -> V_118 == 0 ) {
V_115 &= ~ V_105 ;
V_114 |= F_3 ( V_122 , & V_98 -> V_81 ) ;
V_114 |= F_3 ( V_121 , & V_98 -> V_81 ) ;
}
if ( V_115 == 0 )
F_7 ( V_123 , & V_98 -> V_81 ) ;
}
F_90 ( V_98 , V_115 ) ;
F_25 ( & V_107 -> V_87 ) ;
if ( ! V_114 ) {
F_101 ( V_98 ) ;
F_84 ( V_107 ) ;
} else
F_104 ( V_98 , V_113 , V_85 ) ;
}
void F_105 ( struct V_97 * V_98 , T_2 V_104 )
{
F_103 ( V_98 , V_104 , V_99 , 0 ) ;
}
void F_106 ( struct V_97 * V_98 , T_2 V_104 )
{
F_103 ( V_98 , V_104 , V_124 , 1 ) ;
}
static struct V_125 *
F_107 ( struct V_97 * V_98 , T_3 V_126 , T_4 V_127 , unsigned int type )
{
struct V_125 * V_34 ;
F_94 (pos, &state->lock_states, ls_locks) {
if ( type != V_128 && V_34 -> V_129 . V_130 != type )
continue;
switch ( V_34 -> V_129 . V_130 ) {
case V_131 :
if ( V_34 -> V_129 . V_132 . V_133 != V_126 )
continue;
break;
case V_134 :
if ( V_34 -> V_129 . V_132 . V_135 != V_127 )
continue;
}
F_49 ( & V_34 -> V_136 ) ;
return V_34 ;
}
return NULL ;
}
static struct V_125 * F_108 ( struct V_97 * V_98 , T_3 V_126 , T_4 V_127 , unsigned int type )
{
struct V_125 * V_137 ;
struct V_29 * V_30 = V_98 -> V_107 -> V_73 ;
V_137 = F_67 ( sizeof( * V_137 ) , V_99 ) ;
if ( V_137 == NULL )
return NULL ;
F_59 ( & V_137 -> V_138 ) ;
F_68 ( & V_137 -> V_136 , 1 ) ;
V_137 -> V_139 = V_98 ;
V_137 -> V_129 . V_130 = type ;
switch ( V_137 -> V_129 . V_130 ) {
case V_134 :
V_137 -> V_129 . V_132 . V_135 = V_127 ;
break;
case V_131 :
V_137 -> V_129 . V_132 . V_133 = V_126 ;
break;
default:
goto V_140;
}
V_137 -> V_138 . V_77 = F_109 ( & V_30 -> V_141 , 0 , 0 , V_99 ) ;
if ( V_137 -> V_138 . V_77 < 0 )
goto V_140;
F_62 ( & V_137 -> V_142 ) ;
return V_137 ;
V_140:
F_75 ( V_137 ) ;
return NULL ;
}
void F_110 ( struct V_29 * V_30 , struct V_125 * V_137 )
{
F_111 ( & V_30 -> V_141 , V_137 -> V_138 . V_77 ) ;
F_64 ( & V_137 -> V_138 ) ;
F_75 ( V_137 ) ;
}
static struct V_125 * F_112 ( struct V_97 * V_98 , T_3 V_107 , T_4 V_143 , unsigned int type )
{
struct V_125 * V_137 , * V_72 = NULL ;
for(; ; ) {
F_24 ( & V_98 -> V_102 ) ;
V_137 = F_107 ( V_98 , V_107 , V_143 , type ) ;
if ( V_137 != NULL )
break;
if ( V_72 != NULL ) {
F_99 ( & V_72 -> V_142 , & V_98 -> V_101 ) ;
F_5 ( V_144 , & V_98 -> V_81 ) ;
V_137 = V_72 ;
V_72 = NULL ;
break;
}
F_25 ( & V_98 -> V_102 ) ;
V_72 = F_108 ( V_98 , V_107 , V_143 , type ) ;
if ( V_72 == NULL )
return NULL ;
}
F_25 ( & V_98 -> V_102 ) ;
if ( V_72 != NULL )
F_110 ( V_98 -> V_107 -> V_73 , V_72 ) ;
return V_137 ;
}
void F_113 ( struct V_125 * V_137 )
{
struct V_29 * V_30 ;
struct V_97 * V_98 ;
if ( V_137 == NULL )
return;
V_98 = V_137 -> V_139 ;
if ( ! F_85 ( & V_137 -> V_136 , & V_98 -> V_102 ) )
return;
F_81 ( & V_137 -> V_142 ) ;
if ( F_17 ( & V_98 -> V_101 ) )
F_7 ( V_144 , & V_98 -> V_81 ) ;
F_25 ( & V_98 -> V_102 ) ;
V_30 = V_98 -> V_107 -> V_73 ;
if ( F_3 ( V_145 , & V_137 -> V_146 ) ) {
struct V_1 * V_2 = V_30 -> V_1 ;
V_2 -> V_147 -> V_148 ( V_30 , V_137 ) ;
} else
F_110 ( V_30 , V_137 ) ;
}
static void F_114 ( struct V_149 * V_150 , struct V_149 * V_151 )
{
struct V_125 * V_137 = V_151 -> V_152 . V_153 . V_107 ;
V_150 -> V_152 . V_153 . V_107 = V_137 ;
F_49 ( & V_137 -> V_136 ) ;
}
static void F_115 ( struct V_149 * V_154 )
{
F_113 ( V_154 -> V_152 . V_153 . V_107 ) ;
}
int F_116 ( struct V_97 * V_98 , struct V_149 * V_154 )
{
struct V_125 * V_137 ;
if ( V_154 -> V_155 != NULL )
return 0 ;
if ( V_154 -> V_156 & V_157 )
V_137 = F_112 ( V_98 , V_154 -> V_126 , 0 , V_131 ) ;
else if ( V_154 -> V_156 & V_158 )
V_137 = F_112 ( V_98 , NULL , V_154 -> V_127 ,
V_134 ) ;
else
return - V_159 ;
if ( V_137 == NULL )
return - V_160 ;
V_154 -> V_152 . V_153 . V_107 = V_137 ;
V_154 -> V_155 = & V_161 ;
return 0 ;
}
static int F_117 ( T_5 * V_150 ,
struct V_97 * V_98 ,
const struct V_162 * V_163 )
{
struct V_125 * V_137 ;
T_3 V_126 ;
T_4 V_127 ;
int V_61 = - V_164 ;
if ( V_163 == NULL )
goto V_26;
if ( F_3 ( V_144 , & V_98 -> V_81 ) == 0 )
goto V_26;
V_126 = V_163 -> V_165 ;
V_127 = V_163 -> V_166 ;
F_24 ( & V_98 -> V_102 ) ;
V_137 = F_107 ( V_98 , V_126 , V_127 , V_128 ) ;
if ( V_137 != NULL && F_3 ( V_145 , & V_137 -> V_146 ) != 0 ) {
F_118 ( V_150 , & V_137 -> V_167 ) ;
V_61 = 0 ;
F_119 () ;
if ( ! F_17 ( & V_137 -> V_138 . V_84 ) )
V_61 = - V_168 ;
}
F_25 ( & V_98 -> V_102 ) ;
F_113 ( V_137 ) ;
V_26:
return V_61 ;
}
static int F_120 ( T_5 * V_150 , struct V_97 * V_98 )
{
const T_5 * V_151 ;
int V_61 ;
int V_169 ;
do {
V_151 = & V_170 ;
V_169 = F_121 ( & V_98 -> V_103 ) ;
if ( F_3 ( V_171 , & V_98 -> V_81 ) )
V_151 = & V_98 -> V_172 ;
F_118 ( V_150 , V_151 ) ;
V_61 = 0 ;
F_119 () ;
if ( ! F_17 ( & V_98 -> V_107 -> V_76 . V_84 ) )
V_61 = - V_168 ;
} while ( F_122 ( & V_98 -> V_103 , V_169 ) );
return V_61 ;
}
int F_123 ( T_5 * V_150 , struct V_97 * V_98 ,
T_2 V_104 , const struct V_162 * V_163 )
{
int V_61 = 0 ;
if ( F_124 ( V_150 , V_98 -> V_108 , V_104 ) )
goto V_26;
V_61 = F_117 ( V_150 , V_98 , V_163 ) ;
if ( V_61 != - V_164 )
goto V_26;
V_61 = F_120 ( V_150 , V_98 ) ;
V_26:
if ( F_125 ( V_98 -> V_108 , V_173 ) )
V_150 -> V_174 = 0 ;
return V_61 ;
}
struct V_175 * F_126 ( struct V_78 * V_82 , T_1 V_113 )
{
struct V_175 * V_72 ;
V_72 = F_127 ( sizeof( * V_72 ) , V_113 ) ;
if ( V_72 != NULL ) {
V_72 -> V_176 = V_82 ;
F_62 ( & V_72 -> V_84 ) ;
V_72 -> V_177 = NULL ;
}
return V_72 ;
}
void F_128 ( struct V_175 * V_174 )
{
struct V_78 * V_176 ;
if ( F_17 ( & V_174 -> V_84 ) )
return;
V_176 = V_174 -> V_176 ;
F_24 ( & V_176 -> V_83 ) ;
F_48 ( & V_174 -> V_84 ) ;
if ( ! F_17 ( & V_176 -> V_84 ) ) {
struct V_175 * V_178 ;
V_178 = F_129 ( & V_176 -> V_84 ,
struct V_175 , V_84 ) ;
F_130 ( & V_176 -> V_85 , V_178 -> V_177 ) ;
}
F_25 ( & V_176 -> V_83 ) ;
}
void F_131 ( struct V_175 * V_174 )
{
F_128 ( V_174 ) ;
F_75 ( V_174 ) ;
}
static void F_132 ( int V_12 , struct V_175 * V_174 )
{
switch ( V_12 ) {
case 0 :
break;
case - V_179 :
if ( V_174 -> V_176 -> V_81 & V_180 )
return;
F_133 ( L_2
L_3
L_4 ,
V_174 -> V_176 ) ;
case - V_181 :
case - V_182 :
case - V_183 :
case - V_184 :
case - V_185 :
case - V_186 :
return;
} ;
V_174 -> V_176 -> V_82 ++ ;
}
void F_134 ( int V_12 , struct V_175 * V_174 )
{
struct V_31 * V_32 = F_135 ( V_174 -> V_176 ,
struct V_31 , V_76 ) ;
struct V_29 * V_30 = V_32 -> V_73 ;
if ( V_12 == - V_179 )
F_71 ( V_32 ) ;
if ( ! F_136 ( V_30 -> V_1 ) )
F_132 ( V_12 , V_174 ) ;
}
void F_137 ( int V_12 , struct V_175 * V_174 )
{
F_132 ( V_12 , V_174 ) ;
}
int F_138 ( struct V_175 * V_174 , struct V_187 * V_177 )
{
struct V_78 * V_176 = V_174 -> V_176 ;
int V_12 = 0 ;
F_24 ( & V_176 -> V_83 ) ;
V_174 -> V_177 = V_177 ;
if ( F_17 ( & V_174 -> V_84 ) )
F_86 ( & V_174 -> V_84 , & V_176 -> V_84 ) ;
if ( F_129 ( & V_176 -> V_84 , struct V_175 , V_84 ) == V_174 )
goto V_188;
F_139 ( & V_176 -> V_85 , V_177 , NULL ) ;
V_12 = - V_95 ;
V_188:
F_25 ( & V_176 -> V_83 ) ;
return V_12 ;
}
static void F_140 ( struct V_1 * V_2 )
{
F_141 () ;
F_7 ( V_189 , & V_2 -> V_18 ) ;
F_142 () ;
F_143 ( & V_2 -> V_18 , V_189 ) ;
F_144 ( & V_2 -> V_190 ) ;
}
void F_145 ( struct V_1 * V_2 )
{
struct V_191 * V_177 ;
char V_192 [ V_193 + sizeof( L_5 ) + 1 ] ;
if ( F_146 ( V_189 , & V_2 -> V_18 ) != 0 )
return;
F_147 ( V_194 ) ;
F_49 ( & V_2 -> V_195 ) ;
F_19 () ;
snprintf ( V_192 , sizeof( V_192 ) , L_6 ,
F_148 ( V_2 -> V_196 , V_197 ) ) ;
F_21 () ;
V_177 = F_149 ( V_198 , V_2 , L_7 , V_192 ) ;
if ( F_150 ( V_177 ) ) {
F_151 ( V_199 L_8 ,
V_200 , F_152 ( V_177 ) ) ;
F_140 ( V_2 ) ;
F_153 ( V_2 ) ;
F_154 ( V_194 ) ;
}
}
void F_155 ( struct V_1 * V_2 )
{
if ( ! V_2 )
return;
if ( ! F_3 ( V_201 , & V_2 -> V_18 ) )
F_5 ( V_202 , & V_2 -> V_18 ) ;
F_156 ( L_9 , V_200 ,
V_2 -> V_203 ) ;
F_145 ( V_2 ) ;
}
int F_157 ( struct V_1 * V_2 )
{
int V_204 ;
F_158 () ;
V_204 = F_159 ( & V_2 -> V_18 , V_189 ,
V_205 , V_206 ) ;
if ( V_204 )
return V_204 ;
if ( V_2 -> V_207 < 0 )
return V_2 -> V_207 ;
return 0 ;
}
int F_160 ( struct V_1 * V_2 )
{
unsigned int V_208 ;
int V_61 ;
for ( V_208 = V_209 ; V_208 != 0 ; V_208 -- ) {
V_61 = F_157 ( V_2 ) ;
if ( V_61 != 0 )
break;
if ( ! F_3 ( V_201 , & V_2 -> V_18 ) &&
! F_3 ( V_202 , & V_2 -> V_18 ) )
break;
F_145 ( V_2 ) ;
V_61 = - V_210 ;
}
return V_61 ;
}
static void F_161 ( struct V_1 * V_2 )
{
F_5 ( V_201 , & V_2 -> V_18 ) ;
F_162 ( V_2 ) ;
F_156 ( L_10 , V_200 ,
V_2 -> V_203 ) ;
}
void F_163 ( struct V_1 * V_2 )
{
F_161 ( V_2 ) ;
F_145 ( V_2 ) ;
}
static int F_164 ( struct V_1 * V_2 , struct V_97 * V_98 )
{
F_5 ( V_211 , & V_98 -> V_81 ) ;
if ( F_3 ( V_212 , & V_98 -> V_81 ) ) {
F_7 ( V_211 , & V_98 -> V_81 ) ;
return 0 ;
}
F_5 ( V_213 , & V_98 -> V_107 -> V_214 ) ;
F_5 ( V_215 , & V_2 -> V_18 ) ;
return 1 ;
}
static int F_165 ( struct V_1 * V_2 , struct V_97 * V_98 )
{
F_5 ( V_212 , & V_98 -> V_81 ) ;
F_7 ( V_211 , & V_98 -> V_81 ) ;
F_5 ( V_216 , & V_98 -> V_107 -> V_214 ) ;
F_5 ( V_217 , & V_2 -> V_18 ) ;
return 1 ;
}
int F_166 ( const struct V_29 * V_30 , struct V_97 * V_98 )
{
struct V_1 * V_2 = V_30 -> V_1 ;
if ( ! F_95 ( V_98 ) )
return - V_218 ;
F_165 ( V_2 , V_98 ) ;
F_156 ( L_11 , V_200 ,
V_2 -> V_203 ) ;
F_145 ( V_2 ) ;
return 0 ;
}
void F_167 ( struct V_108 * V_108 ,
const T_5 * V_219 )
{
struct V_1 * V_2 = F_168 ( V_108 ) -> V_1 ;
struct V_109 * V_110 = F_93 ( V_108 ) ;
struct V_220 * V_221 ;
struct V_97 * V_98 ;
bool V_222 = false ;
F_24 ( & V_108 -> V_111 ) ;
F_94 (ctx, &nfsi->open_files, list) {
V_98 = V_221 -> V_98 ;
if ( V_98 == NULL )
continue;
if ( ! F_3 ( V_123 , & V_98 -> V_81 ) )
continue;
if ( ! F_169 ( & V_98 -> V_219 , V_219 ) )
continue;
F_165 ( V_2 , V_98 ) ;
V_222 = true ;
}
F_25 ( & V_108 -> V_111 ) ;
if ( V_222 )
F_145 ( V_2 ) ;
}
static void F_170 ( struct V_97 * V_98 )
{
struct V_108 * V_108 = V_98 -> V_108 ;
struct V_109 * V_110 = F_93 ( V_108 ) ;
struct V_220 * V_221 ;
F_24 ( & V_108 -> V_111 ) ;
F_94 (ctx, &nfsi->open_files, list) {
if ( V_221 -> V_98 != V_98 )
continue;
F_5 ( V_223 , & V_221 -> V_81 ) ;
}
F_25 ( & V_108 -> V_111 ) ;
}
static void F_171 ( struct V_97 * V_98 , int error )
{
F_5 ( V_224 , & V_98 -> V_81 ) ;
F_170 ( V_98 ) ;
}
static int F_172 ( struct V_97 * V_98 , const struct V_225 * V_226 )
{
struct V_108 * V_108 = V_98 -> V_108 ;
struct V_109 * V_110 = F_93 ( V_108 ) ;
struct V_149 * V_154 ;
int V_12 = 0 ;
if ( V_108 -> V_227 == NULL )
return 0 ;
F_173 ( & V_110 -> V_228 ) ;
F_24 ( & V_108 -> V_111 ) ;
for ( V_154 = V_108 -> V_227 ; V_154 != NULL ; V_154 = V_154 -> V_229 ) {
if ( ! ( V_154 -> V_156 & ( V_157 | V_158 ) ) )
continue;
if ( F_174 ( V_154 -> V_230 ) -> V_98 != V_98 )
continue;
F_25 ( & V_108 -> V_111 ) ;
V_12 = V_226 -> V_231 ( V_98 , V_154 ) ;
switch ( V_12 ) {
case 0 :
break;
case - V_232 :
case - V_233 :
case - V_182 :
case - V_183 :
case - V_234 :
case - V_235 :
case - V_181 :
case - V_236 :
case - V_237 :
case - V_238 :
case - V_239 :
goto V_26;
default:
F_151 ( V_199 L_12
L_13 , V_200 , V_12 ) ;
case - V_160 :
case - V_240 :
case - V_241 :
case - V_242 :
V_12 = 0 ;
}
F_24 ( & V_108 -> V_111 ) ;
}
F_25 ( & V_108 -> V_111 ) ;
V_26:
F_175 ( & V_110 -> V_228 ) ;
return V_12 ;
}
static int F_176 ( struct V_31 * V_32 , const struct V_225 * V_226 )
{
struct V_97 * V_98 ;
struct V_125 * V_83 ;
int V_12 = 0 ;
F_24 ( & V_32 -> V_87 ) ;
F_177 ( & V_32 -> V_88 ) ;
V_243:
F_94 (state, &sp->so_states, open_states) {
if ( ! F_27 ( V_226 -> V_244 , & V_98 -> V_81 ) )
continue;
if ( ! F_95 ( V_98 ) )
continue;
if ( V_98 -> V_98 == 0 )
continue;
F_49 ( & V_98 -> V_100 ) ;
F_25 ( & V_32 -> V_87 ) ;
V_12 = V_226 -> V_245 ( V_32 , V_98 ) ;
if ( V_12 >= 0 ) {
V_12 = F_172 ( V_98 , V_226 ) ;
if ( V_12 >= 0 ) {
F_24 ( & V_98 -> V_102 ) ;
F_94 (lock, &state->lock_states, ls_locks) {
if ( ! F_3 ( V_145 , & V_83 -> V_146 ) )
F_133 ( L_14
L_15
L_16 , V_200 ) ;
}
F_25 ( & V_98 -> V_102 ) ;
F_101 ( V_98 ) ;
F_24 ( & V_32 -> V_87 ) ;
goto V_243;
}
}
switch ( V_12 ) {
default:
F_151 ( V_199 L_12
L_13 , V_200 , V_12 ) ;
case - V_164 :
case - V_160 :
case - V_232 :
F_171 ( V_98 , V_12 ) ;
break;
case - V_95 :
F_178 ( 1 ) ;
case - V_233 :
case - V_182 :
case - V_183 :
case - V_241 :
case - V_242 :
F_165 ( V_32 -> V_73 -> V_1 , V_98 ) ;
break;
case - V_234 :
case - V_235 :
F_165 ( V_32 -> V_73 -> V_1 , V_98 ) ;
case - V_181 :
case - V_236 :
case - V_237 :
case - V_238 :
case - V_239 :
goto V_246;
}
F_101 ( V_98 ) ;
F_24 ( & V_32 -> V_87 ) ;
goto V_243;
}
F_179 ( & V_32 -> V_88 ) ;
F_25 ( & V_32 -> V_87 ) ;
return 0 ;
V_246:
F_101 ( V_98 ) ;
F_24 ( & V_32 -> V_87 ) ;
F_179 ( & V_32 -> V_88 ) ;
F_25 ( & V_32 -> V_87 ) ;
return V_12 ;
}
static void F_180 ( struct V_97 * V_98 )
{
struct V_125 * V_83 ;
F_7 ( V_123 , & V_98 -> V_81 ) ;
F_7 ( V_120 , & V_98 -> V_81 ) ;
F_7 ( V_122 , & V_98 -> V_81 ) ;
F_7 ( V_121 , & V_98 -> V_81 ) ;
F_24 ( & V_98 -> V_102 ) ;
F_94 (lock, &state->lock_states, ls_locks) {
V_83 -> V_138 . V_81 = 0 ;
F_7 ( V_145 , & V_83 -> V_146 ) ;
}
F_25 ( & V_98 -> V_102 ) ;
}
static void F_181 ( struct V_29 * V_30 ,
int (* F_182)( struct V_1 * V_2 , struct V_97 * V_98 ) )
{
struct V_1 * V_2 = V_30 -> V_1 ;
struct V_31 * V_32 ;
struct V_33 * V_34 ;
struct V_97 * V_98 ;
F_24 ( & V_2 -> V_43 ) ;
for ( V_34 = F_14 ( & V_30 -> V_35 ) ;
V_34 != NULL ;
V_34 = F_15 ( V_34 ) ) {
V_32 = F_16 ( V_34 , struct V_31 , V_36 ) ;
V_32 -> V_76 . V_81 = 0 ;
F_24 ( & V_32 -> V_87 ) ;
F_94 (state, &sp->so_states, open_states) {
if ( F_182 ( V_2 , V_98 ) )
F_180 ( V_98 ) ;
}
F_25 ( & V_32 -> V_87 ) ;
}
F_25 ( & V_2 -> V_43 ) ;
}
static void F_183 ( struct V_1 * V_2 ,
int (* F_182)( struct V_1 * V_2 , struct V_97 * V_98 ) )
{
struct V_29 * V_30 ;
F_19 () ;
F_20 (server, &clp->cl_superblocks, client_link)
F_181 ( V_30 , F_182 ) ;
F_21 () ;
}
static void F_184 ( struct V_1 * V_2 )
{
F_185 ( V_2 ) ;
F_183 ( V_2 , F_164 ) ;
}
static void F_186 ( struct V_1 * V_2 ,
const struct V_225 * V_226 ,
struct V_3 * V_4 )
{
if ( V_226 -> V_247 )
( void ) V_226 -> V_247 ( V_2 , V_4 ) ;
}
static void F_187 ( struct V_29 * V_30 )
{
struct V_1 * V_2 = V_30 -> V_1 ;
struct V_31 * V_32 ;
struct V_33 * V_34 ;
struct V_97 * V_98 ;
F_24 ( & V_2 -> V_43 ) ;
for ( V_34 = F_14 ( & V_30 -> V_35 ) ;
V_34 != NULL ;
V_34 = F_15 ( V_34 ) ) {
V_32 = F_16 ( V_34 , struct V_31 , V_36 ) ;
F_24 ( & V_32 -> V_87 ) ;
F_94 (state, &sp->so_states, open_states) {
if ( ! F_27 ( V_211 ,
& V_98 -> V_81 ) )
continue;
F_165 ( V_2 , V_98 ) ;
}
F_25 ( & V_32 -> V_87 ) ;
}
F_25 ( & V_2 -> V_43 ) ;
}
static int F_188 ( struct V_1 * V_2 )
{
struct V_29 * V_30 ;
if ( ! F_27 ( V_215 , & V_2 -> V_18 ) )
return 0 ;
F_19 () ;
F_20 (server, &clp->cl_superblocks, client_link)
F_187 ( V_30 ) ;
F_21 () ;
F_189 ( V_2 ) ;
return 1 ;
}
static void F_190 ( struct V_1 * V_2 )
{
const struct V_225 * V_226 ;
struct V_3 * V_4 ;
if ( ! F_188 ( V_2 ) )
return;
V_226 = V_2 -> V_147 -> V_248 ;
V_4 = V_226 -> V_249 ( V_2 ) ;
F_186 ( V_2 , V_226 , V_4 ) ;
F_74 ( V_4 ) ;
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
case - V_250 :
F_161 ( V_2 ) ;
break;
case - V_235 :
F_190 ( V_2 ) ;
break;
case - V_181 :
case - V_251 :
F_5 ( V_201 , & V_2 -> V_18 ) ;
F_188 ( V_2 ) ;
F_184 ( V_2 ) ;
break;
case - V_234 :
F_5 ( V_201 , & V_2 -> V_18 ) ;
F_192 ( V_2 ) ;
break;
case - V_236 :
case - V_237 :
case - V_238 :
case - V_252 :
case - V_253 :
case - V_254 :
F_5 ( V_62 , & V_2 -> V_18 ) ;
break;
case - V_239 :
F_5 ( V_63 , & V_2 -> V_18 ) ;
break;
default:
F_156 ( L_17 ,
V_200 , error , V_2 -> V_203 ) ;
return error ;
}
F_156 ( L_18 , V_200 , error ,
V_2 -> V_203 ) ;
return 0 ;
}
static int F_194 ( struct V_1 * V_2 , const struct V_225 * V_226 )
{
struct V_31 * V_32 ;
struct V_29 * V_30 ;
struct V_33 * V_34 ;
int V_12 = 0 ;
V_243:
F_19 () ;
F_20 (server, &clp->cl_superblocks, client_link) {
F_87 ( V_30 ) ;
F_24 ( & V_2 -> V_43 ) ;
for ( V_34 = F_14 ( & V_30 -> V_35 ) ;
V_34 != NULL ;
V_34 = F_15 ( V_34 ) ) {
V_32 = F_16 ( V_34 ,
struct V_31 , V_36 ) ;
if ( ! F_27 ( V_226 -> V_255 ,
& V_32 -> V_214 ) )
continue;
F_49 ( & V_32 -> V_71 ) ;
F_25 ( & V_2 -> V_43 ) ;
F_21 () ;
V_12 = F_176 ( V_32 , V_226 ) ;
if ( V_12 < 0 ) {
F_5 ( V_226 -> V_255 , & V_32 -> V_214 ) ;
F_84 ( V_32 ) ;
return F_193 ( V_2 , V_12 ) ;
}
F_84 ( V_32 ) ;
goto V_243;
}
F_25 ( & V_2 -> V_43 ) ;
}
F_21 () ;
return V_12 ;
}
static int F_195 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
const struct V_256 * V_226 =
V_2 -> V_147 -> V_257 ;
int V_12 ;
if ( F_3 ( V_201 , & V_2 -> V_18 ) )
return 0 ;
F_24 ( & V_2 -> V_43 ) ;
V_4 = V_226 -> V_258 ( V_2 ) ;
F_25 ( & V_2 -> V_43 ) ;
if ( V_4 == NULL ) {
V_4 = F_46 ( V_2 ) ;
V_12 = - V_259 ;
if ( V_4 == NULL )
goto V_26;
}
V_12 = V_226 -> V_260 ( V_2 , V_4 ) ;
F_74 ( V_4 ) ;
if ( V_12 == - V_261 ) {
F_5 ( V_202 , & V_2 -> V_18 ) ;
return 0 ;
}
V_26:
return F_193 ( V_2 , V_12 ) ;
}
static int F_196 ( struct V_1 * V_2 , int V_12 )
{
switch ( V_12 ) {
case - V_254 :
if ( F_146 ( V_262 , & V_2 -> V_18 ) )
return - V_263 ;
F_178 ( 1 ) ;
F_7 ( V_17 , & V_2 -> V_18 ) ;
break;
case - V_181 :
F_7 ( V_17 , & V_2 -> V_18 ) ;
F_188 ( V_2 ) ;
F_184 ( V_2 ) ;
break;
case - V_264 :
F_197 ( L_19 ,
V_2 -> V_203 ) ;
F_41 ( V_2 , - V_265 ) ;
F_7 ( V_17 , & V_2 -> V_18 ) ;
return - V_265 ;
case - V_266 :
case - V_267 :
case - V_261 :
case - V_95 :
F_178 ( 1 ) ;
break;
case - V_268 :
if ( V_2 -> V_207 == V_269 )
F_41 ( V_2 , - V_270 ) ;
F_156 ( L_20 ,
V_200 , - V_270 , V_2 -> V_203 ) ;
return - V_270 ;
case - V_271 :
default:
F_156 ( L_20 , V_200 ,
V_12 , V_2 -> V_203 ) ;
return V_12 ;
}
F_5 ( V_201 , & V_2 -> V_18 ) ;
F_156 ( L_18 , V_200 , V_12 ,
V_2 -> V_203 ) ;
return 0 ;
}
static int F_198 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
const struct V_225 * V_226 =
V_2 -> V_147 -> V_248 ;
int V_12 ;
V_4 = V_226 -> V_249 ( V_2 ) ;
if ( V_4 == NULL )
return - V_164 ;
V_12 = V_226 -> V_272 ( V_2 , V_4 ) ;
F_74 ( V_4 ) ;
if ( V_12 != 0 )
return V_12 ;
F_199 ( V_2 ) ;
return 0 ;
}
static int F_200 ( struct V_1 * V_2 )
{
int V_12 ;
V_12 = F_198 ( V_2 ) ;
if ( V_12 < 0 )
return F_196 ( V_2 , V_12 ) ;
if ( F_27 ( V_273 , & V_2 -> V_18 ) )
F_192 ( V_2 ) ;
if ( ! F_3 ( V_217 , & V_2 -> V_18 ) )
F_5 ( V_215 , & V_2 -> V_18 ) ;
F_7 ( V_202 , & V_2 -> V_18 ) ;
F_7 ( V_201 , & V_2 -> V_18 ) ;
return 0 ;
}
static int F_201 ( struct V_1 * V_2 )
{
int V_12 ;
V_12 = F_198 ( V_2 ) ;
if ( V_12 < 0 )
return F_196 ( V_2 , V_12 ) ;
F_7 ( V_262 , & V_2 -> V_18 ) ;
F_5 ( V_201 , & V_2 -> V_18 ) ;
F_192 ( V_2 ) ;
return 0 ;
}
int F_202 ( struct V_1 * V_2 ,
struct V_1 * * V_27 )
{
const struct V_225 * V_226 =
V_2 -> V_147 -> V_248 ;
struct V_274 * V_275 ;
struct V_3 * V_4 ;
int V_276 , V_12 ;
F_156 ( L_21 , V_200 , V_2 -> V_203 ) ;
V_275 = V_2 -> V_196 ;
V_276 = 0 ;
F_203 ( & V_277 ) ;
V_278:
V_12 = - V_164 ;
V_4 = V_226 -> V_249 ( V_2 ) ;
if ( V_4 == NULL )
goto V_279;
V_12 = V_226 -> V_280 ( V_2 , V_27 , V_4 ) ;
F_74 ( V_4 ) ;
switch ( V_12 ) {
case 0 :
break;
case - V_267 :
case - V_261 :
case - V_95 :
F_178 ( 1 ) ;
case - V_181 :
F_156 ( L_22 ,
V_200 , V_12 ) ;
goto V_278;
case - V_266 :
if ( V_276 ++ )
break;
case - V_264 :
case - V_281 :
V_275 = F_204 ( V_275 , V_282 ) ;
if ( F_150 ( V_275 ) ) {
V_12 = F_152 ( V_275 ) ;
break;
}
V_275 = F_205 ( & V_2 -> V_196 , V_275 ) ;
F_206 ( V_275 ) ;
V_275 = V_2 -> V_196 ;
goto V_278;
case - V_268 :
V_12 = - V_270 ;
break;
case - V_283 :
case - V_271 :
V_12 = - V_283 ;
break;
default:
F_207 ( L_23 ,
V_200 , V_12 ) ;
V_12 = - V_210 ;
}
V_279:
F_208 ( & V_277 ) ;
F_156 ( L_24 , V_200 , V_12 ) ;
return V_12 ;
}
void F_209 ( struct V_54 * V_284 , int V_74 )
{
struct V_1 * V_2 = V_284 -> V_2 ;
switch ( V_74 ) {
default:
F_5 ( V_62 , & V_2 -> V_18 ) ;
break;
case - V_239 :
F_5 ( V_63 , & V_2 -> V_18 ) ;
}
F_155 ( V_2 ) ;
}
static void F_210 ( struct V_1 * V_2 )
{
F_5 ( V_202 , & V_2 -> V_18 ) ;
F_145 ( V_2 ) ;
}
void F_211 ( struct V_1 * V_2 )
{
F_210 ( V_2 ) ;
}
void F_212 ( struct V_1 * V_2 )
{
F_210 ( V_2 ) ;
}
static void F_213 ( struct V_1 * V_2 )
{
if ( F_146 ( V_201 , & V_2 -> V_18 ) == 0 ) {
F_5 ( V_262 , & V_2 -> V_18 ) ;
F_7 ( V_17 , & V_2 -> V_18 ) ;
F_192 ( V_2 ) ;
F_156 ( L_25 ,
V_200 , V_2 -> V_203 ) ;
F_145 ( V_2 ) ;
}
}
static void F_214 ( struct V_1 * V_2 )
{
if ( F_146 ( V_201 , & V_2 -> V_18 ) == 0 ) {
F_184 ( V_2 ) ;
F_156 ( L_26 , V_200 ,
V_2 -> V_203 ) ;
F_145 ( V_2 ) ;
}
}
static void F_215 ( struct V_1 * V_2 )
{
F_213 ( V_2 ) ;
F_156 ( L_27 , V_200 , V_2 -> V_203 ) ;
}
static void F_216 ( struct V_1 * V_2 )
{
F_162 ( V_2 ) ;
F_156 ( L_28 , V_200 ,
V_2 -> V_203 ) ;
}
static void F_217 ( struct V_1 * V_2 )
{
F_162 ( V_2 ) ;
if ( F_146 ( V_62 , & V_2 -> V_18 ) == 0 )
F_145 ( V_2 ) ;
F_156 ( L_29 , V_200 ,
V_2 -> V_203 ) ;
}
static void F_218 ( struct V_1 * V_2 )
{
if ( F_146 ( V_63 ,
& V_2 -> V_18 ) == 0 )
F_145 ( V_2 ) ;
}
void F_219 ( struct V_1 * V_2 , T_6 V_81 )
{
if ( ! V_81 )
return;
F_156 ( L_30 ,
V_200 , V_2 -> V_203 , V_2 -> V_8 , V_81 ) ;
if ( V_81 & V_285 )
F_214 ( V_2 ) ;
if ( V_81 & ( V_286 |
V_287 |
V_288 |
V_289 ) )
F_215 ( V_2 ) ;
if ( V_81 & V_290 )
F_216 ( V_2 ) ;
if ( V_81 & V_291 )
F_217 ( V_2 ) ;
else if ( V_81 & ( V_292 |
V_293 ) )
F_218 ( V_2 ) ;
}
static int F_220 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
int V_12 ;
if ( ! F_136 ( V_2 ) )
return 0 ;
F_36 ( V_2 ) ;
V_4 = F_44 ( V_2 ) ;
V_12 = F_221 ( V_2 -> V_56 , V_4 ) ;
switch ( V_12 ) {
case 0 :
case - V_236 :
case - V_252 :
break;
case - V_294 :
case - V_267 :
F_5 ( V_62 , & V_2 -> V_18 ) ;
V_12 = 0 ;
F_178 ( 1 ) ;
goto V_26;
default:
V_12 = F_193 ( V_2 , V_12 ) ;
goto V_26;
}
memset ( V_2 -> V_56 -> V_295 . V_296 , 0 , V_297 ) ;
V_12 = F_40 ( V_2 , V_4 ) ;
if ( V_12 ) {
F_156 ( L_31 ,
V_200 , V_12 , V_2 -> V_203 ) ;
V_12 = F_196 ( V_2 , V_12 ) ;
goto V_26;
}
F_37 ( V_2 ) ;
F_156 ( L_32 ,
V_200 , V_2 -> V_203 ) ;
V_26:
if ( V_4 )
F_74 ( V_4 ) ;
return V_12 ;
}
static int F_222 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
int V_61 ;
if ( ! F_136 ( V_2 ) )
return 0 ;
F_36 ( V_2 ) ;
V_4 = F_44 ( V_2 ) ;
V_61 = F_223 ( V_2 , V_4 ) ;
if ( V_4 )
F_74 ( V_4 ) ;
F_7 ( V_63 , & V_2 -> V_18 ) ;
switch ( V_61 ) {
case 0 :
F_156 ( L_33 ,
V_200 , V_2 -> V_203 ) ;
break;
case - V_267 :
F_178 ( 1 ) ;
F_5 ( V_63 , & V_2 -> V_18 ) ;
break;
default:
return F_193 ( V_2 , V_61 ) ;
}
return 0 ;
}
static int F_220 ( struct V_1 * V_2 ) { return 0 ; }
static int F_29 ( struct V_1 * V_2 ) { return 0 ; }
static int F_222 ( struct V_1 * V_2 )
{
return 0 ;
}
static void F_224 ( struct V_1 * V_2 )
{
int V_12 = 0 ;
const char * V_298 = L_34 , * V_299 = L_34 ;
do {
if ( F_3 ( V_262 , & V_2 -> V_18 ) ) {
V_298 = L_35 ;
V_12 = F_201 ( V_2 ) ;
if ( V_12 < 0 )
goto V_300;
continue;
}
if ( F_3 ( V_201 , & V_2 -> V_18 ) ) {
V_298 = L_36 ;
V_12 = F_200 ( V_2 ) ;
if ( V_12 < 0 )
goto V_300;
continue;
}
if ( F_27 ( V_62 , & V_2 -> V_18 ) ) {
V_298 = L_37 ;
V_12 = F_220 ( V_2 ) ;
if ( F_3 ( V_201 , & V_2 -> V_18 ) )
continue;
if ( V_12 < 0 )
goto V_300;
}
if ( F_27 ( V_63 ,
& V_2 -> V_18 ) ) {
V_298 = L_38 ;
V_12 = F_222 ( V_2 ) ;
if ( V_12 < 0 )
goto V_300;
continue;
}
if ( F_27 ( V_202 , & V_2 -> V_18 ) ) {
V_298 = L_39 ;
V_12 = F_195 ( V_2 ) ;
if ( V_12 < 0 )
goto V_300;
continue;
}
if ( F_3 ( V_215 , & V_2 -> V_18 ) ) {
V_298 = L_40 ;
V_12 = F_194 ( V_2 ,
V_2 -> V_147 -> V_248 ) ;
if ( F_3 ( V_201 , & V_2 -> V_18 ) ||
F_3 ( V_62 , & V_2 -> V_18 ) )
continue;
F_190 ( V_2 ) ;
if ( F_3 ( V_217 , & V_2 -> V_18 ) )
continue;
if ( V_12 < 0 )
goto V_300;
}
if ( F_27 ( V_217 , & V_2 -> V_18 ) ) {
V_298 = L_41 ;
V_12 = F_194 ( V_2 ,
V_2 -> V_147 -> V_301 ) ;
if ( F_3 ( V_201 , & V_2 -> V_18 ) ||
F_3 ( V_62 , & V_2 -> V_18 ) ||
F_3 ( V_215 , & V_2 -> V_18 ) )
continue;
if ( V_12 < 0 )
goto V_300;
}
F_29 ( V_2 ) ;
if ( F_27 ( V_302 , & V_2 -> V_18 ) ) {
F_225 ( V_2 ) ;
continue;
}
F_140 ( V_2 ) ;
if ( V_2 -> V_18 == 0 )
break;
if ( F_146 ( V_189 , & V_2 -> V_18 ) != 0 )
break;
} while ( F_226 ( & V_2 -> V_195 ) > 1 );
return;
V_300:
if ( strlen ( V_298 ) )
V_299 = L_42 ;
F_133 ( L_43
L_44 , V_299 , V_298 ,
V_2 -> V_203 , - V_12 ) ;
F_178 ( 1 ) ;
F_29 ( V_2 ) ;
F_140 ( V_2 ) ;
}
static int V_198 ( void * V_303 )
{
struct V_1 * V_2 = V_303 ;
F_227 ( V_304 ) ;
F_224 ( V_2 ) ;
F_153 ( V_2 ) ;
F_228 ( 0 ) ;
return 0 ;
}
