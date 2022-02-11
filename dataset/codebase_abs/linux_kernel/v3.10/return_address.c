void * F_1 ( unsigned int V_1 )
{
struct V_2 * V_3 ;
unsigned long V_4 ;
int V_5 ;
for ( V_5 = 0 , V_3 = NULL , V_4 = 0 ; V_5 <= V_1 ; V_5 ++ ) {
struct V_2 * V_6 ;
V_6 = F_2 ( V_4 , V_3 ) ;
if ( ! V_6 )
return NULL ;
if ( V_3 )
F_3 ( V_3 ) ;
V_3 = V_6 ;
if ( ! V_3 || ! V_3 -> V_7 )
break;
V_4 = V_3 -> V_7 ;
}
F_4 ( V_5 != V_1 + 1 ) ;
if ( V_3 )
F_3 ( V_3 ) ;
return ( void * ) V_4 ;
}
void * F_1 ( unsigned int V_1 )
{
return NULL ;
}
