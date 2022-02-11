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
static struct V_12 * F_6 ( struct V_4 * V_5 )
{
struct V_13 * V_14 ;
V_14 = F_7 ( V_5 -> V_7 , 0 , V_15 , true ) ;
return F_8 ( V_14 ) ;
}
static void F_9 ( struct V_4 * V_5 , struct V_12 * V_16 )
{
F_10 ( F_11 ( V_16 ) ) ;
}
static struct V_13 * F_12 ( struct V_4 * V_5 ,
unsigned int V_17 )
{
struct V_18 * V_19 = V_5 -> V_7 -> V_20 [ 0 ] ;
return F_13 ( V_19 -> V_21 , V_17 ) ;
}
static struct V_12 * F_14 ( struct V_4 * V_5 ,
unsigned int V_17 )
{
struct V_13 * V_14 = F_12 ( V_5 , V_17 ) ;
return F_8 ( V_14 ) ;
}
static void F_15 ( struct V_22 * V_23 ,
int V_17 , struct V_12 * V_16 , int V_24 )
{
struct V_4 * V_5 = V_23 -> V_5 ;
struct V_13 * V_14 ;
if ( F_16 ( ! V_5 ) || F_16 ( ! V_23 ) )
return;
if ( F_16 ( V_24 == V_25 ) ) {
F_5 ( & V_23 -> V_5 -> V_2 -> V_10 ,
L_2 , V_17 ) ;
}
F_17 ( & V_5 -> V_2 -> V_10 , V_16 -> V_26 , V_16 -> V_27 , V_16 -> V_28 ) ;
V_14 = F_12 ( V_5 , V_17 ) ;
if ( F_16 ( V_16 -> V_29 ) )
F_18 ( & V_23 -> V_30 ) ;
F_19 ( V_14 , V_24 ? - V_31 : 0 ) ;
}
static int F_20 ( struct V_4 * V_5 )
{
unsigned long V_32 ;
F_21 ( V_33 , V_5 -> V_34 + V_35 ) ;
F_22 ( V_5 -> V_34 + V_35 ) ;
V_32 = V_36 + F_23 ( 10000 ) ;
do {
F_24 ( 10 ) ;
if ( F_25 ( V_37 , & V_5 -> V_38 ) )
return - 1 ;
} while ( ( F_22 ( V_5 -> V_34 + V_35 ) & V_33 )
&& F_26 ( V_36 , V_32 ) );
if ( F_22 ( V_5 -> V_34 + V_35 ) & V_33 )
return - 1 ;
return 0 ;
}
static inline void F_27 ( struct V_22 * V_23 , int V_17 )
{
int V_39 = V_17 >> 5 ;
F_28 ( & V_23 -> V_40 [ V_39 ] ) ;
F_21 ( ( 1 << F_29 ( V_17 ) ) ,
V_23 -> V_41 [ F_30 ( V_17 ) ] ) ;
F_21 ( ( 1 << F_29 ( V_17 ) ) ,
V_23 -> V_42 [ F_30 ( V_17 ) ] ) ;
F_31 ( & V_23 -> V_40 [ V_39 ] ) ;
}
static int F_32 ( struct V_22 * V_23 , int V_43 )
{
T_2 V_44 ;
V_44 = F_22 ( V_23 -> V_34 + V_45 ) ;
if ( V_43 )
F_21 ( V_44 | V_46 , V_23 -> V_34 + V_45 ) ;
else
F_21 ( V_44 & ~ V_46 , V_23 -> V_34 + V_45 ) ;
F_22 ( V_23 -> V_34 + V_45 ) ;
return ( ( ( V_44 & V_46 ) == V_46 ) ) ;
}
static int F_33 ( struct V_22 * V_23 , int V_43 )
{
T_2 V_44 ;
V_44 = F_22 ( V_23 -> V_34 + V_45 ) ;
if ( V_43 )
F_21 ( V_44 | V_47 , V_23 -> V_34 + V_45 ) ;
else
F_21 ( V_44 & ~ V_47 , V_23 -> V_34 + V_45 ) ;
F_22 ( V_23 -> V_34 + V_45 ) ;
return ( ( ( V_44 & V_47 ) == V_47 ) ) ;
}
static inline void F_34 ( struct V_22 * V_23 )
{
F_32 ( V_23 , 1 ) ;
F_33 ( V_23 , 1 ) ;
}
static inline void F_35 ( struct V_22 * V_23 )
{
F_21 ( 0 , V_23 -> V_34 + V_48 ) ;
F_33 ( V_23 , 0 ) ;
F_32 ( V_23 , 0 ) ;
}
static void F_36 ( struct V_22 * V_23 )
{
int V_49 ;
F_35 ( V_23 ) ;
if ( F_22 ( V_23 -> V_5 -> V_34 + V_50 ) & V_51 ) {
F_21 ( ( V_23 -> V_52 >> 16 ) >> 16 ,
V_23 -> V_34 + V_53 ) ;
F_21 ( ( V_23 -> V_54 >> 16 ) >> 16 ,
V_23 -> V_34 + V_55 ) ;
}
F_21 ( V_23 -> V_52 & 0xFFFFFFFF ,
V_23 -> V_34 + V_56 ) ;
F_21 ( V_23 -> V_54 & 0xFFFFFFFF , V_23 -> V_34 + V_57 ) ;
F_21 ( F_22 ( V_23 -> V_34 + V_58 ) , V_23 -> V_34 + V_58 ) ;
for ( V_49 = 0 ; V_49 < V_23 -> V_5 -> V_59 ; V_49 ++ )
F_21 ( 0xFFFFFFFF , V_23 -> V_60 [ V_49 ] ) ;
F_21 ( F_22 ( V_23 -> V_34 + V_61 ) , V_23 -> V_34 + V_61 ) ;
F_21 ( F_22 ( V_23 -> V_5 -> V_34 + V_62 ) ,
V_23 -> V_5 -> V_34 + V_62 ) ;
F_21 ( V_63 , V_23 -> V_34 + V_48 ) ;
}
static void F_37 ( struct V_22 * V_23 )
{
unsigned long V_32 ;
F_33 ( V_23 , 0 ) ;
V_32 = V_36 + F_23 ( 500 ) ;
while ( ( F_22 ( V_23 -> V_34 + V_45 ) & V_64 )
&& F_26 ( V_36 , V_32 ) )
;
if ( F_25 ( V_37 , & V_23 -> V_5 -> V_38 ) )
return;
if ( F_22 ( V_23 -> V_34 + V_45 ) & V_64 ) {
F_5 ( & V_23 -> V_5 -> V_2 -> V_10 ,
L_3 ) ;
if ( F_20 ( V_23 -> V_5 ) )
F_38 ( & V_23 -> V_5 -> V_2 -> V_10 ,
L_4 ) ;
F_24 ( 30 ) ;
}
F_5 ( & V_23 -> V_5 -> V_2 -> V_10 , L_5 ) ;
F_21 ( F_22 ( V_23 -> V_34 + V_65 ) |
1 , V_23 -> V_34 + V_65 ) ;
F_22 ( V_23 -> V_34 + V_65 ) ;
V_32 = V_36 + F_23 ( 1 ) ;
while ( F_26 ( V_36 , V_32 ) )
;
if ( F_25 ( V_37 , & V_23 -> V_5 -> V_38 ) )
return;
F_21 ( F_22 ( V_23 -> V_34 + V_65 ) & ~ 1 ,
V_23 -> V_34 + V_65 ) ;
F_22 ( V_23 -> V_34 + V_65 ) ;
V_32 = V_36 + F_23 ( 500 ) ;
while ( ( ( F_22 ( V_23 -> V_34 + V_66 ) & 0x01 ) == 0 )
&& F_26 ( V_36 , V_32 ) )
;
if ( F_25 ( V_37 , & V_23 -> V_5 -> V_38 ) )
return;
if ( ( F_22 ( V_23 -> V_34 + V_66 ) & 0x01 ) == 0 )
F_5 ( & V_23 -> V_5 -> V_2 -> V_10 ,
L_6 ) ;
F_36 ( V_23 ) ;
F_34 ( V_23 ) ;
}
static int F_39 ( struct V_4 * V_5 )
{
int V_67 = 0 ;
if ( F_1 ( V_5 -> V_2 ) )
return 0 ;
if ( F_20 ( V_5 ) < 0 )
V_67 = - V_68 ;
F_24 ( 1 ) ;
F_36 ( V_5 -> V_23 ) ;
F_34 ( V_5 -> V_23 ) ;
F_21 ( F_22 ( V_5 -> V_34 + V_35 ) | V_69 ,
V_5 -> V_34 + V_35 ) ;
return V_67 ;
}
static void F_40 ( struct V_4 * V_5 ,
char * V_70 ,
unsigned long * V_71 ,
int V_72 )
{
unsigned char V_73 [ 128 ] ;
int V_39 , V_74 = 0 ;
memset ( V_73 , 0 , sizeof( V_73 ) ) ;
for ( V_39 = V_75 ; V_39 > 0 ; V_39 -- )
V_74 += sprintf ( V_73 + V_74 , L_7 ,
V_71 [ V_39 - 1 ] ) ;
F_5 ( & V_5 -> V_2 -> V_10 ,
L_8 , V_72 , V_70 , V_73 ) ;
}
static void F_41 ( struct V_22 * V_23 ,
int V_17 , struct V_12 * V_76 , int V_24 )
{
struct V_77 * V_78 = V_76 -> V_79 ;
if ( F_16 ( V_24 == V_25 ) )
F_5 ( & V_23 -> V_5 -> V_2 -> V_10 ,
L_9 , V_17 ) ;
F_42 ( V_78 ) ;
}
static void F_43 ( struct V_22 * V_23 ,
int V_17 , struct V_12 * V_76 , int V_24 )
{
}
static void F_44 ( struct V_4 * V_5 )
{
int V_39 , V_17 , V_80 , V_81 , V_67 ;
struct V_22 * V_23 ;
struct V_12 * V_16 ;
T_2 V_60 ;
struct V_82 * V_83 ;
unsigned long V_84 [ V_75 ] ;
unsigned int V_85 = 0 ;
unsigned char * V_86 ;
char * V_87 = NULL ;
int V_88 = 0 , V_89 = 0 ;
F_5 ( & V_5 -> V_2 -> V_10 , L_10 ) ;
V_23 = V_5 -> V_23 ;
F_4 ( V_90 , & V_23 -> V_91 ) ;
if ( F_25 ( V_92 , & V_23 -> V_91 ) ) {
V_16 = F_14 ( V_5 , V_93 ) ;
F_45 ( V_94 L_11 ) ;
if ( V_16 -> V_79 && V_16 -> V_95 ) {
V_16 -> V_95 ( V_23 , V_93 ,
V_16 , V_25 ) ;
}
goto V_96;
}
memset ( V_84 , 0 , V_75 * sizeof( long ) ) ;
for ( V_39 = 0 ; V_39 < V_5 -> V_59 ; V_39 ++ ) {
V_60 = F_22 ( V_23 -> V_60 [ V_39 ] ) ;
F_5 ( & V_5 -> V_2 -> V_10 , L_12 , V_39 , V_60 ) ;
F_21 ( V_60 , V_23 -> V_60 [ V_39 ] ) ;
for ( V_80 = 0 ; V_80 < 32 && V_60 ; V_80 ++ ) {
if ( ! ( V_60 & ( 1 << V_80 ) ) )
continue;
V_17 = ( V_39 << 5 ) + V_80 ;
if ( V_17 == V_93 )
continue;
V_16 = F_14 ( V_5 , V_17 ) ;
if ( F_46 ( V_16 -> V_95 ) ) {
F_4 ( V_17 , V_84 ) ;
V_85 ++ ;
V_16 -> V_95 ( V_23 , V_17 , V_16 , 0 ) ;
} else {
F_38 ( & V_23 -> V_5 -> V_2 -> V_10 ,
L_13 ,
V_17 ) ;
if ( F_1 ( V_5 -> V_2 ) ) {
return;
}
}
}
}
F_40 ( V_5 , L_14 , V_84 , V_85 ) ;
F_24 ( 20 ) ;
F_37 ( V_23 ) ;
V_67 = F_47 ( V_5 -> V_23 , V_97 ,
V_5 -> V_23 -> V_98 ,
V_5 -> V_23 -> V_99 , 1 ) ;
if ( V_67 ) {
F_5 ( & V_5 -> V_2 -> V_10 ,
L_15 ) ;
} else {
V_86 = ( unsigned char * ) V_5 -> V_23 -> V_98 ;
if ( V_86 [ 259 ] & 0x1 ) {
F_48 ( & V_5 -> V_2 -> V_10 ,
L_16 ) ;
F_4 ( V_100 , & V_5 -> V_38 ) ;
V_88 = 1 ;
V_87 = L_17 ;
}
if ( V_86 [ 288 ] == 0xF7 ) {
F_48 ( & V_5 -> V_2 -> V_10 ,
L_18 ) ;
F_4 ( V_101 , & V_5 -> V_38 ) ;
V_89 = 1 ;
V_87 = L_19 ;
}
if ( V_86 [ 288 ] == 0xBF ) {
F_4 ( V_102 , & V_5 -> V_38 ) ;
F_48 ( & V_5 -> V_2 -> V_10 ,
L_20 ) ;
V_89 = 1 ;
V_87 = L_21 ;
}
}
memset ( V_84 , 0 , V_75 * sizeof( long ) ) ;
for ( V_39 = 0 ; V_39 < V_5 -> V_59 ; V_39 ++ ) {
for ( V_80 = 0 ; V_80 < 32 ; V_80 ++ ) {
V_81 = 1 ;
V_17 = ( V_39 << 5 ) + V_80 ;
V_16 = F_14 ( V_5 , V_17 ) ;
V_83 = (struct V_82 * ) V_16 -> V_76 ;
if ( V_17 == V_93 ||
V_83 -> V_76 == V_103 )
V_81 = 0 ;
else {
if ( V_89 ||
( V_88 &&
V_83 -> V_76 == V_104 ) ) {
F_5 ( & V_5 -> V_2 -> V_10 ,
L_22 ,
V_83 -> V_76 == V_104 ?
L_23 : L_24 ,
V_17 ,
V_87 != NULL ?
V_87 : L_25 ) ;
if ( V_16 -> V_95 ) {
V_16 -> V_95 ( V_23 , V_17 ,
V_16 , - V_105 ) ;
}
continue;
}
}
if ( V_81 && ( V_16 -> V_106 -- > 0 ) ) {
F_4 ( V_17 , V_84 ) ;
F_27 ( V_23 , V_17 ) ;
continue;
}
F_5 ( & V_23 -> V_5 -> V_2 -> V_10 ,
L_26 , V_17 ) ;
if ( V_16 -> V_95 )
V_16 -> V_95 ( V_23 , V_17 , V_16 , V_25 ) ;
else
F_5 ( & V_23 -> V_5 -> V_2 -> V_10 ,
L_27 ,
V_17 ) ;
}
}
F_40 ( V_5 , L_28 , V_84 , V_85 ) ;
V_96:
F_49 ( V_90 , & V_23 -> V_91 ) ;
F_50 ( & V_23 -> V_107 ) ;
}
static inline void F_51 ( struct V_22 * V_23 , int V_39 ,
T_2 V_60 )
{
struct V_4 * V_5 = V_23 -> V_5 ;
int V_17 , V_80 ;
struct V_12 * V_76 ;
if ( ! V_60 ) {
F_52 ( ! V_60 ) ;
return;
}
F_21 ( V_60 , V_23 -> V_60 [ V_39 ] ) ;
for ( V_80 = 0 ; ( V_80 < 32 ) && V_60 ; V_80 ++ ) {
if ( V_60 & 0x01 ) {
V_17 = ( V_39 << 5 ) | V_80 ;
if ( F_16 ( V_17 == V_93 ) )
continue;
V_76 = F_14 ( V_5 , V_17 ) ;
if ( F_46 ( V_76 -> V_95 ) )
V_76 -> V_95 ( V_23 , V_17 , V_76 , 0 ) ;
else {
F_53 ( & V_5 -> V_2 -> V_10 ,
L_29 ,
V_17 ) ;
if ( F_1 (
V_5 -> V_2 ) ) {
return;
}
}
}
V_60 >>= 1 ;
}
if ( F_54 ( & V_5 -> V_108 ) == 0 )
F_21 ( 0xffffffff , V_5 -> V_34 + V_62 ) ;
}
static inline void F_55 ( struct V_4 * V_5 , T_2 V_109 )
{
struct V_22 * V_23 = V_5 -> V_23 ;
struct V_12 * V_16 = F_14 ( V_5 , V_93 ) ;
if ( F_25 ( V_92 , & V_23 -> V_91 ) &&
( V_16 != NULL ) && ! ( F_22 ( V_23 -> V_42 [ V_93 ] )
& ( 1 << V_93 ) ) ) {
if ( V_16 -> V_95 ) {
V_16 -> V_95 ( V_23 , V_93 , V_16 , 0 ) ;
return;
}
}
return;
}
static inline void F_56 ( struct V_4 * V_5 , T_2 V_109 )
{
if ( F_16 ( V_109 & V_110 ) ) {
F_5 ( & V_5 -> V_2 -> V_10 ,
L_30 ) ;
F_21 ( ( 1 << 26 ) , V_5 -> V_23 -> V_34 + V_58 ) ;
}
if ( F_16 ( V_109 & V_111 ) ) {
F_5 ( & V_5 -> V_2 -> V_10 ,
L_31 ) ;
F_21 ( ( 1 << 16 ) , V_5 -> V_23 -> V_34 + V_58 ) ;
}
if ( F_16 ( V_109 & ~ V_112 ) ) {
F_5 ( & V_5 -> V_2 -> V_10 ,
L_32 ,
( V_109 & ~ V_112 ) ) ;
if ( F_1 ( V_5 -> V_2 ) )
return;
}
if ( F_46 ( V_109 & ( V_25 | V_113 ) ) ) {
F_4 ( V_90 , & V_5 -> V_23 -> V_91 ) ;
F_50 ( & V_5 -> V_23 -> V_107 ) ;
}
}
static inline T_3 F_57 ( struct V_4 * V_114 )
{
struct V_4 * V_5 = (struct V_4 * ) V_114 ;
struct V_22 * V_23 = V_5 -> V_23 ;
T_2 V_115 , V_109 ;
int V_67 = V_116 ;
int V_117 = 1 , V_49 , V_118 ;
struct V_119 * V_120 ;
V_115 = F_22 ( V_5 -> V_34 + V_62 ) ;
if ( V_115 ) {
V_67 = V_121 ;
V_109 = F_22 ( V_23 -> V_34 + V_61 ) ;
if ( F_16 ( V_109 == 0xFFFFFFFF ) ) {
F_1 ( V_5 -> V_2 ) ;
return V_121 ;
}
F_21 ( V_109 , V_23 -> V_34 + V_61 ) ;
if ( F_46 ( V_109 & V_122 ) ) {
V_117 = 0 ;
F_52 ( F_58 ( & V_5 -> V_108 ) != 0 ) ;
for ( V_49 = 0 , V_118 = 0 ; V_49 < V_123 ;
V_49 ++ ) {
V_120 = & V_5 -> V_124 [ V_49 ] ;
V_120 -> V_60 = F_22 ( V_23 -> V_60 [ V_49 ] ) ;
if ( V_120 -> V_60 )
V_118 ++ ;
}
F_59 ( & V_5 -> V_108 , V_118 ) ;
if ( V_118 ) {
for ( V_49 = 1 ; V_49 < V_123 ; V_49 ++ ) {
V_120 = & V_5 -> V_124 [ V_49 ] ;
if ( V_120 -> V_60 )
F_60 (
V_120 -> V_125 ,
V_5 -> V_126 ,
& V_120 -> V_124 ) ;
}
if ( F_46 ( V_5 -> V_124 [ 0 ] . V_60 ) )
F_51 ( V_23 , 0 ,
V_5 -> V_124 [ 0 ] . V_60 ) ;
} else {
V_117 = 1 ;
}
}
if ( F_16 ( V_109 & V_127 ) ) {
if ( F_16 ( F_1 ( V_5 -> V_2 ) ) ) {
return V_121 ;
}
if ( F_25 ( V_37 ,
& V_5 -> V_38 ) )
return V_67 ;
F_56 ( V_5 , V_109 & V_127 ) ;
}
if ( F_16 ( V_109 & V_128 ) )
F_55 ( V_5 , V_109 & V_128 ) ;
}
if ( F_16 ( V_117 ) )
F_21 ( V_115 , V_5 -> V_34 + V_62 ) ;
return V_67 ;
}
static T_3 F_61 ( int V_129 , void * V_130 )
{
struct V_4 * V_5 = V_130 ;
return F_57 ( V_5 ) ;
}
static void F_62 ( struct V_22 * V_23 , int V_17 )
{
F_21 ( 1 << F_29 ( V_17 ) ,
V_23 -> V_42 [ F_30 ( V_17 ) ] ) ;
}
static bool F_63 ( struct V_22 * V_23 ,
struct V_82 * V_83 )
{
struct V_82 * V_131 ;
unsigned long V_132 ;
V_131 = V_23 -> V_133 + V_134 ;
V_132 = F_22 ( V_23 -> V_34 + V_135 ) ;
if ( ( V_132 & 1 ) )
return false ;
if ( V_83 -> V_76 == V_136 ) {
V_23 -> V_137 = V_36 ;
return true ;
} else if ( ( V_83 -> V_76 == V_138 ) &&
( V_83 -> V_139 == 0x03 ) ) {
F_4 ( V_140 , & V_23 -> V_91 ) ;
V_23 -> V_137 = V_36 ;
return true ;
} else if ( ( V_83 -> V_76 == V_141 ) ||
( ( V_83 -> V_76 == 0xFC ) &&
( V_83 -> V_139 == 0x27 || V_83 -> V_139 == 0x72 ||
V_83 -> V_139 == 0x62 || V_83 -> V_139 == 0x26 ) ) ) {
F_49 ( V_102 , & V_23 -> V_5 -> V_38 ) ;
F_37 ( V_23 ) ;
F_49 ( V_142 , & V_23 -> V_91 ) ;
return false ;
}
return false ;
}
static int F_64 ( struct V_22 * V_23 , unsigned long V_32 )
{
unsigned long V_143 ;
unsigned int V_144 ;
unsigned int V_145 = 1 ;
F_65 ( V_23 -> V_5 -> V_7 ) ;
V_143 = V_36 + F_23 ( V_32 ) ;
do {
if ( F_25 ( V_146 , & V_23 -> V_91 ) &&
F_25 ( V_147 , & V_23 -> V_91 ) ) {
F_66 ( 20 ) ;
continue;
}
F_66 ( 100 ) ;
if ( F_1 ( V_23 -> V_5 -> V_2 ) )
goto V_148;
if ( F_25 ( V_37 , & V_23 -> V_5 -> V_38 ) )
goto V_148;
V_145 = F_22 ( V_23 -> V_41 [ 0 ] ) & 0xFFFFFFFE ;
for ( V_144 = 1 ; V_144 < V_23 -> V_5 -> V_59 ; V_144 ++ )
V_145 |= F_22 ( V_23 -> V_41 [ V_144 ] ) ;
if ( ! V_145 )
break;
} while ( F_26 ( V_36 , V_143 ) );
F_67 ( V_23 -> V_5 -> V_7 , true ) ;
return V_145 ? - V_149 : 0 ;
V_148:
F_67 ( V_23 -> V_5 -> V_7 , true ) ;
return - V_68 ;
}
static int F_68 ( struct V_22 * V_23 ,
struct V_82 * V_83 ,
int V_150 ,
T_4 V_151 ,
int V_152 ,
T_2 V_153 ,
T_5 V_154 ,
unsigned long V_32 )
{
struct V_155 * V_156 ;
F_69 ( V_157 ) ;
struct V_12 * V_158 ;
struct V_4 * V_5 = V_23 -> V_5 ;
int V_67 = 0 ;
if ( V_151 & 0x00000007 ) {
F_38 ( & V_5 -> V_2 -> V_10 , L_33 ) ;
return - V_68 ;
}
V_158 = F_6 ( V_5 ) ;
F_4 ( V_92 , & V_23 -> V_91 ) ;
if ( V_83 -> V_76 == V_136 )
F_4 ( V_142 , & V_23 -> V_91 ) ;
F_49 ( V_140 , & V_23 -> V_91 ) ;
if ( V_154 == V_159 ) {
if ( V_83 -> V_76 != V_160 ) {
if ( F_64 ( V_23 ,
V_161 ) < 0 ) {
F_5 ( & V_5 -> V_2 -> V_10 ,
L_34 ) ;
F_9 ( V_5 , V_158 ) ;
F_49 ( V_92 , & V_23 -> V_91 ) ;
F_50 ( & V_23 -> V_107 ) ;
return - V_149 ;
}
}
V_158 -> V_79 = & V_157 ;
V_158 -> V_95 = F_41 ;
} else {
V_158 -> V_79 = NULL ;
V_158 -> V_95 = F_43 ;
}
memcpy ( V_158 -> V_76 , V_83 , V_150 * 4 ) ;
V_158 -> V_162 -> V_153 =
V_163 F_70 ( V_153 | V_150 ) ;
if ( V_152 ) {
V_156 = V_158 -> V_76 + V_164 ;
V_156 -> V_165 =
V_163 F_70 ( ( V_152 - 1 ) & 0x3FFFFF ) ;
V_156 -> V_166 =
V_163 F_70 ( V_151 & 0xFFFFFFFF ) ;
V_156 -> V_167 =
V_163 F_70 ( ( V_151 >> 16 ) >> 16 ) ;
V_158 -> V_162 -> V_153 |=
V_163 F_70 ( ( 1 << 16 ) ) ;
}
V_158 -> V_162 -> V_168 = 0 ;
F_62 ( V_23 , V_93 ) ;
if ( V_154 == V_159 ) {
if ( ( V_67 = F_71 (
& V_157 ,
F_23 ( V_32 ) ) ) <= 0 ) {
if ( V_67 == - V_169 ) {
F_38 ( & V_5 -> V_2 -> V_10 ,
L_35 ,
V_83 -> V_76 , V_32 ) ;
V_67 = - V_170 ;
goto V_171;
} else if ( V_67 == 0 )
F_38 ( & V_5 -> V_2 -> V_10 ,
L_36 ,
V_83 -> V_76 , V_32 ) ;
else
F_38 ( & V_5 -> V_2 -> V_10 ,
L_37 ,
V_83 -> V_76 , V_67 , V_32 ) ;
if ( F_1 ( V_5 -> V_2 ) ||
F_25 ( V_37 ,
& V_5 -> V_38 ) ) {
F_38 ( & V_5 -> V_2 -> V_10 ,
L_38 ,
V_83 -> V_76 ) ;
V_67 = - V_172 ;
goto V_171;
}
F_39 ( V_5 ) ;
V_67 = - V_173 ;
goto V_171;
}
} else {
T_2 V_115 , V_109 ;
V_32 = V_36 + F_23 ( V_32 ) ;
while ( ( F_22 ( V_23 -> V_42 [ V_93 ] )
& ( 1 << V_93 ) )
&& F_26 ( V_36 , V_32 ) ) {
if ( F_1 ( V_5 -> V_2 ) ) {
V_67 = - V_172 ;
goto V_171;
}
if ( ( V_83 -> V_76 != V_160 ) &&
F_25 ( V_37 ,
& V_5 -> V_38 ) ) {
V_67 = - V_172 ;
goto V_171;
}
V_109 = F_22 ( V_23 -> V_34 + V_61 ) ;
if ( ! V_109 )
continue;
if ( V_109 & V_127 ) {
F_38 ( & V_5 -> V_2 -> V_10 ,
L_39 ,
V_83 -> V_76 ) ;
F_39 ( V_5 ) ;
V_67 = - V_31 ;
goto V_171;
} else {
F_21 ( V_109 , V_23 -> V_34 + V_61 ) ;
V_115 = F_22 ( V_5 -> V_34 + V_62 ) ;
if ( V_115 )
F_21 ( V_115 ,
V_5 -> V_34 + V_62 ) ;
}
break;
}
}
if ( F_22 ( V_23 -> V_42 [ V_93 ] )
& ( 1 << V_93 ) ) {
V_67 = - V_172 ;
if ( ! F_25 ( V_37 , & V_5 -> V_38 ) ) {
F_39 ( V_5 ) ;
V_67 = - V_173 ;
}
}
V_171:
F_9 ( V_5 , V_158 ) ;
F_49 ( V_92 , & V_23 -> V_91 ) ;
if ( V_67 >= 0 && F_63 ( V_23 , V_83 ) ) {
return V_67 ;
}
F_50 ( & V_23 -> V_107 ) ;
return V_67 ;
}
static inline void F_72 ( T_1 * V_86 , unsigned int V_174 )
{
int V_49 ;
for ( V_49 = 0 ; V_49 < ( V_174 / 2 ) ; V_49 ++ )
F_73 ( & V_86 [ V_49 ] ) ;
}
static void F_74 ( struct V_4 * V_5 ,
struct V_82 * V_83 ,
unsigned int * V_32 , T_6 V_175 )
{
switch ( V_83 -> V_76 ) {
case V_138 :
* V_32 = 120000 ;
break;
case V_141 :
case 0xFC :
if ( V_175 )
* V_32 = ( ( * ( V_5 -> V_23 -> V_176 + 90 ) * 2 ) * 60000 ) ;
else
* V_32 = ( ( * ( V_5 -> V_23 -> V_176 + 89 ) * 2 ) * 60000 ) ;
break;
case V_160 :
* V_32 = 120000 ;
break;
case 0xF7 :
case 0xFA :
* V_32 = 60000 ;
break;
case V_177 :
* V_32 = 15000 ;
break;
default:
* V_32 = V_178 ;
break;
}
}
static int F_75 ( struct V_22 * V_23 , void T_7 * V_179 )
{
int V_67 = 0 ;
struct V_82 V_83 ;
if ( F_25 ( V_37 , & V_23 -> V_5 -> V_38 ) )
return - V_68 ;
memset ( & V_83 , 0 , sizeof( struct V_82 ) ) ;
V_83 . type = 0x27 ;
V_83 . V_153 = 1 << 7 ;
V_83 . V_76 = V_180 ;
V_23 -> V_181 = 0 ;
memset ( V_23 -> V_176 , 0 , sizeof( T_1 ) * V_182 ) ;
if ( F_68 ( V_23 ,
& V_83 ,
5 ,
V_23 -> V_183 ,
sizeof( T_1 ) * V_182 ,
0 ,
V_159 ,
V_184 )
< 0 ) {
V_67 = - 1 ;
goto V_185;
}
#ifdef F_76
F_72 ( V_23 -> V_176 + 27 , 40 ) ;
F_72 ( V_23 -> V_176 + 23 , 8 ) ;
F_72 ( V_23 -> V_176 + 10 , 20 ) ;
#else
{
int V_49 ;
for ( V_49 = 0 ; V_49 < V_182 ; V_49 ++ )
V_23 -> V_176 [ V_49 ] = F_77 ( V_23 -> V_176 [ V_49 ] ) ;
}
#endif
if ( V_23 -> V_176 [ 128 ] & 0x4 )
F_4 ( V_102 , & V_23 -> V_5 -> V_38 ) ;
else
F_49 ( V_102 , & V_23 -> V_5 -> V_38 ) ;
#ifdef F_78
if ( V_23 -> V_176 [ 69 ] & ( 1 << 14 ) && V_23 -> V_176 [ 69 ] & ( 1 << 5 ) )
V_23 -> V_5 -> V_186 = true ;
else
#endif
V_23 -> V_5 -> V_186 = false ;
V_23 -> V_181 = 1 ;
if ( V_179 ) {
if ( F_79 (
V_179 ,
V_23 -> V_176 ,
V_182 * sizeof( T_1 ) ) ) {
V_67 = - V_68 ;
goto V_185;
}
}
V_185:
return V_67 ;
}
static int F_80 ( struct V_22 * V_23 )
{
int V_67 ;
struct V_82 V_83 ;
unsigned long V_187 ;
unsigned int V_32 ;
memset ( & V_83 , 0 , sizeof( struct V_82 ) ) ;
V_83 . type = 0x27 ;
V_83 . V_153 = 1 << 7 ;
V_83 . V_76 = V_160 ;
F_74 ( V_23 -> V_5 , & V_83 , & V_32 , 0 ) ;
V_187 = V_36 ;
V_67 = F_68 ( V_23 ,
& V_83 ,
5 ,
0 ,
0 ,
0 ,
V_188 ,
V_32 ) ;
F_45 ( V_94 L_40 ,
F_81 ( V_36 - V_187 ) ) ;
if ( V_67 )
F_5 ( & V_23 -> V_5 -> V_2 -> V_10 ,
L_41 ) ;
return V_67 ;
}
static int F_47 ( struct V_22 * V_23 , T_6 V_189 , T_1 * V_151 ,
T_4 V_190 , unsigned int V_191 )
{
struct V_82 V_83 ;
memset ( & V_83 , 0 , sizeof( struct V_82 ) ) ;
V_83 . type = 0x27 ;
V_83 . V_153 = 1 << 7 ;
V_83 . V_76 = V_192 ;
V_83 . V_193 = V_191 & 0xFF ;
V_83 . V_194 = ( V_191 >> 8 ) & 0xFF ;
V_83 . V_195 = V_189 ;
V_83 . V_196 = 0 ;
V_83 . V_197 = V_198 ;
memset ( V_151 , 0 , V_191 * V_199 ) ;
return F_68 ( V_23 ,
& V_83 ,
5 ,
V_190 ,
V_191 * V_199 ,
0 ,
V_188 ,
V_184 ) ;
}
static int F_82 ( struct V_22 * V_23 , T_6 * V_151 ,
T_4 V_190 )
{
struct V_82 V_83 ;
memset ( & V_83 , 0 , sizeof( struct V_82 ) ) ;
V_83 . type = 0x27 ;
V_83 . V_153 = 1 << 7 ;
V_83 . V_76 = V_177 ;
V_83 . V_139 = 0xD0 ;
V_83 . V_193 = 1 ;
V_83 . V_196 = 0x4F ;
V_83 . V_200 = 0xC2 ;
V_83 . V_197 = V_198 ;
return F_68 ( V_23 ,
& V_83 ,
5 ,
V_190 ,
V_199 ,
0 ,
V_188 ,
15000 ) ;
}
static int F_83 ( struct V_22 * V_23 , unsigned int V_201 ,
struct V_202 * V_203 )
{
int V_67 , V_49 ;
struct V_202 * V_204 ;
if ( ! V_203 )
return - V_205 ;
if ( ! V_23 -> V_181 ) {
F_5 ( & V_23 -> V_5 -> V_2 -> V_10 , L_42 ) ;
return - V_206 ;
}
if ( ! ( V_23 -> V_176 [ 82 ] & 0x1 ) ) {
F_5 ( & V_23 -> V_5 -> V_2 -> V_10 , L_43 ) ;
return - V_206 ;
}
if ( ! ( V_23 -> V_176 [ 85 ] & 0x1 ) ) {
F_5 ( & V_23 -> V_5 -> V_2 -> V_10 , L_44 ) ;
return - V_206 ;
}
memset ( V_23 -> V_207 , 0 , V_199 ) ;
V_67 = F_82 ( V_23 , V_23 -> V_207 , V_23 -> V_208 ) ;
if ( V_67 ) {
F_5 ( & V_23 -> V_5 -> V_2 -> V_10 , L_45 ) ;
return V_67 ;
}
V_204 = (struct V_202 * ) ( V_23 -> V_207 + 2 ) ;
for ( V_49 = 0 ; V_49 < 29 ; V_49 ++ , V_204 ++ )
if ( V_204 -> V_209 == V_201 ) {
memcpy ( V_203 , V_204 , sizeof( struct V_202 ) ) ;
break;
}
if ( V_49 == 29 ) {
F_5 ( & V_23 -> V_5 -> V_2 -> V_10 ,
L_46 ) ;
V_67 = - V_205 ;
}
return V_67 ;
}
static int F_84 ( struct V_4 * V_5 , unsigned int V_210 ,
unsigned int V_174 )
{
int V_49 , V_67 = 0 ;
T_8 V_211 , V_212 , V_213 ;
struct V_214 * V_86 ;
T_4 V_215 ;
struct V_82 V_83 ;
if ( ! V_174 || V_5 -> V_186 == false )
return - V_205 ;
F_85 ( V_174 > ( V_216 * V_217 ) ) ;
F_85 ( V_174 % 8 != 0 ) ;
F_85 ( sizeof( struct V_218 ) > V_199 ) ;
V_86 = F_86 ( & V_5 -> V_2 -> V_10 , V_199 , & V_215 ,
V_159 ) ;
if ( ! V_86 )
return - V_219 ;
memset ( V_86 , 0 , V_199 ) ;
for ( V_49 = 0 , V_213 = V_174 , V_211 = V_210 ;
V_49 < V_217 && V_213 ;
V_49 ++ ) {
V_212 = ( V_213 >= V_216 ?
V_216 :
V_213 ) ;
V_86 [ V_49 ] . V_210 = V_163 F_70 ( V_211 ) ;
V_86 [ V_49 ] . V_220 = V_163 F_87 ( V_212 ) ;
V_211 += V_212 ;
V_213 -= V_212 ;
}
F_85 ( V_213 != 0 ) ;
memset ( & V_83 , 0 , sizeof( struct V_82 ) ) ;
V_83 . type = 0x27 ;
V_83 . V_153 = 1 << 7 ;
V_83 . V_76 = 0xfb ;
V_83 . V_139 = 0x60 ;
V_83 . V_193 = 1 ;
V_83 . V_197 = V_198 ;
if ( F_68 ( V_5 -> V_23 ,
& V_83 ,
5 ,
V_215 ,
V_199 ,
0 ,
V_159 ,
V_221 ) < 0 )
V_67 = - V_31 ;
F_88 ( & V_5 -> V_2 -> V_10 , V_199 , V_86 , V_215 ) ;
return V_67 ;
}
static bool F_89 ( struct V_4 * V_5 , T_9 * V_191 )
{
struct V_22 * V_23 = V_5 -> V_23 ;
T_8 V_222 , V_223 , V_224 , V_225 , V_226 ;
V_223 = V_23 -> V_176 [ 100 ] ;
V_224 = V_23 -> V_176 [ 101 ] ;
V_225 = V_23 -> V_176 [ 102 ] ;
V_226 = V_23 -> V_176 [ 103 ] ;
V_222 = V_223 | V_224 << 16 | V_225 << 32 | V_226 << 48 ;
* V_191 = V_222 ;
return ( bool ) ! ! V_23 -> V_181 ;
}
static void F_90 ( struct V_22 * V_23 )
{
T_9 V_191 ;
unsigned short V_227 ;
char V_228 [ 42 ] ;
if ( ! V_23 -> V_181 )
return;
F_91 ( V_228 , ( char * ) ( V_23 -> V_176 + 10 ) , 21 ) ;
F_48 ( & V_23 -> V_5 -> V_2 -> V_10 ,
L_47 , V_228 ) ;
F_91 ( V_228 , ( char * ) ( V_23 -> V_176 + 23 ) , 9 ) ;
F_48 ( & V_23 -> V_5 -> V_2 -> V_10 ,
L_48 , V_228 ) ;
F_91 ( V_228 , ( char * ) ( V_23 -> V_176 + 27 ) , 41 ) ;
F_48 ( & V_23 -> V_5 -> V_2 -> V_10 , L_49 , V_228 ) ;
F_48 ( & V_23 -> V_5 -> V_2 -> V_10 , L_50 ,
V_23 -> V_176 [ 128 ] ,
V_23 -> V_176 [ 128 ] & 0x4 ? L_51 : L_52 ) ;
if ( F_89 ( V_23 -> V_5 , & V_191 ) )
F_48 ( & V_23 -> V_5 -> V_2 -> V_10 ,
L_53 ,
( T_8 ) V_191 ,
( ( T_8 ) V_191 ) * V_199 >> 20 ) ;
F_3 ( V_23 -> V_5 -> V_2 , V_229 , & V_227 ) ;
switch ( V_227 & 0xFF ) {
case 0x1 :
F_91 ( V_228 , L_54 , 3 ) ;
break;
case 0x3 :
F_91 ( V_228 , L_55 , 3 ) ;
break;
default:
F_91 ( V_228 , L_56 , 2 ) ;
break;
}
F_48 ( & V_23 -> V_5 -> V_2 -> V_10 ,
L_57 , V_228 ) ;
}
static inline void F_92 ( struct V_4 * V_5 ,
struct V_12 * V_76 ,
int V_230 )
{
int V_144 ;
unsigned int V_231 ;
struct V_155 * V_156 ;
struct V_232 * V_26 = V_76 -> V_26 ;
V_156 = V_76 -> V_76 + V_164 ;
for ( V_144 = 0 ; V_144 < V_230 ; V_144 ++ ) {
V_231 = F_93 ( V_26 ) ;
if ( V_231 > 0x400000 )
F_38 ( & V_5 -> V_2 -> V_10 ,
L_58 ) ;
V_156 -> V_165 = V_163
F_70 ( ( V_231 - 1 ) & 0x3FFFFF ) ;
V_156 -> V_166 = V_163
F_70 ( F_94 ( V_26 ) ) ;
V_156 -> V_167 = V_163
F_70 ( ( F_94 ( V_26 ) >> 16 ) >> 16 ) ;
V_156 ++ ;
V_26 ++ ;
}
}
static int F_95 ( struct V_22 * V_23 , T_6 * V_76 )
{
struct V_82 V_83 ;
struct V_82 * V_131 = ( V_23 -> V_133 + V_134 ) ;
unsigned int V_143 ;
memset ( & V_83 , 0 , sizeof( struct V_82 ) ) ;
V_83 . type = 0x27 ;
V_83 . V_153 = 1 << 7 ;
V_83 . V_76 = V_76 [ 0 ] ;
V_83 . V_139 = V_76 [ 1 ] ;
V_83 . V_193 = V_76 [ 2 ] ;
V_83 . V_233 = V_76 [ 3 ] ;
V_83 . V_234 = V_76 [ 4 ] ;
V_83 . V_235 = V_76 [ 5 ] ;
V_83 . V_197 = V_76 [ 6 ] & ~ 0x10 ;
F_74 ( V_23 -> V_5 , & V_83 , & V_143 , 0 ) ;
F_45 ( V_94 L_59 ,
V_11 ,
V_76 [ 0 ] ,
V_76 [ 1 ] ,
V_76 [ 2 ] ,
V_76 [ 3 ] ,
V_76 [ 4 ] ,
V_76 [ 5 ] ,
V_76 [ 6 ] ) ;
if ( F_68 ( V_23 ,
& V_83 ,
5 ,
0 ,
0 ,
0 ,
V_159 ,
V_143 ) < 0 ) {
return - 1 ;
}
V_76 [ 0 ] = V_131 -> V_76 ;
V_76 [ 1 ] = V_131 -> V_139 ;
V_76 [ 4 ] = V_131 -> V_234 ;
V_76 [ 5 ] = V_131 -> V_235 ;
F_45 ( V_94 L_60 ,
V_11 ,
V_76 [ 0 ] ,
V_76 [ 1 ] ,
V_76 [ 4 ] ,
V_76 [ 5 ] ) ;
return 0 ;
}
static int F_96 ( struct V_22 * V_23 , T_6 * V_76 ,
void T_7 * V_179 )
{
struct V_82 V_83 ;
struct V_82 * V_131 ;
T_6 * V_86 = NULL ;
T_4 V_215 = 0 ;
int V_67 = 0 , V_236 = V_76 [ 3 ] ;
unsigned int V_143 ;
if ( V_236 ) {
if ( ! V_179 )
return - V_68 ;
V_86 = F_86 ( & V_23 -> V_5 -> V_2 -> V_10 ,
V_199 * V_236 ,
& V_215 ,
V_159 ) ;
if ( ! V_86 ) {
F_38 ( & V_23 -> V_5 -> V_2 -> V_10 ,
L_61 ,
V_199 * V_236 ) ;
return - V_219 ;
}
memset ( V_86 , 0 , V_199 * V_236 ) ;
}
memset ( & V_83 , 0 , sizeof( struct V_82 ) ) ;
V_83 . type = 0x27 ;
V_83 . V_153 = 1 << 7 ;
V_83 . V_76 = V_76 [ 0 ] ;
V_83 . V_139 = V_76 [ 2 ] ;
V_83 . V_193 = V_76 [ 3 ] ;
if ( V_83 . V_76 == V_177 ) {
V_83 . V_233 = V_76 [ 1 ] ;
V_83 . V_234 = 0x4F ;
V_83 . V_235 = 0xC2 ;
}
F_74 ( V_23 -> V_5 , & V_83 , & V_143 , 0 ) ;
if ( V_236 )
V_131 = ( V_23 -> V_133 + V_237 ) ;
else
V_131 = ( V_23 -> V_133 + V_134 ) ;
F_45 ( V_94
L_62
L_63 ,
V_11 ,
V_76 [ 0 ] ,
V_76 [ 1 ] ,
V_76 [ 2 ] ,
V_76 [ 3 ] ) ;
if ( F_68 ( V_23 ,
& V_83 ,
5 ,
( V_236 ? V_215 : 0 ) ,
( V_236 ? V_199 * V_236 : 0 ) ,
0 ,
V_159 ,
V_143 )
< 0 ) {
V_67 = - V_68 ;
goto V_238;
}
V_76 [ 0 ] = V_131 -> V_76 ;
V_76 [ 1 ] = V_131 -> V_139 ;
V_76 [ 2 ] = V_131 -> V_193 ;
F_45 ( V_94
L_64
L_65 ,
V_11 ,
V_76 [ 0 ] ,
V_76 [ 1 ] ,
V_76 [ 2 ] ) ;
if ( V_236 ) {
if ( F_79 ( V_179 ,
V_86 ,
V_199 * V_76 [ 3 ] ) ) {
V_67 = - V_68 ;
goto V_238;
}
}
V_238:
if ( V_86 )
F_88 ( & V_23 -> V_5 -> V_2 -> V_10 ,
V_199 * V_236 , V_86 , V_215 ) ;
return V_67 ;
}
static unsigned int F_97 ( unsigned char V_76 ,
unsigned char V_139 )
{
unsigned int V_67 = 0 ;
switch ( V_76 ) {
case V_239 :
case V_240 :
case V_136 :
case V_141 :
case V_241 :
case V_242 :
case V_243 :
case V_244 :
V_67 = 1 ;
break;
case V_245 :
if ( V_139 == V_246 )
V_67 = 1 ;
break;
case V_177 :
if ( ( V_139 == V_247 ) ||
( V_139 == V_248 ) )
V_67 = 1 ;
break;
case V_249 :
if ( ( V_139 == V_250 ) ||
( V_139 == V_251 ) )
V_67 = 1 ;
break;
}
return V_67 ;
}
static int F_98 ( struct V_4 * V_5 ,
void T_7 * V_86 ,
T_10 * V_252 ,
int V_253 )
{
struct V_82 V_83 ;
struct V_82 * V_131 ;
T_6 * V_254 = NULL ;
T_6 * V_255 = NULL ;
T_4 V_256 = 0 ;
T_4 V_257 = 0 ;
T_4 V_258 = 0 ;
int V_259 = 0 ;
unsigned int V_260 = 0 ;
unsigned int V_261 = 0 ;
T_6 V_262 = 0 ;
unsigned int V_32 ;
unsigned int V_263 ;
unsigned int V_264 ;
unsigned long V_132 ;
int V_265 = V_253 + V_252 -> V_266 ;
int V_175 = 0 ;
V_261 = V_252 -> V_266 ;
V_260 = V_252 -> V_267 ;
if ( V_260 > 130560 || V_261 > 130560 ) {
V_259 = - V_205 ;
goto abort;
}
if ( V_261 ) {
V_254 = F_99 ( V_261 , V_159 ) ;
if ( V_254 == NULL ) {
V_259 = - V_219 ;
goto abort;
}
if ( F_100 ( V_254 , V_86 + V_253 , V_261 ) ) {
V_259 = - V_68 ;
goto abort;
}
V_256 = F_101 ( V_5 -> V_2 ,
V_254 ,
V_261 ,
V_268 ) ;
if ( V_256 == 0 ) {
V_259 = - V_219 ;
goto abort;
}
V_258 = V_256 ;
}
if ( V_260 ) {
V_255 = F_99 ( V_260 , V_159 ) ;
if ( V_255 == NULL ) {
V_259 = - V_219 ;
goto abort;
}
if ( F_100 ( V_255 , V_86 + V_265 , V_260 ) ) {
V_259 = - V_68 ;
goto abort;
}
V_257 = F_101 ( V_5 -> V_2 ,
V_255 ,
V_260 , V_269 ) ;
if ( V_257 == 0 ) {
V_259 = - V_219 ;
goto abort;
}
V_258 = V_257 ;
}
switch ( V_252 -> V_270 ) {
case V_271 :
V_262 = V_261 / V_199 ;
V_131 = ( V_5 -> V_23 -> V_133 + V_237 ) ;
break;
case V_272 :
V_131 = ( V_5 -> V_23 -> V_133 + V_237 ) ;
break;
case V_273 :
V_131 = ( V_5 -> V_23 -> V_133 + V_134 ) ;
break;
default:
V_259 = - V_205 ;
goto abort;
}
memset ( & V_83 , 0 , sizeof( struct V_82 ) ) ;
V_83 . type = 0x27 ;
V_83 . V_153 = 1 << 7 ;
V_83 . V_76 = V_252 -> V_274 [ 7 ] ;
V_83 . V_139 = V_252 -> V_274 [ 1 ] ;
V_83 . V_193 = V_252 -> V_274 [ 2 ] ;
V_83 . V_195 = V_252 -> V_274 [ 3 ] ;
V_83 . V_196 = V_252 -> V_274 [ 4 ] ;
V_83 . V_200 = V_252 -> V_274 [ 5 ] ;
V_83 . V_197 = V_252 -> V_274 [ 6 ] & ~ 0x10 ;
if ( ( V_252 -> V_275 . V_276 == 0 ) && ( V_252 -> V_277 . V_276 & 1 ) ) {
V_252 -> V_275 . V_276 =
V_278 |
( V_279 << 8 ) ;
V_83 . V_280 = V_252 -> V_281 [ 3 ] ;
V_83 . V_282 = V_252 -> V_281 [ 4 ] ;
V_83 . V_283 = V_252 -> V_281 [ 5 ] ;
V_83 . V_284 = V_252 -> V_281 [ 1 ] ;
V_83 . V_194 = V_252 -> V_281 [ 2 ] ;
} else {
V_252 -> V_275 . V_276 = V_278 ;
}
V_263 = F_97 ( V_83 . V_76 , V_83 . V_139 ) ;
if ( ( V_260 || V_261 ) && ( ! V_83 . V_193 ) ) {
if ( V_262 )
V_83 . V_193 = V_262 ;
else {
if ( ! V_263 ) {
F_5 ( & V_5 -> V_2 -> V_10 ,
L_66
L_67 ) ;
V_259 = - V_205 ;
goto abort;
}
}
}
F_45 ( V_94
L_68
L_69
L_70 ,
V_11 ,
V_83 . V_76 ,
V_83 . V_139 ,
V_83 . V_193 ,
V_83 . V_195 ,
V_83 . V_196 ,
V_83 . V_200 ,
V_83 . V_197 ) ;
if ( ( V_83 . V_76 == V_141 ) && V_254 &&
( V_254 [ 0 ] & V_285 ) ) {
V_175 = 1 ;
}
F_74 ( V_5 , & V_83 , & V_32 , V_175 ) ;
if ( V_263 )
V_264 = V_199 ;
else
V_264 = V_199 * V_83 . V_193 ;
if ( F_68 ( V_5 -> V_23 ,
& V_83 ,
5 ,
V_258 ,
V_264 ,
0 ,
V_159 ,
V_32 ) < 0 ) {
V_259 = - V_31 ;
goto abort;
}
V_132 = F_22 ( V_5 -> V_23 -> V_34 + V_135 ) ;
if ( ( V_252 -> V_270 == V_272 ) && ! ( V_132 & 1 ) ) {
V_131 = V_5 -> V_23 -> V_133 + V_237 ;
V_252 -> V_274 [ 7 ] = V_131 -> V_286 ;
} else {
V_131 = V_5 -> V_23 -> V_133 + V_134 ;
V_252 -> V_274 [ 7 ] = V_131 -> V_76 ;
}
if ( V_257 )
F_102 ( V_5 -> V_2 , V_257 ,
V_260 , V_269 ) ;
if ( V_256 )
F_102 ( V_5 -> V_2 , V_256 ,
V_261 , V_268 ) ;
V_257 = 0 ;
V_256 = 0 ;
V_252 -> V_274 [ 1 ] = V_131 -> V_139 ;
V_252 -> V_274 [ 2 ] = V_131 -> V_193 ;
V_252 -> V_274 [ 3 ] = V_131 -> V_195 ;
V_252 -> V_274 [ 4 ] = V_131 -> V_196 ;
V_252 -> V_274 [ 5 ] = V_131 -> V_200 ;
V_252 -> V_274 [ 6 ] = V_131 -> V_197 ;
if ( V_252 -> V_277 . V_276 & 1 ) {
V_252 -> V_281 [ 3 ] = V_131 -> V_280 ;
V_252 -> V_281 [ 4 ] = V_131 -> V_282 ;
V_252 -> V_281 [ 5 ] = V_131 -> V_283 ;
V_252 -> V_281 [ 1 ] = V_131 -> V_284 ;
V_252 -> V_281 [ 2 ] = V_131 -> V_194 ;
}
F_45 ( V_94
L_71
L_72
L_73 ,
V_11 ,
V_252 -> V_274 [ 7 ] ,
V_252 -> V_274 [ 1 ] ,
V_252 -> V_274 [ 2 ] ,
V_252 -> V_274 [ 3 ] ,
V_252 -> V_274 [ 4 ] ,
V_252 -> V_274 [ 5 ] ,
V_252 -> V_274 [ 6 ] ) ;
if ( V_261 ) {
if ( F_79 ( V_86 + V_253 , V_254 , V_261 ) ) {
V_259 = - V_68 ;
goto abort;
}
}
if ( V_260 ) {
if ( F_79 ( V_86 + V_265 , V_255 , V_260 ) ) {
V_259 = - V_68 ;
goto abort;
}
}
abort:
if ( V_257 )
F_102 ( V_5 -> V_2 , V_257 ,
V_260 , V_269 ) ;
if ( V_256 )
F_102 ( V_5 -> V_2 , V_256 ,
V_261 , V_268 ) ;
F_103 ( V_254 ) ;
F_103 ( V_255 ) ;
return V_259 ;
}
static int F_104 ( struct V_4 * V_5 , unsigned int V_16 ,
unsigned long V_287 )
{
switch ( V_16 ) {
case V_288 :
{
if ( F_79 ( ( void T_7 * ) V_287 , V_5 -> V_23 -> V_176 ,
sizeof( T_1 ) * V_182 ) )
return - V_68 ;
break;
}
case V_289 :
{
T_6 V_290 [ 4 ] ;
if ( F_100 ( V_290 ,
( void T_7 * ) V_287 ,
sizeof( V_290 ) ) )
return - V_68 ;
if ( F_96 ( V_5 -> V_23 ,
V_290 ,
( void T_7 * ) ( V_287 + 4 ) ) )
return - V_31 ;
if ( F_79 ( ( void T_7 * ) V_287 ,
V_290 ,
sizeof( V_290 ) ) )
return - V_68 ;
break;
}
case V_291 :
{
T_6 V_290 [ 7 ] ;
if ( F_100 ( V_290 ,
( void T_7 * ) V_287 ,
sizeof( V_290 ) ) )
return - V_68 ;
if ( F_95 ( V_5 -> V_23 , V_290 ) )
return - V_31 ;
if ( F_79 ( ( void T_7 * ) V_287 ,
V_290 ,
sizeof( V_290 ) ) )
return - V_68 ;
break;
}
case V_292 : {
T_10 V_252 ;
int V_293 , V_253 ;
if ( F_100 ( & V_252 , ( void T_7 * ) V_287 ,
sizeof( V_252 ) ) )
return - V_68 ;
V_253 = sizeof( V_252 ) ;
V_293 = F_98 ( V_5 , ( void T_7 * ) V_287 ,
& V_252 , V_253 ) ;
if ( F_79 ( ( void T_7 * ) V_287 , & V_252 ,
sizeof( V_252 ) ) )
return - V_68 ;
return V_293 ;
}
default:
return - V_205 ;
}
return 0 ;
}
static void F_105 ( struct V_4 * V_5 , struct V_13 * V_14 ,
struct V_12 * V_76 , int V_230 ,
struct V_18 * V_19 )
{
struct V_82 * V_83 ;
struct V_22 * V_23 = V_5 -> V_23 ;
int V_294 = F_106 ( V_14 ) == V_295 ? V_269 : V_268 ;
T_8 V_187 = F_107 ( V_14 ) ;
unsigned int V_262 = F_108 ( V_14 ) ;
V_230 = F_109 ( & V_5 -> V_2 -> V_10 , V_76 -> V_26 , V_230 , V_294 ) ;
F_110 ( & V_23 -> V_91 ) ;
V_76 -> V_27 = V_230 ;
V_76 -> V_106 = V_296 ;
V_83 = V_76 -> V_76 ;
V_83 -> type = 0x27 ;
V_83 -> V_153 = 1 << 7 ;
if ( V_294 == V_269 )
V_83 -> V_76 = V_297 ;
else
V_83 -> V_76 = V_104 ;
V_83 -> V_195 = V_187 & 0xFF ;
V_83 -> V_196 = ( V_187 >> 8 ) & 0xFF ;
V_83 -> V_200 = ( V_187 >> 16 ) & 0xFF ;
V_83 -> V_280 = ( V_187 >> 24 ) & 0xFF ;
V_83 -> V_282 = ( V_187 >> 32 ) & 0xFF ;
V_83 -> V_283 = ( V_187 >> 40 ) & 0xFF ;
V_83 -> V_197 = 1 << 6 ;
V_83 -> V_139 = V_262 & 0xFF ;
V_83 -> V_284 = ( V_262 >> 8 ) & 0xFF ;
V_83 -> V_193 = ( ( V_14 -> V_17 << 3 ) | ( V_14 -> V_17 >> 5 ) ) ;
V_83 -> V_194 = 0 ;
V_83 -> V_286 = 0 ;
V_83 -> V_298 = 0 ;
V_83 -> V_299 = 0 ;
F_92 ( V_5 , V_76 , V_230 ) ;
if ( F_16 ( V_76 -> V_29 ) )
V_83 -> V_197 |= 1 << 7 ;
V_76 -> V_162 -> V_153 =
V_163 F_70 (
( V_230 << 16 ) | 5 | V_300 ) ;
V_76 -> V_162 -> V_168 = 0 ;
V_76 -> V_79 = V_5 ;
V_76 -> V_95 = F_15 ;
V_76 -> V_28 = V_294 ;
if ( F_16 ( V_23 -> V_91 & V_301 ) ) {
F_4 ( V_14 -> V_17 , V_23 -> V_302 ) ;
F_4 ( V_147 , & V_23 -> V_91 ) ;
return;
}
F_27 ( V_23 , V_14 -> V_17 ) ;
}
static T_11 F_111 ( struct V_197 * V_10 ,
struct V_303 * V_304 ,
char * V_86 )
{
struct V_4 * V_5 = F_112 ( V_10 ) -> V_305 ;
int V_306 = 0 ;
if ( F_25 ( V_101 , & V_5 -> V_38 ) )
V_306 += sprintf ( V_86 , L_74 , L_75 ) ;
else if ( F_25 ( V_100 , & V_5 -> V_38 ) )
V_306 += sprintf ( V_86 , L_74 , L_76 ) ;
else
V_306 += sprintf ( V_86 , L_74 , L_77 ) ;
return V_306 ;
}
static T_11 F_113 ( struct V_307 * V_308 , char * V_86 )
{
int V_306 = 0 ;
struct V_4 * V_5 , * V_44 ;
unsigned long V_91 ;
char V_309 [ 42 ] ;
T_1 V_24 = 0 ;
F_114 ( & V_310 , V_91 ) ;
V_306 += sprintf ( & V_86 [ V_306 ] , L_78 ) ;
F_115 (dd, tmp, &online_list, online_list) {
if ( V_5 -> V_2 ) {
if ( V_5 -> V_23 &&
V_5 -> V_23 -> V_176 &&
V_5 -> V_23 -> V_181 ) {
F_91 ( V_309 ,
( char * ) ( V_5 -> V_23 -> V_176 + 10 ) , 21 ) ;
V_24 = * ( V_5 -> V_23 -> V_176 + 141 ) ;
} else {
memset ( V_309 , 0 , 42 ) ;
V_24 = 0 ;
}
if ( V_5 -> V_23 &&
F_25 ( V_311 , & V_5 -> V_23 -> V_91 ) ) {
V_306 += sprintf ( & V_86 [ V_306 ] ,
L_79 ,
F_116 ( & V_5 -> V_2 -> V_10 ) ,
V_309 ,
V_24 ) ;
} else {
V_306 += sprintf ( & V_86 [ V_306 ] ,
L_80 ,
F_116 ( & V_5 -> V_2 -> V_10 ) ,
V_309 ) ;
}
}
}
V_306 += sprintf ( & V_86 [ V_306 ] , L_81 ) ;
F_115 (dd, tmp, &removing_list, remove_list) {
if ( V_5 -> V_2 ) {
if ( V_5 -> V_23 &&
V_5 -> V_23 -> V_176 &&
V_5 -> V_23 -> V_181 ) {
F_91 ( V_309 ,
( char * ) ( V_5 -> V_23 -> V_176 + 10 ) , 21 ) ;
V_24 = * ( V_5 -> V_23 -> V_176 + 141 ) ;
} else {
memset ( V_309 , 0 , 42 ) ;
V_24 = 0 ;
}
if ( V_5 -> V_23 &&
F_25 ( V_311 , & V_5 -> V_23 -> V_91 ) ) {
V_306 += sprintf ( & V_86 [ V_306 ] ,
L_79 ,
F_116 ( & V_5 -> V_2 -> V_10 ) ,
V_309 ,
V_24 ) ;
} else {
V_306 += sprintf ( & V_86 [ V_306 ] ,
L_80 ,
F_116 ( & V_5 -> V_2 -> V_10 ) ,
V_309 ) ;
}
}
}
F_117 ( & V_310 , V_91 ) ;
return V_306 ;
}
static T_11 F_118 ( struct V_312 * V_313 , char T_7 * V_314 ,
T_12 V_174 , T_13 * V_315 )
{
struct V_4 * V_5 = (struct V_4 * ) V_313 -> V_305 ;
int V_306 = * V_315 ;
char * V_86 ;
int V_67 = 0 ;
if ( ! V_174 || * V_315 )
return 0 ;
V_86 = F_99 ( V_316 , V_159 ) ;
if ( ! V_86 ) {
F_38 ( & V_5 -> V_2 -> V_10 ,
L_82 ) ;
return - V_219 ;
}
V_306 += F_113 ( NULL , V_86 ) ;
* V_315 = V_306 <= V_174 ? V_306 : V_174 ;
V_306 = F_79 ( V_314 , V_86 , * V_315 ) ;
if ( V_306 )
V_67 = - V_68 ;
F_103 ( V_86 ) ;
return V_67 ? V_67 : * V_315 ;
}
static T_11 F_119 ( struct V_312 * V_313 , char T_7 * V_314 ,
T_12 V_174 , T_13 * V_315 )
{
struct V_4 * V_5 = (struct V_4 * ) V_313 -> V_305 ;
char * V_86 ;
T_2 V_317 ;
int V_306 = * V_315 ;
int V_144 , V_67 = 0 ;
if ( ! V_174 || V_306 )
return 0 ;
V_86 = F_99 ( V_316 , V_159 ) ;
if ( ! V_86 ) {
F_38 ( & V_5 -> V_2 -> V_10 ,
L_83 ) ;
return - V_219 ;
}
V_306 += sprintf ( & V_86 [ V_306 ] , L_84 ) ;
for ( V_144 = V_5 -> V_59 - 1 ; V_144 >= 0 ; V_144 -- )
V_306 += sprintf ( & V_86 [ V_306 ] , L_85 ,
F_22 ( V_5 -> V_23 -> V_41 [ V_144 ] ) ) ;
V_306 += sprintf ( & V_86 [ V_306 ] , L_86 ) ;
V_306 += sprintf ( & V_86 [ V_306 ] , L_87 ) ;
for ( V_144 = V_5 -> V_59 - 1 ; V_144 >= 0 ; V_144 -- )
V_306 += sprintf ( & V_86 [ V_306 ] , L_85 ,
F_22 ( V_5 -> V_23 -> V_42 [ V_144 ] ) ) ;
V_306 += sprintf ( & V_86 [ V_306 ] , L_86 ) ;
V_306 += sprintf ( & V_86 [ V_306 ] , L_88 ) ;
for ( V_144 = V_5 -> V_59 - 1 ; V_144 >= 0 ; V_144 -- )
V_306 += sprintf ( & V_86 [ V_306 ] , L_85 ,
F_22 ( V_5 -> V_23 -> V_60 [ V_144 ] ) ) ;
V_306 += sprintf ( & V_86 [ V_306 ] , L_86 ) ;
V_306 += sprintf ( & V_86 [ V_306 ] , L_89 ,
F_22 ( V_5 -> V_23 -> V_34 + V_61 ) ) ;
V_306 += sprintf ( & V_86 [ V_306 ] , L_90 ,
F_22 ( V_5 -> V_34 + V_62 ) ) ;
V_306 += sprintf ( & V_86 [ V_306 ] , L_91 ) ;
V_306 += sprintf ( & V_86 [ V_306 ] , L_92 ) ;
for ( V_144 = V_5 -> V_59 - 1 ; V_144 >= 0 ; V_144 -- ) {
if ( sizeof( long ) > sizeof( T_2 ) )
V_317 =
V_5 -> V_23 -> V_302 [ V_144 / 2 ] >> ( 32 * ( V_144 & 1 ) ) ;
else
V_317 = V_5 -> V_23 -> V_302 [ V_144 ] ;
V_306 += sprintf ( & V_86 [ V_306 ] , L_85 , V_317 ) ;
}
V_306 += sprintf ( & V_86 [ V_306 ] , L_86 ) ;
* V_315 = V_306 <= V_174 ? V_306 : V_174 ;
V_306 = F_79 ( V_314 , V_86 , * V_315 ) ;
if ( V_306 )
V_67 = - V_68 ;
F_103 ( V_86 ) ;
return V_67 ? V_67 : * V_315 ;
}
static T_11 F_120 ( struct V_312 * V_313 , char T_7 * V_314 ,
T_12 V_174 , T_13 * V_315 )
{
struct V_4 * V_5 = (struct V_4 * ) V_313 -> V_305 ;
char * V_86 ;
int V_306 = * V_315 ;
int V_67 = 0 ;
if ( ! V_174 || V_306 )
return 0 ;
V_86 = F_99 ( V_316 , V_159 ) ;
if ( ! V_86 ) {
F_38 ( & V_5 -> V_2 -> V_10 ,
L_93 ) ;
return - V_219 ;
}
V_306 += sprintf ( & V_86 [ V_306 ] , L_94 ,
V_5 -> V_23 -> V_91 ) ;
V_306 += sprintf ( & V_86 [ V_306 ] , L_95 ,
V_5 -> V_38 ) ;
* V_315 = V_306 <= V_174 ? V_306 : V_174 ;
V_306 = F_79 ( V_314 , V_86 , * V_315 ) ;
if ( V_306 )
V_67 = - V_68 ;
F_103 ( V_86 ) ;
return V_67 ? V_67 : * V_315 ;
}
static int F_121 ( struct V_4 * V_5 , struct V_318 * V_319 )
{
if ( ! V_319 || ! V_5 )
return - V_205 ;
if ( F_122 ( V_319 , & V_320 . V_304 ) )
F_5 ( & V_5 -> V_2 -> V_10 ,
L_96 ) ;
return 0 ;
}
static int F_123 ( struct V_4 * V_5 , struct V_318 * V_319 )
{
if ( ! V_319 || ! V_5 )
return - V_205 ;
F_124 ( V_319 , & V_320 . V_304 ) ;
return 0 ;
}
static int F_125 ( struct V_4 * V_5 )
{
if ( ! V_321 )
return - 1 ;
V_5 -> V_322 = F_126 ( V_5 -> V_323 -> V_324 , V_321 ) ;
if ( F_127 ( V_5 -> V_322 ) ) {
F_5 ( & V_5 -> V_2 -> V_10 ,
L_97 ,
V_5 -> V_323 -> V_324 ) ;
V_5 -> V_322 = NULL ;
return - 1 ;
}
F_128 ( L_98 , V_325 , V_5 -> V_322 , V_5 ,
& V_326 ) ;
F_128 ( L_99 , V_325 , V_5 -> V_322 , V_5 ,
& V_327 ) ;
return 0 ;
}
static void F_129 ( struct V_4 * V_5 )
{
if ( V_5 -> V_322 )
F_130 ( V_5 -> V_322 ) ;
}
static inline void F_131 ( struct V_4 * V_5 )
{
T_2 V_328 ;
V_328 = F_22 ( V_5 -> V_34 + V_329 ) ;
F_21 ( V_328 |
V_330 |
V_331 ,
V_5 -> V_34 + V_329 ) ;
}
static int F_132 ( struct V_4 * V_5 )
{
return ( V_5 -> V_2 -> V_197 == V_332 ? 1 : 0 ) ;
}
static void F_133 ( struct V_4 * V_5 )
{
T_2 V_328 ;
unsigned int V_333 , V_334 ;
V_328 = F_22 ( V_5 -> V_34 + V_329 ) ;
V_5 -> V_335 = V_336 ;
V_5 -> V_59 = 1 ;
if ( V_328 & 0x8 ) {
V_5 -> V_335 = V_337 ;
V_333 = ( V_328 & V_338 ) >> 8 ;
V_334 = ( V_328 & V_339 ) + 1 ;
F_48 ( & V_5 -> V_2 -> V_10 ,
L_100
L_101 ,
V_333 ,
V_334 ,
V_334 * 32 ) ;
if ( V_334 > V_123 ) {
F_5 ( & V_5 -> V_2 -> V_10 ,
L_102
L_103 , V_123 ) ;
V_334 = V_123 ;
}
V_5 -> V_59 = V_334 ;
return;
}
F_5 ( & V_5 -> V_2 -> V_10 , L_104 ) ;
}
static int F_134 ( struct V_4 * V_5 )
{
unsigned long V_32 , V_72 = 0 , V_187 ;
F_5 ( & V_5 -> V_2 -> V_10 ,
L_105 ) ;
V_187 = V_36 ;
V_32 = V_36 + F_23 ( V_340 ) ;
do {
if ( F_16 ( F_25 ( V_37 ,
& V_5 -> V_38 ) ) )
return - V_68 ;
if ( F_1 ( V_5 -> V_2 ) )
return - V_68 ;
if ( F_75 ( V_5 -> V_23 , NULL ) < 0 )
return - V_68 ;
if ( * ( V_5 -> V_23 -> V_176 + V_341 ) ==
V_342 ) {
F_135 ( 1 ) ;
if ( V_72 ++ >= 180 ) {
F_5 ( & V_5 -> V_2 -> V_10 ,
L_106 ,
F_81 ( V_36 - V_187 ) / 1000 ) ;
V_72 = 0 ;
}
} else {
F_5 ( & V_5 -> V_2 -> V_10 ,
L_107 ,
F_81 ( V_36 - V_187 ) / 1000 ) ;
F_136 ( V_5 ) ;
return 0 ;
}
} while ( F_26 ( V_36 , V_32 ) );
F_38 ( & V_5 -> V_2 -> V_10 ,
L_108 ,
F_81 ( V_36 - V_187 ) / 1000 ) ;
return - V_68 ;
}
static int F_137 ( void * V_114 )
{
struct V_4 * V_5 = (struct V_4 * ) V_114 ;
unsigned long V_343 , V_344 , V_345 ;
unsigned int V_346 = V_5 -> V_59 * 32 ;
struct V_22 * V_23 = V_5 -> V_23 ;
while ( 1 ) {
if ( F_138 () ||
F_25 ( V_347 , & V_23 -> V_91 ) )
goto V_348;
F_49 ( V_146 , & V_23 -> V_91 ) ;
F_139 ( V_23 -> V_107 , ( V_23 -> V_91 ) &&
! ( V_23 -> V_91 & V_301 ) ) ;
F_4 ( V_146 , & V_23 -> V_91 ) ;
if ( F_138 () ||
F_25 ( V_347 , & V_23 -> V_91 ) )
goto V_348;
if ( F_16 ( F_25 ( V_37 ,
& V_5 -> V_38 ) ) )
goto V_348;
V_349:
if ( F_25 ( V_90 , & V_23 -> V_91 ) ) {
F_44 ( V_5 ) ;
F_49 ( V_90 , & V_23 -> V_91 ) ;
}
if ( F_25 ( V_90 , & V_23 -> V_91 ) )
goto V_349;
if ( F_25 ( V_147 , & V_23 -> V_91 ) ) {
V_343 = 1 ;
V_344 = V_346 ;
V_345 = 0 ;
while ( 1 ) {
V_343 = F_140 ( V_23 -> V_302 ,
V_346 , V_343 ) ;
if ( V_345 == 1 ) {
if ( ( V_344 >= V_343 ) ||
( V_343 >= V_346 ) )
break;
}
if ( F_16 ( V_344 == V_346 ) )
V_344 = V_343 ;
if ( F_16 ( V_343 == V_346 ) ) {
V_343 = 1 ;
V_345 = 1 ;
continue;
}
F_27 ( V_23 , V_343 ) ;
F_49 ( V_343 , V_23 -> V_302 ) ;
}
F_49 ( V_147 , & V_23 -> V_91 ) ;
}
if ( F_25 ( V_311 , & V_23 -> V_91 ) ) {
if ( F_134 ( V_5 ) < 0 )
F_4 ( V_350 ,
& V_5 -> V_38 ) ;
F_49 ( V_311 , & V_23 -> V_91 ) ;
}
}
V_348:
return 0 ;
}
static void F_141 ( struct V_4 * V_5 )
{
struct V_22 * V_23 = V_5 -> V_23 ;
if ( V_23 -> V_351 )
F_88 ( & V_5 -> V_2 -> V_10 , V_352 ,
V_23 -> V_351 , V_23 -> V_353 ) ;
if ( V_23 -> V_354 ) {
F_88 ( & V_5 -> V_2 -> V_10 , V_355 ,
V_23 -> V_354 , V_23 -> V_52 ) ;
}
}
static int F_142 ( struct V_4 * V_5 )
{
struct V_22 * V_23 = V_5 -> V_23 ;
V_23 -> V_351 =
F_86 ( & V_5 -> V_2 -> V_10 , V_352 ,
& V_23 -> V_353 , V_159 ) ;
if ( ! V_23 -> V_351 )
return - V_219 ;
memset ( V_23 -> V_351 , 0 , V_352 ) ;
V_23 -> V_354 =
F_86 ( & V_5 -> V_2 -> V_10 , V_355 ,
& V_23 -> V_52 , V_159 ) ;
if ( ! V_23 -> V_354 ) {
F_88 ( & V_5 -> V_2 -> V_10 , V_352 ,
V_23 -> V_351 , V_23 -> V_353 ) ;
V_23 -> V_351 = NULL ;
V_23 -> V_353 = 0 ;
return - V_219 ;
}
memset ( V_23 -> V_354 , 0 , V_355 ) ;
V_23 -> V_133 = V_23 -> V_351 + V_356 ;
V_23 -> V_54 = V_23 -> V_353 + V_356 ;
V_23 -> V_176 = V_23 -> V_351 + V_357 ;
V_23 -> V_183 = V_23 -> V_353 + V_357 ;
V_23 -> V_98 = V_23 -> V_351 + V_358 ;
V_23 -> V_99 = V_23 -> V_353 + V_358 ;
V_23 -> V_207 = V_23 -> V_351 + V_359 ;
V_23 -> V_208 = V_23 -> V_353 + V_359 ;
return 0 ;
}
static int F_143 ( struct V_4 * V_5 )
{
struct V_202 V_360 ;
unsigned char * V_86 ;
int V_67 ;
if ( F_75 ( V_5 -> V_23 , NULL ) < 0 )
return - V_68 ;
if ( * ( V_5 -> V_23 -> V_176 + V_341 ) ==
V_342 ) {
F_4 ( V_311 , & V_5 -> V_23 -> V_91 ) ;
return V_342 ;
}
F_90 ( V_5 -> V_23 ) ;
V_67 = F_47 ( V_5 -> V_23 , V_97 ,
V_5 -> V_23 -> V_98 ,
V_5 -> V_23 -> V_99 , 1 ) ;
if ( V_67 ) {
F_5 ( & V_5 -> V_2 -> V_10 ,
L_15 ) ;
} else {
V_86 = ( unsigned char * ) V_5 -> V_23 -> V_98 ;
if ( V_86 [ 259 ] & 0x1 ) {
F_48 ( & V_5 -> V_2 -> V_10 ,
L_16 ) ;
F_4 ( V_100 , & V_5 -> V_38 ) ;
}
if ( V_86 [ 288 ] == 0xF7 ) {
F_48 ( & V_5 -> V_2 -> V_10 ,
L_18 ) ;
F_4 ( V_101 , & V_5 -> V_38 ) ;
}
if ( V_86 [ 288 ] == 0xBF ) {
F_48 ( & V_5 -> V_2 -> V_10 ,
L_109 ) ;
}
}
memset ( & V_360 , 0 , sizeof( struct V_202 ) ) ;
if ( F_83 ( V_5 -> V_23 , 242 , & V_360 ) )
F_5 ( & V_5 -> V_2 -> V_10 ,
L_110 ) ;
else
F_48 ( & V_5 -> V_2 -> V_10 ,
L_111 ,
V_360 . V_361 , F_144 ( V_360 . V_114 ) ) ;
return V_67 ;
}
static int F_145 ( struct V_4 * V_5 )
{
int V_49 ;
int V_67 ;
unsigned int V_362 ;
unsigned long V_32 , V_363 ;
V_5 -> V_34 = F_146 ( V_5 -> V_2 ) [ V_364 ] ;
F_133 ( V_5 ) ;
if ( V_5 -> V_335 == V_336 ) {
V_67 = - V_31 ;
goto V_365;
}
V_362 = V_5 -> V_59 * 32 ;
F_131 ( V_5 ) ;
V_5 -> V_23 = F_147 ( sizeof( struct V_22 ) , V_159 ,
V_5 -> V_366 ) ;
if ( ! V_5 -> V_23 ) {
F_38 ( & V_5 -> V_2 -> V_10 ,
L_112 ) ;
return - V_219 ;
}
for ( V_49 = 0 ; V_49 < V_123 ; V_49 ++ )
V_5 -> V_124 [ V_49 ] . V_23 = V_5 -> V_23 ;
if ( F_132 ( V_5 ) )
V_5 -> V_367 = V_368 ;
else
V_5 -> V_367 = 0 ;
F_148 ( & V_5 -> V_23 -> V_30 , V_5 -> V_367 ) ;
for ( V_49 = 0 ; V_49 < V_123 ; V_49 ++ )
F_149 ( & V_5 -> V_23 -> V_40 [ V_49 ] ) ;
V_5 -> V_23 -> V_34 = V_5 -> V_34 + V_369 ;
V_5 -> V_23 -> V_5 = V_5 ;
V_67 = F_142 ( V_5 ) ;
if ( V_67 < 0 )
goto V_365;
for ( V_49 = 0 ; V_49 < V_5 -> V_59 ; V_49 ++ ) {
V_5 -> V_23 -> V_41 [ V_49 ] =
V_5 -> V_23 -> V_34 + V_49 * 0x80 + V_370 ;
V_5 -> V_23 -> V_42 [ V_49 ] =
V_5 -> V_23 -> V_34 + V_49 * 0x80 + V_371 ;
V_5 -> V_23 -> V_60 [ V_49 ] =
V_5 -> V_23 -> V_34 + V_49 * 0x80 + V_372 ;
}
V_363 = V_36 ;
V_32 = V_36 + F_23 ( 30000 ) ;
while ( ( ( F_22 ( V_5 -> V_23 -> V_34 + V_66 ) & 0x0F ) != 0x03 ) &&
F_26 ( V_36 , V_32 ) ) {
F_24 ( 100 ) ;
}
if ( F_16 ( F_1 ( V_5 -> V_2 ) ) ) {
V_363 = V_36 - V_363 ;
F_5 ( & V_5 -> V_2 -> V_10 ,
L_113 ,
F_81 ( V_363 ) ) ;
V_67 = - V_373 ;
goto V_374 ;
}
if ( F_16 ( F_25 ( V_37 , & V_5 -> V_38 ) ) ) {
V_363 = V_36 - V_363 ;
F_5 ( & V_5 -> V_2 -> V_10 ,
L_114 ,
F_81 ( V_363 ) ) ;
V_67 = - V_68 ;
goto V_374;
}
if ( ! ( F_22 ( V_5 -> V_34 + V_50 ) & V_375 ) ) {
if ( F_20 ( V_5 ) < 0 ) {
F_38 ( & V_5 -> V_2 -> V_10 ,
L_115 ) ;
V_67 = - V_31 ;
goto V_374;
}
} else {
F_21 ( F_22 ( V_5 -> V_34 + V_62 ) ,
V_5 -> V_34 + V_62 ) ;
}
F_36 ( V_5 -> V_23 ) ;
F_34 ( V_5 -> V_23 ) ;
V_67 = F_150 ( & V_5 -> V_2 -> V_10 ,
V_5 -> V_2 -> V_129 ,
F_61 ,
V_376 ,
F_151 ( & V_5 -> V_2 -> V_10 ) ,
V_5 ) ;
if ( V_67 ) {
F_38 ( & V_5 -> V_2 -> V_10 ,
L_116 , V_5 -> V_2 -> V_129 ) ;
goto V_374;
}
F_152 ( V_5 -> V_2 -> V_129 , F_153 ( V_5 -> V_377 ) ) ;
F_21 ( F_22 ( V_5 -> V_34 + V_35 ) | V_69 ,
V_5 -> V_34 + V_35 ) ;
F_154 ( & V_5 -> V_23 -> V_107 ) ;
if ( F_25 ( V_37 , & V_5 -> V_38 ) ) {
V_67 = - V_68 ;
goto V_378;
}
return V_67 ;
V_378:
F_21 ( F_22 ( V_5 -> V_34 + V_35 ) & ~ V_69 ,
V_5 -> V_34 + V_35 ) ;
F_152 ( V_5 -> V_2 -> V_129 , NULL ) ;
F_155 ( & V_5 -> V_2 -> V_10 , V_5 -> V_2 -> V_129 , V_5 ) ;
V_374:
F_35 ( V_5 -> V_23 ) ;
F_141 ( V_5 ) ;
V_365:
F_103 ( V_5 -> V_23 ) ;
return V_67 ;
}
static void F_156 ( struct V_4 * V_5 )
{
if ( V_5 -> V_6 )
return;
if ( ! F_25 ( V_311 , & V_5 -> V_23 -> V_91 ) &&
! F_25 ( V_102 , & V_5 -> V_38 ) )
if ( F_80 ( V_5 -> V_23 ) )
F_5 ( & V_5 -> V_2 -> V_10 ,
L_117 ) ;
}
static int F_157 ( struct V_4 * V_5 )
{
if ( ! V_5 -> V_6 ) {
F_35 ( V_5 -> V_23 ) ;
F_21 ( F_22 ( V_5 -> V_34 + V_35 ) & ~ V_69 ,
V_5 -> V_34 + V_35 ) ;
}
F_152 ( V_5 -> V_2 -> V_129 , NULL ) ;
F_155 ( & V_5 -> V_2 -> V_10 , V_5 -> V_2 -> V_129 , V_5 ) ;
F_66 ( 1000 ) ;
F_141 ( V_5 ) ;
F_103 ( V_5 -> V_23 ) ;
V_5 -> V_23 = NULL ;
return 0 ;
}
static int F_158 ( struct V_4 * V_5 )
{
if ( ! V_5 -> V_6 && V_5 -> V_23 )
F_80 ( V_5 -> V_23 ) ;
return 0 ;
}
static int F_159 ( struct V_4 * V_5 )
{
if ( F_80 ( V_5 -> V_23 ) != 0 ) {
F_38 ( & V_5 -> V_2 -> V_10 ,
L_118 ) ;
return - V_68 ;
}
F_21 ( F_22 ( V_5 -> V_34 + V_35 ) & ~ V_69 ,
V_5 -> V_34 + V_35 ) ;
F_35 ( V_5 -> V_23 ) ;
return 0 ;
}
static int F_160 ( struct V_4 * V_5 )
{
F_131 ( V_5 ) ;
if ( F_20 ( V_5 ) != 0 ) {
F_38 ( & V_5 -> V_2 -> V_10 ,
L_119 ) ;
return - V_68 ;
}
F_36 ( V_5 -> V_23 ) ;
F_34 ( V_5 -> V_23 ) ;
F_21 ( F_22 ( V_5 -> V_34 + V_35 ) | V_69 ,
V_5 -> V_34 + V_35 ) ;
return 0 ;
}
static int F_161 ( char * V_379 ,
int V_380 ,
char * V_86 ,
int V_381 )
{
const int V_382 = 'z' - 'a' + 1 ;
char * V_383 = V_86 + strlen ( V_379 ) ;
char * V_384 = V_86 + V_381 ;
char * V_385 ;
int V_386 ;
V_385 = V_384 - 1 ;
* V_385 = '\0' ;
V_386 = V_382 ;
do {
if ( V_385 == V_383 )
return - V_205 ;
* -- V_385 = 'a' + ( V_380 % V_386 ) ;
V_380 = ( V_380 / V_386 ) - 1 ;
} while ( V_380 >= 0 );
memmove ( V_383 , V_385 , V_384 - V_385 ) ;
memcpy ( V_86 , V_379 , strlen ( V_379 ) ) ;
return 0 ;
}
static int F_162 ( struct V_387 * V_10 ,
T_14 V_388 ,
unsigned V_16 ,
unsigned long V_287 )
{
struct V_4 * V_5 = V_10 -> V_389 -> V_305 ;
if ( ! F_163 ( V_390 ) )
return - V_391 ;
if ( ! V_5 )
return - V_392 ;
if ( F_16 ( F_25 ( V_37 , & V_5 -> V_38 ) ) )
return - V_392 ;
switch ( V_16 ) {
case V_393 :
return - V_392 ;
default:
return F_104 ( V_5 , V_16 , V_287 ) ;
}
}
static int F_164 ( struct V_387 * V_10 ,
T_14 V_388 ,
unsigned V_16 ,
unsigned long V_287 )
{
struct V_4 * V_5 = V_10 -> V_389 -> V_305 ;
if ( ! F_163 ( V_390 ) )
return - V_391 ;
if ( ! V_5 )
return - V_392 ;
if ( F_16 ( F_25 ( V_37 , & V_5 -> V_38 ) ) )
return - V_392 ;
switch ( V_16 ) {
case V_393 :
return - V_392 ;
case V_292 : {
struct V_394 T_7 * V_395 ;
T_10 V_252 ;
int V_396 , V_253 , V_293 ;
V_396 =
sizeof( struct V_394 ) ;
V_395 =
(struct V_394 T_7 * ) V_287 ;
if ( F_100 ( & V_252 , ( void T_7 * ) V_287 ,
V_396 - ( 2 * sizeof( V_397 ) ) ) )
return - V_68 ;
if ( F_165 ( V_252 . V_266 , & V_395 -> V_266 ) )
return - V_68 ;
if ( F_165 ( V_252 . V_267 , & V_395 -> V_267 ) )
return - V_68 ;
V_253 = sizeof( struct V_394 ) ;
V_293 = F_98 ( V_5 , ( void T_7 * ) V_287 ,
& V_252 , V_253 ) ;
if ( F_79 ( ( void T_7 * ) V_287 , & V_252 ,
V_396 -
( 2 * sizeof( V_397 ) ) ) )
return - V_68 ;
if ( F_166 ( V_252 . V_266 , & V_395 -> V_266 ) )
return - V_68 ;
if ( F_166 ( V_252 . V_267 , & V_395 -> V_267 ) )
return - V_68 ;
return V_293 ;
}
default:
return F_104 ( V_5 , V_16 , V_287 ) ;
}
}
static int F_167 ( struct V_387 * V_10 ,
struct V_398 * V_399 )
{
struct V_4 * V_5 = V_10 -> V_389 -> V_305 ;
T_9 V_400 ;
if ( ! V_5 )
return - V_392 ;
if ( ! ( F_89 ( V_5 , & V_400 ) ) ) {
F_5 ( & V_5 -> V_2 -> V_10 ,
L_120 ) ;
return - V_392 ;
}
V_399 -> V_401 = 224 ;
V_399 -> V_191 = 56 ;
F_168 ( V_400 , ( V_399 -> V_401 * V_399 -> V_191 ) ) ;
V_399 -> V_402 = V_400 ;
return 0 ;
}
static inline bool F_169 ( struct V_4 * V_5 )
{
if ( F_16 ( F_25 ( V_142 , & V_5 -> V_23 -> V_91 ) ) ) {
if ( V_5 -> V_23 -> V_137 ) {
unsigned long V_143 = V_5 -> V_23 -> V_137 +
F_23 ( 1000 ) ;
if ( F_170 ( V_36 , V_143 ) ) {
F_49 ( V_142 ,
& V_5 -> V_23 -> V_91 ) ;
F_49 ( V_102 , & V_5 -> V_38 ) ;
V_5 -> V_23 -> V_137 = 0 ;
F_50 ( & V_5 -> V_23 -> V_107 ) ;
return false ;
}
}
return true ;
}
return false ;
}
static int F_171 ( struct V_18 * V_19 , struct V_13 * V_14 )
{
struct V_4 * V_5 = V_19 -> V_7 -> V_403 ;
struct V_12 * V_16 = F_8 ( V_14 ) ;
unsigned int V_230 ;
if ( F_169 ( V_5 ) )
return - V_105 ;
if ( F_16 ( V_5 -> V_38 & V_404 ) ) {
if ( F_16 ( F_25 ( V_37 ,
& V_5 -> V_38 ) ) ) {
return - V_172 ;
}
if ( F_16 ( F_25 ( V_101 , & V_5 -> V_38 ) ) ) {
return - V_105 ;
}
if ( F_16 ( F_25 ( V_100 ,
& V_5 -> V_38 ) &&
F_106 ( V_14 ) ) ) {
return - V_105 ;
}
if ( F_16 ( F_25 ( V_102 , & V_5 -> V_38 ) ) )
return - V_105 ;
if ( F_25 ( V_350 , & V_5 -> V_38 ) )
return - V_172 ;
}
if ( V_14 -> V_405 & V_406 ) {
int V_259 ;
V_259 = F_84 ( V_5 , F_107 ( V_14 ) , F_108 ( V_14 ) ) ;
F_19 ( V_14 , V_259 ) ;
return 0 ;
}
V_230 = F_172 ( V_19 -> V_7 , V_14 , V_16 -> V_26 ) ;
F_105 ( V_5 , V_14 , V_16 , V_230 , V_19 ) ;
return 0 ;
}
static bool F_173 ( struct V_18 * V_19 ,
struct V_13 * V_14 )
{
struct V_4 * V_5 = V_19 -> V_7 -> V_403 ;
struct V_12 * V_16 = F_8 ( V_14 ) ;
if ( F_106 ( V_14 ) == V_295 || ! V_5 -> V_367 )
return false ;
if ( F_108 ( V_14 ) <= 64 ) {
if ( ( F_107 ( V_14 ) & 7 ) || ( F_108 ( V_14 ) & 7 ) )
V_16 -> V_29 = 1 ;
}
if ( V_16 -> V_29 && F_174 ( & V_5 -> V_23 -> V_30 ) )
return true ;
return false ;
}
static int F_175 ( struct V_18 * V_19 ,
const struct V_407 * V_408 )
{
struct V_13 * V_14 = V_408 -> V_14 ;
int V_293 ;
if ( F_16 ( F_173 ( V_19 , V_14 ) ) )
return V_409 ;
F_176 ( V_14 ) ;
V_293 = F_171 ( V_19 , V_14 ) ;
if ( F_46 ( ! V_293 ) )
return V_410 ;
V_14 -> V_411 = V_293 ;
return V_412 ;
}
static void F_177 ( void * V_114 , struct V_13 * V_14 ,
unsigned int V_413 , unsigned int V_414 )
{
struct V_4 * V_5 = V_114 ;
struct V_12 * V_16 = F_8 ( V_14 ) ;
if ( ! V_16 -> V_76 )
return;
F_88 ( & V_5 -> V_2 -> V_10 , V_415 ,
V_16 -> V_76 , V_16 -> V_416 ) ;
}
static int F_178 ( void * V_114 , struct V_13 * V_14 , unsigned int V_413 ,
unsigned int V_414 , unsigned int V_366 )
{
struct V_4 * V_5 = V_114 ;
struct V_12 * V_16 = F_8 ( V_14 ) ;
T_2 V_417 = F_22 ( V_5 -> V_34 + V_50 ) & V_51 ;
if ( V_414 >= V_418 )
return 0 ;
V_16 -> V_76 = F_86 ( & V_5 -> V_2 -> V_10 , V_415 ,
& V_16 -> V_416 , V_159 ) ;
if ( ! V_16 -> V_76 )
return - V_219 ;
memset ( V_16 -> V_76 , 0 , V_415 ) ;
V_16 -> V_162 = V_5 -> V_23 -> V_354 +
( sizeof( struct V_419 ) * V_414 ) ;
V_16 -> V_420 = V_5 -> V_23 -> V_52 +
( sizeof( struct V_419 ) * V_414 ) ;
if ( V_417 )
V_16 -> V_162 -> V_421 = V_163 F_70 ( ( V_16 -> V_416 >> 16 ) >> 16 ) ;
V_16 -> V_162 -> V_422 = V_163 F_70 ( V_16 -> V_416 & 0xFFFFFFFF ) ;
F_179 ( V_16 -> V_26 , V_423 ) ;
return 0 ;
}
static int F_136 ( struct V_4 * V_5 )
{
int V_67 = 0 , V_424 = 0 ;
T_9 V_400 ;
unsigned int V_380 = 0 ;
struct V_318 * V_319 ;
if ( V_5 -> V_323 )
goto V_425;
if ( F_145 ( V_5 ) ) {
V_67 = - V_205 ;
goto V_426;
}
V_5 -> V_323 = F_180 ( V_427 , V_5 -> V_366 ) ;
if ( V_5 -> V_323 == NULL ) {
F_38 ( & V_5 -> V_2 -> V_10 ,
L_121 ) ;
V_67 = - V_205 ;
goto V_428;
}
do {
if ( ! F_181 ( & V_429 , V_159 ) )
goto V_430;
F_28 ( & V_431 ) ;
V_67 = F_182 ( & V_429 , & V_380 ) ;
F_31 ( & V_431 ) ;
} while ( V_67 == - V_173 );
if ( V_67 )
goto V_430;
V_67 = F_161 ( L_122 ,
V_380 ,
V_5 -> V_323 -> V_324 ,
V_432 ) ;
if ( V_67 )
goto V_433;
V_5 -> V_323 -> V_434 = & V_5 -> V_2 -> V_10 ;
V_5 -> V_323 -> V_435 = V_5 -> V_435 ;
V_5 -> V_323 -> V_436 = V_380 * V_427 ;
V_5 -> V_323 -> V_437 = V_427 ;
V_5 -> V_323 -> V_438 = & V_439 ;
V_5 -> V_323 -> V_305 = V_5 ;
V_5 -> V_380 = V_380 ;
F_125 ( V_5 ) ;
V_425:
memset ( & V_5 -> V_21 , 0 , sizeof( V_5 -> V_21 ) ) ;
V_5 -> V_21 . V_440 = & V_441 ;
V_5 -> V_21 . V_442 = 1 ;
V_5 -> V_21 . V_443 = V_418 ;
V_5 -> V_21 . V_444 = 1 ;
V_5 -> V_21 . V_445 = sizeof( struct V_12 ) ;
V_5 -> V_21 . V_366 = V_5 -> V_366 ;
V_5 -> V_21 . V_91 = V_446 ;
V_5 -> V_21 . V_4 = V_5 ;
V_67 = F_183 ( & V_5 -> V_21 ) ;
if ( V_67 ) {
F_38 ( & V_5 -> V_2 -> V_10 ,
L_123 ) ;
goto V_447;
}
V_5 -> V_7 = F_184 ( & V_5 -> V_21 ) ;
if ( F_185 ( V_5 -> V_7 ) ) {
F_38 ( & V_5 -> V_2 -> V_10 ,
L_123 ) ;
V_67 = - V_219 ;
goto V_447;
}
V_5 -> V_323 -> V_7 = V_5 -> V_7 ;
V_5 -> V_7 -> V_403 = V_5 ;
V_424 = F_143 ( V_5 ) ;
if ( V_424 < 0 ) {
F_38 ( & V_5 -> V_2 -> V_10 ,
L_124 ) ;
V_67 = - V_205 ;
goto V_448;
}
if ( V_424 == V_342 )
goto V_449;
F_4 ( V_450 , & V_5 -> V_7 -> V_9 ) ;
F_49 ( V_451 , & V_5 -> V_7 -> V_9 ) ;
F_186 ( V_5 -> V_7 , V_423 ) ;
F_187 ( V_5 -> V_7 , 4096 ) ;
F_188 ( V_5 -> V_7 , 0xffff ) ;
F_189 ( V_5 -> V_7 , 0x400000 ) ;
F_190 ( V_5 -> V_7 , 4096 ) ;
F_191 ( V_5 -> V_7 , V_5 -> V_2 -> V_452 ) ;
F_192 ( V_5 -> V_7 , 0 ) ;
if ( V_5 -> V_186 == true ) {
F_4 ( V_453 , & V_5 -> V_7 -> V_9 ) ;
V_5 -> V_7 -> V_454 . V_455 = 4096 ;
F_193 ( V_5 -> V_7 ,
V_216 * V_217 ) ;
V_5 -> V_7 -> V_454 . V_456 = 0 ;
}
if ( ! ( F_89 ( V_5 , & V_400 ) ) ) {
F_5 ( & V_5 -> V_2 -> V_10 ,
L_125 ) ;
V_67 = - V_31 ;
goto V_457;
}
F_194 ( V_5 -> V_323 , V_400 ) ;
F_195 ( V_5 -> V_323 ) ;
V_5 -> V_458 = F_196 ( V_5 -> V_323 , 0 ) ;
V_319 = F_197 ( & F_198 ( V_5 -> V_323 ) -> V_319 ) ;
if ( V_319 ) {
F_121 ( V_5 , V_319 ) ;
F_199 ( V_319 ) ;
}
if ( V_5 -> V_459 ) {
F_4 ( V_460 , & V_5 -> V_38 ) ;
return V_67 ;
}
V_449:
V_5 -> V_459 = F_200 ( F_137 ,
V_5 , V_5 -> V_366 ,
L_126 , V_380 ) ;
if ( F_185 ( V_5 -> V_459 ) ) {
F_38 ( & V_5 -> V_2 -> V_10 , L_127 ) ;
V_5 -> V_459 = NULL ;
V_67 = - V_68 ;
goto V_461;
}
F_201 ( V_5 -> V_459 ) ;
if ( V_424 == V_342 )
V_67 = V_424 ;
return V_67 ;
V_461:
F_202 ( V_5 -> V_458 ) ;
V_5 -> V_458 = NULL ;
F_203 ( V_5 -> V_323 ) ;
V_457:
V_448:
F_204 ( V_5 -> V_7 ) ;
F_205 ( & V_5 -> V_21 ) ;
V_447:
F_129 ( V_5 ) ;
V_433:
F_28 ( & V_431 ) ;
F_206 ( & V_429 , V_380 ) ;
F_31 ( & V_431 ) ;
V_430:
F_207 ( V_5 -> V_323 ) ;
V_428:
F_157 ( V_5 ) ;
V_426:
return V_67 ;
}
static int F_208 ( struct V_4 * V_5 )
{
struct V_318 * V_319 ;
F_129 ( V_5 ) ;
if ( V_5 -> V_459 ) {
F_4 ( V_347 , & V_5 -> V_23 -> V_91 ) ;
F_50 ( & V_5 -> V_23 -> V_107 ) ;
F_209 ( V_5 -> V_459 ) ;
}
if ( F_25 ( V_460 , & V_5 -> V_38 ) ) {
V_319 = F_197 ( & F_198 ( V_5 -> V_323 ) -> V_319 ) ;
if ( V_319 ) {
F_123 ( V_5 , V_319 ) ;
F_199 ( V_319 ) ;
}
}
if ( ! V_5 -> V_6 )
F_156 ( V_5 ) ;
else
F_48 ( & V_5 -> V_2 -> V_10 , L_128 ,
V_5 -> V_323 -> V_324 ) ;
if ( V_5 -> V_458 ) {
F_202 ( V_5 -> V_458 ) ;
V_5 -> V_458 = NULL ;
}
if ( V_5 -> V_323 ) {
F_203 ( V_5 -> V_323 ) ;
if ( V_5 -> V_323 -> V_7 ) {
F_204 ( V_5 -> V_7 ) ;
F_205 ( & V_5 -> V_21 ) ;
V_5 -> V_7 = NULL ;
}
F_207 ( V_5 -> V_323 ) ;
}
V_5 -> V_323 = NULL ;
F_28 ( & V_431 ) ;
F_206 ( & V_429 , V_5 -> V_380 ) ;
F_31 ( & V_431 ) ;
F_157 ( V_5 ) ;
return 0 ;
}
static int F_210 ( struct V_4 * V_5 )
{
F_158 ( V_5 ) ;
if ( V_5 -> V_323 ) {
F_48 ( & V_5 -> V_2 -> V_10 ,
L_129 , V_5 -> V_323 -> V_324 ) ;
F_203 ( V_5 -> V_323 ) ;
if ( V_5 -> V_323 -> V_7 ) {
F_204 ( V_5 -> V_7 ) ;
F_205 ( & V_5 -> V_21 ) ;
}
F_207 ( V_5 -> V_323 ) ;
V_5 -> V_323 = NULL ;
V_5 -> V_7 = NULL ;
}
F_28 ( & V_431 ) ;
F_206 ( & V_429 , V_5 -> V_380 ) ;
F_31 ( & V_431 ) ;
return 0 ;
}
static int F_211 ( struct V_4 * V_5 )
{
F_48 ( & V_5 -> V_2 -> V_10 ,
L_130 , V_5 -> V_323 -> V_324 ) ;
F_159 ( V_5 ) ;
return 0 ;
}
static int F_212 ( struct V_4 * V_5 )
{
F_48 ( & V_5 -> V_2 -> V_10 , L_131 ,
V_5 -> V_323 -> V_324 ) ;
F_160 ( V_5 ) ;
return 0 ;
}
static void F_213 ( int V_462 )
{
V_463 [ V_462 ] -- ;
}
static int F_214 ( int V_464 )
{
int V_462 , V_465 , V_466 ;
const struct V_467 * V_468 ;
V_468 = F_215 ( V_464 ) ;
V_465 = F_216 ( V_468 ) ;
V_466 = V_463 [ V_465 ] ;
V_462 = V_465 ;
F_217 (cpu, node_mask) {
if ( V_463 [ V_462 ] < V_466 ) {
V_465 = V_462 ;
V_466 = V_463 [ V_462 ] ;
}
}
V_463 [ V_465 ] ++ ;
return V_465 ;
}
static inline int F_218 ( void )
{
static int V_469 = - 1 ;
if ( V_469 == - 1 ) {
V_469 = V_470 ;
return V_469 ;
}
V_469 = F_219 ( V_469 ) ;
if ( V_469 == V_471 )
V_469 = V_470 ;
return V_469 ;
}
static void F_220 ( struct V_4 * V_5 , struct V_1 * V_2 )
{
int V_472 ;
unsigned short V_473 ;
V_472 = F_221 ( V_2 , V_474 ) ;
if ( V_472 ) {
F_3 ( V_2 ,
V_472 + V_475 ,
& V_473 ) ;
if ( V_473 & ( 1 << 11 ) ||
V_473 & ( 1 << 4 ) ) {
F_48 ( & V_5 -> V_2 -> V_10 ,
L_132 ,
V_2 -> V_476 , V_2 -> V_197 ) ;
V_473 &= ~ ( V_477 |
V_478 ) ;
F_222 ( V_2 ,
V_472 + V_475 ,
V_473 ) ;
}
}
}
static void F_223 ( struct V_4 * V_5 , struct V_1 * V_2 )
{
if ( V_2 -> V_479 && V_2 -> V_479 -> V_480 ) {
if ( V_2 -> V_479 -> V_480 -> V_476 == V_481 &&
( ( V_2 -> V_479 -> V_480 -> V_197 & 0xff00 ) == 0x5a00 ) ) {
F_220 ( V_5 , V_2 -> V_479 -> V_480 ) ;
} else {
struct V_1 * V_482 = V_2 -> V_479 -> V_480 ;
if ( V_482 -> V_479 &&
V_482 -> V_479 -> V_483 &&
V_482 -> V_479 -> V_483 -> V_480 &&
V_482 -> V_479 -> V_483 -> V_480 -> V_476 ==
V_481 &&
( V_482 -> V_479 -> V_483 -> V_480 -> V_197 &
0xff00 ) == 0x5a00 ) {
F_220 ( V_5 ,
V_482 -> V_479 -> V_483 -> V_480 ) ;
}
}
}
}
static int F_224 ( struct V_1 * V_2 ,
const struct V_484 * V_485 )
{
int V_67 = 0 ;
struct V_4 * V_5 = NULL ;
char V_486 [ 256 ] ;
const struct V_467 * V_468 ;
int V_462 , V_49 = 0 , V_487 = 0 ;
int V_488 = V_489 ;
unsigned long V_91 ;
V_488 = F_225 ( V_2 -> V_479 ) ;
if ( V_488 != V_489 ) {
if ( ! F_226 ( V_488 ) )
V_488 = F_218 () ;
} else {
F_48 ( & V_2 -> V_10 , L_133 ) ;
V_488 = F_218 () ;
}
F_48 ( & V_2 -> V_10 , L_134 ,
V_488 , F_225 ( V_2 -> V_479 ) , F_227 ( & V_2 -> V_10 ) ,
F_228 ( F_229 () ) , F_229 () ) ;
V_5 = F_147 ( sizeof( struct V_4 ) , V_159 , V_488 ) ;
if ( V_5 == NULL ) {
F_38 ( & V_2 -> V_10 ,
L_135 ) ;
return - V_219 ;
}
F_230 ( V_2 , V_5 ) ;
V_67 = F_231 ( V_2 ) ;
if ( V_67 < 0 ) {
F_38 ( & V_2 -> V_10 , L_136 ) ;
goto V_490;
}
V_67 = F_232 ( V_2 , 1 << V_364 , V_94 ) ;
if ( V_67 < 0 ) {
F_38 ( & V_2 -> V_10 , L_137 ) ;
goto V_490;
}
if ( ! F_233 ( V_2 , F_234 ( 64 ) ) ) {
V_67 = F_235 ( V_2 , F_234 ( 64 ) ) ;
if ( V_67 ) {
V_67 = F_235 ( V_2 ,
F_234 ( 32 ) ) ;
if ( V_67 ) {
F_5 ( & V_2 -> V_10 ,
L_138 ) ;
goto V_491;
}
}
}
V_5 -> V_435 = V_492 ;
V_5 -> V_130 = V_130 ;
V_5 -> V_2 = V_2 ;
V_5 -> V_366 = V_488 ;
F_236 ( & V_5 -> V_493 ) ;
F_236 ( & V_5 -> V_494 ) ;
memset ( V_5 -> V_495 , 0 , 32 ) ;
snprintf ( V_5 -> V_495 , 31 , L_139 , V_5 -> V_130 ) ;
V_5 -> V_126 = F_237 ( V_5 -> V_495 ) ;
if ( ! V_5 -> V_126 ) {
F_5 ( & V_2 -> V_10 , L_140 , V_5 -> V_130 ) ;
V_67 = - V_219 ;
goto V_496;
}
memset ( V_486 , 0 , sizeof( V_486 ) ) ;
V_468 = F_215 ( V_5 -> V_366 ) ;
if ( ! F_238 ( V_468 ) ) {
F_217 (cpu, node_mask)
{
snprintf ( & V_486 [ V_487 ] , 256 - V_487 , L_141 , V_462 ) ;
V_487 = strlen ( V_486 ) ;
}
F_48 ( & V_2 -> V_10 , L_142 ,
V_5 -> V_366 ,
F_239 ( F_216 ( V_468 ) ) ,
F_240 ( V_5 -> V_366 ) ,
V_486 ) ;
} else
F_53 ( & V_2 -> V_10 , L_143 ) ;
V_5 -> V_377 = F_214 ( V_5 -> V_366 ) ;
F_48 ( & V_2 -> V_10 , L_144 ,
F_228 ( V_5 -> V_377 ) , V_5 -> V_377 ) ;
V_5 -> V_124 [ 0 ] . V_125 = V_5 -> V_377 ;
V_5 -> V_124 [ 1 ] . V_125 = F_214 ( V_5 -> V_366 ) ;
V_5 -> V_124 [ 2 ] . V_125 = F_214 ( V_5 -> V_366 ) ;
V_5 -> V_124 [ 3 ] . V_125 = V_5 -> V_124 [ 0 ] . V_125 ;
V_5 -> V_124 [ 4 ] . V_125 = V_5 -> V_124 [ 1 ] . V_125 ;
V_5 -> V_124 [ 5 ] . V_125 = V_5 -> V_124 [ 2 ] . V_125 ;
V_5 -> V_124 [ 6 ] . V_125 = V_5 -> V_124 [ 2 ] . V_125 ;
V_5 -> V_124 [ 7 ] . V_125 = V_5 -> V_124 [ 1 ] . V_125 ;
F_241 (cpu) {
memset ( V_486 , 0 , sizeof( V_486 ) ) ;
for ( V_49 = 0 , V_487 = 0 ; V_49 < V_123 ; V_49 ++ ) {
if ( V_5 -> V_124 [ V_49 ] . V_125 == V_462 ) {
snprintf ( & V_486 [ V_487 ] , 256 - V_487 , L_141 , V_49 ) ;
V_487 = strlen ( V_486 ) ;
}
}
if ( V_487 )
F_48 ( & V_2 -> V_10 , L_145 , V_462 , V_486 ) ;
}
F_242 ( & V_5 -> V_124 [ 0 ] . V_124 , V_497 ) ;
F_242 ( & V_5 -> V_124 [ 1 ] . V_124 , V_498 ) ;
F_242 ( & V_5 -> V_124 [ 2 ] . V_124 , V_499 ) ;
F_242 ( & V_5 -> V_124 [ 3 ] . V_124 , V_500 ) ;
F_242 ( & V_5 -> V_124 [ 4 ] . V_124 , V_501 ) ;
F_242 ( & V_5 -> V_124 [ 5 ] . V_124 , V_502 ) ;
F_242 ( & V_5 -> V_124 [ 6 ] . V_124 , V_503 ) ;
F_242 ( & V_5 -> V_124 [ 7 ] . V_124 , V_504 ) ;
F_243 ( V_2 ) ;
V_67 = F_244 ( V_2 ) ;
if ( V_67 ) {
F_5 ( & V_2 -> V_10 ,
L_146 ) ;
goto V_505;
}
F_223 ( V_5 , V_2 ) ;
V_67 = F_136 ( V_5 ) ;
if ( V_67 < 0 ) {
F_38 ( & V_2 -> V_10 ,
L_147 ) ;
goto V_496;
}
V_130 ++ ;
if ( V_67 != V_342 )
F_4 ( V_460 , & V_5 -> V_38 ) ;
else
V_67 = 0 ;
F_114 ( & V_310 , V_91 ) ;
F_245 ( & V_5 -> V_493 , & V_493 ) ;
F_117 ( & V_310 , V_91 ) ;
goto V_506;
V_496:
F_246 ( V_2 ) ;
V_505:
if ( V_5 -> V_126 ) {
F_247 ( V_5 -> V_126 ) ;
F_248 ( V_5 -> V_126 ) ;
F_213 ( V_5 -> V_124 [ 0 ] . V_125 ) ;
F_213 ( V_5 -> V_124 [ 1 ] . V_125 ) ;
F_213 ( V_5 -> V_124 [ 2 ] . V_125 ) ;
}
V_491:
F_249 ( V_2 , 1 << V_364 ) ;
V_490:
F_103 ( V_5 ) ;
F_230 ( V_2 , NULL ) ;
return V_67 ;
V_506:
return V_67 ;
}
static void F_250 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
unsigned long V_91 , V_143 ;
F_4 ( V_37 , & V_5 -> V_38 ) ;
F_114 ( & V_310 , V_91 ) ;
F_251 ( & V_5 -> V_493 ) ;
F_245 ( & V_5 -> V_494 , & V_507 ) ;
F_117 ( & V_310 , V_91 ) ;
F_1 ( V_2 ) ;
F_252 ( V_5 -> V_2 -> V_129 ) ;
V_143 = V_36 + F_23 ( 4000 ) ;
do {
F_66 ( 20 ) ;
} while ( F_58 ( & V_5 -> V_108 ) != 0 &&
F_26 ( V_36 , V_143 ) );
if ( F_58 ( & V_5 -> V_108 ) != 0 ) {
F_5 ( & V_5 -> V_2 -> V_10 ,
L_148 ) ;
}
F_65 ( V_5 -> V_7 ) ;
F_208 ( V_5 ) ;
if ( V_5 -> V_126 ) {
F_247 ( V_5 -> V_126 ) ;
F_248 ( V_5 -> V_126 ) ;
F_213 ( V_5 -> V_124 [ 0 ] . V_125 ) ;
F_213 ( V_5 -> V_124 [ 1 ] . V_125 ) ;
F_213 ( V_5 -> V_124 [ 2 ] . V_125 ) ;
}
F_246 ( V_2 ) ;
F_114 ( & V_310 , V_91 ) ;
F_251 ( & V_5 -> V_494 ) ;
F_117 ( & V_310 , V_91 ) ;
F_103 ( V_5 ) ;
F_249 ( V_2 , 1 << V_364 ) ;
F_230 ( V_2 , NULL ) ;
}
static int F_253 ( struct V_1 * V_2 , T_15 V_508 )
{
int V_67 = 0 ;
struct V_4 * V_5 = F_2 ( V_2 ) ;
if ( ! V_5 ) {
F_38 ( & V_2 -> V_10 ,
L_149 ) ;
return - V_68 ;
}
F_4 ( V_509 , & V_5 -> V_38 ) ;
V_67 = F_211 ( V_5 ) ;
if ( V_67 < 0 ) {
F_38 ( & V_2 -> V_10 ,
L_150 ) ;
return V_67 ;
}
F_254 ( V_2 ) ;
F_255 ( V_2 ) ;
F_256 ( V_2 , V_510 ) ;
return V_67 ;
}
static int F_257 ( struct V_1 * V_2 )
{
int V_67 = 0 ;
struct V_4 * V_5 ;
V_5 = F_2 ( V_2 ) ;
if ( ! V_5 ) {
F_38 ( & V_2 -> V_10 ,
L_149 ) ;
return - V_68 ;
}
F_256 ( V_2 , V_511 ) ;
F_258 ( V_2 ) ;
V_67 = F_231 ( V_2 ) ;
if ( V_67 < 0 ) {
F_38 ( & V_2 -> V_10 ,
L_151 ) ;
goto V_259;
}
F_243 ( V_2 ) ;
V_67 = F_212 ( V_5 ) ;
if ( V_67 < 0 )
F_38 ( & V_2 -> V_10 , L_152 ) ;
V_259:
F_49 ( V_509 , & V_5 -> V_38 ) ;
return V_67 ;
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
F_261 ( V_94 L_153 V_512 L_91 ) ;
F_149 ( & V_310 ) ;
F_236 ( & V_493 ) ;
F_236 ( & V_507 ) ;
error = F_262 ( 0 , V_94 ) ;
if ( error <= 0 ) {
F_263 ( L_154 ,
error ) ;
return - V_149 ;
}
V_492 = error ;
V_321 = F_126 ( L_122 , NULL ) ;
if ( F_127 ( V_321 ) ) {
F_264 ( L_155 ) ;
V_321 = NULL ;
}
if ( V_321 ) {
V_513 = F_128 ( L_156 ,
V_325 , V_321 , NULL ,
& V_514 ) ;
if ( F_127 ( V_513 ) ) {
F_263 ( L_157 ) ;
V_513 = NULL ;
}
}
error = F_265 ( & V_515 ) ;
if ( error ) {
F_266 ( V_321 ) ;
F_267 ( V_492 , V_94 ) ;
}
return error ;
}
static void T_17 F_268 ( void )
{
F_267 ( V_492 , V_94 ) ;
F_269 ( & V_515 ) ;
F_130 ( V_321 ) ;
}
