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
F_20 ( ! F_21 () ) ;
if ( F_22 ( & V_10 -> V_5 ) &&
( F_4 ( V_10 -> V_6 , V_25 ) & V_26 ) ) {
unsigned V_27 ;
V_27 = F_11 ( F_4 ( V_10 -> V_6 , V_20 ) ) ;
do {
V_10 -> V_14 += V_10 -> V_16 ;
V_10 -> V_5 . V_28 ( & V_10 -> V_5 ) ;
V_27 -- ;
} while ( V_27 );
return V_29 ;
}
return V_30 ;
}
static int T_5 F_23 ( struct V_1 * V_10 )
{
unsigned long V_31 ;
unsigned V_32 ;
int V_33 ;
V_31 = F_24 ( V_10 -> V_34 ) / 16 ;
V_10 -> V_16 = F_25 ( V_31 , V_35 ) ;
F_26 ( ( ( V_10 -> V_16 - 1 ) & ~ V_36 ) != 0 ) ;
F_16 ( V_10 ) ;
V_32 = 12 + F_27 ( V_10 -> V_16 ) ;
V_10 -> V_3 . V_37 = F_28 ( V_32 ) ;
V_10 -> V_3 . V_38 = L_1 ;
V_10 -> V_3 . V_39 = 175 ;
V_10 -> V_3 . V_40 = F_8 ;
V_10 -> V_3 . V_11 = V_41 ;
V_33 = F_29 ( & V_10 -> V_3 , V_31 ) ;
if ( V_33 ) {
F_30 ( L_2 ) ;
return V_33 ;
}
V_33 = F_31 ( V_10 -> V_23 , F_19 ,
V_42 | V_43 | V_44 ,
L_3 , V_10 ) ;
if ( V_33 ) {
F_30 ( L_4 ) ;
return V_33 ;
}
V_10 -> V_5 . V_38 = L_1 ;
V_10 -> V_5 . V_45 = V_46 ;
V_10 -> V_5 . V_47 = 32 ;
V_10 -> V_5 . V_48 = F_32 ( V_31 , V_49 , V_10 -> V_5 . V_47 ) ;
V_10 -> V_5 . V_39 = 100 ;
V_10 -> V_5 . V_50 = F_33 ( 0 ) ;
V_10 -> V_5 . V_51 = F_13 ;
V_10 -> V_5 . V_52 = F_14 ;
V_10 -> V_5 . V_53 = F_18 ;
V_10 -> V_5 . V_54 = F_15 ;
F_34 ( & V_10 -> V_5 ) ;
return 0 ;
}
static int T_5 F_35 ( struct V_55 * V_56 )
{
struct V_1 * V_10 ;
int V_33 ;
V_10 = F_36 ( sizeof( * V_10 ) , V_57 ) ;
if ( ! V_10 )
return - V_58 ;
V_10 -> V_6 = F_37 ( V_56 , 0 ) ;
if ( ! V_10 -> V_6 ) {
F_30 ( L_5 ) ;
return - V_59 ;
}
V_10 -> V_34 = F_38 ( V_56 , 0 ) ;
if ( F_39 ( V_10 -> V_34 ) )
V_10 -> V_34 = F_40 ( NULL , L_6 ) ;
if ( F_39 ( V_10 -> V_34 ) ) {
F_30 ( L_7 ) ;
return F_41 ( V_10 -> V_34 ) ;
}
V_33 = F_42 ( V_10 -> V_34 ) ;
if ( V_33 ) {
F_30 ( L_8 ) ;
return V_33 ;
}
V_10 -> V_23 = F_43 ( V_56 , 0 ) ;
if ( ! V_10 -> V_23 ) {
F_30 ( L_9 ) ;
return - V_60 ;
}
return F_23 ( V_10 ) ;
}
