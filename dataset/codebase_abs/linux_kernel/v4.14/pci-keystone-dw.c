static inline void F_1 ( T_1 V_1 , T_1 * V_2 ,
T_1 * V_3 )
{
* V_2 = V_1 % 8 ;
* V_3 = V_1 >> 3 ;
}
T_2 F_2 ( struct V_4 * V_5 )
{
struct V_6 * V_7 = F_3 ( V_5 ) ;
struct V_8 * V_9 = F_4 ( V_7 ) ;
return V_9 -> V_10 . V_11 + V_12 ;
}
static T_1 F_5 ( struct V_8 * V_9 , T_1 V_1 )
{
return F_6 ( V_9 -> V_13 + V_1 ) ;
}
static void F_7 ( struct V_8 * V_9 , T_1 V_1 , T_1 V_14 )
{
F_8 ( V_14 , V_9 -> V_13 + V_1 ) ;
}
void F_9 ( struct V_8 * V_9 , int V_1 )
{
struct V_6 * V_7 = V_9 -> V_7 ;
struct V_4 * V_5 = & V_7 -> V_5 ;
struct V_15 * V_16 = V_7 -> V_16 ;
T_1 V_17 , V_18 ;
int V_19 , V_20 ;
V_17 = F_5 ( V_9 , V_21 + ( V_1 << 4 ) ) ;
for ( V_19 = 0 ; V_19 < 4 ; V_19 ++ ) {
if ( F_10 ( V_19 ) & V_17 ) {
V_18 = V_1 + ( V_19 << 3 ) ;
V_20 = F_11 ( V_5 -> V_22 , V_18 ) ;
F_12 ( V_16 , L_1 ,
V_19 , V_18 , V_20 ) ;
F_13 ( V_20 ) ;
}
}
}
static void F_14 ( struct V_23 * V_24 )
{
T_1 V_1 , V_2 , V_3 ;
struct V_8 * V_9 ;
struct V_25 * V_26 ;
struct V_4 * V_5 ;
struct V_6 * V_7 ;
V_26 = F_15 ( V_24 ) ;
V_5 = (struct V_4 * ) F_16 ( V_26 ) ;
V_7 = F_3 ( V_5 ) ;
V_9 = F_4 ( V_7 ) ;
V_1 = V_24 -> V_27 - F_11 ( V_5 -> V_22 , 0 ) ;
F_1 ( V_1 , & V_2 , & V_3 ) ;
F_7 ( V_9 , V_21 + ( V_2 << 4 ) ,
F_10 ( V_3 ) ) ;
F_7 ( V_9 , V_28 , V_2 + V_29 ) ;
}
void F_17 ( struct V_4 * V_5 , int V_27 )
{
T_1 V_2 , V_3 ;
struct V_6 * V_7 = F_3 ( V_5 ) ;
struct V_8 * V_9 = F_4 ( V_7 ) ;
F_1 ( V_27 , & V_2 , & V_3 ) ;
F_7 ( V_9 , V_30 + ( V_2 << 4 ) ,
F_10 ( V_3 ) ) ;
}
void F_18 ( struct V_4 * V_5 , int V_27 )
{
T_1 V_2 , V_3 ;
struct V_6 * V_7 = F_3 ( V_5 ) ;
struct V_8 * V_9 = F_4 ( V_7 ) ;
F_1 ( V_27 , & V_2 , & V_3 ) ;
F_7 ( V_9 , V_31 + ( V_2 << 4 ) ,
F_10 ( V_3 ) ) ;
}
static void F_19 ( struct V_23 * V_24 )
{
struct V_25 * V_26 ;
struct V_4 * V_5 ;
T_1 V_1 ;
V_26 = F_15 ( V_24 ) ;
V_5 = (struct V_4 * ) F_16 ( V_26 ) ;
V_1 = V_24 -> V_27 - F_11 ( V_5 -> V_22 , 0 ) ;
if ( F_20 ( V_32 ) ) {
if ( V_26 -> V_33 . V_34 )
F_21 ( V_24 ) ;
}
F_18 ( V_5 , V_1 ) ;
}
static void F_22 ( struct V_23 * V_24 )
{
struct V_25 * V_26 ;
struct V_4 * V_5 ;
T_1 V_1 ;
V_26 = F_15 ( V_24 ) ;
V_5 = (struct V_4 * ) F_16 ( V_26 ) ;
V_1 = V_24 -> V_27 - F_11 ( V_5 -> V_22 , 0 ) ;
if ( F_20 ( V_32 ) ) {
if ( V_26 -> V_33 . V_34 )
F_23 ( V_24 ) ;
}
F_17 ( V_5 , V_1 ) ;
}
static int F_24 ( struct V_22 * V_35 , unsigned int V_27 ,
T_3 V_36 )
{
F_25 ( V_27 , & V_37 ,
V_38 ) ;
F_26 ( V_27 , V_35 -> V_39 ) ;
return 0 ;
}
int F_27 ( struct V_4 * V_5 , struct V_40 * V_41 )
{
struct V_6 * V_7 = F_3 ( V_5 ) ;
struct V_8 * V_9 = F_4 ( V_7 ) ;
struct V_15 * V_16 = V_7 -> V_16 ;
int V_42 ;
V_5 -> V_22 = F_28 ( V_9 -> V_43 ,
V_44 ,
& V_45 ,
V_41 ) ;
if ( ! V_5 -> V_22 ) {
F_29 ( V_16 , L_2 ) ;
return - V_46 ;
}
for ( V_42 = 0 ; V_42 < V_44 ; V_42 ++ )
F_30 ( V_5 -> V_22 , V_42 ) ;
return 0 ;
}
void F_31 ( struct V_8 * V_9 )
{
int V_42 ;
for ( V_42 = 0 ; V_42 < V_47 ; V_42 ++ )
F_7 ( V_9 , V_48 + ( V_42 << 4 ) , 0x1 ) ;
}
void F_32 ( struct V_8 * V_9 , int V_1 )
{
struct V_6 * V_7 = V_9 -> V_7 ;
struct V_15 * V_16 = V_7 -> V_16 ;
T_1 V_17 ;
int V_20 ;
V_17 = F_5 ( V_9 , V_49 + ( V_1 << 4 ) ) ;
if ( F_10 ( 0 ) & V_17 ) {
V_20 = F_11 ( V_9 -> V_50 , V_1 ) ;
F_12 ( V_16 , L_3 , V_1 , V_20 ) ;
F_13 ( V_20 ) ;
}
F_7 ( V_9 , V_28 , V_1 ) ;
}
void F_33 ( struct V_8 * V_9 )
{
F_7 ( V_9 , V_51 , V_52 ) ;
}
T_4 F_34 ( struct V_8 * V_9 )
{
T_1 V_53 ;
V_53 = F_5 ( V_9 , V_54 ) & V_52 ;
if ( ! V_53 )
return V_55 ;
if ( V_53 & V_56 )
F_29 ( V_9 -> V_7 -> V_16 , L_4 ,
V_53 ) ;
F_7 ( V_9 , V_57 , V_53 ) ;
return V_58 ;
}
static void F_35 ( struct V_23 * V_24 )
{
}
static void F_36 ( struct V_23 * V_24 )
{
}
static void F_37 ( struct V_23 * V_24 )
{
}
static int F_38 ( struct V_22 * V_24 ,
unsigned int V_27 , T_3 V_59 )
{
F_25 ( V_27 , & V_60 ,
V_38 ) ;
F_26 ( V_27 , V_24 -> V_39 ) ;
return 0 ;
}
static void F_39 ( struct V_8 * V_9 )
{
T_1 V_14 ;
V_14 = F_5 ( V_9 , V_61 ) ;
F_7 ( V_9 , V_61 , V_62 | V_14 ) ;
do {
V_14 = F_5 ( V_9 , V_61 ) ;
} while ( ! ( V_14 & V_62 ) );
}
static void F_40 ( struct V_8 * V_9 )
{
T_1 V_14 ;
V_14 = F_5 ( V_9 , V_61 ) ;
F_7 ( V_9 , V_61 , ~ V_62 & V_14 ) ;
do {
V_14 = F_5 ( V_9 , V_61 ) ;
} while ( V_14 & V_62 );
}
void F_41 ( struct V_8 * V_9 )
{
struct V_6 * V_7 = V_9 -> V_7 ;
struct V_4 * V_5 = & V_7 -> V_5 ;
T_1 V_11 = V_5 -> V_63 -> V_11 , V_64 = V_5 -> V_63 -> V_64 ;
int V_42 , V_65 ;
T_1 V_14 ;
F_39 ( V_9 ) ;
F_42 ( V_7 , V_66 , 0 ) ;
F_42 ( V_7 , V_67 , 0 ) ;
F_40 ( V_9 ) ;
F_7 ( V_9 , V_68 , V_69 & 0x7 ) ;
V_65 = ( 1 << ( V_69 & 0x7 ) ) * V_70 ;
for ( V_42 = 0 ; ( V_42 < V_71 ) && ( V_11 < V_64 ) ; V_42 ++ ) {
F_7 ( V_9 , F_43 ( V_42 ) , V_11 | 1 ) ;
F_7 ( V_9 , F_44 ( V_42 ) , 0 ) ;
V_11 += V_65 ;
}
V_14 = F_5 ( V_9 , V_61 ) ;
F_7 ( V_9 , V_61 , V_72 | V_14 ) ;
}
static void T_5 * F_45 ( struct V_8 * V_9 , T_6 V_73 ,
unsigned int V_74 )
{
T_6 V_15 = F_46 ( V_74 ) , V_75 = F_47 ( V_74 ) ;
struct V_6 * V_7 = V_9 -> V_7 ;
struct V_4 * V_5 = & V_7 -> V_5 ;
T_1 V_76 ;
if ( V_73 == 0 )
return V_7 -> V_77 ;
V_76 = ( V_73 << 16 ) | ( V_15 << 8 ) | V_75 ;
if ( V_73 != 1 )
V_76 |= F_10 ( 24 ) ;
F_7 ( V_9 , V_78 , V_76 ) ;
return V_5 -> V_79 ;
}
int F_48 ( struct V_4 * V_5 , struct V_80 * V_73 ,
unsigned int V_74 , int V_81 , int V_82 , T_1 * V_14 )
{
struct V_6 * V_7 = F_3 ( V_5 ) ;
struct V_8 * V_9 = F_4 ( V_7 ) ;
T_6 V_83 = V_73 -> V_84 ;
void T_5 * V_85 ;
V_85 = F_45 ( V_9 , V_83 , V_74 ) ;
return F_49 ( V_85 + V_81 , V_82 , V_14 ) ;
}
int F_50 ( struct V_4 * V_5 , struct V_80 * V_73 ,
unsigned int V_74 , int V_81 , int V_82 , T_1 V_14 )
{
struct V_6 * V_7 = F_3 ( V_5 ) ;
struct V_8 * V_9 = F_4 ( V_7 ) ;
T_6 V_83 = V_73 -> V_84 ;
void T_5 * V_85 ;
V_85 = F_45 ( V_9 , V_83 , V_74 ) ;
return F_51 ( V_85 + V_81 , V_82 , V_14 ) ;
}
void F_52 ( struct V_4 * V_5 )
{
struct V_6 * V_7 = F_3 ( V_5 ) ;
struct V_8 * V_9 = F_4 ( V_7 ) ;
F_39 ( V_9 ) ;
F_42 ( V_7 , V_66 , 1 ) ;
F_42 ( V_7 , V_66 , V_86 - 1 ) ;
F_40 ( V_9 ) ;
F_42 ( V_7 , V_66 , V_9 -> V_10 . V_11 ) ;
}
int F_53 ( struct V_6 * V_7 )
{
T_1 V_14 ;
V_14 = F_54 ( V_7 , V_87 ) ;
return ( V_14 & V_88 ) == V_89 ;
}
void F_55 ( struct V_8 * V_9 )
{
T_1 V_14 ;
V_14 = F_5 ( V_9 , V_61 ) ;
V_14 &= ~ V_90 ;
F_7 ( V_9 , V_61 , V_90 | V_14 ) ;
V_14 = F_5 ( V_9 , V_61 ) ;
F_7 ( V_9 , V_61 , V_90 | V_14 ) ;
}
int T_7 F_56 ( struct V_8 * V_9 ,
struct V_91 * V_43 )
{
struct V_6 * V_7 = V_9 -> V_7 ;
struct V_4 * V_5 = & V_7 -> V_5 ;
struct V_15 * V_16 = V_7 -> V_16 ;
struct V_92 * V_93 = F_57 ( V_16 ) ;
struct V_94 * V_95 ;
V_95 = F_58 ( V_93 , V_96 , 0 ) ;
V_7 -> V_77 = F_59 ( V_16 , V_95 ) ;
if ( F_60 ( V_7 -> V_77 ) )
return F_61 ( V_7 -> V_77 ) ;
V_5 -> V_79 = V_7 -> V_77 + V_97 ;
V_5 -> V_98 = V_5 -> V_79 ;
V_95 = F_58 ( V_93 , V_96 , 1 ) ;
V_9 -> V_13 = F_62 ( V_16 , V_95 ) ;
if ( F_60 ( V_9 -> V_13 ) )
return F_61 ( V_9 -> V_13 ) ;
V_9 -> V_10 = * V_95 ;
V_9 -> V_50 =
F_28 ( V_9 -> V_99 ,
V_47 ,
& V_100 ,
NULL ) ;
if ( ! V_9 -> V_50 ) {
F_29 ( V_16 , L_5 ) ;
return - V_101 ;
}
return F_63 ( V_5 ) ;
}
