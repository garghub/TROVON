static inline unsigned int F_1 ( struct V_1 * V_2 )
{
if ( V_2 -> V_3 . V_4 ) {
const struct V_5 * V_6 ;
V_6 = F_2 ( V_7 , V_2 -> V_3 . V_4 ) ;
return ( unsigned int ) V_6 -> V_8 ;
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
F_6 ( & V_11 -> V_17 ) ;
}
static inline void F_7 ( struct V_10 * V_11 )
{
unsigned long V_18 ;
V_18 = F_8 ( V_11 -> V_19 + V_20 ) ;
F_9 ( V_18 & ~ V_21 , V_11 -> V_19 + V_20 ) ;
}
static inline void F_10 ( struct V_10 * V_11 )
{
unsigned long V_18 ;
V_18 = F_8 ( V_11 -> V_19 + V_20 ) ;
F_9 ( V_18 | V_21 , V_11 -> V_19 + V_20 ) ;
}
static inline void F_11 ( struct V_10 * V_11 )
{
unsigned long V_18 ;
V_18 = F_8 ( V_11 -> V_19 + V_20 ) ;
F_9 ( V_18 & ~ V_22 , V_11 -> V_19 + V_20 ) ;
}
static inline void F_12 ( struct V_10 * V_11 )
{
unsigned long V_18 ;
V_18 = F_8 ( V_11 -> V_19 + V_20 ) ;
F_9 ( V_18 | V_22 , V_11 -> V_19 + V_20 ) ;
}
static void F_13 ( struct V_10 * V_11 ,
struct V_23 * V_14 )
{
unsigned int V_24 = ( V_14 -> V_24 & 0x7f ) << 1 ;
unsigned long V_25 ;
unsigned long V_26 ;
V_25 = 0 ;
V_25 |= V_27 ;
if ( V_14 -> V_28 & V_29 ) {
V_25 |= V_30 ;
V_24 |= 1 ;
} else
V_25 |= V_31 ;
if ( V_14 -> V_28 & V_32 )
V_24 ^= 1 ;
F_10 ( V_11 ) ;
V_26 = F_8 ( V_11 -> V_19 + V_20 ) ;
F_9 ( V_25 , V_11 -> V_19 + V_33 ) ;
F_5 ( V_11 -> V_3 , L_2 , V_25 , V_24 ) ;
F_14 ( V_24 , V_11 -> V_19 + V_34 ) ;
F_15 ( V_11 -> V_35 ) ;
F_5 ( V_11 -> V_3 , L_3 , V_26 ) ;
F_9 ( V_26 , V_11 -> V_19 + V_20 ) ;
V_25 |= V_36 ;
F_9 ( V_25 , V_11 -> V_19 + V_33 ) ;
}
static inline void F_16 ( struct V_10 * V_11 , int V_12 )
{
unsigned long V_37 = F_8 ( V_11 -> V_19 + V_33 ) ;
F_5 ( V_11 -> V_3 , L_4 ) ;
if ( V_11 -> V_38 & V_39 ) {
V_37 &= ~ V_27 ;
} else {
V_37 &= ~ V_36 ;
}
F_9 ( V_37 , V_11 -> V_19 + V_33 ) ;
V_11 -> V_40 = V_41 ;
F_4 ( V_11 , V_12 ) ;
F_11 ( V_11 ) ;
}
static inline int F_17 ( struct V_10 * V_11 )
{
return V_11 -> V_15 >= ( V_11 -> V_16 - 1 ) ;
}
static inline int F_18 ( struct V_10 * V_11 )
{
if ( V_11 -> V_14 -> V_28 & V_42 && V_11 -> V_14 -> V_43 == 1 )
return 0 ;
return V_11 -> V_13 == V_11 -> V_14 -> V_43 - 1 ;
}
static inline int F_19 ( struct V_10 * V_11 )
{
return V_11 -> V_13 >= V_11 -> V_14 -> V_43 ;
}
static int F_20 ( struct V_10 * V_11 , unsigned long V_37 )
{
unsigned long V_18 ;
unsigned char V_44 ;
int V_12 = 0 ;
switch ( V_11 -> V_40 ) {
case V_45 :
F_21 ( V_11 -> V_3 , L_5 , V_46 ) ;
goto V_47;
case V_41 :
F_21 ( V_11 -> V_3 , L_6 , V_46 ) ;
F_11 ( V_11 ) ;
goto V_48;
case V_49 :
if ( V_37 & V_50 &&
! ( V_11 -> V_14 -> V_28 & V_51 ) ) {
F_5 ( V_11 -> V_3 , L_7 ) ;
F_16 ( V_11 , - V_52 ) ;
goto V_48;
}
if ( V_11 -> V_14 -> V_28 & V_29 )
V_11 -> V_40 = V_53 ;
else
V_11 -> V_40 = V_54 ;
if ( F_17 ( V_11 ) && V_11 -> V_14 -> V_43 == 0 ) {
F_16 ( V_11 , 0 ) ;
goto V_48;
}
if ( V_11 -> V_40 == V_53 )
goto V_55;
case V_54 :
if ( ! ( V_11 -> V_14 -> V_28 & V_51 ) ) {
if ( V_37 & V_50 ) {
F_5 ( V_11 -> V_3 , L_8 ) ;
F_16 ( V_11 , - V_56 ) ;
goto V_48;
}
}
V_57:
if ( ! F_19 ( V_11 ) ) {
V_44 = V_11 -> V_14 -> V_58 [ V_11 -> V_13 ++ ] ;
F_14 ( V_44 , V_11 -> V_19 + V_34 ) ;
F_15 ( V_11 -> V_35 ) ;
} else if ( ! F_17 ( V_11 ) ) {
F_5 ( V_11 -> V_3 , L_9 ) ;
V_11 -> V_13 = 0 ;
V_11 -> V_15 ++ ;
V_11 -> V_14 ++ ;
if ( V_11 -> V_14 -> V_28 & V_59 ) {
if ( V_11 -> V_14 -> V_28 & V_29 ) {
F_16 ( V_11 , - V_60 ) ;
}
goto V_57;
} else {
F_13 ( V_11 , V_11 -> V_14 ) ;
V_11 -> V_40 = V_49 ;
}
} else {
F_16 ( V_11 , 0 ) ;
}
break;
case V_53 :
V_44 = F_22 ( V_11 -> V_19 + V_34 ) ;
V_11 -> V_14 -> V_58 [ V_11 -> V_13 ++ ] = V_44 ;
if ( V_11 -> V_14 -> V_28 & V_42 && V_11 -> V_14 -> V_43 == 1 )
V_11 -> V_14 -> V_43 += V_44 ;
V_55:
if ( F_18 ( V_11 ) ) {
if ( F_17 ( V_11 ) )
F_7 ( V_11 ) ;
} else if ( F_19 ( V_11 ) ) {
if ( F_17 ( V_11 ) ) {
F_5 ( V_11 -> V_3 , L_10 ) ;
F_16 ( V_11 , 0 ) ;
} else {
F_5 ( V_11 -> V_3 , L_11 ) ;
V_11 -> V_13 = 0 ;
V_11 -> V_15 ++ ;
V_11 -> V_14 ++ ;
}
}
break;
}
V_48:
V_18 = F_8 ( V_11 -> V_19 + V_20 ) ;
V_18 &= ~ V_61 ;
F_9 ( V_18 , V_11 -> V_19 + V_20 ) ;
V_47:
return V_12 ;
}
static T_1 F_23 ( int V_62 , void * V_63 )
{
struct V_10 * V_11 = V_63 ;
unsigned long V_64 ;
unsigned long V_18 ;
V_64 = F_8 ( V_11 -> V_19 + V_33 ) ;
if ( V_64 & V_65 ) {
F_21 ( V_11 -> V_3 , L_12 ) ;
}
if ( V_11 -> V_40 == V_45 ) {
F_5 ( V_11 -> V_3 , L_13 ) ;
V_18 = F_8 ( V_11 -> V_19 + V_20 ) ;
V_18 &= ~ V_61 ;
F_9 ( V_18 , V_11 -> V_19 + V_20 ) ;
goto V_47;
}
F_20 ( V_11 , V_64 ) ;
V_47:
return V_66 ;
}
static int F_24 ( struct V_10 * V_11 )
{
unsigned long V_37 ;
int V_67 = 400 ;
while ( V_67 -- > 0 ) {
V_37 = F_8 ( V_11 -> V_19 + V_33 ) ;
if ( ! ( V_37 & V_68 ) )
return 0 ;
F_25 ( 1 ) ;
}
return - V_69 ;
}
static void F_26 ( struct V_10 * V_11 )
{
unsigned long V_37 ;
T_2 V_70 , V_71 ;
unsigned long V_72 ;
int V_73 ;
F_5 ( V_11 -> V_3 , L_14 ) ;
V_70 = V_71 = F_27 () ;
V_73 = 3 ;
V_37 = F_8 ( V_11 -> V_19 + V_33 ) ;
while ( ( V_37 & V_36 ) && -- V_73 ) {
F_28 () ;
V_37 = F_8 ( V_11 -> V_19 + V_33 ) ;
}
V_72 = 1 ;
while ( ( V_37 & V_36 ) &&
F_29 ( V_71 , V_70 ) < V_74 ) {
F_30 ( V_72 , 2 * V_72 ) ;
if ( V_72 < V_74 / 10 )
V_72 <<= 1 ;
V_71 = F_27 () ;
V_37 = F_8 ( V_11 -> V_19 + V_33 ) ;
}
if ( V_37 & V_36 )
F_31 ( V_11 -> V_3 , L_15 ) ;
}
static int F_32 ( struct V_10 * V_11 ,
struct V_23 * V_75 , int V_76 )
{
unsigned long V_67 ;
int V_12 ;
if ( V_11 -> V_77 )
return - V_78 ;
V_12 = F_24 ( V_11 ) ;
if ( V_12 != 0 ) {
F_21 ( V_11 -> V_3 , L_16 , V_12 ) ;
V_12 = - V_79 ;
goto V_47;
}
V_11 -> V_14 = V_75 ;
V_11 -> V_16 = V_76 ;
V_11 -> V_13 = 0 ;
V_11 -> V_15 = 0 ;
V_11 -> V_40 = V_49 ;
F_12 ( V_11 ) ;
F_13 ( V_11 , V_75 ) ;
V_67 = F_33 ( V_11 -> V_17 , V_11 -> V_16 == 0 , V_80 * 5 ) ;
V_12 = V_11 -> V_15 ;
if ( V_67 == 0 )
F_5 ( V_11 -> V_3 , L_17 ) ;
else if ( V_12 != V_76 )
F_5 ( V_11 -> V_3 , L_18 , V_12 ) ;
if ( V_11 -> V_38 & V_39 )
goto V_47;
F_26 ( V_11 ) ;
V_47:
return V_12 ;
}
static int F_34 ( struct V_81 * V_82 ,
struct V_23 * V_75 , int V_76 )
{
struct V_10 * V_11 = (struct V_10 * ) V_82 -> V_83 ;
int V_84 ;
int V_12 ;
F_35 ( & V_82 -> V_3 ) ;
F_36 ( V_11 -> V_85 ) ;
for ( V_84 = 0 ; V_84 < V_82 -> V_86 ; V_84 ++ ) {
V_12 = F_32 ( V_11 , V_75 , V_76 ) ;
if ( V_12 != - V_79 ) {
F_37 ( V_11 -> V_85 ) ;
F_38 ( & V_82 -> V_3 ) ;
return V_12 ;
}
F_5 ( V_11 -> V_3 , L_19 , V_84 ) ;
F_39 ( 100 ) ;
}
F_37 ( V_11 -> V_85 ) ;
F_38 ( & V_82 -> V_3 ) ;
return - V_87 ;
}
static T_3 F_40 ( struct V_81 * V_82 )
{
return V_88 | V_89 | V_90 |
V_91 ;
}
static int F_41 ( unsigned long V_92 , unsigned int V_93 ,
unsigned int * V_94 , unsigned int * V_95 )
{
unsigned int V_96 = V_92 / V_93 ;
unsigned int V_97 ;
if ( V_96 > ( 16 * 16 ) )
V_97 = 512 ;
else
V_97 = 16 ;
V_96 += V_97 - 1 ;
V_96 /= V_97 ;
if ( V_96 == 0 )
V_96 = 1 ;
if ( V_96 > 17 )
V_96 = 17 ;
* V_95 = V_96 ;
* V_94 = V_97 ;
return V_92 / ( V_96 * V_97 ) ;
}
static int F_42 ( struct V_10 * V_11 , unsigned int * V_98 )
{
struct V_99 * V_100 = V_11 -> V_100 ;
unsigned long V_92 = F_43 ( V_11 -> V_85 ) ;
unsigned int V_95 , V_94 ;
unsigned long V_101 ;
T_3 V_26 ;
int V_102 ;
V_11 -> V_103 = V_92 ;
V_92 /= 1000 ;
F_5 ( V_11 -> V_3 , L_20 , V_100 -> V_104 ) ;
V_101 = V_100 -> V_104 ? V_100 -> V_104 : 100000 ;
V_101 /= 1000 ;
V_102 = F_41 ( V_92 , V_101 , & V_94 , & V_95 ) ;
if ( V_102 > V_101 ) {
F_21 ( V_11 -> V_3 ,
L_21 \
L_22 , V_101 , V_102 ) ;
return - V_60 ;
}
* V_98 = V_102 ;
V_26 = F_8 ( V_11 -> V_19 + V_20 ) ;
V_26 &= ~ ( V_105 | V_106 ) ;
V_26 |= ( V_95 - 1 ) ;
if ( V_94 == 512 )
V_26 |= V_106 ;
F_9 ( V_26 , V_11 -> V_19 + V_20 ) ;
if ( V_11 -> V_38 & V_107 ) {
unsigned long V_108 ;
if ( V_100 -> V_108 ) {
V_108 = V_92 * V_100 -> V_108 ;
V_108 = F_44 ( V_108 , 1000000 ) ;
V_108 = F_44 ( V_108 , 5 ) ;
if ( V_108 > 3 )
V_108 = 3 ;
V_108 |= V_109 ;
} else
V_108 = 0 ;
F_5 ( V_11 -> V_3 , L_23 , V_108 ) ;
F_9 ( V_108 , V_11 -> V_19 + V_110 ) ;
}
return 0 ;
}
static int F_45 ( struct V_111 * V_112 ,
unsigned long V_113 , void * V_8 )
{
struct V_10 * V_11 = F_46 ( V_112 ) ;
unsigned int V_98 ;
int V_114 ;
int V_12 ;
V_114 = F_43 ( V_11 -> V_85 ) - V_11 -> V_103 ;
if ( ( V_113 == V_115 && V_114 < 0 ) ||
( V_113 == V_116 && V_114 > 0 ) ) {
F_47 ( & V_11 -> V_82 ) ;
V_12 = F_42 ( V_11 , & V_98 ) ;
F_48 ( & V_11 -> V_82 ) ;
if ( V_12 < 0 )
F_21 ( V_11 -> V_3 , L_24 ) ;
else
F_49 ( V_11 -> V_3 , L_25 , V_98 ) ;
}
return 0 ;
}
static inline int F_50 ( struct V_10 * V_11 )
{
V_11 -> V_117 . V_118 = F_45 ;
return F_51 ( & V_11 -> V_117 ,
V_119 ) ;
}
static inline void F_52 ( struct V_10 * V_11 )
{
F_53 ( & V_11 -> V_117 ,
V_119 ) ;
}
static inline int F_50 ( struct V_10 * V_11 )
{
return 0 ;
}
static inline void F_52 ( struct V_10 * V_11 )
{
}
static int F_54 ( struct V_10 * V_11 )
{
int V_120 , V_121 , V_12 ;
if ( V_11 -> V_38 & V_122 )
return 0 ;
for ( V_120 = 0 ; V_120 < 2 ; V_120 ++ ) {
V_121 = F_55 ( V_11 -> V_3 -> V_4 , V_120 ) ;
if ( ! F_56 ( V_121 ) ) {
F_21 ( V_11 -> V_3 , L_26 , V_120 , V_121 ) ;
goto V_123;
}
V_11 -> V_124 [ V_120 ] = V_121 ;
V_12 = F_57 ( V_121 , L_27 ) ;
if ( V_12 ) {
F_21 ( V_11 -> V_3 , L_28 , V_121 ) ;
goto V_123;
}
}
return 0 ;
V_123:
while ( -- V_120 >= 0 )
F_58 ( V_11 -> V_124 [ V_120 ] ) ;
return - V_60 ;
}
static void F_59 ( struct V_10 * V_11 )
{
unsigned int V_120 ;
if ( V_11 -> V_38 & V_122 )
return;
for ( V_120 = 0 ; V_120 < 2 ; V_120 ++ )
F_58 ( V_11 -> V_124 [ V_120 ] ) ;
}
static int F_54 ( struct V_10 * V_11 )
{
return 0 ;
}
static void F_59 ( struct V_10 * V_11 )
{
}
static int F_60 ( struct V_10 * V_11 )
{
unsigned long V_125 = V_22 | V_21 ;
struct V_99 * V_100 ;
unsigned int V_102 ;
V_100 = V_11 -> V_100 ;
F_14 ( V_100 -> V_126 , V_11 -> V_19 + V_127 ) ;
F_49 ( V_11 -> V_3 , L_29 , V_100 -> V_126 ) ;
F_9 ( V_125 , V_11 -> V_19 + V_20 ) ;
if ( F_42 ( V_11 , & V_102 ) != 0 ) {
F_9 ( 0 , V_11 -> V_19 + V_20 ) ;
F_21 ( V_11 -> V_3 , L_30 ) ;
return - V_60 ;
}
F_49 ( V_11 -> V_3 , L_31 , V_102 ) ;
F_5 ( V_11 -> V_3 , L_32 , V_125 ) ;
return 0 ;
}
static void
F_61 ( struct V_128 * V_129 , struct V_10 * V_11 )
{
struct V_99 * V_100 = V_11 -> V_100 ;
if ( ! V_129 )
return;
V_100 -> V_130 = - 1 ;
F_62 ( V_129 , L_33 , & V_100 -> V_108 ) ;
F_62 ( V_129 , L_34 , & V_100 -> V_126 ) ;
F_62 ( V_129 , L_35 ,
( T_3 * ) & V_100 -> V_104 ) ;
}
static void
F_61 ( struct V_128 * V_129 , struct V_10 * V_11 )
{
return;
}
static int F_63 ( struct V_1 * V_2 )
{
struct V_10 * V_11 ;
struct V_99 * V_100 = NULL ;
struct V_131 * V_132 ;
int V_12 ;
if ( ! V_2 -> V_3 . V_4 ) {
V_100 = F_64 ( & V_2 -> V_3 ) ;
if ( ! V_100 ) {
F_21 ( & V_2 -> V_3 , L_36 ) ;
return - V_60 ;
}
}
V_11 = F_65 ( & V_2 -> V_3 , sizeof( struct V_10 ) , V_133 ) ;
if ( ! V_11 ) {
F_21 ( & V_2 -> V_3 , L_37 ) ;
return - V_134 ;
}
V_11 -> V_100 = F_65 ( & V_2 -> V_3 , sizeof( * V_100 ) , V_133 ) ;
if ( ! V_11 -> V_100 ) {
F_21 ( & V_2 -> V_3 , L_38 ) ;
return - V_134 ;
}
V_11 -> V_38 = F_1 ( V_2 ) ;
if ( V_100 )
memcpy ( V_11 -> V_100 , V_100 , sizeof( * V_100 ) ) ;
else
F_61 ( V_2 -> V_3 . V_4 , V_11 ) ;
F_66 ( V_11 -> V_82 . V_135 , L_39 , sizeof( V_11 -> V_82 . V_135 ) ) ;
V_11 -> V_82 . V_136 = V_137 ;
V_11 -> V_82 . V_138 = & V_139 ;
V_11 -> V_82 . V_86 = 2 ;
V_11 -> V_82 . V_140 = V_141 | V_142 ;
V_11 -> V_35 = 50 ;
F_67 ( & V_11 -> V_17 ) ;
V_11 -> V_3 = & V_2 -> V_3 ;
V_11 -> V_85 = F_68 ( & V_2 -> V_3 , L_40 ) ;
if ( F_69 ( V_11 -> V_85 ) ) {
F_21 ( & V_2 -> V_3 , L_41 ) ;
return - V_143 ;
}
F_5 ( & V_2 -> V_3 , L_42 , V_11 -> V_85 ) ;
V_132 = F_70 ( V_2 , V_144 , 0 ) ;
V_11 -> V_19 = F_71 ( & V_2 -> V_3 , V_132 ) ;
if ( F_69 ( V_11 -> V_19 ) )
return F_72 ( V_11 -> V_19 ) ;
F_5 ( & V_2 -> V_3 , L_43 ,
V_11 -> V_19 , V_132 ) ;
V_11 -> V_82 . V_83 = V_11 ;
V_11 -> V_82 . V_3 . V_145 = & V_2 -> V_3 ;
V_11 -> V_146 = F_73 ( V_11 -> V_3 ) ;
if ( V_11 -> V_100 -> V_147 ) {
V_11 -> V_100 -> V_147 ( F_74 ( V_11 -> V_3 ) ) ;
} else if ( F_69 ( V_11 -> V_146 ) && F_54 ( V_11 ) ) {
return - V_60 ;
}
F_36 ( V_11 -> V_85 ) ;
V_12 = F_60 ( V_11 ) ;
F_37 ( V_11 -> V_85 ) ;
if ( V_12 != 0 ) {
F_21 ( & V_2 -> V_3 , L_44 ) ;
return V_12 ;
}
V_11 -> V_148 = V_12 = F_75 ( V_2 , 0 ) ;
if ( V_12 <= 0 ) {
F_21 ( & V_2 -> V_3 , L_45 ) ;
return V_12 ;
}
V_12 = F_76 ( & V_2 -> V_3 , V_11 -> V_148 , F_23 , 0 ,
F_77 ( & V_2 -> V_3 ) , V_11 ) ;
if ( V_12 != 0 ) {
F_21 ( & V_2 -> V_3 , L_46 , V_11 -> V_148 ) ;
return V_12 ;
}
V_12 = F_50 ( V_11 ) ;
if ( V_12 < 0 ) {
F_21 ( & V_2 -> V_3 , L_47 ) ;
return V_12 ;
}
V_11 -> V_82 . V_149 = V_11 -> V_100 -> V_130 ;
V_11 -> V_82 . V_3 . V_4 = V_2 -> V_3 . V_4 ;
V_12 = F_78 ( & V_11 -> V_82 ) ;
if ( V_12 < 0 ) {
F_21 ( & V_2 -> V_3 , L_48 ) ;
F_52 ( V_11 ) ;
return V_12 ;
}
F_79 ( V_2 , V_11 ) ;
F_80 ( & V_2 -> V_3 ) ;
F_80 ( & V_11 -> V_82 . V_3 ) ;
F_49 ( & V_2 -> V_3 , L_49 , F_77 ( & V_11 -> V_82 . V_3 ) ) ;
return 0 ;
}
static int F_81 ( struct V_1 * V_2 )
{
struct V_10 * V_11 = F_82 ( V_2 ) ;
F_83 ( & V_11 -> V_82 . V_3 ) ;
F_83 ( & V_2 -> V_3 ) ;
F_52 ( V_11 ) ;
F_84 ( & V_11 -> V_82 ) ;
if ( V_2 -> V_3 . V_4 && F_69 ( V_11 -> V_146 ) )
F_59 ( V_11 ) ;
return 0 ;
}
static int F_85 ( struct V_150 * V_3 )
{
struct V_1 * V_2 = F_74 ( V_3 ) ;
struct V_10 * V_11 = F_82 ( V_2 ) ;
V_11 -> V_77 = 1 ;
return 0 ;
}
static int F_86 ( struct V_150 * V_3 )
{
struct V_1 * V_2 = F_74 ( V_3 ) ;
struct V_10 * V_11 = F_82 ( V_2 ) ;
V_11 -> V_77 = 0 ;
F_36 ( V_11 -> V_85 ) ;
F_60 ( V_11 ) ;
F_37 ( V_11 -> V_85 ) ;
return 0 ;
}
static int T_4 F_87 ( void )
{
return F_88 ( & V_151 ) ;
}
static void T_5 F_89 ( void )
{
F_90 ( & V_151 ) ;
}
