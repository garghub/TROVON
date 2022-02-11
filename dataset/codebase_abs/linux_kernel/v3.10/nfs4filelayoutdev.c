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
static bool
F_8 ( const struct V_27 * V_28 ,
const struct V_27 * V_29 )
{
struct V_30 * V_31 , * V_32 ;
for ( V_31 = F_9 ( V_28 , F_10 ( * V_31 ) , V_33 ) ,
V_32 = F_9 ( V_29 , F_10 ( * V_32 ) , V_33 ) ;
V_31 != NULL && V_32 != NULL ;
V_31 = F_11 ( V_31 -> V_33 . V_34 , F_10 ( * V_31 ) , V_33 ) ,
V_32 = F_11 ( V_32 -> V_33 . V_34 , F_10 ( * V_32 ) , V_33 ) ) {
if ( ! F_4 ( (struct V_8 * ) & V_31 -> V_35 ,
(struct V_8 * ) & V_32 -> V_35 ) )
return false ;
}
if ( V_31 == NULL && V_32 == NULL )
return true ;
return false ;
}
static struct V_1 *
F_12 ( const struct V_27 * V_36 )
{
struct V_1 * V_2 ;
F_13 (ds, &nfs4_data_server_cache, ds_node)
if ( F_8 ( & V_2 -> V_37 , V_36 ) )
return V_2 ;
return NULL ;
}
static int
F_14 ( struct V_38 * V_39 , struct V_1 * V_2 )
{
struct V_40 * V_41 = F_15 ( - V_42 ) ;
struct V_30 * V_43 ;
int V_44 = 0 ;
F_7 ( L_7 , V_3 , V_2 -> V_4 ,
V_39 -> V_40 -> V_45 -> V_46 -> V_47 ) ;
F_13 (da, &ds->ds_addrs, da_node) {
F_7 ( L_8 ,
V_3 , V_2 -> V_4 , V_43 -> V_48 ) ;
V_41 = F_16 ( V_39 -> V_40 ,
(struct V_8 * ) & V_43 -> V_35 ,
V_43 -> V_49 , V_50 ,
V_51 , V_52 ) ;
if ( ! F_17 ( V_41 ) )
break;
}
if ( F_17 ( V_41 ) ) {
V_44 = F_18 ( V_41 ) ;
goto V_53;
}
V_44 = F_19 ( V_41 , V_39 -> V_40 -> V_54 ) ;
if ( V_44 )
goto V_55;
V_2 -> V_6 = V_41 ;
F_7 ( L_9 , V_3 , V_2 -> V_4 ) ;
V_53:
return V_44 ;
V_55:
F_20 ( V_41 ) ;
goto V_53;
}
static void
F_21 ( struct V_1 * V_2 )
{
struct V_30 * V_43 ;
F_7 ( L_10 , V_3 ) ;
F_22 (FACILITY)
F_1 ( V_2 ) ;
if ( V_2 -> V_6 )
F_20 ( V_2 -> V_6 ) ;
while ( ! F_23 ( & V_2 -> V_37 ) ) {
V_43 = F_9 ( & V_2 -> V_37 ,
struct V_30 ,
V_33 ) ;
F_24 ( & V_43 -> V_33 ) ;
F_25 ( V_43 -> V_48 ) ;
F_25 ( V_43 ) ;
}
F_25 ( V_2 -> V_4 ) ;
F_25 ( V_2 ) ;
}
void
F_26 ( struct V_56 * V_57 )
{
struct V_1 * V_2 ;
int V_58 ;
F_27 ( & V_57 -> V_59 . V_60 ) ;
for ( V_58 = 0 ; V_58 < V_57 -> V_61 ; V_58 ++ ) {
V_2 = V_57 -> V_62 [ V_58 ] ;
if ( V_2 != NULL ) {
if ( F_28 ( & V_2 -> V_5 ,
& V_63 ) ) {
F_24 ( & V_2 -> V_64 ) ;
F_29 ( & V_63 ) ;
F_21 ( V_2 ) ;
}
}
}
F_25 ( V_57 -> V_65 ) ;
F_25 ( V_57 ) ;
}
static char *
F_30 ( struct V_27 * V_36 , T_1 V_66 )
{
struct V_30 * V_43 ;
char * V_67 ;
T_2 V_68 ;
char * V_69 ;
V_68 = 3 ;
F_13 (da, dsaddrs, da_node) {
V_68 += strlen ( V_43 -> V_48 ) + 1 ;
}
V_67 = F_31 ( V_68 , V_66 ) ;
if ( ! V_67 )
return NULL ;
V_69 = V_67 ;
* ( V_69 ++ ) = '{' ;
V_68 -- ;
F_13 (da, dsaddrs, da_node) {
T_2 V_70 = strlen ( V_43 -> V_48 ) ;
if ( V_70 > V_68 )
goto V_71;
memcpy ( V_69 , V_43 -> V_48 , V_70 ) ;
V_69 += V_70 ;
V_68 -= V_70 ;
if ( V_68 < 1 )
goto V_71;
( * V_69 ++ ) = ',' ;
V_68 -- ;
}
if ( V_68 < 2 )
goto V_71;
* ( V_69 ++ ) = '}' ;
* V_69 = '\0' ;
return V_67 ;
V_71:
F_25 ( V_67 ) ;
return NULL ;
}
static struct V_1 *
F_32 ( struct V_27 * V_36 , T_1 V_66 )
{
struct V_1 * V_72 , * V_2 = NULL ;
char * V_67 ;
if ( F_23 ( V_36 ) ) {
F_7 ( L_11 , V_3 ) ;
goto V_53;
}
V_2 = F_31 ( sizeof( * V_2 ) , V_66 ) ;
if ( ! V_2 )
goto V_53;
V_67 = F_30 ( V_36 , V_66 ) ;
F_33 ( & V_63 ) ;
V_72 = F_12 ( V_36 ) ;
if ( V_72 == NULL ) {
F_34 ( & V_2 -> V_37 ) ;
F_35 ( V_36 , & V_2 -> V_37 ) ;
V_2 -> V_4 = V_67 ;
F_36 ( & V_2 -> V_5 , 1 ) ;
F_34 ( & V_2 -> V_64 ) ;
V_2 -> V_6 = NULL ;
F_37 ( & V_2 -> V_64 , & V_73 ) ;
F_7 ( L_12 , V_3 ,
V_2 -> V_4 ) ;
} else {
F_25 ( V_67 ) ;
F_25 ( V_2 ) ;
F_38 ( & V_72 -> V_5 ) ;
F_7 ( L_13 ,
V_3 , V_72 -> V_4 ,
F_3 ( & V_72 -> V_5 ) ) ;
V_2 = V_72 ;
}
F_29 ( & V_63 ) ;
V_53:
return V_2 ;
}
static struct V_30 *
F_39 ( struct V_74 * V_74 , struct V_75 * V_76 , T_1 V_66 )
{
struct V_30 * V_43 = NULL ;
char * V_77 , * V_78 ;
T_3 V_79 ;
int V_80 , V_81 ;
int V_82 [ 2 ] ;
T_4 * V_69 ;
char * V_83 , * V_84 ;
T_2 V_68 , V_85 ;
char * V_86 = L_14 ;
char * V_87 = L_14 ;
V_69 = F_40 ( V_76 , 4 ) ;
if ( F_41 ( ! V_69 ) )
goto V_71;
V_80 = F_42 ( V_69 ++ ) ;
V_69 = F_40 ( V_76 , V_80 ) ;
if ( F_41 ( ! V_69 ) )
goto V_71;
V_83 = F_43 ( V_80 + 1 , V_66 ) ;
if ( F_41 ( ! V_83 ) )
goto V_71;
V_83 [ V_80 ] = '\0' ;
memcpy ( V_83 , V_69 , V_80 ) ;
V_69 = F_40 ( V_76 , 4 ) ;
if ( F_41 ( ! V_69 ) )
goto V_88;
V_81 = F_42 ( V_69 ) ;
V_69 = F_40 ( V_76 , V_81 ) ;
if ( F_41 ( ! V_69 ) )
goto V_88;
if ( V_81 > V_89 + V_90 + 8 ) {
F_7 ( L_15 , V_3 ,
V_81 ) ;
goto V_88;
}
V_77 = F_43 ( V_81 + 1 , V_66 ) ;
if ( ! V_77 ) {
F_7 ( L_16 , V_3 ) ;
goto V_88;
}
V_77 [ V_81 ] = '\0' ;
memcpy ( V_77 , V_69 , V_81 ) ;
V_78 = strrchr ( V_77 , '.' ) ;
if ( ! V_78 ) {
F_7 ( L_17 ,
V_3 ) ;
goto V_91;
}
* V_78 = '-' ;
V_78 = strrchr ( V_77 , '.' ) ;
if ( ! V_78 ) {
F_7 ( L_18
L_19 , V_3 ) ;
goto V_91;
}
* V_78 = '\0' ;
V_43 = F_31 ( sizeof( * V_43 ) , V_66 ) ;
if ( F_41 ( ! V_43 ) )
goto V_91;
F_34 ( & V_43 -> V_33 ) ;
if ( ! F_44 ( V_74 , V_77 , V_78 - V_77 , (struct V_8 * ) & V_43 -> V_35 ,
sizeof( V_43 -> V_35 ) ) ) {
F_7 ( L_20 , V_3 , V_77 ) ;
goto V_92;
}
V_78 ++ ;
sscanf ( V_78 , L_21 , & V_82 [ 0 ] , & V_82 [ 1 ] ) ;
V_79 = F_45 ( ( V_82 [ 0 ] << 8 ) | ( V_82 [ 1 ] ) ) ;
switch ( V_43 -> V_35 . V_93 ) {
case V_18 :
( (struct V_11 * ) & V_43 -> V_35 ) -> V_21 = V_79 ;
V_43 -> V_49 = sizeof( struct V_11 ) ;
V_84 = L_22 ;
V_85 = 3 ;
break;
case V_22 :
( (struct V_14 * ) & V_43 -> V_35 ) -> V_26 = V_79 ;
V_43 -> V_49 = sizeof( struct V_14 ) ;
V_84 = L_23 ;
V_85 = 4 ;
V_86 = L_24 ;
V_87 = L_25 ;
break;
default:
F_7 ( L_26 ,
V_3 , V_43 -> V_35 . V_93 ) ;
goto V_92;
}
if ( V_80 != V_85 || strncmp ( V_83 , V_84 , V_80 ) ) {
F_7 ( L_27 ,
V_3 , V_83 , V_84 ) ;
goto V_92;
}
V_68 = strlen ( V_86 ) + strlen ( V_77 ) + strlen ( V_87 ) + 7 ;
V_43 -> V_48 = F_31 ( V_68 , V_66 ) ;
if ( V_43 -> V_48 )
snprintf ( V_43 -> V_48 , V_68 , L_28 , V_86 ,
V_77 , V_87 , F_46 ( V_79 ) ) ;
F_7 ( L_29 , V_3 , V_43 -> V_48 ) ;
F_25 ( V_77 ) ;
F_25 ( V_83 ) ;
return V_43 ;
V_92:
F_25 ( V_43 ) ;
V_91:
F_7 ( L_30 , V_3 , V_77 ) ;
F_25 ( V_77 ) ;
V_88:
F_25 ( V_83 ) ;
V_71:
return NULL ;
}
static struct V_56 *
F_47 ( struct V_94 * V_95 , struct V_96 * V_97 , T_1 V_66 )
{
int V_58 ;
T_5 V_98 , V_99 ;
T_6 * V_100 ;
T_4 * V_69 ;
T_6 * V_65 ;
T_6 V_101 ;
struct V_56 * V_57 = NULL ;
struct V_75 V_102 ;
struct V_103 V_77 ;
struct V_104 * V_105 ;
struct V_27 V_36 ;
struct V_30 * V_43 ;
V_105 = F_48 ( V_66 ) ;
if ( ! V_105 )
goto V_71;
F_49 ( & V_102 , & V_77 , V_97 -> V_106 , V_97 -> V_107 ) ;
F_50 ( & V_102 , F_51 ( V_105 ) , V_108 ) ;
V_69 = F_40 ( & V_102 , 4 ) ;
if ( F_41 ( ! V_69 ) )
goto V_109;
V_98 = F_42 ( V_69 ) ;
F_7 ( L_31 , V_3 , V_98 ) ;
if ( V_98 > V_110 ) {
F_2 ( V_111 L_32
L_33 , V_3 ,
V_98 , V_110 ) ;
goto V_109;
}
V_65 = F_52 ( V_98 , sizeof( T_6 ) , V_66 ) ;
if ( ! V_65 )
goto V_109;
V_69 = F_40 ( & V_102 , V_98 << 2 ) ;
if ( F_41 ( ! V_69 ) )
goto V_112;
V_100 = & V_65 [ 0 ] ;
V_101 = 0 ;
for ( V_58 = 0 ; V_58 < V_98 ; V_58 ++ ) {
* V_100 = F_42 ( V_69 ++ ) ;
V_101 = F_53 ( V_101 , * V_100 ) ;
V_100 ++ ;
}
V_69 = F_40 ( & V_102 , 4 ) ;
if ( F_41 ( ! V_69 ) )
goto V_112;
V_99 = F_42 ( V_69 ) ;
F_7 ( L_34 , V_3 , V_99 ) ;
if ( V_99 > V_113 ) {
F_2 ( V_111 L_35
L_33 , V_3 ,
V_99 , V_113 ) ;
goto V_112;
}
if ( V_101 >= V_99 ) {
F_2 ( V_111 L_36 ,
V_3 , V_101 , V_99 ) ;
goto V_112;
}
V_57 = F_31 ( sizeof( * V_57 ) +
( sizeof( struct V_1 * ) * ( V_99 - 1 ) ) ,
V_66 ) ;
if ( ! V_57 )
goto V_112;
V_57 -> V_114 = V_98 ;
V_57 -> V_65 = V_65 ;
V_65 = NULL ;
V_57 -> V_61 = V_99 ;
F_54 ( & V_57 -> V_59 ,
F_55 ( V_95 ) -> V_115 ,
F_55 ( V_95 ) -> V_40 ,
& V_97 -> V_116 ) ;
F_34 ( & V_36 ) ;
for ( V_58 = 0 ; V_58 < V_57 -> V_61 ; V_58 ++ ) {
int V_117 ;
T_5 V_118 ;
V_69 = F_40 ( & V_102 , 4 ) ;
if ( F_41 ( ! V_69 ) )
goto V_119;
V_118 = F_42 ( V_69 ) ;
for ( V_117 = 0 ; V_117 < V_118 ; V_117 ++ ) {
V_43 = F_39 ( F_55 ( V_95 ) -> V_40 -> V_120 ,
& V_102 , V_66 ) ;
if ( V_43 )
F_56 ( & V_43 -> V_33 , & V_36 ) ;
}
if ( F_23 ( & V_36 ) ) {
F_7 ( L_37 ,
V_3 ) ;
goto V_119;
}
V_57 -> V_62 [ V_58 ] = F_32 ( & V_36 , V_66 ) ;
if ( ! V_57 -> V_62 [ V_58 ] )
goto V_121;
while ( ! F_23 ( & V_36 ) ) {
V_43 = F_9 ( & V_36 ,
struct V_30 ,
V_33 ) ;
F_24 ( & V_43 -> V_33 ) ;
F_25 ( V_43 -> V_48 ) ;
F_25 ( V_43 ) ;
}
}
F_57 ( V_105 ) ;
return V_57 ;
V_121:
while ( ! F_23 ( & V_36 ) ) {
V_43 = F_9 ( & V_36 , struct V_30 ,
V_33 ) ;
F_24 ( & V_43 -> V_33 ) ;
F_25 ( V_43 -> V_48 ) ;
F_25 ( V_43 ) ;
}
V_119:
F_26 ( V_57 ) ;
goto V_109;
V_112:
F_25 ( V_65 ) ;
V_109:
F_57 ( V_105 ) ;
V_71:
F_7 ( L_38 , V_3 ) ;
return NULL ;
}
static struct V_56 *
F_58 ( struct V_94 * V_94 , struct V_96 * V_122 , T_1 V_66 )
{
struct V_123 * V_124 ;
struct V_56 * V_125 , * V_126 ;
V_126 = F_47 ( V_94 , V_122 , V_66 ) ;
if ( ! V_126 ) {
F_2 ( V_111 L_39 ,
V_3 ) ;
return NULL ;
}
V_124 = F_59 ( & V_126 -> V_59 ) ;
V_125 = F_60 ( V_124 , struct V_56 , V_59 ) ;
if ( V_125 != V_126 ) {
F_26 ( V_126 ) ;
return V_125 ;
}
return V_126 ;
}
struct V_56 *
F_61 ( struct V_94 * V_94 , struct V_127 * V_116 , T_1 V_66 )
{
struct V_96 * V_97 = NULL ;
T_5 V_128 ;
int V_129 ;
struct V_104 * * V_106 = NULL ;
struct V_56 * V_57 = NULL ;
int V_130 , V_58 ;
struct V_38 * V_131 = F_55 ( V_94 ) ;
V_128 = V_131 -> V_40 -> V_132 -> V_133 . V_128 ;
V_129 = F_62 ( 0 , V_128 ) ;
F_7 ( L_40 ,
V_3 , V_94 , V_128 , V_129 ) ;
V_97 = F_31 ( sizeof( struct V_96 ) , V_66 ) ;
if ( V_97 == NULL )
return NULL ;
V_106 = F_31 ( V_129 * sizeof( struct V_104 * ) , V_66 ) ;
if ( V_106 == NULL ) {
F_25 ( V_97 ) ;
return NULL ;
}
for ( V_58 = 0 ; V_58 < V_129 ; V_58 ++ ) {
V_106 [ V_58 ] = F_48 ( V_66 ) ;
if ( ! V_106 [ V_58 ] )
goto V_134;
}
memcpy ( & V_97 -> V_116 , V_116 , sizeof( * V_116 ) ) ;
V_97 -> V_135 = V_136 ;
V_97 -> V_106 = V_106 ;
V_97 -> V_137 = 0 ;
V_97 -> V_107 = V_128 ;
V_97 -> V_138 = 0 ;
V_130 = F_63 ( V_131 , V_97 ) ;
F_7 ( L_41 , V_3 , V_130 ) ;
if ( V_130 )
goto V_134;
V_57 = F_58 ( V_94 , V_97 , V_66 ) ;
V_134:
for ( V_58 = 0 ; V_58 < V_129 ; V_58 ++ )
F_57 ( V_106 [ V_58 ] ) ;
F_25 ( V_106 ) ;
F_25 ( V_97 ) ;
F_7 ( L_42 , V_3 , V_57 ) ;
return V_57 ;
}
void
F_64 ( struct V_56 * V_57 )
{
F_65 ( & V_57 -> V_59 ) ;
}
T_5
F_66 ( struct V_139 * V_140 , T_7 V_141 )
{
struct V_142 * V_143 = F_67 ( V_140 ) ;
T_8 V_82 ;
V_82 = V_141 - V_143 -> V_144 ;
F_68 ( V_82 , V_143 -> V_145 ) ;
V_82 += V_143 -> V_146 ;
return F_68 ( V_82 , V_143 -> V_57 -> V_114 ) ;
}
T_5
F_69 ( struct V_139 * V_140 , T_5 V_117 )
{
return F_67 ( V_140 ) -> V_57 -> V_65 [ V_117 ] ;
}
struct V_147 *
F_70 ( struct V_139 * V_140 , T_5 V_117 )
{
struct V_142 * V_143 = F_67 ( V_140 ) ;
T_5 V_58 ;
if ( V_143 -> V_148 == V_149 ) {
if ( V_143 -> V_150 == 1 )
V_58 = 0 ;
else if ( V_143 -> V_150 == 0 )
return NULL ;
else
V_58 = F_69 ( V_140 , V_117 ) ;
} else
V_58 = V_117 ;
return V_143 -> V_151 [ V_58 ] ;
}
static void F_71 ( struct V_1 * V_2 )
{
F_72 () ;
F_73 ( & V_2 -> V_152 , V_153 ,
V_154 , V_155 ) ;
}
static void F_74 ( struct V_1 * V_2 )
{
F_75 () ;
F_76 ( V_153 , & V_2 -> V_152 ) ;
F_77 () ;
F_78 ( & V_2 -> V_152 , V_153 ) ;
}
struct V_1 *
F_79 ( struct V_139 * V_140 , T_5 V_156 )
{
struct V_56 * V_57 = F_67 ( V_140 ) -> V_57 ;
struct V_1 * V_2 = V_57 -> V_62 [ V_156 ] ;
struct V_123 * V_157 = F_80 ( V_140 ) ;
if ( F_81 ( V_157 ) )
return NULL ;
if ( V_2 == NULL ) {
F_2 ( V_158 L_43 ,
V_3 , V_156 ) ;
F_82 ( V_157 ) ;
return NULL ;
}
if ( V_2 -> V_6 )
return V_2 ;
if ( F_83 ( V_153 , & V_2 -> V_152 ) == 0 ) {
struct V_38 * V_159 = F_55 ( V_140 -> V_160 -> V_161 ) ;
int V_162 ;
V_162 = F_14 ( V_159 , V_2 ) ;
if ( V_162 ) {
F_84 ( V_157 ) ;
V_2 = NULL ;
}
F_74 ( V_2 ) ;
} else {
F_71 ( V_2 ) ;
}
return V_2 ;
}
