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
F_7 ( V_28 ) ;
}
static int
F_14 ( struct V_35 * V_36 ,
struct V_25 * V_26 ,
int V_39 )
{
struct V_40 * V_41 = & V_36 -> V_37 ;
struct V_40 * V_42 = & V_36 -> V_43 ;
int V_44 ;
F_15 ( & F_16 ( V_26 -> V_45 ) -> V_46 ) ;
V_44 = F_17 ( V_41 , V_42 , V_26 , V_39 ) ;
if ( V_44 ) {
V_26 -> V_32 -> V_33 -= V_44 ;
V_26 -> V_32 -> V_47 += V_44 ;
if ( V_36 -> V_48 == NULL )
V_36 -> V_48 = F_18 ( V_36 -> V_38 ) ;
if ( F_19 ( V_41 ) ) {
F_7 ( V_36 -> V_38 ) ;
V_36 -> V_38 = NULL ;
}
}
return V_44 ;
}
int F_20 ( struct V_25 * V_26 ,
int V_39 )
{
int V_49 , V_50 = 0 , V_51 ;
F_15 ( & F_16 ( V_26 -> V_45 ) -> V_46 ) ;
for ( V_49 = 0 ; V_49 < V_26 -> V_32 -> V_52 && V_39 != 0 ; V_49 ++ ) {
V_51 = F_14 ( & V_26 -> V_32 -> V_53 [ V_49 ] ,
V_26 , V_39 ) ;
V_39 -= V_51 ;
V_50 += V_51 ;
}
return V_50 ;
}
void F_21 ( struct V_40 * V_42 ,
struct V_25 * V_26 )
{
struct V_35 * V_54 ;
struct V_27 * V_28 ;
int V_33 ;
int V_49 ;
F_15 ( & F_16 ( V_26 -> V_45 ) -> V_46 ) ;
V_55:
for ( V_49 = 0 , V_54 = V_26 -> V_32 -> V_53 ; V_49 < V_26 -> V_32 -> V_52 ; V_49 ++ , V_54 ++ ) {
V_33 = F_17 ( & V_54 -> V_37 , V_42 , V_26 , 0 ) ;
if ( ! V_33 )
continue;
V_26 -> V_32 -> V_33 -= V_33 ;
if ( F_19 ( & V_54 -> V_37 ) ) {
V_28 = V_54 -> V_38 ;
V_54 -> V_38 = NULL ;
F_22 ( & V_26 -> V_45 -> V_56 ) ;
F_7 ( V_28 ) ;
F_23 ( & V_26 -> V_45 -> V_56 ) ;
goto V_55;
}
}
}
static void F_24 ( struct V_25 * V_26 , int V_57 )
{
struct V_58 * V_59 = V_26 -> V_32 ;
struct V_35 * V_36 ;
struct V_27 * V_28 ;
struct V_40 * V_60 ;
F_25 ( V_10 ) ;
int V_49 ;
F_23 ( & V_26 -> V_45 -> V_56 ) ;
for ( V_49 = V_57 ; V_49 < V_59 -> V_52 ; V_49 ++ ) {
V_36 = & V_59 -> V_53 [ V_49 ] ;
if ( F_19 ( & V_36 -> V_43 ) )
continue;
V_28 = V_36 -> V_48 ;
V_36 -> V_48 = NULL ;
F_26 (pos, &bucket->committing)
V_26 -> V_32 -> V_47 -- ;
F_27 ( & V_36 -> V_43 , & V_10 ) ;
F_22 ( & V_26 -> V_45 -> V_56 ) ;
F_28 ( & V_10 , V_28 , V_26 , V_49 ) ;
F_7 ( V_28 ) ;
F_23 ( & V_26 -> V_45 -> V_56 ) ;
}
F_22 ( & V_26 -> V_45 -> V_56 ) ;
}
static unsigned int
F_29 ( struct V_25 * V_26 ,
struct V_40 * V_61 )
{
struct V_58 * V_59 ;
struct V_35 * V_36 ;
struct V_7 * V_1 ;
int V_49 ;
unsigned int V_62 = 0 ;
V_59 = V_26 -> V_32 ;
V_36 = V_59 -> V_53 ;
for ( V_49 = 0 ; V_49 < V_59 -> V_52 ; V_49 ++ , V_36 ++ ) {
if ( F_19 ( & V_36 -> V_43 ) )
continue;
V_1 = F_30 ( false ) ;
if ( ! V_1 )
break;
V_1 -> V_63 = V_49 ;
F_31 ( & V_1 -> V_10 , V_61 ) ;
V_62 ++ ;
}
F_24 ( V_26 , V_49 ) ;
return V_62 ;
}
static inline
void F_32 ( struct V_40 * V_10 ,
struct V_7 * V_1 ,
struct V_25 * V_26 )
{
struct V_35 * V_36 ;
struct V_40 * V_60 ;
V_36 = & V_26 -> V_32 -> V_53 [ V_1 -> V_63 ] ;
F_23 ( & V_26 -> V_45 -> V_56 ) ;
F_26 (pos, &bucket->committing)
V_26 -> V_32 -> V_47 -- ;
F_27 ( & V_36 -> V_43 , V_10 ) ;
V_1 -> V_23 = V_36 -> V_48 ;
V_36 -> V_48 = NULL ;
F_22 ( & V_26 -> V_45 -> V_56 ) ;
}
static bool
F_33 ( struct V_40 * V_10 ,
struct V_7 * V_1 ,
struct V_25 * V_26 )
{
if ( F_19 ( V_10 ) ) {
if ( F_34 ( & V_26 -> V_64 -> V_65 ) )
F_35 ( & V_26 -> V_64 -> V_65 ) ;
F_36 ( V_1 -> V_66 ) ;
F_37 ( V_1 ) ;
return true ;
}
return false ;
}
int
F_38 ( struct V_45 * V_45 , struct V_40 * V_67 ,
int V_68 , struct V_25 * V_26 ,
int (* F_39)( struct V_7 * V_1 ,
int V_68 ) )
{
struct V_7 * V_1 , * V_69 ;
F_25 ( V_61 ) ;
unsigned int V_62 = 0 ;
if ( ! F_19 ( V_67 ) ) {
V_1 = F_30 ( true ) ;
V_1 -> V_63 = - 1 ;
F_31 ( & V_1 -> V_10 , & V_61 ) ;
V_62 ++ ;
}
V_62 += F_29 ( V_26 , & V_61 ) ;
if ( V_62 == 0 )
goto V_31;
F_40 ( V_62 , & V_26 -> V_64 -> V_65 ) ;
F_41 (data, tmp, &list, pages) {
F_42 ( & V_1 -> V_10 ) ;
if ( V_1 -> V_63 < 0 ) {
if ( F_33 ( V_67 ,
V_1 , V_26 ) )
continue;
F_43 ( V_1 , V_67 , NULL , V_26 ) ;
F_44 ( F_45 ( V_45 ) , V_1 ,
F_46 ( V_1 -> V_45 ) ,
V_1 -> V_5 , V_68 , 0 ) ;
} else {
F_25 ( V_10 ) ;
F_32 ( & V_10 , V_1 , V_26 ) ;
if ( F_33 ( & V_10 ,
V_1 , V_26 ) )
continue;
F_43 ( V_1 , & V_10 , V_1 -> V_23 , V_26 ) ;
F_39 ( V_1 , V_68 ) ;
}
}
V_31:
return V_70 ;
}
static void
F_47 ( struct V_71 * V_32 )
{
if ( V_32 == NULL ) {
F_48 ( V_72 L_1 , V_73 ) ;
return;
}
F_48 ( V_72 L_2
L_3
L_4
L_5 ,
V_32 -> V_74 ,
F_49 ( & V_32 -> V_75 ) , V_32 -> V_4 ,
V_32 -> V_4 ? V_32 -> V_4 -> V_76 : 0 ) ;
}
static bool
F_50 ( struct V_77 * V_78 , struct V_77 * V_79 )
{
struct V_80 * V_81 , * V_54 ;
struct V_82 * V_83 , * V_84 ;
if ( V_78 -> V_85 != V_79 -> V_85 )
return false ;
switch ( V_78 -> V_85 ) {
case V_86 :
V_81 = (struct V_80 * ) V_78 ;
V_54 = (struct V_80 * ) V_79 ;
if ( V_81 -> V_87 . V_88 == V_54 -> V_87 . V_88 &&
V_81 -> V_89 == V_54 -> V_89 )
return true ;
break;
case V_90 :
V_83 = (struct V_82 * ) V_78 ;
V_84 = (struct V_82 * ) V_79 ;
if ( F_51 ( & V_83 -> V_91 ) ==
V_92 &&
V_83 -> V_93 != V_84 -> V_93 )
return false ;
if ( F_52 ( & V_83 -> V_91 , & V_84 -> V_91 ) &&
V_83 -> V_94 == V_84 -> V_94 )
return true ;
break;
default:
F_53 ( L_6 ,
V_73 , V_78 -> V_85 ) ;
return false ;
}
return false ;
}
static bool
F_54 ( const struct V_40 * V_95 ,
const struct V_40 * V_96 )
{
struct V_97 * V_98 , * V_99 ;
struct V_77 * V_100 , * V_101 ;
bool V_102 = false ;
F_55 (da1, dsaddrs1, da_node) {
V_100 = (struct V_77 * ) & V_98 -> V_103 ;
V_102 = false ;
F_55 (da2, dsaddrs2, da_node) {
V_101 = (struct V_77 * ) & V_99 -> V_103 ;
V_102 = F_50 ( V_100 , V_101 ) ;
if ( V_102 )
break;
}
if ( ! V_102 )
break;
}
return V_102 ;
}
static struct V_71 *
F_56 ( const struct V_40 * V_104 )
{
struct V_71 * V_32 ;
F_55 (ds, &nfs4_data_server_cache, ds_node)
if ( F_54 ( & V_32 -> V_105 , V_104 ) )
return V_32 ;
return NULL ;
}
static void F_57 ( struct V_71 * V_32 )
{
struct V_97 * V_106 ;
F_53 ( L_7 , V_73 ) ;
F_58 (FACILITY)
F_47 ( V_32 ) ;
F_2 ( V_32 -> V_4 ) ;
while ( ! F_19 ( & V_32 -> V_105 ) ) {
V_106 = F_12 ( & V_32 -> V_105 ,
struct V_97 ,
V_107 ) ;
F_42 ( & V_106 -> V_107 ) ;
F_59 ( V_106 -> V_108 ) ;
F_59 ( V_106 ) ;
}
F_59 ( V_32 -> V_74 ) ;
F_59 ( V_32 ) ;
}
void F_60 ( struct V_71 * V_32 )
{
if ( F_61 ( & V_32 -> V_75 ,
& V_109 ) ) {
F_42 ( & V_32 -> V_110 ) ;
F_22 ( & V_109 ) ;
F_57 ( V_32 ) ;
}
}
static char *
F_62 ( struct V_40 * V_104 , T_1 V_111 )
{
struct V_97 * V_106 ;
char * V_112 ;
T_2 V_113 ;
char * V_114 ;
V_113 = 3 ;
F_55 (da, dsaddrs, da_node) {
V_113 += strlen ( V_106 -> V_108 ) + 1 ;
}
V_112 = F_63 ( V_113 , V_111 ) ;
if ( ! V_112 )
return NULL ;
V_114 = V_112 ;
* ( V_114 ++ ) = '{' ;
V_113 -- ;
F_55 (da, dsaddrs, da_node) {
T_2 V_115 = strlen ( V_106 -> V_108 ) ;
if ( V_115 > V_113 )
goto V_116;
memcpy ( V_114 , V_106 -> V_108 , V_115 ) ;
V_114 += V_115 ;
V_113 -= V_115 ;
if ( V_113 < 1 )
goto V_116;
( * V_114 ++ ) = ',' ;
V_113 -- ;
}
if ( V_113 < 2 )
goto V_116;
* ( V_114 ++ ) = '}' ;
* V_114 = '\0' ;
return V_112 ;
V_116:
F_59 ( V_112 ) ;
return NULL ;
}
struct V_71 *
F_64 ( struct V_40 * V_104 , T_1 V_111 )
{
struct V_71 * V_117 , * V_32 = NULL ;
char * V_112 ;
if ( F_19 ( V_104 ) ) {
F_53 ( L_8 , V_73 ) ;
goto V_31;
}
V_32 = F_63 ( sizeof( * V_32 ) , V_111 ) ;
if ( ! V_32 )
goto V_31;
V_112 = F_62 ( V_104 , V_111 ) ;
F_23 ( & V_109 ) ;
V_117 = F_56 ( V_104 ) ;
if ( V_117 == NULL ) {
F_65 ( & V_32 -> V_105 ) ;
F_27 ( V_104 , & V_32 -> V_105 ) ;
V_32 -> V_74 = V_112 ;
F_66 ( & V_32 -> V_75 , 1 ) ;
F_65 ( & V_32 -> V_110 ) ;
V_32 -> V_4 = NULL ;
F_31 ( & V_32 -> V_110 , & V_118 ) ;
F_53 ( L_9 , V_73 ,
V_32 -> V_74 ) ;
} else {
F_59 ( V_112 ) ;
F_59 ( V_32 ) ;
F_67 ( & V_117 -> V_75 ) ;
F_53 ( L_10 ,
V_73 , V_117 -> V_74 ,
F_49 ( & V_117 -> V_75 ) ) ;
V_32 = V_117 ;
}
F_22 ( & V_109 ) ;
V_31:
return V_32 ;
}
static void F_68 ( struct V_71 * V_32 )
{
F_69 () ;
F_70 ( & V_32 -> V_119 , V_120 ,
V_121 ) ;
}
static void F_71 ( struct V_71 * V_32 )
{
F_72 () ;
F_73 ( V_120 , & V_32 -> V_119 ) ;
F_74 () ;
F_75 ( & V_32 -> V_119 , V_120 ) ;
}
static bool F_76 ( void )
{
if ( ! V_122 ) {
V_122 = F_77 ( V_123 ) ;
F_36 ( ! V_122 ) ;
}
return ( V_122 != NULL ) ;
}
void F_78 ( void )
{
if ( V_122 ) {
F_79 ( V_123 ) ;
V_122 = NULL ;
}
}
static int F_80 ( struct V_124 * V_125 ,
struct V_71 * V_32 ,
unsigned int V_126 ,
unsigned int V_127 )
{
struct V_128 * V_129 = F_81 ( - V_130 ) ;
struct V_97 * V_106 ;
int V_131 = 0 ;
F_53 ( L_11 , V_73 , V_32 -> V_74 ) ;
if ( ! F_76 () )
goto V_31;
F_55 (da, &ds->ds_addrs, da_node) {
F_53 ( L_12 ,
V_73 , V_32 -> V_74 , V_106 -> V_108 ) ;
if ( ! F_82 ( V_129 ) ) {
struct V_132 V_133 = {
. V_134 = V_135 ,
. V_136 = V_129 -> V_137 ,
. V_138 = (struct V_77 * ) & V_106 -> V_103 ,
. V_139 = V_106 -> V_140 ,
. V_141 = V_129 -> V_142 ,
} ;
F_83 ( V_129 -> V_143 , & V_133 ,
V_144 , NULL ) ;
} else
V_129 = V_122 ( V_125 ,
(struct V_77 * ) & V_106 -> V_103 ,
V_106 -> V_140 , V_145 ,
V_126 , V_127 ) ;
}
if ( F_82 ( V_129 ) ) {
V_131 = F_84 ( V_129 ) ;
goto V_31;
}
F_85 () ;
V_32 -> V_4 = V_129 ;
F_53 ( L_13 , V_73 , V_32 -> V_74 ) ;
V_31:
return V_131 ;
}
static int F_86 ( struct V_124 * V_125 ,
struct V_71 * V_32 ,
unsigned int V_126 ,
unsigned int V_127 ,
T_3 V_146 )
{
struct V_128 * V_129 = F_81 ( - V_130 ) ;
struct V_97 * V_106 ;
int V_131 = 0 ;
F_53 ( L_11 , V_73 , V_32 -> V_74 ) ;
F_55 (da, &ds->ds_addrs, da_node) {
F_53 ( L_12 ,
V_73 , V_32 -> V_74 , V_106 -> V_108 ) ;
if ( ! F_82 ( V_129 ) && V_129 -> V_147 -> V_148 ) {
struct V_132 V_133 = {
. V_134 = V_135 ,
. V_136 = V_129 -> V_137 ,
. V_138 = (struct V_77 * ) & V_106 -> V_103 ,
. V_139 = V_106 -> V_140 ,
. V_141 = V_129 -> V_142 ,
} ;
struct V_149 V_150 = {
. V_129 = V_129 ,
. V_151 = F_87 ( V_129 ) ,
} ;
struct V_152 V_153 = {
. V_154 = V_129 -> V_147 -> V_148 ,
. V_1 = & V_150 ,
} ;
F_83 ( V_129 -> V_143 , & V_133 ,
V_155 ,
& V_153 ) ;
if ( V_150 . V_151 )
F_88 ( V_150 . V_151 ) ;
} else {
V_129 = F_89 ( V_125 ,
(struct V_77 * ) & V_106 -> V_103 ,
V_106 -> V_140 , V_145 ,
V_126 , V_127 , V_146 ) ;
if ( F_82 ( V_129 ) )
continue;
V_131 = F_90 ( V_129 ,
V_125 -> V_128 -> V_156 ) ;
if ( V_131 ) {
F_2 ( V_129 ) ;
V_129 = F_81 ( - V_130 ) ;
continue;
}
}
}
if ( F_82 ( V_129 ) ) {
V_131 = F_84 ( V_129 ) ;
goto V_31;
}
F_85 () ;
V_32 -> V_4 = V_129 ;
F_53 ( L_13 , V_73 , V_32 -> V_74 ) ;
V_31:
return V_131 ;
}
int F_91 ( struct V_124 * V_125 , struct V_71 * V_32 ,
struct V_157 * V_158 , unsigned int V_126 ,
unsigned int V_127 , T_3 V_159 , T_3 V_146 )
{
int V_160 ;
V_161:
V_160 = 0 ;
if ( F_92 ( V_120 , & V_32 -> V_119 ) == 0 ) {
if ( V_159 == 3 ) {
V_160 = F_80 ( V_125 , V_32 , V_126 ,
V_127 ) ;
} else if ( V_159 == 4 ) {
V_160 = F_86 ( V_125 , V_32 , V_126 ,
V_127 , V_146 ) ;
} else {
F_53 ( L_14 , V_73 ,
V_159 ) ;
V_160 = - V_162 ;
}
F_71 ( V_32 ) ;
} else {
F_68 ( V_32 ) ;
if ( ! V_32 -> V_4 && ! F_93 ( V_158 ) )
goto V_161;
}
if ( ! V_160 ) {
if ( ! V_32 -> V_4 || ! F_94 ( V_32 -> V_4 ) ) {
F_36 ( V_32 -> V_4 ||
! F_93 ( V_158 ) ) ;
return - V_163 ;
}
V_160 = F_95 ( V_32 -> V_4 ) ;
}
return V_160 ;
}
struct V_97 *
F_96 ( struct V_136 * V_136 , struct V_164 * V_165 , T_1 V_111 )
{
struct V_97 * V_106 = NULL ;
char * V_166 , * V_167 ;
T_4 V_168 ;
int V_169 , V_170 ;
int V_69 [ 2 ] ;
T_5 * V_114 ;
char * V_171 , * V_172 ;
T_2 V_113 , V_173 ;
char * V_174 = L_15 ;
char * V_175 = L_15 ;
V_114 = F_97 ( V_165 , 4 ) ;
if ( F_98 ( ! V_114 ) )
goto V_116;
V_169 = F_99 ( V_114 ++ ) ;
V_114 = F_97 ( V_165 , V_169 ) ;
if ( F_98 ( ! V_114 ) )
goto V_116;
V_171 = F_100 ( V_169 + 1 , V_111 ) ;
if ( F_98 ( ! V_171 ) )
goto V_116;
V_171 [ V_169 ] = '\0' ;
memcpy ( V_171 , V_114 , V_169 ) ;
V_114 = F_97 ( V_165 , 4 ) ;
if ( F_98 ( ! V_114 ) )
goto V_176;
V_170 = F_99 ( V_114 ) ;
V_114 = F_97 ( V_165 , V_170 ) ;
if ( F_98 ( ! V_114 ) )
goto V_176;
if ( V_170 > V_177 + V_178 + 8 ) {
F_53 ( L_16 , V_73 ,
V_170 ) ;
goto V_176;
}
V_166 = F_100 ( V_170 + 1 , V_111 ) ;
if ( ! V_166 ) {
F_53 ( L_17 , V_73 ) ;
goto V_176;
}
V_166 [ V_170 ] = '\0' ;
memcpy ( V_166 , V_114 , V_170 ) ;
V_167 = strrchr ( V_166 , '.' ) ;
if ( ! V_167 ) {
F_53 ( L_18 ,
V_73 ) ;
goto V_179;
}
* V_167 = '-' ;
V_167 = strrchr ( V_166 , '.' ) ;
if ( ! V_167 ) {
F_53 ( L_19
L_20 , V_73 ) ;
goto V_179;
}
* V_167 = '\0' ;
V_106 = F_63 ( sizeof( * V_106 ) , V_111 ) ;
if ( F_98 ( ! V_106 ) )
goto V_179;
F_65 ( & V_106 -> V_107 ) ;
if ( ! F_101 ( V_136 , V_166 , V_167 - V_166 , (struct V_77 * ) & V_106 -> V_103 ,
sizeof( V_106 -> V_103 ) ) ) {
F_53 ( L_21 , V_73 , V_166 ) ;
goto V_180;
}
V_167 ++ ;
sscanf ( V_167 , L_22 , & V_69 [ 0 ] , & V_69 [ 1 ] ) ;
V_168 = F_102 ( ( V_69 [ 0 ] << 8 ) | ( V_69 [ 1 ] ) ) ;
switch ( V_106 -> V_103 . V_181 ) {
case V_86 :
( (struct V_80 * ) & V_106 -> V_103 ) -> V_89 = V_168 ;
V_106 -> V_140 = sizeof( struct V_80 ) ;
V_172 = L_23 ;
V_173 = 3 ;
break;
case V_90 :
( (struct V_82 * ) & V_106 -> V_103 ) -> V_94 = V_168 ;
V_106 -> V_140 = sizeof( struct V_82 ) ;
V_172 = L_24 ;
V_173 = 4 ;
V_174 = L_25 ;
V_175 = L_26 ;
break;
default:
F_53 ( L_27 ,
V_73 , V_106 -> V_103 . V_181 ) ;
goto V_180;
}
if ( V_169 != V_173 || strncmp ( V_171 , V_172 , V_169 ) ) {
F_53 ( L_28 ,
V_73 , V_171 , V_172 ) ;
goto V_180;
}
V_113 = strlen ( V_174 ) + strlen ( V_166 ) + strlen ( V_175 ) + 7 ;
V_106 -> V_108 = F_63 ( V_113 , V_111 ) ;
if ( V_106 -> V_108 )
snprintf ( V_106 -> V_108 , V_113 , L_29 , V_174 ,
V_166 , V_175 , F_103 ( V_168 ) ) ;
F_53 ( L_30 , V_73 , V_106 -> V_108 ) ;
F_59 ( V_166 ) ;
F_59 ( V_171 ) ;
return V_106 ;
V_180:
F_59 ( V_106 ) ;
V_179:
F_53 ( L_31 , V_73 , V_166 ) ;
F_59 ( V_166 ) ;
V_176:
F_59 ( V_171 ) ;
V_116:
return NULL ;
}
void
F_104 ( struct V_8 * V_24 ,
struct V_27 * V_23 ,
struct V_25 * V_26 ,
T_3 V_182 )
{
struct V_40 * V_61 ;
struct V_35 * V_53 ;
F_105 ( & F_16 ( V_26 -> V_45 ) -> V_46 ) ;
V_53 = V_26 -> V_32 -> V_53 ;
V_61 = & V_53 [ V_182 ] . V_37 ;
if ( F_19 ( V_61 ) ) {
if ( ! F_106 ( V_23 ) ) {
F_107 ( & F_16 ( V_26 -> V_45 ) -> V_46 ) ;
V_26 -> V_21 -> V_183 ( V_26 , V_24 ) ;
return;
}
F_36 ( V_53 [ V_182 ] . V_38 != NULL ) ;
V_53 [ V_182 ] . V_38 = F_18 ( V_23 ) ;
}
F_108 ( V_29 , & V_24 -> V_30 ) ;
V_26 -> V_32 -> V_33 ++ ;
F_109 ( V_24 , V_61 , V_26 ) ;
F_107 ( & F_16 ( V_26 -> V_45 ) -> V_46 ) ;
F_110 ( V_24 -> V_184 , V_26 ) ;
}
int
F_111 ( struct V_45 * V_45 , bool V_185 )
{
int V_44 ;
if ( ! F_112 ( V_45 ) )
return 0 ;
V_44 = F_113 ( V_45 , V_186 ) ;
if ( V_44 < 0 )
return V_44 ;
if ( V_185 )
return 0 ;
return F_114 ( V_45 , true ) ;
}
