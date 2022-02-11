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
return V_10 ;
}
static void F_8 ( struct V_4 * V_5 ,
enum V_11 V_12 )
{
if ( ! F_7 ( V_5 ) && V_12 == V_13 )
return;
if ( V_5 -> V_14 == V_15 ) {
if ( V_12 != V_15 )
F_9 ( V_5 -> V_16 ) ;
} else {
if ( V_12 == V_15 )
F_10 ( V_5 -> V_16 ) ;
}
V_5 -> V_14 = V_12 ;
}
static int F_11 ( int V_17 , unsigned long V_16 , int V_18 )
{
int V_19 ;
V_19 = F_12 ( ( V_17 * V_16 ) , V_20 ) ;
F_13 ( L_1 , V_19 , V_16 , V_17 ) ;
if ( V_19 > V_18 ) {
F_14 ( L_2 , V_17 , V_16 ) ;
return - 1 ;
}
if ( V_19 < 1 )
V_19 = 1 ;
return V_19 ;
}
static int F_15 ( struct V_4 * V_5 )
{
struct V_8 * V_21 = V_5 -> V_22 ;
int V_23 = ( V_5 -> V_24 == V_25 ) ? 8 : 4 ;
int V_26 , V_27 , V_28 ;
unsigned long V_29 = F_16 ( V_5 -> V_16 ) ;
unsigned long V_30 ( V_31 ) , V_32 , V_30 ( V_33 ) ;
unsigned long V_34 ;
V_5 -> V_35 = V_29 ;
V_29 /= 1000 ;
if ( V_21 != NULL ) {
V_26 = F_11 ( V_21 -> V_26 , V_29 , V_23 ) ;
V_27 = F_11 ( V_21 -> V_27 , V_29 , 8 ) ;
V_28 = F_11 ( V_21 -> V_28 , V_29 , 8 ) ;
} else {
V_26 = V_23 ;
V_27 = 8 ;
V_28 = 8 ;
}
if ( V_26 < 0 || V_27 < 0 || V_28 < 0 ) {
F_17 ( V_5 -> V_36 , L_3 ) ;
return - V_37 ;
}
F_18 ( V_5 -> V_36 , L_4 ,
V_26 , F_19 ( V_26 , V_29 ) , V_27 , F_19 ( V_27 , V_29 ) , V_28 , F_19 ( V_28 , V_29 ) ) ;
switch ( V_5 -> V_24 ) {
case V_38 :
V_33 = ( F_20 ( 3 ) |
F_21 ( 7 ) |
F_22 ( 7 ) ) ;
V_31 = V_39 ;
V_31 |= F_20 ( V_26 - 1 ) ;
V_31 |= F_21 ( V_27 - 1 ) ;
V_31 |= F_22 ( V_28 - 1 ) ;
break;
case V_40 :
case V_25 :
V_33 = ( F_23 ( V_23 - 1 ) |
F_24 ( 7 ) |
F_25 ( 7 ) ) ;
V_31 = F_23 ( V_26 - 1 ) ;
V_31 |= F_24 ( V_27 - 1 ) ;
V_31 |= F_25 ( V_28 - 1 ) ;
break;
default:
F_26 () ;
}
F_27 ( V_34 ) ;
V_32 = F_28 ( V_5 -> V_41 + V_42 ) ;
V_32 &= ~ V_33 ;
V_32 |= V_31 ;
F_29 ( V_32 , V_5 -> V_41 + V_42 ) ;
F_30 ( V_34 ) ;
F_31 ( V_5 -> V_36 , L_5 , V_32 ) ;
return 0 ;
}
static int F_32 ( struct V_4 * V_5 )
{
int V_43 ;
V_43 = F_15 ( V_5 ) ;
if ( V_43 < 0 )
return V_43 ;
switch ( V_5 -> V_24 ) {
case V_38 :
default:
break;
case V_40 :
case V_25 :
F_29 ( V_44 , V_5 -> V_41 + V_45 ) ;
}
return 0 ;
}
static void F_33 ( struct V_2 * V_3 , int V_46 )
{
struct V_4 * V_5 ;
struct V_1 * V_47 ;
struct V_48 * V_49 = V_3 -> V_50 ;
unsigned long V_51 ;
V_47 = V_49 -> V_50 ;
V_5 = V_47 -> V_5 ;
if ( V_46 != - 1 )
F_8 ( V_5 , V_15 ) ;
V_51 = F_28 ( V_5 -> V_52 ) ;
if ( V_46 == - 1 ) {
V_51 |= V_5 -> V_53 ;
} else {
if ( V_47 -> V_31 != NULL && V_46 > V_47 -> V_31 -> V_54 ) {
F_17 ( V_5 -> V_36 , L_6 , V_46 ) ;
return;
}
if ( V_5 -> V_22 != NULL ) {
if ( V_5 -> V_22 -> V_55 != NULL )
( V_5 -> V_22 -> V_55 ) ( V_47 -> V_31 , V_46 ) ;
}
V_51 &= ~ V_5 -> V_53 ;
}
F_29 ( V_51 , V_5 -> V_52 ) ;
if ( V_46 == - 1 )
F_8 ( V_5 , V_13 ) ;
}
static void F_34 ( struct V_2 * V_3 , int V_56 ,
unsigned int V_57 )
{
struct V_4 * V_5 = F_3 ( V_3 ) ;
if ( V_56 == V_58 )
return;
if ( V_57 & V_59 )
F_35 ( V_56 , V_5 -> V_41 + V_60 ) ;
else
F_35 ( V_56 , V_5 -> V_41 + V_61 ) ;
}
static void F_36 ( struct V_2 * V_3 , int V_56 ,
unsigned int V_57 )
{
struct V_4 * V_5 = F_3 ( V_3 ) ;
if ( V_56 == V_58 )
return;
if ( V_57 & V_59 )
F_35 ( V_56 , V_5 -> V_41 + V_62 ) ;
else
F_35 ( V_56 , V_5 -> V_41 + V_63 ) ;
}
static int F_37 ( struct V_2 * V_3 )
{
struct V_4 * V_5 = F_3 ( V_3 ) ;
return F_38 ( V_5 -> V_41 + V_64 ) & V_65 ;
}
static int F_39 ( struct V_2 * V_3 )
{
struct V_4 * V_5 = F_3 ( V_3 ) ;
return F_38 ( V_5 -> V_41 + V_66 ) & V_67 ;
}
static int F_40 ( struct V_2 * V_3 )
{
struct V_4 * V_5 = F_3 ( V_3 ) ;
return F_38 ( V_5 -> V_41 + V_68 ) & V_69 ;
}
static int F_41 ( struct V_2 * V_3 , T_1 * V_70 ,
T_1 * V_71 , T_1 * V_72 )
{
struct V_4 * V_5 = F_3 ( V_3 ) ;
unsigned int V_73 , V_74 , V_75 ;
unsigned int V_76 , V_77 ;
F_13 ( L_7 , V_78 , V_3 , V_70 , V_71 , V_72 ) ;
V_73 = V_71 [ 0 ] ^ V_72 [ 0 ] ;
V_74 = V_71 [ 1 ] ^ V_72 [ 1 ] ;
V_75 = V_71 [ 2 ] ^ V_72 [ 2 ] ;
F_13 ( L_8 ,
V_78 ,
V_71 [ 0 ] , V_71 [ 1 ] , V_71 [ 2 ] ,
V_72 [ 0 ] , V_72 [ 1 ] , V_72 [ 2 ] ,
V_73 , V_74 , V_75 ) ;
if ( V_73 == 0 && V_74 == 0 && V_75 == 0 )
return 0 ;
if ( V_71 [ 0 ] == 0xff && V_71 [ 1 ] == 0xff && V_71 [ 2 ] == 0xff
&& V_5 -> V_22 -> V_79 )
return 0 ;
if ( ( ( V_73 ^ ( V_73 >> 1 ) ) & 0x55 ) == 0x55 &&
( ( V_74 ^ ( V_74 >> 1 ) ) & 0x55 ) == 0x55 &&
( ( V_75 ^ ( V_75 >> 1 ) ) & 0x55 ) == 0x55 ) {
V_76 = ( ( V_75 >> 3 ) & 1 ) |
( ( V_75 >> 4 ) & 2 ) |
( ( V_75 >> 5 ) & 4 ) ;
V_77 = ( ( V_75 << 7 ) & 0x100 ) |
( ( V_74 << 0 ) & 0x80 ) |
( ( V_74 << 1 ) & 0x40 ) |
( ( V_74 << 2 ) & 0x20 ) |
( ( V_74 << 3 ) & 0x10 ) |
( ( V_73 >> 4 ) & 0x08 ) |
( ( V_73 >> 3 ) & 0x04 ) |
( ( V_73 >> 2 ) & 0x02 ) |
( ( V_73 >> 1 ) & 0x01 ) ;
F_31 ( V_5 -> V_36 , L_9 ,
V_76 , V_77 ) ;
V_70 [ V_77 ] ^= ( 1 << V_76 ) ;
return 1 ;
}
V_73 |= ( V_74 << 8 ) ;
V_73 |= ( V_75 << 16 ) ;
if ( ( V_73 & ~ ( 1 << F_42 ( V_73 ) ) ) == 0 )
return 1 ;
return - 1 ;
}
static void F_43 ( struct V_2 * V_3 , int V_80 )
{
struct V_4 * V_5 = F_3 ( V_3 ) ;
unsigned long V_57 ;
V_57 = F_28 ( V_5 -> V_41 + V_42 ) ;
V_57 |= V_81 ;
F_29 ( V_57 , V_5 -> V_41 + V_42 ) ;
}
static void F_44 ( struct V_2 * V_3 , int V_80 )
{
struct V_4 * V_5 = F_3 ( V_3 ) ;
unsigned long V_57 ;
V_57 = F_28 ( V_5 -> V_41 + V_45 ) ;
F_29 ( V_57 | V_82 , V_5 -> V_41 + V_45 ) ;
}
static void F_45 ( struct V_2 * V_3 , int V_80 )
{
struct V_4 * V_5 = F_3 ( V_3 ) ;
unsigned long V_57 ;
V_57 = F_28 ( V_5 -> V_41 + V_45 ) ;
F_29 ( V_57 | V_83 , V_5 -> V_41 + V_45 ) ;
}
static int F_46 ( struct V_2 * V_3 , const T_1 * V_70 , T_1 * V_84 )
{
struct V_4 * V_5 = F_3 ( V_3 ) ;
V_84 [ 0 ] = F_38 ( V_5 -> V_41 + V_85 + 0 ) ;
V_84 [ 1 ] = F_38 ( V_5 -> V_41 + V_85 + 1 ) ;
V_84 [ 2 ] = F_38 ( V_5 -> V_41 + V_85 + 2 ) ;
F_13 ( L_10 , V_78 ,
V_84 [ 0 ] , V_84 [ 1 ] , V_84 [ 2 ] ) ;
return 0 ;
}
static int F_47 ( struct V_2 * V_3 , const T_1 * V_70 , T_1 * V_84 )
{
struct V_4 * V_5 = F_3 ( V_3 ) ;
unsigned long V_86 = F_28 ( V_5 -> V_41 + V_87 ) ;
V_84 [ 0 ] = V_86 ;
V_84 [ 1 ] = V_86 >> 8 ;
V_84 [ 2 ] = V_86 >> 16 ;
F_13 ( L_11 , V_84 [ 0 ] , V_84 [ 1 ] , V_84 [ 2 ] ) ;
return 0 ;
}
static int F_48 ( struct V_2 * V_3 , const T_1 * V_70 , T_1 * V_84 )
{
struct V_4 * V_5 = F_3 ( V_3 ) ;
unsigned long V_86 = F_28 ( V_5 -> V_41 + V_88 ) ;
V_84 [ 0 ] = V_86 ;
V_84 [ 1 ] = V_86 >> 8 ;
V_84 [ 2 ] = V_86 >> 16 ;
F_13 ( L_12 , V_78 , V_86 & 0xffffff ) ;
return 0 ;
}
static void F_49 ( struct V_2 * V_3 , T_1 * V_89 , int V_90 )
{
struct V_48 * V_49 = V_3 -> V_50 ;
F_50 ( V_49 -> V_91 , V_89 , V_90 ) ;
}
static void F_51 ( struct V_2 * V_3 , T_1 * V_89 , int V_90 )
{
struct V_4 * V_5 = F_3 ( V_3 ) ;
F_52 ( V_5 -> V_41 + V_92 , V_89 , V_90 >> 2 ) ;
if ( V_90 & 3 ) {
V_89 += V_90 & ~ 3 ;
for (; V_90 & 3 ; V_90 -- )
* V_89 ++ = F_38 ( V_5 -> V_41 + V_92 ) ;
}
}
static void F_53 ( struct V_2 * V_3 , const T_1 * V_89 , int V_90 )
{
struct V_48 * V_49 = V_3 -> V_50 ;
F_54 ( V_49 -> V_93 , V_89 , V_90 ) ;
}
static void F_55 ( struct V_2 * V_3 , const T_1 * V_89 , int V_90 )
{
struct V_4 * V_5 = F_3 ( V_3 ) ;
F_56 ( V_5 -> V_41 + V_92 , V_89 , V_90 >> 2 ) ;
if ( V_90 & 3 ) {
V_89 += V_90 & ~ 3 ;
for (; V_90 & 3 ; V_90 -- , V_89 ++ )
F_35 ( * V_89 , V_5 -> V_41 + V_92 ) ;
}
}
static int F_57 ( struct V_94 * V_95 ,
unsigned long V_96 , void * V_97 )
{
struct V_4 * V_5 ;
unsigned long V_98 ;
V_5 = F_2 ( V_95 , struct V_4 , V_99 ) ;
V_98 = F_16 ( V_5 -> V_16 ) ;
if ( ( V_96 == V_100 && V_98 < V_5 -> V_35 ) ||
( V_96 == V_101 && V_98 > V_5 -> V_35 ) ) {
F_15 ( V_5 ) ;
}
return 0 ;
}
static inline int F_58 ( struct V_4 * V_5 )
{
V_5 -> V_99 . V_102 = F_57 ;
return F_59 ( & V_5 -> V_99 ,
V_103 ) ;
}
static inline void F_60 ( struct V_4 * V_5 )
{
F_61 ( & V_5 -> V_99 ,
V_103 ) ;
}
static inline int F_58 ( struct V_4 * V_5 )
{
return 0 ;
}
static inline void F_60 ( struct V_4 * V_5 )
{
}
static int F_62 ( struct V_6 * V_104 )
{
struct V_4 * V_5 = F_4 ( V_104 ) ;
F_63 ( V_104 , NULL ) ;
if ( V_5 == NULL )
return 0 ;
F_60 ( V_5 ) ;
if ( V_5 -> V_105 != NULL ) {
struct V_1 * V_106 = V_5 -> V_105 ;
int V_107 ;
for ( V_107 = 0 ; V_107 < V_5 -> V_108 ; V_107 ++ , V_106 ++ ) {
F_13 ( L_13 , V_107 , V_106 ) ;
F_64 ( & V_106 -> V_3 ) ;
}
F_65 ( V_5 -> V_105 ) ;
}
if ( ! F_66 ( V_5 -> V_16 ) ) {
F_8 ( V_5 , V_109 ) ;
F_67 ( V_5 -> V_16 ) ;
}
if ( V_5 -> V_41 != NULL ) {
F_68 ( V_5 -> V_41 ) ;
V_5 -> V_41 = NULL ;
}
if ( V_5 -> V_110 != NULL ) {
F_69 ( V_5 -> V_110 ) ;
F_65 ( V_5 -> V_110 ) ;
V_5 -> V_110 = NULL ;
}
F_65 ( V_5 ) ;
return 0 ;
}
static int F_70 ( struct V_4 * V_5 ,
struct V_1 * V_3 ,
struct V_111 * V_31 )
{
if ( V_31 )
V_3 -> V_3 . V_112 = V_31 -> V_112 ;
return F_71 ( & V_3 -> V_3 , NULL , 0 ,
V_31 -> V_113 , V_31 -> V_114 ) ;
}
static void F_72 ( struct V_4 * V_5 ,
struct V_1 * V_47 ,
struct V_111 * V_31 )
{
struct V_48 * V_46 = & V_47 -> V_46 ;
void T_2 * V_41 = V_5 -> V_41 ;
V_46 -> V_115 = F_53 ;
V_46 -> V_116 = F_49 ;
V_46 -> V_55 = F_33 ;
V_46 -> V_117 = 50 ;
V_46 -> V_50 = V_47 ;
V_46 -> V_118 = V_31 -> V_118 ;
V_46 -> V_119 = & V_5 -> V_119 ;
switch ( V_5 -> V_24 ) {
case V_38 :
V_46 -> V_93 = V_41 + V_120 ;
V_5 -> V_52 = V_41 + V_42 ;
V_5 -> V_53 = V_121 ;
V_46 -> V_122 = F_34 ;
V_46 -> V_123 = F_37 ;
break;
case V_40 :
V_46 -> V_93 = V_41 + V_92 ;
V_5 -> V_52 = V_41 + V_45 ;
V_5 -> V_53 = V_124 ;
V_46 -> V_122 = F_36 ;
V_46 -> V_123 = F_39 ;
V_46 -> V_116 = F_51 ;
V_46 -> V_115 = F_55 ;
break;
case V_25 :
V_46 -> V_93 = V_41 + V_92 ;
V_5 -> V_52 = V_41 + V_45 ;
V_5 -> V_53 = V_125 ;
V_46 -> V_122 = F_36 ;
V_46 -> V_123 = F_40 ;
if ( F_28 ( V_41 + V_42 ) & V_126 )
F_18 ( V_5 -> V_36 , L_14 ) ;
break;
}
V_46 -> V_91 = V_46 -> V_93 ;
V_47 -> V_5 = V_5 ;
V_47 -> V_3 . V_50 = V_46 ;
V_47 -> V_3 . V_127 = V_128 ;
V_47 -> V_31 = V_31 ;
if ( V_129 ) {
V_46 -> V_86 . V_130 = F_46 ;
V_46 -> V_86 . V_131 = F_41 ;
V_46 -> V_86 . V_80 = V_132 ;
switch ( V_5 -> V_24 ) {
case V_38 :
V_46 -> V_86 . V_133 = F_43 ;
V_46 -> V_86 . V_130 = F_46 ;
break;
case V_25 :
V_46 -> V_86 . V_133 = F_44 ;
V_46 -> V_86 . V_130 = F_47 ;
break;
case V_40 :
V_46 -> V_86 . V_133 = F_45 ;
V_46 -> V_86 . V_130 = F_48 ;
break;
}
} else {
V_46 -> V_86 . V_80 = V_134 ;
}
if ( V_31 -> V_135 != NULL )
V_46 -> V_86 . V_136 = V_31 -> V_135 ;
if ( V_31 -> V_137 )
V_46 -> V_86 . V_80 = V_138 ;
switch ( V_46 -> V_86 . V_80 ) {
case V_138 :
F_18 ( V_5 -> V_36 , L_15 ) ;
break;
case V_134 :
F_18 ( V_5 -> V_36 , L_16 ) ;
break;
case V_132 :
F_18 ( V_5 -> V_36 , L_17 ) ;
break;
default:
F_18 ( V_5 -> V_36 , L_18 ) ;
break;
}
if ( V_31 -> V_139 ) {
V_46 -> V_140 |= V_141 ;
V_46 -> V_118 |= V_142 ;
}
}
static void F_73 ( struct V_4 * V_5 ,
struct V_1 * V_47 )
{
struct V_48 * V_46 = & V_47 -> V_46 ;
F_31 ( V_5 -> V_36 , L_19 ,
V_46 , V_46 -> V_143 ) ;
if ( V_46 -> V_86 . V_80 != V_132 )
return;
if ( V_46 -> V_143 > 10 ) {
V_46 -> V_86 . V_144 = 256 ;
V_46 -> V_86 . V_145 = 3 ;
} else {
V_46 -> V_86 . V_144 = 512 ;
V_46 -> V_86 . V_145 = 3 ;
V_46 -> V_86 . V_136 = & V_146 ;
}
}
static int F_74 ( struct V_6 * V_104 )
{
struct V_8 * V_21 = F_6 ( V_104 ) ;
enum V_147 V_24 ;
struct V_4 * V_5 ;
struct V_1 * V_47 ;
struct V_111 * V_148 ;
struct V_149 * V_150 ;
int V_151 = 0 ;
int V_144 ;
int V_152 ;
int V_153 ;
V_24 = F_75 ( V_104 ) -> V_154 ;
F_13 ( L_20 , V_104 ) ;
V_5 = F_76 ( sizeof( * V_5 ) , V_155 ) ;
if ( V_5 == NULL ) {
F_17 ( & V_104 -> V_7 , L_21 ) ;
V_151 = - V_156 ;
goto V_157;
}
F_63 ( V_104 , V_5 ) ;
F_77 ( & V_5 -> V_119 . V_158 ) ;
F_78 ( & V_5 -> V_119 . V_159 ) ;
V_5 -> V_16 = F_79 ( & V_104 -> V_7 , L_22 ) ;
if ( F_66 ( V_5 -> V_16 ) ) {
F_17 ( & V_104 -> V_7 , L_23 ) ;
V_151 = - V_160 ;
goto V_157;
}
F_8 ( V_5 , V_15 ) ;
V_150 = V_104 -> V_149 ;
V_144 = F_80 ( V_150 ) ;
V_5 -> V_110 = F_81 ( V_150 -> V_161 , V_144 , V_104 -> V_112 ) ;
if ( V_5 -> V_110 == NULL ) {
F_17 ( & V_104 -> V_7 , L_24 ) ;
V_151 = - V_160 ;
goto V_157;
}
V_5 -> V_36 = & V_104 -> V_7 ;
V_5 -> V_22 = V_21 ;
V_5 -> V_41 = F_82 ( V_150 -> V_161 , V_144 ) ;
V_5 -> V_24 = V_24 ;
if ( V_5 -> V_41 == NULL ) {
F_17 ( & V_104 -> V_7 , L_24 ) ;
V_151 = - V_162 ;
goto V_157;
}
F_31 ( & V_104 -> V_7 , L_25 , V_5 -> V_41 ) ;
V_151 = F_32 ( V_5 ) ;
if ( V_151 != 0 )
goto V_157;
V_148 = ( V_21 != NULL ) ? V_21 -> V_148 : NULL ;
V_152 = ( V_21 != NULL ) ? V_21 -> V_152 : 1 ;
V_5 -> V_108 = V_152 ;
V_144 = V_152 * sizeof( * V_5 -> V_105 ) ;
V_5 -> V_105 = F_76 ( V_144 , V_155 ) ;
if ( V_5 -> V_105 == NULL ) {
F_17 ( & V_104 -> V_7 , L_26 ) ;
V_151 = - V_156 ;
goto V_157;
}
V_47 = V_5 -> V_105 ;
for ( V_153 = 0 ; V_153 < V_152 ; V_153 ++ , V_47 ++ ) {
F_13 ( L_27 , V_153 , V_47 , V_5 ) ;
F_72 ( V_5 , V_47 , V_148 ) ;
V_47 -> V_163 = F_83 ( & V_47 -> V_3 ,
( V_148 ) ? V_148 -> V_54 : 1 ,
NULL ) ;
if ( V_47 -> V_163 == 0 ) {
F_73 ( V_5 , V_47 ) ;
F_84 ( & V_47 -> V_3 ) ;
F_70 ( V_5 , V_47 , V_148 ) ;
}
if ( V_148 != NULL )
V_148 ++ ;
}
V_151 = F_58 ( V_5 ) ;
if ( V_151 < 0 ) {
F_17 ( & V_104 -> V_7 , L_28 ) ;
goto V_157;
}
if ( F_7 ( V_5 ) ) {
F_18 ( & V_104 -> V_7 , L_29 ) ;
F_8 ( V_5 , V_13 ) ;
}
F_13 ( L_30 ) ;
return 0 ;
V_157:
F_62 ( V_104 ) ;
if ( V_151 == 0 )
V_151 = - V_37 ;
return V_151 ;
}
static int F_85 ( struct V_6 * V_7 , T_3 V_164 )
{
struct V_4 * V_5 = F_5 ( V_7 ) ;
if ( V_5 ) {
V_5 -> V_165 = F_28 ( V_5 -> V_52 ) ;
F_29 ( V_5 -> V_165 | V_5 -> V_53 , V_5 -> V_52 ) ;
F_8 ( V_5 , V_109 ) ;
}
return 0 ;
}
static int F_86 ( struct V_6 * V_7 )
{
struct V_4 * V_5 = F_5 ( V_7 ) ;
unsigned long V_166 ;
if ( V_5 ) {
F_8 ( V_5 , V_15 ) ;
F_32 ( V_5 ) ;
V_166 = F_28 ( V_5 -> V_52 ) ;
V_166 &= ~ V_5 -> V_53 ;
V_166 |= V_5 -> V_165 & V_5 -> V_53 ;
F_29 ( V_166 , V_5 -> V_52 ) ;
F_8 ( V_5 , V_13 ) ;
}
return 0 ;
}
static int T_4 F_87 ( void )
{
F_14 ( L_31 ) ;
return F_88 ( & V_167 ) ;
}
static void T_5 F_89 ( void )
{
F_90 ( & V_167 ) ;
}
