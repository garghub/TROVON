static inline int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 -> V_5 ) ;
enum V_6 type ;
#ifdef F_3
if ( V_2 -> V_5 -> V_7 )
return F_4 ( V_2 -> V_5 -> V_7 ,
L_1 ) ;
#endif
type = F_5 ( V_4 ) -> V_8 ;
return type == V_9 ;
}
static inline void F_6 ( struct V_1 * V_2 , int V_10 )
{
F_7 ( V_2 -> V_5 , L_2 , V_10 ) ;
V_2 -> V_11 = 0 ;
V_2 -> V_12 = NULL ;
V_2 -> V_13 ++ ;
V_2 -> V_14 = 0 ;
if ( V_10 )
V_2 -> V_13 = V_10 ;
F_8 ( & V_2 -> V_15 ) ;
}
static inline void F_9 ( struct V_1 * V_2 )
{
unsigned long V_16 ;
V_16 = F_10 ( V_2 -> V_17 + V_18 ) ;
F_11 ( V_16 & ~ V_19 , V_2 -> V_17 + V_18 ) ;
}
static inline void F_12 ( struct V_1 * V_2 )
{
unsigned long V_16 ;
V_16 = F_10 ( V_2 -> V_17 + V_18 ) ;
F_11 ( V_16 | V_19 , V_2 -> V_17 + V_18 ) ;
}
static inline void F_13 ( struct V_1 * V_2 )
{
unsigned long V_16 ;
V_16 = F_10 ( V_2 -> V_17 + V_18 ) ;
F_11 ( V_16 & ~ V_20 , V_2 -> V_17 + V_18 ) ;
}
static inline void F_14 ( struct V_1 * V_2 )
{
unsigned long V_16 ;
V_16 = F_10 ( V_2 -> V_17 + V_18 ) ;
F_11 ( V_16 | V_20 , V_2 -> V_17 + V_18 ) ;
}
static void F_15 ( struct V_1 * V_2 ,
struct V_21 * V_12 )
{
unsigned int V_22 = ( V_12 -> V_22 & 0x7f ) << 1 ;
unsigned long V_23 ;
unsigned long V_24 ;
V_23 = 0 ;
V_23 |= V_25 ;
if ( V_12 -> V_26 & V_27 ) {
V_23 |= V_28 ;
V_22 |= 1 ;
} else
V_23 |= V_29 ;
if ( V_12 -> V_26 & V_30 )
V_22 ^= 1 ;
F_12 ( V_2 ) ;
V_24 = F_10 ( V_2 -> V_17 + V_18 ) ;
F_11 ( V_23 , V_2 -> V_17 + V_31 ) ;
F_7 ( V_2 -> V_5 , L_3 , V_23 , V_22 ) ;
F_16 ( V_22 , V_2 -> V_17 + V_32 ) ;
F_17 ( V_2 -> V_33 ) ;
F_7 ( V_2 -> V_5 , L_4 , V_24 ) ;
F_11 ( V_24 , V_2 -> V_17 + V_18 ) ;
V_23 |= V_34 ;
F_11 ( V_23 , V_2 -> V_17 + V_31 ) ;
}
static inline void F_18 ( struct V_1 * V_2 , int V_10 )
{
unsigned long V_35 = F_10 ( V_2 -> V_17 + V_31 ) ;
F_7 ( V_2 -> V_5 , L_5 ) ;
V_35 &= ~ V_34 ;
F_11 ( V_35 , V_2 -> V_17 + V_31 ) ;
V_2 -> V_36 = V_37 ;
F_6 ( V_2 , V_10 ) ;
F_13 ( V_2 ) ;
}
static inline int F_19 ( struct V_1 * V_2 )
{
return V_2 -> V_13 >= ( V_2 -> V_14 - 1 ) ;
}
static inline int F_20 ( struct V_1 * V_2 )
{
return V_2 -> V_11 == V_2 -> V_12 -> V_38 - 1 ;
}
static inline int F_21 ( struct V_1 * V_2 )
{
return V_2 -> V_11 >= V_2 -> V_12 -> V_38 ;
}
static int F_22 ( struct V_1 * V_2 , unsigned long V_35 )
{
unsigned long V_16 ;
unsigned char V_39 ;
int V_10 = 0 ;
switch ( V_2 -> V_36 ) {
case V_40 :
F_23 ( V_2 -> V_5 , L_6 , V_41 ) ;
goto V_42;
case V_37 :
F_23 ( V_2 -> V_5 , L_7 , V_41 ) ;
F_13 ( V_2 ) ;
goto V_43;
case V_44 :
if ( V_35 & V_45 &&
! ( V_2 -> V_12 -> V_26 & V_46 ) ) {
F_7 ( V_2 -> V_5 , L_8 ) ;
F_18 ( V_2 , - V_47 ) ;
goto V_43;
}
if ( V_2 -> V_12 -> V_26 & V_27 )
V_2 -> V_36 = V_48 ;
else
V_2 -> V_36 = V_49 ;
if ( F_19 ( V_2 ) && V_2 -> V_12 -> V_38 == 0 ) {
F_18 ( V_2 , 0 ) ;
goto V_43;
}
if ( V_2 -> V_36 == V_48 )
goto V_50;
case V_49 :
if ( ! ( V_2 -> V_12 -> V_26 & V_46 ) ) {
if ( V_35 & V_45 ) {
F_7 ( V_2 -> V_5 , L_9 ) ;
F_18 ( V_2 , - V_51 ) ;
goto V_43;
}
}
V_52:
if ( ! F_21 ( V_2 ) ) {
V_39 = V_2 -> V_12 -> V_53 [ V_2 -> V_11 ++ ] ;
F_16 ( V_39 , V_2 -> V_17 + V_32 ) ;
F_17 ( V_2 -> V_33 ) ;
} else if ( ! F_19 ( V_2 ) ) {
F_7 ( V_2 -> V_5 , L_10 ) ;
V_2 -> V_11 = 0 ;
V_2 -> V_13 ++ ;
V_2 -> V_12 ++ ;
if ( V_2 -> V_12 -> V_26 & V_54 ) {
if ( V_2 -> V_12 -> V_26 & V_27 ) {
F_18 ( V_2 , - V_55 ) ;
}
goto V_52;
} else {
F_15 ( V_2 , V_2 -> V_12 ) ;
V_2 -> V_36 = V_44 ;
}
} else {
F_18 ( V_2 , 0 ) ;
}
break;
case V_48 :
V_39 = F_24 ( V_2 -> V_17 + V_32 ) ;
V_2 -> V_12 -> V_53 [ V_2 -> V_11 ++ ] = V_39 ;
V_50:
if ( F_20 ( V_2 ) ) {
if ( F_19 ( V_2 ) )
F_9 ( V_2 ) ;
} else if ( F_21 ( V_2 ) ) {
if ( F_19 ( V_2 ) ) {
F_7 ( V_2 -> V_5 , L_11 ) ;
F_18 ( V_2 , 0 ) ;
} else {
F_7 ( V_2 -> V_5 , L_12 ) ;
V_2 -> V_11 = 0 ;
V_2 -> V_13 ++ ;
V_2 -> V_12 ++ ;
}
}
break;
}
V_43:
V_16 = F_10 ( V_2 -> V_17 + V_18 ) ;
V_16 &= ~ V_56 ;
F_11 ( V_16 , V_2 -> V_17 + V_18 ) ;
V_42:
return V_10 ;
}
static T_1 F_25 ( int V_57 , void * V_58 )
{
struct V_1 * V_2 = V_58 ;
unsigned long V_59 ;
unsigned long V_16 ;
V_59 = F_10 ( V_2 -> V_17 + V_31 ) ;
if ( V_59 & V_60 ) {
F_23 ( V_2 -> V_5 , L_13 ) ;
}
if ( V_2 -> V_36 == V_40 ) {
F_7 ( V_2 -> V_5 , L_14 ) ;
V_16 = F_10 ( V_2 -> V_17 + V_18 ) ;
V_16 &= ~ V_56 ;
F_11 ( V_16 , V_2 -> V_17 + V_18 ) ;
goto V_42;
}
F_22 ( V_2 , V_59 ) ;
V_42:
return V_61 ;
}
static int F_26 ( struct V_1 * V_2 )
{
unsigned long V_35 ;
int V_62 = 400 ;
while ( V_62 -- > 0 ) {
V_35 = F_10 ( V_2 -> V_17 + V_31 ) ;
if ( ! ( V_35 & V_63 ) )
return 0 ;
F_27 ( 1 ) ;
}
return - V_64 ;
}
static int F_28 ( struct V_1 * V_2 ,
struct V_21 * V_65 , int V_66 )
{
unsigned long V_35 , V_62 ;
int V_67 = 20 ;
int V_10 ;
if ( V_2 -> V_68 )
return - V_69 ;
V_10 = F_26 ( V_2 ) ;
if ( V_10 != 0 ) {
F_23 ( V_2 -> V_5 , L_15 , V_10 ) ;
V_10 = - V_70 ;
goto V_42;
}
F_29 ( & V_2 -> V_71 ) ;
V_2 -> V_12 = V_65 ;
V_2 -> V_14 = V_66 ;
V_2 -> V_11 = 0 ;
V_2 -> V_13 = 0 ;
V_2 -> V_36 = V_44 ;
F_14 ( V_2 ) ;
F_15 ( V_2 , V_65 ) ;
F_30 ( & V_2 -> V_71 ) ;
V_62 = F_31 ( V_2 -> V_15 , V_2 -> V_14 == 0 , V_72 * 5 ) ;
V_10 = V_2 -> V_13 ;
if ( V_62 == 0 )
F_7 ( V_2 -> V_5 , L_16 ) ;
else if ( V_10 != V_66 )
F_7 ( V_2 -> V_5 , L_17 , V_10 ) ;
F_7 ( V_2 -> V_5 , L_18 ) ;
do {
F_32 () ;
V_35 = F_10 ( V_2 -> V_17 + V_31 ) ;
} while ( ( V_35 & V_34 ) && -- V_67 );
if ( ! V_67 ) {
F_27 ( 1 ) ;
V_35 = F_10 ( V_2 -> V_17 + V_31 ) ;
}
if ( V_35 & V_34 )
F_33 ( V_2 -> V_5 , L_19 ) ;
V_42:
return V_10 ;
}
static int F_34 ( struct V_73 * V_74 ,
struct V_21 * V_65 , int V_66 )
{
struct V_1 * V_2 = (struct V_1 * ) V_74 -> V_75 ;
int V_76 ;
int V_10 ;
F_35 ( & V_74 -> V_5 ) ;
F_36 ( V_2 -> V_77 ) ;
for ( V_76 = 0 ; V_76 < V_74 -> V_78 ; V_76 ++ ) {
V_10 = F_28 ( V_2 , V_65 , V_66 ) ;
if ( V_10 != - V_70 ) {
F_37 ( V_2 -> V_77 ) ;
F_38 ( & V_74 -> V_5 ) ;
return V_10 ;
}
F_7 ( V_2 -> V_5 , L_20 , V_76 ) ;
F_39 ( 100 ) ;
}
F_37 ( V_2 -> V_77 ) ;
F_38 ( & V_74 -> V_5 ) ;
return - V_79 ;
}
static T_2 F_40 ( struct V_73 * V_74 )
{
return V_80 | V_81 | V_82 ;
}
static int F_41 ( unsigned long V_83 , unsigned int V_84 ,
unsigned int * V_85 , unsigned int * V_86 )
{
unsigned int V_87 = V_83 / V_84 ;
unsigned int V_88 ;
if ( V_87 > ( 16 * 16 ) )
V_88 = 512 ;
else
V_88 = 16 ;
V_87 += V_88 - 1 ;
V_87 /= V_88 ;
if ( V_87 == 0 )
V_87 = 1 ;
if ( V_87 > 17 )
V_87 = 17 ;
* V_86 = V_87 ;
* V_85 = V_88 ;
return V_83 / ( V_87 * V_88 ) ;
}
static int F_42 ( struct V_1 * V_2 , unsigned int * V_89 )
{
struct V_90 * V_91 = V_2 -> V_91 ;
unsigned long V_83 = F_43 ( V_2 -> V_77 ) ;
unsigned int V_86 , V_85 ;
unsigned long V_92 ;
T_2 V_24 ;
int V_93 ;
V_2 -> V_94 = V_83 ;
V_83 /= 1000 ;
F_7 ( V_2 -> V_5 , L_21 , V_91 -> V_95 ) ;
V_92 = V_91 -> V_95 ? V_91 -> V_95 : 100000 ;
V_92 /= 1000 ;
V_93 = F_41 ( V_83 , V_92 , & V_85 , & V_86 ) ;
if ( V_93 > V_92 ) {
F_23 ( V_2 -> V_5 ,
L_22 \
L_23 , V_92 , V_93 ) ;
return - V_55 ;
}
* V_89 = V_93 ;
V_24 = F_10 ( V_2 -> V_17 + V_18 ) ;
V_24 &= ~ ( V_96 | V_97 ) ;
V_24 |= ( V_86 - 1 ) ;
if ( V_85 == 512 )
V_24 |= V_97 ;
F_11 ( V_24 , V_2 -> V_17 + V_18 ) ;
if ( F_1 ( V_2 ) ) {
unsigned long V_98 ;
if ( V_91 -> V_98 ) {
V_98 = V_83 * V_91 -> V_98 ;
V_98 = F_44 ( V_98 , 1000000 ) ;
V_98 = F_44 ( V_98 , 5 ) ;
if ( V_98 > 3 )
V_98 = 3 ;
V_98 |= V_99 ;
} else
V_98 = 0 ;
F_7 ( V_2 -> V_5 , L_24 , V_98 ) ;
F_11 ( V_98 , V_2 -> V_17 + V_100 ) ;
}
return 0 ;
}
static int F_45 ( struct V_101 * V_102 ,
unsigned long V_103 , void * V_104 )
{
struct V_1 * V_2 = F_46 ( V_102 ) ;
unsigned long V_26 ;
unsigned int V_89 ;
int V_105 ;
int V_10 ;
V_105 = F_43 ( V_2 -> V_77 ) - V_2 -> V_94 ;
if ( ( V_103 == V_106 && V_105 < 0 ) ||
( V_103 == V_107 && V_105 > 0 ) ) {
F_47 ( & V_2 -> V_71 , V_26 ) ;
V_10 = F_42 ( V_2 , & V_89 ) ;
F_48 ( & V_2 -> V_71 , V_26 ) ;
if ( V_10 < 0 )
F_23 ( V_2 -> V_5 , L_25 ) ;
else
F_49 ( V_2 -> V_5 , L_26 , V_89 ) ;
}
return 0 ;
}
static inline int F_50 ( struct V_1 * V_2 )
{
V_2 -> V_108 . V_109 = F_45 ;
return F_51 ( & V_2 -> V_108 ,
V_110 ) ;
}
static inline void F_52 ( struct V_1 * V_2 )
{
F_53 ( & V_2 -> V_108 ,
V_110 ) ;
}
static inline int F_50 ( struct V_1 * V_2 )
{
return 0 ;
}
static inline void F_52 ( struct V_1 * V_2 )
{
}
static int F_54 ( struct V_1 * V_2 )
{
int V_111 , V_112 , V_10 ;
for ( V_111 = 0 ; V_111 < 2 ; V_111 ++ ) {
V_112 = F_55 ( V_2 -> V_5 -> V_7 , V_111 ) ;
if ( ! F_56 ( V_112 ) ) {
F_23 ( V_2 -> V_5 , L_27 , V_111 , V_112 ) ;
goto V_113;
}
V_10 = F_57 ( V_112 , L_28 ) ;
if ( V_10 ) {
F_23 ( V_2 -> V_5 , L_29 , V_112 ) ;
goto V_113;
}
}
return 0 ;
V_113:
while ( -- V_111 >= 0 )
F_58 ( V_2 -> V_114 [ V_111 ] ) ;
return - V_55 ;
}
static void F_59 ( struct V_1 * V_2 )
{
unsigned int V_111 ;
for ( V_111 = 0 ; V_111 < 2 ; V_111 ++ )
F_58 ( V_2 -> V_114 [ V_111 ] ) ;
}
static int F_54 ( struct V_1 * V_2 )
{
return 0 ;
}
static void F_59 ( struct V_1 * V_2 )
{
}
static int F_60 ( struct V_1 * V_2 )
{
unsigned long V_115 = V_20 | V_19 ;
struct V_90 * V_91 ;
unsigned int V_93 ;
V_91 = V_2 -> V_91 ;
if ( V_91 -> V_116 )
V_91 -> V_116 ( F_2 ( V_2 -> V_5 ) ) ;
else
if ( F_54 ( V_2 ) )
return - V_55 ;
F_16 ( V_91 -> V_117 , V_2 -> V_17 + V_118 ) ;
F_49 ( V_2 -> V_5 , L_30 , V_91 -> V_117 ) ;
F_11 ( V_115 , V_2 -> V_17 + V_18 ) ;
if ( F_42 ( V_2 , & V_93 ) != 0 ) {
F_11 ( 0 , V_2 -> V_17 + V_18 ) ;
F_23 ( V_2 -> V_5 , L_31 ) ;
return - V_55 ;
}
F_49 ( V_2 -> V_5 , L_32 , V_93 ) ;
F_7 ( V_2 -> V_5 , L_33 , V_115 ) ;
return 0 ;
}
static void
F_61 ( struct V_119 * V_120 , struct V_1 * V_2 )
{
struct V_90 * V_91 = V_2 -> V_91 ;
if ( ! V_120 )
return;
V_91 -> V_121 = - 1 ;
F_62 ( V_120 , L_34 , & V_91 -> V_98 ) ;
F_62 ( V_120 , L_35 , & V_91 -> V_117 ) ;
F_62 ( V_120 , L_36 ,
( T_2 * ) & V_91 -> V_95 ) ;
}
static void
F_61 ( struct V_119 * V_120 , struct V_1 * V_2 )
{
return;
}
static int F_63 ( struct V_3 * V_4 )
{
struct V_1 * V_2 ;
struct V_90 * V_91 = NULL ;
struct V_122 * V_123 ;
int V_10 ;
if ( ! V_4 -> V_5 . V_7 ) {
V_91 = V_4 -> V_5 . V_124 ;
if ( ! V_91 ) {
F_23 ( & V_4 -> V_5 , L_37 ) ;
return - V_55 ;
}
}
V_2 = F_64 ( & V_4 -> V_5 , sizeof( struct V_1 ) , V_125 ) ;
if ( ! V_2 ) {
F_23 ( & V_4 -> V_5 , L_38 ) ;
return - V_126 ;
}
V_2 -> V_91 = F_64 ( & V_4 -> V_5 , sizeof( * V_91 ) , V_125 ) ;
if ( ! V_2 -> V_91 ) {
V_10 = - V_126 ;
goto V_127;
}
if ( V_91 )
memcpy ( V_2 -> V_91 , V_91 , sizeof( * V_91 ) ) ;
else
F_61 ( V_4 -> V_5 . V_7 , V_2 ) ;
F_65 ( V_2 -> V_74 . V_128 , L_39 , sizeof( V_2 -> V_74 . V_128 ) ) ;
V_2 -> V_74 . V_129 = V_130 ;
V_2 -> V_74 . V_131 = & V_132 ;
V_2 -> V_74 . V_78 = 2 ;
V_2 -> V_74 . V_133 = V_134 | V_135 ;
V_2 -> V_33 = 50 ;
F_66 ( & V_2 -> V_71 ) ;
F_67 ( & V_2 -> V_15 ) ;
V_2 -> V_5 = & V_4 -> V_5 ;
V_2 -> V_77 = F_68 ( & V_4 -> V_5 , L_40 ) ;
if ( F_69 ( V_2 -> V_77 ) ) {
F_23 ( & V_4 -> V_5 , L_41 ) ;
V_10 = - V_136 ;
goto V_127;
}
F_7 ( & V_4 -> V_5 , L_42 , V_2 -> V_77 ) ;
F_36 ( V_2 -> V_77 ) ;
V_123 = F_70 ( V_4 , V_137 , 0 ) ;
if ( V_123 == NULL ) {
F_23 ( & V_4 -> V_5 , L_43 ) ;
V_10 = - V_136 ;
goto V_138;
}
V_2 -> V_139 = F_71 ( V_123 -> V_140 , F_72 ( V_123 ) ,
V_4 -> V_128 ) ;
if ( V_2 -> V_139 == NULL ) {
F_23 ( & V_4 -> V_5 , L_44 ) ;
V_10 = - V_47 ;
goto V_138;
}
V_2 -> V_17 = F_73 ( V_123 -> V_140 , F_72 ( V_123 ) ) ;
if ( V_2 -> V_17 == NULL ) {
F_23 ( & V_4 -> V_5 , L_45 ) ;
V_10 = - V_47 ;
goto V_141;
}
F_7 ( & V_4 -> V_5 , L_46 ,
V_2 -> V_17 , V_2 -> V_139 , V_123 ) ;
V_2 -> V_74 . V_75 = V_2 ;
V_2 -> V_74 . V_5 . V_142 = & V_4 -> V_5 ;
V_10 = F_60 ( V_2 ) ;
if ( V_10 != 0 )
goto V_143;
V_2 -> V_144 = V_10 = F_74 ( V_4 , 0 ) ;
if ( V_10 <= 0 ) {
F_23 ( & V_4 -> V_5 , L_47 ) ;
goto V_143;
}
V_10 = F_75 ( V_2 -> V_144 , F_25 , 0 ,
F_76 ( & V_4 -> V_5 ) , V_2 ) ;
if ( V_10 != 0 ) {
F_23 ( & V_4 -> V_5 , L_48 , V_2 -> V_144 ) ;
goto V_143;
}
V_10 = F_50 ( V_2 ) ;
if ( V_10 < 0 ) {
F_23 ( & V_4 -> V_5 , L_49 ) ;
goto V_145;
}
V_2 -> V_74 . V_146 = V_2 -> V_91 -> V_121 ;
V_2 -> V_74 . V_5 . V_7 = V_4 -> V_5 . V_7 ;
V_10 = F_77 ( & V_2 -> V_74 ) ;
if ( V_10 < 0 ) {
F_23 ( & V_4 -> V_5 , L_50 ) ;
goto V_147;
}
F_78 ( & V_2 -> V_74 ) ;
F_79 ( V_4 , V_2 ) ;
F_80 ( & V_4 -> V_5 ) ;
F_80 ( & V_2 -> V_74 . V_5 ) ;
F_49 ( & V_4 -> V_5 , L_51 , F_76 ( & V_2 -> V_74 . V_5 ) ) ;
F_37 ( V_2 -> V_77 ) ;
return 0 ;
V_147:
F_52 ( V_2 ) ;
V_145:
F_81 ( V_2 -> V_144 , V_2 ) ;
V_143:
F_82 ( V_2 -> V_17 ) ;
V_141:
F_83 ( V_2 -> V_139 ) ;
F_84 ( V_2 -> V_139 ) ;
V_138:
F_37 ( V_2 -> V_77 ) ;
F_85 ( V_2 -> V_77 ) ;
V_127:
return V_10 ;
}
static int F_86 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = F_87 ( V_4 ) ;
F_88 ( & V_2 -> V_74 . V_5 ) ;
F_88 ( & V_4 -> V_5 ) ;
F_52 ( V_2 ) ;
F_89 ( & V_2 -> V_74 ) ;
F_81 ( V_2 -> V_144 , V_2 ) ;
F_37 ( V_2 -> V_77 ) ;
F_85 ( V_2 -> V_77 ) ;
F_82 ( V_2 -> V_17 ) ;
F_83 ( V_2 -> V_139 ) ;
F_59 ( V_2 ) ;
F_84 ( V_2 -> V_139 ) ;
return 0 ;
}
static int F_90 ( struct V_148 * V_5 )
{
struct V_3 * V_4 = F_2 ( V_5 ) ;
struct V_1 * V_2 = F_87 ( V_4 ) ;
V_2 -> V_68 = 1 ;
return 0 ;
}
static int F_91 ( struct V_148 * V_5 )
{
struct V_3 * V_4 = F_2 ( V_5 ) ;
struct V_1 * V_2 = F_87 ( V_4 ) ;
V_2 -> V_68 = 0 ;
F_36 ( V_2 -> V_77 ) ;
F_60 ( V_2 ) ;
F_37 ( V_2 -> V_77 ) ;
return 0 ;
}
static int T_3 F_92 ( void )
{
return F_93 ( & V_149 ) ;
}
static void T_4 F_94 ( void )
{
F_95 ( & V_149 ) ;
}
