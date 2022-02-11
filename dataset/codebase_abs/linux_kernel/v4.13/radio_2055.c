void F_1 ( struct V_1 * V_2 ,
bool V_3 , bool V_4 )
{
const struct V_5 * V_6 ;
unsigned int V_7 , V_8 = 0 ;
T_1 V_9 ;
for ( V_7 = 0 ; V_7 < F_2 ( V_10 ) ; V_7 ++ ) {
V_6 = & ( V_10 [ V_7 ] ) ;
if ( ! ( V_6 -> V_11 & V_12 ) )
continue;
if ( ( V_6 -> V_11 & V_13 ) || V_4 ) {
if ( V_3 )
V_9 = V_6 -> V_3 ;
else
V_9 = V_6 -> V_14 ;
F_3 ( V_2 , V_7 , V_9 ) ;
if ( ++ V_8 % 4 == 0 )
F_4 ( V_2 , V_15 ) ;
}
}
}
const struct V_16 *
F_5 ( struct V_1 * V_2 , T_2 V_17 )
{
const struct V_16 * V_6 ;
unsigned int V_7 ;
for ( V_7 = 0 ; V_7 < F_2 ( V_18 ) ; V_7 ++ ) {
V_6 = & ( V_18 [ V_7 ] ) ;
if ( V_6 -> V_17 == V_17 )
return V_6 ;
}
return NULL ;
}
