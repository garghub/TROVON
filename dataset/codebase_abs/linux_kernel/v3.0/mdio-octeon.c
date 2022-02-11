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
F_2 ( F_3 ( V_6 -> V_18 ) , V_9 . V_13 ) ;
do {
F_4 ( 1000 ) ;
V_11 . V_13 = F_5 ( F_6 ( V_6 -> V_18 ) ) ;
} while ( V_11 . V_14 . V_19 && -- V_12 );
if ( V_11 . V_14 . V_20 )
return V_11 . V_14 . V_21 ;
else
return - V_22 ;
}
static int F_7 ( struct V_1 * V_2 , int V_3 ,
int V_4 , T_1 V_20 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
union V_8 V_9 ;
union V_23 V_24 ;
int V_12 = 1000 ;
V_24 . V_13 = 0 ;
V_24 . V_14 . V_21 = V_20 ;
F_2 ( F_8 ( V_6 -> V_18 ) , V_24 . V_13 ) ;
V_9 . V_13 = 0 ;
V_9 . V_14 . V_15 = 0 ;
V_9 . V_14 . V_16 = V_3 ;
V_9 . V_14 . V_17 = V_4 ;
F_2 ( F_3 ( V_6 -> V_18 ) , V_9 . V_13 ) ;
do {
F_4 ( 1000 ) ;
V_24 . V_13 = F_5 ( F_8 ( V_6 -> V_18 ) ) ;
} while ( V_24 . V_14 . V_19 && -- V_12 );
if ( V_12 <= 0 )
return - V_22 ;
return 0 ;
}
static int T_2 F_9 ( struct V_25 * V_26 )
{
struct V_5 * V_2 ;
union V_27 V_28 ;
int V_29 ;
int V_30 = - V_31 ;
V_2 = F_10 ( & V_26 -> V_32 , sizeof( * V_2 ) , V_33 ) ;
if ( ! V_2 )
return - V_34 ;
V_2 -> V_18 = V_26 -> V_35 ;
V_2 -> V_1 = F_11 () ;
if ( ! V_2 -> V_1 )
goto V_30;
V_28 . V_13 = 0 ;
V_28 . V_14 . V_36 = 1 ;
F_2 ( F_12 ( V_2 -> V_18 ) , V_28 . V_13 ) ;
for ( V_29 = 0 ; V_29 < V_37 ; V_29 ++ )
V_2 -> V_38 [ V_29 ] = V_39 ;
V_2 -> V_1 -> V_7 = V_2 ;
V_2 -> V_1 -> V_40 = V_2 -> V_38 ;
V_2 -> V_1 -> V_41 = L_1 ;
snprintf ( V_2 -> V_1 -> V_35 , V_42 , L_2 , V_2 -> V_18 ) ;
V_2 -> V_1 -> V_43 = & V_26 -> V_32 ;
V_2 -> V_1 -> V_44 = F_1 ;
V_2 -> V_1 -> V_45 = F_7 ;
F_13 ( & V_26 -> V_32 , V_2 ) ;
V_30 = F_14 ( V_2 -> V_1 ) ;
if ( V_30 )
goto V_46;
F_15 ( & V_26 -> V_32 , L_3 V_47 L_4 ) ;
return 0 ;
V_46:
F_16 ( V_2 -> V_1 ) ;
V_30:
F_17 ( & V_26 -> V_32 , V_2 ) ;
V_28 . V_13 = 0 ;
F_2 ( F_12 ( V_2 -> V_18 ) , V_28 . V_13 ) ;
return V_30 ;
}
static int T_3 F_18 ( struct V_25 * V_26 )
{
struct V_5 * V_2 ;
union V_27 V_28 ;
V_2 = F_19 ( & V_26 -> V_32 ) ;
F_20 ( V_2 -> V_1 ) ;
F_16 ( V_2 -> V_1 ) ;
V_28 . V_13 = 0 ;
F_2 ( F_12 ( V_2 -> V_18 ) , V_28 . V_13 ) ;
return 0 ;
}
void F_21 ( void )
{
}
static int T_4 F_22 ( void )
{
return F_23 ( & V_48 ) ;
}
static void T_5 F_24 ( void )
{
F_25 ( & V_48 ) ;
}
