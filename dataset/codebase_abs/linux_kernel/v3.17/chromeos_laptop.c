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
F_6 ( L_4 ,
V_15 , V_3 , V_5 -> V_19 ) ;
else
F_7 ( L_5 ,
V_15 , V_3 , V_5 -> V_19 ) ;
F_8 ( V_12 ) ;
return V_13 ;
}
static int F_9 ( struct V_20 * V_21 , void * V_22 )
{
struct V_23 * V_24 = V_22 ;
static const char * V_25 = L_6 ;
struct V_11 * V_12 ;
if ( strncmp ( F_10 ( V_21 ) , V_25 , strlen ( V_25 ) ) != 0 )
return 0 ;
V_12 = F_11 ( V_21 ) ;
if ( strncmp ( V_12 -> V_2 , V_24 -> V_2 , strlen ( V_24 -> V_2 ) ) == 0 &&
V_24 -> V_26 ++ == V_24 -> V_18 )
return 1 ;
return 0 ;
}
static int F_12 ( enum V_27 type )
{
struct V_20 * V_21 = NULL ;
struct V_11 * V_12 ;
struct V_23 V_24 ;
memset ( & V_24 , 0 , sizeof( V_24 ) ) ;
V_24 . V_2 = V_28 [ type ] ;
V_24 . V_18 = ( type == V_29 ) ? 1 : 0 ;
V_21 = F_13 ( & V_30 , NULL , & V_24 , F_9 ) ;
if ( ! V_21 ) {
F_6 ( L_7 , V_15 ,
V_24 . V_2 ) ;
return - V_31 ;
}
V_12 = F_11 ( V_21 ) ;
return V_12 -> V_32 ;
}
static struct V_1 * F_14 (
const char * V_2 ,
enum V_27 type ,
struct V_4 * V_5 ,
const unsigned short * V_6 )
{
return F_1 ( V_2 ,
F_12 ( type ) ,
V_5 ,
V_6 ) ;
}
static struct V_1 * F_15 ( const char * V_2 ,
enum V_27 type ,
struct V_4 * V_5 )
{
const unsigned short V_33 [] = { V_5 -> V_19 , V_34 } ;
return F_1 ( V_2 ,
F_12 ( type ) ,
V_5 ,
V_33 ) ;
}
static int F_16 ( enum V_27 type )
{
if ( V_35 )
return 0 ;
V_35 = F_15 ( L_8 , type , & V_36 ) ;
return ( ! V_35 ) ? - V_37 : 0 ;
}
static int F_17 ( enum V_27 type )
{
const unsigned short V_33 [] = { V_38 ,
V_39 ,
V_34 } ;
if ( V_35 )
return 0 ;
V_35 = F_14 ( L_8 , type ,
& V_40 , V_33 ) ;
return ( ! V_35 ) ? - V_37 : 0 ;
}
static int F_18 ( enum V_27 type )
{
const unsigned short V_33 [] = { V_41 ,
V_42 ,
V_34 } ;
if ( V_43 )
return 0 ;
V_43 = F_14 ( L_9 , type ,
& V_44 , V_33 ) ;
return ( ! V_43 ) ? - V_37 : 0 ;
}
static int F_19 ( enum V_27 type )
{
if ( V_45 )
return 0 ;
V_45 = F_15 ( L_10 , type , & V_46 ) ;
return ( ! V_45 ) ? - V_37 : 0 ;
}
static int F_20 ( enum V_27 type )
{
if ( V_45 )
return 0 ;
V_45 = F_15 ( NULL , type , & V_47 ) ;
return ( ! V_45 ) ? - V_37 : 0 ;
}
static int F_21 ( enum V_27 type )
{
if ( V_45 )
return 0 ;
V_45 = F_15 ( NULL , type , & V_48 ) ;
return ( ! V_45 ) ? - V_37 : 0 ;
}
static int T_1 F_22 ( const struct V_49 * V_50 )
{
V_51 = ( void * ) V_50 -> V_52 ;
F_7 ( L_11 , V_50 -> V_53 ) ;
return 1 ;
}
static int F_23 ( struct V_54 * V_55 )
{
int V_56 ;
int V_57 = 0 ;
for ( V_56 = 0 ; V_56 < V_58 ; V_56 ++ ) {
struct V_59 * V_60 ;
V_60 = & V_51 -> V_61 [ V_56 ] ;
if ( V_60 -> V_62 == NULL )
break;
if ( V_60 -> V_63 == V_64 || V_60 -> V_63 == V_65 )
continue;
if ( F_12 ( V_60 -> type ) == - V_31 ) {
V_57 = - V_66 ;
continue;
}
if ( V_60 -> V_62 ( V_60 -> type ) == - V_37 ) {
if ( ++ V_60 -> V_67 < V_68 ) {
V_57 = - V_66 ;
} else {
F_6 ( L_12 ,
V_15 ) ;
V_60 -> V_63 = V_64 ;
}
} else {
V_60 -> V_63 = V_65 ;
}
}
return V_57 ;
}
static int T_1 F_24 ( void )
{
int V_57 ;
if ( ! F_25 ( V_69 ) ) {
F_7 ( L_13 , V_15 ) ;
return - V_31 ;
}
V_57 = F_26 ( & V_70 ) ;
if ( V_57 )
return V_57 ;
V_71 = F_27 ( L_14 , - 1 ) ;
if ( ! V_71 ) {
V_57 = - V_72 ;
goto V_73;
}
V_57 = F_28 ( V_71 ) ;
if ( V_57 )
goto V_74;
return 0 ;
V_74:
F_29 ( V_71 ) ;
V_73:
F_30 ( & V_70 ) ;
return V_57 ;
}
static void T_2 F_31 ( void )
{
if ( V_45 )
F_32 ( V_45 ) ;
if ( V_35 )
F_32 ( V_35 ) ;
if ( V_43 )
F_32 ( V_43 ) ;
F_33 ( V_71 ) ;
F_30 ( & V_70 ) ;
}
