int F_1 ( void )
{
return V_1 -> V_2 ;
}
int F_2 ( void )
{
return V_1 -> V_3 ;
}
int F_3 ( void )
{
return V_1 -> V_4 ;
}
unsigned long F_4 ( enum V_5 V_6 )
{
return V_1 -> V_7 [ V_6 ] . V_8 ;
}
unsigned long F_5 ( enum V_5 V_6 )
{
return V_1 -> V_7 [ V_6 ] . V_9 ;
}
enum V_10 F_6 ( enum V_11 V_12 )
{
return V_1 -> V_13 [ V_12 ] ;
}
enum V_14 F_7 ( enum V_11 V_12 )
{
return V_1 -> V_15 [ V_12 ] ;
}
enum V_16 F_8 ( enum V_17 V_18 )
{
return V_1 -> V_19 [ V_18 ] ;
}
enum V_20 F_9 ( enum V_17 V_18 )
{
return V_1 -> V_21 [ V_18 ] ;
}
bool F_10 ( enum V_17 V_18 ,
enum V_16 V_22 )
{
return V_1 -> V_19 [ V_18 ] &
V_22 ;
}
const char * F_11 ( enum V_23 V_24 )
{
return V_1 -> V_25 [ V_24 ] ;
}
T_1 F_12 ( void )
{
return V_1 -> V_26 ;
}
T_1 F_13 ( void )
{
return V_1 -> V_27 ;
}
bool F_14 ( enum V_28 V_24 )
{
int V_29 ;
const enum V_28 * V_30 = V_1 -> V_30 ;
const int V_31 = V_1 -> V_31 ;
for ( V_29 = 0 ; V_29 < V_31 ; V_29 ++ ) {
if ( V_30 [ V_29 ] == V_24 )
return true ;
}
return false ;
}
void F_15 ( enum V_32 V_24 , T_2 * V_33 , T_2 * V_34 )
{
if ( V_24 >= V_1 -> V_35 )
F_16 () ;
* V_33 = V_1 -> V_36 [ V_24 ] . V_33 ;
* V_34 = V_1 -> V_36 [ V_24 ] . V_34 ;
}
bool F_17 ( enum V_37 V_38 )
{
return V_1 -> V_39 & V_38 ;
}
void F_18 ( enum V_40 V_41 )
{
switch ( V_41 ) {
case V_42 :
V_1 = & V_43 ;
break;
case V_44 :
case V_45 :
V_1 = & V_46 ;
break;
case V_47 :
V_1 = & V_48 ;
break;
case V_49 :
V_1 = & V_50 ;
break;
case V_51 :
V_1 = & V_52 ;
break;
case V_53 :
V_1 = & V_54 ;
break;
case V_55 :
case V_56 :
V_1 = & V_57 ;
break;
case V_58 :
V_1 = & V_59 ;
break;
case V_60 :
V_1 = & V_61 ;
break;
default:
F_19 ( L_1 ) ;
break;
}
}
