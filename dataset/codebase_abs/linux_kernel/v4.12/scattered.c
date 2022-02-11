void F_1 ( struct V_1 * V_2 )
{
T_1 V_3 ;
T_1 V_4 [ 4 ] ;
const struct V_5 * V_6 ;
for ( V_6 = V_7 ; V_6 -> V_8 ; V_6 ++ ) {
V_3 = F_2 ( V_6 -> V_9 & 0xffff0000 ) ;
if ( V_3 < V_6 -> V_9 ||
V_3 > ( V_6 -> V_9 | 0xffff ) )
continue;
F_3 ( V_6 -> V_9 , V_6 -> V_10 , & V_4 [ V_11 ] ,
& V_4 [ V_12 ] , & V_4 [ V_13 ] ,
& V_4 [ V_14 ] ) ;
if ( V_4 [ V_6 -> V_15 ] & ( 1 << V_6 -> V_16 ) )
F_4 ( V_2 , V_6 -> V_8 ) ;
}
}
T_1 F_5 ( unsigned int V_9 , unsigned int V_10 ,
enum V_17 V_15 )
{
const struct V_5 * V_6 ;
T_1 V_18 = 0 ;
for ( V_6 = V_7 ; V_6 -> V_8 ; V_6 ++ ) {
if ( V_9 > V_6 -> V_9 )
continue;
if ( V_9 < V_6 -> V_9 )
break;
if ( V_15 == V_6 -> V_15 && V_10 == V_6 -> V_10 ) {
if ( F_6 ( & V_19 , V_6 -> V_8 ) )
V_18 |= F_7 ( V_6 -> V_16 ) ;
}
}
return V_18 ;
}
