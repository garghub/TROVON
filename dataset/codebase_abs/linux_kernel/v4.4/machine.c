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
V_6 -> V_16 = NULL ;
V_6 -> V_8 = V_8 ;
V_6 -> V_17 = NULL ;
V_6 -> V_18 = 0 ;
V_6 -> V_19 = false ;
V_6 -> V_20 = 0 ;
V_6 -> V_7 = F_7 ( V_7 ) ;
if ( V_6 -> V_7 == NULL )
return - V_21 ;
if ( V_8 != V_22 ) {
struct V_23 * V_23 = F_8 ( V_6 , - 1 ,
V_8 ) ;
char V_24 [ 64 ] ;
if ( V_23 == NULL )
return - V_21 ;
snprintf ( V_24 , sizeof( V_24 ) , L_1 , V_8 ) ;
F_9 ( V_23 , V_24 , 0 ) ;
F_10 ( V_23 ) ;
}
V_6 -> V_25 = NULL ;
return 0 ;
}
struct V_6 * F_11 ( void )
{
struct V_6 * V_6 = malloc ( sizeof( * V_6 ) ) ;
if ( V_6 != NULL ) {
F_4 ( V_6 , L_2 , V_22 ) ;
if ( F_12 ( V_6 ) < 0 )
goto V_26;
}
return V_6 ;
V_26:
free ( V_6 ) ;
return NULL ;
}
static void F_13 ( struct V_1 * V_1 )
{
struct V_27 * V_28 , * V_29 ;
F_14 ( & V_1 -> V_5 ) ;
F_15 (pos, n, &dsos->head, node) {
F_6 ( & V_28 -> V_10 ) ;
V_28 -> V_3 = NULL ;
F_16 ( & V_28 -> V_30 ) ;
F_17 ( V_28 ) ;
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
struct V_10 * V_31 ;
F_14 ( & V_6 -> V_12 ) ;
V_31 = F_22 ( & V_6 -> V_11 ) ;
while ( V_31 ) {
struct V_23 * V_32 = F_23 ( V_31 , struct V_23 , V_10 ) ;
V_31 = F_24 ( V_31 ) ;
F_25 ( V_6 , V_32 , false ) ;
}
F_18 ( & V_6 -> V_12 ) ;
}
void F_26 ( struct V_6 * V_6 )
{
F_27 ( & V_6 -> V_9 ) ;
F_19 ( & V_6 -> V_1 ) ;
F_28 ( V_6 ) ;
F_29 ( & V_6 -> V_7 ) ;
F_29 ( & V_6 -> V_25 ) ;
F_20 ( & V_6 -> V_12 ) ;
}
void F_30 ( struct V_6 * V_6 )
{
F_26 ( V_6 ) ;
free ( V_6 ) ;
}
void F_31 ( struct V_33 * V_33 )
{
F_4 ( & V_33 -> V_34 , L_2 , V_22 ) ;
V_33 -> V_35 = V_4 ;
V_33 -> V_17 = NULL ;
}
void F_32 ( struct V_33 * V_33 )
{
F_26 ( & V_33 -> V_34 ) ;
}
struct V_6 * F_33 ( struct V_33 * V_33 , T_1 V_8 ,
const char * V_7 )
{
struct V_10 * * V_36 = & V_33 -> V_35 . V_10 ;
struct V_10 * V_37 = NULL ;
struct V_6 * V_28 , * V_6 = malloc ( sizeof( * V_6 ) ) ;
if ( V_6 == NULL )
return NULL ;
if ( F_4 ( V_6 , V_7 , V_8 ) != 0 ) {
free ( V_6 ) ;
return NULL ;
}
V_6 -> V_17 = V_33 -> V_17 ;
while ( * V_36 != NULL ) {
V_37 = * V_36 ;
V_28 = F_23 ( V_37 , struct V_6 , V_10 ) ;
if ( V_8 < V_28 -> V_8 )
V_36 = & ( * V_36 ) -> V_38 ;
else
V_36 = & ( * V_36 ) -> V_39 ;
}
F_34 ( & V_6 -> V_10 , V_37 , V_36 ) ;
F_35 ( & V_6 -> V_10 , & V_33 -> V_35 ) ;
return V_6 ;
}
void F_36 ( struct V_33 * V_33 ,
T_2 V_17 )
{
struct V_10 * V_31 ;
V_33 -> V_17 = V_17 ;
V_33 -> V_34 . V_17 = V_17 ;
for ( V_31 = F_22 ( & V_33 -> V_35 ) ; V_31 ; V_31 = F_24 ( V_31 ) ) {
struct V_6 * V_6 = F_23 ( V_31 , struct V_6 , V_10 ) ;
V_6 -> V_17 = V_17 ;
}
}
void F_37 ( struct V_33 * V_33 , bool V_19 )
{
struct V_10 * V_31 ;
V_33 -> V_34 . V_19 = V_19 ;
for ( V_31 = F_22 ( & V_33 -> V_35 ) ; V_31 ; V_31 = F_24 ( V_31 ) ) {
struct V_6 * V_6 = F_23 ( V_31 , struct V_6 , V_10 ) ;
V_6 -> V_19 = V_19 ;
}
}
struct V_6 * F_38 ( struct V_33 * V_33 , T_1 V_8 )
{
struct V_10 * * V_36 = & V_33 -> V_35 . V_10 ;
struct V_10 * V_37 = NULL ;
struct V_6 * V_6 ;
struct V_6 * V_40 = NULL ;
if ( V_8 == V_22 )
return & V_33 -> V_34 ;
while ( * V_36 != NULL ) {
V_37 = * V_36 ;
V_6 = F_23 ( V_37 , struct V_6 , V_10 ) ;
if ( V_8 < V_6 -> V_8 )
V_36 = & ( * V_36 ) -> V_38 ;
else if ( V_8 > V_6 -> V_8 )
V_36 = & ( * V_36 ) -> V_39 ;
else
return V_6 ;
if ( ! V_6 -> V_8 )
V_40 = V_6 ;
}
return V_40 ;
}
struct V_6 * F_39 ( struct V_33 * V_33 , T_1 V_8 )
{
char V_41 [ V_42 ] ;
const char * V_7 = L_2 ;
struct V_6 * V_6 = F_38 ( V_33 , V_8 ) ;
if ( V_6 && ( V_6 -> V_8 == V_8 ) )
goto V_43;
if ( ( V_8 != V_22 ) &&
( V_8 != V_44 ) &&
( V_45 . V_46 ) ) {
sprintf ( V_41 , L_3 , V_45 . V_46 , V_8 ) ;
if ( F_40 ( V_41 , V_47 ) ) {
static struct V_48 * V_49 ;
if ( ! V_49 )
V_49 = F_41 ( NULL , NULL ) ;
if ( ! F_42 ( V_49 , V_41 ) ) {
F_43 ( L_4 , V_41 ) ;
F_44 ( V_49 , V_41 ) ;
}
V_6 = NULL ;
goto V_43;
}
V_7 = V_41 ;
}
V_6 = F_33 ( V_33 , V_8 , V_7 ) ;
V_43:
return V_6 ;
}
void F_45 ( struct V_33 * V_33 ,
T_3 V_50 , void * V_51 )
{
struct V_10 * V_31 ;
for ( V_31 = F_22 ( & V_33 -> V_35 ) ; V_31 ; V_31 = F_24 ( V_31 ) ) {
struct V_6 * V_28 = F_23 ( V_31 , struct V_6 , V_10 ) ;
V_50 ( V_28 , V_51 ) ;
}
}
char * F_46 ( struct V_6 * V_6 , char * V_52 , T_4 V_53 )
{
if ( F_47 ( V_6 ) )
snprintf ( V_52 , V_53 , L_5 , L_6 ) ;
else if ( F_48 ( V_6 ) )
snprintf ( V_52 , V_53 , L_5 , L_7 ) ;
else {
snprintf ( V_52 , V_53 , L_8 , L_7 ,
V_6 -> V_8 ) ;
}
return V_52 ;
}
void F_49 ( struct V_33 * V_33 , T_5 V_18 )
{
struct V_10 * V_30 ;
struct V_6 * V_6 ;
V_33 -> V_34 . V_18 = V_18 ;
for ( V_30 = F_22 ( & V_33 -> V_35 ) ; V_30 ; V_30 = F_24 ( V_30 ) ) {
V_6 = F_23 ( V_30 , struct V_6 , V_10 ) ;
V_6 -> V_18 = V_18 ;
}
return;
}
static void F_50 ( struct V_6 * V_6 ,
struct V_23 * V_54 , T_1 V_8 )
{
struct V_23 * V_55 ;
if ( V_8 == V_54 -> V_56 || V_8 == - 1 || V_54 -> V_56 != - 1 )
return;
V_54 -> V_56 = V_8 ;
if ( V_54 -> V_56 == V_54 -> V_57 )
return;
V_55 = F_51 ( V_6 , V_54 -> V_56 , V_54 -> V_56 ) ;
if ( ! V_55 )
goto V_58;
if ( ! V_55 -> V_59 )
V_55 -> V_59 = F_52 ( V_6 ) ;
if ( ! V_55 -> V_59 )
goto V_58;
if ( V_54 -> V_59 == V_55 -> V_59 )
return;
if ( V_54 -> V_59 ) {
if ( ! F_53 ( V_54 -> V_59 ) )
F_43 ( L_9 ,
V_54 -> V_56 , V_54 -> V_57 ) ;
F_54 ( V_54 -> V_59 ) ;
}
V_54 -> V_59 = F_55 ( V_55 -> V_59 ) ;
return;
V_58:
F_43 ( L_10 , V_54 -> V_56 , V_54 -> V_57 ) ;
}
static struct V_23 * F_56 ( struct V_6 * V_6 ,
T_1 V_8 , T_1 V_57 ,
bool V_60 )
{
struct V_10 * * V_36 = & V_6 -> V_11 . V_10 ;
struct V_10 * V_37 = NULL ;
struct V_23 * V_54 ;
V_54 = V_6 -> V_14 ;
if ( V_54 != NULL ) {
if ( V_54 -> V_57 == V_57 ) {
F_50 ( V_6 , V_54 , V_8 ) ;
return V_54 ;
}
V_6 -> V_14 = NULL ;
}
while ( * V_36 != NULL ) {
V_37 = * V_36 ;
V_54 = F_23 ( V_37 , struct V_23 , V_10 ) ;
if ( V_54 -> V_57 == V_57 ) {
V_6 -> V_14 = V_54 ;
F_50 ( V_6 , V_54 , V_8 ) ;
return V_54 ;
}
if ( V_57 < V_54 -> V_57 )
V_36 = & ( * V_36 ) -> V_38 ;
else
V_36 = & ( * V_36 ) -> V_39 ;
}
if ( ! V_60 )
return NULL ;
V_54 = F_57 ( V_8 , V_57 ) ;
if ( V_54 != NULL ) {
F_34 ( & V_54 -> V_10 , V_37 , V_36 ) ;
F_35 ( & V_54 -> V_10 , & V_6 -> V_11 ) ;
if ( F_58 ( V_54 , V_6 ) ) {
F_59 ( & V_54 -> V_10 , & V_6 -> V_11 ) ;
F_6 ( & V_54 -> V_10 ) ;
F_60 ( V_54 ) ;
return NULL ;
}
F_61 ( V_54 ) ;
V_6 -> V_14 = V_54 ;
}
return V_54 ;
}
struct V_23 * F_51 ( struct V_6 * V_6 , T_1 V_8 , T_1 V_57 )
{
return F_56 ( V_6 , V_8 , V_57 , true ) ;
}
struct V_23 * F_8 ( struct V_6 * V_6 , T_1 V_8 ,
T_1 V_57 )
{
struct V_23 * V_54 ;
F_14 ( & V_6 -> V_12 ) ;
V_54 = F_61 ( F_51 ( V_6 , V_8 , V_57 ) ) ;
F_18 ( & V_6 -> V_12 ) ;
return V_54 ;
}
struct V_23 * F_62 ( struct V_6 * V_6 , T_1 V_8 ,
T_1 V_57 )
{
struct V_23 * V_54 ;
F_63 ( & V_6 -> V_12 ) ;
V_54 = F_61 ( F_56 ( V_6 , V_8 , V_57 , false ) ) ;
F_18 ( & V_6 -> V_12 ) ;
return V_54 ;
}
struct V_24 * F_64 ( struct V_6 * V_6 ,
struct V_23 * V_23 )
{
if ( V_6 -> V_19 )
return F_65 ( V_23 ) ;
else
return F_66 ( V_23 ) ;
}
int F_67 ( struct V_6 * V_6 , union V_61 * V_62 ,
struct V_63 * V_64 )
{
struct V_23 * V_23 = F_8 ( V_6 ,
V_62 -> V_24 . V_8 ,
V_62 -> V_24 . V_57 ) ;
bool V_65 = V_62 -> V_66 . V_67 & V_68 ;
int V_69 = 0 ;
if ( V_65 )
V_6 -> V_19 = true ;
if ( V_70 )
F_68 ( V_62 , stdout ) ;
if ( V_23 == NULL ||
F_69 ( V_23 , V_62 -> V_24 . V_24 , V_64 -> time , V_65 ) ) {
F_70 ( L_11 ) ;
V_69 = - 1 ;
}
F_10 ( V_23 ) ;
return V_69 ;
}
int F_71 ( struct V_6 * V_6 V_71 ,
union V_61 * V_62 , struct V_63 * V_64 V_71 )
{
F_70 ( L_12 V_72 L_13 V_72 L_14 ,
V_62 -> V_73 . V_74 , V_62 -> V_73 . V_73 ) ;
return 0 ;
}
int F_72 ( struct V_6 * V_6 V_71 ,
union V_61 * V_62 , struct V_63 * V_64 )
{
F_70 ( L_12 V_72 L_15 V_72 L_14 ,
V_64 -> V_74 , V_62 -> V_75 . V_73 ) ;
return 0 ;
}
static struct V_27 * F_73 ( struct V_6 * V_6 ,
struct V_76 * V_77 ,
const char * V_78 )
{
struct V_27 * V_27 ;
F_14 ( & V_6 -> V_1 . V_5 ) ;
V_27 = F_74 ( & V_6 -> V_1 , V_77 -> V_79 , true ) ;
if ( ! V_27 ) {
V_27 = F_75 ( & V_6 -> V_1 , V_77 -> V_79 ) ;
if ( V_27 == NULL )
goto V_80;
if ( F_47 ( V_6 ) )
V_27 -> V_81 = V_82 ;
else
V_27 -> V_81 = V_83 ;
if ( V_77 -> V_84 && V_77 -> V_85 )
V_27 -> V_81 ++ ;
F_76 ( V_27 , F_7 ( V_77 -> V_79 ) , true ) ;
F_77 ( V_27 , F_7 ( V_78 ) , true ) ;
}
F_78 ( V_27 ) ;
V_80:
F_18 ( & V_6 -> V_1 . V_5 ) ;
return V_27 ;
}
int F_79 ( struct V_6 * V_6 V_71 ,
union V_61 * V_62 )
{
if ( V_70 )
F_80 ( V_62 , stdout ) ;
return 0 ;
}
int F_81 ( struct V_6 * V_6 V_71 ,
union V_61 * V_62 )
{
if ( V_70 )
F_82 ( V_62 , stdout ) ;
return 0 ;
}
int F_83 ( struct V_6 * V_6 V_71 ,
union V_61 * V_62 )
{
if ( V_70 )
F_84 ( V_62 , stdout ) ;
return 0 ;
}
struct V_86 * F_85 ( struct V_6 * V_6 , T_6 V_87 ,
const char * V_78 )
{
struct V_86 * V_86 = NULL ;
struct V_27 * V_27 ;
struct V_76 V_77 ;
if ( F_86 ( & V_77 , V_78 ) )
return NULL ;
V_86 = F_87 ( & V_6 -> V_9 , V_88 ,
V_77 . V_79 ) ;
if ( V_86 )
goto V_43;
V_27 = F_73 ( V_6 , & V_77 , V_78 ) ;
if ( V_27 == NULL )
goto V_43;
V_86 = F_88 ( V_87 , V_27 , V_88 ) ;
if ( V_86 == NULL )
goto V_43;
F_89 ( & V_6 -> V_9 , V_86 ) ;
V_43:
free ( V_77 . V_79 ) ;
return V_86 ;
}
T_4 F_90 ( struct V_33 * V_33 , T_7 * V_89 )
{
struct V_10 * V_31 ;
T_4 V_90 = F_91 ( & V_33 -> V_34 . V_1 . V_2 , V_89 ) ;
for ( V_31 = F_22 ( & V_33 -> V_35 ) ; V_31 ; V_31 = F_24 ( V_31 ) ) {
struct V_6 * V_28 = F_23 ( V_31 , struct V_6 , V_10 ) ;
V_90 += F_91 ( & V_28 -> V_1 . V_2 , V_89 ) ;
}
return V_90 ;
}
T_4 F_92 ( struct V_6 * V_77 , T_7 * V_89 ,
bool (F_93)( struct V_27 * V_27 , int V_91 ) , int V_91 )
{
return F_94 ( & V_77 -> V_1 . V_2 , V_89 , F_93 , V_91 ) ;
}
T_4 F_95 ( struct V_33 * V_33 , T_7 * V_89 ,
bool (F_93)( struct V_27 * V_27 , int V_91 ) , int V_91 )
{
struct V_10 * V_31 ;
T_4 V_90 = F_92 ( & V_33 -> V_34 , V_89 , F_93 , V_91 ) ;
for ( V_31 = F_22 ( & V_33 -> V_35 ) ; V_31 ; V_31 = F_24 ( V_31 ) ) {
struct V_6 * V_28 = F_23 ( V_31 , struct V_6 , V_10 ) ;
V_90 += F_92 ( V_28 , V_89 , F_93 , V_91 ) ;
}
return V_90 ;
}
T_4 F_96 ( struct V_6 * V_6 , T_7 * V_89 )
{
int V_92 ;
T_4 V_93 = 0 ;
struct V_27 * V_94 = F_97 ( V_6 ) -> V_27 ;
if ( V_94 -> V_95 ) {
char V_78 [ V_42 ] ;
if ( F_98 ( V_94 , V_78 , sizeof( V_78 ) ) )
V_93 += fprintf ( V_89 , L_16 , V_78 ) ;
}
for ( V_92 = 0 ; V_92 < V_96 ; ++ V_92 )
V_93 += fprintf ( V_89 , L_17 ,
V_92 + V_94 -> V_95 , V_97 [ V_92 ] ) ;
return V_93 ;
}
T_4 F_99 ( struct V_6 * V_6 , T_7 * V_89 )
{
T_4 V_90 = 0 ;
struct V_10 * V_31 ;
F_63 ( & V_6 -> V_12 ) ;
for ( V_31 = F_22 ( & V_6 -> V_11 ) ; V_31 ; V_31 = F_24 ( V_31 ) ) {
struct V_23 * V_28 = F_23 ( V_31 , struct V_23 , V_10 ) ;
V_90 += F_100 ( V_28 , V_89 ) ;
}
F_18 ( & V_6 -> V_12 ) ;
return V_90 ;
}
static struct V_27 * F_101 ( struct V_6 * V_6 )
{
const char * V_98 = NULL ;
struct V_27 * V_99 ;
if ( F_47 ( V_6 ) ) {
V_98 = V_45 . V_98 ;
if ( ! V_98 )
V_98 = L_18 ;
V_99 = F_102 ( V_6 , V_98 ,
L_19 , V_100 ) ;
} else {
char V_52 [ V_42 ] ;
if ( F_48 ( V_6 ) )
V_98 = V_45 . V_101 ;
if ( ! V_98 )
V_98 = F_46 ( V_6 , V_52 ,
sizeof( V_52 ) ) ;
V_99 = F_102 ( V_6 , V_98 ,
L_20 ,
V_102 ) ;
}
if ( V_99 != NULL && ( ! V_99 -> V_95 ) )
F_103 ( V_99 , V_6 ) ;
return V_99 ;
}
static void F_104 ( struct V_6 * V_6 , char * V_103 ,
T_4 V_104 )
{
if ( F_48 ( V_6 ) )
F_105 ( V_103 , V_104 , L_21 , V_45 . V_105 ) ;
else
F_105 ( V_103 , V_104 , L_22 , V_6 -> V_7 ) ;
}
static T_6 F_106 ( struct V_6 * V_6 ,
const char * * V_106 )
{
char V_78 [ V_42 ] ;
int V_92 ;
const char * V_79 ;
T_6 V_107 = 0 ;
F_104 ( V_6 , V_78 , V_42 ) ;
if ( F_107 ( V_78 , L_23 ) )
return 0 ;
for ( V_92 = 0 ; ( V_79 = V_108 [ V_92 ] ) != NULL ; V_92 ++ ) {
V_107 = F_108 ( V_78 , V_79 ) ;
if ( V_107 )
break;
}
if ( V_106 )
* V_106 = V_79 ;
return V_107 ;
}
int F_109 ( struct V_6 * V_6 , struct V_27 * V_99 )
{
enum V_109 type ;
T_6 V_87 = F_106 ( V_6 , NULL ) ;
for ( type = 0 ; type < V_110 ; ++ type ) {
struct V_111 * V_111 ;
struct V_86 * V_86 ;
V_6 -> V_112 [ type ] = F_88 ( V_87 , V_99 , type ) ;
if ( V_6 -> V_112 [ type ] == NULL )
return - 1 ;
V_6 -> V_112 [ type ] -> V_113 =
V_6 -> V_112 [ type ] -> V_114 =
V_115 ;
V_86 = F_110 ( V_6 , type ) ;
V_111 = F_111 ( V_86 ) ;
if ( ! V_111 )
return - 1 ;
V_111 -> V_9 = & V_6 -> V_9 ;
F_89 ( & V_6 -> V_9 , V_86 ) ;
}
return 0 ;
}
void F_112 ( struct V_6 * V_6 )
{
enum V_109 type ;
for ( type = 0 ; type < V_110 ; ++ type ) {
struct V_111 * V_111 ;
struct V_86 * V_86 = F_110 ( V_6 , type ) ;
if ( V_86 == NULL )
continue;
V_111 = F_111 ( V_86 ) ;
F_113 ( & V_6 -> V_9 , V_86 ) ;
if ( V_111 && V_111 -> V_116 ) {
if ( type == V_88 ) {
F_29 ( ( char * * ) & V_111 -> V_116 -> V_79 ) ;
F_29 ( & V_111 -> V_116 ) ;
} else
V_111 -> V_116 = NULL ;
}
V_6 -> V_112 [ type ] = NULL ;
}
}
int F_114 ( struct V_33 * V_33 )
{
int V_90 = 0 ;
struct V_117 * * V_118 = NULL ;
int V_92 , V_119 = 0 ;
char V_41 [ V_42 ] ;
T_1 V_8 ;
char * V_120 ;
if ( V_45 . V_101 ||
V_45 . V_121 ||
V_45 . V_105 ) {
F_115 ( V_33 , V_44 ) ;
}
if ( V_45 . V_46 ) {
V_119 = F_116 ( V_45 . V_46 , & V_118 , NULL , NULL ) ;
if ( V_119 <= 0 )
return - V_122 ;
for ( V_92 = 0 ; V_92 < V_119 ; V_92 ++ ) {
if ( ! isdigit ( V_118 [ V_92 ] -> V_123 [ 0 ] ) ) {
continue;
}
V_8 = ( T_1 ) strtol ( V_118 [ V_92 ] -> V_123 , & V_120 , 10 ) ;
if ( ( * V_120 != '\0' ) ||
( V_120 == V_118 [ V_92 ] -> V_123 ) ||
( V_124 == V_125 ) ) {
F_117 ( L_24 ,
V_118 [ V_92 ] -> V_123 ) ;
continue;
}
sprintf ( V_41 , L_25 ,
V_45 . V_46 ,
V_118 [ V_92 ] -> V_123 ) ;
V_90 = F_40 ( V_41 , V_47 ) ;
if ( V_90 ) {
F_117 ( L_4 , V_41 ) ;
goto V_126;
}
F_115 ( V_33 , V_8 ) ;
}
V_126:
free ( V_118 ) ;
}
return V_90 ;
}
void F_118 ( struct V_33 * V_33 )
{
struct V_10 * V_127 = F_22 ( & V_33 -> V_35 ) ;
F_112 ( & V_33 -> V_34 ) ;
while ( V_127 ) {
struct V_6 * V_28 = F_23 ( V_127 , struct V_6 , V_10 ) ;
V_127 = F_24 ( & V_28 -> V_10 ) ;
F_119 ( & V_28 -> V_10 , & V_33 -> V_35 ) ;
F_30 ( V_28 ) ;
}
}
int F_115 ( struct V_33 * V_33 , T_1 V_8 )
{
struct V_6 * V_6 = F_39 ( V_33 , V_8 ) ;
if ( V_6 == NULL )
return - 1 ;
return F_12 ( V_6 ) ;
}
int F_120 ( struct V_6 * V_6 , const char * V_78 ,
enum V_109 type , T_2 V_128 )
{
struct V_86 * V_86 = F_97 ( V_6 ) ;
int V_90 = F_121 ( V_86 -> V_27 , V_78 , V_86 , V_128 ) ;
if ( V_90 > 0 ) {
F_122 ( V_86 -> V_27 , type ) ;
F_123 ( & V_6 -> V_9 , type ) ;
}
return V_90 ;
}
int F_124 ( struct V_6 * V_6 , enum V_109 type ,
T_2 V_128 )
{
struct V_86 * V_86 = F_97 ( V_6 ) ;
int V_90 = F_125 ( V_86 -> V_27 , V_86 , V_128 ) ;
if ( V_90 > 0 )
F_122 ( V_86 -> V_27 , type ) ;
return V_90 ;
}
static void F_126 ( struct V_129 * V_59 )
{
int V_92 ;
for ( V_92 = 0 ; V_92 < V_110 ; ++ V_92 )
F_123 ( V_59 , V_92 ) ;
}
static char * F_127 ( const char * V_7 )
{
char V_130 [ V_42 ] ;
T_7 * V_131 ;
char * V_79 , * V_132 ;
const char * V_133 = L_26 ;
sprintf ( V_130 , L_27 , V_7 ) ;
V_131 = fopen ( V_130 , L_28 ) ;
if ( ! V_131 )
return NULL ;
V_130 [ 0 ] = '\0' ;
V_132 = fgets ( V_130 , sizeof( V_130 ) , V_131 ) ;
fclose ( V_131 ) ;
V_79 = strstr ( V_130 , V_133 ) ;
if ( ! V_79 )
return NULL ;
V_79 += strlen ( V_133 ) ;
V_132 = strchr ( V_79 , ' ' ) ;
if ( V_132 )
* V_132 = '\0' ;
return F_7 ( V_79 ) ;
}
static bool F_128 ( struct V_27 * V_27 )
{
return V_27 -> V_81 == V_82 ||
V_27 -> V_81 == V_83 ;
}
static int F_129 ( struct V_129 * V_59 , const char * V_41 ,
struct V_76 * V_77 )
{
struct V_86 * V_86 ;
char * V_134 ;
V_86 = F_87 ( V_59 , V_88 , V_77 -> V_79 ) ;
if ( V_86 == NULL )
return 0 ;
V_134 = F_7 ( V_41 ) ;
if ( V_134 == NULL )
return - V_21 ;
F_77 ( V_86 -> V_27 , V_134 , true ) ;
F_130 ( V_86 -> V_27 , L_2 ) ;
if ( V_77 -> V_85 && F_128 ( V_86 -> V_27 ) )
V_86 -> V_27 -> V_81 ++ ;
return 0 ;
}
static int F_131 ( struct V_129 * V_59 ,
const char * V_135 , int V_136 )
{
struct V_117 * V_137 ;
T_8 * V_138 = F_132 ( V_135 ) ;
int V_90 = 0 ;
if ( ! V_138 ) {
F_117 ( L_29 , V_139 , V_135 ) ;
return - 1 ;
}
while ( ( V_137 = F_133 ( V_138 ) ) != NULL ) {
char V_41 [ V_42 ] ;
struct V_140 V_141 ;
snprintf ( V_41 , sizeof( V_41 ) , L_30 , V_135 , V_137 -> V_123 ) ;
if ( V_140 ( V_41 , & V_141 ) )
continue;
if ( F_134 ( V_141 . V_142 ) ) {
if ( ! strcmp ( V_137 -> V_123 , L_31 ) ||
! strcmp ( V_137 -> V_123 , L_32 ) )
continue;
if ( V_136 == 0 ) {
if ( ! strcmp ( V_137 -> V_123 , L_33 ) ||
! strcmp ( V_137 -> V_123 , L_34 ) )
continue;
}
V_90 = F_131 ( V_59 , V_41 ,
V_136 + 1 ) ;
if ( V_90 < 0 )
goto V_43;
} else {
struct V_76 V_77 ;
V_90 = F_86 ( & V_77 , V_137 -> V_123 ) ;
if ( V_90 )
goto V_43;
if ( V_77 . V_84 )
V_90 = F_129 ( V_59 , V_41 , & V_77 ) ;
free ( V_77 . V_79 ) ;
if ( V_90 )
goto V_43;
}
}
V_43:
F_135 ( V_138 ) ;
return V_90 ;
}
static int F_136 ( struct V_6 * V_6 )
{
char * V_130 ;
char V_143 [ V_42 ] ;
V_130 = F_127 ( V_6 -> V_7 ) ;
if ( ! V_130 )
return - 1 ;
snprintf ( V_143 , sizeof( V_143 ) , L_35 ,
V_6 -> V_7 , V_130 ) ;
free ( V_130 ) ;
return F_131 ( & V_6 -> V_9 , V_143 , 0 ) ;
}
static int F_137 ( void * V_144 , const char * V_79 , T_6 V_87 )
{
struct V_6 * V_6 = V_144 ;
struct V_86 * V_86 ;
V_86 = F_85 ( V_6 , V_87 , V_79 ) ;
if ( V_86 == NULL )
return - 1 ;
F_130 ( V_86 -> V_27 , V_6 -> V_7 ) ;
return 0 ;
}
static int F_138 ( struct V_6 * V_6 )
{
const char * V_145 ;
char V_41 [ V_42 ] ;
if ( F_48 ( V_6 ) ) {
V_145 = V_45 . V_121 ;
} else {
snprintf ( V_41 , V_42 , L_36 , V_6 -> V_7 ) ;
V_145 = V_41 ;
}
if ( F_107 ( V_145 , L_37 ) )
return - 1 ;
if ( F_139 ( V_145 , V_6 , F_137 ) )
return - 1 ;
if ( ! F_136 ( V_6 ) )
return 0 ;
F_117 ( L_38 ) ;
return 0 ;
}
int F_12 ( struct V_6 * V_6 )
{
struct V_27 * V_99 = F_101 ( V_6 ) ;
const char * V_79 ;
T_6 V_107 = F_106 ( V_6 , & V_79 ) ;
if ( ! V_107 )
return - 1 ;
if ( V_99 == NULL ||
F_109 ( V_6 , V_99 ) < 0 )
return - 1 ;
if ( V_45 . V_146 && F_138 ( V_6 ) < 0 ) {
if ( F_47 ( V_6 ) )
F_117 ( L_39
L_40 ) ;
else
F_117 ( L_41
L_40 , V_6 -> V_8 ) ;
}
F_126 ( & V_6 -> V_9 ) ;
if ( F_140 ( V_6 -> V_112 , V_79 ,
V_107 ) ) {
F_112 ( V_6 ) ;
return - 1 ;
}
return 0 ;
}
static void F_141 ( struct V_6 * V_6 ,
union V_61 * V_62 )
{
int V_92 ;
for ( V_92 = 0 ; V_92 < V_110 ; V_92 ++ ) {
V_6 -> V_112 [ V_92 ] -> V_87 = V_62 -> V_147 . V_87 ;
V_6 -> V_112 [ V_92 ] -> V_148 = ( V_62 -> V_147 . V_87 +
V_62 -> V_147 . V_149 ) ;
if ( V_6 -> V_112 [ V_92 ] -> V_148 == 0 )
V_6 -> V_112 [ V_92 ] -> V_148 = ~ 0ULL ;
}
}
static bool F_142 ( struct V_6 * V_6 )
{
struct V_27 * V_27 ;
F_143 (dso, &machine->dsos.head, node) {
if ( F_144 ( V_27 ) )
return true ;
}
return false ;
}
static int F_145 ( struct V_6 * V_6 ,
union V_61 * V_62 )
{
struct V_86 * V_86 ;
char V_150 [ V_42 ] ;
enum V_151 V_152 ;
bool V_153 ;
if ( F_142 ( V_6 ) )
return 0 ;
F_46 ( V_6 , V_150 , sizeof( V_150 ) ) ;
if ( F_47 ( V_6 ) )
V_152 = V_100 ;
else
V_152 = V_102 ;
V_153 = memcmp ( V_62 -> V_147 . V_78 ,
V_150 ,
strlen ( V_150 ) - 1 ) == 0 ;
if ( V_62 -> V_147 . V_78 [ 0 ] == '/' ||
( ! V_153 && V_62 -> V_147 . V_78 [ 0 ] == '[' ) ) {
V_86 = F_85 ( V_6 , V_62 -> V_147 . V_87 ,
V_62 -> V_147 . V_78 ) ;
if ( V_86 == NULL )
goto V_154;
V_86 -> V_148 = V_86 -> V_87 + V_62 -> V_147 . V_149 ;
} else if ( V_153 ) {
const char * V_106 = ( V_62 -> V_147 . V_78 +
strlen ( V_150 ) ) ;
struct V_27 * V_99 = NULL ;
struct V_27 * V_27 ;
F_63 ( & V_6 -> V_1 . V_5 ) ;
F_143 (dso, &machine->dsos.head, node) {
if ( ! V_27 -> V_99 ||
F_146 ( V_27 -> V_134 ,
V_155 ) )
continue;
V_99 = V_27 ;
break;
}
F_18 ( & V_6 -> V_1 . V_5 ) ;
if ( V_99 == NULL )
V_99 = F_147 ( V_6 , V_150 ) ;
if ( V_99 == NULL )
goto V_154;
V_99 -> V_99 = V_152 ;
if ( F_109 ( V_6 , V_99 ) < 0 ) {
F_17 ( V_99 ) ;
goto V_154;
}
if ( strstr ( V_99 -> V_134 , L_42 ) )
F_76 ( V_99 , L_43 , false ) ;
F_141 ( V_6 , V_62 ) ;
if ( V_62 -> V_147 . V_156 != 0 ) {
F_140 ( V_6 -> V_112 ,
V_106 ,
V_62 -> V_147 . V_156 ) ;
}
if ( F_48 ( V_6 ) ) {
F_148 ( V_99 , F_97 ( V_6 ) , NULL ) ;
}
}
return 0 ;
V_154:
return - 1 ;
}
int F_149 ( struct V_6 * V_6 ,
union V_61 * V_62 ,
struct V_63 * V_64 V_71 )
{
T_9 V_157 = V_62 -> V_66 . V_67 & V_158 ;
struct V_23 * V_23 ;
struct V_86 * V_86 ;
enum V_109 type ;
int V_90 = 0 ;
if ( V_70 )
F_150 ( V_62 , stdout ) ;
if ( V_157 == V_159 ||
V_157 == V_160 ) {
V_90 = F_145 ( V_6 , V_62 ) ;
if ( V_90 < 0 )
goto V_154;
return 0 ;
}
V_23 = F_8 ( V_6 , V_62 -> V_161 . V_8 ,
V_62 -> V_161 . V_57 ) ;
if ( V_23 == NULL )
goto V_154;
if ( V_62 -> V_66 . V_67 & V_162 )
type = V_163 ;
else
type = V_88 ;
V_86 = F_151 ( V_6 , V_62 -> V_161 . V_87 ,
V_62 -> V_161 . V_149 , V_62 -> V_161 . V_156 ,
V_62 -> V_161 . V_8 , V_62 -> V_161 . V_164 ,
V_62 -> V_161 . V_165 , V_62 -> V_161 . V_166 ,
V_62 -> V_161 . V_167 ,
V_62 -> V_161 . V_168 ,
V_62 -> V_161 . V_169 ,
V_62 -> V_161 . V_78 , type , V_23 ) ;
if ( V_86 == NULL )
goto V_170;
F_152 ( V_23 , V_86 ) ;
F_10 ( V_23 ) ;
F_153 ( V_86 ) ;
return 0 ;
V_170:
F_10 ( V_23 ) ;
V_154:
F_70 ( L_44 ) ;
return 0 ;
}
int F_154 ( struct V_6 * V_6 , union V_61 * V_62 ,
struct V_63 * V_64 V_71 )
{
T_9 V_157 = V_62 -> V_66 . V_67 & V_158 ;
struct V_23 * V_23 ;
struct V_86 * V_86 ;
enum V_109 type ;
int V_90 = 0 ;
if ( V_70 )
F_155 ( V_62 , stdout ) ;
if ( V_157 == V_159 ||
V_157 == V_160 ) {
V_90 = F_145 ( V_6 , V_62 ) ;
if ( V_90 < 0 )
goto V_154;
return 0 ;
}
V_23 = F_8 ( V_6 , V_62 -> V_147 . V_8 ,
V_62 -> V_147 . V_57 ) ;
if ( V_23 == NULL )
goto V_154;
if ( V_62 -> V_66 . V_67 & V_162 )
type = V_163 ;
else
type = V_88 ;
V_86 = F_151 ( V_6 , V_62 -> V_147 . V_87 ,
V_62 -> V_147 . V_149 , V_62 -> V_147 . V_156 ,
V_62 -> V_147 . V_8 , 0 , 0 , 0 , 0 , 0 , 0 ,
V_62 -> V_147 . V_78 ,
type , V_23 ) ;
if ( V_86 == NULL )
goto V_170;
F_152 ( V_23 , V_86 ) ;
F_10 ( V_23 ) ;
F_153 ( V_86 ) ;
return 0 ;
V_170:
F_10 ( V_23 ) ;
V_154:
F_70 ( L_45 ) ;
return 0 ;
}
static void F_25 ( struct V_6 * V_6 , struct V_23 * V_54 , bool V_5 )
{
if ( V_6 -> V_14 == V_54 )
V_6 -> V_14 = NULL ;
F_156 ( F_157 ( & V_54 -> V_171 ) == 0 ) ;
if ( V_5 )
F_14 ( & V_6 -> V_12 ) ;
F_59 ( & V_54 -> V_10 , & V_6 -> V_11 ) ;
F_6 ( & V_54 -> V_10 ) ;
F_158 ( & V_54 -> V_30 , & V_6 -> V_13 ) ;
if ( V_5 )
F_18 ( & V_6 -> V_12 ) ;
F_10 ( V_54 ) ;
}
void F_159 ( struct V_6 * V_6 , struct V_23 * V_54 )
{
return F_25 ( V_6 , V_54 , true ) ;
}
int F_160 ( struct V_6 * V_6 , union V_61 * V_62 ,
struct V_63 * V_64 )
{
struct V_23 * V_23 = F_62 ( V_6 ,
V_62 -> V_172 . V_8 ,
V_62 -> V_172 . V_57 ) ;
struct V_23 * V_37 = F_8 ( V_6 ,
V_62 -> V_172 . V_173 ,
V_62 -> V_172 . V_174 ) ;
int V_69 = 0 ;
if ( V_70 )
F_161 ( V_62 , stdout ) ;
if ( V_37 -> V_56 != ( T_1 ) V_62 -> V_172 . V_173 ) {
F_70 ( L_46 ,
V_37 -> V_56 , V_37 -> V_57 ) ;
F_159 ( V_6 , V_37 ) ;
F_10 ( V_37 ) ;
V_37 = F_8 ( V_6 , V_62 -> V_172 . V_173 ,
V_62 -> V_172 . V_174 ) ;
}
if ( V_23 != NULL ) {
F_159 ( V_6 , V_23 ) ;
F_10 ( V_23 ) ;
}
V_23 = F_8 ( V_6 , V_62 -> V_172 . V_8 ,
V_62 -> V_172 . V_57 ) ;
if ( V_23 == NULL || V_37 == NULL ||
F_162 ( V_23 , V_37 , V_64 -> time ) < 0 ) {
F_70 ( L_47 ) ;
V_69 = - 1 ;
}
F_10 ( V_23 ) ;
F_10 ( V_37 ) ;
return V_69 ;
}
int F_163 ( struct V_6 * V_6 , union V_61 * V_62 ,
struct V_63 * V_64 V_71 )
{
struct V_23 * V_23 = F_62 ( V_6 ,
V_62 -> V_172 . V_8 ,
V_62 -> V_172 . V_57 ) ;
if ( V_70 )
F_161 ( V_62 , stdout ) ;
if ( V_23 != NULL ) {
F_164 ( V_23 ) ;
F_10 ( V_23 ) ;
}
return 0 ;
}
int F_165 ( struct V_6 * V_6 , union V_61 * V_62 ,
struct V_63 * V_64 )
{
int V_90 ;
switch ( V_62 -> V_66 . type ) {
case V_175 :
V_90 = F_67 ( V_6 , V_62 , V_64 ) ; break;
case V_176 :
V_90 = F_154 ( V_6 , V_62 , V_64 ) ; break;
case V_177 :
V_90 = F_149 ( V_6 , V_62 , V_64 ) ; break;
case V_178 :
V_90 = F_160 ( V_6 , V_62 , V_64 ) ; break;
case V_179 :
V_90 = F_163 ( V_6 , V_62 , V_64 ) ; break;
case V_180 :
V_90 = F_71 ( V_6 , V_62 , V_64 ) ; break;
case V_181 :
V_90 = F_79 ( V_6 , V_62 ) ; break;
case V_182 :
V_90 = F_81 ( V_6 , V_62 ) ; break;
case V_183 :
V_90 = F_72 ( V_6 , V_62 , V_64 ) ; break;
case V_184 :
case V_185 :
V_90 = F_83 ( V_6 , V_62 ) ; break;
default:
V_90 = - 1 ;
break;
}
return V_90 ;
}
static bool F_166 ( struct V_186 * V_187 , T_10 * V_188 )
{
if ( V_187 -> V_79 && ! regexec ( V_188 , V_187 -> V_79 , 0 , NULL , 0 ) )
return 1 ;
return 0 ;
}
static void F_167 ( struct V_23 * V_23 ,
struct V_189 * V_190 ,
T_6 V_191 )
{
struct V_192 V_193 ;
memset ( & V_193 , 0 , sizeof( V_193 ) ) ;
F_168 ( V_23 , V_88 , V_191 , & V_193 ) ;
V_190 -> V_107 = V_191 ;
V_190 -> V_194 = V_193 . V_107 ;
V_190 -> V_187 = V_193 . V_187 ;
V_190 -> V_86 = V_193 . V_86 ;
}
static void F_169 ( struct V_23 * V_23 ,
T_9 V_77 , struct V_189 * V_190 , T_6 V_107 )
{
struct V_192 V_193 ;
memset ( & V_193 , 0 , sizeof( V_193 ) ) ;
F_170 ( V_23 , V_77 , V_163 , V_107 , & V_193 ) ;
if ( V_193 . V_86 == NULL ) {
F_170 ( V_23 , V_77 , V_88 , V_107 , & V_193 ) ;
}
V_190 -> V_107 = V_107 ;
V_190 -> V_194 = V_193 . V_107 ;
V_190 -> V_187 = V_193 . V_187 ;
V_190 -> V_86 = V_193 . V_86 ;
}
struct V_195 * F_171 ( struct V_63 * V_64 ,
struct V_192 * V_193 )
{
struct V_195 * V_196 = F_172 ( sizeof( * V_196 ) ) ;
if ( ! V_196 )
return NULL ;
F_167 ( V_193 -> V_23 , & V_196 -> V_197 , V_64 -> V_191 ) ;
F_169 ( V_193 -> V_23 , V_193 -> V_157 , & V_196 -> V_198 , V_64 -> V_107 ) ;
V_196 -> V_199 . V_200 = V_64 -> V_199 ;
return V_196 ;
}
static int F_173 ( struct V_23 * V_23 ,
struct V_186 * * V_37 ,
struct V_192 * V_201 ,
T_9 * V_157 ,
T_6 V_191 )
{
struct V_192 V_193 ;
V_193 . V_202 = 0 ;
V_193 . V_187 = NULL ;
if ( ! V_157 ) {
F_168 ( V_23 , V_88 ,
V_191 , & V_193 ) ;
} else {
if ( V_191 >= V_203 ) {
switch ( V_191 ) {
case V_204 :
* V_157 = V_205 ;
break;
case V_206 :
* V_157 = V_160 ;
break;
case V_207 :
* V_157 = V_208 ;
break;
default:
F_117 ( L_48
L_49 V_209 L_14 , ( V_210 ) V_191 ) ;
F_174 ( & V_211 ) ;
return 1 ;
}
return 0 ;
}
F_170 ( V_23 , * V_157 , V_88 ,
V_191 , & V_193 ) ;
}
if ( V_193 . V_187 != NULL ) {
if ( V_212 && ! * V_37 &&
F_166 ( V_193 . V_187 , & V_213 ) )
* V_37 = V_193 . V_187 ;
else if ( V_214 && V_201 &&
F_166 ( V_193 . V_187 , & V_215 ) ) {
* V_201 = V_193 ;
F_174 ( & V_211 ) ;
}
}
return F_175 ( & V_211 , V_193 . V_107 , V_193 . V_86 , V_193 . V_187 ) ;
}
struct V_216 * F_176 ( struct V_63 * V_64 ,
struct V_192 * V_193 )
{
unsigned int V_92 ;
const struct V_217 * V_218 = V_64 -> V_217 ;
struct V_216 * V_219 = calloc ( V_218 -> V_220 , sizeof( struct V_216 ) ) ;
if ( ! V_219 )
return NULL ;
for ( V_92 = 0 ; V_92 < V_218 -> V_220 ; V_92 ++ ) {
F_167 ( V_193 -> V_23 , & V_219 [ V_92 ] . V_221 , V_218 -> V_222 [ V_92 ] . V_221 ) ;
F_167 ( V_193 -> V_23 , & V_219 [ V_92 ] . V_223 , V_218 -> V_222 [ V_92 ] . V_223 ) ;
V_219 [ V_92 ] . V_169 = V_218 -> V_222 [ V_92 ] . V_169 ;
}
return V_219 ;
}
static int F_177 ( struct V_224 * V_225 , int V_220 )
{
int V_92 , V_226 , V_227 ;
unsigned char V_228 [ V_229 ] ;
memset ( V_228 , V_230 , sizeof( V_228 ) ) ;
F_156 ( V_231 > 255 ) ;
for ( V_92 = 0 ; V_92 < V_220 ; V_92 ++ ) {
int V_232 = F_178 ( V_225 [ V_92 ] . V_223 , V_233 ) % V_229 ;
if ( V_228 [ V_232 ] == V_230 ) {
V_228 [ V_232 ] = V_92 ;
} else if ( V_225 [ V_228 [ V_232 ] ] . V_223 == V_225 [ V_92 ] . V_223 ) {
bool V_234 = true ;
V_227 = 0 ;
for ( V_226 = V_228 [ V_232 ] ; V_226 < V_92 && V_92 + V_227 < V_220 ; V_226 ++ , V_227 ++ )
if ( V_225 [ V_226 ] . V_223 != V_225 [ V_92 + V_227 ] . V_223 ) {
V_234 = false ;
break;
}
if ( V_234 ) {
memmove ( V_225 + V_92 , V_225 + V_92 + V_227 ,
( V_220 - ( V_92 + V_227 ) ) * sizeof( * V_225 ) ) ;
V_220 -= V_227 ;
}
}
}
return V_220 ;
}
static int F_179 ( struct V_23 * V_23 ,
struct V_63 * V_64 ,
struct V_186 * * V_37 ,
struct V_192 * V_201 ,
int V_235 )
{
struct V_236 * V_237 = V_64 -> V_238 ;
int V_239 = V_165 ( V_235 , ( int ) V_237 -> V_220 ) ;
T_9 V_157 = V_208 ;
int V_92 , V_226 , V_69 ;
T_6 V_191 ;
for ( V_92 = 0 ; V_92 < V_239 ; V_92 ++ ) {
if ( V_237 -> V_240 [ V_92 ] == V_207 )
break;
}
if ( V_92 != V_239 ) {
struct V_217 * V_241 = V_64 -> V_217 ;
int V_242 = V_241 -> V_220 ;
int V_243 = V_92 + 1 + V_242 + 1 ;
if ( V_243 > V_244 + V_231 ) {
F_180 ( L_50 ) ;
return 0 ;
}
for ( V_226 = 0 ; V_226 < V_243 ; V_226 ++ ) {
if ( V_245 . V_246 == V_247 ) {
if ( V_226 < V_92 + 1 )
V_191 = V_237 -> V_240 [ V_226 ] ;
else if ( V_226 > V_92 + 1 )
V_191 = V_241 -> V_222 [ V_226 - V_92 - 2 ] . V_223 ;
else
V_191 = V_241 -> V_222 [ 0 ] . V_221 ;
} else {
if ( V_226 < V_242 )
V_191 = V_241 -> V_222 [ V_242 - V_226 - 1 ] . V_223 ;
else if ( V_226 > V_242 )
V_191 = V_237 -> V_240 [ V_92 + 1 - ( V_226 - V_242 ) ] ;
else
V_191 = V_241 -> V_222 [ 0 ] . V_221 ;
}
V_69 = F_173 ( V_23 , V_37 , V_201 , & V_157 , V_191 ) ;
if ( V_69 )
return ( V_69 < 0 ) ? V_69 : 0 ;
}
return 1 ;
}
return 0 ;
}
static int F_181 ( struct V_23 * V_23 ,
struct V_248 * V_249 ,
struct V_63 * V_64 ,
struct V_186 * * V_37 ,
struct V_192 * V_201 ,
int V_235 )
{
struct V_217 * V_250 = V_64 -> V_217 ;
struct V_236 * V_237 = V_64 -> V_238 ;
int V_239 = V_165 ( V_235 , ( int ) V_237 -> V_220 ) ;
T_9 V_157 = V_208 ;
int V_92 , V_226 , V_69 ;
int V_251 = - 1 ;
int V_252 = 0 ;
F_174 ( & V_211 ) ;
if ( F_182 ( V_249 ) ) {
V_69 = F_179 ( V_23 , V_64 , V_37 ,
V_201 , V_235 ) ;
if ( V_69 )
return ( V_69 < 0 ) ? V_69 : 0 ;
}
if ( V_237 -> V_220 < V_244 )
V_251 = F_183 ( V_23 , V_237 ) ;
if ( V_250 && V_245 . V_253 ) {
int V_220 = V_165 ( V_235 , ( int ) V_250 -> V_220 ) ;
struct V_224 V_254 [ V_220 ] ;
if ( V_250 -> V_220 > V_231 ) {
F_180 ( L_51 ) ;
goto V_255;
}
for ( V_92 = 0 ; V_92 < V_220 ; V_92 ++ ) {
if ( V_245 . V_246 == V_247 ) {
V_254 [ V_92 ] = V_250 -> V_222 [ V_92 ] ;
if ( V_92 == V_251 ||
V_237 -> V_240 [ V_252 ] >= V_203 )
V_252 ++ ;
else if ( V_254 [ V_92 ] . V_223 < V_237 -> V_240 [ V_252 ] &&
V_254 [ V_92 ] . V_223 >= V_237 -> V_240 [ V_252 ] - 8 )
V_252 ++ ;
} else
V_254 [ V_92 ] = V_250 -> V_222 [ V_250 -> V_220 - V_92 - 1 ] ;
}
V_220 = F_177 ( V_254 , V_220 ) ;
for ( V_92 = 0 ; V_92 < V_220 ; V_92 ++ ) {
V_69 = F_173 ( V_23 , V_37 , V_201 ,
NULL , V_254 [ V_92 ] . V_221 ) ;
if ( ! V_69 )
V_69 = F_173 ( V_23 , V_37 , V_201 ,
NULL , V_254 [ V_92 ] . V_223 ) ;
if ( V_69 == - V_256 )
break;
if ( V_69 )
return V_69 ;
}
V_239 -= V_220 ;
}
V_255:
if ( V_237 -> V_220 > V_244 && ( int ) V_237 -> V_220 > V_235 ) {
F_180 ( L_50 ) ;
return 0 ;
}
for ( V_92 = V_252 ; V_92 < V_239 ; V_92 ++ ) {
T_6 V_191 ;
if ( V_245 . V_246 == V_247 )
V_226 = V_92 ;
else
V_226 = V_237 -> V_220 - V_92 - 1 ;
#ifdef F_184
if ( V_226 == V_251 )
continue;
#endif
V_191 = V_237 -> V_240 [ V_226 ] ;
V_69 = F_173 ( V_23 , V_37 , V_201 , & V_157 , V_191 ) ;
if ( V_69 )
return ( V_69 < 0 ) ? V_69 : 0 ;
}
return 0 ;
}
static int F_185 ( struct F_185 * V_257 , void * V_144 )
{
struct V_211 * V_258 = V_144 ;
return F_175 ( V_258 , V_257 -> V_191 ,
V_257 -> V_86 , V_257 -> V_187 ) ;
}
int F_186 ( struct V_23 * V_23 ,
struct V_248 * V_249 ,
struct V_63 * V_64 ,
struct V_186 * * V_37 ,
struct V_192 * V_201 ,
int V_235 )
{
int V_90 = F_181 ( V_23 , V_249 ,
V_64 , V_37 ,
V_201 , V_235 ) ;
if ( V_90 )
return V_90 ;
if ( ! ( ( V_249 -> V_259 . V_260 & V_261 ) &&
( V_249 -> V_259 . V_260 & V_262 ) ) )
return 0 ;
if ( ( ! V_64 -> V_263 . V_264 ) ||
( ! V_64 -> V_265 . V_53 ) )
return 0 ;
return F_187 ( F_185 , & V_211 ,
V_23 , V_64 , V_235 ) ;
}
int F_188 ( struct V_6 * V_6 ,
int (* F_189)( struct V_23 * V_23 , void * V_36 ) ,
void * V_266 )
{
struct V_10 * V_31 ;
struct V_23 * V_23 ;
int V_267 = 0 ;
for ( V_31 = F_22 ( & V_6 -> V_11 ) ; V_31 ; V_31 = F_24 ( V_31 ) ) {
V_23 = F_23 ( V_31 , struct V_23 , V_10 ) ;
V_267 = F_189 ( V_23 , V_266 ) ;
if ( V_267 != 0 )
return V_267 ;
}
F_143 (thread, &machine->dead_threads, node) {
V_267 = F_189 ( V_23 , V_266 ) ;
if ( V_267 != 0 )
return V_267 ;
}
return V_267 ;
}
int F_190 ( struct V_33 * V_33 ,
int (* F_189)( struct V_23 * V_23 , void * V_36 ) ,
void * V_266 )
{
struct V_10 * V_31 ;
int V_267 = 0 ;
V_267 = F_188 ( & V_33 -> V_34 , F_189 , V_266 ) ;
if ( V_267 != 0 )
return V_267 ;
for ( V_31 = F_22 ( & V_33 -> V_35 ) ; V_31 ; V_31 = F_24 ( V_31 ) ) {
struct V_6 * V_6 = F_23 ( V_31 , struct V_6 , V_10 ) ;
V_267 = F_188 ( V_6 , F_189 , V_266 ) ;
if ( V_267 != 0 )
return V_267 ;
}
return V_267 ;
}
int F_191 ( struct V_6 * V_6 , struct V_268 * V_269 ,
struct V_270 * V_270 , struct V_271 * V_11 ,
T_11 V_50 , bool V_272 ,
unsigned int V_273 )
{
if ( F_192 ( V_270 ) )
return F_193 ( V_269 , V_11 , V_50 , V_6 , V_272 , V_273 ) ;
else if ( F_194 ( V_270 ) )
return F_195 ( V_269 , V_50 , V_6 , V_272 , V_273 ) ;
return 0 ;
}
T_1 F_196 ( struct V_6 * V_6 , int V_274 )
{
if ( V_274 < 0 || V_274 >= V_275 || ! V_6 -> V_25 )
return - 1 ;
return V_6 -> V_25 [ V_274 ] ;
}
int F_197 ( struct V_6 * V_6 , int V_274 , T_1 V_8 ,
T_1 V_57 )
{
struct V_23 * V_23 ;
if ( V_274 < 0 )
return - V_256 ;
if ( ! V_6 -> V_25 ) {
int V_92 ;
V_6 -> V_25 = calloc ( V_275 , sizeof( T_1 ) ) ;
if ( ! V_6 -> V_25 )
return - V_21 ;
for ( V_92 = 0 ; V_92 < V_275 ; V_92 ++ )
V_6 -> V_25 [ V_92 ] = - 1 ;
}
if ( V_274 >= V_275 ) {
F_43 ( L_52 , V_274 ) ;
F_43 ( L_53 ) ;
return - V_256 ;
}
V_6 -> V_25 [ V_274 ] = V_57 ;
V_23 = F_8 ( V_6 , V_8 , V_57 ) ;
if ( ! V_23 )
return - V_21 ;
V_23 -> V_274 = V_274 ;
F_10 ( V_23 ) ;
return 0 ;
}
int F_198 ( struct V_6 * V_6 )
{
struct V_86 * V_86 = F_97 ( V_6 ) ;
int V_69 = 0 ;
V_6 -> V_20 = 1ULL << 63 ;
if ( V_86 ) {
V_69 = F_199 ( V_86 , V_6 -> V_17 ) ;
if ( V_86 -> V_87 )
V_6 -> V_20 = V_86 -> V_87 ;
}
return V_69 ;
}
struct V_27 * F_147 ( struct V_6 * V_6 , const char * V_78 )
{
return F_200 ( & V_6 -> V_1 , V_78 ) ;
}
char * F_201 ( void * V_276 , unsigned long long * V_277 , char * * V_278 )
{
struct V_6 * V_6 = V_276 ;
struct V_86 * V_86 ;
struct V_186 * V_187 = F_202 ( & V_6 -> V_9 , V_88 , * V_277 , & V_86 , NULL ) ;
if ( V_187 == NULL )
return NULL ;
* V_278 = F_203 ( V_86 ) ? ( char * ) V_86 -> V_27 -> V_279 : NULL ;
* V_277 = V_86 -> V_114 ( V_86 , V_187 -> V_87 ) ;
return V_187 -> V_79 ;
}
