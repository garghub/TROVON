static bool F_1 ( struct V_1 * V_2 )
{
T_1 V_3 = 0 ;
struct V_4 * V_5 = F_2 ( V_2 ) ;
if ( V_5 -> V_6 )
return true ;
F_3 ( V_2 , 0x00 , & V_3 ) ;
if ( V_3 == 0xFFFF ) {
V_5 -> V_6 = true ;
if ( V_5 -> V_7 )
F_4 ( V_8 , & V_5 -> V_7 -> V_9 ) ;
else
F_5 ( & V_5 -> V_2 -> V_10 ,
L_1 , V_11 ) ;
return true ;
}
return false ;
}
static void F_6 ( struct V_12 * V_13 )
{
struct V_4 * V_5 = V_13 -> V_14 -> V_15 ;
struct V_16 * V_17 = F_7 ( V_13 ) ;
T_2 V_18 = F_8 ( V_5 -> V_19 + V_20 ) & V_21 ;
V_17 -> V_22 = V_5 -> V_23 -> V_24 +
( sizeof( struct V_25 ) * V_13 -> V_26 ) ;
V_17 -> V_27 = V_5 -> V_23 -> V_28 +
( sizeof( struct V_25 ) * V_13 -> V_26 ) ;
if ( V_18 )
V_17 -> V_22 -> V_29 = V_30 F_9 ( ( V_17 -> V_31 >> 16 ) >> 16 ) ;
V_17 -> V_22 -> V_32 = V_30 F_9 ( V_17 -> V_31 & 0xFFFFFFFF ) ;
}
static struct V_16 * F_10 ( struct V_4 * V_5 )
{
struct V_12 * V_13 ;
if ( F_1 ( V_5 -> V_2 ) )
return NULL ;
V_13 = F_11 ( V_5 -> V_7 , V_33 , V_34 ) ;
if ( F_12 ( V_13 ) )
return NULL ;
F_6 ( V_13 ) ;
return F_7 ( V_13 ) ;
}
static struct V_16 * F_13 ( struct V_4 * V_5 ,
unsigned int V_26 )
{
struct V_35 * V_36 = V_5 -> V_7 -> V_37 [ 0 ] ;
return F_7 ( F_14 ( V_36 -> V_38 , V_26 ) ) ;
}
static int F_15 ( struct V_4 * V_5 )
{
unsigned long V_39 ;
F_16 ( V_40 , V_5 -> V_19 + V_41 ) ;
F_8 ( V_5 -> V_19 + V_41 ) ;
V_39 = V_42 + F_17 ( 10000 ) ;
do {
F_18 ( 10 ) ;
if ( F_19 ( V_43 , & V_5 -> V_44 ) )
return - 1 ;
} while ( ( F_8 ( V_5 -> V_19 + V_41 ) & V_40 )
&& F_20 ( V_42 , V_39 ) );
if ( F_8 ( V_5 -> V_19 + V_41 ) & V_40 )
return - 1 ;
return 0 ;
}
static inline void F_21 ( struct V_45 * V_23 , int V_26 )
{
int V_46 = V_26 >> 5 ;
F_22 ( & V_23 -> V_47 [ V_46 ] ) ;
F_16 ( ( 1 << F_23 ( V_26 ) ) ,
V_23 -> V_48 [ F_24 ( V_26 ) ] ) ;
F_16 ( ( 1 << F_23 ( V_26 ) ) ,
V_23 -> V_49 [ F_24 ( V_26 ) ] ) ;
F_25 ( & V_23 -> V_47 [ V_46 ] ) ;
}
static int F_26 ( struct V_45 * V_23 , int V_50 )
{
T_2 V_51 ;
V_51 = F_8 ( V_23 -> V_19 + V_52 ) ;
if ( V_50 )
F_16 ( V_51 | V_53 , V_23 -> V_19 + V_52 ) ;
else
F_16 ( V_51 & ~ V_53 , V_23 -> V_19 + V_52 ) ;
F_8 ( V_23 -> V_19 + V_52 ) ;
return ( ( ( V_51 & V_53 ) == V_53 ) ) ;
}
static int F_27 ( struct V_45 * V_23 , int V_50 )
{
T_2 V_51 ;
V_51 = F_8 ( V_23 -> V_19 + V_52 ) ;
if ( V_50 )
F_16 ( V_51 | V_54 , V_23 -> V_19 + V_52 ) ;
else
F_16 ( V_51 & ~ V_54 , V_23 -> V_19 + V_52 ) ;
F_8 ( V_23 -> V_19 + V_52 ) ;
return ( ( ( V_51 & V_54 ) == V_54 ) ) ;
}
static inline void F_28 ( struct V_45 * V_23 )
{
F_26 ( V_23 , 1 ) ;
F_27 ( V_23 , 1 ) ;
}
static inline void F_29 ( struct V_45 * V_23 )
{
F_16 ( 0 , V_23 -> V_19 + V_55 ) ;
F_27 ( V_23 , 0 ) ;
F_26 ( V_23 , 0 ) ;
}
static void F_30 ( struct V_45 * V_23 )
{
int V_56 ;
F_29 ( V_23 ) ;
if ( F_8 ( V_23 -> V_5 -> V_19 + V_20 ) & V_21 ) {
F_16 ( ( V_23 -> V_28 >> 16 ) >> 16 ,
V_23 -> V_19 + V_57 ) ;
F_16 ( ( V_23 -> V_58 >> 16 ) >> 16 ,
V_23 -> V_19 + V_59 ) ;
}
F_16 ( V_23 -> V_28 & 0xFFFFFFFF ,
V_23 -> V_19 + V_60 ) ;
F_16 ( V_23 -> V_58 & 0xFFFFFFFF , V_23 -> V_19 + V_61 ) ;
F_16 ( F_8 ( V_23 -> V_19 + V_62 ) , V_23 -> V_19 + V_62 ) ;
for ( V_56 = 0 ; V_56 < V_23 -> V_5 -> V_63 ; V_56 ++ )
F_16 ( 0xFFFFFFFF , V_23 -> V_64 [ V_56 ] ) ;
F_16 ( F_8 ( V_23 -> V_19 + V_65 ) , V_23 -> V_19 + V_65 ) ;
F_16 ( F_8 ( V_23 -> V_5 -> V_19 + V_66 ) ,
V_23 -> V_5 -> V_19 + V_66 ) ;
F_16 ( V_67 , V_23 -> V_19 + V_55 ) ;
}
static void F_31 ( struct V_45 * V_23 )
{
unsigned long V_39 ;
F_27 ( V_23 , 0 ) ;
V_39 = V_42 + F_17 ( 500 ) ;
while ( ( F_8 ( V_23 -> V_19 + V_52 ) & V_68 )
&& F_20 ( V_42 , V_39 ) )
;
if ( F_19 ( V_43 , & V_23 -> V_5 -> V_44 ) )
return;
if ( F_8 ( V_23 -> V_19 + V_52 ) & V_68 ) {
F_5 ( & V_23 -> V_5 -> V_2 -> V_10 ,
L_2 ) ;
if ( F_15 ( V_23 -> V_5 ) )
F_32 ( & V_23 -> V_5 -> V_2 -> V_10 ,
L_3 ) ;
F_18 ( 30 ) ;
}
F_5 ( & V_23 -> V_5 -> V_2 -> V_10 , L_4 ) ;
F_16 ( F_8 ( V_23 -> V_19 + V_69 ) |
1 , V_23 -> V_19 + V_69 ) ;
F_8 ( V_23 -> V_19 + V_69 ) ;
V_39 = V_42 + F_17 ( 1 ) ;
while ( F_20 ( V_42 , V_39 ) )
;
if ( F_19 ( V_43 , & V_23 -> V_5 -> V_44 ) )
return;
F_16 ( F_8 ( V_23 -> V_19 + V_69 ) & ~ 1 ,
V_23 -> V_19 + V_69 ) ;
F_8 ( V_23 -> V_19 + V_69 ) ;
V_39 = V_42 + F_17 ( 500 ) ;
while ( ( ( F_8 ( V_23 -> V_19 + V_70 ) & 0x01 ) == 0 )
&& F_20 ( V_42 , V_39 ) )
;
if ( F_19 ( V_43 , & V_23 -> V_5 -> V_44 ) )
return;
if ( ( F_8 ( V_23 -> V_19 + V_70 ) & 0x01 ) == 0 )
F_5 ( & V_23 -> V_5 -> V_2 -> V_10 ,
L_5 ) ;
F_30 ( V_23 ) ;
F_28 ( V_23 ) ;
}
static int F_33 ( struct V_4 * V_5 )
{
int V_71 = 0 ;
if ( F_1 ( V_5 -> V_2 ) )
return 0 ;
if ( F_15 ( V_5 ) < 0 )
V_71 = - V_72 ;
F_18 ( 1 ) ;
F_30 ( V_5 -> V_23 ) ;
F_28 ( V_5 -> V_23 ) ;
F_16 ( F_8 ( V_5 -> V_19 + V_41 ) | V_73 ,
V_5 -> V_19 + V_41 ) ;
return V_71 ;
}
static void F_34 ( struct V_4 * V_5 ,
char * V_74 ,
unsigned long * V_75 ,
int V_76 )
{
unsigned char V_77 [ 128 ] ;
int V_46 , V_78 = 0 ;
memset ( V_77 , 0 , sizeof( V_77 ) ) ;
for ( V_46 = V_79 ; V_46 > 0 ; V_46 -- )
V_78 += sprintf ( V_77 + V_78 , L_6 ,
V_75 [ V_46 - 1 ] ) ;
F_5 ( & V_5 -> V_2 -> V_10 ,
L_7 , V_76 , V_74 , V_77 ) ;
}
static void F_35 ( struct V_16 * V_17 , int V_80 )
{
struct V_12 * V_81 = F_36 ( V_17 ) ;
V_17 -> V_80 = V_80 ;
F_37 ( V_81 ) ;
}
static void F_38 ( struct V_4 * V_5 )
{
int V_46 , V_26 , V_82 , V_83 , V_71 ;
struct V_45 * V_23 ;
struct V_16 * V_17 ;
T_2 V_64 ;
struct V_84 * V_85 ;
unsigned long V_86 [ V_79 ] ;
unsigned int V_87 = 0 ;
unsigned char * V_88 ;
char * V_89 = NULL ;
int V_90 = 0 , V_91 = 0 ;
F_5 ( & V_5 -> V_2 -> V_10 , L_8 ) ;
V_23 = V_5 -> V_23 ;
if ( F_19 ( V_92 , & V_23 -> V_93 ) ) {
V_17 = F_13 ( V_5 , V_94 ) ;
F_39 ( V_95 L_9 ) ;
F_35 ( V_17 , - V_96 ) ;
return;
}
memset ( V_86 , 0 , V_79 * sizeof( long ) ) ;
for ( V_46 = 0 ; V_46 < V_5 -> V_63 ; V_46 ++ ) {
V_64 = F_8 ( V_23 -> V_64 [ V_46 ] ) ;
F_5 ( & V_5 -> V_2 -> V_10 , L_10 , V_46 , V_64 ) ;
F_16 ( V_64 , V_23 -> V_64 [ V_46 ] ) ;
for ( V_82 = 0 ; V_82 < 32 && V_64 ; V_82 ++ ) {
if ( ! ( V_64 & ( 1 << V_82 ) ) )
continue;
V_26 = ( V_46 << 5 ) + V_82 ;
if ( V_26 == V_94 )
continue;
V_17 = F_13 ( V_5 , V_26 ) ;
F_35 ( V_17 , 0 ) ;
F_4 ( V_26 , V_86 ) ;
V_87 ++ ;
}
}
F_34 ( V_5 , L_11 , V_86 , V_87 ) ;
F_18 ( 20 ) ;
F_31 ( V_23 ) ;
V_71 = F_40 ( V_5 -> V_23 , V_97 ,
V_5 -> V_23 -> V_98 ,
V_5 -> V_23 -> V_99 , 1 ) ;
if ( V_71 ) {
F_5 ( & V_5 -> V_2 -> V_10 ,
L_12 ) ;
} else {
V_88 = ( unsigned char * ) V_5 -> V_23 -> V_98 ;
if ( V_88 [ 259 ] & 0x1 ) {
F_41 ( & V_5 -> V_2 -> V_10 ,
L_13 ) ;
F_4 ( V_100 , & V_5 -> V_44 ) ;
V_90 = 1 ;
V_89 = L_14 ;
}
if ( V_88 [ 288 ] == 0xF7 ) {
F_41 ( & V_5 -> V_2 -> V_10 ,
L_15 ) ;
F_4 ( V_101 , & V_5 -> V_44 ) ;
V_91 = 1 ;
V_89 = L_16 ;
}
if ( V_88 [ 288 ] == 0xBF ) {
F_4 ( V_102 , & V_5 -> V_44 ) ;
F_41 ( & V_5 -> V_2 -> V_10 ,
L_17 ) ;
V_91 = 1 ;
V_89 = L_18 ;
}
}
memset ( V_86 , 0 , V_79 * sizeof( long ) ) ;
for ( V_46 = 0 ; V_46 < V_5 -> V_63 ; V_46 ++ ) {
for ( V_82 = 0 ; V_82 < 32 ; V_82 ++ ) {
V_83 = 1 ;
V_26 = ( V_46 << 5 ) + V_82 ;
V_17 = F_13 ( V_5 , V_26 ) ;
V_85 = (struct V_84 * ) V_17 -> V_103 ;
if ( V_26 == V_94 ||
V_85 -> V_103 == V_104 )
V_83 = 0 ;
else {
if ( V_91 ||
( V_90 &&
V_85 -> V_103 == V_105 ) ) {
F_5 ( & V_5 -> V_2 -> V_10 ,
L_19 ,
V_85 -> V_103 == V_105 ?
L_20 : L_21 ,
V_26 ,
V_89 != NULL ?
V_89 : L_22 ) ;
F_35 ( V_17 , - V_106 ) ;
continue;
}
}
if ( V_83 && ( V_17 -> V_107 -- > 0 ) ) {
F_4 ( V_26 , V_86 ) ;
F_21 ( V_23 , V_26 ) ;
continue;
}
F_5 ( & V_23 -> V_5 -> V_2 -> V_10 ,
L_23 , V_26 ) ;
F_35 ( V_17 , - V_96 ) ;
}
}
F_34 ( V_5 , L_24 , V_86 , V_87 ) ;
}
static inline void F_42 ( struct V_45 * V_23 , int V_46 ,
T_2 V_64 )
{
struct V_4 * V_5 = V_23 -> V_5 ;
int V_26 , V_82 ;
struct V_16 * V_103 ;
if ( ! V_64 ) {
F_43 ( ! V_64 ) ;
return;
}
F_16 ( V_64 , V_23 -> V_64 [ V_46 ] ) ;
for ( V_82 = 0 ; ( V_82 < 32 ) && V_64 ; V_82 ++ ) {
if ( V_64 & 0x01 ) {
V_26 = ( V_46 << 5 ) | V_82 ;
if ( F_44 ( V_26 == V_94 ) )
continue;
V_103 = F_13 ( V_5 , V_26 ) ;
F_35 ( V_103 , 0 ) ;
}
V_64 >>= 1 ;
}
if ( F_45 ( & V_5 -> V_108 ) == 0 )
F_16 ( 0xffffffff , V_5 -> V_19 + V_66 ) ;
}
static inline void F_46 ( struct V_4 * V_5 , T_2 V_109 )
{
struct V_45 * V_23 = V_5 -> V_23 ;
struct V_16 * V_17 = F_13 ( V_5 , V_94 ) ;
if ( F_19 ( V_92 , & V_23 -> V_93 ) && V_17 ) {
int V_46 = F_24 ( V_94 ) ;
int V_80 = F_8 ( V_23 -> V_49 [ V_46 ] ) ;
if ( ! ( V_80 & ( 1 << F_23 ( V_94 ) ) ) )
F_35 ( V_17 , 0 ) ;
}
}
static inline void F_47 ( struct V_4 * V_5 , T_2 V_109 )
{
if ( F_44 ( V_109 & V_110 ) ) {
F_5 ( & V_5 -> V_2 -> V_10 ,
L_25 ) ;
F_16 ( ( 1 << 26 ) , V_5 -> V_23 -> V_19 + V_62 ) ;
}
if ( F_44 ( V_109 & V_111 ) ) {
F_5 ( & V_5 -> V_2 -> V_10 ,
L_26 ) ;
F_16 ( ( 1 << 16 ) , V_5 -> V_23 -> V_19 + V_62 ) ;
}
if ( F_44 ( V_109 & ~ V_112 ) ) {
F_5 ( & V_5 -> V_2 -> V_10 ,
L_27 ,
( V_109 & ~ V_112 ) ) ;
if ( F_1 ( V_5 -> V_2 ) )
return;
}
if ( F_48 ( V_109 & ( V_113 | V_114 ) ) ) {
F_4 ( V_115 , & V_5 -> V_23 -> V_93 ) ;
F_49 ( & V_5 -> V_23 -> V_116 ) ;
}
}
static inline T_3 F_50 ( struct V_4 * V_117 )
{
struct V_4 * V_5 = (struct V_4 * ) V_117 ;
struct V_45 * V_23 = V_5 -> V_23 ;
T_2 V_118 , V_109 ;
int V_71 = V_119 ;
int V_120 = 1 , V_56 , V_121 ;
struct V_122 * V_123 ;
V_118 = F_8 ( V_5 -> V_19 + V_66 ) ;
if ( V_118 ) {
V_71 = V_124 ;
V_109 = F_8 ( V_23 -> V_19 + V_65 ) ;
if ( F_44 ( V_109 == 0xFFFFFFFF ) ) {
F_1 ( V_5 -> V_2 ) ;
return V_124 ;
}
F_16 ( V_109 , V_23 -> V_19 + V_65 ) ;
if ( F_48 ( V_109 & V_125 ) ) {
V_120 = 0 ;
F_43 ( F_51 ( & V_5 -> V_108 ) != 0 ) ;
for ( V_56 = 0 , V_121 = 0 ; V_56 < V_126 ;
V_56 ++ ) {
V_123 = & V_5 -> V_127 [ V_56 ] ;
V_123 -> V_64 = F_8 ( V_23 -> V_64 [ V_56 ] ) ;
if ( V_123 -> V_64 )
V_121 ++ ;
}
F_52 ( & V_5 -> V_108 , V_121 ) ;
if ( V_121 ) {
for ( V_56 = 1 ; V_56 < V_126 ; V_56 ++ ) {
V_123 = & V_5 -> V_127 [ V_56 ] ;
if ( V_123 -> V_64 )
F_53 (
V_123 -> V_128 ,
V_5 -> V_129 ,
& V_123 -> V_127 ) ;
}
if ( F_48 ( V_5 -> V_127 [ 0 ] . V_64 ) )
F_42 ( V_23 , 0 ,
V_5 -> V_127 [ 0 ] . V_64 ) ;
} else {
V_120 = 1 ;
}
}
if ( F_44 ( V_109 & V_130 ) ) {
if ( F_44 ( F_1 ( V_5 -> V_2 ) ) ) {
return V_124 ;
}
if ( F_19 ( V_43 ,
& V_5 -> V_44 ) )
return V_71 ;
F_47 ( V_5 , V_109 & V_130 ) ;
}
if ( F_44 ( V_109 & V_131 ) )
F_46 ( V_5 , V_109 & V_131 ) ;
}
if ( F_44 ( V_120 ) )
F_16 ( V_118 , V_5 -> V_19 + V_66 ) ;
return V_71 ;
}
static T_3 F_54 ( int V_132 , void * V_133 )
{
struct V_4 * V_5 = V_133 ;
return F_50 ( V_5 ) ;
}
static void F_55 ( struct V_45 * V_23 , int V_26 )
{
F_16 ( 1 << F_23 ( V_26 ) , V_23 -> V_49 [ F_24 ( V_26 ) ] ) ;
}
static bool F_56 ( struct V_45 * V_23 ,
struct V_84 * V_85 )
{
struct V_84 * V_134 ;
unsigned long V_135 ;
V_134 = V_23 -> V_136 + V_137 ;
V_135 = F_8 ( V_23 -> V_19 + V_138 ) ;
if ( ( V_135 & 1 ) )
return false ;
if ( V_85 -> V_103 == V_139 ) {
V_23 -> V_140 = V_42 ;
return true ;
} else if ( ( V_85 -> V_103 == V_141 ) &&
( V_85 -> V_142 == 0x03 ) ) {
F_4 ( V_143 , & V_23 -> V_93 ) ;
V_23 -> V_140 = V_42 ;
return true ;
} else if ( ( V_85 -> V_103 == V_144 ) ||
( ( V_85 -> V_103 == 0xFC ) &&
( V_85 -> V_142 == 0x27 || V_85 -> V_142 == 0x72 ||
V_85 -> V_142 == 0x62 || V_85 -> V_142 == 0x26 ) ) ) {
F_57 ( V_145 , & V_23 -> V_5 -> V_44 ) ;
F_57 ( V_102 , & V_23 -> V_5 -> V_44 ) ;
F_31 ( V_23 ) ;
F_57 ( V_146 , & V_23 -> V_93 ) ;
return false ;
}
return false ;
}
static bool F_58 ( struct V_45 * V_23 )
{
unsigned int V_147 ;
unsigned int V_148 ;
V_147 = F_8 ( V_23 -> V_48 [ 0 ] ) & 0xFFFFFFFE ;
for ( V_148 = 1 ; V_148 < V_23 -> V_5 -> V_63 ; V_148 ++ )
V_147 |= F_8 ( V_23 -> V_48 [ V_148 ] ) ;
return V_147 != 0 ;
}
static int F_59 ( struct V_45 * V_23 , unsigned long V_39 )
{
unsigned long V_149 ;
bool V_147 = true ;
F_60 ( V_23 -> V_5 -> V_7 ) ;
V_149 = V_42 + F_17 ( V_39 ) ;
do {
if ( F_19 ( V_150 , & V_23 -> V_93 ) &&
F_19 ( V_151 , & V_23 -> V_93 ) ) {
F_61 ( 20 ) ;
continue;
}
F_61 ( 100 ) ;
if ( F_1 ( V_23 -> V_5 -> V_2 ) )
goto V_152;
V_147 = F_58 ( V_23 ) ;
if ( ! V_147 )
break;
} while ( F_20 ( V_42 , V_149 ) );
F_62 ( V_23 -> V_5 -> V_7 , true ) ;
return V_147 ? - V_153 : 0 ;
V_152:
F_62 ( V_23 -> V_5 -> V_7 , true ) ;
return - V_72 ;
}
static int F_63 ( struct V_45 * V_23 ,
struct V_84 * V_85 ,
int V_154 ,
T_4 V_155 ,
int V_156 ,
T_2 V_157 ,
unsigned long V_39 )
{
struct V_16 * V_158 ;
struct V_4 * V_5 = V_23 -> V_5 ;
struct V_12 * V_13 ;
struct V_159 V_160 = {
. V_154 = V_154 ,
. V_155 = V_155 ,
. V_156 = V_156 ,
. V_157 = V_157
} ;
int V_71 = 0 ;
unsigned long V_161 ;
if ( V_155 & 0x00000007 ) {
F_32 ( & V_5 -> V_2 -> V_10 , L_28 ) ;
return - V_72 ;
}
V_158 = F_10 ( V_5 ) ;
if ( ! V_158 ) {
F_39 ( V_95 L_29 ) ;
return - V_72 ;
}
V_13 = F_36 ( V_158 ) ;
V_13 -> V_162 = & V_160 ;
F_4 ( V_92 , & V_23 -> V_93 ) ;
if ( V_85 -> V_103 == V_139 )
F_4 ( V_146 , & V_23 -> V_93 ) ;
F_57 ( V_143 , & V_23 -> V_93 ) ;
if ( V_85 -> V_103 != V_163 ) {
if ( F_59 ( V_23 , V_164 ) < 0 ) {
F_5 ( & V_5 -> V_2 -> V_10 , L_30 ) ;
F_64 ( V_13 ) ;
F_57 ( V_92 , & V_23 -> V_93 ) ;
F_49 ( & V_23 -> V_116 ) ;
return - V_153 ;
}
}
memcpy ( V_158 -> V_103 , V_85 , V_154 * 4 ) ;
V_161 = V_42 ;
V_13 -> V_39 = V_39 ;
F_65 ( V_13 -> V_14 , NULL , V_13 , true ) ;
V_71 = V_158 -> V_80 ;
if ( V_71 < 0 ) {
if ( V_71 == - V_165 ) {
F_32 ( & V_5 -> V_2 -> V_10 ,
L_31 ,
V_85 -> V_103 ,
F_66 ( V_42 - V_161 ) ) ;
V_71 = - V_166 ;
goto V_167;
} else if ( V_71 == 0 )
F_32 ( & V_5 -> V_2 -> V_10 ,
L_32 ,
V_85 -> V_103 , V_39 ) ;
else
F_32 ( & V_5 -> V_2 -> V_10 ,
L_33 ,
V_85 -> V_103 , V_71 , V_39 ) ;
if ( F_1 ( V_5 -> V_2 ) ||
F_19 ( V_43 ,
& V_5 -> V_44 ) ) {
F_32 ( & V_5 -> V_2 -> V_10 ,
L_34 ,
V_85 -> V_103 ) ;
V_71 = - V_168 ;
goto V_167;
}
F_33 ( V_5 ) ;
V_71 = - V_169 ;
goto V_167;
}
if ( F_8 ( V_23 -> V_49 [ F_24 ( V_94 ) ] )
& ( 1 << F_23 ( V_94 ) ) ) {
V_71 = - V_168 ;
if ( ! F_19 ( V_43 , & V_5 -> V_44 ) ) {
F_33 ( V_5 ) ;
V_71 = - V_169 ;
}
}
V_167:
F_64 ( V_13 ) ;
F_57 ( V_92 , & V_23 -> V_93 ) ;
if ( V_71 >= 0 && F_56 ( V_23 , V_85 ) ) {
return V_71 ;
}
F_49 ( & V_23 -> V_116 ) ;
return V_71 ;
}
static inline void F_67 ( T_1 * V_88 , unsigned int V_170 )
{
int V_56 ;
for ( V_56 = 0 ; V_56 < ( V_170 / 2 ) ; V_56 ++ )
F_68 ( & V_88 [ V_56 ] ) ;
}
static void F_69 ( struct V_4 * V_5 ,
struct V_84 * V_85 ,
unsigned int * V_39 , T_5 V_171 )
{
switch ( V_85 -> V_103 ) {
case V_141 :
* V_39 = 120000 ;
break;
case V_144 :
case 0xFC :
if ( V_171 )
* V_39 = ( ( * ( V_5 -> V_23 -> V_172 + 90 ) * 2 ) * 60000 ) ;
else
* V_39 = ( ( * ( V_5 -> V_23 -> V_172 + 89 ) * 2 ) * 60000 ) ;
break;
case V_163 :
* V_39 = 120000 ;
break;
case 0xF7 :
case 0xFA :
* V_39 = 60000 ;
break;
case V_173 :
* V_39 = 15000 ;
break;
default:
* V_39 = V_174 ;
break;
}
}
static int F_70 ( struct V_45 * V_23 , void T_6 * V_175 )
{
int V_71 = 0 ;
struct V_84 V_85 ;
if ( F_19 ( V_43 , & V_23 -> V_5 -> V_44 ) )
return - V_72 ;
memset ( & V_85 , 0 , sizeof( struct V_84 ) ) ;
V_85 . type = 0x27 ;
V_85 . V_157 = 1 << 7 ;
V_85 . V_103 = V_176 ;
V_23 -> V_177 = 0 ;
memset ( V_23 -> V_172 , 0 , sizeof( T_1 ) * V_178 ) ;
if ( F_63 ( V_23 ,
& V_85 ,
5 ,
V_23 -> V_179 ,
sizeof( T_1 ) * V_178 ,
0 ,
V_180 )
< 0 ) {
V_71 = - 1 ;
goto V_181;
}
#ifdef F_71
F_67 ( V_23 -> V_172 + 27 , 40 ) ;
F_67 ( V_23 -> V_172 + 23 , 8 ) ;
F_67 ( V_23 -> V_172 + 10 , 20 ) ;
#else
{
int V_56 ;
for ( V_56 = 0 ; V_56 < V_178 ; V_56 ++ )
V_23 -> V_172 [ V_56 ] = F_72 ( V_23 -> V_172 [ V_56 ] ) ;
}
#endif
if ( V_23 -> V_172 [ 128 ] & 0x4 )
F_4 ( V_145 , & V_23 -> V_5 -> V_44 ) ;
else
F_57 ( V_145 , & V_23 -> V_5 -> V_44 ) ;
#ifdef F_73
if ( V_23 -> V_172 [ 69 ] & ( 1 << 14 ) && V_23 -> V_172 [ 69 ] & ( 1 << 5 ) )
V_23 -> V_5 -> V_182 = true ;
else
#endif
V_23 -> V_5 -> V_182 = false ;
V_23 -> V_177 = 1 ;
if ( V_175 ) {
if ( F_74 (
V_175 ,
V_23 -> V_172 ,
V_178 * sizeof( T_1 ) ) ) {
V_71 = - V_72 ;
goto V_181;
}
}
V_181:
return V_71 ;
}
static int F_75 ( struct V_45 * V_23 )
{
int V_71 ;
struct V_84 V_85 ;
unsigned long V_161 ;
unsigned int V_39 ;
memset ( & V_85 , 0 , sizeof( struct V_84 ) ) ;
V_85 . type = 0x27 ;
V_85 . V_157 = 1 << 7 ;
V_85 . V_103 = V_163 ;
F_69 ( V_23 -> V_5 , & V_85 , & V_39 , 0 ) ;
V_161 = V_42 ;
V_71 = F_63 ( V_23 ,
& V_85 ,
5 ,
0 ,
0 ,
0 ,
V_39 ) ;
F_39 ( V_95 L_35 ,
F_66 ( V_42 - V_161 ) ) ;
if ( V_71 )
F_5 ( & V_23 -> V_5 -> V_2 -> V_10 ,
L_36 ) ;
return V_71 ;
}
static int F_40 ( struct V_45 * V_23 , T_5 V_183 , T_1 * V_155 ,
T_4 V_184 , unsigned int V_185 )
{
struct V_84 V_85 ;
memset ( & V_85 , 0 , sizeof( struct V_84 ) ) ;
V_85 . type = 0x27 ;
V_85 . V_157 = 1 << 7 ;
V_85 . V_103 = V_186 ;
V_85 . V_187 = V_185 & 0xFF ;
V_85 . V_188 = ( V_185 >> 8 ) & 0xFF ;
V_85 . V_189 = V_183 ;
V_85 . V_190 = 0 ;
V_85 . V_191 = V_192 ;
memset ( V_155 , 0 , V_185 * V_193 ) ;
return F_63 ( V_23 ,
& V_85 ,
5 ,
V_184 ,
V_185 * V_193 ,
0 ,
V_180 ) ;
}
static int F_76 ( struct V_45 * V_23 , T_5 * V_155 ,
T_4 V_184 )
{
struct V_84 V_85 ;
memset ( & V_85 , 0 , sizeof( struct V_84 ) ) ;
V_85 . type = 0x27 ;
V_85 . V_157 = 1 << 7 ;
V_85 . V_103 = V_173 ;
V_85 . V_142 = 0xD0 ;
V_85 . V_187 = 1 ;
V_85 . V_190 = 0x4F ;
V_85 . V_194 = 0xC2 ;
V_85 . V_191 = V_192 ;
return F_63 ( V_23 ,
& V_85 ,
5 ,
V_184 ,
V_193 ,
0 ,
15000 ) ;
}
static int F_77 ( struct V_45 * V_23 , unsigned int V_195 ,
struct V_196 * V_197 )
{
int V_71 , V_56 ;
struct V_196 * V_198 ;
if ( ! V_197 )
return - V_199 ;
if ( ! V_23 -> V_177 ) {
F_5 ( & V_23 -> V_5 -> V_2 -> V_10 , L_37 ) ;
return - V_200 ;
}
if ( ! ( V_23 -> V_172 [ 82 ] & 0x1 ) ) {
F_5 ( & V_23 -> V_5 -> V_2 -> V_10 , L_38 ) ;
return - V_200 ;
}
if ( ! ( V_23 -> V_172 [ 85 ] & 0x1 ) ) {
F_5 ( & V_23 -> V_5 -> V_2 -> V_10 , L_39 ) ;
return - V_200 ;
}
memset ( V_23 -> V_201 , 0 , V_193 ) ;
V_71 = F_76 ( V_23 , V_23 -> V_201 , V_23 -> V_202 ) ;
if ( V_71 ) {
F_5 ( & V_23 -> V_5 -> V_2 -> V_10 , L_40 ) ;
return V_71 ;
}
V_198 = (struct V_196 * ) ( V_23 -> V_201 + 2 ) ;
for ( V_56 = 0 ; V_56 < 29 ; V_56 ++ , V_198 ++ )
if ( V_198 -> V_203 == V_195 ) {
memcpy ( V_197 , V_198 , sizeof( struct V_196 ) ) ;
break;
}
if ( V_56 == 29 ) {
F_5 ( & V_23 -> V_5 -> V_2 -> V_10 ,
L_41 ) ;
V_71 = - V_199 ;
}
return V_71 ;
}
static int F_78 ( struct V_4 * V_5 , unsigned int V_204 ,
unsigned int V_170 )
{
int V_56 , V_71 = 0 ;
T_7 V_205 , V_206 , V_207 ;
struct V_208 * V_88 ;
T_4 V_209 ;
struct V_84 V_85 ;
if ( ! V_170 || V_5 -> V_182 == false )
return - V_199 ;
F_79 ( V_170 > ( V_210 * V_211 ) ) ;
F_79 ( V_170 % 8 != 0 ) ;
F_79 ( sizeof( struct V_212 ) > V_193 ) ;
V_88 = F_80 ( & V_5 -> V_2 -> V_10 , V_193 , & V_209 ,
V_213 ) ;
if ( ! V_88 )
return - V_214 ;
memset ( V_88 , 0 , V_193 ) ;
for ( V_56 = 0 , V_207 = V_170 , V_205 = V_204 ;
V_56 < V_211 && V_207 ;
V_56 ++ ) {
V_206 = ( V_207 >= V_210 ?
V_210 :
V_207 ) ;
V_88 [ V_56 ] . V_204 = V_30 F_9 ( V_205 ) ;
V_88 [ V_56 ] . V_215 = V_30 F_81 ( V_206 ) ;
V_205 += V_206 ;
V_207 -= V_206 ;
}
F_79 ( V_207 != 0 ) ;
memset ( & V_85 , 0 , sizeof( struct V_84 ) ) ;
V_85 . type = 0x27 ;
V_85 . V_157 = 1 << 7 ;
V_85 . V_103 = 0xfb ;
V_85 . V_142 = 0x60 ;
V_85 . V_187 = 1 ;
V_85 . V_191 = V_192 ;
if ( F_63 ( V_5 -> V_23 ,
& V_85 ,
5 ,
V_209 ,
V_193 ,
0 ,
V_216 ) < 0 )
V_71 = - V_96 ;
F_82 ( & V_5 -> V_2 -> V_10 , V_193 , V_88 , V_209 ) ;
return V_71 ;
}
static bool F_83 ( struct V_4 * V_5 , T_8 * V_185 )
{
struct V_45 * V_23 = V_5 -> V_23 ;
T_7 V_217 , V_218 , V_219 , V_220 , V_221 ;
V_218 = V_23 -> V_172 [ 100 ] ;
V_219 = V_23 -> V_172 [ 101 ] ;
V_220 = V_23 -> V_172 [ 102 ] ;
V_221 = V_23 -> V_172 [ 103 ] ;
V_217 = V_218 | V_219 << 16 | V_220 << 32 | V_221 << 48 ;
* V_185 = V_217 ;
return ( bool ) ! ! V_23 -> V_177 ;
}
static void F_84 ( struct V_45 * V_23 )
{
T_8 V_185 ;
unsigned short V_222 ;
char V_223 [ 42 ] ;
if ( ! V_23 -> V_177 )
return;
F_85 ( V_223 , ( char * ) ( V_23 -> V_172 + 10 ) , 21 ) ;
F_41 ( & V_23 -> V_5 -> V_2 -> V_10 ,
L_42 , V_223 ) ;
F_85 ( V_223 , ( char * ) ( V_23 -> V_172 + 23 ) , 9 ) ;
F_41 ( & V_23 -> V_5 -> V_2 -> V_10 ,
L_43 , V_223 ) ;
F_85 ( V_223 , ( char * ) ( V_23 -> V_172 + 27 ) , 41 ) ;
F_41 ( & V_23 -> V_5 -> V_2 -> V_10 , L_44 , V_223 ) ;
F_41 ( & V_23 -> V_5 -> V_2 -> V_10 , L_45 ,
V_23 -> V_172 [ 128 ] ,
V_23 -> V_172 [ 128 ] & 0x4 ? L_46 : L_47 ) ;
if ( F_83 ( V_23 -> V_5 , & V_185 ) )
F_41 ( & V_23 -> V_5 -> V_2 -> V_10 ,
L_48 ,
( T_7 ) V_185 ,
( ( T_7 ) V_185 ) * V_193 >> 20 ) ;
F_3 ( V_23 -> V_5 -> V_2 , V_224 , & V_222 ) ;
switch ( V_222 & 0xFF ) {
case 0x1 :
F_85 ( V_223 , L_49 , 3 ) ;
break;
case 0x3 :
F_85 ( V_223 , L_50 , 3 ) ;
break;
default:
F_85 ( V_223 , L_51 , 2 ) ;
break;
}
F_41 ( & V_23 -> V_5 -> V_2 -> V_10 ,
L_52 , V_223 ) ;
}
static inline void F_86 ( struct V_4 * V_5 ,
struct V_16 * V_103 ,
int V_225 )
{
int V_148 ;
unsigned int V_226 ;
struct V_227 * V_228 ;
struct V_229 * V_230 = V_103 -> V_230 ;
V_228 = V_103 -> V_103 + V_231 ;
for ( V_148 = 0 ; V_148 < V_225 ; V_148 ++ ) {
V_226 = F_87 ( V_230 ) ;
if ( V_226 > 0x400000 )
F_32 ( & V_5 -> V_2 -> V_10 ,
L_53 ) ;
V_228 -> V_232 = V_30
F_9 ( ( V_226 - 1 ) & 0x3FFFFF ) ;
V_228 -> V_233 = V_30
F_9 ( F_88 ( V_230 ) ) ;
V_228 -> V_234 = V_30
F_9 ( ( F_88 ( V_230 ) >> 16 ) >> 16 ) ;
V_228 ++ ;
V_230 ++ ;
}
}
static int F_89 ( struct V_45 * V_23 , T_5 * V_103 )
{
struct V_84 V_85 ;
struct V_84 * V_134 = ( V_23 -> V_136 + V_137 ) ;
unsigned int V_149 ;
memset ( & V_85 , 0 , sizeof( struct V_84 ) ) ;
V_85 . type = 0x27 ;
V_85 . V_157 = 1 << 7 ;
V_85 . V_103 = V_103 [ 0 ] ;
V_85 . V_142 = V_103 [ 1 ] ;
V_85 . V_187 = V_103 [ 2 ] ;
V_85 . V_235 = V_103 [ 3 ] ;
V_85 . V_236 = V_103 [ 4 ] ;
V_85 . V_237 = V_103 [ 5 ] ;
V_85 . V_191 = V_103 [ 6 ] & ~ 0x10 ;
F_69 ( V_23 -> V_5 , & V_85 , & V_149 , 0 ) ;
F_39 ( V_95 L_54 ,
V_11 ,
V_103 [ 0 ] ,
V_103 [ 1 ] ,
V_103 [ 2 ] ,
V_103 [ 3 ] ,
V_103 [ 4 ] ,
V_103 [ 5 ] ,
V_103 [ 6 ] ) ;
if ( F_63 ( V_23 ,
& V_85 ,
5 ,
0 ,
0 ,
0 ,
V_149 ) < 0 ) {
return - 1 ;
}
V_103 [ 0 ] = V_134 -> V_103 ;
V_103 [ 1 ] = V_134 -> V_142 ;
V_103 [ 4 ] = V_134 -> V_236 ;
V_103 [ 5 ] = V_134 -> V_237 ;
F_39 ( V_95 L_55 ,
V_11 ,
V_103 [ 0 ] ,
V_103 [ 1 ] ,
V_103 [ 4 ] ,
V_103 [ 5 ] ) ;
return 0 ;
}
static int F_90 ( struct V_45 * V_23 , T_5 * V_103 ,
void T_6 * V_175 )
{
struct V_84 V_85 ;
struct V_84 * V_134 ;
T_5 * V_88 = NULL ;
T_4 V_209 = 0 ;
int V_71 = 0 , V_238 = V_103 [ 3 ] ;
unsigned int V_149 ;
if ( V_238 ) {
if ( ! V_175 )
return - V_72 ;
V_88 = F_80 ( & V_23 -> V_5 -> V_2 -> V_10 ,
V_193 * V_238 ,
& V_209 ,
V_213 ) ;
if ( ! V_88 ) {
F_32 ( & V_23 -> V_5 -> V_2 -> V_10 ,
L_56 ,
V_193 * V_238 ) ;
return - V_214 ;
}
memset ( V_88 , 0 , V_193 * V_238 ) ;
}
memset ( & V_85 , 0 , sizeof( struct V_84 ) ) ;
V_85 . type = 0x27 ;
V_85 . V_157 = 1 << 7 ;
V_85 . V_103 = V_103 [ 0 ] ;
V_85 . V_142 = V_103 [ 2 ] ;
V_85 . V_187 = V_103 [ 3 ] ;
if ( V_85 . V_103 == V_173 ) {
V_85 . V_235 = V_103 [ 1 ] ;
V_85 . V_236 = 0x4F ;
V_85 . V_237 = 0xC2 ;
}
F_69 ( V_23 -> V_5 , & V_85 , & V_149 , 0 ) ;
if ( V_238 )
V_134 = ( V_23 -> V_136 + V_239 ) ;
else
V_134 = ( V_23 -> V_136 + V_137 ) ;
F_39 ( V_95
L_57
L_58 ,
V_11 ,
V_103 [ 0 ] ,
V_103 [ 1 ] ,
V_103 [ 2 ] ,
V_103 [ 3 ] ) ;
if ( F_63 ( V_23 ,
& V_85 ,
5 ,
( V_238 ? V_209 : 0 ) ,
( V_238 ? V_193 * V_238 : 0 ) ,
0 ,
V_149 )
< 0 ) {
V_71 = - V_72 ;
goto V_240;
}
V_103 [ 0 ] = V_134 -> V_103 ;
V_103 [ 1 ] = V_134 -> V_142 ;
V_103 [ 2 ] = V_134 -> V_187 ;
F_39 ( V_95
L_59
L_60 ,
V_11 ,
V_103 [ 0 ] ,
V_103 [ 1 ] ,
V_103 [ 2 ] ) ;
if ( V_238 ) {
if ( F_74 ( V_175 ,
V_88 ,
V_193 * V_103 [ 3 ] ) ) {
V_71 = - V_72 ;
goto V_240;
}
}
V_240:
if ( V_88 )
F_82 ( & V_23 -> V_5 -> V_2 -> V_10 ,
V_193 * V_238 , V_88 , V_209 ) ;
return V_71 ;
}
static unsigned int F_91 ( unsigned char V_103 ,
unsigned char V_142 )
{
unsigned int V_71 = 0 ;
switch ( V_103 ) {
case V_241 :
case V_242 :
case V_139 :
case V_144 :
case V_243 :
case V_244 :
case V_245 :
case V_246 :
V_71 = 1 ;
break;
case V_247 :
if ( V_142 == V_248 )
V_71 = 1 ;
break;
case V_173 :
if ( ( V_142 == V_249 ) ||
( V_142 == V_250 ) )
V_71 = 1 ;
break;
case V_251 :
if ( ( V_142 == V_252 ) ||
( V_142 == V_253 ) )
V_71 = 1 ;
break;
}
return V_71 ;
}
static int F_92 ( struct V_4 * V_5 ,
void T_6 * V_88 ,
T_9 * V_254 ,
int V_255 )
{
struct V_84 V_85 ;
struct V_84 * V_134 ;
T_5 * V_256 = NULL ;
T_5 * V_257 = NULL ;
T_4 V_258 = 0 ;
T_4 V_259 = 0 ;
T_4 V_260 = 0 ;
int V_261 = 0 ;
unsigned int V_262 = 0 ;
unsigned int V_263 = 0 ;
T_5 V_264 = 0 ;
unsigned int V_39 ;
unsigned int V_265 ;
unsigned int V_266 ;
unsigned long V_135 ;
int V_267 = V_255 + V_254 -> V_268 ;
int V_171 = 0 ;
V_263 = V_254 -> V_268 ;
V_262 = V_254 -> V_269 ;
if ( V_262 > 130560 || V_263 > 130560 )
return - V_199 ;
if ( V_263 ) {
V_256 = F_93 ( V_88 + V_255 , V_263 ) ;
if ( F_12 ( V_256 ) )
return F_94 ( V_256 ) ;
V_258 = F_95 ( V_5 -> V_2 ,
V_256 ,
V_263 ,
V_270 ) ;
if ( F_96 ( V_5 -> V_2 , V_258 ) ) {
V_261 = - V_214 ;
goto abort;
}
V_260 = V_258 ;
}
if ( V_262 ) {
V_257 = F_93 ( V_88 + V_267 , V_262 ) ;
if ( F_12 ( V_257 ) ) {
V_261 = F_94 ( V_257 ) ;
V_257 = NULL ;
goto abort;
}
V_259 = F_95 ( V_5 -> V_2 ,
V_257 ,
V_262 , V_271 ) ;
if ( F_96 ( V_5 -> V_2 , V_259 ) ) {
V_261 = - V_214 ;
goto abort;
}
V_260 = V_259 ;
}
switch ( V_254 -> V_272 ) {
case V_273 :
V_264 = V_263 / V_193 ;
V_134 = ( V_5 -> V_23 -> V_136 + V_239 ) ;
break;
case V_274 :
V_134 = ( V_5 -> V_23 -> V_136 + V_239 ) ;
break;
case V_275 :
V_134 = ( V_5 -> V_23 -> V_136 + V_137 ) ;
break;
default:
V_261 = - V_199 ;
goto abort;
}
memset ( & V_85 , 0 , sizeof( struct V_84 ) ) ;
V_85 . type = 0x27 ;
V_85 . V_157 = 1 << 7 ;
V_85 . V_103 = V_254 -> V_276 [ 7 ] ;
V_85 . V_142 = V_254 -> V_276 [ 1 ] ;
V_85 . V_187 = V_254 -> V_276 [ 2 ] ;
V_85 . V_189 = V_254 -> V_276 [ 3 ] ;
V_85 . V_190 = V_254 -> V_276 [ 4 ] ;
V_85 . V_194 = V_254 -> V_276 [ 5 ] ;
V_85 . V_191 = V_254 -> V_276 [ 6 ] & ~ 0x10 ;
if ( ( V_254 -> V_277 . V_278 == 0 ) && ( V_254 -> V_279 . V_278 & 1 ) ) {
V_254 -> V_277 . V_278 =
V_280 |
( V_281 << 8 ) ;
V_85 . V_282 = V_254 -> V_283 [ 3 ] ;
V_85 . V_284 = V_254 -> V_283 [ 4 ] ;
V_85 . V_285 = V_254 -> V_283 [ 5 ] ;
V_85 . V_286 = V_254 -> V_283 [ 1 ] ;
V_85 . V_188 = V_254 -> V_283 [ 2 ] ;
} else {
V_254 -> V_277 . V_278 = V_280 ;
}
V_265 = F_91 ( V_85 . V_103 , V_85 . V_142 ) ;
if ( ( V_262 || V_263 ) && ( ! V_85 . V_187 ) ) {
if ( V_264 )
V_85 . V_187 = V_264 ;
else {
if ( ! V_265 ) {
F_5 ( & V_5 -> V_2 -> V_10 ,
L_61
L_62 ) ;
V_261 = - V_199 ;
goto abort;
}
}
}
F_39 ( V_95
L_63
L_64
L_65 ,
V_11 ,
V_85 . V_103 ,
V_85 . V_142 ,
V_85 . V_187 ,
V_85 . V_189 ,
V_85 . V_190 ,
V_85 . V_194 ,
V_85 . V_191 ) ;
if ( ( V_85 . V_103 == V_144 ) && V_256 &&
( V_256 [ 0 ] & V_287 ) ) {
V_171 = 1 ;
}
F_69 ( V_5 , & V_85 , & V_39 , V_171 ) ;
if ( V_265 )
V_266 = V_193 ;
else
V_266 = V_193 * V_85 . V_187 ;
if ( F_63 ( V_5 -> V_23 ,
& V_85 ,
5 ,
V_260 ,
V_266 ,
0 ,
V_39 ) < 0 ) {
V_261 = - V_96 ;
goto abort;
}
V_135 = F_8 ( V_5 -> V_23 -> V_19 + V_138 ) ;
if ( ( V_254 -> V_272 == V_274 ) && ! ( V_135 & 1 ) ) {
V_134 = V_5 -> V_23 -> V_136 + V_239 ;
V_254 -> V_276 [ 7 ] = V_134 -> V_288 ;
} else {
V_134 = V_5 -> V_23 -> V_136 + V_137 ;
V_254 -> V_276 [ 7 ] = V_134 -> V_103 ;
}
if ( V_259 )
F_97 ( V_5 -> V_2 , V_259 ,
V_262 , V_271 ) ;
if ( V_258 )
F_97 ( V_5 -> V_2 , V_258 ,
V_263 , V_270 ) ;
V_259 = 0 ;
V_258 = 0 ;
V_254 -> V_276 [ 1 ] = V_134 -> V_142 ;
V_254 -> V_276 [ 2 ] = V_134 -> V_187 ;
V_254 -> V_276 [ 3 ] = V_134 -> V_189 ;
V_254 -> V_276 [ 4 ] = V_134 -> V_190 ;
V_254 -> V_276 [ 5 ] = V_134 -> V_194 ;
V_254 -> V_276 [ 6 ] = V_134 -> V_191 ;
if ( V_254 -> V_279 . V_278 & 1 ) {
V_254 -> V_283 [ 3 ] = V_134 -> V_282 ;
V_254 -> V_283 [ 4 ] = V_134 -> V_284 ;
V_254 -> V_283 [ 5 ] = V_134 -> V_285 ;
V_254 -> V_283 [ 1 ] = V_134 -> V_286 ;
V_254 -> V_283 [ 2 ] = V_134 -> V_188 ;
}
F_39 ( V_95
L_66
L_67
L_68 ,
V_11 ,
V_254 -> V_276 [ 7 ] ,
V_254 -> V_276 [ 1 ] ,
V_254 -> V_276 [ 2 ] ,
V_254 -> V_276 [ 3 ] ,
V_254 -> V_276 [ 4 ] ,
V_254 -> V_276 [ 5 ] ,
V_254 -> V_276 [ 6 ] ) ;
if ( V_263 ) {
if ( F_74 ( V_88 + V_255 , V_256 , V_263 ) ) {
V_261 = - V_72 ;
goto abort;
}
}
if ( V_262 ) {
if ( F_74 ( V_88 + V_267 , V_257 , V_262 ) ) {
V_261 = - V_72 ;
goto abort;
}
}
abort:
if ( V_259 )
F_97 ( V_5 -> V_2 , V_259 ,
V_262 , V_271 ) ;
if ( V_258 )
F_97 ( V_5 -> V_2 , V_258 ,
V_263 , V_270 ) ;
F_98 ( V_256 ) ;
F_98 ( V_257 ) ;
return V_261 ;
}
static int F_99 ( struct V_4 * V_5 , unsigned int V_17 ,
unsigned long V_289 )
{
switch ( V_17 ) {
case V_290 :
{
if ( F_74 ( ( void T_6 * ) V_289 , V_5 -> V_23 -> V_172 ,
sizeof( T_1 ) * V_178 ) )
return - V_72 ;
break;
}
case V_291 :
{
T_5 V_292 [ 4 ] ;
if ( F_100 ( V_292 ,
( void T_6 * ) V_289 ,
sizeof( V_292 ) ) )
return - V_72 ;
if ( F_90 ( V_5 -> V_23 ,
V_292 ,
( void T_6 * ) ( V_289 + 4 ) ) )
return - V_96 ;
if ( F_74 ( ( void T_6 * ) V_289 ,
V_292 ,
sizeof( V_292 ) ) )
return - V_72 ;
break;
}
case V_293 :
{
T_5 V_292 [ 7 ] ;
if ( F_100 ( V_292 ,
( void T_6 * ) V_289 ,
sizeof( V_292 ) ) )
return - V_72 ;
if ( F_89 ( V_5 -> V_23 , V_292 ) )
return - V_96 ;
if ( F_74 ( ( void T_6 * ) V_289 ,
V_292 ,
sizeof( V_292 ) ) )
return - V_72 ;
break;
}
case V_294 : {
T_9 V_254 ;
int V_295 , V_255 ;
if ( F_100 ( & V_254 , ( void T_6 * ) V_289 ,
sizeof( V_254 ) ) )
return - V_72 ;
V_255 = sizeof( V_254 ) ;
V_295 = F_92 ( V_5 , ( void T_6 * ) V_289 ,
& V_254 , V_255 ) ;
if ( F_74 ( ( void T_6 * ) V_289 , & V_254 ,
sizeof( V_254 ) ) )
return - V_72 ;
return V_295 ;
}
default:
return - V_199 ;
}
return 0 ;
}
static void F_101 ( struct V_4 * V_5 , struct V_12 * V_13 ,
struct V_16 * V_103 , int V_225 ,
struct V_35 * V_36 )
{
struct V_84 * V_85 ;
struct V_45 * V_23 = V_5 -> V_23 ;
int V_296 = F_102 ( V_13 ) == V_297 ? V_271 : V_270 ;
T_7 V_161 = F_103 ( V_13 ) ;
unsigned int V_264 = F_104 ( V_13 ) ;
V_225 = F_105 ( & V_5 -> V_2 -> V_10 , V_103 -> V_230 , V_225 , V_296 ) ;
F_106 ( & V_23 -> V_93 ) ;
V_103 -> V_298 = V_225 ;
V_103 -> V_107 = V_299 ;
V_85 = V_103 -> V_103 ;
V_85 -> type = 0x27 ;
V_85 -> V_157 = 1 << 7 ;
if ( V_296 == V_271 )
V_85 -> V_103 = V_300 ;
else
V_85 -> V_103 = V_105 ;
V_85 -> V_189 = V_161 & 0xFF ;
V_85 -> V_190 = ( V_161 >> 8 ) & 0xFF ;
V_85 -> V_194 = ( V_161 >> 16 ) & 0xFF ;
V_85 -> V_282 = ( V_161 >> 24 ) & 0xFF ;
V_85 -> V_284 = ( V_161 >> 32 ) & 0xFF ;
V_85 -> V_285 = ( V_161 >> 40 ) & 0xFF ;
V_85 -> V_191 = 1 << 6 ;
V_85 -> V_142 = V_264 & 0xFF ;
V_85 -> V_286 = ( V_264 >> 8 ) & 0xFF ;
V_85 -> V_187 = ( ( V_13 -> V_26 << 3 ) | ( V_13 -> V_26 >> 5 ) ) ;
V_85 -> V_188 = 0 ;
V_85 -> V_288 = 0 ;
V_85 -> V_301 = 0 ;
V_85 -> V_302 = 0 ;
F_86 ( V_5 , V_103 , V_225 ) ;
if ( F_44 ( V_103 -> V_303 ) )
V_85 -> V_191 |= 1 << 7 ;
V_103 -> V_22 -> V_157 =
V_30 F_9 (
( V_225 << 16 ) | 5 | V_304 ) ;
V_103 -> V_22 -> V_305 = 0 ;
V_103 -> V_306 = V_296 ;
if ( F_44 ( V_23 -> V_93 & V_307 ) ) {
F_4 ( V_13 -> V_26 , V_23 -> V_308 ) ;
F_4 ( V_151 , & V_23 -> V_93 ) ;
return;
}
F_21 ( V_23 , V_13 -> V_26 ) ;
}
static T_10 F_107 ( struct V_191 * V_10 ,
struct V_309 * V_310 ,
char * V_88 )
{
struct V_4 * V_5 = F_108 ( V_10 ) -> V_311 ;
int V_312 = 0 ;
if ( F_19 ( V_101 , & V_5 -> V_44 ) )
V_312 += sprintf ( V_88 , L_69 , L_70 ) ;
else if ( F_19 ( V_100 , & V_5 -> V_44 ) )
V_312 += sprintf ( V_88 , L_69 , L_71 ) ;
else
V_312 += sprintf ( V_88 , L_69 , L_72 ) ;
return V_312 ;
}
static T_10 F_109 ( struct V_313 * V_314 , char * V_88 )
{
int V_312 = 0 ;
struct V_4 * V_5 , * V_51 ;
unsigned long V_93 ;
char V_315 [ 42 ] ;
T_1 V_80 = 0 ;
F_110 ( & V_316 , V_93 ) ;
V_312 += sprintf ( & V_88 [ V_312 ] , L_73 ) ;
F_111 (dd, tmp, &online_list, online_list) {
if ( V_5 -> V_2 ) {
if ( V_5 -> V_23 &&
V_5 -> V_23 -> V_172 &&
V_5 -> V_23 -> V_177 ) {
F_85 ( V_315 ,
( char * ) ( V_5 -> V_23 -> V_172 + 10 ) , 21 ) ;
V_80 = * ( V_5 -> V_23 -> V_172 + 141 ) ;
} else {
memset ( V_315 , 0 , 42 ) ;
V_80 = 0 ;
}
if ( V_5 -> V_23 &&
F_19 ( V_317 , & V_5 -> V_23 -> V_93 ) ) {
V_312 += sprintf ( & V_88 [ V_312 ] ,
L_74 ,
F_112 ( & V_5 -> V_2 -> V_10 ) ,
V_315 ,
V_80 ) ;
} else {
V_312 += sprintf ( & V_88 [ V_312 ] ,
L_75 ,
F_112 ( & V_5 -> V_2 -> V_10 ) ,
V_315 ) ;
}
}
}
V_312 += sprintf ( & V_88 [ V_312 ] , L_76 ) ;
F_111 (dd, tmp, &removing_list, remove_list) {
if ( V_5 -> V_2 ) {
if ( V_5 -> V_23 &&
V_5 -> V_23 -> V_172 &&
V_5 -> V_23 -> V_177 ) {
F_85 ( V_315 ,
( char * ) ( V_5 -> V_23 -> V_172 + 10 ) , 21 ) ;
V_80 = * ( V_5 -> V_23 -> V_172 + 141 ) ;
} else {
memset ( V_315 , 0 , 42 ) ;
V_80 = 0 ;
}
if ( V_5 -> V_23 &&
F_19 ( V_317 , & V_5 -> V_23 -> V_93 ) ) {
V_312 += sprintf ( & V_88 [ V_312 ] ,
L_74 ,
F_112 ( & V_5 -> V_2 -> V_10 ) ,
V_315 ,
V_80 ) ;
} else {
V_312 += sprintf ( & V_88 [ V_312 ] ,
L_75 ,
F_112 ( & V_5 -> V_2 -> V_10 ) ,
V_315 ) ;
}
}
}
F_113 ( & V_316 , V_93 ) ;
return V_312 ;
}
static T_10 F_114 ( struct V_318 * V_319 , char T_6 * V_320 ,
T_11 V_170 , T_12 * V_321 )
{
struct V_4 * V_5 = (struct V_4 * ) V_319 -> V_311 ;
int V_312 = * V_321 ;
char * V_88 ;
int V_71 = 0 ;
if ( ! V_170 || * V_321 )
return 0 ;
V_88 = F_115 ( V_322 , V_213 ) ;
if ( ! V_88 ) {
F_32 ( & V_5 -> V_2 -> V_10 ,
L_77 ) ;
return - V_214 ;
}
V_312 += F_109 ( NULL , V_88 ) ;
* V_321 = V_312 <= V_170 ? V_312 : V_170 ;
V_312 = F_74 ( V_320 , V_88 , * V_321 ) ;
if ( V_312 )
V_71 = - V_72 ;
F_98 ( V_88 ) ;
return V_71 ? V_71 : * V_321 ;
}
static T_10 F_116 ( struct V_318 * V_319 , char T_6 * V_320 ,
T_11 V_170 , T_12 * V_321 )
{
struct V_4 * V_5 = (struct V_4 * ) V_319 -> V_311 ;
char * V_88 ;
T_2 V_323 ;
int V_312 = * V_321 ;
int V_148 , V_71 = 0 ;
if ( ! V_170 || V_312 )
return 0 ;
V_88 = F_115 ( V_322 , V_213 ) ;
if ( ! V_88 ) {
F_32 ( & V_5 -> V_2 -> V_10 ,
L_78 ) ;
return - V_214 ;
}
V_312 += sprintf ( & V_88 [ V_312 ] , L_79 ) ;
for ( V_148 = V_5 -> V_63 - 1 ; V_148 >= 0 ; V_148 -- )
V_312 += sprintf ( & V_88 [ V_312 ] , L_80 ,
F_8 ( V_5 -> V_23 -> V_48 [ V_148 ] ) ) ;
V_312 += sprintf ( & V_88 [ V_312 ] , L_81 ) ;
V_312 += sprintf ( & V_88 [ V_312 ] , L_82 ) ;
for ( V_148 = V_5 -> V_63 - 1 ; V_148 >= 0 ; V_148 -- )
V_312 += sprintf ( & V_88 [ V_312 ] , L_80 ,
F_8 ( V_5 -> V_23 -> V_49 [ V_148 ] ) ) ;
V_312 += sprintf ( & V_88 [ V_312 ] , L_81 ) ;
V_312 += sprintf ( & V_88 [ V_312 ] , L_83 ) ;
for ( V_148 = V_5 -> V_63 - 1 ; V_148 >= 0 ; V_148 -- )
V_312 += sprintf ( & V_88 [ V_312 ] , L_80 ,
F_8 ( V_5 -> V_23 -> V_64 [ V_148 ] ) ) ;
V_312 += sprintf ( & V_88 [ V_312 ] , L_81 ) ;
V_312 += sprintf ( & V_88 [ V_312 ] , L_84 ,
F_8 ( V_5 -> V_23 -> V_19 + V_65 ) ) ;
V_312 += sprintf ( & V_88 [ V_312 ] , L_85 ,
F_8 ( V_5 -> V_19 + V_66 ) ) ;
V_312 += sprintf ( & V_88 [ V_312 ] , L_86 ) ;
V_312 += sprintf ( & V_88 [ V_312 ] , L_87 ) ;
for ( V_148 = V_5 -> V_63 - 1 ; V_148 >= 0 ; V_148 -- ) {
if ( sizeof( long ) > sizeof( T_2 ) )
V_323 =
V_5 -> V_23 -> V_308 [ V_148 / 2 ] >> ( 32 * ( V_148 & 1 ) ) ;
else
V_323 = V_5 -> V_23 -> V_308 [ V_148 ] ;
V_312 += sprintf ( & V_88 [ V_312 ] , L_80 , V_323 ) ;
}
V_312 += sprintf ( & V_88 [ V_312 ] , L_81 ) ;
* V_321 = V_312 <= V_170 ? V_312 : V_170 ;
V_312 = F_74 ( V_320 , V_88 , * V_321 ) ;
if ( V_312 )
V_71 = - V_72 ;
F_98 ( V_88 ) ;
return V_71 ? V_71 : * V_321 ;
}
static T_10 F_117 ( struct V_318 * V_319 , char T_6 * V_320 ,
T_11 V_170 , T_12 * V_321 )
{
struct V_4 * V_5 = (struct V_4 * ) V_319 -> V_311 ;
char * V_88 ;
int V_312 = * V_321 ;
int V_71 = 0 ;
if ( ! V_170 || V_312 )
return 0 ;
V_88 = F_115 ( V_322 , V_213 ) ;
if ( ! V_88 ) {
F_32 ( & V_5 -> V_2 -> V_10 ,
L_88 ) ;
return - V_214 ;
}
V_312 += sprintf ( & V_88 [ V_312 ] , L_89 ,
V_5 -> V_23 -> V_93 ) ;
V_312 += sprintf ( & V_88 [ V_312 ] , L_90 ,
V_5 -> V_44 ) ;
* V_321 = V_312 <= V_170 ? V_312 : V_170 ;
V_312 = F_74 ( V_320 , V_88 , * V_321 ) ;
if ( V_312 )
V_71 = - V_72 ;
F_98 ( V_88 ) ;
return V_71 ? V_71 : * V_321 ;
}
static int F_118 ( struct V_4 * V_5 , struct V_324 * V_325 )
{
if ( ! V_325 || ! V_5 )
return - V_199 ;
if ( F_119 ( V_325 , & V_326 . V_310 ) )
F_5 ( & V_5 -> V_2 -> V_10 ,
L_91 ) ;
return 0 ;
}
static int F_120 ( struct V_4 * V_5 , struct V_324 * V_325 )
{
if ( ! V_325 || ! V_5 )
return - V_199 ;
F_121 ( V_325 , & V_326 . V_310 ) ;
return 0 ;
}
static int F_122 ( struct V_4 * V_5 )
{
if ( ! V_327 )
return - 1 ;
V_5 -> V_328 = F_123 ( V_5 -> V_329 -> V_330 , V_327 ) ;
if ( F_124 ( V_5 -> V_328 ) ) {
F_5 ( & V_5 -> V_2 -> V_10 ,
L_92 ,
V_5 -> V_329 -> V_330 ) ;
V_5 -> V_328 = NULL ;
return - 1 ;
}
F_125 ( L_93 , V_331 , V_5 -> V_328 , V_5 ,
& V_332 ) ;
F_125 ( L_94 , V_331 , V_5 -> V_328 , V_5 ,
& V_333 ) ;
return 0 ;
}
static void F_126 ( struct V_4 * V_5 )
{
if ( V_5 -> V_328 )
F_127 ( V_5 -> V_328 ) ;
}
static inline void F_128 ( struct V_4 * V_5 )
{
T_2 V_334 ;
V_334 = F_8 ( V_5 -> V_19 + V_335 ) ;
F_16 ( V_334 |
V_336 |
V_337 ,
V_5 -> V_19 + V_335 ) ;
}
static int F_129 ( struct V_4 * V_5 )
{
return ( V_5 -> V_2 -> V_191 == V_338 ? 1 : 0 ) ;
}
static void F_130 ( struct V_4 * V_5 )
{
T_2 V_334 ;
unsigned int V_339 , V_340 ;
V_334 = F_8 ( V_5 -> V_19 + V_335 ) ;
V_5 -> V_341 = V_342 ;
V_5 -> V_63 = 1 ;
if ( V_334 & 0x8 ) {
V_5 -> V_341 = V_343 ;
V_339 = ( V_334 & V_344 ) >> 8 ;
V_340 = ( V_334 & V_345 ) + 1 ;
F_41 ( & V_5 -> V_2 -> V_10 ,
L_95
L_96 ,
V_339 ,
V_340 ,
V_340 * 32 ) ;
if ( V_340 > V_126 ) {
F_5 ( & V_5 -> V_2 -> V_10 ,
L_97
L_98 , V_126 ) ;
V_340 = V_126 ;
}
V_5 -> V_63 = V_340 ;
return;
}
F_5 ( & V_5 -> V_2 -> V_10 , L_99 ) ;
}
static int F_131 ( struct V_4 * V_5 )
{
unsigned long V_39 , V_76 = 0 , V_161 ;
F_5 ( & V_5 -> V_2 -> V_10 ,
L_100 ) ;
V_161 = V_42 ;
V_39 = V_42 + F_17 ( V_346 ) ;
do {
if ( F_44 ( F_19 ( V_43 ,
& V_5 -> V_44 ) ) )
return - V_72 ;
if ( F_1 ( V_5 -> V_2 ) )
return - V_72 ;
if ( F_70 ( V_5 -> V_23 , NULL ) < 0 )
return - V_72 ;
if ( * ( V_5 -> V_23 -> V_172 + V_347 ) ==
V_348 ) {
F_132 ( 1 ) ;
if ( V_76 ++ >= 180 ) {
F_5 ( & V_5 -> V_2 -> V_10 ,
L_101 ,
F_66 ( V_42 - V_161 ) / 1000 ) ;
V_76 = 0 ;
}
} else {
F_5 ( & V_5 -> V_2 -> V_10 ,
L_102 ,
F_66 ( V_42 - V_161 ) / 1000 ) ;
F_133 ( V_5 ) ;
return 0 ;
}
} while ( F_20 ( V_42 , V_39 ) );
F_32 ( & V_5 -> V_2 -> V_10 ,
L_103 ,
F_66 ( V_42 - V_161 ) / 1000 ) ;
return - V_72 ;
}
static void F_134 ( struct V_12 * V_13 )
{
struct V_16 * V_17 = F_7 ( V_13 ) ;
struct V_4 * V_5 = V_13 -> V_14 -> V_15 ;
F_135 ( & V_5 -> V_2 -> V_10 , V_17 -> V_230 , V_17 -> V_298 ,
V_17 -> V_306 ) ;
if ( F_44 ( V_17 -> V_303 ) )
F_136 ( & V_5 -> V_23 -> V_349 ) ;
F_137 ( V_13 , V_17 -> V_80 ) ;
}
static void F_138 ( struct V_12 * V_81 , void * V_117 ,
bool V_350 )
{
struct V_16 * V_17 = F_7 ( V_81 ) ;
struct V_4 * V_5 = V_117 ;
F_39 ( V_95 L_104 , V_81 -> V_26 ) ;
F_57 ( V_81 -> V_26 , V_5 -> V_23 -> V_308 ) ;
V_17 -> V_80 = - V_96 ;
F_134 ( V_81 ) ;
}
static void F_139 ( struct V_12 * V_81 , void * V_117 ,
bool V_350 )
{
struct V_4 * V_5 = V_117 ;
F_4 ( V_81 -> V_26 , V_5 -> V_23 -> V_308 ) ;
F_140 ( V_81 ) ;
}
static int F_141 ( void * V_117 )
{
struct V_4 * V_5 = (struct V_4 * ) V_117 ;
unsigned long V_351 , V_352 , V_353 , V_149 ;
unsigned int V_354 = V_5 -> V_63 * 32 ;
struct V_45 * V_23 = V_5 -> V_23 ;
while ( 1 ) {
if ( F_142 () ||
F_19 ( V_355 , & V_23 -> V_93 ) )
goto V_356;
F_57 ( V_150 , & V_23 -> V_93 ) ;
F_143 ( V_23 -> V_116 , ( V_23 -> V_93 ) &&
( V_23 -> V_93 & V_357 ) ) ;
if ( F_142 () ||
F_19 ( V_355 , & V_23 -> V_93 ) )
goto V_356;
if ( F_44 ( F_19 ( V_43 ,
& V_5 -> V_44 ) ) )
goto V_356;
F_4 ( V_150 , & V_23 -> V_93 ) ;
V_358:
if ( F_19 ( V_115 , & V_23 -> V_93 ) ) {
F_38 ( V_5 ) ;
F_57 ( V_115 , & V_23 -> V_93 ) ;
}
if ( F_19 ( V_115 , & V_23 -> V_93 ) )
goto V_358;
if ( F_19 ( V_359 , & V_23 -> V_93 ) ) {
V_149 = V_42 + F_17 ( 5000 ) ;
do {
F_18 ( 100 ) ;
} while ( F_51 ( & V_5 -> V_108 ) != 0 &&
F_20 ( V_42 , V_149 ) );
if ( F_51 ( & V_5 -> V_108 ) != 0 )
F_5 ( & V_5 -> V_2 -> V_10 ,
L_105 ) ;
F_22 ( V_5 -> V_7 -> V_360 ) ;
F_144 ( & V_5 -> V_38 ,
F_139 , V_5 ) ;
F_25 ( V_5 -> V_7 -> V_360 ) ;
F_4 ( V_151 , & V_5 -> V_23 -> V_93 ) ;
if ( F_33 ( V_5 ) )
F_144 ( & V_5 -> V_38 ,
F_138 , V_5 ) ;
F_57 ( V_359 , & V_5 -> V_23 -> V_93 ) ;
}
if ( F_19 ( V_151 , & V_23 -> V_93 ) ) {
V_351 = 1 ;
V_352 = V_354 ;
V_353 = 0 ;
while ( 1 ) {
V_351 = F_145 ( V_23 -> V_308 ,
V_354 , V_351 ) ;
if ( V_353 == 1 ) {
if ( ( V_352 >= V_351 ) ||
( V_351 >= V_354 ) )
break;
}
if ( F_44 ( V_352 == V_354 ) )
V_352 = V_351 ;
if ( F_44 ( V_351 == V_354 ) ) {
V_351 = 1 ;
V_353 = 1 ;
continue;
}
F_21 ( V_23 , V_351 ) ;
F_57 ( V_351 , V_23 -> V_308 ) ;
}
F_57 ( V_151 , & V_23 -> V_93 ) ;
}
if ( F_19 ( V_317 , & V_23 -> V_93 ) ) {
if ( F_131 ( V_5 ) == 0 )
F_57 ( V_317 , & V_23 -> V_93 ) ;
}
}
V_356:
return 0 ;
}
static void F_146 ( struct V_4 * V_5 )
{
struct V_45 * V_23 = V_5 -> V_23 ;
if ( V_23 -> V_361 )
F_82 ( & V_5 -> V_2 -> V_10 , V_362 ,
V_23 -> V_361 , V_23 -> V_363 ) ;
if ( V_23 -> V_24 ) {
F_82 ( & V_5 -> V_2 -> V_10 , V_364 ,
V_23 -> V_24 , V_23 -> V_28 ) ;
}
}
static int F_147 ( struct V_4 * V_5 )
{
struct V_45 * V_23 = V_5 -> V_23 ;
V_23 -> V_361 =
F_80 ( & V_5 -> V_2 -> V_10 , V_362 ,
& V_23 -> V_363 , V_213 ) ;
if ( ! V_23 -> V_361 )
return - V_214 ;
memset ( V_23 -> V_361 , 0 , V_362 ) ;
V_23 -> V_24 =
F_80 ( & V_5 -> V_2 -> V_10 , V_364 ,
& V_23 -> V_28 , V_213 ) ;
if ( ! V_23 -> V_24 ) {
F_82 ( & V_5 -> V_2 -> V_10 , V_362 ,
V_23 -> V_361 , V_23 -> V_363 ) ;
V_23 -> V_361 = NULL ;
V_23 -> V_363 = 0 ;
return - V_214 ;
}
memset ( V_23 -> V_24 , 0 , V_364 ) ;
V_23 -> V_136 = V_23 -> V_361 + V_365 ;
V_23 -> V_58 = V_23 -> V_363 + V_365 ;
V_23 -> V_172 = V_23 -> V_361 + V_366 ;
V_23 -> V_179 = V_23 -> V_363 + V_366 ;
V_23 -> V_98 = V_23 -> V_361 + V_367 ;
V_23 -> V_99 = V_23 -> V_363 + V_367 ;
V_23 -> V_201 = V_23 -> V_361 + V_368 ;
V_23 -> V_202 = V_23 -> V_363 + V_368 ;
return 0 ;
}
static int F_148 ( struct V_4 * V_5 )
{
struct V_196 V_369 ;
unsigned char * V_88 ;
int V_71 ;
if ( F_70 ( V_5 -> V_23 , NULL ) < 0 )
return - V_72 ;
if ( * ( V_5 -> V_23 -> V_172 + V_347 ) ==
V_348 ) {
F_4 ( V_317 , & V_5 -> V_23 -> V_93 ) ;
return V_348 ;
}
F_84 ( V_5 -> V_23 ) ;
V_71 = F_40 ( V_5 -> V_23 , V_97 ,
V_5 -> V_23 -> V_98 ,
V_5 -> V_23 -> V_99 , 1 ) ;
if ( V_71 ) {
F_5 ( & V_5 -> V_2 -> V_10 ,
L_12 ) ;
} else {
V_88 = ( unsigned char * ) V_5 -> V_23 -> V_98 ;
if ( V_88 [ 259 ] & 0x1 ) {
F_41 ( & V_5 -> V_2 -> V_10 ,
L_13 ) ;
F_4 ( V_100 , & V_5 -> V_44 ) ;
}
if ( V_88 [ 288 ] == 0xF7 ) {
F_41 ( & V_5 -> V_2 -> V_10 ,
L_15 ) ;
F_4 ( V_101 , & V_5 -> V_44 ) ;
}
if ( V_88 [ 288 ] == 0xBF ) {
F_41 ( & V_5 -> V_2 -> V_10 ,
L_106 ) ;
F_4 ( V_102 , & V_5 -> V_44 ) ;
}
}
memset ( & V_369 , 0 , sizeof( struct V_196 ) ) ;
if ( F_77 ( V_5 -> V_23 , 242 , & V_369 ) )
F_5 ( & V_5 -> V_2 -> V_10 ,
L_107 ) ;
else
F_41 ( & V_5 -> V_2 -> V_10 ,
L_108 ,
V_369 . V_370 , F_149 ( V_369 . V_117 ) ) ;
return V_71 ;
}
static int F_150 ( struct V_4 * V_5 )
{
int V_56 ;
int V_71 ;
unsigned int V_371 ;
unsigned long V_39 , V_372 ;
V_5 -> V_19 = F_151 ( V_5 -> V_2 ) [ V_373 ] ;
F_130 ( V_5 ) ;
if ( V_5 -> V_341 == V_342 ) {
V_71 = - V_96 ;
goto V_374;
}
V_371 = V_5 -> V_63 * 32 ;
F_128 ( V_5 ) ;
V_5 -> V_23 = F_152 ( sizeof( struct V_45 ) , V_213 ,
V_5 -> V_375 ) ;
if ( ! V_5 -> V_23 ) {
F_32 ( & V_5 -> V_2 -> V_10 ,
L_109 ) ;
return - V_214 ;
}
for ( V_56 = 0 ; V_56 < V_126 ; V_56 ++ )
V_5 -> V_127 [ V_56 ] . V_23 = V_5 -> V_23 ;
if ( F_129 ( V_5 ) )
V_5 -> V_376 = V_377 ;
else
V_5 -> V_376 = 0 ;
F_153 ( & V_5 -> V_23 -> V_349 , V_5 -> V_376 ) ;
for ( V_56 = 0 ; V_56 < V_126 ; V_56 ++ )
F_154 ( & V_5 -> V_23 -> V_47 [ V_56 ] ) ;
V_5 -> V_23 -> V_19 = V_5 -> V_19 + V_378 ;
V_5 -> V_23 -> V_5 = V_5 ;
V_71 = F_147 ( V_5 ) ;
if ( V_71 < 0 )
goto V_374;
for ( V_56 = 0 ; V_56 < V_5 -> V_63 ; V_56 ++ ) {
V_5 -> V_23 -> V_48 [ V_56 ] =
V_5 -> V_23 -> V_19 + V_56 * 0x80 + V_379 ;
V_5 -> V_23 -> V_49 [ V_56 ] =
V_5 -> V_23 -> V_19 + V_56 * 0x80 + V_380 ;
V_5 -> V_23 -> V_64 [ V_56 ] =
V_5 -> V_23 -> V_19 + V_56 * 0x80 + V_381 ;
}
V_372 = V_42 ;
V_39 = V_42 + F_17 ( 30000 ) ;
while ( ( ( F_8 ( V_5 -> V_23 -> V_19 + V_70 ) & 0x0F ) != 0x03 ) &&
F_20 ( V_42 , V_39 ) ) {
F_18 ( 100 ) ;
}
if ( F_44 ( F_1 ( V_5 -> V_2 ) ) ) {
V_372 = V_42 - V_372 ;
F_5 ( & V_5 -> V_2 -> V_10 ,
L_110 ,
F_66 ( V_372 ) ) ;
V_71 = - V_382 ;
goto V_383 ;
}
if ( F_44 ( F_19 ( V_43 , & V_5 -> V_44 ) ) ) {
V_372 = V_42 - V_372 ;
F_5 ( & V_5 -> V_2 -> V_10 ,
L_111 ,
F_66 ( V_372 ) ) ;
V_71 = - V_72 ;
goto V_383;
}
if ( ! ( F_8 ( V_5 -> V_19 + V_20 ) & V_384 ) ) {
if ( F_15 ( V_5 ) < 0 ) {
F_32 ( & V_5 -> V_2 -> V_10 ,
L_112 ) ;
V_71 = - V_96 ;
goto V_383;
}
} else {
F_16 ( F_8 ( V_5 -> V_19 + V_66 ) ,
V_5 -> V_19 + V_66 ) ;
}
F_30 ( V_5 -> V_23 ) ;
F_28 ( V_5 -> V_23 ) ;
V_71 = F_155 ( & V_5 -> V_2 -> V_10 ,
V_5 -> V_2 -> V_132 ,
F_54 ,
V_385 ,
F_156 ( & V_5 -> V_2 -> V_10 ) ,
V_5 ) ;
if ( V_71 ) {
F_32 ( & V_5 -> V_2 -> V_10 ,
L_113 , V_5 -> V_2 -> V_132 ) ;
goto V_383;
}
F_157 ( V_5 -> V_2 -> V_132 , F_158 ( V_5 -> V_386 ) ) ;
F_16 ( F_8 ( V_5 -> V_19 + V_41 ) | V_73 ,
V_5 -> V_19 + V_41 ) ;
F_159 ( & V_5 -> V_23 -> V_116 ) ;
if ( F_19 ( V_43 , & V_5 -> V_44 ) ) {
V_71 = - V_72 ;
goto V_387;
}
return V_71 ;
V_387:
F_16 ( F_8 ( V_5 -> V_19 + V_41 ) & ~ V_73 ,
V_5 -> V_19 + V_41 ) ;
F_157 ( V_5 -> V_2 -> V_132 , NULL ) ;
F_160 ( & V_5 -> V_2 -> V_10 , V_5 -> V_2 -> V_132 , V_5 ) ;
V_383:
F_29 ( V_5 -> V_23 ) ;
F_146 ( V_5 ) ;
V_374:
F_98 ( V_5 -> V_23 ) ;
return V_71 ;
}
static int F_161 ( struct V_4 * V_5 )
{
int V_71 = 0 ;
if ( V_5 -> V_6 || ! V_5 -> V_23 )
return - V_382 ;
if ( ! F_19 ( V_317 , & V_5 -> V_23 -> V_93 ) &&
! F_19 ( V_102 , & V_5 -> V_44 ) &&
! F_19 ( V_145 , & V_5 -> V_44 ) ) {
V_71 = F_75 ( V_5 -> V_23 ) ;
if ( V_71 )
F_5 ( & V_5 -> V_2 -> V_10 ,
L_114 ) ;
}
return V_71 ;
}
static int F_162 ( struct V_4 * V_5 )
{
if ( ! V_5 -> V_6 ) {
F_29 ( V_5 -> V_23 ) ;
F_16 ( F_8 ( V_5 -> V_19 + V_41 ) & ~ V_73 ,
V_5 -> V_19 + V_41 ) ;
}
F_157 ( V_5 -> V_2 -> V_132 , NULL ) ;
F_160 ( & V_5 -> V_2 -> V_10 , V_5 -> V_2 -> V_132 , V_5 ) ;
F_61 ( 1000 ) ;
F_146 ( V_5 ) ;
F_98 ( V_5 -> V_23 ) ;
V_5 -> V_23 = NULL ;
return 0 ;
}
static int F_163 ( struct V_4 * V_5 )
{
F_161 ( V_5 ) ;
return 0 ;
}
static int F_164 ( struct V_4 * V_5 )
{
if ( F_161 ( V_5 ) != 0 ) {
F_32 ( & V_5 -> V_2 -> V_10 ,
L_115 ) ;
return - V_72 ;
}
F_16 ( F_8 ( V_5 -> V_19 + V_41 ) & ~ V_73 ,
V_5 -> V_19 + V_41 ) ;
F_29 ( V_5 -> V_23 ) ;
return 0 ;
}
static int F_165 ( struct V_4 * V_5 )
{
F_128 ( V_5 ) ;
if ( F_15 ( V_5 ) != 0 ) {
F_32 ( & V_5 -> V_2 -> V_10 ,
L_116 ) ;
return - V_72 ;
}
F_30 ( V_5 -> V_23 ) ;
F_28 ( V_5 -> V_23 ) ;
F_16 ( F_8 ( V_5 -> V_19 + V_41 ) | V_73 ,
V_5 -> V_19 + V_41 ) ;
return 0 ;
}
static int F_166 ( char * V_388 ,
int V_389 ,
char * V_88 ,
int V_390 )
{
const int V_391 = 'z' - 'a' + 1 ;
char * V_392 = V_88 + strlen ( V_388 ) ;
char * V_393 = V_88 + V_390 ;
char * V_394 ;
int V_395 ;
V_394 = V_393 - 1 ;
* V_394 = '\0' ;
V_395 = V_391 ;
do {
if ( V_394 == V_392 )
return - V_199 ;
* -- V_394 = 'a' + ( V_389 % V_395 ) ;
V_389 = ( V_389 / V_395 ) - 1 ;
} while ( V_389 >= 0 );
memmove ( V_392 , V_394 , V_393 - V_394 ) ;
memcpy ( V_88 , V_388 , strlen ( V_388 ) ) ;
return 0 ;
}
static int F_167 ( struct V_396 * V_10 ,
T_13 V_397 ,
unsigned V_17 ,
unsigned long V_289 )
{
struct V_4 * V_5 = V_10 -> V_398 -> V_311 ;
if ( ! F_168 ( V_399 ) )
return - V_400 ;
if ( ! V_5 )
return - V_401 ;
if ( F_44 ( F_19 ( V_43 , & V_5 -> V_44 ) ) )
return - V_401 ;
switch ( V_17 ) {
case V_402 :
return - V_401 ;
default:
return F_99 ( V_5 , V_17 , V_289 ) ;
}
}
static int F_169 ( struct V_396 * V_10 ,
T_13 V_397 ,
unsigned V_17 ,
unsigned long V_289 )
{
struct V_4 * V_5 = V_10 -> V_398 -> V_311 ;
if ( ! F_168 ( V_399 ) )
return - V_400 ;
if ( ! V_5 )
return - V_401 ;
if ( F_44 ( F_19 ( V_43 , & V_5 -> V_44 ) ) )
return - V_401 ;
switch ( V_17 ) {
case V_402 :
return - V_401 ;
case V_294 : {
struct V_403 T_6 * V_404 ;
T_9 V_254 ;
int V_405 , V_255 , V_295 ;
V_405 =
sizeof( struct V_403 ) ;
V_404 =
(struct V_403 T_6 * ) V_289 ;
if ( F_100 ( & V_254 , ( void T_6 * ) V_289 ,
V_405 - ( 2 * sizeof( V_406 ) ) ) )
return - V_72 ;
if ( F_170 ( V_254 . V_268 , & V_404 -> V_268 ) )
return - V_72 ;
if ( F_170 ( V_254 . V_269 , & V_404 -> V_269 ) )
return - V_72 ;
V_255 = sizeof( struct V_403 ) ;
V_295 = F_92 ( V_5 , ( void T_6 * ) V_289 ,
& V_254 , V_255 ) ;
if ( F_74 ( ( void T_6 * ) V_289 , & V_254 ,
V_405 -
( 2 * sizeof( V_406 ) ) ) )
return - V_72 ;
if ( F_171 ( V_254 . V_268 , & V_404 -> V_268 ) )
return - V_72 ;
if ( F_171 ( V_254 . V_269 , & V_404 -> V_269 ) )
return - V_72 ;
return V_295 ;
}
default:
return F_99 ( V_5 , V_17 , V_289 ) ;
}
}
static int F_172 ( struct V_396 * V_10 ,
struct V_407 * V_408 )
{
struct V_4 * V_5 = V_10 -> V_398 -> V_311 ;
T_8 V_409 ;
if ( ! V_5 )
return - V_401 ;
if ( ! ( F_83 ( V_5 , & V_409 ) ) ) {
F_5 ( & V_5 -> V_2 -> V_10 ,
L_117 ) ;
return - V_401 ;
}
V_408 -> V_410 = 224 ;
V_408 -> V_185 = 56 ;
F_173 ( V_409 , ( V_408 -> V_410 * V_408 -> V_185 ) ) ;
V_408 -> V_411 = V_409 ;
return 0 ;
}
static int F_174 ( struct V_396 * V_10 , T_13 V_397 )
{
struct V_4 * V_5 ;
if ( V_10 && V_10 -> V_398 ) {
V_5 = (struct V_4 * ) V_10 -> V_398 -> V_311 ;
if ( V_5 ) {
if ( F_19 ( V_412 ,
& V_5 -> V_44 ) ) {
return - V_382 ;
}
return 0 ;
}
}
return - V_382 ;
}
static void F_175 ( struct V_413 * V_329 , T_13 V_397 )
{
}
static inline bool F_176 ( struct V_4 * V_5 )
{
if ( F_44 ( F_19 ( V_146 , & V_5 -> V_23 -> V_93 ) ) ) {
if ( V_5 -> V_23 -> V_140 ) {
unsigned long V_149 = V_5 -> V_23 -> V_140 +
F_17 ( 1000 ) ;
if ( F_177 ( V_42 , V_149 ) ) {
F_57 ( V_146 ,
& V_5 -> V_23 -> V_93 ) ;
F_57 ( V_145 , & V_5 -> V_44 ) ;
V_5 -> V_23 -> V_140 = 0 ;
F_49 ( & V_5 -> V_23 -> V_116 ) ;
return false ;
}
}
return true ;
}
return false ;
}
static int F_178 ( struct V_35 * V_36 , struct V_12 * V_13 )
{
struct V_4 * V_5 = V_36 -> V_7 -> V_15 ;
struct V_16 * V_17 = F_7 ( V_13 ) ;
unsigned int V_225 ;
if ( F_176 ( V_5 ) )
return - V_106 ;
if ( F_44 ( V_5 -> V_44 & V_414 ) ) {
if ( F_44 ( F_19 ( V_43 ,
& V_5 -> V_44 ) ) ) {
return - V_168 ;
}
if ( F_44 ( F_19 ( V_101 , & V_5 -> V_44 ) ) ) {
return - V_106 ;
}
if ( F_44 ( F_19 ( V_100 ,
& V_5 -> V_44 ) &&
F_102 ( V_13 ) ) ) {
return - V_106 ;
}
if ( F_44 ( F_19 ( V_145 , & V_5 -> V_44 ) ||
F_19 ( V_102 , & V_5 -> V_44 ) ) )
return - V_106 ;
}
if ( F_179 ( V_13 ) == V_415 ) {
int V_261 ;
V_261 = F_78 ( V_5 , F_103 ( V_13 ) , F_104 ( V_13 ) ) ;
F_137 ( V_13 , V_261 ) ;
return 0 ;
}
V_225 = F_180 ( V_36 -> V_7 , V_13 , V_17 -> V_230 ) ;
F_101 ( V_5 , V_13 , V_17 , V_225 , V_36 ) ;
return 0 ;
}
static bool F_181 ( struct V_35 * V_36 ,
struct V_12 * V_13 )
{
struct V_4 * V_5 = V_36 -> V_7 -> V_15 ;
struct V_16 * V_17 = F_7 ( V_13 ) ;
if ( F_102 ( V_13 ) == V_297 || ! V_5 -> V_376 )
return false ;
if ( F_104 ( V_13 ) <= 64 ) {
if ( ( F_103 ( V_13 ) & 7 ) || ( F_104 ( V_13 ) & 7 ) )
V_17 -> V_303 = 1 ;
}
if ( V_17 -> V_303 && F_182 ( & V_5 -> V_23 -> V_349 ) )
return true ;
return false ;
}
static int F_183 ( struct V_35 * V_36 ,
struct V_12 * V_13 )
{
struct V_4 * V_5 = V_36 -> V_7 -> V_15 ;
struct V_159 * V_160 = V_13 -> V_162 ;
struct V_16 * V_17 = F_7 ( V_13 ) ;
struct V_227 * V_228 ;
if ( F_58 ( V_5 -> V_23 ) )
return V_416 ;
V_17 -> V_22 -> V_157 =
V_30 F_9 ( V_160 -> V_157 | V_160 -> V_154 ) ;
if ( V_160 -> V_156 ) {
V_228 = V_17 -> V_103 + V_231 ;
V_228 -> V_232 =
V_30 F_9 ( ( V_160 -> V_156 - 1 ) & 0x3FFFFF ) ;
V_228 -> V_233 =
V_30 F_9 ( V_160 -> V_155 & 0xFFFFFFFF ) ;
V_228 -> V_234 =
V_30 F_9 ( ( V_160 -> V_155 >> 16 ) >> 16 ) ;
V_17 -> V_22 -> V_157 |=
V_30 F_9 ( ( 1 << 16 ) ) ;
}
V_17 -> V_22 -> V_305 = 0 ;
F_184 ( V_13 ) ;
F_55 ( V_5 -> V_23 , V_13 -> V_26 ) ;
return V_417 ;
}
static int F_185 ( struct V_35 * V_36 ,
const struct V_418 * V_419 )
{
struct V_12 * V_13 = V_419 -> V_13 ;
int V_295 ;
F_6 ( V_13 ) ;
if ( F_186 ( V_13 ) )
return F_183 ( V_36 , V_13 ) ;
if ( F_44 ( F_181 ( V_36 , V_13 ) ) )
return V_416 ;
F_184 ( V_13 ) ;
V_295 = F_178 ( V_36 , V_13 ) ;
if ( F_48 ( ! V_295 ) )
return V_417 ;
return V_420 ;
}
static void F_187 ( struct V_421 * V_422 , struct V_12 * V_13 ,
unsigned int V_423 )
{
struct V_4 * V_5 = V_422 -> V_4 ;
struct V_16 * V_17 = F_7 ( V_13 ) ;
if ( ! V_17 -> V_103 )
return;
F_82 ( & V_5 -> V_2 -> V_10 , V_424 ,
V_17 -> V_103 , V_17 -> V_31 ) ;
}
static int F_188 ( struct V_421 * V_422 , struct V_12 * V_13 ,
unsigned int V_423 , unsigned int V_375 )
{
struct V_4 * V_5 = V_422 -> V_4 ;
struct V_16 * V_17 = F_7 ( V_13 ) ;
V_17 -> V_103 = F_80 ( & V_5 -> V_2 -> V_10 , V_424 ,
& V_17 -> V_31 , V_213 ) ;
if ( ! V_17 -> V_103 )
return - V_214 ;
memset ( V_17 -> V_103 , 0 , V_424 ) ;
F_189 ( V_17 -> V_230 , V_425 ) ;
return 0 ;
}
static enum V_426 F_190 ( struct V_12 * V_81 ,
bool V_350 )
{
struct V_4 * V_5 = V_81 -> V_14 -> V_15 ;
if ( V_350 ) {
struct V_16 * V_17 = F_7 ( V_81 ) ;
V_17 -> V_80 = - V_427 ;
return V_428 ;
}
if ( F_19 ( V_81 -> V_26 , V_5 -> V_23 -> V_308 ) )
goto V_429;
if ( F_191 ( V_359 , & V_5 -> V_23 -> V_93 ) )
goto V_429;
F_49 ( & V_5 -> V_23 -> V_116 ) ;
V_429:
return V_430 ;
}
static int F_133 ( struct V_4 * V_5 )
{
int V_71 = 0 , V_431 = 0 ;
T_8 V_409 ;
unsigned int V_389 = 0 ;
struct V_324 * V_325 ;
if ( V_5 -> V_329 )
goto V_432;
if ( F_150 ( V_5 ) ) {
V_71 = - V_199 ;
goto V_433;
}
V_5 -> V_329 = F_192 ( V_434 , V_5 -> V_375 ) ;
if ( V_5 -> V_329 == NULL ) {
F_32 ( & V_5 -> V_2 -> V_10 ,
L_118 ) ;
V_71 = - V_199 ;
goto V_435;
}
do {
if ( ! F_193 ( & V_436 , V_213 ) ) {
V_71 = - V_214 ;
goto V_437;
}
F_22 ( & V_438 ) ;
V_71 = F_194 ( & V_436 , & V_389 ) ;
F_25 ( & V_438 ) ;
} while ( V_71 == - V_169 );
if ( V_71 )
goto V_437;
V_71 = F_166 ( L_119 ,
V_389 ,
V_5 -> V_329 -> V_330 ,
V_439 ) ;
if ( V_71 )
goto V_440;
V_5 -> V_329 -> V_441 = V_5 -> V_441 ;
V_5 -> V_329 -> V_442 = V_389 * V_434 ;
V_5 -> V_329 -> V_443 = V_434 ;
V_5 -> V_329 -> V_444 = & V_445 ;
V_5 -> V_329 -> V_311 = V_5 ;
V_5 -> V_389 = V_389 ;
F_122 ( V_5 ) ;
memset ( & V_5 -> V_38 , 0 , sizeof( V_5 -> V_38 ) ) ;
V_5 -> V_38 . V_446 = & V_447 ;
V_5 -> V_38 . V_448 = 1 ;
V_5 -> V_38 . V_449 = V_450 ;
V_5 -> V_38 . V_451 = 1 ;
V_5 -> V_38 . V_452 = sizeof( struct V_16 ) ;
V_5 -> V_38 . V_375 = V_5 -> V_375 ;
V_5 -> V_38 . V_93 = V_453 ;
V_5 -> V_38 . V_4 = V_5 ;
V_5 -> V_38 . V_39 = V_454 ;
V_71 = F_195 ( & V_5 -> V_38 ) ;
if ( V_71 ) {
F_32 ( & V_5 -> V_2 -> V_10 ,
L_120 ) ;
goto V_455;
}
V_5 -> V_7 = F_196 ( & V_5 -> V_38 ) ;
if ( F_12 ( V_5 -> V_7 ) ) {
F_32 ( & V_5 -> V_2 -> V_10 ,
L_120 ) ;
V_71 = - V_214 ;
goto V_456;
}
V_5 -> V_329 -> V_7 = V_5 -> V_7 ;
V_5 -> V_7 -> V_15 = V_5 ;
V_432:
V_431 = F_148 ( V_5 ) ;
if ( V_431 < 0 ) {
F_32 ( & V_5 -> V_2 -> V_10 ,
L_121 ) ;
V_71 = - V_199 ;
goto V_457;
}
if ( V_431 == V_348 )
goto V_458;
F_4 ( V_459 , & V_5 -> V_7 -> V_9 ) ;
F_57 ( V_460 , & V_5 -> V_7 -> V_9 ) ;
F_197 ( V_5 -> V_7 , V_425 ) ;
F_198 ( V_5 -> V_7 , 4096 ) ;
F_199 ( V_5 -> V_7 , 0xffff ) ;
F_200 ( V_5 -> V_7 , 0x400000 ) ;
F_201 ( V_5 -> V_7 , 4096 ) ;
F_202 ( V_5 -> V_7 , V_5 -> V_2 -> V_461 ) ;
if ( V_5 -> V_182 == true ) {
F_4 ( V_462 , & V_5 -> V_7 -> V_9 ) ;
V_5 -> V_7 -> V_463 . V_464 = 4096 ;
F_203 ( V_5 -> V_7 ,
V_210 * V_211 ) ;
}
if ( ! ( F_83 ( V_5 , & V_409 ) ) ) {
F_5 ( & V_5 -> V_2 -> V_10 ,
L_122 ) ;
V_71 = - V_96 ;
goto V_465;
}
F_204 ( V_5 -> V_329 , V_409 ) ;
F_205 ( & V_5 -> V_2 -> V_10 , V_5 -> V_329 ) ;
V_5 -> V_466 = F_206 ( V_5 -> V_329 , 0 ) ;
V_325 = F_207 ( & F_208 ( V_5 -> V_329 ) -> V_325 ) ;
if ( V_325 ) {
F_118 ( V_5 , V_325 ) ;
F_209 ( V_325 ) ;
}
if ( V_5 -> V_467 ) {
F_4 ( V_468 , & V_5 -> V_44 ) ;
return V_71 ;
}
V_458:
V_5 -> V_467 = F_210 ( F_141 ,
V_5 , V_5 -> V_375 ,
L_123 , V_389 ) ;
if ( F_12 ( V_5 -> V_467 ) ) {
F_32 ( & V_5 -> V_2 -> V_10 , L_124 ) ;
V_5 -> V_467 = NULL ;
V_71 = - V_72 ;
goto V_469;
}
F_211 ( V_5 -> V_467 ) ;
if ( V_431 == V_348 )
V_71 = V_431 ;
return V_71 ;
V_469:
F_212 ( V_5 -> V_466 ) ;
V_5 -> V_466 = NULL ;
F_213 ( V_5 -> V_329 ) ;
V_465:
V_457:
F_214 ( V_5 -> V_7 ) ;
V_456:
F_215 ( & V_5 -> V_38 ) ;
V_455:
F_126 ( V_5 ) ;
V_440:
F_22 ( & V_438 ) ;
F_216 ( & V_436 , V_389 ) ;
F_25 ( & V_438 ) ;
V_437:
F_217 ( V_5 -> V_329 ) ;
V_435:
F_162 ( V_5 ) ;
V_433:
return V_71 ;
}
static void F_218 ( struct V_12 * V_13 , void * V_117 , bool V_470 )
{
struct V_16 * V_17 = F_7 ( V_13 ) ;
V_17 -> V_80 = - V_382 ;
F_37 ( V_13 ) ;
}
static int F_219 ( struct V_4 * V_5 )
{
struct V_324 * V_325 ;
F_126 ( V_5 ) ;
if ( V_5 -> V_467 ) {
F_4 ( V_355 , & V_5 -> V_23 -> V_93 ) ;
F_49 ( & V_5 -> V_23 -> V_116 ) ;
F_220 ( V_5 -> V_467 ) ;
}
if ( F_19 ( V_468 , & V_5 -> V_44 ) ) {
V_325 = F_207 ( & F_208 ( V_5 -> V_329 ) -> V_325 ) ;
if ( V_325 ) {
F_120 ( V_5 , V_325 ) ;
F_209 ( V_325 ) ;
}
}
if ( ! V_5 -> V_6 ) {
if ( ! F_59 ( V_5 -> V_23 , V_164 ) )
F_161 ( V_5 ) ;
}
else
F_41 ( & V_5 -> V_2 -> V_10 , L_125 ,
V_5 -> V_329 -> V_330 ) ;
F_221 ( V_5 -> V_7 ) ;
F_60 ( V_5 -> V_7 ) ;
F_144 ( & V_5 -> V_38 , F_218 , V_5 ) ;
if ( V_5 -> V_466 ) {
F_212 ( V_5 -> V_466 ) ;
V_5 -> V_466 = NULL ;
}
if ( V_5 -> V_329 ) {
if ( F_19 ( V_468 , & V_5 -> V_44 ) )
F_213 ( V_5 -> V_329 ) ;
if ( V_5 -> V_329 -> V_7 ) {
F_214 ( V_5 -> V_7 ) ;
F_215 ( & V_5 -> V_38 ) ;
V_5 -> V_7 = NULL ;
}
F_217 ( V_5 -> V_329 ) ;
}
V_5 -> V_329 = NULL ;
F_22 ( & V_438 ) ;
F_216 ( & V_436 , V_5 -> V_389 ) ;
F_25 ( & V_438 ) ;
F_162 ( V_5 ) ;
return 0 ;
}
static int F_222 ( struct V_4 * V_5 )
{
F_163 ( V_5 ) ;
if ( V_5 -> V_329 ) {
F_41 ( & V_5 -> V_2 -> V_10 ,
L_126 , V_5 -> V_329 -> V_330 ) ;
if ( F_19 ( V_468 , & V_5 -> V_44 ) )
F_213 ( V_5 -> V_329 ) ;
if ( V_5 -> V_329 -> V_7 ) {
F_214 ( V_5 -> V_7 ) ;
F_215 ( & V_5 -> V_38 ) ;
}
F_217 ( V_5 -> V_329 ) ;
V_5 -> V_329 = NULL ;
V_5 -> V_7 = NULL ;
}
F_22 ( & V_438 ) ;
F_216 ( & V_436 , V_5 -> V_389 ) ;
F_25 ( & V_438 ) ;
return 0 ;
}
static int F_223 ( struct V_4 * V_5 )
{
F_41 ( & V_5 -> V_2 -> V_10 ,
L_127 , V_5 -> V_329 -> V_330 ) ;
F_164 ( V_5 ) ;
return 0 ;
}
static int F_224 ( struct V_4 * V_5 )
{
F_41 ( & V_5 -> V_2 -> V_10 , L_128 ,
V_5 -> V_329 -> V_330 ) ;
F_165 ( V_5 ) ;
return 0 ;
}
static void F_225 ( int V_471 )
{
V_472 [ V_471 ] -- ;
}
static int F_226 ( int V_473 )
{
int V_471 , V_474 , V_475 ;
const struct V_476 * V_477 ;
V_477 = F_227 ( V_473 ) ;
V_474 = F_228 ( V_477 ) ;
V_475 = V_472 [ V_474 ] ;
V_471 = V_474 ;
F_229 (cpu, node_mask) {
if ( V_472 [ V_471 ] < V_475 ) {
V_474 = V_471 ;
V_475 = V_472 [ V_471 ] ;
}
}
V_472 [ V_474 ] ++ ;
return V_474 ;
}
static inline int F_230 ( void )
{
static int V_478 = - 1 ;
if ( V_478 == - 1 ) {
V_478 = V_479 ;
return V_478 ;
}
V_478 = F_231 ( V_478 ) ;
if ( V_478 == V_480 )
V_478 = V_479 ;
return V_478 ;
}
static void F_232 ( struct V_4 * V_5 , struct V_1 * V_2 )
{
int V_481 ;
unsigned short V_482 ;
V_481 = F_233 ( V_2 , V_483 ) ;
if ( V_481 ) {
F_3 ( V_2 ,
V_481 + V_484 ,
& V_482 ) ;
if ( V_482 & ( 1 << 11 ) ||
V_482 & ( 1 << 4 ) ) {
F_41 ( & V_5 -> V_2 -> V_10 ,
L_129 ,
V_2 -> V_485 , V_2 -> V_191 ) ;
V_482 &= ~ ( V_486 |
V_487 ) ;
F_234 ( V_2 ,
V_481 + V_484 ,
V_482 ) ;
}
}
}
static void F_235 ( struct V_4 * V_5 , struct V_1 * V_2 )
{
if ( V_2 -> V_488 && V_2 -> V_488 -> V_489 ) {
if ( V_2 -> V_488 -> V_489 -> V_485 == V_490 &&
( ( V_2 -> V_488 -> V_489 -> V_191 & 0xff00 ) == 0x5a00 ) ) {
F_232 ( V_5 , V_2 -> V_488 -> V_489 ) ;
} else {
struct V_1 * V_491 = V_2 -> V_488 -> V_489 ;
if ( V_491 -> V_488 &&
V_491 -> V_488 -> V_492 &&
V_491 -> V_488 -> V_492 -> V_489 &&
V_491 -> V_488 -> V_492 -> V_489 -> V_485 ==
V_490 &&
( V_491 -> V_488 -> V_492 -> V_489 -> V_191 &
0xff00 ) == 0x5a00 ) {
F_232 ( V_5 ,
V_491 -> V_488 -> V_492 -> V_489 ) ;
}
}
}
}
static int F_236 ( struct V_1 * V_2 ,
const struct V_493 * V_494 )
{
int V_71 = 0 ;
struct V_4 * V_5 = NULL ;
char V_495 [ 256 ] ;
const struct V_476 * V_477 ;
int V_471 , V_56 = 0 , V_496 = 0 ;
int V_497 = V_498 ;
unsigned long V_93 ;
V_497 = F_237 ( V_2 -> V_488 ) ;
if ( V_497 != V_498 ) {
if ( ! F_238 ( V_497 ) )
V_497 = F_230 () ;
} else {
F_41 ( & V_2 -> V_10 , L_130 ) ;
V_497 = F_230 () ;
}
F_41 ( & V_2 -> V_10 , L_131 ,
V_497 , F_237 ( V_2 -> V_488 ) , F_239 ( & V_2 -> V_10 ) ,
F_240 ( F_241 () ) , F_241 () ) ;
V_5 = F_152 ( sizeof( struct V_4 ) , V_213 , V_497 ) ;
if ( V_5 == NULL ) {
F_32 ( & V_2 -> V_10 ,
L_132 ) ;
return - V_214 ;
}
F_242 ( V_2 , V_5 ) ;
V_71 = F_243 ( V_2 ) ;
if ( V_71 < 0 ) {
F_32 ( & V_2 -> V_10 , L_133 ) ;
goto V_499;
}
V_71 = F_244 ( V_2 , 1 << V_373 , V_95 ) ;
if ( V_71 < 0 ) {
F_32 ( & V_2 -> V_10 , L_134 ) ;
goto V_499;
}
if ( ! F_245 ( V_2 , F_246 ( 64 ) ) ) {
V_71 = F_247 ( V_2 , F_246 ( 64 ) ) ;
if ( V_71 ) {
V_71 = F_247 ( V_2 ,
F_246 ( 32 ) ) ;
if ( V_71 ) {
F_5 ( & V_2 -> V_10 ,
L_135 ) ;
goto V_500;
}
}
}
V_5 -> V_441 = V_501 ;
V_5 -> V_133 = V_133 ;
V_5 -> V_2 = V_2 ;
V_5 -> V_375 = V_497 ;
F_248 ( & V_5 -> V_502 ) ;
F_248 ( & V_5 -> V_503 ) ;
memset ( V_5 -> V_504 , 0 , 32 ) ;
snprintf ( V_5 -> V_504 , 31 , L_136 , V_5 -> V_133 ) ;
V_5 -> V_129 = F_249 ( V_5 -> V_504 ) ;
if ( ! V_5 -> V_129 ) {
F_5 ( & V_2 -> V_10 , L_137 , V_5 -> V_133 ) ;
V_71 = - V_214 ;
goto V_505;
}
memset ( V_495 , 0 , sizeof( V_495 ) ) ;
V_477 = F_227 ( V_5 -> V_375 ) ;
if ( ! F_250 ( V_477 ) ) {
F_229 (cpu, node_mask)
{
snprintf ( & V_495 [ V_496 ] , 256 - V_496 , L_138 , V_471 ) ;
V_496 = strlen ( V_495 ) ;
}
F_41 ( & V_2 -> V_10 , L_139 ,
V_5 -> V_375 ,
F_251 ( F_228 ( V_477 ) ) ,
F_252 ( V_5 -> V_375 ) ,
V_495 ) ;
} else
F_253 ( & V_2 -> V_10 , L_140 ) ;
V_5 -> V_386 = F_226 ( V_5 -> V_375 ) ;
F_41 ( & V_2 -> V_10 , L_141 ,
F_240 ( V_5 -> V_386 ) , V_5 -> V_386 ) ;
V_5 -> V_127 [ 0 ] . V_128 = V_5 -> V_386 ;
V_5 -> V_127 [ 1 ] . V_128 = F_226 ( V_5 -> V_375 ) ;
V_5 -> V_127 [ 2 ] . V_128 = F_226 ( V_5 -> V_375 ) ;
V_5 -> V_127 [ 3 ] . V_128 = V_5 -> V_127 [ 0 ] . V_128 ;
V_5 -> V_127 [ 4 ] . V_128 = V_5 -> V_127 [ 1 ] . V_128 ;
V_5 -> V_127 [ 5 ] . V_128 = V_5 -> V_127 [ 2 ] . V_128 ;
V_5 -> V_127 [ 6 ] . V_128 = V_5 -> V_127 [ 2 ] . V_128 ;
V_5 -> V_127 [ 7 ] . V_128 = V_5 -> V_127 [ 1 ] . V_128 ;
F_254 (cpu) {
memset ( V_495 , 0 , sizeof( V_495 ) ) ;
for ( V_56 = 0 , V_496 = 0 ; V_56 < V_126 ; V_56 ++ ) {
if ( V_5 -> V_127 [ V_56 ] . V_128 == V_471 ) {
snprintf ( & V_495 [ V_496 ] , 256 - V_496 , L_138 , V_56 ) ;
V_496 = strlen ( V_495 ) ;
}
}
if ( V_496 )
F_41 ( & V_2 -> V_10 , L_142 , V_471 , V_495 ) ;
}
F_255 ( & V_5 -> V_127 [ 0 ] . V_127 , V_506 ) ;
F_255 ( & V_5 -> V_127 [ 1 ] . V_127 , V_507 ) ;
F_255 ( & V_5 -> V_127 [ 2 ] . V_127 , V_508 ) ;
F_255 ( & V_5 -> V_127 [ 3 ] . V_127 , V_509 ) ;
F_255 ( & V_5 -> V_127 [ 4 ] . V_127 , V_510 ) ;
F_255 ( & V_5 -> V_127 [ 5 ] . V_127 , V_511 ) ;
F_255 ( & V_5 -> V_127 [ 6 ] . V_127 , V_512 ) ;
F_255 ( & V_5 -> V_127 [ 7 ] . V_127 , V_513 ) ;
F_256 ( V_2 ) ;
V_71 = F_257 ( V_2 ) ;
if ( V_71 ) {
F_5 ( & V_2 -> V_10 ,
L_143 ) ;
goto V_514;
}
F_235 ( V_5 , V_2 ) ;
V_71 = F_133 ( V_5 ) ;
if ( V_71 < 0 ) {
F_32 ( & V_2 -> V_10 ,
L_144 ) ;
goto V_505;
}
V_133 ++ ;
if ( V_71 != V_348 )
F_4 ( V_468 , & V_5 -> V_44 ) ;
else
V_71 = 0 ;
F_110 ( & V_316 , V_93 ) ;
F_258 ( & V_5 -> V_502 , & V_502 ) ;
F_113 ( & V_316 , V_93 ) ;
goto V_515;
V_505:
F_259 ( V_2 ) ;
V_514:
if ( V_5 -> V_129 ) {
F_260 ( V_5 -> V_129 ) ;
F_261 ( V_5 -> V_129 ) ;
F_225 ( V_5 -> V_127 [ 0 ] . V_128 ) ;
F_225 ( V_5 -> V_127 [ 1 ] . V_128 ) ;
F_225 ( V_5 -> V_127 [ 2 ] . V_128 ) ;
}
V_500:
F_262 ( V_2 , 1 << V_373 ) ;
V_499:
F_98 ( V_5 ) ;
F_242 ( V_2 , NULL ) ;
return V_71 ;
V_515:
return V_71 ;
}
static void F_263 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
unsigned long V_93 , V_149 ;
F_4 ( V_412 , & V_5 -> V_44 ) ;
F_110 ( & V_316 , V_93 ) ;
F_264 ( & V_5 -> V_502 ) ;
F_258 ( & V_5 -> V_503 , & V_516 ) ;
F_113 ( & V_316 , V_93 ) ;
F_1 ( V_2 ) ;
F_265 ( V_5 -> V_2 -> V_132 ) ;
V_149 = V_42 + F_17 ( 4000 ) ;
do {
F_61 ( 20 ) ;
} while ( F_51 ( & V_5 -> V_108 ) != 0 &&
F_20 ( V_42 , V_149 ) );
if ( ! V_5 -> V_6 )
F_266 ( V_5 -> V_466 ) ;
if ( F_51 ( & V_5 -> V_108 ) != 0 ) {
F_5 ( & V_5 -> V_2 -> V_10 ,
L_145 ) ;
}
F_267 ( V_5 -> V_7 ) ;
F_4 ( V_43 , & V_5 -> V_44 ) ;
F_219 ( V_5 ) ;
if ( V_5 -> V_129 ) {
F_260 ( V_5 -> V_129 ) ;
F_261 ( V_5 -> V_129 ) ;
F_225 ( V_5 -> V_127 [ 0 ] . V_128 ) ;
F_225 ( V_5 -> V_127 [ 1 ] . V_128 ) ;
F_225 ( V_5 -> V_127 [ 2 ] . V_128 ) ;
}
F_259 ( V_2 ) ;
F_110 ( & V_316 , V_93 ) ;
F_264 ( & V_5 -> V_503 ) ;
F_113 ( & V_316 , V_93 ) ;
F_98 ( V_5 ) ;
F_262 ( V_2 , 1 << V_373 ) ;
F_242 ( V_2 , NULL ) ;
}
static int F_268 ( struct V_1 * V_2 , T_14 V_517 )
{
int V_71 = 0 ;
struct V_4 * V_5 = F_2 ( V_2 ) ;
if ( ! V_5 ) {
F_32 ( & V_2 -> V_10 ,
L_146 ) ;
return - V_72 ;
}
F_4 ( V_518 , & V_5 -> V_44 ) ;
V_71 = F_223 ( V_5 ) ;
if ( V_71 < 0 ) {
F_32 ( & V_2 -> V_10 ,
L_147 ) ;
return V_71 ;
}
F_269 ( V_2 ) ;
F_270 ( V_2 ) ;
F_271 ( V_2 , V_519 ) ;
return V_71 ;
}
static int F_272 ( struct V_1 * V_2 )
{
int V_71 = 0 ;
struct V_4 * V_5 ;
V_5 = F_2 ( V_2 ) ;
if ( ! V_5 ) {
F_32 ( & V_2 -> V_10 ,
L_146 ) ;
return - V_72 ;
}
F_271 ( V_2 , V_520 ) ;
F_273 ( V_2 ) ;
V_71 = F_243 ( V_2 ) ;
if ( V_71 < 0 ) {
F_32 ( & V_2 -> V_10 ,
L_148 ) ;
goto V_261;
}
F_256 ( V_2 ) ;
V_71 = F_224 ( V_5 ) ;
if ( V_71 < 0 )
F_32 ( & V_2 -> V_10 , L_149 ) ;
V_261:
F_57 ( V_518 , & V_5 -> V_44 ) ;
return V_71 ;
}
static void F_274 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
if ( V_5 )
F_222 ( V_5 ) ;
}
static int T_15 F_275 ( void )
{
int error ;
F_276 ( V_95 L_150 V_521 L_86 ) ;
F_154 ( & V_316 ) ;
F_248 ( & V_502 ) ;
F_248 ( & V_516 ) ;
error = F_277 ( 0 , V_95 ) ;
if ( error <= 0 ) {
F_278 ( L_151 ,
error ) ;
return - V_153 ;
}
V_501 = error ;
V_327 = F_123 ( L_119 , NULL ) ;
if ( F_124 ( V_327 ) ) {
F_279 ( L_152 ) ;
V_327 = NULL ;
}
if ( V_327 ) {
V_522 = F_125 ( L_153 ,
V_331 , V_327 , NULL ,
& V_523 ) ;
if ( F_124 ( V_522 ) ) {
F_278 ( L_154 ) ;
V_522 = NULL ;
}
}
error = F_280 ( & V_524 ) ;
if ( error ) {
F_281 ( V_327 ) ;
F_282 ( V_501 , V_95 ) ;
}
return error ;
}
static void T_16 F_283 ( void )
{
F_282 ( V_501 , V_95 ) ;
F_284 ( & V_524 ) ;
F_127 ( V_327 ) ;
}
