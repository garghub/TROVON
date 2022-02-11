static T_1 F_1 ( T_2 V_1 , T_1 V_2 )
{
if ( ! strcmp ( L_1 , V_1 ) ) {
F_2 ( V_3
L_2 ,
V_4 . V_5 ? L_3 : L_4 ,
V_4 . V_6 ? L_5 :
V_4 . V_7 ? L_6 : L_7 ) ;
}
if ( ! strcmp ( L_8 , V_1 ) ) {
F_2 (
L_9 ,
V_4 . V_8 ? L_3 : L_4 ,
V_4 . V_9 ? L_5 :
V_4 . V_10 ? L_6 : L_7 ) ;
}
return V_2 ;
}
void T_3 F_3 ( char * V_11 )
{
struct V_12 * V_13 ;
bool V_14 = true ;
int V_15 ;
if ( ! V_16 )
return;
if ( V_11 == NULL || * V_11 == '\0' ) {
F_4 ( L_10 ) ;
V_16 = FALSE ;
return;
}
if ( * V_11 == '!' ) {
V_11 ++ ;
if ( * V_11 == '\0' ) {
if ( ! V_4 . V_17 )
V_4 . V_17 =
V_18 ;
return;
} else if ( * V_11 == '*' ) {
V_4 . V_17 = V_19 ;
for ( V_15 = 0 ; V_15 < V_20 ; V_15 ++ ) {
V_13 = & V_21 [ V_15 ] ;
V_13 -> V_14 = false ;
}
return;
} else if ( * V_11 == '!' ) {
V_4 . V_17 = 0 ;
return;
}
V_14 = false ;
}
for ( V_15 = 0 ; V_15 < V_20 ; V_15 ++ ) {
V_13 = & V_21 [ V_15 ] ;
if ( ! strcmp ( V_13 -> string , V_11 ) ) {
V_13 -> V_14 = V_14 ;
break;
} else if ( V_13 -> string [ 0 ] == '\0' ) {
V_13 -> V_14 = V_14 ;
strncpy ( V_13 -> string , V_11 , V_22 ) ;
break;
}
}
}
static void T_3 F_5 ( bool V_14 )
{
V_4 . V_8 = ! ! V_14 ;
if ( V_14 ) {
F_3 ( L_11 ) ;
F_3 ( L_8 ) ;
} else {
F_3 ( L_12 ) ;
F_3 ( L_13 ) ;
}
}
static void T_3 F_6 ( bool V_14 )
{
V_4 . V_10 = 0 ;
V_4 . V_9 = 1 ;
F_5 ( V_14 ) ;
}
static void T_3 F_7 ( bool V_14 )
{
V_4 . V_5 = ! ! V_14 ;
if ( V_14 )
F_3 ( L_1 ) ;
else
F_3 ( L_14 ) ;
}
static void T_3 F_8 ( bool V_14 )
{
V_4 . V_7 = 0 ;
V_4 . V_6 = 1 ;
F_7 ( V_14 ) ;
}
static void T_3 F_9 ( void )
{
struct V_12 * V_13 ;
char * V_11 ;
int V_15 ;
T_4 V_23 ;
if ( V_4 . V_17 ) {
V_23 = F_10 ( V_4 . V_17 ) ;
if ( F_11 ( V_23 ) )
F_4 ( L_15 ,
V_4 . V_17 ==
V_19 ?
L_16 : L_7 ) ;
}
for ( V_15 = 0 ; V_15 < V_20 ; V_15 ++ ) {
V_13 = & V_21 [ V_15 ] ;
V_11 = V_13 -> string ;
if ( * V_11 == '\0' )
break;
if ( V_13 -> V_14 ) {
V_23 = F_12 ( V_11 ) ;
if ( F_11 ( V_23 ) )
F_4 ( L_17 , V_11 ) ;
} else {
V_23 = F_13 ( V_11 ) ;
if ( F_11 ( V_23 ) )
F_4 ( L_18 , V_11 ) ;
}
}
}
static int T_3 F_14 ( char * V_11 )
{
if ( V_11 && ! strcmp ( L_1 , V_11 ) )
F_8 ( true ) ;
else if ( V_11 && ! strcmp ( L_14 , V_11 ) )
F_8 ( false ) ;
else if ( V_11 && ! strcmp ( L_8 , V_11 ) )
F_6 ( true ) ;
else if ( V_11 && ! strcmp ( L_13 , V_11 ) )
F_6 ( false ) ;
else
F_3 ( V_11 ) ;
return 1 ;
}
bool F_15 ( void )
{
return V_24 >= V_25 ;
}
static void T_3 F_16 ( bool V_14 ,
const struct V_26 * V_27 )
{
F_17 ( L_19 , V_27 -> V_28 ) ;
V_4 . V_10 = 1 ;
F_5 ( V_14 ) ;
}
static void T_3 F_18 ( bool V_14 ,
const struct V_26 * V_27 )
{
F_17 ( L_20 , V_27 -> V_28 ) ;
V_4 . V_7 = 1 ;
F_7 ( V_14 ) ;
}
static int T_3 F_19 ( const struct V_26 * V_27 )
{
F_16 ( true , V_27 ) ;
return 0 ;
}
static int T_3 F_20 ( const struct V_26 * V_27 )
{
F_18 ( true , V_27 ) ;
return 0 ;
}
static int T_3 F_21 ( const struct V_26 * V_27 )
{
F_17 ( L_21 , V_27 -> V_28 ) ;
F_3 ( L_22 ) ;
F_3 ( L_23 ) ;
F_3 ( L_24 ) ;
return 0 ;
}
static int T_3 F_22 ( const struct V_26 * V_27 )
{
F_17 ( L_21 , V_27 -> V_28 ) ;
F_3 ( L_25 ) ;
return 0 ;
}
static int T_3 F_23 ( const struct V_26 * V_27 )
{
F_17 ( L_21 , V_27 -> V_28 ) ;
F_3 ( L_26 ) ;
return 0 ;
}
static T_3 void F_24 ( void )
{
F_25 ( V_29 ) ;
}
int T_3 F_26 ( void )
{
F_24 () ;
return 0 ;
}
int T_3 F_27 ( void )
{
F_28 ( F_1 ) ;
F_9 () ;
return 0 ;
}
