static struct V_1 * F_1 (
const char * V_2 ,
int V_3 ,
struct V_4 * V_5 ,
const unsigned short * V_6 )
{
const struct V_7 * V_8 ;
const struct V_9 * V_10 ;
struct V_11 * V_12 ;
struct V_1 * V_13 = NULL ;
const unsigned short V_14 [] = { V_5 -> V_15 , V_16 } ;
if ( V_3 < 0 )
return NULL ;
if ( V_2 ) {
V_8 = F_2 ( V_17 , V_2 , NULL ) ;
if ( ! V_8 ) {
F_3 ( L_1 ,
V_18 ,
V_2 ) ;
return NULL ;
}
V_10 = (struct V_9 * ) V_8 -> V_19 ;
if ( ! V_10 ) {
F_3 ( L_2 ,
V_18 , V_2 ) ;
return NULL ;
}
V_5 -> V_20 = V_10 -> V_21 ;
}
V_12 = F_4 ( V_3 ) ;
if ( ! V_12 ) {
F_3 ( L_3 , V_18 , V_3 ) ;
return NULL ;
}
V_13 = F_5 ( V_12 , V_5 , V_14 , NULL ) ;
if ( ! V_13 && V_6 ) {
struct V_4 V_22 = {
F_6 ( L_4 , V_5 -> V_15 ) ,
} ;
struct V_1 * V_23 ;
V_23 = F_5 ( V_12 , & V_22 ,
V_6 , NULL ) ;
if ( V_23 ) {
F_7 ( L_5 ,
V_18 , V_3 , V_5 -> V_15 , V_23 -> V_15 ) ;
F_8 ( V_23 ) ;
V_13 = F_9 ( V_12 , V_5 ) ;
}
}
if ( ! V_13 )
F_10 ( L_6 ,
V_18 , V_3 , V_5 -> V_15 ) ;
else
F_7 ( L_7 ,
V_18 , V_3 , V_5 -> V_15 ) ;
F_11 ( V_12 ) ;
return V_13 ;
}
static int F_12 ( struct V_24 * V_25 , void * V_26 )
{
struct V_27 * V_28 = V_26 ;
static const char * V_29 = L_8 ;
struct V_11 * V_12 ;
if ( strncmp ( F_13 ( V_25 ) , V_29 , strlen ( V_29 ) ) != 0 )
return 0 ;
V_12 = F_14 ( V_25 ) ;
if ( strncmp ( V_12 -> V_2 , V_28 -> V_2 , strlen ( V_28 -> V_2 ) ) == 0 &&
V_28 -> V_30 ++ == V_28 -> V_21 )
return 1 ;
return 0 ;
}
static int F_15 ( enum V_31 type )
{
struct V_24 * V_25 = NULL ;
struct V_11 * V_12 ;
struct V_27 V_28 ;
memset ( & V_28 , 0 , sizeof( V_28 ) ) ;
V_28 . V_2 = V_32 [ type ] ;
V_28 . V_21 = ( type == V_33 ) ? 1 : 0 ;
V_25 = F_16 ( & V_34 , NULL , & V_28 , F_12 ) ;
if ( ! V_25 ) {
F_10 ( L_9 , V_18 ,
V_28 . V_2 ) ;
return - V_35 ;
}
V_12 = F_14 ( V_25 ) ;
return V_12 -> V_36 ;
}
static struct V_1 * F_17 (
const char * V_2 ,
enum V_31 type ,
struct V_4 * V_5 ,
const unsigned short * V_37 )
{
return F_1 ( V_2 ,
F_15 ( type ) ,
V_5 ,
V_37 ) ;
}
static struct V_1 * F_18 ( const char * V_2 ,
enum V_31 type ,
struct V_4 * V_5 )
{
return F_1 ( V_2 ,
F_15 ( type ) ,
V_5 ,
NULL ) ;
}
static int F_19 ( enum V_31 type )
{
if ( V_38 )
return 0 ;
V_38 = F_18 ( L_10 , type , & V_39 ) ;
return ( ! V_38 ) ? - V_40 : 0 ;
}
static int F_20 ( enum V_31 type )
{
const unsigned short V_14 [] = { V_41 ,
V_16 } ;
if ( V_38 )
return 0 ;
V_38 = F_17 ( L_10 , type ,
& V_42 , V_14 ) ;
return ( ! V_38 ) ? - V_40 : 0 ;
}
static int F_21 ( enum V_31 type )
{
if ( V_38 )
return 0 ;
V_38 = F_18 ( L_10 , type , & V_43 ) ;
return ( ! V_38 ) ? - V_40 : 0 ;
}
static int F_22 ( enum V_31 type )
{
const unsigned short V_14 [] = { V_44 ,
V_16 } ;
if ( V_45 )
return 0 ;
V_45 = F_17 ( L_11 , type ,
& V_46 , V_14 ) ;
return ( ! V_45 ) ? - V_40 : 0 ;
}
static int F_23 ( enum V_31 type )
{
if ( V_47 )
return 0 ;
V_47 = F_18 ( L_12 , type , & V_48 ) ;
return ( ! V_47 ) ? - V_40 : 0 ;
}
static int F_24 ( enum V_31 type )
{
if ( V_47 )
return 0 ;
V_47 = F_18 ( NULL , type , & V_49 ) ;
return ( ! V_47 ) ? - V_40 : 0 ;
}
static int F_25 ( enum V_31 type )
{
if ( V_47 )
return 0 ;
V_47 = F_18 ( NULL , type , & V_50 ) ;
return ( ! V_47 ) ? - V_40 : 0 ;
}
static int T_1 F_26 ( const struct V_51 * V_52 )
{
V_53 = ( void * ) V_52 -> V_54 ;
F_7 ( L_13 , V_52 -> V_55 ) ;
return 1 ;
}
static int F_27 ( struct V_56 * V_57 )
{
int V_58 ;
int V_59 = 0 ;
for ( V_58 = 0 ; V_58 < V_60 ; V_58 ++ ) {
struct V_61 * V_62 ;
V_62 = & V_53 -> V_63 [ V_58 ] ;
if ( V_62 -> V_64 == NULL )
break;
if ( V_62 -> V_65 == V_66 || V_62 -> V_65 == V_67 )
continue;
if ( F_15 ( V_62 -> type ) == - V_35 ) {
V_59 = - V_68 ;
continue;
}
if ( V_62 -> V_64 ( V_62 -> type ) == - V_40 ) {
if ( ++ V_62 -> V_69 < V_70 ) {
V_59 = - V_68 ;
} else {
F_10 ( L_14 ,
V_18 ) ;
V_62 -> V_65 = V_66 ;
}
} else {
V_62 -> V_65 = V_67 ;
}
}
return V_59 ;
}
static int T_1 F_28 ( void )
{
int V_59 ;
if ( ! F_29 ( V_71 ) ) {
F_7 ( L_15 , V_18 ) ;
return - V_35 ;
}
V_59 = F_30 ( & V_72 ) ;
if ( V_59 )
return V_59 ;
V_73 = F_31 ( L_16 , - 1 ) ;
if ( ! V_73 ) {
V_59 = - V_74 ;
goto V_75;
}
V_59 = F_32 ( V_73 ) ;
if ( V_59 )
goto V_76;
return 0 ;
V_76:
F_33 ( V_73 ) ;
V_75:
F_34 ( & V_72 ) ;
return V_59 ;
}
static void T_2 F_35 ( void )
{
if ( V_47 )
F_8 ( V_47 ) ;
if ( V_38 )
F_8 ( V_38 ) ;
if ( V_45 )
F_8 ( V_45 ) ;
F_36 ( V_73 ) ;
F_34 ( & V_72 ) ;
}
