int
F_1 ( const struct V_1 * V_2 , const char * V_3 , int V_4 )
{
#define F_2 \
(PERF_SAMPLE_BRANCH_USER |\
PERF_SAMPLE_BRANCH_KERNEL |\
PERF_SAMPLE_BRANCH_HV)
T_1 * V_5 = ( T_1 * ) V_2 -> V_6 ;
const struct V_7 * V_8 ;
char * V_9 , * V_10 = NULL , * V_11 ;
int V_12 = - 1 ;
if ( V_4 )
return 0 ;
if ( * V_5 )
return - 1 ;
if ( V_3 ) {
V_9 = V_10 = F_3 ( V_3 ) ;
if ( ! V_9 )
return - 1 ;
for (; ; ) {
V_11 = strchr ( V_9 , ',' ) ;
if ( V_11 )
* V_11 = '\0' ;
for ( V_8 = V_13 ; V_8 -> V_14 ; V_8 ++ ) {
if ( ! strcasecmp ( V_9 , V_8 -> V_14 ) )
break;
}
if ( ! V_8 -> V_14 ) {
F_4 ( L_1
L_2 , V_9 ) ;
goto error;
}
* V_5 |= V_8 -> V_5 ;
if ( ! V_11 )
break;
V_9 = V_11 + 1 ;
}
}
V_12 = 0 ;
if ( ( * V_5 & ~ F_2 ) == 0 ) {
* V_5 = V_15 ;
}
error:
free ( V_10 ) ;
return V_12 ;
}
