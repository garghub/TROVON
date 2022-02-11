const struct V_1 * F_1 ( T_1 V_2 , T_1 V_3 )
{
const struct V_1 * V_4 = NULL ;
int V_5 ;
for ( V_5 = F_2 ( V_6 ) - 1 ; V_5 >= 0 ; V_5 -- ) {
if ( ( V_6 [ V_5 ] . V_2 == V_2 ) &&
( V_6 [ V_5 ] . V_3 == V_3 ) ) {
V_4 = & V_6 [ V_5 ] ;
break;
}
}
return V_4 ;
}
