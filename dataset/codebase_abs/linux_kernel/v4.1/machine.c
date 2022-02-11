static void F_1 ( struct V_1 * V_1 )
{
F_2 ( & V_1 -> V_2 ) ;
V_1 -> V_3 = V_4 ;
}
int F_3 ( struct V_5 * V_5 , const char * V_6 , T_1 V_7 )
{
F_4 ( & V_5 -> V_8 , V_5 ) ;
F_5 ( & V_5 -> V_9 ) ;
F_1 ( & V_5 -> V_10 ) ;
F_1 ( & V_5 -> V_11 ) ;
V_5 -> V_12 = V_4 ;
F_2 ( & V_5 -> V_13 ) ;
V_5 -> V_14 = NULL ;
V_5 -> V_15 = NULL ;
V_5 -> V_7 = V_7 ;
V_5 -> V_16 = NULL ;
V_5 -> V_17 = 0 ;
V_5 -> V_18 = false ;
V_5 -> V_19 = 0 ;
V_5 -> V_6 = F_6 ( V_6 ) ;
if ( V_5 -> V_6 == NULL )
return - V_20 ;
if ( V_7 != V_21 ) {
struct V_22 * V_22 = F_7 ( V_5 , - 1 ,
V_7 ) ;
char V_23 [ 64 ] ;
if ( V_22 == NULL )
return - V_20 ;
snprintf ( V_23 , sizeof( V_23 ) , L_1 , V_7 ) ;
F_8 ( V_22 , V_23 , 0 ) ;
}
V_5 -> V_24 = NULL ;
return 0 ;
}
struct V_5 * F_9 ( void )
{
struct V_5 * V_5 = malloc ( sizeof( * V_5 ) ) ;
if ( V_5 != NULL ) {
F_3 ( V_5 , L_2 , V_21 ) ;
if ( F_10 ( V_5 ) < 0 )
goto V_25;
}
return V_5 ;
V_25:
free ( V_5 ) ;
return NULL ;
}
static void F_11 ( struct V_1 * V_1 )
{
struct V_26 * V_27 , * V_28 ;
F_12 (pos, n, &dsos->head, node) {
F_5 ( & V_27 -> V_9 ) ;
F_13 ( & V_27 -> V_29 ) ;
F_14 ( V_27 ) ;
}
}
void F_15 ( struct V_5 * V_5 )
{
struct V_9 * V_30 = F_16 ( & V_5 -> V_12 ) ;
while ( V_30 ) {
struct V_22 * V_31 = F_17 ( V_30 , struct V_22 , V_9 ) ;
V_30 = F_18 ( V_30 ) ;
F_19 ( V_5 , V_31 ) ;
}
}
void F_20 ( struct V_5 * V_5 )
{
F_21 ( & V_5 -> V_8 ) ;
F_11 ( & V_5 -> V_10 ) ;
F_11 ( & V_5 -> V_11 ) ;
F_22 ( V_5 ) ;
F_23 ( & V_5 -> V_6 ) ;
F_23 ( & V_5 -> V_24 ) ;
}
void F_24 ( struct V_5 * V_5 )
{
F_20 ( V_5 ) ;
free ( V_5 ) ;
}
void F_25 ( struct V_32 * V_32 )
{
F_3 ( & V_32 -> V_33 , L_2 , V_21 ) ;
V_32 -> V_34 = V_4 ;
V_32 -> V_16 = NULL ;
}
void F_26 ( struct V_32 * V_32 )
{
F_20 ( & V_32 -> V_33 ) ;
}
struct V_5 * F_27 ( struct V_32 * V_32 , T_1 V_7 ,
const char * V_6 )
{
struct V_9 * * V_35 = & V_32 -> V_34 . V_9 ;
struct V_9 * V_36 = NULL ;
struct V_5 * V_27 , * V_5 = malloc ( sizeof( * V_5 ) ) ;
if ( V_5 == NULL )
return NULL ;
if ( F_3 ( V_5 , V_6 , V_7 ) != 0 ) {
free ( V_5 ) ;
return NULL ;
}
V_5 -> V_16 = V_32 -> V_16 ;
while ( * V_35 != NULL ) {
V_36 = * V_35 ;
V_27 = F_17 ( V_36 , struct V_5 , V_9 ) ;
if ( V_7 < V_27 -> V_7 )
V_35 = & ( * V_35 ) -> V_37 ;
else
V_35 = & ( * V_35 ) -> V_38 ;
}
F_28 ( & V_5 -> V_9 , V_36 , V_35 ) ;
F_29 ( & V_5 -> V_9 , & V_32 -> V_34 ) ;
return V_5 ;
}
void F_30 ( struct V_32 * V_32 ,
T_2 V_16 )
{
struct V_9 * V_30 ;
V_32 -> V_16 = V_16 ;
V_32 -> V_33 . V_16 = V_16 ;
for ( V_30 = F_16 ( & V_32 -> V_34 ) ; V_30 ; V_30 = F_18 ( V_30 ) ) {
struct V_5 * V_5 = F_17 ( V_30 , struct V_5 , V_9 ) ;
V_5 -> V_16 = V_16 ;
}
}
void F_31 ( struct V_32 * V_32 , bool V_18 )
{
struct V_9 * V_30 ;
V_32 -> V_33 . V_18 = V_18 ;
for ( V_30 = F_16 ( & V_32 -> V_34 ) ; V_30 ; V_30 = F_18 ( V_30 ) ) {
struct V_5 * V_5 = F_17 ( V_30 , struct V_5 , V_9 ) ;
V_5 -> V_18 = V_18 ;
}
}
struct V_5 * F_32 ( struct V_32 * V_32 , T_1 V_7 )
{
struct V_9 * * V_35 = & V_32 -> V_34 . V_9 ;
struct V_9 * V_36 = NULL ;
struct V_5 * V_5 ;
struct V_5 * V_39 = NULL ;
if ( V_7 == V_21 )
return & V_32 -> V_33 ;
while ( * V_35 != NULL ) {
V_36 = * V_35 ;
V_5 = F_17 ( V_36 , struct V_5 , V_9 ) ;
if ( V_7 < V_5 -> V_7 )
V_35 = & ( * V_35 ) -> V_37 ;
else if ( V_7 > V_5 -> V_7 )
V_35 = & ( * V_35 ) -> V_38 ;
else
return V_5 ;
if ( ! V_5 -> V_7 )
V_39 = V_5 ;
}
return V_39 ;
}
struct V_5 * F_33 ( struct V_32 * V_32 , T_1 V_7 )
{
char V_40 [ V_41 ] ;
const char * V_6 = L_2 ;
struct V_5 * V_5 = F_32 ( V_32 , V_7 ) ;
if ( V_5 && ( V_5 -> V_7 == V_7 ) )
goto V_42;
if ( ( V_7 != V_21 ) &&
( V_7 != V_43 ) &&
( V_44 . V_45 ) ) {
sprintf ( V_40 , L_3 , V_44 . V_45 , V_7 ) ;
if ( F_34 ( V_40 , V_46 ) ) {
static struct V_47 * V_48 ;
if ( ! V_48 )
V_48 = F_35 ( true , NULL ) ;
if ( ! F_36 ( V_48 , V_40 ) ) {
F_37 ( L_4 , V_40 ) ;
F_38 ( V_48 , V_40 ) ;
}
V_5 = NULL ;
goto V_42;
}
V_6 = V_40 ;
}
V_5 = F_27 ( V_32 , V_7 , V_6 ) ;
V_42:
return V_5 ;
}
void F_39 ( struct V_32 * V_32 ,
T_3 V_49 , void * V_50 )
{
struct V_9 * V_30 ;
for ( V_30 = F_16 ( & V_32 -> V_34 ) ; V_30 ; V_30 = F_18 ( V_30 ) ) {
struct V_5 * V_27 = F_17 ( V_30 , struct V_5 , V_9 ) ;
V_49 ( V_27 , V_50 ) ;
}
}
char * F_40 ( struct V_5 * V_5 , char * V_51 , T_4 V_52 )
{
if ( F_41 ( V_5 ) )
snprintf ( V_51 , V_52 , L_5 , L_6 ) ;
else if ( F_42 ( V_5 ) )
snprintf ( V_51 , V_52 , L_5 , L_7 ) ;
else {
snprintf ( V_51 , V_52 , L_8 , L_7 ,
V_5 -> V_7 ) ;
}
return V_51 ;
}
void F_43 ( struct V_32 * V_32 , T_5 V_17 )
{
struct V_9 * V_29 ;
struct V_5 * V_5 ;
V_32 -> V_33 . V_17 = V_17 ;
for ( V_29 = F_16 ( & V_32 -> V_34 ) ; V_29 ; V_29 = F_18 ( V_29 ) ) {
V_5 = F_17 ( V_29 , struct V_5 , V_9 ) ;
V_5 -> V_17 = V_17 ;
}
return;
}
static void F_44 ( struct V_5 * V_5 ,
struct V_22 * V_53 , T_1 V_7 )
{
struct V_22 * V_54 ;
if ( V_7 == V_53 -> V_55 || V_7 == - 1 || V_53 -> V_55 != - 1 )
return;
V_53 -> V_55 = V_7 ;
if ( V_53 -> V_55 == V_53 -> V_56 )
return;
V_54 = F_7 ( V_5 , V_53 -> V_55 , V_53 -> V_55 ) ;
if ( ! V_54 )
goto V_57;
if ( ! V_54 -> V_58 )
V_54 -> V_58 = F_45 ( V_5 ) ;
if ( ! V_54 -> V_58 )
goto V_57;
if ( V_53 -> V_58 == V_54 -> V_58 )
return;
if ( V_53 -> V_58 ) {
if ( ! F_46 ( V_53 -> V_58 ) )
F_37 ( L_9 ,
V_53 -> V_55 , V_53 -> V_56 ) ;
F_47 ( V_53 -> V_58 ) ;
}
V_53 -> V_58 = F_48 ( V_54 -> V_58 ) ;
return;
V_57:
F_37 ( L_10 , V_53 -> V_55 , V_53 -> V_56 ) ;
}
static struct V_22 * F_49 ( struct V_5 * V_5 ,
T_1 V_7 , T_1 V_56 ,
bool V_59 )
{
struct V_9 * * V_35 = & V_5 -> V_12 . V_9 ;
struct V_9 * V_36 = NULL ;
struct V_22 * V_53 ;
V_53 = V_5 -> V_14 ;
if ( V_53 != NULL ) {
if ( V_53 -> V_56 == V_56 ) {
F_44 ( V_5 , V_53 , V_7 ) ;
return V_53 ;
}
F_50 ( V_5 -> V_14 ) ;
}
while ( * V_35 != NULL ) {
V_36 = * V_35 ;
V_53 = F_17 ( V_36 , struct V_22 , V_9 ) ;
if ( V_53 -> V_56 == V_56 ) {
V_5 -> V_14 = F_51 ( V_53 ) ;
F_44 ( V_5 , V_53 , V_7 ) ;
return V_53 ;
}
if ( V_56 < V_53 -> V_56 )
V_35 = & ( * V_35 ) -> V_37 ;
else
V_35 = & ( * V_35 ) -> V_38 ;
}
if ( ! V_59 )
return NULL ;
V_53 = F_52 ( V_7 , V_56 ) ;
if ( V_53 != NULL ) {
F_28 ( & V_53 -> V_9 , V_36 , V_35 ) ;
F_29 ( & V_53 -> V_9 , & V_5 -> V_12 ) ;
if ( F_53 ( V_53 , V_5 ) ) {
F_54 ( & V_53 -> V_9 , & V_5 -> V_12 ) ;
F_55 ( V_53 ) ;
return NULL ;
}
F_51 ( V_53 ) ;
V_5 -> V_14 = F_51 ( V_53 ) ;
}
return V_53 ;
}
struct V_22 * F_7 ( struct V_5 * V_5 , T_1 V_7 ,
T_1 V_56 )
{
return F_49 ( V_5 , V_7 , V_56 , true ) ;
}
struct V_22 * F_56 ( struct V_5 * V_5 , T_1 V_7 ,
T_1 V_56 )
{
return F_49 ( V_5 , V_7 , V_56 , false ) ;
}
struct V_23 * F_57 ( struct V_5 * V_5 ,
struct V_22 * V_22 )
{
if ( V_5 -> V_18 )
return F_58 ( V_22 ) ;
else
return F_59 ( V_22 ) ;
}
int F_60 ( struct V_5 * V_5 , union V_60 * V_61 ,
struct V_62 * V_63 )
{
struct V_22 * V_22 = F_7 ( V_5 ,
V_61 -> V_23 . V_7 ,
V_61 -> V_23 . V_56 ) ;
bool V_64 = V_61 -> V_65 . V_66 & V_67 ;
if ( V_64 )
V_5 -> V_18 = true ;
if ( V_68 )
F_61 ( V_61 , stdout ) ;
if ( V_22 == NULL ||
F_62 ( V_22 , V_61 -> V_23 . V_23 , V_63 -> time , V_64 ) ) {
F_63 ( L_11 ) ;
return - 1 ;
}
return 0 ;
}
int F_64 ( struct V_5 * V_5 V_69 ,
union V_60 * V_61 , struct V_62 * V_63 V_69 )
{
F_63 ( L_12 V_70 L_13 V_70 L_14 ,
V_61 -> V_71 . V_72 , V_61 -> V_71 . V_71 ) ;
return 0 ;
}
static struct V_26 *
F_65 ( struct V_5 * V_5 , struct V_73 * V_74 ,
const char * V_75 )
{
struct V_26 * V_26 ;
V_26 = F_66 ( & V_5 -> V_11 , V_74 -> V_76 , true ) ;
if ( ! V_26 ) {
V_26 = F_67 ( & V_5 -> V_11 , V_74 -> V_76 ) ;
if ( V_26 == NULL )
return NULL ;
if ( F_41 ( V_5 ) )
V_26 -> V_77 = V_78 ;
else
V_26 -> V_77 = V_79 ;
if ( V_74 -> V_80 && V_74 -> V_81 )
V_26 -> V_77 ++ ;
F_68 ( V_26 , F_6 ( V_74 -> V_76 ) , true ) ;
F_69 ( V_26 , F_6 ( V_75 ) , true ) ;
}
return V_26 ;
}
struct V_82 * F_70 ( struct V_5 * V_5 , T_6 V_83 ,
const char * V_75 )
{
struct V_82 * V_82 = NULL ;
struct V_26 * V_26 ;
struct V_73 V_74 ;
if ( F_71 ( & V_74 , V_75 ) )
return NULL ;
V_82 = F_72 ( & V_5 -> V_8 , V_84 ,
V_74 . V_76 ) ;
if ( V_82 )
goto V_42;
V_26 = F_65 ( V_5 , & V_74 , V_75 ) ;
if ( V_26 == NULL )
goto V_42;
V_82 = F_73 ( V_83 , V_26 , V_84 ) ;
if ( V_82 == NULL )
goto V_42;
F_74 ( & V_5 -> V_8 , V_82 ) ;
V_42:
free ( V_74 . V_76 ) ;
return V_82 ;
}
T_4 F_75 ( struct V_32 * V_32 , T_7 * V_85 )
{
struct V_9 * V_30 ;
T_4 V_86 = F_76 ( & V_32 -> V_33 . V_11 . V_2 , V_85 ) +
F_76 ( & V_32 -> V_33 . V_10 . V_2 , V_85 ) ;
for ( V_30 = F_16 ( & V_32 -> V_34 ) ; V_30 ; V_30 = F_18 ( V_30 ) ) {
struct V_5 * V_27 = F_17 ( V_30 , struct V_5 , V_9 ) ;
V_86 += F_76 ( & V_27 -> V_11 . V_2 , V_85 ) ;
V_86 += F_76 ( & V_27 -> V_10 . V_2 , V_85 ) ;
}
return V_86 ;
}
T_4 F_77 ( struct V_5 * V_74 , T_7 * V_85 ,
bool (F_78)( struct V_26 * V_26 , int V_87 ) , int V_87 )
{
return F_79 ( & V_74 -> V_11 . V_2 , V_85 , F_78 , V_87 ) +
F_79 ( & V_74 -> V_10 . V_2 , V_85 , F_78 , V_87 ) ;
}
T_4 F_80 ( struct V_32 * V_32 , T_7 * V_85 ,
bool (F_78)( struct V_26 * V_26 , int V_87 ) , int V_87 )
{
struct V_9 * V_30 ;
T_4 V_86 = F_77 ( & V_32 -> V_33 , V_85 , F_78 , V_87 ) ;
for ( V_30 = F_16 ( & V_32 -> V_34 ) ; V_30 ; V_30 = F_18 ( V_30 ) ) {
struct V_5 * V_27 = F_17 ( V_30 , struct V_5 , V_9 ) ;
V_86 += F_77 ( V_27 , V_85 , F_78 , V_87 ) ;
}
return V_86 ;
}
T_4 F_81 ( struct V_5 * V_5 , T_7 * V_85 )
{
int V_88 ;
T_4 V_89 = 0 ;
struct V_26 * V_90 = V_5 -> V_91 [ V_84 ] -> V_26 ;
if ( V_90 -> V_92 ) {
char V_75 [ V_41 ] ;
if ( F_82 ( V_90 , V_75 , sizeof( V_75 ) ) )
V_89 += fprintf ( V_85 , L_15 , V_75 ) ;
}
for ( V_88 = 0 ; V_88 < V_93 ; ++ V_88 )
V_89 += fprintf ( V_85 , L_16 ,
V_88 + V_90 -> V_92 , V_94 [ V_88 ] ) ;
return V_89 ;
}
T_4 F_83 ( struct V_5 * V_5 , T_7 * V_85 )
{
T_4 V_86 = 0 ;
struct V_9 * V_30 ;
for ( V_30 = F_16 ( & V_5 -> V_12 ) ; V_30 ; V_30 = F_18 ( V_30 ) ) {
struct V_22 * V_27 = F_17 ( V_30 , struct V_22 , V_9 ) ;
V_86 += F_84 ( V_27 , V_85 ) ;
}
return V_86 ;
}
static struct V_26 * F_85 ( struct V_5 * V_5 )
{
const char * V_95 = NULL ;
struct V_26 * V_96 ;
if ( F_41 ( V_5 ) ) {
V_95 = V_44 . V_95 ;
if ( ! V_95 )
V_95 = L_17 ;
V_96 = F_86 ( V_5 , V_95 ,
L_18 ,
V_97 ) ;
} else {
char V_51 [ V_41 ] ;
if ( F_42 ( V_5 ) )
V_95 = V_44 . V_98 ;
if ( ! V_95 )
V_95 = F_40 ( V_5 , V_51 ,
sizeof( V_51 ) ) ;
V_96 = F_86 ( V_5 , V_95 ,
L_19 ,
V_99 ) ;
}
if ( V_96 != NULL && ( ! V_96 -> V_92 ) )
F_87 ( V_96 , V_5 ) ;
return V_96 ;
}
static void F_88 ( struct V_5 * V_5 , char * V_100 ,
T_4 V_101 )
{
if ( F_42 ( V_5 ) )
F_89 ( V_100 , V_101 , L_20 , V_44 . V_102 ) ;
else
F_89 ( V_100 , V_101 , L_21 , V_5 -> V_6 ) ;
}
static T_6 F_90 ( struct V_5 * V_5 ,
const char * * V_103 )
{
char V_75 [ V_41 ] ;
int V_88 ;
const char * V_76 ;
T_6 V_104 = 0 ;
F_88 ( V_5 , V_75 , V_41 ) ;
if ( F_91 ( V_75 , L_22 ) )
return 0 ;
for ( V_88 = 0 ; ( V_76 = V_105 [ V_88 ] ) != NULL ; V_88 ++ ) {
V_104 = F_92 ( V_75 , V_76 ) ;
if ( V_104 )
break;
}
if ( V_103 )
* V_103 = V_76 ;
return V_104 ;
}
int F_93 ( struct V_5 * V_5 , struct V_26 * V_96 )
{
enum V_106 type ;
T_6 V_83 = F_90 ( V_5 , NULL ) ;
for ( type = 0 ; type < V_107 ; ++ type ) {
struct V_108 * V_108 ;
V_5 -> V_91 [ type ] = F_73 ( V_83 , V_96 , type ) ;
if ( V_5 -> V_91 [ type ] == NULL )
return - 1 ;
V_5 -> V_91 [ type ] -> V_109 =
V_5 -> V_91 [ type ] -> V_110 =
V_111 ;
V_108 = F_94 ( V_5 -> V_91 [ type ] ) ;
if ( ! V_108 )
return - 1 ;
V_108 -> V_8 = & V_5 -> V_8 ;
F_74 ( & V_5 -> V_8 ,
V_5 -> V_91 [ type ] ) ;
}
return 0 ;
}
void F_95 ( struct V_5 * V_5 )
{
enum V_106 type ;
for ( type = 0 ; type < V_107 ; ++ type ) {
struct V_108 * V_108 ;
if ( V_5 -> V_91 [ type ] == NULL )
continue;
V_108 = F_94 ( V_5 -> V_91 [ type ] ) ;
F_96 ( & V_5 -> V_8 ,
V_5 -> V_91 [ type ] ) ;
if ( V_108 && V_108 -> V_112 ) {
if ( type == V_84 ) {
F_23 ( ( char * * ) & V_108 -> V_112 -> V_76 ) ;
F_23 ( & V_108 -> V_112 ) ;
} else
V_108 -> V_112 = NULL ;
}
F_97 ( V_5 -> V_91 [ type ] ) ;
V_5 -> V_91 [ type ] = NULL ;
}
}
int F_98 ( struct V_32 * V_32 )
{
int V_86 = 0 ;
struct V_113 * * V_114 = NULL ;
int V_88 , V_115 = 0 ;
char V_40 [ V_41 ] ;
T_1 V_7 ;
char * V_116 ;
if ( V_44 . V_98 ||
V_44 . V_117 ||
V_44 . V_102 ) {
F_99 ( V_32 , V_43 ) ;
}
if ( V_44 . V_45 ) {
V_115 = F_100 ( V_44 . V_45 , & V_114 , NULL , NULL ) ;
if ( V_115 <= 0 )
return - V_118 ;
for ( V_88 = 0 ; V_88 < V_115 ; V_88 ++ ) {
if ( ! isdigit ( V_114 [ V_88 ] -> V_119 [ 0 ] ) ) {
continue;
}
V_7 = ( T_1 ) strtol ( V_114 [ V_88 ] -> V_119 , & V_116 , 10 ) ;
if ( ( * V_116 != '\0' ) ||
( V_116 == V_114 [ V_88 ] -> V_119 ) ||
( V_120 == V_121 ) ) {
F_101 ( L_23 ,
V_114 [ V_88 ] -> V_119 ) ;
continue;
}
sprintf ( V_40 , L_24 ,
V_44 . V_45 ,
V_114 [ V_88 ] -> V_119 ) ;
V_86 = F_34 ( V_40 , V_46 ) ;
if ( V_86 ) {
F_101 ( L_4 , V_40 ) ;
goto V_122;
}
F_99 ( V_32 , V_7 ) ;
}
V_122:
free ( V_114 ) ;
}
return V_86 ;
}
void F_102 ( struct V_32 * V_32 )
{
struct V_9 * V_123 = F_16 ( & V_32 -> V_34 ) ;
F_95 ( & V_32 -> V_33 ) ;
while ( V_123 ) {
struct V_5 * V_27 = F_17 ( V_123 , struct V_5 , V_9 ) ;
V_123 = F_18 ( & V_27 -> V_9 ) ;
F_54 ( & V_27 -> V_9 , & V_32 -> V_34 ) ;
F_24 ( V_27 ) ;
}
}
int F_99 ( struct V_32 * V_32 , T_1 V_7 )
{
struct V_5 * V_5 = F_33 ( V_32 , V_7 ) ;
if ( V_5 == NULL )
return - 1 ;
return F_10 ( V_5 ) ;
}
int F_103 ( struct V_5 * V_5 , const char * V_75 ,
enum V_106 type , T_2 V_124 )
{
struct V_82 * V_82 = V_5 -> V_91 [ type ] ;
int V_86 = F_104 ( V_82 -> V_26 , V_75 , V_82 , V_124 ) ;
if ( V_86 > 0 ) {
F_105 ( V_82 -> V_26 , type ) ;
F_106 ( & V_5 -> V_8 , type ) ;
}
return V_86 ;
}
int F_107 ( struct V_5 * V_5 , enum V_106 type ,
T_2 V_124 )
{
struct V_82 * V_82 = V_5 -> V_91 [ type ] ;
int V_86 = F_108 ( V_82 -> V_26 , V_82 , V_124 ) ;
if ( V_86 > 0 )
F_105 ( V_82 -> V_26 , type ) ;
return V_86 ;
}
static void F_109 ( struct V_125 * V_58 )
{
int V_88 ;
for ( V_88 = 0 ; V_88 < V_107 ; ++ V_88 )
F_106 ( V_58 , V_88 ) ;
}
static char * F_110 ( const char * V_6 )
{
char V_126 [ V_41 ] ;
T_7 * V_127 ;
char * V_76 , * V_128 ;
const char * V_129 = L_25 ;
sprintf ( V_126 , L_26 , V_6 ) ;
V_127 = fopen ( V_126 , L_27 ) ;
if ( ! V_127 )
return NULL ;
V_126 [ 0 ] = '\0' ;
V_128 = fgets ( V_126 , sizeof( V_126 ) , V_127 ) ;
fclose ( V_127 ) ;
V_76 = strstr ( V_126 , V_129 ) ;
if ( ! V_76 )
return NULL ;
V_76 += strlen ( V_129 ) ;
V_128 = strchr ( V_76 , ' ' ) ;
if ( V_128 )
* V_128 = '\0' ;
return F_6 ( V_76 ) ;
}
static bool F_111 ( struct V_26 * V_26 )
{
return V_26 -> V_77 == V_78 ||
V_26 -> V_77 == V_79 ;
}
static int F_112 ( struct V_125 * V_58 , const char * V_40 ,
struct V_73 * V_74 )
{
struct V_82 * V_82 ;
char * V_130 ;
V_82 = F_72 ( V_58 , V_84 , V_74 -> V_76 ) ;
if ( V_82 == NULL )
return 0 ;
V_130 = F_6 ( V_40 ) ;
if ( V_130 == NULL )
return - V_20 ;
F_69 ( V_82 -> V_26 , V_130 , true ) ;
F_113 ( V_82 -> V_26 , L_2 ) ;
if ( V_74 -> V_81 && F_111 ( V_82 -> V_26 ) )
V_82 -> V_26 -> V_77 ++ ;
return 0 ;
}
static int F_114 ( struct V_125 * V_58 ,
const char * V_131 , int V_132 )
{
struct V_113 * V_133 ;
T_8 * V_134 = F_115 ( V_131 ) ;
int V_86 = 0 ;
if ( ! V_134 ) {
F_101 ( L_28 , V_135 , V_131 ) ;
return - 1 ;
}
while ( ( V_133 = F_116 ( V_134 ) ) != NULL ) {
char V_40 [ V_41 ] ;
struct V_136 V_137 ;
snprintf ( V_40 , sizeof( V_40 ) , L_29 , V_131 , V_133 -> V_119 ) ;
if ( V_136 ( V_40 , & V_137 ) )
continue;
if ( F_117 ( V_137 . V_138 ) ) {
if ( ! strcmp ( V_133 -> V_119 , L_30 ) ||
! strcmp ( V_133 -> V_119 , L_31 ) )
continue;
if ( V_132 == 0 ) {
if ( ! strcmp ( V_133 -> V_119 , L_32 ) ||
! strcmp ( V_133 -> V_119 , L_33 ) )
continue;
}
V_86 = F_114 ( V_58 , V_40 ,
V_132 + 1 ) ;
if ( V_86 < 0 )
goto V_42;
} else {
struct V_73 V_74 ;
V_86 = F_71 ( & V_74 , V_133 -> V_119 ) ;
if ( V_86 )
goto V_42;
if ( V_74 . V_80 )
V_86 = F_112 ( V_58 , V_40 , & V_74 ) ;
free ( V_74 . V_76 ) ;
if ( V_86 )
goto V_42;
}
}
V_42:
F_118 ( V_134 ) ;
return V_86 ;
}
static int F_119 ( struct V_5 * V_5 )
{
char * V_126 ;
char V_139 [ V_41 ] ;
V_126 = F_110 ( V_5 -> V_6 ) ;
if ( ! V_126 )
return - 1 ;
snprintf ( V_139 , sizeof( V_139 ) , L_34 ,
V_5 -> V_6 , V_126 ) ;
free ( V_126 ) ;
return F_114 ( & V_5 -> V_8 , V_139 , 0 ) ;
}
static int F_120 ( void * V_140 , const char * V_76 , T_6 V_83 )
{
struct V_5 * V_5 = V_140 ;
struct V_82 * V_82 ;
V_82 = F_70 ( V_5 , V_83 , V_76 ) ;
if ( V_82 == NULL )
return - 1 ;
F_113 ( V_82 -> V_26 , V_5 -> V_6 ) ;
return 0 ;
}
static int F_121 ( struct V_5 * V_5 )
{
const char * V_141 ;
char V_40 [ V_41 ] ;
if ( F_42 ( V_5 ) ) {
V_141 = V_44 . V_117 ;
} else {
snprintf ( V_40 , V_41 , L_35 , V_5 -> V_6 ) ;
V_141 = V_40 ;
}
if ( F_91 ( V_141 , L_36 ) )
return - 1 ;
if ( F_122 ( V_141 , V_5 , F_120 ) )
return - 1 ;
if ( ! F_119 ( V_5 ) )
return 0 ;
F_101 ( L_37 ) ;
return 0 ;
}
int F_10 ( struct V_5 * V_5 )
{
struct V_26 * V_96 = F_85 ( V_5 ) ;
const char * V_76 ;
T_6 V_104 = F_90 ( V_5 , & V_76 ) ;
if ( ! V_104 )
return - 1 ;
if ( V_96 == NULL ||
F_93 ( V_5 , V_96 ) < 0 )
return - 1 ;
if ( V_44 . V_142 && F_121 ( V_5 ) < 0 ) {
if ( F_41 ( V_5 ) )
F_101 ( L_38
L_39 ) ;
else
F_101 ( L_40
L_39 , V_5 -> V_7 ) ;
}
F_109 ( & V_5 -> V_8 ) ;
if ( F_123 ( V_5 -> V_91 , V_76 ,
V_104 ) ) {
F_95 ( V_5 ) ;
return - 1 ;
}
return 0 ;
}
static void F_124 ( struct V_5 * V_5 ,
union V_60 * V_61 )
{
int V_88 ;
for ( V_88 = 0 ; V_88 < V_107 ; V_88 ++ ) {
V_5 -> V_91 [ V_88 ] -> V_83 = V_61 -> V_143 . V_83 ;
V_5 -> V_91 [ V_88 ] -> V_144 = ( V_61 -> V_143 . V_83 +
V_61 -> V_143 . V_145 ) ;
if ( V_5 -> V_91 [ V_88 ] -> V_144 == 0 )
V_5 -> V_91 [ V_88 ] -> V_144 = ~ 0ULL ;
}
}
static bool F_125 ( struct V_5 * V_5 )
{
struct V_26 * V_26 ;
F_126 (dso, &machine->kernel_dsos.head, node) {
if ( F_127 ( V_26 ) )
return true ;
}
return false ;
}
static int F_128 ( struct V_5 * V_5 ,
union V_60 * V_61 )
{
struct V_82 * V_82 ;
char V_146 [ V_41 ] ;
enum V_147 V_148 ;
bool V_149 ;
if ( F_125 ( V_5 ) )
return 0 ;
F_40 ( V_5 , V_146 , sizeof( V_146 ) ) ;
if ( F_41 ( V_5 ) )
V_148 = V_97 ;
else
V_148 = V_99 ;
V_149 = memcmp ( V_61 -> V_143 . V_75 ,
V_146 ,
strlen ( V_146 ) - 1 ) == 0 ;
if ( V_61 -> V_143 . V_75 [ 0 ] == '/' ||
( ! V_149 && V_61 -> V_143 . V_75 [ 0 ] == '[' ) ) {
V_82 = F_70 ( V_5 , V_61 -> V_143 . V_83 ,
V_61 -> V_143 . V_75 ) ;
if ( V_82 == NULL )
goto V_150;
V_82 -> V_144 = V_82 -> V_83 + V_61 -> V_143 . V_145 ;
} else if ( V_149 ) {
const char * V_103 = ( V_61 -> V_143 . V_75 +
strlen ( V_146 ) ) ;
struct V_26 * V_96 = NULL ;
struct V_26 * V_26 ;
F_126 (dso, &machine->kernel_dsos.head, node) {
if ( F_129 ( V_26 -> V_130 ) )
continue;
V_96 = V_26 ;
break;
}
if ( V_96 == NULL )
V_96 = F_130 ( & V_5 -> V_11 ,
V_146 ) ;
if ( V_96 == NULL )
goto V_150;
V_96 -> V_96 = V_148 ;
if ( F_93 ( V_5 , V_96 ) < 0 )
goto V_150;
if ( strstr ( V_96 -> V_130 , L_41 ) )
F_68 ( V_96 , L_42 , false ) ;
F_124 ( V_5 , V_61 ) ;
if ( V_61 -> V_143 . V_151 != 0 ) {
F_123 ( V_5 -> V_91 ,
V_103 ,
V_61 -> V_143 . V_151 ) ;
}
if ( F_42 ( V_5 ) ) {
F_131 ( V_96 , V_5 -> V_91 [ V_84 ] ,
NULL ) ;
}
}
return 0 ;
V_150:
return - 1 ;
}
int F_132 ( struct V_5 * V_5 ,
union V_60 * V_61 ,
struct V_62 * V_63 V_69 )
{
T_9 V_152 = V_61 -> V_65 . V_66 & V_153 ;
struct V_22 * V_22 ;
struct V_82 * V_82 ;
enum V_106 type ;
int V_86 = 0 ;
if ( V_68 )
F_133 ( V_61 , stdout ) ;
if ( V_152 == V_154 ||
V_152 == V_155 ) {
V_86 = F_128 ( V_5 , V_61 ) ;
if ( V_86 < 0 )
goto V_150;
return 0 ;
}
V_22 = F_7 ( V_5 , V_61 -> V_156 . V_7 ,
V_61 -> V_156 . V_56 ) ;
if ( V_22 == NULL )
goto V_150;
if ( V_61 -> V_65 . V_66 & V_157 )
type = V_158 ;
else
type = V_84 ;
V_82 = F_134 ( V_5 , V_61 -> V_156 . V_83 ,
V_61 -> V_156 . V_145 , V_61 -> V_156 . V_151 ,
V_61 -> V_156 . V_7 , V_61 -> V_156 . V_159 ,
V_61 -> V_156 . V_160 , V_61 -> V_156 . V_161 ,
V_61 -> V_156 . V_162 ,
V_61 -> V_156 . V_163 ,
V_61 -> V_156 . V_164 ,
V_61 -> V_156 . V_75 , type , V_22 ) ;
if ( V_82 == NULL )
goto V_150;
F_135 ( V_22 , V_82 ) ;
return 0 ;
V_150:
F_63 ( L_43 ) ;
return 0 ;
}
int F_136 ( struct V_5 * V_5 , union V_60 * V_61 ,
struct V_62 * V_63 V_69 )
{
T_9 V_152 = V_61 -> V_65 . V_66 & V_153 ;
struct V_22 * V_22 ;
struct V_82 * V_82 ;
enum V_106 type ;
int V_86 = 0 ;
if ( V_68 )
F_137 ( V_61 , stdout ) ;
if ( V_152 == V_154 ||
V_152 == V_155 ) {
V_86 = F_128 ( V_5 , V_61 ) ;
if ( V_86 < 0 )
goto V_150;
return 0 ;
}
V_22 = F_7 ( V_5 , V_61 -> V_143 . V_7 ,
V_61 -> V_143 . V_56 ) ;
if ( V_22 == NULL )
goto V_150;
if ( V_61 -> V_65 . V_66 & V_157 )
type = V_158 ;
else
type = V_84 ;
V_82 = F_134 ( V_5 , V_61 -> V_143 . V_83 ,
V_61 -> V_143 . V_145 , V_61 -> V_143 . V_151 ,
V_61 -> V_143 . V_7 , 0 , 0 , 0 , 0 , 0 , 0 ,
V_61 -> V_143 . V_75 ,
type , V_22 ) ;
if ( V_82 == NULL )
goto V_150;
F_135 ( V_22 , V_82 ) ;
return 0 ;
V_150:
F_63 ( L_44 ) ;
return 0 ;
}
void F_19 ( struct V_5 * V_5 , struct V_22 * V_53 )
{
if ( V_5 -> V_14 == V_53 )
F_50 ( V_5 -> V_14 ) ;
F_54 ( & V_53 -> V_9 , & V_5 -> V_12 ) ;
F_138 ( & V_53 -> V_29 , & V_5 -> V_13 ) ;
F_139 ( V_53 ) ;
}
int F_140 ( struct V_5 * V_5 , union V_60 * V_61 ,
struct V_62 * V_63 )
{
struct V_22 * V_22 = F_56 ( V_5 ,
V_61 -> V_165 . V_7 ,
V_61 -> V_165 . V_56 ) ;
struct V_22 * V_36 = F_7 ( V_5 ,
V_61 -> V_165 . V_166 ,
V_61 -> V_165 . V_167 ) ;
if ( V_22 != NULL )
F_19 ( V_5 , V_22 ) ;
V_22 = F_7 ( V_5 , V_61 -> V_165 . V_7 ,
V_61 -> V_165 . V_56 ) ;
if ( V_68 )
F_141 ( V_61 , stdout ) ;
if ( V_22 == NULL || V_36 == NULL ||
F_142 ( V_22 , V_36 , V_63 -> time ) < 0 ) {
F_63 ( L_45 ) ;
return - 1 ;
}
return 0 ;
}
int F_143 ( struct V_5 * V_5 , union V_60 * V_61 ,
struct V_62 * V_63 V_69 )
{
struct V_22 * V_22 = F_56 ( V_5 ,
V_61 -> V_165 . V_7 ,
V_61 -> V_165 . V_56 ) ;
if ( V_68 )
F_141 ( V_61 , stdout ) ;
if ( V_22 != NULL )
F_144 ( V_22 ) ;
return 0 ;
}
int F_145 ( struct V_5 * V_5 , union V_60 * V_61 ,
struct V_62 * V_63 )
{
int V_86 ;
switch ( V_61 -> V_65 . type ) {
case V_168 :
V_86 = F_60 ( V_5 , V_61 , V_63 ) ; break;
case V_169 :
V_86 = F_136 ( V_5 , V_61 , V_63 ) ; break;
case V_170 :
V_86 = F_132 ( V_5 , V_61 , V_63 ) ; break;
case V_171 :
V_86 = F_140 ( V_5 , V_61 , V_63 ) ; break;
case V_172 :
V_86 = F_143 ( V_5 , V_61 , V_63 ) ; break;
case V_173 :
V_86 = F_64 ( V_5 , V_61 , V_63 ) ; break;
default:
V_86 = - 1 ;
break;
}
return V_86 ;
}
static bool F_146 ( struct V_174 * V_175 , T_10 * V_176 )
{
if ( V_175 -> V_76 && ! regexec ( V_176 , V_175 -> V_76 , 0 , NULL , 0 ) )
return 1 ;
return 0 ;
}
static void F_147 ( struct V_22 * V_22 ,
struct V_177 * V_178 ,
T_6 V_179 )
{
struct V_180 V_181 ;
memset ( & V_181 , 0 , sizeof( V_181 ) ) ;
F_148 ( V_22 , V_84 , V_179 , & V_181 ) ;
V_178 -> V_104 = V_179 ;
V_178 -> V_182 = V_181 . V_104 ;
V_178 -> V_175 = V_181 . V_175 ;
V_178 -> V_82 = V_181 . V_82 ;
}
static void F_149 ( struct V_22 * V_22 ,
T_9 V_74 , struct V_177 * V_178 , T_6 V_104 )
{
struct V_180 V_181 ;
memset ( & V_181 , 0 , sizeof( V_181 ) ) ;
F_150 ( V_22 , V_74 , V_158 , V_104 , & V_181 ) ;
if ( V_181 . V_82 == NULL ) {
F_150 ( V_22 , V_74 , V_84 , V_104 , & V_181 ) ;
}
V_178 -> V_104 = V_104 ;
V_178 -> V_182 = V_181 . V_104 ;
V_178 -> V_175 = V_181 . V_175 ;
V_178 -> V_82 = V_181 . V_82 ;
}
struct V_183 * F_151 ( struct V_62 * V_63 ,
struct V_180 * V_181 )
{
struct V_183 * V_184 = F_152 ( sizeof( * V_184 ) ) ;
if ( ! V_184 )
return NULL ;
F_147 ( V_181 -> V_22 , & V_184 -> V_185 , V_63 -> V_179 ) ;
F_149 ( V_181 -> V_22 , V_181 -> V_152 , & V_184 -> V_186 , V_63 -> V_104 ) ;
V_184 -> V_187 . V_188 = V_63 -> V_187 ;
return V_184 ;
}
static int F_153 ( struct V_22 * V_22 ,
struct V_174 * * V_36 ,
struct V_180 * V_189 ,
T_9 * V_152 ,
T_6 V_179 )
{
struct V_180 V_181 ;
V_181 . V_190 = 0 ;
V_181 . V_175 = NULL ;
if ( ! V_152 ) {
F_148 ( V_22 , V_84 ,
V_179 , & V_181 ) ;
} else {
if ( V_179 >= V_191 ) {
switch ( V_179 ) {
case V_192 :
* V_152 = V_193 ;
break;
case V_194 :
* V_152 = V_155 ;
break;
case V_195 :
* V_152 = V_196 ;
break;
default:
F_101 ( L_46
L_47 V_197 L_14 , ( V_198 ) V_179 ) ;
F_154 ( & V_199 ) ;
return 1 ;
}
return 0 ;
}
F_150 ( V_22 , * V_152 , V_84 ,
V_179 , & V_181 ) ;
}
if ( V_181 . V_175 != NULL ) {
if ( V_200 && ! * V_36 &&
F_146 ( V_181 . V_175 , & V_201 ) )
* V_36 = V_181 . V_175 ;
else if ( V_202 && V_189 &&
F_146 ( V_181 . V_175 , & V_203 ) ) {
* V_189 = V_181 ;
F_154 ( & V_199 ) ;
}
}
return F_155 ( & V_199 , V_181 . V_104 , V_181 . V_82 , V_181 . V_175 ) ;
}
struct V_204 * F_156 ( struct V_62 * V_63 ,
struct V_180 * V_181 )
{
unsigned int V_88 ;
const struct V_205 * V_206 = V_63 -> V_205 ;
struct V_204 * V_207 = calloc ( V_206 -> V_208 , sizeof( struct V_204 ) ) ;
if ( ! V_207 )
return NULL ;
for ( V_88 = 0 ; V_88 < V_206 -> V_208 ; V_88 ++ ) {
F_147 ( V_181 -> V_22 , & V_207 [ V_88 ] . V_209 , V_206 -> V_210 [ V_88 ] . V_209 ) ;
F_147 ( V_181 -> V_22 , & V_207 [ V_88 ] . V_211 , V_206 -> V_210 [ V_88 ] . V_211 ) ;
V_207 [ V_88 ] . V_164 = V_206 -> V_210 [ V_88 ] . V_164 ;
}
return V_207 ;
}
static int F_157 ( struct V_212 * V_213 , int V_208 )
{
int V_88 , V_214 , V_215 ;
unsigned char V_216 [ V_217 ] ;
memset ( V_216 , V_218 , sizeof( V_216 ) ) ;
F_158 ( V_219 > 255 ) ;
for ( V_88 = 0 ; V_88 < V_208 ; V_88 ++ ) {
int V_220 = F_159 ( V_213 [ V_88 ] . V_211 , V_221 ) % V_217 ;
if ( V_216 [ V_220 ] == V_218 ) {
V_216 [ V_220 ] = V_88 ;
} else if ( V_213 [ V_216 [ V_220 ] ] . V_211 == V_213 [ V_88 ] . V_211 ) {
bool V_222 = true ;
V_215 = 0 ;
for ( V_214 = V_216 [ V_220 ] ; V_214 < V_88 && V_88 + V_215 < V_208 ; V_214 ++ , V_215 ++ )
if ( V_213 [ V_214 ] . V_211 != V_213 [ V_88 + V_215 ] . V_211 ) {
V_222 = false ;
break;
}
if ( V_222 ) {
memmove ( V_213 + V_88 , V_213 + V_88 + V_215 ,
( V_208 - ( V_88 + V_215 ) ) * sizeof( * V_213 ) ) ;
V_208 -= V_215 ;
}
}
}
return V_208 ;
}
static int F_160 ( struct V_22 * V_22 ,
struct V_62 * V_63 ,
struct V_174 * * V_36 ,
struct V_180 * V_189 ,
int V_223 )
{
struct V_224 * V_225 = V_63 -> V_226 ;
int V_227 = V_160 ( V_223 , ( int ) V_225 -> V_208 ) ;
T_9 V_152 = V_196 ;
int V_88 , V_214 , V_228 ;
T_6 V_179 ;
for ( V_88 = 0 ; V_88 < V_227 ; V_88 ++ ) {
if ( V_225 -> V_229 [ V_88 ] == V_195 )
break;
}
if ( V_88 != V_227 ) {
struct V_205 * V_230 = V_63 -> V_205 ;
int V_231 = V_230 -> V_208 ;
int V_232 = V_88 + 1 + V_231 + 1 ;
if ( V_232 > V_233 + V_219 ) {
F_161 ( L_48 ) ;
return 0 ;
}
for ( V_214 = 0 ; V_214 < V_232 ; V_214 ++ ) {
if ( V_234 . V_235 == V_236 ) {
if ( V_214 < V_88 + 1 )
V_179 = V_225 -> V_229 [ V_214 ] ;
else if ( V_214 > V_88 + 1 )
V_179 = V_230 -> V_210 [ V_214 - V_88 - 2 ] . V_211 ;
else
V_179 = V_230 -> V_210 [ 0 ] . V_209 ;
} else {
if ( V_214 < V_231 )
V_179 = V_230 -> V_210 [ V_231 - V_214 - 1 ] . V_211 ;
else if ( V_214 > V_231 )
V_179 = V_225 -> V_229 [ V_88 + 1 - ( V_214 - V_231 ) ] ;
else
V_179 = V_230 -> V_210 [ 0 ] . V_209 ;
}
V_228 = F_153 ( V_22 , V_36 , V_189 , & V_152 , V_179 ) ;
if ( V_228 )
return ( V_228 < 0 ) ? V_228 : 0 ;
}
return 1 ;
}
return 0 ;
}
static int F_162 ( struct V_22 * V_22 ,
struct V_237 * V_238 ,
struct V_62 * V_63 ,
struct V_174 * * V_36 ,
struct V_180 * V_189 ,
int V_223 )
{
struct V_205 * V_239 = V_63 -> V_205 ;
struct V_224 * V_225 = V_63 -> V_226 ;
int V_227 = V_160 ( V_223 , ( int ) V_225 -> V_208 ) ;
T_9 V_152 = V_196 ;
int V_88 , V_214 , V_228 ;
int V_240 = - 1 ;
int V_241 = 0 ;
F_154 ( & V_199 ) ;
if ( F_163 ( V_238 ) ) {
V_228 = F_160 ( V_22 , V_63 , V_36 ,
V_189 , V_223 ) ;
if ( V_228 )
return ( V_228 < 0 ) ? V_228 : 0 ;
}
if ( V_225 -> V_208 < V_233 )
V_240 = F_164 ( V_22 , V_225 ) ;
if ( V_239 && V_234 . V_242 ) {
int V_208 = V_160 ( V_223 , ( int ) V_239 -> V_208 ) ;
struct V_212 V_243 [ V_208 ] ;
if ( V_239 -> V_208 > V_219 ) {
F_161 ( L_49 ) ;
goto V_244;
}
for ( V_88 = 0 ; V_88 < V_208 ; V_88 ++ ) {
if ( V_234 . V_235 == V_236 ) {
V_243 [ V_88 ] = V_239 -> V_210 [ V_88 ] ;
if ( V_88 == V_240 ||
V_225 -> V_229 [ V_241 ] >= V_191 )
V_241 ++ ;
else if ( V_243 [ V_88 ] . V_211 < V_225 -> V_229 [ V_241 ] &&
V_243 [ V_88 ] . V_211 >= V_225 -> V_229 [ V_241 ] - 8 )
V_241 ++ ;
} else
V_243 [ V_88 ] = V_239 -> V_210 [ V_239 -> V_208 - V_88 - 1 ] ;
}
V_208 = F_157 ( V_243 , V_208 ) ;
for ( V_88 = 0 ; V_88 < V_208 ; V_88 ++ ) {
V_228 = F_153 ( V_22 , V_36 , V_189 ,
NULL , V_243 [ V_88 ] . V_209 ) ;
if ( ! V_228 )
V_228 = F_153 ( V_22 , V_36 , V_189 ,
NULL , V_243 [ V_88 ] . V_211 ) ;
if ( V_228 == - V_245 )
break;
if ( V_228 )
return V_228 ;
}
V_227 -= V_208 ;
}
V_244:
if ( V_225 -> V_208 > V_233 ) {
F_161 ( L_48 ) ;
return 0 ;
}
for ( V_88 = V_241 ; V_88 < V_227 ; V_88 ++ ) {
T_6 V_179 ;
if ( V_234 . V_235 == V_236 )
V_214 = V_88 ;
else
V_214 = V_225 -> V_208 - V_88 - 1 ;
#ifdef F_165
if ( V_214 == V_240 )
continue;
#endif
V_179 = V_225 -> V_229 [ V_214 ] ;
V_228 = F_153 ( V_22 , V_36 , V_189 , & V_152 , V_179 ) ;
if ( V_228 )
return ( V_228 < 0 ) ? V_228 : 0 ;
}
return 0 ;
}
static int F_166 ( struct F_166 * V_246 , void * V_140 )
{
struct V_199 * V_247 = V_140 ;
return F_155 ( V_247 , V_246 -> V_179 ,
V_246 -> V_82 , V_246 -> V_175 ) ;
}
int F_167 ( struct V_22 * V_22 ,
struct V_237 * V_238 ,
struct V_62 * V_63 ,
struct V_174 * * V_36 ,
struct V_180 * V_189 ,
int V_223 )
{
int V_86 = F_162 ( V_22 , V_238 ,
V_63 , V_36 ,
V_189 , V_223 ) ;
if ( V_86 )
return V_86 ;
if ( ! ( ( V_238 -> V_248 . V_249 & V_250 ) &&
( V_238 -> V_248 . V_249 & V_251 ) ) )
return 0 ;
if ( ( ! V_63 -> V_252 . V_253 ) ||
( ! V_63 -> V_254 . V_52 ) )
return 0 ;
return F_168 ( F_166 , & V_199 ,
V_22 , V_63 , V_223 ) ;
}
int F_169 ( struct V_5 * V_5 ,
int (* F_170)( struct V_22 * V_22 , void * V_35 ) ,
void * V_255 )
{
struct V_9 * V_30 ;
struct V_22 * V_22 ;
int V_256 = 0 ;
for ( V_30 = F_16 ( & V_5 -> V_12 ) ; V_30 ; V_30 = F_18 ( V_30 ) ) {
V_22 = F_17 ( V_30 , struct V_22 , V_9 ) ;
V_256 = F_170 ( V_22 , V_255 ) ;
if ( V_256 != 0 )
return V_256 ;
}
F_126 (thread, &machine->dead_threads, node) {
V_256 = F_170 ( V_22 , V_255 ) ;
if ( V_256 != 0 )
return V_256 ;
}
return V_256 ;
}
int F_171 ( struct V_5 * V_5 , struct V_257 * V_258 ,
struct V_259 * V_259 , struct V_260 * V_12 ,
T_11 V_49 , bool V_261 )
{
if ( F_172 ( V_259 ) )
return F_173 ( V_258 , V_12 , V_49 , V_5 , V_261 ) ;
else if ( F_174 ( V_259 ) )
return F_175 ( V_258 , V_49 , V_5 , V_261 ) ;
return 0 ;
}
T_1 F_176 ( struct V_5 * V_5 , int V_262 )
{
if ( V_262 < 0 || V_262 >= V_263 || ! V_5 -> V_24 )
return - 1 ;
return V_5 -> V_24 [ V_262 ] ;
}
int F_177 ( struct V_5 * V_5 , int V_262 , T_1 V_7 ,
T_1 V_56 )
{
struct V_22 * V_22 ;
if ( V_262 < 0 )
return - V_245 ;
if ( ! V_5 -> V_24 ) {
int V_88 ;
V_5 -> V_24 = calloc ( V_263 , sizeof( T_1 ) ) ;
if ( ! V_5 -> V_24 )
return - V_20 ;
for ( V_88 = 0 ; V_88 < V_263 ; V_88 ++ )
V_5 -> V_24 [ V_88 ] = - 1 ;
}
if ( V_262 >= V_263 ) {
F_37 ( L_50 , V_262 ) ;
F_37 ( L_51 ) ;
return - V_245 ;
}
V_5 -> V_24 [ V_262 ] = V_56 ;
V_22 = F_7 ( V_5 , V_7 , V_56 ) ;
if ( ! V_22 )
return - V_20 ;
V_22 -> V_262 = V_262 ;
return 0 ;
}
int F_178 ( struct V_5 * V_5 )
{
struct V_82 * V_82 = F_179 ( V_5 , V_84 ) ;
int V_228 = 0 ;
V_5 -> V_19 = 1ULL << 63 ;
if ( V_82 ) {
V_228 = F_180 ( V_82 , V_5 -> V_16 ) ;
if ( V_82 -> V_83 )
V_5 -> V_19 = V_82 -> V_83 ;
}
return V_228 ;
}
