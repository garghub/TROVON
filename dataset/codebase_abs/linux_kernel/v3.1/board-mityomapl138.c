static void F_1 ( const char * V_1 )
{
int V_2 , V_3 ;
for ( V_2 = 0 ; V_1 && V_2 < F_2 ( V_4 ) ; V_2 ++ ) {
if ( ! strncmp ( V_1 , V_4 [ V_2 ] . V_5 ,
strlen ( V_4 [ V_2 ] . V_5 ) ) ) {
V_6 = V_4 [ V_2 ] . V_7 ;
break;
}
}
V_3 = F_3 ( L_1 ) ;
if ( V_3 )
F_4 ( L_2 , V_3 ) ;
}
static void F_1 ( const char * V_1 ) { }
static void F_5 ( struct V_8 * V_9 , void * V_10 )
{
int V_3 ;
const char * V_1 = NULL ;
struct V_11 * V_12 = & V_11 ;
V_3 = V_9 -> V_13 ( V_9 , ( char * ) & V_14 , 0 , sizeof( V_14 ) ) ;
if ( V_3 != sizeof( struct V_14 ) ) {
F_4 ( L_3 ,
V_3 ) ;
goto V_15;
}
if ( V_14 . V_16 != V_17 ) {
F_4 ( L_4 ,
V_14 . V_16 ) ;
goto V_15;
}
if ( V_14 . V_18 != V_19 ) {
F_4 ( L_5 ,
V_14 . V_18 ) ;
goto V_15;
}
F_6 ( L_6 , V_14 . V_20 ) ;
if ( F_7 ( V_14 . V_20 ) )
memcpy ( V_12 -> V_21 -> V_22 ,
V_14 . V_20 , V_23 ) ;
else
F_4 ( L_7
L_8 ) ;
V_1 = V_14 . V_1 ;
F_6 ( L_9 , V_1 ) ;
V_15:
F_1 ( V_1 ) ;
}
static int T_1 F_8 ( void )
{
return F_9 ( 1 , V_24 ,
F_2 ( V_24 ) ) ;
}
static void T_1 F_10 ( void )
{
F_11 ( V_25 ,
F_2 ( V_25 ) ) ;
}
static void T_1 F_12 ( void )
{
void T_2 * V_26 ;
int V_3 ;
T_3 V_27 ;
struct V_11 * V_12 = & V_11 ;
V_12 -> V_21 -> V_28 = 0 ;
V_26 = F_13 ( V_29 ) ;
V_27 = F_14 ( V_26 ) ;
if ( V_12 -> V_21 -> V_28 ) {
V_27 |= F_15 ( 8 ) ;
V_3 = F_16 ( V_30 ) ;
F_6 ( L_10 ) ;
} else {
V_27 &= ~ F_15 ( 8 ) ;
V_3 = F_16 ( V_31 ) ;
F_6 ( L_11 ) ;
}
if ( V_3 ) {
F_4 ( L_12 , V_3 ) ;
return;
}
F_17 ( V_27 , V_26 ) ;
V_12 -> V_21 -> V_32 = V_33 ;
V_3 = F_18 () ;
if ( V_3 )
F_4 ( L_13 , V_3 ) ;
}
static void T_1 F_19 ( void )
{
int V_3 ;
V_3 = F_20 ( NULL ) ;
if ( V_3 )
F_4 ( L_14 , V_3 ) ;
V_3 = F_21 () ;
if ( V_3 )
F_4 ( L_15 , V_3 ) ;
F_22 ( & V_34 ) ;
V_3 = F_23 ( 0 , & V_35 ) ;
if ( V_3 )
F_4 ( L_16 , V_3 ) ;
V_3 = F_8 () ;
if ( V_3 )
F_4 ( L_17 , V_3 ) ;
F_10 () ;
V_3 = F_24 ( 1 , V_36 ,
F_2 ( V_36 ) ) ;
if ( V_3 )
F_4 ( L_18 , V_3 ) ;
F_12 () ;
V_3 = F_25 () ;
if ( V_3 )
F_4 ( L_19 , V_3 ) ;
V_3 = F_26 () ;
if ( V_3 )
F_4 ( L_20 , V_3 ) ;
V_3 = F_27 ( & V_37 ) ;
if ( V_3 )
F_4 ( L_21 ,
V_3 ) ;
}
static int T_1 F_28 ( void )
{
if ( ! F_29 () )
return 0 ;
return F_30 ( L_22 , 1 , L_23 ) ;
}
static void T_1 F_31 ( void )
{
F_32 () ;
}
