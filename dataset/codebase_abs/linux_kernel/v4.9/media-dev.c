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
V_42 = F_36 ( V_50 , & V_76 ) ;
if ( V_42 ) {
F_37 ( V_50 ) ;
return V_42 ;
}
if ( F_3 ( V_76 . V_77 . V_69 == 0 ) || V_70 >= V_78 )
return - V_54 ;
V_71 -> V_79 = ( V_76 . V_77 . V_69 - 1 ) & 0x1 ;
V_73 = F_38 ( V_50 ) ;
F_37 ( V_50 ) ;
if ( V_73 == NULL ) {
F_39 ( & V_2 -> V_80 , L_2 ,
V_50 -> V_81 ) ;
return 0 ;
}
if ( F_40 ( V_76 . V_77 . V_69 ) ) {
if ( V_76 . V_82 == V_83 )
V_71 -> V_84 = V_85 ;
else
V_71 -> V_84 = V_86 ;
V_71 -> V_10 = V_76 . V_87 . V_88 . V_10 ;
} else if ( F_41 ( V_76 . V_77 . V_69 ) ) {
V_71 -> V_84 = V_89 ;
} else {
F_42 ( & V_2 -> V_80 , L_3 ,
V_76 . V_77 . V_69 , V_73 -> V_81 ) ;
}
V_74 = F_43 ( V_73 ) ;
if ( V_74 && ! F_44 ( V_74 -> V_90 , L_4 ) )
V_71 -> V_91 = V_92 ;
else
V_71 -> V_91 = V_71 -> V_84 ;
if ( F_3 ( V_70 >= F_45 ( V_2 -> V_4 ) ) ) {
F_37 ( V_73 ) ;
return - V_54 ;
}
V_2 -> V_4 [ V_70 ] . V_93 . V_94 = V_95 ;
V_2 -> V_4 [ V_70 ] . V_93 . V_96 . V_97 . V_98 = V_73 ;
V_2 -> V_99 [ V_70 ] = & V_2 -> V_4 [ V_70 ] . V_93 ;
V_2 -> V_100 ++ ;
F_37 ( V_73 ) ;
return 0 ;
}
static int F_46 ( struct V_1 * V_2 )
{
struct V_68 * V_101 = V_2 -> V_102 -> V_103 . V_104 ;
struct V_68 * V_98 , * V_105 ;
int V_70 = 0 ;
int V_42 ;
if ( ! V_2 -> V_106 )
return - V_43 ;
V_42 = F_47 ( V_2 -> V_106 ) ;
if ( V_42 < 0 )
return V_42 ;
V_2 -> V_100 = 0 ;
F_48 (parent, node) {
struct V_68 * V_69 ;
if ( F_44 ( V_98 -> V_90 , L_5 ) )
continue;
V_69 = F_35 ( V_98 , NULL ) ;
if ( ! V_69 )
continue;
V_42 = F_34 ( V_2 , V_69 , V_70 ) ;
if ( V_42 < 0 ) {
F_37 ( V_98 ) ;
goto V_107;
}
V_70 ++ ;
}
V_105 = F_49 ( V_101 , L_6 ) ;
if ( ! V_105 )
goto V_107;
F_50 (ports, node) {
V_42 = F_34 ( V_2 , V_98 , V_70 ) ;
if ( V_42 < 0 ) {
F_37 ( V_98 ) ;
break;
}
V_70 ++ ;
}
V_107:
F_51 ( V_2 -> V_106 ) ;
return V_42 ;
}
static int F_52 ( struct V_68 * V_74 )
{
T_2 V_108 = 0 ;
V_74 = F_49 ( V_74 , L_7 ) ;
if ( ! V_74 )
return - V_54 ;
F_53 ( V_74 , L_8 , & V_108 ) ;
return V_108 - V_109 ;
}
static int F_54 ( struct V_1 * V_2 ,
struct V_110 * V_110 )
{
struct V_3 * V_17 ;
struct V_49 * V_50 ;
int V_42 ;
if ( F_3 ( V_110 -> V_70 >= V_111 ||
V_2 -> V_110 [ V_110 -> V_70 ] ) )
return - V_112 ;
V_17 = & V_110 -> V_113 ;
V_17 -> V_28 = V_34 ;
V_50 = F_25 ( V_2 ) ;
if ( ! V_50 )
return - V_114 ;
F_55 ( V_17 , V_50 ) ;
V_42 = F_56 ( & V_2 -> V_80 , V_17 ) ;
if ( ! V_42 )
V_2 -> V_110 [ V_110 -> V_70 ] = V_110 ;
else
F_42 ( & V_2 -> V_80 , L_9 ,
V_110 -> V_70 ) ;
return V_42 ;
}
static int F_57 ( struct V_1 * V_2 , struct V_115 * V_116 )
{
struct V_3 * V_17 ;
struct V_49 * V_50 ;
int V_42 ;
if ( F_3 ( V_116 -> V_117 >= V_118 || V_2 -> V_116 [ V_116 -> V_117 ] ) )
return - V_112 ;
V_17 = & V_116 -> V_119 . V_113 ;
V_17 -> V_28 = V_36 ;
V_50 = F_25 ( V_2 ) ;
if ( ! V_50 )
return - V_114 ;
F_55 ( V_17 , V_50 ) ;
V_42 = F_56 ( & V_2 -> V_80 , V_17 ) ;
if ( ! V_42 ) {
if ( ! V_2 -> V_106 && V_116 -> V_102 )
V_2 -> V_106 = & V_116 -> V_102 -> V_103 ;
V_2 -> V_116 [ V_116 -> V_117 ] = V_116 ;
V_116 -> V_119 . V_58 = V_2 -> V_58 ;
} else {
F_42 ( & V_2 -> V_80 , L_10 ,
V_116 -> V_117 , V_42 ) ;
}
return V_42 ;
}
static int F_58 ( struct V_1 * V_2 ,
struct V_120 * V_102 ,
struct V_3 * V_17 )
{
struct V_68 * V_98 = V_102 -> V_103 . V_104 ;
int V_117 , V_42 ;
V_117 = V_98 ? F_52 ( V_98 ) : F_59 ( 0 , V_102 -> V_117 ) ;
if ( F_3 ( V_117 < 0 || V_117 >= V_121 ) )
return - V_122 ;
if ( F_3 ( V_2 -> V_123 [ V_117 ] . V_17 ) )
return - V_112 ;
V_17 -> V_28 = V_32 ;
V_42 = F_56 ( & V_2 -> V_80 , V_17 ) ;
if ( ! V_42 )
V_2 -> V_123 [ V_117 ] . V_17 = V_17 ;
else
F_42 ( & V_2 -> V_80 ,
L_11 , V_117 , V_42 ) ;
return V_42 ;
}
static int F_60 ( struct V_1 * V_2 , struct V_124 * V_125 )
{
struct V_3 * V_17 = & V_125 -> V_126 . V_113 ;
struct V_49 * V_50 ;
int V_42 ;
V_50 = F_25 ( V_2 ) ;
if ( ! V_50 )
return - V_114 ;
F_55 ( V_17 , V_50 ) ;
V_42 = F_56 ( & V_2 -> V_80 , V_17 ) ;
if ( V_42 ) {
F_42 ( & V_2 -> V_80 ,
L_12 , V_42 ) ;
return V_42 ;
}
V_2 -> V_124 = V_125 ;
return 0 ;
}
static int F_61 ( struct V_1 * V_2 ,
struct V_120 * V_102 ,
int V_127 )
{
struct V_128 * V_103 = & V_102 -> V_103 ;
int V_42 = - V_129 ;
void * V_130 ;
F_62 ( V_103 ) ;
if ( ! V_103 -> V_131 || ! F_63 ( V_103 -> V_131 -> V_132 ) )
goto V_133;
V_130 = F_64 ( V_103 ) ;
if ( V_130 ) {
switch ( V_127 ) {
case V_37 :
V_42 = F_57 ( V_2 , V_130 ) ;
break;
case V_35 :
V_42 = F_54 ( V_2 , V_130 ) ;
break;
case V_33 :
V_42 = F_58 ( V_2 , V_102 , V_130 ) ;
break;
case V_39 :
V_42 = F_60 ( V_2 , V_130 ) ;
break;
default:
V_42 = - V_59 ;
}
}
F_65 ( V_103 -> V_131 -> V_132 ) ;
V_133:
F_66 ( V_103 ) ;
if ( V_42 == - V_129 )
F_67 ( & V_2 -> V_102 -> V_103 , L_13 ,
F_68 ( V_103 ) ) ;
else if ( V_42 < 0 )
F_69 ( & V_2 -> V_102 -> V_103 , L_14 ,
F_68 ( V_103 ) , V_42 ) ;
return V_42 ;
}
static int F_70 ( struct V_1 * V_2 ,
struct V_68 * V_101 )
{
struct V_68 * V_98 ;
int V_42 = 0 ;
F_48 (parent, node) {
struct V_120 * V_102 ;
int V_127 = - 1 ;
V_102 = F_71 ( V_98 ) ;
if ( ! V_102 )
continue;
if ( ! strcmp ( V_98 -> V_90 , V_134 ) )
V_127 = V_33 ;
else if ( ! strcmp ( V_98 -> V_90 , V_135 ) )
V_127 = V_39 ;
else if ( ! strcmp ( V_98 -> V_90 , V_136 ) )
V_127 = V_35 ;
else if ( ! strcmp ( V_98 -> V_90 , V_137 ) &&
! F_72 ( V_98 , L_15 ) )
V_127 = V_37 ;
if ( V_127 >= 0 )
V_42 = F_61 ( V_2 , V_102 ,
V_127 ) ;
F_73 ( & V_102 -> V_103 ) ;
if ( V_42 < 0 ) {
F_37 ( V_98 ) ;
break;
}
}
return V_42 ;
}
static void F_74 ( struct V_1 * V_2 )
{
int V_18 ;
for ( V_18 = 0 ; V_18 < V_118 ; V_18 ++ ) {
struct V_115 * V_103 = V_2 -> V_116 [ V_18 ] ;
if ( V_103 == NULL )
continue;
F_75 ( & V_103 -> V_119 . V_113 ) ;
V_103 -> V_119 . V_138 . V_139 = NULL ;
V_2 -> V_116 [ V_18 ] = NULL ;
}
for ( V_18 = 0 ; V_18 < V_111 ; V_18 ++ ) {
struct V_110 * V_103 = V_2 -> V_110 [ V_18 ] ;
if ( V_103 == NULL )
continue;
F_75 ( & V_103 -> V_113 ) ;
V_103 -> V_138 . V_139 = NULL ;
V_2 -> V_110 [ V_18 ] = NULL ;
}
for ( V_18 = 0 ; V_18 < V_121 ; V_18 ++ ) {
if ( V_2 -> V_123 [ V_18 ] . V_17 == NULL )
continue;
F_75 ( V_2 -> V_123 [ V_18 ] . V_17 ) ;
V_2 -> V_123 [ V_18 ] . V_17 = NULL ;
}
if ( V_2 -> V_124 )
F_75 ( & V_2 -> V_124 -> V_126 . V_113 ) ;
F_39 ( & V_2 -> V_80 , L_16 ) ;
}
static int F_76 ( struct V_1 * V_2 ,
struct V_15 * V_140 ,
struct V_3 * V_4 ,
int V_22 , int V_141 )
{
struct V_6 * V_142 = NULL ;
struct V_15 * V_143 ;
unsigned int V_10 = 0 ;
int V_18 , V_42 = 0 ;
if ( V_4 ) {
V_142 = F_2 ( V_4 ) ;
if ( V_142 && V_142 -> V_91 == V_92 )
V_42 = 1 ;
}
for ( V_18 = 0 ; ! V_42 && V_18 < V_118 ; V_18 ++ ) {
if ( ! V_2 -> V_116 [ V_18 ] )
continue;
if ( ! V_2 -> V_116 [ V_18 ] -> V_144 -> V_145 )
continue;
V_10 = ( ( 1 << V_18 ) & V_141 ) ? V_146 : 0 ;
V_143 = & V_2 -> V_116 [ V_18 ] -> V_119 . V_113 . V_27 ;
V_42 = F_77 ( V_140 , V_22 , V_143 ,
V_147 , V_10 ) ;
if ( V_42 )
return V_42 ;
V_42 = F_78 ( V_143 , V_148 , & V_143 -> V_25 [ 0 ] ,
& V_140 -> V_25 [ V_22 ] , V_10 ) ;
if ( V_42 )
break;
F_39 ( & V_2 -> V_80 , L_17 ,
V_140 -> V_90 , V_10 ? '=' : '-' , V_143 -> V_90 ) ;
}
for ( V_18 = 0 ; V_18 < V_111 ; V_18 ++ ) {
if ( ! V_2 -> V_110 [ V_18 ] )
continue;
V_143 = & V_2 -> V_110 [ V_18 ] -> V_113 . V_27 ;
V_42 = F_77 ( V_140 , V_22 , V_143 ,
V_149 , 0 ) ;
if ( V_42 )
return V_42 ;
V_42 = F_78 ( V_143 , V_148 , & V_143 -> V_25 [ 0 ] ,
& V_140 -> V_25 [ V_22 ] , 0 ) ;
if ( V_42 )
break;
F_39 ( & V_2 -> V_80 , L_18 ,
V_140 -> V_90 , V_143 -> V_90 ) ;
}
return 0 ;
}
static int F_79 ( struct V_1 * V_2 )
{
struct V_15 * V_140 , * V_143 ;
int V_18 , V_42 = 0 ;
for ( V_18 = 0 ; V_18 < V_111 ; V_18 ++ ) {
struct V_110 * V_116 = V_2 -> V_110 [ V_18 ] ;
if ( V_116 == NULL )
continue;
V_140 = & V_116 -> V_113 . V_27 ;
V_143 = & V_116 -> V_138 . V_150 . V_27 ;
V_42 = F_77 ( V_140 , V_151 ,
V_143 , 0 , 0 ) ;
if ( V_42 )
break;
V_143 = & V_2 -> V_124 -> V_126 . V_113 . V_27 ;
V_42 = F_77 ( V_140 , V_152 ,
V_143 , 0 , 0 ) ;
if ( V_42 )
break;
}
return V_42 ;
}
static int F_80 ( struct V_1 * V_2 )
{
struct V_153 * V_126 = & V_2 -> V_124 -> V_126 ;
struct V_15 * V_140 , * V_143 ;
int V_18 , V_42 ;
V_140 = & V_126 -> V_113 . V_27 ;
for ( V_18 = 0 ; V_18 < V_118 ; V_18 ++ ) {
if ( V_2 -> V_116 [ V_18 ] == NULL )
continue;
V_143 = & V_2 -> V_116 [ V_18 ] -> V_119 . V_113 . V_27 ;
V_42 = F_77 ( V_140 , V_154 ,
V_143 , V_155 , 0 ) ;
if ( V_42 )
return V_42 ;
}
V_143 = & V_126 -> V_156 . V_138 . V_150 . V_27 ;
if ( V_143 -> V_23 == 0 )
return 0 ;
return F_77 ( V_140 , V_157 ,
V_143 , 0 , 0 ) ;
}
static int F_81 ( struct V_1 * V_2 )
{
struct V_3 * V_158 [ V_121 ] = { NULL } ;
struct V_3 * V_4 , * V_123 ;
struct V_6 * V_72 ;
struct V_15 * V_140 , * V_143 ;
int V_18 , V_22 , V_159 = 0 , V_42 = 0 ;
T_2 V_10 , V_141 = 0 ;
for ( V_18 = 0 ; V_18 < V_2 -> V_100 ; V_18 ++ ) {
if ( V_2 -> V_4 [ V_18 ] . V_113 == NULL )
continue;
V_4 = V_2 -> V_4 [ V_18 ] . V_113 ;
V_72 = F_2 ( V_4 ) ;
if ( ! V_72 )
continue;
V_140 = NULL ;
switch ( V_72 -> V_84 ) {
case V_89 :
if ( F_82 ( V_72 -> V_79 >= V_121 ,
L_19 , V_72 -> V_79 ) )
return - V_54 ;
V_123 = V_2 -> V_123 [ V_72 -> V_79 ] . V_17 ;
if ( F_82 ( V_123 == NULL ,
L_20
L_21 ) )
return - V_54 ;
V_22 = V_4 -> V_27 . V_23 - 1 ;
V_42 = F_77 ( & V_4 -> V_27 , V_22 ,
& V_123 -> V_27 , V_160 ,
V_161 |
V_146 ) ;
if ( V_42 )
return V_42 ;
F_39 ( & V_2 -> V_80 , L_22 ,
V_4 -> V_27 . V_90 , V_123 -> V_27 . V_90 ) ;
V_140 = NULL ;
V_158 [ V_72 -> V_79 ] = V_4 ;
break;
case V_85 ... V_86 :
V_140 = & V_4 -> V_27 ;
V_22 = 0 ;
break;
default:
F_42 ( & V_2 -> V_80 , L_23 ,
V_72 -> V_84 ) ;
return - V_54 ;
}
if ( V_140 == NULL )
continue;
V_141 = 1 << V_159 ++ ;
V_42 = F_76 ( V_2 , V_140 , V_4 ,
V_22 , V_141 ) ;
}
for ( V_18 = 0 ; V_18 < V_121 ; V_18 ++ ) {
if ( V_2 -> V_123 [ V_18 ] . V_17 == NULL )
continue;
V_140 = & V_2 -> V_123 [ V_18 ] . V_17 -> V_27 ;
V_22 = V_162 ;
V_4 = V_158 [ V_18 ] ;
V_141 = 1 << V_159 ++ ;
V_42 = F_76 ( V_2 , V_140 , V_4 ,
V_22 , V_141 ) ;
}
V_10 = V_161 | V_146 ;
for ( V_18 = 0 ; V_18 < V_118 ; V_18 ++ ) {
if ( ! V_2 -> V_116 [ V_18 ] )
continue;
V_140 = & V_2 -> V_116 [ V_18 ] -> V_119 . V_113 . V_27 ;
V_143 = & V_2 -> V_116 [ V_18 ] -> V_119 . V_138 . V_150 . V_27 ;
V_42 = F_77 ( V_140 , V_163 ,
V_143 , 0 , V_10 ) ;
if ( V_42 )
break;
}
V_42 = F_79 ( V_2 ) ;
if ( V_42 < 0 )
return V_42 ;
if ( V_2 -> V_164 )
V_42 = F_80 ( V_2 ) ;
return V_42 ;
}
static void F_83 ( struct V_1 * V_2 )
{
int V_18 = V_165 ;
while ( -- V_18 >= 0 ) {
if ( F_18 ( V_2 -> V_166 [ V_18 ] . clock ) )
continue;
F_84 ( V_2 -> V_166 [ V_18 ] . clock ) ;
V_2 -> V_166 [ V_18 ] . clock = F_85 ( - V_54 ) ;
}
for ( V_18 = 0 ; V_18 < V_167 ; V_18 ++ ) {
if ( F_18 ( V_2 -> V_51 [ V_18 ] ) )
continue;
F_84 ( V_2 -> V_51 [ V_18 ] ) ;
V_2 -> V_51 [ V_18 ] = F_85 ( - V_54 ) ;
}
}
static int F_86 ( struct V_1 * V_2 )
{
struct V_128 * V_103 = & V_2 -> V_102 -> V_103 ;
char V_168 [ 32 ] ;
struct V_169 * clock ;
int V_18 , V_42 = 0 ;
for ( V_18 = 0 ; V_18 < V_165 ; V_18 ++ )
V_2 -> V_166 [ V_18 ] . clock = F_85 ( - V_54 ) ;
for ( V_18 = 0 ; V_18 < V_165 ; V_18 ++ ) {
snprintf ( V_168 , sizeof( V_168 ) , L_24 , V_18 ) ;
clock = F_87 ( V_103 , V_168 ) ;
if ( F_18 ( clock ) ) {
F_69 ( V_103 , L_25 , V_168 ) ;
V_42 = F_88 ( clock ) ;
break;
}
V_2 -> V_166 [ V_18 ] . clock = clock ;
}
if ( V_42 )
F_83 ( V_2 ) ;
if ( ! V_2 -> V_164 )
return 0 ;
V_2 -> V_51 [ V_170 ] = F_85 ( - V_54 ) ;
for ( V_18 = V_52 ; V_18 < V_167 ; V_18 ++ ) {
snprintf ( V_168 , sizeof( V_168 ) , L_26 , V_18 ) ;
clock = F_87 ( V_103 , V_168 ) ;
if ( F_18 ( clock ) ) {
F_42 ( & V_2 -> V_80 , L_25 ,
V_168 ) ;
V_42 = F_88 ( clock ) ;
break;
}
V_2 -> V_51 [ V_18 ] = clock ;
}
if ( V_42 )
F_83 ( V_2 ) ;
return V_42 ;
}
static int F_89 ( struct V_15 * V_27 , bool V_171 )
{
struct V_172 * V_138 ;
struct V_13 * V_14 ;
struct V_173 * V_150 ;
int V_42 ;
V_150 = F_90 ( V_27 ) ;
if ( V_150 -> V_27 . V_41 == 0 )
return 0 ;
V_138 = F_91 ( V_150 ) ;
V_14 = F_17 ( V_138 -> V_139 ) ;
if ( ! V_171 && V_14 -> V_20 [ V_31 ] == NULL )
return 0 ;
if ( V_171 )
V_42 = F_21 ( V_138 -> V_139 , V_27 , true ) ;
else
V_42 = F_23 ( V_138 -> V_139 ) ;
if ( V_42 == 0 && ! V_171 )
memset ( V_14 -> V_20 , 0 , sizeof( V_14 -> V_20 ) ) ;
return V_42 ;
}
static int F_92 ( struct V_15 * V_27 , bool V_171 ,
struct V_174 * V_175 )
{
struct V_15 * V_176 = V_27 ;
int V_42 ;
F_93 ( V_175 , V_27 ) ;
while ( ( V_27 = F_94 ( V_175 ) ) ) {
if ( ! F_95 ( V_27 ) )
continue;
V_42 = F_89 ( V_27 , V_171 ) ;
if ( V_42 < 0 )
goto V_177;
}
return 0 ;
V_177:
F_93 ( V_175 , V_176 ) ;
while ( ( V_176 = F_94 ( V_175 ) ) ) {
if ( ! F_95 ( V_176 ) )
continue;
F_89 ( V_176 , ! V_171 ) ;
if ( V_176 == V_27 )
break;
}
return V_42 ;
}
static int F_96 ( struct V_178 * V_179 , unsigned int V_10 ,
unsigned int V_180 )
{
struct V_174 * V_175 =
& F_97 ( V_179 -> V_181 . V_182 , struct V_1 ,
V_183 ) -> V_184 ;
struct V_15 * V_143 = V_179 -> V_143 -> V_27 ;
int V_42 = 0 ;
if ( V_180 == V_185 ) {
V_42 = F_98 ( V_175 ,
V_179 -> V_181 . V_182 ) ;
if ( V_42 )
return V_42 ;
if ( ! ( V_10 & V_146 ) )
V_42 = F_92 ( V_143 , false , V_175 ) ;
#if 0
else
#endif
} else if ( V_180 == V_186 ) {
if ( V_179 -> V_10 & V_146 )
V_42 = F_92 ( V_143 , true , V_175 ) ;
F_99 ( V_175 ) ;
}
return V_42 ? - V_187 : 0 ;
}
static T_3 F_100 ( struct V_128 * V_103 ,
struct V_188 * V_189 , char * V_190 )
{
struct V_120 * V_102 = F_101 ( V_103 ) ;
struct V_1 * V_2 = F_102 ( V_102 ) ;
if ( V_2 -> V_58 )
return F_103 ( V_190 , L_27 , V_191 ) ;
return F_103 ( V_190 , L_28 , V_191 ) ;
}
static T_3 F_104 ( struct V_128 * V_103 ,
struct V_188 * V_189 ,
const char * V_190 , T_4 V_192 )
{
struct V_120 * V_102 = F_101 ( V_103 ) ;
struct V_1 * V_2 = F_102 ( V_102 ) ;
bool V_193 ;
int V_18 ;
if ( ! strcmp ( V_190 , L_29 ) )
V_193 = false ;
else if ( ! strcmp ( V_190 , L_30 ) )
V_193 = true ;
else
return V_192 ;
V_2 -> V_58 = V_193 ;
for ( V_18 = 0 ; V_18 < V_118 ; V_18 ++ )
if ( V_2 -> V_116 [ V_18 ] )
V_2 -> V_116 [ V_18 ] -> V_119 . V_58 = V_193 ;
return V_192 ;
}
static int F_105 ( struct V_1 * V_2 )
{
struct V_128 * V_103 = & V_2 -> V_102 -> V_103 ;
struct V_194 * V_195 = & V_2 -> V_196 ;
V_195 -> V_197 = F_106 ( V_103 ) ;
if ( F_18 ( V_195 -> V_197 ) )
return F_88 ( V_195 -> V_197 ) ;
V_195 -> V_198 = F_107 ( V_195 -> V_197 ,
V_199 ) ;
if ( F_18 ( V_195 -> V_198 ) )
return F_88 ( V_195 -> V_198 ) ;
V_195 -> V_200 = F_107 ( V_195 -> V_197 ,
V_201 ) ;
return 0 ;
}
static int F_108 ( struct V_202 * V_203 )
{
struct V_204 * V_166 = F_109 ( V_203 ) ;
int V_42 ;
if ( V_166 -> V_2 -> V_106 == NULL )
return - V_59 ;
V_42 = F_47 ( V_166 -> V_2 -> V_106 ) ;
return V_42 < 0 ? V_42 : 0 ;
}
static void F_110 ( struct V_202 * V_203 )
{
struct V_204 * V_166 = F_109 ( V_203 ) ;
if ( V_166 -> V_2 -> V_106 == NULL )
return;
F_111 ( V_166 -> V_2 -> V_106 ) ;
}
static void F_112 ( struct V_1 * V_2 )
{
struct V_205 * V_206 = & V_2 -> V_207 ;
unsigned int V_18 ;
if ( V_206 -> V_104 )
F_113 ( V_206 -> V_104 ) ;
for ( V_18 = 0 ; V_18 < V_206 -> V_208 ; V_18 ++ )
F_114 ( V_206 -> V_209 [ V_18 ] ) ;
}
static int F_115 ( struct V_1 * V_2 )
{
struct V_205 * V_206 = & V_2 -> V_207 ;
struct V_128 * V_103 = & V_2 -> V_102 -> V_103 ;
int V_18 , V_42 ;
for ( V_18 = 0 ; V_18 < V_165 ; V_18 ++ ) {
struct V_204 * V_166 = & V_206 -> V_166 [ V_18 ] ;
struct V_210 V_211 ;
const char * V_212 ;
V_42 = F_116 ( V_103 -> V_104 ,
L_31 , V_18 , & V_211 . V_90 ) ;
if ( V_42 < 0 )
break;
V_212 = F_117 ( V_2 -> V_166 [ V_18 ] . clock ) ;
V_211 . V_213 = & V_212 ;
V_211 . V_214 = 1 ;
V_211 . V_65 = & V_215 ;
V_211 . V_10 = V_216 ;
V_166 -> V_203 . V_211 = & V_211 ;
V_166 -> V_2 = V_2 ;
V_206 -> V_209 [ V_18 ] = F_118 ( NULL , & V_166 -> V_203 ) ;
if ( F_18 ( V_206 -> V_209 [ V_18 ] ) ) {
F_69 ( V_103 , L_32 ,
V_211 . V_90 , F_88 ( V_206 -> V_209 [ V_18 ] ) ) ;
V_42 = F_88 ( V_206 -> V_209 [ V_18 ] ) ;
goto V_177;
}
V_206 -> V_208 ++ ;
}
if ( V_206 -> V_208 == 0 ) {
F_119 ( V_103 , L_33 ) ;
return 0 ;
}
V_206 -> V_217 . V_209 = V_206 -> V_209 ;
V_206 -> V_217 . V_218 = V_206 -> V_208 ;
V_206 -> V_104 = V_103 -> V_104 ;
V_42 = F_120 ( V_103 -> V_104 , V_219 ,
& V_206 -> V_217 ) ;
if ( V_42 == 0 )
return 0 ;
V_177:
F_112 ( V_2 ) ;
return V_42 ;
}
static int F_121 ( struct V_220 * V_221 ,
struct V_3 * V_113 ,
struct V_222 * V_93 )
{
struct V_1 * V_2 = F_122 ( V_221 ) ;
struct V_8 * V_142 = NULL ;
int V_18 ;
for ( V_18 = 0 ; V_18 < F_45 ( V_2 -> V_4 ) ; V_18 ++ )
if ( V_2 -> V_4 [ V_18 ] . V_93 . V_96 . V_97 . V_98 == V_113 -> V_103 -> V_104 )
V_142 = & V_2 -> V_4 [ V_18 ] ;
if ( V_142 == NULL )
return - V_54 ;
F_55 ( V_113 , & V_142 -> V_72 ) ;
if ( V_142 -> V_72 . V_91 == V_92 )
V_113 -> V_28 = V_30 ;
else
V_113 -> V_28 = V_29 ;
V_142 -> V_113 = V_113 ;
F_39 ( & V_2 -> V_80 , L_34 ,
V_113 -> V_90 , V_2 -> V_100 ) ;
V_2 -> V_100 ++ ;
return 0 ;
}
static int F_123 ( struct V_220 * V_221 )
{
struct V_1 * V_2 = F_122 ( V_221 ) ;
int V_42 ;
F_124 ( & V_2 -> V_183 . V_223 ) ;
V_42 = F_81 ( V_2 ) ;
if ( V_42 < 0 )
goto V_224;
V_42 = F_125 ( & V_2 -> V_80 ) ;
V_224:
F_126 ( & V_2 -> V_183 . V_223 ) ;
if ( V_42 < 0 )
return V_42 ;
return F_127 ( & V_2 -> V_183 ) ;
}
static int F_128 ( struct V_120 * V_102 )
{
struct V_128 * V_103 = & V_102 -> V_103 ;
struct V_225 * V_80 ;
struct V_1 * V_2 ;
int V_42 ;
V_2 = F_129 ( V_103 , sizeof( * V_2 ) , V_62 ) ;
if ( ! V_2 )
return - V_114 ;
F_130 ( & V_2 -> V_11 ) ;
F_131 ( & V_2 -> V_64 ) ;
V_2 -> V_102 = V_102 ;
F_103 ( V_2 -> V_183 . V_226 , L_35 ,
sizeof( V_2 -> V_183 . V_226 ) ) ;
V_2 -> V_183 . V_65 = & V_227 ;
V_2 -> V_183 . V_103 = V_103 ;
V_80 = & V_2 -> V_80 ;
V_80 -> V_182 = & V_2 -> V_183 ;
V_80 -> V_228 = V_229 ;
F_103 ( V_80 -> V_90 , L_36 , sizeof( V_80 -> V_90 ) ) ;
V_2 -> V_164 = F_132 ( V_103 -> V_104 ) ;
V_2 -> V_58 = true ;
F_133 ( & V_2 -> V_183 ) ;
V_42 = F_134 ( V_103 , & V_2 -> V_80 ) ;
if ( V_42 < 0 ) {
F_42 ( V_80 , L_37 , V_42 ) ;
return V_42 ;
}
V_42 = F_86 ( V_2 ) ;
if ( V_42 )
goto V_230;
V_42 = F_105 ( V_2 ) ;
if ( V_42 < 0 ) {
if ( V_42 != V_129 )
F_69 ( V_103 , L_38 , V_42 ) ;
goto V_231;
}
F_135 ( V_102 , V_2 ) ;
V_42 = F_70 ( V_2 , V_103 -> V_104 ) ;
if ( V_42 )
goto V_231;
V_42 = F_46 ( V_2 ) ;
if ( V_42 )
goto V_232;
V_42 = F_136 ( & V_102 -> V_103 , & V_233 ) ;
if ( V_42 )
goto V_232;
V_42 = F_115 ( V_2 ) ;
if ( V_42 < 0 ) {
F_42 ( V_80 , L_39 ) ;
goto V_234;
}
if ( V_2 -> V_100 > 0 ) {
V_2 -> V_235 . V_20 = V_2 -> V_99 ;
V_2 -> V_235 . V_236 = V_2 -> V_100 ;
V_2 -> V_235 . V_237 = F_121 ;
V_2 -> V_235 . V_238 = F_123 ;
V_2 -> V_100 = 0 ;
V_42 = F_137 ( & V_2 -> V_80 ,
& V_2 -> V_235 ) ;
if ( V_42 )
goto V_239;
}
return 0 ;
V_239:
F_112 ( V_2 ) ;
V_234:
F_138 ( & V_102 -> V_103 , & V_233 ) ;
V_231:
F_83 ( V_2 ) ;
V_232:
F_74 ( V_2 ) ;
V_230:
F_139 ( & V_2 -> V_183 ) ;
F_140 ( & V_2 -> V_80 ) ;
return V_42 ;
}
static int F_141 ( struct V_120 * V_102 )
{
struct V_1 * V_2 = F_102 ( V_102 ) ;
if ( ! V_2 )
return 0 ;
F_112 ( V_2 ) ;
F_142 ( & V_2 -> V_235 ) ;
F_140 ( & V_2 -> V_80 ) ;
F_138 ( & V_102 -> V_103 , & V_233 ) ;
F_74 ( V_2 ) ;
F_28 ( V_2 ) ;
F_143 ( & V_2 -> V_183 ) ;
F_139 ( & V_2 -> V_183 ) ;
F_83 ( V_2 ) ;
return 0 ;
}
static int T_5 F_144 ( void )
{
int V_42 ;
F_145 ( L_40 ) ;
V_42 = F_146 () ;
if ( V_42 )
return V_42 ;
return F_147 ( & V_240 ) ;
}
static void T_6 F_148 ( void )
{
F_149 ( & V_240 ) ;
F_150 () ;
}
