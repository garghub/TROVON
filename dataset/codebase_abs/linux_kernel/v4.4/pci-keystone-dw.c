static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return V_3 -> V_4 ;
}
static inline void F_2 ( T_1 V_5 , T_1 * V_6 ,
T_1 * V_7 )
{
* V_6 = V_5 % 8 ;
* V_7 = V_5 >> 3 ;
}
T_2 F_3 ( struct V_1 * V_8 )
{
struct V_9 * V_10 = F_4 ( V_8 ) ;
return V_10 -> V_11 . V_12 + V_13 ;
}
void F_5 ( struct V_9 * V_10 , int V_5 )
{
struct V_1 * V_8 = & V_10 -> V_8 ;
T_1 V_14 , V_15 ;
int V_16 , V_17 ;
V_14 = F_6 ( V_10 -> V_18 + V_19 + ( V_5 << 4 ) ) ;
for ( V_16 = 0 ; V_16 < 4 ; V_16 ++ ) {
if ( F_7 ( V_16 ) & V_14 ) {
V_15 = V_5 + ( V_16 << 3 ) ;
V_17 = F_8 ( V_8 -> V_20 , V_15 ) ;
F_9 ( V_8 -> V_21 , L_1 ,
V_16 , V_15 , V_17 ) ;
F_10 ( V_17 ) ;
}
}
}
static void F_11 ( struct V_22 * V_23 )
{
T_1 V_5 , V_6 , V_7 ;
struct V_9 * V_10 ;
struct V_24 * V_25 ;
struct V_1 * V_8 ;
V_25 = F_12 ( V_23 ) ;
V_8 = F_1 ( F_13 ( V_25 ) ) ;
V_10 = F_4 ( V_8 ) ;
V_5 = V_23 -> V_26 - F_8 ( V_8 -> V_20 , 0 ) ;
F_2 ( V_5 , & V_6 , & V_7 ) ;
F_14 ( F_7 ( V_7 ) ,
V_10 -> V_18 + V_19 + ( V_6 << 4 ) ) ;
F_14 ( V_6 + V_27 , V_10 -> V_18 + V_28 ) ;
}
void F_15 ( struct V_1 * V_8 , int V_26 )
{
T_1 V_6 , V_7 ;
struct V_9 * V_10 = F_4 ( V_8 ) ;
F_2 ( V_26 , & V_6 , & V_7 ) ;
F_14 ( F_7 ( V_7 ) ,
V_10 -> V_18 + V_29 + ( V_6 << 4 ) ) ;
}
void F_16 ( struct V_1 * V_8 , int V_26 )
{
T_1 V_6 , V_7 ;
struct V_9 * V_10 = F_4 ( V_8 ) ;
F_2 ( V_26 , & V_6 , & V_7 ) ;
F_14 ( F_7 ( V_7 ) ,
V_10 -> V_18 + V_30 + ( V_6 << 4 ) ) ;
}
static void F_17 ( struct V_22 * V_23 )
{
struct V_9 * V_10 ;
struct V_24 * V_25 ;
struct V_1 * V_8 ;
T_1 V_5 ;
V_25 = F_12 ( V_23 ) ;
V_8 = F_1 ( F_13 ( V_25 ) ) ;
V_10 = F_4 ( V_8 ) ;
V_5 = V_23 -> V_26 - F_8 ( V_8 -> V_20 , 0 ) ;
if ( F_18 ( V_31 ) ) {
if ( V_25 -> V_32 . V_33 )
F_19 ( V_23 ) ;
}
F_16 ( V_8 , V_5 ) ;
}
static void F_20 ( struct V_22 * V_23 )
{
struct V_9 * V_10 ;
struct V_24 * V_25 ;
struct V_1 * V_8 ;
T_1 V_5 ;
V_25 = F_12 ( V_23 ) ;
V_8 = F_1 ( F_13 ( V_25 ) ) ;
V_10 = F_4 ( V_8 ) ;
V_5 = V_23 -> V_26 - F_8 ( V_8 -> V_20 , 0 ) ;
if ( F_18 ( V_31 ) ) {
if ( V_25 -> V_32 . V_33 )
F_21 ( V_23 ) ;
}
F_15 ( V_8 , V_5 ) ;
}
static int F_22 ( struct V_20 * V_34 , unsigned int V_26 ,
T_3 V_35 )
{
F_23 ( V_26 , & V_36 ,
V_37 ) ;
F_24 ( V_26 , V_34 -> V_38 ) ;
return 0 ;
}
int F_25 ( struct V_1 * V_8 , struct V_39 * V_40 )
{
struct V_9 * V_10 = F_4 ( V_8 ) ;
int V_41 ;
V_8 -> V_20 = F_26 ( V_10 -> V_42 ,
V_43 ,
& V_44 ,
V_40 ) ;
if ( ! V_8 -> V_20 ) {
F_27 ( V_8 -> V_21 , L_2 ) ;
return - V_45 ;
}
for ( V_41 = 0 ; V_41 < V_43 ; V_41 ++ )
F_28 ( V_8 -> V_20 , V_41 ) ;
return 0 ;
}
void F_29 ( struct V_9 * V_10 )
{
int V_41 ;
for ( V_41 = 0 ; V_41 < V_46 ; V_41 ++ )
F_14 ( 0x1 , V_10 -> V_18 + V_47 + ( V_41 << 4 ) ) ;
}
void F_30 ( struct V_9 * V_10 , int V_5 )
{
struct V_1 * V_8 = & V_10 -> V_8 ;
T_1 V_14 ;
int V_17 ;
V_14 = F_6 ( V_10 -> V_18 + V_48 + ( V_5 << 4 ) ) ;
if ( F_7 ( 0 ) & V_14 ) {
V_17 = F_8 ( V_10 -> V_49 , V_5 ) ;
F_9 ( V_8 -> V_21 , L_3 , V_5 ,
V_17 ) ;
F_10 ( V_17 ) ;
}
F_14 ( V_5 , V_10 -> V_18 + V_28 ) ;
}
static void F_31 ( struct V_22 * V_23 )
{
}
static void F_32 ( struct V_22 * V_23 )
{
}
static void F_33 ( struct V_22 * V_23 )
{
}
static int F_34 ( struct V_20 * V_23 ,
unsigned int V_26 , T_3 V_50 )
{
F_23 ( V_26 , & V_51 ,
V_37 ) ;
F_24 ( V_26 , V_23 -> V_38 ) ;
return 0 ;
}
static void F_35 ( void T_4 * V_52 )
{
T_1 V_53 ;
F_14 ( V_54 | F_6 ( V_52 + V_55 ) ,
V_52 + V_55 ) ;
do {
V_53 = F_6 ( V_52 + V_55 ) ;
} while ( ! ( V_53 & V_54 ) );
}
static void F_36 ( void T_4 * V_52 )
{
T_1 V_53 ;
F_14 ( ~ V_54 & F_6 ( V_52 + V_55 ) ,
V_52 + V_55 ) ;
do {
V_53 = F_6 ( V_52 + V_55 ) ;
} while ( V_53 & V_54 );
}
void F_37 ( struct V_9 * V_10 )
{
struct V_1 * V_8 = & V_10 -> V_8 ;
T_1 V_12 = V_8 -> V_56 -> V_12 , V_57 = V_8 -> V_56 -> V_57 ;
int V_41 , V_58 ;
F_35 ( V_10 -> V_18 ) ;
F_14 ( 0 , V_8 -> V_59 + V_60 ) ;
F_14 ( 0 , V_8 -> V_59 + V_61 ) ;
F_36 ( V_10 -> V_18 ) ;
F_14 ( V_62 & 0x7 , V_10 -> V_18 + V_63 ) ;
V_58 = ( 1 << ( V_62 & 0x7 ) ) * V_64 ;
for ( V_41 = 0 ; ( V_41 < V_65 ) && ( V_12 < V_57 ) ; V_41 ++ ) {
F_14 ( V_12 | 1 , V_10 -> V_18 + F_38 ( V_41 ) ) ;
F_14 ( 0 , V_10 -> V_18 + F_39 ( V_41 ) ) ;
V_12 += V_58 ;
}
F_14 ( V_66 | F_6 ( V_10 -> V_18 + V_55 ) ,
V_10 -> V_18 + V_55 ) ;
}
static void T_4 * F_40 ( struct V_9 * V_10 , T_5 V_67 ,
unsigned int V_68 )
{
T_5 V_69 = F_41 ( V_68 ) , V_70 = F_42 ( V_68 ) ;
struct V_1 * V_8 = & V_10 -> V_8 ;
T_1 V_71 ;
if ( V_67 == 0 )
return V_8 -> V_59 ;
V_71 = ( V_67 << 16 ) | ( V_69 << 8 ) | V_70 ;
if ( V_67 != 1 )
V_71 |= F_7 ( 24 ) ;
F_14 ( V_71 , V_10 -> V_18 + V_72 ) ;
return V_8 -> V_73 ;
}
int F_43 ( struct V_1 * V_8 , struct V_74 * V_67 ,
unsigned int V_68 , int V_75 , int V_76 , T_1 * V_53 )
{
struct V_9 * V_10 = F_4 ( V_8 ) ;
T_5 V_77 = V_67 -> V_78 ;
void T_4 * V_79 ;
V_79 = F_40 ( V_10 , V_77 , V_68 ) ;
return F_44 ( V_79 + V_75 , V_76 , V_53 ) ;
}
int F_45 ( struct V_1 * V_8 , struct V_74 * V_67 ,
unsigned int V_68 , int V_75 , int V_76 , T_1 V_53 )
{
struct V_9 * V_10 = F_4 ( V_8 ) ;
T_5 V_77 = V_67 -> V_78 ;
void T_4 * V_79 ;
V_79 = F_40 ( V_10 , V_77 , V_68 ) ;
return F_46 ( V_79 + V_75 , V_76 , V_53 ) ;
}
void F_47 ( struct V_1 * V_8 )
{
struct V_9 * V_10 = F_4 ( V_8 ) ;
F_35 ( V_10 -> V_18 ) ;
F_14 ( 1 , V_8 -> V_59 + V_60 ) ;
F_14 ( V_80 - 1 , V_8 -> V_59 + V_60 ) ;
F_36 ( V_10 -> V_18 ) ;
F_14 ( V_10 -> V_11 . V_12 , V_8 -> V_59 + V_60 ) ;
}
int F_48 ( struct V_1 * V_8 )
{
T_1 V_53 = F_6 ( V_8 -> V_59 + V_81 ) ;
return ( V_53 & V_82 ) == V_83 ;
}
void F_49 ( struct V_9 * V_10 )
{
T_1 V_53 ;
V_53 = F_6 ( V_10 -> V_18 + V_55 ) ;
V_53 &= ~ V_84 ;
F_14 ( V_84 | V_53 , V_10 -> V_18 + V_55 ) ;
V_53 = F_6 ( V_10 -> V_18 + V_55 ) ;
F_14 ( V_84 | V_53 , V_10 -> V_18 + V_55 ) ;
}
int T_6 F_50 ( struct V_9 * V_10 ,
struct V_85 * V_42 )
{
struct V_1 * V_8 = & V_10 -> V_8 ;
struct V_86 * V_87 = F_51 ( V_8 -> V_21 ) ;
struct V_88 * V_89 ;
V_89 = F_52 ( V_87 , V_90 , 0 ) ;
V_8 -> V_59 = F_53 ( V_8 -> V_21 , V_89 ) ;
if ( F_54 ( V_8 -> V_59 ) )
return F_55 ( V_8 -> V_59 ) ;
V_8 -> V_73 = V_8 -> V_59 + V_91 ;
V_8 -> V_92 = V_8 -> V_73 ;
V_89 = F_52 ( V_87 , V_90 , 1 ) ;
V_10 -> V_18 = F_53 ( V_8 -> V_21 , V_89 ) ;
if ( F_54 ( V_10 -> V_18 ) )
return F_55 ( V_10 -> V_18 ) ;
V_10 -> V_11 = * V_89 ;
V_10 -> V_49 =
F_26 ( V_10 -> V_93 ,
V_46 ,
& V_94 ,
NULL ) ;
if ( ! V_10 -> V_49 ) {
F_27 ( V_8 -> V_21 , L_4 ) ;
return - V_95 ;
}
return F_56 ( V_8 ) ;
}
