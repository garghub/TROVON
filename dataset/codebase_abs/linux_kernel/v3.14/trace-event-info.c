int F_1 ( void )
{
unsigned char V_1 [] = { 0x1 , 0x2 , 0x3 , 0x4 , 0x0 , 0x0 , 0x0 , 0x0 } ;
unsigned int * V_2 ;
V_2 = ( unsigned int * ) ( void * ) V_1 ;
return * V_2 == 0x01020304 ;
}
static int F_2 ( const char * V_3 , T_1 V_4 )
{
unsigned long long V_5 = 0 ;
char V_6 [ V_7 ] , * V_8 ;
T_2 V_9 = F_3 ( V_10 , 0 , V_11 ) ;
int V_12 , V_13 ;
int V_14 = - V_15 ;
V_13 = F_4 ( V_3 , V_16 ) ;
if ( V_13 < 0 ) {
F_5 ( L_1 , V_3 ) ;
return - V_17 ;
}
if ( V_4 ) {
if ( F_6 ( V_10 , & V_5 , V_4 ) != V_4 )
goto V_18;
}
do {
V_12 = F_7 ( V_13 , V_6 , V_7 ) ;
if ( V_12 > 0 ) {
V_5 += V_12 ;
if ( F_6 ( V_10 , V_6 , V_12 ) != V_12 )
goto V_18;
}
} while ( V_12 > 0 );
V_8 = ( char * ) & V_5 ;
if ( F_1 () )
V_8 += sizeof( V_19 ) - V_4 ;
if ( V_4 && F_8 ( V_10 , V_8 , V_4 , V_9 ) < 0 ) {
F_5 ( L_2 ) ;
goto V_18;
}
V_14 = 0 ;
V_18:
F_9 ( V_13 ) ;
return V_14 ;
}
static int F_10 ( void )
{
char * V_20 ;
struct V_21 V_22 ;
int V_14 = - V_15 ;
V_20 = F_11 ( L_3 ) ;
if ( ! V_20 ) {
F_5 ( L_4 ) ;
return - V_23 ;
}
if ( V_21 ( V_20 , & V_22 ) < 0 ) {
F_5 ( L_5 , V_20 ) ;
goto V_18;
}
if ( F_6 ( V_10 , L_6 , 12 ) != 12 ) {
F_5 ( L_7 ) ;
goto V_18;
}
if ( F_2 ( V_20 , 8 ) < 0 ) {
F_5 ( L_8 ) ;
goto V_18;
}
F_12 ( V_20 ) ;
V_20 = F_11 ( L_9 ) ;
if ( ! V_20 ) {
F_5 ( L_10 ) ;
V_14 = - V_23 ;
goto V_18;
}
if ( V_21 ( V_20 , & V_22 ) < 0 ) {
F_5 ( L_5 , V_20 ) ;
goto V_18;
}
if ( F_6 ( V_10 , L_11 , 13 ) != 13 ) {
F_5 ( L_12 ) ;
goto V_18;
}
if ( F_2 ( V_20 , 8 ) < 0 ) {
F_5 ( L_13 ) ;
goto V_18;
}
V_14 = 0 ;
V_18:
F_12 ( V_20 ) ;
return V_14 ;
}
static bool F_13 ( char * V_24 , struct V_25 * V_26 )
{
while ( V_26 ) {
if ( ! strcmp ( V_24 , V_26 -> V_27 ) )
return true ;
V_26 = V_26 -> V_28 ;
}
return false ;
}
static int F_14 ( const char * V_24 , struct V_25 * V_26 )
{
struct V_29 * V_30 ;
struct V_21 V_22 ;
char * V_31 ;
T_3 * V_32 ;
int V_33 = 0 ;
int V_34 ;
int V_14 ;
V_32 = F_15 ( V_24 ) ;
if ( ! V_32 ) {
F_5 ( L_14 , V_24 ) ;
return - V_17 ;
}
while ( ( V_30 = F_16 ( V_32 ) ) ) {
if ( V_30 -> V_35 != V_36 ||
strcmp ( V_30 -> V_37 , L_15 ) == 0 ||
strcmp ( V_30 -> V_37 , L_16 ) == 0 ||
! F_13 ( V_30 -> V_37 , V_26 ) )
continue;
V_31 = malloc ( strlen ( V_24 ) + strlen ( V_30 -> V_37 ) + 10 ) ;
if ( ! V_31 ) {
V_14 = - V_23 ;
goto V_18;
}
sprintf ( V_31 , L_17 , V_24 , V_30 -> V_37 ) ;
V_34 = V_21 ( V_31 , & V_22 ) ;
free ( V_31 ) ;
if ( V_34 < 0 )
continue;
V_33 ++ ;
}
if ( F_6 ( V_10 , & V_33 , 4 ) != 4 ) {
V_14 = - V_15 ;
F_5 ( L_18 ) ;
goto V_18;
}
F_17 ( V_32 ) ;
while ( ( V_30 = F_16 ( V_32 ) ) ) {
if ( V_30 -> V_35 != V_36 ||
strcmp ( V_30 -> V_37 , L_15 ) == 0 ||
strcmp ( V_30 -> V_37 , L_16 ) == 0 ||
! F_13 ( V_30 -> V_37 , V_26 ) )
continue;
V_31 = malloc ( strlen ( V_24 ) + strlen ( V_30 -> V_37 ) + 10 ) ;
if ( ! V_31 ) {
V_14 = - V_23 ;
goto V_18;
}
sprintf ( V_31 , L_17 , V_24 , V_30 -> V_37 ) ;
V_34 = V_21 ( V_31 , & V_22 ) ;
if ( V_34 >= 0 ) {
V_14 = F_2 ( V_31 , 8 ) ;
if ( V_14 ) {
free ( V_31 ) ;
goto V_18;
}
}
free ( V_31 ) ;
}
V_14 = 0 ;
V_18:
F_18 ( V_32 ) ;
return V_14 ;
}
static int F_19 ( struct V_25 * V_26 )
{
char * V_20 ;
int V_34 ;
V_20 = F_11 ( L_19 ) ;
if ( ! V_20 ) {
F_5 ( L_20 ) ;
return - V_23 ;
}
V_34 = F_14 ( V_20 , V_26 ) ;
F_12 ( V_20 ) ;
return V_34 ;
}
static bool F_20 ( char * V_24 , struct V_25 * V_26 )
{
while ( V_26 ) {
if ( ! strcmp ( V_24 , V_26 -> system ) )
return true ;
V_26 = V_26 -> V_28 ;
}
return false ;
}
static int F_21 ( struct V_25 * V_26 )
{
struct V_29 * V_30 ;
struct V_21 V_22 ;
char * V_20 ;
char * V_24 ;
T_3 * V_32 ;
int V_33 = 0 ;
int V_34 ;
int V_14 ;
V_20 = F_11 ( L_21 ) ;
if ( ! V_20 ) {
F_5 ( L_22 ) ;
return - V_23 ;
}
V_32 = F_15 ( V_20 ) ;
if ( ! V_32 ) {
V_14 = - V_17 ;
F_5 ( L_14 , V_20 ) ;
goto V_18;
}
while ( ( V_30 = F_16 ( V_32 ) ) ) {
if ( V_30 -> V_35 != V_36 ||
strcmp ( V_30 -> V_37 , L_15 ) == 0 ||
strcmp ( V_30 -> V_37 , L_16 ) == 0 ||
strcmp ( V_30 -> V_37 , L_23 ) == 0 ||
! F_20 ( V_30 -> V_37 , V_26 ) )
continue;
V_33 ++ ;
}
if ( F_6 ( V_10 , & V_33 , 4 ) != 4 ) {
V_14 = - V_15 ;
F_5 ( L_18 ) ;
goto V_18;
}
F_17 ( V_32 ) ;
while ( ( V_30 = F_16 ( V_32 ) ) ) {
if ( V_30 -> V_35 != V_36 ||
strcmp ( V_30 -> V_37 , L_15 ) == 0 ||
strcmp ( V_30 -> V_37 , L_16 ) == 0 ||
strcmp ( V_30 -> V_37 , L_23 ) == 0 ||
! F_20 ( V_30 -> V_37 , V_26 ) )
continue;
V_24 = malloc ( strlen ( V_20 ) + strlen ( V_30 -> V_37 ) + 2 ) ;
if ( ! V_24 ) {
V_14 = - V_23 ;
goto V_18;
}
sprintf ( V_24 , L_24 , V_20 , V_30 -> V_37 ) ;
V_34 = V_21 ( V_24 , & V_22 ) ;
if ( V_34 >= 0 ) {
T_1 V_5 = strlen ( V_30 -> V_37 ) + 1 ;
if ( F_6 ( V_10 , V_30 -> V_37 , V_5 ) != V_5 ||
F_14 ( V_24 , V_26 ) < 0 ) {
V_14 = - V_15 ;
free ( V_24 ) ;
goto V_18;
}
}
free ( V_24 ) ;
}
V_14 = 0 ;
V_18:
F_18 ( V_32 ) ;
F_12 ( V_20 ) ;
return V_14 ;
}
static int F_22 ( void )
{
unsigned int V_5 ;
const char * V_20 = L_25 ;
struct V_21 V_22 ;
int V_34 , V_14 = 0 ;
V_34 = V_21 ( V_20 , & V_22 ) ;
if ( V_34 < 0 ) {
V_5 = 0 ;
if ( F_6 ( V_10 , & V_5 , 4 ) != 4 )
V_14 = - V_15 ;
return V_14 ;
}
return F_2 ( V_20 , 4 ) ;
}
static int F_23 ( void )
{
unsigned int V_5 ;
char * V_20 ;
struct V_21 V_22 ;
int V_34 , V_14 = 0 ;
V_20 = F_11 ( L_26 ) ;
if ( ! V_20 ) {
F_5 ( L_27 ) ;
return - V_23 ;
}
V_34 = V_21 ( V_20 , & V_22 ) ;
if ( V_34 < 0 ) {
V_5 = 0 ;
if ( F_6 ( V_10 , & V_5 , 4 ) != 4 )
V_14 = - V_15 ;
goto V_18;
}
V_14 = F_2 ( V_20 , 4 ) ;
V_18:
F_12 ( V_20 ) ;
return V_14 ;
}
static void
F_24 ( struct V_25 * V_26 )
{
while ( V_26 ) {
struct V_25 * V_38 = V_26 ;
V_26 = V_26 -> V_28 ;
F_25 ( & V_38 -> V_27 ) ;
F_25 ( & V_38 -> system ) ;
free ( V_38 ) ;
}
}
static struct V_25 *
F_26 ( struct V_39 * V_40 )
{
struct V_25 V_20 , * V_41 = & V_20 ;
struct V_42 * V_43 ;
int V_44 = 0 ;
F_27 (pos, pattrs, node) {
if ( V_43 -> V_45 . type != V_46 )
continue;
++ V_44 ;
if ( V_43 -> V_27 ) {
V_41 -> V_28 = F_28 ( V_43 -> V_27 ) ;
if ( V_41 -> V_28 )
goto V_28;
if ( strchr ( V_43 -> V_27 , ':' ) == NULL )
goto V_47;
goto error;
}
V_47:
V_41 -> V_28 = F_29 ( V_43 -> V_45 . V_48 ) ;
if ( ! V_41 -> V_28 ) {
error:
F_5 ( L_28 ) ;
F_24 ( & V_20 ) ;
return NULL ;
}
V_28:
V_41 = V_41 -> V_28 ;
}
return V_44 > 0 ? V_20 . V_28 : NULL ;
}
bool F_30 ( struct V_39 * V_40 )
{
struct V_42 * V_43 ;
F_27 (pos, pattrs, node)
if ( V_43 -> V_45 . type == V_46 )
return true ;
return false ;
}
static int F_31 ( void )
{
char V_6 [ 20 ] ;
T_1 V_5 ;
V_6 [ 0 ] = 23 ;
V_6 [ 1 ] = 8 ;
V_6 [ 2 ] = 68 ;
memcpy ( V_6 + 3 , L_29 , 7 ) ;
if ( F_6 ( V_10 , V_6 , 10 ) != 10 )
return - 1 ;
V_5 = strlen ( V_49 ) + 1 ;
if ( F_6 ( V_10 , V_49 , V_5 ) != V_5 )
return - 1 ;
if ( F_1 () )
V_6 [ 0 ] = 1 ;
else
V_6 [ 0 ] = 0 ;
if ( F_6 ( V_10 , V_6 , 1 ) != 1 )
return - 1 ;
V_6 [ 0 ] = sizeof( long ) ;
if ( F_6 ( V_10 , V_6 , 1 ) != 1 )
return - 1 ;
if ( F_6 ( V_10 , & V_50 , 4 ) != 4 )
return - 1 ;
return 0 ;
}
struct V_51 * F_32 ( struct V_39 * V_40 ,
int V_13 , bool V_52 )
{
struct V_25 * V_26 ;
struct V_51 * V_53 ;
int V_14 ;
V_10 = V_13 ;
V_26 = F_26 ( V_40 ) ;
if ( ! V_26 )
return NULL ;
V_53 = malloc ( sizeof( * V_53 ) ) ;
if ( ! V_53 )
return NULL ;
V_53 -> V_52 = V_52 ;
V_53 -> V_5 = 0 ;
if ( V_52 ) {
int V_54 ;
snprintf ( V_53 -> V_55 , sizeof( V_53 -> V_55 ) ,
L_30 ) ;
if ( ! F_33 ( V_53 -> V_55 ) ) {
F_5 ( L_31 ) ;
return NULL ;
}
V_54 = F_4 ( V_53 -> V_55 , V_56 ) ;
if ( V_54 < 0 ) {
F_5 ( L_1 , V_53 -> V_55 ) ;
return NULL ;
}
V_10 = V_54 ;
}
V_14 = F_31 () ;
if ( V_14 )
goto V_18;
V_14 = F_10 () ;
if ( V_14 )
goto V_18;
V_14 = F_19 ( V_26 ) ;
if ( V_14 )
goto V_18;
V_14 = F_21 ( V_26 ) ;
if ( V_14 )
goto V_18;
V_14 = F_22 () ;
if ( V_14 )
goto V_18;
V_14 = F_23 () ;
V_18:
if ( V_52 ) {
V_53 -> V_5 = F_3 ( V_10 , 0 , V_11 ) ;
F_9 ( V_10 ) ;
V_10 = V_13 ;
}
if ( V_14 )
F_25 ( & V_53 ) ;
F_24 ( V_26 ) ;
return V_53 ;
}
int F_34 ( struct V_51 * V_53 )
{
int V_14 = 0 ;
if ( V_53 -> V_52 ) {
V_14 = F_2 ( V_53 -> V_55 , 0 ) ;
F_35 ( V_53 -> V_55 ) ;
}
free ( V_53 ) ;
return V_14 ;
}
int F_36 ( int V_13 , struct V_39 * V_40 )
{
int V_14 ;
struct V_51 * V_53 ;
V_53 = F_32 ( V_40 , V_13 , false ) ;
if ( ! V_53 )
return - V_23 ;
V_14 = F_34 ( V_53 ) ;
return V_14 ;
}
