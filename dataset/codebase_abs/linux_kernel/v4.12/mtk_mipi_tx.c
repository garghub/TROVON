static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_4 ) ;
}
static void F_3 ( struct V_1 * V_5 , T_1 V_6 ,
T_1 V_7 )
{
T_1 V_8 = F_4 ( V_5 -> V_9 + V_6 ) ;
F_5 ( V_8 & ~ V_7 , V_5 -> V_9 + V_6 ) ;
}
static void F_6 ( struct V_1 * V_5 , T_1 V_6 ,
T_1 V_7 )
{
T_1 V_8 = F_4 ( V_5 -> V_9 + V_6 ) ;
F_5 ( V_8 | V_7 , V_5 -> V_9 + V_6 ) ;
}
static void F_7 ( struct V_1 * V_5 , T_1 V_6 ,
T_1 V_10 , T_1 V_11 )
{
T_1 V_8 = F_4 ( V_5 -> V_9 + V_6 ) ;
F_5 ( ( V_8 & ~ V_10 ) | ( V_11 & V_10 ) , V_5 -> V_9 + V_6 ) ;
}
static int F_8 ( struct V_2 * V_3 )
{
struct V_1 * V_5 = F_1 ( V_3 ) ;
T_2 V_12 , V_13 , V_14 ;
T_3 V_15 ;
F_9 ( V_5 -> V_16 , L_1 , V_5 -> V_17 ) ;
if ( V_5 -> V_17 >= 500000000 ) {
V_12 = 1 ;
V_13 = 0 ;
V_14 = 0 ;
} else if ( V_5 -> V_17 >= 250000000 ) {
V_12 = 2 ;
V_13 = 1 ;
V_14 = 0 ;
} else if ( V_5 -> V_17 >= 125000000 ) {
V_12 = 4 ;
V_13 = 2 ;
V_14 = 0 ;
} else if ( V_5 -> V_17 > 62000000 ) {
V_12 = 8 ;
V_13 = 2 ;
V_14 = 1 ;
} else if ( V_5 -> V_17 >= 50000000 ) {
V_12 = 16 ;
V_13 = 2 ;
V_14 = 2 ;
} else {
return - V_18 ;
}
F_7 ( V_5 , V_19 ,
V_20 |
V_21 | V_22 ,
( 4 << 20 ) | ( 4 << 17 ) | ( 4 << 14 ) |
( 4 << 11 ) | ( 4 << 8 ) | ( 4 << 5 ) |
V_21 | V_22 ) ;
F_10 ( 30 , 100 ) ;
F_7 ( V_5 , V_23 ,
V_24 | V_25 ,
( 8 << 4 ) | V_25 ) ;
F_6 ( V_5 , V_26 ,
V_27 | V_28 ) ;
F_7 ( V_5 , V_29 ,
V_30 |
V_31 ,
V_30 ) ;
F_3 ( V_5 , V_32 ,
V_33 ) ;
F_7 ( V_5 , V_32 ,
V_34 | V_35 |
V_36 ,
( V_13 << 3 ) | ( V_14 << 5 ) ) ;
V_15 = F_11 ( ( ( T_3 ) V_5 -> V_17 * 2 * V_12 ) << 24 ,
26000000 ) ;
F_5 ( V_15 , V_5 -> V_9 + V_37 ) ;
F_6 ( V_5 , V_38 ,
V_39 ) ;
F_6 ( V_5 , V_32 , V_33 ) ;
F_10 ( 20 , 100 ) ;
F_3 ( V_5 , V_38 ,
V_40 ) ;
F_7 ( V_5 , V_41 ,
V_42 ,
V_5 -> V_43 -> V_44 ) ;
return 0 ;
}
static void F_12 ( struct V_2 * V_3 )
{
struct V_1 * V_5 = F_1 ( V_3 ) ;
F_9 ( V_5 -> V_16 , L_2 ) ;
F_3 ( V_5 , V_32 ,
V_33 ) ;
F_7 ( V_5 , V_41 ,
V_42 , 0 ) ;
F_7 ( V_5 , V_29 ,
V_31 |
V_30 ,
V_31 ) ;
F_3 ( V_5 , V_23 ,
V_25 ) ;
F_3 ( V_5 , V_26 ,
V_27 | V_28 ) ;
F_3 ( V_5 , V_19 ,
V_21 | V_22 ) ;
F_3 ( V_5 , V_32 ,
V_45 ) ;
}
static long F_13 ( struct V_2 * V_3 , unsigned long V_46 ,
unsigned long * V_47 )
{
return F_14 ( V_46 , 50000000 , 1250000000 ) ;
}
static int F_15 ( struct V_2 * V_3 , unsigned long V_46 ,
unsigned long V_48 )
{
struct V_1 * V_5 = F_1 ( V_3 ) ;
F_9 ( V_5 -> V_16 , L_3 , V_46 ) ;
V_5 -> V_17 = V_46 ;
return 0 ;
}
static unsigned long F_16 ( struct V_2 * V_3 ,
unsigned long V_48 )
{
struct V_1 * V_5 = F_1 ( V_3 ) ;
return V_5 -> V_17 ;
}
static int F_17 ( struct V_49 * V_49 )
{
struct V_1 * V_5 = F_18 ( V_49 ) ;
T_1 V_50 ;
for ( V_50 = V_51 ;
V_50 <= V_52 ; V_50 += 4 )
F_6 ( V_5 , V_50 , V_53 ) ;
F_3 ( V_5 , V_23 ,
V_54 ) ;
return 0 ;
}
static int F_19 ( struct V_49 * V_49 )
{
struct V_1 * V_5 = F_18 ( V_49 ) ;
int V_55 ;
V_55 = F_20 ( V_5 -> V_56 ) ;
if ( V_55 < 0 )
return V_55 ;
F_17 ( V_49 ) ;
return 0 ;
}
static void F_21 ( struct V_49 * V_49 )
{
struct V_1 * V_5 = F_18 ( V_49 ) ;
T_1 V_50 ;
F_6 ( V_5 , V_23 ,
V_54 ) ;
for ( V_50 = V_51 ;
V_50 <= V_52 ; V_50 += 4 )
F_3 ( V_5 , V_50 , V_53 ) ;
}
static int F_22 ( struct V_49 * V_49 )
{
struct V_1 * V_5 = F_18 ( V_49 ) ;
F_21 ( V_49 ) ;
F_23 ( V_5 -> V_56 ) ;
return 0 ;
}
static int F_24 ( struct V_57 * V_58 )
{
struct V_59 * V_16 = & V_58 -> V_16 ;
struct V_1 * V_5 ;
struct V_60 * V_61 ;
struct V_62 * V_63 ;
const char * V_64 ;
struct V_65 V_66 = {
. V_67 = & V_68 ,
. V_69 = 1 ,
. V_70 = ( const char * const * ) & V_64 ,
. V_71 = V_72 ,
} ;
struct V_49 * V_49 ;
struct V_73 * V_73 ;
int V_55 ;
V_5 = F_25 ( V_16 , sizeof( * V_5 ) , V_74 ) ;
if ( ! V_5 )
return - V_75 ;
V_5 -> V_43 = F_26 ( V_16 ) ;
V_61 = F_27 ( V_58 , V_76 , 0 ) ;
V_5 -> V_9 = F_28 ( V_16 , V_61 ) ;
if ( F_29 ( V_5 -> V_9 ) ) {
V_55 = F_30 ( V_5 -> V_9 ) ;
F_31 ( V_16 , L_4 , V_55 ) ;
return V_55 ;
}
V_63 = F_32 ( V_16 , NULL ) ;
if ( F_29 ( V_63 ) ) {
V_55 = F_30 ( V_63 ) ;
F_31 ( V_16 , L_5 , V_55 ) ;
return V_55 ;
}
V_64 = F_33 ( V_63 ) ;
V_55 = F_34 ( V_16 -> V_77 , L_6 ,
& V_66 . V_78 ) ;
if ( V_55 < 0 ) {
F_31 ( V_16 , L_7 , V_55 ) ;
return V_55 ;
}
V_5 -> V_4 . V_79 = & V_66 ;
V_5 -> V_56 = F_35 ( V_16 , & V_5 -> V_4 ) ;
if ( F_29 ( V_5 -> V_56 ) ) {
V_55 = F_30 ( V_5 -> V_56 ) ;
F_31 ( V_16 , L_8 , V_55 ) ;
return V_55 ;
}
V_49 = F_36 ( V_16 , NULL , & V_80 ) ;
if ( F_29 ( V_49 ) ) {
V_55 = F_30 ( V_49 ) ;
F_31 ( V_16 , L_9 , V_55 ) ;
return V_55 ;
}
F_37 ( V_49 , V_5 ) ;
V_73 = F_38 ( V_16 , V_81 ) ;
if ( F_29 ( V_73 ) ) {
V_55 = F_30 ( V_73 ) ;
return V_55 ;
}
V_5 -> V_16 = V_16 ;
return F_39 ( V_16 -> V_77 , V_82 ,
V_5 -> V_56 ) ;
}
static int F_40 ( struct V_57 * V_58 )
{
F_41 ( V_58 -> V_16 . V_77 ) ;
return 0 ;
}
