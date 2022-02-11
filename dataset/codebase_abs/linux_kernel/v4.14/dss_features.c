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
const char * F_10 ( enum V_22 V_23 )
{
return V_1 -> V_24 [ V_23 ] ;
}
T_1 F_11 ( void )
{
return V_1 -> V_25 ;
}
T_1 F_12 ( void )
{
return V_1 -> V_26 ;
}
bool F_13 ( enum V_27 V_23 )
{
int V_28 ;
const enum V_27 * V_29 = V_1 -> V_29 ;
const int V_30 = V_1 -> V_30 ;
for ( V_28 = 0 ; V_28 < V_30 ; V_28 ++ ) {
if ( V_29 [ V_28 ] == V_23 )
return true ;
}
return false ;
}
void F_14 ( enum V_31 V_23 , T_2 * V_32 , T_2 * V_33 )
{
if ( V_23 >= V_1 -> V_34 )
F_15 () ;
* V_32 = V_1 -> V_35 [ V_23 ] . V_32 ;
* V_33 = V_1 -> V_35 [ V_23 ] . V_33 ;
}
bool F_16 ( enum V_36 V_37 )
{
return V_1 -> V_38 & V_37 ;
}
void F_17 ( enum V_39 V_40 )
{
switch ( V_40 ) {
case V_41 :
V_1 = & V_42 ;
break;
case V_43 :
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
V_1 = & V_53 ;
break;
case V_54 :
case V_55 :
V_1 = & V_56 ;
break;
case V_57 :
V_1 = & V_58 ;
break;
case V_59 :
V_1 = & V_60 ;
break;
default:
F_18 ( L_1 ) ;
break;
}
}
