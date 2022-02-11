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
static unsigned int F_6 ( unsigned int V_12 )
{
if ( V_12 )
return 0 ;
return F_7 ( V_5 . V_11 ) / 1000 ;
}
static int F_8 ( struct V_1 * V_2 , unsigned int V_19 )
{
struct V_3 * V_4 = V_5 . V_6 -> V_7 ;
struct V_10 * V_11 = V_5 . V_11 ;
unsigned int V_20 , V_21 ;
int V_22 = 0 ;
V_20 = F_6 ( 0 ) ;
V_21 = V_4 -> V_9 [ V_19 ] . V_23 ;
if ( V_4 -> V_24 && V_21 > V_20 ) {
V_22 = V_4 -> V_24 ( V_19 ) ;
if ( V_22 )
return V_22 ;
}
V_22 = F_9 ( V_11 , V_19 ) ;
if ( V_22 )
return V_22 ;
if ( V_5 . V_25 ) {
V_22 = F_9 ( V_5 . V_25 , V_5 . V_26 ) ;
if ( V_22 )
return V_22 ;
}
if ( V_4 -> V_24 && V_21 < V_20 )
V_4 -> V_24 ( V_19 ) ;
return 0 ;
}
static int F_10 ( struct V_1 * V_2 )
{
int V_27 = 0 ;
struct V_3 * V_4 = V_5 . V_6 -> V_7 ;
struct V_8 * V_9 = V_4 -> V_9 ;
if ( V_2 -> V_12 != 0 )
return - V_13 ;
if ( V_4 -> V_28 ) {
V_27 = V_4 -> V_28 () ;
if ( V_27 )
return V_27 ;
}
return F_11 ( V_2 , V_9 , 2000 * 1000 ) ;
}
static int T_1 F_12 ( struct V_29 * V_30 )
{
struct V_3 * V_4 = V_30 -> V_6 . V_7 ;
struct V_10 * V_25 ;
if ( ! V_4 )
return - V_13 ;
if ( ! V_4 -> V_9 )
return - V_13 ;
V_5 . V_6 = & V_30 -> V_6 ;
V_5 . V_11 = F_13 ( NULL , L_1 ) ;
if ( F_14 ( V_5 . V_11 ) ) {
F_15 ( V_5 . V_6 , L_2 ) ;
return F_16 ( V_5 . V_11 ) ;
}
V_25 = F_13 ( V_5 . V_6 , L_3 ) ;
if ( ! F_14 ( V_25 ) ) {
V_5 . V_25 = V_25 ;
V_5 . V_26 = F_7 ( V_25 ) ;
}
return F_17 ( & V_31 ) ;
}
static int T_2 F_18 ( struct V_29 * V_30 )
{
F_19 ( V_5 . V_11 ) ;
if ( V_5 . V_25 )
F_19 ( V_5 . V_25 ) ;
return F_20 ( & V_31 ) ;
}
int T_1 F_21 ( void )
{
return F_22 ( & V_32 ,
F_12 ) ;
}
