static inline T_1 F_1 ( void T_2 * V_1 , T_1 V_2 , T_1 V_3 )
{
return F_2 ( V_1 + 0x20 * V_3 + V_2 ) ;
}
static inline void F_3 ( void T_2 * V_1 , T_1 V_4 , T_1 V_2 ,
T_1 V_3 )
{
F_4 ( V_4 , V_1 + 0x20 * V_3 + V_2 ) ;
}
static T_3 T_4
F_5 ( struct V_5 * V_6 )
{
struct V_7 * V_8 = F_6 ( V_6 ) ;
T_1 V_9 , V_10 ;
unsigned long V_11 ;
F_7 ( & V_8 -> V_12 , V_11 ) ;
V_10 = F_1 ( V_8 -> V_1 , V_13 , 0 ) ;
V_9 = F_1 ( V_8 -> V_1 , V_14 , 0 ) ;
F_8 ( & V_8 -> V_12 , V_11 ) ;
return ( T_3 ) ~ V_9 ;
}
static T_5 T_4 F_9 ( void )
{
return F_5 ( & V_15 . V_6 ) ;
}
static void F_10 ( struct V_5 * V_6 , int V_16 ,
int V_17 )
{
struct V_7 * V_8 = F_6 ( V_6 ) ;
T_1 V_18 ;
V_18 = F_1 ( V_8 -> V_1 , V_19 , V_16 ) ;
if ( V_17 )
V_18 |= V_20 ;
else
V_18 &= ~ V_20 ;
F_3 ( V_8 -> V_1 , V_18 , V_19 , V_16 ) ;
}
static void F_11 ( struct V_5 * V_6 , int V_16 )
{
struct V_7 * V_8 = F_6 ( V_6 ) ;
F_10 ( V_6 , V_16 , false ) ;
F_3 ( V_8 -> V_1 , V_21 , V_22 , V_16 ) ;
F_10 ( V_6 , V_16 , true ) ;
}
static void F_12 ( struct V_5 * V_6 , int V_16 )
{
F_10 ( V_6 , V_16 , false ) ;
}
static int F_13 ( struct V_5 * V_6 )
{
F_11 ( V_6 , 0 ) ;
return 0 ;
}
static void F_14 ( struct V_5 * V_6 )
{
F_12 ( V_6 , 0 ) ;
}
static void T_6 F_15 ( struct V_23 * V_24 )
{
struct V_25 * V_26 , * V_27 ;
struct V_28 * V_29 ;
unsigned long V_30 ;
int V_31 ;
V_15 . V_1 = F_16 ( V_24 , 0 ) ;
if ( ! V_15 . V_1 ) {
F_17 ( L_1 ) ;
return;
}
V_29 = F_18 ( V_24 , L_2 ) ;
if ( F_19 ( V_29 ) ) {
F_17 ( L_3 ,
F_20 ( V_29 ) ) ;
return;
}
V_31 = F_21 ( V_29 , V_32 ,
0xf , 0x0 ) ;
if ( V_31 )
return;
V_26 = F_22 ( V_24 , L_4 ) ;
if ( F_19 ( V_26 ) ) {
F_17 ( L_5 , F_20 ( V_26 ) ) ;
return;
}
V_27 = F_22 ( V_24 , L_6 ) ;
if ( F_19 ( V_27 ) ) {
F_17 ( L_7 , F_20 ( V_27 ) ) ;
return;
}
V_31 = F_23 ( V_26 ) ;
if ( V_31 < 0 ) {
F_17 ( L_8 , V_31 ) ;
return;
}
V_31 = F_23 ( V_27 ) ;
if ( V_31 < 0 ) {
F_17 ( L_8 , V_31 ) ;
F_24 ( V_26 ) ;
return;
}
V_30 = F_25 ( V_27 ) ;
F_3 ( & V_15 . V_1 , 0 , V_33 , 0 ) ;
F_3 ( & V_15 . V_1 , 0 , V_33 , 1 ) ;
F_3 ( & V_15 . V_1 , 0 , V_33 , 2 ) ;
F_3 ( & V_15 . V_1 , 0 , V_33 , 3 ) ;
F_4 ( V_34 , V_15 . V_1 ) ;
F_26 ( & V_15 . V_12 ) ;
F_27 ( F_9 , 32 , V_30 ) ;
F_28 ( & V_15 . V_6 , V_30 ) ;
}
