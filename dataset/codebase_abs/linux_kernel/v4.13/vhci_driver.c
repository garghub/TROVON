static struct V_1 *
F_1 ( struct V_1 * V_2 , char * V_3 )
{
struct V_4 * V_5 ;
V_5 = F_2 ( V_6 ,
L_1 , V_3 ) ;
if ( ! V_5 ) {
F_3 ( L_2 , V_3 ) ;
goto V_7;
}
F_4 ( V_5 , & V_2 -> V_8 ) ;
F_5 ( V_5 ) ;
return V_2 ;
V_7:
return NULL ;
}
static int F_6 ( const char * V_9 )
{
int V_10 = 0 ;
char * V_11 ;
V_11 = strchr ( V_9 , '\n' ) ;
if ( ! V_11 )
return - 1 ;
V_11 ++ ;
while ( * V_11 != '\0' ) {
int V_12 , V_13 , V_14 , V_15 ;
unsigned long V_16 ;
char V_17 [ V_18 ] ;
struct V_1 * V_2 ;
char V_19 [ 3 ] ;
V_10 = sscanf ( V_11 , L_3 ,
V_19 , & V_12 , & V_13 , & V_14 ,
& V_15 , & V_16 , V_17 ) ;
if ( V_10 < 5 ) {
F_3 ( L_4 , V_10 ) ;
F_7 () ;
}
F_3 ( L_5 ,
V_19 , V_12 , V_13 , V_14 , V_15 ) ;
F_3 ( L_6 , V_16 , V_17 ) ;
V_2 = & V_20 -> V_2 [ V_12 ] ;
memset ( V_2 , 0 , sizeof( * V_2 ) ) ;
if ( strncmp ( L_7 , V_19 , 2 ) == 0 )
V_2 -> V_19 = V_21 ;
else
V_2 -> V_19 = V_22 ;
V_2 -> V_12 = V_12 ;
V_2 -> V_13 = V_13 ;
V_2 -> V_15 = V_15 ;
V_2 -> V_23 = ( V_15 >> 16 ) ;
V_2 -> V_24 = ( V_15 & 0x0000ffff ) ;
if ( V_2 -> V_13 != V_25
&& V_2 -> V_13 != V_26 ) {
V_2 = F_1 ( V_2 , V_17 ) ;
if ( ! V_2 ) {
F_3 ( L_8 ) ;
return - 1 ;
}
}
V_11 = strchr ( V_11 , '\n' ) ;
if ( ! V_11 )
break;
V_11 ++ ;
}
F_3 ( L_9 ) ;
return 0 ;
}
static int F_8 ( void )
{
const char * V_27 ;
char V_13 [ V_28 + 1 ] = L_10 ;
int V_29 , V_10 ;
for ( V_29 = 0 ; V_29 < V_20 -> V_30 ; V_29 ++ ) {
if ( V_29 > 0 )
snprintf ( V_13 , sizeof( V_13 ) , L_11 , V_29 ) ;
V_27 = F_9 ( V_20 -> V_31 ,
V_13 ) ;
if ( ! V_27 ) {
V_7 ( L_12 ) ;
return - 1 ;
}
F_3 ( L_13 , V_29 ) ;
V_10 = F_6 ( V_27 ) ;
if ( V_10 != 0 )
return V_10 ;
}
return 0 ;
}
static int F_10 ( void )
{
const char * V_32 ;
V_32 = F_9 ( V_20 -> V_31 , L_14 ) ;
if ( ! V_32 ) {
V_7 ( L_15 ) ;
return - 1 ;
}
return ( int ) strtoul ( V_32 , NULL , 10 ) ;
}
static int F_11 ( const struct V_33 * V_33 )
{
return strcmp ( V_33 -> V_34 , L_16 ) >= 0 ;
}
static int F_12 ( void )
{
struct V_33 * * V_35 ;
struct V_4 * V_36 ;
int V_37 ;
V_36 = F_13 ( V_20 -> V_31 ) ;
if ( V_36 == NULL )
return - 1 ;
V_37 = F_14 ( F_15 ( V_36 ) , & V_35 , F_11 , NULL ) ;
if ( V_37 < 0 )
V_7 ( L_17 ) ;
else {
for ( int V_29 = 0 ; V_29 < V_37 ; V_29 ++ )
free ( V_35 [ V_29 ] ) ;
free ( V_35 ) ;
}
return V_37 ;
}
static int F_16 ( int V_38 , char * V_39 , unsigned long V_40 ,
char * V_12 , unsigned long V_41 , char * V_3 )
{
int V_42 ;
T_1 * V_43 ;
char V_44 [ V_45 + 1 ] ;
char * V_46 , * V_47 , * V_48 ;
char V_49 [] = { ' ' , ' ' , '\n' } ;
int V_50 [] = { ( int ) V_40 , ( int ) V_41 , V_18 } ;
T_2 V_51 = V_40 + V_41 + V_18 + 4 ;
V_46 = malloc ( V_51 ) ;
if ( ! V_46 )
return - 1 ;
snprintf ( V_44 , V_45 , V_52 L_18 , V_38 ) ;
V_43 = fopen ( V_44 , L_19 ) ;
if ( ! V_43 ) {
V_7 ( L_20 ) ;
free ( V_46 ) ;
return - 1 ;
}
if ( fgets ( V_46 , V_51 , V_43 ) == NULL ) {
V_7 ( L_21 ) ;
free ( V_46 ) ;
fclose ( V_43 ) ;
return - 1 ;
}
fclose ( V_43 ) ;
V_47 = V_46 ;
for ( V_42 = 0 ; V_42 < 3 ; V_42 ++ ) {
V_48 = strchr ( V_47 , V_49 [ V_42 ] ) ;
if ( V_48 == NULL || ( V_48 - V_47 ) > V_50 [ V_42 ] ) {
free ( V_46 ) ;
return - 1 ;
}
V_47 = V_48 + 1 ;
}
if ( sscanf ( V_46 , L_22 , V_39 , V_12 , V_3 ) != 3 ) {
V_7 ( L_23 ) ;
free ( V_46 ) ;
return - 1 ;
}
free ( V_46 ) ;
return 0 ;
}
int F_17 ( void )
{
V_6 = F_18 () ;
if ( ! V_6 ) {
V_7 ( L_24 ) ;
return - 1 ;
}
V_20 = calloc ( 1 , sizeof( struct V_53 ) ) ;
V_20 -> V_31 =
F_2 ( V_6 ,
V_54 ,
V_55 ) ;
if ( ! V_20 -> V_31 ) {
V_7 ( L_25 ) ;
goto V_7;
}
V_20 -> V_56 = F_10 () ;
F_3 ( L_26 , V_20 -> V_56 ) ;
if ( V_20 -> V_56 <= 0 ) {
V_7 ( L_27 ) ;
goto V_7;
} else if ( V_20 -> V_56 > V_57 ) {
V_7 ( L_28 , V_57 ) ;
goto V_7;
}
V_20 -> V_30 = F_12 () ;
F_3 ( L_29 , V_20 -> V_30 ) ;
if ( V_20 -> V_30 <= 0 ) {
V_7 ( L_30 ) ;
goto V_7;
}
if ( F_8 () )
goto V_7;
return 0 ;
V_7:
F_5 ( V_20 -> V_31 ) ;
if ( V_20 )
free ( V_20 ) ;
V_20 = NULL ;
F_19 ( V_6 ) ;
return - 1 ;
}
void F_20 ( void )
{
if ( ! V_20 )
return;
F_5 ( V_20 -> V_31 ) ;
free ( V_20 ) ;
V_20 = NULL ;
F_19 ( V_6 ) ;
}
int F_21 ( void )
{
if ( F_8 () )
goto V_7;
return 0 ;
V_7:
F_3 ( L_31 ) ;
return - 1 ;
}
int F_22 ( T_3 V_14 )
{
for ( int V_29 = 0 ; V_29 < V_20 -> V_56 ; V_29 ++ ) {
if ( V_14 == V_58 &&
V_20 -> V_2 [ V_29 ] . V_19 != V_22 )
continue;
if ( V_20 -> V_2 [ V_29 ] . V_13 == V_25 )
return V_20 -> V_2 [ V_29 ] . V_12 ;
}
return - 1 ;
}
int F_23 ( T_4 V_12 , int V_59 , T_3 V_15 ,
T_3 V_14 ) {
char V_60 [ 200 ] ;
char V_61 [ V_62 ] ;
char V_63 [] = L_32 ;
const char * V_44 ;
int V_10 ;
snprintf ( V_60 , sizeof( V_60 ) , L_33 ,
V_12 , V_59 , V_15 , V_14 ) ;
F_3 ( L_34 , V_60 ) ;
V_44 = F_15 ( V_20 -> V_31 ) ;
snprintf ( V_61 , sizeof( V_61 ) , L_35 ,
V_44 , V_63 ) ;
F_3 ( L_36 , V_61 ) ;
V_10 = F_24 ( V_61 , V_60 , strlen ( V_60 ) ) ;
if ( V_10 < 0 ) {
F_3 ( L_37 ) ;
return - 1 ;
}
F_3 ( L_38 , V_12 ) ;
return 0 ;
}
static unsigned long F_25 ( T_4 V_23 , T_4 V_24 )
{
return ( V_23 << 16 ) | V_24 ;
}
int F_26 ( T_4 V_12 , int V_59 , T_4 V_23 ,
T_4 V_24 , T_3 V_14 )
{
int V_15 = F_25 ( V_23 , V_24 ) ;
return F_23 ( V_12 , V_59 , V_15 , V_14 ) ;
}
int F_27 ( T_4 V_12 )
{
char V_64 [ V_62 ] ;
char V_65 [] = L_39 ;
char V_60 [ 200 ] ;
const char * V_44 ;
int V_10 ;
snprintf ( V_60 , sizeof( V_60 ) , L_40 , V_12 ) ;
F_3 ( L_34 , V_60 ) ;
V_44 = F_15 ( V_20 -> V_31 ) ;
snprintf ( V_64 , sizeof( V_64 ) , L_35 ,
V_44 , V_65 ) ;
F_3 ( L_41 , V_64 ) ;
V_10 = F_24 ( V_64 , V_60 , strlen ( V_60 ) ) ;
if ( V_10 < 0 ) {
F_3 ( L_37 ) ;
return - 1 ;
}
F_3 ( L_42 , V_12 ) ;
return 0 ;
}
int F_28 ( struct V_1 * V_2 )
{
char V_66 [ 100 ] ;
char V_39 [ V_67 ] = L_43 ;
char V_68 [ V_69 ] = L_44 ;
char V_70 [ V_18 ] ;
int V_10 ;
int V_71 = 0 ;
if ( V_2 -> V_13 == V_25 || V_2 -> V_13 == V_26 )
return 0 ;
V_10 = F_16 ( V_2 -> V_12 , V_39 , sizeof( V_39 ) , V_68 , sizeof( V_68 ) ,
V_70 ) ;
if ( V_10 ) {
V_7 ( L_45 ) ;
V_71 = 1 ;
}
printf ( L_46 , V_2 -> V_12 ,
F_29 ( V_2 -> V_13 ) ,
F_30 ( V_2 -> V_8 . V_14 ) ) ;
F_31 ( V_66 , sizeof( V_66 ) ,
V_2 -> V_8 . V_72 , V_2 -> V_8 . V_73 ) ;
printf ( L_47 , V_66 ) ;
if ( ! V_71 ) {
printf ( L_48 , V_2 -> V_8 . V_3 ,
V_39 , V_68 , V_70 ) ;
printf ( L_49 , L_50 ,
V_2 -> V_23 , V_2 -> V_24 ) ;
} else {
printf ( L_51 ,
V_2 -> V_8 . V_3 ) ;
printf ( L_49 , L_50 ,
V_2 -> V_23 , V_2 -> V_24 ) ;
}
return 0 ;
}
