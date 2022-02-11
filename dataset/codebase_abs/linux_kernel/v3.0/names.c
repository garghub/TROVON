static unsigned int F_1 ( unsigned int V_1 )
{
unsigned int V_2 = V_3 << 27 , V_4 = V_5 << 27 ;
for (; V_2 >= V_3 ; V_2 >>= 1 , V_4 >>= 1 )
if ( V_1 & V_2 )
V_1 ^= V_4 ;
return V_1 & ( V_6 - 1 ) ;
}
static const char * F_2 ( struct V_7 * V_8 [ V_6 ] , unsigned int V_9 )
{
struct V_7 * V_10 ;
for ( V_10 = V_8 [ F_1 ( V_9 ) ] ; V_10 ; V_10 = V_10 -> V_11 )
if ( V_10 -> V_1 == V_9 )
return V_10 -> V_12 ;
return NULL ;
}
const char * F_3 ( T_1 V_13 )
{
return F_2 ( V_14 , V_13 ) ;
}
const char * F_4 ( T_1 V_15 )
{
return F_2 ( V_16 , V_15 ) ;
}
const char * F_5 ( unsigned int V_17 )
{
return F_2 ( V_18 , V_17 ) ;
}
const char * F_6 ( unsigned int V_17 )
{
return F_2 ( V_19 , V_17 ) ;
}
const char * F_7 ( T_2 V_20 )
{
return F_2 ( V_21 , V_20 ) ;
}
const char * F_8 ( T_1 V_22 )
{
return F_2 ( V_23 , V_22 ) ;
}
const char * F_9 ( T_1 V_24 )
{
return F_2 ( V_25 , V_24 ) ;
}
const char * F_10 ( unsigned int V_26 )
{
return F_2 ( V_27 , V_26 ) ;
}
const char * F_11 ( T_2 V_28 )
{
struct V_29 * V_30 ;
V_30 = V_31 [ F_1 ( V_28 ) ] ;
for (; V_30 ; V_30 = V_30 -> V_11 )
if ( V_30 -> V_28 == V_28 )
return V_30 -> V_12 ;
return NULL ;
}
const char * F_12 ( T_2 V_28 , T_2 V_32 )
{
struct V_33 * V_34 ;
V_34 = V_35 [ F_1 ( ( V_28 << 16 ) | V_32 ) ] ;
for (; V_34 ; V_34 = V_34 -> V_11 )
if ( V_34 -> V_28 == V_28 && V_34 -> V_32 == V_32 )
return V_34 -> V_12 ;
return NULL ;
}
const char * F_13 ( T_1 V_36 )
{
struct V_37 * V_38 ;
V_38 = V_39 [ F_1 ( V_36 ) ] ;
for (; V_38 ; V_38 = V_38 -> V_11 )
if ( V_38 -> V_36 == V_36 )
return V_38 -> V_12 ;
return NULL ;
}
const char * F_14 ( T_1 V_36 , T_1 V_40 )
{
struct V_41 * V_42 ;
V_42 = V_43 [ F_1 ( ( V_36 << 8 ) | V_40 ) ] ;
for (; V_42 ; V_42 = V_42 -> V_11 )
if ( V_42 -> V_36 == V_36 && V_42 -> V_40 == V_40 )
return V_42 -> V_12 ;
return NULL ;
}
const char * F_15 ( T_1 V_36 , T_1 V_40 , T_1 V_44 )
{
struct V_45 * V_34 ;
V_34 = V_46 [ F_1 ( ( V_36 << 16 ) | ( V_40 << 8 ) | V_44 ) ] ;
for (; V_34 ; V_34 = V_34 -> V_11 )
if ( V_34 -> V_36 == V_36 && V_34 -> V_40 == V_40 && V_34 -> V_44 == V_44 )
return V_34 -> V_12 ;
return NULL ;
}
const char * F_16 ( T_2 V_47 )
{
struct V_48 * V_49 ;
V_49 = V_50 [ F_1 ( V_47 ) ] ;
for (; V_49 ; V_49 = V_49 -> V_11 )
if ( V_49 -> V_47 == V_47 )
return V_49 -> V_12 ;
return NULL ;
}
static void * F_17 ( T_3 V_51 )
{
struct V_52 * V_34 ;
V_34 = calloc ( 1 , sizeof( struct V_52 ) ) ;
if ( ! V_34 ) {
free ( V_34 ) ;
return NULL ;
}
V_34 -> V_53 = calloc ( 1 , V_51 ) ;
if ( ! V_34 -> V_53 )
return NULL ;
V_34 -> V_11 = V_54 ;
V_54 = V_34 ;
return V_34 -> V_53 ;
}
void F_18 ( void )
{
struct V_52 * V_52 ;
if ( ! V_54 )
return;
for ( V_52 = V_54 ; V_52 != NULL ; ) {
struct V_52 * V_55 ;
if ( V_52 -> V_53 )
free ( V_52 -> V_53 ) ;
V_55 = V_52 ;
V_52 = V_52 -> V_11 ;
free ( V_55 ) ;
}
}
static int F_19 ( const char * V_12 , T_2 V_28 )
{
struct V_29 * V_30 ;
unsigned int V_10 = F_1 ( V_28 ) ;
V_30 = V_31 [ V_10 ] ;
for (; V_30 ; V_30 = V_30 -> V_11 )
if ( V_30 -> V_28 == V_28 )
return - 1 ;
V_30 = F_17 ( sizeof( struct V_29 ) + strlen ( V_12 ) ) ;
if ( ! V_30 )
return - 1 ;
strcpy ( V_30 -> V_12 , V_12 ) ;
V_30 -> V_28 = V_28 ;
V_30 -> V_11 = V_31 [ V_10 ] ;
V_31 [ V_10 ] = V_30 ;
return 0 ;
}
static int F_20 ( const char * V_12 , T_2 V_28 , T_2 V_32 )
{
struct V_33 * V_34 ;
unsigned int V_10 = F_1 ( ( V_28 << 16 ) | V_32 ) ;
V_34 = V_35 [ V_10 ] ;
for (; V_34 ; V_34 = V_34 -> V_11 )
if ( V_34 -> V_28 == V_28 && V_34 -> V_32 == V_32 )
return - 1 ;
V_34 = F_17 ( sizeof( struct V_33 ) + strlen ( V_12 ) ) ;
if ( ! V_34 )
return - 1 ;
strcpy ( V_34 -> V_12 , V_12 ) ;
V_34 -> V_28 = V_28 ;
V_34 -> V_32 = V_32 ;
V_34 -> V_11 = V_35 [ V_10 ] ;
V_35 [ V_10 ] = V_34 ;
return 0 ;
}
static int F_21 ( const char * V_12 , T_1 V_36 )
{
struct V_37 * V_38 ;
unsigned int V_10 = F_1 ( V_36 ) ;
V_38 = V_39 [ V_10 ] ;
for (; V_38 ; V_38 = V_38 -> V_11 )
if ( V_38 -> V_36 == V_36 )
return - 1 ;
V_38 = F_17 ( sizeof( struct V_37 ) + strlen ( V_12 ) ) ;
if ( ! V_38 )
return - 1 ;
strcpy ( V_38 -> V_12 , V_12 ) ;
V_38 -> V_36 = V_36 ;
V_38 -> V_11 = V_39 [ V_10 ] ;
V_39 [ V_10 ] = V_38 ;
return 0 ;
}
static int F_22 ( const char * V_12 , T_1 V_36 , T_1 V_40 )
{
struct V_41 * V_42 ;
unsigned int V_10 = F_1 ( ( V_36 << 8 ) | V_40 ) ;
V_42 = V_43 [ V_10 ] ;
for (; V_42 ; V_42 = V_42 -> V_11 )
if ( V_42 -> V_36 == V_36 && V_42 -> V_40 == V_40 )
return - 1 ;
V_42 = F_17 ( sizeof( struct V_41 ) + strlen ( V_12 ) ) ;
if ( ! V_42 )
return - 1 ;
strcpy ( V_42 -> V_12 , V_12 ) ;
V_42 -> V_36 = V_36 ;
V_42 -> V_40 = V_40 ;
V_42 -> V_11 = V_43 [ V_10 ] ;
V_43 [ V_10 ] = V_42 ;
return 0 ;
}
static int F_23 ( const char * V_12 , T_1 V_36 , T_1 V_40 , T_1 V_44 )
{
struct V_45 * V_34 ;
unsigned int V_10 = F_1 ( ( V_36 << 16 ) | ( V_40 << 8 ) | V_44 ) ;
V_34 = V_46 [ V_10 ] ;
for (; V_34 ; V_34 = V_34 -> V_11 )
if ( V_34 -> V_36 == V_36 && V_34 -> V_40 == V_40 && V_34 -> V_44 == V_44 )
return - 1 ;
V_34 = F_17 ( sizeof( struct V_45 ) + strlen ( V_12 ) ) ;
if ( ! V_34 )
return - 1 ;
strcpy ( V_34 -> V_12 , V_12 ) ;
V_34 -> V_36 = V_36 ;
V_34 -> V_40 = V_40 ;
V_34 -> V_44 = V_44 ;
V_34 -> V_11 = V_46 [ V_10 ] ;
V_46 [ V_10 ] = V_34 ;
return 0 ;
}
static int F_24 ( const char * V_12 , T_2 V_47 )
{
struct V_48 * V_49 ;
unsigned int V_10 = F_1 ( V_47 ) ;
V_49 = V_50 [ V_10 ] ;
for (; V_49 ; V_49 = V_49 -> V_11 )
if ( V_49 -> V_47 == V_47 )
return - 1 ;
V_49 = F_17 ( sizeof( struct V_48 ) + strlen ( V_12 ) ) ;
if ( ! V_49 )
return - 1 ;
strcpy ( V_49 -> V_12 , V_12 ) ;
V_49 -> V_47 = V_47 ;
V_49 -> V_11 = V_50 [ V_10 ] ;
V_50 [ V_10 ] = V_49 ;
return 0 ;
}
static int F_25 ( struct V_7 * V_8 [ V_6 ] , const char * V_12 , unsigned int V_9 )
{
struct V_7 * V_56 ;
unsigned int V_10 = F_1 ( V_9 ) ;
for ( V_56 = V_8 [ V_10 ] ; V_56 ; V_56 = V_56 -> V_11 )
if ( V_56 -> V_1 == V_9 )
return - 1 ;
V_56 = F_17 ( sizeof( struct V_7 ) + strlen ( V_12 ) ) ;
if ( ! V_56 )
return - 1 ;
strcpy ( V_56 -> V_12 , V_12 ) ;
V_56 -> V_1 = V_9 ;
V_56 -> V_11 = V_8 [ V_10 ] ;
V_8 [ V_10 ] = V_56 ;
return 0 ;
}
static int F_26 ( const char * V_12 , T_1 V_13 )
{
return F_25 ( V_14 , V_12 , V_13 ) ;
}
static int F_27 ( const char * V_12 , T_1 V_15 )
{
return F_25 ( V_16 , V_12 , V_15 ) ;
}
static int F_28 ( const char * V_12 , unsigned int V_17 )
{
return F_25 ( V_18 , V_12 , V_17 ) ;
}
static int F_29 ( const char * V_12 , unsigned int V_17 )
{
return F_25 ( V_19 , V_12 , V_17 ) ;
}
static int F_30 ( const char * V_12 , T_2 V_20 )
{
return F_25 ( V_21 , V_12 , V_20 ) ;
}
static int F_31 ( const char * V_12 , T_1 V_22 )
{
return F_25 ( V_23 , V_12 , V_22 ) ;
}
static int F_32 ( const char * V_12 , T_1 V_24 )
{
return F_25 ( V_25 , V_12 , V_24 ) ;
}
static int F_33 ( const char * V_12 , unsigned int V_26 )
{
return F_25 ( V_27 , V_12 , V_26 ) ;
}
static void F_34 ( T_4 * V_57 )
{
char V_58 [ 512 ] , * V_59 ;
unsigned int V_60 = 0 ;
int V_61 = - 1 , V_62 = - 1 , V_63 = - 1 , V_64 = - 1 , V_65 = - 1 ;
unsigned int V_66 ;
while ( fgets ( V_58 , sizeof( V_58 ) , V_57 ) ) {
V_60 ++ ;
if ( ( V_59 = strchr ( V_58 , 13 ) ) )
* V_59 = 0 ;
if ( ( V_59 = strchr ( V_58 , 10 ) ) )
* V_59 = 0 ;
if ( V_58 [ 0 ] == '#' || ! V_58 [ 0 ] )
continue;
V_59 = V_58 ;
if ( V_58 [ 0 ] == 'P' && V_58 [ 1 ] == 'H' && V_58 [ 2 ] == 'Y' && V_58 [ 3 ] == 'S' && V_58 [ 4 ] == 'D' &&
V_58 [ 5 ] == 'E' && V_58 [ 6 ] == 'S' && V_58 [ 7 ] == ' ' ) {
V_59 = V_58 + 8 ;
while ( isspace ( * V_59 ) )
V_59 ++ ;
if ( ! isxdigit ( * V_59 ) ) {
fprintf ( V_67 , L_1 , V_60 ) ;
continue;
}
V_66 = strtoul ( V_59 , & V_59 , 16 ) ;
while ( isspace ( * V_59 ) )
V_59 ++ ;
if ( ! * V_59 ) {
fprintf ( V_67 , L_1 , V_60 ) ;
continue;
}
if ( F_31 ( V_59 , V_66 ) )
fprintf ( V_67 , L_2 , V_60 , V_66 , V_59 ) ;
F_35 ( printf ( L_3 , V_60 , V_66 , V_59 ) ) ;
continue;
}
if ( V_58 [ 0 ] == 'P' && V_58 [ 1 ] == 'H' && V_58 [ 2 ] == 'Y' && V_58 [ 3 ] == ' ' ) {
V_59 = V_58 + 4 ;
while ( isspace ( * V_59 ) )
V_59 ++ ;
if ( ! isxdigit ( * V_59 ) ) {
fprintf ( V_67 , L_4 , V_60 ) ;
continue;
}
V_66 = strtoul ( V_59 , & V_59 , 16 ) ;
while ( isspace ( * V_59 ) )
V_59 ++ ;
if ( ! * V_59 ) {
fprintf ( V_67 , L_4 , V_60 ) ;
continue;
}
if ( F_31 ( V_59 , V_66 ) )
fprintf ( V_67 , L_5 , V_60 , V_66 , V_59 ) ;
F_35 ( printf ( L_6 , V_60 , V_66 , V_59 ) ) ;
continue;
}
if ( V_58 [ 0 ] == 'B' && V_58 [ 1 ] == 'I' && V_58 [ 2 ] == 'A' && V_58 [ 3 ] == 'S' && V_58 [ 4 ] == ' ' ) {
V_59 = V_58 + 5 ;
while ( isspace ( * V_59 ) )
V_59 ++ ;
if ( ! isxdigit ( * V_59 ) ) {
fprintf ( V_67 , L_7 , V_60 ) ;
continue;
}
V_66 = strtoul ( V_59 , & V_59 , 16 ) ;
while ( isspace ( * V_59 ) )
V_59 ++ ;
if ( ! * V_59 ) {
fprintf ( V_67 , L_7 , V_60 ) ;
continue;
}
if ( F_32 ( V_59 , V_66 ) )
fprintf ( V_67 , L_8 , V_60 , V_66 , V_59 ) ;
F_35 ( printf ( L_9 , V_60 , V_66 , V_59 ) ) ;
continue;
}
if ( V_58 [ 0 ] == 'L' && V_58 [ 1 ] == ' ' ) {
V_59 = V_58 + 2 ;
while ( isspace ( * V_59 ) )
V_59 ++ ;
if ( ! isxdigit ( * V_59 ) ) {
fprintf ( V_67 , L_10 , V_60 ) ;
continue;
}
V_66 = strtoul ( V_59 , & V_59 , 16 ) ;
while ( isspace ( * V_59 ) )
V_59 ++ ;
if ( ! * V_59 ) {
fprintf ( V_67 , L_10 , V_60 ) ;
continue;
}
if ( F_30 ( V_59 , V_66 ) )
fprintf ( V_67 , L_11 , V_60 , V_66 , V_59 ) ;
F_35 ( printf ( L_12 , V_60 , V_66 , V_59 ) ) ;
V_64 = V_62 = V_61 = V_63 = - 1 ;
V_65 = V_66 ;
continue;
}
if ( V_58 [ 0 ] == 'C' && V_58 [ 1 ] == ' ' ) {
V_59 = V_58 + 2 ;
while ( isspace ( * V_59 ) )
V_59 ++ ;
if ( ! isxdigit ( * V_59 ) ) {
fprintf ( V_67 , L_13 , V_60 ) ;
continue;
}
V_66 = strtoul ( V_59 , & V_59 , 16 ) ;
while ( isspace ( * V_59 ) )
V_59 ++ ;
if ( ! * V_59 ) {
fprintf ( V_67 , L_13 , V_60 ) ;
continue;
}
if ( F_21 ( V_59 , V_66 ) )
fprintf ( V_67 , L_14 , V_60 , V_66 , V_59 ) ;
F_35 ( printf ( L_15 , V_60 , V_66 , V_59 ) ) ;
V_64 = V_65 = V_61 = V_63 = - 1 ;
V_62 = V_66 ;
continue;
}
if ( V_58 [ 0 ] == 'A' && V_58 [ 1 ] == 'T' && isspace ( V_58 [ 2 ] ) ) {
V_59 = V_58 + 3 ;
while ( isspace ( * V_59 ) )
V_59 ++ ;
if ( ! isxdigit ( * V_59 ) ) {
fprintf ( V_67 , L_16 , V_60 ) ;
continue;
}
V_66 = strtoul ( V_59 , & V_59 , 16 ) ;
while ( isspace ( * V_59 ) )
V_59 ++ ;
if ( ! * V_59 ) {
fprintf ( V_67 , L_16 , V_60 ) ;
continue;
}
if ( F_24 ( V_59 , V_66 ) )
fprintf ( V_67 , L_17 , V_60 , V_66 , V_59 ) ;
F_35 ( printf ( L_18 , V_60 , V_66 , V_59 ) ) ;
continue;
}
if ( V_58 [ 0 ] == 'H' && V_58 [ 1 ] == 'C' && V_58 [ 2 ] == 'C' && isspace ( V_58 [ 3 ] ) ) {
V_59 = V_58 + 3 ;
while ( isspace ( * V_59 ) )
V_59 ++ ;
if ( ! isxdigit ( * V_59 ) ) {
fprintf ( V_67 , L_19 , V_60 ) ;
continue;
}
V_66 = strtoul ( V_59 , & V_59 , 10 ) ;
while ( isspace ( * V_59 ) )
V_59 ++ ;
if ( ! * V_59 ) {
fprintf ( V_67 , L_19 , V_60 ) ;
continue;
}
if ( F_33 ( V_59 , V_66 ) )
fprintf ( V_67 , L_20 , V_60 , V_66 , V_59 ) ;
F_35 ( printf ( L_21 , V_60 , V_66 , V_59 ) ) ;
continue;
}
if ( isxdigit ( * V_59 ) ) {
V_66 = strtoul ( V_59 , & V_59 , 16 ) ;
while ( isspace ( * V_59 ) )
V_59 ++ ;
if ( ! * V_59 ) {
fprintf ( V_67 , L_22 , V_60 ) ;
continue;
}
if ( F_19 ( V_59 , V_66 ) )
fprintf ( V_67 , L_23 , V_60 , V_66 , V_59 ) ;
F_35 ( printf ( L_24 , V_60 , V_66 , V_59 ) ) ;
V_61 = V_66 ;
V_64 = V_65 = V_62 = V_63 = - 1 ;
continue;
}
if ( V_58 [ 0 ] == '\t' && isxdigit ( V_58 [ 1 ] ) ) {
V_66 = strtoul ( V_58 + 1 , & V_59 , 16 ) ;
while ( isspace ( * V_59 ) )
V_59 ++ ;
if ( ! * V_59 ) {
fprintf ( V_67 , L_25 , V_60 ) ;
continue;
}
if ( V_61 != - 1 ) {
if ( F_20 ( V_59 , V_61 , V_66 ) )
fprintf ( V_67 , L_26 , V_60 , V_61 , V_66 , V_59 ) ;
F_35 ( printf ( L_27 , V_60 , V_61 , V_66 , V_59 ) ) ;
continue;
}
if ( V_62 != - 1 ) {
if ( F_22 ( V_59 , V_62 , V_66 ) )
fprintf ( V_67 , L_28 , V_60 , V_62 , V_66 , V_59 ) ;
F_35 ( printf ( L_29 , V_60 , V_62 , V_66 , V_59 ) ) ;
V_63 = V_66 ;
continue;
}
if ( V_64 != - 1 ) {
if ( F_29 ( V_59 , ( V_64 << 16 ) + V_66 ) )
fprintf ( V_67 , L_30 , V_60 ) ;
continue;
}
if ( V_65 != - 1 ) {
if ( F_30 ( V_59 , V_65 + ( V_66 << 10 ) ) )
fprintf ( V_67 , L_31 , V_60 ) ;
continue;
}
fprintf ( V_67 , L_32 , V_60 ) ;
continue;
}
if ( V_58 [ 0 ] == '\t' && V_58 [ 1 ] == '\t' && isxdigit ( V_58 [ 2 ] ) ) {
V_66 = strtoul ( V_58 + 2 , & V_59 , 16 ) ;
while ( isspace ( * V_59 ) )
V_59 ++ ;
if ( ! * V_59 ) {
fprintf ( V_67 , L_33 , V_60 ) ;
continue;
}
if ( V_62 != - 1 && V_63 != - 1 ) {
if ( F_23 ( V_59 , V_62 , V_63 , V_66 ) )
fprintf ( V_67 , L_34 , V_60 , V_62 , V_63 , V_66 , V_59 ) ;
F_35 ( printf ( L_35 , V_60 , V_62 , V_63 , V_66 , V_59 ) ) ;
continue;
}
fprintf ( V_67 , L_36 , V_60 ) ;
continue;
}
if ( V_58 [ 0 ] == 'H' && V_58 [ 1 ] == 'I' && V_58 [ 2 ] == 'D' && V_58 [ 3 ] == ' ' ) {
V_59 = V_58 + 4 ;
while ( isspace ( * V_59 ) )
V_59 ++ ;
if ( ! isxdigit ( * V_59 ) ) {
fprintf ( V_67 , L_37 , V_60 ) ;
continue;
}
V_66 = strtoul ( V_59 , & V_59 , 16 ) ;
while ( isspace ( * V_59 ) )
V_59 ++ ;
if ( ! * V_59 ) {
fprintf ( V_67 , L_37 , V_60 ) ;
continue;
}
if ( F_26 ( V_59 , V_66 ) )
fprintf ( V_67 , L_38 , V_60 , V_66 , V_59 ) ;
F_35 ( printf ( L_39 , V_60 , V_66 , V_59 ) ) ;
continue;
}
if ( V_58 [ 0 ] == 'H' && V_58 [ 1 ] == 'U' && V_58 [ 2 ] == 'T' && V_58 [ 3 ] == ' ' ) {
V_59 = V_58 + 4 ;
while ( isspace ( * V_59 ) )
V_59 ++ ;
if ( ! isxdigit ( * V_59 ) ) {
fprintf ( V_67 , L_40 , V_60 ) ;
continue;
}
V_66 = strtoul ( V_59 , & V_59 , 16 ) ;
while ( isspace ( * V_59 ) )
V_59 ++ ;
if ( ! * V_59 ) {
fprintf ( V_67 , L_40 , V_60 ) ;
continue;
}
if ( F_28 ( V_59 , V_66 ) )
fprintf ( V_67 , L_41 , V_60 , V_66 , V_59 ) ;
V_65 = V_62 = V_61 = V_63 = - 1 ;
V_64 = V_66 ;
F_35 ( printf ( L_42 , V_60 , V_66 , V_59 ) ) ;
continue;
}
if ( V_58 [ 0 ] == 'R' && V_58 [ 1 ] == ' ' ) {
V_59 = V_58 + 2 ;
while ( isspace ( * V_59 ) )
V_59 ++ ;
if ( ! isxdigit ( * V_59 ) ) {
fprintf ( V_67 , L_43 , V_60 ) ;
continue;
}
V_66 = strtoul ( V_59 , & V_59 , 16 ) ;
while ( isspace ( * V_59 ) )
V_59 ++ ;
if ( ! * V_59 ) {
fprintf ( V_67 , L_43 , V_60 ) ;
continue;
}
if ( F_27 ( V_59 , V_66 ) )
fprintf ( V_67 , L_44 , V_60 , V_66 , V_59 ) ;
F_35 ( printf ( L_45 , V_60 , V_66 , V_59 ) ) ;
continue;
}
if ( V_58 [ 0 ] == 'V' && V_58 [ 1 ] == 'T' ) {
continue;
}
fprintf ( V_67 , L_46 , V_60 ) ;
}
}
int F_36 ( char * V_68 )
{
T_4 * V_57 ;
if ( ! ( V_57 = fopen ( V_68 , L_47 ) ) ) {
return V_69 ;
}
F_34 ( V_57 ) ;
fclose ( V_57 ) ;
return 0 ;
}
