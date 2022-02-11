int F_1 ( char * V_1 )
{
struct V_2 * V_3 ;
for ( V_3 = V_4 ; V_3 -> V_5 != NULL ; V_3 ++ ) {
if ( strncmp ( V_3 -> V_5 , V_1 , strlen ( V_3 -> V_5 ) ) == 0 )
return V_3 -> V_6 ;
}
return - 1 ;
}
