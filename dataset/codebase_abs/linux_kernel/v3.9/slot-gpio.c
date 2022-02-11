static T_1 F_1 ( int V_1 , void * V_2 )
{
struct V_3 * V_4 = V_2 ;
if ( V_4 -> V_5 -> V_6 )
V_4 -> V_5 -> V_6 ( V_4 ) ;
F_2 ( V_4 , F_3 ( 200 ) ) ;
return V_7 ;
}
static int F_4 ( struct V_3 * V_4 )
{
T_2 V_8 = strlen ( F_5 ( V_4 -> V_9 ) ) + 4 ;
struct V_10 * V_11 ;
F_6 ( & V_4 -> V_12 . V_13 ) ;
V_11 = V_4 -> V_12 . V_14 ;
if ( ! V_11 ) {
V_11 = F_7 ( & V_4 -> V_15 , sizeof( * V_11 ) + 2 * V_8 ,
V_16 ) ;
if ( V_11 ) {
V_11 -> V_17 = V_11 -> V_18 + V_8 ;
snprintf ( V_11 -> V_18 , V_8 , L_1 , F_5 ( V_4 -> V_9 ) ) ;
snprintf ( V_11 -> V_17 , V_8 , L_2 , F_5 ( V_4 -> V_9 ) ) ;
V_11 -> V_19 = - V_20 ;
V_11 -> V_21 = - V_20 ;
V_4 -> V_12 . V_14 = V_11 ;
}
}
F_8 ( & V_4 -> V_12 . V_13 ) ;
return V_11 ? 0 : - V_22 ;
}
int F_9 ( struct V_3 * V_4 )
{
struct V_10 * V_11 = V_4 -> V_12 . V_14 ;
if ( ! V_11 || ! F_10 ( V_11 -> V_21 ) )
return - V_23 ;
return ! F_11 ( V_11 -> V_21 ) ^
! ! ( V_4 -> V_24 & V_25 ) ;
}
int F_12 ( struct V_3 * V_4 )
{
struct V_10 * V_11 = V_4 -> V_12 . V_14 ;
if ( ! V_11 || ! F_10 ( V_11 -> V_19 ) )
return - V_23 ;
return ! F_11 ( V_11 -> V_19 ) ^
! ! ( V_4 -> V_24 & V_26 ) ;
}
int F_13 ( struct V_3 * V_4 , unsigned int V_27 )
{
struct V_10 * V_11 ;
int V_28 ;
if ( ! F_10 ( V_27 ) )
return - V_20 ;
V_28 = F_4 ( V_4 ) ;
if ( V_28 < 0 )
return V_28 ;
V_11 = V_4 -> V_12 . V_14 ;
V_28 = F_14 ( & V_4 -> V_15 , V_27 , V_29 ,
V_11 -> V_17 ) ;
if ( V_28 < 0 )
return V_28 ;
V_11 -> V_21 = V_27 ;
return 0 ;
}
int F_15 ( struct V_3 * V_4 , unsigned int V_27 )
{
struct V_10 * V_11 ;
int V_1 = F_16 ( V_27 ) ;
int V_28 ;
V_28 = F_4 ( V_4 ) ;
if ( V_28 < 0 )
return V_28 ;
V_11 = V_4 -> V_12 . V_14 ;
V_28 = F_14 ( & V_4 -> V_15 , V_27 , V_29 ,
V_11 -> V_18 ) ;
if ( V_28 < 0 )
return V_28 ;
if ( V_1 >= 0 && V_4 -> V_30 & V_31 )
V_1 = - V_20 ;
if ( V_1 >= 0 ) {
V_28 = F_17 ( & V_4 -> V_15 , V_1 ,
NULL , F_1 ,
V_32 | V_33 | V_34 ,
V_11 -> V_18 , V_4 ) ;
if ( V_28 < 0 )
V_1 = V_28 ;
}
V_4 -> V_12 . V_35 = V_1 ;
if ( V_1 < 0 )
V_4 -> V_30 |= V_31 ;
V_11 -> V_19 = V_27 ;
return 0 ;
}
void F_18 ( struct V_3 * V_4 )
{
struct V_10 * V_11 = V_4 -> V_12 . V_14 ;
int V_27 ;
if ( ! V_11 || ! F_10 ( V_11 -> V_21 ) )
return;
V_27 = V_11 -> V_21 ;
V_11 -> V_21 = - V_20 ;
F_19 ( & V_4 -> V_15 , V_27 ) ;
}
void F_20 ( struct V_3 * V_4 )
{
struct V_10 * V_11 = V_4 -> V_12 . V_14 ;
int V_27 ;
if ( ! V_11 || ! F_10 ( V_11 -> V_19 ) )
return;
if ( V_4 -> V_12 . V_35 >= 0 ) {
F_21 ( & V_4 -> V_15 , V_4 -> V_12 . V_35 , V_4 ) ;
V_4 -> V_12 . V_35 = - V_20 ;
}
V_27 = V_11 -> V_19 ;
V_11 -> V_19 = - V_20 ;
F_19 ( & V_4 -> V_15 , V_27 ) ;
}
