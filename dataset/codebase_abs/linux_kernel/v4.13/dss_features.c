int F_1 ( void )
{
return V_1 -> V_2 ;
}
int F_2 ( void )
{
return V_1 -> V_3 ;
}
unsigned long F_3 ( enum V_4 V_5 )
{
return V_1 -> V_6 [ V_5 ] . V_7 ;
}
unsigned long F_4 ( enum V_4 V_5 )
{
return V_1 -> V_6 [ V_5 ] . V_8 ;
}
enum V_9 F_5 ( enum V_10 V_11 )
{
return V_1 -> V_12 [ V_11 ] ;
}
enum V_13 F_6 ( enum V_10 V_11 )
{
return V_1 -> V_14 [ V_11 ] ;
}
const T_1 * F_7 ( enum V_15 V_16 )
{
return V_1 -> V_17 [ V_16 ] ;
}
enum V_18 F_8 ( enum V_15 V_16 )
{
return V_1 -> V_19 [ V_16 ] ;
}
bool F_9 ( enum V_15 V_16 , T_1 V_20 )
{
const T_1 * V_21 ;
unsigned int V_22 ;
V_21 = V_1 -> V_17 [ V_16 ] ;
for ( V_22 = 0 ; V_21 [ V_22 ] ; ++ V_22 ) {
if ( V_21 [ V_22 ] == V_20 )
return true ;
}
return false ;
}
T_1 F_10 ( void )
{
return V_1 -> V_23 ;
}
T_1 F_11 ( void )
{
return V_1 -> V_24 ;
}
bool F_12 ( enum V_25 V_26 )
{
int V_22 ;
const enum V_25 * V_27 = V_1 -> V_27 ;
const int V_28 = V_1 -> V_28 ;
for ( V_22 = 0 ; V_22 < V_28 ; V_22 ++ ) {
if ( V_27 [ V_22 ] == V_26 )
return true ;
}
return false ;
}
void F_13 ( enum V_29 V_26 , T_2 * V_30 , T_2 * V_31 )
{
if ( V_26 >= V_1 -> V_32 )
F_14 () ;
* V_30 = V_1 -> V_33 [ V_26 ] . V_30 ;
* V_31 = V_1 -> V_33 [ V_26 ] . V_31 ;
}
void F_15 ( enum V_34 V_35 )
{
switch ( V_35 ) {
case V_36 :
V_1 = & V_37 ;
break;
case V_38 :
case V_39 :
V_1 = & V_40 ;
break;
case V_41 :
V_1 = & V_42 ;
break;
case V_43 :
V_1 = & V_44 ;
break;
case V_45 :
V_1 = & V_46 ;
break;
case V_47 :
V_1 = & V_48 ;
break;
case V_49 :
case V_50 :
V_1 = & V_51 ;
break;
case V_52 :
V_1 = & V_53 ;
break;
case V_54 :
V_1 = & V_55 ;
break;
default:
F_16 ( L_1 ) ;
break;
}
}
