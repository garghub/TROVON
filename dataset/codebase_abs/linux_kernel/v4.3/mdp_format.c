T_1 F_1 ( T_1 * V_1 , T_1 V_2 ,
bool V_3 )
{
T_1 V_4 ;
for ( V_4 = 0 ; V_4 < F_2 ( V_5 ) ; V_4 ++ ) {
const struct V_6 * V_7 = & V_5 [ V_4 ] ;
if ( V_4 == V_2 )
break;
if ( V_3 && F_3 ( V_7 ) )
break;
V_1 [ V_4 ] = V_7 -> V_8 . V_9 ;
}
return V_4 ;
}
const struct V_10 * F_4 ( struct V_11 * V_12 , T_1 V_13 )
{
int V_4 ;
for ( V_4 = 0 ; V_4 < F_2 ( V_5 ) ; V_4 ++ ) {
const struct V_6 * V_7 = & V_5 [ V_4 ] ;
if ( V_7 -> V_8 . V_9 == V_13 )
return & V_7 -> V_8 ;
}
return NULL ;
}
struct V_14 * F_5 ( enum V_15 type )
{
if ( F_6 ( F_7 ( type >= V_16 ) ) )
return NULL ;
return & V_17 [ type ] ;
}
