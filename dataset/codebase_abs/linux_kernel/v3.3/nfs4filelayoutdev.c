void
F_1 ( struct V_1 * V_2 )
{
if ( V_2 == NULL ) {
F_2 ( L_1 , V_3 ) ;
return;
}
F_2 ( L_2
L_3
L_4
L_5 ,
V_2 -> V_4 ,
F_3 ( & V_2 -> V_5 ) , V_2 -> V_6 ,
V_2 -> V_6 ? V_2 -> V_6 -> V_7 : 0 ) ;
}
static bool
F_4 ( struct V_8 * V_9 , struct V_8 * V_10 )
{
struct V_11 * V_12 , * V_13 ;
struct V_14 * V_15 , * V_16 ;
if ( V_9 -> V_17 != V_10 -> V_17 )
return false ;
switch ( V_9 -> V_17 ) {
case V_18 :
V_12 = (struct V_11 * ) V_9 ;
V_13 = (struct V_11 * ) V_10 ;
if ( V_12 -> V_19 . V_20 == V_13 -> V_19 . V_20 &&
V_12 -> V_21 == V_13 -> V_21 )
return true ;
break;
case V_22 :
V_15 = (struct V_14 * ) V_9 ;
V_16 = (struct V_14 * ) V_10 ;
if ( F_5 ( & V_15 -> V_23 ) ==
V_24 &&
V_15 -> V_25 != V_16 -> V_25 )
return false ;
if ( F_6 ( & V_15 -> V_23 , & V_16 -> V_23 ) &&
V_15 -> V_26 == V_16 -> V_26 )
return true ;
break;
default:
F_7 ( L_6 ,
V_3 , V_9 -> V_17 ) ;
return false ;
}
return false ;
}
static struct V_1 *
F_8 ( struct V_27 * V_28 )
{
struct V_1 * V_2 ;
struct V_29 * V_30 , * V_31 ;
F_9 (da1, dsaddrs, da_node) {
F_9 (ds, &nfs4_data_server_cache, ds_node) {
F_9 (da2, &ds->ds_addrs, da_node) {
if ( F_4 (
(struct V_8 * ) & V_30 -> V_32 ,
(struct V_8 * ) & V_31 -> V_32 ) )
return V_2 ;
}
}
}
return NULL ;
}
static bool
F_10 ( struct V_27 * V_33 ,
struct V_27 * V_34 )
{
struct V_29 * V_30 , * V_31 ;
T_1 V_35 = 0 ,
V_36 = 0 ;
F_9 (da1, dsaddrs1, da_node)
V_35 ++ ;
F_9 (da2, dsaddrs2, da_node) {
bool V_37 = false ;
V_36 ++ ;
F_9 (da1, dsaddrs1, da_node) {
if ( F_4 ( (struct V_8 * ) & V_30 -> V_32 ,
(struct V_8 * ) & V_31 -> V_32 ) ) {
V_37 = true ;
break;
}
}
if ( ! V_37 )
return false ;
}
return ( V_35 == V_36 ) ;
}
static int
F_11 ( struct V_38 * V_39 , struct V_1 * V_2 )
{
struct V_40 * V_41 = F_12 ( - V_42 ) ;
struct V_29 * V_43 ;
int V_44 = 0 ;
F_7 ( L_7 , V_3 , V_2 -> V_4 ,
V_39 -> V_40 -> V_45 -> V_46 -> V_47 ) ;
F_13 ( F_14 ( & V_2 -> V_48 ) ) ;
F_9 (da, &ds->ds_addrs, da_node) {
F_7 ( L_8 ,
V_3 , V_2 -> V_4 , V_43 -> V_49 ) ;
V_41 = F_15 ( V_39 -> V_40 ,
(struct V_8 * ) & V_43 -> V_32 ,
V_43 -> V_50 , V_51 ) ;
if ( ! F_16 ( V_41 ) )
break;
}
if ( F_16 ( V_41 ) ) {
V_44 = F_17 ( V_41 ) ;
goto V_52;
}
if ( ( V_41 -> V_7 & V_53 ) != 0 ) {
if ( ! F_18 ( V_41 ) ) {
V_44 = - V_54 ;
goto V_55;
}
V_2 -> V_6 = V_41 ;
F_7 ( L_9 , V_3 ,
V_2 -> V_4 ) ;
goto V_52;
}
F_19 ( & V_39 -> V_40 -> V_56 ) ;
V_41 -> V_57 = V_39 -> V_40 -> V_57 ;
F_20 ( & V_39 -> V_40 -> V_56 ) ;
V_41 -> V_58 = V_59 ;
V_44 = F_21 ( V_41 ) ;
if ( V_44 )
goto V_55;
V_2 -> V_6 = V_41 ;
F_7 ( L_10 , V_3 , V_2 -> V_4 ) ;
V_52:
return V_44 ;
V_55:
F_22 ( V_41 ) ;
goto V_52;
}
static void
F_23 ( struct V_1 * V_2 )
{
struct V_29 * V_43 ;
F_7 ( L_11 , V_3 ) ;
F_24 (FACILITY)
F_1 ( V_2 ) ;
if ( V_2 -> V_6 )
F_22 ( V_2 -> V_6 ) ;
while ( ! F_14 ( & V_2 -> V_48 ) ) {
V_43 = F_25 ( & V_2 -> V_48 ,
struct V_29 ,
V_60 ) ;
F_26 ( & V_43 -> V_60 ) ;
F_27 ( V_43 -> V_49 ) ;
F_27 ( V_43 ) ;
}
F_27 ( V_2 -> V_4 ) ;
F_27 ( V_2 ) ;
}
void
F_28 ( struct V_61 * V_62 )
{
struct V_1 * V_2 ;
int V_63 ;
F_29 ( & V_62 -> V_64 . V_65 ) ;
for ( V_63 = 0 ; V_63 < V_62 -> V_66 ; V_63 ++ ) {
V_2 = V_62 -> V_67 [ V_63 ] ;
if ( V_2 != NULL ) {
if ( F_30 ( & V_2 -> V_5 ,
& V_68 ) ) {
F_26 ( & V_2 -> V_69 ) ;
F_20 ( & V_68 ) ;
F_23 ( V_2 ) ;
}
}
}
F_27 ( V_62 -> V_70 ) ;
F_27 ( V_62 ) ;
}
static char *
F_31 ( struct V_27 * V_28 , T_2 V_71 )
{
struct V_29 * V_43 ;
char * V_72 ;
T_1 V_73 ;
char * V_74 ;
V_73 = 3 ;
F_9 (da, dsaddrs, da_node) {
V_73 += strlen ( V_43 -> V_49 ) + 1 ;
}
V_72 = F_32 ( V_73 , V_71 ) ;
if ( ! V_72 )
return NULL ;
V_74 = V_72 ;
* ( V_74 ++ ) = '{' ;
V_73 -- ;
F_9 (da, dsaddrs, da_node) {
T_1 V_75 = strlen ( V_43 -> V_49 ) ;
if ( V_75 > V_73 )
goto V_76;
memcpy ( V_74 , V_43 -> V_49 , V_75 ) ;
V_74 += V_75 ;
V_73 -= V_75 ;
if ( V_73 < 1 )
goto V_76;
( * V_74 ++ ) = ',' ;
V_73 -- ;
}
if ( V_73 < 2 )
goto V_76;
* ( V_74 ++ ) = '}' ;
* V_74 = '\0' ;
return V_72 ;
V_76:
F_27 ( V_72 ) ;
return NULL ;
}
static struct V_1 *
F_33 ( struct V_27 * V_28 , T_2 V_71 )
{
struct V_1 * V_77 , * V_2 = NULL ;
char * V_72 ;
if ( F_14 ( V_28 ) ) {
F_7 ( L_12 , V_3 ) ;
goto V_52;
}
V_2 = F_32 ( sizeof( * V_2 ) , V_71 ) ;
if ( ! V_2 )
goto V_52;
V_72 = F_31 ( V_28 , V_71 ) ;
F_19 ( & V_68 ) ;
V_77 = F_8 ( V_28 ) ;
if ( V_77 == NULL ) {
F_34 ( & V_2 -> V_48 ) ;
F_35 ( V_28 , & V_2 -> V_48 ) ;
V_2 -> V_4 = V_72 ;
F_36 ( & V_2 -> V_5 , 1 ) ;
F_34 ( & V_2 -> V_69 ) ;
V_2 -> V_6 = NULL ;
F_37 ( & V_2 -> V_69 , & V_78 ) ;
F_7 ( L_13 , V_3 ,
V_2 -> V_4 ) ;
} else {
if ( ! F_10 ( & V_77 -> V_48 ,
V_28 ) ) {
F_7 ( L_14 ,
V_3 , V_77 -> V_4 , V_72 ) ;
}
F_27 ( V_72 ) ;
F_27 ( V_2 ) ;
F_38 ( & V_77 -> V_5 ) ;
F_7 ( L_15 ,
V_3 , V_77 -> V_4 ,
F_3 ( & V_77 -> V_5 ) ) ;
V_2 = V_77 ;
}
F_20 ( & V_68 ) ;
V_52:
return V_2 ;
}
static struct V_29 *
F_39 ( struct V_79 * V_80 , T_2 V_71 )
{
struct V_29 * V_43 = NULL ;
char * V_81 , * V_82 ;
T_3 V_83 ;
int V_84 , V_85 ;
int V_86 [ 2 ] ;
T_4 * V_74 ;
char * V_87 , * V_88 ;
T_1 V_73 , V_89 ;
char * V_90 = L_16 ;
char * V_91 = L_16 ;
V_74 = F_40 ( V_80 , 4 ) ;
if ( F_41 ( ! V_74 ) )
goto V_76;
V_84 = F_42 ( V_74 ++ ) ;
V_74 = F_40 ( V_80 , V_84 ) ;
if ( F_41 ( ! V_74 ) )
goto V_76;
V_87 = F_43 ( V_84 + 1 , V_71 ) ;
if ( F_41 ( ! V_87 ) )
goto V_76;
V_87 [ V_84 ] = '\0' ;
memcpy ( V_87 , V_74 , V_84 ) ;
V_74 = F_40 ( V_80 , 4 ) ;
if ( F_41 ( ! V_74 ) )
goto V_92;
V_85 = F_42 ( V_74 ) ;
V_74 = F_40 ( V_80 , V_85 ) ;
if ( F_41 ( ! V_74 ) )
goto V_92;
if ( V_85 > V_93 + V_94 + 8 ) {
F_7 ( L_17 , V_3 ,
V_85 ) ;
goto V_92;
}
V_81 = F_43 ( V_85 + 1 , V_71 ) ;
if ( ! V_81 ) {
F_7 ( L_18 , V_3 ) ;
goto V_92;
}
V_81 [ V_85 ] = '\0' ;
memcpy ( V_81 , V_74 , V_85 ) ;
V_82 = strrchr ( V_81 , '.' ) ;
if ( ! V_82 ) {
F_7 ( L_19 ,
V_3 ) ;
goto V_95;
}
* V_82 = '-' ;
V_82 = strrchr ( V_81 , '.' ) ;
if ( ! V_82 ) {
F_7 ( L_20
L_21 , V_3 ) ;
goto V_95;
}
* V_82 = '\0' ;
V_43 = F_32 ( sizeof( * V_43 ) , V_71 ) ;
if ( F_41 ( ! V_43 ) )
goto V_95;
F_34 ( & V_43 -> V_60 ) ;
if ( ! F_44 ( V_81 , V_82 - V_81 , (struct V_8 * ) & V_43 -> V_32 ,
sizeof( V_43 -> V_32 ) ) ) {
F_7 ( L_22 , V_3 , V_81 ) ;
goto V_96;
}
V_82 ++ ;
sscanf ( V_82 , L_23 , & V_86 [ 0 ] , & V_86 [ 1 ] ) ;
V_83 = F_45 ( ( V_86 [ 0 ] << 8 ) | ( V_86 [ 1 ] ) ) ;
switch ( V_43 -> V_32 . V_97 ) {
case V_18 :
( (struct V_11 * ) & V_43 -> V_32 ) -> V_21 = V_83 ;
V_43 -> V_50 = sizeof( struct V_11 ) ;
V_88 = L_24 ;
V_89 = 3 ;
break;
case V_22 :
( (struct V_14 * ) & V_43 -> V_32 ) -> V_26 = V_83 ;
V_43 -> V_50 = sizeof( struct V_14 ) ;
V_88 = L_25 ;
V_89 = 4 ;
V_90 = L_26 ;
V_91 = L_27 ;
break;
default:
F_7 ( L_28 ,
V_3 , V_43 -> V_32 . V_97 ) ;
goto V_96;
}
if ( V_84 != V_89 || strncmp ( V_87 , V_88 , V_84 ) ) {
F_7 ( L_29 ,
V_3 , V_87 , V_88 ) ;
goto V_96;
}
V_73 = strlen ( V_90 ) + strlen ( V_81 ) + strlen ( V_91 ) + 7 ;
V_43 -> V_49 = F_32 ( V_73 , V_71 ) ;
if ( V_43 -> V_49 )
snprintf ( V_43 -> V_49 , V_73 , L_30 , V_90 ,
V_81 , V_91 , F_46 ( V_83 ) ) ;
F_7 ( L_31 , V_3 , V_43 -> V_49 ) ;
F_27 ( V_81 ) ;
F_27 ( V_87 ) ;
return V_43 ;
V_96:
F_27 ( V_43 ) ;
V_95:
F_7 ( L_32 , V_3 , V_81 ) ;
F_27 ( V_81 ) ;
V_92:
F_27 ( V_87 ) ;
V_76:
return NULL ;
}
static struct V_61 *
F_47 ( struct V_98 * V_99 , struct V_100 * V_101 , T_2 V_71 )
{
int V_63 ;
T_5 V_102 , V_103 ;
T_6 * V_104 ;
T_4 * V_74 ;
T_6 * V_70 ;
T_6 V_105 ;
struct V_61 * V_62 = NULL ;
struct V_79 V_106 ;
struct V_107 V_81 ;
struct V_108 * V_109 ;
struct V_27 V_28 ;
struct V_29 * V_43 ;
V_109 = F_48 ( V_71 ) ;
if ( ! V_109 )
goto V_76;
F_49 ( & V_106 , & V_81 , V_101 -> V_110 , V_101 -> V_111 ) ;
F_50 ( & V_106 , F_51 ( V_109 ) , V_112 ) ;
V_74 = F_40 ( & V_106 , 4 ) ;
if ( F_41 ( ! V_74 ) )
goto V_113;
V_102 = F_42 ( V_74 ) ;
F_7 ( L_33 , V_3 , V_102 ) ;
if ( V_102 > V_114 ) {
F_2 ( V_115 L_34
L_35 , V_3 ,
V_102 , V_114 ) ;
goto V_113;
}
V_70 = F_52 ( V_102 , sizeof( T_6 ) , V_71 ) ;
if ( ! V_70 )
goto V_113;
V_74 = F_40 ( & V_106 , V_102 << 2 ) ;
if ( F_41 ( ! V_74 ) )
goto V_116;
V_104 = & V_70 [ 0 ] ;
V_105 = 0 ;
for ( V_63 = 0 ; V_63 < V_102 ; V_63 ++ ) {
* V_104 = F_42 ( V_74 ++ ) ;
V_105 = F_53 ( V_105 , * V_104 ) ;
V_104 ++ ;
}
V_74 = F_40 ( & V_106 , 4 ) ;
if ( F_41 ( ! V_74 ) )
goto V_116;
V_103 = F_42 ( V_74 ) ;
F_7 ( L_36 , V_3 , V_103 ) ;
if ( V_103 > V_117 ) {
F_2 ( V_115 L_37
L_35 , V_3 ,
V_103 , V_117 ) ;
goto V_116;
}
if ( V_105 >= V_103 ) {
F_2 ( V_115 L_38 ,
V_3 , V_105 , V_103 ) ;
goto V_116;
}
V_62 = F_32 ( sizeof( * V_62 ) +
( sizeof( struct V_1 * ) * ( V_103 - 1 ) ) ,
V_71 ) ;
if ( ! V_62 )
goto V_116;
V_62 -> V_118 = V_102 ;
V_62 -> V_70 = V_70 ;
V_70 = NULL ;
V_62 -> V_66 = V_103 ;
F_54 ( & V_62 -> V_64 ,
F_55 ( V_99 ) -> V_119 ,
F_55 ( V_99 ) -> V_40 ,
& V_101 -> V_120 ) ;
F_34 ( & V_28 ) ;
for ( V_63 = 0 ; V_63 < V_62 -> V_66 ; V_63 ++ ) {
int V_121 ;
T_5 V_122 ;
V_74 = F_40 ( & V_106 , 4 ) ;
if ( F_41 ( ! V_74 ) )
goto V_123;
V_122 = F_42 ( V_74 ) ;
for ( V_121 = 0 ; V_121 < V_122 ; V_121 ++ ) {
V_43 = F_39 ( & V_106 , V_71 ) ;
if ( V_43 )
F_56 ( & V_43 -> V_60 , & V_28 ) ;
}
if ( F_14 ( & V_28 ) ) {
F_7 ( L_39 ,
V_3 ) ;
goto V_123;
}
V_62 -> V_67 [ V_63 ] = F_33 ( & V_28 , V_71 ) ;
if ( ! V_62 -> V_67 [ V_63 ] )
goto V_124;
while ( ! F_14 ( & V_28 ) ) {
V_43 = F_25 ( & V_28 ,
struct V_29 ,
V_60 ) ;
F_26 ( & V_43 -> V_60 ) ;
F_27 ( V_43 -> V_49 ) ;
F_27 ( V_43 ) ;
}
}
F_57 ( V_109 ) ;
return V_62 ;
V_124:
while ( ! F_14 ( & V_28 ) ) {
V_43 = F_25 ( & V_28 , struct V_29 ,
V_60 ) ;
F_26 ( & V_43 -> V_60 ) ;
F_27 ( V_43 -> V_49 ) ;
F_27 ( V_43 ) ;
}
V_123:
F_28 ( V_62 ) ;
goto V_113;
V_116:
F_27 ( V_70 ) ;
V_113:
F_57 ( V_109 ) ;
V_76:
F_7 ( L_40 , V_3 ) ;
return NULL ;
}
static struct V_61 *
F_58 ( struct V_98 * V_98 , struct V_100 * V_125 , T_2 V_71 )
{
struct V_126 * V_127 ;
struct V_61 * V_128 , * V_129 ;
V_129 = F_47 ( V_98 , V_125 , V_71 ) ;
if ( ! V_129 ) {
F_2 ( V_115 L_41 ,
V_3 ) ;
return NULL ;
}
V_127 = F_59 ( & V_129 -> V_64 ) ;
V_128 = F_60 ( V_127 , struct V_61 , V_64 ) ;
if ( V_128 != V_129 ) {
F_28 ( V_129 ) ;
return V_128 ;
}
return V_129 ;
}
struct V_61 *
F_61 ( struct V_98 * V_98 , struct V_130 * V_120 , T_2 V_71 )
{
struct V_100 * V_101 = NULL ;
T_5 V_131 ;
int V_132 ;
struct V_108 * * V_110 = NULL ;
struct V_61 * V_62 = NULL ;
int V_133 , V_63 ;
struct V_38 * V_134 = F_55 ( V_98 ) ;
V_131 = V_134 -> V_40 -> V_135 -> V_136 . V_131 ;
V_132 = V_131 >> V_137 ;
F_7 ( L_42 ,
V_3 , V_98 , V_131 , V_132 ) ;
V_101 = F_32 ( sizeof( struct V_100 ) , V_71 ) ;
if ( V_101 == NULL )
return NULL ;
V_110 = F_32 ( V_132 * sizeof( struct V_108 * ) , V_71 ) ;
if ( V_110 == NULL ) {
F_27 ( V_101 ) ;
return NULL ;
}
for ( V_63 = 0 ; V_63 < V_132 ; V_63 ++ ) {
V_110 [ V_63 ] = F_48 ( V_71 ) ;
if ( ! V_110 [ V_63 ] )
goto V_138;
}
memcpy ( & V_101 -> V_120 , V_120 , sizeof( * V_120 ) ) ;
V_101 -> V_139 = V_140 ;
V_101 -> V_110 = V_110 ;
V_101 -> V_141 = 0 ;
V_101 -> V_111 = V_112 * V_132 ;
V_101 -> V_142 = 0 ;
V_133 = F_62 ( V_134 , V_101 ) ;
F_7 ( L_43 , V_3 , V_133 ) ;
if ( V_133 )
goto V_138;
V_62 = F_58 ( V_98 , V_101 , V_71 ) ;
V_138:
for ( V_63 = 0 ; V_63 < V_132 ; V_63 ++ )
F_57 ( V_110 [ V_63 ] ) ;
F_27 ( V_110 ) ;
F_27 ( V_101 ) ;
F_7 ( L_44 , V_3 , V_62 ) ;
return V_62 ;
}
void
F_63 ( struct V_61 * V_62 )
{
F_64 ( & V_62 -> V_64 ) ;
}
T_5
F_65 ( struct V_143 * V_144 , T_7 V_145 )
{
struct V_146 * V_147 = F_66 ( V_144 ) ;
T_8 V_86 ;
V_86 = V_145 - V_147 -> V_148 ;
F_67 ( V_86 , V_147 -> V_149 ) ;
V_86 += V_147 -> V_150 ;
return F_67 ( V_86 , V_147 -> V_62 -> V_118 ) ;
}
T_5
F_68 ( struct V_143 * V_144 , T_5 V_121 )
{
return F_66 ( V_144 ) -> V_62 -> V_70 [ V_121 ] ;
}
struct V_151 *
F_69 ( struct V_143 * V_144 , T_5 V_121 )
{
struct V_146 * V_147 = F_66 ( V_144 ) ;
T_5 V_63 ;
if ( V_147 -> V_152 == V_153 ) {
if ( V_147 -> V_154 == 1 )
V_63 = 0 ;
else if ( V_147 -> V_154 == 0 )
return NULL ;
else
V_63 = F_68 ( V_144 , V_121 ) ;
} else
V_63 = V_121 ;
return V_147 -> V_155 [ V_63 ] ;
}
static void
F_70 ( struct V_61 * V_62 ,
int V_156 , const char * V_4 )
{
T_5 * V_74 = ( T_5 * ) & V_62 -> V_64 . V_65 ;
F_2 ( V_157 L_45
L_46 ,
V_4 , V_156 , V_74 [ 0 ] , V_74 [ 1 ] , V_74 [ 2 ] , V_74 [ 3 ] ) ;
F_19 ( & V_68 ) ;
V_62 -> V_158 |= V_159 ;
F_20 ( & V_68 ) ;
}
struct V_1 *
F_71 ( struct V_143 * V_144 , T_5 V_160 )
{
struct V_61 * V_62 = F_66 ( V_144 ) -> V_62 ;
struct V_1 * V_2 = V_62 -> V_67 [ V_160 ] ;
if ( V_2 == NULL ) {
F_2 ( V_157 L_47 ,
V_3 , V_160 ) ;
return NULL ;
}
if ( ! V_2 -> V_6 ) {
struct V_38 * V_161 = F_55 ( V_144 -> V_162 -> V_163 ) ;
int V_156 ;
if ( V_62 -> V_158 & V_159 ) {
F_7 ( L_48 , V_3 ) ;
return NULL ;
}
V_156 = F_11 ( V_161 , V_2 ) ;
if ( V_156 ) {
F_70 ( V_62 , V_156 ,
V_2 -> V_4 ) ;
return NULL ;
}
}
return V_2 ;
}
