enum V_1 F_1 ( struct V_2 * V_2 )
{
enum V_1 V_3 = V_4 ;
if ( V_2 -> V_5 )
V_2 -> V_6 = V_2 -> V_5 ;
if ( V_2 -> V_6 && V_2 -> V_7 ) {
V_2 -> V_7 = NULL ;
if ( V_3 == V_4 )
V_3 = V_8 ;
}
if ( V_2 -> V_6 && V_2 -> V_9 ) {
V_2 -> V_9 = NULL ;
if ( V_3 == V_4 )
V_3 = V_10 ;
}
if ( V_2 -> V_9 && V_2 -> V_7 ) {
V_2 -> V_7 = NULL ;
if ( V_3 == V_4 )
V_3 = V_11 ;
}
if ( V_2 -> V_6 && V_2 -> V_12 ) {
V_2 -> V_12 = false ;
if ( V_3 == V_4 )
V_3 = V_13 ;
}
if ( V_2 -> V_9 && V_2 -> V_12 ) {
V_2 -> V_12 = false ;
if ( V_3 == V_4 )
V_3 = V_14 ;
}
return V_3 ;
}
enum V_1 F_2 ( struct V_2 * V_2 )
{
struct V_15 V_16 , * V_17 ;
char V_18 [ 1024 ] ;
const char * V_19 = V_2 -> V_9 ;
V_2 -> V_20 = V_21 ;
if ( V_19 == NULL )
return V_4 ;
F_3 ( V_19 , & V_16 , V_18 , sizeof( V_18 ) , & V_17 ) ;
if ( V_17 == NULL ) {
char * V_22 ;
int V_20 = strtol ( V_19 , & V_22 , 10 ) ;
if ( * V_22 != '\0' )
return V_23 ;
F_4 ( V_20 , & V_16 , V_18 , sizeof( V_18 ) , & V_17 ) ;
if ( V_17 == NULL )
return V_24 ;
}
V_2 -> V_20 = V_17 -> V_25 ;
return V_4 ;
}
int F_5 ( struct V_2 * V_2 , int V_26 ,
char * V_18 , T_1 V_27 )
{
int V_28 ;
const char * V_29 ;
F_6 ( V_27 == 0 ) ;
if ( V_26 >= 0 ) {
const char * V_30 = F_7 ( V_26 , V_18 , V_27 ) ;
if ( V_30 != V_18 ) {
T_1 V_31 = strlen ( V_30 ) ;
memcpy ( V_18 , V_30 , F_8 ( V_27 - 1 , V_31 ) ) ;
* ( V_18 + F_8 ( V_27 - 1 , V_31 ) ) = '\0' ;
}
return 0 ;
}
if ( V_26 < V_32 || V_26 >= V_33 )
return - 1 ;
V_28 = V_26 - V_32 ;
V_29 = V_34 [ V_28 ] ;
switch ( V_26 ) {
case V_8 ... V_14 :
snprintf ( V_18 , V_27 , L_1 , V_29 ) ;
break;
case V_23 :
case V_24 :
snprintf ( V_18 , V_27 , V_29 , V_2 -> V_9 ) ;
break;
default:
break;
}
return 0 ;
}
