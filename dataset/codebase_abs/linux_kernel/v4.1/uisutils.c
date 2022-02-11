int
F_1 ( int * V_1 , char * * V_2 , int * V_3 ,
char * V_4 , ... )
{
T_1 args ;
int V_5 ;
va_start ( args , V_4 ) ;
V_5 = vsnprintf ( * V_2 , * V_3 , V_4 , args ) ;
va_end ( args ) ;
if ( V_5 >= * V_3 ) {
* V_2 += * V_3 ;
* V_1 += * V_3 ;
* V_3 = 0 ;
return - 1 ;
}
* V_3 -= V_5 ;
* V_2 += V_5 ;
* V_1 += V_5 ;
return V_5 ;
}
int
F_2 ( int type , void * V_6 ,
struct V_7 * V_8 )
{
switch ( type ) {
case 2 :
if ( V_6 ) {
if ( ! V_9 )
F_3 ( & V_10 ) ;
V_9 = V_6 ;
} else {
if ( V_9 )
F_4 ( & V_10 ) ;
V_9 = NULL ;
}
break;
default:
return 0 ;
}
if ( V_8 )
F_5 ( V_8 , L_1 , L_2 ,
V_11 , NULL ) ;
return 1 ;
}
struct V_12 *
F_6 ( T_2 V_13 )
{
struct V_14 * V_15 , * V_16 ;
struct V_12 * V_17 = NULL ;
F_7 ( & V_18 ) ;
F_8 (lelt, tmp, &req_handler_info_list) {
V_17 = F_9 ( V_15 , struct V_12 , V_19 ) ;
if ( F_10 ( V_17 -> V_13 , V_13 ) == 0 ) {
F_11 ( & V_18 ) ;
return V_17 ;
}
}
F_11 ( & V_18 ) ;
return NULL ;
}
