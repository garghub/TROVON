static struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( F_3 ( V_3 ) , struct V_1 ,
V_4 ) ;
}
static struct V_5 * F_4 ( struct V_2 * V_3 )
{
return F_1 ( V_3 ) -> V_6 ;
}
static struct V_5 * F_5 ( struct V_7 * V_8 )
{
return F_6 ( V_8 ) ;
}
static struct V_9 * F_7 ( struct V_7 * V_8 )
{
return F_8 ( & V_8 -> V_8 ) ;
}
static inline int F_9 ( struct V_5 * V_6 )
{
#ifdef F_10
return 1 ;
#else
return 0 ;
#endif
}
static void F_11 ( struct V_5 * V_6 ,
enum V_10 V_11 )
{
if ( ! F_9 ( V_6 ) && V_11 == V_12 )
return;
if ( V_6 -> V_13 == V_14 ) {
if ( V_11 != V_14 )
F_12 ( V_6 -> V_15 ) ;
} else {
if ( V_11 == V_14 )
F_13 ( V_6 -> V_15 ) ;
}
V_6 -> V_13 = V_11 ;
}
static int F_14 ( int V_16 , unsigned long V_15 , int V_17 )
{
int V_18 ;
V_18 = F_15 ( ( V_16 * V_15 ) , V_19 ) ;
F_16 ( L_1 , V_18 , V_15 , V_16 ) ;
if ( V_18 > V_17 ) {
F_17 ( L_2 ,
V_16 , V_15 ) ;
return - 1 ;
}
if ( V_18 < 1 )
V_18 = 1 ;
return V_18 ;
}
static int F_18 ( struct V_5 * V_6 )
{
struct V_9 * V_20 = V_6 -> V_21 ;
int V_22 = ( V_6 -> V_23 == V_24 ) ? 8 : 4 ;
int V_25 , V_26 , V_27 ;
unsigned long V_28 = F_19 ( V_6 -> V_15 ) ;
unsigned long V_29 ( V_30 ) , V_31 , V_29 ( V_32 ) ;
unsigned long V_33 ;
V_6 -> V_34 = V_28 ;
V_28 /= 1000 ;
if ( V_20 != NULL ) {
V_25 = F_14 ( V_20 -> V_25 , V_28 , V_22 ) ;
V_26 = F_14 ( V_20 -> V_26 , V_28 , 8 ) ;
V_27 = F_14 ( V_20 -> V_27 , V_28 , 8 ) ;
} else {
V_25 = V_22 ;
V_26 = 8 ;
V_27 = 8 ;
}
if ( V_25 < 0 || V_26 < 0 || V_27 < 0 ) {
F_20 ( V_6 -> V_35 , L_3 ) ;
return - V_36 ;
}
F_21 ( V_6 -> V_35 , L_4 ,
V_25 , F_22 ( V_25 , V_28 ) , V_26 , F_22 ( V_26 , V_28 ) ,
V_27 , F_22 ( V_27 , V_28 ) ) ;
switch ( V_6 -> V_23 ) {
case V_37 :
V_32 = ( F_23 ( 3 ) |
F_24 ( 7 ) |
F_25 ( 7 ) ) ;
V_30 = V_38 ;
V_30 |= F_23 ( V_25 - 1 ) ;
V_30 |= F_24 ( V_26 - 1 ) ;
V_30 |= F_25 ( V_27 - 1 ) ;
break;
case V_39 :
case V_24 :
V_32 = ( F_26 ( V_22 - 1 ) |
F_27 ( 7 ) |
F_28 ( 7 ) ) ;
V_30 = F_26 ( V_25 - 1 ) ;
V_30 |= F_27 ( V_26 - 1 ) ;
V_30 |= F_28 ( V_27 - 1 ) ;
break;
default:
F_29 () ;
}
F_30 ( V_33 ) ;
V_31 = F_31 ( V_6 -> V_40 + V_41 ) ;
V_31 &= ~ V_32 ;
V_31 |= V_30 ;
F_32 ( V_31 , V_6 -> V_40 + V_41 ) ;
F_33 ( V_33 ) ;
F_34 ( V_6 -> V_35 , L_5 , V_31 ) ;
return 0 ;
}
static int F_35 ( struct V_5 * V_6 )
{
int V_42 ;
V_42 = F_18 ( V_6 ) ;
if ( V_42 < 0 )
return V_42 ;
switch ( V_6 -> V_23 ) {
case V_37 :
default:
break;
case V_39 :
case V_24 :
F_32 ( V_43 , V_6 -> V_40 + V_44 ) ;
}
return 0 ;
}
static void F_36 ( struct V_2 * V_3 , int V_4 )
{
struct V_5 * V_6 ;
struct V_1 * V_45 ;
struct V_46 * V_47 = F_3 ( V_3 ) ;
unsigned long V_48 ;
V_45 = F_37 ( V_47 ) ;
V_6 = V_45 -> V_6 ;
if ( V_4 != - 1 )
F_11 ( V_6 , V_14 ) ;
V_48 = F_31 ( V_6 -> V_49 ) ;
if ( V_4 == - 1 ) {
V_48 |= V_6 -> V_50 ;
} else {
if ( V_45 -> V_30 != NULL && V_4 > V_45 -> V_30 -> V_51 ) {
F_20 ( V_6 -> V_35 , L_6 , V_4 ) ;
return;
}
if ( V_6 -> V_21 != NULL ) {
if ( V_6 -> V_21 -> V_52 != NULL )
( V_6 -> V_21 -> V_52 ) ( V_45 -> V_30 , V_4 ) ;
}
V_48 &= ~ V_6 -> V_50 ;
}
F_32 ( V_48 , V_6 -> V_49 ) ;
if ( V_4 == - 1 )
F_11 ( V_6 , V_12 ) ;
}
static void F_38 ( struct V_2 * V_3 , int V_53 ,
unsigned int V_54 )
{
struct V_5 * V_6 = F_4 ( V_3 ) ;
if ( V_53 == V_55 )
return;
if ( V_54 & V_56 )
F_39 ( V_53 , V_6 -> V_40 + V_57 ) ;
else
F_39 ( V_53 , V_6 -> V_40 + V_58 ) ;
}
static void F_40 ( struct V_2 * V_3 , int V_53 ,
unsigned int V_54 )
{
struct V_5 * V_6 = F_4 ( V_3 ) ;
if ( V_53 == V_55 )
return;
if ( V_54 & V_56 )
F_39 ( V_53 , V_6 -> V_40 + V_59 ) ;
else
F_39 ( V_53 , V_6 -> V_40 + V_60 ) ;
}
static int F_41 ( struct V_2 * V_3 )
{
struct V_5 * V_6 = F_4 ( V_3 ) ;
return F_42 ( V_6 -> V_40 + V_61 ) & V_62 ;
}
static int F_43 ( struct V_2 * V_3 )
{
struct V_5 * V_6 = F_4 ( V_3 ) ;
return F_42 ( V_6 -> V_40 + V_63 ) & V_64 ;
}
static int F_44 ( struct V_2 * V_3 )
{
struct V_5 * V_6 = F_4 ( V_3 ) ;
return F_42 ( V_6 -> V_40 + V_65 ) & V_66 ;
}
static int F_45 ( struct V_2 * V_3 , T_1 * V_67 ,
T_1 * V_68 , T_1 * V_69 )
{
struct V_5 * V_6 = F_4 ( V_3 ) ;
unsigned int V_70 , V_71 , V_72 ;
unsigned int V_73 , V_74 ;
F_16 ( L_7 , V_75 , V_3 , V_67 , V_68 , V_69 ) ;
V_70 = V_68 [ 0 ] ^ V_69 [ 0 ] ;
V_71 = V_68 [ 1 ] ^ V_69 [ 1 ] ;
V_72 = V_68 [ 2 ] ^ V_69 [ 2 ] ;
F_16 ( L_8 ,
V_75 , 3 , V_68 , 3 , V_69 ,
V_70 , V_71 , V_72 ) ;
if ( V_70 == 0 && V_71 == 0 && V_72 == 0 )
return 0 ;
if ( V_68 [ 0 ] == 0xff && V_68 [ 1 ] == 0xff && V_68 [ 2 ] == 0xff
&& V_6 -> V_21 -> V_76 )
return 0 ;
if ( ( ( V_70 ^ ( V_70 >> 1 ) ) & 0x55 ) == 0x55 &&
( ( V_71 ^ ( V_71 >> 1 ) ) & 0x55 ) == 0x55 &&
( ( V_72 ^ ( V_72 >> 1 ) ) & 0x55 ) == 0x55 ) {
V_73 = ( ( V_72 >> 3 ) & 1 ) |
( ( V_72 >> 4 ) & 2 ) |
( ( V_72 >> 5 ) & 4 ) ;
V_74 = ( ( V_72 << 7 ) & 0x100 ) |
( ( V_71 << 0 ) & 0x80 ) |
( ( V_71 << 1 ) & 0x40 ) |
( ( V_71 << 2 ) & 0x20 ) |
( ( V_71 << 3 ) & 0x10 ) |
( ( V_70 >> 4 ) & 0x08 ) |
( ( V_70 >> 3 ) & 0x04 ) |
( ( V_70 >> 2 ) & 0x02 ) |
( ( V_70 >> 1 ) & 0x01 ) ;
F_34 ( V_6 -> V_35 , L_9 ,
V_73 , V_74 ) ;
V_67 [ V_74 ] ^= ( 1 << V_73 ) ;
return 1 ;
}
V_70 |= ( V_71 << 8 ) ;
V_70 |= ( V_72 << 16 ) ;
if ( ( V_70 & ~ ( 1 << F_46 ( V_70 ) ) ) == 0 )
return 1 ;
return - 1 ;
}
static void F_47 ( struct V_2 * V_3 , int V_77 )
{
struct V_5 * V_6 = F_4 ( V_3 ) ;
unsigned long V_54 ;
V_54 = F_31 ( V_6 -> V_40 + V_41 ) ;
V_54 |= V_78 ;
F_32 ( V_54 , V_6 -> V_40 + V_41 ) ;
}
static void F_48 ( struct V_2 * V_3 , int V_77 )
{
struct V_5 * V_6 = F_4 ( V_3 ) ;
unsigned long V_54 ;
V_54 = F_31 ( V_6 -> V_40 + V_44 ) ;
F_32 ( V_54 | V_79 ,
V_6 -> V_40 + V_44 ) ;
}
static void F_49 ( struct V_2 * V_3 , int V_77 )
{
struct V_5 * V_6 = F_4 ( V_3 ) ;
unsigned long V_54 ;
V_54 = F_31 ( V_6 -> V_40 + V_44 ) ;
F_32 ( V_54 | V_80 , V_6 -> V_40 + V_44 ) ;
}
static int F_50 ( struct V_2 * V_3 , const T_1 * V_67 ,
T_1 * V_81 )
{
struct V_5 * V_6 = F_4 ( V_3 ) ;
V_81 [ 0 ] = F_42 ( V_6 -> V_40 + V_82 + 0 ) ;
V_81 [ 1 ] = F_42 ( V_6 -> V_40 + V_82 + 1 ) ;
V_81 [ 2 ] = F_42 ( V_6 -> V_40 + V_82 + 2 ) ;
F_16 ( L_10 , V_75 , 3 , V_81 ) ;
return 0 ;
}
static int F_51 ( struct V_2 * V_3 , const T_1 * V_67 ,
T_1 * V_81 )
{
struct V_5 * V_6 = F_4 ( V_3 ) ;
unsigned long V_83 = F_31 ( V_6 -> V_40 + V_84 ) ;
V_81 [ 0 ] = V_83 ;
V_81 [ 1 ] = V_83 >> 8 ;
V_81 [ 2 ] = V_83 >> 16 ;
F_16 ( L_10 , V_75 , 3 , V_81 ) ;
return 0 ;
}
static int F_52 ( struct V_2 * V_3 , const T_1 * V_67 ,
T_1 * V_81 )
{
struct V_5 * V_6 = F_4 ( V_3 ) ;
unsigned long V_83 = F_31 ( V_6 -> V_40 + V_85 ) ;
V_81 [ 0 ] = V_83 ;
V_81 [ 1 ] = V_83 >> 8 ;
V_81 [ 2 ] = V_83 >> 16 ;
F_16 ( L_11 , V_75 , V_83 & 0xffffff ) ;
return 0 ;
}
static void F_53 ( struct V_2 * V_3 , T_1 * V_86 , int V_87 )
{
struct V_46 * V_47 = F_3 ( V_3 ) ;
F_54 ( V_47 -> V_88 , V_86 , V_87 ) ;
}
static void F_55 ( struct V_2 * V_3 , T_1 * V_86 , int V_87 )
{
struct V_5 * V_6 = F_4 ( V_3 ) ;
F_56 ( V_6 -> V_40 + V_89 , V_86 , V_87 >> 2 ) ;
if ( V_87 & 3 ) {
V_86 += V_87 & ~ 3 ;
for (; V_87 & 3 ; V_87 -- )
* V_86 ++ = F_42 ( V_6 -> V_40 + V_89 ) ;
}
}
static void F_57 ( struct V_2 * V_3 , const T_1 * V_86 ,
int V_87 )
{
struct V_46 * V_47 = F_3 ( V_3 ) ;
F_58 ( V_47 -> V_90 , V_86 , V_87 ) ;
}
static void F_59 ( struct V_2 * V_3 , const T_1 * V_86 ,
int V_87 )
{
struct V_5 * V_6 = F_4 ( V_3 ) ;
F_60 ( V_6 -> V_40 + V_89 , V_86 , V_87 >> 2 ) ;
if ( V_87 & 3 ) {
V_86 += V_87 & ~ 3 ;
for (; V_87 & 3 ; V_87 -- , V_86 ++ )
F_39 ( * V_86 , V_6 -> V_40 + V_89 ) ;
}
}
static int F_61 ( struct V_91 * V_92 ,
unsigned long V_93 , void * V_94 )
{
struct V_5 * V_6 ;
unsigned long V_95 ;
V_6 = F_2 ( V_92 , struct V_5 , V_96 ) ;
V_95 = F_19 ( V_6 -> V_15 ) ;
if ( ( V_93 == V_97 && V_95 < V_6 -> V_34 ) ||
( V_93 == V_98 && V_95 > V_6 -> V_34 ) ) {
F_18 ( V_6 ) ;
}
return 0 ;
}
static inline int F_62 ( struct V_5 * V_6 )
{
V_6 -> V_96 . V_99 = F_61 ;
return F_63 ( & V_6 -> V_96 ,
V_100 ) ;
}
static inline void
F_64 ( struct V_5 * V_6 )
{
F_65 ( & V_6 -> V_96 ,
V_100 ) ;
}
static inline int F_62 ( struct V_5 * V_6 )
{
return 0 ;
}
static inline void
F_64 ( struct V_5 * V_6 )
{
}
static int F_66 ( struct V_7 * V_101 )
{
struct V_5 * V_6 = F_5 ( V_101 ) ;
if ( V_6 == NULL )
return 0 ;
F_64 ( V_6 ) ;
if ( V_6 -> V_102 != NULL ) {
struct V_1 * V_103 = V_6 -> V_102 ;
int V_104 ;
for ( V_104 = 0 ; V_104 < V_6 -> V_105 ; V_104 ++ , V_103 ++ ) {
F_16 ( L_12 , V_104 , V_103 ) ;
F_67 ( F_68 ( & V_103 -> V_4 ) ) ;
}
}
if ( ! F_69 ( V_6 -> V_15 ) )
F_11 ( V_6 , V_106 ) ;
return 0 ;
}
static int F_70 ( struct V_5 * V_6 ,
struct V_1 * V_3 ,
struct V_107 * V_30 )
{
if ( V_30 ) {
struct V_2 * V_108 = F_68 ( & V_3 -> V_4 ) ;
V_108 -> V_109 = V_30 -> V_109 ;
return F_71 ( V_108 , NULL , NULL ,
V_30 -> V_110 , V_30 -> V_111 ) ;
}
return - V_112 ;
}
static void F_72 ( struct V_5 * V_6 ,
struct V_1 * V_45 ,
struct V_107 * V_30 )
{
struct V_46 * V_4 = & V_45 -> V_4 ;
void T_2 * V_40 = V_6 -> V_40 ;
V_4 -> V_113 = F_57 ;
V_4 -> V_114 = F_53 ;
V_4 -> V_52 = F_36 ;
V_4 -> V_115 = 50 ;
F_73 ( V_4 , V_45 ) ;
V_4 -> V_116 = V_30 -> V_116 ;
V_4 -> V_117 = & V_6 -> V_117 ;
switch ( V_6 -> V_23 ) {
case V_37 :
V_4 -> V_90 = V_40 + V_118 ;
V_6 -> V_49 = V_40 + V_41 ;
V_6 -> V_50 = V_119 ;
V_4 -> V_120 = F_38 ;
V_4 -> V_121 = F_41 ;
break;
case V_39 :
V_4 -> V_90 = V_40 + V_89 ;
V_6 -> V_49 = V_40 + V_44 ;
V_6 -> V_50 = V_122 ;
V_4 -> V_120 = F_40 ;
V_4 -> V_121 = F_43 ;
V_4 -> V_114 = F_55 ;
V_4 -> V_113 = F_59 ;
break;
case V_24 :
V_4 -> V_90 = V_40 + V_89 ;
V_6 -> V_49 = V_40 + V_44 ;
V_6 -> V_50 = V_123 ;
V_4 -> V_120 = F_40 ;
V_4 -> V_121 = F_44 ;
if ( F_31 ( V_40 + V_41 ) & V_124 )
F_21 ( V_6 -> V_35 , L_13 ) ;
break;
}
V_4 -> V_88 = V_4 -> V_90 ;
V_45 -> V_6 = V_6 ;
V_45 -> V_30 = V_30 ;
#ifdef F_74
V_4 -> V_83 . V_125 = F_50 ;
V_4 -> V_83 . V_126 = F_45 ;
V_4 -> V_83 . V_77 = V_127 ;
V_4 -> V_83 . V_128 = 1 ;
switch ( V_6 -> V_23 ) {
case V_37 :
V_4 -> V_83 . V_129 = F_47 ;
V_4 -> V_83 . V_125 = F_50 ;
break;
case V_24 :
V_4 -> V_83 . V_129 = F_48 ;
V_4 -> V_83 . V_125 = F_51 ;
break;
case V_39 :
V_4 -> V_83 . V_129 = F_49 ;
V_4 -> V_83 . V_125 = F_52 ;
break;
}
#else
V_4 -> V_83 . V_77 = V_130 ;
#endif
if ( V_30 -> V_131 )
V_4 -> V_83 . V_77 = V_132 ;
switch ( V_4 -> V_83 . V_77 ) {
case V_132 :
F_21 ( V_6 -> V_35 , L_14 ) ;
break;
case V_130 :
F_21 ( V_6 -> V_35 , L_15 ) ;
break;
case V_127 :
F_21 ( V_6 -> V_35 , L_16 ) ;
break;
default:
F_21 ( V_6 -> V_35 , L_17 ) ;
break;
}
if ( V_30 -> V_133 ) {
V_4 -> V_134 |= V_135 ;
V_4 -> V_116 |= V_136 ;
}
}
static void F_75 ( struct V_5 * V_6 ,
struct V_1 * V_45 )
{
struct V_46 * V_4 = & V_45 -> V_4 ;
F_34 ( V_6 -> V_35 , L_18 ,
V_4 , V_4 -> V_137 ) ;
if ( V_4 -> V_83 . V_77 != V_127 )
return;
if ( V_4 -> V_137 > 10 ) {
V_4 -> V_83 . V_138 = 256 ;
V_4 -> V_83 . V_139 = 3 ;
} else {
V_4 -> V_83 . V_138 = 512 ;
V_4 -> V_83 . V_139 = 3 ;
V_4 -> V_83 . V_140 = & V_141 ;
}
}
static int F_76 ( struct V_7 * V_101 )
{
struct V_9 * V_20 = F_7 ( V_101 ) ;
enum V_142 V_23 ;
struct V_5 * V_6 ;
struct V_1 * V_45 ;
struct V_107 * V_143 ;
struct V_144 * V_145 ;
int V_146 = 0 ;
int V_138 ;
int V_147 ;
int V_148 ;
V_23 = F_77 ( V_101 ) -> V_149 ;
V_6 = F_78 ( & V_101 -> V_8 , sizeof( * V_6 ) , V_150 ) ;
if ( V_6 == NULL ) {
V_146 = - V_151 ;
goto V_152;
}
F_79 ( V_101 , V_6 ) ;
F_80 ( & V_6 -> V_117 . V_153 ) ;
F_81 ( & V_6 -> V_117 . V_154 ) ;
V_6 -> V_15 = F_82 ( & V_101 -> V_8 , L_19 ) ;
if ( F_69 ( V_6 -> V_15 ) ) {
F_20 ( & V_101 -> V_8 , L_20 ) ;
V_146 = - V_155 ;
goto V_152;
}
F_11 ( V_6 , V_14 ) ;
V_145 = V_101 -> V_144 ;
V_138 = F_83 ( V_145 ) ;
V_6 -> V_35 = & V_101 -> V_8 ;
V_6 -> V_21 = V_20 ;
V_6 -> V_23 = V_23 ;
V_6 -> V_40 = F_84 ( & V_101 -> V_8 , V_145 ) ;
if ( F_69 ( V_6 -> V_40 ) ) {
V_146 = F_85 ( V_6 -> V_40 ) ;
goto V_152;
}
F_34 ( & V_101 -> V_8 , L_21 , V_6 -> V_40 ) ;
V_146 = F_35 ( V_6 ) ;
if ( V_146 != 0 )
goto V_152;
V_143 = ( V_20 != NULL ) ? V_20 -> V_143 : NULL ;
V_147 = ( V_20 != NULL ) ? V_20 -> V_147 : 1 ;
V_6 -> V_105 = V_147 ;
V_138 = V_147 * sizeof( * V_6 -> V_102 ) ;
V_6 -> V_102 = F_78 ( & V_101 -> V_8 , V_138 , V_150 ) ;
if ( V_6 -> V_102 == NULL ) {
V_146 = - V_151 ;
goto V_152;
}
V_45 = V_6 -> V_102 ;
for ( V_148 = 0 ; V_148 < V_147 ; V_148 ++ , V_45 ++ ) {
struct V_2 * V_3 = F_68 ( & V_45 -> V_4 ) ;
F_16 ( L_22 ,
V_148 , V_45 , V_6 ) ;
V_3 -> V_8 . V_156 = & V_101 -> V_8 ;
F_72 ( V_6 , V_45 , V_143 ) ;
V_45 -> V_157 = F_86 ( V_3 ,
( V_143 ) ? V_143 -> V_51 : 1 ,
NULL ) ;
if ( V_45 -> V_157 == 0 ) {
F_75 ( V_6 , V_45 ) ;
F_87 ( V_3 ) ;
F_70 ( V_6 , V_45 , V_143 ) ;
}
if ( V_143 != NULL )
V_143 ++ ;
}
V_146 = F_62 ( V_6 ) ;
if ( V_146 < 0 ) {
F_20 ( & V_101 -> V_8 , L_23 ) ;
goto V_152;
}
if ( F_9 ( V_6 ) ) {
F_21 ( & V_101 -> V_8 , L_24 ) ;
F_11 ( V_6 , V_12 ) ;
}
return 0 ;
V_152:
F_66 ( V_101 ) ;
if ( V_146 == 0 )
V_146 = - V_36 ;
return V_146 ;
}
static int F_88 ( struct V_7 * V_8 , T_3 V_158 )
{
struct V_5 * V_6 = F_6 ( V_8 ) ;
if ( V_6 ) {
V_6 -> V_159 = F_31 ( V_6 -> V_49 ) ;
F_32 ( V_6 -> V_159 | V_6 -> V_50 , V_6 -> V_49 ) ;
F_11 ( V_6 , V_106 ) ;
}
return 0 ;
}
static int F_89 ( struct V_7 * V_8 )
{
struct V_5 * V_6 = F_6 ( V_8 ) ;
unsigned long V_160 ;
if ( V_6 ) {
F_11 ( V_6 , V_14 ) ;
F_35 ( V_6 ) ;
V_160 = F_31 ( V_6 -> V_49 ) ;
V_160 &= ~ V_6 -> V_50 ;
V_160 |= V_6 -> V_159 & V_6 -> V_50 ;
F_32 ( V_160 , V_6 -> V_49 ) ;
F_11 ( V_6 , V_12 ) ;
}
return 0 ;
}
