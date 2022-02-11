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
V_10 -> V_18 = V_19 ;
V_10 -> V_20 = V_21 ;
V_10 -> V_22 = 0 ;
V_10 -> V_23 = 0 ;
V_10 -> V_24 = 0 ;
V_10 -> V_25 = 0 ;
V_10 -> V_26 = 1 ;
V_10 -> V_27 = V_10 -> V_28 = V_10 -> V_29 = 512 ;
V_10 -> V_30 = ( unsigned long ) ( V_31 >> V_32 ) ;
V_10 -> V_33 = 0 ;
V_10 -> V_34 = 0 ;
V_10 -> V_35 = 0 ;
V_10 -> V_36 = 1 ;
}
void F_9 ( struct V_1 * V_2 , T_7 * V_37 )
{
V_2 -> V_38 = V_39 ;
V_2 -> T_7 = V_37 ;
F_10 ( V_2 , 511 ) ;
F_11 ( V_2 ) ;
V_2 -> V_40 = V_41 ;
F_8 ( & V_2 -> V_42 ) ;
F_12 ( V_2 , V_43 ) ;
V_2 -> V_42 . V_26 = 0 ;
F_13 ( V_2 , V_44 ) ;
}
void F_13 ( struct V_1 * V_2 , T_8 V_45 )
{
unsigned long V_46 = V_45 >> V_32 ;
int V_47 = 0 ;
V_2 -> V_48 = V_49 ;
#if V_50 == 64
if ( V_46 < ( F_14 ( T_8 , 0xffffffffUL , V_44 ) >> V_32 ) )
V_47 = 1 ;
V_2 -> V_42 . V_30 = F_15 ( V_51 , V_46 ) ;
#else
if ( V_46 < V_52 )
V_47 = 1 ;
V_2 -> V_42 . V_30 = V_46 ;
#endif
if ( V_47 ) {
F_16 () ;
V_2 -> V_48 = V_49 | V_53 ;
V_2 -> V_42 . V_30 = V_46 ;
}
}
void F_17 ( struct V_9 * V_42 , unsigned int V_20 )
{
if ( ( V_20 << 9 ) < V_54 ) {
V_20 = 1 << ( V_55 - 9 ) ;
F_18 ( V_56 L_1 ,
V_57 , V_20 ) ;
}
V_42 -> V_20 = V_20 ;
V_42 -> V_18 = F_14 (unsigned int, max_hw_sectors,
BLK_DEF_MAX_SECTORS) ;
}
void F_12 ( struct V_1 * V_2 , unsigned int V_20 )
{
F_17 ( & V_2 -> V_42 , V_20 ) ;
}
void F_19 ( struct V_1 * V_2 ,
unsigned int V_22 )
{
V_2 -> V_42 . V_22 = V_22 ;
}
void F_20 ( struct V_1 * V_2 , unsigned short V_11 )
{
if ( ! V_11 ) {
V_11 = 1 ;
F_18 ( V_56 L_1 ,
V_57 , V_11 ) ;
}
V_2 -> V_42 . V_11 = V_11 ;
}
void F_21 ( struct V_1 * V_2 , unsigned int V_58 )
{
if ( V_58 < V_54 ) {
V_58 = V_54 ;
F_18 ( V_56 L_1 ,
V_57 , V_58 ) ;
}
V_2 -> V_42 . V_16 = V_58 ;
}
void F_22 ( struct V_1 * V_2 , unsigned short V_59 )
{
V_2 -> V_42 . V_27 = V_59 ;
if ( V_2 -> V_42 . V_28 < V_59 )
V_2 -> V_42 . V_28 = V_59 ;
if ( V_2 -> V_42 . V_29 < V_2 -> V_42 . V_28 )
V_2 -> V_42 . V_29 = V_2 -> V_42 . V_28 ;
}
void F_23 ( struct V_1 * V_2 , unsigned int V_59 )
{
V_2 -> V_42 . V_28 = V_59 ;
if ( V_2 -> V_42 . V_28 < V_2 -> V_42 . V_27 )
V_2 -> V_42 . V_28 = V_2 -> V_42 . V_27 ;
if ( V_2 -> V_42 . V_29 < V_2 -> V_42 . V_28 )
V_2 -> V_42 . V_29 = V_2 -> V_42 . V_28 ;
}
void F_24 ( struct V_1 * V_2 , unsigned int V_60 )
{
V_2 -> V_42 . V_33 =
V_60 & ( V_2 -> V_42 . V_28 - 1 ) ;
V_2 -> V_42 . V_35 = 0 ;
}
void F_25 ( struct V_9 * V_42 , unsigned int V_61 )
{
V_42 -> V_29 = V_61 ;
if ( V_42 -> V_29 < V_42 -> V_27 )
V_42 -> V_29 = V_42 -> V_27 ;
if ( V_42 -> V_29 < V_42 -> V_28 )
V_42 -> V_29 = V_42 -> V_28 ;
}
void F_26 ( struct V_1 * V_2 , unsigned int V_61 )
{
F_25 ( & V_2 -> V_42 , V_61 ) ;
}
void F_27 ( struct V_9 * V_42 , unsigned int V_62 )
{
V_42 -> V_34 = V_62 ;
}
void F_28 ( struct V_1 * V_2 , unsigned int V_62 )
{
F_27 ( & V_2 -> V_42 , V_62 ) ;
}
void F_29 ( struct V_1 * V_63 , struct V_1 * V_64 )
{
F_30 ( & V_63 -> V_42 , & V_64 -> V_42 , 0 ) ;
}
int F_30 ( struct V_9 * V_63 , struct V_9 * V_64 ,
T_9 V_65 )
{
unsigned int V_66 , V_67 , V_68 , V_69 = 0 ;
V_63 -> V_18 = F_31 ( V_63 -> V_18 , V_64 -> V_18 ) ;
V_63 -> V_20 = F_31 ( V_63 -> V_20 , V_64 -> V_20 ) ;
V_63 -> V_30 = F_31 ( V_63 -> V_30 , V_64 -> V_30 ) ;
V_63 -> V_14 = F_31 ( V_63 -> V_14 ,
V_64 -> V_14 ) ;
V_63 -> V_11 = F_31 ( V_63 -> V_11 , V_64 -> V_11 ) ;
V_63 -> V_13 = F_31 ( V_63 -> V_13 ,
V_64 -> V_13 ) ;
V_63 -> V_16 = F_31 ( V_63 -> V_16 ,
V_64 -> V_16 ) ;
V_63 -> V_35 |= V_64 -> V_35 ;
V_68 = F_32 ( V_64 , V_65 ) ;
if ( V_63 -> V_33 != V_68 ) {
V_66 = F_15 ( V_63 -> V_28 , V_63 -> V_29 )
+ V_63 -> V_33 ;
V_67 = F_15 ( V_64 -> V_28 , V_64 -> V_29 ) + V_68 ;
if ( F_15 ( V_66 , V_67 ) & ( V_61 ( V_66 , V_67 ) - 1 ) ) {
V_63 -> V_35 = 1 ;
V_69 = - 1 ;
}
}
V_63 -> V_27 = F_15 ( V_63 -> V_27 ,
V_64 -> V_27 ) ;
V_63 -> V_28 = F_15 ( V_63 -> V_28 ,
V_64 -> V_28 ) ;
V_63 -> V_29 = F_15 ( V_63 -> V_29 , V_64 -> V_29 ) ;
V_63 -> V_34 = F_33 ( V_63 -> V_34 , V_64 -> V_34 ) ;
V_63 -> V_36 &= V_64 -> V_36 ;
V_63 -> V_26 &= V_64 -> V_26 ;
if ( V_63 -> V_28 & ( V_63 -> V_27 - 1 ) ) {
V_63 -> V_28 = V_63 -> V_27 ;
V_63 -> V_35 = 1 ;
V_69 = - 1 ;
}
if ( V_63 -> V_29 & ( V_63 -> V_28 - 1 ) ) {
V_63 -> V_29 = V_63 -> V_28 ;
V_63 -> V_35 = 1 ;
V_69 = - 1 ;
}
if ( V_63 -> V_34 & ( V_63 -> V_28 - 1 ) ) {
V_63 -> V_34 = 0 ;
V_63 -> V_35 = 1 ;
V_69 = - 1 ;
}
V_63 -> V_33 = F_33 ( V_63 -> V_33 , V_68 )
& ( F_15 ( V_63 -> V_28 , V_63 -> V_29 ) - 1 ) ;
if ( V_63 -> V_33 & ( V_63 -> V_27 - 1 ) ) {
V_63 -> V_35 = 1 ;
V_69 = - 1 ;
}
if ( V_64 -> V_23 ) {
V_68 = F_34 ( V_64 , V_65 ) ;
if ( V_63 -> V_23 != 0 &&
V_63 -> V_24 != V_68 ) {
V_66 = V_63 -> V_23 + V_63 -> V_24 ;
V_67 = V_64 -> V_23 + V_68 ;
if ( F_15 ( V_66 , V_67 ) & ( V_61 ( V_66 , V_67 ) - 1 ) )
V_63 -> V_25 = 1 ;
}
V_63 -> V_22 = F_31 ( V_63 -> V_22 ,
V_64 -> V_22 ) ;
V_63 -> V_23 = F_15 ( V_63 -> V_23 ,
V_64 -> V_23 ) ;
V_63 -> V_24 = F_33 ( V_63 -> V_24 , V_68 ) &
( V_63 -> V_23 - 1 ) ;
}
return V_69 ;
}
int F_35 ( struct V_9 * V_63 , struct V_70 * V_71 ,
T_9 V_65 )
{
struct V_1 * V_72 = F_36 ( V_71 ) ;
V_65 += F_37 ( V_71 ) ;
return F_30 ( V_63 , & V_72 -> V_42 , V_65 ) ;
}
void F_38 ( struct V_73 * V_74 , struct V_70 * V_71 ,
T_9 V_60 )
{
struct V_1 * V_63 = V_74 -> V_75 ;
if ( F_35 ( & V_63 -> V_42 , V_71 , V_60 >> 9 ) < 0 ) {
char V_66 [ V_76 ] , V_67 [ V_76 ] ;
F_39 ( V_74 , 0 , V_66 ) ;
F_40 ( V_71 , V_67 ) ;
F_18 ( V_77 L_2 ,
V_66 , V_67 ) ;
}
}
void F_41 ( struct V_1 * V_2 , unsigned int V_78 )
{
V_2 -> V_79 = V_78 ;
}
void F_42 ( struct V_1 * V_2 , unsigned int V_78 )
{
if ( V_78 > V_2 -> V_79 )
V_2 -> V_79 = V_78 ;
}
int F_43 ( struct V_1 * V_2 ,
T_10 * V_80 ,
void * V_81 , unsigned int V_59 )
{
if ( F_44 ( V_2 ) < 2 )
return - V_82 ;
F_20 ( V_2 , F_44 ( V_2 ) - 1 ) ;
V_2 -> V_80 = V_80 ;
V_2 -> V_83 = V_81 ;
V_2 -> V_84 = V_59 ;
return 0 ;
}
void F_45 ( struct V_1 * V_2 , unsigned long V_78 )
{
if ( V_78 < V_54 - 1 ) {
V_78 = V_54 - 1 ;
F_18 ( V_56 L_3 ,
V_57 , V_78 ) ;
}
V_2 -> V_42 . V_14 = V_78 ;
}
void F_10 ( struct V_1 * V_2 , int V_78 )
{
V_2 -> V_85 = V_78 ;
}
void F_46 ( struct V_1 * V_2 , int V_78 )
{
F_47 ( V_78 > V_86 ) ;
if ( V_78 > V_2 -> V_85 )
V_2 -> V_85 = V_78 ;
}
void F_48 ( struct V_1 * V_2 , unsigned int V_87 )
{
F_49 ( V_87 & ~ ( V_88 | V_89 ) ) ;
if ( F_49 ( ! ( V_87 & V_88 ) && ( V_87 & V_89 ) ) )
V_87 &= ~ V_89 ;
V_2 -> V_90 = V_87 & ( V_88 | V_89 ) ;
}
void F_50 ( struct V_1 * V_2 , bool V_91 )
{
V_2 -> V_92 = ! V_91 ;
}
static int T_11 F_51 ( void )
{
V_52 = V_51 - 1 ;
V_93 = V_94 - 1 ;
return 0 ;
}
