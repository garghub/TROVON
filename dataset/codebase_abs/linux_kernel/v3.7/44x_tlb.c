void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_6 ;
int V_7 ;
F_3 ( L_1 , V_2 -> V_8 ) ;
F_3 ( L_2 ,
L_3 , L_4 , L_5 , L_6 , L_7 ) ;
for ( V_7 = 0 ; V_7 < F_4 ( V_4 -> V_9 ) ; V_7 ++ ) {
V_6 = & V_4 -> V_9 [ V_7 ] ;
if ( V_6 -> V_10 & V_11 )
F_3 ( L_8 ,
V_7 , V_6 -> V_12 , V_6 -> V_10 , V_6 -> V_13 ,
V_6 -> V_14 ) ;
}
}
static inline void F_5 ( unsigned int V_15 )
{
asm volatile(
"tlbwe %[index], %[index], 0\n"
:
: [index] "r"(index)
);
}
static inline void F_6 ( unsigned int V_15 ,
struct V_5 * V_6 )
{
asm volatile(
"tlbre %[word0], %[index], 0\n"
"mfspr %[tid], %[sprn_mmucr]\n"
"andi. %[tid], %[tid], 0xff\n"
"tlbre %[word1], %[index], 1\n"
"tlbre %[word2], %[index], 2\n"
: [word0] "=r"(tlbe->word0),
[word1] "=r"(tlbe->word1),
[word2] "=r"(tlbe->word2),
[tid] "=r"(tlbe->tid)
: [index] "r"(index),
[sprn_mmucr] "i"(SPRN_MMUCR)
: "cc"
);
}
static inline void F_7 ( unsigned int V_15 ,
struct V_5 * V_16 )
{
unsigned long V_17 ;
asm volatile(
"mfspr %[tmp], %[sprn_mmucr]\n"
"rlwimi %[tmp], %[tid], 0, 0xff\n"
"mtspr %[sprn_mmucr], %[tmp]\n"
"tlbwe %[word0], %[index], 0\n"
"tlbwe %[word1], %[index], 1\n"
"tlbwe %[word2], %[index], 2\n"
: [tmp] "=&r"(tmp)
: [word0] "r"(stlbe->word0),
[word1] "r"(stlbe->word1),
[word2] "r"(stlbe->word2),
[tid] "r"(stlbe->tid),
[index] "r"(index),
[sprn_mmucr] "i"(SPRN_MMUCR)
);
}
static T_1 F_8 ( T_1 V_18 , int V_19 )
{
V_18 &= V_20 | V_21 ;
if ( ! V_19 ) {
V_18 &= ~ V_22 ;
V_18 |= ( V_18 & V_23 ) << 3 ;
}
V_18 |= V_24 | V_25 | V_26 ;
V_18 |= V_27 ;
return V_18 ;
}
void F_9 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_7 ;
for ( V_7 = 0 ; V_7 <= V_28 ; V_7 ++ ) {
struct V_5 * V_16 = & V_4 -> V_29 [ V_7 ] ;
if ( F_10 ( V_16 ) && F_11 ( V_16 ) )
F_7 ( V_7 , V_16 ) ;
}
}
static void F_12 ( struct V_3 * V_4 ,
unsigned int V_7 )
{
V_4 -> V_30 [ V_7 ] = 1 ;
}
void F_13 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_7 ;
for ( V_7 = 0 ; V_7 <= V_28 ; V_7 ++ ) {
struct V_5 * V_16 = & V_4 -> V_29 [ V_7 ] ;
if ( V_4 -> V_30 [ V_7 ] )
F_6 ( V_7 , V_16 ) ;
if ( F_10 ( V_16 ) && F_11 ( V_16 ) )
F_5 ( V_7 ) ;
}
}
int F_14 ( struct V_1 * V_2 , T_2 V_31 , unsigned int V_32 ,
unsigned int V_33 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_7 ;
for ( V_7 = 0 ; V_7 < F_4 ( V_4 -> V_9 ) ; V_7 ++ ) {
struct V_5 * V_6 = & V_4 -> V_9 [ V_7 ] ;
unsigned int V_12 ;
if ( V_31 < F_15 ( V_6 ) )
continue;
if ( V_31 > F_16 ( V_6 ) )
continue;
V_12 = F_17 ( V_6 ) ;
if ( V_12 && ( V_12 != V_32 ) )
continue;
if ( ! F_10 ( V_6 ) )
continue;
if ( F_11 ( V_6 ) != V_33 )
continue;
return V_7 ;
}
return - 1 ;
}
T_3 F_18 ( struct V_1 * V_2 , unsigned int V_34 ,
T_2 V_31 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_35 = & V_4 -> V_9 [ V_34 ] ;
unsigned int V_36 = F_19 ( V_35 ) - 1 ;
return F_20 ( V_35 ) | ( V_31 & V_36 ) ;
}
int F_21 ( struct V_1 * V_2 , T_2 V_31 )
{
unsigned int V_33 = ! ! ( V_2 -> V_37 . V_38 -> V_39 & V_40 ) ;
return F_14 ( V_2 , V_31 , V_2 -> V_37 . V_32 , V_33 ) ;
}
int F_22 ( struct V_1 * V_2 , T_2 V_31 )
{
unsigned int V_33 = ! ! ( V_2 -> V_37 . V_38 -> V_39 & V_41 ) ;
return F_14 ( V_2 , V_31 , V_2 -> V_37 . V_32 , V_33 ) ;
}
void F_23 ( struct V_1 * V_2 )
{
}
void F_24 ( struct V_1 * V_2 )
{
}
static void F_25 ( struct V_3 * V_4 ,
unsigned int V_42 )
{
struct V_43 * V_44 = & V_4 -> V_45 [ V_42 ] ;
if ( ! V_44 -> V_46 )
return;
F_5 ( V_42 ) ;
if ( V_44 -> V_47 )
F_26 ( V_44 -> V_46 ) ;
else
F_27 ( V_44 -> V_46 ) ;
V_44 -> V_46 = NULL ;
F_28 ( V_42 ) ;
}
void F_29 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_7 ;
for ( V_7 = 0 ; V_7 <= V_28 ; V_7 ++ )
F_25 ( V_4 , V_7 ) ;
}
void F_30 ( struct V_1 * V_2 , T_4 V_48 , T_3 V_49 ,
unsigned int V_34 )
{
struct V_5 V_16 ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_35 = & V_4 -> V_9 [ V_34 ] ;
struct V_43 * V_44 ;
struct V_46 * V_50 ;
T_5 V_51 ;
T_6 V_52 ;
T_1 V_53 = V_35 -> V_12 ;
T_1 V_54 = V_35 -> V_14 ;
T_1 V_55 = F_19 ( V_35 ) ;
unsigned int V_56 ;
F_31 () ;
V_56 = ++ V_57 ;
if ( V_56 > V_28 )
V_56 = 0 ;
V_57 = V_56 ;
F_32 () ;
V_52 = V_49 >> V_58 ;
V_50 = F_33 ( V_2 -> V_59 , V_52 ) ;
if ( F_34 ( V_50 ) ) {
F_3 ( V_60 L_9 ,
( unsigned long long ) V_52 ) ;
return;
}
V_51 = F_35 ( V_50 ) ;
F_25 ( V_4 , V_56 ) ;
V_16 . V_10 = V_11 | V_61 ;
if ( V_55 >= V_62 ) {
V_16 . V_10 |= ( V_48 & V_63 ) | V_64 ;
} else {
V_16 . V_10 |= ( V_48 & V_65 ) | V_66 ;
V_51 |= V_49 & ( V_63 ^ V_65 ) ;
}
V_16 . V_13 = ( V_51 & 0xfffffc00 ) | ( ( V_51 >> 32 ) & 0xf ) ;
V_16 . V_14 = F_8 ( V_54 ,
V_2 -> V_37 . V_38 -> V_39 & V_67 ) ;
V_16 . V_12 = ! ( V_53 & 0xff ) ;
V_44 = & V_4 -> V_45 [ V_56 ] ;
V_44 -> V_46 = V_50 ;
V_44 -> V_34 = V_34 ;
V_44 -> V_47 = ! ! ( V_16 . V_14 & V_68 ) ;
V_44 -> V_12 = V_16 . V_12 ;
F_12 ( V_4 , V_56 ) ;
F_7 ( V_56 , & V_16 ) ;
F_36 ( V_56 , V_16 . V_12 , V_16 . V_10 , V_16 . V_13 ,
V_16 . V_14 ) ;
}
static void F_37 ( struct V_1 * V_2 ,
unsigned int V_34 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_7 ;
for ( V_7 = 0 ; V_7 < F_4 ( V_4 -> V_45 ) ; V_7 ++ ) {
struct V_43 * V_44 = & V_4 -> V_45 [ V_7 ] ;
if ( V_44 -> V_34 == V_34 )
F_25 ( V_4 , V_7 ) ;
}
}
void F_38 ( struct V_1 * V_2 , T_1 V_69 )
{
int V_19 = V_2 -> V_37 . V_38 -> V_39 & V_67 ;
V_2 -> V_37 . V_70 = ! V_19 ;
}
void F_39 ( struct V_1 * V_2 , T_1 V_71 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_7 ;
if ( F_40 ( V_2 -> V_37 . V_32 == V_71 ) )
return;
V_2 -> V_37 . V_32 = V_71 ;
for ( V_7 = 0 ; V_7 < F_4 ( V_4 -> V_45 ) ; V_7 ++ ) {
struct V_43 * V_44 = & V_4 -> V_45 [ V_7 ] ;
if ( V_44 -> V_12 == 0 )
F_25 ( V_4 , V_7 ) ;
}
}
static int F_41 ( const struct V_1 * V_2 ,
const struct V_5 * V_6 )
{
T_3 V_72 ;
if ( ! F_10 ( V_6 ) )
return 0 ;
if ( F_11 ( V_6 ) != ! ! ( V_2 -> V_37 . V_38 -> V_39 & V_40 ) )
return 0 ;
V_72 = F_20 ( V_6 ) ;
if ( ! F_42 ( V_2 -> V_59 , V_72 >> V_58 ) )
return 0 ;
return 1 ;
}
int F_43 ( struct V_1 * V_2 , T_7 V_73 , T_7 V_74 , T_7 V_75 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_6 ;
unsigned int V_34 ;
V_34 = F_44 ( V_2 , V_73 ) ;
if ( V_34 >= V_76 ) {
F_3 ( L_10 , V_77 , V_34 ) ;
F_45 ( V_2 ) ;
return V_78 ;
}
V_6 = & V_4 -> V_9 [ V_34 ] ;
if ( V_6 -> V_10 & V_11 )
F_37 ( V_2 , V_34 ) ;
switch ( V_75 ) {
case V_79 :
V_6 -> V_12 = F_46 ( V_2 ) ;
V_6 -> V_10 = F_44 ( V_2 , V_74 ) ;
break;
case V_80 :
V_6 -> V_13 = F_44 ( V_2 , V_74 ) ;
break;
case V_81 :
V_6 -> V_14 = F_44 ( V_2 , V_74 ) ;
break;
default:
return V_78 ;
}
if ( F_41 ( V_2 , V_6 ) ) {
T_2 V_31 ;
T_3 V_49 ;
T_1 V_82 ;
V_31 = F_15 ( V_6 ) ;
V_49 = F_20 ( V_6 ) ;
V_82 = F_19 ( V_6 ) ;
V_31 &= ~ ( V_82 - 1 ) ;
V_49 &= ~ ( V_82 - 1 ) ;
F_30 ( V_2 , V_31 , V_49 , V_34 ) ;
}
F_47 ( V_34 , V_6 -> V_12 , V_6 -> V_10 , V_6 -> V_13 ,
V_6 -> V_14 ) ;
F_48 ( V_2 , V_83 ) ;
return V_84 ;
}
int F_49 ( struct V_1 * V_2 , T_7 V_85 , T_7 V_73 , T_7 V_86 , T_7 V_87 )
{
T_1 V_88 ;
int V_34 ;
unsigned int V_33 = F_50 ( V_2 ) ;
unsigned int V_32 = F_46 ( V_2 ) ;
V_88 = F_44 ( V_2 , V_86 ) ;
if ( V_73 )
V_88 += F_44 ( V_2 , V_73 ) ;
V_34 = F_14 ( V_2 , V_88 , V_32 , V_33 ) ;
if ( V_87 ) {
T_1 V_89 = F_51 ( V_2 ) ;
if ( V_34 < 0 )
F_52 ( V_2 , V_89 & ~ 0x20000000 ) ;
else
F_52 ( V_2 , V_89 | 0x20000000 ) ;
}
F_53 ( V_2 , V_85 , V_34 ) ;
F_48 ( V_2 , V_90 ) ;
return V_84 ;
}
