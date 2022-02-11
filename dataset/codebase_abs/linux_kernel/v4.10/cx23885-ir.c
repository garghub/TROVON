void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 =
F_2 ( V_2 , struct V_3 , V_5 ) ;
T_1 V_6 = 0 ;
unsigned long * V_7 = & V_4 -> V_8 ;
if ( F_3 ( V_9 , V_7 ) )
V_6 |= V_10 ;
if ( F_3 ( V_11 , V_7 ) )
V_6 |= V_12 ;
if ( F_3 ( V_13 , V_7 ) )
V_6 |= V_14 ;
if ( F_3 ( V_15 , V_7 ) )
V_6 |= V_16 ;
if ( V_6 == 0 )
return;
if ( V_4 -> V_17 )
F_4 ( V_4 , V_6 ) ;
}
void F_5 ( struct V_1 * V_2 )
{
struct V_3 * V_4 =
F_2 ( V_2 , struct V_3 , V_18 ) ;
T_1 V_6 = 0 ;
unsigned long * V_7 = & V_4 -> V_19 ;
if ( F_3 ( V_20 , V_7 ) )
V_6 |= V_21 ;
if ( V_6 == 0 )
return;
}
void F_6 ( struct V_22 * V_23 , T_1 V_6 )
{
struct V_3 * V_4 = F_7 ( V_23 -> V_24 ) ;
unsigned long * V_7 = & V_4 -> V_8 ;
if ( V_6 & V_16 )
F_8 ( V_15 , V_7 ) ;
if ( V_6 & V_14 )
F_8 ( V_13 , V_7 ) ;
if ( V_6 & V_12 )
F_8 ( V_11 , V_7 ) ;
if ( V_6 & V_10 )
F_8 ( V_9 , V_7 ) ;
if ( V_23 == V_4 -> V_25 )
F_1 ( & V_4 -> V_5 ) ;
else
F_9 ( & V_4 -> V_5 ) ;
}
void F_10 ( struct V_22 * V_23 , T_1 V_6 )
{
struct V_3 * V_4 = F_7 ( V_23 -> V_24 ) ;
unsigned long * V_7 = & V_4 -> V_19 ;
if ( V_6 & V_21 )
F_8 ( V_20 , V_7 ) ;
if ( V_23 == V_4 -> V_25 )
F_5 ( & V_4 -> V_18 ) ;
else
F_9 ( & V_4 -> V_18 ) ;
}
