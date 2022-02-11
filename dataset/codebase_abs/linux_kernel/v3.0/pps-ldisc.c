static void F_1 ( struct V_1 * V_2 , unsigned int V_3 ,
struct V_4 * V_5 )
{
struct V_6 * V_7 = (struct V_6 * ) V_2 -> V_8 ;
F_2 ( V_7 == NULL ) ;
F_3 ( V_7 , V_5 , V_3 ? V_9 :
V_10 , NULL ) ;
F_4 ( V_7 -> V_11 , L_1 ,
V_3 ? L_2 : L_3 , V_12 ) ;
}
static int F_5 ( struct V_1 * V_2 )
{
struct V_13 V_14 ;
struct V_15 * V_16 = V_2 -> V_17 ;
int V_18 = V_2 -> V_18 + V_16 -> V_19 ;
struct V_6 * V_7 ;
int V_20 ;
V_14 . V_21 = V_22 ;
V_14 . V_11 = NULL ;
snprintf ( V_14 . V_23 , V_24 , L_4 , V_16 -> V_25 , V_18 ) ;
snprintf ( V_14 . V_26 , V_24 , L_5 , V_16 -> V_23 , V_18 ) ;
V_14 . V_27 = V_28 | \
V_29 | V_30 | \
V_31 | V_32 ;
V_7 = F_6 ( & V_14 , V_28 | \
V_29 | V_30 ) ;
if ( V_7 == NULL ) {
F_7 ( L_6 , V_14 . V_26 ) ;
return - V_33 ;
}
V_2 -> V_8 = V_7 ;
V_20 = F_8 ( V_2 ) ;
if ( V_20 < 0 ) {
F_7 ( L_7 , V_14 . V_26 ) ;
goto V_34;
}
F_9 ( V_7 -> V_11 , L_8 , V_14 . V_26 ) ;
return 0 ;
V_34:
V_2 -> V_8 = NULL ;
F_10 ( V_7 ) ;
return V_20 ;
}
static void F_11 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = (struct V_6 * ) V_2 -> V_8 ;
F_12 ( V_2 ) ;
V_2 -> V_8 = NULL ;
F_9 ( V_7 -> V_11 , L_9 ) ;
F_10 ( V_7 ) ;
}
static int T_1 F_13 ( void )
{
int V_35 ;
F_14 ( & V_36 ) ;
F_8 = V_36 . V_37 ;
F_12 = V_36 . V_38 ;
V_36 . V_21 = V_22 ;
V_36 . V_39 = V_40 ;
V_36 . V_23 = L_10 ;
V_36 . V_41 = F_1 ;
V_36 . V_37 = F_5 ;
V_36 . V_38 = F_11 ;
V_35 = F_15 ( V_42 , & V_36 ) ;
if ( V_35 )
F_7 ( L_11 ) ;
else
F_16 ( L_12 ) ;
return V_35 ;
}
static void T_2 F_17 ( void )
{
int V_35 ;
V_35 = F_18 ( V_42 ) ;
if ( V_35 )
F_7 ( L_13 ) ;
else
F_16 ( L_14 ) ;
}
