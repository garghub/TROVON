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
if ( V_36 -> V_51 && ! F_36 ( V_36 -> V_51 ) &&
! F_37 ( V_64 , & V_36 -> V_51 -> V_65 ) )
break;
V_1 = F_38 ( false ) ;
if ( ! V_1 )
break;
V_1 -> V_66 = V_52 ;
F_39 ( & V_1 -> V_10 , V_62 ) ;
V_63 ++ ;
}
F_31 ( V_26 , V_52 ) ;
return V_63 ;
}
static inline
void F_40 ( struct V_39 * V_10 ,
struct V_7 * V_1 ,
struct V_25 * V_26 )
{
struct V_35 * V_36 ;
V_36 = & V_26 -> V_32 -> V_56 [ V_1 -> V_66 ] ;
F_30 ( & V_26 -> V_46 -> V_47 ) ;
F_33 ( & V_36 -> V_49 , V_10 ) ;
V_1 -> V_23 = V_36 -> V_51 ;
V_36 -> V_51 = NULL ;
F_29 ( & V_26 -> V_46 -> V_47 ) ;
}
static bool
F_41 ( struct V_39 * V_10 ,
struct V_7 * V_1 ,
struct V_25 * V_26 )
{
if ( F_26 ( V_10 ) ) {
if ( F_42 ( & V_26 -> V_67 -> V_68 ) )
F_43 ( & V_26 -> V_67 -> V_68 ) ;
F_44 ( V_1 -> V_69 ) ;
F_45 ( V_1 ) ;
return true ;
}
return false ;
}
int
F_46 ( struct V_46 * V_46 , struct V_39 * V_70 ,
int V_71 , struct V_25 * V_26 ,
int (* F_47)( struct V_7 * V_1 ,
int V_71 ) )
{
struct V_7 * V_1 , * V_43 ;
F_32 ( V_62 ) ;
unsigned int V_63 = 0 ;
if ( ! F_26 ( V_70 ) ) {
V_1 = F_38 ( true ) ;
V_1 -> V_66 = - 1 ;
F_39 ( & V_1 -> V_10 , & V_62 ) ;
V_63 ++ ;
}
V_63 += F_35 ( V_26 , & V_62 ) ;
if ( V_63 == 0 )
goto V_31;
F_48 ( V_63 , & V_26 -> V_67 -> V_68 ) ;
F_16 (data, tmp, &list, pages) {
F_49 ( & V_1 -> V_10 ) ;
if ( V_1 -> V_66 < 0 ) {
if ( F_41 ( V_70 ,
V_1 , V_26 ) )
continue;
F_50 ( V_1 , V_70 , NULL , V_26 ) ;
F_51 ( F_52 ( V_46 ) , V_1 ,
F_53 ( V_1 -> V_46 ) ,
V_1 -> V_5 , V_71 , 0 ) ;
} else {
F_32 ( V_10 ) ;
F_40 ( & V_10 , V_1 , V_26 ) ;
if ( F_41 ( & V_10 ,
V_1 , V_26 ) )
continue;
F_50 ( V_1 , & V_10 , V_1 -> V_23 , V_26 ) ;
F_47 ( V_1 , V_71 ) ;
}
}
V_31:
V_26 -> V_32 -> V_50 = 0 ;
return V_72 ;
}
static void
F_54 ( struct V_73 * V_32 )
{
if ( V_32 == NULL ) {
F_55 ( V_74 L_1 , V_75 ) ;
return;
}
F_55 ( V_74 L_2
L_3
L_4
L_5 ,
V_32 -> V_76 ,
F_56 ( & V_32 -> V_77 ) , V_32 -> V_4 ,
V_32 -> V_4 ? V_32 -> V_4 -> V_78 : 0 ) ;
}
static bool
F_57 ( struct V_79 * V_80 , struct V_79 * V_81 )
{
struct V_82 * V_83 , * V_57 ;
struct V_84 * V_85 , * V_86 ;
if ( V_80 -> V_87 != V_81 -> V_87 )
return false ;
switch ( V_80 -> V_87 ) {
case V_88 :
V_83 = (struct V_82 * ) V_80 ;
V_57 = (struct V_82 * ) V_81 ;
if ( V_83 -> V_89 . V_90 == V_57 -> V_89 . V_90 &&
V_83 -> V_91 == V_57 -> V_91 )
return true ;
break;
case V_92 :
V_85 = (struct V_84 * ) V_80 ;
V_86 = (struct V_84 * ) V_81 ;
if ( F_58 ( & V_85 -> V_93 ) ==
V_94 &&
V_85 -> V_95 != V_86 -> V_95 )
return false ;
if ( F_59 ( & V_85 -> V_93 , & V_86 -> V_93 ) &&
V_85 -> V_96 == V_86 -> V_96 )
return true ;
break;
default:
F_60 ( L_6 ,
V_75 , V_80 -> V_87 ) ;
return false ;
}
return false ;
}
static bool
F_61 ( const struct V_39 * V_97 ,
const struct V_39 * V_98 )
{
struct V_99 * V_100 , * V_101 ;
struct V_79 * V_102 , * V_103 ;
bool V_104 = false ;
F_62 (da1, dsaddrs1, da_node) {
V_102 = (struct V_79 * ) & V_100 -> V_105 ;
V_104 = false ;
F_62 (da2, dsaddrs2, da_node) {
V_103 = (struct V_79 * ) & V_101 -> V_105 ;
V_104 = F_57 ( V_102 , V_103 ) ;
if ( V_104 )
break;
}
if ( ! V_104 )
break;
}
return V_104 ;
}
static struct V_73 *
F_63 ( const struct V_39 * V_106 )
{
struct V_73 * V_32 ;
F_62 (ds, &nfs4_data_server_cache, ds_node)
if ( F_61 ( & V_32 -> V_107 , V_106 ) )
return V_32 ;
return NULL ;
}
static void F_64 ( struct V_73 * V_32 )
{
struct V_99 * V_108 ;
F_60 ( L_7 , V_75 ) ;
F_65 (FACILITY)
F_54 ( V_32 ) ;
F_2 ( V_32 -> V_4 ) ;
while ( ! F_26 ( & V_32 -> V_107 ) ) {
V_108 = F_12 ( & V_32 -> V_107 ,
struct V_99 ,
V_109 ) ;
F_49 ( & V_108 -> V_109 ) ;
F_66 ( V_108 -> V_110 ) ;
F_66 ( V_108 ) ;
}
F_66 ( V_32 -> V_76 ) ;
F_66 ( V_32 ) ;
}
void F_67 ( struct V_73 * V_32 )
{
if ( F_68 ( & V_32 -> V_77 ,
& V_111 ) ) {
F_49 ( & V_32 -> V_112 ) ;
F_29 ( & V_111 ) ;
F_64 ( V_32 ) ;
}
}
static char *
F_69 ( struct V_39 * V_106 , T_1 V_113 )
{
struct V_99 * V_108 ;
char * V_114 ;
T_2 V_115 ;
char * V_116 ;
V_115 = 3 ;
F_62 (da, dsaddrs, da_node) {
V_115 += strlen ( V_108 -> V_110 ) + 1 ;
}
V_114 = F_70 ( V_115 , V_113 ) ;
if ( ! V_114 )
return NULL ;
V_116 = V_114 ;
* ( V_116 ++ ) = '{' ;
V_115 -- ;
F_62 (da, dsaddrs, da_node) {
T_2 V_117 = strlen ( V_108 -> V_110 ) ;
if ( V_117 > V_115 )
goto V_118;
memcpy ( V_116 , V_108 -> V_110 , V_117 ) ;
V_116 += V_117 ;
V_115 -= V_117 ;
if ( V_115 < 1 )
goto V_118;
( * V_116 ++ ) = ',' ;
V_115 -- ;
}
if ( V_115 < 2 )
goto V_118;
* ( V_116 ++ ) = '}' ;
* V_116 = '\0' ;
return V_114 ;
V_118:
F_66 ( V_114 ) ;
return NULL ;
}
struct V_73 *
F_71 ( struct V_39 * V_106 , T_1 V_113 )
{
struct V_73 * V_119 , * V_32 = NULL ;
char * V_114 ;
if ( F_26 ( V_106 ) ) {
F_60 ( L_8 , V_75 ) ;
goto V_31;
}
V_32 = F_70 ( sizeof( * V_32 ) , V_113 ) ;
if ( ! V_32 )
goto V_31;
V_114 = F_69 ( V_106 , V_113 ) ;
F_30 ( & V_111 ) ;
V_119 = F_63 ( V_106 ) ;
if ( V_119 == NULL ) {
F_72 ( & V_32 -> V_107 ) ;
F_33 ( V_106 , & V_32 -> V_107 ) ;
V_32 -> V_76 = V_114 ;
F_73 ( & V_32 -> V_77 , 1 ) ;
F_72 ( & V_32 -> V_112 ) ;
V_32 -> V_4 = NULL ;
F_39 ( & V_32 -> V_112 , & V_120 ) ;
F_60 ( L_9 , V_75 ,
V_32 -> V_76 ) ;
} else {
F_66 ( V_114 ) ;
F_66 ( V_32 ) ;
F_74 ( & V_119 -> V_77 ) ;
F_60 ( L_10 ,
V_75 , V_119 -> V_76 ,
F_56 ( & V_119 -> V_77 ) ) ;
V_32 = V_119 ;
}
F_29 ( & V_111 ) ;
V_31:
return V_32 ;
}
static void F_75 ( struct V_73 * V_32 )
{
F_76 () ;
F_77 ( & V_32 -> V_121 , V_122 ,
V_123 ) ;
}
static void F_78 ( struct V_73 * V_32 )
{
F_79 () ;
F_21 ( V_122 , & V_32 -> V_121 ) ;
F_80 () ;
F_81 ( & V_32 -> V_121 , V_122 ) ;
}
static bool F_82 ( void )
{
if ( ! V_124 ) {
V_124 = F_83 ( V_125 ) ;
F_44 ( ! V_124 ) ;
}
return ( V_124 != NULL ) ;
}
void F_84 ( void )
{
if ( V_124 ) {
F_85 ( V_125 ) ;
V_124 = NULL ;
}
}
static int F_86 ( struct V_126 * V_127 ,
struct V_73 * V_32 ,
unsigned int V_128 ,
unsigned int V_129 )
{
struct V_130 * V_131 = F_87 ( - V_132 ) ;
struct V_99 * V_108 ;
int V_133 = 0 ;
F_60 ( L_11 , V_75 , V_32 -> V_76 ) ;
if ( ! F_82 () )
goto V_31;
F_62 (da, &ds->ds_addrs, da_node) {
F_60 ( L_12 ,
V_75 , V_32 -> V_76 , V_108 -> V_110 ) ;
if ( ! F_88 ( V_131 ) ) {
struct V_134 V_135 = {
. V_136 = V_137 ,
. V_138 = V_131 -> V_139 ,
. V_140 = (struct V_79 * ) & V_108 -> V_105 ,
. V_141 = V_108 -> V_142 ,
. V_143 = V_131 -> V_144 ,
} ;
F_89 ( V_131 -> V_145 , & V_135 ,
V_146 , NULL ) ;
} else
V_131 = V_124 ( V_127 ,
(struct V_79 * ) & V_108 -> V_105 ,
V_108 -> V_142 , V_147 ,
V_128 , V_129 ) ;
}
if ( F_88 ( V_131 ) ) {
V_133 = F_90 ( V_131 ) ;
goto V_31;
}
F_91 () ;
V_32 -> V_4 = V_131 ;
F_60 ( L_13 , V_75 , V_32 -> V_76 ) ;
V_31:
return V_133 ;
}
static int F_92 ( struct V_126 * V_127 ,
struct V_73 * V_32 ,
unsigned int V_128 ,
unsigned int V_129 ,
T_3 V_148 )
{
struct V_130 * V_131 = F_87 ( - V_132 ) ;
struct V_99 * V_108 ;
int V_133 = 0 ;
F_60 ( L_11 , V_75 , V_32 -> V_76 ) ;
F_62 (da, &ds->ds_addrs, da_node) {
F_60 ( L_12 ,
V_75 , V_32 -> V_76 , V_108 -> V_110 ) ;
if ( ! F_88 ( V_131 ) && V_131 -> V_149 -> V_150 ) {
struct V_134 V_135 = {
. V_136 = V_137 ,
. V_138 = V_131 -> V_139 ,
. V_140 = (struct V_79 * ) & V_108 -> V_105 ,
. V_141 = V_108 -> V_142 ,
. V_143 = V_131 -> V_144 ,
} ;
struct V_151 V_152 = {
. V_131 = V_131 ,
. V_153 = F_93 ( V_131 ) ,
} ;
struct V_154 V_155 = {
. V_156 = V_131 -> V_149 -> V_150 ,
. V_1 = & V_152 ,
} ;
F_89 ( V_131 -> V_145 , & V_135 ,
V_157 ,
& V_155 ) ;
if ( V_152 . V_153 )
F_94 ( V_152 . V_153 ) ;
} else {
V_131 = F_95 ( V_127 ,
(struct V_79 * ) & V_108 -> V_105 ,
V_108 -> V_142 , V_147 ,
V_128 , V_129 , V_148 ) ;
if ( F_88 ( V_131 ) )
continue;
V_133 = F_96 ( V_131 ,
V_127 -> V_130 -> V_158 ) ;
if ( V_133 ) {
F_2 ( V_131 ) ;
V_131 = F_87 ( - V_132 ) ;
continue;
}
}
}
if ( F_88 ( V_131 ) ) {
V_133 = F_90 ( V_131 ) ;
goto V_31;
}
F_91 () ;
V_32 -> V_4 = V_131 ;
F_60 ( L_13 , V_75 , V_32 -> V_76 ) ;
V_31:
return V_133 ;
}
int F_97 ( struct V_126 * V_127 , struct V_73 * V_32 ,
struct V_159 * V_160 , unsigned int V_128 ,
unsigned int V_129 , T_3 V_161 , T_3 V_148 )
{
int V_162 ;
V_163:
V_162 = 0 ;
if ( F_98 ( V_122 , & V_32 -> V_121 ) == 0 ) {
if ( V_161 == 3 ) {
V_162 = F_86 ( V_127 , V_32 , V_128 ,
V_129 ) ;
} else if ( V_161 == 4 ) {
V_162 = F_92 ( V_127 , V_32 , V_128 ,
V_129 , V_148 ) ;
} else {
F_60 ( L_14 , V_75 ,
V_161 ) ;
V_162 = - V_164 ;
}
F_78 ( V_32 ) ;
} else {
F_75 ( V_32 ) ;
if ( ! V_32 -> V_4 && ! F_99 ( V_160 ) )
goto V_163;
}
if ( ! V_162 ) {
if ( ! V_32 -> V_4 || ! F_100 ( V_32 -> V_4 ) ) {
F_44 ( V_32 -> V_4 ||
! F_99 ( V_160 ) ) ;
return - V_165 ;
}
V_162 = F_101 ( V_32 -> V_4 ) ;
}
return V_162 ;
}
struct V_99 *
F_102 ( struct V_138 * V_138 , struct V_166 * V_167 , T_1 V_113 )
{
struct V_99 * V_108 = NULL ;
char * V_168 , * V_169 ;
T_4 V_170 ;
int V_171 , V_172 ;
int V_43 [ 2 ] ;
T_5 * V_116 ;
char * V_173 , * V_174 ;
T_2 V_115 , V_175 ;
char * V_176 = L_15 ;
char * V_177 = L_15 ;
V_116 = F_103 ( V_167 , 4 ) ;
if ( F_104 ( ! V_116 ) )
goto V_118;
V_171 = F_105 ( V_116 ++ ) ;
V_116 = F_103 ( V_167 , V_171 ) ;
if ( F_104 ( ! V_116 ) )
goto V_118;
V_173 = F_106 ( V_171 + 1 , V_113 ) ;
if ( F_104 ( ! V_173 ) )
goto V_118;
V_173 [ V_171 ] = '\0' ;
memcpy ( V_173 , V_116 , V_171 ) ;
V_116 = F_103 ( V_167 , 4 ) ;
if ( F_104 ( ! V_116 ) )
goto V_178;
V_172 = F_105 ( V_116 ) ;
V_116 = F_103 ( V_167 , V_172 ) ;
if ( F_104 ( ! V_116 ) )
goto V_178;
if ( V_172 > V_179 + V_180 + 8 ) {
F_60 ( L_16 , V_75 ,
V_172 ) ;
goto V_178;
}
V_168 = F_106 ( V_172 + 1 , V_113 ) ;
if ( ! V_168 ) {
F_60 ( L_17 , V_75 ) ;
goto V_178;
}
V_168 [ V_172 ] = '\0' ;
memcpy ( V_168 , V_116 , V_172 ) ;
V_169 = strrchr ( V_168 , '.' ) ;
if ( ! V_169 ) {
F_60 ( L_18 ,
V_75 ) ;
goto V_181;
}
* V_169 = '-' ;
V_169 = strrchr ( V_168 , '.' ) ;
if ( ! V_169 ) {
F_60 ( L_19
L_20 , V_75 ) ;
goto V_181;
}
* V_169 = '\0' ;
V_108 = F_70 ( sizeof( * V_108 ) , V_113 ) ;
if ( F_104 ( ! V_108 ) )
goto V_181;
F_72 ( & V_108 -> V_109 ) ;
if ( ! F_107 ( V_138 , V_168 , V_169 - V_168 , (struct V_79 * ) & V_108 -> V_105 ,
sizeof( V_108 -> V_105 ) ) ) {
F_60 ( L_21 , V_75 , V_168 ) ;
goto V_182;
}
V_169 ++ ;
sscanf ( V_169 , L_22 , & V_43 [ 0 ] , & V_43 [ 1 ] ) ;
V_170 = F_108 ( ( V_43 [ 0 ] << 8 ) | ( V_43 [ 1 ] ) ) ;
switch ( V_108 -> V_105 . V_183 ) {
case V_88 :
( (struct V_82 * ) & V_108 -> V_105 ) -> V_91 = V_170 ;
V_108 -> V_142 = sizeof( struct V_82 ) ;
V_174 = L_23 ;
V_175 = 3 ;
break;
case V_92 :
( (struct V_84 * ) & V_108 -> V_105 ) -> V_96 = V_170 ;
V_108 -> V_142 = sizeof( struct V_84 ) ;
V_174 = L_24 ;
V_175 = 4 ;
V_176 = L_25 ;
V_177 = L_26 ;
break;
default:
F_60 ( L_27 ,
V_75 , V_108 -> V_105 . V_183 ) ;
goto V_182;
}
if ( V_171 != V_175 || strncmp ( V_173 , V_174 , V_171 ) ) {
F_60 ( L_28 ,
V_75 , V_173 , V_174 ) ;
goto V_182;
}
V_115 = strlen ( V_176 ) + strlen ( V_168 ) + strlen ( V_177 ) + 7 ;
V_108 -> V_110 = F_70 ( V_115 , V_113 ) ;
if ( V_108 -> V_110 )
snprintf ( V_108 -> V_110 , V_115 , L_29 , V_176 ,
V_168 , V_177 , F_109 ( V_170 ) ) ;
F_60 ( L_30 , V_75 , V_108 -> V_110 ) ;
F_66 ( V_168 ) ;
F_66 ( V_173 ) ;
return V_108 ;
V_182:
F_66 ( V_108 ) ;
V_181:
F_60 ( L_31 , V_75 , V_168 ) ;
F_66 ( V_168 ) ;
V_178:
F_66 ( V_173 ) ;
V_118:
return NULL ;
}
void
F_110 ( struct V_8 * V_24 ,
struct V_27 * V_23 ,
struct V_25 * V_26 ,
T_3 V_184 )
{
struct V_39 * V_62 ;
struct V_35 * V_56 ;
F_30 ( & V_26 -> V_46 -> V_47 ) ;
V_56 = V_26 -> V_32 -> V_56 ;
V_62 = & V_56 [ V_184 ] . V_37 ;
if ( F_26 ( V_62 ) ) {
if ( ! F_36 ( V_23 ) ) {
F_29 ( & V_26 -> V_46 -> V_47 ) ;
V_26 -> V_21 -> V_185 ( V_26 , V_24 ) ;
return;
}
F_44 ( V_56 [ V_184 ] . V_38 != NULL ) ;
V_56 [ V_184 ] . V_38 = F_25 ( V_23 ) ;
}
F_111 ( V_29 , & V_24 -> V_30 ) ;
V_26 -> V_32 -> V_33 ++ ;
F_112 ( V_24 , V_62 , V_26 ) ;
F_29 ( & V_26 -> V_46 -> V_47 ) ;
F_113 ( V_24 -> V_186 , V_26 ) ;
}
int
F_114 ( struct V_46 * V_46 , bool V_187 )
{
int V_44 ;
if ( ! F_115 ( V_46 ) )
return 0 ;
V_44 = F_116 ( V_46 , V_188 ) ;
if ( V_44 < 0 )
return V_44 ;
if ( V_187 )
return 0 ;
return F_117 ( V_46 , true ) ;
}
