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
[ V_10 ] = 'b' ,
[ V_11 ] = 'd' ,
[ V_12 ] = 'K' ,
[ V_13 ] = 'g' ,
[ V_14 ] = 'G' ,
[ V_15 ] = 'V' ,
} ;
if ( V_1 == NULL || V_1 -> V_16 == V_17 )
return '!' ;
return V_2 [ V_1 -> V_16 ] ;
}
int F_2 ( struct V_1 * V_1 , enum V_18 type ,
char * V_19 , char * V_20 , T_1 V_21 )
{
char V_22 [ V_23 * 2 + 1 ] ;
int V_24 = 0 ;
switch ( type ) {
case V_6 : {
char * V_25 ;
strncpy ( V_20 , V_1 -> V_26 , V_21 ) ;
V_25 = V_20 + V_1 -> V_27 ;
while ( V_25 != V_20 && * V_25 != '/' )
V_25 -- ;
if ( * V_25 == '/' )
V_25 ++ ;
F_3 ( V_1 -> V_26 , V_25 ,
V_21 - ( V_25 - V_20 ) ) ;
}
break;
case V_7 :
if ( V_28 . V_29 [ 0 ] ||
( F_4 ( V_1 , V_20 , V_21 ) == NULL ) )
V_24 = - 1 ;
break;
case V_8 :
snprintf ( V_20 , V_21 , L_1 ,
V_28 . V_29 , V_1 -> V_26 ) ;
break;
case V_9 :
snprintf ( V_20 , V_21 , L_2 ,
V_28 . V_29 , V_1 -> V_26 ) ;
break;
case V_10 :
if ( ! V_1 -> V_30 ) {
V_24 = - 1 ;
break;
}
F_5 ( V_1 -> V_31 ,
sizeof( V_1 -> V_31 ) ,
V_22 ) ;
snprintf ( V_20 , V_21 ,
L_3 ,
V_28 . V_29 , V_22 , V_22 + 2 ) ;
break;
case V_4 :
case V_15 :
case V_11 :
snprintf ( V_20 , V_21 , L_4 ,
V_28 . V_29 , V_1 -> V_26 ) ;
break;
case V_14 :
snprintf ( V_20 , V_21 , L_5 , V_28 . V_29 ,
V_19 , V_1 -> V_26 ) ;
break;
case V_12 :
snprintf ( V_20 , V_21 , L_4 , V_28 . V_29 ,
V_1 -> V_26 ) ;
break;
case V_32 :
case V_33 :
snprintf ( V_20 , V_21 , L_6 , V_1 -> V_26 ) ;
break;
default:
case V_3 :
case V_13 :
case V_5 :
case V_17 :
V_24 = - 1 ;
break;
}
return V_24 ;
}
static int F_6 ( struct V_1 * V_1 , struct V_34 * V_34 )
{
char * V_19 = ( char * ) L_7 ;
char * V_35 ;
int V_36 ;
V_35 = malloc ( V_37 ) ;
if ( ! V_35 )
return - V_38 ;
if ( V_34 )
V_19 = V_34 -> V_19 ;
if ( F_2 ( V_1 , V_1 -> V_39 ,
V_19 , V_35 , V_37 ) ) {
free ( V_35 ) ;
return - V_40 ;
}
V_36 = F_7 ( V_35 , V_41 ) ;
free ( V_35 ) ;
return V_36 ;
}
int F_8 ( struct V_1 * V_1 , struct V_34 * V_34 )
{
static enum V_18 V_42 [] = {
V_7 ,
V_11 ,
V_17 ,
} ;
int V_43 = 0 ;
if ( V_1 -> V_39 != V_17 )
return F_6 ( V_1 , V_34 ) ;
do {
int V_36 ;
V_1 -> V_39 = V_42 [ V_43 ++ ] ;
V_36 = F_6 ( V_1 , V_34 ) ;
if ( V_36 >= 0 )
return V_36 ;
} while ( V_1 -> V_39 != V_17 );
return - V_40 ;
}
static void
F_9 ( struct V_44 * V_45 )
{
struct V_46 * V_47 = F_10 ( V_45 ) ;
while ( V_47 ) {
struct V_48 * V_49 ;
V_49 = F_11 ( V_47 , struct V_48 , V_46 ) ;
V_47 = F_12 ( & V_49 -> V_46 ) ;
F_13 ( & V_49 -> V_46 , V_45 ) ;
free ( V_49 ) ;
}
}
static struct V_48 *
F_14 ( struct V_44 * V_45 , T_2 V_50 )
{
struct V_46 * * V_51 = & V_45 -> V_46 ;
struct V_46 * V_52 = NULL ;
struct V_48 * V_49 ;
while ( * V_51 != NULL ) {
T_2 V_53 ;
V_52 = * V_51 ;
V_49 = F_11 ( V_52 , struct V_48 , V_46 ) ;
V_53 = V_49 -> V_50 + V_54 ;
if ( V_50 < V_49 -> V_50 )
V_51 = & ( * V_51 ) -> V_55 ;
else if ( V_50 >= V_53 )
V_51 = & ( * V_51 ) -> V_56 ;
else
return V_49 ;
}
return NULL ;
}
static void
F_15 ( struct V_44 * V_45 , struct V_48 * V_57 )
{
struct V_46 * * V_51 = & V_45 -> V_46 ;
struct V_46 * V_52 = NULL ;
struct V_48 * V_49 ;
T_2 V_50 = V_57 -> V_50 ;
while ( * V_51 != NULL ) {
T_2 V_53 ;
V_52 = * V_51 ;
V_49 = F_11 ( V_52 , struct V_48 , V_46 ) ;
V_53 = V_49 -> V_50 + V_54 ;
if ( V_50 < V_49 -> V_50 )
V_51 = & ( * V_51 ) -> V_55 ;
else if ( V_50 >= V_53 )
V_51 = & ( * V_51 ) -> V_56 ;
}
F_16 ( & V_57 -> V_46 , V_52 , V_51 ) ;
F_17 ( & V_57 -> V_46 , V_45 ) ;
}
static T_3
F_18 ( struct V_48 * V_49 , T_2 V_50 ,
T_4 * V_58 , T_2 V_21 )
{
T_2 V_59 = V_50 - V_49 -> V_50 ;
T_2 V_60 = F_19 ( V_49 -> V_21 - V_59 , V_21 ) ;
memcpy ( V_58 , V_49 -> V_58 + V_59 , V_60 ) ;
return V_60 ;
}
static T_3
F_20 ( struct V_1 * V_1 , struct V_34 * V_34 ,
T_2 V_50 , T_4 * V_58 , T_3 V_21 )
{
struct V_48 * V_49 ;
T_3 V_24 ;
int V_36 ;
V_36 = F_8 ( V_1 , V_34 ) ;
if ( V_36 < 0 )
return - 1 ;
do {
T_2 V_59 ;
V_24 = - V_38 ;
V_49 = F_21 ( sizeof( * V_49 ) + V_54 ) ;
if ( ! V_49 )
break;
V_59 = V_50 & V_61 ;
V_24 = - V_40 ;
if ( - 1 == F_22 ( V_36 , V_59 , V_62 ) )
break;
V_24 = F_23 ( V_36 , V_49 -> V_58 , V_54 ) ;
if ( V_24 <= 0 )
break;
V_49 -> V_50 = V_59 ;
V_49 -> V_21 = V_24 ;
F_15 ( & V_1 -> V_49 , V_49 ) ;
V_24 = F_18 ( V_49 , V_50 , V_58 , V_21 ) ;
} while ( 0 );
if ( V_24 <= 0 )
free ( V_49 ) ;
F_24 ( V_36 ) ;
return V_24 ;
}
static T_3 F_25 ( struct V_1 * V_1 , struct V_34 * V_34 ,
T_2 V_50 , T_4 * V_58 , T_3 V_21 )
{
struct V_48 * V_49 ;
V_49 = F_14 ( & V_1 -> V_49 , V_50 ) ;
if ( V_49 )
return F_18 ( V_49 , V_50 , V_58 , V_21 ) ;
else
return F_20 ( V_1 , V_34 , V_50 , V_58 , V_21 ) ;
}
T_3 F_26 ( struct V_1 * V_1 , struct V_34 * V_34 ,
T_2 V_50 , T_4 * V_58 , T_3 V_21 )
{
T_3 V_63 = 0 ;
T_4 * V_51 = V_58 ;
do {
T_3 V_24 ;
V_24 = F_25 ( V_1 , V_34 , V_50 , V_51 , V_21 ) ;
if ( V_24 < 0 )
return V_24 ;
if ( ! V_24 )
break;
F_27 ( V_24 > V_21 ) ;
V_63 += V_24 ;
V_51 += V_24 ;
V_50 += V_24 ;
V_21 -= V_24 ;
} while ( V_21 );
return V_63 ;
}
T_3 F_28 ( struct V_1 * V_1 , struct V_64 * V_64 ,
struct V_34 * V_34 , T_2 V_65 ,
T_4 * V_58 , T_3 V_21 )
{
T_2 V_50 = V_64 -> V_66 ( V_64 , V_65 ) ;
return F_26 ( V_1 , V_34 , V_50 , V_58 , V_21 ) ;
}
struct V_64 * F_29 ( const char * V_35 )
{
struct V_64 * V_64 = NULL ;
struct V_1 * V_1 = F_30 ( V_35 ) ;
if ( V_1 )
V_64 = F_31 ( 0 , V_1 , V_67 ) ;
return V_64 ;
}
struct V_1 * F_32 ( struct V_34 * V_34 , const char * V_35 ,
const char * V_68 , int V_69 )
{
struct V_1 * V_1 = F_33 ( & V_34 -> V_70 , V_35 ) ;
if ( V_1 != NULL ) {
F_34 ( V_1 , V_68 ) ;
V_1 -> V_71 = V_69 ;
}
return V_1 ;
}
void F_35 ( struct V_1 * V_1 , char * V_35 )
{
if ( V_35 == NULL )
return;
V_1 -> V_26 = V_35 ;
V_1 -> V_27 = strlen ( V_35 ) ;
}
void F_34 ( struct V_1 * V_1 , const char * V_35 )
{
if ( V_35 == NULL )
return;
V_1 -> V_68 = V_35 ;
V_1 -> V_72 = strlen ( V_35 ) ;
}
static void F_36 ( struct V_1 * V_1 )
{
F_34 ( V_1 , F_37 ( V_1 -> V_26 ) ) ;
}
int F_38 ( const struct V_1 * V_1 )
{
if ( ! V_1 )
return strlen ( L_8 ) ;
if ( V_73 )
return V_1 -> V_27 ;
return V_1 -> V_72 ;
}
bool F_39 ( const struct V_1 * V_1 , enum V_74 type )
{
return V_1 -> V_75 & ( 1 << type ) ;
}
bool F_40 ( const struct V_1 * V_1 , enum V_74 type )
{
return V_1 -> V_76 & ( 1 << type ) ;
}
void F_41 ( struct V_1 * V_1 , enum V_74 type )
{
V_1 -> V_76 |= ( 1 << type ) ;
}
struct V_1 * F_30 ( const char * V_35 )
{
struct V_1 * V_1 = calloc ( 1 , sizeof( * V_1 ) + strlen ( V_35 ) + 1 ) ;
if ( V_1 != NULL ) {
int V_43 ;
strcpy ( V_1 -> V_35 , V_35 ) ;
F_35 ( V_1 , V_1 -> V_35 ) ;
F_34 ( V_1 , V_1 -> V_35 ) ;
for ( V_43 = 0 ; V_43 < V_77 ; ++ V_43 )
V_1 -> V_78 [ V_43 ] = V_1 -> V_79 [ V_43 ] = V_80 ;
V_1 -> V_49 = V_80 ;
V_1 -> V_16 = V_17 ;
V_1 -> V_39 = V_17 ;
V_1 -> V_75 = 0 ;
V_1 -> V_81 = 0 ;
V_1 -> V_76 = 0 ;
V_1 -> V_30 = 0 ;
V_1 -> V_71 = V_82 ;
V_1 -> V_83 = V_84 ;
F_42 ( & V_1 -> V_85 ) ;
}
return V_1 ;
}
void F_43 ( struct V_1 * V_1 )
{
int V_43 ;
for ( V_43 = 0 ; V_43 < V_77 ; ++ V_43 )
F_44 ( & V_1 -> V_78 [ V_43 ] ) ;
if ( V_1 -> V_86 )
free ( ( char * ) V_1 -> V_68 ) ;
if ( V_1 -> V_87 )
free ( V_1 -> V_26 ) ;
F_9 ( & V_1 -> V_49 ) ;
free ( V_1 ) ;
}
void F_45 ( struct V_1 * V_1 , void * V_31 )
{
memcpy ( V_1 -> V_31 , V_31 , sizeof( V_1 -> V_31 ) ) ;
V_1 -> V_30 = 1 ;
}
bool F_46 ( const struct V_1 * V_1 , T_4 * V_31 )
{
return memcmp ( V_1 -> V_31 , V_31 , sizeof( V_1 -> V_31 ) ) == 0 ;
}
void F_47 ( struct V_1 * V_1 , struct V_34 * V_34 )
{
char V_88 [ V_37 ] ;
if ( F_48 ( V_34 ) )
return;
sprintf ( V_88 , L_9 , V_34 -> V_19 ) ;
if ( F_49 ( V_88 , V_1 -> V_31 ,
sizeof( V_1 -> V_31 ) ) == 0 )
V_1 -> V_30 = true ;
}
int F_50 ( struct V_1 * V_1 ,
const char * V_19 )
{
char V_89 [ V_37 ] ;
const char * V_35 = V_1 -> V_68 + 1 ;
snprintf ( V_89 , sizeof( V_89 ) ,
L_10 ,
V_19 , ( int ) strlen ( V_35 ) - 1 , V_35 ) ;
if ( F_49 ( V_89 , V_1 -> V_31 ,
sizeof( V_1 -> V_31 ) ) == 0 )
V_1 -> V_30 = true ;
return 0 ;
}
bool F_51 ( struct V_90 * V_91 , bool V_92 )
{
bool V_93 = false ;
struct V_1 * V_94 ;
F_52 (pos, head, node) {
if ( V_92 && ! V_94 -> V_95 )
continue;
if ( V_94 -> V_30 ) {
V_93 = true ;
continue;
}
if ( F_53 ( V_94 -> V_26 , V_94 -> V_31 ,
sizeof( V_94 -> V_31 ) ) > 0 ) {
V_93 = true ;
V_94 -> V_30 = true ;
}
}
return V_93 ;
}
void F_54 ( struct V_90 * V_91 , struct V_1 * V_1 )
{
F_55 ( & V_1 -> V_85 , V_91 ) ;
}
struct V_1 * F_56 ( struct V_90 * V_91 , const char * V_35 , bool V_96 )
{
struct V_1 * V_94 ;
if ( V_96 ) {
F_52 (pos, head, node)
if ( strcmp ( V_94 -> V_68 , V_35 ) == 0 )
return V_94 ;
return NULL ;
}
F_52 (pos, head, node)
if ( strcmp ( V_94 -> V_26 , V_35 ) == 0 )
return V_94 ;
return NULL ;
}
struct V_1 * F_33 ( struct V_90 * V_91 , const char * V_35 )
{
struct V_1 * V_1 = F_56 ( V_91 , V_35 , false ) ;
if ( ! V_1 ) {
V_1 = F_30 ( V_35 ) ;
if ( V_1 != NULL ) {
F_54 ( V_91 , V_1 ) ;
F_36 ( V_1 ) ;
}
}
return V_1 ;
}
T_1 F_57 ( struct V_90 * V_91 , T_5 * V_97 ,
bool (F_58)( struct V_1 * V_1 , int V_98 ) , int V_98 )
{
struct V_1 * V_94 ;
T_1 V_24 = 0 ;
F_52 (pos, head, node) {
if ( F_58 && F_58 ( V_94 , V_98 ) )
continue;
V_24 += F_59 ( V_94 , V_97 ) ;
V_24 += fprintf ( V_97 , L_11 , V_94 -> V_26 ) ;
}
return V_24 ;
}
T_1 F_60 ( struct V_90 * V_91 , T_5 * V_97 )
{
struct V_1 * V_94 ;
T_1 V_24 = 0 ;
F_52 (pos, head, node) {
int V_43 ;
for ( V_43 = 0 ; V_43 < V_77 ; ++ V_43 )
V_24 += F_61 ( V_94 , V_43 , V_97 ) ;
}
return V_24 ;
}
T_1 F_59 ( struct V_1 * V_1 , T_5 * V_97 )
{
char V_99 [ V_23 * 2 + 1 ] ;
F_5 ( V_1 -> V_31 , sizeof( V_1 -> V_31 ) , V_99 ) ;
return fprintf ( V_97 , L_6 , V_99 ) ;
}
T_1 F_61 ( struct V_1 * V_1 , enum V_74 type , T_5 * V_97 )
{
struct V_46 * V_100 ;
T_1 V_24 = fprintf ( V_97 , L_12 , V_1 -> V_68 ) ;
if ( V_1 -> V_68 != V_1 -> V_26 )
V_24 += fprintf ( V_97 , L_13 , V_1 -> V_26 ) ;
V_24 += fprintf ( V_97 , L_14 , V_101 [ type ] ,
F_39 ( V_1 , type ) ? L_7 : L_15 ) ;
V_24 += F_59 ( V_1 , V_97 ) ;
V_24 += fprintf ( V_97 , L_16 ) ;
for ( V_100 = F_10 ( & V_1 -> V_78 [ type ] ) ; V_100 ; V_100 = F_12 ( V_100 ) ) {
struct V_102 * V_94 = F_11 ( V_100 , struct V_102 , V_46 ) ;
V_24 += F_62 ( V_94 , V_97 ) ;
}
return V_24 ;
}
