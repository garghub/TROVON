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
for ( int V_12 = 0 ; V_12 < V_13 -> V_14 ; V_12 ++ )
memset ( & V_13 -> V_2 [ V_12 ] , 0 , sizeof( V_13 -> V_2 [ V_12 ] ) ) ;
V_11 = strchr ( V_9 , '\n' ) ;
if ( ! V_11 )
return - 1 ;
V_11 ++ ;
while ( * V_11 != '\0' ) {
int V_15 , V_16 , V_17 , V_18 ;
unsigned long V_19 ;
char V_20 [ V_21 ] ;
V_10 = sscanf ( V_11 , L_3 ,
& V_15 , & V_16 , & V_17 ,
& V_18 , & V_19 , V_20 ) ;
if ( V_10 < 5 ) {
F_3 ( L_4 , V_10 ) ;
F_7 () ;
}
F_3 ( L_5 ,
V_15 , V_16 , V_17 , V_18 ) ;
F_3 ( L_6 , V_19 , V_20 ) ;
{
struct V_1 * V_2 = & V_13 -> V_2 [ V_15 ] ;
V_2 -> V_15 = V_15 ;
V_2 -> V_16 = V_16 ;
V_2 -> V_18 = V_18 ;
V_2 -> V_22 = ( V_18 >> 16 ) ;
V_2 -> V_23 = ( V_18 & 0x0000ffff ) ;
if ( V_2 -> V_16 != V_24
&& V_2 -> V_16 != V_25 ) {
V_2 = F_1 ( V_2 , V_20 ) ;
if ( ! V_2 ) {
F_3 ( L_7 ) ;
return - 1 ;
}
}
}
V_11 = strchr ( V_11 , '\n' ) ;
if ( ! V_11 )
break;
V_11 ++ ;
}
F_3 ( L_8 ) ;
return 0 ;
}
static int F_8 ( void )
{
const char * V_26 ;
V_26 = F_9 ( V_13 -> V_27 ,
L_9 ) ;
if ( ! V_26 ) {
V_7 ( L_10 ) ;
return - 1 ;
}
return F_6 ( V_26 ) ;
}
static int F_10 ( void )
{
char * V_11 ;
int V_14 = 0 ;
const char * V_26 ;
V_26 = F_9 ( V_13 -> V_27 ,
L_9 ) ;
if ( ! V_26 ) {
V_7 ( L_10 ) ;
return - 1 ;
}
V_11 = strchr ( V_26 , '\n' ) ;
if ( ! V_11 )
return 0 ;
V_11 ++ ;
while ( * V_11 != '\0' ) {
V_11 = strchr ( V_11 , '\n' ) ;
if ( ! V_11 )
return V_14 ;
V_11 ++ ;
V_14 += 1 ;
}
return V_14 ;
}
static int F_11 ( int V_28 , char * V_29 , unsigned long V_30 ,
char * V_15 , unsigned long V_31 , char * V_3 )
{
int V_32 ;
T_1 * V_33 ;
char V_34 [ V_35 + 1 ] ;
char * V_36 , * V_37 , * V_38 ;
char V_39 [] = { ' ' , ' ' , '\n' } ;
int V_40 [] = { ( int ) V_30 , ( int ) V_31 , V_21 } ;
T_2 V_41 = V_30 + V_31 + V_21 + 4 ;
V_36 = malloc ( V_41 ) ;
if ( ! V_36 )
return - 1 ;
snprintf ( V_34 , V_35 , V_42 L_11 , V_28 ) ;
V_33 = fopen ( V_34 , L_12 ) ;
if ( ! V_33 ) {
V_7 ( L_13 ) ;
free ( V_36 ) ;
return - 1 ;
}
if ( fgets ( V_36 , V_41 , V_33 ) == NULL ) {
V_7 ( L_14 ) ;
free ( V_36 ) ;
fclose ( V_33 ) ;
return - 1 ;
}
fclose ( V_33 ) ;
V_37 = V_36 ;
for ( V_32 = 0 ; V_32 < 3 ; V_32 ++ ) {
V_38 = strchr ( V_37 , V_39 [ V_32 ] ) ;
if ( V_38 == NULL || ( V_38 - V_37 ) > V_40 [ V_32 ] ) {
free ( V_36 ) ;
return - 1 ;
}
V_37 = V_38 + 1 ;
}
if ( sscanf ( V_36 , L_15 , V_29 , V_15 , V_3 ) != 3 ) {
V_7 ( L_16 ) ;
free ( V_36 ) ;
return - 1 ;
}
free ( V_36 ) ;
return 0 ;
}
int F_12 ( void )
{
V_6 = F_13 () ;
if ( ! V_6 ) {
V_7 ( L_17 ) ;
return - 1 ;
}
V_13 = calloc ( 1 , sizeof( struct V_43 ) ) ;
V_13 -> V_27 =
F_2 ( V_6 ,
V_44 ,
V_45 ) ;
if ( ! V_13 -> V_27 ) {
V_7 ( L_18 ) ;
goto V_7;
}
V_13 -> V_14 = F_10 () ;
F_3 ( L_19 , V_13 -> V_14 ) ;
if ( F_8 () )
goto V_7;
return 0 ;
V_7:
F_5 ( V_13 -> V_27 ) ;
if ( V_13 )
free ( V_13 ) ;
V_13 = NULL ;
F_14 ( V_6 ) ;
return - 1 ;
}
void F_15 ()
{
if ( ! V_13 )
return;
F_5 ( V_13 -> V_27 ) ;
free ( V_13 ) ;
V_13 = NULL ;
F_14 ( V_6 ) ;
}
int F_16 ( void )
{
if ( F_8 () )
goto V_7;
return 0 ;
V_7:
F_3 ( L_20 ) ;
return - 1 ;
}
int F_17 ( void )
{
for ( int V_12 = 0 ; V_12 < V_13 -> V_14 ; V_12 ++ ) {
if ( V_13 -> V_2 [ V_12 ] . V_16 == V_24 )
return V_12 ;
}
return - 1 ;
}
int F_18 ( T_3 V_15 , int V_46 , T_4 V_18 ,
T_4 V_17 ) {
char V_47 [ 200 ] ;
char V_48 [ V_49 ] ;
char V_50 [] = L_21 ;
const char * V_34 ;
int V_10 ;
snprintf ( V_47 , sizeof( V_47 ) , L_22 ,
V_15 , V_46 , V_18 , V_17 ) ;
F_3 ( L_23 , V_47 ) ;
V_34 = F_19 ( V_13 -> V_27 ) ;
snprintf ( V_48 , sizeof( V_48 ) , L_24 ,
V_34 , V_50 ) ;
F_3 ( L_25 , V_48 ) ;
V_10 = F_20 ( V_48 , V_47 , strlen ( V_47 ) ) ;
if ( V_10 < 0 ) {
F_3 ( L_26 ) ;
return - 1 ;
}
F_3 ( L_27 , V_15 ) ;
return 0 ;
}
static unsigned long F_21 ( T_3 V_22 , T_3 V_23 )
{
return ( V_22 << 16 ) | V_23 ;
}
int F_22 ( T_3 V_15 , int V_46 , T_3 V_22 ,
T_3 V_23 , T_4 V_17 )
{
int V_18 = F_21 ( V_22 , V_23 ) ;
return F_18 ( V_15 , V_46 , V_18 , V_17 ) ;
}
int F_23 ( T_3 V_15 )
{
char V_51 [ V_49 ] ;
char V_52 [] = L_28 ;
char V_47 [ 200 ] ;
const char * V_34 ;
int V_10 ;
snprintf ( V_47 , sizeof( V_47 ) , L_29 , V_15 ) ;
F_3 ( L_23 , V_47 ) ;
V_34 = F_19 ( V_13 -> V_27 ) ;
snprintf ( V_51 , sizeof( V_51 ) , L_24 ,
V_34 , V_52 ) ;
F_3 ( L_30 , V_51 ) ;
V_10 = F_20 ( V_51 , V_47 , strlen ( V_47 ) ) ;
if ( V_10 < 0 ) {
F_3 ( L_26 ) ;
return - 1 ;
}
F_3 ( L_31 , V_15 ) ;
return 0 ;
}
int F_24 ( struct V_1 * V_2 )
{
char V_53 [ 100 ] ;
char V_29 [ V_54 ] = L_32 ;
char V_55 [ V_56 ] = L_33 ;
char V_57 [ V_21 ] ;
int V_10 ;
int V_58 = 0 ;
if ( V_2 -> V_16 == V_24 || V_2 -> V_16 == V_25 )
return 0 ;
V_10 = F_11 ( V_2 -> V_15 , V_29 , sizeof( V_29 ) , V_55 , sizeof( V_55 ) ,
V_57 ) ;
if ( V_10 ) {
V_7 ( L_34 ) ;
V_58 = 1 ;
}
printf ( L_35 , V_2 -> V_15 ,
F_25 ( V_2 -> V_16 ) ,
F_26 ( V_2 -> V_8 . V_17 ) ) ;
F_27 ( V_53 , sizeof( V_53 ) ,
V_2 -> V_8 . V_59 , V_2 -> V_8 . V_60 ) ;
printf ( L_36 , V_53 ) ;
if ( ! V_58 ) {
printf ( L_37 , V_2 -> V_8 . V_3 ,
V_29 , V_55 , V_57 ) ;
printf ( L_38 , L_39 ,
V_2 -> V_22 , V_2 -> V_23 ) ;
} else {
printf ( L_40 ,
V_2 -> V_8 . V_3 ) ;
printf ( L_38 , L_39 ,
V_2 -> V_22 , V_2 -> V_23 ) ;
}
return 0 ;
}
