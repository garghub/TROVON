static int T_1
F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_5 ;
if ( ( V_5 = F_3 ( V_4 ) ) < 0 )
return V_5 ;
if ( ( V_5 = F_4 ( V_4 ) ) < 0 ) {
F_5 ( V_2 -> V_6 . V_7 , L_1 ,
V_2 -> V_6 . V_8 ) ;
F_6 ( V_2 ) ;
return V_5 ;
}
return 0 ;
}
static int T_1 F_7 ( struct V_9 * V_10 )
{
struct V_11 * V_12 = V_10 -> V_13 . V_14 ;
struct V_1 * V_2 ;
struct V_3 * V_4 ;
struct V_15 V_16 ;
int V_17 ;
int V_18 ;
int V_19 ;
struct V_11 * V_20 ;
if ( F_8 () )
return - V_21 ;
V_19 =
F_9 ( V_12 , L_2 ) ||
F_9 ( V_12 , L_3 ) ;
F_10 ( & V_10 -> V_13 , L_4 ) ;
V_18 = F_11 ( V_12 , 0 , & V_16 ) ;
if ( V_18 )
return V_18 ;
V_2 = F_12 ( & V_22 , & V_10 -> V_13 , L_5 ) ;
if ( ! V_2 )
return - V_23 ;
V_2 -> V_24 = V_16 . V_25 ;
V_2 -> V_26 = F_13 ( & V_16 ) ;
if ( ! F_14 ( V_2 -> V_24 , V_2 -> V_26 , V_27 ) ) {
F_15 ( V_28 L_6 , __FILE__ ) ;
V_18 = - V_29 ;
goto V_30;
}
V_17 = F_16 ( V_12 , 0 ) ;
if ( V_17 == V_31 ) {
F_15 ( V_28 L_7 , __FILE__ ) ;
V_18 = - V_29 ;
goto V_32;
}
V_2 -> V_33 = F_17 ( V_2 -> V_24 , V_2 -> V_26 ) ;
if ( ! V_2 -> V_33 ) {
F_15 ( V_28 L_8 , __FILE__ ) ;
V_18 = - V_23 ;
goto V_34;
}
V_4 = F_2 ( V_2 ) ;
if ( V_19 ) {
V_4 -> V_35 |= V_36 | V_37 ;
if ( F_9 ( V_12 , L_9 ) )
V_4 -> V_35 |= V_38 ;
if ( F_9 ( V_12 , L_10 ) )
V_4 -> V_35 |= V_38 ;
}
F_18 ( V_4 ) ;
V_18 = F_19 ( V_2 , V_17 , 0 ) ;
if ( V_18 == 0 )
return 0 ;
V_20 = F_20 ( NULL , NULL , L_11 ) ;
if ( V_20 != NULL ) {
if ( ! F_11 ( V_20 , 0 , & V_16 ) ) {
if ( ! F_14 ( V_16 . V_25 , 0x4 , V_27 ) ) {
F_21 ( ( F_22 ( & V_4 -> V_33 -> V_39 ) |
V_40 ) , & V_4 -> V_33 -> V_39 ) ;
( void ) F_22 ( & V_4 -> V_33 -> V_39 ) ;
} else
F_23 ( V_16 . V_25 , 0x4 ) ;
} else
F_24 ( L_12 , __FILE__ ) ;
}
F_25 ( V_2 -> V_33 ) ;
V_34:
F_26 ( V_17 ) ;
V_32:
F_23 ( V_2 -> V_24 , V_2 -> V_26 ) ;
V_30:
F_27 ( V_2 ) ;
return V_18 ;
}
static int F_28 ( struct V_9 * V_10 )
{
struct V_1 * V_2 = F_29 ( & V_10 -> V_13 ) ;
F_30 ( & V_10 -> V_13 , NULL ) ;
F_10 ( & V_10 -> V_13 , L_13 ) ;
F_31 ( V_2 ) ;
F_25 ( V_2 -> V_33 ) ;
F_26 ( V_2 -> V_17 ) ;
F_23 ( V_2 -> V_24 , V_2 -> V_26 ) ;
F_27 ( V_2 ) ;
return 0 ;
}
static void F_32 ( struct V_9 * V_10 )
{
struct V_1 * V_2 = F_29 ( & V_10 -> V_13 ) ;
if ( V_2 -> V_41 -> V_42 )
V_2 -> V_41 -> V_42 ( V_2 ) ;
}
