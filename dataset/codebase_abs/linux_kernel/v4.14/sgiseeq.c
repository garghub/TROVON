static inline void F_1 ( struct V_1 * V_2 , void * V_3 )
{
F_2 ( V_2 -> V_2 . V_4 , V_3 , sizeof( struct V_5 ) ,
V_6 ) ;
}
static inline void F_3 ( struct V_1 * V_2 , void * V_3 )
{
F_2 ( V_2 -> V_2 . V_4 , V_3 , sizeof( struct V_5 ) ,
V_7 ) ;
}
static inline void F_4 ( struct V_8 * V_9 )
{
V_9 -> V_10 = V_11 | V_12 ;
F_5 ( 20 ) ;
V_9 -> V_10 = 0 ;
}
static inline void F_6 ( struct V_8 * V_9 ,
struct V_13 * V_14 )
{
V_9 -> V_15 = V_9 -> V_16 = 0 ;
F_4 ( V_9 ) ;
}
static inline void F_7 ( struct V_17 * V_18 ,
struct V_8 * V_9 ,
struct V_13 * V_14 )
{
V_14 -> V_19 = V_18 -> V_20 | V_21 ;
V_9 -> V_15 = V_22 ;
}
static inline void F_8 ( struct V_1 * V_2 )
{
struct V_17 * V_18 = F_9 ( V_2 ) ;
struct V_13 * V_14 = V_18 -> V_14 ;
int V_23 ;
V_14 -> V_24 = V_25 ;
for ( V_23 = 0 ; V_23 < 6 ; V_23 ++ )
V_14 -> V_26 . V_27 [ V_23 ] = V_2 -> V_28 [ V_23 ] ;
}
static int F_10 ( struct V_1 * V_2 , void * V_3 )
{
struct V_17 * V_18 = F_9 ( V_2 ) ;
struct V_29 * V_30 = V_3 ;
memcpy ( V_2 -> V_28 , V_30 -> V_31 , V_2 -> V_32 ) ;
F_11 ( & V_18 -> V_33 ) ;
F_8 ( V_2 ) ;
F_12 ( & V_18 -> V_33 ) ;
return 0 ;
}
static int F_13 ( struct V_1 * V_2 )
{
struct V_17 * V_18 = F_9 ( V_2 ) ;
int V_23 ;
F_14 ( V_2 ) ;
V_18 -> V_34 = V_18 -> V_35 = 0 ;
V_18 -> V_36 = V_18 -> V_37 = 0 ;
F_8 ( V_2 ) ;
for( V_23 = 0 ; V_23 < V_38 ; V_23 ++ ) {
V_18 -> V_39 [ V_23 ] . V_40 . V_41 = V_42 ;
F_3 ( V_2 , & V_18 -> V_39 [ V_23 ] ) ;
}
for ( V_23 = 0 ; V_23 < V_43 ; V_23 ++ ) {
if ( ! V_18 -> V_44 [ V_23 ] . V_45 ) {
T_1 V_46 ;
struct V_47 * V_45 = F_15 ( V_2 , V_48 ) ;
if ( V_45 == NULL )
return - V_49 ;
F_16 ( V_45 , 2 ) ;
V_46 = F_17 ( V_2 -> V_2 . V_4 ,
V_45 -> V_50 - 2 ,
V_48 , V_6 ) ;
V_18 -> V_44 [ V_23 ] . V_45 = V_45 ;
V_18 -> V_44 [ V_23 ] . V_51 . V_52 = V_46 ;
}
V_18 -> V_44 [ V_23 ] . V_51 . V_41 = V_53 ;
F_3 ( V_2 , & V_18 -> V_44 [ V_23 ] ) ;
}
V_18 -> V_44 [ V_23 - 1 ] . V_51 . V_41 |= V_54 ;
F_3 ( V_2 , & V_18 -> V_44 [ V_23 - 1 ] ) ;
return 0 ;
}
static void F_18 ( struct V_1 * V_2 )
{
struct V_17 * V_18 = F_9 ( V_2 ) ;
int V_23 ;
for ( V_23 = 0 ; V_23 < V_38 ; V_23 ++ ) {
if ( V_18 -> V_39 [ V_23 ] . V_45 ) {
F_19 ( V_18 -> V_39 [ V_23 ] . V_45 ) ;
V_18 -> V_39 [ V_23 ] . V_45 = NULL ;
}
}
for ( V_23 = 0 ; V_23 < V_43 ; V_23 ++ ) {
if ( V_18 -> V_44 [ V_23 ] . V_45 ) {
F_19 ( V_18 -> V_44 [ V_23 ] . V_45 ) ;
V_18 -> V_44 [ V_23 ] . V_45 = NULL ;
}
}
}
static void F_20 ( void )
{
static int V_55 ;
struct V_5 * V_56 = V_57 -> V_44 ;
struct V_58 * V_59 = V_57 -> V_39 ;
struct V_8 * V_9 = V_57 -> V_9 ;
int V_23 ;
if ( V_55 )
return;
V_55 ++ ;
F_21 ( L_1 ) ;
for ( V_23 = 0 ; V_23 < V_43 ; V_23 ++ ) {
F_21 ( L_2 ,
V_23 , ( & V_56 [ V_23 ] ) , V_56 [ V_23 ] . V_51 . V_52 , V_56 [ V_23 ] . V_51 . V_41 ,
V_56 [ V_23 ] . V_51 . V_60 ) ;
V_23 += 1 ;
F_21 ( L_3 ,
V_23 , ( & V_56 [ V_23 ] ) , V_56 [ V_23 ] . V_51 . V_52 , V_56 [ V_23 ] . V_51 . V_41 ,
V_56 [ V_23 ] . V_51 . V_60 ) ;
}
for ( V_23 = 0 ; V_23 < V_38 ; V_23 ++ ) {
F_21 ( L_4 ,
V_23 , ( & V_59 [ V_23 ] ) , V_59 [ V_23 ] . V_40 . V_52 , V_59 [ V_23 ] . V_40 . V_41 ,
V_59 [ V_23 ] . V_40 . V_60 ) ;
V_23 += 1 ;
F_21 ( L_3 ,
V_23 , ( & V_59 [ V_23 ] ) , V_59 [ V_23 ] . V_40 . V_52 , V_59 [ V_23 ] . V_40 . V_41 ,
V_59 [ V_23 ] . V_40 . V_60 ) ;
}
F_21 ( L_5 ,
V_57 -> V_34 , V_57 -> V_36 , V_57 -> V_35 , V_57 -> V_37 ) ;
F_21 ( L_6 ,
V_9 -> V_61 , V_9 -> V_62 , V_9 -> V_15 ) ;
F_21 ( L_7 ,
V_9 -> V_63 , V_9 -> V_64 , V_9 -> V_16 ) ;
}
static int F_22 ( struct V_1 * V_2 , struct V_17 * V_18 ,
struct V_13 * V_14 )
{
struct V_8 * V_9 = V_18 -> V_9 ;
int V_65 ;
F_6 ( V_9 , V_14 ) ;
V_65 = F_13 ( V_2 ) ;
if ( V_65 )
return V_65 ;
if ( V_18 -> V_66 ) {
V_14 -> V_24 = V_67 ;
V_14 -> V_26 . V_68 . V_69 = V_18 -> V_69 ;
V_14 -> V_26 . V_68 . V_70 = 0 ;
} else {
V_14 -> V_24 = V_71 ;
}
V_9 -> V_62 = F_23 ( V_18 , V_18 -> V_44 ) ;
V_9 -> V_64 = F_23 ( V_18 , V_18 -> V_39 ) ;
F_7 ( V_18 , V_9 , V_14 ) ;
return 0 ;
}
static void F_24 ( struct V_1 * V_2 , unsigned char V_72 )
{
if ( V_72 & V_73 ||
V_72 & V_74 )
V_2 -> V_75 . V_76 ++ ;
if ( V_72 & V_77 )
V_2 -> V_75 . V_78 ++ ;
if ( V_72 & V_79 )
V_2 -> V_75 . V_80 ++ ;
if ( V_72 & V_81 )
V_2 -> V_75 . V_82 ++ ;
}
static inline void F_25 ( struct V_17 * V_18 ,
struct V_8 * V_9 ,
struct V_13 * V_14 )
{
if ( ! ( V_9 -> V_15 & V_22 ) ) {
V_9 -> V_62 = F_23 ( V_18 , V_18 -> V_44 + V_18 -> V_34 ) ;
F_7 ( V_18 , V_9 , V_14 ) ;
}
}
static inline void F_26 ( struct V_1 * V_2 , struct V_17 * V_18 ,
struct V_8 * V_9 ,
struct V_13 * V_14 )
{
struct V_5 * V_83 ;
struct V_47 * V_45 = NULL ;
struct V_47 * V_84 ;
unsigned char V_85 ;
int V_86 = 0 ;
unsigned int V_87 = F_27 ( V_18 -> V_34 ) ;
V_83 = & V_18 -> V_44 [ V_18 -> V_34 ] ;
F_1 ( V_2 , V_83 ) ;
while ( ! ( V_83 -> V_51 . V_41 & V_88 ) ) {
V_86 = V_48 - ( V_83 -> V_51 . V_41 & V_89 ) - 3 ;
F_28 ( V_2 -> V_2 . V_4 , V_83 -> V_51 . V_52 ,
V_48 , V_6 ) ;
V_85 = V_83 -> V_45 -> V_50 [ V_86 ] ;
if ( V_85 & V_90 ) {
if ( ! F_29 ( V_83 -> V_45 -> V_50 + 6 , V_2 -> V_28 ) ) {
if ( V_86 > V_91 ) {
V_45 = V_83 -> V_45 ;
V_84 = F_15 ( V_2 , V_48 ) ;
if ( ! V_84 ) {
V_84 = V_45 ;
V_45 = NULL ;
goto V_92;
}
F_16 ( V_84 , 2 ) ;
} else {
V_45 = F_30 ( V_2 , V_86 ) ;
if ( V_45 )
F_31 ( V_45 , V_83 -> V_45 -> V_50 , V_86 ) ;
V_84 = V_83 -> V_45 ;
}
V_92:
if ( V_45 ) {
F_32 ( V_45 , V_86 ) ;
V_45 -> V_93 = F_33 ( V_45 , V_2 ) ;
F_34 ( V_45 ) ;
V_2 -> V_75 . V_94 ++ ;
V_2 -> V_75 . V_95 += V_86 ;
} else {
V_2 -> V_75 . V_96 ++ ;
}
} else {
V_84 = V_83 -> V_45 ;
}
} else {
F_24 ( V_2 , V_85 ) ;
V_84 = V_83 -> V_45 ;
}
V_83 -> V_45 = V_84 ;
V_83 -> V_51 . V_52 = F_17 ( V_2 -> V_2 . V_4 ,
V_84 -> V_50 - 2 ,
V_48 , V_6 ) ;
V_83 -> V_51 . V_41 = V_53 ;
V_18 -> V_34 = F_35 ( V_18 -> V_34 ) ;
F_3 ( V_2 , V_83 ) ;
V_83 = & V_18 -> V_44 [ V_18 -> V_34 ] ;
F_1 ( V_2 , V_83 ) ;
}
F_1 ( V_2 , & V_18 -> V_44 [ V_87 ] ) ;
V_18 -> V_44 [ V_87 ] . V_51 . V_41 &= ~ ( V_54 ) ;
F_3 ( V_2 , & V_18 -> V_44 [ V_87 ] ) ;
F_1 ( V_2 , & V_18 -> V_44 [ F_27 ( V_18 -> V_34 ) ] ) ;
V_18 -> V_44 [ F_27 ( V_18 -> V_34 ) ] . V_51 . V_41 |= V_54 ;
F_3 ( V_2 , & V_18 -> V_44 [ F_27 ( V_18 -> V_34 ) ] ) ;
F_25 ( V_18 , V_9 , V_14 ) ;
}
static inline void F_36 ( struct V_17 * V_18 ,
struct V_13 * V_14 )
{
if ( V_18 -> V_66 ) {
V_14 -> V_26 . V_68 . V_69 = V_18 -> V_69 & ~ ( V_97 ) ;
V_14 -> V_26 . V_68 . V_69 = V_18 -> V_69 ;
}
}
static inline void F_37 ( struct V_1 * V_2 ,
struct V_17 * V_18 ,
struct V_8 * V_9 )
{
struct V_58 * V_98 ;
int V_23 = V_18 -> V_37 ;
V_98 = & V_18 -> V_39 [ V_23 ] ;
F_1 ( V_2 , V_98 ) ;
while ( ( V_98 -> V_40 . V_41 & ( V_99 | V_100 ) ) ==
( V_99 | V_100 ) ) {
V_23 = F_38 ( V_23 ) ;
V_98 = & V_18 -> V_39 [ V_23 ] ;
F_1 ( V_2 , V_98 ) ;
}
if ( V_98 -> V_40 . V_41 & V_99 ) {
V_9 -> V_64 = F_23 ( V_18 , V_98 ) ;
V_9 -> V_16 = V_101 ;
}
}
static inline void F_39 ( struct V_1 * V_2 , struct V_17 * V_18 ,
struct V_8 * V_9 ,
struct V_13 * V_14 )
{
struct V_58 * V_98 ;
unsigned long V_72 = V_9 -> V_16 ;
int V_102 ;
F_36 ( V_18 , V_14 ) ;
if ( ! ( V_72 & ( V_101 | V_103 ) ) ) {
if ( V_72 & V_104 )
V_2 -> V_75 . V_105 ++ ;
if ( V_72 & V_106 )
V_2 -> V_75 . V_107 ++ ;
if ( V_72 & V_108 )
V_2 -> V_75 . V_109 ++ ;
}
for ( V_102 = V_18 -> V_37 ; V_102 != V_18 -> V_35 ; V_102 = F_38 ( V_102 ) ) {
V_98 = & V_18 -> V_39 [ V_102 ] ;
F_1 ( V_2 , V_98 ) ;
if ( ! ( V_98 -> V_40 . V_41 & ( V_99 ) ) )
break;
if ( ! ( V_98 -> V_40 . V_41 & ( V_100 ) ) ) {
if ( ! ( V_72 & V_101 ) ) {
V_9 -> V_64 = F_23 ( V_18 , V_98 ) ;
V_9 -> V_16 = V_101 ;
}
break;
}
V_2 -> V_75 . V_110 ++ ;
V_18 -> V_37 = F_38 ( V_18 -> V_37 ) ;
V_98 -> V_40 . V_41 &= ~ ( V_99 | V_111 ) ;
V_98 -> V_40 . V_41 |= V_112 ;
if ( V_98 -> V_45 ) {
F_40 ( V_98 -> V_45 ) ;
V_98 -> V_45 = NULL ;
}
F_3 ( V_2 , V_98 ) ;
}
}
static T_2 F_41 ( int V_113 , void * V_114 )
{
struct V_1 * V_2 = (struct V_1 * ) V_114 ;
struct V_17 * V_18 = F_9 ( V_2 ) ;
struct V_8 * V_9 = V_18 -> V_9 ;
struct V_13 * V_14 = V_18 -> V_14 ;
F_42 ( & V_18 -> V_33 ) ;
V_9 -> V_10 = V_12 ;
F_26 ( V_2 , V_18 , V_9 , V_14 ) ;
if ( V_18 -> V_37 != V_18 -> V_35 )
F_39 ( V_2 , V_18 , V_9 , V_14 ) ;
if ( ( F_43 ( V_18 ) > 0 ) && F_44 ( V_2 ) ) {
F_45 ( V_2 ) ;
}
F_46 ( & V_18 -> V_33 ) ;
return V_115 ;
}
static int F_47 ( struct V_1 * V_2 )
{
struct V_17 * V_18 = F_9 ( V_2 ) ;
struct V_13 * V_14 = V_18 -> V_14 ;
unsigned int V_113 = V_2 -> V_113 ;
int V_65 ;
if ( F_48 ( V_113 , F_41 , 0 , V_116 , V_2 ) ) {
F_21 ( V_117 L_8 , V_2 -> V_113 ) ;
return - V_118 ;
}
V_65 = F_22 ( V_2 , V_18 , V_14 ) ;
if ( V_65 )
goto V_119;
F_49 ( V_2 ) ;
return 0 ;
V_119:
F_50 ( V_113 , V_2 ) ;
return V_65 ;
}
static int F_51 ( struct V_1 * V_2 )
{
struct V_17 * V_18 = F_9 ( V_2 ) ;
struct V_13 * V_14 = V_18 -> V_14 ;
unsigned int V_113 = V_2 -> V_113 ;
F_14 ( V_2 ) ;
F_6 ( V_18 -> V_9 , V_14 ) ;
F_50 ( V_113 , V_2 ) ;
F_18 ( V_2 ) ;
return 0 ;
}
static inline int F_52 ( struct V_1 * V_2 )
{
struct V_17 * V_18 = F_9 ( V_2 ) ;
struct V_13 * V_14 = V_18 -> V_14 ;
int V_65 ;
V_65 = F_22 ( V_2 , V_18 , V_14 ) ;
if ( V_65 )
return V_65 ;
F_53 ( V_2 ) ;
F_45 ( V_2 ) ;
return 0 ;
}
static int F_54 ( struct V_47 * V_45 , struct V_1 * V_2 )
{
struct V_17 * V_18 = F_9 ( V_2 ) ;
struct V_8 * V_9 = V_18 -> V_9 ;
unsigned long V_120 ;
struct V_58 * V_98 ;
int V_86 , V_121 ;
F_55 ( & V_18 -> V_33 , V_120 ) ;
V_86 = V_45 -> V_86 ;
if ( V_86 < V_122 ) {
if ( F_56 ( V_45 , V_122 ) ) {
F_57 ( & V_18 -> V_33 , V_120 ) ;
return V_123 ;
}
V_86 = V_122 ;
}
V_2 -> V_75 . V_124 += V_86 ;
V_121 = V_18 -> V_35 ;
V_98 = & V_18 -> V_39 [ V_121 ] ;
F_1 ( V_2 , V_98 ) ;
V_98 -> V_45 = V_45 ;
V_98 -> V_40 . V_52 = F_17 ( V_2 -> V_2 . V_4 , V_45 -> V_50 ,
V_86 , V_7 ) ;
V_98 -> V_40 . V_41 = ( V_86 & V_89 ) |
V_99 | V_125 | V_111 | V_112 ;
F_3 ( V_2 , V_98 ) ;
if ( V_18 -> V_37 != V_18 -> V_35 ) {
struct V_58 * V_126 ;
V_126 = & V_18 -> V_39 [ F_58 ( V_18 -> V_35 ) ] ;
F_1 ( V_2 , V_126 ) ;
V_126 -> V_40 . V_41 &= ~ V_112 ;
F_3 ( V_2 , V_126 ) ;
}
V_18 -> V_35 = F_38 ( V_18 -> V_35 ) ;
if ( ! ( V_9 -> V_16 & V_101 ) )
F_37 ( V_2 , V_18 , V_9 ) ;
if ( ! F_43 ( V_18 ) )
F_14 ( V_2 ) ;
F_57 ( & V_18 -> V_33 , V_120 ) ;
return V_123 ;
}
static void F_59 ( struct V_1 * V_2 )
{
F_21 ( V_127 L_9 , V_2 -> V_128 ) ;
F_52 ( V_2 ) ;
F_53 ( V_2 ) ;
F_45 ( V_2 ) ;
}
static void F_60 ( struct V_1 * V_2 )
{
struct V_17 * V_18 = F_9 ( V_2 ) ;
unsigned char V_129 = V_18 -> V_20 ;
if( V_2 -> V_120 & V_130 )
V_18 -> V_20 = V_131 ;
else if ( ( V_2 -> V_120 & V_132 ) || ! F_61 ( V_2 ) )
V_18 -> V_20 = V_133 ;
else
V_18 -> V_20 = V_134 ;
if ( V_129 != V_18 -> V_20 )
F_52 ( V_2 ) ;
}
static inline void F_62 ( struct V_1 * V_2 ,
struct V_58 * V_135 ,
int V_136 )
{
struct V_17 * V_18 = F_9 ( V_2 ) ;
int V_23 = 0 ;
while ( V_23 < ( V_136 - 1 ) ) {
V_135 [ V_23 ] . V_40 . V_60 = F_23 ( V_18 , V_135 + V_23 + 1 ) ;
V_135 [ V_23 ] . V_40 . V_52 = 0 ;
F_3 ( V_2 , & V_135 [ V_23 ] ) ;
V_23 ++ ;
}
V_135 [ V_23 ] . V_40 . V_60 = F_23 ( V_18 , V_135 ) ;
F_3 ( V_2 , & V_135 [ V_23 ] ) ;
}
static inline void F_63 ( struct V_1 * V_2 ,
struct V_5 * V_135 ,
int V_136 )
{
struct V_17 * V_18 = F_9 ( V_2 ) ;
int V_23 = 0 ;
while ( V_23 < ( V_136 - 1 ) ) {
V_135 [ V_23 ] . V_51 . V_60 = F_23 ( V_18 , V_135 + V_23 + 1 ) ;
V_135 [ V_23 ] . V_51 . V_52 = 0 ;
F_3 ( V_2 , & V_135 [ V_23 ] ) ;
V_23 ++ ;
}
V_135 [ V_23 ] . V_51 . V_52 = 0 ;
V_135 [ V_23 ] . V_51 . V_60 = F_23 ( V_18 , V_135 ) ;
F_3 ( V_2 , & V_135 [ V_23 ] ) ;
}
static int F_64 ( struct V_137 * V_138 )
{
struct V_139 * V_140 = F_65 ( & V_138 -> V_2 ) ;
struct V_141 * V_142 = V_140 -> V_143 ;
struct V_144 * V_145 ;
unsigned int V_113 = V_140 -> V_113 ;
struct V_17 * V_18 ;
struct V_1 * V_2 ;
int V_65 ;
V_2 = F_66 ( sizeof ( struct V_17 ) ) ;
if ( ! V_2 ) {
V_65 = - V_49 ;
goto V_146;
}
F_67 ( V_138 , V_2 ) ;
V_18 = F_9 ( V_2 ) ;
V_145 = F_68 ( & V_138 -> V_2 , sizeof( * V_18 -> V_147 ) , & V_18 -> V_148 ,
V_149 , V_150 ) ;
if ( ! V_145 ) {
F_21 ( V_117 L_10 ) ;
V_65 = - V_49 ;
goto V_151;
}
V_18 -> V_147 = V_145 ;
V_18 -> V_44 = V_18 -> V_147 -> V_152 ;
V_18 -> V_39 = V_18 -> V_147 -> V_153 ;
F_69 ( & V_18 -> V_33 ) ;
F_63 ( V_2 , V_18 -> V_44 , V_43 ) ;
F_62 ( V_2 , V_18 -> V_39 , V_38 ) ;
memcpy ( V_2 -> V_28 , V_140 -> V_154 , V_155 ) ;
#ifdef F_70
V_57 = V_18 ;
V_156 = V_2 ;
#endif
V_18 -> V_14 = (struct V_13 * ) & V_142 -> V_157 [ 0 ] ;
V_18 -> V_9 = & V_142 -> V_158 ;
V_18 -> V_128 = V_116 ;
V_18 -> V_20 = V_134 ;
V_18 -> V_9 -> V_159 = 0x161 ;
V_18 -> V_9 -> V_160 = V_161 | V_162 |
V_163 | V_164 | 0x026 ;
V_18 -> V_9 -> V_159 = 0x161 ;
V_18 -> V_9 -> V_160 = V_161 | V_162 |
V_163 | V_164 | 0x026 ;
F_4 ( V_18 -> V_9 ) ;
V_18 -> V_66 = ! ( V_18 -> V_14 -> V_26 . V_165 . V_166 [ 0 ] & 0xff ) ;
if ( V_18 -> V_66 )
V_18 -> V_69 = V_97 | V_167 |
V_168 | V_169 |
V_170 ;
V_2 -> V_171 = & V_172 ;
V_2 -> V_173 = ( 200 * V_174 ) / 1000 ;
V_2 -> V_113 = V_113 ;
if ( F_71 ( V_2 ) ) {
F_21 ( V_117 L_11
L_12 ) ;
V_65 = - V_175 ;
goto V_176;
}
F_21 ( V_177 L_13 , V_2 -> V_128 , V_116 , V_2 -> V_28 ) ;
return 0 ;
V_176:
F_72 ( ( unsigned long ) V_18 -> V_147 ) ;
V_151:
F_73 ( V_2 ) ;
V_146:
return V_65 ;
}
static int F_74 ( struct V_137 * V_138 )
{
struct V_1 * V_2 = F_75 ( V_138 ) ;
struct V_17 * V_18 = F_9 ( V_2 ) ;
F_76 ( V_2 ) ;
F_77 ( & V_138 -> V_2 , sizeof( * V_18 -> V_147 ) , V_18 -> V_147 ,
V_18 -> V_148 , V_150 ) ;
F_73 ( V_2 ) ;
return 0 ;
}
