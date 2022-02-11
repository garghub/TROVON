T_1 F_1 ( T_2 * V_1 , T_3 V_2 )
{
T_1 V_3 = 0 ;
if ( V_1 != NULL )
{
for ( V_3 = V_2 - 1 ; V_3 >= 0 ; V_3 -- )
{
if ( V_1 [ V_3 ] != ' ' && V_1 [ V_3 ] != '\0' )
break;
else
V_1 [ V_3 ] = '\0' ;
}
}
return V_3 ;
}
