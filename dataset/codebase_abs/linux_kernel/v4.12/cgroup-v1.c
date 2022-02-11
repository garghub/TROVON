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
if ( ! F_15 ( V_15 ) )
return - V_24 ;
F_3 ( & V_9 ) ;
F_4 ( & V_10 ) ;
F_6 ( & V_14 ) ;
F_16 (link, &from->cset_links, cset_link)
F_17 ( V_18 -> V_25 , V_15 , & V_16 ) ;
F_8 ( & V_14 ) ;
V_22 = F_18 ( & V_16 ) ;
if ( V_22 )
goto V_26;
do {
F_19 ( & V_4 -> V_27 , & V_20 ) ;
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
V_26:
F_26 ( & V_16 ) ;
F_10 ( & V_10 ) ;
F_11 ( & V_9 ) ;
return V_22 ;
}
static void * F_27 ( int V_28 )
{
if ( F_28 ( V_28 ) )
return F_29 ( V_28 * sizeof( V_29 ) ) ;
else
return F_30 ( V_28 * sizeof( V_29 ) , V_30 ) ;
}
static void F_31 ( void * V_31 )
{
F_32 ( V_31 ) ;
}
void F_33 ( struct V_11 * V_32 )
{
struct V_33 * V_34 , * V_35 ;
F_3 ( & V_32 -> V_36 ) ;
F_34 (l, tmp_l, &cgrp->pidlists, links)
F_35 ( V_37 , & V_34 -> V_38 , 0 ) ;
F_11 ( & V_32 -> V_36 ) ;
F_36 ( V_37 ) ;
F_37 ( ! F_38 ( & V_32 -> V_39 ) ) ;
}
static void F_39 ( struct V_40 * V_41 )
{
struct V_42 * V_43 = F_40 ( V_41 ) ;
struct V_33 * V_34 = F_41 ( V_43 , struct V_33 ,
V_38 ) ;
struct V_33 * V_44 = NULL ;
F_3 ( & V_34 -> V_45 -> V_36 ) ;
if ( ! F_42 ( V_43 ) ) {
F_43 ( & V_34 -> V_46 ) ;
F_31 ( V_34 -> V_47 ) ;
F_44 ( V_34 -> V_48 . V_49 ) ;
V_44 = V_34 ;
}
F_11 ( & V_34 -> V_45 -> V_36 ) ;
F_45 ( V_44 ) ;
}
static int F_46 ( V_29 * V_47 , int V_50 )
{
int V_51 , V_52 = 1 ;
if ( V_50 == 0 || V_50 == 1 )
return V_50 ;
for ( V_51 = 1 ; V_51 < V_50 ; V_51 ++ ) {
while ( V_47 [ V_51 ] == V_47 [ V_51 - 1 ] ) {
V_51 ++ ;
if ( V_51 == V_50 )
goto V_53;
}
V_47 [ V_52 ] = V_47 [ V_51 ] ;
V_52 ++ ;
}
V_53:
return V_52 ;
}
static int F_47 ( const void * V_54 , const void * V_55 )
{
return * ( V_29 * ) V_54 - * ( V_29 * ) V_55 ;
}
static struct V_33 * F_48 ( struct V_11 * V_32 ,
enum V_56 type )
{
struct V_33 * V_34 ;
struct V_57 * V_49 = F_49 ( V_58 ) ;
F_50 ( & V_32 -> V_36 ) ;
F_16 (l, &cgrp->pidlists, links)
if ( V_34 -> V_48 . type == type && V_34 -> V_48 . V_49 == V_49 )
return V_34 ;
return NULL ;
}
static struct V_33 * F_51 ( struct V_11 * V_32 ,
enum V_56 type )
{
struct V_33 * V_34 ;
F_50 ( & V_32 -> V_36 ) ;
V_34 = F_48 ( V_32 , type ) ;
if ( V_34 )
return V_34 ;
V_34 = F_52 ( sizeof( struct V_33 ) , V_30 ) ;
if ( ! V_34 )
return V_34 ;
F_53 ( & V_34 -> V_38 , F_39 ) ;
V_34 -> V_48 . type = type ;
V_34 -> V_48 . V_49 = F_54 ( F_49 ( V_58 ) ) ;
V_34 -> V_45 = V_32 ;
F_55 ( & V_34 -> V_46 , & V_32 -> V_39 ) ;
return V_34 ;
}
static int F_56 ( const struct V_11 * V_32 )
{
int V_28 = 0 ;
struct V_17 * V_18 ;
F_6 ( & V_14 ) ;
F_16 (link, &cgrp->cset_links, cset_link)
V_28 += F_57 ( & V_18 -> V_25 -> V_59 ) ;
F_8 ( & V_14 ) ;
return V_28 ;
}
static int F_58 ( struct V_11 * V_32 , enum V_56 type ,
struct V_33 * * V_60 )
{
V_29 * V_61 ;
int V_50 ;
int V_62 , V_63 = 0 ;
struct V_19 V_20 ;
struct V_3 * V_5 ;
struct V_33 * V_34 ;
F_50 ( & V_32 -> V_36 ) ;
V_50 = F_56 ( V_32 ) ;
V_61 = F_27 ( V_50 ) ;
if ( ! V_61 )
return - V_64 ;
F_19 ( & V_32 -> V_27 , & V_20 ) ;
while ( ( V_5 = F_20 ( & V_20 ) ) ) {
if ( F_59 ( V_63 == V_50 ) )
break;
if ( type == V_65 )
V_62 = F_60 ( V_5 ) ;
else
V_62 = F_61 ( V_5 ) ;
if ( V_62 > 0 )
V_61 [ V_63 ++ ] = V_62 ;
}
F_22 ( & V_20 ) ;
V_50 = V_63 ;
F_62 ( V_61 , V_50 , sizeof( V_29 ) , F_47 , NULL ) ;
if ( type == V_65 )
V_50 = F_46 ( V_61 , V_50 ) ;
V_34 = F_51 ( V_32 , type ) ;
if ( ! V_34 ) {
F_31 ( V_61 ) ;
return - V_64 ;
}
F_31 ( V_34 -> V_47 ) ;
V_34 -> V_47 = V_61 ;
V_34 -> V_50 = V_50 ;
* V_60 = V_34 ;
return 0 ;
}
static void * F_63 ( struct V_66 * V_67 , T_1 * V_68 )
{
struct V_69 * V_70 = V_67 -> V_71 ;
struct V_11 * V_32 = F_64 ( V_67 ) -> V_11 ;
struct V_33 * V_34 ;
enum V_56 type = F_65 ( V_67 ) -> V_71 ;
int V_72 = 0 , V_62 = * V_68 ;
int * V_73 , V_22 ;
F_3 ( & V_32 -> V_36 ) ;
if ( V_70 -> V_74 )
V_70 -> V_74 = F_48 ( V_32 , type ) ;
if ( ! V_70 -> V_74 ) {
V_22 = F_58 ( V_32 , type ,
(struct V_33 * * ) & V_70 -> V_74 ) ;
if ( V_22 )
return F_66 ( V_22 ) ;
}
V_34 = V_70 -> V_74 ;
if ( V_62 ) {
int V_75 = V_34 -> V_50 ;
while ( V_72 < V_75 ) {
int V_76 = ( V_72 + V_75 ) / 2 ;
if ( V_34 -> V_47 [ V_76 ] == V_62 ) {
V_72 = V_76 ;
break;
} else if ( V_34 -> V_47 [ V_76 ] <= V_62 )
V_72 = V_76 + 1 ;
else
V_75 = V_76 ;
}
}
if ( V_72 >= V_34 -> V_50 )
return NULL ;
V_73 = V_34 -> V_47 + V_72 ;
* V_68 = * V_73 ;
return V_73 ;
}
static void F_67 ( struct V_66 * V_67 , void * V_77 )
{
struct V_69 * V_70 = V_67 -> V_71 ;
struct V_33 * V_34 = V_70 -> V_74 ;
if ( V_34 )
F_35 ( V_37 , & V_34 -> V_38 ,
V_78 ) ;
F_11 ( & F_64 ( V_67 ) -> V_11 -> V_36 ) ;
}
static void * F_68 ( struct V_66 * V_67 , void * V_77 , T_1 * V_68 )
{
struct V_69 * V_70 = V_67 -> V_71 ;
struct V_33 * V_34 = V_70 -> V_74 ;
V_29 * V_31 = V_77 ;
V_29 * V_75 = V_34 -> V_47 + V_34 -> V_50 ;
V_31 ++ ;
if ( V_31 >= V_75 ) {
return NULL ;
} else {
* V_68 = * V_31 ;
return V_31 ;
}
}
static int F_69 ( struct V_66 * V_67 , void * V_77 )
{
F_70 ( V_67 , L_1 , * ( int * ) V_77 ) ;
return 0 ;
}
static T_2 F_71 ( struct V_69 * V_70 ,
char * V_79 , T_3 V_80 , T_1 V_81 )
{
return F_72 ( V_70 , V_79 , V_80 , V_81 , false ) ;
}
static T_2 F_73 ( struct V_69 * V_70 ,
char * V_79 , T_3 V_80 , T_1 V_81 )
{
struct V_11 * V_32 ;
F_74 ( sizeof( V_32 -> V_7 -> V_82 ) < V_83 ) ;
V_32 = F_75 ( V_70 -> V_84 , false ) ;
if ( ! V_32 )
return - V_85 ;
F_76 ( & V_86 ) ;
F_77 ( V_32 -> V_7 -> V_82 , F_78 ( V_79 ) ,
sizeof( V_32 -> V_7 -> V_82 ) ) ;
F_79 ( & V_86 ) ;
F_80 ( V_70 -> V_84 ) ;
return V_80 ;
}
static int F_81 ( struct V_66 * V_87 , void * V_77 )
{
struct V_11 * V_32 = F_64 ( V_87 ) -> V_11 ;
F_76 ( & V_86 ) ;
F_82 ( V_87 , V_32 -> V_7 -> V_82 ) ;
F_79 ( & V_86 ) ;
F_83 ( V_87 , '\n' ) ;
return 0 ;
}
static int F_84 ( struct V_66 * V_87 , void * V_77 )
{
F_82 ( V_87 , L_2 ) ;
return 0 ;
}
static T_4 F_85 ( struct V_88 * V_89 ,
struct V_90 * V_91 )
{
return F_86 ( V_89 -> V_11 ) ;
}
static int F_87 ( struct V_88 * V_89 ,
struct V_90 * V_91 , T_4 V_92 )
{
if ( V_92 )
F_88 ( V_93 , & V_89 -> V_11 -> V_94 ) ;
else
F_89 ( V_93 , & V_89 -> V_11 -> V_94 ) ;
return 0 ;
}
static T_4 F_90 ( struct V_88 * V_89 ,
struct V_90 * V_91 )
{
return F_91 ( V_95 , & V_89 -> V_11 -> V_94 ) ;
}
static int F_92 ( struct V_88 * V_89 ,
struct V_90 * V_91 , T_4 V_92 )
{
if ( V_92 )
F_88 ( V_95 , & V_89 -> V_11 -> V_94 ) ;
else
F_89 ( V_95 , & V_89 -> V_11 -> V_94 ) ;
return 0 ;
}
static int F_93 ( struct V_66 * V_96 , void * V_77 )
{
struct V_97 * V_98 ;
int V_99 ;
F_82 ( V_96 , L_3 ) ;
F_3 ( & V_9 ) ;
F_94 (ss, i)
F_70 ( V_96 , L_4 ,
V_98 -> V_100 , V_98 -> V_7 -> V_101 ,
F_95 ( & V_98 -> V_7 -> V_102 ) ,
F_96 ( V_99 ) ) ;
F_11 ( & V_9 ) ;
return 0 ;
}
static int F_97 ( struct V_103 * V_103 , struct V_104 * V_104 )
{
return F_98 ( V_104 , F_93 , NULL ) ;
}
int F_99 ( struct V_105 * V_106 , struct V_107 * V_107 )
{
struct V_108 * V_84 = F_100 ( V_107 ) ;
struct V_11 * V_32 ;
struct V_19 V_20 ;
struct V_3 * V_5 ;
if ( V_107 -> V_109 -> V_110 != & V_111 || ! V_84 ||
F_101 ( V_84 ) != V_112 )
return - V_23 ;
F_3 ( & V_9 ) ;
F_102 () ;
V_32 = F_103 ( * ( void V_113 V_114 * * ) & V_84 -> V_74 ) ;
if ( ! V_32 || F_104 ( V_32 ) ) {
F_105 () ;
F_11 ( & V_9 ) ;
return - V_115 ;
}
F_105 () ;
F_19 ( & V_32 -> V_27 , & V_20 ) ;
while ( ( V_5 = F_20 ( & V_20 ) ) ) {
switch ( V_5 -> V_116 ) {
case V_117 :
V_106 -> V_118 ++ ;
break;
case V_119 :
V_106 -> V_120 ++ ;
break;
case V_121 :
V_106 -> V_122 ++ ;
break;
case V_123 :
V_106 -> V_124 ++ ;
break;
default:
if ( F_106 ( V_5 ) )
V_106 -> V_125 ++ ;
break;
}
}
F_22 ( & V_20 ) ;
F_11 ( & V_9 ) ;
return 0 ;
}
void F_107 ( struct V_11 * V_32 )
{
if ( F_86 ( V_32 ) && ! F_108 ( V_32 ) &&
! F_109 ( & V_32 -> V_27 ) && ! F_104 ( V_32 ) )
F_110 ( & V_32 -> V_126 ) ;
}
void F_111 ( struct V_40 * V_41 )
{
struct V_11 * V_32 =
F_41 ( V_41 , struct V_11 , V_126 ) ;
char * V_127 = NULL , * V_128 = NULL ;
char * V_129 [ 3 ] , * V_130 [ 3 ] ;
int V_22 ;
F_3 ( & V_9 ) ;
V_127 = F_30 ( V_83 , V_30 ) ;
V_128 = F_112 ( V_32 -> V_7 -> V_82 , V_30 ) ;
if ( ! V_127 || ! V_128 )
goto V_131;
F_6 ( & V_14 ) ;
V_22 = F_113 ( V_32 , V_127 , V_83 , & V_132 ) ;
F_8 ( & V_14 ) ;
if ( V_22 < 0 || V_22 >= V_83 )
goto V_131;
V_129 [ 0 ] = V_128 ;
V_129 [ 1 ] = V_127 ;
V_129 [ 2 ] = NULL ;
V_130 [ 0 ] = L_5 ;
V_130 [ 1 ] = L_6 ;
V_130 [ 2 ] = NULL ;
F_11 ( & V_9 ) ;
F_114 ( V_129 [ 0 ] , V_129 , V_130 , V_133 ) ;
goto V_134;
V_131:
F_11 ( & V_9 ) ;
V_134:
F_45 ( V_128 ) ;
F_45 ( V_127 ) ;
}
static int F_115 ( struct V_108 * V_84 , struct V_108 * V_135 ,
const char * V_136 )
{
struct V_11 * V_32 = V_84 -> V_74 ;
int V_22 ;
if ( F_101 ( V_84 ) != V_112 )
return - V_137 ;
if ( V_84 -> V_138 != V_135 )
return - V_139 ;
F_116 ( V_135 ) ;
F_116 ( V_84 ) ;
F_3 ( & V_9 ) ;
V_22 = F_117 ( V_84 , V_135 , V_136 ) ;
if ( ! V_22 )
F_118 ( V_32 ) ;
F_11 ( & V_9 ) ;
F_119 ( V_84 ) ;
F_119 ( V_135 ) ;
return V_22 ;
}
static int F_120 ( struct V_66 * V_87 , struct V_140 * V_141 )
{
struct V_6 * V_7 = F_121 ( V_141 ) ;
struct V_97 * V_98 ;
int V_1 ;
F_94 (ss, ssid)
if ( V_7 -> V_142 & ( 1 << V_1 ) )
F_122 ( V_87 , V_98 -> V_100 , NULL ) ;
if ( V_7 -> V_94 & V_143 )
F_82 ( V_87 , L_7 ) ;
if ( V_7 -> V_94 & V_144 )
F_82 ( V_87 , L_8 ) ;
F_76 ( & V_86 ) ;
if ( strlen ( V_7 -> V_82 ) )
F_122 ( V_87 , L_9 ,
V_7 -> V_82 ) ;
F_79 ( & V_86 ) ;
if ( F_91 ( V_95 , & V_7 -> V_32 . V_94 ) )
F_82 ( V_87 , L_10 ) ;
if ( strlen ( V_7 -> V_145 ) )
F_122 ( V_87 , L_11 , V_7 -> V_145 ) ;
return 0 ;
}
static int F_123 ( char * V_146 , struct V_147 * V_148 )
{
char * V_149 , * V_150 = V_146 ;
bool V_151 = false , V_152 = false ;
T_5 V_153 = V_154 ;
struct V_97 * V_98 ;
int V_155 = 0 ;
int V_99 ;
#ifdef F_124
V_153 = ~ ( ( T_5 ) 1 << V_156 ) ;
#endif
memset ( V_148 , 0 , sizeof( * V_148 ) ) ;
while ( ( V_149 = F_125 ( & V_150 , L_12 ) ) != NULL ) {
V_155 ++ ;
if ( ! * V_149 )
return - V_23 ;
if ( ! strcmp ( V_149 , L_13 ) ) {
V_148 -> V_157 = true ;
continue;
}
if ( ! strcmp ( V_149 , L_14 ) ) {
if ( V_152 )
return - V_23 ;
V_151 = true ;
continue;
}
if ( ! strcmp ( V_149 , L_15 ) ) {
V_148 -> V_94 |= V_143 ;
continue;
}
if ( ! strcmp ( V_149 , L_16 ) ) {
V_148 -> V_158 = true ;
continue;
}
if ( ! strcmp ( V_149 , L_17 ) ) {
V_148 -> V_94 |= V_144 ;
continue;
}
if ( ! strncmp ( V_149 , L_18 , 14 ) ) {
if ( V_148 -> V_159 )
return - V_23 ;
V_148 -> V_159 =
F_126 ( V_149 + 14 , V_83 - 1 , V_30 ) ;
if ( ! V_148 -> V_159 )
return - V_64 ;
continue;
}
if ( ! strncmp ( V_149 , L_19 , 5 ) ) {
const char * V_145 = V_149 + 5 ;
if ( ! strlen ( V_145 ) )
return - V_23 ;
for ( V_99 = 0 ; V_99 < strlen ( V_145 ) ; V_99 ++ ) {
char V_160 = V_145 [ V_99 ] ;
if ( isalnum ( V_160 ) )
continue;
if ( ( V_160 == '.' ) || ( V_160 == '-' ) || ( V_160 == '_' ) )
continue;
return - V_23 ;
}
if ( V_148 -> V_145 )
return - V_23 ;
V_148 -> V_145 = F_126 ( V_145 ,
V_161 - 1 ,
V_30 ) ;
if ( ! V_148 -> V_145 )
return - V_64 ;
continue;
}
F_94 (ss, i) {
if ( strcmp ( V_149 , V_98 -> V_100 ) )
continue;
if ( ! F_96 ( V_99 ) )
continue;
if ( F_1 ( V_99 ) )
continue;
if ( V_151 )
return - V_23 ;
V_148 -> V_142 |= ( 1 << V_99 ) ;
V_152 = true ;
break;
}
if ( V_99 == V_162 )
return - V_115 ;
}
if ( V_151 || ( ! V_152 && ! V_148 -> V_157 && ! V_148 -> V_145 ) )
F_94 (ss, i)
if ( F_96 ( V_99 ) && ! F_1 ( V_99 ) )
V_148 -> V_142 |= ( 1 << V_99 ) ;
if ( ! V_148 -> V_142 && ! V_148 -> V_145 )
return - V_23 ;
if ( ( V_148 -> V_94 & V_143 ) && ( V_148 -> V_142 & V_153 ) )
return - V_23 ;
if ( V_148 -> V_142 && V_148 -> V_157 )
return - V_23 ;
return 0 ;
}
static int F_127 ( struct V_140 * V_141 , int * V_94 , char * V_146 )
{
int V_22 = 0 ;
struct V_6 * V_7 = F_121 ( V_141 ) ;
struct V_147 V_148 ;
T_5 V_163 , V_164 ;
F_128 ( & V_13 . V_32 ) ;
V_22 = F_123 ( V_146 , & V_148 ) ;
if ( V_22 )
goto V_165;
if ( V_148 . V_142 != V_7 -> V_142 || V_148 . V_159 )
F_129 ( L_20 ,
F_130 ( V_58 ) , V_58 -> V_166 ) ;
V_163 = V_148 . V_142 & ~ V_7 -> V_142 ;
V_164 = V_7 -> V_142 & ~ V_148 . V_142 ;
if ( ( V_148 . V_94 ^ V_7 -> V_94 ) ||
( V_148 . V_145 && strcmp ( V_148 . V_145 , V_7 -> V_145 ) ) ) {
F_131 ( L_21 ,
V_148 . V_94 , V_148 . V_145 ? : L_22 , V_7 -> V_94 , V_7 -> V_145 ) ;
V_22 = - V_23 ;
goto V_165;
}
if ( ! F_38 ( & V_7 -> V_32 . V_27 . V_167 ) ) {
V_22 = - V_24 ;
goto V_165;
}
V_22 = F_132 ( V_7 , V_163 ) ;
if ( V_22 )
goto V_165;
F_133 ( F_132 ( & V_13 , V_164 ) ) ;
if ( V_148 . V_159 ) {
F_76 ( & V_86 ) ;
strcpy ( V_7 -> V_82 , V_148 . V_159 ) ;
F_79 ( & V_86 ) ;
}
F_134 ( V_7 ) ;
V_165:
F_45 ( V_148 . V_159 ) ;
F_45 ( V_148 . V_145 ) ;
F_11 ( & V_9 ) ;
return V_22 ;
}
struct V_107 * F_135 ( struct V_168 * V_169 , int V_94 ,
void * V_146 , unsigned long V_170 ,
struct V_171 * V_49 )
{
struct V_172 * V_173 = NULL ;
struct V_147 V_148 ;
struct V_6 * V_7 ;
struct V_97 * V_98 ;
struct V_107 * V_107 ;
int V_99 , V_22 ;
bool V_174 = false ;
F_128 ( & V_13 . V_32 ) ;
V_22 = F_123 ( V_146 , & V_148 ) ;
if ( V_22 )
goto V_165;
F_94 (ss, i) {
if ( ! ( V_148 . V_142 & ( 1 << V_99 ) ) ||
V_98 -> V_7 == & V_13 )
continue;
if ( ! F_136 ( & V_98 -> V_7 -> V_32 . V_27 . V_175 ) ) {
F_11 ( & V_9 ) ;
F_137 ( 10 ) ;
V_22 = F_138 () ;
goto V_134;
}
F_139 ( & V_98 -> V_7 -> V_32 ) ;
}
F_5 (root) {
bool V_176 = false ;
if ( V_7 == & V_13 )
continue;
if ( V_148 . V_145 ) {
if ( strcmp ( V_148 . V_145 , V_7 -> V_145 ) )
continue;
V_176 = true ;
}
if ( ( V_148 . V_142 || V_148 . V_157 ) &&
( V_148 . V_142 != V_7 -> V_142 ) ) {
if ( ! V_176 )
continue;
V_22 = - V_24 ;
goto V_165;
}
if ( V_7 -> V_94 ^ V_148 . V_94 )
F_129 ( L_23 ) ;
V_173 = F_140 ( V_7 -> V_141 , NULL ) ;
if ( F_141 ( V_173 ) ||
! F_136 ( & V_7 -> V_32 . V_27 . V_175 ) ) {
F_11 ( & V_9 ) ;
if ( ! F_142 ( V_173 ) )
F_143 ( V_173 ) ;
F_137 ( 10 ) ;
V_22 = F_138 () ;
goto V_134;
}
V_22 = 0 ;
goto V_165;
}
if ( ! V_148 . V_142 && ! V_148 . V_157 ) {
V_22 = - V_23 ;
goto V_165;
}
if ( V_49 != & V_132 ) {
V_22 = - V_177 ;
goto V_165;
}
V_7 = F_52 ( sizeof( * V_7 ) , V_30 ) ;
if ( ! V_7 ) {
V_22 = - V_64 ;
goto V_165;
}
V_174 = true ;
F_144 ( V_7 , & V_148 ) ;
V_22 = F_145 ( V_7 , V_148 . V_142 , V_178 ) ;
if ( V_22 )
F_146 ( V_7 ) ;
V_165:
F_11 ( & V_9 ) ;
V_134:
F_45 ( V_148 . V_159 ) ;
F_45 ( V_148 . V_145 ) ;
if ( V_22 )
return F_66 ( V_22 ) ;
V_107 = F_147 ( & V_111 , V_94 , V_7 ,
V_179 , V_49 ) ;
if ( V_174 ) {
F_3 ( & V_9 ) ;
F_148 ( & V_7 -> V_32 . V_27 . V_175 ) ;
F_11 ( & V_9 ) ;
}
if ( V_173 )
F_143 ( V_173 ) ;
return V_107 ;
}
static int T_6 F_149 ( void )
{
V_37 = F_150 ( L_24 ,
0 , 1 ) ;
F_37 ( ! V_37 ) ;
return 0 ;
}
static int T_6 F_151 ( char * V_180 )
{
struct V_97 * V_98 ;
char * V_149 ;
int V_99 ;
while ( ( V_149 = F_125 ( & V_180 , L_12 ) ) != NULL ) {
if ( ! * V_149 )
continue;
if ( ! strcmp ( V_149 , L_14 ) ) {
V_2 = V_154 ;
break;
}
F_94 (ss, i) {
if ( strcmp ( V_149 , V_98 -> V_145 ) &&
strcmp ( V_149 , V_98 -> V_100 ) )
continue;
V_2 |= 1 << V_99 ;
}
}
return 1 ;
}
static struct V_88 *
F_152 ( struct V_88 * V_181 )
{
struct V_88 * V_89 = F_52 ( sizeof( * V_89 ) , V_30 ) ;
if ( ! V_89 )
return F_66 ( - V_64 ) ;
return V_89 ;
}
static void F_153 ( struct V_88 * V_89 )
{
F_45 ( V_89 ) ;
}
static T_4 F_154 ( struct V_88 * V_89 ,
struct V_90 * V_91 )
{
return F_56 ( V_89 -> V_11 ) ;
}
static T_4 F_155 ( struct V_88 * V_89 ,
struct V_90 * V_91 )
{
return ( T_4 ) ( unsigned long ) V_58 -> V_182 ;
}
static T_4 F_156 ( struct V_88 * V_89 ,
struct V_90 * V_91 )
{
T_4 V_28 ;
F_102 () ;
V_28 = F_57 ( & F_157 ( V_58 ) -> V_59 ) ;
F_105 () ;
return V_28 ;
}
static int F_158 ( struct V_66 * V_87 , void * V_77 )
{
struct V_17 * V_18 ;
struct V_183 * V_25 ;
char * V_184 ;
V_184 = F_30 ( V_185 + 1 , V_30 ) ;
if ( ! V_184 )
return - V_64 ;
F_6 ( & V_14 ) ;
F_102 () ;
V_25 = F_103 ( V_58 -> V_182 ) ;
F_16 (link, &cset->cgrp_links, cgrp_link) {
struct V_11 * V_160 = V_18 -> V_32 ;
F_159 ( V_160 , V_184 , V_185 + 1 ) ;
F_70 ( V_87 , L_25 ,
V_160 -> V_7 -> V_101 , V_184 ) ;
}
F_105 () ;
F_8 ( & V_14 ) ;
F_45 ( V_184 ) ;
return 0 ;
}
static int F_160 ( struct V_66 * V_87 , void * V_77 )
{
struct V_88 * V_89 = F_64 ( V_87 ) ;
struct V_17 * V_18 ;
F_6 ( & V_14 ) ;
F_16 (link, &css->cgroup->cset_links, cset_link) {
struct V_183 * V_25 = V_18 -> V_25 ;
struct V_3 * V_21 ;
int V_28 = 0 ;
F_70 ( V_87 , L_26 , V_25 ) ;
F_16 (task, &cset->tasks, cg_list) {
if ( V_28 ++ > V_186 )
goto V_187;
F_70 ( V_87 , L_27 , F_61 ( V_21 ) ) ;
}
F_16 (task, &cset->mg_tasks, cg_list) {
if ( V_28 ++ > V_186 )
goto V_187;
F_70 ( V_87 , L_27 , F_61 ( V_21 ) ) ;
}
continue;
V_187:
F_82 ( V_87 , L_28 ) ;
}
F_8 ( & V_14 ) ;
return 0 ;
}
static T_4 F_161 ( struct V_88 * V_89 , struct V_90 * V_91 )
{
return ( ! F_108 ( V_89 -> V_11 ) &&
! F_109 ( & V_89 -> V_11 -> V_27 ) ) ;
}
