static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
struct V_5 * V_6 ;
if ( V_2 == NULL )
return - 1 ;
F_2 (set, section, item) {
char * V_7 = V_6 -> V_7 ;
if ( V_7 )
printf ( L_1 , V_4 -> V_8 ,
V_6 -> V_8 , V_7 ) ;
}
return 0 ;
}
int F_3 ( int V_9 , const char * * V_10 , const char * T_1 V_11 )
{
int V_12 = 0 ;
struct V_1 * V_2 ;
char * V_13 = F_4 ( L_2 , getenv ( L_3 ) ) ;
V_9 = F_5 ( V_9 , V_10 , V_14 , V_15 ,
V_16 ) ;
if ( V_17 && V_18 ) {
F_6 ( L_4 ) ;
F_7 ( V_15 , V_14 , L_5 , 0 ) ;
F_7 ( NULL , V_14 , L_6 , 0 ) ;
return - 1 ;
}
if ( V_17 )
V_19 = F_8 () ;
else if ( V_18 )
V_19 = V_13 ;
V_2 = F_9 () ;
if ( ! V_2 ) {
V_12 = - 1 ;
goto V_20;
}
switch ( V_21 ) {
case V_22 :
if ( V_9 ) {
F_6 ( L_7 ) ;
F_7 ( V_15 , V_14 , L_8 , 1 ) ;
} else {
V_12 = F_1 ( V_2 ) ;
if ( V_12 < 0 ) {
const char * V_23 = V_19 ;
if ( ! V_19 )
V_23 = V_13 ;
F_6 ( L_9
L_10 , V_23 ) ;
}
}
break;
default:
F_10 ( V_15 , V_14 ) ;
}
F_11 ( V_2 ) ;
V_20:
return V_12 ;
}
