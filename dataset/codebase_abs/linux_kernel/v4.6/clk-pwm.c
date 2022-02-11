static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_3 ) ;
}
static int F_3 ( struct V_2 * V_3 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
return F_4 ( V_1 -> V_4 ) ;
}
static void F_5 ( struct V_2 * V_3 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
F_6 ( V_1 -> V_4 ) ;
}
static unsigned long F_7 ( struct V_2 * V_3 ,
unsigned long V_5 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
return V_1 -> V_6 ;
}
static int F_8 ( struct V_7 * V_8 )
{
struct V_9 * V_10 = V_8 -> V_11 . V_12 ;
struct V_13 V_14 ;
struct V_1 * V_1 ;
struct V_15 * V_4 ;
const char * V_16 ;
struct V_17 * V_17 ;
int V_18 ;
V_1 = F_9 ( & V_8 -> V_11 , sizeof( * V_1 ) , V_19 ) ;
if ( ! V_1 )
return - V_20 ;
V_4 = F_10 ( & V_8 -> V_11 , NULL ) ;
if ( F_11 ( V_4 ) )
return F_12 ( V_4 ) ;
if ( ! V_4 -> V_21 ) {
F_13 ( & V_8 -> V_11 , L_1 ) ;
return - V_22 ;
}
if ( F_14 ( V_10 , L_2 , & V_1 -> V_6 ) )
V_1 -> V_6 = V_23 / V_4 -> V_21 ;
if ( V_4 -> V_21 != V_23 / V_1 -> V_6 &&
V_4 -> V_21 != F_15 ( V_23 , V_1 -> V_6 ) ) {
F_13 ( & V_8 -> V_11 ,
L_3 ) ;
return - V_22 ;
}
V_18 = F_16 ( V_4 , ( V_4 -> V_21 + 1 ) >> 1 , V_4 -> V_21 ) ;
if ( V_18 < 0 )
return V_18 ;
V_16 = V_10 -> V_24 ;
F_17 ( V_10 , L_4 , & V_16 ) ;
V_14 . V_24 = V_16 ;
V_14 . V_25 = & V_26 ;
V_14 . V_27 = V_28 ;
V_14 . V_29 = 0 ;
V_1 -> V_4 = V_4 ;
V_1 -> V_3 . V_14 = & V_14 ;
V_17 = F_18 ( & V_8 -> V_11 , & V_1 -> V_3 ) ;
if ( F_11 ( V_17 ) )
return F_12 ( V_17 ) ;
return F_19 ( V_10 , V_30 , V_17 ) ;
}
static int F_20 ( struct V_7 * V_8 )
{
F_21 ( V_8 -> V_11 . V_12 ) ;
return 0 ;
}
