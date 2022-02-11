static void F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_3 * V_5 )
{
struct V_6 * V_7 ;
struct V_8 * V_9 ;
unsigned long V_10 ;
V_7 = F_2 ( V_4 ) ;
if ( ! V_7 || F_3 ( V_2 == NULL ) )
return;
V_9 = F_4 ( V_7 ) ;
F_5 ( & V_2 -> V_11 , V_10 ) ;
V_9 -> V_12 = F_6 ( V_5 ) ;
F_7 ( & V_2 -> V_11 , V_10 ) ;
}
static void F_8 ( struct V_13 * V_14 ,
struct V_15 * V_16 )
{
struct V_1 * V_2 = F_9 ( V_16 ) ;
struct V_3 * V_17 ;
struct V_3 * V_4 = NULL ;
int V_18 ;
for ( V_18 = 0 ; V_18 < V_19 ; V_18 ++ )
V_14 -> V_20 [ V_18 ] = NULL ;
while ( 1 ) {
struct V_21 * V_22 = NULL ;
for ( V_18 = 0 ; V_18 < V_16 -> V_23 ; V_18 ++ ) {
struct V_21 * V_24 = & V_16 -> V_25 [ V_18 ] ;
if ( ! ( V_24 -> V_10 & V_26 ) )
continue;
V_22 = F_10 ( V_24 ) ;
if ( V_22 )
break;
}
if ( V_22 == NULL ||
F_11 ( V_22 -> V_27 ) != V_28 )
break;
V_17 = F_12 ( V_22 -> V_27 ) ;
switch ( V_17 -> V_29 ) {
case V_30 :
V_4 = V_17 ;
case V_31 :
V_14 -> V_20 [ V_32 ] = V_17 ;
break;
case V_33 :
V_14 -> V_20 [ V_34 ] = V_17 ;
break;
case V_35 :
V_14 -> V_20 [ V_36 ] = V_17 ;
break;
case V_37 :
V_14 -> V_20 [ V_38 ] = V_17 ;
break;
case V_39 :
V_14 -> V_20 [ V_40 ] = V_17 ;
break;
default:
break;
}
V_16 = & V_17 -> V_27 ;
if ( V_16 -> V_23 == 1 )
break;
}
if ( V_4 && V_14 -> V_20 [ V_38 ] )
F_1 ( V_2 , V_4 , V_14 -> V_20 [ V_38 ] ) ;
}
static int F_13 ( struct V_3 * V_17 , int V_41 )
{
int * V_42 ;
int V_43 ;
if ( V_17 == NULL )
return - V_44 ;
V_42 = & V_17 -> V_27 . V_42 ;
if ( V_41 && ( * V_42 ) ++ > 0 )
return 0 ;
else if ( ! V_41 && ( * V_42 == 0 || -- ( * V_42 ) > 0 ) )
return 0 ;
V_43 = F_14 ( V_17 , V_45 , V_46 , V_41 ) ;
return V_43 != - V_47 ? V_43 : 0 ;
}
static int F_15 ( struct V_13 * V_14 , bool V_41 )
{
static const T_1 V_48 [ 2 ] [ V_19 - 1 ] = {
{ V_40 , V_32 , V_34 , V_36 } ,
{ V_34 , V_36 , V_32 , V_40 } ,
} ;
int V_18 , V_43 = 0 ;
if ( V_14 -> V_20 [ V_32 ] == NULL )
return - V_44 ;
for ( V_18 = 0 ; V_18 < V_19 - 1 ; V_18 ++ ) {
unsigned int V_49 = V_48 [ V_41 ] [ V_18 ] ;
V_43 = F_13 ( V_14 -> V_20 [ V_49 ] , V_41 ) ;
if ( V_43 < 0 && V_43 != - V_44 )
goto error;
}
return 0 ;
error:
for (; V_18 >= 0 ; V_18 -- ) {
unsigned int V_49 = V_48 [ V_41 ] [ V_18 ] ;
F_13 ( V_14 -> V_20 [ V_49 ] , ! V_41 ) ;
}
return V_43 ;
}
static int F_16 ( struct V_50 * V_51 ,
struct V_15 * V_16 , bool V_52 )
{
struct V_1 * V_2 = F_9 ( V_16 ) ;
struct V_13 * V_14 = F_17 ( V_51 ) ;
struct V_3 * V_17 ;
int V_43 ;
if ( F_3 ( V_14 == NULL || V_16 == NULL ) )
return - V_53 ;
if ( V_52 )
F_8 ( V_14 , V_16 ) ;
V_17 = V_14 -> V_20 [ V_32 ] ;
if ( V_17 == NULL )
return - V_53 ;
if ( ! F_18 ( V_2 -> V_54 [ V_55 ] ) && V_14 -> V_20 [ V_40 ] ) {
V_43 = F_19 ( V_2 -> V_54 [ V_55 ] ) ;
if ( V_43 < 0 )
return V_43 ;
}
V_43 = F_20 ( V_17 , true ) ;
if ( V_43 < 0 )
goto V_56;
V_43 = F_15 ( V_14 , 1 ) ;
if ( ! V_43 )
return 0 ;
F_20 ( V_17 , false ) ;
V_56:
if ( ! F_18 ( V_2 -> V_54 [ V_55 ] ) && V_14 -> V_20 [ V_40 ] )
F_21 ( V_2 -> V_54 [ V_55 ] ) ;
return V_43 ;
}
static int F_22 ( struct V_50 * V_51 )
{
struct V_13 * V_14 = F_17 ( V_51 ) ;
struct V_3 * V_17 = V_14 ? V_14 -> V_20 [ V_32 ] : NULL ;
struct V_1 * V_2 ;
int V_43 ;
if ( V_17 == NULL ) {
F_23 ( L_1 , V_57 ) ;
return 0 ;
}
V_43 = F_15 ( V_14 , 0 ) ;
F_20 ( V_17 , false ) ;
V_2 = F_9 ( & V_17 -> V_27 ) ;
if ( ! F_18 ( V_2 -> V_54 [ V_55 ] ) && V_14 -> V_20 [ V_40 ] )
F_21 ( V_2 -> V_54 [ V_55 ] ) ;
return V_43 == - V_44 ? 0 : V_43 ;
}
static int F_24 ( struct V_50 * V_51 , bool V_41 )
{
static const T_1 V_48 [ 2 ] [ V_19 ] = {
{ V_38 , V_32 , V_40 , V_34 , V_36 } ,
{ V_34 , V_36 , V_38 , V_32 , V_40 } ,
} ;
struct V_13 * V_14 = F_17 ( V_51 ) ;
int V_18 , V_43 = 0 ;
if ( V_14 -> V_20 [ V_32 ] == NULL )
return - V_58 ;
for ( V_18 = 0 ; V_18 < V_19 ; V_18 ++ ) {
unsigned int V_49 = V_48 [ V_41 ] [ V_18 ] ;
V_43 = F_14 ( V_14 -> V_20 [ V_49 ] , V_59 , V_60 , V_41 ) ;
if ( V_43 < 0 && V_43 != - V_47 && V_43 != - V_58 )
goto error;
}
return 0 ;
error:
for (; V_18 >= 0 ; V_18 -- ) {
unsigned int V_49 = V_48 [ V_41 ] [ V_18 ] ;
F_14 ( V_14 -> V_20 [ V_49 ] , V_59 , V_60 , ! V_41 ) ;
}
return V_43 ;
}
static struct V_50 * F_25 (
struct V_1 * V_2 )
{
struct V_13 * V_14 ;
V_14 = F_26 ( sizeof( * V_14 ) , V_61 ) ;
if ( ! V_14 )
return NULL ;
F_27 ( & V_14 -> V_62 , & V_2 -> V_63 ) ;
V_14 -> V_51 . V_64 = & V_65 ;
return & V_14 -> V_51 ;
}
static void F_28 ( struct V_1 * V_2 )
{
while ( ! F_29 ( & V_2 -> V_63 ) ) {
struct V_13 * V_14 ;
V_14 = F_30 ( V_2 -> V_63 . V_66 , F_31 ( * V_14 ) , V_62 ) ;
F_32 ( & V_14 -> V_62 ) ;
F_33 ( V_14 ) ;
}
}
static struct V_3 * F_34 ( struct V_1 * V_2 ,
struct V_6 * V_67 )
{
struct V_68 * V_69 ;
struct V_3 * V_17 = NULL ;
if ( ! V_67 || ! V_2 )
return NULL ;
V_67 -> V_70 = V_67 -> V_71 ;
V_69 = F_35 ( V_67 -> V_72 ) ;
if ( ! V_69 ) {
F_36 ( & V_2 -> V_73 ,
L_2 ,
V_67 -> V_72 ) ;
return F_37 ( - V_74 ) ;
}
V_17 = F_38 ( & V_2 -> V_73 , V_69 ,
V_67 -> V_75 , NULL ) ;
if ( F_39 ( V_17 ) ) {
F_40 ( V_69 ) ;
F_36 ( & V_2 -> V_73 ,
L_3 ,
V_67 -> V_75 -> type ) ;
return F_37 ( - V_74 ) ;
}
F_41 ( V_17 , V_67 ) ;
V_17 -> V_29 = V_30 ;
F_42 ( & V_2 -> V_73 , L_4 ,
V_17 -> V_76 ) ;
return V_17 ;
}
static void F_43 ( struct V_3 * V_17 )
{
struct V_77 * V_78 = F_6 ( V_17 ) ;
struct V_68 * V_69 ;
if ( ! V_78 || V_78 -> V_79 . V_80 )
return;
F_44 ( V_17 ) ;
V_69 = V_78 -> V_69 ;
F_45 ( V_78 ) ;
if ( V_69 )
F_40 ( V_69 ) ;
}
static int F_46 ( struct V_1 * V_2 ,
struct V_81 * V_82 ,
unsigned int V_83 )
{
struct V_81 * V_84 , * V_51 , * V_85 ;
struct V_6 * V_86 ;
struct V_87 V_88 ;
T_2 V_89 ;
V_86 = & V_2 -> V_4 [ V_83 ] . V_90 ;
V_51 = F_47 ( V_82 , NULL ) ;
if ( ! V_51 )
return 0 ;
F_48 ( V_51 , & V_88 ) ;
if ( F_3 ( V_88 . V_91 . V_82 == 0 ) || V_83 >= V_92 )
return - V_53 ;
V_86 -> V_93 = ( V_88 . V_91 . V_82 - 1 ) & 0x1 ;
V_84 = F_49 ( V_51 ) ;
F_50 ( V_51 ) ;
if ( V_84 == NULL ) {
F_42 ( & V_2 -> V_73 , L_5 ,
V_51 -> V_94 ) ;
return 0 ;
}
if ( ! F_51 ( V_84 , L_6 , & V_89 ) )
V_86 -> V_95 = V_89 ;
if ( ! F_51 ( V_84 , L_7 , & V_89 ) )
V_86 -> V_96 = V_89 ;
else
V_86 -> V_96 = V_97 ;
if ( V_86 -> V_96 == 0 ) {
F_52 ( & V_2 -> V_73 , L_8 ,
V_84 -> V_94 ) ;
F_50 ( V_84 ) ;
return - V_53 ;
}
if ( F_53 ( V_88 . V_91 . V_82 ) ) {
if ( V_88 . V_98 == V_99 )
V_86 -> V_71 = V_100 ;
else
V_86 -> V_71 = V_101 ;
V_86 -> V_10 = V_88 . V_102 . V_103 . V_10 ;
} else if ( F_54 ( V_88 . V_91 . V_82 ) ) {
V_86 -> V_71 = V_104 ;
} else {
F_52 ( & V_2 -> V_73 , L_9 ,
V_88 . V_91 . V_82 , V_84 -> V_94 ) ;
}
V_85 = F_55 ( V_84 ) ;
if ( V_85 && ! F_56 ( V_85 -> V_76 , L_10 ) )
V_86 -> V_70 = V_105 ;
else
V_86 -> V_70 = V_86 -> V_71 ;
if ( F_3 ( V_83 >= F_57 ( V_2 -> V_4 ) ) )
return - V_53 ;
V_2 -> V_4 [ V_83 ] . V_106 . V_107 = V_108 ;
V_2 -> V_4 [ V_83 ] . V_106 . V_109 . V_110 . V_111 = V_84 ;
V_2 -> V_112 [ V_83 ] = & V_2 -> V_4 [ V_83 ] . V_106 ;
V_2 -> V_113 ++ ;
F_50 ( V_84 ) ;
return 0 ;
}
static int F_58 ( struct V_1 * V_2 ,
struct V_81 * V_85 )
{
struct V_81 * V_114 = V_2 -> V_115 -> V_79 . V_80 ;
struct V_81 * V_111 , * V_116 ;
int V_83 = 0 ;
int V_43 ;
F_59 (parent, node) {
struct V_81 * V_82 ;
if ( F_56 ( V_111 -> V_76 , L_11 ) )
continue;
V_82 = F_47 ( V_111 , NULL ) ;
if ( ! V_82 )
continue;
V_43 = F_46 ( V_2 , V_82 , V_83 ) ;
if ( V_43 < 0 )
return V_43 ;
V_83 ++ ;
}
V_116 = F_60 ( V_114 , L_12 ) ;
if ( ! V_116 )
return 0 ;
F_61 (ports, node) {
V_43 = F_46 ( V_2 , V_111 , V_83 ) ;
if ( V_43 < 0 )
break;
V_83 ++ ;
}
return 0 ;
}
static int F_62 ( struct V_81 * V_85 )
{
T_2 V_117 = 0 ;
V_85 = F_60 ( V_85 , L_13 ) ;
if ( ! V_85 )
return - V_53 ;
F_51 ( V_85 , L_14 , & V_117 ) ;
return V_117 - V_118 ;
}
static int F_63 ( struct V_1 * V_2 )
{
struct V_119 * V_90 = V_2 -> V_115 -> V_79 . V_120 ;
struct V_81 * V_80 = V_2 -> V_115 -> V_79 . V_80 ;
int V_121 = 0 ;
int V_43 , V_18 ;
if ( ! V_2 -> V_122 )
return - V_44 ;
V_43 = F_64 ( V_2 -> V_122 ) ;
if ( V_43 < 0 )
return V_43 ;
if ( V_80 ) {
V_2 -> V_113 = 0 ;
V_43 = F_58 ( V_2 , V_80 ) ;
} else if ( V_90 ) {
F_3 ( V_90 -> V_121 > F_57 ( V_2 -> V_4 ) ) ;
V_121 = F_65 ( T_2 , V_90 -> V_121 ,
F_57 ( V_2 -> V_4 ) ) ;
V_2 -> V_113 = V_121 ;
for ( V_18 = 0 ; V_18 < V_121 ; V_18 ++ ) {
struct V_8 * V_67 = & V_2 -> V_4 [ V_18 ] ;
struct V_3 * V_17 ;
V_67 -> V_90 = V_90 -> V_123 [ V_18 ] ;
V_43 = F_66 ( V_2 , & V_67 -> V_90 , true ) ;
if ( V_43 )
break;
V_17 = F_34 ( V_2 , & V_67 -> V_90 ) ;
V_43 = F_66 ( V_2 , & V_67 -> V_90 , false ) ;
if ( F_18 ( V_17 ) ) {
V_67 -> V_124 = NULL ;
V_43 = F_67 ( V_17 ) ;
break;
}
V_67 -> V_124 = V_17 ;
if ( V_43 )
break;
}
}
F_68 ( V_2 -> V_122 ) ;
return V_43 ;
}
static int F_69 ( struct V_1 * V_2 ,
struct V_125 * V_125 )
{
struct V_3 * V_17 ;
struct V_50 * V_51 ;
int V_43 ;
if ( F_3 ( V_125 -> V_83 >= V_126 ||
V_2 -> V_125 [ V_125 -> V_83 ] ) )
return - V_127 ;
V_17 = & V_125 -> V_124 ;
V_17 -> V_29 = V_35 ;
V_51 = F_25 ( V_2 ) ;
if ( ! V_51 )
return - V_128 ;
F_41 ( V_17 , V_51 ) ;
V_43 = F_70 ( & V_2 -> V_73 , V_17 ) ;
if ( ! V_43 )
V_2 -> V_125 [ V_125 -> V_83 ] = V_125 ;
else
F_52 ( & V_2 -> V_73 , L_15 ,
V_125 -> V_83 ) ;
return V_43 ;
}
static int F_71 ( struct V_1 * V_2 , struct V_129 * V_130 )
{
struct V_3 * V_17 ;
struct V_50 * V_51 ;
int V_43 ;
if ( F_3 ( V_130 -> V_131 >= V_132 || V_2 -> V_130 [ V_130 -> V_131 ] ) )
return - V_127 ;
V_17 = & V_130 -> V_133 . V_124 ;
V_17 -> V_29 = V_37 ;
V_51 = F_25 ( V_2 ) ;
if ( ! V_51 )
return - V_128 ;
F_41 ( V_17 , V_51 ) ;
V_43 = F_70 ( & V_2 -> V_73 , V_17 ) ;
if ( ! V_43 ) {
if ( ! V_2 -> V_122 && V_130 -> V_115 )
V_2 -> V_122 = & V_130 -> V_115 -> V_79 ;
V_2 -> V_130 [ V_130 -> V_131 ] = V_130 ;
V_130 -> V_133 . V_134 = V_2 -> V_134 ;
} else {
F_52 ( & V_2 -> V_73 , L_16 ,
V_130 -> V_131 , V_43 ) ;
}
return V_43 ;
}
static int F_72 ( struct V_1 * V_2 ,
struct V_135 * V_115 ,
struct V_3 * V_17 )
{
struct V_81 * V_111 = V_115 -> V_79 . V_80 ;
int V_131 , V_43 ;
V_131 = V_111 ? F_62 ( V_111 ) : F_73 ( 0 , V_115 -> V_131 ) ;
if ( F_3 ( V_131 < 0 || V_131 >= V_136 ) )
return - V_137 ;
if ( F_3 ( V_2 -> V_138 [ V_131 ] . V_17 ) )
return - V_127 ;
V_17 -> V_29 = V_33 ;
V_43 = F_70 ( & V_2 -> V_73 , V_17 ) ;
if ( ! V_43 )
V_2 -> V_138 [ V_131 ] . V_17 = V_17 ;
else
F_52 ( & V_2 -> V_73 ,
L_17 , V_131 , V_43 ) ;
return V_43 ;
}
static int F_74 ( struct V_1 * V_2 , struct V_139 * V_140 )
{
struct V_3 * V_17 = & V_140 -> V_141 . V_124 ;
struct V_50 * V_51 ;
int V_43 ;
V_51 = F_25 ( V_2 ) ;
if ( ! V_51 )
return - V_128 ;
F_41 ( V_17 , V_51 ) ;
V_43 = F_70 ( & V_2 -> V_73 , V_17 ) ;
if ( V_43 ) {
F_52 ( & V_2 -> V_73 ,
L_18 , V_43 ) ;
return V_43 ;
}
V_2 -> V_139 = V_140 ;
return 0 ;
}
static int F_75 ( struct V_1 * V_2 ,
struct V_135 * V_115 ,
int V_142 )
{
struct V_143 * V_79 = & V_115 -> V_79 ;
int V_43 = - V_74 ;
void * V_144 ;
F_76 ( V_79 ) ;
if ( ! V_79 -> V_145 || ! F_77 ( V_79 -> V_145 -> V_146 ) )
goto V_147;
V_144 = F_78 ( V_79 ) ;
if ( V_144 ) {
switch ( V_142 ) {
case V_38 :
V_43 = F_71 ( V_2 , V_144 ) ;
break;
case V_36 :
V_43 = F_69 ( V_2 , V_144 ) ;
break;
case V_34 :
V_43 = F_72 ( V_2 , V_115 , V_144 ) ;
break;
case V_40 :
V_43 = F_74 ( V_2 , V_144 ) ;
break;
default:
V_43 = - V_58 ;
}
}
F_79 ( V_79 -> V_145 -> V_146 ) ;
V_147:
F_80 ( V_79 ) ;
if ( V_43 == - V_74 )
F_81 ( & V_2 -> V_115 -> V_79 , L_19 ,
F_82 ( V_79 ) ) ;
else if ( V_43 < 0 )
F_83 ( & V_2 -> V_115 -> V_79 , L_20 ,
F_82 ( V_79 ) , V_43 ) ;
return V_43 ;
}
static int F_84 ( struct V_143 * V_79 , void * V_148 )
{
struct V_135 * V_115 = F_85 ( V_79 ) ;
int V_142 = - 1 ;
int V_43 ;
char * V_14 ;
if ( ! F_86 ( V_79 ) )
return - V_58 ;
if ( ! strcmp ( V_115 -> V_76 , V_149 ) ) {
V_142 = V_34 ;
} else {
V_14 = strstr ( V_115 -> V_76 , L_21 ) ;
if ( V_14 && * ( V_14 + 4 ) == 0 )
V_142 = V_38 ;
}
if ( V_142 >= 0 )
V_43 = F_75 ( V_148 , V_115 ,
V_142 ) ;
F_87 ( V_79 ) ;
return 0 ;
}
static int F_88 ( struct V_1 * V_2 ,
struct V_81 * V_114 )
{
struct V_81 * V_111 ;
int V_43 = 0 ;
F_59 (parent, node) {
struct V_135 * V_115 ;
int V_142 = - 1 ;
V_115 = F_89 ( V_111 ) ;
if ( ! V_115 )
continue;
if ( ! strcmp ( V_111 -> V_76 , V_150 ) )
V_142 = V_34 ;
else if ( ! strcmp ( V_111 -> V_76 , V_151 ) )
V_142 = V_40 ;
else if ( ! strcmp ( V_111 -> V_76 , V_152 ) )
V_142 = V_36 ;
else if ( ! strcmp ( V_111 -> V_76 , V_153 ) &&
! F_90 ( V_111 , L_22 ) )
V_142 = V_38 ;
if ( V_142 >= 0 )
V_43 = F_75 ( V_2 , V_115 ,
V_142 ) ;
F_87 ( & V_115 -> V_79 ) ;
if ( V_43 < 0 )
break;
}
return V_43 ;
}
static void F_91 ( struct V_1 * V_2 )
{
int V_18 ;
for ( V_18 = 0 ; V_18 < V_132 ; V_18 ++ ) {
struct V_129 * V_79 = V_2 -> V_130 [ V_18 ] ;
if ( V_79 == NULL )
continue;
F_44 ( & V_79 -> V_133 . V_124 ) ;
V_79 -> V_133 . V_154 . V_155 = NULL ;
V_2 -> V_130 [ V_18 ] = NULL ;
}
for ( V_18 = 0 ; V_18 < V_126 ; V_18 ++ ) {
struct V_125 * V_79 = V_2 -> V_125 [ V_18 ] ;
if ( V_79 == NULL )
continue;
F_44 ( & V_79 -> V_124 ) ;
V_79 -> V_154 . V_155 = NULL ;
V_2 -> V_125 [ V_18 ] = NULL ;
}
for ( V_18 = 0 ; V_18 < V_136 ; V_18 ++ ) {
if ( V_2 -> V_138 [ V_18 ] . V_17 == NULL )
continue;
F_44 ( V_2 -> V_138 [ V_18 ] . V_17 ) ;
V_2 -> V_138 [ V_18 ] . V_17 = NULL ;
}
if ( V_2 -> V_115 -> V_79 . V_80 == NULL ) {
for ( V_18 = 0 ; V_18 < V_2 -> V_113 ; V_18 ++ ) {
if ( V_2 -> V_4 [ V_18 ] . V_124 == NULL )
continue;
F_43 ( V_2 -> V_4 [ V_18 ] . V_124 ) ;
V_2 -> V_4 [ V_18 ] . V_124 = NULL ;
}
}
if ( V_2 -> V_139 )
F_44 ( & V_2 -> V_139 -> V_141 . V_124 ) ;
F_42 ( & V_2 -> V_73 , L_23 ) ;
}
static int F_92 ( struct V_1 * V_2 ,
struct V_15 * V_156 ,
struct V_3 * V_4 ,
int V_22 , int V_157 )
{
struct V_6 * V_67 = NULL ;
struct V_15 * V_158 ;
unsigned int V_10 = 0 ;
int V_18 , V_43 = 0 ;
if ( V_4 ) {
V_67 = F_2 ( V_4 ) ;
if ( V_67 && V_67 -> V_70 == V_105 )
V_43 = 1 ;
}
for ( V_18 = 0 ; ! V_43 && V_18 < V_132 ; V_18 ++ ) {
if ( ! V_2 -> V_130 [ V_18 ] )
continue;
if ( ! V_2 -> V_130 [ V_18 ] -> V_159 -> V_160 )
continue;
V_10 = ( ( 1 << V_18 ) & V_157 ) ? V_161 : 0 ;
V_158 = & V_2 -> V_130 [ V_18 ] -> V_133 . V_124 . V_27 ;
V_43 = F_93 ( V_156 , V_22 , V_158 ,
V_162 , V_10 ) ;
if ( V_43 )
return V_43 ;
V_43 = F_94 ( V_158 , V_163 , & V_158 -> V_25 [ 0 ] ,
& V_156 -> V_25 [ V_22 ] , V_10 ) ;
if ( V_43 )
break;
F_42 ( & V_2 -> V_73 , L_24 ,
V_156 -> V_76 , V_10 ? '=' : '-' , V_158 -> V_76 ) ;
}
for ( V_18 = 0 ; V_18 < V_126 ; V_18 ++ ) {
if ( ! V_2 -> V_125 [ V_18 ] )
continue;
V_158 = & V_2 -> V_125 [ V_18 ] -> V_124 . V_27 ;
V_43 = F_93 ( V_156 , V_22 , V_158 ,
V_164 , 0 ) ;
if ( V_43 )
return V_43 ;
V_43 = F_94 ( V_158 , V_163 , & V_158 -> V_25 [ 0 ] ,
& V_156 -> V_25 [ V_22 ] , 0 ) ;
if ( V_43 )
break;
F_42 ( & V_2 -> V_73 , L_25 ,
V_156 -> V_76 , V_158 -> V_76 ) ;
}
return 0 ;
}
static int F_95 ( struct V_1 * V_2 )
{
struct V_15 * V_156 , * V_158 ;
int V_18 , V_43 = 0 ;
for ( V_18 = 0 ; V_18 < V_126 ; V_18 ++ ) {
struct V_125 * V_130 = V_2 -> V_125 [ V_18 ] ;
if ( V_130 == NULL )
continue;
V_156 = & V_130 -> V_124 . V_27 ;
V_158 = & V_130 -> V_154 . V_165 . V_27 ;
V_43 = F_93 ( V_156 , V_166 ,
V_158 , 0 , 0 ) ;
if ( V_43 )
break;
V_158 = & V_2 -> V_139 -> V_141 . V_124 . V_27 ;
V_43 = F_93 ( V_156 , V_167 ,
V_158 , 0 , 0 ) ;
if ( V_43 )
break;
}
return V_43 ;
}
static int F_96 ( struct V_1 * V_2 )
{
struct V_168 * V_141 = & V_2 -> V_139 -> V_141 ;
struct V_15 * V_156 , * V_158 ;
int V_18 , V_43 ;
V_156 = & V_141 -> V_124 . V_27 ;
for ( V_18 = 0 ; V_18 < V_132 ; V_18 ++ ) {
if ( V_2 -> V_130 [ V_18 ] == NULL )
continue;
V_158 = & V_2 -> V_130 [ V_18 ] -> V_133 . V_124 . V_27 ;
V_43 = F_93 ( V_156 , V_169 ,
V_158 , V_170 , 0 ) ;
if ( V_43 )
return V_43 ;
}
V_158 = & V_141 -> V_171 . V_154 . V_165 . V_27 ;
if ( V_158 -> V_23 == 0 )
return 0 ;
return F_93 ( V_156 , V_172 ,
V_158 , 0 , 0 ) ;
}
static int F_97 ( struct V_1 * V_2 )
{
struct V_3 * V_173 [ V_136 ] = { NULL } ;
struct V_3 * V_4 , * V_138 ;
struct V_6 * V_90 ;
struct V_15 * V_156 , * V_158 ;
int V_18 , V_22 , V_174 = 0 , V_43 = 0 ;
T_2 V_10 , V_157 = 0 ;
for ( V_18 = 0 ; V_18 < V_2 -> V_113 ; V_18 ++ ) {
if ( V_2 -> V_4 [ V_18 ] . V_124 == NULL )
continue;
V_4 = V_2 -> V_4 [ V_18 ] . V_124 ;
V_90 = F_2 ( V_4 ) ;
if ( ! V_90 )
continue;
V_156 = NULL ;
switch ( V_90 -> V_71 ) {
case V_104 :
if ( F_98 ( V_90 -> V_93 >= V_136 ,
L_26 , V_90 -> V_93 ) )
return - V_53 ;
V_138 = V_2 -> V_138 [ V_90 -> V_93 ] . V_17 ;
if ( F_98 ( V_138 == NULL ,
L_27
L_28 ) )
return - V_53 ;
V_22 = V_4 -> V_27 . V_23 - 1 ;
V_43 = F_93 ( & V_4 -> V_27 , V_22 ,
& V_138 -> V_27 , V_175 ,
V_176 |
V_161 ) ;
if ( V_43 )
return V_43 ;
F_42 ( & V_2 -> V_73 , L_29 ,
V_4 -> V_27 . V_76 , V_138 -> V_27 . V_76 ) ;
V_156 = NULL ;
V_173 [ V_90 -> V_93 ] = V_4 ;
break;
case V_100 ... V_101 :
V_156 = & V_4 -> V_27 ;
V_22 = 0 ;
break;
default:
F_52 ( & V_2 -> V_73 , L_30 ,
V_90 -> V_71 ) ;
return - V_53 ;
}
if ( V_156 == NULL )
continue;
V_157 = 1 << V_174 ++ ;
V_43 = F_92 ( V_2 , V_156 , V_4 ,
V_22 , V_157 ) ;
}
for ( V_18 = 0 ; V_18 < V_136 ; V_18 ++ ) {
if ( V_2 -> V_138 [ V_18 ] . V_17 == NULL )
continue;
V_156 = & V_2 -> V_138 [ V_18 ] . V_17 -> V_27 ;
V_22 = V_177 ;
V_4 = V_173 [ V_18 ] ;
V_157 = 1 << V_174 ++ ;
V_43 = F_92 ( V_2 , V_156 , V_4 ,
V_22 , V_157 ) ;
}
V_10 = V_176 | V_161 ;
for ( V_18 = 0 ; V_18 < V_132 ; V_18 ++ ) {
if ( ! V_2 -> V_130 [ V_18 ] )
continue;
V_156 = & V_2 -> V_130 [ V_18 ] -> V_133 . V_124 . V_27 ;
V_158 = & V_2 -> V_130 [ V_18 ] -> V_133 . V_154 . V_165 . V_27 ;
V_43 = F_93 ( V_156 , V_178 ,
V_158 , 0 , V_10 ) ;
if ( V_43 )
break;
}
V_43 = F_95 ( V_2 ) ;
if ( V_43 < 0 )
return V_43 ;
if ( V_2 -> V_179 )
V_43 = F_96 ( V_2 ) ;
return V_43 ;
}
static void F_99 ( struct V_1 * V_2 )
{
int V_18 = V_180 ;
while ( -- V_18 >= 0 ) {
if ( F_18 ( V_2 -> V_181 [ V_18 ] . clock ) )
continue;
F_100 ( V_2 -> V_181 [ V_18 ] . clock ) ;
V_2 -> V_181 [ V_18 ] . clock = F_37 ( - V_53 ) ;
}
for ( V_18 = 0 ; V_18 < V_182 ; V_18 ++ ) {
if ( F_18 ( V_2 -> V_54 [ V_18 ] ) )
continue;
F_100 ( V_2 -> V_54 [ V_18 ] ) ;
V_2 -> V_54 [ V_18 ] = F_37 ( - V_53 ) ;
}
}
static int F_101 ( struct V_1 * V_2 )
{
struct V_143 * V_79 = NULL ;
char V_183 [ 32 ] ;
struct V_184 * clock ;
int V_18 , V_43 = 0 ;
for ( V_18 = 0 ; V_18 < V_180 ; V_18 ++ )
V_2 -> V_181 [ V_18 ] . clock = F_37 ( - V_53 ) ;
if ( V_2 -> V_115 -> V_79 . V_80 )
V_79 = & V_2 -> V_115 -> V_79 ;
for ( V_18 = 0 ; V_18 < V_180 ; V_18 ++ ) {
snprintf ( V_183 , sizeof( V_183 ) , L_31 , V_18 ) ;
clock = F_102 ( V_79 , V_183 ) ;
if ( F_18 ( clock ) ) {
F_83 ( & V_2 -> V_115 -> V_79 , L_32 ,
V_183 ) ;
V_43 = F_67 ( clock ) ;
break;
}
V_2 -> V_181 [ V_18 ] . clock = clock ;
}
if ( V_43 )
F_99 ( V_2 ) ;
if ( ! V_2 -> V_179 )
return 0 ;
V_2 -> V_54 [ V_185 ] = F_37 ( - V_53 ) ;
for ( V_18 = V_55 ; V_18 < V_182 ; V_18 ++ ) {
snprintf ( V_183 , sizeof( V_183 ) , L_33 , V_18 ) ;
clock = F_102 ( V_79 , V_183 ) ;
if ( F_18 ( clock ) ) {
F_52 ( & V_2 -> V_73 , L_32 ,
V_183 ) ;
V_43 = F_67 ( clock ) ;
break;
}
V_2 -> V_54 [ V_18 ] = clock ;
}
if ( V_43 )
F_99 ( V_2 ) ;
return V_43 ;
}
static int F_66 ( struct V_1 * V_2 ,
struct V_6 * V_67 ,
bool V_41 )
{
struct V_186 * V_181 ;
int V_43 = 0 ;
if ( V_2 -> V_115 -> V_79 . V_80 )
return 0 ;
if ( F_3 ( V_67 -> V_95 >= V_180 ) || ! V_2 || ! V_2 -> V_122 )
return - V_53 ;
V_181 = & V_2 -> V_181 [ V_67 -> V_95 ] ;
F_103 ( L_34 ,
V_67 -> V_95 , V_67 -> V_96 , V_181 -> V_42 , V_41 ) ;
if ( V_41 ) {
if ( V_181 -> V_42 > 0 &&
V_181 -> V_187 != V_67 -> V_96 )
return - V_53 ;
if ( V_181 -> V_42 ++ == 0 ) {
F_104 ( V_181 -> clock , V_67 -> V_96 ) ;
V_181 -> V_187 = V_67 -> V_96 ;
V_43 = F_64 ( V_2 -> V_122 ) ;
if ( V_43 < 0 )
return V_43 ;
V_43 = F_19 ( V_181 -> clock ) ;
F_103 ( L_35 , V_67 -> V_95 ,
F_105 ( V_181 -> clock ) ) ;
}
return V_43 ;
}
if ( F_3 ( V_181 -> V_42 == 0 ) )
return 0 ;
if ( -- V_181 -> V_42 == 0 ) {
F_21 ( V_181 -> clock ) ;
F_68 ( V_2 -> V_122 ) ;
F_103 ( L_36 , V_67 -> V_95 ) ;
}
return V_43 ;
}
int F_20 ( struct V_3 * V_17 , bool V_41 )
{
struct V_6 * V_67 = F_2 ( V_17 ) ;
struct V_1 * V_2 = F_9 ( & V_17 -> V_27 ) ;
if ( V_2 -> V_188 . V_189 > 0 )
return 0 ;
return F_66 ( V_2 , V_67 , V_41 ) ;
}
static int F_106 ( struct V_15 * V_27 , bool V_190 )
{
struct V_191 * V_154 ;
struct V_13 * V_14 ;
struct V_192 * V_165 ;
int V_43 ;
V_165 = F_107 ( V_27 ) ;
if ( V_165 -> V_27 . V_42 == 0 )
return 0 ;
V_154 = F_108 ( V_165 ) ;
V_14 = F_17 ( V_154 -> V_155 ) ;
if ( ! V_190 && V_14 -> V_20 [ V_32 ] == NULL )
return 0 ;
if ( V_190 )
V_43 = F_16 ( V_154 -> V_155 , V_27 , true ) ;
else
V_43 = F_22 ( V_154 -> V_155 ) ;
if ( V_43 == 0 && ! V_190 )
memset ( V_14 -> V_20 , 0 , sizeof( V_14 -> V_20 ) ) ;
return V_43 ;
}
static int F_109 ( struct V_15 * V_27 , bool V_190 )
{
struct V_15 * V_193 = V_27 ;
struct V_194 V_195 ;
int V_43 ;
F_110 ( & V_195 , V_27 ) ;
while ( ( V_27 = F_111 ( & V_195 ) ) ) {
if ( F_11 ( V_27 ) != V_196 )
continue;
V_43 = F_106 ( V_27 , V_190 ) ;
if ( V_43 < 0 )
goto V_197;
}
return 0 ;
V_197:
F_110 ( & V_195 , V_193 ) ;
while ( ( V_193 = F_111 ( & V_195 ) ) ) {
if ( F_11 ( V_193 ) != V_196 )
continue;
F_106 ( V_193 , ! V_190 ) ;
if ( V_193 == V_27 )
break;
}
return V_43 ;
}
static int F_112 ( struct V_198 * V_199 , unsigned int V_10 ,
unsigned int V_200 )
{
struct V_15 * V_158 = V_199 -> V_158 -> V_27 ;
int V_43 = 0 ;
if ( V_200 == V_201 ) {
if ( ! ( V_10 & V_161 ) )
V_43 = F_109 ( V_158 , false ) ;
else
;
} else if ( V_200 == V_202 &&
( V_199 -> V_10 & V_161 ) ) {
V_43 = F_109 ( V_158 , true ) ;
}
return V_43 ? - V_203 : 0 ;
}
static T_3 F_113 ( struct V_143 * V_79 ,
struct V_204 * V_205 , char * V_206 )
{
struct V_135 * V_115 = F_85 ( V_79 ) ;
struct V_1 * V_2 = F_114 ( V_115 ) ;
if ( V_2 -> V_134 )
return F_115 ( V_206 , L_37 , V_207 ) ;
return F_115 ( V_206 , L_38 , V_207 ) ;
}
static T_3 F_116 ( struct V_143 * V_79 ,
struct V_204 * V_205 ,
const char * V_206 , T_4 V_208 )
{
struct V_135 * V_115 = F_85 ( V_79 ) ;
struct V_1 * V_2 = F_114 ( V_115 ) ;
bool V_209 ;
int V_18 ;
if ( ! strcmp ( V_206 , L_39 ) )
V_209 = false ;
else if ( ! strcmp ( V_206 , L_40 ) )
V_209 = true ;
else
return V_208 ;
V_2 -> V_134 = V_209 ;
for ( V_18 = 0 ; V_18 < V_132 ; V_18 ++ )
if ( V_2 -> V_130 [ V_18 ] )
V_2 -> V_130 [ V_18 ] -> V_133 . V_134 = V_209 ;
return V_208 ;
}
static int F_117 ( struct V_1 * V_2 )
{
struct V_143 * V_79 = & V_2 -> V_115 -> V_79 ;
struct V_210 * V_211 = & V_2 -> V_212 ;
V_211 -> V_213 = F_118 ( V_79 ) ;
if ( F_18 ( V_211 -> V_213 ) )
return F_67 ( V_211 -> V_213 ) ;
V_211 -> V_214 = F_119 ( V_211 -> V_213 ,
V_215 ) ;
if ( F_18 ( V_211 -> V_214 ) )
return F_67 ( V_211 -> V_214 ) ;
V_211 -> V_216 = F_119 ( V_211 -> V_213 ,
V_217 ) ;
return 0 ;
}
static int F_120 ( struct V_218 * V_219 )
{
struct V_220 * V_181 = F_121 ( V_219 ) ;
int V_43 ;
if ( V_181 -> V_2 -> V_122 == NULL )
return - V_58 ;
V_43 = F_64 ( V_181 -> V_2 -> V_122 ) ;
return V_43 < 0 ? V_43 : 0 ;
}
static void F_122 ( struct V_218 * V_219 )
{
struct V_220 * V_181 = F_121 ( V_219 ) ;
if ( V_181 -> V_2 -> V_122 == NULL )
return;
F_123 ( V_181 -> V_2 -> V_122 ) ;
}
static void F_124 ( struct V_1 * V_2 )
{
struct V_221 * V_222 = & V_2 -> V_188 ;
unsigned int V_18 ;
if ( V_222 -> V_80 )
F_125 ( V_222 -> V_80 ) ;
for ( V_18 = 0 ; V_18 < V_222 -> V_189 ; V_18 ++ )
F_126 ( V_222 -> V_223 [ V_18 ] ) ;
}
static int F_127 ( struct V_1 * V_2 )
{
struct V_221 * V_222 = & V_2 -> V_188 ;
struct V_143 * V_79 = & V_2 -> V_115 -> V_79 ;
int V_18 , V_43 ;
for ( V_18 = 0 ; V_18 < V_180 ; V_18 ++ ) {
struct V_220 * V_181 = & V_222 -> V_181 [ V_18 ] ;
struct V_224 V_225 ;
const char * V_226 ;
V_43 = F_128 ( V_79 -> V_80 ,
L_41 , V_18 , & V_225 . V_76 ) ;
if ( V_43 < 0 )
break;
V_226 = F_129 ( V_2 -> V_181 [ V_18 ] . clock ) ;
V_225 . V_227 = & V_226 ;
V_225 . V_228 = 1 ;
V_225 . V_64 = & V_229 ;
V_225 . V_10 = V_230 ;
V_181 -> V_219 . V_225 = & V_225 ;
V_181 -> V_2 = V_2 ;
V_222 -> V_223 [ V_18 ] = F_130 ( NULL , & V_181 -> V_219 ) ;
if ( F_18 ( V_222 -> V_223 [ V_18 ] ) ) {
F_83 ( V_79 , L_42 ,
V_225 . V_76 , F_67 ( V_222 -> V_223 [ V_18 ] ) ) ;
V_43 = F_67 ( V_222 -> V_223 [ V_18 ] ) ;
goto V_197;
}
V_222 -> V_189 ++ ;
}
if ( V_222 -> V_189 == 0 ) {
F_131 ( V_79 , L_43 ) ;
return 0 ;
}
V_222 -> V_231 . V_223 = V_222 -> V_223 ;
V_222 -> V_231 . V_232 = V_222 -> V_189 ;
V_222 -> V_80 = V_79 -> V_80 ;
V_43 = F_132 ( V_79 -> V_80 , V_233 ,
& V_222 -> V_231 ) ;
if ( V_43 == 0 )
return 0 ;
V_197:
F_124 ( V_2 ) ;
return V_43 ;
}
static int F_133 ( struct V_234 * V_235 ,
struct V_3 * V_124 ,
struct V_236 * V_106 )
{
struct V_1 * V_2 = F_134 ( V_235 ) ;
struct V_8 * V_67 = NULL ;
int V_18 ;
for ( V_18 = 0 ; V_18 < F_57 ( V_2 -> V_4 ) ; V_18 ++ )
if ( V_2 -> V_4 [ V_18 ] . V_106 . V_109 . V_110 . V_111 == V_124 -> V_79 -> V_80 )
V_67 = & V_2 -> V_4 [ V_18 ] ;
if ( V_67 == NULL )
return - V_53 ;
F_41 ( V_124 , & V_67 -> V_90 ) ;
if ( V_67 -> V_90 . V_70 == V_105 )
V_124 -> V_29 = V_31 ;
else
V_124 -> V_29 = V_30 ;
V_67 -> V_124 = V_124 ;
F_42 ( & V_2 -> V_73 , L_44 ,
V_124 -> V_76 , V_2 -> V_113 ) ;
V_2 -> V_113 ++ ;
return 0 ;
}
static int F_135 ( struct V_234 * V_235 )
{
struct V_1 * V_2 = F_134 ( V_235 ) ;
int V_43 ;
F_136 ( & V_2 -> V_237 . V_238 ) ;
V_43 = F_97 ( V_2 ) ;
if ( V_43 < 0 )
goto V_239;
V_43 = F_137 ( & V_2 -> V_73 ) ;
V_239:
F_138 ( & V_2 -> V_237 . V_238 ) ;
return V_43 ;
}
static int F_139 ( struct V_135 * V_115 )
{
struct V_143 * V_79 = & V_115 -> V_79 ;
struct V_240 * V_73 ;
struct V_1 * V_2 ;
int V_43 ;
V_2 = F_140 ( V_79 , sizeof( * V_2 ) , V_61 ) ;
if ( ! V_2 )
return - V_128 ;
F_141 ( & V_2 -> V_11 ) ;
V_2 -> V_115 = V_115 ;
F_142 ( & V_2 -> V_63 ) ;
F_115 ( V_2 -> V_237 . V_241 , L_45 ,
sizeof( V_2 -> V_237 . V_241 ) ) ;
V_2 -> V_237 . V_242 = F_112 ;
V_2 -> V_237 . V_79 = V_79 ;
V_73 = & V_2 -> V_73 ;
V_73 -> V_243 = & V_2 -> V_237 ;
V_73 -> V_244 = V_245 ;
F_115 ( V_73 -> V_76 , L_46 , sizeof( V_73 -> V_76 ) ) ;
V_2 -> V_179 = F_143 ( V_79 -> V_80 ) ;
V_43 = F_144 ( V_79 , & V_2 -> V_73 ) ;
if ( V_43 < 0 ) {
F_52 ( V_73 , L_47 , V_43 ) ;
return V_43 ;
}
V_43 = F_145 ( & V_2 -> V_237 ) ;
if ( V_43 < 0 ) {
F_52 ( V_73 , L_48 , V_43 ) ;
goto V_246;
}
V_43 = F_101 ( V_2 ) ;
if ( V_43 )
goto V_247;
V_2 -> V_134 = ( V_79 -> V_80 != NULL ) ;
V_43 = F_117 ( V_2 ) ;
if ( V_43 < 0 ) {
if ( V_43 != V_74 )
F_83 ( V_79 , L_49 , V_43 ) ;
goto V_248;
}
F_146 ( V_115 , V_2 ) ;
F_136 ( & V_2 -> V_237 . V_238 ) ;
if ( V_79 -> V_80 )
V_43 = F_88 ( V_2 , V_79 -> V_80 ) ;
else
V_43 = F_147 ( & V_249 , NULL , V_2 ,
F_84 ) ;
if ( V_43 ) {
F_138 ( & V_2 -> V_237 . V_238 ) ;
goto V_248;
}
if ( V_79 -> V_120 || V_79 -> V_80 ) {
V_43 = F_63 ( V_2 ) ;
if ( V_43 ) {
F_138 ( & V_2 -> V_237 . V_238 ) ;
goto V_250;
}
}
F_138 ( & V_2 -> V_237 . V_238 ) ;
V_43 = F_148 ( & V_115 -> V_79 , & V_251 ) ;
if ( V_43 )
goto V_250;
V_43 = F_127 ( V_2 ) ;
if ( V_43 < 0 ) {
F_52 ( V_73 , L_50 ) ;
goto V_252;
}
if ( V_2 -> V_113 > 0 ) {
V_2 -> V_253 . V_20 = V_2 -> V_112 ;
V_2 -> V_253 . V_254 = V_2 -> V_113 ;
V_2 -> V_253 . V_255 = F_133 ;
V_2 -> V_253 . V_256 = F_135 ;
V_2 -> V_113 = 0 ;
V_43 = F_149 ( & V_2 -> V_73 ,
& V_2 -> V_253 ) ;
if ( V_43 )
goto V_257;
}
return 0 ;
V_257:
F_124 ( V_2 ) ;
V_252:
F_150 ( & V_115 -> V_79 , & V_251 ) ;
V_248:
F_99 ( V_2 ) ;
V_250:
F_91 ( V_2 ) ;
V_247:
F_151 ( & V_2 -> V_237 ) ;
V_246:
F_152 ( & V_2 -> V_73 ) ;
return V_43 ;
}
static int F_153 ( struct V_135 * V_115 )
{
struct V_1 * V_2 = F_114 ( V_115 ) ;
if ( ! V_2 )
return 0 ;
F_124 ( V_2 ) ;
F_154 ( & V_2 -> V_253 ) ;
F_152 ( & V_2 -> V_73 ) ;
F_150 ( & V_115 -> V_79 , & V_251 ) ;
F_91 ( V_2 ) ;
F_28 ( V_2 ) ;
F_151 ( & V_2 -> V_237 ) ;
F_99 ( V_2 ) ;
return 0 ;
}
static int T_5 F_155 ( void )
{
int V_43 ;
F_156 ( L_51 ) ;
V_43 = F_157 () ;
if ( V_43 )
return V_43 ;
return F_158 ( & V_258 ) ;
}
static void T_6 F_159 ( void )
{
F_160 ( & V_258 ) ;
F_161 () ;
}
