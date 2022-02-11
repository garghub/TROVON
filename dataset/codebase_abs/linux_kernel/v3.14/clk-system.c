static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_6 = V_4 -> V_6 ;
F_3 ( V_6 , V_7 , 1 << V_4 -> V_8 ) ;
return 0 ;
}
static void F_4 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_6 = V_4 -> V_6 ;
F_3 ( V_6 , V_9 , 1 << V_4 -> V_8 ) ;
}
static int F_5 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_6 = V_4 -> V_6 ;
return ! ! ( F_6 ( V_6 , V_10 ) & ( 1 << V_4 -> V_8 ) ) ;
}
static struct V_11 * T_1
F_7 ( struct V_5 * V_6 , const char * V_12 ,
const char * V_13 , T_2 V_8 )
{
struct V_3 * V_4 ;
struct V_11 * V_11 = NULL ;
struct V_14 V_15 ;
if ( ! V_13 || V_8 > V_16 )
return F_8 ( - V_17 ) ;
V_4 = F_9 ( sizeof( * V_4 ) , V_18 ) ;
if ( ! V_4 )
return F_8 ( - V_19 ) ;
V_15 . V_12 = V_12 ;
V_15 . V_20 = & V_21 ;
V_15 . V_22 = & V_13 ;
V_15 . V_23 = 1 ;
V_15 . V_24 = V_25 ;
V_4 -> V_8 = V_8 ;
V_4 -> V_2 . V_15 = & V_15 ;
V_4 -> V_6 = V_6 ;
V_11 = F_10 ( NULL , & V_4 -> V_2 ) ;
if ( F_11 ( V_11 ) )
F_12 ( V_4 ) ;
return V_11 ;
}
static void T_1
F_13 ( struct V_26 * V_27 , struct V_5 * V_6 )
{
int V_28 ;
T_3 V_8 ;
struct V_11 * V_11 ;
const char * V_12 ;
struct V_26 * V_29 ;
const char * V_13 ;
V_28 = F_14 ( V_27 ) ;
if ( V_28 > ( V_16 + 1 ) )
return;
F_15 (np, sysclknp) {
if ( F_16 ( V_29 , L_1 , & V_8 ) )
continue;
if ( F_17 ( V_27 , L_2 , & V_12 ) )
V_12 = V_29 -> V_12 ;
V_13 = F_18 ( V_29 , 0 ) ;
V_11 = F_7 ( V_6 , V_12 , V_13 , V_8 ) ;
if ( F_11 ( V_11 ) )
continue;
F_19 ( V_29 , V_30 , V_11 ) ;
}
}
void T_1 F_20 ( struct V_26 * V_27 ,
struct V_5 * V_6 )
{
F_13 ( V_27 , V_6 ) ;
}
