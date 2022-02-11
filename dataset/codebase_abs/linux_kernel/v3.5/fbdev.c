int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_3 = V_2 -> V_3 ;
struct V_4 * V_4 = NULL ;
struct V_4 * V_5 = F_2 () ;
struct V_6 * V_7 = NULL ;
if ( V_3 )
V_4 = F_3 ( V_3 ) ;
if ( ! V_4 )
return 0 ;
if ( V_5 ) {
if ( V_4 == V_5 )
return 1 ;
else
return 0 ;
}
V_7 = & V_4 -> V_6 [ V_8 ] ;
if ( V_7 && V_7 -> V_9 & V_10 )
return 1 ;
return 0 ;
}
