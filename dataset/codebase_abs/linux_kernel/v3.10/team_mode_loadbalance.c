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
int V_18 ;
V_18 = V_17 % V_2 -> V_19 ;
return F_9 ( V_2 , V_18 ) ;
}
static struct V_5 * F_10 ( struct V_2 * V_2 ,
struct V_1 * V_1 ,
struct V_15 * V_16 ,
unsigned char V_17 )
{
return F_11 ( F_12 ( V_1 , V_17 ) ) ;
}
static char * F_13 ( T_1 * V_20 )
{
int V_8 ;
for ( V_8 = 0 ; V_8 < V_21 ; V_8 ++ ) {
const struct V_22 * V_23 ;
V_23 = & V_24 [ V_8 ] ;
if ( V_23 -> V_20 == V_20 )
return V_23 -> V_25 ;
}
return NULL ;
}
static T_1 * F_14 ( const char * V_25 )
{
int V_8 ;
for ( V_8 = 0 ; V_8 < V_21 ; V_8 ++ ) {
const struct V_22 * V_23 ;
V_23 = & V_24 [ V_8 ] ;
if ( ! strcmp ( V_23 -> V_25 , V_25 ) )
return V_23 -> V_20 ;
}
return NULL ;
}
static unsigned int F_15 ( struct V_1 * V_1 ,
struct V_15 * V_16 )
{
struct V_26 * V_27 ;
T_2 V_28 ;
unsigned char * V_29 ;
V_27 = F_11 ( V_1 -> V_27 ) ;
if ( F_16 ( ! V_27 ) )
return 0 ;
V_28 = F_17 ( V_27 , V_16 ) ;
V_29 = ( char * ) & V_28 ;
return V_29 [ 0 ] ^ V_29 [ 1 ] ^ V_29 [ 2 ] ^ V_29 [ 3 ] ;
}
static void F_18 ( unsigned int V_30 , struct V_1 * V_1 ,
struct V_4 * V_4 ,
unsigned char V_17 )
{
struct V_31 * V_32 ;
struct V_33 * V_34 ;
struct V_33 * V_35 ;
V_32 = F_19 ( V_1 -> V_32 ) ;
V_34 = F_19 ( V_4 -> V_32 ) ;
V_35 = & V_32 -> V_35 [ V_17 ] ;
F_20 ( & V_32 -> V_36 ) ;
V_34 -> V_30 += V_30 ;
V_35 -> V_30 += V_30 ;
F_21 ( & V_32 -> V_36 ) ;
}
static bool F_22 ( struct V_2 * V_2 , struct V_15 * V_16 )
{
struct V_1 * V_1 = F_1 ( V_2 ) ;
T_1 * V_37 ;
struct V_5 * V_6 ;
unsigned char V_17 ;
unsigned int V_30 = V_16 -> V_38 ;
V_17 = F_15 ( V_1 , V_16 ) ;
V_37 = F_11 ( V_1 -> V_37 ) ;
V_6 = V_37 ( V_2 , V_1 , V_16 , V_17 ) ;
if ( F_16 ( ! V_6 ) )
goto V_39;
if ( F_23 ( V_2 , V_6 , V_16 ) )
return false ;
F_18 ( V_30 , V_1 , F_2 ( V_6 ) , V_17 ) ;
return true ;
V_39:
F_24 ( V_16 ) ;
return false ;
}
static int F_25 ( struct V_2 * V_2 , struct V_40 * V_41 )
{
struct V_1 * V_1 = F_1 ( V_2 ) ;
if ( ! V_1 -> V_12 -> V_42 ) {
V_41 -> V_43 . V_44 . V_38 = 0 ;
V_41 -> V_43 . V_44 . V_45 = NULL ;
return 0 ;
}
V_41 -> V_43 . V_44 . V_38 = V_1 -> V_12 -> V_42 -> V_38 *
sizeof( struct V_46 ) ;
V_41 -> V_43 . V_44 . V_45 = V_1 -> V_12 -> V_42 -> V_47 ;
return 0 ;
}
static int F_26 ( struct V_48 * * V_49 , T_3 V_50 ,
const void * V_43 )
{
struct V_48 * V_51 ;
struct V_46 * V_47 = (struct V_46 * ) V_43 ;
if ( V_50 % sizeof( struct V_46 ) )
return - V_52 ;
V_51 = F_27 ( sizeof( struct V_48 ) , V_53 ) ;
if ( ! V_51 )
return - V_54 ;
V_51 -> V_47 = F_28 ( V_47 , V_50 , V_53 ) ;
if ( ! V_51 -> V_47 ) {
F_29 ( V_51 ) ;
return - V_54 ;
}
V_51 -> V_38 = V_50 / sizeof( struct V_46 ) ;
* V_49 = V_51 ;
return 0 ;
}
static void F_30 ( struct V_48 * V_51 )
{
F_29 ( V_51 -> V_47 ) ;
F_29 ( V_51 ) ;
}
static int F_31 ( struct V_2 * V_2 , struct V_40 * V_41 )
{
struct V_1 * V_1 = F_1 ( V_2 ) ;
struct V_26 * V_27 = NULL ;
struct V_26 * V_55 ;
struct V_48 * V_51 = NULL ;
int V_56 ;
if ( V_41 -> V_43 . V_44 . V_38 ) {
V_56 = F_26 ( & V_51 , V_41 -> V_43 . V_44 . V_38 ,
V_41 -> V_43 . V_44 . V_45 ) ;
if ( V_56 )
return V_56 ;
V_56 = F_32 ( & V_27 , V_51 ) ;
if ( V_56 ) {
F_30 ( V_51 ) ;
return V_56 ;
}
}
if ( V_1 -> V_12 -> V_42 ) {
F_30 ( V_1 -> V_12 -> V_42 ) ;
V_55 = F_33 ( V_1 -> V_27 ,
F_34 ( & V_2 -> V_57 ) ) ;
F_35 ( V_55 ) ;
}
F_36 ( V_1 -> V_27 , V_27 ) ;
V_1 -> V_12 -> V_42 = V_51 ;
return 0 ;
}
static int F_37 ( struct V_2 * V_2 , struct V_40 * V_41 )
{
struct V_1 * V_1 = F_1 ( V_2 ) ;
T_1 * V_20 ;
char * V_25 ;
V_20 = F_33 ( V_1 -> V_37 ,
F_34 ( & V_2 -> V_57 ) ) ;
V_25 = F_13 ( V_20 ) ;
F_38 ( ! V_25 ) ;
V_41 -> V_43 . V_58 = V_25 ;
return 0 ;
}
static int F_39 ( struct V_2 * V_2 , struct V_40 * V_41 )
{
struct V_1 * V_1 = F_1 ( V_2 ) ;
T_1 * V_20 ;
V_20 = F_14 ( V_41 -> V_43 . V_58 ) ;
if ( ! V_20 )
return - V_52 ;
F_36 ( V_1 -> V_37 , V_20 ) ;
return 0 ;
}
static int F_40 ( struct V_2 * V_2 ,
struct V_59 * V_60 )
{
struct V_1 * V_1 = F_1 ( V_2 ) ;
unsigned char V_17 = V_60 -> V_61 ;
F_41 ( V_1 , V_17 ) = V_60 ;
return 0 ;
}
static int F_42 ( struct V_2 * V_2 ,
struct V_40 * V_41 )
{
struct V_1 * V_1 = F_1 ( V_2 ) ;
struct V_5 * V_6 ;
unsigned char V_17 = V_41 -> V_60 -> V_61 ;
V_6 = F_12 ( V_1 , V_17 ) ;
V_41 -> V_43 . V_62 = V_6 ? V_6 -> V_63 -> V_64 : 0 ;
return 0 ;
}
static int F_43 ( struct V_2 * V_2 ,
struct V_40 * V_41 )
{
struct V_1 * V_1 = F_1 ( V_2 ) ;
struct V_5 * V_6 ;
unsigned char V_17 = V_41 -> V_60 -> V_61 ;
F_44 (port, &team->port_list, list) {
if ( V_41 -> V_43 . V_62 == V_6 -> V_63 -> V_64 &&
F_45 ( V_6 ) ) {
F_36 ( F_12 ( V_1 , V_17 ) ,
V_6 ) ;
return 0 ;
}
}
return - V_65 ;
}
static int F_46 ( struct V_2 * V_2 ,
struct V_59 * V_60 )
{
struct V_1 * V_1 = F_1 ( V_2 ) ;
unsigned char V_17 = V_60 -> V_61 ;
V_1 -> V_12 -> V_66 . V_60 [ V_17 ] . V_14 = V_60 ;
return 0 ;
}
static int F_47 ( struct V_2 * V_2 , struct V_40 * V_41 )
{
struct V_1 * V_1 = F_1 ( V_2 ) ;
unsigned char V_17 = V_41 -> V_60 -> V_61 ;
V_41 -> V_43 . V_44 . V_45 = & V_1 -> V_12 -> V_66 . V_60 [ V_17 ] . V_66 ;
V_41 -> V_43 . V_44 . V_38 = sizeof( struct V_33 ) ;
return 0 ;
}
static int F_48 ( struct V_2 * V_2 ,
struct V_59 * V_60 )
{
struct V_5 * V_6 = V_60 -> V_6 ;
struct V_4 * V_4 = F_2 ( V_6 ) ;
V_4 -> V_67 . V_14 = V_60 ;
return 0 ;
}
static int F_49 ( struct V_2 * V_2 , struct V_40 * V_41 )
{
struct V_5 * V_6 = V_41 -> V_60 -> V_6 ;
struct V_4 * V_4 = F_2 ( V_6 ) ;
V_41 -> V_43 . V_44 . V_45 = & V_4 -> V_67 . V_66 ;
V_41 -> V_43 . V_44 . V_38 = sizeof( struct V_33 ) ;
return 0 ;
}
static void F_50 ( struct V_68 * V_69 )
{
memcpy ( & V_69 -> V_70 , & V_69 -> V_66 , sizeof( struct V_33 ) ) ;
memset ( & V_69 -> V_66 , 0 , sizeof( struct V_33 ) ) ;
}
static bool F_51 ( struct V_68 * V_69 ,
struct V_2 * V_2 )
{
if ( memcmp ( & V_69 -> V_70 , & V_69 -> V_66 ,
sizeof( struct V_33 ) ) ) {
F_6 ( V_69 -> V_14 ) ;
return true ;
}
return false ;
}
static void F_52 ( struct V_33 * V_71 ,
struct V_33 * V_72 ,
struct V_73 * V_36 )
{
unsigned int V_74 ;
struct V_33 V_75 ;
do {
V_74 = F_53 ( V_36 ) ;
V_75 . V_30 = V_72 -> V_30 ;
} while ( F_54 ( V_36 , V_74 ) );
V_71 -> V_30 += V_75 . V_30 ;
}
static void F_55 ( struct V_76 * V_77 )
{
struct V_2 * V_2 ;
struct V_1 * V_1 ;
struct V_78 * V_78 ;
struct V_31 * V_32 ;
struct V_33 * V_66 ;
struct V_68 * V_69 ;
struct V_5 * V_6 ;
bool V_7 = false ;
int V_8 ;
int V_79 ;
V_78 = F_56 ( V_77 , struct V_78 ,
V_66 . V_80 . V_77 ) ;
V_2 = V_78 -> V_2 ;
V_1 = F_1 ( V_2 ) ;
if ( ! F_57 ( & V_2 -> V_57 ) ) {
F_58 ( & V_78 -> V_66 . V_80 , 0 ) ;
return;
}
for ( V_79 = 0 ; V_79 < V_9 ; V_79 ++ ) {
V_69 = & V_1 -> V_12 -> V_66 . V_60 [ V_79 ] ;
F_50 ( V_69 ) ;
F_59 (i) {
V_32 = F_60 ( V_1 -> V_32 , V_8 ) ;
V_66 = & V_32 -> V_35 [ V_79 ] ;
F_52 ( & V_69 -> V_66 , V_66 ,
& V_32 -> V_36 ) ;
}
V_7 |= F_51 ( V_69 , V_2 ) ;
}
F_44 (port, &team->port_list, list) {
struct V_4 * V_4 = F_2 ( V_6 ) ;
V_69 = & V_4 -> V_67 ;
F_50 ( V_69 ) ;
F_59 (i) {
V_32 = F_60 ( V_1 -> V_32 , V_8 ) ;
V_66 = F_60 ( V_4 -> V_32 , V_8 ) ;
F_52 ( & V_69 -> V_66 , V_66 ,
& V_32 -> V_36 ) ;
}
V_7 |= F_51 ( V_69 , V_2 ) ;
}
if ( V_7 )
F_7 ( V_2 ) ;
F_58 ( & V_78 -> V_66 . V_80 ,
( V_78 -> V_66 . V_81 * V_82 ) / 10 ) ;
F_61 ( & V_2 -> V_57 ) ;
}
static int F_62 ( struct V_2 * V_2 ,
struct V_40 * V_41 )
{
struct V_1 * V_1 = F_1 ( V_2 ) ;
V_41 -> V_43 . V_62 = V_1 -> V_12 -> V_66 . V_81 ;
return 0 ;
}
static int F_63 ( struct V_2 * V_2 ,
struct V_40 * V_41 )
{
struct V_1 * V_1 = F_1 ( V_2 ) ;
unsigned int V_83 ;
V_83 = V_41 -> V_43 . V_62 ;
if ( V_1 -> V_12 -> V_66 . V_81 == V_83 )
return 0 ;
V_1 -> V_12 -> V_66 . V_81 = V_83 ;
if ( V_83 )
F_58 ( & V_1 -> V_12 -> V_66 . V_80 , 0 ) ;
else
F_64 ( & V_1 -> V_12 -> V_66 . V_80 ) ;
return 0 ;
}
static int F_65 ( struct V_2 * V_2 )
{
struct V_1 * V_1 = F_1 ( V_2 ) ;
T_1 * V_20 ;
int V_56 ;
V_20 = F_14 ( L_1 ) ;
F_38 ( ! V_20 ) ;
F_36 ( V_1 -> V_37 , V_20 ) ;
V_1 -> V_12 = F_66 ( sizeof( * V_1 -> V_12 ) , V_53 ) ;
if ( ! V_1 -> V_12 )
return - V_54 ;
V_1 -> V_12 -> V_2 = V_2 ;
V_1 -> V_32 = F_67 ( struct V_31 ) ;
if ( ! V_1 -> V_32 ) {
V_56 = - V_54 ;
goto V_84;
}
F_68 ( & V_1 -> V_12 -> V_66 . V_80 , F_55 ) ;
V_56 = F_69 ( V_2 , V_85 , F_70 ( V_85 ) ) ;
if ( V_56 )
goto V_86;
return 0 ;
V_86:
F_71 ( V_1 -> V_32 ) ;
V_84:
F_29 ( V_1 -> V_12 ) ;
return V_56 ;
}
static void F_72 ( struct V_2 * V_2 )
{
struct V_1 * V_1 = F_1 ( V_2 ) ;
F_73 ( V_2 , V_85 ,
F_70 ( V_85 ) ) ;
F_74 ( & V_1 -> V_12 -> V_66 . V_80 ) ;
F_71 ( V_1 -> V_32 ) ;
F_29 ( V_1 -> V_12 ) ;
}
static int F_75 ( struct V_2 * V_2 , struct V_5 * V_6 )
{
struct V_4 * V_4 = F_2 ( V_6 ) ;
V_4 -> V_32 = F_67 ( struct V_33 ) ;
if ( ! V_4 -> V_32 )
return - V_54 ;
return 0 ;
}
static void F_76 ( struct V_2 * V_2 , struct V_5 * V_6 )
{
struct V_4 * V_4 = F_2 ( V_6 ) ;
F_71 ( V_4 -> V_32 ) ;
}
static void F_77 ( struct V_2 * V_2 , struct V_5 * V_6 )
{
F_3 ( V_2 , V_6 ) ;
}
static int T_4 F_78 ( void )
{
return F_79 ( & V_87 ) ;
}
static void T_5 F_80 ( void )
{
F_81 ( & V_87 ) ;
}
