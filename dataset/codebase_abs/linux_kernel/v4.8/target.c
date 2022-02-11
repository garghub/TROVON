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
if ( V_2 -> V_15 && ( V_2 -> V_12 || V_2 -> V_7 ) ) {
V_2 -> V_15 = false ;
if ( V_3 == V_4 )
V_3 = V_16 ;
}
return V_3 ;
}
enum V_1 F_2 ( struct V_2 * V_2 )
{
struct V_17 V_18 , * V_19 ;
char V_20 [ 1024 ] ;
const char * V_21 = V_2 -> V_9 ;
V_2 -> V_22 = V_23 ;
if ( V_21 == NULL )
return V_4 ;
F_3 ( V_21 , & V_18 , V_20 , sizeof( V_20 ) , & V_19 ) ;
if ( V_19 == NULL ) {
char * V_24 ;
int V_22 = strtol ( V_21 , & V_24 , 10 ) ;
if ( * V_24 != '\0' )
return V_25 ;
F_4 ( V_22 , & V_18 , V_20 , sizeof( V_20 ) , & V_19 ) ;
if ( V_19 == NULL )
return V_26 ;
}
V_2 -> V_22 = V_19 -> V_27 ;
return V_4 ;
}
int F_5 ( struct V_2 * V_2 , int V_28 ,
char * V_20 , T_1 V_29 )
{
int V_30 ;
const char * V_31 ;
F_6 ( V_29 == 0 ) ;
if ( V_28 >= 0 ) {
F_7 ( V_28 , V_20 , V_29 ) ;
return 0 ;
}
if ( V_28 < V_32 || V_28 >= V_33 )
return - 1 ;
V_30 = V_28 - V_32 ;
V_31 = V_34 [ V_30 ] ;
switch ( V_28 ) {
case V_8 ...
V_16 :
snprintf ( V_20 , V_29 , L_1 , V_31 ) ;
break;
case V_25 :
case V_26 :
snprintf ( V_20 , V_29 , V_31 , V_2 -> V_9 ) ;
break;
default:
break;
}
return 0 ;
}
