int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
unsigned char * V_5 ;
V_4 = F_2 ( sizeof( struct V_3 ) ) ;
if ( ! V_4 )
return - V_6 ;
V_2 -> V_4 = V_4 ;
for ( V_5 = V_4 -> V_7 ; V_5 < V_4 -> V_7 + V_8 ; V_5 += V_9 )
F_3 ( F_4 ( V_5 ) ) ;
return 0 ;
}
void F_5 ( struct V_1 * V_2 )
{
unsigned char * V_5 ;
if ( V_2 -> V_4 == NULL )
return;
for ( V_5 = V_2 -> V_4 -> V_7 ; V_5 < V_2 -> V_4 -> V_7 + V_8 ; V_5 += V_9 )
F_6 ( F_4 ( V_5 ) ) ;
F_7 ( V_2 -> V_4 ) ;
}
