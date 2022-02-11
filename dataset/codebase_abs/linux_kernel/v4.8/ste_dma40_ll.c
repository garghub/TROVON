static T_1 F_1 ( enum V_1 V_2 )
{
if ( V_2 == V_3 )
return V_4 ;
else if ( V_2 == V_5 )
return V_6 ;
else if ( V_2 == V_7 )
return V_8 ;
else
return V_9 ;
}
void F_2 ( struct V_10 * V_11 ,
T_2 * V_12 , T_2 * V_13 )
{
T_2 V_14 = 0 ;
T_2 V_15 = 0 ;
if ( V_11 -> V_16 == V_17 ||
V_11 -> V_16 == V_18 )
V_15 |= F_3 ( V_19 ) ;
if ( V_11 -> V_16 == V_20 ||
V_11 -> V_16 == V_18 )
V_14 |= F_3 ( V_21 ) ;
if ( V_11 -> V_16 == V_20 ||
V_11 -> V_16 == V_22 )
V_15 |= F_3 ( V_23 ) ;
if ( V_11 -> V_16 == V_17 ||
V_11 -> V_16 == V_22 )
V_14 |= F_3 ( V_24 ) ;
V_14 |= F_3 ( V_25 ) ;
V_14 |= V_11 -> V_26 . V_27 << V_28 ;
V_14 |= F_1 ( V_11 -> V_26 . V_29 )
<< V_30 ;
V_15 |= F_3 ( V_31 ) ;
V_15 |= V_11 -> V_32 . V_27 << V_33 ;
V_15 |= F_1 ( V_11 -> V_32 . V_29 )
<< V_34 ;
* V_12 = V_15 ;
* V_13 = V_14 ;
}
void F_4 ( struct V_10 * V_11 , T_2 * V_35 , T_2 * V_36 )
{
T_2 V_37 = 0 ;
T_2 V_38 = 0 ;
if ( ( V_11 -> V_16 == V_20 ) ||
( V_11 -> V_16 == V_22 ) ) {
V_37 |= F_3 ( V_39 ) ;
V_37 |= F_5 ( V_11 -> V_40 ) ;
if ( V_11 -> V_32 . V_41 == V_42 )
V_37 |= F_3 ( V_43 ) ;
else
V_37 |= 3 << V_43 ;
}
if ( ( V_11 -> V_16 == V_17 ) ||
( V_11 -> V_16 == V_22 ) ) {
V_38 |= F_3 ( V_39 ) ;
V_38 |= F_5 ( V_11 -> V_40 ) ;
if ( V_11 -> V_26 . V_41 == V_42 )
V_38 |= F_3 ( V_43 ) ;
else
V_38 |= 3 << V_43 ;
}
V_38 |= F_3 ( V_44 ) ;
V_37 |= F_3 ( V_45 ) ;
V_38 |= F_3 ( V_45 ) ;
if ( V_11 -> V_32 . V_27 != V_46 ) {
V_37 |= F_3 ( V_47 ) ;
V_37 |= V_11 -> V_32 . V_27 << V_48 ;
}
if ( V_11 -> V_26 . V_27 != V_46 ) {
V_38 |= F_3 ( V_47 ) ;
V_38 |= V_11 -> V_26 . V_27 << V_48 ;
}
V_37 |= F_1 ( V_11 -> V_32 . V_29 )
<< V_49 ;
V_38 |= F_1 ( V_11 -> V_26 . V_29 )
<< V_49 ;
if ( V_11 -> V_50 ) {
V_37 |= F_3 ( V_51 ) ;
V_38 |= F_3 ( V_51 ) ;
}
if ( V_11 -> V_32 . V_52 )
V_37 |= F_3 ( V_53 ) ;
if ( V_11 -> V_26 . V_52 )
V_38 |= F_3 ( V_53 ) ;
* V_35 = V_37 ;
* V_36 = V_38 ;
}
static int F_6 ( struct V_54 * V_55 ,
T_3 V_56 ,
T_2 V_57 ,
T_3 V_58 ,
T_2 V_59 ,
struct V_60 * V_61 ,
unsigned int V_62 )
{
bool V_63 = V_62 & V_64 ;
bool V_65 = V_62 & V_66 ;
unsigned int V_29 = V_61 -> V_29 ;
int V_27 = V_61 -> V_27 ;
int V_67 ;
if ( V_27 == V_46 )
V_67 = 1 ;
else
V_67 = 2 << V_27 ;
if ( ! F_7 ( V_56 , V_29 ) )
return - V_68 ;
if ( V_57 < V_67 * V_29 )
return - V_68 ;
V_55 -> V_69 = ( V_57 / V_29 ) << V_70 ;
if ( V_63 )
V_55 -> V_69 |= V_29 << V_71 ;
V_55 -> V_72 = V_56 ;
V_55 -> V_59 = V_59 ;
if ( V_58 == 0 )
V_55 -> V_73 = F_3 ( V_74 ) ;
else
V_55 -> V_73 = V_58 ;
if ( V_65 )
V_55 -> V_59 |= F_3 ( V_44 ) ;
else
V_55 -> V_59 &= ~ F_3 ( V_44 ) ;
return 0 ;
}
static int F_8 ( int V_75 , int V_76 , int V_77 )
{
T_2 V_78 = F_9 ( V_76 , V_77 ) ;
T_2 V_79 = F_10 ( V_76 , V_77 ) ;
T_2 V_80 = F_11 ( V_81 * V_79 , V_78 ) ;
if ( V_80 > V_81 )
V_80 -= V_78 ;
if ( V_75 <= V_80 )
return V_75 ;
if ( V_75 <= 2 * V_80 )
return F_11 ( V_75 / 2 , V_78 ) ;
return V_80 ;
}
static struct V_54 *
F_12 ( struct V_54 * V_55 , T_3 V_82 , T_2 V_75 ,
T_3 V_83 , T_3 V_84 , T_2 V_59 ,
struct V_60 * V_61 ,
struct V_60 * V_85 ,
unsigned long V_62 )
{
bool V_86 = V_62 & V_87 ;
bool V_63 = V_62 & V_64 ;
bool V_65 = V_62 & V_66 ;
bool V_88 = V_62 & V_89 ;
int V_90 ;
T_3 V_91 = V_83 ;
int V_92 = V_75 ;
int V_93 = 0 ;
if ( V_65 )
V_62 &= ~ V_66 ;
do {
V_93 = F_8 ( V_92 , V_61 -> V_29 ,
V_85 -> V_29 ) ;
V_92 -= V_93 ;
if ( V_92 == 0 && V_65 )
V_62 |= V_66 ;
if ( V_92 == 0 && V_86 )
V_91 = V_88 ? V_84 : 0 ;
else
V_91 = F_11 ( V_91 + sizeof( struct V_54 ) ,
V_94 ) ;
V_90 = F_6 ( V_55 , V_82 , V_93 , V_91 ,
V_59 , V_61 , V_62 ) ;
if ( V_90 )
goto V_90;
V_55 ++ ;
if ( V_63 )
V_82 += V_93 ;
} while ( V_92 );
return V_55 ;
V_90:
return NULL ;
}
int F_13 ( struct V_95 * V_96 ,
int V_97 ,
T_3 V_98 ,
struct V_54 * V_99 ,
T_3 V_83 ,
T_2 V_59 ,
struct V_60 * V_61 ,
struct V_60 * V_85 ,
unsigned long V_62 )
{
int V_100 = 0 ;
int V_101 ;
struct V_95 * V_102 = V_96 ;
struct V_54 * V_55 = V_99 ;
T_3 V_103 = V_83 ;
if ( ! V_98 )
V_62 |= V_64 ;
F_14 (sg, current_sg, sg_len, i) {
T_3 V_104 = F_15 ( V_102 ) ;
unsigned int V_105 = F_16 ( V_102 ) ;
T_3 V_38 = V_98 ? : V_104 ;
V_100 += F_16 ( V_102 ) ;
if ( V_101 == V_97 - 1 )
V_62 |= V_66 | V_87 ;
V_103 = F_11 ( V_83 + ( V_55 - V_99 ) *
sizeof( struct V_54 ) , V_94 ) ;
V_55 = F_12 ( V_55 , V_38 , V_105 , V_103 , V_83 ,
V_59 , V_61 , V_85 , V_62 ) ;
if ( V_55 == NULL )
return - V_68 ;
}
return V_100 ;
}
static void F_17 ( struct V_106 * V_107 ,
struct V_106 * V_108 ,
int V_91 , unsigned int V_62 )
{
bool V_109 = V_62 & V_66 ;
T_2 V_110 = 0 ;
T_2 V_111 = 0 ;
if ( V_91 != - V_68 ) {
V_110 = V_91 * 2 ;
V_111 = V_91 * 2 + 1 ;
}
if ( V_109 ) {
V_107 -> V_112 |= V_113 ;
V_107 -> V_112 |= V_114 ;
}
V_108 -> V_112 = ( V_108 -> V_112 & ~ V_115 ) |
( V_110 << V_116 ) ;
V_107 -> V_112 = ( V_107 -> V_112 & ~ V_115 ) |
( V_111 << V_116 ) ;
}
void F_18 ( struct V_117 * V_118 ,
struct V_106 * V_107 ,
struct V_106 * V_108 ,
int V_91 , unsigned int V_62 )
{
F_17 ( V_107 , V_108 , V_91 , V_62 ) ;
F_19 ( V_108 -> V_119 , & V_118 [ 0 ] . V_120 ) ;
F_19 ( V_108 -> V_112 , & V_118 [ 0 ] . V_12 ) ;
F_19 ( V_107 -> V_119 , & V_118 [ 0 ] . V_121 ) ;
F_19 ( V_107 -> V_112 , & V_118 [ 0 ] . V_13 ) ;
}
void F_20 ( struct V_106 * V_122 ,
struct V_106 * V_107 ,
struct V_106 * V_108 ,
int V_91 , unsigned int V_62 )
{
F_17 ( V_107 , V_108 , V_91 , V_62 ) ;
F_19 ( V_108 -> V_119 , & V_122 [ 0 ] . V_119 ) ;
F_19 ( V_108 -> V_112 , & V_122 [ 0 ] . V_112 ) ;
F_19 ( V_107 -> V_119 , & V_122 [ 1 ] . V_119 ) ;
F_19 ( V_107 -> V_112 , & V_122 [ 1 ] . V_112 ) ;
}
static void F_21 ( struct V_106 * V_55 ,
T_3 V_56 , T_2 V_57 ,
T_2 V_59 ,
T_2 V_29 ,
unsigned int V_62 )
{
bool V_63 = V_62 & V_64 ;
V_55 -> V_112 = V_59 ;
V_55 -> V_119 = ( ( V_57 / V_29 ) <<
V_123 ) & V_124 ;
F_22 ( ( V_57 / V_29 ) > V_81 ) ;
V_55 -> V_119 |= V_56 & V_125 ;
V_55 -> V_112 |= V_56 & V_126 ;
if ( V_63 )
V_55 -> V_112 |= V_127 ;
}
static struct V_106 * F_23 ( struct V_106 * V_99 ,
T_3 V_82 ,
int V_75 ,
T_2 V_112 ,
T_2 V_76 ,
T_2 V_77 ,
unsigned int V_62 )
{
bool V_63 = V_62 & V_64 ;
struct V_106 * V_55 = V_99 ;
int V_92 = V_75 ;
int V_93 = 0 ;
do {
V_93 = F_8 ( V_92 , V_76 , V_77 ) ;
V_92 -= V_93 ;
F_21 ( V_55 ,
V_82 ,
V_93 ,
V_112 , V_76 ,
V_62 ) ;
if ( V_63 )
V_82 += V_93 ;
V_55 ++ ;
} while ( V_92 );
return V_55 ;
}
int F_24 ( struct V_95 * V_96 ,
int V_97 ,
T_3 V_128 ,
struct V_106 * V_99 ,
T_2 V_112 ,
T_2 V_76 , T_2 V_77 )
{
int V_100 = 0 ;
struct V_95 * V_102 = V_96 ;
int V_101 ;
struct V_106 * V_55 = V_99 ;
unsigned long V_62 = 0 ;
if ( ! V_128 )
V_62 |= V_64 ;
F_14 (sg, current_sg, sg_len, i) {
T_3 V_104 = F_15 ( V_102 ) ;
unsigned int V_105 = F_16 ( V_102 ) ;
T_3 V_82 = V_128 ? : V_104 ;
V_100 += F_16 ( V_102 ) ;
V_55 = F_23 ( V_55 , V_82 , V_105 ,
V_112 ,
V_76 ,
V_77 ,
V_62 ) ;
}
return V_100 ;
}
