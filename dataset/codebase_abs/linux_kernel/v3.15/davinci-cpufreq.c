static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_5 . V_6 -> V_7 ;
struct V_8 * V_9 = V_4 -> V_9 ;
struct V_10 * V_11 = V_5 . V_11 ;
if ( V_9 )
return F_2 ( V_2 , V_9 ) ;
if ( V_2 -> V_12 )
return - V_13 ;
F_3 ( V_2 ) ;
V_2 -> V_14 = F_4 ( V_11 , V_2 -> V_14 * 1000 ) / 1000 ;
V_2 -> V_15 = F_4 ( V_11 , V_2 -> V_15 * 1000 ) / 1000 ;
F_5 ( V_2 , V_2 -> V_16 . V_17 ,
V_2 -> V_16 . V_18 ) ;
return 0 ;
}
static int F_6 ( struct V_1 * V_2 , unsigned int V_19 )
{
struct V_3 * V_4 = V_5 . V_6 -> V_7 ;
struct V_10 * V_11 = V_5 . V_11 ;
unsigned int V_20 , V_21 ;
int V_22 = 0 ;
V_20 = V_2 -> V_23 ;
V_21 = V_4 -> V_9 [ V_19 ] . V_24 ;
if ( V_4 -> V_25 && V_21 > V_20 ) {
V_22 = V_4 -> V_25 ( V_19 ) ;
if ( V_22 )
return V_22 ;
}
V_22 = F_7 ( V_11 , V_19 ) ;
if ( V_22 )
return V_22 ;
if ( V_5 . V_26 ) {
V_22 = F_7 ( V_5 . V_26 , V_5 . V_27 ) ;
if ( V_22 )
return V_22 ;
}
if ( V_4 -> V_25 && V_21 < V_20 )
V_4 -> V_25 ( V_19 ) ;
return 0 ;
}
static int F_8 ( struct V_1 * V_2 )
{
int V_28 = 0 ;
struct V_3 * V_4 = V_5 . V_6 -> V_7 ;
struct V_8 * V_9 = V_4 -> V_9 ;
if ( V_2 -> V_12 != 0 )
return - V_13 ;
if ( V_4 -> V_29 ) {
V_28 = V_4 -> V_29 () ;
if ( V_28 )
return V_28 ;
}
V_2 -> V_10 = V_5 . V_11 ;
return F_9 ( V_2 , V_9 , 2000 * 1000 ) ;
}
static int T_1 F_10 ( struct V_30 * V_31 )
{
struct V_3 * V_4 = V_31 -> V_6 . V_7 ;
struct V_10 * V_26 ;
if ( ! V_4 )
return - V_13 ;
if ( ! V_4 -> V_9 )
return - V_13 ;
V_5 . V_6 = & V_31 -> V_6 ;
V_5 . V_11 = F_11 ( NULL , L_1 ) ;
if ( F_12 ( V_5 . V_11 ) ) {
F_13 ( V_5 . V_6 , L_2 ) ;
return F_14 ( V_5 . V_11 ) ;
}
V_26 = F_11 ( V_5 . V_6 , L_3 ) ;
if ( ! F_12 ( V_26 ) ) {
V_5 . V_26 = V_26 ;
V_5 . V_27 = F_15 ( V_26 ) ;
}
return F_16 ( & V_32 ) ;
}
static int T_2 F_17 ( struct V_30 * V_31 )
{
F_18 ( V_5 . V_11 ) ;
if ( V_5 . V_26 )
F_18 ( V_5 . V_26 ) ;
return F_19 ( & V_32 ) ;
}
int T_1 F_20 ( void )
{
return F_21 ( & V_33 ,
F_10 ) ;
}
