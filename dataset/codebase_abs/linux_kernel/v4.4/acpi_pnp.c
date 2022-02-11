static bool F_1 ( const char * V_1 , const char * V_2 )
{
int V_3 ;
if ( memcmp ( V_1 , V_2 , 3 ) )
return false ;
for ( V_3 = 3 ; V_3 < 7 ; V_3 ++ ) {
char V_4 = toupper ( V_1 [ V_3 ] ) ;
if ( ! isxdigit ( V_4 )
|| ( V_2 [ V_3 ] != 'X' && V_4 != toupper ( V_2 [ V_3 ] ) ) )
return false ;
}
return true ;
}
static bool F_2 ( const char * V_1 , const struct V_5 * * V_6 )
{
const struct V_5 * V_7 ;
for ( V_7 = V_8 ; V_7 -> V_9 [ 0 ] ; V_7 ++ )
if ( F_1 ( V_1 , ( char * ) V_7 -> V_9 ) ) {
if ( V_6 )
* V_6 = V_7 ;
return true ;
}
return false ;
}
static int F_3 ( struct V_10 * V_11 ,
const struct V_5 * V_9 )
{
return 1 ;
}
static int F_4 ( struct V_10 * V_11 )
{
struct V_5 V_12 [] = {
{ L_1 } ,
{ L_2 } ,
{ L_3 } ,
{ L_4 } ,
} ;
return ! F_5 ( V_11 , V_12 ) ;
}
bool F_6 ( struct V_10 * V_11 )
{
return V_11 -> V_13 == & V_14 || F_4 ( V_11 ) ;
}
void T_1 F_7 ( void )
{
F_8 ( & V_14 ) ;
}
