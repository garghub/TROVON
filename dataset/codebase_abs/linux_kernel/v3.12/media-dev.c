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
if ( ! V_78 )
return;
F_44 ( V_17 ) ;
if ( ! V_78 -> V_79 . V_80 ) {
V_69 = V_78 -> V_69 ;
F_45 ( V_78 ) ;
if ( V_69 )
F_40 ( V_69 ) ;
}
}
static int F_46 ( struct V_1 * V_2 ,
struct V_81 * V_82 , int V_83 )
{
struct V_8 * V_67 ;
struct V_77 * V_78 ;
struct V_3 * V_17 ;
int V_43 ;
if ( F_3 ( V_83 >= F_47 ( V_2 -> V_4 ) ) )
return - V_53 ;
V_67 = & V_2 -> V_4 [ V_83 ] ;
V_78 = F_48 ( V_82 ) ;
if ( ! V_78 )
return - V_74 ;
F_49 ( & V_78 -> V_79 ) ;
if ( ! V_78 -> V_84 ||
! F_50 ( V_78 -> V_84 -> V_84 . V_85 ) ) {
V_43 = - V_74 ;
F_42 ( & V_2 -> V_73 , L_5 ,
V_82 -> V_86 ) ;
goto V_87;
}
V_43 = F_51 ( V_2 , & V_67 -> V_88 , true ) ;
if ( V_43 < 0 )
goto V_89;
V_17 = F_52 ( V_78 ) ;
V_43 = F_53 ( & V_2 -> V_73 , V_17 ) ;
F_51 ( V_2 , & V_67 -> V_88 , false ) ;
if ( V_43 < 0 )
goto V_89;
F_41 ( V_17 , & V_67 -> V_88 ) ;
if ( V_67 -> V_88 . V_70 == V_90 )
V_17 -> V_29 = V_31 ;
else
V_17 -> V_29 = V_30 ;
V_67 -> V_91 = V_17 ;
F_42 ( & V_2 -> V_73 , L_6 ,
V_17 -> V_76 , V_2 -> V_92 ) ;
V_2 -> V_92 ++ ;
V_89:
F_54 ( V_78 -> V_84 -> V_84 . V_85 ) ;
V_87:
F_55 ( & V_78 -> V_79 ) ;
F_56 ( & V_78 -> V_79 ) ;
return V_43 ;
}
static int F_57 ( struct V_1 * V_2 ,
struct V_81 * V_93 ,
unsigned int V_83 )
{
struct V_81 * V_94 , * V_51 , * V_95 ;
struct V_6 * V_96 ;
struct V_97 V_98 ;
int V_43 ;
T_2 V_99 ;
V_96 = & V_2 -> V_4 [ V_83 ] . V_88 ;
V_51 = F_58 ( V_93 , NULL ) ;
if ( ! V_51 )
return 0 ;
F_59 ( V_51 , & V_98 ) ;
if ( F_3 ( V_98 . V_93 == 0 ) || V_83 >= V_100 )
return - V_53 ;
V_96 -> V_101 = ( V_98 . V_93 - 1 ) & 0x1 ;
V_94 = F_60 ( V_51 ) ;
F_61 ( V_51 ) ;
if ( V_94 == NULL ) {
F_42 ( & V_2 -> V_73 , L_7 ,
V_51 -> V_86 ) ;
return 0 ;
}
if ( ! F_62 ( V_94 , L_8 , & V_99 ) )
V_96 -> V_102 = V_99 ;
if ( ! F_62 ( V_94 , L_9 , & V_99 ) )
V_96 -> V_103 = V_99 ;
if ( V_96 -> V_103 == 0 ) {
F_63 ( & V_2 -> V_73 , L_10 ,
V_94 -> V_86 ) ;
F_61 ( V_94 ) ;
return - V_53 ;
}
if ( F_64 ( V_98 . V_93 ) ) {
if ( V_98 . V_104 == V_105 )
V_96 -> V_71 = V_106 ;
else
V_96 -> V_71 = V_107 ;
V_96 -> V_10 = V_98 . V_108 . V_109 . V_10 ;
} else if ( F_65 ( V_98 . V_93 ) ) {
V_96 -> V_71 = V_110 ;
} else {
F_63 ( & V_2 -> V_73 , L_11 ,
V_98 . V_93 , V_94 -> V_86 ) ;
}
V_95 = F_66 ( V_94 ) ;
if ( V_95 && ! F_67 ( V_95 -> V_76 , L_12 ) )
V_96 -> V_70 = V_90 ;
else
V_96 -> V_70 = V_96 -> V_71 ;
V_43 = F_46 ( V_2 , V_94 , V_83 ) ;
F_61 ( V_94 ) ;
return V_43 ;
}
static int F_68 ( struct V_1 * V_2 ,
struct V_81 * V_95 )
{
struct V_81 * V_111 = V_2 -> V_112 -> V_79 . V_80 ;
struct V_81 * V_82 , * V_113 ;
int V_83 = 0 ;
int V_43 ;
F_69 (parent, node) {
struct V_81 * V_93 ;
if ( F_67 ( V_82 -> V_76 , L_13 ) )
continue;
V_93 = F_58 ( V_82 , NULL ) ;
if ( ! V_93 )
continue;
V_43 = F_57 ( V_2 , V_93 , V_83 ) ;
if ( V_43 < 0 )
return V_43 ;
V_83 ++ ;
}
V_113 = F_70 ( V_111 , L_14 ) ;
if ( ! V_113 )
return 0 ;
F_71 (ports, node) {
V_43 = F_57 ( V_2 , V_82 , V_83 ) ;
if ( V_43 < 0 )
break;
V_83 ++ ;
}
return 0 ;
}
static int F_72 ( struct V_81 * V_95 )
{
T_2 V_114 = 0 ;
V_95 = F_70 ( V_95 , L_15 ) ;
if ( ! V_95 )
return - V_53 ;
F_62 ( V_95 , L_16 , & V_114 ) ;
return V_114 - V_115 ;
}
static int F_73 ( struct V_1 * V_2 )
{
struct V_116 * V_88 = V_2 -> V_112 -> V_79 . V_117 ;
struct V_81 * V_80 = V_2 -> V_112 -> V_79 . V_80 ;
int V_118 = 0 ;
int V_43 , V_18 ;
if ( ! V_2 -> V_119 )
return - V_44 ;
V_43 = F_74 ( V_2 -> V_119 ) ;
if ( V_43 < 0 )
return V_43 ;
if ( V_80 ) {
V_2 -> V_92 = 0 ;
V_43 = F_68 ( V_2 , V_80 ) ;
} else if ( V_88 ) {
F_3 ( V_88 -> V_118 > F_47 ( V_2 -> V_4 ) ) ;
V_118 = F_75 ( T_2 , V_88 -> V_118 ,
F_47 ( V_2 -> V_4 ) ) ;
V_2 -> V_92 = V_118 ;
for ( V_18 = 0 ; V_18 < V_118 ; V_18 ++ ) {
struct V_8 * V_67 = & V_2 -> V_4 [ V_18 ] ;
struct V_3 * V_17 ;
V_67 -> V_88 = V_88 -> V_120 [ V_18 ] ;
V_43 = F_51 ( V_2 , & V_67 -> V_88 , true ) ;
if ( V_43 )
break;
V_17 = F_34 ( V_2 , & V_67 -> V_88 ) ;
V_43 = F_51 ( V_2 , & V_67 -> V_88 , false ) ;
if ( F_18 ( V_17 ) ) {
V_67 -> V_91 = NULL ;
V_43 = F_76 ( V_17 ) ;
break;
}
V_67 -> V_91 = V_17 ;
if ( V_43 )
break;
}
}
F_77 ( V_2 -> V_119 ) ;
return V_43 ;
}
static int F_78 ( struct V_1 * V_2 ,
struct V_121 * V_121 )
{
struct V_3 * V_17 ;
struct V_50 * V_51 ;
int V_43 ;
if ( F_3 ( V_121 -> V_83 >= V_122 ||
V_2 -> V_121 [ V_121 -> V_83 ] ) )
return - V_123 ;
V_17 = & V_121 -> V_91 ;
V_17 -> V_29 = V_35 ;
V_51 = F_25 ( V_2 ) ;
if ( ! V_51 )
return - V_124 ;
F_41 ( V_17 , V_51 ) ;
V_43 = F_53 ( & V_2 -> V_73 , V_17 ) ;
if ( ! V_43 )
V_2 -> V_121 [ V_121 -> V_83 ] = V_121 ;
else
F_63 ( & V_2 -> V_73 , L_17 ,
V_121 -> V_83 ) ;
return V_43 ;
}
static int F_79 ( struct V_1 * V_2 , struct V_125 * V_126 )
{
struct V_3 * V_17 ;
struct V_50 * V_51 ;
int V_43 ;
if ( F_3 ( V_126 -> V_127 >= V_128 || V_2 -> V_126 [ V_126 -> V_127 ] ) )
return - V_123 ;
V_17 = & V_126 -> V_129 . V_91 ;
V_17 -> V_29 = V_37 ;
V_51 = F_25 ( V_2 ) ;
if ( ! V_51 )
return - V_124 ;
F_41 ( V_17 , V_51 ) ;
V_43 = F_53 ( & V_2 -> V_73 , V_17 ) ;
if ( ! V_43 ) {
if ( ! V_2 -> V_119 && V_126 -> V_112 )
V_2 -> V_119 = & V_126 -> V_112 -> V_79 ;
V_2 -> V_126 [ V_126 -> V_127 ] = V_126 ;
V_126 -> V_129 . V_130 = V_2 -> V_130 ;
} else {
F_63 ( & V_2 -> V_73 , L_18 ,
V_126 -> V_127 , V_43 ) ;
}
return V_43 ;
}
static int F_80 ( struct V_1 * V_2 ,
struct V_131 * V_112 ,
struct V_3 * V_17 )
{
struct V_81 * V_82 = V_112 -> V_79 . V_80 ;
int V_127 , V_43 ;
V_127 = V_82 ? F_72 ( V_82 ) : F_81 ( 0 , V_112 -> V_127 ) ;
if ( F_3 ( V_127 < 0 || V_127 >= V_132 ) )
return - V_133 ;
if ( F_3 ( V_2 -> V_134 [ V_127 ] . V_17 ) )
return - V_123 ;
V_17 -> V_29 = V_33 ;
V_43 = F_53 ( & V_2 -> V_73 , V_17 ) ;
if ( ! V_43 )
V_2 -> V_134 [ V_127 ] . V_17 = V_17 ;
else
F_63 ( & V_2 -> V_73 ,
L_19 , V_127 , V_43 ) ;
return V_43 ;
}
static int F_82 ( struct V_1 * V_2 , struct V_135 * V_136 )
{
struct V_3 * V_17 = & V_136 -> V_137 . V_91 ;
int V_43 ;
V_43 = F_53 ( & V_2 -> V_73 , V_17 ) ;
if ( V_43 ) {
F_63 ( & V_2 -> V_73 ,
L_20 , V_43 ) ;
return V_43 ;
}
V_2 -> V_135 = V_136 ;
return 0 ;
}
static int F_83 ( struct V_1 * V_2 ,
struct V_131 * V_112 ,
int V_138 )
{
struct V_139 * V_79 = & V_112 -> V_79 ;
int V_43 = - V_74 ;
void * V_140 ;
F_49 ( V_79 ) ;
if ( ! V_79 -> V_84 || ! F_50 ( V_79 -> V_84 -> V_85 ) )
goto V_141;
V_140 = F_84 ( V_79 ) ;
if ( V_140 ) {
switch ( V_138 ) {
case V_38 :
V_43 = F_79 ( V_2 , V_140 ) ;
break;
case V_36 :
V_43 = F_78 ( V_2 , V_140 ) ;
break;
case V_34 :
V_43 = F_80 ( V_2 , V_112 , V_140 ) ;
break;
case V_40 :
V_43 = F_82 ( V_2 , V_140 ) ;
break;
default:
V_43 = - V_58 ;
}
}
F_54 ( V_79 -> V_84 -> V_85 ) ;
V_141:
F_55 ( V_79 ) ;
if ( V_43 == - V_74 )
F_85 ( & V_2 -> V_112 -> V_79 , L_21 ,
F_86 ( V_79 ) ) ;
else if ( V_43 < 0 )
F_87 ( & V_2 -> V_112 -> V_79 , L_22 ,
F_86 ( V_79 ) , V_43 ) ;
return V_43 ;
}
static int F_88 ( struct V_139 * V_79 , void * V_142 )
{
struct V_131 * V_112 = F_89 ( V_79 ) ;
int V_138 = - 1 ;
int V_43 ;
char * V_14 ;
if ( ! F_90 ( V_79 ) )
return - V_58 ;
if ( ! strcmp ( V_112 -> V_76 , V_143 ) ) {
V_138 = V_34 ;
} else {
V_14 = strstr ( V_112 -> V_76 , L_23 ) ;
if ( V_14 && * ( V_14 + 4 ) == 0 )
V_138 = V_38 ;
}
if ( V_138 >= 0 )
V_43 = F_83 ( V_142 , V_112 ,
V_138 ) ;
F_56 ( V_79 ) ;
return 0 ;
}
static int F_91 ( struct V_1 * V_2 ,
struct V_81 * V_111 )
{
struct V_81 * V_82 ;
int V_43 = 0 ;
F_69 (parent, node) {
struct V_131 * V_112 ;
int V_138 = - 1 ;
V_112 = F_92 ( V_82 ) ;
if ( ! V_112 )
continue;
if ( ! strcmp ( V_82 -> V_76 , V_144 ) )
V_138 = V_34 ;
else if ( ! strcmp ( V_82 -> V_76 , V_145 ) )
V_138 = V_40 ;
else if ( ! strcmp ( V_82 -> V_76 , V_146 ) )
V_138 = V_36 ;
else if ( ! strcmp ( V_82 -> V_76 , V_147 ) &&
! F_93 ( V_82 , L_24 ) )
V_138 = V_38 ;
if ( V_138 >= 0 )
V_43 = F_83 ( V_2 , V_112 ,
V_138 ) ;
F_56 ( & V_112 -> V_79 ) ;
if ( V_43 < 0 )
break;
}
return V_43 ;
}
static void F_94 ( struct V_1 * V_2 )
{
int V_18 ;
for ( V_18 = 0 ; V_18 < V_128 ; V_18 ++ ) {
struct V_125 * V_79 = V_2 -> V_126 [ V_18 ] ;
if ( V_79 == NULL )
continue;
F_44 ( & V_79 -> V_129 . V_91 ) ;
V_79 -> V_129 . V_148 . V_149 = NULL ;
V_2 -> V_126 [ V_18 ] = NULL ;
}
for ( V_18 = 0 ; V_18 < V_122 ; V_18 ++ ) {
struct V_121 * V_79 = V_2 -> V_121 [ V_18 ] ;
if ( V_79 == NULL )
continue;
F_44 ( & V_79 -> V_91 ) ;
V_79 -> V_148 . V_149 = NULL ;
V_2 -> V_121 [ V_18 ] = NULL ;
}
for ( V_18 = 0 ; V_18 < V_132 ; V_18 ++ ) {
if ( V_2 -> V_134 [ V_18 ] . V_17 == NULL )
continue;
F_44 ( V_2 -> V_134 [ V_18 ] . V_17 ) ;
V_2 -> V_134 [ V_18 ] . V_17 = NULL ;
}
for ( V_18 = 0 ; V_18 < V_2 -> V_92 ; V_18 ++ ) {
if ( V_2 -> V_4 [ V_18 ] . V_91 == NULL )
continue;
F_43 ( V_2 -> V_4 [ V_18 ] . V_91 ) ;
V_2 -> V_4 [ V_18 ] . V_91 = NULL ;
}
if ( V_2 -> V_135 )
F_44 ( & V_2 -> V_135 -> V_137 . V_91 ) ;
F_42 ( & V_2 -> V_73 , L_25 ) ;
}
static int F_95 ( struct V_1 * V_2 ,
struct V_15 * V_150 ,
struct V_3 * V_4 ,
int V_22 , int V_151 )
{
struct V_6 * V_67 = NULL ;
struct V_15 * V_152 ;
unsigned int V_10 = 0 ;
int V_18 , V_43 = 0 ;
if ( V_4 ) {
V_67 = F_2 ( V_4 ) ;
if ( V_67 && V_67 -> V_70 == V_90 )
V_43 = 1 ;
}
for ( V_18 = 0 ; ! V_43 && V_18 < V_128 ; V_18 ++ ) {
if ( ! V_2 -> V_126 [ V_18 ] )
continue;
if ( ! V_2 -> V_126 [ V_18 ] -> V_153 -> V_154 )
continue;
V_10 = ( ( 1 << V_18 ) & V_151 ) ? V_155 : 0 ;
V_152 = & V_2 -> V_126 [ V_18 ] -> V_129 . V_91 . V_27 ;
V_43 = F_96 ( V_150 , V_22 , V_152 ,
V_156 , V_10 ) ;
if ( V_43 )
return V_43 ;
V_43 = F_97 ( V_152 , V_157 , & V_152 -> V_25 [ 0 ] ,
& V_150 -> V_25 [ V_22 ] , V_10 ) ;
if ( V_43 )
break;
F_42 ( & V_2 -> V_73 , L_26 ,
V_150 -> V_76 , V_10 ? '=' : '-' , V_152 -> V_76 ) ;
}
for ( V_18 = 0 ; V_18 < V_122 ; V_18 ++ ) {
if ( ! V_2 -> V_121 [ V_18 ] )
continue;
V_152 = & V_2 -> V_121 [ V_18 ] -> V_91 . V_27 ;
V_43 = F_96 ( V_150 , V_22 , V_152 ,
V_158 , 0 ) ;
if ( V_43 )
return V_43 ;
V_43 = F_97 ( V_152 , V_157 , & V_152 -> V_25 [ 0 ] ,
& V_150 -> V_25 [ V_22 ] , 0 ) ;
if ( V_43 )
break;
F_42 ( & V_2 -> V_73 , L_27 ,
V_150 -> V_76 , V_152 -> V_76 ) ;
}
return 0 ;
}
static int F_98 ( struct V_1 * V_2 )
{
struct V_15 * V_150 , * V_152 ;
int V_18 , V_43 = 0 ;
for ( V_18 = 0 ; V_18 < V_122 ; V_18 ++ ) {
struct V_121 * V_126 = V_2 -> V_121 [ V_18 ] ;
if ( V_126 == NULL )
continue;
V_150 = & V_126 -> V_91 . V_27 ;
V_152 = & V_126 -> V_148 . V_159 . V_27 ;
V_43 = F_96 ( V_150 , V_160 ,
V_152 , 0 , 0 ) ;
if ( V_43 )
break;
V_152 = & V_2 -> V_135 -> V_137 . V_91 . V_27 ;
V_43 = F_96 ( V_150 , V_161 ,
V_152 , 0 , 0 ) ;
if ( V_43 )
break;
}
return V_43 ;
}
static int F_99 ( struct V_1 * V_2 )
{
struct V_15 * V_150 , * V_152 ;
int V_18 , V_43 ;
V_150 = & V_2 -> V_135 -> V_137 . V_91 . V_27 ;
for ( V_18 = 0 ; V_18 < V_128 ; V_18 ++ ) {
if ( V_2 -> V_126 [ V_18 ] == NULL )
continue;
V_152 = & V_2 -> V_126 [ V_18 ] -> V_129 . V_91 . V_27 ;
V_43 = F_96 ( V_150 , V_162 ,
V_152 , V_163 , 0 ) ;
if ( V_43 )
return V_43 ;
}
return V_43 ;
}
static int F_100 ( struct V_1 * V_2 )
{
struct V_3 * V_164 [ V_132 ] = { NULL } ;
struct V_3 * V_4 , * V_134 ;
struct V_6 * V_88 ;
struct V_15 * V_150 , * V_152 ;
int V_18 , V_22 , V_165 = 0 , V_43 = 0 ;
T_2 V_10 , V_151 = 0 ;
for ( V_18 = 0 ; V_18 < V_2 -> V_92 ; V_18 ++ ) {
if ( V_2 -> V_4 [ V_18 ] . V_91 == NULL )
continue;
V_4 = V_2 -> V_4 [ V_18 ] . V_91 ;
V_88 = F_2 ( V_4 ) ;
if ( ! V_88 )
continue;
V_150 = NULL ;
switch ( V_88 -> V_71 ) {
case V_110 :
if ( F_101 ( V_88 -> V_101 >= V_132 ,
L_28 , V_88 -> V_101 ) )
return - V_53 ;
V_134 = V_2 -> V_134 [ V_88 -> V_101 ] . V_17 ;
if ( F_101 ( V_134 == NULL ,
L_29
L_30 ) )
return - V_53 ;
V_22 = V_4 -> V_27 . V_23 - 1 ;
V_43 = F_96 ( & V_4 -> V_27 , V_22 ,
& V_134 -> V_27 , V_166 ,
V_167 |
V_155 ) ;
if ( V_43 )
return V_43 ;
F_42 ( & V_2 -> V_73 , L_31 ,
V_4 -> V_27 . V_76 , V_134 -> V_27 . V_76 ) ;
V_150 = NULL ;
V_164 [ V_88 -> V_101 ] = V_4 ;
break;
case V_106 ... V_107 :
V_150 = & V_4 -> V_27 ;
V_22 = 0 ;
break;
default:
F_63 ( & V_2 -> V_73 , L_32 ,
V_88 -> V_71 ) ;
return - V_53 ;
}
if ( V_150 == NULL )
continue;
V_151 = 1 << V_165 ++ ;
V_43 = F_95 ( V_2 , V_150 , V_4 ,
V_22 , V_151 ) ;
}
for ( V_18 = 0 ; V_18 < V_132 ; V_18 ++ ) {
if ( V_2 -> V_134 [ V_18 ] . V_17 == NULL )
continue;
V_150 = & V_2 -> V_134 [ V_18 ] . V_17 -> V_27 ;
V_22 = V_168 ;
V_4 = V_164 [ V_18 ] ;
V_151 = 1 << V_165 ++ ;
V_43 = F_95 ( V_2 , V_150 , V_4 ,
V_22 , V_151 ) ;
}
V_10 = V_167 | V_155 ;
for ( V_18 = 0 ; V_18 < V_128 ; V_18 ++ ) {
if ( ! V_2 -> V_126 [ V_18 ] )
continue;
V_150 = & V_2 -> V_126 [ V_18 ] -> V_129 . V_91 . V_27 ;
V_152 = & V_2 -> V_126 [ V_18 ] -> V_129 . V_148 . V_159 . V_27 ;
V_43 = F_96 ( V_150 , V_169 ,
V_152 , 0 , V_10 ) ;
if ( V_43 )
break;
}
V_43 = F_98 ( V_2 ) ;
if ( V_43 < 0 )
return V_43 ;
if ( V_2 -> V_170 )
V_43 = F_99 ( V_2 ) ;
return V_43 ;
}
static void F_102 ( struct V_1 * V_2 )
{
int V_18 = V_171 ;
while ( -- V_18 >= 0 ) {
if ( F_18 ( V_2 -> V_172 [ V_18 ] . clock ) )
continue;
F_103 ( V_2 -> V_172 [ V_18 ] . clock ) ;
V_2 -> V_172 [ V_18 ] . clock = F_37 ( - V_53 ) ;
}
for ( V_18 = 0 ; V_18 < V_173 ; V_18 ++ ) {
if ( F_18 ( V_2 -> V_54 [ V_18 ] ) )
continue;
F_103 ( V_2 -> V_54 [ V_18 ] ) ;
V_2 -> V_54 [ V_18 ] = F_37 ( - V_53 ) ;
}
}
static int F_104 ( struct V_1 * V_2 )
{
struct V_139 * V_79 = NULL ;
char V_174 [ 32 ] ;
struct V_175 * clock ;
int V_18 , V_43 = 0 ;
for ( V_18 = 0 ; V_18 < V_171 ; V_18 ++ )
V_2 -> V_172 [ V_18 ] . clock = F_37 ( - V_53 ) ;
if ( V_2 -> V_112 -> V_79 . V_80 )
V_79 = & V_2 -> V_112 -> V_79 ;
for ( V_18 = 0 ; V_18 < V_171 ; V_18 ++ ) {
snprintf ( V_174 , sizeof( V_174 ) , L_33 , V_18 ) ;
clock = F_105 ( V_79 , V_174 ) ;
if ( F_18 ( clock ) ) {
F_87 ( & V_2 -> V_112 -> V_79 , L_34 ,
V_174 ) ;
V_43 = F_76 ( clock ) ;
break;
}
V_2 -> V_172 [ V_18 ] . clock = clock ;
}
if ( V_43 )
F_102 ( V_2 ) ;
if ( ! V_2 -> V_170 )
return 0 ;
V_2 -> V_54 [ V_176 ] = F_37 ( - V_53 ) ;
for ( V_18 = V_55 ; V_18 < V_173 ; V_18 ++ ) {
snprintf ( V_174 , sizeof( V_174 ) , L_35 , V_18 ) ;
clock = F_105 ( V_79 , V_174 ) ;
if ( F_18 ( clock ) ) {
F_63 ( & V_2 -> V_73 , L_34 ,
V_174 ) ;
V_43 = F_76 ( clock ) ;
break;
}
V_2 -> V_54 [ V_18 ] = clock ;
}
if ( V_43 )
F_102 ( V_2 ) ;
return V_43 ;
}
static int F_51 ( struct V_1 * V_2 ,
struct V_6 * V_67 ,
bool V_41 )
{
struct V_177 * V_172 ;
int V_43 = 0 ;
if ( F_3 ( V_67 -> V_102 >= V_171 ) || ! V_2 || ! V_2 -> V_119 )
return - V_53 ;
V_172 = & V_2 -> V_172 [ V_67 -> V_102 ] ;
F_106 ( L_36 ,
V_67 -> V_102 , V_67 -> V_103 , V_172 -> V_42 , V_41 ) ;
if ( V_41 ) {
if ( V_172 -> V_42 > 0 &&
V_172 -> V_178 != V_67 -> V_103 )
return - V_53 ;
if ( V_172 -> V_42 ++ == 0 ) {
F_107 ( V_172 -> clock , V_67 -> V_103 ) ;
V_172 -> V_178 = V_67 -> V_103 ;
V_43 = F_74 ( V_2 -> V_119 ) ;
if ( V_43 < 0 )
return V_43 ;
V_43 = F_19 ( V_172 -> clock ) ;
F_106 ( L_37 , V_67 -> V_102 ,
F_108 ( V_172 -> clock ) ) ;
}
return V_43 ;
}
if ( F_3 ( V_172 -> V_42 == 0 ) )
return 0 ;
if ( -- V_172 -> V_42 == 0 ) {
F_21 ( V_172 -> clock ) ;
F_77 ( V_2 -> V_119 ) ;
F_106 ( L_38 , V_67 -> V_102 ) ;
}
return V_43 ;
}
int F_20 ( struct V_3 * V_17 , bool V_41 )
{
struct V_6 * V_67 = F_2 ( V_17 ) ;
struct V_1 * V_2 = F_9 ( & V_17 -> V_27 ) ;
return F_51 ( V_2 , V_67 , V_41 ) ;
}
static int F_109 ( struct V_15 * V_27 , bool V_179 )
{
struct V_180 * V_148 ;
struct V_13 * V_14 ;
struct V_181 * V_159 ;
int V_43 ;
V_159 = F_110 ( V_27 ) ;
if ( V_159 -> V_27 . V_42 == 0 )
return 0 ;
V_148 = F_111 ( V_159 ) ;
V_14 = F_17 ( V_148 -> V_149 ) ;
if ( ! V_179 && V_14 -> V_20 [ V_32 ] == NULL )
return 0 ;
if ( V_179 )
V_43 = F_16 ( V_148 -> V_149 , V_27 , true ) ;
else
V_43 = F_22 ( V_148 -> V_149 ) ;
if ( V_43 == 0 && ! V_179 )
memset ( V_14 -> V_20 , 0 , sizeof( V_14 -> V_20 ) ) ;
return V_43 ;
}
static int F_112 ( struct V_15 * V_27 , bool V_179 )
{
struct V_15 * V_182 = V_27 ;
struct V_183 V_184 ;
int V_43 ;
F_113 ( & V_184 , V_27 ) ;
while ( ( V_27 = F_114 ( & V_184 ) ) ) {
if ( F_11 ( V_27 ) != V_185 )
continue;
V_43 = F_109 ( V_27 , V_179 ) ;
if ( V_43 < 0 )
goto V_186;
}
return 0 ;
V_186:
F_113 ( & V_184 , V_182 ) ;
while ( ( V_182 = F_114 ( & V_184 ) ) ) {
if ( F_11 ( V_182 ) != V_185 )
continue;
F_109 ( V_182 , ! V_179 ) ;
if ( V_182 == V_27 )
break;
}
return V_43 ;
}
static int F_115 ( struct V_187 * V_188 , unsigned int V_10 ,
unsigned int V_189 )
{
struct V_15 * V_152 = V_188 -> V_152 -> V_27 ;
int V_43 = 0 ;
if ( V_189 == V_190 ) {
if ( ! ( V_10 & V_155 ) )
V_43 = F_112 ( V_152 , false ) ;
else
;
} else if ( V_189 == V_191 &&
( V_188 -> V_10 & V_155 ) ) {
V_43 = F_112 ( V_152 , true ) ;
}
return V_43 ? - V_192 : 0 ;
}
static T_3 F_116 ( struct V_139 * V_79 ,
struct V_193 * V_194 , char * V_195 )
{
struct V_131 * V_112 = F_89 ( V_79 ) ;
struct V_1 * V_2 = F_117 ( V_112 ) ;
if ( V_2 -> V_130 )
return F_118 ( V_195 , L_39 , V_196 ) ;
return F_118 ( V_195 , L_40 , V_196 ) ;
}
static T_3 F_119 ( struct V_139 * V_79 ,
struct V_193 * V_194 ,
const char * V_195 , T_4 V_197 )
{
struct V_131 * V_112 = F_89 ( V_79 ) ;
struct V_1 * V_2 = F_117 ( V_112 ) ;
bool V_198 ;
int V_18 ;
if ( ! strcmp ( V_195 , L_41 ) )
V_198 = false ;
else if ( ! strcmp ( V_195 , L_42 ) )
V_198 = true ;
else
return V_197 ;
V_2 -> V_130 = V_198 ;
for ( V_18 = 0 ; V_18 < V_128 ; V_18 ++ )
if ( V_2 -> V_126 [ V_18 ] )
V_2 -> V_126 [ V_18 ] -> V_129 . V_130 = V_198 ;
return V_197 ;
}
static int F_120 ( struct V_1 * V_2 )
{
struct V_139 * V_79 = & V_2 -> V_112 -> V_79 ;
struct V_199 * V_200 = & V_2 -> V_201 ;
V_200 -> V_202 = F_121 ( V_79 ) ;
if ( F_18 ( V_200 -> V_202 ) )
return F_76 ( V_200 -> V_202 ) ;
V_200 -> V_203 = F_122 ( V_200 -> V_202 ,
V_204 ) ;
if ( F_18 ( V_200 -> V_203 ) )
return F_76 ( V_200 -> V_203 ) ;
V_200 -> V_205 = F_122 ( V_200 -> V_202 ,
V_206 ) ;
return 0 ;
}
static int F_123 ( struct V_131 * V_112 )
{
struct V_139 * V_79 = & V_112 -> V_79 ;
struct V_207 * V_73 ;
struct V_1 * V_2 ;
int V_43 ;
V_2 = F_124 ( V_79 , sizeof( * V_2 ) , V_61 ) ;
if ( ! V_2 )
return - V_124 ;
F_125 ( & V_2 -> V_11 ) ;
V_2 -> V_112 = V_112 ;
F_126 ( & V_2 -> V_63 ) ;
F_118 ( V_2 -> V_208 . V_209 , L_43 ,
sizeof( V_2 -> V_208 . V_209 ) ) ;
V_2 -> V_208 . V_210 = F_115 ;
V_2 -> V_208 . V_79 = V_79 ;
V_73 = & V_2 -> V_73 ;
V_73 -> V_211 = & V_2 -> V_208 ;
V_73 -> V_212 = V_213 ;
F_118 ( V_73 -> V_76 , L_44 , sizeof( V_73 -> V_76 ) ) ;
V_2 -> V_170 = F_127 ( V_79 -> V_80 ) ;
V_43 = F_128 ( V_79 , & V_2 -> V_73 ) ;
if ( V_43 < 0 ) {
F_63 ( V_73 , L_45 , V_43 ) ;
return V_43 ;
}
V_43 = F_129 ( & V_2 -> V_208 ) ;
if ( V_43 < 0 ) {
F_63 ( V_73 , L_46 , V_43 ) ;
goto V_214;
}
V_43 = F_104 ( V_2 ) ;
if ( V_43 )
goto V_215;
V_2 -> V_130 = ( V_79 -> V_80 != NULL ) ;
F_130 ( & V_2 -> V_208 . V_216 ) ;
V_43 = F_120 ( V_2 ) ;
if ( V_43 < 0 ) {
if ( V_43 != V_74 )
F_87 ( V_79 , L_47 , V_43 ) ;
goto V_217;
}
if ( V_79 -> V_80 )
V_43 = F_91 ( V_2 , V_79 -> V_80 ) ;
else
V_43 = F_131 ( & V_218 , NULL , V_2 ,
F_88 ) ;
if ( V_43 )
goto V_217;
if ( V_79 -> V_117 || V_79 -> V_80 ) {
V_43 = F_73 ( V_2 ) ;
if ( V_43 )
goto V_217;
}
V_43 = F_100 ( V_2 ) ;
if ( V_43 )
goto V_217;
V_43 = F_132 ( & V_2 -> V_73 ) ;
if ( V_43 )
goto V_217;
V_43 = F_133 ( & V_112 -> V_79 , & V_219 ) ;
if ( V_43 )
goto V_217;
F_134 ( V_112 , V_2 ) ;
F_135 ( & V_2 -> V_208 . V_216 ) ;
return 0 ;
V_217:
F_135 ( & V_2 -> V_208 . V_216 ) ;
V_215:
F_102 ( V_2 ) ;
F_94 ( V_2 ) ;
F_136 ( & V_2 -> V_208 ) ;
V_214:
F_137 ( & V_2 -> V_73 ) ;
return V_43 ;
}
static int F_138 ( struct V_131 * V_112 )
{
struct V_1 * V_2 = F_117 ( V_112 ) ;
if ( ! V_2 )
return 0 ;
F_137 ( & V_2 -> V_73 ) ;
F_139 ( & V_112 -> V_79 , & V_219 ) ;
F_94 ( V_2 ) ;
F_28 ( V_2 ) ;
F_136 ( & V_2 -> V_208 ) ;
F_102 ( V_2 ) ;
return 0 ;
}
static int T_5 F_140 ( void )
{
int V_43 ;
F_141 ( L_48 ) ;
V_43 = F_142 () ;
if ( V_43 )
return V_43 ;
return F_143 ( & V_220 ) ;
}
static void T_6 F_144 ( void )
{
F_145 ( & V_220 ) ;
F_146 () ;
}
