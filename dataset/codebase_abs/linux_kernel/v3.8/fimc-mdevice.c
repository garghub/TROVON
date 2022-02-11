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
V_2 -> V_12 [ V_19 ] = V_9 ;
break;
case V_20 :
V_2 -> V_12 [ V_21 ] = V_9 ;
break;
case V_22 :
V_2 -> V_12 [ V_23 ] = V_9 ;
break;
case V_24 :
break;
default:
F_5 ( L_1 ,
V_25 , V_9 -> V_17 ) ;
}
V_6 = & V_9 -> V_15 . V_7 [ 0 ] ;
}
}
static int F_6 ( struct V_8 * V_9 , int V_26 )
{
int * V_27 ;
int V_28 ;
if ( V_9 == NULL )
return - V_29 ;
V_27 = & V_9 -> V_15 . V_27 ;
if ( V_26 && ( * V_27 ) ++ > 0 )
return 0 ;
else if ( ! V_26 && ( * V_27 == 0 || -- ( * V_27 ) > 0 ) )
return 0 ;
V_28 = F_7 ( V_9 , V_30 , V_31 , V_26 ) ;
return V_28 != - V_32 ? V_28 : 0 ;
}
static int F_8 ( struct V_1 * V_2 , bool V_33 )
{
unsigned int V_10 ;
int V_28 ;
if ( V_2 -> V_12 [ V_19 ] == NULL )
return - V_29 ;
for ( V_10 = 0 ; V_10 < V_11 ; V_10 ++ ) {
unsigned int V_34 = V_33 ? ( V_11 - 1 ) - V_10 : V_10 ;
V_28 = F_6 ( V_2 -> V_12 [ V_34 ] , V_33 ) ;
if ( V_28 < 0 && V_28 != - V_29 )
return V_28 ;
}
return 0 ;
}
static int F_9 ( struct V_1 * V_2 ,
struct V_3 * V_4 , bool V_35 )
{
int V_28 ;
if ( V_35 )
F_1 ( V_2 , V_4 ) ;
if ( V_2 -> V_12 [ V_19 ] == NULL )
return - V_36 ;
V_28 = F_10 ( V_2 -> V_12 [ V_19 ] , true ) ;
if ( V_28 )
return V_28 ;
return F_8 ( V_2 , 1 ) ;
}
static int F_11 ( struct V_1 * V_2 ,
struct V_3 * V_4 , bool V_35 )
{
int V_28 ;
F_12 ( & V_4 -> V_37 -> V_38 ) ;
V_28 = F_9 ( V_2 , V_4 , V_35 ) ;
F_13 ( & V_4 -> V_37 -> V_38 ) ;
return V_28 ;
}
static int F_14 ( struct V_1 * V_2 )
{
int V_28 = 0 ;
if ( V_2 -> V_12 [ V_19 ] ) {
V_28 = F_8 ( V_2 , 0 ) ;
F_10 ( V_2 -> V_12 [ V_19 ] , false ) ;
}
return V_28 == - V_29 ? 0 : V_28 ;
}
static int F_15 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
int V_28 ;
if ( ! V_2 || ! V_2 -> V_12 [ V_19 ] )
return - V_36 ;
V_4 = & V_2 -> V_12 [ V_19 ] -> V_15 ;
F_12 ( & V_4 -> V_37 -> V_38 ) ;
V_28 = F_14 ( V_2 ) ;
F_13 ( & V_4 -> V_37 -> V_38 ) ;
return V_28 ;
}
static int F_16 ( struct V_1 * V_2 , bool V_26 )
{
int V_10 , V_28 ;
if ( V_2 -> V_12 [ V_19 ] == NULL )
return - V_39 ;
for ( V_10 = 0 ; V_10 < V_11 ; V_10 ++ ) {
unsigned int V_34 = V_26 ? ( V_11 - 1 ) - V_10 : V_10 ;
V_28 = F_7 ( V_2 -> V_12 [ V_34 ] , V_40 , V_41 , V_26 ) ;
if ( V_28 < 0 && V_28 != - V_32 && V_28 != - V_39 )
return V_28 ;
}
return 0 ;
}
static struct V_8 * F_17 ( struct V_42 * V_43 ,
struct V_44 * V_45 )
{
struct V_46 * V_47 ;
struct V_8 * V_9 = NULL ;
if ( ! V_45 || ! V_43 )
return NULL ;
V_47 = F_18 ( V_45 -> V_48 . V_49 ) ;
if ( ! V_47 ) {
F_19 ( & V_43 -> V_50 ,
L_2 ,
V_45 -> V_48 . V_49 ) ;
return F_20 ( - V_51 ) ;
}
V_9 = F_21 ( & V_43 -> V_50 , V_47 ,
V_45 -> V_48 . V_52 , NULL ) ;
if ( F_22 ( V_9 ) ) {
F_23 ( V_47 ) ;
F_19 ( & V_43 -> V_50 ,
L_3 ,
V_45 -> V_48 . V_52 -> type ) ;
return F_20 ( - V_51 ) ;
}
F_24 ( V_9 , V_45 ) ;
V_9 -> V_17 = V_18 ;
F_25 ( & V_43 -> V_50 , L_4 ,
V_45 -> V_48 . V_52 -> type ) ;
return V_9 ;
}
static void F_26 ( struct V_8 * V_9 )
{
struct V_53 * V_54 = F_27 ( V_9 ) ;
struct V_46 * V_47 ;
if ( ! V_54 )
return;
F_28 ( V_9 ) ;
V_47 = V_54 -> V_47 ;
F_29 ( V_54 ) ;
if ( V_47 )
F_23 ( V_47 ) ;
}
static int F_30 ( struct V_42 * V_43 )
{
struct V_55 * V_48 = V_43 -> V_56 -> V_57 . V_58 ;
struct V_59 * V_60 = NULL ;
int V_61 , V_28 , V_10 ;
for ( V_10 = 0 ; ! V_60 && V_10 < F_31 ( V_43 -> V_62 ) ; V_10 ++ )
if ( V_43 -> V_62 [ V_10 ] )
V_60 = V_43 -> V_62 [ V_10 ] ;
if ( ! V_60 )
return - V_29 ;
V_28 = F_32 ( & V_60 -> V_56 -> V_57 ) ;
if ( V_28 < 0 )
return V_28 ;
F_33 ( V_48 -> V_61 > F_31 ( V_43 -> V_63 ) ) ;
V_61 = F_34 ( V_64 , V_48 -> V_61 , F_31 ( V_43 -> V_63 ) ) ;
V_43 -> V_65 = V_61 ;
for ( V_10 = 0 ; V_10 < V_61 ; V_10 ++ ) {
struct V_8 * V_9 ;
V_43 -> V_63 [ V_10 ] . V_48 = V_48 -> V_66 [ V_10 ] ;
V_28 = F_35 ( V_43 , & V_43 -> V_63 [ V_10 ] , true ) ;
if ( V_28 )
break;
V_9 = F_17 ( V_43 , & V_43 -> V_63 [ V_10 ] ) ;
V_28 = F_35 ( V_43 , & V_43 -> V_63 [ V_10 ] , false ) ;
if ( ! F_36 ( V_9 ) ) {
V_43 -> V_63 [ V_10 ] . V_67 = V_9 ;
} else {
V_43 -> V_63 [ V_10 ] . V_67 = NULL ;
V_28 = F_37 ( V_9 ) ;
break;
}
if ( V_28 )
break;
}
F_38 ( & V_60 -> V_56 -> V_57 ) ;
return V_28 ;
}
static int F_39 ( struct V_68 * V_57 , void * V_2 )
{
struct V_59 * V_62 = F_40 ( V_57 ) ;
struct V_8 * V_9 ;
struct V_42 * V_43 = V_2 ;
int V_28 ;
if ( V_62 == NULL || V_62 -> V_69 >= V_70 )
return 0 ;
V_9 = & V_62 -> V_71 . V_67 ;
V_9 -> V_17 = V_24 ;
F_24 ( V_9 , ( void * ) & V_72 ) ;
V_28 = F_41 ( & V_43 -> V_50 , V_9 ) ;
if ( V_28 ) {
F_42 ( & V_43 -> V_50 , L_5 ,
V_62 -> V_69 , V_28 ) ;
return V_28 ;
}
V_43 -> V_62 [ V_62 -> V_69 ] = V_62 ;
return 0 ;
}
static int F_43 ( struct V_68 * V_57 , void * V_2 )
{
struct V_73 * V_62 = F_40 ( V_57 ) ;
struct V_42 * V_43 = V_2 ;
int V_28 ;
if ( V_62 == NULL || V_62 -> V_74 >= V_75 )
return 0 ;
V_62 -> V_67 . V_17 = V_22 ;
F_24 ( & V_62 -> V_67 , ( void * ) & V_72 ) ;
V_28 = F_41 ( & V_43 -> V_50 , & V_62 -> V_67 ) ;
if ( V_28 ) {
F_42 ( & V_43 -> V_50 ,
L_6 ,
V_62 -> V_74 , V_28 ) ;
return V_28 ;
}
V_43 -> V_73 [ V_62 -> V_74 ] = V_62 ;
return 0 ;
}
static int F_44 ( struct V_68 * V_57 , void * V_2 )
{
struct V_8 * V_9 = F_40 ( V_57 ) ;
struct V_76 * V_56 ;
struct V_42 * V_43 = V_2 ;
int V_69 , V_28 ;
if ( ! V_9 )
return 0 ;
V_56 = F_27 ( V_9 ) ;
if ( ! V_56 || V_56 -> V_69 < 0 || V_56 -> V_69 >= V_77 )
return 0 ;
F_25 ( V_9 , L_7 , V_56 -> V_69 , V_9 -> V_78 ) ;
V_69 = V_56 -> V_69 < 0 ? 0 : V_56 -> V_69 ;
V_9 -> V_17 = V_20 ;
V_28 = F_41 ( & V_43 -> V_50 , V_9 ) ;
if ( ! V_28 )
V_43 -> V_79 [ V_69 ] . V_9 = V_9 ;
else
F_42 ( & V_43 -> V_50 ,
L_8 , V_28 ) ;
return V_28 ;
}
static int F_45 ( struct V_42 * V_43 )
{
struct V_55 * V_48 = V_43 -> V_56 -> V_57 . V_58 ;
struct V_80 * V_81 ;
int V_28 , V_10 ;
V_81 = F_46 ( V_82 , & V_83 ) ;
if ( ! V_81 ) {
F_19 ( & V_43 -> V_50 ,
L_9 ,
V_82 ) ;
return - V_51 ;
}
V_28 = F_47 ( V_81 , NULL , V_43 ,
F_39 ) ;
if ( V_28 )
return V_28 ;
V_81 = F_46 ( V_84 , & V_83 ) ;
if ( V_81 && F_48 ( V_81 -> V_85 ) ) {
V_28 = F_47 ( V_81 , NULL , V_43 ,
F_43 ) ;
if ( V_28 )
return V_28 ;
F_49 ( V_81 -> V_85 ) ;
}
if ( V_48 == NULL )
return 0 ;
for ( V_10 = 0 ; V_10 < V_48 -> V_61 ; V_10 ++ ) {
if ( V_48 -> V_66 [ V_10 ] . V_86 == V_87 ) {
V_28 = 1 ;
break;
}
}
if ( ! V_28 )
return 0 ;
V_81 = F_46 ( V_88 , & V_83 ) ;
if ( ! V_81 || ! F_48 ( V_81 -> V_85 ) ) {
F_19 ( & V_43 -> V_50 ,
L_9 ,
V_88 ) ;
return - V_51 ;
}
return F_47 ( V_81 , NULL , V_43 ,
F_44 ) ;
}
static void F_50 ( struct V_42 * V_43 )
{
int V_10 ;
for ( V_10 = 0 ; V_10 < V_70 ; V_10 ++ ) {
if ( V_43 -> V_62 [ V_10 ] == NULL )
continue;
F_28 ( & V_43 -> V_62 [ V_10 ] -> V_71 . V_67 ) ;
V_43 -> V_62 [ V_10 ] -> V_89 = NULL ;
V_43 -> V_62 [ V_10 ] = NULL ;
}
for ( V_10 = 0 ; V_10 < V_75 ; V_10 ++ ) {
if ( V_43 -> V_73 [ V_10 ] == NULL )
continue;
F_28 ( & V_43 -> V_73 [ V_10 ] -> V_67 ) ;
V_43 -> V_62 [ V_10 ] -> V_89 = NULL ;
V_43 -> V_73 [ V_10 ] = NULL ;
}
for ( V_10 = 0 ; V_10 < V_77 ; V_10 ++ ) {
if ( V_43 -> V_79 [ V_10 ] . V_9 == NULL )
continue;
F_28 ( V_43 -> V_79 [ V_10 ] . V_9 ) ;
F_49 ( V_43 -> V_79 [ V_10 ] . V_9 -> V_85 ) ;
V_43 -> V_79 [ V_10 ] . V_9 = NULL ;
}
for ( V_10 = 0 ; V_10 < V_43 -> V_65 ; V_10 ++ ) {
if ( V_43 -> V_63 [ V_10 ] . V_67 == NULL )
continue;
F_26 ( V_43 -> V_63 [ V_10 ] . V_67 ) ;
V_43 -> V_63 [ V_10 ] . V_67 = NULL ;
}
}
static int F_51 ( struct V_42 * V_43 ,
struct V_3 * V_90 ,
struct V_8 * V_63 ,
int V_6 , int V_91 )
{
struct V_44 * V_45 ;
struct V_3 * V_92 ;
unsigned int V_13 = 0 ;
int V_28 , V_10 ;
for ( V_10 = 0 ; V_10 < V_70 ; V_10 ++ ) {
if ( ! V_43 -> V_62 [ V_10 ] )
continue;
if ( ! V_43 -> V_62 [ V_10 ] -> V_93 -> V_94 )
continue;
V_13 = ( ( 1 << V_10 ) & V_91 ) ? V_95 : 0 ;
V_92 = & V_43 -> V_62 [ V_10 ] -> V_71 . V_67 . V_15 ;
V_28 = F_52 ( V_90 , V_6 , V_92 ,
V_96 , V_13 ) ;
if ( V_28 )
return V_28 ;
V_28 = F_53 ( V_92 , V_97 , & V_92 -> V_7 [ 0 ] ,
& V_90 -> V_7 [ V_6 ] , V_13 ) ;
if ( V_28 )
break;
F_25 ( & V_43 -> V_50 , L_10 ,
V_90 -> V_78 , V_13 ? '=' : '-' , V_92 -> V_78 ) ;
if ( V_13 == 0 || V_63 == NULL )
continue;
V_45 = F_54 ( V_63 ) ;
if ( ! F_33 ( V_45 == NULL ) ) {
unsigned long V_98 ;
F_55 ( & V_43 -> V_99 , V_98 ) ;
V_45 -> V_100 = V_43 -> V_62 [ V_10 ] ;
F_56 ( & V_43 -> V_99 , V_98 ) ;
}
}
for ( V_10 = 0 ; V_10 < V_75 ; V_10 ++ ) {
if ( ! V_43 -> V_73 [ V_10 ] )
continue;
if ( V_91 & ( 1 << ( V_10 + V_70 ) ) )
V_13 = V_95 ;
else
V_13 = 0 ;
V_92 = & V_43 -> V_73 [ V_10 ] -> V_67 . V_15 ;
V_28 = F_52 ( V_90 , V_6 , V_92 ,
V_101 , V_13 ) ;
if ( V_28 )
return V_28 ;
V_28 = F_53 ( V_92 , V_97 , & V_92 -> V_7 [ 0 ] ,
& V_90 -> V_7 [ V_6 ] , V_13 ) ;
if ( V_28 )
break;
F_25 ( & V_43 -> V_50 , L_11 ,
V_90 -> V_78 , V_13 ? '=' : '-' , V_92 -> V_78 ) ;
}
return 0 ;
}
static int F_57 ( struct V_42 * V_43 )
{
struct V_3 * V_90 , * V_92 ;
unsigned int V_13 = V_95 ;
int V_10 , V_28 = 0 ;
for ( V_10 = 0 ; V_10 < V_75 ; V_10 ++ ) {
struct V_73 * V_62 = V_43 -> V_73 [ V_10 ] ;
if ( V_62 == NULL )
continue;
V_90 = & V_62 -> V_67 . V_15 ;
V_92 = & V_62 -> V_102 . V_15 ;
V_28 = F_52 ( V_90 , V_103 ,
V_92 , 0 , V_13 ) ;
if ( V_28 )
break;
}
return V_28 ;
}
static int F_58 ( struct V_42 * V_43 )
{
struct V_8 * V_104 [ 2 ] = { NULL } ;
struct V_8 * V_63 , * V_79 ;
struct V_105 * V_48 ;
struct V_44 * V_45 ;
struct V_3 * V_90 , * V_92 ;
int V_10 , V_6 , V_106 = 0 , V_28 = 0 ;
V_64 V_13 , V_91 = 0 ;
for ( V_10 = 0 ; V_10 < V_43 -> V_65 ; V_10 ++ ) {
if ( V_43 -> V_63 [ V_10 ] . V_67 == NULL )
continue;
V_63 = V_43 -> V_63 [ V_10 ] . V_67 ;
V_45 = F_54 ( V_63 ) ;
if ( ! V_45 )
continue;
V_90 = NULL ;
V_48 = & V_45 -> V_48 ;
switch ( V_48 -> V_86 ) {
case V_87 :
if ( F_59 ( V_48 -> V_107 >= V_77 ,
L_12 , V_48 -> V_107 ) )
return - V_36 ;
V_79 = V_43 -> V_79 [ V_48 -> V_107 ] . V_9 ;
if ( F_59 ( V_79 == NULL ,
L_13
L_14 ) )
return - V_36 ;
V_28 = F_52 ( & V_63 -> V_15 , 0 ,
& V_79 -> V_15 , V_108 ,
V_109 |
V_95 ) ;
if ( V_28 )
return V_28 ;
F_25 ( & V_43 -> V_50 , L_15 ,
V_63 -> V_15 . V_78 , V_79 -> V_15 . V_78 ) ;
V_90 = NULL ;
V_104 [ V_48 -> V_107 ] = V_63 ;
break;
case V_110 ... V_111 :
V_90 = & V_63 -> V_15 ;
V_6 = 0 ;
break;
default:
F_42 ( & V_43 -> V_50 , L_16 ,
V_48 -> V_86 ) ;
return - V_36 ;
}
if ( V_90 == NULL )
continue;
V_91 = 1 << V_106 ++ ;
V_28 = F_51 ( V_43 , V_90 , V_63 ,
V_6 , V_91 ) ;
}
for ( V_10 = 0 ; V_10 < F_31 ( V_43 -> V_79 ) ; V_10 ++ ) {
if ( V_43 -> V_79 [ V_10 ] . V_9 == NULL )
continue;
V_90 = & V_43 -> V_79 [ V_10 ] . V_9 -> V_15 ;
V_6 = V_112 ;
V_63 = V_104 [ V_10 ] ;
V_91 = 1 << V_106 ++ ;
V_28 = F_51 ( V_43 , V_90 , V_63 ,
V_6 , V_91 ) ;
}
V_13 = V_109 | V_95 ;
for ( V_10 = 0 ; V_10 < V_70 ; V_10 ++ ) {
if ( ! V_43 -> V_62 [ V_10 ] )
continue;
V_90 = & V_43 -> V_62 [ V_10 ] -> V_71 . V_67 . V_15 ;
V_92 = & V_43 -> V_62 [ V_10 ] -> V_71 . V_102 . V_15 ;
V_28 = F_52 ( V_90 , V_103 ,
V_92 , 0 , V_13 ) ;
if ( V_28 )
break;
}
return F_57 ( V_43 ) ;
}
static int F_60 ( struct V_42 * V_43 )
{
char V_113 [ 32 ] ;
struct V_114 * clock ;
int V_10 ;
for ( V_10 = 0 ; V_10 < V_115 ; V_10 ++ ) {
snprintf ( V_113 , sizeof( V_113 ) , L_17 , V_10 ) ;
clock = F_61 ( NULL , V_113 ) ;
if ( F_22 ( clock ) ) {
F_42 ( & V_43 -> V_50 , L_18 ,
V_113 ) ;
return - V_29 ;
}
V_43 -> V_116 [ V_10 ] . clock = clock ;
}
return 0 ;
}
static void F_62 ( struct V_42 * V_43 )
{
int V_10 = V_115 ;
while ( -- V_10 >= 0 ) {
if ( F_22 ( V_43 -> V_116 [ V_10 ] . clock ) )
continue;
F_63 ( V_43 -> V_116 [ V_10 ] . clock ) ;
V_43 -> V_116 [ V_10 ] . clock = NULL ;
}
}
static int F_35 ( struct V_42 * V_43 ,
struct V_44 * V_45 ,
bool V_26 )
{
struct V_105 * V_48 = & V_45 -> V_48 ;
struct V_117 * V_116 ;
int V_28 = 0 ;
if ( F_33 ( V_48 -> V_118 >= V_115 ) || V_43 == NULL )
return - V_36 ;
V_116 = & V_43 -> V_116 [ V_48 -> V_118 ] ;
F_64 ( L_19 ,
V_48 -> V_118 , V_48 -> V_119 , V_116 -> V_27 , V_26 ) ;
if ( V_26 ) {
if ( V_116 -> V_27 > 0 &&
V_116 -> V_120 != V_48 -> V_119 )
return - V_36 ;
if ( V_116 -> V_27 ++ == 0 ) {
F_65 ( V_116 -> clock , V_48 -> V_119 ) ;
V_116 -> V_120 = V_48 -> V_119 ;
V_28 = F_66 ( V_116 -> clock ) ;
F_64 ( L_20 , V_48 -> V_118 ,
F_67 ( V_116 -> clock ) ) ;
}
return V_28 ;
}
if ( F_33 ( V_116 -> V_27 == 0 ) )
return 0 ;
if ( -- V_116 -> V_27 == 0 ) {
F_68 ( V_116 -> clock ) ;
F_64 ( L_21 , V_48 -> V_118 ) ;
}
return V_28 ;
}
int F_10 ( struct V_8 * V_9 , bool V_26 )
{
struct V_44 * V_45 = F_54 ( V_9 ) ;
struct V_42 * V_43 = F_69 ( & V_9 -> V_15 ) ;
return F_35 ( V_43 , V_45 , V_26 ) ;
}
static int F_70 ( struct V_5 * V_90 ,
struct V_5 * V_92 , V_64 V_13 )
{
struct V_73 * V_73 = NULL ;
struct V_59 * V_62 = NULL ;
struct V_1 * V_121 ;
struct V_8 * V_9 ;
int V_28 = 0 ;
if ( F_3 ( V_92 -> V_15 ) != V_16 )
return 0 ;
V_9 = F_4 ( V_92 -> V_15 ) ;
switch ( V_9 -> V_17 ) {
case V_22 :
V_73 = F_27 ( V_9 ) ;
V_121 = & V_73 -> V_121 ;
break;
case V_24 :
V_62 = F_27 ( V_9 ) ;
V_121 = & V_62 -> V_121 ;
break;
default:
return 0 ;
}
if ( ! ( V_13 & V_95 ) ) {
V_28 = F_14 ( V_121 ) ;
V_121 -> V_12 [ V_19 ] = NULL ;
V_121 -> V_12 [ V_21 ] = NULL ;
if ( V_62 ) {
F_12 ( & V_62 -> V_122 ) ;
F_71 ( V_62 -> V_71 . V_123 ) ;
F_13 ( & V_62 -> V_122 ) ;
}
return V_28 ;
}
if ( V_62 ) {
F_12 ( & V_62 -> V_122 ) ;
if ( V_62 -> V_71 . V_124 > 0 ) {
V_28 = F_9 ( V_121 ,
V_90 -> V_15 , true ) ;
if ( ! V_28 )
V_28 = F_72 ( V_62 ) ;
}
F_13 ( & V_62 -> V_122 ) ;
} else {
F_12 ( & V_73 -> V_122 ) ;
if ( V_73 -> V_125 > 0 ) {
V_28 = F_9 ( V_121 ,
V_90 -> V_15 , true ) ;
}
F_13 ( & V_73 -> V_122 ) ;
}
return V_28 ? - V_126 : V_28 ;
}
static T_1 F_73 ( struct V_68 * V_57 ,
struct V_127 * V_128 , char * V_129 )
{
struct V_76 * V_56 = F_74 ( V_57 ) ;
struct V_42 * V_43 = F_75 ( V_56 ) ;
if ( V_43 -> V_130 )
return F_76 ( V_129 , L_22 , V_131 ) ;
return F_76 ( V_129 , L_23 , V_131 ) ;
}
static T_1 F_77 ( struct V_68 * V_57 ,
struct V_127 * V_128 ,
const char * V_129 , T_2 V_132 )
{
struct V_76 * V_56 = F_74 ( V_57 ) ;
struct V_42 * V_43 = F_75 ( V_56 ) ;
bool V_133 ;
int V_10 ;
if ( ! strcmp ( V_129 , L_24 ) )
V_133 = false ;
else if ( ! strcmp ( V_129 , L_25 ) )
V_133 = true ;
else
return V_132 ;
V_43 -> V_130 = V_133 ;
for ( V_10 = 0 ; V_10 < V_70 ; V_10 ++ )
if ( V_43 -> V_62 [ V_10 ] )
V_43 -> V_62 [ V_10 ] -> V_71 . V_130 = V_133 ;
return V_132 ;
}
static int F_78 ( struct V_76 * V_56 )
{
struct V_134 * V_50 ;
struct V_42 * V_43 ;
int V_28 ;
V_43 = F_79 ( & V_56 -> V_57 , sizeof( * V_43 ) , V_135 ) ;
if ( ! V_43 )
return - V_136 ;
F_80 ( & V_43 -> V_99 ) ;
V_43 -> V_56 = V_56 ;
F_76 ( V_43 -> V_137 . V_138 , L_26 ,
sizeof( V_43 -> V_137 . V_138 ) ) ;
V_43 -> V_137 . V_139 = F_70 ;
V_43 -> V_137 . V_57 = & V_56 -> V_57 ;
V_50 = & V_43 -> V_50 ;
V_50 -> V_140 = & V_43 -> V_137 ;
V_50 -> V_141 = V_142 ;
snprintf ( V_50 -> V_78 , sizeof( V_50 -> V_78 ) , L_27 ,
F_81 ( & V_56 -> V_57 ) ) ;
V_28 = F_82 ( & V_56 -> V_57 , & V_43 -> V_50 ) ;
if ( V_28 < 0 ) {
F_42 ( V_50 , L_28 , V_28 ) ;
return V_28 ;
}
V_28 = F_83 ( & V_43 -> V_137 ) ;
if ( V_28 < 0 ) {
F_42 ( V_50 , L_29 , V_28 ) ;
goto V_143;
}
V_28 = F_60 ( V_43 ) ;
if ( V_28 )
goto V_144;
V_43 -> V_130 = false ;
F_12 ( & V_43 -> V_137 . V_38 ) ;
V_28 = F_45 ( V_43 ) ;
if ( V_28 )
goto V_145;
if ( V_56 -> V_57 . V_58 ) {
V_28 = F_30 ( V_43 ) ;
if ( V_28 )
goto V_145;
}
V_28 = F_58 ( V_43 ) ;
if ( V_28 )
goto V_145;
V_28 = F_84 ( & V_43 -> V_50 ) ;
if ( V_28 )
goto V_145;
V_28 = F_85 ( & V_56 -> V_57 , & V_146 ) ;
if ( V_28 )
goto V_145;
F_86 ( V_56 , V_43 ) ;
F_13 ( & V_43 -> V_137 . V_38 ) ;
return 0 ;
V_145:
F_13 ( & V_43 -> V_137 . V_38 ) ;
V_144:
F_87 ( & V_43 -> V_137 ) ;
F_62 ( V_43 ) ;
F_50 ( V_43 ) ;
V_143:
F_88 ( & V_43 -> V_50 ) ;
return V_28 ;
}
static int F_89 ( struct V_76 * V_56 )
{
struct V_42 * V_43 = F_75 ( V_56 ) ;
if ( ! V_43 )
return 0 ;
F_90 ( & V_56 -> V_57 , & V_146 ) ;
F_50 ( V_43 ) ;
F_87 ( & V_43 -> V_137 ) ;
F_62 ( V_43 ) ;
return 0 ;
}
static int T_3 F_91 ( void )
{
int V_28 ;
F_92 ( L_30 ) ;
V_28 = F_93 () ;
if ( V_28 )
return V_28 ;
return F_94 ( & V_147 ) ;
}
static void T_4 F_95 ( void )
{
F_96 ( & V_147 ) ;
F_97 () ;
}
