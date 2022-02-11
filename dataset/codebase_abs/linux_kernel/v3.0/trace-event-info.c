static void F_1 ( const char * V_1 , ... )
{
T_1 V_2 ;
int V_3 = V_4 ;
if ( V_4 )
perror ( L_1 ) ;
else
V_3 = - 1 ;
va_start ( V_2 , V_1 ) ;
fprintf ( V_5 , L_2 ) ;
vfprintf ( V_5 , V_1 , V_2 ) ;
va_end ( V_2 ) ;
fprintf ( V_5 , L_3 ) ;
exit ( V_3 ) ;
}
void * F_2 ( unsigned int V_6 )
{
void * V_7 ;
V_7 = malloc ( V_6 ) ;
if ( ! V_7 )
F_1 ( L_4 ) ;
return V_7 ;
}
static const char * F_3 ( void )
{
const char * V_8 = F_4 ( NULL ) ;
if ( ! V_8 )
F_1 ( L_5 ) ;
return V_8 ;
}
static const char * F_5 ( void )
{
static char * V_9 ;
static int V_10 ;
const char * V_11 ;
if ( V_10 )
return V_9 ;
V_11 = F_3 () ;
V_9 = F_2 ( strlen ( V_11 ) + 9 ) ;
sprintf ( V_9 , L_6 , V_11 ) ;
V_10 = 1 ;
return V_9 ;
}
static char * F_6 ( const char * V_12 )
{
const char * V_9 ;
char * V_13 ;
V_9 = F_5 () ;
if ( ! V_9 )
return NULL ;
V_13 = F_2 ( strlen ( V_9 ) + strlen ( V_12 ) + 2 ) ;
sprintf ( V_13 , L_7 , V_9 , V_12 ) ;
return V_13 ;
}
static void F_7 ( char * V_13 )
{
free ( V_13 ) ;
}
static T_2 F_8 ( const void * V_14 , T_3 V_15 )
{
int V_3 ;
if ( V_16 ) {
V_16 += V_15 ;
return V_15 ;
}
V_3 = F_9 ( V_17 , V_14 , V_15 ) ;
if ( V_3 < 0 )
F_1 ( L_8 , V_18 ) ;
return V_3 ;
}
int F_10 ( void )
{
unsigned char V_19 [] = { 0x1 , 0x2 , 0x3 , 0x4 , 0x0 , 0x0 , 0x0 , 0x0 } ;
unsigned int * V_20 ;
V_20 = ( unsigned int * ) ( void * ) V_19 ;
return * V_20 == 0x01020304 ;
}
static unsigned long long F_11 ( int V_21 )
{
unsigned long long V_6 = 0 ;
char V_14 [ V_22 ] ;
int V_23 ;
do {
V_23 = F_12 ( V_21 , V_14 , V_22 ) ;
if ( V_23 > 0 ) {
V_6 += V_23 ;
F_8 ( V_14 , V_23 ) ;
}
} while ( V_23 > 0 );
return V_6 ;
}
static unsigned long long F_13 ( const char * V_13 )
{
unsigned long long V_6 = 0 ;
int V_21 ;
V_21 = F_14 ( V_13 , V_24 ) ;
if ( V_21 < 0 )
F_1 ( L_9 , V_13 ) ;
V_6 = F_11 ( V_21 ) ;
F_15 ( V_21 ) ;
return V_6 ;
}
static unsigned long F_16 ( int V_21 )
{
unsigned long long V_6 = 0 ;
char V_14 [ V_22 ] ;
int V_23 ;
do {
V_23 = F_12 ( V_21 , V_14 , V_22 ) ;
if ( V_23 > 0 )
V_6 += V_23 ;
} while ( V_23 > 0 );
F_17 ( V_21 , 0 , V_25 ) ;
return V_6 ;
}
static unsigned long F_18 ( const char * V_13 )
{
unsigned long long V_6 = 0 ;
int V_21 ;
V_21 = F_14 ( V_13 , V_24 ) ;
if ( V_21 < 0 )
F_1 ( L_9 , V_13 ) ;
V_6 = F_16 ( V_21 ) ;
F_15 ( V_21 ) ;
return V_6 ;
}
static void F_19 ( void )
{
unsigned long long V_6 , V_26 ;
char * V_8 ;
int V_21 ;
V_8 = F_6 ( L_10 ) ;
V_21 = F_14 ( V_8 , V_24 ) ;
if ( V_21 < 0 )
F_1 ( L_11 , V_8 ) ;
V_6 = F_16 ( V_21 ) ;
F_8 ( L_12 , 12 ) ;
F_8 ( & V_6 , 8 ) ;
V_26 = F_11 ( V_21 ) ;
F_15 ( V_21 ) ;
if ( V_6 != V_26 )
F_1 ( L_13 ,
V_8 , V_6 , V_26 ) ;
F_7 ( V_8 ) ;
V_8 = F_6 ( L_14 ) ;
V_21 = F_14 ( V_8 , V_24 ) ;
if ( V_21 < 0 )
F_1 ( L_11 , V_8 ) ;
V_6 = F_16 ( V_21 ) ;
F_8 ( L_15 , 13 ) ;
F_8 ( & V_6 , 8 ) ;
V_26 = F_11 ( V_21 ) ;
if ( V_6 != V_26 )
F_1 ( L_16 , V_8 ) ;
F_7 ( V_8 ) ;
F_15 ( V_21 ) ;
}
static bool F_20 ( char * V_27 , struct V_28 * V_29 )
{
while ( V_29 ) {
if ( ! strcmp ( V_27 , V_29 -> V_12 ) )
return true ;
V_29 = V_29 -> V_30 ;
}
return false ;
}
static void F_21 ( const char * V_27 , struct V_28 * V_29 )
{
unsigned long long V_6 , V_26 ;
struct V_31 * V_32 ;
struct V_33 V_34 ;
char * V_35 ;
T_4 * V_36 ;
int V_37 = 0 ;
int V_3 ;
V_36 = F_22 ( V_27 ) ;
if ( ! V_36 )
F_1 ( L_17 , V_27 ) ;
while ( ( V_32 = F_23 ( V_36 ) ) ) {
if ( V_32 -> V_38 != V_39 ||
strcmp ( V_32 -> V_40 , L_18 ) == 0 ||
strcmp ( V_32 -> V_40 , L_19 ) == 0 ||
! F_20 ( V_32 -> V_40 , V_29 ) )
continue;
V_35 = F_2 ( strlen ( V_27 ) + strlen ( V_32 -> V_40 ) + 10 ) ;
sprintf ( V_35 , L_20 , V_27 , V_32 -> V_40 ) ;
V_3 = V_33 ( V_35 , & V_34 ) ;
free ( V_35 ) ;
if ( V_3 < 0 )
continue;
V_37 ++ ;
}
F_8 ( & V_37 , 4 ) ;
F_24 ( V_36 ) ;
while ( ( V_32 = F_23 ( V_36 ) ) ) {
if ( V_32 -> V_38 != V_39 ||
strcmp ( V_32 -> V_40 , L_18 ) == 0 ||
strcmp ( V_32 -> V_40 , L_19 ) == 0 ||
! F_20 ( V_32 -> V_40 , V_29 ) )
continue;
V_35 = F_2 ( strlen ( V_27 ) + strlen ( V_32 -> V_40 ) + 10 ) ;
sprintf ( V_35 , L_20 , V_27 , V_32 -> V_40 ) ;
V_3 = V_33 ( V_35 , & V_34 ) ;
if ( V_3 >= 0 ) {
V_6 = F_18 ( V_35 ) ;
F_8 ( & V_6 , 8 ) ;
V_26 = F_13 ( V_35 ) ;
if ( V_6 != V_26 )
F_1 ( L_21 , V_35 ) ;
}
free ( V_35 ) ;
}
F_25 ( V_36 ) ;
}
static void F_26 ( struct V_28 * V_29 )
{
char * V_8 ;
V_8 = F_6 ( L_22 ) ;
F_21 ( V_8 , V_29 ) ;
F_7 ( V_8 ) ;
}
static bool F_27 ( char * V_27 , struct V_28 * V_29 )
{
while ( V_29 ) {
if ( ! strcmp ( V_27 , V_29 -> system ) )
return true ;
V_29 = V_29 -> V_30 ;
}
return false ;
}
static void F_28 ( struct V_28 * V_29 )
{
struct V_31 * V_32 ;
struct V_33 V_34 ;
char * V_8 ;
char * V_27 ;
T_4 * V_36 ;
int V_37 = 0 ;
int V_3 ;
V_8 = F_6 ( L_23 ) ;
V_36 = F_22 ( V_8 ) ;
if ( ! V_36 )
F_1 ( L_17 , V_8 ) ;
while ( ( V_32 = F_23 ( V_36 ) ) ) {
if ( V_32 -> V_38 != V_39 ||
strcmp ( V_32 -> V_40 , L_18 ) == 0 ||
strcmp ( V_32 -> V_40 , L_19 ) == 0 ||
strcmp ( V_32 -> V_40 , L_24 ) == 0 ||
! F_27 ( V_32 -> V_40 , V_29 ) )
continue;
V_37 ++ ;
}
F_8 ( & V_37 , 4 ) ;
F_24 ( V_36 ) ;
while ( ( V_32 = F_23 ( V_36 ) ) ) {
if ( V_32 -> V_38 != V_39 ||
strcmp ( V_32 -> V_40 , L_18 ) == 0 ||
strcmp ( V_32 -> V_40 , L_19 ) == 0 ||
strcmp ( V_32 -> V_40 , L_24 ) == 0 ||
! F_27 ( V_32 -> V_40 , V_29 ) )
continue;
V_27 = F_2 ( strlen ( V_8 ) + strlen ( V_32 -> V_40 ) + 2 ) ;
sprintf ( V_27 , L_7 , V_8 , V_32 -> V_40 ) ;
V_3 = V_33 ( V_27 , & V_34 ) ;
if ( V_3 >= 0 ) {
F_8 ( V_32 -> V_40 , strlen ( V_32 -> V_40 ) + 1 ) ;
F_21 ( V_27 , V_29 ) ;
}
free ( V_27 ) ;
}
F_25 ( V_36 ) ;
F_7 ( V_8 ) ;
}
static void F_29 ( void )
{
unsigned int V_6 , V_26 ;
const char * V_8 = L_25 ;
struct V_33 V_34 ;
int V_3 ;
V_3 = V_33 ( V_8 , & V_34 ) ;
if ( V_3 < 0 ) {
V_6 = 0 ;
F_8 ( & V_6 , 4 ) ;
return;
}
V_6 = F_18 ( V_8 ) ;
F_8 ( & V_6 , 4 ) ;
V_26 = F_13 ( V_8 ) ;
if ( V_6 != V_26 )
F_1 ( L_21 , V_8 ) ;
}
static void F_30 ( void )
{
unsigned int V_6 , V_26 ;
char * V_8 ;
struct V_33 V_34 ;
int V_3 ;
V_8 = F_6 ( L_26 ) ;
V_3 = V_33 ( V_8 , & V_34 ) ;
if ( V_3 < 0 ) {
V_6 = 0 ;
F_8 ( & V_6 , 4 ) ;
goto V_41;
}
V_6 = F_18 ( V_8 ) ;
F_8 ( & V_6 , 4 ) ;
V_26 = F_13 ( V_8 ) ;
if ( V_6 != V_26 )
F_1 ( L_21 , V_8 ) ;
V_41:
F_7 ( V_8 ) ;
}
static struct V_28 *
F_31 ( struct V_42 * V_43 )
{
struct V_28 V_8 , * V_44 = & V_8 ;
struct V_45 * V_46 ;
int V_47 = 0 ;
F_32 (pos, pattrs, node) {
if ( V_46 -> V_48 . type != V_49 )
continue;
++ V_47 ;
V_44 -> V_30 = F_33 ( V_46 -> V_48 . V_50 ) ;
if ( ! V_44 -> V_30 )
F_1 ( L_27 , L_28 ) ;
V_44 = V_44 -> V_30 ;
}
return V_47 > 0 ? V_8 . V_30 : NULL ;
}
bool F_34 ( struct V_42 * V_43 )
{
struct V_45 * V_46 ;
F_32 (pos, pattrs, node)
if ( V_46 -> V_48 . type == V_49 )
return true ;
return false ;
}
int F_35 ( int V_21 , struct V_42 * V_43 )
{
char V_14 [ V_22 ] ;
struct V_28 * V_29 = F_31 ( V_43 ) ;
if ( V_29 == NULL )
return - 1 ;
V_17 = V_21 ;
V_14 [ 0 ] = 23 ;
V_14 [ 1 ] = 8 ;
V_14 [ 2 ] = 68 ;
memcpy ( V_14 + 3 , L_29 , 7 ) ;
F_8 ( V_14 , 10 ) ;
F_8 ( V_51 , strlen ( V_51 ) + 1 ) ;
if ( F_10 () )
V_14 [ 0 ] = 1 ;
else
V_14 [ 0 ] = 0 ;
F_8 ( V_14 , 1 ) ;
V_14 [ 0 ] = sizeof( long ) ;
F_8 ( V_14 , 1 ) ;
V_52 = F_36 ( V_53 ) ;
F_8 ( & V_52 , 4 ) ;
F_19 () ;
F_26 ( V_29 ) ;
F_28 ( V_29 ) ;
F_29 () ;
F_30 () ;
return 0 ;
}
T_2 F_37 ( int V_21 , struct V_42 * V_43 )
{
T_2 V_6 ;
int V_54 = 0 ;
V_16 = 1 ;
V_54 = F_35 ( V_21 , V_43 ) ;
V_6 = V_16 - 1 ;
V_16 = 0 ;
if ( V_54 < 0 )
return V_54 ;
return V_6 ;
}
