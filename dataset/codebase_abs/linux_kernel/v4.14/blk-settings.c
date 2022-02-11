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
F_6 ( V_2 -> V_8 ) ;
V_2 -> T_4 = V_5 ;
}
void F_7 ( struct V_1 * V_2 , T_5 * V_5 )
{
V_2 -> T_5 = V_5 ;
}
void F_8 ( struct V_9 * V_10 )
{
V_10 -> V_11 = V_12 ;
V_10 -> V_13 = 1 ;
V_10 -> V_14 = 0 ;
V_10 -> V_15 = V_16 ;
V_10 -> V_17 = 0 ;
V_10 -> V_18 = V_19 ;
V_10 -> V_20 = V_10 -> V_21 = V_22 ;
V_10 -> V_23 = 0 ;
V_10 -> V_24 = 0 ;
V_10 -> V_25 = 0 ;
V_10 -> V_26 = 0 ;
V_10 -> V_27 = 0 ;
V_10 -> V_28 = 0 ;
V_10 -> V_29 = 0 ;
V_10 -> V_30 = 0 ;
V_10 -> V_31 = 0 ;
V_10 -> V_32 = V_10 -> V_33 = V_10 -> V_34 = 512 ;
V_10 -> V_35 = ( unsigned long ) ( V_36 >> V_37 ) ;
V_10 -> V_38 = 0 ;
V_10 -> V_39 = 0 ;
V_10 -> V_40 = 0 ;
V_10 -> V_41 = 1 ;
V_10 -> V_42 = V_43 ;
}
void F_9 ( struct V_9 * V_10 )
{
F_8 ( V_10 ) ;
V_10 -> V_11 = V_44 ;
V_10 -> V_13 = 1 ;
V_10 -> V_21 = V_45 ;
V_10 -> V_18 = V_45 ;
V_10 -> V_20 = V_45 ;
V_10 -> V_23 = V_45 ;
V_10 -> V_25 = V_45 ;
V_10 -> V_26 = V_45 ;
}
void F_10 ( struct V_1 * V_2 , T_6 * V_46 )
{
V_2 -> V_47 = V_48 ;
V_2 -> T_6 = V_46 ;
F_11 ( V_2 , 511 ) ;
F_12 ( V_2 ) ;
V_2 -> V_49 = V_50 ;
F_8 ( & V_2 -> V_51 ) ;
}
void F_13 ( struct V_1 * V_2 , T_7 V_52 )
{
unsigned long V_53 = V_52 >> V_37 ;
int V_54 = 0 ;
V_2 -> V_55 = V_56 ;
#if V_57 == 64
if ( V_53 < ( F_14 ( T_7 , 0xffffffffUL , V_58 ) >> V_37 ) )
V_54 = 1 ;
V_2 -> V_51 . V_35 = F_15 ( V_59 , V_53 ) ;
#else
if ( V_53 < V_60 )
V_54 = 1 ;
V_2 -> V_51 . V_35 = V_53 ;
#endif
if ( V_54 ) {
F_16 () ;
V_2 -> V_55 = V_56 | V_61 ;
V_2 -> V_51 . V_35 = V_53 ;
}
}
void F_17 ( struct V_1 * V_2 , unsigned int V_21 )
{
struct V_9 * V_51 = & V_2 -> V_51 ;
unsigned int V_20 ;
if ( ( V_21 << 9 ) < V_62 ) {
V_21 = 1 << ( V_37 - 9 ) ;
F_18 ( V_63 L_1 ,
V_64 , V_21 ) ;
}
V_51 -> V_21 = V_21 ;
V_20 = F_19 ( V_21 , V_51 -> V_23 ) ;
V_20 = F_14 (unsigned int, max_sectors, BLK_DEF_MAX_SECTORS) ;
V_51 -> V_20 = V_20 ;
V_2 -> V_65 -> V_66 = V_20 >> ( V_37 - 9 ) ;
}
void F_20 ( struct V_1 * V_2 , unsigned int V_24 )
{
F_21 ( ! F_22 ( V_24 ) ) ;
V_2 -> V_51 . V_24 = V_24 ;
}
void F_23 ( struct V_1 * V_2 ,
unsigned int V_27 )
{
V_2 -> V_51 . V_28 = V_27 ;
V_2 -> V_51 . V_27 = V_27 ;
}
void F_24 ( struct V_1 * V_2 ,
unsigned int V_25 )
{
V_2 -> V_51 . V_25 = V_25 ;
}
void F_25 ( struct V_1 * V_2 ,
unsigned int V_26 )
{
V_2 -> V_51 . V_26 = V_26 ;
}
void F_26 ( struct V_1 * V_2 , unsigned short V_11 )
{
if ( ! V_11 ) {
V_11 = 1 ;
F_18 ( V_63 L_1 ,
V_64 , V_11 ) ;
}
V_2 -> V_51 . V_11 = V_11 ;
}
void F_27 ( struct V_1 * V_2 ,
unsigned short V_11 )
{
V_2 -> V_51 . V_13 = V_11 ;
}
void F_28 ( struct V_1 * V_2 , unsigned int V_67 )
{
if ( V_67 < V_62 ) {
V_67 = V_62 ;
F_18 ( V_63 L_1 ,
V_64 , V_67 ) ;
}
V_2 -> V_51 . V_18 = V_67 ;
}
void F_29 ( struct V_1 * V_2 , unsigned short V_68 )
{
V_2 -> V_51 . V_32 = V_68 ;
if ( V_2 -> V_51 . V_33 < V_68 )
V_2 -> V_51 . V_33 = V_68 ;
if ( V_2 -> V_51 . V_34 < V_2 -> V_51 . V_33 )
V_2 -> V_51 . V_34 = V_2 -> V_51 . V_33 ;
}
void F_30 ( struct V_1 * V_2 , unsigned int V_68 )
{
V_2 -> V_51 . V_33 = V_68 ;
if ( V_2 -> V_51 . V_33 < V_2 -> V_51 . V_32 )
V_2 -> V_51 . V_33 = V_2 -> V_51 . V_32 ;
if ( V_2 -> V_51 . V_34 < V_2 -> V_51 . V_33 )
V_2 -> V_51 . V_34 = V_2 -> V_51 . V_33 ;
}
void F_31 ( struct V_1 * V_2 , unsigned int V_69 )
{
V_2 -> V_51 . V_38 =
V_69 & ( V_2 -> V_51 . V_33 - 1 ) ;
V_2 -> V_51 . V_40 = 0 ;
}
void F_32 ( struct V_9 * V_51 , unsigned int V_70 )
{
V_51 -> V_34 = V_70 ;
if ( V_51 -> V_34 < V_51 -> V_32 )
V_51 -> V_34 = V_51 -> V_32 ;
if ( V_51 -> V_34 < V_51 -> V_33 )
V_51 -> V_34 = V_51 -> V_33 ;
}
void F_33 ( struct V_1 * V_2 , unsigned int V_70 )
{
F_32 ( & V_2 -> V_51 , V_70 ) ;
}
void F_34 ( struct V_9 * V_51 , unsigned int V_71 )
{
V_51 -> V_39 = V_71 ;
}
void F_35 ( struct V_1 * V_2 , unsigned int V_71 )
{
F_34 ( & V_2 -> V_51 , V_71 ) ;
}
void F_36 ( struct V_1 * V_72 , struct V_1 * V_73 )
{
F_37 ( & V_72 -> V_51 , & V_73 -> V_51 , 0 ) ;
}
int F_37 ( struct V_9 * V_72 , struct V_9 * V_73 ,
T_8 V_74 )
{
unsigned int V_75 , V_76 , V_77 , V_78 = 0 ;
V_72 -> V_20 = F_19 ( V_72 -> V_20 , V_73 -> V_20 ) ;
V_72 -> V_21 = F_19 ( V_72 -> V_21 , V_73 -> V_21 ) ;
V_72 -> V_23 = F_19 ( V_72 -> V_23 , V_73 -> V_23 ) ;
V_72 -> V_25 = V_70 ( V_72 -> V_25 ,
V_73 -> V_25 ) ;
V_72 -> V_26 = V_70 ( V_72 -> V_26 ,
V_73 -> V_26 ) ;
V_72 -> V_35 = F_19 ( V_72 -> V_35 , V_73 -> V_35 ) ;
V_72 -> V_15 = F_19 ( V_72 -> V_15 ,
V_73 -> V_15 ) ;
V_72 -> V_17 = F_19 ( V_72 -> V_17 ,
V_73 -> V_17 ) ;
V_72 -> V_11 = F_19 ( V_72 -> V_11 , V_73 -> V_11 ) ;
V_72 -> V_13 = F_19 ( V_72 -> V_13 ,
V_73 -> V_13 ) ;
V_72 -> V_14 = F_19 ( V_72 -> V_14 ,
V_73 -> V_14 ) ;
V_72 -> V_18 = F_19 ( V_72 -> V_18 ,
V_73 -> V_18 ) ;
V_72 -> V_40 |= V_73 -> V_40 ;
V_77 = F_38 ( V_73 , V_74 ) ;
if ( V_72 -> V_38 != V_77 ) {
V_75 = F_15 ( V_72 -> V_33 , V_72 -> V_34 )
+ V_72 -> V_38 ;
V_76 = F_15 ( V_73 -> V_33 , V_73 -> V_34 ) + V_77 ;
if ( F_15 ( V_75 , V_76 ) % V_70 ( V_75 , V_76 ) ) {
V_72 -> V_40 = 1 ;
V_78 = - 1 ;
}
}
V_72 -> V_32 = F_15 ( V_72 -> V_32 ,
V_73 -> V_32 ) ;
V_72 -> V_33 = F_15 ( V_72 -> V_33 ,
V_73 -> V_33 ) ;
V_72 -> V_34 = F_15 ( V_72 -> V_34 , V_73 -> V_34 ) ;
V_72 -> V_39 = F_39 ( V_72 -> V_39 , V_73 -> V_39 ) ;
V_72 -> V_41 &= V_73 -> V_41 ;
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
F_15 ( V_72 -> V_79 ,
V_73 -> V_79 ) ;
V_72 -> V_38 = F_39 ( V_72 -> V_38 , V_77 )
% F_15 ( V_72 -> V_33 , V_72 -> V_34 ) ;
if ( V_72 -> V_38 & ( V_72 -> V_32 - 1 ) ) {
V_72 -> V_40 = 1 ;
V_78 = - 1 ;
}
if ( V_73 -> V_29 ) {
V_77 = F_40 ( V_73 , V_74 ) ;
if ( V_72 -> V_29 != 0 &&
V_72 -> V_30 != V_77 ) {
V_75 = V_72 -> V_29 + V_72 -> V_30 ;
V_76 = V_73 -> V_29 + V_77 ;
if ( ( F_15 ( V_75 , V_76 ) % V_70 ( V_75 , V_76 ) ) != 0 )
V_72 -> V_31 = 1 ;
}
V_72 -> V_27 = F_19 ( V_72 -> V_27 ,
V_73 -> V_27 ) ;
V_72 -> V_28 = F_19 ( V_72 -> V_28 ,
V_73 -> V_28 ) ;
V_72 -> V_29 = F_15 ( V_72 -> V_29 ,
V_73 -> V_29 ) ;
V_72 -> V_30 = F_39 ( V_72 -> V_30 , V_77 ) %
V_72 -> V_29 ;
}
if ( V_73 -> V_24 )
V_72 -> V_24 = F_19 ( V_72 -> V_24 ,
V_73 -> V_24 ) ;
return V_78 ;
}
int F_41 ( struct V_9 * V_72 , struct V_80 * V_81 ,
T_8 V_74 )
{
struct V_1 * V_82 = F_42 ( V_81 ) ;
V_74 += F_43 ( V_81 ) ;
return F_37 ( V_72 , & V_82 -> V_51 , V_74 ) ;
}
void F_44 ( struct V_83 * V_84 , struct V_80 * V_81 ,
T_8 V_69 )
{
struct V_1 * V_72 = V_84 -> V_85 ;
if ( F_41 ( & V_72 -> V_51 , V_81 , V_69 >> 9 ) < 0 ) {
char V_75 [ V_86 ] , V_76 [ V_86 ] ;
F_45 ( V_84 , 0 , V_75 ) ;
F_46 ( V_81 , V_76 ) ;
F_18 ( V_87 L_2 ,
V_75 , V_76 ) ;
}
}
void F_47 ( struct V_1 * V_2 , unsigned int V_88 )
{
V_2 -> V_89 = V_88 ;
}
void F_48 ( struct V_1 * V_2 , unsigned int V_88 )
{
if ( V_88 > V_2 -> V_89 )
V_2 -> V_89 = V_88 ;
}
int F_49 ( struct V_1 * V_2 ,
T_9 * V_90 ,
void * V_91 , unsigned int V_68 )
{
if ( F_50 ( V_2 ) < 2 )
return - V_92 ;
F_26 ( V_2 , F_50 ( V_2 ) - 1 ) ;
V_2 -> V_90 = V_90 ;
V_2 -> V_93 = V_91 ;
V_2 -> V_94 = V_68 ;
return 0 ;
}
void F_51 ( struct V_1 * V_2 , unsigned long V_88 )
{
if ( V_88 < V_62 - 1 ) {
V_88 = V_62 - 1 ;
F_18 ( V_63 L_3 ,
V_64 , V_88 ) ;
}
V_2 -> V_51 . V_15 = V_88 ;
}
void F_52 ( struct V_1 * V_2 , unsigned long V_88 )
{
V_2 -> V_51 . V_17 = V_88 ;
}
void F_11 ( struct V_1 * V_2 , int V_88 )
{
V_2 -> V_95 = V_88 ;
}
void F_53 ( struct V_1 * V_2 , int V_88 )
{
F_21 ( V_88 > V_62 ) ;
if ( V_88 > V_2 -> V_95 )
V_2 -> V_95 = V_88 ;
}
void F_54 ( struct V_1 * V_2 , bool V_96 )
{
F_55 ( V_2 -> V_97 ) ;
if ( V_96 )
F_56 ( V_98 , & V_2 -> V_99 ) ;
else
F_57 ( V_98 , & V_2 -> V_99 ) ;
F_58 ( V_2 -> V_97 ) ;
}
void F_59 ( struct V_1 * V_2 , unsigned int V_100 )
{
V_2 -> V_101 = V_100 ;
F_60 ( V_2 -> V_102 , V_100 ) ;
}
void F_61 ( struct V_1 * V_2 , bool V_103 , bool V_104 )
{
F_55 ( V_2 -> V_97 ) ;
if ( V_103 )
F_62 ( V_105 , V_2 ) ;
else
F_63 ( V_105 , V_2 ) ;
if ( V_104 )
F_62 ( V_106 , V_2 ) ;
else
F_63 ( V_106 , V_2 ) ;
F_58 ( V_2 -> V_97 ) ;
F_64 ( V_2 -> V_102 , F_65 ( V_105 , & V_2 -> V_99 ) ) ;
}
static int T_10 F_66 ( void )
{
V_60 = V_59 - 1 ;
V_107 = V_108 - 1 ;
return 0 ;
}
