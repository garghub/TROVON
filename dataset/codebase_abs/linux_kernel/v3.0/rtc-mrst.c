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
time -> V_22 += 60 ;
time -> V_20 -- ;
return V_24 ;
}
static int F_8 ( struct V_9 * V_10 , struct V_11 * time )
{
int V_25 ;
unsigned long V_5 ;
unsigned char V_26 , V_27 , V_28 , V_29 , V_30 ;
unsigned int V_31 ;
V_31 = time -> V_22 ;
V_26 = time -> V_20 + 1 ;
V_27 = time -> V_18 ;
V_28 = time -> V_16 ;
V_29 = time -> V_14 ;
V_30 = time -> V_12 ;
if ( V_31 < 70 || V_31 > 138 )
return - V_32 ;
V_31 -= 60 ;
F_3 ( & V_6 , V_5 ) ;
F_9 ( V_31 , V_23 ) ;
F_9 ( V_26 , V_21 ) ;
F_9 ( V_27 , V_19 ) ;
F_9 ( V_28 , V_17 ) ;
F_9 ( V_29 , V_15 ) ;
F_9 ( V_30 , V_13 ) ;
F_5 ( & V_6 , V_5 ) ;
V_25 = F_10 ( V_33 , V_34 ) ;
return V_25 ;
}
static int F_11 ( struct V_9 * V_10 , struct V_35 * V_36 )
{
struct V_37 * V_38 = F_12 ( V_10 ) ;
unsigned char V_39 ;
if ( V_38 -> V_40 <= 0 )
return - V_41 ;
V_36 -> time . V_18 = - 1 ;
V_36 -> time . V_20 = - 1 ;
V_36 -> time . V_22 = - 1 ;
F_13 ( & V_6 ) ;
V_36 -> time . V_12 = F_4 ( V_42 ) ;
V_36 -> time . V_14 = F_4 ( V_43 ) ;
V_36 -> time . V_16 = F_4 ( V_44 ) ;
V_39 = F_4 ( V_45 ) ;
F_14 ( & V_6 ) ;
V_36 -> V_46 = ! ! ( V_39 & V_47 ) ;
V_36 -> V_48 = 0 ;
return 0 ;
}
static void F_15 ( struct V_37 * V_38 , unsigned char V_39 )
{
unsigned char V_1 ;
V_1 = F_4 ( V_49 ) ;
V_1 &= ( V_39 & V_3 ) | V_2 ;
if ( F_1 ( V_1 ) )
F_16 ( V_38 -> V_50 , 1 , V_1 ) ;
}
static void F_17 ( struct V_37 * V_38 , unsigned char V_51 )
{
unsigned char V_39 ;
V_39 = F_4 ( V_45 ) ;
F_15 ( V_38 , V_39 ) ;
V_39 |= V_51 ;
F_9 ( V_39 , V_45 ) ;
F_15 ( V_38 , V_39 ) ;
}
static void F_18 ( struct V_37 * V_38 , unsigned char V_51 )
{
unsigned char V_39 ;
V_39 = F_4 ( V_45 ) ;
V_39 &= ~ V_51 ;
F_9 ( V_39 , V_45 ) ;
F_15 ( V_38 , V_39 ) ;
}
static int F_19 ( struct V_9 * V_10 , struct V_35 * V_36 )
{
struct V_37 * V_38 = F_12 ( V_10 ) ;
unsigned char V_28 , V_29 , V_30 ;
int V_25 = 0 ;
if ( ! V_38 -> V_40 )
return - V_41 ;
V_28 = V_36 -> time . V_16 ;
V_29 = V_36 -> time . V_14 ;
V_30 = V_36 -> time . V_12 ;
F_13 ( & V_6 ) ;
F_18 ( V_38 , V_47 ) ;
F_9 ( V_28 , V_44 ) ;
F_9 ( V_29 , V_43 ) ;
F_9 ( V_30 , V_42 ) ;
F_14 ( & V_6 ) ;
V_25 = F_10 ( V_33 , V_52 ) ;
if ( V_25 )
return V_25 ;
F_13 ( & V_6 ) ;
if ( V_36 -> V_46 )
F_17 ( V_38 , V_47 ) ;
F_14 ( & V_6 ) ;
return 0 ;
}
static int F_20 ( struct V_9 * V_10 , unsigned int V_46 )
{
struct V_37 * V_38 = F_12 ( V_10 ) ;
unsigned long V_5 ;
F_3 ( & V_6 , V_5 ) ;
if ( V_46 )
F_17 ( V_38 , V_47 ) ;
else
F_18 ( V_38 , V_47 ) ;
F_5 ( & V_6 , V_5 ) ;
return 0 ;
}
static int F_21 ( struct V_9 * V_10 , struct V_53 * V_54 )
{
unsigned char V_39 , V_55 ;
F_13 ( & V_6 ) ;
V_39 = F_4 ( V_45 ) ;
V_55 = F_4 ( V_56 ) ;
F_14 ( & V_6 ) ;
return F_22 ( V_54 ,
L_1
L_2
L_3
L_4 ,
( V_39 & V_57 ) ? L_5 : L_6 ,
( V_39 & V_47 ) ? L_5 : L_6 ) ;
}
static T_2 F_23 ( int V_40 , void * V_58 )
{
T_1 V_59 ;
F_24 ( & V_6 ) ;
V_59 = F_4 ( V_49 ) ;
F_25 ( & V_6 ) ;
V_59 &= V_3 | V_2 ;
if ( F_1 ( V_59 ) ) {
F_16 ( V_58 , 1 , V_59 ) ;
return V_60 ;
}
return V_61 ;
}
static int T_3
F_26 ( struct V_9 * V_10 , struct V_62 * V_63 , int V_64 )
{
int V_65 = 0 ;
unsigned char V_39 ;
if ( V_37 . V_10 )
return - V_66 ;
if ( ! V_63 )
return - V_67 ;
V_63 = F_27 ( V_63 -> V_68 ,
V_63 -> V_69 + 1 - V_63 -> V_68 ,
V_70 ) ;
if ( ! V_63 ) {
F_28 ( V_10 , L_7 ) ;
return - V_66 ;
}
V_37 . V_40 = V_64 ;
V_37 . V_63 = V_63 ;
V_37 . V_10 = V_10 ;
F_29 ( V_10 , & V_37 ) ;
V_37 . V_50 = F_30 ( V_70 , V_10 ,
& V_71 , V_72 ) ;
if ( F_31 ( V_37 . V_50 ) ) {
V_65 = F_32 ( V_37 . V_50 ) ;
goto V_73;
}
F_33 ( V_63 , F_34 ( & V_37 . V_50 -> V_10 ) ) ;
F_13 ( & V_6 ) ;
F_18 ( & V_37 , V_57 | V_47 ) ;
V_39 = F_4 ( V_45 ) ;
F_14 ( & V_6 ) ;
if ( ! ( V_39 & V_24 ) || ( V_39 & ( V_74 ) ) )
F_28 ( V_10 , L_8 ) ;
if ( V_64 ) {
V_65 = F_35 ( V_64 , F_23 ,
V_75 , F_34 ( & V_37 . V_50 -> V_10 ) ,
V_37 . V_50 ) ;
if ( V_65 < 0 ) {
F_28 ( V_10 , L_9 ,
V_64 , V_65 ) ;
goto V_76;
}
}
F_28 ( V_10 , L_10 ) ;
return 0 ;
V_76:
F_36 ( V_37 . V_50 ) ;
V_73:
F_29 ( V_10 , NULL ) ;
V_37 . V_10 = NULL ;
F_37 ( V_63 -> V_68 , F_38 ( V_63 ) ) ;
F_39 ( V_10 , L_11 ) ;
return V_65 ;
}
static void F_40 ( void )
{
F_13 ( & V_6 ) ;
F_18 ( & V_37 , V_3 ) ;
F_14 ( & V_6 ) ;
}
static void T_4 F_41 ( struct V_9 * V_10 )
{
struct V_37 * V_38 = F_12 ( V_10 ) ;
struct V_62 * V_63 ;
F_40 () ;
if ( V_38 -> V_40 )
F_42 ( V_38 -> V_40 , V_38 -> V_50 ) ;
F_36 ( V_38 -> V_50 ) ;
V_38 -> V_50 = NULL ;
V_63 = V_38 -> V_63 ;
F_37 ( V_63 -> V_68 , F_38 ( V_63 ) ) ;
V_38 -> V_63 = NULL ;
V_38 -> V_10 = NULL ;
F_29 ( V_10 , NULL ) ;
}
static int F_43 ( struct V_9 * V_10 , T_5 V_77 )
{
struct V_37 * V_38 = F_12 ( V_10 ) ;
unsigned char V_78 ;
F_13 ( & V_6 ) ;
V_38 -> V_79 = V_78 = F_4 ( V_45 ) ;
if ( V_78 & ( V_57 | V_47 ) ) {
unsigned char V_51 ;
if ( F_44 ( V_10 ) )
V_51 = V_3 & ~ V_47 ;
else
V_51 = V_3 ;
V_78 &= ~ V_51 ;
F_9 ( V_78 , V_45 ) ;
F_15 ( V_38 , V_78 ) ;
}
F_14 ( & V_6 ) ;
if ( V_78 & V_47 ) {
V_38 -> V_80 = 1 ;
F_45 ( V_38 -> V_40 ) ;
}
F_28 ( & V_37 . V_50 -> V_10 , L_12 ,
( V_78 & V_47 ) ? L_13 : L_14 ,
V_78 ) ;
return 0 ;
}
static inline int F_46 ( struct V_9 * V_10 )
{
return F_43 ( V_10 , V_81 ) ;
}
static int F_47 ( struct V_9 * V_10 )
{
struct V_37 * V_38 = F_12 ( V_10 ) ;
unsigned char V_78 = V_38 -> V_79 ;
if ( V_78 & V_3 ) {
unsigned char V_51 ;
if ( V_38 -> V_80 ) {
F_48 ( V_38 -> V_40 ) ;
V_38 -> V_80 = 0 ;
}
F_13 ( & V_6 ) ;
do {
F_9 ( V_78 , V_45 ) ;
V_51 = F_4 ( V_49 ) ;
V_51 &= ( V_78 & V_3 ) | V_2 ;
if ( ! F_1 ( V_51 ) )
break;
F_16 ( V_38 -> V_50 , 1 , V_51 ) ;
V_78 &= ~ V_47 ;
} while ( V_51 & V_47 );
F_14 ( & V_6 ) ;
}
F_28 ( & V_37 . V_50 -> V_10 , L_15 , V_78 ) ;
return 0 ;
}
static inline int F_46 ( struct V_9 * V_10 )
{
return - V_82 ;
}
static int T_3 F_49 ( struct V_83 * V_84 )
{
return F_26 ( & V_84 -> V_10 ,
F_50 ( V_84 , V_85 , 0 ) ,
F_51 ( V_84 , 0 ) ) ;
}
static int T_4 F_52 ( struct V_83 * V_84 )
{
F_41 ( & V_84 -> V_10 ) ;
return 0 ;
}
static void F_53 ( struct V_83 * V_84 )
{
if ( V_86 == V_87 && ! F_46 ( & V_84 -> V_10 ) )
return;
F_40 () ;
}
static int T_6 F_54 ( void )
{
return F_55 ( & V_88 ) ;
}
static void T_7 F_56 ( void )
{
F_57 ( & V_88 ) ;
}
