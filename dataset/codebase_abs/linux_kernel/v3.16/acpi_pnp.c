static bool F_1 ( char V_1 )
{
return ( V_1 >= 0 && V_1 <= '9' ) || ( V_1 >= 'A' && V_1 <= 'F' ) ;
}
static bool F_2 ( char * V_2 , char * V_3 )
{
int V_4 ;
if ( memcmp ( V_2 , V_3 , 3 ) )
return false ;
for ( V_4 = 3 ; V_4 < 7 ; V_4 ++ ) {
char V_1 = toupper ( V_2 [ V_4 ] ) ;
if ( ! F_1 ( V_1 )
|| ( V_3 [ V_4 ] != 'X' && V_1 != toupper ( V_3 [ V_4 ] ) ) )
return false ;
}
return true ;
}
static bool F_3 ( char * V_2 , const struct V_5 * * V_6 )
{
const struct V_5 * V_7 ;
for ( V_7 = V_8 ; V_7 -> V_9 [ 0 ] ; V_7 ++ )
if ( F_2 ( V_2 , ( char * ) V_7 -> V_9 ) ) {
if ( V_6 )
* V_6 = V_7 ;
return true ;
}
return false ;
}
static int F_4 ( struct V_10 * V_11 ,
const struct V_5 * V_9 )
{
return 1 ;
}
static int F_5 ( struct V_10 * V_11 )
{
struct V_5 V_12 [] = {
{ L_1 } ,
{ L_2 } ,
{ L_3 } ,
{ L_4 } ,
} ;
return ! F_6 ( V_11 , V_12 ) ;
}
bool F_7 ( struct V_10 * V_11 )
{
return V_11 -> V_13 == & V_14 || F_5 ( V_11 ) ;
}
void T_1 F_8 ( void )
{
F_9 ( & V_14 ) ;
}
