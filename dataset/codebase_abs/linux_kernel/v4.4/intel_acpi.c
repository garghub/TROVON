static char * F_1 ( T_1 V_1 )
{
switch ( V_1 ) {
case 0 :
return L_1 ;
case 1 :
return L_2 ;
case 2 :
return L_3 ;
case 3 :
return L_1 ;
case 4 :
return L_4 ;
case 5 :
return L_5 ;
case 6 :
return L_6 ;
case 7 :
return L_7 ;
case 8 :
return L_8 ;
case 9 :
return L_9 ;
case 0xa :
return L_10 ;
case 0xb :
case 0xc :
case 0xd :
return L_1 ;
case 0xe :
return L_11 ;
default:
return L_12 ;
}
}
static char * F_2 ( T_1 type )
{
switch ( type ) {
case 0 :
return L_13 ;
case 1 :
return L_14 ;
case 2 :
return L_15 ;
case 3 :
return L_16 ;
default:
return L_12 ;
}
}
static void F_3 ( void )
{
int V_2 ;
union V_3 * V_4 , * V_5 ;
V_4 = F_4 ( V_6 . V_7 , V_8 ,
V_9 , V_10 ,
NULL , V_11 ) ;
if ( ! V_4 ) {
F_5 ( L_17 ) ;
return;
}
V_5 = & V_4 -> V_12 . V_13 [ 0 ] ;
F_5 ( L_18 ,
( unsigned long long ) V_5 -> integer . V_14 ) ;
for ( V_2 = 1 ; V_2 < V_4 -> V_12 . V_15 ; V_2 ++ ) {
union V_3 * V_16 = & V_4 -> V_12 . V_13 [ V_2 ] ;
union V_3 * V_17 = & V_16 -> V_12 . V_13 [ 0 ] ;
union V_3 * V_18 = & V_16 -> V_12 . V_13 [ 1 ] ;
F_5 ( L_19 ,
( unsigned long long ) V_17 -> integer . V_14 ) ;
F_5 ( L_20 ,
F_1 ( V_18 -> V_19 . V_20 [ 0 ] ) ) ;
F_5 ( L_21 ,
F_2 ( V_18 -> V_19 . V_20 [ 1 ] ) ) ;
F_5 ( L_22 ,
F_2 ( V_18 -> V_19 . V_20 [ 2 ] ) ) ;
F_5 ( L_23 ,
F_2 ( V_18 -> V_19 . V_20 [ 3 ] ) ) ;
}
F_6 ( V_4 ) ;
}
static bool F_7 ( struct V_21 * V_22 )
{
T_2 V_7 ;
V_7 = F_8 ( & V_22 -> V_23 ) ;
if ( ! V_7 )
return false ;
if ( ! F_9 ( V_7 , V_8 , V_9 ,
1 << V_10 ) ) {
F_10 ( L_24 ) ;
return false ;
}
V_6 . V_7 = V_7 ;
F_3 () ;
return true ;
}
static bool F_11 ( void )
{
char V_24 [ 255 ] = { 0 } ;
struct V_25 V_19 = { sizeof( V_24 ) , V_24 } ;
struct V_21 * V_22 = NULL ;
bool V_26 = false ;
int V_27 = 0 ;
while ( ( V_22 = F_12 ( V_28 << 8 , V_22 ) ) != NULL ) {
V_27 ++ ;
V_26 |= F_7 ( V_22 ) ;
}
if ( V_27 == 2 && V_26 ) {
F_13 ( V_6 . V_7 , V_29 , & V_19 ) ;
F_5 ( L_25 ,
V_24 ) ;
return true ;
}
return false ;
}
void F_14 ( void )
{
if ( ! F_11 () )
return;
}
void F_15 ( void )
{
}
