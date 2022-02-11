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
F_3 ( V_6 , false ) ;
else
F_3 ( V_6 , true ) ;
F_4 ( V_6 ) ;
}
void F_5 ( struct V_1 * V_2 , T_1 V_3 )
{
struct V_4 * V_5 = & V_2 -> V_5 ;
if ( ! V_5 -> V_7 )
return;
F_1 ( V_2 , V_3 ) ;
F_6 ( & V_5 -> V_14 , V_15 + F_7 ( V_16 ) ) ;
}
static void F_8 ( unsigned long V_17 )
{
struct V_1 * V_2 = (struct V_1 * ) V_17 ;
F_9 ( & V_2 -> V_18 ) ;
if ( V_2 -> V_5 . V_7 )
F_1 ( V_2 , 0 ) ;
F_10 ( & V_2 -> V_18 ) ;
}
void F_11 ( struct V_1 * V_2 )
{
T_1 V_19 ;
if ( ! V_2 -> V_5 . V_7 )
return;
F_9 ( & V_2 -> V_18 ) ;
V_19 = F_2 ( V_2 , V_20 ) ;
V_19 |= V_10 ;
F_12 ( V_2 , V_21 , V_10 ) ;
F_12 ( V_2 , V_20 , V_19 ) ;
F_10 ( & V_2 -> V_18 ) ;
}
int F_13 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = & V_2 -> V_5 ;
struct V_6 * V_7 ;
int error ;
F_14 ( & V_5 -> V_14 , F_8 , ( unsigned long ) V_2 ) ;
V_5 -> V_7 = V_7 = F_15 ( V_22 ) ;
if ( ! V_7 ) {
F_16 ( V_2 -> V_23 , L_1 ) ;
return - V_24 ;
}
V_7 -> V_2 = V_2 ;
V_7 -> V_25 = V_26 ;
V_7 -> V_27 = L_2 ;
error = F_17 ( V_7 ) ;
if ( error ) {
F_16 ( V_2 -> V_23 , L_3 ) ;
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
T_1 V_19 ;
if ( ! V_7 )
return;
F_9 ( & V_2 -> V_18 ) ;
V_5 -> V_7 = NULL ;
V_19 = F_2 ( V_2 , V_20 ) ;
V_19 &= ~ V_10 ;
F_12 ( V_2 , V_20 , V_19 ) ;
F_12 ( V_2 , V_21 , V_10 ) ;
F_10 ( & V_2 -> V_18 ) ;
F_20 ( V_7 ) ;
F_21 ( & V_5 -> V_14 ) ;
}
