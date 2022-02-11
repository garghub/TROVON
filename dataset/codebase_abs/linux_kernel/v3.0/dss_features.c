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
enum V_13 F_6 ( enum V_14 V_15 )
{
return V_1 -> V_16 [ V_15 ] ;
}
bool F_7 ( enum V_14 V_15 ,
enum V_13 V_17 )
{
return V_1 -> V_16 [ V_15 ] &
V_17 ;
}
const char * F_8 ( enum V_18 V_19 )
{
return V_1 -> V_20 [ V_19 ] ;
}
bool F_9 ( enum V_21 V_19 )
{
return V_1 -> V_22 & V_19 ;
}
void F_10 ( enum V_23 V_19 , T_1 * V_24 , T_1 * V_25 )
{
if ( V_19 >= V_1 -> V_26 )
F_11 () ;
* V_24 = V_1 -> V_27 [ V_19 ] . V_24 ;
* V_25 = V_1 -> V_27 [ V_19 ] . V_25 ;
}
void F_12 ( void )
{
if ( F_13 () )
V_1 = & V_28 ;
else if ( F_14 () )
V_1 = & V_29 ;
else if ( F_15 () )
V_1 = & V_30 ;
else if ( F_16 () == V_31 )
V_1 = & V_32 ;
else if ( F_17 () )
V_1 = & V_33 ;
else
F_18 ( L_1 ) ;
}
