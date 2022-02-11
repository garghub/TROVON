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
static int F_9 ( void )
{
return 1 ;
}
static int T_1 F_10 ( char * V_6 )
{
struct V_7 * * V_8 ;
if ( ! V_6 )
return - V_9 ;
for ( V_8 = V_10 ; V_8 < V_11 ; V_8 ++ ) {
if ( ! strcmp ( ( * V_8 ) -> V_12 , V_6 ) ) {
V_7 = * V_8 ;
V_13 = 1 ;
return 0 ;
}
}
return 0 ;
}
void T_1 F_11 ( void )
{
int V_14 = V_15 [ V_16 ] ;
if ( F_12 () > 8 ) {
switch ( V_17 . V_18 ) {
case V_19 :
if ( ! F_13 ( V_14 ) ) {
V_20 = 0 ;
break;
}
case V_21 :
V_20 = 1 ;
}
}
#ifdef F_14
if ( ! V_13 && V_7 == & V_22 )
F_15 () ;
#endif
if ( V_7 -> V_23 )
V_7 -> V_23 () ;
if ( V_24 . V_25 )
V_24 . V_25 () ;
}
void T_1 F_16 ( void )
{
if ( ! V_13 ) {
struct V_7 * * V_8 ;
for ( V_8 = V_10 ; V_8 < V_11 ; V_8 ++ ) {
if ( ( * V_8 ) -> V_26 () ) {
V_7 = * V_8 ;
break;
}
}
if ( V_8 == V_11 )
F_17 ( L_8 ) ;
}
F_8 ( V_4 L_9 , V_7 -> V_12 ) ;
}
int T_1 F_18 ( char * V_27 , char * V_28 )
{
struct V_7 * * V_8 ;
for ( V_8 = V_10 ; V_8 < V_11 ; V_8 ++ ) {
if ( ! ( * V_8 ) -> V_29 )
continue;
if ( ! ( * V_8 ) -> V_29 ( V_27 , V_28 ) )
continue;
if ( ! V_13 ) {
V_7 = * V_8 ;
F_8 ( V_4 L_10 ,
V_7 -> V_12 ) ;
}
return 1 ;
}
return 0 ;
}
