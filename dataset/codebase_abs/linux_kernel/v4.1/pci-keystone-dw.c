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
T_1 F_3 ( struct V_1 * V_8 )
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
unsigned int V_24 = V_23 -> V_24 ;
struct V_25 * V_26 ;
struct V_1 * V_8 ;
V_26 = F_12 ( V_24 ) ;
V_8 = F_1 ( V_26 -> V_21 -> V_27 -> V_28 ) ;
V_10 = F_4 ( V_8 ) ;
V_5 = V_24 - F_8 ( V_8 -> V_20 , 0 ) ;
F_2 ( V_5 , & V_6 , & V_7 ) ;
F_13 ( F_7 ( V_7 ) ,
V_10 -> V_18 + V_19 + ( V_6 << 4 ) ) ;
F_13 ( V_6 + V_29 , V_10 -> V_18 + V_30 ) ;
}
void F_14 ( struct V_1 * V_8 , int V_24 )
{
T_1 V_6 , V_7 ;
struct V_9 * V_10 = F_4 ( V_8 ) ;
F_2 ( V_24 , & V_6 , & V_7 ) ;
F_13 ( F_7 ( V_7 ) ,
V_10 -> V_18 + V_31 + ( V_6 << 4 ) ) ;
}
void F_15 ( struct V_1 * V_8 , int V_24 )
{
T_1 V_6 , V_7 ;
struct V_9 * V_10 = F_4 ( V_8 ) ;
F_2 ( V_24 , & V_6 , & V_7 ) ;
F_13 ( F_7 ( V_7 ) ,
V_10 -> V_18 + V_32 + ( V_6 << 4 ) ) ;
}
static void F_16 ( struct V_22 * V_23 )
{
struct V_9 * V_10 ;
unsigned int V_24 = V_23 -> V_24 ;
struct V_25 * V_26 ;
struct V_1 * V_8 ;
T_1 V_5 ;
V_26 = F_12 ( V_24 ) ;
V_8 = F_1 ( V_26 -> V_21 -> V_27 -> V_28 ) ;
V_10 = F_4 ( V_8 ) ;
V_5 = V_24 - F_8 ( V_8 -> V_20 , 0 ) ;
if ( F_17 ( V_33 ) ) {
if ( V_26 -> V_34 . V_35 )
F_18 ( V_23 ) ;
}
F_15 ( V_8 , V_5 ) ;
}
static void F_19 ( struct V_22 * V_23 )
{
struct V_9 * V_10 ;
unsigned int V_24 = V_23 -> V_24 ;
struct V_25 * V_26 ;
struct V_1 * V_8 ;
T_1 V_5 ;
V_26 = F_12 ( V_24 ) ;
V_8 = F_1 ( V_26 -> V_21 -> V_27 -> V_28 ) ;
V_10 = F_4 ( V_8 ) ;
V_5 = V_24 - F_8 ( V_8 -> V_20 , 0 ) ;
if ( F_17 ( V_33 ) ) {
if ( V_26 -> V_34 . V_35 )
F_20 ( V_23 ) ;
}
F_14 ( V_8 , V_5 ) ;
}
static int F_21 ( struct V_20 * V_36 , unsigned int V_24 ,
T_2 V_37 )
{
F_22 ( V_24 , & V_38 ,
V_39 ) ;
F_23 ( V_24 , V_36 -> V_40 ) ;
F_24 ( V_24 , V_41 ) ;
return 0 ;
}
int F_25 ( struct V_1 * V_8 , struct V_42 * V_43 )
{
struct V_9 * V_10 = F_4 ( V_8 ) ;
int V_44 ;
V_8 -> V_20 = F_26 ( V_10 -> V_45 ,
V_46 ,
& V_47 ,
V_43 ) ;
if ( ! V_8 -> V_20 ) {
F_27 ( V_8 -> V_21 , L_2 ) ;
return - V_48 ;
}
for ( V_44 = 0 ; V_44 < V_46 ; V_44 ++ )
F_28 ( V_8 -> V_20 , V_44 ) ;
return 0 ;
}
void F_29 ( struct V_9 * V_10 )
{
int V_44 ;
for ( V_44 = 0 ; V_44 < V_49 ; V_44 ++ )
F_13 ( 0x1 , V_10 -> V_18 + V_50 + ( V_44 << 4 ) ) ;
}
void F_30 ( struct V_9 * V_10 , int V_5 )
{
struct V_1 * V_8 = & V_10 -> V_8 ;
T_1 V_14 ;
int V_17 ;
V_14 = F_6 ( V_10 -> V_18 + V_51 + ( V_5 << 4 ) ) ;
if ( F_7 ( 0 ) & V_14 ) {
V_17 = F_8 ( V_10 -> V_52 , V_5 ) ;
F_9 ( V_8 -> V_21 , L_3 , V_5 ,
V_17 ) ;
F_10 ( V_17 ) ;
}
F_13 ( V_5 , V_10 -> V_18 + V_30 ) ;
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
unsigned int V_24 , T_2 V_53 )
{
F_22 ( V_24 , & V_54 ,
V_39 ) ;
F_23 ( V_24 , V_23 -> V_40 ) ;
F_24 ( V_24 , V_41 ) ;
return 0 ;
}
static void F_35 ( void T_3 * V_55 )
{
T_1 V_56 ;
F_13 ( V_57 | F_6 ( V_55 + V_58 ) ,
V_55 + V_58 ) ;
do {
V_56 = F_6 ( V_55 + V_58 ) ;
} while ( ! ( V_56 & V_57 ) );
}
static void F_36 ( void T_3 * V_55 )
{
T_1 V_56 ;
F_13 ( ~ V_57 & F_6 ( V_55 + V_58 ) ,
V_55 + V_58 ) ;
do {
V_56 = F_6 ( V_55 + V_58 ) ;
} while ( V_56 & V_57 );
}
void F_37 ( struct V_9 * V_10 )
{
struct V_1 * V_8 = & V_10 -> V_8 ;
T_1 V_12 = V_8 -> V_59 . V_12 , V_60 = V_8 -> V_59 . V_60 ;
int V_44 , V_61 ;
F_35 ( V_10 -> V_18 ) ;
F_13 ( 0 , V_8 -> V_62 + V_63 ) ;
F_13 ( 0 , V_8 -> V_62 + V_64 ) ;
F_36 ( V_10 -> V_18 ) ;
F_13 ( V_65 & 0x7 , V_10 -> V_18 + V_66 ) ;
V_61 = ( 1 << ( V_65 & 0x7 ) ) * V_67 ;
for ( V_44 = 0 ; ( V_44 < V_68 ) && ( V_12 < V_60 ) ; V_44 ++ ) {
F_13 ( V_12 | 1 , V_10 -> V_18 + F_38 ( V_44 ) ) ;
F_13 ( 0 , V_10 -> V_18 + F_39 ( V_44 ) ) ;
V_12 += V_61 ;
}
F_13 ( V_69 | F_6 ( V_10 -> V_18 + V_58 ) ,
V_10 -> V_18 + V_58 ) ;
}
static void T_3 * F_40 ( struct V_9 * V_10 , T_4 V_27 ,
unsigned int V_70 )
{
T_4 V_71 = F_41 ( V_70 ) , V_72 = F_42 ( V_70 ) ;
struct V_1 * V_8 = & V_10 -> V_8 ;
T_1 V_73 ;
if ( V_27 == 0 )
return V_8 -> V_62 ;
V_73 = ( V_27 << 16 ) | ( V_71 << 8 ) | V_72 ;
if ( V_27 != 1 )
V_73 |= F_7 ( 24 ) ;
F_13 ( V_73 , V_10 -> V_18 + V_74 ) ;
return V_8 -> V_75 ;
}
int F_43 ( struct V_1 * V_8 , struct V_76 * V_27 ,
unsigned int V_70 , int V_77 , int V_78 , T_1 * V_56 )
{
struct V_9 * V_10 = F_4 ( V_8 ) ;
T_4 V_79 = V_27 -> V_80 ;
void T_3 * V_81 ;
V_81 = F_40 ( V_10 , V_79 , V_70 ) ;
return F_44 ( V_81 + ( V_77 & ~ 0x3 ) , V_77 , V_78 , V_56 ) ;
}
int F_45 ( struct V_1 * V_8 , struct V_76 * V_27 ,
unsigned int V_70 , int V_77 , int V_78 , T_1 V_56 )
{
struct V_9 * V_10 = F_4 ( V_8 ) ;
T_4 V_79 = V_27 -> V_80 ;
void T_3 * V_81 ;
V_81 = F_40 ( V_10 , V_79 , V_70 ) ;
return F_46 ( V_81 + ( V_77 & ~ 0x3 ) , V_77 , V_78 , V_56 ) ;
}
void F_47 ( struct V_1 * V_8 )
{
struct V_9 * V_10 = F_4 ( V_8 ) ;
F_35 ( V_10 -> V_18 ) ;
F_13 ( 1 , V_8 -> V_62 + V_63 ) ;
F_13 ( V_82 - 1 , V_8 -> V_62 + V_63 ) ;
F_36 ( V_10 -> V_18 ) ;
F_13 ( V_10 -> V_11 . V_12 , V_8 -> V_62 + V_63 ) ;
}
int F_48 ( struct V_1 * V_8 )
{
T_1 V_56 = F_6 ( V_8 -> V_62 + V_83 ) ;
return ( V_56 & V_84 ) == V_85 ;
}
void F_49 ( struct V_9 * V_10 )
{
T_1 V_56 ;
V_56 = F_6 ( V_10 -> V_18 + V_58 ) ;
V_56 &= ~ V_86 ;
F_13 ( V_86 | V_56 , V_10 -> V_18 + V_58 ) ;
V_56 = F_6 ( V_10 -> V_18 + V_58 ) ;
F_13 ( V_86 | V_56 , V_10 -> V_18 + V_58 ) ;
}
int T_5 F_50 ( struct V_9 * V_10 ,
struct V_87 * V_45 )
{
struct V_1 * V_8 = & V_10 -> V_8 ;
struct V_88 * V_89 = F_51 ( V_8 -> V_21 ) ;
struct V_90 * V_91 ;
V_91 = F_52 ( V_89 , V_92 , 0 ) ;
V_8 -> V_62 = F_53 ( V_8 -> V_21 , V_91 ) ;
if ( F_54 ( V_8 -> V_62 ) )
return F_55 ( V_8 -> V_62 ) ;
V_8 -> V_75 = V_8 -> V_62 + V_93 ;
V_8 -> V_94 = V_8 -> V_75 ;
V_91 = F_52 ( V_89 , V_92 , 1 ) ;
V_10 -> V_18 = F_53 ( V_8 -> V_21 , V_91 ) ;
if ( F_54 ( V_10 -> V_18 ) )
return F_55 ( V_10 -> V_18 ) ;
V_10 -> V_11 = * V_91 ;
V_10 -> V_52 =
F_26 ( V_10 -> V_95 ,
V_49 ,
& V_96 ,
NULL ) ;
if ( ! V_10 -> V_52 ) {
F_27 ( V_8 -> V_21 , L_4 ) ;
return - V_97 ;
}
return F_56 ( V_8 ) ;
}
