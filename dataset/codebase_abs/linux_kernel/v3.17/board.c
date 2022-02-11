static bool F_1 ( T_1 V_1 )
{
struct V_2 * V_3 = F_2 ( NULL ) ;
struct V_4 V_5 ;
while ( V_3 ) {
if ( F_3 ( V_3 )
&& ! F_4 ( V_3 , 0 , & V_5 ) ) {
if ( V_5 . V_6 == V_1 ) {
F_5 ( V_3 ) ;
return true ;
}
}
V_3 = F_2 ( V_3 ) ;
}
return false ;
}
bool T_2 F_6 ( const struct V_4 * V_4 ,
unsigned int V_7 )
{
unsigned int V_8 ;
for ( V_8 = 0 ; V_8 < V_7 ; V_8 ++ ) {
const struct V_4 * V_9 = V_4 + V_8 ;
if ( F_7 ( V_9 ) == V_10 )
if ( F_1 ( V_9 -> V_6 ) )
return true ;
}
return false ;
}
