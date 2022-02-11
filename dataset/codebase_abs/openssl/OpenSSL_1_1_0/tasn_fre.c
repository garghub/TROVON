void F_1 ( T_1 * V_1 , const T_2 * V_2 )
{
F_2 ( & V_1 , V_2 , 0 ) ;
}
void F_3 ( T_1 * * V_3 , const T_2 * V_2 )
{
F_2 ( V_3 , V_2 , 0 ) ;
}
static void F_2 ( T_1 * * V_3 , const T_2 * V_2 ,
int V_4 )
{
const T_3 * V_5 = NULL , * V_6 ;
const T_4 * V_7 ;
const T_5 * V_8 = V_2 -> V_9 ;
T_6 * V_10 ;
int V_11 ;
if ( ! V_3 )
return;
if ( ( V_2 -> V_12 != V_13 ) && ! * V_3 )
return;
if ( V_8 && V_8 -> V_10 )
V_10 = V_8 -> V_10 ;
else
V_10 = 0 ;
switch ( V_2 -> V_12 ) {
case V_13 :
if ( V_2 -> V_14 )
F_4 ( V_3 , V_2 -> V_14 ) ;
else
F_5 ( V_3 , V_2 ) ;
break;
case V_15 :
F_5 ( V_3 , V_2 ) ;
break;
case V_16 :
if ( V_10 ) {
V_11 = V_10 ( V_17 , V_3 , V_2 , NULL ) ;
if ( V_11 == 2 )
return;
}
V_11 = F_6 ( V_3 , V_2 ) ;
if ( ( V_11 >= 0 ) && ( V_11 < V_2 -> V_18 ) ) {
T_1 * * V_19 ;
V_5 = V_2 -> V_14 + V_11 ;
V_19 = F_7 ( V_3 , V_5 ) ;
F_4 ( V_19 , V_5 ) ;
}
if ( V_10 )
V_10 ( V_20 , V_3 , V_2 , NULL ) ;
if ( V_4 == 0 ) {
F_8 ( * V_3 ) ;
* V_3 = NULL ;
}
break;
case V_21 :
V_7 = V_2 -> V_9 ;
if ( V_7 && V_7 -> V_22 )
V_7 -> V_22 ( V_3 , V_2 ) ;
break;
case V_23 :
case V_24 :
if ( F_9 ( V_3 , - 1 , V_2 ) != 0 )
return;
if ( V_10 ) {
V_11 = V_10 ( V_17 , V_3 , V_2 , NULL ) ;
if ( V_11 == 2 )
return;
}
F_10 ( V_3 , V_2 ) ;
V_5 = V_2 -> V_14 + V_2 -> V_18 ;
for ( V_11 = 0 ; V_11 < V_2 -> V_18 ; V_11 ++ ) {
T_1 * * V_25 ;
V_5 -- ;
V_6 = F_11 ( V_3 , V_5 , 0 ) ;
if ( ! V_6 )
continue;
V_25 = F_7 ( V_3 , V_6 ) ;
F_4 ( V_25 , V_6 ) ;
}
if ( V_10 )
V_10 ( V_20 , V_3 , V_2 , NULL ) ;
if ( V_4 == 0 ) {
F_8 ( * V_3 ) ;
* V_3 = NULL ;
}
break;
}
}
void F_4 ( T_1 * * V_3 , const T_3 * V_5 )
{
int V_4 = V_5 -> V_26 & V_27 ;
T_1 * V_28 ;
if ( V_4 ) {
V_28 = ( T_1 * ) V_3 ;
V_3 = & V_28 ;
}
if ( V_5 -> V_26 & V_29 ) {
F_12 ( T_1 ) * V_30 = ( F_12 ( T_1 ) * ) * V_3 ;
int V_11 ;
for ( V_11 = 0 ; V_11 < F_13 ( V_30 ) ; V_11 ++ ) {
T_1 * V_31 = F_14 ( V_30 , V_11 ) ;
F_2 ( & V_31 , F_15 ( V_5 -> V_32 ) , V_4 ) ;
}
F_16 ( V_30 ) ;
* V_3 = NULL ;
} else {
F_2 ( V_3 , F_15 ( V_5 -> V_32 ) , V_4 ) ;
}
}
void F_5 ( T_1 * * V_3 , const T_2 * V_2 )
{
int V_33 ;
if ( V_2 ) {
const T_7 * V_34 = V_2 -> V_9 ;
if ( V_34 && V_34 -> V_35 ) {
V_34 -> V_35 ( V_3 , V_2 ) ;
return;
}
}
if ( ! V_2 ) {
T_8 * V_36 = ( T_8 * ) * V_3 ;
V_33 = V_36 -> type ;
V_3 = & V_36 -> V_37 . V_38 ;
if ( ! * V_3 )
return;
} else if ( V_2 -> V_12 == V_15 ) {
V_33 = - 1 ;
if ( ! * V_3 )
return;
} else {
V_33 = V_2 -> V_33 ;
if ( ( V_33 != V_39 ) && ! * V_3 )
return;
}
switch ( V_33 ) {
case V_40 :
F_17 ( ( V_41 * ) * V_3 ) ;
break;
case V_39 :
if ( V_2 )
* ( V_42 * ) V_3 = V_2 -> V_43 ;
else
* ( V_42 * ) V_3 = - 1 ;
return;
case V_44 :
break;
case V_45 :
F_5 ( V_3 , NULL ) ;
F_8 ( * V_3 ) ;
break;
default:
F_18 ( ( V_46 * ) * V_3 ) ;
break;
}
* V_3 = NULL ;
}
