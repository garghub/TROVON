static void F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 ;
int V_7 ;
for ( V_7 = 0 ; V_7 < V_8 ; V_7 ++ )
V_2 -> V_9 [ V_7 ] = NULL ;
while ( 1 ) {
struct V_10 * V_11 = NULL ;
for ( V_7 = 0 ; V_7 < V_4 -> V_12 ; V_7 ++ ) {
struct V_10 * V_13 = & V_4 -> V_14 [ V_7 ] ;
if ( ! ( V_13 -> V_15 & V_16 ) )
continue;
V_11 = F_2 ( V_13 ) ;
if ( V_11 )
break;
}
if ( V_11 == NULL ||
F_3 ( V_11 -> V_17 ) != V_18 )
break;
V_6 = F_4 ( V_11 -> V_17 ) ;
switch ( V_6 -> V_19 ) {
case V_20 :
case V_21 :
V_2 -> V_9 [ V_22 ] = V_6 ;
break;
case V_23 :
V_2 -> V_9 [ V_24 ] = V_6 ;
break;
case V_25 :
V_2 -> V_9 [ V_26 ] = V_6 ;
break;
case V_27 :
break;
case V_28 :
V_2 -> V_9 [ V_29 ] = V_6 ;
break;
default:
break;
}
V_4 = & V_6 -> V_17 ;
if ( V_4 -> V_12 == 1 )
break;
}
}
static int F_5 ( struct V_5 * V_6 , int V_30 )
{
int * V_31 ;
int V_32 ;
if ( V_6 == NULL )
return - V_33 ;
V_31 = & V_6 -> V_17 . V_31 ;
if ( V_30 && ( * V_31 ) ++ > 0 )
return 0 ;
else if ( ! V_30 && ( * V_31 == 0 || -- ( * V_31 ) > 0 ) )
return 0 ;
V_32 = F_6 ( V_6 , V_34 , V_35 , V_30 ) ;
return V_32 != - V_36 ? V_32 : 0 ;
}
static int F_7 ( struct V_1 * V_2 , bool V_30 )
{
static const T_1 V_37 [ 2 ] [ V_8 - 1 ] = {
{ V_29 , V_22 , V_24 , V_26 } ,
{ V_24 , V_26 , V_22 , V_29 } ,
} ;
int V_7 , V_32 = 0 ;
if ( V_2 -> V_9 [ V_22 ] == NULL )
return - V_33 ;
for ( V_7 = 0 ; V_7 < V_8 - 1 ; V_7 ++ ) {
unsigned int V_38 = V_37 [ V_30 ] [ V_7 ] ;
V_32 = F_5 ( V_2 -> V_9 [ V_38 ] , V_30 ) ;
if ( V_32 < 0 && V_32 != - V_33 )
goto error;
}
return 0 ;
error:
for (; V_7 >= 0 ; V_7 -- ) {
unsigned int V_38 = V_37 [ V_30 ] [ V_7 ] ;
F_5 ( V_2 -> V_9 [ V_38 ] , ! V_30 ) ;
}
return V_32 ;
}
static int F_8 ( struct V_1 * V_2 ,
struct V_3 * V_4 , bool V_39 )
{
struct V_40 * V_41 = F_9 ( V_4 ) ;
struct V_5 * V_6 ;
int V_32 ;
if ( F_10 ( V_2 == NULL || V_4 == NULL ) )
return - V_42 ;
if ( V_39 )
F_1 ( V_2 , V_4 ) ;
V_6 = V_2 -> V_9 [ V_22 ] ;
if ( V_6 == NULL )
return - V_42 ;
if ( ! F_11 ( V_41 -> V_43 [ V_44 ] ) && V_2 -> V_9 [ V_29 ] ) {
V_32 = F_12 ( V_41 -> V_43 [ V_44 ] ) ;
if ( V_32 < 0 )
return V_32 ;
}
V_32 = F_13 ( V_6 , true ) ;
if ( V_32 < 0 )
goto V_45;
V_32 = F_7 ( V_2 , 1 ) ;
if ( ! V_32 )
return 0 ;
F_13 ( V_6 , false ) ;
V_45:
if ( ! F_11 ( V_41 -> V_43 [ V_44 ] ) && V_2 -> V_9 [ V_29 ] )
F_14 ( V_41 -> V_43 [ V_44 ] ) ;
return V_32 ;
}
static int F_15 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = V_2 ? V_2 -> V_9 [ V_22 ] : NULL ;
struct V_40 * V_41 ;
int V_32 = 0 ;
if ( F_10 ( V_6 == NULL ) )
return - V_42 ;
if ( V_2 -> V_9 [ V_22 ] ) {
V_32 = F_7 ( V_2 , 0 ) ;
F_13 ( V_6 , false ) ;
}
V_41 = F_9 ( & V_6 -> V_17 ) ;
if ( ! F_11 ( V_41 -> V_43 [ V_44 ] ) && V_2 -> V_9 [ V_29 ] )
F_14 ( V_41 -> V_43 [ V_44 ] ) ;
return V_32 == - V_33 ? 0 : V_32 ;
}
static int F_16 ( struct V_1 * V_2 , bool V_30 )
{
static const T_1 V_37 [ 2 ] [ V_8 ] = {
{ V_46 , V_22 , V_29 , V_24 , V_26 } ,
{ V_24 , V_26 , V_46 , V_22 , V_29 } ,
} ;
int V_7 , V_32 = 0 ;
if ( V_2 -> V_9 [ V_22 ] == NULL )
return - V_47 ;
for ( V_7 = 0 ; V_7 < V_8 ; V_7 ++ ) {
unsigned int V_38 = V_37 [ V_30 ] [ V_7 ] ;
V_32 = F_6 ( V_2 -> V_9 [ V_38 ] , V_48 , V_49 , V_30 ) ;
if ( V_32 < 0 && V_32 != - V_36 && V_32 != - V_47 )
goto error;
}
return 0 ;
error:
for (; V_7 >= 0 ; V_7 -- ) {
unsigned int V_38 = V_37 [ V_30 ] [ V_7 ] ;
F_6 ( V_2 -> V_9 [ V_38 ] , V_48 , V_49 , ! V_30 ) ;
}
return V_32 ;
}
static struct V_5 * F_17 ( struct V_40 * V_41 ,
struct V_50 * V_51 )
{
struct V_52 * V_53 ;
struct V_5 * V_6 = NULL ;
if ( ! V_51 || ! V_41 )
return NULL ;
V_51 -> V_54 = V_51 -> V_55 ;
V_53 = F_18 ( V_51 -> V_56 ) ;
if ( ! V_53 ) {
F_19 ( & V_41 -> V_57 ,
L_1 ,
V_51 -> V_56 ) ;
return F_20 ( - V_58 ) ;
}
V_6 = F_21 ( & V_41 -> V_57 , V_53 ,
V_51 -> V_59 , NULL ) ;
if ( F_22 ( V_6 ) ) {
F_23 ( V_53 ) ;
F_19 ( & V_41 -> V_57 ,
L_2 ,
V_51 -> V_59 -> type ) ;
return F_20 ( - V_58 ) ;
}
F_24 ( V_6 , V_51 ) ;
V_6 -> V_19 = V_21 ;
F_25 ( & V_41 -> V_57 , L_3 ,
V_6 -> V_60 ) ;
return V_6 ;
}
static void F_26 ( struct V_5 * V_6 )
{
struct V_61 * V_62 = F_27 ( V_6 ) ;
struct V_52 * V_53 ;
if ( ! V_62 )
return;
F_28 ( V_6 ) ;
if ( ! V_62 -> V_63 . V_64 ) {
V_53 = V_62 -> V_53 ;
F_29 ( V_62 ) ;
if ( V_53 )
F_23 ( V_53 ) ;
}
}
static int F_30 ( struct V_40 * V_41 ,
struct V_65 * V_66 , int V_67 )
{
struct V_68 * V_51 ;
struct V_61 * V_62 ;
struct V_5 * V_6 ;
int V_32 ;
if ( F_10 ( V_67 >= F_31 ( V_41 -> V_69 ) ) )
return - V_42 ;
V_51 = & V_41 -> V_69 [ V_67 ] ;
V_62 = F_32 ( V_66 ) ;
if ( ! V_62 )
return - V_58 ;
F_33 ( & V_62 -> V_63 ) ;
if ( ! V_62 -> V_70 ||
! F_34 ( V_62 -> V_70 -> V_70 . V_71 ) ) {
V_32 = - V_58 ;
F_25 ( & V_41 -> V_57 , L_4 ,
V_66 -> V_72 ) ;
goto V_73;
}
V_32 = F_35 ( V_41 , & V_51 -> V_74 , true ) ;
if ( V_32 < 0 )
goto V_75;
V_6 = F_36 ( V_62 ) ;
V_32 = F_37 ( & V_41 -> V_57 , V_6 ) ;
F_35 ( V_41 , & V_51 -> V_74 , false ) ;
if ( V_32 < 0 )
goto V_75;
F_24 ( V_6 , & V_51 -> V_74 ) ;
if ( V_51 -> V_74 . V_54 == V_76 )
V_6 -> V_19 = V_20 ;
else
V_6 -> V_19 = V_21 ;
V_51 -> V_77 = V_6 ;
F_25 ( & V_41 -> V_57 , L_5 ,
V_6 -> V_60 , V_41 -> V_78 ) ;
V_41 -> V_78 ++ ;
V_75:
F_38 ( V_62 -> V_70 -> V_70 . V_71 ) ;
V_73:
F_39 ( & V_62 -> V_63 ) ;
F_40 ( & V_62 -> V_63 ) ;
return V_32 ;
}
static int F_41 ( struct V_40 * V_41 ,
struct V_65 * V_79 ,
unsigned int V_67 )
{
struct V_65 * V_80 , * V_81 , * V_82 ;
struct V_50 * V_83 ;
struct V_84 V_85 ;
int V_32 ;
T_2 V_86 ;
V_83 = & V_41 -> V_69 [ V_67 ] . V_74 ;
V_81 = F_42 ( V_79 , NULL ) ;
if ( ! V_81 )
return 0 ;
F_43 ( V_81 , & V_85 ) ;
if ( F_10 ( V_85 . V_79 == 0 ) || V_67 >= V_87 )
return - V_42 ;
V_83 -> V_88 = ( V_85 . V_79 - 1 ) & 0x1 ;
V_80 = F_44 ( V_81 ) ;
F_45 ( V_81 ) ;
if ( V_80 == NULL ) {
F_25 ( & V_41 -> V_57 , L_6 ,
V_81 -> V_72 ) ;
return 0 ;
}
if ( ! F_46 ( V_80 , L_7 , & V_86 ) )
V_83 -> V_89 = V_86 ;
if ( ! F_46 ( V_80 , L_8 , & V_86 ) )
V_83 -> V_90 = V_86 ;
if ( V_83 -> V_90 == 0 ) {
F_47 ( & V_41 -> V_57 , L_9 ,
V_80 -> V_72 ) ;
F_45 ( V_80 ) ;
return - V_42 ;
}
if ( F_48 ( V_85 . V_79 ) ) {
if ( V_85 . V_91 == V_92 )
V_83 -> V_55 = V_93 ;
else
V_83 -> V_55 = V_94 ;
V_83 -> V_15 = V_85 . V_95 . V_96 . V_15 ;
} else if ( F_49 ( V_85 . V_79 ) ) {
V_83 -> V_55 = V_97 ;
} else {
F_47 ( & V_41 -> V_57 , L_10 ,
V_85 . V_79 , V_80 -> V_72 ) ;
}
V_82 = F_50 ( V_80 ) ;
if ( V_82 && ! F_51 ( V_82 -> V_60 , L_11 ) )
V_83 -> V_54 = V_76 ;
else
V_83 -> V_54 = V_83 -> V_55 ;
V_32 = F_30 ( V_41 , V_80 , V_67 ) ;
F_45 ( V_80 ) ;
return V_32 ;
}
static int F_52 ( struct V_40 * V_41 ,
struct V_65 * V_82 )
{
struct V_65 * V_98 = V_41 -> V_99 -> V_63 . V_64 ;
struct V_65 * V_66 , * V_100 ;
int V_67 = 0 ;
int V_32 ;
F_53 (parent, node) {
struct V_65 * V_79 ;
if ( F_51 ( V_66 -> V_60 , L_12 ) )
continue;
V_79 = F_42 ( V_66 , NULL ) ;
if ( ! V_79 )
continue;
V_32 = F_41 ( V_41 , V_79 , V_67 ) ;
if ( V_32 < 0 )
return V_32 ;
V_67 ++ ;
}
V_100 = F_54 ( V_98 , L_13 ) ;
if ( ! V_100 )
return 0 ;
F_55 (ports, node) {
V_32 = F_41 ( V_41 , V_66 , V_67 ) ;
if ( V_32 < 0 )
break;
V_67 ++ ;
}
return 0 ;
}
static int F_56 ( struct V_65 * V_82 )
{
T_2 V_101 = 0 ;
V_82 = F_54 ( V_82 , L_14 ) ;
if ( ! V_82 )
return - V_42 ;
F_46 ( V_82 , L_15 , & V_101 ) ;
return V_101 - V_102 ;
}
static int F_57 ( struct V_40 * V_41 )
{
struct V_103 * V_74 = V_41 -> V_99 -> V_63 . V_104 ;
struct V_65 * V_64 = V_41 -> V_99 -> V_63 . V_64 ;
int V_105 = 0 ;
int V_32 , V_7 ;
if ( ! V_41 -> V_106 )
return - V_33 ;
V_32 = F_58 ( V_41 -> V_106 ) ;
if ( V_32 < 0 )
return V_32 ;
if ( V_64 ) {
V_41 -> V_78 = 0 ;
V_32 = F_52 ( V_41 , V_64 ) ;
} else if ( V_74 ) {
F_10 ( V_74 -> V_105 > F_31 ( V_41 -> V_69 ) ) ;
V_105 = F_59 ( T_2 , V_74 -> V_105 ,
F_31 ( V_41 -> V_69 ) ) ;
V_41 -> V_78 = V_105 ;
for ( V_7 = 0 ; V_7 < V_105 ; V_7 ++ ) {
struct V_68 * V_51 = & V_41 -> V_69 [ V_7 ] ;
struct V_5 * V_6 ;
V_51 -> V_74 = V_74 -> V_107 [ V_7 ] ;
V_32 = F_35 ( V_41 , & V_51 -> V_74 , true ) ;
if ( V_32 )
break;
V_6 = F_17 ( V_41 , & V_51 -> V_74 ) ;
V_32 = F_35 ( V_41 , & V_51 -> V_74 , false ) ;
if ( F_11 ( V_6 ) ) {
V_51 -> V_77 = NULL ;
V_32 = F_60 ( V_6 ) ;
break;
}
V_51 -> V_77 = V_6 ;
if ( V_32 )
break;
}
}
F_61 ( V_41 -> V_106 ) ;
return V_32 ;
}
static int F_62 ( struct V_40 * V_41 ,
struct V_108 * V_108 )
{
struct V_5 * V_6 ;
int V_32 ;
if ( F_10 ( V_108 -> V_67 >= V_109 ||
V_41 -> V_108 [ V_108 -> V_67 ] ) )
return - V_110 ;
V_6 = & V_108 -> V_77 ;
V_6 -> V_19 = V_25 ;
F_24 ( V_6 , ( void * ) & V_111 ) ;
V_32 = F_37 ( & V_41 -> V_57 , V_6 ) ;
if ( ! V_32 )
V_41 -> V_108 [ V_108 -> V_67 ] = V_108 ;
else
F_47 ( & V_41 -> V_57 , L_16 ,
V_108 -> V_67 ) ;
return V_32 ;
}
static int F_63 ( struct V_40 * V_41 , struct V_112 * V_113 )
{
struct V_5 * V_6 ;
int V_32 ;
if ( F_10 ( V_113 -> V_114 >= V_115 || V_41 -> V_113 [ V_113 -> V_114 ] ) )
return - V_110 ;
V_6 = & V_113 -> V_116 . V_77 ;
V_6 -> V_19 = V_27 ;
F_24 ( V_6 , ( void * ) & V_111 ) ;
V_32 = F_37 ( & V_41 -> V_57 , V_6 ) ;
if ( ! V_32 ) {
if ( ! V_41 -> V_106 && V_113 -> V_99 )
V_41 -> V_106 = & V_113 -> V_99 -> V_63 ;
V_41 -> V_113 [ V_113 -> V_114 ] = V_113 ;
V_113 -> V_116 . V_117 = V_41 -> V_117 ;
} else {
F_47 ( & V_41 -> V_57 , L_17 ,
V_113 -> V_114 , V_32 ) ;
}
return V_32 ;
}
static int F_64 ( struct V_40 * V_41 ,
struct V_118 * V_99 ,
struct V_5 * V_6 )
{
struct V_65 * V_66 = V_99 -> V_63 . V_64 ;
int V_114 , V_32 ;
V_114 = V_66 ? F_56 ( V_66 ) : F_65 ( 0 , V_99 -> V_114 ) ;
if ( F_10 ( V_114 < 0 || V_114 >= V_119 ) )
return - V_120 ;
if ( F_10 ( V_41 -> V_121 [ V_114 ] . V_6 ) )
return - V_110 ;
V_6 -> V_19 = V_23 ;
V_32 = F_37 ( & V_41 -> V_57 , V_6 ) ;
if ( ! V_32 )
V_41 -> V_121 [ V_114 ] . V_6 = V_6 ;
else
F_47 ( & V_41 -> V_57 ,
L_18 , V_114 , V_32 ) ;
return V_32 ;
}
static int F_66 ( struct V_40 * V_41 , struct V_122 * V_123 )
{
struct V_5 * V_6 = & V_123 -> V_124 . V_77 ;
int V_32 ;
V_32 = F_37 ( & V_41 -> V_57 , V_6 ) ;
if ( V_32 ) {
F_47 ( & V_41 -> V_57 ,
L_19 , V_32 ) ;
return V_32 ;
}
V_41 -> V_122 = V_123 ;
return 0 ;
}
static int F_67 ( struct V_40 * V_41 ,
struct V_118 * V_99 ,
int V_125 )
{
struct V_126 * V_63 = & V_99 -> V_63 ;
int V_32 = - V_58 ;
void * V_127 ;
F_33 ( V_63 ) ;
if ( ! V_63 -> V_70 || ! F_34 ( V_63 -> V_70 -> V_71 ) )
goto V_128;
V_127 = F_68 ( V_63 ) ;
if ( V_127 ) {
switch ( V_125 ) {
case V_46 :
V_32 = F_63 ( V_41 , V_127 ) ;
break;
case V_26 :
V_32 = F_62 ( V_41 , V_127 ) ;
break;
case V_24 :
V_32 = F_64 ( V_41 , V_99 , V_127 ) ;
break;
case V_29 :
V_32 = F_66 ( V_41 , V_127 ) ;
break;
default:
V_32 = - V_47 ;
}
}
F_38 ( V_63 -> V_70 -> V_71 ) ;
V_128:
F_39 ( V_63 ) ;
if ( V_32 == - V_58 )
F_69 ( & V_41 -> V_99 -> V_63 , L_20 ,
F_70 ( V_63 ) ) ;
else if ( V_32 < 0 )
F_71 ( & V_41 -> V_99 -> V_63 , L_21 ,
F_70 ( V_63 ) , V_32 ) ;
return V_32 ;
}
static int F_72 ( struct V_126 * V_63 , void * V_129 )
{
struct V_118 * V_99 = F_73 ( V_63 ) ;
int V_125 = - 1 ;
int V_32 ;
char * V_2 ;
if ( ! F_74 ( V_63 ) )
return - V_47 ;
if ( ! strcmp ( V_99 -> V_60 , V_130 ) ) {
V_125 = V_24 ;
} else if ( ! strcmp ( V_99 -> V_60 , V_131 ) ) {
V_125 = V_26 ;
} else {
V_2 = strstr ( V_99 -> V_60 , L_22 ) ;
if ( V_2 && * ( V_2 + 4 ) == 0 )
V_125 = V_46 ;
}
if ( V_125 >= 0 )
V_32 = F_67 ( V_129 , V_99 ,
V_125 ) ;
F_40 ( V_63 ) ;
return 0 ;
}
static int F_75 ( struct V_40 * V_41 ,
struct V_65 * V_98 )
{
struct V_65 * V_66 ;
int V_32 = 0 ;
F_53 (parent, node) {
struct V_118 * V_99 ;
int V_125 = - 1 ;
V_99 = F_76 ( V_66 ) ;
if ( ! V_99 )
continue;
if ( ! strcmp ( V_66 -> V_60 , V_132 ) )
V_125 = V_24 ;
else if ( ! strcmp ( V_66 -> V_60 , V_133 ) )
V_125 = V_29 ;
else if ( ! strcmp ( V_66 -> V_60 , V_134 ) )
V_125 = V_26 ;
else if ( ! strcmp ( V_66 -> V_60 , V_135 ) &&
! F_77 ( V_66 , L_23 ) )
V_125 = V_46 ;
if ( V_125 >= 0 )
V_32 = F_67 ( V_41 , V_99 ,
V_125 ) ;
F_40 ( & V_99 -> V_63 ) ;
if ( V_32 < 0 )
break;
}
return V_32 ;
}
static void F_78 ( struct V_40 * V_41 )
{
int V_7 ;
for ( V_7 = 0 ; V_7 < V_115 ; V_7 ++ ) {
if ( V_41 -> V_113 [ V_7 ] == NULL )
continue;
F_28 ( & V_41 -> V_113 [ V_7 ] -> V_116 . V_77 ) ;
V_41 -> V_113 [ V_7 ] -> V_136 = NULL ;
V_41 -> V_113 [ V_7 ] = NULL ;
}
for ( V_7 = 0 ; V_7 < V_109 ; V_7 ++ ) {
if ( V_41 -> V_108 [ V_7 ] == NULL )
continue;
F_28 ( & V_41 -> V_108 [ V_7 ] -> V_77 ) ;
V_41 -> V_108 [ V_7 ] -> V_136 = NULL ;
V_41 -> V_108 [ V_7 ] = NULL ;
}
for ( V_7 = 0 ; V_7 < V_119 ; V_7 ++ ) {
if ( V_41 -> V_121 [ V_7 ] . V_6 == NULL )
continue;
F_28 ( V_41 -> V_121 [ V_7 ] . V_6 ) ;
V_41 -> V_121 [ V_7 ] . V_6 = NULL ;
}
for ( V_7 = 0 ; V_7 < V_41 -> V_78 ; V_7 ++ ) {
if ( V_41 -> V_69 [ V_7 ] . V_77 == NULL )
continue;
F_26 ( V_41 -> V_69 [ V_7 ] . V_77 ) ;
V_41 -> V_69 [ V_7 ] . V_77 = NULL ;
}
if ( V_41 -> V_122 )
F_28 ( & V_41 -> V_122 -> V_124 . V_77 ) ;
F_25 ( & V_41 -> V_57 , L_24 ) ;
}
static int F_79 ( struct V_40 * V_41 ,
struct V_3 * V_137 ,
struct V_5 * V_69 ,
int V_11 , int V_138 )
{
struct V_50 * V_51 = NULL ;
struct V_3 * V_139 ;
unsigned int V_15 = 0 ;
int V_7 , V_32 = 0 ;
if ( V_69 ) {
V_51 = F_80 ( V_69 ) ;
if ( V_51 && V_51 -> V_54 == V_76 )
V_32 = 1 ;
}
for ( V_7 = 0 ; ! V_32 && V_7 < V_115 ; V_7 ++ ) {
if ( ! V_41 -> V_113 [ V_7 ] )
continue;
if ( ! V_41 -> V_113 [ V_7 ] -> V_140 -> V_141 )
continue;
V_15 = ( ( 1 << V_7 ) & V_138 ) ? V_142 : 0 ;
V_139 = & V_41 -> V_113 [ V_7 ] -> V_116 . V_77 . V_17 ;
V_32 = F_81 ( V_137 , V_11 , V_139 ,
V_143 , V_15 ) ;
if ( V_32 )
return V_32 ;
V_32 = F_82 ( V_139 , V_144 , & V_139 -> V_14 [ 0 ] ,
& V_137 -> V_14 [ V_11 ] , V_15 ) ;
if ( V_32 )
break;
F_25 ( & V_41 -> V_57 , L_25 ,
V_137 -> V_60 , V_15 ? '=' : '-' , V_139 -> V_60 ) ;
if ( V_15 == 0 || V_69 == NULL )
continue;
if ( ! F_10 ( V_51 == NULL ) ) {
unsigned long V_145 ;
struct V_68 * V_146 = F_83 ( V_51 ) ;
F_84 ( & V_41 -> V_147 , V_145 ) ;
V_146 -> V_148 = V_41 -> V_113 [ V_7 ] ;
F_85 ( & V_41 -> V_147 , V_145 ) ;
}
}
for ( V_7 = 0 ; V_7 < V_109 ; V_7 ++ ) {
if ( ! V_41 -> V_108 [ V_7 ] )
continue;
V_139 = & V_41 -> V_108 [ V_7 ] -> V_77 . V_17 ;
V_32 = F_81 ( V_137 , V_11 , V_139 ,
V_149 , 0 ) ;
if ( V_32 )
return V_32 ;
V_32 = F_82 ( V_139 , V_144 , & V_139 -> V_14 [ 0 ] ,
& V_137 -> V_14 [ V_11 ] , 0 ) ;
if ( V_32 )
break;
F_25 ( & V_41 -> V_57 , L_26 ,
V_137 -> V_60 , V_139 -> V_60 ) ;
}
return 0 ;
}
static int F_86 ( struct V_40 * V_41 )
{
struct V_3 * V_137 , * V_139 ;
int V_7 , V_32 = 0 ;
for ( V_7 = 0 ; V_7 < V_109 ; V_7 ++ ) {
struct V_108 * V_113 = V_41 -> V_108 [ V_7 ] ;
if ( V_113 == NULL )
continue;
V_137 = & V_113 -> V_77 . V_17 ;
V_139 = & V_113 -> V_150 . V_17 ;
V_32 = F_81 ( V_137 , V_151 ,
V_139 , 0 , 0 ) ;
if ( V_32 )
break;
V_139 = & V_41 -> V_122 -> V_124 . V_77 . V_17 ;
V_32 = F_81 ( V_137 , V_152 ,
V_139 , 0 , 0 ) ;
if ( V_32 )
break;
}
return V_32 ;
}
static int F_87 ( struct V_40 * V_41 )
{
struct V_3 * V_137 , * V_139 ;
int V_7 , V_32 ;
V_137 = & V_41 -> V_122 -> V_124 . V_77 . V_17 ;
for ( V_7 = 0 ; V_7 < V_115 ; V_7 ++ ) {
if ( V_41 -> V_113 [ V_7 ] == NULL )
continue;
V_139 = & V_41 -> V_113 [ V_7 ] -> V_116 . V_77 . V_17 ;
V_32 = F_81 ( V_137 , V_153 ,
V_139 , V_154 , 0 ) ;
if ( V_32 )
return V_32 ;
}
return V_32 ;
}
static int F_88 ( struct V_40 * V_41 )
{
struct V_5 * V_155 [ V_119 ] = { NULL } ;
struct V_5 * V_69 , * V_121 ;
struct V_50 * V_74 ;
struct V_3 * V_137 , * V_139 ;
int V_7 , V_11 , V_156 = 0 , V_32 = 0 ;
T_2 V_15 , V_138 = 0 ;
for ( V_7 = 0 ; V_7 < V_41 -> V_78 ; V_7 ++ ) {
if ( V_41 -> V_69 [ V_7 ] . V_77 == NULL )
continue;
V_69 = V_41 -> V_69 [ V_7 ] . V_77 ;
V_74 = F_80 ( V_69 ) ;
if ( ! V_74 )
continue;
V_137 = NULL ;
switch ( V_74 -> V_55 ) {
case V_97 :
if ( F_89 ( V_74 -> V_88 >= V_119 ,
L_27 , V_74 -> V_88 ) )
return - V_42 ;
V_121 = V_41 -> V_121 [ V_74 -> V_88 ] . V_6 ;
if ( F_89 ( V_121 == NULL ,
L_28
L_29 ) )
return - V_42 ;
V_11 = V_69 -> V_17 . V_12 - 1 ;
V_32 = F_81 ( & V_69 -> V_17 , V_11 ,
& V_121 -> V_17 , V_157 ,
V_158 |
V_142 ) ;
if ( V_32 )
return V_32 ;
F_25 ( & V_41 -> V_57 , L_30 ,
V_69 -> V_17 . V_60 , V_121 -> V_17 . V_60 ) ;
V_137 = NULL ;
V_155 [ V_74 -> V_88 ] = V_69 ;
break;
case V_93 ... V_94 :
V_137 = & V_69 -> V_17 ;
V_11 = 0 ;
break;
default:
F_47 ( & V_41 -> V_57 , L_31 ,
V_74 -> V_55 ) ;
return - V_42 ;
}
if ( V_137 == NULL )
continue;
V_138 = 1 << V_156 ++ ;
V_32 = F_79 ( V_41 , V_137 , V_69 ,
V_11 , V_138 ) ;
}
for ( V_7 = 0 ; V_7 < V_119 ; V_7 ++ ) {
if ( V_41 -> V_121 [ V_7 ] . V_6 == NULL )
continue;
V_137 = & V_41 -> V_121 [ V_7 ] . V_6 -> V_17 ;
V_11 = V_159 ;
V_69 = V_155 [ V_7 ] ;
V_138 = 1 << V_156 ++ ;
V_32 = F_79 ( V_41 , V_137 , V_69 ,
V_11 , V_138 ) ;
}
V_15 = V_158 | V_142 ;
for ( V_7 = 0 ; V_7 < V_115 ; V_7 ++ ) {
if ( ! V_41 -> V_113 [ V_7 ] )
continue;
V_137 = & V_41 -> V_113 [ V_7 ] -> V_116 . V_77 . V_17 ;
V_139 = & V_41 -> V_113 [ V_7 ] -> V_116 . V_150 . V_17 ;
V_32 = F_81 ( V_137 , V_160 ,
V_139 , 0 , V_15 ) ;
if ( V_32 )
break;
}
V_32 = F_86 ( V_41 ) ;
if ( V_32 < 0 )
return V_32 ;
if ( V_41 -> V_161 )
V_32 = F_87 ( V_41 ) ;
return V_32 ;
}
static void F_90 ( struct V_40 * V_41 )
{
int V_7 = V_162 ;
while ( -- V_7 >= 0 ) {
if ( F_11 ( V_41 -> V_163 [ V_7 ] . clock ) )
continue;
F_91 ( V_41 -> V_163 [ V_7 ] . clock ) ;
F_92 ( V_41 -> V_163 [ V_7 ] . clock ) ;
V_41 -> V_163 [ V_7 ] . clock = F_20 ( - V_42 ) ;
}
for ( V_7 = 0 ; V_7 < V_164 ; V_7 ++ ) {
if ( F_11 ( V_41 -> V_43 [ V_7 ] ) )
continue;
F_92 ( V_41 -> V_43 [ V_7 ] ) ;
V_41 -> V_43 [ V_7 ] = F_20 ( - V_42 ) ;
}
}
static int F_93 ( struct V_40 * V_41 )
{
struct V_126 * V_63 = NULL ;
char V_165 [ 32 ] ;
struct V_166 * clock ;
int V_32 , V_7 ;
for ( V_7 = 0 ; V_7 < V_162 ; V_7 ++ )
V_41 -> V_163 [ V_7 ] . clock = F_20 ( - V_42 ) ;
if ( V_41 -> V_99 -> V_63 . V_64 )
V_63 = & V_41 -> V_99 -> V_63 ;
for ( V_7 = 0 ; V_7 < V_162 ; V_7 ++ ) {
snprintf ( V_165 , sizeof( V_165 ) , L_32 , V_7 ) ;
clock = F_94 ( V_63 , V_165 ) ;
if ( F_11 ( clock ) ) {
F_71 ( & V_41 -> V_99 -> V_63 , L_33 ,
V_165 ) ;
V_32 = F_60 ( clock ) ;
break;
}
V_32 = F_95 ( clock ) ;
if ( V_32 < 0 ) {
F_92 ( clock ) ;
V_41 -> V_163 [ V_7 ] . clock = F_20 ( - V_42 ) ;
break;
}
V_41 -> V_163 [ V_7 ] . clock = clock ;
}
if ( V_32 )
F_90 ( V_41 ) ;
if ( ! V_41 -> V_161 )
return 0 ;
V_41 -> V_43 [ V_167 ] = F_20 ( - V_42 ) ;
for ( V_7 = V_44 ; V_7 < V_164 ; V_7 ++ ) {
snprintf ( V_165 , sizeof( V_165 ) , L_34 , V_7 ) ;
clock = F_94 ( V_63 , V_165 ) ;
if ( F_11 ( clock ) ) {
F_47 ( & V_41 -> V_57 , L_33 ,
V_165 ) ;
V_32 = F_60 ( clock ) ;
break;
}
V_41 -> V_43 [ V_7 ] = clock ;
}
if ( V_32 )
F_90 ( V_41 ) ;
return V_32 ;
}
static int F_35 ( struct V_40 * V_41 ,
struct V_50 * V_51 ,
bool V_30 )
{
struct V_168 * V_163 ;
int V_32 = 0 ;
if ( F_10 ( V_51 -> V_89 >= V_162 ) || ! V_41 || ! V_41 -> V_106 )
return - V_42 ;
V_163 = & V_41 -> V_163 [ V_51 -> V_89 ] ;
F_96 ( L_35 ,
V_51 -> V_89 , V_51 -> V_90 , V_163 -> V_31 , V_30 ) ;
if ( V_30 ) {
if ( V_163 -> V_31 > 0 &&
V_163 -> V_169 != V_51 -> V_90 )
return - V_42 ;
if ( V_163 -> V_31 ++ == 0 ) {
F_97 ( V_163 -> clock , V_51 -> V_90 ) ;
V_163 -> V_169 = V_51 -> V_90 ;
V_32 = F_58 ( V_41 -> V_106 ) ;
if ( V_32 < 0 )
return V_32 ;
V_32 = F_98 ( V_163 -> clock ) ;
F_96 ( L_36 , V_51 -> V_89 ,
F_99 ( V_163 -> clock ) ) ;
}
return V_32 ;
}
if ( F_10 ( V_163 -> V_31 == 0 ) )
return 0 ;
if ( -- V_163 -> V_31 == 0 ) {
F_100 ( V_163 -> clock ) ;
F_61 ( V_41 -> V_106 ) ;
F_96 ( L_37 , V_51 -> V_89 ) ;
}
return V_32 ;
}
int F_13 ( struct V_5 * V_6 , bool V_30 )
{
struct V_50 * V_51 = F_80 ( V_6 ) ;
struct V_40 * V_41 = F_9 ( & V_6 -> V_17 ) ;
return F_35 ( V_41 , V_51 , V_30 ) ;
}
static int F_101 ( struct V_10 * V_137 ,
struct V_10 * V_139 , T_2 V_15 )
{
struct V_108 * V_108 = NULL ;
struct V_112 * V_113 = NULL ;
struct V_1 * V_170 ;
struct V_5 * V_6 ;
struct V_171 * V_172 ;
int V_7 , V_32 = 0 ;
int V_173 ;
if ( F_3 ( V_139 -> V_17 ) != V_18 )
return 0 ;
V_6 = F_4 ( V_139 -> V_17 ) ;
switch ( V_6 -> V_19 ) {
case V_25 :
V_108 = F_27 ( V_6 ) ;
if ( F_10 ( V_108 == NULL ) )
return 0 ;
V_170 = & V_108 -> V_170 ;
V_172 = & V_108 -> V_172 ;
break;
case V_27 :
V_113 = F_27 ( V_6 ) ;
if ( F_10 ( V_113 == NULL ) )
return 0 ;
V_170 = & V_113 -> V_170 ;
V_172 = & V_113 -> V_172 ;
break;
default:
return 0 ;
}
F_102 ( V_172 ) ;
V_173 = V_113 ? V_113 -> V_116 . V_174 : V_108 -> V_173 ;
if ( ! ( V_15 & V_142 ) ) {
if ( V_173 > 0 ) {
V_32 = F_15 ( V_170 ) ;
if ( ! V_32 && V_113 )
F_103 ( V_113 -> V_116 . V_175 ) ;
}
for ( V_7 = 0 ; V_7 < V_8 ; V_7 ++ )
V_170 -> V_9 [ V_7 ] = NULL ;
} else if ( V_173 > 0 ) {
V_32 = F_8 ( V_170 ,
V_137 -> V_17 , true ) ;
if ( ! V_32 && V_113 )
V_32 = F_104 ( V_113 ) ;
}
F_105 ( V_172 ) ;
return V_32 ? - V_176 : V_32 ;
}
static T_3 F_106 ( struct V_126 * V_63 ,
struct V_177 * V_178 , char * V_179 )
{
struct V_118 * V_99 = F_73 ( V_63 ) ;
struct V_40 * V_41 = F_107 ( V_99 ) ;
if ( V_41 -> V_117 )
return F_108 ( V_179 , L_38 , V_180 ) ;
return F_108 ( V_179 , L_39 , V_180 ) ;
}
static T_3 F_109 ( struct V_126 * V_63 ,
struct V_177 * V_178 ,
const char * V_179 , T_4 V_181 )
{
struct V_118 * V_99 = F_73 ( V_63 ) ;
struct V_40 * V_41 = F_107 ( V_99 ) ;
bool V_182 ;
int V_7 ;
if ( ! strcmp ( V_179 , L_40 ) )
V_182 = false ;
else if ( ! strcmp ( V_179 , L_41 ) )
V_182 = true ;
else
return V_181 ;
V_41 -> V_117 = V_182 ;
for ( V_7 = 0 ; V_7 < V_115 ; V_7 ++ )
if ( V_41 -> V_113 [ V_7 ] )
V_41 -> V_113 [ V_7 ] -> V_116 . V_117 = V_182 ;
return V_181 ;
}
static int F_110 ( struct V_40 * V_41 )
{
struct V_126 * V_63 = & V_41 -> V_99 -> V_63 ;
struct V_183 * V_184 = & V_41 -> V_185 ;
V_184 -> V_186 = F_111 ( V_63 ) ;
if ( F_11 ( V_184 -> V_186 ) )
return F_60 ( V_184 -> V_186 ) ;
V_184 -> V_187 = F_112 ( V_184 -> V_186 ,
V_188 ) ;
if ( F_11 ( V_184 -> V_187 ) )
return F_60 ( V_184 -> V_187 ) ;
V_184 -> V_189 = F_112 ( V_184 -> V_186 ,
V_190 ) ;
return 0 ;
}
static int F_113 ( struct V_118 * V_99 )
{
struct V_126 * V_63 = & V_99 -> V_63 ;
struct V_191 * V_57 ;
struct V_40 * V_41 ;
int V_32 ;
V_41 = F_114 ( V_63 , sizeof( * V_41 ) , V_192 ) ;
if ( ! V_41 )
return - V_193 ;
F_115 ( & V_41 -> V_147 ) ;
V_41 -> V_99 = V_99 ;
F_108 ( V_41 -> V_194 . V_195 , L_42 ,
sizeof( V_41 -> V_194 . V_195 ) ) ;
V_41 -> V_194 . V_196 = F_101 ;
V_41 -> V_194 . V_63 = V_63 ;
V_57 = & V_41 -> V_57 ;
V_57 -> V_197 = & V_41 -> V_194 ;
V_57 -> V_198 = V_199 ;
F_108 ( V_57 -> V_60 , L_43 , sizeof( V_57 -> V_60 ) ) ;
V_41 -> V_161 = F_116 ( V_63 -> V_64 ) ;
V_32 = F_117 ( V_63 , & V_41 -> V_57 ) ;
if ( V_32 < 0 ) {
F_47 ( V_57 , L_44 , V_32 ) ;
return V_32 ;
}
V_32 = F_118 ( & V_41 -> V_194 ) ;
if ( V_32 < 0 ) {
F_47 ( V_57 , L_45 , V_32 ) ;
goto V_200;
}
V_32 = F_93 ( V_41 ) ;
if ( V_32 )
goto V_201;
V_41 -> V_117 = ( V_63 -> V_64 != NULL ) ;
F_102 ( & V_41 -> V_194 . V_202 ) ;
V_32 = F_110 ( V_41 ) ;
if ( V_32 < 0 ) {
if ( V_32 != V_58 )
F_71 ( V_63 , L_46 , V_32 ) ;
goto V_203;
}
if ( V_63 -> V_64 )
V_32 = F_75 ( V_41 , V_63 -> V_64 ) ;
else
V_32 = F_119 ( & V_204 , NULL , V_41 ,
F_72 ) ;
if ( V_32 )
goto V_203;
if ( V_63 -> V_104 || V_63 -> V_64 ) {
V_32 = F_57 ( V_41 ) ;
if ( V_32 )
goto V_203;
}
V_32 = F_88 ( V_41 ) ;
if ( V_32 )
goto V_203;
V_32 = F_120 ( & V_41 -> V_57 ) ;
if ( V_32 )
goto V_203;
V_32 = F_121 ( & V_99 -> V_63 , & V_205 ) ;
if ( V_32 )
goto V_203;
F_122 ( V_99 , V_41 ) ;
F_105 ( & V_41 -> V_194 . V_202 ) ;
return 0 ;
V_203:
F_105 ( & V_41 -> V_194 . V_202 ) ;
V_201:
F_123 ( & V_41 -> V_194 ) ;
F_90 ( V_41 ) ;
F_78 ( V_41 ) ;
V_200:
F_124 ( & V_41 -> V_57 ) ;
return V_32 ;
}
static int F_125 ( struct V_118 * V_99 )
{
struct V_40 * V_41 = F_107 ( V_99 ) ;
if ( ! V_41 )
return 0 ;
F_126 ( & V_99 -> V_63 , & V_205 ) ;
F_78 ( V_41 ) ;
F_123 ( & V_41 -> V_194 ) ;
F_90 ( V_41 ) ;
return 0 ;
}
static int T_5 F_127 ( void )
{
int V_32 ;
F_128 ( L_47 ) ;
V_32 = F_129 () ;
if ( V_32 )
return V_32 ;
return F_130 ( & V_206 ) ;
}
static void T_6 F_131 ( void )
{
F_132 ( & V_206 ) ;
F_133 () ;
}
