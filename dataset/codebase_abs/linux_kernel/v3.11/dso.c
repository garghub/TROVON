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
default:
case V_3 :
case V_4 :
case V_13 :
case V_15 :
case V_5 :
case V_17 :
V_24 = - 1 ;
break;
}
return V_24 ;
}
static int F_6 ( struct V_1 * V_1 , struct V_32 * V_32 )
{
char * V_19 = ( char * ) L_6 ;
char * V_33 ;
int V_34 ;
V_33 = malloc ( V_35 ) ;
if ( ! V_33 )
return - V_36 ;
if ( V_32 )
V_19 = V_32 -> V_19 ;
if ( F_2 ( V_1 , V_1 -> V_37 ,
V_19 , V_33 , V_35 ) ) {
free ( V_33 ) ;
return - V_38 ;
}
V_34 = F_7 ( V_33 , V_39 ) ;
free ( V_33 ) ;
return V_34 ;
}
int F_8 ( struct V_1 * V_1 , struct V_32 * V_32 )
{
static enum V_18 V_40 [] = {
V_7 ,
V_11 ,
V_17 ,
} ;
int V_41 = 0 ;
if ( V_1 -> V_37 != V_17 )
return F_6 ( V_1 , V_32 ) ;
do {
int V_34 ;
V_1 -> V_37 = V_40 [ V_41 ++ ] ;
V_34 = F_6 ( V_1 , V_32 ) ;
if ( V_34 >= 0 )
return V_34 ;
} while ( V_1 -> V_37 != V_17 );
return - V_38 ;
}
static void
F_9 ( struct V_42 * V_43 )
{
struct V_44 * V_45 = F_10 ( V_43 ) ;
while ( V_45 ) {
struct V_46 * V_47 ;
V_47 = F_11 ( V_45 , struct V_46 , V_44 ) ;
V_45 = F_12 ( & V_47 -> V_44 ) ;
F_13 ( & V_47 -> V_44 , V_43 ) ;
free ( V_47 ) ;
}
}
static struct V_46 *
F_14 ( struct V_42 * V_43 , T_2 V_48 )
{
struct V_44 * * V_49 = & V_43 -> V_44 ;
struct V_44 * V_50 = NULL ;
struct V_46 * V_47 ;
while ( * V_49 != NULL ) {
T_2 V_51 ;
V_50 = * V_49 ;
V_47 = F_11 ( V_50 , struct V_46 , V_44 ) ;
V_51 = V_47 -> V_48 + V_52 ;
if ( V_48 < V_47 -> V_48 )
V_49 = & ( * V_49 ) -> V_53 ;
else if ( V_48 >= V_51 )
V_49 = & ( * V_49 ) -> V_54 ;
else
return V_47 ;
}
return NULL ;
}
static void
F_15 ( struct V_42 * V_43 , struct V_46 * V_55 )
{
struct V_44 * * V_49 = & V_43 -> V_44 ;
struct V_44 * V_50 = NULL ;
struct V_46 * V_47 ;
T_2 V_48 = V_55 -> V_48 ;
while ( * V_49 != NULL ) {
T_2 V_51 ;
V_50 = * V_49 ;
V_47 = F_11 ( V_50 , struct V_46 , V_44 ) ;
V_51 = V_47 -> V_48 + V_52 ;
if ( V_48 < V_47 -> V_48 )
V_49 = & ( * V_49 ) -> V_53 ;
else if ( V_48 >= V_51 )
V_49 = & ( * V_49 ) -> V_54 ;
}
F_16 ( & V_55 -> V_44 , V_50 , V_49 ) ;
F_17 ( & V_55 -> V_44 , V_43 ) ;
}
static T_3
F_18 ( struct V_46 * V_47 , T_2 V_48 ,
T_4 * V_56 , T_2 V_21 )
{
T_2 V_57 = V_48 - V_47 -> V_48 ;
T_2 V_58 = F_19 ( V_47 -> V_21 - V_57 , V_21 ) ;
memcpy ( V_56 , V_47 -> V_56 + V_57 , V_58 ) ;
return V_58 ;
}
static T_3
F_20 ( struct V_1 * V_1 , struct V_32 * V_32 ,
T_2 V_48 , T_4 * V_56 , T_3 V_21 )
{
struct V_46 * V_47 ;
T_3 V_24 ;
int V_34 ;
V_34 = F_8 ( V_1 , V_32 ) ;
if ( V_34 < 0 )
return - 1 ;
do {
T_2 V_57 ;
V_24 = - V_36 ;
V_47 = F_21 ( sizeof( * V_47 ) + V_52 ) ;
if ( ! V_47 )
break;
V_57 = V_48 & V_59 ;
V_24 = - V_38 ;
if ( - 1 == F_22 ( V_34 , V_57 , V_60 ) )
break;
V_24 = F_23 ( V_34 , V_47 -> V_56 , V_52 ) ;
if ( V_24 <= 0 )
break;
V_47 -> V_48 = V_57 ;
V_47 -> V_21 = V_24 ;
F_15 ( & V_1 -> V_47 , V_47 ) ;
V_24 = F_18 ( V_47 , V_48 , V_56 , V_21 ) ;
} while ( 0 );
if ( V_24 <= 0 )
free ( V_47 ) ;
F_24 ( V_34 ) ;
return V_24 ;
}
static T_3 F_25 ( struct V_1 * V_1 , struct V_32 * V_32 ,
T_2 V_48 , T_4 * V_56 , T_3 V_21 )
{
struct V_46 * V_47 ;
V_47 = F_14 ( & V_1 -> V_47 , V_48 ) ;
if ( V_47 )
return F_18 ( V_47 , V_48 , V_56 , V_21 ) ;
else
return F_20 ( V_1 , V_32 , V_48 , V_56 , V_21 ) ;
}
T_3 F_26 ( struct V_1 * V_1 , struct V_32 * V_32 ,
T_2 V_48 , T_4 * V_56 , T_3 V_21 )
{
T_3 V_61 = 0 ;
T_4 * V_49 = V_56 ;
do {
T_3 V_24 ;
V_24 = F_25 ( V_1 , V_32 , V_48 , V_49 , V_21 ) ;
if ( V_24 < 0 )
return V_24 ;
if ( ! V_24 )
break;
F_27 ( V_24 > V_21 ) ;
V_61 += V_24 ;
V_49 += V_24 ;
V_48 += V_24 ;
V_21 -= V_24 ;
} while ( V_21 );
return V_61 ;
}
T_3 F_28 ( struct V_1 * V_1 , struct V_62 * V_62 ,
struct V_32 * V_32 , T_2 V_63 ,
T_4 * V_56 , T_3 V_21 )
{
T_2 V_48 = V_62 -> V_64 ( V_62 , V_63 ) ;
return F_26 ( V_1 , V_32 , V_48 , V_56 , V_21 ) ;
}
struct V_62 * F_29 ( const char * V_33 )
{
struct V_62 * V_62 = NULL ;
struct V_1 * V_1 = F_30 ( V_33 ) ;
if ( V_1 )
V_62 = F_31 ( 0 , V_1 , V_65 ) ;
return V_62 ;
}
struct V_1 * F_32 ( struct V_32 * V_32 , const char * V_33 ,
const char * V_66 , int V_67 )
{
struct V_1 * V_1 = F_33 ( & V_32 -> V_68 , V_33 ) ;
if ( V_1 != NULL ) {
F_34 ( V_1 , V_66 ) ;
V_1 -> V_69 = V_67 ;
}
return V_1 ;
}
void F_35 ( struct V_1 * V_1 , char * V_33 )
{
if ( V_33 == NULL )
return;
V_1 -> V_26 = V_33 ;
V_1 -> V_27 = strlen ( V_33 ) ;
}
void F_34 ( struct V_1 * V_1 , const char * V_33 )
{
if ( V_33 == NULL )
return;
V_1 -> V_66 = V_33 ;
V_1 -> V_70 = strlen ( V_33 ) ;
}
static void F_36 ( struct V_1 * V_1 )
{
F_34 ( V_1 , F_37 ( V_1 -> V_26 ) ) ;
}
int F_38 ( const struct V_1 * V_1 )
{
if ( ! V_1 )
return strlen ( L_7 ) ;
if ( V_71 )
return V_1 -> V_27 ;
return V_1 -> V_70 ;
}
bool F_39 ( const struct V_1 * V_1 , enum V_72 type )
{
return V_1 -> V_73 & ( 1 << type ) ;
}
bool F_40 ( const struct V_1 * V_1 , enum V_72 type )
{
return V_1 -> V_74 & ( 1 << type ) ;
}
void F_41 ( struct V_1 * V_1 , enum V_72 type )
{
V_1 -> V_74 |= ( 1 << type ) ;
}
struct V_1 * F_30 ( const char * V_33 )
{
struct V_1 * V_1 = calloc ( 1 , sizeof( * V_1 ) + strlen ( V_33 ) + 1 ) ;
if ( V_1 != NULL ) {
int V_41 ;
strcpy ( V_1 -> V_33 , V_33 ) ;
F_35 ( V_1 , V_1 -> V_33 ) ;
F_34 ( V_1 , V_1 -> V_33 ) ;
for ( V_41 = 0 ; V_41 < V_75 ; ++ V_41 )
V_1 -> V_76 [ V_41 ] = V_1 -> V_77 [ V_41 ] = V_78 ;
V_1 -> V_47 = V_78 ;
V_1 -> V_16 = V_17 ;
V_1 -> V_37 = V_17 ;
V_1 -> V_73 = 0 ;
V_1 -> V_74 = 0 ;
V_1 -> V_30 = 0 ;
V_1 -> V_69 = V_79 ;
V_1 -> V_80 = V_81 ;
F_42 ( & V_1 -> V_82 ) ;
}
return V_1 ;
}
void F_43 ( struct V_1 * V_1 )
{
int V_41 ;
for ( V_41 = 0 ; V_41 < V_75 ; ++ V_41 )
F_44 ( & V_1 -> V_76 [ V_41 ] ) ;
if ( V_1 -> V_83 )
free ( ( char * ) V_1 -> V_66 ) ;
if ( V_1 -> V_84 )
free ( V_1 -> V_26 ) ;
F_9 ( & V_1 -> V_47 ) ;
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
void F_47 ( struct V_1 * V_1 , struct V_32 * V_32 )
{
char V_85 [ V_35 ] ;
if ( F_48 ( V_32 ) )
return;
sprintf ( V_85 , L_8 , V_32 -> V_19 ) ;
if ( F_49 ( V_85 , V_1 -> V_31 ,
sizeof( V_1 -> V_31 ) ) == 0 )
V_1 -> V_30 = true ;
}
int F_50 ( struct V_1 * V_1 ,
const char * V_19 )
{
char V_86 [ V_35 ] ;
const char * V_33 = V_1 -> V_66 + 1 ;
snprintf ( V_86 , sizeof( V_86 ) ,
L_9 ,
V_19 , ( int ) strlen ( V_33 ) - 1 , V_33 ) ;
if ( F_49 ( V_86 , V_1 -> V_31 ,
sizeof( V_1 -> V_31 ) ) == 0 )
V_1 -> V_30 = true ;
return 0 ;
}
bool F_51 ( struct V_87 * V_88 , bool V_89 )
{
bool V_90 = false ;
struct V_1 * V_91 ;
F_52 (pos, head, node) {
if ( V_89 && ! V_91 -> V_92 )
continue;
if ( V_91 -> V_30 ) {
V_90 = true ;
continue;
}
if ( F_53 ( V_91 -> V_26 , V_91 -> V_31 ,
sizeof( V_91 -> V_31 ) ) > 0 ) {
V_90 = true ;
V_91 -> V_30 = true ;
}
}
return V_90 ;
}
void F_54 ( struct V_87 * V_88 , struct V_1 * V_1 )
{
F_55 ( & V_1 -> V_82 , V_88 ) ;
}
struct V_1 * F_56 ( struct V_87 * V_88 , const char * V_33 , bool V_93 )
{
struct V_1 * V_91 ;
if ( V_93 ) {
F_52 (pos, head, node)
if ( strcmp ( V_91 -> V_66 , V_33 ) == 0 )
return V_91 ;
return NULL ;
}
F_52 (pos, head, node)
if ( strcmp ( V_91 -> V_26 , V_33 ) == 0 )
return V_91 ;
return NULL ;
}
struct V_1 * F_33 ( struct V_87 * V_88 , const char * V_33 )
{
struct V_1 * V_1 = F_56 ( V_88 , V_33 , false ) ;
if ( ! V_1 ) {
V_1 = F_30 ( V_33 ) ;
if ( V_1 != NULL ) {
F_54 ( V_88 , V_1 ) ;
F_36 ( V_1 ) ;
}
}
return V_1 ;
}
T_1 F_57 ( struct V_87 * V_88 , T_5 * V_94 ,
bool (F_58)( struct V_1 * V_1 , int V_95 ) , int V_95 )
{
struct V_1 * V_91 ;
T_1 V_24 = 0 ;
F_52 (pos, head, node) {
if ( F_58 && F_58 ( V_91 , V_95 ) )
continue;
V_24 += F_59 ( V_91 , V_94 ) ;
V_24 += fprintf ( V_94 , L_10 , V_91 -> V_26 ) ;
}
return V_24 ;
}
T_1 F_60 ( struct V_87 * V_88 , T_5 * V_94 )
{
struct V_1 * V_91 ;
T_1 V_24 = 0 ;
F_52 (pos, head, node) {
int V_41 ;
for ( V_41 = 0 ; V_41 < V_75 ; ++ V_41 )
V_24 += F_61 ( V_91 , V_41 , V_94 ) ;
}
return V_24 ;
}
T_1 F_59 ( struct V_1 * V_1 , T_5 * V_94 )
{
char V_96 [ V_23 * 2 + 1 ] ;
F_5 ( V_1 -> V_31 , sizeof( V_1 -> V_31 ) , V_96 ) ;
return fprintf ( V_94 , L_11 , V_96 ) ;
}
T_1 F_61 ( struct V_1 * V_1 , enum V_72 type , T_5 * V_94 )
{
struct V_44 * V_97 ;
T_1 V_24 = fprintf ( V_94 , L_12 , V_1 -> V_66 ) ;
if ( V_1 -> V_66 != V_1 -> V_26 )
V_24 += fprintf ( V_94 , L_13 , V_1 -> V_26 ) ;
V_24 += fprintf ( V_94 , L_14 , V_98 [ type ] ,
F_39 ( V_1 , type ) ? L_6 : L_15 ) ;
V_24 += F_59 ( V_1 , V_94 ) ;
V_24 += fprintf ( V_94 , L_16 ) ;
for ( V_97 = F_10 ( & V_1 -> V_76 [ type ] ) ; V_97 ; V_97 = F_12 ( V_97 ) ) {
struct V_99 * V_91 = F_11 ( V_97 , struct V_99 , V_44 ) ;
V_24 += F_62 ( V_91 , V_94 ) ;
}
return V_24 ;
}
