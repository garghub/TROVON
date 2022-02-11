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
void F_14 ( struct V_38 * V_39 )
{
struct V_1 * V_2 ;
struct V_38 * V_40 = NULL ;
F_7 ( L_7 , V_3 , V_39 ) ;
F_15 ( & V_41 ) ;
F_13 (ds, &nfs4_data_server_cache, ds_node)
if ( V_2 -> V_6 && V_2 -> V_6 == V_39 ) {
V_40 = V_2 -> V_6 ;
V_2 -> V_6 = NULL ;
}
F_16 ( & V_41 ) ;
if ( V_40 ) {
F_17 ( V_42 , & V_39 -> V_43 ) ;
F_18 ( V_39 ) ;
}
}
static int
F_19 ( struct V_44 * V_45 , struct V_1 * V_2 )
{
struct V_38 * V_39 = F_20 ( - V_46 ) ;
struct V_30 * V_47 ;
int V_48 = 0 ;
F_7 ( L_8 , V_3 , V_2 -> V_4 ,
V_45 -> V_38 -> V_49 -> V_50 -> V_51 ) ;
F_21 ( F_22 ( & V_2 -> V_37 ) ) ;
F_13 (da, &ds->ds_addrs, da_node) {
F_7 ( L_9 ,
V_3 , V_2 -> V_4 , V_47 -> V_52 ) ;
V_39 = F_23 ( V_45 -> V_38 ,
(struct V_8 * ) & V_47 -> V_35 ,
V_47 -> V_53 , V_54 ,
V_55 , V_56 ) ;
if ( ! F_24 ( V_39 ) )
break;
}
if ( F_24 ( V_39 ) ) {
V_48 = F_25 ( V_39 ) ;
goto V_57;
}
V_48 = F_26 ( V_39 , V_45 -> V_38 -> V_58 ) ;
if ( V_48 )
goto V_59;
V_2 -> V_6 = V_39 ;
F_7 ( L_10 , V_3 , V_2 -> V_4 ) ;
V_57:
return V_48 ;
V_59:
F_18 ( V_39 ) ;
goto V_57;
}
static void
F_27 ( struct V_1 * V_2 )
{
struct V_30 * V_47 ;
F_7 ( L_11 , V_3 ) ;
F_28 (FACILITY)
F_1 ( V_2 ) ;
if ( V_2 -> V_6 )
F_18 ( V_2 -> V_6 ) ;
while ( ! F_22 ( & V_2 -> V_37 ) ) {
V_47 = F_9 ( & V_2 -> V_37 ,
struct V_30 ,
V_33 ) ;
F_29 ( & V_47 -> V_33 ) ;
F_30 ( V_47 -> V_52 ) ;
F_30 ( V_47 ) ;
}
F_30 ( V_2 -> V_4 ) ;
F_30 ( V_2 ) ;
}
void
F_31 ( struct V_60 * V_61 )
{
struct V_1 * V_2 ;
int V_62 ;
F_32 ( & V_61 -> V_63 . V_64 ) ;
for ( V_62 = 0 ; V_62 < V_61 -> V_65 ; V_62 ++ ) {
V_2 = V_61 -> V_66 [ V_62 ] ;
if ( V_2 != NULL ) {
if ( F_33 ( & V_2 -> V_5 ,
& V_41 ) ) {
F_29 ( & V_2 -> V_67 ) ;
F_16 ( & V_41 ) ;
F_27 ( V_2 ) ;
}
}
}
F_30 ( V_61 -> V_68 ) ;
F_30 ( V_61 ) ;
}
static char *
F_34 ( struct V_27 * V_36 , T_1 V_69 )
{
struct V_30 * V_47 ;
char * V_70 ;
T_2 V_71 ;
char * V_72 ;
V_71 = 3 ;
F_13 (da, dsaddrs, da_node) {
V_71 += strlen ( V_47 -> V_52 ) + 1 ;
}
V_70 = F_35 ( V_71 , V_69 ) ;
if ( ! V_70 )
return NULL ;
V_72 = V_70 ;
* ( V_72 ++ ) = '{' ;
V_71 -- ;
F_13 (da, dsaddrs, da_node) {
T_2 V_73 = strlen ( V_47 -> V_52 ) ;
if ( V_73 > V_71 )
goto V_74;
memcpy ( V_72 , V_47 -> V_52 , V_73 ) ;
V_72 += V_73 ;
V_71 -= V_73 ;
if ( V_71 < 1 )
goto V_74;
( * V_72 ++ ) = ',' ;
V_71 -- ;
}
if ( V_71 < 2 )
goto V_74;
* ( V_72 ++ ) = '}' ;
* V_72 = '\0' ;
return V_70 ;
V_74:
F_30 ( V_70 ) ;
return NULL ;
}
static struct V_1 *
F_36 ( struct V_27 * V_36 , T_1 V_69 )
{
struct V_1 * V_75 , * V_2 = NULL ;
char * V_70 ;
if ( F_22 ( V_36 ) ) {
F_7 ( L_12 , V_3 ) ;
goto V_57;
}
V_2 = F_35 ( sizeof( * V_2 ) , V_69 ) ;
if ( ! V_2 )
goto V_57;
V_70 = F_34 ( V_36 , V_69 ) ;
F_15 ( & V_41 ) ;
V_75 = F_12 ( V_36 ) ;
if ( V_75 == NULL ) {
F_37 ( & V_2 -> V_37 ) ;
F_38 ( V_36 , & V_2 -> V_37 ) ;
V_2 -> V_4 = V_70 ;
F_39 ( & V_2 -> V_5 , 1 ) ;
F_37 ( & V_2 -> V_67 ) ;
V_2 -> V_6 = NULL ;
F_40 ( & V_2 -> V_67 , & V_76 ) ;
F_7 ( L_13 , V_3 ,
V_2 -> V_4 ) ;
} else {
F_30 ( V_70 ) ;
F_30 ( V_2 ) ;
F_41 ( & V_75 -> V_5 ) ;
F_7 ( L_14 ,
V_3 , V_75 -> V_4 ,
F_3 ( & V_75 -> V_5 ) ) ;
V_2 = V_75 ;
}
F_16 ( & V_41 ) ;
V_57:
return V_2 ;
}
static struct V_30 *
F_42 ( struct V_77 * V_77 , struct V_78 * V_79 , T_1 V_69 )
{
struct V_30 * V_47 = NULL ;
char * V_80 , * V_81 ;
T_3 V_82 ;
int V_83 , V_84 ;
int V_85 [ 2 ] ;
T_4 * V_72 ;
char * V_86 , * V_87 ;
T_2 V_71 , V_88 ;
char * V_89 = L_15 ;
char * V_90 = L_15 ;
V_72 = F_43 ( V_79 , 4 ) ;
if ( F_44 ( ! V_72 ) )
goto V_74;
V_83 = F_45 ( V_72 ++ ) ;
V_72 = F_43 ( V_79 , V_83 ) ;
if ( F_44 ( ! V_72 ) )
goto V_74;
V_86 = F_46 ( V_83 + 1 , V_69 ) ;
if ( F_44 ( ! V_86 ) )
goto V_74;
V_86 [ V_83 ] = '\0' ;
memcpy ( V_86 , V_72 , V_83 ) ;
V_72 = F_43 ( V_79 , 4 ) ;
if ( F_44 ( ! V_72 ) )
goto V_91;
V_84 = F_45 ( V_72 ) ;
V_72 = F_43 ( V_79 , V_84 ) ;
if ( F_44 ( ! V_72 ) )
goto V_91;
if ( V_84 > V_92 + V_93 + 8 ) {
F_7 ( L_16 , V_3 ,
V_84 ) ;
goto V_91;
}
V_80 = F_46 ( V_84 + 1 , V_69 ) ;
if ( ! V_80 ) {
F_7 ( L_17 , V_3 ) ;
goto V_91;
}
V_80 [ V_84 ] = '\0' ;
memcpy ( V_80 , V_72 , V_84 ) ;
V_81 = strrchr ( V_80 , '.' ) ;
if ( ! V_81 ) {
F_7 ( L_18 ,
V_3 ) ;
goto V_94;
}
* V_81 = '-' ;
V_81 = strrchr ( V_80 , '.' ) ;
if ( ! V_81 ) {
F_7 ( L_19
L_20 , V_3 ) ;
goto V_94;
}
* V_81 = '\0' ;
V_47 = F_35 ( sizeof( * V_47 ) , V_69 ) ;
if ( F_44 ( ! V_47 ) )
goto V_94;
F_37 ( & V_47 -> V_33 ) ;
if ( ! F_47 ( V_77 , V_80 , V_81 - V_80 , (struct V_8 * ) & V_47 -> V_35 ,
sizeof( V_47 -> V_35 ) ) ) {
F_7 ( L_21 , V_3 , V_80 ) ;
goto V_95;
}
V_81 ++ ;
sscanf ( V_81 , L_22 , & V_85 [ 0 ] , & V_85 [ 1 ] ) ;
V_82 = F_48 ( ( V_85 [ 0 ] << 8 ) | ( V_85 [ 1 ] ) ) ;
switch ( V_47 -> V_35 . V_96 ) {
case V_18 :
( (struct V_11 * ) & V_47 -> V_35 ) -> V_21 = V_82 ;
V_47 -> V_53 = sizeof( struct V_11 ) ;
V_87 = L_23 ;
V_88 = 3 ;
break;
case V_22 :
( (struct V_14 * ) & V_47 -> V_35 ) -> V_26 = V_82 ;
V_47 -> V_53 = sizeof( struct V_14 ) ;
V_87 = L_24 ;
V_88 = 4 ;
V_89 = L_25 ;
V_90 = L_26 ;
break;
default:
F_7 ( L_27 ,
V_3 , V_47 -> V_35 . V_96 ) ;
goto V_95;
}
if ( V_83 != V_88 || strncmp ( V_86 , V_87 , V_83 ) ) {
F_7 ( L_28 ,
V_3 , V_86 , V_87 ) ;
goto V_95;
}
V_71 = strlen ( V_89 ) + strlen ( V_80 ) + strlen ( V_90 ) + 7 ;
V_47 -> V_52 = F_35 ( V_71 , V_69 ) ;
if ( V_47 -> V_52 )
snprintf ( V_47 -> V_52 , V_71 , L_29 , V_89 ,
V_80 , V_90 , F_49 ( V_82 ) ) ;
F_7 ( L_30 , V_3 , V_47 -> V_52 ) ;
F_30 ( V_80 ) ;
F_30 ( V_86 ) ;
return V_47 ;
V_95:
F_30 ( V_47 ) ;
V_94:
F_7 ( L_31 , V_3 , V_80 ) ;
F_30 ( V_80 ) ;
V_91:
F_30 ( V_86 ) ;
V_74:
return NULL ;
}
static struct V_60 *
F_50 ( struct V_97 * V_98 , struct V_99 * V_100 , T_1 V_69 )
{
int V_62 ;
T_5 V_101 , V_102 ;
T_6 * V_103 ;
T_4 * V_72 ;
T_6 * V_68 ;
T_6 V_104 ;
struct V_60 * V_61 = NULL ;
struct V_78 V_105 ;
struct V_106 V_80 ;
struct V_107 * V_108 ;
struct V_27 V_36 ;
struct V_30 * V_47 ;
V_108 = F_51 ( V_69 ) ;
if ( ! V_108 )
goto V_74;
F_52 ( & V_105 , & V_80 , V_100 -> V_109 , V_100 -> V_110 ) ;
F_53 ( & V_105 , F_54 ( V_108 ) , V_111 ) ;
V_72 = F_43 ( & V_105 , 4 ) ;
if ( F_44 ( ! V_72 ) )
goto V_112;
V_101 = F_45 ( V_72 ) ;
F_7 ( L_32 , V_3 , V_101 ) ;
if ( V_101 > V_113 ) {
F_2 ( V_114 L_33
L_34 , V_3 ,
V_101 , V_113 ) ;
goto V_112;
}
V_68 = F_55 ( V_101 , sizeof( T_6 ) , V_69 ) ;
if ( ! V_68 )
goto V_112;
V_72 = F_43 ( & V_105 , V_101 << 2 ) ;
if ( F_44 ( ! V_72 ) )
goto V_115;
V_103 = & V_68 [ 0 ] ;
V_104 = 0 ;
for ( V_62 = 0 ; V_62 < V_101 ; V_62 ++ ) {
* V_103 = F_45 ( V_72 ++ ) ;
V_104 = F_56 ( V_104 , * V_103 ) ;
V_103 ++ ;
}
V_72 = F_43 ( & V_105 , 4 ) ;
if ( F_44 ( ! V_72 ) )
goto V_115;
V_102 = F_45 ( V_72 ) ;
F_7 ( L_35 , V_3 , V_102 ) ;
if ( V_102 > V_116 ) {
F_2 ( V_114 L_36
L_34 , V_3 ,
V_102 , V_116 ) ;
goto V_115;
}
if ( V_104 >= V_102 ) {
F_2 ( V_114 L_37 ,
V_3 , V_104 , V_102 ) ;
goto V_115;
}
V_61 = F_35 ( sizeof( * V_61 ) +
( sizeof( struct V_1 * ) * ( V_102 - 1 ) ) ,
V_69 ) ;
if ( ! V_61 )
goto V_115;
V_61 -> V_117 = V_101 ;
V_61 -> V_68 = V_68 ;
V_68 = NULL ;
V_61 -> V_65 = V_102 ;
F_57 ( & V_61 -> V_63 ,
F_58 ( V_98 ) -> V_118 ,
F_58 ( V_98 ) -> V_38 ,
& V_100 -> V_119 ) ;
F_37 ( & V_36 ) ;
for ( V_62 = 0 ; V_62 < V_61 -> V_65 ; V_62 ++ ) {
int V_120 ;
T_5 V_121 ;
V_72 = F_43 ( & V_105 , 4 ) ;
if ( F_44 ( ! V_72 ) )
goto V_122;
V_121 = F_45 ( V_72 ) ;
for ( V_120 = 0 ; V_120 < V_121 ; V_120 ++ ) {
V_47 = F_42 ( F_58 ( V_98 ) -> V_38 -> V_123 ,
& V_105 , V_69 ) ;
if ( V_47 )
F_59 ( & V_47 -> V_33 , & V_36 ) ;
}
if ( F_22 ( & V_36 ) ) {
F_7 ( L_38 ,
V_3 ) ;
goto V_122;
}
V_61 -> V_66 [ V_62 ] = F_36 ( & V_36 , V_69 ) ;
if ( ! V_61 -> V_66 [ V_62 ] )
goto V_124;
while ( ! F_22 ( & V_36 ) ) {
V_47 = F_9 ( & V_36 ,
struct V_30 ,
V_33 ) ;
F_29 ( & V_47 -> V_33 ) ;
F_30 ( V_47 -> V_52 ) ;
F_30 ( V_47 ) ;
}
}
F_60 ( V_108 ) ;
return V_61 ;
V_124:
while ( ! F_22 ( & V_36 ) ) {
V_47 = F_9 ( & V_36 , struct V_30 ,
V_33 ) ;
F_29 ( & V_47 -> V_33 ) ;
F_30 ( V_47 -> V_52 ) ;
F_30 ( V_47 ) ;
}
V_122:
F_31 ( V_61 ) ;
goto V_112;
V_115:
F_30 ( V_68 ) ;
V_112:
F_60 ( V_108 ) ;
V_74:
F_7 ( L_39 , V_3 ) ;
return NULL ;
}
static struct V_60 *
F_61 ( struct V_97 * V_97 , struct V_99 * V_125 , T_1 V_69 )
{
struct V_126 * V_127 ;
struct V_60 * V_128 , * V_129 ;
V_129 = F_50 ( V_97 , V_125 , V_69 ) ;
if ( ! V_129 ) {
F_2 ( V_114 L_40 ,
V_3 ) ;
return NULL ;
}
V_127 = F_62 ( & V_129 -> V_63 ) ;
V_128 = F_63 ( V_127 , struct V_60 , V_63 ) ;
if ( V_128 != V_129 ) {
F_31 ( V_129 ) ;
return V_128 ;
}
return V_129 ;
}
struct V_60 *
F_64 ( struct V_97 * V_97 , struct V_130 * V_119 , T_1 V_69 )
{
struct V_99 * V_100 = NULL ;
T_5 V_131 ;
int V_132 ;
struct V_107 * * V_109 = NULL ;
struct V_60 * V_61 = NULL ;
int V_133 , V_62 ;
struct V_44 * V_134 = F_58 ( V_97 ) ;
V_131 = V_134 -> V_38 -> V_135 -> V_136 . V_131 ;
V_132 = F_65 ( 0 , V_131 ) ;
F_7 ( L_41 ,
V_3 , V_97 , V_131 , V_132 ) ;
V_100 = F_35 ( sizeof( struct V_99 ) , V_69 ) ;
if ( V_100 == NULL )
return NULL ;
V_109 = F_35 ( V_132 * sizeof( struct V_107 * ) , V_69 ) ;
if ( V_109 == NULL ) {
F_30 ( V_100 ) ;
return NULL ;
}
for ( V_62 = 0 ; V_62 < V_132 ; V_62 ++ ) {
V_109 [ V_62 ] = F_51 ( V_69 ) ;
if ( ! V_109 [ V_62 ] )
goto V_137;
}
memcpy ( & V_100 -> V_119 , V_119 , sizeof( * V_119 ) ) ;
V_100 -> V_138 = V_139 ;
V_100 -> V_109 = V_109 ;
V_100 -> V_140 = 0 ;
V_100 -> V_110 = V_131 ;
V_100 -> V_141 = 0 ;
V_133 = F_66 ( V_134 , V_100 ) ;
F_7 ( L_42 , V_3 , V_133 ) ;
if ( V_133 )
goto V_137;
V_61 = F_61 ( V_97 , V_100 , V_69 ) ;
V_137:
for ( V_62 = 0 ; V_62 < V_132 ; V_62 ++ )
F_60 ( V_109 [ V_62 ] ) ;
F_30 ( V_109 ) ;
F_30 ( V_100 ) ;
F_7 ( L_43 , V_3 , V_61 ) ;
return V_61 ;
}
void
F_67 ( struct V_60 * V_61 )
{
F_68 ( & V_61 -> V_63 ) ;
}
T_5
F_69 ( struct V_142 * V_143 , T_7 V_144 )
{
struct V_145 * V_146 = F_70 ( V_143 ) ;
T_8 V_85 ;
V_85 = V_144 - V_146 -> V_147 ;
F_71 ( V_85 , V_146 -> V_148 ) ;
V_85 += V_146 -> V_149 ;
return F_71 ( V_85 , V_146 -> V_61 -> V_117 ) ;
}
T_5
F_72 ( struct V_142 * V_143 , T_5 V_120 )
{
return F_70 ( V_143 ) -> V_61 -> V_68 [ V_120 ] ;
}
struct V_150 *
F_73 ( struct V_142 * V_143 , T_5 V_120 )
{
struct V_145 * V_146 = F_70 ( V_143 ) ;
T_5 V_62 ;
if ( V_146 -> V_151 == V_152 ) {
if ( V_146 -> V_153 == 1 )
V_62 = 0 ;
else if ( V_146 -> V_153 == 0 )
return NULL ;
else
V_62 = F_72 ( V_143 , V_120 ) ;
} else
V_62 = V_120 ;
return V_146 -> V_154 [ V_62 ] ;
}
struct V_1 *
F_74 ( struct V_142 * V_143 , T_5 V_155 )
{
struct V_60 * V_61 = F_70 ( V_143 ) -> V_61 ;
struct V_1 * V_2 = V_61 -> V_66 [ V_155 ] ;
struct V_126 * V_156 = F_75 ( V_143 ) ;
if ( F_76 ( V_156 ) )
return NULL ;
if ( V_2 == NULL ) {
F_2 ( V_157 L_44 ,
V_3 , V_155 ) ;
goto V_158;
}
if ( ! V_2 -> V_6 ) {
struct V_44 * V_159 = F_58 ( V_143 -> V_160 -> V_161 ) ;
int V_162 ;
V_162 = F_19 ( V_159 , V_2 ) ;
if ( V_162 )
goto V_158;
}
return V_2 ;
V_158:
F_77 ( V_156 ) ;
return NULL ;
}
