static void F_1 ( char * V_1 [] )
{
int V_2 ;
printf ( L_1 , V_3 ) ;
printf ( L_2 ) ;
printf ( L_3 ,
V_1 [ 0 ] ) ;
printf ( L_4 ) ;
for ( V_2 = 0 ; V_4 [ V_2 ] . V_5 != 0 ; V_2 ++ ) {
printf ( L_5 , V_4 [ V_2 ] . V_5 ) ;
if ( V_4 [ V_2 ] . V_6 != NULL )
printf ( L_6 ,
* V_4 [ V_2 ] . V_6 ) ;
else
printf ( L_7 ,
V_4 [ V_2 ] . V_7 ) ;
printf ( L_2 ) ;
}
printf ( L_2 ) ;
}
T_1 F_2 ( void )
{
struct V_8 V_9 ;
int V_10 ;
V_10 = F_3 ( V_11 , & V_9 ) ;
if ( V_10 < 0 ) {
fprintf ( V_12 , L_8 , V_10 ) ;
exit ( V_13 ) ;
}
return ( T_1 ) V_9 . V_14 * V_15 + V_9 . V_16 ;
}
static const char * F_4 ( int V_17 )
{
if ( V_17 < V_18 )
return V_19 [ V_17 ] ;
return NULL ;
}
static void F_5 ( bool V_20 )
{
if ( V_20 )
printf ( L_9 , V_21 ) ;
printf ( L_10 ,
L_11 , L_12 , L_13 , L_14 ) ;
}
static void F_6 ( struct V_22 * V_23 ,
struct V_22 * V_24 ,
bool V_20 )
{
int V_2 = 0 ;
if ( V_20 )
V_2 = V_25 ;
for (; V_2 < V_18 ; V_2 ++ ) {
struct V_26 * V_27 = & V_23 -> V_28 [ V_2 ] ;
struct V_26 * V_29 = & V_24 -> V_28 [ V_2 ] ;
T_1 V_30 = 0 ;
T_1 V_31 = 0 ;
double V_32 = 0 ;
double V_33 = 0 ;
if ( V_29 -> V_34 ) {
V_31 = V_27 -> V_35 - V_29 -> V_35 ;
V_30 = V_27 -> V_34 - V_29 -> V_34 ;
if ( V_30 > 0 ) {
V_33 = ( ( double ) V_30 / V_15 ) ;
V_32 = V_31 / V_33 ;
}
}
printf ( L_15 ,
F_4 ( V_2 ) , V_32 , V_32 , V_33 ) ;
}
}
static T_1 F_7 ( int V_36 , T_2 V_37 )
{
unsigned int V_38 = F_8 () ;
T_1 V_39 [ V_38 ] ;
T_1 V_40 = 0 ;
int V_2 ;
if ( ( F_9 ( V_36 , & V_37 , V_39 ) ) != 0 ) {
fprintf ( V_12 ,
L_16 , V_37 ) ;
return 0 ;
}
for ( V_2 = 0 ; V_2 < V_38 ; V_2 ++ ) {
V_40 += V_39 [ V_2 ] ;
}
return V_40 ;
}
static bool F_10 ( int V_36 , struct V_22 * V_23 )
{
int V_2 ;
for ( V_2 = 0 ; V_2 < V_18 ; V_2 ++ ) {
V_23 -> V_28 [ V_2 ] . V_34 = F_2 () ;
V_23 -> V_28 [ V_2 ] . V_35 = F_7 ( V_36 , V_2 ) ;
}
return true ;
}
static void F_11 ( int V_41 , bool V_20 )
{
struct V_22 V_23 , V_24 ;
int V_42 ;
memset ( & V_23 , 0 , sizeof( V_23 ) ) ;
setlocale ( V_43 , L_17 ) ;
if ( V_44 )
printf ( L_18 , V_3 ) ;
if ( V_44 )
printf ( L_19 , V_45 [ 0 ] . V_5 ) ;
V_42 = V_45 [ 0 ] . V_36 ;
F_5 ( V_20 ) ;
fflush ( stdout ) ;
while ( 1 ) {
memcpy ( & V_24 , & V_23 , sizeof( V_23 ) ) ;
F_10 ( V_42 , & V_23 ) ;
F_6 ( & V_23 , & V_24 , V_20 ) ;
fflush ( stdout ) ;
F_12 ( V_41 ) ;
}
}
void F_13 ( void )
{
int V_2 ;
printf ( L_20 , V_46 ) ;
for ( V_2 = 0 ; V_2 < V_46 ; V_2 ++ ) {
printf ( L_21 , V_2 , V_47 [ V_2 ] ) ;
}
printf ( L_22 , V_48 ) ;
for ( V_2 = 0 ; V_2 < V_48 ; V_2 ++ ) {
char * V_5 = V_45 [ V_2 ] . V_5 ;
int V_36 = V_45 [ V_2 ] . V_36 ;
printf ( L_23 , V_2 , V_36 , V_5 ) ;
}
printf ( L_24 , V_46 ) ;
for ( V_2 = 0 ; V_2 < V_46 ; V_2 ++ ) {
if ( V_49 [ V_2 ] != - 1 )
printf ( L_25 , V_2 , V_49 [ V_2 ] ) ;
}
}
int main ( int V_50 , char * * V_1 )
{
int V_51 = 0 , V_52 ;
int V_53 = V_54 ;
char V_55 [ 256 ] ;
bool V_56 = true ;
int V_41 = 2 ;
snprintf ( V_55 , sizeof( V_55 ) , L_26 , V_1 [ 0 ] ) ;
while ( ( V_52 = F_14 ( V_50 , V_1 , L_27 ,
V_4 , & V_51 ) ) != - 1 ) {
switch ( V_52 ) {
case 'D' :
V_57 = true ;
break;
case 'S' :
V_56 = false ;
break;
case 's' :
V_41 = atoi ( V_58 ) ;
break;
case 'h' :
default:
F_1 ( V_1 ) ;
return V_13 ;
}
}
if ( F_15 ( V_55 ) ) {
printf ( L_28 , V_59 ) ;
return 1 ;
}
if ( ! V_47 [ 0 ] ) {
printf ( L_29 , strerror ( V_60 ) ) ;
return 1 ;
}
if ( V_57 ) {
F_13 () ;
}
if ( V_56 ) {
F_16 ( V_49 [ 2 ] ) ;
F_16 ( V_47 [ 2 ] ) ;
F_16 ( V_49 [ 3 ] ) ;
F_16 ( V_47 [ 3 ] ) ;
}
F_11 ( V_41 , V_56 ) ;
return V_53 ;
}
