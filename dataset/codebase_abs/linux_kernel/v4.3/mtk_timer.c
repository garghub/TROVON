static inline struct V_1 * F_1 (
struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_4 ) ;
}
static void F_3 ( struct V_1 * V_5 , T_1 V_6 )
{
T_2 V_7 ;
V_7 = F_4 ( V_5 -> V_8 + F_5 ( V_6 ) ) ;
F_6 ( V_7 & ~ V_9 , V_5 -> V_8 +
F_5 ( V_6 ) ) ;
}
static void F_7 ( struct V_1 * V_5 ,
unsigned long V_10 , T_1 V_6 )
{
F_6 ( V_10 , V_5 -> V_8 + F_8 ( V_6 ) ) ;
}
static void F_9 ( struct V_1 * V_5 ,
bool V_11 , T_1 V_6 )
{
T_2 V_7 ;
F_6 ( F_10 ( V_6 ) , V_5 -> V_8 + V_12 ) ;
V_7 = F_4 ( V_5 -> V_8 + F_5 ( V_6 ) ) ;
V_7 &= ~ F_11 ( 0x3 ) ;
if ( V_11 )
V_7 |= F_11 ( V_13 ) ;
else
V_7 |= F_11 ( V_14 ) ;
F_6 ( V_7 | V_9 | V_15 ,
V_5 -> V_8 + F_5 ( V_6 ) ) ;
}
static int F_12 ( struct V_2 * V_16 )
{
F_3 ( F_1 ( V_16 ) , V_17 ) ;
return 0 ;
}
static int F_13 ( struct V_2 * V_16 )
{
struct V_1 * V_5 = F_1 ( V_16 ) ;
F_3 ( V_5 , V_17 ) ;
F_7 ( V_5 , V_5 -> V_18 , V_17 ) ;
F_9 ( V_5 , true , V_17 ) ;
return 0 ;
}
static int F_14 ( unsigned long V_19 ,
struct V_2 * V_16 )
{
struct V_1 * V_5 = F_1 ( V_16 ) ;
F_3 ( V_5 , V_17 ) ;
F_7 ( V_5 , V_19 , V_17 ) ;
F_9 ( V_5 , false , V_17 ) ;
return 0 ;
}
static T_3 F_15 ( int V_20 , void * V_21 )
{
struct V_1 * V_5 = V_21 ;
F_6 ( F_10 ( V_17 ) , V_5 -> V_8 + V_12 ) ;
V_5 -> V_4 . V_22 ( & V_5 -> V_4 ) ;
return V_23 ;
}
static void F_16 ( struct V_1 * V_5 )
{
F_6 ( 0x0 , V_5 -> V_8 + V_24 ) ;
F_6 ( 0x3f , V_5 -> V_8 + V_12 ) ;
}
static void
F_17 ( struct V_1 * V_5 , T_1 V_6 , T_1 V_25 )
{
F_6 ( V_15 | V_26 ,
V_5 -> V_8 + F_5 ( V_6 ) ) ;
F_6 ( F_18 ( V_27 ) | V_28 ,
V_5 -> V_8 + F_19 ( V_6 ) ) ;
F_6 ( 0x0 , V_5 -> V_8 + F_8 ( V_6 ) ) ;
F_6 ( F_11 ( V_25 ) | V_9 ,
V_5 -> V_8 + F_5 ( V_6 ) ) ;
}
static void F_20 ( struct V_1 * V_5 , T_1 V_6 )
{
T_2 V_7 ;
V_7 = F_4 ( V_5 -> V_8 + V_24 ) ;
F_6 ( V_7 | F_21 ( V_6 ) ,
V_5 -> V_8 + V_24 ) ;
}
static void T_4 F_22 ( struct V_29 * V_30 )
{
struct V_1 * V_5 ;
struct V_31 V_32 ;
unsigned long V_33 = 0 ;
struct V_16 * V_16 ;
V_5 = F_23 ( sizeof( * V_5 ) , V_34 ) ;
if ( ! V_5 ) {
F_24 ( L_1 ) ;
return;
}
V_5 -> V_4 . V_35 = L_2 ;
V_5 -> V_4 . V_36 = 300 ;
V_5 -> V_4 . V_37 = V_38 | V_39 ;
V_5 -> V_4 . V_40 = F_12 ;
V_5 -> V_4 . V_41 = F_13 ;
V_5 -> V_4 . V_42 = F_12 ;
V_5 -> V_4 . V_43 = F_12 ;
V_5 -> V_4 . V_44 = F_14 ;
V_5 -> V_4 . V_45 = V_46 ;
V_5 -> V_8 = F_25 ( V_30 , 0 , L_3 ) ;
if ( F_26 ( V_5 -> V_8 ) ) {
F_24 ( L_4 ) ;
return;
}
V_5 -> V_4 . V_20 = F_27 ( V_30 , 0 ) ;
if ( V_5 -> V_4 . V_20 <= 0 ) {
F_24 ( L_5 ) ;
goto V_47;
}
V_16 = F_28 ( V_30 , 0 ) ;
if ( F_26 ( V_16 ) ) {
F_24 ( L_6 ) ;
goto V_48;
}
if ( F_29 ( V_16 ) ) {
F_24 ( L_7 ) ;
goto V_49;
}
V_33 = F_30 ( V_16 ) ;
F_16 ( V_5 ) ;
if ( F_31 ( V_5 -> V_4 . V_20 , F_15 ,
V_50 | V_51 , L_8 , V_5 ) ) {
F_24 ( L_9 , V_5 -> V_4 . V_20 ) ;
goto V_52;
}
V_5 -> V_18 = F_32 ( V_33 , V_53 ) ;
F_17 ( V_5 , V_54 , V_55 ) ;
F_33 ( V_5 -> V_8 + F_34 ( V_54 ) ,
V_30 -> V_35 , V_33 , 300 , 32 , V_56 ) ;
F_17 ( V_5 , V_17 , V_13 ) ;
F_35 ( & V_5 -> V_4 , V_33 , 0x3 ,
0xffffffff ) ;
F_20 ( V_5 , V_17 ) ;
return;
V_52:
F_36 ( V_16 ) ;
V_49:
F_37 ( V_16 ) ;
V_48:
F_38 ( V_5 -> V_4 . V_20 ) ;
V_47:
F_39 ( V_5 -> V_8 ) ;
F_40 ( V_30 , 0 , & V_32 ) ;
F_41 ( V_32 . V_57 , F_42 ( & V_32 ) ) ;
}
