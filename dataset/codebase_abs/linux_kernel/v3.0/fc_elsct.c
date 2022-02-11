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
V_14 = F_4 ( V_3 , V_4 , V_6 , V_7 , & V_11 , & V_13 ) ;
V_4 = V_17 ;
}
if ( V_14 ) {
F_5 ( V_6 ) ;
return NULL ;
}
F_6 ( V_6 , V_11 , V_4 , V_3 -> V_18 , V_13 ,
V_19 , 0 ) ;
return V_3 -> V_20 . V_21 ( V_3 , V_6 , F_2 , NULL , V_8 , V_9 ) ;
}
int F_7 ( struct V_2 * V_3 )
{
if ( ! V_3 -> V_20 . V_22 )
V_3 -> V_20 . V_22 = F_1 ;
return 0 ;
}
const char * F_8 ( struct V_5 * V_6 )
{
const char * V_23 ;
struct V_24 * V_25 ;
struct V_26 * V_27 ;
if ( F_9 ( V_6 ) ) {
switch ( - F_10 ( V_6 ) ) {
case V_28 :
V_23 = L_1 ;
break;
case V_29 :
V_23 = L_2 ;
break;
case V_30 :
V_23 = L_3 ;
break;
default:
V_23 = L_4 ;
break;
}
} else {
V_25 = F_11 ( V_6 ) ;
switch ( V_25 -> V_13 ) {
case V_31 :
switch ( F_12 ( V_6 ) ) {
case V_32 :
V_23 = L_5 ;
break;
case V_15 :
V_23 = L_6 ;
break;
default:
V_23 = L_7 ;
break;
}
break;
case V_33 :
V_27 = F_13 ( V_6 , sizeof( * V_27 ) ) ;
if ( V_27 ) {
switch ( F_14 ( V_27 -> V_34 ) ) {
case V_35 :
V_23 = L_8 ;
break;
case V_36 :
V_23 = L_9 ;
break;
default:
V_23 = L_10 ;
break;
}
} else {
V_23 = L_11 ;
}
break;
default:
V_23 = L_12 ;
break;
}
}
return V_23 ;
}
