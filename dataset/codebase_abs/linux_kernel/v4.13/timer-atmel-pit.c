static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_3 ) ;
}
static inline struct V_1 * F_3 ( struct V_4 * V_5 )
{
return F_2 ( V_5 , struct V_1 , V_5 ) ;
}
static inline unsigned int F_4 ( void T_1 * V_6 , unsigned int V_7 )
{
return F_5 ( V_6 + V_7 ) ;
}
static inline void F_6 ( void T_1 * V_6 , unsigned int V_7 , unsigned long V_8 )
{
F_7 ( V_8 , V_6 + V_7 ) ;
}
static T_2 F_8 ( struct V_2 * V_9 )
{
struct V_1 * V_10 = F_1 ( V_9 ) ;
unsigned long V_11 ;
T_3 V_12 ;
T_3 V_13 ;
F_9 ( V_11 ) ;
V_12 = V_10 -> V_14 ;
V_13 = F_4 ( V_10 -> V_6 , V_15 ) ;
F_10 ( V_11 ) ;
V_12 += F_11 ( V_13 ) * V_10 -> V_16 ;
V_12 += F_12 ( V_13 ) ;
return V_12 ;
}
static int F_13 ( struct V_4 * V_17 )
{
struct V_1 * V_10 = F_3 ( V_17 ) ;
F_6 ( V_10 -> V_6 , V_18 , ( V_10 -> V_16 - 1 ) | V_19 ) ;
return 0 ;
}
static int F_14 ( struct V_4 * V_17 )
{
struct V_1 * V_10 = F_3 ( V_17 ) ;
V_10 -> V_14 += V_10 -> V_16 * F_11 ( F_4 ( V_10 -> V_6 , V_20 ) ) ;
F_6 ( V_10 -> V_6 , V_18 ,
( V_10 -> V_16 - 1 ) | V_19 | V_21 ) ;
return 0 ;
}
static void F_15 ( struct V_4 * V_22 )
{
struct V_1 * V_10 = F_3 ( V_22 ) ;
F_6 ( V_10 -> V_6 , V_18 , 0 ) ;
}
static void F_16 ( struct V_1 * V_10 )
{
F_6 ( V_10 -> V_6 , V_18 , 0 ) ;
while ( F_12 ( F_4 ( V_10 -> V_6 , V_20 ) ) != 0 )
F_17 () ;
F_6 ( V_10 -> V_6 , V_18 ,
( V_10 -> V_16 - 1 ) | V_19 ) ;
}
static void F_18 ( struct V_4 * V_22 )
{
struct V_1 * V_10 = F_3 ( V_22 ) ;
F_16 ( V_10 ) ;
}
static T_4 F_19 ( int V_23 , void * V_24 )
{
struct V_1 * V_10 = V_24 ;
if ( F_20 ( & V_10 -> V_5 ) &&
( F_4 ( V_10 -> V_6 , V_25 ) & V_26 ) ) {
V_10 -> V_14 += V_10 -> V_16 * F_11 ( F_4 ( V_10 -> V_6 ,
V_20 ) ) ;
V_10 -> V_5 . V_27 ( & V_10 -> V_5 ) ;
return V_28 ;
}
return V_29 ;
}
static int T_5 F_21 ( struct V_30 * V_31 )
{
unsigned long V_32 ;
unsigned V_33 ;
int V_34 ;
struct V_1 * V_10 ;
V_10 = F_22 ( sizeof( * V_10 ) , V_35 ) ;
if ( ! V_10 )
return - V_36 ;
V_10 -> V_6 = F_23 ( V_31 , 0 ) ;
if ( ! V_10 -> V_6 ) {
F_24 ( L_1 ) ;
return - V_37 ;
}
V_10 -> V_38 = F_25 ( V_31 , 0 ) ;
if ( F_26 ( V_10 -> V_38 ) ) {
F_24 ( L_2 ) ;
return F_27 ( V_10 -> V_38 ) ;
}
V_34 = F_28 ( V_10 -> V_38 ) ;
if ( V_34 ) {
F_24 ( L_3 ) ;
return V_34 ;
}
V_10 -> V_23 = F_29 ( V_31 , 0 ) ;
if ( ! V_10 -> V_23 ) {
F_24 ( L_4 ) ;
return - V_39 ;
}
V_32 = F_30 ( V_10 -> V_38 ) / 16 ;
V_10 -> V_16 = F_31 ( V_32 , V_40 ) ;
F_32 ( ( ( V_10 -> V_16 - 1 ) & ~ V_41 ) != 0 ) ;
F_16 ( V_10 ) ;
V_33 = 12 + F_33 ( V_10 -> V_16 ) ;
V_10 -> V_3 . V_42 = F_34 ( V_33 ) ;
V_10 -> V_3 . V_43 = L_5 ;
V_10 -> V_3 . V_44 = 175 ;
V_10 -> V_3 . V_45 = F_8 ;
V_10 -> V_3 . V_11 = V_46 ;
V_34 = F_35 ( & V_10 -> V_3 , V_32 ) ;
if ( V_34 ) {
F_24 ( L_6 ) ;
return V_34 ;
}
V_34 = F_36 ( V_10 -> V_23 , F_19 ,
V_47 | V_48 | V_49 ,
L_7 , V_10 ) ;
if ( V_34 ) {
F_24 ( L_8 ) ;
return V_34 ;
}
V_10 -> V_5 . V_43 = L_5 ;
V_10 -> V_5 . V_50 = V_51 ;
V_10 -> V_5 . V_52 = 32 ;
V_10 -> V_5 . V_53 = F_37 ( V_32 , V_54 , V_10 -> V_5 . V_52 ) ;
V_10 -> V_5 . V_44 = 100 ;
V_10 -> V_5 . V_55 = F_38 ( 0 ) ;
V_10 -> V_5 . V_56 = F_13 ;
V_10 -> V_5 . V_57 = F_14 ;
V_10 -> V_5 . V_58 = F_18 ;
V_10 -> V_5 . V_59 = F_15 ;
F_39 ( & V_10 -> V_5 ) ;
return 0 ;
}
