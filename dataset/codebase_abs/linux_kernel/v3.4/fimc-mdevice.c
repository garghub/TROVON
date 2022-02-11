void F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_5 V_6 ;
struct V_7 * V_8 ;
F_2 ( & V_6 , V_4 ) ;
while ( ( V_4 = F_3 ( & V_6 ) ) ) {
if ( F_4 ( V_4 ) != V_9 )
continue;
V_8 = F_5 ( V_4 ) ;
if ( V_8 -> V_10 == V_11 )
V_2 -> V_12 . V_13 = V_8 ;
else if ( V_8 -> V_10 == V_14 )
V_2 -> V_12 . V_15 = V_8 ;
}
}
static int F_6 ( struct V_7 * V_8 , int V_16 )
{
int * V_17 ;
int V_18 ;
if ( V_8 == NULL )
return - V_19 ;
V_17 = & V_8 -> V_20 . V_17 ;
if ( V_16 && ( * V_17 ) ++ > 0 )
return 0 ;
else if ( ! V_16 && ( * V_17 == 0 || -- ( * V_17 ) > 0 ) )
return 0 ;
V_18 = F_7 ( V_8 , V_21 , V_22 , V_16 ) ;
return V_18 != - V_23 ? V_18 : 0 ;
}
int F_8 ( struct V_1 * V_2 , int V_24 )
{
int V_18 = 0 ;
if ( V_2 -> V_12 . V_13 == NULL )
return - V_19 ;
if ( V_24 ) {
V_18 = F_6 ( V_2 -> V_12 . V_15 , 1 ) ;
if ( V_18 && V_18 != - V_19 )
return V_18 ;
return F_6 ( V_2 -> V_12 . V_13 , 1 ) ;
}
V_18 = F_6 ( V_2 -> V_12 . V_13 , 0 ) ;
if ( V_18 )
return V_18 ;
V_18 = F_6 ( V_2 -> V_12 . V_15 , 0 ) ;
return V_18 == - V_19 ? 0 : V_18 ;
}
static int F_9 ( struct V_1 * V_2 ,
struct V_3 * V_4 , bool V_25 )
{
int V_18 ;
if ( V_25 )
F_1 ( V_2 , V_4 ) ;
if ( V_2 -> V_12 . V_13 == NULL )
return - V_26 ;
V_18 = F_10 ( V_2 -> V_12 . V_13 , true ) ;
if ( V_18 )
return V_18 ;
return F_8 ( V_2 , 1 ) ;
}
int F_11 ( struct V_1 * V_2 , struct V_3 * V_4 ,
bool V_25 )
{
int V_18 ;
F_12 ( & V_4 -> V_27 -> V_28 ) ;
V_18 = F_9 ( V_2 , V_4 , V_25 ) ;
F_13 ( & V_4 -> V_27 -> V_28 ) ;
return V_18 ;
}
int F_14 ( struct V_1 * V_2 )
{
int V_18 = 0 ;
if ( V_2 -> V_12 . V_13 ) {
V_18 = F_8 ( V_2 , 0 ) ;
F_10 ( V_2 -> V_12 . V_13 , false ) ;
}
return V_18 == - V_19 ? 0 : V_18 ;
}
int F_15 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = & V_2 -> V_29 . V_30 -> V_20 ;
int V_18 ;
F_12 ( & V_4 -> V_27 -> V_28 ) ;
V_18 = F_14 ( V_2 ) ;
F_13 ( & V_4 -> V_27 -> V_28 ) ;
return V_18 ;
}
int F_16 ( struct V_1 * V_2 , int V_16 )
{
struct V_31 * V_32 = & V_2 -> V_12 ;
int V_18 = 0 ;
if ( V_32 -> V_13 == NULL )
return - V_33 ;
if ( ( V_16 && V_32 -> V_15 ) || ! V_16 )
V_18 = F_7 ( V_16 ? V_32 -> V_15 : V_32 -> V_13 ,
V_34 , V_35 , V_16 ) ;
if ( V_18 < 0 && V_18 != - V_23 )
return V_18 ;
if ( ( ! V_16 && V_32 -> V_15 ) || V_16 )
V_18 = F_7 ( V_16 ? V_32 -> V_13 : V_32 -> V_15 ,
V_34 , V_35 , V_16 ) ;
return V_18 == - V_23 ? 0 : V_18 ;
}
static struct V_7 * F_17 ( struct V_36 * V_37 ,
struct V_38 * V_39 )
{
struct V_40 * V_41 ;
struct V_7 * V_8 = NULL ;
if ( ! V_39 || ! V_37 )
return NULL ;
V_41 = F_18 ( V_39 -> V_42 -> V_43 ) ;
if ( ! V_41 )
return NULL ;
V_8 = F_19 ( & V_37 -> V_44 , V_41 ,
V_39 -> V_42 -> V_45 , NULL ) ;
if ( F_20 ( V_8 ) ) {
F_21 ( V_41 ) ;
F_22 ( & V_37 -> V_44 , L_1 ) ;
return NULL ;
}
F_23 ( V_8 , V_39 ) ;
V_8 -> V_10 = V_11 ;
F_24 ( & V_37 -> V_44 , L_2 ,
V_39 -> V_42 -> V_45 -> type ) ;
return V_8 ;
}
static void F_25 ( struct V_7 * V_8 )
{
struct V_46 * V_47 = F_26 ( V_8 ) ;
struct V_40 * V_41 ;
if ( ! V_47 )
return;
F_27 ( V_8 ) ;
V_41 = V_47 -> V_41 ;
F_28 ( V_47 ) ;
if ( V_41 )
F_21 ( V_41 ) ;
}
static int F_29 ( struct V_36 * V_37 )
{
struct V_48 * V_42 = V_37 -> V_49 -> V_50 . V_51 ;
struct V_1 * V_52 = NULL ;
int V_53 , V_18 , V_54 ;
for ( V_54 = 0 ; ! V_52 && V_54 < F_30 ( V_37 -> V_2 ) ; V_54 ++ )
if ( V_37 -> V_2 [ V_54 ] )
V_52 = V_37 -> V_2 [ V_54 ] ;
if ( ! V_52 )
return - V_19 ;
V_18 = F_31 ( & V_52 -> V_49 -> V_50 ) ;
if ( V_18 < 0 )
return V_18 ;
F_32 ( V_42 -> V_53 > F_30 ( V_37 -> V_13 ) ) ;
V_53 = F_33 ( V_55 , V_42 -> V_53 , F_30 ( V_37 -> V_13 ) ) ;
V_37 -> V_56 = V_53 ;
for ( V_54 = 0 ; V_54 < V_53 ; V_54 ++ ) {
V_37 -> V_13 [ V_54 ] . V_42 = & V_42 -> V_57 [ V_54 ] ;
V_18 = F_34 ( V_37 , & V_37 -> V_13 [ V_54 ] , true ) ;
if ( V_18 )
break;
V_37 -> V_13 [ V_54 ] . V_58 =
F_17 ( V_37 , & V_37 -> V_13 [ V_54 ] ) ;
V_18 = F_34 ( V_37 , & V_37 -> V_13 [ V_54 ] , false ) ;
if ( V_18 )
break;
}
F_35 ( & V_52 -> V_49 -> V_50 ) ;
return V_18 ;
}
static int F_36 ( struct V_59 * V_50 , void * V_32 )
{
struct V_1 * V_2 = F_37 ( V_50 ) ;
struct V_36 * V_37 = V_32 ;
int V_18 ;
if ( ! V_2 || ! V_2 -> V_49 )
return 0 ;
if ( V_2 -> V_49 -> V_60 < 0 || V_2 -> V_49 -> V_60 >= V_61 )
return 0 ;
V_37 -> V_2 [ V_2 -> V_49 -> V_60 ] = V_2 ;
V_18 = F_38 ( V_2 , & V_37 -> V_44 ) ;
if ( V_18 )
return V_18 ;
V_18 = F_39 ( V_2 , & V_37 -> V_44 ) ;
if ( ! V_18 )
V_2 -> V_29 . V_62 = V_37 -> V_62 ;
return V_18 ;
}
static int F_40 ( struct V_59 * V_50 , void * V_32 )
{
struct V_7 * V_8 = F_37 ( V_50 ) ;
struct V_63 * V_49 ;
struct V_36 * V_37 = V_32 ;
int V_60 , V_18 ;
if ( ! V_8 )
return 0 ;
V_49 = F_26 ( V_8 ) ;
if ( ! V_49 || V_49 -> V_60 < 0 || V_49 -> V_60 >= V_64 )
return 0 ;
F_24 ( V_8 , L_3 , V_49 -> V_60 , V_8 -> V_65 ) ;
V_60 = V_49 -> V_60 < 0 ? 0 : V_49 -> V_60 ;
V_37 -> V_15 [ V_60 ] . V_8 = V_8 ;
V_8 -> V_10 = V_14 ;
V_18 = F_41 ( & V_37 -> V_44 , V_8 ) ;
if ( V_18 )
F_22 ( & V_37 -> V_44 ,
L_4 , V_18 ) ;
return V_18 ;
}
static int F_42 ( struct V_36 * V_37 )
{
struct V_66 * V_67 ;
int V_18 ;
V_67 = F_43 ( V_68 , & V_69 ) ;
if ( ! V_67 )
return - V_33 ;
V_18 = F_44 ( V_67 , NULL , V_37 ,
F_36 ) ;
if ( V_18 )
return V_18 ;
V_67 = F_43 ( V_70 , & V_69 ) ;
if ( V_67 )
V_18 = F_44 ( V_67 , NULL , V_37 ,
F_40 ) ;
return V_18 ;
}
static void F_45 ( struct V_36 * V_37 )
{
int V_54 ;
for ( V_54 = 0 ; V_54 < V_61 ; V_54 ++ ) {
if ( V_37 -> V_2 [ V_54 ] == NULL )
continue;
F_46 ( V_37 -> V_2 [ V_54 ] ) ;
F_47 ( V_37 -> V_2 [ V_54 ] ) ;
V_37 -> V_2 [ V_54 ] = NULL ;
}
for ( V_54 = 0 ; V_54 < V_64 ; V_54 ++ ) {
if ( V_37 -> V_15 [ V_54 ] . V_8 == NULL )
continue;
F_27 ( V_37 -> V_15 [ V_54 ] . V_8 ) ;
V_37 -> V_15 [ V_54 ] . V_8 = NULL ;
}
for ( V_54 = 0 ; V_54 < V_37 -> V_56 ; V_54 ++ ) {
if ( V_37 -> V_13 [ V_54 ] . V_58 == NULL )
continue;
F_25 ( V_37 -> V_13 [ V_54 ] . V_58 ) ;
V_37 -> V_13 [ V_54 ] . V_58 = NULL ;
}
}
static int F_48 ( struct V_36 * V_37 )
{
struct V_71 * V_72 ;
int V_54 , V_18 = 0 ;
for ( V_54 = 0 ; V_54 < V_61 && ! V_18 ; V_54 ++ ) {
if ( ! V_37 -> V_2 [ V_54 ] )
continue;
V_72 = V_37 -> V_2 [ V_54 ] -> V_73 . V_30 ;
if ( V_72 ) {
V_18 = F_49 ( V_72 , V_74 , - 1 ) ;
if ( V_18 )
break;
F_24 ( & V_37 -> V_44 , L_5 ,
V_72 -> V_65 , F_50 ( V_72 ) ) ;
}
V_72 = V_37 -> V_2 [ V_54 ] -> V_29 . V_30 ;
if ( V_72 == NULL )
continue;
V_18 = F_49 ( V_72 , V_74 , - 1 ) ;
F_24 ( & V_37 -> V_44 , L_5 ,
V_72 -> V_65 , F_50 ( V_72 ) ) ;
}
return V_18 ;
}
static int F_51 ( struct V_36 * V_37 ,
struct V_3 * V_75 ,
struct V_7 * V_13 ,
int V_76 , int V_77 )
{
struct V_38 * V_39 ;
struct V_3 * V_78 ;
unsigned int V_79 ;
int V_18 , V_54 ;
for ( V_54 = 0 ; V_54 < V_61 ; V_54 ++ ) {
if ( ! V_37 -> V_2 [ V_54 ] )
break;
if ( V_13 -> V_10 == V_11 &&
! V_37 -> V_2 [ V_54 ] -> V_80 -> V_81 )
continue;
V_79 = ( V_54 == V_77 ) ? V_82 : 0 ;
V_78 = & V_37 -> V_2 [ V_54 ] -> V_29 . V_58 -> V_20 ;
V_18 = F_52 ( V_75 , V_76 , V_78 ,
V_83 , V_79 ) ;
if ( V_18 )
return V_18 ;
V_18 = F_53 ( V_78 , V_84 , & V_78 -> V_85 [ 0 ] ,
& V_75 -> V_85 [ V_76 ] , V_79 ) ;
if ( V_18 )
break;
F_24 ( & V_37 -> V_44 , L_6 ,
V_75 -> V_65 , V_79 ? '=' : '-' , V_78 -> V_65 ) ;
if ( V_79 == 0 )
continue;
V_39 = F_54 ( V_13 ) ;
if ( ! F_32 ( V_39 == NULL ) ) {
unsigned long V_86 ;
F_55 ( & V_37 -> V_87 , V_86 ) ;
V_39 -> V_88 = V_37 -> V_2 [ V_54 ] ;
F_56 ( & V_37 -> V_87 , V_86 ) ;
}
}
return 0 ;
}
static int F_57 ( struct V_36 * V_37 )
{
struct V_7 * V_13 , * V_15 ;
struct V_89 * V_42 ;
struct V_38 * V_39 ;
struct V_3 * V_75 , * V_78 ;
int V_54 , V_76 , V_77 = 0 ;
int V_18 = 0 ;
V_55 V_79 ;
for ( V_54 = 0 ; V_54 < V_37 -> V_56 ; V_54 ++ ) {
if ( V_37 -> V_13 [ V_54 ] . V_58 == NULL )
continue;
V_13 = V_37 -> V_13 [ V_54 ] . V_58 ;
V_39 = F_54 ( V_13 ) ;
if ( ! V_39 || ! V_39 -> V_42 )
continue;
V_75 = NULL ;
V_42 = V_39 -> V_42 ;
switch ( V_42 -> V_90 ) {
case V_91 :
if ( F_58 ( V_42 -> V_92 >= V_64 ,
L_7 , V_42 -> V_92 ) )
return - V_26 ;
V_15 = V_37 -> V_15 [ V_42 -> V_92 ] . V_8 ;
if ( F_58 ( V_15 == NULL ,
L_8
L_9 ) )
return - V_26 ;
V_18 = F_52 ( & V_13 -> V_20 , 0 ,
& V_15 -> V_20 , V_93 ,
V_94 |
V_82 ) ;
if ( V_18 )
return V_18 ;
F_24 ( & V_37 -> V_44 , L_10 ,
V_13 -> V_20 . V_65 , V_15 -> V_20 . V_65 ) ;
V_75 = & V_15 -> V_20 ;
V_76 = V_95 ;
break;
case V_96 ... V_97 :
V_75 = & V_13 -> V_20 ;
V_76 = 0 ;
break;
default:
F_22 ( & V_37 -> V_44 , L_11 ,
V_42 -> V_90 ) ;
return - V_26 ;
}
if ( V_75 == NULL )
continue;
V_18 = F_51 ( V_37 , V_75 , V_13 , V_76 ,
V_77 ++ ) ;
}
V_79 = V_94 | V_82 ;
for ( V_54 = 0 ; V_54 < V_61 ; V_54 ++ ) {
if ( ! V_37 -> V_2 [ V_54 ] )
continue;
V_75 = & V_37 -> V_2 [ V_54 ] -> V_29 . V_58 -> V_20 ;
V_78 = & V_37 -> V_2 [ V_54 ] -> V_29 . V_30 -> V_20 ;
V_18 = F_52 ( V_75 , V_98 ,
V_78 , 0 , V_79 ) ;
if ( V_18 )
break;
}
return V_18 ;
}
static int F_59 ( struct V_36 * V_37 )
{
char V_99 [ 32 ] ;
struct V_100 * clock ;
int V_54 ;
for ( V_54 = 0 ; V_54 < V_101 ; V_54 ++ ) {
snprintf ( V_99 , sizeof( V_99 ) , L_12 , V_54 ) ;
clock = F_60 ( NULL , V_99 ) ;
if ( F_20 ( clock ) ) {
F_22 ( & V_37 -> V_44 , L_13 ,
V_99 ) ;
return - V_19 ;
}
V_37 -> V_102 [ V_54 ] . clock = clock ;
}
return 0 ;
}
static void F_61 ( struct V_36 * V_37 )
{
int V_54 = V_101 ;
while ( -- V_54 >= 0 ) {
if ( F_20 ( V_37 -> V_102 [ V_54 ] . clock ) )
continue;
F_62 ( V_37 -> V_102 [ V_54 ] . clock ) ;
V_37 -> V_102 [ V_54 ] . clock = NULL ;
}
}
static int F_34 ( struct V_36 * V_37 ,
struct V_38 * V_39 ,
bool V_16 )
{
struct V_89 * V_42 = V_39 -> V_42 ;
struct V_103 * V_102 ;
int V_18 = 0 ;
if ( F_32 ( V_42 -> V_104 >= V_101 ) || V_37 == NULL )
return - V_26 ;
if ( V_39 -> V_105 == V_16 )
return 0 ;
V_102 = & V_37 -> V_102 [ V_42 -> V_104 ] ;
F_63 ( L_14 ,
V_42 -> V_104 , V_42 -> V_106 , V_102 , V_16 ) ;
if ( V_16 ) {
if ( V_102 -> V_17 > 0 &&
V_102 -> V_107 != V_42 -> V_106 )
return - V_26 ;
if ( V_102 -> V_17 ++ == 0 ) {
F_64 ( V_102 -> clock , V_42 -> V_106 ) ;
V_102 -> V_107 = V_42 -> V_106 ;
V_18 = F_65 ( V_102 -> clock ) ;
}
V_39 -> V_105 = 1 ;
F_63 ( L_15 , V_42 -> V_104 ,
F_66 ( V_102 -> clock ) ) ;
return V_18 ;
}
if ( F_32 ( V_102 -> V_17 == 0 ) )
return 0 ;
if ( -- V_102 -> V_17 == 0 ) {
F_67 ( V_102 -> clock ) ;
V_39 -> V_105 = 0 ;
F_63 ( L_16 , V_42 -> V_104 ) ;
}
return V_18 ;
}
int F_10 ( struct V_7 * V_8 , bool V_16 )
{
struct V_38 * V_39 = F_54 ( V_8 ) ;
struct V_36 * V_37 = F_68 ( & V_8 -> V_20 ) ;
return F_34 ( V_37 , V_39 , V_16 ) ;
}
static int F_69 ( struct V_108 * V_75 ,
struct V_108 * V_78 , V_55 V_79 )
{
struct V_7 * V_8 ;
struct V_1 * V_2 ;
int V_18 = 0 ;
if ( F_4 ( V_78 -> V_20 ) != V_9 )
return 0 ;
V_8 = F_5 ( V_78 -> V_20 ) ;
V_2 = F_26 ( V_8 ) ;
if ( ! ( V_79 & V_82 ) ) {
V_18 = F_14 ( V_2 ) ;
V_2 -> V_12 . V_13 = NULL ;
V_2 -> V_12 . V_15 = NULL ;
F_12 ( & V_2 -> V_109 ) ;
F_70 ( V_2 -> V_29 . V_110 ) ;
F_13 ( & V_2 -> V_109 ) ;
return V_18 ;
}
F_12 ( & V_2 -> V_109 ) ;
if ( V_2 -> V_29 . V_111 > 0 ) {
V_18 = F_9 ( V_2 , V_75 -> V_20 , true ) ;
if ( ! V_18 )
V_18 = F_71 ( V_2 ) ;
}
F_13 ( & V_2 -> V_109 ) ;
return V_18 ? - V_112 : V_18 ;
}
static T_1 F_72 ( struct V_59 * V_50 ,
struct V_113 * V_114 , char * V_115 )
{
struct V_63 * V_49 = F_73 ( V_50 ) ;
struct V_36 * V_37 = F_74 ( V_49 ) ;
if ( V_37 -> V_62 )
return F_75 ( V_115 , L_17 , V_116 ) ;
return F_75 ( V_115 , L_18 , V_116 ) ;
}
static T_1 F_76 ( struct V_59 * V_50 ,
struct V_113 * V_114 ,
const char * V_115 , T_2 V_117 )
{
struct V_63 * V_49 = F_73 ( V_50 ) ;
struct V_36 * V_37 = F_74 ( V_49 ) ;
bool V_118 ;
int V_54 ;
if ( ! strcmp ( V_115 , L_19 ) )
V_118 = false ;
else if ( ! strcmp ( V_115 , L_20 ) )
V_118 = true ;
else
return V_117 ;
V_37 -> V_62 = V_118 ;
for ( V_54 = 0 ; V_54 < V_61 ; V_54 ++ )
if ( V_37 -> V_2 [ V_54 ] )
V_37 -> V_2 [ V_54 ] -> V_29 . V_62 = V_118 ;
return V_117 ;
}
static int T_3 F_77 ( struct V_63 * V_49 )
{
struct V_119 * V_44 ;
struct V_36 * V_37 ;
int V_18 ;
V_37 = F_78 ( & V_49 -> V_50 , sizeof( * V_37 ) , V_120 ) ;
if ( ! V_37 )
return - V_121 ;
F_79 ( & V_37 -> V_87 ) ;
V_37 -> V_49 = V_49 ;
F_75 ( V_37 -> V_122 . V_123 , L_21 ,
sizeof( V_37 -> V_122 . V_123 ) ) ;
V_37 -> V_122 . V_124 = F_69 ;
V_37 -> V_122 . V_50 = & V_49 -> V_50 ;
V_44 = & V_37 -> V_44 ;
V_44 -> V_125 = & V_37 -> V_122 ;
V_44 -> V_126 = V_127 ;
snprintf ( V_44 -> V_65 , sizeof( V_44 -> V_65 ) , L_22 ,
F_80 ( & V_49 -> V_50 ) ) ;
V_18 = F_81 ( & V_49 -> V_50 , & V_37 -> V_44 ) ;
if ( V_18 < 0 ) {
F_22 ( V_44 , L_23 , V_18 ) ;
return V_18 ;
}
V_18 = F_82 ( & V_37 -> V_122 ) ;
if ( V_18 < 0 ) {
F_22 ( V_44 , L_24 , V_18 ) ;
goto V_128;
}
V_18 = F_59 ( V_37 ) ;
if ( V_18 )
goto V_129;
V_37 -> V_62 = false ;
V_18 = F_42 ( V_37 ) ;
if ( V_18 )
goto V_129;
if ( V_49 -> V_50 . V_51 ) {
V_18 = F_29 ( V_37 ) ;
if ( V_18 )
goto V_129;
}
V_18 = F_57 ( V_37 ) ;
if ( V_18 )
goto V_129;
V_18 = F_83 ( & V_37 -> V_44 ) ;
if ( V_18 )
goto V_129;
V_18 = F_48 ( V_37 ) ;
if ( V_18 )
goto V_129;
V_18 = F_84 ( & V_49 -> V_50 , & V_130 ) ;
if ( ! V_18 ) {
F_85 ( V_49 , V_37 ) ;
return 0 ;
}
V_129:
F_86 ( & V_37 -> V_122 ) ;
F_61 ( V_37 ) ;
F_45 ( V_37 ) ;
V_128:
F_87 ( & V_37 -> V_44 ) ;
return V_18 ;
}
static int T_4 F_88 ( struct V_63 * V_49 )
{
struct V_36 * V_37 = F_74 ( V_49 ) ;
if ( ! V_37 )
return 0 ;
F_89 ( & V_49 -> V_50 , & V_130 ) ;
F_45 ( V_37 ) ;
F_86 ( & V_37 -> V_122 ) ;
F_61 ( V_37 ) ;
return 0 ;
}
int T_5 F_90 ( void )
{
int V_18 ;
F_91 ( L_25 ) ;
V_18 = F_92 () ;
if ( V_18 )
return V_18 ;
return F_93 ( & V_131 ) ;
}
void T_6 F_94 ( void )
{
F_95 ( & V_131 ) ;
F_96 () ;
}
