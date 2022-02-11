void F_1 ( struct V_1 * V_2 , T_1 * V_3 )
{
V_2 -> T_1 = V_3 ;
}
void F_2 ( struct V_1 * V_2 , T_2 * V_4 )
{
V_2 -> T_2 = V_4 ;
}
void F_3 ( struct V_1 * V_2 , T_3 * V_5 )
{
V_2 -> T_3 = V_5 ;
}
void F_4 ( struct V_1 * V_2 , T_4 * V_6 )
{
V_2 -> T_4 = V_6 ;
}
void F_5 ( struct V_1 * V_2 , unsigned int V_7 )
{
V_2 -> V_8 = V_7 ;
}
void F_6 ( struct V_1 * V_2 , T_5 * V_6 )
{
V_2 -> T_5 = V_6 ;
}
void F_7 ( struct V_1 * V_2 , T_6 * V_6 )
{
V_2 -> T_6 = V_6 ;
}
void F_8 ( struct V_9 * V_10 )
{
V_10 -> V_11 = V_12 ;
V_10 -> V_13 = 0 ;
V_10 -> V_14 = V_15 ;
V_10 -> V_16 = V_17 ;
V_10 -> V_18 = V_10 -> V_19 = V_20 ;
V_10 -> V_21 = 0 ;
V_10 -> V_22 = 0 ;
V_10 -> V_23 = 0 ;
V_10 -> V_24 = 0 ;
V_10 -> V_25 = 0 ;
V_10 -> V_26 = V_10 -> V_27 = V_10 -> V_28 = 512 ;
V_10 -> V_29 = ( unsigned long ) ( V_30 >> V_31 ) ;
V_10 -> V_32 = 0 ;
V_10 -> V_33 = 0 ;
V_10 -> V_34 = 0 ;
V_10 -> V_35 = 1 ;
}
void F_9 ( struct V_9 * V_10 )
{
F_8 ( V_10 ) ;
V_10 -> V_25 = 1 ;
V_10 -> V_11 = V_36 ;
V_10 -> V_19 = V_37 ;
V_10 -> V_18 = V_38 ;
}
void F_10 ( struct V_1 * V_2 , T_7 * V_39 )
{
V_2 -> V_40 = V_41 ;
V_2 -> T_7 = V_39 ;
F_11 ( V_2 , 511 ) ;
F_12 ( V_2 ) ;
V_2 -> V_42 = V_43 ;
F_8 ( & V_2 -> V_44 ) ;
F_13 ( V_2 , V_45 ) ;
}
void F_13 ( struct V_1 * V_2 , T_8 V_46 )
{
unsigned long V_47 = V_46 >> V_31 ;
int V_48 = 0 ;
V_2 -> V_49 = V_50 ;
#if V_51 == 64
if ( V_47 < ( F_14 ( T_8 , 0xffffffffUL , V_45 ) >> V_31 ) )
V_48 = 1 ;
V_2 -> V_44 . V_29 = F_15 ( V_52 , V_47 ) ;
#else
if ( V_47 < V_53 )
V_48 = 1 ;
V_2 -> V_44 . V_29 = V_47 ;
#endif
if ( V_48 ) {
F_16 () ;
V_2 -> V_49 = V_50 | V_54 ;
V_2 -> V_44 . V_29 = V_47 ;
}
}
void F_17 ( struct V_9 * V_44 , unsigned int V_19 )
{
if ( ( V_19 << 9 ) < V_55 ) {
V_19 = 1 << ( V_56 - 9 ) ;
F_18 ( V_57 L_1 ,
V_58 , V_19 ) ;
}
V_44 -> V_19 = V_19 ;
V_44 -> V_18 = F_14 (unsigned int, max_hw_sectors,
BLK_DEF_MAX_SECTORS) ;
}
void F_19 ( struct V_1 * V_2 , unsigned int V_19 )
{
F_17 ( & V_2 -> V_44 , V_19 ) ;
}
void F_20 ( struct V_1 * V_2 ,
unsigned int V_21 )
{
V_2 -> V_44 . V_21 = V_21 ;
}
void F_21 ( struct V_1 * V_2 , unsigned short V_11 )
{
if ( ! V_11 ) {
V_11 = 1 ;
F_18 ( V_57 L_1 ,
V_58 , V_11 ) ;
}
V_2 -> V_44 . V_11 = V_11 ;
}
void F_22 ( struct V_1 * V_2 , unsigned int V_59 )
{
if ( V_59 < V_55 ) {
V_59 = V_55 ;
F_18 ( V_57 L_1 ,
V_58 , V_59 ) ;
}
V_2 -> V_44 . V_16 = V_59 ;
}
void F_23 ( struct V_1 * V_2 , unsigned short V_60 )
{
V_2 -> V_44 . V_26 = V_60 ;
if ( V_2 -> V_44 . V_27 < V_60 )
V_2 -> V_44 . V_27 = V_60 ;
if ( V_2 -> V_44 . V_28 < V_2 -> V_44 . V_27 )
V_2 -> V_44 . V_28 = V_2 -> V_44 . V_27 ;
}
void F_24 ( struct V_1 * V_2 , unsigned int V_60 )
{
V_2 -> V_44 . V_27 = V_60 ;
if ( V_2 -> V_44 . V_27 < V_2 -> V_44 . V_26 )
V_2 -> V_44 . V_27 = V_2 -> V_44 . V_26 ;
if ( V_2 -> V_44 . V_28 < V_2 -> V_44 . V_27 )
V_2 -> V_44 . V_28 = V_2 -> V_44 . V_27 ;
}
void F_25 ( struct V_1 * V_2 , unsigned int V_61 )
{
V_2 -> V_44 . V_32 =
V_61 & ( V_2 -> V_44 . V_27 - 1 ) ;
V_2 -> V_44 . V_34 = 0 ;
}
void F_26 ( struct V_9 * V_44 , unsigned int V_62 )
{
V_44 -> V_28 = V_62 ;
if ( V_44 -> V_28 < V_44 -> V_26 )
V_44 -> V_28 = V_44 -> V_26 ;
if ( V_44 -> V_28 < V_44 -> V_27 )
V_44 -> V_28 = V_44 -> V_27 ;
}
void F_27 ( struct V_1 * V_2 , unsigned int V_62 )
{
F_26 ( & V_2 -> V_44 , V_62 ) ;
}
void F_28 ( struct V_9 * V_44 , unsigned int V_63 )
{
V_44 -> V_33 = V_63 ;
}
void F_29 ( struct V_1 * V_2 , unsigned int V_63 )
{
F_28 ( & V_2 -> V_44 , V_63 ) ;
}
void F_30 ( struct V_1 * V_64 , struct V_1 * V_65 )
{
F_31 ( & V_64 -> V_44 , & V_65 -> V_44 , 0 ) ;
}
int F_31 ( struct V_9 * V_64 , struct V_9 * V_65 ,
T_9 V_66 )
{
unsigned int V_67 , V_68 , V_69 , V_70 = 0 ;
V_64 -> V_18 = F_32 ( V_64 -> V_18 , V_65 -> V_18 ) ;
V_64 -> V_19 = F_32 ( V_64 -> V_19 , V_65 -> V_19 ) ;
V_64 -> V_29 = F_32 ( V_64 -> V_29 , V_65 -> V_29 ) ;
V_64 -> V_14 = F_32 ( V_64 -> V_14 ,
V_65 -> V_14 ) ;
V_64 -> V_11 = F_32 ( V_64 -> V_11 , V_65 -> V_11 ) ;
V_64 -> V_13 = F_32 ( V_64 -> V_13 ,
V_65 -> V_13 ) ;
V_64 -> V_16 = F_32 ( V_64 -> V_16 ,
V_65 -> V_16 ) ;
V_64 -> V_34 |= V_65 -> V_34 ;
V_69 = F_33 ( V_65 , V_66 ) ;
if ( V_64 -> V_32 != V_69 ) {
V_67 = F_15 ( V_64 -> V_27 , V_64 -> V_28 )
+ V_64 -> V_32 ;
V_68 = F_15 ( V_65 -> V_27 , V_65 -> V_28 ) + V_69 ;
if ( F_15 ( V_67 , V_68 ) & ( V_62 ( V_67 , V_68 ) - 1 ) ) {
V_64 -> V_34 = 1 ;
V_70 = - 1 ;
}
}
V_64 -> V_26 = F_15 ( V_64 -> V_26 ,
V_65 -> V_26 ) ;
V_64 -> V_27 = F_15 ( V_64 -> V_27 ,
V_65 -> V_27 ) ;
V_64 -> V_28 = F_15 ( V_64 -> V_28 , V_65 -> V_28 ) ;
V_64 -> V_33 = F_34 ( V_64 -> V_33 , V_65 -> V_33 ) ;
V_64 -> V_35 &= V_65 -> V_35 ;
V_64 -> V_25 &= V_65 -> V_25 ;
if ( V_64 -> V_27 & ( V_64 -> V_26 - 1 ) ) {
V_64 -> V_27 = V_64 -> V_26 ;
V_64 -> V_34 = 1 ;
V_70 = - 1 ;
}
if ( V_64 -> V_28 & ( V_64 -> V_27 - 1 ) ) {
V_64 -> V_28 = V_64 -> V_27 ;
V_64 -> V_34 = 1 ;
V_70 = - 1 ;
}
if ( V_64 -> V_33 & ( V_64 -> V_27 - 1 ) ) {
V_64 -> V_33 = 0 ;
V_64 -> V_34 = 1 ;
V_70 = - 1 ;
}
V_64 -> V_32 = F_34 ( V_64 -> V_32 , V_69 )
& ( F_15 ( V_64 -> V_27 , V_64 -> V_28 ) - 1 ) ;
if ( V_64 -> V_32 & ( V_64 -> V_26 - 1 ) ) {
V_64 -> V_34 = 1 ;
V_70 = - 1 ;
}
if ( V_65 -> V_22 ) {
V_69 = F_35 ( V_65 , V_66 ) ;
if ( V_64 -> V_22 != 0 &&
V_64 -> V_23 != V_69 ) {
V_67 = V_64 -> V_22 + V_64 -> V_23 ;
V_68 = V_65 -> V_22 + V_69 ;
if ( F_15 ( V_67 , V_68 ) & ( V_62 ( V_67 , V_68 ) - 1 ) )
V_64 -> V_24 = 1 ;
}
V_64 -> V_21 = F_32 ( V_64 -> V_21 ,
V_65 -> V_21 ) ;
V_64 -> V_22 = F_15 ( V_64 -> V_22 ,
V_65 -> V_22 ) ;
V_64 -> V_23 = F_34 ( V_64 -> V_23 , V_69 ) &
( V_64 -> V_22 - 1 ) ;
}
return V_70 ;
}
int F_36 ( struct V_9 * V_64 , struct V_71 * V_72 ,
T_9 V_66 )
{
struct V_1 * V_73 = F_37 ( V_72 ) ;
V_66 += F_38 ( V_72 ) ;
return F_31 ( V_64 , & V_73 -> V_44 , V_66 ) ;
}
void F_39 ( struct V_74 * V_75 , struct V_71 * V_72 ,
T_9 V_61 )
{
struct V_1 * V_64 = V_75 -> V_76 ;
if ( F_36 ( & V_64 -> V_44 , V_72 , V_61 >> 9 ) < 0 ) {
char V_67 [ V_77 ] , V_68 [ V_77 ] ;
F_40 ( V_75 , 0 , V_67 ) ;
F_41 ( V_72 , V_68 ) ;
F_18 ( V_78 L_2 ,
V_67 , V_68 ) ;
}
}
void F_42 ( struct V_1 * V_2 , unsigned int V_79 )
{
V_2 -> V_80 = V_79 ;
}
void F_43 ( struct V_1 * V_2 , unsigned int V_79 )
{
if ( V_79 > V_2 -> V_80 )
V_2 -> V_80 = V_79 ;
}
int F_44 ( struct V_1 * V_2 ,
T_10 * V_81 ,
void * V_82 , unsigned int V_60 )
{
if ( F_45 ( V_2 ) < 2 )
return - V_83 ;
F_21 ( V_2 , F_45 ( V_2 ) - 1 ) ;
V_2 -> V_81 = V_81 ;
V_2 -> V_84 = V_82 ;
V_2 -> V_85 = V_60 ;
return 0 ;
}
void F_46 ( struct V_1 * V_2 , unsigned long V_79 )
{
if ( V_79 < V_55 - 1 ) {
V_79 = V_55 - 1 ;
F_18 ( V_57 L_3 ,
V_58 , V_79 ) ;
}
V_2 -> V_44 . V_14 = V_79 ;
}
void F_11 ( struct V_1 * V_2 , int V_79 )
{
V_2 -> V_86 = V_79 ;
}
void F_47 ( struct V_1 * V_2 , int V_79 )
{
F_48 ( V_79 > V_87 ) ;
if ( V_79 > V_2 -> V_86 )
V_2 -> V_86 = V_79 ;
}
void F_49 ( struct V_1 * V_2 , unsigned int V_88 )
{
F_50 ( V_88 & ~ ( V_89 | V_90 ) ) ;
if ( F_50 ( ! ( V_88 & V_89 ) && ( V_88 & V_90 ) ) )
V_88 &= ~ V_90 ;
V_2 -> V_91 = V_88 & ( V_89 | V_90 ) ;
}
void F_51 ( struct V_1 * V_2 , bool V_92 )
{
V_2 -> V_93 = ! V_92 ;
}
static int T_11 F_52 ( void )
{
V_53 = V_52 - 1 ;
V_94 = V_95 - 1 ;
return 0 ;
}
