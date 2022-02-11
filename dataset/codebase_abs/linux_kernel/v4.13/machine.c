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
V_6 -> V_18 = 0 ;
V_6 -> V_19 = false ;
V_6 -> V_20 = false ;
V_6 -> V_21 = 0 ;
memset ( V_6 -> V_22 , 0 , sizeof( V_6 -> V_22 ) ) ;
V_6 -> V_7 = F_7 ( V_7 ) ;
if ( V_6 -> V_7 == NULL )
return - V_23 ;
if ( V_8 != V_24 ) {
struct V_25 * V_25 = F_8 ( V_6 , - 1 ,
V_8 ) ;
char V_26 [ 64 ] ;
if ( V_25 == NULL )
return - V_23 ;
snprintf ( V_26 , sizeof( V_26 ) , L_1 , V_8 ) ;
F_9 ( V_25 , V_26 , 0 ) ;
F_10 ( V_25 ) ;
}
V_6 -> V_27 = NULL ;
return 0 ;
}
struct V_6 * F_11 ( void )
{
struct V_6 * V_6 = malloc ( sizeof( * V_6 ) ) ;
if ( V_6 != NULL ) {
F_4 ( V_6 , L_2 , V_24 ) ;
if ( F_12 ( V_6 ) < 0 )
goto V_28;
}
return V_6 ;
V_28:
free ( V_6 ) ;
return NULL ;
}
struct V_6 * F_13 ( void )
{
struct V_6 * V_6 = F_11 () ;
if ( V_6 && F_14 ( V_6 , L_3 , V_29 , true ) <= 0 ) {
F_15 ( V_6 ) ;
V_6 = NULL ;
}
return V_6 ;
}
static void F_16 ( struct V_1 * V_1 )
{
struct V_30 * V_31 , * V_32 ;
F_17 ( & V_1 -> V_5 ) ;
F_18 (pos, n, &dsos->head, node) {
F_6 ( & V_31 -> V_10 ) ;
V_31 -> V_3 = NULL ;
F_19 ( & V_31 -> V_33 ) ;
F_20 ( V_31 ) ;
}
F_21 ( & V_1 -> V_5 ) ;
}
static void F_22 ( struct V_1 * V_1 )
{
F_16 ( V_1 ) ;
F_23 ( & V_1 -> V_5 ) ;
}
void F_24 ( struct V_6 * V_6 )
{
struct V_10 * V_34 ;
F_17 ( & V_6 -> V_12 ) ;
V_34 = F_25 ( & V_6 -> V_11 ) ;
while ( V_34 ) {
struct V_25 * V_35 = F_26 ( V_34 , struct V_25 , V_10 ) ;
V_34 = F_27 ( V_34 ) ;
F_28 ( V_6 , V_35 , false ) ;
}
F_21 ( & V_6 -> V_12 ) ;
}
void F_29 ( struct V_6 * V_6 )
{
F_30 ( V_6 ) ;
F_31 ( & V_6 -> V_9 ) ;
F_22 ( & V_6 -> V_1 ) ;
F_32 ( V_6 ) ;
F_33 ( & V_6 -> V_7 ) ;
F_33 ( & V_6 -> V_27 ) ;
F_23 ( & V_6 -> V_12 ) ;
}
void F_15 ( struct V_6 * V_6 )
{
if ( V_6 ) {
F_29 ( V_6 ) ;
free ( V_6 ) ;
}
}
void F_34 ( struct V_36 * V_36 )
{
F_4 ( & V_36 -> V_37 , L_2 , V_24 ) ;
V_36 -> V_38 = V_4 ;
}
void F_35 ( struct V_36 * V_36 )
{
F_29 ( & V_36 -> V_37 ) ;
}
struct V_6 * F_36 ( struct V_36 * V_36 , T_1 V_8 ,
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
while ( * V_39 != NULL ) {
V_40 = * V_39 ;
V_31 = F_26 ( V_40 , struct V_6 , V_10 ) ;
if ( V_8 < V_31 -> V_8 )
V_39 = & ( * V_39 ) -> V_41 ;
else
V_39 = & ( * V_39 ) -> V_42 ;
}
F_37 ( & V_6 -> V_10 , V_40 , V_39 ) ;
F_38 ( & V_6 -> V_10 , & V_36 -> V_38 ) ;
return V_6 ;
}
void F_39 ( struct V_36 * V_36 , bool V_20 )
{
struct V_10 * V_34 ;
V_36 -> V_37 . V_20 = V_20 ;
for ( V_34 = F_25 ( & V_36 -> V_38 ) ; V_34 ; V_34 = F_27 ( V_34 ) ) {
struct V_6 * V_6 = F_26 ( V_34 , struct V_6 , V_10 ) ;
V_6 -> V_20 = V_20 ;
}
}
struct V_6 * F_40 ( struct V_36 * V_36 , T_1 V_8 )
{
struct V_10 * * V_39 = & V_36 -> V_38 . V_10 ;
struct V_10 * V_40 = NULL ;
struct V_6 * V_6 ;
struct V_6 * V_43 = NULL ;
if ( V_8 == V_24 )
return & V_36 -> V_37 ;
while ( * V_39 != NULL ) {
V_40 = * V_39 ;
V_6 = F_26 ( V_40 , struct V_6 , V_10 ) ;
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
struct V_6 * F_41 ( struct V_36 * V_36 , T_1 V_8 )
{
char V_44 [ V_45 ] ;
const char * V_7 = L_2 ;
struct V_6 * V_6 = F_40 ( V_36 , V_8 ) ;
if ( V_6 && ( V_6 -> V_8 == V_8 ) )
goto V_46;
if ( ( V_8 != V_24 ) &&
( V_8 != V_47 ) &&
( V_48 . V_49 ) ) {
sprintf ( V_44 , L_4 , V_48 . V_49 , V_8 ) ;
if ( F_42 ( V_44 , V_50 ) ) {
static struct V_51 * V_52 ;
if ( ! V_52 )
V_52 = F_43 ( NULL , NULL ) ;
if ( ! F_44 ( V_52 , V_44 ) ) {
F_45 ( L_5 , V_44 ) ;
F_46 ( V_52 , V_44 ) ;
}
V_6 = NULL ;
goto V_46;
}
V_7 = V_44 ;
}
V_6 = F_36 ( V_36 , V_8 , V_7 ) ;
V_46:
return V_6 ;
}
void F_47 ( struct V_36 * V_36 ,
T_2 V_53 , void * V_54 )
{
struct V_10 * V_34 ;
for ( V_34 = F_25 ( & V_36 -> V_38 ) ; V_34 ; V_34 = F_27 ( V_34 ) ) {
struct V_6 * V_31 = F_26 ( V_34 , struct V_6 , V_10 ) ;
V_53 ( V_31 , V_54 ) ;
}
}
char * F_48 ( struct V_6 * V_6 , char * V_55 , T_3 V_56 )
{
if ( F_49 ( V_6 ) )
snprintf ( V_55 , V_56 , L_6 , L_7 ) ;
else if ( F_50 ( V_6 ) )
snprintf ( V_55 , V_56 , L_6 , L_8 ) ;
else {
snprintf ( V_55 , V_56 , L_9 , L_8 ,
V_6 -> V_8 ) ;
}
return V_55 ;
}
void F_51 ( struct V_36 * V_36 , T_4 V_18 )
{
struct V_10 * V_33 ;
struct V_6 * V_6 ;
V_36 -> V_37 . V_18 = V_18 ;
for ( V_33 = F_25 ( & V_36 -> V_38 ) ; V_33 ; V_33 = F_27 ( V_33 ) ) {
V_6 = F_26 ( V_33 , struct V_6 , V_10 ) ;
V_6 -> V_18 = V_18 ;
}
return;
}
static void F_52 ( struct V_6 * V_6 ,
struct V_25 * V_57 , T_1 V_8 )
{
struct V_25 * V_58 ;
if ( V_8 == V_57 -> V_59 || V_8 == - 1 || V_57 -> V_59 != - 1 )
return;
V_57 -> V_59 = V_8 ;
if ( V_57 -> V_59 == V_57 -> V_60 )
return;
V_58 = F_53 ( V_6 , V_57 -> V_59 , V_57 -> V_59 ) ;
if ( ! V_58 )
goto V_61;
if ( ! V_58 -> V_62 )
V_58 -> V_62 = F_54 ( V_6 ) ;
if ( ! V_58 -> V_62 )
goto V_61;
if ( V_57 -> V_62 == V_58 -> V_62 )
return;
if ( V_57 -> V_62 ) {
if ( ! F_55 ( V_57 -> V_62 ) )
F_45 ( L_10 ,
V_57 -> V_59 , V_57 -> V_60 ) ;
F_56 ( V_57 -> V_62 ) ;
}
V_57 -> V_62 = F_57 ( V_58 -> V_62 ) ;
V_63:
F_10 ( V_58 ) ;
return;
V_61:
F_45 ( L_11 , V_57 -> V_59 , V_57 -> V_60 ) ;
goto V_63;
}
static struct V_25 * F_58 ( struct V_6 * V_6 ,
T_1 V_8 , T_1 V_60 ,
bool V_64 )
{
struct V_10 * * V_39 = & V_6 -> V_11 . V_10 ;
struct V_10 * V_40 = NULL ;
struct V_25 * V_57 ;
V_57 = V_6 -> V_15 ;
if ( V_57 != NULL ) {
if ( V_57 -> V_60 == V_60 ) {
F_52 ( V_6 , V_57 , V_8 ) ;
return F_59 ( V_57 ) ;
}
V_6 -> V_15 = NULL ;
}
while ( * V_39 != NULL ) {
V_40 = * V_39 ;
V_57 = F_26 ( V_40 , struct V_25 , V_10 ) ;
if ( V_57 -> V_60 == V_60 ) {
V_6 -> V_15 = V_57 ;
F_52 ( V_6 , V_57 , V_8 ) ;
return F_59 ( V_57 ) ;
}
if ( V_60 < V_57 -> V_60 )
V_39 = & ( * V_39 ) -> V_41 ;
else
V_39 = & ( * V_39 ) -> V_42 ;
}
if ( ! V_64 )
return NULL ;
V_57 = F_60 ( V_8 , V_60 ) ;
if ( V_57 != NULL ) {
F_37 ( & V_57 -> V_10 , V_40 , V_39 ) ;
F_38 ( & V_57 -> V_10 , & V_6 -> V_11 ) ;
if ( F_61 ( V_57 , V_6 ) ) {
F_62 ( & V_57 -> V_10 , & V_6 -> V_11 ) ;
F_6 ( & V_57 -> V_10 ) ;
F_10 ( V_57 ) ;
return NULL ;
}
F_59 ( V_57 ) ;
V_6 -> V_15 = V_57 ;
++ V_6 -> V_13 ;
}
return V_57 ;
}
struct V_25 * F_53 ( struct V_6 * V_6 , T_1 V_8 , T_1 V_60 )
{
return F_58 ( V_6 , V_8 , V_60 , true ) ;
}
struct V_25 * F_8 ( struct V_6 * V_6 , T_1 V_8 ,
T_1 V_60 )
{
struct V_25 * V_57 ;
F_17 ( & V_6 -> V_12 ) ;
V_57 = F_53 ( V_6 , V_8 , V_60 ) ;
F_21 ( & V_6 -> V_12 ) ;
return V_57 ;
}
struct V_25 * F_63 ( struct V_6 * V_6 , T_1 V_8 ,
T_1 V_60 )
{
struct V_25 * V_57 ;
F_64 ( & V_6 -> V_12 ) ;
V_57 = F_58 ( V_6 , V_8 , V_60 , false ) ;
F_21 ( & V_6 -> V_12 ) ;
return V_57 ;
}
struct V_26 * F_65 ( struct V_6 * V_6 ,
struct V_25 * V_25 )
{
if ( V_6 -> V_20 )
return F_66 ( V_25 ) ;
else
return F_67 ( V_25 ) ;
}
int F_68 ( struct V_6 * V_6 , union V_65 * V_66 ,
struct V_67 * V_68 )
{
struct V_25 * V_25 = F_8 ( V_6 ,
V_66 -> V_26 . V_8 ,
V_66 -> V_26 . V_60 ) ;
bool V_69 = V_66 -> V_70 . V_71 & V_72 ;
int V_73 = 0 ;
if ( V_69 )
V_6 -> V_20 = true ;
if ( V_74 )
F_69 ( V_66 , stdout ) ;
if ( V_25 == NULL ||
F_70 ( V_25 , V_66 -> V_26 . V_26 , V_68 -> time , V_69 ) ) {
F_71 ( L_12 ) ;
V_73 = - 1 ;
}
F_10 ( V_25 ) ;
return V_73 ;
}
int F_72 ( struct V_6 * V_6 V_75 ,
union V_65 * V_66 ,
struct V_67 * V_68 V_75 )
{
struct V_25 * V_25 = F_8 ( V_6 ,
V_66 -> V_76 . V_8 ,
V_66 -> V_76 . V_60 ) ;
int V_73 = 0 ;
F_73 ( V_66 -> V_76 . V_77 > V_78 ,
L_13
L_14 ) ;
F_73 ( V_66 -> V_76 . V_77 < V_78 ,
L_15
L_16 ) ;
if ( V_74 )
F_74 ( V_66 , stdout ) ;
if ( V_25 == NULL ||
F_75 ( V_25 , V_68 -> time , & V_66 -> V_76 ) ) {
F_71 ( L_17 ) ;
V_73 = - 1 ;
}
F_10 ( V_25 ) ;
return V_73 ;
}
int F_76 ( struct V_6 * V_6 V_75 ,
union V_65 * V_66 , struct V_67 * V_68 V_75 )
{
F_71 ( L_18 V_79 L_19 V_79 L_20 ,
V_66 -> V_80 . V_81 , V_66 -> V_80 . V_80 ) ;
return 0 ;
}
int F_77 ( struct V_6 * V_6 V_75 ,
union V_65 * V_66 , struct V_67 * V_68 )
{
F_71 ( L_18 V_79 L_21 V_79 L_20 ,
V_68 -> V_81 , V_66 -> V_82 . V_80 ) ;
return 0 ;
}
static struct V_30 * F_78 ( struct V_6 * V_6 ,
struct V_83 * V_84 ,
const char * V_85 )
{
struct V_30 * V_30 ;
F_17 ( & V_6 -> V_1 . V_5 ) ;
V_30 = F_79 ( & V_6 -> V_1 , V_84 -> V_86 , true ) ;
if ( ! V_30 ) {
V_30 = F_80 ( & V_6 -> V_1 , V_84 -> V_86 ) ;
if ( V_30 == NULL )
goto V_87;
F_81 ( V_30 , V_84 , V_6 ) ;
F_82 ( V_30 , F_7 ( V_85 ) , true ) ;
}
F_83 ( V_30 ) ;
V_87:
F_21 ( & V_6 -> V_1 . V_5 ) ;
return V_30 ;
}
int F_84 ( struct V_6 * V_6 V_75 ,
union V_65 * V_66 )
{
if ( V_74 )
F_85 ( V_66 , stdout ) ;
return 0 ;
}
int F_86 ( struct V_6 * V_6 V_75 ,
union V_65 * V_66 )
{
if ( V_74 )
F_87 ( V_66 , stdout ) ;
return 0 ;
}
int F_88 ( struct V_6 * V_6 V_75 ,
union V_65 * V_66 )
{
if ( V_74 )
F_89 ( V_66 , stdout ) ;
return 0 ;
}
static void F_90 ( struct V_30 * V_30 , const char * V_85 )
{
const char * V_88 ;
if ( ! V_85 || ! V_30 || ! V_30 -> V_89 )
return;
if ( V_30 -> V_89 [ 0 ] != '[' )
return;
if ( ! strchr ( V_85 , '/' ) )
return;
V_88 = F_7 ( V_85 ) ;
if ( ! V_88 )
return;
F_82 ( V_30 , V_88 , true ) ;
}
struct V_90 * F_91 ( struct V_6 * V_6 , T_5 V_91 ,
const char * V_85 )
{
struct V_90 * V_90 = NULL ;
struct V_30 * V_30 = NULL ;
struct V_83 V_84 ;
if ( F_92 ( & V_84 , V_85 ) )
return NULL ;
V_90 = F_93 ( & V_6 -> V_9 , V_29 ,
V_84 . V_86 ) ;
if ( V_90 ) {
F_90 ( V_90 -> V_30 , V_85 ) ;
goto V_46;
}
V_30 = F_78 ( V_6 , & V_84 , V_85 ) ;
if ( V_30 == NULL )
goto V_46;
V_90 = F_94 ( V_91 , V_30 , V_29 ) ;
if ( V_90 == NULL )
goto V_46;
F_95 ( & V_6 -> V_9 , V_90 ) ;
F_96 ( V_90 ) ;
V_46:
F_20 ( V_30 ) ;
free ( V_84 . V_86 ) ;
return V_90 ;
}
T_3 F_97 ( struct V_36 * V_36 , T_6 * V_92 )
{
struct V_10 * V_34 ;
T_3 V_93 = F_98 ( & V_36 -> V_37 . V_1 . V_2 , V_92 ) ;
for ( V_34 = F_25 ( & V_36 -> V_38 ) ; V_34 ; V_34 = F_27 ( V_34 ) ) {
struct V_6 * V_31 = F_26 ( V_34 , struct V_6 , V_10 ) ;
V_93 += F_98 ( & V_31 -> V_1 . V_2 , V_92 ) ;
}
return V_93 ;
}
T_3 F_99 ( struct V_6 * V_84 , T_6 * V_92 ,
bool (F_100)( struct V_30 * V_30 , int V_94 ) , int V_94 )
{
return F_101 ( & V_84 -> V_1 . V_2 , V_92 , F_100 , V_94 ) ;
}
T_3 F_102 ( struct V_36 * V_36 , T_6 * V_92 ,
bool (F_100)( struct V_30 * V_30 , int V_94 ) , int V_94 )
{
struct V_10 * V_34 ;
T_3 V_93 = F_99 ( & V_36 -> V_37 , V_92 , F_100 , V_94 ) ;
for ( V_34 = F_25 ( & V_36 -> V_38 ) ; V_34 ; V_34 = F_27 ( V_34 ) ) {
struct V_6 * V_31 = F_26 ( V_34 , struct V_6 , V_10 ) ;
V_93 += F_99 ( V_31 , V_92 , F_100 , V_94 ) ;
}
return V_93 ;
}
T_3 F_103 ( struct V_6 * V_6 , T_6 * V_92 )
{
int V_95 ;
T_3 V_96 = 0 ;
struct V_30 * V_97 = F_104 ( V_6 ) -> V_30 ;
if ( V_97 -> V_98 ) {
char V_85 [ V_45 ] ;
if ( F_105 ( V_97 , V_85 , sizeof( V_85 ) ) )
V_96 += fprintf ( V_92 , L_22 , V_85 ) ;
}
for ( V_95 = 0 ; V_95 < V_99 ; ++ V_95 )
V_96 += fprintf ( V_92 , L_23 ,
V_95 + V_97 -> V_98 , V_100 [ V_95 ] ) ;
return V_96 ;
}
T_3 F_106 ( struct V_6 * V_6 , T_6 * V_92 )
{
T_3 V_93 ;
struct V_10 * V_34 ;
F_64 ( & V_6 -> V_12 ) ;
V_93 = fprintf ( V_92 , L_24 , V_6 -> V_13 ) ;
for ( V_34 = F_25 ( & V_6 -> V_11 ) ; V_34 ; V_34 = F_27 ( V_34 ) ) {
struct V_25 * V_31 = F_26 ( V_34 , struct V_25 , V_10 ) ;
V_93 += F_107 ( V_31 , V_92 ) ;
}
F_21 ( & V_6 -> V_12 ) ;
return V_93 ;
}
static struct V_30 * F_108 ( struct V_6 * V_6 )
{
const char * V_101 = NULL ;
struct V_30 * V_102 ;
if ( F_49 ( V_6 ) ) {
V_101 = V_48 . V_101 ;
if ( ! V_101 )
V_101 = V_103 ;
V_102 = F_109 ( V_6 , V_101 ,
L_25 , V_104 ) ;
} else {
char V_55 [ V_45 ] ;
if ( F_50 ( V_6 ) )
V_101 = V_48 . V_105 ;
if ( ! V_101 )
V_101 = F_48 ( V_6 , V_55 ,
sizeof( V_55 ) ) ;
V_102 = F_109 ( V_6 , V_101 ,
L_26 ,
V_106 ) ;
}
if ( V_102 != NULL && ( ! V_102 -> V_98 ) )
F_110 ( V_102 , V_6 ) ;
return V_102 ;
}
static void F_111 ( struct V_6 * V_6 , char * V_107 ,
T_3 V_108 )
{
if ( F_50 ( V_6 ) )
F_112 ( V_107 , V_108 , L_27 , V_48 . V_109 ) ;
else
F_112 ( V_107 , V_108 , L_28 , V_6 -> V_7 ) ;
}
static int F_113 ( struct V_6 * V_6 ,
const char * * V_110 , T_5 * V_91 )
{
char V_85 [ V_45 ] ;
int V_95 , V_73 = - 1 ;
const char * V_86 ;
T_5 V_111 = 0 ;
F_111 ( V_6 , V_85 , V_45 ) ;
if ( F_114 ( V_85 , L_3 ) )
return 0 ;
for ( V_95 = 0 ; ( V_86 = V_112 [ V_95 ] ) != NULL ; V_95 ++ ) {
V_73 = F_115 ( V_85 , V_86 , & V_111 ) ;
if ( ! V_73 )
break;
}
if ( V_73 )
return - 1 ;
if ( V_110 )
* V_110 = V_86 ;
* V_91 = V_111 ;
return 0 ;
}
int F_116 ( struct V_6 * V_6 , struct V_30 * V_102 )
{
int type ;
T_5 V_91 = 0 ;
if ( F_113 ( V_6 , NULL , & V_91 ) )
return - 1 ;
F_30 ( V_6 ) ;
for ( type = 0 ; type < V_113 ; ++ type ) {
struct V_114 * V_114 ;
struct V_90 * V_90 ;
V_6 -> V_22 [ type ] = F_94 ( V_91 , V_102 , type ) ;
if ( V_6 -> V_22 [ type ] == NULL )
return - 1 ;
V_6 -> V_22 [ type ] -> V_115 =
V_6 -> V_22 [ type ] -> V_116 =
V_117 ;
V_90 = F_117 ( V_6 , type ) ;
V_114 = F_118 ( V_90 ) ;
if ( ! V_114 )
return - 1 ;
V_114 -> V_9 = & V_6 -> V_9 ;
F_95 ( & V_6 -> V_9 , V_90 ) ;
}
return 0 ;
}
void F_30 ( struct V_6 * V_6 )
{
int type ;
for ( type = 0 ; type < V_113 ; ++ type ) {
struct V_114 * V_114 ;
struct V_90 * V_90 = F_117 ( V_6 , type ) ;
if ( V_90 == NULL )
continue;
V_114 = F_118 ( V_90 ) ;
F_119 ( & V_6 -> V_9 , V_90 ) ;
if ( V_114 && V_114 -> V_118 ) {
if ( type == V_29 ) {
F_33 ( ( char * * ) & V_114 -> V_118 -> V_86 ) ;
F_33 ( & V_114 -> V_118 ) ;
} else
V_114 -> V_118 = NULL ;
}
F_96 ( V_6 -> V_22 [ type ] ) ;
V_6 -> V_22 [ type ] = NULL ;
}
}
int F_120 ( struct V_36 * V_36 )
{
int V_93 = 0 ;
struct V_119 * * V_120 = NULL ;
int V_95 , V_121 = 0 ;
char V_44 [ V_45 ] ;
T_1 V_8 ;
char * V_122 ;
if ( V_48 . V_105 ||
V_48 . V_123 ||
V_48 . V_109 ) {
F_121 ( V_36 , V_47 ) ;
}
if ( V_48 . V_49 ) {
V_121 = F_122 ( V_48 . V_49 , & V_120 , NULL , NULL ) ;
if ( V_121 <= 0 )
return - V_124 ;
for ( V_95 = 0 ; V_95 < V_121 ; V_95 ++ ) {
if ( ! isdigit ( V_120 [ V_95 ] -> V_125 [ 0 ] ) ) {
continue;
}
V_8 = ( T_1 ) strtol ( V_120 [ V_95 ] -> V_125 , & V_122 , 10 ) ;
if ( ( * V_122 != '\0' ) ||
( V_122 == V_120 [ V_95 ] -> V_125 ) ||
( V_126 == V_127 ) ) {
F_123 ( L_29 ,
V_120 [ V_95 ] -> V_125 ) ;
continue;
}
sprintf ( V_44 , L_30 ,
V_48 . V_49 ,
V_120 [ V_95 ] -> V_125 ) ;
V_93 = F_42 ( V_44 , V_50 ) ;
if ( V_93 ) {
F_123 ( L_5 , V_44 ) ;
goto V_128;
}
F_121 ( V_36 , V_8 ) ;
}
V_128:
free ( V_120 ) ;
}
return V_93 ;
}
void F_124 ( struct V_36 * V_36 )
{
struct V_10 * V_129 = F_25 ( & V_36 -> V_38 ) ;
F_30 ( & V_36 -> V_37 ) ;
while ( V_129 ) {
struct V_6 * V_31 = F_26 ( V_129 , struct V_6 , V_10 ) ;
V_129 = F_27 ( & V_31 -> V_10 ) ;
F_125 ( & V_31 -> V_10 , & V_36 -> V_38 ) ;
F_15 ( V_31 ) ;
}
}
int F_121 ( struct V_36 * V_36 , T_1 V_8 )
{
struct V_6 * V_6 = F_41 ( V_36 , V_8 ) ;
if ( V_6 == NULL )
return - 1 ;
return F_12 ( V_6 ) ;
}
int F_14 ( struct V_6 * V_6 , const char * V_85 ,
enum V_130 type , bool V_131 )
{
struct V_90 * V_90 = F_104 ( V_6 ) ;
int V_93 = F_126 ( V_90 -> V_30 , V_85 , V_90 , V_131 ) ;
if ( V_93 > 0 ) {
F_127 ( V_90 -> V_30 , type ) ;
F_128 ( & V_6 -> V_9 , type ) ;
}
return V_93 ;
}
int F_129 ( struct V_6 * V_6 , const char * V_85 ,
enum V_130 type )
{
return F_14 ( V_6 , V_85 , type , false ) ;
}
int F_130 ( struct V_6 * V_6 , enum V_130 type )
{
struct V_90 * V_90 = F_104 ( V_6 ) ;
int V_93 = F_131 ( V_90 -> V_30 , V_90 ) ;
if ( V_93 > 0 )
F_127 ( V_90 -> V_30 , type ) ;
return V_93 ;
}
static void F_132 ( struct V_132 * V_62 )
{
int V_95 ;
for ( V_95 = 0 ; V_95 < V_113 ; ++ V_95 )
F_128 ( V_62 , V_95 ) ;
}
static char * F_133 ( const char * V_7 )
{
char V_133 [ V_45 ] ;
T_6 * V_134 ;
char * V_86 , * V_135 ;
const char * V_136 = L_31 ;
sprintf ( V_133 , L_32 , V_7 ) ;
V_134 = fopen ( V_133 , L_33 ) ;
if ( ! V_134 )
return NULL ;
V_133 [ 0 ] = '\0' ;
V_135 = fgets ( V_133 , sizeof( V_133 ) , V_134 ) ;
fclose ( V_134 ) ;
V_86 = strstr ( V_133 , V_136 ) ;
if ( ! V_86 )
return NULL ;
V_86 += strlen ( V_136 ) ;
V_135 = strchr ( V_86 , ' ' ) ;
if ( V_135 )
* V_135 = '\0' ;
return F_7 ( V_86 ) ;
}
static bool F_134 ( struct V_30 * V_30 )
{
return V_30 -> V_137 == V_138 ||
V_30 -> V_137 == V_139 ;
}
static int F_135 ( struct V_132 * V_62 , const char * V_44 ,
struct V_83 * V_84 )
{
struct V_90 * V_90 ;
char * V_89 ;
V_90 = F_93 ( V_62 , V_29 , V_84 -> V_86 ) ;
if ( V_90 == NULL )
return 0 ;
V_89 = F_7 ( V_44 ) ;
if ( V_89 == NULL )
return - V_23 ;
F_82 ( V_90 -> V_30 , V_89 , true ) ;
F_136 ( V_90 -> V_30 , L_2 ) ;
if ( V_84 -> V_140 && F_134 ( V_90 -> V_30 ) )
V_90 -> V_30 -> V_137 ++ ;
return 0 ;
}
static int F_137 ( struct V_132 * V_62 ,
const char * V_141 , int V_142 )
{
struct V_119 * V_143 ;
T_7 * V_144 = F_138 ( V_141 ) ;
int V_93 = 0 ;
if ( ! V_144 ) {
F_123 ( L_34 , V_145 , V_141 ) ;
return - 1 ;
}
while ( ( V_143 = F_139 ( V_144 ) ) != NULL ) {
char V_44 [ V_45 ] ;
struct V_146 V_147 ;
snprintf ( V_44 , sizeof( V_44 ) , L_35 , V_141 , V_143 -> V_125 ) ;
if ( V_146 ( V_44 , & V_147 ) )
continue;
if ( F_140 ( V_147 . V_148 ) ) {
if ( ! strcmp ( V_143 -> V_125 , L_36 ) ||
! strcmp ( V_143 -> V_125 , L_37 ) )
continue;
if ( V_142 == 0 ) {
if ( ! strcmp ( V_143 -> V_125 , L_38 ) ||
! strcmp ( V_143 -> V_125 , L_39 ) )
continue;
}
V_93 = F_137 ( V_62 , V_44 ,
V_142 + 1 ) ;
if ( V_93 < 0 )
goto V_46;
} else {
struct V_83 V_84 ;
V_93 = F_92 ( & V_84 , V_143 -> V_125 ) ;
if ( V_93 )
goto V_46;
if ( V_84 . V_149 )
V_93 = F_135 ( V_62 , V_44 , & V_84 ) ;
free ( V_84 . V_86 ) ;
if ( V_93 )
goto V_46;
}
}
V_46:
F_141 ( V_144 ) ;
return V_93 ;
}
static int F_142 ( struct V_6 * V_6 )
{
char * V_133 ;
char V_150 [ V_45 ] ;
V_133 = F_133 ( V_6 -> V_7 ) ;
if ( ! V_133 )
return - 1 ;
snprintf ( V_150 , sizeof( V_150 ) , L_40 ,
V_6 -> V_7 , V_133 ) ;
free ( V_133 ) ;
return F_137 ( & V_6 -> V_9 , V_150 , 0 ) ;
}
int __weak F_143 ( T_5 * V_91 V_75 ,
const char * V_86 V_75 )
{
return 0 ;
}
static int F_144 ( void * V_151 , const char * V_86 , T_5 V_91 )
{
struct V_6 * V_6 = V_151 ;
struct V_90 * V_90 ;
if ( F_143 ( & V_91 , V_86 ) < 0 )
return - 1 ;
V_90 = F_91 ( V_6 , V_91 , V_86 ) ;
if ( V_90 == NULL )
return - 1 ;
F_136 ( V_90 -> V_30 , V_6 -> V_7 ) ;
return 0 ;
}
static int F_145 ( struct V_6 * V_6 )
{
const char * V_152 ;
char V_44 [ V_45 ] ;
if ( F_50 ( V_6 ) ) {
V_152 = V_48 . V_123 ;
} else {
snprintf ( V_44 , V_45 , L_41 , V_6 -> V_7 ) ;
V_152 = V_44 ;
}
if ( F_114 ( V_152 , L_42 ) )
return - 1 ;
if ( F_146 ( V_152 , V_6 , F_144 ) )
return - 1 ;
if ( ! F_142 ( V_6 ) )
return 0 ;
F_123 ( L_43 ) ;
return 0 ;
}
int F_12 ( struct V_6 * V_6 )
{
struct V_30 * V_102 = F_108 ( V_6 ) ;
const char * V_86 = NULL ;
T_5 V_111 = 0 ;
int V_93 ;
if ( V_102 == NULL )
return - 1 ;
V_93 = F_116 ( V_6 , V_102 ) ;
F_20 ( V_102 ) ;
if ( V_93 < 0 )
return - 1 ;
if ( V_48 . V_153 && F_145 ( V_6 ) < 0 ) {
if ( F_49 ( V_6 ) )
F_123 ( L_44
L_45 ) ;
else
F_123 ( L_46
L_45 , V_6 -> V_8 ) ;
}
F_132 ( & V_6 -> V_9 ) ;
if ( ! F_113 ( V_6 , & V_86 , & V_111 ) ) {
if ( V_86 &&
F_147 ( V_6 -> V_22 , V_86 , V_111 ) ) {
F_30 ( V_6 ) ;
return - 1 ;
}
}
return 0 ;
}
static void F_148 ( struct V_6 * V_6 ,
union V_65 * V_66 )
{
int V_95 ;
for ( V_95 = 0 ; V_95 < V_113 ; V_95 ++ ) {
V_6 -> V_22 [ V_95 ] -> V_91 = V_66 -> V_154 . V_91 ;
V_6 -> V_22 [ V_95 ] -> V_155 = ( V_66 -> V_154 . V_91 +
V_66 -> V_154 . V_156 ) ;
if ( V_6 -> V_22 [ V_95 ] -> V_155 == 0 )
V_6 -> V_22 [ V_95 ] -> V_155 = ~ 0ULL ;
}
}
static bool F_149 ( struct V_6 * V_6 )
{
struct V_30 * V_30 ;
F_150 (dso, &machine->dsos.head, node) {
if ( F_151 ( V_30 ) )
return true ;
}
return false ;
}
static int F_152 ( struct V_6 * V_6 ,
union V_65 * V_66 )
{
struct V_90 * V_90 ;
char V_157 [ V_45 ] ;
enum V_158 V_159 ;
bool V_160 ;
if ( F_149 ( V_6 ) )
return 0 ;
F_48 ( V_6 , V_157 , sizeof( V_157 ) ) ;
if ( F_49 ( V_6 ) )
V_159 = V_104 ;
else
V_159 = V_106 ;
V_160 = memcmp ( V_66 -> V_154 . V_85 ,
V_157 ,
strlen ( V_157 ) - 1 ) == 0 ;
if ( V_66 -> V_154 . V_85 [ 0 ] == '/' ||
( ! V_160 && V_66 -> V_154 . V_85 [ 0 ] == '[' ) ) {
V_90 = F_91 ( V_6 , V_66 -> V_154 . V_91 ,
V_66 -> V_154 . V_85 ) ;
if ( V_90 == NULL )
goto V_161;
V_90 -> V_155 = V_90 -> V_91 + V_66 -> V_154 . V_156 ;
} else if ( V_160 ) {
const char * V_110 = ( V_66 -> V_154 . V_85 +
strlen ( V_157 ) ) ;
struct V_30 * V_102 = NULL ;
struct V_30 * V_30 ;
F_64 ( & V_6 -> V_1 . V_5 ) ;
F_150 (dso, &machine->dsos.head, node) {
if ( ! V_30 -> V_102 ||
F_153 ( V_30 -> V_89 ,
V_162 ) )
continue;
V_102 = V_30 ;
break;
}
F_21 ( & V_6 -> V_1 . V_5 ) ;
if ( V_102 == NULL )
V_102 = F_154 ( V_6 , V_157 ) ;
if ( V_102 == NULL )
goto V_161;
V_102 -> V_102 = V_159 ;
if ( F_116 ( V_6 , V_102 ) < 0 ) {
F_20 ( V_102 ) ;
goto V_161;
}
if ( strstr ( V_102 -> V_89 , L_47 ) )
F_155 ( V_102 , L_48 , false ) ;
F_148 ( V_6 , V_66 ) ;
if ( V_66 -> V_154 . V_163 != 0 ) {
F_147 ( V_6 -> V_22 ,
V_110 ,
V_66 -> V_154 . V_163 ) ;
}
if ( F_50 ( V_6 ) ) {
F_156 ( V_102 , F_104 ( V_6 ) ) ;
}
}
return 0 ;
V_161:
return - 1 ;
}
int F_157 ( struct V_6 * V_6 ,
union V_65 * V_66 ,
struct V_67 * V_68 )
{
struct V_25 * V_25 ;
struct V_90 * V_90 ;
enum V_130 type ;
int V_93 = 0 ;
if ( V_74 )
F_158 ( V_66 , stdout ) ;
if ( V_68 -> V_164 == V_165 ||
V_68 -> V_164 == V_166 ) {
V_93 = F_152 ( V_6 , V_66 ) ;
if ( V_93 < 0 )
goto V_161;
return 0 ;
}
V_25 = F_8 ( V_6 , V_66 -> V_167 . V_8 ,
V_66 -> V_167 . V_60 ) ;
if ( V_25 == NULL )
goto V_161;
if ( V_66 -> V_70 . V_71 & V_168 )
type = V_169 ;
else
type = V_29 ;
V_90 = F_159 ( V_6 , V_66 -> V_167 . V_91 ,
V_66 -> V_167 . V_156 , V_66 -> V_167 . V_163 ,
V_66 -> V_167 . V_8 , V_66 -> V_167 . V_170 ,
V_66 -> V_167 . V_171 , V_66 -> V_167 . V_172 ,
V_66 -> V_167 . V_173 ,
V_66 -> V_167 . V_174 ,
V_66 -> V_167 . V_175 ,
V_66 -> V_167 . V_85 , type , V_25 ) ;
if ( V_90 == NULL )
goto V_176;
V_93 = F_160 ( V_25 , V_90 ) ;
if ( V_93 )
goto V_177;
F_10 ( V_25 ) ;
F_96 ( V_90 ) ;
return 0 ;
V_177:
F_96 ( V_90 ) ;
V_176:
F_10 ( V_25 ) ;
V_161:
F_71 ( L_49 ) ;
return 0 ;
}
int F_161 ( struct V_6 * V_6 , union V_65 * V_66 ,
struct V_67 * V_68 )
{
struct V_25 * V_25 ;
struct V_90 * V_90 ;
enum V_130 type ;
int V_93 = 0 ;
if ( V_74 )
F_162 ( V_66 , stdout ) ;
if ( V_68 -> V_164 == V_165 ||
V_68 -> V_164 == V_166 ) {
V_93 = F_152 ( V_6 , V_66 ) ;
if ( V_93 < 0 )
goto V_161;
return 0 ;
}
V_25 = F_8 ( V_6 , V_66 -> V_154 . V_8 ,
V_66 -> V_154 . V_60 ) ;
if ( V_25 == NULL )
goto V_161;
if ( V_66 -> V_70 . V_71 & V_168 )
type = V_169 ;
else
type = V_29 ;
V_90 = F_159 ( V_6 , V_66 -> V_154 . V_91 ,
V_66 -> V_154 . V_156 , V_66 -> V_154 . V_163 ,
V_66 -> V_154 . V_8 , 0 , 0 , 0 , 0 , 0 , 0 ,
V_66 -> V_154 . V_85 ,
type , V_25 ) ;
if ( V_90 == NULL )
goto V_176;
V_93 = F_160 ( V_25 , V_90 ) ;
if ( V_93 )
goto V_177;
F_10 ( V_25 ) ;
F_96 ( V_90 ) ;
return 0 ;
V_177:
F_96 ( V_90 ) ;
V_176:
F_10 ( V_25 ) ;
V_161:
F_71 ( L_50 ) ;
return 0 ;
}
static void F_28 ( struct V_6 * V_6 , struct V_25 * V_57 , bool V_5 )
{
if ( V_6 -> V_15 == V_57 )
V_6 -> V_15 = NULL ;
F_163 ( F_164 ( & V_57 -> V_178 ) == 0 ) ;
if ( V_5 )
F_17 ( & V_6 -> V_12 ) ;
F_62 ( & V_57 -> V_10 , & V_6 -> V_11 ) ;
F_6 ( & V_57 -> V_10 ) ;
-- V_6 -> V_13 ;
F_165 ( & V_57 -> V_33 , & V_6 -> V_14 ) ;
if ( V_5 )
F_21 ( & V_6 -> V_12 ) ;
F_10 ( V_57 ) ;
}
void F_166 ( struct V_6 * V_6 , struct V_25 * V_57 )
{
return F_28 ( V_6 , V_57 , true ) ;
}
int F_167 ( struct V_6 * V_6 , union V_65 * V_66 ,
struct V_67 * V_68 )
{
struct V_25 * V_25 = F_63 ( V_6 ,
V_66 -> V_179 . V_8 ,
V_66 -> V_179 . V_60 ) ;
struct V_25 * V_40 = F_8 ( V_6 ,
V_66 -> V_179 . V_180 ,
V_66 -> V_179 . V_181 ) ;
int V_73 = 0 ;
if ( V_74 )
F_168 ( V_66 , stdout ) ;
if ( V_40 -> V_59 != ( T_1 ) V_66 -> V_179 . V_180 ) {
F_71 ( L_51 ,
V_40 -> V_59 , V_40 -> V_60 ) ;
F_166 ( V_6 , V_40 ) ;
F_10 ( V_40 ) ;
V_40 = F_8 ( V_6 , V_66 -> V_179 . V_180 ,
V_66 -> V_179 . V_181 ) ;
}
if ( V_25 != NULL ) {
F_166 ( V_6 , V_25 ) ;
F_10 ( V_25 ) ;
}
V_25 = F_8 ( V_6 , V_66 -> V_179 . V_8 ,
V_66 -> V_179 . V_60 ) ;
if ( V_25 == NULL || V_40 == NULL ||
F_169 ( V_25 , V_40 , V_68 -> time ) < 0 ) {
F_71 ( L_52 ) ;
V_73 = - 1 ;
}
F_10 ( V_25 ) ;
F_10 ( V_40 ) ;
return V_73 ;
}
int F_170 ( struct V_6 * V_6 , union V_65 * V_66 ,
struct V_67 * V_68 V_75 )
{
struct V_25 * V_25 = F_63 ( V_6 ,
V_66 -> V_179 . V_8 ,
V_66 -> V_179 . V_60 ) ;
if ( V_74 )
F_168 ( V_66 , stdout ) ;
if ( V_25 != NULL ) {
F_171 ( V_25 ) ;
F_10 ( V_25 ) ;
}
return 0 ;
}
int F_172 ( struct V_6 * V_6 , union V_65 * V_66 ,
struct V_67 * V_68 )
{
int V_93 ;
switch ( V_66 -> V_70 . type ) {
case V_182 :
V_93 = F_68 ( V_6 , V_66 , V_68 ) ; break;
case V_183 :
V_93 = F_161 ( V_6 , V_66 , V_68 ) ; break;
case V_184 :
V_93 = F_72 ( V_6 , V_66 , V_68 ) ; break;
case V_185 :
V_93 = F_157 ( V_6 , V_66 , V_68 ) ; break;
case V_186 :
V_93 = F_167 ( V_6 , V_66 , V_68 ) ; break;
case V_187 :
V_93 = F_170 ( V_6 , V_66 , V_68 ) ; break;
case V_188 :
V_93 = F_76 ( V_6 , V_66 , V_68 ) ; break;
case V_189 :
V_93 = F_84 ( V_6 , V_66 ) ; break;
case V_190 :
V_93 = F_86 ( V_6 , V_66 ) ; break;
case V_191 :
V_93 = F_77 ( V_6 , V_66 , V_68 ) ; break;
case V_192 :
case V_193 :
V_93 = F_88 ( V_6 , V_66 ) ; break;
default:
V_93 = - 1 ;
break;
}
return V_93 ;
}
static bool F_173 ( struct V_194 * V_195 , T_8 * V_196 )
{
if ( ! regexec ( V_196 , V_195 -> V_86 , 0 , NULL , 0 ) )
return 1 ;
return 0 ;
}
static void F_174 ( struct V_25 * V_25 ,
struct V_197 * V_198 ,
T_5 V_199 )
{
struct V_200 V_201 ;
memset ( & V_201 , 0 , sizeof( V_201 ) ) ;
F_175 ( V_25 , V_29 , V_199 , & V_201 ) ;
V_198 -> V_111 = V_199 ;
V_198 -> V_202 = V_201 . V_111 ;
V_198 -> V_195 = V_201 . V_195 ;
V_198 -> V_90 = V_201 . V_90 ;
}
static void F_176 ( struct V_25 * V_25 ,
T_9 V_84 , struct V_197 * V_198 , T_5 V_111 )
{
struct V_200 V_201 ;
memset ( & V_201 , 0 , sizeof( V_201 ) ) ;
F_177 ( V_25 , V_84 , V_169 , V_111 , & V_201 ) ;
if ( V_201 . V_90 == NULL ) {
F_177 ( V_25 , V_84 , V_29 , V_111 , & V_201 ) ;
}
V_198 -> V_111 = V_111 ;
V_198 -> V_202 = V_201 . V_111 ;
V_198 -> V_195 = V_201 . V_195 ;
V_198 -> V_90 = V_201 . V_90 ;
}
struct V_203 * F_178 ( struct V_67 * V_68 ,
struct V_200 * V_201 )
{
struct V_203 * V_204 = F_179 ( sizeof( * V_204 ) ) ;
if ( ! V_204 )
return NULL ;
F_174 ( V_201 -> V_25 , & V_204 -> V_205 , V_68 -> V_199 ) ;
F_176 ( V_201 -> V_25 , V_201 -> V_164 , & V_204 -> V_206 , V_68 -> V_111 ) ;
V_204 -> V_207 . V_208 = V_68 -> V_207 ;
return V_204 ;
}
static int F_180 ( struct V_25 * V_25 ,
struct V_209 * V_210 ,
struct V_194 * * V_40 ,
struct V_200 * V_211 ,
T_9 * V_164 ,
T_5 V_199 ,
bool V_212 ,
struct V_213 * V_175 ,
int V_214 ,
int V_215 )
{
struct V_200 V_201 ;
V_201 . V_216 = 0 ;
V_201 . V_195 = NULL ;
if ( ! V_164 ) {
F_175 ( V_25 , V_29 ,
V_199 , & V_201 ) ;
} else {
if ( V_199 >= V_217 ) {
switch ( V_199 ) {
case V_218 :
* V_164 = V_219 ;
break;
case V_220 :
* V_164 = V_166 ;
break;
case V_221 :
* V_164 = V_222 ;
break;
default:
F_123 ( L_53
L_54 V_223 L_20 , ( V_224 ) V_199 ) ;
F_181 ( V_210 ) ;
return 1 ;
}
return 0 ;
}
F_177 ( V_25 , * V_164 , V_29 ,
V_199 , & V_201 ) ;
}
if ( V_201 . V_195 != NULL ) {
if ( V_225 . V_40 && ! * V_40 &&
F_173 ( V_201 . V_195 , & V_226 ) )
* V_40 = V_201 . V_195 ;
else if ( V_227 && V_211 &&
F_173 ( V_201 . V_195 , & V_228 ) ) {
* V_211 = V_201 ;
F_181 ( V_210 ) ;
}
}
if ( V_48 . V_229 && V_201 . V_195 == NULL )
return 0 ;
return F_182 ( V_210 , V_201 . V_111 , V_201 . V_90 , V_201 . V_195 ,
V_212 , V_175 , V_214 , V_215 ) ;
}
struct V_230 * F_183 ( struct V_67 * V_68 ,
struct V_200 * V_201 )
{
unsigned int V_95 ;
const struct V_231 * V_232 = V_68 -> V_231 ;
struct V_230 * V_233 = calloc ( V_232 -> V_234 , sizeof( struct V_230 ) ) ;
if ( ! V_233 )
return NULL ;
for ( V_95 = 0 ; V_95 < V_232 -> V_234 ; V_95 ++ ) {
F_174 ( V_201 -> V_25 , & V_233 [ V_95 ] . V_235 , V_232 -> V_236 [ V_95 ] . V_235 ) ;
F_174 ( V_201 -> V_25 , & V_233 [ V_95 ] . V_237 , V_232 -> V_236 [ V_95 ] . V_237 ) ;
V_233 [ V_95 ] . V_175 = V_232 -> V_236 [ V_95 ] . V_175 ;
}
return V_233 ;
}
static int F_184 ( struct V_238 * V_239 , int V_234 )
{
int V_95 , V_240 , V_241 ;
unsigned char V_242 [ V_243 ] ;
memset ( V_242 , V_244 , sizeof( V_242 ) ) ;
F_163 ( V_245 > 255 ) ;
for ( V_95 = 0 ; V_95 < V_234 ; V_95 ++ ) {
int V_246 = F_185 ( V_239 [ V_95 ] . V_237 , V_247 ) % V_243 ;
if ( V_242 [ V_246 ] == V_244 ) {
V_242 [ V_246 ] = V_95 ;
} else if ( V_239 [ V_242 [ V_246 ] ] . V_237 == V_239 [ V_95 ] . V_237 ) {
bool V_248 = true ;
V_241 = 0 ;
for ( V_240 = V_242 [ V_246 ] ; V_240 < V_95 && V_95 + V_241 < V_234 ; V_240 ++ , V_241 ++ )
if ( V_239 [ V_240 ] . V_237 != V_239 [ V_95 + V_241 ] . V_237 ) {
V_248 = false ;
break;
}
if ( V_248 ) {
memmove ( V_239 + V_95 , V_239 + V_95 + V_241 ,
( V_234 - ( V_95 + V_241 ) ) * sizeof( * V_239 ) ) ;
V_234 -= V_241 ;
}
}
}
return V_234 ;
}
static int F_186 ( struct V_25 * V_25 ,
struct V_209 * V_210 ,
struct V_67 * V_68 ,
struct V_194 * * V_40 ,
struct V_200 * V_211 ,
int V_249 )
{
struct V_250 * V_251 = V_68 -> V_252 ;
int V_253 = V_171 ( V_249 , ( int ) V_251 -> V_234 ) , V_95 ;
T_9 V_164 = V_222 ;
T_5 V_199 ;
for ( V_95 = 0 ; V_95 < V_253 ; V_95 ++ ) {
if ( V_251 -> V_254 [ V_95 ] == V_221 )
break;
}
if ( V_95 != V_253 ) {
struct V_231 * V_255 = V_68 -> V_231 ;
int V_256 = V_255 -> V_234 , V_240 , V_257 ;
bool V_212 ;
struct V_213 * V_175 ;
int V_258 = V_95 + 1 + V_256 + 1 ;
for ( V_240 = 0 ; V_240 < V_258 ; V_240 ++ ) {
int V_73 ;
V_212 = false ;
V_175 = NULL ;
if ( V_259 . V_260 == V_261 ) {
if ( V_240 < V_95 + 1 )
V_199 = V_251 -> V_254 [ V_240 ] ;
else if ( V_240 > V_95 + 1 ) {
V_257 = V_240 - V_95 - 2 ;
V_199 = V_255 -> V_236 [ V_257 ] . V_237 ;
V_212 = true ;
V_175 = & V_255 -> V_236 [ V_257 ] . V_175 ;
} else {
V_199 = V_255 -> V_236 [ 0 ] . V_235 ;
V_212 = true ;
V_175 = & V_255 -> V_236 [ 0 ] . V_175 ;
}
} else {
if ( V_240 < V_256 ) {
V_257 = V_256 - V_240 - 1 ;
V_199 = V_255 -> V_236 [ V_257 ] . V_237 ;
V_212 = true ;
V_175 = & V_255 -> V_236 [ V_257 ] . V_175 ;
}
else if ( V_240 > V_256 )
V_199 = V_251 -> V_254 [ V_95 + 1 - ( V_240 - V_256 ) ] ;
else {
V_199 = V_255 -> V_236 [ 0 ] . V_235 ;
V_212 = true ;
V_175 = & V_255 -> V_236 [ 0 ] . V_175 ;
}
}
V_73 = F_180 ( V_25 , V_210 , V_40 ,
V_211 , & V_164 , V_199 ,
V_212 , V_175 , 0 , 0 ) ;
if ( V_73 )
return ( V_73 < 0 ) ? V_73 : 0 ;
}
return 1 ;
}
return 0 ;
}
static int F_187 ( struct V_25 * V_25 ,
struct V_209 * V_210 ,
struct V_262 * V_263 ,
struct V_67 * V_68 ,
struct V_194 * * V_40 ,
struct V_200 * V_211 ,
int V_249 )
{
struct V_231 * V_212 = V_68 -> V_231 ;
struct V_250 * V_251 = V_68 -> V_252 ;
int V_253 = V_251 -> V_234 ;
T_9 V_164 = V_222 ;
int V_95 , V_240 , V_73 , V_264 ;
int V_265 = - 1 ;
int V_266 = 0 ;
int V_214 ;
if ( F_188 ( V_263 ) ) {
V_73 = F_186 ( V_25 , V_210 , V_68 , V_40 ,
V_211 , V_249 ) ;
if ( V_73 )
return ( V_73 < 0 ) ? V_73 : 0 ;
}
V_265 = F_189 ( V_25 , V_251 ) ;
if ( V_212 && V_259 . V_267 ) {
int V_234 = V_171 ( V_249 , ( int ) V_212 -> V_234 ) ;
struct V_238 V_268 [ V_234 ] ;
if ( V_212 -> V_234 > V_245 ) {
F_190 ( L_55 ) ;
goto V_269;
}
for ( V_95 = 0 ; V_95 < V_234 ; V_95 ++ ) {
if ( V_259 . V_260 == V_261 ) {
V_268 [ V_95 ] = V_212 -> V_236 [ V_95 ] ;
if ( V_95 == V_265 ||
V_251 -> V_254 [ V_266 ] >= V_217 )
V_266 ++ ;
else if ( V_268 [ V_95 ] . V_237 < V_251 -> V_254 [ V_266 ] &&
V_268 [ V_95 ] . V_237 >= V_251 -> V_254 [ V_266 ] - 8 )
V_266 ++ ;
} else
V_268 [ V_95 ] = V_212 -> V_236 [ V_212 -> V_234 - V_95 - 1 ] ;
}
V_214 = V_234 ;
V_234 = F_184 ( V_268 , V_234 ) ;
if ( V_214 > V_234 )
V_214 = V_214 - V_234 + 1 ;
else
V_214 = 0 ;
for ( V_95 = 0 ; V_95 < V_234 ; V_95 ++ ) {
if ( V_95 == V_234 - 1 )
V_73 = F_180 ( V_25 , V_210 , V_40 ,
V_211 ,
NULL , V_268 [ V_95 ] . V_235 ,
true , & V_268 [ V_95 ] . V_175 ,
V_214 , 1 ) ;
else
V_73 = F_180 ( V_25 , V_210 , V_40 ,
V_211 ,
NULL , V_268 [ V_95 ] . V_235 ,
true , & V_268 [ V_95 ] . V_175 ,
0 , 0 ) ;
if ( ! V_73 )
V_73 = F_180 ( V_25 , V_210 , V_40 , V_211 ,
NULL , V_268 [ V_95 ] . V_237 ,
true , & V_268 [ V_95 ] . V_175 ,
0 , 0 ) ;
if ( V_73 == - V_270 )
break;
if ( V_73 )
return V_73 ;
}
V_253 -= V_234 ;
}
V_269:
for ( V_95 = V_266 , V_264 = 0 ;
V_95 < V_253 && V_264 < V_249 ; V_95 ++ ) {
T_5 V_199 ;
if ( V_259 . V_260 == V_261 )
V_240 = V_95 ;
else
V_240 = V_251 -> V_234 - V_95 - 1 ;
#ifdef F_191
if ( V_240 == V_265 )
continue;
#endif
V_199 = V_251 -> V_254 [ V_240 ] ;
if ( V_199 < V_217 )
++ V_264 ;
V_73 = F_180 ( V_25 , V_210 , V_40 ,
V_211 , & V_164 , V_199 ,
false , NULL , 0 , 0 ) ;
if ( V_73 )
return ( V_73 < 0 ) ? V_73 : 0 ;
}
return 0 ;
}
static int F_192 ( struct F_192 * V_271 , void * V_151 )
{
struct V_209 * V_210 = V_151 ;
if ( V_48 . V_229 && V_271 -> V_195 == NULL )
return 0 ;
return F_182 ( V_210 , V_271 -> V_199 ,
V_271 -> V_90 , V_271 -> V_195 ,
false , NULL , 0 , 0 ) ;
}
static int F_193 ( struct V_25 * V_25 ,
struct V_209 * V_210 ,
struct V_262 * V_263 ,
struct V_67 * V_68 ,
int V_249 )
{
if ( ! ( ( V_263 -> V_272 . V_273 & V_274 ) &&
( V_263 -> V_272 . V_273 & V_275 ) ) )
return 0 ;
if ( ( ! V_68 -> V_276 . V_277 ) ||
( ! V_68 -> V_278 . V_56 ) )
return 0 ;
return F_194 ( F_192 , V_210 ,
V_25 , V_68 , V_249 ) ;
}
int F_195 ( struct V_25 * V_25 ,
struct V_209 * V_210 ,
struct V_262 * V_263 ,
struct V_67 * V_68 ,
struct V_194 * * V_40 ,
struct V_200 * V_211 ,
int V_249 )
{
int V_93 = 0 ;
F_181 ( & V_209 ) ;
if ( V_259 . V_260 == V_261 ) {
V_93 = F_187 ( V_25 , V_210 ,
V_263 , V_68 ,
V_40 , V_211 ,
V_249 ) ;
if ( V_93 )
return V_93 ;
V_93 = F_193 ( V_25 , V_210 ,
V_263 , V_68 ,
V_249 ) ;
} else {
V_93 = F_193 ( V_25 , V_210 ,
V_263 , V_68 ,
V_249 ) ;
if ( V_93 )
return V_93 ;
V_93 = F_187 ( V_25 , V_210 ,
V_263 , V_68 ,
V_40 , V_211 ,
V_249 ) ;
}
return V_93 ;
}
int F_196 ( struct V_6 * V_6 ,
int (* F_197)( struct V_25 * V_25 , void * V_39 ) ,
void * V_279 )
{
struct V_10 * V_34 ;
struct V_25 * V_25 ;
int V_280 = 0 ;
for ( V_34 = F_25 ( & V_6 -> V_11 ) ; V_34 ; V_34 = F_27 ( V_34 ) ) {
V_25 = F_26 ( V_34 , struct V_25 , V_10 ) ;
V_280 = F_197 ( V_25 , V_279 ) ;
if ( V_280 != 0 )
return V_280 ;
}
F_150 (thread, &machine->dead_threads, node) {
V_280 = F_197 ( V_25 , V_279 ) ;
if ( V_280 != 0 )
return V_280 ;
}
return V_280 ;
}
int F_198 ( struct V_36 * V_36 ,
int (* F_197)( struct V_25 * V_25 , void * V_39 ) ,
void * V_279 )
{
struct V_10 * V_34 ;
int V_280 = 0 ;
V_280 = F_196 ( & V_36 -> V_37 , F_197 , V_279 ) ;
if ( V_280 != 0 )
return V_280 ;
for ( V_34 = F_25 ( & V_36 -> V_38 ) ; V_34 ; V_34 = F_27 ( V_34 ) ) {
struct V_6 * V_6 = F_26 ( V_34 , struct V_6 , V_10 ) ;
V_280 = F_196 ( V_6 , F_197 , V_279 ) ;
if ( V_280 != 0 )
return V_280 ;
}
return V_280 ;
}
int F_199 ( struct V_6 * V_6 , struct V_281 * V_282 ,
struct V_283 * V_283 , struct V_284 * V_11 ,
T_10 V_53 , bool V_285 ,
unsigned int V_286 )
{
if ( F_200 ( V_283 ) )
return F_201 ( V_282 , V_11 , V_53 , V_6 , V_285 , V_286 ) ;
else if ( F_202 ( V_283 ) )
return F_203 ( V_282 , V_53 , V_6 , V_285 , V_286 ) ;
return 0 ;
}
T_1 F_204 ( struct V_6 * V_6 , int V_287 )
{
if ( V_287 < 0 || V_287 >= V_288 || ! V_6 -> V_27 )
return - 1 ;
return V_6 -> V_27 [ V_287 ] ;
}
int F_205 ( struct V_6 * V_6 , int V_287 , T_1 V_8 ,
T_1 V_60 )
{
struct V_25 * V_25 ;
if ( V_287 < 0 )
return - V_270 ;
if ( ! V_6 -> V_27 ) {
int V_95 ;
V_6 -> V_27 = calloc ( V_288 , sizeof( T_1 ) ) ;
if ( ! V_6 -> V_27 )
return - V_23 ;
for ( V_95 = 0 ; V_95 < V_288 ; V_95 ++ )
V_6 -> V_27 [ V_95 ] = - 1 ;
}
if ( V_287 >= V_288 ) {
F_45 ( L_56 , V_287 ) ;
F_45 ( L_57 ) ;
return - V_270 ;
}
V_6 -> V_27 [ V_287 ] = V_60 ;
V_25 = F_8 ( V_6 , V_8 , V_60 ) ;
if ( ! V_25 )
return - V_23 ;
V_25 -> V_287 = V_287 ;
F_10 ( V_25 ) ;
return 0 ;
}
int F_206 ( struct V_6 * V_6 )
{
struct V_90 * V_90 = F_104 ( V_6 ) ;
int V_73 = 0 ;
V_6 -> V_21 = 1ULL << 63 ;
if ( V_90 ) {
V_73 = F_207 ( V_90 ) ;
if ( ! V_73 )
V_6 -> V_21 = V_90 -> V_91 ;
}
return V_73 ;
}
struct V_30 * F_154 ( struct V_6 * V_6 , const char * V_85 )
{
return F_208 ( & V_6 -> V_1 , V_85 ) ;
}
char * F_209 ( void * V_289 , unsigned long long * V_290 , char * * V_291 )
{
struct V_6 * V_6 = V_289 ;
struct V_90 * V_90 ;
struct V_194 * V_195 = F_210 ( & V_6 -> V_9 , V_29 , * V_290 , & V_90 ) ;
if ( V_195 == NULL )
return NULL ;
* V_291 = F_211 ( V_90 ) ? ( char * ) V_90 -> V_30 -> V_292 : NULL ;
* V_290 = V_90 -> V_116 ( V_90 , V_195 -> V_91 ) ;
return V_195 -> V_86 ;
}
