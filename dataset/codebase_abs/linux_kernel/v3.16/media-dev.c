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
V_43 = F_15 ( V_14 , 1 ) ;
if ( ! V_43 )
return 0 ;
if ( ! F_18 ( V_2 -> V_54 [ V_55 ] ) && V_14 -> V_20 [ V_40 ] )
F_20 ( V_2 -> V_54 [ V_55 ] ) ;
return V_43 ;
}
static int F_21 ( struct V_50 * V_51 )
{
struct V_13 * V_14 = F_17 ( V_51 ) ;
struct V_3 * V_17 = V_14 ? V_14 -> V_20 [ V_32 ] : NULL ;
struct V_1 * V_2 ;
int V_43 ;
if ( V_17 == NULL ) {
F_22 ( L_1 , V_56 ) ;
return 0 ;
}
V_43 = F_15 ( V_14 , 0 ) ;
V_2 = F_9 ( & V_17 -> V_27 ) ;
if ( ! F_18 ( V_2 -> V_54 [ V_55 ] ) && V_14 -> V_20 [ V_40 ] )
F_20 ( V_2 -> V_54 [ V_55 ] ) ;
return V_43 == - V_44 ? 0 : V_43 ;
}
static int F_23 ( struct V_50 * V_51 , bool V_41 )
{
static const T_1 V_48 [ 2 ] [ V_19 ] = {
{ V_38 , V_32 , V_40 , V_34 , V_36 } ,
{ V_34 , V_36 , V_38 , V_32 , V_40 } ,
} ;
struct V_13 * V_14 = F_17 ( V_51 ) ;
int V_18 , V_43 = 0 ;
if ( V_14 -> V_20 [ V_32 ] == NULL )
return - V_57 ;
for ( V_18 = 0 ; V_18 < V_19 ; V_18 ++ ) {
unsigned int V_49 = V_48 [ V_41 ] [ V_18 ] ;
V_43 = F_14 ( V_14 -> V_20 [ V_49 ] , V_58 , V_59 , V_41 ) ;
if ( V_43 < 0 && V_43 != - V_47 && V_43 != - V_57 )
goto error;
}
return 0 ;
error:
for (; V_18 >= 0 ; V_18 -- ) {
unsigned int V_49 = V_48 [ V_41 ] [ V_18 ] ;
F_14 ( V_14 -> V_20 [ V_49 ] , V_58 , V_59 , ! V_41 ) ;
}
return V_43 ;
}
static struct V_50 * F_24 (
struct V_1 * V_2 )
{
struct V_13 * V_14 ;
V_14 = F_25 ( sizeof( * V_14 ) , V_60 ) ;
if ( ! V_14 )
return NULL ;
F_26 ( & V_14 -> V_61 , & V_2 -> V_62 ) ;
V_14 -> V_51 . V_63 = & V_64 ;
return & V_14 -> V_51 ;
}
static void F_27 ( struct V_1 * V_2 )
{
while ( ! F_28 ( & V_2 -> V_62 ) ) {
struct V_13 * V_14 ;
V_14 = F_29 ( V_2 -> V_62 . V_65 , F_30 ( * V_14 ) , V_61 ) ;
F_31 ( & V_14 -> V_61 ) ;
F_32 ( V_14 ) ;
}
}
static int F_33 ( struct V_1 * V_2 ,
struct V_66 * V_67 ,
unsigned int V_68 )
{
struct V_6 * V_69 = & V_2 -> V_4 [ V_68 ] . V_70 ;
struct V_66 * V_71 , * V_51 , * V_72 ;
struct V_73 V_74 ;
V_51 = F_34 ( V_67 , NULL ) ;
if ( ! V_51 )
return 0 ;
F_35 ( V_51 , & V_74 ) ;
if ( F_3 ( V_74 . V_75 . V_67 == 0 ) || V_68 >= V_76 )
return - V_53 ;
V_69 -> V_77 = ( V_74 . V_75 . V_67 - 1 ) & 0x1 ;
V_71 = F_36 ( V_51 ) ;
F_37 ( V_51 ) ;
if ( V_71 == NULL ) {
F_38 ( & V_2 -> V_78 , L_2 ,
V_51 -> V_79 ) ;
return 0 ;
}
if ( F_39 ( V_74 . V_75 . V_67 ) ) {
if ( V_74 . V_80 == V_81 )
V_69 -> V_82 = V_83 ;
else
V_69 -> V_82 = V_84 ;
V_69 -> V_10 = V_74 . V_85 . V_86 . V_10 ;
} else if ( F_40 ( V_74 . V_75 . V_67 ) ) {
V_69 -> V_82 = V_87 ;
} else {
F_41 ( & V_2 -> V_78 , L_3 ,
V_74 . V_75 . V_67 , V_71 -> V_79 ) ;
}
V_72 = F_42 ( V_71 ) ;
if ( V_72 && ! F_43 ( V_72 -> V_88 , L_4 ) )
V_69 -> V_89 = V_90 ;
else
V_69 -> V_89 = V_69 -> V_82 ;
if ( F_3 ( V_68 >= F_44 ( V_2 -> V_4 ) ) )
return - V_53 ;
V_2 -> V_4 [ V_68 ] . V_91 . V_92 = V_93 ;
V_2 -> V_4 [ V_68 ] . V_91 . V_94 . V_95 . V_96 = V_71 ;
V_2 -> V_97 [ V_68 ] = & V_2 -> V_4 [ V_68 ] . V_91 ;
V_2 -> V_98 ++ ;
F_37 ( V_71 ) ;
return 0 ;
}
static int F_45 ( struct V_1 * V_2 )
{
struct V_66 * V_99 = V_2 -> V_100 -> V_101 . V_102 ;
struct V_66 * V_96 , * V_103 ;
int V_68 = 0 ;
int V_43 ;
if ( ! V_2 -> V_104 )
return - V_44 ;
V_43 = F_46 ( V_2 -> V_104 ) ;
if ( V_43 < 0 )
return V_43 ;
V_2 -> V_98 = 0 ;
F_47 (parent, node) {
struct V_66 * V_67 ;
if ( F_43 ( V_96 -> V_88 , L_5 ) )
continue;
V_67 = F_34 ( V_96 , NULL ) ;
if ( ! V_67 )
continue;
V_43 = F_33 ( V_2 , V_67 , V_68 ) ;
if ( V_43 < 0 )
goto V_105;
V_68 ++ ;
}
V_103 = F_48 ( V_99 , L_6 ) ;
if ( ! V_103 )
goto V_105;
F_49 (ports, node) {
V_43 = F_33 ( V_2 , V_96 , V_68 ) ;
if ( V_43 < 0 )
break;
V_68 ++ ;
}
V_105:
F_50 ( V_2 -> V_104 ) ;
return V_43 ;
}
static int F_51 ( struct V_66 * V_72 )
{
T_2 V_106 = 0 ;
V_72 = F_48 ( V_72 , L_7 ) ;
if ( ! V_72 )
return - V_53 ;
F_52 ( V_72 , L_8 , & V_106 ) ;
return V_106 - V_107 ;
}
static int F_53 ( struct V_1 * V_2 ,
struct V_108 * V_108 )
{
struct V_3 * V_17 ;
struct V_50 * V_51 ;
int V_43 ;
if ( F_3 ( V_108 -> V_68 >= V_109 ||
V_2 -> V_108 [ V_108 -> V_68 ] ) )
return - V_110 ;
V_17 = & V_108 -> V_111 ;
V_17 -> V_29 = V_35 ;
V_51 = F_24 ( V_2 ) ;
if ( ! V_51 )
return - V_112 ;
F_54 ( V_17 , V_51 ) ;
V_43 = F_55 ( & V_2 -> V_78 , V_17 ) ;
if ( ! V_43 )
V_2 -> V_108 [ V_108 -> V_68 ] = V_108 ;
else
F_41 ( & V_2 -> V_78 , L_9 ,
V_108 -> V_68 ) ;
return V_43 ;
}
static int F_56 ( struct V_1 * V_2 , struct V_113 * V_114 )
{
struct V_3 * V_17 ;
struct V_50 * V_51 ;
int V_43 ;
if ( F_3 ( V_114 -> V_115 >= V_116 || V_2 -> V_114 [ V_114 -> V_115 ] ) )
return - V_110 ;
V_17 = & V_114 -> V_117 . V_111 ;
V_17 -> V_29 = V_37 ;
V_51 = F_24 ( V_2 ) ;
if ( ! V_51 )
return - V_112 ;
F_54 ( V_17 , V_51 ) ;
V_43 = F_55 ( & V_2 -> V_78 , V_17 ) ;
if ( ! V_43 ) {
if ( ! V_2 -> V_104 && V_114 -> V_100 )
V_2 -> V_104 = & V_114 -> V_100 -> V_101 ;
V_2 -> V_114 [ V_114 -> V_115 ] = V_114 ;
V_114 -> V_117 . V_118 = V_2 -> V_118 ;
} else {
F_41 ( & V_2 -> V_78 , L_10 ,
V_114 -> V_115 , V_43 ) ;
}
return V_43 ;
}
static int F_57 ( struct V_1 * V_2 ,
struct V_119 * V_100 ,
struct V_3 * V_17 )
{
struct V_66 * V_96 = V_100 -> V_101 . V_102 ;
int V_115 , V_43 ;
V_115 = V_96 ? F_51 ( V_96 ) : F_58 ( 0 , V_100 -> V_115 ) ;
if ( F_3 ( V_115 < 0 || V_115 >= V_120 ) )
return - V_121 ;
if ( F_3 ( V_2 -> V_122 [ V_115 ] . V_17 ) )
return - V_110 ;
V_17 -> V_29 = V_33 ;
V_43 = F_55 ( & V_2 -> V_78 , V_17 ) ;
if ( ! V_43 )
V_2 -> V_122 [ V_115 ] . V_17 = V_17 ;
else
F_41 ( & V_2 -> V_78 ,
L_11 , V_115 , V_43 ) ;
return V_43 ;
}
static int F_59 ( struct V_1 * V_2 , struct V_123 * V_124 )
{
struct V_3 * V_17 = & V_124 -> V_125 . V_111 ;
struct V_50 * V_51 ;
int V_43 ;
V_51 = F_24 ( V_2 ) ;
if ( ! V_51 )
return - V_112 ;
F_54 ( V_17 , V_51 ) ;
V_43 = F_55 ( & V_2 -> V_78 , V_17 ) ;
if ( V_43 ) {
F_41 ( & V_2 -> V_78 ,
L_12 , V_43 ) ;
return V_43 ;
}
V_2 -> V_123 = V_124 ;
return 0 ;
}
static int F_60 ( struct V_1 * V_2 ,
struct V_119 * V_100 ,
int V_126 )
{
struct V_127 * V_101 = & V_100 -> V_101 ;
int V_43 = - V_128 ;
void * V_129 ;
F_61 ( V_101 ) ;
if ( ! V_101 -> V_130 || ! F_62 ( V_101 -> V_130 -> V_131 ) )
goto V_132;
V_129 = F_63 ( V_101 ) ;
if ( V_129 ) {
switch ( V_126 ) {
case V_38 :
V_43 = F_56 ( V_2 , V_129 ) ;
break;
case V_36 :
V_43 = F_53 ( V_2 , V_129 ) ;
break;
case V_34 :
V_43 = F_57 ( V_2 , V_100 , V_129 ) ;
break;
case V_40 :
V_43 = F_59 ( V_2 , V_129 ) ;
break;
default:
V_43 = - V_57 ;
}
}
F_64 ( V_101 -> V_130 -> V_131 ) ;
V_132:
F_65 ( V_101 ) ;
if ( V_43 == - V_128 )
F_66 ( & V_2 -> V_100 -> V_101 , L_13 ,
F_67 ( V_101 ) ) ;
else if ( V_43 < 0 )
F_68 ( & V_2 -> V_100 -> V_101 , L_14 ,
F_67 ( V_101 ) , V_43 ) ;
return V_43 ;
}
static int F_69 ( struct V_1 * V_2 ,
struct V_66 * V_99 )
{
struct V_66 * V_96 ;
int V_43 = 0 ;
F_47 (parent, node) {
struct V_119 * V_100 ;
int V_126 = - 1 ;
V_100 = F_70 ( V_96 ) ;
if ( ! V_100 )
continue;
if ( ! strcmp ( V_96 -> V_88 , V_133 ) )
V_126 = V_34 ;
else if ( ! strcmp ( V_96 -> V_88 , V_134 ) )
V_126 = V_40 ;
else if ( ! strcmp ( V_96 -> V_88 , V_135 ) )
V_126 = V_36 ;
else if ( ! strcmp ( V_96 -> V_88 , V_136 ) &&
! F_71 ( V_96 , L_15 ) )
V_126 = V_38 ;
if ( V_126 >= 0 )
V_43 = F_60 ( V_2 , V_100 ,
V_126 ) ;
F_72 ( & V_100 -> V_101 ) ;
if ( V_43 < 0 )
break;
}
return V_43 ;
}
static void F_73 ( struct V_1 * V_2 )
{
int V_18 ;
for ( V_18 = 0 ; V_18 < V_116 ; V_18 ++ ) {
struct V_113 * V_101 = V_2 -> V_114 [ V_18 ] ;
if ( V_101 == NULL )
continue;
F_74 ( & V_101 -> V_117 . V_111 ) ;
V_101 -> V_117 . V_137 . V_138 = NULL ;
V_2 -> V_114 [ V_18 ] = NULL ;
}
for ( V_18 = 0 ; V_18 < V_109 ; V_18 ++ ) {
struct V_108 * V_101 = V_2 -> V_108 [ V_18 ] ;
if ( V_101 == NULL )
continue;
F_74 ( & V_101 -> V_111 ) ;
V_101 -> V_137 . V_138 = NULL ;
V_2 -> V_108 [ V_18 ] = NULL ;
}
for ( V_18 = 0 ; V_18 < V_120 ; V_18 ++ ) {
if ( V_2 -> V_122 [ V_18 ] . V_17 == NULL )
continue;
F_74 ( V_2 -> V_122 [ V_18 ] . V_17 ) ;
V_2 -> V_122 [ V_18 ] . V_17 = NULL ;
}
if ( V_2 -> V_123 )
F_74 ( & V_2 -> V_123 -> V_125 . V_111 ) ;
F_38 ( & V_2 -> V_78 , L_16 ) ;
}
static int F_75 ( struct V_1 * V_2 ,
struct V_15 * V_139 ,
struct V_3 * V_4 ,
int V_22 , int V_140 )
{
struct V_6 * V_141 = NULL ;
struct V_15 * V_142 ;
unsigned int V_10 = 0 ;
int V_18 , V_43 = 0 ;
if ( V_4 ) {
V_141 = F_2 ( V_4 ) ;
if ( V_141 && V_141 -> V_89 == V_90 )
V_43 = 1 ;
}
for ( V_18 = 0 ; ! V_43 && V_18 < V_116 ; V_18 ++ ) {
if ( ! V_2 -> V_114 [ V_18 ] )
continue;
if ( ! V_2 -> V_114 [ V_18 ] -> V_143 -> V_144 )
continue;
V_10 = ( ( 1 << V_18 ) & V_140 ) ? V_145 : 0 ;
V_142 = & V_2 -> V_114 [ V_18 ] -> V_117 . V_111 . V_27 ;
V_43 = F_76 ( V_139 , V_22 , V_142 ,
V_146 , V_10 ) ;
if ( V_43 )
return V_43 ;
V_43 = F_77 ( V_142 , V_147 , & V_142 -> V_25 [ 0 ] ,
& V_139 -> V_25 [ V_22 ] , V_10 ) ;
if ( V_43 )
break;
F_38 ( & V_2 -> V_78 , L_17 ,
V_139 -> V_88 , V_10 ? '=' : '-' , V_142 -> V_88 ) ;
}
for ( V_18 = 0 ; V_18 < V_109 ; V_18 ++ ) {
if ( ! V_2 -> V_108 [ V_18 ] )
continue;
V_142 = & V_2 -> V_108 [ V_18 ] -> V_111 . V_27 ;
V_43 = F_76 ( V_139 , V_22 , V_142 ,
V_148 , 0 ) ;
if ( V_43 )
return V_43 ;
V_43 = F_77 ( V_142 , V_147 , & V_142 -> V_25 [ 0 ] ,
& V_139 -> V_25 [ V_22 ] , 0 ) ;
if ( V_43 )
break;
F_38 ( & V_2 -> V_78 , L_18 ,
V_139 -> V_88 , V_142 -> V_88 ) ;
}
return 0 ;
}
static int F_78 ( struct V_1 * V_2 )
{
struct V_15 * V_139 , * V_142 ;
int V_18 , V_43 = 0 ;
for ( V_18 = 0 ; V_18 < V_109 ; V_18 ++ ) {
struct V_108 * V_114 = V_2 -> V_108 [ V_18 ] ;
if ( V_114 == NULL )
continue;
V_139 = & V_114 -> V_111 . V_27 ;
V_142 = & V_114 -> V_137 . V_149 . V_27 ;
V_43 = F_76 ( V_139 , V_150 ,
V_142 , 0 , 0 ) ;
if ( V_43 )
break;
V_142 = & V_2 -> V_123 -> V_125 . V_111 . V_27 ;
V_43 = F_76 ( V_139 , V_151 ,
V_142 , 0 , 0 ) ;
if ( V_43 )
break;
}
return V_43 ;
}
static int F_79 ( struct V_1 * V_2 )
{
struct V_152 * V_125 = & V_2 -> V_123 -> V_125 ;
struct V_15 * V_139 , * V_142 ;
int V_18 , V_43 ;
V_139 = & V_125 -> V_111 . V_27 ;
for ( V_18 = 0 ; V_18 < V_116 ; V_18 ++ ) {
if ( V_2 -> V_114 [ V_18 ] == NULL )
continue;
V_142 = & V_2 -> V_114 [ V_18 ] -> V_117 . V_111 . V_27 ;
V_43 = F_76 ( V_139 , V_153 ,
V_142 , V_154 , 0 ) ;
if ( V_43 )
return V_43 ;
}
V_142 = & V_125 -> V_155 . V_137 . V_149 . V_27 ;
if ( V_142 -> V_23 == 0 )
return 0 ;
return F_76 ( V_139 , V_156 ,
V_142 , 0 , 0 ) ;
}
static int F_80 ( struct V_1 * V_2 )
{
struct V_3 * V_157 [ V_120 ] = { NULL } ;
struct V_3 * V_4 , * V_122 ;
struct V_6 * V_70 ;
struct V_15 * V_139 , * V_142 ;
int V_18 , V_22 , V_158 = 0 , V_43 = 0 ;
T_2 V_10 , V_140 = 0 ;
for ( V_18 = 0 ; V_18 < V_2 -> V_98 ; V_18 ++ ) {
if ( V_2 -> V_4 [ V_18 ] . V_111 == NULL )
continue;
V_4 = V_2 -> V_4 [ V_18 ] . V_111 ;
V_70 = F_2 ( V_4 ) ;
if ( ! V_70 )
continue;
V_139 = NULL ;
switch ( V_70 -> V_82 ) {
case V_87 :
if ( F_81 ( V_70 -> V_77 >= V_120 ,
L_19 , V_70 -> V_77 ) )
return - V_53 ;
V_122 = V_2 -> V_122 [ V_70 -> V_77 ] . V_17 ;
if ( F_81 ( V_122 == NULL ,
L_20
L_21 ) )
return - V_53 ;
V_22 = V_4 -> V_27 . V_23 - 1 ;
V_43 = F_76 ( & V_4 -> V_27 , V_22 ,
& V_122 -> V_27 , V_159 ,
V_160 |
V_145 ) ;
if ( V_43 )
return V_43 ;
F_38 ( & V_2 -> V_78 , L_22 ,
V_4 -> V_27 . V_88 , V_122 -> V_27 . V_88 ) ;
V_139 = NULL ;
V_157 [ V_70 -> V_77 ] = V_4 ;
break;
case V_83 ... V_84 :
V_139 = & V_4 -> V_27 ;
V_22 = 0 ;
break;
default:
F_41 ( & V_2 -> V_78 , L_23 ,
V_70 -> V_82 ) ;
return - V_53 ;
}
if ( V_139 == NULL )
continue;
V_140 = 1 << V_158 ++ ;
V_43 = F_75 ( V_2 , V_139 , V_4 ,
V_22 , V_140 ) ;
}
for ( V_18 = 0 ; V_18 < V_120 ; V_18 ++ ) {
if ( V_2 -> V_122 [ V_18 ] . V_17 == NULL )
continue;
V_139 = & V_2 -> V_122 [ V_18 ] . V_17 -> V_27 ;
V_22 = V_161 ;
V_4 = V_157 [ V_18 ] ;
V_140 = 1 << V_158 ++ ;
V_43 = F_75 ( V_2 , V_139 , V_4 ,
V_22 , V_140 ) ;
}
V_10 = V_160 | V_145 ;
for ( V_18 = 0 ; V_18 < V_116 ; V_18 ++ ) {
if ( ! V_2 -> V_114 [ V_18 ] )
continue;
V_139 = & V_2 -> V_114 [ V_18 ] -> V_117 . V_111 . V_27 ;
V_142 = & V_2 -> V_114 [ V_18 ] -> V_117 . V_137 . V_149 . V_27 ;
V_43 = F_76 ( V_139 , V_162 ,
V_142 , 0 , V_10 ) ;
if ( V_43 )
break;
}
V_43 = F_78 ( V_2 ) ;
if ( V_43 < 0 )
return V_43 ;
if ( V_2 -> V_163 )
V_43 = F_79 ( V_2 ) ;
return V_43 ;
}
static void F_82 ( struct V_1 * V_2 )
{
int V_18 = V_164 ;
while ( -- V_18 >= 0 ) {
if ( F_18 ( V_2 -> V_165 [ V_18 ] . clock ) )
continue;
F_83 ( V_2 -> V_165 [ V_18 ] . clock ) ;
V_2 -> V_165 [ V_18 ] . clock = F_84 ( - V_53 ) ;
}
for ( V_18 = 0 ; V_18 < V_166 ; V_18 ++ ) {
if ( F_18 ( V_2 -> V_54 [ V_18 ] ) )
continue;
F_83 ( V_2 -> V_54 [ V_18 ] ) ;
V_2 -> V_54 [ V_18 ] = F_84 ( - V_53 ) ;
}
}
static int F_85 ( struct V_1 * V_2 )
{
struct V_127 * V_101 = & V_2 -> V_100 -> V_101 ;
char V_167 [ 32 ] ;
struct V_168 * clock ;
int V_18 , V_43 = 0 ;
for ( V_18 = 0 ; V_18 < V_164 ; V_18 ++ )
V_2 -> V_165 [ V_18 ] . clock = F_84 ( - V_53 ) ;
for ( V_18 = 0 ; V_18 < V_164 ; V_18 ++ ) {
snprintf ( V_167 , sizeof( V_167 ) , L_24 , V_18 ) ;
clock = F_86 ( V_101 , V_167 ) ;
if ( F_18 ( clock ) ) {
F_68 ( V_101 , L_25 , V_167 ) ;
V_43 = F_87 ( clock ) ;
break;
}
V_2 -> V_165 [ V_18 ] . clock = clock ;
}
if ( V_43 )
F_82 ( V_2 ) ;
if ( ! V_2 -> V_163 )
return 0 ;
V_2 -> V_54 [ V_169 ] = F_84 ( - V_53 ) ;
for ( V_18 = V_55 ; V_18 < V_166 ; V_18 ++ ) {
snprintf ( V_167 , sizeof( V_167 ) , L_26 , V_18 ) ;
clock = F_86 ( V_101 , V_167 ) ;
if ( F_18 ( clock ) ) {
F_41 ( & V_2 -> V_78 , L_25 ,
V_167 ) ;
V_43 = F_87 ( clock ) ;
break;
}
V_2 -> V_54 [ V_18 ] = clock ;
}
if ( V_43 )
F_82 ( V_2 ) ;
return V_43 ;
}
static int F_88 ( struct V_15 * V_27 , bool V_170 )
{
struct V_171 * V_137 ;
struct V_13 * V_14 ;
struct V_172 * V_149 ;
int V_43 ;
V_149 = F_89 ( V_27 ) ;
if ( V_149 -> V_27 . V_42 == 0 )
return 0 ;
V_137 = F_90 ( V_149 ) ;
V_14 = F_17 ( V_137 -> V_138 ) ;
if ( ! V_170 && V_14 -> V_20 [ V_32 ] == NULL )
return 0 ;
if ( V_170 )
V_43 = F_16 ( V_137 -> V_138 , V_27 , true ) ;
else
V_43 = F_21 ( V_137 -> V_138 ) ;
if ( V_43 == 0 && ! V_170 )
memset ( V_14 -> V_20 , 0 , sizeof( V_14 -> V_20 ) ) ;
return V_43 ;
}
static int F_91 ( struct V_15 * V_27 , bool V_170 )
{
struct V_15 * V_173 = V_27 ;
struct V_174 V_175 ;
int V_43 ;
F_92 ( & V_175 , V_27 ) ;
while ( ( V_27 = F_93 ( & V_175 ) ) ) {
if ( F_11 ( V_27 ) != V_176 )
continue;
V_43 = F_88 ( V_27 , V_170 ) ;
if ( V_43 < 0 )
goto V_177;
}
return 0 ;
V_177:
F_92 ( & V_175 , V_173 ) ;
while ( ( V_173 = F_93 ( & V_175 ) ) ) {
if ( F_11 ( V_173 ) != V_176 )
continue;
F_88 ( V_173 , ! V_170 ) ;
if ( V_173 == V_27 )
break;
}
return V_43 ;
}
static int F_94 ( struct V_178 * V_179 , unsigned int V_10 ,
unsigned int V_180 )
{
struct V_15 * V_142 = V_179 -> V_142 -> V_27 ;
int V_43 = 0 ;
if ( V_180 == V_181 ) {
if ( ! ( V_10 & V_145 ) )
V_43 = F_91 ( V_142 , false ) ;
else
;
} else if ( V_180 == V_182 &&
( V_179 -> V_10 & V_145 ) ) {
V_43 = F_91 ( V_142 , true ) ;
}
return V_43 ? - V_183 : 0 ;
}
static T_3 F_95 ( struct V_127 * V_101 ,
struct V_184 * V_185 , char * V_186 )
{
struct V_119 * V_100 = F_96 ( V_101 ) ;
struct V_1 * V_2 = F_97 ( V_100 ) ;
if ( V_2 -> V_118 )
return F_98 ( V_186 , L_27 , V_187 ) ;
return F_98 ( V_186 , L_28 , V_187 ) ;
}
static T_3 F_99 ( struct V_127 * V_101 ,
struct V_184 * V_185 ,
const char * V_186 , T_4 V_188 )
{
struct V_119 * V_100 = F_96 ( V_101 ) ;
struct V_1 * V_2 = F_97 ( V_100 ) ;
bool V_189 ;
int V_18 ;
if ( ! strcmp ( V_186 , L_29 ) )
V_189 = false ;
else if ( ! strcmp ( V_186 , L_30 ) )
V_189 = true ;
else
return V_188 ;
V_2 -> V_118 = V_189 ;
for ( V_18 = 0 ; V_18 < V_116 ; V_18 ++ )
if ( V_2 -> V_114 [ V_18 ] )
V_2 -> V_114 [ V_18 ] -> V_117 . V_118 = V_189 ;
return V_188 ;
}
static int F_100 ( struct V_1 * V_2 )
{
struct V_127 * V_101 = & V_2 -> V_100 -> V_101 ;
struct V_190 * V_191 = & V_2 -> V_192 ;
V_191 -> V_193 = F_101 ( V_101 ) ;
if ( F_18 ( V_191 -> V_193 ) )
return F_87 ( V_191 -> V_193 ) ;
V_191 -> V_194 = F_102 ( V_191 -> V_193 ,
V_195 ) ;
if ( F_18 ( V_191 -> V_194 ) )
return F_87 ( V_191 -> V_194 ) ;
V_191 -> V_196 = F_102 ( V_191 -> V_193 ,
V_197 ) ;
return 0 ;
}
static int F_103 ( struct V_198 * V_199 )
{
struct V_200 * V_165 = F_104 ( V_199 ) ;
int V_43 ;
if ( V_165 -> V_2 -> V_104 == NULL )
return - V_57 ;
V_43 = F_46 ( V_165 -> V_2 -> V_104 ) ;
return V_43 < 0 ? V_43 : 0 ;
}
static void F_105 ( struct V_198 * V_199 )
{
struct V_200 * V_165 = F_104 ( V_199 ) ;
if ( V_165 -> V_2 -> V_104 == NULL )
return;
F_106 ( V_165 -> V_2 -> V_104 ) ;
}
static void F_107 ( struct V_1 * V_2 )
{
struct V_201 * V_202 = & V_2 -> V_203 ;
unsigned int V_18 ;
if ( V_202 -> V_102 )
F_108 ( V_202 -> V_102 ) ;
for ( V_18 = 0 ; V_18 < V_202 -> V_204 ; V_18 ++ )
F_109 ( V_202 -> V_205 [ V_18 ] ) ;
}
static int F_110 ( struct V_1 * V_2 )
{
struct V_201 * V_202 = & V_2 -> V_203 ;
struct V_127 * V_101 = & V_2 -> V_100 -> V_101 ;
int V_18 , V_43 ;
for ( V_18 = 0 ; V_18 < V_164 ; V_18 ++ ) {
struct V_200 * V_165 = & V_202 -> V_165 [ V_18 ] ;
struct V_206 V_207 ;
const char * V_208 ;
V_43 = F_111 ( V_101 -> V_102 ,
L_31 , V_18 , & V_207 . V_88 ) ;
if ( V_43 < 0 )
break;
V_208 = F_112 ( V_2 -> V_165 [ V_18 ] . clock ) ;
V_207 . V_209 = & V_208 ;
V_207 . V_210 = 1 ;
V_207 . V_63 = & V_211 ;
V_207 . V_10 = V_212 ;
V_165 -> V_199 . V_207 = & V_207 ;
V_165 -> V_2 = V_2 ;
V_202 -> V_205 [ V_18 ] = F_113 ( NULL , & V_165 -> V_199 ) ;
if ( F_18 ( V_202 -> V_205 [ V_18 ] ) ) {
F_68 ( V_101 , L_32 ,
V_207 . V_88 , F_87 ( V_202 -> V_205 [ V_18 ] ) ) ;
V_43 = F_87 ( V_202 -> V_205 [ V_18 ] ) ;
goto V_177;
}
V_202 -> V_204 ++ ;
}
if ( V_202 -> V_204 == 0 ) {
F_114 ( V_101 , L_33 ) ;
return 0 ;
}
V_202 -> V_213 . V_205 = V_202 -> V_205 ;
V_202 -> V_213 . V_214 = V_202 -> V_204 ;
V_202 -> V_102 = V_101 -> V_102 ;
V_43 = F_115 ( V_101 -> V_102 , V_215 ,
& V_202 -> V_213 ) ;
if ( V_43 == 0 )
return 0 ;
V_177:
F_107 ( V_2 ) ;
return V_43 ;
}
static int F_116 ( struct V_216 * V_217 ,
struct V_3 * V_111 ,
struct V_218 * V_91 )
{
struct V_1 * V_2 = F_117 ( V_217 ) ;
struct V_8 * V_141 = NULL ;
int V_18 ;
for ( V_18 = 0 ; V_18 < F_44 ( V_2 -> V_4 ) ; V_18 ++ )
if ( V_2 -> V_4 [ V_18 ] . V_91 . V_94 . V_95 . V_96 == V_111 -> V_101 -> V_102 )
V_141 = & V_2 -> V_4 [ V_18 ] ;
if ( V_141 == NULL )
return - V_53 ;
F_54 ( V_111 , & V_141 -> V_70 ) ;
if ( V_141 -> V_70 . V_89 == V_90 )
V_111 -> V_29 = V_31 ;
else
V_111 -> V_29 = V_30 ;
V_141 -> V_111 = V_111 ;
F_38 ( & V_2 -> V_78 , L_34 ,
V_111 -> V_88 , V_2 -> V_98 ) ;
V_2 -> V_98 ++ ;
return 0 ;
}
static int F_118 ( struct V_216 * V_217 )
{
struct V_1 * V_2 = F_117 ( V_217 ) ;
int V_43 ;
F_119 ( & V_2 -> V_219 . V_220 ) ;
V_43 = F_80 ( V_2 ) ;
if ( V_43 < 0 )
goto V_221;
V_43 = F_120 ( & V_2 -> V_78 ) ;
V_221:
F_121 ( & V_2 -> V_219 . V_220 ) ;
return V_43 ;
}
static int F_122 ( struct V_119 * V_100 )
{
struct V_127 * V_101 = & V_100 -> V_101 ;
struct V_222 * V_78 ;
struct V_1 * V_2 ;
int V_43 ;
V_2 = F_123 ( V_101 , sizeof( * V_2 ) , V_60 ) ;
if ( ! V_2 )
return - V_112 ;
F_124 ( & V_2 -> V_11 ) ;
F_125 ( & V_2 -> V_62 ) ;
V_2 -> V_100 = V_100 ;
F_98 ( V_2 -> V_219 . V_223 , L_35 ,
sizeof( V_2 -> V_219 . V_223 ) ) ;
V_2 -> V_219 . V_224 = F_94 ;
V_2 -> V_219 . V_101 = V_101 ;
V_78 = & V_2 -> V_78 ;
V_78 -> V_225 = & V_2 -> V_219 ;
V_78 -> V_226 = V_227 ;
F_98 ( V_78 -> V_88 , L_36 , sizeof( V_78 -> V_88 ) ) ;
V_2 -> V_163 = F_126 ( V_101 -> V_102 ) ;
V_2 -> V_118 = true ;
V_43 = F_127 ( V_101 , & V_2 -> V_78 ) ;
if ( V_43 < 0 ) {
F_41 ( V_78 , L_37 , V_43 ) ;
return V_43 ;
}
V_43 = F_128 ( & V_2 -> V_219 ) ;
if ( V_43 < 0 ) {
F_41 ( V_78 , L_38 , V_43 ) ;
goto V_228;
}
V_43 = F_85 ( V_2 ) ;
if ( V_43 )
goto V_229;
V_43 = F_100 ( V_2 ) ;
if ( V_43 < 0 ) {
if ( V_43 != V_128 )
F_68 ( V_101 , L_39 , V_43 ) ;
goto V_230;
}
F_129 ( V_100 , V_2 ) ;
F_119 ( & V_2 -> V_219 . V_220 ) ;
V_43 = F_69 ( V_2 , V_101 -> V_102 ) ;
if ( V_43 ) {
F_121 ( & V_2 -> V_219 . V_220 ) ;
goto V_230;
}
V_43 = F_45 ( V_2 ) ;
if ( V_43 ) {
F_121 ( & V_2 -> V_219 . V_220 ) ;
goto V_231;
}
F_121 ( & V_2 -> V_219 . V_220 ) ;
V_43 = F_130 ( & V_100 -> V_101 , & V_232 ) ;
if ( V_43 )
goto V_231;
V_43 = F_110 ( V_2 ) ;
if ( V_43 < 0 ) {
F_41 ( V_78 , L_40 ) ;
goto V_233;
}
if ( V_2 -> V_98 > 0 ) {
V_2 -> V_234 . V_20 = V_2 -> V_97 ;
V_2 -> V_234 . V_235 = V_2 -> V_98 ;
V_2 -> V_234 . V_236 = F_116 ;
V_2 -> V_234 . V_237 = F_118 ;
V_2 -> V_98 = 0 ;
V_43 = F_131 ( & V_2 -> V_78 ,
& V_2 -> V_234 ) ;
if ( V_43 )
goto V_238;
}
return 0 ;
V_238:
F_107 ( V_2 ) ;
V_233:
F_132 ( & V_100 -> V_101 , & V_232 ) ;
V_230:
F_82 ( V_2 ) ;
V_231:
F_73 ( V_2 ) ;
V_229:
F_133 ( & V_2 -> V_219 ) ;
V_228:
F_134 ( & V_2 -> V_78 ) ;
return V_43 ;
}
static int F_135 ( struct V_119 * V_100 )
{
struct V_1 * V_2 = F_97 ( V_100 ) ;
if ( ! V_2 )
return 0 ;
F_107 ( V_2 ) ;
F_136 ( & V_2 -> V_234 ) ;
F_134 ( & V_2 -> V_78 ) ;
F_132 ( & V_100 -> V_101 , & V_232 ) ;
F_73 ( V_2 ) ;
F_27 ( V_2 ) ;
F_133 ( & V_2 -> V_219 ) ;
F_82 ( V_2 ) ;
return 0 ;
}
static int T_5 F_137 ( void )
{
int V_43 ;
F_138 ( L_41 ) ;
V_43 = F_139 () ;
if ( V_43 )
return V_43 ;
return F_140 ( & V_239 ) ;
}
static void T_6 F_141 ( void )
{
F_142 ( & V_239 ) ;
F_143 () ;
}
