static inline int F_1 ( char V_1 )
{
return ( V_1 == '\'' || V_1 == '!' ) ;
}
static int F_2 ( struct V_2 * V_3 , const char * V_4 )
{
char * V_5 = NULL ;
int V_6 ;
if ( V_3 -> V_7 == V_4 )
V_5 = F_3 ( V_3 , NULL ) ;
V_6 = F_4 ( V_3 , '\'' ) ;
while ( ! V_6 && * V_4 ) {
T_1 V_8 = strcspn ( V_4 , L_1 ) ;
V_6 = F_5 ( V_3 , V_4 , V_8 ) ;
V_4 += V_8 ;
while ( ! V_6 && F_1 ( * V_4 ) )
V_6 = F_6 ( V_3 , L_2 , * V_4 ++ ) ;
}
if ( ! V_6 )
V_6 = F_4 ( V_3 , '\'' ) ;
free ( V_5 ) ;
return V_6 ;
}
int F_7 ( struct V_2 * V_3 , const char * * V_9 , T_1 V_10 )
{
int V_11 , V_6 ;
V_6 = F_8 ( V_3 , 255 ) ;
for ( V_11 = 0 ; ! V_6 && V_9 [ V_11 ] ; ++ V_11 ) {
V_6 = F_4 ( V_3 , ' ' ) ;
if ( V_6 )
break;
V_6 = F_2 ( V_3 , V_9 [ V_11 ] ) ;
if ( V_10 && V_3 -> V_8 > V_10 )
F_9 ( L_3 ) ;
}
return V_6 ;
}
