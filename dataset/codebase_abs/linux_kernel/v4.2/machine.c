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
V_48 = F_41 ( true , NULL ) ;
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
struct V_85 * F_83 ( struct V_6 * V_6 , T_6 V_86 ,
const char * V_77 )
{
struct V_85 * V_85 = NULL ;
struct V_26 * V_26 ;
struct V_75 V_76 ;
if ( F_84 ( & V_76 , V_77 ) )
return NULL ;
V_85 = F_85 ( & V_6 -> V_9 , V_87 ,
V_76 . V_78 ) ;
if ( V_85 )
goto V_42;
V_26 = F_73 ( V_6 , & V_76 , V_77 ) ;
if ( V_26 == NULL )
goto V_42;
V_85 = F_86 ( V_86 , V_26 , V_87 ) ;
if ( V_85 == NULL )
goto V_42;
F_87 ( & V_6 -> V_9 , V_85 ) ;
V_42:
free ( V_76 . V_78 ) ;
return V_85 ;
}
T_4 F_88 ( struct V_32 * V_32 , T_7 * V_88 )
{
struct V_10 * V_30 ;
T_4 V_89 = F_89 ( & V_32 -> V_33 . V_1 . V_2 , V_88 ) ;
for ( V_30 = F_22 ( & V_32 -> V_34 ) ; V_30 ; V_30 = F_24 ( V_30 ) ) {
struct V_6 * V_27 = F_23 ( V_30 , struct V_6 , V_10 ) ;
V_89 += F_89 ( & V_27 -> V_1 . V_2 , V_88 ) ;
}
return V_89 ;
}
T_4 F_90 ( struct V_6 * V_76 , T_7 * V_88 ,
bool (F_91)( struct V_26 * V_26 , int V_90 ) , int V_90 )
{
return F_92 ( & V_76 -> V_1 . V_2 , V_88 , F_91 , V_90 ) ;
}
T_4 F_93 ( struct V_32 * V_32 , T_7 * V_88 ,
bool (F_91)( struct V_26 * V_26 , int V_90 ) , int V_90 )
{
struct V_10 * V_30 ;
T_4 V_89 = F_90 ( & V_32 -> V_33 , V_88 , F_91 , V_90 ) ;
for ( V_30 = F_22 ( & V_32 -> V_34 ) ; V_30 ; V_30 = F_24 ( V_30 ) ) {
struct V_6 * V_27 = F_23 ( V_30 , struct V_6 , V_10 ) ;
V_89 += F_90 ( V_27 , V_88 , F_91 , V_90 ) ;
}
return V_89 ;
}
T_4 F_94 ( struct V_6 * V_6 , T_7 * V_88 )
{
int V_91 ;
T_4 V_92 = 0 ;
struct V_26 * V_93 = V_6 -> V_94 [ V_87 ] -> V_26 ;
if ( V_93 -> V_95 ) {
char V_77 [ V_41 ] ;
if ( F_95 ( V_93 , V_77 , sizeof( V_77 ) ) )
V_92 += fprintf ( V_88 , L_16 , V_77 ) ;
}
for ( V_91 = 0 ; V_91 < V_96 ; ++ V_91 )
V_92 += fprintf ( V_88 , L_17 ,
V_91 + V_93 -> V_95 , V_97 [ V_91 ] ) ;
return V_92 ;
}
T_4 F_96 ( struct V_6 * V_6 , T_7 * V_88 )
{
T_4 V_89 = 0 ;
struct V_10 * V_30 ;
F_63 ( & V_6 -> V_12 ) ;
for ( V_30 = F_22 ( & V_6 -> V_11 ) ; V_30 ; V_30 = F_24 ( V_30 ) ) {
struct V_22 * V_27 = F_23 ( V_30 , struct V_22 , V_10 ) ;
V_89 += F_97 ( V_27 , V_88 ) ;
}
F_18 ( & V_6 -> V_12 ) ;
return V_89 ;
}
static struct V_26 * F_98 ( struct V_6 * V_6 )
{
const char * V_98 = NULL ;
struct V_26 * V_99 ;
if ( F_47 ( V_6 ) ) {
V_98 = V_44 . V_98 ;
if ( ! V_98 )
V_98 = L_18 ;
V_99 = F_99 ( V_6 , V_98 ,
L_19 , V_100 ) ;
} else {
char V_51 [ V_41 ] ;
if ( F_48 ( V_6 ) )
V_98 = V_44 . V_101 ;
if ( ! V_98 )
V_98 = F_46 ( V_6 , V_51 ,
sizeof( V_51 ) ) ;
V_99 = F_99 ( V_6 , V_98 ,
L_20 ,
V_102 ) ;
}
if ( V_99 != NULL && ( ! V_99 -> V_95 ) )
F_100 ( V_99 , V_6 ) ;
return V_99 ;
}
static void F_101 ( struct V_6 * V_6 , char * V_103 ,
T_4 V_104 )
{
if ( F_48 ( V_6 ) )
F_102 ( V_103 , V_104 , L_21 , V_44 . V_105 ) ;
else
F_102 ( V_103 , V_104 , L_22 , V_6 -> V_7 ) ;
}
static T_6 F_103 ( struct V_6 * V_6 ,
const char * * V_106 )
{
char V_77 [ V_41 ] ;
int V_91 ;
const char * V_78 ;
T_6 V_107 = 0 ;
F_101 ( V_6 , V_77 , V_41 ) ;
if ( F_104 ( V_77 , L_23 ) )
return 0 ;
for ( V_91 = 0 ; ( V_78 = V_108 [ V_91 ] ) != NULL ; V_91 ++ ) {
V_107 = F_105 ( V_77 , V_78 ) ;
if ( V_107 )
break;
}
if ( V_106 )
* V_106 = V_78 ;
return V_107 ;
}
int F_106 ( struct V_6 * V_6 , struct V_26 * V_99 )
{
enum V_109 type ;
T_6 V_86 = F_103 ( V_6 , NULL ) ;
for ( type = 0 ; type < V_110 ; ++ type ) {
struct V_111 * V_111 ;
V_6 -> V_94 [ type ] = F_86 ( V_86 , V_99 , type ) ;
if ( V_6 -> V_94 [ type ] == NULL )
return - 1 ;
V_6 -> V_94 [ type ] -> V_112 =
V_6 -> V_94 [ type ] -> V_113 =
V_114 ;
V_111 = F_107 ( V_6 -> V_94 [ type ] ) ;
if ( ! V_111 )
return - 1 ;
V_111 -> V_9 = & V_6 -> V_9 ;
F_87 ( & V_6 -> V_9 ,
V_6 -> V_94 [ type ] ) ;
}
return 0 ;
}
void F_108 ( struct V_6 * V_6 )
{
enum V_109 type ;
for ( type = 0 ; type < V_110 ; ++ type ) {
struct V_111 * V_111 ;
if ( V_6 -> V_94 [ type ] == NULL )
continue;
V_111 = F_107 ( V_6 -> V_94 [ type ] ) ;
F_109 ( & V_6 -> V_9 ,
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
int F_110 ( struct V_32 * V_32 )
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
F_111 ( V_32 , V_43 ) ;
}
if ( V_44 . V_45 ) {
V_118 = F_112 ( V_44 . V_45 , & V_117 , NULL , NULL ) ;
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
F_113 ( L_24 ,
V_117 [ V_91 ] -> V_122 ) ;
continue;
}
sprintf ( V_40 , L_25 ,
V_44 . V_45 ,
V_117 [ V_91 ] -> V_122 ) ;
V_89 = F_40 ( V_40 , V_46 ) ;
if ( V_89 ) {
F_113 ( L_4 , V_40 ) ;
goto V_125;
}
F_111 ( V_32 , V_8 ) ;
}
V_125:
free ( V_117 ) ;
}
return V_89 ;
}
void F_114 ( struct V_32 * V_32 )
{
struct V_10 * V_126 = F_22 ( & V_32 -> V_34 ) ;
F_108 ( & V_32 -> V_33 ) ;
while ( V_126 ) {
struct V_6 * V_27 = F_23 ( V_126 , struct V_6 , V_10 ) ;
V_126 = F_24 ( & V_27 -> V_10 ) ;
F_115 ( & V_27 -> V_10 , & V_32 -> V_34 ) ;
F_30 ( V_27 ) ;
}
}
int F_111 ( struct V_32 * V_32 , T_1 V_8 )
{
struct V_6 * V_6 = F_39 ( V_32 , V_8 ) ;
if ( V_6 == NULL )
return - 1 ;
return F_12 ( V_6 ) ;
}
int F_116 ( struct V_6 * V_6 , const char * V_77 ,
enum V_109 type , T_2 V_127 )
{
struct V_85 * V_85 = V_6 -> V_94 [ type ] ;
int V_89 = F_117 ( V_85 -> V_26 , V_77 , V_85 , V_127 ) ;
if ( V_89 > 0 ) {
F_118 ( V_85 -> V_26 , type ) ;
F_119 ( & V_6 -> V_9 , type ) ;
}
return V_89 ;
}
int F_120 ( struct V_6 * V_6 , enum V_109 type ,
T_2 V_127 )
{
struct V_85 * V_85 = V_6 -> V_94 [ type ] ;
int V_89 = F_121 ( V_85 -> V_26 , V_85 , V_127 ) ;
if ( V_89 > 0 )
F_118 ( V_85 -> V_26 , type ) ;
return V_89 ;
}
static void F_122 ( struct V_128 * V_58 )
{
int V_91 ;
for ( V_91 = 0 ; V_91 < V_110 ; ++ V_91 )
F_119 ( V_58 , V_91 ) ;
}
static char * F_123 ( const char * V_7 )
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
static bool F_124 ( struct V_26 * V_26 )
{
return V_26 -> V_80 == V_81 ||
V_26 -> V_80 == V_82 ;
}
static int F_125 ( struct V_128 * V_58 , const char * V_40 ,
struct V_75 * V_76 )
{
struct V_85 * V_85 ;
char * V_133 ;
V_85 = F_85 ( V_58 , V_87 , V_76 -> V_78 ) ;
if ( V_85 == NULL )
return 0 ;
V_133 = F_7 ( V_40 ) ;
if ( V_133 == NULL )
return - V_20 ;
F_77 ( V_85 -> V_26 , V_133 , true ) ;
F_126 ( V_85 -> V_26 , L_2 ) ;
if ( V_76 -> V_84 && F_124 ( V_85 -> V_26 ) )
V_85 -> V_26 -> V_80 ++ ;
return 0 ;
}
static int F_127 ( struct V_128 * V_58 ,
const char * V_134 , int V_135 )
{
struct V_116 * V_136 ;
T_8 * V_137 = F_128 ( V_134 ) ;
int V_89 = 0 ;
if ( ! V_137 ) {
F_113 ( L_29 , V_138 , V_134 ) ;
return - 1 ;
}
while ( ( V_136 = F_129 ( V_137 ) ) != NULL ) {
char V_40 [ V_41 ] ;
struct V_139 V_140 ;
snprintf ( V_40 , sizeof( V_40 ) , L_30 , V_134 , V_136 -> V_122 ) ;
if ( V_139 ( V_40 , & V_140 ) )
continue;
if ( F_130 ( V_140 . V_141 ) ) {
if ( ! strcmp ( V_136 -> V_122 , L_31 ) ||
! strcmp ( V_136 -> V_122 , L_32 ) )
continue;
if ( V_135 == 0 ) {
if ( ! strcmp ( V_136 -> V_122 , L_33 ) ||
! strcmp ( V_136 -> V_122 , L_34 ) )
continue;
}
V_89 = F_127 ( V_58 , V_40 ,
V_135 + 1 ) ;
if ( V_89 < 0 )
goto V_42;
} else {
struct V_75 V_76 ;
V_89 = F_84 ( & V_76 , V_136 -> V_122 ) ;
if ( V_89 )
goto V_42;
if ( V_76 . V_83 )
V_89 = F_125 ( V_58 , V_40 , & V_76 ) ;
free ( V_76 . V_78 ) ;
if ( V_89 )
goto V_42;
}
}
V_42:
F_131 ( V_137 ) ;
return V_89 ;
}
static int F_132 ( struct V_6 * V_6 )
{
char * V_129 ;
char V_142 [ V_41 ] ;
V_129 = F_123 ( V_6 -> V_7 ) ;
if ( ! V_129 )
return - 1 ;
snprintf ( V_142 , sizeof( V_142 ) , L_35 ,
V_6 -> V_7 , V_129 ) ;
free ( V_129 ) ;
return F_127 ( & V_6 -> V_9 , V_142 , 0 ) ;
}
static int F_133 ( void * V_143 , const char * V_78 , T_6 V_86 )
{
struct V_6 * V_6 = V_143 ;
struct V_85 * V_85 ;
V_85 = F_83 ( V_6 , V_86 , V_78 ) ;
if ( V_85 == NULL )
return - 1 ;
F_126 ( V_85 -> V_26 , V_6 -> V_7 ) ;
return 0 ;
}
static int F_134 ( struct V_6 * V_6 )
{
const char * V_144 ;
char V_40 [ V_41 ] ;
if ( F_48 ( V_6 ) ) {
V_144 = V_44 . V_120 ;
} else {
snprintf ( V_40 , V_41 , L_36 , V_6 -> V_7 ) ;
V_144 = V_40 ;
}
if ( F_104 ( V_144 , L_37 ) )
return - 1 ;
if ( F_135 ( V_144 , V_6 , F_133 ) )
return - 1 ;
if ( ! F_132 ( V_6 ) )
return 0 ;
F_113 ( L_38 ) ;
return 0 ;
}
int F_12 ( struct V_6 * V_6 )
{
struct V_26 * V_99 = F_98 ( V_6 ) ;
const char * V_78 ;
T_6 V_107 = F_103 ( V_6 , & V_78 ) ;
if ( ! V_107 )
return - 1 ;
if ( V_99 == NULL ||
F_106 ( V_6 , V_99 ) < 0 )
return - 1 ;
if ( V_44 . V_145 && F_134 ( V_6 ) < 0 ) {
if ( F_47 ( V_6 ) )
F_113 ( L_39
L_40 ) ;
else
F_113 ( L_41
L_40 , V_6 -> V_8 ) ;
}
F_122 ( & V_6 -> V_9 ) ;
if ( F_136 ( V_6 -> V_94 , V_78 ,
V_107 ) ) {
F_108 ( V_6 ) ;
return - 1 ;
}
return 0 ;
}
static void F_137 ( struct V_6 * V_6 ,
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
static bool F_138 ( struct V_6 * V_6 )
{
struct V_26 * V_26 ;
F_139 (dso, &machine->dsos.head, node) {
if ( F_140 ( V_26 ) )
return true ;
}
return false ;
}
static int F_141 ( struct V_6 * V_6 ,
union V_60 * V_61 )
{
struct V_85 * V_85 ;
char V_149 [ V_41 ] ;
enum V_150 V_151 ;
bool V_152 ;
if ( F_138 ( V_6 ) )
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
V_85 = F_83 ( V_6 , V_61 -> V_146 . V_86 ,
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
F_139 (dso, &machine->dsos.head, node) {
if ( ! V_26 -> V_99 ||
F_142 ( V_26 -> V_133 ,
V_154 ) )
continue;
V_99 = V_26 ;
break;
}
F_18 ( & V_6 -> V_1 . V_5 ) ;
if ( V_99 == NULL )
V_99 = F_143 ( V_6 , V_149 ) ;
if ( V_99 == NULL )
goto V_153;
V_99 -> V_99 = V_151 ;
if ( F_106 ( V_6 , V_99 ) < 0 ) {
F_17 ( V_99 ) ;
goto V_153;
}
if ( strstr ( V_99 -> V_133 , L_42 ) )
F_76 ( V_99 , L_43 , false ) ;
F_137 ( V_6 , V_61 ) ;
if ( V_61 -> V_146 . V_155 != 0 ) {
F_136 ( V_6 -> V_94 ,
V_106 ,
V_61 -> V_146 . V_155 ) ;
}
if ( F_48 ( V_6 ) ) {
F_144 ( V_99 , V_6 -> V_94 [ V_87 ] ,
NULL ) ;
}
}
return 0 ;
V_153:
return - 1 ;
}
int F_145 ( struct V_6 * V_6 ,
union V_60 * V_61 ,
struct V_62 * V_63 V_70 )
{
T_9 V_156 = V_61 -> V_65 . V_66 & V_157 ;
struct V_22 * V_22 ;
struct V_85 * V_85 ;
enum V_109 type ;
int V_89 = 0 ;
if ( V_69 )
F_146 ( V_61 , stdout ) ;
if ( V_156 == V_158 ||
V_156 == V_159 ) {
V_89 = F_141 ( V_6 , V_61 ) ;
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
V_85 = F_147 ( V_6 , V_61 -> V_160 . V_86 ,
V_61 -> V_160 . V_148 , V_61 -> V_160 . V_155 ,
V_61 -> V_160 . V_8 , V_61 -> V_160 . V_163 ,
V_61 -> V_160 . V_164 , V_61 -> V_160 . V_165 ,
V_61 -> V_160 . V_166 ,
V_61 -> V_160 . V_167 ,
V_61 -> V_160 . V_168 ,
V_61 -> V_160 . V_77 , type , V_22 ) ;
if ( V_85 == NULL )
goto V_169;
F_148 ( V_22 , V_85 ) ;
F_10 ( V_22 ) ;
F_149 ( V_85 ) ;
return 0 ;
V_169:
F_10 ( V_22 ) ;
V_153:
F_70 ( L_44 ) ;
return 0 ;
}
int F_150 ( struct V_6 * V_6 , union V_60 * V_61 ,
struct V_62 * V_63 V_70 )
{
T_9 V_156 = V_61 -> V_65 . V_66 & V_157 ;
struct V_22 * V_22 ;
struct V_85 * V_85 ;
enum V_109 type ;
int V_89 = 0 ;
if ( V_69 )
F_151 ( V_61 , stdout ) ;
if ( V_156 == V_158 ||
V_156 == V_159 ) {
V_89 = F_141 ( V_6 , V_61 ) ;
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
V_85 = F_147 ( V_6 , V_61 -> V_146 . V_86 ,
V_61 -> V_146 . V_148 , V_61 -> V_146 . V_155 ,
V_61 -> V_146 . V_8 , 0 , 0 , 0 , 0 , 0 , 0 ,
V_61 -> V_146 . V_77 ,
type , V_22 ) ;
if ( V_85 == NULL )
goto V_169;
F_148 ( V_22 , V_85 ) ;
F_10 ( V_22 ) ;
F_149 ( V_85 ) ;
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
F_152 ( F_153 ( & V_53 -> V_170 ) == 0 ) ;
if ( V_5 )
F_14 ( & V_6 -> V_12 ) ;
F_59 ( & V_53 -> V_10 , & V_6 -> V_11 ) ;
F_6 ( & V_53 -> V_10 ) ;
F_154 ( & V_53 -> V_29 , & V_6 -> V_13 ) ;
if ( V_5 )
F_18 ( & V_6 -> V_12 ) ;
F_10 ( V_53 ) ;
}
void F_155 ( struct V_6 * V_6 , struct V_22 * V_53 )
{
return F_25 ( V_6 , V_53 , true ) ;
}
int F_156 ( struct V_6 * V_6 , union V_60 * V_61 ,
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
F_157 ( V_61 , stdout ) ;
if ( V_36 -> V_55 != ( T_1 ) V_61 -> V_171 . V_172 ) {
F_70 ( L_46 ,
V_36 -> V_55 , V_36 -> V_56 ) ;
F_155 ( V_6 , V_36 ) ;
F_10 ( V_36 ) ;
V_36 = F_8 ( V_6 , V_61 -> V_171 . V_172 ,
V_61 -> V_171 . V_173 ) ;
}
if ( V_22 != NULL ) {
F_155 ( V_6 , V_22 ) ;
F_10 ( V_22 ) ;
}
V_22 = F_8 ( V_6 , V_61 -> V_171 . V_8 ,
V_61 -> V_171 . V_56 ) ;
if ( V_22 == NULL || V_36 == NULL ||
F_158 ( V_22 , V_36 , V_63 -> time ) < 0 ) {
F_70 ( L_47 ) ;
V_68 = - 1 ;
}
F_10 ( V_22 ) ;
F_10 ( V_36 ) ;
return V_68 ;
}
int F_159 ( struct V_6 * V_6 , union V_60 * V_61 ,
struct V_62 * V_63 V_70 )
{
struct V_22 * V_22 = F_62 ( V_6 ,
V_61 -> V_171 . V_8 ,
V_61 -> V_171 . V_56 ) ;
if ( V_69 )
F_157 ( V_61 , stdout ) ;
if ( V_22 != NULL ) {
F_160 ( V_22 ) ;
F_10 ( V_22 ) ;
}
return 0 ;
}
int F_161 ( struct V_6 * V_6 , union V_60 * V_61 ,
struct V_62 * V_63 )
{
int V_89 ;
switch ( V_61 -> V_65 . type ) {
case V_174 :
V_89 = F_67 ( V_6 , V_61 , V_63 ) ; break;
case V_175 :
V_89 = F_150 ( V_6 , V_61 , V_63 ) ; break;
case V_176 :
V_89 = F_145 ( V_6 , V_61 , V_63 ) ; break;
case V_177 :
V_89 = F_156 ( V_6 , V_61 , V_63 ) ; break;
case V_178 :
V_89 = F_159 ( V_6 , V_61 , V_63 ) ; break;
case V_179 :
V_89 = F_71 ( V_6 , V_61 , V_63 ) ; break;
case V_180 :
V_89 = F_79 ( V_6 , V_61 ) ; break;
case V_181 :
V_89 = F_81 ( V_6 , V_61 ) ; break;
case V_182 :
V_89 = F_72 ( V_6 , V_61 , V_63 ) ; break;
default:
V_89 = - 1 ;
break;
}
return V_89 ;
}
static bool F_162 ( struct V_183 * V_184 , T_10 * V_185 )
{
if ( V_184 -> V_78 && ! regexec ( V_185 , V_184 -> V_78 , 0 , NULL , 0 ) )
return 1 ;
return 0 ;
}
static void F_163 ( struct V_22 * V_22 ,
struct V_186 * V_187 ,
T_6 V_188 )
{
struct V_189 V_190 ;
memset ( & V_190 , 0 , sizeof( V_190 ) ) ;
F_164 ( V_22 , V_87 , V_188 , & V_190 ) ;
V_187 -> V_107 = V_188 ;
V_187 -> V_191 = V_190 . V_107 ;
V_187 -> V_184 = V_190 . V_184 ;
V_187 -> V_85 = V_190 . V_85 ;
}
static void F_165 ( struct V_22 * V_22 ,
T_9 V_76 , struct V_186 * V_187 , T_6 V_107 )
{
struct V_189 V_190 ;
memset ( & V_190 , 0 , sizeof( V_190 ) ) ;
F_166 ( V_22 , V_76 , V_162 , V_107 , & V_190 ) ;
if ( V_190 . V_85 == NULL ) {
F_166 ( V_22 , V_76 , V_87 , V_107 , & V_190 ) ;
}
V_187 -> V_107 = V_107 ;
V_187 -> V_191 = V_190 . V_107 ;
V_187 -> V_184 = V_190 . V_184 ;
V_187 -> V_85 = V_190 . V_85 ;
}
struct V_192 * F_167 ( struct V_62 * V_63 ,
struct V_189 * V_190 )
{
struct V_192 * V_193 = F_168 ( sizeof( * V_193 ) ) ;
if ( ! V_193 )
return NULL ;
F_163 ( V_190 -> V_22 , & V_193 -> V_194 , V_63 -> V_188 ) ;
F_165 ( V_190 -> V_22 , V_190 -> V_156 , & V_193 -> V_195 , V_63 -> V_107 ) ;
V_193 -> V_196 . V_197 = V_63 -> V_196 ;
return V_193 ;
}
static int F_169 ( struct V_22 * V_22 ,
struct V_183 * * V_36 ,
struct V_189 * V_198 ,
T_9 * V_156 ,
T_6 V_188 )
{
struct V_189 V_190 ;
V_190 . V_199 = 0 ;
V_190 . V_184 = NULL ;
if ( ! V_156 ) {
F_164 ( V_22 , V_87 ,
V_188 , & V_190 ) ;
} else {
if ( V_188 >= V_200 ) {
switch ( V_188 ) {
case V_201 :
* V_156 = V_202 ;
break;
case V_203 :
* V_156 = V_159 ;
break;
case V_204 :
* V_156 = V_205 ;
break;
default:
F_113 ( L_48
L_49 V_206 L_14 , ( V_207 ) V_188 ) ;
F_170 ( & V_208 ) ;
return 1 ;
}
return 0 ;
}
F_166 ( V_22 , * V_156 , V_87 ,
V_188 , & V_190 ) ;
}
if ( V_190 . V_184 != NULL ) {
if ( V_209 && ! * V_36 &&
F_162 ( V_190 . V_184 , & V_210 ) )
* V_36 = V_190 . V_184 ;
else if ( V_211 && V_198 &&
F_162 ( V_190 . V_184 , & V_212 ) ) {
* V_198 = V_190 ;
F_170 ( & V_208 ) ;
}
}
return F_171 ( & V_208 , V_190 . V_107 , V_190 . V_85 , V_190 . V_184 ) ;
}
struct V_213 * F_172 ( struct V_62 * V_63 ,
struct V_189 * V_190 )
{
unsigned int V_91 ;
const struct V_214 * V_215 = V_63 -> V_214 ;
struct V_213 * V_216 = calloc ( V_215 -> V_217 , sizeof( struct V_213 ) ) ;
if ( ! V_216 )
return NULL ;
for ( V_91 = 0 ; V_91 < V_215 -> V_217 ; V_91 ++ ) {
F_163 ( V_190 -> V_22 , & V_216 [ V_91 ] . V_218 , V_215 -> V_219 [ V_91 ] . V_218 ) ;
F_163 ( V_190 -> V_22 , & V_216 [ V_91 ] . V_220 , V_215 -> V_219 [ V_91 ] . V_220 ) ;
V_216 [ V_91 ] . V_168 = V_215 -> V_219 [ V_91 ] . V_168 ;
}
return V_216 ;
}
static int F_173 ( struct V_221 * V_222 , int V_217 )
{
int V_91 , V_223 , V_224 ;
unsigned char V_225 [ V_226 ] ;
memset ( V_225 , V_227 , sizeof( V_225 ) ) ;
F_152 ( V_228 > 255 ) ;
for ( V_91 = 0 ; V_91 < V_217 ; V_91 ++ ) {
int V_229 = F_174 ( V_222 [ V_91 ] . V_220 , V_230 ) % V_226 ;
if ( V_225 [ V_229 ] == V_227 ) {
V_225 [ V_229 ] = V_91 ;
} else if ( V_222 [ V_225 [ V_229 ] ] . V_220 == V_222 [ V_91 ] . V_220 ) {
bool V_231 = true ;
V_224 = 0 ;
for ( V_223 = V_225 [ V_229 ] ; V_223 < V_91 && V_91 + V_224 < V_217 ; V_223 ++ , V_224 ++ )
if ( V_222 [ V_223 ] . V_220 != V_222 [ V_91 + V_224 ] . V_220 ) {
V_231 = false ;
break;
}
if ( V_231 ) {
memmove ( V_222 + V_91 , V_222 + V_91 + V_224 ,
( V_217 - ( V_91 + V_224 ) ) * sizeof( * V_222 ) ) ;
V_217 -= V_224 ;
}
}
}
return V_217 ;
}
static int F_175 ( struct V_22 * V_22 ,
struct V_62 * V_63 ,
struct V_183 * * V_36 ,
struct V_189 * V_198 ,
int V_232 )
{
struct V_233 * V_234 = V_63 -> V_235 ;
int V_236 = V_164 ( V_232 , ( int ) V_234 -> V_217 ) ;
T_9 V_156 = V_205 ;
int V_91 , V_223 , V_68 ;
T_6 V_188 ;
for ( V_91 = 0 ; V_91 < V_236 ; V_91 ++ ) {
if ( V_234 -> V_237 [ V_91 ] == V_204 )
break;
}
if ( V_91 != V_236 ) {
struct V_214 * V_238 = V_63 -> V_214 ;
int V_239 = V_238 -> V_217 ;
int V_240 = V_91 + 1 + V_239 + 1 ;
if ( V_240 > V_241 + V_228 ) {
F_176 ( L_50 ) ;
return 0 ;
}
for ( V_223 = 0 ; V_223 < V_240 ; V_223 ++ ) {
if ( V_242 . V_243 == V_244 ) {
if ( V_223 < V_91 + 1 )
V_188 = V_234 -> V_237 [ V_223 ] ;
else if ( V_223 > V_91 + 1 )
V_188 = V_238 -> V_219 [ V_223 - V_91 - 2 ] . V_220 ;
else
V_188 = V_238 -> V_219 [ 0 ] . V_218 ;
} else {
if ( V_223 < V_239 )
V_188 = V_238 -> V_219 [ V_239 - V_223 - 1 ] . V_220 ;
else if ( V_223 > V_239 )
V_188 = V_234 -> V_237 [ V_91 + 1 - ( V_223 - V_239 ) ] ;
else
V_188 = V_238 -> V_219 [ 0 ] . V_218 ;
}
V_68 = F_169 ( V_22 , V_36 , V_198 , & V_156 , V_188 ) ;
if ( V_68 )
return ( V_68 < 0 ) ? V_68 : 0 ;
}
return 1 ;
}
return 0 ;
}
static int F_177 ( struct V_22 * V_22 ,
struct V_245 * V_246 ,
struct V_62 * V_63 ,
struct V_183 * * V_36 ,
struct V_189 * V_198 ,
int V_232 )
{
struct V_214 * V_247 = V_63 -> V_214 ;
struct V_233 * V_234 = V_63 -> V_235 ;
int V_236 = V_164 ( V_232 , ( int ) V_234 -> V_217 ) ;
T_9 V_156 = V_205 ;
int V_91 , V_223 , V_68 ;
int V_248 = - 1 ;
int V_249 = 0 ;
F_170 ( & V_208 ) ;
if ( F_178 ( V_246 ) ) {
V_68 = F_175 ( V_22 , V_63 , V_36 ,
V_198 , V_232 ) ;
if ( V_68 )
return ( V_68 < 0 ) ? V_68 : 0 ;
}
if ( V_234 -> V_217 < V_241 )
V_248 = F_179 ( V_22 , V_234 ) ;
if ( V_247 && V_242 . V_250 ) {
int V_217 = V_164 ( V_232 , ( int ) V_247 -> V_217 ) ;
struct V_221 V_251 [ V_217 ] ;
if ( V_247 -> V_217 > V_228 ) {
F_176 ( L_51 ) ;
goto V_252;
}
for ( V_91 = 0 ; V_91 < V_217 ; V_91 ++ ) {
if ( V_242 . V_243 == V_244 ) {
V_251 [ V_91 ] = V_247 -> V_219 [ V_91 ] ;
if ( V_91 == V_248 ||
V_234 -> V_237 [ V_249 ] >= V_200 )
V_249 ++ ;
else if ( V_251 [ V_91 ] . V_220 < V_234 -> V_237 [ V_249 ] &&
V_251 [ V_91 ] . V_220 >= V_234 -> V_237 [ V_249 ] - 8 )
V_249 ++ ;
} else
V_251 [ V_91 ] = V_247 -> V_219 [ V_247 -> V_217 - V_91 - 1 ] ;
}
V_217 = F_173 ( V_251 , V_217 ) ;
for ( V_91 = 0 ; V_91 < V_217 ; V_91 ++ ) {
V_68 = F_169 ( V_22 , V_36 , V_198 ,
NULL , V_251 [ V_91 ] . V_218 ) ;
if ( ! V_68 )
V_68 = F_169 ( V_22 , V_36 , V_198 ,
NULL , V_251 [ V_91 ] . V_220 ) ;
if ( V_68 == - V_253 )
break;
if ( V_68 )
return V_68 ;
}
V_236 -= V_217 ;
}
V_252:
if ( V_234 -> V_217 > V_241 ) {
F_176 ( L_50 ) ;
return 0 ;
}
for ( V_91 = V_249 ; V_91 < V_236 ; V_91 ++ ) {
T_6 V_188 ;
if ( V_242 . V_243 == V_244 )
V_223 = V_91 ;
else
V_223 = V_234 -> V_217 - V_91 - 1 ;
#ifdef F_180
if ( V_223 == V_248 )
continue;
#endif
V_188 = V_234 -> V_237 [ V_223 ] ;
V_68 = F_169 ( V_22 , V_36 , V_198 , & V_156 , V_188 ) ;
if ( V_68 )
return ( V_68 < 0 ) ? V_68 : 0 ;
}
return 0 ;
}
static int F_181 ( struct F_181 * V_254 , void * V_143 )
{
struct V_208 * V_255 = V_143 ;
return F_171 ( V_255 , V_254 -> V_188 ,
V_254 -> V_85 , V_254 -> V_184 ) ;
}
int F_182 ( struct V_22 * V_22 ,
struct V_245 * V_246 ,
struct V_62 * V_63 ,
struct V_183 * * V_36 ,
struct V_189 * V_198 ,
int V_232 )
{
int V_89 = F_177 ( V_22 , V_246 ,
V_63 , V_36 ,
V_198 , V_232 ) ;
if ( V_89 )
return V_89 ;
if ( ! ( ( V_246 -> V_256 . V_257 & V_258 ) &&
( V_246 -> V_256 . V_257 & V_259 ) ) )
return 0 ;
if ( ( ! V_63 -> V_260 . V_261 ) ||
( ! V_63 -> V_262 . V_52 ) )
return 0 ;
return F_183 ( F_181 , & V_208 ,
V_22 , V_63 , V_232 ) ;
}
int F_184 ( struct V_6 * V_6 ,
int (* F_185)( struct V_22 * V_22 , void * V_35 ) ,
void * V_263 )
{
struct V_10 * V_30 ;
struct V_22 * V_22 ;
int V_264 = 0 ;
for ( V_30 = F_22 ( & V_6 -> V_11 ) ; V_30 ; V_30 = F_24 ( V_30 ) ) {
V_22 = F_23 ( V_30 , struct V_22 , V_10 ) ;
V_264 = F_185 ( V_22 , V_263 ) ;
if ( V_264 != 0 )
return V_264 ;
}
F_139 (thread, &machine->dead_threads, node) {
V_264 = F_185 ( V_22 , V_263 ) ;
if ( V_264 != 0 )
return V_264 ;
}
return V_264 ;
}
int F_186 ( struct V_32 * V_32 ,
int (* F_185)( struct V_22 * V_22 , void * V_35 ) ,
void * V_263 )
{
struct V_10 * V_30 ;
int V_264 = 0 ;
V_264 = F_184 ( & V_32 -> V_33 , F_185 , V_263 ) ;
if ( V_264 != 0 )
return V_264 ;
for ( V_30 = F_22 ( & V_32 -> V_34 ) ; V_30 ; V_30 = F_24 ( V_30 ) ) {
struct V_6 * V_6 = F_23 ( V_30 , struct V_6 , V_10 ) ;
V_264 = F_184 ( V_6 , F_185 , V_263 ) ;
if ( V_264 != 0 )
return V_264 ;
}
return V_264 ;
}
int F_187 ( struct V_6 * V_6 , struct V_265 * V_266 ,
struct V_267 * V_267 , struct V_268 * V_11 ,
T_11 V_49 , bool V_269 ,
unsigned int V_270 )
{
if ( F_188 ( V_267 ) )
return F_189 ( V_266 , V_11 , V_49 , V_6 , V_269 , V_270 ) ;
else if ( F_190 ( V_267 ) )
return F_191 ( V_266 , V_49 , V_6 , V_269 , V_270 ) ;
return 0 ;
}
T_1 F_192 ( struct V_6 * V_6 , int V_271 )
{
if ( V_271 < 0 || V_271 >= V_272 || ! V_6 -> V_24 )
return - 1 ;
return V_6 -> V_24 [ V_271 ] ;
}
int F_193 ( struct V_6 * V_6 , int V_271 , T_1 V_8 ,
T_1 V_56 )
{
struct V_22 * V_22 ;
if ( V_271 < 0 )
return - V_253 ;
if ( ! V_6 -> V_24 ) {
int V_91 ;
V_6 -> V_24 = calloc ( V_272 , sizeof( T_1 ) ) ;
if ( ! V_6 -> V_24 )
return - V_20 ;
for ( V_91 = 0 ; V_91 < V_272 ; V_91 ++ )
V_6 -> V_24 [ V_91 ] = - 1 ;
}
if ( V_271 >= V_272 ) {
F_43 ( L_52 , V_271 ) ;
F_43 ( L_53 ) ;
return - V_253 ;
}
V_6 -> V_24 [ V_271 ] = V_56 ;
V_22 = F_8 ( V_6 , V_8 , V_56 ) ;
if ( ! V_22 )
return - V_20 ;
V_22 -> V_271 = V_271 ;
F_10 ( V_22 ) ;
return 0 ;
}
int F_194 ( struct V_6 * V_6 )
{
struct V_85 * V_85 = F_195 ( V_6 , V_87 ) ;
int V_68 = 0 ;
V_6 -> V_19 = 1ULL << 63 ;
if ( V_85 ) {
V_68 = F_196 ( V_85 , V_6 -> V_16 ) ;
if ( V_85 -> V_86 )
V_6 -> V_19 = V_85 -> V_86 ;
}
return V_68 ;
}
struct V_26 * F_143 ( struct V_6 * V_6 , const char * V_77 )
{
return F_197 ( & V_6 -> V_1 , V_77 ) ;
}
