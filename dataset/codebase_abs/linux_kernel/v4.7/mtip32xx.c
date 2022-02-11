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
if ( F_1 ( V_5 -> V_2 ) )
return NULL ;
V_14 = F_7 ( V_5 -> V_7 , 0 , V_15 ) ;
if ( F_8 ( V_14 ) )
return NULL ;
return F_9 ( V_14 ) ;
}
static void F_10 ( struct V_4 * V_5 , struct V_12 * V_16 )
{
F_11 ( F_12 ( V_16 ) ) ;
}
static struct V_13 * F_13 ( struct V_4 * V_5 ,
unsigned int V_17 )
{
struct V_18 * V_19 = V_5 -> V_7 -> V_20 [ 0 ] ;
return F_14 ( V_19 -> V_21 , V_17 ) ;
}
static struct V_12 * F_15 ( struct V_4 * V_5 ,
unsigned int V_17 )
{
struct V_13 * V_14 = F_13 ( V_5 , V_17 ) ;
return F_9 ( V_14 ) ;
}
static void F_16 ( struct V_22 * V_23 ,
int V_17 , struct V_12 * V_16 , int V_24 )
{
struct V_4 * V_5 = V_23 -> V_5 ;
struct V_13 * V_14 ;
if ( F_17 ( ! V_5 ) || F_17 ( ! V_23 ) )
return;
if ( F_17 ( V_24 == V_25 ) ) {
F_5 ( & V_23 -> V_5 -> V_2 -> V_10 ,
L_2 , V_17 ) ;
}
V_14 = F_13 ( V_5 , V_17 ) ;
F_18 ( V_14 , V_24 ) ;
}
static int F_19 ( struct V_4 * V_5 )
{
unsigned long V_26 ;
F_20 ( V_27 , V_5 -> V_28 + V_29 ) ;
F_21 ( V_5 -> V_28 + V_29 ) ;
V_26 = V_30 + F_22 ( 10000 ) ;
do {
F_23 ( 10 ) ;
if ( F_24 ( V_31 , & V_5 -> V_32 ) )
return - 1 ;
} while ( ( F_21 ( V_5 -> V_28 + V_29 ) & V_27 )
&& F_25 ( V_30 , V_26 ) );
if ( F_21 ( V_5 -> V_28 + V_29 ) & V_27 )
return - 1 ;
return 0 ;
}
static inline void F_26 ( struct V_22 * V_23 , int V_17 )
{
int V_33 = V_17 >> 5 ;
F_27 ( & V_23 -> V_34 [ V_33 ] ) ;
F_20 ( ( 1 << F_28 ( V_17 ) ) ,
V_23 -> V_35 [ F_29 ( V_17 ) ] ) ;
F_20 ( ( 1 << F_28 ( V_17 ) ) ,
V_23 -> V_36 [ F_29 ( V_17 ) ] ) ;
F_30 ( & V_23 -> V_34 [ V_33 ] ) ;
}
static int F_31 ( struct V_22 * V_23 , int V_37 )
{
T_2 V_38 ;
V_38 = F_21 ( V_23 -> V_28 + V_39 ) ;
if ( V_37 )
F_20 ( V_38 | V_40 , V_23 -> V_28 + V_39 ) ;
else
F_20 ( V_38 & ~ V_40 , V_23 -> V_28 + V_39 ) ;
F_21 ( V_23 -> V_28 + V_39 ) ;
return ( ( ( V_38 & V_40 ) == V_40 ) ) ;
}
static int F_32 ( struct V_22 * V_23 , int V_37 )
{
T_2 V_38 ;
V_38 = F_21 ( V_23 -> V_28 + V_39 ) ;
if ( V_37 )
F_20 ( V_38 | V_41 , V_23 -> V_28 + V_39 ) ;
else
F_20 ( V_38 & ~ V_41 , V_23 -> V_28 + V_39 ) ;
F_21 ( V_23 -> V_28 + V_39 ) ;
return ( ( ( V_38 & V_41 ) == V_41 ) ) ;
}
static inline void F_33 ( struct V_22 * V_23 )
{
F_31 ( V_23 , 1 ) ;
F_32 ( V_23 , 1 ) ;
}
static inline void F_34 ( struct V_22 * V_23 )
{
F_20 ( 0 , V_23 -> V_28 + V_42 ) ;
F_32 ( V_23 , 0 ) ;
F_31 ( V_23 , 0 ) ;
}
static void F_35 ( struct V_22 * V_23 )
{
int V_43 ;
F_34 ( V_23 ) ;
if ( F_21 ( V_23 -> V_5 -> V_28 + V_44 ) & V_45 ) {
F_20 ( ( V_23 -> V_46 >> 16 ) >> 16 ,
V_23 -> V_28 + V_47 ) ;
F_20 ( ( V_23 -> V_48 >> 16 ) >> 16 ,
V_23 -> V_28 + V_49 ) ;
}
F_20 ( V_23 -> V_46 & 0xFFFFFFFF ,
V_23 -> V_28 + V_50 ) ;
F_20 ( V_23 -> V_48 & 0xFFFFFFFF , V_23 -> V_28 + V_51 ) ;
F_20 ( F_21 ( V_23 -> V_28 + V_52 ) , V_23 -> V_28 + V_52 ) ;
for ( V_43 = 0 ; V_43 < V_23 -> V_5 -> V_53 ; V_43 ++ )
F_20 ( 0xFFFFFFFF , V_23 -> V_54 [ V_43 ] ) ;
F_20 ( F_21 ( V_23 -> V_28 + V_55 ) , V_23 -> V_28 + V_55 ) ;
F_20 ( F_21 ( V_23 -> V_5 -> V_28 + V_56 ) ,
V_23 -> V_5 -> V_28 + V_56 ) ;
F_20 ( V_57 , V_23 -> V_28 + V_42 ) ;
}
static void F_36 ( struct V_22 * V_23 )
{
unsigned long V_26 ;
F_32 ( V_23 , 0 ) ;
V_26 = V_30 + F_22 ( 500 ) ;
while ( ( F_21 ( V_23 -> V_28 + V_39 ) & V_58 )
&& F_25 ( V_30 , V_26 ) )
;
if ( F_24 ( V_31 , & V_23 -> V_5 -> V_32 ) )
return;
if ( F_21 ( V_23 -> V_28 + V_39 ) & V_58 ) {
F_5 ( & V_23 -> V_5 -> V_2 -> V_10 ,
L_3 ) ;
if ( F_19 ( V_23 -> V_5 ) )
F_37 ( & V_23 -> V_5 -> V_2 -> V_10 ,
L_4 ) ;
F_23 ( 30 ) ;
}
F_5 ( & V_23 -> V_5 -> V_2 -> V_10 , L_5 ) ;
F_20 ( F_21 ( V_23 -> V_28 + V_59 ) |
1 , V_23 -> V_28 + V_59 ) ;
F_21 ( V_23 -> V_28 + V_59 ) ;
V_26 = V_30 + F_22 ( 1 ) ;
while ( F_25 ( V_30 , V_26 ) )
;
if ( F_24 ( V_31 , & V_23 -> V_5 -> V_32 ) )
return;
F_20 ( F_21 ( V_23 -> V_28 + V_59 ) & ~ 1 ,
V_23 -> V_28 + V_59 ) ;
F_21 ( V_23 -> V_28 + V_59 ) ;
V_26 = V_30 + F_22 ( 500 ) ;
while ( ( ( F_21 ( V_23 -> V_28 + V_60 ) & 0x01 ) == 0 )
&& F_25 ( V_30 , V_26 ) )
;
if ( F_24 ( V_31 , & V_23 -> V_5 -> V_32 ) )
return;
if ( ( F_21 ( V_23 -> V_28 + V_60 ) & 0x01 ) == 0 )
F_5 ( & V_23 -> V_5 -> V_2 -> V_10 ,
L_6 ) ;
F_35 ( V_23 ) ;
F_33 ( V_23 ) ;
}
static int F_38 ( struct V_4 * V_5 )
{
int V_61 = 0 ;
if ( F_1 ( V_5 -> V_2 ) )
return 0 ;
if ( F_19 ( V_5 ) < 0 )
V_61 = - V_62 ;
F_23 ( 1 ) ;
F_35 ( V_5 -> V_23 ) ;
F_33 ( V_5 -> V_23 ) ;
F_20 ( F_21 ( V_5 -> V_28 + V_29 ) | V_63 ,
V_5 -> V_28 + V_29 ) ;
return V_61 ;
}
static void F_39 ( struct V_4 * V_5 ,
char * V_64 ,
unsigned long * V_65 ,
int V_66 )
{
unsigned char V_67 [ 128 ] ;
int V_33 , V_68 = 0 ;
memset ( V_67 , 0 , sizeof( V_67 ) ) ;
for ( V_33 = V_69 ; V_33 > 0 ; V_33 -- )
V_68 += sprintf ( V_67 + V_68 , L_7 ,
V_65 [ V_33 - 1 ] ) ;
F_5 ( & V_5 -> V_2 -> V_10 ,
L_8 , V_66 , V_64 , V_67 ) ;
}
static void F_40 ( struct V_22 * V_23 ,
int V_17 , struct V_12 * V_70 , int V_24 )
{
struct V_71 * V_72 = V_70 -> V_73 ;
if ( F_17 ( V_24 == V_25 ) )
F_5 ( & V_23 -> V_5 -> V_2 -> V_10 ,
L_9 , V_17 ) ;
V_70 -> V_74 = NULL ;
V_70 -> V_73 = NULL ;
F_41 ( V_72 ) ;
}
static void F_42 ( struct V_22 * V_23 ,
int V_17 , struct V_12 * V_70 , int V_24 )
{
}
static void F_43 ( struct V_4 * V_5 )
{
int V_33 , V_17 , V_75 , V_76 , V_61 ;
struct V_22 * V_23 ;
struct V_12 * V_16 ;
T_2 V_54 ;
struct V_77 * V_78 ;
unsigned long V_79 [ V_69 ] ;
unsigned int V_80 = 0 ;
unsigned char * V_81 ;
char * V_82 = NULL ;
int V_83 = 0 , V_84 = 0 ;
F_5 ( & V_5 -> V_2 -> V_10 , L_10 ) ;
V_23 = V_5 -> V_23 ;
if ( F_24 ( V_85 , & V_23 -> V_86 ) ) {
V_16 = F_15 ( V_5 , V_87 ) ;
F_44 ( V_88 L_11 ) ;
if ( V_16 -> V_73 && V_16 -> V_74 ) {
V_16 -> V_74 ( V_23 , V_87 ,
V_16 , V_25 ) ;
}
return;
}
memset ( V_79 , 0 , V_69 * sizeof( long ) ) ;
for ( V_33 = 0 ; V_33 < V_5 -> V_53 ; V_33 ++ ) {
V_54 = F_21 ( V_23 -> V_54 [ V_33 ] ) ;
F_5 ( & V_5 -> V_2 -> V_10 , L_12 , V_33 , V_54 ) ;
F_20 ( V_54 , V_23 -> V_54 [ V_33 ] ) ;
for ( V_75 = 0 ; V_75 < 32 && V_54 ; V_75 ++ ) {
if ( ! ( V_54 & ( 1 << V_75 ) ) )
continue;
V_17 = ( V_33 << 5 ) + V_75 ;
if ( V_17 == V_87 )
continue;
V_16 = F_15 ( V_5 , V_17 ) ;
if ( F_45 ( V_16 -> V_74 ) ) {
F_4 ( V_17 , V_79 ) ;
V_80 ++ ;
V_16 -> V_74 ( V_23 , V_17 , V_16 , 0 ) ;
} else {
F_37 ( & V_23 -> V_5 -> V_2 -> V_10 ,
L_13 ,
V_17 ) ;
if ( F_1 ( V_5 -> V_2 ) ) {
return;
}
}
}
}
F_39 ( V_5 , L_14 , V_79 , V_80 ) ;
F_23 ( 20 ) ;
F_36 ( V_23 ) ;
V_61 = F_46 ( V_5 -> V_23 , V_89 ,
V_5 -> V_23 -> V_90 ,
V_5 -> V_23 -> V_91 , 1 ) ;
if ( V_61 ) {
F_5 ( & V_5 -> V_2 -> V_10 ,
L_15 ) ;
} else {
V_81 = ( unsigned char * ) V_5 -> V_23 -> V_90 ;
if ( V_81 [ 259 ] & 0x1 ) {
F_47 ( & V_5 -> V_2 -> V_10 ,
L_16 ) ;
F_4 ( V_92 , & V_5 -> V_32 ) ;
V_83 = 1 ;
V_82 = L_17 ;
}
if ( V_81 [ 288 ] == 0xF7 ) {
F_47 ( & V_5 -> V_2 -> V_10 ,
L_18 ) ;
F_4 ( V_93 , & V_5 -> V_32 ) ;
V_84 = 1 ;
V_82 = L_19 ;
}
if ( V_81 [ 288 ] == 0xBF ) {
F_4 ( V_94 , & V_5 -> V_32 ) ;
F_47 ( & V_5 -> V_2 -> V_10 ,
L_20 ) ;
V_84 = 1 ;
V_82 = L_21 ;
}
}
memset ( V_79 , 0 , V_69 * sizeof( long ) ) ;
for ( V_33 = 0 ; V_33 < V_5 -> V_53 ; V_33 ++ ) {
for ( V_75 = 0 ; V_75 < 32 ; V_75 ++ ) {
V_76 = 1 ;
V_17 = ( V_33 << 5 ) + V_75 ;
V_16 = F_15 ( V_5 , V_17 ) ;
V_78 = (struct V_77 * ) V_16 -> V_70 ;
if ( V_17 == V_87 ||
V_78 -> V_70 == V_95 )
V_76 = 0 ;
else {
if ( V_84 ||
( V_83 &&
V_78 -> V_70 == V_96 ) ) {
F_5 ( & V_5 -> V_2 -> V_10 ,
L_22 ,
V_78 -> V_70 == V_96 ?
L_23 : L_24 ,
V_17 ,
V_82 != NULL ?
V_82 : L_25 ) ;
if ( V_16 -> V_74 ) {
V_16 -> V_74 ( V_23 , V_17 ,
V_16 , - V_97 ) ;
}
continue;
}
}
if ( V_76 && ( V_16 -> V_98 -- > 0 ) ) {
F_4 ( V_17 , V_79 ) ;
F_26 ( V_23 , V_17 ) ;
continue;
}
F_5 ( & V_23 -> V_5 -> V_2 -> V_10 ,
L_26 , V_17 ) ;
if ( V_16 -> V_74 )
V_16 -> V_74 ( V_23 , V_17 , V_16 , V_25 ) ;
else
F_5 ( & V_23 -> V_5 -> V_2 -> V_10 ,
L_27 ,
V_17 ) ;
}
}
F_39 ( V_5 , L_28 , V_79 , V_80 ) ;
}
static inline void F_48 ( struct V_22 * V_23 , int V_33 ,
T_2 V_54 )
{
struct V_4 * V_5 = V_23 -> V_5 ;
int V_17 , V_75 ;
struct V_12 * V_70 ;
if ( ! V_54 ) {
F_49 ( ! V_54 ) ;
return;
}
F_20 ( V_54 , V_23 -> V_54 [ V_33 ] ) ;
for ( V_75 = 0 ; ( V_75 < 32 ) && V_54 ; V_75 ++ ) {
if ( V_54 & 0x01 ) {
V_17 = ( V_33 << 5 ) | V_75 ;
if ( F_17 ( V_17 == V_87 ) )
continue;
V_70 = F_15 ( V_5 , V_17 ) ;
if ( F_45 ( V_70 -> V_74 ) )
V_70 -> V_74 ( V_23 , V_17 , V_70 , 0 ) ;
else {
F_50 ( & V_5 -> V_2 -> V_10 ,
L_29 ,
V_17 ) ;
if ( F_1 (
V_5 -> V_2 ) ) {
return;
}
}
}
V_54 >>= 1 ;
}
if ( F_51 ( & V_5 -> V_99 ) == 0 )
F_20 ( 0xffffffff , V_5 -> V_28 + V_56 ) ;
}
static inline void F_52 ( struct V_4 * V_5 , T_2 V_100 )
{
struct V_22 * V_23 = V_5 -> V_23 ;
struct V_12 * V_16 = F_15 ( V_5 , V_87 ) ;
if ( F_24 ( V_85 , & V_23 -> V_86 ) &&
( V_16 != NULL ) && ! ( F_21 ( V_23 -> V_36 [ V_87 ] )
& ( 1 << V_87 ) ) ) {
if ( V_16 -> V_74 ) {
V_16 -> V_74 ( V_23 , V_87 , V_16 , 0 ) ;
return;
}
}
return;
}
static inline void F_53 ( struct V_4 * V_5 , T_2 V_100 )
{
if ( F_17 ( V_100 & V_101 ) ) {
F_5 ( & V_5 -> V_2 -> V_10 ,
L_30 ) ;
F_20 ( ( 1 << 26 ) , V_5 -> V_23 -> V_28 + V_52 ) ;
}
if ( F_17 ( V_100 & V_102 ) ) {
F_5 ( & V_5 -> V_2 -> V_10 ,
L_31 ) ;
F_20 ( ( 1 << 16 ) , V_5 -> V_23 -> V_28 + V_52 ) ;
}
if ( F_17 ( V_100 & ~ V_103 ) ) {
F_5 ( & V_5 -> V_2 -> V_10 ,
L_32 ,
( V_100 & ~ V_103 ) ) ;
if ( F_1 ( V_5 -> V_2 ) )
return;
}
if ( F_45 ( V_100 & ( V_25 | V_104 ) ) ) {
F_4 ( V_105 , & V_5 -> V_23 -> V_86 ) ;
F_54 ( & V_5 -> V_23 -> V_106 ) ;
}
}
static inline T_3 F_55 ( struct V_4 * V_107 )
{
struct V_4 * V_5 = (struct V_4 * ) V_107 ;
struct V_22 * V_23 = V_5 -> V_23 ;
T_2 V_108 , V_100 ;
int V_61 = V_109 ;
int V_110 = 1 , V_43 , V_111 ;
struct V_112 * V_113 ;
V_108 = F_21 ( V_5 -> V_28 + V_56 ) ;
if ( V_108 ) {
V_61 = V_114 ;
V_100 = F_21 ( V_23 -> V_28 + V_55 ) ;
if ( F_17 ( V_100 == 0xFFFFFFFF ) ) {
F_1 ( V_5 -> V_2 ) ;
return V_114 ;
}
F_20 ( V_100 , V_23 -> V_28 + V_55 ) ;
if ( F_45 ( V_100 & V_115 ) ) {
V_110 = 0 ;
F_49 ( F_56 ( & V_5 -> V_99 ) != 0 ) ;
for ( V_43 = 0 , V_111 = 0 ; V_43 < V_116 ;
V_43 ++ ) {
V_113 = & V_5 -> V_117 [ V_43 ] ;
V_113 -> V_54 = F_21 ( V_23 -> V_54 [ V_43 ] ) ;
if ( V_113 -> V_54 )
V_111 ++ ;
}
F_57 ( & V_5 -> V_99 , V_111 ) ;
if ( V_111 ) {
for ( V_43 = 1 ; V_43 < V_116 ; V_43 ++ ) {
V_113 = & V_5 -> V_117 [ V_43 ] ;
if ( V_113 -> V_54 )
F_58 (
V_113 -> V_118 ,
V_5 -> V_119 ,
& V_113 -> V_117 ) ;
}
if ( F_45 ( V_5 -> V_117 [ 0 ] . V_54 ) )
F_48 ( V_23 , 0 ,
V_5 -> V_117 [ 0 ] . V_54 ) ;
} else {
V_110 = 1 ;
}
}
if ( F_17 ( V_100 & V_120 ) ) {
if ( F_17 ( F_1 ( V_5 -> V_2 ) ) ) {
return V_114 ;
}
if ( F_24 ( V_31 ,
& V_5 -> V_32 ) )
return V_61 ;
F_53 ( V_5 , V_100 & V_120 ) ;
}
if ( F_17 ( V_100 & V_121 ) )
F_52 ( V_5 , V_100 & V_121 ) ;
}
if ( F_17 ( V_110 ) )
F_20 ( V_108 , V_5 -> V_28 + V_56 ) ;
return V_61 ;
}
static T_3 F_59 ( int V_122 , void * V_123 )
{
struct V_4 * V_5 = V_123 ;
return F_55 ( V_5 ) ;
}
static void F_60 ( struct V_22 * V_23 , int V_17 )
{
F_20 ( 1 << F_28 ( V_17 ) ,
V_23 -> V_36 [ F_29 ( V_17 ) ] ) ;
}
static bool F_61 ( struct V_22 * V_23 ,
struct V_77 * V_78 )
{
struct V_77 * V_124 ;
unsigned long V_125 ;
V_124 = V_23 -> V_126 + V_127 ;
V_125 = F_21 ( V_23 -> V_28 + V_128 ) ;
if ( ( V_125 & 1 ) )
return false ;
if ( V_78 -> V_70 == V_129 ) {
V_23 -> V_130 = V_30 ;
return true ;
} else if ( ( V_78 -> V_70 == V_131 ) &&
( V_78 -> V_132 == 0x03 ) ) {
F_4 ( V_133 , & V_23 -> V_86 ) ;
V_23 -> V_130 = V_30 ;
return true ;
} else if ( ( V_78 -> V_70 == V_134 ) ||
( ( V_78 -> V_70 == 0xFC ) &&
( V_78 -> V_132 == 0x27 || V_78 -> V_132 == 0x72 ||
V_78 -> V_132 == 0x62 || V_78 -> V_132 == 0x26 ) ) ) {
F_62 ( V_135 , & V_23 -> V_5 -> V_32 ) ;
F_62 ( V_94 , & V_23 -> V_5 -> V_32 ) ;
F_36 ( V_23 ) ;
F_62 ( V_136 , & V_23 -> V_86 ) ;
return false ;
}
return false ;
}
static int F_63 ( struct V_22 * V_23 , unsigned long V_26 ,
T_4 V_137 )
{
unsigned long V_138 ;
unsigned int V_139 ;
unsigned int V_140 = 1 ;
F_64 ( V_23 -> V_5 -> V_7 ) ;
V_138 = V_30 + F_22 ( V_26 ) ;
do {
if ( F_24 ( V_141 , & V_23 -> V_86 ) &&
F_24 ( V_142 , & V_23 -> V_86 ) &&
V_137 == V_143 ) {
F_65 ( 20 ) ;
continue;
}
if ( V_137 == V_143 )
F_65 ( 100 ) ;
else {
F_66 () ;
F_67 ( 100 ) ;
}
if ( F_1 ( V_23 -> V_5 -> V_2 ) )
goto V_144;
V_140 = F_21 ( V_23 -> V_35 [ 0 ] ) & 0xFFFFFFFE ;
for ( V_139 = 1 ; V_139 < V_23 -> V_5 -> V_53 ; V_139 ++ )
V_140 |= F_21 ( V_23 -> V_35 [ V_139 ] ) ;
if ( ! V_140 )
break;
} while ( F_25 ( V_30 , V_138 ) );
F_68 ( V_23 -> V_5 -> V_7 , true ) ;
return V_140 ? - V_145 : 0 ;
V_144:
F_68 ( V_23 -> V_5 -> V_7 , true ) ;
return - V_62 ;
}
static int F_69 ( struct V_22 * V_23 ,
struct V_77 * V_78 ,
int V_146 ,
T_5 V_147 ,
int V_148 ,
T_2 V_149 ,
T_4 V_137 ,
unsigned long V_26 )
{
struct V_150 * V_151 ;
F_70 ( V_152 ) ;
struct V_12 * V_153 ;
struct V_4 * V_5 = V_23 -> V_5 ;
int V_61 = 0 ;
unsigned long V_154 ;
if ( V_147 & 0x00000007 ) {
F_37 ( & V_5 -> V_2 -> V_10 , L_33 ) ;
return - V_62 ;
}
V_153 = F_6 ( V_5 ) ;
if ( ! V_153 ) {
F_44 ( V_88 L_34 ) ;
return - V_62 ;
}
F_4 ( V_85 , & V_23 -> V_86 ) ;
if ( V_78 -> V_70 == V_129 )
F_4 ( V_136 , & V_23 -> V_86 ) ;
F_62 ( V_133 , & V_23 -> V_86 ) ;
if ( V_137 == V_143 ) {
if ( V_78 -> V_70 != V_155 ) {
if ( F_63 ( V_23 ,
V_156 , V_137 ) < 0 ) {
F_5 ( & V_5 -> V_2 -> V_10 ,
L_35 ) ;
F_10 ( V_5 , V_153 ) ;
F_62 ( V_85 , & V_23 -> V_86 ) ;
F_54 ( & V_23 -> V_106 ) ;
return - V_145 ;
}
}
V_153 -> V_73 = & V_152 ;
V_153 -> V_74 = F_40 ;
} else {
V_153 -> V_73 = NULL ;
V_153 -> V_74 = F_42 ;
}
memcpy ( V_153 -> V_70 , V_78 , V_146 * 4 ) ;
V_153 -> V_157 -> V_149 =
V_158 F_71 ( V_149 | V_146 ) ;
if ( V_148 ) {
V_151 = V_153 -> V_70 + V_159 ;
V_151 -> V_160 =
V_158 F_71 ( ( V_148 - 1 ) & 0x3FFFFF ) ;
V_151 -> V_161 =
V_158 F_71 ( V_147 & 0xFFFFFFFF ) ;
V_151 -> V_162 =
V_158 F_71 ( ( V_147 >> 16 ) >> 16 ) ;
V_153 -> V_157 -> V_149 |=
V_158 F_71 ( ( 1 << 16 ) ) ;
}
V_153 -> V_157 -> V_163 = 0 ;
V_154 = V_30 ;
F_60 ( V_23 , V_87 ) ;
if ( V_137 == V_143 ) {
if ( ( V_61 = F_72 (
& V_152 ,
F_22 ( V_26 ) ) ) <= 0 ) {
if ( V_61 == - V_164 ) {
F_37 ( & V_5 -> V_2 -> V_10 ,
L_36 ,
V_78 -> V_70 ,
F_73 ( V_30 - V_154 ) ) ;
V_61 = - V_165 ;
goto V_166;
} else if ( V_61 == 0 )
F_37 ( & V_5 -> V_2 -> V_10 ,
L_37 ,
V_78 -> V_70 , V_26 ) ;
else
F_37 ( & V_5 -> V_2 -> V_10 ,
L_38 ,
V_78 -> V_70 , V_61 , V_26 ) ;
if ( F_1 ( V_5 -> V_2 ) ||
F_24 ( V_31 ,
& V_5 -> V_32 ) ) {
F_37 ( & V_5 -> V_2 -> V_10 ,
L_39 ,
V_78 -> V_70 ) ;
V_61 = - V_167 ;
goto V_166;
}
F_38 ( V_5 ) ;
V_61 = - V_168 ;
goto V_166;
}
} else {
T_2 V_108 , V_100 ;
V_26 = V_30 + F_22 ( V_26 ) ;
while ( ( F_21 ( V_23 -> V_36 [ V_87 ] )
& ( 1 << V_87 ) )
&& F_25 ( V_30 , V_26 ) ) {
if ( F_1 ( V_5 -> V_2 ) ) {
V_61 = - V_167 ;
goto V_166;
}
if ( ( V_78 -> V_70 != V_155 ) &&
F_24 ( V_31 ,
& V_5 -> V_32 ) ) {
V_61 = - V_167 ;
goto V_166;
}
V_100 = F_21 ( V_23 -> V_28 + V_55 ) ;
if ( ! V_100 )
continue;
if ( V_100 & V_120 ) {
F_37 ( & V_5 -> V_2 -> V_10 ,
L_40 ,
V_78 -> V_70 ) ;
F_38 ( V_5 ) ;
V_61 = - V_169 ;
goto V_166;
} else {
F_20 ( V_100 , V_23 -> V_28 + V_55 ) ;
V_108 = F_21 ( V_5 -> V_28 + V_56 ) ;
if ( V_108 )
F_20 ( V_108 ,
V_5 -> V_28 + V_56 ) ;
}
break;
}
}
if ( F_21 ( V_23 -> V_36 [ V_87 ] )
& ( 1 << V_87 ) ) {
V_61 = - V_167 ;
if ( ! F_24 ( V_31 , & V_5 -> V_32 ) ) {
F_38 ( V_5 ) ;
V_61 = - V_168 ;
}
}
V_166:
F_10 ( V_5 , V_153 ) ;
F_62 ( V_85 , & V_23 -> V_86 ) ;
if ( V_61 >= 0 && F_61 ( V_23 , V_78 ) ) {
return V_61 ;
}
F_54 ( & V_23 -> V_106 ) ;
return V_61 ;
}
static inline void F_74 ( T_1 * V_81 , unsigned int V_170 )
{
int V_43 ;
for ( V_43 = 0 ; V_43 < ( V_170 / 2 ) ; V_43 ++ )
F_75 ( & V_81 [ V_43 ] ) ;
}
static void F_76 ( struct V_4 * V_5 ,
struct V_77 * V_78 ,
unsigned int * V_26 , T_6 V_171 )
{
switch ( V_78 -> V_70 ) {
case V_131 :
* V_26 = 120000 ;
break;
case V_134 :
case 0xFC :
if ( V_171 )
* V_26 = ( ( * ( V_5 -> V_23 -> V_172 + 90 ) * 2 ) * 60000 ) ;
else
* V_26 = ( ( * ( V_5 -> V_23 -> V_172 + 89 ) * 2 ) * 60000 ) ;
break;
case V_155 :
* V_26 = 120000 ;
break;
case 0xF7 :
case 0xFA :
* V_26 = 60000 ;
break;
case V_173 :
* V_26 = 15000 ;
break;
default:
* V_26 = V_174 ;
break;
}
}
static int F_77 ( struct V_22 * V_23 , void T_7 * V_175 )
{
int V_61 = 0 ;
struct V_77 V_78 ;
if ( F_24 ( V_31 , & V_23 -> V_5 -> V_32 ) )
return - V_62 ;
memset ( & V_78 , 0 , sizeof( struct V_77 ) ) ;
V_78 . type = 0x27 ;
V_78 . V_149 = 1 << 7 ;
V_78 . V_70 = V_176 ;
V_23 -> V_177 = 0 ;
memset ( V_23 -> V_172 , 0 , sizeof( T_1 ) * V_178 ) ;
if ( F_69 ( V_23 ,
& V_78 ,
5 ,
V_23 -> V_179 ,
sizeof( T_1 ) * V_178 ,
0 ,
V_143 ,
V_180 )
< 0 ) {
V_61 = - 1 ;
goto V_181;
}
#ifdef F_78
F_74 ( V_23 -> V_172 + 27 , 40 ) ;
F_74 ( V_23 -> V_172 + 23 , 8 ) ;
F_74 ( V_23 -> V_172 + 10 , 20 ) ;
#else
{
int V_43 ;
for ( V_43 = 0 ; V_43 < V_178 ; V_43 ++ )
V_23 -> V_172 [ V_43 ] = F_79 ( V_23 -> V_172 [ V_43 ] ) ;
}
#endif
if ( V_23 -> V_172 [ 128 ] & 0x4 )
F_4 ( V_135 , & V_23 -> V_5 -> V_32 ) ;
else
F_62 ( V_135 , & V_23 -> V_5 -> V_32 ) ;
#ifdef F_80
if ( V_23 -> V_172 [ 69 ] & ( 1 << 14 ) && V_23 -> V_172 [ 69 ] & ( 1 << 5 ) )
V_23 -> V_5 -> V_182 = true ;
else
#endif
V_23 -> V_5 -> V_182 = false ;
V_23 -> V_177 = 1 ;
if ( V_175 ) {
if ( F_81 (
V_175 ,
V_23 -> V_172 ,
V_178 * sizeof( T_1 ) ) ) {
V_61 = - V_62 ;
goto V_181;
}
}
V_181:
return V_61 ;
}
static int F_82 ( struct V_22 * V_23 )
{
int V_61 ;
struct V_77 V_78 ;
unsigned long V_154 ;
unsigned int V_26 ;
memset ( & V_78 , 0 , sizeof( struct V_77 ) ) ;
V_78 . type = 0x27 ;
V_78 . V_149 = 1 << 7 ;
V_78 . V_70 = V_155 ;
F_76 ( V_23 -> V_5 , & V_78 , & V_26 , 0 ) ;
V_154 = V_30 ;
V_61 = F_69 ( V_23 ,
& V_78 ,
5 ,
0 ,
0 ,
0 ,
V_183 ,
V_26 ) ;
F_44 ( V_88 L_41 ,
F_73 ( V_30 - V_154 ) ) ;
if ( V_61 )
F_5 ( & V_23 -> V_5 -> V_2 -> V_10 ,
L_42 ) ;
return V_61 ;
}
static int F_46 ( struct V_22 * V_23 , T_6 V_184 , T_1 * V_147 ,
T_5 V_185 , unsigned int V_186 )
{
struct V_77 V_78 ;
memset ( & V_78 , 0 , sizeof( struct V_77 ) ) ;
V_78 . type = 0x27 ;
V_78 . V_149 = 1 << 7 ;
V_78 . V_70 = V_187 ;
V_78 . V_188 = V_186 & 0xFF ;
V_78 . V_189 = ( V_186 >> 8 ) & 0xFF ;
V_78 . V_190 = V_184 ;
V_78 . V_191 = 0 ;
V_78 . V_192 = V_193 ;
memset ( V_147 , 0 , V_186 * V_194 ) ;
return F_69 ( V_23 ,
& V_78 ,
5 ,
V_185 ,
V_186 * V_194 ,
0 ,
V_183 ,
V_180 ) ;
}
static int F_83 ( struct V_22 * V_23 , T_6 * V_147 ,
T_5 V_185 )
{
struct V_77 V_78 ;
memset ( & V_78 , 0 , sizeof( struct V_77 ) ) ;
V_78 . type = 0x27 ;
V_78 . V_149 = 1 << 7 ;
V_78 . V_70 = V_173 ;
V_78 . V_132 = 0xD0 ;
V_78 . V_188 = 1 ;
V_78 . V_191 = 0x4F ;
V_78 . V_195 = 0xC2 ;
V_78 . V_192 = V_193 ;
return F_69 ( V_23 ,
& V_78 ,
5 ,
V_185 ,
V_194 ,
0 ,
V_183 ,
15000 ) ;
}
static int F_84 ( struct V_22 * V_23 , unsigned int V_196 ,
struct V_197 * V_198 )
{
int V_61 , V_43 ;
struct V_197 * V_199 ;
if ( ! V_198 )
return - V_200 ;
if ( ! V_23 -> V_177 ) {
F_5 ( & V_23 -> V_5 -> V_2 -> V_10 , L_43 ) ;
return - V_201 ;
}
if ( ! ( V_23 -> V_172 [ 82 ] & 0x1 ) ) {
F_5 ( & V_23 -> V_5 -> V_2 -> V_10 , L_44 ) ;
return - V_201 ;
}
if ( ! ( V_23 -> V_172 [ 85 ] & 0x1 ) ) {
F_5 ( & V_23 -> V_5 -> V_2 -> V_10 , L_45 ) ;
return - V_201 ;
}
memset ( V_23 -> V_202 , 0 , V_194 ) ;
V_61 = F_83 ( V_23 , V_23 -> V_202 , V_23 -> V_203 ) ;
if ( V_61 ) {
F_5 ( & V_23 -> V_5 -> V_2 -> V_10 , L_46 ) ;
return V_61 ;
}
V_199 = (struct V_197 * ) ( V_23 -> V_202 + 2 ) ;
for ( V_43 = 0 ; V_43 < 29 ; V_43 ++ , V_199 ++ )
if ( V_199 -> V_204 == V_196 ) {
memcpy ( V_198 , V_199 , sizeof( struct V_197 ) ) ;
break;
}
if ( V_43 == 29 ) {
F_5 ( & V_23 -> V_5 -> V_2 -> V_10 ,
L_47 ) ;
V_61 = - V_200 ;
}
return V_61 ;
}
static int F_85 ( struct V_4 * V_5 , unsigned int V_205 ,
unsigned int V_170 )
{
int V_43 , V_61 = 0 ;
T_8 V_206 , V_207 , V_208 ;
struct V_209 * V_81 ;
T_5 V_210 ;
struct V_77 V_78 ;
if ( ! V_170 || V_5 -> V_182 == false )
return - V_200 ;
F_86 ( V_170 > ( V_211 * V_212 ) ) ;
F_86 ( V_170 % 8 != 0 ) ;
F_86 ( sizeof( struct V_213 ) > V_194 ) ;
V_81 = F_87 ( & V_5 -> V_2 -> V_10 , V_194 , & V_210 ,
V_143 ) ;
if ( ! V_81 )
return - V_214 ;
memset ( V_81 , 0 , V_194 ) ;
for ( V_43 = 0 , V_208 = V_170 , V_206 = V_205 ;
V_43 < V_212 && V_208 ;
V_43 ++ ) {
V_207 = ( V_208 >= V_211 ?
V_211 :
V_208 ) ;
V_81 [ V_43 ] . V_205 = V_158 F_71 ( V_206 ) ;
V_81 [ V_43 ] . V_215 = V_158 F_88 ( V_207 ) ;
V_206 += V_207 ;
V_208 -= V_207 ;
}
F_86 ( V_208 != 0 ) ;
memset ( & V_78 , 0 , sizeof( struct V_77 ) ) ;
V_78 . type = 0x27 ;
V_78 . V_149 = 1 << 7 ;
V_78 . V_70 = 0xfb ;
V_78 . V_132 = 0x60 ;
V_78 . V_188 = 1 ;
V_78 . V_192 = V_193 ;
if ( F_69 ( V_5 -> V_23 ,
& V_78 ,
5 ,
V_210 ,
V_194 ,
0 ,
V_143 ,
V_216 ) < 0 )
V_61 = - V_169 ;
F_89 ( & V_5 -> V_2 -> V_10 , V_194 , V_81 , V_210 ) ;
return V_61 ;
}
static bool F_90 ( struct V_4 * V_5 , T_9 * V_186 )
{
struct V_22 * V_23 = V_5 -> V_23 ;
T_8 V_217 , V_218 , V_219 , V_220 , V_221 ;
V_218 = V_23 -> V_172 [ 100 ] ;
V_219 = V_23 -> V_172 [ 101 ] ;
V_220 = V_23 -> V_172 [ 102 ] ;
V_221 = V_23 -> V_172 [ 103 ] ;
V_217 = V_218 | V_219 << 16 | V_220 << 32 | V_221 << 48 ;
* V_186 = V_217 ;
return ( bool ) ! ! V_23 -> V_177 ;
}
static void F_91 ( struct V_22 * V_23 )
{
T_9 V_186 ;
unsigned short V_222 ;
char V_223 [ 42 ] ;
if ( ! V_23 -> V_177 )
return;
F_92 ( V_223 , ( char * ) ( V_23 -> V_172 + 10 ) , 21 ) ;
F_47 ( & V_23 -> V_5 -> V_2 -> V_10 ,
L_48 , V_223 ) ;
F_92 ( V_223 , ( char * ) ( V_23 -> V_172 + 23 ) , 9 ) ;
F_47 ( & V_23 -> V_5 -> V_2 -> V_10 ,
L_49 , V_223 ) ;
F_92 ( V_223 , ( char * ) ( V_23 -> V_172 + 27 ) , 41 ) ;
F_47 ( & V_23 -> V_5 -> V_2 -> V_10 , L_50 , V_223 ) ;
F_47 ( & V_23 -> V_5 -> V_2 -> V_10 , L_51 ,
V_23 -> V_172 [ 128 ] ,
V_23 -> V_172 [ 128 ] & 0x4 ? L_52 : L_53 ) ;
if ( F_90 ( V_23 -> V_5 , & V_186 ) )
F_47 ( & V_23 -> V_5 -> V_2 -> V_10 ,
L_54 ,
( T_8 ) V_186 ,
( ( T_8 ) V_186 ) * V_194 >> 20 ) ;
F_3 ( V_23 -> V_5 -> V_2 , V_224 , & V_222 ) ;
switch ( V_222 & 0xFF ) {
case 0x1 :
F_92 ( V_223 , L_55 , 3 ) ;
break;
case 0x3 :
F_92 ( V_223 , L_56 , 3 ) ;
break;
default:
F_92 ( V_223 , L_57 , 2 ) ;
break;
}
F_47 ( & V_23 -> V_5 -> V_2 -> V_10 ,
L_58 , V_223 ) ;
}
static inline void F_93 ( struct V_4 * V_5 ,
struct V_12 * V_70 ,
int V_225 )
{
int V_139 ;
unsigned int V_226 ;
struct V_150 * V_151 ;
struct V_227 * V_228 = V_70 -> V_228 ;
V_151 = V_70 -> V_70 + V_159 ;
for ( V_139 = 0 ; V_139 < V_225 ; V_139 ++ ) {
V_226 = F_94 ( V_228 ) ;
if ( V_226 > 0x400000 )
F_37 ( & V_5 -> V_2 -> V_10 ,
L_59 ) ;
V_151 -> V_160 = V_158
F_71 ( ( V_226 - 1 ) & 0x3FFFFF ) ;
V_151 -> V_161 = V_158
F_71 ( F_95 ( V_228 ) ) ;
V_151 -> V_162 = V_158
F_71 ( ( F_95 ( V_228 ) >> 16 ) >> 16 ) ;
V_151 ++ ;
V_228 ++ ;
}
}
static int F_96 ( struct V_22 * V_23 , T_6 * V_70 )
{
struct V_77 V_78 ;
struct V_77 * V_124 = ( V_23 -> V_126 + V_127 ) ;
unsigned int V_138 ;
memset ( & V_78 , 0 , sizeof( struct V_77 ) ) ;
V_78 . type = 0x27 ;
V_78 . V_149 = 1 << 7 ;
V_78 . V_70 = V_70 [ 0 ] ;
V_78 . V_132 = V_70 [ 1 ] ;
V_78 . V_188 = V_70 [ 2 ] ;
V_78 . V_229 = V_70 [ 3 ] ;
V_78 . V_230 = V_70 [ 4 ] ;
V_78 . V_231 = V_70 [ 5 ] ;
V_78 . V_192 = V_70 [ 6 ] & ~ 0x10 ;
F_76 ( V_23 -> V_5 , & V_78 , & V_138 , 0 ) ;
F_44 ( V_88 L_60 ,
V_11 ,
V_70 [ 0 ] ,
V_70 [ 1 ] ,
V_70 [ 2 ] ,
V_70 [ 3 ] ,
V_70 [ 4 ] ,
V_70 [ 5 ] ,
V_70 [ 6 ] ) ;
if ( F_69 ( V_23 ,
& V_78 ,
5 ,
0 ,
0 ,
0 ,
V_143 ,
V_138 ) < 0 ) {
return - 1 ;
}
V_70 [ 0 ] = V_124 -> V_70 ;
V_70 [ 1 ] = V_124 -> V_132 ;
V_70 [ 4 ] = V_124 -> V_230 ;
V_70 [ 5 ] = V_124 -> V_231 ;
F_44 ( V_88 L_61 ,
V_11 ,
V_70 [ 0 ] ,
V_70 [ 1 ] ,
V_70 [ 4 ] ,
V_70 [ 5 ] ) ;
return 0 ;
}
static int F_97 ( struct V_22 * V_23 , T_6 * V_70 ,
void T_7 * V_175 )
{
struct V_77 V_78 ;
struct V_77 * V_124 ;
T_6 * V_81 = NULL ;
T_5 V_210 = 0 ;
int V_61 = 0 , V_232 = V_70 [ 3 ] ;
unsigned int V_138 ;
if ( V_232 ) {
if ( ! V_175 )
return - V_62 ;
V_81 = F_87 ( & V_23 -> V_5 -> V_2 -> V_10 ,
V_194 * V_232 ,
& V_210 ,
V_143 ) ;
if ( ! V_81 ) {
F_37 ( & V_23 -> V_5 -> V_2 -> V_10 ,
L_62 ,
V_194 * V_232 ) ;
return - V_214 ;
}
memset ( V_81 , 0 , V_194 * V_232 ) ;
}
memset ( & V_78 , 0 , sizeof( struct V_77 ) ) ;
V_78 . type = 0x27 ;
V_78 . V_149 = 1 << 7 ;
V_78 . V_70 = V_70 [ 0 ] ;
V_78 . V_132 = V_70 [ 2 ] ;
V_78 . V_188 = V_70 [ 3 ] ;
if ( V_78 . V_70 == V_173 ) {
V_78 . V_229 = V_70 [ 1 ] ;
V_78 . V_230 = 0x4F ;
V_78 . V_231 = 0xC2 ;
}
F_76 ( V_23 -> V_5 , & V_78 , & V_138 , 0 ) ;
if ( V_232 )
V_124 = ( V_23 -> V_126 + V_233 ) ;
else
V_124 = ( V_23 -> V_126 + V_127 ) ;
F_44 ( V_88
L_63
L_64 ,
V_11 ,
V_70 [ 0 ] ,
V_70 [ 1 ] ,
V_70 [ 2 ] ,
V_70 [ 3 ] ) ;
if ( F_69 ( V_23 ,
& V_78 ,
5 ,
( V_232 ? V_210 : 0 ) ,
( V_232 ? V_194 * V_232 : 0 ) ,
0 ,
V_143 ,
V_138 )
< 0 ) {
V_61 = - V_62 ;
goto V_234;
}
V_70 [ 0 ] = V_124 -> V_70 ;
V_70 [ 1 ] = V_124 -> V_132 ;
V_70 [ 2 ] = V_124 -> V_188 ;
F_44 ( V_88
L_65
L_66 ,
V_11 ,
V_70 [ 0 ] ,
V_70 [ 1 ] ,
V_70 [ 2 ] ) ;
if ( V_232 ) {
if ( F_81 ( V_175 ,
V_81 ,
V_194 * V_70 [ 3 ] ) ) {
V_61 = - V_62 ;
goto V_234;
}
}
V_234:
if ( V_81 )
F_89 ( & V_23 -> V_5 -> V_2 -> V_10 ,
V_194 * V_232 , V_81 , V_210 ) ;
return V_61 ;
}
static unsigned int F_98 ( unsigned char V_70 ,
unsigned char V_132 )
{
unsigned int V_61 = 0 ;
switch ( V_70 ) {
case V_235 :
case V_236 :
case V_129 :
case V_134 :
case V_237 :
case V_238 :
case V_239 :
case V_240 :
V_61 = 1 ;
break;
case V_241 :
if ( V_132 == V_242 )
V_61 = 1 ;
break;
case V_173 :
if ( ( V_132 == V_243 ) ||
( V_132 == V_244 ) )
V_61 = 1 ;
break;
case V_245 :
if ( ( V_132 == V_246 ) ||
( V_132 == V_247 ) )
V_61 = 1 ;
break;
}
return V_61 ;
}
static int F_99 ( struct V_4 * V_5 ,
void T_7 * V_81 ,
T_10 * V_248 ,
int V_249 )
{
struct V_77 V_78 ;
struct V_77 * V_124 ;
T_6 * V_250 = NULL ;
T_6 * V_251 = NULL ;
T_5 V_252 = 0 ;
T_5 V_253 = 0 ;
T_5 V_254 = 0 ;
int V_255 = 0 ;
unsigned int V_256 = 0 ;
unsigned int V_257 = 0 ;
T_6 V_258 = 0 ;
unsigned int V_26 ;
unsigned int V_259 ;
unsigned int V_260 ;
unsigned long V_125 ;
int V_261 = V_249 + V_248 -> V_262 ;
int V_171 = 0 ;
V_257 = V_248 -> V_262 ;
V_256 = V_248 -> V_263 ;
if ( V_256 > 130560 || V_257 > 130560 ) {
V_255 = - V_200 ;
goto abort;
}
if ( V_257 ) {
V_250 = F_100 ( V_81 + V_249 , V_257 ) ;
if ( F_8 ( V_250 ) ) {
V_255 = F_101 ( V_250 ) ;
V_250 = NULL ;
goto abort;
}
V_252 = F_102 ( V_5 -> V_2 ,
V_250 ,
V_257 ,
V_264 ) ;
if ( F_103 ( V_5 -> V_2 , V_252 ) ) {
V_255 = - V_214 ;
goto abort;
}
V_254 = V_252 ;
}
if ( V_256 ) {
V_251 = F_100 ( V_81 + V_261 , V_256 ) ;
if ( F_8 ( V_251 ) ) {
V_255 = F_101 ( V_251 ) ;
V_251 = NULL ;
goto abort;
}
V_253 = F_102 ( V_5 -> V_2 ,
V_251 ,
V_256 , V_265 ) ;
if ( F_103 ( V_5 -> V_2 , V_253 ) ) {
V_255 = - V_214 ;
goto abort;
}
V_254 = V_253 ;
}
switch ( V_248 -> V_266 ) {
case V_267 :
V_258 = V_257 / V_194 ;
V_124 = ( V_5 -> V_23 -> V_126 + V_233 ) ;
break;
case V_268 :
V_124 = ( V_5 -> V_23 -> V_126 + V_233 ) ;
break;
case V_269 :
V_124 = ( V_5 -> V_23 -> V_126 + V_127 ) ;
break;
default:
V_255 = - V_200 ;
goto abort;
}
memset ( & V_78 , 0 , sizeof( struct V_77 ) ) ;
V_78 . type = 0x27 ;
V_78 . V_149 = 1 << 7 ;
V_78 . V_70 = V_248 -> V_270 [ 7 ] ;
V_78 . V_132 = V_248 -> V_270 [ 1 ] ;
V_78 . V_188 = V_248 -> V_270 [ 2 ] ;
V_78 . V_190 = V_248 -> V_270 [ 3 ] ;
V_78 . V_191 = V_248 -> V_270 [ 4 ] ;
V_78 . V_195 = V_248 -> V_270 [ 5 ] ;
V_78 . V_192 = V_248 -> V_270 [ 6 ] & ~ 0x10 ;
if ( ( V_248 -> V_271 . V_272 == 0 ) && ( V_248 -> V_273 . V_272 & 1 ) ) {
V_248 -> V_271 . V_272 =
V_274 |
( V_275 << 8 ) ;
V_78 . V_276 = V_248 -> V_277 [ 3 ] ;
V_78 . V_278 = V_248 -> V_277 [ 4 ] ;
V_78 . V_279 = V_248 -> V_277 [ 5 ] ;
V_78 . V_280 = V_248 -> V_277 [ 1 ] ;
V_78 . V_189 = V_248 -> V_277 [ 2 ] ;
} else {
V_248 -> V_271 . V_272 = V_274 ;
}
V_259 = F_98 ( V_78 . V_70 , V_78 . V_132 ) ;
if ( ( V_256 || V_257 ) && ( ! V_78 . V_188 ) ) {
if ( V_258 )
V_78 . V_188 = V_258 ;
else {
if ( ! V_259 ) {
F_5 ( & V_5 -> V_2 -> V_10 ,
L_67
L_68 ) ;
V_255 = - V_200 ;
goto abort;
}
}
}
F_44 ( V_88
L_69
L_70
L_71 ,
V_11 ,
V_78 . V_70 ,
V_78 . V_132 ,
V_78 . V_188 ,
V_78 . V_190 ,
V_78 . V_191 ,
V_78 . V_195 ,
V_78 . V_192 ) ;
if ( ( V_78 . V_70 == V_134 ) && V_250 &&
( V_250 [ 0 ] & V_281 ) ) {
V_171 = 1 ;
}
F_76 ( V_5 , & V_78 , & V_26 , V_171 ) ;
if ( V_259 )
V_260 = V_194 ;
else
V_260 = V_194 * V_78 . V_188 ;
if ( F_69 ( V_5 -> V_23 ,
& V_78 ,
5 ,
V_254 ,
V_260 ,
0 ,
V_143 ,
V_26 ) < 0 ) {
V_255 = - V_169 ;
goto abort;
}
V_125 = F_21 ( V_5 -> V_23 -> V_28 + V_128 ) ;
if ( ( V_248 -> V_266 == V_268 ) && ! ( V_125 & 1 ) ) {
V_124 = V_5 -> V_23 -> V_126 + V_233 ;
V_248 -> V_270 [ 7 ] = V_124 -> V_282 ;
} else {
V_124 = V_5 -> V_23 -> V_126 + V_127 ;
V_248 -> V_270 [ 7 ] = V_124 -> V_70 ;
}
if ( V_253 )
F_104 ( V_5 -> V_2 , V_253 ,
V_256 , V_265 ) ;
if ( V_252 )
F_104 ( V_5 -> V_2 , V_252 ,
V_257 , V_264 ) ;
V_253 = 0 ;
V_252 = 0 ;
V_248 -> V_270 [ 1 ] = V_124 -> V_132 ;
V_248 -> V_270 [ 2 ] = V_124 -> V_188 ;
V_248 -> V_270 [ 3 ] = V_124 -> V_190 ;
V_248 -> V_270 [ 4 ] = V_124 -> V_191 ;
V_248 -> V_270 [ 5 ] = V_124 -> V_195 ;
V_248 -> V_270 [ 6 ] = V_124 -> V_192 ;
if ( V_248 -> V_273 . V_272 & 1 ) {
V_248 -> V_277 [ 3 ] = V_124 -> V_276 ;
V_248 -> V_277 [ 4 ] = V_124 -> V_278 ;
V_248 -> V_277 [ 5 ] = V_124 -> V_279 ;
V_248 -> V_277 [ 1 ] = V_124 -> V_280 ;
V_248 -> V_277 [ 2 ] = V_124 -> V_189 ;
}
F_44 ( V_88
L_72
L_73
L_74 ,
V_11 ,
V_248 -> V_270 [ 7 ] ,
V_248 -> V_270 [ 1 ] ,
V_248 -> V_270 [ 2 ] ,
V_248 -> V_270 [ 3 ] ,
V_248 -> V_270 [ 4 ] ,
V_248 -> V_270 [ 5 ] ,
V_248 -> V_270 [ 6 ] ) ;
if ( V_257 ) {
if ( F_81 ( V_81 + V_249 , V_250 , V_257 ) ) {
V_255 = - V_62 ;
goto abort;
}
}
if ( V_256 ) {
if ( F_81 ( V_81 + V_261 , V_251 , V_256 ) ) {
V_255 = - V_62 ;
goto abort;
}
}
abort:
if ( V_253 )
F_104 ( V_5 -> V_2 , V_253 ,
V_256 , V_265 ) ;
if ( V_252 )
F_104 ( V_5 -> V_2 , V_252 ,
V_257 , V_264 ) ;
F_105 ( V_250 ) ;
F_105 ( V_251 ) ;
return V_255 ;
}
static int F_106 ( struct V_4 * V_5 , unsigned int V_16 ,
unsigned long V_283 )
{
switch ( V_16 ) {
case V_284 :
{
if ( F_81 ( ( void T_7 * ) V_283 , V_5 -> V_23 -> V_172 ,
sizeof( T_1 ) * V_178 ) )
return - V_62 ;
break;
}
case V_285 :
{
T_6 V_286 [ 4 ] ;
if ( F_107 ( V_286 ,
( void T_7 * ) V_283 ,
sizeof( V_286 ) ) )
return - V_62 ;
if ( F_97 ( V_5 -> V_23 ,
V_286 ,
( void T_7 * ) ( V_283 + 4 ) ) )
return - V_169 ;
if ( F_81 ( ( void T_7 * ) V_283 ,
V_286 ,
sizeof( V_286 ) ) )
return - V_62 ;
break;
}
case V_287 :
{
T_6 V_286 [ 7 ] ;
if ( F_107 ( V_286 ,
( void T_7 * ) V_283 ,
sizeof( V_286 ) ) )
return - V_62 ;
if ( F_96 ( V_5 -> V_23 , V_286 ) )
return - V_169 ;
if ( F_81 ( ( void T_7 * ) V_283 ,
V_286 ,
sizeof( V_286 ) ) )
return - V_62 ;
break;
}
case V_288 : {
T_10 V_248 ;
int V_289 , V_249 ;
if ( F_107 ( & V_248 , ( void T_7 * ) V_283 ,
sizeof( V_248 ) ) )
return - V_62 ;
V_249 = sizeof( V_248 ) ;
V_289 = F_99 ( V_5 , ( void T_7 * ) V_283 ,
& V_248 , V_249 ) ;
if ( F_81 ( ( void T_7 * ) V_283 , & V_248 ,
sizeof( V_248 ) ) )
return - V_62 ;
return V_289 ;
}
default:
return - V_200 ;
}
return 0 ;
}
static void F_108 ( struct V_4 * V_5 , struct V_13 * V_14 ,
struct V_12 * V_70 , int V_225 ,
struct V_18 * V_19 )
{
struct V_77 * V_78 ;
struct V_22 * V_23 = V_5 -> V_23 ;
int V_290 = F_109 ( V_14 ) == V_291 ? V_265 : V_264 ;
T_8 V_154 = F_110 ( V_14 ) ;
unsigned int V_258 = F_111 ( V_14 ) ;
V_225 = F_112 ( & V_5 -> V_2 -> V_10 , V_70 -> V_228 , V_225 , V_290 ) ;
F_113 ( & V_23 -> V_86 ) ;
V_70 -> V_292 = V_225 ;
V_70 -> V_98 = V_293 ;
V_78 = V_70 -> V_70 ;
V_78 -> type = 0x27 ;
V_78 -> V_149 = 1 << 7 ;
if ( V_290 == V_265 )
V_78 -> V_70 = V_294 ;
else
V_78 -> V_70 = V_96 ;
V_78 -> V_190 = V_154 & 0xFF ;
V_78 -> V_191 = ( V_154 >> 8 ) & 0xFF ;
V_78 -> V_195 = ( V_154 >> 16 ) & 0xFF ;
V_78 -> V_276 = ( V_154 >> 24 ) & 0xFF ;
V_78 -> V_278 = ( V_154 >> 32 ) & 0xFF ;
V_78 -> V_279 = ( V_154 >> 40 ) & 0xFF ;
V_78 -> V_192 = 1 << 6 ;
V_78 -> V_132 = V_258 & 0xFF ;
V_78 -> V_280 = ( V_258 >> 8 ) & 0xFF ;
V_78 -> V_188 = ( ( V_14 -> V_17 << 3 ) | ( V_14 -> V_17 >> 5 ) ) ;
V_78 -> V_189 = 0 ;
V_78 -> V_282 = 0 ;
V_78 -> V_295 = 0 ;
V_78 -> V_296 = 0 ;
F_93 ( V_5 , V_70 , V_225 ) ;
if ( F_17 ( V_70 -> V_297 ) )
V_78 -> V_192 |= 1 << 7 ;
V_70 -> V_157 -> V_149 =
V_158 F_71 (
( V_225 << 16 ) | 5 | V_298 ) ;
V_70 -> V_157 -> V_163 = 0 ;
V_70 -> V_73 = V_5 ;
V_70 -> V_74 = F_16 ;
V_70 -> V_299 = V_290 ;
if ( F_17 ( V_23 -> V_86 & V_300 ) ) {
F_4 ( V_14 -> V_17 , V_23 -> V_301 ) ;
F_4 ( V_142 , & V_23 -> V_86 ) ;
return;
}
F_26 ( V_23 , V_14 -> V_17 ) ;
}
static T_11 F_114 ( struct V_192 * V_10 ,
struct V_302 * V_303 ,
char * V_81 )
{
struct V_4 * V_5 = F_115 ( V_10 ) -> V_304 ;
int V_305 = 0 ;
if ( F_24 ( V_93 , & V_5 -> V_32 ) )
V_305 += sprintf ( V_81 , L_75 , L_76 ) ;
else if ( F_24 ( V_92 , & V_5 -> V_32 ) )
V_305 += sprintf ( V_81 , L_75 , L_77 ) ;
else
V_305 += sprintf ( V_81 , L_75 , L_78 ) ;
return V_305 ;
}
static T_11 F_116 ( struct V_306 * V_307 , char * V_81 )
{
int V_305 = 0 ;
struct V_4 * V_5 , * V_38 ;
unsigned long V_86 ;
char V_308 [ 42 ] ;
T_1 V_24 = 0 ;
F_117 ( & V_309 , V_86 ) ;
V_305 += sprintf ( & V_81 [ V_305 ] , L_79 ) ;
F_118 (dd, tmp, &online_list, online_list) {
if ( V_5 -> V_2 ) {
if ( V_5 -> V_23 &&
V_5 -> V_23 -> V_172 &&
V_5 -> V_23 -> V_177 ) {
F_92 ( V_308 ,
( char * ) ( V_5 -> V_23 -> V_172 + 10 ) , 21 ) ;
V_24 = * ( V_5 -> V_23 -> V_172 + 141 ) ;
} else {
memset ( V_308 , 0 , 42 ) ;
V_24 = 0 ;
}
if ( V_5 -> V_23 &&
F_24 ( V_310 , & V_5 -> V_23 -> V_86 ) ) {
V_305 += sprintf ( & V_81 [ V_305 ] ,
L_80 ,
F_119 ( & V_5 -> V_2 -> V_10 ) ,
V_308 ,
V_24 ) ;
} else {
V_305 += sprintf ( & V_81 [ V_305 ] ,
L_81 ,
F_119 ( & V_5 -> V_2 -> V_10 ) ,
V_308 ) ;
}
}
}
V_305 += sprintf ( & V_81 [ V_305 ] , L_82 ) ;
F_118 (dd, tmp, &removing_list, remove_list) {
if ( V_5 -> V_2 ) {
if ( V_5 -> V_23 &&
V_5 -> V_23 -> V_172 &&
V_5 -> V_23 -> V_177 ) {
F_92 ( V_308 ,
( char * ) ( V_5 -> V_23 -> V_172 + 10 ) , 21 ) ;
V_24 = * ( V_5 -> V_23 -> V_172 + 141 ) ;
} else {
memset ( V_308 , 0 , 42 ) ;
V_24 = 0 ;
}
if ( V_5 -> V_23 &&
F_24 ( V_310 , & V_5 -> V_23 -> V_86 ) ) {
V_305 += sprintf ( & V_81 [ V_305 ] ,
L_80 ,
F_119 ( & V_5 -> V_2 -> V_10 ) ,
V_308 ,
V_24 ) ;
} else {
V_305 += sprintf ( & V_81 [ V_305 ] ,
L_81 ,
F_119 ( & V_5 -> V_2 -> V_10 ) ,
V_308 ) ;
}
}
}
F_120 ( & V_309 , V_86 ) ;
return V_305 ;
}
static T_11 F_121 ( struct V_311 * V_312 , char T_7 * V_313 ,
T_12 V_170 , T_13 * V_314 )
{
struct V_4 * V_5 = (struct V_4 * ) V_312 -> V_304 ;
int V_305 = * V_314 ;
char * V_81 ;
int V_61 = 0 ;
if ( ! V_170 || * V_314 )
return 0 ;
V_81 = F_122 ( V_315 , V_143 ) ;
if ( ! V_81 ) {
F_37 ( & V_5 -> V_2 -> V_10 ,
L_83 ) ;
return - V_214 ;
}
V_305 += F_116 ( NULL , V_81 ) ;
* V_314 = V_305 <= V_170 ? V_305 : V_170 ;
V_305 = F_81 ( V_313 , V_81 , * V_314 ) ;
if ( V_305 )
V_61 = - V_62 ;
F_105 ( V_81 ) ;
return V_61 ? V_61 : * V_314 ;
}
static T_11 F_123 ( struct V_311 * V_312 , char T_7 * V_313 ,
T_12 V_170 , T_13 * V_314 )
{
struct V_4 * V_5 = (struct V_4 * ) V_312 -> V_304 ;
char * V_81 ;
T_2 V_316 ;
int V_305 = * V_314 ;
int V_139 , V_61 = 0 ;
if ( ! V_170 || V_305 )
return 0 ;
V_81 = F_122 ( V_315 , V_143 ) ;
if ( ! V_81 ) {
F_37 ( & V_5 -> V_2 -> V_10 ,
L_84 ) ;
return - V_214 ;
}
V_305 += sprintf ( & V_81 [ V_305 ] , L_85 ) ;
for ( V_139 = V_5 -> V_53 - 1 ; V_139 >= 0 ; V_139 -- )
V_305 += sprintf ( & V_81 [ V_305 ] , L_86 ,
F_21 ( V_5 -> V_23 -> V_35 [ V_139 ] ) ) ;
V_305 += sprintf ( & V_81 [ V_305 ] , L_87 ) ;
V_305 += sprintf ( & V_81 [ V_305 ] , L_88 ) ;
for ( V_139 = V_5 -> V_53 - 1 ; V_139 >= 0 ; V_139 -- )
V_305 += sprintf ( & V_81 [ V_305 ] , L_86 ,
F_21 ( V_5 -> V_23 -> V_36 [ V_139 ] ) ) ;
V_305 += sprintf ( & V_81 [ V_305 ] , L_87 ) ;
V_305 += sprintf ( & V_81 [ V_305 ] , L_89 ) ;
for ( V_139 = V_5 -> V_53 - 1 ; V_139 >= 0 ; V_139 -- )
V_305 += sprintf ( & V_81 [ V_305 ] , L_86 ,
F_21 ( V_5 -> V_23 -> V_54 [ V_139 ] ) ) ;
V_305 += sprintf ( & V_81 [ V_305 ] , L_87 ) ;
V_305 += sprintf ( & V_81 [ V_305 ] , L_90 ,
F_21 ( V_5 -> V_23 -> V_28 + V_55 ) ) ;
V_305 += sprintf ( & V_81 [ V_305 ] , L_91 ,
F_21 ( V_5 -> V_28 + V_56 ) ) ;
V_305 += sprintf ( & V_81 [ V_305 ] , L_92 ) ;
V_305 += sprintf ( & V_81 [ V_305 ] , L_93 ) ;
for ( V_139 = V_5 -> V_53 - 1 ; V_139 >= 0 ; V_139 -- ) {
if ( sizeof( long ) > sizeof( T_2 ) )
V_316 =
V_5 -> V_23 -> V_301 [ V_139 / 2 ] >> ( 32 * ( V_139 & 1 ) ) ;
else
V_316 = V_5 -> V_23 -> V_301 [ V_139 ] ;
V_305 += sprintf ( & V_81 [ V_305 ] , L_86 , V_316 ) ;
}
V_305 += sprintf ( & V_81 [ V_305 ] , L_87 ) ;
* V_314 = V_305 <= V_170 ? V_305 : V_170 ;
V_305 = F_81 ( V_313 , V_81 , * V_314 ) ;
if ( V_305 )
V_61 = - V_62 ;
F_105 ( V_81 ) ;
return V_61 ? V_61 : * V_314 ;
}
static T_11 F_124 ( struct V_311 * V_312 , char T_7 * V_313 ,
T_12 V_170 , T_13 * V_314 )
{
struct V_4 * V_5 = (struct V_4 * ) V_312 -> V_304 ;
char * V_81 ;
int V_305 = * V_314 ;
int V_61 = 0 ;
if ( ! V_170 || V_305 )
return 0 ;
V_81 = F_122 ( V_315 , V_143 ) ;
if ( ! V_81 ) {
F_37 ( & V_5 -> V_2 -> V_10 ,
L_94 ) ;
return - V_214 ;
}
V_305 += sprintf ( & V_81 [ V_305 ] , L_95 ,
V_5 -> V_23 -> V_86 ) ;
V_305 += sprintf ( & V_81 [ V_305 ] , L_96 ,
V_5 -> V_32 ) ;
* V_314 = V_305 <= V_170 ? V_305 : V_170 ;
V_305 = F_81 ( V_313 , V_81 , * V_314 ) ;
if ( V_305 )
V_61 = - V_62 ;
F_105 ( V_81 ) ;
return V_61 ? V_61 : * V_314 ;
}
static int F_125 ( struct V_4 * V_5 , struct V_317 * V_318 )
{
if ( ! V_318 || ! V_5 )
return - V_200 ;
if ( F_126 ( V_318 , & V_319 . V_303 ) )
F_5 ( & V_5 -> V_2 -> V_10 ,
L_97 ) ;
return 0 ;
}
static int F_127 ( struct V_4 * V_5 , struct V_317 * V_318 )
{
if ( ! V_318 || ! V_5 )
return - V_200 ;
F_128 ( V_318 , & V_319 . V_303 ) ;
return 0 ;
}
static int F_129 ( struct V_4 * V_5 )
{
if ( ! V_320 )
return - 1 ;
V_5 -> V_321 = F_130 ( V_5 -> V_322 -> V_323 , V_320 ) ;
if ( F_131 ( V_5 -> V_321 ) ) {
F_5 ( & V_5 -> V_2 -> V_10 ,
L_98 ,
V_5 -> V_322 -> V_323 ) ;
V_5 -> V_321 = NULL ;
return - 1 ;
}
F_132 ( L_99 , V_324 , V_5 -> V_321 , V_5 ,
& V_325 ) ;
F_132 ( L_100 , V_324 , V_5 -> V_321 , V_5 ,
& V_326 ) ;
return 0 ;
}
static void F_133 ( struct V_4 * V_5 )
{
if ( V_5 -> V_321 )
F_134 ( V_5 -> V_321 ) ;
}
static inline void F_135 ( struct V_4 * V_5 )
{
T_2 V_327 ;
V_327 = F_21 ( V_5 -> V_28 + V_328 ) ;
F_20 ( V_327 |
V_329 |
V_330 ,
V_5 -> V_28 + V_328 ) ;
}
static int F_136 ( struct V_4 * V_5 )
{
return ( V_5 -> V_2 -> V_192 == V_331 ? 1 : 0 ) ;
}
static void F_137 ( struct V_4 * V_5 )
{
T_2 V_327 ;
unsigned int V_332 , V_333 ;
V_327 = F_21 ( V_5 -> V_28 + V_328 ) ;
V_5 -> V_334 = V_335 ;
V_5 -> V_53 = 1 ;
if ( V_327 & 0x8 ) {
V_5 -> V_334 = V_336 ;
V_332 = ( V_327 & V_337 ) >> 8 ;
V_333 = ( V_327 & V_338 ) + 1 ;
F_47 ( & V_5 -> V_2 -> V_10 ,
L_101
L_102 ,
V_332 ,
V_333 ,
V_333 * 32 ) ;
if ( V_333 > V_116 ) {
F_5 ( & V_5 -> V_2 -> V_10 ,
L_103
L_104 , V_116 ) ;
V_333 = V_116 ;
}
V_5 -> V_53 = V_333 ;
return;
}
F_5 ( & V_5 -> V_2 -> V_10 , L_105 ) ;
}
static int F_138 ( struct V_4 * V_5 )
{
unsigned long V_26 , V_66 = 0 , V_154 ;
F_5 ( & V_5 -> V_2 -> V_10 ,
L_106 ) ;
V_154 = V_30 ;
V_26 = V_30 + F_22 ( V_339 ) ;
do {
if ( F_17 ( F_24 ( V_31 ,
& V_5 -> V_32 ) ) )
return - V_62 ;
if ( F_1 ( V_5 -> V_2 ) )
return - V_62 ;
if ( F_77 ( V_5 -> V_23 , NULL ) < 0 )
return - V_62 ;
if ( * ( V_5 -> V_23 -> V_172 + V_340 ) ==
V_341 ) {
F_139 ( 1 ) ;
if ( V_66 ++ >= 180 ) {
F_5 ( & V_5 -> V_2 -> V_10 ,
L_107 ,
F_73 ( V_30 - V_154 ) / 1000 ) ;
V_66 = 0 ;
}
} else {
F_5 ( & V_5 -> V_2 -> V_10 ,
L_108 ,
F_73 ( V_30 - V_154 ) / 1000 ) ;
F_140 ( V_5 ) ;
return 0 ;
}
} while ( F_25 ( V_30 , V_26 ) );
F_37 ( & V_5 -> V_2 -> V_10 ,
L_109 ,
F_73 ( V_30 - V_154 ) / 1000 ) ;
return - V_62 ;
}
static void F_141 ( struct V_13 * V_14 )
{
struct V_12 * V_16 = F_9 ( V_14 ) ;
struct V_4 * V_5 = V_14 -> V_342 -> V_343 ;
F_142 ( & V_5 -> V_2 -> V_10 , V_16 -> V_228 , V_16 -> V_292 ,
V_16 -> V_299 ) ;
if ( F_17 ( V_16 -> V_297 ) )
F_143 ( & V_5 -> V_23 -> V_344 ) ;
F_144 ( V_14 , V_14 -> V_345 ) ;
}
static void F_145 ( struct V_13 * V_346 , void * V_107 ,
bool V_347 )
{
struct V_4 * V_5 = V_107 ;
F_44 ( V_88 L_110 , V_346 -> V_17 ) ;
F_62 ( V_346 -> V_17 , V_5 -> V_23 -> V_301 ) ;
V_346 -> V_345 = - V_169 ;
F_141 ( V_346 ) ;
}
static void F_146 ( struct V_13 * V_346 , void * V_107 ,
bool V_347 )
{
struct V_4 * V_5 = V_107 ;
F_4 ( V_346 -> V_17 , V_5 -> V_23 -> V_301 ) ;
F_147 ( V_346 ) ;
}
static int F_148 ( void * V_107 )
{
struct V_4 * V_5 = (struct V_4 * ) V_107 ;
unsigned long V_348 , V_349 , V_350 , V_138 ;
unsigned int V_351 = V_5 -> V_53 * 32 ;
struct V_22 * V_23 = V_5 -> V_23 ;
while ( 1 ) {
if ( F_149 () ||
F_24 ( V_352 , & V_23 -> V_86 ) )
goto V_353;
F_62 ( V_141 , & V_23 -> V_86 ) ;
F_150 ( V_23 -> V_106 , ( V_23 -> V_86 ) &&
( V_23 -> V_86 & V_354 ) ) ;
if ( F_149 () ||
F_24 ( V_352 , & V_23 -> V_86 ) )
goto V_353;
if ( F_17 ( F_24 ( V_31 ,
& V_5 -> V_32 ) ) )
goto V_353;
F_4 ( V_141 , & V_23 -> V_86 ) ;
V_355:
if ( F_24 ( V_105 , & V_23 -> V_86 ) ) {
F_43 ( V_5 ) ;
F_62 ( V_105 , & V_23 -> V_86 ) ;
}
if ( F_24 ( V_105 , & V_23 -> V_86 ) )
goto V_355;
if ( F_24 ( V_356 , & V_23 -> V_86 ) ) {
V_138 = V_30 + F_22 ( 5000 ) ;
do {
F_23 ( 100 ) ;
} while ( F_56 ( & V_5 -> V_99 ) != 0 &&
F_25 ( V_30 , V_138 ) );
if ( F_56 ( & V_5 -> V_99 ) != 0 )
F_5 ( & V_5 -> V_2 -> V_10 ,
L_111 ) ;
F_27 ( V_5 -> V_7 -> V_357 ) ;
F_151 ( & V_5 -> V_21 ,
F_146 , V_5 ) ;
F_30 ( V_5 -> V_7 -> V_357 ) ;
F_4 ( V_142 , & V_5 -> V_23 -> V_86 ) ;
if ( F_38 ( V_5 ) )
F_151 ( & V_5 -> V_21 ,
F_145 , V_5 ) ;
F_62 ( V_356 , & V_5 -> V_23 -> V_86 ) ;
}
if ( F_24 ( V_142 , & V_23 -> V_86 ) ) {
V_348 = 1 ;
V_349 = V_351 ;
V_350 = 0 ;
while ( 1 ) {
V_348 = F_152 ( V_23 -> V_301 ,
V_351 , V_348 ) ;
if ( V_350 == 1 ) {
if ( ( V_349 >= V_348 ) ||
( V_348 >= V_351 ) )
break;
}
if ( F_17 ( V_349 == V_351 ) )
V_349 = V_348 ;
if ( F_17 ( V_348 == V_351 ) ) {
V_348 = 1 ;
V_350 = 1 ;
continue;
}
F_26 ( V_23 , V_348 ) ;
F_62 ( V_348 , V_23 -> V_301 ) ;
}
F_62 ( V_142 , & V_23 -> V_86 ) ;
}
if ( F_24 ( V_310 , & V_23 -> V_86 ) ) {
if ( F_138 ( V_5 ) == 0 )
F_62 ( V_310 , & V_23 -> V_86 ) ;
}
}
V_353:
return 0 ;
}
static void F_153 ( struct V_4 * V_5 )
{
struct V_22 * V_23 = V_5 -> V_23 ;
if ( V_23 -> V_358 )
F_89 ( & V_5 -> V_2 -> V_10 , V_359 ,
V_23 -> V_358 , V_23 -> V_360 ) ;
if ( V_23 -> V_361 ) {
F_89 ( & V_5 -> V_2 -> V_10 , V_362 ,
V_23 -> V_361 , V_23 -> V_46 ) ;
}
}
static int F_154 ( struct V_4 * V_5 )
{
struct V_22 * V_23 = V_5 -> V_23 ;
V_23 -> V_358 =
F_87 ( & V_5 -> V_2 -> V_10 , V_359 ,
& V_23 -> V_360 , V_143 ) ;
if ( ! V_23 -> V_358 )
return - V_214 ;
memset ( V_23 -> V_358 , 0 , V_359 ) ;
V_23 -> V_361 =
F_87 ( & V_5 -> V_2 -> V_10 , V_362 ,
& V_23 -> V_46 , V_143 ) ;
if ( ! V_23 -> V_361 ) {
F_89 ( & V_5 -> V_2 -> V_10 , V_359 ,
V_23 -> V_358 , V_23 -> V_360 ) ;
V_23 -> V_358 = NULL ;
V_23 -> V_360 = 0 ;
return - V_214 ;
}
memset ( V_23 -> V_361 , 0 , V_362 ) ;
V_23 -> V_126 = V_23 -> V_358 + V_363 ;
V_23 -> V_48 = V_23 -> V_360 + V_363 ;
V_23 -> V_172 = V_23 -> V_358 + V_364 ;
V_23 -> V_179 = V_23 -> V_360 + V_364 ;
V_23 -> V_90 = V_23 -> V_358 + V_365 ;
V_23 -> V_91 = V_23 -> V_360 + V_365 ;
V_23 -> V_202 = V_23 -> V_358 + V_366 ;
V_23 -> V_203 = V_23 -> V_360 + V_366 ;
return 0 ;
}
static int F_155 ( struct V_4 * V_5 )
{
struct V_197 V_367 ;
unsigned char * V_81 ;
int V_61 ;
if ( F_77 ( V_5 -> V_23 , NULL ) < 0 )
return - V_62 ;
if ( * ( V_5 -> V_23 -> V_172 + V_340 ) ==
V_341 ) {
F_4 ( V_310 , & V_5 -> V_23 -> V_86 ) ;
return V_341 ;
}
F_91 ( V_5 -> V_23 ) ;
V_61 = F_46 ( V_5 -> V_23 , V_89 ,
V_5 -> V_23 -> V_90 ,
V_5 -> V_23 -> V_91 , 1 ) ;
if ( V_61 ) {
F_5 ( & V_5 -> V_2 -> V_10 ,
L_15 ) ;
} else {
V_81 = ( unsigned char * ) V_5 -> V_23 -> V_90 ;
if ( V_81 [ 259 ] & 0x1 ) {
F_47 ( & V_5 -> V_2 -> V_10 ,
L_16 ) ;
F_4 ( V_92 , & V_5 -> V_32 ) ;
}
if ( V_81 [ 288 ] == 0xF7 ) {
F_47 ( & V_5 -> V_2 -> V_10 ,
L_18 ) ;
F_4 ( V_93 , & V_5 -> V_32 ) ;
}
if ( V_81 [ 288 ] == 0xBF ) {
F_47 ( & V_5 -> V_2 -> V_10 ,
L_112 ) ;
F_4 ( V_94 , & V_5 -> V_32 ) ;
}
}
memset ( & V_367 , 0 , sizeof( struct V_197 ) ) ;
if ( F_84 ( V_5 -> V_23 , 242 , & V_367 ) )
F_5 ( & V_5 -> V_2 -> V_10 ,
L_113 ) ;
else
F_47 ( & V_5 -> V_2 -> V_10 ,
L_114 ,
V_367 . V_368 , F_156 ( V_367 . V_107 ) ) ;
return V_61 ;
}
static int F_157 ( struct V_4 * V_5 )
{
int V_43 ;
int V_61 ;
unsigned int V_369 ;
unsigned long V_26 , V_370 ;
V_5 -> V_28 = F_158 ( V_5 -> V_2 ) [ V_371 ] ;
F_137 ( V_5 ) ;
if ( V_5 -> V_334 == V_335 ) {
V_61 = - V_169 ;
goto V_372;
}
V_369 = V_5 -> V_53 * 32 ;
F_135 ( V_5 ) ;
V_5 -> V_23 = F_159 ( sizeof( struct V_22 ) , V_143 ,
V_5 -> V_373 ) ;
if ( ! V_5 -> V_23 ) {
F_37 ( & V_5 -> V_2 -> V_10 ,
L_115 ) ;
return - V_214 ;
}
for ( V_43 = 0 ; V_43 < V_116 ; V_43 ++ )
V_5 -> V_117 [ V_43 ] . V_23 = V_5 -> V_23 ;
if ( F_136 ( V_5 ) )
V_5 -> V_374 = V_375 ;
else
V_5 -> V_374 = 0 ;
F_160 ( & V_5 -> V_23 -> V_344 , V_5 -> V_374 ) ;
for ( V_43 = 0 ; V_43 < V_116 ; V_43 ++ )
F_161 ( & V_5 -> V_23 -> V_34 [ V_43 ] ) ;
V_5 -> V_23 -> V_28 = V_5 -> V_28 + V_376 ;
V_5 -> V_23 -> V_5 = V_5 ;
V_61 = F_154 ( V_5 ) ;
if ( V_61 < 0 )
goto V_372;
for ( V_43 = 0 ; V_43 < V_5 -> V_53 ; V_43 ++ ) {
V_5 -> V_23 -> V_35 [ V_43 ] =
V_5 -> V_23 -> V_28 + V_43 * 0x80 + V_377 ;
V_5 -> V_23 -> V_36 [ V_43 ] =
V_5 -> V_23 -> V_28 + V_43 * 0x80 + V_378 ;
V_5 -> V_23 -> V_54 [ V_43 ] =
V_5 -> V_23 -> V_28 + V_43 * 0x80 + V_379 ;
}
V_370 = V_30 ;
V_26 = V_30 + F_22 ( 30000 ) ;
while ( ( ( F_21 ( V_5 -> V_23 -> V_28 + V_60 ) & 0x0F ) != 0x03 ) &&
F_25 ( V_30 , V_26 ) ) {
F_23 ( 100 ) ;
}
if ( F_17 ( F_1 ( V_5 -> V_2 ) ) ) {
V_370 = V_30 - V_370 ;
F_5 ( & V_5 -> V_2 -> V_10 ,
L_116 ,
F_73 ( V_370 ) ) ;
V_61 = - V_380 ;
goto V_381 ;
}
if ( F_17 ( F_24 ( V_31 , & V_5 -> V_32 ) ) ) {
V_370 = V_30 - V_370 ;
F_5 ( & V_5 -> V_2 -> V_10 ,
L_117 ,
F_73 ( V_370 ) ) ;
V_61 = - V_62 ;
goto V_381;
}
if ( ! ( F_21 ( V_5 -> V_28 + V_44 ) & V_382 ) ) {
if ( F_19 ( V_5 ) < 0 ) {
F_37 ( & V_5 -> V_2 -> V_10 ,
L_118 ) ;
V_61 = - V_169 ;
goto V_381;
}
} else {
F_20 ( F_21 ( V_5 -> V_28 + V_56 ) ,
V_5 -> V_28 + V_56 ) ;
}
F_35 ( V_5 -> V_23 ) ;
F_33 ( V_5 -> V_23 ) ;
V_61 = F_162 ( & V_5 -> V_2 -> V_10 ,
V_5 -> V_2 -> V_122 ,
F_59 ,
V_383 ,
F_163 ( & V_5 -> V_2 -> V_10 ) ,
V_5 ) ;
if ( V_61 ) {
F_37 ( & V_5 -> V_2 -> V_10 ,
L_119 , V_5 -> V_2 -> V_122 ) ;
goto V_381;
}
F_164 ( V_5 -> V_2 -> V_122 , F_165 ( V_5 -> V_384 ) ) ;
F_20 ( F_21 ( V_5 -> V_28 + V_29 ) | V_63 ,
V_5 -> V_28 + V_29 ) ;
F_166 ( & V_5 -> V_23 -> V_106 ) ;
if ( F_24 ( V_31 , & V_5 -> V_32 ) ) {
V_61 = - V_62 ;
goto V_385;
}
return V_61 ;
V_385:
F_20 ( F_21 ( V_5 -> V_28 + V_29 ) & ~ V_63 ,
V_5 -> V_28 + V_29 ) ;
F_164 ( V_5 -> V_2 -> V_122 , NULL ) ;
F_167 ( & V_5 -> V_2 -> V_10 , V_5 -> V_2 -> V_122 , V_5 ) ;
V_381:
F_34 ( V_5 -> V_23 ) ;
F_153 ( V_5 ) ;
V_372:
F_105 ( V_5 -> V_23 ) ;
return V_61 ;
}
static int F_168 ( struct V_4 * V_5 )
{
int V_61 = 0 ;
if ( V_5 -> V_6 || ! V_5 -> V_23 )
return - V_380 ;
if ( ! F_24 ( V_310 , & V_5 -> V_23 -> V_86 ) &&
! F_24 ( V_94 , & V_5 -> V_32 ) &&
! F_24 ( V_135 , & V_5 -> V_32 ) ) {
V_61 = F_82 ( V_5 -> V_23 ) ;
if ( V_61 )
F_5 ( & V_5 -> V_2 -> V_10 ,
L_120 ) ;
}
return V_61 ;
}
static int F_169 ( struct V_4 * V_5 )
{
if ( ! V_5 -> V_6 ) {
F_34 ( V_5 -> V_23 ) ;
F_20 ( F_21 ( V_5 -> V_28 + V_29 ) & ~ V_63 ,
V_5 -> V_28 + V_29 ) ;
}
F_164 ( V_5 -> V_2 -> V_122 , NULL ) ;
F_167 ( & V_5 -> V_2 -> V_10 , V_5 -> V_2 -> V_122 , V_5 ) ;
F_65 ( 1000 ) ;
F_153 ( V_5 ) ;
F_105 ( V_5 -> V_23 ) ;
V_5 -> V_23 = NULL ;
return 0 ;
}
static int F_170 ( struct V_4 * V_5 )
{
F_168 ( V_5 ) ;
return 0 ;
}
static int F_171 ( struct V_4 * V_5 )
{
if ( F_168 ( V_5 ) != 0 ) {
F_37 ( & V_5 -> V_2 -> V_10 ,
L_121 ) ;
return - V_62 ;
}
F_20 ( F_21 ( V_5 -> V_28 + V_29 ) & ~ V_63 ,
V_5 -> V_28 + V_29 ) ;
F_34 ( V_5 -> V_23 ) ;
return 0 ;
}
static int F_172 ( struct V_4 * V_5 )
{
F_135 ( V_5 ) ;
if ( F_19 ( V_5 ) != 0 ) {
F_37 ( & V_5 -> V_2 -> V_10 ,
L_122 ) ;
return - V_62 ;
}
F_35 ( V_5 -> V_23 ) ;
F_33 ( V_5 -> V_23 ) ;
F_20 ( F_21 ( V_5 -> V_28 + V_29 ) | V_63 ,
V_5 -> V_28 + V_29 ) ;
return 0 ;
}
static int F_173 ( char * V_386 ,
int V_387 ,
char * V_81 ,
int V_388 )
{
const int V_389 = 'z' - 'a' + 1 ;
char * V_390 = V_81 + strlen ( V_386 ) ;
char * V_391 = V_81 + V_388 ;
char * V_392 ;
int V_393 ;
V_392 = V_391 - 1 ;
* V_392 = '\0' ;
V_393 = V_389 ;
do {
if ( V_392 == V_390 )
return - V_200 ;
* -- V_392 = 'a' + ( V_387 % V_393 ) ;
V_387 = ( V_387 / V_393 ) - 1 ;
} while ( V_387 >= 0 );
memmove ( V_390 , V_392 , V_391 - V_392 ) ;
memcpy ( V_81 , V_386 , strlen ( V_386 ) ) ;
return 0 ;
}
static int F_174 ( struct V_394 * V_10 ,
T_14 V_395 ,
unsigned V_16 ,
unsigned long V_283 )
{
struct V_4 * V_5 = V_10 -> V_396 -> V_304 ;
if ( ! F_175 ( V_397 ) )
return - V_398 ;
if ( ! V_5 )
return - V_399 ;
if ( F_17 ( F_24 ( V_31 , & V_5 -> V_32 ) ) )
return - V_399 ;
switch ( V_16 ) {
case V_400 :
return - V_399 ;
default:
return F_106 ( V_5 , V_16 , V_283 ) ;
}
}
static int F_176 ( struct V_394 * V_10 ,
T_14 V_395 ,
unsigned V_16 ,
unsigned long V_283 )
{
struct V_4 * V_5 = V_10 -> V_396 -> V_304 ;
if ( ! F_175 ( V_397 ) )
return - V_398 ;
if ( ! V_5 )
return - V_399 ;
if ( F_17 ( F_24 ( V_31 , & V_5 -> V_32 ) ) )
return - V_399 ;
switch ( V_16 ) {
case V_400 :
return - V_399 ;
case V_288 : {
struct V_401 T_7 * V_402 ;
T_10 V_248 ;
int V_403 , V_249 , V_289 ;
V_403 =
sizeof( struct V_401 ) ;
V_402 =
(struct V_401 T_7 * ) V_283 ;
if ( F_107 ( & V_248 , ( void T_7 * ) V_283 ,
V_403 - ( 2 * sizeof( V_404 ) ) ) )
return - V_62 ;
if ( F_177 ( V_248 . V_262 , & V_402 -> V_262 ) )
return - V_62 ;
if ( F_177 ( V_248 . V_263 , & V_402 -> V_263 ) )
return - V_62 ;
V_249 = sizeof( struct V_401 ) ;
V_289 = F_99 ( V_5 , ( void T_7 * ) V_283 ,
& V_248 , V_249 ) ;
if ( F_81 ( ( void T_7 * ) V_283 , & V_248 ,
V_403 -
( 2 * sizeof( V_404 ) ) ) )
return - V_62 ;
if ( F_178 ( V_248 . V_262 , & V_402 -> V_262 ) )
return - V_62 ;
if ( F_178 ( V_248 . V_263 , & V_402 -> V_263 ) )
return - V_62 ;
return V_289 ;
}
default:
return F_106 ( V_5 , V_16 , V_283 ) ;
}
}
static int F_179 ( struct V_394 * V_10 ,
struct V_405 * V_406 )
{
struct V_4 * V_5 = V_10 -> V_396 -> V_304 ;
T_9 V_407 ;
if ( ! V_5 )
return - V_399 ;
if ( ! ( F_90 ( V_5 , & V_407 ) ) ) {
F_5 ( & V_5 -> V_2 -> V_10 ,
L_123 ) ;
return - V_399 ;
}
V_406 -> V_408 = 224 ;
V_406 -> V_186 = 56 ;
F_180 ( V_407 , ( V_406 -> V_408 * V_406 -> V_186 ) ) ;
V_406 -> V_409 = V_407 ;
return 0 ;
}
static int F_181 ( struct V_394 * V_10 , T_14 V_395 )
{
struct V_4 * V_5 ;
if ( V_10 && V_10 -> V_396 ) {
V_5 = (struct V_4 * ) V_10 -> V_396 -> V_304 ;
if ( V_5 ) {
if ( F_24 ( V_410 ,
& V_5 -> V_32 ) ) {
return - V_380 ;
}
return 0 ;
}
}
return - V_380 ;
}
void F_182 ( struct V_411 * V_322 , T_14 V_395 )
{
}
static inline bool F_183 ( struct V_4 * V_5 )
{
if ( F_17 ( F_24 ( V_136 , & V_5 -> V_23 -> V_86 ) ) ) {
if ( V_5 -> V_23 -> V_130 ) {
unsigned long V_138 = V_5 -> V_23 -> V_130 +
F_22 ( 1000 ) ;
if ( F_184 ( V_30 , V_138 ) ) {
F_62 ( V_136 ,
& V_5 -> V_23 -> V_86 ) ;
F_62 ( V_135 , & V_5 -> V_32 ) ;
V_5 -> V_23 -> V_130 = 0 ;
F_54 ( & V_5 -> V_23 -> V_106 ) ;
return false ;
}
}
return true ;
}
return false ;
}
static int F_185 ( struct V_18 * V_19 , struct V_13 * V_14 )
{
struct V_4 * V_5 = V_19 -> V_7 -> V_343 ;
struct V_12 * V_16 = F_9 ( V_14 ) ;
unsigned int V_225 ;
if ( F_183 ( V_5 ) )
return - V_97 ;
if ( F_17 ( V_5 -> V_32 & V_412 ) ) {
if ( F_17 ( F_24 ( V_31 ,
& V_5 -> V_32 ) ) ) {
return - V_167 ;
}
if ( F_17 ( F_24 ( V_93 , & V_5 -> V_32 ) ) ) {
return - V_97 ;
}
if ( F_17 ( F_24 ( V_92 ,
& V_5 -> V_32 ) &&
F_109 ( V_14 ) ) ) {
return - V_97 ;
}
if ( F_17 ( F_24 ( V_135 , & V_5 -> V_32 ) ||
F_24 ( V_94 , & V_5 -> V_32 ) ) )
return - V_97 ;
}
if ( V_14 -> V_413 & V_414 ) {
int V_255 ;
V_255 = F_85 ( V_5 , F_110 ( V_14 ) , F_111 ( V_14 ) ) ;
F_144 ( V_14 , V_255 ) ;
return 0 ;
}
V_225 = F_186 ( V_19 -> V_7 , V_14 , V_16 -> V_228 ) ;
F_108 ( V_5 , V_14 , V_16 , V_225 , V_19 ) ;
return 0 ;
}
static bool F_187 ( struct V_18 * V_19 ,
struct V_13 * V_14 )
{
struct V_4 * V_5 = V_19 -> V_7 -> V_343 ;
struct V_12 * V_16 = F_9 ( V_14 ) ;
if ( F_109 ( V_14 ) == V_291 || ! V_5 -> V_374 )
return false ;
if ( F_111 ( V_14 ) <= 64 ) {
if ( ( F_110 ( V_14 ) & 7 ) || ( F_111 ( V_14 ) & 7 ) )
V_16 -> V_297 = 1 ;
}
if ( V_16 -> V_297 && F_188 ( & V_5 -> V_23 -> V_344 ) )
return true ;
return false ;
}
static int F_189 ( struct V_18 * V_19 ,
const struct V_415 * V_416 )
{
struct V_13 * V_14 = V_416 -> V_14 ;
int V_289 ;
if ( F_17 ( F_187 ( V_19 , V_14 ) ) )
return V_417 ;
F_190 ( V_14 ) ;
V_289 = F_185 ( V_19 , V_14 ) ;
if ( F_45 ( ! V_289 ) )
return V_418 ;
V_14 -> V_345 = V_289 ;
return V_419 ;
}
static void F_191 ( void * V_107 , struct V_13 * V_14 ,
unsigned int V_420 , unsigned int V_421 )
{
struct V_4 * V_5 = V_107 ;
struct V_12 * V_16 = F_9 ( V_14 ) ;
if ( ! V_16 -> V_70 )
return;
F_89 ( & V_5 -> V_2 -> V_10 , V_422 ,
V_16 -> V_70 , V_16 -> V_423 ) ;
}
static int F_192 ( void * V_107 , struct V_13 * V_14 , unsigned int V_420 ,
unsigned int V_421 , unsigned int V_373 )
{
struct V_4 * V_5 = V_107 ;
struct V_12 * V_16 = F_9 ( V_14 ) ;
T_2 V_424 = F_21 ( V_5 -> V_28 + V_44 ) & V_45 ;
if ( V_421 >= V_425 )
return 0 ;
V_16 -> V_70 = F_87 ( & V_5 -> V_2 -> V_10 , V_422 ,
& V_16 -> V_423 , V_143 ) ;
if ( ! V_16 -> V_70 )
return - V_214 ;
memset ( V_16 -> V_70 , 0 , V_422 ) ;
V_16 -> V_157 = V_5 -> V_23 -> V_361 +
( sizeof( struct V_426 ) * V_421 ) ;
V_16 -> V_427 = V_5 -> V_23 -> V_46 +
( sizeof( struct V_426 ) * V_421 ) ;
if ( V_424 )
V_16 -> V_157 -> V_428 = V_158 F_71 ( ( V_16 -> V_423 >> 16 ) >> 16 ) ;
V_16 -> V_157 -> V_429 = V_158 F_71 ( V_16 -> V_423 & 0xFFFFFFFF ) ;
F_193 ( V_16 -> V_228 , V_430 ) ;
return 0 ;
}
static enum V_431 F_194 ( struct V_13 * V_346 ,
bool V_347 )
{
struct V_4 * V_5 = V_346 -> V_342 -> V_343 ;
if ( V_347 )
goto V_432;
if ( F_24 ( V_346 -> V_17 , V_5 -> V_23 -> V_301 ) )
goto V_432;
if ( F_195 ( V_356 , & V_5 -> V_23 -> V_86 ) )
goto V_432;
F_54 ( & V_5 -> V_23 -> V_106 ) ;
V_432:
return V_433 ;
}
static int F_140 ( struct V_4 * V_5 )
{
int V_61 = 0 , V_434 = 0 ;
T_9 V_407 ;
unsigned int V_387 = 0 ;
struct V_317 * V_318 ;
if ( V_5 -> V_322 )
goto V_435;
if ( F_157 ( V_5 ) ) {
V_61 = - V_200 ;
goto V_436;
}
V_5 -> V_322 = F_196 ( V_437 , V_5 -> V_373 ) ;
if ( V_5 -> V_322 == NULL ) {
F_37 ( & V_5 -> V_2 -> V_10 ,
L_124 ) ;
V_61 = - V_200 ;
goto V_438;
}
do {
if ( ! F_197 ( & V_439 , V_143 ) )
goto V_440;
F_27 ( & V_441 ) ;
V_61 = F_198 ( & V_439 , & V_387 ) ;
F_30 ( & V_441 ) ;
} while ( V_61 == - V_168 );
if ( V_61 )
goto V_440;
V_61 = F_173 ( L_125 ,
V_387 ,
V_5 -> V_322 -> V_323 ,
V_442 ) ;
if ( V_61 )
goto V_443;
V_5 -> V_322 -> V_444 = & V_5 -> V_2 -> V_10 ;
V_5 -> V_322 -> V_445 = V_5 -> V_445 ;
V_5 -> V_322 -> V_446 = V_387 * V_437 ;
V_5 -> V_322 -> V_447 = V_437 ;
V_5 -> V_322 -> V_448 = & V_449 ;
V_5 -> V_322 -> V_304 = V_5 ;
V_5 -> V_387 = V_387 ;
F_129 ( V_5 ) ;
memset ( & V_5 -> V_21 , 0 , sizeof( V_5 -> V_21 ) ) ;
V_5 -> V_21 . V_450 = & V_451 ;
V_5 -> V_21 . V_452 = 1 ;
V_5 -> V_21 . V_453 = V_425 ;
V_5 -> V_21 . V_454 = 1 ;
V_5 -> V_21 . V_455 = sizeof( struct V_12 ) ;
V_5 -> V_21 . V_373 = V_5 -> V_373 ;
V_5 -> V_21 . V_86 = V_456 ;
V_5 -> V_21 . V_4 = V_5 ;
V_5 -> V_21 . V_26 = V_457 ;
V_61 = F_199 ( & V_5 -> V_21 ) ;
if ( V_61 ) {
F_37 ( & V_5 -> V_2 -> V_10 ,
L_126 ) ;
goto V_458;
}
V_5 -> V_7 = F_200 ( & V_5 -> V_21 ) ;
if ( F_8 ( V_5 -> V_7 ) ) {
F_37 ( & V_5 -> V_2 -> V_10 ,
L_126 ) ;
V_61 = - V_214 ;
goto V_459;
}
V_5 -> V_322 -> V_7 = V_5 -> V_7 ;
V_5 -> V_7 -> V_343 = V_5 ;
V_435:
V_434 = F_155 ( V_5 ) ;
if ( V_434 < 0 ) {
F_37 ( & V_5 -> V_2 -> V_10 ,
L_127 ) ;
V_61 = - V_200 ;
goto V_460;
}
if ( V_434 == V_341 )
goto V_461;
F_4 ( V_462 , & V_5 -> V_7 -> V_9 ) ;
F_62 ( V_463 , & V_5 -> V_7 -> V_9 ) ;
F_201 ( V_5 -> V_7 , V_430 ) ;
F_202 ( V_5 -> V_7 , 4096 ) ;
F_203 ( V_5 -> V_7 , 0xffff ) ;
F_204 ( V_5 -> V_7 , 0x400000 ) ;
F_205 ( V_5 -> V_7 , 4096 ) ;
F_206 ( V_5 -> V_7 , V_5 -> V_2 -> V_464 ) ;
if ( V_5 -> V_182 == true ) {
F_4 ( V_465 , & V_5 -> V_7 -> V_9 ) ;
V_5 -> V_7 -> V_466 . V_467 = 4096 ;
F_207 ( V_5 -> V_7 ,
V_211 * V_212 ) ;
V_5 -> V_7 -> V_466 . V_468 = 0 ;
}
if ( ! ( F_90 ( V_5 , & V_407 ) ) ) {
F_5 ( & V_5 -> V_2 -> V_10 ,
L_128 ) ;
V_61 = - V_169 ;
goto V_469;
}
F_208 ( V_5 -> V_322 , V_407 ) ;
F_209 ( V_5 -> V_322 ) ;
V_5 -> V_470 = F_210 ( V_5 -> V_322 , 0 ) ;
V_318 = F_211 ( & F_212 ( V_5 -> V_322 ) -> V_318 ) ;
if ( V_318 ) {
F_125 ( V_5 , V_318 ) ;
F_213 ( V_318 ) ;
}
if ( V_5 -> V_471 ) {
F_4 ( V_472 , & V_5 -> V_32 ) ;
return V_61 ;
}
V_461:
V_5 -> V_471 = F_214 ( F_148 ,
V_5 , V_5 -> V_373 ,
L_129 , V_387 ) ;
if ( F_8 ( V_5 -> V_471 ) ) {
F_37 ( & V_5 -> V_2 -> V_10 , L_130 ) ;
V_5 -> V_471 = NULL ;
V_61 = - V_62 ;
goto V_473;
}
F_215 ( V_5 -> V_471 ) ;
if ( V_434 == V_341 )
V_61 = V_434 ;
return V_61 ;
V_473:
F_216 ( V_5 -> V_470 ) ;
V_5 -> V_470 = NULL ;
F_217 ( V_5 -> V_322 ) ;
V_469:
V_460:
F_218 ( V_5 -> V_7 ) ;
V_459:
F_219 ( & V_5 -> V_21 ) ;
V_458:
F_133 ( V_5 ) ;
V_443:
F_27 ( & V_441 ) ;
F_220 ( & V_439 , V_387 ) ;
F_30 ( & V_441 ) ;
V_440:
F_221 ( V_5 -> V_322 ) ;
V_438:
F_169 ( V_5 ) ;
V_436:
return V_61 ;
}
static void F_222 ( struct V_13 * V_14 , void * V_107 , bool V_474 )
{
struct V_4 * V_5 = (struct V_4 * ) V_107 ;
struct V_12 * V_16 ;
if ( F_45 ( ! V_474 ) )
F_18 ( V_14 , - V_380 ) ;
else if ( F_24 ( V_85 , & V_5 -> V_23 -> V_86 ) ) {
V_16 = F_15 ( V_5 , V_87 ) ;
if ( V_16 -> V_74 )
V_16 -> V_74 ( V_5 -> V_23 , V_87 ,
V_16 , - V_380 ) ;
}
}
static int F_223 ( struct V_4 * V_5 )
{
struct V_317 * V_318 ;
F_133 ( V_5 ) ;
if ( V_5 -> V_471 ) {
F_4 ( V_352 , & V_5 -> V_23 -> V_86 ) ;
F_54 ( & V_5 -> V_23 -> V_106 ) ;
F_224 ( V_5 -> V_471 ) ;
}
if ( F_24 ( V_472 , & V_5 -> V_32 ) ) {
V_318 = F_211 ( & F_212 ( V_5 -> V_322 ) -> V_318 ) ;
if ( V_318 ) {
F_127 ( V_5 , V_318 ) ;
F_213 ( V_318 ) ;
}
}
if ( ! V_5 -> V_6 ) {
if ( ! F_63 ( V_5 -> V_23 , V_156 ,
V_143 ) )
F_168 ( V_5 ) ;
}
else
F_47 ( & V_5 -> V_2 -> V_10 , L_131 ,
V_5 -> V_322 -> V_323 ) ;
F_225 ( V_5 -> V_7 ) ;
F_64 ( V_5 -> V_7 ) ;
F_151 ( & V_5 -> V_21 , F_222 , V_5 ) ;
if ( V_5 -> V_470 ) {
F_216 ( V_5 -> V_470 ) ;
V_5 -> V_470 = NULL ;
}
if ( V_5 -> V_322 ) {
if ( F_24 ( V_472 , & V_5 -> V_32 ) )
F_217 ( V_5 -> V_322 ) ;
if ( V_5 -> V_322 -> V_7 ) {
F_218 ( V_5 -> V_7 ) ;
F_219 ( & V_5 -> V_21 ) ;
V_5 -> V_7 = NULL ;
}
F_221 ( V_5 -> V_322 ) ;
}
V_5 -> V_322 = NULL ;
F_27 ( & V_441 ) ;
F_220 ( & V_439 , V_5 -> V_387 ) ;
F_30 ( & V_441 ) ;
F_169 ( V_5 ) ;
return 0 ;
}
static int F_226 ( struct V_4 * V_5 )
{
F_170 ( V_5 ) ;
if ( V_5 -> V_322 ) {
F_47 ( & V_5 -> V_2 -> V_10 ,
L_132 , V_5 -> V_322 -> V_323 ) ;
if ( F_24 ( V_472 , & V_5 -> V_32 ) )
F_217 ( V_5 -> V_322 ) ;
if ( V_5 -> V_322 -> V_7 ) {
F_218 ( V_5 -> V_7 ) ;
F_219 ( & V_5 -> V_21 ) ;
}
F_221 ( V_5 -> V_322 ) ;
V_5 -> V_322 = NULL ;
V_5 -> V_7 = NULL ;
}
F_27 ( & V_441 ) ;
F_220 ( & V_439 , V_5 -> V_387 ) ;
F_30 ( & V_441 ) ;
return 0 ;
}
static int F_227 ( struct V_4 * V_5 )
{
F_47 ( & V_5 -> V_2 -> V_10 ,
L_133 , V_5 -> V_322 -> V_323 ) ;
F_171 ( V_5 ) ;
return 0 ;
}
static int F_228 ( struct V_4 * V_5 )
{
F_47 ( & V_5 -> V_2 -> V_10 , L_134 ,
V_5 -> V_322 -> V_323 ) ;
F_172 ( V_5 ) ;
return 0 ;
}
static void F_229 ( int V_475 )
{
V_476 [ V_475 ] -- ;
}
static int F_230 ( int V_477 )
{
int V_475 , V_478 , V_479 ;
const struct V_480 * V_481 ;
V_481 = F_231 ( V_477 ) ;
V_478 = F_232 ( V_481 ) ;
V_479 = V_476 [ V_478 ] ;
V_475 = V_478 ;
F_233 (cpu, node_mask) {
if ( V_476 [ V_475 ] < V_479 ) {
V_478 = V_475 ;
V_479 = V_476 [ V_475 ] ;
}
}
V_476 [ V_478 ] ++ ;
return V_478 ;
}
static inline int F_234 ( void )
{
static int V_482 = - 1 ;
if ( V_482 == - 1 ) {
V_482 = V_483 ;
return V_482 ;
}
V_482 = F_235 ( V_482 ) ;
if ( V_482 == V_484 )
V_482 = V_483 ;
return V_482 ;
}
static void F_236 ( struct V_4 * V_5 , struct V_1 * V_2 )
{
int V_485 ;
unsigned short V_486 ;
V_485 = F_237 ( V_2 , V_487 ) ;
if ( V_485 ) {
F_3 ( V_2 ,
V_485 + V_488 ,
& V_486 ) ;
if ( V_486 & ( 1 << 11 ) ||
V_486 & ( 1 << 4 ) ) {
F_47 ( & V_5 -> V_2 -> V_10 ,
L_135 ,
V_2 -> V_489 , V_2 -> V_192 ) ;
V_486 &= ~ ( V_490 |
V_491 ) ;
F_238 ( V_2 ,
V_485 + V_488 ,
V_486 ) ;
}
}
}
static void F_239 ( struct V_4 * V_5 , struct V_1 * V_2 )
{
if ( V_2 -> V_492 && V_2 -> V_492 -> V_493 ) {
if ( V_2 -> V_492 -> V_493 -> V_489 == V_494 &&
( ( V_2 -> V_492 -> V_493 -> V_192 & 0xff00 ) == 0x5a00 ) ) {
F_236 ( V_5 , V_2 -> V_492 -> V_493 ) ;
} else {
struct V_1 * V_495 = V_2 -> V_492 -> V_493 ;
if ( V_495 -> V_492 &&
V_495 -> V_492 -> V_496 &&
V_495 -> V_492 -> V_496 -> V_493 &&
V_495 -> V_492 -> V_496 -> V_493 -> V_489 ==
V_494 &&
( V_495 -> V_492 -> V_496 -> V_493 -> V_192 &
0xff00 ) == 0x5a00 ) {
F_236 ( V_5 ,
V_495 -> V_492 -> V_496 -> V_493 ) ;
}
}
}
}
static int F_240 ( struct V_1 * V_2 ,
const struct V_497 * V_498 )
{
int V_61 = 0 ;
struct V_4 * V_5 = NULL ;
char V_499 [ 256 ] ;
const struct V_480 * V_481 ;
int V_475 , V_43 = 0 , V_500 = 0 ;
int V_501 = V_502 ;
unsigned long V_86 ;
V_501 = F_241 ( V_2 -> V_492 ) ;
if ( V_501 != V_502 ) {
if ( ! F_242 ( V_501 ) )
V_501 = F_234 () ;
} else {
F_47 ( & V_2 -> V_10 , L_136 ) ;
V_501 = F_234 () ;
}
F_47 ( & V_2 -> V_10 , L_137 ,
V_501 , F_241 ( V_2 -> V_492 ) , F_243 ( & V_2 -> V_10 ) ,
F_244 ( F_245 () ) , F_245 () ) ;
V_5 = F_159 ( sizeof( struct V_4 ) , V_143 , V_501 ) ;
if ( V_5 == NULL ) {
F_37 ( & V_2 -> V_10 ,
L_138 ) ;
return - V_214 ;
}
F_246 ( V_2 , V_5 ) ;
V_61 = F_247 ( V_2 ) ;
if ( V_61 < 0 ) {
F_37 ( & V_2 -> V_10 , L_139 ) ;
goto V_503;
}
V_61 = F_248 ( V_2 , 1 << V_371 , V_88 ) ;
if ( V_61 < 0 ) {
F_37 ( & V_2 -> V_10 , L_140 ) ;
goto V_503;
}
if ( ! F_249 ( V_2 , F_250 ( 64 ) ) ) {
V_61 = F_251 ( V_2 , F_250 ( 64 ) ) ;
if ( V_61 ) {
V_61 = F_251 ( V_2 ,
F_250 ( 32 ) ) ;
if ( V_61 ) {
F_5 ( & V_2 -> V_10 ,
L_141 ) ;
goto V_504;
}
}
}
V_5 -> V_445 = V_505 ;
V_5 -> V_123 = V_123 ;
V_5 -> V_2 = V_2 ;
V_5 -> V_373 = V_501 ;
F_252 ( & V_5 -> V_506 ) ;
F_252 ( & V_5 -> V_507 ) ;
memset ( V_5 -> V_508 , 0 , 32 ) ;
snprintf ( V_5 -> V_508 , 31 , L_142 , V_5 -> V_123 ) ;
V_5 -> V_119 = F_253 ( V_5 -> V_508 ) ;
if ( ! V_5 -> V_119 ) {
F_5 ( & V_2 -> V_10 , L_143 , V_5 -> V_123 ) ;
V_61 = - V_214 ;
goto V_509;
}
memset ( V_499 , 0 , sizeof( V_499 ) ) ;
V_481 = F_231 ( V_5 -> V_373 ) ;
if ( ! F_254 ( V_481 ) ) {
F_233 (cpu, node_mask)
{
snprintf ( & V_499 [ V_500 ] , 256 - V_500 , L_144 , V_475 ) ;
V_500 = strlen ( V_499 ) ;
}
F_47 ( & V_2 -> V_10 , L_145 ,
V_5 -> V_373 ,
F_255 ( F_232 ( V_481 ) ) ,
F_256 ( V_5 -> V_373 ) ,
V_499 ) ;
} else
F_50 ( & V_2 -> V_10 , L_146 ) ;
V_5 -> V_384 = F_230 ( V_5 -> V_373 ) ;
F_47 ( & V_2 -> V_10 , L_147 ,
F_244 ( V_5 -> V_384 ) , V_5 -> V_384 ) ;
V_5 -> V_117 [ 0 ] . V_118 = V_5 -> V_384 ;
V_5 -> V_117 [ 1 ] . V_118 = F_230 ( V_5 -> V_373 ) ;
V_5 -> V_117 [ 2 ] . V_118 = F_230 ( V_5 -> V_373 ) ;
V_5 -> V_117 [ 3 ] . V_118 = V_5 -> V_117 [ 0 ] . V_118 ;
V_5 -> V_117 [ 4 ] . V_118 = V_5 -> V_117 [ 1 ] . V_118 ;
V_5 -> V_117 [ 5 ] . V_118 = V_5 -> V_117 [ 2 ] . V_118 ;
V_5 -> V_117 [ 6 ] . V_118 = V_5 -> V_117 [ 2 ] . V_118 ;
V_5 -> V_117 [ 7 ] . V_118 = V_5 -> V_117 [ 1 ] . V_118 ;
F_257 (cpu) {
memset ( V_499 , 0 , sizeof( V_499 ) ) ;
for ( V_43 = 0 , V_500 = 0 ; V_43 < V_116 ; V_43 ++ ) {
if ( V_5 -> V_117 [ V_43 ] . V_118 == V_475 ) {
snprintf ( & V_499 [ V_500 ] , 256 - V_500 , L_144 , V_43 ) ;
V_500 = strlen ( V_499 ) ;
}
}
if ( V_500 )
F_47 ( & V_2 -> V_10 , L_148 , V_475 , V_499 ) ;
}
F_258 ( & V_5 -> V_117 [ 0 ] . V_117 , V_510 ) ;
F_258 ( & V_5 -> V_117 [ 1 ] . V_117 , V_511 ) ;
F_258 ( & V_5 -> V_117 [ 2 ] . V_117 , V_512 ) ;
F_258 ( & V_5 -> V_117 [ 3 ] . V_117 , V_513 ) ;
F_258 ( & V_5 -> V_117 [ 4 ] . V_117 , V_514 ) ;
F_258 ( & V_5 -> V_117 [ 5 ] . V_117 , V_515 ) ;
F_258 ( & V_5 -> V_117 [ 6 ] . V_117 , V_516 ) ;
F_258 ( & V_5 -> V_117 [ 7 ] . V_117 , V_517 ) ;
F_259 ( V_2 ) ;
V_61 = F_260 ( V_2 ) ;
if ( V_61 ) {
F_5 ( & V_2 -> V_10 ,
L_149 ) ;
goto V_518;
}
F_239 ( V_5 , V_2 ) ;
V_61 = F_140 ( V_5 ) ;
if ( V_61 < 0 ) {
F_37 ( & V_2 -> V_10 ,
L_150 ) ;
goto V_509;
}
V_123 ++ ;
if ( V_61 != V_341 )
F_4 ( V_472 , & V_5 -> V_32 ) ;
else
V_61 = 0 ;
F_117 ( & V_309 , V_86 ) ;
F_261 ( & V_5 -> V_506 , & V_506 ) ;
F_120 ( & V_309 , V_86 ) ;
goto V_519;
V_509:
F_262 ( V_2 ) ;
V_518:
if ( V_5 -> V_119 ) {
F_263 ( V_5 -> V_119 ) ;
F_264 ( V_5 -> V_119 ) ;
F_229 ( V_5 -> V_117 [ 0 ] . V_118 ) ;
F_229 ( V_5 -> V_117 [ 1 ] . V_118 ) ;
F_229 ( V_5 -> V_117 [ 2 ] . V_118 ) ;
}
V_504:
F_265 ( V_2 , 1 << V_371 ) ;
V_503:
F_105 ( V_5 ) ;
F_246 ( V_2 , NULL ) ;
return V_61 ;
V_519:
return V_61 ;
}
static void F_266 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
unsigned long V_86 , V_138 ;
F_4 ( V_410 , & V_5 -> V_32 ) ;
F_117 ( & V_309 , V_86 ) ;
F_267 ( & V_5 -> V_506 ) ;
F_261 ( & V_5 -> V_507 , & V_520 ) ;
F_120 ( & V_309 , V_86 ) ;
F_1 ( V_2 ) ;
F_268 ( V_5 -> V_2 -> V_122 ) ;
V_138 = V_30 + F_22 ( 4000 ) ;
do {
F_65 ( 20 ) ;
} while ( F_56 ( & V_5 -> V_99 ) != 0 &&
F_25 ( V_30 , V_138 ) );
if ( ! V_5 -> V_6 )
F_269 ( V_5 -> V_470 ) ;
if ( F_56 ( & V_5 -> V_99 ) != 0 ) {
F_5 ( & V_5 -> V_2 -> V_10 ,
L_151 ) ;
}
F_270 ( V_5 -> V_7 ) ;
F_4 ( V_31 , & V_5 -> V_32 ) ;
F_223 ( V_5 ) ;
if ( V_5 -> V_119 ) {
F_263 ( V_5 -> V_119 ) ;
F_264 ( V_5 -> V_119 ) ;
F_229 ( V_5 -> V_117 [ 0 ] . V_118 ) ;
F_229 ( V_5 -> V_117 [ 1 ] . V_118 ) ;
F_229 ( V_5 -> V_117 [ 2 ] . V_118 ) ;
}
F_262 ( V_2 ) ;
F_117 ( & V_309 , V_86 ) ;
F_267 ( & V_5 -> V_507 ) ;
F_120 ( & V_309 , V_86 ) ;
F_105 ( V_5 ) ;
F_265 ( V_2 , 1 << V_371 ) ;
F_246 ( V_2 , NULL ) ;
}
static int F_271 ( struct V_1 * V_2 , T_15 V_521 )
{
int V_61 = 0 ;
struct V_4 * V_5 = F_2 ( V_2 ) ;
if ( ! V_5 ) {
F_37 ( & V_2 -> V_10 ,
L_152 ) ;
return - V_62 ;
}
F_4 ( V_522 , & V_5 -> V_32 ) ;
V_61 = F_227 ( V_5 ) ;
if ( V_61 < 0 ) {
F_37 ( & V_2 -> V_10 ,
L_153 ) ;
return V_61 ;
}
F_272 ( V_2 ) ;
F_273 ( V_2 ) ;
F_274 ( V_2 , V_523 ) ;
return V_61 ;
}
static int F_275 ( struct V_1 * V_2 )
{
int V_61 = 0 ;
struct V_4 * V_5 ;
V_5 = F_2 ( V_2 ) ;
if ( ! V_5 ) {
F_37 ( & V_2 -> V_10 ,
L_152 ) ;
return - V_62 ;
}
F_274 ( V_2 , V_524 ) ;
F_276 ( V_2 ) ;
V_61 = F_247 ( V_2 ) ;
if ( V_61 < 0 ) {
F_37 ( & V_2 -> V_10 ,
L_154 ) ;
goto V_255;
}
F_259 ( V_2 ) ;
V_61 = F_228 ( V_5 ) ;
if ( V_61 < 0 )
F_37 ( & V_2 -> V_10 , L_155 ) ;
V_255:
F_62 ( V_522 , & V_5 -> V_32 ) ;
return V_61 ;
}
static void F_277 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
if ( V_5 )
F_226 ( V_5 ) ;
}
static int T_16 F_278 ( void )
{
int error ;
F_279 ( V_88 L_156 V_525 L_92 ) ;
F_161 ( & V_309 ) ;
F_252 ( & V_506 ) ;
F_252 ( & V_520 ) ;
error = F_280 ( 0 , V_88 ) ;
if ( error <= 0 ) {
F_281 ( L_157 ,
error ) ;
return - V_145 ;
}
V_505 = error ;
V_320 = F_130 ( L_125 , NULL ) ;
if ( F_131 ( V_320 ) ) {
F_282 ( L_158 ) ;
V_320 = NULL ;
}
if ( V_320 ) {
V_526 = F_132 ( L_159 ,
V_324 , V_320 , NULL ,
& V_527 ) ;
if ( F_131 ( V_526 ) ) {
F_281 ( L_160 ) ;
V_526 = NULL ;
}
}
error = F_283 ( & V_528 ) ;
if ( error ) {
F_284 ( V_320 ) ;
F_285 ( V_505 , V_88 ) ;
}
return error ;
}
static void T_17 F_286 ( void )
{
F_285 ( V_505 , V_88 ) ;
F_287 ( & V_528 ) ;
F_134 ( V_320 ) ;
}
