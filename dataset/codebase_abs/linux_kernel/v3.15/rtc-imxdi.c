static void F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
unsigned long V_4 ;
F_2 ( & V_2 -> V_5 , V_4 ) ;
F_3 ( F_4 ( V_2 -> V_6 + V_7 ) | V_3 ,
V_2 -> V_6 + V_7 ) ;
F_5 ( & V_2 -> V_5 , V_4 ) ;
}
static void F_6 ( struct V_1 * V_2 , T_1 V_3 )
{
unsigned long V_4 ;
F_2 ( & V_2 -> V_5 , V_4 ) ;
F_3 ( F_4 ( V_2 -> V_6 + V_7 ) & ~ V_3 ,
V_2 -> V_6 + V_7 ) ;
F_5 ( & V_2 -> V_5 , V_4 ) ;
}
static void F_7 ( struct V_1 * V_2 )
{
int V_8 ;
F_8 ( & V_2 -> V_9 -> V_10 , L_1 ) ;
F_3 ( V_11 , V_2 -> V_6 + V_12 ) ;
for ( V_8 = 0 ; V_8 < 1000 ; V_8 ++ ) {
if ( ( F_4 ( V_2 -> V_6 + V_12 ) & V_11 ) == 0 )
return;
F_9 ( 10 ) ;
}
F_10 ( & V_2 -> V_9 -> V_10 ,
L_2 ) ;
}
static int F_11 ( struct V_1 * V_2 , T_1 V_13 , int V_14 )
{
int V_15 ;
int V_16 = 0 ;
F_12 ( & V_2 -> V_17 ) ;
F_1 ( V_2 , V_18 ) ;
V_2 -> V_19 = 0 ;
F_3 ( V_13 , V_2 -> V_6 + V_14 ) ;
V_15 = F_13 ( V_2 -> V_20 ,
V_2 -> V_19 & ( V_21 | V_11 ) , F_14 ( 1 ) ) ;
if ( V_15 < 0 ) {
V_16 = V_15 ;
goto V_22;
} else if ( V_15 == 0 ) {
F_8 ( & V_2 -> V_9 -> V_10 ,
L_3
L_4 , V_13 , V_14 ) ;
}
if ( V_2 -> V_19 & V_11 ) {
F_7 ( V_2 ) ;
V_16 = - V_23 ;
}
V_22:
F_15 ( & V_2 -> V_17 ) ;
return V_16 ;
}
static int F_16 ( struct V_24 * V_10 , struct V_25 * V_26 )
{
struct V_1 * V_2 = F_17 ( V_10 ) ;
unsigned long V_27 ;
V_27 = F_4 ( V_2 -> V_6 + V_28 ) ;
F_18 ( V_27 , V_26 ) ;
return 0 ;
}
static int F_19 ( struct V_24 * V_10 , unsigned long V_29 )
{
struct V_1 * V_2 = F_17 ( V_10 ) ;
int V_16 ;
V_16 = F_11 ( V_2 , 0 , V_30 ) ;
if ( V_16 == 0 )
V_16 = F_11 ( V_2 , V_29 , V_28 ) ;
return V_16 ;
}
static int F_20 ( struct V_24 * V_10 ,
unsigned int V_31 )
{
struct V_1 * V_2 = F_17 ( V_10 ) ;
if ( V_31 )
F_1 ( V_2 , V_32 ) ;
else
F_6 ( V_2 , V_32 ) ;
return 0 ;
}
static int F_21 ( struct V_24 * V_10 , struct V_33 * V_34 )
{
struct V_1 * V_2 = F_17 ( V_10 ) ;
T_1 V_35 ;
V_35 = F_4 ( V_2 -> V_6 + V_36 ) ;
F_18 ( V_35 , & V_34 -> time ) ;
V_34 -> V_31 = ( F_4 ( V_2 -> V_6 + V_7 ) & V_32 ) != 0 ;
F_12 ( & V_2 -> V_17 ) ;
V_34 -> V_37 = ( F_4 ( V_2 -> V_6 + V_12 ) & V_38 ) != 0 ;
F_15 ( & V_2 -> V_17 ) ;
return 0 ;
}
static int F_22 ( struct V_24 * V_10 , struct V_33 * V_34 )
{
struct V_1 * V_2 = F_17 ( V_10 ) ;
unsigned long V_27 ;
unsigned long V_39 ;
int V_16 ;
V_16 = F_23 ( & V_34 -> time , & V_39 ) ;
if ( V_16 )
return V_16 ;
V_27 = F_4 ( V_2 -> V_6 + V_28 ) ;
if ( V_39 < V_27 )
return - V_40 ;
V_16 = F_11 ( V_2 , ( T_1 ) V_39 , V_36 ) ;
if ( V_16 )
return V_16 ;
if ( V_34 -> V_31 )
F_1 ( V_2 , V_32 ) ;
else
F_6 ( V_2 , V_32 ) ;
return 0 ;
}
static T_2 F_24 ( int V_41 , void * V_42 )
{
struct V_1 * V_2 = V_42 ;
T_1 V_19 , V_43 ;
T_2 V_16 = V_44 ;
V_43 = F_4 ( V_2 -> V_6 + V_7 ) ;
if ( ( V_43 & V_18 ) ) {
if ( F_25 ( & V_2 -> V_20 . V_45 ) )
return V_16 ;
V_19 = F_4 ( V_2 -> V_6 + V_12 ) ;
if ( ( V_19 & ( V_21 | V_11 ) ) ) {
F_6 ( V_2 , V_18 ) ;
V_2 -> V_19 |= V_19 ;
F_26 ( & V_2 -> V_20 ) ;
V_16 = V_46 ;
}
}
if ( ( V_43 & V_32 ) ) {
V_19 = F_4 ( V_2 -> V_6 + V_12 ) ;
if ( V_19 & V_38 ) {
F_6 ( V_2 , V_32 ) ;
F_27 ( & V_2 -> V_47 ) ;
V_16 = V_46 ;
}
}
return V_16 ;
}
static void F_28 ( struct V_48 * V_47 )
{
struct V_1 * V_2 = F_29 ( V_47 ,
struct V_1 , V_47 ) ;
F_11 ( V_2 , V_38 , V_12 ) ;
F_30 ( V_2 -> V_49 , 1 , V_50 | V_51 ) ;
}
static int T_3 F_31 ( struct V_52 * V_9 )
{
struct V_53 * V_54 ;
struct V_1 * V_2 ;
int V_16 ;
V_2 = F_32 ( & V_9 -> V_10 , sizeof( * V_2 ) , V_55 ) ;
if ( ! V_2 )
return - V_56 ;
V_2 -> V_9 = V_9 ;
V_54 = F_33 ( V_9 , V_57 , 0 ) ;
V_2 -> V_6 = F_34 ( & V_9 -> V_10 , V_54 ) ;
if ( F_35 ( V_2 -> V_6 ) )
return F_36 ( V_2 -> V_6 ) ;
F_37 ( & V_2 -> V_5 ) ;
V_2 -> V_41 = F_38 ( V_9 , 0 ) ;
if ( V_2 -> V_41 < 0 )
return V_2 -> V_41 ;
F_39 ( & V_2 -> V_20 ) ;
F_40 ( & V_2 -> V_47 , F_28 ) ;
F_41 ( & V_2 -> V_17 ) ;
V_2 -> V_58 = F_42 ( & V_9 -> V_10 , NULL ) ;
if ( F_35 ( V_2 -> V_58 ) )
return F_36 ( V_2 -> V_58 ) ;
V_16 = F_43 ( V_2 -> V_58 ) ;
if ( V_16 )
return V_16 ;
F_3 ( 0 , V_2 -> V_6 + V_7 ) ;
V_16 = F_44 ( & V_9 -> V_10 , V_2 -> V_41 , F_24 ,
V_59 , V_9 -> V_60 , V_2 ) ;
if ( V_16 ) {
F_8 ( & V_9 -> V_10 , L_5 ) ;
goto V_61;
}
if ( F_4 ( V_2 -> V_6 + V_12 ) & V_62 ) {
V_16 = F_11 ( V_2 , V_62 | V_63 , V_12 ) ;
if ( V_16 )
goto V_61;
}
V_16 = F_11 ( V_2 , V_64 , V_36 ) ;
if ( V_16 )
goto V_61;
V_16 = F_11 ( V_2 , 0 , V_65 ) ;
if ( V_16 )
goto V_61;
if ( F_4 ( V_2 -> V_6 + V_12 ) & V_38 ) {
V_16 = F_11 ( V_2 , V_38 , V_12 ) ;
if ( V_16 )
goto V_61;
}
if ( F_4 ( V_2 -> V_6 + V_28 ) == 0 ) {
V_16 = F_11 ( V_2 , 0 , V_28 ) ;
if ( V_16 )
goto V_61;
}
if ( ! ( F_4 ( V_2 -> V_6 + V_66 ) & V_67 ) ) {
V_16 = F_11 ( V_2 ,
F_4 ( V_2 -> V_6 + V_66 ) | V_67 ,
V_66 ) ;
if ( V_16 )
goto V_61;
}
F_45 ( V_9 , V_2 ) ;
V_2 -> V_49 = F_46 ( & V_9 -> V_10 , V_9 -> V_60 ,
& V_68 , V_69 ) ;
if ( F_35 ( V_2 -> V_49 ) ) {
V_16 = F_36 ( V_2 -> V_49 ) ;
goto V_61;
}
return 0 ;
V_61:
F_47 ( V_2 -> V_58 ) ;
return V_16 ;
}
static int T_4 F_48 ( struct V_52 * V_9 )
{
struct V_1 * V_2 = F_49 ( V_9 ) ;
F_50 ( & V_2 -> V_47 ) ;
F_3 ( 0 , V_2 -> V_6 + V_7 ) ;
F_47 ( V_2 -> V_58 ) ;
return 0 ;
}
