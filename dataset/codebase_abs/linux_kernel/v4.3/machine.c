static void F_1 ( struct V_1 * V_1 )
{
F_2 ( & V_1 -> V_2 ) ;
V_1 -> V_3 = V_4 ;
F_3 ( & V_1 -> V_5 , NULL ) ;
}
int F_4 ( struct V_6 * V_6 , const char * V_7 , T_1 V_8 )
{
F_5 ( & V_6 -> V_9 , V_6 ) ;
F_6 ( & V_6 -> V_10 ) ;
F_1 ( & V_6 -> V_1 ) ;
V_6 -> V_11 = V_4 ;
F_3 ( & V_6 -> V_12 , NULL ) ;
F_2 ( & V_6 -> V_13 ) ;
V_6 -> V_14 = NULL ;
V_6 -> V_15 = NULL ;
V_6 -> V_8 = V_8 ;
V_6 -> V_16 = NULL ;
V_6 -> V_17 = 0 ;
V_6 -> V_18 = false ;
V_6 -> V_19 = 0 ;
V_6 -> V_7 = F_7 ( V_7 ) ;
if ( V_6 -> V_7 == NULL )
return - V_20 ;
if ( V_8 != V_21 ) {
struct V_22 * V_22 = F_8 ( V_6 , - 1 ,
V_8 ) ;
char V_23 [ 64 ] ;
if ( V_22 == NULL )
return - V_20 ;
snprintf ( V_23 , sizeof( V_23 ) , L_1 , V_8 ) ;
F_9 ( V_22 , V_23 , 0 ) ;
F_10 ( V_22 ) ;
}
V_6 -> V_24 = NULL ;
return 0 ;
}
struct V_6 * F_11 ( void )
{
struct V_6 * V_6 = malloc ( sizeof( * V_6 ) ) ;
if ( V_6 != NULL ) {
F_4 ( V_6 , L_2 , V_21 ) ;
if ( F_12 ( V_6 ) < 0 )
goto V_25;
}
return V_6 ;
V_25:
free ( V_6 ) ;
return NULL ;
}
static void F_13 ( struct V_1 * V_1 )
{
struct V_26 * V_27 , * V_28 ;
F_14 ( & V_1 -> V_5 ) ;
F_15 (pos, n, &dsos->head, node) {
F_6 ( & V_27 -> V_10 ) ;
F_16 ( & V_27 -> V_29 ) ;
F_17 ( V_27 ) ;
}
F_18 ( & V_1 -> V_5 ) ;
}
static void F_19 ( struct V_1 * V_1 )
{
F_13 ( V_1 ) ;
F_20 ( & V_1 -> V_5 ) ;
}
void F_21 ( struct V_6 * V_6 )
{
struct V_10 * V_30 ;
F_14 ( & V_6 -> V_12 ) ;
V_30 = F_22 ( & V_6 -> V_11 ) ;
while ( V_30 ) {
struct V_22 * V_31 = F_23 ( V_30 , struct V_22 , V_10 ) ;
V_30 = F_24 ( V_30 ) ;
F_25 ( V_6 , V_31 , false ) ;
}
F_18 ( & V_6 -> V_12 ) ;
}
void F_26 ( struct V_6 * V_6 )
{
F_27 ( & V_6 -> V_9 ) ;
F_19 ( & V_6 -> V_1 ) ;
F_28 ( V_6 ) ;
F_29 ( & V_6 -> V_7 ) ;
F_29 ( & V_6 -> V_24 ) ;
F_20 ( & V_6 -> V_12 ) ;
}
void F_30 ( struct V_6 * V_6 )
{
F_26 ( V_6 ) ;
free ( V_6 ) ;
}
void F_31 ( struct V_32 * V_32 )
{
F_4 ( & V_32 -> V_33 , L_2 , V_21 ) ;
V_32 -> V_34 = V_4 ;
V_32 -> V_16 = NULL ;
}
void F_32 ( struct V_32 * V_32 )
{
F_26 ( & V_32 -> V_33 ) ;
}
struct V_6 * F_33 ( struct V_32 * V_32 , T_1 V_8 ,
const char * V_7 )
{
struct V_10 * * V_35 = & V_32 -> V_34 . V_10 ;
struct V_10 * V_36 = NULL ;
struct V_6 * V_27 , * V_6 = malloc ( sizeof( * V_6 ) ) ;
if ( V_6 == NULL )
return NULL ;
if ( F_4 ( V_6 , V_7 , V_8 ) != 0 ) {
free ( V_6 ) ;
return NULL ;
}
V_6 -> V_16 = V_32 -> V_16 ;
while ( * V_35 != NULL ) {
V_36 = * V_35 ;
V_27 = F_23 ( V_36 , struct V_6 , V_10 ) ;
if ( V_8 < V_27 -> V_8 )
V_35 = & ( * V_35 ) -> V_37 ;
else
V_35 = & ( * V_35 ) -> V_38 ;
}
F_34 ( & V_6 -> V_10 , V_36 , V_35 ) ;
F_35 ( & V_6 -> V_10 , & V_32 -> V_34 ) ;
return V_6 ;
}
void F_36 ( struct V_32 * V_32 ,
T_2 V_16 )
{
struct V_10 * V_30 ;
V_32 -> V_16 = V_16 ;
V_32 -> V_33 . V_16 = V_16 ;
for ( V_30 = F_22 ( & V_32 -> V_34 ) ; V_30 ; V_30 = F_24 ( V_30 ) ) {
struct V_6 * V_6 = F_23 ( V_30 , struct V_6 , V_10 ) ;
V_6 -> V_16 = V_16 ;
}
}
void F_37 ( struct V_32 * V_32 , bool V_18 )
{
struct V_10 * V_30 ;
V_32 -> V_33 . V_18 = V_18 ;
for ( V_30 = F_22 ( & V_32 -> V_34 ) ; V_30 ; V_30 = F_24 ( V_30 ) ) {
struct V_6 * V_6 = F_23 ( V_30 , struct V_6 , V_10 ) ;
V_6 -> V_18 = V_18 ;
}
}
struct V_6 * F_38 ( struct V_32 * V_32 , T_1 V_8 )
{
struct V_10 * * V_35 = & V_32 -> V_34 . V_10 ;
struct V_10 * V_36 = NULL ;
struct V_6 * V_6 ;
struct V_6 * V_39 = NULL ;
if ( V_8 == V_21 )
return & V_32 -> V_33 ;
while ( * V_35 != NULL ) {
V_36 = * V_35 ;
V_6 = F_23 ( V_36 , struct V_6 , V_10 ) ;
if ( V_8 < V_6 -> V_8 )
V_35 = & ( * V_35 ) -> V_37 ;
else if ( V_8 > V_6 -> V_8 )
V_35 = & ( * V_35 ) -> V_38 ;
else
return V_6 ;
if ( ! V_6 -> V_8 )
V_39 = V_6 ;
}
return V_39 ;
}
struct V_6 * F_39 ( struct V_32 * V_32 , T_1 V_8 )
{
char V_40 [ V_41 ] ;
const char * V_7 = L_2 ;
struct V_6 * V_6 = F_38 ( V_32 , V_8 ) ;
if ( V_6 && ( V_6 -> V_8 == V_8 ) )
goto V_42;
if ( ( V_8 != V_21 ) &&
( V_8 != V_43 ) &&
( V_44 . V_45 ) ) {
sprintf ( V_40 , L_3 , V_44 . V_45 , V_8 ) ;
if ( F_40 ( V_40 , V_46 ) ) {
static struct V_47 * V_48 ;
if ( ! V_48 )
V_48 = F_41 ( NULL , NULL ) ;
if ( ! F_42 ( V_48 , V_40 ) ) {
F_43 ( L_4 , V_40 ) ;
F_44 ( V_48 , V_40 ) ;
}
V_6 = NULL ;
goto V_42;
}
V_7 = V_40 ;
}
V_6 = F_33 ( V_32 , V_8 , V_7 ) ;
V_42:
return V_6 ;
}
void F_45 ( struct V_32 * V_32 ,
T_3 V_49 , void * V_50 )
{
struct V_10 * V_30 ;
for ( V_30 = F_22 ( & V_32 -> V_34 ) ; V_30 ; V_30 = F_24 ( V_30 ) ) {
struct V_6 * V_27 = F_23 ( V_30 , struct V_6 , V_10 ) ;
V_49 ( V_27 , V_50 ) ;
}
}
char * F_46 ( struct V_6 * V_6 , char * V_51 , T_4 V_52 )
{
if ( F_47 ( V_6 ) )
snprintf ( V_51 , V_52 , L_5 , L_6 ) ;
else if ( F_48 ( V_6 ) )
snprintf ( V_51 , V_52 , L_5 , L_7 ) ;
else {
snprintf ( V_51 , V_52 , L_8 , L_7 ,
V_6 -> V_8 ) ;
}
return V_51 ;
}
void F_49 ( struct V_32 * V_32 , T_5 V_17 )
{
struct V_10 * V_29 ;
struct V_6 * V_6 ;
V_32 -> V_33 . V_17 = V_17 ;
for ( V_29 = F_22 ( & V_32 -> V_34 ) ; V_29 ; V_29 = F_24 ( V_29 ) ) {
V_6 = F_23 ( V_29 , struct V_6 , V_10 ) ;
V_6 -> V_17 = V_17 ;
}
return;
}
static void F_50 ( struct V_6 * V_6 ,
struct V_22 * V_53 , T_1 V_8 )
{
struct V_22 * V_54 ;
if ( V_8 == V_53 -> V_55 || V_8 == - 1 || V_53 -> V_55 != - 1 )
return;
V_53 -> V_55 = V_8 ;
if ( V_53 -> V_55 == V_53 -> V_56 )
return;
V_54 = F_51 ( V_6 , V_53 -> V_55 , V_53 -> V_55 ) ;
if ( ! V_54 )
goto V_57;
if ( ! V_54 -> V_58 )
V_54 -> V_58 = F_52 ( V_6 ) ;
if ( ! V_54 -> V_58 )
goto V_57;
if ( V_53 -> V_58 == V_54 -> V_58 )
return;
if ( V_53 -> V_58 ) {
if ( ! F_53 ( V_53 -> V_58 ) )
F_43 ( L_9 ,
V_53 -> V_55 , V_53 -> V_56 ) ;
F_54 ( V_53 -> V_58 ) ;
}
V_53 -> V_58 = F_55 ( V_54 -> V_58 ) ;
return;
V_57:
F_43 ( L_10 , V_53 -> V_55 , V_53 -> V_56 ) ;
}
static struct V_22 * F_56 ( struct V_6 * V_6 ,
T_1 V_8 , T_1 V_56 ,
bool V_59 )
{
struct V_10 * * V_35 = & V_6 -> V_11 . V_10 ;
struct V_10 * V_36 = NULL ;
struct V_22 * V_53 ;
V_53 = V_6 -> V_14 ;
if ( V_53 != NULL ) {
if ( V_53 -> V_56 == V_56 ) {
F_50 ( V_6 , V_53 , V_8 ) ;
return V_53 ;
}
V_6 -> V_14 = NULL ;
}
while ( * V_35 != NULL ) {
V_36 = * V_35 ;
V_53 = F_23 ( V_36 , struct V_22 , V_10 ) ;
if ( V_53 -> V_56 == V_56 ) {
V_6 -> V_14 = V_53 ;
F_50 ( V_6 , V_53 , V_8 ) ;
return V_53 ;
}
if ( V_56 < V_53 -> V_56 )
V_35 = & ( * V_35 ) -> V_37 ;
else
V_35 = & ( * V_35 ) -> V_38 ;
}
if ( ! V_59 )
return NULL ;
V_53 = F_57 ( V_8 , V_56 ) ;
if ( V_53 != NULL ) {
F_34 ( & V_53 -> V_10 , V_36 , V_35 ) ;
F_35 ( & V_53 -> V_10 , & V_6 -> V_11 ) ;
if ( F_58 ( V_53 , V_6 ) ) {
F_59 ( & V_53 -> V_10 , & V_6 -> V_11 ) ;
F_6 ( & V_53 -> V_10 ) ;
F_60 ( V_53 ) ;
return NULL ;
}
F_61 ( V_53 ) ;
V_6 -> V_14 = V_53 ;
}
return V_53 ;
}
struct V_22 * F_51 ( struct V_6 * V_6 , T_1 V_8 , T_1 V_56 )
{
return F_56 ( V_6 , V_8 , V_56 , true ) ;
}
struct V_22 * F_8 ( struct V_6 * V_6 , T_1 V_8 ,
T_1 V_56 )
{
struct V_22 * V_53 ;
F_14 ( & V_6 -> V_12 ) ;
V_53 = F_61 ( F_51 ( V_6 , V_8 , V_56 ) ) ;
F_18 ( & V_6 -> V_12 ) ;
return V_53 ;
}
struct V_22 * F_62 ( struct V_6 * V_6 , T_1 V_8 ,
T_1 V_56 )
{
struct V_22 * V_53 ;
F_63 ( & V_6 -> V_12 ) ;
V_53 = F_61 ( F_56 ( V_6 , V_8 , V_56 , false ) ) ;
F_18 ( & V_6 -> V_12 ) ;
return V_53 ;
}
struct V_23 * F_64 ( struct V_6 * V_6 ,
struct V_22 * V_22 )
{
if ( V_6 -> V_18 )
return F_65 ( V_22 ) ;
else
return F_66 ( V_22 ) ;
}
int F_67 ( struct V_6 * V_6 , union V_60 * V_61 ,
struct V_62 * V_63 )
{
struct V_22 * V_22 = F_8 ( V_6 ,
V_61 -> V_23 . V_8 ,
V_61 -> V_23 . V_56 ) ;
bool V_64 = V_61 -> V_65 . V_66 & V_67 ;
int V_68 = 0 ;
if ( V_64 )
V_6 -> V_18 = true ;
if ( V_69 )
F_68 ( V_61 , stdout ) ;
if ( V_22 == NULL ||
F_69 ( V_22 , V_61 -> V_23 . V_23 , V_63 -> time , V_64 ) ) {
F_70 ( L_11 ) ;
V_68 = - 1 ;
}
F_10 ( V_22 ) ;
return V_68 ;
}
int F_71 ( struct V_6 * V_6 V_70 ,
union V_60 * V_61 , struct V_62 * V_63 V_70 )
{
F_70 ( L_12 V_71 L_13 V_71 L_14 ,
V_61 -> V_72 . V_73 , V_61 -> V_72 . V_72 ) ;
return 0 ;
}
int F_72 ( struct V_6 * V_6 V_70 ,
union V_60 * V_61 , struct V_62 * V_63 )
{
F_70 ( L_12 V_71 L_15 V_71 L_14 ,
V_63 -> V_73 , V_61 -> V_74 . V_72 ) ;
return 0 ;
}
static struct V_26 * F_73 ( struct V_6 * V_6 ,
struct V_75 * V_76 ,
const char * V_77 )
{
struct V_26 * V_26 ;
F_14 ( & V_6 -> V_1 . V_5 ) ;
V_26 = F_74 ( & V_6 -> V_1 , V_76 -> V_78 , true ) ;
if ( ! V_26 ) {
V_26 = F_75 ( & V_6 -> V_1 , V_76 -> V_78 ) ;
if ( V_26 == NULL )
goto V_79;
if ( F_47 ( V_6 ) )
V_26 -> V_80 = V_81 ;
else
V_26 -> V_80 = V_82 ;
if ( V_76 -> V_83 && V_76 -> V_84 )
V_26 -> V_80 ++ ;
F_76 ( V_26 , F_7 ( V_76 -> V_78 ) , true ) ;
F_77 ( V_26 , F_7 ( V_77 ) , true ) ;
}
F_78 ( V_26 ) ;
V_79:
F_18 ( & V_6 -> V_1 . V_5 ) ;
return V_26 ;
}
int F_79 ( struct V_6 * V_6 V_70 ,
union V_60 * V_61 )
{
if ( V_69 )
F_80 ( V_61 , stdout ) ;
return 0 ;
}
int F_81 ( struct V_6 * V_6 V_70 ,
union V_60 * V_61 )
{
if ( V_69 )
F_82 ( V_61 , stdout ) ;
return 0 ;
}
int F_83 ( struct V_6 * V_6 V_70 ,
union V_60 * V_61 )
{
if ( V_69 )
F_84 ( V_61 , stdout ) ;
return 0 ;
}
struct V_85 * F_85 ( struct V_6 * V_6 , T_6 V_86 ,
const char * V_77 )
{
struct V_85 * V_85 = NULL ;
struct V_26 * V_26 ;
struct V_75 V_76 ;
if ( F_86 ( & V_76 , V_77 ) )
return NULL ;
V_85 = F_87 ( & V_6 -> V_9 , V_87 ,
V_76 . V_78 ) ;
if ( V_85 )
goto V_42;
V_26 = F_73 ( V_6 , & V_76 , V_77 ) ;
if ( V_26 == NULL )
goto V_42;
V_85 = F_88 ( V_86 , V_26 , V_87 ) ;
if ( V_85 == NULL )
goto V_42;
F_89 ( & V_6 -> V_9 , V_85 ) ;
V_42:
free ( V_76 . V_78 ) ;
return V_85 ;
}
T_4 F_90 ( struct V_32 * V_32 , T_7 * V_88 )
{
struct V_10 * V_30 ;
T_4 V_89 = F_91 ( & V_32 -> V_33 . V_1 . V_2 , V_88 ) ;
for ( V_30 = F_22 ( & V_32 -> V_34 ) ; V_30 ; V_30 = F_24 ( V_30 ) ) {
struct V_6 * V_27 = F_23 ( V_30 , struct V_6 , V_10 ) ;
V_89 += F_91 ( & V_27 -> V_1 . V_2 , V_88 ) ;
}
return V_89 ;
}
T_4 F_92 ( struct V_6 * V_76 , T_7 * V_88 ,
bool (F_93)( struct V_26 * V_26 , int V_90 ) , int V_90 )
{
return F_94 ( & V_76 -> V_1 . V_2 , V_88 , F_93 , V_90 ) ;
}
T_4 F_95 ( struct V_32 * V_32 , T_7 * V_88 ,
bool (F_93)( struct V_26 * V_26 , int V_90 ) , int V_90 )
{
struct V_10 * V_30 ;
T_4 V_89 = F_92 ( & V_32 -> V_33 , V_88 , F_93 , V_90 ) ;
for ( V_30 = F_22 ( & V_32 -> V_34 ) ; V_30 ; V_30 = F_24 ( V_30 ) ) {
struct V_6 * V_27 = F_23 ( V_30 , struct V_6 , V_10 ) ;
V_89 += F_92 ( V_27 , V_88 , F_93 , V_90 ) ;
}
return V_89 ;
}
T_4 F_96 ( struct V_6 * V_6 , T_7 * V_88 )
{
int V_91 ;
T_4 V_92 = 0 ;
struct V_26 * V_93 = V_6 -> V_94 [ V_87 ] -> V_26 ;
if ( V_93 -> V_95 ) {
char V_77 [ V_41 ] ;
if ( F_97 ( V_93 , V_77 , sizeof( V_77 ) ) )
V_92 += fprintf ( V_88 , L_16 , V_77 ) ;
}
for ( V_91 = 0 ; V_91 < V_96 ; ++ V_91 )
V_92 += fprintf ( V_88 , L_17 ,
V_91 + V_93 -> V_95 , V_97 [ V_91 ] ) ;
return V_92 ;
}
T_4 F_98 ( struct V_6 * V_6 , T_7 * V_88 )
{
T_4 V_89 = 0 ;
struct V_10 * V_30 ;
F_63 ( & V_6 -> V_12 ) ;
for ( V_30 = F_22 ( & V_6 -> V_11 ) ; V_30 ; V_30 = F_24 ( V_30 ) ) {
struct V_22 * V_27 = F_23 ( V_30 , struct V_22 , V_10 ) ;
V_89 += F_99 ( V_27 , V_88 ) ;
}
F_18 ( & V_6 -> V_12 ) ;
return V_89 ;
}
static struct V_26 * F_100 ( struct V_6 * V_6 )
{
const char * V_98 = NULL ;
struct V_26 * V_99 ;
if ( F_47 ( V_6 ) ) {
V_98 = V_44 . V_98 ;
if ( ! V_98 )
V_98 = L_18 ;
V_99 = F_101 ( V_6 , V_98 ,
L_19 , V_100 ) ;
} else {
char V_51 [ V_41 ] ;
if ( F_48 ( V_6 ) )
V_98 = V_44 . V_101 ;
if ( ! V_98 )
V_98 = F_46 ( V_6 , V_51 ,
sizeof( V_51 ) ) ;
V_99 = F_101 ( V_6 , V_98 ,
L_20 ,
V_102 ) ;
}
if ( V_99 != NULL && ( ! V_99 -> V_95 ) )
F_102 ( V_99 , V_6 ) ;
return V_99 ;
}
static void F_103 ( struct V_6 * V_6 , char * V_103 ,
T_4 V_104 )
{
if ( F_48 ( V_6 ) )
F_104 ( V_103 , V_104 , L_21 , V_44 . V_105 ) ;
else
F_104 ( V_103 , V_104 , L_22 , V_6 -> V_7 ) ;
}
static T_6 F_105 ( struct V_6 * V_6 ,
const char * * V_106 )
{
char V_77 [ V_41 ] ;
int V_91 ;
const char * V_78 ;
T_6 V_107 = 0 ;
F_103 ( V_6 , V_77 , V_41 ) ;
if ( F_106 ( V_77 , L_23 ) )
return 0 ;
for ( V_91 = 0 ; ( V_78 = V_108 [ V_91 ] ) != NULL ; V_91 ++ ) {
V_107 = F_107 ( V_77 , V_78 ) ;
if ( V_107 )
break;
}
if ( V_106 )
* V_106 = V_78 ;
return V_107 ;
}
int F_108 ( struct V_6 * V_6 , struct V_26 * V_99 )
{
enum V_109 type ;
T_6 V_86 = F_105 ( V_6 , NULL ) ;
for ( type = 0 ; type < V_110 ; ++ type ) {
struct V_111 * V_111 ;
V_6 -> V_94 [ type ] = F_88 ( V_86 , V_99 , type ) ;
if ( V_6 -> V_94 [ type ] == NULL )
return - 1 ;
V_6 -> V_94 [ type ] -> V_112 =
V_6 -> V_94 [ type ] -> V_113 =
V_114 ;
V_111 = F_109 ( V_6 -> V_94 [ type ] ) ;
if ( ! V_111 )
return - 1 ;
V_111 -> V_9 = & V_6 -> V_9 ;
F_89 ( & V_6 -> V_9 ,
V_6 -> V_94 [ type ] ) ;
}
return 0 ;
}
void F_110 ( struct V_6 * V_6 )
{
enum V_109 type ;
for ( type = 0 ; type < V_110 ; ++ type ) {
struct V_111 * V_111 ;
if ( V_6 -> V_94 [ type ] == NULL )
continue;
V_111 = F_109 ( V_6 -> V_94 [ type ] ) ;
F_111 ( & V_6 -> V_9 ,
V_6 -> V_94 [ type ] ) ;
if ( V_111 && V_111 -> V_115 ) {
if ( type == V_87 ) {
F_29 ( ( char * * ) & V_111 -> V_115 -> V_78 ) ;
F_29 ( & V_111 -> V_115 ) ;
} else
V_111 -> V_115 = NULL ;
}
V_6 -> V_94 [ type ] = NULL ;
}
}
int F_112 ( struct V_32 * V_32 )
{
int V_89 = 0 ;
struct V_116 * * V_117 = NULL ;
int V_91 , V_118 = 0 ;
char V_40 [ V_41 ] ;
T_1 V_8 ;
char * V_119 ;
if ( V_44 . V_101 ||
V_44 . V_120 ||
V_44 . V_105 ) {
F_113 ( V_32 , V_43 ) ;
}
if ( V_44 . V_45 ) {
V_118 = F_114 ( V_44 . V_45 , & V_117 , NULL , NULL ) ;
if ( V_118 <= 0 )
return - V_121 ;
for ( V_91 = 0 ; V_91 < V_118 ; V_91 ++ ) {
if ( ! isdigit ( V_117 [ V_91 ] -> V_122 [ 0 ] ) ) {
continue;
}
V_8 = ( T_1 ) strtol ( V_117 [ V_91 ] -> V_122 , & V_119 , 10 ) ;
if ( ( * V_119 != '\0' ) ||
( V_119 == V_117 [ V_91 ] -> V_122 ) ||
( V_123 == V_124 ) ) {
F_115 ( L_24 ,
V_117 [ V_91 ] -> V_122 ) ;
continue;
}
sprintf ( V_40 , L_25 ,
V_44 . V_45 ,
V_117 [ V_91 ] -> V_122 ) ;
V_89 = F_40 ( V_40 , V_46 ) ;
if ( V_89 ) {
F_115 ( L_4 , V_40 ) ;
goto V_125;
}
F_113 ( V_32 , V_8 ) ;
}
V_125:
free ( V_117 ) ;
}
return V_89 ;
}
void F_116 ( struct V_32 * V_32 )
{
struct V_10 * V_126 = F_22 ( & V_32 -> V_34 ) ;
F_110 ( & V_32 -> V_33 ) ;
while ( V_126 ) {
struct V_6 * V_27 = F_23 ( V_126 , struct V_6 , V_10 ) ;
V_126 = F_24 ( & V_27 -> V_10 ) ;
F_117 ( & V_27 -> V_10 , & V_32 -> V_34 ) ;
F_30 ( V_27 ) ;
}
}
int F_113 ( struct V_32 * V_32 , T_1 V_8 )
{
struct V_6 * V_6 = F_39 ( V_32 , V_8 ) ;
if ( V_6 == NULL )
return - 1 ;
return F_12 ( V_6 ) ;
}
int F_118 ( struct V_6 * V_6 , const char * V_77 ,
enum V_109 type , T_2 V_127 )
{
struct V_85 * V_85 = V_6 -> V_94 [ type ] ;
int V_89 = F_119 ( V_85 -> V_26 , V_77 , V_85 , V_127 ) ;
if ( V_89 > 0 ) {
F_120 ( V_85 -> V_26 , type ) ;
F_121 ( & V_6 -> V_9 , type ) ;
}
return V_89 ;
}
int F_122 ( struct V_6 * V_6 , enum V_109 type ,
T_2 V_127 )
{
struct V_85 * V_85 = V_6 -> V_94 [ type ] ;
int V_89 = F_123 ( V_85 -> V_26 , V_85 , V_127 ) ;
if ( V_89 > 0 )
F_120 ( V_85 -> V_26 , type ) ;
return V_89 ;
}
static void F_124 ( struct V_128 * V_58 )
{
int V_91 ;
for ( V_91 = 0 ; V_91 < V_110 ; ++ V_91 )
F_121 ( V_58 , V_91 ) ;
}
static char * F_125 ( const char * V_7 )
{
char V_129 [ V_41 ] ;
T_7 * V_130 ;
char * V_78 , * V_131 ;
const char * V_132 = L_26 ;
sprintf ( V_129 , L_27 , V_7 ) ;
V_130 = fopen ( V_129 , L_28 ) ;
if ( ! V_130 )
return NULL ;
V_129 [ 0 ] = '\0' ;
V_131 = fgets ( V_129 , sizeof( V_129 ) , V_130 ) ;
fclose ( V_130 ) ;
V_78 = strstr ( V_129 , V_132 ) ;
if ( ! V_78 )
return NULL ;
V_78 += strlen ( V_132 ) ;
V_131 = strchr ( V_78 , ' ' ) ;
if ( V_131 )
* V_131 = '\0' ;
return F_7 ( V_78 ) ;
}
static bool F_126 ( struct V_26 * V_26 )
{
return V_26 -> V_80 == V_81 ||
V_26 -> V_80 == V_82 ;
}
static int F_127 ( struct V_128 * V_58 , const char * V_40 ,
struct V_75 * V_76 )
{
struct V_85 * V_85 ;
char * V_133 ;
V_85 = F_87 ( V_58 , V_87 , V_76 -> V_78 ) ;
if ( V_85 == NULL )
return 0 ;
V_133 = F_7 ( V_40 ) ;
if ( V_133 == NULL )
return - V_20 ;
F_77 ( V_85 -> V_26 , V_133 , true ) ;
F_128 ( V_85 -> V_26 , L_2 ) ;
if ( V_76 -> V_84 && F_126 ( V_85 -> V_26 ) )
V_85 -> V_26 -> V_80 ++ ;
return 0 ;
}
static int F_129 ( struct V_128 * V_58 ,
const char * V_134 , int V_135 )
{
struct V_116 * V_136 ;
T_8 * V_137 = F_130 ( V_134 ) ;
int V_89 = 0 ;
if ( ! V_137 ) {
F_115 ( L_29 , V_138 , V_134 ) ;
return - 1 ;
}
while ( ( V_136 = F_131 ( V_137 ) ) != NULL ) {
char V_40 [ V_41 ] ;
struct V_139 V_140 ;
snprintf ( V_40 , sizeof( V_40 ) , L_30 , V_134 , V_136 -> V_122 ) ;
if ( V_139 ( V_40 , & V_140 ) )
continue;
if ( F_132 ( V_140 . V_141 ) ) {
if ( ! strcmp ( V_136 -> V_122 , L_31 ) ||
! strcmp ( V_136 -> V_122 , L_32 ) )
continue;
if ( V_135 == 0 ) {
if ( ! strcmp ( V_136 -> V_122 , L_33 ) ||
! strcmp ( V_136 -> V_122 , L_34 ) )
continue;
}
V_89 = F_129 ( V_58 , V_40 ,
V_135 + 1 ) ;
if ( V_89 < 0 )
goto V_42;
} else {
struct V_75 V_76 ;
V_89 = F_86 ( & V_76 , V_136 -> V_122 ) ;
if ( V_89 )
goto V_42;
if ( V_76 . V_83 )
V_89 = F_127 ( V_58 , V_40 , & V_76 ) ;
free ( V_76 . V_78 ) ;
if ( V_89 )
goto V_42;
}
}
V_42:
F_133 ( V_137 ) ;
return V_89 ;
}
static int F_134 ( struct V_6 * V_6 )
{
char * V_129 ;
char V_142 [ V_41 ] ;
V_129 = F_125 ( V_6 -> V_7 ) ;
if ( ! V_129 )
return - 1 ;
snprintf ( V_142 , sizeof( V_142 ) , L_35 ,
V_6 -> V_7 , V_129 ) ;
free ( V_129 ) ;
return F_129 ( & V_6 -> V_9 , V_142 , 0 ) ;
}
static int F_135 ( void * V_143 , const char * V_78 , T_6 V_86 )
{
struct V_6 * V_6 = V_143 ;
struct V_85 * V_85 ;
V_85 = F_85 ( V_6 , V_86 , V_78 ) ;
if ( V_85 == NULL )
return - 1 ;
F_128 ( V_85 -> V_26 , V_6 -> V_7 ) ;
return 0 ;
}
static int F_136 ( struct V_6 * V_6 )
{
const char * V_144 ;
char V_40 [ V_41 ] ;
if ( F_48 ( V_6 ) ) {
V_144 = V_44 . V_120 ;
} else {
snprintf ( V_40 , V_41 , L_36 , V_6 -> V_7 ) ;
V_144 = V_40 ;
}
if ( F_106 ( V_144 , L_37 ) )
return - 1 ;
if ( F_137 ( V_144 , V_6 , F_135 ) )
return - 1 ;
if ( ! F_134 ( V_6 ) )
return 0 ;
F_115 ( L_38 ) ;
return 0 ;
}
int F_12 ( struct V_6 * V_6 )
{
struct V_26 * V_99 = F_100 ( V_6 ) ;
const char * V_78 ;
T_6 V_107 = F_105 ( V_6 , & V_78 ) ;
if ( ! V_107 )
return - 1 ;
if ( V_99 == NULL ||
F_108 ( V_6 , V_99 ) < 0 )
return - 1 ;
if ( V_44 . V_145 && F_136 ( V_6 ) < 0 ) {
if ( F_47 ( V_6 ) )
F_115 ( L_39
L_40 ) ;
else
F_115 ( L_41
L_40 , V_6 -> V_8 ) ;
}
F_124 ( & V_6 -> V_9 ) ;
if ( F_138 ( V_6 -> V_94 , V_78 ,
V_107 ) ) {
F_110 ( V_6 ) ;
return - 1 ;
}
return 0 ;
}
static void F_139 ( struct V_6 * V_6 ,
union V_60 * V_61 )
{
int V_91 ;
for ( V_91 = 0 ; V_91 < V_110 ; V_91 ++ ) {
V_6 -> V_94 [ V_91 ] -> V_86 = V_61 -> V_146 . V_86 ;
V_6 -> V_94 [ V_91 ] -> V_147 = ( V_61 -> V_146 . V_86 +
V_61 -> V_146 . V_148 ) ;
if ( V_6 -> V_94 [ V_91 ] -> V_147 == 0 )
V_6 -> V_94 [ V_91 ] -> V_147 = ~ 0ULL ;
}
}
static bool F_140 ( struct V_6 * V_6 )
{
struct V_26 * V_26 ;
F_141 (dso, &machine->dsos.head, node) {
if ( F_142 ( V_26 ) )
return true ;
}
return false ;
}
static int F_143 ( struct V_6 * V_6 ,
union V_60 * V_61 )
{
struct V_85 * V_85 ;
char V_149 [ V_41 ] ;
enum V_150 V_151 ;
bool V_152 ;
if ( F_140 ( V_6 ) )
return 0 ;
F_46 ( V_6 , V_149 , sizeof( V_149 ) ) ;
if ( F_47 ( V_6 ) )
V_151 = V_100 ;
else
V_151 = V_102 ;
V_152 = memcmp ( V_61 -> V_146 . V_77 ,
V_149 ,
strlen ( V_149 ) - 1 ) == 0 ;
if ( V_61 -> V_146 . V_77 [ 0 ] == '/' ||
( ! V_152 && V_61 -> V_146 . V_77 [ 0 ] == '[' ) ) {
V_85 = F_85 ( V_6 , V_61 -> V_146 . V_86 ,
V_61 -> V_146 . V_77 ) ;
if ( V_85 == NULL )
goto V_153;
V_85 -> V_147 = V_85 -> V_86 + V_61 -> V_146 . V_148 ;
} else if ( V_152 ) {
const char * V_106 = ( V_61 -> V_146 . V_77 +
strlen ( V_149 ) ) ;
struct V_26 * V_99 = NULL ;
struct V_26 * V_26 ;
F_63 ( & V_6 -> V_1 . V_5 ) ;
F_141 (dso, &machine->dsos.head, node) {
if ( ! V_26 -> V_99 ||
F_144 ( V_26 -> V_133 ,
V_154 ) )
continue;
V_99 = V_26 ;
break;
}
F_18 ( & V_6 -> V_1 . V_5 ) ;
if ( V_99 == NULL )
V_99 = F_145 ( V_6 , V_149 ) ;
if ( V_99 == NULL )
goto V_153;
V_99 -> V_99 = V_151 ;
if ( F_108 ( V_6 , V_99 ) < 0 ) {
F_17 ( V_99 ) ;
goto V_153;
}
if ( strstr ( V_99 -> V_133 , L_42 ) )
F_76 ( V_99 , L_43 , false ) ;
F_139 ( V_6 , V_61 ) ;
if ( V_61 -> V_146 . V_155 != 0 ) {
F_138 ( V_6 -> V_94 ,
V_106 ,
V_61 -> V_146 . V_155 ) ;
}
if ( F_48 ( V_6 ) ) {
F_146 ( V_99 , V_6 -> V_94 [ V_87 ] ,
NULL ) ;
}
}
return 0 ;
V_153:
return - 1 ;
}
int F_147 ( struct V_6 * V_6 ,
union V_60 * V_61 ,
struct V_62 * V_63 V_70 )
{
T_9 V_156 = V_61 -> V_65 . V_66 & V_157 ;
struct V_22 * V_22 ;
struct V_85 * V_85 ;
enum V_109 type ;
int V_89 = 0 ;
if ( V_69 )
F_148 ( V_61 , stdout ) ;
if ( V_156 == V_158 ||
V_156 == V_159 ) {
V_89 = F_143 ( V_6 , V_61 ) ;
if ( V_89 < 0 )
goto V_153;
return 0 ;
}
V_22 = F_8 ( V_6 , V_61 -> V_160 . V_8 ,
V_61 -> V_160 . V_56 ) ;
if ( V_22 == NULL )
goto V_153;
if ( V_61 -> V_65 . V_66 & V_161 )
type = V_162 ;
else
type = V_87 ;
V_85 = F_149 ( V_6 , V_61 -> V_160 . V_86 ,
V_61 -> V_160 . V_148 , V_61 -> V_160 . V_155 ,
V_61 -> V_160 . V_8 , V_61 -> V_160 . V_163 ,
V_61 -> V_160 . V_164 , V_61 -> V_160 . V_165 ,
V_61 -> V_160 . V_166 ,
V_61 -> V_160 . V_167 ,
V_61 -> V_160 . V_168 ,
V_61 -> V_160 . V_77 , type , V_22 ) ;
if ( V_85 == NULL )
goto V_169;
F_150 ( V_22 , V_85 ) ;
F_10 ( V_22 ) ;
F_151 ( V_85 ) ;
return 0 ;
V_169:
F_10 ( V_22 ) ;
V_153:
F_70 ( L_44 ) ;
return 0 ;
}
int F_152 ( struct V_6 * V_6 , union V_60 * V_61 ,
struct V_62 * V_63 V_70 )
{
T_9 V_156 = V_61 -> V_65 . V_66 & V_157 ;
struct V_22 * V_22 ;
struct V_85 * V_85 ;
enum V_109 type ;
int V_89 = 0 ;
if ( V_69 )
F_153 ( V_61 , stdout ) ;
if ( V_156 == V_158 ||
V_156 == V_159 ) {
V_89 = F_143 ( V_6 , V_61 ) ;
if ( V_89 < 0 )
goto V_153;
return 0 ;
}
V_22 = F_8 ( V_6 , V_61 -> V_146 . V_8 ,
V_61 -> V_146 . V_56 ) ;
if ( V_22 == NULL )
goto V_153;
if ( V_61 -> V_65 . V_66 & V_161 )
type = V_162 ;
else
type = V_87 ;
V_85 = F_149 ( V_6 , V_61 -> V_146 . V_86 ,
V_61 -> V_146 . V_148 , V_61 -> V_146 . V_155 ,
V_61 -> V_146 . V_8 , 0 , 0 , 0 , 0 , 0 , 0 ,
V_61 -> V_146 . V_77 ,
type , V_22 ) ;
if ( V_85 == NULL )
goto V_169;
F_150 ( V_22 , V_85 ) ;
F_10 ( V_22 ) ;
F_151 ( V_85 ) ;
return 0 ;
V_169:
F_10 ( V_22 ) ;
V_153:
F_70 ( L_45 ) ;
return 0 ;
}
static void F_25 ( struct V_6 * V_6 , struct V_22 * V_53 , bool V_5 )
{
if ( V_6 -> V_14 == V_53 )
V_6 -> V_14 = NULL ;
F_154 ( F_155 ( & V_53 -> V_170 ) == 0 ) ;
if ( V_5 )
F_14 ( & V_6 -> V_12 ) ;
F_59 ( & V_53 -> V_10 , & V_6 -> V_11 ) ;
F_6 ( & V_53 -> V_10 ) ;
F_156 ( & V_53 -> V_29 , & V_6 -> V_13 ) ;
if ( V_5 )
F_18 ( & V_6 -> V_12 ) ;
F_10 ( V_53 ) ;
}
void F_157 ( struct V_6 * V_6 , struct V_22 * V_53 )
{
return F_25 ( V_6 , V_53 , true ) ;
}
int F_158 ( struct V_6 * V_6 , union V_60 * V_61 ,
struct V_62 * V_63 )
{
struct V_22 * V_22 = F_62 ( V_6 ,
V_61 -> V_171 . V_8 ,
V_61 -> V_171 . V_56 ) ;
struct V_22 * V_36 = F_8 ( V_6 ,
V_61 -> V_171 . V_172 ,
V_61 -> V_171 . V_173 ) ;
int V_68 = 0 ;
if ( V_69 )
F_159 ( V_61 , stdout ) ;
if ( V_36 -> V_55 != ( T_1 ) V_61 -> V_171 . V_172 ) {
F_70 ( L_46 ,
V_36 -> V_55 , V_36 -> V_56 ) ;
F_157 ( V_6 , V_36 ) ;
F_10 ( V_36 ) ;
V_36 = F_8 ( V_6 , V_61 -> V_171 . V_172 ,
V_61 -> V_171 . V_173 ) ;
}
if ( V_22 != NULL ) {
F_157 ( V_6 , V_22 ) ;
F_10 ( V_22 ) ;
}
V_22 = F_8 ( V_6 , V_61 -> V_171 . V_8 ,
V_61 -> V_171 . V_56 ) ;
if ( V_22 == NULL || V_36 == NULL ||
F_160 ( V_22 , V_36 , V_63 -> time ) < 0 ) {
F_70 ( L_47 ) ;
V_68 = - 1 ;
}
F_10 ( V_22 ) ;
F_10 ( V_36 ) ;
return V_68 ;
}
int F_161 ( struct V_6 * V_6 , union V_60 * V_61 ,
struct V_62 * V_63 V_70 )
{
struct V_22 * V_22 = F_62 ( V_6 ,
V_61 -> V_171 . V_8 ,
V_61 -> V_171 . V_56 ) ;
if ( V_69 )
F_159 ( V_61 , stdout ) ;
if ( V_22 != NULL ) {
F_162 ( V_22 ) ;
F_10 ( V_22 ) ;
}
return 0 ;
}
int F_163 ( struct V_6 * V_6 , union V_60 * V_61 ,
struct V_62 * V_63 )
{
int V_89 ;
switch ( V_61 -> V_65 . type ) {
case V_174 :
V_89 = F_67 ( V_6 , V_61 , V_63 ) ; break;
case V_175 :
V_89 = F_152 ( V_6 , V_61 , V_63 ) ; break;
case V_176 :
V_89 = F_147 ( V_6 , V_61 , V_63 ) ; break;
case V_177 :
V_89 = F_158 ( V_6 , V_61 , V_63 ) ; break;
case V_178 :
V_89 = F_161 ( V_6 , V_61 , V_63 ) ; break;
case V_179 :
V_89 = F_71 ( V_6 , V_61 , V_63 ) ; break;
case V_180 :
V_89 = F_79 ( V_6 , V_61 ) ; break;
case V_181 :
V_89 = F_81 ( V_6 , V_61 ) ; break;
case V_182 :
V_89 = F_72 ( V_6 , V_61 , V_63 ) ; break;
case V_183 :
case V_184 :
V_89 = F_83 ( V_6 , V_61 ) ; break;
default:
V_89 = - 1 ;
break;
}
return V_89 ;
}
static bool F_164 ( struct V_185 * V_186 , T_10 * V_187 )
{
if ( V_186 -> V_78 && ! regexec ( V_187 , V_186 -> V_78 , 0 , NULL , 0 ) )
return 1 ;
return 0 ;
}
static void F_165 ( struct V_22 * V_22 ,
struct V_188 * V_189 ,
T_6 V_190 )
{
struct V_191 V_192 ;
memset ( & V_192 , 0 , sizeof( V_192 ) ) ;
F_166 ( V_22 , V_87 , V_190 , & V_192 ) ;
V_189 -> V_107 = V_190 ;
V_189 -> V_193 = V_192 . V_107 ;
V_189 -> V_186 = V_192 . V_186 ;
V_189 -> V_85 = V_192 . V_85 ;
}
static void F_167 ( struct V_22 * V_22 ,
T_9 V_76 , struct V_188 * V_189 , T_6 V_107 )
{
struct V_191 V_192 ;
memset ( & V_192 , 0 , sizeof( V_192 ) ) ;
F_168 ( V_22 , V_76 , V_162 , V_107 , & V_192 ) ;
if ( V_192 . V_85 == NULL ) {
F_168 ( V_22 , V_76 , V_87 , V_107 , & V_192 ) ;
}
V_189 -> V_107 = V_107 ;
V_189 -> V_193 = V_192 . V_107 ;
V_189 -> V_186 = V_192 . V_186 ;
V_189 -> V_85 = V_192 . V_85 ;
}
struct V_194 * F_169 ( struct V_62 * V_63 ,
struct V_191 * V_192 )
{
struct V_194 * V_195 = F_170 ( sizeof( * V_195 ) ) ;
if ( ! V_195 )
return NULL ;
F_165 ( V_192 -> V_22 , & V_195 -> V_196 , V_63 -> V_190 ) ;
F_167 ( V_192 -> V_22 , V_192 -> V_156 , & V_195 -> V_197 , V_63 -> V_107 ) ;
V_195 -> V_198 . V_199 = V_63 -> V_198 ;
return V_195 ;
}
static int F_171 ( struct V_22 * V_22 ,
struct V_185 * * V_36 ,
struct V_191 * V_200 ,
T_9 * V_156 ,
T_6 V_190 )
{
struct V_191 V_192 ;
V_192 . V_201 = 0 ;
V_192 . V_186 = NULL ;
if ( ! V_156 ) {
F_166 ( V_22 , V_87 ,
V_190 , & V_192 ) ;
} else {
if ( V_190 >= V_202 ) {
switch ( V_190 ) {
case V_203 :
* V_156 = V_204 ;
break;
case V_205 :
* V_156 = V_159 ;
break;
case V_206 :
* V_156 = V_207 ;
break;
default:
F_115 ( L_48
L_49 V_208 L_14 , ( V_209 ) V_190 ) ;
F_172 ( & V_210 ) ;
return 1 ;
}
return 0 ;
}
F_168 ( V_22 , * V_156 , V_87 ,
V_190 , & V_192 ) ;
}
if ( V_192 . V_186 != NULL ) {
if ( V_211 && ! * V_36 &&
F_164 ( V_192 . V_186 , & V_212 ) )
* V_36 = V_192 . V_186 ;
else if ( V_213 && V_200 &&
F_164 ( V_192 . V_186 , & V_214 ) ) {
* V_200 = V_192 ;
F_172 ( & V_210 ) ;
}
}
return F_173 ( & V_210 , V_192 . V_107 , V_192 . V_85 , V_192 . V_186 ) ;
}
struct V_215 * F_174 ( struct V_62 * V_63 ,
struct V_191 * V_192 )
{
unsigned int V_91 ;
const struct V_216 * V_217 = V_63 -> V_216 ;
struct V_215 * V_218 = calloc ( V_217 -> V_219 , sizeof( struct V_215 ) ) ;
if ( ! V_218 )
return NULL ;
for ( V_91 = 0 ; V_91 < V_217 -> V_219 ; V_91 ++ ) {
F_165 ( V_192 -> V_22 , & V_218 [ V_91 ] . V_220 , V_217 -> V_221 [ V_91 ] . V_220 ) ;
F_165 ( V_192 -> V_22 , & V_218 [ V_91 ] . V_222 , V_217 -> V_221 [ V_91 ] . V_222 ) ;
V_218 [ V_91 ] . V_168 = V_217 -> V_221 [ V_91 ] . V_168 ;
}
return V_218 ;
}
static int F_175 ( struct V_223 * V_224 , int V_219 )
{
int V_91 , V_225 , V_226 ;
unsigned char V_227 [ V_228 ] ;
memset ( V_227 , V_229 , sizeof( V_227 ) ) ;
F_154 ( V_230 > 255 ) ;
for ( V_91 = 0 ; V_91 < V_219 ; V_91 ++ ) {
int V_231 = F_176 ( V_224 [ V_91 ] . V_222 , V_232 ) % V_228 ;
if ( V_227 [ V_231 ] == V_229 ) {
V_227 [ V_231 ] = V_91 ;
} else if ( V_224 [ V_227 [ V_231 ] ] . V_222 == V_224 [ V_91 ] . V_222 ) {
bool V_233 = true ;
V_226 = 0 ;
for ( V_225 = V_227 [ V_231 ] ; V_225 < V_91 && V_91 + V_226 < V_219 ; V_225 ++ , V_226 ++ )
if ( V_224 [ V_225 ] . V_222 != V_224 [ V_91 + V_226 ] . V_222 ) {
V_233 = false ;
break;
}
if ( V_233 ) {
memmove ( V_224 + V_91 , V_224 + V_91 + V_226 ,
( V_219 - ( V_91 + V_226 ) ) * sizeof( * V_224 ) ) ;
V_219 -= V_226 ;
}
}
}
return V_219 ;
}
static int F_177 ( struct V_22 * V_22 ,
struct V_62 * V_63 ,
struct V_185 * * V_36 ,
struct V_191 * V_200 ,
int V_234 )
{
struct V_235 * V_236 = V_63 -> V_237 ;
int V_238 = V_164 ( V_234 , ( int ) V_236 -> V_219 ) ;
T_9 V_156 = V_207 ;
int V_91 , V_225 , V_68 ;
T_6 V_190 ;
for ( V_91 = 0 ; V_91 < V_238 ; V_91 ++ ) {
if ( V_236 -> V_239 [ V_91 ] == V_206 )
break;
}
if ( V_91 != V_238 ) {
struct V_216 * V_240 = V_63 -> V_216 ;
int V_241 = V_240 -> V_219 ;
int V_242 = V_91 + 1 + V_241 + 1 ;
if ( V_242 > V_243 + V_230 ) {
F_178 ( L_50 ) ;
return 0 ;
}
for ( V_225 = 0 ; V_225 < V_242 ; V_225 ++ ) {
if ( V_244 . V_245 == V_246 ) {
if ( V_225 < V_91 + 1 )
V_190 = V_236 -> V_239 [ V_225 ] ;
else if ( V_225 > V_91 + 1 )
V_190 = V_240 -> V_221 [ V_225 - V_91 - 2 ] . V_222 ;
else
V_190 = V_240 -> V_221 [ 0 ] . V_220 ;
} else {
if ( V_225 < V_241 )
V_190 = V_240 -> V_221 [ V_241 - V_225 - 1 ] . V_222 ;
else if ( V_225 > V_241 )
V_190 = V_236 -> V_239 [ V_91 + 1 - ( V_225 - V_241 ) ] ;
else
V_190 = V_240 -> V_221 [ 0 ] . V_220 ;
}
V_68 = F_171 ( V_22 , V_36 , V_200 , & V_156 , V_190 ) ;
if ( V_68 )
return ( V_68 < 0 ) ? V_68 : 0 ;
}
return 1 ;
}
return 0 ;
}
static int F_179 ( struct V_22 * V_22 ,
struct V_247 * V_248 ,
struct V_62 * V_63 ,
struct V_185 * * V_36 ,
struct V_191 * V_200 ,
int V_234 )
{
struct V_216 * V_249 = V_63 -> V_216 ;
struct V_235 * V_236 = V_63 -> V_237 ;
int V_238 = V_164 ( V_234 , ( int ) V_236 -> V_219 ) ;
T_9 V_156 = V_207 ;
int V_91 , V_225 , V_68 ;
int V_250 = - 1 ;
int V_251 = 0 ;
F_172 ( & V_210 ) ;
if ( F_180 ( V_248 ) ) {
V_68 = F_177 ( V_22 , V_63 , V_36 ,
V_200 , V_234 ) ;
if ( V_68 )
return ( V_68 < 0 ) ? V_68 : 0 ;
}
if ( V_236 -> V_219 < V_243 )
V_250 = F_181 ( V_22 , V_236 ) ;
if ( V_249 && V_244 . V_252 ) {
int V_219 = V_164 ( V_234 , ( int ) V_249 -> V_219 ) ;
struct V_223 V_253 [ V_219 ] ;
if ( V_249 -> V_219 > V_230 ) {
F_178 ( L_51 ) ;
goto V_254;
}
for ( V_91 = 0 ; V_91 < V_219 ; V_91 ++ ) {
if ( V_244 . V_245 == V_246 ) {
V_253 [ V_91 ] = V_249 -> V_221 [ V_91 ] ;
if ( V_91 == V_250 ||
V_236 -> V_239 [ V_251 ] >= V_202 )
V_251 ++ ;
else if ( V_253 [ V_91 ] . V_222 < V_236 -> V_239 [ V_251 ] &&
V_253 [ V_91 ] . V_222 >= V_236 -> V_239 [ V_251 ] - 8 )
V_251 ++ ;
} else
V_253 [ V_91 ] = V_249 -> V_221 [ V_249 -> V_219 - V_91 - 1 ] ;
}
V_219 = F_175 ( V_253 , V_219 ) ;
for ( V_91 = 0 ; V_91 < V_219 ; V_91 ++ ) {
V_68 = F_171 ( V_22 , V_36 , V_200 ,
NULL , V_253 [ V_91 ] . V_220 ) ;
if ( ! V_68 )
V_68 = F_171 ( V_22 , V_36 , V_200 ,
NULL , V_253 [ V_91 ] . V_222 ) ;
if ( V_68 == - V_255 )
break;
if ( V_68 )
return V_68 ;
}
V_238 -= V_219 ;
}
V_254:
if ( V_236 -> V_219 > V_243 ) {
F_178 ( L_50 ) ;
return 0 ;
}
for ( V_91 = V_251 ; V_91 < V_238 ; V_91 ++ ) {
T_6 V_190 ;
if ( V_244 . V_245 == V_246 )
V_225 = V_91 ;
else
V_225 = V_236 -> V_219 - V_91 - 1 ;
#ifdef F_182
if ( V_225 == V_250 )
continue;
#endif
V_190 = V_236 -> V_239 [ V_225 ] ;
V_68 = F_171 ( V_22 , V_36 , V_200 , & V_156 , V_190 ) ;
if ( V_68 )
return ( V_68 < 0 ) ? V_68 : 0 ;
}
return 0 ;
}
static int F_183 ( struct F_183 * V_256 , void * V_143 )
{
struct V_210 * V_257 = V_143 ;
return F_173 ( V_257 , V_256 -> V_190 ,
V_256 -> V_85 , V_256 -> V_186 ) ;
}
int F_184 ( struct V_22 * V_22 ,
struct V_247 * V_248 ,
struct V_62 * V_63 ,
struct V_185 * * V_36 ,
struct V_191 * V_200 ,
int V_234 )
{
int V_89 = F_179 ( V_22 , V_248 ,
V_63 , V_36 ,
V_200 , V_234 ) ;
if ( V_89 )
return V_89 ;
if ( ! ( ( V_248 -> V_258 . V_259 & V_260 ) &&
( V_248 -> V_258 . V_259 & V_261 ) ) )
return 0 ;
if ( ( ! V_63 -> V_262 . V_263 ) ||
( ! V_63 -> V_264 . V_52 ) )
return 0 ;
return F_185 ( F_183 , & V_210 ,
V_22 , V_63 , V_234 ) ;
}
int F_186 ( struct V_6 * V_6 ,
int (* F_187)( struct V_22 * V_22 , void * V_35 ) ,
void * V_265 )
{
struct V_10 * V_30 ;
struct V_22 * V_22 ;
int V_266 = 0 ;
for ( V_30 = F_22 ( & V_6 -> V_11 ) ; V_30 ; V_30 = F_24 ( V_30 ) ) {
V_22 = F_23 ( V_30 , struct V_22 , V_10 ) ;
V_266 = F_187 ( V_22 , V_265 ) ;
if ( V_266 != 0 )
return V_266 ;
}
F_141 (thread, &machine->dead_threads, node) {
V_266 = F_187 ( V_22 , V_265 ) ;
if ( V_266 != 0 )
return V_266 ;
}
return V_266 ;
}
int F_188 ( struct V_32 * V_32 ,
int (* F_187)( struct V_22 * V_22 , void * V_35 ) ,
void * V_265 )
{
struct V_10 * V_30 ;
int V_266 = 0 ;
V_266 = F_186 ( & V_32 -> V_33 , F_187 , V_265 ) ;
if ( V_266 != 0 )
return V_266 ;
for ( V_30 = F_22 ( & V_32 -> V_34 ) ; V_30 ; V_30 = F_24 ( V_30 ) ) {
struct V_6 * V_6 = F_23 ( V_30 , struct V_6 , V_10 ) ;
V_266 = F_186 ( V_6 , F_187 , V_265 ) ;
if ( V_266 != 0 )
return V_266 ;
}
return V_266 ;
}
int F_189 ( struct V_6 * V_6 , struct V_267 * V_268 ,
struct V_269 * V_269 , struct V_270 * V_11 ,
T_11 V_49 , bool V_271 ,
unsigned int V_272 )
{
if ( F_190 ( V_269 ) )
return F_191 ( V_268 , V_11 , V_49 , V_6 , V_271 , V_272 ) ;
else if ( F_192 ( V_269 ) )
return F_193 ( V_268 , V_49 , V_6 , V_271 , V_272 ) ;
return 0 ;
}
T_1 F_194 ( struct V_6 * V_6 , int V_273 )
{
if ( V_273 < 0 || V_273 >= V_274 || ! V_6 -> V_24 )
return - 1 ;
return V_6 -> V_24 [ V_273 ] ;
}
int F_195 ( struct V_6 * V_6 , int V_273 , T_1 V_8 ,
T_1 V_56 )
{
struct V_22 * V_22 ;
if ( V_273 < 0 )
return - V_255 ;
if ( ! V_6 -> V_24 ) {
int V_91 ;
V_6 -> V_24 = calloc ( V_274 , sizeof( T_1 ) ) ;
if ( ! V_6 -> V_24 )
return - V_20 ;
for ( V_91 = 0 ; V_91 < V_274 ; V_91 ++ )
V_6 -> V_24 [ V_91 ] = - 1 ;
}
if ( V_273 >= V_274 ) {
F_43 ( L_52 , V_273 ) ;
F_43 ( L_53 ) ;
return - V_255 ;
}
V_6 -> V_24 [ V_273 ] = V_56 ;
V_22 = F_8 ( V_6 , V_8 , V_56 ) ;
if ( ! V_22 )
return - V_20 ;
V_22 -> V_273 = V_273 ;
F_10 ( V_22 ) ;
return 0 ;
}
int F_196 ( struct V_6 * V_6 )
{
struct V_85 * V_85 = F_197 ( V_6 , V_87 ) ;
int V_68 = 0 ;
V_6 -> V_19 = 1ULL << 63 ;
if ( V_85 ) {
V_68 = F_198 ( V_85 , V_6 -> V_16 ) ;
if ( V_85 -> V_86 )
V_6 -> V_19 = V_85 -> V_86 ;
}
return V_68 ;
}
struct V_26 * F_145 ( struct V_6 * V_6 , const char * V_77 )
{
return F_199 ( & V_6 -> V_1 , V_77 ) ;
}
char * F_200 ( void * V_275 , unsigned long long * V_276 , char * * V_277 )
{
struct V_6 * V_6 = V_275 ;
struct V_85 * V_85 ;
struct V_185 * V_186 = F_201 ( & V_6 -> V_9 , V_87 , * V_276 , & V_85 , NULL ) ;
if ( V_186 == NULL )
return NULL ;
* V_277 = F_202 ( V_85 ) ? ( char * ) V_85 -> V_26 -> V_278 : NULL ;
* V_276 = V_85 -> V_113 ( V_85 , V_186 -> V_86 ) ;
return V_186 -> V_78 ;
}
