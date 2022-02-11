static int F_1 ( struct V_1 * V_2 , int V_3 , int V_4 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
union V_8 V_9 ;
union V_10 V_11 ;
int V_12 = 1000 ;
V_9 . V_13 = 0 ;
V_9 . V_14 . V_15 = 1 ;
V_9 . V_14 . V_16 = V_3 ;
V_9 . V_14 . V_17 = V_4 ;
F_2 ( V_6 -> V_18 + V_19 , V_9 . V_13 ) ;
do {
F_3 ( 1000 ) ;
V_11 . V_13 = F_4 ( V_6 -> V_18 + V_20 ) ;
} while ( V_11 . V_14 . V_21 && -- V_12 );
if ( V_11 . V_14 . V_22 )
return V_11 . V_14 . V_23 ;
else
return - V_24 ;
}
static int F_5 ( struct V_1 * V_2 , int V_3 ,
int V_4 , T_1 V_22 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
union V_8 V_9 ;
union V_25 V_26 ;
int V_12 = 1000 ;
V_26 . V_13 = 0 ;
V_26 . V_14 . V_23 = V_22 ;
F_2 ( V_6 -> V_18 + V_27 , V_26 . V_13 ) ;
V_9 . V_13 = 0 ;
V_9 . V_14 . V_15 = 0 ;
V_9 . V_14 . V_16 = V_3 ;
V_9 . V_14 . V_17 = V_4 ;
F_2 ( V_6 -> V_18 + V_19 , V_9 . V_13 ) ;
do {
F_3 ( 1000 ) ;
V_26 . V_13 = F_4 ( V_6 -> V_18 + V_27 ) ;
} while ( V_26 . V_14 . V_21 && -- V_12 );
if ( V_12 <= 0 )
return - V_24 ;
return 0 ;
}
static int T_2 F_6 ( struct V_28 * V_29 )
{
struct V_5 * V_2 ;
struct V_30 * V_31 ;
union V_32 V_33 ;
int V_34 = - V_35 ;
V_2 = F_7 ( & V_29 -> V_36 , sizeof( * V_2 ) , V_37 ) ;
if ( ! V_2 )
return - V_38 ;
V_31 = F_8 ( V_29 , V_39 , 0 ) ;
if ( V_31 == NULL ) {
F_9 ( & V_29 -> V_36 , L_1 ) ;
V_34 = - V_40 ;
goto V_41;
}
V_2 -> V_42 = V_31 -> V_43 ;
V_2 -> V_44 = F_10 ( V_31 ) ;
if ( ! F_11 ( & V_29 -> V_36 , V_2 -> V_42 , V_2 -> V_44 ,
V_31 -> V_45 ) ) {
F_9 ( & V_29 -> V_36 , L_2 ) ;
goto V_41;
}
V_2 -> V_18 =
( V_13 ) F_12 ( & V_29 -> V_36 , V_2 -> V_42 , V_2 -> V_44 ) ;
V_2 -> V_1 = F_13 () ;
if ( ! V_2 -> V_1 )
goto V_41;
V_33 . V_13 = 0 ;
V_33 . V_14 . V_46 = 1 ;
F_2 ( V_2 -> V_18 + V_47 , V_33 . V_13 ) ;
V_2 -> V_1 -> V_7 = V_2 ;
V_2 -> V_1 -> V_48 = V_2 -> V_49 ;
V_2 -> V_1 -> V_45 = L_3 ;
snprintf ( V_2 -> V_1 -> V_50 , V_51 , L_4 , V_2 -> V_18 ) ;
V_2 -> V_1 -> V_52 = & V_29 -> V_36 ;
V_2 -> V_1 -> V_53 = F_1 ;
V_2 -> V_1 -> V_54 = F_5 ;
F_14 ( & V_29 -> V_36 , V_2 ) ;
V_34 = F_15 ( V_2 -> V_1 , V_29 -> V_36 . V_55 ) ;
if ( V_34 )
goto V_56;
F_16 ( & V_29 -> V_36 , L_5 V_57 L_6 ) ;
return 0 ;
V_56:
F_17 ( V_2 -> V_1 ) ;
V_41:
V_33 . V_13 = 0 ;
F_2 ( V_2 -> V_18 + V_47 , V_33 . V_13 ) ;
return V_34 ;
}
static int T_3 F_18 ( struct V_28 * V_29 )
{
struct V_5 * V_2 ;
union V_32 V_33 ;
V_2 = F_19 ( & V_29 -> V_36 ) ;
F_20 ( V_2 -> V_1 ) ;
F_17 ( V_2 -> V_1 ) ;
V_33 . V_13 = 0 ;
F_2 ( V_2 -> V_18 + V_47 , V_33 . V_13 ) ;
return 0 ;
}
void F_21 ( void )
{
}
static int T_4 F_22 ( void )
{
return F_23 ( & V_58 ) ;
}
static void T_5 F_24 ( void )
{
F_25 ( & V_58 ) ;
}
