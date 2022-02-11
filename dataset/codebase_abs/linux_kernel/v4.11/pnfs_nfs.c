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
if ( F_19 ( & V_26 -> V_46 -> V_47 ) )
F_20 ( V_24 , V_43 , V_34 ) ;
F_13 ( V_24 , V_26 ) ;
F_21 ( V_29 , & V_24 -> V_30 ) ;
F_22 ( V_24 , V_41 ) ;
V_44 ++ ;
if ( ( V_44 == V_42 ) && ! V_26 -> V_48 )
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
struct V_39 * V_41 = & V_36 -> V_49 ;
int V_44 ;
F_24 ( & V_26 -> V_46 -> V_47 ) ;
V_44 = F_15 ( V_40 , V_41 , V_26 , V_42 ) ;
if ( V_44 ) {
V_26 -> V_32 -> V_33 -= V_44 ;
V_26 -> V_32 -> V_50 += V_44 ;
if ( V_36 -> V_51 == NULL )
V_36 -> V_51 = F_25 ( V_36 -> V_38 ) ;
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
int V_52 , V_53 = 0 , V_54 ;
F_24 ( & V_26 -> V_46 -> V_47 ) ;
for ( V_52 = 0 ; V_52 < V_26 -> V_32 -> V_55 && V_42 != 0 ; V_52 ++ ) {
V_54 = F_23 ( & V_26 -> V_32 -> V_56 [ V_52 ] ,
V_26 , V_42 ) ;
V_42 -= V_54 ;
V_53 += V_54 ;
}
return V_53 ;
}
void F_28 ( struct V_39 * V_41 ,
struct V_25 * V_26 )
{
struct V_35 * V_57 ;
struct V_27 * V_28 ;
int V_52 ;
F_24 ( & V_26 -> V_46 -> V_47 ) ;
V_58:
for ( V_52 = 0 , V_57 = V_26 -> V_32 -> V_56 ; V_52 < V_26 -> V_32 -> V_55 ; V_52 ++ , V_57 ++ ) {
if ( F_15 ( & V_57 -> V_37 , V_41 ,
V_26 , 0 ) ) {
V_28 = V_57 -> V_38 ;
V_57 -> V_38 = NULL ;
F_29 ( & V_26 -> V_46 -> V_47 ) ;
F_7 ( V_28 ) ;
F_30 ( & V_26 -> V_46 -> V_47 ) ;
goto V_58;
}
}
V_26 -> V_32 -> V_33 = 0 ;
}
static void F_31 ( struct V_25 * V_26 , int V_59 )
{
struct V_60 * V_61 = V_26 -> V_32 ;
struct V_35 * V_36 ;
struct V_27 * V_28 ;
F_32 ( V_10 ) ;
int V_52 ;
F_30 ( & V_26 -> V_46 -> V_47 ) ;
for ( V_52 = V_59 ; V_52 < V_61 -> V_55 ; V_52 ++ ) {
V_36 = & V_61 -> V_56 [ V_52 ] ;
if ( F_26 ( & V_36 -> V_49 ) )
continue;
V_28 = V_36 -> V_51 ;
V_36 -> V_51 = NULL ;
F_33 ( & V_36 -> V_49 , & V_10 ) ;
F_29 ( & V_26 -> V_46 -> V_47 ) ;
F_34 ( & V_10 , V_28 , V_26 , V_52 ) ;
F_7 ( V_28 ) ;
F_30 ( & V_26 -> V_46 -> V_47 ) ;
}
F_29 ( & V_26 -> V_46 -> V_47 ) ;
}
static unsigned int
F_35 ( struct V_25 * V_26 ,
struct V_39 * V_62 )
{
struct V_60 * V_61 ;
struct V_35 * V_36 ;
struct V_7 * V_1 ;
int V_52 ;
unsigned int V_63 = 0 ;
V_61 = V_26 -> V_32 ;
V_36 = V_61 -> V_56 ;
for ( V_52 = 0 ; V_52 < V_61 -> V_55 ; V_52 ++ , V_36 ++ ) {
if ( F_26 ( & V_36 -> V_49 ) )
continue;
V_1 = F_36 () ;
if ( ! V_1 )
break;
V_1 -> V_64 = V_52 ;
F_37 ( & V_1 -> V_10 , V_62 ) ;
V_63 ++ ;
}
F_31 ( V_26 , V_52 ) ;
return V_63 ;
}
static inline
void F_38 ( struct V_39 * V_10 ,
struct V_7 * V_1 ,
struct V_25 * V_26 )
{
struct V_35 * V_36 ;
V_36 = & V_26 -> V_32 -> V_56 [ V_1 -> V_64 ] ;
F_30 ( & V_26 -> V_46 -> V_47 ) ;
F_33 ( & V_36 -> V_49 , V_10 ) ;
V_1 -> V_23 = V_36 -> V_51 ;
V_36 -> V_51 = NULL ;
F_29 ( & V_26 -> V_46 -> V_47 ) ;
}
static bool
F_39 ( struct V_39 * V_10 ,
struct V_7 * V_1 ,
struct V_25 * V_26 )
{
if ( F_26 ( V_10 ) ) {
if ( F_40 ( & V_26 -> V_65 -> V_66 ) )
F_41 ( & V_26 -> V_65 -> V_66 ) ;
F_42 ( V_1 -> V_67 ) ;
F_43 ( V_1 ) ;
return true ;
}
return false ;
}
int
F_44 ( struct V_46 * V_46 , struct V_39 * V_68 ,
int V_69 , struct V_25 * V_26 ,
int (* F_45)( struct V_7 * V_1 ,
int V_69 ) )
{
struct V_7 * V_1 , * V_43 ;
F_32 ( V_62 ) ;
unsigned int V_63 = 0 ;
if ( ! F_26 ( V_68 ) ) {
V_1 = F_36 () ;
if ( V_1 != NULL ) {
V_1 -> V_64 = - 1 ;
F_37 ( & V_1 -> V_10 , & V_62 ) ;
V_63 ++ ;
} else {
F_34 ( V_68 , NULL , V_26 , 0 ) ;
F_31 ( V_26 , 0 ) ;
return - V_70 ;
}
}
V_63 += F_35 ( V_26 , & V_62 ) ;
if ( V_63 == 0 )
goto V_31;
F_46 ( V_63 , & V_26 -> V_65 -> V_66 ) ;
F_16 (data, tmp, &list, pages) {
F_47 ( & V_1 -> V_10 ) ;
if ( V_1 -> V_64 < 0 ) {
if ( F_39 ( V_68 ,
V_1 , V_26 ) )
continue;
F_48 ( V_1 , V_68 , NULL , V_26 ) ;
F_49 ( F_50 ( V_46 ) , V_1 ,
F_51 ( V_1 -> V_46 ) ,
V_1 -> V_5 , V_69 , 0 ) ;
} else {
F_32 ( V_10 ) ;
F_38 ( & V_10 , V_1 , V_26 ) ;
if ( F_39 ( & V_10 ,
V_1 , V_26 ) )
continue;
F_48 ( V_1 , & V_10 , V_1 -> V_23 , V_26 ) ;
F_45 ( V_1 , V_69 ) ;
}
}
V_31:
V_26 -> V_32 -> V_50 = 0 ;
return V_71 ;
}
static void
F_52 ( struct V_72 * V_32 )
{
if ( V_32 == NULL ) {
F_53 ( V_73 L_1 , V_74 ) ;
return;
}
F_53 ( V_73 L_2
L_3
L_4
L_5 ,
V_32 -> V_75 ,
F_54 ( & V_32 -> V_76 ) , V_32 -> V_4 ,
V_32 -> V_4 ? V_32 -> V_4 -> V_77 : 0 ) ;
}
static bool
F_55 ( struct V_78 * V_79 , struct V_78 * V_80 )
{
struct V_81 * V_82 , * V_57 ;
struct V_83 * V_84 , * V_85 ;
if ( V_79 -> V_86 != V_80 -> V_86 )
return false ;
switch ( V_79 -> V_86 ) {
case V_87 :
V_82 = (struct V_81 * ) V_79 ;
V_57 = (struct V_81 * ) V_80 ;
if ( V_82 -> V_88 . V_89 == V_57 -> V_88 . V_89 &&
V_82 -> V_90 == V_57 -> V_90 )
return true ;
break;
case V_91 :
V_84 = (struct V_83 * ) V_79 ;
V_85 = (struct V_83 * ) V_80 ;
if ( F_56 ( & V_84 -> V_92 ) ==
V_93 &&
V_84 -> V_94 != V_85 -> V_94 )
return false ;
if ( F_57 ( & V_84 -> V_92 , & V_85 -> V_92 ) &&
V_84 -> V_95 == V_85 -> V_95 )
return true ;
break;
default:
F_58 ( L_6 ,
V_74 , V_79 -> V_86 ) ;
return false ;
}
return false ;
}
static bool
F_59 ( const struct V_39 * V_96 ,
const struct V_39 * V_97 )
{
struct V_98 * V_99 , * V_100 ;
struct V_78 * V_101 , * V_102 ;
bool V_103 = false ;
F_60 (da1, dsaddrs1, da_node) {
V_101 = (struct V_78 * ) & V_99 -> V_104 ;
V_103 = false ;
F_60 (da2, dsaddrs2, da_node) {
V_102 = (struct V_78 * ) & V_100 -> V_104 ;
V_103 = F_55 ( V_101 , V_102 ) ;
if ( V_103 )
break;
}
if ( ! V_103 )
break;
}
return V_103 ;
}
static struct V_72 *
F_61 ( const struct V_39 * V_105 )
{
struct V_72 * V_32 ;
F_60 (ds, &nfs4_data_server_cache, ds_node)
if ( F_59 ( & V_32 -> V_106 , V_105 ) )
return V_32 ;
return NULL ;
}
static void F_62 ( struct V_72 * V_32 )
{
struct V_98 * V_107 ;
F_58 ( L_7 , V_74 ) ;
F_63 (FACILITY)
F_52 ( V_32 ) ;
F_2 ( V_32 -> V_4 ) ;
while ( ! F_26 ( & V_32 -> V_106 ) ) {
V_107 = F_12 ( & V_32 -> V_106 ,
struct V_98 ,
V_108 ) ;
F_47 ( & V_107 -> V_108 ) ;
F_64 ( V_107 -> V_109 ) ;
F_64 ( V_107 ) ;
}
F_64 ( V_32 -> V_75 ) ;
F_64 ( V_32 ) ;
}
void F_65 ( struct V_72 * V_32 )
{
if ( F_66 ( & V_32 -> V_76 ,
& V_110 ) ) {
F_47 ( & V_32 -> V_111 ) ;
F_29 ( & V_110 ) ;
F_62 ( V_32 ) ;
}
}
static char *
F_67 ( struct V_39 * V_105 , T_1 V_112 )
{
struct V_98 * V_107 ;
char * V_113 ;
T_2 V_114 ;
char * V_115 ;
V_114 = 3 ;
F_60 (da, dsaddrs, da_node) {
V_114 += strlen ( V_107 -> V_109 ) + 1 ;
}
V_113 = F_68 ( V_114 , V_112 ) ;
if ( ! V_113 )
return NULL ;
V_115 = V_113 ;
* ( V_115 ++ ) = '{' ;
V_114 -- ;
F_60 (da, dsaddrs, da_node) {
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
F_64 ( V_113 ) ;
return NULL ;
}
struct V_72 *
F_69 ( struct V_39 * V_105 , T_1 V_112 )
{
struct V_72 * V_118 , * V_32 = NULL ;
char * V_113 ;
if ( F_26 ( V_105 ) ) {
F_58 ( L_8 , V_74 ) ;
goto V_31;
}
V_32 = F_68 ( sizeof( * V_32 ) , V_112 ) ;
if ( ! V_32 )
goto V_31;
V_113 = F_67 ( V_105 , V_112 ) ;
F_30 ( & V_110 ) ;
V_118 = F_61 ( V_105 ) ;
if ( V_118 == NULL ) {
F_70 ( & V_32 -> V_106 ) ;
F_33 ( V_105 , & V_32 -> V_106 ) ;
V_32 -> V_75 = V_113 ;
F_71 ( & V_32 -> V_76 , 1 ) ;
F_70 ( & V_32 -> V_111 ) ;
V_32 -> V_4 = NULL ;
F_37 ( & V_32 -> V_111 , & V_119 ) ;
F_58 ( L_9 , V_74 ,
V_32 -> V_75 ) ;
} else {
F_64 ( V_113 ) ;
F_64 ( V_32 ) ;
F_72 ( & V_118 -> V_76 ) ;
F_58 ( L_10 ,
V_74 , V_118 -> V_75 ,
F_54 ( & V_118 -> V_76 ) ) ;
V_32 = V_118 ;
}
F_29 ( & V_110 ) ;
V_31:
return V_32 ;
}
static void F_73 ( struct V_72 * V_32 )
{
F_74 () ;
F_75 ( & V_32 -> V_120 , V_121 ,
V_122 ) ;
}
static void F_76 ( struct V_72 * V_32 )
{
F_77 () ;
F_21 ( V_121 , & V_32 -> V_120 ) ;
F_78 () ;
F_79 ( & V_32 -> V_120 , V_121 ) ;
}
static bool F_80 ( void )
{
if ( ! V_123 ) {
V_123 = F_81 ( V_124 ) ;
F_42 ( ! V_123 ) ;
}
return ( V_123 != NULL ) ;
}
void F_82 ( void )
{
if ( V_123 ) {
F_83 ( V_124 ) ;
V_123 = NULL ;
}
}
static int F_84 ( struct V_125 * V_126 ,
struct V_72 * V_32 ,
unsigned int V_127 ,
unsigned int V_128 )
{
struct V_129 * V_130 = F_85 ( - V_131 ) ;
struct V_98 * V_107 ;
int V_132 = 0 ;
F_58 ( L_11 , V_74 , V_32 -> V_75 ) ;
if ( ! F_80 () )
goto V_31;
F_60 (da, &ds->ds_addrs, da_node) {
F_58 ( L_12 ,
V_74 , V_32 -> V_75 , V_107 -> V_109 ) ;
if ( ! F_86 ( V_130 ) ) {
struct V_133 V_134 = {
. V_135 = V_136 ,
. V_137 = V_130 -> V_138 ,
. V_139 = (struct V_78 * ) & V_107 -> V_104 ,
. V_140 = V_107 -> V_141 ,
. V_142 = V_130 -> V_143 ,
} ;
F_87 ( V_130 -> V_144 , & V_134 ,
V_145 , NULL ) ;
} else
V_130 = V_123 ( V_126 ,
(struct V_78 * ) & V_107 -> V_104 ,
V_107 -> V_141 , V_146 ,
V_127 , V_128 ) ;
}
if ( F_86 ( V_130 ) ) {
V_132 = F_88 ( V_130 ) ;
goto V_31;
}
F_89 () ;
V_32 -> V_4 = V_130 ;
F_58 ( L_13 , V_74 , V_32 -> V_75 ) ;
V_31:
return V_132 ;
}
static int F_90 ( struct V_125 * V_126 ,
struct V_72 * V_32 ,
unsigned int V_127 ,
unsigned int V_128 ,
T_3 V_147 )
{
struct V_129 * V_130 = F_85 ( - V_131 ) ;
struct V_98 * V_107 ;
int V_132 = 0 ;
F_58 ( L_11 , V_74 , V_32 -> V_75 ) ;
F_60 (da, &ds->ds_addrs, da_node) {
F_58 ( L_12 ,
V_74 , V_32 -> V_75 , V_107 -> V_109 ) ;
if ( ! F_86 ( V_130 ) && V_130 -> V_148 -> V_149 ) {
struct V_133 V_134 = {
. V_135 = V_136 ,
. V_137 = V_130 -> V_138 ,
. V_139 = (struct V_78 * ) & V_107 -> V_104 ,
. V_140 = V_107 -> V_141 ,
. V_142 = V_130 -> V_143 ,
} ;
struct V_150 V_151 = {
. V_130 = V_130 ,
. V_152 = F_91 ( V_130 ) ,
} ;
struct V_153 V_154 = {
. V_155 = V_130 -> V_148 -> V_149 ,
. V_1 = & V_151 ,
} ;
F_87 ( V_130 -> V_144 , & V_134 ,
V_156 ,
& V_154 ) ;
if ( V_151 . V_152 )
F_92 ( V_151 . V_152 ) ;
} else {
V_130 = F_93 ( V_126 ,
(struct V_78 * ) & V_107 -> V_104 ,
V_107 -> V_141 , V_146 ,
V_127 , V_128 , V_147 ) ;
if ( F_86 ( V_130 ) )
continue;
V_132 = F_94 ( V_130 ,
V_126 -> V_129 -> V_157 ) ;
if ( V_132 ) {
F_2 ( V_130 ) ;
V_130 = F_85 ( - V_131 ) ;
continue;
}
}
}
if ( F_86 ( V_130 ) ) {
V_132 = F_88 ( V_130 ) ;
goto V_31;
}
F_89 () ;
V_32 -> V_4 = V_130 ;
F_58 ( L_13 , V_74 , V_32 -> V_75 ) ;
V_31:
return V_132 ;
}
int F_95 ( struct V_125 * V_126 , struct V_72 * V_32 ,
struct V_158 * V_159 , unsigned int V_127 ,
unsigned int V_128 , T_3 V_160 , T_3 V_147 )
{
int V_161 ;
V_162:
V_161 = 0 ;
if ( F_96 ( V_121 , & V_32 -> V_120 ) == 0 ) {
if ( V_160 == 3 ) {
V_161 = F_84 ( V_126 , V_32 , V_127 ,
V_128 ) ;
} else if ( V_160 == 4 ) {
V_161 = F_90 ( V_126 , V_32 , V_127 ,
V_128 , V_147 ) ;
} else {
F_58 ( L_14 , V_74 ,
V_160 ) ;
V_161 = - V_163 ;
}
F_76 ( V_32 ) ;
} else {
F_73 ( V_32 ) ;
if ( ! V_32 -> V_4 && ! F_97 ( V_159 ) )
goto V_162;
}
if ( ! V_161 ) {
if ( ! V_32 -> V_4 || ! F_98 ( V_32 -> V_4 ) ) {
F_42 ( V_32 -> V_4 ||
! F_97 ( V_159 ) ) ;
return - V_164 ;
}
V_161 = F_99 ( V_32 -> V_4 ) ;
}
return V_161 ;
}
struct V_98 *
F_100 ( struct V_137 * V_137 , struct V_165 * V_166 , T_1 V_112 )
{
struct V_98 * V_107 = NULL ;
char * V_167 , * V_168 ;
T_4 V_169 ;
int V_170 , V_171 ;
int V_43 [ 2 ] ;
T_5 * V_115 ;
char * V_172 , * V_173 ;
T_2 V_114 , V_174 ;
char * V_175 = L_15 ;
char * V_176 = L_15 ;
V_115 = F_101 ( V_166 , 4 ) ;
if ( F_102 ( ! V_115 ) )
goto V_117;
V_170 = F_103 ( V_115 ++ ) ;
V_115 = F_101 ( V_166 , V_170 ) ;
if ( F_102 ( ! V_115 ) )
goto V_117;
V_172 = F_104 ( V_170 + 1 , V_112 ) ;
if ( F_102 ( ! V_172 ) )
goto V_117;
V_172 [ V_170 ] = '\0' ;
memcpy ( V_172 , V_115 , V_170 ) ;
V_115 = F_101 ( V_166 , 4 ) ;
if ( F_102 ( ! V_115 ) )
goto V_177;
V_171 = F_103 ( V_115 ) ;
V_115 = F_101 ( V_166 , V_171 ) ;
if ( F_102 ( ! V_115 ) )
goto V_177;
if ( V_171 > V_178 + V_179 + 8 ) {
F_58 ( L_16 , V_74 ,
V_171 ) ;
goto V_177;
}
V_167 = F_104 ( V_171 + 1 , V_112 ) ;
if ( ! V_167 ) {
F_58 ( L_17 , V_74 ) ;
goto V_177;
}
V_167 [ V_171 ] = '\0' ;
memcpy ( V_167 , V_115 , V_171 ) ;
V_168 = strrchr ( V_167 , '.' ) ;
if ( ! V_168 ) {
F_58 ( L_18 ,
V_74 ) ;
goto V_180;
}
* V_168 = '-' ;
V_168 = strrchr ( V_167 , '.' ) ;
if ( ! V_168 ) {
F_58 ( L_19
L_20 , V_74 ) ;
goto V_180;
}
* V_168 = '\0' ;
V_107 = F_68 ( sizeof( * V_107 ) , V_112 ) ;
if ( F_102 ( ! V_107 ) )
goto V_180;
F_70 ( & V_107 -> V_108 ) ;
if ( ! F_105 ( V_137 , V_167 , V_168 - V_167 , (struct V_78 * ) & V_107 -> V_104 ,
sizeof( V_107 -> V_104 ) ) ) {
F_58 ( L_21 , V_74 , V_167 ) ;
goto V_181;
}
V_168 ++ ;
sscanf ( V_168 , L_22 , & V_43 [ 0 ] , & V_43 [ 1 ] ) ;
V_169 = F_106 ( ( V_43 [ 0 ] << 8 ) | ( V_43 [ 1 ] ) ) ;
switch ( V_107 -> V_104 . V_182 ) {
case V_87 :
( (struct V_81 * ) & V_107 -> V_104 ) -> V_90 = V_169 ;
V_107 -> V_141 = sizeof( struct V_81 ) ;
V_173 = L_23 ;
V_174 = 3 ;
break;
case V_91 :
( (struct V_83 * ) & V_107 -> V_104 ) -> V_95 = V_169 ;
V_107 -> V_141 = sizeof( struct V_83 ) ;
V_173 = L_24 ;
V_174 = 4 ;
V_175 = L_25 ;
V_176 = L_26 ;
break;
default:
F_58 ( L_27 ,
V_74 , V_107 -> V_104 . V_182 ) ;
goto V_181;
}
if ( V_170 != V_174 || strncmp ( V_172 , V_173 , V_170 ) ) {
F_58 ( L_28 ,
V_74 , V_172 , V_173 ) ;
goto V_181;
}
V_114 = strlen ( V_175 ) + strlen ( V_167 ) + strlen ( V_176 ) + 7 ;
V_107 -> V_109 = F_68 ( V_114 , V_112 ) ;
if ( V_107 -> V_109 )
snprintf ( V_107 -> V_109 , V_114 , L_29 , V_175 ,
V_167 , V_176 , F_107 ( V_169 ) ) ;
F_58 ( L_30 , V_74 , V_107 -> V_109 ) ;
F_64 ( V_167 ) ;
F_64 ( V_172 ) ;
return V_107 ;
V_181:
F_64 ( V_107 ) ;
V_180:
F_58 ( L_31 , V_74 , V_167 ) ;
F_64 ( V_167 ) ;
V_177:
F_64 ( V_172 ) ;
V_117:
return NULL ;
}
void
F_108 ( struct V_8 * V_24 ,
struct V_27 * V_23 ,
struct V_25 * V_26 ,
T_3 V_183 )
{
struct V_39 * V_62 ;
struct V_35 * V_56 ;
F_30 ( & V_26 -> V_46 -> V_47 ) ;
V_56 = V_26 -> V_32 -> V_56 ;
V_62 = & V_56 [ V_183 ] . V_37 ;
if ( F_26 ( V_62 ) ) {
if ( ! F_109 ( V_23 ) ) {
F_29 ( & V_26 -> V_46 -> V_47 ) ;
V_26 -> V_21 -> V_184 ( V_26 , V_24 ) ;
return;
}
F_42 ( V_56 [ V_183 ] . V_38 != NULL ) ;
V_56 [ V_183 ] . V_38 = F_25 ( V_23 ) ;
}
F_110 ( V_29 , & V_24 -> V_30 ) ;
V_26 -> V_32 -> V_33 ++ ;
F_111 ( V_24 , V_62 , V_26 ) ;
F_29 ( & V_26 -> V_46 -> V_47 ) ;
F_112 ( V_24 -> V_185 , V_26 ) ;
}
int
F_113 ( struct V_46 * V_46 , bool V_186 )
{
int V_44 ;
if ( ! F_114 ( V_46 ) )
return 0 ;
V_44 = F_115 ( V_46 , V_187 ) ;
if ( V_44 < 0 )
return V_44 ;
if ( V_186 )
return 0 ;
return F_116 ( V_46 , true ) ;
}
