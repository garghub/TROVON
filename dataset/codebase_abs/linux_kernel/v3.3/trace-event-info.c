void * F_1 ( unsigned int V_1 )
{
void * V_2 ;
V_2 = malloc ( V_1 ) ;
if ( ! V_2 )
F_2 ( L_1 ) ;
return V_2 ;
}
static const char * F_3 ( void )
{
const char * V_3 = F_4 ( NULL ) ;
if ( ! V_3 )
F_2 ( L_2 ) ;
return V_3 ;
}
static const char * F_5 ( void )
{
static char * V_4 ;
static int V_5 ;
const char * V_6 ;
if ( V_5 )
return V_4 ;
V_6 = F_3 () ;
V_4 = F_1 ( strlen ( V_6 ) + 9 ) ;
sprintf ( V_4 , L_3 , V_6 ) ;
V_5 = 1 ;
return V_4 ;
}
static char * F_6 ( const char * V_7 )
{
const char * V_4 ;
char * V_8 ;
V_4 = F_5 () ;
if ( ! V_4 )
return NULL ;
V_8 = F_1 ( strlen ( V_4 ) + strlen ( V_7 ) + 2 ) ;
sprintf ( V_8 , L_4 , V_4 , V_7 ) ;
return V_8 ;
}
static void F_7 ( char * V_8 )
{
free ( V_8 ) ;
}
static T_1 F_8 ( const void * V_9 , T_2 V_10 )
{
int V_11 ;
if ( V_12 ) {
V_12 += V_10 ;
return V_10 ;
}
V_11 = F_9 ( V_13 , V_9 , V_10 ) ;
if ( V_11 < 0 )
F_2 ( L_5 , V_14 ) ;
return V_11 ;
}
int F_10 ( void )
{
unsigned char V_15 [] = { 0x1 , 0x2 , 0x3 , 0x4 , 0x0 , 0x0 , 0x0 , 0x0 } ;
unsigned int * V_16 ;
V_16 = ( unsigned int * ) ( void * ) V_15 ;
return * V_16 == 0x01020304 ;
}
static void F_11 ( const char * V_8 , T_2 V_17 )
{
unsigned long long V_1 = 0 ;
char V_9 [ V_18 ] , * V_19 ;
T_3 V_20 = F_12 ( V_13 , 0 , V_21 ) ;
int V_22 , V_23 ;
V_23 = F_13 ( V_8 , V_24 ) ;
if ( V_23 < 0 )
F_2 ( L_6 , V_8 ) ;
if ( V_17 )
F_8 ( & V_1 , V_17 ) ;
do {
V_22 = F_14 ( V_23 , V_9 , V_18 ) ;
if ( V_22 > 0 ) {
V_1 += V_22 ;
F_8 ( V_9 , V_22 ) ;
}
} while ( V_22 > 0 );
F_15 ( V_23 ) ;
V_19 = ( char * ) & V_1 ;
if ( F_10 () )
V_19 += sizeof( V_25 ) - V_17 ;
if ( V_17 && F_16 ( V_13 , V_19 , V_17 , V_20 ) < 0 )
F_2 ( L_7 , V_14 ) ;
}
static void F_17 ( void )
{
char * V_3 ;
struct V_26 V_27 ;
V_3 = F_6 ( L_8 ) ;
if ( V_26 ( V_3 , & V_27 ) < 0 )
F_2 ( L_9 , V_3 ) ;
F_8 ( L_10 , 12 ) ;
F_11 ( V_3 , 8 ) ;
F_7 ( V_3 ) ;
V_3 = F_6 ( L_11 ) ;
if ( V_26 ( V_3 , & V_27 ) < 0 )
F_2 ( L_9 , V_3 ) ;
F_8 ( L_12 , 13 ) ;
F_11 ( V_3 , 8 ) ;
F_7 ( V_3 ) ;
}
static bool F_18 ( char * V_28 , struct V_29 * V_30 )
{
while ( V_30 ) {
if ( ! strcmp ( V_28 , V_30 -> V_7 ) )
return true ;
V_30 = V_30 -> V_31 ;
}
return false ;
}
static void F_19 ( const char * V_28 , struct V_29 * V_30 )
{
struct V_32 * V_33 ;
struct V_26 V_27 ;
char * V_34 ;
T_4 * V_35 ;
int V_36 = 0 ;
int V_11 ;
V_35 = F_20 ( V_28 ) ;
if ( ! V_35 )
F_2 ( L_13 , V_28 ) ;
while ( ( V_33 = F_21 ( V_35 ) ) ) {
if ( V_33 -> V_37 != V_38 ||
strcmp ( V_33 -> V_39 , L_14 ) == 0 ||
strcmp ( V_33 -> V_39 , L_15 ) == 0 ||
! F_18 ( V_33 -> V_39 , V_30 ) )
continue;
V_34 = F_1 ( strlen ( V_28 ) + strlen ( V_33 -> V_39 ) + 10 ) ;
sprintf ( V_34 , L_16 , V_28 , V_33 -> V_39 ) ;
V_11 = V_26 ( V_34 , & V_27 ) ;
free ( V_34 ) ;
if ( V_11 < 0 )
continue;
V_36 ++ ;
}
F_8 ( & V_36 , 4 ) ;
F_22 ( V_35 ) ;
while ( ( V_33 = F_21 ( V_35 ) ) ) {
if ( V_33 -> V_37 != V_38 ||
strcmp ( V_33 -> V_39 , L_14 ) == 0 ||
strcmp ( V_33 -> V_39 , L_15 ) == 0 ||
! F_18 ( V_33 -> V_39 , V_30 ) )
continue;
V_34 = F_1 ( strlen ( V_28 ) + strlen ( V_33 -> V_39 ) + 10 ) ;
sprintf ( V_34 , L_16 , V_28 , V_33 -> V_39 ) ;
V_11 = V_26 ( V_34 , & V_27 ) ;
if ( V_11 >= 0 )
F_11 ( V_34 , 8 ) ;
free ( V_34 ) ;
}
F_23 ( V_35 ) ;
}
static void F_24 ( struct V_29 * V_30 )
{
char * V_3 ;
V_3 = F_6 ( L_17 ) ;
F_19 ( V_3 , V_30 ) ;
F_7 ( V_3 ) ;
}
static bool F_25 ( char * V_28 , struct V_29 * V_30 )
{
while ( V_30 ) {
if ( ! strcmp ( V_28 , V_30 -> system ) )
return true ;
V_30 = V_30 -> V_31 ;
}
return false ;
}
static void F_26 ( struct V_29 * V_30 )
{
struct V_32 * V_33 ;
struct V_26 V_27 ;
char * V_3 ;
char * V_28 ;
T_4 * V_35 ;
int V_36 = 0 ;
int V_11 ;
V_3 = F_6 ( L_18 ) ;
V_35 = F_20 ( V_3 ) ;
if ( ! V_35 )
F_2 ( L_13 , V_3 ) ;
while ( ( V_33 = F_21 ( V_35 ) ) ) {
if ( V_33 -> V_37 != V_38 ||
strcmp ( V_33 -> V_39 , L_14 ) == 0 ||
strcmp ( V_33 -> V_39 , L_15 ) == 0 ||
strcmp ( V_33 -> V_39 , L_19 ) == 0 ||
! F_25 ( V_33 -> V_39 , V_30 ) )
continue;
V_36 ++ ;
}
F_8 ( & V_36 , 4 ) ;
F_22 ( V_35 ) ;
while ( ( V_33 = F_21 ( V_35 ) ) ) {
if ( V_33 -> V_37 != V_38 ||
strcmp ( V_33 -> V_39 , L_14 ) == 0 ||
strcmp ( V_33 -> V_39 , L_15 ) == 0 ||
strcmp ( V_33 -> V_39 , L_19 ) == 0 ||
! F_25 ( V_33 -> V_39 , V_30 ) )
continue;
V_28 = F_1 ( strlen ( V_3 ) + strlen ( V_33 -> V_39 ) + 2 ) ;
sprintf ( V_28 , L_4 , V_3 , V_33 -> V_39 ) ;
V_11 = V_26 ( V_28 , & V_27 ) ;
if ( V_11 >= 0 ) {
F_8 ( V_33 -> V_39 , strlen ( V_33 -> V_39 ) + 1 ) ;
F_19 ( V_28 , V_30 ) ;
}
free ( V_28 ) ;
}
F_23 ( V_35 ) ;
F_7 ( V_3 ) ;
}
static void F_27 ( void )
{
unsigned int V_1 ;
const char * V_3 = L_20 ;
struct V_26 V_27 ;
int V_11 ;
V_11 = V_26 ( V_3 , & V_27 ) ;
if ( V_11 < 0 ) {
V_1 = 0 ;
F_8 ( & V_1 , 4 ) ;
return;
}
F_11 ( V_3 , 4 ) ;
}
static void F_28 ( void )
{
unsigned int V_1 ;
char * V_3 ;
struct V_26 V_27 ;
int V_11 ;
V_3 = F_6 ( L_21 ) ;
V_11 = V_26 ( V_3 , & V_27 ) ;
if ( V_11 < 0 ) {
V_1 = 0 ;
F_8 ( & V_1 , 4 ) ;
goto V_40;
}
F_11 ( V_3 , 4 ) ;
V_40:
F_7 ( V_3 ) ;
}
static struct V_29 *
F_29 ( struct V_41 * V_42 )
{
struct V_29 V_3 , * V_43 = & V_3 ;
struct V_44 * V_45 ;
int V_46 = 0 ;
F_30 (pos, pattrs, node) {
if ( V_45 -> V_47 . type != V_48 )
continue;
++ V_46 ;
V_43 -> V_31 = F_31 ( V_45 -> V_47 . V_49 ) ;
if ( ! V_43 -> V_31 )
F_2 ( L_22 , L_23 ) ;
V_43 = V_43 -> V_31 ;
}
return V_46 > 0 ? V_3 . V_31 : NULL ;
}
static void
F_32 ( struct V_29 * V_30 )
{
while ( V_30 ) {
struct V_29 * V_50 = V_30 ;
V_30 = V_30 -> V_31 ;
free ( V_50 -> V_7 ) ;
free ( V_50 -> system ) ;
free ( V_50 ) ;
}
}
bool F_33 ( struct V_41 * V_42 )
{
struct V_44 * V_45 ;
F_30 (pos, pattrs, node)
if ( V_45 -> V_47 . type == V_48 )
return true ;
return false ;
}
static void F_34 ( void )
{
char V_9 [ 20 ] ;
V_9 [ 0 ] = 23 ;
V_9 [ 1 ] = 8 ;
V_9 [ 2 ] = 68 ;
memcpy ( V_9 + 3 , L_24 , 7 ) ;
F_8 ( V_9 , 10 ) ;
F_8 ( V_51 , strlen ( V_51 ) + 1 ) ;
if ( F_10 () )
V_9 [ 0 ] = 1 ;
else
V_9 [ 0 ] = 0 ;
F_8 ( V_9 , 1 ) ;
V_9 [ 0 ] = sizeof( long ) ;
F_8 ( V_9 , 1 ) ;
V_52 = F_35 ( V_53 ) ;
F_8 ( & V_52 , 4 ) ;
}
struct V_54 * F_36 ( struct V_41 * V_42 ,
int V_23 , bool V_55 )
{
struct V_29 * V_30 ;
struct V_54 * V_56 ;
V_13 = V_23 ;
V_30 = F_29 ( V_42 ) ;
if ( ! V_30 )
return NULL ;
V_56 = F_1 ( sizeof( * V_56 ) ) ;
V_56 -> V_55 = V_55 ;
V_56 -> V_1 = 0 ;
if ( V_55 ) {
int V_57 ;
snprintf ( V_56 -> V_58 , sizeof( V_56 -> V_58 ) ,
L_25 ) ;
if ( ! F_37 ( V_56 -> V_58 ) )
F_2 ( L_26 ) ;
V_57 = F_13 ( V_56 -> V_58 , V_59 ) ;
if ( V_57 < 0 )
F_2 ( L_6 , V_56 -> V_58 ) ;
V_13 = V_57 ;
}
F_34 () ;
F_17 () ;
F_24 ( V_30 ) ;
F_26 ( V_30 ) ;
F_27 () ;
F_28 () ;
if ( V_55 ) {
V_56 -> V_1 = F_12 ( V_13 , 0 , V_21 ) ;
F_15 ( V_13 ) ;
V_13 = V_23 ;
}
F_32 ( V_30 ) ;
return V_56 ;
}
void F_38 ( struct V_54 * V_56 )
{
if ( V_56 -> V_55 ) {
F_11 ( V_56 -> V_58 , 0 ) ;
F_39 ( V_56 -> V_58 ) ;
}
free ( V_56 ) ;
}
int F_40 ( int V_23 , struct V_41 * V_42 )
{
struct V_54 * V_56 ;
V_56 = F_36 ( V_42 , V_23 , false ) ;
if ( ! V_56 )
return - V_60 ;
F_38 ( V_56 ) ;
return 0 ;
}
