static struct V_1 * F_1 ( struct V_2 * V_2 )
{
return (struct V_1 * ) & V_2 -> V_3 ;
}
static struct V_4 * F_2 ( struct V_5 * V_6 )
{
return (struct V_4 * ) & V_6 -> V_3 ;
}
static void F_3 ( struct V_2 * V_2 ,
struct V_5 * V_6 )
{
struct V_1 * V_1 = F_1 ( V_2 ) ;
bool V_7 = false ;
int V_8 ;
for ( V_8 = 0 ; V_8 < V_9 ; V_8 ++ ) {
struct V_10 * V_11 ;
V_11 = & V_1 -> V_12 -> V_13 [ V_8 ] ;
if ( F_4 ( V_11 -> V_6 ) == V_6 ) {
F_5 ( V_11 -> V_6 , NULL ) ;
F_6 ( V_11 -> V_14 ) ;
V_7 = true ;
}
}
if ( V_7 )
F_7 ( V_2 ) ;
}
static struct V_5 * F_8 ( struct V_2 * V_2 ,
struct V_1 * V_1 ,
struct V_15 * V_16 ,
unsigned char V_17 )
{
int V_18 = F_9 ( V_2 , V_17 ) ;
return F_10 ( V_2 , V_18 ) ;
}
static struct V_5 * F_11 ( struct V_2 * V_2 ,
struct V_1 * V_1 ,
struct V_15 * V_16 ,
unsigned char V_17 )
{
return F_12 ( F_13 ( V_1 , V_17 ) ) ;
}
static char * F_14 ( T_1 * V_19 )
{
int V_8 ;
for ( V_8 = 0 ; V_8 < V_20 ; V_8 ++ ) {
const struct V_21 * V_22 ;
V_22 = & V_23 [ V_8 ] ;
if ( V_22 -> V_19 == V_19 )
return V_22 -> V_24 ;
}
return NULL ;
}
static T_1 * F_15 ( const char * V_24 )
{
int V_8 ;
for ( V_8 = 0 ; V_8 < V_20 ; V_8 ++ ) {
const struct V_21 * V_22 ;
V_22 = & V_23 [ V_8 ] ;
if ( ! strcmp ( V_22 -> V_24 , V_24 ) )
return V_22 -> V_19 ;
}
return NULL ;
}
static unsigned int F_16 ( struct V_1 * V_1 ,
struct V_15 * V_16 )
{
struct V_25 * V_26 ;
T_2 V_27 ;
unsigned char * V_28 ;
V_26 = F_12 ( V_1 -> V_26 ) ;
if ( F_17 ( ! V_26 ) )
return 0 ;
V_27 = F_18 ( V_26 , V_16 ) ;
V_28 = ( char * ) & V_27 ;
return V_28 [ 0 ] ^ V_28 [ 1 ] ^ V_28 [ 2 ] ^ V_28 [ 3 ] ;
}
static void F_19 ( unsigned int V_29 , struct V_1 * V_1 ,
struct V_4 * V_4 ,
unsigned char V_17 )
{
struct V_30 * V_31 ;
struct V_32 * V_33 ;
struct V_32 * V_34 ;
V_31 = F_20 ( V_1 -> V_31 ) ;
V_33 = F_20 ( V_4 -> V_31 ) ;
V_34 = & V_31 -> V_34 [ V_17 ] ;
F_21 ( & V_31 -> V_35 ) ;
V_33 -> V_29 += V_29 ;
V_34 -> V_29 += V_29 ;
F_22 ( & V_31 -> V_35 ) ;
}
static bool F_23 ( struct V_2 * V_2 , struct V_15 * V_16 )
{
struct V_1 * V_1 = F_1 ( V_2 ) ;
T_1 * V_36 ;
struct V_5 * V_6 ;
unsigned char V_17 ;
unsigned int V_29 = V_16 -> V_37 ;
V_17 = F_16 ( V_1 , V_16 ) ;
V_36 = F_12 ( V_1 -> V_36 ) ;
V_6 = V_36 ( V_2 , V_1 , V_16 , V_17 ) ;
if ( F_17 ( ! V_6 ) )
goto V_38;
if ( F_24 ( V_2 , V_6 , V_16 ) )
return false ;
F_19 ( V_29 , V_1 , F_2 ( V_6 ) , V_17 ) ;
return true ;
V_38:
F_25 ( V_16 ) ;
return false ;
}
static int F_26 ( struct V_2 * V_2 , struct V_39 * V_40 )
{
struct V_1 * V_1 = F_1 ( V_2 ) ;
if ( ! V_1 -> V_12 -> V_41 ) {
V_40 -> V_42 . V_43 . V_37 = 0 ;
V_40 -> V_42 . V_43 . V_44 = NULL ;
return 0 ;
}
V_40 -> V_42 . V_43 . V_37 = V_1 -> V_12 -> V_41 -> V_37 *
sizeof( struct V_45 ) ;
V_40 -> V_42 . V_43 . V_44 = V_1 -> V_12 -> V_41 -> V_46 ;
return 0 ;
}
static int F_27 ( struct V_47 * * V_48 , T_3 V_49 ,
const void * V_42 )
{
struct V_47 * V_50 ;
struct V_45 * V_46 = (struct V_45 * ) V_42 ;
if ( V_49 % sizeof( struct V_45 ) )
return - V_51 ;
V_50 = F_28 ( sizeof( struct V_47 ) , V_52 ) ;
if ( ! V_50 )
return - V_53 ;
V_50 -> V_46 = F_29 ( V_46 , V_49 , V_52 ) ;
if ( ! V_50 -> V_46 ) {
F_30 ( V_50 ) ;
return - V_53 ;
}
V_50 -> V_37 = V_49 / sizeof( struct V_45 ) ;
* V_48 = V_50 ;
return 0 ;
}
static void F_31 ( struct V_47 * V_50 )
{
F_30 ( V_50 -> V_46 ) ;
F_30 ( V_50 ) ;
}
static int F_32 ( struct V_2 * V_2 , struct V_39 * V_40 )
{
struct V_1 * V_1 = F_1 ( V_2 ) ;
struct V_25 * V_26 = NULL ;
struct V_25 * V_54 ;
struct V_47 * V_50 = NULL ;
int V_55 ;
if ( V_40 -> V_42 . V_43 . V_37 ) {
V_55 = F_27 ( & V_50 , V_40 -> V_42 . V_43 . V_37 ,
V_40 -> V_42 . V_43 . V_44 ) ;
if ( V_55 )
return V_55 ;
V_55 = F_33 ( & V_26 , V_50 ) ;
if ( V_55 ) {
F_31 ( V_50 ) ;
return V_55 ;
}
}
if ( V_1 -> V_12 -> V_41 ) {
F_31 ( V_1 -> V_12 -> V_41 ) ;
V_54 = F_34 ( V_1 -> V_26 ,
F_35 ( & V_2 -> V_56 ) ) ;
F_36 ( V_54 ) ;
}
F_37 ( V_1 -> V_26 , V_26 ) ;
V_1 -> V_12 -> V_41 = V_50 ;
return 0 ;
}
static int F_38 ( struct V_2 * V_2 , struct V_39 * V_40 )
{
struct V_1 * V_1 = F_1 ( V_2 ) ;
T_1 * V_19 ;
char * V_24 ;
V_19 = F_34 ( V_1 -> V_36 ,
F_35 ( & V_2 -> V_56 ) ) ;
V_24 = F_14 ( V_19 ) ;
F_39 ( ! V_24 ) ;
V_40 -> V_42 . V_57 = V_24 ;
return 0 ;
}
static int F_40 ( struct V_2 * V_2 , struct V_39 * V_40 )
{
struct V_1 * V_1 = F_1 ( V_2 ) ;
T_1 * V_19 ;
V_19 = F_15 ( V_40 -> V_42 . V_57 ) ;
if ( ! V_19 )
return - V_51 ;
F_37 ( V_1 -> V_36 , V_19 ) ;
return 0 ;
}
static int F_41 ( struct V_2 * V_2 ,
struct V_58 * V_59 )
{
struct V_1 * V_1 = F_1 ( V_2 ) ;
unsigned char V_17 = V_59 -> V_60 ;
F_42 ( V_1 , V_17 ) = V_59 ;
return 0 ;
}
static int F_43 ( struct V_2 * V_2 ,
struct V_39 * V_40 )
{
struct V_1 * V_1 = F_1 ( V_2 ) ;
struct V_5 * V_6 ;
unsigned char V_17 = V_40 -> V_59 -> V_60 ;
V_6 = F_13 ( V_1 , V_17 ) ;
V_40 -> V_42 . V_61 = V_6 ? V_6 -> V_62 -> V_63 : 0 ;
return 0 ;
}
static int F_44 ( struct V_2 * V_2 ,
struct V_39 * V_40 )
{
struct V_1 * V_1 = F_1 ( V_2 ) ;
struct V_5 * V_6 ;
unsigned char V_17 = V_40 -> V_59 -> V_60 ;
F_45 (port, &team->port_list, list) {
if ( V_40 -> V_42 . V_61 == V_6 -> V_62 -> V_63 &&
F_46 ( V_6 ) ) {
F_37 ( F_13 ( V_1 , V_17 ) ,
V_6 ) ;
return 0 ;
}
}
return - V_64 ;
}
static int F_47 ( struct V_2 * V_2 ,
struct V_58 * V_59 )
{
struct V_1 * V_1 = F_1 ( V_2 ) ;
unsigned char V_17 = V_59 -> V_60 ;
V_1 -> V_12 -> V_65 . V_59 [ V_17 ] . V_14 = V_59 ;
return 0 ;
}
static int F_48 ( struct V_2 * V_2 , struct V_39 * V_40 )
{
struct V_1 * V_1 = F_1 ( V_2 ) ;
unsigned char V_17 = V_40 -> V_59 -> V_60 ;
V_40 -> V_42 . V_43 . V_44 = & V_1 -> V_12 -> V_65 . V_59 [ V_17 ] . V_65 ;
V_40 -> V_42 . V_43 . V_37 = sizeof( struct V_32 ) ;
return 0 ;
}
static int F_49 ( struct V_2 * V_2 ,
struct V_58 * V_59 )
{
struct V_5 * V_6 = V_59 -> V_6 ;
struct V_4 * V_4 = F_2 ( V_6 ) ;
V_4 -> V_66 . V_14 = V_59 ;
return 0 ;
}
static int F_50 ( struct V_2 * V_2 , struct V_39 * V_40 )
{
struct V_5 * V_6 = V_40 -> V_59 -> V_6 ;
struct V_4 * V_4 = F_2 ( V_6 ) ;
V_40 -> V_42 . V_43 . V_44 = & V_4 -> V_66 . V_65 ;
V_40 -> V_42 . V_43 . V_37 = sizeof( struct V_32 ) ;
return 0 ;
}
static void F_51 ( struct V_67 * V_68 )
{
memcpy ( & V_68 -> V_69 , & V_68 -> V_65 , sizeof( struct V_32 ) ) ;
memset ( & V_68 -> V_65 , 0 , sizeof( struct V_32 ) ) ;
}
static bool F_52 ( struct V_67 * V_68 ,
struct V_2 * V_2 )
{
if ( memcmp ( & V_68 -> V_69 , & V_68 -> V_65 ,
sizeof( struct V_32 ) ) ) {
F_6 ( V_68 -> V_14 ) ;
return true ;
}
return false ;
}
static void F_53 ( struct V_32 * V_70 ,
struct V_32 * V_71 ,
struct V_72 * V_35 )
{
unsigned int V_73 ;
struct V_32 V_74 ;
do {
V_73 = F_54 ( V_35 ) ;
V_74 . V_29 = V_71 -> V_29 ;
} while ( F_55 ( V_35 , V_73 ) );
V_70 -> V_29 += V_74 . V_29 ;
}
static void F_56 ( struct V_75 * V_76 )
{
struct V_2 * V_2 ;
struct V_1 * V_1 ;
struct V_77 * V_77 ;
struct V_30 * V_31 ;
struct V_32 * V_65 ;
struct V_67 * V_68 ;
struct V_5 * V_6 ;
bool V_7 = false ;
int V_8 ;
int V_78 ;
V_77 = F_57 ( V_76 , struct V_77 ,
V_65 . V_79 . V_76 ) ;
V_2 = V_77 -> V_2 ;
V_1 = F_1 ( V_2 ) ;
if ( ! F_58 ( & V_2 -> V_56 ) ) {
F_59 ( & V_77 -> V_65 . V_79 , 0 ) ;
return;
}
for ( V_78 = 0 ; V_78 < V_9 ; V_78 ++ ) {
V_68 = & V_1 -> V_12 -> V_65 . V_59 [ V_78 ] ;
F_51 ( V_68 ) ;
F_60 (i) {
V_31 = F_61 ( V_1 -> V_31 , V_8 ) ;
V_65 = & V_31 -> V_34 [ V_78 ] ;
F_53 ( & V_68 -> V_65 , V_65 ,
& V_31 -> V_35 ) ;
}
V_7 |= F_52 ( V_68 , V_2 ) ;
}
F_45 (port, &team->port_list, list) {
struct V_4 * V_4 = F_2 ( V_6 ) ;
V_68 = & V_4 -> V_66 ;
F_51 ( V_68 ) ;
F_60 (i) {
V_31 = F_61 ( V_1 -> V_31 , V_8 ) ;
V_65 = F_61 ( V_4 -> V_31 , V_8 ) ;
F_53 ( & V_68 -> V_65 , V_65 ,
& V_31 -> V_35 ) ;
}
V_7 |= F_52 ( V_68 , V_2 ) ;
}
if ( V_7 )
F_7 ( V_2 ) ;
F_59 ( & V_77 -> V_65 . V_79 ,
( V_77 -> V_65 . V_80 * V_81 ) / 10 ) ;
F_62 ( & V_2 -> V_56 ) ;
}
static int F_63 ( struct V_2 * V_2 ,
struct V_39 * V_40 )
{
struct V_1 * V_1 = F_1 ( V_2 ) ;
V_40 -> V_42 . V_61 = V_1 -> V_12 -> V_65 . V_80 ;
return 0 ;
}
static int F_64 ( struct V_2 * V_2 ,
struct V_39 * V_40 )
{
struct V_1 * V_1 = F_1 ( V_2 ) ;
unsigned int V_82 ;
V_82 = V_40 -> V_42 . V_61 ;
if ( V_1 -> V_12 -> V_65 . V_80 == V_82 )
return 0 ;
V_1 -> V_12 -> V_65 . V_80 = V_82 ;
if ( V_82 )
F_59 ( & V_1 -> V_12 -> V_65 . V_79 , 0 ) ;
else
F_65 ( & V_1 -> V_12 -> V_65 . V_79 ) ;
return 0 ;
}
static int F_66 ( struct V_2 * V_2 )
{
struct V_1 * V_1 = F_1 ( V_2 ) ;
T_1 * V_19 ;
int V_8 , V_55 ;
V_19 = F_15 ( L_1 ) ;
F_39 ( ! V_19 ) ;
F_37 ( V_1 -> V_36 , V_19 ) ;
V_1 -> V_12 = F_67 ( sizeof( * V_1 -> V_12 ) , V_52 ) ;
if ( ! V_1 -> V_12 )
return - V_53 ;
V_1 -> V_12 -> V_2 = V_2 ;
V_1 -> V_31 = F_68 ( struct V_30 ) ;
if ( ! V_1 -> V_31 ) {
V_55 = - V_53 ;
goto V_83;
}
F_60 (i) {
struct V_30 * V_84 ;
V_84 = F_61 ( V_1 -> V_31 , V_8 ) ;
F_69 ( & V_84 -> V_35 ) ;
}
F_70 ( & V_1 -> V_12 -> V_65 . V_79 , F_56 ) ;
V_55 = F_71 ( V_2 , V_85 , F_72 ( V_85 ) ) ;
if ( V_55 )
goto V_86;
return 0 ;
V_86:
F_73 ( V_1 -> V_31 ) ;
V_83:
F_30 ( V_1 -> V_12 ) ;
return V_55 ;
}
static void F_74 ( struct V_2 * V_2 )
{
struct V_1 * V_1 = F_1 ( V_2 ) ;
F_75 ( V_2 , V_85 ,
F_72 ( V_85 ) ) ;
F_76 ( & V_1 -> V_12 -> V_65 . V_79 ) ;
F_73 ( V_1 -> V_31 ) ;
F_30 ( V_1 -> V_12 ) ;
}
static int F_77 ( struct V_2 * V_2 , struct V_5 * V_6 )
{
struct V_4 * V_4 = F_2 ( V_6 ) ;
V_4 -> V_31 = F_68 ( struct V_32 ) ;
if ( ! V_4 -> V_31 )
return - V_53 ;
return 0 ;
}
static void F_78 ( struct V_2 * V_2 , struct V_5 * V_6 )
{
struct V_4 * V_4 = F_2 ( V_6 ) ;
F_73 ( V_4 -> V_31 ) ;
}
static void F_79 ( struct V_2 * V_2 , struct V_5 * V_6 )
{
F_3 ( V_2 , V_6 ) ;
}
static int T_4 F_80 ( void )
{
return F_81 ( & V_87 ) ;
}
static void T_5 F_82 ( void )
{
F_83 ( & V_87 ) ;
}
