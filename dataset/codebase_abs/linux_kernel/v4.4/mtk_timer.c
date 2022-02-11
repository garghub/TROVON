static T_1 T_2 F_1 ( void )
{
return F_2 ( V_1 ) ;
}
static inline struct V_2 * F_3 (
struct V_3 * V_4 )
{
return F_4 ( V_4 , struct V_2 , V_5 ) ;
}
static void F_5 ( struct V_2 * V_6 , T_3 V_7 )
{
T_4 V_8 ;
V_8 = F_6 ( V_6 -> V_9 + F_7 ( V_7 ) ) ;
F_8 ( V_8 & ~ V_10 , V_6 -> V_9 +
F_7 ( V_7 ) ) ;
}
static void F_9 ( struct V_2 * V_6 ,
unsigned long V_11 , T_3 V_7 )
{
F_8 ( V_11 , V_6 -> V_9 + F_10 ( V_7 ) ) ;
}
static void F_11 ( struct V_2 * V_6 ,
bool V_12 , T_3 V_7 )
{
T_4 V_8 ;
F_8 ( F_12 ( V_7 ) , V_6 -> V_9 + V_13 ) ;
V_8 = F_6 ( V_6 -> V_9 + F_7 ( V_7 ) ) ;
V_8 &= ~ F_13 ( 0x3 ) ;
if ( V_12 )
V_8 |= F_13 ( V_14 ) ;
else
V_8 |= F_13 ( V_15 ) ;
F_8 ( V_8 | V_10 | V_16 ,
V_6 -> V_9 + F_7 ( V_7 ) ) ;
}
static int F_14 ( struct V_3 * V_17 )
{
F_5 ( F_3 ( V_17 ) , V_18 ) ;
return 0 ;
}
static int F_15 ( struct V_3 * V_17 )
{
struct V_2 * V_6 = F_3 ( V_17 ) ;
F_5 ( V_6 , V_18 ) ;
F_9 ( V_6 , V_6 -> V_19 , V_18 ) ;
F_11 ( V_6 , true , V_18 ) ;
return 0 ;
}
static int F_16 ( unsigned long V_20 ,
struct V_3 * V_17 )
{
struct V_2 * V_6 = F_3 ( V_17 ) ;
F_5 ( V_6 , V_18 ) ;
F_9 ( V_6 , V_20 , V_18 ) ;
F_11 ( V_6 , false , V_18 ) ;
return 0 ;
}
static T_5 F_17 ( int V_21 , void * V_22 )
{
struct V_2 * V_6 = V_22 ;
F_8 ( F_12 ( V_18 ) , V_6 -> V_9 + V_13 ) ;
V_6 -> V_5 . V_23 ( & V_6 -> V_5 ) ;
return V_24 ;
}
static void
F_18 ( struct V_2 * V_6 , T_3 V_7 , T_3 V_25 )
{
F_8 ( V_16 | V_26 ,
V_6 -> V_9 + F_7 ( V_7 ) ) ;
F_8 ( F_19 ( V_27 ) | V_28 ,
V_6 -> V_9 + F_20 ( V_7 ) ) ;
F_8 ( 0x0 , V_6 -> V_9 + F_10 ( V_7 ) ) ;
F_8 ( F_13 ( V_25 ) | V_10 ,
V_6 -> V_9 + F_7 ( V_7 ) ) ;
}
static void F_21 ( struct V_2 * V_6 , T_3 V_7 )
{
T_4 V_8 ;
F_8 ( 0x0 , V_6 -> V_9 + V_29 ) ;
F_8 ( 0x3f , V_6 -> V_9 + V_13 ) ;
V_8 = F_6 ( V_6 -> V_9 + V_29 ) ;
F_8 ( V_8 | F_22 ( V_7 ) ,
V_6 -> V_9 + V_29 ) ;
}
static void T_6 F_23 ( struct V_30 * V_31 )
{
struct V_2 * V_6 ;
struct V_32 V_33 ;
unsigned long V_34 = 0 ;
struct V_17 * V_17 ;
V_6 = F_24 ( sizeof( * V_6 ) , V_35 ) ;
if ( ! V_6 ) {
F_25 ( L_1 ) ;
return;
}
V_6 -> V_5 . V_36 = L_2 ;
V_6 -> V_5 . V_37 = 300 ;
V_6 -> V_5 . V_38 = V_39 | V_40 ;
V_6 -> V_5 . V_41 = F_14 ;
V_6 -> V_5 . V_42 = F_15 ;
V_6 -> V_5 . V_43 = F_14 ;
V_6 -> V_5 . V_44 = F_14 ;
V_6 -> V_5 . V_45 = F_16 ;
V_6 -> V_5 . V_46 = V_47 ;
V_6 -> V_9 = F_26 ( V_31 , 0 , L_3 ) ;
if ( F_27 ( V_6 -> V_9 ) ) {
F_25 ( L_4 ) ;
return;
}
V_6 -> V_5 . V_21 = F_28 ( V_31 , 0 ) ;
if ( V_6 -> V_5 . V_21 <= 0 ) {
F_25 ( L_5 ) ;
goto V_48;
}
V_17 = F_29 ( V_31 , 0 ) ;
if ( F_27 ( V_17 ) ) {
F_25 ( L_6 ) ;
goto V_49;
}
if ( F_30 ( V_17 ) ) {
F_25 ( L_7 ) ;
goto V_50;
}
V_34 = F_31 ( V_17 ) ;
if ( F_32 ( V_6 -> V_5 . V_21 , F_17 ,
V_51 | V_52 , L_8 , V_6 ) ) {
F_25 ( L_9 , V_6 -> V_5 . V_21 ) ;
goto V_53;
}
V_6 -> V_19 = F_33 ( V_34 , V_54 ) ;
F_18 ( V_6 , V_55 , V_56 ) ;
F_34 ( V_6 -> V_9 + F_35 ( V_55 ) ,
V_31 -> V_36 , V_34 , 300 , 32 , V_57 ) ;
V_1 = V_6 -> V_9 + F_35 ( V_55 ) ;
F_36 ( F_1 , 32 , V_34 ) ;
F_18 ( V_6 , V_18 , V_14 ) ;
F_37 ( & V_6 -> V_5 , V_34 , 0x3 ,
0xffffffff ) ;
F_21 ( V_6 , V_18 ) ;
return;
V_53:
F_38 ( V_17 ) ;
V_50:
F_39 ( V_17 ) ;
V_49:
F_40 ( V_6 -> V_5 . V_21 ) ;
V_48:
F_41 ( V_6 -> V_9 ) ;
F_42 ( V_31 , 0 , & V_33 ) ;
F_43 ( V_33 . V_58 , F_44 ( & V_33 ) ) ;
}
