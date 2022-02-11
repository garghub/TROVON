static int F_1 ( struct V_1 * V_2 , int V_3 )
{
int V_4 ;
struct V_5 * V_5 = F_2 ( V_2 , struct V_5 , V_2 ) ;
for ( V_4 = 0 ; V_4 < 20 ; V_4 ++ ) {
int V_6 = ( F_3 ( V_5 -> V_7 + V_8 ) &
V_9 ) >> 8 ;
if ( V_6 || ! V_3 )
return ! ! V_6 ;
F_4 ( 10 ) ;
}
return 0 ;
}
static int F_5 ( struct V_1 * V_2 , T_1 * V_10 )
{
int V_11 ;
T_1 V_12 ;
struct V_5 * V_5 = F_2 ( V_2 , struct V_5 , V_2 ) ;
* V_10 = F_3 ( V_5 -> V_7 + V_13 ) ;
V_11 = F_3 ( V_5 -> V_7 + V_8 ) & V_14 ;
if ( V_11 ) {
F_6 ( V_5 -> V_15 , L_1 ) ;
V_12 = F_3 ( V_5 -> V_7 + V_16 ) ;
F_7 ( V_12 | V_17 ,
V_5 -> V_7 + V_16 ) ;
return 0 ;
} else
return 4 ;
}
static int F_8 ( struct V_1 * V_2 )
{
T_1 V_12 , V_18 ;
struct V_5 * V_5 = F_2 ( V_2 , struct V_5 , V_2 ) ;
V_12 = F_3 ( V_5 -> V_7 + V_16 ) ;
F_7 ( V_12 & ~ V_19 , V_5 -> V_7 + V_16 ) ;
V_18 = F_3 ( V_5 -> V_7 + V_8 ) ;
if ( V_18 & V_20 ) {
F_9 ( V_5 -> V_15 , L_2 ) ;
return - V_21 ;
}
V_12 = F_3 ( V_5 -> V_7 + V_16 ) ;
F_7 ( V_12 | V_22 , V_5 -> V_7 + V_16 ) ;
return 0 ;
}
static void F_10 ( struct V_1 * V_2 )
{
T_1 V_12 ;
struct V_5 * V_5 = F_2 ( V_2 , struct V_5 , V_2 ) ;
V_12 = F_3 ( V_5 -> V_7 + V_16 ) ;
F_7 ( V_12 & ~ V_22 , V_5 -> V_7 + V_16 ) ;
}
static int T_2 F_11 ( struct V_23 * V_24 )
{
int V_11 = - V_21 ;
struct V_25 * V_26 , * V_7 ;
struct V_5 * V_5 ;
V_5 = F_12 ( & V_24 -> V_15 , sizeof( struct V_5 ) ,
V_27 ) ;
if ( ! V_5 )
return - V_28 ;
V_5 -> V_15 = & V_24 -> V_15 ;
V_5 -> V_2 . V_29 = L_3 ;
V_5 -> V_2 . V_30 = F_8 ;
V_5 -> V_2 . V_31 = F_10 ,
V_5 -> V_2 . V_32 = F_1 ,
V_5 -> V_2 . V_33 = F_5 ,
V_5 -> V_34 = F_13 ( & V_24 -> V_15 , NULL ) ;
if ( F_14 ( V_5 -> V_34 ) ) {
F_9 ( & V_24 -> V_15 , L_4 ) ;
V_11 = F_15 ( V_5 -> V_34 ) ;
goto V_35;
}
F_16 ( V_5 -> V_34 ) ;
V_26 = F_17 ( V_24 , V_36 , 0 ) ;
if ( ! V_26 ) {
V_11 = - V_37 ;
goto V_38;
}
V_7 = F_18 ( V_26 -> V_39 , F_19 ( V_26 ) , V_24 -> V_29 ) ;
if ( V_7 == NULL ) {
V_11 = - V_40 ;
goto V_38;
}
V_5 -> V_7 = F_20 ( V_26 -> V_39 , F_19 ( V_26 ) ) ;
if ( ! V_5 -> V_7 ) {
V_11 = - V_28 ;
goto V_41;
}
V_11 = F_21 ( & V_5 -> V_2 ) ;
if ( V_11 ) {
F_9 ( & V_24 -> V_15 , L_5 , V_11 ) ;
goto V_41;
}
F_22 ( & V_24 -> V_15 , L_6 ) ;
return 0 ;
V_41:
F_23 ( V_26 -> V_39 , F_19 ( V_26 ) ) ;
V_38:
F_24 ( V_5 -> V_34 ) ;
V_35:
return V_11 ;
}
static int T_3 F_25 ( struct V_23 * V_24 )
{
struct V_25 * V_26 = F_17 ( V_24 , V_36 , 0 ) ;
struct V_5 * V_5 = F_26 ( V_24 ) ;
F_27 ( & V_5 -> V_2 ) ;
F_28 ( V_5 -> V_7 ) ;
F_23 ( V_26 -> V_39 , F_19 ( V_26 ) ) ;
F_24 ( V_5 -> V_34 ) ;
return 0 ;
}
static int T_2 F_29 ( void )
{
return F_30 ( & V_42 , F_11 ) ;
}
static void T_3 F_31 ( void )
{
F_32 ( & V_42 ) ;
}
