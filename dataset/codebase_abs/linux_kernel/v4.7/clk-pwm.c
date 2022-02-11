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
struct V_16 V_17 ;
const char * V_18 ;
struct V_19 * V_19 ;
int V_20 ;
V_1 = F_9 ( & V_8 -> V_11 , sizeof( * V_1 ) , V_21 ) ;
if ( ! V_1 )
return - V_22 ;
V_4 = F_10 ( & V_8 -> V_11 , NULL ) ;
if ( F_11 ( V_4 ) )
return F_12 ( V_4 ) ;
F_13 ( V_4 , & V_17 ) ;
if ( ! V_17 . V_23 ) {
F_14 ( & V_8 -> V_11 , L_1 ) ;
return - V_24 ;
}
if ( F_15 ( V_10 , L_2 , & V_1 -> V_6 ) )
V_1 -> V_6 = V_25 / V_17 . V_23 ;
if ( V_17 . V_23 != V_25 / V_1 -> V_6 &&
V_17 . V_23 != F_16 ( V_25 , V_1 -> V_6 ) ) {
F_14 ( & V_8 -> V_11 ,
L_3 ) ;
return - V_24 ;
}
F_17 ( V_4 ) ;
V_20 = F_18 ( V_4 , ( V_17 . V_23 + 1 ) >> 1 , V_17 . V_23 ) ;
if ( V_20 < 0 )
return V_20 ;
V_18 = V_10 -> V_26 ;
F_19 ( V_10 , L_4 , & V_18 ) ;
V_14 . V_26 = V_18 ;
V_14 . V_27 = & V_28 ;
V_14 . V_29 = V_30 ;
V_14 . V_31 = 0 ;
V_1 -> V_4 = V_4 ;
V_1 -> V_3 . V_14 = & V_14 ;
V_19 = F_20 ( & V_8 -> V_11 , & V_1 -> V_3 ) ;
if ( F_11 ( V_19 ) )
return F_12 ( V_19 ) ;
return F_21 ( V_10 , V_32 , V_19 ) ;
}
static int F_22 ( struct V_7 * V_8 )
{
F_23 ( V_8 -> V_11 . V_12 ) ;
return 0 ;
}
