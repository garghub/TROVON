static void F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
struct V_4 * V_5 = & V_2 -> V_5 ;
struct V_6 * V_6 = V_2 -> V_5 . V_7 ;
int V_8 ;
T_1 V_9 ;
V_8 = ( ( V_3 & V_10 ) == V_10 ) ;
V_9 = F_2 ( V_2 , V_11 ) & V_12 ;
if ( V_8 && V_9 == V_5 -> V_13 )
return;
V_5 -> V_13 = V_9 ;
if ( V_9 )
F_3 ( V_6 , V_14 ) ;
else
F_3 ( V_6 , V_15 ) ;
F_4 ( V_6 ) ;
}
void F_5 ( struct V_1 * V_2 , T_1 V_3 )
{
struct V_4 * V_5 = & V_2 -> V_5 ;
if ( ! V_5 -> V_7 )
return;
F_1 ( V_2 , V_3 ) ;
F_6 ( & V_5 -> V_16 , V_17 + F_7 ( V_18 ) ) ;
}
static void F_8 ( unsigned long V_19 )
{
struct V_1 * V_2 = (struct V_1 * ) V_19 ;
F_9 ( & V_2 -> V_20 ) ;
if ( V_2 -> V_5 . V_7 )
F_1 ( V_2 , 0 ) ;
F_10 ( & V_2 -> V_20 ) ;
}
void F_11 ( struct V_1 * V_2 )
{
T_1 V_21 ;
if ( ! V_2 -> V_5 . V_7 )
return;
F_9 ( & V_2 -> V_20 ) ;
V_21 = F_2 ( V_2 , V_22 ) ;
V_21 |= V_10 ;
F_12 ( V_2 , V_23 , V_10 ) ;
F_12 ( V_2 , V_22 , V_21 ) ;
F_10 ( & V_2 -> V_20 ) ;
}
int F_13 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = & V_2 -> V_5 ;
struct V_6 * V_7 ;
int error ;
F_14 ( & V_5 -> V_16 , F_8 , ( unsigned long ) V_2 ) ;
V_5 -> V_7 = V_7 = F_15 () ;
if ( ! V_7 ) {
F_16 ( V_2 -> V_24 , L_1 ) ;
return - V_25 ;
}
V_7 -> V_2 = V_2 ;
V_7 -> V_26 = V_27 ;
V_7 -> V_28 = L_2 ;
V_7 -> V_29 = V_30 ;
error = F_17 ( V_7 ) ;
if ( error ) {
F_16 ( V_2 -> V_24 , L_3 ) ;
F_18 ( V_7 ) ;
V_5 -> V_7 = NULL ;
return error ;
}
return 0 ;
}
void F_19 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = & V_2 -> V_5 ;
struct V_6 * V_7 = V_5 -> V_7 ;
T_1 V_21 ;
if ( ! V_7 )
return;
F_9 ( & V_2 -> V_20 ) ;
V_5 -> V_7 = NULL ;
V_21 = F_2 ( V_2 , V_22 ) ;
V_21 &= ~ V_10 ;
F_12 ( V_2 , V_22 , V_21 ) ;
F_12 ( V_2 , V_23 , V_10 ) ;
F_10 ( & V_2 -> V_20 ) ;
F_20 ( V_7 ) ;
F_21 ( & V_5 -> V_16 ) ;
}
