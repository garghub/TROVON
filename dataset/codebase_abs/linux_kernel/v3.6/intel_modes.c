int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_3 )
{
int V_4 ;
F_2 ( V_2 , V_3 ) ;
V_4 = F_3 ( V_2 , V_3 ) ;
F_4 ( V_2 , V_3 ) ;
V_2 -> V_5 . V_6 = NULL ;
F_5 ( V_3 ) ;
return V_4 ;
}
int F_6 ( struct V_1 * V_2 ,
struct V_7 * V_8 )
{
struct V_3 * V_3 ;
V_3 = F_7 ( V_2 , V_8 ) ;
if ( ! V_3 )
return 0 ;
return F_1 ( V_2 , V_3 ) ;
}
void
F_8 ( struct V_1 * V_2 )
{
struct V_9 * V_10 = V_2 -> V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
struct V_14 * V_15 ;
V_15 = V_12 -> V_16 ;
if ( V_15 == NULL ) {
V_15 = F_9 ( V_10 , 0 ,
L_1 ,
V_17 ,
F_10 ( V_17 ) ) ;
if ( V_15 == NULL )
return;
V_12 -> V_16 = V_15 ;
}
F_11 ( V_2 , V_15 , 0 ) ;
}
void
F_12 ( struct V_1 * V_2 )
{
struct V_9 * V_10 = V_2 -> V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
struct V_14 * V_15 ;
V_15 = V_12 -> V_18 ;
if ( V_15 == NULL ) {
V_15 = F_9 ( V_10 , V_19 ,
L_2 ,
V_20 ,
F_10 ( V_20 ) ) ;
if ( V_15 == NULL )
return;
V_12 -> V_18 = V_15 ;
}
F_11 ( V_2 , V_15 , 0 ) ;
}
