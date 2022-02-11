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
static int F_14 ( struct V_25 * V_26 )
{
char * V_20 ;
int V_29 ;
V_20 = F_11 ( L_14 ) ;
if ( ! V_20 ) {
F_5 ( L_15 ) ;
return - V_23 ;
}
V_29 = F_15 ( V_20 , V_26 ) ;
F_12 ( V_20 ) ;
return V_29 ;
}
static bool F_16 ( char * V_24 , struct V_25 * V_26 )
{
while ( V_26 ) {
if ( ! strcmp ( V_24 , V_26 -> system ) )
return true ;
V_26 = V_26 -> V_28 ;
}
return false ;
}
static int F_17 ( struct V_25 * V_26 )
{
struct V_30 * V_31 ;
struct V_21 V_22 ;
char * V_20 ;
char * V_24 ;
T_3 * V_32 ;
int V_33 = 0 ;
int V_29 ;
int V_14 ;
V_20 = F_11 ( L_16 ) ;
if ( ! V_20 ) {
F_5 ( L_17 ) ;
return - V_23 ;
}
V_32 = F_18 ( V_20 ) ;
if ( ! V_32 ) {
V_14 = - V_17 ;
F_5 ( L_18 , V_20 ) ;
goto V_18;
}
F_19 (dir, dent, tps) {
if ( strcmp ( V_31 -> V_34 , L_19 ) == 0 ||
! F_16 ( V_31 -> V_34 , V_26 ) )
continue;
V_33 ++ ;
}
if ( F_6 ( V_10 , & V_33 , 4 ) != 4 ) {
V_14 = - V_15 ;
F_5 ( L_20 ) ;
goto V_18;
}
F_20 ( V_32 ) ;
F_19 (dir, dent, tps) {
if ( strcmp ( V_31 -> V_34 , L_19 ) == 0 ||
! F_16 ( V_31 -> V_34 , V_26 ) )
continue;
if ( F_21 ( & V_24 , L_21 , V_20 , V_31 -> V_34 ) < 0 ) {
V_14 = - V_23 ;
goto V_18;
}
V_29 = V_21 ( V_24 , & V_22 ) ;
if ( V_29 >= 0 ) {
T_1 V_5 = strlen ( V_31 -> V_34 ) + 1 ;
if ( F_6 ( V_10 , V_31 -> V_34 , V_5 ) != V_5 ||
F_15 ( V_24 , V_26 ) < 0 ) {
V_14 = - V_15 ;
free ( V_24 ) ;
goto V_18;
}
}
free ( V_24 ) ;
}
V_14 = 0 ;
V_18:
F_22 ( V_32 ) ;
F_12 ( V_20 ) ;
return V_14 ;
}
static int F_23 ( void )
{
unsigned long long V_5 = 0 ;
return F_6 ( V_10 , & V_5 , 4 ) != 4 ? - V_15 : 0 ;
}
static int F_24 ( void )
{
unsigned int V_5 ;
char * V_20 ;
struct V_21 V_22 ;
int V_29 , V_14 = 0 ;
V_20 = F_11 ( L_22 ) ;
if ( ! V_20 ) {
F_5 ( L_23 ) ;
return - V_23 ;
}
V_29 = V_21 ( V_20 , & V_22 ) ;
if ( V_29 < 0 ) {
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
static int F_25 ( void )
{
unsigned int V_5 ;
char * V_20 ;
struct V_21 V_22 ;
int V_29 , V_14 = 0 ;
V_20 = F_11 ( L_24 ) ;
if ( ! V_20 ) {
F_5 ( L_25 ) ;
return - V_23 ;
}
V_29 = V_21 ( V_20 , & V_22 ) ;
if ( V_29 < 0 ) {
V_5 = 0 ;
if ( F_6 ( V_10 , & V_5 , 8 ) != 8 )
V_14 = - V_15 ;
goto V_18;
}
V_14 = F_2 ( V_20 , 8 ) ;
V_18:
F_12 ( V_20 ) ;
return V_14 ;
}
static void
F_26 ( struct V_25 * V_26 )
{
while ( V_26 ) {
struct V_25 * V_35 = V_26 ;
V_26 = V_26 -> V_28 ;
F_27 ( & V_35 -> V_27 ) ;
F_27 ( & V_35 -> system ) ;
free ( V_35 ) ;
}
}
static struct V_25 *
F_28 ( struct V_36 * V_37 )
{
struct V_25 V_20 , * V_38 = & V_20 ;
struct V_39 * V_40 ;
int V_41 = 0 ;
F_29 (pos, pattrs, node) {
if ( V_40 -> V_42 . type != V_43 )
continue;
++ V_41 ;
if ( V_40 -> V_27 ) {
V_38 -> V_28 = F_30 ( V_40 -> V_27 ) ;
if ( V_38 -> V_28 )
goto V_28;
if ( strchr ( V_40 -> V_27 , ':' ) == NULL )
goto V_44;
goto error;
}
V_44:
V_38 -> V_28 = F_31 ( V_40 -> V_42 . V_45 ) ;
if ( ! V_38 -> V_28 ) {
error:
F_5 ( L_26 ) ;
F_26 ( & V_20 ) ;
return NULL ;
}
V_28:
V_38 = V_38 -> V_28 ;
}
return V_41 > 0 ? V_20 . V_28 : NULL ;
}
bool F_32 ( struct V_36 * V_37 )
{
struct V_39 * V_40 ;
F_29 (pos, pattrs, node)
if ( V_40 -> V_42 . type == V_43 )
return true ;
return false ;
}
static int F_33 ( void )
{
char V_6 [ 20 ] ;
T_1 V_5 ;
V_6 [ 0 ] = 23 ;
V_6 [ 1 ] = 8 ;
V_6 [ 2 ] = 68 ;
memcpy ( V_6 + 3 , L_27 , 7 ) ;
if ( F_6 ( V_10 , V_6 , 10 ) != 10 )
return - 1 ;
V_5 = strlen ( V_46 ) + 1 ;
if ( F_6 ( V_10 , V_46 , V_5 ) != V_5 )
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
if ( F_6 ( V_10 , & V_47 , 4 ) != 4 )
return - 1 ;
return 0 ;
}
struct V_48 * F_34 ( struct V_36 * V_37 ,
int V_13 , bool V_49 )
{
struct V_25 * V_26 ;
struct V_48 * V_50 ;
int V_14 ;
V_10 = V_13 ;
V_26 = F_28 ( V_37 ) ;
if ( ! V_26 )
return NULL ;
V_50 = malloc ( sizeof( * V_50 ) ) ;
if ( ! V_50 )
return NULL ;
V_50 -> V_49 = V_49 ;
V_50 -> V_5 = 0 ;
if ( V_49 ) {
int V_51 ;
snprintf ( V_50 -> V_52 , sizeof( V_50 -> V_52 ) ,
L_28 ) ;
if ( ! F_35 ( V_50 -> V_52 ) ) {
F_5 ( L_29 ) ;
return NULL ;
}
V_51 = F_4 ( V_50 -> V_52 , V_53 ) ;
if ( V_51 < 0 ) {
F_5 ( L_1 , V_50 -> V_52 ) ;
return NULL ;
}
V_10 = V_51 ;
}
V_14 = F_33 () ;
if ( V_14 )
goto V_18;
V_14 = F_10 () ;
if ( V_14 )
goto V_18;
V_14 = F_14 ( V_26 ) ;
if ( V_14 )
goto V_18;
V_14 = F_17 ( V_26 ) ;
if ( V_14 )
goto V_18;
V_14 = F_23 () ;
if ( V_14 )
goto V_18;
V_14 = F_24 () ;
if ( V_14 )
goto V_18;
V_14 = F_25 () ;
V_18:
if ( V_49 ) {
V_50 -> V_5 = F_3 ( V_10 , 0 , V_11 ) ;
F_9 ( V_10 ) ;
V_10 = V_13 ;
}
if ( V_14 )
F_27 ( & V_50 ) ;
F_26 ( V_26 ) ;
return V_50 ;
}
int F_36 ( struct V_48 * V_50 )
{
int V_14 = 0 ;
if ( V_50 -> V_49 ) {
V_14 = F_2 ( V_50 -> V_52 , 0 ) ;
F_37 ( V_50 -> V_52 ) ;
}
free ( V_50 ) ;
return V_14 ;
}
int F_38 ( int V_13 , struct V_36 * V_37 )
{
int V_14 ;
struct V_48 * V_50 ;
V_50 = F_34 ( V_37 , V_13 , false ) ;
if ( ! V_50 )
return - V_23 ;
V_14 = F_36 ( V_50 ) ;
return V_14 ;
}
