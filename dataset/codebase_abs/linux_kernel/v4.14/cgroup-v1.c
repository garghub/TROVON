bool F_1 ( int V_1 )
{
return V_2 & ( 1 << V_1 ) ;
}
int F_2 ( struct V_3 * V_4 , struct V_3 * V_5 )
{
struct V_6 * V_7 ;
int V_8 = 0 ;
F_3 ( & V_9 ) ;
F_4 ( & V_10 ) ;
F_5 (root) {
struct V_11 * V_12 ;
if ( V_7 == & V_13 )
continue;
F_6 ( & V_14 ) ;
V_12 = F_7 ( V_4 , V_7 ) ;
F_8 ( & V_14 ) ;
V_8 = F_9 ( V_12 , V_5 , false ) ;
if ( V_8 )
break;
}
F_10 ( & V_10 ) ;
F_11 ( & V_9 ) ;
return V_8 ;
}
int F_12 ( struct V_11 * V_15 , struct V_11 * V_4 )
{
F_13 ( V_16 ) ;
struct V_17 * V_18 ;
struct V_19 V_20 ;
struct V_3 * V_21 ;
int V_22 ;
if ( F_14 ( V_15 ) )
return - V_23 ;
V_22 = F_15 ( V_15 ) ;
if ( V_22 )
return V_22 ;
F_3 ( & V_9 ) ;
F_4 ( & V_10 ) ;
F_6 ( & V_14 ) ;
F_16 (link, &from->cset_links, cset_link)
F_17 ( V_18 -> V_24 , V_15 , & V_16 ) ;
F_8 ( & V_14 ) ;
V_22 = F_18 ( & V_16 ) ;
if ( V_22 )
goto V_25;
do {
F_19 ( & V_4 -> V_26 , 0 , & V_20 ) ;
V_21 = F_20 ( & V_20 ) ;
if ( V_21 )
F_21 ( V_21 ) ;
F_22 ( & V_20 ) ;
if ( V_21 ) {
V_22 = F_23 ( V_21 , false , & V_16 ) ;
if ( ! V_22 )
F_24 ( V_15 , V_21 , false ) ;
F_25 ( V_21 ) ;
}
} while ( V_21 && ! V_22 );
V_25:
F_26 ( & V_16 ) ;
F_10 ( & V_10 ) ;
F_11 ( & V_9 ) ;
return V_22 ;
}
static void * F_27 ( int V_27 )
{
if ( F_28 ( V_27 ) )
return F_29 ( V_27 * sizeof( V_28 ) ) ;
else
return F_30 ( V_27 * sizeof( V_28 ) , V_29 ) ;
}
static void F_31 ( void * V_30 )
{
F_32 ( V_30 ) ;
}
void F_33 ( struct V_11 * V_31 )
{
struct V_32 * V_33 , * V_34 ;
F_3 ( & V_31 -> V_35 ) ;
F_34 (l, tmp_l, &cgrp->pidlists, links)
F_35 ( V_36 , & V_33 -> V_37 , 0 ) ;
F_11 ( & V_31 -> V_35 ) ;
F_36 ( V_36 ) ;
F_37 ( ! F_38 ( & V_31 -> V_38 ) ) ;
}
static void F_39 ( struct V_39 * V_40 )
{
struct V_41 * V_42 = F_40 ( V_40 ) ;
struct V_32 * V_33 = F_41 ( V_42 , struct V_32 ,
V_37 ) ;
struct V_32 * V_43 = NULL ;
F_3 ( & V_33 -> V_44 -> V_35 ) ;
if ( ! F_42 ( V_42 ) ) {
F_43 ( & V_33 -> V_45 ) ;
F_31 ( V_33 -> V_46 ) ;
F_44 ( V_33 -> V_47 . V_48 ) ;
V_43 = V_33 ;
}
F_11 ( & V_33 -> V_44 -> V_35 ) ;
F_45 ( V_43 ) ;
}
static int F_46 ( V_28 * V_46 , int V_49 )
{
int V_50 , V_51 = 1 ;
if ( V_49 == 0 || V_49 == 1 )
return V_49 ;
for ( V_50 = 1 ; V_50 < V_49 ; V_50 ++ ) {
while ( V_46 [ V_50 ] == V_46 [ V_50 - 1 ] ) {
V_50 ++ ;
if ( V_50 == V_49 )
goto V_52;
}
V_46 [ V_51 ] = V_46 [ V_50 ] ;
V_51 ++ ;
}
V_52:
return V_51 ;
}
static int F_47 ( const void * V_53 , const void * V_54 )
{
return * ( V_28 * ) V_53 - * ( V_28 * ) V_54 ;
}
static struct V_32 * F_48 ( struct V_11 * V_31 ,
enum V_55 type )
{
struct V_32 * V_33 ;
struct V_56 * V_48 = F_49 ( V_57 ) ;
F_50 ( & V_31 -> V_35 ) ;
F_16 (l, &cgrp->pidlists, links)
if ( V_33 -> V_47 . type == type && V_33 -> V_47 . V_48 == V_48 )
return V_33 ;
return NULL ;
}
static struct V_32 * F_51 ( struct V_11 * V_31 ,
enum V_55 type )
{
struct V_32 * V_33 ;
F_50 ( & V_31 -> V_35 ) ;
V_33 = F_48 ( V_31 , type ) ;
if ( V_33 )
return V_33 ;
V_33 = F_52 ( sizeof( struct V_32 ) , V_29 ) ;
if ( ! V_33 )
return V_33 ;
F_53 ( & V_33 -> V_37 , F_39 ) ;
V_33 -> V_47 . type = type ;
V_33 -> V_47 . V_48 = F_54 ( F_49 ( V_57 ) ) ;
V_33 -> V_44 = V_31 ;
F_55 ( & V_33 -> V_45 , & V_31 -> V_38 ) ;
return V_33 ;
}
int F_56 ( const struct V_11 * V_31 )
{
int V_27 = 0 ;
struct V_17 * V_18 ;
F_6 ( & V_14 ) ;
F_16 (link, &cgrp->cset_links, cset_link)
V_27 += V_18 -> V_24 -> V_58 ;
F_8 ( & V_14 ) ;
return V_27 ;
}
static int F_57 ( struct V_11 * V_31 , enum V_55 type ,
struct V_32 * * V_59 )
{
V_28 * V_60 ;
int V_49 ;
int V_61 , V_62 = 0 ;
struct V_19 V_20 ;
struct V_3 * V_5 ;
struct V_32 * V_33 ;
F_50 ( & V_31 -> V_35 ) ;
V_49 = F_56 ( V_31 ) ;
V_60 = F_27 ( V_49 ) ;
if ( ! V_60 )
return - V_63 ;
F_19 ( & V_31 -> V_26 , 0 , & V_20 ) ;
while ( ( V_5 = F_20 ( & V_20 ) ) ) {
if ( F_58 ( V_62 == V_49 ) )
break;
if ( type == V_64 )
V_61 = F_59 ( V_5 ) ;
else
V_61 = F_60 ( V_5 ) ;
if ( V_61 > 0 )
V_60 [ V_62 ++ ] = V_61 ;
}
F_22 ( & V_20 ) ;
V_49 = V_62 ;
F_61 ( V_60 , V_49 , sizeof( V_28 ) , F_47 , NULL ) ;
if ( type == V_64 )
V_49 = F_46 ( V_60 , V_49 ) ;
V_33 = F_51 ( V_31 , type ) ;
if ( ! V_33 ) {
F_31 ( V_60 ) ;
return - V_63 ;
}
F_31 ( V_33 -> V_46 ) ;
V_33 -> V_46 = V_60 ;
V_33 -> V_49 = V_49 ;
* V_59 = V_33 ;
return 0 ;
}
static void * F_62 ( struct V_65 * V_66 , T_1 * V_67 )
{
struct V_68 * V_69 = V_66 -> V_70 ;
struct V_11 * V_31 = F_63 ( V_66 ) -> V_11 ;
struct V_32 * V_33 ;
enum V_55 type = F_64 ( V_66 ) -> V_70 ;
int V_71 = 0 , V_61 = * V_67 ;
int * V_72 , V_22 ;
F_3 ( & V_31 -> V_35 ) ;
if ( V_69 -> V_73 )
V_69 -> V_73 = F_48 ( V_31 , type ) ;
if ( ! V_69 -> V_73 ) {
V_22 = F_57 ( V_31 , type ,
(struct V_32 * * ) & V_69 -> V_73 ) ;
if ( V_22 )
return F_65 ( V_22 ) ;
}
V_33 = V_69 -> V_73 ;
if ( V_61 ) {
int V_74 = V_33 -> V_49 ;
while ( V_71 < V_74 ) {
int V_75 = ( V_71 + V_74 ) / 2 ;
if ( V_33 -> V_46 [ V_75 ] == V_61 ) {
V_71 = V_75 ;
break;
} else if ( V_33 -> V_46 [ V_75 ] <= V_61 )
V_71 = V_75 + 1 ;
else
V_74 = V_75 ;
}
}
if ( V_71 >= V_33 -> V_49 )
return NULL ;
V_72 = V_33 -> V_46 + V_71 ;
* V_67 = * V_72 ;
return V_72 ;
}
static void F_66 ( struct V_65 * V_66 , void * V_76 )
{
struct V_68 * V_69 = V_66 -> V_70 ;
struct V_32 * V_33 = V_69 -> V_73 ;
if ( V_33 )
F_35 ( V_36 , & V_33 -> V_37 ,
V_77 ) ;
F_11 ( & F_63 ( V_66 ) -> V_11 -> V_35 ) ;
}
static void * F_67 ( struct V_65 * V_66 , void * V_76 , T_1 * V_67 )
{
struct V_68 * V_69 = V_66 -> V_70 ;
struct V_32 * V_33 = V_69 -> V_73 ;
V_28 * V_30 = V_76 ;
V_28 * V_74 = V_33 -> V_46 + V_33 -> V_49 ;
V_30 ++ ;
if ( V_30 >= V_74 ) {
return NULL ;
} else {
* V_67 = * V_30 ;
return V_30 ;
}
}
static int F_68 ( struct V_65 * V_66 , void * V_76 )
{
F_69 ( V_66 , L_1 , * ( int * ) V_76 ) ;
return 0 ;
}
static T_2 F_70 ( struct V_68 * V_69 ,
char * V_78 , T_3 V_79 , T_1 V_80 ,
bool V_81 )
{
struct V_11 * V_31 ;
struct V_3 * V_21 ;
const struct V_82 * V_82 , * V_83 ;
T_2 V_22 ;
V_31 = F_71 ( V_69 -> V_84 , false ) ;
if ( ! V_31 )
return - V_85 ;
V_21 = F_72 ( V_78 , V_81 ) ;
V_22 = F_73 ( V_21 ) ;
if ( V_22 )
goto V_86;
V_82 = F_74 () ;
V_83 = F_75 ( V_21 ) ;
if ( ! F_76 ( V_82 -> V_87 , V_88 ) &&
! F_76 ( V_82 -> V_87 , V_83 -> V_89 ) &&
! F_76 ( V_82 -> V_87 , V_83 -> V_90 ) )
V_22 = - V_91 ;
F_77 ( V_83 ) ;
if ( V_22 )
goto V_92;
V_22 = F_9 ( V_31 , V_21 , V_81 ) ;
V_92:
F_78 ( V_21 ) ;
V_86:
F_79 ( V_69 -> V_84 ) ;
return V_22 ? : V_79 ;
}
static T_2 F_80 ( struct V_68 * V_69 ,
char * V_78 , T_3 V_79 , T_1 V_80 )
{
return F_70 ( V_69 , V_78 , V_79 , V_80 , true ) ;
}
static T_2 F_81 ( struct V_68 * V_69 ,
char * V_78 , T_3 V_79 , T_1 V_80 )
{
return F_70 ( V_69 , V_78 , V_79 , V_80 , false ) ;
}
static T_2 F_82 ( struct V_68 * V_69 ,
char * V_78 , T_3 V_79 , T_1 V_80 )
{
struct V_11 * V_31 ;
F_83 ( sizeof( V_31 -> V_7 -> V_93 ) < V_94 ) ;
V_31 = F_71 ( V_69 -> V_84 , false ) ;
if ( ! V_31 )
return - V_85 ;
F_84 ( & V_95 ) ;
F_85 ( V_31 -> V_7 -> V_93 , F_86 ( V_78 ) ,
sizeof( V_31 -> V_7 -> V_93 ) ) ;
F_87 ( & V_95 ) ;
F_79 ( V_69 -> V_84 ) ;
return V_79 ;
}
static int F_88 ( struct V_65 * V_96 , void * V_76 )
{
struct V_11 * V_31 = F_63 ( V_96 ) -> V_11 ;
F_84 ( & V_95 ) ;
F_89 ( V_96 , V_31 -> V_7 -> V_93 ) ;
F_87 ( & V_95 ) ;
F_90 ( V_96 , '\n' ) ;
return 0 ;
}
static int F_91 ( struct V_65 * V_96 , void * V_76 )
{
F_89 ( V_96 , L_2 ) ;
return 0 ;
}
static T_4 F_92 ( struct V_97 * V_98 ,
struct V_99 * V_100 )
{
return F_93 ( V_98 -> V_11 ) ;
}
static int F_94 ( struct V_97 * V_98 ,
struct V_99 * V_100 , T_4 V_101 )
{
if ( V_101 )
F_95 ( V_102 , & V_98 -> V_11 -> V_103 ) ;
else
F_96 ( V_102 , & V_98 -> V_11 -> V_103 ) ;
return 0 ;
}
static T_4 F_97 ( struct V_97 * V_98 ,
struct V_99 * V_100 )
{
return F_98 ( V_104 , & V_98 -> V_11 -> V_103 ) ;
}
static int F_99 ( struct V_97 * V_98 ,
struct V_99 * V_100 , T_4 V_101 )
{
if ( V_101 )
F_95 ( V_104 , & V_98 -> V_11 -> V_103 ) ;
else
F_96 ( V_104 , & V_98 -> V_11 -> V_103 ) ;
return 0 ;
}
static int F_100 ( struct V_65 * V_105 , void * V_76 )
{
struct V_106 * V_107 ;
int V_108 ;
F_89 ( V_105 , L_3 ) ;
F_3 ( & V_9 ) ;
F_101 (ss, i)
F_69 ( V_105 , L_4 ,
V_107 -> V_109 , V_107 -> V_7 -> V_110 ,
F_102 ( & V_107 -> V_7 -> V_111 ) ,
F_103 ( V_108 ) ) ;
F_11 ( & V_9 ) ;
return 0 ;
}
static int F_104 ( struct V_112 * V_112 , struct V_113 * V_113 )
{
return F_105 ( V_113 , F_100 , NULL ) ;
}
int F_106 ( struct V_114 * V_115 , struct V_116 * V_116 )
{
struct V_117 * V_84 = F_107 ( V_116 ) ;
struct V_11 * V_31 ;
struct V_19 V_20 ;
struct V_3 * V_5 ;
if ( V_116 -> V_118 -> V_119 != & V_120 || ! V_84 ||
F_108 ( V_84 ) != V_121 )
return - V_23 ;
F_3 ( & V_9 ) ;
F_109 () ;
V_31 = F_110 ( * ( void V_122 V_123 * * ) & V_84 -> V_73 ) ;
if ( ! V_31 || F_111 ( V_31 ) ) {
F_112 () ;
F_11 ( & V_9 ) ;
return - V_124 ;
}
F_112 () ;
F_19 ( & V_31 -> V_26 , 0 , & V_20 ) ;
while ( ( V_5 = F_20 ( & V_20 ) ) ) {
switch ( V_5 -> V_125 ) {
case V_126 :
V_115 -> V_127 ++ ;
break;
case V_128 :
V_115 -> V_129 ++ ;
break;
case V_130 :
V_115 -> V_131 ++ ;
break;
case V_132 :
V_115 -> V_133 ++ ;
break;
default:
if ( F_113 ( V_5 ) )
V_115 -> V_134 ++ ;
break;
}
}
F_22 ( & V_20 ) ;
F_11 ( & V_9 ) ;
return 0 ;
}
void F_114 ( struct V_11 * V_31 )
{
if ( F_93 ( V_31 ) && ! F_115 ( V_31 ) &&
! F_116 ( & V_31 -> V_26 ) && ! F_111 ( V_31 ) )
F_117 ( & V_31 -> V_135 ) ;
}
void F_118 ( struct V_39 * V_40 )
{
struct V_11 * V_31 =
F_41 ( V_40 , struct V_11 , V_135 ) ;
char * V_136 = NULL , * V_137 = NULL ;
char * V_138 [ 3 ] , * V_139 [ 3 ] ;
int V_22 ;
F_3 ( & V_9 ) ;
V_136 = F_30 ( V_94 , V_29 ) ;
V_137 = F_119 ( V_31 -> V_7 -> V_93 , V_29 ) ;
if ( ! V_136 || ! V_137 )
goto V_140;
F_6 ( & V_14 ) ;
V_22 = F_120 ( V_31 , V_136 , V_94 , & V_141 ) ;
F_8 ( & V_14 ) ;
if ( V_22 < 0 || V_22 >= V_94 )
goto V_140;
V_138 [ 0 ] = V_137 ;
V_138 [ 1 ] = V_136 ;
V_138 [ 2 ] = NULL ;
V_139 [ 0 ] = L_5 ;
V_139 [ 1 ] = L_6 ;
V_139 [ 2 ] = NULL ;
F_11 ( & V_9 ) ;
F_121 ( V_138 [ 0 ] , V_138 , V_139 , V_142 ) ;
goto V_143;
V_140:
F_11 ( & V_9 ) ;
V_143:
F_45 ( V_137 ) ;
F_45 ( V_136 ) ;
}
static int F_122 ( struct V_117 * V_84 , struct V_117 * V_144 ,
const char * V_145 )
{
struct V_11 * V_31 = V_84 -> V_73 ;
int V_22 ;
if ( F_108 ( V_84 ) != V_121 )
return - V_146 ;
if ( V_84 -> V_147 != V_144 )
return - V_148 ;
F_123 ( V_144 ) ;
F_123 ( V_84 ) ;
F_3 ( & V_9 ) ;
V_22 = F_124 ( V_84 , V_144 , V_145 ) ;
if ( ! V_22 )
F_125 ( V_31 ) ;
F_11 ( & V_9 ) ;
F_126 ( V_84 ) ;
F_126 ( V_144 ) ;
return V_22 ;
}
static int F_127 ( struct V_65 * V_96 , struct V_149 * V_150 )
{
struct V_6 * V_7 = F_128 ( V_150 ) ;
struct V_106 * V_107 ;
int V_1 ;
F_101 (ss, ssid)
if ( V_7 -> V_151 & ( 1 << V_1 ) )
F_129 ( V_96 , V_107 -> V_109 , NULL ) ;
if ( V_7 -> V_103 & V_152 )
F_89 ( V_96 , L_7 ) ;
if ( V_7 -> V_103 & V_153 )
F_89 ( V_96 , L_8 ) ;
if ( V_7 -> V_103 & V_154 )
F_89 ( V_96 , L_9 ) ;
F_84 ( & V_95 ) ;
if ( strlen ( V_7 -> V_93 ) )
F_129 ( V_96 , L_10 ,
V_7 -> V_93 ) ;
F_87 ( & V_95 ) ;
if ( F_98 ( V_104 , & V_7 -> V_31 . V_103 ) )
F_89 ( V_96 , L_11 ) ;
if ( strlen ( V_7 -> V_155 ) )
F_129 ( V_96 , L_12 , V_7 -> V_155 ) ;
return 0 ;
}
static int F_130 ( char * V_156 , struct V_157 * V_158 )
{
char * V_159 , * V_160 = V_156 ;
bool V_161 = false , V_162 = false ;
T_5 V_163 = V_164 ;
struct V_106 * V_107 ;
int V_165 = 0 ;
int V_108 ;
#ifdef F_131
V_163 = ~ ( ( T_5 ) 1 << V_166 ) ;
#endif
memset ( V_158 , 0 , sizeof( * V_158 ) ) ;
while ( ( V_159 = F_132 ( & V_160 , L_13 ) ) != NULL ) {
V_165 ++ ;
if ( ! * V_159 )
return - V_23 ;
if ( ! strcmp ( V_159 , L_14 ) ) {
V_158 -> V_167 = true ;
continue;
}
if ( ! strcmp ( V_159 , L_15 ) ) {
if ( V_162 )
return - V_23 ;
V_161 = true ;
continue;
}
if ( ! strcmp ( V_159 , L_16 ) ) {
V_158 -> V_103 |= V_152 ;
continue;
}
if ( ! strcmp ( V_159 , L_17 ) ) {
V_158 -> V_168 = true ;
continue;
}
if ( ! strcmp ( V_159 , L_18 ) ) {
V_158 -> V_103 |= V_154 ;
continue;
}
if ( ! strcmp ( V_159 , L_19 ) ) {
V_158 -> V_103 |= V_153 ;
continue;
}
if ( ! strncmp ( V_159 , L_20 , 14 ) ) {
if ( V_158 -> V_169 )
return - V_23 ;
V_158 -> V_169 =
F_133 ( V_159 + 14 , V_94 - 1 , V_29 ) ;
if ( ! V_158 -> V_169 )
return - V_63 ;
continue;
}
if ( ! strncmp ( V_159 , L_21 , 5 ) ) {
const char * V_155 = V_159 + 5 ;
if ( ! strlen ( V_155 ) )
return - V_23 ;
for ( V_108 = 0 ; V_108 < strlen ( V_155 ) ; V_108 ++ ) {
char V_170 = V_155 [ V_108 ] ;
if ( isalnum ( V_170 ) )
continue;
if ( ( V_170 == '.' ) || ( V_170 == '-' ) || ( V_170 == '_' ) )
continue;
return - V_23 ;
}
if ( V_158 -> V_155 )
return - V_23 ;
V_158 -> V_155 = F_133 ( V_155 ,
V_171 - 1 ,
V_29 ) ;
if ( ! V_158 -> V_155 )
return - V_63 ;
continue;
}
F_101 (ss, i) {
if ( strcmp ( V_159 , V_107 -> V_109 ) )
continue;
if ( ! F_103 ( V_108 ) )
continue;
if ( F_1 ( V_108 ) )
continue;
if ( V_161 )
return - V_23 ;
V_158 -> V_151 |= ( 1 << V_108 ) ;
V_162 = true ;
break;
}
if ( V_108 == V_172 )
return - V_124 ;
}
if ( V_161 || ( ! V_162 && ! V_158 -> V_167 && ! V_158 -> V_155 ) )
F_101 (ss, i)
if ( F_103 ( V_108 ) && ! F_1 ( V_108 ) )
V_158 -> V_151 |= ( 1 << V_108 ) ;
if ( ! V_158 -> V_151 && ! V_158 -> V_155 )
return - V_23 ;
if ( ( V_158 -> V_103 & V_152 ) && ( V_158 -> V_151 & V_163 ) )
return - V_23 ;
if ( V_158 -> V_151 && V_158 -> V_167 )
return - V_23 ;
return 0 ;
}
static int F_134 ( struct V_149 * V_150 , int * V_103 , char * V_156 )
{
int V_22 = 0 ;
struct V_6 * V_7 = F_128 ( V_150 ) ;
struct V_157 V_158 ;
T_5 V_173 , V_174 ;
F_135 ( & V_13 . V_31 ) ;
V_22 = F_130 ( V_156 , & V_158 ) ;
if ( V_22 )
goto V_86;
if ( V_158 . V_151 != V_7 -> V_151 || V_158 . V_169 )
F_136 ( L_22 ,
F_137 ( V_57 ) , V_57 -> V_175 ) ;
V_173 = V_158 . V_151 & ~ V_7 -> V_151 ;
V_174 = V_7 -> V_151 & ~ V_158 . V_151 ;
if ( ( V_158 . V_103 ^ V_7 -> V_103 ) ||
( V_158 . V_155 && strcmp ( V_158 . V_155 , V_7 -> V_155 ) ) ) {
F_138 ( L_23 ,
V_158 . V_103 , V_158 . V_155 ? : L_24 , V_7 -> V_103 , V_7 -> V_155 ) ;
V_22 = - V_23 ;
goto V_86;
}
if ( ! F_38 ( & V_7 -> V_31 . V_26 . V_176 ) ) {
V_22 = - V_177 ;
goto V_86;
}
V_22 = F_139 ( V_7 , V_173 ) ;
if ( V_22 )
goto V_86;
F_140 ( F_139 ( & V_13 , V_174 ) ) ;
if ( V_158 . V_169 ) {
F_84 ( & V_95 ) ;
strcpy ( V_7 -> V_93 , V_158 . V_169 ) ;
F_87 ( & V_95 ) ;
}
F_141 ( V_7 ) ;
V_86:
F_45 ( V_158 . V_169 ) ;
F_45 ( V_158 . V_155 ) ;
F_11 ( & V_9 ) ;
return V_22 ;
}
struct V_116 * F_142 ( struct V_178 * V_179 , int V_103 ,
void * V_156 , unsigned long V_180 ,
struct V_181 * V_48 )
{
struct V_182 * V_183 = NULL ;
struct V_157 V_158 ;
struct V_6 * V_7 ;
struct V_106 * V_107 ;
struct V_116 * V_116 ;
int V_108 , V_22 ;
bool V_184 = false ;
F_135 ( & V_13 . V_31 ) ;
V_22 = F_130 ( V_156 , & V_158 ) ;
if ( V_22 )
goto V_86;
F_101 (ss, i) {
if ( ! ( V_158 . V_151 & ( 1 << V_108 ) ) ||
V_107 -> V_7 == & V_13 )
continue;
if ( ! F_143 ( & V_107 -> V_7 -> V_31 . V_26 . V_185 ) ) {
F_11 ( & V_9 ) ;
F_144 ( 10 ) ;
V_22 = F_145 () ;
goto V_143;
}
F_146 ( & V_107 -> V_7 -> V_31 ) ;
}
F_5 (root) {
bool V_186 = false ;
if ( V_7 == & V_13 )
continue;
if ( V_158 . V_155 ) {
if ( strcmp ( V_158 . V_155 , V_7 -> V_155 ) )
continue;
V_186 = true ;
}
if ( ( V_158 . V_151 || V_158 . V_167 ) &&
( V_158 . V_151 != V_7 -> V_151 ) ) {
if ( ! V_186 )
continue;
V_22 = - V_177 ;
goto V_86;
}
if ( V_7 -> V_103 ^ V_158 . V_103 )
F_136 ( L_25 ) ;
V_183 = F_147 ( V_7 -> V_150 , NULL ) ;
if ( F_148 ( V_183 ) ||
! F_143 ( & V_7 -> V_31 . V_26 . V_185 ) ) {
F_11 ( & V_9 ) ;
if ( ! F_149 ( V_183 ) )
F_150 ( V_183 ) ;
F_144 ( 10 ) ;
V_22 = F_145 () ;
goto V_143;
}
V_22 = 0 ;
goto V_86;
}
if ( ! V_158 . V_151 && ! V_158 . V_167 ) {
V_22 = - V_23 ;
goto V_86;
}
if ( V_48 != & V_141 ) {
V_22 = - V_187 ;
goto V_86;
}
V_7 = F_52 ( sizeof( * V_7 ) , V_29 ) ;
if ( ! V_7 ) {
V_22 = - V_63 ;
goto V_86;
}
V_184 = true ;
F_151 ( V_7 , & V_158 ) ;
V_22 = F_152 ( V_7 , V_158 . V_151 , V_188 ) ;
if ( V_22 )
F_153 ( V_7 ) ;
V_86:
F_11 ( & V_9 ) ;
V_143:
F_45 ( V_158 . V_169 ) ;
F_45 ( V_158 . V_155 ) ;
if ( V_22 )
return F_65 ( V_22 ) ;
V_116 = F_154 ( & V_120 , V_103 , V_7 ,
V_189 , V_48 ) ;
if ( V_184 ) {
F_3 ( & V_9 ) ;
F_155 ( & V_7 -> V_31 . V_26 . V_185 ) ;
F_11 ( & V_9 ) ;
}
if ( V_183 )
F_150 ( V_183 ) ;
return V_116 ;
}
static int T_6 F_156 ( void )
{
V_36 = F_157 ( L_26 ,
0 , 1 ) ;
F_37 ( ! V_36 ) ;
return 0 ;
}
static int T_6 F_158 ( char * V_190 )
{
struct V_106 * V_107 ;
char * V_159 ;
int V_108 ;
while ( ( V_159 = F_132 ( & V_190 , L_13 ) ) != NULL ) {
if ( ! * V_159 )
continue;
if ( ! strcmp ( V_159 , L_15 ) ) {
V_2 = V_164 ;
break;
}
F_101 (ss, i) {
if ( strcmp ( V_159 , V_107 -> V_155 ) &&
strcmp ( V_159 , V_107 -> V_109 ) )
continue;
V_2 |= 1 << V_108 ;
}
}
return 1 ;
}
