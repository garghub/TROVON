static void F_1 ( struct V_1 * V_2 )
{
T_1 V_3 ;
if ( V_2 -> V_4 == V_5 ||
V_2 -> V_4 == V_6 ) {
V_3 = V_7 ;
} else {
V_3 = V_8 ;
}
V_2 -> V_9 [ V_10 ] &= ~ V_11 ;
V_2 -> V_9 [ V_10 ] |= V_3 ;
}
int F_2 ( struct V_1 * V_2 ,
struct V_12 * V_12 )
{
int V_13 ;
F_3 ( V_2 , V_12 ) ;
V_13 = F_4 ( V_2 , V_12 ) ;
F_5 ( V_2 , V_12 ) ;
F_1 ( V_2 ) ;
return V_13 ;
}
int F_6 ( struct V_1 * V_2 ,
struct V_14 * V_15 )
{
struct V_12 * V_12 ;
int V_13 ;
V_12 = F_7 ( V_2 , V_15 ) ;
if ( ! V_12 )
return 0 ;
V_13 = F_2 ( V_2 , V_12 ) ;
F_8 ( V_12 ) ;
return V_13 ;
}
void
F_9 ( struct V_1 * V_2 )
{
struct V_16 * V_17 = V_2 -> V_17 ;
struct V_18 * V_19 = F_10 ( V_17 ) ;
struct V_20 * V_21 ;
V_21 = V_19 -> V_22 ;
if ( V_21 == NULL ) {
V_21 = F_11 ( V_17 , 0 ,
L_1 ,
V_23 ,
F_12 ( V_23 ) ) ;
if ( V_21 == NULL )
return;
V_19 -> V_22 = V_21 ;
}
F_13 ( & V_2 -> V_24 , V_21 , 0 ) ;
}
void
F_14 ( struct V_1 * V_2 )
{
struct V_16 * V_17 = V_2 -> V_17 ;
struct V_18 * V_19 = F_10 ( V_17 ) ;
struct V_20 * V_21 ;
V_21 = V_19 -> V_25 ;
if ( V_21 == NULL ) {
V_21 = F_11 ( V_17 , V_26 ,
L_2 ,
V_27 ,
F_12 ( V_27 ) ) ;
if ( V_21 == NULL )
return;
V_19 -> V_25 = V_21 ;
}
F_13 ( & V_2 -> V_24 , V_21 , 0 ) ;
}
void
F_15 ( struct V_1 * V_2 )
{
if ( ! F_16 ( V_2 -> V_17 ) )
F_13 ( & V_2 -> V_24 ,
V_2 -> V_17 -> V_28 . V_29 ,
V_30 ) ;
}
