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
enum V_15 F_7 ( enum V_16 V_17 )
{
return V_1 -> V_18 [ V_17 ] ;
}
enum V_19 F_8 ( enum V_16 V_17 )
{
return V_1 -> V_20 [ V_17 ] ;
}
bool F_9 ( enum V_16 V_17 ,
enum V_15 V_21 )
{
return V_1 -> V_18 [ V_17 ] &
V_21 ;
}
T_1 F_10 ( void )
{
return V_1 -> V_22 ;
}
T_1 F_11 ( void )
{
return V_1 -> V_23 ;
}
bool F_12 ( enum V_24 V_25 )
{
int V_26 ;
const enum V_24 * V_27 = V_1 -> V_27 ;
const int V_28 = V_1 -> V_28 ;
for ( V_26 = 0 ; V_26 < V_28 ; V_26 ++ ) {
if ( V_27 [ V_26 ] == V_25 )
return true ;
}
return false ;
}
void F_13 ( enum V_29 V_25 , T_2 * V_30 , T_2 * V_31 )
{
if ( V_25 >= V_1 -> V_32 )
F_14 () ;
* V_30 = V_1 -> V_33 [ V_25 ] . V_30 ;
* V_31 = V_1 -> V_33 [ V_25 ] . V_31 ;
}
bool F_15 ( enum V_34 V_35 )
{
return V_1 -> V_36 & V_35 ;
}
void F_16 ( enum V_37 V_38 )
{
switch ( V_38 ) {
case V_39 :
V_1 = & V_40 ;
break;
case V_41 :
case V_42 :
V_1 = & V_43 ;
break;
case V_44 :
V_1 = & V_45 ;
break;
case V_46 :
V_1 = & V_47 ;
break;
case V_48 :
V_1 = & V_49 ;
break;
case V_50 :
V_1 = & V_51 ;
break;
case V_52 :
case V_53 :
V_1 = & V_54 ;
break;
case V_55 :
V_1 = & V_56 ;
break;
case V_57 :
V_1 = & V_58 ;
break;
default:
F_17 ( L_1 ) ;
break;
}
}
