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
V_6 -> V_13 = 0 ;
F_2 ( & V_6 -> V_14 ) ;
V_6 -> V_15 = NULL ;
V_6 -> V_16 = NULL ;
V_6 -> V_17 = NULL ;
V_6 -> V_8 = V_8 ;
V_6 -> V_18 = NULL ;
V_6 -> V_19 = 0 ;
V_6 -> V_20 = false ;
V_6 -> V_21 = false ;
V_6 -> V_22 = 0 ;
memset ( V_6 -> V_23 , 0 , sizeof( V_6 -> V_23 ) ) ;
V_6 -> V_7 = F_7 ( V_7 ) ;
if ( V_6 -> V_7 == NULL )
return - V_24 ;
if ( V_8 != V_25 ) {
struct V_26 * V_26 = F_8 ( V_6 , - 1 ,
V_8 ) ;
char V_27 [ 64 ] ;
if ( V_26 == NULL )
return - V_24 ;
snprintf ( V_27 , sizeof( V_27 ) , L_1 , V_8 ) ;
F_9 ( V_26 , V_27 , 0 ) ;
F_10 ( V_26 ) ;
}
V_6 -> V_28 = NULL ;
return 0 ;
}
struct V_6 * F_11 ( void )
{
struct V_6 * V_6 = malloc ( sizeof( * V_6 ) ) ;
if ( V_6 != NULL ) {
F_4 ( V_6 , L_2 , V_25 ) ;
if ( F_12 ( V_6 ) < 0 )
goto V_29;
}
return V_6 ;
V_29:
free ( V_6 ) ;
return NULL ;
}
static void F_13 ( struct V_1 * V_1 )
{
struct V_30 * V_31 , * V_32 ;
F_14 ( & V_1 -> V_5 ) ;
F_15 (pos, n, &dsos->head, node) {
F_6 ( & V_31 -> V_10 ) ;
V_31 -> V_3 = NULL ;
F_16 ( & V_31 -> V_33 ) ;
F_17 ( V_31 ) ;
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
struct V_10 * V_34 ;
F_14 ( & V_6 -> V_12 ) ;
V_34 = F_22 ( & V_6 -> V_11 ) ;
while ( V_34 ) {
struct V_26 * V_35 = F_23 ( V_34 , struct V_26 , V_10 ) ;
V_34 = F_24 ( V_34 ) ;
F_25 ( V_6 , V_35 , false ) ;
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
F_30 ( & V_6 -> V_28 ) ;
F_20 ( & V_6 -> V_12 ) ;
}
void F_31 ( struct V_6 * V_6 )
{
F_26 ( V_6 ) ;
free ( V_6 ) ;
}
void F_32 ( struct V_36 * V_36 )
{
F_4 ( & V_36 -> V_37 , L_2 , V_25 ) ;
V_36 -> V_38 = V_4 ;
V_36 -> V_18 = NULL ;
}
void F_33 ( struct V_36 * V_36 )
{
F_26 ( & V_36 -> V_37 ) ;
}
struct V_6 * F_34 ( struct V_36 * V_36 , T_1 V_8 ,
const char * V_7 )
{
struct V_10 * * V_39 = & V_36 -> V_38 . V_10 ;
struct V_10 * V_40 = NULL ;
struct V_6 * V_31 , * V_6 = malloc ( sizeof( * V_6 ) ) ;
if ( V_6 == NULL )
return NULL ;
if ( F_4 ( V_6 , V_7 , V_8 ) != 0 ) {
free ( V_6 ) ;
return NULL ;
}
V_6 -> V_18 = V_36 -> V_18 ;
while ( * V_39 != NULL ) {
V_40 = * V_39 ;
V_31 = F_23 ( V_40 , struct V_6 , V_10 ) ;
if ( V_8 < V_31 -> V_8 )
V_39 = & ( * V_39 ) -> V_41 ;
else
V_39 = & ( * V_39 ) -> V_42 ;
}
F_35 ( & V_6 -> V_10 , V_40 , V_39 ) ;
F_36 ( & V_6 -> V_10 , & V_36 -> V_38 ) ;
return V_6 ;
}
void F_37 ( struct V_36 * V_36 ,
T_2 V_18 )
{
struct V_10 * V_34 ;
V_36 -> V_18 = V_18 ;
V_36 -> V_37 . V_18 = V_18 ;
for ( V_34 = F_22 ( & V_36 -> V_38 ) ; V_34 ; V_34 = F_24 ( V_34 ) ) {
struct V_6 * V_6 = F_23 ( V_34 , struct V_6 , V_10 ) ;
V_6 -> V_18 = V_18 ;
}
}
void F_38 ( struct V_36 * V_36 , bool V_21 )
{
struct V_10 * V_34 ;
V_36 -> V_37 . V_21 = V_21 ;
for ( V_34 = F_22 ( & V_36 -> V_38 ) ; V_34 ; V_34 = F_24 ( V_34 ) ) {
struct V_6 * V_6 = F_23 ( V_34 , struct V_6 , V_10 ) ;
V_6 -> V_21 = V_21 ;
}
}
struct V_6 * F_39 ( struct V_36 * V_36 , T_1 V_8 )
{
struct V_10 * * V_39 = & V_36 -> V_38 . V_10 ;
struct V_10 * V_40 = NULL ;
struct V_6 * V_6 ;
struct V_6 * V_43 = NULL ;
if ( V_8 == V_25 )
return & V_36 -> V_37 ;
while ( * V_39 != NULL ) {
V_40 = * V_39 ;
V_6 = F_23 ( V_40 , struct V_6 , V_10 ) ;
if ( V_8 < V_6 -> V_8 )
V_39 = & ( * V_39 ) -> V_41 ;
else if ( V_8 > V_6 -> V_8 )
V_39 = & ( * V_39 ) -> V_42 ;
else
return V_6 ;
if ( ! V_6 -> V_8 )
V_43 = V_6 ;
}
return V_43 ;
}
struct V_6 * F_40 ( struct V_36 * V_36 , T_1 V_8 )
{
char V_44 [ V_45 ] ;
const char * V_7 = L_2 ;
struct V_6 * V_6 = F_39 ( V_36 , V_8 ) ;
if ( V_6 && ( V_6 -> V_8 == V_8 ) )
goto V_46;
if ( ( V_8 != V_25 ) &&
( V_8 != V_47 ) &&
( V_48 . V_49 ) ) {
sprintf ( V_44 , L_3 , V_48 . V_49 , V_8 ) ;
if ( F_41 ( V_44 , V_50 ) ) {
static struct V_51 * V_52 ;
if ( ! V_52 )
V_52 = F_42 ( NULL , NULL ) ;
if ( ! F_43 ( V_52 , V_44 ) ) {
F_44 ( L_4 , V_44 ) ;
F_45 ( V_52 , V_44 ) ;
}
V_6 = NULL ;
goto V_46;
}
V_7 = V_44 ;
}
V_6 = F_34 ( V_36 , V_8 , V_7 ) ;
V_46:
return V_6 ;
}
void F_46 ( struct V_36 * V_36 ,
T_3 V_53 , void * V_54 )
{
struct V_10 * V_34 ;
for ( V_34 = F_22 ( & V_36 -> V_38 ) ; V_34 ; V_34 = F_24 ( V_34 ) ) {
struct V_6 * V_31 = F_23 ( V_34 , struct V_6 , V_10 ) ;
V_53 ( V_31 , V_54 ) ;
}
}
char * F_47 ( struct V_6 * V_6 , char * V_55 , T_4 V_56 )
{
if ( F_48 ( V_6 ) )
snprintf ( V_55 , V_56 , L_5 , L_6 ) ;
else if ( F_49 ( V_6 ) )
snprintf ( V_55 , V_56 , L_5 , L_7 ) ;
else {
snprintf ( V_55 , V_56 , L_8 , L_7 ,
V_6 -> V_8 ) ;
}
return V_55 ;
}
void F_50 ( struct V_36 * V_36 , T_5 V_19 )
{
struct V_10 * V_33 ;
struct V_6 * V_6 ;
V_36 -> V_37 . V_19 = V_19 ;
for ( V_33 = F_22 ( & V_36 -> V_38 ) ; V_33 ; V_33 = F_24 ( V_33 ) ) {
V_6 = F_23 ( V_33 , struct V_6 , V_10 ) ;
V_6 -> V_19 = V_19 ;
}
return;
}
static void F_51 ( struct V_6 * V_6 ,
struct V_26 * V_57 , T_1 V_8 )
{
struct V_26 * V_58 ;
if ( V_8 == V_57 -> V_59 || V_8 == - 1 || V_57 -> V_59 != - 1 )
return;
V_57 -> V_59 = V_8 ;
if ( V_57 -> V_59 == V_57 -> V_60 )
return;
V_58 = F_52 ( V_6 , V_57 -> V_59 , V_57 -> V_59 ) ;
if ( ! V_58 )
goto V_61;
if ( ! V_58 -> V_62 )
V_58 -> V_62 = F_53 ( V_6 ) ;
if ( ! V_58 -> V_62 )
goto V_61;
if ( V_57 -> V_62 == V_58 -> V_62 )
return;
if ( V_57 -> V_62 ) {
if ( ! F_54 ( V_57 -> V_62 ) )
F_44 ( L_9 ,
V_57 -> V_59 , V_57 -> V_60 ) ;
F_55 ( V_57 -> V_62 ) ;
}
V_57 -> V_62 = F_56 ( V_58 -> V_62 ) ;
V_63:
F_10 ( V_58 ) ;
return;
V_61:
F_44 ( L_10 , V_57 -> V_59 , V_57 -> V_60 ) ;
goto V_63;
}
static struct V_26 * F_57 ( struct V_6 * V_6 ,
T_1 V_8 , T_1 V_60 ,
bool V_64 )
{
struct V_10 * * V_39 = & V_6 -> V_11 . V_10 ;
struct V_10 * V_40 = NULL ;
struct V_26 * V_57 ;
V_57 = V_6 -> V_15 ;
if ( V_57 != NULL ) {
if ( V_57 -> V_60 == V_60 ) {
F_51 ( V_6 , V_57 , V_8 ) ;
return F_58 ( V_57 ) ;
}
V_6 -> V_15 = NULL ;
}
while ( * V_39 != NULL ) {
V_40 = * V_39 ;
V_57 = F_23 ( V_40 , struct V_26 , V_10 ) ;
if ( V_57 -> V_60 == V_60 ) {
V_6 -> V_15 = V_57 ;
F_51 ( V_6 , V_57 , V_8 ) ;
return F_58 ( V_57 ) ;
}
if ( V_60 < V_57 -> V_60 )
V_39 = & ( * V_39 ) -> V_41 ;
else
V_39 = & ( * V_39 ) -> V_42 ;
}
if ( ! V_64 )
return NULL ;
V_57 = F_59 ( V_8 , V_60 ) ;
if ( V_57 != NULL ) {
F_35 ( & V_57 -> V_10 , V_40 , V_39 ) ;
F_36 ( & V_57 -> V_10 , & V_6 -> V_11 ) ;
if ( F_60 ( V_57 , V_6 ) ) {
F_61 ( & V_57 -> V_10 , & V_6 -> V_11 ) ;
F_6 ( & V_57 -> V_10 ) ;
F_10 ( V_57 ) ;
return NULL ;
}
F_58 ( V_57 ) ;
V_6 -> V_15 = V_57 ;
++ V_6 -> V_13 ;
}
return V_57 ;
}
struct V_26 * F_52 ( struct V_6 * V_6 , T_1 V_8 , T_1 V_60 )
{
return F_57 ( V_6 , V_8 , V_60 , true ) ;
}
struct V_26 * F_8 ( struct V_6 * V_6 , T_1 V_8 ,
T_1 V_60 )
{
struct V_26 * V_57 ;
F_14 ( & V_6 -> V_12 ) ;
V_57 = F_52 ( V_6 , V_8 , V_60 ) ;
F_18 ( & V_6 -> V_12 ) ;
return V_57 ;
}
struct V_26 * F_62 ( struct V_6 * V_6 , T_1 V_8 ,
T_1 V_60 )
{
struct V_26 * V_57 ;
F_63 ( & V_6 -> V_12 ) ;
V_57 = F_57 ( V_6 , V_8 , V_60 , false ) ;
F_18 ( & V_6 -> V_12 ) ;
return V_57 ;
}
struct V_27 * F_64 ( struct V_6 * V_6 ,
struct V_26 * V_26 )
{
if ( V_6 -> V_21 )
return F_65 ( V_26 ) ;
else
return F_66 ( V_26 ) ;
}
int F_67 ( struct V_6 * V_6 , union V_65 * V_66 ,
struct V_67 * V_68 )
{
struct V_26 * V_26 = F_8 ( V_6 ,
V_66 -> V_27 . V_8 ,
V_66 -> V_27 . V_60 ) ;
bool V_69 = V_66 -> V_70 . V_71 & V_72 ;
int V_73 = 0 ;
if ( V_69 )
V_6 -> V_21 = true ;
if ( V_74 )
F_68 ( V_66 , stdout ) ;
if ( V_26 == NULL ||
F_69 ( V_26 , V_66 -> V_27 . V_27 , V_68 -> time , V_69 ) ) {
F_70 ( L_11 ) ;
V_73 = - 1 ;
}
F_10 ( V_26 ) ;
return V_73 ;
}
int F_71 ( struct V_6 * V_6 V_75 ,
union V_65 * V_66 , struct V_67 * V_68 V_75 )
{
F_70 ( L_12 V_76 L_13 V_76 L_14 ,
V_66 -> V_77 . V_78 , V_66 -> V_77 . V_77 ) ;
return 0 ;
}
int F_72 ( struct V_6 * V_6 V_75 ,
union V_65 * V_66 , struct V_67 * V_68 )
{
F_70 ( L_12 V_76 L_15 V_76 L_14 ,
V_68 -> V_78 , V_66 -> V_79 . V_77 ) ;
return 0 ;
}
static struct V_30 * F_73 ( struct V_6 * V_6 ,
struct V_80 * V_81 ,
const char * V_82 )
{
struct V_30 * V_30 ;
F_14 ( & V_6 -> V_1 . V_5 ) ;
V_30 = F_74 ( & V_6 -> V_1 , V_81 -> V_83 , true ) ;
if ( ! V_30 ) {
V_30 = F_75 ( & V_6 -> V_1 , V_81 -> V_83 ) ;
if ( V_30 == NULL )
goto V_84;
if ( F_48 ( V_6 ) )
V_30 -> V_85 = V_86 ;
else
V_30 -> V_85 = V_87 ;
if ( V_81 -> V_88 && V_81 -> V_89 )
V_30 -> V_85 ++ ;
F_76 ( V_30 , F_7 ( V_81 -> V_83 ) , true ) ;
F_77 ( V_30 , F_7 ( V_82 ) , true ) ;
}
F_78 ( V_30 ) ;
V_84:
F_18 ( & V_6 -> V_1 . V_5 ) ;
return V_30 ;
}
int F_79 ( struct V_6 * V_6 V_75 ,
union V_65 * V_66 )
{
if ( V_74 )
F_80 ( V_66 , stdout ) ;
return 0 ;
}
int F_81 ( struct V_6 * V_6 V_75 ,
union V_65 * V_66 )
{
if ( V_74 )
F_82 ( V_66 , stdout ) ;
return 0 ;
}
int F_83 ( struct V_6 * V_6 V_75 ,
union V_65 * V_66 )
{
if ( V_74 )
F_84 ( V_66 , stdout ) ;
return 0 ;
}
static void F_85 ( struct V_30 * V_30 , const char * V_82 )
{
const char * V_90 ;
if ( ! V_82 || ! V_30 || ! V_30 -> V_91 )
return;
if ( V_30 -> V_91 [ 0 ] != '[' )
return;
if ( ! strchr ( V_82 , '/' ) )
return;
V_90 = F_7 ( V_82 ) ;
if ( ! V_90 )
return;
F_77 ( V_30 , V_90 , true ) ;
}
struct V_92 * F_86 ( struct V_6 * V_6 , T_6 V_93 ,
const char * V_82 )
{
struct V_92 * V_92 = NULL ;
struct V_30 * V_30 = NULL ;
struct V_80 V_81 ;
if ( F_87 ( & V_81 , V_82 ) )
return NULL ;
V_92 = F_88 ( & V_6 -> V_9 , V_94 ,
V_81 . V_83 ) ;
if ( V_92 ) {
F_85 ( V_92 -> V_30 , V_82 ) ;
goto V_46;
}
V_30 = F_73 ( V_6 , & V_81 , V_82 ) ;
if ( V_30 == NULL )
goto V_46;
V_92 = F_89 ( V_93 , V_30 , V_94 ) ;
if ( V_92 == NULL )
goto V_46;
F_90 ( & V_6 -> V_9 , V_92 ) ;
F_91 ( V_92 ) ;
V_46:
F_17 ( V_30 ) ;
free ( V_81 . V_83 ) ;
return V_92 ;
}
T_4 F_92 ( struct V_36 * V_36 , T_7 * V_95 )
{
struct V_10 * V_34 ;
T_4 V_96 = F_93 ( & V_36 -> V_37 . V_1 . V_2 , V_95 ) ;
for ( V_34 = F_22 ( & V_36 -> V_38 ) ; V_34 ; V_34 = F_24 ( V_34 ) ) {
struct V_6 * V_31 = F_23 ( V_34 , struct V_6 , V_10 ) ;
V_96 += F_93 ( & V_31 -> V_1 . V_2 , V_95 ) ;
}
return V_96 ;
}
T_4 F_94 ( struct V_6 * V_81 , T_7 * V_95 ,
bool (F_95)( struct V_30 * V_30 , int V_97 ) , int V_97 )
{
return F_96 ( & V_81 -> V_1 . V_2 , V_95 , F_95 , V_97 ) ;
}
T_4 F_97 ( struct V_36 * V_36 , T_7 * V_95 ,
bool (F_95)( struct V_30 * V_30 , int V_97 ) , int V_97 )
{
struct V_10 * V_34 ;
T_4 V_96 = F_94 ( & V_36 -> V_37 , V_95 , F_95 , V_97 ) ;
for ( V_34 = F_22 ( & V_36 -> V_38 ) ; V_34 ; V_34 = F_24 ( V_34 ) ) {
struct V_6 * V_31 = F_23 ( V_34 , struct V_6 , V_10 ) ;
V_96 += F_94 ( V_31 , V_95 , F_95 , V_97 ) ;
}
return V_96 ;
}
T_4 F_98 ( struct V_6 * V_6 , T_7 * V_95 )
{
int V_98 ;
T_4 V_99 = 0 ;
struct V_30 * V_100 = F_99 ( V_6 ) -> V_30 ;
if ( V_100 -> V_101 ) {
char V_82 [ V_45 ] ;
if ( F_100 ( V_100 , V_82 , sizeof( V_82 ) ) )
V_99 += fprintf ( V_95 , L_16 , V_82 ) ;
}
for ( V_98 = 0 ; V_98 < V_102 ; ++ V_98 )
V_99 += fprintf ( V_95 , L_17 ,
V_98 + V_100 -> V_101 , V_103 [ V_98 ] ) ;
return V_99 ;
}
T_4 F_101 ( struct V_6 * V_6 , T_7 * V_95 )
{
T_4 V_96 ;
struct V_10 * V_34 ;
F_63 ( & V_6 -> V_12 ) ;
V_96 = fprintf ( V_95 , L_18 , V_6 -> V_13 ) ;
for ( V_34 = F_22 ( & V_6 -> V_11 ) ; V_34 ; V_34 = F_24 ( V_34 ) ) {
struct V_26 * V_31 = F_23 ( V_34 , struct V_26 , V_10 ) ;
V_96 += F_102 ( V_31 , V_95 ) ;
}
F_18 ( & V_6 -> V_12 ) ;
return V_96 ;
}
static struct V_30 * F_103 ( struct V_6 * V_6 )
{
const char * V_104 = NULL ;
struct V_30 * V_105 ;
if ( F_48 ( V_6 ) ) {
V_104 = V_48 . V_104 ;
if ( ! V_104 )
V_104 = V_106 ;
V_105 = F_104 ( V_6 , V_104 ,
L_19 , V_107 ) ;
} else {
char V_55 [ V_45 ] ;
if ( F_49 ( V_6 ) )
V_104 = V_48 . V_108 ;
if ( ! V_104 )
V_104 = F_47 ( V_6 , V_55 ,
sizeof( V_55 ) ) ;
V_105 = F_104 ( V_6 , V_104 ,
L_20 ,
V_109 ) ;
}
if ( V_105 != NULL && ( ! V_105 -> V_101 ) )
F_105 ( V_105 , V_6 ) ;
return V_105 ;
}
static void F_106 ( struct V_6 * V_6 , char * V_110 ,
T_4 V_111 )
{
if ( F_49 ( V_6 ) )
F_107 ( V_110 , V_111 , L_21 , V_48 . V_112 ) ;
else
F_107 ( V_110 , V_111 , L_22 , V_6 -> V_7 ) ;
}
static T_6 F_108 ( struct V_6 * V_6 ,
const char * * V_113 )
{
char V_82 [ V_45 ] ;
int V_98 ;
const char * V_83 ;
T_6 V_114 = 0 ;
F_106 ( V_6 , V_82 , V_45 ) ;
if ( F_109 ( V_82 , L_23 ) )
return 0 ;
for ( V_98 = 0 ; ( V_83 = V_115 [ V_98 ] ) != NULL ; V_98 ++ ) {
V_114 = F_110 ( V_82 , V_83 ) ;
if ( V_114 )
break;
}
if ( V_113 )
* V_113 = V_83 ;
return V_114 ;
}
int F_111 ( struct V_6 * V_6 , struct V_30 * V_105 )
{
enum V_116 type ;
T_6 V_93 = F_108 ( V_6 , NULL ) ;
F_27 ( V_6 ) ;
for ( type = 0 ; type < V_117 ; ++ type ) {
struct V_118 * V_118 ;
struct V_92 * V_92 ;
V_6 -> V_23 [ type ] = F_89 ( V_93 , V_105 , type ) ;
if ( V_6 -> V_23 [ type ] == NULL )
return - 1 ;
V_6 -> V_23 [ type ] -> V_119 =
V_6 -> V_23 [ type ] -> V_120 =
V_121 ;
V_92 = F_112 ( V_6 , type ) ;
V_118 = F_113 ( V_92 ) ;
if ( ! V_118 )
return - 1 ;
V_118 -> V_9 = & V_6 -> V_9 ;
F_90 ( & V_6 -> V_9 , V_92 ) ;
}
return 0 ;
}
void F_27 ( struct V_6 * V_6 )
{
enum V_116 type ;
for ( type = 0 ; type < V_117 ; ++ type ) {
struct V_118 * V_118 ;
struct V_92 * V_92 = F_112 ( V_6 , type ) ;
if ( V_92 == NULL )
continue;
V_118 = F_113 ( V_92 ) ;
F_114 ( & V_6 -> V_9 , V_92 ) ;
if ( V_118 && V_118 -> V_122 ) {
if ( type == V_94 ) {
F_30 ( ( char * * ) & V_118 -> V_122 -> V_83 ) ;
F_30 ( & V_118 -> V_122 ) ;
} else
V_118 -> V_122 = NULL ;
}
F_91 ( V_6 -> V_23 [ type ] ) ;
V_6 -> V_23 [ type ] = NULL ;
}
}
int F_115 ( struct V_36 * V_36 )
{
int V_96 = 0 ;
struct V_123 * * V_124 = NULL ;
int V_98 , V_125 = 0 ;
char V_44 [ V_45 ] ;
T_1 V_8 ;
char * V_126 ;
if ( V_48 . V_108 ||
V_48 . V_127 ||
V_48 . V_112 ) {
F_116 ( V_36 , V_47 ) ;
}
if ( V_48 . V_49 ) {
V_125 = F_117 ( V_48 . V_49 , & V_124 , NULL , NULL ) ;
if ( V_125 <= 0 )
return - V_128 ;
for ( V_98 = 0 ; V_98 < V_125 ; V_98 ++ ) {
if ( ! isdigit ( V_124 [ V_98 ] -> V_129 [ 0 ] ) ) {
continue;
}
V_8 = ( T_1 ) strtol ( V_124 [ V_98 ] -> V_129 , & V_126 , 10 ) ;
if ( ( * V_126 != '\0' ) ||
( V_126 == V_124 [ V_98 ] -> V_129 ) ||
( V_130 == V_131 ) ) {
F_118 ( L_24 ,
V_124 [ V_98 ] -> V_129 ) ;
continue;
}
sprintf ( V_44 , L_25 ,
V_48 . V_49 ,
V_124 [ V_98 ] -> V_129 ) ;
V_96 = F_41 ( V_44 , V_50 ) ;
if ( V_96 ) {
F_118 ( L_4 , V_44 ) ;
goto V_132;
}
F_116 ( V_36 , V_8 ) ;
}
V_132:
free ( V_124 ) ;
}
return V_96 ;
}
void F_119 ( struct V_36 * V_36 )
{
struct V_10 * V_133 = F_22 ( & V_36 -> V_38 ) ;
F_27 ( & V_36 -> V_37 ) ;
while ( V_133 ) {
struct V_6 * V_31 = F_23 ( V_133 , struct V_6 , V_10 ) ;
V_133 = F_24 ( & V_31 -> V_10 ) ;
F_120 ( & V_31 -> V_10 , & V_36 -> V_38 ) ;
F_31 ( V_31 ) ;
}
}
int F_116 ( struct V_36 * V_36 , T_1 V_8 )
{
struct V_6 * V_6 = F_40 ( V_36 , V_8 ) ;
if ( V_6 == NULL )
return - 1 ;
return F_12 ( V_6 ) ;
}
int F_121 ( struct V_6 * V_6 , const char * V_82 ,
enum V_116 type , bool V_134 , T_2 V_135 )
{
struct V_92 * V_92 = F_99 ( V_6 ) ;
int V_96 = F_122 ( V_92 -> V_30 , V_82 , V_92 , V_134 , V_135 ) ;
if ( V_96 > 0 ) {
F_123 ( V_92 -> V_30 , type ) ;
F_124 ( & V_6 -> V_9 , type ) ;
}
return V_96 ;
}
int F_125 ( struct V_6 * V_6 , const char * V_82 ,
enum V_116 type , T_2 V_135 )
{
return F_121 ( V_6 , V_82 , type , false , V_135 ) ;
}
int F_126 ( struct V_6 * V_6 , enum V_116 type ,
T_2 V_135 )
{
struct V_92 * V_92 = F_99 ( V_6 ) ;
int V_96 = F_127 ( V_92 -> V_30 , V_92 , V_135 ) ;
if ( V_96 > 0 )
F_123 ( V_92 -> V_30 , type ) ;
return V_96 ;
}
static void F_128 ( struct V_136 * V_62 )
{
int V_98 ;
for ( V_98 = 0 ; V_98 < V_117 ; ++ V_98 )
F_124 ( V_62 , V_98 ) ;
}
static char * F_129 ( const char * V_7 )
{
char V_137 [ V_45 ] ;
T_7 * V_138 ;
char * V_83 , * V_139 ;
const char * V_140 = L_26 ;
sprintf ( V_137 , L_27 , V_7 ) ;
V_138 = fopen ( V_137 , L_28 ) ;
if ( ! V_138 )
return NULL ;
V_137 [ 0 ] = '\0' ;
V_139 = fgets ( V_137 , sizeof( V_137 ) , V_138 ) ;
fclose ( V_138 ) ;
V_83 = strstr ( V_137 , V_140 ) ;
if ( ! V_83 )
return NULL ;
V_83 += strlen ( V_140 ) ;
V_139 = strchr ( V_83 , ' ' ) ;
if ( V_139 )
* V_139 = '\0' ;
return F_7 ( V_83 ) ;
}
static bool F_130 ( struct V_30 * V_30 )
{
return V_30 -> V_85 == V_86 ||
V_30 -> V_85 == V_87 ;
}
static int F_131 ( struct V_136 * V_62 , const char * V_44 ,
struct V_80 * V_81 )
{
struct V_92 * V_92 ;
char * V_91 ;
V_92 = F_88 ( V_62 , V_94 , V_81 -> V_83 ) ;
if ( V_92 == NULL )
return 0 ;
V_91 = F_7 ( V_44 ) ;
if ( V_91 == NULL )
return - V_24 ;
F_77 ( V_92 -> V_30 , V_91 , true ) ;
F_132 ( V_92 -> V_30 , L_2 ) ;
if ( V_81 -> V_89 && F_130 ( V_92 -> V_30 ) )
V_92 -> V_30 -> V_85 ++ ;
return 0 ;
}
static int F_133 ( struct V_136 * V_62 ,
const char * V_141 , int V_142 )
{
struct V_123 * V_143 ;
T_8 * V_144 = F_134 ( V_141 ) ;
int V_96 = 0 ;
if ( ! V_144 ) {
F_118 ( L_29 , V_145 , V_141 ) ;
return - 1 ;
}
while ( ( V_143 = F_135 ( V_144 ) ) != NULL ) {
char V_44 [ V_45 ] ;
struct V_146 V_147 ;
snprintf ( V_44 , sizeof( V_44 ) , L_30 , V_141 , V_143 -> V_129 ) ;
if ( V_146 ( V_44 , & V_147 ) )
continue;
if ( F_136 ( V_147 . V_148 ) ) {
if ( ! strcmp ( V_143 -> V_129 , L_31 ) ||
! strcmp ( V_143 -> V_129 , L_32 ) )
continue;
if ( V_142 == 0 ) {
if ( ! strcmp ( V_143 -> V_129 , L_33 ) ||
! strcmp ( V_143 -> V_129 , L_34 ) )
continue;
}
V_96 = F_133 ( V_62 , V_44 ,
V_142 + 1 ) ;
if ( V_96 < 0 )
goto V_46;
} else {
struct V_80 V_81 ;
V_96 = F_87 ( & V_81 , V_143 -> V_129 ) ;
if ( V_96 )
goto V_46;
if ( V_81 . V_88 )
V_96 = F_131 ( V_62 , V_44 , & V_81 ) ;
free ( V_81 . V_83 ) ;
if ( V_96 )
goto V_46;
}
}
V_46:
F_137 ( V_144 ) ;
return V_96 ;
}
static int F_138 ( struct V_6 * V_6 )
{
char * V_137 ;
char V_149 [ V_45 ] ;
V_137 = F_129 ( V_6 -> V_7 ) ;
if ( ! V_137 )
return - 1 ;
snprintf ( V_149 , sizeof( V_149 ) , L_35 ,
V_6 -> V_7 , V_137 ) ;
free ( V_137 ) ;
return F_133 ( & V_6 -> V_9 , V_149 , 0 ) ;
}
static int F_139 ( void * V_150 , const char * V_83 , T_6 V_93 )
{
struct V_6 * V_6 = V_150 ;
struct V_92 * V_92 ;
V_92 = F_86 ( V_6 , V_93 , V_83 ) ;
if ( V_92 == NULL )
return - 1 ;
F_132 ( V_92 -> V_30 , V_6 -> V_7 ) ;
return 0 ;
}
static int F_140 ( struct V_6 * V_6 )
{
const char * V_151 ;
char V_44 [ V_45 ] ;
if ( F_49 ( V_6 ) ) {
V_151 = V_48 . V_127 ;
} else {
snprintf ( V_44 , V_45 , L_36 , V_6 -> V_7 ) ;
V_151 = V_44 ;
}
if ( F_109 ( V_151 , L_37 ) )
return - 1 ;
if ( F_141 ( V_151 , V_6 , F_139 ) )
return - 1 ;
if ( ! F_138 ( V_6 ) )
return 0 ;
F_118 ( L_38 ) ;
return 0 ;
}
int F_12 ( struct V_6 * V_6 )
{
struct V_30 * V_105 = F_103 ( V_6 ) ;
const char * V_83 ;
T_6 V_114 ;
int V_96 ;
if ( V_105 == NULL )
return - 1 ;
V_96 = F_111 ( V_6 , V_105 ) ;
F_17 ( V_105 ) ;
if ( V_96 < 0 )
return - 1 ;
if ( V_48 . V_152 && F_140 ( V_6 ) < 0 ) {
if ( F_48 ( V_6 ) )
F_118 ( L_39
L_40 ) ;
else
F_118 ( L_41
L_40 , V_6 -> V_8 ) ;
}
F_128 ( & V_6 -> V_9 ) ;
V_114 = F_108 ( V_6 , & V_83 ) ;
if ( ! V_114 ) {
} else if ( F_142 ( V_6 -> V_23 , V_83 , V_114 ) ) {
F_27 ( V_6 ) ;
return - 1 ;
}
return 0 ;
}
static void F_143 ( struct V_6 * V_6 ,
union V_65 * V_66 )
{
int V_98 ;
for ( V_98 = 0 ; V_98 < V_117 ; V_98 ++ ) {
V_6 -> V_23 [ V_98 ] -> V_93 = V_66 -> V_153 . V_93 ;
V_6 -> V_23 [ V_98 ] -> V_154 = ( V_66 -> V_153 . V_93 +
V_66 -> V_153 . V_155 ) ;
if ( V_6 -> V_23 [ V_98 ] -> V_154 == 0 )
V_6 -> V_23 [ V_98 ] -> V_154 = ~ 0ULL ;
}
}
static bool F_144 ( struct V_6 * V_6 )
{
struct V_30 * V_30 ;
F_145 (dso, &machine->dsos.head, node) {
if ( F_146 ( V_30 ) )
return true ;
}
return false ;
}
static int F_147 ( struct V_6 * V_6 ,
union V_65 * V_66 )
{
struct V_92 * V_92 ;
char V_156 [ V_45 ] ;
enum V_157 V_158 ;
bool V_159 ;
if ( F_144 ( V_6 ) )
return 0 ;
F_47 ( V_6 , V_156 , sizeof( V_156 ) ) ;
if ( F_48 ( V_6 ) )
V_158 = V_107 ;
else
V_158 = V_109 ;
V_159 = memcmp ( V_66 -> V_153 . V_82 ,
V_156 ,
strlen ( V_156 ) - 1 ) == 0 ;
if ( V_66 -> V_153 . V_82 [ 0 ] == '/' ||
( ! V_159 && V_66 -> V_153 . V_82 [ 0 ] == '[' ) ) {
V_92 = F_86 ( V_6 , V_66 -> V_153 . V_93 ,
V_66 -> V_153 . V_82 ) ;
if ( V_92 == NULL )
goto V_160;
V_92 -> V_154 = V_92 -> V_93 + V_66 -> V_153 . V_155 ;
} else if ( V_159 ) {
const char * V_113 = ( V_66 -> V_153 . V_82 +
strlen ( V_156 ) ) ;
struct V_30 * V_105 = NULL ;
struct V_30 * V_30 ;
F_63 ( & V_6 -> V_1 . V_5 ) ;
F_145 (dso, &machine->dsos.head, node) {
if ( ! V_30 -> V_105 ||
F_148 ( V_30 -> V_91 ,
V_161 ) )
continue;
V_105 = V_30 ;
break;
}
F_18 ( & V_6 -> V_1 . V_5 ) ;
if ( V_105 == NULL )
V_105 = F_149 ( V_6 , V_156 ) ;
if ( V_105 == NULL )
goto V_160;
V_105 -> V_105 = V_158 ;
if ( F_111 ( V_6 , V_105 ) < 0 ) {
F_17 ( V_105 ) ;
goto V_160;
}
if ( strstr ( V_105 -> V_91 , L_42 ) )
F_76 ( V_105 , L_43 , false ) ;
F_143 ( V_6 , V_66 ) ;
if ( V_66 -> V_153 . V_162 != 0 ) {
F_142 ( V_6 -> V_23 ,
V_113 ,
V_66 -> V_153 . V_162 ) ;
}
if ( F_49 ( V_6 ) ) {
F_150 ( V_105 , F_99 ( V_6 ) , NULL ) ;
}
}
return 0 ;
V_160:
return - 1 ;
}
int F_151 ( struct V_6 * V_6 ,
union V_65 * V_66 ,
struct V_67 * V_68 )
{
struct V_26 * V_26 ;
struct V_92 * V_92 ;
enum V_116 type ;
int V_96 = 0 ;
if ( V_74 )
F_152 ( V_66 , stdout ) ;
if ( V_68 -> V_163 == V_164 ||
V_68 -> V_163 == V_165 ) {
V_96 = F_147 ( V_6 , V_66 ) ;
if ( V_96 < 0 )
goto V_160;
return 0 ;
}
V_26 = F_8 ( V_6 , V_66 -> V_166 . V_8 ,
V_66 -> V_166 . V_60 ) ;
if ( V_26 == NULL )
goto V_160;
if ( V_66 -> V_70 . V_71 & V_167 )
type = V_168 ;
else
type = V_94 ;
V_92 = F_153 ( V_6 , V_66 -> V_166 . V_93 ,
V_66 -> V_166 . V_155 , V_66 -> V_166 . V_162 ,
V_66 -> V_166 . V_8 , V_66 -> V_166 . V_169 ,
V_66 -> V_166 . V_170 , V_66 -> V_166 . V_171 ,
V_66 -> V_166 . V_172 ,
V_66 -> V_166 . V_173 ,
V_66 -> V_166 . V_174 ,
V_66 -> V_166 . V_82 , type , V_26 ) ;
if ( V_92 == NULL )
goto V_175;
F_154 ( V_26 , V_92 ) ;
F_10 ( V_26 ) ;
F_91 ( V_92 ) ;
return 0 ;
V_175:
F_10 ( V_26 ) ;
V_160:
F_70 ( L_44 ) ;
return 0 ;
}
int F_155 ( struct V_6 * V_6 , union V_65 * V_66 ,
struct V_67 * V_68 )
{
struct V_26 * V_26 ;
struct V_92 * V_92 ;
enum V_116 type ;
int V_96 = 0 ;
if ( V_74 )
F_156 ( V_66 , stdout ) ;
if ( V_68 -> V_163 == V_164 ||
V_68 -> V_163 == V_165 ) {
V_96 = F_147 ( V_6 , V_66 ) ;
if ( V_96 < 0 )
goto V_160;
return 0 ;
}
V_26 = F_8 ( V_6 , V_66 -> V_153 . V_8 ,
V_66 -> V_153 . V_60 ) ;
if ( V_26 == NULL )
goto V_160;
if ( V_66 -> V_70 . V_71 & V_167 )
type = V_168 ;
else
type = V_94 ;
V_92 = F_153 ( V_6 , V_66 -> V_153 . V_93 ,
V_66 -> V_153 . V_155 , V_66 -> V_153 . V_162 ,
V_66 -> V_153 . V_8 , 0 , 0 , 0 , 0 , 0 , 0 ,
V_66 -> V_153 . V_82 ,
type , V_26 ) ;
if ( V_92 == NULL )
goto V_175;
F_154 ( V_26 , V_92 ) ;
F_10 ( V_26 ) ;
F_91 ( V_92 ) ;
return 0 ;
V_175:
F_10 ( V_26 ) ;
V_160:
F_70 ( L_45 ) ;
return 0 ;
}
static void F_25 ( struct V_6 * V_6 , struct V_26 * V_57 , bool V_5 )
{
if ( V_6 -> V_15 == V_57 )
V_6 -> V_15 = NULL ;
F_157 ( F_158 ( & V_57 -> V_176 ) == 0 ) ;
if ( V_5 )
F_14 ( & V_6 -> V_12 ) ;
F_61 ( & V_57 -> V_10 , & V_6 -> V_11 ) ;
F_6 ( & V_57 -> V_10 ) ;
-- V_6 -> V_13 ;
F_159 ( & V_57 -> V_33 , & V_6 -> V_14 ) ;
if ( V_5 )
F_18 ( & V_6 -> V_12 ) ;
F_10 ( V_57 ) ;
}
void F_160 ( struct V_6 * V_6 , struct V_26 * V_57 )
{
return F_25 ( V_6 , V_57 , true ) ;
}
int F_161 ( struct V_6 * V_6 , union V_65 * V_66 ,
struct V_67 * V_68 )
{
struct V_26 * V_26 = F_62 ( V_6 ,
V_66 -> V_177 . V_8 ,
V_66 -> V_177 . V_60 ) ;
struct V_26 * V_40 = F_8 ( V_6 ,
V_66 -> V_177 . V_178 ,
V_66 -> V_177 . V_179 ) ;
int V_73 = 0 ;
if ( V_74 )
F_162 ( V_66 , stdout ) ;
if ( V_40 -> V_59 != ( T_1 ) V_66 -> V_177 . V_178 ) {
F_70 ( L_46 ,
V_40 -> V_59 , V_40 -> V_60 ) ;
F_160 ( V_6 , V_40 ) ;
F_10 ( V_40 ) ;
V_40 = F_8 ( V_6 , V_66 -> V_177 . V_178 ,
V_66 -> V_177 . V_179 ) ;
}
if ( V_26 != NULL ) {
F_160 ( V_6 , V_26 ) ;
F_10 ( V_26 ) ;
}
V_26 = F_8 ( V_6 , V_66 -> V_177 . V_8 ,
V_66 -> V_177 . V_60 ) ;
if ( V_26 == NULL || V_40 == NULL ||
F_163 ( V_26 , V_40 , V_68 -> time ) < 0 ) {
F_70 ( L_47 ) ;
V_73 = - 1 ;
}
F_10 ( V_26 ) ;
F_10 ( V_40 ) ;
return V_73 ;
}
int F_164 ( struct V_6 * V_6 , union V_65 * V_66 ,
struct V_67 * V_68 V_75 )
{
struct V_26 * V_26 = F_62 ( V_6 ,
V_66 -> V_177 . V_8 ,
V_66 -> V_177 . V_60 ) ;
if ( V_74 )
F_162 ( V_66 , stdout ) ;
if ( V_26 != NULL ) {
F_165 ( V_26 ) ;
F_10 ( V_26 ) ;
}
return 0 ;
}
int F_166 ( struct V_6 * V_6 , union V_65 * V_66 ,
struct V_67 * V_68 )
{
int V_96 ;
switch ( V_66 -> V_70 . type ) {
case V_180 :
V_96 = F_67 ( V_6 , V_66 , V_68 ) ; break;
case V_181 :
V_96 = F_155 ( V_6 , V_66 , V_68 ) ; break;
case V_182 :
V_96 = F_151 ( V_6 , V_66 , V_68 ) ; break;
case V_183 :
V_96 = F_161 ( V_6 , V_66 , V_68 ) ; break;
case V_184 :
V_96 = F_164 ( V_6 , V_66 , V_68 ) ; break;
case V_185 :
V_96 = F_71 ( V_6 , V_66 , V_68 ) ; break;
case V_186 :
V_96 = F_79 ( V_6 , V_66 ) ; break;
case V_187 :
V_96 = F_81 ( V_6 , V_66 ) ; break;
case V_188 :
V_96 = F_72 ( V_6 , V_66 , V_68 ) ; break;
case V_189 :
case V_190 :
V_96 = F_83 ( V_6 , V_66 ) ; break;
default:
V_96 = - 1 ;
break;
}
return V_96 ;
}
static bool F_167 ( struct V_191 * V_192 , T_9 * V_193 )
{
if ( V_192 -> V_83 && ! regexec ( V_193 , V_192 -> V_83 , 0 , NULL , 0 ) )
return 1 ;
return 0 ;
}
static void F_168 ( struct V_26 * V_26 ,
struct V_194 * V_195 ,
T_6 V_196 )
{
struct V_197 V_198 ;
memset ( & V_198 , 0 , sizeof( V_198 ) ) ;
F_169 ( V_26 , V_94 , V_196 , & V_198 ) ;
V_195 -> V_114 = V_196 ;
V_195 -> V_199 = V_198 . V_114 ;
V_195 -> V_192 = V_198 . V_192 ;
V_195 -> V_92 = V_198 . V_92 ;
}
static void F_170 ( struct V_26 * V_26 ,
T_10 V_81 , struct V_194 * V_195 , T_6 V_114 )
{
struct V_197 V_198 ;
memset ( & V_198 , 0 , sizeof( V_198 ) ) ;
F_171 ( V_26 , V_81 , V_168 , V_114 , & V_198 ) ;
if ( V_198 . V_92 == NULL ) {
F_171 ( V_26 , V_81 , V_94 , V_114 , & V_198 ) ;
}
V_195 -> V_114 = V_114 ;
V_195 -> V_199 = V_198 . V_114 ;
V_195 -> V_192 = V_198 . V_192 ;
V_195 -> V_92 = V_198 . V_92 ;
}
struct V_200 * F_172 ( struct V_67 * V_68 ,
struct V_197 * V_198 )
{
struct V_200 * V_201 = F_173 ( sizeof( * V_201 ) ) ;
if ( ! V_201 )
return NULL ;
F_168 ( V_198 -> V_26 , & V_201 -> V_202 , V_68 -> V_196 ) ;
F_170 ( V_198 -> V_26 , V_198 -> V_163 , & V_201 -> V_203 , V_68 -> V_114 ) ;
V_201 -> V_204 . V_205 = V_68 -> V_204 ;
return V_201 ;
}
static int F_174 ( struct V_26 * V_26 ,
struct V_206 * V_207 ,
struct V_191 * * V_40 ,
struct V_197 * V_208 ,
T_10 * V_163 ,
T_6 V_196 )
{
struct V_197 V_198 ;
V_198 . V_209 = 0 ;
V_198 . V_192 = NULL ;
if ( ! V_163 ) {
F_169 ( V_26 , V_94 ,
V_196 , & V_198 ) ;
} else {
if ( V_196 >= V_210 ) {
switch ( V_196 ) {
case V_211 :
* V_163 = V_212 ;
break;
case V_213 :
* V_163 = V_165 ;
break;
case V_214 :
* V_163 = V_215 ;
break;
default:
F_118 ( L_48
L_49 V_216 L_14 , ( V_217 ) V_196 ) ;
F_175 ( V_207 ) ;
return 1 ;
}
return 0 ;
}
F_171 ( V_26 , * V_163 , V_94 ,
V_196 , & V_198 ) ;
}
if ( V_198 . V_192 != NULL ) {
if ( V_218 . V_40 && ! * V_40 &&
F_167 ( V_198 . V_192 , & V_219 ) )
* V_40 = V_198 . V_192 ;
else if ( V_220 && V_208 &&
F_167 ( V_198 . V_192 , & V_221 ) ) {
* V_208 = V_198 ;
F_175 ( V_207 ) ;
}
}
if ( V_48 . V_222 && V_198 . V_192 == NULL )
return 0 ;
return F_176 ( V_207 , V_198 . V_114 , V_198 . V_92 , V_198 . V_192 ) ;
}
struct V_223 * F_177 ( struct V_67 * V_68 ,
struct V_197 * V_198 )
{
unsigned int V_98 ;
const struct V_224 * V_225 = V_68 -> V_224 ;
struct V_223 * V_226 = calloc ( V_225 -> V_227 , sizeof( struct V_223 ) ) ;
if ( ! V_226 )
return NULL ;
for ( V_98 = 0 ; V_98 < V_225 -> V_227 ; V_98 ++ ) {
F_168 ( V_198 -> V_26 , & V_226 [ V_98 ] . V_228 , V_225 -> V_229 [ V_98 ] . V_228 ) ;
F_168 ( V_198 -> V_26 , & V_226 [ V_98 ] . V_230 , V_225 -> V_229 [ V_98 ] . V_230 ) ;
V_226 [ V_98 ] . V_174 = V_225 -> V_229 [ V_98 ] . V_174 ;
}
return V_226 ;
}
static int F_178 ( struct V_231 * V_232 , int V_227 )
{
int V_98 , V_233 , V_234 ;
unsigned char V_235 [ V_236 ] ;
memset ( V_235 , V_237 , sizeof( V_235 ) ) ;
F_157 ( V_238 > 255 ) ;
for ( V_98 = 0 ; V_98 < V_227 ; V_98 ++ ) {
int V_239 = F_179 ( V_232 [ V_98 ] . V_230 , V_240 ) % V_236 ;
if ( V_235 [ V_239 ] == V_237 ) {
V_235 [ V_239 ] = V_98 ;
} else if ( V_232 [ V_235 [ V_239 ] ] . V_230 == V_232 [ V_98 ] . V_230 ) {
bool V_241 = true ;
V_234 = 0 ;
for ( V_233 = V_235 [ V_239 ] ; V_233 < V_98 && V_98 + V_234 < V_227 ; V_233 ++ , V_234 ++ )
if ( V_232 [ V_233 ] . V_230 != V_232 [ V_98 + V_234 ] . V_230 ) {
V_241 = false ;
break;
}
if ( V_241 ) {
memmove ( V_232 + V_98 , V_232 + V_98 + V_234 ,
( V_227 - ( V_98 + V_234 ) ) * sizeof( * V_232 ) ) ;
V_227 -= V_234 ;
}
}
}
return V_227 ;
}
static int F_180 ( struct V_26 * V_26 ,
struct V_206 * V_207 ,
struct V_67 * V_68 ,
struct V_191 * * V_40 ,
struct V_197 * V_208 ,
int V_242 )
{
struct V_243 * V_244 = V_68 -> V_245 ;
int V_246 = V_170 ( V_242 , ( int ) V_244 -> V_227 ) ;
T_10 V_163 = V_215 ;
int V_98 , V_233 , V_73 ;
T_6 V_196 ;
for ( V_98 = 0 ; V_98 < V_246 ; V_98 ++ ) {
if ( V_244 -> V_247 [ V_98 ] == V_214 )
break;
}
if ( V_98 != V_246 ) {
struct V_224 * V_248 = V_68 -> V_224 ;
int V_249 = V_248 -> V_227 ;
int V_250 = V_98 + 1 + V_249 + 1 ;
for ( V_233 = 0 ; V_233 < V_250 ; V_233 ++ ) {
if ( V_251 . V_252 == V_253 ) {
if ( V_233 < V_98 + 1 )
V_196 = V_244 -> V_247 [ V_233 ] ;
else if ( V_233 > V_98 + 1 )
V_196 = V_248 -> V_229 [ V_233 - V_98 - 2 ] . V_230 ;
else
V_196 = V_248 -> V_229 [ 0 ] . V_228 ;
} else {
if ( V_233 < V_249 )
V_196 = V_248 -> V_229 [ V_249 - V_233 - 1 ] . V_230 ;
else if ( V_233 > V_249 )
V_196 = V_244 -> V_247 [ V_98 + 1 - ( V_233 - V_249 ) ] ;
else
V_196 = V_248 -> V_229 [ 0 ] . V_228 ;
}
V_73 = F_174 ( V_26 , V_207 , V_40 , V_208 , & V_163 , V_196 ) ;
if ( V_73 )
return ( V_73 < 0 ) ? V_73 : 0 ;
}
return 1 ;
}
return 0 ;
}
static int F_181 ( struct V_26 * V_26 ,
struct V_206 * V_207 ,
struct V_254 * V_255 ,
struct V_67 * V_68 ,
struct V_191 * * V_40 ,
struct V_197 * V_208 ,
int V_242 )
{
struct V_224 * V_256 = V_68 -> V_224 ;
struct V_243 * V_244 = V_68 -> V_245 ;
int V_246 = V_244 -> V_227 ;
T_10 V_163 = V_215 ;
int V_98 , V_233 , V_73 , V_257 ;
int V_258 = - 1 ;
int V_259 = 0 ;
if ( F_182 ( V_255 ) ) {
V_73 = F_180 ( V_26 , V_207 , V_68 , V_40 ,
V_208 , V_242 ) ;
if ( V_73 )
return ( V_73 < 0 ) ? V_73 : 0 ;
}
V_258 = F_183 ( V_26 , V_244 ) ;
if ( V_256 && V_251 . V_260 ) {
int V_227 = V_170 ( V_242 , ( int ) V_256 -> V_227 ) ;
struct V_231 V_261 [ V_227 ] ;
if ( V_256 -> V_227 > V_238 ) {
F_184 ( L_50 ) ;
goto V_262;
}
for ( V_98 = 0 ; V_98 < V_227 ; V_98 ++ ) {
if ( V_251 . V_252 == V_253 ) {
V_261 [ V_98 ] = V_256 -> V_229 [ V_98 ] ;
if ( V_98 == V_258 ||
V_244 -> V_247 [ V_259 ] >= V_210 )
V_259 ++ ;
else if ( V_261 [ V_98 ] . V_230 < V_244 -> V_247 [ V_259 ] &&
V_261 [ V_98 ] . V_230 >= V_244 -> V_247 [ V_259 ] - 8 )
V_259 ++ ;
} else
V_261 [ V_98 ] = V_256 -> V_229 [ V_256 -> V_227 - V_98 - 1 ] ;
}
V_227 = F_178 ( V_261 , V_227 ) ;
for ( V_98 = 0 ; V_98 < V_227 ; V_98 ++ ) {
V_73 = F_174 ( V_26 , V_207 , V_40 , V_208 ,
NULL , V_261 [ V_98 ] . V_228 ) ;
if ( ! V_73 )
V_73 = F_174 ( V_26 , V_207 , V_40 , V_208 ,
NULL , V_261 [ V_98 ] . V_230 ) ;
if ( V_73 == - V_263 )
break;
if ( V_73 )
return V_73 ;
}
V_246 -= V_227 ;
}
V_262:
for ( V_98 = V_259 , V_257 = 0 ;
V_98 < V_246 && V_257 < V_242 ; V_98 ++ ) {
T_6 V_196 ;
if ( V_251 . V_252 == V_253 )
V_233 = V_98 ;
else
V_233 = V_244 -> V_227 - V_98 - 1 ;
#ifdef F_185
if ( V_233 == V_258 )
continue;
#endif
V_196 = V_244 -> V_247 [ V_233 ] ;
if ( V_196 < V_210 )
++ V_257 ;
V_73 = F_174 ( V_26 , V_207 , V_40 , V_208 , & V_163 , V_196 ) ;
if ( V_73 )
return ( V_73 < 0 ) ? V_73 : 0 ;
}
return 0 ;
}
static int F_186 ( struct F_186 * V_264 , void * V_150 )
{
struct V_206 * V_207 = V_150 ;
if ( V_48 . V_222 && V_264 -> V_192 == NULL )
return 0 ;
return F_176 ( V_207 , V_264 -> V_196 ,
V_264 -> V_92 , V_264 -> V_192 ) ;
}
static int F_187 ( struct V_26 * V_26 ,
struct V_206 * V_207 ,
struct V_254 * V_255 ,
struct V_67 * V_68 ,
int V_242 )
{
if ( ! ( ( V_255 -> V_265 . V_266 & V_267 ) &&
( V_255 -> V_265 . V_266 & V_268 ) ) )
return 0 ;
if ( ( ! V_68 -> V_269 . V_270 ) ||
( ! V_68 -> V_271 . V_56 ) )
return 0 ;
return F_188 ( F_186 , V_207 ,
V_26 , V_68 , V_242 ) ;
}
int F_189 ( struct V_26 * V_26 ,
struct V_206 * V_207 ,
struct V_254 * V_255 ,
struct V_67 * V_68 ,
struct V_191 * * V_40 ,
struct V_197 * V_208 ,
int V_242 )
{
int V_96 = 0 ;
F_175 ( & V_206 ) ;
if ( V_251 . V_252 == V_253 ) {
V_96 = F_181 ( V_26 , V_207 ,
V_255 , V_68 ,
V_40 , V_208 ,
V_242 ) ;
if ( V_96 )
return V_96 ;
V_96 = F_187 ( V_26 , V_207 ,
V_255 , V_68 ,
V_242 ) ;
} else {
V_96 = F_187 ( V_26 , V_207 ,
V_255 , V_68 ,
V_242 ) ;
if ( V_96 )
return V_96 ;
V_96 = F_181 ( V_26 , V_207 ,
V_255 , V_68 ,
V_40 , V_208 ,
V_242 ) ;
}
return V_96 ;
}
int F_190 ( struct V_6 * V_6 ,
int (* F_191)( struct V_26 * V_26 , void * V_39 ) ,
void * V_272 )
{
struct V_10 * V_34 ;
struct V_26 * V_26 ;
int V_273 = 0 ;
for ( V_34 = F_22 ( & V_6 -> V_11 ) ; V_34 ; V_34 = F_24 ( V_34 ) ) {
V_26 = F_23 ( V_34 , struct V_26 , V_10 ) ;
V_273 = F_191 ( V_26 , V_272 ) ;
if ( V_273 != 0 )
return V_273 ;
}
F_145 (thread, &machine->dead_threads, node) {
V_273 = F_191 ( V_26 , V_272 ) ;
if ( V_273 != 0 )
return V_273 ;
}
return V_273 ;
}
int F_192 ( struct V_36 * V_36 ,
int (* F_191)( struct V_26 * V_26 , void * V_39 ) ,
void * V_272 )
{
struct V_10 * V_34 ;
int V_273 = 0 ;
V_273 = F_190 ( & V_36 -> V_37 , F_191 , V_272 ) ;
if ( V_273 != 0 )
return V_273 ;
for ( V_34 = F_22 ( & V_36 -> V_38 ) ; V_34 ; V_34 = F_24 ( V_34 ) ) {
struct V_6 * V_6 = F_23 ( V_34 , struct V_6 , V_10 ) ;
V_273 = F_190 ( V_6 , F_191 , V_272 ) ;
if ( V_273 != 0 )
return V_273 ;
}
return V_273 ;
}
int F_193 ( struct V_6 * V_6 , struct V_274 * V_275 ,
struct V_276 * V_276 , struct V_277 * V_11 ,
T_11 V_53 , bool V_278 ,
unsigned int V_279 )
{
if ( F_194 ( V_276 ) )
return F_195 ( V_275 , V_11 , V_53 , V_6 , V_278 , V_279 ) ;
else if ( F_196 ( V_276 ) )
return F_197 ( V_275 , V_53 , V_6 , V_278 , V_279 ) ;
return 0 ;
}
T_1 F_198 ( struct V_6 * V_6 , int V_280 )
{
if ( V_280 < 0 || V_280 >= V_281 || ! V_6 -> V_28 )
return - 1 ;
return V_6 -> V_28 [ V_280 ] ;
}
int F_199 ( struct V_6 * V_6 , int V_280 , T_1 V_8 ,
T_1 V_60 )
{
struct V_26 * V_26 ;
if ( V_280 < 0 )
return - V_263 ;
if ( ! V_6 -> V_28 ) {
int V_98 ;
V_6 -> V_28 = calloc ( V_281 , sizeof( T_1 ) ) ;
if ( ! V_6 -> V_28 )
return - V_24 ;
for ( V_98 = 0 ; V_98 < V_281 ; V_98 ++ )
V_6 -> V_28 [ V_98 ] = - 1 ;
}
if ( V_280 >= V_281 ) {
F_44 ( L_51 , V_280 ) ;
F_44 ( L_52 ) ;
return - V_263 ;
}
V_6 -> V_28 [ V_280 ] = V_60 ;
V_26 = F_8 ( V_6 , V_8 , V_60 ) ;
if ( ! V_26 )
return - V_24 ;
V_26 -> V_280 = V_280 ;
F_10 ( V_26 ) ;
return 0 ;
}
int F_200 ( struct V_6 * V_6 )
{
struct V_92 * V_92 = F_99 ( V_6 ) ;
int V_73 = 0 ;
V_6 -> V_22 = 1ULL << 63 ;
if ( V_92 ) {
V_73 = F_201 ( V_92 , V_6 -> V_18 ) ;
if ( V_92 -> V_93 )
V_6 -> V_22 = V_92 -> V_93 ;
}
return V_73 ;
}
struct V_30 * F_149 ( struct V_6 * V_6 , const char * V_82 )
{
return F_202 ( & V_6 -> V_1 , V_82 ) ;
}
char * F_203 ( void * V_282 , unsigned long long * V_283 , char * * V_284 )
{
struct V_6 * V_6 = V_282 ;
struct V_92 * V_92 ;
struct V_191 * V_192 = F_204 ( & V_6 -> V_9 , V_94 , * V_283 , & V_92 , NULL ) ;
if ( V_192 == NULL )
return NULL ;
* V_284 = F_205 ( V_92 ) ? ( char * ) V_92 -> V_30 -> V_285 : NULL ;
* V_283 = V_92 -> V_120 ( V_92 , V_192 -> V_93 ) ;
return V_192 -> V_83 ;
}
