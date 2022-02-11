static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
T_1 V_5 ;
unsigned int V_6 ;
V_5 = F_3 ( V_4 -> V_7 + V_8 ) ;
for ( V_6 = 0 ; V_6 < 5 ; ++ V_6 ) {
if ( V_5 & F_4 ( V_6 ) )
F_5 ( V_4 -> V_9 + V_6 ) ;
}
}
static inline void F_6 ( struct V_10 * V_11 )
{
if ( F_7 ( & V_11 -> V_12 ) == 1 )
F_8 ( V_11 -> V_13 ) ;
}
static inline void F_9 ( struct V_10 * V_11 )
{
if ( F_10 ( & V_11 -> V_12 ) == 0 )
F_11 ( V_11 -> V_13 ) ;
}
static inline void F_12 ( struct V_10 * V_11 , int V_14 ,
bool V_15 )
{
unsigned long V_16 ;
T_1 V_17 ;
F_13 ( & V_11 -> V_18 , V_16 ) ;
V_17 = F_3 ( V_11 -> V_19 + V_20 ) ;
if ( V_15 )
V_17 |= F_4 ( V_14 ) ;
else
V_17 &= ~ F_4 ( V_14 ) ;
F_14 ( V_17 , V_11 -> V_19 + V_20 ) ;
F_15 ( & V_11 -> V_18 , V_16 ) ;
}
static int F_16 ( struct V_21 * V_22 )
{
struct V_10 * V_11 = F_17 ( V_22 -> V_23 . V_24 ) ;
F_6 ( V_11 ) ;
F_12 ( V_11 , V_22 -> V_25 , true ) ;
return 0 ;
}
static int F_18 ( struct V_21 * V_22 )
{
struct V_10 * V_11 = F_17 ( V_22 -> V_23 . V_24 ) ;
F_12 ( V_11 , V_22 -> V_25 , false ) ;
F_9 ( V_11 ) ;
return 0 ;
}
int F_19 ( struct V_26 * V_23 , T_2 V_27 , T_2 V_17 )
{
struct V_10 * V_11 = F_17 ( V_23 ) ;
unsigned long V_16 ;
T_2 V_28 ;
if ( ! V_11 )
return - V_29 ;
F_13 ( & V_11 -> V_18 , V_16 ) ;
V_28 = F_20 ( V_11 -> V_19 + V_30 ) ;
V_28 &= ~ V_27 ;
V_28 |= V_17 ;
F_21 ( V_28 , V_11 -> V_19 + V_30 ) ;
F_15 ( & V_11 -> V_18 , V_16 ) ;
return 0 ;
}
static int F_22 ( struct V_21 * V_22 )
{
struct V_3 * V_4 ;
struct V_31 * V_32 ;
struct V_10 * V_11 ;
struct V_33 * V_34 ;
int V_35 ;
int V_9 ;
V_11 = F_23 ( & V_22 -> V_23 , sizeof( * V_11 ) , V_36 ) ;
if ( ! V_11 ) {
F_24 ( & V_22 -> V_23 , L_1 ) ;
return - V_37 ;
}
V_11 -> V_38 = F_25 ( V_22 , 0 ) ;
if ( V_11 -> V_38 < 0 ) {
V_35 = V_11 -> V_38 ;
F_24 ( & V_22 -> V_23 , L_2 , V_35 ) ;
return V_35 ;
}
V_9 = F_25 ( V_22 , 1 ) ;
if ( V_9 < 0 ) {
F_24 ( & V_22 -> V_23 , L_3 , V_9 ) ;
return V_9 ;
}
V_34 = F_26 ( V_22 , V_39 , 0 ) ;
if ( ! V_34 ) {
F_24 ( & V_22 -> V_23 , L_4 ) ;
return - V_40 ;
}
V_11 -> V_41 = F_27 ( V_34 -> V_42 , V_8 ,
V_22 -> V_43 ) ;
if ( ! V_11 -> V_41 ) {
F_24 ( & V_22 -> V_23 , L_5 ) ;
return - V_44 ;
}
V_11 -> V_19 = F_28 ( V_11 -> V_41 -> V_42 , F_29 ( V_11 -> V_41 ) ) ;
if ( ! V_11 -> V_19 ) {
V_35 = - V_44 ;
F_24 ( & V_22 -> V_23 , L_6 ) ;
goto V_45;
}
V_11 -> V_13 = F_30 ( & V_22 -> V_23 , L_7 ) ;
if ( F_31 ( V_11 -> V_13 ) ) {
V_35 = F_32 ( V_11 -> V_13 ) ;
F_24 ( & V_22 -> V_23 , L_8 , V_35 ) ;
goto V_46;
}
F_33 ( & V_11 -> V_18 ) ;
F_34 ( & V_11 -> V_12 , 0 ) ;
F_35 ( V_22 , V_11 ) ;
V_4 = F_36 ( L_9 , 1 , V_9 , V_11 -> V_19 ,
V_47 ) ;
V_32 = V_4 -> V_48 ;
V_32 -> V_49 . V_27 = V_50 ;
V_32 -> V_49 . V_51 = V_8 ;
V_32 -> V_52 . V_53 = V_54 ;
V_32 -> V_52 . V_55 = V_56 ;
V_32 -> V_52 . V_57 = V_58 ;
F_37 ( V_4 , F_38 ( 5 ) , V_59 , 0 ,
V_60 | V_61 ) ;
V_11 -> V_4 = V_4 ;
F_39 ( V_11 -> V_38 , F_1 , V_4 ) ;
F_14 ( 0x00 , V_11 -> V_19 + V_20 ) ;
F_14 ( 0xff , V_11 -> V_19 + V_50 ) ;
V_35 = F_40 ( & V_22 -> V_23 , 0 , V_62 ,
F_41 ( V_62 ) , V_34 ,
V_9 , NULL ) ;
if ( V_35 < 0 )
goto V_63;
return 0 ;
V_63:
F_42 ( V_11 -> V_13 ) ;
V_46:
F_43 ( V_11 -> V_19 ) ;
V_45:
F_44 ( V_11 -> V_41 -> V_42 , F_29 ( V_11 -> V_41 ) ) ;
return V_35 ;
}
static int F_45 ( struct V_21 * V_22 )
{
struct V_10 * V_11 = F_46 ( V_22 ) ;
F_47 ( & V_22 -> V_23 ) ;
F_48 ( V_11 -> V_4 , F_38 ( 5 ) , V_60 | V_61 , 0 ) ;
F_49 ( V_11 -> V_4 ) ;
F_39 ( V_11 -> V_38 , NULL , NULL ) ;
F_43 ( V_11 -> V_19 ) ;
F_44 ( V_11 -> V_41 -> V_42 , F_29 ( V_11 -> V_41 ) ) ;
F_42 ( V_11 -> V_13 ) ;
return 0 ;
}
