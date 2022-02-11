char F_1 ( const struct V_1 * V_1 )
{
static const char V_2 [] = {
[ V_3 ] = 'k' ,
[ V_4 ] = 'v' ,
[ V_5 ] = 'j' ,
[ V_6 ] = 'l' ,
[ V_7 ] = 'B' ,
[ V_8 ] = 'f' ,
[ V_9 ] = 'u' ,
[ V_10 ] = 'o' ,
[ V_11 ] = 'b' ,
[ V_12 ] = 'd' ,
[ V_13 ] = 'K' ,
[ V_14 ] = 'g' ,
[ V_15 ] = 'G' ,
[ V_16 ] = 'V' ,
} ;
if ( V_1 == NULL || V_1 -> V_17 == V_18 )
return '!' ;
return V_2 [ V_1 -> V_17 ] ;
}
int F_2 ( const struct V_1 * V_1 ,
enum V_19 type ,
char * V_20 , char * V_21 , T_1 V_22 )
{
char V_23 [ V_24 * 2 + 1 ] ;
int V_25 = 0 ;
switch ( type ) {
case V_6 : {
char * V_26 ;
strncpy ( V_21 , V_1 -> V_27 , V_22 ) ;
V_26 = V_21 + V_1 -> V_28 ;
while ( V_26 != V_21 && * V_26 != '/' )
V_26 -- ;
if ( * V_26 == '/' )
V_26 ++ ;
V_25 = F_3 ( V_1 -> V_27 , V_26 ,
V_22 - ( V_26 - V_21 ) ) ;
}
break;
case V_7 :
if ( V_29 . V_30 [ 0 ] ||
( F_4 ( V_1 , V_21 , V_22 ) == NULL ) )
V_25 = - 1 ;
break;
case V_8 :
snprintf ( V_21 , V_22 , L_1 ,
V_29 . V_30 , V_1 -> V_27 ) ;
break;
case V_9 :
snprintf ( V_21 , V_22 , L_2 ,
V_29 . V_30 , V_1 -> V_27 ) ;
break;
case V_10 :
{
const char * V_31 ;
T_1 V_32 ;
T_1 V_33 ;
V_31 = V_1 -> V_27 + V_1 -> V_28 ;
while ( V_31 != V_1 -> V_27 && * V_31 != '/' )
V_31 -- ;
V_32 = F_5 ( V_21 , V_22 , L_3 , V_29 . V_30 ) ;
V_33 = V_31 - V_1 -> V_27 + 2 ;
if ( V_33 > ( V_22 - V_32 ) ) {
V_25 = - 1 ;
break;
}
V_32 += F_5 ( V_21 + V_32 , V_33 , L_3 , V_1 -> V_27 ) ;
V_32 += F_5 ( V_21 + V_32 , V_22 - V_32 , L_4 ,
V_31 ) ;
break;
}
case V_11 :
if ( ! V_1 -> V_34 ) {
V_25 = - 1 ;
break;
}
F_6 ( V_1 -> V_35 ,
sizeof( V_1 -> V_35 ) ,
V_23 ) ;
snprintf ( V_21 , V_22 ,
L_5 ,
V_29 . V_30 , V_23 , V_23 + 2 ) ;
break;
case V_4 :
case V_16 :
case V_12 :
snprintf ( V_21 , V_22 , L_6 ,
V_29 . V_30 , V_1 -> V_27 ) ;
break;
case V_15 :
snprintf ( V_21 , V_22 , L_7 , V_29 . V_30 ,
V_20 , V_1 -> V_27 ) ;
break;
case V_13 :
snprintf ( V_21 , V_22 , L_6 , V_29 . V_30 ,
V_1 -> V_27 ) ;
break;
case V_36 :
case V_37 :
snprintf ( V_21 , V_22 , L_3 , V_1 -> V_27 ) ;
break;
default:
case V_3 :
case V_14 :
case V_5 :
case V_18 :
V_25 = - 1 ;
break;
}
return V_25 ;
}
static int F_7 ( struct V_1 * V_1 , struct V_38 * V_38 )
{
int V_39 ;
char * V_20 = ( char * ) L_8 ;
char * V_40 = malloc ( V_41 ) ;
if ( ! V_40 )
return - V_42 ;
if ( V_38 )
V_20 = V_38 -> V_20 ;
if ( F_2 ( V_1 , V_1 -> V_43 ,
V_20 , V_40 , V_41 ) ) {
free ( V_40 ) ;
return - V_44 ;
}
V_39 = F_8 ( V_40 , V_45 ) ;
free ( V_40 ) ;
return V_39 ;
}
int F_9 ( struct V_1 * V_1 , struct V_38 * V_38 )
{
enum V_19 V_46 [] = {
V_7 ,
V_12 ,
V_18 ,
} ;
int V_47 = 0 ;
if ( V_1 -> V_43 != V_18 )
return F_7 ( V_1 , V_38 ) ;
do {
int V_39 ;
V_1 -> V_43 = V_46 [ V_47 ++ ] ;
V_39 = F_7 ( V_1 , V_38 ) ;
if ( V_39 >= 0 )
return V_39 ;
} while ( V_1 -> V_43 != V_18 );
return - V_44 ;
}
static void
F_10 ( struct V_48 * V_49 )
{
struct V_50 * V_51 = F_11 ( V_49 ) ;
while ( V_51 ) {
struct V_52 * V_53 ;
V_53 = F_12 ( V_51 , struct V_52 , V_50 ) ;
V_51 = F_13 ( & V_53 -> V_50 ) ;
F_14 ( & V_53 -> V_50 , V_49 ) ;
free ( V_53 ) ;
}
}
static struct V_52 * F_15 ( const struct V_48 * V_49 , T_2 V_54 )
{
struct V_50 * const * V_55 = & V_49 -> V_50 ;
const struct V_50 * V_56 = NULL ;
struct V_52 * V_53 ;
while ( * V_55 != NULL ) {
T_2 V_57 ;
V_56 = * V_55 ;
V_53 = F_12 ( V_56 , struct V_52 , V_50 ) ;
V_57 = V_53 -> V_54 + V_58 ;
if ( V_54 < V_53 -> V_54 )
V_55 = & ( * V_55 ) -> V_59 ;
else if ( V_54 >= V_57 )
V_55 = & ( * V_55 ) -> V_60 ;
else
return V_53 ;
}
return NULL ;
}
static void
F_16 ( struct V_48 * V_49 , struct V_52 * V_61 )
{
struct V_50 * * V_55 = & V_49 -> V_50 ;
struct V_50 * V_56 = NULL ;
struct V_52 * V_53 ;
T_2 V_54 = V_61 -> V_54 ;
while ( * V_55 != NULL ) {
T_2 V_57 ;
V_56 = * V_55 ;
V_53 = F_12 ( V_56 , struct V_52 , V_50 ) ;
V_57 = V_53 -> V_54 + V_58 ;
if ( V_54 < V_53 -> V_54 )
V_55 = & ( * V_55 ) -> V_59 ;
else if ( V_54 >= V_57 )
V_55 = & ( * V_55 ) -> V_60 ;
}
F_17 ( & V_61 -> V_50 , V_56 , V_55 ) ;
F_18 ( & V_61 -> V_50 , V_49 ) ;
}
static T_3
F_19 ( struct V_52 * V_53 , T_2 V_54 ,
T_4 * V_62 , T_2 V_22 )
{
T_2 V_63 = V_54 - V_53 -> V_54 ;
T_2 V_64 = F_20 ( V_53 -> V_22 - V_63 , V_22 ) ;
memcpy ( V_62 , V_53 -> V_62 + V_63 , V_64 ) ;
return V_64 ;
}
static T_3
F_21 ( struct V_1 * V_1 , struct V_38 * V_38 ,
T_2 V_54 , T_4 * V_62 , T_3 V_22 )
{
struct V_52 * V_53 ;
T_3 V_25 ;
int V_39 ;
V_39 = F_9 ( V_1 , V_38 ) ;
if ( V_39 < 0 )
return - 1 ;
do {
T_2 V_63 ;
V_25 = - V_42 ;
V_53 = F_22 ( sizeof( * V_53 ) + V_58 ) ;
if ( ! V_53 )
break;
V_63 = V_54 & V_65 ;
V_25 = - V_44 ;
if ( - 1 == F_23 ( V_39 , V_63 , V_66 ) )
break;
V_25 = F_24 ( V_39 , V_53 -> V_62 , V_58 ) ;
if ( V_25 <= 0 )
break;
V_53 -> V_54 = V_63 ;
V_53 -> V_22 = V_25 ;
F_16 ( & V_1 -> V_53 , V_53 ) ;
V_25 = F_19 ( V_53 , V_54 , V_62 , V_22 ) ;
} while ( 0 );
if ( V_25 <= 0 )
free ( V_53 ) ;
F_25 ( V_39 ) ;
return V_25 ;
}
static T_3 F_26 ( struct V_1 * V_1 , struct V_38 * V_38 ,
T_2 V_54 , T_4 * V_62 , T_3 V_22 )
{
struct V_52 * V_53 ;
V_53 = F_15 ( & V_1 -> V_53 , V_54 ) ;
if ( V_53 )
return F_19 ( V_53 , V_54 , V_62 , V_22 ) ;
else
return F_21 ( V_1 , V_38 , V_54 , V_62 , V_22 ) ;
}
T_3 F_27 ( struct V_1 * V_1 , struct V_38 * V_38 ,
T_2 V_54 , T_4 * V_62 , T_3 V_22 )
{
T_3 V_67 = 0 ;
T_4 * V_55 = V_62 ;
do {
T_3 V_25 ;
V_25 = F_26 ( V_1 , V_38 , V_54 , V_55 , V_22 ) ;
if ( V_25 < 0 )
return V_25 ;
if ( ! V_25 )
break;
F_28 ( V_25 > V_22 ) ;
V_67 += V_25 ;
V_55 += V_25 ;
V_54 += V_25 ;
V_22 -= V_25 ;
} while ( V_22 );
return V_67 ;
}
T_3 F_29 ( struct V_1 * V_1 , struct V_68 * V_68 ,
struct V_38 * V_38 , T_2 V_69 ,
T_4 * V_62 , T_3 V_22 )
{
T_2 V_54 = V_68 -> V_70 ( V_68 , V_69 ) ;
return F_27 ( V_1 , V_38 , V_54 , V_62 , V_22 ) ;
}
struct V_68 * F_30 ( const char * V_40 )
{
struct V_68 * V_68 = NULL ;
struct V_1 * V_1 = F_31 ( V_40 ) ;
if ( V_1 )
V_68 = F_32 ( 0 , V_1 , V_71 ) ;
return V_68 ;
}
struct V_1 * F_33 ( struct V_38 * V_38 , const char * V_40 ,
const char * V_72 , int V_73 )
{
struct V_1 * V_1 = F_34 ( & V_38 -> V_74 , V_40 ) ;
if ( V_1 != NULL ) {
F_35 ( V_1 , V_72 , false ) ;
V_1 -> V_75 = V_73 ;
}
return V_1 ;
}
void F_36 ( struct V_1 * V_1 , const char * V_40 , bool V_76 )
{
if ( V_40 == NULL )
return;
if ( V_1 -> V_77 )
free ( ( char * ) V_1 -> V_27 ) ;
V_1 -> V_27 = V_40 ;
V_1 -> V_28 = strlen ( V_40 ) ;
V_1 -> V_77 = V_76 ;
}
void F_35 ( struct V_1 * V_1 , const char * V_40 , bool V_76 )
{
if ( V_40 == NULL )
return;
if ( V_1 -> V_78 )
free ( ( char * ) V_1 -> V_72 ) ;
V_1 -> V_72 = V_40 ;
V_1 -> V_79 = strlen ( V_40 ) ;
V_1 -> V_78 = V_76 ;
}
static void F_37 ( struct V_1 * V_1 )
{
char * V_80 , * V_81 = F_38 ( V_1 -> V_27 ) ;
if ( ! V_81 )
return;
V_80 = F_38 ( F_39 ( V_81 ) ) ;
free ( V_81 ) ;
if ( ! V_80 )
return;
F_35 ( V_1 , V_80 , true ) ;
}
int F_40 ( const struct V_1 * V_1 )
{
if ( ! V_1 )
return strlen ( L_9 ) ;
if ( V_82 )
return V_1 -> V_28 ;
return V_1 -> V_79 ;
}
bool F_41 ( const struct V_1 * V_1 , enum V_83 type )
{
return V_1 -> V_84 & ( 1 << type ) ;
}
bool F_42 ( const struct V_1 * V_1 , enum V_83 type )
{
return V_1 -> V_85 & ( 1 << type ) ;
}
void F_43 ( struct V_1 * V_1 , enum V_83 type )
{
V_1 -> V_85 |= ( 1 << type ) ;
}
struct V_1 * F_31 ( const char * V_40 )
{
struct V_1 * V_1 = calloc ( 1 , sizeof( * V_1 ) + strlen ( V_40 ) + 1 ) ;
if ( V_1 != NULL ) {
int V_47 ;
strcpy ( V_1 -> V_40 , V_40 ) ;
F_36 ( V_1 , V_1 -> V_40 , false ) ;
F_35 ( V_1 , V_1 -> V_40 , false ) ;
for ( V_47 = 0 ; V_47 < V_86 ; ++ V_47 )
V_1 -> V_87 [ V_47 ] = V_1 -> V_88 [ V_47 ] = V_89 ;
V_1 -> V_53 = V_89 ;
V_1 -> V_17 = V_18 ;
V_1 -> V_43 = V_18 ;
V_1 -> V_84 = 0 ;
V_1 -> V_90 = 0 ;
V_1 -> V_85 = 0 ;
V_1 -> V_34 = 0 ;
V_1 -> V_91 = 1 ;
V_1 -> V_92 = 1 ;
V_1 -> V_75 = V_93 ;
V_1 -> V_94 = V_95 ;
F_44 ( & V_1 -> V_96 ) ;
}
return V_1 ;
}
void F_45 ( struct V_1 * V_1 )
{
int V_47 ;
for ( V_47 = 0 ; V_47 < V_86 ; ++ V_47 )
F_46 ( & V_1 -> V_87 [ V_47 ] ) ;
if ( V_1 -> V_78 ) {
F_47 ( ( char * * ) & V_1 -> V_72 ) ;
V_1 -> V_78 = false ;
}
if ( V_1 -> V_77 ) {
F_47 ( ( char * * ) & V_1 -> V_27 ) ;
V_1 -> V_77 = false ;
}
F_10 ( & V_1 -> V_53 ) ;
F_48 ( V_1 ) ;
F_47 ( & V_1 -> V_97 ) ;
free ( V_1 ) ;
}
void F_49 ( struct V_1 * V_1 , void * V_35 )
{
memcpy ( V_1 -> V_35 , V_35 , sizeof( V_1 -> V_35 ) ) ;
V_1 -> V_34 = 1 ;
}
bool F_50 ( const struct V_1 * V_1 , T_4 * V_35 )
{
return memcmp ( V_1 -> V_35 , V_35 , sizeof( V_1 -> V_35 ) ) == 0 ;
}
void F_51 ( struct V_1 * V_1 , struct V_38 * V_38 )
{
char V_98 [ V_41 ] ;
if ( F_52 ( V_38 ) )
return;
sprintf ( V_98 , L_10 , V_38 -> V_20 ) ;
if ( F_53 ( V_98 , V_1 -> V_35 ,
sizeof( V_1 -> V_35 ) ) == 0 )
V_1 -> V_34 = true ;
}
int F_54 ( struct V_1 * V_1 ,
const char * V_20 )
{
char V_21 [ V_41 ] ;
const char * V_40 = V_1 -> V_72 + 1 ;
snprintf ( V_21 , sizeof( V_21 ) ,
L_11 ,
V_20 , ( int ) strlen ( V_40 ) - 1 , V_40 ) ;
if ( F_53 ( V_21 , V_1 -> V_35 ,
sizeof( V_1 -> V_35 ) ) == 0 )
V_1 -> V_34 = true ;
return 0 ;
}
bool F_55 ( struct V_99 * V_100 , bool V_101 )
{
bool V_102 = false ;
struct V_1 * V_103 ;
F_56 (pos, head, node) {
if ( V_101 && ! V_103 -> V_104 )
continue;
if ( V_103 -> V_34 ) {
V_102 = true ;
continue;
}
if ( F_57 ( V_103 -> V_27 , V_103 -> V_35 ,
sizeof( V_103 -> V_35 ) ) > 0 ) {
V_102 = true ;
V_103 -> V_34 = true ;
}
}
return V_102 ;
}
void F_58 ( struct V_99 * V_100 , struct V_1 * V_1 )
{
F_59 ( & V_1 -> V_96 , V_100 ) ;
}
struct V_1 * F_60 ( const struct V_99 * V_100 , const char * V_40 , bool V_105 )
{
struct V_1 * V_103 ;
if ( V_105 ) {
F_56 (pos, head, node)
if ( strcmp ( V_103 -> V_72 , V_40 ) == 0 )
return V_103 ;
return NULL ;
}
F_56 (pos, head, node)
if ( strcmp ( V_103 -> V_27 , V_40 ) == 0 )
return V_103 ;
return NULL ;
}
struct V_1 * F_34 ( struct V_99 * V_100 , const char * V_40 )
{
struct V_1 * V_1 = F_60 ( V_100 , V_40 , false ) ;
if ( ! V_1 ) {
V_1 = F_31 ( V_40 ) ;
if ( V_1 != NULL ) {
F_58 ( V_100 , V_1 ) ;
F_37 ( V_1 ) ;
}
}
return V_1 ;
}
T_1 F_61 ( struct V_99 * V_100 , T_5 * V_106 ,
bool (F_62)( struct V_1 * V_1 , int V_107 ) , int V_107 )
{
struct V_1 * V_103 ;
T_1 V_25 = 0 ;
F_56 (pos, head, node) {
if ( F_62 && F_62 ( V_103 , V_107 ) )
continue;
V_25 += F_63 ( V_103 , V_106 ) ;
V_25 += fprintf ( V_106 , L_12 , V_103 -> V_27 ) ;
}
return V_25 ;
}
T_1 F_64 ( struct V_99 * V_100 , T_5 * V_106 )
{
struct V_1 * V_103 ;
T_1 V_25 = 0 ;
F_56 (pos, head, node) {
int V_47 ;
for ( V_47 = 0 ; V_47 < V_86 ; ++ V_47 )
V_25 += F_65 ( V_103 , V_47 , V_106 ) ;
}
return V_25 ;
}
T_1 F_63 ( struct V_1 * V_1 , T_5 * V_106 )
{
char V_108 [ V_24 * 2 + 1 ] ;
F_6 ( V_1 -> V_35 , sizeof( V_1 -> V_35 ) , V_108 ) ;
return fprintf ( V_106 , L_3 , V_108 ) ;
}
T_1 F_65 ( struct V_1 * V_1 , enum V_83 type , T_5 * V_106 )
{
struct V_50 * V_109 ;
T_1 V_25 = fprintf ( V_106 , L_13 , V_1 -> V_72 ) ;
if ( V_1 -> V_72 != V_1 -> V_27 )
V_25 += fprintf ( V_106 , L_14 , V_1 -> V_27 ) ;
V_25 += fprintf ( V_106 , L_15 , V_110 [ type ] ,
F_41 ( V_1 , type ) ? L_8 : L_16 ) ;
V_25 += F_63 ( V_1 , V_106 ) ;
V_25 += fprintf ( V_106 , L_17 ) ;
for ( V_109 = F_11 ( & V_1 -> V_87 [ type ] ) ; V_109 ; V_109 = F_13 ( V_109 ) ) {
struct V_111 * V_103 = F_12 ( V_109 , struct V_111 , V_50 ) ;
V_25 += F_66 ( V_103 , V_106 ) ;
}
return V_25 ;
}
