static int F_1 ( struct V_1 * V_2 , unsigned int V_3 )
{
struct V_4 * V_5 = V_6 . V_7 -> V_8 ;
struct V_9 * V_10 = V_6 . V_10 ;
unsigned int V_11 , V_12 ;
int V_13 = 0 ;
V_11 = V_2 -> V_14 ;
V_12 = V_5 -> V_15 [ V_3 ] . V_16 ;
if ( V_5 -> V_17 && V_12 > V_11 ) {
V_13 = V_5 -> V_17 ( V_3 ) ;
if ( V_13 )
return V_13 ;
}
V_13 = F_2 ( V_10 , V_12 * 1000 ) ;
if ( V_13 )
return V_13 ;
if ( V_6 . V_18 ) {
V_13 = F_2 ( V_6 . V_18 , V_6 . V_19 ) ;
if ( V_13 )
return V_13 ;
}
if ( V_5 -> V_17 && V_12 < V_11 )
V_5 -> V_17 ( V_3 ) ;
return 0 ;
}
static int F_3 ( struct V_1 * V_2 )
{
int V_20 = 0 ;
struct V_4 * V_5 = V_6 . V_7 -> V_8 ;
struct V_21 * V_15 = V_5 -> V_15 ;
if ( V_2 -> V_22 != 0 )
return - V_23 ;
if ( V_5 -> V_24 ) {
V_20 = V_5 -> V_24 () ;
if ( V_20 )
return V_20 ;
}
V_2 -> V_9 = V_6 . V_10 ;
return F_4 ( V_2 , V_15 , 2000 * 1000 ) ;
}
static int T_1 F_5 ( struct V_25 * V_26 )
{
struct V_4 * V_5 = V_26 -> V_7 . V_8 ;
struct V_9 * V_18 ;
if ( ! V_5 )
return - V_23 ;
if ( ! V_5 -> V_15 )
return - V_23 ;
V_6 . V_7 = & V_26 -> V_7 ;
V_6 . V_10 = F_6 ( NULL , L_1 ) ;
if ( F_7 ( V_6 . V_10 ) ) {
F_8 ( V_6 . V_7 , L_2 ) ;
return F_9 ( V_6 . V_10 ) ;
}
V_18 = F_6 ( V_6 . V_7 , L_3 ) ;
if ( ! F_7 ( V_18 ) ) {
V_6 . V_18 = V_18 ;
V_6 . V_19 = F_10 ( V_18 ) ;
}
return F_11 ( & V_27 ) ;
}
static int T_2 F_12 ( struct V_25 * V_26 )
{
F_13 ( V_6 . V_10 ) ;
if ( V_6 . V_18 )
F_13 ( V_6 . V_18 ) ;
return F_14 ( & V_27 ) ;
}
int T_1 F_15 ( void )
{
return F_16 ( & V_28 ,
F_5 ) ;
}
