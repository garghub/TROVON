static inline unsigned long F_1 ( struct V_1 * V_2 ,
unsigned long V_3 )
{
return F_2 ( V_2 -> V_4 + V_3 ) ;
}
static inline void F_3 ( struct V_1 * V_2 ,
unsigned long V_5 , unsigned long V_3 )
{
F_4 ( V_5 , V_2 -> V_4 + V_3 ) ;
}
static int F_5 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = F_6 ( V_7 -> V_8 ) ;
struct V_9 * V_10 = & V_2 -> V_10 ;
int V_11 = 0 , V_12 ;
T_1 V_13 , V_14 , V_15 ;
if ( V_7 -> V_8 -> V_16 ) {
F_7 ( V_2 -> V_17 , L_1 ) ;
return - V_18 ;
}
if ( ! V_2 -> V_19 ) {
F_8 ( V_2 -> V_17 , L_2 ) ;
return - V_20 ;
}
V_14 = F_9 ( V_2 -> V_21 ) ;
V_11 = F_10 ( V_14 , V_2 -> V_19 ) - 1 ;
if ( V_11 < 0 ) {
F_7 ( V_2 -> V_17 , L_3 ) ;
return - V_20 ;
}
if ( V_11 > V_22 ) {
F_7 ( V_2 -> V_17 , L_4 ,
V_22 , V_22 + 1 ) ;
return - V_20 ;
}
F_7 ( V_2 -> V_17 , L_5 ,
V_2 -> V_19 , V_11 ) ;
V_12 = F_11 ( V_2 -> V_17 ) ;
if ( V_12 < 0 ) {
F_8 ( V_2 -> V_17 , L_6 ) ;
return V_12 ;
}
V_13 = F_1 ( V_2 , V_23 ) ;
V_13 &= ~ V_24 ;
F_3 ( V_2 , V_13 , V_23 ) ;
V_15 = V_24 | V_11 ;
F_3 ( V_2 , V_15 , V_23 ) ;
V_10 -> V_25 = V_15 ;
F_12 ( V_2 -> V_17 ) ;
V_12 = F_13 ( V_2 -> V_17 ) ;
if ( V_12 < 0 ) {
F_8 ( V_2 -> V_17 , L_7 ) ;
return V_12 ;
}
return 0 ;
}
static void F_14 ( struct V_1 * V_2 )
{
struct V_9 * V_10 = & V_2 -> V_10 ;
F_3 ( V_2 , V_10 -> V_25 , V_23 ) ;
}
static inline T_1 F_15 ( struct V_1 * V_2 )
{
T_1 V_26 ;
unsigned long V_27 = V_28 + V_29 ;
V_26 = F_1 ( V_2 , V_30 ) ;
while ( ( V_26 & V_31 ) && F_16 ( V_27 , V_28 ) ) {
F_17 () ;
V_26 = F_1 ( V_2 , V_30 ) ;
}
F_18 ( V_26 & V_31 , L_8 ) ;
return V_26 & V_31 ;
}
static inline int F_19 ( struct V_1 * V_2 )
{
T_1 V_26 ;
unsigned long V_27 = V_28 + V_29 ;
do {
V_26 = F_1 ( V_2 , V_30 ) ;
if ( V_26 & V_32 )
return 0 ;
F_17 () ;
} while ( F_16 ( V_27 , V_28 ) );
V_26 = F_1 ( V_2 , V_30 ) ;
if ( V_26 & V_32 )
return 0 ;
return - V_33 ;
}
static int F_20 ( struct V_1 * V_2 , struct V_34 * V_35 ,
int V_36 )
{
int V_37 , V_38 ;
unsigned int V_39 ;
const T_2 * V_40 ;
T_1 V_41 ;
V_40 = V_35 -> V_42 ;
V_39 = V_2 -> V_39 | V_43 ;
V_37 = V_35 -> V_44 >> 3 ;
V_38 = V_37 ;
while ( V_36 ) {
if ( F_15 ( V_2 ) )
return - V_18 ;
switch ( V_37 ) {
case 1 :
F_7 ( V_2 -> V_17 , L_9 ,
V_39 , V_2 -> V_45 , * V_40 ) ;
if ( V_36 >= V_46 ) {
T_1 * V_47 = ( T_1 * ) V_40 ;
V_41 = F_21 ( * V_47 ++ ) ;
F_4 ( V_41 , V_2 -> V_4 +
V_48 ) ;
V_41 = F_21 ( * V_47 ++ ) ;
F_4 ( V_41 , V_2 -> V_4 +
V_49 ) ;
V_41 = F_21 ( * V_47 ++ ) ;
F_4 ( V_41 , V_2 -> V_4 +
V_50 ) ;
V_41 = F_21 ( * V_47 ++ ) ;
F_4 ( V_41 , V_2 -> V_4 +
V_51 ) ;
V_38 = V_46 ;
V_39 |= F_22 ( V_52 ) ;
} else {
F_23 ( * V_40 , V_2 -> V_4 + V_51 ) ;
V_39 = V_2 -> V_39 | V_43 ;
V_38 = V_37 ;
V_39 |= F_22 ( V_37 ) ;
}
break;
case 2 :
F_7 ( V_2 -> V_17 , L_10 ,
V_39 , V_2 -> V_45 , * V_40 ) ;
F_24 ( * ( ( V_53 * ) V_40 ) , V_2 -> V_4 + V_51 ) ;
break;
case 4 :
F_7 ( V_2 -> V_17 , L_11 ,
V_39 , V_2 -> V_45 , * V_40 ) ;
F_4 ( * ( ( T_1 * ) V_40 ) , V_2 -> V_4 + V_51 ) ;
break;
}
F_3 ( V_2 , V_39 , V_54 ) ;
if ( F_19 ( V_2 ) ) {
F_8 ( V_2 -> V_17 , L_12 ) ;
return - V_33 ;
}
V_40 += V_38 ;
V_36 -= V_38 ;
}
return 0 ;
}
static int F_25 ( struct V_1 * V_2 , struct V_34 * V_35 ,
int V_36 )
{
int V_37 ;
unsigned int V_39 ;
T_2 * V_55 ;
V_55 = V_35 -> V_56 ;
V_39 = V_2 -> V_39 ;
switch ( V_35 -> V_57 ) {
case V_58 :
V_39 |= V_59 ;
break;
case V_60 :
V_39 |= V_61 ;
break;
default:
V_39 |= V_62 ;
break;
}
V_37 = V_35 -> V_44 >> 3 ;
while ( V_36 ) {
F_7 ( V_2 -> V_17 , L_13 , V_39 , V_2 -> V_45 ) ;
if ( F_15 ( V_2 ) )
return - V_18 ;
F_3 ( V_2 , V_39 , V_54 ) ;
if ( F_19 ( V_2 ) ) {
F_8 ( V_2 -> V_17 , L_14 ) ;
return - V_33 ;
}
switch ( V_37 ) {
case 1 :
* V_55 = F_26 ( V_2 -> V_4 + V_51 ) ;
break;
case 2 :
* ( ( V_53 * ) V_55 ) = F_27 ( V_2 -> V_4 + V_51 ) ;
break;
case 4 :
* ( ( T_1 * ) V_55 ) = F_2 ( V_2 -> V_4 + V_51 ) ;
break;
}
V_55 += V_37 ;
V_36 -= V_37 ;
}
return 0 ;
}
static int F_28 ( struct V_1 * V_2 , struct V_34 * V_35 ,
int V_36 )
{
int V_12 ;
if ( V_35 -> V_42 ) {
V_12 = F_20 ( V_2 , V_35 , V_36 ) ;
if ( V_12 ) {
F_7 ( V_2 -> V_17 , L_15 ) ;
return V_12 ;
}
}
if ( V_35 -> V_56 ) {
V_12 = F_25 ( V_2 , V_35 , V_36 ) ;
if ( V_12 ) {
F_7 ( V_2 -> V_17 , L_16 ) ;
return V_12 ;
}
}
return 0 ;
}
static void F_29 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = F_6 ( V_7 -> V_8 ) ;
F_3 ( V_2 , V_63 , V_64 ) ;
if ( V_2 -> V_65 ) {
F_30 ( V_2 -> V_65 , V_2 -> V_66 ,
F_31 ( V_7 -> V_67 ) ,
V_68 ) ;
}
V_2 -> V_69 = true ;
}
static void F_32 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = F_6 ( V_7 -> V_8 ) ;
F_3 ( V_2 , 0 , V_64 ) ;
if ( V_2 -> V_65 )
F_30 ( V_2 -> V_65 , V_2 -> V_66 ,
0 , V_68 ) ;
V_2 -> V_69 = false ;
}
static void F_33 ( struct V_6 * V_7 ,
struct V_70 * V_71 )
{
struct V_1 * V_2 = F_6 ( V_7 -> V_8 ) ;
T_1 V_72 = V_71 -> V_73 ;
switch ( V_71 -> V_74 ) {
case V_60 :
V_72 |= V_75 ;
break;
case V_58 :
V_72 |= V_76 ;
break;
default:
V_72 |= V_77 ;
break;
}
V_72 |= ( ( V_71 -> V_78 - 1 ) << V_79 |
V_71 -> V_80 << V_81 ) ;
F_3 ( V_2 , V_72 ,
F_34 ( V_7 -> V_67 ) ) ;
}
static int F_35 ( struct V_6 * V_7 ,
struct V_70 * V_71 )
{
struct V_1 * V_2 = F_6 ( V_7 -> V_8 ) ;
int V_12 = 0 ;
F_36 ( & V_2 -> V_82 ) ;
if ( ! V_2 -> V_69 )
F_29 ( V_7 ) ;
F_33 ( V_7 , V_71 ) ;
F_37 ( V_71 -> V_83 , V_2 -> V_84 + V_71 -> V_85 , V_71 -> V_86 ) ;
V_71 -> V_87 = V_71 -> V_86 ;
F_38 ( & V_2 -> V_82 ) ;
return V_12 ;
}
static int F_39 ( struct V_88 * V_8 ,
struct V_89 * V_90 )
{
struct V_1 * V_2 = F_6 ( V_8 ) ;
struct V_6 * V_7 = V_90 -> V_7 ;
struct V_34 * V_35 ;
int V_91 = 0 , V_12 ;
unsigned int V_92 , V_93 ;
int V_37 ;
V_2 -> V_45 = 0 ;
if ( V_7 -> V_94 & V_95 )
V_2 -> V_45 |= F_40 ( V_7 -> V_67 ) ;
if ( V_7 -> V_94 & V_96 )
V_2 -> V_45 |= F_41 ( V_7 -> V_67 ) ;
if ( V_7 -> V_94 & V_97 )
V_2 -> V_45 |= F_42 ( V_7 -> V_67 ) ;
V_92 = 0 ;
F_43 (t, &m->transfers, transfer_list)
V_92 += V_35 -> V_86 / ( V_35 -> V_44 >> 3 ) ;
V_92 = F_44 (unsigned int, frame_len_words, QSPI_FRAME) ;
V_2 -> V_39 = 0 ;
V_2 -> V_39 |= F_45 ( V_7 -> V_67 ) ;
V_2 -> V_39 |= F_46 ( V_92 ) ;
F_3 ( V_2 , V_2 -> V_45 , V_98 ) ;
F_36 ( & V_2 -> V_82 ) ;
if ( V_2 -> V_69 )
F_32 ( V_7 ) ;
F_43 (t, &m->transfers, transfer_list) {
V_2 -> V_39 = ( ( V_2 -> V_39 & ~ V_99 ) |
F_22 ( V_35 -> V_44 ) ) ;
V_37 = V_35 -> V_44 >> 3 ;
V_93 = F_47 ( V_35 -> V_86 / V_37 , V_92 ) ;
V_12 = F_28 ( V_2 , V_35 , V_93 * V_37 ) ;
if ( V_12 ) {
F_7 ( V_2 -> V_17 , L_17 ) ;
F_38 ( & V_2 -> V_82 ) ;
return - V_20 ;
}
V_90 -> V_100 += V_93 * V_37 ;
V_92 -= V_93 ;
if ( V_92 == 0 )
break;
}
F_38 ( & V_2 -> V_82 ) ;
F_3 ( V_2 , V_2 -> V_39 | V_101 , V_54 ) ;
V_90 -> V_91 = V_91 ;
F_48 ( V_8 ) ;
return V_91 ;
}
static int F_49 ( struct V_102 * V_17 )
{
struct V_1 * V_2 ;
V_2 = F_50 ( V_17 ) ;
F_14 ( V_2 ) ;
return 0 ;
}
static int F_51 ( struct V_103 * V_104 )
{
struct V_1 * V_2 ;
struct V_88 * V_8 ;
struct V_105 * V_106 , * V_107 ;
struct V_108 * V_109 = V_104 -> V_17 . V_110 ;
T_1 V_111 ;
int V_12 = 0 , V_112 , V_113 ;
V_8 = F_52 ( & V_104 -> V_17 , sizeof( * V_2 ) ) ;
if ( ! V_8 )
return - V_114 ;
V_8 -> V_115 = V_96 | V_95 | V_116 | V_117 ;
V_8 -> V_118 = V_119 ;
V_8 -> V_120 = F_5 ;
V_8 -> V_121 = true ;
V_8 -> V_122 = F_39 ;
V_8 -> V_17 . V_110 = V_104 -> V_17 . V_110 ;
V_8 -> V_123 = F_53 ( 32 ) | F_53 ( 16 ) |
F_53 ( 8 ) ;
if ( ! F_54 ( V_109 , L_18 , & V_112 ) )
V_8 -> V_124 = V_112 ;
V_2 = F_6 ( V_8 ) ;
V_2 -> V_8 = V_8 ;
V_2 -> V_17 = & V_104 -> V_17 ;
F_55 ( V_104 , V_2 ) ;
V_106 = F_56 ( V_104 , V_125 , L_19 ) ;
if ( V_106 == NULL ) {
V_106 = F_57 ( V_104 , V_125 , 0 ) ;
if ( V_106 == NULL ) {
F_8 ( & V_104 -> V_17 , L_20 ) ;
return - V_126 ;
}
}
V_107 = F_56 ( V_104 ,
V_125 , L_21 ) ;
if ( V_107 == NULL ) {
V_107 = F_57 ( V_104 , V_125 , 1 ) ;
if ( V_107 == NULL ) {
F_8 ( & V_104 -> V_17 ,
L_22 ) ;
}
}
V_113 = F_58 ( V_104 , 0 ) ;
if ( V_113 < 0 ) {
F_8 ( & V_104 -> V_17 , L_23 ) ;
return V_113 ;
}
F_59 ( & V_2 -> V_82 ) ;
V_2 -> V_4 = F_60 ( & V_104 -> V_17 , V_106 ) ;
if ( F_61 ( V_2 -> V_4 ) ) {
V_12 = F_62 ( V_2 -> V_4 ) ;
goto V_127;
}
if ( V_107 ) {
V_2 -> V_84 = F_60 ( & V_104 -> V_17 ,
V_107 ) ;
V_8 -> V_128 = F_35 ;
if ( F_61 ( V_2 -> V_84 ) ) {
F_8 ( & V_104 -> V_17 ,
L_24 ) ;
V_8 -> V_128 = NULL ;
}
}
V_2 -> V_69 = false ;
if ( F_63 ( V_109 , L_25 ) ) {
V_2 -> V_65 =
F_64 ( V_109 ,
L_25 ) ;
if ( F_61 ( V_2 -> V_65 ) )
return F_62 ( V_2 -> V_65 ) ;
V_12 = F_65 ( V_109 ,
L_25 ,
1 , & V_2 -> V_66 ) ;
if ( V_12 ) {
F_8 ( & V_104 -> V_17 ,
L_26 ) ;
return V_12 ;
}
}
V_2 -> V_21 = F_66 ( & V_104 -> V_17 , L_27 ) ;
if ( F_61 ( V_2 -> V_21 ) ) {
V_12 = F_62 ( V_2 -> V_21 ) ;
F_8 ( & V_104 -> V_17 , L_28 , V_12 ) ;
}
F_67 ( & V_104 -> V_17 ) ;
F_68 ( & V_104 -> V_17 , V_129 ) ;
F_69 ( & V_104 -> V_17 ) ;
if ( ! F_54 ( V_109 , L_29 , & V_111 ) )
V_2 -> V_19 = V_111 ;
V_12 = F_70 ( & V_104 -> V_17 , V_8 ) ;
if ( V_12 )
goto V_127;
return 0 ;
V_127:
F_71 ( V_8 ) ;
return V_12 ;
}
static int F_72 ( struct V_103 * V_104 )
{
struct V_1 * V_2 = F_73 ( V_104 ) ;
int V_130 ;
V_130 = F_74 ( V_2 -> V_8 ) ;
if ( V_130 )
return V_130 ;
F_75 ( & V_104 -> V_17 ) ;
F_76 ( & V_104 -> V_17 ) ;
return 0 ;
}
