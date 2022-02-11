static int F_1 ( void T_1 * V_1 , bool V_2 )
{
unsigned int V_3 = 1000 ;
T_2 V_4 ;
do {
V_4 = F_2 ( V_1 + V_5 ) ;
if ( ( V_4 & V_6 ) == V_2 )
return 0 ;
F_3 ( 1000 , 2000 ) ;
} while ( V_3 -- );
return - V_7 ;
}
static int F_4 ( void T_1 * V_1 ,
T_3 V_8 , T_2 V_9 , T_3 V_4 , T_2 V_10 )
{
T_2 V_11 ;
int V_12 ;
F_5 ( 0 , V_1 + V_13 ) ;
V_12 = F_1 ( V_1 , 0 ) ;
if ( V_12 )
goto V_14;
V_11 = F_2 ( V_1 + V_15 ) ;
V_11 |= V_8 << V_16 ;
V_11 |= V_4 << V_17 ;
if ( V_9 & V_18 )
V_11 |= F_6 ( V_19 ) ;
F_5 ( V_11 , V_1 + V_15 ) ;
F_5 ( V_9 , V_1 + V_20 ) ;
F_5 ( V_10 , V_1 + V_13 ) ;
V_12 = F_1 ( V_1 , 1 ) ;
if ( V_12 )
goto V_14;
if ( V_10 == V_21 )
V_12 = F_2 ( V_1 + V_22 ) & V_23 ;
V_14:
return V_12 ;
}
static int F_7 ( struct V_24 * V_25 , int V_8 , int V_9 )
{
struct V_26 * V_27 = V_25 -> V_28 ;
int V_12 ;
V_12 = F_4 ( V_27 -> V_1 , V_8 , V_9 , 0 , V_21 ) ;
if ( V_12 < 0 )
F_8 ( & V_25 -> V_29 , L_1 ) ;
return V_12 ;
}
static int F_9 ( struct V_24 * V_25 ,
int V_8 , int V_9 , T_3 V_4 )
{
struct V_26 * V_27 = V_25 -> V_28 ;
int V_12 ;
V_12 = F_4 ( V_27 -> V_1 , V_8 , V_9 , V_4 , V_30 ) ;
if ( V_12 < 0 )
F_8 ( & V_25 -> V_29 , L_2 ) ;
return V_12 ;
}
static int F_10 ( int V_31 , int V_32 ,
void * V_33 )
{
struct V_26 * V_27 = V_33 ;
T_2 V_11 , V_34 ;
bool V_35 ;
V_35 = ( V_32 < V_36 ) ;
V_34 = V_35 ? V_32 : ( V_32 - V_36 ) ;
V_11 = ( V_35 ? 1 : 0 ) << V_37 ;
V_11 |= ( V_34 << V_38 ) ;
F_5 ( V_11 , V_27 -> V_1 + V_15 ) ;
return 0 ;
}
static int F_11 ( struct V_39 * V_40 )
{
struct V_26 * V_27 ;
struct V_24 * V_25 ;
struct V_41 * V_42 ;
int V_43 ;
V_27 = F_12 ( & V_40 -> V_29 , sizeof( * V_27 ) , V_44 ) ;
if ( ! V_27 )
return - V_45 ;
V_27 -> V_29 = & V_40 -> V_29 ;
V_42 = F_13 ( V_40 , V_46 , 0 ) ;
V_27 -> V_1 = F_14 ( & V_40 -> V_29 , V_42 ) ;
if ( F_15 ( V_27 -> V_1 ) ) {
F_8 ( & V_40 -> V_29 , L_3 ) ;
return F_16 ( V_27 -> V_1 ) ;
}
V_27 -> V_24 = F_17 () ;
if ( ! V_27 -> V_24 ) {
F_8 ( & V_40 -> V_29 , L_4 ) ;
return - V_45 ;
}
V_25 = V_27 -> V_24 ;
V_25 -> V_28 = V_27 ;
V_25 -> V_47 = L_5 ;
snprintf ( V_25 -> V_48 , V_49 , L_6 , V_40 -> V_47 , V_40 -> V_48 ) ;
V_25 -> V_50 = & V_40 -> V_29 ;
V_25 -> V_51 = F_7 ;
V_25 -> V_52 = F_9 ;
V_25 -> V_53 = ~ 0 ;
V_25 -> V_29 . V_54 = V_40 -> V_29 . V_54 ;
V_43 = F_18 ( V_25 ) ;
if ( V_43 ) {
F_8 ( & V_40 -> V_29 , L_7 ) ;
goto V_55;
}
F_19 ( V_40 , V_27 ) ;
V_43 = F_20 ( V_27 -> V_29 , V_27 -> V_29 -> V_54 , F_10 ,
& V_27 -> V_56 , V_27 , V_27 -> V_24 ) ;
if ( V_43 ) {
F_21 ( V_27 -> V_29 , L_8 ) ;
goto V_57;
}
F_21 ( V_27 -> V_29 , L_9 ) ;
return 0 ;
V_57:
F_22 ( V_25 ) ;
V_55:
F_23 ( V_25 ) ;
return V_43 ;
}
static int F_24 ( struct V_39 * V_40 )
{
struct V_26 * V_27 = F_25 ( & V_40 -> V_29 ) ;
F_26 ( V_27 -> V_56 ) ;
F_22 ( V_27 -> V_24 ) ;
F_23 ( V_27 -> V_24 ) ;
return 0 ;
}
