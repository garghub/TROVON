struct V_1 * F_1 ( enum V_2 V_3 ,
struct V_4 * V_5 ,
void * V_6 )
{
struct V_7 * V_8 ;
const struct V_9 * V_10 ;
if ( V_3 >= V_11 )
return NULL ;
V_10 = V_12 [ V_3 ] ;
if ( ! V_10 )
return NULL ;
V_8 = V_10 -> V_13 ( V_5 , V_6 ) ;
if ( ! V_8 )
return NULL ;
V_8 -> V_3 = V_3 ;
V_8 -> V_6 = V_6 ;
V_8 -> V_5 = * V_5 ;
return & V_8 -> V_14 ;
}
void F_2 ( struct V_1 * V_14 )
{
struct V_7 * V_8 ;
if ( ! V_14 )
return;
V_8 = F_3 ( V_14 , struct V_7 , V_14 ) ;
V_8 -> V_5 . V_15 -> V_16 ( V_8 -> V_6 ) ;
V_12 [ V_8 -> V_3 ] -> free ( V_8 ) ;
}
