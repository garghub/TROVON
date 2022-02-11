static T_1 F_1 ( int V_1 , void * V_2 )
{
F_2 ( V_2 , F_3 ( 100 ) ) ;
return V_3 ;
}
static int F_4 ( struct V_4 * V_5 )
{
T_2 V_6 = strlen ( F_5 ( V_5 -> V_7 ) ) + 4 ;
struct V_8 * V_9 ;
F_6 ( & V_5 -> V_10 . V_11 ) ;
V_9 = V_5 -> V_10 . V_12 ;
if ( ! V_9 ) {
V_9 = F_7 ( & V_5 -> V_13 , sizeof( * V_9 ) + 2 * V_6 ,
V_14 ) ;
if ( V_9 ) {
V_9 -> V_15 = V_9 -> V_16 + V_6 ;
snprintf ( V_9 -> V_16 , V_6 , L_1 , F_5 ( V_5 -> V_7 ) ) ;
snprintf ( V_9 -> V_15 , V_6 , L_2 , F_5 ( V_5 -> V_7 ) ) ;
V_9 -> V_17 = - V_18 ;
V_9 -> V_19 = - V_18 ;
V_5 -> V_10 . V_12 = V_9 ;
}
}
F_8 ( & V_5 -> V_10 . V_11 ) ;
return V_9 ? 0 : - V_20 ;
}
int F_9 ( struct V_4 * V_5 )
{
struct V_8 * V_9 = V_5 -> V_10 . V_12 ;
if ( ! V_9 || ! F_10 ( V_9 -> V_19 ) )
return - V_21 ;
return ! F_11 ( V_9 -> V_19 ) ^
! ! ( V_5 -> V_22 & V_23 ) ;
}
int F_12 ( struct V_4 * V_5 )
{
struct V_8 * V_9 = V_5 -> V_10 . V_12 ;
if ( ! V_9 || ! F_10 ( V_9 -> V_17 ) )
return - V_21 ;
return ! F_11 ( V_9 -> V_17 ) ^
! ! ( V_5 -> V_22 & V_24 ) ;
}
int F_13 ( struct V_4 * V_5 , unsigned int V_25 )
{
struct V_8 * V_9 ;
int V_26 ;
if ( ! F_10 ( V_25 ) )
return - V_18 ;
V_26 = F_4 ( V_5 ) ;
if ( V_26 < 0 )
return V_26 ;
V_9 = V_5 -> V_10 . V_12 ;
return F_14 ( V_25 , V_27 , V_9 -> V_15 ) ;
}
int F_15 ( struct V_4 * V_5 , unsigned int V_25 )
{
struct V_8 * V_9 ;
int V_1 = F_16 ( V_25 ) ;
int V_26 ;
V_26 = F_4 ( V_5 ) ;
if ( V_26 < 0 )
return V_26 ;
V_9 = V_5 -> V_10 . V_12 ;
V_26 = F_14 ( V_25 , V_27 , V_9 -> V_16 ) ;
if ( V_26 < 0 )
return V_26 ;
if ( V_1 >= 0 && V_5 -> V_28 & V_29 )
V_1 = - V_18 ;
if ( V_1 >= 0 ) {
V_26 = F_17 ( V_1 , NULL , F_1 ,
V_30 | V_31 | V_32 ,
V_9 -> V_16 , V_5 ) ;
if ( V_26 < 0 )
V_1 = V_26 ;
}
V_5 -> V_10 . V_33 = V_1 ;
if ( V_1 < 0 )
V_5 -> V_28 |= V_29 ;
V_9 -> V_17 = V_25 ;
return 0 ;
}
void F_18 ( struct V_4 * V_5 )
{
struct V_8 * V_9 = V_5 -> V_10 . V_12 ;
int V_25 ;
if ( ! V_9 || ! F_10 ( V_9 -> V_19 ) )
return;
V_25 = V_9 -> V_19 ;
V_9 -> V_19 = - V_18 ;
F_19 ( V_25 ) ;
}
void F_20 ( struct V_4 * V_5 )
{
struct V_8 * V_9 = V_5 -> V_10 . V_12 ;
int V_25 ;
if ( ! V_9 || ! F_10 ( V_9 -> V_17 ) )
return;
if ( V_5 -> V_10 . V_33 >= 0 ) {
F_21 ( V_5 -> V_10 . V_33 , V_5 ) ;
V_5 -> V_10 . V_33 = - V_18 ;
}
V_25 = V_9 -> V_17 ;
V_9 -> V_17 = - V_18 ;
F_19 ( V_25 ) ;
}
