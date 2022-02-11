static unsigned int
F_1 ( struct V_1 * V_2 , const struct V_3 * V_4 )
{
const struct V_5 * V_6 = V_4 -> V_7 ;
const struct V_8 * V_9 ;
unsigned char * V_10 ;
int V_11 , V_12 ;
if ( ! F_2 ( V_2 , V_2 -> V_13 ) )
return V_14 ;
V_9 = F_3 ( V_2 ) ;
V_10 = F_4 ( V_2 ) + sizeof( * V_9 ) ;
V_11 = V_9 -> V_15 ;
V_12 = V_9 -> V_16 ;
if ( V_6 -> V_17 & V_18 ) {
if ( V_19 < V_12 ||
( V_10 + V_12 > F_5 ( V_2 ) ) )
return V_14 ;
memcpy ( V_10 , V_6 -> V_20 , V_12 ) ;
}
V_10 += V_12 ;
if ( V_6 -> V_17 & V_21 ) {
if ( V_22 < V_11 ||
( V_10 + V_11 > F_5 ( V_2 ) ) )
return V_14 ;
memcpy ( V_10 , & V_6 -> V_23 . V_24 , V_11 ) ;
}
V_10 += V_11 ;
if ( V_6 -> V_17 & V_25 ) {
if ( V_19 < V_12 ||
( V_10 + V_12 > F_5 ( V_2 ) ) )
return V_14 ;
memcpy ( V_10 , V_6 -> V_26 , V_12 ) ;
}
V_10 += V_12 ;
if ( V_6 -> V_17 & V_27 ) {
if ( V_22 < V_11 ||
( V_10 + V_11 > F_5 ( V_2 ) ) )
return V_14 ;
memcpy ( V_10 , & V_6 -> V_28 . V_29 , V_11 ) ;
}
return V_6 -> F_1 ;
}
static int F_6 ( const struct V_30 * V_4 )
{
const struct V_5 * V_6 = V_4 -> V_7 ;
if ( V_6 -> V_17 & ~ V_31 ||
! ( V_6 -> V_17 & V_31 ) )
return - V_32 ;
if ( V_6 -> F_1 != V_14 && V_6 -> F_1 != V_33 &&
V_6 -> F_1 != V_34 )
return - V_32 ;
return 0 ;
}
static int T_1 F_7 ( void )
{
return F_8 ( & V_35 ) ;
}
static void T_2 F_9 ( void )
{
F_10 ( & V_35 ) ;
}
