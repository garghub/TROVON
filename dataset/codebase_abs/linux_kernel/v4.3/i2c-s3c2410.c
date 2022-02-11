static inline T_1 F_1 ( struct V_1 * V_2 )
{
if ( V_2 -> V_3 . V_4 ) {
const struct V_5 * V_6 ;
V_6 = F_2 ( V_7 , V_2 -> V_3 . V_4 ) ;
return ( T_1 ) V_6 -> V_8 ;
}
return F_3 ( V_2 ) -> V_9 ;
}
static inline void F_4 ( struct V_10 * V_11 , int V_12 )
{
F_5 ( V_11 -> V_3 , L_1 , V_12 ) ;
V_11 -> V_13 = 0 ;
V_11 -> V_14 = NULL ;
V_11 -> V_15 ++ ;
V_11 -> V_16 = 0 ;
if ( V_12 )
V_11 -> V_15 = V_12 ;
if ( ! ( V_11 -> V_17 & V_18 ) )
F_6 ( & V_11 -> V_19 ) ;
}
static inline void F_7 ( struct V_10 * V_11 )
{
unsigned long V_20 ;
V_20 = F_8 ( V_11 -> V_21 + V_22 ) ;
F_9 ( V_20 & ~ V_23 , V_11 -> V_21 + V_22 ) ;
}
static inline void F_10 ( struct V_10 * V_11 )
{
unsigned long V_20 ;
V_20 = F_8 ( V_11 -> V_21 + V_22 ) ;
F_9 ( V_20 | V_23 , V_11 -> V_21 + V_22 ) ;
}
static inline void F_11 ( struct V_10 * V_11 )
{
unsigned long V_20 ;
V_20 = F_8 ( V_11 -> V_21 + V_22 ) ;
F_9 ( V_20 & ~ V_24 , V_11 -> V_21 + V_22 ) ;
}
static inline void F_12 ( struct V_10 * V_11 )
{
unsigned long V_20 ;
V_20 = F_8 ( V_11 -> V_21 + V_22 ) ;
F_9 ( V_20 | V_24 , V_11 -> V_21 + V_22 ) ;
}
static bool F_13 ( struct V_10 * V_11 )
{
int V_25 ;
for ( V_25 = 50 ; V_25 ; -- V_25 ) {
if ( F_8 ( V_11 -> V_21 + V_22 )
& V_26 ) {
if ( ! ( F_8 ( V_11 -> V_21 + V_27 )
& V_28 ) )
return true ;
}
F_14 ( 1000 , 2000 ) ;
}
F_15 ( V_11 -> V_3 , L_2 ) ;
return false ;
}
static void F_16 ( struct V_10 * V_11 ,
struct V_29 * V_14 )
{
unsigned int V_30 = ( V_14 -> V_30 & 0x7f ) << 1 ;
unsigned long V_31 ;
unsigned long V_32 ;
V_31 = 0 ;
V_31 |= V_33 ;
if ( V_14 -> V_34 & V_35 ) {
V_31 |= V_36 ;
V_30 |= 1 ;
} else
V_31 |= V_37 ;
if ( V_14 -> V_34 & V_38 )
V_30 ^= 1 ;
F_10 ( V_11 ) ;
V_32 = F_8 ( V_11 -> V_21 + V_22 ) ;
F_9 ( V_31 , V_11 -> V_21 + V_27 ) ;
F_5 ( V_11 -> V_3 , L_3 , V_31 , V_30 ) ;
F_17 ( V_30 , V_11 -> V_21 + V_39 ) ;
F_18 ( V_11 -> V_40 ) ;
F_5 ( V_11 -> V_3 , L_4 , V_32 ) ;
F_9 ( V_32 , V_11 -> V_21 + V_22 ) ;
V_31 |= V_41 ;
F_9 ( V_31 , V_11 -> V_21 + V_27 ) ;
if ( V_11 -> V_17 & V_18 ) {
while ( ( V_11 -> V_16 != 0 ) && F_13 ( V_11 ) ) {
F_19 ( V_11 , V_31 ) ;
V_31 = F_8 ( V_11 -> V_21 + V_27 ) ;
if ( V_31 & V_42 )
F_15 ( V_11 -> V_3 , L_5 ) ;
}
}
}
static inline void F_20 ( struct V_10 * V_11 , int V_12 )
{
unsigned long V_43 = F_8 ( V_11 -> V_21 + V_27 ) ;
F_5 ( V_11 -> V_3 , L_6 ) ;
if ( V_11 -> V_17 & V_44 ) {
V_43 &= ~ V_33 ;
} else {
V_43 &= ~ V_41 ;
}
F_9 ( V_43 , V_11 -> V_21 + V_27 ) ;
V_11 -> V_45 = V_46 ;
F_4 ( V_11 , V_12 ) ;
F_11 ( V_11 ) ;
}
static inline int F_21 ( struct V_10 * V_11 )
{
return V_11 -> V_15 >= ( V_11 -> V_16 - 1 ) ;
}
static inline int F_22 ( struct V_10 * V_11 )
{
if ( V_11 -> V_14 -> V_34 & V_47 && V_11 -> V_14 -> V_48 == 1 )
return 0 ;
return V_11 -> V_13 == V_11 -> V_14 -> V_48 - 1 ;
}
static inline int F_23 ( struct V_10 * V_11 )
{
return V_11 -> V_13 >= V_11 -> V_14 -> V_48 ;
}
static int F_19 ( struct V_10 * V_11 , unsigned long V_43 )
{
unsigned long V_20 ;
unsigned char V_49 ;
int V_12 = 0 ;
switch ( V_11 -> V_45 ) {
case V_50 :
F_15 ( V_11 -> V_3 , L_7 , V_51 ) ;
goto V_52;
case V_46 :
F_15 ( V_11 -> V_3 , L_8 , V_51 ) ;
F_11 ( V_11 ) ;
goto V_53;
case V_54 :
if ( V_43 & V_28 &&
! ( V_11 -> V_14 -> V_34 & V_55 ) ) {
F_5 ( V_11 -> V_3 , L_2 ) ;
F_20 ( V_11 , - V_56 ) ;
goto V_53;
}
if ( V_11 -> V_14 -> V_34 & V_35 )
V_11 -> V_45 = V_57 ;
else
V_11 -> V_45 = V_58 ;
if ( F_21 ( V_11 ) && V_11 -> V_14 -> V_48 == 0 ) {
F_20 ( V_11 , 0 ) ;
goto V_53;
}
if ( V_11 -> V_45 == V_57 )
goto V_59;
case V_58 :
if ( ! ( V_11 -> V_14 -> V_34 & V_55 ) ) {
if ( V_43 & V_28 ) {
F_5 ( V_11 -> V_3 , L_9 ) ;
F_20 ( V_11 , - V_60 ) ;
goto V_53;
}
}
V_61:
if ( ! F_23 ( V_11 ) ) {
V_49 = V_11 -> V_14 -> V_62 [ V_11 -> V_13 ++ ] ;
F_17 ( V_49 , V_11 -> V_21 + V_39 ) ;
F_18 ( V_11 -> V_40 ) ;
} else if ( ! F_21 ( V_11 ) ) {
F_5 ( V_11 -> V_3 , L_10 ) ;
V_11 -> V_13 = 0 ;
V_11 -> V_15 ++ ;
V_11 -> V_14 ++ ;
if ( V_11 -> V_14 -> V_34 & V_63 ) {
if ( V_11 -> V_14 -> V_34 & V_35 ) {
F_20 ( V_11 , - V_64 ) ;
}
goto V_61;
} else {
F_16 ( V_11 , V_11 -> V_14 ) ;
V_11 -> V_45 = V_54 ;
}
} else {
F_20 ( V_11 , 0 ) ;
}
break;
case V_57 :
V_49 = F_24 ( V_11 -> V_21 + V_39 ) ;
V_11 -> V_14 -> V_62 [ V_11 -> V_13 ++ ] = V_49 ;
if ( V_11 -> V_14 -> V_34 & V_47 && V_11 -> V_14 -> V_48 == 1 )
V_11 -> V_14 -> V_48 += V_49 ;
V_59:
if ( F_22 ( V_11 ) ) {
if ( F_21 ( V_11 ) )
F_7 ( V_11 ) ;
} else if ( F_23 ( V_11 ) ) {
if ( F_21 ( V_11 ) ) {
F_5 ( V_11 -> V_3 , L_11 ) ;
F_20 ( V_11 , 0 ) ;
} else {
F_5 ( V_11 -> V_3 , L_12 ) ;
V_11 -> V_13 = 0 ;
V_11 -> V_15 ++ ;
V_11 -> V_14 ++ ;
}
}
break;
}
V_53:
V_20 = F_8 ( V_11 -> V_21 + V_22 ) ;
V_20 &= ~ V_26 ;
F_9 ( V_20 , V_11 -> V_21 + V_22 ) ;
V_52:
return V_12 ;
}
static T_2 F_25 ( int V_65 , void * V_66 )
{
struct V_10 * V_11 = V_66 ;
unsigned long V_67 ;
unsigned long V_20 ;
V_67 = F_8 ( V_11 -> V_21 + V_27 ) ;
if ( V_67 & V_42 ) {
F_15 ( V_11 -> V_3 , L_5 ) ;
}
if ( V_11 -> V_45 == V_50 ) {
F_5 ( V_11 -> V_3 , L_13 ) ;
V_20 = F_8 ( V_11 -> V_21 + V_22 ) ;
V_20 &= ~ V_26 ;
F_9 ( V_20 , V_11 -> V_21 + V_22 ) ;
goto V_52;
}
F_19 ( V_11 , V_67 ) ;
V_52:
return V_68 ;
}
static inline void F_26 ( struct V_10 * V_11 )
{
unsigned long V_20 ;
V_20 = F_8 ( V_11 -> V_21 + V_27 ) ;
V_20 &= ~ V_33 ;
F_9 ( V_20 , V_11 -> V_21 + V_27 ) ;
V_20 = F_8 ( V_11 -> V_21 + V_22 ) ;
V_20 &= ~ ( V_24 | V_26 |
V_23 ) ;
F_9 ( V_20 , V_11 -> V_21 + V_22 ) ;
}
static int F_27 ( struct V_10 * V_11 )
{
unsigned long V_43 ;
int V_69 = 400 ;
while ( V_69 -- > 0 ) {
V_43 = F_8 ( V_11 -> V_21 + V_27 ) ;
if ( ! ( V_43 & V_70 ) )
return 0 ;
F_28 ( 1 ) ;
}
return - V_71 ;
}
static void F_29 ( struct V_10 * V_11 )
{
unsigned long V_43 ;
T_3 V_72 , V_73 ;
unsigned long V_74 ;
int V_75 ;
F_5 ( V_11 -> V_3 , L_14 ) ;
V_72 = V_73 = F_30 () ;
V_75 = 3 ;
V_43 = F_8 ( V_11 -> V_21 + V_27 ) ;
while ( ( V_43 & V_41 ) && -- V_75 ) {
F_31 () ;
V_43 = F_8 ( V_11 -> V_21 + V_27 ) ;
}
V_74 = 1 ;
while ( ( V_43 & V_41 ) &&
F_32 ( V_73 , V_72 ) < V_76 ) {
F_14 ( V_74 , 2 * V_74 ) ;
if ( V_74 < V_76 / 10 )
V_74 <<= 1 ;
V_73 = F_30 () ;
V_43 = F_8 ( V_11 -> V_21 + V_27 ) ;
}
if ( V_43 & V_41 )
F_33 ( V_11 -> V_3 , L_15 ) ;
}
static int F_34 ( struct V_10 * V_11 ,
struct V_29 * V_77 , int V_78 )
{
unsigned long V_69 ;
int V_12 ;
if ( V_11 -> V_79 )
return - V_80 ;
V_12 = F_27 ( V_11 ) ;
if ( V_12 != 0 ) {
F_15 ( V_11 -> V_3 , L_16 , V_12 ) ;
V_12 = - V_81 ;
goto V_52;
}
V_11 -> V_14 = V_77 ;
V_11 -> V_16 = V_78 ;
V_11 -> V_13 = 0 ;
V_11 -> V_15 = 0 ;
V_11 -> V_45 = V_54 ;
F_12 ( V_11 ) ;
F_16 ( V_11 , V_77 ) ;
if ( V_11 -> V_17 & V_18 ) {
V_12 = V_11 -> V_15 ;
if ( V_12 != V_78 )
F_5 ( V_11 -> V_3 , L_17 , V_12 ) ;
goto V_52;
}
V_69 = F_35 ( V_11 -> V_19 , V_11 -> V_16 == 0 , V_82 * 5 ) ;
V_12 = V_11 -> V_15 ;
if ( V_69 == 0 )
F_5 ( V_11 -> V_3 , L_18 ) ;
else if ( V_12 != V_78 )
F_5 ( V_11 -> V_3 , L_17 , V_12 ) ;
if ( V_11 -> V_17 & V_44 )
goto V_52;
F_29 ( V_11 ) ;
F_26 ( V_11 ) ;
V_52:
V_11 -> V_45 = V_50 ;
return V_12 ;
}
static int F_36 ( struct V_83 * V_84 ,
struct V_29 * V_77 , int V_78 )
{
struct V_10 * V_11 = (struct V_10 * ) V_84 -> V_85 ;
int V_86 ;
int V_12 ;
F_37 ( & V_84 -> V_3 ) ;
V_12 = F_38 ( V_11 -> V_87 ) ;
if ( V_12 )
return V_12 ;
for ( V_86 = 0 ; V_86 < V_84 -> V_88 ; V_86 ++ ) {
V_12 = F_34 ( V_11 , V_77 , V_78 ) ;
if ( V_12 != - V_81 ) {
F_39 ( V_11 -> V_87 ) ;
F_40 ( & V_84 -> V_3 ) ;
return V_12 ;
}
F_5 ( V_11 -> V_3 , L_19 , V_86 ) ;
F_41 ( 100 ) ;
}
F_39 ( V_11 -> V_87 ) ;
F_40 ( & V_84 -> V_3 ) ;
return - V_89 ;
}
static T_4 F_42 ( struct V_83 * V_84 )
{
return V_90 | V_91 | V_92 |
V_93 ;
}
static int F_43 ( unsigned long V_94 , unsigned int V_95 ,
unsigned int * V_96 , unsigned int * V_97 )
{
unsigned int V_98 = V_94 / V_95 ;
unsigned int V_99 ;
if ( V_98 > ( 16 * 16 ) )
V_99 = 512 ;
else
V_99 = 16 ;
V_98 += V_99 - 1 ;
V_98 /= V_99 ;
if ( V_98 == 0 )
V_98 = 1 ;
if ( V_98 > 17 )
V_98 = 17 ;
* V_97 = V_98 ;
* V_96 = V_99 ;
return V_94 / ( V_98 * V_99 ) ;
}
static int F_44 ( struct V_10 * V_11 , unsigned int * V_100 )
{
struct V_101 * V_102 = V_11 -> V_102 ;
unsigned long V_94 = F_45 ( V_11 -> V_87 ) ;
unsigned int V_97 , V_96 ;
unsigned long V_103 ;
T_4 V_32 ;
int V_104 ;
V_11 -> V_105 = V_94 ;
V_94 /= 1000 ;
F_5 ( V_11 -> V_3 , L_20 , V_102 -> V_106 ) ;
V_103 = V_102 -> V_106 ? V_102 -> V_106 : 100000 ;
V_103 /= 1000 ;
V_104 = F_43 ( V_94 , V_103 , & V_96 , & V_97 ) ;
if ( V_104 > V_103 ) {
F_15 ( V_11 -> V_3 ,
L_21 \
L_22 , V_103 , V_104 ) ;
return - V_64 ;
}
* V_100 = V_104 ;
V_32 = F_8 ( V_11 -> V_21 + V_22 ) ;
V_32 &= ~ ( V_107 | V_108 ) ;
V_32 |= ( V_97 - 1 ) ;
if ( V_96 == 512 )
V_32 |= V_108 ;
if ( V_11 -> V_17 & V_18 )
V_32 |= F_46 ( 2 ) ;
F_9 ( V_32 , V_11 -> V_21 + V_22 ) ;
if ( V_11 -> V_17 & V_109 ) {
unsigned long V_110 ;
if ( V_102 -> V_110 ) {
V_110 = V_94 * V_102 -> V_110 ;
V_110 = F_47 ( V_110 , 1000000 ) ;
V_110 = F_47 ( V_110 , 5 ) ;
if ( V_110 > 3 )
V_110 = 3 ;
V_110 |= V_111 ;
} else
V_110 = 0 ;
F_5 ( V_11 -> V_3 , L_23 , V_110 ) ;
F_9 ( V_110 , V_11 -> V_21 + V_112 ) ;
}
return 0 ;
}
static int F_48 ( struct V_113 * V_114 ,
unsigned long V_115 , void * V_8 )
{
struct V_10 * V_11 = F_49 ( V_114 ) ;
unsigned int V_100 ;
int V_116 ;
int V_12 ;
V_116 = F_45 ( V_11 -> V_87 ) - V_11 -> V_105 ;
if ( ( V_115 == V_117 && V_116 < 0 ) ||
( V_115 == V_118 && V_116 > 0 ) ) {
F_50 ( & V_11 -> V_84 ) ;
V_12 = F_44 ( V_11 , & V_100 ) ;
F_51 ( & V_11 -> V_84 ) ;
if ( V_12 < 0 )
F_15 ( V_11 -> V_3 , L_24 ) ;
else
F_52 ( V_11 -> V_3 , L_25 , V_100 ) ;
}
return 0 ;
}
static inline int F_53 ( struct V_10 * V_11 )
{
V_11 -> V_119 . V_120 = F_48 ;
return F_54 ( & V_11 -> V_119 ,
V_121 ) ;
}
static inline void F_55 ( struct V_10 * V_11 )
{
F_56 ( & V_11 -> V_119 ,
V_121 ) ;
}
static inline int F_53 ( struct V_10 * V_11 )
{
return 0 ;
}
static inline void F_55 ( struct V_10 * V_11 )
{
}
static int F_57 ( struct V_10 * V_11 )
{
int V_122 , V_123 , V_12 ;
if ( V_11 -> V_17 & V_124 )
return 0 ;
for ( V_122 = 0 ; V_122 < 2 ; V_122 ++ ) {
V_123 = F_58 ( V_11 -> V_3 -> V_4 , V_122 ) ;
if ( ! F_59 ( V_123 ) ) {
F_15 ( V_11 -> V_3 , L_26 , V_122 , V_123 ) ;
goto V_125;
}
V_11 -> V_126 [ V_122 ] = V_123 ;
V_12 = F_60 ( V_123 , L_27 ) ;
if ( V_12 ) {
F_15 ( V_11 -> V_3 , L_28 , V_123 ) ;
goto V_125;
}
}
return 0 ;
V_125:
while ( -- V_122 >= 0 )
F_61 ( V_11 -> V_126 [ V_122 ] ) ;
return - V_64 ;
}
static void F_62 ( struct V_10 * V_11 )
{
unsigned int V_122 ;
if ( V_11 -> V_17 & V_124 )
return;
for ( V_122 = 0 ; V_122 < 2 ; V_122 ++ )
F_61 ( V_11 -> V_126 [ V_122 ] ) ;
}
static int F_57 ( struct V_10 * V_11 )
{
return 0 ;
}
static void F_62 ( struct V_10 * V_11 )
{
}
static int F_63 ( struct V_10 * V_11 )
{
struct V_101 * V_102 ;
unsigned int V_104 ;
V_102 = V_11 -> V_102 ;
F_17 ( V_102 -> V_127 , V_11 -> V_21 + V_128 ) ;
F_52 ( V_11 -> V_3 , L_29 , V_102 -> V_127 ) ;
F_9 ( 0 , V_11 -> V_21 + V_22 ) ;
F_9 ( 0 , V_11 -> V_21 + V_27 ) ;
if ( F_44 ( V_11 , & V_104 ) != 0 ) {
F_15 ( V_11 -> V_3 , L_30 ) ;
return - V_64 ;
}
F_52 ( V_11 -> V_3 , L_31 , V_104 ) ;
F_5 ( V_11 -> V_3 , L_32 ,
F_8 ( V_11 -> V_21 + V_22 ) ) ;
return 0 ;
}
static void
F_64 ( struct V_129 * V_130 , struct V_10 * V_11 )
{
struct V_101 * V_102 = V_11 -> V_102 ;
int V_131 ;
if ( ! V_130 )
return;
V_102 -> V_132 = - 1 ;
F_65 ( V_130 , L_33 , & V_102 -> V_110 ) ;
F_65 ( V_130 , L_34 , & V_102 -> V_127 ) ;
F_65 ( V_130 , L_35 ,
( T_4 * ) & V_102 -> V_106 ) ;
V_131 = F_66 ( V_130 , L_36 ) ;
V_11 -> V_133 = F_67 ( V_130 ,
L_37 ) ;
if ( F_68 ( V_11 -> V_133 ) )
return;
F_69 ( V_11 -> V_133 , V_134 , F_70 ( V_131 ) , 0 ) ;
}
static void
F_64 ( struct V_129 * V_130 , struct V_10 * V_11 )
{
return;
}
static int F_71 ( struct V_1 * V_2 )
{
struct V_10 * V_11 ;
struct V_101 * V_102 = NULL ;
struct V_135 * V_136 ;
int V_12 ;
if ( ! V_2 -> V_3 . V_4 ) {
V_102 = F_72 ( & V_2 -> V_3 ) ;
if ( ! V_102 ) {
F_15 ( & V_2 -> V_3 , L_38 ) ;
return - V_64 ;
}
}
V_11 = F_73 ( & V_2 -> V_3 , sizeof( struct V_10 ) , V_137 ) ;
if ( ! V_11 )
return - V_138 ;
V_11 -> V_102 = F_73 ( & V_2 -> V_3 , sizeof( * V_102 ) , V_137 ) ;
if ( ! V_11 -> V_102 )
return - V_138 ;
V_11 -> V_17 = F_1 ( V_2 ) ;
V_11 -> V_133 = F_74 ( - V_139 ) ;
if ( V_102 )
memcpy ( V_11 -> V_102 , V_102 , sizeof( * V_102 ) ) ;
else
F_64 ( V_2 -> V_3 . V_4 , V_11 ) ;
F_75 ( V_11 -> V_84 . V_140 , L_39 , sizeof( V_11 -> V_84 . V_140 ) ) ;
V_11 -> V_84 . V_141 = V_142 ;
V_11 -> V_84 . V_143 = & V_144 ;
V_11 -> V_84 . V_88 = 2 ;
V_11 -> V_84 . V_145 = V_146 ;
V_11 -> V_40 = 50 ;
F_76 ( & V_11 -> V_19 ) ;
V_11 -> V_3 = & V_2 -> V_3 ;
V_11 -> V_87 = F_77 ( & V_2 -> V_3 , L_36 ) ;
if ( F_68 ( V_11 -> V_87 ) ) {
F_15 ( & V_2 -> V_3 , L_40 ) ;
return - V_139 ;
}
F_5 ( & V_2 -> V_3 , L_41 , V_11 -> V_87 ) ;
V_136 = F_78 ( V_2 , V_147 , 0 ) ;
V_11 -> V_21 = F_79 ( & V_2 -> V_3 , V_136 ) ;
if ( F_68 ( V_11 -> V_21 ) )
return F_80 ( V_11 -> V_21 ) ;
F_5 ( & V_2 -> V_3 , L_42 ,
V_11 -> V_21 , V_136 ) ;
V_11 -> V_84 . V_85 = V_11 ;
V_11 -> V_84 . V_3 . V_148 = & V_2 -> V_3 ;
V_11 -> V_149 = F_81 ( V_11 -> V_3 ) ;
if ( V_11 -> V_102 -> V_150 ) {
V_11 -> V_102 -> V_150 ( F_82 ( V_11 -> V_3 ) ) ;
} else if ( F_68 ( V_11 -> V_149 ) && F_57 ( V_11 ) ) {
return - V_64 ;
}
F_83 ( V_11 -> V_87 ) ;
V_12 = F_63 ( V_11 ) ;
F_39 ( V_11 -> V_87 ) ;
if ( V_12 != 0 ) {
F_15 ( & V_2 -> V_3 , L_43 ) ;
return V_12 ;
}
if ( ! ( V_11 -> V_17 & V_18 ) ) {
V_11 -> V_151 = V_12 = F_84 ( V_2 , 0 ) ;
if ( V_12 <= 0 ) {
F_15 ( & V_2 -> V_3 , L_44 ) ;
F_85 ( V_11 -> V_87 ) ;
return V_12 ;
}
V_12 = F_86 ( & V_2 -> V_3 , V_11 -> V_151 , F_25 , 0 ,
F_87 ( & V_2 -> V_3 ) , V_11 ) ;
if ( V_12 != 0 ) {
F_15 ( & V_2 -> V_3 , L_45 , V_11 -> V_151 ) ;
F_85 ( V_11 -> V_87 ) ;
return V_12 ;
}
}
V_12 = F_53 ( V_11 ) ;
if ( V_12 < 0 ) {
F_15 ( & V_2 -> V_3 , L_46 ) ;
F_85 ( V_11 -> V_87 ) ;
return V_12 ;
}
V_11 -> V_84 . V_152 = V_11 -> V_102 -> V_132 ;
V_11 -> V_84 . V_3 . V_4 = V_2 -> V_3 . V_4 ;
F_88 ( V_2 , V_11 ) ;
F_89 ( & V_2 -> V_3 ) ;
V_12 = F_90 ( & V_11 -> V_84 ) ;
if ( V_12 < 0 ) {
F_15 ( & V_2 -> V_3 , L_47 ) ;
F_91 ( & V_2 -> V_3 ) ;
F_55 ( V_11 ) ;
F_85 ( V_11 -> V_87 ) ;
return V_12 ;
}
F_89 ( & V_11 -> V_84 . V_3 ) ;
F_52 ( & V_2 -> V_3 , L_48 , F_87 ( & V_11 -> V_84 . V_3 ) ) ;
return 0 ;
}
static int F_92 ( struct V_1 * V_2 )
{
struct V_10 * V_11 = F_93 ( V_2 ) ;
F_85 ( V_11 -> V_87 ) ;
F_91 ( & V_11 -> V_84 . V_3 ) ;
F_91 ( & V_2 -> V_3 ) ;
F_55 ( V_11 ) ;
F_94 ( & V_11 -> V_84 ) ;
if ( V_2 -> V_3 . V_4 && F_68 ( V_11 -> V_149 ) )
F_62 ( V_11 ) ;
return 0 ;
}
static int F_95 ( struct V_153 * V_3 )
{
struct V_1 * V_2 = F_82 ( V_3 ) ;
struct V_10 * V_11 = F_93 ( V_2 ) ;
V_11 -> V_79 = 1 ;
if ( ! F_68 ( V_11 -> V_133 ) )
F_96 ( V_11 -> V_133 , V_134 , & V_11 -> V_154 ) ;
return 0 ;
}
static int F_97 ( struct V_153 * V_3 )
{
struct V_1 * V_2 = F_82 ( V_3 ) ;
struct V_10 * V_11 = F_93 ( V_2 ) ;
int V_12 ;
if ( ! F_68 ( V_11 -> V_133 ) )
F_98 ( V_11 -> V_133 , V_134 , V_11 -> V_154 ) ;
V_12 = F_38 ( V_11 -> V_87 ) ;
if ( V_12 )
return V_12 ;
F_63 ( V_11 ) ;
F_39 ( V_11 -> V_87 ) ;
V_11 -> V_79 = 0 ;
return 0 ;
}
static int T_5 F_99 ( void )
{
return F_100 ( & V_155 ) ;
}
static void T_6 F_101 ( void )
{
F_102 ( & V_155 ) ;
}
