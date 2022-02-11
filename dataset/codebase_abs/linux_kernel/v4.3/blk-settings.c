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
void F_4 ( struct V_1 * V_2 , unsigned int V_6 )
{
V_2 -> V_7 = V_6 ;
}
void F_5 ( struct V_1 * V_2 , T_4 * V_5 )
{
V_2 -> T_4 = V_5 ;
}
void F_6 ( struct V_1 * V_2 , T_5 * V_5 )
{
V_2 -> T_5 = V_5 ;
}
void F_7 ( struct V_8 * V_9 )
{
V_9 -> V_10 = V_11 ;
V_9 -> V_12 = 0 ;
V_9 -> V_13 = V_14 ;
V_9 -> V_15 = 0 ;
V_9 -> V_16 = V_17 ;
V_9 -> V_18 = V_9 -> V_19 = V_20 ;
V_9 -> V_21 = 0 ;
V_9 -> V_22 = 0 ;
V_9 -> V_23 = 0 ;
V_9 -> V_24 = 0 ;
V_9 -> V_25 = 0 ;
V_9 -> V_26 = 0 ;
V_9 -> V_27 = 0 ;
V_9 -> V_28 = 0 ;
V_9 -> V_29 = V_9 -> V_30 = V_9 -> V_31 = 512 ;
V_9 -> V_32 = ( unsigned long ) ( V_33 >> V_34 ) ;
V_9 -> V_35 = 0 ;
V_9 -> V_36 = 0 ;
V_9 -> V_37 = 0 ;
V_9 -> V_38 = 1 ;
}
void F_8 ( struct V_8 * V_9 )
{
F_7 ( V_9 ) ;
V_9 -> V_28 = 1 ;
V_9 -> V_10 = V_39 ;
V_9 -> V_19 = V_40 ;
V_9 -> V_16 = V_40 ;
V_9 -> V_18 = V_40 ;
V_9 -> V_22 = V_40 ;
}
void F_9 ( struct V_1 * V_2 , T_6 * V_41 )
{
V_2 -> V_42 = V_43 ;
V_2 -> T_6 = V_41 ;
F_10 ( V_2 , 511 ) ;
F_11 ( V_2 ) ;
V_2 -> V_44 = V_45 ;
F_7 ( & V_2 -> V_46 ) ;
F_12 ( V_2 , V_47 ) ;
}
void F_12 ( struct V_1 * V_2 , T_7 V_48 )
{
unsigned long V_49 = V_48 >> V_34 ;
int V_50 = 0 ;
V_2 -> V_51 = V_52 ;
#if V_53 == 64
if ( V_49 < ( F_13 ( T_7 , 0xffffffffUL , V_47 ) >> V_34 ) )
V_50 = 1 ;
V_2 -> V_46 . V_32 = F_14 ( V_54 , V_49 ) ;
#else
if ( V_49 < V_55 )
V_50 = 1 ;
V_2 -> V_46 . V_32 = V_49 ;
#endif
if ( V_50 ) {
F_15 () ;
V_2 -> V_51 = V_52 | V_56 ;
V_2 -> V_46 . V_32 = V_49 ;
}
}
void F_16 ( struct V_8 * V_46 , unsigned int V_19 )
{
if ( ( V_19 << 9 ) < V_57 ) {
V_19 = 1 << ( V_58 - 9 ) ;
F_17 ( V_59 L_1 ,
V_60 , V_19 ) ;
}
V_46 -> V_19 = V_19 ;
V_46 -> V_18 = F_13 (unsigned int, max_hw_sectors,
BLK_DEF_MAX_SECTORS) ;
}
void F_18 ( struct V_1 * V_2 , unsigned int V_19 )
{
F_16 ( & V_2 -> V_46 , V_19 ) ;
}
void F_19 ( struct V_1 * V_2 , unsigned int V_21 )
{
F_20 ( ! F_21 ( V_21 ) ) ;
V_2 -> V_46 . V_21 = V_21 ;
}
void F_22 ( struct V_1 * V_2 ,
unsigned int V_23 )
{
V_2 -> V_46 . V_24 = V_23 ;
V_2 -> V_46 . V_23 = V_23 ;
}
void F_23 ( struct V_1 * V_2 ,
unsigned int V_22 )
{
V_2 -> V_46 . V_22 = V_22 ;
}
void F_24 ( struct V_1 * V_2 , unsigned short V_10 )
{
if ( ! V_10 ) {
V_10 = 1 ;
F_17 ( V_59 L_1 ,
V_60 , V_10 ) ;
}
V_2 -> V_46 . V_10 = V_10 ;
}
void F_25 ( struct V_1 * V_2 , unsigned int V_61 )
{
if ( V_61 < V_57 ) {
V_61 = V_57 ;
F_17 ( V_59 L_1 ,
V_60 , V_61 ) ;
}
V_2 -> V_46 . V_16 = V_61 ;
}
void F_26 ( struct V_1 * V_2 , unsigned short V_62 )
{
V_2 -> V_46 . V_29 = V_62 ;
if ( V_2 -> V_46 . V_30 < V_62 )
V_2 -> V_46 . V_30 = V_62 ;
if ( V_2 -> V_46 . V_31 < V_2 -> V_46 . V_30 )
V_2 -> V_46 . V_31 = V_2 -> V_46 . V_30 ;
}
void F_27 ( struct V_1 * V_2 , unsigned int V_62 )
{
V_2 -> V_46 . V_30 = V_62 ;
if ( V_2 -> V_46 . V_30 < V_2 -> V_46 . V_29 )
V_2 -> V_46 . V_30 = V_2 -> V_46 . V_29 ;
if ( V_2 -> V_46 . V_31 < V_2 -> V_46 . V_30 )
V_2 -> V_46 . V_31 = V_2 -> V_46 . V_30 ;
}
void F_28 ( struct V_1 * V_2 , unsigned int V_63 )
{
V_2 -> V_46 . V_35 =
V_63 & ( V_2 -> V_46 . V_30 - 1 ) ;
V_2 -> V_46 . V_37 = 0 ;
}
void F_29 ( struct V_8 * V_46 , unsigned int V_64 )
{
V_46 -> V_31 = V_64 ;
if ( V_46 -> V_31 < V_46 -> V_29 )
V_46 -> V_31 = V_46 -> V_29 ;
if ( V_46 -> V_31 < V_46 -> V_30 )
V_46 -> V_31 = V_46 -> V_30 ;
}
void F_30 ( struct V_1 * V_2 , unsigned int V_64 )
{
F_29 ( & V_2 -> V_46 , V_64 ) ;
}
void F_31 ( struct V_8 * V_46 , unsigned int V_65 )
{
V_46 -> V_36 = V_65 ;
}
void F_32 ( struct V_1 * V_2 , unsigned int V_65 )
{
F_31 ( & V_2 -> V_46 , V_65 ) ;
}
void F_33 ( struct V_1 * V_66 , struct V_1 * V_67 )
{
F_34 ( & V_66 -> V_46 , & V_67 -> V_46 , 0 ) ;
}
int F_34 ( struct V_8 * V_66 , struct V_8 * V_67 ,
T_8 V_68 )
{
unsigned int V_69 , V_70 , V_71 , V_72 = 0 ;
V_66 -> V_18 = F_35 ( V_66 -> V_18 , V_67 -> V_18 ) ;
V_66 -> V_19 = F_35 ( V_66 -> V_19 , V_67 -> V_19 ) ;
V_66 -> V_22 = V_64 ( V_66 -> V_22 ,
V_67 -> V_22 ) ;
V_66 -> V_32 = F_35 ( V_66 -> V_32 , V_67 -> V_32 ) ;
V_66 -> V_13 = F_35 ( V_66 -> V_13 ,
V_67 -> V_13 ) ;
V_66 -> V_15 = F_35 ( V_66 -> V_15 ,
V_67 -> V_15 ) ;
V_66 -> V_10 = F_35 ( V_66 -> V_10 , V_67 -> V_10 ) ;
V_66 -> V_12 = F_35 ( V_66 -> V_12 ,
V_67 -> V_12 ) ;
V_66 -> V_16 = F_35 ( V_66 -> V_16 ,
V_67 -> V_16 ) ;
V_66 -> V_37 |= V_67 -> V_37 ;
V_71 = F_36 ( V_67 , V_68 ) ;
if ( V_66 -> V_35 != V_71 ) {
V_69 = F_14 ( V_66 -> V_30 , V_66 -> V_31 )
+ V_66 -> V_35 ;
V_70 = F_14 ( V_67 -> V_30 , V_67 -> V_31 ) + V_71 ;
if ( F_14 ( V_69 , V_70 ) % V_64 ( V_69 , V_70 ) ) {
V_66 -> V_37 = 1 ;
V_72 = - 1 ;
}
}
V_66 -> V_29 = F_14 ( V_66 -> V_29 ,
V_67 -> V_29 ) ;
V_66 -> V_30 = F_14 ( V_66 -> V_30 ,
V_67 -> V_30 ) ;
V_66 -> V_31 = F_14 ( V_66 -> V_31 , V_67 -> V_31 ) ;
V_66 -> V_36 = F_37 ( V_66 -> V_36 , V_67 -> V_36 ) ;
V_66 -> V_38 &= V_67 -> V_38 ;
V_66 -> V_28 &= V_67 -> V_28 ;
if ( V_66 -> V_30 & ( V_66 -> V_29 - 1 ) ) {
V_66 -> V_30 = V_66 -> V_29 ;
V_66 -> V_37 = 1 ;
V_72 = - 1 ;
}
if ( V_66 -> V_31 & ( V_66 -> V_30 - 1 ) ) {
V_66 -> V_31 = V_66 -> V_30 ;
V_66 -> V_37 = 1 ;
V_72 = - 1 ;
}
if ( V_66 -> V_36 & ( V_66 -> V_30 - 1 ) ) {
V_66 -> V_36 = 0 ;
V_66 -> V_37 = 1 ;
V_72 = - 1 ;
}
V_66 -> V_73 =
F_14 ( V_66 -> V_73 ,
V_67 -> V_73 ) ;
V_66 -> V_35 = F_37 ( V_66 -> V_35 , V_71 )
% F_14 ( V_66 -> V_30 , V_66 -> V_31 ) ;
if ( V_66 -> V_35 & ( V_66 -> V_29 - 1 ) ) {
V_66 -> V_37 = 1 ;
V_72 = - 1 ;
}
if ( V_67 -> V_25 ) {
V_71 = F_38 ( V_67 , V_68 ) ;
if ( V_66 -> V_25 != 0 &&
V_66 -> V_26 != V_71 ) {
V_69 = V_66 -> V_25 + V_66 -> V_26 ;
V_70 = V_67 -> V_25 + V_71 ;
if ( ( F_14 ( V_69 , V_70 ) % V_64 ( V_69 , V_70 ) ) != 0 )
V_66 -> V_27 = 1 ;
}
V_66 -> V_23 = F_35 ( V_66 -> V_23 ,
V_67 -> V_23 ) ;
V_66 -> V_24 = F_35 ( V_66 -> V_24 ,
V_67 -> V_24 ) ;
V_66 -> V_25 = F_14 ( V_66 -> V_25 ,
V_67 -> V_25 ) ;
V_66 -> V_26 = F_37 ( V_66 -> V_26 , V_71 ) %
V_66 -> V_25 ;
}
return V_72 ;
}
int F_39 ( struct V_8 * V_66 , struct V_74 * V_75 ,
T_8 V_68 )
{
struct V_1 * V_76 = F_40 ( V_75 ) ;
V_68 += F_41 ( V_75 ) ;
return F_34 ( V_66 , & V_76 -> V_46 , V_68 ) ;
}
void F_42 ( struct V_77 * V_78 , struct V_74 * V_75 ,
T_8 V_63 )
{
struct V_1 * V_66 = V_78 -> V_79 ;
if ( F_39 ( & V_66 -> V_46 , V_75 , V_63 >> 9 ) < 0 ) {
char V_69 [ V_80 ] , V_70 [ V_80 ] ;
F_43 ( V_78 , 0 , V_69 ) ;
F_44 ( V_75 , V_70 ) ;
F_17 ( V_81 L_2 ,
V_69 , V_70 ) ;
}
}
void F_45 ( struct V_1 * V_2 , unsigned int V_82 )
{
V_2 -> V_83 = V_82 ;
}
void F_46 ( struct V_1 * V_2 , unsigned int V_82 )
{
if ( V_82 > V_2 -> V_83 )
V_2 -> V_83 = V_82 ;
}
int F_47 ( struct V_1 * V_2 ,
T_9 * V_84 ,
void * V_85 , unsigned int V_62 )
{
if ( F_48 ( V_2 ) < 2 )
return - V_86 ;
F_24 ( V_2 , F_48 ( V_2 ) - 1 ) ;
V_2 -> V_84 = V_84 ;
V_2 -> V_87 = V_85 ;
V_2 -> V_88 = V_62 ;
return 0 ;
}
void F_49 ( struct V_1 * V_2 , unsigned long V_82 )
{
if ( V_82 < V_57 - 1 ) {
V_82 = V_57 - 1 ;
F_17 ( V_59 L_3 ,
V_60 , V_82 ) ;
}
V_2 -> V_46 . V_13 = V_82 ;
}
void F_50 ( struct V_1 * V_2 , unsigned long V_82 )
{
V_2 -> V_46 . V_15 = V_82 ;
}
void F_10 ( struct V_1 * V_2 , int V_82 )
{
V_2 -> V_89 = V_82 ;
}
void F_51 ( struct V_1 * V_2 , int V_82 )
{
F_20 ( V_82 > V_90 ) ;
if ( V_82 > V_2 -> V_89 )
V_2 -> V_89 = V_82 ;
}
void F_52 ( struct V_1 * V_2 , unsigned int V_91 )
{
F_53 ( V_91 & ~ ( V_92 | V_93 ) ) ;
if ( F_53 ( ! ( V_91 & V_92 ) && ( V_91 & V_93 ) ) )
V_91 &= ~ V_93 ;
V_2 -> V_94 = V_91 & ( V_92 | V_93 ) ;
}
void F_54 ( struct V_1 * V_2 , bool V_95 )
{
V_2 -> V_96 = ! V_95 ;
}
static int T_10 F_55 ( void )
{
V_55 = V_54 - 1 ;
V_97 = V_98 - 1 ;
return 0 ;
}
