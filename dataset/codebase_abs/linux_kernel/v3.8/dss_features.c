void F_1 ( struct V_1 * V_2 ,
enum V_3 V_4 )
{
switch ( V_4 ) {
case V_5 :
case V_6 :
case V_7 :
V_2 -> V_8 = & V_9 ;
break;
default:
V_2 -> V_8 = NULL ;
}
F_2 ( V_2 -> V_8 == NULL ) ;
}
int F_3 ( void )
{
return V_10 -> V_11 ;
}
int F_4 ( void )
{
return V_10 -> V_12 ;
}
int F_5 ( void )
{
return V_10 -> V_13 ;
}
unsigned long F_6 ( enum V_14 V_15 )
{
return V_10 -> V_16 [ V_15 ] . V_17 ;
}
unsigned long F_7 ( enum V_14 V_15 )
{
return V_10 -> V_16 [ V_15 ] . V_18 ;
}
enum V_19 F_8 ( enum V_20 V_21 )
{
return V_10 -> V_22 [ V_21 ] ;
}
enum V_23 F_9 ( enum V_20 V_21 )
{
return V_10 -> V_24 [ V_21 ] ;
}
enum V_25 F_10 ( enum V_26 V_27 )
{
return V_10 -> V_28 [ V_27 ] ;
}
enum V_29 F_11 ( enum V_26 V_27 )
{
return V_10 -> V_30 [ V_27 ] ;
}
bool F_12 ( enum V_26 V_27 ,
enum V_25 V_31 )
{
return V_10 -> V_28 [ V_27 ] &
V_31 ;
}
const char * F_13 ( enum V_32 V_33 )
{
return V_10 -> V_34 [ V_33 ] ;
}
T_1 F_14 ( void )
{
return V_10 -> V_35 ;
}
T_1 F_15 ( void )
{
return V_10 -> V_36 ;
}
bool F_16 ( enum V_37 V_33 )
{
int V_38 ;
const enum V_37 * V_39 = V_10 -> V_39 ;
const int V_40 = V_10 -> V_40 ;
for ( V_38 = 0 ; V_38 < V_40 ; V_38 ++ ) {
if ( V_39 [ V_38 ] == V_33 )
return true ;
}
return false ;
}
void F_17 ( enum V_41 V_33 , T_2 * V_42 , T_2 * V_43 )
{
if ( V_33 >= V_10 -> V_44 )
F_18 () ;
* V_42 = V_10 -> V_45 [ V_33 ] . V_42 ;
* V_43 = V_10 -> V_45 [ V_33 ] . V_43 ;
}
bool F_19 ( enum V_46 V_47 )
{
return V_10 -> V_48 & V_47 ;
}
void F_20 ( enum V_3 V_4 )
{
switch ( V_4 ) {
case V_49 :
V_10 = & V_50 ;
break;
case V_51 :
case V_52 :
V_10 = & V_53 ;
break;
case V_54 :
V_10 = & V_55 ;
break;
case V_5 :
V_10 = & V_56 ;
break;
case V_6 :
V_10 = & V_57 ;
break;
case V_7 :
V_10 = & V_58 ;
break;
case V_59 :
V_10 = & V_60 ;
break;
case V_61 :
V_10 = & V_62 ;
break;
default:
F_21 ( L_1 ) ;
break;
}
}
