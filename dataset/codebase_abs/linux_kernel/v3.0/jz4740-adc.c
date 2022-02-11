static inline void F_1 ( struct V_1 * V_2 , int V_3 ,
bool V_4 )
{
unsigned long V_5 ;
T_1 V_6 ;
V_3 -= V_2 -> V_7 ;
F_2 ( & V_2 -> V_8 , V_5 ) ;
V_6 = F_3 ( V_2 -> V_9 + V_10 ) ;
if ( V_4 )
V_6 |= F_4 ( V_3 ) ;
else
V_6 &= ~ F_4 ( V_3 ) ;
F_5 ( V_6 , V_2 -> V_9 + V_10 ) ;
F_6 ( & V_2 -> V_8 , V_5 ) ;
}
static void F_7 ( struct V_11 * V_12 )
{
struct V_1 * V_2 = F_8 ( V_12 ) ;
F_1 ( V_2 , V_12 -> V_3 , true ) ;
}
static void F_9 ( struct V_11 * V_12 )
{
struct V_1 * V_2 = F_8 ( V_12 ) ;
F_1 ( V_2 , V_12 -> V_3 , false ) ;
}
static void F_10 ( struct V_11 * V_12 )
{
struct V_1 * V_2 = F_8 ( V_12 ) ;
unsigned int V_3 = V_12 -> V_3 - V_2 -> V_7 ;
F_5 ( F_4 ( V_3 ) , V_2 -> V_9 + V_13 ) ;
}
static void F_11 ( unsigned int V_3 , struct V_14 * V_15 )
{
struct V_1 * V_2 = F_12 ( V_15 ) ;
T_1 V_16 ;
unsigned int V_17 ;
V_16 = F_3 ( V_2 -> V_9 + V_13 ) ;
for ( V_17 = 0 ; V_17 < 5 ; ++ V_17 ) {
if ( V_16 & F_4 ( V_17 ) )
F_13 ( V_2 -> V_7 + V_17 ) ;
}
}
static inline void F_14 ( struct V_1 * V_2 )
{
if ( F_15 ( & V_2 -> V_18 ) == 1 )
F_16 ( V_2 -> V_19 ) ;
}
static inline void F_17 ( struct V_1 * V_2 )
{
if ( F_18 ( & V_2 -> V_18 ) == 0 )
F_19 ( V_2 -> V_19 ) ;
}
static inline void F_20 ( struct V_1 * V_2 , int V_20 ,
bool V_21 )
{
unsigned long V_5 ;
T_1 V_6 ;
F_2 ( & V_2 -> V_8 , V_5 ) ;
V_6 = F_3 ( V_2 -> V_9 + V_22 ) ;
if ( V_21 )
V_6 |= F_4 ( V_20 ) ;
else
V_6 &= ~ F_4 ( V_20 ) ;
F_5 ( V_6 , V_2 -> V_9 + V_22 ) ;
F_6 ( & V_2 -> V_8 , V_5 ) ;
}
static int F_21 ( struct V_23 * V_24 )
{
struct V_1 * V_2 = F_22 ( V_24 -> V_25 . V_26 ) ;
F_14 ( V_2 ) ;
F_20 ( V_2 , V_24 -> V_27 , true ) ;
return 0 ;
}
static int F_23 ( struct V_23 * V_24 )
{
struct V_1 * V_2 = F_22 ( V_24 -> V_25 . V_26 ) ;
F_20 ( V_2 , V_24 -> V_27 , false ) ;
F_17 ( V_2 ) ;
return 0 ;
}
int F_24 ( struct V_28 * V_25 , T_2 V_29 , T_2 V_6 )
{
struct V_1 * V_2 = F_22 ( V_25 ) ;
unsigned long V_5 ;
T_2 V_30 ;
if ( ! V_2 )
return - V_31 ;
F_2 ( & V_2 -> V_8 , V_5 ) ;
V_30 = F_25 ( V_2 -> V_9 + V_32 ) ;
V_30 &= ~ V_29 ;
V_30 |= V_6 ;
F_26 ( V_30 , V_2 -> V_9 + V_32 ) ;
F_6 ( & V_2 -> V_8 , V_5 ) ;
return 0 ;
}
static int T_3 F_27 ( struct V_23 * V_24 )
{
int V_33 ;
struct V_1 * V_2 ;
struct V_34 * V_35 ;
int V_3 ;
V_2 = F_28 ( sizeof( * V_2 ) , V_36 ) ;
if ( ! V_2 ) {
F_29 ( & V_24 -> V_25 , L_1 ) ;
return - V_37 ;
}
V_2 -> V_3 = F_30 ( V_24 , 0 ) ;
if ( V_2 -> V_3 < 0 ) {
V_33 = V_2 -> V_3 ;
F_29 ( & V_24 -> V_25 , L_2 , V_33 ) ;
goto V_38;
}
V_2 -> V_7 = F_30 ( V_24 , 1 ) ;
if ( V_2 -> V_7 < 0 ) {
V_33 = V_2 -> V_7 ;
F_29 ( & V_24 -> V_25 , L_3 , V_33 ) ;
goto V_38;
}
V_35 = F_31 ( V_24 , V_39 , 0 ) ;
if ( ! V_35 ) {
V_33 = - V_40 ;
F_29 ( & V_24 -> V_25 , L_4 ) ;
goto V_38;
}
V_2 -> V_41 = F_32 ( V_35 -> V_42 , V_13 ,
V_24 -> V_43 ) ;
if ( ! V_2 -> V_41 ) {
V_33 = - V_44 ;
F_29 ( & V_24 -> V_25 , L_5 ) ;
goto V_38;
}
V_2 -> V_9 = F_33 ( V_2 -> V_41 -> V_42 , F_34 ( V_2 -> V_41 ) ) ;
if ( ! V_2 -> V_9 ) {
V_33 = - V_44 ;
F_29 ( & V_24 -> V_25 , L_6 ) ;
goto V_45;
}
V_2 -> V_19 = F_35 ( & V_24 -> V_25 , L_7 ) ;
if ( F_36 ( V_2 -> V_19 ) ) {
V_33 = F_37 ( V_2 -> V_19 ) ;
F_29 ( & V_24 -> V_25 , L_8 , V_33 ) ;
goto V_46;
}
F_38 ( & V_2 -> V_8 ) ;
F_39 ( & V_2 -> V_18 , 0 ) ;
F_40 ( V_24 , V_2 ) ;
for ( V_3 = V_2 -> V_7 ; V_3 < V_2 -> V_7 + 5 ; ++ V_3 ) {
F_41 ( V_3 , V_2 ) ;
F_42 ( V_3 , & V_47 ,
V_48 ) ;
}
F_43 ( V_2 -> V_3 , V_2 ) ;
F_44 ( V_2 -> V_3 , F_11 ) ;
F_5 ( 0x00 , V_2 -> V_9 + V_22 ) ;
F_5 ( 0xff , V_2 -> V_9 + V_10 ) ;
V_33 = F_45 ( & V_24 -> V_25 , 0 , V_49 ,
F_46 ( V_49 ) , V_35 , V_2 -> V_7 ) ;
if ( V_33 < 0 )
goto V_50;
return 0 ;
V_50:
F_47 ( V_2 -> V_19 ) ;
V_46:
F_40 ( V_24 , NULL ) ;
F_48 ( V_2 -> V_9 ) ;
V_45:
F_49 ( V_2 -> V_41 -> V_42 , F_34 ( V_2 -> V_41 ) ) ;
V_38:
F_50 ( V_2 ) ;
return V_33 ;
}
static int T_4 F_51 ( struct V_23 * V_24 )
{
struct V_1 * V_2 = F_52 ( V_24 ) ;
F_53 ( & V_24 -> V_25 ) ;
F_43 ( V_2 -> V_3 , NULL ) ;
F_44 ( V_2 -> V_3 , NULL ) ;
F_48 ( V_2 -> V_9 ) ;
F_49 ( V_2 -> V_41 -> V_42 , F_34 ( V_2 -> V_41 ) ) ;
F_47 ( V_2 -> V_19 ) ;
F_40 ( V_24 , NULL ) ;
F_50 ( V_2 ) ;
return 0 ;
}
static int T_5 F_54 ( void )
{
return F_55 ( & V_51 ) ;
}
static void T_6 F_56 ( void )
{
F_57 ( & V_51 ) ;
}
