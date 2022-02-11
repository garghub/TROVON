static inline int F_1 ( char V_1 )
{
return ( V_1 == '\'' || V_1 == '!' ) ;
}
static void F_2 ( struct V_2 * V_3 , const char * V_4 )
{
char * V_5 = NULL ;
if ( V_3 -> V_6 == V_4 )
V_5 = F_3 ( V_3 , NULL ) ;
F_4 ( V_3 , '\'' ) ;
while ( * V_4 ) {
T_1 V_7 = strcspn ( V_4 , L_1 ) ;
F_5 ( V_3 , V_4 , V_7 ) ;
V_4 += V_7 ;
while ( F_1 ( * V_4 ) ) {
F_6 ( V_3 , L_2 ) ;
F_4 ( V_3 , * V_4 ++ ) ;
F_4 ( V_3 , '\'' ) ;
}
}
F_4 ( V_3 , '\'' ) ;
free ( V_5 ) ;
}
void F_7 ( struct V_2 * V_3 , const char * * V_8 , T_1 V_9 )
{
int V_10 ;
F_8 ( V_3 , 255 ) ;
for ( V_10 = 0 ; V_8 [ V_10 ] ; ++ V_10 ) {
F_4 ( V_3 , ' ' ) ;
F_2 ( V_3 , V_8 [ V_10 ] ) ;
if ( V_9 && V_3 -> V_7 > V_9 )
F_9 ( L_3 ) ;
}
}
