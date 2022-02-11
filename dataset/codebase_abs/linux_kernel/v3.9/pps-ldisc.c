static void F_1 ( struct V_1 * V_2 , unsigned int V_3 )
{
struct V_4 * V_5 ;
struct V_6 V_7 ;
F_2 ( & V_7 ) ;
V_5 = F_3 ( V_2 ) ;
if ( F_4 ( V_5 == NULL ) )
return;
F_5 ( V_5 , & V_7 , V_3 ? V_8 :
V_9 , NULL ) ;
F_6 ( V_5 -> V_10 , L_1 ,
V_3 ? L_2 : L_3 , V_11 ) ;
}
static int F_7 ( struct V_1 * V_2 )
{
struct V_12 V_13 ;
struct V_14 * V_15 = V_2 -> V_16 ;
int V_17 = V_2 -> V_17 + V_15 -> V_18 ;
struct V_4 * V_5 ;
int V_19 ;
V_13 . V_20 = V_21 ;
V_13 . V_10 = NULL ;
snprintf ( V_13 . V_22 , V_23 , L_4 , V_15 -> V_24 , V_17 ) ;
snprintf ( V_13 . V_25 , V_23 , L_5 , V_15 -> V_22 , V_17 ) ;
V_13 . V_26 = V_27 | \
V_28 | V_29 | \
V_30 | V_31 ;
V_5 = F_8 ( & V_13 , V_27 | \
V_28 | V_29 ) ;
if ( V_5 == NULL ) {
F_9 ( L_6 , V_13 . V_25 ) ;
return - V_32 ;
}
V_5 -> V_33 = V_2 ;
V_19 = F_10 ( V_2 ) ;
if ( V_19 < 0 ) {
F_9 ( L_7 , V_13 . V_25 ) ;
goto V_34;
}
F_11 ( V_5 -> V_10 , L_8 , V_13 . V_25 ) ;
return 0 ;
V_34:
F_12 ( V_5 ) ;
return V_19 ;
}
static void F_13 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_3 ( V_2 ) ;
F_14 ( V_2 ) ;
if ( F_15 ( ! V_5 ) )
return;
F_11 ( V_5 -> V_10 , L_9 ) ;
F_12 ( V_5 ) ;
}
static int T_1 F_16 ( void )
{
int V_35 ;
F_17 ( & V_36 ) ;
F_10 = V_36 . V_37 ;
F_14 = V_36 . V_38 ;
V_36 . V_20 = V_21 ;
V_36 . V_39 = V_40 ;
V_36 . V_22 = L_10 ;
V_36 . V_41 = F_1 ;
V_36 . V_37 = F_7 ;
V_36 . V_38 = F_13 ;
V_35 = F_18 ( V_42 , & V_36 ) ;
if ( V_35 )
F_9 ( L_11 ) ;
else
F_19 ( L_12 ) ;
return V_35 ;
}
static void T_2 F_20 ( void )
{
int V_35 ;
V_35 = F_21 ( V_42 ) ;
if ( V_35 )
F_9 ( L_13 ) ;
else
F_19 ( L_14 ) ;
}
