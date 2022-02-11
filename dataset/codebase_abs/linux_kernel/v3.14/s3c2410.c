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
return F_7 ( & V_7 -> V_7 ) ;
}
static inline int F_8 ( struct V_4 * V_5 )
{
#ifdef F_9
return 1 ;
#else
return 0 ;
#endif
}
static void F_10 ( struct V_4 * V_5 ,
enum V_9 V_10 )
{
if ( ! F_8 ( V_5 ) && V_10 == V_11 )
return;
if ( V_5 -> V_12 == V_13 ) {
if ( V_10 != V_13 )
F_11 ( V_5 -> V_14 ) ;
} else {
if ( V_10 == V_13 )
F_12 ( V_5 -> V_14 ) ;
}
V_5 -> V_12 = V_10 ;
}
static int F_13 ( int V_15 , unsigned long V_14 , int V_16 )
{
int V_17 ;
V_17 = F_14 ( ( V_15 * V_14 ) , V_18 ) ;
F_15 ( L_1 , V_17 , V_14 , V_15 ) ;
if ( V_17 > V_16 ) {
F_16 ( L_2 ,
V_15 , V_14 ) ;
return - 1 ;
}
if ( V_17 < 1 )
V_17 = 1 ;
return V_17 ;
}
static int F_17 ( struct V_4 * V_5 )
{
struct V_8 * V_19 = V_5 -> V_20 ;
int V_21 = ( V_5 -> V_22 == V_23 ) ? 8 : 4 ;
int V_24 , V_25 , V_26 ;
unsigned long V_27 = F_18 ( V_5 -> V_14 ) ;
unsigned long V_28 ( V_29 ) , V_30 , V_28 ( V_31 ) ;
unsigned long V_32 ;
V_5 -> V_33 = V_27 ;
V_27 /= 1000 ;
if ( V_19 != NULL ) {
V_24 = F_13 ( V_19 -> V_24 , V_27 , V_21 ) ;
V_25 = F_13 ( V_19 -> V_25 , V_27 , 8 ) ;
V_26 = F_13 ( V_19 -> V_26 , V_27 , 8 ) ;
} else {
V_24 = V_21 ;
V_25 = 8 ;
V_26 = 8 ;
}
if ( V_24 < 0 || V_25 < 0 || V_26 < 0 ) {
F_19 ( V_5 -> V_34 , L_3 ) ;
return - V_35 ;
}
F_20 ( V_5 -> V_34 , L_4 ,
V_24 , F_21 ( V_24 , V_27 ) , V_25 , F_21 ( V_25 , V_27 ) ,
V_26 , F_21 ( V_26 , V_27 ) ) ;
switch ( V_5 -> V_22 ) {
case V_36 :
V_31 = ( F_22 ( 3 ) |
F_23 ( 7 ) |
F_24 ( 7 ) ) ;
V_29 = V_37 ;
V_29 |= F_22 ( V_24 - 1 ) ;
V_29 |= F_23 ( V_25 - 1 ) ;
V_29 |= F_24 ( V_26 - 1 ) ;
break;
case V_38 :
case V_23 :
V_31 = ( F_25 ( V_21 - 1 ) |
F_26 ( 7 ) |
F_27 ( 7 ) ) ;
V_29 = F_25 ( V_24 - 1 ) ;
V_29 |= F_26 ( V_25 - 1 ) ;
V_29 |= F_27 ( V_26 - 1 ) ;
break;
default:
F_28 () ;
}
F_29 ( V_32 ) ;
V_30 = F_30 ( V_5 -> V_39 + V_40 ) ;
V_30 &= ~ V_31 ;
V_30 |= V_29 ;
F_31 ( V_30 , V_5 -> V_39 + V_40 ) ;
F_32 ( V_32 ) ;
F_33 ( V_5 -> V_34 , L_5 , V_30 ) ;
return 0 ;
}
static int F_34 ( struct V_4 * V_5 )
{
int V_41 ;
V_41 = F_17 ( V_5 ) ;
if ( V_41 < 0 )
return V_41 ;
switch ( V_5 -> V_22 ) {
case V_36 :
default:
break;
case V_38 :
case V_23 :
F_31 ( V_42 , V_5 -> V_39 + V_43 ) ;
}
return 0 ;
}
static void F_35 ( struct V_2 * V_3 , int V_44 )
{
struct V_4 * V_5 ;
struct V_1 * V_45 ;
struct V_46 * V_47 = V_3 -> V_48 ;
unsigned long V_49 ;
V_45 = V_47 -> V_48 ;
V_5 = V_45 -> V_5 ;
if ( V_44 != - 1 )
F_10 ( V_5 , V_13 ) ;
V_49 = F_30 ( V_5 -> V_50 ) ;
if ( V_44 == - 1 ) {
V_49 |= V_5 -> V_51 ;
} else {
if ( V_45 -> V_29 != NULL && V_44 > V_45 -> V_29 -> V_52 ) {
F_19 ( V_5 -> V_34 , L_6 , V_44 ) ;
return;
}
if ( V_5 -> V_20 != NULL ) {
if ( V_5 -> V_20 -> V_53 != NULL )
( V_5 -> V_20 -> V_53 ) ( V_45 -> V_29 , V_44 ) ;
}
V_49 &= ~ V_5 -> V_51 ;
}
F_31 ( V_49 , V_5 -> V_50 ) ;
if ( V_44 == - 1 )
F_10 ( V_5 , V_11 ) ;
}
static void F_36 ( struct V_2 * V_3 , int V_54 ,
unsigned int V_55 )
{
struct V_4 * V_5 = F_3 ( V_3 ) ;
if ( V_54 == V_56 )
return;
if ( V_55 & V_57 )
F_37 ( V_54 , V_5 -> V_39 + V_58 ) ;
else
F_37 ( V_54 , V_5 -> V_39 + V_59 ) ;
}
static void F_38 ( struct V_2 * V_3 , int V_54 ,
unsigned int V_55 )
{
struct V_4 * V_5 = F_3 ( V_3 ) ;
if ( V_54 == V_56 )
return;
if ( V_55 & V_57 )
F_37 ( V_54 , V_5 -> V_39 + V_60 ) ;
else
F_37 ( V_54 , V_5 -> V_39 + V_61 ) ;
}
static int F_39 ( struct V_2 * V_3 )
{
struct V_4 * V_5 = F_3 ( V_3 ) ;
return F_40 ( V_5 -> V_39 + V_62 ) & V_63 ;
}
static int F_41 ( struct V_2 * V_3 )
{
struct V_4 * V_5 = F_3 ( V_3 ) ;
return F_40 ( V_5 -> V_39 + V_64 ) & V_65 ;
}
static int F_42 ( struct V_2 * V_3 )
{
struct V_4 * V_5 = F_3 ( V_3 ) ;
return F_40 ( V_5 -> V_39 + V_66 ) & V_67 ;
}
static int F_43 ( struct V_2 * V_3 , T_1 * V_68 ,
T_1 * V_69 , T_1 * V_70 )
{
struct V_4 * V_5 = F_3 ( V_3 ) ;
unsigned int V_71 , V_72 , V_73 ;
unsigned int V_74 , V_75 ;
F_15 ( L_7 , V_76 , V_3 , V_68 , V_69 , V_70 ) ;
V_71 = V_69 [ 0 ] ^ V_70 [ 0 ] ;
V_72 = V_69 [ 1 ] ^ V_70 [ 1 ] ;
V_73 = V_69 [ 2 ] ^ V_70 [ 2 ] ;
F_15 ( L_8 ,
V_76 , 3 , V_69 , 3 , V_70 ,
V_71 , V_72 , V_73 ) ;
if ( V_71 == 0 && V_72 == 0 && V_73 == 0 )
return 0 ;
if ( V_69 [ 0 ] == 0xff && V_69 [ 1 ] == 0xff && V_69 [ 2 ] == 0xff
&& V_5 -> V_20 -> V_77 )
return 0 ;
if ( ( ( V_71 ^ ( V_71 >> 1 ) ) & 0x55 ) == 0x55 &&
( ( V_72 ^ ( V_72 >> 1 ) ) & 0x55 ) == 0x55 &&
( ( V_73 ^ ( V_73 >> 1 ) ) & 0x55 ) == 0x55 ) {
V_74 = ( ( V_73 >> 3 ) & 1 ) |
( ( V_73 >> 4 ) & 2 ) |
( ( V_73 >> 5 ) & 4 ) ;
V_75 = ( ( V_73 << 7 ) & 0x100 ) |
( ( V_72 << 0 ) & 0x80 ) |
( ( V_72 << 1 ) & 0x40 ) |
( ( V_72 << 2 ) & 0x20 ) |
( ( V_72 << 3 ) & 0x10 ) |
( ( V_71 >> 4 ) & 0x08 ) |
( ( V_71 >> 3 ) & 0x04 ) |
( ( V_71 >> 2 ) & 0x02 ) |
( ( V_71 >> 1 ) & 0x01 ) ;
F_33 ( V_5 -> V_34 , L_9 ,
V_74 , V_75 ) ;
V_68 [ V_75 ] ^= ( 1 << V_74 ) ;
return 1 ;
}
V_71 |= ( V_72 << 8 ) ;
V_71 |= ( V_73 << 16 ) ;
if ( ( V_71 & ~ ( 1 << F_44 ( V_71 ) ) ) == 0 )
return 1 ;
return - 1 ;
}
static void F_45 ( struct V_2 * V_3 , int V_78 )
{
struct V_4 * V_5 = F_3 ( V_3 ) ;
unsigned long V_55 ;
V_55 = F_30 ( V_5 -> V_39 + V_40 ) ;
V_55 |= V_79 ;
F_31 ( V_55 , V_5 -> V_39 + V_40 ) ;
}
static void F_46 ( struct V_2 * V_3 , int V_78 )
{
struct V_4 * V_5 = F_3 ( V_3 ) ;
unsigned long V_55 ;
V_55 = F_30 ( V_5 -> V_39 + V_43 ) ;
F_31 ( V_55 | V_80 ,
V_5 -> V_39 + V_43 ) ;
}
static void F_47 ( struct V_2 * V_3 , int V_78 )
{
struct V_4 * V_5 = F_3 ( V_3 ) ;
unsigned long V_55 ;
V_55 = F_30 ( V_5 -> V_39 + V_43 ) ;
F_31 ( V_55 | V_81 , V_5 -> V_39 + V_43 ) ;
}
static int F_48 ( struct V_2 * V_3 , const T_1 * V_68 ,
T_1 * V_82 )
{
struct V_4 * V_5 = F_3 ( V_3 ) ;
V_82 [ 0 ] = F_40 ( V_5 -> V_39 + V_83 + 0 ) ;
V_82 [ 1 ] = F_40 ( V_5 -> V_39 + V_83 + 1 ) ;
V_82 [ 2 ] = F_40 ( V_5 -> V_39 + V_83 + 2 ) ;
F_15 ( L_10 , V_76 , 3 , V_82 ) ;
return 0 ;
}
static int F_49 ( struct V_2 * V_3 , const T_1 * V_68 ,
T_1 * V_82 )
{
struct V_4 * V_5 = F_3 ( V_3 ) ;
unsigned long V_84 = F_30 ( V_5 -> V_39 + V_85 ) ;
V_82 [ 0 ] = V_84 ;
V_82 [ 1 ] = V_84 >> 8 ;
V_82 [ 2 ] = V_84 >> 16 ;
F_15 ( L_10 , V_76 , 3 , V_82 ) ;
return 0 ;
}
static int F_50 ( struct V_2 * V_3 , const T_1 * V_68 ,
T_1 * V_82 )
{
struct V_4 * V_5 = F_3 ( V_3 ) ;
unsigned long V_84 = F_30 ( V_5 -> V_39 + V_86 ) ;
V_82 [ 0 ] = V_84 ;
V_82 [ 1 ] = V_84 >> 8 ;
V_82 [ 2 ] = V_84 >> 16 ;
F_15 ( L_11 , V_76 , V_84 & 0xffffff ) ;
return 0 ;
}
static void F_51 ( struct V_2 * V_3 , T_1 * V_87 , int V_88 )
{
struct V_46 * V_47 = V_3 -> V_48 ;
F_52 ( V_47 -> V_89 , V_87 , V_88 ) ;
}
static void F_53 ( struct V_2 * V_3 , T_1 * V_87 , int V_88 )
{
struct V_4 * V_5 = F_3 ( V_3 ) ;
F_54 ( V_5 -> V_39 + V_90 , V_87 , V_88 >> 2 ) ;
if ( V_88 & 3 ) {
V_87 += V_88 & ~ 3 ;
for (; V_88 & 3 ; V_88 -- )
* V_87 ++ = F_40 ( V_5 -> V_39 + V_90 ) ;
}
}
static void F_55 ( struct V_2 * V_3 , const T_1 * V_87 ,
int V_88 )
{
struct V_46 * V_47 = V_3 -> V_48 ;
F_56 ( V_47 -> V_91 , V_87 , V_88 ) ;
}
static void F_57 ( struct V_2 * V_3 , const T_1 * V_87 ,
int V_88 )
{
struct V_4 * V_5 = F_3 ( V_3 ) ;
F_58 ( V_5 -> V_39 + V_90 , V_87 , V_88 >> 2 ) ;
if ( V_88 & 3 ) {
V_87 += V_88 & ~ 3 ;
for (; V_88 & 3 ; V_88 -- , V_87 ++ )
F_37 ( * V_87 , V_5 -> V_39 + V_90 ) ;
}
}
static int F_59 ( struct V_92 * V_93 ,
unsigned long V_94 , void * V_95 )
{
struct V_4 * V_5 ;
unsigned long V_96 ;
V_5 = F_2 ( V_93 , struct V_4 , V_97 ) ;
V_96 = F_18 ( V_5 -> V_14 ) ;
if ( ( V_94 == V_98 && V_96 < V_5 -> V_33 ) ||
( V_94 == V_99 && V_96 > V_5 -> V_33 ) ) {
F_17 ( V_5 ) ;
}
return 0 ;
}
static inline int F_60 ( struct V_4 * V_5 )
{
V_5 -> V_97 . V_100 = F_59 ;
return F_61 ( & V_5 -> V_97 ,
V_101 ) ;
}
static inline void
F_62 ( struct V_4 * V_5 )
{
F_63 ( & V_5 -> V_97 ,
V_101 ) ;
}
static inline int F_60 ( struct V_4 * V_5 )
{
return 0 ;
}
static inline void
F_62 ( struct V_4 * V_5 )
{
}
static int F_64 ( struct V_6 * V_102 )
{
struct V_4 * V_5 = F_4 ( V_102 ) ;
if ( V_5 == NULL )
return 0 ;
F_62 ( V_5 ) ;
if ( V_5 -> V_103 != NULL ) {
struct V_1 * V_104 = V_5 -> V_103 ;
int V_105 ;
for ( V_105 = 0 ; V_105 < V_5 -> V_106 ; V_105 ++ , V_104 ++ ) {
F_15 ( L_12 , V_105 , V_104 ) ;
F_65 ( & V_104 -> V_3 ) ;
}
}
if ( ! F_66 ( V_5 -> V_14 ) )
F_10 ( V_5 , V_107 ) ;
return 0 ;
}
static int F_67 ( struct V_4 * V_5 ,
struct V_1 * V_3 ,
struct V_108 * V_29 )
{
if ( V_29 ) {
V_3 -> V_3 . V_109 = V_29 -> V_109 ;
return F_68 ( & V_3 -> V_3 , NULL , NULL ,
V_29 -> V_110 , V_29 -> V_111 ) ;
}
return - V_112 ;
}
static void F_69 ( struct V_4 * V_5 ,
struct V_1 * V_45 ,
struct V_108 * V_29 )
{
struct V_46 * V_44 = & V_45 -> V_44 ;
void T_2 * V_39 = V_5 -> V_39 ;
V_44 -> V_113 = F_55 ;
V_44 -> V_114 = F_51 ;
V_44 -> V_53 = F_35 ;
V_44 -> V_115 = 50 ;
V_44 -> V_48 = V_45 ;
V_44 -> V_116 = V_29 -> V_116 ;
V_44 -> V_117 = & V_5 -> V_117 ;
switch ( V_5 -> V_22 ) {
case V_36 :
V_44 -> V_91 = V_39 + V_118 ;
V_5 -> V_50 = V_39 + V_40 ;
V_5 -> V_51 = V_119 ;
V_44 -> V_120 = F_36 ;
V_44 -> V_121 = F_39 ;
break;
case V_38 :
V_44 -> V_91 = V_39 + V_90 ;
V_5 -> V_50 = V_39 + V_43 ;
V_5 -> V_51 = V_122 ;
V_44 -> V_120 = F_38 ;
V_44 -> V_121 = F_41 ;
V_44 -> V_114 = F_53 ;
V_44 -> V_113 = F_57 ;
break;
case V_23 :
V_44 -> V_91 = V_39 + V_90 ;
V_5 -> V_50 = V_39 + V_43 ;
V_5 -> V_51 = V_123 ;
V_44 -> V_120 = F_38 ;
V_44 -> V_121 = F_42 ;
if ( F_30 ( V_39 + V_40 ) & V_124 )
F_20 ( V_5 -> V_34 , L_13 ) ;
break;
}
V_44 -> V_89 = V_44 -> V_91 ;
V_45 -> V_5 = V_5 ;
V_45 -> V_3 . V_48 = V_44 ;
V_45 -> V_3 . V_125 = V_126 ;
V_45 -> V_29 = V_29 ;
#ifdef F_70
V_44 -> V_84 . V_127 = F_48 ;
V_44 -> V_84 . V_128 = F_43 ;
V_44 -> V_84 . V_78 = V_129 ;
V_44 -> V_84 . V_130 = 1 ;
switch ( V_5 -> V_22 ) {
case V_36 :
V_44 -> V_84 . V_131 = F_45 ;
V_44 -> V_84 . V_127 = F_48 ;
break;
case V_23 :
V_44 -> V_84 . V_131 = F_46 ;
V_44 -> V_84 . V_127 = F_49 ;
break;
case V_38 :
V_44 -> V_84 . V_131 = F_47 ;
V_44 -> V_84 . V_127 = F_50 ;
break;
}
#else
V_44 -> V_84 . V_78 = V_132 ;
#endif
if ( V_29 -> V_133 != NULL )
V_44 -> V_84 . V_134 = V_29 -> V_133 ;
if ( V_29 -> V_135 )
V_44 -> V_84 . V_78 = V_136 ;
switch ( V_44 -> V_84 . V_78 ) {
case V_136 :
F_20 ( V_5 -> V_34 , L_14 ) ;
break;
case V_132 :
F_20 ( V_5 -> V_34 , L_15 ) ;
break;
case V_129 :
F_20 ( V_5 -> V_34 , L_16 ) ;
break;
default:
F_20 ( V_5 -> V_34 , L_17 ) ;
break;
}
if ( V_29 -> V_137 ) {
V_44 -> V_138 |= V_139 ;
V_44 -> V_116 |= V_140 ;
}
}
static void F_71 ( struct V_4 * V_5 ,
struct V_1 * V_45 )
{
struct V_46 * V_44 = & V_45 -> V_44 ;
F_33 ( V_5 -> V_34 , L_18 ,
V_44 , V_44 -> V_141 ) ;
if ( V_44 -> V_84 . V_78 != V_129 )
return;
if ( V_44 -> V_141 > 10 ) {
V_44 -> V_84 . V_142 = 256 ;
V_44 -> V_84 . V_143 = 3 ;
} else {
V_44 -> V_84 . V_142 = 512 ;
V_44 -> V_84 . V_143 = 3 ;
V_44 -> V_84 . V_134 = & V_144 ;
}
}
static int F_72 ( struct V_6 * V_102 )
{
struct V_8 * V_19 = F_6 ( V_102 ) ;
enum V_145 V_22 ;
struct V_4 * V_5 ;
struct V_1 * V_45 ;
struct V_108 * V_146 ;
struct V_147 * V_148 ;
int V_149 = 0 ;
int V_142 ;
int V_150 ;
int V_151 ;
V_22 = F_73 ( V_102 ) -> V_152 ;
F_15 ( L_19 , V_102 ) ;
V_5 = F_74 ( & V_102 -> V_7 , sizeof( * V_5 ) , V_153 ) ;
if ( V_5 == NULL ) {
V_149 = - V_154 ;
goto V_155;
}
F_75 ( V_102 , V_5 ) ;
F_76 ( & V_5 -> V_117 . V_156 ) ;
F_77 ( & V_5 -> V_117 . V_157 ) ;
V_5 -> V_14 = F_78 ( & V_102 -> V_7 , L_20 ) ;
if ( F_66 ( V_5 -> V_14 ) ) {
F_19 ( & V_102 -> V_7 , L_21 ) ;
V_149 = - V_158 ;
goto V_155;
}
F_10 ( V_5 , V_13 ) ;
V_148 = V_102 -> V_147 ;
V_142 = F_79 ( V_148 ) ;
V_5 -> V_34 = & V_102 -> V_7 ;
V_5 -> V_20 = V_19 ;
V_5 -> V_22 = V_22 ;
V_5 -> V_39 = F_80 ( & V_102 -> V_7 , V_148 ) ;
if ( F_66 ( V_5 -> V_39 ) ) {
V_149 = F_81 ( V_5 -> V_39 ) ;
goto V_155;
}
F_33 ( & V_102 -> V_7 , L_22 , V_5 -> V_39 ) ;
V_149 = F_34 ( V_5 ) ;
if ( V_149 != 0 )
goto V_155;
V_146 = ( V_19 != NULL ) ? V_19 -> V_146 : NULL ;
V_150 = ( V_19 != NULL ) ? V_19 -> V_150 : 1 ;
V_5 -> V_106 = V_150 ;
V_142 = V_150 * sizeof( * V_5 -> V_103 ) ;
V_5 -> V_103 = F_74 ( & V_102 -> V_7 , V_142 , V_153 ) ;
if ( V_5 -> V_103 == NULL ) {
V_149 = - V_154 ;
goto V_155;
}
V_45 = V_5 -> V_103 ;
for ( V_151 = 0 ; V_151 < V_150 ; V_151 ++ , V_45 ++ ) {
F_15 ( L_23 ,
V_151 , V_45 , V_5 ) ;
F_69 ( V_5 , V_45 , V_146 ) ;
V_45 -> V_159 = F_82 ( & V_45 -> V_3 ,
( V_146 ) ? V_146 -> V_52 : 1 ,
NULL ) ;
if ( V_45 -> V_159 == 0 ) {
F_71 ( V_5 , V_45 ) ;
F_83 ( & V_45 -> V_3 ) ;
F_67 ( V_5 , V_45 , V_146 ) ;
}
if ( V_146 != NULL )
V_146 ++ ;
}
V_149 = F_60 ( V_5 ) ;
if ( V_149 < 0 ) {
F_19 ( & V_102 -> V_7 , L_24 ) ;
goto V_155;
}
if ( F_8 ( V_5 ) ) {
F_20 ( & V_102 -> V_7 , L_25 ) ;
F_10 ( V_5 , V_11 ) ;
}
F_15 ( L_26 ) ;
return 0 ;
V_155:
F_64 ( V_102 ) ;
if ( V_149 == 0 )
V_149 = - V_35 ;
return V_149 ;
}
static int F_84 ( struct V_6 * V_7 , T_3 V_160 )
{
struct V_4 * V_5 = F_5 ( V_7 ) ;
if ( V_5 ) {
V_5 -> V_161 = F_30 ( V_5 -> V_50 ) ;
F_31 ( V_5 -> V_161 | V_5 -> V_51 , V_5 -> V_50 ) ;
F_10 ( V_5 , V_107 ) ;
}
return 0 ;
}
static int F_85 ( struct V_6 * V_7 )
{
struct V_4 * V_5 = F_5 ( V_7 ) ;
unsigned long V_162 ;
if ( V_5 ) {
F_10 ( V_5 , V_13 ) ;
F_34 ( V_5 ) ;
V_162 = F_30 ( V_5 -> V_50 ) ;
V_162 &= ~ V_5 -> V_51 ;
V_162 |= V_5 -> V_161 & V_5 -> V_51 ;
F_31 ( V_162 , V_5 -> V_50 ) ;
F_10 ( V_5 , V_11 ) ;
}
return 0 ;
}
