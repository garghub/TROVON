void F_1 ( void )
{
F_2 ( & V_1 ) ;
}
static char *
F_3 ( void )
{
char * V_2 ;
unsigned long V_3 ;
F_4 ( V_3 ) ;
V_2 = V_4 [ V_5 ++ ] ;
if ( V_5 ==
sizeof( V_4 ) / sizeof( V_4 [ 0 ] ) )
V_5 = 0 ;
F_5 ( V_3 ) ;
return V_2 ;
}
int
F_6 ( const char * V_2 , int V_6 , T_1 * V_7 )
{
* V_7 = 0 ;
return 1 ;
}
void
F_7 ( T_1 V_7 , char * V_2 )
{
#if 0
#endif
snprintf ( V_2 , V_8 , L_1 ,
( V_7 >> 24 ) & 0xff , ( V_7 >> 16 ) & 0xff ,
( V_7 >> 8 ) & 0xff , V_7 & 0xff ) ;
}
int
F_8 ( const char * V_2 , int V_6 , T_1 * V_7 )
{
int V_9 ;
int V_10 ;
int V_11 ;
int V_12 ;
int V_13 = V_6 ;
if ( sscanf ( V_2 , L_2 , & V_9 , & V_10 , & V_11 , & V_12 , & V_13 ) >= 4 &&
V_13 == V_6 &&
( V_9 & ~ 0xff ) == 0 && ( V_10 & ~ 0xff ) == 0 &&
( V_11 & ~ 0xff ) == 0 && ( V_12 & ~ 0xff ) == 0 ) {
* V_7 = ( ( V_9 << 24 ) | ( V_10 << 16 ) | ( V_11 << 8 ) | V_12 ) ;
return 1 ;
}
return 0 ;
}
void
F_9 ( T_1 V_7 , char * V_2 )
{
snprintf ( V_2 , V_8 , L_3 , V_7 ) ;
}
void
F_10 ( T_1 V_7 , char * V_2 )
{
snprintf ( V_2 , V_8 , L_4 , V_7 ) ;
}
int
F_11 ( const char * V_2 , int V_6 , T_1 * V_7 )
{
int V_13 ;
V_13 = V_6 ;
if ( sscanf ( V_2 , L_5 , V_7 , & V_13 ) >= 1 && V_13 == V_6 )
return 1 ;
V_13 = V_6 ;
if ( sscanf ( V_2 , L_6 , V_7 , & V_13 ) >= 1 && V_13 == V_6 )
return 1 ;
V_13 = V_6 ;
if ( sscanf ( V_2 , L_7 , V_7 , & V_13 ) >= 1 && V_13 == V_6 )
return 1 ;
return 0 ;
}
struct V_14 *
F_12 ( int V_15 )
{
int V_16 ;
if ( V_15 >= 0 )
for ( V_16 = 0 ; V_16 < V_17 ; V_16 ++ )
if ( V_15 == V_18 [ V_16 ] . V_19 )
return & V_18 [ V_16 ] ;
return NULL ;
}
struct V_14 *
F_13 ( const char * V_20 )
{
struct V_14 * V_21 ;
int V_16 ;
for ( V_16 = 0 ; V_16 < V_17 ; V_16 ++ ) {
V_21 = & V_18 [ V_16 ] ;
if ( V_21 -> V_19 >= 0 &&
! strncmp ( V_20 , V_21 -> V_22 , strlen ( V_21 -> V_22 ) ) )
return V_21 ;
}
return NULL ;
}
struct V_14 *
F_14 ( const char * V_20 )
{
int V_16 ;
for ( V_16 = 0 ; V_16 < V_17 ; V_16 ++ )
if ( V_18 [ V_16 ] . V_19 >= 0 &&
! strcmp ( V_18 [ V_16 ] . V_22 , V_20 ) )
return & V_18 [ V_16 ] ;
return NULL ;
}
int
F_15 ( int type )
{
return F_12 ( type ) != NULL ;
}
char *
F_16 ( int V_15 )
{
struct V_14 * V_21 = F_12 ( V_15 ) ;
return ( V_21 == NULL ) ? NULL : V_21 -> V_23 ;
}
char *
F_17 ( int V_15 )
{
char * V_2 ;
struct V_14 * V_21 = F_12 ( V_15 ) ;
if ( V_21 != NULL )
return V_21 -> V_22 ;
V_2 = F_3 () ;
snprintf ( V_2 , V_8 , L_8 , V_15 ) ;
return V_2 ;
}
int
F_18 ( const char * V_2 )
{
struct V_14 * V_21 = F_14 ( V_2 ) ;
if ( V_21 != NULL )
return V_21 -> V_19 ;
return - 1 ;
}
char *
F_19 ( T_1 V_24 )
{
int V_15 = F_20 ( V_24 ) ;
int V_25 = F_21 ( V_24 ) ;
struct V_14 * V_21 = F_12 ( V_15 ) ;
char * V_2 = F_3 () ;
if ( V_21 == NULL )
snprintf ( V_2 , V_8 , L_9 , V_15 , V_25 ) ;
else if ( V_25 == 0 )
snprintf ( V_2 , V_8 , L_10 , V_21 -> V_22 ) ;
else
snprintf ( V_2 , V_8 , L_11 , V_21 -> V_22 , V_25 ) ;
return V_2 ;
}
char *
F_22 ( T_2 V_26 )
{
T_1 V_7 = F_23 ( V_26 ) ;
T_1 V_24 = F_24 ( V_26 ) ;
int V_15 = F_20 ( V_24 ) ;
int V_27 = F_21 ( V_24 ) ;
struct V_14 * V_21 ;
char * V_2 ;
int V_6 ;
if ( V_26 == V_28 )
return L_12 ;
V_21 = F_12 ( V_15 ) ;
V_2 = F_3 () ;
if ( V_21 == NULL )
snprintf ( V_2 , V_8 , L_13 , V_7 , V_15 , V_27 ) ;
else {
V_21 -> V_29 ( V_7 , V_2 ) ;
V_6 = strlen ( V_2 ) ;
if ( V_27 == 0 )
snprintf ( V_2 + V_6 , V_8 - V_6 , L_14 ,
V_21 -> V_22 ) ;
else
snprintf ( V_2 + V_6 , V_8 - V_6 , L_15 ,
V_21 -> V_22 , V_27 ) ;
}
return V_2 ;
}
static struct V_14 *
F_25 ( const char * V_2 , T_1 * V_24 )
{
struct V_14 * V_30 ( V_21 ) ;
int V_6 ;
int V_31 ;
int V_16 ;
for ( V_16 = 0 ; V_16 < V_17 ; V_16 ++ ) {
V_21 = & V_18 [ V_16 ] ;
if ( V_21 -> V_19 >= 0 &&
! strncmp ( V_2 , V_21 -> V_22 , strlen ( V_21 -> V_22 ) ) )
break;
}
if ( V_16 == V_17 )
return NULL ;
V_6 = strlen ( V_21 -> V_22 ) ;
if ( strlen ( V_2 ) == ( unsigned int ) V_6 ) {
V_31 = 0 ;
} else {
if ( V_21 -> V_19 == V_32 )
return NULL ;
V_2 += V_6 ;
V_16 = strlen ( V_2 ) ;
if ( sscanf ( V_2 , L_7 , & V_31 , & V_16 ) < 1 ||
V_16 != ( int ) strlen ( V_2 ) )
return NULL ;
}
* V_24 = F_26 ( V_21 -> V_19 , V_31 ) ;
return V_21 ;
}
T_1
F_27 ( const char * V_2 )
{
T_1 V_24 ;
if ( F_25 ( V_2 , & V_24 ) != NULL )
return V_24 ;
return F_24 ( V_28 ) ;
}
T_2
F_28 ( const char * V_2 )
{
const char * V_33 = strchr ( V_2 , '@' ) ;
struct V_14 * V_21 ;
T_1 V_24 ;
T_1 V_7 ;
if ( V_33 != NULL ) {
V_21 = F_25 ( V_33 + 1 , & V_24 ) ;
if ( V_21 == NULL )
return V_28 ;
} else {
V_33 = V_2 + strlen ( V_2 ) ;
V_24 = F_26 ( V_34 , 0 ) ;
V_21 = F_12 ( V_34 ) ;
F_29 ( V_21 != NULL ) ;
}
if ( ! V_21 -> V_35 ( V_2 , ( int ) ( V_33 - V_2 ) , & V_7 ) )
return V_28 ;
return F_30 ( V_24 , V_7 ) ;
}
char *
F_31 ( T_3 V_36 )
{
char * V_2 = F_3 () ;
if ( V_36 . V_37 == V_38 ) {
snprintf ( V_2 , V_8 ,
L_16 , F_22 ( V_36 . V_26 ) ) ;
return V_2 ;
}
snprintf ( V_2 , V_8 , L_17 ,
( ( V_36 . V_37 & V_39 ) != 0 ) ? L_18 : L_19 ,
( V_36 . V_37 & ~ V_39 ) , F_22 ( V_36 . V_26 ) ) ;
return V_2 ;
}
int
F_32 ( T_2 * V_40 , const char * V_2 )
{
if ( ! strcmp ( V_2 , L_20 ) ) {
* V_40 = V_28 ;
return 1 ;
}
* V_40 = F_28 ( V_2 ) ;
return * V_40 != V_28 ;
}
static int
F_33 ( char * V_2 , int V_41 , struct V_42 * V_43 )
{
struct V_44 * V_45 ;
int V_46 ;
V_46 = F_34 ( V_2 , V_41 , 0 , V_47 , & V_45 ) ;
if ( V_46 == 0 )
F_35 ( & V_45 -> V_48 , V_43 ) ;
return V_46 ;
}
static int
F_36 ( const struct V_49 * V_50 , struct V_51 * V_51 )
{
struct V_52 * V_52 ;
if ( V_50 -> V_53 == 1 && V_50 -> V_54 [ 0 ] == '*' ) {
V_51 -> V_55 = 1 ;
return 1 ;
}
F_37 ( V_52 , sizeof( struct V_52 ) ) ;
if ( V_52 == NULL )
return 0 ;
F_35 ( & V_52 -> V_56 , & V_51 -> V_57 ) ;
F_38 ( & V_52 -> V_58 ) ;
return V_51 -> V_59 -> V_60 ( V_50 -> V_54 ,
V_50 -> V_53 ,
& V_52 -> V_58 ) ;
}
static struct V_51 *
F_39 ( const struct V_49 * V_50 ,
struct V_42 * V_61 )
{
struct V_14 * V_21 ;
struct V_51 * V_62 ;
int V_63 ;
unsigned V_31 ;
if ( V_50 -> V_53 >= V_8 )
return NULL ;
V_21 = F_13 ( V_50 -> V_54 ) ;
if ( V_21 == NULL )
return NULL ;
V_63 = V_50 -> V_53 - strlen ( V_21 -> V_22 ) ;
if ( V_63 == 0 )
V_31 = 0 ;
else {
if ( ! F_40 ( V_50 -> V_54 + strlen ( V_21 -> V_22 ) ,
V_63 , & V_31 , 0 , V_47 ) )
return NULL ;
}
F_41 (nr, nidlist, nr_link) {
if ( V_62 -> V_59 != V_21 )
continue;
if ( V_62 -> V_64 != V_31 )
continue;
return V_62 ;
}
F_37 ( V_62 , sizeof( struct V_51 ) ) ;
if ( V_62 == NULL )
return NULL ;
F_35 ( & V_62 -> V_65 , V_61 ) ;
F_38 ( & V_62 -> V_57 ) ;
V_62 -> V_59 = V_21 ;
V_62 -> V_55 = 0 ;
V_62 -> V_64 = V_31 ;
return V_62 ;
}
static int
F_42 ( struct V_49 * V_50 , struct V_42 * V_61 )
{
struct V_49 V_52 ;
struct V_49 V_24 ;
struct V_49 V_66 ;
struct V_51 * V_62 ;
V_66 = * V_50 ;
if ( F_43 ( V_50 , '@' , & V_52 ) == 0 )
goto V_67;
if ( F_43 ( V_50 , '@' , & V_24 ) == 0 || V_50 -> V_54 != NULL )
goto V_67;
V_62 = F_39 ( & V_24 , V_61 ) ;
if ( V_62 == NULL )
goto V_67;
if ( F_36 ( & V_52 , V_62 ) != 0 )
goto V_67;
return 1 ;
V_67:
F_44 ( L_21 , V_66 . V_53 , V_66 . V_54 ) ;
return 0 ;
}
static void
F_45 ( struct V_42 * V_43 )
{
while ( ! F_46 ( V_43 ) ) {
struct V_52 * V_68 ;
V_68 = F_47 ( V_43 -> V_69 , struct V_52 , V_56 ) ;
F_48 ( & V_68 -> V_58 ) ;
F_49 ( & V_68 -> V_56 ) ;
F_50 ( V_68 , sizeof( struct V_52 ) ) ;
}
}
void
F_51 ( struct V_42 * V_43 )
{
struct V_42 * V_70 , * V_69 ;
struct V_51 * V_62 ;
F_52 (pos, next, list) {
V_62 = F_47 ( V_70 , struct V_51 , V_65 ) ;
F_45 ( & V_62 -> V_57 ) ;
F_49 ( V_70 ) ;
F_50 ( V_62 , sizeof( struct V_51 ) ) ;
}
}
int
F_53 ( char * V_2 , int V_41 , struct V_42 * V_61 )
{
struct V_49 V_50 ;
struct V_49 V_71 ;
int V_46 ;
V_72 ;
V_50 . V_54 = V_2 ;
V_50 . V_53 = V_41 ;
F_38 ( V_61 ) ;
while ( V_50 . V_54 ) {
V_46 = F_43 ( & V_50 , ' ' , & V_71 ) ;
if ( V_46 == 0 ) {
F_51 ( V_61 ) ;
RETURN ( 0 ) ;
}
V_46 = F_42 ( & V_71 , V_61 ) ;
if ( V_46 == 0 ) {
F_51 ( V_61 ) ;
RETURN ( 0 ) ;
}
}
RETURN ( 1 ) ;
}
static int
F_54 ( T_1 V_7 , struct V_42 * V_73 )
{
struct V_44 * V_45 ;
F_29 ( ! F_46 ( V_73 ) ) ;
V_45 = F_47 ( V_73 -> V_69 , struct V_44 , V_48 ) ;
return F_55 ( V_7 , V_45 ) ;
}
int F_56 ( T_2 V_26 , struct V_42 * V_61 )
{
struct V_51 * V_62 ;
struct V_52 * V_68 ;
V_72 ;
F_41 (nr, nidlist, nr_link) {
if ( V_62 -> V_59 -> V_19 != F_20 ( F_24 ( V_26 ) ) )
continue;
if ( V_62 -> V_64 != F_21 ( F_24 ( V_26 ) ) )
continue;
if ( V_62 -> V_55 )
RETURN ( 1 ) ;
F_41 (ar, &nr->nr_addrranges, ar_link)
if ( V_62 -> V_59 -> V_74 ( F_23 ( V_26 ) ,
& V_68 -> V_58 ) )
RETURN ( 1 ) ;
}
RETURN ( 0 ) ;
}
