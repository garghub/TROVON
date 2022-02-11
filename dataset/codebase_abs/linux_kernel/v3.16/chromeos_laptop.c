static struct V_1 * F_1 (
const char * V_2 ,
int V_3 ,
struct V_4 * V_5 ,
const unsigned short * V_6 )
{
const struct V_7 * V_8 ;
const struct V_9 * V_10 ;
struct V_11 * V_12 ;
struct V_1 * V_13 ;
if ( V_3 < 0 )
return NULL ;
if ( V_2 ) {
V_8 = F_2 ( V_14 , V_2 , NULL ) ;
if ( ! V_8 ) {
F_3 ( L_1 ,
V_15 ,
V_2 ) ;
return NULL ;
}
V_10 = (struct V_9 * ) V_8 -> V_16 ;
if ( ! V_10 ) {
F_3 ( L_2 ,
V_15 , V_2 ) ;
return NULL ;
}
V_5 -> V_17 = V_10 -> V_18 ;
}
V_12 = F_4 ( V_3 ) ;
if ( ! V_12 ) {
F_3 ( L_3 , V_15 , V_3 ) ;
return NULL ;
}
V_13 = F_5 ( V_12 , V_5 , V_6 , NULL ) ;
if ( ! V_13 )
F_3 ( L_4 ,
V_15 , V_3 , V_5 -> V_19 ) ;
else
F_6 ( L_5 ,
V_15 , V_3 , V_5 -> V_19 ) ;
F_7 ( V_12 ) ;
return V_13 ;
}
static int F_8 ( struct V_20 * V_21 , void * V_22 )
{
const char * V_2 = V_22 ;
static const char * V_23 = L_6 ;
struct V_11 * V_12 ;
if ( strncmp ( F_9 ( V_21 ) , V_23 , strlen ( V_23 ) ) != 0 )
return 0 ;
V_12 = F_10 ( V_21 ) ;
return ( strncmp ( V_12 -> V_2 , V_2 , strlen ( V_2 ) ) == 0 ) ;
}
static int F_11 ( enum V_24 type )
{
struct V_20 * V_21 = NULL ;
struct V_11 * V_12 ;
const char * V_2 = V_25 [ type ] ;
V_21 = F_12 ( & V_26 , NULL , ( void * ) V_2 ,
F_8 ) ;
if ( ! V_21 ) {
F_13 ( L_7 , V_15 ,
V_2 ) ;
return - V_27 ;
}
V_12 = F_10 ( V_21 ) ;
return V_12 -> V_28 ;
}
static struct V_1 * F_14 (
const char * V_2 ,
enum V_24 type ,
struct V_4 * V_5 ,
const unsigned short * V_6 )
{
return F_1 ( V_2 ,
F_11 ( type ) ,
V_5 ,
V_6 ) ;
}
static struct V_1 * F_15 ( const char * V_2 ,
enum V_24 type ,
struct V_4 * V_5 )
{
const unsigned short V_29 [] = { V_5 -> V_19 , V_30 } ;
return F_1 ( V_2 ,
F_11 ( type ) ,
V_5 ,
V_29 ) ;
}
static int F_16 ( enum V_24 type )
{
if ( V_31 )
return 0 ;
V_31 = F_15 ( L_8 , type , & V_32 ) ;
return ( ! V_31 ) ? - V_33 : 0 ;
}
static int F_17 ( enum V_24 type )
{
const unsigned short V_29 [] = { V_34 ,
V_35 ,
V_30 } ;
if ( V_31 )
return 0 ;
V_31 = F_14 ( L_8 , type ,
& V_36 , V_29 ) ;
return ( ! V_31 ) ? - V_33 : 0 ;
}
static int F_18 ( enum V_24 type )
{
const unsigned short V_29 [] = { V_37 ,
V_38 ,
V_30 } ;
if ( V_39 )
return 0 ;
V_39 = F_14 ( L_9 , type ,
& V_40 , V_29 ) ;
return ( ! V_39 ) ? - V_33 : 0 ;
}
static int F_19 ( enum V_24 type )
{
if ( V_41 )
return 0 ;
V_41 = F_15 ( L_10 , type , & V_42 ) ;
return ( ! V_41 ) ? - V_33 : 0 ;
}
static int F_20 ( enum V_24 type )
{
if ( V_41 )
return 0 ;
V_41 = F_15 ( NULL , type , & V_43 ) ;
return ( ! V_41 ) ? - V_33 : 0 ;
}
static int F_21 ( enum V_24 type )
{
if ( V_41 )
return 0 ;
V_41 = F_15 ( NULL , type , & V_44 ) ;
return ( ! V_41 ) ? - V_33 : 0 ;
}
static int T_1 F_22 ( const struct V_45 * V_46 )
{
V_47 = ( void * ) V_46 -> V_48 ;
F_6 ( L_11 , V_46 -> V_49 ) ;
return 1 ;
}
static int F_23 ( struct V_50 * V_51 )
{
int V_52 ;
int V_53 = 0 ;
for ( V_52 = 0 ; V_52 < V_54 ; V_52 ++ ) {
struct V_55 * V_56 ;
V_56 = & V_47 -> V_57 [ V_52 ] ;
if ( V_56 -> V_58 == NULL )
break;
if ( V_56 -> V_58 ( V_56 -> type ) )
V_53 = - V_59 ;
}
return V_53 ;
}
static int T_1 F_24 ( void )
{
int V_53 ;
if ( ! F_25 ( V_60 ) ) {
F_6 ( L_12 , V_15 ) ;
return - V_27 ;
}
V_53 = F_26 ( & V_61 ) ;
if ( V_53 )
return V_53 ;
V_62 = F_27 ( L_13 , - 1 ) ;
if ( ! V_62 ) {
V_53 = - V_63 ;
goto V_64;
}
V_53 = F_28 ( V_62 ) ;
if ( V_53 )
goto V_65;
return 0 ;
V_65:
F_29 ( V_62 ) ;
V_64:
F_30 ( & V_61 ) ;
return V_53 ;
}
static void T_2 F_31 ( void )
{
if ( V_41 )
F_32 ( V_41 ) ;
if ( V_31 )
F_32 ( V_31 ) ;
if ( V_39 )
F_32 ( V_39 ) ;
F_33 ( V_62 ) ;
F_30 ( & V_61 ) ;
}
