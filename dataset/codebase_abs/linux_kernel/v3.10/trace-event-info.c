static const char * F_1 ( void )
{
const char * V_1 = F_2 ( NULL ) ;
if ( ! V_1 )
F_3 ( L_1 ) ;
return V_1 ;
}
static const char * F_4 ( void )
{
static char * V_2 ;
static int V_3 ;
const char * V_4 ;
if ( V_3 )
return V_2 ;
V_4 = F_1 () ;
if ( ! V_4 )
return NULL ;
V_2 = malloc ( strlen ( V_4 ) + 9 ) ;
if ( ! V_2 )
return NULL ;
sprintf ( V_2 , L_2 , V_4 ) ;
V_3 = 1 ;
return V_2 ;
}
static char * F_5 ( const char * V_5 )
{
const char * V_2 ;
char * V_6 ;
V_2 = F_4 () ;
if ( ! V_2 )
return NULL ;
V_6 = malloc ( strlen ( V_2 ) + strlen ( V_5 ) + 2 ) ;
if ( ! V_6 )
return NULL ;
sprintf ( V_6 , L_3 , V_2 , V_5 ) ;
return V_6 ;
}
static void F_6 ( char * V_6 )
{
free ( V_6 ) ;
}
int F_7 ( void )
{
unsigned char V_7 [] = { 0x1 , 0x2 , 0x3 , 0x4 , 0x0 , 0x0 , 0x0 , 0x0 } ;
unsigned int * V_8 ;
V_8 = ( unsigned int * ) ( void * ) V_7 ;
return * V_8 == 0x01020304 ;
}
static int F_8 ( const char * V_6 , T_1 V_9 )
{
unsigned long long V_10 = 0 ;
char V_11 [ V_12 ] , * V_13 ;
T_2 V_14 = F_9 ( V_15 , 0 , V_16 ) ;
int V_17 , V_18 ;
int V_19 = - V_20 ;
V_18 = F_10 ( V_6 , V_21 ) ;
if ( V_18 < 0 ) {
F_3 ( L_4 , V_6 ) ;
return - V_22 ;
}
if ( V_9 ) {
if ( F_11 ( V_15 , & V_10 , V_9 ) != V_9 )
goto V_23;
}
do {
V_17 = F_12 ( V_18 , V_11 , V_12 ) ;
if ( V_17 > 0 ) {
V_10 += V_17 ;
if ( F_11 ( V_15 , V_11 , V_17 ) != V_17 )
goto V_23;
}
} while ( V_17 > 0 );
V_13 = ( char * ) & V_10 ;
if ( F_7 () )
V_13 += sizeof( V_24 ) - V_9 ;
if ( V_9 && F_13 ( V_15 , V_13 , V_9 , V_14 ) < 0 ) {
F_3 ( L_5 ) ;
goto V_23;
}
V_19 = 0 ;
V_23:
F_14 ( V_18 ) ;
return V_19 ;
}
static int F_15 ( void )
{
char * V_1 ;
struct V_25 V_26 ;
int V_19 = - V_20 ;
V_1 = F_5 ( L_6 ) ;
if ( ! V_1 ) {
F_3 ( L_7 ) ;
return - V_27 ;
}
if ( V_25 ( V_1 , & V_26 ) < 0 ) {
F_3 ( L_8 , V_1 ) ;
goto V_23;
}
if ( F_11 ( V_15 , L_9 , 12 ) != 12 ) {
F_3 ( L_10 ) ;
goto V_23;
}
if ( F_8 ( V_1 , 8 ) < 0 ) {
F_3 ( L_11 ) ;
goto V_23;
}
F_6 ( V_1 ) ;
V_1 = F_5 ( L_12 ) ;
if ( ! V_1 ) {
F_3 ( L_13 ) ;
V_19 = - V_27 ;
goto V_23;
}
if ( V_25 ( V_1 , & V_26 ) < 0 ) {
F_3 ( L_8 , V_1 ) ;
goto V_23;
}
if ( F_11 ( V_15 , L_14 , 13 ) != 13 ) {
F_3 ( L_15 ) ;
goto V_23;
}
if ( F_8 ( V_1 , 8 ) < 0 ) {
F_3 ( L_16 ) ;
goto V_23;
}
V_19 = 0 ;
V_23:
F_6 ( V_1 ) ;
return V_19 ;
}
static bool F_16 ( char * V_28 , struct V_29 * V_30 )
{
while ( V_30 ) {
if ( ! strcmp ( V_28 , V_30 -> V_5 ) )
return true ;
V_30 = V_30 -> V_31 ;
}
return false ;
}
static int F_17 ( const char * V_28 , struct V_29 * V_30 )
{
struct V_32 * V_33 ;
struct V_25 V_26 ;
char * V_34 ;
T_3 * V_35 ;
int V_36 = 0 ;
int V_37 ;
int V_19 ;
V_35 = F_18 ( V_28 ) ;
if ( ! V_35 ) {
F_3 ( L_17 , V_28 ) ;
return - V_22 ;
}
while ( ( V_33 = F_19 ( V_35 ) ) ) {
if ( V_33 -> V_38 != V_39 ||
strcmp ( V_33 -> V_40 , L_18 ) == 0 ||
strcmp ( V_33 -> V_40 , L_19 ) == 0 ||
! F_16 ( V_33 -> V_40 , V_30 ) )
continue;
V_34 = malloc ( strlen ( V_28 ) + strlen ( V_33 -> V_40 ) + 10 ) ;
if ( ! V_34 ) {
V_19 = - V_27 ;
goto V_23;
}
sprintf ( V_34 , L_20 , V_28 , V_33 -> V_40 ) ;
V_37 = V_25 ( V_34 , & V_26 ) ;
free ( V_34 ) ;
if ( V_37 < 0 )
continue;
V_36 ++ ;
}
if ( F_11 ( V_15 , & V_36 , 4 ) != 4 ) {
V_19 = - V_20 ;
F_3 ( L_21 ) ;
goto V_23;
}
F_20 ( V_35 ) ;
while ( ( V_33 = F_19 ( V_35 ) ) ) {
if ( V_33 -> V_38 != V_39 ||
strcmp ( V_33 -> V_40 , L_18 ) == 0 ||
strcmp ( V_33 -> V_40 , L_19 ) == 0 ||
! F_16 ( V_33 -> V_40 , V_30 ) )
continue;
V_34 = malloc ( strlen ( V_28 ) + strlen ( V_33 -> V_40 ) + 10 ) ;
if ( ! V_34 ) {
V_19 = - V_27 ;
goto V_23;
}
sprintf ( V_34 , L_20 , V_28 , V_33 -> V_40 ) ;
V_37 = V_25 ( V_34 , & V_26 ) ;
if ( V_37 >= 0 ) {
V_19 = F_8 ( V_34 , 8 ) ;
if ( V_19 ) {
free ( V_34 ) ;
goto V_23;
}
}
free ( V_34 ) ;
}
V_19 = 0 ;
V_23:
F_21 ( V_35 ) ;
return V_19 ;
}
static int F_22 ( struct V_29 * V_30 )
{
char * V_1 ;
int V_37 ;
V_1 = F_5 ( L_22 ) ;
if ( ! V_1 ) {
F_3 ( L_23 ) ;
return - V_27 ;
}
V_37 = F_17 ( V_1 , V_30 ) ;
F_6 ( V_1 ) ;
return V_37 ;
}
static bool F_23 ( char * V_28 , struct V_29 * V_30 )
{
while ( V_30 ) {
if ( ! strcmp ( V_28 , V_30 -> system ) )
return true ;
V_30 = V_30 -> V_31 ;
}
return false ;
}
static int F_24 ( struct V_29 * V_30 )
{
struct V_32 * V_33 ;
struct V_25 V_26 ;
char * V_1 ;
char * V_28 ;
T_3 * V_35 ;
int V_36 = 0 ;
int V_37 ;
int V_19 ;
V_1 = F_5 ( L_24 ) ;
if ( ! V_1 ) {
F_3 ( L_25 ) ;
return - V_27 ;
}
V_35 = F_18 ( V_1 ) ;
if ( ! V_35 ) {
V_19 = - V_22 ;
F_3 ( L_17 , V_1 ) ;
goto V_23;
}
while ( ( V_33 = F_19 ( V_35 ) ) ) {
if ( V_33 -> V_38 != V_39 ||
strcmp ( V_33 -> V_40 , L_18 ) == 0 ||
strcmp ( V_33 -> V_40 , L_19 ) == 0 ||
strcmp ( V_33 -> V_40 , L_26 ) == 0 ||
! F_23 ( V_33 -> V_40 , V_30 ) )
continue;
V_36 ++ ;
}
if ( F_11 ( V_15 , & V_36 , 4 ) != 4 ) {
V_19 = - V_20 ;
F_3 ( L_21 ) ;
goto V_23;
}
F_20 ( V_35 ) ;
while ( ( V_33 = F_19 ( V_35 ) ) ) {
if ( V_33 -> V_38 != V_39 ||
strcmp ( V_33 -> V_40 , L_18 ) == 0 ||
strcmp ( V_33 -> V_40 , L_19 ) == 0 ||
strcmp ( V_33 -> V_40 , L_26 ) == 0 ||
! F_23 ( V_33 -> V_40 , V_30 ) )
continue;
V_28 = malloc ( strlen ( V_1 ) + strlen ( V_33 -> V_40 ) + 2 ) ;
if ( ! V_28 ) {
V_19 = - V_27 ;
goto V_23;
}
sprintf ( V_28 , L_3 , V_1 , V_33 -> V_40 ) ;
V_37 = V_25 ( V_28 , & V_26 ) ;
if ( V_37 >= 0 ) {
T_1 V_10 = strlen ( V_33 -> V_40 ) + 1 ;
if ( F_11 ( V_15 , V_33 -> V_40 , V_10 ) != V_10 ||
F_17 ( V_28 , V_30 ) < 0 ) {
V_19 = - V_20 ;
free ( V_28 ) ;
goto V_23;
}
}
free ( V_28 ) ;
}
V_19 = 0 ;
V_23:
F_21 ( V_35 ) ;
F_6 ( V_1 ) ;
return V_19 ;
}
static int F_25 ( void )
{
unsigned int V_10 ;
const char * V_1 = L_27 ;
struct V_25 V_26 ;
int V_37 , V_19 = 0 ;
V_37 = V_25 ( V_1 , & V_26 ) ;
if ( V_37 < 0 ) {
V_10 = 0 ;
if ( F_11 ( V_15 , & V_10 , 4 ) != 4 )
V_19 = - V_20 ;
return V_19 ;
}
return F_8 ( V_1 , 4 ) ;
}
static int F_26 ( void )
{
unsigned int V_10 ;
char * V_1 ;
struct V_25 V_26 ;
int V_37 , V_19 = 0 ;
V_1 = F_5 ( L_28 ) ;
if ( ! V_1 ) {
F_3 ( L_29 ) ;
return - V_27 ;
}
V_37 = V_25 ( V_1 , & V_26 ) ;
if ( V_37 < 0 ) {
V_10 = 0 ;
if ( F_11 ( V_15 , & V_10 , 4 ) != 4 )
V_19 = - V_20 ;
goto V_23;
}
V_19 = F_8 ( V_1 , 4 ) ;
V_23:
F_6 ( V_1 ) ;
return V_19 ;
}
static void
F_27 ( struct V_29 * V_30 )
{
while ( V_30 ) {
struct V_29 * V_41 = V_30 ;
V_30 = V_30 -> V_31 ;
free ( V_41 -> V_5 ) ;
free ( V_41 -> system ) ;
free ( V_41 ) ;
}
}
static struct V_29 *
F_28 ( struct V_42 * V_43 )
{
struct V_29 V_1 , * V_44 = & V_1 ;
struct V_45 * V_46 ;
int V_47 = 0 ;
F_29 (pos, pattrs, node) {
if ( V_46 -> V_48 . type != V_49 )
continue;
++ V_47 ;
V_44 -> V_31 = F_30 ( V_46 -> V_48 . V_50 ) ;
if ( ! V_44 -> V_31 ) {
F_3 ( L_30 ) ;
F_27 ( & V_1 ) ;
return NULL ;
}
V_44 = V_44 -> V_31 ;
}
return V_47 > 0 ? V_1 . V_31 : NULL ;
}
bool F_31 ( struct V_42 * V_43 )
{
struct V_45 * V_46 ;
F_29 (pos, pattrs, node)
if ( V_46 -> V_48 . type == V_49 )
return true ;
return false ;
}
static int F_32 ( void )
{
char V_11 [ 20 ] ;
T_1 V_10 ;
V_11 [ 0 ] = 23 ;
V_11 [ 1 ] = 8 ;
V_11 [ 2 ] = 68 ;
memcpy ( V_11 + 3 , L_31 , 7 ) ;
if ( F_11 ( V_15 , V_11 , 10 ) != 10 )
return - 1 ;
V_10 = strlen ( V_51 ) + 1 ;
if ( F_11 ( V_15 , V_51 , V_10 ) != V_10 )
return - 1 ;
if ( F_7 () )
V_11 [ 0 ] = 1 ;
else
V_11 [ 0 ] = 0 ;
F_33 ( V_11 [ 0 ] , V_11 [ 0 ] ) ;
if ( F_11 ( V_15 , V_11 , 1 ) != 1 )
return - 1 ;
V_11 [ 0 ] = sizeof( long ) ;
if ( F_11 ( V_15 , V_11 , 1 ) != 1 )
return - 1 ;
if ( F_11 ( V_15 , & V_52 , 4 ) != 4 )
return - 1 ;
return 0 ;
}
struct V_53 * F_34 ( struct V_42 * V_43 ,
int V_18 , bool V_54 )
{
struct V_29 * V_30 ;
struct V_53 * V_55 ;
int V_19 ;
V_15 = V_18 ;
V_30 = F_28 ( V_43 ) ;
if ( ! V_30 )
return NULL ;
V_55 = malloc ( sizeof( * V_55 ) ) ;
if ( ! V_55 )
return NULL ;
V_55 -> V_54 = V_54 ;
V_55 -> V_10 = 0 ;
if ( V_54 ) {
int V_56 ;
snprintf ( V_55 -> V_57 , sizeof( V_55 -> V_57 ) ,
L_32 ) ;
if ( ! F_35 ( V_55 -> V_57 ) ) {
F_3 ( L_33 ) ;
return NULL ;
}
V_56 = F_10 ( V_55 -> V_57 , V_58 ) ;
if ( V_56 < 0 ) {
F_3 ( L_4 , V_55 -> V_57 ) ;
return NULL ;
}
V_15 = V_56 ;
}
V_19 = F_32 () ;
if ( V_19 )
goto V_23;
V_19 = F_15 () ;
if ( V_19 )
goto V_23;
V_19 = F_22 ( V_30 ) ;
if ( V_19 )
goto V_23;
V_19 = F_24 ( V_30 ) ;
if ( V_19 )
goto V_23;
V_19 = F_25 () ;
if ( V_19 )
goto V_23;
V_19 = F_26 () ;
V_23:
if ( V_54 ) {
V_55 -> V_10 = F_9 ( V_15 , 0 , V_16 ) ;
F_14 ( V_15 ) ;
V_15 = V_18 ;
}
if ( V_19 ) {
free ( V_55 ) ;
V_55 = NULL ;
}
F_27 ( V_30 ) ;
return V_55 ;
}
int F_36 ( struct V_53 * V_55 )
{
int V_19 = 0 ;
if ( V_55 -> V_54 ) {
V_19 = F_8 ( V_55 -> V_57 , 0 ) ;
F_37 ( V_55 -> V_57 ) ;
}
free ( V_55 ) ;
return V_19 ;
}
int F_38 ( int V_18 , struct V_42 * V_43 )
{
int V_19 ;
struct V_53 * V_55 ;
V_55 = F_34 ( V_43 , V_18 , false ) ;
if ( ! V_55 )
return - V_27 ;
V_19 = F_36 ( V_55 ) ;
return V_19 ;
}
