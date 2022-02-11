static int T_1
F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_5 ;
if ( ( V_5 = F_3 ( V_4 ) ) < 0 )
return V_5 ;
if ( ( V_5 = F_4 ( V_4 ) ) < 0 ) {
F_5 ( L_1 , F_6 ( V_4 ) -> V_6 . V_7 ) ;
F_7 ( V_2 ) ;
return V_5 ;
}
return 0 ;
}
static int T_1 F_8 ( struct V_8 * V_9 )
{
struct V_10 * V_11 = V_9 -> V_12 . V_13 ;
struct V_1 * V_2 ;
struct V_3 * V_4 ;
struct V_14 V_15 ;
int V_16 ;
int V_17 ;
int V_18 ;
struct V_10 * V_19 ;
if ( F_9 () )
return - V_20 ;
V_18 =
F_10 ( V_11 , L_2 ) ||
F_10 ( V_11 , L_3 ) ;
F_11 ( & V_9 -> V_12 , L_4 ) ;
V_17 = F_12 ( V_11 , 0 , & V_15 ) ;
if ( V_17 )
return V_17 ;
V_2 = F_13 ( & V_21 , & V_9 -> V_12 , L_5 ) ;
if ( ! V_2 )
return - V_22 ;
V_2 -> V_23 = V_15 . V_24 ;
V_2 -> V_25 = F_14 ( & V_15 ) ;
if ( ! F_15 ( V_2 -> V_23 , V_2 -> V_25 , V_26 ) ) {
F_16 ( V_27 L_6 , __FILE__ ) ;
V_17 = - V_28 ;
goto V_29;
}
V_16 = F_17 ( V_11 , 0 ) ;
if ( V_16 == V_30 ) {
F_16 ( V_27 L_7 , __FILE__ ) ;
V_17 = - V_28 ;
goto V_31;
}
V_2 -> V_32 = F_18 ( V_2 -> V_23 , V_2 -> V_25 ) ;
if ( ! V_2 -> V_32 ) {
F_16 ( V_27 L_8 , __FILE__ ) ;
V_17 = - V_22 ;
goto V_33;
}
V_4 = F_2 ( V_2 ) ;
if ( V_18 ) {
V_4 -> V_34 |= V_35 | V_36 ;
if ( F_10 ( V_11 , L_9 ) )
V_4 -> V_34 |= V_37 ;
if ( F_10 ( V_11 , L_10 ) )
V_4 -> V_34 |= V_37 ;
}
F_19 ( V_4 ) ;
V_17 = F_20 ( V_2 , V_16 , 0 ) ;
if ( V_17 == 0 )
return 0 ;
V_19 = F_21 ( NULL , NULL , L_11 ) ;
if ( V_19 != NULL ) {
if ( ! F_12 ( V_19 , 0 , & V_15 ) ) {
if ( ! F_15 ( V_15 . V_24 , 0x4 , V_26 ) ) {
F_22 ( ( F_23 ( & V_4 -> V_32 -> V_38 ) |
V_39 ) , & V_4 -> V_32 -> V_38 ) ;
( void ) F_23 ( & V_4 -> V_32 -> V_38 ) ;
} else
F_24 ( V_15 . V_24 , 0x4 ) ;
} else
F_25 ( L_12 , __FILE__ ) ;
}
F_26 ( V_2 -> V_32 ) ;
V_33:
F_27 ( V_16 ) ;
V_31:
F_24 ( V_2 -> V_23 , V_2 -> V_25 ) ;
V_29:
F_28 ( V_2 ) ;
return V_17 ;
}
static int F_29 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = F_30 ( & V_9 -> V_12 ) ;
F_31 ( & V_9 -> V_12 , NULL ) ;
F_11 ( & V_9 -> V_12 , L_13 ) ;
F_32 ( V_2 ) ;
F_26 ( V_2 -> V_32 ) ;
F_27 ( V_2 -> V_16 ) ;
F_24 ( V_2 -> V_23 , V_2 -> V_25 ) ;
F_28 ( V_2 ) ;
return 0 ;
}
static void F_33 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = F_30 ( & V_9 -> V_12 ) ;
if ( V_2 -> V_40 -> V_41 )
V_2 -> V_40 -> V_41 ( V_2 ) ;
}
