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
V_36 -> V_50 = V_36 -> V_38 ;
if ( F_25 ( V_40 ) )
V_36 -> V_38 = NULL ;
else
F_26 ( V_36 -> V_50 ) ;
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
int V_51 ;
for ( V_51 = V_58 ; V_51 < V_60 -> V_54 ; V_51 ++ ) {
V_36 = & V_60 -> V_55 [ V_51 ] ;
if ( F_25 ( & V_36 -> V_48 ) )
continue;
F_32 ( & V_36 -> V_48 , V_36 -> V_50 , V_26 , V_51 ) ;
F_30 ( V_26 -> V_46 ) ;
V_28 = V_36 -> V_50 ;
V_36 -> V_50 = NULL ;
F_29 ( V_26 -> V_46 ) ;
F_7 ( V_28 ) ;
}
}
static unsigned int
F_33 ( struct V_25 * V_26 ,
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
if ( F_25 ( & V_36 -> V_48 ) )
continue;
V_1 = F_34 () ;
if ( ! V_1 )
break;
V_1 -> V_63 = V_51 ;
F_30 ( V_26 -> V_46 ) ;
V_1 -> V_23 = V_36 -> V_50 ;
V_36 -> V_50 = NULL ;
F_29 ( V_26 -> V_46 ) ;
F_35 ( & V_1 -> V_10 , V_61 ) ;
V_62 ++ ;
}
F_31 ( V_26 , V_51 ) ;
return V_62 ;
}
int
F_36 ( struct V_64 * V_64 , struct V_39 * V_65 ,
int V_66 , struct V_25 * V_26 ,
int (* F_37)( struct V_7 * V_1 ,
int V_66 ) )
{
struct V_7 * V_1 , * V_43 ;
F_38 ( V_61 ) ;
unsigned int V_62 = 0 ;
if ( ! F_25 ( V_65 ) ) {
V_1 = F_34 () ;
if ( V_1 != NULL ) {
V_1 -> V_23 = NULL ;
F_35 ( & V_1 -> V_10 , & V_61 ) ;
V_62 ++ ;
} else {
F_32 ( V_65 , NULL , V_26 , 0 ) ;
F_31 ( V_26 , 0 ) ;
V_26 -> V_21 -> V_67 ( F_39 ( V_64 ) ) ;
return - V_68 ;
}
}
V_62 += F_33 ( V_26 , & V_61 ) ;
if ( V_62 == 0 ) {
V_26 -> V_21 -> V_67 ( F_39 ( V_64 ) ) ;
goto V_31;
}
F_40 ( V_62 , & V_26 -> V_69 -> V_70 ) ;
F_16 (data, tmp, &list, pages) {
F_41 ( & V_1 -> V_10 ) ;
if ( ! V_1 -> V_23 ) {
F_42 ( V_1 , V_65 , NULL , V_26 ) ;
F_43 ( F_44 ( V_64 ) , V_1 ,
F_45 ( V_1 -> V_64 ) ,
V_1 -> V_5 , V_66 , 0 ) ;
} else {
struct V_35 * V_55 ;
V_55 = V_26 -> V_32 -> V_55 ;
F_42 ( V_1 ,
& V_55 [ V_1 -> V_63 ] . V_48 ,
V_1 -> V_23 ,
V_26 ) ;
F_37 ( V_1 , V_66 ) ;
}
}
V_31:
V_26 -> V_32 -> V_49 = 0 ;
return V_71 ;
}
static void
F_46 ( struct V_72 * V_32 )
{
if ( V_32 == NULL ) {
F_47 ( V_73 L_1 , V_74 ) ;
return;
}
F_47 ( V_73 L_2
L_3
L_4
L_5 ,
V_32 -> V_75 ,
F_48 ( & V_32 -> V_76 ) , V_32 -> V_4 ,
V_32 -> V_4 ? V_32 -> V_4 -> V_77 : 0 ) ;
}
static bool
F_49 ( struct V_78 * V_79 , struct V_78 * V_80 )
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
if ( F_50 ( & V_84 -> V_92 ) ==
V_93 &&
V_84 -> V_94 != V_85 -> V_94 )
return false ;
if ( F_51 ( & V_84 -> V_92 , & V_85 -> V_92 ) &&
V_84 -> V_95 == V_85 -> V_95 )
return true ;
break;
default:
F_52 ( L_6 ,
V_74 , V_79 -> V_86 ) ;
return false ;
}
return false ;
}
static bool
F_53 ( const struct V_39 * V_96 ,
const struct V_39 * V_97 )
{
struct V_98 * V_99 , * V_100 ;
for ( V_99 = F_12 ( V_96 , F_54 ( * V_99 ) , V_101 ) ,
V_100 = F_12 ( V_97 , F_54 ( * V_100 ) , V_101 ) ;
V_99 != NULL && V_100 != NULL ;
V_99 = F_55 ( V_99 -> V_101 . V_11 , F_54 ( * V_99 ) , V_101 ) ,
V_100 = F_55 ( V_100 -> V_101 . V_11 , F_54 ( * V_100 ) , V_101 ) ) {
if ( ! F_49 ( (struct V_78 * ) & V_99 -> V_102 ,
(struct V_78 * ) & V_100 -> V_102 ) )
return false ;
}
if ( V_99 == NULL && V_100 == NULL )
return true ;
return false ;
}
static struct V_72 *
F_56 ( const struct V_39 * V_103 )
{
struct V_72 * V_32 ;
F_57 (ds, &nfs4_data_server_cache, ds_node)
if ( F_53 ( & V_32 -> V_104 , V_103 ) )
return V_32 ;
return NULL ;
}
static void F_58 ( struct V_72 * V_32 )
{
struct V_98 * V_105 ;
F_52 ( L_7 , V_74 ) ;
F_59 (FACILITY)
F_46 ( V_32 ) ;
F_2 ( V_32 -> V_4 ) ;
while ( ! F_25 ( & V_32 -> V_104 ) ) {
V_105 = F_12 ( & V_32 -> V_104 ,
struct V_98 ,
V_101 ) ;
F_41 ( & V_105 -> V_101 ) ;
F_60 ( V_105 -> V_106 ) ;
F_60 ( V_105 ) ;
}
F_60 ( V_32 -> V_75 ) ;
F_60 ( V_32 ) ;
}
void F_61 ( struct V_72 * V_32 )
{
if ( F_62 ( & V_32 -> V_76 ,
& V_107 ) ) {
F_41 ( & V_32 -> V_108 ) ;
F_29 ( & V_107 ) ;
F_58 ( V_32 ) ;
}
}
static char *
F_63 ( struct V_39 * V_103 , T_1 V_109 )
{
struct V_98 * V_105 ;
char * V_110 ;
T_2 V_111 ;
char * V_112 ;
V_111 = 3 ;
F_57 (da, dsaddrs, da_node) {
V_111 += strlen ( V_105 -> V_106 ) + 1 ;
}
V_110 = F_64 ( V_111 , V_109 ) ;
if ( ! V_110 )
return NULL ;
V_112 = V_110 ;
* ( V_112 ++ ) = '{' ;
V_111 -- ;
F_57 (da, dsaddrs, da_node) {
T_2 V_113 = strlen ( V_105 -> V_106 ) ;
if ( V_113 > V_111 )
goto V_114;
memcpy ( V_112 , V_105 -> V_106 , V_113 ) ;
V_112 += V_113 ;
V_111 -= V_113 ;
if ( V_111 < 1 )
goto V_114;
( * V_112 ++ ) = ',' ;
V_111 -- ;
}
if ( V_111 < 2 )
goto V_114;
* ( V_112 ++ ) = '}' ;
* V_112 = '\0' ;
return V_110 ;
V_114:
F_60 ( V_110 ) ;
return NULL ;
}
struct V_72 *
F_65 ( struct V_39 * V_103 , T_1 V_109 )
{
struct V_72 * V_115 , * V_32 = NULL ;
char * V_110 ;
if ( F_25 ( V_103 ) ) {
F_52 ( L_8 , V_74 ) ;
goto V_31;
}
V_32 = F_64 ( sizeof( * V_32 ) , V_109 ) ;
if ( ! V_32 )
goto V_31;
V_110 = F_63 ( V_103 , V_109 ) ;
F_30 ( & V_107 ) ;
V_115 = F_56 ( V_103 ) ;
if ( V_115 == NULL ) {
F_66 ( & V_32 -> V_104 ) ;
F_67 ( V_103 , & V_32 -> V_104 ) ;
V_32 -> V_75 = V_110 ;
F_68 ( & V_32 -> V_76 , 1 ) ;
F_66 ( & V_32 -> V_108 ) ;
V_32 -> V_4 = NULL ;
F_35 ( & V_32 -> V_108 , & V_116 ) ;
F_52 ( L_9 , V_74 ,
V_32 -> V_75 ) ;
} else {
F_60 ( V_110 ) ;
F_60 ( V_32 ) ;
F_69 ( & V_115 -> V_76 ) ;
F_52 ( L_10 ,
V_74 , V_115 -> V_75 ,
F_48 ( & V_115 -> V_76 ) ) ;
V_32 = V_115 ;
}
F_29 ( & V_107 ) ;
V_31:
return V_32 ;
}
static void F_70 ( struct V_72 * V_32 )
{
F_71 () ;
F_72 ( & V_32 -> V_117 , V_118 ,
V_119 ) ;
}
static void F_73 ( struct V_72 * V_32 )
{
F_74 () ;
F_21 ( V_118 , & V_32 -> V_117 ) ;
F_75 () ;
F_76 ( & V_32 -> V_117 , V_118 ) ;
}
static bool F_77 ( void )
{
if ( ! V_120 ) {
V_120 = F_78 ( V_121 ) ;
F_79 ( ! V_120 ) ;
}
return ( V_120 != NULL ) ;
}
void T_3 F_80 ( void )
{
if ( V_120 ) {
F_81 ( V_121 ) ;
V_120 = NULL ;
}
}
static int F_82 ( struct V_122 * V_123 ,
struct V_72 * V_32 ,
unsigned int V_124 ,
unsigned int V_125 ,
T_4 V_126 )
{
struct V_127 * V_128 = F_83 ( - V_129 ) ;
struct V_98 * V_105 ;
int V_130 = 0 ;
F_52 ( L_11 , V_74 ,
V_32 -> V_75 , V_126 ) ;
if ( ! F_77 () )
goto V_31;
F_57 (da, &ds->ds_addrs, da_node) {
F_52 ( L_12 ,
V_74 , V_32 -> V_75 , V_105 -> V_106 ) ;
V_128 = V_120 ( V_123 -> V_127 ,
(struct V_78 * ) & V_105 -> V_102 ,
V_105 -> V_131 , V_132 ,
V_124 , V_125 , V_126 ) ;
if ( ! F_84 ( V_128 ) )
break;
}
if ( F_84 ( V_128 ) ) {
V_130 = F_85 ( V_128 ) ;
goto V_31;
}
F_86 () ;
V_32 -> V_4 = V_128 ;
F_52 ( L_13 , V_74 , V_32 -> V_75 ) ;
V_31:
return V_130 ;
}
static int F_87 ( struct V_122 * V_123 ,
struct V_72 * V_32 ,
unsigned int V_124 ,
unsigned int V_125 ,
T_5 V_133 ,
T_4 V_126 )
{
struct V_127 * V_128 = F_83 ( - V_129 ) ;
struct V_98 * V_105 ;
int V_130 = 0 ;
F_52 ( L_11 , V_74 , V_32 -> V_75 ,
V_126 ) ;
F_57 (da, &ds->ds_addrs, da_node) {
F_52 ( L_12 ,
V_74 , V_32 -> V_75 , V_105 -> V_106 ) ;
V_128 = F_88 ( V_123 -> V_127 ,
(struct V_78 * ) & V_105 -> V_102 ,
V_105 -> V_131 , V_132 ,
V_124 , V_125 , V_133 ,
V_126 ) ;
if ( ! F_84 ( V_128 ) )
break;
}
if ( F_84 ( V_128 ) ) {
V_130 = F_85 ( V_128 ) ;
goto V_31;
}
V_130 = F_89 ( V_128 , V_123 -> V_127 -> V_134 ) ;
if ( V_130 )
goto V_135;
F_86 () ;
V_32 -> V_4 = V_128 ;
F_52 ( L_13 , V_74 , V_32 -> V_75 ) ;
V_31:
return V_130 ;
V_135:
F_2 ( V_128 ) ;
goto V_31;
}
void F_90 ( struct V_122 * V_123 , struct V_72 * V_32 ,
struct V_136 * V_137 , unsigned int V_124 ,
unsigned int V_125 , T_5 V_138 ,
T_5 V_133 , T_4 V_126 )
{
if ( F_91 ( V_118 , & V_32 -> V_117 ) == 0 ) {
int V_139 = 0 ;
if ( V_138 == 3 ) {
V_139 = F_82 ( V_123 , V_32 , V_124 ,
V_125 , V_126 ) ;
} else if ( V_138 == 4 ) {
V_139 = F_87 ( V_123 , V_32 , V_124 ,
V_125 , V_133 ,
V_126 ) ;
} else {
F_52 ( L_14 , V_74 ,
V_138 ) ;
V_139 = - V_140 ;
}
if ( V_139 )
F_92 ( V_137 ) ;
F_73 ( V_32 ) ;
} else {
F_70 ( V_32 ) ;
}
}
struct V_98 *
F_93 ( struct V_141 * V_141 , struct V_142 * V_143 , T_1 V_109 )
{
struct V_98 * V_105 = NULL ;
char * V_144 , * V_145 ;
T_6 V_146 ;
int V_147 , V_148 ;
int V_43 [ 2 ] ;
T_7 * V_112 ;
char * V_149 , * V_150 ;
T_2 V_111 , V_151 ;
char * V_152 = L_15 ;
char * V_153 = L_15 ;
V_112 = F_94 ( V_143 , 4 ) ;
if ( F_95 ( ! V_112 ) )
goto V_114;
V_147 = F_96 ( V_112 ++ ) ;
V_112 = F_94 ( V_143 , V_147 ) ;
if ( F_95 ( ! V_112 ) )
goto V_114;
V_149 = F_97 ( V_147 + 1 , V_109 ) ;
if ( F_95 ( ! V_149 ) )
goto V_114;
V_149 [ V_147 ] = '\0' ;
memcpy ( V_149 , V_112 , V_147 ) ;
V_112 = F_94 ( V_143 , 4 ) ;
if ( F_95 ( ! V_112 ) )
goto V_154;
V_148 = F_96 ( V_112 ) ;
V_112 = F_94 ( V_143 , V_148 ) ;
if ( F_95 ( ! V_112 ) )
goto V_154;
if ( V_148 > V_155 + V_156 + 8 ) {
F_52 ( L_16 , V_74 ,
V_148 ) ;
goto V_154;
}
V_144 = F_97 ( V_148 + 1 , V_109 ) ;
if ( ! V_144 ) {
F_52 ( L_17 , V_74 ) ;
goto V_154;
}
V_144 [ V_148 ] = '\0' ;
memcpy ( V_144 , V_112 , V_148 ) ;
V_145 = strrchr ( V_144 , '.' ) ;
if ( ! V_145 ) {
F_52 ( L_18 ,
V_74 ) ;
goto V_157;
}
* V_145 = '-' ;
V_145 = strrchr ( V_144 , '.' ) ;
if ( ! V_145 ) {
F_52 ( L_19
L_20 , V_74 ) ;
goto V_157;
}
* V_145 = '\0' ;
V_105 = F_64 ( sizeof( * V_105 ) , V_109 ) ;
if ( F_95 ( ! V_105 ) )
goto V_157;
F_66 ( & V_105 -> V_101 ) ;
if ( ! F_98 ( V_141 , V_144 , V_145 - V_144 , (struct V_78 * ) & V_105 -> V_102 ,
sizeof( V_105 -> V_102 ) ) ) {
F_52 ( L_21 , V_74 , V_144 ) ;
goto V_158;
}
V_145 ++ ;
sscanf ( V_145 , L_22 , & V_43 [ 0 ] , & V_43 [ 1 ] ) ;
V_146 = F_99 ( ( V_43 [ 0 ] << 8 ) | ( V_43 [ 1 ] ) ) ;
switch ( V_105 -> V_102 . V_159 ) {
case V_87 :
( (struct V_81 * ) & V_105 -> V_102 ) -> V_90 = V_146 ;
V_105 -> V_131 = sizeof( struct V_81 ) ;
V_150 = L_23 ;
V_151 = 3 ;
break;
case V_91 :
( (struct V_83 * ) & V_105 -> V_102 ) -> V_95 = V_146 ;
V_105 -> V_131 = sizeof( struct V_83 ) ;
V_150 = L_24 ;
V_151 = 4 ;
V_152 = L_25 ;
V_153 = L_26 ;
break;
default:
F_52 ( L_27 ,
V_74 , V_105 -> V_102 . V_159 ) ;
goto V_158;
}
if ( V_147 != V_151 || strncmp ( V_149 , V_150 , V_147 ) ) {
F_52 ( L_28 ,
V_74 , V_149 , V_150 ) ;
goto V_158;
}
V_111 = strlen ( V_152 ) + strlen ( V_144 ) + strlen ( V_153 ) + 7 ;
V_105 -> V_106 = F_64 ( V_111 , V_109 ) ;
if ( V_105 -> V_106 )
snprintf ( V_105 -> V_106 , V_111 , L_29 , V_152 ,
V_144 , V_153 , F_100 ( V_146 ) ) ;
F_52 ( L_30 , V_74 , V_105 -> V_106 ) ;
F_60 ( V_144 ) ;
F_60 ( V_149 ) ;
return V_105 ;
V_158:
F_60 ( V_105 ) ;
V_157:
F_52 ( L_31 , V_74 , V_144 ) ;
F_60 ( V_144 ) ;
V_154:
F_60 ( V_149 ) ;
V_114:
return NULL ;
}
void
F_101 ( struct V_8 * V_24 ,
struct V_27 * V_23 ,
struct V_25 * V_26 ,
T_5 V_160 )
{
struct V_39 * V_61 ;
struct V_35 * V_55 ;
F_30 ( V_26 -> V_46 ) ;
V_55 = V_26 -> V_32 -> V_55 ;
V_61 = & V_55 [ V_160 ] . V_37 ;
if ( F_25 ( V_61 ) ) {
F_79 ( V_55 [ V_160 ] . V_38 != NULL ) ;
V_55 [ V_160 ] . V_38 = F_26 ( V_23 ) ;
}
F_102 ( V_29 , & V_24 -> V_30 ) ;
V_26 -> V_32 -> V_33 ++ ;
F_29 ( V_26 -> V_46 ) ;
F_103 ( V_24 , V_61 , V_26 ) ;
}
