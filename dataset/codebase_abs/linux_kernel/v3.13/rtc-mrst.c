static inline int F_1 ( T_1 V_1 )
{
if ( ! ( V_1 & V_2 ) )
return 0 ;
return V_1 & V_3 ;
}
static inline unsigned char F_2 ( void )
{
unsigned char V_4 ;
unsigned long V_5 ;
F_3 ( & V_6 , V_5 ) ;
V_4 = ( F_4 ( V_7 ) & V_8 ) ;
F_5 ( & V_6 , V_5 ) ;
return V_4 ;
}
static int F_6 ( struct V_9 * V_10 , struct V_11 * time )
{
unsigned long V_5 ;
if ( F_2 () )
F_7 ( 20 ) ;
F_3 ( & V_6 , V_5 ) ;
time -> V_12 = F_4 ( V_13 ) ;
time -> V_14 = F_4 ( V_15 ) ;
time -> V_16 = F_4 ( V_17 ) ;
time -> V_18 = F_4 ( V_19 ) ;
time -> V_20 = F_4 ( V_21 ) ;
time -> V_22 = F_4 ( V_23 ) ;
F_5 ( & V_6 , V_5 ) ;
time -> V_22 += 72 ;
time -> V_20 -- ;
return F_8 ( time ) ;
}
static int F_9 ( struct V_9 * V_10 , struct V_11 * time )
{
int V_24 ;
unsigned long V_5 ;
unsigned char V_25 , V_26 , V_27 , V_28 , V_29 ;
unsigned int V_30 ;
V_30 = time -> V_22 ;
V_25 = time -> V_20 + 1 ;
V_26 = time -> V_18 ;
V_27 = time -> V_16 ;
V_28 = time -> V_14 ;
V_29 = time -> V_12 ;
if ( V_30 < 72 || V_30 > 138 )
return - V_31 ;
V_30 -= 72 ;
F_3 ( & V_6 , V_5 ) ;
F_10 ( V_30 , V_23 ) ;
F_10 ( V_25 , V_21 ) ;
F_10 ( V_26 , V_19 ) ;
F_10 ( V_27 , V_17 ) ;
F_10 ( V_28 , V_15 ) ;
F_10 ( V_29 , V_13 ) ;
F_5 ( & V_6 , V_5 ) ;
V_24 = F_11 ( V_32 , V_33 ) ;
return V_24 ;
}
static int F_12 ( struct V_9 * V_10 , struct V_34 * V_35 )
{
struct V_36 * V_37 = F_13 ( V_10 ) ;
unsigned char V_38 ;
if ( V_37 -> V_39 <= 0 )
return - V_40 ;
V_35 -> time . V_18 = - 1 ;
V_35 -> time . V_20 = - 1 ;
V_35 -> time . V_22 = - 1 ;
F_14 ( & V_6 ) ;
V_35 -> time . V_12 = F_4 ( V_41 ) ;
V_35 -> time . V_14 = F_4 ( V_42 ) ;
V_35 -> time . V_16 = F_4 ( V_43 ) ;
V_38 = F_4 ( V_44 ) ;
F_15 ( & V_6 ) ;
V_35 -> V_45 = ! ! ( V_38 & V_46 ) ;
V_35 -> V_47 = 0 ;
return 0 ;
}
static void F_16 ( struct V_36 * V_37 , unsigned char V_38 )
{
unsigned char V_1 ;
V_1 = F_4 ( V_48 ) ;
V_1 &= ( V_38 & V_3 ) | V_2 ;
if ( F_1 ( V_1 ) )
F_17 ( V_37 -> V_49 , 1 , V_1 ) ;
}
static void F_18 ( struct V_36 * V_37 , unsigned char V_50 )
{
unsigned char V_38 ;
V_38 = F_4 ( V_44 ) ;
F_16 ( V_37 , V_38 ) ;
V_38 |= V_50 ;
F_10 ( V_38 , V_44 ) ;
F_16 ( V_37 , V_38 ) ;
}
static void F_19 ( struct V_36 * V_37 , unsigned char V_50 )
{
unsigned char V_38 ;
V_38 = F_4 ( V_44 ) ;
V_38 &= ~ V_50 ;
F_10 ( V_38 , V_44 ) ;
F_16 ( V_37 , V_38 ) ;
}
static int F_20 ( struct V_9 * V_10 , struct V_34 * V_35 )
{
struct V_36 * V_37 = F_13 ( V_10 ) ;
unsigned char V_27 , V_28 , V_29 ;
int V_24 = 0 ;
if ( ! V_37 -> V_39 )
return - V_40 ;
V_27 = V_35 -> time . V_16 ;
V_28 = V_35 -> time . V_14 ;
V_29 = V_35 -> time . V_12 ;
F_14 ( & V_6 ) ;
F_19 ( V_37 , V_46 ) ;
F_10 ( V_27 , V_43 ) ;
F_10 ( V_28 , V_42 ) ;
F_10 ( V_29 , V_41 ) ;
F_15 ( & V_6 ) ;
V_24 = F_11 ( V_32 , V_51 ) ;
if ( V_24 )
return V_24 ;
F_14 ( & V_6 ) ;
if ( V_35 -> V_45 )
F_18 ( V_37 , V_46 ) ;
F_15 ( & V_6 ) ;
return 0 ;
}
static int F_21 ( struct V_9 * V_10 , unsigned int V_45 )
{
struct V_36 * V_37 = F_13 ( V_10 ) ;
unsigned long V_5 ;
F_3 ( & V_6 , V_5 ) ;
if ( V_45 )
F_18 ( V_37 , V_46 ) ;
else
F_19 ( V_37 , V_46 ) ;
F_5 ( & V_6 , V_5 ) ;
return 0 ;
}
static int F_22 ( struct V_9 * V_10 , struct V_52 * V_53 )
{
unsigned char V_38 , V_54 ;
F_14 ( & V_6 ) ;
V_38 = F_4 ( V_44 ) ;
V_54 = F_4 ( V_55 ) ;
F_15 ( & V_6 ) ;
return F_23 ( V_53 ,
L_1
L_2
L_3
L_4 ,
( V_38 & V_56 ) ? L_5 : L_6 ,
( V_38 & V_46 ) ? L_5 : L_6 ) ;
}
static T_2 F_24 ( int V_39 , void * V_57 )
{
T_1 V_58 ;
F_25 ( & V_6 ) ;
V_58 = F_4 ( V_48 ) ;
F_26 ( & V_6 ) ;
V_58 &= V_3 | V_2 ;
if ( F_1 ( V_58 ) ) {
F_17 ( V_57 , 1 , V_58 ) ;
return V_59 ;
}
return V_60 ;
}
static int F_27 ( struct V_9 * V_10 , struct V_61 * V_62 ,
int V_63 )
{
int V_64 = 0 ;
unsigned char V_38 ;
if ( V_36 . V_10 )
return - V_65 ;
if ( ! V_62 )
return - V_66 ;
V_62 = F_28 ( V_62 -> V_67 , F_29 ( V_62 ) ,
V_68 ) ;
if ( ! V_62 ) {
F_30 ( V_10 , L_7 ) ;
return - V_65 ;
}
V_36 . V_39 = V_63 ;
V_36 . V_62 = V_62 ;
V_36 . V_10 = V_10 ;
F_31 ( V_10 , & V_36 ) ;
V_36 . V_49 = F_32 ( V_68 , V_10 ,
& V_69 , V_70 ) ;
if ( F_33 ( V_36 . V_49 ) ) {
V_64 = F_34 ( V_36 . V_49 ) ;
goto V_71;
}
F_35 ( V_62 , F_36 ( & V_36 . V_49 -> V_10 ) ) ;
F_14 ( & V_6 ) ;
F_19 ( & V_36 , V_56 | V_46 ) ;
V_38 = F_4 ( V_44 ) ;
F_15 ( & V_6 ) ;
if ( ! ( V_38 & V_72 ) || ( V_38 & ( V_73 ) ) )
F_30 ( V_10 , L_8 ) ;
if ( V_63 ) {
V_64 = F_37 ( V_63 , F_24 ,
0 , F_36 ( & V_36 . V_49 -> V_10 ) ,
V_36 . V_49 ) ;
if ( V_64 < 0 ) {
F_30 ( V_10 , L_9 ,
V_63 , V_64 ) ;
goto V_74;
}
}
F_30 ( V_10 , L_10 ) ;
return 0 ;
V_74:
F_38 ( V_36 . V_49 ) ;
V_71:
V_36 . V_10 = NULL ;
F_39 ( V_62 -> V_67 , F_29 ( V_62 ) ) ;
F_40 ( V_10 , L_11 ) ;
return V_64 ;
}
static void F_41 ( void )
{
F_14 ( & V_6 ) ;
F_19 ( & V_36 , V_3 ) ;
F_15 ( & V_6 ) ;
}
static void F_42 ( struct V_9 * V_10 )
{
struct V_36 * V_37 = F_13 ( V_10 ) ;
struct V_61 * V_62 ;
F_41 () ;
if ( V_37 -> V_39 )
F_43 ( V_37 -> V_39 , V_37 -> V_49 ) ;
F_38 ( V_37 -> V_49 ) ;
V_37 -> V_49 = NULL ;
V_62 = V_37 -> V_62 ;
F_39 ( V_62 -> V_67 , F_29 ( V_62 ) ) ;
V_37 -> V_62 = NULL ;
V_37 -> V_10 = NULL ;
}
static int F_44 ( struct V_9 * V_10 , T_3 V_75 )
{
struct V_36 * V_37 = F_13 ( V_10 ) ;
unsigned char V_76 ;
F_14 ( & V_6 ) ;
V_37 -> V_77 = V_76 = F_4 ( V_44 ) ;
if ( V_76 & ( V_56 | V_46 ) ) {
unsigned char V_50 ;
if ( F_45 ( V_10 ) )
V_50 = V_3 & ~ V_46 ;
else
V_50 = V_3 ;
V_76 &= ~ V_50 ;
F_10 ( V_76 , V_44 ) ;
F_16 ( V_37 , V_76 ) ;
}
F_15 ( & V_6 ) ;
if ( V_76 & V_46 ) {
V_37 -> V_78 = 1 ;
F_46 ( V_37 -> V_39 ) ;
}
F_30 ( & V_36 . V_49 -> V_10 , L_12 ,
( V_76 & V_46 ) ? L_13 : L_14 ,
V_76 ) ;
return 0 ;
}
static inline int F_47 ( struct V_9 * V_10 )
{
return F_44 ( V_10 , V_79 ) ;
}
static int F_48 ( struct V_9 * V_10 )
{
struct V_36 * V_37 = F_13 ( V_10 ) ;
unsigned char V_76 = V_37 -> V_77 ;
if ( V_76 & V_3 ) {
unsigned char V_50 ;
if ( V_37 -> V_78 ) {
F_49 ( V_37 -> V_39 ) ;
V_37 -> V_78 = 0 ;
}
F_14 ( & V_6 ) ;
do {
F_10 ( V_76 , V_44 ) ;
V_50 = F_4 ( V_48 ) ;
V_50 &= ( V_76 & V_3 ) | V_2 ;
if ( ! F_1 ( V_50 ) )
break;
F_17 ( V_37 -> V_49 , 1 , V_50 ) ;
V_76 &= ~ V_46 ;
} while ( V_50 & V_46 );
F_15 ( & V_6 ) ;
}
F_30 ( & V_36 . V_49 -> V_10 , L_15 , V_76 ) ;
return 0 ;
}
static inline int F_47 ( struct V_9 * V_10 )
{
return - V_80 ;
}
static int F_50 ( struct V_81 * V_82 )
{
return F_27 ( & V_82 -> V_10 ,
F_51 ( V_82 , V_83 , 0 ) ,
F_52 ( V_82 , 0 ) ) ;
}
static int F_53 ( struct V_81 * V_82 )
{
F_42 ( & V_82 -> V_10 ) ;
return 0 ;
}
static void F_54 ( struct V_81 * V_82 )
{
if ( V_84 == V_85 && ! F_47 ( & V_82 -> V_10 ) )
return;
F_41 () ;
}
