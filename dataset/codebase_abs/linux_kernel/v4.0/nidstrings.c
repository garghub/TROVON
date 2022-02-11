void F_1 ( void )
{
F_2 ( & V_1 ) ;
}
static char *
F_3 ( void )
{
char * V_2 ;
unsigned long V_3 ;
F_4 ( & V_1 , V_3 ) ;
V_2 = V_4 [ V_5 ++ ] ;
if ( V_5 == F_5 ( V_4 ) )
V_5 = 0 ;
F_6 ( & V_1 , V_3 ) ;
return V_2 ;
}
static int F_7 ( const char * V_2 , int V_6 , T_1 * V_7 )
{
* V_7 = 0 ;
return 1 ;
}
static void F_8 ( T_1 V_7 , char * V_2 )
{
snprintf ( V_2 , V_8 , L_1 ,
( V_7 >> 24 ) & 0xff , ( V_7 >> 16 ) & 0xff ,
( V_7 >> 8 ) & 0xff , V_7 & 0xff ) ;
}
static int F_9 ( const char * V_2 , int V_6 , T_1 * V_7 )
{
unsigned int V_9 ;
unsigned int V_10 ;
unsigned int V_11 ;
unsigned int V_12 ;
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
static void F_10 ( T_1 V_7 , char * V_2 )
{
snprintf ( V_2 , V_8 , L_3 , V_7 ) ;
}
static void F_11 ( T_1 V_7 , char * V_2 )
{
snprintf ( V_2 , V_8 , L_4 , V_7 ) ;
}
static int F_12 ( const char * V_2 , int V_6 , T_1 * V_7 )
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
static int
F_13 ( char * V_2 , int V_14 , struct V_15 * V_16 )
{
struct V_17 * V_18 ;
int V_19 ;
V_19 = F_14 ( V_2 , V_14 , 0 , V_20 , & V_18 ) ;
if ( V_19 == 0 )
F_15 ( & V_18 -> V_21 , V_16 ) ;
return V_19 ;
}
static int
F_16 ( T_1 V_7 , struct V_15 * V_22 )
{
struct V_17 * V_18 ;
F_17 ( ! F_18 ( V_22 ) ) ;
V_18 = F_19 ( V_22 -> V_23 , struct V_17 , V_21 ) ;
return F_20 ( V_7 , V_18 ) ;
}
static struct V_24 *
F_21 ( int V_25 )
{
int V_26 ;
if ( V_25 >= 0 )
for ( V_26 = 0 ; V_26 < V_27 ; V_26 ++ )
if ( V_25 == V_28 [ V_26 ] . V_29 )
return & V_28 [ V_26 ] ;
return NULL ;
}
static struct V_24 *
F_22 ( const char * V_30 )
{
struct V_24 * V_31 ;
int V_26 ;
for ( V_26 = 0 ; V_26 < V_27 ; V_26 ++ ) {
V_31 = & V_28 [ V_26 ] ;
if ( V_31 -> V_29 >= 0 &&
! strncmp ( V_30 , V_31 -> V_32 , strlen ( V_31 -> V_32 ) ) )
return V_31 ;
}
return NULL ;
}
static struct V_24 *
F_23 ( const char * V_30 )
{
int V_26 ;
for ( V_26 = 0 ; V_26 < V_27 ; V_26 ++ )
if ( V_28 [ V_26 ] . V_29 >= 0 &&
! strcmp ( V_28 [ V_26 ] . V_32 , V_30 ) )
return & V_28 [ V_26 ] ;
return NULL ;
}
int
F_24 ( int type )
{
return F_21 ( type ) != NULL ;
}
char *
F_25 ( int V_25 )
{
struct V_24 * V_31 = F_21 ( V_25 ) ;
return ( V_31 == NULL ) ? NULL : V_31 -> V_33 ;
}
char *
F_26 ( int V_25 )
{
char * V_2 ;
struct V_24 * V_31 = F_21 ( V_25 ) ;
if ( V_31 != NULL )
return V_31 -> V_32 ;
V_2 = F_3 () ;
snprintf ( V_2 , V_8 , L_8 , V_25 ) ;
return V_2 ;
}
int
F_27 ( const char * V_2 )
{
struct V_24 * V_31 = F_23 ( V_2 ) ;
if ( V_31 != NULL )
return V_31 -> V_29 ;
return - 1 ;
}
char *
F_28 ( T_1 V_34 )
{
int V_25 = F_29 ( V_34 ) ;
int V_35 = F_30 ( V_34 ) ;
struct V_24 * V_31 = F_21 ( V_25 ) ;
char * V_2 = F_3 () ;
if ( V_31 == NULL )
snprintf ( V_2 , V_8 , L_9 , V_25 , V_35 ) ;
else if ( V_35 == 0 )
snprintf ( V_2 , V_8 , L_10 , V_31 -> V_32 ) ;
else
snprintf ( V_2 , V_8 , L_11 , V_31 -> V_32 , V_35 ) ;
return V_2 ;
}
char *
F_31 ( T_2 V_36 )
{
T_1 V_7 = F_32 ( V_36 ) ;
T_1 V_34 = F_33 ( V_36 ) ;
int V_25 = F_29 ( V_34 ) ;
int V_37 = F_30 ( V_34 ) ;
struct V_24 * V_31 ;
char * V_2 ;
int V_6 ;
if ( V_36 == V_38 )
return L_12 ;
V_31 = F_21 ( V_25 ) ;
V_2 = F_3 () ;
if ( V_31 == NULL )
snprintf ( V_2 , V_8 , L_13 , V_7 , V_25 , V_37 ) ;
else {
V_31 -> V_39 ( V_7 , V_2 ) ;
V_6 = strlen ( V_2 ) ;
if ( V_37 == 0 )
snprintf ( V_2 + V_6 , V_8 - V_6 , L_14 ,
V_31 -> V_32 ) ;
else
snprintf ( V_2 + V_6 , V_8 - V_6 , L_15 ,
V_31 -> V_32 , V_37 ) ;
}
return V_2 ;
}
static struct V_24 *
F_34 ( const char * V_2 , T_1 * V_34 )
{
struct V_24 * V_40 ( V_31 ) ;
int V_6 ;
unsigned int V_41 ;
int V_26 ;
for ( V_26 = 0 ; V_26 < V_27 ; V_26 ++ ) {
V_31 = & V_28 [ V_26 ] ;
if ( V_31 -> V_29 >= 0 &&
! strncmp ( V_2 , V_31 -> V_32 , strlen ( V_31 -> V_32 ) ) )
break;
}
if ( V_26 == V_27 )
return NULL ;
V_6 = strlen ( V_31 -> V_32 ) ;
if ( strlen ( V_2 ) == ( unsigned int ) V_6 ) {
V_41 = 0 ;
} else {
if ( V_31 -> V_29 == V_42 )
return NULL ;
V_2 += V_6 ;
V_26 = strlen ( V_2 ) ;
if ( sscanf ( V_2 , L_7 , & V_41 , & V_26 ) < 1 ||
V_26 != ( int ) strlen ( V_2 ) )
return NULL ;
}
* V_34 = F_35 ( V_31 -> V_29 , V_41 ) ;
return V_31 ;
}
T_1
F_36 ( const char * V_2 )
{
T_1 V_34 ;
if ( F_34 ( V_2 , & V_34 ) != NULL )
return V_34 ;
return F_33 ( V_38 ) ;
}
T_2
F_37 ( const char * V_2 )
{
const char * V_43 = strchr ( V_2 , '@' ) ;
struct V_24 * V_31 ;
T_1 V_34 ;
T_1 V_7 ;
if ( V_43 != NULL ) {
V_31 = F_34 ( V_43 + 1 , & V_34 ) ;
if ( V_31 == NULL )
return V_38 ;
} else {
V_43 = V_2 + strlen ( V_2 ) ;
V_34 = F_35 ( V_44 , 0 ) ;
V_31 = F_21 ( V_44 ) ;
F_17 ( V_31 != NULL ) ;
}
if ( ! V_31 -> V_45 ( V_2 , ( int ) ( V_43 - V_2 ) , & V_7 ) )
return V_38 ;
return F_38 ( V_34 , V_7 ) ;
}
char *
F_39 ( T_3 V_46 )
{
char * V_2 = F_3 () ;
if ( V_46 . V_47 == V_48 ) {
snprintf ( V_2 , V_8 ,
L_16 , F_31 ( V_46 . V_36 ) ) ;
return V_2 ;
}
snprintf ( V_2 , V_8 , L_17 ,
( ( V_46 . V_47 & V_49 ) != 0 ) ? L_18 : L_19 ,
( V_46 . V_47 & ~ V_49 ) , F_31 ( V_46 . V_36 ) ) ;
return V_2 ;
}
int
F_40 ( T_2 * V_50 , const char * V_2 )
{
if ( ! strcmp ( V_2 , L_20 ) ) {
* V_50 = V_38 ;
return 1 ;
}
* V_50 = F_37 ( V_2 ) ;
return * V_50 != V_38 ;
}
static int
F_41 ( const struct V_51 * V_52 , struct V_53 * V_53 )
{
struct V_54 * V_54 ;
if ( V_52 -> V_55 == 1 && V_52 -> V_56 [ 0 ] == '*' ) {
V_53 -> V_57 = 1 ;
return 1 ;
}
F_42 ( V_54 , sizeof( struct V_54 ) ) ;
if ( V_54 == NULL )
return 0 ;
F_15 ( & V_54 -> V_58 , & V_53 -> V_59 ) ;
F_43 ( & V_54 -> V_60 ) ;
return V_53 -> V_61 -> V_62 ( V_52 -> V_56 ,
V_52 -> V_55 ,
& V_54 -> V_60 ) ;
}
static struct V_53 *
F_44 ( const struct V_51 * V_52 ,
struct V_15 * V_63 )
{
struct V_24 * V_31 ;
struct V_53 * V_64 ;
int V_65 ;
unsigned V_41 ;
if ( V_52 -> V_55 >= V_8 )
return NULL ;
V_31 = F_22 ( V_52 -> V_56 ) ;
if ( V_31 == NULL )
return NULL ;
V_65 = V_52 -> V_55 - strlen ( V_31 -> V_32 ) ;
if ( V_65 == 0 )
V_41 = 0 ;
else {
if ( ! F_45 ( V_52 -> V_56 + strlen ( V_31 -> V_32 ) ,
V_65 , & V_41 , 0 , V_20 ) )
return NULL ;
}
F_46 (nr, nidlist, nr_link) {
if ( V_64 -> V_61 != V_31 )
continue;
if ( V_64 -> V_66 != V_41 )
continue;
return V_64 ;
}
F_42 ( V_64 , sizeof( struct V_53 ) ) ;
if ( V_64 == NULL )
return NULL ;
F_15 ( & V_64 -> V_67 , V_63 ) ;
F_43 ( & V_64 -> V_59 ) ;
V_64 -> V_61 = V_31 ;
V_64 -> V_57 = 0 ;
V_64 -> V_66 = V_41 ;
return V_64 ;
}
static int
F_47 ( struct V_51 * V_52 , struct V_15 * V_63 )
{
struct V_51 V_54 ;
struct V_51 V_34 ;
struct V_51 V_68 ;
struct V_53 * V_64 ;
V_68 = * V_52 ;
if ( F_48 ( V_52 , '@' , & V_54 ) == 0 )
goto V_69;
if ( F_48 ( V_52 , '@' , & V_34 ) == 0 || V_52 -> V_56 != NULL )
goto V_69;
V_64 = F_44 ( & V_34 , V_63 ) ;
if ( V_64 == NULL )
goto V_69;
if ( F_41 ( & V_54 , V_64 ) != 0 )
goto V_69;
return 1 ;
V_69:
F_49 ( L_21 , V_68 . V_55 , V_68 . V_56 ) ;
return 0 ;
}
static void
F_50 ( struct V_15 * V_16 )
{
while ( ! F_18 ( V_16 ) ) {
struct V_54 * V_70 ;
V_70 = F_19 ( V_16 -> V_23 , struct V_54 , V_58 ) ;
F_51 ( & V_70 -> V_60 ) ;
F_52 ( & V_70 -> V_58 ) ;
F_53 ( V_70 , sizeof( struct V_54 ) ) ;
}
}
void
F_54 ( struct V_15 * V_16 )
{
struct V_15 * V_71 , * V_23 ;
struct V_53 * V_64 ;
F_55 (pos, next, list) {
V_64 = F_19 ( V_71 , struct V_53 , V_67 ) ;
F_50 ( & V_64 -> V_59 ) ;
F_52 ( V_71 ) ;
F_53 ( V_64 , sizeof( struct V_53 ) ) ;
}
}
int
F_56 ( char * V_2 , int V_14 , struct V_15 * V_63 )
{
struct V_51 V_52 ;
struct V_51 V_72 ;
int V_19 ;
V_52 . V_56 = V_2 ;
V_52 . V_55 = V_14 ;
F_43 ( V_63 ) ;
while ( V_52 . V_56 ) {
V_19 = F_48 ( & V_52 , ' ' , & V_72 ) ;
if ( V_19 == 0 ) {
F_54 ( V_63 ) ;
return 0 ;
}
V_19 = F_47 ( & V_72 , V_63 ) ;
if ( V_19 == 0 ) {
F_54 ( V_63 ) ;
return 0 ;
}
}
return 1 ;
}
int F_57 ( T_2 V_36 , struct V_15 * V_63 )
{
struct V_53 * V_64 ;
struct V_54 * V_70 ;
F_46 (nr, nidlist, nr_link) {
if ( V_64 -> V_61 -> V_29 != F_29 ( F_33 ( V_36 ) ) )
continue;
if ( V_64 -> V_66 != F_30 ( F_33 ( V_36 ) ) )
continue;
if ( V_64 -> V_57 )
return 1 ;
F_46 (ar, &nr->nr_addrranges, ar_link)
if ( V_64 -> V_61 -> V_73 ( F_32 ( V_36 ) ,
& V_70 -> V_60 ) )
return 1 ;
}
return 0 ;
}
