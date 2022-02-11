void F_1 ( struct V_1 * V_2 )
{
if ( F_2 () )
V_2 -> V_3 = & V_4 ;
}
int F_3 ( void )
{
return V_5 -> V_6 ;
}
int F_4 ( void )
{
return V_5 -> V_7 ;
}
unsigned long F_5 ( enum V_8 V_9 )
{
return V_5 -> V_10 [ V_9 ] . V_11 ;
}
unsigned long F_6 ( enum V_8 V_9 )
{
return V_5 -> V_10 [ V_9 ] . V_12 ;
}
enum V_13 F_7 ( enum V_14 V_15 )
{
return V_5 -> V_16 [ V_15 ] ;
}
enum V_17 F_8 ( enum V_18 V_19 )
{
return V_5 -> V_20 [ V_19 ] ;
}
enum V_21 F_9 ( enum V_18 V_19 )
{
return V_5 -> V_22 [ V_19 ] ;
}
bool F_10 ( enum V_18 V_19 ,
enum V_17 V_23 )
{
return V_5 -> V_20 [ V_19 ] &
V_23 ;
}
const char * F_11 ( enum V_24 V_25 )
{
return V_5 -> V_26 [ V_25 ] ;
}
T_1 F_12 ( void )
{
return V_5 -> V_27 ;
}
T_1 F_13 ( void )
{
return V_5 -> V_28 ;
}
bool F_14 ( enum V_29 V_25 )
{
int V_30 ;
const enum V_29 * V_31 = V_5 -> V_31 ;
const int V_32 = V_5 -> V_32 ;
for ( V_30 = 0 ; V_30 < V_32 ; V_30 ++ ) {
if ( V_31 [ V_30 ] == V_25 )
return true ;
}
return false ;
}
void F_15 ( enum V_33 V_25 , T_2 * V_34 , T_2 * V_35 )
{
if ( V_25 >= V_5 -> V_36 )
F_16 () ;
* V_34 = V_5 -> V_37 [ V_25 ] . V_34 ;
* V_35 = V_5 -> V_37 [ V_25 ] . V_35 ;
}
void F_17 ( void )
{
if ( F_18 () )
V_5 = & V_38 ;
else if ( F_19 () )
V_5 = & V_39 ;
else if ( F_20 () )
V_5 = & V_40 ;
else if ( F_21 () == V_41 )
V_5 = & V_42 ;
else if ( F_21 () == V_43 ||
F_21 () == V_44 ||
F_21 () == V_45 )
V_5 = & V_46 ;
else if ( F_2 () )
V_5 = & V_47 ;
else
F_22 ( L_1 ) ;
}
