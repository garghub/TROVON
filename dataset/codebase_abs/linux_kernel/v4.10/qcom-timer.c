static T_1 F_1 ( int V_1 , void * V_2 )
{
struct V_3 * V_4 = V_2 ;
if ( F_2 ( V_4 ) ) {
T_2 V_5 = F_3 ( V_6 + V_7 ) ;
V_5 &= ~ V_8 ;
F_4 ( V_5 , V_6 + V_7 ) ;
}
V_4 -> V_9 ( V_4 ) ;
return V_10 ;
}
static int F_5 ( unsigned long V_11 ,
struct V_3 * V_4 )
{
T_2 V_5 = F_3 ( V_6 + V_7 ) ;
V_5 &= ~ V_8 ;
F_4 ( V_5 , V_6 + V_7 ) ;
F_4 ( V_5 , V_6 + V_12 ) ;
F_4 ( V_11 , V_6 + V_13 ) ;
if ( V_14 )
while ( F_3 ( V_14 ) & V_15 )
F_6 () ;
F_4 ( V_5 | V_8 , V_6 + V_7 ) ;
return 0 ;
}
static int F_7 ( struct V_3 * V_4 )
{
T_2 V_5 ;
V_5 = F_3 ( V_6 + V_7 ) ;
V_5 &= ~ ( V_8 | V_16 ) ;
F_4 ( V_5 , V_6 + V_7 ) ;
return 0 ;
}
static T_3 T_4 F_8 ( struct V_17 * V_18 )
{
return F_3 ( V_19 + V_20 ) ;
}
static int F_9 ( unsigned int V_21 )
{
struct V_3 * V_4 = F_10 ( V_22 , V_21 ) ;
int V_23 ;
V_4 -> V_1 = V_24 ;
V_4 -> V_25 = L_1 ;
V_4 -> V_26 = V_27 ;
V_4 -> V_28 = 200 ;
V_4 -> V_29 = F_7 ;
V_4 -> V_30 = F_7 ;
V_4 -> V_31 = F_7 ;
V_4 -> V_32 = F_5 ;
V_4 -> V_33 = F_11 ( V_21 ) ;
F_12 ( V_4 , V_34 , 4 , 0xffffffff ) ;
if ( V_35 ) {
F_13 ( V_4 -> V_1 , V_36 ) ;
} else {
V_23 = F_14 ( V_4 -> V_1 , F_1 ,
V_37 | V_38 |
V_39 , L_2 , V_4 ) ;
if ( V_23 )
F_15 ( L_3 ) ;
}
return 0 ;
}
static int F_16 ( unsigned int V_21 )
{
struct V_3 * V_4 = F_10 ( V_22 , V_21 ) ;
V_4 -> V_29 ( V_4 ) ;
F_17 ( V_4 -> V_1 ) ;
return 0 ;
}
static T_4 T_3 F_18 ( void )
{
return V_40 . V_41 ( & V_40 ) ;
}
static unsigned long F_19 ( void )
{
return V_40 . V_41 ( & V_40 ) ;
}
static int T_5 F_20 ( T_2 V_42 , int V_43 , int V_1 ,
bool V_44 )
{
struct V_17 * V_18 = & V_40 ;
int V_45 = 0 ;
V_24 = V_1 ;
V_35 = V_44 ;
V_22 = F_21 ( struct V_3 ) ;
if ( ! V_22 ) {
F_15 ( L_4 ) ;
goto V_23;
}
if ( V_44 )
V_45 = F_22 ( V_1 , F_1 ,
L_2 , V_22 ) ;
if ( V_45 ) {
F_15 ( L_5 ) ;
} else {
V_45 = F_23 ( V_46 ,
L_6 ,
F_9 ,
F_16 ) ;
if ( V_45 ) {
F_24 ( V_1 , V_22 ) ;
goto V_23;
}
}
V_23:
F_4 ( V_8 , V_19 + V_7 ) ;
V_45 = F_25 ( V_18 , V_42 ) ;
if ( V_45 )
F_15 ( L_7 ) ;
F_26 ( F_18 , V_43 , V_42 ) ;
V_47 . V_48 = V_42 ;
F_27 ( & V_47 ) ;
return V_45 ;
}
static int T_5 F_28 ( struct V_49 * V_50 )
{
T_2 V_48 ;
int V_1 , V_51 ;
struct V_52 V_45 ;
T_2 V_53 ;
void T_6 * V_54 ;
void T_6 * V_55 ;
V_54 = F_29 ( V_50 , 0 ) ;
if ( ! V_54 ) {
F_15 ( L_8 ) ;
return - V_56 ;
}
V_1 = F_30 ( V_50 , 1 ) ;
if ( V_1 <= 0 ) {
F_15 ( L_9 ) ;
return - V_57 ;
}
if ( F_31 ( V_50 , L_10 , & V_53 ) )
V_53 = 0 ;
V_51 = F_32 ( V_50 , 0 , & V_45 ) ;
if ( V_51 ) {
F_15 ( L_11 ) ;
return V_51 ;
}
V_55 = F_33 ( V_45 . V_58 + V_53 , F_34 ( & V_45 ) ) ;
if ( ! V_55 ) {
F_15 ( L_12 ) ;
return - V_57 ;
}
if ( F_31 ( V_50 , L_13 , & V_48 ) ) {
F_15 ( L_14 ) ;
return - V_57 ;
}
V_6 = V_54 + 0x4 ;
V_14 = V_54 + 0x88 ;
V_19 = V_55 + 0x24 ;
V_48 /= 4 ;
F_4 ( V_59 , V_19 + V_60 ) ;
return F_20 ( V_48 , 32 , V_1 , ! ! V_53 ) ;
}
