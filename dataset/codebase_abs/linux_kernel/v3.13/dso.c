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
int F_2 ( struct V_1 * V_1 , enum V_19 type ,
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
F_3 ( V_1 -> V_27 , V_26 ,
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
char * V_31 ;
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
char * V_20 = ( char * ) L_8 ;
char * V_39 ;
int V_40 ;
V_39 = malloc ( V_41 ) ;
if ( ! V_39 )
return - V_42 ;
if ( V_38 )
V_20 = V_38 -> V_20 ;
if ( F_2 ( V_1 , V_1 -> V_43 ,
V_20 , V_39 , V_41 ) ) {
free ( V_39 ) ;
return - V_44 ;
}
V_40 = F_8 ( V_39 , V_45 ) ;
free ( V_39 ) ;
return V_40 ;
}
int F_9 ( struct V_1 * V_1 , struct V_38 * V_38 )
{
static enum V_19 V_46 [] = {
V_7 ,
V_12 ,
V_18 ,
} ;
int V_47 = 0 ;
if ( V_1 -> V_43 != V_18 )
return F_7 ( V_1 , V_38 ) ;
do {
int V_40 ;
V_1 -> V_43 = V_46 [ V_47 ++ ] ;
V_40 = F_7 ( V_1 , V_38 ) ;
if ( V_40 >= 0 )
return V_40 ;
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
static struct V_52 *
F_15 ( struct V_48 * V_49 , T_2 V_54 )
{
struct V_50 * * V_55 = & V_49 -> V_50 ;
struct V_50 * V_56 = NULL ;
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
int V_40 ;
V_40 = F_9 ( V_1 , V_38 ) ;
if ( V_40 < 0 )
return - 1 ;
do {
T_2 V_63 ;
V_25 = - V_42 ;
V_53 = F_22 ( sizeof( * V_53 ) + V_58 ) ;
if ( ! V_53 )
break;
V_63 = V_54 & V_65 ;
V_25 = - V_44 ;
if ( - 1 == F_23 ( V_40 , V_63 , V_66 ) )
break;
V_25 = F_24 ( V_40 , V_53 -> V_62 , V_58 ) ;
if ( V_25 <= 0 )
break;
V_53 -> V_54 = V_63 ;
V_53 -> V_22 = V_25 ;
F_16 ( & V_1 -> V_53 , V_53 ) ;
V_25 = F_19 ( V_53 , V_54 , V_62 , V_22 ) ;
} while ( 0 );
if ( V_25 <= 0 )
free ( V_53 ) ;
F_25 ( V_40 ) ;
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
struct V_68 * F_30 ( const char * V_39 )
{
struct V_68 * V_68 = NULL ;
struct V_1 * V_1 = F_31 ( V_39 ) ;
if ( V_1 )
V_68 = F_32 ( 0 , V_1 , V_71 ) ;
return V_68 ;
}
struct V_1 * F_33 ( struct V_38 * V_38 , const char * V_39 ,
const char * V_72 , int V_73 )
{
struct V_1 * V_1 = F_34 ( & V_38 -> V_74 , V_39 ) ;
if ( V_1 != NULL ) {
F_35 ( V_1 , V_72 ) ;
V_1 -> V_75 = V_73 ;
}
return V_1 ;
}
void F_36 ( struct V_1 * V_1 , char * V_39 )
{
if ( V_39 == NULL )
return;
V_1 -> V_27 = V_39 ;
V_1 -> V_28 = strlen ( V_39 ) ;
}
void F_35 ( struct V_1 * V_1 , const char * V_39 )
{
if ( V_39 == NULL )
return;
V_1 -> V_72 = V_39 ;
V_1 -> V_76 = strlen ( V_39 ) ;
}
static void F_37 ( struct V_1 * V_1 )
{
F_35 ( V_1 , F_38 ( V_1 -> V_27 ) ) ;
}
int F_39 ( const struct V_1 * V_1 )
{
if ( ! V_1 )
return strlen ( L_9 ) ;
if ( V_77 )
return V_1 -> V_28 ;
return V_1 -> V_76 ;
}
bool F_40 ( const struct V_1 * V_1 , enum V_78 type )
{
return V_1 -> V_79 & ( 1 << type ) ;
}
bool F_41 ( const struct V_1 * V_1 , enum V_78 type )
{
return V_1 -> V_80 & ( 1 << type ) ;
}
void F_42 ( struct V_1 * V_1 , enum V_78 type )
{
V_1 -> V_80 |= ( 1 << type ) ;
}
struct V_1 * F_31 ( const char * V_39 )
{
struct V_1 * V_1 = calloc ( 1 , sizeof( * V_1 ) + strlen ( V_39 ) + 1 ) ;
if ( V_1 != NULL ) {
int V_47 ;
strcpy ( V_1 -> V_39 , V_39 ) ;
F_36 ( V_1 , V_1 -> V_39 ) ;
F_35 ( V_1 , V_1 -> V_39 ) ;
for ( V_47 = 0 ; V_47 < V_81 ; ++ V_47 )
V_1 -> V_82 [ V_47 ] = V_1 -> V_83 [ V_47 ] = V_84 ;
V_1 -> V_53 = V_84 ;
V_1 -> V_17 = V_18 ;
V_1 -> V_43 = V_18 ;
V_1 -> V_79 = 0 ;
V_1 -> V_85 = 0 ;
V_1 -> V_80 = 0 ;
V_1 -> V_34 = 0 ;
V_1 -> V_86 = 1 ;
V_1 -> V_75 = V_87 ;
V_1 -> V_88 = V_89 ;
F_43 ( & V_1 -> V_90 ) ;
}
return V_1 ;
}
void F_44 ( struct V_1 * V_1 )
{
int V_47 ;
for ( V_47 = 0 ; V_47 < V_81 ; ++ V_47 )
F_45 ( & V_1 -> V_82 [ V_47 ] ) ;
if ( V_1 -> V_91 )
free ( ( char * ) V_1 -> V_72 ) ;
if ( V_1 -> V_92 )
free ( V_1 -> V_27 ) ;
F_10 ( & V_1 -> V_53 ) ;
free ( V_1 ) ;
}
void F_46 ( struct V_1 * V_1 , void * V_35 )
{
memcpy ( V_1 -> V_35 , V_35 , sizeof( V_1 -> V_35 ) ) ;
V_1 -> V_34 = 1 ;
}
bool F_47 ( const struct V_1 * V_1 , T_4 * V_35 )
{
return memcmp ( V_1 -> V_35 , V_35 , sizeof( V_1 -> V_35 ) ) == 0 ;
}
void F_48 ( struct V_1 * V_1 , struct V_38 * V_38 )
{
char V_93 [ V_41 ] ;
if ( F_49 ( V_38 ) )
return;
sprintf ( V_93 , L_10 , V_38 -> V_20 ) ;
if ( F_50 ( V_93 , V_1 -> V_35 ,
sizeof( V_1 -> V_35 ) ) == 0 )
V_1 -> V_34 = true ;
}
int F_51 ( struct V_1 * V_1 ,
const char * V_20 )
{
char V_94 [ V_41 ] ;
const char * V_39 = V_1 -> V_72 + 1 ;
snprintf ( V_94 , sizeof( V_94 ) ,
L_11 ,
V_20 , ( int ) strlen ( V_39 ) - 1 , V_39 ) ;
if ( F_50 ( V_94 , V_1 -> V_35 ,
sizeof( V_1 -> V_35 ) ) == 0 )
V_1 -> V_34 = true ;
return 0 ;
}
bool F_52 ( struct V_95 * V_96 , bool V_97 )
{
bool V_98 = false ;
struct V_1 * V_99 ;
F_53 (pos, head, node) {
if ( V_97 && ! V_99 -> V_100 )
continue;
if ( V_99 -> V_34 ) {
V_98 = true ;
continue;
}
if ( F_54 ( V_99 -> V_27 , V_99 -> V_35 ,
sizeof( V_99 -> V_35 ) ) > 0 ) {
V_98 = true ;
V_99 -> V_34 = true ;
}
}
return V_98 ;
}
void F_55 ( struct V_95 * V_96 , struct V_1 * V_1 )
{
F_56 ( & V_1 -> V_90 , V_96 ) ;
}
struct V_1 * F_57 ( struct V_95 * V_96 , const char * V_39 , bool V_101 )
{
struct V_1 * V_99 ;
if ( V_101 ) {
F_53 (pos, head, node)
if ( strcmp ( V_99 -> V_72 , V_39 ) == 0 )
return V_99 ;
return NULL ;
}
F_53 (pos, head, node)
if ( strcmp ( V_99 -> V_27 , V_39 ) == 0 )
return V_99 ;
return NULL ;
}
struct V_1 * F_34 ( struct V_95 * V_96 , const char * V_39 )
{
struct V_1 * V_1 = F_57 ( V_96 , V_39 , false ) ;
if ( ! V_1 ) {
V_1 = F_31 ( V_39 ) ;
if ( V_1 != NULL ) {
F_55 ( V_96 , V_1 ) ;
F_37 ( V_1 ) ;
}
}
return V_1 ;
}
T_1 F_58 ( struct V_95 * V_96 , T_5 * V_102 ,
bool (F_59)( struct V_1 * V_1 , int V_103 ) , int V_103 )
{
struct V_1 * V_99 ;
T_1 V_25 = 0 ;
F_53 (pos, head, node) {
if ( F_59 && F_59 ( V_99 , V_103 ) )
continue;
V_25 += F_60 ( V_99 , V_102 ) ;
V_25 += fprintf ( V_102 , L_12 , V_99 -> V_27 ) ;
}
return V_25 ;
}
T_1 F_61 ( struct V_95 * V_96 , T_5 * V_102 )
{
struct V_1 * V_99 ;
T_1 V_25 = 0 ;
F_53 (pos, head, node) {
int V_47 ;
for ( V_47 = 0 ; V_47 < V_81 ; ++ V_47 )
V_25 += F_62 ( V_99 , V_47 , V_102 ) ;
}
return V_25 ;
}
T_1 F_60 ( struct V_1 * V_1 , T_5 * V_102 )
{
char V_104 [ V_24 * 2 + 1 ] ;
F_6 ( V_1 -> V_35 , sizeof( V_1 -> V_35 ) , V_104 ) ;
return fprintf ( V_102 , L_3 , V_104 ) ;
}
T_1 F_62 ( struct V_1 * V_1 , enum V_78 type , T_5 * V_102 )
{
struct V_50 * V_105 ;
T_1 V_25 = fprintf ( V_102 , L_13 , V_1 -> V_72 ) ;
if ( V_1 -> V_72 != V_1 -> V_27 )
V_25 += fprintf ( V_102 , L_14 , V_1 -> V_27 ) ;
V_25 += fprintf ( V_102 , L_15 , V_106 [ type ] ,
F_40 ( V_1 , type ) ? L_8 : L_16 ) ;
V_25 += F_60 ( V_1 , V_102 ) ;
V_25 += fprintf ( V_102 , L_17 ) ;
for ( V_105 = F_11 ( & V_1 -> V_82 [ type ] ) ; V_105 ; V_105 = F_13 ( V_105 ) ) {
struct V_107 * V_99 = F_12 ( V_105 , struct V_107 , V_50 ) ;
V_25 += F_63 ( V_99 , V_102 ) ;
}
return V_25 ;
}
