static inline struct V_1 *
F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_4 ) ;
}
static inline struct V_5 *
F_3 ( struct V_6 * V_7 )
{
return F_2 ( V_7 , struct V_5 , V_7 ) ;
}
static inline T_1 F_4 ( struct V_8 * V_9 , unsigned long V_10 )
{
return F_5 ( V_9 -> V_11 + V_10 ) ;
}
static inline void F_6 ( struct V_8 * V_9 , T_1 V_12 ,
unsigned long V_10 )
{
F_7 ( V_12 , V_9 -> V_11 + V_10 ) ;
}
static inline T_1 F_8 ( struct V_8 * V_9 , unsigned long V_10 )
{
return F_9 ( V_9 -> V_11 + V_10 ) ;
}
static inline void F_10 ( struct V_8 * V_9 , T_1 V_12 ,
unsigned long V_10 )
{
F_11 ( V_12 , V_9 -> V_11 + V_10 ) ;
}
static void F_12 ( struct V_8 * V_9 )
{
T_1 V_13 = F_4 ( V_9 , V_14 ) ;
V_13 |= V_15 ;
F_6 ( V_9 , V_13 , V_14 ) ;
}
void F_13 ( struct V_1 * V_16 )
{
F_14 ( V_16 -> V_9 . V_17 ) ;
F_12 ( & V_16 -> V_9 ) ;
}
static void F_15 ( struct V_8 * V_9 )
{
F_8 ( V_9 , V_18 ) ;
}
static T_2 F_16 ( int V_17 , void * V_19 )
{
struct V_2 * V_3 = V_19 ;
struct V_1 * V_16 = F_1 ( V_3 ) ;
if ( ! V_3 -> V_20 ) {
F_17 ( L_1 , V_17 ) ;
return V_21 ;
}
if ( V_16 -> V_22 )
V_16 -> V_22 ( & V_16 -> V_9 ) ;
V_3 -> V_20 ( V_3 ) ;
return V_23 ;
}
static void F_18 ( struct V_8 * V_9 )
{
T_1 V_13 = F_4 ( V_9 , V_14 ) ;
F_4 ( V_9 , V_18 ) ;
V_13 &= ~ V_15 ;
F_6 ( V_9 , V_13 , V_14 ) ;
}
static int F_19 ( struct V_2 * V_3 )
{
struct V_1 * V_16 = F_1 ( V_3 ) ;
T_1 V_13 ;
F_20 ( L_2 , V_24 ,
F_21 ( V_3 -> V_25 ) ) ;
V_13 = F_4 ( & V_16 -> V_9 , V_14 ) ;
V_13 &= ~ V_26 ;
F_6 ( & V_16 -> V_9 , V_13 , V_14 ) ;
return 0 ;
}
static int F_22 ( struct V_2 * V_3 )
{
struct V_1 * V_16 = F_1 ( V_3 ) ;
T_1 V_13 ;
F_20 ( L_3 , V_24 ,
F_21 ( V_3 -> V_25 ) ) ;
V_13 = F_4 ( & V_16 -> V_9 , V_14 ) ;
V_13 &= ~ V_26 ;
V_13 &= ~ V_27 ;
F_6 ( & V_16 -> V_9 , V_13 , V_14 ) ;
F_6 ( & V_16 -> V_9 , V_13 , V_14 ) ;
F_6 ( & V_16 -> V_9 , ~ 0 , V_28 ) ;
V_13 &= ~ V_15 ;
V_13 |= V_26 ;
F_6 ( & V_16 -> V_9 , V_13 , V_14 ) ;
return 0 ;
}
static int F_23 ( struct V_2 * V_3 )
{
struct V_1 * V_16 = F_1 ( V_3 ) ;
unsigned long V_29 = F_24 ( V_16 -> V_9 . V_30 , V_31 ) ;
T_1 V_13 ;
F_20 ( L_4 , V_24 ,
F_21 ( V_3 -> V_25 ) ) ;
V_13 = F_4 ( & V_16 -> V_9 , V_14 ) ;
V_13 |= V_27 ;
F_6 ( & V_16 -> V_9 , V_13 , V_14 ) ;
V_13 &= ~ V_26 ;
F_6 ( & V_16 -> V_9 , V_13 , V_14 ) ;
F_25 ( 1 ) ;
F_20 ( L_5 , V_29 , V_31 ) ;
F_6 ( & V_16 -> V_9 , V_29 , V_28 ) ;
V_13 |= V_26 ;
F_6 ( & V_16 -> V_9 , V_13 , V_14 ) ;
return 0 ;
}
static int F_26 ( struct V_2 * V_3 )
{
struct V_1 * V_16 = F_1 ( V_3 ) ;
F_20 ( L_6 , V_24 ,
F_21 ( V_3 -> V_25 ) ) ;
F_18 ( & V_16 -> V_9 ) ;
return 0 ;
}
static int F_27 ( unsigned long V_32 ,
struct V_2 * V_3 )
{
T_1 V_13 ;
struct V_1 * V_16 = F_1 ( V_3 ) ;
V_13 = F_8 ( & V_16 -> V_9 , V_14 ) ;
V_13 &= ~ V_26 ;
F_10 ( & V_16 -> V_9 , V_13 , V_14 ) ;
F_10 ( & V_16 -> V_9 , V_32 , V_28 ) ;
V_13 |= V_26 ;
F_10 ( & V_16 -> V_9 , V_13 , V_14 ) ;
return 0 ;
}
struct V_1 *
F_28 ( int V_33 , const char * V_34 , unsigned V_35 ,
void T_3 * V_11 , int V_17 , unsigned long V_30 )
{
struct V_1 * V_16 =
F_29 ( sizeof( * V_16 ) , V_36 ) ;
int V_37 ;
if ( ! V_16 )
return NULL ;
V_16 -> V_9 . V_11 = V_11 ;
V_16 -> V_9 . V_17 = V_17 ;
V_16 -> V_9 . V_30 = V_30 ;
F_30 ( & V_16 -> V_4 , V_30 , V_38 ) ;
V_16 -> V_4 . V_39 = F_31 ( 0x7fffffff ,
& V_16 -> V_4 ) ;
V_16 -> V_4 . V_40 = 0x7fffffff ;
V_16 -> V_4 . V_41 = F_31 ( 5000 , & V_16 -> V_4 ) ;
V_16 -> V_4 . V_42 = 5000 ;
V_16 -> V_4 . V_25 = F_32 ( V_33 ) ;
V_16 -> V_4 . V_43 = V_44 |
V_45 | V_46 ;
V_16 -> V_4 . V_47 = F_19 ;
V_16 -> V_4 . V_48 = F_23 ;
V_16 -> V_4 . V_49 = F_22 ;
V_16 -> V_4 . V_50 = F_19 ;
V_16 -> V_4 . V_51 = F_26 ;
V_16 -> V_4 . V_52 = F_27 ;
V_16 -> V_4 . V_17 = V_16 -> V_9 . V_17 ;
V_16 -> V_4 . V_35 = V_35 ;
V_16 -> V_4 . V_34 = V_34 ;
V_16 -> V_53 . V_34 = V_16 -> V_4 . V_34 ;
V_16 -> V_53 . V_54 = F_16 ;
V_16 -> V_53 . V_55 = & V_16 -> V_4 ;
V_16 -> V_53 . V_17 = V_17 ;
V_16 -> V_53 . V_56 = V_57 | V_58 |
V_59 ;
V_16 -> V_22 = F_15 ;
V_37 = F_33 ( V_17 , & V_16 -> V_53 ) ;
if ( V_37 ) {
F_34 ( L_7 ) ;
F_35 ( V_16 ) ;
V_16 = NULL ;
}
return V_16 ;
}
void F_36 ( struct V_1 * V_16 )
{
F_37 ( V_16 -> V_9 . V_17 ) ;
}
void F_38 ( struct V_1 * V_16 )
{
F_39 ( V_16 -> V_9 . V_17 , & V_16 -> V_4 ) ;
}
void F_40 ( struct V_1 * V_16 )
{
F_6 ( & V_16 -> V_9 , 0 , V_14 ) ;
F_41 ( & V_16 -> V_4 ) ;
F_18 ( & V_16 -> V_9 ) ;
}
void F_42 ( struct V_5 * V_60 )
{
T_1 V_13 = F_4 ( & V_60 -> V_9 , V_14 ) ;
V_13 &= ~ V_26 ;
F_6 ( & V_60 -> V_9 , V_13 , V_14 ) ;
F_6 ( & V_60 -> V_9 , ~ 0 , V_28 ) ;
V_13 &= ~ V_27 ;
V_13 |= ( V_26 | V_15 ) ;
F_6 ( & V_60 -> V_9 , V_13 , V_14 ) ;
F_43 ( V_60 ) ;
}
static T_4 F_44 ( struct V_6 * V_7 )
{
T_1 V_61 ;
struct V_5 * V_60 =
F_3 ( V_7 ) ;
V_61 = F_8 ( & V_60 -> V_9 ,
V_62 ) ;
return ( T_4 ) ~ V_61 ;
}
static void F_45 ( struct V_6 * V_7 )
{
struct V_5 * V_60 =
F_3 ( V_7 ) ;
F_42 ( V_60 ) ;
}
struct V_5 *
F_46 ( unsigned V_35 , const char * V_34 , void T_3 * V_11 ,
unsigned long V_30 )
{
struct V_5 * V_60 = F_29 ( sizeof( * V_60 ) , V_36 ) ;
if ( ! V_60 )
return NULL ;
V_60 -> V_9 . V_11 = V_11 ;
V_60 -> V_9 . V_30 = V_30 ;
V_60 -> V_7 . V_34 = V_34 ;
V_60 -> V_7 . V_35 = V_35 ;
V_60 -> V_7 . V_63 = F_44 ;
V_60 -> V_7 . V_64 = F_47 ( 32 ) ;
V_60 -> V_7 . V_56 = V_65 ;
V_60 -> V_7 . V_66 = F_45 ;
return V_60 ;
}
void F_48 ( struct V_5 * V_60 )
{
F_49 ( & V_60 -> V_7 , V_60 -> V_9 . V_30 ) ;
}
T_4 F_43 ( struct V_5 * V_60 )
{
return ( T_4 ) ~ F_4 ( & V_60 -> V_9 , V_62 ) ;
}
