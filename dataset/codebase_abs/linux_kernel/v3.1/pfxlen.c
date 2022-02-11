T_1
F_1 ( T_1 V_1 , T_1 V_2 , T_2 * V_3 )
{
T_1 V_4 ;
T_2 V_5 ;
for ( V_5 = 1 ; V_5 < 32 ; V_5 ++ ) {
if ( ( V_1 & F_2 ( V_5 ) ) != V_1 )
continue;
V_4 = V_1 | ~ F_2 ( V_5 ) ;
if ( ! F_3 ( V_4 , V_2 ) ) {
* V_3 = V_5 ;
return V_4 ;
}
}
* V_3 = 32 ;
return V_1 ;
}
