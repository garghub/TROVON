static inline void F_1 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_4 )
{
F_2 ( V_4 , V_2 -> V_5 + V_3 ) ;
}
static inline T_1 F_3 ( struct V_1 * V_2 , T_1 V_3 )
{
return F_4 ( V_2 -> V_5 + V_3 ) ;
}
static T_2 F_5 ( int V_6 , void * V_7 )
{
struct V_1 * V_2 = V_7 ;
T_1 V_8 ;
V_8 = F_3 ( V_2 , V_9 ) ;
F_6 ( L_1 , V_8 ) ;
while ( V_8 ) {
T_3 V_10 = F_7 ( V_8 ) - 1 ;
F_8 ( F_9 (
V_2 -> V_11 . V_12 , V_10 ) ) ;
V_8 &= ~ ( 1 << V_10 ) ;
}
return V_13 ;
}
static void F_10 ( struct V_14 * V_15 )
{
struct V_1 * V_2 = F_11 ( V_15 ) ;
F_12 () ;
F_13 ( V_15 -> V_10 , & V_2 -> V_11 . V_16 ) ;
F_14 () ;
}
static void F_15 ( struct V_14 * V_15 )
{
struct V_1 * V_2 = F_11 ( V_15 ) ;
F_12 () ;
F_16 ( V_15 -> V_10 , & V_2 -> V_11 . V_16 ) ;
F_14 () ;
}
static int F_17 ( struct V_17 * V_18 , unsigned int V_6 ,
T_3 V_10 )
{
struct V_1 * V_2 = V_18 -> V_19 ;
if ( ! ( V_20 & ( 1 << V_10 ) ) )
return - V_21 ;
F_18 ( V_6 , & V_22 , V_23 ) ;
F_19 ( V_6 , V_2 ) ;
return 0 ;
}
static int F_20 ( struct V_1 * V_2 )
{
struct V_24 * V_25 = V_2 -> V_25 -> V_25 ;
struct V_17 * V_18 ;
V_18 = F_21 ( V_25 -> V_26 , 32 , & V_27 ,
V_2 ) ;
if ( ! V_18 ) {
F_22 ( V_25 , L_2 ) ;
return - V_28 ;
}
V_2 -> V_11 . V_16 = 0 ;
V_2 -> V_11 . V_12 = V_18 ;
return 0 ;
}
void F_23 ( struct V_29 * V_25 )
{
struct V_30 * V_31 = V_25 -> V_32 ;
struct V_1 * V_2 = V_31 -> V_2 ;
if ( ! V_2 )
return;
F_24 ( V_2 -> V_11 . V_12 ) ;
V_2 -> V_11 . V_12 = NULL ;
F_25 ( V_2 -> V_33 ) ;
F_26 ( V_25 -> V_25 ) ;
F_27 ( V_25 -> V_25 ) ;
}
int F_28 ( struct V_29 * V_25 )
{
struct V_34 * V_35 = F_29 ( V_25 -> V_25 ) ;
struct V_30 * V_31 = V_25 -> V_32 ;
struct V_1 * V_2 ;
int V_36 ;
F_30 ( L_3 ) ;
if ( ! F_31 ( V_25 -> V_25 -> V_26 , L_4 ) )
return 0 ;
V_2 = F_32 ( V_25 -> V_25 , sizeof( * V_2 ) , V_37 ) ;
if ( ! V_2 ) {
V_36 = - V_38 ;
goto V_39;
}
V_2 -> V_25 = V_25 ;
V_2 -> V_5 = F_33 ( V_35 , L_5 , L_6 ) ;
if ( F_34 ( V_2 -> V_5 ) ) {
V_36 = F_35 ( V_2 -> V_5 ) ;
goto V_39;
}
V_2 -> V_40 = F_33 ( V_35 , L_7 , L_8 ) ;
if ( F_34 ( V_2 -> V_40 ) ) {
V_36 = F_35 ( V_2 -> V_40 ) ;
goto V_39;
}
V_2 -> V_33 = F_36 ( V_25 -> V_25 , L_9 ) ;
if ( F_34 ( V_2 -> V_33 ) ) {
V_36 = F_35 ( V_2 -> V_33 ) ;
goto V_39;
}
V_36 = F_37 ( V_2 -> V_33 ) ;
if ( V_36 ) {
F_22 ( V_25 -> V_25 , L_10 ,
V_36 ) ;
goto V_39;
}
V_36 = F_38 ( V_25 -> V_25 , F_39 ( V_35 , 0 ) ,
F_5 , 0 , L_11 , V_2 ) ;
if ( V_36 ) {
F_22 ( V_25 -> V_25 , L_12 , V_36 ) ;
goto V_41;
}
V_36 = F_20 ( V_2 ) ;
if ( V_36 ) {
F_22 ( V_25 -> V_25 , L_13 , V_36 ) ;
goto V_41;
}
V_31 -> V_2 = V_2 ;
F_40 ( V_25 -> V_25 ) ;
F_41 ( V_25 -> V_25 ) ;
return 0 ;
V_41:
F_25 ( V_2 -> V_33 ) ;
V_39:
return V_36 ;
}
