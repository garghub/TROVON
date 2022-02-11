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
V_9 -> V_29 = 0 ;
V_9 -> V_30 = V_9 -> V_31 = V_9 -> V_32 = 512 ;
V_9 -> V_33 = ( unsigned long ) ( V_34 >> V_35 ) ;
V_9 -> V_36 = 0 ;
V_9 -> V_37 = 0 ;
V_9 -> V_38 = 0 ;
V_9 -> V_39 = 1 ;
}
void F_8 ( struct V_8 * V_9 )
{
F_7 ( V_9 ) ;
V_9 -> V_29 = 1 ;
V_9 -> V_10 = V_40 ;
V_9 -> V_19 = V_41 ;
V_9 -> V_16 = V_41 ;
V_9 -> V_18 = V_41 ;
V_9 -> V_21 = V_41 ;
V_9 -> V_23 = V_41 ;
}
void F_9 ( struct V_1 * V_2 , T_6 * V_42 )
{
V_2 -> V_43 = V_44 ;
V_2 -> T_6 = V_42 ;
F_10 ( V_2 , 511 ) ;
F_11 ( V_2 ) ;
V_2 -> V_45 = V_46 ;
F_7 ( & V_2 -> V_47 ) ;
F_12 ( V_2 , V_48 ) ;
}
void F_12 ( struct V_1 * V_2 , T_7 V_49 )
{
unsigned long V_50 = V_49 >> V_35 ;
int V_51 = 0 ;
V_2 -> V_52 = V_53 ;
#if V_54 == 64
if ( V_50 < ( F_13 ( T_7 , 0xffffffffUL , V_48 ) >> V_35 ) )
V_51 = 1 ;
V_2 -> V_47 . V_33 = F_14 ( V_55 , V_50 ) ;
#else
if ( V_50 < V_56 )
V_51 = 1 ;
V_2 -> V_47 . V_33 = V_50 ;
#endif
if ( V_51 ) {
F_15 () ;
V_2 -> V_52 = V_53 | V_57 ;
V_2 -> V_47 . V_33 = V_50 ;
}
}
void F_16 ( struct V_1 * V_2 , unsigned int V_19 )
{
struct V_8 * V_47 = & V_2 -> V_47 ;
unsigned int V_18 ;
if ( ( V_19 << 9 ) < V_58 ) {
V_19 = 1 << ( V_59 - 9 ) ;
F_17 ( V_60 L_1 ,
V_61 , V_19 ) ;
}
V_47 -> V_19 = V_19 ;
V_18 = F_18 ( V_19 , V_47 -> V_21 ) ;
V_18 = F_13 (unsigned int, max_sectors, BLK_DEF_MAX_SECTORS) ;
V_47 -> V_18 = V_18 ;
}
void F_19 ( struct V_1 * V_2 , unsigned int V_22 )
{
F_20 ( ! F_21 ( V_22 ) ) ;
V_2 -> V_47 . V_22 = V_22 ;
}
void F_22 ( struct V_1 * V_2 ,
unsigned int V_24 )
{
V_2 -> V_47 . V_25 = V_24 ;
V_2 -> V_47 . V_24 = V_24 ;
}
void F_23 ( struct V_1 * V_2 ,
unsigned int V_23 )
{
V_2 -> V_47 . V_23 = V_23 ;
}
void F_24 ( struct V_1 * V_2 , unsigned short V_10 )
{
if ( ! V_10 ) {
V_10 = 1 ;
F_17 ( V_60 L_1 ,
V_61 , V_10 ) ;
}
V_2 -> V_47 . V_10 = V_10 ;
}
void F_25 ( struct V_1 * V_2 , unsigned int V_62 )
{
if ( V_62 < V_58 ) {
V_62 = V_58 ;
F_17 ( V_60 L_1 ,
V_61 , V_62 ) ;
}
V_2 -> V_47 . V_16 = V_62 ;
}
void F_26 ( struct V_1 * V_2 , unsigned short V_63 )
{
V_2 -> V_47 . V_30 = V_63 ;
if ( V_2 -> V_47 . V_31 < V_63 )
V_2 -> V_47 . V_31 = V_63 ;
if ( V_2 -> V_47 . V_32 < V_2 -> V_47 . V_31 )
V_2 -> V_47 . V_32 = V_2 -> V_47 . V_31 ;
}
void F_27 ( struct V_1 * V_2 , unsigned int V_63 )
{
V_2 -> V_47 . V_31 = V_63 ;
if ( V_2 -> V_47 . V_31 < V_2 -> V_47 . V_30 )
V_2 -> V_47 . V_31 = V_2 -> V_47 . V_30 ;
if ( V_2 -> V_47 . V_32 < V_2 -> V_47 . V_31 )
V_2 -> V_47 . V_32 = V_2 -> V_47 . V_31 ;
}
void F_28 ( struct V_1 * V_2 , unsigned int V_64 )
{
V_2 -> V_47 . V_36 =
V_64 & ( V_2 -> V_47 . V_31 - 1 ) ;
V_2 -> V_47 . V_38 = 0 ;
}
void F_29 ( struct V_8 * V_47 , unsigned int V_65 )
{
V_47 -> V_32 = V_65 ;
if ( V_47 -> V_32 < V_47 -> V_30 )
V_47 -> V_32 = V_47 -> V_30 ;
if ( V_47 -> V_32 < V_47 -> V_31 )
V_47 -> V_32 = V_47 -> V_31 ;
}
void F_30 ( struct V_1 * V_2 , unsigned int V_65 )
{
F_29 ( & V_2 -> V_47 , V_65 ) ;
}
void F_31 ( struct V_8 * V_47 , unsigned int V_66 )
{
V_47 -> V_37 = V_66 ;
}
void F_32 ( struct V_1 * V_2 , unsigned int V_66 )
{
F_31 ( & V_2 -> V_47 , V_66 ) ;
}
void F_33 ( struct V_1 * V_67 , struct V_1 * V_68 )
{
F_34 ( & V_67 -> V_47 , & V_68 -> V_47 , 0 ) ;
}
int F_34 ( struct V_8 * V_67 , struct V_8 * V_68 ,
T_8 V_69 )
{
unsigned int V_70 , V_71 , V_72 , V_73 = 0 ;
V_67 -> V_18 = F_18 ( V_67 -> V_18 , V_68 -> V_18 ) ;
V_67 -> V_19 = F_18 ( V_67 -> V_19 , V_68 -> V_19 ) ;
V_67 -> V_21 = F_18 ( V_67 -> V_21 , V_68 -> V_21 ) ;
V_67 -> V_23 = V_65 ( V_67 -> V_23 ,
V_68 -> V_23 ) ;
V_67 -> V_33 = F_18 ( V_67 -> V_33 , V_68 -> V_33 ) ;
V_67 -> V_13 = F_18 ( V_67 -> V_13 ,
V_68 -> V_13 ) ;
V_67 -> V_15 = F_18 ( V_67 -> V_15 ,
V_68 -> V_15 ) ;
V_67 -> V_10 = F_18 ( V_67 -> V_10 , V_68 -> V_10 ) ;
V_67 -> V_12 = F_18 ( V_67 -> V_12 ,
V_68 -> V_12 ) ;
V_67 -> V_16 = F_18 ( V_67 -> V_16 ,
V_68 -> V_16 ) ;
V_67 -> V_38 |= V_68 -> V_38 ;
V_72 = F_35 ( V_68 , V_69 ) ;
if ( V_67 -> V_36 != V_72 ) {
V_70 = F_14 ( V_67 -> V_31 , V_67 -> V_32 )
+ V_67 -> V_36 ;
V_71 = F_14 ( V_68 -> V_31 , V_68 -> V_32 ) + V_72 ;
if ( F_14 ( V_70 , V_71 ) % V_65 ( V_70 , V_71 ) ) {
V_67 -> V_38 = 1 ;
V_73 = - 1 ;
}
}
V_67 -> V_30 = F_14 ( V_67 -> V_30 ,
V_68 -> V_30 ) ;
V_67 -> V_31 = F_14 ( V_67 -> V_31 ,
V_68 -> V_31 ) ;
V_67 -> V_32 = F_14 ( V_67 -> V_32 , V_68 -> V_32 ) ;
V_67 -> V_37 = F_36 ( V_67 -> V_37 , V_68 -> V_37 ) ;
V_67 -> V_39 &= V_68 -> V_39 ;
V_67 -> V_29 &= V_68 -> V_29 ;
if ( V_67 -> V_31 & ( V_67 -> V_30 - 1 ) ) {
V_67 -> V_31 = V_67 -> V_30 ;
V_67 -> V_38 = 1 ;
V_73 = - 1 ;
}
if ( V_67 -> V_32 & ( V_67 -> V_31 - 1 ) ) {
V_67 -> V_32 = V_67 -> V_31 ;
V_67 -> V_38 = 1 ;
V_73 = - 1 ;
}
if ( V_67 -> V_37 & ( V_67 -> V_31 - 1 ) ) {
V_67 -> V_37 = 0 ;
V_67 -> V_38 = 1 ;
V_73 = - 1 ;
}
V_67 -> V_74 =
F_14 ( V_67 -> V_74 ,
V_68 -> V_74 ) ;
V_67 -> V_36 = F_36 ( V_67 -> V_36 , V_72 )
% F_14 ( V_67 -> V_31 , V_67 -> V_32 ) ;
if ( V_67 -> V_36 & ( V_67 -> V_30 - 1 ) ) {
V_67 -> V_38 = 1 ;
V_73 = - 1 ;
}
if ( V_68 -> V_26 ) {
V_72 = F_37 ( V_68 , V_69 ) ;
if ( V_67 -> V_26 != 0 &&
V_67 -> V_27 != V_72 ) {
V_70 = V_67 -> V_26 + V_67 -> V_27 ;
V_71 = V_68 -> V_26 + V_72 ;
if ( ( F_14 ( V_70 , V_71 ) % V_65 ( V_70 , V_71 ) ) != 0 )
V_67 -> V_28 = 1 ;
}
V_67 -> V_24 = F_18 ( V_67 -> V_24 ,
V_68 -> V_24 ) ;
V_67 -> V_25 = F_18 ( V_67 -> V_25 ,
V_68 -> V_25 ) ;
V_67 -> V_26 = F_14 ( V_67 -> V_26 ,
V_68 -> V_26 ) ;
V_67 -> V_27 = F_36 ( V_67 -> V_27 , V_72 ) %
V_67 -> V_26 ;
}
return V_73 ;
}
int F_38 ( struct V_8 * V_67 , struct V_75 * V_76 ,
T_8 V_69 )
{
struct V_1 * V_77 = F_39 ( V_76 ) ;
V_69 += F_40 ( V_76 ) ;
return F_34 ( V_67 , & V_77 -> V_47 , V_69 ) ;
}
void F_41 ( struct V_78 * V_79 , struct V_75 * V_76 ,
T_8 V_64 )
{
struct V_1 * V_67 = V_79 -> V_80 ;
if ( F_38 ( & V_67 -> V_47 , V_76 , V_64 >> 9 ) < 0 ) {
char V_70 [ V_81 ] , V_71 [ V_81 ] ;
F_42 ( V_79 , 0 , V_70 ) ;
F_43 ( V_76 , V_71 ) ;
F_17 ( V_82 L_2 ,
V_70 , V_71 ) ;
}
}
void F_44 ( struct V_1 * V_2 , unsigned int V_83 )
{
V_2 -> V_84 = V_83 ;
}
void F_45 ( struct V_1 * V_2 , unsigned int V_83 )
{
if ( V_83 > V_2 -> V_84 )
V_2 -> V_84 = V_83 ;
}
int F_46 ( struct V_1 * V_2 ,
T_9 * V_85 ,
void * V_86 , unsigned int V_63 )
{
if ( F_47 ( V_2 ) < 2 )
return - V_87 ;
F_24 ( V_2 , F_47 ( V_2 ) - 1 ) ;
V_2 -> V_85 = V_85 ;
V_2 -> V_88 = V_86 ;
V_2 -> V_89 = V_63 ;
return 0 ;
}
void F_48 ( struct V_1 * V_2 , unsigned long V_83 )
{
if ( V_83 < V_58 - 1 ) {
V_83 = V_58 - 1 ;
F_17 ( V_60 L_3 ,
V_61 , V_83 ) ;
}
V_2 -> V_47 . V_13 = V_83 ;
}
void F_49 ( struct V_1 * V_2 , unsigned long V_83 )
{
V_2 -> V_47 . V_15 = V_83 ;
}
void F_10 ( struct V_1 * V_2 , int V_83 )
{
V_2 -> V_90 = V_83 ;
}
void F_50 ( struct V_1 * V_2 , int V_83 )
{
F_20 ( V_83 > V_91 ) ;
if ( V_83 > V_2 -> V_90 )
V_2 -> V_90 = V_83 ;
}
void F_51 ( struct V_1 * V_2 , unsigned int V_92 )
{
F_52 ( V_92 & ~ ( V_93 | V_94 ) ) ;
if ( F_52 ( ! ( V_92 & V_93 ) && ( V_92 & V_94 ) ) )
V_92 &= ~ V_94 ;
V_2 -> V_95 = V_92 & ( V_93 | V_94 ) ;
}
void F_53 ( struct V_1 * V_2 , bool V_96 )
{
V_2 -> V_97 = ! V_96 ;
}
static int T_10 F_54 ( void )
{
V_56 = V_55 - 1 ;
V_98 = V_99 - 1 ;
return 0 ;
}
