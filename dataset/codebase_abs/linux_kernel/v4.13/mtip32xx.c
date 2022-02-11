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
V_17 -> V_18 = V_5 -> V_19 -> V_20 +
( sizeof( struct V_21 ) * V_13 -> V_22 ) ;
V_17 -> V_23 = V_5 -> V_19 -> V_24 +
( sizeof( struct V_21 ) * V_13 -> V_22 ) ;
if ( F_8 ( V_25 , & V_5 -> V_19 -> V_26 ) )
V_17 -> V_18 -> V_27 = V_28 F_9 ( ( V_17 -> V_29 >> 16 ) >> 16 ) ;
V_17 -> V_18 -> V_30 = V_28 F_9 ( V_17 -> V_29 & 0xFFFFFFFF ) ;
}
static struct V_16 * F_10 ( struct V_4 * V_5 )
{
struct V_12 * V_13 ;
if ( F_1 ( V_5 -> V_2 ) )
return NULL ;
V_13 = F_11 ( V_5 -> V_7 , V_31 , V_32 ) ;
if ( F_12 ( V_13 ) )
return NULL ;
F_6 ( V_13 ) ;
return F_7 ( V_13 ) ;
}
static struct V_16 * F_13 ( struct V_4 * V_5 ,
unsigned int V_22 )
{
struct V_33 * V_34 = V_5 -> V_7 -> V_35 [ 0 ] ;
return F_7 ( F_14 ( V_34 -> V_36 , V_22 ) ) ;
}
static int F_15 ( struct V_4 * V_5 )
{
unsigned long V_37 ;
F_16 ( V_38 , V_5 -> V_39 + V_40 ) ;
F_17 ( V_5 -> V_39 + V_40 ) ;
V_37 = V_41 + F_18 ( 10000 ) ;
do {
F_19 ( 10 ) ;
if ( F_8 ( V_42 , & V_5 -> V_43 ) )
return - 1 ;
} while ( ( F_17 ( V_5 -> V_39 + V_40 ) & V_38 )
&& F_20 ( V_41 , V_37 ) );
if ( F_17 ( V_5 -> V_39 + V_40 ) & V_38 )
return - 1 ;
return 0 ;
}
static inline void F_21 ( struct V_44 * V_19 , int V_22 )
{
int V_45 = V_22 >> 5 ;
F_22 ( & V_19 -> V_46 [ V_45 ] ) ;
F_16 ( ( 1 << F_23 ( V_22 ) ) ,
V_19 -> V_47 [ F_24 ( V_22 ) ] ) ;
F_16 ( ( 1 << F_23 ( V_22 ) ) ,
V_19 -> V_48 [ F_24 ( V_22 ) ] ) ;
F_25 ( & V_19 -> V_46 [ V_45 ] ) ;
}
static int F_26 ( struct V_44 * V_19 , int V_49 )
{
T_2 V_50 ;
V_50 = F_17 ( V_19 -> V_39 + V_51 ) ;
if ( V_49 )
F_16 ( V_50 | V_52 , V_19 -> V_39 + V_51 ) ;
else
F_16 ( V_50 & ~ V_52 , V_19 -> V_39 + V_51 ) ;
F_17 ( V_19 -> V_39 + V_51 ) ;
return ( ( ( V_50 & V_52 ) == V_52 ) ) ;
}
static int F_27 ( struct V_44 * V_19 , int V_49 )
{
T_2 V_50 ;
V_50 = F_17 ( V_19 -> V_39 + V_51 ) ;
if ( V_49 )
F_16 ( V_50 | V_53 , V_19 -> V_39 + V_51 ) ;
else
F_16 ( V_50 & ~ V_53 , V_19 -> V_39 + V_51 ) ;
F_17 ( V_19 -> V_39 + V_51 ) ;
return ( ( ( V_50 & V_53 ) == V_53 ) ) ;
}
static inline void F_28 ( struct V_44 * V_19 )
{
F_26 ( V_19 , 1 ) ;
F_27 ( V_19 , 1 ) ;
}
static inline void F_29 ( struct V_44 * V_19 )
{
F_16 ( 0 , V_19 -> V_39 + V_54 ) ;
F_27 ( V_19 , 0 ) ;
F_26 ( V_19 , 0 ) ;
}
static void F_30 ( struct V_44 * V_19 )
{
int V_55 ;
F_29 ( V_19 ) ;
if ( F_17 ( V_19 -> V_5 -> V_39 + V_56 ) & V_57 ) {
F_16 ( ( V_19 -> V_24 >> 16 ) >> 16 ,
V_19 -> V_39 + V_58 ) ;
F_16 ( ( V_19 -> V_59 >> 16 ) >> 16 ,
V_19 -> V_39 + V_60 ) ;
F_4 ( V_25 , & V_19 -> V_26 ) ;
}
F_16 ( V_19 -> V_24 & 0xFFFFFFFF ,
V_19 -> V_39 + V_61 ) ;
F_16 ( V_19 -> V_59 & 0xFFFFFFFF , V_19 -> V_39 + V_62 ) ;
F_16 ( F_17 ( V_19 -> V_39 + V_63 ) , V_19 -> V_39 + V_63 ) ;
for ( V_55 = 0 ; V_55 < V_19 -> V_5 -> V_64 ; V_55 ++ )
F_16 ( 0xFFFFFFFF , V_19 -> V_65 [ V_55 ] ) ;
F_16 ( F_17 ( V_19 -> V_39 + V_66 ) , V_19 -> V_39 + V_66 ) ;
F_16 ( F_17 ( V_19 -> V_5 -> V_39 + V_67 ) ,
V_19 -> V_5 -> V_39 + V_67 ) ;
F_16 ( V_68 , V_19 -> V_39 + V_54 ) ;
}
static void F_31 ( struct V_44 * V_19 )
{
unsigned long V_37 ;
F_27 ( V_19 , 0 ) ;
V_37 = V_41 + F_18 ( 500 ) ;
while ( ( F_17 ( V_19 -> V_39 + V_51 ) & V_69 )
&& F_20 ( V_41 , V_37 ) )
;
if ( F_8 ( V_42 , & V_19 -> V_5 -> V_43 ) )
return;
if ( F_17 ( V_19 -> V_39 + V_51 ) & V_69 ) {
F_5 ( & V_19 -> V_5 -> V_2 -> V_10 ,
L_2 ) ;
if ( F_15 ( V_19 -> V_5 ) )
F_32 ( & V_19 -> V_5 -> V_2 -> V_10 ,
L_3 ) ;
F_19 ( 30 ) ;
}
F_5 ( & V_19 -> V_5 -> V_2 -> V_10 , L_4 ) ;
F_16 ( F_17 ( V_19 -> V_39 + V_70 ) |
1 , V_19 -> V_39 + V_70 ) ;
F_17 ( V_19 -> V_39 + V_70 ) ;
V_37 = V_41 + F_18 ( 1 ) ;
while ( F_20 ( V_41 , V_37 ) )
;
if ( F_8 ( V_42 , & V_19 -> V_5 -> V_43 ) )
return;
F_16 ( F_17 ( V_19 -> V_39 + V_70 ) & ~ 1 ,
V_19 -> V_39 + V_70 ) ;
F_17 ( V_19 -> V_39 + V_70 ) ;
V_37 = V_41 + F_18 ( 500 ) ;
while ( ( ( F_17 ( V_19 -> V_39 + V_71 ) & 0x01 ) == 0 )
&& F_20 ( V_41 , V_37 ) )
;
if ( F_8 ( V_42 , & V_19 -> V_5 -> V_43 ) )
return;
if ( ( F_17 ( V_19 -> V_39 + V_71 ) & 0x01 ) == 0 )
F_5 ( & V_19 -> V_5 -> V_2 -> V_10 ,
L_5 ) ;
F_30 ( V_19 ) ;
F_28 ( V_19 ) ;
}
static int F_33 ( struct V_4 * V_5 )
{
int V_72 = 0 ;
if ( F_1 ( V_5 -> V_2 ) )
return 0 ;
if ( F_15 ( V_5 ) < 0 )
V_72 = - V_73 ;
F_19 ( 1 ) ;
F_30 ( V_5 -> V_19 ) ;
F_28 ( V_5 -> V_19 ) ;
F_16 ( F_17 ( V_5 -> V_39 + V_40 ) | V_74 ,
V_5 -> V_39 + V_40 ) ;
return V_72 ;
}
static void F_34 ( struct V_4 * V_5 ,
char * V_75 ,
unsigned long * V_76 ,
int V_77 )
{
unsigned char V_78 [ 128 ] ;
int V_45 , V_79 = 0 ;
memset ( V_78 , 0 , sizeof( V_78 ) ) ;
for ( V_45 = V_80 ; V_45 > 0 ; V_45 -- )
V_79 += sprintf ( V_78 + V_79 , L_6 ,
V_76 [ V_45 - 1 ] ) ;
F_5 ( & V_5 -> V_2 -> V_10 ,
L_7 , V_77 , V_75 , V_78 ) ;
}
static void F_35 ( struct V_16 * V_17 , T_3 V_81 )
{
struct V_12 * V_82 = F_36 ( V_17 ) ;
V_17 -> V_81 = V_81 ;
F_37 ( V_82 ) ;
}
static void F_38 ( struct V_4 * V_5 )
{
int V_45 , V_22 , V_83 , V_84 , V_72 ;
struct V_44 * V_19 ;
struct V_16 * V_17 ;
T_2 V_65 ;
struct V_85 * V_86 ;
unsigned long V_87 [ V_80 ] ;
unsigned int V_88 = 0 ;
unsigned char * V_89 ;
char * V_90 = NULL ;
int V_91 = 0 , V_92 = 0 ;
F_5 ( & V_5 -> V_2 -> V_10 , L_8 ) ;
V_19 = V_5 -> V_19 ;
if ( F_8 ( V_93 , & V_19 -> V_26 ) ) {
V_17 = F_13 ( V_5 , V_94 ) ;
F_39 ( V_95 L_9 ) ;
F_35 ( V_17 , V_96 ) ;
return;
}
memset ( V_87 , 0 , V_80 * sizeof( long ) ) ;
for ( V_45 = 0 ; V_45 < V_5 -> V_64 ; V_45 ++ ) {
V_65 = F_17 ( V_19 -> V_65 [ V_45 ] ) ;
F_5 ( & V_5 -> V_2 -> V_10 , L_10 , V_45 , V_65 ) ;
F_16 ( V_65 , V_19 -> V_65 [ V_45 ] ) ;
for ( V_83 = 0 ; V_83 < 32 && V_65 ; V_83 ++ ) {
if ( ! ( V_65 & ( 1 << V_83 ) ) )
continue;
V_22 = ( V_45 << 5 ) + V_83 ;
if ( V_22 == V_94 )
continue;
V_17 = F_13 ( V_5 , V_22 ) ;
F_35 ( V_17 , 0 ) ;
F_4 ( V_22 , V_87 ) ;
V_88 ++ ;
}
}
F_34 ( V_5 , L_11 , V_87 , V_88 ) ;
F_19 ( 20 ) ;
F_31 ( V_19 ) ;
V_72 = F_40 ( V_5 -> V_19 , V_97 ,
V_5 -> V_19 -> V_98 ,
V_5 -> V_19 -> V_99 , 1 ) ;
if ( V_72 ) {
F_5 ( & V_5 -> V_2 -> V_10 ,
L_12 ) ;
} else {
V_89 = ( unsigned char * ) V_5 -> V_19 -> V_98 ;
if ( V_89 [ 259 ] & 0x1 ) {
F_41 ( & V_5 -> V_2 -> V_10 ,
L_13 ) ;
F_4 ( V_100 , & V_5 -> V_43 ) ;
V_91 = 1 ;
V_90 = L_14 ;
}
if ( V_89 [ 288 ] == 0xF7 ) {
F_41 ( & V_5 -> V_2 -> V_10 ,
L_15 ) ;
F_4 ( V_101 , & V_5 -> V_43 ) ;
V_92 = 1 ;
V_90 = L_16 ;
}
if ( V_89 [ 288 ] == 0xBF ) {
F_4 ( V_102 , & V_5 -> V_43 ) ;
F_41 ( & V_5 -> V_2 -> V_10 ,
L_17 ) ;
V_92 = 1 ;
V_90 = L_18 ;
}
}
memset ( V_87 , 0 , V_80 * sizeof( long ) ) ;
for ( V_45 = 0 ; V_45 < V_5 -> V_64 ; V_45 ++ ) {
for ( V_83 = 0 ; V_83 < 32 ; V_83 ++ ) {
V_84 = 1 ;
V_22 = ( V_45 << 5 ) + V_83 ;
V_17 = F_13 ( V_5 , V_22 ) ;
V_86 = (struct V_85 * ) V_17 -> V_103 ;
if ( V_22 == V_94 ||
V_86 -> V_103 == V_104 )
V_84 = 0 ;
else {
if ( V_92 ||
( V_91 &&
V_86 -> V_103 == V_105 ) ) {
F_5 ( & V_5 -> V_2 -> V_10 ,
L_19 ,
V_86 -> V_103 == V_105 ?
L_20 : L_21 ,
V_22 ,
V_90 != NULL ?
V_90 : L_22 ) ;
F_35 ( V_17 , V_106 ) ;
continue;
}
}
if ( V_84 && ( V_17 -> V_107 -- > 0 ) ) {
F_4 ( V_22 , V_87 ) ;
F_21 ( V_19 , V_22 ) ;
continue;
}
F_5 ( & V_19 -> V_5 -> V_2 -> V_10 ,
L_23 , V_22 ) ;
F_35 ( V_17 , V_96 ) ;
}
}
F_34 ( V_5 , L_24 , V_87 , V_88 ) ;
}
static inline void F_42 ( struct V_44 * V_19 , int V_45 ,
T_2 V_65 )
{
struct V_4 * V_5 = V_19 -> V_5 ;
int V_22 , V_83 ;
struct V_16 * V_103 ;
if ( ! V_65 ) {
F_43 ( ! V_65 ) ;
return;
}
F_16 ( V_65 , V_19 -> V_65 [ V_45 ] ) ;
for ( V_83 = 0 ; ( V_83 < 32 ) && V_65 ; V_83 ++ ) {
if ( V_65 & 0x01 ) {
V_22 = ( V_45 << 5 ) | V_83 ;
if ( F_44 ( V_22 == V_94 ) )
continue;
V_103 = F_13 ( V_5 , V_22 ) ;
F_35 ( V_103 , 0 ) ;
}
V_65 >>= 1 ;
}
if ( F_45 ( & V_5 -> V_108 ) == 0 )
F_16 ( 0xffffffff , V_5 -> V_39 + V_67 ) ;
}
static inline void F_46 ( struct V_4 * V_5 , T_2 V_109 )
{
struct V_44 * V_19 = V_5 -> V_19 ;
struct V_16 * V_17 = F_13 ( V_5 , V_94 ) ;
if ( F_8 ( V_93 , & V_19 -> V_26 ) && V_17 ) {
int V_45 = F_24 ( V_94 ) ;
int V_81 = F_17 ( V_19 -> V_48 [ V_45 ] ) ;
if ( ! ( V_81 & ( 1 << F_23 ( V_94 ) ) ) )
F_35 ( V_17 , 0 ) ;
}
}
static inline void F_47 ( struct V_4 * V_5 , T_2 V_109 )
{
if ( F_44 ( V_109 & V_110 ) ) {
F_5 ( & V_5 -> V_2 -> V_10 ,
L_25 ) ;
F_16 ( ( 1 << 26 ) , V_5 -> V_19 -> V_39 + V_63 ) ;
}
if ( F_44 ( V_109 & V_111 ) ) {
F_5 ( & V_5 -> V_2 -> V_10 ,
L_26 ) ;
F_16 ( ( 1 << 16 ) , V_5 -> V_19 -> V_39 + V_63 ) ;
}
if ( F_44 ( V_109 & ~ V_112 ) ) {
F_5 ( & V_5 -> V_2 -> V_10 ,
L_27 ,
( V_109 & ~ V_112 ) ) ;
if ( F_1 ( V_5 -> V_2 ) )
return;
}
if ( F_48 ( V_109 & ( V_113 | V_114 ) ) ) {
F_4 ( V_115 , & V_5 -> V_19 -> V_26 ) ;
F_49 ( & V_5 -> V_19 -> V_116 ) ;
}
}
static inline T_4 F_50 ( struct V_4 * V_117 )
{
struct V_4 * V_5 = (struct V_4 * ) V_117 ;
struct V_44 * V_19 = V_5 -> V_19 ;
T_2 V_118 , V_109 ;
int V_72 = V_119 ;
int V_120 = 1 , V_55 , V_121 ;
struct V_122 * V_123 ;
V_118 = F_17 ( V_5 -> V_39 + V_67 ) ;
if ( V_118 ) {
V_72 = V_124 ;
V_109 = F_17 ( V_19 -> V_39 + V_66 ) ;
if ( F_44 ( V_109 == 0xFFFFFFFF ) ) {
F_1 ( V_5 -> V_2 ) ;
return V_124 ;
}
F_16 ( V_109 , V_19 -> V_39 + V_66 ) ;
if ( F_48 ( V_109 & V_125 ) ) {
V_120 = 0 ;
F_43 ( F_51 ( & V_5 -> V_108 ) != 0 ) ;
for ( V_55 = 0 , V_121 = 0 ; V_55 < V_126 ;
V_55 ++ ) {
V_123 = & V_5 -> V_127 [ V_55 ] ;
V_123 -> V_65 = F_17 ( V_19 -> V_65 [ V_55 ] ) ;
if ( V_123 -> V_65 )
V_121 ++ ;
}
F_52 ( & V_5 -> V_108 , V_121 ) ;
if ( V_121 ) {
for ( V_55 = 1 ; V_55 < V_126 ; V_55 ++ ) {
V_123 = & V_5 -> V_127 [ V_55 ] ;
if ( V_123 -> V_65 )
F_53 (
V_123 -> V_128 ,
V_5 -> V_129 ,
& V_123 -> V_127 ) ;
}
if ( F_48 ( V_5 -> V_127 [ 0 ] . V_65 ) )
F_42 ( V_19 , 0 ,
V_5 -> V_127 [ 0 ] . V_65 ) ;
} else {
V_120 = 1 ;
}
}
if ( F_44 ( V_109 & V_130 ) ) {
if ( F_44 ( F_1 ( V_5 -> V_2 ) ) ) {
return V_124 ;
}
if ( F_8 ( V_42 ,
& V_5 -> V_43 ) )
return V_72 ;
F_47 ( V_5 , V_109 & V_130 ) ;
}
if ( F_44 ( V_109 & V_131 ) )
F_46 ( V_5 , V_109 & V_131 ) ;
}
if ( F_44 ( V_120 ) )
F_16 ( V_118 , V_5 -> V_39 + V_67 ) ;
return V_72 ;
}
static T_4 F_54 ( int V_132 , void * V_133 )
{
struct V_4 * V_5 = V_133 ;
return F_50 ( V_5 ) ;
}
static void F_55 ( struct V_44 * V_19 , int V_22 )
{
F_16 ( 1 << F_23 ( V_22 ) , V_19 -> V_48 [ F_24 ( V_22 ) ] ) ;
}
static bool F_56 ( struct V_44 * V_19 ,
struct V_85 * V_86 )
{
struct V_85 * V_134 ;
unsigned long V_135 ;
V_134 = V_19 -> V_136 + V_137 ;
V_135 = F_17 ( V_19 -> V_39 + V_138 ) ;
if ( ( V_135 & 1 ) )
return false ;
if ( V_86 -> V_103 == V_139 ) {
V_19 -> V_140 = V_41 ;
return true ;
} else if ( ( V_86 -> V_103 == V_141 ) &&
( V_86 -> V_142 == 0x03 ) ) {
F_4 ( V_143 , & V_19 -> V_26 ) ;
V_19 -> V_140 = V_41 ;
return true ;
} else if ( ( V_86 -> V_103 == V_144 ) ||
( ( V_86 -> V_103 == 0xFC ) &&
( V_86 -> V_142 == 0x27 || V_86 -> V_142 == 0x72 ||
V_86 -> V_142 == 0x62 || V_86 -> V_142 == 0x26 ) ) ) {
F_57 ( V_145 , & V_19 -> V_5 -> V_43 ) ;
F_57 ( V_102 , & V_19 -> V_5 -> V_43 ) ;
F_31 ( V_19 ) ;
F_57 ( V_146 , & V_19 -> V_26 ) ;
return false ;
}
return false ;
}
static bool F_58 ( struct V_44 * V_19 )
{
unsigned int V_147 ;
unsigned int V_148 ;
V_147 = F_17 ( V_19 -> V_47 [ 0 ] ) & 0xFFFFFFFE ;
for ( V_148 = 1 ; V_148 < V_19 -> V_5 -> V_64 ; V_148 ++ )
V_147 |= F_17 ( V_19 -> V_47 [ V_148 ] ) ;
return V_147 != 0 ;
}
static int F_59 ( struct V_44 * V_19 , unsigned long V_37 )
{
unsigned long V_149 ;
bool V_147 = true ;
F_60 ( V_19 -> V_5 -> V_7 ) ;
V_149 = V_41 + F_18 ( V_37 ) ;
do {
if ( F_8 ( V_150 , & V_19 -> V_26 ) &&
F_8 ( V_151 , & V_19 -> V_26 ) ) {
F_61 ( 20 ) ;
continue;
}
F_61 ( 100 ) ;
if ( F_1 ( V_19 -> V_5 -> V_2 ) )
goto V_152;
V_147 = F_58 ( V_19 ) ;
if ( ! V_147 )
break;
} while ( F_20 ( V_41 , V_149 ) );
F_62 ( V_19 -> V_5 -> V_7 ) ;
return V_147 ? - V_153 : 0 ;
V_152:
F_62 ( V_19 -> V_5 -> V_7 ) ;
return - V_73 ;
}
static int F_63 ( struct V_44 * V_19 ,
struct V_85 * V_86 ,
int V_154 ,
T_5 V_155 ,
int V_156 ,
T_2 V_157 ,
unsigned long V_37 )
{
struct V_16 * V_158 ;
struct V_4 * V_5 = V_19 -> V_5 ;
struct V_12 * V_13 ;
struct V_159 V_160 = {
. V_154 = V_154 ,
. V_155 = V_155 ,
. V_156 = V_156 ,
. V_157 = V_157
} ;
int V_72 = 0 ;
unsigned long V_161 ;
if ( V_155 & 0x00000007 ) {
F_32 ( & V_5 -> V_2 -> V_10 , L_28 ) ;
return - V_73 ;
}
V_158 = F_10 ( V_5 ) ;
if ( ! V_158 ) {
F_39 ( V_95 L_29 ) ;
return - V_73 ;
}
V_13 = F_36 ( V_158 ) ;
V_13 -> V_162 = & V_160 ;
F_4 ( V_93 , & V_19 -> V_26 ) ;
if ( V_86 -> V_103 == V_139 )
F_4 ( V_146 , & V_19 -> V_26 ) ;
F_57 ( V_143 , & V_19 -> V_26 ) ;
if ( V_86 -> V_103 != V_163 ) {
if ( F_59 ( V_19 , V_164 ) < 0 ) {
F_5 ( & V_5 -> V_2 -> V_10 , L_30 ) ;
F_64 ( V_13 ) ;
F_57 ( V_93 , & V_19 -> V_26 ) ;
F_49 ( & V_19 -> V_116 ) ;
return - V_153 ;
}
}
memcpy ( V_158 -> V_103 , V_86 , V_154 * 4 ) ;
V_161 = V_41 ;
V_13 -> V_37 = V_37 ;
F_65 ( V_13 -> V_14 , NULL , V_13 , true ) ;
if ( V_158 -> V_81 ) {
F_32 ( & V_5 -> V_2 -> V_10 , L_31 ,
V_86 -> V_103 , V_158 -> V_81 ) ;
V_72 = - V_165 ;
if ( F_1 ( V_5 -> V_2 ) ||
F_8 ( V_42 ,
& V_5 -> V_43 ) ) {
F_32 ( & V_5 -> V_2 -> V_10 ,
L_32 ,
V_86 -> V_103 ) ;
V_72 = - V_166 ;
goto V_167;
}
F_33 ( V_5 ) ;
V_72 = - V_168 ;
goto V_167;
}
if ( F_17 ( V_19 -> V_48 [ F_24 ( V_94 ) ] )
& ( 1 << F_23 ( V_94 ) ) ) {
V_72 = - V_166 ;
if ( ! F_8 ( V_42 , & V_5 -> V_43 ) ) {
F_33 ( V_5 ) ;
V_72 = - V_168 ;
}
}
V_167:
F_64 ( V_13 ) ;
F_57 ( V_93 , & V_19 -> V_26 ) ;
if ( V_72 >= 0 && F_56 ( V_19 , V_86 ) ) {
return V_72 ;
}
F_49 ( & V_19 -> V_116 ) ;
return V_72 ;
}
static inline void F_66 ( T_1 * V_89 , unsigned int V_169 )
{
int V_55 ;
for ( V_55 = 0 ; V_55 < ( V_169 / 2 ) ; V_55 ++ )
F_67 ( & V_89 [ V_55 ] ) ;
}
static void F_68 ( struct V_4 * V_5 ,
struct V_85 * V_86 ,
unsigned int * V_37 , T_6 V_170 )
{
switch ( V_86 -> V_103 ) {
case V_141 :
* V_37 = 120000 ;
break;
case V_144 :
case 0xFC :
if ( V_170 )
* V_37 = ( ( * ( V_5 -> V_19 -> V_171 + 90 ) * 2 ) * 60000 ) ;
else
* V_37 = ( ( * ( V_5 -> V_19 -> V_171 + 89 ) * 2 ) * 60000 ) ;
break;
case V_163 :
* V_37 = 120000 ;
break;
case 0xF7 :
case 0xFA :
* V_37 = 60000 ;
break;
case V_172 :
* V_37 = 15000 ;
break;
default:
* V_37 = V_173 ;
break;
}
}
static int F_69 ( struct V_44 * V_19 , void T_7 * V_174 )
{
int V_72 = 0 ;
struct V_85 V_86 ;
if ( F_8 ( V_42 , & V_19 -> V_5 -> V_43 ) )
return - V_73 ;
memset ( & V_86 , 0 , sizeof( struct V_85 ) ) ;
V_86 . type = 0x27 ;
V_86 . V_157 = 1 << 7 ;
V_86 . V_103 = V_175 ;
V_19 -> V_176 = 0 ;
memset ( V_19 -> V_171 , 0 , sizeof( T_1 ) * V_177 ) ;
if ( F_63 ( V_19 ,
& V_86 ,
5 ,
V_19 -> V_178 ,
sizeof( T_1 ) * V_177 ,
0 ,
V_179 )
< 0 ) {
V_72 = - 1 ;
goto V_180;
}
#ifdef F_70
F_66 ( V_19 -> V_171 + 27 , 40 ) ;
F_66 ( V_19 -> V_171 + 23 , 8 ) ;
F_66 ( V_19 -> V_171 + 10 , 20 ) ;
#else
{
int V_55 ;
for ( V_55 = 0 ; V_55 < V_177 ; V_55 ++ )
V_19 -> V_171 [ V_55 ] = F_71 ( V_19 -> V_171 [ V_55 ] ) ;
}
#endif
if ( V_19 -> V_171 [ 128 ] & 0x4 )
F_4 ( V_145 , & V_19 -> V_5 -> V_43 ) ;
else
F_57 ( V_145 , & V_19 -> V_5 -> V_43 ) ;
#ifdef F_72
if ( V_19 -> V_171 [ 69 ] & ( 1 << 14 ) && V_19 -> V_171 [ 69 ] & ( 1 << 5 ) )
V_19 -> V_5 -> V_181 = true ;
else
#endif
V_19 -> V_5 -> V_181 = false ;
V_19 -> V_176 = 1 ;
if ( V_174 ) {
if ( F_73 (
V_174 ,
V_19 -> V_171 ,
V_177 * sizeof( T_1 ) ) ) {
V_72 = - V_73 ;
goto V_180;
}
}
V_180:
return V_72 ;
}
static int F_74 ( struct V_44 * V_19 )
{
int V_72 ;
struct V_85 V_86 ;
unsigned long V_161 ;
unsigned int V_37 ;
memset ( & V_86 , 0 , sizeof( struct V_85 ) ) ;
V_86 . type = 0x27 ;
V_86 . V_157 = 1 << 7 ;
V_86 . V_103 = V_163 ;
F_68 ( V_19 -> V_5 , & V_86 , & V_37 , 0 ) ;
V_161 = V_41 ;
V_72 = F_63 ( V_19 ,
& V_86 ,
5 ,
0 ,
0 ,
0 ,
V_37 ) ;
F_39 ( V_95 L_33 ,
F_75 ( V_41 - V_161 ) ) ;
if ( V_72 )
F_5 ( & V_19 -> V_5 -> V_2 -> V_10 ,
L_34 ) ;
return V_72 ;
}
static int F_40 ( struct V_44 * V_19 , T_6 V_182 , T_1 * V_155 ,
T_5 V_183 , unsigned int V_184 )
{
struct V_85 V_86 ;
memset ( & V_86 , 0 , sizeof( struct V_85 ) ) ;
V_86 . type = 0x27 ;
V_86 . V_157 = 1 << 7 ;
V_86 . V_103 = V_185 ;
V_86 . V_186 = V_184 & 0xFF ;
V_86 . V_187 = ( V_184 >> 8 ) & 0xFF ;
V_86 . V_188 = V_182 ;
V_86 . V_189 = 0 ;
V_86 . V_190 = V_191 ;
memset ( V_155 , 0 , V_184 * V_192 ) ;
return F_63 ( V_19 ,
& V_86 ,
5 ,
V_183 ,
V_184 * V_192 ,
0 ,
V_179 ) ;
}
static int F_76 ( struct V_44 * V_19 , T_6 * V_155 ,
T_5 V_183 )
{
struct V_85 V_86 ;
memset ( & V_86 , 0 , sizeof( struct V_85 ) ) ;
V_86 . type = 0x27 ;
V_86 . V_157 = 1 << 7 ;
V_86 . V_103 = V_172 ;
V_86 . V_142 = 0xD0 ;
V_86 . V_186 = 1 ;
V_86 . V_189 = 0x4F ;
V_86 . V_193 = 0xC2 ;
V_86 . V_190 = V_191 ;
return F_63 ( V_19 ,
& V_86 ,
5 ,
V_183 ,
V_192 ,
0 ,
15000 ) ;
}
static int F_77 ( struct V_44 * V_19 , unsigned int V_194 ,
struct V_195 * V_196 )
{
int V_72 , V_55 ;
struct V_195 * V_197 ;
if ( ! V_196 )
return - V_198 ;
if ( ! V_19 -> V_176 ) {
F_5 ( & V_19 -> V_5 -> V_2 -> V_10 , L_35 ) ;
return - V_199 ;
}
if ( ! ( V_19 -> V_171 [ 82 ] & 0x1 ) ) {
F_5 ( & V_19 -> V_5 -> V_2 -> V_10 , L_36 ) ;
return - V_199 ;
}
if ( ! ( V_19 -> V_171 [ 85 ] & 0x1 ) ) {
F_5 ( & V_19 -> V_5 -> V_2 -> V_10 , L_37 ) ;
return - V_199 ;
}
memset ( V_19 -> V_200 , 0 , V_192 ) ;
V_72 = F_76 ( V_19 , V_19 -> V_200 , V_19 -> V_201 ) ;
if ( V_72 ) {
F_5 ( & V_19 -> V_5 -> V_2 -> V_10 , L_38 ) ;
return V_72 ;
}
V_197 = (struct V_195 * ) ( V_19 -> V_200 + 2 ) ;
for ( V_55 = 0 ; V_55 < 29 ; V_55 ++ , V_197 ++ )
if ( V_197 -> V_202 == V_194 ) {
memcpy ( V_196 , V_197 , sizeof( struct V_195 ) ) ;
break;
}
if ( V_55 == 29 ) {
F_5 ( & V_19 -> V_5 -> V_2 -> V_10 ,
L_39 ) ;
V_72 = - V_198 ;
}
return V_72 ;
}
static int F_78 ( struct V_4 * V_5 , unsigned int V_203 ,
unsigned int V_169 )
{
int V_55 , V_72 = 0 ;
T_8 V_204 , V_205 , V_206 ;
struct V_207 * V_89 ;
T_5 V_208 ;
struct V_85 V_86 ;
if ( ! V_169 || V_5 -> V_181 == false )
return - V_198 ;
F_79 ( V_169 > ( V_209 * V_210 ) ) ;
F_79 ( V_169 % 8 != 0 ) ;
F_79 ( sizeof( struct V_211 ) > V_192 ) ;
V_89 = F_80 ( & V_5 -> V_2 -> V_10 , V_192 , & V_208 ,
V_212 ) ;
if ( ! V_89 )
return - V_213 ;
memset ( V_89 , 0 , V_192 ) ;
for ( V_55 = 0 , V_206 = V_169 , V_204 = V_203 ;
V_55 < V_210 && V_206 ;
V_55 ++ ) {
V_205 = ( V_206 >= V_209 ?
V_209 :
V_206 ) ;
V_89 [ V_55 ] . V_203 = V_28 F_9 ( V_204 ) ;
V_89 [ V_55 ] . V_214 = V_28 F_81 ( V_205 ) ;
V_204 += V_205 ;
V_206 -= V_205 ;
}
F_79 ( V_206 != 0 ) ;
memset ( & V_86 , 0 , sizeof( struct V_85 ) ) ;
V_86 . type = 0x27 ;
V_86 . V_157 = 1 << 7 ;
V_86 . V_103 = 0xfb ;
V_86 . V_142 = 0x60 ;
V_86 . V_186 = 1 ;
V_86 . V_190 = V_191 ;
if ( F_63 ( V_5 -> V_19 ,
& V_86 ,
5 ,
V_208 ,
V_192 ,
0 ,
V_215 ) < 0 )
V_72 = - V_165 ;
F_82 ( & V_5 -> V_2 -> V_10 , V_192 , V_89 , V_208 ) ;
return V_72 ;
}
static bool F_83 ( struct V_4 * V_5 , T_9 * V_184 )
{
struct V_44 * V_19 = V_5 -> V_19 ;
T_8 V_216 , V_217 , V_218 , V_219 , V_220 ;
V_217 = V_19 -> V_171 [ 100 ] ;
V_218 = V_19 -> V_171 [ 101 ] ;
V_219 = V_19 -> V_171 [ 102 ] ;
V_220 = V_19 -> V_171 [ 103 ] ;
V_216 = V_217 | V_218 << 16 | V_219 << 32 | V_220 << 48 ;
* V_184 = V_216 ;
return ( bool ) ! ! V_19 -> V_176 ;
}
static void F_84 ( struct V_44 * V_19 )
{
T_9 V_184 ;
unsigned short V_221 ;
char V_222 [ 42 ] ;
if ( ! V_19 -> V_176 )
return;
F_85 ( V_222 , ( char * ) ( V_19 -> V_171 + 10 ) , 21 ) ;
F_41 ( & V_19 -> V_5 -> V_2 -> V_10 ,
L_40 , V_222 ) ;
F_85 ( V_222 , ( char * ) ( V_19 -> V_171 + 23 ) , 9 ) ;
F_41 ( & V_19 -> V_5 -> V_2 -> V_10 ,
L_41 , V_222 ) ;
F_85 ( V_222 , ( char * ) ( V_19 -> V_171 + 27 ) , 41 ) ;
F_41 ( & V_19 -> V_5 -> V_2 -> V_10 , L_42 , V_222 ) ;
F_41 ( & V_19 -> V_5 -> V_2 -> V_10 , L_43 ,
V_19 -> V_171 [ 128 ] ,
V_19 -> V_171 [ 128 ] & 0x4 ? L_44 : L_45 ) ;
if ( F_83 ( V_19 -> V_5 , & V_184 ) )
F_41 ( & V_19 -> V_5 -> V_2 -> V_10 ,
L_46 ,
( T_8 ) V_184 ,
( ( T_8 ) V_184 ) * V_192 >> 20 ) ;
F_3 ( V_19 -> V_5 -> V_2 , V_223 , & V_221 ) ;
switch ( V_221 & 0xFF ) {
case 0x1 :
F_85 ( V_222 , L_47 , 3 ) ;
break;
case 0x3 :
F_85 ( V_222 , L_48 , 3 ) ;
break;
default:
F_85 ( V_222 , L_49 , 2 ) ;
break;
}
F_41 ( & V_19 -> V_5 -> V_2 -> V_10 ,
L_50 , V_222 ) ;
}
static inline void F_86 ( struct V_4 * V_5 ,
struct V_16 * V_103 ,
int V_224 )
{
int V_148 ;
unsigned int V_225 ;
struct V_226 * V_227 ;
struct V_228 * V_229 = V_103 -> V_229 ;
V_227 = V_103 -> V_103 + V_230 ;
for ( V_148 = 0 ; V_148 < V_224 ; V_148 ++ ) {
V_225 = F_87 ( V_229 ) ;
if ( V_225 > 0x400000 )
F_32 ( & V_5 -> V_2 -> V_10 ,
L_51 ) ;
V_227 -> V_231 = V_28
F_9 ( ( V_225 - 1 ) & 0x3FFFFF ) ;
V_227 -> V_232 = V_28
F_9 ( F_88 ( V_229 ) ) ;
V_227 -> V_233 = V_28
F_9 ( ( F_88 ( V_229 ) >> 16 ) >> 16 ) ;
V_227 ++ ;
V_229 ++ ;
}
}
static int F_89 ( struct V_44 * V_19 , T_6 * V_103 )
{
struct V_85 V_86 ;
struct V_85 * V_134 = ( V_19 -> V_136 + V_137 ) ;
unsigned int V_149 ;
memset ( & V_86 , 0 , sizeof( struct V_85 ) ) ;
V_86 . type = 0x27 ;
V_86 . V_157 = 1 << 7 ;
V_86 . V_103 = V_103 [ 0 ] ;
V_86 . V_142 = V_103 [ 1 ] ;
V_86 . V_186 = V_103 [ 2 ] ;
V_86 . V_234 = V_103 [ 3 ] ;
V_86 . V_235 = V_103 [ 4 ] ;
V_86 . V_236 = V_103 [ 5 ] ;
V_86 . V_190 = V_103 [ 6 ] & ~ 0x10 ;
F_68 ( V_19 -> V_5 , & V_86 , & V_149 , 0 ) ;
F_39 ( V_95 L_52 ,
V_11 ,
V_103 [ 0 ] ,
V_103 [ 1 ] ,
V_103 [ 2 ] ,
V_103 [ 3 ] ,
V_103 [ 4 ] ,
V_103 [ 5 ] ,
V_103 [ 6 ] ) ;
if ( F_63 ( V_19 ,
& V_86 ,
5 ,
0 ,
0 ,
0 ,
V_149 ) < 0 ) {
return - 1 ;
}
V_103 [ 0 ] = V_134 -> V_103 ;
V_103 [ 1 ] = V_134 -> V_142 ;
V_103 [ 4 ] = V_134 -> V_235 ;
V_103 [ 5 ] = V_134 -> V_236 ;
F_39 ( V_95 L_53 ,
V_11 ,
V_103 [ 0 ] ,
V_103 [ 1 ] ,
V_103 [ 4 ] ,
V_103 [ 5 ] ) ;
return 0 ;
}
static int F_90 ( struct V_44 * V_19 , T_6 * V_103 ,
void T_7 * V_174 )
{
struct V_85 V_86 ;
struct V_85 * V_134 ;
T_6 * V_89 = NULL ;
T_5 V_208 = 0 ;
int V_72 = 0 , V_237 = V_103 [ 3 ] ;
unsigned int V_149 ;
if ( V_237 ) {
if ( ! V_174 )
return - V_73 ;
V_89 = F_80 ( & V_19 -> V_5 -> V_2 -> V_10 ,
V_192 * V_237 ,
& V_208 ,
V_212 ) ;
if ( ! V_89 ) {
F_32 ( & V_19 -> V_5 -> V_2 -> V_10 ,
L_54 ,
V_192 * V_237 ) ;
return - V_213 ;
}
memset ( V_89 , 0 , V_192 * V_237 ) ;
}
memset ( & V_86 , 0 , sizeof( struct V_85 ) ) ;
V_86 . type = 0x27 ;
V_86 . V_157 = 1 << 7 ;
V_86 . V_103 = V_103 [ 0 ] ;
V_86 . V_142 = V_103 [ 2 ] ;
V_86 . V_186 = V_103 [ 3 ] ;
if ( V_86 . V_103 == V_172 ) {
V_86 . V_234 = V_103 [ 1 ] ;
V_86 . V_235 = 0x4F ;
V_86 . V_236 = 0xC2 ;
}
F_68 ( V_19 -> V_5 , & V_86 , & V_149 , 0 ) ;
if ( V_237 )
V_134 = ( V_19 -> V_136 + V_238 ) ;
else
V_134 = ( V_19 -> V_136 + V_137 ) ;
F_39 ( V_95
L_55
L_56 ,
V_11 ,
V_103 [ 0 ] ,
V_103 [ 1 ] ,
V_103 [ 2 ] ,
V_103 [ 3 ] ) ;
if ( F_63 ( V_19 ,
& V_86 ,
5 ,
( V_237 ? V_208 : 0 ) ,
( V_237 ? V_192 * V_237 : 0 ) ,
0 ,
V_149 )
< 0 ) {
V_72 = - V_73 ;
goto V_239;
}
V_103 [ 0 ] = V_134 -> V_103 ;
V_103 [ 1 ] = V_134 -> V_142 ;
V_103 [ 2 ] = V_134 -> V_186 ;
F_39 ( V_95
L_57
L_58 ,
V_11 ,
V_103 [ 0 ] ,
V_103 [ 1 ] ,
V_103 [ 2 ] ) ;
if ( V_237 ) {
if ( F_73 ( V_174 ,
V_89 ,
V_192 * V_103 [ 3 ] ) ) {
V_72 = - V_73 ;
goto V_239;
}
}
V_239:
if ( V_89 )
F_82 ( & V_19 -> V_5 -> V_2 -> V_10 ,
V_192 * V_237 , V_89 , V_208 ) ;
return V_72 ;
}
static unsigned int F_91 ( unsigned char V_103 ,
unsigned char V_142 )
{
unsigned int V_72 = 0 ;
switch ( V_103 ) {
case V_240 :
case V_241 :
case V_139 :
case V_144 :
case V_242 :
case V_243 :
case V_244 :
case V_245 :
V_72 = 1 ;
break;
case V_246 :
if ( V_142 == V_247 )
V_72 = 1 ;
break;
case V_172 :
if ( ( V_142 == V_248 ) ||
( V_142 == V_249 ) )
V_72 = 1 ;
break;
case V_250 :
if ( ( V_142 == V_251 ) ||
( V_142 == V_252 ) )
V_72 = 1 ;
break;
}
return V_72 ;
}
static int F_92 ( struct V_4 * V_5 ,
void T_7 * V_89 ,
T_10 * V_253 ,
int V_254 )
{
struct V_85 V_86 ;
struct V_85 * V_134 ;
T_6 * V_255 = NULL ;
T_6 * V_256 = NULL ;
T_5 V_257 = 0 ;
T_5 V_258 = 0 ;
T_5 V_259 = 0 ;
int V_260 = 0 ;
unsigned int V_261 = 0 ;
unsigned int V_262 = 0 ;
T_6 V_263 = 0 ;
unsigned int V_37 ;
unsigned int V_264 ;
unsigned int V_265 ;
unsigned long V_135 ;
int V_266 = V_254 + V_253 -> V_267 ;
int V_170 = 0 ;
V_262 = V_253 -> V_267 ;
V_261 = V_253 -> V_268 ;
if ( V_261 > 130560 || V_262 > 130560 )
return - V_198 ;
if ( V_262 ) {
V_255 = F_93 ( V_89 + V_254 , V_262 ) ;
if ( F_12 ( V_255 ) )
return F_94 ( V_255 ) ;
V_257 = F_95 ( V_5 -> V_2 ,
V_255 ,
V_262 ,
V_269 ) ;
if ( F_96 ( V_5 -> V_2 , V_257 ) ) {
V_260 = - V_213 ;
goto abort;
}
V_259 = V_257 ;
}
if ( V_261 ) {
V_256 = F_93 ( V_89 + V_266 , V_261 ) ;
if ( F_12 ( V_256 ) ) {
V_260 = F_94 ( V_256 ) ;
V_256 = NULL ;
goto abort;
}
V_258 = F_95 ( V_5 -> V_2 ,
V_256 ,
V_261 , V_270 ) ;
if ( F_96 ( V_5 -> V_2 , V_258 ) ) {
V_260 = - V_213 ;
goto abort;
}
V_259 = V_258 ;
}
switch ( V_253 -> V_271 ) {
case V_272 :
V_263 = V_262 / V_192 ;
V_134 = ( V_5 -> V_19 -> V_136 + V_238 ) ;
break;
case V_273 :
V_134 = ( V_5 -> V_19 -> V_136 + V_238 ) ;
break;
case V_274 :
V_134 = ( V_5 -> V_19 -> V_136 + V_137 ) ;
break;
default:
V_260 = - V_198 ;
goto abort;
}
memset ( & V_86 , 0 , sizeof( struct V_85 ) ) ;
V_86 . type = 0x27 ;
V_86 . V_157 = 1 << 7 ;
V_86 . V_103 = V_253 -> V_275 [ 7 ] ;
V_86 . V_142 = V_253 -> V_275 [ 1 ] ;
V_86 . V_186 = V_253 -> V_275 [ 2 ] ;
V_86 . V_188 = V_253 -> V_275 [ 3 ] ;
V_86 . V_189 = V_253 -> V_275 [ 4 ] ;
V_86 . V_193 = V_253 -> V_275 [ 5 ] ;
V_86 . V_190 = V_253 -> V_275 [ 6 ] & ~ 0x10 ;
if ( ( V_253 -> V_276 . V_277 == 0 ) && ( V_253 -> V_278 . V_277 & 1 ) ) {
V_253 -> V_276 . V_277 =
V_279 |
( V_280 << 8 ) ;
V_86 . V_281 = V_253 -> V_282 [ 3 ] ;
V_86 . V_283 = V_253 -> V_282 [ 4 ] ;
V_86 . V_284 = V_253 -> V_282 [ 5 ] ;
V_86 . V_285 = V_253 -> V_282 [ 1 ] ;
V_86 . V_187 = V_253 -> V_282 [ 2 ] ;
} else {
V_253 -> V_276 . V_277 = V_279 ;
}
V_264 = F_91 ( V_86 . V_103 , V_86 . V_142 ) ;
if ( ( V_261 || V_262 ) && ( ! V_86 . V_186 ) ) {
if ( V_263 )
V_86 . V_186 = V_263 ;
else {
if ( ! V_264 ) {
F_5 ( & V_5 -> V_2 -> V_10 ,
L_59
L_60 ) ;
V_260 = - V_198 ;
goto abort;
}
}
}
F_39 ( V_95
L_61
L_62
L_63 ,
V_11 ,
V_86 . V_103 ,
V_86 . V_142 ,
V_86 . V_186 ,
V_86 . V_188 ,
V_86 . V_189 ,
V_86 . V_193 ,
V_86 . V_190 ) ;
if ( ( V_86 . V_103 == V_144 ) && V_255 &&
( V_255 [ 0 ] & V_286 ) ) {
V_170 = 1 ;
}
F_68 ( V_5 , & V_86 , & V_37 , V_170 ) ;
if ( V_264 )
V_265 = V_192 ;
else
V_265 = V_192 * V_86 . V_186 ;
if ( F_63 ( V_5 -> V_19 ,
& V_86 ,
5 ,
V_259 ,
V_265 ,
0 ,
V_37 ) < 0 ) {
V_260 = - V_165 ;
goto abort;
}
V_135 = F_17 ( V_5 -> V_19 -> V_39 + V_138 ) ;
if ( ( V_253 -> V_271 == V_273 ) && ! ( V_135 & 1 ) ) {
V_134 = V_5 -> V_19 -> V_136 + V_238 ;
V_253 -> V_275 [ 7 ] = V_134 -> V_287 ;
} else {
V_134 = V_5 -> V_19 -> V_136 + V_137 ;
V_253 -> V_275 [ 7 ] = V_134 -> V_103 ;
}
if ( V_258 )
F_97 ( V_5 -> V_2 , V_258 ,
V_261 , V_270 ) ;
if ( V_257 )
F_97 ( V_5 -> V_2 , V_257 ,
V_262 , V_269 ) ;
V_258 = 0 ;
V_257 = 0 ;
V_253 -> V_275 [ 1 ] = V_134 -> V_142 ;
V_253 -> V_275 [ 2 ] = V_134 -> V_186 ;
V_253 -> V_275 [ 3 ] = V_134 -> V_188 ;
V_253 -> V_275 [ 4 ] = V_134 -> V_189 ;
V_253 -> V_275 [ 5 ] = V_134 -> V_193 ;
V_253 -> V_275 [ 6 ] = V_134 -> V_190 ;
if ( V_253 -> V_278 . V_277 & 1 ) {
V_253 -> V_282 [ 3 ] = V_134 -> V_281 ;
V_253 -> V_282 [ 4 ] = V_134 -> V_283 ;
V_253 -> V_282 [ 5 ] = V_134 -> V_284 ;
V_253 -> V_282 [ 1 ] = V_134 -> V_285 ;
V_253 -> V_282 [ 2 ] = V_134 -> V_187 ;
}
F_39 ( V_95
L_64
L_65
L_66 ,
V_11 ,
V_253 -> V_275 [ 7 ] ,
V_253 -> V_275 [ 1 ] ,
V_253 -> V_275 [ 2 ] ,
V_253 -> V_275 [ 3 ] ,
V_253 -> V_275 [ 4 ] ,
V_253 -> V_275 [ 5 ] ,
V_253 -> V_275 [ 6 ] ) ;
if ( V_262 ) {
if ( F_73 ( V_89 + V_254 , V_255 , V_262 ) ) {
V_260 = - V_73 ;
goto abort;
}
}
if ( V_261 ) {
if ( F_73 ( V_89 + V_266 , V_256 , V_261 ) ) {
V_260 = - V_73 ;
goto abort;
}
}
abort:
if ( V_258 )
F_97 ( V_5 -> V_2 , V_258 ,
V_261 , V_270 ) ;
if ( V_257 )
F_97 ( V_5 -> V_2 , V_257 ,
V_262 , V_269 ) ;
F_98 ( V_255 ) ;
F_98 ( V_256 ) ;
return V_260 ;
}
static int F_99 ( struct V_4 * V_5 , unsigned int V_17 ,
unsigned long V_288 )
{
switch ( V_17 ) {
case V_289 :
{
if ( F_73 ( ( void T_7 * ) V_288 , V_5 -> V_19 -> V_171 ,
sizeof( T_1 ) * V_177 ) )
return - V_73 ;
break;
}
case V_290 :
{
T_6 V_291 [ 4 ] ;
if ( F_100 ( V_291 ,
( void T_7 * ) V_288 ,
sizeof( V_291 ) ) )
return - V_73 ;
if ( F_90 ( V_5 -> V_19 ,
V_291 ,
( void T_7 * ) ( V_288 + 4 ) ) )
return - V_165 ;
if ( F_73 ( ( void T_7 * ) V_288 ,
V_291 ,
sizeof( V_291 ) ) )
return - V_73 ;
break;
}
case V_292 :
{
T_6 V_291 [ 7 ] ;
if ( F_100 ( V_291 ,
( void T_7 * ) V_288 ,
sizeof( V_291 ) ) )
return - V_73 ;
if ( F_89 ( V_5 -> V_19 , V_291 ) )
return - V_165 ;
if ( F_73 ( ( void T_7 * ) V_288 ,
V_291 ,
sizeof( V_291 ) ) )
return - V_73 ;
break;
}
case V_293 : {
T_10 V_253 ;
int V_294 , V_254 ;
if ( F_100 ( & V_253 , ( void T_7 * ) V_288 ,
sizeof( V_253 ) ) )
return - V_73 ;
V_254 = sizeof( V_253 ) ;
V_294 = F_92 ( V_5 , ( void T_7 * ) V_288 ,
& V_253 , V_254 ) ;
if ( F_73 ( ( void T_7 * ) V_288 , & V_253 ,
sizeof( V_253 ) ) )
return - V_73 ;
return V_294 ;
}
default:
return - V_198 ;
}
return 0 ;
}
static void F_101 ( struct V_4 * V_5 , struct V_12 * V_13 ,
struct V_16 * V_103 , int V_224 ,
struct V_33 * V_34 )
{
struct V_85 * V_86 ;
struct V_44 * V_19 = V_5 -> V_19 ;
int V_295 = F_102 ( V_13 ) == V_296 ? V_270 : V_269 ;
T_8 V_161 = F_103 ( V_13 ) ;
unsigned int V_263 = F_104 ( V_13 ) ;
V_224 = F_105 ( & V_5 -> V_2 -> V_10 , V_103 -> V_229 , V_224 , V_295 ) ;
F_106 ( & V_19 -> V_26 ) ;
V_103 -> V_297 = V_224 ;
V_103 -> V_107 = V_298 ;
V_86 = V_103 -> V_103 ;
V_86 -> type = 0x27 ;
V_86 -> V_157 = 1 << 7 ;
if ( V_295 == V_270 )
V_86 -> V_103 = V_299 ;
else
V_86 -> V_103 = V_105 ;
V_86 -> V_188 = V_161 & 0xFF ;
V_86 -> V_189 = ( V_161 >> 8 ) & 0xFF ;
V_86 -> V_193 = ( V_161 >> 16 ) & 0xFF ;
V_86 -> V_281 = ( V_161 >> 24 ) & 0xFF ;
V_86 -> V_283 = ( V_161 >> 32 ) & 0xFF ;
V_86 -> V_284 = ( V_161 >> 40 ) & 0xFF ;
V_86 -> V_190 = 1 << 6 ;
V_86 -> V_142 = V_263 & 0xFF ;
V_86 -> V_285 = ( V_263 >> 8 ) & 0xFF ;
V_86 -> V_186 = ( ( V_13 -> V_22 << 3 ) | ( V_13 -> V_22 >> 5 ) ) ;
V_86 -> V_187 = 0 ;
V_86 -> V_287 = 0 ;
V_86 -> V_300 = 0 ;
V_86 -> V_301 = 0 ;
F_86 ( V_5 , V_103 , V_224 ) ;
if ( F_44 ( V_103 -> V_302 ) )
V_86 -> V_190 |= 1 << 7 ;
V_103 -> V_18 -> V_157 =
V_28 F_9 (
( V_224 << 16 ) | 5 | V_303 ) ;
V_103 -> V_18 -> V_304 = 0 ;
V_103 -> V_305 = V_295 ;
if ( F_44 ( V_19 -> V_26 & V_306 ) ) {
F_4 ( V_13 -> V_22 , V_19 -> V_307 ) ;
F_4 ( V_151 , & V_19 -> V_26 ) ;
return;
}
F_21 ( V_19 , V_13 -> V_22 ) ;
}
static T_11 F_107 ( struct V_190 * V_10 ,
struct V_308 * V_309 ,
char * V_89 )
{
struct V_4 * V_5 = F_108 ( V_10 ) -> V_310 ;
int V_311 = 0 ;
if ( F_8 ( V_101 , & V_5 -> V_43 ) )
V_311 += sprintf ( V_89 , L_67 , L_68 ) ;
else if ( F_8 ( V_100 , & V_5 -> V_43 ) )
V_311 += sprintf ( V_89 , L_67 , L_69 ) ;
else
V_311 += sprintf ( V_89 , L_67 , L_70 ) ;
return V_311 ;
}
static T_11 F_109 ( struct V_312 * V_313 , char * V_89 )
{
int V_311 = 0 ;
struct V_4 * V_5 , * V_50 ;
unsigned long V_26 ;
char V_314 [ 42 ] ;
T_1 V_81 = 0 ;
F_110 ( & V_315 , V_26 ) ;
V_311 += sprintf ( & V_89 [ V_311 ] , L_71 ) ;
F_111 (dd, tmp, &online_list, online_list) {
if ( V_5 -> V_2 ) {
if ( V_5 -> V_19 &&
V_5 -> V_19 -> V_171 &&
V_5 -> V_19 -> V_176 ) {
F_85 ( V_314 ,
( char * ) ( V_5 -> V_19 -> V_171 + 10 ) , 21 ) ;
V_81 = * ( V_5 -> V_19 -> V_171 + 141 ) ;
} else {
memset ( V_314 , 0 , 42 ) ;
V_81 = 0 ;
}
if ( V_5 -> V_19 &&
F_8 ( V_316 , & V_5 -> V_19 -> V_26 ) ) {
V_311 += sprintf ( & V_89 [ V_311 ] ,
L_72 ,
F_112 ( & V_5 -> V_2 -> V_10 ) ,
V_314 ,
V_81 ) ;
} else {
V_311 += sprintf ( & V_89 [ V_311 ] ,
L_73 ,
F_112 ( & V_5 -> V_2 -> V_10 ) ,
V_314 ) ;
}
}
}
V_311 += sprintf ( & V_89 [ V_311 ] , L_74 ) ;
F_111 (dd, tmp, &removing_list, remove_list) {
if ( V_5 -> V_2 ) {
if ( V_5 -> V_19 &&
V_5 -> V_19 -> V_171 &&
V_5 -> V_19 -> V_176 ) {
F_85 ( V_314 ,
( char * ) ( V_5 -> V_19 -> V_171 + 10 ) , 21 ) ;
V_81 = * ( V_5 -> V_19 -> V_171 + 141 ) ;
} else {
memset ( V_314 , 0 , 42 ) ;
V_81 = 0 ;
}
if ( V_5 -> V_19 &&
F_8 ( V_316 , & V_5 -> V_19 -> V_26 ) ) {
V_311 += sprintf ( & V_89 [ V_311 ] ,
L_72 ,
F_112 ( & V_5 -> V_2 -> V_10 ) ,
V_314 ,
V_81 ) ;
} else {
V_311 += sprintf ( & V_89 [ V_311 ] ,
L_73 ,
F_112 ( & V_5 -> V_2 -> V_10 ) ,
V_314 ) ;
}
}
}
F_113 ( & V_315 , V_26 ) ;
return V_311 ;
}
static T_11 F_114 ( struct V_317 * V_318 , char T_7 * V_319 ,
T_12 V_169 , T_13 * V_320 )
{
struct V_4 * V_5 = (struct V_4 * ) V_318 -> V_310 ;
int V_311 = * V_320 ;
char * V_89 ;
int V_72 = 0 ;
if ( ! V_169 || * V_320 )
return 0 ;
V_89 = F_115 ( V_321 , V_212 ) ;
if ( ! V_89 ) {
F_32 ( & V_5 -> V_2 -> V_10 ,
L_75 ) ;
return - V_213 ;
}
V_311 += F_109 ( NULL , V_89 ) ;
* V_320 = V_311 <= V_169 ? V_311 : V_169 ;
V_311 = F_73 ( V_319 , V_89 , * V_320 ) ;
if ( V_311 )
V_72 = - V_73 ;
F_98 ( V_89 ) ;
return V_72 ? V_72 : * V_320 ;
}
static T_11 F_116 ( struct V_317 * V_318 , char T_7 * V_319 ,
T_12 V_169 , T_13 * V_320 )
{
struct V_4 * V_5 = (struct V_4 * ) V_318 -> V_310 ;
char * V_89 ;
T_2 V_322 ;
int V_311 = * V_320 ;
int V_148 , V_72 = 0 ;
if ( ! V_169 || V_311 )
return 0 ;
V_89 = F_115 ( V_321 , V_212 ) ;
if ( ! V_89 ) {
F_32 ( & V_5 -> V_2 -> V_10 ,
L_76 ) ;
return - V_213 ;
}
V_311 += sprintf ( & V_89 [ V_311 ] , L_77 ) ;
for ( V_148 = V_5 -> V_64 - 1 ; V_148 >= 0 ; V_148 -- )
V_311 += sprintf ( & V_89 [ V_311 ] , L_78 ,
F_17 ( V_5 -> V_19 -> V_47 [ V_148 ] ) ) ;
V_311 += sprintf ( & V_89 [ V_311 ] , L_79 ) ;
V_311 += sprintf ( & V_89 [ V_311 ] , L_80 ) ;
for ( V_148 = V_5 -> V_64 - 1 ; V_148 >= 0 ; V_148 -- )
V_311 += sprintf ( & V_89 [ V_311 ] , L_78 ,
F_17 ( V_5 -> V_19 -> V_48 [ V_148 ] ) ) ;
V_311 += sprintf ( & V_89 [ V_311 ] , L_79 ) ;
V_311 += sprintf ( & V_89 [ V_311 ] , L_81 ) ;
for ( V_148 = V_5 -> V_64 - 1 ; V_148 >= 0 ; V_148 -- )
V_311 += sprintf ( & V_89 [ V_311 ] , L_78 ,
F_17 ( V_5 -> V_19 -> V_65 [ V_148 ] ) ) ;
V_311 += sprintf ( & V_89 [ V_311 ] , L_79 ) ;
V_311 += sprintf ( & V_89 [ V_311 ] , L_82 ,
F_17 ( V_5 -> V_19 -> V_39 + V_66 ) ) ;
V_311 += sprintf ( & V_89 [ V_311 ] , L_83 ,
F_17 ( V_5 -> V_39 + V_67 ) ) ;
V_311 += sprintf ( & V_89 [ V_311 ] , L_84 ) ;
V_311 += sprintf ( & V_89 [ V_311 ] , L_85 ) ;
for ( V_148 = V_5 -> V_64 - 1 ; V_148 >= 0 ; V_148 -- ) {
if ( sizeof( long ) > sizeof( T_2 ) )
V_322 =
V_5 -> V_19 -> V_307 [ V_148 / 2 ] >> ( 32 * ( V_148 & 1 ) ) ;
else
V_322 = V_5 -> V_19 -> V_307 [ V_148 ] ;
V_311 += sprintf ( & V_89 [ V_311 ] , L_78 , V_322 ) ;
}
V_311 += sprintf ( & V_89 [ V_311 ] , L_79 ) ;
* V_320 = V_311 <= V_169 ? V_311 : V_169 ;
V_311 = F_73 ( V_319 , V_89 , * V_320 ) ;
if ( V_311 )
V_72 = - V_73 ;
F_98 ( V_89 ) ;
return V_72 ? V_72 : * V_320 ;
}
static T_11 F_117 ( struct V_317 * V_318 , char T_7 * V_319 ,
T_12 V_169 , T_13 * V_320 )
{
struct V_4 * V_5 = (struct V_4 * ) V_318 -> V_310 ;
char * V_89 ;
int V_311 = * V_320 ;
int V_72 = 0 ;
if ( ! V_169 || V_311 )
return 0 ;
V_89 = F_115 ( V_321 , V_212 ) ;
if ( ! V_89 ) {
F_32 ( & V_5 -> V_2 -> V_10 ,
L_86 ) ;
return - V_213 ;
}
V_311 += sprintf ( & V_89 [ V_311 ] , L_87 ,
V_5 -> V_19 -> V_26 ) ;
V_311 += sprintf ( & V_89 [ V_311 ] , L_88 ,
V_5 -> V_43 ) ;
* V_320 = V_311 <= V_169 ? V_311 : V_169 ;
V_311 = F_73 ( V_319 , V_89 , * V_320 ) ;
if ( V_311 )
V_72 = - V_73 ;
F_98 ( V_89 ) ;
return V_72 ? V_72 : * V_320 ;
}
static int F_118 ( struct V_4 * V_5 , struct V_323 * V_324 )
{
if ( ! V_324 || ! V_5 )
return - V_198 ;
if ( F_119 ( V_324 , & V_325 . V_309 ) )
F_5 ( & V_5 -> V_2 -> V_10 ,
L_89 ) ;
return 0 ;
}
static int F_120 ( struct V_4 * V_5 , struct V_323 * V_324 )
{
if ( ! V_324 || ! V_5 )
return - V_198 ;
F_121 ( V_324 , & V_325 . V_309 ) ;
return 0 ;
}
static int F_122 ( struct V_4 * V_5 )
{
if ( ! V_326 )
return - 1 ;
V_5 -> V_327 = F_123 ( V_5 -> V_328 -> V_329 , V_326 ) ;
if ( F_124 ( V_5 -> V_327 ) ) {
F_5 ( & V_5 -> V_2 -> V_10 ,
L_90 ,
V_5 -> V_328 -> V_329 ) ;
V_5 -> V_327 = NULL ;
return - 1 ;
}
F_125 ( L_91 , V_330 , V_5 -> V_327 , V_5 ,
& V_331 ) ;
F_125 ( L_92 , V_330 , V_5 -> V_327 , V_5 ,
& V_332 ) ;
return 0 ;
}
static void F_126 ( struct V_4 * V_5 )
{
if ( V_5 -> V_327 )
F_127 ( V_5 -> V_327 ) ;
}
static inline void F_128 ( struct V_4 * V_5 )
{
T_2 V_333 ;
V_333 = F_17 ( V_5 -> V_39 + V_334 ) ;
F_16 ( V_333 |
V_335 |
V_336 ,
V_5 -> V_39 + V_334 ) ;
}
static int F_129 ( struct V_4 * V_5 )
{
return ( V_5 -> V_2 -> V_190 == V_337 ? 1 : 0 ) ;
}
static void F_130 ( struct V_4 * V_5 )
{
T_2 V_333 ;
unsigned int V_338 , V_339 ;
V_333 = F_17 ( V_5 -> V_39 + V_334 ) ;
V_5 -> V_340 = V_341 ;
V_5 -> V_64 = 1 ;
if ( V_333 & 0x8 ) {
V_5 -> V_340 = V_342 ;
V_338 = ( V_333 & V_343 ) >> 8 ;
V_339 = ( V_333 & V_344 ) + 1 ;
F_41 ( & V_5 -> V_2 -> V_10 ,
L_93
L_94 ,
V_338 ,
V_339 ,
V_339 * 32 ) ;
if ( V_339 > V_126 ) {
F_5 ( & V_5 -> V_2 -> V_10 ,
L_95
L_96 , V_126 ) ;
V_339 = V_126 ;
}
V_5 -> V_64 = V_339 ;
return;
}
F_5 ( & V_5 -> V_2 -> V_10 , L_97 ) ;
}
static int F_131 ( struct V_4 * V_5 )
{
unsigned long V_37 , V_77 = 0 , V_161 ;
F_5 ( & V_5 -> V_2 -> V_10 ,
L_98 ) ;
V_161 = V_41 ;
V_37 = V_41 + F_18 ( V_345 ) ;
do {
if ( F_44 ( F_8 ( V_42 ,
& V_5 -> V_43 ) ) )
return - V_73 ;
if ( F_1 ( V_5 -> V_2 ) )
return - V_73 ;
if ( F_69 ( V_5 -> V_19 , NULL ) < 0 )
return - V_73 ;
if ( * ( V_5 -> V_19 -> V_171 + V_346 ) ==
V_347 ) {
F_132 ( 1 ) ;
if ( V_77 ++ >= 180 ) {
F_5 ( & V_5 -> V_2 -> V_10 ,
L_99 ,
F_75 ( V_41 - V_161 ) / 1000 ) ;
V_77 = 0 ;
}
} else {
F_5 ( & V_5 -> V_2 -> V_10 ,
L_100 ,
F_75 ( V_41 - V_161 ) / 1000 ) ;
F_133 ( V_5 ) ;
return 0 ;
}
} while ( F_20 ( V_41 , V_37 ) );
F_32 ( & V_5 -> V_2 -> V_10 ,
L_101 ,
F_75 ( V_41 - V_161 ) / 1000 ) ;
return - V_73 ;
}
static void F_134 ( struct V_12 * V_13 )
{
struct V_16 * V_17 = F_7 ( V_13 ) ;
struct V_4 * V_5 = V_13 -> V_14 -> V_15 ;
F_135 ( & V_5 -> V_2 -> V_10 , V_17 -> V_229 , V_17 -> V_297 ,
V_17 -> V_305 ) ;
if ( F_44 ( V_17 -> V_302 ) )
F_136 ( & V_5 -> V_19 -> V_348 ) ;
F_137 ( V_13 , V_17 -> V_81 ) ;
}
static void F_138 ( struct V_12 * V_82 , void * V_117 ,
bool V_349 )
{
struct V_16 * V_17 = F_7 ( V_82 ) ;
struct V_4 * V_5 = V_117 ;
if ( ! F_139 ( V_82 ) )
return;
F_39 ( V_95 L_102 , V_82 -> V_22 ) ;
F_57 ( V_82 -> V_22 , V_5 -> V_19 -> V_307 ) ;
V_17 -> V_81 = V_96 ;
F_134 ( V_82 ) ;
}
static void F_140 ( struct V_12 * V_82 , void * V_117 ,
bool V_349 )
{
struct V_4 * V_5 = V_117 ;
if ( ! F_139 ( V_82 ) )
return;
F_4 ( V_82 -> V_22 , V_5 -> V_19 -> V_307 ) ;
F_141 ( V_82 ) ;
}
static int F_142 ( void * V_117 )
{
struct V_4 * V_5 = (struct V_4 * ) V_117 ;
unsigned long V_350 , V_351 , V_352 , V_149 ;
unsigned int V_353 = V_5 -> V_64 * 32 ;
struct V_44 * V_19 = V_5 -> V_19 ;
while ( 1 ) {
if ( F_143 () ||
F_8 ( V_354 , & V_19 -> V_26 ) )
goto V_355;
F_57 ( V_150 , & V_19 -> V_26 ) ;
F_144 ( V_19 -> V_116 , ( V_19 -> V_26 ) &&
( V_19 -> V_26 & V_356 ) ) ;
if ( F_143 () ||
F_8 ( V_354 , & V_19 -> V_26 ) )
goto V_355;
if ( F_44 ( F_8 ( V_42 ,
& V_5 -> V_43 ) ) )
goto V_355;
F_4 ( V_150 , & V_19 -> V_26 ) ;
V_357:
if ( F_8 ( V_115 , & V_19 -> V_26 ) ) {
F_38 ( V_5 ) ;
F_57 ( V_115 , & V_19 -> V_26 ) ;
}
if ( F_8 ( V_115 , & V_19 -> V_26 ) )
goto V_357;
if ( F_8 ( V_358 , & V_19 -> V_26 ) ) {
V_149 = V_41 + F_18 ( 5000 ) ;
do {
F_19 ( 100 ) ;
} while ( F_51 ( & V_5 -> V_108 ) != 0 &&
F_20 ( V_41 , V_149 ) );
if ( F_51 ( & V_5 -> V_108 ) != 0 )
F_5 ( & V_5 -> V_2 -> V_10 ,
L_103 ) ;
F_60 ( V_5 -> V_7 ) ;
F_22 ( V_5 -> V_7 -> V_359 ) ;
F_145 ( & V_5 -> V_36 ,
F_140 , V_5 ) ;
F_25 ( V_5 -> V_7 -> V_359 ) ;
F_4 ( V_151 , & V_5 -> V_19 -> V_26 ) ;
if ( F_33 ( V_5 ) )
F_145 ( & V_5 -> V_36 ,
F_138 , V_5 ) ;
F_57 ( V_358 , & V_5 -> V_19 -> V_26 ) ;
F_62 ( V_5 -> V_7 ) ;
}
if ( F_8 ( V_151 , & V_19 -> V_26 ) ) {
V_350 = 1 ;
V_351 = V_353 ;
V_352 = 0 ;
while ( 1 ) {
V_350 = F_146 ( V_19 -> V_307 ,
V_353 , V_350 ) ;
if ( V_352 == 1 ) {
if ( ( V_351 >= V_350 ) ||
( V_350 >= V_353 ) )
break;
}
if ( F_44 ( V_351 == V_353 ) )
V_351 = V_350 ;
if ( F_44 ( V_350 == V_353 ) ) {
V_350 = 1 ;
V_352 = 1 ;
continue;
}
F_21 ( V_19 , V_350 ) ;
F_57 ( V_350 , V_19 -> V_307 ) ;
}
F_57 ( V_151 , & V_19 -> V_26 ) ;
}
if ( F_8 ( V_316 , & V_19 -> V_26 ) ) {
if ( F_131 ( V_5 ) == 0 )
F_57 ( V_316 , & V_19 -> V_26 ) ;
}
}
V_355:
return 0 ;
}
static void F_147 ( struct V_4 * V_5 )
{
struct V_44 * V_19 = V_5 -> V_19 ;
if ( V_19 -> V_360 )
F_82 ( & V_5 -> V_2 -> V_10 , V_361 ,
V_19 -> V_360 , V_19 -> V_362 ) ;
if ( V_19 -> V_20 ) {
F_82 ( & V_5 -> V_2 -> V_10 , V_363 ,
V_19 -> V_20 , V_19 -> V_24 ) ;
}
}
static int F_148 ( struct V_4 * V_5 )
{
struct V_44 * V_19 = V_5 -> V_19 ;
V_19 -> V_360 =
F_80 ( & V_5 -> V_2 -> V_10 , V_361 ,
& V_19 -> V_362 , V_212 ) ;
if ( ! V_19 -> V_360 )
return - V_213 ;
memset ( V_19 -> V_360 , 0 , V_361 ) ;
V_19 -> V_20 =
F_80 ( & V_5 -> V_2 -> V_10 , V_363 ,
& V_19 -> V_24 , V_212 ) ;
if ( ! V_19 -> V_20 ) {
F_82 ( & V_5 -> V_2 -> V_10 , V_361 ,
V_19 -> V_360 , V_19 -> V_362 ) ;
V_19 -> V_360 = NULL ;
V_19 -> V_362 = 0 ;
return - V_213 ;
}
memset ( V_19 -> V_20 , 0 , V_363 ) ;
V_19 -> V_136 = V_19 -> V_360 + V_364 ;
V_19 -> V_59 = V_19 -> V_362 + V_364 ;
V_19 -> V_171 = V_19 -> V_360 + V_365 ;
V_19 -> V_178 = V_19 -> V_362 + V_365 ;
V_19 -> V_98 = V_19 -> V_360 + V_366 ;
V_19 -> V_99 = V_19 -> V_362 + V_366 ;
V_19 -> V_200 = V_19 -> V_360 + V_367 ;
V_19 -> V_201 = V_19 -> V_362 + V_367 ;
return 0 ;
}
static int F_149 ( struct V_4 * V_5 )
{
struct V_195 V_368 ;
unsigned char * V_89 ;
int V_72 ;
if ( F_69 ( V_5 -> V_19 , NULL ) < 0 )
return - V_73 ;
if ( * ( V_5 -> V_19 -> V_171 + V_346 ) ==
V_347 ) {
F_4 ( V_316 , & V_5 -> V_19 -> V_26 ) ;
return V_347 ;
}
F_84 ( V_5 -> V_19 ) ;
V_72 = F_40 ( V_5 -> V_19 , V_97 ,
V_5 -> V_19 -> V_98 ,
V_5 -> V_19 -> V_99 , 1 ) ;
if ( V_72 ) {
F_5 ( & V_5 -> V_2 -> V_10 ,
L_12 ) ;
} else {
V_89 = ( unsigned char * ) V_5 -> V_19 -> V_98 ;
if ( V_89 [ 259 ] & 0x1 ) {
F_41 ( & V_5 -> V_2 -> V_10 ,
L_13 ) ;
F_4 ( V_100 , & V_5 -> V_43 ) ;
}
if ( V_89 [ 288 ] == 0xF7 ) {
F_41 ( & V_5 -> V_2 -> V_10 ,
L_15 ) ;
F_4 ( V_101 , & V_5 -> V_43 ) ;
}
if ( V_89 [ 288 ] == 0xBF ) {
F_41 ( & V_5 -> V_2 -> V_10 ,
L_104 ) ;
F_4 ( V_102 , & V_5 -> V_43 ) ;
}
}
memset ( & V_368 , 0 , sizeof( struct V_195 ) ) ;
if ( F_77 ( V_5 -> V_19 , 242 , & V_368 ) )
F_5 ( & V_5 -> V_2 -> V_10 ,
L_105 ) ;
else
F_41 ( & V_5 -> V_2 -> V_10 ,
L_106 ,
V_368 . V_369 , F_150 ( V_368 . V_117 ) ) ;
return V_72 ;
}
static int F_151 ( struct V_4 * V_5 )
{
int V_55 ;
int V_72 ;
unsigned int V_370 ;
unsigned long V_37 , V_371 ;
V_5 -> V_39 = F_152 ( V_5 -> V_2 ) [ V_372 ] ;
F_130 ( V_5 ) ;
if ( V_5 -> V_340 == V_341 ) {
V_72 = - V_165 ;
goto V_373;
}
V_370 = V_5 -> V_64 * 32 ;
F_128 ( V_5 ) ;
V_5 -> V_19 = F_153 ( sizeof( struct V_44 ) , V_212 ,
V_5 -> V_374 ) ;
if ( ! V_5 -> V_19 ) {
F_32 ( & V_5 -> V_2 -> V_10 ,
L_107 ) ;
return - V_213 ;
}
for ( V_55 = 0 ; V_55 < V_126 ; V_55 ++ )
V_5 -> V_127 [ V_55 ] . V_19 = V_5 -> V_19 ;
if ( F_129 ( V_5 ) )
V_5 -> V_375 = V_376 ;
else
V_5 -> V_375 = 0 ;
F_154 ( & V_5 -> V_19 -> V_348 , V_5 -> V_375 ) ;
for ( V_55 = 0 ; V_55 < V_126 ; V_55 ++ )
F_155 ( & V_5 -> V_19 -> V_46 [ V_55 ] ) ;
V_5 -> V_19 -> V_39 = V_5 -> V_39 + V_377 ;
V_5 -> V_19 -> V_5 = V_5 ;
V_72 = F_148 ( V_5 ) ;
if ( V_72 < 0 )
goto V_373;
for ( V_55 = 0 ; V_55 < V_5 -> V_64 ; V_55 ++ ) {
V_5 -> V_19 -> V_47 [ V_55 ] =
V_5 -> V_19 -> V_39 + V_55 * 0x80 + V_378 ;
V_5 -> V_19 -> V_48 [ V_55 ] =
V_5 -> V_19 -> V_39 + V_55 * 0x80 + V_379 ;
V_5 -> V_19 -> V_65 [ V_55 ] =
V_5 -> V_19 -> V_39 + V_55 * 0x80 + V_380 ;
}
V_371 = V_41 ;
V_37 = V_41 + F_18 ( 30000 ) ;
while ( ( ( F_17 ( V_5 -> V_19 -> V_39 + V_71 ) & 0x0F ) != 0x03 ) &&
F_20 ( V_41 , V_37 ) ) {
F_19 ( 100 ) ;
}
if ( F_44 ( F_1 ( V_5 -> V_2 ) ) ) {
V_371 = V_41 - V_371 ;
F_5 ( & V_5 -> V_2 -> V_10 ,
L_108 ,
F_75 ( V_371 ) ) ;
V_72 = - V_381 ;
goto V_382 ;
}
if ( F_44 ( F_8 ( V_42 , & V_5 -> V_43 ) ) ) {
V_371 = V_41 - V_371 ;
F_5 ( & V_5 -> V_2 -> V_10 ,
L_109 ,
F_75 ( V_371 ) ) ;
V_72 = - V_73 ;
goto V_382;
}
if ( ! ( F_17 ( V_5 -> V_39 + V_56 ) & V_383 ) ) {
if ( F_15 ( V_5 ) < 0 ) {
F_32 ( & V_5 -> V_2 -> V_10 ,
L_110 ) ;
V_72 = - V_165 ;
goto V_382;
}
} else {
F_16 ( F_17 ( V_5 -> V_39 + V_67 ) ,
V_5 -> V_39 + V_67 ) ;
}
F_30 ( V_5 -> V_19 ) ;
F_28 ( V_5 -> V_19 ) ;
V_72 = F_156 ( & V_5 -> V_2 -> V_10 ,
V_5 -> V_2 -> V_132 ,
F_54 ,
V_384 ,
F_157 ( & V_5 -> V_2 -> V_10 ) ,
V_5 ) ;
if ( V_72 ) {
F_32 ( & V_5 -> V_2 -> V_10 ,
L_111 , V_5 -> V_2 -> V_132 ) ;
goto V_382;
}
F_158 ( V_5 -> V_2 -> V_132 , F_159 ( V_5 -> V_385 ) ) ;
F_16 ( F_17 ( V_5 -> V_39 + V_40 ) | V_74 ,
V_5 -> V_39 + V_40 ) ;
F_160 ( & V_5 -> V_19 -> V_116 ) ;
if ( F_8 ( V_42 , & V_5 -> V_43 ) ) {
V_72 = - V_73 ;
goto V_386;
}
return V_72 ;
V_386:
F_16 ( F_17 ( V_5 -> V_39 + V_40 ) & ~ V_74 ,
V_5 -> V_39 + V_40 ) ;
F_158 ( V_5 -> V_2 -> V_132 , NULL ) ;
F_161 ( & V_5 -> V_2 -> V_10 , V_5 -> V_2 -> V_132 , V_5 ) ;
V_382:
F_29 ( V_5 -> V_19 ) ;
F_147 ( V_5 ) ;
V_373:
F_98 ( V_5 -> V_19 ) ;
return V_72 ;
}
static int F_162 ( struct V_4 * V_5 )
{
int V_72 = 0 ;
if ( V_5 -> V_6 || ! V_5 -> V_19 )
return - V_381 ;
if ( ! F_8 ( V_316 , & V_5 -> V_19 -> V_26 ) &&
! F_8 ( V_102 , & V_5 -> V_43 ) &&
! F_8 ( V_145 , & V_5 -> V_43 ) ) {
V_72 = F_74 ( V_5 -> V_19 ) ;
if ( V_72 )
F_5 ( & V_5 -> V_2 -> V_10 ,
L_112 ) ;
}
return V_72 ;
}
static int F_163 ( struct V_4 * V_5 )
{
if ( ! V_5 -> V_6 ) {
F_29 ( V_5 -> V_19 ) ;
F_16 ( F_17 ( V_5 -> V_39 + V_40 ) & ~ V_74 ,
V_5 -> V_39 + V_40 ) ;
}
F_158 ( V_5 -> V_2 -> V_132 , NULL ) ;
F_161 ( & V_5 -> V_2 -> V_10 , V_5 -> V_2 -> V_132 , V_5 ) ;
F_61 ( 1000 ) ;
F_147 ( V_5 ) ;
F_98 ( V_5 -> V_19 ) ;
V_5 -> V_19 = NULL ;
return 0 ;
}
static int F_164 ( struct V_4 * V_5 )
{
F_162 ( V_5 ) ;
return 0 ;
}
static int F_165 ( struct V_4 * V_5 )
{
if ( F_162 ( V_5 ) != 0 ) {
F_32 ( & V_5 -> V_2 -> V_10 ,
L_113 ) ;
return - V_73 ;
}
F_16 ( F_17 ( V_5 -> V_39 + V_40 ) & ~ V_74 ,
V_5 -> V_39 + V_40 ) ;
F_29 ( V_5 -> V_19 ) ;
return 0 ;
}
static int F_166 ( struct V_4 * V_5 )
{
F_128 ( V_5 ) ;
if ( F_15 ( V_5 ) != 0 ) {
F_32 ( & V_5 -> V_2 -> V_10 ,
L_114 ) ;
return - V_73 ;
}
F_30 ( V_5 -> V_19 ) ;
F_28 ( V_5 -> V_19 ) ;
F_16 ( F_17 ( V_5 -> V_39 + V_40 ) | V_74 ,
V_5 -> V_39 + V_40 ) ;
return 0 ;
}
static int F_167 ( char * V_387 ,
int V_388 ,
char * V_89 ,
int V_389 )
{
const int V_390 = 'z' - 'a' + 1 ;
char * V_391 = V_89 + strlen ( V_387 ) ;
char * V_392 = V_89 + V_389 ;
char * V_393 ;
int V_394 ;
V_393 = V_392 - 1 ;
* V_393 = '\0' ;
V_394 = V_390 ;
do {
if ( V_393 == V_391 )
return - V_198 ;
* -- V_393 = 'a' + ( V_388 % V_394 ) ;
V_388 = ( V_388 / V_394 ) - 1 ;
} while ( V_388 >= 0 );
memmove ( V_391 , V_393 , V_392 - V_393 ) ;
memcpy ( V_89 , V_387 , strlen ( V_387 ) ) ;
return 0 ;
}
static int F_168 ( struct V_395 * V_10 ,
T_14 V_396 ,
unsigned V_17 ,
unsigned long V_288 )
{
struct V_4 * V_5 = V_10 -> V_397 -> V_310 ;
if ( ! F_169 ( V_398 ) )
return - V_399 ;
if ( ! V_5 )
return - V_400 ;
if ( F_44 ( F_8 ( V_42 , & V_5 -> V_43 ) ) )
return - V_400 ;
switch ( V_17 ) {
case V_401 :
return - V_400 ;
default:
return F_99 ( V_5 , V_17 , V_288 ) ;
}
}
static int F_170 ( struct V_395 * V_10 ,
T_14 V_396 ,
unsigned V_17 ,
unsigned long V_288 )
{
struct V_4 * V_5 = V_10 -> V_397 -> V_310 ;
if ( ! F_169 ( V_398 ) )
return - V_399 ;
if ( ! V_5 )
return - V_400 ;
if ( F_44 ( F_8 ( V_42 , & V_5 -> V_43 ) ) )
return - V_400 ;
switch ( V_17 ) {
case V_401 :
return - V_400 ;
case V_293 : {
struct V_402 T_7 * V_403 ;
T_10 V_253 ;
int V_404 , V_254 , V_294 ;
V_404 =
sizeof( struct V_402 ) ;
V_403 =
(struct V_402 T_7 * ) V_288 ;
if ( F_100 ( & V_253 , ( void T_7 * ) V_288 ,
V_404 - ( 2 * sizeof( V_405 ) ) ) )
return - V_73 ;
if ( F_171 ( V_253 . V_267 , & V_403 -> V_267 ) )
return - V_73 ;
if ( F_171 ( V_253 . V_268 , & V_403 -> V_268 ) )
return - V_73 ;
V_254 = sizeof( struct V_402 ) ;
V_294 = F_92 ( V_5 , ( void T_7 * ) V_288 ,
& V_253 , V_254 ) ;
if ( F_73 ( ( void T_7 * ) V_288 , & V_253 ,
V_404 -
( 2 * sizeof( V_405 ) ) ) )
return - V_73 ;
if ( F_172 ( V_253 . V_267 , & V_403 -> V_267 ) )
return - V_73 ;
if ( F_172 ( V_253 . V_268 , & V_403 -> V_268 ) )
return - V_73 ;
return V_294 ;
}
default:
return F_99 ( V_5 , V_17 , V_288 ) ;
}
}
static int F_173 ( struct V_395 * V_10 ,
struct V_406 * V_407 )
{
struct V_4 * V_5 = V_10 -> V_397 -> V_310 ;
T_9 V_408 ;
if ( ! V_5 )
return - V_400 ;
if ( ! ( F_83 ( V_5 , & V_408 ) ) ) {
F_5 ( & V_5 -> V_2 -> V_10 ,
L_115 ) ;
return - V_400 ;
}
V_407 -> V_409 = 224 ;
V_407 -> V_184 = 56 ;
F_174 ( V_408 , ( V_407 -> V_409 * V_407 -> V_184 ) ) ;
V_407 -> V_410 = V_408 ;
return 0 ;
}
static int F_175 ( struct V_395 * V_10 , T_14 V_396 )
{
struct V_4 * V_5 ;
if ( V_10 && V_10 -> V_397 ) {
V_5 = (struct V_4 * ) V_10 -> V_397 -> V_310 ;
if ( V_5 ) {
if ( F_8 ( V_411 ,
& V_5 -> V_43 ) ) {
return - V_381 ;
}
return 0 ;
}
}
return - V_381 ;
}
static void F_176 ( struct V_412 * V_328 , T_14 V_396 )
{
}
static inline bool F_177 ( struct V_4 * V_5 )
{
if ( F_44 ( F_8 ( V_146 , & V_5 -> V_19 -> V_26 ) ) ) {
if ( V_5 -> V_19 -> V_140 ) {
unsigned long V_149 = V_5 -> V_19 -> V_140 +
F_18 ( 1000 ) ;
if ( F_178 ( V_41 , V_149 ) ) {
F_57 ( V_146 ,
& V_5 -> V_19 -> V_26 ) ;
F_57 ( V_145 , & V_5 -> V_43 ) ;
V_5 -> V_19 -> V_140 = 0 ;
F_49 ( & V_5 -> V_19 -> V_116 ) ;
return false ;
}
}
return true ;
}
return false ;
}
static int F_179 ( struct V_33 * V_34 , struct V_12 * V_13 )
{
struct V_4 * V_5 = V_34 -> V_7 -> V_15 ;
struct V_16 * V_17 = F_7 ( V_13 ) ;
unsigned int V_224 ;
if ( F_177 ( V_5 ) )
return - V_413 ;
if ( F_44 ( V_5 -> V_43 & V_414 ) ) {
if ( F_44 ( F_8 ( V_42 ,
& V_5 -> V_43 ) ) ) {
return - V_166 ;
}
if ( F_44 ( F_8 ( V_101 , & V_5 -> V_43 ) ) ) {
return - V_413 ;
}
if ( F_44 ( F_8 ( V_100 ,
& V_5 -> V_43 ) &&
F_102 ( V_13 ) ) ) {
return - V_413 ;
}
if ( F_44 ( F_8 ( V_145 , & V_5 -> V_43 ) ||
F_8 ( V_102 , & V_5 -> V_43 ) ) )
return - V_413 ;
}
if ( F_180 ( V_13 ) == V_415 ) {
int V_260 ;
V_260 = F_78 ( V_5 , F_103 ( V_13 ) , F_104 ( V_13 ) ) ;
F_137 ( V_13 , V_260 ? V_96 : V_416 ) ;
return 0 ;
}
V_224 = F_181 ( V_34 -> V_7 , V_13 , V_17 -> V_229 ) ;
F_101 ( V_5 , V_13 , V_17 , V_224 , V_34 ) ;
return 0 ;
}
static bool F_182 ( struct V_33 * V_34 ,
struct V_12 * V_13 )
{
struct V_4 * V_5 = V_34 -> V_7 -> V_15 ;
struct V_16 * V_17 = F_7 ( V_13 ) ;
if ( F_102 ( V_13 ) == V_296 || ! V_5 -> V_375 )
return false ;
if ( F_104 ( V_13 ) <= 64 ) {
if ( ( F_103 ( V_13 ) & 7 ) || ( F_104 ( V_13 ) & 7 ) )
V_17 -> V_302 = 1 ;
}
if ( V_17 -> V_302 && F_183 ( & V_5 -> V_19 -> V_348 ) )
return true ;
return false ;
}
static T_3 F_184 ( struct V_33 * V_34 ,
struct V_12 * V_13 )
{
struct V_4 * V_5 = V_34 -> V_7 -> V_15 ;
struct V_159 * V_160 = V_13 -> V_162 ;
struct V_16 * V_17 = F_7 ( V_13 ) ;
struct V_226 * V_227 ;
if ( F_58 ( V_5 -> V_19 ) )
return V_417 ;
V_17 -> V_18 -> V_157 =
V_28 F_9 ( V_160 -> V_157 | V_160 -> V_154 ) ;
if ( V_160 -> V_156 ) {
V_227 = V_17 -> V_103 + V_230 ;
V_227 -> V_231 =
V_28 F_9 ( ( V_160 -> V_156 - 1 ) & 0x3FFFFF ) ;
V_227 -> V_232 =
V_28 F_9 ( V_160 -> V_155 & 0xFFFFFFFF ) ;
V_227 -> V_233 =
V_28 F_9 ( ( V_160 -> V_155 >> 16 ) >> 16 ) ;
V_17 -> V_18 -> V_157 |=
V_28 F_9 ( ( 1 << 16 ) ) ;
}
V_17 -> V_18 -> V_304 = 0 ;
F_185 ( V_13 ) ;
F_55 ( V_5 -> V_19 , V_13 -> V_22 ) ;
return 0 ;
}
static T_3 F_186 ( struct V_33 * V_34 ,
const struct V_418 * V_419 )
{
struct V_12 * V_13 = V_419 -> V_13 ;
int V_294 ;
F_6 ( V_13 ) ;
if ( F_187 ( V_13 ) )
return F_184 ( V_34 , V_13 ) ;
if ( F_44 ( F_182 ( V_34 , V_13 ) ) )
return V_417 ;
F_185 ( V_13 ) ;
V_294 = F_179 ( V_34 , V_13 ) ;
if ( F_48 ( ! V_294 ) )
return V_416 ;
return V_96 ;
}
static void F_188 ( struct V_420 * V_421 , struct V_12 * V_13 ,
unsigned int V_422 )
{
struct V_4 * V_5 = V_421 -> V_4 ;
struct V_16 * V_17 = F_7 ( V_13 ) ;
if ( ! V_17 -> V_103 )
return;
F_82 ( & V_5 -> V_2 -> V_10 , V_423 ,
V_17 -> V_103 , V_17 -> V_29 ) ;
}
static int F_189 ( struct V_420 * V_421 , struct V_12 * V_13 ,
unsigned int V_422 , unsigned int V_374 )
{
struct V_4 * V_5 = V_421 -> V_4 ;
struct V_16 * V_17 = F_7 ( V_13 ) ;
V_17 -> V_103 = F_80 ( & V_5 -> V_2 -> V_10 , V_423 ,
& V_17 -> V_29 , V_212 ) ;
if ( ! V_17 -> V_103 )
return - V_213 ;
memset ( V_17 -> V_103 , 0 , V_423 ) ;
F_190 ( V_17 -> V_229 , V_424 ) ;
return 0 ;
}
static enum V_425 F_191 ( struct V_12 * V_82 ,
bool V_349 )
{
struct V_4 * V_5 = V_82 -> V_14 -> V_15 ;
if ( V_349 ) {
struct V_16 * V_17 = F_7 ( V_82 ) ;
V_17 -> V_81 = V_426 ;
return V_427 ;
}
if ( F_8 ( V_82 -> V_22 , V_5 -> V_19 -> V_307 ) )
goto V_428;
if ( F_192 ( V_358 , & V_5 -> V_19 -> V_26 ) )
goto V_428;
F_49 ( & V_5 -> V_19 -> V_116 ) ;
V_428:
return V_429 ;
}
static int F_133 ( struct V_4 * V_5 )
{
int V_72 = 0 , V_430 = 0 ;
T_9 V_408 ;
unsigned int V_388 = 0 ;
struct V_323 * V_324 ;
if ( V_5 -> V_328 )
goto V_431;
if ( F_151 ( V_5 ) ) {
V_72 = - V_198 ;
goto V_432;
}
V_5 -> V_328 = F_193 ( V_433 , V_5 -> V_374 ) ;
if ( V_5 -> V_328 == NULL ) {
F_32 ( & V_5 -> V_2 -> V_10 ,
L_116 ) ;
V_72 = - V_198 ;
goto V_434;
}
do {
if ( ! F_194 ( & V_435 , V_212 ) ) {
V_72 = - V_213 ;
goto V_436;
}
F_22 ( & V_437 ) ;
V_72 = F_195 ( & V_435 , & V_388 ) ;
F_25 ( & V_437 ) ;
} while ( V_72 == - V_168 );
if ( V_72 )
goto V_436;
V_72 = F_167 ( L_117 ,
V_388 ,
V_5 -> V_328 -> V_329 ,
V_438 ) ;
if ( V_72 )
goto V_439;
V_5 -> V_328 -> V_440 = V_5 -> V_440 ;
V_5 -> V_328 -> V_441 = V_388 * V_433 ;
V_5 -> V_328 -> V_442 = V_433 ;
V_5 -> V_328 -> V_443 = & V_444 ;
V_5 -> V_328 -> V_310 = V_5 ;
V_5 -> V_388 = V_388 ;
F_122 ( V_5 ) ;
memset ( & V_5 -> V_36 , 0 , sizeof( V_5 -> V_36 ) ) ;
V_5 -> V_36 . V_445 = & V_446 ;
V_5 -> V_36 . V_447 = 1 ;
V_5 -> V_36 . V_448 = V_449 ;
V_5 -> V_36 . V_450 = 1 ;
V_5 -> V_36 . V_451 = sizeof( struct V_16 ) ;
V_5 -> V_36 . V_374 = V_5 -> V_374 ;
V_5 -> V_36 . V_26 = V_452 ;
V_5 -> V_36 . V_4 = V_5 ;
V_5 -> V_36 . V_37 = V_453 ;
V_72 = F_196 ( & V_5 -> V_36 ) ;
if ( V_72 ) {
F_32 ( & V_5 -> V_2 -> V_10 ,
L_118 ) ;
goto V_454;
}
V_5 -> V_7 = F_197 ( & V_5 -> V_36 ) ;
if ( F_12 ( V_5 -> V_7 ) ) {
F_32 ( & V_5 -> V_2 -> V_10 ,
L_118 ) ;
V_72 = - V_213 ;
goto V_455;
}
V_5 -> V_328 -> V_7 = V_5 -> V_7 ;
V_5 -> V_7 -> V_15 = V_5 ;
V_431:
V_430 = F_149 ( V_5 ) ;
if ( V_430 < 0 ) {
F_32 ( & V_5 -> V_2 -> V_10 ,
L_119 ) ;
V_72 = - V_198 ;
goto V_456;
}
if ( V_430 == V_347 )
goto V_457;
F_4 ( V_458 , & V_5 -> V_7 -> V_9 ) ;
F_57 ( V_459 , & V_5 -> V_7 -> V_9 ) ;
F_198 ( V_5 -> V_7 , V_424 ) ;
F_199 ( V_5 -> V_7 , 4096 ) ;
F_200 ( V_5 -> V_7 , 0xffff ) ;
F_201 ( V_5 -> V_7 , 0x400000 ) ;
F_202 ( V_5 -> V_7 , 4096 ) ;
F_203 ( V_5 -> V_7 , V_5 -> V_2 -> V_460 ) ;
if ( V_5 -> V_181 == true ) {
F_4 ( V_461 , & V_5 -> V_7 -> V_9 ) ;
V_5 -> V_7 -> V_462 . V_463 = 4096 ;
F_204 ( V_5 -> V_7 ,
V_209 * V_210 ) ;
}
if ( ! ( F_83 ( V_5 , & V_408 ) ) ) {
F_5 ( & V_5 -> V_2 -> V_10 ,
L_120 ) ;
V_72 = - V_165 ;
goto V_464;
}
F_205 ( V_5 -> V_328 , V_408 ) ;
F_206 ( & V_5 -> V_2 -> V_10 , V_5 -> V_328 ) ;
V_5 -> V_465 = F_207 ( V_5 -> V_328 , 0 ) ;
V_324 = F_208 ( & F_209 ( V_5 -> V_328 ) -> V_324 ) ;
if ( V_324 ) {
F_118 ( V_5 , V_324 ) ;
F_210 ( V_324 ) ;
}
if ( V_5 -> V_466 ) {
F_4 ( V_467 , & V_5 -> V_43 ) ;
return V_72 ;
}
V_457:
V_5 -> V_466 = F_211 ( F_142 ,
V_5 , V_5 -> V_374 ,
L_121 , V_388 ) ;
if ( F_12 ( V_5 -> V_466 ) ) {
F_32 ( & V_5 -> V_2 -> V_10 , L_122 ) ;
V_5 -> V_466 = NULL ;
V_72 = - V_73 ;
goto V_468;
}
F_212 ( V_5 -> V_466 ) ;
if ( V_430 == V_347 )
V_72 = V_430 ;
return V_72 ;
V_468:
F_213 ( V_5 -> V_465 ) ;
V_5 -> V_465 = NULL ;
F_214 ( V_5 -> V_328 ) ;
V_464:
V_456:
F_215 ( V_5 -> V_7 ) ;
V_455:
F_216 ( & V_5 -> V_36 ) ;
V_454:
F_126 ( V_5 ) ;
V_439:
F_22 ( & V_437 ) ;
F_217 ( & V_435 , V_388 ) ;
F_25 ( & V_437 ) ;
V_436:
F_218 ( V_5 -> V_328 ) ;
V_434:
F_163 ( V_5 ) ;
V_432:
return V_72 ;
}
static void F_219 ( struct V_12 * V_13 , void * V_117 , bool V_469 )
{
struct V_16 * V_17 = F_7 ( V_13 ) ;
V_17 -> V_81 = V_96 ;
F_37 ( V_13 ) ;
}
static int F_220 ( struct V_4 * V_5 )
{
struct V_323 * V_324 ;
F_126 ( V_5 ) ;
if ( V_5 -> V_466 ) {
F_4 ( V_354 , & V_5 -> V_19 -> V_26 ) ;
F_49 ( & V_5 -> V_19 -> V_116 ) ;
F_221 ( V_5 -> V_466 ) ;
}
if ( F_8 ( V_467 , & V_5 -> V_43 ) ) {
V_324 = F_208 ( & F_209 ( V_5 -> V_328 ) -> V_324 ) ;
if ( V_324 ) {
F_120 ( V_5 , V_324 ) ;
F_210 ( V_324 ) ;
}
}
if ( ! V_5 -> V_6 ) {
if ( ! F_59 ( V_5 -> V_19 , V_164 ) )
F_162 ( V_5 ) ;
}
else
F_41 ( & V_5 -> V_2 -> V_10 , L_123 ,
V_5 -> V_328 -> V_329 ) ;
F_222 ( V_5 -> V_7 ) ;
F_60 ( V_5 -> V_7 ) ;
F_145 ( & V_5 -> V_36 , F_219 , V_5 ) ;
F_62 ( V_5 -> V_7 ) ;
if ( V_5 -> V_465 ) {
F_213 ( V_5 -> V_465 ) ;
V_5 -> V_465 = NULL ;
}
if ( V_5 -> V_328 ) {
if ( F_8 ( V_467 , & V_5 -> V_43 ) )
F_214 ( V_5 -> V_328 ) ;
if ( V_5 -> V_328 -> V_7 ) {
F_215 ( V_5 -> V_7 ) ;
F_216 ( & V_5 -> V_36 ) ;
V_5 -> V_7 = NULL ;
}
F_218 ( V_5 -> V_328 ) ;
}
V_5 -> V_328 = NULL ;
F_22 ( & V_437 ) ;
F_217 ( & V_435 , V_5 -> V_388 ) ;
F_25 ( & V_437 ) ;
F_163 ( V_5 ) ;
return 0 ;
}
static int F_223 ( struct V_4 * V_5 )
{
F_164 ( V_5 ) ;
if ( V_5 -> V_328 ) {
F_41 ( & V_5 -> V_2 -> V_10 ,
L_124 , V_5 -> V_328 -> V_329 ) ;
if ( F_8 ( V_467 , & V_5 -> V_43 ) )
F_214 ( V_5 -> V_328 ) ;
if ( V_5 -> V_328 -> V_7 ) {
F_215 ( V_5 -> V_7 ) ;
F_216 ( & V_5 -> V_36 ) ;
}
F_218 ( V_5 -> V_328 ) ;
V_5 -> V_328 = NULL ;
V_5 -> V_7 = NULL ;
}
F_22 ( & V_437 ) ;
F_217 ( & V_435 , V_5 -> V_388 ) ;
F_25 ( & V_437 ) ;
return 0 ;
}
static int F_224 ( struct V_4 * V_5 )
{
F_41 ( & V_5 -> V_2 -> V_10 ,
L_125 , V_5 -> V_328 -> V_329 ) ;
F_165 ( V_5 ) ;
return 0 ;
}
static int F_225 ( struct V_4 * V_5 )
{
F_41 ( & V_5 -> V_2 -> V_10 , L_126 ,
V_5 -> V_328 -> V_329 ) ;
F_166 ( V_5 ) ;
return 0 ;
}
static void F_226 ( int V_470 )
{
V_471 [ V_470 ] -- ;
}
static int F_227 ( int V_472 )
{
int V_470 , V_473 , V_474 ;
const struct V_475 * V_476 ;
V_476 = F_228 ( V_472 ) ;
V_473 = F_229 ( V_476 ) ;
V_474 = V_471 [ V_473 ] ;
V_470 = V_473 ;
F_230 (cpu, node_mask) {
if ( V_471 [ V_470 ] < V_474 ) {
V_473 = V_470 ;
V_474 = V_471 [ V_470 ] ;
}
}
V_471 [ V_473 ] ++ ;
return V_473 ;
}
static inline int F_231 ( void )
{
static int V_477 = - 1 ;
if ( V_477 == - 1 ) {
V_477 = V_478 ;
return V_477 ;
}
V_477 = F_232 ( V_477 ) ;
if ( V_477 == V_479 )
V_477 = V_478 ;
return V_477 ;
}
static void F_233 ( struct V_4 * V_5 , struct V_1 * V_2 )
{
int V_480 ;
unsigned short V_481 ;
V_480 = F_234 ( V_2 , V_482 ) ;
if ( V_480 ) {
F_3 ( V_2 ,
V_480 + V_483 ,
& V_481 ) ;
if ( V_481 & ( 1 << 11 ) ||
V_481 & ( 1 << 4 ) ) {
F_41 ( & V_5 -> V_2 -> V_10 ,
L_127 ,
V_2 -> V_484 , V_2 -> V_190 ) ;
V_481 &= ~ ( V_485 |
V_486 ) ;
F_235 ( V_2 ,
V_480 + V_483 ,
V_481 ) ;
}
}
}
static void F_236 ( struct V_4 * V_5 , struct V_1 * V_2 )
{
if ( V_2 -> V_487 && V_2 -> V_487 -> V_488 ) {
if ( V_2 -> V_487 -> V_488 -> V_484 == V_489 &&
( ( V_2 -> V_487 -> V_488 -> V_190 & 0xff00 ) == 0x5a00 ) ) {
F_233 ( V_5 , V_2 -> V_487 -> V_488 ) ;
} else {
struct V_1 * V_490 = V_2 -> V_487 -> V_488 ;
if ( V_490 -> V_487 &&
V_490 -> V_487 -> V_491 &&
V_490 -> V_487 -> V_491 -> V_488 &&
V_490 -> V_487 -> V_491 -> V_488 -> V_484 ==
V_489 &&
( V_490 -> V_487 -> V_491 -> V_488 -> V_190 &
0xff00 ) == 0x5a00 ) {
F_233 ( V_5 ,
V_490 -> V_487 -> V_491 -> V_488 ) ;
}
}
}
}
static int F_237 ( struct V_1 * V_2 ,
const struct V_492 * V_493 )
{
int V_72 = 0 ;
struct V_4 * V_5 = NULL ;
char V_494 [ 256 ] ;
const struct V_475 * V_476 ;
int V_470 , V_55 = 0 , V_495 = 0 ;
int V_496 = V_497 ;
unsigned long V_26 ;
V_496 = F_238 ( V_2 -> V_487 ) ;
if ( V_496 != V_497 ) {
if ( ! F_239 ( V_496 ) )
V_496 = F_231 () ;
} else {
F_41 ( & V_2 -> V_10 , L_128 ) ;
V_496 = F_231 () ;
}
F_41 ( & V_2 -> V_10 , L_129 ,
V_496 , F_238 ( V_2 -> V_487 ) , F_240 ( & V_2 -> V_10 ) ,
F_241 ( F_242 () ) , F_242 () ) ;
V_5 = F_153 ( sizeof( struct V_4 ) , V_212 , V_496 ) ;
if ( V_5 == NULL ) {
F_32 ( & V_2 -> V_10 ,
L_130 ) ;
return - V_213 ;
}
F_243 ( V_2 , V_5 ) ;
V_72 = F_244 ( V_2 ) ;
if ( V_72 < 0 ) {
F_32 ( & V_2 -> V_10 , L_131 ) ;
goto V_498;
}
V_72 = F_245 ( V_2 , 1 << V_372 , V_95 ) ;
if ( V_72 < 0 ) {
F_32 ( & V_2 -> V_10 , L_132 ) ;
goto V_498;
}
if ( ! F_246 ( V_2 , F_247 ( 64 ) ) ) {
V_72 = F_248 ( V_2 , F_247 ( 64 ) ) ;
if ( V_72 ) {
V_72 = F_248 ( V_2 ,
F_247 ( 32 ) ) ;
if ( V_72 ) {
F_5 ( & V_2 -> V_10 ,
L_133 ) ;
goto V_499;
}
}
}
V_5 -> V_440 = V_500 ;
V_5 -> V_133 = V_133 ;
V_5 -> V_2 = V_2 ;
V_5 -> V_374 = V_496 ;
F_249 ( & V_5 -> V_501 ) ;
F_249 ( & V_5 -> V_502 ) ;
memset ( V_5 -> V_503 , 0 , 32 ) ;
snprintf ( V_5 -> V_503 , 31 , L_134 , V_5 -> V_133 ) ;
V_5 -> V_129 = F_250 ( V_5 -> V_503 ) ;
if ( ! V_5 -> V_129 ) {
F_5 ( & V_2 -> V_10 , L_135 , V_5 -> V_133 ) ;
V_72 = - V_213 ;
goto V_504;
}
memset ( V_494 , 0 , sizeof( V_494 ) ) ;
V_476 = F_228 ( V_5 -> V_374 ) ;
if ( ! F_251 ( V_476 ) ) {
F_230 (cpu, node_mask)
{
snprintf ( & V_494 [ V_495 ] , 256 - V_495 , L_136 , V_470 ) ;
V_495 = strlen ( V_494 ) ;
}
F_41 ( & V_2 -> V_10 , L_137 ,
V_5 -> V_374 ,
F_252 ( F_229 ( V_476 ) ) ,
F_253 ( V_5 -> V_374 ) ,
V_494 ) ;
} else
F_254 ( & V_2 -> V_10 , L_138 ) ;
V_5 -> V_385 = F_227 ( V_5 -> V_374 ) ;
F_41 ( & V_2 -> V_10 , L_139 ,
F_241 ( V_5 -> V_385 ) , V_5 -> V_385 ) ;
V_5 -> V_127 [ 0 ] . V_128 = V_5 -> V_385 ;
V_5 -> V_127 [ 1 ] . V_128 = F_227 ( V_5 -> V_374 ) ;
V_5 -> V_127 [ 2 ] . V_128 = F_227 ( V_5 -> V_374 ) ;
V_5 -> V_127 [ 3 ] . V_128 = V_5 -> V_127 [ 0 ] . V_128 ;
V_5 -> V_127 [ 4 ] . V_128 = V_5 -> V_127 [ 1 ] . V_128 ;
V_5 -> V_127 [ 5 ] . V_128 = V_5 -> V_127 [ 2 ] . V_128 ;
V_5 -> V_127 [ 6 ] . V_128 = V_5 -> V_127 [ 2 ] . V_128 ;
V_5 -> V_127 [ 7 ] . V_128 = V_5 -> V_127 [ 1 ] . V_128 ;
F_255 (cpu) {
memset ( V_494 , 0 , sizeof( V_494 ) ) ;
for ( V_55 = 0 , V_495 = 0 ; V_55 < V_126 ; V_55 ++ ) {
if ( V_5 -> V_127 [ V_55 ] . V_128 == V_470 ) {
snprintf ( & V_494 [ V_495 ] , 256 - V_495 , L_136 , V_55 ) ;
V_495 = strlen ( V_494 ) ;
}
}
if ( V_495 )
F_41 ( & V_2 -> V_10 , L_140 , V_470 , V_494 ) ;
}
F_256 ( & V_5 -> V_127 [ 0 ] . V_127 , V_505 ) ;
F_256 ( & V_5 -> V_127 [ 1 ] . V_127 , V_506 ) ;
F_256 ( & V_5 -> V_127 [ 2 ] . V_127 , V_507 ) ;
F_256 ( & V_5 -> V_127 [ 3 ] . V_127 , V_508 ) ;
F_256 ( & V_5 -> V_127 [ 4 ] . V_127 , V_509 ) ;
F_256 ( & V_5 -> V_127 [ 5 ] . V_127 , V_510 ) ;
F_256 ( & V_5 -> V_127 [ 6 ] . V_127 , V_511 ) ;
F_256 ( & V_5 -> V_127 [ 7 ] . V_127 , V_512 ) ;
F_257 ( V_2 ) ;
V_72 = F_258 ( V_2 ) ;
if ( V_72 ) {
F_5 ( & V_2 -> V_10 ,
L_141 ) ;
goto V_513;
}
F_236 ( V_5 , V_2 ) ;
V_72 = F_133 ( V_5 ) ;
if ( V_72 < 0 ) {
F_32 ( & V_2 -> V_10 ,
L_142 ) ;
goto V_504;
}
V_133 ++ ;
if ( V_72 != V_347 )
F_4 ( V_467 , & V_5 -> V_43 ) ;
else
V_72 = 0 ;
F_110 ( & V_315 , V_26 ) ;
F_259 ( & V_5 -> V_501 , & V_501 ) ;
F_113 ( & V_315 , V_26 ) ;
goto V_514;
V_504:
F_260 ( V_2 ) ;
V_513:
if ( V_5 -> V_129 ) {
F_261 ( V_5 -> V_129 ) ;
F_262 ( V_5 -> V_129 ) ;
F_226 ( V_5 -> V_127 [ 0 ] . V_128 ) ;
F_226 ( V_5 -> V_127 [ 1 ] . V_128 ) ;
F_226 ( V_5 -> V_127 [ 2 ] . V_128 ) ;
}
V_499:
F_263 ( V_2 , 1 << V_372 ) ;
V_498:
F_98 ( V_5 ) ;
F_243 ( V_2 , NULL ) ;
return V_72 ;
V_514:
return V_72 ;
}
static void F_264 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
unsigned long V_26 , V_149 ;
F_4 ( V_411 , & V_5 -> V_43 ) ;
F_110 ( & V_315 , V_26 ) ;
F_265 ( & V_5 -> V_501 ) ;
F_259 ( & V_5 -> V_502 , & V_515 ) ;
F_113 ( & V_315 , V_26 ) ;
F_1 ( V_2 ) ;
F_266 ( V_5 -> V_2 -> V_132 ) ;
V_149 = V_41 + F_18 ( 4000 ) ;
do {
F_61 ( 20 ) ;
} while ( F_51 ( & V_5 -> V_108 ) != 0 &&
F_20 ( V_41 , V_149 ) );
if ( ! V_5 -> V_6 )
F_267 ( V_5 -> V_465 ) ;
if ( F_51 ( & V_5 -> V_108 ) != 0 ) {
F_5 ( & V_5 -> V_2 -> V_10 ,
L_143 ) ;
}
F_268 ( V_5 -> V_7 ) ;
F_4 ( V_42 , & V_5 -> V_43 ) ;
F_220 ( V_5 ) ;
if ( V_5 -> V_129 ) {
F_261 ( V_5 -> V_129 ) ;
F_262 ( V_5 -> V_129 ) ;
F_226 ( V_5 -> V_127 [ 0 ] . V_128 ) ;
F_226 ( V_5 -> V_127 [ 1 ] . V_128 ) ;
F_226 ( V_5 -> V_127 [ 2 ] . V_128 ) ;
}
F_260 ( V_2 ) ;
F_110 ( & V_315 , V_26 ) ;
F_265 ( & V_5 -> V_502 ) ;
F_113 ( & V_315 , V_26 ) ;
F_98 ( V_5 ) ;
F_263 ( V_2 , 1 << V_372 ) ;
F_243 ( V_2 , NULL ) ;
}
static int F_269 ( struct V_1 * V_2 , T_15 V_516 )
{
int V_72 = 0 ;
struct V_4 * V_5 = F_2 ( V_2 ) ;
if ( ! V_5 ) {
F_32 ( & V_2 -> V_10 ,
L_144 ) ;
return - V_73 ;
}
F_4 ( V_517 , & V_5 -> V_43 ) ;
V_72 = F_224 ( V_5 ) ;
if ( V_72 < 0 ) {
F_32 ( & V_2 -> V_10 ,
L_145 ) ;
return V_72 ;
}
F_270 ( V_2 ) ;
F_271 ( V_2 ) ;
F_272 ( V_2 , V_518 ) ;
return V_72 ;
}
static int F_273 ( struct V_1 * V_2 )
{
int V_72 = 0 ;
struct V_4 * V_5 ;
V_5 = F_2 ( V_2 ) ;
if ( ! V_5 ) {
F_32 ( & V_2 -> V_10 ,
L_144 ) ;
return - V_73 ;
}
F_272 ( V_2 , V_519 ) ;
F_274 ( V_2 ) ;
V_72 = F_244 ( V_2 ) ;
if ( V_72 < 0 ) {
F_32 ( & V_2 -> V_10 ,
L_146 ) ;
goto V_260;
}
F_257 ( V_2 ) ;
V_72 = F_225 ( V_5 ) ;
if ( V_72 < 0 )
F_32 ( & V_2 -> V_10 , L_147 ) ;
V_260:
F_57 ( V_517 , & V_5 -> V_43 ) ;
return V_72 ;
}
static void F_275 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
if ( V_5 )
F_223 ( V_5 ) ;
}
static int T_16 F_276 ( void )
{
int error ;
F_277 ( V_95 L_148 V_520 L_84 ) ;
F_155 ( & V_315 ) ;
F_249 ( & V_501 ) ;
F_249 ( & V_515 ) ;
error = F_278 ( 0 , V_95 ) ;
if ( error <= 0 ) {
F_279 ( L_149 ,
error ) ;
return - V_153 ;
}
V_500 = error ;
V_326 = F_123 ( L_117 , NULL ) ;
if ( F_124 ( V_326 ) ) {
F_280 ( L_150 ) ;
V_326 = NULL ;
}
if ( V_326 ) {
V_521 = F_125 ( L_151 ,
V_330 , V_326 , NULL ,
& V_522 ) ;
if ( F_124 ( V_521 ) ) {
F_279 ( L_152 ) ;
V_521 = NULL ;
}
}
error = F_281 ( & V_523 ) ;
if ( error ) {
F_282 ( V_326 ) ;
F_283 ( V_500 , V_95 ) ;
}
return error ;
}
static void T_17 F_284 ( void )
{
F_283 ( V_500 , V_95 ) ;
F_285 ( & V_523 ) ;
F_127 ( V_326 ) ;
}
