void F_1 ( T_1 V_1 )
{
for (; V_1 -> V_2 && ! V_1 -> V_3 [ V_1 -> V_2 - 1 ] ; V_1 -> V_2 -- )
;
}
unsigned F_2 ( T_1 V_1 )
{
unsigned V_4 ;
F_1 ( V_1 ) ;
if ( V_1 -> V_2 ) {
T_2 V_5 = V_1 -> V_3 [ V_1 -> V_2 - 1 ] ;
if ( V_5 )
V_4 = F_3 ( V_5 ) ;
else
V_4 = V_6 ;
V_4 = V_6 - V_4 + ( V_1 -> V_2 - 1 ) * V_6 ;
} else
V_4 = 0 ;
return V_4 ;
}
