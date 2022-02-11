static T_1 int F_1 ( char * V_1 )
{
F_2 ( & V_1 , & V_2 ) ;
F_3 ( L_1 ,
V_2 ? L_2 : L_3 ) ;
return 1 ;
}
static int T_1 F_4 ( void )
{
F_3 ( L_4 ,
V_2 ? L_5 : L_6 ) ;
return 0 ;
}
static int F_5 ( int V_3 )
{
return 1 << V_3 ;
}
static void F_6 ( void )
{
#ifdef F_7
F_8 ( V_4
L_7 ,
V_5 ) ;
#endif
}
static void F_9 ( int V_3 , struct V_6 * V_7 )
{
F_10 ( V_7 ) ;
F_11 ( V_7 ) [ 0 ] = V_8 ;
}
static int F_12 ( void )
{
return 1 ;
}
static int T_1 F_13 ( char * V_9 )
{
struct V_10 * * V_11 ;
if ( ! V_9 )
return - V_12 ;
for ( V_11 = V_13 ; V_11 < V_14 ; V_11 ++ ) {
if ( ! strcmp ( ( * V_11 ) -> V_15 , V_9 ) ) {
V_10 = * V_11 ;
V_16 = 1 ;
return 0 ;
}
}
return 0 ;
}
void T_1 F_14 ( void )
{
int V_17 = V_18 [ V_19 ] ;
if ( F_15 () > 8 ) {
switch ( V_20 . V_21 ) {
case V_22 :
if ( ! F_16 ( V_17 ) ) {
V_23 = 0 ;
break;
}
case V_24 :
V_23 = 1 ;
}
}
#ifdef F_17
if ( ! V_16 && V_10 == & V_25 ) {
struct V_10 * V_26 = F_18 () ;
if ( V_26 ) {
V_10 = V_26 ;
F_8 ( V_4 L_8 ,
V_10 -> V_15 ) ;
}
}
#endif
if ( V_10 -> V_27 )
V_10 -> V_27 () ;
}
void T_1 F_19 ( void )
{
if ( ! V_16 ) {
struct V_10 * * V_11 ;
for ( V_11 = V_13 ; V_11 < V_14 ; V_11 ++ ) {
if ( ( * V_11 ) -> V_28 () ) {
V_10 = * V_11 ;
break;
}
}
if ( V_11 == V_14 )
F_20 ( L_9 ) ;
}
F_8 ( V_4 L_10 , V_10 -> V_15 ) ;
}
int T_1
F_21 ( struct V_29 * V_30 , char * V_31 , char * V_32 )
{
struct V_10 * * V_11 ;
for ( V_11 = V_13 ; V_11 < V_14 ; V_11 ++ ) {
if ( ! ( ( * V_11 ) -> V_33 ) )
continue;
if ( ! ( * V_11 ) -> V_33 ( V_30 , V_31 , V_32 ) )
continue;
if ( ! V_16 ) {
V_10 = * V_11 ;
F_8 ( V_4 L_11 ,
V_10 -> V_15 ) ;
}
return 1 ;
}
return 0 ;
}
int T_1 F_22 ( char * V_34 , char * V_35 )
{
struct V_10 * * V_11 ;
for ( V_11 = V_13 ; V_11 < V_14 ; V_11 ++ ) {
if ( ! ( * V_11 ) -> V_36 )
continue;
if ( ! ( * V_11 ) -> V_36 ( V_34 , V_35 ) )
continue;
if ( ! V_16 ) {
V_10 = * V_11 ;
F_8 ( V_4 L_11 ,
V_10 -> V_15 ) ;
}
return 1 ;
}
return 0 ;
}
