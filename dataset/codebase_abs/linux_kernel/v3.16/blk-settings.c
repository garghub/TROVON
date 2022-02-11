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
V_10 -> V_26 = 0 ;
V_10 -> V_27 = 0 ;
V_10 -> V_28 = V_10 -> V_29 = V_10 -> V_30 = 512 ;
V_10 -> V_31 = ( unsigned long ) ( V_32 >> V_33 ) ;
V_10 -> V_34 = 0 ;
V_10 -> V_35 = 0 ;
V_10 -> V_36 = 0 ;
V_10 -> V_37 = 1 ;
}
void F_9 ( struct V_9 * V_10 )
{
F_8 ( V_10 ) ;
V_10 -> V_27 = 1 ;
V_10 -> V_11 = V_38 ;
V_10 -> V_19 = V_39 ;
V_10 -> V_16 = V_39 ;
V_10 -> V_18 = V_39 ;
V_10 -> V_22 = V_39 ;
}
void F_10 ( struct V_1 * V_2 , T_7 * V_40 )
{
V_2 -> V_41 = V_42 ;
V_2 -> T_7 = V_40 ;
F_11 ( V_2 , 511 ) ;
F_12 ( V_2 ) ;
V_2 -> V_43 = V_44 ;
F_8 ( & V_2 -> V_45 ) ;
F_13 ( V_2 , V_46 ) ;
}
void F_13 ( struct V_1 * V_2 , T_8 V_47 )
{
unsigned long V_48 = V_47 >> V_33 ;
int V_49 = 0 ;
V_2 -> V_50 = V_51 ;
#if V_52 == 64
if ( V_48 < ( F_14 ( T_8 , 0xffffffffUL , V_46 ) >> V_33 ) )
V_49 = 1 ;
V_2 -> V_45 . V_31 = F_15 ( V_53 , V_48 ) ;
#else
if ( V_48 < V_54 )
V_49 = 1 ;
V_2 -> V_45 . V_31 = V_48 ;
#endif
if ( V_49 ) {
F_16 () ;
V_2 -> V_50 = V_51 | V_55 ;
V_2 -> V_45 . V_31 = V_48 ;
}
}
void F_17 ( struct V_9 * V_45 , unsigned int V_19 )
{
if ( ( V_19 << 9 ) < V_56 ) {
V_19 = 1 << ( V_57 - 9 ) ;
F_18 ( V_58 L_1 ,
V_59 , V_19 ) ;
}
V_45 -> V_19 = V_19 ;
V_45 -> V_18 = F_14 (unsigned int, max_hw_sectors,
BLK_DEF_MAX_SECTORS) ;
}
void F_19 ( struct V_1 * V_2 , unsigned int V_19 )
{
F_17 ( & V_2 -> V_45 , V_19 ) ;
}
void F_20 ( struct V_1 * V_2 , unsigned int V_21 )
{
F_21 ( ! F_22 ( V_21 ) ) ;
V_2 -> V_45 . V_21 = V_21 ;
}
void F_23 ( struct V_1 * V_2 ,
unsigned int V_23 )
{
V_2 -> V_45 . V_23 = V_23 ;
}
void F_24 ( struct V_1 * V_2 ,
unsigned int V_22 )
{
V_2 -> V_45 . V_22 = V_22 ;
}
void F_25 ( struct V_1 * V_2 , unsigned short V_11 )
{
if ( ! V_11 ) {
V_11 = 1 ;
F_18 ( V_58 L_1 ,
V_59 , V_11 ) ;
}
V_2 -> V_45 . V_11 = V_11 ;
}
void F_26 ( struct V_1 * V_2 , unsigned int V_60 )
{
if ( V_60 < V_56 ) {
V_60 = V_56 ;
F_18 ( V_58 L_1 ,
V_59 , V_60 ) ;
}
V_2 -> V_45 . V_16 = V_60 ;
}
void F_27 ( struct V_1 * V_2 , unsigned short V_61 )
{
V_2 -> V_45 . V_28 = V_61 ;
if ( V_2 -> V_45 . V_29 < V_61 )
V_2 -> V_45 . V_29 = V_61 ;
if ( V_2 -> V_45 . V_30 < V_2 -> V_45 . V_29 )
V_2 -> V_45 . V_30 = V_2 -> V_45 . V_29 ;
}
void F_28 ( struct V_1 * V_2 , unsigned int V_61 )
{
V_2 -> V_45 . V_29 = V_61 ;
if ( V_2 -> V_45 . V_29 < V_2 -> V_45 . V_28 )
V_2 -> V_45 . V_29 = V_2 -> V_45 . V_28 ;
if ( V_2 -> V_45 . V_30 < V_2 -> V_45 . V_29 )
V_2 -> V_45 . V_30 = V_2 -> V_45 . V_29 ;
}
void F_29 ( struct V_1 * V_2 , unsigned int V_62 )
{
V_2 -> V_45 . V_34 =
V_62 & ( V_2 -> V_45 . V_29 - 1 ) ;
V_2 -> V_45 . V_36 = 0 ;
}
void F_30 ( struct V_9 * V_45 , unsigned int V_63 )
{
V_45 -> V_30 = V_63 ;
if ( V_45 -> V_30 < V_45 -> V_28 )
V_45 -> V_30 = V_45 -> V_28 ;
if ( V_45 -> V_30 < V_45 -> V_29 )
V_45 -> V_30 = V_45 -> V_29 ;
}
void F_31 ( struct V_1 * V_2 , unsigned int V_63 )
{
F_30 ( & V_2 -> V_45 , V_63 ) ;
}
void F_32 ( struct V_9 * V_45 , unsigned int V_64 )
{
V_45 -> V_35 = V_64 ;
}
void F_33 ( struct V_1 * V_2 , unsigned int V_64 )
{
F_32 ( & V_2 -> V_45 , V_64 ) ;
}
void F_34 ( struct V_1 * V_65 , struct V_1 * V_66 )
{
F_35 ( & V_65 -> V_45 , & V_66 -> V_45 , 0 ) ;
}
int F_35 ( struct V_9 * V_65 , struct V_9 * V_66 ,
T_9 V_67 )
{
unsigned int V_68 , V_69 , V_70 , V_71 = 0 ;
V_65 -> V_18 = F_36 ( V_65 -> V_18 , V_66 -> V_18 ) ;
V_65 -> V_19 = F_36 ( V_65 -> V_19 , V_66 -> V_19 ) ;
V_65 -> V_22 = V_63 ( V_65 -> V_22 ,
V_66 -> V_22 ) ;
V_65 -> V_31 = F_36 ( V_65 -> V_31 , V_66 -> V_31 ) ;
V_65 -> V_14 = F_36 ( V_65 -> V_14 ,
V_66 -> V_14 ) ;
V_65 -> V_11 = F_36 ( V_65 -> V_11 , V_66 -> V_11 ) ;
V_65 -> V_13 = F_36 ( V_65 -> V_13 ,
V_66 -> V_13 ) ;
V_65 -> V_16 = F_36 ( V_65 -> V_16 ,
V_66 -> V_16 ) ;
V_65 -> V_36 |= V_66 -> V_36 ;
V_70 = F_37 ( V_66 , V_67 ) ;
if ( V_65 -> V_34 != V_70 ) {
V_68 = F_15 ( V_65 -> V_29 , V_65 -> V_30 )
+ V_65 -> V_34 ;
V_69 = F_15 ( V_66 -> V_29 , V_66 -> V_30 ) + V_70 ;
if ( F_15 ( V_68 , V_69 ) & ( V_63 ( V_68 , V_69 ) - 1 ) ) {
V_65 -> V_36 = 1 ;
V_71 = - 1 ;
}
}
V_65 -> V_28 = F_15 ( V_65 -> V_28 ,
V_66 -> V_28 ) ;
V_65 -> V_29 = F_15 ( V_65 -> V_29 ,
V_66 -> V_29 ) ;
V_65 -> V_30 = F_15 ( V_65 -> V_30 , V_66 -> V_30 ) ;
V_65 -> V_35 = F_38 ( V_65 -> V_35 , V_66 -> V_35 ) ;
V_65 -> V_37 &= V_66 -> V_37 ;
V_65 -> V_27 &= V_66 -> V_27 ;
if ( V_65 -> V_29 & ( V_65 -> V_28 - 1 ) ) {
V_65 -> V_29 = V_65 -> V_28 ;
V_65 -> V_36 = 1 ;
V_71 = - 1 ;
}
if ( V_65 -> V_30 & ( V_65 -> V_29 - 1 ) ) {
V_65 -> V_30 = V_65 -> V_29 ;
V_65 -> V_36 = 1 ;
V_71 = - 1 ;
}
if ( V_65 -> V_35 & ( V_65 -> V_29 - 1 ) ) {
V_65 -> V_35 = 0 ;
V_65 -> V_36 = 1 ;
V_71 = - 1 ;
}
V_65 -> V_72 =
F_15 ( V_65 -> V_72 ,
V_66 -> V_72 ) ;
V_65 -> V_34 = F_38 ( V_65 -> V_34 , V_70 )
& ( F_15 ( V_65 -> V_29 , V_65 -> V_30 ) - 1 ) ;
if ( V_65 -> V_34 & ( V_65 -> V_28 - 1 ) ) {
V_65 -> V_36 = 1 ;
V_71 = - 1 ;
}
if ( V_66 -> V_24 ) {
V_70 = F_39 ( V_66 , V_67 ) ;
if ( V_65 -> V_24 != 0 &&
V_65 -> V_25 != V_70 ) {
V_68 = V_65 -> V_24 + V_65 -> V_25 ;
V_69 = V_66 -> V_24 + V_70 ;
if ( ( F_15 ( V_68 , V_69 ) % V_63 ( V_68 , V_69 ) ) != 0 )
V_65 -> V_26 = 1 ;
}
V_65 -> V_23 = F_36 ( V_65 -> V_23 ,
V_66 -> V_23 ) ;
V_65 -> V_24 = F_15 ( V_65 -> V_24 ,
V_66 -> V_24 ) ;
V_65 -> V_25 = F_38 ( V_65 -> V_25 , V_70 ) %
V_65 -> V_24 ;
}
return V_71 ;
}
int F_40 ( struct V_9 * V_65 , struct V_73 * V_74 ,
T_9 V_67 )
{
struct V_1 * V_75 = F_41 ( V_74 ) ;
V_67 += F_42 ( V_74 ) ;
return F_35 ( V_65 , & V_75 -> V_45 , V_67 ) ;
}
void F_43 ( struct V_76 * V_77 , struct V_73 * V_74 ,
T_9 V_62 )
{
struct V_1 * V_65 = V_77 -> V_78 ;
if ( F_40 ( & V_65 -> V_45 , V_74 , V_62 >> 9 ) < 0 ) {
char V_68 [ V_79 ] , V_69 [ V_79 ] ;
F_44 ( V_77 , 0 , V_68 ) ;
F_45 ( V_74 , V_69 ) ;
F_18 ( V_80 L_2 ,
V_68 , V_69 ) ;
}
}
void F_46 ( struct V_1 * V_2 , unsigned int V_81 )
{
V_2 -> V_82 = V_81 ;
}
void F_47 ( struct V_1 * V_2 , unsigned int V_81 )
{
if ( V_81 > V_2 -> V_82 )
V_2 -> V_82 = V_81 ;
}
int F_48 ( struct V_1 * V_2 ,
T_10 * V_83 ,
void * V_84 , unsigned int V_61 )
{
if ( F_49 ( V_2 ) < 2 )
return - V_85 ;
F_25 ( V_2 , F_49 ( V_2 ) - 1 ) ;
V_2 -> V_83 = V_83 ;
V_2 -> V_86 = V_84 ;
V_2 -> V_87 = V_61 ;
return 0 ;
}
void F_50 ( struct V_1 * V_2 , unsigned long V_81 )
{
if ( V_81 < V_56 - 1 ) {
V_81 = V_56 - 1 ;
F_18 ( V_58 L_3 ,
V_59 , V_81 ) ;
}
V_2 -> V_45 . V_14 = V_81 ;
}
void F_11 ( struct V_1 * V_2 , int V_81 )
{
V_2 -> V_88 = V_81 ;
}
void F_51 ( struct V_1 * V_2 , int V_81 )
{
F_21 ( V_81 > V_89 ) ;
if ( V_81 > V_2 -> V_88 )
V_2 -> V_88 = V_81 ;
}
void F_52 ( struct V_1 * V_2 , unsigned int V_90 )
{
F_53 ( V_90 & ~ ( V_91 | V_92 ) ) ;
if ( F_53 ( ! ( V_90 & V_91 ) && ( V_90 & V_92 ) ) )
V_90 &= ~ V_92 ;
V_2 -> V_93 = V_90 & ( V_91 | V_92 ) ;
}
void F_54 ( struct V_1 * V_2 , bool V_94 )
{
V_2 -> V_95 = ! V_94 ;
}
static int T_11 F_55 ( void )
{
V_54 = V_53 - 1 ;
V_96 = V_97 - 1 ;
return 0 ;
}
