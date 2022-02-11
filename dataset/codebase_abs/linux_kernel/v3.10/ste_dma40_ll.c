void F_1 ( struct V_1 * V_2 ,
T_1 * V_3 , T_1 * V_4 )
{
T_1 V_5 = 0 ;
T_1 V_6 = 0 ;
if ( V_2 -> V_7 == V_8 ||
V_2 -> V_7 == V_9 )
V_6 |= 1 << V_10 ;
if ( V_2 -> V_7 == V_11 ||
V_2 -> V_7 == V_9 )
V_5 |= 1 << V_12 ;
if ( V_2 -> V_7 == V_11 ||
V_2 -> V_7 == V_13 )
V_6 |= 1 << V_14 ;
if ( V_2 -> V_7 == V_8 ||
V_2 -> V_7 == V_13 )
V_5 |= 1 << V_15 ;
V_5 |= 1 << V_16 ;
V_5 |= V_2 -> V_17 . V_18 << V_19 ;
V_5 |= V_2 -> V_17 . V_20 << V_21 ;
V_6 |= 1 << V_22 ;
V_6 |= V_2 -> V_23 . V_18 << V_24 ;
V_6 |= V_2 -> V_23 . V_20 << V_25 ;
* V_3 = V_6 ;
* V_4 = V_5 ;
}
void F_2 ( struct V_1 * V_2 ,
T_1 * V_26 , T_1 * V_27 , bool V_28 )
{
T_1 V_29 = 0 ;
T_1 V_30 = 0 ;
if ( ! V_28 ) {
if ( ( V_2 -> V_7 == V_11 ) ||
( V_2 -> V_7 == V_13 ) ) {
V_29 |= 1 << V_31 ;
V_29 |= F_3 ( V_2 -> V_32 ) ;
if ( V_2 -> V_23 . V_33 == V_34 )
V_29 |= 1 << V_35 ;
else
V_29 |= 3 << V_35 ;
}
if ( ( V_2 -> V_7 == V_8 ) ||
( V_2 -> V_7 == V_13 ) ) {
V_30 |= 1 << V_31 ;
V_30 |= F_3 ( V_2 -> V_36 ) ;
if ( V_2 -> V_17 . V_33 == V_34 )
V_30 |= 1 << V_35 ;
else
V_30 |= 3 << V_35 ;
}
V_30 |= 1 << V_37 ;
V_29 |= 1 << V_38 ;
V_30 |= 1 << V_38 ;
if ( V_2 -> V_23 . V_18 != V_39 ) {
V_29 |= 1 << V_40 ;
V_29 |= V_2 -> V_23 . V_18 << V_41 ;
}
if ( V_2 -> V_17 . V_18 != V_39 ) {
V_30 |= 1 << V_40 ;
V_30 |= V_2 -> V_17 . V_18 << V_41 ;
}
V_29 |= V_2 -> V_23 . V_20 << V_42 ;
V_30 |= V_2 -> V_17 . V_20 << V_42 ;
if ( V_2 -> V_43 ) {
V_29 |= 1 << V_44 ;
V_30 |= 1 << V_44 ;
}
} else {
V_30 |= 1 << V_45 ;
V_29 |= 1 << V_45 ;
}
if ( V_2 -> V_23 . V_46 )
V_29 |= 1 << V_47 ;
if ( V_2 -> V_17 . V_46 )
V_30 |= 1 << V_47 ;
* V_26 = V_29 ;
* V_27 = V_30 ;
}
static int F_4 ( struct V_48 * V_49 ,
T_2 V_50 ,
T_1 V_51 ,
T_2 V_52 ,
T_1 V_53 ,
struct V_54 * V_55 ,
unsigned int V_56 )
{
bool V_57 = V_56 & V_58 ;
bool V_59 = V_56 & V_60 ;
unsigned int V_20 = V_55 -> V_20 ;
int V_18 = V_55 -> V_18 ;
int V_61 ;
if ( V_18 == V_39 )
V_61 = 1 ;
else
V_61 = 2 << V_18 ;
if ( ! F_5 ( V_50 , 0x1 << V_20 ) )
return - V_62 ;
if ( V_51 < V_61 * ( 0x1 << V_20 ) )
return - V_62 ;
V_49 -> V_63 = ( V_51 >> V_20 ) << V_64 ;
if ( V_57 )
V_49 -> V_63 |= ( 0x1 << V_20 ) <<
V_65 ;
V_49 -> V_66 = V_50 ;
V_49 -> V_53 = V_53 ;
if ( V_52 == 0 )
V_49 -> V_67 = 0x1 << V_68 ;
else
V_49 -> V_67 = V_52 ;
if ( V_59 )
V_49 -> V_53 |= 0x1 << V_37 ;
else
V_49 -> V_53 &= ~ ( 0x1 << V_37 ) ;
V_49 -> V_67 |= 0 << V_69 ;
return 0 ;
}
static int F_6 ( int V_70 , int V_71 , int V_72 )
{
T_1 V_73 = F_7 ( V_71 , V_72 ) ;
T_1 V_74 = F_8 ( V_71 , V_72 ) ;
T_1 V_75 = F_9 ( V_76 << V_74 , 1 << V_73 ) ;
if ( V_75 > V_76 )
V_75 -= ( 1 << V_73 ) ;
if ( V_70 <= V_75 )
return V_70 ;
if ( V_70 <= 2 * V_75 )
return F_9 ( V_70 / 2 , 1 << V_73 ) ;
return V_75 ;
}
static struct V_48 *
F_10 ( struct V_48 * V_49 , T_2 V_77 , T_1 V_70 ,
T_2 V_78 , T_2 V_79 , T_1 V_53 ,
struct V_54 * V_55 ,
struct V_54 * V_80 ,
unsigned long V_56 )
{
bool V_81 = V_56 & V_82 ;
bool V_57 = V_56 & V_58 ;
bool V_59 = V_56 & V_60 ;
bool V_83 = V_56 & V_84 ;
int V_85 ;
T_2 V_86 = V_78 ;
int V_87 = V_70 ;
int V_88 = 0 ;
if ( V_59 )
V_56 &= ~ V_60 ;
do {
V_88 = F_6 ( V_87 , V_55 -> V_20 ,
V_80 -> V_20 ) ;
V_87 -= V_88 ;
if ( V_87 == 0 && V_59 )
V_56 |= V_60 ;
if ( V_87 == 0 && V_81 )
V_86 = V_83 ? V_79 : 0 ;
else
V_86 = F_9 ( V_86 + sizeof( struct V_48 ) ,
V_89 ) ;
V_85 = F_4 ( V_49 , V_77 , V_88 , V_86 ,
V_53 , V_55 , V_56 ) ;
if ( V_85 )
goto V_85;
V_49 ++ ;
if ( V_57 )
V_77 += V_88 ;
} while ( V_87 );
return V_49 ;
V_85:
return NULL ;
}
int F_11 ( struct V_90 * V_91 ,
int V_92 ,
T_2 V_93 ,
struct V_48 * V_94 ,
T_2 V_78 ,
T_1 V_53 ,
struct V_54 * V_55 ,
struct V_54 * V_80 ,
unsigned long V_56 )
{
int V_95 = 0 ;
int V_96 ;
struct V_90 * V_97 = V_91 ;
struct V_48 * V_49 = V_94 ;
T_2 V_98 = V_78 ;
if ( ! V_93 )
V_56 |= V_58 ;
F_12 (sg, current_sg, sg_len, i) {
T_2 V_99 = F_13 ( V_97 ) ;
unsigned int V_100 = F_14 ( V_97 ) ;
T_2 V_30 = V_93 ? : V_99 ;
V_95 += F_14 ( V_97 ) ;
if ( V_96 == V_92 - 1 )
V_56 |= V_60 | V_82 ;
V_98 = F_9 ( V_78 + ( V_49 - V_94 ) *
sizeof( struct V_48 ) , V_89 ) ;
V_49 = F_10 ( V_49 , V_30 , V_100 , V_98 , V_78 ,
V_53 , V_55 , V_80 , V_56 ) ;
if ( V_49 == NULL )
return - V_62 ;
}
return V_95 ;
}
static void F_15 ( struct V_101 * V_102 ,
struct V_101 * V_103 ,
int V_86 , unsigned int V_56 )
{
bool V_104 = V_56 & V_60 ;
T_1 V_105 = 0 ;
T_1 V_106 = 0 ;
if ( V_86 != - V_62 ) {
V_105 = V_86 * 2 ;
V_106 = V_86 * 2 + 1 ;
}
if ( V_104 ) {
V_102 -> V_107 |= V_108 ;
V_102 -> V_107 |= V_109 ;
}
V_103 -> V_107 = ( V_103 -> V_107 & ~ V_110 ) |
( V_105 << V_111 ) ;
V_102 -> V_107 = ( V_102 -> V_107 & ~ V_110 ) |
( V_106 << V_111 ) ;
}
void F_16 ( struct V_112 * V_113 ,
struct V_101 * V_102 ,
struct V_101 * V_103 ,
int V_86 , unsigned int V_56 )
{
F_15 ( V_102 , V_103 , V_86 , V_56 ) ;
F_17 ( V_103 -> V_114 , & V_113 [ 0 ] . V_115 ) ;
F_17 ( V_103 -> V_107 , & V_113 [ 0 ] . V_3 ) ;
F_17 ( V_102 -> V_114 , & V_113 [ 0 ] . V_116 ) ;
F_17 ( V_102 -> V_107 , & V_113 [ 0 ] . V_4 ) ;
}
void F_18 ( struct V_101 * V_117 ,
struct V_101 * V_102 ,
struct V_101 * V_103 ,
int V_86 , unsigned int V_56 )
{
F_15 ( V_102 , V_103 , V_86 , V_56 ) ;
F_17 ( V_103 -> V_114 , & V_117 [ 0 ] . V_114 ) ;
F_17 ( V_103 -> V_107 , & V_117 [ 0 ] . V_107 ) ;
F_17 ( V_102 -> V_114 , & V_117 [ 1 ] . V_114 ) ;
F_17 ( V_102 -> V_107 , & V_117 [ 1 ] . V_107 ) ;
}
static void F_19 ( struct V_101 * V_49 ,
T_2 V_50 , T_1 V_51 ,
T_1 V_53 ,
T_1 V_20 ,
unsigned int V_56 )
{
bool V_57 = V_56 & V_58 ;
V_49 -> V_107 = V_53 ;
V_49 -> V_114 = ( ( V_51 >> V_20 ) <<
V_118 ) & V_119 ;
F_20 ( ( V_51 >> V_20 ) > V_76 ) ;
V_49 -> V_114 |= V_50 & V_120 ;
V_49 -> V_107 |= V_50 & V_121 ;
if ( V_57 )
V_49 -> V_107 |= V_122 ;
}
static struct V_101 * F_21 ( struct V_101 * V_94 ,
T_2 V_77 ,
int V_70 ,
T_1 V_107 ,
T_1 V_71 ,
T_1 V_72 ,
unsigned int V_56 )
{
bool V_57 = V_56 & V_58 ;
struct V_101 * V_49 = V_94 ;
int V_87 = V_70 ;
int V_88 = 0 ;
do {
V_88 = F_6 ( V_87 , V_71 , V_72 ) ;
V_87 -= V_88 ;
F_19 ( V_49 ,
V_77 ,
V_88 ,
V_107 , V_71 ,
V_56 ) ;
if ( V_57 )
V_77 += V_88 ;
V_49 ++ ;
} while ( V_87 );
return V_49 ;
}
int F_22 ( struct V_90 * V_91 ,
int V_92 ,
T_2 V_123 ,
struct V_101 * V_94 ,
T_1 V_107 ,
T_1 V_71 , T_1 V_72 )
{
int V_95 = 0 ;
struct V_90 * V_97 = V_91 ;
int V_96 ;
struct V_101 * V_49 = V_94 ;
unsigned long V_56 = 0 ;
if ( ! V_123 )
V_56 |= V_58 ;
F_12 (sg, current_sg, sg_len, i) {
T_2 V_99 = F_13 ( V_97 ) ;
unsigned int V_100 = F_14 ( V_97 ) ;
T_2 V_77 = V_123 ? : V_99 ;
V_95 += F_14 ( V_97 ) ;
V_49 = F_21 ( V_49 , V_77 , V_100 ,
V_107 ,
V_71 ,
V_72 ,
V_56 ) ;
}
return V_95 ;
}
