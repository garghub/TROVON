static int F_1 ( const char * V_1 , const char * V_2 )
{
int V_3 = strlen ( V_1 ) ;
int V_4 = strlen ( V_2 ) ;
while ( -- V_3 >= 0 && -- V_4 >= 0 ) {
if ( V_1 [ V_3 ] != V_2 [ V_4 ] )
return V_1 [ V_3 ] - V_2 [ V_4 ] ;
}
return 0 ;
}
static int F_2 ( struct V_5 * V_6 , int line )
{
struct V_7 * V_8 ;
struct V_5 * V_9 ;
F_3 (ln, head, list) {
if ( V_8 -> line < line ) {
V_9 = & V_8 -> V_10 ;
goto V_11;
} else if ( V_8 -> line == line )
return 1 ;
}
V_9 = V_6 ;
V_11:
F_4 ( L_1 , line ) ;
V_8 = F_5 ( sizeof( struct V_7 ) ) ;
if ( V_8 == NULL )
return - V_12 ;
V_8 -> line = line ;
F_6 ( & V_8 -> V_10 ) ;
F_7 ( & V_8 -> V_10 , V_9 ) ;
return 0 ;
}
static int F_8 ( struct V_5 * V_6 , int line )
{
struct V_7 * V_8 ;
F_9 (ln, head, list)
if ( V_8 -> line == line )
return 1 ;
return 0 ;
}
static void F_10 ( struct V_5 * V_6 )
{
F_6 ( V_6 ) ;
}
static void F_11 ( struct V_5 * V_6 )
{
struct V_7 * V_8 ;
while ( ! F_12 ( V_6 ) ) {
V_8 = F_13 ( V_6 , struct V_7 , V_10 ) ;
F_14 ( & V_8 -> V_10 ) ;
free ( V_8 ) ;
}
}
static T_1 * F_15 ( int V_13 , T_2 * * V_14 , T_3 * V_15 )
{
T_4 * V_16 ;
T_1 * V_17 = NULL ;
if ( ! V_14 )
return NULL ;
* V_14 = F_16 ( & V_18 ) ;
if ( ! * V_14 )
return NULL ;
V_16 = F_17 ( * V_14 , L_2 , L_2 , V_13 ) ;
if ( ! V_16 )
goto error;
V_17 = F_18 ( V_16 , V_15 ) ;
if ( ! V_17 ) {
error:
F_19 ( * V_14 ) ;
* V_14 = NULL ;
}
return V_17 ;
}
static int F_20 ( T_4 * V_16 ,
void * * V_19 ,
const char * V_20 ,
T_3 V_21 ,
char * * V_22 , T_5 * * V_23 )
{
int V_13 ;
const char * V_24 = F_21 ( V_20 ) ;
F_22 ( L_3 , V_24 , V_20 ) ;
if ( V_24 ) {
V_13 = F_23 ( V_24 , V_25 ) ;
if ( V_13 >= 0 ) {
* V_22 = F_24 ( V_24 ) ;
return V_13 ;
}
}
return F_25 ( V_16 , V_19 , V_20 , V_21 ,
V_22 , V_23 ) ;
}
static T_1 * F_26 ( T_3 V_26 , T_2 * * V_14 ,
T_3 * V_15 )
{
T_1 * V_17 ;
if ( ! V_14 )
return NULL ;
* V_14 = F_16 ( & V_27 ) ;
if ( ! * V_14 )
return NULL ;
F_27 ( * V_14 ) ;
F_28 ( * V_14 ) ;
V_17 = F_29 ( * V_14 , V_26 , V_15 ) ;
if ( ! V_17 ) {
F_4 ( L_4 ,
( unsigned long ) V_26 ) ;
F_19 ( * V_14 ) ;
* V_14 = NULL ;
}
return V_17 ;
}
static T_1 * F_26 ( T_3 V_26 V_28 , T_2 * * V_14 ,
T_3 * V_15 )
{
int V_13 ;
const char * V_24 = F_21 ( L_5 ) ;
if ( ! V_24 ) {
F_30 ( L_6 ) ;
return NULL ;
}
F_22 ( L_7 , V_24 ) ;
V_13 = F_23 ( V_24 , V_25 ) ;
if ( V_13 < 0 )
return NULL ;
return F_15 ( V_13 , V_14 , V_15 ) ;
}
static const char * F_31 ( T_6 * V_29 , const char * V_30 )
{
T_7 * V_31 ;
T_8 V_32 , V_33 ;
const char * V_34 = NULL ;
int V_35 ;
if ( ! V_30 )
return NULL ;
V_35 = F_32 ( V_29 , & V_31 , & V_32 ) ;
if ( V_35 != 0 )
return NULL ;
for ( V_33 = 0 ; V_33 < V_32 ; V_33 ++ ) {
V_34 = F_33 ( V_31 , V_33 , NULL , NULL ) ;
if ( F_1 ( V_34 , V_30 ) == 0 )
break;
}
if ( V_33 == V_32 )
return NULL ;
return V_34 ;
}
static const char * F_34 ( T_6 * V_29 )
{
T_9 V_36 ;
if ( F_35 ( V_29 , V_37 , & V_36 ) == NULL )
return NULL ;
return F_36 ( & V_36 ) ;
}
static int F_37 ( T_6 * V_38 , unsigned long V_26 ,
const char * * V_30 , int * V_39 )
{
T_10 * line ;
T_3 V_40 ;
line = F_38 ( V_38 , ( T_3 ) V_26 ) ;
if ( line && F_39 ( line , & V_40 ) == 0 &&
V_26 == ( unsigned long ) V_40 && F_40 ( line , V_39 ) == 0 ) {
* V_30 = F_41 ( line , NULL , NULL ) ;
if ( ! * V_30 )
* V_39 = 0 ;
}
return * V_39 ? : - V_41 ;
}
static bool F_42 ( T_6 * V_42 , const char * V_43 )
{
const char * V_44 ;
V_44 = F_43 ( V_42 ) ;
return V_44 ? ( strcmp ( V_43 , V_44 ) == 0 ) : false ;
}
static int F_44 ( T_6 * V_45 )
{
T_9 V_36 ;
T_11 V_35 ;
if ( ! F_35 ( V_45 , V_46 , & V_36 ) )
return - V_41 ;
F_45 ( & V_36 , & V_35 ) ;
return ( int ) V_35 ;
}
static T_6 * F_46 ( T_6 * V_47 , T_6 * V_48 )
{
T_9 V_36 ;
if ( F_47 ( V_47 , V_49 , & V_36 ) &&
F_48 ( & V_36 , V_48 ) )
return V_48 ;
else
return NULL ;
}
static T_6 * F_49 ( T_6 * V_47 , T_6 * V_48 )
{
int V_50 ;
do {
V_47 = F_46 ( V_47 , V_48 ) ;
if ( ! V_47 )
break;
V_50 = F_50 ( V_47 ) ;
} while ( V_50 == V_51 ||
V_50 == V_52 ||
V_50 == V_53 ||
V_50 == V_54 );
return V_47 ;
}
static T_6 * F_51 ( T_6 * V_47 , T_6 * V_48 )
{
do {
V_47 = F_49 ( V_47 , V_48 ) ;
} while ( V_47 && F_50 ( V_47 ) == V_55 );
return V_47 ;
}
static int F_52 ( T_6 * V_56 , unsigned int V_57 ,
T_11 * V_58 )
{
T_9 V_36 ;
if ( F_35 ( V_56 , V_57 , & V_36 ) == NULL ||
F_45 ( & V_36 , V_58 ) != 0 )
return - V_41 ;
return 0 ;
}
static bool F_53 ( T_6 * V_56 )
{
T_11 V_35 ;
if ( F_52 ( V_56 , V_59 , & V_35 ) )
return false ;
return ( V_35 == V_60 || V_35 == V_61 ||
V_35 == V_62 ) ;
}
static int F_54 ( T_6 * V_56 )
{
T_11 V_35 ;
if ( F_52 ( V_56 , V_63 , & V_35 ) )
return 0 ;
return ( int ) V_35 ;
}
static int F_55 ( T_6 * V_56 )
{
T_11 V_35 ;
if ( F_52 ( V_56 , V_64 , & V_35 ) )
return 0 ;
return ( int ) V_35 ;
}
static int F_56 ( T_6 * V_56 )
{
T_11 V_35 ;
if ( F_52 ( V_56 , V_65 , & V_35 ) )
return 0 ;
return ( int ) V_35 ;
}
static int F_57 ( T_6 * V_66 , T_11 * V_67 )
{
T_9 V_36 ;
T_12 * V_68 ;
T_8 V_69 ;
int V_35 ;
if ( F_35 ( V_66 , V_70 , & V_36 ) == NULL )
return - V_41 ;
if ( F_45 ( & V_36 , V_67 ) != 0 ) {
V_35 = F_58 ( & V_36 , & V_68 , & V_69 ) ;
if ( V_35 < 0 || V_69 == 0 )
return - V_41 ;
if ( V_68 [ 0 ] . V_71 != V_72 || V_69 != 1 ) {
F_4 ( L_8 ,
V_68 [ 0 ] . V_71 , V_69 ) ;
return - V_73 ;
}
* V_67 = ( T_11 ) V_68 [ 0 ] . V_74 ;
}
return 0 ;
}
static T_6 * F_59 ( T_6 * V_75 ,
int (* F_60)( T_6 * , void * ) ,
void * V_76 , T_6 * V_48 )
{
T_6 V_77 ;
int V_35 ;
V_35 = F_61 ( V_75 , V_48 ) ;
if ( V_35 != 0 )
return NULL ;
do {
V_35 = F_60 ( V_48 , V_76 ) ;
if ( V_35 == V_78 )
return V_48 ;
if ( ( V_35 & V_79 ) &&
F_59 ( V_48 , F_60 , V_76 , & V_77 ) ) {
memcpy ( V_48 , & V_77 , sizeof( T_6 ) ) ;
return V_48 ;
}
} while ( ( V_35 & V_80 ) &&
F_62 ( V_48 , V_48 ) == 0 );
return NULL ;
}
static int F_63 ( T_6 * V_81 , void * V_76 )
{
struct V_82 * V_83 = V_76 ;
if ( F_50 ( V_81 ) == V_84 &&
F_64 ( V_81 , V_83 -> V_26 ) ) {
memcpy ( V_83 -> V_48 , V_81 , sizeof( T_6 ) ) ;
return V_85 ;
}
return V_86 ;
}
static T_6 * F_65 ( T_6 * V_29 , T_3 V_26 ,
T_6 * V_48 )
{
struct V_82 V_83 ;
V_83 . V_26 = V_26 ;
V_83 . V_48 = V_48 ;
if ( ! F_66 ( V_29 , F_63 , & V_83 , 0 ) )
return NULL ;
else
return V_48 ;
}
static int F_67 ( T_6 * V_48 , void * V_76 )
{
T_3 * V_26 = V_76 ;
if ( F_50 ( V_48 ) == V_87 &&
F_64 ( V_48 , * V_26 ) )
return V_78 ;
return V_88 ;
}
static T_6 * F_68 ( T_6 * V_89 , T_3 V_26 ,
T_6 * V_48 )
{
T_6 V_90 ;
V_89 = F_59 ( V_89 , F_67 , & V_26 , & V_90 ) ;
if ( ! V_89 )
return NULL ;
while ( V_89 ) {
memcpy ( V_48 , V_89 , sizeof( T_6 ) ) ;
V_89 = F_59 ( V_89 , F_67 , & V_26 ,
& V_90 ) ;
}
return V_48 ;
}
static int F_69 ( T_6 * V_45 , void * V_76 )
{
struct V_91 * V_92 = V_76 ;
T_3 V_26 ;
int V_39 ;
if ( F_50 ( V_45 ) == V_87 ) {
V_39 = F_44 ( V_45 ) ;
if ( V_39 > 0 && F_70 ( V_45 , & V_26 ) == 0 ) {
V_92 -> V_93 = V_92 -> V_94 ( V_92 -> V_30 , V_39 , V_26 ,
V_92 -> V_76 ) ;
if ( V_92 -> V_93 != 0 )
return V_78 ;
}
}
return V_80 ;
}
static int F_71 ( T_6 * V_89 ,
T_13 V_94 , void * V_76 )
{
struct V_91 V_92 = {
. V_94 = V_94 ,
. V_76 = V_76 ,
. V_93 = 0 ,
} ;
T_6 V_48 ;
T_3 V_26 ;
int V_39 ;
V_92 . V_30 = F_72 ( V_89 ) ;
if ( V_92 . V_30 && F_73 ( V_89 , & V_39 ) == 0 &&
F_70 ( V_89 , & V_26 ) == 0 ) {
V_92 . V_93 = V_94 ( V_92 . V_30 , V_39 , V_26 , V_76 ) ;
if ( V_92 . V_93 != 0 )
goto V_95;
}
F_59 ( V_89 , F_69 , & V_92 , & V_48 ) ;
V_95:
return V_92 . V_93 ;
}
static int F_74 ( T_6 * V_89 , void * V_76 )
{
struct V_91 * V_92 = V_76 ;
V_92 -> V_93 = F_71 ( V_89 , V_92 -> V_94 , V_92 -> V_76 ) ;
if ( V_92 -> V_93 != 0 )
return V_85 ;
return V_86 ;
}
static int F_75 ( T_6 * V_96 , T_13 V_94 ,
void * V_76 )
{
T_14 * V_97 ;
T_10 * line ;
T_3 V_26 ;
const char * V_30 ;
int V_39 , V_35 = 0 ;
T_6 V_48 , * V_29 ;
T_8 V_98 , V_33 ;
if ( F_50 ( V_96 ) == V_84 )
V_29 = F_76 ( V_96 , & V_48 , NULL , NULL ) ;
else
V_29 = V_96 ;
if ( ! V_29 ) {
F_22 ( L_9 ) ;
return - V_99 ;
}
if ( F_77 ( V_29 , & V_97 , & V_98 ) != 0 ) {
F_22 ( L_10 ) ;
return - V_41 ;
}
F_22 ( L_11 , V_98 ) ;
for ( V_33 = 0 ; V_33 < V_98 ; V_33 ++ ) {
line = F_78 ( V_97 , V_33 ) ;
if ( line == NULL ||
F_40 ( line , & V_39 ) != 0 ||
F_39 ( line , & V_26 ) != 0 ) {
F_22 ( L_12
L_13 ) ;
continue;
}
if ( V_96 != V_29 )
if ( ! F_64 ( V_96 , V_26 ) ||
F_68 ( V_96 , V_26 , & V_48 ) )
continue;
V_30 = F_41 ( line , NULL , NULL ) ;
V_35 = V_94 ( V_30 , V_39 , V_26 , V_76 ) ;
if ( V_35 != 0 )
return V_35 ;
}
if ( V_96 != V_29 )
V_35 = F_71 ( V_96 , V_94 , V_76 ) ;
else {
struct V_91 V_100 = {
. V_94 = V_94 ,
. V_76 = V_76 ,
. V_93 = 0 ,
} ;
F_66 ( V_29 , F_74 , & V_100 , 0 ) ;
V_35 = V_100 . V_93 ;
}
return V_35 ;
}
static int F_79 ( T_6 * V_48 , void * V_76 )
{
struct V_101 * V_102 = V_76 ;
int V_50 ;
V_50 = F_50 ( V_48 ) ;
if ( ( V_50 == V_103 ||
V_50 == V_104 ) &&
F_42 ( V_48 , V_102 -> V_44 ) )
return V_78 ;
if ( F_64 ( V_48 , V_102 -> V_26 ) )
return V_88 ;
else
return V_80 ;
}
static T_6 * F_80 ( T_6 * V_89 , const char * V_44 ,
T_3 V_26 , T_6 * V_48 )
{
struct V_101 V_102 = { . V_44 = V_44 , . V_26 = V_26 } ;
return F_59 ( V_89 , F_79 , ( void * ) & V_102 ,
V_48 ) ;
}
static int F_81 ( T_6 * V_48 , void * V_76 )
{
const char * V_44 = V_76 ;
if ( ( F_50 ( V_48 ) == V_105 ) &&
F_42 ( V_48 , V_44 ) )
return V_78 ;
return V_80 ;
}
static T_6 * F_82 ( T_6 * V_106 , const char * V_44 ,
T_6 * V_48 )
{
return F_59 ( V_106 , F_81 , ( void * ) V_44 ,
V_48 ) ;
}
static int F_83 ( T_6 * V_47 , char * V_107 , int V_108 )
{
T_6 type ;
int V_50 , V_35 , V_109 ;
const char * V_110 = L_2 ;
if ( F_49 ( V_47 , & type ) == NULL )
return - V_41 ;
V_50 = F_50 ( & type ) ;
if ( V_50 == V_111 || V_50 == V_112 )
V_110 = L_14 ;
else if ( V_50 == V_113 ) {
V_35 = snprintf ( V_107 , V_108 , L_15 ) ;
return ( V_35 >= V_108 ) ? - V_114 : V_35 ;
} else {
if ( ! F_43 ( & type ) )
return - V_41 ;
if ( V_50 == V_115 )
V_110 = L_16 ;
else if ( V_50 == V_116 )
V_110 = L_17 ;
V_35 = snprintf ( V_107 , V_108 , L_18 , V_110 , F_43 ( & type ) ) ;
return ( V_35 >= V_108 ) ? - V_114 : V_35 ;
}
V_35 = F_83 ( & type , V_107 , V_108 ) ;
if ( V_35 > 0 ) {
V_109 = snprintf ( V_107 + V_35 , V_108 - V_35 , L_19 , V_110 ) ;
V_35 = ( V_109 >= V_108 - V_35 ) ? - V_114 : V_109 + V_35 ;
}
return V_35 ;
}
static int F_84 ( T_6 * V_47 , char * V_107 , int V_108 )
{
int V_35 , V_109 ;
V_35 = F_83 ( V_47 , V_107 , V_108 ) ;
if ( V_35 < 0 ) {
F_4 ( L_20 ) ;
V_35 = snprintf ( V_107 , V_108 , L_21 ) ;
}
if ( V_35 > 0 ) {
V_109 = snprintf ( V_107 + V_35 , V_108 - V_35 , L_22 ,
F_43 ( V_47 ) ) ;
V_35 = ( V_109 >= V_108 - V_35 ) ? - V_114 : V_109 + V_35 ;
}
return V_35 ;
}
static struct V_117 * F_85 ( long V_67 )
{
struct V_117 * V_118 ;
V_118 = F_5 ( sizeof( struct V_117 ) ) ;
if ( V_118 != NULL )
V_118 -> V_119 = V_67 ;
return V_118 ;
}
static int F_86 ( T_6 * V_47 , T_3 V_26 ,
T_12 * V_120 ,
struct V_121 * V_122 )
{
T_9 V_36 ;
T_12 * V_123 ;
T_8 V_124 ;
unsigned int V_125 ;
T_11 V_67 = 0 ;
bool V_118 = false ;
const char * V_126 ;
int V_35 ;
if ( F_35 ( V_47 , V_127 , & V_36 ) != NULL )
goto V_128;
if ( F_35 ( V_47 , V_129 , & V_36 ) == NULL ||
F_87 ( & V_36 , V_26 , & V_123 , & V_124 , 1 ) <= 0 ||
V_124 == 0 ) {
return - V_41 ;
}
if ( V_123 -> V_71 == V_130 ) {
V_128:
if ( ! V_122 )
return 0 ;
V_35 = strlen ( F_43 ( V_47 ) ) ;
V_122 -> V_131 = F_5 ( V_35 + 2 ) ;
if ( V_122 -> V_131 == NULL )
return - V_12 ;
snprintf ( V_122 -> V_131 , V_35 + 2 , L_23 , F_43 ( V_47 ) ) ;
V_122 -> V_118 = F_85 ( ( long ) V_67 ) ;
if ( V_122 -> V_118 == NULL )
return - V_12 ;
return 0 ;
}
if ( V_123 -> V_71 == V_132 ) {
if ( V_120 == NULL )
return - V_73 ;
V_118 = true ;
V_67 = V_123 -> V_74 ;
V_123 = & V_120 [ 0 ] ;
}
if ( V_123 -> V_71 >= V_133 && V_123 -> V_71 <= V_134 ) {
V_125 = V_123 -> V_71 - V_133 ;
V_67 += V_123 -> V_74 ;
V_118 = true ;
} else if ( V_123 -> V_71 >= V_135 && V_123 -> V_71 <= V_136 ) {
V_125 = V_123 -> V_71 - V_135 ;
} else if ( V_123 -> V_71 == V_137 ) {
V_125 = V_123 -> V_74 ;
V_67 += V_123 -> V_138 ;
V_118 = true ;
} else if ( V_123 -> V_71 == V_139 ) {
V_125 = V_123 -> V_74 ;
} else {
F_4 ( L_24 , V_123 -> V_71 ) ;
return - V_73 ;
}
if ( ! V_122 )
return 0 ;
V_126 = F_88 ( V_125 ) ;
if ( ! V_126 ) {
F_89 ( L_25
L_26 , V_125 ) ;
return - V_140 ;
}
V_122 -> V_131 = F_24 ( V_126 ) ;
if ( V_122 -> V_131 == NULL )
return - V_12 ;
if ( V_118 ) {
V_122 -> V_118 = F_85 ( ( long ) V_67 ) ;
if ( V_122 -> V_118 == NULL )
return - V_12 ;
}
return 0 ;
}
static int F_90 ( T_6 * V_47 ,
struct V_121 * V_122 ,
const char * V_141 )
{
struct V_117 * * V_142 = & V_122 -> V_118 ;
T_6 type ;
char V_107 [ 16 ] ;
int V_35 ;
if ( V_141 && strcmp ( V_141 , L_27 ) != 0 ) {
V_122 -> type = F_24 ( V_141 ) ;
return ( V_122 -> type == NULL ) ? - V_12 : 0 ;
}
if ( F_55 ( V_47 ) != 0 ) {
V_35 = snprintf ( V_107 , 16 , L_28 , F_55 ( V_47 ) ,
F_56 ( V_47 ) ,
F_91 ( F_54 ( V_47 ) ) ) ;
goto V_143;
}
if ( F_51 ( V_47 , & type ) == NULL ) {
F_89 ( L_29 ,
F_43 ( V_47 ) ) ;
return - V_41 ;
}
F_4 ( L_30 ,
F_43 ( V_47 ) , F_43 ( & type ) ) ;
if ( V_141 && strcmp ( V_141 , L_27 ) == 0 ) {
V_35 = F_50 ( & type ) ;
if ( V_35 != V_112 &&
V_35 != V_111 ) {
F_89 ( L_31
L_32 ,
F_43 ( V_47 ) , F_43 ( & type ) ) ;
return - V_99 ;
}
if ( V_35 == V_112 ) {
if ( F_51 ( & type , & type ) == NULL ) {
F_89 ( L_33
L_34 ) ;
return - V_41 ;
}
while ( * V_142 )
V_142 = & ( * V_142 ) -> V_144 ;
* V_142 = F_5 ( sizeof( struct V_117 ) ) ;
if ( * V_142 == NULL ) {
F_89 ( L_35 ) ;
return - V_12 ;
}
}
if ( ! F_42 ( & type , L_36 ) &&
! F_42 ( & type , L_37 ) ) {
F_89 ( L_31
L_38 ,
F_43 ( V_47 ) ) ;
return - V_99 ;
}
V_122 -> type = F_24 ( V_141 ) ;
return ( V_122 -> type == NULL ) ? - V_12 : 0 ;
}
V_35 = F_91 ( F_54 ( & type ) ) ;
if ( ! V_35 )
return 0 ;
if ( V_35 > V_145 ) {
F_92 ( L_39 ,
F_43 ( & type ) , V_145 ) ;
V_35 = V_145 ;
}
V_35 = snprintf ( V_107 , 16 , L_40 ,
F_53 ( & type ) ? 's' : 'u' , V_35 ) ;
V_143:
if ( V_35 < 0 || V_35 >= 16 ) {
if ( V_35 >= 16 )
V_35 = - V_114 ;
F_89 ( L_41 ,
strerror ( - V_35 ) ) ;
return V_35 ;
}
V_122 -> type = F_24 ( V_107 ) ;
if ( V_122 -> type == NULL )
return - V_12 ;
return 0 ;
}
static int F_93 ( T_6 * V_47 , const char * V_146 ,
struct V_147 * V_148 ,
struct V_117 * * V_142 ,
T_6 * V_48 )
{
struct V_117 * V_118 = * V_142 ;
T_6 type ;
T_11 V_67 ;
int V_35 , V_50 ;
F_4 ( L_42 , V_148 -> V_44 , V_146 ) ;
if ( F_51 ( V_47 , & type ) == NULL ) {
F_89 ( L_43 , V_146 ) ;
return - V_41 ;
}
F_22 ( L_44 , ( unsigned ) F_94 ( & type ) ) ;
V_50 = F_50 ( & type ) ;
if ( V_148 -> V_44 [ 0 ] == '[' &&
( V_50 == V_111 || V_50 == V_112 ) ) {
if ( V_148 -> V_144 )
memcpy ( V_48 , & type , sizeof( * V_48 ) ) ;
if ( F_51 ( & type , & type ) == NULL ) {
F_89 ( L_43 , V_146 ) ;
return - V_41 ;
}
F_22 ( L_45 ,
( unsigned ) F_94 ( & type ) ) ;
if ( V_50 == V_112 ) {
V_118 = F_5 ( sizeof( struct V_117 ) ) ;
if ( V_118 == NULL )
return - V_12 ;
if ( * V_142 )
( * V_142 ) -> V_144 = V_118 ;
else
* V_142 = V_118 ;
}
V_118 -> V_119 += F_54 ( & type ) * V_148 -> V_149 ;
if ( ! V_148 -> V_144 )
memcpy ( V_48 , V_47 , sizeof( * V_48 ) ) ;
goto V_144;
} else if ( V_50 == V_112 ) {
if ( ! V_148 -> V_118 ) {
F_30 ( L_46 ,
V_148 -> V_44 ) ;
return - V_99 ;
}
if ( F_51 ( & type , & type ) == NULL ) {
F_89 ( L_43 , V_146 ) ;
return - V_41 ;
}
if ( F_50 ( & type ) != V_116 ) {
F_89 ( L_47 , V_146 ) ;
return - V_99 ;
}
V_118 = F_5 ( sizeof( struct V_117 ) ) ;
if ( V_118 == NULL )
return - V_12 ;
if ( * V_142 )
( * V_142 ) -> V_144 = V_118 ;
else
* V_142 = V_118 ;
} else {
if ( V_50 != V_116 ) {
F_89 ( L_47 , V_146 ) ;
return - V_99 ;
}
if ( V_148 -> V_44 [ 0 ] == '[' ) {
F_30 ( L_48
L_49 , V_146 ) ;
return - V_99 ;
}
if ( V_148 -> V_118 ) {
F_30 ( L_50 ,
V_148 -> V_44 ) ;
return - V_99 ;
}
if ( ! V_118 ) {
F_89 ( L_51
L_52 ) ;
return - V_73 ;
}
}
if ( F_82 ( & type , V_148 -> V_44 , V_48 ) == NULL ) {
F_89 ( L_53 , V_146 ,
F_43 ( & type ) , V_148 -> V_44 ) ;
return - V_99 ;
}
V_35 = F_57 ( V_48 , & V_67 ) ;
if ( V_35 < 0 ) {
F_89 ( L_54 , V_148 -> V_44 ) ;
return V_35 ;
}
V_118 -> V_119 += ( long ) V_67 ;
V_144:
if ( V_148 -> V_144 )
return F_93 ( V_48 , V_148 -> V_44 ,
V_148 -> V_144 , & V_118 , V_48 ) ;
else
return 0 ;
}
static int F_95 ( T_6 * V_47 , struct V_150 * V_151 )
{
T_6 V_48 ;
int V_35 ;
F_4 ( L_55 ,
F_43 ( V_47 ) ) ;
V_35 = F_86 ( V_47 , V_151 -> V_26 , V_151 -> V_120 ,
V_151 -> V_122 ) ;
if ( V_35 == - V_41 )
F_30 ( L_56
L_57 , V_151 -> V_152 -> V_153 ) ;
else if ( V_35 == - V_73 )
F_30 ( L_58 ) ;
else if ( V_151 -> V_152 -> V_148 ) {
V_35 = F_93 ( V_47 , V_151 -> V_152 -> V_153 ,
V_151 -> V_152 -> V_148 , & V_151 -> V_122 -> V_118 ,
& V_48 ) ;
V_47 = & V_48 ;
}
if ( V_35 == 0 )
V_35 = F_90 ( V_47 , V_151 -> V_122 , V_151 -> V_152 -> type ) ;
return V_35 ;
}
static int F_96 ( T_6 * V_89 , struct V_150 * V_151 )
{
T_6 V_47 , * V_154 ;
char V_107 [ 32 ] , * V_155 ;
int V_35 , V_156 ;
if ( ! F_97 ( V_151 -> V_152 -> V_153 ) ) {
V_151 -> V_122 -> V_131 = F_24 ( V_151 -> V_152 -> V_153 ) ;
if ( V_151 -> V_122 -> V_131 == NULL )
return - V_12 ;
if ( V_151 -> V_152 -> type ) {
V_151 -> V_122 -> type = F_24 ( V_151 -> V_152 -> type ) ;
if ( V_151 -> V_122 -> type == NULL )
return - V_12 ;
}
if ( V_151 -> V_152 -> V_44 ) {
V_151 -> V_122 -> V_44 = F_24 ( V_151 -> V_152 -> V_44 ) ;
if ( V_151 -> V_122 -> V_44 == NULL )
return - V_12 ;
} else
V_151 -> V_122 -> V_44 = NULL ;
return 0 ;
}
if ( V_151 -> V_152 -> V_44 )
V_151 -> V_122 -> V_44 = F_24 ( V_151 -> V_152 -> V_44 ) ;
else {
V_35 = F_98 ( V_151 -> V_152 , V_107 , 32 ) ;
if ( V_35 < 0 )
return V_35 ;
V_155 = strchr ( V_107 , ':' ) ;
if ( V_155 )
* V_155 = '_' ;
V_151 -> V_122 -> V_44 = F_24 ( V_107 ) ;
}
if ( V_151 -> V_122 -> V_44 == NULL )
return - V_12 ;
F_4 ( L_59 ,
V_151 -> V_152 -> V_153 ) ;
if ( F_80 ( V_89 , V_151 -> V_152 -> V_153 , V_151 -> V_26 , & V_47 ) )
V_35 = F_95 ( & V_47 , V_151 ) ;
else {
V_156 = F_99 ( V_89 , & V_154 ) ;
while ( V_156 -- > 1 ) {
F_4 ( L_60 ,
F_43 ( & V_154 [ V_156 ] ) ) ;
if ( F_80 ( & V_154 [ V_156 ] ,
V_151 -> V_152 -> V_153 , 0 ,
& V_47 ) ) {
V_35 = F_95 ( & V_47 , V_151 ) ;
goto V_11;
}
}
if ( V_154 )
free ( V_154 ) ;
V_35 = - V_41 ;
}
V_11:
if ( V_35 < 0 )
F_89 ( L_61 ,
V_151 -> V_152 -> V_153 ) ;
return V_35 ;
}
static int F_100 ( T_6 * V_89 , T_3 V_157 ,
bool V_158 , struct V_159 * V_160 )
{
T_3 V_161 ;
const char * V_44 ;
V_44 = F_43 ( V_89 ) ;
if ( V_44 ) {
if ( F_70 ( V_89 , & V_161 ) != 0 ) {
F_89 ( L_62 ,
F_43 ( V_89 ) ) ;
return - V_41 ;
}
V_160 -> V_162 = F_24 ( V_44 ) ;
if ( V_160 -> V_162 == NULL )
return - V_12 ;
V_160 -> V_119 = ( unsigned long ) ( V_157 - V_161 ) ;
} else
V_160 -> V_119 = ( unsigned long ) V_157 ;
if ( V_158 ) {
if ( V_161 != V_157 ) {
F_89 ( L_63
L_64 ) ;
return - V_99 ;
}
V_160 -> V_158 = true ;
}
return 0 ;
}
static int F_101 ( T_6 * V_89 , struct V_150 * V_151 )
{
T_6 V_48 ;
T_9 V_163 ;
T_8 V_124 ;
int V_35 ;
if ( ! V_89 || F_50 ( V_89 ) != V_84 ) {
V_89 = F_65 ( & V_151 -> V_29 ,
V_151 -> V_26 , & V_48 ) ;
if ( ! V_89 ) {
F_89 ( L_65
L_66 ) ;
return - V_41 ;
}
}
F_35 ( V_89 , V_164 , & V_163 ) ;
V_35 = F_87 ( & V_163 , V_151 -> V_26 , & V_151 -> V_120 , & V_124 , 1 ) ;
if ( V_35 <= 0 || V_124 == 0 ) {
V_151 -> V_120 = NULL ;
#if F_102 ( 0 , 142 )
} else if ( V_124 == 1 && V_151 -> V_120 [ 0 ] . V_71 == V_165 &&
V_151 -> V_166 != NULL ) {
T_15 * V_167 ;
if ( F_103 ( V_151 -> V_166 , V_151 -> V_26 , & V_167 ) != 0 ||
F_104 ( V_167 , & V_151 -> V_120 , & V_124 ) != 0 ) {
F_89 ( L_67 ,
( V_168 ) V_151 -> V_26 ) ;
return - V_41 ;
}
#endif
}
V_35 = V_151 -> F_60 ( V_89 , V_151 ) ;
V_151 -> V_120 = NULL ;
return V_35 ;
}
static int F_105 ( const char * V_30 , int V_39 ,
T_3 V_26 , void * V_76 )
{
struct V_150 * V_151 = V_76 ;
int V_35 ;
if ( V_39 != V_151 -> V_169 || F_1 ( V_30 , V_151 -> V_30 ) != 0 )
return 0 ;
V_151 -> V_26 = V_26 ;
V_35 = F_101 ( NULL , V_151 ) ;
return V_35 < 0 ? V_35 : 0 ;
}
static int F_106 ( struct V_150 * V_151 )
{
return F_75 ( & V_151 -> V_29 , F_105 , V_151 ) ;
}
static int F_107 ( struct V_5 * V_6 ,
const char * V_30 , const char * V_170 )
{
T_16 * V_171 ;
char * line = NULL ;
T_8 V_172 ;
T_17 V_108 ;
int V_173 = 0 , V_174 = 1 ;
V_171 = fopen ( V_30 , L_68 ) ;
if ( ! V_171 ) {
F_89 ( L_69 , V_30 , strerror ( V_175 ) ) ;
return - V_175 ;
}
while ( ( V_108 = F_108 ( & line , & V_172 , V_171 ) ) > 0 ) {
if ( line [ V_108 - 1 ] == '\n' )
line [ V_108 - 1 ] = '\0' ;
if ( F_109 ( line , V_170 ) ) {
F_2 ( V_6 , V_174 ) ;
V_173 ++ ;
}
V_174 ++ ;
}
if ( ferror ( V_171 ) )
V_173 = - V_175 ;
free ( line ) ;
fclose ( V_171 ) ;
if ( V_173 == 0 )
F_4 ( L_70 , V_30 ) ;
return V_173 ;
}
static int F_110 ( const char * V_30 , int V_39 ,
T_3 V_26 , void * V_76 )
{
struct V_150 * V_151 = V_76 ;
int V_35 ;
if ( ! F_8 ( & V_151 -> V_176 , V_39 ) ||
F_1 ( V_30 , V_151 -> V_30 ) != 0 )
return 0 ;
F_4 ( L_71 ,
V_39 , ( unsigned long long ) V_26 ) ;
V_151 -> V_26 = V_26 ;
V_35 = F_101 ( NULL , V_151 ) ;
return V_35 < 0 ? V_35 : 0 ;
}
static int F_111 ( T_6 * V_89 , struct V_150 * V_151 )
{
int V_35 = 0 ;
if ( F_12 ( & V_151 -> V_176 ) ) {
V_35 = F_107 ( & V_151 -> V_176 , V_151 -> V_30 ,
V_151 -> V_177 -> V_178 . V_179 ) ;
if ( V_35 <= 0 )
return V_35 ;
}
return F_75 ( V_89 , F_110 , V_151 ) ;
}
static int F_112 ( T_6 * V_45 , void * V_76 )
{
struct V_180 * V_100 = V_76 ;
struct V_150 * V_151 = V_100 -> V_76 ;
struct V_181 * V_182 = & V_151 -> V_177 -> V_178 ;
T_3 V_26 ;
if ( V_182 -> V_179 )
V_100 -> V_93 = F_111 ( V_45 , V_151 ) ;
else {
if ( F_70 ( V_45 , & V_26 ) != 0 ) {
F_89 ( L_72 ,
F_43 ( V_45 ) ) ;
V_100 -> V_93 = - V_41 ;
return V_85 ;
}
V_151 -> V_26 = V_26 ;
V_151 -> V_26 += V_182 -> V_119 ;
F_4 ( L_73 ,
( V_168 ) V_151 -> V_26 ) ;
V_100 -> V_93 = F_101 ( V_45 , V_151 ) ;
if ( V_100 -> V_93 < 0 )
return V_85 ;
}
return V_86 ;
}
static int F_113 ( T_6 * V_89 , void * V_76 )
{
struct V_180 * V_100 = V_76 ;
struct V_150 * V_151 = V_100 -> V_76 ;
struct V_181 * V_182 = & V_151 -> V_177 -> V_178 ;
if ( F_50 ( V_89 ) != V_84 ||
! F_42 ( V_89 , V_182 -> V_183 ) )
return V_86 ;
if ( V_182 -> V_184 && F_1 ( V_182 -> V_184 , F_72 ( V_89 ) ) )
return V_86 ;
V_151 -> V_30 = F_72 ( V_89 ) ;
if ( V_182 -> line ) {
F_73 ( V_89 , & V_151 -> V_169 ) ;
V_151 -> V_169 += V_182 -> line ;
V_100 -> V_93 = F_106 ( V_151 ) ;
} else if ( ! F_114 ( V_89 ) ) {
if ( V_182 -> V_179 )
V_100 -> V_93 = F_111 ( V_89 , V_151 ) ;
else {
if ( F_70 ( V_89 , & V_151 -> V_26 ) != 0 ) {
F_89 ( L_74
L_75 , F_43 ( V_89 ) ) ;
V_100 -> V_93 = - V_41 ;
return V_85 ;
}
V_151 -> V_26 += V_182 -> V_119 ;
V_100 -> V_93 = F_101 ( V_89 , V_151 ) ;
}
} else {
struct V_180 V_185 = { . V_76 = ( void * ) V_151 ,
. V_93 = 0 } ;
F_115 ( V_89 , F_112 ,
& V_185 ) ;
V_100 -> V_93 = V_185 . V_93 ;
}
return V_85 ;
}
static int F_116 ( struct V_150 * V_151 )
{
struct V_180 V_185 = { . V_76 = ( void * ) V_151 ,
. V_93 = 0 } ;
F_66 ( & V_151 -> V_29 , F_113 , & V_185 , 0 ) ;
return V_185 . V_93 ;
}
static int F_117 ( T_1 * V_17 , T_18 * V_186 , void * V_76 )
{
struct V_187 * V_100 = V_76 ;
if ( F_118 ( V_17 , V_186 -> V_188 , V_100 -> V_89 ) ) {
if ( F_50 ( V_100 -> V_89 ) != V_84 )
return V_86 ;
if ( F_42 ( V_100 -> V_89 , V_100 -> V_183 ) ) {
if ( ! F_118 ( V_17 , V_186 -> V_189 , V_100 -> V_29 ) )
return V_86 ;
if ( V_100 -> V_184 &&
F_1 ( V_100 -> V_184 , F_72 ( V_100 -> V_89 ) ) )
return V_86 ;
V_100 -> V_11 = 1 ;
return V_85 ;
}
}
return V_86 ;
}
static int F_119 ( int V_13 , struct V_150 * V_151 )
{
struct V_181 * V_182 = & V_151 -> V_177 -> V_178 ;
T_19 V_190 , V_191 ;
T_8 V_192 ;
T_6 * V_193 ;
T_1 * V_17 = NULL ;
T_2 * V_194 ;
T_3 V_15 ;
int V_35 = 0 ;
V_17 = F_15 ( V_13 , & V_194 , & V_15 ) ;
if ( ! V_17 ) {
F_89 ( L_76
L_77 ) ;
F_120 ( V_13 ) ;
return - V_195 ;
}
#if F_102 ( 0 , 142 )
V_151 -> V_166 = F_121 ( V_17 ) ;
#endif
V_190 = 0 ;
F_10 ( & V_151 -> V_176 ) ;
if ( V_182 -> V_183 ) {
struct V_187 V_196 = {
. V_183 = V_182 -> V_183 ,
. V_184 = V_182 -> V_184 ,
. V_29 = & V_151 -> V_29 ,
. V_89 = & V_151 -> V_89 ,
. V_11 = 0 ,
} ;
struct V_180 V_197 = {
. V_76 = V_151 ,
} ;
F_122 ( V_17 , F_117 , & V_196 , 0 ) ;
if ( V_196 . V_11 ) {
V_35 = F_113 ( & V_151 -> V_89 , & V_197 ) ;
if ( V_35 )
goto V_11;
}
}
while ( ! F_123 ( V_17 , V_190 , & V_191 , & V_192 , NULL , NULL , NULL ) ) {
V_193 = F_118 ( V_17 , V_190 + V_192 , & V_151 -> V_29 ) ;
if ( ! V_193 )
continue;
if ( V_182 -> V_184 )
V_151 -> V_30 = F_31 ( & V_151 -> V_29 , V_182 -> V_184 ) ;
else
V_151 -> V_30 = NULL ;
if ( ! V_182 -> V_184 || V_151 -> V_30 ) {
if ( V_182 -> V_183 )
V_35 = F_116 ( V_151 ) ;
else if ( V_182 -> V_179 )
V_35 = F_111 ( NULL , V_151 ) ;
else {
V_151 -> V_169 = V_182 -> line ;
V_35 = F_106 ( V_151 ) ;
}
if ( V_35 < 0 )
break;
}
V_190 = V_191 ;
}
V_11:
F_11 ( & V_151 -> V_176 ) ;
if ( V_194 )
F_19 ( V_194 ) ;
return V_35 ;
}
static int F_124 ( T_6 * V_89 , struct V_150 * V_151 )
{
struct V_198 * V_199 =
F_125 ( V_151 , struct V_198 , V_151 ) ;
struct V_200 * V_201 ;
int V_35 , V_33 ;
if ( V_199 -> V_202 == V_199 -> V_203 ) {
F_89 ( L_78 ,
V_199 -> V_203 ) ;
return - V_140 ;
}
V_201 = & V_199 -> V_204 [ V_199 -> V_202 ++ ] ;
V_35 = F_100 ( V_89 , V_151 -> V_26 , V_151 -> V_177 -> V_178 . V_158 ,
& V_201 -> V_178 ) ;
if ( V_35 < 0 )
return V_35 ;
F_4 ( L_79 , V_201 -> V_178 . V_162 ,
V_201 -> V_178 . V_119 ) ;
V_201 -> V_205 = V_151 -> V_177 -> V_205 ;
V_201 -> args = F_5 ( sizeof( struct V_121 ) * V_201 -> V_205 ) ;
if ( V_201 -> args == NULL )
return - V_12 ;
for ( V_33 = 0 ; V_33 < V_151 -> V_177 -> V_205 ; V_33 ++ ) {
V_151 -> V_152 = & V_151 -> V_177 -> args [ V_33 ] ;
V_151 -> V_122 = & V_201 -> args [ V_33 ] ;
V_35 = F_96 ( V_89 , V_151 ) ;
if ( V_35 != 0 )
return V_35 ;
}
return 0 ;
}
int F_126 ( int V_13 , struct V_206 * V_177 ,
struct V_200 * * V_204 , int V_203 )
{
struct V_198 V_199 = {
. V_151 = { . V_177 = V_177 , . F_60 = F_124 } ,
. V_203 = V_203 } ;
int V_35 ;
* V_204 = F_5 ( sizeof( struct V_200 ) * V_203 ) ;
if ( * V_204 == NULL )
return - V_12 ;
V_199 . V_204 = * V_204 ;
V_199 . V_202 = 0 ;
V_35 = F_119 ( V_13 , & V_199 . V_151 ) ;
if ( V_35 < 0 ) {
free ( * V_204 ) ;
* V_204 = NULL ;
return V_35 ;
}
return ( V_35 < 0 ) ? V_35 : V_199 . V_202 ;
}
static int F_127 ( T_6 * V_48 , void * V_76 )
{
struct V_207 * V_208 = V_76 ;
struct V_209 * V_210 ;
char V_107 [ V_211 ] ;
int V_50 , V_35 ;
V_210 = & V_208 -> V_212 [ V_208 -> V_213 - 1 ] ;
V_50 = F_50 ( V_48 ) ;
if ( V_50 == V_103 ||
V_50 == V_104 ) {
V_35 = F_86 ( V_48 , V_208 -> V_151 . V_26 ,
V_208 -> V_151 . V_120 , NULL ) ;
if ( V_35 == 0 ) {
V_35 = F_84 ( V_48 , V_107 , V_211 ) ;
F_22 ( L_80 , V_107 ) ;
if ( V_35 > 0 )
F_128 ( V_210 -> V_214 , V_107 ) ;
}
}
if ( V_208 -> V_215 && F_64 ( V_48 , V_208 -> V_151 . V_26 ) )
return V_88 ;
else
return V_80 ;
}
static int F_129 ( T_6 * V_89 , struct V_150 * V_151 )
{
struct V_207 * V_208 =
F_125 ( V_151 , struct V_207 , V_151 ) ;
struct V_209 * V_210 ;
T_6 V_48 , * V_154 = NULL ;
int V_35 , V_156 ;
if ( V_208 -> V_213 == V_208 -> V_216 ) {
F_89 ( L_78 , V_208 -> V_216 ) ;
return - V_140 ;
}
V_210 = & V_208 -> V_212 [ V_208 -> V_213 ++ ] ;
V_35 = F_100 ( V_89 , V_151 -> V_26 , V_151 -> V_177 -> V_178 . V_158 ,
& V_210 -> V_178 ) ;
if ( V_35 < 0 )
return V_35 ;
F_4 ( L_79 , V_210 -> V_178 . V_162 ,
V_210 -> V_178 . V_119 ) ;
V_210 -> V_214 = F_130 ( true , NULL ) ;
if ( V_210 -> V_214 == NULL )
return - V_12 ;
V_208 -> V_215 = true ;
F_59 ( V_89 , F_127 , ( void * ) V_208 , & V_48 ) ;
if ( ! V_208 -> V_217 )
goto V_218;
V_208 -> V_215 = false ;
V_156 = F_99 ( V_89 , & V_154 ) ;
while ( V_156 -- > 1 )
F_59 ( & V_154 [ V_156 ] , F_127 ,
( void * ) V_208 , & V_48 ) ;
if ( V_154 )
free ( V_154 ) ;
V_218:
if ( F_131 ( V_210 -> V_214 ) ) {
F_132 ( V_210 -> V_214 ) ;
V_210 -> V_214 = NULL ;
}
return V_35 ;
}
int F_133 ( int V_13 , struct V_206 * V_177 ,
struct V_209 * * V_212 , int V_216 ,
bool V_217 )
{
struct V_207 V_208 = {
. V_151 = { . V_177 = V_177 , . F_60 = F_129 } ,
. V_216 = V_216 , . V_217 = V_217 } ;
int V_35 ;
* V_212 = F_5 ( sizeof( struct V_209 ) * V_216 ) ;
if ( * V_212 == NULL )
return - V_12 ;
V_208 . V_212 = * V_212 ;
V_208 . V_213 = 0 ;
V_35 = F_119 ( V_13 , & V_208 . V_151 ) ;
if ( V_35 < 0 ) {
while ( V_208 . V_213 -- ) {
if ( V_208 . V_212 [ V_208 . V_213 ] . V_178 . V_162 )
free ( V_208 . V_212 [ V_208 . V_213 ] . V_178 . V_162 ) ;
if ( V_208 . V_212 [ V_208 . V_213 ] . V_214 )
F_132 ( V_208 . V_212 [ V_208 . V_213 ] . V_214 ) ;
}
free ( V_208 . V_212 ) ;
* V_212 = NULL ;
return V_35 ;
}
return ( V_35 < 0 ) ? V_35 : V_208 . V_213 ;
}
int F_134 ( unsigned long V_26 , struct V_181 * V_219 )
{
T_6 V_38 , V_220 , V_221 ;
T_1 * V_17 = NULL ;
T_2 * V_194 = NULL ;
T_3 V_222 , V_223 , V_15 = 0 ;
const char * V_30 = NULL , * V_224 = NULL , * V_110 ;
int V_225 = 0 , V_39 = 0 , V_35 = 0 ;
V_17 = F_26 ( V_26 , & V_194 , & V_15 ) ;
if ( ! V_17 ) {
F_89 ( L_76
L_77 ) ;
V_35 = - V_99 ;
goto V_226;
}
V_26 += V_15 ;
if ( ! F_135 ( V_17 , ( T_3 ) V_26 - V_15 , & V_38 ) ) {
F_89 ( L_81 ,
V_26 ) ;
V_35 = - V_99 ;
goto V_226;
}
F_37 ( & V_38 , V_26 , & V_30 , & V_39 ) ;
if ( F_65 ( & V_38 , ( T_3 ) V_26 , & V_220 ) ) {
V_110 = F_43 ( & V_220 ) ;
if ( ! V_110 ||
F_70 ( & V_220 , & V_223 ) != 0 ||
F_73 ( & V_220 , & V_225 ) != 0 )
goto V_227;
V_224 = V_110 ;
if ( V_26 == ( unsigned long ) V_223 )
V_39 = V_225 ;
else if ( F_68 ( & V_220 , ( T_3 ) V_26 ,
& V_221 ) ) {
if ( F_70 ( & V_221 , & V_222 ) == 0 &&
V_222 == V_26 )
V_39 = F_44 ( & V_221 ) ;
else {
V_110 = F_43 ( & V_221 ) ;
if ( V_110 &&
F_73 ( & V_220 , & V_225 ) == 0 )
V_224 = V_110 ;
}
}
}
V_227:
if ( V_39 )
V_219 -> line = V_39 - V_225 ;
else if ( V_224 )
V_219 -> V_119 = V_26 - ( unsigned long ) V_223 ;
if ( V_224 ) {
V_219 -> V_183 = F_24 ( V_224 ) ;
if ( V_219 -> V_183 == NULL ) {
V_35 = - V_12 ;
goto V_226;
}
}
if ( V_30 ) {
V_219 -> V_184 = F_24 ( V_30 ) ;
if ( V_219 -> V_184 == NULL ) {
if ( V_219 -> V_183 ) {
free ( V_219 -> V_183 ) ;
V_219 -> V_183 = NULL ;
}
V_35 = - V_12 ;
goto V_226;
}
}
V_226:
if ( V_194 )
F_19 ( V_194 ) ;
if ( V_35 == 0 && ( V_30 || V_224 ) )
V_35 = 1 ;
return V_35 ;
}
static int F_136 ( const char * V_34 , unsigned int V_39 ,
struct V_228 * V_229 )
{
if ( ! V_229 -> V_24 ) {
V_229 -> V_24 = F_24 ( V_34 ) ;
if ( V_229 -> V_24 == NULL )
return - V_12 ;
}
return F_2 ( & V_229 -> V_230 , V_39 ) ;
}
static int F_137 ( const char * V_30 , int V_39 ,
T_3 V_26 V_28 ,
void * V_76 )
{
struct V_231 * V_232 = V_76 ;
if ( ( F_1 ( V_30 , V_232 -> V_30 ) != 0 ) ||
( V_232 -> V_233 > V_39 || V_232 -> V_234 < V_39 ) )
return 0 ;
if ( F_136 ( V_30 , V_39 , V_232 -> V_229 ) < 0 )
return - V_99 ;
return 0 ;
}
static int F_138 ( T_6 * V_89 , struct V_231 * V_232 )
{
int V_35 ;
V_35 = F_75 ( V_89 ? : & V_232 -> V_29 , F_137 , V_232 ) ;
if ( V_35 >= 0 )
if ( ! F_12 ( & V_232 -> V_229 -> V_230 ) )
V_35 = V_232 -> V_11 = 1 ;
else
V_35 = 0 ;
else {
free ( V_232 -> V_229 -> V_24 ) ;
V_232 -> V_229 -> V_24 = NULL ;
}
return V_35 ;
}
static int F_139 ( T_6 * V_45 , void * V_76 )
{
struct V_180 * V_100 = V_76 ;
V_100 -> V_93 = F_138 ( V_45 , V_100 -> V_76 ) ;
return V_85 ;
}
static int F_140 ( T_6 * V_89 , void * V_76 )
{
struct V_180 * V_100 = V_76 ;
struct V_231 * V_232 = V_100 -> V_76 ;
struct V_228 * V_229 = V_232 -> V_229 ;
if ( V_229 -> V_184 && F_1 ( V_229 -> V_184 , F_72 ( V_89 ) ) )
return V_86 ;
if ( F_50 ( V_89 ) == V_84 &&
F_42 ( V_89 , V_229 -> V_183 ) ) {
V_232 -> V_30 = F_72 ( V_89 ) ;
F_73 ( V_89 , & V_229 -> V_119 ) ;
F_4 ( L_82 , V_232 -> V_30 , V_229 -> V_119 ) ;
V_232 -> V_233 = V_229 -> V_119 + V_229 -> V_235 ;
if ( V_232 -> V_233 < 0 )
V_232 -> V_233 = V_236 ;
V_232 -> V_234 = V_229 -> V_119 + V_229 -> V_226 ;
if ( V_232 -> V_234 < 0 )
V_232 -> V_234 = V_236 ;
F_4 ( L_83 , V_232 -> V_233 , V_232 -> V_234 ) ;
V_229 -> V_235 = V_232 -> V_233 ;
V_229 -> V_226 = V_232 -> V_234 ;
if ( F_114 ( V_89 ) ) {
struct V_180 V_185 ;
V_185 . V_76 = ( void * ) V_232 ;
V_185 . V_93 = 0 ;
F_115 ( V_89 ,
F_139 ,
& V_185 ) ;
V_100 -> V_93 = V_185 . V_93 ;
} else
V_100 -> V_93 = F_138 ( V_89 , V_232 ) ;
return V_85 ;
}
return V_86 ;
}
static int F_141 ( struct V_231 * V_232 )
{
struct V_180 V_100 = { . V_76 = ( void * ) V_232 , . V_93 = 0 } ;
F_66 ( & V_232 -> V_29 , F_140 , & V_100 , 0 ) ;
return V_100 . V_93 ;
}
int F_142 ( int V_13 , struct V_228 * V_229 )
{
struct V_231 V_232 = { . V_229 = V_229 , . V_11 = 0 } ;
int V_35 = 0 ;
T_19 V_190 = 0 , V_191 ;
T_8 V_192 ;
T_6 * V_193 ;
T_1 * V_17 = NULL ;
T_2 * V_194 ;
T_3 V_15 ;
const char * V_237 ;
V_17 = F_15 ( V_13 , & V_194 , & V_15 ) ;
if ( ! V_17 ) {
F_89 ( L_76
L_77 ) ;
F_120 ( V_13 ) ;
return - V_195 ;
}
if ( V_229 -> V_183 ) {
struct V_187 V_196 = {
. V_183 = V_229 -> V_183 , . V_184 = V_229 -> V_184 ,
. V_29 = & V_232 . V_29 , . V_89 = & V_232 . V_89 , . V_11 = 0 } ;
struct V_180 V_238 = {
. V_76 = ( void * ) & V_232 , . V_93 = 0 } ;
F_122 ( V_17 , F_117 , & V_196 , 0 ) ;
if ( V_196 . V_11 ) {
F_140 ( & V_232 . V_89 , & V_238 ) ;
if ( V_232 . V_11 )
goto V_11;
}
}
while ( ! V_232 . V_11 && V_35 >= 0 ) {
if ( F_123 ( V_17 , V_190 , & V_191 , & V_192 , NULL , NULL , NULL ) != 0 )
break;
V_193 = F_118 ( V_17 , V_190 + V_192 , & V_232 . V_29 ) ;
if ( ! V_193 )
continue;
if ( V_229 -> V_184 )
V_232 . V_30 = F_31 ( & V_232 . V_29 , V_229 -> V_184 ) ;
else
V_232 . V_30 = 0 ;
if ( ! V_229 -> V_184 || V_232 . V_30 ) {
if ( V_229 -> V_183 )
V_35 = F_141 ( & V_232 ) ;
else {
V_232 . V_233 = V_229 -> V_235 ;
V_232 . V_234 = V_229 -> V_226 ;
V_35 = F_138 ( NULL , & V_232 ) ;
}
}
V_190 = V_191 ;
}
V_11:
if ( V_232 . V_11 ) {
V_237 = F_34 ( & V_232 . V_29 ) ;
if ( V_237 ) {
V_229 -> V_237 = F_24 ( V_237 ) ;
if ( ! V_229 -> V_237 )
V_35 = - V_12 ;
}
}
F_4 ( L_84 , V_229 -> V_24 ) ;
F_19 ( V_194 ) ;
return ( V_35 < 0 ) ? V_35 : V_232 . V_11 ;
}
