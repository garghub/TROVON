static inline void F_1 ( T_1 V_1 , T_1 * V_2 ,
T_1 * V_3 )
{
* V_2 = V_1 % 8 ;
* V_3 = V_1 >> 3 ;
}
T_2 F_2 ( struct V_4 * V_5 )
{
struct V_6 * V_7 = F_3 ( V_5 ) ;
return V_7 -> V_8 . V_9 + V_10 ;
}
void F_4 ( struct V_6 * V_7 , int V_1 )
{
struct V_4 * V_5 = & V_7 -> V_5 ;
T_1 V_11 , V_12 ;
int V_13 , V_14 ;
V_11 = F_5 ( V_7 -> V_15 + V_16 + ( V_1 << 4 ) ) ;
for ( V_13 = 0 ; V_13 < 4 ; V_13 ++ ) {
if ( F_6 ( V_13 ) & V_11 ) {
V_12 = V_1 + ( V_13 << 3 ) ;
V_14 = F_7 ( V_5 -> V_17 , V_12 ) ;
F_8 ( V_5 -> V_18 , L_1 ,
V_13 , V_12 , V_14 ) ;
F_9 ( V_14 ) ;
}
}
}
static void F_10 ( struct V_19 * V_20 )
{
T_1 V_1 , V_2 , V_3 ;
struct V_6 * V_7 ;
struct V_21 * V_22 ;
struct V_4 * V_5 ;
V_22 = F_11 ( V_20 ) ;
V_5 = (struct V_4 * ) F_12 ( V_22 ) ;
V_7 = F_3 ( V_5 ) ;
V_1 = V_20 -> V_23 - F_7 ( V_5 -> V_17 , 0 ) ;
F_1 ( V_1 , & V_2 , & V_3 ) ;
F_13 ( F_6 ( V_3 ) ,
V_7 -> V_15 + V_16 + ( V_2 << 4 ) ) ;
F_13 ( V_2 + V_24 , V_7 -> V_15 + V_25 ) ;
}
void F_14 ( struct V_4 * V_5 , int V_23 )
{
T_1 V_2 , V_3 ;
struct V_6 * V_7 = F_3 ( V_5 ) ;
F_1 ( V_23 , & V_2 , & V_3 ) ;
F_13 ( F_6 ( V_3 ) ,
V_7 -> V_15 + V_26 + ( V_2 << 4 ) ) ;
}
void F_15 ( struct V_4 * V_5 , int V_23 )
{
T_1 V_2 , V_3 ;
struct V_6 * V_7 = F_3 ( V_5 ) ;
F_1 ( V_23 , & V_2 , & V_3 ) ;
F_13 ( F_6 ( V_3 ) ,
V_7 -> V_15 + V_27 + ( V_2 << 4 ) ) ;
}
static void F_16 ( struct V_19 * V_20 )
{
struct V_6 * V_7 ;
struct V_21 * V_22 ;
struct V_4 * V_5 ;
T_1 V_1 ;
V_22 = F_11 ( V_20 ) ;
V_5 = (struct V_4 * ) F_12 ( V_22 ) ;
V_7 = F_3 ( V_5 ) ;
V_1 = V_20 -> V_23 - F_7 ( V_5 -> V_17 , 0 ) ;
if ( F_17 ( V_28 ) ) {
if ( V_22 -> V_29 . V_30 )
F_18 ( V_20 ) ;
}
F_15 ( V_5 , V_1 ) ;
}
static void F_19 ( struct V_19 * V_20 )
{
struct V_6 * V_7 ;
struct V_21 * V_22 ;
struct V_4 * V_5 ;
T_1 V_1 ;
V_22 = F_11 ( V_20 ) ;
V_5 = (struct V_4 * ) F_12 ( V_22 ) ;
V_7 = F_3 ( V_5 ) ;
V_1 = V_20 -> V_23 - F_7 ( V_5 -> V_17 , 0 ) ;
if ( F_17 ( V_28 ) ) {
if ( V_22 -> V_29 . V_30 )
F_20 ( V_20 ) ;
}
F_14 ( V_5 , V_1 ) ;
}
static int F_21 ( struct V_17 * V_31 , unsigned int V_23 ,
T_3 V_32 )
{
F_22 ( V_23 , & V_33 ,
V_34 ) ;
F_23 ( V_23 , V_31 -> V_35 ) ;
return 0 ;
}
int F_24 ( struct V_4 * V_5 , struct V_36 * V_37 )
{
struct V_6 * V_7 = F_3 ( V_5 ) ;
int V_38 ;
V_5 -> V_17 = F_25 ( V_7 -> V_39 ,
V_40 ,
& V_41 ,
V_37 ) ;
if ( ! V_5 -> V_17 ) {
F_26 ( V_5 -> V_18 , L_2 ) ;
return - V_42 ;
}
for ( V_38 = 0 ; V_38 < V_40 ; V_38 ++ )
F_27 ( V_5 -> V_17 , V_38 ) ;
return 0 ;
}
void F_28 ( struct V_6 * V_7 )
{
int V_38 ;
for ( V_38 = 0 ; V_38 < V_43 ; V_38 ++ )
F_13 ( 0x1 , V_7 -> V_15 + V_44 + ( V_38 << 4 ) ) ;
}
void F_29 ( struct V_6 * V_7 , int V_1 )
{
struct V_4 * V_5 = & V_7 -> V_5 ;
T_1 V_11 ;
int V_14 ;
V_11 = F_5 ( V_7 -> V_15 + V_45 + ( V_1 << 4 ) ) ;
if ( F_6 ( 0 ) & V_11 ) {
V_14 = F_7 ( V_7 -> V_46 , V_1 ) ;
F_8 ( V_5 -> V_18 , L_3 , V_1 ,
V_14 ) ;
F_9 ( V_14 ) ;
}
F_13 ( V_1 , V_7 -> V_15 + V_25 ) ;
}
static void F_30 ( struct V_19 * V_20 )
{
}
static void F_31 ( struct V_19 * V_20 )
{
}
static void F_32 ( struct V_19 * V_20 )
{
}
static int F_33 ( struct V_17 * V_20 ,
unsigned int V_23 , T_3 V_47 )
{
F_22 ( V_23 , & V_48 ,
V_34 ) ;
F_23 ( V_23 , V_20 -> V_35 ) ;
return 0 ;
}
static void F_34 ( void T_4 * V_49 )
{
T_1 V_50 ;
F_13 ( V_51 | F_5 ( V_49 + V_52 ) ,
V_49 + V_52 ) ;
do {
V_50 = F_5 ( V_49 + V_52 ) ;
} while ( ! ( V_50 & V_51 ) );
}
static void F_35 ( void T_4 * V_49 )
{
T_1 V_50 ;
F_13 ( ~ V_51 & F_5 ( V_49 + V_52 ) ,
V_49 + V_52 ) ;
do {
V_50 = F_5 ( V_49 + V_52 ) ;
} while ( V_50 & V_51 );
}
void F_36 ( struct V_6 * V_7 )
{
struct V_4 * V_5 = & V_7 -> V_5 ;
T_1 V_9 = V_5 -> V_53 -> V_9 , V_54 = V_5 -> V_53 -> V_54 ;
int V_38 , V_55 ;
F_34 ( V_7 -> V_15 ) ;
F_13 ( 0 , V_5 -> V_56 + V_57 ) ;
F_13 ( 0 , V_5 -> V_56 + V_58 ) ;
F_35 ( V_7 -> V_15 ) ;
F_13 ( V_59 & 0x7 , V_7 -> V_15 + V_60 ) ;
V_55 = ( 1 << ( V_59 & 0x7 ) ) * V_61 ;
for ( V_38 = 0 ; ( V_38 < V_62 ) && ( V_9 < V_54 ) ; V_38 ++ ) {
F_13 ( V_9 | 1 , V_7 -> V_15 + F_37 ( V_38 ) ) ;
F_13 ( 0 , V_7 -> V_15 + F_38 ( V_38 ) ) ;
V_9 += V_55 ;
}
F_13 ( V_63 | F_5 ( V_7 -> V_15 + V_52 ) ,
V_7 -> V_15 + V_52 ) ;
}
static void T_4 * F_39 ( struct V_6 * V_7 , T_5 V_64 ,
unsigned int V_65 )
{
T_5 V_66 = F_40 ( V_65 ) , V_67 = F_41 ( V_65 ) ;
struct V_4 * V_5 = & V_7 -> V_5 ;
T_1 V_68 ;
if ( V_64 == 0 )
return V_5 -> V_56 ;
V_68 = ( V_64 << 16 ) | ( V_66 << 8 ) | V_67 ;
if ( V_64 != 1 )
V_68 |= F_6 ( 24 ) ;
F_13 ( V_68 , V_7 -> V_15 + V_69 ) ;
return V_5 -> V_70 ;
}
int F_42 ( struct V_4 * V_5 , struct V_71 * V_64 ,
unsigned int V_65 , int V_72 , int V_73 , T_1 * V_50 )
{
struct V_6 * V_7 = F_3 ( V_5 ) ;
T_5 V_74 = V_64 -> V_75 ;
void T_4 * V_76 ;
V_76 = F_39 ( V_7 , V_74 , V_65 ) ;
return F_43 ( V_76 + V_72 , V_73 , V_50 ) ;
}
int F_44 ( struct V_4 * V_5 , struct V_71 * V_64 ,
unsigned int V_65 , int V_72 , int V_73 , T_1 V_50 )
{
struct V_6 * V_7 = F_3 ( V_5 ) ;
T_5 V_74 = V_64 -> V_75 ;
void T_4 * V_76 ;
V_76 = F_39 ( V_7 , V_74 , V_65 ) ;
return F_45 ( V_76 + V_72 , V_73 , V_50 ) ;
}
void F_46 ( struct V_4 * V_5 )
{
struct V_6 * V_7 = F_3 ( V_5 ) ;
F_34 ( V_7 -> V_15 ) ;
F_13 ( 1 , V_5 -> V_56 + V_57 ) ;
F_13 ( V_77 - 1 , V_5 -> V_56 + V_57 ) ;
F_35 ( V_7 -> V_15 ) ;
F_13 ( V_7 -> V_8 . V_9 , V_5 -> V_56 + V_57 ) ;
}
int F_47 ( struct V_4 * V_5 )
{
T_1 V_50 = F_5 ( V_5 -> V_56 + V_78 ) ;
return ( V_50 & V_79 ) == V_80 ;
}
void F_48 ( struct V_6 * V_7 )
{
T_1 V_50 ;
V_50 = F_5 ( V_7 -> V_15 + V_52 ) ;
V_50 &= ~ V_81 ;
F_13 ( V_81 | V_50 , V_7 -> V_15 + V_52 ) ;
V_50 = F_5 ( V_7 -> V_15 + V_52 ) ;
F_13 ( V_81 | V_50 , V_7 -> V_15 + V_52 ) ;
}
int T_6 F_49 ( struct V_6 * V_7 ,
struct V_82 * V_39 )
{
struct V_4 * V_5 = & V_7 -> V_5 ;
struct V_83 * V_84 = F_50 ( V_5 -> V_18 ) ;
struct V_85 * V_86 ;
V_86 = F_51 ( V_84 , V_87 , 0 ) ;
V_5 -> V_56 = F_52 ( V_5 -> V_18 , V_86 ) ;
if ( F_53 ( V_5 -> V_56 ) )
return F_54 ( V_5 -> V_56 ) ;
V_5 -> V_70 = V_5 -> V_56 + V_88 ;
V_5 -> V_89 = V_5 -> V_70 ;
V_86 = F_51 ( V_84 , V_87 , 1 ) ;
V_7 -> V_15 = F_52 ( V_5 -> V_18 , V_86 ) ;
if ( F_53 ( V_7 -> V_15 ) )
return F_54 ( V_7 -> V_15 ) ;
V_7 -> V_8 = * V_86 ;
V_7 -> V_46 =
F_25 ( V_7 -> V_90 ,
V_43 ,
& V_91 ,
NULL ) ;
if ( ! V_7 -> V_46 ) {
F_26 ( V_5 -> V_18 , L_4 ) ;
return - V_92 ;
}
return F_55 ( V_5 ) ;
}
