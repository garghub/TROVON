static inline void F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
int V_5 ;
char * V_6 , * V_7 ;
char * V_8 ;
char V_9 [ sizeof( V_4 -> V_10 ) ] ;
F_2 ( V_9 , V_4 ) ;
F_3 ( V_2 , L_1 ) ;
V_7 = V_2 -> V_6 + V_2 -> V_11 ;
V_6 = V_2 -> V_6 + V_2 -> V_12 ;
V_8 = V_9 ;
V_5 = sizeof( V_9 ) ;
while ( V_5 && ( V_6 < V_7 ) ) {
unsigned char V_13 = * V_8 ;
V_8 ++ ;
V_5 -- ;
* V_6 = V_13 ;
if ( ! V_13 )
break;
if ( V_13 == '\\' ) {
V_6 ++ ;
if ( V_6 < V_7 )
* V_6 ++ = V_13 ;
continue;
}
if ( V_13 == '\n' ) {
* V_6 ++ = '\\' ;
if ( V_6 < V_7 )
* V_6 ++ = 'n' ;
continue;
}
V_6 ++ ;
}
V_2 -> V_12 = V_6 - V_2 -> V_6 ;
F_4 ( V_2 , '\n' ) ;
}
static inline const char * F_5 ( struct V_3 * V_14 )
{
unsigned int V_15 = ( V_14 -> V_15 & V_16 ) | V_14 -> V_17 ;
const char * const * V_4 = & V_18 [ 0 ] ;
F_6 ( 1 + F_7 ( V_19 ) != F_8 ( V_18 ) ) ;
while ( V_15 ) {
V_4 ++ ;
V_15 >>= 1 ;
}
return * V_4 ;
}
static inline void F_9 ( struct V_1 * V_2 , struct V_20 * V_21 ,
struct V_22 * V_22 , struct V_3 * V_4 )
{
struct V_23 * V_23 ;
int V_24 ;
struct V_25 * V_26 = NULL ;
const struct V_27 * V_27 ;
T_1 V_28 , V_29 ;
F_10 () ;
V_28 = F_11 ( V_4 ) ?
F_12 ( F_13 ( V_4 -> V_30 ) , V_21 ) : 0 ;
V_29 = 0 ;
if ( F_11 ( V_4 ) ) {
struct V_3 * V_31 = F_14 ( V_4 ) ;
if ( V_31 )
V_29 = F_15 ( V_31 , V_21 ) ;
}
V_27 = F_16 ( V_4 ) ;
F_17 ( V_2 ,
L_2
L_3
L_4
L_5
L_6
L_7
L_8 ,
F_5 ( V_4 ) ,
F_12 ( V_4 , V_21 ) ,
F_18 ( V_22 , V_21 ) ,
V_28 , V_29 ,
V_27 -> V_32 , V_27 -> V_33 , V_27 -> V_34 , V_27 -> V_35 ,
V_27 -> V_36 , V_27 -> V_37 , V_27 -> V_38 , V_27 -> V_39 ) ;
F_19 ( V_4 ) ;
if ( V_4 -> V_40 )
V_26 = F_20 ( V_4 -> V_40 ) ;
F_17 ( V_2 ,
L_9
L_10 ,
V_26 ? V_26 -> V_41 : 0 ) ;
F_21 () ;
V_23 = V_27 -> V_23 ;
F_22 ( V_4 ) ;
for ( V_24 = 0 ; V_24 < F_23 ( V_23 -> V_42 , V_43 ) ; V_24 ++ )
F_17 ( V_2 , L_11 , F_24 ( V_23 , V_24 ) ) ;
F_25 ( V_27 ) ;
F_4 ( V_2 , '\n' ) ;
}
static void F_26 ( struct V_1 * V_2 , const char * V_44 ,
T_2 * V_45 )
{
int V_5 ;
F_3 ( V_2 , V_44 ) ;
V_5 = V_46 ;
do {
int V_47 = 0 ;
V_5 -= 4 ;
if ( F_27 ( V_45 , V_5 + 1 ) ) V_47 |= 1 ;
if ( F_27 ( V_45 , V_5 + 2 ) ) V_47 |= 2 ;
if ( F_27 ( V_45 , V_5 + 3 ) ) V_47 |= 4 ;
if ( F_27 ( V_45 , V_5 + 4 ) ) V_47 |= 8 ;
F_17 ( V_2 , L_12 , V_47 ) ;
} while ( V_5 >= 4 );
F_4 ( V_2 , '\n' ) ;
}
static void F_28 ( struct V_3 * V_4 , T_2 * V_48 ,
T_2 * V_49 )
{
struct V_50 * V_51 ;
int V_5 ;
V_51 = V_4 -> V_52 -> V_53 ;
for ( V_5 = 1 ; V_5 <= V_46 ; ++ V_5 , ++ V_51 ) {
if ( V_51 -> V_54 . V_55 == V_56 )
F_29 ( V_48 , V_5 ) ;
else if ( V_51 -> V_54 . V_55 != V_57 )
F_29 ( V_49 , V_5 ) ;
}
}
static inline void F_30 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
unsigned long V_58 ;
T_2 V_59 , V_60 , V_61 , V_62 , V_63 ;
int V_64 = 0 ;
unsigned long V_65 = 0 ;
unsigned long V_66 = 0 ;
F_31 ( & V_59 ) ;
F_31 ( & V_60 ) ;
F_31 ( & V_61 ) ;
F_31 ( & V_62 ) ;
F_31 ( & V_63 ) ;
if ( F_32 ( V_4 , & V_58 ) ) {
V_59 = V_4 -> V_59 . signal ;
V_60 = V_4 -> signal -> V_67 . signal ;
V_61 = V_4 -> V_61 ;
F_28 ( V_4 , & V_62 , & V_63 ) ;
V_64 = F_33 ( V_4 ) ;
F_10 () ;
V_65 = F_34 ( & F_35 ( V_4 ) -> V_68 -> V_69 ) ;
F_21 () ;
V_66 = F_36 ( V_4 , V_70 ) ;
F_37 ( V_4 , & V_58 ) ;
}
F_17 ( V_2 , L_13 , V_64 ) ;
F_17 ( V_2 , L_14 , V_65 , V_66 ) ;
F_26 ( V_2 , L_15 , & V_59 ) ;
F_26 ( V_2 , L_16 , & V_60 ) ;
F_26 ( V_2 , L_17 , & V_61 ) ;
F_26 ( V_2 , L_18 , & V_62 ) ;
F_26 ( V_2 , L_19 , & V_63 ) ;
}
static void F_38 ( struct V_1 * V_2 , const char * V_44 ,
T_3 * V_71 )
{
unsigned V_72 ;
F_3 ( V_2 , V_44 ) ;
F_39 (__capi) {
F_17 ( V_2 , L_20 ,
V_71 -> V_73 [ ( V_74 - 1 ) - V_72 ] ) ;
}
F_4 ( V_2 , '\n' ) ;
}
static inline void F_40 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
const struct V_27 * V_27 ;
T_3 V_75 , V_76 , V_77 , V_78 ;
F_10 () ;
V_27 = F_35 ( V_4 ) ;
V_75 = V_27 -> V_75 ;
V_76 = V_27 -> V_76 ;
V_77 = V_27 -> V_77 ;
V_78 = V_27 -> V_78 ;
F_21 () ;
F_38 ( V_2 , L_21 , & V_75 ) ;
F_38 ( V_2 , L_22 , & V_76 ) ;
F_38 ( V_2 , L_23 , & V_77 ) ;
F_38 ( V_2 , L_24 , & V_78 ) ;
}
static inline void F_41 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
F_17 ( V_2 , L_25
L_26 ,
V_4 -> V_79 ,
V_4 -> V_80 ) ;
}
static void F_42 ( struct V_1 * V_2 , struct V_3 * V_81 )
{
F_3 ( V_2 , L_27 ) ;
F_43 ( V_2 , & V_81 -> V_82 ) ;
F_4 ( V_2 , '\n' ) ;
F_3 ( V_2 , L_28 ) ;
F_44 ( V_2 , & V_81 -> V_82 ) ;
F_4 ( V_2 , '\n' ) ;
}
int F_45 ( struct V_1 * V_2 , struct V_20 * V_21 ,
struct V_22 * V_22 , struct V_3 * V_81 )
{
struct V_83 * V_84 = F_46 ( V_81 ) ;
F_1 ( V_2 , V_81 ) ;
F_9 ( V_2 , V_21 , V_22 , V_81 ) ;
if ( V_84 ) {
F_47 ( V_2 , V_84 ) ;
F_48 ( V_84 ) ;
}
F_30 ( V_2 , V_81 ) ;
F_40 ( V_2 , V_81 ) ;
F_42 ( V_2 , V_81 ) ;
F_49 ( V_2 , V_81 ) ;
F_41 ( V_2 , V_81 ) ;
return 0 ;
}
static int F_50 ( struct V_1 * V_2 , struct V_20 * V_21 ,
struct V_22 * V_22 , struct V_3 * V_81 , int V_85 )
{
unsigned long V_86 , V_87 , V_88 , V_89 = ~ 0UL ;
long V_90 , V_91 ;
int V_92 = - 1 , V_93 = 0 ;
T_2 V_94 , V_95 ;
char V_15 ;
T_1 V_28 = 0 , V_96 = - 1 , V_97 = - 1 ;
int V_64 = 0 ;
int V_98 ;
struct V_83 * V_84 ;
unsigned long long V_99 ;
unsigned long V_100 = 0 , V_101 = 0 ;
unsigned long V_102 = 0 , V_103 = 0 ;
T_4 V_104 , V_105 , V_106 , V_107 ;
T_4 V_108 , V_109 ;
unsigned long V_110 = 0 ;
char V_9 [ sizeof( V_81 -> V_10 ) ] ;
unsigned long V_58 ;
V_15 = * F_5 ( V_81 ) ;
V_86 = V_87 = V_88 = 0 ;
V_98 = F_51 ( V_81 , V_111 | V_112 ) ;
V_84 = F_46 ( V_81 ) ;
if ( V_84 ) {
V_86 = F_52 ( V_84 ) ;
if ( V_98 ) {
V_87 = F_53 ( V_81 ) ;
V_88 = F_54 ( V_81 ) ;
}
}
F_2 ( V_9 , V_81 ) ;
F_31 ( & V_94 ) ;
F_31 ( & V_95 ) ;
V_104 = V_105 = V_106 = V_107 = 0 ;
V_108 = V_109 = 0 ;
if ( F_32 ( V_81 , & V_58 ) ) {
struct V_113 * V_114 = V_81 -> signal ;
if ( V_114 -> V_115 ) {
struct V_22 * V_116 = F_55 ( V_114 -> V_115 ) ;
V_92 = F_18 ( V_116 , V_21 ) ;
F_56 ( V_116 ) ;
V_93 = F_57 ( F_58 ( V_114 -> V_115 ) ) ;
}
V_64 = F_33 ( V_81 ) ;
F_28 ( V_81 , & V_94 , & V_95 ) ;
V_100 = V_114 -> V_100 ;
V_101 = V_114 -> V_101 ;
V_104 = V_114 -> V_104 ;
V_105 = V_114 -> V_105 ;
V_108 = V_114 -> V_108 ;
V_110 = F_59 ( V_114 -> V_117 [ V_118 ] . V_119 ) ;
if ( V_85 ) {
struct V_3 * V_120 = V_81 ;
do {
V_102 += V_120 -> V_102 ;
V_103 += V_120 -> V_103 ;
V_109 += V_120 -> V_109 ;
V_120 = F_60 ( V_120 ) ;
} while ( V_120 != V_81 );
V_102 += V_114 -> V_102 ;
V_103 += V_114 -> V_103 ;
F_61 ( V_81 , & V_106 , & V_107 ) ;
V_109 += V_114 -> V_109 ;
}
V_97 = F_62 ( V_81 , V_21 ) ;
V_28 = F_12 ( V_81 -> V_30 , V_21 ) ;
V_96 = F_63 ( V_81 , V_21 ) ;
F_37 ( V_81 , & V_58 ) ;
}
if ( V_98 && ( ! V_85 || V_64 < 2 ) )
V_89 = F_64 ( V_81 ) ;
if ( ! V_85 ) {
V_102 = V_81 -> V_102 ;
V_103 = V_81 -> V_103 ;
F_65 ( V_81 , & V_106 , & V_107 ) ;
V_109 = V_81 -> V_109 ;
}
V_90 = F_66 ( V_81 ) ;
V_91 = F_67 ( V_81 ) ;
V_99 =
( unsigned long long ) V_81 -> V_121 . V_122 * V_123
+ V_81 -> V_121 . V_124 ;
V_99 = F_68 ( V_99 ) ;
F_17 ( V_2 , L_29 , F_18 ( V_22 , V_21 ) , V_9 , V_15 ) ;
F_69 ( V_2 , ' ' , V_28 ) ;
F_69 ( V_2 , ' ' , V_96 ) ;
F_69 ( V_2 , ' ' , V_97 ) ;
F_69 ( V_2 , ' ' , V_93 ) ;
F_69 ( V_2 , ' ' , V_92 ) ;
F_70 ( V_2 , ' ' , V_81 -> V_58 ) ;
F_70 ( V_2 , ' ' , V_102 ) ;
F_70 ( V_2 , ' ' , V_100 ) ;
F_70 ( V_2 , ' ' , V_103 ) ;
F_70 ( V_2 , ' ' , V_101 ) ;
F_70 ( V_2 , ' ' , F_71 ( V_106 ) ) ;
F_70 ( V_2 , ' ' , F_71 ( V_107 ) ) ;
F_69 ( V_2 , ' ' , F_71 ( V_104 ) ) ;
F_69 ( V_2 , ' ' , F_71 ( V_105 ) ) ;
F_69 ( V_2 , ' ' , V_90 ) ;
F_69 ( V_2 , ' ' , V_91 ) ;
F_69 ( V_2 , ' ' , V_64 ) ;
F_70 ( V_2 , ' ' , 0 ) ;
F_70 ( V_2 , ' ' , V_99 ) ;
F_70 ( V_2 , ' ' , V_86 ) ;
F_69 ( V_2 , ' ' , V_84 ? F_72 ( V_84 ) : 0 ) ;
F_70 ( V_2 , ' ' , V_110 ) ;
F_70 ( V_2 , ' ' , V_84 ? ( V_98 ? V_84 -> V_125 : 1 ) : 0 ) ;
F_70 ( V_2 , ' ' , V_84 ? ( V_98 ? V_84 -> V_126 : 1 ) : 0 ) ;
F_70 ( V_2 , ' ' , ( V_98 && V_84 ) ? V_84 -> V_127 : 0 ) ;
F_70 ( V_2 , ' ' , V_88 ) ;
F_70 ( V_2 , ' ' , V_87 ) ;
F_70 ( V_2 , ' ' , V_81 -> V_59 . signal . V_114 [ 0 ] & 0x7fffffffUL ) ;
F_70 ( V_2 , ' ' , V_81 -> V_61 . V_114 [ 0 ] & 0x7fffffffUL ) ;
F_70 ( V_2 , ' ' , V_94 . V_114 [ 0 ] & 0x7fffffffUL ) ;
F_70 ( V_2 , ' ' , V_95 . V_114 [ 0 ] & 0x7fffffffUL ) ;
F_70 ( V_2 , ' ' , V_89 ) ;
F_70 ( V_2 , ' ' , 0 ) ;
F_70 ( V_2 , ' ' , 0 ) ;
F_69 ( V_2 , ' ' , V_81 -> V_128 ) ;
F_69 ( V_2 , ' ' , F_73 ( V_81 ) ) ;
F_70 ( V_2 , ' ' , V_81 -> V_129 ) ;
F_70 ( V_2 , ' ' , V_81 -> V_130 ) ;
F_70 ( V_2 , ' ' , F_74 ( V_81 ) ) ;
F_70 ( V_2 , ' ' , F_71 ( V_109 ) ) ;
F_69 ( V_2 , ' ' , F_71 ( V_108 ) ) ;
F_70 ( V_2 , ' ' , ( V_84 && V_98 ) ? V_84 -> V_131 : 0 ) ;
F_70 ( V_2 , ' ' , ( V_84 && V_98 ) ? V_84 -> V_132 : 0 ) ;
F_70 ( V_2 , ' ' , ( V_84 && V_98 ) ? V_84 -> V_133 : 0 ) ;
F_4 ( V_2 , '\n' ) ;
if ( V_84 )
F_48 ( V_84 ) ;
return 0 ;
}
int F_75 ( struct V_1 * V_2 , struct V_20 * V_21 ,
struct V_22 * V_22 , struct V_3 * V_81 )
{
return F_50 ( V_2 , V_21 , V_22 , V_81 , 0 ) ;
}
int F_76 ( struct V_1 * V_2 , struct V_20 * V_21 ,
struct V_22 * V_22 , struct V_3 * V_81 )
{
return F_50 ( V_2 , V_21 , V_22 , V_81 , 1 ) ;
}
int F_77 ( struct V_1 * V_2 , struct V_20 * V_21 ,
struct V_22 * V_22 , struct V_3 * V_81 )
{
unsigned long V_11 = 0 , V_134 = 0 , V_135 = 0 , V_136 = 0 , V_137 = 0 ;
struct V_83 * V_84 = F_46 ( V_81 ) ;
if ( V_84 ) {
V_11 = F_78 ( V_84 , & V_135 , & V_136 , & V_137 , & V_134 ) ;
F_48 ( V_84 ) ;
}
F_70 ( V_2 , 0 , V_11 ) ;
F_70 ( V_2 , ' ' , V_134 ) ;
F_70 ( V_2 , ' ' , V_135 ) ;
F_70 ( V_2 , ' ' , V_136 ) ;
F_70 ( V_2 , ' ' , 0 ) ;
F_70 ( V_2 , ' ' , V_137 ) ;
F_70 ( V_2 , ' ' , 0 ) ;
F_4 ( V_2 , '\n' ) ;
return 0 ;
}
