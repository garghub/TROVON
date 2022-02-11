char *
F_1 ( char * V_1 , int * V_2 )
{
char * V_3 ;
V_3 = strstr ( V_1 , L_1 ) ;
if ( ! V_3 ) {
* V_2 = ( int ) strlen ( V_1 ) ;
return NULL ;
}
* V_3 = '\0' ;
* V_2 = ( int ) ( V_3 - V_1 + 2 ) ;
return V_1 ;
}
T_1
F_2 ( char * V_4 , T_2 V_5 , T_2 * V_6 )
{
char * V_7 , * V_8 , * line ;
T_2 V_9 = 0 ;
int V_10 ;
T_1 V_11 ;
V_7 = V_8 = F_3 ( V_4 , V_5 ) ;
if ( ! V_7 ) {
* V_6 = 0 ;
return FALSE ;
}
F_1 ( V_7 , & V_10 ) ;
V_7 += V_10 ;
V_9 += V_10 ;
V_11 = FALSE ;
* V_6 = - 1 ;
while ( ( line = F_1 ( V_7 , & V_10 ) ) ) {
char * V_12 , * V_13 , * V_14 ;
V_7 += V_10 ;
V_9 += V_10 ;
if ( strlen ( line ) == 0 ) {
break;
}
V_14 = strchr ( line , ':' ) ;
if ( ! V_14 ) break;
V_12 = line ;
* V_14 = '\0' ;
V_13 = V_14 + 2 ;
if ( ! strcmp ( V_12 , L_2 ) && strstr ( V_13 , L_3 ) ) {
V_11 = TRUE ;
}
}
* V_6 = V_9 ;
F_4 ( V_8 ) ;
return V_11 ;
}
