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
static T_1 F_4 ( struct V_6 * V_7 , T_1 V_1 )
{
return F_5 ( V_7 -> V_11 + V_1 ) ;
}
static void F_6 ( struct V_6 * V_7 , T_1 V_1 , T_1 V_12 )
{
F_7 ( V_12 , V_7 -> V_11 + V_1 ) ;
}
void F_8 ( struct V_6 * V_7 , int V_1 )
{
struct V_4 * V_5 = & V_7 -> V_5 ;
struct V_13 * V_14 = V_5 -> V_14 ;
T_1 V_15 , V_16 ;
int V_17 , V_18 ;
V_15 = F_4 ( V_7 , V_19 + ( V_1 << 4 ) ) ;
for ( V_17 = 0 ; V_17 < 4 ; V_17 ++ ) {
if ( F_9 ( V_17 ) & V_15 ) {
V_16 = V_1 + ( V_17 << 3 ) ;
V_18 = F_10 ( V_5 -> V_20 , V_16 ) ;
F_11 ( V_14 , L_1 ,
V_17 , V_16 , V_18 ) ;
F_12 ( V_18 ) ;
}
}
}
static void F_13 ( struct V_21 * V_22 )
{
T_1 V_1 , V_2 , V_3 ;
struct V_6 * V_7 ;
struct V_23 * V_24 ;
struct V_4 * V_5 ;
V_24 = F_14 ( V_22 ) ;
V_5 = (struct V_4 * ) F_15 ( V_24 ) ;
V_7 = F_3 ( V_5 ) ;
V_1 = V_22 -> V_25 - F_10 ( V_5 -> V_20 , 0 ) ;
F_1 ( V_1 , & V_2 , & V_3 ) ;
F_6 ( V_7 , V_19 + ( V_2 << 4 ) ,
F_9 ( V_3 ) ) ;
F_6 ( V_7 , V_26 , V_2 + V_27 ) ;
}
void F_16 ( struct V_4 * V_5 , int V_25 )
{
T_1 V_2 , V_3 ;
struct V_6 * V_7 = F_3 ( V_5 ) ;
F_1 ( V_25 , & V_2 , & V_3 ) ;
F_6 ( V_7 , V_28 + ( V_2 << 4 ) ,
F_9 ( V_3 ) ) ;
}
void F_17 ( struct V_4 * V_5 , int V_25 )
{
T_1 V_2 , V_3 ;
struct V_6 * V_7 = F_3 ( V_5 ) ;
F_1 ( V_25 , & V_2 , & V_3 ) ;
F_6 ( V_7 , V_29 + ( V_2 << 4 ) ,
F_9 ( V_3 ) ) ;
}
static void F_18 ( struct V_21 * V_22 )
{
struct V_6 * V_7 ;
struct V_23 * V_24 ;
struct V_4 * V_5 ;
T_1 V_1 ;
V_24 = F_14 ( V_22 ) ;
V_5 = (struct V_4 * ) F_15 ( V_24 ) ;
V_7 = F_3 ( V_5 ) ;
V_1 = V_22 -> V_25 - F_10 ( V_5 -> V_20 , 0 ) ;
if ( F_19 ( V_30 ) ) {
if ( V_24 -> V_31 . V_32 )
F_20 ( V_22 ) ;
}
F_17 ( V_5 , V_1 ) ;
}
static void F_21 ( struct V_21 * V_22 )
{
struct V_6 * V_7 ;
struct V_23 * V_24 ;
struct V_4 * V_5 ;
T_1 V_1 ;
V_24 = F_14 ( V_22 ) ;
V_5 = (struct V_4 * ) F_15 ( V_24 ) ;
V_7 = F_3 ( V_5 ) ;
V_1 = V_22 -> V_25 - F_10 ( V_5 -> V_20 , 0 ) ;
if ( F_19 ( V_30 ) ) {
if ( V_24 -> V_31 . V_32 )
F_22 ( V_22 ) ;
}
F_16 ( V_5 , V_1 ) ;
}
static int F_23 ( struct V_20 * V_33 , unsigned int V_25 ,
T_3 V_34 )
{
F_24 ( V_25 , & V_35 ,
V_36 ) ;
F_25 ( V_25 , V_33 -> V_37 ) ;
return 0 ;
}
int F_26 ( struct V_4 * V_5 , struct V_38 * V_39 )
{
struct V_6 * V_7 = F_3 ( V_5 ) ;
struct V_13 * V_14 = V_5 -> V_14 ;
int V_40 ;
V_5 -> V_20 = F_27 ( V_7 -> V_41 ,
V_42 ,
& V_43 ,
V_39 ) ;
if ( ! V_5 -> V_20 ) {
F_28 ( V_14 , L_2 ) ;
return - V_44 ;
}
for ( V_40 = 0 ; V_40 < V_42 ; V_40 ++ )
F_29 ( V_5 -> V_20 , V_40 ) ;
return 0 ;
}
void F_30 ( struct V_6 * V_7 )
{
int V_40 ;
for ( V_40 = 0 ; V_40 < V_45 ; V_40 ++ )
F_6 ( V_7 , V_46 + ( V_40 << 4 ) , 0x1 ) ;
}
void F_31 ( struct V_6 * V_7 , int V_1 )
{
struct V_4 * V_5 = & V_7 -> V_5 ;
struct V_13 * V_14 = V_5 -> V_14 ;
T_1 V_15 ;
int V_18 ;
V_15 = F_4 ( V_7 , V_47 + ( V_1 << 4 ) ) ;
if ( F_9 ( 0 ) & V_15 ) {
V_18 = F_10 ( V_7 -> V_48 , V_1 ) ;
F_11 ( V_14 , L_3 , V_1 , V_18 ) ;
F_12 ( V_18 ) ;
}
F_6 ( V_7 , V_26 , V_1 ) ;
}
void F_32 ( struct V_6 * V_7 )
{
F_6 ( V_7 , V_49 , V_50 ) ;
}
T_4 F_33 ( struct V_6 * V_7 )
{
T_1 V_51 ;
V_51 = F_4 ( V_7 , V_52 ) & V_50 ;
if ( ! V_51 )
return V_53 ;
if ( V_51 & V_54 )
F_28 ( V_7 -> V_5 . V_14 , L_4 ,
V_51 ) ;
F_6 ( V_7 , V_55 , V_51 ) ;
return V_56 ;
}
static void F_34 ( struct V_21 * V_22 )
{
}
static void F_35 ( struct V_21 * V_22 )
{
}
static void F_36 ( struct V_21 * V_22 )
{
}
static int F_37 ( struct V_20 * V_22 ,
unsigned int V_25 , T_3 V_57 )
{
F_24 ( V_25 , & V_58 ,
V_36 ) ;
F_25 ( V_25 , V_22 -> V_37 ) ;
return 0 ;
}
static void F_38 ( struct V_6 * V_7 )
{
T_1 V_12 ;
V_12 = F_4 ( V_7 , V_59 ) ;
F_6 ( V_7 , V_59 , V_60 | V_12 ) ;
do {
V_12 = F_4 ( V_7 , V_59 ) ;
} while ( ! ( V_12 & V_60 ) );
}
static void F_39 ( struct V_6 * V_7 )
{
T_1 V_12 ;
V_12 = F_4 ( V_7 , V_59 ) ;
F_6 ( V_7 , V_59 , ~ V_60 & V_12 ) ;
do {
V_12 = F_4 ( V_7 , V_59 ) ;
} while ( V_12 & V_60 );
}
void F_40 ( struct V_6 * V_7 )
{
struct V_4 * V_5 = & V_7 -> V_5 ;
T_1 V_9 = V_5 -> V_61 -> V_9 , V_62 = V_5 -> V_61 -> V_62 ;
int V_40 , V_63 ;
T_1 V_12 ;
F_38 ( V_7 ) ;
F_41 ( V_5 , V_64 , 0 ) ;
F_41 ( V_5 , V_65 , 0 ) ;
F_39 ( V_7 ) ;
F_6 ( V_7 , V_66 , V_67 & 0x7 ) ;
V_63 = ( 1 << ( V_67 & 0x7 ) ) * V_68 ;
for ( V_40 = 0 ; ( V_40 < V_69 ) && ( V_9 < V_62 ) ; V_40 ++ ) {
F_6 ( V_7 , F_42 ( V_40 ) , V_9 | 1 ) ;
F_6 ( V_7 , F_43 ( V_40 ) , 0 ) ;
V_9 += V_63 ;
}
V_12 = F_4 ( V_7 , V_59 ) ;
F_6 ( V_7 , V_59 , V_70 | V_12 ) ;
}
static void T_5 * F_44 ( struct V_6 * V_7 , T_6 V_71 ,
unsigned int V_72 )
{
T_6 V_13 = F_45 ( V_72 ) , V_73 = F_46 ( V_72 ) ;
struct V_4 * V_5 = & V_7 -> V_5 ;
T_1 V_74 ;
if ( V_71 == 0 )
return V_5 -> V_75 ;
V_74 = ( V_71 << 16 ) | ( V_13 << 8 ) | V_73 ;
if ( V_71 != 1 )
V_74 |= F_9 ( 24 ) ;
F_6 ( V_7 , V_76 , V_74 ) ;
return V_5 -> V_77 ;
}
int F_47 ( struct V_4 * V_5 , struct V_78 * V_71 ,
unsigned int V_72 , int V_79 , int V_80 , T_1 * V_12 )
{
struct V_6 * V_7 = F_3 ( V_5 ) ;
T_6 V_81 = V_71 -> V_82 ;
void T_5 * V_83 ;
V_83 = F_44 ( V_7 , V_81 , V_72 ) ;
return F_48 ( V_83 + V_79 , V_80 , V_12 ) ;
}
int F_49 ( struct V_4 * V_5 , struct V_78 * V_71 ,
unsigned int V_72 , int V_79 , int V_80 , T_1 V_12 )
{
struct V_6 * V_7 = F_3 ( V_5 ) ;
T_6 V_81 = V_71 -> V_82 ;
void T_5 * V_83 ;
V_83 = F_44 ( V_7 , V_81 , V_72 ) ;
return F_50 ( V_83 + V_79 , V_80 , V_12 ) ;
}
void F_51 ( struct V_4 * V_5 )
{
struct V_6 * V_7 = F_3 ( V_5 ) ;
F_38 ( V_7 ) ;
F_41 ( V_5 , V_64 , 1 ) ;
F_41 ( V_5 , V_64 , V_84 - 1 ) ;
F_39 ( V_7 ) ;
F_41 ( V_5 , V_64 , V_7 -> V_8 . V_9 ) ;
}
int F_52 ( struct V_4 * V_5 )
{
T_1 V_12 ;
V_12 = F_53 ( V_5 , V_85 ) ;
return ( V_12 & V_86 ) == V_87 ;
}
void F_54 ( struct V_6 * V_7 )
{
T_1 V_12 ;
V_12 = F_4 ( V_7 , V_59 ) ;
V_12 &= ~ V_88 ;
F_6 ( V_7 , V_59 , V_88 | V_12 ) ;
V_12 = F_4 ( V_7 , V_59 ) ;
F_6 ( V_7 , V_59 , V_88 | V_12 ) ;
}
int T_7 F_55 ( struct V_6 * V_7 ,
struct V_89 * V_41 )
{
struct V_4 * V_5 = & V_7 -> V_5 ;
struct V_13 * V_14 = V_5 -> V_14 ;
struct V_90 * V_91 = F_56 ( V_14 ) ;
struct V_92 * V_93 ;
V_93 = F_57 ( V_91 , V_94 , 0 ) ;
V_5 -> V_75 = F_58 ( V_14 , V_93 ) ;
if ( F_59 ( V_5 -> V_75 ) )
return F_60 ( V_5 -> V_75 ) ;
V_5 -> V_77 = V_5 -> V_75 + V_95 ;
V_5 -> V_96 = V_5 -> V_77 ;
V_93 = F_57 ( V_91 , V_94 , 1 ) ;
V_7 -> V_11 = F_58 ( V_14 , V_93 ) ;
if ( F_59 ( V_7 -> V_11 ) )
return F_60 ( V_7 -> V_11 ) ;
V_7 -> V_8 = * V_93 ;
V_7 -> V_48 =
F_27 ( V_7 -> V_97 ,
V_45 ,
& V_98 ,
NULL ) ;
if ( ! V_7 -> V_48 ) {
F_28 ( V_14 , L_5 ) ;
return - V_99 ;
}
return F_61 ( V_5 ) ;
}
