static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 ) ;
}
static
inline int F_3 ( struct V_4 * V_5 , T_1 V_6 , T_1 V_7 )
{
F_4 ( V_6 , V_7 ) ;
return 0 ;
}
static inline T_1 F_5 ( struct V_4 * V_5 , T_1 V_6 )
{
return F_6 ( V_6 ) ;
}
static inline int F_7 ( struct V_4 * V_5 , T_1 V_6 ,
T_1 V_8 , T_1 V_9 )
{
F_8 ( V_6 , ~ V_8 , V_9 ) ;
return 0 ;
}
static inline T_2 F_9 ( unsigned int V_10 )
{
if ( V_10 > V_11 + 1 )
V_10 = V_11 ;
else if ( V_10 < 2 )
V_10 = 1 ;
else
V_10 -- ;
return ( T_2 ) V_10 ;
}
static inline T_2 F_10 ( unsigned int V_12 )
{
return F_9 (
F_11 ( V_13 / 1000000 * V_12 , 1000 ) ) ;
}
static inline unsigned int F_12 ( unsigned int V_14 )
{
return F_11 ( ( V_14 + 1 ) * 1000 ,
V_13 / 1000000 ) ;
}
static inline T_2 F_13 ( unsigned int V_15 )
{
return F_9 (
F_11 ( V_13 , V_15 * 16 ) ) ;
}
static inline unsigned int F_14 ( unsigned int V_14 )
{
return F_11 ( V_13 , ( V_14 + 1 ) * 16 ) ;
}
static inline T_2 F_15 ( unsigned int V_15 ,
unsigned int V_16 )
{
return F_9 (
F_11 ( V_13 , V_15 * V_16 ) ) ;
}
static inline unsigned int F_16 ( unsigned int V_14 ,
unsigned int V_16 )
{
return F_11 ( V_13 ,
( V_14 + 1 ) * V_16 ) ;
}
static inline T_2 F_17 ( unsigned int V_10 )
{
if ( V_10 > V_17 )
V_10 = V_17 ;
else if ( V_10 < 4 )
V_10 = 0 ;
return ( T_2 ) V_10 ;
}
static inline T_2 F_18 ( unsigned int V_12 )
{
return F_17 (
F_11 ( V_13 / 1000000 * V_12 , 1000 ) ) ;
}
static inline unsigned int F_19 ( unsigned int V_18 )
{
return F_11 ( V_18 * 1000 ,
V_13 / 1000000 ) ;
}
static inline unsigned int F_20 ( unsigned int V_18 )
{
return F_11 ( V_18 , V_13 / 1000000 ) ;
}
static T_1 F_21 ( T_2 V_14 )
{
return F_11 ( ( 1 << 2 ) * ( ( T_1 ) V_14 + 1 ) * 1000 ,
V_13 / 1000000 ) ;
}
static T_3 F_22 ( T_2 V_18 , T_2 V_14 )
{
T_3 V_19 ;
T_1 V_20 ;
V_19 = ( ( ( T_3 ) V_18 << 2 ) | 0x3 ) * ( V_14 + 1 ) * 1000 ;
V_20 = F_23 ( V_19 , V_13 / 1000000 ) ;
if ( V_20 >= V_13 / 1000000 / 2 )
V_19 ++ ;
return V_19 ;
}
static unsigned int F_24 ( T_2 V_18 , T_2 V_14 )
{
T_3 V_19 ;
T_1 V_20 ;
V_19 = ( ( ( T_3 ) V_18 << 2 ) | 0x3 ) * ( V_14 + 1 ) ;
V_20 = F_23 ( V_19 , V_13 / 1000000 ) ;
if ( V_20 >= V_13 / 1000000 / 2 )
V_19 ++ ;
return ( unsigned int ) V_19 ;
}
static T_3 F_25 ( T_1 V_12 )
{
T_3 V_21 ;
T_1 V_20 ;
V_21 = V_13 / 1000000 * ( T_3 ) V_12 ;
V_20 = F_23 ( V_21 , 1000 ) ;
if ( V_20 >= 1000 / 2 )
V_21 ++ ;
return V_21 ;
}
static T_2 F_26 ( T_3 V_18 )
{
T_1 V_20 ;
V_20 = F_23 ( V_18 , ( V_22 << 2 ) | 0x3 ) ;
if ( V_18 > V_11 + 1 )
V_18 = V_11 ;
else if ( V_18 < 2 )
V_18 = 1 ;
else
V_18 -- ;
return ( T_2 ) V_18 ;
}
static inline void F_27 ( struct V_4 * V_5 ,
enum V_23 V_24 )
{
F_7 ( V_5 , V_25 , ~ V_26 , V_24 ) ;
}
static inline void F_28 ( struct V_4 * V_5 ,
enum V_27 V_24 )
{
F_7 ( V_5 , V_25 , ~ V_28 , V_24 ) ;
}
static inline void F_29 ( struct V_4 * V_5 , bool V_29 )
{
F_7 ( V_5 , V_25 , ~ ( V_30 | V_31 ) ,
V_29 ? ( V_30 | V_31 ) : 0 ) ;
}
static inline void F_30 ( struct V_4 * V_5 , bool V_29 )
{
F_7 ( V_5 , V_25 , ~ ( V_32 | V_33 ) ,
V_29 ? ( V_32 | V_33 ) : 0 ) ;
}
static inline void F_31 ( struct V_4 * V_5 ,
bool V_29 )
{
F_7 ( V_5 , V_25 , ~ V_34 ,
V_29 ? V_34 : 0 ) ;
}
static inline void F_32 ( struct V_4 * V_5 ,
bool V_29 )
{
F_7 ( V_5 , V_25 , ~ V_35 ,
V_29 ? V_35 : 0 ) ;
}
static inline void F_33 ( struct V_4 * V_5 ,
T_1 V_36 )
{
F_7 ( V_5 , V_25 , ~ V_37 ,
V_36 & V_37 ) ;
}
static void F_34 ( struct V_4 * V_5 ,
unsigned int V_38 ,
unsigned int * V_39 ,
unsigned int * V_40 )
{
T_1 V_41 ;
unsigned int V_42 = V_38 * 16 ;
if ( * V_39 < F_11 ( V_42 , 16 + 3 ) ) {
V_41 = V_43 ;
* V_39 = F_11 ( V_42 , 16 + 4 ) ;
} else {
V_41 = V_44 ;
* V_39 = F_11 ( V_42 , 16 + 3 ) ;
}
if ( * V_40 > F_11 ( V_42 , 16 - 3 ) ) {
V_41 |= V_45 ;
* V_40 = F_11 ( V_42 , 16 - 4 ) ;
} else {
V_41 |= V_44 ;
* V_40 = F_11 ( V_42 , 16 - 3 ) ;
}
F_7 ( V_5 , V_25 , ~ V_46 , V_41 ) ;
}
static inline void F_35 ( struct V_4 * V_5 ,
bool V_47 )
{
F_7 ( V_5 , V_25 , ~ V_48 ,
V_47 ? V_48 : 0 ) ;
}
static inline void F_36 ( struct V_4 * V_5 ,
bool V_47 )
{
F_7 ( V_5 , V_25 , ~ V_49 ,
V_47 ? V_49 : 0 ) ;
}
static unsigned int F_37 ( struct V_4 * V_5 ,
unsigned int V_15 ,
T_2 * V_14 )
{
* V_14 = F_13 ( V_15 ) ;
F_3 ( V_5 , V_50 , * V_14 ) ;
return F_14 ( * V_14 ) ;
}
static unsigned int F_38 ( struct V_4 * V_5 ,
unsigned int V_15 ,
T_2 * V_14 )
{
* V_14 = F_13 ( V_15 ) ;
F_3 ( V_5 , V_51 , * V_14 ) ;
return F_14 ( * V_14 ) ;
}
static T_1 F_39 ( struct V_4 * V_5 , T_1 V_12 ,
T_2 * V_14 )
{
T_3 V_52 ;
if ( V_12 > V_53 )
V_12 = V_53 ;
V_52 = F_25 ( V_12 ) ;
* V_14 = F_26 ( V_52 ) ;
F_3 ( V_5 , V_50 , * V_14 ) ;
return ( T_1 ) F_22 ( V_22 , * V_14 ) ;
}
static T_1 F_40 ( struct V_4 * V_5 , T_1 V_12 ,
T_2 * V_14 )
{
T_3 V_52 ;
if ( V_12 > V_53 )
V_12 = V_53 ;
V_52 = F_25 ( V_12 ) ;
* V_14 = F_26 ( V_52 ) ;
F_3 ( V_5 , V_51 , * V_14 ) ;
return ( T_1 ) F_22 ( V_22 , * V_14 ) ;
}
static unsigned int F_41 ( struct V_4 * V_5 ,
unsigned int V_54 )
{
T_1 V_19 ;
V_19 = F_11 ( V_54 * 100 , 625 ) ;
if ( V_19 != 0 )
V_19 -- ;
if ( V_19 > 15 )
V_19 = 15 ;
F_3 ( V_5 , V_55 , V_19 ) ;
return F_11 ( ( V_19 + 1 ) * 100 , 16 ) ;
}
static T_1 F_42 ( struct V_4 * V_5 , T_1 V_56 )
{
T_1 V_18 = F_18 ( V_56 ) ;
F_3 ( V_5 , V_57 , V_18 ) ;
return F_19 ( V_18 ) ;
}
static inline void F_43 ( struct V_4 * V_5 , T_1 V_58 )
{
V_58 &= ( V_59 | V_60 | V_61 ) ;
F_7 ( V_5 , V_62 ,
~ ( V_59 | V_60 | V_61 ) , V_58 ) ;
}
static inline void F_44 ( struct V_4 * V_5 , T_1 V_58 )
{
V_58 &= V_63 ;
F_7 ( V_5 , V_62 , ~ V_63 , V_58 ) ;
}
static int F_45 ( struct V_2 * V_3 , T_1 V_64 ,
bool * V_65 )
{
struct V_1 * V_66 = F_1 ( V_3 ) ;
struct V_4 * V_5 = V_66 -> V_5 ;
unsigned long V_67 ;
T_1 V_68 = F_5 ( V_5 , V_25 ) ;
T_1 V_69 = F_5 ( V_5 , V_62 ) ;
T_1 V_70 = F_5 ( V_5 , V_71 ) ;
union V_72 V_73 [ V_74 ] ;
unsigned int V_75 , V_76 , V_77 ;
T_1 V_78 , V_41 ;
int V_79 , V_80 , V_81 , V_82 , V_83 , V_84 , V_85 , V_86 , V_87 ;
V_79 = V_70 & V_88 ;
V_80 = V_70 & V_89 ;
V_81 = V_70 & V_90 ;
V_82 = V_70 & V_91 ;
V_83 = V_69 & V_63 ;
V_84 = V_69 & V_61 ;
V_85 = V_69 & V_59 ;
V_86 = V_69 & V_60 ;
* V_65 = false ;
F_46 ( 2 , V_92 , V_3 , L_1 ,
V_79 ? L_2 : L_3 , V_80 ? L_4 : L_3 ,
V_81 ? L_5 : L_3 , V_82 ? L_6 : L_3 ,
V_70 & V_93 ? L_7 : L_3 ,
V_70 & V_94 ? L_8 : L_3 ) ;
F_46 ( 2 , V_92 , V_3 , L_9 ,
V_83 ? L_10 : L_3 , V_84 ? L_11 : L_3 ,
V_85 ? L_12 : L_3 , V_86 ? L_13 : L_3 ) ;
if ( V_83 && V_79 ) {
F_44 ( V_5 , 0 ) ;
V_78 = V_95 ;
F_47 ( V_3 , V_96 , & V_78 ) ;
* V_65 = true ;
}
V_87 = 0 ;
if ( ( V_84 && V_80 ) || ( V_85 && V_81 ) ) {
for ( V_75 = 0 , V_41 = V_97 ;
( V_41 & V_97 ) && ! V_87 ; V_75 = 0 ) {
for ( V_76 = 0 ;
( V_41 & V_97 ) && V_76 < V_74 ; V_76 ++ ) {
V_41 = F_5 ( V_5 , V_98 ) ;
V_73 [ V_75 ] . V_99 = V_41 & ~ V_97 ;
V_75 ++ ;
}
if ( V_75 == 0 )
break;
V_76 = V_75 * sizeof( union V_72 ) ;
V_77 = F_48 ( & V_66 -> V_100 ,
( unsigned char * ) V_73 , V_76 ,
& V_66 -> V_101 ) ;
if ( V_77 != V_76 )
V_87 ++ ;
}
* V_65 = true ;
}
V_78 = 0 ;
V_41 = 0 ;
if ( V_87 ) {
V_78 |= V_102 ;
F_49 ( V_3 , L_14 ) ;
}
if ( V_86 && V_82 ) {
V_41 |= V_33 ;
V_78 |= V_103 ;
F_49 ( V_3 , L_15 ) ;
}
if ( V_85 && V_81 ) {
V_41 |= V_32 ;
V_78 |= V_104 ;
}
if ( V_41 ) {
F_3 ( V_5 , V_25 , V_68 & ~ V_41 ) ;
F_3 ( V_5 , V_25 , V_68 ) ;
* V_65 = true ;
}
F_50 ( & V_66 -> V_101 , V_67 ) ;
if ( F_51 ( & V_66 -> V_100 ) >= V_105 / 2 )
V_78 |= V_106 ;
F_52 ( & V_66 -> V_101 , V_67 ) ;
if ( V_78 )
F_47 ( V_3 , V_107 , & V_78 ) ;
return 0 ;
}
static int F_53 ( struct V_2 * V_3 , T_4 * V_108 , T_5 V_18 ,
T_6 * V_109 )
{
struct V_1 * V_66 = F_1 ( V_3 ) ;
bool V_47 = ( bool ) F_54 ( & V_66 -> V_110 ) ;
T_2 V_14 = ( T_2 ) F_54 ( & V_66 -> V_111 ) ;
unsigned int V_75 , V_19 ;
union V_72 * V_112 ;
unsigned V_113 , V_41 , V_114 ;
V_19 = V_18 / sizeof( union V_72 )
* sizeof( union V_72 ) ;
if ( V_19 == 0 ) {
* V_109 = 0 ;
return 0 ;
}
V_19 = F_55 ( & V_66 -> V_100 , V_108 , V_19 , & V_66 -> V_101 ) ;
V_19 /= sizeof( union V_72 ) ;
* V_109 = V_19 * sizeof( union V_72 ) ;
for ( V_112 = (union V_72 * ) V_108 , V_75 = 0 ; V_75 < V_19 ; V_112 ++ , V_75 ++ ) {
if ( ( V_112 -> V_99 & V_115 ) == V_115 ) {
V_113 = 0 ;
V_114 = 1 ;
} else {
V_113 = ( V_112 -> V_99 & V_116 ) ? 1 : 0 ;
if ( V_47 )
V_113 = V_113 ? 0 : 1 ;
V_114 = 0 ;
}
V_41 = ( unsigned ) F_22 (
( T_2 ) ( V_112 -> V_99 & V_22 ) , V_14 ) ;
if ( V_41 > V_53 )
V_41 = V_53 ;
F_56 ( & V_112 -> V_117 ) ;
V_112 -> V_117 . V_118 = V_113 ;
V_112 -> V_117 . V_119 = V_41 ;
V_112 -> V_117 . V_120 = V_114 ;
F_46 ( 2 , V_92 , V_3 , L_16 ,
V_41 , V_113 ? L_17 : L_18 , V_114 ? L_19 : L_20 ) ;
if ( V_114 )
F_46 ( 2 , V_92 , V_3 , L_21 ) ;
}
return 0 ;
}
static int F_57 ( struct V_2 * V_3 ,
struct V_121 * V_112 )
{
struct V_1 * V_66 = F_1 ( V_3 ) ;
F_58 ( & V_66 -> V_122 ) ;
memcpy ( V_112 , & V_66 -> V_123 , sizeof( struct V_121 ) ) ;
F_59 ( & V_66 -> V_122 ) ;
return 0 ;
}
static int F_60 ( struct V_2 * V_3 )
{
struct V_1 * V_66 = F_1 ( V_3 ) ;
struct V_4 * V_5 = V_66 -> V_5 ;
F_58 ( & V_66 -> V_122 ) ;
F_43 ( V_5 , 0 ) ;
F_30 ( V_5 , false ) ;
F_32 ( V_5 , false ) ;
F_33 ( V_5 , V_124 ) ;
F_42 ( V_5 , 0 ) ;
F_3 ( V_5 , V_51 , V_11 ) ;
V_66 -> V_123 . V_125 = true ;
F_59 ( & V_66 -> V_122 ) ;
return 0 ;
}
static int F_61 ( struct V_2 * V_3 ,
struct V_121 * V_112 )
{
struct V_1 * V_66 = F_1 ( V_3 ) ;
struct V_4 * V_5 = V_66 -> V_5 ;
struct V_121 * V_126 = & V_66 -> V_123 ;
T_2 V_111 ;
if ( V_112 -> V_125 )
return F_60 ( V_3 ) ;
if ( V_112 -> V_127 != V_128 )
return - V_129 ;
F_58 ( & V_66 -> V_122 ) ;
V_126 -> V_125 = V_112 -> V_125 ;
V_126 -> V_127 = V_112 -> V_127 = V_128 ;
V_126 -> V_130 = V_112 -> V_130
= sizeof( union V_72 ) ;
F_43 ( V_5 , 0 ) ;
F_30 ( V_5 , false ) ;
F_32 ( V_5 , V_112 -> V_131 ) ;
V_126 -> V_131 = V_112 -> V_131 ;
if ( V_112 -> V_131 ) {
V_112 -> V_132 = F_38 ( V_5 , V_112 -> V_132 ,
& V_111 ) ;
V_126 -> V_132 = V_112 -> V_132 ;
V_126 -> V_54 = V_112 -> V_54 = 50 ;
F_34 ( V_5 , V_112 -> V_132 ,
& V_112 -> V_133 ,
& V_112 -> V_134 ) ;
V_126 -> V_133 = V_112 -> V_133 ;
V_126 -> V_134 = V_112 -> V_134 ;
V_112 -> V_135 =
( T_1 ) F_22 ( V_22 , V_111 ) ;
} else {
V_112 -> V_135 =
F_40 ( V_5 , V_112 -> V_135 ,
& V_111 ) ;
}
V_126 -> V_135 = V_112 -> V_135 ;
F_62 ( & V_66 -> V_111 , V_111 ) ;
V_112 -> V_136 =
F_42 ( V_5 , V_112 -> V_136 ) ;
V_126 -> V_136 = V_112 -> V_136 ;
V_112 -> V_137 = F_21 ( V_111 ) ;
V_126 -> V_137 = V_112 -> V_137 ;
F_28 ( V_5 , V_138 ) ;
F_33 ( V_5 , V_37 ) ;
V_126 -> V_139 = V_112 -> V_139 ;
F_62 ( & V_66 -> V_110 , V_112 -> V_139 ) ;
V_126 -> V_140 = V_112 -> V_140 ;
V_126 -> V_29 = V_112 -> V_29 ;
if ( V_112 -> V_29 ) {
unsigned long V_67 ;
F_50 ( & V_66 -> V_101 , V_67 ) ;
F_63 ( & V_66 -> V_100 ) ;
F_52 ( & V_66 -> V_101 , V_67 ) ;
if ( V_112 -> V_140 )
F_43 ( V_5 , V_61 | V_59 | V_60 ) ;
F_30 ( V_5 , V_112 -> V_29 ) ;
}
F_59 ( & V_66 -> V_122 ) ;
return 0 ;
}
static int F_64 ( struct V_2 * V_3 , T_4 * V_108 , T_5 V_18 ,
T_6 * V_109 )
{
struct V_1 * V_66 = F_1 ( V_3 ) ;
struct V_4 * V_5 = V_66 -> V_5 ;
F_44 ( V_5 , V_63 ) ;
* V_109 = V_18 ;
return 0 ;
}
static int F_65 ( struct V_2 * V_3 ,
struct V_121 * V_112 )
{
struct V_1 * V_66 = F_1 ( V_3 ) ;
F_58 ( & V_66 -> V_141 ) ;
memcpy ( V_112 , & V_66 -> V_142 , sizeof( struct V_121 ) ) ;
F_59 ( & V_66 -> V_141 ) ;
return 0 ;
}
static int F_66 ( struct V_2 * V_3 )
{
struct V_1 * V_66 = F_1 ( V_3 ) ;
struct V_4 * V_5 = V_66 -> V_5 ;
F_58 ( & V_66 -> V_141 ) ;
F_44 ( V_5 , 0 ) ;
F_29 ( V_5 , false ) ;
F_31 ( V_5 , false ) ;
F_3 ( V_5 , V_50 , V_143 ) ;
V_66 -> V_142 . V_125 = true ;
F_59 ( & V_66 -> V_141 ) ;
return 0 ;
}
static int F_67 ( struct V_2 * V_3 ,
struct V_121 * V_112 )
{
struct V_1 * V_66 = F_1 ( V_3 ) ;
struct V_4 * V_5 = V_66 -> V_5 ;
struct V_121 * V_126 = & V_66 -> V_142 ;
T_2 V_144 ;
if ( V_112 -> V_125 )
return F_66 ( V_3 ) ;
if ( V_112 -> V_127 != V_128 )
return - V_129 ;
F_58 ( & V_66 -> V_141 ) ;
V_126 -> V_125 = V_112 -> V_125 ;
V_126 -> V_127 = V_112 -> V_127 = V_128 ;
V_126 -> V_130 = V_112 -> V_130
= sizeof( union V_72 ) ;
F_44 ( V_5 , 0 ) ;
F_29 ( V_5 , false ) ;
F_31 ( V_5 , V_112 -> V_131 ) ;
V_126 -> V_131 = V_112 -> V_131 ;
if ( V_112 -> V_131 ) {
V_112 -> V_132 = F_37 ( V_5 , V_112 -> V_132 ,
& V_144 ) ;
V_126 -> V_132 = V_112 -> V_132 ;
V_112 -> V_54 = F_41 ( V_5 , V_112 -> V_54 ) ;
V_126 -> V_54 = V_112 -> V_54 ;
V_112 -> V_135 =
( T_1 ) F_22 ( V_22 , V_144 ) ;
} else {
V_112 -> V_135 =
F_39 ( V_5 , V_112 -> V_135 ,
& V_144 ) ;
}
V_126 -> V_135 = V_112 -> V_135 ;
F_62 ( & V_66 -> V_144 , V_144 ) ;
V_112 -> V_137 = F_21 ( V_144 ) ;
V_126 -> V_137 = V_112 -> V_137 ;
F_27 ( V_5 , V_145 ) ;
F_35 ( V_5 , V_112 -> V_146 ) ;
V_126 -> V_146 = V_112 -> V_146 ;
F_36 ( V_5 , V_112 -> V_139 ) ;
V_126 -> V_139 = V_112 -> V_139 ;
V_126 -> V_140 = V_112 -> V_140 ;
V_126 -> V_29 = V_112 -> V_29 ;
if ( V_112 -> V_29 ) {
if ( V_112 -> V_140 )
F_44 ( V_5 , V_63 ) ;
F_29 ( V_5 , V_112 -> V_29 ) ;
}
F_59 ( & V_66 -> V_141 ) ;
return 0 ;
}
static int F_68 ( struct V_2 * V_3 )
{
struct V_1 * V_66 = F_1 ( V_3 ) ;
struct V_4 * V_5 = V_66 -> V_5 ;
char * V_147 ;
int V_75 , V_76 ;
T_1 V_68 = F_5 ( V_5 , V_25 ) ;
T_1 V_148 = F_5 ( V_5 , V_50 ) & V_143 ;
T_1 V_149 = F_5 ( V_5 , V_51 ) & V_11 ;
T_1 V_150 = F_5 ( V_5 , V_55 ) & V_151 ;
T_1 V_70 = F_5 ( V_5 , V_71 ) ;
T_1 V_69 = F_5 ( V_5 , V_62 ) ;
T_1 V_152 = F_5 ( V_5 , V_57 ) & V_17 ;
F_69 ( V_3 , L_22 ) ;
F_69 ( V_3 , L_23 ,
V_68 & V_32 ? L_24 : L_25 ) ;
F_69 ( V_3 , L_26 ,
V_68 & V_35 ? L_27 : L_28 ) ;
F_69 ( V_3 , L_29 ,
V_68 & V_33 ? L_27 : L_28 ) ;
switch ( V_68 & V_153 ) {
case V_124 :
V_147 = L_28 ;
break;
case V_154 :
V_147 = L_30 ;
break;
case V_155 :
V_147 = L_31 ;
break;
case V_37 :
V_147 = L_32 ;
break;
default:
V_147 = L_33 ;
break;
}
F_69 ( V_3 , L_34 , V_147 ) ;
F_69 ( V_3 , L_35 ,
V_68 & V_156 ? L_36 : L_37 ) ;
F_69 ( V_3 , L_38 ,
V_68 & V_28 ? L_39 : L_40 ) ;
F_69 ( V_3 , L_41 ,
V_68 & V_157 ? L_42 : L_43 ) ;
if ( V_68 & V_35 ) {
F_69 ( V_3 , L_44 ,
F_14 ( V_149 ) ) ;
switch ( V_68 & V_46 ) {
case V_44 :
V_75 = 3 ;
V_76 = 3 ;
break;
case V_45 :
V_75 = 4 ;
V_76 = 3 ;
break;
case V_43 :
V_75 = 3 ;
V_76 = 4 ;
break;
case V_158 :
V_75 = 4 ;
V_76 = 4 ;
break;
default:
V_75 = 0 ;
V_76 = 0 ;
break;
}
F_69 ( V_3 , L_45
L_46 , V_75 , V_76 ,
F_16 ( V_149 , 16 + V_76 ) ,
F_16 ( V_149 , 16 - V_75 ) ) ;
}
F_69 ( V_3 , L_47 ,
F_24 ( V_22 , V_149 ) ,
F_22 ( V_22 , V_149 ) ) ;
F_69 ( V_3 , L_48 ,
V_152 ? L_27 : L_28 ) ;
if ( V_152 )
F_69 ( V_3 , L_49
L_50 ,
F_20 ( V_152 ) ,
F_19 ( V_152 ) ) ;
F_69 ( V_3 , L_51 ,
V_70 & V_90 ? L_24 : L_25 ) ;
F_69 ( V_3 , L_52 ,
V_69 & V_59 ? L_27 : L_28 ) ;
F_69 ( V_3 , L_53 ,
V_70 & V_91 ? L_24 : L_25 ) ;
F_69 ( V_3 , L_54 ,
V_69 & V_60 ? L_27 : L_28 ) ;
F_69 ( V_3 , L_55 ,
V_70 & V_94 ? L_24 : L_25 ) ;
F_69 ( V_3 , L_56 ,
V_70 & V_89 ? L_24 : L_25 ) ;
F_69 ( V_3 , L_57 ,
V_69 & V_61 ? L_27 : L_28 ) ;
F_69 ( V_3 , L_58 ) ;
F_69 ( V_3 , L_23 ,
V_68 & V_30 ? L_24 : L_25 ) ;
F_69 ( V_3 , L_59 ,
V_68 & V_34 ? L_27 : L_28 ) ;
F_69 ( V_3 , L_29 ,
V_68 & V_31 ? L_27 : L_28 ) ;
F_69 ( V_3 , L_38 ,
V_68 & V_26 ? L_39 : L_60 ) ;
F_69 ( V_3 , L_61 ,
V_68 & V_49 ? L_24 : L_25 ) ;
F_69 ( V_3 , L_62 ,
V_68 & V_48 ? L_63
: L_64 ) ;
if ( V_68 & V_34 ) {
F_69 ( V_3 , L_65 ,
F_14 ( V_148 ) ) ;
F_69 ( V_3 , L_66 ,
V_150 + 1 ) ;
}
F_69 ( V_3 , L_67 ,
F_24 ( V_22 , V_148 ) ,
F_22 ( V_22 , V_148 ) ) ;
F_69 ( V_3 , L_55 ,
V_70 & V_93 ? L_24 : L_25 ) ;
F_69 ( V_3 , L_56 ,
V_70 & V_88 ? L_24 : L_25 ) ;
F_69 ( V_3 , L_57 ,
V_69 & V_63 ? L_27 : L_28 ) ;
return 0 ;
}
static inline int F_70 ( const struct V_159 * V_160 )
{
return V_160 -> type == V_161 && V_160 -> V_6 == 2 ;
}
static int F_71 ( struct V_2 * V_3 ,
struct V_162 * V_163 )
{
struct V_1 * V_66 = F_1 ( V_3 ) ;
if ( F_70 ( & V_163 -> V_160 ) ) {
V_163 -> V_164 = V_66 -> V_165 ;
V_163 -> V_166 = V_66 -> V_167 ;
}
return 0 ;
}
static int F_72 ( struct V_2 * V_3 ,
struct V_168 * V_169 )
{
struct V_1 * V_66 = F_1 ( V_3 ) ;
T_1 V_6 = V_170 + ( T_1 ) V_169 -> V_169 ;
if ( ! F_70 ( & V_169 -> V_160 ) )
return - V_171 ;
if ( ( V_6 & 0x3 ) != 0 )
return - V_171 ;
if ( V_6 < V_25 || V_6 > V_172 )
return - V_171 ;
if ( ! F_73 ( V_173 ) )
return - V_174 ;
V_169 -> V_175 = 4 ;
V_169 -> V_176 = F_5 ( V_66 -> V_5 , V_6 ) ;
return 0 ;
}
static int F_74 ( struct V_2 * V_3 ,
struct V_168 * V_169 )
{
struct V_1 * V_66 = F_1 ( V_3 ) ;
T_1 V_6 = V_170 + ( T_1 ) V_169 -> V_169 ;
if ( ! F_70 ( & V_169 -> V_160 ) )
return - V_171 ;
if ( ( V_6 & 0x3 ) != 0 )
return - V_171 ;
if ( V_6 < V_25 || V_6 > V_172 )
return - V_171 ;
if ( ! F_73 ( V_173 ) )
return - V_174 ;
F_3 ( V_66 -> V_5 , V_6 , V_169 -> V_176 ) ;
return 0 ;
}
int F_75 ( struct V_4 * V_5 )
{
struct V_1 * V_66 ;
struct V_2 * V_3 ;
struct V_121 V_177 ;
int V_178 ;
V_66 = F_76 ( sizeof( struct V_1 ) , V_179 ) ;
if ( V_66 == NULL )
return - V_180 ;
F_77 ( & V_66 -> V_101 ) ;
if ( F_78 ( & V_66 -> V_100 , V_105 , V_179 ) )
return - V_180 ;
V_66 -> V_5 = V_5 ;
V_66 -> V_165 = V_181 ;
V_66 -> V_167 = 0 ;
V_3 = & V_66 -> V_3 ;
F_79 ( V_3 , & V_182 ) ;
F_80 ( V_3 , V_66 ) ;
snprintf ( V_3 -> V_183 , sizeof( V_3 -> V_183 ) , L_68 , V_5 -> V_183 ) ;
V_3 -> V_184 = V_185 ;
V_178 = F_81 ( & V_5 -> V_186 , V_3 ) ;
if ( V_178 == 0 ) {
F_3 ( V_5 , V_62 , 0 ) ;
F_82 ( & V_66 -> V_122 ) ;
memcpy ( & V_177 , & V_187 ,
sizeof( struct V_121 ) ) ;
F_83 ( V_3 , V_188 , V_189 , & V_177 ) ;
F_82 ( & V_66 -> V_141 ) ;
memcpy ( & V_177 , & V_190 ,
sizeof( struct V_121 ) ) ;
F_83 ( V_3 , V_188 , V_191 , & V_177 ) ;
} else {
F_84 ( & V_66 -> V_100 ) ;
}
return V_178 ;
}
int F_85 ( struct V_4 * V_5 )
{
struct V_2 * V_3 ;
struct V_1 * V_66 ;
V_3 = F_86 ( V_5 , V_185 ) ;
if ( V_3 == NULL )
return - V_192 ;
F_60 ( V_3 ) ;
F_66 ( V_3 ) ;
V_66 = F_1 ( V_3 ) ;
F_87 ( V_3 ) ;
F_84 ( & V_66 -> V_100 ) ;
F_88 ( V_66 ) ;
return 0 ;
}
