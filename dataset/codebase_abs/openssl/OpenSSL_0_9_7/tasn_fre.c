void F_1 ( T_1 * V_1 , const T_2 * V_2 )
{
F_2 ( & V_1 , V_2 , 0 ) ;
}
void F_3 ( T_1 * * V_3 , const T_2 * V_2 )
{
F_2 ( V_3 , V_2 , 0 ) ;
}
static void F_2 ( T_1 * * V_3 , const T_2 * V_2 , int V_4 )
{
const T_3 * V_5 = NULL , * V_6 ;
const T_4 * V_7 ;
const T_5 * V_8 ;
const T_6 * V_9 = V_2 -> V_10 ;
T_7 * V_11 ;
int V_12 ;
if( ! V_3 ) return;
if( ( V_2 -> V_13 != V_14 ) && ! * V_3 ) return;
if( V_9 && V_9 -> V_11 ) V_11 = V_9 -> V_11 ;
else V_11 = 0 ;
switch( V_2 -> V_13 ) {
case V_14 :
if( V_2 -> V_15 ) F_4 ( V_3 , V_2 -> V_15 ) ;
else F_5 ( V_3 , V_2 ) ;
break;
case V_16 :
F_5 ( V_3 , V_2 ) ;
break;
case V_17 :
if( V_11 ) {
V_12 = V_11 ( V_18 , V_3 , V_2 ) ;
if( V_12 == 2 ) return;
}
V_12 = F_6 ( V_3 , V_2 ) ;
if( V_11 ) V_11 ( V_18 , V_3 , V_2 ) ;
if( ( V_12 >= 0 ) && ( V_12 < V_2 -> V_19 ) ) {
T_1 * * V_20 ;
V_5 = V_2 -> V_15 + V_12 ;
V_20 = F_7 ( V_3 , V_5 ) ;
F_4 ( V_20 , V_5 ) ;
}
if( V_11 ) V_11 ( V_21 , V_3 , V_2 ) ;
if( ! V_4 ) {
F_8 ( * V_3 ) ;
* V_3 = NULL ;
}
break;
case V_22 :
V_8 = V_2 -> V_10 ;
if( V_8 && V_8 -> V_23 ) V_8 -> V_23 ( * V_3 ) ;
break;
case V_24 :
V_7 = V_2 -> V_10 ;
if( V_7 && V_7 -> V_25 ) V_7 -> V_25 ( V_3 , V_2 ) ;
break;
case V_26 :
if( F_9 ( V_3 , - 1 , V_2 ) > 0 ) return;
if( V_11 ) {
V_12 = V_11 ( V_18 , V_3 , V_2 ) ;
if( V_12 == 2 ) return;
}
F_10 ( V_3 , V_2 ) ;
V_5 = V_2 -> V_15 + V_2 -> V_19 - 1 ;
for( V_12 = 0 ; V_12 < V_2 -> V_19 ; V_5 -- , V_12 ++ ) {
T_1 * * V_27 ;
V_6 = F_11 ( V_3 , V_5 , 0 ) ;
if( ! V_6 ) continue;
V_27 = F_7 ( V_3 , V_6 ) ;
F_4 ( V_27 , V_6 ) ;
}
if( V_11 ) V_11 ( V_21 , V_3 , V_2 ) ;
if( ! V_4 ) {
F_8 ( * V_3 ) ;
* V_3 = NULL ;
}
break;
}
}
void F_4 ( T_1 * * V_3 , const T_3 * V_5 )
{
int V_12 ;
if( V_5 -> V_28 & V_29 ) {
F_12 ( T_1 ) * V_30 = ( F_12 ( T_1 ) * ) * V_3 ;
for( V_12 = 0 ; V_12 < F_13 ( V_30 ) ; V_12 ++ ) {
T_1 * V_31 ;
V_31 = F_14 ( V_30 , V_12 ) ;
F_2 ( & V_31 , F_15 ( V_5 -> V_32 ) , 0 ) ;
}
F_16 ( V_30 ) ;
* V_3 = NULL ;
} else F_2 ( V_3 , F_15 ( V_5 -> V_32 ) ,
V_5 -> V_28 & V_33 ) ;
}
void F_5 ( T_1 * * V_3 , const T_2 * V_2 )
{
int V_34 ;
if( V_2 ) {
const T_8 * V_35 ;
V_35 = V_2 -> V_10 ;
if( V_35 && V_35 -> V_36 ) {
V_35 -> V_36 ( V_3 , V_2 ) ;
return;
}
}
if( ! V_2 ) {
T_9 * V_37 = ( T_9 * ) * V_3 ;
V_34 = V_37 -> type ;
V_3 = ( T_1 * * ) & V_37 -> V_38 . V_39 ;
if( ! * V_3 ) return;
} else if( V_2 -> V_13 == V_16 ) {
V_34 = - 1 ;
if( ! * V_3 ) return;
} else {
V_34 = V_2 -> V_34 ;
if( ( V_34 != V_40 ) && ! * V_3 ) return;
}
switch( V_34 ) {
case V_41 :
F_17 ( ( V_42 * ) * V_3 ) ;
break;
case V_40 :
if ( V_2 )
* ( V_43 * ) V_3 = V_2 -> V_44 ;
else
* ( V_43 * ) V_3 = - 1 ;
return;
case V_45 :
break;
case V_46 :
F_5 ( V_3 , NULL ) ;
F_8 ( * V_3 ) ;
break;
default:
F_18 ( ( V_47 * ) * V_3 ) ;
* V_3 = NULL ;
break;
}
* V_3 = NULL ;
}
