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
V_9 -> V_12 = 1 ;
V_9 -> V_13 = 0 ;
V_9 -> V_14 = V_15 ;
V_9 -> V_16 = 0 ;
V_9 -> V_17 = V_18 ;
V_9 -> V_19 = V_9 -> V_20 = V_21 ;
V_9 -> V_22 = 0 ;
V_9 -> V_23 = 0 ;
V_9 -> V_24 = 0 ;
V_9 -> V_25 = 0 ;
V_9 -> V_26 = 0 ;
V_9 -> V_27 = 0 ;
V_9 -> V_28 = 0 ;
V_9 -> V_29 = 0 ;
V_9 -> V_30 = 0 ;
V_9 -> V_31 = 0 ;
V_9 -> V_32 = V_9 -> V_33 = V_9 -> V_34 = 512 ;
V_9 -> V_35 = ( unsigned long ) ( V_36 >> V_37 ) ;
V_9 -> V_38 = 0 ;
V_9 -> V_39 = 0 ;
V_9 -> V_40 = 0 ;
V_9 -> V_41 = 1 ;
V_9 -> V_42 = V_43 ;
}
void F_8 ( struct V_8 * V_9 )
{
F_7 ( V_9 ) ;
V_9 -> V_31 = 1 ;
V_9 -> V_10 = V_44 ;
V_9 -> V_12 = 1 ;
V_9 -> V_20 = V_45 ;
V_9 -> V_17 = V_45 ;
V_9 -> V_19 = V_45 ;
V_9 -> V_22 = V_45 ;
V_9 -> V_24 = V_45 ;
V_9 -> V_25 = V_45 ;
}
void F_9 ( struct V_1 * V_2 , T_6 * V_46 )
{
V_2 -> V_47 = V_48 ;
V_2 -> T_6 = V_46 ;
F_10 ( V_2 , 511 ) ;
F_11 ( V_2 ) ;
V_2 -> V_49 = V_50 ;
F_7 ( & V_2 -> V_51 ) ;
F_12 ( V_2 , V_52 ) ;
}
void F_12 ( struct V_1 * V_2 , T_7 V_53 )
{
unsigned long V_54 = V_53 >> V_37 ;
int V_55 = 0 ;
V_2 -> V_56 = V_57 ;
#if V_58 == 64
if ( V_54 < ( F_13 ( T_7 , 0xffffffffUL , V_52 ) >> V_37 ) )
V_55 = 1 ;
V_2 -> V_51 . V_35 = F_14 ( V_59 , V_54 ) ;
#else
if ( V_54 < V_60 )
V_55 = 1 ;
V_2 -> V_51 . V_35 = V_54 ;
#endif
if ( V_55 ) {
F_15 () ;
V_2 -> V_56 = V_57 | V_61 ;
V_2 -> V_51 . V_35 = V_54 ;
}
}
void F_16 ( struct V_1 * V_2 , unsigned int V_20 )
{
struct V_8 * V_51 = & V_2 -> V_51 ;
unsigned int V_19 ;
if ( ( V_20 << 9 ) < V_62 ) {
V_20 = 1 << ( V_37 - 9 ) ;
F_17 ( V_63 L_1 ,
V_64 , V_20 ) ;
}
V_51 -> V_20 = V_20 ;
V_19 = F_18 ( V_20 , V_51 -> V_22 ) ;
V_19 = F_13 (unsigned int, max_sectors, BLK_DEF_MAX_SECTORS) ;
V_51 -> V_19 = V_19 ;
V_2 -> V_65 -> V_66 = V_19 >> ( V_37 - 9 ) ;
}
void F_19 ( struct V_1 * V_2 , unsigned int V_23 )
{
F_20 ( ! F_21 ( V_23 ) ) ;
V_2 -> V_51 . V_23 = V_23 ;
}
void F_22 ( struct V_1 * V_2 ,
unsigned int V_26 )
{
V_2 -> V_51 . V_27 = V_26 ;
V_2 -> V_51 . V_26 = V_26 ;
}
void F_23 ( struct V_1 * V_2 ,
unsigned int V_24 )
{
V_2 -> V_51 . V_24 = V_24 ;
}
void F_24 ( struct V_1 * V_2 ,
unsigned int V_25 )
{
V_2 -> V_51 . V_25 = V_25 ;
}
void F_25 ( struct V_1 * V_2 , unsigned short V_10 )
{
if ( ! V_10 ) {
V_10 = 1 ;
F_17 ( V_63 L_1 ,
V_64 , V_10 ) ;
}
V_2 -> V_51 . V_10 = V_10 ;
}
void F_26 ( struct V_1 * V_2 ,
unsigned short V_10 )
{
V_2 -> V_51 . V_12 = V_10 ;
}
void F_27 ( struct V_1 * V_2 , unsigned int V_67 )
{
if ( V_67 < V_62 ) {
V_67 = V_62 ;
F_17 ( V_63 L_1 ,
V_64 , V_67 ) ;
}
V_2 -> V_51 . V_17 = V_67 ;
}
void F_28 ( struct V_1 * V_2 , unsigned short V_68 )
{
V_2 -> V_51 . V_32 = V_68 ;
if ( V_2 -> V_51 . V_33 < V_68 )
V_2 -> V_51 . V_33 = V_68 ;
if ( V_2 -> V_51 . V_34 < V_2 -> V_51 . V_33 )
V_2 -> V_51 . V_34 = V_2 -> V_51 . V_33 ;
}
void F_29 ( struct V_1 * V_2 , unsigned int V_68 )
{
V_2 -> V_51 . V_33 = V_68 ;
if ( V_2 -> V_51 . V_33 < V_2 -> V_51 . V_32 )
V_2 -> V_51 . V_33 = V_2 -> V_51 . V_32 ;
if ( V_2 -> V_51 . V_34 < V_2 -> V_51 . V_33 )
V_2 -> V_51 . V_34 = V_2 -> V_51 . V_33 ;
}
void F_30 ( struct V_1 * V_2 , unsigned int V_69 )
{
V_2 -> V_51 . V_38 =
V_69 & ( V_2 -> V_51 . V_33 - 1 ) ;
V_2 -> V_51 . V_40 = 0 ;
}
void F_31 ( struct V_8 * V_51 , unsigned int V_70 )
{
V_51 -> V_34 = V_70 ;
if ( V_51 -> V_34 < V_51 -> V_32 )
V_51 -> V_34 = V_51 -> V_32 ;
if ( V_51 -> V_34 < V_51 -> V_33 )
V_51 -> V_34 = V_51 -> V_33 ;
}
void F_32 ( struct V_1 * V_2 , unsigned int V_70 )
{
F_31 ( & V_2 -> V_51 , V_70 ) ;
}
void F_33 ( struct V_8 * V_51 , unsigned int V_71 )
{
V_51 -> V_39 = V_71 ;
}
void F_34 ( struct V_1 * V_2 , unsigned int V_71 )
{
F_33 ( & V_2 -> V_51 , V_71 ) ;
}
void F_35 ( struct V_1 * V_72 , struct V_1 * V_73 )
{
F_36 ( & V_72 -> V_51 , & V_73 -> V_51 , 0 ) ;
}
int F_36 ( struct V_8 * V_72 , struct V_8 * V_73 ,
T_8 V_74 )
{
unsigned int V_75 , V_76 , V_77 , V_78 = 0 ;
V_72 -> V_19 = F_18 ( V_72 -> V_19 , V_73 -> V_19 ) ;
V_72 -> V_20 = F_18 ( V_72 -> V_20 , V_73 -> V_20 ) ;
V_72 -> V_22 = F_18 ( V_72 -> V_22 , V_73 -> V_22 ) ;
V_72 -> V_24 = V_70 ( V_72 -> V_24 ,
V_73 -> V_24 ) ;
V_72 -> V_25 = V_70 ( V_72 -> V_25 ,
V_73 -> V_25 ) ;
V_72 -> V_35 = F_18 ( V_72 -> V_35 , V_73 -> V_35 ) ;
V_72 -> V_14 = F_18 ( V_72 -> V_14 ,
V_73 -> V_14 ) ;
V_72 -> V_16 = F_18 ( V_72 -> V_16 ,
V_73 -> V_16 ) ;
V_72 -> V_10 = F_18 ( V_72 -> V_10 , V_73 -> V_10 ) ;
V_72 -> V_12 = F_18 ( V_72 -> V_12 ,
V_73 -> V_12 ) ;
V_72 -> V_13 = F_18 ( V_72 -> V_13 ,
V_73 -> V_13 ) ;
V_72 -> V_17 = F_18 ( V_72 -> V_17 ,
V_73 -> V_17 ) ;
V_72 -> V_40 |= V_73 -> V_40 ;
V_77 = F_37 ( V_73 , V_74 ) ;
if ( V_72 -> V_38 != V_77 ) {
V_75 = F_14 ( V_72 -> V_33 , V_72 -> V_34 )
+ V_72 -> V_38 ;
V_76 = F_14 ( V_73 -> V_33 , V_73 -> V_34 ) + V_77 ;
if ( F_14 ( V_75 , V_76 ) % V_70 ( V_75 , V_76 ) ) {
V_72 -> V_40 = 1 ;
V_78 = - 1 ;
}
}
V_72 -> V_32 = F_14 ( V_72 -> V_32 ,
V_73 -> V_32 ) ;
V_72 -> V_33 = F_14 ( V_72 -> V_33 ,
V_73 -> V_33 ) ;
V_72 -> V_34 = F_14 ( V_72 -> V_34 , V_73 -> V_34 ) ;
V_72 -> V_39 = F_38 ( V_72 -> V_39 , V_73 -> V_39 ) ;
V_72 -> V_41 &= V_73 -> V_41 ;
V_72 -> V_31 &= V_73 -> V_31 ;
if ( V_72 -> V_33 & ( V_72 -> V_32 - 1 ) ) {
V_72 -> V_33 = V_72 -> V_32 ;
V_72 -> V_40 = 1 ;
V_78 = - 1 ;
}
if ( V_72 -> V_34 & ( V_72 -> V_33 - 1 ) ) {
V_72 -> V_34 = V_72 -> V_33 ;
V_72 -> V_40 = 1 ;
V_78 = - 1 ;
}
if ( V_72 -> V_39 & ( V_72 -> V_33 - 1 ) ) {
V_72 -> V_39 = 0 ;
V_72 -> V_40 = 1 ;
V_78 = - 1 ;
}
V_72 -> V_79 =
F_14 ( V_72 -> V_79 ,
V_73 -> V_79 ) ;
V_72 -> V_38 = F_38 ( V_72 -> V_38 , V_77 )
% F_14 ( V_72 -> V_33 , V_72 -> V_34 ) ;
if ( V_72 -> V_38 & ( V_72 -> V_32 - 1 ) ) {
V_72 -> V_40 = 1 ;
V_78 = - 1 ;
}
if ( V_73 -> V_28 ) {
V_77 = F_39 ( V_73 , V_74 ) ;
if ( V_72 -> V_28 != 0 &&
V_72 -> V_29 != V_77 ) {
V_75 = V_72 -> V_28 + V_72 -> V_29 ;
V_76 = V_73 -> V_28 + V_77 ;
if ( ( F_14 ( V_75 , V_76 ) % V_70 ( V_75 , V_76 ) ) != 0 )
V_72 -> V_30 = 1 ;
}
V_72 -> V_26 = F_18 ( V_72 -> V_26 ,
V_73 -> V_26 ) ;
V_72 -> V_27 = F_18 ( V_72 -> V_27 ,
V_73 -> V_27 ) ;
V_72 -> V_28 = F_14 ( V_72 -> V_28 ,
V_73 -> V_28 ) ;
V_72 -> V_29 = F_38 ( V_72 -> V_29 , V_77 ) %
V_72 -> V_28 ;
}
if ( V_73 -> V_23 )
V_72 -> V_23 = F_18 ( V_72 -> V_23 ,
V_73 -> V_23 ) ;
return V_78 ;
}
int F_40 ( struct V_8 * V_72 , struct V_80 * V_81 ,
T_8 V_74 )
{
struct V_1 * V_82 = F_41 ( V_81 ) ;
V_74 += F_42 ( V_81 ) ;
return F_36 ( V_72 , & V_82 -> V_51 , V_74 ) ;
}
void F_43 ( struct V_83 * V_84 , struct V_80 * V_81 ,
T_8 V_69 )
{
struct V_1 * V_72 = V_84 -> V_85 ;
if ( F_40 ( & V_72 -> V_51 , V_81 , V_69 >> 9 ) < 0 ) {
char V_75 [ V_86 ] , V_76 [ V_86 ] ;
F_44 ( V_84 , 0 , V_75 ) ;
F_45 ( V_81 , V_76 ) ;
F_17 ( V_87 L_2 ,
V_75 , V_76 ) ;
}
}
void F_46 ( struct V_1 * V_2 , unsigned int V_88 )
{
V_2 -> V_89 = V_88 ;
}
void F_47 ( struct V_1 * V_2 , unsigned int V_88 )
{
if ( V_88 > V_2 -> V_89 )
V_2 -> V_89 = V_88 ;
}
int F_48 ( struct V_1 * V_2 ,
T_9 * V_90 ,
void * V_91 , unsigned int V_68 )
{
if ( F_49 ( V_2 ) < 2 )
return - V_92 ;
F_25 ( V_2 , F_49 ( V_2 ) - 1 ) ;
V_2 -> V_90 = V_90 ;
V_2 -> V_93 = V_91 ;
V_2 -> V_94 = V_68 ;
return 0 ;
}
void F_50 ( struct V_1 * V_2 , unsigned long V_88 )
{
if ( V_88 < V_62 - 1 ) {
V_88 = V_62 - 1 ;
F_17 ( V_63 L_3 ,
V_64 , V_88 ) ;
}
V_2 -> V_51 . V_14 = V_88 ;
}
void F_51 ( struct V_1 * V_2 , unsigned long V_88 )
{
V_2 -> V_51 . V_16 = V_88 ;
}
void F_10 ( struct V_1 * V_2 , int V_88 )
{
V_2 -> V_95 = V_88 ;
}
void F_52 ( struct V_1 * V_2 , int V_88 )
{
F_20 ( V_88 > V_62 ) ;
if ( V_88 > V_2 -> V_95 )
V_2 -> V_95 = V_88 ;
}
void F_53 ( struct V_1 * V_2 , bool V_96 )
{
F_54 ( V_2 -> V_97 ) ;
if ( V_96 )
F_55 ( V_98 , & V_2 -> V_99 ) ;
else
F_56 ( V_98 , & V_2 -> V_99 ) ;
F_57 ( V_2 -> V_97 ) ;
}
void F_58 ( struct V_1 * V_2 , unsigned int V_100 )
{
V_2 -> V_101 = V_100 ;
F_59 ( V_2 -> V_102 , V_100 ) ;
}
void F_60 ( struct V_1 * V_2 , bool V_103 , bool V_104 )
{
F_54 ( V_2 -> V_97 ) ;
if ( V_103 )
F_61 ( V_105 , V_2 ) ;
else
F_62 ( V_105 , V_2 ) ;
if ( V_104 )
F_61 ( V_106 , V_2 ) ;
else
F_62 ( V_106 , V_2 ) ;
F_57 ( V_2 -> V_97 ) ;
F_63 ( V_2 -> V_102 , F_64 ( V_105 , & V_2 -> V_99 ) ) ;
}
static int T_10 F_65 ( void )
{
V_60 = V_59 - 1 ;
V_107 = V_108 - 1 ;
return 0 ;
}
