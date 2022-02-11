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
void F_30 ( void T_4 * V_47 )
{
F_13 ( V_48 , V_47 + V_49 ) ;
}
T_5 F_31 ( struct V_50 * V_18 ,
void T_4 * V_47 )
{
T_1 V_51 ;
V_51 = F_5 ( V_47 + V_52 ) & V_48 ;
if ( ! V_51 )
return V_53 ;
if ( V_51 & V_54 )
F_26 ( V_18 , L_4 , V_51 ) ;
F_13 ( V_51 , V_47 + V_55 ) ;
return V_56 ;
}
static void F_32 ( struct V_19 * V_20 )
{
}
static void F_33 ( struct V_19 * V_20 )
{
}
static void F_34 ( struct V_19 * V_20 )
{
}
static int F_35 ( struct V_17 * V_20 ,
unsigned int V_23 , T_3 V_57 )
{
F_22 ( V_23 , & V_58 ,
V_34 ) ;
F_23 ( V_23 , V_20 -> V_35 ) ;
return 0 ;
}
static void F_36 ( void T_4 * V_59 )
{
T_1 V_60 ;
F_13 ( V_61 | F_5 ( V_59 + V_62 ) ,
V_59 + V_62 ) ;
do {
V_60 = F_5 ( V_59 + V_62 ) ;
} while ( ! ( V_60 & V_61 ) );
}
static void F_37 ( void T_4 * V_59 )
{
T_1 V_60 ;
F_13 ( ~ V_61 & F_5 ( V_59 + V_62 ) ,
V_59 + V_62 ) ;
do {
V_60 = F_5 ( V_59 + V_62 ) ;
} while ( V_60 & V_61 );
}
void F_38 ( struct V_6 * V_7 )
{
struct V_4 * V_5 = & V_7 -> V_5 ;
T_1 V_9 = V_5 -> V_63 -> V_9 , V_64 = V_5 -> V_63 -> V_64 ;
int V_38 , V_65 ;
F_36 ( V_7 -> V_15 ) ;
F_13 ( 0 , V_5 -> V_66 + V_67 ) ;
F_13 ( 0 , V_5 -> V_66 + V_68 ) ;
F_37 ( V_7 -> V_15 ) ;
F_13 ( V_69 & 0x7 , V_7 -> V_15 + V_70 ) ;
V_65 = ( 1 << ( V_69 & 0x7 ) ) * V_71 ;
for ( V_38 = 0 ; ( V_38 < V_72 ) && ( V_9 < V_64 ) ; V_38 ++ ) {
F_13 ( V_9 | 1 , V_7 -> V_15 + F_39 ( V_38 ) ) ;
F_13 ( 0 , V_7 -> V_15 + F_40 ( V_38 ) ) ;
V_9 += V_65 ;
}
F_13 ( V_73 | F_5 ( V_7 -> V_15 + V_62 ) ,
V_7 -> V_15 + V_62 ) ;
}
static void T_4 * F_41 ( struct V_6 * V_7 , T_6 V_74 ,
unsigned int V_75 )
{
T_6 V_50 = F_42 ( V_75 ) , V_76 = F_43 ( V_75 ) ;
struct V_4 * V_5 = & V_7 -> V_5 ;
T_1 V_77 ;
if ( V_74 == 0 )
return V_5 -> V_66 ;
V_77 = ( V_74 << 16 ) | ( V_50 << 8 ) | V_76 ;
if ( V_74 != 1 )
V_77 |= F_6 ( 24 ) ;
F_13 ( V_77 , V_7 -> V_15 + V_78 ) ;
return V_5 -> V_79 ;
}
int F_44 ( struct V_4 * V_5 , struct V_80 * V_74 ,
unsigned int V_75 , int V_81 , int V_82 , T_1 * V_60 )
{
struct V_6 * V_7 = F_3 ( V_5 ) ;
T_6 V_83 = V_74 -> V_84 ;
void T_4 * V_85 ;
V_85 = F_41 ( V_7 , V_83 , V_75 ) ;
return F_45 ( V_85 + V_81 , V_82 , V_60 ) ;
}
int F_46 ( struct V_4 * V_5 , struct V_80 * V_74 ,
unsigned int V_75 , int V_81 , int V_82 , T_1 V_60 )
{
struct V_6 * V_7 = F_3 ( V_5 ) ;
T_6 V_83 = V_74 -> V_84 ;
void T_4 * V_85 ;
V_85 = F_41 ( V_7 , V_83 , V_75 ) ;
return F_47 ( V_85 + V_81 , V_82 , V_60 ) ;
}
void F_48 ( struct V_4 * V_5 )
{
struct V_6 * V_7 = F_3 ( V_5 ) ;
F_36 ( V_7 -> V_15 ) ;
F_13 ( 1 , V_5 -> V_66 + V_67 ) ;
F_13 ( V_86 - 1 , V_5 -> V_66 + V_67 ) ;
F_37 ( V_7 -> V_15 ) ;
F_13 ( V_7 -> V_8 . V_9 , V_5 -> V_66 + V_67 ) ;
}
int F_49 ( struct V_4 * V_5 )
{
T_1 V_60 = F_5 ( V_5 -> V_66 + V_87 ) ;
return ( V_60 & V_88 ) == V_89 ;
}
void F_50 ( struct V_6 * V_7 )
{
T_1 V_60 ;
V_60 = F_5 ( V_7 -> V_15 + V_62 ) ;
V_60 &= ~ V_90 ;
F_13 ( V_90 | V_60 , V_7 -> V_15 + V_62 ) ;
V_60 = F_5 ( V_7 -> V_15 + V_62 ) ;
F_13 ( V_90 | V_60 , V_7 -> V_15 + V_62 ) ;
}
int T_7 F_51 ( struct V_6 * V_7 ,
struct V_91 * V_39 )
{
struct V_4 * V_5 = & V_7 -> V_5 ;
struct V_92 * V_93 = F_52 ( V_5 -> V_18 ) ;
struct V_94 * V_95 ;
V_95 = F_53 ( V_93 , V_96 , 0 ) ;
V_5 -> V_66 = F_54 ( V_5 -> V_18 , V_95 ) ;
if ( F_55 ( V_5 -> V_66 ) )
return F_56 ( V_5 -> V_66 ) ;
V_5 -> V_79 = V_5 -> V_66 + V_97 ;
V_5 -> V_98 = V_5 -> V_79 ;
V_95 = F_53 ( V_93 , V_96 , 1 ) ;
V_7 -> V_15 = F_54 ( V_5 -> V_18 , V_95 ) ;
if ( F_55 ( V_7 -> V_15 ) )
return F_56 ( V_7 -> V_15 ) ;
V_7 -> V_8 = * V_95 ;
V_7 -> V_46 =
F_25 ( V_7 -> V_99 ,
V_43 ,
& V_100 ,
NULL ) ;
if ( ! V_7 -> V_46 ) {
F_26 ( V_5 -> V_18 , L_5 ) ;
return - V_101 ;
}
return F_57 ( V_5 ) ;
}
