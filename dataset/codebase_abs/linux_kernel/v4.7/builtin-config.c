static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
struct V_5 * V_6 ;
struct V_7 * V_8 ;
if ( V_2 == NULL )
return - 1 ;
V_8 = & V_2 -> V_8 ;
if ( F_2 ( V_8 ) )
return - 1 ;
F_3 (section, sections, node) {
F_3 (item, &section->items, node) {
char * V_9 = V_6 -> V_9 ;
if ( V_9 )
printf ( L_1 , V_4 -> V_10 ,
V_6 -> V_10 , V_9 ) ;
}
}
return 0 ;
}
int F_4 ( int V_11 , const char * * V_12 , const char * T_1 V_13 )
{
int V_14 = 0 ;
struct V_1 * V_2 ;
char * V_15 = F_5 ( L_2 , getenv ( L_3 ) ) ;
V_11 = F_6 ( V_11 , V_12 , V_16 , V_17 ,
V_18 ) ;
if ( V_19 && V_20 ) {
F_7 ( L_4 ) ;
F_8 ( V_17 , V_16 , L_5 , 0 ) ;
F_8 ( NULL , V_16 , L_6 , 0 ) ;
return - 1 ;
}
if ( V_19 )
V_21 = F_9 () ;
else if ( V_20 )
V_21 = V_15 ;
V_2 = F_10 () ;
if ( ! V_2 ) {
V_14 = - 1 ;
goto V_22;
}
switch ( V_23 ) {
case V_24 :
if ( V_11 ) {
F_7 ( L_7 ) ;
F_8 ( V_17 , V_16 , L_8 , 1 ) ;
} else {
V_14 = F_1 ( V_2 ) ;
if ( V_14 < 0 ) {
const char * V_25 = V_21 ;
if ( ! V_21 )
V_25 = V_15 ;
F_7 ( L_9
L_10 , V_25 ) ;
}
}
break;
default:
F_11 ( V_17 , V_16 ) ;
}
F_12 ( V_2 ) ;
V_22:
return V_14 ;
}
