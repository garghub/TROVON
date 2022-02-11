int F_1 ( struct V_1 * V_2 )
{
const struct V_3 * V_4 ;
const struct V_5 * V_6 ;
const char * V_7 ;
int V_8 ;
for ( V_4 = F_2 ( V_9 ) ;
V_4 ;
V_4 = F_2 ( V_4 + 1 ) ) {
V_6 = V_4 -> V_10 ;
if ( V_6 -> V_11 != V_2 -> V_12 . V_13 ||
V_6 -> V_14 != V_2 -> V_12 . V_15 )
continue;
if ( ! V_6 -> V_16 )
return V_6 -> V_17 ;
V_7 = F_3 ( V_18 ) ;
if ( ! V_7 )
continue;
for ( V_8 = 0 ; V_6 -> V_16 [ V_8 ] ; V_8 ++ ) {
if ( ! strcmp ( V_6 -> V_16 [ V_8 ] , V_7 ) )
return V_6 -> V_17 ;
}
}
return V_19 ;
}
