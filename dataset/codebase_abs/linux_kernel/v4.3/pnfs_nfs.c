void F_1 ( void * V_1 )
{
struct V_2 * V_3 = V_1 ;
F_2 ( V_3 -> V_4 ) ;
V_3 -> V_5 -> V_6 ( V_1 ) ;
}
void F_3 ( struct V_7 * V_1 )
{
struct V_8 * V_9 = F_4 ( V_1 -> V_10 . V_11 ) ;
V_1 -> V_12 . V_13 = 0 ;
memcpy ( & V_1 -> V_14 . V_15 , & V_9 -> V_16 ,
sizeof( V_1 -> V_14 . V_15 ) ) ;
V_1 -> V_14 . V_15 . V_1 [ 0 ] ++ ;
}
void F_5 ( struct V_17 * V_12 , void * V_1 )
{
struct V_7 * V_18 = V_1 ;
V_18 -> V_5 -> V_19 ( V_12 , V_1 ) ;
}
void F_6 ( void * V_20 )
{
struct V_7 * V_1 = V_20 ;
V_1 -> V_21 -> V_22 ( V_1 ) ;
F_7 ( V_1 -> V_23 ) ;
F_2 ( V_1 -> V_4 ) ;
F_8 ( V_1 ) ;
}
void
F_9 ( struct V_8 * V_24 ,
struct V_25 * V_26 )
{
struct V_27 * V_28 = NULL ;
if ( ! F_10 ( V_29 , & V_24 -> V_30 ) )
goto V_31;
V_26 -> V_32 -> V_33 -- ;
if ( F_11 ( & V_24 -> V_34 ) ) {
struct V_35 * V_36 ;
V_36 = F_12 ( & V_24 -> V_34 ,
struct V_35 ,
V_37 ) ;
V_28 = V_36 -> V_38 ;
V_36 -> V_38 = NULL ;
}
V_31:
F_13 ( V_24 , V_26 ) ;
F_14 ( V_28 ) ;
}
static int
F_15 ( struct V_39 * V_40 , struct V_39 * V_41 ,
struct V_25 * V_26 , int V_42 )
{
struct V_8 * V_24 , * V_43 ;
int V_44 = 0 ;
F_16 (req, tmp, src, wb_list) {
if ( ! F_17 ( V_24 ) )
continue;
F_18 ( & V_24 -> V_45 ) ;
if ( F_19 ( V_26 -> V_46 ) )
F_20 ( V_24 , V_43 , V_34 ) ;
F_13 ( V_24 , V_26 ) ;
F_21 ( V_29 , & V_24 -> V_30 ) ;
F_22 ( V_24 , V_41 ) ;
V_44 ++ ;
if ( ( V_44 == V_42 ) && ! V_26 -> V_47 )
break;
}
return V_44 ;
}
static int
F_23 ( struct V_35 * V_36 ,
struct V_25 * V_26 ,
int V_42 )
{
struct V_39 * V_40 = & V_36 -> V_37 ;
struct V_39 * V_41 = & V_36 -> V_48 ;
int V_44 ;
F_24 ( V_26 -> V_46 ) ;
V_44 = F_15 ( V_40 , V_41 , V_26 , V_42 ) ;
if ( V_44 ) {
V_26 -> V_32 -> V_33 -= V_44 ;
V_26 -> V_32 -> V_49 += V_44 ;
if ( V_36 -> V_50 == NULL )
V_36 -> V_50 = F_25 ( V_36 -> V_38 ) ;
if ( F_26 ( V_40 ) ) {
F_14 ( V_36 -> V_38 ) ;
V_36 -> V_38 = NULL ;
}
}
return V_44 ;
}
int F_27 ( struct V_25 * V_26 ,
int V_42 )
{
int V_51 , V_52 = 0 , V_53 ;
F_24 ( V_26 -> V_46 ) ;
for ( V_51 = 0 ; V_51 < V_26 -> V_32 -> V_54 && V_42 != 0 ; V_51 ++ ) {
V_53 = F_23 ( & V_26 -> V_32 -> V_55 [ V_51 ] ,
V_26 , V_42 ) ;
V_42 -= V_53 ;
V_52 += V_53 ;
}
return V_52 ;
}
void F_28 ( struct V_39 * V_41 ,
struct V_25 * V_26 )
{
struct V_35 * V_56 ;
struct V_27 * V_28 ;
int V_51 ;
F_24 ( V_26 -> V_46 ) ;
V_57:
for ( V_51 = 0 , V_56 = V_26 -> V_32 -> V_55 ; V_51 < V_26 -> V_32 -> V_54 ; V_51 ++ , V_56 ++ ) {
if ( F_15 ( & V_56 -> V_37 , V_41 ,
V_26 , 0 ) ) {
V_28 = V_56 -> V_38 ;
V_56 -> V_38 = NULL ;
F_29 ( V_26 -> V_46 ) ;
F_7 ( V_28 ) ;
F_30 ( V_26 -> V_46 ) ;
goto V_57;
}
}
V_26 -> V_32 -> V_33 = 0 ;
}
static void F_31 ( struct V_25 * V_26 , int V_58 )
{
struct V_59 * V_60 = V_26 -> V_32 ;
struct V_35 * V_36 ;
struct V_27 * V_28 ;
F_32 ( V_10 ) ;
int V_51 ;
F_30 ( V_26 -> V_46 ) ;
for ( V_51 = V_58 ; V_51 < V_60 -> V_54 ; V_51 ++ ) {
V_36 = & V_60 -> V_55 [ V_51 ] ;
if ( F_26 ( & V_36 -> V_48 ) )
continue;
V_28 = V_36 -> V_50 ;
V_36 -> V_50 = NULL ;
F_33 ( & V_36 -> V_48 , & V_10 ) ;
F_29 ( V_26 -> V_46 ) ;
F_34 ( & V_10 , V_28 , V_26 , V_51 ) ;
F_7 ( V_28 ) ;
F_30 ( V_26 -> V_46 ) ;
}
F_29 ( V_26 -> V_46 ) ;
}
static unsigned int
F_35 ( struct V_25 * V_26 ,
struct V_39 * V_61 )
{
struct V_59 * V_60 ;
struct V_35 * V_36 ;
struct V_7 * V_1 ;
int V_51 ;
unsigned int V_62 = 0 ;
V_60 = V_26 -> V_32 ;
V_36 = V_60 -> V_55 ;
for ( V_51 = 0 ; V_51 < V_60 -> V_54 ; V_51 ++ , V_36 ++ ) {
if ( F_26 ( & V_36 -> V_48 ) )
continue;
V_1 = F_36 () ;
if ( ! V_1 )
break;
V_1 -> V_63 = V_51 ;
F_37 ( & V_1 -> V_10 , V_61 ) ;
V_62 ++ ;
}
F_31 ( V_26 , V_51 ) ;
return V_62 ;
}
static inline
void F_38 ( struct V_39 * V_10 ,
struct V_7 * V_1 ,
struct V_25 * V_26 )
{
struct V_35 * V_36 ;
V_36 = & V_26 -> V_32 -> V_55 [ V_1 -> V_63 ] ;
F_30 ( V_26 -> V_46 ) ;
F_33 ( & V_36 -> V_48 , V_10 ) ;
V_1 -> V_23 = V_36 -> V_50 ;
V_36 -> V_50 = NULL ;
F_29 ( V_26 -> V_46 ) ;
}
int
F_39 ( struct V_64 * V_64 , struct V_39 * V_65 ,
int V_66 , struct V_25 * V_26 ,
int (* F_40)( struct V_7 * V_1 ,
int V_66 ) )
{
struct V_7 * V_1 , * V_43 ;
F_32 ( V_61 ) ;
unsigned int V_62 = 0 ;
if ( ! F_26 ( V_65 ) ) {
V_1 = F_36 () ;
if ( V_1 != NULL ) {
V_1 -> V_63 = - 1 ;
F_37 ( & V_1 -> V_10 , & V_61 ) ;
V_62 ++ ;
} else {
F_34 ( V_65 , NULL , V_26 , 0 ) ;
F_31 ( V_26 , 0 ) ;
V_26 -> V_21 -> V_67 ( F_41 ( V_64 ) ) ;
return - V_68 ;
}
}
V_62 += F_35 ( V_26 , & V_61 ) ;
if ( V_62 == 0 ) {
V_26 -> V_21 -> V_67 ( F_41 ( V_64 ) ) ;
goto V_31;
}
F_42 ( V_62 , & V_26 -> V_69 -> V_70 ) ;
F_16 (data, tmp, &list, pages) {
F_43 ( & V_1 -> V_10 ) ;
if ( V_1 -> V_63 < 0 ) {
F_44 ( V_1 , V_65 , NULL , V_26 ) ;
F_45 ( F_46 ( V_64 ) , V_1 ,
F_47 ( V_1 -> V_64 ) ,
V_1 -> V_5 , V_66 , 0 ) ;
} else {
F_32 ( V_10 ) ;
F_38 ( & V_10 , V_1 , V_26 ) ;
F_44 ( V_1 , & V_10 , V_1 -> V_23 , V_26 ) ;
F_40 ( V_1 , V_66 ) ;
}
}
V_31:
V_26 -> V_32 -> V_49 = 0 ;
return V_71 ;
}
static void
F_48 ( struct V_72 * V_32 )
{
if ( V_32 == NULL ) {
F_49 ( V_73 L_1 , V_74 ) ;
return;
}
F_49 ( V_73 L_2
L_3
L_4
L_5 ,
V_32 -> V_75 ,
F_50 ( & V_32 -> V_76 ) , V_32 -> V_4 ,
V_32 -> V_4 ? V_32 -> V_4 -> V_77 : 0 ) ;
}
static bool
F_51 ( struct V_78 * V_79 , struct V_78 * V_80 )
{
struct V_81 * V_82 , * V_56 ;
struct V_83 * V_84 , * V_85 ;
if ( V_79 -> V_86 != V_80 -> V_86 )
return false ;
switch ( V_79 -> V_86 ) {
case V_87 :
V_82 = (struct V_81 * ) V_79 ;
V_56 = (struct V_81 * ) V_80 ;
if ( V_82 -> V_88 . V_89 == V_56 -> V_88 . V_89 &&
V_82 -> V_90 == V_56 -> V_90 )
return true ;
break;
case V_91 :
V_84 = (struct V_83 * ) V_79 ;
V_85 = (struct V_83 * ) V_80 ;
if ( F_52 ( & V_84 -> V_92 ) ==
V_93 &&
V_84 -> V_94 != V_85 -> V_94 )
return false ;
if ( F_53 ( & V_84 -> V_92 , & V_85 -> V_92 ) &&
V_84 -> V_95 == V_85 -> V_95 )
return true ;
break;
default:
F_54 ( L_6 ,
V_74 , V_79 -> V_86 ) ;
return false ;
}
return false ;
}
static bool
F_55 ( const struct V_39 * V_96 ,
const struct V_39 * V_97 )
{
struct V_98 * V_99 , * V_100 ;
struct V_78 * V_101 , * V_102 ;
bool V_103 = false ;
F_56 (da1, dsaddrs1, da_node) {
V_101 = (struct V_78 * ) & V_99 -> V_104 ;
V_103 = false ;
F_56 (da2, dsaddrs2, da_node) {
V_102 = (struct V_78 * ) & V_100 -> V_104 ;
V_103 = F_51 ( V_101 , V_102 ) ;
if ( V_103 )
break;
}
if ( ! V_103 )
break;
}
return V_103 ;
}
static struct V_72 *
F_57 ( const struct V_39 * V_105 )
{
struct V_72 * V_32 ;
F_56 (ds, &nfs4_data_server_cache, ds_node)
if ( F_55 ( & V_32 -> V_106 , V_105 ) )
return V_32 ;
return NULL ;
}
static void F_58 ( struct V_72 * V_32 )
{
struct V_98 * V_107 ;
F_54 ( L_7 , V_74 ) ;
F_59 (FACILITY)
F_48 ( V_32 ) ;
F_2 ( V_32 -> V_4 ) ;
while ( ! F_26 ( & V_32 -> V_106 ) ) {
V_107 = F_12 ( & V_32 -> V_106 ,
struct V_98 ,
V_108 ) ;
F_43 ( & V_107 -> V_108 ) ;
F_60 ( V_107 -> V_109 ) ;
F_60 ( V_107 ) ;
}
F_60 ( V_32 -> V_75 ) ;
F_60 ( V_32 ) ;
}
void F_61 ( struct V_72 * V_32 )
{
if ( F_62 ( & V_32 -> V_76 ,
& V_110 ) ) {
F_43 ( & V_32 -> V_111 ) ;
F_29 ( & V_110 ) ;
F_58 ( V_32 ) ;
}
}
static char *
F_63 ( struct V_39 * V_105 , T_1 V_112 )
{
struct V_98 * V_107 ;
char * V_113 ;
T_2 V_114 ;
char * V_115 ;
V_114 = 3 ;
F_56 (da, dsaddrs, da_node) {
V_114 += strlen ( V_107 -> V_109 ) + 1 ;
}
V_113 = F_64 ( V_114 , V_112 ) ;
if ( ! V_113 )
return NULL ;
V_115 = V_113 ;
* ( V_115 ++ ) = '{' ;
V_114 -- ;
F_56 (da, dsaddrs, da_node) {
T_2 V_116 = strlen ( V_107 -> V_109 ) ;
if ( V_116 > V_114 )
goto V_117;
memcpy ( V_115 , V_107 -> V_109 , V_116 ) ;
V_115 += V_116 ;
V_114 -= V_116 ;
if ( V_114 < 1 )
goto V_117;
( * V_115 ++ ) = ',' ;
V_114 -- ;
}
if ( V_114 < 2 )
goto V_117;
* ( V_115 ++ ) = '}' ;
* V_115 = '\0' ;
return V_113 ;
V_117:
F_60 ( V_113 ) ;
return NULL ;
}
struct V_72 *
F_65 ( struct V_39 * V_105 , T_1 V_112 )
{
struct V_72 * V_118 , * V_32 = NULL ;
char * V_113 ;
if ( F_26 ( V_105 ) ) {
F_54 ( L_8 , V_74 ) ;
goto V_31;
}
V_32 = F_64 ( sizeof( * V_32 ) , V_112 ) ;
if ( ! V_32 )
goto V_31;
V_113 = F_63 ( V_105 , V_112 ) ;
F_30 ( & V_110 ) ;
V_118 = F_57 ( V_105 ) ;
if ( V_118 == NULL ) {
F_66 ( & V_32 -> V_106 ) ;
F_33 ( V_105 , & V_32 -> V_106 ) ;
V_32 -> V_75 = V_113 ;
F_67 ( & V_32 -> V_76 , 1 ) ;
F_66 ( & V_32 -> V_111 ) ;
V_32 -> V_4 = NULL ;
F_37 ( & V_32 -> V_111 , & V_119 ) ;
F_54 ( L_9 , V_74 ,
V_32 -> V_75 ) ;
} else {
F_60 ( V_113 ) ;
F_60 ( V_32 ) ;
F_68 ( & V_118 -> V_76 ) ;
F_54 ( L_10 ,
V_74 , V_118 -> V_75 ,
F_50 ( & V_118 -> V_76 ) ) ;
V_32 = V_118 ;
}
F_29 ( & V_110 ) ;
V_31:
return V_32 ;
}
static void F_69 ( struct V_72 * V_32 )
{
F_70 () ;
F_71 ( & V_32 -> V_120 , V_121 ,
V_122 ) ;
}
static void F_72 ( struct V_72 * V_32 )
{
F_73 () ;
F_21 ( V_121 , & V_32 -> V_120 ) ;
F_74 () ;
F_75 ( & V_32 -> V_120 , V_121 ) ;
}
static bool F_76 ( void )
{
if ( ! V_123 ) {
V_123 = F_77 ( V_124 ) ;
F_78 ( ! V_123 ) ;
}
return ( V_123 != NULL ) ;
}
void F_79 ( void )
{
if ( V_123 ) {
F_80 ( V_124 ) ;
V_123 = NULL ;
}
}
static int F_81 ( struct V_125 * V_126 ,
struct V_72 * V_32 ,
unsigned int V_127 ,
unsigned int V_128 ,
T_3 V_129 )
{
struct V_130 * V_131 = F_82 ( - V_132 ) ;
struct V_98 * V_107 ;
int V_133 = 0 ;
F_54 ( L_11 , V_74 ,
V_32 -> V_75 , V_129 ) ;
if ( ! F_76 () )
goto V_31;
F_56 (da, &ds->ds_addrs, da_node) {
F_54 ( L_12 ,
V_74 , V_32 -> V_75 , V_107 -> V_109 ) ;
V_131 = V_123 ( V_126 -> V_130 ,
(struct V_78 * ) & V_107 -> V_104 ,
V_107 -> V_134 , V_135 ,
V_127 , V_128 , V_129 ) ;
if ( ! F_83 ( V_131 ) )
break;
}
if ( F_83 ( V_131 ) ) {
V_133 = F_84 ( V_131 ) ;
goto V_31;
}
F_85 () ;
V_32 -> V_4 = V_131 ;
F_54 ( L_13 , V_74 , V_32 -> V_75 ) ;
V_31:
return V_133 ;
}
static int F_86 ( struct V_125 * V_126 ,
struct V_72 * V_32 ,
unsigned int V_127 ,
unsigned int V_128 ,
T_4 V_136 ,
T_3 V_129 )
{
struct V_130 * V_131 = F_82 ( - V_132 ) ;
struct V_98 * V_107 ;
int V_133 = 0 ;
F_54 ( L_11 , V_74 , V_32 -> V_75 ,
V_129 ) ;
F_56 (da, &ds->ds_addrs, da_node) {
F_54 ( L_12 ,
V_74 , V_32 -> V_75 , V_107 -> V_109 ) ;
V_131 = F_87 ( V_126 -> V_130 ,
(struct V_78 * ) & V_107 -> V_104 ,
V_107 -> V_134 , V_135 ,
V_127 , V_128 , V_136 ,
V_129 ) ;
if ( ! F_83 ( V_131 ) )
break;
}
if ( F_83 ( V_131 ) ) {
V_133 = F_84 ( V_131 ) ;
goto V_31;
}
V_133 = F_88 ( V_131 , V_126 -> V_130 -> V_137 ) ;
if ( V_133 )
goto V_138;
F_85 () ;
V_32 -> V_4 = V_131 ;
F_54 ( L_13 , V_74 , V_32 -> V_75 ) ;
V_31:
return V_133 ;
V_138:
F_2 ( V_131 ) ;
goto V_31;
}
void F_89 ( struct V_125 * V_126 , struct V_72 * V_32 ,
struct V_139 * V_140 , unsigned int V_127 ,
unsigned int V_128 , T_4 V_141 ,
T_4 V_136 , T_3 V_129 )
{
if ( F_90 ( V_121 , & V_32 -> V_120 ) == 0 ) {
int V_142 = 0 ;
if ( V_141 == 3 ) {
V_142 = F_81 ( V_126 , V_32 , V_127 ,
V_128 , V_129 ) ;
} else if ( V_141 == 4 ) {
V_142 = F_86 ( V_126 , V_32 , V_127 ,
V_128 , V_136 ,
V_129 ) ;
} else {
F_54 ( L_14 , V_74 ,
V_141 ) ;
V_142 = - V_143 ;
}
if ( V_142 )
F_91 ( V_140 ) ;
F_72 ( V_32 ) ;
} else {
F_69 ( V_32 ) ;
}
}
struct V_98 *
F_92 ( struct V_144 * V_144 , struct V_145 * V_146 , T_1 V_112 )
{
struct V_98 * V_107 = NULL ;
char * V_147 , * V_148 ;
T_5 V_149 ;
int V_150 , V_151 ;
int V_43 [ 2 ] ;
T_6 * V_115 ;
char * V_152 , * V_153 ;
T_2 V_114 , V_154 ;
char * V_155 = L_15 ;
char * V_156 = L_15 ;
V_115 = F_93 ( V_146 , 4 ) ;
if ( F_94 ( ! V_115 ) )
goto V_117;
V_150 = F_95 ( V_115 ++ ) ;
V_115 = F_93 ( V_146 , V_150 ) ;
if ( F_94 ( ! V_115 ) )
goto V_117;
V_152 = F_96 ( V_150 + 1 , V_112 ) ;
if ( F_94 ( ! V_152 ) )
goto V_117;
V_152 [ V_150 ] = '\0' ;
memcpy ( V_152 , V_115 , V_150 ) ;
V_115 = F_93 ( V_146 , 4 ) ;
if ( F_94 ( ! V_115 ) )
goto V_157;
V_151 = F_95 ( V_115 ) ;
V_115 = F_93 ( V_146 , V_151 ) ;
if ( F_94 ( ! V_115 ) )
goto V_157;
if ( V_151 > V_158 + V_159 + 8 ) {
F_54 ( L_16 , V_74 ,
V_151 ) ;
goto V_157;
}
V_147 = F_96 ( V_151 + 1 , V_112 ) ;
if ( ! V_147 ) {
F_54 ( L_17 , V_74 ) ;
goto V_157;
}
V_147 [ V_151 ] = '\0' ;
memcpy ( V_147 , V_115 , V_151 ) ;
V_148 = strrchr ( V_147 , '.' ) ;
if ( ! V_148 ) {
F_54 ( L_18 ,
V_74 ) ;
goto V_160;
}
* V_148 = '-' ;
V_148 = strrchr ( V_147 , '.' ) ;
if ( ! V_148 ) {
F_54 ( L_19
L_20 , V_74 ) ;
goto V_160;
}
* V_148 = '\0' ;
V_107 = F_64 ( sizeof( * V_107 ) , V_112 ) ;
if ( F_94 ( ! V_107 ) )
goto V_160;
F_66 ( & V_107 -> V_108 ) ;
if ( ! F_97 ( V_144 , V_147 , V_148 - V_147 , (struct V_78 * ) & V_107 -> V_104 ,
sizeof( V_107 -> V_104 ) ) ) {
F_54 ( L_21 , V_74 , V_147 ) ;
goto V_161;
}
V_148 ++ ;
sscanf ( V_148 , L_22 , & V_43 [ 0 ] , & V_43 [ 1 ] ) ;
V_149 = F_98 ( ( V_43 [ 0 ] << 8 ) | ( V_43 [ 1 ] ) ) ;
switch ( V_107 -> V_104 . V_162 ) {
case V_87 :
( (struct V_81 * ) & V_107 -> V_104 ) -> V_90 = V_149 ;
V_107 -> V_134 = sizeof( struct V_81 ) ;
V_153 = L_23 ;
V_154 = 3 ;
break;
case V_91 :
( (struct V_83 * ) & V_107 -> V_104 ) -> V_95 = V_149 ;
V_107 -> V_134 = sizeof( struct V_83 ) ;
V_153 = L_24 ;
V_154 = 4 ;
V_155 = L_25 ;
V_156 = L_26 ;
break;
default:
F_54 ( L_27 ,
V_74 , V_107 -> V_104 . V_162 ) ;
goto V_161;
}
if ( V_150 != V_154 || strncmp ( V_152 , V_153 , V_150 ) ) {
F_54 ( L_28 ,
V_74 , V_152 , V_153 ) ;
goto V_161;
}
V_114 = strlen ( V_155 ) + strlen ( V_147 ) + strlen ( V_156 ) + 7 ;
V_107 -> V_109 = F_64 ( V_114 , V_112 ) ;
if ( V_107 -> V_109 )
snprintf ( V_107 -> V_109 , V_114 , L_29 , V_155 ,
V_147 , V_156 , F_99 ( V_149 ) ) ;
F_54 ( L_30 , V_74 , V_107 -> V_109 ) ;
F_60 ( V_147 ) ;
F_60 ( V_152 ) ;
return V_107 ;
V_161:
F_60 ( V_107 ) ;
V_160:
F_54 ( L_31 , V_74 , V_147 ) ;
F_60 ( V_147 ) ;
V_157:
F_60 ( V_152 ) ;
V_117:
return NULL ;
}
void
F_100 ( struct V_8 * V_24 ,
struct V_27 * V_23 ,
struct V_25 * V_26 ,
T_4 V_163 )
{
struct V_39 * V_61 ;
struct V_35 * V_55 ;
F_30 ( V_26 -> V_46 ) ;
V_55 = V_26 -> V_32 -> V_55 ;
V_61 = & V_55 [ V_163 ] . V_37 ;
if ( F_26 ( V_61 ) ) {
F_78 ( V_55 [ V_163 ] . V_38 != NULL ) ;
V_55 [ V_163 ] . V_38 = F_25 ( V_23 ) ;
}
F_101 ( V_29 , & V_24 -> V_30 ) ;
V_26 -> V_32 -> V_33 ++ ;
F_102 ( V_24 , V_61 , V_26 ) ;
F_29 ( V_26 -> V_46 ) ;
F_103 ( V_24 -> V_164 , V_26 ) ;
}
int
F_104 ( struct V_64 * V_64 , bool V_165 )
{
if ( V_165 )
return 0 ;
return F_105 ( V_64 , true ) ;
}
