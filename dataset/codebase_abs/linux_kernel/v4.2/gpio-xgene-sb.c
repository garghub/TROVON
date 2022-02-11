static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
struct V_4 * V_5 = F_2 ( V_3 ) ;
return F_3 ( V_5 , struct V_1 , V_5 ) ;
}
static void F_4 ( struct V_4 * V_5 , void T_1 * V_6 , T_2 V_7 , int V_8 )
{
T_2 V_9 ;
V_9 = V_5 -> V_10 ( V_6 ) ;
if ( V_8 )
V_9 |= F_5 ( V_7 ) ;
else
V_9 &= ~ F_5 ( V_7 ) ;
V_5 -> V_11 ( V_6 , V_9 ) ;
}
static int F_6 ( struct V_2 * V_3 , T_2 V_7 )
{
struct V_1 * V_12 = F_1 ( V_3 ) ;
if ( V_12 -> V_13 [ V_7 ] )
return V_12 -> V_13 [ V_7 ] ;
return - V_14 ;
}
static int F_7 ( struct V_15 * V_16 )
{
struct V_1 * V_12 ;
T_2 V_17 , V_18 ;
T_2 V_19 [] = { 0x08 , 0x09 , 0x0A , 0x0B , 0x0C , 0x0D } ;
struct V_20 * V_21 ;
void T_1 * V_22 ;
V_12 = F_8 ( & V_16 -> V_23 , sizeof( * V_12 ) , V_24 ) ;
if ( ! V_12 )
return - V_25 ;
V_21 = F_9 ( V_16 , V_26 , 0 ) ;
V_22 = F_10 ( & V_16 -> V_23 , V_21 ) ;
if ( F_11 ( V_22 ) )
return F_12 ( V_22 ) ;
V_17 = F_13 ( & V_12 -> V_5 , & V_16 -> V_23 , 4 ,
V_22 + V_27 ,
V_22 + V_28 , NULL ,
V_22 + V_29 , NULL , 0 ) ;
if ( V_17 )
return V_17 ;
V_12 -> V_5 . V_3 . V_30 = F_6 ;
V_12 -> V_5 . V_3 . V_31 = V_32 ;
V_12 -> V_33 = V_34 ;
V_12 -> V_13 = F_8 ( & V_16 -> V_23 , sizeof( T_2 ) * V_32 ,
V_24 ) ;
if ( ! V_12 -> V_13 )
return - V_25 ;
for ( V_18 = 0 ; V_18 < V_12 -> V_33 ; V_18 ++ ) {
V_12 -> V_13 [ V_19 [ V_18 ] ] = F_14 ( V_16 , V_18 ) ;
F_4 ( & V_12 -> V_5 , V_22 + V_35 ,
V_19 [ V_18 ] * 2 , 1 ) ;
F_4 ( & V_12 -> V_5 , V_22 + V_36 , V_18 , 1 ) ;
}
F_15 ( V_16 , V_12 ) ;
V_17 = F_16 ( & V_12 -> V_5 . V_3 ) ;
if ( V_17 )
F_17 ( & V_16 -> V_23 , L_1 ) ;
else
F_18 ( & V_16 -> V_23 , L_2 ) ;
if ( V_12 -> V_33 > 0 ) {
F_19 ( & V_12 -> V_5 . V_3 ) ;
}
return V_17 ;
}
static int F_20 ( struct V_15 * V_16 )
{
struct V_1 * V_12 = F_21 ( V_16 ) ;
if ( V_12 -> V_33 > 0 ) {
F_22 ( & V_12 -> V_5 . V_3 ) ;
}
return F_23 ( & V_12 -> V_5 ) ;
}
