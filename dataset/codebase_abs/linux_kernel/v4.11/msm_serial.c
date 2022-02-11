static
void F_1 ( struct V_1 * V_2 , unsigned int V_3 , unsigned int V_4 )
{
F_2 ( V_3 , V_2 -> V_5 + V_4 ) ;
}
static
unsigned int F_3 ( struct V_1 * V_2 , unsigned int V_4 )
{
return F_4 ( V_2 -> V_5 + V_4 ) ;
}
static void F_5 ( struct V_1 * V_2 )
{
F_1 ( V_2 , 0x06 , V_6 ) ;
F_1 ( V_2 , 0xF1 , V_7 ) ;
F_1 ( V_2 , 0x0F , V_8 ) ;
F_1 ( V_2 , 0x1A , V_9 ) ;
V_2 -> V_10 = 1843200 ;
}
static void F_6 ( struct V_1 * V_2 )
{
F_1 ( V_2 , 0x18 , V_6 ) ;
F_1 ( V_2 , 0xF6 , V_7 ) ;
F_1 ( V_2 , 0x0F , V_8 ) ;
F_1 ( V_2 , 0x0A , V_9 ) ;
V_2 -> V_10 = 1843200 ;
}
static void F_7 ( struct V_1 * V_2 )
{
struct V_11 * V_11 = F_8 ( V_2 ) ;
if ( V_11 -> V_12 )
return;
if ( V_2 -> V_10 == 19200000 )
F_5 ( V_2 ) ;
else if ( V_2 -> V_10 == 4800000 )
F_6 ( V_2 ) ;
}
static void F_9 ( struct V_1 * V_2 , struct V_13 * V_14 )
{
struct V_15 * V_16 = V_2 -> V_16 ;
unsigned int V_17 ;
T_1 V_3 ;
V_17 = V_14 -> V_18 ;
V_14 -> V_18 = 0 ;
F_10 ( V_14 -> V_19 ) ;
V_3 = F_3 ( V_2 , V_20 ) ;
V_3 &= ~ V_14 -> V_21 ;
F_1 ( V_2 , V_3 , V_20 ) ;
if ( V_17 )
F_11 ( V_16 , V_14 -> V_22 , V_17 , V_14 -> V_23 ) ;
}
static void F_12 ( struct V_11 * V_11 )
{
struct V_13 * V_14 ;
V_14 = & V_11 -> V_24 ;
if ( V_14 -> V_19 ) {
F_9 ( & V_11 -> V_25 , V_14 ) ;
F_13 ( V_14 -> V_19 ) ;
}
memset ( V_14 , 0 , sizeof( * V_14 ) ) ;
V_14 = & V_11 -> V_26 ;
if ( V_14 -> V_19 ) {
F_9 ( & V_11 -> V_25 , V_14 ) ;
F_13 ( V_14 -> V_19 ) ;
F_14 ( V_14 -> V_27 ) ;
}
memset ( V_14 , 0 , sizeof( * V_14 ) ) ;
}
static void F_15 ( struct V_11 * V_11 , T_2 V_28 )
{
struct V_15 * V_16 = V_11 -> V_25 . V_16 ;
struct V_29 V_30 ;
struct V_13 * V_14 ;
T_1 V_31 = 0 ;
int V_32 ;
V_14 = & V_11 -> V_24 ;
V_14 -> V_19 = F_16 ( V_16 , L_1 ) ;
if ( F_17 ( V_14 -> V_19 ) )
goto V_33;
F_18 ( V_16 -> V_34 , L_2 , & V_31 ) ;
memset ( & V_30 , 0 , sizeof( V_30 ) ) ;
V_30 . V_35 = V_36 ;
V_30 . V_37 = true ;
V_30 . V_38 = V_28 + V_39 ;
V_30 . V_40 = V_41 ;
V_30 . V_42 = V_31 ;
V_32 = F_19 ( V_14 -> V_19 , & V_30 ) ;
if ( V_32 )
goto V_43;
V_14 -> V_23 = V_44 ;
if ( V_11 -> V_12 < V_45 )
V_14 -> V_21 = V_46 ;
else
V_14 -> V_21 = V_47 ;
return;
V_43:
F_13 ( V_14 -> V_19 ) ;
V_33:
memset ( V_14 , 0 , sizeof( * V_14 ) ) ;
}
static void F_20 ( struct V_11 * V_11 , T_2 V_28 )
{
struct V_15 * V_16 = V_11 -> V_25 . V_16 ;
struct V_29 V_30 ;
struct V_13 * V_14 ;
T_1 V_31 = 0 ;
int V_32 ;
V_14 = & V_11 -> V_26 ;
V_14 -> V_19 = F_16 ( V_16 , L_3 ) ;
if ( F_17 ( V_14 -> V_19 ) )
goto V_48;
F_18 ( V_16 -> V_34 , L_4 , & V_31 ) ;
V_14 -> V_27 = F_21 ( V_49 , V_50 ) ;
if ( ! V_14 -> V_27 )
goto V_51;
memset ( & V_30 , 0 , sizeof( V_30 ) ) ;
V_30 . V_35 = V_52 ;
V_30 . V_37 = true ;
V_30 . V_53 = V_28 + V_54 ;
V_30 . V_55 = V_41 ;
V_30 . V_42 = V_31 ;
V_32 = F_19 ( V_14 -> V_19 , & V_30 ) ;
if ( V_32 )
goto V_56;
V_14 -> V_23 = V_57 ;
if ( V_11 -> V_12 < V_45 )
V_14 -> V_21 = V_58 ;
else
V_14 -> V_21 = V_59 ;
return;
V_56:
F_14 ( V_14 -> V_27 ) ;
V_51:
F_13 ( V_14 -> V_19 ) ;
V_48:
memset ( V_14 , 0 , sizeof( * V_14 ) ) ;
}
static inline void F_22 ( struct V_1 * V_2 )
{
while ( ! ( F_3 ( V_2 , V_60 ) & V_61 ) ) {
if ( F_3 ( V_2 , V_62 ) & V_63 )
break;
F_23 ( 1 ) ;
}
F_1 ( V_2 , V_64 , V_65 ) ;
}
static void F_24 ( struct V_1 * V_2 )
{
struct V_11 * V_11 = F_8 ( V_2 ) ;
V_11 -> V_66 &= ~ V_67 ;
F_1 ( V_2 , V_11 -> V_66 , V_68 ) ;
}
static void F_25 ( struct V_1 * V_2 )
{
struct V_11 * V_11 = F_8 ( V_2 ) ;
struct V_13 * V_14 = & V_11 -> V_24 ;
if ( V_14 -> V_18 )
return;
V_11 -> V_66 |= V_67 ;
F_1 ( V_2 , V_11 -> V_66 , V_68 ) ;
}
static void F_26 ( struct V_1 * V_2 , int V_18 )
{
F_22 ( V_2 ) ;
F_1 ( V_2 , V_18 , V_69 ) ;
F_3 ( V_2 , V_69 ) ;
}
static void F_27 ( void * args )
{
struct V_11 * V_11 = args ;
struct V_1 * V_2 = & V_11 -> V_25 ;
struct V_70 * V_71 = & V_2 -> V_72 -> V_71 ;
struct V_13 * V_14 = & V_11 -> V_24 ;
struct V_73 V_72 ;
enum V_74 V_75 ;
unsigned long V_76 ;
unsigned int V_18 ;
T_1 V_3 ;
F_28 ( & V_2 -> V_77 , V_76 ) ;
if ( ! V_14 -> V_18 )
goto V_78;
V_75 = F_29 ( V_14 -> V_19 , V_14 -> V_79 , & V_72 ) ;
F_11 ( V_2 -> V_16 , V_14 -> V_22 , V_14 -> V_18 , V_14 -> V_23 ) ;
V_3 = F_3 ( V_2 , V_20 ) ;
V_3 &= ~ V_14 -> V_21 ;
F_1 ( V_2 , V_3 , V_20 ) ;
if ( V_11 -> V_12 > V_80 ) {
F_1 ( V_2 , V_81 , V_65 ) ;
F_1 ( V_2 , V_82 , V_65 ) ;
}
V_18 = V_14 -> V_18 - V_72 . V_83 ;
V_2 -> V_84 . V_85 += V_18 ;
V_14 -> V_18 = 0 ;
V_71 -> V_86 += V_18 ;
V_71 -> V_86 &= V_87 - 1 ;
V_11 -> V_66 |= V_67 ;
F_1 ( V_2 , V_11 -> V_66 , V_68 ) ;
if ( F_30 ( V_71 ) < V_88 )
F_31 ( V_2 ) ;
F_32 ( V_2 ) ;
V_78:
F_33 ( & V_2 -> V_77 , V_76 ) ;
}
static int F_34 ( struct V_11 * V_11 , unsigned int V_18 )
{
struct V_70 * V_71 = & V_11 -> V_25 . V_72 -> V_71 ;
struct V_1 * V_2 = & V_11 -> V_25 ;
struct V_13 * V_14 = & V_11 -> V_24 ;
void * V_89 ;
int V_32 ;
T_1 V_3 ;
V_89 = & V_71 -> V_90 [ V_71 -> V_86 ] ;
V_14 -> V_22 = F_35 ( V_2 -> V_16 , V_89 , V_18 , V_14 -> V_23 ) ;
V_32 = F_36 ( V_2 -> V_16 , V_14 -> V_22 ) ;
if ( V_32 )
return V_32 ;
V_14 -> V_91 = F_37 ( V_14 -> V_19 , V_14 -> V_22 ,
V_18 , V_36 ,
V_92 |
V_93 ) ;
if ( ! V_14 -> V_91 ) {
V_32 = - V_94 ;
goto V_95;
}
V_14 -> V_91 -> V_96 = F_27 ;
V_14 -> V_91 -> V_97 = V_11 ;
V_14 -> V_79 = F_38 ( V_14 -> V_91 ) ;
V_32 = F_39 ( V_14 -> V_79 ) ;
if ( V_32 )
goto V_95;
V_11 -> V_66 &= ~ V_67 ;
F_1 ( V_2 , V_11 -> V_66 , V_68 ) ;
V_14 -> V_18 = V_18 ;
V_3 = F_3 ( V_2 , V_20 ) ;
V_3 |= V_14 -> V_21 ;
if ( V_11 -> V_12 < V_45 )
F_1 ( V_2 , V_3 , V_20 ) ;
F_26 ( V_2 , V_18 ) ;
if ( V_11 -> V_12 > V_80 )
F_1 ( V_2 , V_3 , V_20 ) ;
F_40 ( V_14 -> V_19 ) ;
return 0 ;
V_95:
F_11 ( V_2 -> V_16 , V_14 -> V_22 , V_18 , V_14 -> V_23 ) ;
return V_32 ;
}
static void F_41 ( void * args )
{
struct V_11 * V_11 = args ;
struct V_1 * V_2 = & V_11 -> V_25 ;
struct V_98 * V_99 = & V_2 -> V_72 -> V_2 ;
struct V_13 * V_14 = & V_11 -> V_26 ;
int V_18 = 0 , V_100 , V_101 ;
unsigned long V_76 ;
T_1 V_3 ;
F_28 ( & V_2 -> V_77 , V_76 ) ;
if ( ! V_14 -> V_18 )
goto V_78;
V_3 = F_3 ( V_2 , V_20 ) ;
V_3 &= ~ V_14 -> V_21 ;
F_1 ( V_2 , V_3 , V_20 ) ;
if ( F_3 ( V_2 , V_60 ) & V_102 ) {
V_2 -> V_84 . V_103 ++ ;
F_42 ( V_99 , 0 , V_104 ) ;
F_1 ( V_2 , V_105 , V_65 ) ;
}
V_18 = F_3 ( V_2 , V_106 ) ;
V_2 -> V_84 . V_107 += V_18 ;
V_14 -> V_18 = 0 ;
F_11 ( V_2 -> V_16 , V_14 -> V_22 , V_49 , V_14 -> V_23 ) ;
for ( V_100 = 0 ; V_100 < V_18 ; V_100 ++ ) {
char V_108 = V_109 ;
if ( V_11 -> V_110 && V_14 -> V_27 [ V_100 ] == 0 ) {
V_2 -> V_84 . V_111 ++ ;
V_108 = V_112 ;
V_11 -> V_110 = false ;
if ( F_43 ( V_2 ) )
continue;
}
if ( ! ( V_2 -> V_113 & V_114 ) )
V_108 = V_109 ;
F_33 ( & V_2 -> V_77 , V_76 ) ;
V_101 = F_44 ( V_2 , V_14 -> V_27 [ V_100 ] ) ;
F_28 ( & V_2 -> V_77 , V_76 ) ;
if ( ! V_101 )
F_42 ( V_99 , V_14 -> V_27 [ V_100 ] , V_108 ) ;
}
F_45 ( V_11 ) ;
V_78:
F_33 ( & V_2 -> V_77 , V_76 ) ;
if ( V_18 )
F_46 ( V_99 ) ;
}
static void F_45 ( struct V_11 * V_11 )
{
struct V_13 * V_14 = & V_11 -> V_26 ;
struct V_1 * V_25 = & V_11 -> V_25 ;
T_1 V_3 ;
int V_32 ;
if ( ! V_14 -> V_19 )
return;
V_14 -> V_22 = F_35 ( V_25 -> V_16 , V_14 -> V_27 ,
V_49 , V_14 -> V_23 ) ;
V_32 = F_36 ( V_25 -> V_16 , V_14 -> V_22 ) ;
if ( V_32 )
return;
V_14 -> V_91 = F_37 ( V_14 -> V_19 , V_14 -> V_22 ,
V_49 , V_52 ,
V_92 ) ;
if ( ! V_14 -> V_91 )
goto V_95;
V_14 -> V_91 -> V_96 = F_41 ;
V_14 -> V_91 -> V_97 = V_11 ;
V_14 -> V_79 = F_38 ( V_14 -> V_91 ) ;
V_32 = F_39 ( V_14 -> V_79 ) ;
if ( V_32 )
goto V_95;
V_11 -> V_66 &= ~ ( V_115 | V_116 ) ;
if ( V_11 -> V_12 < V_45 )
V_11 -> V_66 |= V_116 ;
F_1 ( V_25 , V_11 -> V_66 , V_68 ) ;
V_14 -> V_18 = V_49 ;
F_40 ( V_14 -> V_19 ) ;
F_1 ( V_25 , V_117 , V_65 ) ;
F_1 ( V_25 , V_118 , V_65 ) ;
V_3 = F_3 ( V_25 , V_20 ) ;
V_3 |= V_14 -> V_21 ;
if ( V_11 -> V_12 < V_45 )
F_1 ( V_25 , V_3 , V_20 ) ;
F_1 ( V_25 , V_49 , V_119 ) ;
if ( V_11 -> V_12 > V_80 )
F_1 ( V_25 , V_3 , V_20 ) ;
return;
V_95:
F_11 ( V_25 -> V_16 , V_14 -> V_22 , V_49 , V_14 -> V_23 ) ;
}
static void F_47 ( struct V_1 * V_2 )
{
struct V_11 * V_11 = F_8 ( V_2 ) ;
struct V_13 * V_14 = & V_11 -> V_26 ;
V_11 -> V_66 &= ~ ( V_115 | V_116 ) ;
F_1 ( V_2 , V_11 -> V_66 , V_68 ) ;
if ( V_14 -> V_19 )
F_9 ( V_2 , V_14 ) ;
}
static void F_48 ( struct V_1 * V_2 )
{
struct V_11 * V_11 = F_8 ( V_2 ) ;
V_11 -> V_66 |= V_120 ;
F_1 ( V_2 , V_11 -> V_66 , V_68 ) ;
}
static void F_49 ( struct V_1 * V_2 , unsigned int V_121 )
{
struct V_98 * V_99 = & V_2 -> V_72 -> V_2 ;
unsigned int V_122 ;
int V_18 = 0 ;
struct V_11 * V_11 = F_8 ( V_2 ) ;
if ( ( F_3 ( V_2 , V_60 ) & V_102 ) ) {
V_2 -> V_84 . V_103 ++ ;
F_42 ( V_99 , 0 , V_104 ) ;
F_1 ( V_2 , V_105 , V_65 ) ;
}
if ( V_121 & V_116 ) {
V_18 = F_3 ( V_2 , V_106 ) -
V_11 -> V_123 ;
V_11 -> V_123 = 0 ;
} else {
V_18 = 4 * ( F_3 ( V_2 , V_124 ) ) ;
V_11 -> V_123 += V_18 ;
}
V_2 -> V_84 . V_107 += V_18 ;
while ( V_18 > 0 ) {
unsigned char V_90 [ 4 ] ;
int V_101 , V_125 , V_100 ;
V_122 = F_3 ( V_2 , V_60 ) ;
if ( ( V_122 & V_126 ) == 0 ) {
V_11 -> V_123 -= V_18 ;
break;
}
F_50 ( V_2 -> V_5 + V_54 , V_90 , 1 ) ;
V_125 = F_51 ( int , V_18 , sizeof( V_90 ) ) ;
for ( V_100 = 0 ; V_100 < V_125 ; V_100 ++ ) {
char V_108 = V_109 ;
if ( V_11 -> V_110 && V_90 [ V_100 ] == 0 ) {
V_2 -> V_84 . V_111 ++ ;
V_108 = V_112 ;
V_11 -> V_110 = false ;
if ( F_43 ( V_2 ) )
continue;
}
if ( ! ( V_2 -> V_113 & V_114 ) )
V_108 = V_109 ;
F_52 ( & V_2 -> V_77 ) ;
V_101 = F_44 ( V_2 , V_90 [ V_100 ] ) ;
F_53 ( & V_2 -> V_77 ) ;
if ( ! V_101 )
F_42 ( V_99 , V_90 [ V_100 ] , V_108 ) ;
}
V_18 -= V_125 ;
}
F_52 ( & V_2 -> V_77 ) ;
F_46 ( V_99 ) ;
F_53 ( & V_2 -> V_77 ) ;
if ( V_121 & ( V_116 ) )
F_1 ( V_2 , V_117 , V_65 ) ;
F_1 ( V_2 , 0xFFFFFF , V_119 ) ;
F_1 ( V_2 , V_118 , V_65 ) ;
F_45 ( V_11 ) ;
}
static void F_54 ( struct V_1 * V_2 )
{
struct V_98 * V_99 = & V_2 -> V_72 -> V_2 ;
unsigned int V_122 ;
if ( ( F_3 ( V_2 , V_60 ) & V_102 ) ) {
V_2 -> V_84 . V_103 ++ ;
F_42 ( V_99 , 0 , V_104 ) ;
F_1 ( V_2 , V_105 , V_65 ) ;
}
while ( ( V_122 = F_3 ( V_2 , V_60 ) ) & V_126 ) {
unsigned int V_127 ;
char V_108 = V_109 ;
int V_101 ;
V_127 = F_3 ( V_2 , V_128 ) ;
if ( V_122 & V_114 ) {
V_2 -> V_84 . V_111 ++ ;
if ( F_43 ( V_2 ) )
continue;
} else if ( V_122 & V_129 ) {
V_2 -> V_84 . V_130 ++ ;
} else {
V_2 -> V_84 . V_107 ++ ;
}
V_122 &= V_2 -> V_113 ;
if ( V_122 & V_114 )
V_108 = V_112 ;
else if ( V_122 & V_129 )
V_108 = V_131 ;
F_52 ( & V_2 -> V_77 ) ;
V_101 = F_44 ( V_2 , V_127 ) ;
F_53 ( & V_2 -> V_77 ) ;
if ( ! V_101 )
F_42 ( V_99 , V_127 , V_108 ) ;
}
F_52 ( & V_2 -> V_77 ) ;
F_46 ( V_99 ) ;
F_53 ( & V_2 -> V_77 ) ;
}
static void F_55 ( struct V_1 * V_2 , unsigned int V_132 )
{
struct V_70 * V_71 = & V_2 -> V_72 -> V_71 ;
struct V_11 * V_11 = F_8 ( V_2 ) ;
unsigned int V_133 ;
unsigned int V_134 = 0 ;
void T_3 * V_135 ;
if ( V_11 -> V_12 )
V_135 = V_2 -> V_5 + V_39 ;
else
V_135 = V_2 -> V_5 + V_136 ;
if ( V_132 && V_11 -> V_12 )
F_26 ( V_2 , V_132 ) ;
while ( V_134 < V_132 ) {
int V_100 ;
char V_90 [ 4 ] = { 0 } ;
if ( ! ( F_3 ( V_2 , V_60 ) & V_137 ) )
break;
if ( V_11 -> V_12 )
V_133 = F_56 ( V_132 - V_134 ,
( unsigned int ) sizeof( V_90 ) ) ;
else
V_133 = 1 ;
for ( V_100 = 0 ; V_100 < V_133 ; V_100 ++ ) {
V_90 [ V_100 ] = V_71 -> V_90 [ V_71 -> V_86 + V_100 ] ;
V_2 -> V_84 . V_85 ++ ;
}
F_57 ( V_135 , V_90 , 1 ) ;
V_71 -> V_86 = ( V_71 -> V_86 + V_133 ) & ( V_87 - 1 ) ;
V_134 += V_133 ;
}
if ( F_58 ( V_71 ) )
F_24 ( V_2 ) ;
if ( F_30 ( V_71 ) < V_88 )
F_31 ( V_2 ) ;
}
static void F_32 ( struct V_1 * V_2 )
{
struct V_11 * V_11 = F_8 ( V_2 ) ;
struct V_70 * V_71 = & V_11 -> V_25 . V_72 -> V_71 ;
struct V_13 * V_14 = & V_11 -> V_24 ;
unsigned int V_138 , V_139 , V_140 ;
void T_3 * V_135 ;
int V_56 = 0 ;
if ( V_2 -> V_141 ) {
if ( V_11 -> V_12 )
V_135 = V_2 -> V_5 + V_39 ;
else
V_135 = V_2 -> V_5 + V_136 ;
if ( V_11 -> V_12 )
F_26 ( V_2 , 1 ) ;
F_59 ( V_135 , & V_2 -> V_141 , 1 ) ;
V_2 -> V_84 . V_85 ++ ;
V_2 -> V_141 = 0 ;
return;
}
if ( F_58 ( V_71 ) || F_60 ( V_2 ) ) {
F_24 ( V_2 ) ;
return;
}
V_138 = F_61 ( V_71 -> V_142 , V_71 -> V_86 , V_87 ) ;
V_139 = F_61 ( V_71 -> V_142 , V_71 -> V_86 , V_87 ) ;
V_140 = 1 ;
if ( V_11 -> V_12 > V_80 ) {
V_139 = F_62 ( V_139 ) ;
V_140 = V_41 ;
} else {
if ( V_139 > V_143 )
V_139 = V_143 ;
}
if ( V_138 > V_2 -> V_144 )
V_138 = V_2 -> V_144 ;
if ( ! V_14 -> V_19 || V_139 < V_140 )
F_55 ( V_2 , V_138 ) ;
else
V_56 = F_34 ( V_11 , V_139 ) ;
if ( V_56 )
F_55 ( V_2 , V_138 ) ;
}
static void F_63 ( struct V_1 * V_2 )
{
F_1 ( V_2 , V_145 , V_65 ) ;
V_2 -> V_84 . V_146 ++ ;
F_64 ( & V_2 -> V_72 -> V_2 . V_147 ) ;
}
static T_4 F_65 ( int V_148 , void * V_149 )
{
struct V_1 * V_2 = V_149 ;
struct V_11 * V_11 = F_8 ( V_2 ) ;
struct V_13 * V_14 = & V_11 -> V_26 ;
unsigned long V_76 ;
unsigned int V_121 ;
T_1 V_3 ;
F_28 ( & V_2 -> V_77 , V_76 ) ;
V_121 = F_3 ( V_2 , V_150 ) ;
F_1 ( V_2 , 0 , V_68 ) ;
if ( V_121 & V_151 ) {
V_11 -> V_110 = true ;
F_1 ( V_2 , V_152 , V_65 ) ;
}
if ( V_121 & ( V_115 | V_116 ) ) {
if ( V_14 -> V_18 ) {
V_3 = V_153 ;
F_1 ( V_2 , V_3 , V_65 ) ;
V_3 = V_117 ;
F_1 ( V_2 , V_3 , V_65 ) ;
F_10 ( V_14 -> V_19 ) ;
} else if ( V_11 -> V_12 ) {
F_49 ( V_2 , V_121 ) ;
} else {
F_54 ( V_2 ) ;
}
}
if ( V_121 & V_67 )
F_32 ( V_2 ) ;
if ( V_121 & V_120 )
F_63 ( V_2 ) ;
F_1 ( V_2 , V_11 -> V_66 , V_68 ) ;
F_33 ( & V_2 -> V_77 , V_76 ) ;
return V_154 ;
}
static unsigned int F_66 ( struct V_1 * V_2 )
{
return ( F_3 ( V_2 , V_60 ) & V_61 ) ? V_155 : 0 ;
}
static unsigned int F_67 ( struct V_1 * V_2 )
{
return V_156 | V_157 | V_158 | V_159 ;
}
static void F_68 ( struct V_1 * V_2 )
{
struct V_11 * V_11 = F_8 ( V_2 ) ;
F_1 ( V_2 , V_160 , V_65 ) ;
F_1 ( V_2 , V_81 , V_65 ) ;
F_1 ( V_2 , V_105 , V_65 ) ;
F_1 ( V_2 , V_161 , V_65 ) ;
F_1 ( V_2 , V_145 , V_65 ) ;
F_1 ( V_2 , V_162 , V_65 ) ;
if ( V_11 -> V_12 )
F_1 ( V_2 , 0 , V_20 ) ;
}
static void F_69 ( struct V_1 * V_2 , unsigned int V_163 )
{
unsigned int V_164 ;
V_164 = F_3 ( V_2 , V_165 ) ;
if ( ! ( V_163 & V_159 ) ) {
V_164 &= ~ V_166 ;
F_1 ( V_2 , V_164 , V_165 ) ;
F_1 ( V_2 , V_167 , V_65 ) ;
} else {
V_164 |= V_166 ;
F_1 ( V_2 , V_164 , V_165 ) ;
}
}
static void F_70 ( struct V_1 * V_2 , int V_168 )
{
if ( V_168 )
F_1 ( V_2 , V_169 , V_65 ) ;
else
F_1 ( V_2 , V_170 , V_65 ) ;
}
static const struct V_171 *
F_71 ( struct V_1 * V_2 , unsigned int V_172 ,
unsigned long * V_173 )
{
struct V_11 * V_11 = F_8 ( V_2 ) ;
unsigned int V_174 , V_175 ;
unsigned long V_176 , V_177 , V_178 = 0 , V_179 , V_180 = V_181 ;
const struct V_171 * V_182 , * V_183 , * V_184 ;
static const struct V_171 V_185 [] = {
{ 1 , 0xff , 31 } ,
{ 2 , 0xee , 16 } ,
{ 3 , 0xdd , 8 } ,
{ 4 , 0xcc , 6 } ,
{ 6 , 0xbb , 6 } ,
{ 8 , 0xaa , 6 } ,
{ 12 , 0x99 , 6 } ,
{ 16 , 0x88 , 1 } ,
{ 24 , 0x77 , 1 } ,
{ 32 , 0x66 , 1 } ,
{ 48 , 0x55 , 1 } ,
{ 96 , 0x44 , 1 } ,
{ 192 , 0x33 , 1 } ,
{ 384 , 0x22 , 1 } ,
{ 768 , 0x11 , 1 } ,
{ 1536 , 0x00 , 1 } ,
} ;
V_184 = V_185 ;
V_176 = F_72 ( V_11 -> V_186 , 16 * V_172 ) ;
V_174 = F_73 ( V_176 , 16 * V_172 ) ;
V_183 = V_185 + F_74 ( V_185 ) ;
V_182 = V_185 ;
while ( V_182 < V_183 ) {
if ( V_182 -> V_174 <= V_174 ) {
V_175 = V_176 / V_182 -> V_174 / 16 ;
V_179 = abs ( V_175 - V_172 ) ;
if ( V_179 < V_180 ) {
V_180 = V_179 ;
V_184 = V_182 ;
V_178 = V_176 ;
}
if ( V_175 == V_172 )
break;
} else if ( V_182 -> V_174 > V_174 ) {
V_177 = V_176 ;
V_176 = F_72 ( V_11 -> V_186 , V_177 + 1 ) ;
if ( V_176 == V_177 )
break;
V_182 = V_185 ;
V_174 = F_73 ( V_176 , 16 * V_172 ) ;
continue;
}
V_182 ++ ;
}
* V_173 = V_178 ;
return V_184 ;
}
static int F_75 ( struct V_1 * V_2 , unsigned int V_172 ,
unsigned long * V_187 )
{
unsigned int V_188 , V_189 , V_190 ;
struct V_11 * V_11 = F_8 ( V_2 ) ;
const struct V_171 * V_182 ;
unsigned long V_76 , V_173 ;
V_76 = * V_187 ;
F_33 ( & V_2 -> V_77 , V_76 ) ;
V_182 = F_71 ( V_2 , V_172 , & V_173 ) ;
F_76 ( V_11 -> V_186 , V_173 ) ;
V_172 = V_173 / 16 / V_182 -> V_174 ;
F_28 ( & V_2 -> V_77 , V_76 ) ;
* V_187 = V_76 ;
V_2 -> V_10 = V_173 ;
F_1 ( V_2 , V_182 -> V_191 , V_192 ) ;
V_188 = V_182 -> V_188 ;
V_189 = V_193 & V_188 ;
if ( V_11 -> V_12 ) {
V_190 = V_194 ;
} else {
V_189 |= V_195 ;
V_190 = V_196 ;
}
V_189 |= V_190 & ( V_188 << 2 ) ;
F_1 ( V_2 , V_189 , V_197 ) ;
V_189 = ( V_2 -> V_144 * 3 ) / 4 ;
F_1 ( V_2 , V_189 , V_124 ) ;
F_1 ( V_2 , 10 , V_198 ) ;
F_1 ( V_2 , V_199 , V_65 ) ;
F_68 ( V_2 ) ;
F_1 ( V_2 , V_82 | V_200 , V_65 ) ;
V_11 -> V_66 = V_115 | V_116 |
V_201 | V_151 ;
F_1 ( V_2 , V_11 -> V_66 , V_68 ) ;
if ( V_11 -> V_12 ) {
F_1 ( V_2 , V_117 , V_65 ) ;
F_1 ( V_2 , 0xFFFFFF , V_119 ) ;
F_1 ( V_2 , V_118 , V_65 ) ;
}
return V_172 ;
}
static void F_77 ( struct V_1 * V_2 )
{
struct V_11 * V_11 = F_8 ( V_2 ) ;
F_78 ( V_11 -> V_186 ) ;
F_78 ( V_11 -> V_202 ) ;
F_7 ( V_2 ) ;
}
static int F_79 ( struct V_1 * V_2 )
{
struct V_11 * V_11 = F_8 ( V_2 ) ;
unsigned int V_203 , V_204 , V_190 ;
int V_32 ;
snprintf ( V_11 -> V_205 , sizeof( V_11 -> V_205 ) ,
L_5 , V_2 -> line ) ;
V_32 = F_80 ( V_2 -> V_148 , F_65 , V_206 ,
V_11 -> V_205 , V_2 ) ;
if ( F_81 ( V_32 ) )
return V_32 ;
F_77 ( V_2 ) ;
if ( F_82 ( V_2 -> V_144 > 12 ) )
V_204 = V_2 -> V_144 - 12 ;
else
V_204 = V_2 -> V_144 ;
V_203 = F_3 ( V_2 , V_165 ) ;
if ( V_11 -> V_12 )
V_190 = V_207 ;
else
V_190 = V_208 ;
V_203 &= ~ V_190 ;
V_203 &= ~ V_209 ;
V_203 |= V_190 & ( V_204 << 2 ) ;
V_203 |= V_209 & V_204 ;
F_1 ( V_2 , V_203 , V_165 ) ;
if ( V_11 -> V_12 ) {
F_15 ( V_11 , V_11 -> V_25 . V_210 ) ;
F_20 ( V_11 , V_11 -> V_25 . V_210 ) ;
}
return 0 ;
}
static void F_83 ( struct V_1 * V_2 )
{
struct V_11 * V_11 = F_8 ( V_2 ) ;
V_11 -> V_66 = 0 ;
F_1 ( V_2 , 0 , V_68 ) ;
if ( V_11 -> V_12 )
F_12 ( V_11 ) ;
F_84 ( V_11 -> V_186 ) ;
F_85 ( V_2 -> V_148 , V_2 ) ;
}
static void F_86 ( struct V_1 * V_2 , struct V_211 * V_212 ,
struct V_211 * V_177 )
{
struct V_11 * V_11 = F_8 ( V_2 ) ;
struct V_13 * V_14 = & V_11 -> V_26 ;
unsigned long V_76 ;
unsigned int V_172 , V_164 ;
F_28 ( & V_2 -> V_77 , V_76 ) ;
if ( V_14 -> V_19 )
F_9 ( V_2 , V_14 ) ;
V_172 = F_87 ( V_2 , V_212 , V_177 , 300 , 4000000 ) ;
V_172 = F_75 ( V_2 , V_172 , & V_76 ) ;
if ( F_88 ( V_212 ) )
F_89 ( V_212 , V_172 , V_172 ) ;
V_164 = F_3 ( V_2 , V_213 ) ;
V_164 &= ~ V_214 ;
if ( V_212 -> V_215 & V_216 ) {
if ( V_212 -> V_215 & V_217 )
V_164 |= V_218 ;
else if ( V_212 -> V_215 & V_219 )
V_164 |= V_220 ;
else
V_164 |= V_221 ;
}
V_164 &= ~ V_222 ;
switch ( V_212 -> V_215 & V_223 ) {
case V_224 :
V_164 |= V_225 ;
break;
case V_226 :
V_164 |= V_227 ;
break;
case V_228 :
V_164 |= V_229 ;
break;
case V_230 :
default:
V_164 |= V_231 ;
break;
}
V_164 &= ~ ( V_232 | V_233 ) ;
if ( V_212 -> V_215 & V_234 )
V_164 |= V_233 ;
else
V_164 |= V_232 ;
F_1 ( V_2 , V_164 , V_213 ) ;
V_164 = F_3 ( V_2 , V_165 ) ;
V_164 &= ~ ( V_235 | V_166 ) ;
if ( V_212 -> V_215 & V_236 ) {
V_164 |= V_235 ;
V_164 |= V_166 ;
}
F_1 ( V_2 , V_164 , V_165 ) ;
V_2 -> V_113 = 0 ;
if ( V_212 -> V_237 & V_238 )
V_2 -> V_113 |= V_129 ;
if ( V_212 -> V_237 & ( V_239 | V_240 | V_241 ) )
V_2 -> V_113 |= V_114 ;
F_90 ( V_2 , V_212 -> V_215 , V_172 ) ;
F_45 ( V_11 ) ;
F_33 ( & V_2 -> V_77 , V_76 ) ;
}
static const char * F_91 ( struct V_1 * V_2 )
{
return L_6 ;
}
static void F_92 ( struct V_1 * V_2 )
{
struct V_242 * V_243 = F_93 ( V_2 -> V_16 ) ;
struct V_244 * V_245 ;
T_2 V_246 ;
V_245 = F_94 ( V_243 , V_247 , 0 ) ;
if ( F_81 ( ! V_245 ) )
return;
V_246 = F_95 ( V_245 ) ;
F_96 ( V_2 -> V_210 , V_246 ) ;
F_97 ( V_2 -> V_5 ) ;
V_2 -> V_5 = NULL ;
}
static int F_98 ( struct V_1 * V_2 )
{
struct V_242 * V_243 = F_93 ( V_2 -> V_16 ) ;
struct V_244 * V_245 ;
T_2 V_246 ;
int V_32 ;
V_245 = F_94 ( V_243 , V_247 , 0 ) ;
if ( F_81 ( ! V_245 ) )
return - V_248 ;
V_246 = F_95 ( V_245 ) ;
if ( ! F_99 ( V_2 -> V_210 , V_246 , L_7 ) )
return - V_249 ;
V_2 -> V_5 = F_100 ( V_2 -> V_210 , V_246 ) ;
if ( ! V_2 -> V_5 ) {
V_32 = - V_249 ;
goto V_250;
}
return 0 ;
V_250:
F_96 ( V_2 -> V_210 , V_246 ) ;
return V_32 ;
}
static void F_101 ( struct V_1 * V_2 , int V_76 )
{
int V_32 ;
if ( V_76 & V_251 ) {
V_2 -> type = V_252 ;
V_32 = F_98 ( V_2 ) ;
if ( V_32 )
return;
}
}
static int F_102 ( struct V_1 * V_2 , struct V_253 * V_254 )
{
if ( F_81 ( V_254 -> type != V_255 && V_254 -> type != V_252 ) )
return - V_256 ;
if ( F_81 ( V_2 -> V_148 != V_254 -> V_148 ) )
return - V_256 ;
return 0 ;
}
static void F_103 ( struct V_1 * V_2 , unsigned int V_72 ,
unsigned int V_257 )
{
struct V_11 * V_11 = F_8 ( V_2 ) ;
switch ( V_72 ) {
case 0 :
F_78 ( V_11 -> V_186 ) ;
F_78 ( V_11 -> V_202 ) ;
break;
case 3 :
F_84 ( V_11 -> V_186 ) ;
F_84 ( V_11 -> V_202 ) ;
break;
default:
F_104 ( L_8 , V_72 ) ;
}
}
static int F_105 ( struct V_1 * V_2 )
{
struct V_11 * V_11 = F_8 ( V_2 ) ;
unsigned int V_258 = V_11 -> V_12 ? V_54 : V_128 ;
if ( ! ( F_3 ( V_2 , V_60 ) & V_126 ) )
return V_259 ;
return F_3 ( V_2 , V_258 ) & 0xff ;
}
static int F_106 ( struct V_1 * V_2 )
{
int V_127 ;
static T_1 V_260 ;
static int V_18 ;
unsigned char * V_261 = ( unsigned char * ) & V_260 ;
if ( V_18 ) {
V_127 = V_261 [ sizeof( V_260 ) - V_18 ] ;
V_18 -- ;
} else if ( ! ( F_3 ( V_2 , V_60 ) & V_126 ) ) {
V_18 = F_3 ( V_2 , V_262 ) ;
V_18 = ( V_18 >> V_263 ) & V_264 ;
if ( V_18 ) {
F_1 ( V_2 , V_265 , V_65 ) ;
V_260 = F_3 ( V_2 , V_54 ) ;
V_127 = V_261 [ 0 ] ;
V_18 -- ;
F_1 ( V_2 , V_117 , V_65 ) ;
F_1 ( V_2 , 0xFFFFFF , V_119 ) ;
F_1 ( V_2 , V_118 ,
V_65 ) ;
} else {
V_127 = V_259 ;
}
} else {
V_260 = F_3 ( V_2 , V_54 ) ;
V_127 = V_261 [ 0 ] ;
V_18 = sizeof( V_260 ) - 1 ;
}
return V_127 ;
}
static int F_107 ( struct V_1 * V_2 )
{
T_1 V_66 ;
int V_127 ;
struct V_11 * V_11 = F_8 ( V_2 ) ;
V_66 = F_3 ( V_2 , V_68 ) ;
F_1 ( V_2 , 0 , V_68 ) ;
if ( V_11 -> V_12 )
V_127 = F_106 ( V_2 ) ;
else
V_127 = F_105 ( V_2 ) ;
F_1 ( V_2 , V_66 , V_68 ) ;
return V_127 ;
}
static void F_108 ( struct V_1 * V_2 , unsigned char V_127 )
{
T_1 V_66 ;
struct V_11 * V_11 = F_8 ( V_2 ) ;
V_66 = F_3 ( V_2 , V_68 ) ;
F_1 ( V_2 , 0 , V_68 ) ;
if ( V_11 -> V_12 )
F_26 ( V_2 , 1 ) ;
while ( ! ( F_3 ( V_2 , V_60 ) & V_137 ) )
F_109 () ;
F_1 ( V_2 , V_127 , V_11 -> V_12 ? V_39 : V_136 ) ;
while ( ! ( F_3 ( V_2 , V_60 ) & V_137 ) )
F_109 () ;
F_1 ( V_2 , V_66 , V_68 ) ;
}
static inline struct V_1 * F_110 ( unsigned int line )
{
return & V_266 [ line ] . V_25 ;
}
static void F_111 ( struct V_1 * V_2 , const char * V_267 ,
unsigned int V_18 , bool V_12 )
{
int V_100 ;
int V_268 = 0 ;
bool V_269 = false ;
void T_3 * V_135 ;
if ( V_12 )
V_135 = V_2 -> V_5 + V_39 ;
else
V_135 = V_2 -> V_5 + V_136 ;
for ( V_100 = 0 ; V_100 < V_18 ; V_100 ++ )
if ( V_267 [ V_100 ] == '\n' )
V_268 ++ ;
V_18 += V_268 ;
F_53 ( & V_2 -> V_77 ) ;
if ( V_12 )
F_26 ( V_2 , V_18 ) ;
V_100 = 0 ;
while ( V_100 < V_18 ) {
int V_270 ;
unsigned int V_133 ;
char V_90 [ 4 ] = { 0 } ;
if ( V_12 )
V_133 = F_56 ( V_18 - V_100 , ( unsigned int ) sizeof( V_90 ) ) ;
else
V_133 = 1 ;
for ( V_270 = 0 ; V_270 < V_133 ; V_270 ++ ) {
char V_127 = * V_267 ;
if ( V_127 == '\n' && ! V_269 ) {
V_90 [ V_270 ] = '\r' ;
V_270 ++ ;
V_269 = true ;
}
if ( V_270 < V_133 ) {
V_90 [ V_270 ] = V_127 ;
V_267 ++ ;
V_269 = false ;
}
}
while ( ! ( F_3 ( V_2 , V_60 ) & V_137 ) )
F_109 () ;
F_57 ( V_135 , V_90 , 1 ) ;
V_100 += V_133 ;
}
F_52 ( & V_2 -> V_77 ) ;
}
static void F_112 ( struct V_271 * V_272 , const char * V_267 ,
unsigned int V_18 )
{
struct V_1 * V_2 ;
struct V_11 * V_11 ;
F_113 ( V_272 -> V_273 < 0 || V_272 -> V_273 >= V_274 ) ;
V_2 = F_110 ( V_272 -> V_273 ) ;
V_11 = F_8 ( V_2 ) ;
F_111 ( V_2 , V_267 , V_18 , V_11 -> V_12 ) ;
}
static int T_5 F_114 ( struct V_271 * V_272 , char * V_275 )
{
struct V_1 * V_2 ;
int V_172 = 115200 ;
int V_276 = 8 ;
int V_277 = 'n' ;
int V_278 = 'n' ;
if ( F_81 ( V_272 -> V_273 >= V_274 || V_272 -> V_273 < 0 ) )
return - V_248 ;
V_2 = F_110 ( V_272 -> V_273 ) ;
if ( F_81 ( ! V_2 -> V_5 ) )
return - V_248 ;
F_77 ( V_2 ) ;
if ( V_275 )
F_115 ( V_275 , & V_172 , & V_277 , & V_276 , & V_278 ) ;
F_116 ( L_9 , V_2 -> line ) ;
return F_117 ( V_2 , V_272 , V_172 , V_277 , V_276 , V_278 ) ;
}
static void
F_118 ( struct V_271 * V_279 , const char * V_267 , unsigned V_280 )
{
struct V_281 * V_16 = V_279 -> V_203 ;
F_111 ( & V_16 -> V_2 , V_267 , V_280 , false ) ;
}
static int T_5
F_119 ( struct V_281 * V_15 , const char * V_282 )
{
if ( ! V_15 -> V_2 . V_5 )
return - V_283 ;
V_15 -> V_279 -> V_284 = F_118 ;
return 0 ;
}
static void
F_120 ( struct V_271 * V_279 , const char * V_267 , unsigned V_280 )
{
struct V_281 * V_16 = V_279 -> V_203 ;
F_111 ( & V_16 -> V_2 , V_267 , V_280 , true ) ;
}
static int T_5
F_121 ( struct V_281 * V_15 ,
const char * V_282 )
{
if ( ! V_15 -> V_2 . V_5 )
return - V_283 ;
V_15 -> V_279 -> V_284 = F_120 ;
return 0 ;
}
static int F_122 ( struct V_242 * V_243 )
{
struct V_11 * V_11 ;
struct V_244 * V_244 ;
struct V_1 * V_2 ;
const struct V_285 * V_286 ;
int V_148 , line ;
if ( V_243 -> V_16 . V_34 )
line = F_123 ( V_243 -> V_16 . V_34 , L_10 ) ;
else
line = V_243 -> V_286 ;
if ( line < 0 )
line = F_124 ( & V_287 ) - 1 ;
if ( F_81 ( line < 0 || line >= V_274 ) )
return - V_248 ;
F_125 ( & V_243 -> V_16 , L_11 , line ) ;
V_2 = F_110 ( line ) ;
V_2 -> V_16 = & V_243 -> V_16 ;
V_11 = F_8 ( V_2 ) ;
V_286 = F_126 ( V_288 , & V_243 -> V_16 ) ;
if ( V_286 )
V_11 -> V_12 = ( unsigned long ) V_286 -> V_203 ;
else
V_11 -> V_12 = 0 ;
V_11 -> V_186 = F_127 ( & V_243 -> V_16 , L_12 ) ;
if ( F_17 ( V_11 -> V_186 ) )
return F_128 ( V_11 -> V_186 ) ;
if ( V_11 -> V_12 ) {
V_11 -> V_202 = F_127 ( & V_243 -> V_16 , L_13 ) ;
if ( F_17 ( V_11 -> V_202 ) )
return F_128 ( V_11 -> V_202 ) ;
}
V_2 -> V_10 = F_129 ( V_11 -> V_186 ) ;
F_125 ( & V_243 -> V_16 , L_14 , V_2 -> V_10 ) ;
V_244 = F_94 ( V_243 , V_247 , 0 ) ;
if ( F_81 ( ! V_244 ) )
return - V_248 ;
V_2 -> V_210 = V_244 -> V_289 ;
V_148 = F_130 ( V_243 , 0 ) ;
if ( F_81 ( V_148 < 0 ) )
return - V_248 ;
V_2 -> V_148 = V_148 ;
F_131 ( V_243 , V_2 ) ;
return F_132 ( & V_290 , V_2 ) ;
}
static int F_133 ( struct V_242 * V_243 )
{
struct V_1 * V_2 = F_134 ( V_243 ) ;
F_135 ( & V_290 , V_2 ) ;
return 0 ;
}
static int T_5 F_136 ( void )
{
int V_32 ;
V_32 = F_137 ( & V_290 ) ;
if ( F_81 ( V_32 ) )
return V_32 ;
V_32 = F_138 ( & V_291 ) ;
if ( F_81 ( V_32 ) )
F_139 ( & V_290 ) ;
F_116 ( L_15 ) ;
return V_32 ;
}
static void T_6 F_140 ( void )
{
F_141 ( & V_291 ) ;
F_139 ( & V_290 ) ;
}
