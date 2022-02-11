static const struct V_1 * F_1 ( register const char * V_2 , register unsigned int V_3 )
{
int V_4 ;
for ( V_4 = 0 ; V_4 < V_5 ; V_4 ++ ) {
struct V_1 * V_6 = V_7 + V_4 ;
int V_8 = strlen ( V_6 -> V_9 ) ;
if ( V_3 == V_8 && ! memcmp ( V_2 , V_6 -> V_9 , V_3 ) )
return V_6 ;
}
return NULL ;
}
