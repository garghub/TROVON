static T_1 F_1 ( int V_1 , void * V_2 )
{
struct V_3 * V_4 = V_2 ;
if ( F_2 ( & V_4 -> V_5 ) )
F_3 ( 0x0000 , V_4 -> V_6 + V_7 ) ;
V_4 -> V_5 . V_8 ( & V_4 -> V_5 ) ;
F_4 ( V_9 , V_4 -> V_6 + V_10 ) ;
return V_11 ;
}
static void F_5 ( struct V_3 * V_4 , unsigned long V_12 )
{
if ( V_12 >= 0x10000 )
F_6 ( L_1 ) ;
F_4 ( V_13 , V_4 -> V_6 + V_7 ) ;
F_3 ( V_12 , V_4 -> V_6 + V_14 ) ;
F_3 ( 0x0000 , V_4 -> V_6 + V_15 ) ;
F_4 ( V_9 , V_4 -> V_6 + V_10 ) ;
F_7 ( V_13 , V_4 -> V_6 + V_7 ) ;
}
static int F_8 ( struct V_3 * V_4 )
{
F_3 ( 0xffff , V_4 -> V_6 + V_14 ) ;
F_3 ( 0x0000 , V_4 -> V_6 + V_15 ) ;
F_3 ( 0x0c02 , V_4 -> V_6 + V_7 ) ;
return 0 ;
}
static int F_9 ( struct V_3 * V_4 )
{
int V_16 ;
if ( ( V_4 -> V_17 & V_18 ) )
return 0 ;
V_16 = F_8 ( V_4 ) ;
if ( ! V_16 )
V_4 -> V_17 |= V_18 ;
return V_16 ;
}
static void F_10 ( struct V_3 * V_4 )
{
F_3 ( 0x0000 , V_4 -> V_6 + V_7 ) ;
}
static inline struct V_3 * F_11 ( struct V_19 * V_5 )
{
return F_12 ( V_5 , struct V_3 , V_5 ) ;
}
static void F_13 ( struct V_3 * V_4 , unsigned long V_12 )
{
struct V_19 * V_5 = & V_4 -> V_5 ;
F_9 ( V_4 ) ;
V_5 -> V_20 = 32 ;
V_5 -> V_21 = F_14 ( V_4 -> V_22 , V_23 , V_5 -> V_20 ) ;
V_5 -> V_24 = F_15 ( 0xffff , V_5 ) ;
V_5 -> V_25 = F_15 ( 0x0001 , V_5 ) ;
F_5 ( V_4 , V_12 ) ;
}
static int F_16 ( struct V_19 * V_5 )
{
F_10 ( F_11 ( V_5 ) ) ;
return 0 ;
}
static int F_17 ( struct V_19 * V_5 )
{
struct V_3 * V_4 = F_11 ( V_5 ) ;
F_18 ( L_2 , V_5 -> V_26 ) ;
F_10 ( V_4 ) ;
F_13 ( V_4 , ( V_4 -> V_22 + V_27 / 2 ) / V_27 ) ;
return 0 ;
}
static int F_19 ( struct V_19 * V_5 )
{
struct V_3 * V_4 = F_11 ( V_5 ) ;
F_18 ( L_3 , V_5 -> V_26 ) ;
F_10 ( V_4 ) ;
F_13 ( V_4 , 0x10000 ) ;
return 0 ;
}
static int F_20 ( unsigned long V_12 ,
struct V_19 * V_5 )
{
struct V_3 * V_4 = F_11 ( V_5 ) ;
F_21 ( ! F_2 ( V_5 ) ) ;
F_5 ( V_4 , V_12 - 1 ) ;
return 0 ;
}
static void T_2 F_22 ( struct V_28 * V_29 )
{
void T_3 * V_30 ;
int V_1 ;
struct V_31 * V_31 ;
V_31 = F_23 ( V_29 , 0 ) ;
if ( F_24 ( V_31 ) ) {
F_25 ( L_4 ) ;
return;
}
V_30 = F_26 ( V_29 , 0 ) ;
if ( ! V_30 ) {
F_25 ( L_5 ) ;
goto V_32;
}
V_1 = F_27 ( V_29 , 0 ) ;
if ( ! V_1 ) {
F_25 ( L_6 ) ;
goto V_33;
}
V_3 . V_6 = V_30 ;
V_3 . V_22 = F_28 ( V_31 ) / V_34 ;
if ( ! V_3 . V_22 ) {
F_25 ( L_7 ) ;
goto V_33;
}
if ( F_29 ( V_1 , F_1 , V_35 ,
V_3 . V_5 . V_26 , & V_3 ) < 0 ) {
F_25 ( L_8 , V_1 ) ;
goto V_33;
}
F_30 ( & V_3 . V_5 ,
V_3 . V_22 , 1 , 0x0000ffff ) ;
return;
V_33:
F_31 ( V_30 ) ;
V_32:
F_32 ( V_31 ) ;
}
