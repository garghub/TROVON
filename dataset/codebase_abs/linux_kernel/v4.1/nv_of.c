int F_1 ( struct V_1 * V_2 , int V_3 , T_1 * * V_4 )
{
struct V_5 * V_6 = V_2 -> V_6 ;
struct V_7 * V_8 , * V_9 ;
const unsigned char * V_10 = NULL ;
static char * V_11 [] = {
L_1 , L_2 , L_3 , L_4 ,
L_5 , L_6 , NULL } ;
int V_12 ;
V_8 = F_2 ( V_6 -> V_13 ) ;
if ( V_8 == NULL )
return - 1 ;
if ( V_6 -> V_14 ) {
const char * V_15 ;
int V_16 ;
for ( V_9 = NULL ;
( V_9 = F_3 ( V_8 , V_9 ) ) != NULL ; ) {
V_15 = F_4 ( V_9 , L_7 , NULL ) ;
if ( ! V_15 )
continue;
V_16 = strlen ( V_15 ) ;
if ( ( V_15 [ V_16 - 1 ] == 'A' && V_3 == 1 ) ||
( V_15 [ V_16 - 1 ] == 'B' && V_3 == 2 ) ) {
for ( V_12 = 0 ; V_11 [ V_12 ] != NULL ; ++ V_12 ) {
V_10 = F_4 ( V_9 ,
V_11 [ V_12 ] , NULL ) ;
if ( V_10 != NULL )
break;
}
F_5 ( V_9 ) ;
break;
}
}
}
if ( V_10 == NULL ) {
for ( V_12 = 0 ; V_11 [ V_12 ] != NULL ; ++ V_12 ) {
V_10 = F_4 ( V_8 , V_11 [ V_12 ] , NULL ) ;
if ( V_10 != NULL )
break;
}
}
if ( V_10 ) {
* V_4 = F_6 ( V_10 , V_17 , V_18 ) ;
if ( * V_4 == NULL )
return - 1 ;
F_7 ( V_19 L_8 , V_3 ) ;
return 0 ;
}
return - 1 ;
}
