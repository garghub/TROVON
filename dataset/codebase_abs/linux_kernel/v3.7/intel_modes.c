int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_3 )
{
int V_4 ;
F_2 ( V_2 , V_3 ) ;
V_4 = F_3 ( V_2 , V_3 ) ;
F_4 ( V_2 , V_3 ) ;
F_5 ( V_3 ) ;
return V_4 ;
}
int F_6 ( struct V_1 * V_2 ,
struct V_5 * V_6 )
{
struct V_3 * V_3 ;
V_3 = F_7 ( V_2 , V_6 ) ;
if ( ! V_3 )
return 0 ;
return F_1 ( V_2 , V_3 ) ;
}
void
F_8 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = V_2 -> V_8 ;
struct V_9 * V_10 = V_8 -> V_11 ;
struct V_12 * V_13 ;
V_13 = V_10 -> V_14 ;
if ( V_13 == NULL ) {
V_13 = F_9 ( V_8 , 0 ,
L_1 ,
V_15 ,
F_10 ( V_15 ) ) ;
if ( V_13 == NULL )
return;
V_10 -> V_14 = V_13 ;
}
F_11 ( V_2 , V_13 , 0 ) ;
}
void
F_12 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = V_2 -> V_8 ;
struct V_9 * V_10 = V_8 -> V_11 ;
struct V_12 * V_13 ;
V_13 = V_10 -> V_16 ;
if ( V_13 == NULL ) {
V_13 = F_9 ( V_8 , V_17 ,
L_2 ,
V_18 ,
F_10 ( V_18 ) ) ;
if ( V_13 == NULL )
return;
V_10 -> V_16 = V_13 ;
}
F_11 ( V_2 , V_13 , 0 ) ;
}
