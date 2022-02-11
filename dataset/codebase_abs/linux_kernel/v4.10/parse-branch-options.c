int F_1 ( const char * V_1 , T_1 * V_2 )
{
#define F_2 \
(PERF_SAMPLE_BRANCH_USER |\
PERF_SAMPLE_BRANCH_KERNEL |\
PERF_SAMPLE_BRANCH_HV)
int V_3 = 0 ;
char * V_4 , * V_5 ;
char * V_6 = NULL ;
const struct V_7 * V_8 ;
if ( V_1 == NULL ) {
* V_2 = V_9 ;
return 0 ;
}
V_5 = V_6 = F_3 ( V_1 ) ;
if ( ! V_5 )
return - 1 ;
for (; ; ) {
V_4 = strchr ( V_5 , ',' ) ;
if ( V_4 )
* V_4 = '\0' ;
for ( V_8 = V_10 ; V_8 -> V_11 ; V_8 ++ ) {
if ( ! strcasecmp ( V_5 , V_8 -> V_11 ) )
break;
}
if ( ! V_8 -> V_11 ) {
V_3 = - 1 ;
F_4 ( L_1
L_2 , V_5 ) ;
goto error;
}
* V_2 |= V_8 -> V_2 ;
if ( ! V_4 )
break;
V_5 = V_4 + 1 ;
}
if ( ( * V_2 & ~ F_2 ) == 0 ) {
* V_2 = V_9 ;
}
error:
free ( V_6 ) ;
return V_3 ;
}
int
F_5 ( const struct V_12 * V_13 , const char * V_1 , int V_14 )
{
T_1 * V_2 = ( T_1 * ) V_13 -> V_15 ;
if ( V_14 )
return 0 ;
if ( * V_2 )
return - 1 ;
return F_1 ( V_1 , V_2 ) ;
}
