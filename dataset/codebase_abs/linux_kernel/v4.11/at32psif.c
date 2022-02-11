static T_1 F_1 ( int V_1 , void * V_2 )
{
struct V_3 * V_3 = V_2 ;
int V_4 = V_5 ;
unsigned int V_6 = 0 ;
unsigned long V_7 ;
V_7 = F_2 ( V_3 , V_8 ) ;
if ( V_7 & F_3 ( V_9 ) ) {
unsigned char V_10 = ( unsigned char ) F_2 ( V_3 , V_11 ) ;
if ( V_7 & F_3 ( V_12 ) )
V_6 |= V_13 ;
if ( V_7 & F_3 ( V_14 ) )
F_4 ( & V_3 -> V_15 -> V_16 , L_1 ) ;
F_5 ( V_3 -> V_17 , V_10 , V_6 ) ;
V_4 = V_18 ;
}
return V_4 ;
}
static int F_6 ( struct V_19 * V_17 , unsigned char V_10 )
{
struct V_3 * V_3 = V_17 -> V_20 ;
unsigned long V_21 ;
int V_22 = 10 ;
int V_4 = 0 ;
F_7 ( & V_3 -> V_23 , V_21 ) ;
while ( ! ( F_2 ( V_3 , V_8 ) & F_3 ( V_24 ) ) && V_22 -- )
F_8 ( 50 ) ;
if ( V_22 >= 0 ) {
F_9 ( V_3 , V_25 , V_10 ) ;
} else {
F_10 ( & V_3 -> V_15 -> V_16 , L_2 ) ;
V_4 = - V_26 ;
}
F_11 ( & V_3 -> V_23 , V_21 ) ;
return V_4 ;
}
static int F_12 ( struct V_19 * V_17 )
{
struct V_3 * V_3 = V_17 -> V_20 ;
int V_4 ;
V_4 = F_13 ( V_3 -> V_27 ) ;
if ( V_4 )
return V_4 ;
F_9 ( V_3 , V_28 , F_3 ( V_29 ) | F_3 ( V_30 ) ) ;
F_9 ( V_3 , V_31 , F_3 ( V_9 ) ) ;
V_3 -> V_32 = true ;
return V_4 ;
}
static void F_14 ( struct V_19 * V_17 )
{
struct V_3 * V_3 = V_17 -> V_20 ;
V_3 -> V_32 = false ;
F_9 ( V_3 , V_33 , ~ 0UL ) ;
F_9 ( V_3 , V_28 , F_3 ( V_34 ) | F_3 ( V_35 ) ) ;
F_15 ( V_3 -> V_27 ) ;
}
static void F_16 ( struct V_3 * V_3 )
{
unsigned long V_36 ;
unsigned long V_37 = F_17 ( V_3 -> V_27 ) ;
V_36 = 100 * ( V_37 / 1000000UL ) ;
if ( V_36 > ( ( 1 << V_38 ) - 1 ) ) {
V_36 = ( 1 << V_38 ) - 1 ;
F_10 ( & V_3 -> V_15 -> V_16 , L_3
L_4 ) ;
}
F_13 ( V_3 -> V_27 ) ;
F_9 ( V_3 , V_39 , V_36 ) ;
F_15 ( V_3 -> V_27 ) ;
}
static int T_2 F_18 ( struct V_40 * V_15 )
{
struct V_41 * V_42 ;
struct V_3 * V_3 ;
struct V_19 * V_17 ;
struct V_43 * V_27 ;
int V_1 ;
int V_44 ;
V_3 = F_19 ( sizeof( struct V_3 ) , V_45 ) ;
if ( ! V_3 )
return - V_46 ;
V_3 -> V_15 = V_15 ;
V_17 = F_19 ( sizeof( struct V_19 ) , V_45 ) ;
if ( ! V_17 ) {
V_44 = - V_46 ;
goto V_47;
}
V_3 -> V_17 = V_17 ;
V_42 = F_20 ( V_15 , V_48 , 0 ) ;
if ( ! V_42 ) {
F_10 ( & V_15 -> V_16 , L_5 ) ;
V_44 = - V_46 ;
goto V_49;
}
V_3 -> V_42 = F_21 ( V_42 -> V_50 , F_22 ( V_42 ) ) ;
if ( ! V_3 -> V_42 ) {
V_44 = - V_46 ;
F_10 ( & V_15 -> V_16 , L_6 ) ;
goto V_49;
}
V_27 = F_23 ( & V_15 -> V_16 , L_7 ) ;
if ( F_24 ( V_27 ) ) {
F_10 ( & V_15 -> V_16 , L_8 ) ;
V_44 = F_25 ( V_27 ) ;
goto V_51;
}
V_3 -> V_27 = V_27 ;
V_44 = F_13 ( V_27 ) ;
if ( V_44 ) {
F_10 ( & V_15 -> V_16 , L_9 ) ;
goto V_52;
}
F_9 ( V_3 , V_28 , F_3 ( V_53 ) ) ;
F_15 ( V_27 ) ;
V_1 = F_26 ( V_15 , 0 ) ;
if ( V_1 < 0 ) {
F_10 ( & V_15 -> V_16 , L_10 ) ;
V_44 = - V_54 ;
goto V_52;
}
V_44 = F_27 ( V_1 , F_1 , V_55 , L_11 , V_3 ) ;
if ( V_44 ) {
F_10 ( & V_15 -> V_16 , L_12 , V_1 ) ;
goto V_52;
}
V_3 -> V_1 = V_1 ;
V_17 -> V_56 . type = V_57 ;
V_17 -> V_58 = F_6 ;
V_17 -> V_32 = F_12 ;
V_17 -> V_59 = F_14 ;
snprintf ( V_17 -> V_60 , sizeof( V_17 -> V_60 ) , L_13 , V_15 -> V_56 ) ;
snprintf ( V_17 -> V_61 , sizeof( V_17 -> V_61 ) , L_14 , V_15 -> V_56 ) ;
V_17 -> V_20 = V_3 ;
V_17 -> V_16 . V_62 = & V_15 -> V_16 ;
F_16 ( V_3 ) ;
F_28 ( & V_3 -> V_23 ) ;
F_29 ( V_3 -> V_17 ) ;
F_30 ( V_15 , V_3 ) ;
F_31 ( & V_15 -> V_16 , L_15 ,
( int ) V_3 -> V_42 , V_3 -> V_1 ) ;
return 0 ;
V_52:
F_32 ( V_3 -> V_27 ) ;
V_51:
F_33 ( V_3 -> V_42 ) ;
V_49:
F_34 ( V_17 ) ;
V_47:
F_34 ( V_3 ) ;
return V_44 ;
}
static int T_3 F_35 ( struct V_40 * V_15 )
{
struct V_3 * V_3 = F_36 ( V_15 ) ;
F_9 ( V_3 , V_33 , ~ 0UL ) ;
F_9 ( V_3 , V_28 , F_3 ( V_34 ) | F_3 ( V_35 ) ) ;
F_37 ( V_3 -> V_17 ) ;
F_33 ( V_3 -> V_42 ) ;
F_38 ( V_3 -> V_1 , V_3 ) ;
F_32 ( V_3 -> V_27 ) ;
F_34 ( V_3 ) ;
return 0 ;
}
static int F_39 ( struct V_63 * V_16 )
{
struct V_40 * V_15 = F_40 ( V_16 ) ;
struct V_3 * V_3 = F_36 ( V_15 ) ;
if ( V_3 -> V_32 ) {
F_9 ( V_3 , V_28 , F_3 ( V_35 ) | F_3 ( V_34 ) ) ;
F_15 ( V_3 -> V_27 ) ;
}
return 0 ;
}
static int F_41 ( struct V_63 * V_16 )
{
struct V_40 * V_15 = F_40 ( V_16 ) ;
struct V_3 * V_3 = F_36 ( V_15 ) ;
if ( V_3 -> V_32 ) {
F_13 ( V_3 -> V_27 ) ;
F_16 ( V_3 ) ;
F_9 ( V_3 , V_28 , F_3 ( V_30 ) | F_3 ( V_29 ) ) ;
}
return 0 ;
}
