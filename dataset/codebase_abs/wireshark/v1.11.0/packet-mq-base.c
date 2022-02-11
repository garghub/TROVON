T_1 F_1 ( T_2 * V_1 , T_3 V_2 , T_3 V_3 )
{
T_1 V_4 ;
if ( V_3 & V_5 )
V_4 = F_2 ( V_1 , V_2 ) ;
else
V_4 = F_3 ( V_1 , V_2 ) ;
return V_4 ;
}
T_4 F_4 ( T_2 * V_1 , T_3 V_2 , T_3 V_3 )
{
T_4 V_4 ;
if ( V_3 & V_5 )
V_4 = F_5 ( V_1 , V_2 ) ;
else
V_4 = F_6 ( V_1 , V_2 ) ;
return V_4 ;
}
T_5 F_7 ( T_2 * V_1 , T_3 V_2 , T_3 V_3 )
{
T_5 V_6 ;
if ( V_3 & V_5 )
V_6 = F_8 ( V_1 , V_2 ) ;
else
V_6 = F_9 ( V_1 , V_2 ) ;
return V_6 ;
}
T_4 F_10 ( T_6 * V_7 , T_4 V_8 )
{
T_7 V_9 = 0 ;
if ( V_7 != NULL )
{
for ( V_9 = V_8 - 1 ; V_9 >= 0 ; V_9 -- )
{
if ( V_7 [ V_9 ] != ' ' && V_7 [ V_9 ] != '\0' )
break;
else
V_7 [ V_9 ] = '\0' ;
}
}
return V_9 ;
}
