static void F_1 ( unsigned int V_1 , struct V_2 * V_3 )
{
struct V_4 * V_5 = F_2 ( V_3 ) ;
T_1 V_6 ;
unsigned int V_7 ;
V_6 = F_3 ( V_5 -> V_8 + V_9 ) ;
for ( V_7 = 0 ; V_7 < 5 ; ++ V_7 ) {
if ( V_6 & F_4 ( V_7 ) )
F_5 ( V_5 -> V_10 + V_7 ) ;
}
}
static inline void F_6 ( struct V_11 * V_12 )
{
if ( F_7 ( & V_12 -> V_13 ) == 1 )
F_8 ( V_12 -> V_14 ) ;
}
static inline void F_9 ( struct V_11 * V_12 )
{
if ( F_10 ( & V_12 -> V_13 ) == 0 )
F_11 ( V_12 -> V_14 ) ;
}
static inline void F_12 ( struct V_11 * V_12 , int V_15 ,
bool V_16 )
{
unsigned long V_17 ;
T_1 V_18 ;
F_13 ( & V_12 -> V_19 , V_17 ) ;
V_18 = F_3 ( V_12 -> V_20 + V_21 ) ;
if ( V_16 )
V_18 |= F_4 ( V_15 ) ;
else
V_18 &= ~ F_4 ( V_15 ) ;
F_14 ( V_18 , V_12 -> V_20 + V_21 ) ;
F_15 ( & V_12 -> V_19 , V_17 ) ;
}
static int F_16 ( struct V_22 * V_23 )
{
struct V_11 * V_12 = F_17 ( V_23 -> V_24 . V_25 ) ;
F_6 ( V_12 ) ;
F_12 ( V_12 , V_23 -> V_26 , true ) ;
return 0 ;
}
static int F_18 ( struct V_22 * V_23 )
{
struct V_11 * V_12 = F_17 ( V_23 -> V_24 . V_25 ) ;
F_12 ( V_12 , V_23 -> V_26 , false ) ;
F_9 ( V_12 ) ;
return 0 ;
}
int F_19 ( struct V_27 * V_24 , T_2 V_28 , T_2 V_18 )
{
struct V_11 * V_12 = F_17 ( V_24 ) ;
unsigned long V_17 ;
T_2 V_29 ;
if ( ! V_12 )
return - V_30 ;
F_13 ( & V_12 -> V_19 , V_17 ) ;
V_29 = F_20 ( V_12 -> V_20 + V_31 ) ;
V_29 &= ~ V_28 ;
V_29 |= V_18 ;
F_21 ( V_29 , V_12 -> V_20 + V_31 ) ;
F_15 ( & V_12 -> V_19 , V_17 ) ;
return 0 ;
}
static int T_3 F_22 ( struct V_22 * V_23 )
{
struct V_4 * V_5 ;
struct V_32 * V_33 ;
struct V_11 * V_12 ;
struct V_34 * V_35 ;
int V_36 ;
int V_10 ;
V_12 = F_23 ( sizeof( * V_12 ) , V_37 ) ;
if ( ! V_12 ) {
F_24 ( & V_23 -> V_24 , L_1 ) ;
return - V_38 ;
}
V_12 -> V_1 = F_25 ( V_23 , 0 ) ;
if ( V_12 -> V_1 < 0 ) {
V_36 = V_12 -> V_1 ;
F_24 ( & V_23 -> V_24 , L_2 , V_36 ) ;
goto V_39;
}
V_10 = F_25 ( V_23 , 1 ) ;
if ( V_10 < 0 ) {
V_36 = V_10 ;
F_24 ( & V_23 -> V_24 , L_3 , V_36 ) ;
goto V_39;
}
V_35 = F_26 ( V_23 , V_40 , 0 ) ;
if ( ! V_35 ) {
V_36 = - V_41 ;
F_24 ( & V_23 -> V_24 , L_4 ) ;
goto V_39;
}
V_12 -> V_42 = F_27 ( V_35 -> V_43 , V_9 ,
V_23 -> V_44 ) ;
if ( ! V_12 -> V_42 ) {
V_36 = - V_45 ;
F_24 ( & V_23 -> V_24 , L_5 ) ;
goto V_39;
}
V_12 -> V_20 = F_28 ( V_12 -> V_42 -> V_43 , F_29 ( V_12 -> V_42 ) ) ;
if ( ! V_12 -> V_20 ) {
V_36 = - V_45 ;
F_24 ( & V_23 -> V_24 , L_6 ) ;
goto V_46;
}
V_12 -> V_14 = F_30 ( & V_23 -> V_24 , L_7 ) ;
if ( F_31 ( V_12 -> V_14 ) ) {
V_36 = F_32 ( V_12 -> V_14 ) ;
F_24 ( & V_23 -> V_24 , L_8 , V_36 ) ;
goto V_47;
}
F_33 ( & V_12 -> V_19 ) ;
F_34 ( & V_12 -> V_13 , 0 ) ;
F_35 ( V_23 , V_12 ) ;
V_5 = F_36 ( L_9 , 1 , V_10 , V_12 -> V_20 ,
V_48 ) ;
V_33 = V_5 -> V_49 ;
V_33 -> V_50 . V_28 = V_51 ;
V_33 -> V_50 . V_52 = V_9 ;
V_33 -> V_53 . V_54 = V_55 ;
V_33 -> V_53 . V_56 = V_57 ;
V_33 -> V_53 . V_58 = V_59 ;
F_37 ( V_5 , F_38 ( 5 ) , 0 , 0 , V_60 | V_61 ) ;
V_12 -> V_5 = V_5 ;
F_39 ( V_12 -> V_1 , V_5 ) ;
F_40 ( V_12 -> V_1 , F_1 ) ;
F_14 ( 0x00 , V_12 -> V_20 + V_21 ) ;
F_14 ( 0xff , V_12 -> V_20 + V_51 ) ;
V_36 = F_41 ( & V_23 -> V_24 , 0 , V_62 ,
F_42 ( V_62 ) , V_35 , V_10 ) ;
if ( V_36 < 0 )
goto V_63;
return 0 ;
V_63:
F_43 ( V_12 -> V_14 ) ;
V_47:
F_35 ( V_23 , NULL ) ;
F_44 ( V_12 -> V_20 ) ;
V_46:
F_45 ( V_12 -> V_42 -> V_43 , F_29 ( V_12 -> V_42 ) ) ;
V_39:
F_46 ( V_12 ) ;
return V_36 ;
}
static int T_4 F_47 ( struct V_22 * V_23 )
{
struct V_11 * V_12 = F_48 ( V_23 ) ;
F_49 ( & V_23 -> V_24 ) ;
F_50 ( V_12 -> V_5 , F_38 ( 5 ) , V_60 | V_61 , 0 ) ;
F_46 ( V_12 -> V_5 ) ;
F_39 ( V_12 -> V_1 , NULL ) ;
F_40 ( V_12 -> V_1 , NULL ) ;
F_44 ( V_12 -> V_20 ) ;
F_45 ( V_12 -> V_42 -> V_43 , F_29 ( V_12 -> V_42 ) ) ;
F_43 ( V_12 -> V_14 ) ;
F_35 ( V_23 , NULL ) ;
F_46 ( V_12 ) ;
return 0 ;
}
