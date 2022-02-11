static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
const struct V_5 * V_6 )
{
F_2 ( V_4 ) ;
return - V_7 ;
}
static void F_3 ( struct V_8 * V_9 )
{
F_4 () ;
}
static void F_5 ( struct V_10 * V_11 )
{
F_6 ( & V_12 ) ;
if ( F_7 ( & V_13 ) == 0 )
F_8 ( & V_13 ) ;
F_9 ( & V_12 ) ;
}
static void F_10 ( void )
{
if ( F_11 ( V_14 == V_15 ) )
F_12 ( & V_16 ) ;
}
static int F_13 ( char * * V_17 )
{
if ( strncmp ( * V_17 , L_1 , 3 ) == 0 ||
strncmp ( * V_17 , L_2 , 3 ) == 0 ) {
if ( V_18 < V_19 ) {
V_20 [ V_18 ] = V_21 ;
V_18 ++ ;
if ( V_17 [ 0 ] [ 3 ] == ',' )
* V_17 += 4 ;
else
return 1 ;
}
}
return 0 ;
}
static void F_14 ( void )
{
int V_22 ;
for ( V_22 = 0 ; V_22 < V_18 ; V_22 ++ ) {
if ( V_20 [ V_22 ] == V_21 ) {
V_18 -- ;
V_20 [ V_22 ] = V_20 [ V_18 ] ;
V_20 [ V_18 ] = NULL ;
V_22 -- ;
}
}
F_15 ( & V_16 ) ;
}
static int F_16 ( char * V_23 )
{
if ( strlen ( V_23 ) >= V_24 ) {
F_17 ( V_25 L_3 ) ;
return - V_26 ;
}
strcpy ( V_27 , V_23 ) ;
return 0 ;
}
static void F_18 ( void )
{
if ( F_19 () )
return;
F_14 () ;
if ( V_28 == 1 )
F_20 ( & V_29 ) ;
}
static int F_21 ( void )
{
struct V_30 * V_31 ;
int V_32 = 0 ;
int V_33 ;
char * V_17 = V_27 ;
struct V_34 * V_35 ;
V_33 = F_16 ( V_27 ) ;
if ( V_33 || ! strlen ( V_27 ) || isspace ( V_27 [ 0 ] ) )
goto V_36;
V_33 = - V_7 ;
V_29 . V_37 = 0 ;
V_38 = NULL ;
V_39 = 0 ;
if ( strncmp ( V_17 , L_4 , 4 ) == 0 ) {
V_17 += 4 ;
V_39 = 1 ;
}
if ( F_13 ( & V_17 ) )
goto V_40;
V_31 = F_22 ( V_17 , & V_32 ) ;
if ( ! V_31 )
goto V_36;
V_35 = V_41 ;
while ( V_35 ) {
int V_42 ;
if ( V_35 -> V_43 && V_35 -> V_43 ( V_35 , & V_42 ) == V_31 &&
V_42 == V_32 ) {
V_29 . V_37 = 1 ;
break;
}
V_35 = V_35 -> V_44 ;
}
V_38 = V_31 ;
V_45 = V_32 ;
V_40:
V_33 = F_23 ( & V_29 ) ;
if ( V_33 )
goto V_36;
V_33 = F_24 () ;
if ( V_33 )
goto V_46;
V_28 = 1 ;
return 0 ;
V_46:
F_20 ( & V_29 ) ;
V_36:
F_14 () ;
V_27 [ 0 ] = 0 ;
V_28 = 0 ;
F_18 () ;
return V_33 ;
}
static int T_1 F_25 ( void )
{
if ( V_28 == 1 )
return 0 ;
return F_21 () ;
}
static int F_26 ( void )
{
if ( ! V_38 )
return - 1 ;
return V_38 -> V_47 -> V_48 ( V_38 ,
V_45 ) ;
}
static void F_27 ( T_2 V_49 )
{
if ( ! V_38 )
return;
V_38 -> V_47 -> V_50 ( V_38 ,
V_45 , V_49 ) ;
}
static int F_28 ( const char * V_51 , struct V_52 * V_53 )
{
int V_54 = strlen ( V_51 ) ;
if ( V_54 >= V_24 ) {
F_17 ( V_25 L_3 ) ;
return - V_26 ;
}
if ( V_28 < 0 ) {
strcpy ( V_27 , V_51 ) ;
return 0 ;
}
if ( V_55 ) {
F_17 ( V_25
L_5 ) ;
return - V_56 ;
}
strcpy ( V_27 , V_51 ) ;
if ( V_27 [ V_54 - 1 ] == '\n' )
V_27 [ V_54 - 1 ] = '\0' ;
if ( V_28 == 1 )
F_18 () ;
return F_21 () ;
}
static void F_29 ( void )
{
if ( ! V_57 && V_39 ) {
V_57 = 1 ;
F_30 ( V_58 [ V_59 ] . V_60 ) ;
}
if ( ! V_55 )
F_31 ( V_61 ) ;
}
static void F_32 ( void )
{
if ( ! V_55 )
F_33 ( V_61 ) ;
if ( V_39 && V_57 ) {
V_57 = 0 ;
F_34 () ;
}
F_10 () ;
}
static int T_1 F_35 ( char * V_23 )
{
char V_62 ;
F_16 ( V_23 ) ;
V_62 = V_27 [ 0 ] ;
F_25 () ;
V_27 [ 0 ] = V_62 ;
return 0 ;
}
