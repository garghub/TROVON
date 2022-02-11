void F_1 ( struct V_1 * V_2 )
{
int V_3 ;
if ( 0 == V_2 -> V_4 -> V_5 &&
0 == V_2 -> V_4 -> V_6 ) {
F_2 ( V_7
L_1
L_2
L_3
L_4
L_5 ,
V_2 -> V_8 , V_2 -> V_8 , V_2 -> V_8 , V_2 -> V_8 , V_2 -> V_8 ) ;
} else {
F_2 ( V_7
L_6
L_7
L_8
L_9 ,
V_2 -> V_8 , V_2 -> V_8 , V_2 -> V_8 , V_2 -> V_8 ) ;
}
F_2 ( V_7 L_10
L_11 , V_2 -> V_8 ) ;
for ( V_3 = 0 ; V_3 < V_9 ; V_3 ++ )
F_2 ( V_7 L_12 ,
V_2 -> V_8 , V_3 , V_10 [ V_3 ] . V_8 ) ;
}
void F_3 ( struct V_1 * V_2 )
{
switch ( V_2 -> V_11 ) {
case V_12 :
case V_13 :
case V_14 :
case V_15 :
case V_16 :
case V_17 :
case V_18 :
case V_19 :
F_4 ( V_2 , V_20 , 2 ) ;
F_4 ( V_2 , V_20 , 3 ) ;
F_5 ( 20 ) ;
F_6 ( V_2 , V_20 , 2 ) ;
F_6 ( V_2 , V_20 , 3 ) ;
break;
}
}
static void F_7 ( struct V_1 * V_2 , T_1 * V_21 )
{
struct V_22 V_23 ;
F_8 ( & V_2 -> V_24 [ 0 ] . V_25 , & V_23 ,
V_21 ) ;
switch ( V_23 . V_26 ) {
case 88001 :
case 88021 :
break;
case 88041 :
break;
case 88061 :
break;
case 89519 :
case 89609 :
break;
case 89619 :
break;
default:
F_2 ( V_7 L_13 ,
V_2 -> V_8 , V_23 . V_26 ) ;
break;
}
F_2 ( V_27 L_14 , V_2 -> V_8 ,
V_23 . V_26 ) ;
}
void F_9 ( struct V_1 * V_2 )
{
static T_1 V_28 [ 256 ] ;
if ( V_2 -> V_24 [ 0 ] . V_29 == 0 ) {
if ( F_10 ( V_2 , & V_28 [ 0 ] ,
sizeof( V_28 ) ) < 0 )
return;
}
switch ( V_2 -> V_11 ) {
case V_12 :
case V_13 :
case V_14 :
case V_15 :
case V_16 :
case V_17 :
case V_18 :
case V_19 :
F_7 ( V_2 , & V_28 [ 0 ] ) ;
break;
}
}
int F_11 ( struct V_30 * V_31 , int V_32 )
{
struct V_1 * V_2 = V_31 -> V_2 ;
struct V_33 * V_34 ;
int V_3 ;
for ( V_3 = 0 ; V_3 < V_35 ; V_3 ++ ) {
V_34 = & V_10 [ V_2 -> V_11 ] . V_34 [ V_3 ] ;
if ( V_34 -> type == V_36 )
continue;
if ( ( V_31 -> V_37 == V_34 -> V_38 ) &&
( V_32 == V_34 -> V_39 ) )
return V_34 -> V_40 ;
}
return - 1 ;
}
int F_12 ( struct V_30 * V_31 , int V_32 )
{
struct V_1 * V_2 = V_31 -> V_2 ;
struct V_33 * V_34 ;
int V_3 ;
for ( V_3 = 0 ; V_3 < V_35 ; V_3 ++ ) {
V_34 = & V_10 [ V_2 -> V_11 ] . V_34 [ V_3 ] ;
if ( V_34 -> type == V_36 )
continue;
if ( ( V_31 -> V_37 == V_34 -> V_38 ) &&
( V_32 == V_34 -> V_39 ) )
return V_34 -> V_41 ;
}
return - 1 ;
}
char * F_13 ( struct V_1 * V_2 , T_1 V_42 )
{
char * V_43 = L_15 ;
char * V_44 = L_16 ;
struct V_33 * V_34 ;
int V_3 ;
if ( V_42 == 0 )
return V_44 ;
for ( V_3 = 0 ; V_3 < V_35 ; V_3 ++ ) {
V_34 = & V_10 [ V_2 -> V_11 ] . V_34 [ V_3 ] ;
if ( V_34 -> type == V_36 )
continue;
if ( V_42 == V_34 -> V_40 )
return V_34 -> V_8 ;
}
return V_43 ;
}
