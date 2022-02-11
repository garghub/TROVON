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
static void F_11 ( const char * V_13 , T_3 V_21 )
{
unsigned long long V_6 = 0 ;
char V_14 [ V_22 ] , * V_23 ;
T_4 V_24 = F_12 ( V_17 , 0 , V_25 ) ;
int V_26 , V_27 ;
V_27 = F_13 ( V_13 , V_28 ) ;
if ( V_27 < 0 )
F_1 ( L_9 , V_13 ) ;
F_8 ( & V_6 , V_21 ) ;
do {
V_26 = F_14 ( V_27 , V_14 , V_22 ) ;
if ( V_26 > 0 ) {
V_6 += V_26 ;
F_8 ( V_14 , V_26 ) ;
}
} while ( V_26 > 0 );
F_15 ( V_27 ) ;
V_23 = ( char * ) & V_6 ;
if ( F_10 () )
V_23 += sizeof( V_29 ) - V_21 ;
if ( F_16 ( V_17 , V_23 , V_21 , V_24 ) < 0 )
F_1 ( L_10 , V_18 ) ;
}
static void F_17 ( void )
{
char * V_8 ;
struct V_30 V_31 ;
V_8 = F_6 ( L_11 ) ;
if ( V_30 ( V_8 , & V_31 ) < 0 )
F_1 ( L_12 , V_8 ) ;
F_8 ( L_13 , 12 ) ;
F_11 ( V_8 , 8 ) ;
F_7 ( V_8 ) ;
V_8 = F_6 ( L_14 ) ;
if ( V_30 ( V_8 , & V_31 ) < 0 )
F_1 ( L_12 , V_8 ) ;
F_8 ( L_15 , 13 ) ;
F_11 ( V_8 , 8 ) ;
F_7 ( V_8 ) ;
}
static bool F_18 ( char * V_32 , struct V_33 * V_34 )
{
while ( V_34 ) {
if ( ! strcmp ( V_32 , V_34 -> V_12 ) )
return true ;
V_34 = V_34 -> V_35 ;
}
return false ;
}
static void F_19 ( const char * V_32 , struct V_33 * V_34 )
{
struct V_36 * V_37 ;
struct V_30 V_31 ;
char * V_38 ;
T_5 * V_39 ;
int V_40 = 0 ;
int V_3 ;
V_39 = F_20 ( V_32 ) ;
if ( ! V_39 )
F_1 ( L_16 , V_32 ) ;
while ( ( V_37 = F_21 ( V_39 ) ) ) {
if ( V_37 -> V_41 != V_42 ||
strcmp ( V_37 -> V_43 , L_17 ) == 0 ||
strcmp ( V_37 -> V_43 , L_18 ) == 0 ||
! F_18 ( V_37 -> V_43 , V_34 ) )
continue;
V_38 = F_2 ( strlen ( V_32 ) + strlen ( V_37 -> V_43 ) + 10 ) ;
sprintf ( V_38 , L_19 , V_32 , V_37 -> V_43 ) ;
V_3 = V_30 ( V_38 , & V_31 ) ;
free ( V_38 ) ;
if ( V_3 < 0 )
continue;
V_40 ++ ;
}
F_8 ( & V_40 , 4 ) ;
F_22 ( V_39 ) ;
while ( ( V_37 = F_21 ( V_39 ) ) ) {
if ( V_37 -> V_41 != V_42 ||
strcmp ( V_37 -> V_43 , L_17 ) == 0 ||
strcmp ( V_37 -> V_43 , L_18 ) == 0 ||
! F_18 ( V_37 -> V_43 , V_34 ) )
continue;
V_38 = F_2 ( strlen ( V_32 ) + strlen ( V_37 -> V_43 ) + 10 ) ;
sprintf ( V_38 , L_19 , V_32 , V_37 -> V_43 ) ;
V_3 = V_30 ( V_38 , & V_31 ) ;
if ( V_3 >= 0 )
F_11 ( V_38 , 8 ) ;
free ( V_38 ) ;
}
F_23 ( V_39 ) ;
}
static void F_24 ( struct V_33 * V_34 )
{
char * V_8 ;
V_8 = F_6 ( L_20 ) ;
F_19 ( V_8 , V_34 ) ;
F_7 ( V_8 ) ;
}
static bool F_25 ( char * V_32 , struct V_33 * V_34 )
{
while ( V_34 ) {
if ( ! strcmp ( V_32 , V_34 -> system ) )
return true ;
V_34 = V_34 -> V_35 ;
}
return false ;
}
static void F_26 ( struct V_33 * V_34 )
{
struct V_36 * V_37 ;
struct V_30 V_31 ;
char * V_8 ;
char * V_32 ;
T_5 * V_39 ;
int V_40 = 0 ;
int V_3 ;
V_8 = F_6 ( L_21 ) ;
V_39 = F_20 ( V_8 ) ;
if ( ! V_39 )
F_1 ( L_16 , V_8 ) ;
while ( ( V_37 = F_21 ( V_39 ) ) ) {
if ( V_37 -> V_41 != V_42 ||
strcmp ( V_37 -> V_43 , L_17 ) == 0 ||
strcmp ( V_37 -> V_43 , L_18 ) == 0 ||
strcmp ( V_37 -> V_43 , L_22 ) == 0 ||
! F_25 ( V_37 -> V_43 , V_34 ) )
continue;
V_40 ++ ;
}
F_8 ( & V_40 , 4 ) ;
F_22 ( V_39 ) ;
while ( ( V_37 = F_21 ( V_39 ) ) ) {
if ( V_37 -> V_41 != V_42 ||
strcmp ( V_37 -> V_43 , L_17 ) == 0 ||
strcmp ( V_37 -> V_43 , L_18 ) == 0 ||
strcmp ( V_37 -> V_43 , L_22 ) == 0 ||
! F_25 ( V_37 -> V_43 , V_34 ) )
continue;
V_32 = F_2 ( strlen ( V_8 ) + strlen ( V_37 -> V_43 ) + 2 ) ;
sprintf ( V_32 , L_7 , V_8 , V_37 -> V_43 ) ;
V_3 = V_30 ( V_32 , & V_31 ) ;
if ( V_3 >= 0 ) {
F_8 ( V_37 -> V_43 , strlen ( V_37 -> V_43 ) + 1 ) ;
F_19 ( V_32 , V_34 ) ;
}
free ( V_32 ) ;
}
F_23 ( V_39 ) ;
F_7 ( V_8 ) ;
}
static void F_27 ( void )
{
unsigned int V_6 ;
const char * V_8 = L_23 ;
struct V_30 V_31 ;
int V_3 ;
V_3 = V_30 ( V_8 , & V_31 ) ;
if ( V_3 < 0 ) {
V_6 = 0 ;
F_8 ( & V_6 , 4 ) ;
return;
}
F_11 ( V_8 , 4 ) ;
}
static void F_28 ( void )
{
unsigned int V_6 ;
char * V_8 ;
struct V_30 V_31 ;
int V_3 ;
V_8 = F_6 ( L_24 ) ;
V_3 = V_30 ( V_8 , & V_31 ) ;
if ( V_3 < 0 ) {
V_6 = 0 ;
F_8 ( & V_6 , 4 ) ;
goto V_44;
}
F_11 ( V_8 , 4 ) ;
V_44:
F_7 ( V_8 ) ;
}
static struct V_33 *
F_29 ( struct V_45 * V_46 )
{
struct V_33 V_8 , * V_47 = & V_8 ;
struct V_48 * V_49 ;
int V_50 = 0 ;
F_30 (pos, pattrs, node) {
if ( V_49 -> V_51 . type != V_52 )
continue;
++ V_50 ;
V_47 -> V_35 = F_31 ( V_49 -> V_51 . V_53 ) ;
if ( ! V_47 -> V_35 )
F_1 ( L_25 , L_26 ) ;
V_47 = V_47 -> V_35 ;
}
return V_50 > 0 ? V_8 . V_35 : NULL ;
}
bool F_32 ( struct V_45 * V_46 )
{
struct V_48 * V_49 ;
F_30 (pos, pattrs, node)
if ( V_49 -> V_51 . type == V_52 )
return true ;
return false ;
}
int F_33 ( int V_27 , struct V_45 * V_46 )
{
char V_14 [ V_22 ] ;
struct V_33 * V_34 = F_29 ( V_46 ) ;
if ( V_34 == NULL )
return - 1 ;
V_17 = V_27 ;
V_14 [ 0 ] = 23 ;
V_14 [ 1 ] = 8 ;
V_14 [ 2 ] = 68 ;
memcpy ( V_14 + 3 , L_27 , 7 ) ;
F_8 ( V_14 , 10 ) ;
F_8 ( V_54 , strlen ( V_54 ) + 1 ) ;
if ( F_10 () )
V_14 [ 0 ] = 1 ;
else
V_14 [ 0 ] = 0 ;
F_8 ( V_14 , 1 ) ;
V_14 [ 0 ] = sizeof( long ) ;
F_8 ( V_14 , 1 ) ;
V_55 = F_34 ( V_56 ) ;
F_8 ( & V_55 , 4 ) ;
F_17 () ;
F_24 ( V_34 ) ;
F_26 ( V_34 ) ;
F_27 () ;
F_28 () ;
return 0 ;
}
T_2 F_35 ( int V_27 , struct V_45 * V_46 )
{
T_2 V_6 ;
int V_57 = 0 ;
V_16 = 1 ;
V_57 = F_33 ( V_27 , V_46 ) ;
V_6 = V_16 - 1 ;
V_16 = 0 ;
if ( V_57 < 0 )
return V_57 ;
return V_6 ;
}
