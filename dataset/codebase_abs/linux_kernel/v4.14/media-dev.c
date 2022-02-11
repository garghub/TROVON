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
if ( ! V_22 || ! F_11 ( V_22 -> V_27 ) )
break;
V_17 = F_12 ( V_22 -> V_27 ) ;
switch ( V_17 -> V_28 ) {
case V_29 :
V_4 = V_17 ;
case V_30 :
V_14 -> V_20 [ V_31 ] = V_17 ;
break;
case V_32 :
V_14 -> V_20 [ V_33 ] = V_17 ;
break;
case V_34 :
V_14 -> V_20 [ V_35 ] = V_17 ;
break;
case V_36 :
V_14 -> V_20 [ V_37 ] = V_17 ;
break;
case V_38 :
V_14 -> V_20 [ V_39 ] = V_17 ;
break;
default:
break;
}
V_16 = & V_17 -> V_27 ;
if ( V_16 -> V_23 == 1 )
break;
}
if ( V_4 && V_14 -> V_20 [ V_37 ] )
F_1 ( V_2 , V_4 , V_14 -> V_20 [ V_37 ] ) ;
}
static int F_13 ( struct V_3 * V_17 , int V_40 )
{
int * V_41 ;
int V_42 ;
if ( V_17 == NULL )
return - V_43 ;
V_41 = & V_17 -> V_27 . V_41 ;
if ( V_40 && ( * V_41 ) ++ > 0 )
return 0 ;
else if ( ! V_40 && ( * V_41 == 0 || -- ( * V_41 ) > 0 ) )
return 0 ;
V_42 = F_14 ( V_17 , V_44 , V_45 , V_40 ) ;
return V_42 != - V_46 ? V_42 : 0 ;
}
static int F_15 ( struct V_13 * V_14 , bool V_40 )
{
static const T_1 V_47 [ 2 ] [ V_19 - 1 ] = {
{ V_39 , V_31 , V_33 , V_35 } ,
{ V_33 , V_35 , V_31 , V_39 } ,
} ;
int V_18 , V_42 = 0 ;
if ( V_14 -> V_20 [ V_31 ] == NULL )
return - V_43 ;
for ( V_18 = 0 ; V_18 < V_19 - 1 ; V_18 ++ ) {
unsigned int V_48 = V_47 [ V_40 ] [ V_18 ] ;
V_42 = F_13 ( V_14 -> V_20 [ V_48 ] , V_40 ) ;
if ( V_42 < 0 && V_42 != - V_43 )
goto error;
}
return 0 ;
error:
for (; V_18 >= 0 ; V_18 -- ) {
unsigned int V_48 = V_47 [ V_40 ] [ V_18 ] ;
F_13 ( V_14 -> V_20 [ V_48 ] , ! V_40 ) ;
}
return V_42 ;
}
static int F_16 ( struct V_49 * V_50 ,
struct V_1 * V_2 )
{
struct V_13 * V_14 = F_17 ( V_50 ) ;
int V_42 ;
if ( ! F_18 ( V_2 -> V_51 [ V_52 ] ) && V_14 -> V_20 [ V_39 ] ) {
V_42 = F_19 ( V_2 -> V_51 [ V_52 ] ) ;
if ( V_42 < 0 )
return V_42 ;
}
V_42 = F_15 ( V_14 , 1 ) ;
if ( ! V_42 )
return 0 ;
if ( ! F_18 ( V_2 -> V_51 [ V_52 ] ) && V_14 -> V_20 [ V_39 ] )
F_20 ( V_2 -> V_51 [ V_52 ] ) ;
return V_42 ;
}
static int F_21 ( struct V_49 * V_50 ,
struct V_15 * V_16 , bool V_53 )
{
struct V_1 * V_2 = F_9 ( V_16 ) ;
struct V_13 * V_14 = F_17 ( V_50 ) ;
struct V_3 * V_17 ;
if ( F_3 ( V_14 == NULL || V_16 == NULL ) )
return - V_54 ;
if ( V_53 )
F_8 ( V_14 , V_16 ) ;
V_17 = V_14 -> V_20 [ V_31 ] ;
if ( V_17 == NULL ) {
F_22 ( L_1 , V_55 ) ;
return 0 ;
}
return F_16 ( V_50 , V_2 ) ;
}
static int F_23 ( struct V_49 * V_50 )
{
struct V_13 * V_14 = F_17 ( V_50 ) ;
struct V_3 * V_17 = V_14 ? V_14 -> V_20 [ V_31 ] : NULL ;
struct V_1 * V_2 ;
int V_42 ;
if ( V_17 == NULL ) {
F_22 ( L_1 , V_55 ) ;
return 0 ;
}
V_42 = F_15 ( V_14 , 0 ) ;
V_2 = F_9 ( & V_17 -> V_27 ) ;
if ( ! F_18 ( V_2 -> V_51 [ V_52 ] ) && V_14 -> V_20 [ V_39 ] )
F_20 ( V_2 -> V_51 [ V_52 ] ) ;
return V_42 == - V_43 ? 0 : V_42 ;
}
static int F_24 ( struct V_49 * V_50 , bool V_40 )
{
static const T_1 V_47 [ 2 ] [ V_19 ] = {
{ V_37 , V_31 , V_39 , V_33 , V_35 } ,
{ V_33 , V_35 , V_37 , V_31 , V_39 } ,
} ;
struct V_13 * V_14 = F_17 ( V_50 ) ;
struct V_1 * V_2 = F_9 ( & V_14 -> V_20 [ V_33 ] -> V_27 ) ;
enum V_56 V_57 ;
int V_18 , V_42 = 0 ;
if ( V_14 -> V_20 [ V_31 ] == NULL ) {
if ( ! V_2 -> V_58 ) {
return - V_59 ;
}
if ( V_14 -> V_20 [ V_37 ] )
V_57 = V_37 ;
else if ( V_14 -> V_20 [ V_39 ] )
V_57 = V_39 ;
else if ( V_14 -> V_20 [ V_35 ] )
V_57 = V_35 ;
else
return - V_59 ;
F_8 ( V_14 , & V_14 -> V_20 [ V_57 ] -> V_27 ) ;
if ( V_14 -> V_20 [ V_31 ] == NULL )
return - V_59 ;
V_42 = F_16 ( V_50 , V_2 ) ;
if ( V_42 < 0 )
return V_42 ;
}
for ( V_18 = 0 ; V_18 < V_19 ; V_18 ++ ) {
unsigned int V_48 = V_47 [ V_40 ] [ V_18 ] ;
V_42 = F_14 ( V_14 -> V_20 [ V_48 ] , V_60 , V_61 , V_40 ) ;
if ( V_42 < 0 && V_42 != - V_46 && V_42 != - V_59 )
goto error;
}
return 0 ;
error:
F_15 ( V_14 , ! V_40 ) ;
for (; V_18 >= 0 ; V_18 -- ) {
unsigned int V_48 = V_47 [ V_40 ] [ V_18 ] ;
F_14 ( V_14 -> V_20 [ V_48 ] , V_60 , V_61 , ! V_40 ) ;
}
return V_42 ;
}
static struct V_49 * F_25 (
struct V_1 * V_2 )
{
struct V_13 * V_14 ;
V_14 = F_26 ( sizeof( * V_14 ) , V_62 ) ;
if ( ! V_14 )
return NULL ;
F_27 ( & V_14 -> V_63 , & V_2 -> V_64 ) ;
V_14 -> V_50 . V_65 = & V_66 ;
return & V_14 -> V_50 ;
}
static void F_28 ( struct V_1 * V_2 )
{
while ( ! F_29 ( & V_2 -> V_64 ) ) {
struct V_13 * V_14 ;
V_14 = F_30 ( V_2 -> V_64 . V_67 , F_31 ( * V_14 ) , V_63 ) ;
F_32 ( & V_14 -> V_63 ) ;
F_33 ( V_14 ) ;
}
}
static int F_34 ( struct V_1 * V_2 ,
struct V_68 * V_69 ,
unsigned int V_70 )
{
struct V_6 * V_71 = & V_2 -> V_4 [ V_70 ] . V_72 ;
struct V_68 * V_73 , * V_50 , * V_74 ;
struct V_75 V_76 ;
int V_42 ;
V_50 = F_35 ( V_69 , NULL ) ;
if ( ! V_50 )
return 0 ;
V_42 = F_36 ( F_37 ( V_50 ) , & V_76 ) ;
if ( V_42 ) {
F_38 ( V_50 ) ;
return V_42 ;
}
if ( F_3 ( V_76 . V_77 . V_69 == 0 ) || V_70 >= V_78 ) {
F_38 ( V_50 ) ;
return - V_54 ;
}
V_71 -> V_79 = ( V_76 . V_77 . V_69 - 1 ) & 0x1 ;
V_73 = F_39 ( V_50 ) ;
F_38 ( V_50 ) ;
if ( V_73 == NULL ) {
F_40 ( & V_2 -> V_80 , L_2 ,
V_50 ) ;
return 0 ;
}
if ( F_41 ( V_76 . V_77 . V_69 ) ) {
if ( V_76 . V_81 == V_82 )
V_71 -> V_83 = V_84 ;
else
V_71 -> V_83 = V_85 ;
V_71 -> V_10 = V_76 . V_86 . V_87 . V_10 ;
} else if ( F_42 ( V_76 . V_77 . V_69 ) ) {
V_71 -> V_83 = V_88 ;
} else {
F_43 ( & V_2 -> V_80 , L_3 ,
V_76 . V_77 . V_69 , V_73 ) ;
}
V_74 = F_44 ( V_73 ) ;
if ( V_74 && ! F_45 ( V_74 -> V_89 , L_4 ) )
V_71 -> V_90 = V_91 ;
else
V_71 -> V_90 = V_71 -> V_83 ;
if ( F_3 ( V_70 >= F_46 ( V_2 -> V_4 ) ) ) {
F_38 ( V_73 ) ;
return - V_54 ;
}
V_2 -> V_4 [ V_70 ] . V_92 . V_93 = V_94 ;
V_2 -> V_4 [ V_70 ] . V_92 . V_95 . V_96 . V_96 = F_37 ( V_73 ) ;
V_2 -> V_97 [ V_70 ] = & V_2 -> V_4 [ V_70 ] . V_92 ;
V_2 -> V_98 ++ ;
F_38 ( V_73 ) ;
return 0 ;
}
static int F_47 ( struct V_1 * V_2 )
{
struct V_68 * V_99 = V_2 -> V_100 -> V_101 . V_102 ;
struct V_68 * V_103 , * V_104 ;
int V_70 = 0 ;
int V_42 ;
if ( ! V_2 -> V_105 )
return - V_43 ;
V_42 = F_48 ( V_2 -> V_105 ) ;
if ( V_42 < 0 )
return V_42 ;
V_2 -> V_98 = 0 ;
F_49 (parent, node) {
struct V_68 * V_69 ;
if ( F_45 ( V_103 -> V_89 , L_5 ) )
continue;
V_69 = F_35 ( V_103 , NULL ) ;
if ( ! V_69 )
continue;
V_42 = F_34 ( V_2 , V_69 , V_70 ) ;
if ( V_42 < 0 ) {
F_38 ( V_103 ) ;
goto V_106;
}
V_70 ++ ;
}
V_104 = F_50 ( V_99 , L_6 ) ;
if ( ! V_104 )
goto V_106;
F_51 (ports, node) {
V_42 = F_34 ( V_2 , V_103 , V_70 ) ;
if ( V_42 < 0 ) {
F_38 ( V_103 ) ;
break;
}
V_70 ++ ;
}
V_106:
F_52 ( V_2 -> V_105 ) ;
return V_42 ;
}
static int F_53 ( struct V_68 * V_74 )
{
T_2 V_107 = 0 ;
V_74 = F_50 ( V_74 , L_7 ) ;
if ( ! V_74 )
return - V_54 ;
F_54 ( V_74 , L_8 , & V_107 ) ;
return V_107 - V_108 ;
}
static int F_55 ( struct V_1 * V_2 ,
struct V_109 * V_109 )
{
struct V_3 * V_17 ;
struct V_49 * V_50 ;
int V_42 ;
if ( F_3 ( V_109 -> V_70 >= V_110 ||
V_2 -> V_109 [ V_109 -> V_70 ] ) )
return - V_111 ;
V_17 = & V_109 -> V_112 ;
V_17 -> V_28 = V_34 ;
V_50 = F_25 ( V_2 ) ;
if ( ! V_50 )
return - V_113 ;
F_56 ( V_17 , V_50 ) ;
V_42 = F_57 ( & V_2 -> V_80 , V_17 ) ;
if ( ! V_42 )
V_2 -> V_109 [ V_109 -> V_70 ] = V_109 ;
else
F_43 ( & V_2 -> V_80 , L_9 ,
V_109 -> V_70 ) ;
return V_42 ;
}
static int F_58 ( struct V_1 * V_2 , struct V_114 * V_115 )
{
struct V_3 * V_17 ;
struct V_49 * V_50 ;
int V_42 ;
if ( F_3 ( V_115 -> V_116 >= V_117 || V_2 -> V_115 [ V_115 -> V_116 ] ) )
return - V_111 ;
V_17 = & V_115 -> V_118 . V_112 ;
V_17 -> V_28 = V_36 ;
V_50 = F_25 ( V_2 ) ;
if ( ! V_50 )
return - V_113 ;
F_56 ( V_17 , V_50 ) ;
V_42 = F_57 ( & V_2 -> V_80 , V_17 ) ;
if ( ! V_42 ) {
if ( ! V_2 -> V_105 && V_115 -> V_100 )
V_2 -> V_105 = & V_115 -> V_100 -> V_101 ;
V_2 -> V_115 [ V_115 -> V_116 ] = V_115 ;
V_115 -> V_118 . V_58 = V_2 -> V_58 ;
} else {
F_43 ( & V_2 -> V_80 , L_10 ,
V_115 -> V_116 , V_42 ) ;
}
return V_42 ;
}
static int F_59 ( struct V_1 * V_2 ,
struct V_119 * V_100 ,
struct V_3 * V_17 )
{
struct V_68 * V_103 = V_100 -> V_101 . V_102 ;
int V_116 , V_42 ;
V_116 = V_103 ? F_53 ( V_103 ) : F_60 ( 0 , V_100 -> V_116 ) ;
if ( F_3 ( V_116 < 0 || V_116 >= V_120 ) )
return - V_121 ;
if ( F_3 ( V_2 -> V_122 [ V_116 ] . V_17 ) )
return - V_111 ;
V_17 -> V_28 = V_32 ;
V_42 = F_57 ( & V_2 -> V_80 , V_17 ) ;
if ( ! V_42 )
V_2 -> V_122 [ V_116 ] . V_17 = V_17 ;
else
F_43 ( & V_2 -> V_80 ,
L_11 , V_116 , V_42 ) ;
return V_42 ;
}
static int F_61 ( struct V_1 * V_2 , struct V_123 * V_124 )
{
struct V_3 * V_17 = & V_124 -> V_125 . V_112 ;
struct V_49 * V_50 ;
int V_42 ;
V_50 = F_25 ( V_2 ) ;
if ( ! V_50 )
return - V_113 ;
F_56 ( V_17 , V_50 ) ;
V_42 = F_57 ( & V_2 -> V_80 , V_17 ) ;
if ( V_42 ) {
F_43 ( & V_2 -> V_80 ,
L_12 , V_42 ) ;
return V_42 ;
}
V_2 -> V_123 = V_124 ;
return 0 ;
}
static int F_62 ( struct V_1 * V_2 ,
struct V_119 * V_100 ,
int V_126 )
{
struct V_127 * V_101 = & V_100 -> V_101 ;
int V_42 = - V_128 ;
void * V_129 ;
F_63 ( V_101 ) ;
if ( ! V_101 -> V_130 || ! F_64 ( V_101 -> V_130 -> V_131 ) )
goto V_132;
V_129 = F_65 ( V_101 ) ;
if ( V_129 ) {
switch ( V_126 ) {
case V_37 :
V_42 = F_58 ( V_2 , V_129 ) ;
break;
case V_35 :
V_42 = F_55 ( V_2 , V_129 ) ;
break;
case V_33 :
V_42 = F_59 ( V_2 , V_100 , V_129 ) ;
break;
case V_39 :
V_42 = F_61 ( V_2 , V_129 ) ;
break;
default:
V_42 = - V_59 ;
}
}
F_66 ( V_101 -> V_130 -> V_131 ) ;
V_132:
F_67 ( V_101 ) ;
if ( V_42 == - V_128 )
F_68 ( & V_2 -> V_100 -> V_101 , L_13 ,
F_69 ( V_101 ) ) ;
else if ( V_42 < 0 )
F_70 ( & V_2 -> V_100 -> V_101 , L_14 ,
F_69 ( V_101 ) , V_42 ) ;
return V_42 ;
}
static int F_71 ( struct V_1 * V_2 ,
struct V_68 * V_99 )
{
struct V_68 * V_103 ;
int V_42 = 0 ;
F_49 (parent, node) {
struct V_119 * V_100 ;
int V_126 = - 1 ;
V_100 = F_72 ( V_103 ) ;
if ( ! V_100 )
continue;
if ( ! strcmp ( V_103 -> V_89 , V_133 ) )
V_126 = V_33 ;
else if ( ! strcmp ( V_103 -> V_89 , V_134 ) )
V_126 = V_39 ;
else if ( ! strcmp ( V_103 -> V_89 , V_135 ) )
V_126 = V_35 ;
else if ( ! strcmp ( V_103 -> V_89 , V_136 ) &&
! F_73 ( V_103 , L_15 ) )
V_126 = V_37 ;
if ( V_126 >= 0 )
V_42 = F_62 ( V_2 , V_100 ,
V_126 ) ;
F_74 ( & V_100 -> V_101 ) ;
if ( V_42 < 0 ) {
F_38 ( V_103 ) ;
break;
}
}
return V_42 ;
}
static void F_75 ( struct V_1 * V_2 )
{
int V_18 ;
for ( V_18 = 0 ; V_18 < V_117 ; V_18 ++ ) {
struct V_114 * V_101 = V_2 -> V_115 [ V_18 ] ;
if ( V_101 == NULL )
continue;
F_76 ( & V_101 -> V_118 . V_112 ) ;
V_101 -> V_118 . V_137 . V_138 = NULL ;
V_2 -> V_115 [ V_18 ] = NULL ;
}
for ( V_18 = 0 ; V_18 < V_110 ; V_18 ++ ) {
struct V_109 * V_101 = V_2 -> V_109 [ V_18 ] ;
if ( V_101 == NULL )
continue;
F_76 ( & V_101 -> V_112 ) ;
V_101 -> V_137 . V_138 = NULL ;
V_2 -> V_109 [ V_18 ] = NULL ;
}
for ( V_18 = 0 ; V_18 < V_120 ; V_18 ++ ) {
if ( V_2 -> V_122 [ V_18 ] . V_17 == NULL )
continue;
F_76 ( V_2 -> V_122 [ V_18 ] . V_17 ) ;
V_2 -> V_122 [ V_18 ] . V_17 = NULL ;
}
if ( V_2 -> V_123 )
F_76 ( & V_2 -> V_123 -> V_125 . V_112 ) ;
F_40 ( & V_2 -> V_80 , L_16 ) ;
}
static int F_77 ( struct V_1 * V_2 ,
struct V_15 * V_139 ,
struct V_3 * V_4 ,
int V_22 , int V_140 )
{
struct V_6 * V_141 = NULL ;
struct V_15 * V_142 ;
unsigned int V_10 = 0 ;
int V_18 , V_42 = 0 ;
if ( V_4 ) {
V_141 = F_2 ( V_4 ) ;
if ( V_141 && V_141 -> V_90 == V_91 )
V_42 = 1 ;
}
for ( V_18 = 0 ; ! V_42 && V_18 < V_117 ; V_18 ++ ) {
if ( ! V_2 -> V_115 [ V_18 ] )
continue;
if ( ! V_2 -> V_115 [ V_18 ] -> V_143 -> V_144 )
continue;
V_10 = ( ( 1 << V_18 ) & V_140 ) ? V_145 : 0 ;
V_142 = & V_2 -> V_115 [ V_18 ] -> V_118 . V_112 . V_27 ;
V_42 = F_78 ( V_139 , V_22 , V_142 ,
V_146 , V_10 ) ;
if ( V_42 )
return V_42 ;
V_42 = F_79 ( V_142 , V_147 , & V_142 -> V_25 [ 0 ] ,
& V_139 -> V_25 [ V_22 ] , V_10 ) ;
if ( V_42 )
break;
F_40 ( & V_2 -> V_80 , L_17 ,
V_139 -> V_89 , V_10 ? '=' : '-' , V_142 -> V_89 ) ;
}
for ( V_18 = 0 ; V_18 < V_110 ; V_18 ++ ) {
if ( ! V_2 -> V_109 [ V_18 ] )
continue;
V_142 = & V_2 -> V_109 [ V_18 ] -> V_112 . V_27 ;
V_42 = F_78 ( V_139 , V_22 , V_142 ,
V_148 , 0 ) ;
if ( V_42 )
return V_42 ;
V_42 = F_79 ( V_142 , V_147 , & V_142 -> V_25 [ 0 ] ,
& V_139 -> V_25 [ V_22 ] , 0 ) ;
if ( V_42 )
break;
F_40 ( & V_2 -> V_80 , L_18 ,
V_139 -> V_89 , V_142 -> V_89 ) ;
}
return 0 ;
}
static int F_80 ( struct V_1 * V_2 )
{
struct V_15 * V_139 , * V_142 ;
int V_18 , V_42 = 0 ;
for ( V_18 = 0 ; V_18 < V_110 ; V_18 ++ ) {
struct V_109 * V_115 = V_2 -> V_109 [ V_18 ] ;
if ( V_115 == NULL )
continue;
V_139 = & V_115 -> V_112 . V_27 ;
V_142 = & V_115 -> V_137 . V_149 . V_27 ;
V_42 = F_78 ( V_139 , V_150 ,
V_142 , 0 , 0 ) ;
if ( V_42 )
break;
V_142 = & V_2 -> V_123 -> V_125 . V_112 . V_27 ;
V_42 = F_78 ( V_139 , V_151 ,
V_142 , 0 , 0 ) ;
if ( V_42 )
break;
}
return V_42 ;
}
static int F_81 ( struct V_1 * V_2 )
{
struct V_152 * V_125 = & V_2 -> V_123 -> V_125 ;
struct V_15 * V_139 , * V_142 ;
int V_18 , V_42 ;
V_139 = & V_125 -> V_112 . V_27 ;
for ( V_18 = 0 ; V_18 < V_117 ; V_18 ++ ) {
if ( V_2 -> V_115 [ V_18 ] == NULL )
continue;
V_142 = & V_2 -> V_115 [ V_18 ] -> V_118 . V_112 . V_27 ;
V_42 = F_78 ( V_139 , V_153 ,
V_142 , V_154 , 0 ) ;
if ( V_42 )
return V_42 ;
}
V_142 = & V_125 -> V_155 . V_137 . V_149 . V_27 ;
if ( V_142 -> V_23 == 0 )
return 0 ;
return F_78 ( V_139 , V_156 ,
V_142 , 0 , 0 ) ;
}
static int F_82 ( struct V_1 * V_2 )
{
struct V_3 * V_157 [ V_120 ] = { NULL } ;
struct V_3 * V_4 , * V_122 ;
struct V_6 * V_72 ;
struct V_15 * V_139 , * V_142 ;
int V_18 , V_22 , V_158 = 0 , V_42 = 0 ;
T_2 V_10 , V_140 = 0 ;
for ( V_18 = 0 ; V_18 < V_2 -> V_98 ; V_18 ++ ) {
if ( V_2 -> V_4 [ V_18 ] . V_112 == NULL )
continue;
V_4 = V_2 -> V_4 [ V_18 ] . V_112 ;
V_72 = F_2 ( V_4 ) ;
if ( ! V_72 )
continue;
V_139 = NULL ;
switch ( V_72 -> V_83 ) {
case V_88 :
if ( F_83 ( V_72 -> V_79 >= V_120 ,
L_19 , V_72 -> V_79 ) )
return - V_54 ;
V_122 = V_2 -> V_122 [ V_72 -> V_79 ] . V_17 ;
if ( F_83 ( V_122 == NULL ,
L_20 ) )
return - V_54 ;
V_22 = V_4 -> V_27 . V_23 - 1 ;
V_42 = F_78 ( & V_4 -> V_27 , V_22 ,
& V_122 -> V_27 , V_159 ,
V_160 |
V_145 ) ;
if ( V_42 )
return V_42 ;
F_40 ( & V_2 -> V_80 , L_21 ,
V_4 -> V_27 . V_89 , V_122 -> V_27 . V_89 ) ;
V_139 = NULL ;
V_157 [ V_72 -> V_79 ] = V_4 ;
break;
case V_84 ... V_85 :
V_139 = & V_4 -> V_27 ;
V_22 = 0 ;
break;
default:
F_43 ( & V_2 -> V_80 , L_22 ,
V_72 -> V_83 ) ;
return - V_54 ;
}
if ( V_139 == NULL )
continue;
V_140 = 1 << V_158 ++ ;
V_42 = F_77 ( V_2 , V_139 , V_4 ,
V_22 , V_140 ) ;
}
for ( V_18 = 0 ; V_18 < V_120 ; V_18 ++ ) {
if ( V_2 -> V_122 [ V_18 ] . V_17 == NULL )
continue;
V_139 = & V_2 -> V_122 [ V_18 ] . V_17 -> V_27 ;
V_22 = V_161 ;
V_4 = V_157 [ V_18 ] ;
V_140 = 1 << V_158 ++ ;
V_42 = F_77 ( V_2 , V_139 , V_4 ,
V_22 , V_140 ) ;
}
V_10 = V_160 | V_145 ;
for ( V_18 = 0 ; V_18 < V_117 ; V_18 ++ ) {
if ( ! V_2 -> V_115 [ V_18 ] )
continue;
V_139 = & V_2 -> V_115 [ V_18 ] -> V_118 . V_112 . V_27 ;
V_142 = & V_2 -> V_115 [ V_18 ] -> V_118 . V_137 . V_149 . V_27 ;
V_42 = F_78 ( V_139 , V_162 ,
V_142 , 0 , V_10 ) ;
if ( V_42 )
break;
}
V_42 = F_80 ( V_2 ) ;
if ( V_42 < 0 )
return V_42 ;
if ( V_2 -> V_163 )
V_42 = F_81 ( V_2 ) ;
return V_42 ;
}
static void F_84 ( struct V_1 * V_2 )
{
int V_18 = V_164 ;
while ( -- V_18 >= 0 ) {
if ( F_18 ( V_2 -> V_165 [ V_18 ] . clock ) )
continue;
F_85 ( V_2 -> V_165 [ V_18 ] . clock ) ;
V_2 -> V_165 [ V_18 ] . clock = F_86 ( - V_54 ) ;
}
for ( V_18 = 0 ; V_18 < V_166 ; V_18 ++ ) {
if ( F_18 ( V_2 -> V_51 [ V_18 ] ) )
continue;
F_85 ( V_2 -> V_51 [ V_18 ] ) ;
V_2 -> V_51 [ V_18 ] = F_86 ( - V_54 ) ;
}
}
static int F_87 ( struct V_1 * V_2 )
{
struct V_127 * V_101 = & V_2 -> V_100 -> V_101 ;
char V_167 [ 32 ] ;
struct V_168 * clock ;
int V_18 , V_42 = 0 ;
for ( V_18 = 0 ; V_18 < V_164 ; V_18 ++ )
V_2 -> V_165 [ V_18 ] . clock = F_86 ( - V_54 ) ;
for ( V_18 = 0 ; V_18 < V_164 ; V_18 ++ ) {
snprintf ( V_167 , sizeof( V_167 ) , L_23 , V_18 ) ;
clock = F_88 ( V_101 , V_167 ) ;
if ( F_18 ( clock ) ) {
F_70 ( V_101 , L_24 , V_167 ) ;
V_42 = F_89 ( clock ) ;
break;
}
V_2 -> V_165 [ V_18 ] . clock = clock ;
}
if ( V_42 )
F_84 ( V_2 ) ;
if ( ! V_2 -> V_163 )
return 0 ;
V_2 -> V_51 [ V_169 ] = F_86 ( - V_54 ) ;
for ( V_18 = V_52 ; V_18 < V_166 ; V_18 ++ ) {
snprintf ( V_167 , sizeof( V_167 ) , L_25 , V_18 ) ;
clock = F_88 ( V_101 , V_167 ) ;
if ( F_18 ( clock ) ) {
F_43 ( & V_2 -> V_80 , L_24 ,
V_167 ) ;
V_42 = F_89 ( clock ) ;
break;
}
V_2 -> V_51 [ V_18 ] = clock ;
}
if ( V_42 )
F_84 ( V_2 ) ;
return V_42 ;
}
static int F_90 ( struct V_15 * V_27 , bool V_170 )
{
struct V_171 * V_137 ;
struct V_13 * V_14 ;
struct V_172 * V_149 ;
int V_42 ;
V_149 = F_91 ( V_27 ) ;
if ( V_149 -> V_27 . V_41 == 0 )
return 0 ;
V_137 = F_92 ( V_149 ) ;
V_14 = F_17 ( V_137 -> V_138 ) ;
if ( ! V_170 && V_14 -> V_20 [ V_31 ] == NULL )
return 0 ;
if ( V_170 )
V_42 = F_21 ( V_137 -> V_138 , V_27 , true ) ;
else
V_42 = F_23 ( V_137 -> V_138 ) ;
if ( V_42 == 0 && ! V_170 )
memset ( V_14 -> V_20 , 0 , sizeof( V_14 -> V_20 ) ) ;
return V_42 ;
}
static int F_93 ( struct V_15 * V_27 , bool V_170 ,
struct V_173 * V_174 )
{
struct V_15 * V_175 = V_27 ;
int V_42 ;
F_94 ( V_174 , V_27 ) ;
while ( ( V_27 = F_95 ( V_174 ) ) ) {
if ( ! F_96 ( V_27 ) )
continue;
V_42 = F_90 ( V_27 , V_170 ) ;
if ( V_42 < 0 )
goto V_176;
}
return 0 ;
V_176:
F_94 ( V_174 , V_175 ) ;
while ( ( V_175 = F_95 ( V_174 ) ) ) {
if ( ! F_96 ( V_175 ) )
continue;
F_90 ( V_175 , ! V_170 ) ;
if ( V_175 == V_27 )
break;
}
return V_42 ;
}
static int F_97 ( struct V_177 * V_178 , unsigned int V_10 ,
unsigned int V_179 )
{
struct V_173 * V_174 =
& F_98 ( V_178 -> V_180 . V_181 , struct V_1 ,
V_182 ) -> V_183 ;
struct V_15 * V_142 = V_178 -> V_142 -> V_27 ;
int V_42 = 0 ;
if ( V_179 == V_184 ) {
V_42 = F_99 ( V_174 ,
V_178 -> V_180 . V_181 ) ;
if ( V_42 )
return V_42 ;
if ( ! ( V_10 & V_145 ) )
V_42 = F_93 ( V_142 , false , V_174 ) ;
#if 0
else
#endif
} else if ( V_179 == V_185 ) {
if ( V_178 -> V_10 & V_145 )
V_42 = F_93 ( V_142 , true , V_174 ) ;
F_100 ( V_174 ) ;
}
return V_42 ? - V_186 : 0 ;
}
static T_3 F_101 ( struct V_127 * V_101 ,
struct V_187 * V_188 , char * V_189 )
{
struct V_119 * V_100 = F_102 ( V_101 ) ;
struct V_1 * V_2 = F_103 ( V_100 ) ;
if ( V_2 -> V_58 )
return F_104 ( V_189 , L_26 , V_190 ) ;
return F_104 ( V_189 , L_27 , V_190 ) ;
}
static T_3 F_105 ( struct V_127 * V_101 ,
struct V_187 * V_188 ,
const char * V_189 , T_4 V_191 )
{
struct V_119 * V_100 = F_102 ( V_101 ) ;
struct V_1 * V_2 = F_103 ( V_100 ) ;
bool V_192 ;
int V_18 ;
if ( ! strcmp ( V_189 , L_28 ) )
V_192 = false ;
else if ( ! strcmp ( V_189 , L_29 ) )
V_192 = true ;
else
return V_191 ;
V_2 -> V_58 = V_192 ;
for ( V_18 = 0 ; V_18 < V_117 ; V_18 ++ )
if ( V_2 -> V_115 [ V_18 ] )
V_2 -> V_115 [ V_18 ] -> V_118 . V_58 = V_192 ;
return V_191 ;
}
static int F_106 ( struct V_1 * V_2 )
{
struct V_127 * V_101 = & V_2 -> V_100 -> V_101 ;
struct V_193 * V_194 = & V_2 -> V_195 ;
V_194 -> V_196 = F_107 ( V_101 ) ;
if ( F_18 ( V_194 -> V_196 ) )
return F_89 ( V_194 -> V_196 ) ;
V_194 -> V_197 = F_108 ( V_194 -> V_196 ,
V_198 ) ;
if ( F_18 ( V_194 -> V_197 ) )
return F_89 ( V_194 -> V_197 ) ;
V_194 -> V_199 = F_108 ( V_194 -> V_196 ,
V_200 ) ;
return 0 ;
}
static int F_109 ( struct V_201 * V_202 )
{
struct V_203 * V_165 = F_110 ( V_202 ) ;
int V_42 ;
if ( V_165 -> V_2 -> V_105 == NULL )
return - V_59 ;
V_42 = F_48 ( V_165 -> V_2 -> V_105 ) ;
return V_42 < 0 ? V_42 : 0 ;
}
static void F_111 ( struct V_201 * V_202 )
{
struct V_203 * V_165 = F_110 ( V_202 ) ;
if ( V_165 -> V_2 -> V_105 == NULL )
return;
F_112 ( V_165 -> V_2 -> V_105 ) ;
}
static void F_113 ( struct V_1 * V_2 )
{
struct V_204 * V_205 = & V_2 -> V_206 ;
unsigned int V_18 ;
if ( V_205 -> V_102 )
F_114 ( V_205 -> V_102 ) ;
for ( V_18 = 0 ; V_18 < V_205 -> V_207 ; V_18 ++ )
F_115 ( V_205 -> V_208 [ V_18 ] ) ;
}
static int F_116 ( struct V_1 * V_2 )
{
struct V_204 * V_205 = & V_2 -> V_206 ;
struct V_127 * V_101 = & V_2 -> V_100 -> V_101 ;
int V_18 , V_42 ;
for ( V_18 = 0 ; V_18 < V_164 ; V_18 ++ ) {
struct V_203 * V_165 = & V_205 -> V_165 [ V_18 ] ;
struct V_209 V_210 ;
const char * V_211 ;
V_42 = F_117 ( V_101 -> V_102 ,
L_30 , V_18 , & V_210 . V_89 ) ;
if ( V_42 < 0 )
break;
V_211 = F_118 ( V_2 -> V_165 [ V_18 ] . clock ) ;
V_210 . V_212 = & V_211 ;
V_210 . V_213 = 1 ;
V_210 . V_65 = & V_214 ;
V_210 . V_10 = V_215 ;
V_165 -> V_202 . V_210 = & V_210 ;
V_165 -> V_2 = V_2 ;
V_205 -> V_208 [ V_18 ] = F_119 ( NULL , & V_165 -> V_202 ) ;
if ( F_18 ( V_205 -> V_208 [ V_18 ] ) ) {
F_70 ( V_101 , L_31 ,
V_210 . V_89 , F_89 ( V_205 -> V_208 [ V_18 ] ) ) ;
V_42 = F_89 ( V_205 -> V_208 [ V_18 ] ) ;
goto V_176;
}
V_205 -> V_207 ++ ;
}
if ( V_205 -> V_207 == 0 ) {
F_120 ( V_101 , L_32 ) ;
return 0 ;
}
V_205 -> V_216 . V_208 = V_205 -> V_208 ;
V_205 -> V_216 . V_217 = V_205 -> V_207 ;
V_205 -> V_102 = V_101 -> V_102 ;
V_42 = F_121 ( V_101 -> V_102 , V_218 ,
& V_205 -> V_216 ) ;
if ( V_42 == 0 )
return 0 ;
V_176:
F_113 ( V_2 ) ;
return V_42 ;
}
static int F_122 ( struct V_219 * V_220 ,
struct V_3 * V_112 ,
struct V_221 * V_92 )
{
struct V_1 * V_2 = F_123 ( V_220 ) ;
struct V_8 * V_141 = NULL ;
int V_18 ;
for ( V_18 = 0 ; V_18 < F_46 ( V_2 -> V_4 ) ; V_18 ++ )
if ( V_2 -> V_4 [ V_18 ] . V_92 . V_95 . V_96 . V_96 ==
F_37 ( V_112 -> V_101 -> V_102 ) )
V_141 = & V_2 -> V_4 [ V_18 ] ;
if ( V_141 == NULL )
return - V_54 ;
F_56 ( V_112 , & V_141 -> V_72 ) ;
if ( V_141 -> V_72 . V_90 == V_91 )
V_112 -> V_28 = V_30 ;
else
V_112 -> V_28 = V_29 ;
V_141 -> V_112 = V_112 ;
F_40 ( & V_2 -> V_80 , L_33 ,
V_112 -> V_89 , V_2 -> V_98 ) ;
V_2 -> V_98 ++ ;
return 0 ;
}
static int F_124 ( struct V_219 * V_220 )
{
struct V_1 * V_2 = F_123 ( V_220 ) ;
int V_42 ;
F_125 ( & V_2 -> V_182 . V_222 ) ;
V_42 = F_82 ( V_2 ) ;
if ( V_42 < 0 )
goto V_223;
V_42 = F_126 ( & V_2 -> V_80 ) ;
V_223:
F_127 ( & V_2 -> V_182 . V_222 ) ;
if ( V_42 < 0 )
return V_42 ;
return F_128 ( & V_2 -> V_182 ) ;
}
static int F_129 ( struct V_119 * V_100 )
{
struct V_127 * V_101 = & V_100 -> V_101 ;
struct V_224 * V_80 ;
struct V_1 * V_2 ;
int V_42 ;
V_2 = F_130 ( V_101 , sizeof( * V_2 ) , V_62 ) ;
if ( ! V_2 )
return - V_113 ;
F_131 ( & V_2 -> V_11 ) ;
F_132 ( & V_2 -> V_64 ) ;
V_2 -> V_100 = V_100 ;
F_104 ( V_2 -> V_182 . V_225 , L_34 ,
sizeof( V_2 -> V_182 . V_225 ) ) ;
V_2 -> V_182 . V_65 = & V_226 ;
V_2 -> V_182 . V_101 = V_101 ;
V_80 = & V_2 -> V_80 ;
V_80 -> V_181 = & V_2 -> V_182 ;
V_80 -> V_227 = V_228 ;
F_104 ( V_80 -> V_89 , L_35 , sizeof( V_80 -> V_89 ) ) ;
V_2 -> V_163 = F_133 ( V_101 -> V_102 ) ;
V_2 -> V_58 = true ;
F_134 ( & V_2 -> V_182 ) ;
V_42 = F_135 ( V_101 , & V_2 -> V_80 ) ;
if ( V_42 < 0 ) {
F_43 ( V_80 , L_36 , V_42 ) ;
return V_42 ;
}
V_42 = F_87 ( V_2 ) ;
if ( V_42 )
goto V_229;
V_42 = F_106 ( V_2 ) ;
if ( V_42 < 0 ) {
if ( V_42 != V_128 )
F_70 ( V_101 , L_37 , V_42 ) ;
goto V_230;
}
F_136 ( V_100 , V_2 ) ;
V_42 = F_71 ( V_2 , V_101 -> V_102 ) ;
if ( V_42 )
goto V_230;
V_42 = F_47 ( V_2 ) ;
if ( V_42 )
goto V_231;
V_42 = F_137 ( & V_100 -> V_101 , & V_232 ) ;
if ( V_42 )
goto V_231;
V_42 = F_116 ( V_2 ) ;
if ( V_42 < 0 ) {
F_43 ( V_80 , L_38 ) ;
goto V_233;
}
if ( V_2 -> V_98 > 0 ) {
V_2 -> V_234 . V_20 = V_2 -> V_97 ;
V_2 -> V_234 . V_235 = V_2 -> V_98 ;
V_2 -> V_234 . V_236 = F_122 ;
V_2 -> V_234 . V_237 = F_124 ;
V_2 -> V_98 = 0 ;
V_42 = F_138 ( & V_2 -> V_80 ,
& V_2 -> V_234 ) ;
if ( V_42 )
goto V_238;
}
return 0 ;
V_238:
F_113 ( V_2 ) ;
V_233:
F_139 ( & V_100 -> V_101 , & V_232 ) ;
V_230:
F_84 ( V_2 ) ;
V_231:
F_75 ( V_2 ) ;
V_229:
F_140 ( & V_2 -> V_182 ) ;
F_141 ( & V_2 -> V_80 ) ;
return V_42 ;
}
static int F_142 ( struct V_119 * V_100 )
{
struct V_1 * V_2 = F_103 ( V_100 ) ;
if ( ! V_2 )
return 0 ;
F_113 ( V_2 ) ;
F_143 ( & V_2 -> V_234 ) ;
F_141 ( & V_2 -> V_80 ) ;
F_139 ( & V_100 -> V_101 , & V_232 ) ;
F_75 ( V_2 ) ;
F_28 ( V_2 ) ;
F_144 ( & V_2 -> V_182 ) ;
F_140 ( & V_2 -> V_182 ) ;
F_84 ( V_2 ) ;
return 0 ;
}
static int T_5 F_145 ( void )
{
int V_42 ;
F_146 ( L_39 ) ;
V_42 = F_147 () ;
if ( V_42 )
return V_42 ;
return F_148 ( & V_239 ) ;
}
static void T_6 F_149 ( void )
{
F_150 ( & V_239 ) ;
F_151 () ;
}
