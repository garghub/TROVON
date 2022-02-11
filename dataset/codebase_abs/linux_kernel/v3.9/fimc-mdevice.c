static void F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = & V_4 -> V_7 [ 0 ] ;
struct V_8 * V_9 ;
int V_10 ;
for ( V_10 = 0 ; V_10 < V_11 ; V_10 ++ )
V_2 -> V_12 [ V_10 ] = NULL ;
while ( 1 ) {
if ( ! ( V_6 -> V_13 & V_14 ) )
break;
V_6 = F_2 ( V_6 ) ;
if ( V_6 == NULL ||
F_3 ( V_6 -> V_15 ) != V_16 )
break;
V_9 = F_4 ( V_6 -> V_15 ) ;
switch ( V_9 -> V_17 ) {
case V_18 :
case V_19 :
V_2 -> V_12 [ V_20 ] = V_9 ;
break;
case V_21 :
V_2 -> V_12 [ V_22 ] = V_9 ;
break;
case V_23 :
V_2 -> V_12 [ V_24 ] = V_9 ;
break;
case V_25 :
break;
default:
F_5 ( L_1 ,
V_26 , V_9 -> V_17 ) ;
}
V_6 = & V_9 -> V_15 . V_7 [ 0 ] ;
}
}
static int F_6 ( struct V_8 * V_9 , int V_27 )
{
int * V_28 ;
int V_29 ;
if ( V_9 == NULL )
return - V_30 ;
V_28 = & V_9 -> V_15 . V_28 ;
if ( V_27 && ( * V_28 ) ++ > 0 )
return 0 ;
else if ( ! V_27 && ( * V_28 == 0 || -- ( * V_28 ) > 0 ) )
return 0 ;
V_29 = F_7 ( V_9 , V_31 , V_32 , V_27 ) ;
return V_29 != - V_33 ? V_29 : 0 ;
}
static int F_8 ( struct V_1 * V_2 , bool V_34 )
{
unsigned int V_10 ;
int V_29 ;
if ( V_2 -> V_12 [ V_20 ] == NULL )
return - V_30 ;
for ( V_10 = 0 ; V_10 < V_11 ; V_10 ++ ) {
unsigned int V_35 = V_34 ? ( V_11 - 1 ) - V_10 : V_10 ;
V_29 = F_6 ( V_2 -> V_12 [ V_35 ] , V_34 ) ;
if ( V_29 < 0 && V_29 != - V_30 )
return V_29 ;
}
return 0 ;
}
static int F_9 ( struct V_1 * V_2 ,
struct V_3 * V_4 , bool V_36 )
{
int V_29 ;
if ( V_36 )
F_1 ( V_2 , V_4 ) ;
if ( V_2 -> V_12 [ V_20 ] == NULL )
return - V_37 ;
V_29 = F_10 ( V_2 -> V_12 [ V_20 ] , true ) ;
if ( V_29 )
return V_29 ;
return F_8 ( V_2 , 1 ) ;
}
static int F_11 ( struct V_1 * V_2 )
{
int V_29 = 0 ;
if ( ! V_2 || ! V_2 -> V_12 [ V_20 ] )
return - V_37 ;
if ( V_2 -> V_12 [ V_20 ] ) {
V_29 = F_8 ( V_2 , 0 ) ;
F_10 ( V_2 -> V_12 [ V_20 ] , false ) ;
}
return V_29 == - V_30 ? 0 : V_29 ;
}
static int F_12 ( struct V_1 * V_2 , bool V_27 )
{
int V_10 , V_29 ;
if ( V_2 -> V_12 [ V_20 ] == NULL )
return - V_38 ;
for ( V_10 = 0 ; V_10 < V_11 ; V_10 ++ ) {
unsigned int V_35 = V_27 ? ( V_11 - 1 ) - V_10 : V_10 ;
V_29 = F_7 ( V_2 -> V_12 [ V_35 ] , V_39 , V_40 , V_27 ) ;
if ( V_29 < 0 && V_29 != - V_33 && V_29 != - V_38 )
return V_29 ;
}
return 0 ;
}
static struct V_8 * F_13 ( struct V_41 * V_42 ,
struct V_43 * V_44 )
{
struct V_45 * V_46 ;
struct V_8 * V_9 = NULL ;
if ( ! V_44 || ! V_42 )
return NULL ;
V_46 = F_14 ( V_44 -> V_47 . V_48 ) ;
if ( ! V_46 ) {
F_15 ( & V_42 -> V_49 ,
L_2 ,
V_44 -> V_47 . V_48 ) ;
return F_16 ( - V_50 ) ;
}
V_9 = F_17 ( & V_42 -> V_49 , V_46 ,
V_44 -> V_47 . V_51 , NULL ) ;
if ( F_18 ( V_9 ) ) {
F_19 ( V_46 ) ;
F_15 ( & V_42 -> V_49 ,
L_3 ,
V_44 -> V_47 . V_51 -> type ) ;
return F_16 ( - V_50 ) ;
}
F_20 ( V_9 , V_44 ) ;
V_9 -> V_17 = V_19 ;
F_21 ( & V_42 -> V_49 , L_4 ,
V_44 -> V_47 . V_51 -> type ) ;
return V_9 ;
}
static void F_22 ( struct V_8 * V_9 )
{
struct V_52 * V_53 = F_23 ( V_9 ) ;
struct V_45 * V_46 ;
if ( ! V_53 )
return;
F_24 ( V_9 ) ;
V_46 = V_53 -> V_46 ;
F_25 ( V_53 ) ;
if ( V_46 )
F_19 ( V_46 ) ;
}
static int F_26 ( struct V_41 * V_42 )
{
struct V_54 * V_47 = V_42 -> V_55 -> V_56 . V_57 ;
struct V_58 * V_59 = NULL ;
int V_60 , V_29 , V_10 ;
for ( V_10 = 0 ; ! V_59 && V_10 < F_27 ( V_42 -> V_61 ) ; V_10 ++ )
if ( V_42 -> V_61 [ V_10 ] )
V_59 = V_42 -> V_61 [ V_10 ] ;
if ( ! V_59 )
return - V_30 ;
V_29 = F_28 ( & V_59 -> V_55 -> V_56 ) ;
if ( V_29 < 0 )
return V_29 ;
F_29 ( V_47 -> V_60 > F_27 ( V_42 -> V_62 ) ) ;
V_60 = F_30 ( V_63 , V_47 -> V_60 , F_27 ( V_42 -> V_62 ) ) ;
V_42 -> V_64 = V_60 ;
for ( V_10 = 0 ; V_10 < V_60 ; V_10 ++ ) {
struct V_8 * V_9 ;
V_42 -> V_62 [ V_10 ] . V_47 = V_47 -> V_65 [ V_10 ] ;
V_29 = F_31 ( V_42 , & V_42 -> V_62 [ V_10 ] , true ) ;
if ( V_29 )
break;
V_9 = F_13 ( V_42 , & V_42 -> V_62 [ V_10 ] ) ;
V_29 = F_31 ( V_42 , & V_42 -> V_62 [ V_10 ] , false ) ;
if ( ! F_32 ( V_9 ) ) {
V_42 -> V_62 [ V_10 ] . V_66 = V_9 ;
} else {
V_42 -> V_62 [ V_10 ] . V_66 = NULL ;
V_29 = F_33 ( V_9 ) ;
break;
}
if ( V_29 )
break;
}
F_34 ( & V_59 -> V_55 -> V_56 ) ;
return V_29 ;
}
static int F_35 ( struct V_41 * V_42 ,
struct V_67 * V_67 )
{
struct V_8 * V_9 ;
int V_29 ;
if ( F_29 ( V_67 -> V_68 >= V_69 ||
V_42 -> V_67 [ V_67 -> V_68 ] ) )
return - V_70 ;
V_9 = & V_67 -> V_66 ;
V_9 -> V_17 = V_23 ;
F_20 ( V_9 , ( void * ) & V_71 ) ;
V_29 = F_36 ( & V_42 -> V_49 , V_9 ) ;
if ( ! V_29 )
V_42 -> V_67 [ V_67 -> V_68 ] = V_67 ;
else
F_37 ( & V_42 -> V_49 , L_5 ,
V_67 -> V_68 ) ;
return V_29 ;
}
static int F_38 ( struct V_41 * V_42 , struct V_58 * V_61 )
{
struct V_8 * V_9 ;
int V_29 ;
if ( F_29 ( V_61 -> V_72 >= V_73 || V_42 -> V_61 [ V_61 -> V_72 ] ) )
return - V_70 ;
V_9 = & V_61 -> V_74 . V_66 ;
V_9 -> V_17 = V_25 ;
F_20 ( V_9 , ( void * ) & V_71 ) ;
V_29 = F_36 ( & V_42 -> V_49 , V_9 ) ;
if ( ! V_29 ) {
V_42 -> V_61 [ V_61 -> V_72 ] = V_61 ;
V_61 -> V_74 . V_75 = V_42 -> V_75 ;
} else {
F_37 ( & V_42 -> V_49 , L_6 ,
V_61 -> V_72 , V_29 ) ;
}
return V_29 ;
}
static int F_39 ( struct V_41 * V_42 ,
struct V_76 * V_55 ,
struct V_8 * V_9 )
{
struct V_77 * V_78 = V_55 -> V_56 . V_79 ;
int V_72 , V_29 ;
V_72 = V_78 ? F_40 ( V_78 , L_7 ) : F_41 ( 0 , V_55 -> V_72 ) ;
if ( F_29 ( V_72 >= V_80 || V_42 -> V_81 [ V_72 ] . V_9 ) )
return - V_70 ;
if ( F_29 ( V_72 >= V_80 ) )
return 0 ;
V_9 -> V_17 = V_21 ;
V_29 = F_36 ( & V_42 -> V_49 , V_9 ) ;
if ( ! V_29 )
V_42 -> V_81 [ V_72 ] . V_9 = V_9 ;
else
F_37 ( & V_42 -> V_49 ,
L_8 , V_72 , V_29 ) ;
return V_29 ;
}
static int F_42 ( struct V_41 * V_42 ,
struct V_76 * V_55 ,
int V_82 )
{
struct V_83 * V_56 = & V_55 -> V_56 ;
int V_29 = - V_50 ;
void * V_84 ;
F_43 ( V_56 ) ;
if ( ! V_56 -> V_85 || ! F_44 ( V_56 -> V_85 -> V_86 ) )
goto V_87;
V_84 = F_45 ( V_56 ) ;
if ( V_84 ) {
switch ( V_82 ) {
case V_88 :
V_29 = F_38 ( V_42 , V_84 ) ;
break;
case V_24 :
V_29 = F_35 ( V_42 , V_84 ) ;
break;
case V_22 :
V_29 = F_39 ( V_42 , V_55 , V_84 ) ;
break;
default:
V_29 = - V_38 ;
}
}
F_46 ( V_56 -> V_85 -> V_86 ) ;
V_87:
F_47 ( V_56 ) ;
if ( V_29 == - V_50 )
F_48 ( & V_42 -> V_55 -> V_56 , L_9 ,
F_49 ( V_56 ) ) ;
else if ( V_29 < 0 )
F_50 ( & V_42 -> V_55 -> V_56 , L_10 ,
F_49 ( V_56 ) , V_29 ) ;
return V_29 ;
}
static int F_51 ( struct V_83 * V_56 , void * V_89 )
{
struct V_76 * V_55 = F_52 ( V_56 ) ;
int V_82 = - 1 ;
int V_29 ;
char * V_2 ;
if ( ! F_53 ( V_56 ) )
return - V_38 ;
if ( ! strcmp ( V_55 -> V_90 , V_91 ) ) {
V_82 = V_22 ;
} else if ( ! strcmp ( V_55 -> V_90 , V_92 ) ) {
V_82 = V_24 ;
} else {
V_2 = strstr ( V_55 -> V_90 , L_11 ) ;
if ( V_2 && * ( V_2 + 4 ) == 0 )
V_82 = V_88 ;
}
if ( V_82 >= 0 )
V_29 = F_42 ( V_89 , V_55 ,
V_82 ) ;
F_54 ( V_56 ) ;
return 0 ;
}
static void F_55 ( struct V_41 * V_42 )
{
int V_10 ;
for ( V_10 = 0 ; V_10 < V_73 ; V_10 ++ ) {
if ( V_42 -> V_61 [ V_10 ] == NULL )
continue;
F_24 ( & V_42 -> V_61 [ V_10 ] -> V_74 . V_66 ) ;
V_42 -> V_61 [ V_10 ] -> V_93 = NULL ;
V_42 -> V_61 [ V_10 ] = NULL ;
}
for ( V_10 = 0 ; V_10 < V_69 ; V_10 ++ ) {
if ( V_42 -> V_67 [ V_10 ] == NULL )
continue;
F_24 ( & V_42 -> V_67 [ V_10 ] -> V_66 ) ;
V_42 -> V_67 [ V_10 ] -> V_93 = NULL ;
V_42 -> V_67 [ V_10 ] = NULL ;
}
for ( V_10 = 0 ; V_10 < V_80 ; V_10 ++ ) {
if ( V_42 -> V_81 [ V_10 ] . V_9 == NULL )
continue;
F_24 ( V_42 -> V_81 [ V_10 ] . V_9 ) ;
F_46 ( V_42 -> V_81 [ V_10 ] . V_9 -> V_86 ) ;
V_42 -> V_81 [ V_10 ] . V_9 = NULL ;
}
for ( V_10 = 0 ; V_10 < V_42 -> V_64 ; V_10 ++ ) {
if ( V_42 -> V_62 [ V_10 ] . V_66 == NULL )
continue;
F_22 ( V_42 -> V_62 [ V_10 ] . V_66 ) ;
V_42 -> V_62 [ V_10 ] . V_66 = NULL ;
}
F_21 ( & V_42 -> V_49 , L_12 ) ;
}
static int F_56 ( struct V_41 * V_42 ,
struct V_3 * V_94 ,
struct V_8 * V_62 ,
int V_6 , int V_95 )
{
struct V_43 * V_44 = NULL ;
struct V_3 * V_96 ;
unsigned int V_13 = 0 ;
int V_29 , V_10 ;
for ( V_10 = 0 ; V_10 < V_73 ; V_10 ++ ) {
if ( ! V_42 -> V_61 [ V_10 ] )
continue;
if ( ! V_42 -> V_61 [ V_10 ] -> V_97 -> V_98 )
continue;
V_13 = ( ( 1 << V_10 ) & V_95 ) ? V_99 : 0 ;
V_96 = & V_42 -> V_61 [ V_10 ] -> V_74 . V_66 . V_15 ;
V_29 = F_57 ( V_94 , V_6 , V_96 ,
V_100 , V_13 ) ;
if ( V_29 )
return V_29 ;
V_29 = F_58 ( V_96 , V_101 , & V_96 -> V_7 [ 0 ] ,
& V_94 -> V_7 [ V_6 ] , V_13 ) ;
if ( V_29 )
break;
F_21 ( & V_42 -> V_49 , L_13 ,
V_94 -> V_90 , V_13 ? '=' : '-' , V_96 -> V_90 ) ;
if ( V_13 == 0 || V_62 == NULL )
continue;
V_44 = F_59 ( V_62 ) ;
if ( ! F_29 ( V_44 == NULL ) ) {
unsigned long V_102 ;
F_60 ( & V_42 -> V_103 , V_102 ) ;
V_44 -> V_104 = V_42 -> V_61 [ V_10 ] ;
F_61 ( & V_42 -> V_103 , V_102 ) ;
}
}
for ( V_10 = 0 ; V_10 < V_69 ; V_10 ++ ) {
if ( ! V_42 -> V_67 [ V_10 ] )
continue;
if ( V_95 & ( 1 << ( V_10 + V_73 ) ) )
V_13 = V_99 ;
else
V_13 = 0 ;
V_96 = & V_42 -> V_67 [ V_10 ] -> V_66 . V_15 ;
V_29 = F_57 ( V_94 , V_6 , V_96 ,
V_105 , V_13 ) ;
if ( V_29 )
return V_29 ;
V_29 = F_58 ( V_96 , V_101 , & V_96 -> V_7 [ 0 ] ,
& V_94 -> V_7 [ V_6 ] , V_13 ) ;
if ( V_29 )
break;
F_21 ( & V_42 -> V_49 , L_13 ,
V_94 -> V_90 , V_13 ? '=' : '-' , V_96 -> V_90 ) ;
}
return 0 ;
}
static int F_62 ( struct V_41 * V_42 )
{
struct V_3 * V_94 , * V_96 ;
unsigned int V_13 = V_99 ;
int V_10 , V_29 = 0 ;
for ( V_10 = 0 ; V_10 < V_69 ; V_10 ++ ) {
struct V_67 * V_61 = V_42 -> V_67 [ V_10 ] ;
if ( V_61 == NULL )
continue;
V_94 = & V_61 -> V_66 . V_15 ;
V_96 = & V_61 -> V_106 . V_15 ;
V_29 = F_57 ( V_94 , V_107 ,
V_96 , 0 , V_13 ) ;
if ( V_29 )
break;
}
return V_29 ;
}
static int F_63 ( struct V_41 * V_42 )
{
struct V_8 * V_108 [ V_80 ] = { NULL } ;
struct V_8 * V_62 , * V_81 ;
struct V_109 * V_47 ;
struct V_43 * V_44 ;
struct V_3 * V_94 , * V_96 ;
int V_10 , V_6 , V_110 = 0 , V_29 = 0 ;
V_63 V_13 , V_95 = 0 ;
for ( V_10 = 0 ; V_10 < V_42 -> V_64 ; V_10 ++ ) {
if ( V_42 -> V_62 [ V_10 ] . V_66 == NULL )
continue;
V_62 = V_42 -> V_62 [ V_10 ] . V_66 ;
V_44 = F_59 ( V_62 ) ;
if ( ! V_44 )
continue;
V_94 = NULL ;
V_47 = & V_44 -> V_47 ;
switch ( V_47 -> V_111 ) {
case V_112 :
if ( F_64 ( V_47 -> V_113 >= V_80 ,
L_14 , V_47 -> V_113 ) )
return - V_37 ;
V_81 = V_42 -> V_81 [ V_47 -> V_113 ] . V_9 ;
if ( F_64 ( V_81 == NULL ,
L_15
L_16 ) )
return - V_37 ;
V_6 = V_62 -> V_15 . V_114 - 1 ;
V_29 = F_57 ( & V_62 -> V_15 , V_6 ,
& V_81 -> V_15 , V_115 ,
V_116 |
V_99 ) ;
if ( V_29 )
return V_29 ;
F_21 ( & V_42 -> V_49 , L_17 ,
V_62 -> V_15 . V_90 , V_81 -> V_15 . V_90 ) ;
V_94 = NULL ;
V_108 [ V_47 -> V_113 ] = V_62 ;
break;
case V_117 ... V_118 :
V_94 = & V_62 -> V_15 ;
V_6 = 0 ;
break;
default:
F_37 ( & V_42 -> V_49 , L_18 ,
V_47 -> V_111 ) ;
return - V_37 ;
}
if ( V_94 == NULL )
continue;
V_95 = 1 << V_110 ++ ;
V_29 = F_56 ( V_42 , V_94 , V_62 ,
V_6 , V_95 ) ;
}
for ( V_10 = 0 ; V_10 < V_80 ; V_10 ++ ) {
if ( V_42 -> V_81 [ V_10 ] . V_9 == NULL )
continue;
V_94 = & V_42 -> V_81 [ V_10 ] . V_9 -> V_15 ;
V_6 = V_119 ;
V_62 = V_108 [ V_10 ] ;
V_95 = 1 << V_110 ++ ;
V_29 = F_56 ( V_42 , V_94 , V_62 ,
V_6 , V_95 ) ;
}
V_13 = V_116 | V_99 ;
for ( V_10 = 0 ; V_10 < V_73 ; V_10 ++ ) {
if ( ! V_42 -> V_61 [ V_10 ] )
continue;
V_94 = & V_42 -> V_61 [ V_10 ] -> V_74 . V_66 . V_15 ;
V_96 = & V_42 -> V_61 [ V_10 ] -> V_74 . V_106 . V_15 ;
V_29 = F_57 ( V_94 , V_120 ,
V_96 , 0 , V_13 ) ;
if ( V_29 )
break;
}
return F_62 ( V_42 ) ;
}
static void F_65 ( struct V_41 * V_42 )
{
int V_10 = V_121 ;
while ( -- V_10 >= 0 ) {
if ( F_32 ( V_42 -> V_122 [ V_10 ] . clock ) )
continue;
F_66 ( V_42 -> V_122 [ V_10 ] . clock ) ;
F_67 ( V_42 -> V_122 [ V_10 ] . clock ) ;
V_42 -> V_122 [ V_10 ] . clock = F_16 ( - V_37 ) ;
}
}
static int F_68 ( struct V_41 * V_42 )
{
struct V_83 * V_56 = NULL ;
char V_123 [ 32 ] ;
struct V_124 * clock ;
int V_29 , V_10 ;
for ( V_10 = 0 ; V_10 < V_121 ; V_10 ++ )
V_42 -> V_122 [ V_10 ] . clock = F_16 ( - V_37 ) ;
if ( V_42 -> V_55 -> V_56 . V_79 )
V_56 = & V_42 -> V_55 -> V_56 ;
for ( V_10 = 0 ; V_10 < V_121 ; V_10 ++ ) {
snprintf ( V_123 , sizeof( V_123 ) , L_19 , V_10 ) ;
clock = F_69 ( V_56 , V_123 ) ;
if ( F_32 ( clock ) ) {
F_50 ( & V_42 -> V_55 -> V_56 , L_20 ,
V_123 ) ;
V_29 = F_33 ( clock ) ;
break;
}
V_29 = F_70 ( clock ) ;
if ( V_29 < 0 ) {
F_67 ( clock ) ;
V_42 -> V_122 [ V_10 ] . clock = F_16 ( - V_37 ) ;
break;
}
V_42 -> V_122 [ V_10 ] . clock = clock ;
}
if ( V_29 )
F_65 ( V_42 ) ;
return V_29 ;
}
static int F_31 ( struct V_41 * V_42 ,
struct V_43 * V_44 ,
bool V_27 )
{
struct V_109 * V_47 = & V_44 -> V_47 ;
struct V_125 * V_122 ;
int V_29 = 0 ;
if ( F_29 ( V_47 -> V_126 >= V_121 ) || V_42 == NULL )
return - V_37 ;
V_122 = & V_42 -> V_122 [ V_47 -> V_126 ] ;
F_71 ( L_21 ,
V_47 -> V_126 , V_47 -> V_127 , V_122 -> V_28 , V_27 ) ;
if ( V_27 ) {
if ( V_122 -> V_28 > 0 &&
V_122 -> V_128 != V_47 -> V_127 )
return - V_37 ;
if ( V_122 -> V_28 ++ == 0 ) {
F_72 ( V_122 -> clock , V_47 -> V_127 ) ;
V_122 -> V_128 = V_47 -> V_127 ;
V_29 = F_73 ( V_122 -> clock ) ;
F_71 ( L_22 , V_47 -> V_126 ,
F_74 ( V_122 -> clock ) ) ;
}
return V_29 ;
}
if ( F_29 ( V_122 -> V_28 == 0 ) )
return 0 ;
if ( -- V_122 -> V_28 == 0 ) {
F_75 ( V_122 -> clock ) ;
F_71 ( L_23 , V_47 -> V_126 ) ;
}
return V_29 ;
}
int F_10 ( struct V_8 * V_9 , bool V_27 )
{
struct V_43 * V_44 = F_59 ( V_9 ) ;
struct V_41 * V_42 = F_76 ( & V_9 -> V_15 ) ;
return F_31 ( V_42 , V_44 , V_27 ) ;
}
static int F_77 ( struct V_5 * V_94 ,
struct V_5 * V_96 , V_63 V_13 )
{
struct V_67 * V_67 = NULL ;
struct V_58 * V_61 = NULL ;
struct V_1 * V_129 ;
struct V_8 * V_9 ;
struct V_130 * V_131 ;
int V_10 , V_29 = 0 ;
int V_132 ;
if ( F_3 ( V_96 -> V_15 ) != V_16 )
return 0 ;
V_9 = F_4 ( V_96 -> V_15 ) ;
switch ( V_9 -> V_17 ) {
case V_23 :
V_67 = F_23 ( V_9 ) ;
if ( F_29 ( V_67 == NULL ) )
return 0 ;
V_129 = & V_67 -> V_129 ;
V_131 = & V_67 -> V_131 ;
break;
case V_25 :
V_61 = F_23 ( V_9 ) ;
if ( F_29 ( V_61 == NULL ) )
return 0 ;
V_129 = & V_61 -> V_129 ;
V_131 = & V_61 -> V_131 ;
break;
default:
return 0 ;
}
F_78 ( V_131 ) ;
V_132 = V_61 ? V_61 -> V_74 . V_133 : V_67 -> V_132 ;
if ( ! ( V_13 & V_99 ) ) {
if ( V_132 > 0 ) {
V_29 = F_11 ( V_129 ) ;
if ( ! V_29 && V_61 )
F_79 ( V_61 -> V_74 . V_134 ) ;
}
for ( V_10 = 0 ; V_10 < V_11 ; V_10 ++ )
V_129 -> V_12 [ V_10 ] = NULL ;
} else if ( V_132 > 0 ) {
V_29 = F_9 ( V_129 ,
V_94 -> V_15 , true ) ;
if ( ! V_29 && V_61 )
V_29 = F_80 ( V_61 ) ;
}
F_81 ( V_131 ) ;
return V_29 ? - V_135 : V_29 ;
}
static T_1 F_82 ( struct V_83 * V_56 ,
struct V_136 * V_137 , char * V_138 )
{
struct V_76 * V_55 = F_52 ( V_56 ) ;
struct V_41 * V_42 = F_83 ( V_55 ) ;
if ( V_42 -> V_75 )
return F_84 ( V_138 , L_24 , V_139 ) ;
return F_84 ( V_138 , L_25 , V_139 ) ;
}
static T_1 F_85 ( struct V_83 * V_56 ,
struct V_136 * V_137 ,
const char * V_138 , T_2 V_140 )
{
struct V_76 * V_55 = F_52 ( V_56 ) ;
struct V_41 * V_42 = F_83 ( V_55 ) ;
bool V_141 ;
int V_10 ;
if ( ! strcmp ( V_138 , L_26 ) )
V_141 = false ;
else if ( ! strcmp ( V_138 , L_27 ) )
V_141 = true ;
else
return V_140 ;
V_42 -> V_75 = V_141 ;
for ( V_10 = 0 ; V_10 < V_73 ; V_10 ++ )
if ( V_42 -> V_61 [ V_10 ] )
V_42 -> V_61 [ V_10 ] -> V_74 . V_75 = V_141 ;
return V_140 ;
}
static int F_86 ( struct V_76 * V_55 )
{
struct V_142 * V_49 ;
struct V_41 * V_42 ;
int V_29 ;
V_42 = F_87 ( & V_55 -> V_56 , sizeof( * V_42 ) , V_143 ) ;
if ( ! V_42 )
return - V_144 ;
F_88 ( & V_42 -> V_103 ) ;
V_42 -> V_55 = V_55 ;
F_84 ( V_42 -> V_145 . V_146 , L_28 ,
sizeof( V_42 -> V_145 . V_146 ) ) ;
V_42 -> V_145 . V_147 = F_77 ;
V_42 -> V_145 . V_56 = & V_55 -> V_56 ;
V_49 = & V_42 -> V_49 ;
V_49 -> V_148 = & V_42 -> V_145 ;
V_49 -> V_149 = V_150 ;
snprintf ( V_49 -> V_90 , sizeof( V_49 -> V_90 ) , L_29 ,
F_49 ( & V_55 -> V_56 ) ) ;
V_29 = F_89 ( & V_55 -> V_56 , & V_42 -> V_49 ) ;
if ( V_29 < 0 ) {
F_37 ( V_49 , L_30 , V_29 ) ;
return V_29 ;
}
V_29 = F_90 ( & V_42 -> V_145 ) ;
if ( V_29 < 0 ) {
F_37 ( V_49 , L_31 , V_29 ) ;
goto V_151;
}
V_29 = F_68 ( V_42 ) ;
if ( V_29 )
goto V_152;
V_42 -> V_75 = false ;
F_78 ( & V_42 -> V_145 . V_153 ) ;
V_29 = F_91 ( & V_154 , NULL , V_42 ,
F_51 ) ;
if ( V_29 )
goto V_155;
if ( V_55 -> V_56 . V_57 ) {
V_29 = F_26 ( V_42 ) ;
if ( V_29 )
goto V_155;
}
V_29 = F_63 ( V_42 ) ;
if ( V_29 )
goto V_155;
V_29 = F_92 ( & V_42 -> V_49 ) ;
if ( V_29 )
goto V_155;
V_29 = F_93 ( & V_55 -> V_56 , & V_156 ) ;
if ( V_29 )
goto V_155;
F_94 ( V_55 , V_42 ) ;
F_81 ( & V_42 -> V_145 . V_153 ) ;
return 0 ;
V_155:
F_81 ( & V_42 -> V_145 . V_153 ) ;
V_152:
F_95 ( & V_42 -> V_145 ) ;
F_65 ( V_42 ) ;
F_55 ( V_42 ) ;
V_151:
F_96 ( & V_42 -> V_49 ) ;
return V_29 ;
}
static int F_97 ( struct V_76 * V_55 )
{
struct V_41 * V_42 = F_83 ( V_55 ) ;
if ( ! V_42 )
return 0 ;
F_98 ( & V_55 -> V_56 , & V_156 ) ;
F_55 ( V_42 ) ;
F_95 ( & V_42 -> V_145 ) ;
F_65 ( V_42 ) ;
return 0 ;
}
static int T_3 F_99 ( void )
{
int V_29 ;
F_100 ( L_32 ) ;
V_29 = F_101 () ;
if ( V_29 )
return V_29 ;
return F_102 ( & V_157 ) ;
}
static void T_4 F_103 ( void )
{
F_104 ( & V_157 ) ;
F_105 () ;
}
