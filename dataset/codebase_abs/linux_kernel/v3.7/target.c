enum V_1 F_1 ( struct V_2 * V_3 )
{
enum V_1 V_4 = V_5 ;
if ( V_3 -> V_6 )
V_3 -> V_7 = V_3 -> V_6 ;
if ( V_3 -> V_7 && V_3 -> V_8 ) {
V_3 -> V_8 = NULL ;
if ( V_4 == V_5 )
V_4 = V_9 ;
}
if ( V_3 -> V_7 && V_3 -> V_10 ) {
V_3 -> V_10 = NULL ;
if ( V_4 == V_5 )
V_4 = V_11 ;
}
if ( V_3 -> V_10 && V_3 -> V_8 ) {
V_3 -> V_8 = NULL ;
if ( V_4 == V_5 )
V_4 = V_12 ;
}
if ( V_3 -> V_7 && V_3 -> V_13 ) {
V_3 -> V_13 = false ;
if ( V_4 == V_5 )
V_4 = V_14 ;
}
if ( V_3 -> V_10 && V_3 -> V_13 ) {
V_3 -> V_13 = false ;
if ( V_4 == V_5 )
V_4 = V_15 ;
}
return V_4 ;
}
enum V_1 F_2 ( struct V_2 * V_3 )
{
struct V_16 V_17 , * V_18 ;
char V_19 [ 1024 ] ;
const char * V_20 = V_3 -> V_10 ;
V_3 -> V_21 = V_22 ;
if ( V_20 == NULL )
return V_5 ;
F_3 ( V_20 , & V_17 , V_19 , sizeof( V_19 ) , & V_18 ) ;
if ( V_18 == NULL ) {
char * V_23 ;
int V_21 = strtol ( V_20 , & V_23 , 10 ) ;
if ( * V_23 != '\0' )
return V_24 ;
F_4 ( V_21 , & V_17 , V_19 , sizeof( V_19 ) , & V_18 ) ;
if ( V_18 == NULL )
return V_25 ;
}
V_3 -> V_21 = V_18 -> V_26 ;
return V_5 ;
}
int F_5 ( struct V_2 * V_3 , int V_27 ,
char * V_19 , T_1 V_28 )
{
int V_29 ;
const char * V_30 ;
F_6 ( V_28 == 0 ) ;
if ( V_27 >= 0 ) {
const char * V_31 = F_7 ( V_27 , V_19 , V_28 ) ;
if ( V_31 != V_19 ) {
T_1 V_32 = strlen ( V_31 ) ;
memcpy ( V_19 , V_31 , F_8 ( V_28 - 1 , V_32 ) ) ;
* ( V_19 + F_8 ( V_28 - 1 , V_32 ) ) = '\0' ;
}
return 0 ;
}
if ( V_27 < V_33 ||
V_27 >= V_34 )
return - 1 ;
V_29 = V_27 - V_33 ;
V_30 = V_35 [ V_29 ] ;
switch ( V_27 ) {
case V_9
... V_15 :
snprintf ( V_19 , V_28 , L_1 , V_30 ) ;
break;
case V_24 :
case V_25 :
snprintf ( V_19 , V_28 , V_30 , V_3 -> V_10 ) ;
break;
default:
break;
}
return 0 ;
}
