static T_1 F_1 ( struct V_1 * V_1 , struct V_2 * V_3 ,
struct V_4 * V_5 )
{
if ( F_2 ( V_5 -> V_6 == F_3 ( V_7 ) ) ) {
const unsigned char * V_8 = F_4 ( V_5 ) -> V_9 ;
if ( F_5 ( V_8 ) && V_8 [ 5 ] == 0x02 )
return V_10 ;
}
return V_11 ;
}
static struct V_12 * F_6 ( struct V_1 * V_1 )
{
return (struct V_12 * ) & V_1 -> V_13 ;
}
static struct V_14 * F_7 ( struct V_2 * V_3 )
{
return (struct V_14 * ) & V_3 -> V_13 ;
}
static void F_8 ( struct V_1 * V_1 ,
struct V_2 * V_3 )
{
struct V_12 * V_12 = F_6 ( V_1 ) ;
bool V_15 = false ;
int V_16 ;
for ( V_16 = 0 ; V_16 < V_17 ; V_16 ++ ) {
struct V_18 * V_19 ;
V_19 = & V_12 -> V_20 -> V_21 [ V_16 ] ;
if ( F_9 ( V_19 -> V_3 ) == V_3 ) {
F_10 ( V_19 -> V_3 , NULL ) ;
F_11 ( V_19 -> V_22 ) ;
V_15 = true ;
}
}
if ( V_15 )
F_12 ( V_1 ) ;
}
static struct V_2 * F_13 ( struct V_1 * V_1 ,
struct V_12 * V_12 ,
struct V_4 * V_5 ,
unsigned char V_23 )
{
int V_24 = F_14 ( V_1 , V_23 ) ;
return F_15 ( V_1 , V_24 ) ;
}
static struct V_2 * F_16 ( struct V_1 * V_1 ,
struct V_12 * V_12 ,
struct V_4 * V_5 ,
unsigned char V_23 )
{
return F_17 ( F_18 ( V_12 , V_23 ) ) ;
}
static char * F_19 ( T_2 * V_25 )
{
int V_16 ;
for ( V_16 = 0 ; V_16 < V_26 ; V_16 ++ ) {
const struct V_27 * V_28 ;
V_28 = & V_29 [ V_16 ] ;
if ( V_28 -> V_25 == V_25 )
return V_28 -> V_30 ;
}
return NULL ;
}
static T_2 * F_20 ( const char * V_30 )
{
int V_16 ;
for ( V_16 = 0 ; V_16 < V_26 ; V_16 ++ ) {
const struct V_27 * V_28 ;
V_28 = & V_29 [ V_16 ] ;
if ( ! strcmp ( V_28 -> V_30 , V_30 ) )
return V_28 -> V_25 ;
}
return NULL ;
}
static unsigned int F_21 ( struct V_12 * V_12 ,
struct V_4 * V_5 )
{
struct V_31 * V_32 ;
T_3 V_33 ;
unsigned char * V_34 ;
V_32 = F_17 ( V_12 -> V_32 ) ;
if ( F_2 ( ! V_32 ) )
return 0 ;
V_33 = F_22 ( V_32 , V_5 ) ;
V_34 = ( char * ) & V_33 ;
return V_34 [ 0 ] ^ V_34 [ 1 ] ^ V_34 [ 2 ] ^ V_34 [ 3 ] ;
}
static void F_23 ( unsigned int V_35 , struct V_12 * V_12 ,
struct V_14 * V_14 ,
unsigned char V_23 )
{
struct V_36 * V_37 ;
struct V_38 * V_39 ;
struct V_38 * V_40 ;
V_37 = F_24 ( V_12 -> V_37 ) ;
V_39 = F_24 ( V_14 -> V_37 ) ;
V_40 = & V_37 -> V_40 [ V_23 ] ;
F_25 ( & V_37 -> V_41 ) ;
V_39 -> V_35 += V_35 ;
V_40 -> V_35 += V_35 ;
F_26 ( & V_37 -> V_41 ) ;
}
static bool F_27 ( struct V_1 * V_1 , struct V_4 * V_5 )
{
struct V_12 * V_12 = F_6 ( V_1 ) ;
T_2 * V_42 ;
struct V_2 * V_3 ;
unsigned char V_23 ;
unsigned int V_35 = V_5 -> V_43 ;
V_23 = F_21 ( V_12 , V_5 ) ;
V_42 = F_17 ( V_12 -> V_42 ) ;
V_3 = V_42 ( V_1 , V_12 , V_5 , V_23 ) ;
if ( F_2 ( ! V_3 ) )
goto V_44;
if ( F_28 ( V_1 , V_3 , V_5 ) )
return false ;
F_23 ( V_35 , V_12 , F_7 ( V_3 ) , V_23 ) ;
return true ;
V_44:
F_29 ( V_5 ) ;
return false ;
}
static int F_30 ( struct V_1 * V_1 , struct V_45 * V_46 )
{
struct V_12 * V_12 = F_6 ( V_1 ) ;
if ( ! V_12 -> V_20 -> V_47 ) {
V_46 -> V_48 . V_49 . V_43 = 0 ;
V_46 -> V_48 . V_49 . V_50 = NULL ;
return 0 ;
}
V_46 -> V_48 . V_49 . V_43 = V_12 -> V_20 -> V_47 -> V_43 *
sizeof( struct V_51 ) ;
V_46 -> V_48 . V_49 . V_50 = V_12 -> V_20 -> V_47 -> V_52 ;
return 0 ;
}
static int F_31 ( struct V_53 * * V_54 , T_4 V_55 ,
const void * V_48 )
{
struct V_53 * V_56 ;
struct V_51 * V_52 = (struct V_51 * ) V_48 ;
if ( V_55 % sizeof( struct V_51 ) )
return - V_57 ;
V_56 = F_32 ( sizeof( * V_56 ) , V_58 ) ;
if ( ! V_56 )
return - V_59 ;
V_56 -> V_52 = F_33 ( V_52 , V_55 , V_58 ) ;
if ( ! V_56 -> V_52 ) {
F_34 ( V_56 ) ;
return - V_59 ;
}
V_56 -> V_43 = V_55 / sizeof( struct V_51 ) ;
* V_54 = V_56 ;
return 0 ;
}
static void F_35 ( struct V_53 * V_56 )
{
F_34 ( V_56 -> V_52 ) ;
F_34 ( V_56 ) ;
}
static int F_36 ( struct V_1 * V_1 , struct V_45 * V_46 )
{
struct V_12 * V_12 = F_6 ( V_1 ) ;
struct V_31 * V_32 = NULL ;
struct V_31 * V_60 = NULL ;
struct V_53 * V_56 = NULL ;
int V_61 ;
if ( V_46 -> V_48 . V_49 . V_43 ) {
V_61 = F_31 ( & V_56 , V_46 -> V_48 . V_49 . V_43 ,
V_46 -> V_48 . V_49 . V_50 ) ;
if ( V_61 )
return V_61 ;
V_61 = F_37 ( & V_32 , V_56 ) ;
if ( V_61 ) {
F_35 ( V_56 ) ;
return V_61 ;
}
}
if ( V_12 -> V_20 -> V_47 ) {
F_35 ( V_12 -> V_20 -> V_47 ) ;
V_60 = F_38 ( V_12 -> V_32 ,
F_39 ( & V_1 -> V_62 ) ) ;
}
F_40 ( V_12 -> V_32 , V_32 ) ;
V_12 -> V_20 -> V_47 = V_56 ;
if ( V_60 ) {
F_41 () ;
F_42 ( V_60 ) ;
}
return 0 ;
}
static int F_43 ( struct V_1 * V_1 , struct V_45 * V_46 )
{
struct V_12 * V_12 = F_6 ( V_1 ) ;
T_2 * V_25 ;
char * V_30 ;
V_25 = F_38 ( V_12 -> V_42 ,
F_39 ( & V_1 -> V_62 ) ) ;
V_30 = F_19 ( V_25 ) ;
F_44 ( ! V_30 ) ;
V_46 -> V_48 . V_63 = V_30 ;
return 0 ;
}
static int F_45 ( struct V_1 * V_1 , struct V_45 * V_46 )
{
struct V_12 * V_12 = F_6 ( V_1 ) ;
T_2 * V_25 ;
V_25 = F_20 ( V_46 -> V_48 . V_63 ) ;
if ( ! V_25 )
return - V_57 ;
F_40 ( V_12 -> V_42 , V_25 ) ;
return 0 ;
}
static int F_46 ( struct V_1 * V_1 ,
struct V_64 * V_65 )
{
struct V_12 * V_12 = F_6 ( V_1 ) ;
unsigned char V_23 = V_65 -> V_66 ;
F_47 ( V_12 , V_23 ) = V_65 ;
return 0 ;
}
static int F_48 ( struct V_1 * V_1 ,
struct V_45 * V_46 )
{
struct V_12 * V_12 = F_6 ( V_1 ) ;
struct V_2 * V_3 ;
unsigned char V_23 = V_46 -> V_65 -> V_66 ;
V_3 = F_18 ( V_12 , V_23 ) ;
V_46 -> V_48 . V_67 = V_3 ? V_3 -> V_68 -> V_69 : 0 ;
return 0 ;
}
static int F_49 ( struct V_1 * V_1 ,
struct V_45 * V_46 )
{
struct V_12 * V_12 = F_6 ( V_1 ) ;
struct V_2 * V_3 ;
unsigned char V_23 = V_46 -> V_65 -> V_66 ;
F_50 (port, &team->port_list, list) {
if ( V_46 -> V_48 . V_67 == V_3 -> V_68 -> V_69 &&
F_51 ( V_3 ) ) {
F_40 ( F_18 ( V_12 , V_23 ) ,
V_3 ) ;
return 0 ;
}
}
return - V_70 ;
}
static int F_52 ( struct V_1 * V_1 ,
struct V_64 * V_65 )
{
struct V_12 * V_12 = F_6 ( V_1 ) ;
unsigned char V_23 = V_65 -> V_66 ;
V_12 -> V_20 -> V_71 . V_65 [ V_23 ] . V_22 = V_65 ;
return 0 ;
}
static int F_53 ( struct V_1 * V_1 , struct V_45 * V_46 )
{
struct V_12 * V_12 = F_6 ( V_1 ) ;
unsigned char V_23 = V_46 -> V_65 -> V_66 ;
V_46 -> V_48 . V_49 . V_50 = & V_12 -> V_20 -> V_71 . V_65 [ V_23 ] . V_71 ;
V_46 -> V_48 . V_49 . V_43 = sizeof( struct V_38 ) ;
return 0 ;
}
static int F_54 ( struct V_1 * V_1 ,
struct V_64 * V_65 )
{
struct V_2 * V_3 = V_65 -> V_3 ;
struct V_14 * V_14 = F_7 ( V_3 ) ;
V_14 -> V_72 . V_22 = V_65 ;
return 0 ;
}
static int F_55 ( struct V_1 * V_1 , struct V_45 * V_46 )
{
struct V_2 * V_3 = V_46 -> V_65 -> V_3 ;
struct V_14 * V_14 = F_7 ( V_3 ) ;
V_46 -> V_48 . V_49 . V_50 = & V_14 -> V_72 . V_71 ;
V_46 -> V_48 . V_49 . V_43 = sizeof( struct V_38 ) ;
return 0 ;
}
static void F_56 ( struct V_73 * V_74 )
{
memcpy ( & V_74 -> V_75 , & V_74 -> V_71 , sizeof( struct V_38 ) ) ;
memset ( & V_74 -> V_71 , 0 , sizeof( struct V_38 ) ) ;
}
static bool F_57 ( struct V_73 * V_74 ,
struct V_1 * V_1 )
{
if ( memcmp ( & V_74 -> V_75 , & V_74 -> V_71 ,
sizeof( struct V_38 ) ) ) {
F_11 ( V_74 -> V_22 ) ;
return true ;
}
return false ;
}
static void F_58 ( struct V_38 * V_76 ,
struct V_38 * V_77 ,
struct V_78 * V_41 )
{
unsigned int V_79 ;
struct V_38 V_80 ;
do {
V_79 = F_59 ( V_41 ) ;
V_80 . V_35 = V_77 -> V_35 ;
} while ( F_60 ( V_41 , V_79 ) );
V_76 -> V_35 += V_80 . V_35 ;
}
static void F_61 ( struct V_81 * V_82 )
{
struct V_1 * V_1 ;
struct V_12 * V_12 ;
struct V_83 * V_83 ;
struct V_36 * V_37 ;
struct V_38 * V_71 ;
struct V_73 * V_74 ;
struct V_2 * V_3 ;
bool V_15 = false ;
int V_16 ;
int V_84 ;
V_83 = F_62 ( V_82 , struct V_83 ,
V_71 . V_85 . V_82 ) ;
V_1 = V_83 -> V_1 ;
V_12 = F_6 ( V_1 ) ;
if ( ! F_63 ( & V_1 -> V_62 ) ) {
F_64 ( & V_83 -> V_71 . V_85 , 0 ) ;
return;
}
for ( V_84 = 0 ; V_84 < V_17 ; V_84 ++ ) {
V_74 = & V_12 -> V_20 -> V_71 . V_65 [ V_84 ] ;
F_56 ( V_74 ) ;
F_65 (i) {
V_37 = F_66 ( V_12 -> V_37 , V_16 ) ;
V_71 = & V_37 -> V_40 [ V_84 ] ;
F_58 ( & V_74 -> V_71 , V_71 ,
& V_37 -> V_41 ) ;
}
V_15 |= F_57 ( V_74 , V_1 ) ;
}
F_50 (port, &team->port_list, list) {
struct V_14 * V_14 = F_7 ( V_3 ) ;
V_74 = & V_14 -> V_72 ;
F_56 ( V_74 ) ;
F_65 (i) {
V_37 = F_66 ( V_12 -> V_37 , V_16 ) ;
V_71 = F_66 ( V_14 -> V_37 , V_16 ) ;
F_58 ( & V_74 -> V_71 , V_71 ,
& V_37 -> V_41 ) ;
}
V_15 |= F_57 ( V_74 , V_1 ) ;
}
if ( V_15 )
F_12 ( V_1 ) ;
F_64 ( & V_83 -> V_71 . V_85 ,
( V_83 -> V_71 . V_86 * V_87 ) / 10 ) ;
F_67 ( & V_1 -> V_62 ) ;
}
static int F_68 ( struct V_1 * V_1 ,
struct V_45 * V_46 )
{
struct V_12 * V_12 = F_6 ( V_1 ) ;
V_46 -> V_48 . V_67 = V_12 -> V_20 -> V_71 . V_86 ;
return 0 ;
}
static int F_69 ( struct V_1 * V_1 ,
struct V_45 * V_46 )
{
struct V_12 * V_12 = F_6 ( V_1 ) ;
unsigned int V_88 ;
V_88 = V_46 -> V_48 . V_67 ;
if ( V_12 -> V_20 -> V_71 . V_86 == V_88 )
return 0 ;
V_12 -> V_20 -> V_71 . V_86 = V_88 ;
if ( V_88 )
F_64 ( & V_12 -> V_20 -> V_71 . V_85 , 0 ) ;
else
F_70 ( & V_12 -> V_20 -> V_71 . V_85 ) ;
return 0 ;
}
static int F_71 ( struct V_1 * V_1 )
{
struct V_12 * V_12 = F_6 ( V_1 ) ;
T_2 * V_25 ;
int V_16 , V_61 ;
V_25 = F_20 ( L_1 ) ;
F_44 ( ! V_25 ) ;
F_40 ( V_12 -> V_42 , V_25 ) ;
V_12 -> V_20 = F_72 ( sizeof( * V_12 -> V_20 ) , V_58 ) ;
if ( ! V_12 -> V_20 )
return - V_59 ;
V_12 -> V_20 -> V_1 = V_1 ;
V_12 -> V_37 = F_73 ( struct V_36 ) ;
if ( ! V_12 -> V_37 ) {
V_61 = - V_59 ;
goto V_89;
}
F_65 (i) {
struct V_36 * V_90 ;
V_90 = F_66 ( V_12 -> V_37 , V_16 ) ;
F_74 ( & V_90 -> V_41 ) ;
}
F_75 ( & V_12 -> V_20 -> V_71 . V_85 , F_61 ) ;
V_61 = F_76 ( V_1 , V_91 , F_77 ( V_91 ) ) ;
if ( V_61 )
goto V_92;
return 0 ;
V_92:
F_78 ( V_12 -> V_37 ) ;
V_89:
F_34 ( V_12 -> V_20 ) ;
return V_61 ;
}
static void F_79 ( struct V_1 * V_1 )
{
struct V_12 * V_12 = F_6 ( V_1 ) ;
F_80 ( V_1 , V_91 ,
F_77 ( V_91 ) ) ;
F_81 ( & V_12 -> V_20 -> V_71 . V_85 ) ;
F_78 ( V_12 -> V_37 ) ;
F_34 ( V_12 -> V_20 ) ;
}
static int F_82 ( struct V_1 * V_1 , struct V_2 * V_3 )
{
struct V_14 * V_14 = F_7 ( V_3 ) ;
V_14 -> V_37 = F_73 ( struct V_38 ) ;
if ( ! V_14 -> V_37 )
return - V_59 ;
return 0 ;
}
static void F_83 ( struct V_1 * V_1 , struct V_2 * V_3 )
{
struct V_14 * V_14 = F_7 ( V_3 ) ;
F_78 ( V_14 -> V_37 ) ;
}
static void F_84 ( struct V_1 * V_1 , struct V_2 * V_3 )
{
F_8 ( V_1 , V_3 ) ;
}
static int T_5 F_85 ( void )
{
return F_86 ( & V_93 ) ;
}
static void T_6 F_87 ( void )
{
F_88 ( & V_93 ) ;
}
