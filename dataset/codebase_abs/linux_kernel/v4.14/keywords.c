static int F_1 ( register const char * V_1 , register unsigned int V_2 )
{
int V_3 ;
for ( V_3 = 0 ; V_3 < V_4 ; V_3 ++ ) {
struct V_5 * V_6 = V_7 + V_3 ;
int V_8 = strlen ( V_6 -> V_9 ) ;
if ( V_2 == V_8 && ! memcmp ( V_1 , V_6 -> V_9 , V_2 ) )
return V_6 -> V_10 ;
}
return - 1 ;
}
