struct V_1 * F_1 ( struct V_2 * V_3 , T_1 V_4 ,
struct V_5 * V_6 , unsigned int V_7 ,
void (* F_2)( struct V_1 * ,
struct V_5 * ,
void * ) ,
void * V_8 , T_1 V_9 )
{
enum V_10 V_11 ;
enum V_12 V_13 ;
int V_14 ;
if ( ( V_7 >= V_15 ) && ( V_7 <= V_16 ) )
V_14 = F_3 ( V_3 , V_4 , V_6 , V_7 , & V_11 , & V_13 ) ;
else {
V_14 = F_4 ( V_3 , V_4 , V_6 , V_7 , & V_11 , & V_13 , & V_4 ) ;
}
if ( V_14 ) {
F_5 ( V_6 ) ;
return NULL ;
}
F_6 ( V_6 , V_11 , V_4 , V_3 -> V_17 , V_13 ,
V_18 , 0 ) ;
return V_3 -> V_19 . V_20 ( V_3 , V_6 , F_2 , NULL , V_8 , V_9 ) ;
}
int F_7 ( struct V_2 * V_3 )
{
if ( ! V_3 -> V_19 . V_21 )
V_3 -> V_19 . V_21 = F_1 ;
return 0 ;
}
const char * F_8 ( struct V_5 * V_6 )
{
const char * V_22 ;
struct V_23 * V_24 ;
struct V_25 * V_26 ;
if ( F_9 ( V_6 ) ) {
switch ( - F_10 ( V_6 ) ) {
case V_27 :
V_22 = L_1 ;
break;
case V_28 :
V_22 = L_2 ;
break;
case V_29 :
V_22 = L_3 ;
break;
default:
V_22 = L_4 ;
break;
}
} else {
V_24 = F_11 ( V_6 ) ;
switch ( V_24 -> V_13 ) {
case V_30 :
switch ( F_12 ( V_6 ) ) {
case V_31 :
V_22 = L_5 ;
break;
case V_15 :
V_22 = L_6 ;
break;
default:
V_22 = L_7 ;
break;
}
break;
case V_32 :
V_26 = F_13 ( V_6 , sizeof( * V_26 ) ) ;
if ( V_26 ) {
switch ( F_14 ( V_26 -> V_33 ) ) {
case V_34 :
V_22 = L_8 ;
break;
case V_35 :
V_22 = L_9 ;
break;
default:
V_22 = L_10 ;
break;
}
} else {
V_22 = L_11 ;
}
break;
default:
V_22 = L_12 ;
break;
}
}
return V_22 ;
}
