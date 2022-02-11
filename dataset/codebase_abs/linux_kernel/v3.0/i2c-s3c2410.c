static inline int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 -> V_5 ) ;
enum V_6 type ;
type = F_3 ( V_4 ) -> V_7 ;
return type == V_8 ;
}
static inline void F_4 ( struct V_1 * V_2 , int V_9 )
{
F_5 ( V_2 -> V_5 , L_1 , V_9 ) ;
V_2 -> V_10 = 0 ;
V_2 -> V_11 = NULL ;
V_2 -> V_12 ++ ;
V_2 -> V_13 = 0 ;
if ( V_9 )
V_2 -> V_12 = V_9 ;
F_6 ( & V_2 -> V_14 ) ;
}
static inline void F_7 ( struct V_1 * V_2 )
{
unsigned long V_15 ;
V_15 = F_8 ( V_2 -> V_16 + V_17 ) ;
F_9 ( V_15 & ~ V_18 , V_2 -> V_16 + V_17 ) ;
}
static inline void F_10 ( struct V_1 * V_2 )
{
unsigned long V_15 ;
V_15 = F_8 ( V_2 -> V_16 + V_17 ) ;
F_9 ( V_15 | V_18 , V_2 -> V_16 + V_17 ) ;
}
static inline void F_11 ( struct V_1 * V_2 )
{
unsigned long V_15 ;
V_15 = F_8 ( V_2 -> V_16 + V_17 ) ;
F_9 ( V_15 & ~ V_19 , V_2 -> V_16 + V_17 ) ;
}
static inline void F_12 ( struct V_1 * V_2 )
{
unsigned long V_15 ;
V_15 = F_8 ( V_2 -> V_16 + V_17 ) ;
F_9 ( V_15 | V_19 , V_2 -> V_16 + V_17 ) ;
}
static void F_13 ( struct V_1 * V_2 ,
struct V_20 * V_11 )
{
unsigned int V_21 = ( V_11 -> V_21 & 0x7f ) << 1 ;
unsigned long V_22 ;
unsigned long V_23 ;
V_22 = 0 ;
V_22 |= V_24 ;
if ( V_11 -> V_25 & V_26 ) {
V_22 |= V_27 ;
V_21 |= 1 ;
} else
V_22 |= V_28 ;
if ( V_11 -> V_25 & V_29 )
V_21 ^= 1 ;
F_10 ( V_2 ) ;
V_23 = F_8 ( V_2 -> V_16 + V_17 ) ;
F_9 ( V_22 , V_2 -> V_16 + V_30 ) ;
F_5 ( V_2 -> V_5 , L_2 , V_22 , V_21 ) ;
F_14 ( V_21 , V_2 -> V_16 + V_31 ) ;
F_15 ( V_2 -> V_32 ) ;
F_5 ( V_2 -> V_5 , L_3 , V_23 ) ;
F_9 ( V_23 , V_2 -> V_16 + V_17 ) ;
V_22 |= V_33 ;
F_9 ( V_22 , V_2 -> V_16 + V_30 ) ;
}
static inline void F_16 ( struct V_1 * V_2 , int V_9 )
{
unsigned long V_34 = F_8 ( V_2 -> V_16 + V_30 ) ;
F_5 ( V_2 -> V_5 , L_4 ) ;
V_34 &= ~ V_33 ;
F_9 ( V_34 , V_2 -> V_16 + V_30 ) ;
V_2 -> V_35 = V_36 ;
F_4 ( V_2 , V_9 ) ;
F_11 ( V_2 ) ;
}
static inline int F_17 ( struct V_1 * V_2 )
{
return V_2 -> V_12 >= ( V_2 -> V_13 - 1 ) ;
}
static inline int F_18 ( struct V_1 * V_2 )
{
return V_2 -> V_10 == V_2 -> V_11 -> V_37 - 1 ;
}
static inline int F_19 ( struct V_1 * V_2 )
{
return V_2 -> V_10 >= V_2 -> V_11 -> V_37 ;
}
static int F_20 ( struct V_1 * V_2 , unsigned long V_34 )
{
unsigned long V_15 ;
unsigned char V_38 ;
int V_9 = 0 ;
switch ( V_2 -> V_35 ) {
case V_39 :
F_21 ( V_2 -> V_5 , L_5 , V_40 ) ;
goto V_41;
case V_36 :
F_21 ( V_2 -> V_5 , L_6 , V_40 ) ;
F_11 ( V_2 ) ;
goto V_42;
case V_43 :
if ( V_34 & V_44 &&
! ( V_2 -> V_11 -> V_25 & V_45 ) ) {
F_5 ( V_2 -> V_5 , L_7 ) ;
F_16 ( V_2 , - V_46 ) ;
goto V_42;
}
if ( V_2 -> V_11 -> V_25 & V_26 )
V_2 -> V_35 = V_47 ;
else
V_2 -> V_35 = V_48 ;
if ( F_17 ( V_2 ) && V_2 -> V_11 -> V_37 == 0 ) {
F_16 ( V_2 , 0 ) ;
goto V_42;
}
if ( V_2 -> V_35 == V_47 )
goto V_49;
case V_48 :
if ( ! ( V_2 -> V_11 -> V_25 & V_45 ) ) {
if ( V_34 & V_44 ) {
F_5 ( V_2 -> V_5 , L_8 ) ;
F_16 ( V_2 , - V_50 ) ;
goto V_42;
}
}
V_51:
if ( ! F_19 ( V_2 ) ) {
V_38 = V_2 -> V_11 -> V_52 [ V_2 -> V_10 ++ ] ;
F_14 ( V_38 , V_2 -> V_16 + V_31 ) ;
F_15 ( V_2 -> V_32 ) ;
} else if ( ! F_17 ( V_2 ) ) {
F_5 ( V_2 -> V_5 , L_9 ) ;
V_2 -> V_10 = 0 ;
V_2 -> V_12 ++ ;
V_2 -> V_11 ++ ;
if ( V_2 -> V_11 -> V_25 & V_53 ) {
if ( V_2 -> V_11 -> V_25 & V_26 ) {
F_16 ( V_2 , - V_54 ) ;
}
goto V_51;
} else {
F_13 ( V_2 , V_2 -> V_11 ) ;
V_2 -> V_35 = V_43 ;
}
} else {
F_16 ( V_2 , 0 ) ;
}
break;
case V_47 :
V_38 = F_22 ( V_2 -> V_16 + V_31 ) ;
V_2 -> V_11 -> V_52 [ V_2 -> V_10 ++ ] = V_38 ;
V_49:
if ( F_18 ( V_2 ) ) {
if ( F_17 ( V_2 ) )
F_7 ( V_2 ) ;
} else if ( F_19 ( V_2 ) ) {
if ( F_17 ( V_2 ) ) {
F_5 ( V_2 -> V_5 , L_10 ) ;
F_16 ( V_2 , 0 ) ;
} else {
F_5 ( V_2 -> V_5 , L_11 ) ;
V_2 -> V_10 = 0 ;
V_2 -> V_12 ++ ;
V_2 -> V_11 ++ ;
}
}
break;
}
V_42:
V_15 = F_8 ( V_2 -> V_16 + V_17 ) ;
V_15 &= ~ V_55 ;
F_9 ( V_15 , V_2 -> V_16 + V_17 ) ;
V_41:
return V_9 ;
}
static T_1 F_23 ( int V_56 , void * V_57 )
{
struct V_1 * V_2 = V_57 ;
unsigned long V_58 ;
unsigned long V_15 ;
V_58 = F_8 ( V_2 -> V_16 + V_30 ) ;
if ( V_58 & V_59 ) {
F_21 ( V_2 -> V_5 , L_12 ) ;
}
if ( V_2 -> V_35 == V_39 ) {
F_5 ( V_2 -> V_5 , L_13 ) ;
V_15 = F_8 ( V_2 -> V_16 + V_17 ) ;
V_15 &= ~ V_55 ;
F_9 ( V_15 , V_2 -> V_16 + V_17 ) ;
goto V_41;
}
F_20 ( V_2 , V_58 ) ;
V_41:
return V_60 ;
}
static int F_24 ( struct V_1 * V_2 )
{
unsigned long V_34 ;
int V_61 = 400 ;
while ( V_61 -- > 0 ) {
V_34 = F_8 ( V_2 -> V_16 + V_30 ) ;
if ( ! ( V_34 & V_62 ) )
return 0 ;
F_25 ( 1 ) ;
}
return - V_63 ;
}
static int F_26 ( struct V_1 * V_2 ,
struct V_20 * V_64 , int V_65 )
{
unsigned long V_34 , V_61 ;
int V_66 = 20 ;
int V_9 ;
if ( V_2 -> V_67 )
return - V_68 ;
V_9 = F_24 ( V_2 ) ;
if ( V_9 != 0 ) {
F_21 ( V_2 -> V_5 , L_14 , V_9 ) ;
V_9 = - V_69 ;
goto V_41;
}
F_27 ( & V_2 -> V_70 ) ;
V_2 -> V_11 = V_64 ;
V_2 -> V_13 = V_65 ;
V_2 -> V_10 = 0 ;
V_2 -> V_12 = 0 ;
V_2 -> V_35 = V_43 ;
F_12 ( V_2 ) ;
F_13 ( V_2 , V_64 ) ;
F_28 ( & V_2 -> V_70 ) ;
V_61 = F_29 ( V_2 -> V_14 , V_2 -> V_13 == 0 , V_71 * 5 ) ;
V_9 = V_2 -> V_12 ;
if ( V_61 == 0 )
F_5 ( V_2 -> V_5 , L_15 ) ;
else if ( V_9 != V_65 )
F_5 ( V_2 -> V_5 , L_16 , V_9 ) ;
F_5 ( V_2 -> V_5 , L_17 ) ;
do {
V_34 = F_8 ( V_2 -> V_16 + V_30 ) ;
} while ( ( V_34 & V_33 ) && -- V_66 );
if ( ! V_66 ) {
F_25 ( 1 ) ;
V_34 = F_8 ( V_2 -> V_16 + V_30 ) ;
}
if ( V_34 & V_33 )
F_30 ( V_2 -> V_5 , L_18 ) ;
V_41:
return V_9 ;
}
static int F_31 ( struct V_72 * V_73 ,
struct V_20 * V_64 , int V_65 )
{
struct V_1 * V_2 = (struct V_1 * ) V_73 -> V_74 ;
int V_75 ;
int V_9 ;
F_32 ( V_2 -> V_76 ) ;
for ( V_75 = 0 ; V_75 < V_73 -> V_77 ; V_75 ++ ) {
V_9 = F_26 ( V_2 , V_64 , V_65 ) ;
if ( V_9 != - V_69 ) {
F_33 ( V_2 -> V_76 ) ;
return V_9 ;
}
F_5 ( V_2 -> V_5 , L_19 , V_75 ) ;
F_34 ( 100 ) ;
}
F_33 ( V_2 -> V_76 ) ;
return - V_78 ;
}
static T_2 F_35 ( struct V_72 * V_73 )
{
return V_79 | V_80 | V_81 ;
}
static int F_36 ( unsigned long V_82 , unsigned int V_83 ,
unsigned int * V_84 , unsigned int * V_85 )
{
unsigned int V_86 = V_82 / V_83 ;
unsigned int V_87 ;
if ( V_86 > ( 16 * 16 ) )
V_87 = 512 ;
else
V_87 = 16 ;
V_86 += V_87 - 1 ;
V_86 /= V_87 ;
if ( V_86 == 0 )
V_86 = 1 ;
if ( V_86 > 17 )
V_86 = 17 ;
* V_85 = V_86 ;
* V_84 = V_87 ;
return V_82 / ( V_86 * V_87 ) ;
}
static int F_37 ( struct V_1 * V_2 , unsigned int * V_88 )
{
struct V_89 * V_90 = V_2 -> V_5 -> V_91 ;
unsigned long V_82 = F_38 ( V_2 -> V_76 ) ;
unsigned int V_85 , V_84 ;
unsigned long V_92 ;
T_2 V_23 ;
int V_93 ;
V_2 -> V_94 = V_82 ;
V_82 /= 1000 ;
F_5 ( V_2 -> V_5 , L_20 , V_90 -> V_95 ) ;
V_92 = V_90 -> V_95 ? V_90 -> V_95 : 100000 ;
V_92 /= 1000 ;
V_93 = F_36 ( V_82 , V_92 , & V_84 , & V_85 ) ;
if ( V_93 > V_92 ) {
F_21 ( V_2 -> V_5 ,
L_21 \
L_22 , V_92 , V_93 ) ;
return - V_54 ;
}
* V_88 = V_93 ;
V_23 = F_8 ( V_2 -> V_16 + V_17 ) ;
V_23 &= ~ ( V_96 | V_97 ) ;
V_23 |= ( V_85 - 1 ) ;
if ( V_84 == 512 )
V_23 |= V_97 ;
F_9 ( V_23 , V_2 -> V_16 + V_17 ) ;
if ( F_1 ( V_2 ) ) {
unsigned long V_98 ;
if ( V_90 -> V_98 ) {
V_98 = V_82 * V_90 -> V_98 ;
V_98 = F_39 ( V_98 , 1000000 ) ;
V_98 = F_39 ( V_98 , 5 ) ;
if ( V_98 > 3 )
V_98 = 3 ;
V_98 |= V_99 ;
} else
V_98 = 0 ;
F_5 ( V_2 -> V_5 , L_23 , V_98 ) ;
F_9 ( V_98 , V_2 -> V_16 + V_100 ) ;
}
return 0 ;
}
static int F_40 ( struct V_101 * V_102 ,
unsigned long V_103 , void * V_104 )
{
struct V_1 * V_2 = F_41 ( V_102 ) ;
unsigned long V_25 ;
unsigned int V_88 ;
int V_105 ;
int V_9 ;
V_105 = F_38 ( V_2 -> V_76 ) - V_2 -> V_94 ;
if ( ( V_103 == V_106 && V_105 < 0 ) ||
( V_103 == V_107 && V_105 > 0 ) ) {
F_42 ( & V_2 -> V_70 , V_25 ) ;
V_9 = F_37 ( V_2 , & V_88 ) ;
F_43 ( & V_2 -> V_70 , V_25 ) ;
if ( V_9 < 0 )
F_21 ( V_2 -> V_5 , L_24 ) ;
else
F_44 ( V_2 -> V_5 , L_25 , V_88 ) ;
}
return 0 ;
}
static inline int F_45 ( struct V_1 * V_2 )
{
V_2 -> V_108 . V_109 = F_40 ;
return F_46 ( & V_2 -> V_108 ,
V_110 ) ;
}
static inline void F_47 ( struct V_1 * V_2 )
{
F_48 ( & V_2 -> V_108 ,
V_110 ) ;
}
static inline int F_45 ( struct V_1 * V_2 )
{
return 0 ;
}
static inline void F_47 ( struct V_1 * V_2 )
{
}
static int F_49 ( struct V_1 * V_2 )
{
unsigned long V_111 = V_19 | V_18 ;
struct V_89 * V_90 ;
unsigned int V_93 ;
V_90 = V_2 -> V_5 -> V_91 ;
if ( V_90 -> V_112 )
V_90 -> V_112 ( F_2 ( V_2 -> V_5 ) ) ;
F_14 ( V_90 -> V_113 , V_2 -> V_16 + V_114 ) ;
F_44 ( V_2 -> V_5 , L_26 , V_90 -> V_113 ) ;
F_9 ( V_111 , V_2 -> V_16 + V_17 ) ;
if ( F_37 ( V_2 , & V_93 ) != 0 ) {
F_9 ( 0 , V_2 -> V_16 + V_17 ) ;
F_21 ( V_2 -> V_5 , L_27 ) ;
return - V_54 ;
}
F_44 ( V_2 -> V_5 , L_28 , V_93 ) ;
F_5 ( V_2 -> V_5 , L_29 , V_111 ) ;
return 0 ;
}
static int F_50 ( struct V_3 * V_4 )
{
struct V_1 * V_2 ;
struct V_89 * V_90 ;
struct V_115 * V_116 ;
int V_9 ;
V_90 = V_4 -> V_5 . V_91 ;
if ( ! V_90 ) {
F_21 ( & V_4 -> V_5 , L_30 ) ;
return - V_54 ;
}
V_2 = F_51 ( sizeof( struct V_1 ) , V_117 ) ;
if ( ! V_2 ) {
F_21 ( & V_4 -> V_5 , L_31 ) ;
return - V_118 ;
}
F_52 ( V_2 -> V_73 . V_119 , L_32 , sizeof( V_2 -> V_73 . V_119 ) ) ;
V_2 -> V_73 . V_120 = V_121 ;
V_2 -> V_73 . V_122 = & V_123 ;
V_2 -> V_73 . V_77 = 2 ;
V_2 -> V_73 . V_124 = V_125 | V_126 ;
V_2 -> V_32 = 50 ;
F_53 ( & V_2 -> V_70 ) ;
F_54 ( & V_2 -> V_14 ) ;
V_2 -> V_5 = & V_4 -> V_5 ;
V_2 -> V_76 = F_55 ( & V_4 -> V_5 , L_33 ) ;
if ( F_56 ( V_2 -> V_76 ) ) {
F_21 ( & V_4 -> V_5 , L_34 ) ;
V_9 = - V_127 ;
goto V_128;
}
F_5 ( & V_4 -> V_5 , L_35 , V_2 -> V_76 ) ;
F_32 ( V_2 -> V_76 ) ;
V_116 = F_57 ( V_4 , V_129 , 0 ) ;
if ( V_116 == NULL ) {
F_21 ( & V_4 -> V_5 , L_36 ) ;
V_9 = - V_127 ;
goto V_130;
}
V_2 -> V_131 = F_58 ( V_116 -> V_132 , F_59 ( V_116 ) ,
V_4 -> V_119 ) ;
if ( V_2 -> V_131 == NULL ) {
F_21 ( & V_4 -> V_5 , L_37 ) ;
V_9 = - V_46 ;
goto V_130;
}
V_2 -> V_16 = F_60 ( V_116 -> V_132 , F_59 ( V_116 ) ) ;
if ( V_2 -> V_16 == NULL ) {
F_21 ( & V_4 -> V_5 , L_38 ) ;
V_9 = - V_46 ;
goto V_133;
}
F_5 ( & V_4 -> V_5 , L_39 ,
V_2 -> V_16 , V_2 -> V_131 , V_116 ) ;
V_2 -> V_73 . V_74 = V_2 ;
V_2 -> V_73 . V_5 . V_134 = & V_4 -> V_5 ;
V_9 = F_49 ( V_2 ) ;
if ( V_9 != 0 )
goto V_135;
V_2 -> V_136 = V_9 = F_61 ( V_4 , 0 ) ;
if ( V_9 <= 0 ) {
F_21 ( & V_4 -> V_5 , L_40 ) ;
goto V_135;
}
V_9 = F_62 ( V_2 -> V_136 , F_23 , V_137 ,
F_63 ( & V_4 -> V_5 ) , V_2 ) ;
if ( V_9 != 0 ) {
F_21 ( & V_4 -> V_5 , L_41 , V_2 -> V_136 ) ;
goto V_135;
}
V_9 = F_45 ( V_2 ) ;
if ( V_9 < 0 ) {
F_21 ( & V_4 -> V_5 , L_42 ) ;
goto V_138;
}
V_2 -> V_73 . V_139 = V_90 -> V_140 ;
V_9 = F_64 ( & V_2 -> V_73 ) ;
if ( V_9 < 0 ) {
F_21 ( & V_4 -> V_5 , L_43 ) ;
goto V_141;
}
F_65 ( V_4 , V_2 ) ;
F_44 ( & V_4 -> V_5 , L_44 , F_63 ( & V_2 -> V_73 . V_5 ) ) ;
F_33 ( V_2 -> V_76 ) ;
return 0 ;
V_141:
F_47 ( V_2 ) ;
V_138:
F_66 ( V_2 -> V_136 , V_2 ) ;
V_135:
F_67 ( V_2 -> V_16 ) ;
V_133:
F_68 ( V_2 -> V_131 ) ;
F_69 ( V_2 -> V_131 ) ;
V_130:
F_33 ( V_2 -> V_76 ) ;
F_70 ( V_2 -> V_76 ) ;
V_128:
F_69 ( V_2 ) ;
return V_9 ;
}
static int F_71 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = F_72 ( V_4 ) ;
F_47 ( V_2 ) ;
F_73 ( & V_2 -> V_73 ) ;
F_66 ( V_2 -> V_136 , V_2 ) ;
F_33 ( V_2 -> V_76 ) ;
F_70 ( V_2 -> V_76 ) ;
F_67 ( V_2 -> V_16 ) ;
F_68 ( V_2 -> V_131 ) ;
F_69 ( V_2 -> V_131 ) ;
F_69 ( V_2 ) ;
return 0 ;
}
static int F_74 ( struct V_142 * V_5 )
{
struct V_3 * V_4 = F_2 ( V_5 ) ;
struct V_1 * V_2 = F_72 ( V_4 ) ;
V_2 -> V_67 = 1 ;
return 0 ;
}
static int F_75 ( struct V_142 * V_5 )
{
struct V_3 * V_4 = F_2 ( V_5 ) ;
struct V_1 * V_2 = F_72 ( V_4 ) ;
V_2 -> V_67 = 0 ;
F_32 ( V_2 -> V_76 ) ;
F_49 ( V_2 ) ;
F_33 ( V_2 -> V_76 ) ;
return 0 ;
}
static int T_3 F_76 ( void )
{
return F_77 ( & V_143 ) ;
}
static void T_4 F_78 ( void )
{
F_79 ( & V_143 ) ;
}
