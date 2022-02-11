T_1 * F_1 ( T_1 * V_1 , T_2 V_2 )
{
if ( V_2 & V_3 )
{
T_2 V_4 = ( V_2 & ~ V_3 ) + V_5 ;
if ( V_4 < ( V_6 + V_5 ) &&
V_7 [ V_4 ] . V_2 == V_2 )
{
return & V_7 [ V_4 ] ;
}
}
else
{
if ( V_2 < V_5 &&
V_7 [ V_2 ] . V_2 == V_2 )
{
return & V_7 [ V_2 ] ;
}
}
return NULL ;
}
void F_2 ( void )
{
F_3 ( V_8 , V_7 ) ;
F_4 ( V_8 , F_1 ) ;
}
const T_3 * F_5 ( void )
{
return & V_9 ;
}
