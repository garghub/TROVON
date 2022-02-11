static int F_1 ( struct V_1 * V_2 )
{
int V_3 = V_2 -> V_4 . V_5 ;
if ( V_2 -> V_4 . V_6 != V_7 )
V_3 = 0 ;
if ( V_2 -> V_4 . V_8 & V_9 )
V_3 = 0 ;
if ( V_2 -> V_4 . V_8 & V_10 )
V_3 = 0 ;
if ( V_2 -> V_4 . V_8 & V_11 )
V_3 &= V_12 -> V_13 ;
V_12 -> V_14 ( V_3 ) ;
V_15 = V_3 ;
if ( V_12 -> V_16 )
V_12 -> V_16 () ;
return 0 ;
}
static int F_2 ( struct V_1 * V_2 )
{
return V_15 ;
}
static int F_3 ( struct V_17 * V_18 )
{
struct V_19 V_4 ;
struct V_20 * V_21 = F_4 ( & V_18 -> V_22 ) ;
const char * V_23 = L_1 ;
struct V_1 * V_2 ;
V_12 = V_21 ;
if ( ! V_21 -> V_13 )
V_21 -> V_13 = - 1 ;
if ( V_21 -> V_23 )
V_23 = V_21 -> V_23 ;
memset ( & V_4 , 0 , sizeof( struct V_19 ) ) ;
V_4 . type = V_24 ;
V_4 . V_25 = V_21 -> V_26 ;
V_2 = F_5 ( & V_18 -> V_22 , V_23 , & V_18 -> V_22 ,
NULL , & V_27 , & V_4 ) ;
if ( F_6 ( V_2 ) )
return F_7 ( V_2 ) ;
F_8 ( V_18 , V_2 ) ;
V_2 -> V_4 . V_6 = V_7 ;
V_2 -> V_4 . V_5 = V_21 -> V_28 ;
F_9 ( V_2 ) ;
V_29 = V_2 ;
F_10 ( & V_18 -> V_22 , L_2 ) ;
return 0 ;
}
static int F_11 ( struct V_17 * V_18 )
{
struct V_1 * V_2 = F_12 ( V_18 ) ;
V_2 -> V_4 . V_6 = 0 ;
V_2 -> V_4 . V_5 = 0 ;
F_9 ( V_2 ) ;
F_10 ( & V_18 -> V_22 , L_3 ) ;
return 0 ;
}
