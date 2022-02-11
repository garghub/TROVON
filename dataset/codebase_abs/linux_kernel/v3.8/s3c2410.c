static struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_3 ) ;
}
static struct V_4 * F_3 ( struct V_2 * V_3 )
{
return F_1 ( V_3 ) -> V_5 ;
}
static struct V_4 * F_4 ( struct V_6 * V_7 )
{
return F_5 ( V_7 ) ;
}
static struct V_8 * F_6 ( struct V_6 * V_7 )
{
return V_7 -> V_7 . V_9 ;
}
static inline int F_7 ( struct V_4 * V_5 )
{
#ifdef F_8
return 1 ;
#else
return 0 ;
#endif
}
static void F_9 ( struct V_4 * V_5 ,
enum V_10 V_11 )
{
if ( ! F_7 ( V_5 ) && V_11 == V_12 )
return;
if ( V_5 -> V_13 == V_14 ) {
if ( V_11 != V_14 )
F_10 ( V_5 -> V_15 ) ;
} else {
if ( V_11 == V_14 )
F_11 ( V_5 -> V_15 ) ;
}
V_5 -> V_13 = V_11 ;
}
static int F_12 ( int V_16 , unsigned long V_15 , int V_17 )
{
int V_18 ;
V_18 = F_13 ( ( V_16 * V_15 ) , V_19 ) ;
F_14 ( L_1 , V_18 , V_15 , V_16 ) ;
if ( V_18 > V_17 ) {
F_15 ( L_2 ,
V_16 , V_15 ) ;
return - 1 ;
}
if ( V_18 < 1 )
V_18 = 1 ;
return V_18 ;
}
static int F_16 ( struct V_4 * V_5 )
{
struct V_8 * V_20 = V_5 -> V_21 ;
int V_22 = ( V_5 -> V_23 == V_24 ) ? 8 : 4 ;
int V_25 , V_26 , V_27 ;
unsigned long V_28 = F_17 ( V_5 -> V_15 ) ;
unsigned long V_29 ( V_30 ) , V_31 , V_29 ( V_32 ) ;
unsigned long V_33 ;
V_5 -> V_34 = V_28 ;
V_28 /= 1000 ;
if ( V_20 != NULL ) {
V_25 = F_12 ( V_20 -> V_25 , V_28 , V_22 ) ;
V_26 = F_12 ( V_20 -> V_26 , V_28 , 8 ) ;
V_27 = F_12 ( V_20 -> V_27 , V_28 , 8 ) ;
} else {
V_25 = V_22 ;
V_26 = 8 ;
V_27 = 8 ;
}
if ( V_25 < 0 || V_26 < 0 || V_27 < 0 ) {
F_18 ( V_5 -> V_35 , L_3 ) ;
return - V_36 ;
}
F_19 ( V_5 -> V_35 , L_4 ,
V_25 , F_20 ( V_25 , V_28 ) , V_26 , F_20 ( V_26 , V_28 ) ,
V_27 , F_20 ( V_27 , V_28 ) ) ;
switch ( V_5 -> V_23 ) {
case V_37 :
V_32 = ( F_21 ( 3 ) |
F_22 ( 7 ) |
F_23 ( 7 ) ) ;
V_30 = V_38 ;
V_30 |= F_21 ( V_25 - 1 ) ;
V_30 |= F_22 ( V_26 - 1 ) ;
V_30 |= F_23 ( V_27 - 1 ) ;
break;
case V_39 :
case V_24 :
V_32 = ( F_24 ( V_22 - 1 ) |
F_25 ( 7 ) |
F_26 ( 7 ) ) ;
V_30 = F_24 ( V_25 - 1 ) ;
V_30 |= F_25 ( V_26 - 1 ) ;
V_30 |= F_26 ( V_27 - 1 ) ;
break;
default:
F_27 () ;
}
F_28 ( V_33 ) ;
V_31 = F_29 ( V_5 -> V_40 + V_41 ) ;
V_31 &= ~ V_32 ;
V_31 |= V_30 ;
F_30 ( V_31 , V_5 -> V_40 + V_41 ) ;
F_31 ( V_33 ) ;
F_32 ( V_5 -> V_35 , L_5 , V_31 ) ;
return 0 ;
}
static int F_33 ( struct V_4 * V_5 )
{
int V_42 ;
V_42 = F_16 ( V_5 ) ;
if ( V_42 < 0 )
return V_42 ;
switch ( V_5 -> V_23 ) {
case V_37 :
default:
break;
case V_39 :
case V_24 :
F_30 ( V_43 , V_5 -> V_40 + V_44 ) ;
}
return 0 ;
}
static void F_34 ( struct V_2 * V_3 , int V_45 )
{
struct V_4 * V_5 ;
struct V_1 * V_46 ;
struct V_47 * V_48 = V_3 -> V_49 ;
unsigned long V_50 ;
V_46 = V_48 -> V_49 ;
V_5 = V_46 -> V_5 ;
if ( V_45 != - 1 )
F_9 ( V_5 , V_14 ) ;
V_50 = F_29 ( V_5 -> V_51 ) ;
if ( V_45 == - 1 ) {
V_50 |= V_5 -> V_52 ;
} else {
if ( V_46 -> V_30 != NULL && V_45 > V_46 -> V_30 -> V_53 ) {
F_18 ( V_5 -> V_35 , L_6 , V_45 ) ;
return;
}
if ( V_5 -> V_21 != NULL ) {
if ( V_5 -> V_21 -> V_54 != NULL )
( V_5 -> V_21 -> V_54 ) ( V_46 -> V_30 , V_45 ) ;
}
V_50 &= ~ V_5 -> V_52 ;
}
F_30 ( V_50 , V_5 -> V_51 ) ;
if ( V_45 == - 1 )
F_9 ( V_5 , V_12 ) ;
}
static void F_35 ( struct V_2 * V_3 , int V_55 ,
unsigned int V_56 )
{
struct V_4 * V_5 = F_3 ( V_3 ) ;
if ( V_55 == V_57 )
return;
if ( V_56 & V_58 )
F_36 ( V_55 , V_5 -> V_40 + V_59 ) ;
else
F_36 ( V_55 , V_5 -> V_40 + V_60 ) ;
}
static void F_37 ( struct V_2 * V_3 , int V_55 ,
unsigned int V_56 )
{
struct V_4 * V_5 = F_3 ( V_3 ) ;
if ( V_55 == V_57 )
return;
if ( V_56 & V_58 )
F_36 ( V_55 , V_5 -> V_40 + V_61 ) ;
else
F_36 ( V_55 , V_5 -> V_40 + V_62 ) ;
}
static int F_38 ( struct V_2 * V_3 )
{
struct V_4 * V_5 = F_3 ( V_3 ) ;
return F_39 ( V_5 -> V_40 + V_63 ) & V_64 ;
}
static int F_40 ( struct V_2 * V_3 )
{
struct V_4 * V_5 = F_3 ( V_3 ) ;
return F_39 ( V_5 -> V_40 + V_65 ) & V_66 ;
}
static int F_41 ( struct V_2 * V_3 )
{
struct V_4 * V_5 = F_3 ( V_3 ) ;
return F_39 ( V_5 -> V_40 + V_67 ) & V_68 ;
}
static int F_42 ( struct V_2 * V_3 , T_1 * V_69 ,
T_1 * V_70 , T_1 * V_71 )
{
struct V_4 * V_5 = F_3 ( V_3 ) ;
unsigned int V_72 , V_73 , V_74 ;
unsigned int V_75 , V_76 ;
F_14 ( L_7 , V_77 , V_3 , V_69 , V_70 , V_71 ) ;
V_72 = V_70 [ 0 ] ^ V_71 [ 0 ] ;
V_73 = V_70 [ 1 ] ^ V_71 [ 1 ] ;
V_74 = V_70 [ 2 ] ^ V_71 [ 2 ] ;
F_14 ( L_8 ,
V_77 , 3 , V_70 , 3 , V_71 ,
V_72 , V_73 , V_74 ) ;
if ( V_72 == 0 && V_73 == 0 && V_74 == 0 )
return 0 ;
if ( V_70 [ 0 ] == 0xff && V_70 [ 1 ] == 0xff && V_70 [ 2 ] == 0xff
&& V_5 -> V_21 -> V_78 )
return 0 ;
if ( ( ( V_72 ^ ( V_72 >> 1 ) ) & 0x55 ) == 0x55 &&
( ( V_73 ^ ( V_73 >> 1 ) ) & 0x55 ) == 0x55 &&
( ( V_74 ^ ( V_74 >> 1 ) ) & 0x55 ) == 0x55 ) {
V_75 = ( ( V_74 >> 3 ) & 1 ) |
( ( V_74 >> 4 ) & 2 ) |
( ( V_74 >> 5 ) & 4 ) ;
V_76 = ( ( V_74 << 7 ) & 0x100 ) |
( ( V_73 << 0 ) & 0x80 ) |
( ( V_73 << 1 ) & 0x40 ) |
( ( V_73 << 2 ) & 0x20 ) |
( ( V_73 << 3 ) & 0x10 ) |
( ( V_72 >> 4 ) & 0x08 ) |
( ( V_72 >> 3 ) & 0x04 ) |
( ( V_72 >> 2 ) & 0x02 ) |
( ( V_72 >> 1 ) & 0x01 ) ;
F_32 ( V_5 -> V_35 , L_9 ,
V_75 , V_76 ) ;
V_69 [ V_76 ] ^= ( 1 << V_75 ) ;
return 1 ;
}
V_72 |= ( V_73 << 8 ) ;
V_72 |= ( V_74 << 16 ) ;
if ( ( V_72 & ~ ( 1 << F_43 ( V_72 ) ) ) == 0 )
return 1 ;
return - 1 ;
}
static void F_44 ( struct V_2 * V_3 , int V_79 )
{
struct V_4 * V_5 = F_3 ( V_3 ) ;
unsigned long V_56 ;
V_56 = F_29 ( V_5 -> V_40 + V_41 ) ;
V_56 |= V_80 ;
F_30 ( V_56 , V_5 -> V_40 + V_41 ) ;
}
static void F_45 ( struct V_2 * V_3 , int V_79 )
{
struct V_4 * V_5 = F_3 ( V_3 ) ;
unsigned long V_56 ;
V_56 = F_29 ( V_5 -> V_40 + V_44 ) ;
F_30 ( V_56 | V_81 ,
V_5 -> V_40 + V_44 ) ;
}
static void F_46 ( struct V_2 * V_3 , int V_79 )
{
struct V_4 * V_5 = F_3 ( V_3 ) ;
unsigned long V_56 ;
V_56 = F_29 ( V_5 -> V_40 + V_44 ) ;
F_30 ( V_56 | V_82 , V_5 -> V_40 + V_44 ) ;
}
static int F_47 ( struct V_2 * V_3 , const T_1 * V_69 ,
T_1 * V_83 )
{
struct V_4 * V_5 = F_3 ( V_3 ) ;
V_83 [ 0 ] = F_39 ( V_5 -> V_40 + V_84 + 0 ) ;
V_83 [ 1 ] = F_39 ( V_5 -> V_40 + V_84 + 1 ) ;
V_83 [ 2 ] = F_39 ( V_5 -> V_40 + V_84 + 2 ) ;
F_14 ( L_10 , V_77 , 3 , V_83 ) ;
return 0 ;
}
static int F_48 ( struct V_2 * V_3 , const T_1 * V_69 ,
T_1 * V_83 )
{
struct V_4 * V_5 = F_3 ( V_3 ) ;
unsigned long V_85 = F_29 ( V_5 -> V_40 + V_86 ) ;
V_83 [ 0 ] = V_85 ;
V_83 [ 1 ] = V_85 >> 8 ;
V_83 [ 2 ] = V_85 >> 16 ;
F_14 ( L_10 , V_77 , 3 , V_83 ) ;
return 0 ;
}
static int F_49 ( struct V_2 * V_3 , const T_1 * V_69 ,
T_1 * V_83 )
{
struct V_4 * V_5 = F_3 ( V_3 ) ;
unsigned long V_85 = F_29 ( V_5 -> V_40 + V_87 ) ;
V_83 [ 0 ] = V_85 ;
V_83 [ 1 ] = V_85 >> 8 ;
V_83 [ 2 ] = V_85 >> 16 ;
F_14 ( L_11 , V_77 , V_85 & 0xffffff ) ;
return 0 ;
}
static void F_50 ( struct V_2 * V_3 , T_1 * V_88 , int V_89 )
{
struct V_47 * V_48 = V_3 -> V_49 ;
F_51 ( V_48 -> V_90 , V_88 , V_89 ) ;
}
static void F_52 ( struct V_2 * V_3 , T_1 * V_88 , int V_89 )
{
struct V_4 * V_5 = F_3 ( V_3 ) ;
F_53 ( V_5 -> V_40 + V_91 , V_88 , V_89 >> 2 ) ;
if ( V_89 & 3 ) {
V_88 += V_89 & ~ 3 ;
for (; V_89 & 3 ; V_89 -- )
* V_88 ++ = F_39 ( V_5 -> V_40 + V_91 ) ;
}
}
static void F_54 ( struct V_2 * V_3 , const T_1 * V_88 ,
int V_89 )
{
struct V_47 * V_48 = V_3 -> V_49 ;
F_55 ( V_48 -> V_92 , V_88 , V_89 ) ;
}
static void F_56 ( struct V_2 * V_3 , const T_1 * V_88 ,
int V_89 )
{
struct V_4 * V_5 = F_3 ( V_3 ) ;
F_57 ( V_5 -> V_40 + V_91 , V_88 , V_89 >> 2 ) ;
if ( V_89 & 3 ) {
V_88 += V_89 & ~ 3 ;
for (; V_89 & 3 ; V_89 -- , V_88 ++ )
F_36 ( * V_88 , V_5 -> V_40 + V_91 ) ;
}
}
static int F_58 ( struct V_93 * V_94 ,
unsigned long V_95 , void * V_96 )
{
struct V_4 * V_5 ;
unsigned long V_97 ;
V_5 = F_2 ( V_94 , struct V_4 , V_98 ) ;
V_97 = F_17 ( V_5 -> V_15 ) ;
if ( ( V_95 == V_99 && V_97 < V_5 -> V_34 ) ||
( V_95 == V_100 && V_97 > V_5 -> V_34 ) ) {
F_16 ( V_5 ) ;
}
return 0 ;
}
static inline int F_59 ( struct V_4 * V_5 )
{
V_5 -> V_98 . V_101 = F_58 ;
return F_60 ( & V_5 -> V_98 ,
V_102 ) ;
}
static inline void
F_61 ( struct V_4 * V_5 )
{
F_62 ( & V_5 -> V_98 ,
V_102 ) ;
}
static inline int F_59 ( struct V_4 * V_5 )
{
return 0 ;
}
static inline void
F_61 ( struct V_4 * V_5 )
{
}
static int F_63 ( struct V_6 * V_103 )
{
struct V_4 * V_5 = F_4 ( V_103 ) ;
F_64 ( V_103 , NULL ) ;
if ( V_5 == NULL )
return 0 ;
F_61 ( V_5 ) ;
if ( V_5 -> V_104 != NULL ) {
struct V_1 * V_105 = V_5 -> V_104 ;
int V_106 ;
for ( V_106 = 0 ; V_106 < V_5 -> V_107 ; V_106 ++ , V_105 ++ ) {
F_14 ( L_12 , V_106 , V_105 ) ;
F_65 ( & V_105 -> V_3 ) ;
}
}
if ( ! F_66 ( V_5 -> V_15 ) )
F_9 ( V_5 , V_108 ) ;
return 0 ;
}
static int F_67 ( struct V_4 * V_5 ,
struct V_1 * V_3 ,
struct V_109 * V_30 )
{
if ( V_30 ) {
V_3 -> V_3 . V_110 = V_30 -> V_110 ;
return F_68 ( & V_3 -> V_3 , NULL , NULL ,
V_30 -> V_111 , V_30 -> V_112 ) ;
}
return - V_113 ;
}
static void F_69 ( struct V_4 * V_5 ,
struct V_1 * V_46 ,
struct V_109 * V_30 )
{
struct V_47 * V_45 = & V_46 -> V_45 ;
void T_2 * V_40 = V_5 -> V_40 ;
V_45 -> V_114 = F_54 ;
V_45 -> V_115 = F_50 ;
V_45 -> V_54 = F_34 ;
V_45 -> V_116 = 50 ;
V_45 -> V_49 = V_46 ;
V_45 -> V_117 = V_30 -> V_117 ;
V_45 -> V_118 = & V_5 -> V_118 ;
switch ( V_5 -> V_23 ) {
case V_37 :
V_45 -> V_92 = V_40 + V_119 ;
V_5 -> V_51 = V_40 + V_41 ;
V_5 -> V_52 = V_120 ;
V_45 -> V_121 = F_35 ;
V_45 -> V_122 = F_38 ;
break;
case V_39 :
V_45 -> V_92 = V_40 + V_91 ;
V_5 -> V_51 = V_40 + V_44 ;
V_5 -> V_52 = V_123 ;
V_45 -> V_121 = F_37 ;
V_45 -> V_122 = F_40 ;
V_45 -> V_115 = F_52 ;
V_45 -> V_114 = F_56 ;
break;
case V_24 :
V_45 -> V_92 = V_40 + V_91 ;
V_5 -> V_51 = V_40 + V_44 ;
V_5 -> V_52 = V_124 ;
V_45 -> V_121 = F_37 ;
V_45 -> V_122 = F_41 ;
if ( F_29 ( V_40 + V_41 ) & V_125 )
F_19 ( V_5 -> V_35 , L_13 ) ;
break;
}
V_45 -> V_90 = V_45 -> V_92 ;
V_46 -> V_5 = V_5 ;
V_46 -> V_3 . V_49 = V_45 ;
V_46 -> V_3 . V_126 = V_127 ;
V_46 -> V_30 = V_30 ;
#ifdef F_70
V_45 -> V_85 . V_128 = F_47 ;
V_45 -> V_85 . V_129 = F_42 ;
V_45 -> V_85 . V_79 = V_130 ;
V_45 -> V_85 . V_131 = 1 ;
switch ( V_5 -> V_23 ) {
case V_37 :
V_45 -> V_85 . V_132 = F_44 ;
V_45 -> V_85 . V_128 = F_47 ;
break;
case V_24 :
V_45 -> V_85 . V_132 = F_45 ;
V_45 -> V_85 . V_128 = F_48 ;
break;
case V_39 :
V_45 -> V_85 . V_132 = F_46 ;
V_45 -> V_85 . V_128 = F_49 ;
break;
}
#else
V_45 -> V_85 . V_79 = V_133 ;
#endif
if ( V_30 -> V_134 != NULL )
V_45 -> V_85 . V_135 = V_30 -> V_134 ;
if ( V_30 -> V_136 )
V_45 -> V_85 . V_79 = V_137 ;
switch ( V_45 -> V_85 . V_79 ) {
case V_137 :
F_19 ( V_5 -> V_35 , L_14 ) ;
break;
case V_133 :
F_19 ( V_5 -> V_35 , L_15 ) ;
break;
case V_130 :
F_19 ( V_5 -> V_35 , L_16 ) ;
break;
default:
F_19 ( V_5 -> V_35 , L_17 ) ;
break;
}
if ( V_30 -> V_138 ) {
V_45 -> V_139 |= V_140 ;
V_45 -> V_117 |= V_141 ;
}
}
static void F_71 ( struct V_4 * V_5 ,
struct V_1 * V_46 )
{
struct V_47 * V_45 = & V_46 -> V_45 ;
F_32 ( V_5 -> V_35 , L_18 ,
V_45 , V_45 -> V_142 ) ;
if ( V_45 -> V_85 . V_79 != V_130 )
return;
if ( V_45 -> V_142 > 10 ) {
V_45 -> V_85 . V_143 = 256 ;
V_45 -> V_85 . V_144 = 3 ;
} else {
V_45 -> V_85 . V_143 = 512 ;
V_45 -> V_85 . V_144 = 3 ;
V_45 -> V_85 . V_135 = & V_145 ;
}
}
static int F_72 ( struct V_6 * V_103 )
{
struct V_8 * V_20 = F_6 ( V_103 ) ;
enum V_146 V_23 ;
struct V_4 * V_5 ;
struct V_1 * V_46 ;
struct V_109 * V_147 ;
struct V_148 * V_149 ;
int V_150 = 0 ;
int V_143 ;
int V_151 ;
int V_152 ;
V_23 = F_73 ( V_103 ) -> V_153 ;
F_14 ( L_19 , V_103 ) ;
V_5 = F_74 ( & V_103 -> V_7 , sizeof( * V_5 ) , V_154 ) ;
if ( V_5 == NULL ) {
F_18 ( & V_103 -> V_7 , L_20 ) ;
V_150 = - V_155 ;
goto V_156;
}
F_64 ( V_103 , V_5 ) ;
F_75 ( & V_5 -> V_118 . V_157 ) ;
F_76 ( & V_5 -> V_118 . V_158 ) ;
V_5 -> V_15 = F_77 ( & V_103 -> V_7 , L_21 ) ;
if ( F_66 ( V_5 -> V_15 ) ) {
F_18 ( & V_103 -> V_7 , L_22 ) ;
V_150 = - V_159 ;
goto V_156;
}
F_9 ( V_5 , V_14 ) ;
V_149 = V_103 -> V_148 ;
V_143 = F_78 ( V_149 ) ;
V_5 -> V_35 = & V_103 -> V_7 ;
V_5 -> V_21 = V_20 ;
V_5 -> V_23 = V_23 ;
V_5 -> V_40 = F_79 ( & V_103 -> V_7 , V_149 ) ;
if ( V_5 -> V_40 == NULL ) {
F_18 ( & V_103 -> V_7 , L_23 ) ;
V_150 = - V_160 ;
goto V_156;
}
F_32 ( & V_103 -> V_7 , L_24 , V_5 -> V_40 ) ;
V_150 = F_33 ( V_5 ) ;
if ( V_150 != 0 )
goto V_156;
V_147 = ( V_20 != NULL ) ? V_20 -> V_147 : NULL ;
V_151 = ( V_20 != NULL ) ? V_20 -> V_151 : 1 ;
V_5 -> V_107 = V_151 ;
V_143 = V_151 * sizeof( * V_5 -> V_104 ) ;
V_5 -> V_104 = F_74 ( & V_103 -> V_7 , V_143 , V_154 ) ;
if ( V_5 -> V_104 == NULL ) {
F_18 ( & V_103 -> V_7 , L_25 ) ;
V_150 = - V_155 ;
goto V_156;
}
V_46 = V_5 -> V_104 ;
for ( V_152 = 0 ; V_152 < V_151 ; V_152 ++ , V_46 ++ ) {
F_14 ( L_26 ,
V_152 , V_46 , V_5 ) ;
F_69 ( V_5 , V_46 , V_147 ) ;
V_46 -> V_161 = F_80 ( & V_46 -> V_3 ,
( V_147 ) ? V_147 -> V_53 : 1 ,
NULL ) ;
if ( V_46 -> V_161 == 0 ) {
F_71 ( V_5 , V_46 ) ;
F_81 ( & V_46 -> V_3 ) ;
F_67 ( V_5 , V_46 , V_147 ) ;
}
if ( V_147 != NULL )
V_147 ++ ;
}
V_150 = F_59 ( V_5 ) ;
if ( V_150 < 0 ) {
F_18 ( & V_103 -> V_7 , L_27 ) ;
goto V_156;
}
if ( F_7 ( V_5 ) ) {
F_19 ( & V_103 -> V_7 , L_28 ) ;
F_9 ( V_5 , V_12 ) ;
}
F_14 ( L_29 ) ;
return 0 ;
V_156:
F_63 ( V_103 ) ;
if ( V_150 == 0 )
V_150 = - V_36 ;
return V_150 ;
}
static int F_82 ( struct V_6 * V_7 , T_3 V_162 )
{
struct V_4 * V_5 = F_5 ( V_7 ) ;
if ( V_5 ) {
V_5 -> V_163 = F_29 ( V_5 -> V_51 ) ;
F_30 ( V_5 -> V_163 | V_5 -> V_52 , V_5 -> V_51 ) ;
F_9 ( V_5 , V_108 ) ;
}
return 0 ;
}
static int F_83 ( struct V_6 * V_7 )
{
struct V_4 * V_5 = F_5 ( V_7 ) ;
unsigned long V_164 ;
if ( V_5 ) {
F_9 ( V_5 , V_14 ) ;
F_33 ( V_5 ) ;
V_164 = F_29 ( V_5 -> V_51 ) ;
V_164 &= ~ V_5 -> V_52 ;
V_164 |= V_5 -> V_163 & V_5 -> V_52 ;
F_30 ( V_164 , V_5 -> V_51 ) ;
F_9 ( V_5 , V_12 ) ;
}
return 0 ;
}
