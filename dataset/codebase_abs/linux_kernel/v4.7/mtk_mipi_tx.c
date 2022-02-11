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
unsigned int V_12 , V_13 , V_14 ;
T_2 V_15 ;
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
V_15 = F_11 ( ( ( T_2 ) V_5 -> V_17 * 2 * V_12 ) << 24 ,
26000000 ) ;
F_5 ( V_15 , V_5 -> V_9 + V_37 ) ;
F_6 ( V_5 , V_38 ,
V_39 ) ;
F_6 ( V_5 , V_32 , V_33 ) ;
F_10 ( 20 , 100 ) ;
F_3 ( V_5 , V_38 ,
V_40 ) ;
return 0 ;
}
static void F_12 ( struct V_2 * V_3 )
{
struct V_1 * V_5 = F_1 ( V_3 ) ;
F_9 ( V_5 -> V_16 , L_2 ) ;
F_3 ( V_5 , V_32 ,
V_33 ) ;
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
V_41 ) ;
}
static long F_13 ( struct V_2 * V_3 , unsigned long V_42 ,
unsigned long * V_43 )
{
return F_14 ( V_42 , 50000000 , 1250000000 ) ;
}
static int F_15 ( struct V_2 * V_3 , unsigned long V_42 ,
unsigned long V_44 )
{
struct V_1 * V_5 = F_1 ( V_3 ) ;
F_9 ( V_5 -> V_16 , L_3 , V_42 ) ;
V_5 -> V_17 = V_42 ;
return 0 ;
}
static unsigned long F_16 ( struct V_2 * V_3 ,
unsigned long V_44 )
{
struct V_1 * V_5 = F_1 ( V_3 ) ;
return V_5 -> V_17 ;
}
static int F_17 ( struct V_45 * V_45 )
{
struct V_1 * V_5 = F_18 ( V_45 ) ;
unsigned int V_46 ;
for ( V_46 = V_47 ;
V_46 <= V_48 ; V_46 += 4 )
F_6 ( V_5 , V_46 , V_49 ) ;
F_3 ( V_5 , V_23 ,
V_50 ) ;
return 0 ;
}
static int F_19 ( struct V_45 * V_45 )
{
struct V_1 * V_5 = F_18 ( V_45 ) ;
int V_51 ;
V_51 = F_20 ( V_5 -> V_52 ) ;
if ( V_51 < 0 )
return V_51 ;
F_17 ( V_45 ) ;
return 0 ;
}
static void F_21 ( struct V_45 * V_45 )
{
struct V_1 * V_5 = F_18 ( V_45 ) ;
unsigned int V_46 ;
F_6 ( V_5 , V_23 ,
V_50 ) ;
for ( V_46 = V_47 ;
V_46 <= V_48 ; V_46 += 4 )
F_3 ( V_5 , V_46 , V_49 ) ;
}
static int F_22 ( struct V_45 * V_45 )
{
struct V_1 * V_5 = F_18 ( V_45 ) ;
F_21 ( V_45 ) ;
F_23 ( V_5 -> V_52 ) ;
return 0 ;
}
static int F_24 ( struct V_53 * V_54 )
{
struct V_55 * V_16 = & V_54 -> V_16 ;
struct V_1 * V_5 ;
struct V_56 * V_57 ;
struct V_58 * V_59 ;
const char * V_60 ;
struct V_61 V_62 = {
. V_63 = & V_64 ,
. V_65 = 1 ,
. V_66 = ( const char * const * ) & V_60 ,
. V_67 = V_68 ,
} ;
struct V_45 * V_45 ;
struct V_69 * V_69 ;
int V_51 ;
V_5 = F_25 ( V_16 , sizeof( * V_5 ) , V_70 ) ;
if ( ! V_5 )
return - V_71 ;
V_57 = F_26 ( V_54 , V_72 , 0 ) ;
V_5 -> V_9 = F_27 ( V_16 , V_57 ) ;
if ( F_28 ( V_5 -> V_9 ) ) {
V_51 = F_29 ( V_5 -> V_9 ) ;
F_30 ( V_16 , L_4 , V_51 ) ;
return V_51 ;
}
V_59 = F_31 ( V_16 , NULL ) ;
if ( F_28 ( V_59 ) ) {
V_51 = F_29 ( V_59 ) ;
F_30 ( V_16 , L_5 , V_51 ) ;
return V_51 ;
}
V_60 = F_32 ( V_59 ) ;
V_51 = F_33 ( V_16 -> V_73 , L_6 ,
& V_62 . V_74 ) ;
if ( V_51 < 0 ) {
F_30 ( V_16 , L_7 , V_51 ) ;
return V_51 ;
}
V_5 -> V_4 . V_75 = & V_62 ;
V_5 -> V_52 = F_34 ( V_16 , & V_5 -> V_4 ) ;
if ( F_28 ( V_5 -> V_52 ) ) {
V_51 = F_29 ( V_5 -> V_52 ) ;
F_30 ( V_16 , L_8 , V_51 ) ;
return V_51 ;
}
V_45 = F_35 ( V_16 , NULL , & V_76 ) ;
if ( F_28 ( V_45 ) ) {
V_51 = F_29 ( V_45 ) ;
F_30 ( V_16 , L_9 , V_51 ) ;
return V_51 ;
}
F_36 ( V_45 , V_5 ) ;
V_69 = F_37 ( V_16 , V_77 ) ;
if ( F_28 ( V_45 ) ) {
V_51 = F_29 ( V_69 ) ;
return V_51 ;
}
V_5 -> V_16 = V_16 ;
return F_38 ( V_16 -> V_73 , V_78 ,
V_5 -> V_52 ) ;
}
static int F_39 ( struct V_53 * V_54 )
{
F_40 ( V_54 -> V_16 . V_73 ) ;
return 0 ;
}
