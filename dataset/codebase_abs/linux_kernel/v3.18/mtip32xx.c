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
if ( V_5 -> V_12 ) {
F_4 ( V_13 , & V_5 -> V_12 -> V_14 ) ;
F_6 ( & V_5 -> V_12 -> V_15 ) ;
} else
F_5 ( & V_5 -> V_2 -> V_10 ,
L_2 , V_11 ) ;
return true ;
}
return false ;
}
static struct V_16 * F_7 ( struct V_4 * V_5 )
{
struct V_17 * V_18 ;
V_18 = F_8 ( V_5 -> V_7 , 0 , V_19 , true ) ;
return F_9 ( V_18 ) ;
}
static void F_10 ( struct V_4 * V_5 , struct V_16 * V_20 )
{
F_11 ( F_12 ( V_20 ) ) ;
}
static struct V_17 * F_13 ( struct V_4 * V_5 ,
unsigned int V_21 )
{
struct V_22 * V_23 = V_5 -> V_7 -> V_24 [ 0 ] ;
return F_14 ( V_23 -> V_25 , V_21 ) ;
}
static struct V_16 * F_15 ( struct V_4 * V_5 ,
unsigned int V_21 )
{
struct V_17 * V_18 = F_13 ( V_5 , V_21 ) ;
return F_9 ( V_18 ) ;
}
static void F_16 ( struct V_26 * V_12 ,
int V_21 , struct V_16 * V_20 , int V_27 )
{
struct V_4 * V_5 = V_12 -> V_5 ;
struct V_17 * V_18 ;
if ( F_17 ( ! V_5 ) || F_17 ( ! V_12 ) )
return;
if ( F_17 ( V_27 == V_28 ) ) {
F_5 ( & V_12 -> V_5 -> V_2 -> V_10 ,
L_3 , V_21 ) ;
}
F_18 ( & V_5 -> V_2 -> V_10 , V_20 -> V_29 , V_20 -> V_30 , V_20 -> V_31 ) ;
V_18 = F_13 ( V_5 , V_21 ) ;
if ( F_17 ( V_20 -> V_32 ) )
F_19 ( & V_12 -> V_33 ) ;
F_20 ( V_18 , V_27 ? - V_34 : 0 ) ;
}
static int F_21 ( struct V_4 * V_5 )
{
unsigned long V_35 ;
F_22 ( V_36 , V_5 -> V_37 + V_38 ) ;
F_23 ( V_5 -> V_37 + V_38 ) ;
V_35 = V_39 + F_24 ( 2000 ) ;
do {
F_25 ( 10 ) ;
if ( F_26 ( V_40 , & V_5 -> V_41 ) )
return - 1 ;
} while ( ( F_23 ( V_5 -> V_37 + V_38 ) & V_36 )
&& F_27 ( V_39 , V_35 ) );
if ( F_23 ( V_5 -> V_37 + V_38 ) & V_36 )
return - 1 ;
return 0 ;
}
static inline void F_28 ( struct V_26 * V_12 , int V_21 )
{
int V_42 = V_21 >> 5 ;
F_29 ( & V_12 -> V_43 [ V_42 ] ) ;
F_22 ( ( 1 << F_30 ( V_21 ) ) ,
V_12 -> V_44 [ F_31 ( V_21 ) ] ) ;
F_22 ( ( 1 << F_30 ( V_21 ) ) ,
V_12 -> V_45 [ F_31 ( V_21 ) ] ) ;
F_32 ( & V_12 -> V_43 [ V_42 ] ) ;
}
static int F_33 ( struct V_26 * V_12 , int V_46 )
{
T_2 V_47 ;
V_47 = F_23 ( V_12 -> V_37 + V_48 ) ;
if ( V_46 )
F_22 ( V_47 | V_49 , V_12 -> V_37 + V_48 ) ;
else
F_22 ( V_47 & ~ V_49 , V_12 -> V_37 + V_48 ) ;
F_23 ( V_12 -> V_37 + V_48 ) ;
return ( ( ( V_47 & V_49 ) == V_49 ) ) ;
}
static int F_34 ( struct V_26 * V_12 , int V_46 )
{
T_2 V_47 ;
V_47 = F_23 ( V_12 -> V_37 + V_48 ) ;
if ( V_46 )
F_22 ( V_47 | V_50 , V_12 -> V_37 + V_48 ) ;
else
F_22 ( V_47 & ~ V_50 , V_12 -> V_37 + V_48 ) ;
F_23 ( V_12 -> V_37 + V_48 ) ;
return ( ( ( V_47 & V_50 ) == V_50 ) ) ;
}
static inline void F_35 ( struct V_26 * V_12 )
{
F_33 ( V_12 , 1 ) ;
F_34 ( V_12 , 1 ) ;
}
static inline void F_36 ( struct V_26 * V_12 )
{
F_22 ( 0 , V_12 -> V_37 + V_51 ) ;
F_34 ( V_12 , 0 ) ;
F_33 ( V_12 , 0 ) ;
}
static void F_37 ( struct V_26 * V_12 )
{
int V_52 ;
F_36 ( V_12 ) ;
if ( F_23 ( V_12 -> V_5 -> V_37 + V_53 ) & V_54 ) {
F_22 ( ( V_12 -> V_55 >> 16 ) >> 16 ,
V_12 -> V_37 + V_56 ) ;
F_22 ( ( V_12 -> V_57 >> 16 ) >> 16 ,
V_12 -> V_37 + V_58 ) ;
}
F_22 ( V_12 -> V_55 & 0xFFFFFFFF ,
V_12 -> V_37 + V_59 ) ;
F_22 ( V_12 -> V_57 & 0xFFFFFFFF , V_12 -> V_37 + V_60 ) ;
F_22 ( F_23 ( V_12 -> V_37 + V_61 ) , V_12 -> V_37 + V_61 ) ;
for ( V_52 = 0 ; V_52 < V_12 -> V_5 -> V_62 ; V_52 ++ )
F_22 ( 0xFFFFFFFF , V_12 -> V_63 [ V_52 ] ) ;
F_22 ( F_23 ( V_12 -> V_37 + V_64 ) , V_12 -> V_37 + V_64 ) ;
F_22 ( F_23 ( V_12 -> V_5 -> V_37 + V_65 ) ,
V_12 -> V_5 -> V_37 + V_65 ) ;
F_22 ( V_66 , V_12 -> V_37 + V_51 ) ;
}
static void F_38 ( struct V_26 * V_12 )
{
unsigned long V_35 ;
F_34 ( V_12 , 0 ) ;
V_35 = V_39 + F_24 ( 500 ) ;
while ( ( F_23 ( V_12 -> V_37 + V_48 ) & V_67 )
&& F_27 ( V_39 , V_35 ) )
;
if ( F_26 ( V_40 , & V_12 -> V_5 -> V_41 ) )
return;
if ( F_23 ( V_12 -> V_37 + V_48 ) & V_67 ) {
F_5 ( & V_12 -> V_5 -> V_2 -> V_10 ,
L_4 ) ;
if ( F_21 ( V_12 -> V_5 ) )
F_39 ( & V_12 -> V_5 -> V_2 -> V_10 ,
L_5 ) ;
F_25 ( 30 ) ;
}
F_5 ( & V_12 -> V_5 -> V_2 -> V_10 , L_6 ) ;
F_22 ( F_23 ( V_12 -> V_37 + V_68 ) |
1 , V_12 -> V_37 + V_68 ) ;
F_23 ( V_12 -> V_37 + V_68 ) ;
V_35 = V_39 + F_24 ( 1 ) ;
while ( F_27 ( V_39 , V_35 ) )
;
if ( F_26 ( V_40 , & V_12 -> V_5 -> V_41 ) )
return;
F_22 ( F_23 ( V_12 -> V_37 + V_68 ) & ~ 1 ,
V_12 -> V_37 + V_68 ) ;
F_23 ( V_12 -> V_37 + V_68 ) ;
V_35 = V_39 + F_24 ( 500 ) ;
while ( ( ( F_23 ( V_12 -> V_37 + V_69 ) & 0x01 ) == 0 )
&& F_27 ( V_39 , V_35 ) )
;
if ( F_26 ( V_40 , & V_12 -> V_5 -> V_41 ) )
return;
if ( ( F_23 ( V_12 -> V_37 + V_69 ) & 0x01 ) == 0 )
F_5 ( & V_12 -> V_5 -> V_2 -> V_10 ,
L_7 ) ;
F_37 ( V_12 ) ;
F_35 ( V_12 ) ;
}
static int F_40 ( struct V_4 * V_5 )
{
int V_70 = 0 ;
if ( F_1 ( V_5 -> V_2 ) )
return 0 ;
if ( F_21 ( V_5 ) < 0 )
V_70 = - V_71 ;
F_25 ( 1 ) ;
F_37 ( V_5 -> V_12 ) ;
F_35 ( V_5 -> V_12 ) ;
F_22 ( F_23 ( V_5 -> V_37 + V_38 ) | V_72 ,
V_5 -> V_37 + V_38 ) ;
return V_70 ;
}
static void F_41 ( struct V_4 * V_5 ,
char * V_73 ,
unsigned long * V_74 ,
int V_75 )
{
unsigned char V_76 [ 128 ] ;
int V_42 , V_77 = 0 ;
memset ( V_76 , 0 , sizeof( V_76 ) ) ;
for ( V_42 = V_78 ; V_42 > 0 ; V_42 -- )
V_77 += sprintf ( V_76 + V_77 , L_8 ,
V_74 [ V_42 - 1 ] ) ;
F_5 ( & V_5 -> V_2 -> V_10 ,
L_9 , V_75 , V_73 , V_76 ) ;
}
static void F_42 ( struct V_26 * V_12 ,
int V_21 , struct V_16 * V_79 , int V_27 )
{
struct V_80 * V_81 = V_79 -> V_82 ;
if ( F_17 ( V_27 == V_28 ) )
F_5 ( & V_12 -> V_5 -> V_2 -> V_10 ,
L_10 , V_21 ) ;
F_43 ( V_81 ) ;
}
static void F_44 ( struct V_26 * V_12 ,
int V_21 , struct V_16 * V_79 , int V_27 )
{
}
static void F_45 ( struct V_4 * V_5 )
{
int V_42 , V_21 , V_83 , V_84 , V_70 ;
struct V_26 * V_12 ;
struct V_16 * V_20 ;
T_2 V_63 ;
struct V_85 * V_86 ;
unsigned long V_87 [ V_78 ] ;
unsigned int V_88 = 0 ;
unsigned char * V_89 ;
char * V_90 = NULL ;
int V_91 = 0 , V_92 = 0 ;
F_5 ( & V_5 -> V_2 -> V_10 , L_11 ) ;
V_12 = V_5 -> V_12 ;
F_4 ( V_93 , & V_12 -> V_14 ) ;
if ( F_26 ( V_94 , & V_12 -> V_14 ) &&
F_26 ( V_95 , V_12 -> V_96 ) ) {
V_20 = F_15 ( V_5 , V_95 ) ;
F_46 ( V_97 L_12 ) ;
if ( V_20 -> V_82 && V_20 -> V_98 ) {
V_20 -> V_98 ( V_12 , V_95 ,
V_20 , V_28 ) ;
}
goto V_99;
}
memset ( V_87 , 0 , V_78 * sizeof( long ) ) ;
for ( V_42 = 0 ; V_42 < V_5 -> V_62 ; V_42 ++ ) {
V_63 = F_23 ( V_12 -> V_63 [ V_42 ] ) ;
F_5 ( & V_5 -> V_2 -> V_10 , L_13 , V_42 , V_63 ) ;
F_22 ( V_63 , V_12 -> V_63 [ V_42 ] ) ;
for ( V_83 = 0 ; V_83 < 32 && V_63 ; V_83 ++ ) {
if ( ! ( V_63 & ( 1 << V_83 ) ) )
continue;
V_21 = ( V_42 << 5 ) + V_83 ;
if ( V_21 == V_95 )
continue;
V_20 = F_15 ( V_5 , V_21 ) ;
if ( F_47 ( V_20 -> V_98 ) ) {
F_4 ( V_21 , V_87 ) ;
V_88 ++ ;
V_20 -> V_98 ( V_12 , V_21 , V_20 , 0 ) ;
} else {
F_39 ( & V_12 -> V_5 -> V_2 -> V_10 ,
L_14 ,
V_21 ) ;
if ( F_1 ( V_5 -> V_2 ) ) {
return;
}
}
}
}
F_41 ( V_5 , L_15 , V_87 , V_88 ) ;
F_25 ( 20 ) ;
F_38 ( V_12 ) ;
V_70 = F_48 ( V_5 -> V_12 , V_100 ,
V_5 -> V_12 -> V_101 ,
V_5 -> V_12 -> V_102 , 1 ) ;
if ( V_70 ) {
F_5 ( & V_5 -> V_2 -> V_10 ,
L_16 ) ;
} else {
V_89 = ( unsigned char * ) V_5 -> V_12 -> V_101 ;
if ( V_89 [ 259 ] & 0x1 ) {
F_49 ( & V_5 -> V_2 -> V_10 ,
L_17 ) ;
F_4 ( V_103 , & V_5 -> V_41 ) ;
V_91 = 1 ;
V_90 = L_18 ;
}
if ( V_89 [ 288 ] == 0xF7 ) {
F_49 ( & V_5 -> V_2 -> V_10 ,
L_19 ) ;
F_4 ( V_104 , & V_5 -> V_41 ) ;
V_92 = 1 ;
V_90 = L_20 ;
}
if ( V_89 [ 288 ] == 0xBF ) {
F_4 ( V_105 , & V_5 -> V_41 ) ;
F_49 ( & V_5 -> V_2 -> V_10 ,
L_21 ) ;
V_92 = 1 ;
V_90 = L_22 ;
}
}
memset ( V_87 , 0 , V_78 * sizeof( long ) ) ;
for ( V_42 = 0 ; V_42 < V_5 -> V_62 ; V_42 ++ ) {
for ( V_83 = 0 ; V_83 < 32 ; V_83 ++ ) {
V_84 = 1 ;
V_21 = ( V_42 << 5 ) + V_83 ;
V_20 = F_15 ( V_5 , V_21 ) ;
V_86 = (struct V_85 * ) V_20 -> V_79 ;
if ( V_21 == V_95 ||
V_86 -> V_79 == V_106 )
V_84 = 0 ;
else {
if ( V_92 ||
( V_91 &&
V_86 -> V_79 == V_107 ) ) {
F_5 ( & V_5 -> V_2 -> V_10 ,
L_23 ,
V_86 -> V_79 == V_107 ?
L_24 : L_25 ,
V_21 ,
V_90 != NULL ?
V_90 : L_26 ) ;
if ( V_20 -> V_98 ) {
V_20 -> V_98 ( V_12 , V_21 ,
V_20 , - V_108 ) ;
}
continue;
}
}
if ( V_84 && ( V_20 -> V_109 -- > 0 ) ) {
F_4 ( V_21 , V_87 ) ;
F_28 ( V_12 , V_21 ) ;
continue;
}
F_5 ( & V_12 -> V_5 -> V_2 -> V_10 ,
L_27 , V_21 ) ;
if ( V_20 -> V_98 )
V_20 -> V_98 ( V_12 , V_21 , V_20 , V_28 ) ;
else
F_5 ( & V_12 -> V_5 -> V_2 -> V_10 ,
L_28 ,
V_21 ) ;
}
}
F_41 ( V_5 , L_29 , V_87 , V_88 ) ;
V_99:
F_50 ( V_93 , & V_12 -> V_14 ) ;
F_6 ( & V_12 -> V_15 ) ;
}
static inline void F_51 ( struct V_26 * V_12 , int V_42 ,
T_2 V_63 )
{
struct V_4 * V_5 = V_12 -> V_5 ;
int V_21 , V_83 ;
struct V_16 * V_79 ;
if ( ! V_63 ) {
F_52 ( ! V_63 ) ;
return;
}
F_22 ( V_63 , V_12 -> V_63 [ V_42 ] ) ;
for ( V_83 = 0 ; ( V_83 < 32 ) && V_63 ; V_83 ++ ) {
if ( V_63 & 0x01 ) {
V_21 = ( V_42 << 5 ) | V_83 ;
if ( F_17 ( V_21 == V_95 ) )
continue;
V_79 = F_15 ( V_5 , V_21 ) ;
if ( F_47 ( V_79 -> V_98 ) )
V_79 -> V_98 ( V_12 , V_21 , V_79 , 0 ) ;
else {
F_53 ( & V_5 -> V_2 -> V_10 ,
L_30 ,
V_21 ) ;
if ( F_1 (
V_5 -> V_2 ) ) {
return;
}
}
}
V_63 >>= 1 ;
}
if ( F_54 ( & V_5 -> V_110 ) == 0 )
F_22 ( 0xffffffff , V_5 -> V_37 + V_65 ) ;
}
static inline void F_55 ( struct V_4 * V_5 , T_2 V_111 )
{
struct V_26 * V_12 = V_5 -> V_12 ;
struct V_16 * V_20 = F_15 ( V_5 , V_95 ) ;
if ( F_26 ( V_94 , & V_12 -> V_14 ) &&
( V_20 != NULL ) && ! ( F_23 ( V_12 -> V_45 [ V_95 ] )
& ( 1 << V_95 ) ) ) {
if ( V_20 -> V_98 ) {
V_20 -> V_98 ( V_12 , V_95 , V_20 , 0 ) ;
return;
}
}
return;
}
static inline void F_56 ( struct V_4 * V_5 , T_2 V_111 )
{
if ( F_17 ( V_111 & V_112 ) ) {
F_5 ( & V_5 -> V_2 -> V_10 ,
L_31 ) ;
F_22 ( ( 1 << 26 ) , V_5 -> V_12 -> V_37 + V_61 ) ;
}
if ( F_17 ( V_111 & V_113 ) ) {
F_5 ( & V_5 -> V_2 -> V_10 ,
L_32 ) ;
F_22 ( ( 1 << 16 ) , V_5 -> V_12 -> V_37 + V_61 ) ;
}
if ( F_17 ( V_111 & ~ V_114 ) ) {
F_5 ( & V_5 -> V_2 -> V_10 ,
L_33 ,
( V_111 & ~ V_114 ) ) ;
if ( F_1 ( V_5 -> V_2 ) )
return;
}
if ( F_47 ( V_111 & ( V_28 | V_115 ) ) ) {
F_4 ( V_93 , & V_5 -> V_12 -> V_14 ) ;
F_6 ( & V_5 -> V_12 -> V_15 ) ;
}
}
static inline T_3 F_57 ( struct V_4 * V_116 )
{
struct V_4 * V_5 = (struct V_4 * ) V_116 ;
struct V_26 * V_12 = V_5 -> V_12 ;
T_2 V_117 , V_111 ;
int V_70 = V_118 ;
int V_119 = 1 , V_52 , V_120 ;
struct V_121 * V_122 ;
V_117 = F_23 ( V_5 -> V_37 + V_65 ) ;
if ( V_117 ) {
V_70 = V_123 ;
V_111 = F_23 ( V_12 -> V_37 + V_64 ) ;
F_22 ( V_111 , V_12 -> V_37 + V_64 ) ;
if ( F_47 ( V_111 & V_124 ) ) {
V_119 = 0 ;
F_52 ( F_58 ( & V_5 -> V_110 ) != 0 ) ;
for ( V_52 = 0 , V_120 = 0 ; V_52 < V_125 ;
V_52 ++ ) {
V_122 = & V_5 -> V_126 [ V_52 ] ;
V_122 -> V_63 = F_23 ( V_12 -> V_63 [ V_52 ] ) ;
if ( V_122 -> V_63 )
V_120 ++ ;
}
F_59 ( & V_5 -> V_110 , V_120 ) ;
if ( V_120 ) {
for ( V_52 = 1 ; V_52 < V_125 ; V_52 ++ ) {
V_122 = & V_5 -> V_126 [ V_52 ] ;
if ( V_122 -> V_63 )
F_60 (
V_122 -> V_127 ,
V_5 -> V_128 ,
& V_122 -> V_126 ) ;
}
if ( F_47 ( V_5 -> V_126 [ 0 ] . V_63 ) )
F_51 ( V_12 , 0 ,
V_5 -> V_126 [ 0 ] . V_63 ) ;
} else {
V_119 = 1 ;
}
}
if ( F_17 ( V_111 & V_129 ) ) {
if ( F_17 ( F_1 ( V_5 -> V_2 ) ) ) {
return V_123 ;
}
if ( F_26 ( V_40 ,
& V_5 -> V_41 ) )
return V_70 ;
F_56 ( V_5 , V_111 & V_129 ) ;
}
if ( F_17 ( V_111 & V_130 ) )
F_55 ( V_5 , V_111 & V_130 ) ;
}
if ( F_17 ( V_119 ) )
F_22 ( V_117 , V_5 -> V_37 + V_65 ) ;
return V_70 ;
}
static T_3 F_61 ( int V_131 , void * V_132 )
{
struct V_4 * V_5 = V_132 ;
return F_57 ( V_5 ) ;
}
static void F_62 ( struct V_26 * V_12 , int V_21 )
{
F_22 ( 1 << F_30 ( V_21 ) ,
V_12 -> V_45 [ F_31 ( V_21 ) ] ) ;
}
static bool F_63 ( struct V_26 * V_12 ,
struct V_85 * V_86 )
{
struct V_85 * V_133 ;
unsigned long V_134 ;
V_133 = V_12 -> V_135 + V_136 ;
V_134 = F_23 ( V_12 -> V_37 + V_137 ) ;
if ( V_86 -> V_79 == V_138 )
F_50 ( V_105 , & V_12 -> V_5 -> V_41 ) ;
if ( ( V_134 & 1 ) )
return false ;
if ( V_86 -> V_79 == V_139 ) {
F_4 ( V_140 , & V_12 -> V_14 ) ;
F_4 ( V_105 , & V_12 -> V_5 -> V_41 ) ;
V_12 -> V_141 = V_39 ;
return true ;
} else if ( ( V_86 -> V_79 == V_142 ) &&
( V_86 -> V_143 == 0x03 ) ) {
F_4 ( V_144 , & V_12 -> V_14 ) ;
V_12 -> V_141 = V_39 ;
return true ;
} else if ( ( V_86 -> V_79 == V_138 ) ||
( ( V_86 -> V_79 == 0xFC ) &&
( V_86 -> V_143 == 0x27 || V_86 -> V_143 == 0x72 ||
V_86 -> V_143 == 0x62 || V_86 -> V_143 == 0x26 ) ) ) {
F_38 ( V_12 ) ;
return false ;
}
return false ;
}
static int F_64 ( struct V_26 * V_12 , unsigned long V_35 )
{
unsigned long V_145 ;
unsigned int V_146 ;
unsigned int V_147 = 1 ;
F_65 ( V_12 -> V_5 -> V_7 ) ;
V_145 = V_39 + F_24 ( V_35 ) ;
do {
if ( F_26 ( V_148 , & V_12 -> V_14 ) &&
F_26 ( V_149 , & V_12 -> V_14 ) ) {
F_66 ( 20 ) ;
continue;
}
F_66 ( 100 ) ;
if ( F_1 ( V_12 -> V_5 -> V_2 ) )
goto V_150;
if ( F_26 ( V_40 , & V_12 -> V_5 -> V_41 ) )
goto V_150;
V_147 = F_23 ( V_12 -> V_44 [ 0 ] ) & 0xFFFFFFFE ;
for ( V_146 = 1 ; V_146 < V_12 -> V_5 -> V_62 ; V_146 ++ )
V_147 |= F_23 ( V_12 -> V_44 [ V_146 ] ) ;
if ( ! V_147 )
break;
} while ( F_27 ( V_39 , V_145 ) );
F_67 ( V_12 -> V_5 -> V_7 , true ) ;
return V_147 ? - V_151 : 0 ;
V_150:
F_67 ( V_12 -> V_5 -> V_7 , true ) ;
return - V_71 ;
}
static int F_68 ( struct V_26 * V_12 ,
struct V_85 * V_86 ,
int V_152 ,
T_4 V_153 ,
int V_154 ,
T_2 V_155 ,
T_5 V_156 ,
unsigned long V_35 )
{
struct V_157 * V_158 ;
F_69 ( V_159 ) ;
struct V_16 * V_160 ;
struct V_4 * V_5 = V_12 -> V_5 ;
int V_70 = 0 ;
if ( V_153 & 0x00000007 ) {
F_39 ( & V_5 -> V_2 -> V_10 , L_34 ) ;
return - V_71 ;
}
V_160 = F_7 ( V_5 ) ;
F_4 ( V_94 , & V_12 -> V_14 ) ;
V_12 -> V_141 = 0 ;
F_50 ( V_140 , & V_12 -> V_14 ) ;
F_50 ( V_144 , & V_12 -> V_14 ) ;
if ( V_156 == V_161 ) {
if ( V_86 -> V_79 != V_162 ) {
if ( F_64 ( V_12 ,
V_163 ) < 0 ) {
F_5 ( & V_5 -> V_2 -> V_10 ,
L_35 ) ;
F_10 ( V_5 , V_160 ) ;
F_50 ( V_94 , & V_12 -> V_14 ) ;
F_6 ( & V_12 -> V_15 ) ;
return - V_151 ;
}
}
V_160 -> V_82 = & V_159 ;
V_160 -> V_98 = F_42 ;
} else {
V_160 -> V_82 = NULL ;
V_160 -> V_98 = F_44 ;
}
memcpy ( V_160 -> V_79 , V_86 , V_152 * 4 ) ;
V_160 -> V_164 -> V_155 =
V_165 F_70 ( V_155 | V_152 ) ;
if ( V_154 ) {
V_158 = V_160 -> V_79 + V_166 ;
V_158 -> V_167 =
V_165 F_70 ( ( V_154 - 1 ) & 0x3FFFFF ) ;
V_158 -> V_168 =
V_165 F_70 ( V_153 & 0xFFFFFFFF ) ;
V_158 -> V_169 =
V_165 F_70 ( ( V_153 >> 16 ) >> 16 ) ;
V_160 -> V_164 -> V_155 |=
V_165 F_70 ( ( 1 << 16 ) ) ;
}
V_160 -> V_164 -> V_170 = 0 ;
F_62 ( V_12 , V_95 ) ;
if ( V_156 == V_161 ) {
if ( ( V_70 = F_71 (
& V_159 ,
F_24 ( V_35 ) ) ) <= 0 ) {
if ( V_70 == - V_171 ) {
F_39 ( & V_5 -> V_2 -> V_10 ,
L_36 ,
V_86 -> V_79 , V_35 ) ;
V_70 = - V_172 ;
goto V_173;
} else if ( V_70 == 0 )
F_39 ( & V_5 -> V_2 -> V_10 ,
L_37 ,
V_86 -> V_79 , V_35 ) ;
else
F_39 ( & V_5 -> V_2 -> V_10 ,
L_38 ,
V_86 -> V_79 , V_70 , V_35 ) ;
if ( F_1 ( V_5 -> V_2 ) ||
F_26 ( V_40 ,
& V_5 -> V_41 ) ) {
F_39 ( & V_5 -> V_2 -> V_10 ,
L_39 ,
V_86 -> V_79 ) ;
V_70 = - V_174 ;
goto V_173;
}
F_40 ( V_5 ) ;
V_70 = - V_175 ;
goto V_173;
}
} else {
T_2 V_117 , V_111 ;
V_35 = V_39 + F_24 ( V_35 ) ;
while ( ( F_23 ( V_12 -> V_45 [ V_95 ] )
& ( 1 << V_95 ) )
&& F_27 ( V_39 , V_35 ) ) {
if ( F_1 ( V_5 -> V_2 ) ) {
V_70 = - V_174 ;
goto V_173;
}
if ( ( V_86 -> V_79 != V_162 ) &&
F_26 ( V_40 ,
& V_5 -> V_41 ) ) {
V_70 = - V_174 ;
goto V_173;
}
V_111 = F_23 ( V_12 -> V_37 + V_64 ) ;
if ( ! V_111 )
continue;
if ( V_111 & V_129 ) {
F_39 ( & V_5 -> V_2 -> V_10 ,
L_40 ,
V_86 -> V_79 ) ;
F_40 ( V_5 ) ;
V_70 = - V_34 ;
goto V_173;
} else {
F_22 ( V_111 , V_12 -> V_37 + V_64 ) ;
V_117 = F_23 ( V_5 -> V_37 + V_65 ) ;
if ( V_117 )
F_22 ( V_117 ,
V_5 -> V_37 + V_65 ) ;
}
break;
}
}
if ( F_23 ( V_12 -> V_45 [ V_95 ] )
& ( 1 << V_95 ) ) {
V_70 = - V_174 ;
if ( ! F_26 ( V_40 , & V_5 -> V_41 ) ) {
F_40 ( V_5 ) ;
V_70 = - V_175 ;
}
}
V_173:
F_10 ( V_5 , V_160 ) ;
if ( V_70 >= 0 && F_63 ( V_12 , V_86 ) ) {
return V_70 ;
}
F_50 ( V_94 , & V_12 -> V_14 ) ;
F_6 ( & V_12 -> V_15 ) ;
return V_70 ;
}
static inline void F_72 ( T_1 * V_89 , unsigned int V_176 )
{
int V_52 ;
for ( V_52 = 0 ; V_52 < ( V_176 / 2 ) ; V_52 ++ )
F_73 ( & V_89 [ V_52 ] ) ;
}
static void F_74 ( struct V_4 * V_5 ,
struct V_85 * V_86 ,
unsigned int * V_35 , T_6 V_177 )
{
switch ( V_86 -> V_79 ) {
case V_142 :
* V_35 = 120000 ;
break;
case V_138 :
case 0xFC :
if ( V_177 )
* V_35 = ( ( * ( V_5 -> V_12 -> V_178 + 90 ) * 2 ) * 60000 ) ;
else
* V_35 = ( ( * ( V_5 -> V_12 -> V_178 + 89 ) * 2 ) * 60000 ) ;
break;
case V_162 :
* V_35 = 120000 ;
break;
case 0xF7 :
case 0xFA :
* V_35 = 60000 ;
break;
case V_179 :
* V_35 = 15000 ;
break;
default:
* V_35 = V_180 ;
break;
}
}
static int F_75 ( struct V_26 * V_12 , void T_7 * V_181 )
{
int V_70 = 0 ;
struct V_85 V_86 ;
if ( F_26 ( V_40 , & V_12 -> V_5 -> V_41 ) )
return - V_71 ;
memset ( & V_86 , 0 , sizeof( struct V_85 ) ) ;
V_86 . type = 0x27 ;
V_86 . V_155 = 1 << 7 ;
V_86 . V_79 = V_182 ;
V_12 -> V_183 = 0 ;
memset ( V_12 -> V_178 , 0 , sizeof( T_1 ) * V_184 ) ;
if ( F_68 ( V_12 ,
& V_86 ,
5 ,
V_12 -> V_185 ,
sizeof( T_1 ) * V_184 ,
0 ,
V_161 ,
V_186 )
< 0 ) {
V_70 = - 1 ;
goto V_187;
}
#ifdef F_76
F_72 ( V_12 -> V_178 + 27 , 40 ) ;
F_72 ( V_12 -> V_178 + 23 , 8 ) ;
F_72 ( V_12 -> V_178 + 10 , 20 ) ;
#else
{
int V_52 ;
for ( V_52 = 0 ; V_52 < V_184 ; V_52 ++ )
V_12 -> V_178 [ V_52 ] = F_77 ( V_12 -> V_178 [ V_52 ] ) ;
}
#endif
if ( V_12 -> V_178 [ 128 ] & 0x4 )
F_4 ( V_105 , & V_12 -> V_5 -> V_41 ) ;
else
F_50 ( V_105 , & V_12 -> V_5 -> V_41 ) ;
#ifdef F_78
if ( V_12 -> V_178 [ 69 ] & ( 1 << 14 ) && V_12 -> V_178 [ 69 ] & ( 1 << 5 ) )
V_12 -> V_5 -> V_188 = true ;
else
#endif
V_12 -> V_5 -> V_188 = false ;
V_12 -> V_183 = 1 ;
if ( V_181 ) {
if ( F_79 (
V_181 ,
V_12 -> V_178 ,
V_184 * sizeof( T_1 ) ) ) {
V_70 = - V_71 ;
goto V_187;
}
}
V_187:
return V_70 ;
}
static int F_80 ( struct V_26 * V_12 )
{
int V_70 ;
struct V_85 V_86 ;
unsigned long V_189 ;
unsigned int V_35 ;
memset ( & V_86 , 0 , sizeof( struct V_85 ) ) ;
V_86 . type = 0x27 ;
V_86 . V_155 = 1 << 7 ;
V_86 . V_79 = V_162 ;
F_74 ( V_12 -> V_5 , & V_86 , & V_35 , 0 ) ;
V_189 = V_39 ;
V_70 = F_68 ( V_12 ,
& V_86 ,
5 ,
0 ,
0 ,
0 ,
V_190 ,
V_35 ) ;
F_46 ( V_97 L_41 ,
F_81 ( V_39 - V_189 ) ) ;
if ( V_70 )
F_5 ( & V_12 -> V_5 -> V_2 -> V_10 ,
L_42 ) ;
return V_70 ;
}
static int F_48 ( struct V_26 * V_12 , T_6 V_191 , T_1 * V_153 ,
T_4 V_192 , unsigned int V_193 )
{
struct V_85 V_86 ;
memset ( & V_86 , 0 , sizeof( struct V_85 ) ) ;
V_86 . type = 0x27 ;
V_86 . V_155 = 1 << 7 ;
V_86 . V_79 = V_194 ;
V_86 . V_195 = V_193 & 0xFF ;
V_86 . V_196 = ( V_193 >> 8 ) & 0xFF ;
V_86 . V_197 = V_191 ;
V_86 . V_198 = 0 ;
V_86 . V_199 = V_200 ;
memset ( V_153 , 0 , V_193 * V_201 ) ;
return F_68 ( V_12 ,
& V_86 ,
5 ,
V_192 ,
V_193 * V_201 ,
0 ,
V_190 ,
V_186 ) ;
}
static int F_82 ( struct V_26 * V_12 , T_6 * V_153 ,
T_4 V_192 )
{
struct V_85 V_86 ;
memset ( & V_86 , 0 , sizeof( struct V_85 ) ) ;
V_86 . type = 0x27 ;
V_86 . V_155 = 1 << 7 ;
V_86 . V_79 = V_179 ;
V_86 . V_143 = 0xD0 ;
V_86 . V_195 = 1 ;
V_86 . V_198 = 0x4F ;
V_86 . V_202 = 0xC2 ;
V_86 . V_199 = V_200 ;
return F_68 ( V_12 ,
& V_86 ,
5 ,
V_192 ,
V_201 ,
0 ,
V_190 ,
15000 ) ;
}
static int F_83 ( struct V_26 * V_12 , unsigned int V_203 ,
struct V_204 * V_205 )
{
int V_70 , V_52 ;
struct V_204 * V_206 ;
if ( ! V_205 )
return - V_207 ;
if ( ! V_12 -> V_183 ) {
F_5 ( & V_12 -> V_5 -> V_2 -> V_10 , L_43 ) ;
return - V_208 ;
}
if ( ! ( V_12 -> V_178 [ 82 ] & 0x1 ) ) {
F_5 ( & V_12 -> V_5 -> V_2 -> V_10 , L_44 ) ;
return - V_208 ;
}
if ( ! ( V_12 -> V_178 [ 85 ] & 0x1 ) ) {
F_5 ( & V_12 -> V_5 -> V_2 -> V_10 , L_45 ) ;
return - V_208 ;
}
memset ( V_12 -> V_209 , 0 , V_201 ) ;
V_70 = F_82 ( V_12 , V_12 -> V_209 , V_12 -> V_210 ) ;
if ( V_70 ) {
F_5 ( & V_12 -> V_5 -> V_2 -> V_10 , L_46 ) ;
return V_70 ;
}
V_206 = (struct V_204 * ) ( V_12 -> V_209 + 2 ) ;
for ( V_52 = 0 ; V_52 < 29 ; V_52 ++ , V_206 ++ )
if ( V_206 -> V_211 == V_203 ) {
memcpy ( V_205 , V_206 , sizeof( struct V_204 ) ) ;
break;
}
if ( V_52 == 29 ) {
F_5 ( & V_12 -> V_5 -> V_2 -> V_10 ,
L_47 ) ;
V_70 = - V_207 ;
}
return V_70 ;
}
static int F_84 ( struct V_4 * V_5 , unsigned int V_212 ,
unsigned int V_176 )
{
int V_52 , V_70 = 0 ;
T_8 V_213 , V_214 , V_215 ;
struct V_216 * V_89 ;
T_4 V_217 ;
struct V_85 V_86 ;
if ( ! V_176 || V_5 -> V_188 == false )
return - V_207 ;
F_85 ( V_176 > ( V_218 * V_219 ) ) ;
F_85 ( V_176 % 8 != 0 ) ;
F_85 ( sizeof( struct V_220 ) > V_201 ) ;
V_89 = F_86 ( & V_5 -> V_2 -> V_10 , V_201 , & V_217 ,
V_161 ) ;
if ( ! V_89 )
return - V_221 ;
memset ( V_89 , 0 , V_201 ) ;
for ( V_52 = 0 , V_215 = V_176 , V_213 = V_212 ;
V_52 < V_219 && V_215 ;
V_52 ++ ) {
V_214 = ( V_215 >= V_218 ?
V_218 :
V_215 ) ;
V_89 [ V_52 ] . V_212 = V_165 F_70 ( V_213 ) ;
V_89 [ V_52 ] . V_222 = V_165 F_87 ( V_214 ) ;
V_213 += V_214 ;
V_215 -= V_214 ;
}
F_85 ( V_215 != 0 ) ;
memset ( & V_86 , 0 , sizeof( struct V_85 ) ) ;
V_86 . type = 0x27 ;
V_86 . V_155 = 1 << 7 ;
V_86 . V_79 = 0xfb ;
V_86 . V_143 = 0x60 ;
V_86 . V_195 = 1 ;
V_86 . V_199 = V_200 ;
if ( F_68 ( V_5 -> V_12 ,
& V_86 ,
5 ,
V_217 ,
V_201 ,
0 ,
V_161 ,
V_223 ) < 0 )
V_70 = - V_34 ;
F_88 ( & V_5 -> V_2 -> V_10 , V_201 , V_89 , V_217 ) ;
return V_70 ;
}
static bool F_89 ( struct V_4 * V_5 , T_9 * V_193 )
{
struct V_26 * V_12 = V_5 -> V_12 ;
T_8 V_224 , V_225 , V_226 , V_227 , V_228 ;
V_225 = V_12 -> V_178 [ 100 ] ;
V_226 = V_12 -> V_178 [ 101 ] ;
V_227 = V_12 -> V_178 [ 102 ] ;
V_228 = V_12 -> V_178 [ 103 ] ;
V_224 = V_225 | V_226 << 16 | V_227 << 32 | V_228 << 48 ;
* V_193 = V_224 ;
return ( bool ) ! ! V_12 -> V_183 ;
}
static void F_90 ( struct V_26 * V_12 )
{
T_9 V_193 ;
unsigned short V_229 ;
char V_230 [ 42 ] ;
if ( ! V_12 -> V_183 )
return;
F_91 ( V_230 , ( char * ) ( V_12 -> V_178 + 10 ) , 21 ) ;
F_49 ( & V_12 -> V_5 -> V_2 -> V_10 ,
L_48 , V_230 ) ;
F_91 ( V_230 , ( char * ) ( V_12 -> V_178 + 23 ) , 9 ) ;
F_49 ( & V_12 -> V_5 -> V_2 -> V_10 ,
L_49 , V_230 ) ;
F_91 ( V_230 , ( char * ) ( V_12 -> V_178 + 27 ) , 41 ) ;
F_49 ( & V_12 -> V_5 -> V_2 -> V_10 , L_50 , V_230 ) ;
F_49 ( & V_12 -> V_5 -> V_2 -> V_10 , L_51 ,
V_12 -> V_178 [ 128 ] ,
V_12 -> V_178 [ 128 ] & 0x4 ? L_52 : L_53 ) ;
if ( F_89 ( V_12 -> V_5 , & V_193 ) )
F_49 ( & V_12 -> V_5 -> V_2 -> V_10 ,
L_54 ,
( T_8 ) V_193 ,
( ( T_8 ) V_193 ) * V_201 >> 20 ) ;
F_3 ( V_12 -> V_5 -> V_2 , V_231 , & V_229 ) ;
switch ( V_229 & 0xFF ) {
case 0x1 :
F_91 ( V_230 , L_55 , 3 ) ;
break;
case 0x3 :
F_91 ( V_230 , L_56 , 3 ) ;
break;
default:
F_91 ( V_230 , L_57 , 2 ) ;
break;
}
F_49 ( & V_12 -> V_5 -> V_2 -> V_10 ,
L_58 , V_230 ) ;
}
static inline void F_92 ( struct V_4 * V_5 ,
struct V_16 * V_79 ,
int V_232 )
{
int V_146 ;
unsigned int V_233 ;
struct V_157 * V_158 ;
struct V_234 * V_29 = V_79 -> V_29 ;
V_158 = V_79 -> V_79 + V_166 ;
for ( V_146 = 0 ; V_146 < V_232 ; V_146 ++ ) {
V_233 = F_93 ( V_29 ) ;
if ( V_233 > 0x400000 )
F_39 ( & V_5 -> V_2 -> V_10 ,
L_59 ) ;
V_158 -> V_167 = V_165
F_70 ( ( V_233 - 1 ) & 0x3FFFFF ) ;
V_158 -> V_168 = V_165
F_70 ( F_94 ( V_29 ) ) ;
V_158 -> V_169 = V_165
F_70 ( ( F_94 ( V_29 ) >> 16 ) >> 16 ) ;
V_158 ++ ;
V_29 ++ ;
}
}
static int F_95 ( struct V_26 * V_12 , T_6 * V_79 )
{
struct V_85 V_86 ;
struct V_85 * V_133 = ( V_12 -> V_135 + V_136 ) ;
unsigned int V_145 ;
memset ( & V_86 , 0 , sizeof( struct V_85 ) ) ;
V_86 . type = 0x27 ;
V_86 . V_155 = 1 << 7 ;
V_86 . V_79 = V_79 [ 0 ] ;
V_86 . V_143 = V_79 [ 1 ] ;
V_86 . V_195 = V_79 [ 2 ] ;
V_86 . V_235 = V_79 [ 3 ] ;
V_86 . V_236 = V_79 [ 4 ] ;
V_86 . V_237 = V_79 [ 5 ] ;
V_86 . V_199 = V_79 [ 6 ] & ~ 0x10 ;
F_74 ( V_12 -> V_5 , & V_86 , & V_145 , 0 ) ;
F_46 ( V_97 L_60 ,
V_11 ,
V_79 [ 0 ] ,
V_79 [ 1 ] ,
V_79 [ 2 ] ,
V_79 [ 3 ] ,
V_79 [ 4 ] ,
V_79 [ 5 ] ,
V_79 [ 6 ] ) ;
if ( F_68 ( V_12 ,
& V_86 ,
5 ,
0 ,
0 ,
0 ,
V_161 ,
V_145 ) < 0 ) {
return - 1 ;
}
V_79 [ 0 ] = V_133 -> V_79 ;
V_79 [ 1 ] = V_133 -> V_143 ;
V_79 [ 4 ] = V_133 -> V_236 ;
V_79 [ 5 ] = V_133 -> V_237 ;
F_46 ( V_97 L_61 ,
V_11 ,
V_79 [ 0 ] ,
V_79 [ 1 ] ,
V_79 [ 4 ] ,
V_79 [ 5 ] ) ;
return 0 ;
}
static int F_96 ( struct V_26 * V_12 , T_6 * V_79 ,
void T_7 * V_181 )
{
struct V_85 V_86 ;
struct V_85 * V_133 ;
T_6 * V_89 = NULL ;
T_4 V_217 = 0 ;
int V_70 = 0 , V_238 = V_79 [ 3 ] ;
unsigned int V_145 ;
if ( V_238 ) {
if ( ! V_181 )
return - V_71 ;
V_89 = F_86 ( & V_12 -> V_5 -> V_2 -> V_10 ,
V_201 * V_238 ,
& V_217 ,
V_161 ) ;
if ( ! V_89 ) {
F_39 ( & V_12 -> V_5 -> V_2 -> V_10 ,
L_62 ,
V_201 * V_238 ) ;
return - V_221 ;
}
memset ( V_89 , 0 , V_201 * V_238 ) ;
}
memset ( & V_86 , 0 , sizeof( struct V_85 ) ) ;
V_86 . type = 0x27 ;
V_86 . V_155 = 1 << 7 ;
V_86 . V_79 = V_79 [ 0 ] ;
V_86 . V_143 = V_79 [ 2 ] ;
V_86 . V_195 = V_79 [ 3 ] ;
if ( V_86 . V_79 == V_179 ) {
V_86 . V_235 = V_79 [ 1 ] ;
V_86 . V_236 = 0x4F ;
V_86 . V_237 = 0xC2 ;
}
F_74 ( V_12 -> V_5 , & V_86 , & V_145 , 0 ) ;
if ( V_238 )
V_133 = ( V_12 -> V_135 + V_239 ) ;
else
V_133 = ( V_12 -> V_135 + V_136 ) ;
F_46 ( V_97
L_63
L_64 ,
V_11 ,
V_79 [ 0 ] ,
V_79 [ 1 ] ,
V_79 [ 2 ] ,
V_79 [ 3 ] ) ;
if ( F_68 ( V_12 ,
& V_86 ,
5 ,
( V_238 ? V_217 : 0 ) ,
( V_238 ? V_201 * V_238 : 0 ) ,
0 ,
V_161 ,
V_145 )
< 0 ) {
V_70 = - V_71 ;
goto V_240;
}
V_79 [ 0 ] = V_133 -> V_79 ;
V_79 [ 1 ] = V_133 -> V_143 ;
V_79 [ 2 ] = V_133 -> V_195 ;
F_46 ( V_97
L_65
L_66 ,
V_11 ,
V_79 [ 0 ] ,
V_79 [ 1 ] ,
V_79 [ 2 ] ) ;
if ( V_238 ) {
if ( F_79 ( V_181 ,
V_89 ,
V_201 * V_79 [ 3 ] ) ) {
V_70 = - V_71 ;
goto V_240;
}
}
V_240:
if ( V_89 )
F_88 ( & V_12 -> V_5 -> V_2 -> V_10 ,
V_201 * V_238 , V_89 , V_217 ) ;
return V_70 ;
}
static unsigned int F_97 ( unsigned char V_79 ,
unsigned char V_143 )
{
unsigned int V_70 = 0 ;
switch ( V_79 ) {
case V_241 :
case V_242 :
case V_139 :
case V_138 :
case V_243 :
case V_244 :
case V_245 :
case V_246 :
V_70 = 1 ;
break;
case V_247 :
if ( V_143 == V_248 )
V_70 = 1 ;
break;
case V_179 :
if ( ( V_143 == V_249 ) ||
( V_143 == V_250 ) )
V_70 = 1 ;
break;
case V_251 :
if ( ( V_143 == V_252 ) ||
( V_143 == V_253 ) )
V_70 = 1 ;
break;
}
return V_70 ;
}
static int F_98 ( struct V_4 * V_5 ,
void T_7 * V_89 ,
T_10 * V_254 ,
int V_255 )
{
struct V_85 V_86 ;
struct V_85 * V_133 ;
T_6 * V_256 = NULL ;
T_6 * V_257 = NULL ;
T_4 V_258 = 0 ;
T_4 V_259 = 0 ;
T_4 V_260 = 0 ;
int V_261 = 0 ;
unsigned int V_262 = 0 ;
unsigned int V_263 = 0 ;
T_6 V_264 = 0 ;
unsigned int V_35 ;
unsigned int V_265 ;
unsigned int V_266 ;
unsigned long V_134 ;
int V_267 = V_255 + V_254 -> V_268 ;
int V_177 = 0 ;
V_263 = V_254 -> V_268 ;
V_262 = V_254 -> V_269 ;
if ( V_262 > 130560 || V_263 > 130560 ) {
V_261 = - V_207 ;
goto abort;
}
if ( V_263 ) {
V_256 = F_99 ( V_263 , V_161 ) ;
if ( V_256 == NULL ) {
V_261 = - V_221 ;
goto abort;
}
if ( F_100 ( V_256 , V_89 + V_255 , V_263 ) ) {
V_261 = - V_71 ;
goto abort;
}
V_258 = F_101 ( V_5 -> V_2 ,
V_256 ,
V_263 ,
V_270 ) ;
if ( V_258 == 0 ) {
V_261 = - V_221 ;
goto abort;
}
V_260 = V_258 ;
}
if ( V_262 ) {
V_257 = F_99 ( V_262 , V_161 ) ;
if ( V_257 == NULL ) {
V_261 = - V_221 ;
goto abort;
}
if ( F_100 ( V_257 , V_89 + V_267 , V_262 ) ) {
V_261 = - V_71 ;
goto abort;
}
V_259 = F_101 ( V_5 -> V_2 ,
V_257 ,
V_262 , V_271 ) ;
if ( V_259 == 0 ) {
V_261 = - V_221 ;
goto abort;
}
V_260 = V_259 ;
}
switch ( V_254 -> V_272 ) {
case V_273 :
V_264 = V_263 / V_201 ;
V_133 = ( V_5 -> V_12 -> V_135 + V_239 ) ;
break;
case V_274 :
V_133 = ( V_5 -> V_12 -> V_135 + V_239 ) ;
break;
case V_275 :
V_133 = ( V_5 -> V_12 -> V_135 + V_136 ) ;
break;
default:
V_261 = - V_207 ;
goto abort;
}
memset ( & V_86 , 0 , sizeof( struct V_85 ) ) ;
V_86 . type = 0x27 ;
V_86 . V_155 = 1 << 7 ;
V_86 . V_79 = V_254 -> V_276 [ 7 ] ;
V_86 . V_143 = V_254 -> V_276 [ 1 ] ;
V_86 . V_195 = V_254 -> V_276 [ 2 ] ;
V_86 . V_197 = V_254 -> V_276 [ 3 ] ;
V_86 . V_198 = V_254 -> V_276 [ 4 ] ;
V_86 . V_202 = V_254 -> V_276 [ 5 ] ;
V_86 . V_199 = V_254 -> V_276 [ 6 ] & ~ 0x10 ;
if ( ( V_254 -> V_277 . V_278 == 0 ) && ( V_254 -> V_279 . V_278 & 1 ) ) {
V_254 -> V_277 . V_278 =
V_280 |
( V_281 << 8 ) ;
V_86 . V_282 = V_254 -> V_283 [ 3 ] ;
V_86 . V_284 = V_254 -> V_283 [ 4 ] ;
V_86 . V_285 = V_254 -> V_283 [ 5 ] ;
V_86 . V_286 = V_254 -> V_283 [ 1 ] ;
V_86 . V_196 = V_254 -> V_283 [ 2 ] ;
} else {
V_254 -> V_277 . V_278 = V_280 ;
}
V_265 = F_97 ( V_86 . V_79 , V_86 . V_143 ) ;
if ( ( V_262 || V_263 ) && ( ! V_86 . V_195 ) ) {
if ( V_264 )
V_86 . V_195 = V_264 ;
else {
if ( ! V_265 ) {
F_5 ( & V_5 -> V_2 -> V_10 ,
L_67
L_68 ) ;
V_261 = - V_207 ;
goto abort;
}
}
}
F_46 ( V_97
L_69
L_70
L_71 ,
V_11 ,
V_86 . V_79 ,
V_86 . V_143 ,
V_86 . V_195 ,
V_86 . V_197 ,
V_86 . V_198 ,
V_86 . V_202 ,
V_86 . V_199 ) ;
if ( ( V_86 . V_79 == V_138 ) && V_256 &&
( V_256 [ 0 ] & V_287 ) ) {
V_177 = 1 ;
}
F_74 ( V_5 , & V_86 , & V_35 , V_177 ) ;
if ( V_265 )
V_266 = V_201 ;
else
V_266 = V_201 * V_86 . V_195 ;
if ( F_68 ( V_5 -> V_12 ,
& V_86 ,
5 ,
V_260 ,
V_266 ,
0 ,
V_161 ,
V_35 ) < 0 ) {
V_261 = - V_34 ;
goto abort;
}
V_134 = F_23 ( V_5 -> V_12 -> V_37 + V_137 ) ;
if ( ( V_254 -> V_272 == V_274 ) && ! ( V_134 & 1 ) ) {
V_133 = V_5 -> V_12 -> V_135 + V_239 ;
V_254 -> V_276 [ 7 ] = V_133 -> V_288 ;
} else {
V_133 = V_5 -> V_12 -> V_135 + V_136 ;
V_254 -> V_276 [ 7 ] = V_133 -> V_79 ;
}
if ( V_259 )
F_102 ( V_5 -> V_2 , V_259 ,
V_262 , V_271 ) ;
if ( V_258 )
F_102 ( V_5 -> V_2 , V_258 ,
V_263 , V_270 ) ;
V_259 = 0 ;
V_258 = 0 ;
V_254 -> V_276 [ 1 ] = V_133 -> V_143 ;
V_254 -> V_276 [ 2 ] = V_133 -> V_195 ;
V_254 -> V_276 [ 3 ] = V_133 -> V_197 ;
V_254 -> V_276 [ 4 ] = V_133 -> V_198 ;
V_254 -> V_276 [ 5 ] = V_133 -> V_202 ;
V_254 -> V_276 [ 6 ] = V_133 -> V_199 ;
if ( V_254 -> V_279 . V_278 & 1 ) {
V_254 -> V_283 [ 3 ] = V_133 -> V_282 ;
V_254 -> V_283 [ 4 ] = V_133 -> V_284 ;
V_254 -> V_283 [ 5 ] = V_133 -> V_285 ;
V_254 -> V_283 [ 1 ] = V_133 -> V_286 ;
V_254 -> V_283 [ 2 ] = V_133 -> V_196 ;
}
F_46 ( V_97
L_72
L_73
L_74 ,
V_11 ,
V_254 -> V_276 [ 7 ] ,
V_254 -> V_276 [ 1 ] ,
V_254 -> V_276 [ 2 ] ,
V_254 -> V_276 [ 3 ] ,
V_254 -> V_276 [ 4 ] ,
V_254 -> V_276 [ 5 ] ,
V_254 -> V_276 [ 6 ] ) ;
if ( V_263 ) {
if ( F_79 ( V_89 + V_255 , V_256 , V_263 ) ) {
V_261 = - V_71 ;
goto abort;
}
}
if ( V_262 ) {
if ( F_79 ( V_89 + V_267 , V_257 , V_262 ) ) {
V_261 = - V_71 ;
goto abort;
}
}
abort:
if ( V_259 )
F_102 ( V_5 -> V_2 , V_259 ,
V_262 , V_271 ) ;
if ( V_258 )
F_102 ( V_5 -> V_2 , V_258 ,
V_263 , V_270 ) ;
F_103 ( V_256 ) ;
F_103 ( V_257 ) ;
return V_261 ;
}
static int F_104 ( struct V_4 * V_5 , unsigned int V_20 ,
unsigned long V_289 )
{
switch ( V_20 ) {
case V_290 :
{
if ( F_79 ( ( void T_7 * ) V_289 , V_5 -> V_12 -> V_178 ,
sizeof( T_1 ) * V_184 ) )
return - V_71 ;
break;
}
case V_291 :
{
T_6 V_292 [ 4 ] ;
if ( F_100 ( V_292 ,
( void T_7 * ) V_289 ,
sizeof( V_292 ) ) )
return - V_71 ;
if ( F_96 ( V_5 -> V_12 ,
V_292 ,
( void T_7 * ) ( V_289 + 4 ) ) )
return - V_34 ;
if ( F_79 ( ( void T_7 * ) V_289 ,
V_292 ,
sizeof( V_292 ) ) )
return - V_71 ;
break;
}
case V_293 :
{
T_6 V_292 [ 7 ] ;
if ( F_100 ( V_292 ,
( void T_7 * ) V_289 ,
sizeof( V_292 ) ) )
return - V_71 ;
if ( F_95 ( V_5 -> V_12 , V_292 ) )
return - V_34 ;
if ( F_79 ( ( void T_7 * ) V_289 ,
V_292 ,
sizeof( V_292 ) ) )
return - V_71 ;
break;
}
case V_294 : {
T_10 V_254 ;
int V_295 , V_255 ;
if ( F_100 ( & V_254 , ( void T_7 * ) V_289 ,
sizeof( V_254 ) ) )
return - V_71 ;
V_255 = sizeof( V_254 ) ;
V_295 = F_98 ( V_5 , ( void T_7 * ) V_289 ,
& V_254 , V_255 ) ;
if ( F_79 ( ( void T_7 * ) V_289 , & V_254 ,
sizeof( V_254 ) ) )
return - V_71 ;
return V_295 ;
}
default:
return - V_207 ;
}
return 0 ;
}
static void F_105 ( struct V_4 * V_5 , struct V_17 * V_18 ,
struct V_16 * V_79 , int V_232 ,
struct V_22 * V_23 )
{
struct V_85 * V_86 ;
struct V_26 * V_12 = V_5 -> V_12 ;
int V_296 = F_106 ( V_18 ) == V_297 ? V_271 : V_270 ;
T_8 V_189 = F_107 ( V_18 ) ;
unsigned int V_264 = F_108 ( V_18 ) ;
V_232 = F_109 ( & V_5 -> V_2 -> V_10 , V_79 -> V_29 , V_232 , V_296 ) ;
F_110 ( & V_12 -> V_14 ) ;
V_79 -> V_30 = V_232 ;
V_79 -> V_109 = V_298 ;
V_86 = V_79 -> V_79 ;
V_86 -> type = 0x27 ;
V_86 -> V_155 = 1 << 7 ;
if ( V_296 == V_271 )
V_86 -> V_79 = V_299 ;
else
V_86 -> V_79 = V_107 ;
V_86 -> V_197 = V_189 & 0xFF ;
V_86 -> V_198 = ( V_189 >> 8 ) & 0xFF ;
V_86 -> V_202 = ( V_189 >> 16 ) & 0xFF ;
V_86 -> V_282 = ( V_189 >> 24 ) & 0xFF ;
V_86 -> V_284 = ( V_189 >> 32 ) & 0xFF ;
V_86 -> V_285 = ( V_189 >> 40 ) & 0xFF ;
V_86 -> V_199 = 1 << 6 ;
V_86 -> V_143 = V_264 & 0xFF ;
V_86 -> V_286 = ( V_264 >> 8 ) & 0xFF ;
V_86 -> V_195 = ( ( V_18 -> V_21 << 3 ) | ( V_18 -> V_21 >> 5 ) ) ;
V_86 -> V_196 = 0 ;
V_86 -> V_288 = 0 ;
V_86 -> V_300 = 0 ;
V_86 -> V_301 = 0 ;
F_92 ( V_5 , V_79 , V_232 ) ;
if ( F_17 ( V_79 -> V_32 ) )
V_86 -> V_199 |= 1 << 7 ;
V_79 -> V_164 -> V_155 =
V_165 F_70 (
( V_232 << 16 ) | 5 | V_302 ) ;
V_79 -> V_164 -> V_170 = 0 ;
V_79 -> V_82 = V_5 ;
V_79 -> V_98 = F_16 ;
V_79 -> V_31 = V_296 ;
if ( F_17 ( V_12 -> V_14 & V_303 ) ) {
F_4 ( V_18 -> V_21 , V_12 -> V_304 ) ;
F_4 ( V_149 , & V_12 -> V_14 ) ;
return;
}
F_28 ( V_12 , V_18 -> V_21 ) ;
}
static T_11 F_111 ( struct V_199 * V_10 ,
struct V_305 * V_306 ,
char * V_89 )
{
struct V_4 * V_5 = F_112 ( V_10 ) -> V_307 ;
int V_308 = 0 ;
if ( F_26 ( V_104 , & V_5 -> V_41 ) )
V_308 += sprintf ( V_89 , L_75 , L_76 ) ;
else if ( F_26 ( V_103 , & V_5 -> V_41 ) )
V_308 += sprintf ( V_89 , L_75 , L_77 ) ;
else
V_308 += sprintf ( V_89 , L_75 , L_78 ) ;
return V_308 ;
}
static T_11 F_113 ( struct V_309 * V_310 , char * V_89 )
{
int V_308 = 0 ;
struct V_4 * V_5 , * V_47 ;
unsigned long V_14 ;
char V_311 [ 42 ] ;
T_1 V_27 = 0 ;
F_114 ( & V_312 , V_14 ) ;
V_308 += sprintf ( & V_89 [ V_308 ] , L_79 ) ;
F_115 (dd, tmp, &online_list, online_list) {
if ( V_5 -> V_2 ) {
if ( V_5 -> V_12 &&
V_5 -> V_12 -> V_178 &&
V_5 -> V_12 -> V_183 ) {
F_91 ( V_311 ,
( char * ) ( V_5 -> V_12 -> V_178 + 10 ) , 21 ) ;
V_27 = * ( V_5 -> V_12 -> V_178 + 141 ) ;
} else {
memset ( V_311 , 0 , 42 ) ;
V_27 = 0 ;
}
if ( V_5 -> V_12 &&
F_26 ( V_313 , & V_5 -> V_12 -> V_14 ) ) {
V_308 += sprintf ( & V_89 [ V_308 ] ,
L_80 ,
F_116 ( & V_5 -> V_2 -> V_10 ) ,
V_311 ,
V_27 ) ;
} else {
V_308 += sprintf ( & V_89 [ V_308 ] ,
L_81 ,
F_116 ( & V_5 -> V_2 -> V_10 ) ,
V_311 ) ;
}
}
}
V_308 += sprintf ( & V_89 [ V_308 ] , L_82 ) ;
F_115 (dd, tmp, &removing_list, remove_list) {
if ( V_5 -> V_2 ) {
if ( V_5 -> V_12 &&
V_5 -> V_12 -> V_178 &&
V_5 -> V_12 -> V_183 ) {
F_91 ( V_311 ,
( char * ) ( V_5 -> V_12 -> V_178 + 10 ) , 21 ) ;
V_27 = * ( V_5 -> V_12 -> V_178 + 141 ) ;
} else {
memset ( V_311 , 0 , 42 ) ;
V_27 = 0 ;
}
if ( V_5 -> V_12 &&
F_26 ( V_313 , & V_5 -> V_12 -> V_14 ) ) {
V_308 += sprintf ( & V_89 [ V_308 ] ,
L_80 ,
F_116 ( & V_5 -> V_2 -> V_10 ) ,
V_311 ,
V_27 ) ;
} else {
V_308 += sprintf ( & V_89 [ V_308 ] ,
L_81 ,
F_116 ( & V_5 -> V_2 -> V_10 ) ,
V_311 ) ;
}
}
}
F_117 ( & V_312 , V_14 ) ;
return V_308 ;
}
static T_11 F_118 ( struct V_314 * V_315 , char T_7 * V_316 ,
T_12 V_176 , T_13 * V_317 )
{
struct V_4 * V_5 = (struct V_4 * ) V_315 -> V_307 ;
int V_308 = * V_317 ;
char * V_89 ;
int V_70 = 0 ;
if ( ! V_176 || * V_317 )
return 0 ;
V_89 = F_99 ( V_318 , V_161 ) ;
if ( ! V_89 ) {
F_39 ( & V_5 -> V_2 -> V_10 ,
L_83 ) ;
return - V_221 ;
}
V_308 += F_113 ( NULL , V_89 ) ;
* V_317 = V_308 <= V_176 ? V_308 : V_176 ;
V_308 = F_79 ( V_316 , V_89 , * V_317 ) ;
if ( V_308 )
V_70 = - V_71 ;
F_103 ( V_89 ) ;
return V_70 ? V_70 : * V_317 ;
}
static T_11 F_119 ( struct V_314 * V_315 , char T_7 * V_316 ,
T_12 V_176 , T_13 * V_317 )
{
struct V_4 * V_5 = (struct V_4 * ) V_315 -> V_307 ;
char * V_89 ;
T_2 V_319 ;
int V_308 = * V_317 ;
int V_146 , V_70 = 0 ;
if ( ! V_176 || V_308 )
return 0 ;
V_89 = F_99 ( V_318 , V_161 ) ;
if ( ! V_89 ) {
F_39 ( & V_5 -> V_2 -> V_10 ,
L_84 ) ;
return - V_221 ;
}
V_308 += sprintf ( & V_89 [ V_308 ] , L_85 ) ;
for ( V_146 = V_5 -> V_62 - 1 ; V_146 >= 0 ; V_146 -- )
V_308 += sprintf ( & V_89 [ V_308 ] , L_86 ,
F_23 ( V_5 -> V_12 -> V_44 [ V_146 ] ) ) ;
V_308 += sprintf ( & V_89 [ V_308 ] , L_87 ) ;
V_308 += sprintf ( & V_89 [ V_308 ] , L_88 ) ;
for ( V_146 = V_5 -> V_62 - 1 ; V_146 >= 0 ; V_146 -- )
V_308 += sprintf ( & V_89 [ V_308 ] , L_86 ,
F_23 ( V_5 -> V_12 -> V_45 [ V_146 ] ) ) ;
V_308 += sprintf ( & V_89 [ V_308 ] , L_87 ) ;
V_308 += sprintf ( & V_89 [ V_308 ] , L_89 ) ;
for ( V_146 = V_5 -> V_62 - 1 ; V_146 >= 0 ; V_146 -- )
V_308 += sprintf ( & V_89 [ V_308 ] , L_86 ,
F_23 ( V_5 -> V_12 -> V_63 [ V_146 ] ) ) ;
V_308 += sprintf ( & V_89 [ V_308 ] , L_87 ) ;
V_308 += sprintf ( & V_89 [ V_308 ] , L_90 ,
F_23 ( V_5 -> V_12 -> V_37 + V_64 ) ) ;
V_308 += sprintf ( & V_89 [ V_308 ] , L_91 ,
F_23 ( V_5 -> V_37 + V_65 ) ) ;
V_308 += sprintf ( & V_89 [ V_308 ] , L_92 ) ;
V_308 += sprintf ( & V_89 [ V_308 ] , L_93 ) ;
for ( V_146 = V_5 -> V_62 - 1 ; V_146 >= 0 ; V_146 -- ) {
if ( sizeof( long ) > sizeof( T_2 ) )
V_319 =
V_5 -> V_12 -> V_96 [ V_146 / 2 ] >> ( 32 * ( V_146 & 1 ) ) ;
else
V_319 = V_5 -> V_12 -> V_96 [ V_146 ] ;
V_308 += sprintf ( & V_89 [ V_308 ] , L_86 , V_319 ) ;
}
V_308 += sprintf ( & V_89 [ V_308 ] , L_87 ) ;
V_308 += sprintf ( & V_89 [ V_308 ] , L_94 ) ;
for ( V_146 = V_5 -> V_62 - 1 ; V_146 >= 0 ; V_146 -- ) {
if ( sizeof( long ) > sizeof( T_2 ) )
V_319 =
V_5 -> V_12 -> V_304 [ V_146 / 2 ] >> ( 32 * ( V_146 & 1 ) ) ;
else
V_319 = V_5 -> V_12 -> V_304 [ V_146 ] ;
V_308 += sprintf ( & V_89 [ V_308 ] , L_86 , V_319 ) ;
}
V_308 += sprintf ( & V_89 [ V_308 ] , L_87 ) ;
* V_317 = V_308 <= V_176 ? V_308 : V_176 ;
V_308 = F_79 ( V_316 , V_89 , * V_317 ) ;
if ( V_308 )
V_70 = - V_71 ;
F_103 ( V_89 ) ;
return V_70 ? V_70 : * V_317 ;
}
static T_11 F_120 ( struct V_314 * V_315 , char T_7 * V_316 ,
T_12 V_176 , T_13 * V_317 )
{
struct V_4 * V_5 = (struct V_4 * ) V_315 -> V_307 ;
char * V_89 ;
int V_308 = * V_317 ;
int V_70 = 0 ;
if ( ! V_176 || V_308 )
return 0 ;
V_89 = F_99 ( V_318 , V_161 ) ;
if ( ! V_89 ) {
F_39 ( & V_5 -> V_2 -> V_10 ,
L_95 ) ;
return - V_221 ;
}
V_308 += sprintf ( & V_89 [ V_308 ] , L_96 ,
V_5 -> V_12 -> V_14 ) ;
V_308 += sprintf ( & V_89 [ V_308 ] , L_97 ,
V_5 -> V_41 ) ;
* V_317 = V_308 <= V_176 ? V_308 : V_176 ;
V_308 = F_79 ( V_316 , V_89 , * V_317 ) ;
if ( V_308 )
V_70 = - V_71 ;
F_103 ( V_89 ) ;
return V_70 ? V_70 : * V_317 ;
}
static int F_121 ( struct V_4 * V_5 , struct V_320 * V_321 )
{
if ( ! V_321 || ! V_5 )
return - V_207 ;
if ( F_122 ( V_321 , & V_322 . V_306 ) )
F_5 ( & V_5 -> V_2 -> V_10 ,
L_98 ) ;
return 0 ;
}
static int F_123 ( struct V_4 * V_5 , struct V_320 * V_321 )
{
if ( ! V_321 || ! V_5 )
return - V_207 ;
F_124 ( V_321 , & V_322 . V_306 ) ;
return 0 ;
}
static int F_125 ( struct V_4 * V_5 )
{
if ( ! V_323 )
return - 1 ;
V_5 -> V_324 = F_126 ( V_5 -> V_325 -> V_326 , V_323 ) ;
if ( F_127 ( V_5 -> V_324 ) ) {
F_5 ( & V_5 -> V_2 -> V_10 ,
L_99 ,
V_5 -> V_325 -> V_326 ) ;
V_5 -> V_324 = NULL ;
return - 1 ;
}
F_128 ( L_100 , V_327 , V_5 -> V_324 , V_5 ,
& V_328 ) ;
F_128 ( L_101 , V_327 , V_5 -> V_324 , V_5 ,
& V_329 ) ;
return 0 ;
}
static void F_129 ( struct V_4 * V_5 )
{
if ( V_5 -> V_324 )
F_130 ( V_5 -> V_324 ) ;
}
static int F_131 ( struct V_4 * V_5 )
{
struct V_320 * V_321 ;
if ( V_5 -> V_330 ) {
if ( V_5 -> V_330 -> V_331 >= 1 )
return - 2 ;
F_132 ( V_5 -> V_330 ) ;
V_5 -> V_330 = NULL ;
}
F_129 ( V_5 ) ;
F_29 ( & V_332 ) ;
F_133 ( & V_333 , V_5 -> V_334 ) ;
F_32 ( & V_332 ) ;
if ( ! F_26 ( V_335 , & V_5 -> V_41 ) &&
F_26 ( V_336 , & V_5 -> V_41 ) ) {
F_134 ( V_5 -> V_325 ) ;
} else {
if ( V_5 -> V_325 ) {
V_321 = F_135 ( & F_136 ( V_5 -> V_325 ) -> V_321 ) ;
if ( V_321 ) {
F_123 ( V_5 , V_321 ) ;
F_137 ( V_321 ) ;
}
F_138 ( V_5 -> V_325 ) ;
V_5 -> V_325 = NULL ;
}
if ( V_5 -> V_7 ) {
V_5 -> V_7 -> V_337 = NULL ;
F_139 ( V_5 -> V_7 ) ;
F_140 ( & V_5 -> V_25 ) ;
V_5 -> V_7 = NULL ;
}
}
F_103 ( V_5 ) ;
return 0 ;
}
static inline void F_141 ( struct V_4 * V_5 )
{
T_2 V_338 ;
V_338 = F_23 ( V_5 -> V_37 + V_339 ) ;
F_22 ( V_338 |
V_340 |
V_341 ,
V_5 -> V_37 + V_339 ) ;
}
static int F_142 ( struct V_4 * V_5 )
{
return ( V_5 -> V_2 -> V_199 == V_342 ? 1 : 0 ) ;
}
static void F_143 ( struct V_4 * V_5 )
{
T_2 V_338 ;
unsigned int V_343 , V_344 ;
V_338 = F_23 ( V_5 -> V_37 + V_339 ) ;
V_5 -> V_345 = V_346 ;
V_5 -> V_62 = 1 ;
if ( V_338 & 0x8 ) {
V_5 -> V_345 = V_347 ;
V_343 = ( V_338 & V_348 ) >> 8 ;
V_344 = ( V_338 & V_349 ) + 1 ;
F_49 ( & V_5 -> V_2 -> V_10 ,
L_102
L_103 ,
V_343 ,
V_344 ,
V_344 * 32 ) ;
if ( V_344 > V_125 ) {
F_5 ( & V_5 -> V_2 -> V_10 ,
L_104
L_105 , V_125 ) ;
V_344 = V_125 ;
}
V_5 -> V_62 = V_344 ;
return;
}
F_5 ( & V_5 -> V_2 -> V_10 , L_106 ) ;
}
static int F_144 ( struct V_4 * V_5 )
{
unsigned long V_35 , V_75 = 0 , V_189 ;
F_5 ( & V_5 -> V_2 -> V_10 ,
L_107 ) ;
V_189 = V_39 ;
V_35 = V_39 + F_24 ( V_350 ) ;
do {
if ( F_17 ( F_26 ( V_40 ,
& V_5 -> V_41 ) ) )
return - V_71 ;
if ( F_1 ( V_5 -> V_2 ) )
return - V_71 ;
if ( F_75 ( V_5 -> V_12 , NULL ) < 0 )
return - V_71 ;
if ( * ( V_5 -> V_12 -> V_178 + V_351 ) ==
V_352 ) {
F_145 ( 1 ) ;
if ( V_75 ++ >= 180 ) {
F_5 ( & V_5 -> V_2 -> V_10 ,
L_108 ,
F_81 ( V_39 - V_189 ) / 1000 ) ;
V_75 = 0 ;
}
} else {
F_5 ( & V_5 -> V_2 -> V_10 ,
L_109 ,
F_81 ( V_39 - V_189 ) / 1000 ) ;
F_146 ( V_5 ) ;
return 0 ;
}
F_145 ( 10 ) ;
} while ( F_27 ( V_39 , V_35 ) );
F_39 ( & V_5 -> V_2 -> V_10 ,
L_110 ,
F_81 ( V_39 - V_189 ) / 1000 ) ;
return - V_71 ;
}
static int F_147 ( void * V_116 )
{
struct V_4 * V_5 = (struct V_4 * ) V_116 ;
unsigned long V_353 , V_354 , V_355 ;
unsigned int V_356 = V_5 -> V_62 * 32 ;
struct V_26 * V_12 = V_5 -> V_12 ;
int V_295 ;
while ( 1 ) {
if ( F_148 () ||
F_26 ( V_357 , & V_12 -> V_14 ) )
goto V_358;
F_50 ( V_148 , & V_12 -> V_14 ) ;
F_149 ( V_12 -> V_15 , ( V_12 -> V_14 ) &&
! ( V_12 -> V_14 & V_303 ) ) ;
F_4 ( V_148 , & V_12 -> V_14 ) ;
if ( F_148 () ||
F_26 ( V_357 , & V_12 -> V_14 ) )
goto V_358;
if ( F_26 ( V_13 , & V_12 -> V_14 ) )
break;
if ( F_17 ( F_26 ( V_40 ,
& V_5 -> V_41 ) ) )
goto V_358;
V_359:
if ( F_26 ( V_93 , & V_12 -> V_14 ) ) {
F_45 ( V_5 ) ;
F_50 ( V_93 , & V_12 -> V_14 ) ;
}
if ( F_26 ( V_93 , & V_12 -> V_14 ) )
goto V_359;
if ( F_26 ( V_149 , & V_12 -> V_14 ) ) {
V_353 = 1 ;
V_354 = V_356 ;
V_355 = 0 ;
while ( 1 ) {
V_353 = F_150 ( V_12 -> V_304 ,
V_356 , V_353 ) ;
if ( V_355 == 1 ) {
if ( ( V_354 >= V_353 ) ||
( V_353 >= V_356 ) )
break;
}
if ( F_17 ( V_354 == V_356 ) )
V_354 = V_353 ;
if ( F_17 ( V_353 == V_356 ) ) {
V_353 = 1 ;
V_355 = 1 ;
continue;
}
F_28 ( V_12 , V_353 ) ;
F_50 ( V_353 , V_12 -> V_304 ) ;
}
F_50 ( V_149 , & V_12 -> V_14 ) ;
}
if ( F_26 ( V_313 , & V_12 -> V_14 ) ) {
if ( F_144 ( V_5 ) < 0 )
F_4 ( V_336 ,
& V_5 -> V_41 ) ;
F_50 ( V_313 , & V_12 -> V_14 ) ;
}
}
while ( 1 ) {
if ( F_26 ( V_360 , & V_5 -> V_41 ) )
break;
F_151 ( 1000 ) ;
if ( F_148 () )
goto V_358;
}
while ( 1 ) {
V_295 = F_131 ( V_5 ) ;
if ( ! V_295 ) {
return 0 ;
}
F_151 ( 1000 ) ;
if ( F_148 () )
goto V_358;
}
V_358:
return 0 ;
}
static void F_152 ( struct V_4 * V_5 )
{
struct V_26 * V_12 = V_5 -> V_12 ;
if ( V_12 -> V_361 )
F_88 ( & V_5 -> V_2 -> V_10 , V_362 ,
V_12 -> V_361 , V_12 -> V_363 ) ;
if ( V_12 -> V_364 ) {
F_88 ( & V_5 -> V_2 -> V_10 , V_365 ,
V_12 -> V_364 , V_12 -> V_55 ) ;
}
}
static int F_153 ( struct V_4 * V_5 )
{
struct V_26 * V_12 = V_5 -> V_12 ;
V_12 -> V_361 =
F_86 ( & V_5 -> V_2 -> V_10 , V_362 ,
& V_12 -> V_363 , V_161 ) ;
if ( ! V_12 -> V_361 )
return - V_221 ;
memset ( V_12 -> V_361 , 0 , V_362 ) ;
V_12 -> V_364 =
F_86 ( & V_5 -> V_2 -> V_10 , V_365 ,
& V_12 -> V_55 , V_161 ) ;
if ( ! V_12 -> V_364 ) {
F_88 ( & V_5 -> V_2 -> V_10 , V_362 ,
V_12 -> V_361 , V_12 -> V_363 ) ;
V_12 -> V_361 = NULL ;
V_12 -> V_363 = 0 ;
return - V_221 ;
}
memset ( V_12 -> V_364 , 0 , V_365 ) ;
V_12 -> V_135 = V_12 -> V_361 + V_366 ;
V_12 -> V_57 = V_12 -> V_363 + V_366 ;
V_12 -> V_178 = V_12 -> V_361 + V_367 ;
V_12 -> V_185 = V_12 -> V_363 + V_367 ;
V_12 -> V_101 = V_12 -> V_361 + V_368 ;
V_12 -> V_102 = V_12 -> V_363 + V_368 ;
V_12 -> V_209 = V_12 -> V_361 + V_369 ;
V_12 -> V_210 = V_12 -> V_363 + V_369 ;
return 0 ;
}
static int F_154 ( struct V_4 * V_5 )
{
struct V_204 V_370 ;
unsigned char * V_89 ;
int V_70 ;
if ( F_75 ( V_5 -> V_12 , NULL ) < 0 )
return - V_71 ;
if ( * ( V_5 -> V_12 -> V_178 + V_351 ) ==
V_352 ) {
F_4 ( V_313 , & V_5 -> V_12 -> V_14 ) ;
return V_352 ;
}
F_90 ( V_5 -> V_12 ) ;
V_70 = F_48 ( V_5 -> V_12 , V_100 ,
V_5 -> V_12 -> V_101 ,
V_5 -> V_12 -> V_102 , 1 ) ;
if ( V_70 ) {
F_5 ( & V_5 -> V_2 -> V_10 ,
L_16 ) ;
} else {
V_89 = ( unsigned char * ) V_5 -> V_12 -> V_101 ;
if ( V_89 [ 259 ] & 0x1 ) {
F_49 ( & V_5 -> V_2 -> V_10 ,
L_17 ) ;
F_4 ( V_103 , & V_5 -> V_41 ) ;
}
if ( V_89 [ 288 ] == 0xF7 ) {
F_49 ( & V_5 -> V_2 -> V_10 ,
L_19 ) ;
F_4 ( V_104 , & V_5 -> V_41 ) ;
}
if ( V_89 [ 288 ] == 0xBF ) {
F_49 ( & V_5 -> V_2 -> V_10 ,
L_111 ) ;
}
}
memset ( & V_370 , 0 , sizeof( struct V_204 ) ) ;
if ( F_83 ( V_5 -> V_12 , 242 , & V_370 ) )
F_5 ( & V_5 -> V_2 -> V_10 ,
L_112 ) ;
else
F_49 ( & V_5 -> V_2 -> V_10 ,
L_113 ,
V_370 . V_371 , F_155 ( V_370 . V_116 ) ) ;
return V_70 ;
}
static int F_156 ( struct V_4 * V_5 )
{
int V_52 ;
int V_70 ;
unsigned int V_372 ;
unsigned long V_35 , V_373 ;
V_5 -> V_37 = F_157 ( V_5 -> V_2 ) [ V_374 ] ;
F_143 ( V_5 ) ;
if ( V_5 -> V_345 == V_346 ) {
V_70 = - V_34 ;
goto V_375;
}
V_372 = V_5 -> V_62 * 32 ;
F_141 ( V_5 ) ;
V_5 -> V_12 = F_158 ( sizeof( struct V_26 ) , V_161 ,
V_5 -> V_376 ) ;
if ( ! V_5 -> V_12 ) {
F_39 ( & V_5 -> V_2 -> V_10 ,
L_114 ) ;
return - V_221 ;
}
for ( V_52 = 0 ; V_52 < V_125 ; V_52 ++ )
V_5 -> V_126 [ V_52 ] . V_12 = V_5 -> V_12 ;
if ( F_142 ( V_5 ) )
V_5 -> V_377 = V_378 ;
else
V_5 -> V_377 = 0 ;
F_159 ( & V_5 -> V_12 -> V_33 , V_5 -> V_377 ) ;
for ( V_52 = 0 ; V_52 < V_125 ; V_52 ++ )
F_160 ( & V_5 -> V_12 -> V_43 [ V_52 ] ) ;
V_5 -> V_12 -> V_37 = V_5 -> V_37 + V_379 ;
V_5 -> V_12 -> V_5 = V_5 ;
V_70 = F_153 ( V_5 ) ;
if ( V_70 < 0 )
goto V_375;
for ( V_52 = 0 ; V_52 < V_5 -> V_62 ; V_52 ++ ) {
V_5 -> V_12 -> V_44 [ V_52 ] =
V_5 -> V_12 -> V_37 + V_52 * 0x80 + V_380 ;
V_5 -> V_12 -> V_45 [ V_52 ] =
V_5 -> V_12 -> V_37 + V_52 * 0x80 + V_381 ;
V_5 -> V_12 -> V_63 [ V_52 ] =
V_5 -> V_12 -> V_37 + V_52 * 0x80 + V_382 ;
}
V_373 = V_39 ;
V_35 = V_39 + F_24 ( 30000 ) ;
while ( ( ( F_23 ( V_5 -> V_12 -> V_37 + V_69 ) & 0x0F ) != 0x03 ) &&
F_27 ( V_39 , V_35 ) ) {
F_25 ( 100 ) ;
}
if ( F_17 ( F_1 ( V_5 -> V_2 ) ) ) {
V_373 = V_39 - V_373 ;
F_5 ( & V_5 -> V_2 -> V_10 ,
L_115 ,
F_81 ( V_373 ) ) ;
V_70 = - V_383 ;
goto V_384 ;
}
if ( F_17 ( F_26 ( V_40 , & V_5 -> V_41 ) ) ) {
V_373 = V_39 - V_373 ;
F_5 ( & V_5 -> V_2 -> V_10 ,
L_116 ,
F_81 ( V_373 ) ) ;
V_70 = - V_71 ;
goto V_384;
}
if ( ! ( F_23 ( V_5 -> V_37 + V_53 ) & V_385 ) ) {
if ( F_21 ( V_5 ) < 0 ) {
F_39 ( & V_5 -> V_2 -> V_10 ,
L_117 ) ;
V_70 = - V_34 ;
goto V_384;
}
} else {
F_22 ( F_23 ( V_5 -> V_37 + V_65 ) ,
V_5 -> V_37 + V_65 ) ;
}
F_37 ( V_5 -> V_12 ) ;
F_35 ( V_5 -> V_12 ) ;
V_70 = F_161 ( & V_5 -> V_2 -> V_10 ,
V_5 -> V_2 -> V_131 ,
F_61 ,
V_386 ,
F_162 ( & V_5 -> V_2 -> V_10 ) ,
V_5 ) ;
if ( V_70 ) {
F_39 ( & V_5 -> V_2 -> V_10 ,
L_118 , V_5 -> V_2 -> V_131 ) ;
goto V_384;
}
F_163 ( V_5 -> V_2 -> V_131 , F_164 ( V_5 -> V_387 ) ) ;
F_22 ( F_23 ( V_5 -> V_37 + V_38 ) | V_72 ,
V_5 -> V_37 + V_38 ) ;
F_165 ( & V_5 -> V_12 -> V_15 ) ;
if ( F_26 ( V_40 , & V_5 -> V_41 ) ) {
V_70 = - V_71 ;
goto V_388;
}
return V_70 ;
V_388:
F_22 ( F_23 ( V_5 -> V_37 + V_38 ) & ~ V_72 ,
V_5 -> V_37 + V_38 ) ;
F_163 ( V_5 -> V_2 -> V_131 , NULL ) ;
F_166 ( & V_5 -> V_2 -> V_10 , V_5 -> V_2 -> V_131 , V_5 ) ;
V_384:
F_36 ( V_5 -> V_12 ) ;
F_152 ( V_5 ) ;
V_375:
F_103 ( V_5 -> V_12 ) ;
return V_70 ;
}
static void F_167 ( struct V_4 * V_5 )
{
if ( V_5 -> V_6 )
return;
if ( ! F_26 ( V_313 , & V_5 -> V_12 -> V_14 ) &&
! F_26 ( V_105 , & V_5 -> V_41 ) )
if ( F_80 ( V_5 -> V_12 ) )
F_5 ( & V_5 -> V_2 -> V_10 ,
L_119 ) ;
}
static int F_168 ( struct V_4 * V_5 )
{
if ( ! V_5 -> V_6 ) {
F_36 ( V_5 -> V_12 ) ;
F_22 ( F_23 ( V_5 -> V_37 + V_38 ) & ~ V_72 ,
V_5 -> V_37 + V_38 ) ;
}
F_163 ( V_5 -> V_2 -> V_131 , NULL ) ;
F_166 ( & V_5 -> V_2 -> V_10 , V_5 -> V_2 -> V_131 , V_5 ) ;
F_152 ( V_5 ) ;
F_103 ( V_5 -> V_12 ) ;
V_5 -> V_12 = NULL ;
return 0 ;
}
static int F_169 ( struct V_4 * V_5 )
{
if ( ! V_5 -> V_6 && V_5 -> V_12 )
F_80 ( V_5 -> V_12 ) ;
return 0 ;
}
static int F_170 ( struct V_4 * V_5 )
{
if ( F_80 ( V_5 -> V_12 ) != 0 ) {
F_39 ( & V_5 -> V_2 -> V_10 ,
L_120 ) ;
return - V_71 ;
}
F_22 ( F_23 ( V_5 -> V_37 + V_38 ) & ~ V_72 ,
V_5 -> V_37 + V_38 ) ;
F_36 ( V_5 -> V_12 ) ;
return 0 ;
}
static int F_171 ( struct V_4 * V_5 )
{
F_141 ( V_5 ) ;
if ( F_21 ( V_5 ) != 0 ) {
F_39 ( & V_5 -> V_2 -> V_10 ,
L_121 ) ;
return - V_71 ;
}
F_37 ( V_5 -> V_12 ) ;
F_35 ( V_5 -> V_12 ) ;
F_22 ( F_23 ( V_5 -> V_37 + V_38 ) | V_72 ,
V_5 -> V_37 + V_38 ) ;
return 0 ;
}
static int F_172 ( char * V_389 ,
int V_334 ,
char * V_89 ,
int V_390 )
{
const int V_391 = 'z' - 'a' + 1 ;
char * V_392 = V_89 + strlen ( V_389 ) ;
char * V_393 = V_89 + V_390 ;
char * V_394 ;
int V_395 ;
V_394 = V_393 - 1 ;
* V_394 = '\0' ;
V_395 = V_391 ;
do {
if ( V_394 == V_392 )
return - V_207 ;
* -- V_394 = 'a' + ( V_334 % V_395 ) ;
V_334 = ( V_334 / V_395 ) - 1 ;
} while ( V_334 >= 0 );
memmove ( V_392 , V_394 , V_393 - V_394 ) ;
memcpy ( V_89 , V_389 , strlen ( V_389 ) ) ;
return 0 ;
}
static int F_173 ( struct V_396 * V_10 ,
T_14 V_397 ,
unsigned V_20 ,
unsigned long V_289 )
{
struct V_4 * V_5 = V_10 -> V_398 -> V_307 ;
if ( ! F_174 ( V_399 ) )
return - V_400 ;
if ( ! V_5 )
return - V_401 ;
if ( F_17 ( F_26 ( V_40 , & V_5 -> V_41 ) ) )
return - V_401 ;
switch ( V_20 ) {
case V_402 :
return - V_401 ;
default:
return F_104 ( V_5 , V_20 , V_289 ) ;
}
}
static int F_175 ( struct V_396 * V_10 ,
T_14 V_397 ,
unsigned V_20 ,
unsigned long V_289 )
{
struct V_4 * V_5 = V_10 -> V_398 -> V_307 ;
if ( ! F_174 ( V_399 ) )
return - V_400 ;
if ( ! V_5 )
return - V_401 ;
if ( F_17 ( F_26 ( V_40 , & V_5 -> V_41 ) ) )
return - V_401 ;
switch ( V_20 ) {
case V_402 :
return - V_401 ;
case V_294 : {
struct V_403 T_7 * V_404 ;
T_10 V_254 ;
int V_405 , V_255 , V_295 ;
V_405 =
sizeof( struct V_403 ) ;
V_404 =
(struct V_403 T_7 * ) V_289 ;
if ( F_100 ( & V_254 , ( void T_7 * ) V_289 ,
V_405 - ( 2 * sizeof( V_406 ) ) ) )
return - V_71 ;
if ( F_176 ( V_254 . V_268 , & V_404 -> V_268 ) )
return - V_71 ;
if ( F_176 ( V_254 . V_269 , & V_404 -> V_269 ) )
return - V_71 ;
V_255 = sizeof( struct V_403 ) ;
V_295 = F_98 ( V_5 , ( void T_7 * ) V_289 ,
& V_254 , V_255 ) ;
if ( F_79 ( ( void T_7 * ) V_289 , & V_254 ,
V_405 -
( 2 * sizeof( V_406 ) ) ) )
return - V_71 ;
if ( F_177 ( V_254 . V_268 , & V_404 -> V_268 ) )
return - V_71 ;
if ( F_177 ( V_254 . V_269 , & V_404 -> V_269 ) )
return - V_71 ;
return V_295 ;
}
default:
return F_104 ( V_5 , V_20 , V_289 ) ;
}
}
static int F_178 ( struct V_396 * V_10 ,
struct V_407 * V_408 )
{
struct V_4 * V_5 = V_10 -> V_398 -> V_307 ;
T_9 V_409 ;
if ( ! V_5 )
return - V_401 ;
if ( ! ( F_89 ( V_5 , & V_409 ) ) ) {
F_5 ( & V_5 -> V_2 -> V_10 ,
L_122 ) ;
return - V_401 ;
}
V_408 -> V_410 = 224 ;
V_408 -> V_193 = 56 ;
F_179 ( V_409 , ( V_408 -> V_410 * V_408 -> V_193 ) ) ;
V_408 -> V_411 = V_409 ;
return 0 ;
}
static int F_180 ( struct V_22 * V_23 , struct V_17 * V_18 )
{
struct V_4 * V_5 = V_23 -> V_7 -> V_337 ;
struct V_16 * V_20 = F_9 ( V_18 ) ;
unsigned int V_232 ;
if ( F_17 ( V_5 -> V_41 & V_412 ) ) {
if ( F_17 ( F_26 ( V_40 ,
& V_5 -> V_41 ) ) ) {
return - V_174 ;
}
if ( F_17 ( F_26 ( V_104 , & V_5 -> V_41 ) ) ) {
return - V_108 ;
}
if ( F_17 ( F_26 ( V_103 ,
& V_5 -> V_41 ) &&
F_106 ( V_18 ) ) ) {
return - V_108 ;
}
if ( F_17 ( F_26 ( V_105 , & V_5 -> V_41 ) ) )
return - V_108 ;
if ( F_26 ( V_336 , & V_5 -> V_41 ) )
return - V_174 ;
}
if ( V_18 -> V_413 & V_414 ) {
int V_261 ;
V_261 = F_84 ( V_5 , F_107 ( V_18 ) , F_108 ( V_18 ) ) ;
F_20 ( V_18 , V_261 ) ;
return 0 ;
}
V_232 = F_181 ( V_23 -> V_7 , V_18 , V_20 -> V_29 ) ;
F_105 ( V_5 , V_18 , V_20 , V_232 , V_23 ) ;
return 0 ;
}
static bool F_182 ( struct V_22 * V_23 ,
struct V_17 * V_18 )
{
struct V_4 * V_5 = V_23 -> V_7 -> V_337 ;
struct V_16 * V_20 = F_9 ( V_18 ) ;
if ( F_106 ( V_18 ) == V_297 || ! V_5 -> V_377 )
return false ;
if ( F_108 ( V_18 ) <= 64 ) {
if ( ( F_107 ( V_18 ) & 7 ) || ( F_108 ( V_18 ) & 7 ) )
V_20 -> V_32 = 1 ;
}
if ( V_20 -> V_32 && F_183 ( & V_5 -> V_12 -> V_33 ) )
return true ;
return false ;
}
static int F_184 ( struct V_22 * V_23 , struct V_17 * V_18 ,
bool V_415 )
{
int V_295 ;
if ( F_17 ( F_182 ( V_23 , V_18 ) ) )
return V_416 ;
F_185 ( V_18 ) ;
V_295 = F_180 ( V_23 , V_18 ) ;
if ( F_47 ( ! V_295 ) )
return V_417 ;
V_18 -> V_418 = V_295 ;
return V_419 ;
}
static void F_186 ( void * V_116 , struct V_17 * V_18 ,
unsigned int V_420 , unsigned int V_421 )
{
struct V_4 * V_5 = V_116 ;
struct V_16 * V_20 = F_9 ( V_18 ) ;
if ( ! V_20 -> V_79 )
return;
F_88 ( & V_5 -> V_2 -> V_10 , V_422 ,
V_20 -> V_79 , V_20 -> V_423 ) ;
}
static int F_187 ( void * V_116 , struct V_17 * V_18 , unsigned int V_420 ,
unsigned int V_421 , unsigned int V_376 )
{
struct V_4 * V_5 = V_116 ;
struct V_16 * V_20 = F_9 ( V_18 ) ;
T_2 V_424 = F_23 ( V_5 -> V_37 + V_53 ) & V_54 ;
V_20 -> V_79 = F_86 ( & V_5 -> V_2 -> V_10 , V_422 ,
& V_20 -> V_423 , V_161 ) ;
if ( ! V_20 -> V_79 )
return - V_221 ;
memset ( V_20 -> V_79 , 0 , V_422 ) ;
V_20 -> V_164 = V_5 -> V_12 -> V_364 +
( sizeof( struct V_425 ) * V_421 ) ;
V_20 -> V_426 = V_5 -> V_12 -> V_55 +
( sizeof( struct V_425 ) * V_421 ) ;
if ( V_424 )
V_20 -> V_164 -> V_427 = V_165 F_70 ( ( V_20 -> V_423 >> 16 ) >> 16 ) ;
V_20 -> V_164 -> V_428 = V_165 F_70 ( V_20 -> V_423 & 0xFFFFFFFF ) ;
F_188 ( V_20 -> V_29 , V_429 ) ;
return 0 ;
}
static int F_146 ( struct V_4 * V_5 )
{
int V_70 = 0 , V_430 = 0 ;
T_9 V_409 ;
unsigned int V_334 = 0 ;
struct V_320 * V_321 ;
unsigned char V_431 [ 16 ] ;
if ( V_5 -> V_325 )
goto V_432;
if ( F_156 ( V_5 ) ) {
V_70 = - V_207 ;
goto V_433;
}
V_5 -> V_325 = F_189 ( V_434 , V_5 -> V_376 ) ;
if ( V_5 -> V_325 == NULL ) {
F_39 ( & V_5 -> V_2 -> V_10 ,
L_123 ) ;
V_70 = - V_207 ;
goto V_435;
}
do {
if ( ! F_190 ( & V_333 , V_161 ) )
goto V_436;
F_29 ( & V_332 ) ;
V_70 = F_191 ( & V_333 , & V_334 ) ;
F_32 ( & V_332 ) ;
} while ( V_70 == - V_175 );
if ( V_70 )
goto V_436;
V_70 = F_172 ( L_124 ,
V_334 ,
V_5 -> V_325 -> V_326 ,
V_437 ) ;
if ( V_70 )
goto V_438;
V_5 -> V_325 -> V_439 = & V_5 -> V_2 -> V_10 ;
V_5 -> V_325 -> V_440 = V_5 -> V_440 ;
V_5 -> V_325 -> V_441 = V_5 -> V_132 * V_434 ;
V_5 -> V_325 -> V_442 = & V_443 ;
V_5 -> V_325 -> V_307 = V_5 ;
V_5 -> V_334 = V_334 ;
F_125 ( V_5 ) ;
V_432:
memset ( & V_5 -> V_25 , 0 , sizeof( V_5 -> V_25 ) ) ;
V_5 -> V_25 . V_444 = & V_445 ;
V_5 -> V_25 . V_446 = 1 ;
V_5 -> V_25 . V_447 = V_448 ;
V_5 -> V_25 . V_449 = 1 ;
V_5 -> V_25 . V_450 = sizeof( struct V_16 ) ;
V_5 -> V_25 . V_376 = V_5 -> V_376 ;
V_5 -> V_25 . V_14 = V_451 ;
V_5 -> V_25 . V_4 = V_5 ;
V_70 = F_192 ( & V_5 -> V_25 ) ;
if ( V_70 ) {
F_39 ( & V_5 -> V_2 -> V_10 ,
L_125 ) ;
goto V_452;
}
V_5 -> V_7 = F_193 ( & V_5 -> V_25 ) ;
if ( F_194 ( V_5 -> V_7 ) ) {
F_39 ( & V_5 -> V_2 -> V_10 ,
L_125 ) ;
V_70 = - V_221 ;
goto V_452;
}
V_5 -> V_325 -> V_7 = V_5 -> V_7 ;
V_5 -> V_7 -> V_337 = V_5 ;
V_430 = F_154 ( V_5 ) ;
if ( V_430 < 0 ) {
F_39 ( & V_5 -> V_2 -> V_10 ,
L_126 ) ;
V_70 = - V_207 ;
goto V_453;
}
if ( V_430 == V_352 )
goto V_454;
F_4 ( V_455 , & V_5 -> V_7 -> V_9 ) ;
F_50 ( V_456 , & V_5 -> V_7 -> V_9 ) ;
F_195 ( V_5 -> V_7 , V_429 ) ;
F_196 ( V_5 -> V_7 , 4096 ) ;
F_197 ( V_5 -> V_7 , 0xffff ) ;
F_198 ( V_5 -> V_7 , 0x400000 ) ;
F_199 ( V_5 -> V_7 , 4096 ) ;
F_200 ( V_5 -> V_7 , V_5 -> V_2 -> V_457 ) ;
F_201 ( V_5 -> V_7 , 0 ) ;
if ( V_5 -> V_188 == true ) {
F_4 ( V_458 , & V_5 -> V_7 -> V_9 ) ;
V_5 -> V_7 -> V_459 . V_460 = 4096 ;
F_202 ( V_5 -> V_7 ,
V_218 * V_219 ) ;
V_5 -> V_7 -> V_459 . V_461 = 0 ;
}
if ( ! ( F_89 ( V_5 , & V_409 ) ) ) {
F_5 ( & V_5 -> V_2 -> V_10 ,
L_127 ) ;
V_70 = - V_34 ;
goto V_462;
}
F_203 ( V_5 -> V_325 , V_409 ) ;
F_204 ( V_5 -> V_325 ) ;
V_5 -> V_330 = F_205 ( V_5 -> V_325 , 0 ) ;
V_321 = F_135 ( & F_136 ( V_5 -> V_325 ) -> V_321 ) ;
if ( V_321 ) {
F_121 ( V_5 , V_321 ) ;
F_137 ( V_321 ) ;
}
if ( V_5 -> V_463 ) {
F_4 ( V_335 , & V_5 -> V_41 ) ;
return V_70 ;
}
V_454:
sprintf ( V_431 , L_128 , V_334 ) ;
V_5 -> V_463 = F_206 ( F_147 ,
V_5 , V_5 -> V_376 , L_75 ,
V_431 ) ;
if ( F_194 ( V_5 -> V_463 ) ) {
F_39 ( & V_5 -> V_2 -> V_10 , L_129 ) ;
V_5 -> V_463 = NULL ;
V_70 = - V_71 ;
goto V_464;
}
F_207 ( V_5 -> V_463 ) ;
if ( V_430 == V_352 )
V_70 = V_430 ;
return V_70 ;
V_464:
F_132 ( V_5 -> V_330 ) ;
V_5 -> V_330 = NULL ;
F_138 ( V_5 -> V_325 ) ;
V_462:
V_453:
F_139 ( V_5 -> V_7 ) ;
F_140 ( & V_5 -> V_25 ) ;
V_452:
F_129 ( V_5 ) ;
V_438:
F_29 ( & V_332 ) ;
F_133 ( & V_333 , V_334 ) ;
F_32 ( & V_332 ) ;
V_436:
F_134 ( V_5 -> V_325 ) ;
V_435:
F_168 ( V_5 ) ;
V_433:
return V_70 ;
}
static int F_208 ( struct V_4 * V_5 )
{
struct V_320 * V_321 ;
if ( ! V_5 -> V_6 ) {
F_129 ( V_5 ) ;
if ( V_5 -> V_463 ) {
F_4 ( V_357 , & V_5 -> V_12 -> V_14 ) ;
F_6 ( & V_5 -> V_12 -> V_15 ) ;
F_209 ( V_5 -> V_463 ) ;
}
if ( F_26 ( V_335 , & V_5 -> V_41 ) ) {
V_321 = F_135 ( & F_136 ( V_5 -> V_325 ) -> V_321 ) ;
if ( V_321 ) {
F_123 ( V_5 , V_321 ) ;
F_137 ( V_321 ) ;
}
}
F_167 ( V_5 ) ;
if ( V_5 -> V_330 ) {
F_132 ( V_5 -> V_330 ) ;
V_5 -> V_330 = NULL ;
}
if ( V_5 -> V_325 ) {
if ( V_5 -> V_325 -> V_7 ) {
F_138 ( V_5 -> V_325 ) ;
F_139 ( V_5 -> V_7 ) ;
F_140 ( & V_5 -> V_25 ) ;
V_5 -> V_7 = NULL ;
} else
F_134 ( V_5 -> V_325 ) ;
}
V_5 -> V_325 = NULL ;
F_29 ( & V_332 ) ;
F_133 ( & V_333 , V_5 -> V_334 ) ;
F_32 ( & V_332 ) ;
} else {
F_49 ( & V_5 -> V_2 -> V_10 , L_130 ,
V_5 -> V_325 -> V_326 ) ;
}
F_168 ( V_5 ) ;
return 0 ;
}
static int F_210 ( struct V_4 * V_5 )
{
F_169 ( V_5 ) ;
if ( V_5 -> V_325 ) {
F_49 ( & V_5 -> V_2 -> V_10 ,
L_131 , V_5 -> V_325 -> V_326 ) ;
if ( V_5 -> V_325 -> V_7 ) {
F_138 ( V_5 -> V_325 ) ;
F_139 ( V_5 -> V_7 ) ;
F_140 ( & V_5 -> V_25 ) ;
} else
F_134 ( V_5 -> V_325 ) ;
V_5 -> V_325 = NULL ;
V_5 -> V_7 = NULL ;
}
F_29 ( & V_332 ) ;
F_133 ( & V_333 , V_5 -> V_334 ) ;
F_32 ( & V_332 ) ;
return 0 ;
}
static int F_211 ( struct V_4 * V_5 )
{
F_49 ( & V_5 -> V_2 -> V_10 ,
L_132 , V_5 -> V_325 -> V_326 ) ;
F_170 ( V_5 ) ;
return 0 ;
}
static int F_212 ( struct V_4 * V_5 )
{
F_49 ( & V_5 -> V_2 -> V_10 , L_133 ,
V_5 -> V_325 -> V_326 ) ;
F_171 ( V_5 ) ;
return 0 ;
}
static void F_213 ( int V_465 )
{
V_466 [ V_465 ] -- ;
}
static int F_214 ( int V_467 )
{
int V_465 , V_468 , V_469 ;
const struct V_470 * V_471 ;
V_471 = F_215 ( V_467 ) ;
V_468 = F_216 ( V_471 ) ;
V_469 = V_466 [ V_468 ] ;
V_465 = V_468 ;
F_217 (cpu, node_mask) {
if ( V_466 [ V_465 ] < V_469 ) {
V_468 = V_465 ;
V_469 = V_466 [ V_465 ] ;
}
}
V_466 [ V_468 ] ++ ;
return V_468 ;
}
static inline int F_218 ( void )
{
static int V_472 = - 1 ;
if ( V_472 == - 1 ) {
V_472 = V_473 ;
return V_472 ;
}
V_472 = F_219 ( V_472 ) ;
if ( V_472 == V_474 )
V_472 = V_473 ;
return V_472 ;
}
static void F_220 ( struct V_4 * V_5 , struct V_1 * V_2 )
{
int V_475 ;
unsigned short V_476 ;
V_475 = F_221 ( V_2 , V_477 ) ;
if ( V_475 ) {
F_3 ( V_2 ,
V_475 + V_478 ,
& V_476 ) ;
if ( V_476 & ( 1 << 11 ) ||
V_476 & ( 1 << 4 ) ) {
F_49 ( & V_5 -> V_2 -> V_10 ,
L_134 ,
V_2 -> V_479 , V_2 -> V_199 ) ;
V_476 &= ~ ( V_480 |
V_481 ) ;
F_222 ( V_2 ,
V_475 + V_478 ,
V_476 ) ;
}
}
}
static void F_223 ( struct V_4 * V_5 , struct V_1 * V_2 )
{
if ( V_2 -> V_482 && V_2 -> V_482 -> V_483 ) {
if ( V_2 -> V_482 -> V_483 -> V_479 == V_484 &&
( ( V_2 -> V_482 -> V_483 -> V_199 & 0xff00 ) == 0x5a00 ) ) {
F_220 ( V_5 , V_2 -> V_482 -> V_483 ) ;
} else {
struct V_1 * V_485 = V_2 -> V_482 -> V_483 ;
if ( V_485 -> V_482 &&
V_485 -> V_482 -> V_486 &&
V_485 -> V_482 -> V_486 -> V_483 &&
V_485 -> V_482 -> V_486 -> V_483 -> V_479 ==
V_484 &&
( V_485 -> V_482 -> V_486 -> V_483 -> V_199 &
0xff00 ) == 0x5a00 ) {
F_220 ( V_5 ,
V_485 -> V_482 -> V_486 -> V_483 ) ;
}
}
}
}
static int F_224 ( struct V_1 * V_2 ,
const struct V_487 * V_488 )
{
int V_70 = 0 ;
struct V_4 * V_5 = NULL ;
char V_489 [ 256 ] ;
const struct V_470 * V_471 ;
int V_465 , V_52 = 0 , V_490 = 0 ;
int V_491 = V_492 ;
unsigned long V_14 ;
V_491 = F_225 ( V_2 -> V_482 ) ;
if ( V_491 != V_492 ) {
if ( ! F_226 ( V_491 ) )
V_491 = F_218 () ;
} else {
F_49 ( & V_2 -> V_10 , L_135 ) ;
V_491 = F_218 () ;
}
F_49 ( & V_2 -> V_10 , L_136 ,
V_491 , F_225 ( V_2 -> V_482 ) , F_227 ( & V_2 -> V_10 ) ,
F_228 ( F_229 () ) , F_229 () ) ;
V_5 = F_158 ( sizeof( struct V_4 ) , V_161 , V_491 ) ;
if ( V_5 == NULL ) {
F_39 ( & V_2 -> V_10 ,
L_137 ) ;
return - V_221 ;
}
F_230 ( V_2 , V_5 ) ;
V_70 = F_231 ( V_2 ) ;
if ( V_70 < 0 ) {
F_39 ( & V_2 -> V_10 , L_138 ) ;
goto V_493;
}
V_70 = F_232 ( V_2 , 1 << V_374 , V_97 ) ;
if ( V_70 < 0 ) {
F_39 ( & V_2 -> V_10 , L_139 ) ;
goto V_493;
}
if ( ! F_233 ( V_2 , F_234 ( 64 ) ) ) {
V_70 = F_235 ( V_2 , F_234 ( 64 ) ) ;
if ( V_70 ) {
V_70 = F_235 ( V_2 ,
F_234 ( 32 ) ) ;
if ( V_70 ) {
F_5 ( & V_2 -> V_10 ,
L_140 ) ;
goto V_494;
}
}
}
V_5 -> V_440 = V_495 ;
V_5 -> V_132 = V_132 ;
V_5 -> V_2 = V_2 ;
V_5 -> V_376 = V_491 ;
F_236 ( & V_5 -> V_496 ) ;
F_236 ( & V_5 -> V_497 ) ;
memset ( V_5 -> V_498 , 0 , 32 ) ;
snprintf ( V_5 -> V_498 , 31 , L_141 , V_5 -> V_132 ) ;
V_5 -> V_128 = F_237 ( V_5 -> V_498 ) ;
if ( ! V_5 -> V_128 ) {
F_5 ( & V_2 -> V_10 , L_142 , V_5 -> V_132 ) ;
V_70 = - V_221 ;
goto V_499;
}
memset ( V_489 , 0 , sizeof( V_489 ) ) ;
V_471 = F_215 ( V_5 -> V_376 ) ;
if ( ! F_238 ( V_471 ) ) {
F_217 (cpu, node_mask)
{
snprintf ( & V_489 [ V_490 ] , 256 - V_490 , L_143 , V_465 ) ;
V_490 = strlen ( V_489 ) ;
}
F_49 ( & V_2 -> V_10 , L_144 ,
V_5 -> V_376 ,
F_239 ( F_216 ( V_471 ) ) ,
F_240 ( V_5 -> V_376 ) ,
V_489 ) ;
} else
F_53 ( & V_2 -> V_10 , L_145 ) ;
V_5 -> V_387 = F_214 ( V_5 -> V_376 ) ;
F_49 ( & V_2 -> V_10 , L_146 ,
F_228 ( V_5 -> V_387 ) , V_5 -> V_387 ) ;
V_5 -> V_126 [ 0 ] . V_127 = V_5 -> V_387 ;
V_5 -> V_126 [ 1 ] . V_127 = F_214 ( V_5 -> V_376 ) ;
V_5 -> V_126 [ 2 ] . V_127 = F_214 ( V_5 -> V_376 ) ;
V_5 -> V_126 [ 3 ] . V_127 = V_5 -> V_126 [ 0 ] . V_127 ;
V_5 -> V_126 [ 4 ] . V_127 = V_5 -> V_126 [ 1 ] . V_127 ;
V_5 -> V_126 [ 5 ] . V_127 = V_5 -> V_126 [ 2 ] . V_127 ;
V_5 -> V_126 [ 6 ] . V_127 = V_5 -> V_126 [ 2 ] . V_127 ;
V_5 -> V_126 [ 7 ] . V_127 = V_5 -> V_126 [ 1 ] . V_127 ;
F_241 (cpu) {
memset ( V_489 , 0 , sizeof( V_489 ) ) ;
for ( V_52 = 0 , V_490 = 0 ; V_52 < V_125 ; V_52 ++ ) {
if ( V_5 -> V_126 [ V_52 ] . V_127 == V_465 ) {
snprintf ( & V_489 [ V_490 ] , 256 - V_490 , L_143 , V_52 ) ;
V_490 = strlen ( V_489 ) ;
}
}
if ( V_490 )
F_49 ( & V_2 -> V_10 , L_147 , V_465 , V_489 ) ;
}
F_242 ( & V_5 -> V_126 [ 0 ] . V_126 , V_500 ) ;
F_242 ( & V_5 -> V_126 [ 1 ] . V_126 , V_501 ) ;
F_242 ( & V_5 -> V_126 [ 2 ] . V_126 , V_502 ) ;
F_242 ( & V_5 -> V_126 [ 3 ] . V_126 , V_503 ) ;
F_242 ( & V_5 -> V_126 [ 4 ] . V_126 , V_504 ) ;
F_242 ( & V_5 -> V_126 [ 5 ] . V_126 , V_505 ) ;
F_242 ( & V_5 -> V_126 [ 6 ] . V_126 , V_506 ) ;
F_242 ( & V_5 -> V_126 [ 7 ] . V_126 , V_507 ) ;
F_243 ( V_2 ) ;
V_70 = F_244 ( V_2 ) ;
if ( V_70 ) {
F_5 ( & V_2 -> V_10 ,
L_148 ) ;
goto V_508;
}
F_223 ( V_5 , V_2 ) ;
V_70 = F_146 ( V_5 ) ;
if ( V_70 < 0 ) {
F_39 ( & V_2 -> V_10 ,
L_149 ) ;
goto V_499;
}
V_132 ++ ;
if ( V_70 != V_352 )
F_4 ( V_335 , & V_5 -> V_41 ) ;
else
V_70 = 0 ;
F_114 ( & V_312 , V_14 ) ;
F_245 ( & V_5 -> V_496 , & V_496 ) ;
F_117 ( & V_312 , V_14 ) ;
goto V_509;
V_499:
F_246 ( V_2 ) ;
V_508:
if ( V_5 -> V_128 ) {
F_247 ( V_5 -> V_128 ) ;
F_248 ( V_5 -> V_128 ) ;
F_213 ( V_5 -> V_126 [ 0 ] . V_127 ) ;
F_213 ( V_5 -> V_126 [ 1 ] . V_127 ) ;
F_213 ( V_5 -> V_126 [ 2 ] . V_127 ) ;
}
V_494:
F_249 ( V_2 , 1 << V_374 ) ;
V_493:
F_103 ( V_5 ) ;
F_230 ( V_2 , NULL ) ;
return V_70 ;
V_509:
return V_70 ;
}
static void F_250 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
unsigned long V_14 , V_145 ;
F_4 ( V_40 , & V_5 -> V_41 ) ;
F_114 ( & V_312 , V_14 ) ;
F_251 ( & V_5 -> V_496 ) ;
F_245 ( & V_5 -> V_497 , & V_510 ) ;
F_117 ( & V_312 , V_14 ) ;
F_1 ( V_2 ) ;
F_252 ( V_5 -> V_2 -> V_131 ) ;
V_145 = V_39 + F_24 ( 4000 ) ;
do {
F_66 ( 20 ) ;
} while ( F_58 ( & V_5 -> V_110 ) != 0 &&
F_27 ( V_39 , V_145 ) );
if ( F_58 ( & V_5 -> V_110 ) != 0 ) {
F_5 ( & V_5 -> V_2 -> V_10 ,
L_150 ) ;
}
F_208 ( V_5 ) ;
if ( V_5 -> V_128 ) {
F_247 ( V_5 -> V_128 ) ;
F_248 ( V_5 -> V_128 ) ;
F_213 ( V_5 -> V_126 [ 0 ] . V_127 ) ;
F_213 ( V_5 -> V_126 [ 1 ] . V_127 ) ;
F_213 ( V_5 -> V_126 [ 2 ] . V_127 ) ;
}
F_246 ( V_2 ) ;
F_114 ( & V_312 , V_14 ) ;
F_251 ( & V_5 -> V_497 ) ;
F_117 ( & V_312 , V_14 ) ;
if ( ! V_5 -> V_6 )
F_103 ( V_5 ) ;
else
F_4 ( V_360 , & V_5 -> V_41 ) ;
F_249 ( V_2 , 1 << V_374 ) ;
F_230 ( V_2 , NULL ) ;
}
static int F_253 ( struct V_1 * V_2 , T_15 V_511 )
{
int V_70 = 0 ;
struct V_4 * V_5 = F_2 ( V_2 ) ;
if ( ! V_5 ) {
F_39 ( & V_2 -> V_10 ,
L_151 ) ;
return - V_71 ;
}
F_4 ( V_512 , & V_5 -> V_41 ) ;
V_70 = F_211 ( V_5 ) ;
if ( V_70 < 0 ) {
F_39 ( & V_2 -> V_10 ,
L_152 ) ;
return V_70 ;
}
F_254 ( V_2 ) ;
F_255 ( V_2 ) ;
F_256 ( V_2 , V_513 ) ;
return V_70 ;
}
static int F_257 ( struct V_1 * V_2 )
{
int V_70 = 0 ;
struct V_4 * V_5 ;
V_5 = F_2 ( V_2 ) ;
if ( ! V_5 ) {
F_39 ( & V_2 -> V_10 ,
L_151 ) ;
return - V_71 ;
}
F_256 ( V_2 , V_514 ) ;
F_258 ( V_2 ) ;
V_70 = F_231 ( V_2 ) ;
if ( V_70 < 0 ) {
F_39 ( & V_2 -> V_10 ,
L_153 ) ;
goto V_261;
}
F_243 ( V_2 ) ;
V_70 = F_212 ( V_5 ) ;
if ( V_70 < 0 )
F_39 ( & V_2 -> V_10 , L_154 ) ;
V_261:
F_50 ( V_512 , & V_5 -> V_41 ) ;
return V_70 ;
}
static void F_259 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
if ( V_5 )
F_210 ( V_5 ) ;
}
static int T_16 F_260 ( void )
{
int error ;
F_261 ( V_97 L_155 V_515 L_92 ) ;
F_160 ( & V_312 ) ;
F_236 ( & V_496 ) ;
F_236 ( & V_510 ) ;
error = F_262 ( 0 , V_97 ) ;
if ( error <= 0 ) {
F_263 ( L_156 ,
error ) ;
return - V_151 ;
}
V_495 = error ;
V_323 = F_126 ( L_124 , NULL ) ;
if ( F_127 ( V_323 ) ) {
F_264 ( L_157 ) ;
V_323 = NULL ;
}
if ( V_323 ) {
V_516 = F_128 ( L_158 ,
V_327 , V_323 , NULL ,
& V_517 ) ;
if ( F_127 ( V_516 ) ) {
F_263 ( L_159 ) ;
V_516 = NULL ;
}
}
error = F_265 ( & V_518 ) ;
if ( error ) {
F_266 ( V_323 ) ;
F_267 ( V_495 , V_97 ) ;
}
return error ;
}
static void T_17 F_268 ( void )
{
F_267 ( V_495 , V_97 ) ;
F_269 ( & V_518 ) ;
F_130 ( V_323 ) ;
}
