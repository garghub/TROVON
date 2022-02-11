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
const char * V_28 ;
V_28 = F_9 ( V_13 -> V_27 , L_11 ) ;
if ( ! V_28 ) {
V_7 ( L_12 ) ;
return - 1 ;
}
return ( int ) strtoul ( V_28 , NULL , 10 ) ;
}
static int F_11 ( int V_29 , char * V_30 , unsigned long V_31 ,
char * V_15 , unsigned long V_32 , char * V_3 )
{
int V_33 ;
T_1 * V_34 ;
char V_35 [ V_36 + 1 ] ;
char * V_37 , * V_38 , * V_39 ;
char V_40 [] = { ' ' , ' ' , '\n' } ;
int V_41 [] = { ( int ) V_31 , ( int ) V_32 , V_21 } ;
T_2 V_42 = V_31 + V_32 + V_21 + 4 ;
V_37 = malloc ( V_42 ) ;
if ( ! V_37 )
return - 1 ;
snprintf ( V_35 , V_36 , V_43 L_13 , V_29 ) ;
V_34 = fopen ( V_35 , L_14 ) ;
if ( ! V_34 ) {
V_7 ( L_15 ) ;
free ( V_37 ) ;
return - 1 ;
}
if ( fgets ( V_37 , V_42 , V_34 ) == NULL ) {
V_7 ( L_16 ) ;
free ( V_37 ) ;
fclose ( V_34 ) ;
return - 1 ;
}
fclose ( V_34 ) ;
V_38 = V_37 ;
for ( V_33 = 0 ; V_33 < 3 ; V_33 ++ ) {
V_39 = strchr ( V_38 , V_40 [ V_33 ] ) ;
if ( V_39 == NULL || ( V_39 - V_38 ) > V_41 [ V_33 ] ) {
free ( V_37 ) ;
return - 1 ;
}
V_38 = V_39 + 1 ;
}
if ( sscanf ( V_37 , L_17 , V_30 , V_15 , V_3 ) != 3 ) {
V_7 ( L_18 ) ;
free ( V_37 ) ;
return - 1 ;
}
free ( V_37 ) ;
return 0 ;
}
int F_12 ( void )
{
V_6 = F_13 () ;
if ( ! V_6 ) {
V_7 ( L_19 ) ;
return - 1 ;
}
V_13 = calloc ( 1 , sizeof( struct V_44 ) ) ;
V_13 -> V_27 =
F_2 ( V_6 ,
V_45 ,
V_46 ) ;
if ( ! V_13 -> V_27 ) {
V_7 ( L_20 ) ;
goto V_7;
}
V_13 -> V_14 = F_10 () ;
F_3 ( L_21 , V_13 -> V_14 ) ;
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
void F_15 ( void )
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
F_3 ( L_22 ) ;
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
int F_18 ( T_3 V_15 , int V_47 , T_4 V_18 ,
T_4 V_17 ) {
char V_48 [ 200 ] ;
char V_49 [ V_50 ] ;
char V_51 [] = L_23 ;
const char * V_35 ;
int V_10 ;
snprintf ( V_48 , sizeof( V_48 ) , L_24 ,
V_15 , V_47 , V_18 , V_17 ) ;
F_3 ( L_25 , V_48 ) ;
V_35 = F_19 ( V_13 -> V_27 ) ;
snprintf ( V_49 , sizeof( V_49 ) , L_26 ,
V_35 , V_51 ) ;
F_3 ( L_27 , V_49 ) ;
V_10 = F_20 ( V_49 , V_48 , strlen ( V_48 ) ) ;
if ( V_10 < 0 ) {
F_3 ( L_28 ) ;
return - 1 ;
}
F_3 ( L_29 , V_15 ) ;
return 0 ;
}
static unsigned long F_21 ( T_3 V_22 , T_3 V_23 )
{
return ( V_22 << 16 ) | V_23 ;
}
int F_22 ( T_3 V_15 , int V_47 , T_3 V_22 ,
T_3 V_23 , T_4 V_17 )
{
int V_18 = F_21 ( V_22 , V_23 ) ;
return F_18 ( V_15 , V_47 , V_18 , V_17 ) ;
}
int F_23 ( T_3 V_15 )
{
char V_52 [ V_50 ] ;
char V_53 [] = L_30 ;
char V_48 [ 200 ] ;
const char * V_35 ;
int V_10 ;
snprintf ( V_48 , sizeof( V_48 ) , L_31 , V_15 ) ;
F_3 ( L_25 , V_48 ) ;
V_35 = F_19 ( V_13 -> V_27 ) ;
snprintf ( V_52 , sizeof( V_52 ) , L_26 ,
V_35 , V_53 ) ;
F_3 ( L_32 , V_52 ) ;
V_10 = F_20 ( V_52 , V_48 , strlen ( V_48 ) ) ;
if ( V_10 < 0 ) {
F_3 ( L_28 ) ;
return - 1 ;
}
F_3 ( L_33 , V_15 ) ;
return 0 ;
}
int F_24 ( struct V_1 * V_2 )
{
char V_54 [ 100 ] ;
char V_30 [ V_55 ] = L_34 ;
char V_56 [ V_57 ] = L_35 ;
char V_58 [ V_21 ] ;
int V_10 ;
int V_59 = 0 ;
if ( V_2 -> V_16 == V_24 || V_2 -> V_16 == V_25 )
return 0 ;
V_10 = F_11 ( V_2 -> V_15 , V_30 , sizeof( V_30 ) , V_56 , sizeof( V_56 ) ,
V_58 ) ;
if ( V_10 ) {
V_7 ( L_36 ) ;
V_59 = 1 ;
}
printf ( L_37 , V_2 -> V_15 ,
F_25 ( V_2 -> V_16 ) ,
F_26 ( V_2 -> V_8 . V_17 ) ) ;
F_27 ( V_54 , sizeof( V_54 ) ,
V_2 -> V_8 . V_60 , V_2 -> V_8 . V_61 ) ;
printf ( L_38 , V_54 ) ;
if ( ! V_59 ) {
printf ( L_39 , V_2 -> V_8 . V_3 ,
V_30 , V_56 , V_58 ) ;
printf ( L_40 , L_41 ,
V_2 -> V_22 , V_2 -> V_23 ) ;
} else {
printf ( L_42 ,
V_2 -> V_8 . V_3 ) ;
printf ( L_40 , L_41 ,
V_2 -> V_22 , V_2 -> V_23 ) ;
}
return 0 ;
}
