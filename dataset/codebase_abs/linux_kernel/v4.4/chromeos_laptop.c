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
const unsigned short V_14 [] = { V_43 ,
V_16 } ;
if ( V_44 )
return 0 ;
V_44 = F_17 ( L_11 , type ,
& V_45 , V_14 ) ;
return ( ! V_44 ) ? - V_40 : 0 ;
}
static int F_22 ( enum V_31 type )
{
if ( V_46 )
return 0 ;
V_46 = F_18 ( L_12 , type , & V_47 ) ;
return ( ! V_46 ) ? - V_40 : 0 ;
}
static int F_23 ( enum V_31 type )
{
if ( V_46 )
return 0 ;
V_46 = F_18 ( NULL , type , & V_48 ) ;
return ( ! V_46 ) ? - V_40 : 0 ;
}
static int F_24 ( enum V_31 type )
{
if ( V_46 )
return 0 ;
V_46 = F_18 ( NULL , type , & V_49 ) ;
return ( ! V_46 ) ? - V_40 : 0 ;
}
static int T_1 F_25 ( const struct V_50 * V_51 )
{
V_52 = ( void * ) V_51 -> V_53 ;
F_7 ( L_13 , V_51 -> V_54 ) ;
return 1 ;
}
static int F_26 ( struct V_55 * V_56 )
{
int V_57 ;
int V_58 = 0 ;
for ( V_57 = 0 ; V_57 < V_59 ; V_57 ++ ) {
struct V_60 * V_61 ;
V_61 = & V_52 -> V_62 [ V_57 ] ;
if ( V_61 -> V_63 == NULL )
break;
if ( V_61 -> V_64 == V_65 || V_61 -> V_64 == V_66 )
continue;
if ( F_15 ( V_61 -> type ) == - V_35 ) {
V_58 = - V_67 ;
continue;
}
if ( V_61 -> V_63 ( V_61 -> type ) == - V_40 ) {
if ( ++ V_61 -> V_68 < V_69 ) {
V_58 = - V_67 ;
} else {
F_10 ( L_14 ,
V_18 ) ;
V_61 -> V_64 = V_65 ;
}
} else {
V_61 -> V_64 = V_66 ;
}
}
return V_58 ;
}
static int T_1 F_27 ( void )
{
int V_58 ;
if ( ! F_28 ( V_70 ) ) {
F_7 ( L_15 , V_18 ) ;
return - V_35 ;
}
V_58 = F_29 ( & V_71 ) ;
if ( V_58 )
return V_58 ;
V_72 = F_30 ( L_16 , - 1 ) ;
if ( ! V_72 ) {
V_58 = - V_73 ;
goto V_74;
}
V_58 = F_31 ( V_72 ) ;
if ( V_58 )
goto V_75;
return 0 ;
V_75:
F_32 ( V_72 ) ;
V_74:
F_33 ( & V_71 ) ;
return V_58 ;
}
static void T_2 F_34 ( void )
{
if ( V_46 )
F_8 ( V_46 ) ;
if ( V_38 )
F_8 ( V_38 ) ;
if ( V_44 )
F_8 ( V_44 ) ;
F_35 ( V_72 ) ;
F_33 ( & V_71 ) ;
}
