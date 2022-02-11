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
struct V_27 * V_28 , * V_77 = NULL ;
while ( * V_69 != NULL ) {
V_70 = * V_69 ;
V_28 = F_17 ( V_70 , struct V_27 , V_32 ) ;
if ( V_26 < V_28 -> V_78 ) {
V_69 = & V_70 -> V_74 ;
continue;
}
if ( V_26 > V_28 -> V_78 ) {
V_69 = & V_70 -> V_75 ;
continue;
}
if ( V_4 < V_28 -> V_34 )
V_69 = & V_70 -> V_74 ;
else if ( V_4 > V_28 -> V_34 )
V_69 = & V_70 -> V_75 ;
else {
F_47 ( & V_28 -> V_79 ) ;
V_77 = V_28 ;
break;
}
}
return V_77 ;
}
static struct V_27 *
F_48 ( struct V_27 * V_66 )
{
struct V_25 * V_26 = V_66 -> V_78 ;
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
F_47 ( & V_28 -> V_79 ) ;
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
F_49 ( struct V_27 * V_28 )
{
struct V_25 * V_26 = V_28 -> V_78 ;
if ( ! F_50 ( & V_28 -> V_32 ) )
F_45 ( & V_28 -> V_32 , & V_26 -> V_31 ) ;
F_44 ( & V_26 -> V_80 , & V_28 -> V_81 ) ;
}
static struct V_27 *
F_51 ( void )
{
struct V_27 * V_28 ;
V_28 = F_52 ( sizeof( * V_28 ) , V_82 ) ;
if ( ! V_28 )
return NULL ;
F_53 ( & V_28 -> V_83 ) ;
F_54 ( & V_28 -> V_33 ) ;
F_55 ( & V_28 -> V_84 . V_85 , L_1 ) ;
V_28 -> V_86 . V_87 = & V_28 -> V_84 ;
F_53 ( & V_28 -> V_84 . V_88 ) ;
F_54 ( & V_28 -> V_84 . V_89 ) ;
F_56 ( & V_28 -> V_79 , 1 ) ;
return V_28 ;
}
static void
F_57 ( struct V_27 * V_28 )
{
if ( ! F_50 ( & V_28 -> V_32 ) ) {
struct V_25 * V_26 = V_28 -> V_78 ;
struct V_1 * V_2 = V_26 -> V_1 ;
F_11 ( & V_2 -> V_24 ) ;
F_45 ( & V_28 -> V_32 , & V_26 -> V_31 ) ;
F_58 ( & V_28 -> V_32 ) ;
F_12 ( & V_2 -> V_24 ) ;
}
}
struct V_27 * F_59 ( struct V_25 * V_26 ,
struct V_3 * V_4 )
{
struct V_1 * V_2 = V_26 -> V_1 ;
struct V_27 * V_28 , * V_66 ;
F_11 ( & V_2 -> V_24 ) ;
V_28 = F_46 ( V_26 , V_4 ) ;
F_12 ( & V_2 -> V_24 ) ;
if ( V_28 != NULL )
return V_28 ;
V_66 = F_51 () ;
if ( V_66 == NULL )
return NULL ;
V_66 -> V_78 = V_26 ;
V_66 -> V_34 = V_4 ;
F_11 ( & V_2 -> V_24 ) ;
V_28 = F_48 ( V_66 ) ;
F_12 ( & V_2 -> V_24 ) ;
if ( V_28 == V_66 )
F_9 ( V_4 ) ;
else {
F_60 ( & V_66 -> V_84 . V_85 ) ;
F_61 ( V_66 ) ;
}
return V_28 ;
}
void F_62 ( struct V_27 * V_28 )
{
struct V_1 * V_2 = V_28 -> V_78 -> V_1 ;
struct V_3 * V_4 = V_28 -> V_34 ;
if ( ! F_63 ( & V_28 -> V_79 , & V_2 -> V_24 ) )
return;
F_49 ( V_28 ) ;
F_12 ( & V_2 -> V_24 ) ;
F_60 ( & V_28 -> V_84 . V_85 ) ;
F_13 ( V_4 ) ;
F_61 ( V_28 ) ;
}
static struct V_90 *
F_64 ( void )
{
struct V_90 * V_91 ;
V_91 = F_52 ( sizeof( * V_91 ) , V_82 ) ;
if ( ! V_91 )
return NULL ;
F_56 ( & V_91 -> V_92 , 1 ) ;
F_54 ( & V_91 -> V_93 ) ;
F_53 ( & V_91 -> V_94 ) ;
F_65 ( & V_91 -> V_95 ) ;
return V_91 ;
}
void
F_66 ( struct V_90 * V_91 , T_2 V_96 )
{
if ( V_91 -> V_91 == V_96 )
return;
if ( ( V_96 & V_97 ) != ( V_91 -> V_91 & V_97 ) ) {
if ( V_96 & V_97 )
F_67 ( & V_91 -> V_98 , & V_91 -> V_99 -> V_33 ) ;
else
F_68 ( & V_91 -> V_98 , & V_91 -> V_99 -> V_33 ) ;
}
V_91 -> V_91 = V_96 ;
}
static struct V_90 *
F_69 ( struct V_100 * V_100 , struct V_27 * V_99 )
{
struct V_101 * V_102 = F_70 ( V_100 ) ;
struct V_90 * V_91 ;
F_71 (state, &nfsi->open_states, inode_states) {
if ( V_91 -> V_99 != V_99 )
continue;
if ( F_72 ( & V_91 -> V_92 ) )
return V_91 ;
}
return NULL ;
}
static void
F_73 ( struct V_90 * V_91 )
{
F_61 ( V_91 ) ;
}
struct V_90 *
F_74 ( struct V_100 * V_100 , struct V_27 * V_99 )
{
struct V_90 * V_91 , * V_66 ;
struct V_101 * V_102 = F_70 ( V_100 ) ;
F_11 ( & V_100 -> V_103 ) ;
V_91 = F_69 ( V_100 , V_99 ) ;
F_12 ( & V_100 -> V_103 ) ;
if ( V_91 )
goto V_22;
V_66 = F_64 () ;
F_11 ( & V_99 -> V_83 ) ;
F_11 ( & V_100 -> V_103 ) ;
V_91 = F_69 ( V_100 , V_99 ) ;
if ( V_91 == NULL && V_66 != NULL ) {
V_91 = V_66 ;
V_91 -> V_99 = V_99 ;
F_47 ( & V_99 -> V_79 ) ;
F_75 ( & V_91 -> V_104 , & V_102 -> V_98 ) ;
F_76 ( V_100 ) ;
V_91 -> V_100 = V_100 ;
F_12 ( & V_100 -> V_103 ) ;
F_77 ( & V_91 -> V_98 , & V_99 -> V_33 ) ;
F_12 ( & V_99 -> V_83 ) ;
} else {
F_12 ( & V_100 -> V_103 ) ;
F_12 ( & V_99 -> V_83 ) ;
if ( V_66 )
F_73 ( V_66 ) ;
}
V_22:
return V_91 ;
}
void F_78 ( struct V_90 * V_91 )
{
struct V_100 * V_100 = V_91 -> V_100 ;
struct V_27 * V_99 = V_91 -> V_99 ;
if ( ! F_63 ( & V_91 -> V_92 , & V_99 -> V_83 ) )
return;
F_11 ( & V_100 -> V_103 ) ;
F_79 ( & V_91 -> V_104 ) ;
F_79 ( & V_91 -> V_98 ) ;
F_12 ( & V_100 -> V_103 ) ;
F_12 ( & V_99 -> V_83 ) ;
F_80 ( V_100 ) ;
F_73 ( V_91 ) ;
F_62 ( V_99 ) ;
}
static void F_81 ( struct V_90 * V_91 ,
T_2 V_96 , T_3 V_105 , int V_85 )
{
struct V_27 * V_99 = V_91 -> V_99 ;
int V_106 = 0 ;
T_2 V_107 ;
F_47 ( & V_99 -> V_79 ) ;
F_11 ( & V_99 -> V_83 ) ;
switch ( V_96 & ( V_108 | V_97 ) ) {
case V_108 :
V_91 -> V_109 -- ;
break;
case V_97 :
V_91 -> V_110 -- ;
break;
case V_108 | V_97 :
V_91 -> V_111 -- ;
}
V_107 = V_108 | V_97 ;
if ( V_91 -> V_111 == 0 ) {
if ( V_91 -> V_109 == 0 ) {
V_107 &= ~ V_108 ;
V_106 |= F_2 ( V_112 , & V_91 -> V_113 ) ;
V_106 |= F_2 ( V_114 , & V_91 -> V_113 ) ;
}
if ( V_91 -> V_110 == 0 ) {
V_107 &= ~ V_97 ;
V_106 |= F_2 ( V_115 , & V_91 -> V_113 ) ;
V_106 |= F_2 ( V_114 , & V_91 -> V_113 ) ;
}
if ( V_107 == 0 )
F_6 ( V_116 , & V_91 -> V_113 ) ;
}
F_66 ( V_91 , V_107 ) ;
F_12 ( & V_99 -> V_83 ) ;
if ( ! V_106 ) {
F_78 ( V_91 ) ;
F_62 ( V_99 ) ;
} else {
bool V_117 = F_82 ( V_91 -> V_100 ) ;
F_83 ( V_91 , V_105 , V_85 , V_117 ) ;
}
}
void F_84 ( struct V_90 * V_91 , T_2 V_96 )
{
F_81 ( V_91 , V_96 , V_82 , 0 ) ;
}
void F_85 ( struct V_90 * V_91 , T_2 V_96 )
{
F_81 ( V_91 , V_96 , V_118 , 1 ) ;
}
static struct V_119 *
F_86 ( struct V_90 * V_91 , T_4 V_120 , T_5 V_121 , unsigned int type )
{
struct V_119 * V_30 ;
F_71 (pos, &state->lock_states, ls_locks) {
if ( type != V_122 && V_30 -> V_123 . V_124 != type )
continue;
switch ( V_30 -> V_123 . V_124 ) {
case V_125 :
if ( V_30 -> V_123 . V_126 . V_127 != V_120 )
continue;
break;
case V_128 :
if ( V_30 -> V_123 . V_126 . V_129 != V_121 )
continue;
}
F_47 ( & V_30 -> V_130 ) ;
return V_30 ;
}
return NULL ;
}
static struct V_119 * F_87 ( struct V_90 * V_91 , T_4 V_120 , T_5 V_121 , unsigned int type )
{
struct V_119 * V_131 ;
struct V_25 * V_26 = V_91 -> V_99 -> V_78 ;
struct V_1 * V_2 = V_26 -> V_1 ;
V_131 = F_52 ( sizeof( * V_131 ) , V_82 ) ;
if ( V_131 == NULL )
return NULL ;
F_55 ( & V_131 -> V_132 . V_85 , L_2 ) ;
F_53 ( & V_131 -> V_132 . V_88 ) ;
F_54 ( & V_131 -> V_132 . V_89 ) ;
V_131 -> V_133 . V_87 = & V_131 -> V_132 ;
F_56 ( & V_131 -> V_130 , 1 ) ;
V_131 -> V_134 = V_91 ;
V_131 -> V_123 . V_124 = type ;
switch ( V_131 -> V_123 . V_124 ) {
case V_128 :
V_131 -> V_123 . V_126 . V_129 = V_121 ;
break;
case V_125 :
V_131 -> V_123 . V_126 . V_127 = V_120 ;
break;
default:
F_61 ( V_131 ) ;
return NULL ;
}
F_11 ( & V_2 -> V_24 ) ;
F_40 ( & V_26 -> V_135 , & V_131 -> V_136 , 1 , 64 ) ;
F_12 ( & V_2 -> V_24 ) ;
F_54 ( & V_131 -> V_137 ) ;
return V_131 ;
}
static void F_88 ( struct V_119 * V_131 )
{
struct V_25 * V_26 = V_131 -> V_134 -> V_99 -> V_78 ;
struct V_1 * V_2 = V_26 -> V_1 ;
F_11 ( & V_2 -> V_24 ) ;
F_44 ( & V_26 -> V_135 , & V_131 -> V_136 ) ;
F_12 ( & V_2 -> V_24 ) ;
F_60 ( & V_131 -> V_132 . V_85 ) ;
F_61 ( V_131 ) ;
}
static struct V_119 * F_89 ( struct V_90 * V_91 , T_4 V_99 , T_5 V_138 , unsigned int type )
{
struct V_119 * V_131 , * V_66 = NULL ;
for(; ; ) {
F_11 ( & V_91 -> V_94 ) ;
V_131 = F_86 ( V_91 , V_99 , V_138 , type ) ;
if ( V_131 != NULL )
break;
if ( V_66 != NULL ) {
F_75 ( & V_66 -> V_137 , & V_91 -> V_93 ) ;
F_4 ( V_139 , & V_91 -> V_113 ) ;
V_131 = V_66 ;
V_66 = NULL ;
break;
}
F_12 ( & V_91 -> V_94 ) ;
V_66 = F_87 ( V_91 , V_99 , V_138 , type ) ;
if ( V_66 == NULL )
return NULL ;
}
F_12 ( & V_91 -> V_94 ) ;
if ( V_66 != NULL )
F_88 ( V_66 ) ;
return V_131 ;
}
void F_90 ( struct V_119 * V_131 )
{
struct V_90 * V_91 ;
if ( V_131 == NULL )
return;
V_91 = V_131 -> V_134 ;
if ( ! F_63 ( & V_131 -> V_130 , & V_91 -> V_94 ) )
return;
F_79 ( & V_131 -> V_137 ) ;
if ( F_18 ( & V_91 -> V_93 ) )
F_6 ( V_139 , & V_91 -> V_113 ) ;
F_12 ( & V_91 -> V_94 ) ;
if ( V_131 -> V_140 & V_141 )
F_91 ( V_131 ) ;
F_88 ( V_131 ) ;
}
static void F_92 ( struct V_142 * V_143 , struct V_142 * V_144 )
{
struct V_119 * V_131 = V_144 -> V_145 . V_146 . V_99 ;
V_143 -> V_145 . V_146 . V_99 = V_131 ;
F_47 ( & V_131 -> V_130 ) ;
}
static void F_93 ( struct V_142 * V_147 )
{
F_90 ( V_147 -> V_145 . V_146 . V_99 ) ;
}
int F_94 ( struct V_90 * V_91 , struct V_142 * V_147 )
{
struct V_119 * V_131 ;
if ( V_147 -> V_148 != NULL )
return 0 ;
if ( V_147 -> V_149 & V_150 )
V_131 = F_89 ( V_91 , V_147 -> V_120 , 0 , V_125 ) ;
else if ( V_147 -> V_149 & V_151 )
V_131 = F_89 ( V_91 , 0 , V_147 -> V_121 , V_128 ) ;
else
return - V_152 ;
if ( V_131 == NULL )
return - V_153 ;
V_147 -> V_145 . V_146 . V_99 = V_131 ;
V_147 -> V_148 = & V_154 ;
return 0 ;
}
void F_95 ( T_6 * V_143 , struct V_90 * V_91 , T_4 V_120 , T_5 V_121 )
{
struct V_119 * V_131 ;
int V_155 ;
do {
V_155 = F_96 ( & V_91 -> V_95 ) ;
memcpy ( V_143 , & V_91 -> V_156 , sizeof( * V_143 ) ) ;
} while ( F_97 ( & V_91 -> V_95 , V_155 ) );
if ( F_2 ( V_139 , & V_91 -> V_113 ) == 0 )
return;
F_11 ( & V_91 -> V_94 ) ;
V_131 = F_86 ( V_91 , V_120 , V_121 , V_122 ) ;
if ( V_131 != NULL && ( V_131 -> V_140 & V_141 ) != 0 )
memcpy ( V_143 , & V_131 -> V_157 , sizeof( * V_143 ) ) ;
F_12 ( & V_91 -> V_94 ) ;
F_90 ( V_131 ) ;
}
struct V_158 * F_98 ( struct V_159 * V_160 , T_3 V_105 )
{
struct V_158 * V_66 ;
V_66 = F_99 ( sizeof( * V_66 ) , V_105 ) ;
if ( V_66 != NULL ) {
V_66 -> V_87 = V_160 ;
F_54 ( & V_66 -> V_89 ) ;
}
return V_66 ;
}
void F_100 ( struct V_158 * V_161 )
{
if ( ! F_18 ( & V_161 -> V_89 ) ) {
struct V_162 * V_87 = V_161 -> V_87 -> V_87 ;
F_11 ( & V_87 -> V_88 ) ;
F_101 ( & V_161 -> V_89 ) ;
F_12 ( & V_87 -> V_88 ) ;
F_102 ( & V_87 -> V_85 ) ;
}
}
void F_103 ( struct V_158 * V_161 )
{
F_100 ( V_161 ) ;
F_61 ( V_161 ) ;
}
static void F_104 ( int V_12 , struct V_158 * V_161 )
{
F_105 ( F_106 ( & V_161 -> V_87 -> V_87 -> V_89 , struct V_158 , V_89 ) != V_161 ) ;
switch ( V_12 ) {
case 0 :
break;
case - V_163 :
if ( V_161 -> V_87 -> V_113 & V_164 )
return;
F_107 ( V_165 L_3
L_4
L_5 ,
V_161 -> V_87 ) ;
case - V_166 :
case - V_167 :
case - V_168 :
case - V_169 :
case - V_170 :
case - V_171 :
return;
} ;
V_161 -> V_87 -> V_160 ++ ;
}
void F_108 ( int V_12 , struct V_158 * V_161 )
{
struct V_27 * V_28 = F_109 ( V_161 -> V_87 ,
struct V_27 , V_86 ) ;
struct V_25 * V_26 = V_28 -> V_78 ;
if ( V_12 == - V_163 )
F_57 ( V_28 ) ;
if ( ! F_110 ( V_26 -> V_1 ) )
F_104 ( V_12 , V_161 ) ;
}
void F_111 ( int V_12 , struct V_158 * V_161 )
{
F_104 ( V_12 , V_161 ) ;
}
int F_112 ( struct V_158 * V_161 , struct V_52 * V_53 )
{
struct V_162 * V_87 = V_161 -> V_87 -> V_87 ;
int V_12 = 0 ;
F_11 ( & V_87 -> V_88 ) ;
if ( F_18 ( & V_161 -> V_89 ) )
F_77 ( & V_161 -> V_89 , & V_87 -> V_89 ) ;
if ( F_106 ( & V_87 -> V_89 , struct V_158 , V_89 ) == V_161 )
goto V_172;
F_113 ( & V_87 -> V_85 , V_53 , NULL ) ;
V_12 = - V_173 ;
V_172:
F_12 ( & V_87 -> V_88 ) ;
return V_12 ;
}
static void F_114 ( struct V_1 * V_2 )
{
F_115 () ;
F_6 ( V_174 , & V_2 -> V_14 ) ;
F_116 () ;
F_117 ( & V_2 -> V_14 , V_174 ) ;
F_102 ( & V_2 -> V_175 ) ;
}
void F_118 ( struct V_1 * V_2 )
{
struct V_176 * V_53 ;
if ( F_119 ( V_174 , & V_2 -> V_14 ) != 0 )
return;
F_120 ( V_177 ) ;
F_47 ( & V_2 -> V_178 ) ;
V_53 = F_121 ( V_179 , V_2 , L_6 ,
F_122 ( V_2 -> V_180 ,
V_181 ) ) ;
if ( ! F_123 ( V_53 ) )
return;
F_114 ( V_2 ) ;
F_124 ( V_2 ) ;
F_125 ( V_177 ) ;
}
void F_126 ( struct V_1 * V_2 )
{
if ( ! V_2 )
return;
if ( ! F_2 ( V_182 , & V_2 -> V_14 ) )
F_4 ( V_183 , & V_2 -> V_14 ) ;
F_118 ( V_2 ) ;
}
void F_127 ( struct V_1 * V_2 )
{
F_128 ( V_2 ) ;
F_118 ( V_2 ) ;
}
static int F_129 ( struct V_1 * V_2 , struct V_90 * V_91 )
{
F_4 ( V_184 , & V_91 -> V_113 ) ;
if ( F_2 ( V_185 , & V_91 -> V_113 ) ) {
F_6 ( V_184 , & V_91 -> V_113 ) ;
return 0 ;
}
F_4 ( V_186 , & V_91 -> V_99 -> V_187 ) ;
F_4 ( V_188 , & V_2 -> V_14 ) ;
return 1 ;
}
static int F_130 ( struct V_1 * V_2 , struct V_90 * V_91 )
{
F_4 ( V_185 , & V_91 -> V_113 ) ;
F_6 ( V_184 , & V_91 -> V_113 ) ;
F_4 ( V_189 , & V_91 -> V_99 -> V_187 ) ;
F_4 ( V_190 , & V_2 -> V_14 ) ;
return 1 ;
}
void F_131 ( const struct V_25 * V_26 , struct V_90 * V_91 )
{
struct V_1 * V_2 = V_26 -> V_1 ;
F_130 ( V_2 , V_91 ) ;
F_118 ( V_2 ) ;
}
static int F_132 ( struct V_90 * V_91 , const struct V_191 * V_192 )
{
struct V_100 * V_100 = V_91 -> V_100 ;
struct V_101 * V_102 = F_70 ( V_100 ) ;
struct V_142 * V_147 ;
int V_12 = 0 ;
if ( V_100 -> V_193 == NULL )
return 0 ;
F_133 ( & V_102 -> V_194 ) ;
F_134 () ;
for ( V_147 = V_100 -> V_193 ; V_147 != NULL ; V_147 = V_147 -> V_195 ) {
if ( ! ( V_147 -> V_149 & ( V_150 | V_151 ) ) )
continue;
if ( F_135 ( V_147 -> V_196 ) -> V_91 != V_91 )
continue;
F_136 () ;
V_12 = V_192 -> V_197 ( V_91 , V_147 ) ;
switch ( V_12 ) {
case 0 :
break;
case - V_198 :
case - V_199 :
case - V_167 :
case - V_168 :
case - V_200 :
case - V_201 :
case - V_166 :
case - V_202 :
case - V_203 :
case - V_204 :
case - V_205 :
goto V_22;
default:
F_107 ( V_206 L_7 ,
V_207 , V_12 ) ;
case - V_153 :
case - V_208 :
case - V_209 :
case - V_210 :
V_12 = 0 ;
}
F_134 () ;
}
F_136 () ;
V_22:
F_137 ( & V_102 -> V_194 ) ;
return V_12 ;
}
static int F_138 ( struct V_27 * V_28 , const struct V_191 * V_192 )
{
struct V_90 * V_91 ;
struct V_119 * V_88 ;
int V_12 = 0 ;
V_211:
F_11 ( & V_28 -> V_83 ) ;
F_71 (state, &sp->so_states, open_states) {
if ( ! F_26 ( V_192 -> V_212 , & V_91 -> V_113 ) )
continue;
if ( V_91 -> V_91 == 0 )
continue;
F_47 ( & V_91 -> V_92 ) ;
F_12 ( & V_28 -> V_83 ) ;
V_12 = V_192 -> V_213 ( V_28 , V_91 ) ;
if ( V_12 >= 0 ) {
V_12 = F_132 ( V_91 , V_192 ) ;
if ( V_12 >= 0 ) {
F_71 (lock, &state->lock_states, ls_locks) {
if ( ! ( V_88 -> V_140 & V_141 ) )
F_107 ( L_8 ,
V_207 ) ;
}
F_78 ( V_91 ) ;
goto V_211;
}
}
switch ( V_12 ) {
default:
F_107 ( V_206 L_7 ,
V_207 , V_12 ) ;
case - V_214 :
case - V_153 :
case - V_198 :
memset ( V_91 -> V_156 . V_215 , 0 ,
sizeof( V_91 -> V_156 . V_215 ) ) ;
V_91 -> V_91 = 0 ;
break;
case - V_216 :
break;
case - V_199 :
case - V_167 :
case - V_168 :
case - V_209 :
case - V_210 :
F_130 ( V_28 -> V_78 -> V_1 , V_91 ) ;
break;
case - V_200 :
case - V_201 :
F_130 ( V_28 -> V_78 -> V_1 , V_91 ) ;
case - V_166 :
case - V_202 :
case - V_203 :
case - V_204 :
case - V_205 :
goto V_217;
}
F_78 ( V_91 ) ;
goto V_211;
}
F_12 ( & V_28 -> V_83 ) ;
return 0 ;
V_217:
F_78 ( V_91 ) ;
return V_12 ;
}
static void F_139 ( struct V_90 * V_91 )
{
struct V_119 * V_88 ;
F_6 ( V_116 , & V_91 -> V_113 ) ;
F_6 ( V_112 , & V_91 -> V_113 ) ;
F_6 ( V_115 , & V_91 -> V_113 ) ;
F_6 ( V_114 , & V_91 -> V_113 ) ;
F_71 (lock, &state->lock_states, ls_locks) {
V_88 -> V_133 . V_113 = 0 ;
V_88 -> V_140 &= ~ V_141 ;
}
}
static void F_140 ( struct V_25 * V_26 ,
int (* F_141)( struct V_1 * V_2 , struct V_90 * V_91 ) )
{
struct V_1 * V_2 = V_26 -> V_1 ;
struct V_27 * V_28 ;
struct V_29 * V_30 ;
struct V_90 * V_91 ;
F_11 ( & V_2 -> V_24 ) ;
for ( V_30 = F_15 ( & V_26 -> V_31 ) ;
V_30 != NULL ;
V_30 = F_16 ( V_30 ) ) {
V_28 = F_17 ( V_30 , struct V_27 , V_32 ) ;
V_28 -> V_86 . V_113 = 0 ;
F_11 ( & V_28 -> V_83 ) ;
F_71 (state, &sp->so_states, open_states) {
if ( F_141 ( V_2 , V_91 ) )
F_139 ( V_91 ) ;
}
F_12 ( & V_28 -> V_83 ) ;
}
F_12 ( & V_2 -> V_24 ) ;
}
static void F_142 ( struct V_1 * V_2 ,
int (* F_141)( struct V_1 * V_2 , struct V_90 * V_91 ) )
{
struct V_25 * V_26 ;
F_20 () ;
F_21 (server, &clp->cl_superblocks, client_link)
F_140 ( V_26 , F_141 ) ;
F_22 () ;
}
static void F_143 ( struct V_1 * V_2 )
{
F_144 ( V_2 ) ;
F_142 ( V_2 , F_129 ) ;
}
static void F_145 ( struct V_1 * V_2 ,
const struct V_191 * V_192 )
{
if ( V_192 -> V_218 )
( void ) V_192 -> V_218 ( V_2 ) ;
}
static void F_146 ( struct V_25 * V_26 )
{
struct V_1 * V_2 = V_26 -> V_1 ;
struct V_27 * V_28 ;
struct V_29 * V_30 ;
struct V_90 * V_91 ;
F_11 ( & V_2 -> V_24 ) ;
for ( V_30 = F_15 ( & V_26 -> V_31 ) ;
V_30 != NULL ;
V_30 = F_16 ( V_30 ) ) {
V_28 = F_17 ( V_30 , struct V_27 , V_32 ) ;
F_11 ( & V_28 -> V_83 ) ;
F_71 (state, &sp->so_states, open_states) {
if ( ! F_26 ( V_184 ,
& V_91 -> V_113 ) )
continue;
F_130 ( V_2 , V_91 ) ;
}
F_12 ( & V_28 -> V_83 ) ;
}
F_12 ( & V_2 -> V_24 ) ;
}
static int F_147 ( struct V_1 * V_2 )
{
struct V_25 * V_26 ;
if ( ! F_26 ( V_188 , & V_2 -> V_14 ) )
return 0 ;
F_20 () ;
F_21 (server, &clp->cl_superblocks, client_link)
F_146 ( V_26 ) ;
F_22 () ;
F_148 ( V_2 ) ;
return 1 ;
}
static void F_149 ( struct V_1 * V_2 )
{
if ( ! F_147 ( V_2 ) )
return;
F_145 ( V_2 , V_2 -> V_219 -> V_220 ) ;
}
static void F_150 ( struct V_1 * V_2 )
{
F_144 ( V_2 ) ;
F_148 ( V_2 ) ;
}
static void F_151 ( struct V_1 * V_2 )
{
F_150 ( V_2 ) ;
F_142 ( V_2 , F_130 ) ;
}
static void F_152 ( const char * V_221 )
{
F_153 ( V_165 L_9
L_10
L_11 ,
V_221 ) ;
}
static int F_154 ( struct V_1 * V_2 , int error )
{
switch ( error ) {
case - V_222 :
F_128 ( V_2 ) ;
return 0 ;
case - V_201 :
F_149 ( V_2 ) ;
return 0 ;
case - V_166 :
case - V_223 :
F_4 ( V_182 , & V_2 -> V_14 ) ;
F_147 ( V_2 ) ;
F_143 ( V_2 ) ;
break;
case - V_200 :
F_4 ( V_182 , & V_2 -> V_14 ) ;
F_151 ( V_2 ) ;
break;
case - V_202 :
case - V_203 :
case - V_204 :
case - V_224 :
case - V_205 :
case - V_225 :
case - V_226 :
F_4 ( V_227 , & V_2 -> V_14 ) ;
return 0 ;
case - V_216 :
F_152 ( V_2 -> V_228 ) ;
return 0 ;
}
return error ;
}
static int F_155 ( struct V_1 * V_2 , const struct V_191 * V_192 )
{
struct V_27 * V_28 ;
struct V_25 * V_26 ;
struct V_29 * V_30 ;
int V_12 = 0 ;
V_211:
F_20 () ;
F_21 (server, &clp->cl_superblocks, client_link) {
F_11 ( & V_2 -> V_24 ) ;
for ( V_30 = F_15 ( & V_26 -> V_31 ) ;
V_30 != NULL ;
V_30 = F_16 ( V_30 ) ) {
V_28 = F_17 ( V_30 ,
struct V_27 , V_32 ) ;
if ( ! F_26 ( V_192 -> V_229 ,
& V_28 -> V_187 ) )
continue;
F_47 ( & V_28 -> V_79 ) ;
F_12 ( & V_2 -> V_24 ) ;
F_22 () ;
V_12 = F_138 ( V_28 , V_192 ) ;
if ( V_12 < 0 ) {
F_4 ( V_192 -> V_229 , & V_28 -> V_187 ) ;
F_62 ( V_28 ) ;
return F_154 ( V_2 , V_12 ) ;
}
F_62 ( V_28 ) ;
goto V_211;
}
F_12 ( & V_2 -> V_24 ) ;
}
F_22 () ;
return V_12 ;
}
static int F_156 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
const struct V_230 * V_192 =
V_2 -> V_219 -> V_231 ;
int V_12 = - V_200 ;
if ( F_2 ( V_182 , & V_2 -> V_14 ) )
return 0 ;
F_11 ( & V_2 -> V_24 ) ;
V_4 = V_192 -> V_232 ( V_2 ) ;
F_12 ( & V_2 -> V_24 ) ;
if ( V_4 == NULL ) {
V_4 = F_39 ( V_2 ) ;
if ( V_4 == NULL )
goto V_22;
}
V_12 = V_192 -> V_233 ( V_2 , V_4 ) ;
F_13 ( V_4 ) ;
V_22:
return F_154 ( V_2 , V_12 ) ;
}
static int F_157 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
const struct V_191 * V_192 =
V_2 -> V_219 -> V_220 ;
int V_12 = - V_214 ;
V_4 = V_192 -> V_234 ( V_2 ) ;
if ( V_4 != NULL ) {
V_12 = V_192 -> V_235 ( V_2 , V_4 ) ;
F_13 ( V_4 ) ;
if ( V_12 == - V_236 && V_4 == V_2 -> V_23 ) {
F_10 ( V_2 ) ;
V_12 = - V_173 ;
}
if ( V_12 == - V_237 )
V_12 = - V_238 ;
}
return V_12 ;
}
void F_158 ( struct V_44 * V_239 )
{
struct V_1 * V_2 = V_239 -> V_2 ;
F_4 ( V_227 , & V_2 -> V_14 ) ;
F_126 ( V_2 ) ;
}
void F_159 ( struct V_1 * V_2 )
{
F_4 ( V_240 , & V_2 -> V_14 ) ;
F_118 ( V_2 ) ;
}
static void F_160 ( struct V_1 * V_2 )
{
if ( F_119 ( V_182 , & V_2 -> V_14 ) == 0 ) {
V_2 -> V_241 = V_242 ;
F_151 ( V_2 ) ;
F_118 ( V_2 ) ;
}
}
static void F_161 ( struct V_1 * V_2 )
{
if ( F_119 ( V_182 , & V_2 -> V_14 ) == 0 ) {
F_143 ( V_2 ) ;
F_118 ( V_2 ) ;
}
}
static void F_162 ( struct V_1 * V_2 )
{
F_160 ( V_2 ) ;
}
static void F_163 ( struct V_1 * V_2 )
{
F_164 ( V_2 ) ;
}
static void F_165 ( struct V_1 * V_2 )
{
F_164 ( V_2 ) ;
if ( F_119 ( V_227 , & V_2 -> V_14 ) == 0 )
F_118 ( V_2 ) ;
}
void F_166 ( struct V_1 * V_2 , T_7 V_113 )
{
if ( ! V_113 )
return;
else if ( V_113 & V_243 )
F_161 ( V_2 ) ;
else if ( V_113 & ( V_244 |
V_245 |
V_246 |
V_247 ) )
F_162 ( V_2 ) ;
else if ( V_113 & V_248 )
F_163 ( V_2 ) ;
else if ( V_113 & ( V_249 |
V_250 |
V_251 ) )
F_165 ( V_2 ) ;
}
static int F_167 ( struct V_1 * V_2 )
{
int V_12 ;
F_32 ( V_2 ) ;
V_12 = F_168 ( V_2 -> V_46 ) ;
if ( V_12 && V_12 != - V_202 &&
V_12 != - V_224 ) {
V_12 = F_154 ( V_2 , V_12 ) ;
goto V_22;
}
memset ( V_2 -> V_46 -> V_252 . V_215 , 0 , V_253 ) ;
V_12 = F_35 ( V_2 ) ;
if ( V_12 ) {
V_12 = F_154 ( V_2 , V_12 ) ;
goto V_22;
}
F_6 ( V_227 , & V_2 -> V_14 ) ;
F_6 ( V_240 , & V_2 -> V_14 ) ;
if ( ! F_2 ( V_182 , & V_2 -> V_14 ) )
F_23 ( V_2 ) ;
V_22:
return V_12 ;
}
static int F_169 ( struct V_1 * V_2 )
{
struct V_56 * V_254 = & V_2 -> V_46 -> V_50 ;
struct V_255 * V_256 = & V_2 -> V_46 -> V_256 ;
struct V_257 * V_66 , * V_258 ;
int V_259 ;
F_32 ( V_2 ) ;
V_66 = F_99 ( V_254 -> V_260 * sizeof( struct V_257 ) ,
V_82 ) ;
if ( ! V_66 )
return - V_153 ;
F_11 ( & V_254 -> V_51 ) ;
for ( V_259 = 0 ; V_259 < V_254 -> V_260 ; V_259 ++ )
V_66 [ V_259 ] . V_261 = V_254 -> V_262 [ V_259 ] . V_261 ;
V_258 = V_254 -> V_262 ;
V_254 -> V_262 = V_66 ;
V_254 -> V_47 = V_254 -> V_260 ;
V_254 -> V_260 = 0 ;
V_256 -> V_263 = V_254 -> V_47 ;
F_12 ( & V_254 -> V_51 ) ;
F_61 ( V_258 ) ;
F_25 ( V_2 ) ;
return 0 ;
}
static int F_167 ( struct V_1 * V_2 ) { return 0 ; }
static int F_25 ( struct V_1 * V_2 ) { return 0 ; }
static int F_169 ( struct V_1 * V_2 ) { return 0 ; }
static void F_170 ( struct V_1 * V_2 , int V_12 )
{
switch ( V_12 ) {
case - V_264 :
case - V_166 :
F_6 ( V_13 , & V_2 -> V_14 ) ;
break;
case - V_265 :
case - V_266 :
case - V_173 :
F_171 ( 1 ) ;
break;
case - V_216 :
F_152 ( V_2 -> V_228 ) ;
case - V_267 :
default:
return;
}
F_4 ( V_182 , & V_2 -> V_14 ) ;
}
static void F_172 ( struct V_1 * V_2 )
{
int V_12 = 0 ;
do {
if ( F_26 ( V_182 , & V_2 -> V_14 ) ) {
V_12 = F_157 ( V_2 ) ;
if ( V_12 ) {
F_170 ( V_2 , V_12 ) ;
if ( F_2 ( V_182 ,
& V_2 -> V_14 ) )
continue;
if ( V_2 -> V_268 ==
V_269 )
F_36 ( V_2 , V_12 ) ;
goto V_270;
}
F_6 ( V_183 , & V_2 -> V_14 ) ;
if ( F_26 ( V_271 ,
& V_2 -> V_14 ) )
F_151 ( V_2 ) ;
else
F_4 ( V_188 ,
& V_2 -> V_14 ) ;
F_173 ( V_2 ) ;
}
if ( F_26 ( V_183 , & V_2 -> V_14 ) ) {
V_12 = F_156 ( V_2 ) ;
if ( F_2 ( V_182 , & V_2 -> V_14 ) )
continue;
if ( V_12 < 0 && V_12 != - V_222 )
goto V_270;
}
if ( F_26 ( V_227 , & V_2 -> V_14 )
&& F_110 ( V_2 ) ) {
V_12 = F_167 ( V_2 ) ;
if ( F_2 ( V_182 , & V_2 -> V_14 ) )
continue;
if ( V_12 < 0 )
goto V_270;
}
if ( F_2 ( V_188 , & V_2 -> V_14 ) ) {
V_12 = F_155 ( V_2 ,
V_2 -> V_219 -> V_220 ) ;
if ( F_2 ( V_182 , & V_2 -> V_14 ) ||
F_2 ( V_227 , & V_2 -> V_14 ) )
continue;
F_149 ( V_2 ) ;
if ( F_2 ( V_190 , & V_2 -> V_14 ) )
continue;
if ( V_12 < 0 )
goto V_270;
}
if ( F_26 ( V_190 , & V_2 -> V_14 ) ) {
V_12 = F_155 ( V_2 ,
V_2 -> V_219 -> V_272 ) ;
if ( F_2 ( V_182 , & V_2 -> V_14 ) ||
F_2 ( V_227 , & V_2 -> V_14 ) ||
F_2 ( V_188 , & V_2 -> V_14 ) )
continue;
if ( V_12 < 0 )
goto V_270;
}
F_25 ( V_2 ) ;
if ( F_26 ( V_273 , & V_2 -> V_14 ) ) {
F_174 ( V_2 ) ;
continue;
}
if ( F_26 ( V_240 , & V_2 -> V_14 )
&& F_110 ( V_2 ) ) {
V_12 = F_169 ( V_2 ) ;
if ( V_12 < 0 )
goto V_270;
continue;
}
F_114 ( V_2 ) ;
if ( V_2 -> V_14 == 0 )
break;
if ( F_119 ( V_174 , & V_2 -> V_14 ) != 0 )
break;
} while ( F_175 ( & V_2 -> V_178 ) > 1 );
return;
V_270:
F_107 ( V_165 L_12
L_13 , V_2 -> V_228 , - V_12 ) ;
F_25 ( V_2 ) ;
F_114 ( V_2 ) ;
}
static int V_179 ( void * V_274 )
{
struct V_1 * V_2 = V_274 ;
F_176 ( V_275 ) ;
F_172 ( V_2 ) ;
F_124 ( V_2 ) ;
F_177 ( 0 ) ;
return 0 ;
}
