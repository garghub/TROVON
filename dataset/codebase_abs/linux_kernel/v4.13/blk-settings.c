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
V_9 -> V_31 = V_9 -> V_32 = V_9 -> V_33 = 512 ;
V_9 -> V_34 = ( unsigned long ) ( V_35 >> V_36 ) ;
V_9 -> V_37 = 0 ;
V_9 -> V_38 = 0 ;
V_9 -> V_39 = 0 ;
V_9 -> V_40 = 1 ;
V_9 -> V_41 = V_42 ;
}
void F_8 ( struct V_8 * V_9 )
{
F_7 ( V_9 ) ;
V_9 -> V_10 = V_43 ;
V_9 -> V_12 = 1 ;
V_9 -> V_20 = V_44 ;
V_9 -> V_17 = V_44 ;
V_9 -> V_19 = V_44 ;
V_9 -> V_22 = V_44 ;
V_9 -> V_24 = V_44 ;
V_9 -> V_25 = V_44 ;
}
void F_9 ( struct V_1 * V_2 , T_6 * V_45 )
{
V_2 -> V_46 = V_47 ;
V_2 -> T_6 = V_45 ;
F_10 ( V_2 , 511 ) ;
F_11 ( V_2 ) ;
V_2 -> V_48 = V_49 ;
F_7 ( & V_2 -> V_50 ) ;
}
void F_12 ( struct V_1 * V_2 , T_7 V_51 )
{
unsigned long V_52 = V_51 >> V_36 ;
int V_53 = 0 ;
V_2 -> V_54 = V_55 ;
#if V_56 == 64
if ( V_52 < ( F_13 ( T_7 , 0xffffffffUL , V_57 ) >> V_36 ) )
V_53 = 1 ;
V_2 -> V_50 . V_34 = F_14 ( V_58 , V_52 ) ;
#else
if ( V_52 < V_59 )
V_53 = 1 ;
V_2 -> V_50 . V_34 = V_52 ;
#endif
if ( V_53 ) {
F_15 () ;
V_2 -> V_54 = V_55 | V_60 ;
V_2 -> V_50 . V_34 = V_52 ;
}
}
void F_16 ( struct V_1 * V_2 , unsigned int V_20 )
{
struct V_8 * V_50 = & V_2 -> V_50 ;
unsigned int V_19 ;
if ( ( V_20 << 9 ) < V_61 ) {
V_20 = 1 << ( V_36 - 9 ) ;
F_17 ( V_62 L_1 ,
V_63 , V_20 ) ;
}
V_50 -> V_20 = V_20 ;
V_19 = F_18 ( V_20 , V_50 -> V_22 ) ;
V_19 = F_13 (unsigned int, max_sectors, BLK_DEF_MAX_SECTORS) ;
V_50 -> V_19 = V_19 ;
V_2 -> V_64 -> V_65 = V_19 >> ( V_36 - 9 ) ;
}
void F_19 ( struct V_1 * V_2 , unsigned int V_23 )
{
F_20 ( ! F_21 ( V_23 ) ) ;
V_2 -> V_50 . V_23 = V_23 ;
}
void F_22 ( struct V_1 * V_2 ,
unsigned int V_26 )
{
V_2 -> V_50 . V_27 = V_26 ;
V_2 -> V_50 . V_26 = V_26 ;
}
void F_23 ( struct V_1 * V_2 ,
unsigned int V_24 )
{
V_2 -> V_50 . V_24 = V_24 ;
}
void F_24 ( struct V_1 * V_2 ,
unsigned int V_25 )
{
V_2 -> V_50 . V_25 = V_25 ;
}
void F_25 ( struct V_1 * V_2 , unsigned short V_10 )
{
if ( ! V_10 ) {
V_10 = 1 ;
F_17 ( V_62 L_1 ,
V_63 , V_10 ) ;
}
V_2 -> V_50 . V_10 = V_10 ;
}
void F_26 ( struct V_1 * V_2 ,
unsigned short V_10 )
{
V_2 -> V_50 . V_12 = V_10 ;
}
void F_27 ( struct V_1 * V_2 , unsigned int V_66 )
{
if ( V_66 < V_61 ) {
V_66 = V_61 ;
F_17 ( V_62 L_1 ,
V_63 , V_66 ) ;
}
V_2 -> V_50 . V_17 = V_66 ;
}
void F_28 ( struct V_1 * V_2 , unsigned short V_67 )
{
V_2 -> V_50 . V_31 = V_67 ;
if ( V_2 -> V_50 . V_32 < V_67 )
V_2 -> V_50 . V_32 = V_67 ;
if ( V_2 -> V_50 . V_33 < V_2 -> V_50 . V_32 )
V_2 -> V_50 . V_33 = V_2 -> V_50 . V_32 ;
}
void F_29 ( struct V_1 * V_2 , unsigned int V_67 )
{
V_2 -> V_50 . V_32 = V_67 ;
if ( V_2 -> V_50 . V_32 < V_2 -> V_50 . V_31 )
V_2 -> V_50 . V_32 = V_2 -> V_50 . V_31 ;
if ( V_2 -> V_50 . V_33 < V_2 -> V_50 . V_32 )
V_2 -> V_50 . V_33 = V_2 -> V_50 . V_32 ;
}
void F_30 ( struct V_1 * V_2 , unsigned int V_68 )
{
V_2 -> V_50 . V_37 =
V_68 & ( V_2 -> V_50 . V_32 - 1 ) ;
V_2 -> V_50 . V_39 = 0 ;
}
void F_31 ( struct V_8 * V_50 , unsigned int V_69 )
{
V_50 -> V_33 = V_69 ;
if ( V_50 -> V_33 < V_50 -> V_31 )
V_50 -> V_33 = V_50 -> V_31 ;
if ( V_50 -> V_33 < V_50 -> V_32 )
V_50 -> V_33 = V_50 -> V_32 ;
}
void F_32 ( struct V_1 * V_2 , unsigned int V_69 )
{
F_31 ( & V_2 -> V_50 , V_69 ) ;
}
void F_33 ( struct V_8 * V_50 , unsigned int V_70 )
{
V_50 -> V_38 = V_70 ;
}
void F_34 ( struct V_1 * V_2 , unsigned int V_70 )
{
F_33 ( & V_2 -> V_50 , V_70 ) ;
}
void F_35 ( struct V_1 * V_71 , struct V_1 * V_72 )
{
F_36 ( & V_71 -> V_50 , & V_72 -> V_50 , 0 ) ;
}
int F_36 ( struct V_8 * V_71 , struct V_8 * V_72 ,
T_8 V_73 )
{
unsigned int V_74 , V_75 , V_76 , V_77 = 0 ;
V_71 -> V_19 = F_18 ( V_71 -> V_19 , V_72 -> V_19 ) ;
V_71 -> V_20 = F_18 ( V_71 -> V_20 , V_72 -> V_20 ) ;
V_71 -> V_22 = F_18 ( V_71 -> V_22 , V_72 -> V_22 ) ;
V_71 -> V_24 = V_69 ( V_71 -> V_24 ,
V_72 -> V_24 ) ;
V_71 -> V_25 = V_69 ( V_71 -> V_25 ,
V_72 -> V_25 ) ;
V_71 -> V_34 = F_18 ( V_71 -> V_34 , V_72 -> V_34 ) ;
V_71 -> V_14 = F_18 ( V_71 -> V_14 ,
V_72 -> V_14 ) ;
V_71 -> V_16 = F_18 ( V_71 -> V_16 ,
V_72 -> V_16 ) ;
V_71 -> V_10 = F_18 ( V_71 -> V_10 , V_72 -> V_10 ) ;
V_71 -> V_12 = F_18 ( V_71 -> V_12 ,
V_72 -> V_12 ) ;
V_71 -> V_13 = F_18 ( V_71 -> V_13 ,
V_72 -> V_13 ) ;
V_71 -> V_17 = F_18 ( V_71 -> V_17 ,
V_72 -> V_17 ) ;
V_71 -> V_39 |= V_72 -> V_39 ;
V_76 = F_37 ( V_72 , V_73 ) ;
if ( V_71 -> V_37 != V_76 ) {
V_74 = F_14 ( V_71 -> V_32 , V_71 -> V_33 )
+ V_71 -> V_37 ;
V_75 = F_14 ( V_72 -> V_32 , V_72 -> V_33 ) + V_76 ;
if ( F_14 ( V_74 , V_75 ) % V_69 ( V_74 , V_75 ) ) {
V_71 -> V_39 = 1 ;
V_77 = - 1 ;
}
}
V_71 -> V_31 = F_14 ( V_71 -> V_31 ,
V_72 -> V_31 ) ;
V_71 -> V_32 = F_14 ( V_71 -> V_32 ,
V_72 -> V_32 ) ;
V_71 -> V_33 = F_14 ( V_71 -> V_33 , V_72 -> V_33 ) ;
V_71 -> V_38 = F_38 ( V_71 -> V_38 , V_72 -> V_38 ) ;
V_71 -> V_40 &= V_72 -> V_40 ;
if ( V_71 -> V_32 & ( V_71 -> V_31 - 1 ) ) {
V_71 -> V_32 = V_71 -> V_31 ;
V_71 -> V_39 = 1 ;
V_77 = - 1 ;
}
if ( V_71 -> V_33 & ( V_71 -> V_32 - 1 ) ) {
V_71 -> V_33 = V_71 -> V_32 ;
V_71 -> V_39 = 1 ;
V_77 = - 1 ;
}
if ( V_71 -> V_38 & ( V_71 -> V_32 - 1 ) ) {
V_71 -> V_38 = 0 ;
V_71 -> V_39 = 1 ;
V_77 = - 1 ;
}
V_71 -> V_78 =
F_14 ( V_71 -> V_78 ,
V_72 -> V_78 ) ;
V_71 -> V_37 = F_38 ( V_71 -> V_37 , V_76 )
% F_14 ( V_71 -> V_32 , V_71 -> V_33 ) ;
if ( V_71 -> V_37 & ( V_71 -> V_31 - 1 ) ) {
V_71 -> V_39 = 1 ;
V_77 = - 1 ;
}
if ( V_72 -> V_28 ) {
V_76 = F_39 ( V_72 , V_73 ) ;
if ( V_71 -> V_28 != 0 &&
V_71 -> V_29 != V_76 ) {
V_74 = V_71 -> V_28 + V_71 -> V_29 ;
V_75 = V_72 -> V_28 + V_76 ;
if ( ( F_14 ( V_74 , V_75 ) % V_69 ( V_74 , V_75 ) ) != 0 )
V_71 -> V_30 = 1 ;
}
V_71 -> V_26 = F_18 ( V_71 -> V_26 ,
V_72 -> V_26 ) ;
V_71 -> V_27 = F_18 ( V_71 -> V_27 ,
V_72 -> V_27 ) ;
V_71 -> V_28 = F_14 ( V_71 -> V_28 ,
V_72 -> V_28 ) ;
V_71 -> V_29 = F_38 ( V_71 -> V_29 , V_76 ) %
V_71 -> V_28 ;
}
if ( V_72 -> V_23 )
V_71 -> V_23 = F_18 ( V_71 -> V_23 ,
V_72 -> V_23 ) ;
return V_77 ;
}
int F_40 ( struct V_8 * V_71 , struct V_79 * V_80 ,
T_8 V_73 )
{
struct V_1 * V_81 = F_41 ( V_80 ) ;
V_73 += F_42 ( V_80 ) ;
return F_36 ( V_71 , & V_81 -> V_50 , V_73 ) ;
}
void F_43 ( struct V_82 * V_83 , struct V_79 * V_80 ,
T_8 V_68 )
{
struct V_1 * V_71 = V_83 -> V_84 ;
if ( F_40 ( & V_71 -> V_50 , V_80 , V_68 >> 9 ) < 0 ) {
char V_74 [ V_85 ] , V_75 [ V_85 ] ;
F_44 ( V_83 , 0 , V_74 ) ;
F_45 ( V_80 , V_75 ) ;
F_17 ( V_86 L_2 ,
V_74 , V_75 ) ;
}
}
void F_46 ( struct V_1 * V_2 , unsigned int V_87 )
{
V_2 -> V_88 = V_87 ;
}
void F_47 ( struct V_1 * V_2 , unsigned int V_87 )
{
if ( V_87 > V_2 -> V_88 )
V_2 -> V_88 = V_87 ;
}
int F_48 ( struct V_1 * V_2 ,
T_9 * V_89 ,
void * V_90 , unsigned int V_67 )
{
if ( F_49 ( V_2 ) < 2 )
return - V_91 ;
F_25 ( V_2 , F_49 ( V_2 ) - 1 ) ;
V_2 -> V_89 = V_89 ;
V_2 -> V_92 = V_90 ;
V_2 -> V_93 = V_67 ;
return 0 ;
}
void F_50 ( struct V_1 * V_2 , unsigned long V_87 )
{
if ( V_87 < V_61 - 1 ) {
V_87 = V_61 - 1 ;
F_17 ( V_62 L_3 ,
V_63 , V_87 ) ;
}
V_2 -> V_50 . V_14 = V_87 ;
}
void F_51 ( struct V_1 * V_2 , unsigned long V_87 )
{
V_2 -> V_50 . V_16 = V_87 ;
}
void F_10 ( struct V_1 * V_2 , int V_87 )
{
V_2 -> V_94 = V_87 ;
}
void F_52 ( struct V_1 * V_2 , int V_87 )
{
F_20 ( V_87 > V_61 ) ;
if ( V_87 > V_2 -> V_94 )
V_2 -> V_94 = V_87 ;
}
void F_53 ( struct V_1 * V_2 , bool V_95 )
{
F_54 ( V_2 -> V_96 ) ;
if ( V_95 )
F_55 ( V_97 , & V_2 -> V_98 ) ;
else
F_56 ( V_97 , & V_2 -> V_98 ) ;
F_57 ( V_2 -> V_96 ) ;
}
void F_58 ( struct V_1 * V_2 , unsigned int V_99 )
{
V_2 -> V_100 = V_99 ;
F_59 ( V_2 -> V_101 , V_99 ) ;
}
void F_60 ( struct V_1 * V_2 , bool V_102 , bool V_103 )
{
F_54 ( V_2 -> V_96 ) ;
if ( V_102 )
F_61 ( V_104 , V_2 ) ;
else
F_62 ( V_104 , V_2 ) ;
if ( V_103 )
F_61 ( V_105 , V_2 ) ;
else
F_62 ( V_105 , V_2 ) ;
F_57 ( V_2 -> V_96 ) ;
F_63 ( V_2 -> V_101 , F_64 ( V_104 , & V_2 -> V_98 ) ) ;
}
static int T_10 F_65 ( void )
{
V_59 = V_58 - 1 ;
V_106 = V_107 - 1 ;
return 0 ;
}
