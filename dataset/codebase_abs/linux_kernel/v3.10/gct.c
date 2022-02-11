int
F_1 ( T_1 * V_1 , T_2 * V_2 )
{
T_2 * V_3 ;
int V_4 = 0 ;
if ( V_1 -> V_5 != V_6 ) {
F_2 ( V_7 L_1 ) ;
return - V_8 ;
}
for ( V_3 = V_2 ;
V_3 && ( V_3 -> type | V_3 -> V_9 ) ;
V_3 ++ ) {
if ( V_1 -> type != V_3 -> type )
continue;
if ( V_1 -> V_9 != V_3 -> V_9 )
continue;
if ( V_3 -> V_10 )
V_3 -> V_10 ( V_1 ) ;
}
if ( V_1 -> V_11 )
V_4 |= F_1 ( F_3 ( V_1 -> V_11 ) , V_2 ) ;
if ( V_1 -> V_12 )
V_4 |= F_1 ( F_3 ( V_1 -> V_12 ) , V_2 ) ;
return V_4 ;
}
