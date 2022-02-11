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
F_16 ( F_17 ( & V_2 -> V_37 ) ) ;
F_13 (da, &ds->ds_addrs, da_node) {
F_7 ( L_8 ,
V_3 , V_2 -> V_4 , V_43 -> V_48 ) ;
V_41 = F_18 ( V_39 -> V_40 ,
(struct V_8 * ) & V_43 -> V_35 ,
V_43 -> V_49 , V_50 ) ;
if ( ! F_19 ( V_41 ) )
break;
}
if ( F_19 ( V_41 ) ) {
V_44 = F_20 ( V_41 ) ;
goto V_51;
}
if ( ( V_41 -> V_7 & V_52 ) != 0 ) {
if ( ! F_21 ( V_41 ) ) {
V_44 = - V_53 ;
goto V_54;
}
V_2 -> V_6 = V_41 ;
F_7 ( L_9 , V_3 ,
V_2 -> V_4 ) ;
goto V_51;
}
F_22 ( & V_39 -> V_40 -> V_55 ) ;
V_41 -> V_56 = V_39 -> V_40 -> V_56 ;
F_23 ( & V_39 -> V_40 -> V_55 ) ;
V_41 -> V_57 = V_58 ;
V_44 = F_24 ( V_41 ) ;
if ( V_44 )
goto V_54;
V_2 -> V_6 = V_41 ;
F_7 ( L_10 , V_3 , V_2 -> V_4 ) ;
V_51:
return V_44 ;
V_54:
F_25 ( V_41 ) ;
goto V_51;
}
static void
F_26 ( struct V_1 * V_2 )
{
struct V_30 * V_43 ;
F_7 ( L_11 , V_3 ) ;
F_27 (FACILITY)
F_1 ( V_2 ) ;
if ( V_2 -> V_6 )
F_25 ( V_2 -> V_6 ) ;
while ( ! F_17 ( & V_2 -> V_37 ) ) {
V_43 = F_9 ( & V_2 -> V_37 ,
struct V_30 ,
V_33 ) ;
F_28 ( & V_43 -> V_33 ) ;
F_29 ( V_43 -> V_48 ) ;
F_29 ( V_43 ) ;
}
F_29 ( V_2 -> V_4 ) ;
F_29 ( V_2 ) ;
}
void
F_30 ( struct V_59 * V_60 )
{
struct V_1 * V_2 ;
int V_61 ;
F_31 ( & V_60 -> V_62 . V_63 ) ;
for ( V_61 = 0 ; V_61 < V_60 -> V_64 ; V_61 ++ ) {
V_2 = V_60 -> V_65 [ V_61 ] ;
if ( V_2 != NULL ) {
if ( F_32 ( & V_2 -> V_5 ,
& V_66 ) ) {
F_28 ( & V_2 -> V_67 ) ;
F_23 ( & V_66 ) ;
F_26 ( V_2 ) ;
}
}
}
F_29 ( V_60 -> V_68 ) ;
F_29 ( V_60 ) ;
}
static char *
F_33 ( struct V_27 * V_36 , T_1 V_69 )
{
struct V_30 * V_43 ;
char * V_70 ;
T_2 V_71 ;
char * V_72 ;
V_71 = 3 ;
F_13 (da, dsaddrs, da_node) {
V_71 += strlen ( V_43 -> V_48 ) + 1 ;
}
V_70 = F_34 ( V_71 , V_69 ) ;
if ( ! V_70 )
return NULL ;
V_72 = V_70 ;
* ( V_72 ++ ) = '{' ;
V_71 -- ;
F_13 (da, dsaddrs, da_node) {
T_2 V_73 = strlen ( V_43 -> V_48 ) ;
if ( V_73 > V_71 )
goto V_74;
memcpy ( V_72 , V_43 -> V_48 , V_73 ) ;
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
F_29 ( V_70 ) ;
return NULL ;
}
static struct V_1 *
F_35 ( struct V_27 * V_36 , T_1 V_69 )
{
struct V_1 * V_75 , * V_2 = NULL ;
char * V_70 ;
if ( F_17 ( V_36 ) ) {
F_7 ( L_12 , V_3 ) ;
goto V_51;
}
V_2 = F_34 ( sizeof( * V_2 ) , V_69 ) ;
if ( ! V_2 )
goto V_51;
V_70 = F_33 ( V_36 , V_69 ) ;
F_22 ( & V_66 ) ;
V_75 = F_12 ( V_36 ) ;
if ( V_75 == NULL ) {
F_36 ( & V_2 -> V_37 ) ;
F_37 ( V_36 , & V_2 -> V_37 ) ;
V_2 -> V_4 = V_70 ;
F_38 ( & V_2 -> V_5 , 1 ) ;
F_36 ( & V_2 -> V_67 ) ;
V_2 -> V_6 = NULL ;
F_39 ( & V_2 -> V_67 , & V_76 ) ;
F_7 ( L_13 , V_3 ,
V_2 -> V_4 ) ;
} else {
F_29 ( V_70 ) ;
F_29 ( V_2 ) ;
F_40 ( & V_75 -> V_5 ) ;
F_7 ( L_14 ,
V_3 , V_75 -> V_4 ,
F_3 ( & V_75 -> V_5 ) ) ;
V_2 = V_75 ;
}
F_23 ( & V_66 ) ;
V_51:
return V_2 ;
}
static struct V_30 *
F_41 ( struct V_77 * V_77 , struct V_78 * V_79 , T_1 V_69 )
{
struct V_30 * V_43 = NULL ;
char * V_80 , * V_81 ;
T_3 V_82 ;
int V_83 , V_84 ;
int V_85 [ 2 ] ;
T_4 * V_72 ;
char * V_86 , * V_87 ;
T_2 V_71 , V_88 ;
char * V_89 = L_15 ;
char * V_90 = L_15 ;
V_72 = F_42 ( V_79 , 4 ) ;
if ( F_43 ( ! V_72 ) )
goto V_74;
V_83 = F_44 ( V_72 ++ ) ;
V_72 = F_42 ( V_79 , V_83 ) ;
if ( F_43 ( ! V_72 ) )
goto V_74;
V_86 = F_45 ( V_83 + 1 , V_69 ) ;
if ( F_43 ( ! V_86 ) )
goto V_74;
V_86 [ V_83 ] = '\0' ;
memcpy ( V_86 , V_72 , V_83 ) ;
V_72 = F_42 ( V_79 , 4 ) ;
if ( F_43 ( ! V_72 ) )
goto V_91;
V_84 = F_44 ( V_72 ) ;
V_72 = F_42 ( V_79 , V_84 ) ;
if ( F_43 ( ! V_72 ) )
goto V_91;
if ( V_84 > V_92 + V_93 + 8 ) {
F_7 ( L_16 , V_3 ,
V_84 ) ;
goto V_91;
}
V_80 = F_45 ( V_84 + 1 , V_69 ) ;
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
V_43 = F_34 ( sizeof( * V_43 ) , V_69 ) ;
if ( F_43 ( ! V_43 ) )
goto V_94;
F_36 ( & V_43 -> V_33 ) ;
if ( ! F_46 ( V_77 , V_80 , V_81 - V_80 , (struct V_8 * ) & V_43 -> V_35 ,
sizeof( V_43 -> V_35 ) ) ) {
F_7 ( L_21 , V_3 , V_80 ) ;
goto V_95;
}
V_81 ++ ;
sscanf ( V_81 , L_22 , & V_85 [ 0 ] , & V_85 [ 1 ] ) ;
V_82 = F_47 ( ( V_85 [ 0 ] << 8 ) | ( V_85 [ 1 ] ) ) ;
switch ( V_43 -> V_35 . V_96 ) {
case V_18 :
( (struct V_11 * ) & V_43 -> V_35 ) -> V_21 = V_82 ;
V_43 -> V_49 = sizeof( struct V_11 ) ;
V_87 = L_23 ;
V_88 = 3 ;
break;
case V_22 :
( (struct V_14 * ) & V_43 -> V_35 ) -> V_26 = V_82 ;
V_43 -> V_49 = sizeof( struct V_14 ) ;
V_87 = L_24 ;
V_88 = 4 ;
V_89 = L_25 ;
V_90 = L_26 ;
break;
default:
F_7 ( L_27 ,
V_3 , V_43 -> V_35 . V_96 ) ;
goto V_95;
}
if ( V_83 != V_88 || strncmp ( V_86 , V_87 , V_83 ) ) {
F_7 ( L_28 ,
V_3 , V_86 , V_87 ) ;
goto V_95;
}
V_71 = strlen ( V_89 ) + strlen ( V_80 ) + strlen ( V_90 ) + 7 ;
V_43 -> V_48 = F_34 ( V_71 , V_69 ) ;
if ( V_43 -> V_48 )
snprintf ( V_43 -> V_48 , V_71 , L_29 , V_89 ,
V_80 , V_90 , F_48 ( V_82 ) ) ;
F_7 ( L_30 , V_3 , V_43 -> V_48 ) ;
F_29 ( V_80 ) ;
F_29 ( V_86 ) ;
return V_43 ;
V_95:
F_29 ( V_43 ) ;
V_94:
F_7 ( L_31 , V_3 , V_80 ) ;
F_29 ( V_80 ) ;
V_91:
F_29 ( V_86 ) ;
V_74:
return NULL ;
}
static struct V_59 *
F_49 ( struct V_97 * V_98 , struct V_99 * V_100 , T_1 V_69 )
{
int V_61 ;
T_5 V_101 , V_102 ;
T_6 * V_103 ;
T_4 * V_72 ;
T_6 * V_68 ;
T_6 V_104 ;
struct V_59 * V_60 = NULL ;
struct V_78 V_105 ;
struct V_106 V_80 ;
struct V_107 * V_108 ;
struct V_27 V_36 ;
struct V_30 * V_43 ;
V_108 = F_50 ( V_69 ) ;
if ( ! V_108 )
goto V_74;
F_51 ( & V_105 , & V_80 , V_100 -> V_109 , V_100 -> V_110 ) ;
F_52 ( & V_105 , F_53 ( V_108 ) , V_111 ) ;
V_72 = F_42 ( & V_105 , 4 ) ;
if ( F_43 ( ! V_72 ) )
goto V_112;
V_101 = F_44 ( V_72 ) ;
F_7 ( L_32 , V_3 , V_101 ) ;
if ( V_101 > V_113 ) {
F_2 ( V_114 L_33
L_34 , V_3 ,
V_101 , V_113 ) ;
goto V_112;
}
V_68 = F_54 ( V_101 , sizeof( T_6 ) , V_69 ) ;
if ( ! V_68 )
goto V_112;
V_72 = F_42 ( & V_105 , V_101 << 2 ) ;
if ( F_43 ( ! V_72 ) )
goto V_115;
V_103 = & V_68 [ 0 ] ;
V_104 = 0 ;
for ( V_61 = 0 ; V_61 < V_101 ; V_61 ++ ) {
* V_103 = F_44 ( V_72 ++ ) ;
V_104 = F_55 ( V_104 , * V_103 ) ;
V_103 ++ ;
}
V_72 = F_42 ( & V_105 , 4 ) ;
if ( F_43 ( ! V_72 ) )
goto V_115;
V_102 = F_44 ( V_72 ) ;
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
V_60 = F_34 ( sizeof( * V_60 ) +
( sizeof( struct V_1 * ) * ( V_102 - 1 ) ) ,
V_69 ) ;
if ( ! V_60 )
goto V_115;
V_60 -> V_117 = V_101 ;
V_60 -> V_68 = V_68 ;
V_68 = NULL ;
V_60 -> V_64 = V_102 ;
F_56 ( & V_60 -> V_62 ,
F_57 ( V_98 ) -> V_118 ,
F_57 ( V_98 ) -> V_40 ,
& V_100 -> V_119 ) ;
F_36 ( & V_36 ) ;
for ( V_61 = 0 ; V_61 < V_60 -> V_64 ; V_61 ++ ) {
int V_120 ;
T_5 V_121 ;
V_72 = F_42 ( & V_105 , 4 ) ;
if ( F_43 ( ! V_72 ) )
goto V_122;
V_121 = F_44 ( V_72 ) ;
for ( V_120 = 0 ; V_120 < V_121 ; V_120 ++ ) {
V_43 = F_41 ( F_57 ( V_98 ) -> V_40 -> V_77 ,
& V_105 , V_69 ) ;
if ( V_43 )
F_58 ( & V_43 -> V_33 , & V_36 ) ;
}
if ( F_17 ( & V_36 ) ) {
F_7 ( L_38 ,
V_3 ) ;
goto V_122;
}
V_60 -> V_65 [ V_61 ] = F_35 ( & V_36 , V_69 ) ;
if ( ! V_60 -> V_65 [ V_61 ] )
goto V_123;
while ( ! F_17 ( & V_36 ) ) {
V_43 = F_9 ( & V_36 ,
struct V_30 ,
V_33 ) ;
F_28 ( & V_43 -> V_33 ) ;
F_29 ( V_43 -> V_48 ) ;
F_29 ( V_43 ) ;
}
}
F_59 ( V_108 ) ;
return V_60 ;
V_123:
while ( ! F_17 ( & V_36 ) ) {
V_43 = F_9 ( & V_36 , struct V_30 ,
V_33 ) ;
F_28 ( & V_43 -> V_33 ) ;
F_29 ( V_43 -> V_48 ) ;
F_29 ( V_43 ) ;
}
V_122:
F_30 ( V_60 ) ;
goto V_112;
V_115:
F_29 ( V_68 ) ;
V_112:
F_59 ( V_108 ) ;
V_74:
F_7 ( L_39 , V_3 ) ;
return NULL ;
}
static struct V_59 *
F_60 ( struct V_97 * V_97 , struct V_99 * V_124 , T_1 V_69 )
{
struct V_125 * V_126 ;
struct V_59 * V_127 , * V_128 ;
V_128 = F_49 ( V_97 , V_124 , V_69 ) ;
if ( ! V_128 ) {
F_2 ( V_114 L_40 ,
V_3 ) ;
return NULL ;
}
V_126 = F_61 ( & V_128 -> V_62 ) ;
V_127 = F_62 ( V_126 , struct V_59 , V_62 ) ;
if ( V_127 != V_128 ) {
F_30 ( V_128 ) ;
return V_127 ;
}
return V_128 ;
}
struct V_59 *
F_63 ( struct V_97 * V_97 , struct V_129 * V_119 , T_1 V_69 )
{
struct V_99 * V_100 = NULL ;
T_5 V_130 ;
int V_131 ;
struct V_107 * * V_109 = NULL ;
struct V_59 * V_60 = NULL ;
int V_132 , V_61 ;
struct V_38 * V_133 = F_57 ( V_97 ) ;
V_130 = V_133 -> V_40 -> V_134 -> V_135 . V_130 ;
V_131 = F_64 ( 0 , V_130 ) ;
F_7 ( L_41 ,
V_3 , V_97 , V_130 , V_131 ) ;
V_100 = F_34 ( sizeof( struct V_99 ) , V_69 ) ;
if ( V_100 == NULL )
return NULL ;
V_109 = F_34 ( V_131 * sizeof( struct V_107 * ) , V_69 ) ;
if ( V_109 == NULL ) {
F_29 ( V_100 ) ;
return NULL ;
}
for ( V_61 = 0 ; V_61 < V_131 ; V_61 ++ ) {
V_109 [ V_61 ] = F_50 ( V_69 ) ;
if ( ! V_109 [ V_61 ] )
goto V_136;
}
memcpy ( & V_100 -> V_119 , V_119 , sizeof( * V_119 ) ) ;
V_100 -> V_137 = V_138 ;
V_100 -> V_109 = V_109 ;
V_100 -> V_139 = 0 ;
V_100 -> V_110 = V_111 * V_131 ;
V_100 -> V_140 = 0 ;
V_132 = F_65 ( V_133 , V_100 ) ;
F_7 ( L_42 , V_3 , V_132 ) ;
if ( V_132 )
goto V_136;
V_60 = F_60 ( V_97 , V_100 , V_69 ) ;
V_136:
for ( V_61 = 0 ; V_61 < V_131 ; V_61 ++ )
F_59 ( V_109 [ V_61 ] ) ;
F_29 ( V_109 ) ;
F_29 ( V_100 ) ;
F_7 ( L_43 , V_3 , V_60 ) ;
return V_60 ;
}
void
F_66 ( struct V_59 * V_60 )
{
F_67 ( & V_60 -> V_62 ) ;
}
T_5
F_68 ( struct V_141 * V_142 , T_7 V_143 )
{
struct V_144 * V_145 = F_69 ( V_142 ) ;
T_8 V_85 ;
V_85 = V_143 - V_145 -> V_146 ;
F_70 ( V_85 , V_145 -> V_147 ) ;
V_85 += V_145 -> V_148 ;
return F_70 ( V_85 , V_145 -> V_60 -> V_117 ) ;
}
T_5
F_71 ( struct V_141 * V_142 , T_5 V_120 )
{
return F_69 ( V_142 ) -> V_60 -> V_68 [ V_120 ] ;
}
struct V_149 *
F_72 ( struct V_141 * V_142 , T_5 V_120 )
{
struct V_144 * V_145 = F_69 ( V_142 ) ;
T_5 V_61 ;
if ( V_145 -> V_150 == V_151 ) {
if ( V_145 -> V_152 == 1 )
V_61 = 0 ;
else if ( V_145 -> V_152 == 0 )
return NULL ;
else
V_61 = F_71 ( V_142 , V_120 ) ;
} else
V_61 = V_120 ;
return V_145 -> V_153 [ V_61 ] ;
}
static void
F_73 ( struct V_59 * V_60 ,
int V_154 , const char * V_4 )
{
T_5 * V_72 = ( T_5 * ) & V_60 -> V_62 . V_63 ;
F_2 ( V_155 L_44
L_45 ,
V_4 , V_154 , V_72 [ 0 ] , V_72 [ 1 ] , V_72 [ 2 ] , V_72 [ 3 ] ) ;
F_22 ( & V_66 ) ;
V_60 -> V_156 |= V_157 ;
F_23 ( & V_66 ) ;
}
struct V_1 *
F_74 ( struct V_141 * V_142 , T_5 V_158 )
{
struct V_59 * V_60 = F_69 ( V_142 ) -> V_60 ;
struct V_1 * V_2 = V_60 -> V_65 [ V_158 ] ;
if ( V_2 == NULL ) {
F_2 ( V_155 L_46 ,
V_3 , V_158 ) ;
return NULL ;
}
if ( ! V_2 -> V_6 ) {
struct V_38 * V_159 = F_57 ( V_142 -> V_160 -> V_161 ) ;
int V_154 ;
if ( V_60 -> V_156 & V_157 ) {
F_7 ( L_47 , V_3 ) ;
return NULL ;
}
V_154 = F_14 ( V_159 , V_2 ) ;
if ( V_154 ) {
F_73 ( V_60 , V_154 ,
V_2 -> V_4 ) ;
return NULL ;
}
}
return V_2 ;
}
