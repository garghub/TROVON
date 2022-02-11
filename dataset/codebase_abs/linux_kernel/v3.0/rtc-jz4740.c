static inline T_1 F_1 ( struct V_1 * V_2 , T_2 V_3 )
{
return F_2 ( V_2 -> V_4 + V_3 ) ;
}
static int F_3 ( struct V_1 * V_2 )
{
T_1 V_5 ;
int V_6 = 1000 ;
do {
V_5 = F_1 ( V_2 , V_7 ) ;
} while ( ! ( V_5 & V_8 ) && -- V_6 );
return V_6 ? 0 : - V_9 ;
}
static inline int F_4 ( struct V_1 * V_2 , T_2 V_3 ,
T_1 V_10 )
{
int V_11 ;
V_11 = F_3 ( V_2 ) ;
if ( V_11 == 0 )
F_5 ( V_10 , V_2 -> V_4 + V_3 ) ;
return V_11 ;
}
static int F_6 ( struct V_1 * V_2 , T_1 V_12 ,
bool V_13 )
{
int V_11 ;
unsigned long V_14 ;
T_1 V_5 ;
F_7 ( & V_2 -> V_15 , V_14 ) ;
V_5 = F_1 ( V_2 , V_7 ) ;
V_5 |= V_16 | V_17 ;
if ( V_13 )
V_5 |= V_12 ;
else
V_5 &= ~ V_12 ;
V_11 = F_4 ( V_2 , V_7 , V_5 ) ;
F_8 ( & V_2 -> V_15 , V_14 ) ;
return V_11 ;
}
static int F_9 ( struct V_18 * V_19 , struct V_20 * time )
{
struct V_1 * V_2 = F_10 ( V_19 ) ;
T_1 V_21 , V_22 ;
int V_6 = 5 ;
V_21 = F_1 ( V_2 , V_23 ) ;
V_22 = F_1 ( V_2 , V_23 ) ;
while ( V_21 != V_22 && -- V_6 ) {
V_21 = V_22 ;
V_22 = F_1 ( V_2 , V_23 ) ;
}
if ( V_6 == 0 )
return - V_9 ;
F_11 ( V_21 , time ) ;
return F_12 ( time ) ;
}
static int F_13 ( struct V_18 * V_19 , unsigned long V_21 )
{
struct V_1 * V_2 = F_10 ( V_19 ) ;
return F_4 ( V_2 , V_23 , V_21 ) ;
}
static int F_14 ( struct V_18 * V_19 , struct V_24 * V_25 )
{
struct V_1 * V_2 = F_10 ( V_19 ) ;
T_1 V_21 ;
T_1 V_5 ;
V_21 = F_1 ( V_2 , V_26 ) ;
V_5 = F_1 ( V_2 , V_7 ) ;
V_25 -> V_27 = ! ! ( V_5 & V_28 ) ;
V_25 -> V_29 = ! ! ( V_5 & V_17 ) ;
F_11 ( V_21 , & V_25 -> time ) ;
return F_12 ( & V_25 -> time ) ;
}
static int F_15 ( struct V_18 * V_19 , struct V_24 * V_25 )
{
int V_11 ;
struct V_1 * V_2 = F_10 ( V_19 ) ;
unsigned long V_21 ;
F_16 ( & V_25 -> time , & V_21 ) ;
V_11 = F_4 ( V_2 , V_26 , V_21 ) ;
if ( ! V_11 )
V_11 = F_6 ( V_2 ,
V_28 | V_30 , V_25 -> V_27 ) ;
return V_11 ;
}
static int F_17 ( struct V_18 * V_19 , unsigned int V_31 )
{
struct V_1 * V_2 = F_10 ( V_19 ) ;
return F_6 ( V_2 , V_30 , V_31 ) ;
}
static T_3 F_18 ( int V_32 , void * V_33 )
{
struct V_1 * V_2 = V_33 ;
T_1 V_5 ;
unsigned long V_34 = 0 ;
V_5 = F_1 ( V_2 , V_7 ) ;
if ( V_5 & V_16 )
V_34 |= ( V_35 | V_36 ) ;
if ( V_5 & V_17 )
V_34 |= ( V_37 | V_36 ) ;
F_19 ( V_2 -> V_2 , 1 , V_34 ) ;
F_6 ( V_2 , V_16 | V_17 , false ) ;
return V_38 ;
}
void F_20 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = F_10 ( V_19 ) ;
F_4 ( V_2 , V_39 , 1 ) ;
}
static int T_4 F_21 ( struct V_40 * V_41 )
{
int V_11 ;
struct V_1 * V_2 ;
T_1 V_42 ;
V_2 = F_22 ( sizeof( * V_2 ) , V_43 ) ;
if ( ! V_2 )
return - V_44 ;
V_2 -> V_32 = F_23 ( V_41 , 0 ) ;
if ( V_2 -> V_32 < 0 ) {
V_11 = - V_45 ;
F_24 ( & V_41 -> V_19 , L_1 ) ;
goto V_46;
}
V_2 -> V_47 = F_25 ( V_41 , V_48 , 0 ) ;
if ( ! V_2 -> V_47 ) {
V_11 = - V_45 ;
F_24 ( & V_41 -> V_19 , L_2 ) ;
goto V_46;
}
V_2 -> V_47 = F_26 ( V_2 -> V_47 -> V_49 , F_27 ( V_2 -> V_47 ) ,
V_41 -> V_50 ) ;
if ( ! V_2 -> V_47 ) {
V_11 = - V_51 ;
F_24 ( & V_41 -> V_19 , L_3 ) ;
goto V_46;
}
V_2 -> V_4 = F_28 ( V_2 -> V_47 -> V_49 , F_27 ( V_2 -> V_47 ) ) ;
if ( ! V_2 -> V_4 ) {
V_11 = - V_51 ;
F_24 ( & V_41 -> V_19 , L_4 ) ;
goto V_52;
}
F_29 ( & V_2 -> V_15 ) ;
F_30 ( V_41 , V_2 ) ;
F_31 ( & V_41 -> V_19 , 1 ) ;
V_2 -> V_2 = F_32 ( V_41 -> V_50 , & V_41 -> V_19 , & V_53 ,
V_54 ) ;
if ( F_33 ( V_2 -> V_2 ) ) {
V_11 = F_34 ( V_2 -> V_2 ) ;
F_24 ( & V_41 -> V_19 , L_5 , V_11 ) ;
goto V_55;
}
V_11 = F_35 ( V_2 -> V_32 , F_18 , 0 ,
V_41 -> V_50 , V_2 ) ;
if ( V_11 ) {
F_24 ( & V_41 -> V_19 , L_6 , V_11 ) ;
goto V_56;
}
V_42 = F_1 ( V_2 , V_57 ) ;
if ( V_42 != 0x12345678 ) {
V_11 = F_4 ( V_2 , V_57 , 0x12345678 ) ;
V_11 = F_4 ( V_2 , V_23 , 0 ) ;
if ( V_11 ) {
F_24 ( & V_41 -> V_19 , L_7 ) ;
goto V_58;
}
}
return 0 ;
V_58:
F_36 ( V_2 -> V_32 , V_2 ) ;
V_56:
F_37 ( V_2 -> V_2 ) ;
V_55:
F_30 ( V_41 , NULL ) ;
F_38 ( V_2 -> V_4 ) ;
V_52:
F_39 ( V_2 -> V_47 -> V_49 , F_27 ( V_2 -> V_47 ) ) ;
V_46:
F_40 ( V_2 ) ;
return V_11 ;
}
static int T_5 F_41 ( struct V_40 * V_41 )
{
struct V_1 * V_2 = F_42 ( V_41 ) ;
F_36 ( V_2 -> V_32 , V_2 ) ;
F_37 ( V_2 -> V_2 ) ;
F_38 ( V_2 -> V_4 ) ;
F_39 ( V_2 -> V_47 -> V_49 , F_27 ( V_2 -> V_47 ) ) ;
F_40 ( V_2 ) ;
F_30 ( V_41 , NULL ) ;
return 0 ;
}
static int F_43 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = F_10 ( V_19 ) ;
if ( F_44 ( V_19 ) )
F_45 ( V_2 -> V_32 ) ;
return 0 ;
}
static int F_46 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = F_10 ( V_19 ) ;
if ( F_44 ( V_19 ) )
F_47 ( V_2 -> V_32 ) ;
return 0 ;
}
static int T_6 F_48 ( void )
{
return F_49 ( & V_59 ) ;
}
static void T_7 F_50 ( void )
{
F_51 ( & V_59 ) ;
}
