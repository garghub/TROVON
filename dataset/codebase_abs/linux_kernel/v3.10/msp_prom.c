static inline unsigned char F_1 ( unsigned char V_1 )
{
if ( V_1 >= '0' && V_1 <= '9' )
return V_1 - '0' ;
if ( V_1 >= 'a' && V_1 <= 'f' )
return V_1 - 'a' + 10 ;
return 0 ;
}
int F_2 ( unsigned char * V_2 , unsigned char * V_3 )
{
int V_4 = 0 ;
unsigned char V_5 = 0 ;
while ( * V_3 != '\0' ) {
if ( ( * V_3 == '.' ) || ( * V_3 == ':' ) ) {
V_2 [ V_4 ++ ] = V_5 ;
V_5 = 0 ;
V_3 ++ ;
} else {
V_5 = V_5 << 4 ;
V_5 |= F_1 ( * V_3 ++ ) ;
}
}
if ( V_4 == 5 ) {
V_2 [ V_4 ++ ] = V_5 ;
return 0 ;
} else
return - 1 ;
}
static inline unsigned long F_3 ( unsigned char * V_3 )
{
int V_6 = 0 ;
while ( * V_3 ) {
V_6 = V_6 << 4 ;
V_6 |= F_1 ( * V_3 ++ ) ;
}
return V_6 ;
}
const char * F_4 ( void )
{
#if F_5 ( V_7 )
return L_1 ;
#elif F_5 ( V_8 )
return L_2 ;
#elif F_5 ( V_9 )
return L_3 ;
#elif F_5 ( V_10 )
return L_4 ;
#elif F_5 ( V_11 )
return L_5 ;
#else
#error "What is the type of *your* MSP?"
#endif
}
int F_6 ( char * V_12 , char * V_13 )
{
char * V_14 ;
V_14 = F_7 ( V_12 ) ;
if ( ! V_14 ) {
F_8 ( V_15 L_6 , V_12 ) ;
return - 1 ;
}
if ( F_2 ( V_13 , V_14 ) == - 1 ) {
F_8 ( V_15 L_7 ,
V_12 , V_14 ) ;
return - 1 ;
}
if ( V_16 > 1 ) {
int V_17 ;
F_8 ( V_18 L_8 , V_12 ) ;
for ( V_17 = 0 ; V_17 < 5 ; V_17 ++ )
F_8 ( V_18 L_9 ,
( unsigned char ) * ( V_13 + V_17 ) ) ;
F_8 ( V_18 L_10 , * ( V_13 + V_17 ) ) ;
}
return 0 ;
}
static char * F_9 ( void )
{
char * V_19 = F_7 ( V_20 ) ;
if ( V_19 == NULL ) {
V_19 = V_21 ;
}
return V_19 ;
}
static char F_10 ( char V_1 )
{
char * V_19 = F_9 () ;
while ( * V_19 ) {
if ( * V_19 ++ == V_1 )
return * V_19 ;
V_19 ++ ;
}
return V_22 ;
}
unsigned long F_11 ( void )
{
char * V_23 = F_7 ( V_24 ) ;
if ( V_23 == NULL )
return * V_25 ;
else
return F_3 ( V_23 ) ;
}
char F_12 ( void )
{
return F_10 ( V_26 ) ;
}
char F_13 ( void )
{
return F_10 ( V_27 ) ;
}
char F_14 ( void )
{
return F_10 ( V_28 ) ;
}
char F_15 ( void )
{
return F_10 ( V_29 ) ;
}
char F_16 ( void )
{
return F_10 ( V_30 ) ;
}
char F_17 ( void )
{
return F_10 ( V_31 ) ;
}
static char F_18 ( char V_32 , unsigned long V_33 )
{
char * V_19 = F_9 () ;
while ( * V_19 ) {
if ( * V_19 ++ == V_32 && V_33 -- == 0 )
return * V_19 ;
V_19 ++ ;
}
return V_22 ;
}
char F_19 ( unsigned long V_33 )
{
return F_18 ( V_34 , V_33 ) ;
}
char F_20 ( unsigned long V_33 )
{
return F_18 ( V_35 , V_33 ) ;
}
unsigned long F_21 ( void )
{
unsigned long V_23 ;
V_23 = F_11 () ;
return V_23 & V_36 ;
}
unsigned long F_22 ( void )
{
unsigned long V_23 ;
V_23 = F_11 () ;
return V_23 & V_37 ;
}
char * F_7 ( char * V_38 )
{
char * * V_39 = V_40 ;
int V_17 = strlen ( V_38 ) ;
while ( * V_39 ) {
if ( strncmp ( V_38 , * V_39 , V_17 ) == 0 ) {
return ( * V_39 + strlen ( V_38 ) + 1 ) ;
}
V_39 ++ ;
}
return NULL ;
}
void T_1 F_23 ( void )
{
char * V_41 ;
int V_42 ;
V_42 = 1 ;
V_41 = & ( V_43 [ 0 ] ) ;
while ( V_42 < V_44 ) {
strcpy ( V_41 , V_45 [ V_42 ] ) ;
V_41 += strlen ( V_45 [ V_42 ] ) ;
* V_41 ++ = ' ' ;
V_42 ++ ;
}
if ( V_41 != & ( V_43 [ 0 ] ) )
-- V_41 ;
* V_41 = '\0' ;
}
static int T_1 F_24 ( unsigned int type )
{
switch ( type ) {
case V_46 :
return V_47 ;
case V_48 :
return V_49 ;
default:
return V_50 ;
}
}
void T_1 F_25 ( void )
{
struct V_51 * V_52 ;
V_52 = F_26 () ;
while ( V_52 -> V_53 ) {
long type ;
unsigned long V_54 , V_53 ;
type = F_24 ( V_52 -> type ) ;
V_54 = V_52 -> V_54 ;
V_53 = V_52 -> V_53 ;
F_27 ( V_54 , V_53 , type ) ;
V_52 ++ ;
}
}
void T_1 F_28 ( void )
{
int V_55 ;
char * * V_56 ;
char * * V_57 ;
char * V_58 ;
int V_59 = 0 ;
int V_17 ;
unsigned long V_60 ;
for ( V_55 = 0 ; V_55 < V_44 ; V_55 ++ ) {
V_59 += sizeof( char * ) ;
V_59 += strlen ( V_45 [ V_55 ] ) + 1 ;
}
V_59 += sizeof( char * ) ;
V_56 = F_29 ( V_59 , V_61 ) ;
V_58 = ( char * ) & V_56 [ V_44 + 1 ] ;
for ( V_55 = 0 ; V_55 < V_44 ; V_55 ++ ) {
V_56 [ V_55 ] = V_58 ;
strcpy ( V_58 , V_45 [ V_55 ] ) ;
V_58 += strlen ( V_45 [ V_55 ] ) + 1 ;
}
V_56 [ V_44 ] = NULL ;
V_45 = V_56 ;
V_59 = 0 ;
V_17 = 0 ;
for ( V_57 = V_40 ; * V_57 != NULL ; V_57 ++ ) {
V_17 ++ ;
V_59 += sizeof( char * ) ;
V_59 += strlen ( * V_57 ) + 1 ;
}
V_59 += sizeof( char * ) ;
V_57 = F_29 ( V_59 , V_61 ) ;
V_58 = ( char * ) & V_57 [ V_17 + 1 ] ;
for ( V_55 = 0 ; V_55 < V_17 ; V_55 ++ ) {
V_57 [ V_55 ] = V_58 ;
strcpy ( V_58 , V_40 [ V_55 ] ) ;
V_58 += strlen ( V_40 [ V_55 ] ) + 1 ;
}
V_57 [ V_17 ] = NULL ;
V_40 = V_57 ;
for ( V_17 = 0 ; V_17 < V_62 . V_63 ; V_17 ++ ) {
if ( V_62 . V_64 [ V_17 ] . type != V_49 )
continue;
V_60 = V_62 . V_64 [ V_17 ] . V_60 ;
F_30 ( L_11 ,
V_60 , V_60 + V_62 . V_64 [ V_17 ] . V_53 ) ;
}
}
struct V_51 * T_1 F_26 ( void )
{
static char V_65 [] V_66 = L_12 ;
static char V_67 [] V_66 = L_13 ;
char * V_3 ;
unsigned int V_68 ;
unsigned int V_69 ;
int V_17 ;
V_3 = F_7 ( V_65 ) ;
if ( ! V_3 ) {
F_31 ( L_14
L_15 ) ;
V_68 = 0x02000000 ;
} else {
V_68 = F_32 ( V_3 , NULL , 0 ) ;
if ( V_68 == 0 ) {
V_68 = 0x02000000 ;
}
V_68 = F_33 ( V_68 ) ;
}
V_3 = F_7 ( V_67 ) ;
if ( ! V_3 ) {
V_69 = F_33 ( ( V_70 ) & V_71 ) ;
F_31 ( L_16
L_17 , V_69 ) ;
} else {
V_69 = F_32 ( V_3 , NULL , 16 ) ;
if ( V_69 == 0 ) {
V_69 = F_32 ( V_3 , NULL , 0 ) ;
if ( V_69 == 0 ) {
V_69 = F_33 ( ( V_70 ) & V_71 ) ;
}
}
V_69 = F_33 ( ( V_70 ) V_69 ) ;
}
V_17 = 0 ;
V_72 [ V_17 ] . type = V_50 ;
V_72 [ V_17 ] . V_54 = 0x00000000 ;
V_72 [ V_17 ] . V_53 = F_34 ( 0x300 + 0x80 ) ;
if ( V_69 > V_72 [ V_17 ] . V_54 + V_72 [ V_17 ] . V_53 ) {
V_17 ++ ;
V_72 [ V_17 ] . type = V_49 ;
V_72 [ V_17 ] . V_54 = V_72 [ V_17 - 1 ] . V_54 + V_72 [ V_17 - 1 ] . V_53 ;
V_72 [ V_17 ] . V_53 = V_69 - V_72 [ V_17 ] . V_54 ;
}
if ( V_69 != F_33 ( ( V_70 ) V_71 ) ) {
V_17 ++ ;
V_72 [ V_17 ] . type = V_47 ;
V_72 [ V_17 ] . V_54 = V_69 ;
V_72 [ V_17 ] . V_53 = F_33 ( ( V_70 ) V_71 ) - V_72 [ V_17 ] . V_54 ;
}
V_17 ++ ;
V_72 [ V_17 ] . type = V_50 ;
V_72 [ V_17 ] . V_54 = F_33 ( ( V_70 ) V_71 ) ;
V_72 [ V_17 ] . V_53 = F_33 ( F_34 ( ( V_70 ) V_73 ) ) - V_72 [ V_17 ] . V_54 ;
V_17 ++ ;
V_72 [ V_17 ] . type = V_46 ;
V_72 [ V_17 ] . V_54 = V_72 [ V_17 - 1 ] . V_54 + V_72 [ V_17 - 1 ] . V_53 ;
V_72 [ V_17 ] . V_53 = V_68 - V_72 [ V_17 ] . V_54 ;
return & V_72 [ 0 ] ;
}
