static void F_1 ( struct V_1 * V_1 )
{
F_2 ( & V_1 -> V_2 ) ;
V_1 -> V_3 = V_4 ;
F_3 ( & V_1 -> V_5 , NULL ) ;
}
int F_4 ( struct V_6 * V_6 , const char * V_7 , T_1 V_8 )
{
memset ( V_6 , 0 , sizeof( * V_6 ) ) ;
F_5 ( & V_6 -> V_9 , V_6 ) ;
F_6 ( & V_6 -> V_10 ) ;
F_1 ( & V_6 -> V_1 ) ;
V_6 -> V_11 = V_4 ;
F_3 ( & V_6 -> V_12 , NULL ) ;
F_2 ( & V_6 -> V_13 ) ;
V_6 -> V_14 = NULL ;
V_6 -> V_15 = NULL ;
V_6 -> V_16 = NULL ;
V_6 -> V_8 = V_8 ;
V_6 -> V_17 = NULL ;
V_6 -> V_18 = 0 ;
V_6 -> V_19 = false ;
V_6 -> V_20 = 0 ;
memset ( V_6 -> V_21 , 0 , sizeof( V_6 -> V_21 ) ) ;
V_6 -> V_7 = F_7 ( V_7 ) ;
if ( V_6 -> V_7 == NULL )
return - V_22 ;
if ( V_8 != V_23 ) {
struct V_24 * V_24 = F_8 ( V_6 , - 1 ,
V_8 ) ;
char V_25 [ 64 ] ;
if ( V_24 == NULL )
return - V_22 ;
snprintf ( V_25 , sizeof( V_25 ) , L_1 , V_8 ) ;
F_9 ( V_24 , V_25 , 0 ) ;
F_10 ( V_24 ) ;
}
V_6 -> V_26 = NULL ;
return 0 ;
}
struct V_6 * F_11 ( void )
{
struct V_6 * V_6 = malloc ( sizeof( * V_6 ) ) ;
if ( V_6 != NULL ) {
F_4 ( V_6 , L_2 , V_23 ) ;
if ( F_12 ( V_6 ) < 0 )
goto V_27;
}
return V_6 ;
V_27:
free ( V_6 ) ;
return NULL ;
}
static void F_13 ( struct V_1 * V_1 )
{
struct V_28 * V_29 , * V_30 ;
F_14 ( & V_1 -> V_5 ) ;
F_15 (pos, n, &dsos->head, node) {
F_6 ( & V_29 -> V_10 ) ;
V_29 -> V_3 = NULL ;
F_16 ( & V_29 -> V_31 ) ;
F_17 ( V_29 ) ;
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
struct V_10 * V_32 ;
F_14 ( & V_6 -> V_12 ) ;
V_32 = F_22 ( & V_6 -> V_11 ) ;
while ( V_32 ) {
struct V_24 * V_33 = F_23 ( V_32 , struct V_24 , V_10 ) ;
V_32 = F_24 ( V_32 ) ;
F_25 ( V_6 , V_33 , false ) ;
}
F_18 ( & V_6 -> V_12 ) ;
}
void F_26 ( struct V_6 * V_6 )
{
F_27 ( V_6 ) ;
F_28 ( & V_6 -> V_9 ) ;
F_19 ( & V_6 -> V_1 ) ;
F_29 ( V_6 ) ;
F_30 ( & V_6 -> V_7 ) ;
F_30 ( & V_6 -> V_26 ) ;
F_20 ( & V_6 -> V_12 ) ;
}
void F_31 ( struct V_6 * V_6 )
{
F_26 ( V_6 ) ;
free ( V_6 ) ;
}
void F_32 ( struct V_34 * V_34 )
{
F_4 ( & V_34 -> V_35 , L_2 , V_23 ) ;
V_34 -> V_36 = V_4 ;
V_34 -> V_17 = NULL ;
}
void F_33 ( struct V_34 * V_34 )
{
F_26 ( & V_34 -> V_35 ) ;
}
struct V_6 * F_34 ( struct V_34 * V_34 , T_1 V_8 ,
const char * V_7 )
{
struct V_10 * * V_37 = & V_34 -> V_36 . V_10 ;
struct V_10 * V_38 = NULL ;
struct V_6 * V_29 , * V_6 = malloc ( sizeof( * V_6 ) ) ;
if ( V_6 == NULL )
return NULL ;
if ( F_4 ( V_6 , V_7 , V_8 ) != 0 ) {
free ( V_6 ) ;
return NULL ;
}
V_6 -> V_17 = V_34 -> V_17 ;
while ( * V_37 != NULL ) {
V_38 = * V_37 ;
V_29 = F_23 ( V_38 , struct V_6 , V_10 ) ;
if ( V_8 < V_29 -> V_8 )
V_37 = & ( * V_37 ) -> V_39 ;
else
V_37 = & ( * V_37 ) -> V_40 ;
}
F_35 ( & V_6 -> V_10 , V_38 , V_37 ) ;
F_36 ( & V_6 -> V_10 , & V_34 -> V_36 ) ;
return V_6 ;
}
void F_37 ( struct V_34 * V_34 ,
T_2 V_17 )
{
struct V_10 * V_32 ;
V_34 -> V_17 = V_17 ;
V_34 -> V_35 . V_17 = V_17 ;
for ( V_32 = F_22 ( & V_34 -> V_36 ) ; V_32 ; V_32 = F_24 ( V_32 ) ) {
struct V_6 * V_6 = F_23 ( V_32 , struct V_6 , V_10 ) ;
V_6 -> V_17 = V_17 ;
}
}
void F_38 ( struct V_34 * V_34 , bool V_19 )
{
struct V_10 * V_32 ;
V_34 -> V_35 . V_19 = V_19 ;
for ( V_32 = F_22 ( & V_34 -> V_36 ) ; V_32 ; V_32 = F_24 ( V_32 ) ) {
struct V_6 * V_6 = F_23 ( V_32 , struct V_6 , V_10 ) ;
V_6 -> V_19 = V_19 ;
}
}
struct V_6 * F_39 ( struct V_34 * V_34 , T_1 V_8 )
{
struct V_10 * * V_37 = & V_34 -> V_36 . V_10 ;
struct V_10 * V_38 = NULL ;
struct V_6 * V_6 ;
struct V_6 * V_41 = NULL ;
if ( V_8 == V_23 )
return & V_34 -> V_35 ;
while ( * V_37 != NULL ) {
V_38 = * V_37 ;
V_6 = F_23 ( V_38 , struct V_6 , V_10 ) ;
if ( V_8 < V_6 -> V_8 )
V_37 = & ( * V_37 ) -> V_39 ;
else if ( V_8 > V_6 -> V_8 )
V_37 = & ( * V_37 ) -> V_40 ;
else
return V_6 ;
if ( ! V_6 -> V_8 )
V_41 = V_6 ;
}
return V_41 ;
}
struct V_6 * F_40 ( struct V_34 * V_34 , T_1 V_8 )
{
char V_42 [ V_43 ] ;
const char * V_7 = L_2 ;
struct V_6 * V_6 = F_39 ( V_34 , V_8 ) ;
if ( V_6 && ( V_6 -> V_8 == V_8 ) )
goto V_44;
if ( ( V_8 != V_23 ) &&
( V_8 != V_45 ) &&
( V_46 . V_47 ) ) {
sprintf ( V_42 , L_3 , V_46 . V_47 , V_8 ) ;
if ( F_41 ( V_42 , V_48 ) ) {
static struct V_49 * V_50 ;
if ( ! V_50 )
V_50 = F_42 ( NULL , NULL ) ;
if ( ! F_43 ( V_50 , V_42 ) ) {
F_44 ( L_4 , V_42 ) ;
F_45 ( V_50 , V_42 ) ;
}
V_6 = NULL ;
goto V_44;
}
V_7 = V_42 ;
}
V_6 = F_34 ( V_34 , V_8 , V_7 ) ;
V_44:
return V_6 ;
}
void F_46 ( struct V_34 * V_34 ,
T_3 V_51 , void * V_52 )
{
struct V_10 * V_32 ;
for ( V_32 = F_22 ( & V_34 -> V_36 ) ; V_32 ; V_32 = F_24 ( V_32 ) ) {
struct V_6 * V_29 = F_23 ( V_32 , struct V_6 , V_10 ) ;
V_51 ( V_29 , V_52 ) ;
}
}
char * F_47 ( struct V_6 * V_6 , char * V_53 , T_4 V_54 )
{
if ( F_48 ( V_6 ) )
snprintf ( V_53 , V_54 , L_5 , L_6 ) ;
else if ( F_49 ( V_6 ) )
snprintf ( V_53 , V_54 , L_5 , L_7 ) ;
else {
snprintf ( V_53 , V_54 , L_8 , L_7 ,
V_6 -> V_8 ) ;
}
return V_53 ;
}
void F_50 ( struct V_34 * V_34 , T_5 V_18 )
{
struct V_10 * V_31 ;
struct V_6 * V_6 ;
V_34 -> V_35 . V_18 = V_18 ;
for ( V_31 = F_22 ( & V_34 -> V_36 ) ; V_31 ; V_31 = F_24 ( V_31 ) ) {
V_6 = F_23 ( V_31 , struct V_6 , V_10 ) ;
V_6 -> V_18 = V_18 ;
}
return;
}
static void F_51 ( struct V_6 * V_6 ,
struct V_24 * V_55 , T_1 V_8 )
{
struct V_24 * V_56 ;
if ( V_8 == V_55 -> V_57 || V_8 == - 1 || V_55 -> V_57 != - 1 )
return;
V_55 -> V_57 = V_8 ;
if ( V_55 -> V_57 == V_55 -> V_58 )
return;
V_56 = F_52 ( V_6 , V_55 -> V_57 , V_55 -> V_57 ) ;
if ( ! V_56 )
goto V_59;
if ( ! V_56 -> V_60 )
V_56 -> V_60 = F_53 ( V_6 ) ;
if ( ! V_56 -> V_60 )
goto V_59;
if ( V_55 -> V_60 == V_56 -> V_60 )
return;
if ( V_55 -> V_60 ) {
if ( ! F_54 ( V_55 -> V_60 ) )
F_44 ( L_9 ,
V_55 -> V_57 , V_55 -> V_58 ) ;
F_55 ( V_55 -> V_60 ) ;
}
V_55 -> V_60 = F_56 ( V_56 -> V_60 ) ;
V_61:
F_10 ( V_56 ) ;
return;
V_59:
F_44 ( L_10 , V_55 -> V_57 , V_55 -> V_58 ) ;
goto V_61;
}
static struct V_24 * F_57 ( struct V_6 * V_6 ,
T_1 V_8 , T_1 V_58 ,
bool V_62 )
{
struct V_10 * * V_37 = & V_6 -> V_11 . V_10 ;
struct V_10 * V_38 = NULL ;
struct V_24 * V_55 ;
V_55 = V_6 -> V_14 ;
if ( V_55 != NULL ) {
if ( V_55 -> V_58 == V_58 ) {
F_51 ( V_6 , V_55 , V_8 ) ;
return F_58 ( V_55 ) ;
}
V_6 -> V_14 = NULL ;
}
while ( * V_37 != NULL ) {
V_38 = * V_37 ;
V_55 = F_23 ( V_38 , struct V_24 , V_10 ) ;
if ( V_55 -> V_58 == V_58 ) {
V_6 -> V_14 = V_55 ;
F_51 ( V_6 , V_55 , V_8 ) ;
return F_58 ( V_55 ) ;
}
if ( V_58 < V_55 -> V_58 )
V_37 = & ( * V_37 ) -> V_39 ;
else
V_37 = & ( * V_37 ) -> V_40 ;
}
if ( ! V_62 )
return NULL ;
V_55 = F_59 ( V_8 , V_58 ) ;
if ( V_55 != NULL ) {
F_35 ( & V_55 -> V_10 , V_38 , V_37 ) ;
F_36 ( & V_55 -> V_10 , & V_6 -> V_11 ) ;
if ( F_60 ( V_55 , V_6 ) ) {
F_61 ( & V_55 -> V_10 , & V_6 -> V_11 ) ;
F_6 ( & V_55 -> V_10 ) ;
F_10 ( V_55 ) ;
return NULL ;
}
F_58 ( V_55 ) ;
V_6 -> V_14 = V_55 ;
}
return V_55 ;
}
struct V_24 * F_52 ( struct V_6 * V_6 , T_1 V_8 , T_1 V_58 )
{
return F_57 ( V_6 , V_8 , V_58 , true ) ;
}
struct V_24 * F_8 ( struct V_6 * V_6 , T_1 V_8 ,
T_1 V_58 )
{
struct V_24 * V_55 ;
F_14 ( & V_6 -> V_12 ) ;
V_55 = F_52 ( V_6 , V_8 , V_58 ) ;
F_18 ( & V_6 -> V_12 ) ;
return V_55 ;
}
struct V_24 * F_62 ( struct V_6 * V_6 , T_1 V_8 ,
T_1 V_58 )
{
struct V_24 * V_55 ;
F_63 ( & V_6 -> V_12 ) ;
V_55 = F_57 ( V_6 , V_8 , V_58 , false ) ;
F_18 ( & V_6 -> V_12 ) ;
return V_55 ;
}
struct V_25 * F_64 ( struct V_6 * V_6 ,
struct V_24 * V_24 )
{
if ( V_6 -> V_19 )
return F_65 ( V_24 ) ;
else
return F_66 ( V_24 ) ;
}
int F_67 ( struct V_6 * V_6 , union V_63 * V_64 ,
struct V_65 * V_66 )
{
struct V_24 * V_24 = F_8 ( V_6 ,
V_64 -> V_25 . V_8 ,
V_64 -> V_25 . V_58 ) ;
bool V_67 = V_64 -> V_68 . V_69 & V_70 ;
int V_71 = 0 ;
if ( V_67 )
V_6 -> V_19 = true ;
if ( V_72 )
F_68 ( V_64 , stdout ) ;
if ( V_24 == NULL ||
F_69 ( V_24 , V_64 -> V_25 . V_25 , V_66 -> time , V_67 ) ) {
F_70 ( L_11 ) ;
V_71 = - 1 ;
}
F_10 ( V_24 ) ;
return V_71 ;
}
int F_71 ( struct V_6 * V_6 V_73 ,
union V_63 * V_64 , struct V_65 * V_66 V_73 )
{
F_70 ( L_12 V_74 L_13 V_74 L_14 ,
V_64 -> V_75 . V_76 , V_64 -> V_75 . V_75 ) ;
return 0 ;
}
int F_72 ( struct V_6 * V_6 V_73 ,
union V_63 * V_64 , struct V_65 * V_66 )
{
F_70 ( L_12 V_74 L_15 V_74 L_14 ,
V_66 -> V_76 , V_64 -> V_77 . V_75 ) ;
return 0 ;
}
static struct V_28 * F_73 ( struct V_6 * V_6 ,
struct V_78 * V_79 ,
const char * V_80 )
{
struct V_28 * V_28 ;
F_14 ( & V_6 -> V_1 . V_5 ) ;
V_28 = F_74 ( & V_6 -> V_1 , V_79 -> V_81 , true ) ;
if ( ! V_28 ) {
V_28 = F_75 ( & V_6 -> V_1 , V_79 -> V_81 ) ;
if ( V_28 == NULL )
goto V_82;
if ( F_48 ( V_6 ) )
V_28 -> V_83 = V_84 ;
else
V_28 -> V_83 = V_85 ;
if ( V_79 -> V_86 && V_79 -> V_87 )
V_28 -> V_83 ++ ;
F_76 ( V_28 , F_7 ( V_79 -> V_81 ) , true ) ;
F_77 ( V_28 , F_7 ( V_80 ) , true ) ;
}
F_78 ( V_28 ) ;
V_82:
F_18 ( & V_6 -> V_1 . V_5 ) ;
return V_28 ;
}
int F_79 ( struct V_6 * V_6 V_73 ,
union V_63 * V_64 )
{
if ( V_72 )
F_80 ( V_64 , stdout ) ;
return 0 ;
}
int F_81 ( struct V_6 * V_6 V_73 ,
union V_63 * V_64 )
{
if ( V_72 )
F_82 ( V_64 , stdout ) ;
return 0 ;
}
int F_83 ( struct V_6 * V_6 V_73 ,
union V_63 * V_64 )
{
if ( V_72 )
F_84 ( V_64 , stdout ) ;
return 0 ;
}
static void F_85 ( struct V_28 * V_28 , const char * V_80 )
{
const char * V_88 ;
if ( ! V_80 || ! V_28 || ! V_28 -> V_89 )
return;
if ( V_28 -> V_89 [ 0 ] != '[' )
return;
if ( ! strchr ( V_80 , '/' ) )
return;
V_88 = F_7 ( V_80 ) ;
if ( ! V_88 )
return;
F_77 ( V_28 , V_88 , true ) ;
}
struct V_90 * F_86 ( struct V_6 * V_6 , T_6 V_91 ,
const char * V_80 )
{
struct V_90 * V_90 = NULL ;
struct V_28 * V_28 = NULL ;
struct V_78 V_79 ;
if ( F_87 ( & V_79 , V_80 ) )
return NULL ;
V_90 = F_88 ( & V_6 -> V_9 , V_92 ,
V_79 . V_81 ) ;
if ( V_90 ) {
F_85 ( V_90 -> V_28 , V_80 ) ;
goto V_44;
}
V_28 = F_73 ( V_6 , & V_79 , V_80 ) ;
if ( V_28 == NULL )
goto V_44;
V_90 = F_89 ( V_91 , V_28 , V_92 ) ;
if ( V_90 == NULL )
goto V_44;
F_90 ( & V_6 -> V_9 , V_90 ) ;
F_91 ( V_90 ) ;
V_44:
F_17 ( V_28 ) ;
free ( V_79 . V_81 ) ;
return V_90 ;
}
T_4 F_92 ( struct V_34 * V_34 , T_7 * V_93 )
{
struct V_10 * V_32 ;
T_4 V_94 = F_93 ( & V_34 -> V_35 . V_1 . V_2 , V_93 ) ;
for ( V_32 = F_22 ( & V_34 -> V_36 ) ; V_32 ; V_32 = F_24 ( V_32 ) ) {
struct V_6 * V_29 = F_23 ( V_32 , struct V_6 , V_10 ) ;
V_94 += F_93 ( & V_29 -> V_1 . V_2 , V_93 ) ;
}
return V_94 ;
}
T_4 F_94 ( struct V_6 * V_79 , T_7 * V_93 ,
bool (F_95)( struct V_28 * V_28 , int V_95 ) , int V_95 )
{
return F_96 ( & V_79 -> V_1 . V_2 , V_93 , F_95 , V_95 ) ;
}
T_4 F_97 ( struct V_34 * V_34 , T_7 * V_93 ,
bool (F_95)( struct V_28 * V_28 , int V_95 ) , int V_95 )
{
struct V_10 * V_32 ;
T_4 V_94 = F_94 ( & V_34 -> V_35 , V_93 , F_95 , V_95 ) ;
for ( V_32 = F_22 ( & V_34 -> V_36 ) ; V_32 ; V_32 = F_24 ( V_32 ) ) {
struct V_6 * V_29 = F_23 ( V_32 , struct V_6 , V_10 ) ;
V_94 += F_94 ( V_29 , V_93 , F_95 , V_95 ) ;
}
return V_94 ;
}
T_4 F_98 ( struct V_6 * V_6 , T_7 * V_93 )
{
int V_96 ;
T_4 V_97 = 0 ;
struct V_28 * V_98 = F_99 ( V_6 ) -> V_28 ;
if ( V_98 -> V_99 ) {
char V_80 [ V_43 ] ;
if ( F_100 ( V_98 , V_80 , sizeof( V_80 ) ) )
V_97 += fprintf ( V_93 , L_16 , V_80 ) ;
}
for ( V_96 = 0 ; V_96 < V_100 ; ++ V_96 )
V_97 += fprintf ( V_93 , L_17 ,
V_96 + V_98 -> V_99 , V_101 [ V_96 ] ) ;
return V_97 ;
}
T_4 F_101 ( struct V_6 * V_6 , T_7 * V_93 )
{
T_4 V_94 = 0 ;
struct V_10 * V_32 ;
F_63 ( & V_6 -> V_12 ) ;
for ( V_32 = F_22 ( & V_6 -> V_11 ) ; V_32 ; V_32 = F_24 ( V_32 ) ) {
struct V_24 * V_29 = F_23 ( V_32 , struct V_24 , V_10 ) ;
V_94 += F_102 ( V_29 , V_93 ) ;
}
F_18 ( & V_6 -> V_12 ) ;
return V_94 ;
}
static struct V_28 * F_103 ( struct V_6 * V_6 )
{
const char * V_102 = NULL ;
struct V_28 * V_103 ;
if ( F_48 ( V_6 ) ) {
V_102 = V_46 . V_102 ;
if ( ! V_102 )
V_102 = L_18 ;
V_103 = F_104 ( V_6 , V_102 ,
L_19 , V_104 ) ;
} else {
char V_53 [ V_43 ] ;
if ( F_49 ( V_6 ) )
V_102 = V_46 . V_105 ;
if ( ! V_102 )
V_102 = F_47 ( V_6 , V_53 ,
sizeof( V_53 ) ) ;
V_103 = F_104 ( V_6 , V_102 ,
L_20 ,
V_106 ) ;
}
if ( V_103 != NULL && ( ! V_103 -> V_99 ) )
F_105 ( V_103 , V_6 ) ;
return V_103 ;
}
static void F_106 ( struct V_6 * V_6 , char * V_107 ,
T_4 V_108 )
{
if ( F_49 ( V_6 ) )
F_107 ( V_107 , V_108 , L_21 , V_46 . V_109 ) ;
else
F_107 ( V_107 , V_108 , L_22 , V_6 -> V_7 ) ;
}
static T_6 F_108 ( struct V_6 * V_6 ,
const char * * V_110 )
{
char V_80 [ V_43 ] ;
int V_96 ;
const char * V_81 ;
T_6 V_111 = 0 ;
F_106 ( V_6 , V_80 , V_43 ) ;
if ( F_109 ( V_80 , L_23 ) )
return 0 ;
for ( V_96 = 0 ; ( V_81 = V_112 [ V_96 ] ) != NULL ; V_96 ++ ) {
V_111 = F_110 ( V_80 , V_81 ) ;
if ( V_111 )
break;
}
if ( V_110 )
* V_110 = V_81 ;
return V_111 ;
}
int F_111 ( struct V_6 * V_6 , struct V_28 * V_103 )
{
enum V_113 type ;
T_6 V_91 = F_108 ( V_6 , NULL ) ;
F_27 ( V_6 ) ;
for ( type = 0 ; type < V_114 ; ++ type ) {
struct V_115 * V_115 ;
struct V_90 * V_90 ;
V_6 -> V_21 [ type ] = F_89 ( V_91 , V_103 , type ) ;
if ( V_6 -> V_21 [ type ] == NULL )
return - 1 ;
V_6 -> V_21 [ type ] -> V_116 =
V_6 -> V_21 [ type ] -> V_117 =
V_118 ;
V_90 = F_112 ( V_6 , type ) ;
V_115 = F_113 ( V_90 ) ;
if ( ! V_115 )
return - 1 ;
V_115 -> V_9 = & V_6 -> V_9 ;
F_90 ( & V_6 -> V_9 , V_90 ) ;
}
return 0 ;
}
void F_27 ( struct V_6 * V_6 )
{
enum V_113 type ;
for ( type = 0 ; type < V_114 ; ++ type ) {
struct V_115 * V_115 ;
struct V_90 * V_90 = F_112 ( V_6 , type ) ;
if ( V_90 == NULL )
continue;
V_115 = F_113 ( V_90 ) ;
F_114 ( & V_6 -> V_9 , V_90 ) ;
if ( V_115 && V_115 -> V_119 ) {
if ( type == V_92 ) {
F_30 ( ( char * * ) & V_115 -> V_119 -> V_81 ) ;
F_30 ( & V_115 -> V_119 ) ;
} else
V_115 -> V_119 = NULL ;
}
F_91 ( V_6 -> V_21 [ type ] ) ;
V_6 -> V_21 [ type ] = NULL ;
}
}
int F_115 ( struct V_34 * V_34 )
{
int V_94 = 0 ;
struct V_120 * * V_121 = NULL ;
int V_96 , V_122 = 0 ;
char V_42 [ V_43 ] ;
T_1 V_8 ;
char * V_123 ;
if ( V_46 . V_105 ||
V_46 . V_124 ||
V_46 . V_109 ) {
F_116 ( V_34 , V_45 ) ;
}
if ( V_46 . V_47 ) {
V_122 = F_117 ( V_46 . V_47 , & V_121 , NULL , NULL ) ;
if ( V_122 <= 0 )
return - V_125 ;
for ( V_96 = 0 ; V_96 < V_122 ; V_96 ++ ) {
if ( ! isdigit ( V_121 [ V_96 ] -> V_126 [ 0 ] ) ) {
continue;
}
V_8 = ( T_1 ) strtol ( V_121 [ V_96 ] -> V_126 , & V_123 , 10 ) ;
if ( ( * V_123 != '\0' ) ||
( V_123 == V_121 [ V_96 ] -> V_126 ) ||
( V_127 == V_128 ) ) {
F_118 ( L_24 ,
V_121 [ V_96 ] -> V_126 ) ;
continue;
}
sprintf ( V_42 , L_25 ,
V_46 . V_47 ,
V_121 [ V_96 ] -> V_126 ) ;
V_94 = F_41 ( V_42 , V_48 ) ;
if ( V_94 ) {
F_118 ( L_4 , V_42 ) ;
goto V_129;
}
F_116 ( V_34 , V_8 ) ;
}
V_129:
free ( V_121 ) ;
}
return V_94 ;
}
void F_119 ( struct V_34 * V_34 )
{
struct V_10 * V_130 = F_22 ( & V_34 -> V_36 ) ;
F_27 ( & V_34 -> V_35 ) ;
while ( V_130 ) {
struct V_6 * V_29 = F_23 ( V_130 , struct V_6 , V_10 ) ;
V_130 = F_24 ( & V_29 -> V_10 ) ;
F_120 ( & V_29 -> V_10 , & V_34 -> V_36 ) ;
F_31 ( V_29 ) ;
}
}
int F_116 ( struct V_34 * V_34 , T_1 V_8 )
{
struct V_6 * V_6 = F_40 ( V_34 , V_8 ) ;
if ( V_6 == NULL )
return - 1 ;
return F_12 ( V_6 ) ;
}
int F_121 ( struct V_6 * V_6 , const char * V_80 ,
enum V_113 type , T_2 V_131 )
{
struct V_90 * V_90 = F_99 ( V_6 ) ;
int V_94 = F_122 ( V_90 -> V_28 , V_80 , V_90 , V_131 ) ;
if ( V_94 > 0 ) {
F_123 ( V_90 -> V_28 , type ) ;
F_124 ( & V_6 -> V_9 , type ) ;
}
return V_94 ;
}
int F_125 ( struct V_6 * V_6 , enum V_113 type ,
T_2 V_131 )
{
struct V_90 * V_90 = F_99 ( V_6 ) ;
int V_94 = F_126 ( V_90 -> V_28 , V_90 , V_131 ) ;
if ( V_94 > 0 )
F_123 ( V_90 -> V_28 , type ) ;
return V_94 ;
}
static void F_127 ( struct V_132 * V_60 )
{
int V_96 ;
for ( V_96 = 0 ; V_96 < V_114 ; ++ V_96 )
F_124 ( V_60 , V_96 ) ;
}
static char * F_128 ( const char * V_7 )
{
char V_133 [ V_43 ] ;
T_7 * V_134 ;
char * V_81 , * V_135 ;
const char * V_136 = L_26 ;
sprintf ( V_133 , L_27 , V_7 ) ;
V_134 = fopen ( V_133 , L_28 ) ;
if ( ! V_134 )
return NULL ;
V_133 [ 0 ] = '\0' ;
V_135 = fgets ( V_133 , sizeof( V_133 ) , V_134 ) ;
fclose ( V_134 ) ;
V_81 = strstr ( V_133 , V_136 ) ;
if ( ! V_81 )
return NULL ;
V_81 += strlen ( V_136 ) ;
V_135 = strchr ( V_81 , ' ' ) ;
if ( V_135 )
* V_135 = '\0' ;
return F_7 ( V_81 ) ;
}
static bool F_129 ( struct V_28 * V_28 )
{
return V_28 -> V_83 == V_84 ||
V_28 -> V_83 == V_85 ;
}
static int F_130 ( struct V_132 * V_60 , const char * V_42 ,
struct V_78 * V_79 )
{
struct V_90 * V_90 ;
char * V_89 ;
V_90 = F_88 ( V_60 , V_92 , V_79 -> V_81 ) ;
if ( V_90 == NULL )
return 0 ;
V_89 = F_7 ( V_42 ) ;
if ( V_89 == NULL )
return - V_22 ;
F_77 ( V_90 -> V_28 , V_89 , true ) ;
F_131 ( V_90 -> V_28 , L_2 ) ;
if ( V_79 -> V_87 && F_129 ( V_90 -> V_28 ) )
V_90 -> V_28 -> V_83 ++ ;
return 0 ;
}
static int F_132 ( struct V_132 * V_60 ,
const char * V_137 , int V_138 )
{
struct V_120 * V_139 ;
T_8 * V_140 = F_133 ( V_137 ) ;
int V_94 = 0 ;
if ( ! V_140 ) {
F_118 ( L_29 , V_141 , V_137 ) ;
return - 1 ;
}
while ( ( V_139 = F_134 ( V_140 ) ) != NULL ) {
char V_42 [ V_43 ] ;
struct V_142 V_143 ;
snprintf ( V_42 , sizeof( V_42 ) , L_30 , V_137 , V_139 -> V_126 ) ;
if ( V_142 ( V_42 , & V_143 ) )
continue;
if ( F_135 ( V_143 . V_144 ) ) {
if ( ! strcmp ( V_139 -> V_126 , L_31 ) ||
! strcmp ( V_139 -> V_126 , L_32 ) )
continue;
if ( V_138 == 0 ) {
if ( ! strcmp ( V_139 -> V_126 , L_33 ) ||
! strcmp ( V_139 -> V_126 , L_34 ) )
continue;
}
V_94 = F_132 ( V_60 , V_42 ,
V_138 + 1 ) ;
if ( V_94 < 0 )
goto V_44;
} else {
struct V_78 V_79 ;
V_94 = F_87 ( & V_79 , V_139 -> V_126 ) ;
if ( V_94 )
goto V_44;
if ( V_79 . V_86 )
V_94 = F_130 ( V_60 , V_42 , & V_79 ) ;
free ( V_79 . V_81 ) ;
if ( V_94 )
goto V_44;
}
}
V_44:
F_136 ( V_140 ) ;
return V_94 ;
}
static int F_137 ( struct V_6 * V_6 )
{
char * V_133 ;
char V_145 [ V_43 ] ;
V_133 = F_128 ( V_6 -> V_7 ) ;
if ( ! V_133 )
return - 1 ;
snprintf ( V_145 , sizeof( V_145 ) , L_35 ,
V_6 -> V_7 , V_133 ) ;
free ( V_133 ) ;
return F_132 ( & V_6 -> V_9 , V_145 , 0 ) ;
}
static int F_138 ( void * V_146 , const char * V_81 , T_6 V_91 )
{
struct V_6 * V_6 = V_146 ;
struct V_90 * V_90 ;
V_90 = F_86 ( V_6 , V_91 , V_81 ) ;
if ( V_90 == NULL )
return - 1 ;
F_131 ( V_90 -> V_28 , V_6 -> V_7 ) ;
return 0 ;
}
static int F_139 ( struct V_6 * V_6 )
{
const char * V_147 ;
char V_42 [ V_43 ] ;
if ( F_49 ( V_6 ) ) {
V_147 = V_46 . V_124 ;
} else {
snprintf ( V_42 , V_43 , L_36 , V_6 -> V_7 ) ;
V_147 = V_42 ;
}
if ( F_109 ( V_147 , L_37 ) )
return - 1 ;
if ( F_140 ( V_147 , V_6 , F_138 ) )
return - 1 ;
if ( ! F_137 ( V_6 ) )
return 0 ;
F_118 ( L_38 ) ;
return 0 ;
}
int F_12 ( struct V_6 * V_6 )
{
struct V_28 * V_103 = F_103 ( V_6 ) ;
const char * V_81 ;
T_6 V_111 = F_108 ( V_6 , & V_81 ) ;
int V_94 ;
if ( ! V_111 || V_103 == NULL )
return - 1 ;
V_94 = F_111 ( V_6 , V_103 ) ;
F_17 ( V_103 ) ;
if ( V_94 < 0 )
return - 1 ;
if ( V_46 . V_148 && F_139 ( V_6 ) < 0 ) {
if ( F_48 ( V_6 ) )
F_118 ( L_39
L_40 ) ;
else
F_118 ( L_41
L_40 , V_6 -> V_8 ) ;
}
F_127 ( & V_6 -> V_9 ) ;
if ( F_141 ( V_6 -> V_21 , V_81 ,
V_111 ) ) {
F_27 ( V_6 ) ;
return - 1 ;
}
return 0 ;
}
static void F_142 ( struct V_6 * V_6 ,
union V_63 * V_64 )
{
int V_96 ;
for ( V_96 = 0 ; V_96 < V_114 ; V_96 ++ ) {
V_6 -> V_21 [ V_96 ] -> V_91 = V_64 -> V_149 . V_91 ;
V_6 -> V_21 [ V_96 ] -> V_150 = ( V_64 -> V_149 . V_91 +
V_64 -> V_149 . V_151 ) ;
if ( V_6 -> V_21 [ V_96 ] -> V_150 == 0 )
V_6 -> V_21 [ V_96 ] -> V_150 = ~ 0ULL ;
}
}
static bool F_143 ( struct V_6 * V_6 )
{
struct V_28 * V_28 ;
F_144 (dso, &machine->dsos.head, node) {
if ( F_145 ( V_28 ) )
return true ;
}
return false ;
}
static int F_146 ( struct V_6 * V_6 ,
union V_63 * V_64 )
{
struct V_90 * V_90 ;
char V_152 [ V_43 ] ;
enum V_153 V_154 ;
bool V_155 ;
if ( F_143 ( V_6 ) )
return 0 ;
F_47 ( V_6 , V_152 , sizeof( V_152 ) ) ;
if ( F_48 ( V_6 ) )
V_154 = V_104 ;
else
V_154 = V_106 ;
V_155 = memcmp ( V_64 -> V_149 . V_80 ,
V_152 ,
strlen ( V_152 ) - 1 ) == 0 ;
if ( V_64 -> V_149 . V_80 [ 0 ] == '/' ||
( ! V_155 && V_64 -> V_149 . V_80 [ 0 ] == '[' ) ) {
V_90 = F_86 ( V_6 , V_64 -> V_149 . V_91 ,
V_64 -> V_149 . V_80 ) ;
if ( V_90 == NULL )
goto V_156;
V_90 -> V_150 = V_90 -> V_91 + V_64 -> V_149 . V_151 ;
} else if ( V_155 ) {
const char * V_110 = ( V_64 -> V_149 . V_80 +
strlen ( V_152 ) ) ;
struct V_28 * V_103 = NULL ;
struct V_28 * V_28 ;
F_63 ( & V_6 -> V_1 . V_5 ) ;
F_144 (dso, &machine->dsos.head, node) {
if ( ! V_28 -> V_103 ||
F_147 ( V_28 -> V_89 ,
V_157 ) )
continue;
V_103 = V_28 ;
break;
}
F_18 ( & V_6 -> V_1 . V_5 ) ;
if ( V_103 == NULL )
V_103 = F_148 ( V_6 , V_152 ) ;
if ( V_103 == NULL )
goto V_156;
V_103 -> V_103 = V_154 ;
if ( F_111 ( V_6 , V_103 ) < 0 ) {
F_17 ( V_103 ) ;
goto V_156;
}
if ( strstr ( V_103 -> V_89 , L_42 ) )
F_76 ( V_103 , L_43 , false ) ;
F_142 ( V_6 , V_64 ) ;
if ( V_64 -> V_149 . V_158 != 0 ) {
F_141 ( V_6 -> V_21 ,
V_110 ,
V_64 -> V_149 . V_158 ) ;
}
if ( F_49 ( V_6 ) ) {
F_149 ( V_103 , F_99 ( V_6 ) , NULL ) ;
}
}
return 0 ;
V_156:
return - 1 ;
}
int F_150 ( struct V_6 * V_6 ,
union V_63 * V_64 ,
struct V_65 * V_66 )
{
struct V_24 * V_24 ;
struct V_90 * V_90 ;
enum V_113 type ;
int V_94 = 0 ;
if ( V_72 )
F_151 ( V_64 , stdout ) ;
if ( V_66 -> V_159 == V_160 ||
V_66 -> V_159 == V_161 ) {
V_94 = F_146 ( V_6 , V_64 ) ;
if ( V_94 < 0 )
goto V_156;
return 0 ;
}
V_24 = F_8 ( V_6 , V_64 -> V_162 . V_8 ,
V_64 -> V_162 . V_58 ) ;
if ( V_24 == NULL )
goto V_156;
if ( V_64 -> V_68 . V_69 & V_163 )
type = V_164 ;
else
type = V_92 ;
V_90 = F_152 ( V_6 , V_64 -> V_162 . V_91 ,
V_64 -> V_162 . V_151 , V_64 -> V_162 . V_158 ,
V_64 -> V_162 . V_8 , V_64 -> V_162 . V_165 ,
V_64 -> V_162 . V_166 , V_64 -> V_162 . V_167 ,
V_64 -> V_162 . V_168 ,
V_64 -> V_162 . V_169 ,
V_64 -> V_162 . V_170 ,
V_64 -> V_162 . V_80 , type , V_24 ) ;
if ( V_90 == NULL )
goto V_171;
F_153 ( V_24 , V_90 ) ;
F_10 ( V_24 ) ;
F_91 ( V_90 ) ;
return 0 ;
V_171:
F_10 ( V_24 ) ;
V_156:
F_70 ( L_44 ) ;
return 0 ;
}
int F_154 ( struct V_6 * V_6 , union V_63 * V_64 ,
struct V_65 * V_66 )
{
struct V_24 * V_24 ;
struct V_90 * V_90 ;
enum V_113 type ;
int V_94 = 0 ;
if ( V_72 )
F_155 ( V_64 , stdout ) ;
if ( V_66 -> V_159 == V_160 ||
V_66 -> V_159 == V_161 ) {
V_94 = F_146 ( V_6 , V_64 ) ;
if ( V_94 < 0 )
goto V_156;
return 0 ;
}
V_24 = F_8 ( V_6 , V_64 -> V_149 . V_8 ,
V_64 -> V_149 . V_58 ) ;
if ( V_24 == NULL )
goto V_156;
if ( V_64 -> V_68 . V_69 & V_163 )
type = V_164 ;
else
type = V_92 ;
V_90 = F_152 ( V_6 , V_64 -> V_149 . V_91 ,
V_64 -> V_149 . V_151 , V_64 -> V_149 . V_158 ,
V_64 -> V_149 . V_8 , 0 , 0 , 0 , 0 , 0 , 0 ,
V_64 -> V_149 . V_80 ,
type , V_24 ) ;
if ( V_90 == NULL )
goto V_171;
F_153 ( V_24 , V_90 ) ;
F_10 ( V_24 ) ;
F_91 ( V_90 ) ;
return 0 ;
V_171:
F_10 ( V_24 ) ;
V_156:
F_70 ( L_45 ) ;
return 0 ;
}
static void F_25 ( struct V_6 * V_6 , struct V_24 * V_55 , bool V_5 )
{
if ( V_6 -> V_14 == V_55 )
V_6 -> V_14 = NULL ;
F_156 ( F_157 ( & V_55 -> V_172 ) == 0 ) ;
if ( V_5 )
F_14 ( & V_6 -> V_12 ) ;
F_61 ( & V_55 -> V_10 , & V_6 -> V_11 ) ;
F_6 ( & V_55 -> V_10 ) ;
F_158 ( & V_55 -> V_31 , & V_6 -> V_13 ) ;
if ( V_5 )
F_18 ( & V_6 -> V_12 ) ;
F_10 ( V_55 ) ;
}
void F_159 ( struct V_6 * V_6 , struct V_24 * V_55 )
{
return F_25 ( V_6 , V_55 , true ) ;
}
int F_160 ( struct V_6 * V_6 , union V_63 * V_64 ,
struct V_65 * V_66 )
{
struct V_24 * V_24 = F_62 ( V_6 ,
V_64 -> V_173 . V_8 ,
V_64 -> V_173 . V_58 ) ;
struct V_24 * V_38 = F_8 ( V_6 ,
V_64 -> V_173 . V_174 ,
V_64 -> V_173 . V_175 ) ;
int V_71 = 0 ;
if ( V_72 )
F_161 ( V_64 , stdout ) ;
if ( V_38 -> V_57 != ( T_1 ) V_64 -> V_173 . V_174 ) {
F_70 ( L_46 ,
V_38 -> V_57 , V_38 -> V_58 ) ;
F_159 ( V_6 , V_38 ) ;
F_10 ( V_38 ) ;
V_38 = F_8 ( V_6 , V_64 -> V_173 . V_174 ,
V_64 -> V_173 . V_175 ) ;
}
if ( V_24 != NULL ) {
F_159 ( V_6 , V_24 ) ;
F_10 ( V_24 ) ;
}
V_24 = F_8 ( V_6 , V_64 -> V_173 . V_8 ,
V_64 -> V_173 . V_58 ) ;
if ( V_24 == NULL || V_38 == NULL ||
F_162 ( V_24 , V_38 , V_66 -> time ) < 0 ) {
F_70 ( L_47 ) ;
V_71 = - 1 ;
}
F_10 ( V_24 ) ;
F_10 ( V_38 ) ;
return V_71 ;
}
int F_163 ( struct V_6 * V_6 , union V_63 * V_64 ,
struct V_65 * V_66 V_73 )
{
struct V_24 * V_24 = F_62 ( V_6 ,
V_64 -> V_173 . V_8 ,
V_64 -> V_173 . V_58 ) ;
if ( V_72 )
F_161 ( V_64 , stdout ) ;
if ( V_24 != NULL ) {
F_164 ( V_24 ) ;
F_10 ( V_24 ) ;
}
return 0 ;
}
int F_165 ( struct V_6 * V_6 , union V_63 * V_64 ,
struct V_65 * V_66 )
{
int V_94 ;
switch ( V_64 -> V_68 . type ) {
case V_176 :
V_94 = F_67 ( V_6 , V_64 , V_66 ) ; break;
case V_177 :
V_94 = F_154 ( V_6 , V_64 , V_66 ) ; break;
case V_178 :
V_94 = F_150 ( V_6 , V_64 , V_66 ) ; break;
case V_179 :
V_94 = F_160 ( V_6 , V_64 , V_66 ) ; break;
case V_180 :
V_94 = F_163 ( V_6 , V_64 , V_66 ) ; break;
case V_181 :
V_94 = F_71 ( V_6 , V_64 , V_66 ) ; break;
case V_182 :
V_94 = F_79 ( V_6 , V_64 ) ; break;
case V_183 :
V_94 = F_81 ( V_6 , V_64 ) ; break;
case V_184 :
V_94 = F_72 ( V_6 , V_64 , V_66 ) ; break;
case V_185 :
case V_186 :
V_94 = F_83 ( V_6 , V_64 ) ; break;
default:
V_94 = - 1 ;
break;
}
return V_94 ;
}
static bool F_166 ( struct V_187 * V_188 , T_9 * V_189 )
{
if ( V_188 -> V_81 && ! regexec ( V_189 , V_188 -> V_81 , 0 , NULL , 0 ) )
return 1 ;
return 0 ;
}
static void F_167 ( struct V_24 * V_24 ,
struct V_190 * V_191 ,
T_6 V_192 )
{
struct V_193 V_194 ;
memset ( & V_194 , 0 , sizeof( V_194 ) ) ;
F_168 ( V_24 , V_92 , V_192 , & V_194 ) ;
V_191 -> V_111 = V_192 ;
V_191 -> V_195 = V_194 . V_111 ;
V_191 -> V_188 = V_194 . V_188 ;
V_191 -> V_90 = V_194 . V_90 ;
}
static void F_169 ( struct V_24 * V_24 ,
T_10 V_79 , struct V_190 * V_191 , T_6 V_111 )
{
struct V_193 V_194 ;
memset ( & V_194 , 0 , sizeof( V_194 ) ) ;
F_170 ( V_24 , V_79 , V_164 , V_111 , & V_194 ) ;
if ( V_194 . V_90 == NULL ) {
F_170 ( V_24 , V_79 , V_92 , V_111 , & V_194 ) ;
}
V_191 -> V_111 = V_111 ;
V_191 -> V_195 = V_194 . V_111 ;
V_191 -> V_188 = V_194 . V_188 ;
V_191 -> V_90 = V_194 . V_90 ;
}
struct V_196 * F_171 ( struct V_65 * V_66 ,
struct V_193 * V_194 )
{
struct V_196 * V_197 = F_172 ( sizeof( * V_197 ) ) ;
if ( ! V_197 )
return NULL ;
F_167 ( V_194 -> V_24 , & V_197 -> V_198 , V_66 -> V_192 ) ;
F_169 ( V_194 -> V_24 , V_194 -> V_159 , & V_197 -> V_199 , V_66 -> V_111 ) ;
V_197 -> V_200 . V_201 = V_66 -> V_200 ;
return V_197 ;
}
static int F_173 ( struct V_24 * V_24 ,
struct V_187 * * V_38 ,
struct V_193 * V_202 ,
T_10 * V_159 ,
T_6 V_192 )
{
struct V_193 V_194 ;
V_194 . V_203 = 0 ;
V_194 . V_188 = NULL ;
if ( ! V_159 ) {
F_168 ( V_24 , V_92 ,
V_192 , & V_194 ) ;
} else {
if ( V_192 >= V_204 ) {
switch ( V_192 ) {
case V_205 :
* V_159 = V_206 ;
break;
case V_207 :
* V_159 = V_161 ;
break;
case V_208 :
* V_159 = V_209 ;
break;
default:
F_118 ( L_48
L_49 V_210 L_14 , ( V_211 ) V_192 ) ;
F_174 ( & V_212 ) ;
return 1 ;
}
return 0 ;
}
F_170 ( V_24 , * V_159 , V_92 ,
V_192 , & V_194 ) ;
}
if ( V_194 . V_188 != NULL ) {
if ( V_213 && ! * V_38 &&
F_166 ( V_194 . V_188 , & V_214 ) )
* V_38 = V_194 . V_188 ;
else if ( V_215 && V_202 &&
F_166 ( V_194 . V_188 , & V_216 ) ) {
* V_202 = V_194 ;
F_174 ( & V_212 ) ;
}
}
if ( V_46 . V_217 && V_194 . V_188 == NULL )
return 0 ;
return F_175 ( & V_212 , V_194 . V_111 , V_194 . V_90 , V_194 . V_188 ) ;
}
struct V_218 * F_176 ( struct V_65 * V_66 ,
struct V_193 * V_194 )
{
unsigned int V_96 ;
const struct V_219 * V_220 = V_66 -> V_219 ;
struct V_218 * V_221 = calloc ( V_220 -> V_222 , sizeof( struct V_218 ) ) ;
if ( ! V_221 )
return NULL ;
for ( V_96 = 0 ; V_96 < V_220 -> V_222 ; V_96 ++ ) {
F_167 ( V_194 -> V_24 , & V_221 [ V_96 ] . V_223 , V_220 -> V_224 [ V_96 ] . V_223 ) ;
F_167 ( V_194 -> V_24 , & V_221 [ V_96 ] . V_225 , V_220 -> V_224 [ V_96 ] . V_225 ) ;
V_221 [ V_96 ] . V_170 = V_220 -> V_224 [ V_96 ] . V_170 ;
}
return V_221 ;
}
static int F_177 ( struct V_226 * V_227 , int V_222 )
{
int V_96 , V_228 , V_229 ;
unsigned char V_230 [ V_231 ] ;
memset ( V_230 , V_232 , sizeof( V_230 ) ) ;
F_156 ( V_233 > 255 ) ;
for ( V_96 = 0 ; V_96 < V_222 ; V_96 ++ ) {
int V_234 = F_178 ( V_227 [ V_96 ] . V_225 , V_235 ) % V_231 ;
if ( V_230 [ V_234 ] == V_232 ) {
V_230 [ V_234 ] = V_96 ;
} else if ( V_227 [ V_230 [ V_234 ] ] . V_225 == V_227 [ V_96 ] . V_225 ) {
bool V_236 = true ;
V_229 = 0 ;
for ( V_228 = V_230 [ V_234 ] ; V_228 < V_96 && V_96 + V_229 < V_222 ; V_228 ++ , V_229 ++ )
if ( V_227 [ V_228 ] . V_225 != V_227 [ V_96 + V_229 ] . V_225 ) {
V_236 = false ;
break;
}
if ( V_236 ) {
memmove ( V_227 + V_96 , V_227 + V_96 + V_229 ,
( V_222 - ( V_96 + V_229 ) ) * sizeof( * V_227 ) ) ;
V_222 -= V_229 ;
}
}
}
return V_222 ;
}
static int F_179 ( struct V_24 * V_24 ,
struct V_65 * V_66 ,
struct V_187 * * V_38 ,
struct V_193 * V_202 ,
int V_237 )
{
struct V_238 * V_239 = V_66 -> V_240 ;
int V_241 = V_166 ( V_237 , ( int ) V_239 -> V_222 ) ;
T_10 V_159 = V_209 ;
int V_96 , V_228 , V_71 ;
T_6 V_192 ;
for ( V_96 = 0 ; V_96 < V_241 ; V_96 ++ ) {
if ( V_239 -> V_242 [ V_96 ] == V_208 )
break;
}
if ( V_96 != V_241 ) {
struct V_219 * V_243 = V_66 -> V_219 ;
int V_244 = V_243 -> V_222 ;
int V_245 = V_96 + 1 + V_244 + 1 ;
if ( V_245 > V_246 + V_233 ) {
F_180 ( L_50 ) ;
return 0 ;
}
for ( V_228 = 0 ; V_228 < V_245 ; V_228 ++ ) {
if ( V_247 . V_248 == V_249 ) {
if ( V_228 < V_96 + 1 )
V_192 = V_239 -> V_242 [ V_228 ] ;
else if ( V_228 > V_96 + 1 )
V_192 = V_243 -> V_224 [ V_228 - V_96 - 2 ] . V_225 ;
else
V_192 = V_243 -> V_224 [ 0 ] . V_223 ;
} else {
if ( V_228 < V_244 )
V_192 = V_243 -> V_224 [ V_244 - V_228 - 1 ] . V_225 ;
else if ( V_228 > V_244 )
V_192 = V_239 -> V_242 [ V_96 + 1 - ( V_228 - V_244 ) ] ;
else
V_192 = V_243 -> V_224 [ 0 ] . V_223 ;
}
V_71 = F_173 ( V_24 , V_38 , V_202 , & V_159 , V_192 ) ;
if ( V_71 )
return ( V_71 < 0 ) ? V_71 : 0 ;
}
return 1 ;
}
return 0 ;
}
static int F_181 ( struct V_24 * V_24 ,
struct V_250 * V_251 ,
struct V_65 * V_66 ,
struct V_187 * * V_38 ,
struct V_193 * V_202 ,
int V_237 )
{
struct V_219 * V_252 = V_66 -> V_219 ;
struct V_238 * V_239 = V_66 -> V_240 ;
int V_241 = V_166 ( V_237 , ( int ) V_239 -> V_222 ) ;
T_10 V_159 = V_209 ;
int V_96 , V_228 , V_71 ;
int V_253 = - 1 ;
int V_254 = 0 ;
F_174 ( & V_212 ) ;
if ( F_182 ( V_251 ) ) {
V_71 = F_179 ( V_24 , V_66 , V_38 ,
V_202 , V_237 ) ;
if ( V_71 )
return ( V_71 < 0 ) ? V_71 : 0 ;
}
if ( V_239 -> V_222 < V_246 )
V_253 = F_183 ( V_24 , V_239 ) ;
if ( V_252 && V_247 . V_255 ) {
int V_222 = V_166 ( V_237 , ( int ) V_252 -> V_222 ) ;
struct V_226 V_256 [ V_222 ] ;
if ( V_252 -> V_222 > V_233 ) {
F_180 ( L_51 ) ;
goto V_257;
}
for ( V_96 = 0 ; V_96 < V_222 ; V_96 ++ ) {
if ( V_247 . V_248 == V_249 ) {
V_256 [ V_96 ] = V_252 -> V_224 [ V_96 ] ;
if ( V_96 == V_253 ||
V_239 -> V_242 [ V_254 ] >= V_204 )
V_254 ++ ;
else if ( V_256 [ V_96 ] . V_225 < V_239 -> V_242 [ V_254 ] &&
V_256 [ V_96 ] . V_225 >= V_239 -> V_242 [ V_254 ] - 8 )
V_254 ++ ;
} else
V_256 [ V_96 ] = V_252 -> V_224 [ V_252 -> V_222 - V_96 - 1 ] ;
}
V_222 = F_177 ( V_256 , V_222 ) ;
for ( V_96 = 0 ; V_96 < V_222 ; V_96 ++ ) {
V_71 = F_173 ( V_24 , V_38 , V_202 ,
NULL , V_256 [ V_96 ] . V_223 ) ;
if ( ! V_71 )
V_71 = F_173 ( V_24 , V_38 , V_202 ,
NULL , V_256 [ V_96 ] . V_225 ) ;
if ( V_71 == - V_258 )
break;
if ( V_71 )
return V_71 ;
}
V_241 -= V_222 ;
}
V_257:
if ( V_239 -> V_222 > V_246 && ( int ) V_239 -> V_222 > V_237 ) {
F_180 ( L_50 ) ;
return 0 ;
}
for ( V_96 = V_254 ; V_96 < V_241 ; V_96 ++ ) {
T_6 V_192 ;
if ( V_247 . V_248 == V_249 )
V_228 = V_96 ;
else
V_228 = V_239 -> V_222 - V_96 - 1 ;
#ifdef F_184
if ( V_228 == V_253 )
continue;
#endif
V_192 = V_239 -> V_242 [ V_228 ] ;
V_71 = F_173 ( V_24 , V_38 , V_202 , & V_159 , V_192 ) ;
if ( V_71 )
return ( V_71 < 0 ) ? V_71 : 0 ;
}
return 0 ;
}
static int F_185 ( struct F_185 * V_259 , void * V_146 )
{
struct V_212 * V_260 = V_146 ;
if ( V_46 . V_217 && V_259 -> V_188 == NULL )
return 0 ;
return F_175 ( V_260 , V_259 -> V_192 ,
V_259 -> V_90 , V_259 -> V_188 ) ;
}
int F_186 ( struct V_24 * V_24 ,
struct V_250 * V_251 ,
struct V_65 * V_66 ,
struct V_187 * * V_38 ,
struct V_193 * V_202 ,
int V_237 )
{
int V_94 = F_181 ( V_24 , V_251 ,
V_66 , V_38 ,
V_202 , V_237 ) ;
if ( V_94 )
return V_94 ;
if ( ! ( ( V_251 -> V_261 . V_262 & V_263 ) &&
( V_251 -> V_261 . V_262 & V_264 ) ) )
return 0 ;
if ( ( ! V_66 -> V_265 . V_266 ) ||
( ! V_66 -> V_267 . V_54 ) )
return 0 ;
return F_187 ( F_185 , & V_212 ,
V_24 , V_66 , V_237 ) ;
}
int F_188 ( struct V_6 * V_6 ,
int (* F_189)( struct V_24 * V_24 , void * V_37 ) ,
void * V_268 )
{
struct V_10 * V_32 ;
struct V_24 * V_24 ;
int V_269 = 0 ;
for ( V_32 = F_22 ( & V_6 -> V_11 ) ; V_32 ; V_32 = F_24 ( V_32 ) ) {
V_24 = F_23 ( V_32 , struct V_24 , V_10 ) ;
V_269 = F_189 ( V_24 , V_268 ) ;
if ( V_269 != 0 )
return V_269 ;
}
F_144 (thread, &machine->dead_threads, node) {
V_269 = F_189 ( V_24 , V_268 ) ;
if ( V_269 != 0 )
return V_269 ;
}
return V_269 ;
}
int F_190 ( struct V_34 * V_34 ,
int (* F_189)( struct V_24 * V_24 , void * V_37 ) ,
void * V_268 )
{
struct V_10 * V_32 ;
int V_269 = 0 ;
V_269 = F_188 ( & V_34 -> V_35 , F_189 , V_268 ) ;
if ( V_269 != 0 )
return V_269 ;
for ( V_32 = F_22 ( & V_34 -> V_36 ) ; V_32 ; V_32 = F_24 ( V_32 ) ) {
struct V_6 * V_6 = F_23 ( V_32 , struct V_6 , V_10 ) ;
V_269 = F_188 ( V_6 , F_189 , V_268 ) ;
if ( V_269 != 0 )
return V_269 ;
}
return V_269 ;
}
int F_191 ( struct V_6 * V_6 , struct V_270 * V_271 ,
struct V_272 * V_272 , struct V_273 * V_11 ,
T_11 V_51 , bool V_274 ,
unsigned int V_275 )
{
if ( F_192 ( V_272 ) )
return F_193 ( V_271 , V_11 , V_51 , V_6 , V_274 , V_275 ) ;
else if ( F_194 ( V_272 ) )
return F_195 ( V_271 , V_51 , V_6 , V_274 , V_275 ) ;
return 0 ;
}
T_1 F_196 ( struct V_6 * V_6 , int V_276 )
{
if ( V_276 < 0 || V_276 >= V_277 || ! V_6 -> V_26 )
return - 1 ;
return V_6 -> V_26 [ V_276 ] ;
}
int F_197 ( struct V_6 * V_6 , int V_276 , T_1 V_8 ,
T_1 V_58 )
{
struct V_24 * V_24 ;
if ( V_276 < 0 )
return - V_258 ;
if ( ! V_6 -> V_26 ) {
int V_96 ;
V_6 -> V_26 = calloc ( V_277 , sizeof( T_1 ) ) ;
if ( ! V_6 -> V_26 )
return - V_22 ;
for ( V_96 = 0 ; V_96 < V_277 ; V_96 ++ )
V_6 -> V_26 [ V_96 ] = - 1 ;
}
if ( V_276 >= V_277 ) {
F_44 ( L_52 , V_276 ) ;
F_44 ( L_53 ) ;
return - V_258 ;
}
V_6 -> V_26 [ V_276 ] = V_58 ;
V_24 = F_8 ( V_6 , V_8 , V_58 ) ;
if ( ! V_24 )
return - V_22 ;
V_24 -> V_276 = V_276 ;
F_10 ( V_24 ) ;
return 0 ;
}
int F_198 ( struct V_6 * V_6 )
{
struct V_90 * V_90 = F_99 ( V_6 ) ;
int V_71 = 0 ;
V_6 -> V_20 = 1ULL << 63 ;
if ( V_90 ) {
V_71 = F_199 ( V_90 , V_6 -> V_17 ) ;
if ( V_90 -> V_91 )
V_6 -> V_20 = V_90 -> V_91 ;
}
return V_71 ;
}
struct V_28 * F_148 ( struct V_6 * V_6 , const char * V_80 )
{
return F_200 ( & V_6 -> V_1 , V_80 ) ;
}
char * F_201 ( void * V_278 , unsigned long long * V_279 , char * * V_280 )
{
struct V_6 * V_6 = V_278 ;
struct V_90 * V_90 ;
struct V_187 * V_188 = F_202 ( & V_6 -> V_9 , V_92 , * V_279 , & V_90 , NULL ) ;
if ( V_188 == NULL )
return NULL ;
* V_280 = F_203 ( V_90 ) ? ( char * ) V_90 -> V_28 -> V_281 : NULL ;
* V_279 = V_90 -> V_117 ( V_90 , V_188 -> V_91 ) ;
return V_188 -> V_81 ;
}
