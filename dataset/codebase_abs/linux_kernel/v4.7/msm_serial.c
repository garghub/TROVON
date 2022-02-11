void F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_5 * V_6 = V_2 -> V_6 ;
unsigned int V_7 ;
T_1 V_8 ;
V_7 = V_4 -> V_9 ;
V_4 -> V_9 = 0 ;
F_2 ( V_4 -> V_10 ) ;
V_8 = F_3 ( V_2 , V_11 ) ;
V_8 &= ~ V_4 -> V_12 ;
F_4 ( V_2 , V_8 , V_11 ) ;
if ( V_7 )
F_5 ( V_6 , V_4 -> V_13 , V_7 , V_4 -> V_14 ) ;
}
static void F_6 ( struct V_15 * V_15 )
{
struct V_3 * V_4 ;
V_4 = & V_15 -> V_16 ;
if ( V_4 -> V_10 ) {
F_1 ( & V_15 -> V_17 , V_4 ) ;
F_7 ( V_4 -> V_10 ) ;
}
memset ( V_4 , 0 , sizeof( * V_4 ) ) ;
V_4 = & V_15 -> V_18 ;
if ( V_4 -> V_10 ) {
F_1 ( & V_15 -> V_17 , V_4 ) ;
F_7 ( V_4 -> V_10 ) ;
F_8 ( V_4 -> V_19 ) ;
}
memset ( V_4 , 0 , sizeof( * V_4 ) ) ;
}
static void F_9 ( struct V_15 * V_15 , T_2 V_20 )
{
struct V_5 * V_6 = V_15 -> V_17 . V_6 ;
struct V_21 V_22 ;
struct V_3 * V_4 ;
T_1 V_23 = 0 ;
int V_24 ;
V_4 = & V_15 -> V_16 ;
V_4 -> V_10 = F_10 ( V_6 , L_1 ) ;
if ( F_11 ( V_4 -> V_10 ) )
goto V_25;
F_12 ( V_6 -> V_26 , L_2 , & V_23 ) ;
memset ( & V_22 , 0 , sizeof( V_22 ) ) ;
V_22 . V_27 = V_28 ;
V_22 . V_29 = true ;
V_22 . V_30 = V_20 + V_31 ;
V_22 . V_32 = V_33 ;
V_22 . V_34 = V_23 ;
V_24 = F_13 ( V_4 -> V_10 , & V_22 ) ;
if ( V_24 )
goto V_35;
V_4 -> V_14 = V_36 ;
if ( V_15 -> V_37 < V_38 )
V_4 -> V_12 = V_39 ;
else
V_4 -> V_12 = V_40 ;
return;
V_35:
F_7 ( V_4 -> V_10 ) ;
V_25:
memset ( V_4 , 0 , sizeof( * V_4 ) ) ;
}
static void F_14 ( struct V_15 * V_15 , T_2 V_20 )
{
struct V_5 * V_6 = V_15 -> V_17 . V_6 ;
struct V_21 V_22 ;
struct V_3 * V_4 ;
T_1 V_23 = 0 ;
int V_24 ;
V_4 = & V_15 -> V_18 ;
V_4 -> V_10 = F_10 ( V_6 , L_3 ) ;
if ( F_11 ( V_4 -> V_10 ) )
goto V_41;
F_12 ( V_6 -> V_26 , L_4 , & V_23 ) ;
V_4 -> V_19 = F_15 ( V_42 , V_43 ) ;
if ( ! V_4 -> V_19 )
goto V_44;
memset ( & V_22 , 0 , sizeof( V_22 ) ) ;
V_22 . V_27 = V_45 ;
V_22 . V_29 = true ;
V_22 . V_46 = V_20 + V_47 ;
V_22 . V_48 = V_33 ;
V_22 . V_34 = V_23 ;
V_24 = F_13 ( V_4 -> V_10 , & V_22 ) ;
if ( V_24 )
goto V_49;
V_4 -> V_14 = V_50 ;
if ( V_15 -> V_37 < V_38 )
V_4 -> V_12 = V_51 ;
else
V_4 -> V_12 = V_52 ;
return;
V_49:
F_8 ( V_4 -> V_19 ) ;
V_44:
F_7 ( V_4 -> V_10 ) ;
V_41:
memset ( V_4 , 0 , sizeof( * V_4 ) ) ;
}
static inline void F_16 ( struct V_1 * V_2 )
{
while ( ! ( F_3 ( V_2 , V_53 ) & V_54 ) ) {
if ( F_3 ( V_2 , V_55 ) & V_56 )
break;
F_17 ( 1 ) ;
}
F_4 ( V_2 , V_57 , V_58 ) ;
}
static void F_18 ( struct V_1 * V_2 )
{
struct V_15 * V_15 = F_19 ( V_2 ) ;
V_15 -> V_59 &= ~ V_60 ;
F_4 ( V_2 , V_15 -> V_59 , V_61 ) ;
}
static void F_20 ( struct V_1 * V_2 )
{
struct V_15 * V_15 = F_19 ( V_2 ) ;
struct V_3 * V_4 = & V_15 -> V_16 ;
if ( V_4 -> V_9 )
return;
V_15 -> V_59 |= V_60 ;
F_4 ( V_2 , V_15 -> V_59 , V_61 ) ;
}
static void F_21 ( struct V_1 * V_2 , int V_9 )
{
F_16 ( V_2 ) ;
F_4 ( V_2 , V_9 , V_62 ) ;
F_3 ( V_2 , V_62 ) ;
}
static void F_22 ( void * args )
{
struct V_15 * V_15 = args ;
struct V_1 * V_2 = & V_15 -> V_17 ;
struct V_63 * V_64 = & V_2 -> V_65 -> V_64 ;
struct V_3 * V_4 = & V_15 -> V_16 ;
struct V_66 V_65 ;
enum V_67 V_68 ;
unsigned long V_69 ;
unsigned int V_9 ;
T_1 V_8 ;
F_23 ( & V_2 -> V_70 , V_69 ) ;
if ( ! V_4 -> V_9 )
goto V_71;
V_68 = F_24 ( V_4 -> V_10 , V_4 -> V_72 , & V_65 ) ;
F_5 ( V_2 -> V_6 , V_4 -> V_13 , V_4 -> V_9 , V_4 -> V_14 ) ;
V_8 = F_3 ( V_2 , V_11 ) ;
V_8 &= ~ V_4 -> V_12 ;
F_4 ( V_2 , V_8 , V_11 ) ;
if ( V_15 -> V_37 > V_73 ) {
F_4 ( V_2 , V_74 , V_58 ) ;
F_4 ( V_2 , V_75 , V_58 ) ;
}
V_9 = V_4 -> V_9 - V_65 . V_76 ;
V_2 -> V_77 . V_78 += V_9 ;
V_4 -> V_9 = 0 ;
V_64 -> V_79 += V_9 ;
V_64 -> V_79 &= V_80 - 1 ;
V_15 -> V_59 |= V_60 ;
F_4 ( V_2 , V_15 -> V_59 , V_61 ) ;
if ( F_25 ( V_64 ) < V_81 )
F_26 ( V_2 ) ;
F_27 ( V_2 ) ;
V_71:
F_28 ( & V_2 -> V_70 , V_69 ) ;
}
static int F_29 ( struct V_15 * V_15 , unsigned int V_9 )
{
struct V_63 * V_64 = & V_15 -> V_17 . V_65 -> V_64 ;
struct V_1 * V_2 = & V_15 -> V_17 ;
struct V_3 * V_4 = & V_15 -> V_16 ;
void * V_82 ;
int V_24 ;
T_1 V_8 ;
V_82 = & V_64 -> V_83 [ V_64 -> V_79 ] ;
V_4 -> V_13 = F_30 ( V_2 -> V_6 , V_82 , V_9 , V_4 -> V_14 ) ;
V_24 = F_31 ( V_2 -> V_6 , V_4 -> V_13 ) ;
if ( V_24 )
return V_24 ;
V_4 -> V_84 = F_32 ( V_4 -> V_10 , V_4 -> V_13 ,
V_9 , V_28 ,
V_85 |
V_86 ) ;
if ( ! V_4 -> V_84 ) {
V_24 = - V_87 ;
goto V_88;
}
V_4 -> V_84 -> V_89 = F_22 ;
V_4 -> V_84 -> V_90 = V_15 ;
V_4 -> V_72 = F_33 ( V_4 -> V_84 ) ;
V_24 = F_34 ( V_4 -> V_72 ) ;
if ( V_24 )
goto V_88;
V_15 -> V_59 &= ~ V_60 ;
F_4 ( V_2 , V_15 -> V_59 , V_61 ) ;
V_4 -> V_9 = V_9 ;
V_8 = F_3 ( V_2 , V_11 ) ;
V_8 |= V_4 -> V_12 ;
if ( V_15 -> V_37 < V_38 )
F_4 ( V_2 , V_8 , V_11 ) ;
F_21 ( V_2 , V_9 ) ;
if ( V_15 -> V_37 > V_73 )
F_4 ( V_2 , V_8 , V_11 ) ;
F_35 ( V_4 -> V_10 ) ;
return 0 ;
V_88:
F_5 ( V_2 -> V_6 , V_4 -> V_13 , V_9 , V_4 -> V_14 ) ;
return V_24 ;
}
static void F_36 ( void * args )
{
struct V_15 * V_15 = args ;
struct V_1 * V_2 = & V_15 -> V_17 ;
struct V_91 * V_92 = & V_2 -> V_65 -> V_2 ;
struct V_3 * V_4 = & V_15 -> V_18 ;
int V_9 = 0 , V_93 , V_94 ;
unsigned long V_69 ;
T_1 V_8 ;
F_23 ( & V_2 -> V_70 , V_69 ) ;
if ( ! V_4 -> V_9 )
goto V_71;
V_8 = F_3 ( V_2 , V_11 ) ;
V_8 &= ~ V_4 -> V_12 ;
F_4 ( V_2 , V_8 , V_11 ) ;
V_15 -> V_59 |= V_95 | V_96 ;
F_4 ( V_2 , V_15 -> V_59 , V_61 ) ;
if ( F_3 ( V_2 , V_53 ) & V_97 ) {
V_2 -> V_77 . V_98 ++ ;
F_37 ( V_92 , 0 , V_99 ) ;
F_4 ( V_2 , V_100 , V_58 ) ;
}
V_9 = F_3 ( V_2 , V_101 ) ;
V_2 -> V_77 . V_102 += V_9 ;
V_4 -> V_9 = 0 ;
F_5 ( V_2 -> V_6 , V_4 -> V_13 , V_42 , V_4 -> V_14 ) ;
for ( V_93 = 0 ; V_93 < V_9 ; V_93 ++ ) {
char V_103 = V_104 ;
if ( V_15 -> V_105 && V_4 -> V_19 [ V_93 ] == 0 ) {
V_2 -> V_77 . V_106 ++ ;
V_103 = V_107 ;
V_15 -> V_105 = false ;
if ( F_38 ( V_2 ) )
continue;
}
if ( ! ( V_2 -> V_108 & V_109 ) )
V_103 = V_104 ;
F_28 ( & V_2 -> V_70 , V_69 ) ;
V_94 = F_39 ( V_2 , V_4 -> V_19 [ V_93 ] ) ;
F_23 ( & V_2 -> V_70 , V_69 ) ;
if ( ! V_94 )
F_37 ( V_92 , V_4 -> V_19 [ V_93 ] , V_103 ) ;
}
F_40 ( V_15 ) ;
V_71:
F_28 ( & V_2 -> V_70 , V_69 ) ;
if ( V_9 )
F_41 ( V_92 ) ;
}
static void F_40 ( struct V_15 * V_15 )
{
struct V_3 * V_4 = & V_15 -> V_18 ;
struct V_1 * V_17 = & V_15 -> V_17 ;
T_1 V_8 ;
int V_24 ;
if ( ! V_4 -> V_10 )
return;
V_4 -> V_13 = F_30 ( V_17 -> V_6 , V_4 -> V_19 ,
V_42 , V_4 -> V_14 ) ;
V_24 = F_31 ( V_17 -> V_6 , V_4 -> V_13 ) ;
if ( V_24 )
return;
V_4 -> V_84 = F_32 ( V_4 -> V_10 , V_4 -> V_13 ,
V_42 , V_45 ,
V_85 ) ;
if ( ! V_4 -> V_84 )
goto V_88;
V_4 -> V_84 -> V_89 = F_36 ;
V_4 -> V_84 -> V_90 = V_15 ;
V_4 -> V_72 = F_33 ( V_4 -> V_84 ) ;
V_24 = F_34 ( V_4 -> V_72 ) ;
if ( V_24 )
goto V_88;
V_15 -> V_59 &= ~ ( V_95 | V_96 ) ;
if ( V_15 -> V_37 < V_38 )
V_15 -> V_59 |= V_96 ;
F_4 ( V_17 , V_15 -> V_59 , V_61 ) ;
V_4 -> V_9 = V_42 ;
F_35 ( V_4 -> V_10 ) ;
F_4 ( V_17 , V_110 , V_58 ) ;
F_4 ( V_17 , V_111 , V_58 ) ;
V_8 = F_3 ( V_17 , V_11 ) ;
V_8 |= V_4 -> V_12 ;
if ( V_15 -> V_37 < V_38 )
F_4 ( V_17 , V_8 , V_11 ) ;
F_4 ( V_17 , V_42 , V_112 ) ;
if ( V_15 -> V_37 > V_73 )
F_4 ( V_17 , V_8 , V_11 ) ;
return;
V_88:
F_5 ( V_17 -> V_6 , V_4 -> V_13 , V_42 , V_4 -> V_14 ) ;
}
static void F_42 ( struct V_1 * V_2 )
{
struct V_15 * V_15 = F_19 ( V_2 ) ;
struct V_3 * V_4 = & V_15 -> V_18 ;
V_15 -> V_59 &= ~ ( V_95 | V_96 ) ;
F_4 ( V_2 , V_15 -> V_59 , V_61 ) ;
if ( V_4 -> V_10 )
F_1 ( V_2 , V_4 ) ;
}
static void F_43 ( struct V_1 * V_2 )
{
struct V_15 * V_15 = F_19 ( V_2 ) ;
V_15 -> V_59 |= V_113 ;
F_4 ( V_2 , V_15 -> V_59 , V_61 ) ;
}
static void F_44 ( struct V_1 * V_2 , unsigned int V_114 )
{
struct V_91 * V_92 = & V_2 -> V_65 -> V_2 ;
unsigned int V_115 ;
int V_9 = 0 ;
struct V_15 * V_15 = F_19 ( V_2 ) ;
if ( ( F_3 ( V_2 , V_53 ) & V_97 ) ) {
V_2 -> V_77 . V_98 ++ ;
F_37 ( V_92 , 0 , V_99 ) ;
F_4 ( V_2 , V_100 , V_58 ) ;
}
if ( V_114 & V_96 ) {
V_9 = F_3 ( V_2 , V_101 ) -
V_15 -> V_116 ;
V_15 -> V_116 = 0 ;
} else {
V_9 = 4 * ( F_3 ( V_2 , V_117 ) ) ;
V_15 -> V_116 += V_9 ;
}
V_2 -> V_77 . V_102 += V_9 ;
while ( V_9 > 0 ) {
unsigned char V_83 [ 4 ] ;
int V_94 , V_118 , V_93 ;
V_115 = F_3 ( V_2 , V_53 ) ;
if ( ( V_115 & V_119 ) == 0 ) {
V_15 -> V_116 -= V_9 ;
break;
}
F_45 ( V_2 -> V_120 + V_47 , V_83 , 1 ) ;
V_118 = F_46 ( int , V_9 , sizeof( V_83 ) ) ;
for ( V_93 = 0 ; V_93 < V_118 ; V_93 ++ ) {
char V_103 = V_104 ;
if ( V_15 -> V_105 && V_83 [ V_93 ] == 0 ) {
V_2 -> V_77 . V_106 ++ ;
V_103 = V_107 ;
V_15 -> V_105 = false ;
if ( F_38 ( V_2 ) )
continue;
}
if ( ! ( V_2 -> V_108 & V_109 ) )
V_103 = V_104 ;
F_47 ( & V_2 -> V_70 ) ;
V_94 = F_39 ( V_2 , V_83 [ V_93 ] ) ;
F_48 ( & V_2 -> V_70 ) ;
if ( ! V_94 )
F_37 ( V_92 , V_83 [ V_93 ] , V_103 ) ;
}
V_9 -= V_118 ;
}
F_47 ( & V_2 -> V_70 ) ;
F_41 ( V_92 ) ;
F_48 ( & V_2 -> V_70 ) ;
if ( V_114 & ( V_96 ) )
F_4 ( V_2 , V_110 , V_58 ) ;
F_4 ( V_2 , 0xFFFFFF , V_112 ) ;
F_4 ( V_2 , V_111 , V_58 ) ;
F_40 ( V_15 ) ;
}
static void F_49 ( struct V_1 * V_2 )
{
struct V_91 * V_92 = & V_2 -> V_65 -> V_2 ;
unsigned int V_115 ;
if ( ( F_3 ( V_2 , V_53 ) & V_97 ) ) {
V_2 -> V_77 . V_98 ++ ;
F_37 ( V_92 , 0 , V_99 ) ;
F_4 ( V_2 , V_100 , V_58 ) ;
}
while ( ( V_115 = F_3 ( V_2 , V_53 ) ) & V_119 ) {
unsigned int V_121 ;
char V_103 = V_104 ;
int V_94 ;
V_121 = F_3 ( V_2 , V_122 ) ;
if ( V_115 & V_109 ) {
V_2 -> V_77 . V_106 ++ ;
if ( F_38 ( V_2 ) )
continue;
} else if ( V_115 & V_123 ) {
V_2 -> V_77 . V_124 ++ ;
} else {
V_2 -> V_77 . V_102 ++ ;
}
V_115 &= V_2 -> V_108 ;
if ( V_115 & V_109 )
V_103 = V_107 ;
else if ( V_115 & V_123 )
V_103 = V_125 ;
F_47 ( & V_2 -> V_70 ) ;
V_94 = F_39 ( V_2 , V_121 ) ;
F_48 ( & V_2 -> V_70 ) ;
if ( ! V_94 )
F_37 ( V_92 , V_121 , V_103 ) ;
}
F_47 ( & V_2 -> V_70 ) ;
F_41 ( V_92 ) ;
F_48 ( & V_2 -> V_70 ) ;
}
static void F_50 ( struct V_1 * V_2 , unsigned int V_126 )
{
struct V_63 * V_64 = & V_2 -> V_65 -> V_64 ;
struct V_15 * V_15 = F_19 ( V_2 ) ;
unsigned int V_127 ;
unsigned int V_128 = 0 ;
void T_3 * V_129 ;
if ( V_15 -> V_37 )
V_129 = V_2 -> V_120 + V_31 ;
else
V_129 = V_2 -> V_120 + V_130 ;
if ( V_126 && V_15 -> V_37 )
F_21 ( V_2 , V_126 ) ;
while ( V_128 < V_126 ) {
int V_93 ;
char V_83 [ 4 ] = { 0 } ;
if ( ! ( F_3 ( V_2 , V_53 ) & V_131 ) )
break;
if ( V_15 -> V_37 )
V_127 = F_51 ( V_126 - V_128 ,
( unsigned int ) sizeof( V_83 ) ) ;
else
V_127 = 1 ;
for ( V_93 = 0 ; V_93 < V_127 ; V_93 ++ ) {
V_83 [ V_93 ] = V_64 -> V_83 [ V_64 -> V_79 + V_93 ] ;
V_2 -> V_77 . V_78 ++ ;
}
F_52 ( V_129 , V_83 , 1 ) ;
V_64 -> V_79 = ( V_64 -> V_79 + V_127 ) & ( V_80 - 1 ) ;
V_128 += V_127 ;
}
if ( F_53 ( V_64 ) )
F_18 ( V_2 ) ;
if ( F_25 ( V_64 ) < V_81 )
F_26 ( V_2 ) ;
}
static void F_27 ( struct V_1 * V_2 )
{
struct V_15 * V_15 = F_19 ( V_2 ) ;
struct V_63 * V_64 = & V_15 -> V_17 . V_65 -> V_64 ;
struct V_3 * V_4 = & V_15 -> V_16 ;
unsigned int V_132 , V_133 , V_134 ;
void T_3 * V_129 ;
int V_49 = 0 ;
if ( V_2 -> V_135 ) {
if ( V_15 -> V_37 )
V_129 = V_2 -> V_120 + V_31 ;
else
V_129 = V_2 -> V_120 + V_130 ;
if ( V_15 -> V_37 )
F_21 ( V_2 , 1 ) ;
F_54 ( V_129 , & V_2 -> V_135 , 1 ) ;
V_2 -> V_77 . V_78 ++ ;
V_2 -> V_135 = 0 ;
return;
}
if ( F_53 ( V_64 ) || F_55 ( V_2 ) ) {
F_18 ( V_2 ) ;
return;
}
V_132 = F_56 ( V_64 -> V_136 , V_64 -> V_79 , V_80 ) ;
V_133 = F_57 ( V_64 -> V_136 , V_64 -> V_79 , V_80 ) ;
V_134 = 1 ;
if ( V_15 -> V_37 > V_73 ) {
V_133 = F_58 ( V_133 ) ;
V_134 = V_33 ;
} else {
if ( V_133 > V_137 )
V_133 = V_137 ;
}
if ( V_132 > V_2 -> V_138 )
V_132 = V_2 -> V_138 ;
if ( ! V_4 -> V_10 || V_133 < V_134 )
F_50 ( V_2 , V_132 ) ;
else
V_49 = F_29 ( V_15 , V_133 ) ;
if ( V_49 )
F_50 ( V_2 , V_132 ) ;
}
static void F_59 ( struct V_1 * V_2 )
{
F_4 ( V_2 , V_139 , V_58 ) ;
V_2 -> V_77 . V_140 ++ ;
F_60 ( & V_2 -> V_65 -> V_2 . V_141 ) ;
}
static T_4 F_61 ( int V_142 , void * V_143 )
{
struct V_1 * V_2 = V_143 ;
struct V_15 * V_15 = F_19 ( V_2 ) ;
struct V_3 * V_4 = & V_15 -> V_18 ;
unsigned long V_69 ;
unsigned int V_114 ;
T_1 V_8 ;
F_23 ( & V_2 -> V_70 , V_69 ) ;
V_114 = F_3 ( V_2 , V_144 ) ;
F_4 ( V_2 , 0 , V_61 ) ;
if ( V_114 & V_145 ) {
V_15 -> V_105 = true ;
F_4 ( V_2 , V_146 , V_58 ) ;
}
if ( V_114 & ( V_95 | V_96 ) ) {
if ( V_4 -> V_9 ) {
V_8 = V_147 ;
F_4 ( V_2 , V_8 , V_58 ) ;
V_8 = V_110 ;
F_4 ( V_2 , V_8 , V_58 ) ;
F_2 ( V_4 -> V_10 ) ;
} else if ( V_15 -> V_37 ) {
F_44 ( V_2 , V_114 ) ;
} else {
F_49 ( V_2 ) ;
}
}
if ( V_114 & V_60 )
F_27 ( V_2 ) ;
if ( V_114 & V_113 )
F_59 ( V_2 ) ;
F_4 ( V_2 , V_15 -> V_59 , V_61 ) ;
F_28 ( & V_2 -> V_70 , V_69 ) ;
return V_148 ;
}
static unsigned int F_62 ( struct V_1 * V_2 )
{
return ( F_3 ( V_2 , V_53 ) & V_54 ) ? V_149 : 0 ;
}
static unsigned int F_63 ( struct V_1 * V_2 )
{
return V_150 | V_151 | V_152 | V_153 ;
}
static void F_64 ( struct V_1 * V_2 )
{
struct V_15 * V_15 = F_19 ( V_2 ) ;
F_4 ( V_2 , V_154 , V_58 ) ;
F_4 ( V_2 , V_74 , V_58 ) ;
F_4 ( V_2 , V_100 , V_58 ) ;
F_4 ( V_2 , V_155 , V_58 ) ;
F_4 ( V_2 , V_139 , V_58 ) ;
F_4 ( V_2 , V_156 , V_58 ) ;
if ( V_15 -> V_37 )
F_4 ( V_2 , 0 , V_11 ) ;
}
static void F_65 ( struct V_1 * V_2 , unsigned int V_157 )
{
unsigned int V_158 ;
V_158 = F_3 ( V_2 , V_159 ) ;
if ( ! ( V_157 & V_153 ) ) {
V_158 &= ~ V_160 ;
F_4 ( V_2 , V_158 , V_159 ) ;
F_4 ( V_2 , V_161 , V_58 ) ;
} else {
V_158 |= V_160 ;
F_4 ( V_2 , V_158 , V_159 ) ;
}
}
static void F_66 ( struct V_1 * V_2 , int V_162 )
{
if ( V_162 )
F_4 ( V_2 , V_163 , V_58 ) ;
else
F_4 ( V_2 , V_164 , V_58 ) ;
}
static const struct V_165 *
F_67 ( struct V_1 * V_2 , unsigned int V_166 ,
unsigned long * V_167 )
{
struct V_15 * V_15 = F_19 ( V_2 ) ;
unsigned int V_168 , V_169 ;
unsigned long V_170 , V_171 , V_172 = 0 , V_173 , V_174 = V_175 ;
const struct V_165 * V_176 , * V_177 , * V_178 ;
static const struct V_165 V_179 [] = {
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
V_178 = V_179 ;
V_170 = F_68 ( V_15 -> V_180 , 16 * V_166 ) ;
V_168 = F_69 ( V_170 , 16 * V_166 ) ;
V_177 = V_179 + F_70 ( V_179 ) ;
V_176 = V_179 ;
while ( V_176 < V_177 ) {
if ( V_176 -> V_168 <= V_168 ) {
V_169 = V_170 / V_176 -> V_168 / 16 ;
V_173 = abs ( V_169 - V_166 ) ;
if ( V_173 < V_174 ) {
V_174 = V_173 ;
V_178 = V_176 ;
V_172 = V_170 ;
}
if ( V_169 == V_166 )
break;
} else if ( V_176 -> V_168 > V_168 ) {
V_171 = V_170 ;
V_170 = F_68 ( V_15 -> V_180 , V_171 + 1 ) ;
if ( V_170 == V_171 )
break;
V_176 = V_179 ;
V_168 = F_69 ( V_170 , 16 * V_166 ) ;
continue;
}
V_176 ++ ;
}
* V_167 = V_172 ;
return V_178 ;
}
static int F_71 ( struct V_1 * V_2 , unsigned int V_166 ,
unsigned long * V_181 )
{
unsigned int V_182 , V_183 , V_184 ;
struct V_15 * V_15 = F_19 ( V_2 ) ;
const struct V_165 * V_176 ;
unsigned long V_69 , V_167 ;
V_69 = * V_181 ;
F_28 ( & V_2 -> V_70 , V_69 ) ;
V_176 = F_67 ( V_2 , V_166 , & V_167 ) ;
F_72 ( V_15 -> V_180 , V_167 ) ;
V_166 = V_167 / 16 / V_176 -> V_168 ;
F_23 ( & V_2 -> V_70 , V_69 ) ;
* V_181 = V_69 ;
V_2 -> V_185 = V_167 ;
F_4 ( V_2 , V_176 -> V_186 , V_187 ) ;
V_182 = V_176 -> V_182 ;
V_183 = V_188 & V_182 ;
if ( V_15 -> V_37 ) {
V_184 = V_189 ;
} else {
V_183 |= V_190 ;
V_184 = V_191 ;
}
V_183 |= V_184 & ( V_182 << 2 ) ;
F_4 ( V_2 , V_183 , V_192 ) ;
V_183 = ( V_2 -> V_138 * 3 ) / 4 ;
F_4 ( V_2 , V_183 , V_117 ) ;
F_4 ( V_2 , 10 , V_193 ) ;
F_4 ( V_2 , V_194 , V_58 ) ;
F_64 ( V_2 ) ;
F_4 ( V_2 , V_75 | V_195 , V_58 ) ;
V_15 -> V_59 = V_95 | V_96 |
V_196 | V_145 ;
F_4 ( V_2 , V_15 -> V_59 , V_61 ) ;
if ( V_15 -> V_37 ) {
F_4 ( V_2 , V_110 , V_58 ) ;
F_4 ( V_2 , 0xFFFFFF , V_112 ) ;
F_4 ( V_2 , V_111 , V_58 ) ;
}
return V_166 ;
}
static void F_73 ( struct V_1 * V_2 )
{
struct V_15 * V_15 = F_19 ( V_2 ) ;
F_74 ( V_15 -> V_180 ) ;
F_74 ( V_15 -> V_197 ) ;
F_75 ( V_2 ) ;
}
static int F_76 ( struct V_1 * V_2 )
{
struct V_15 * V_15 = F_19 ( V_2 ) ;
unsigned int V_198 , V_199 , V_184 ;
int V_24 ;
snprintf ( V_15 -> V_200 , sizeof( V_15 -> V_200 ) ,
L_5 , V_2 -> line ) ;
V_24 = F_77 ( V_2 -> V_142 , F_61 , V_201 ,
V_15 -> V_200 , V_2 ) ;
if ( F_78 ( V_24 ) )
return V_24 ;
F_73 ( V_2 ) ;
if ( F_79 ( V_2 -> V_138 > 12 ) )
V_199 = V_2 -> V_138 - 12 ;
else
V_199 = V_2 -> V_138 ;
V_198 = F_3 ( V_2 , V_159 ) ;
if ( V_15 -> V_37 )
V_184 = V_202 ;
else
V_184 = V_203 ;
V_198 &= ~ V_184 ;
V_198 &= ~ V_204 ;
V_198 |= V_184 & ( V_199 << 2 ) ;
V_198 |= V_204 & V_199 ;
F_4 ( V_2 , V_198 , V_159 ) ;
if ( V_15 -> V_37 ) {
F_9 ( V_15 , V_15 -> V_17 . V_205 ) ;
F_14 ( V_15 , V_15 -> V_17 . V_205 ) ;
}
return 0 ;
}
static void F_80 ( struct V_1 * V_2 )
{
struct V_15 * V_15 = F_19 ( V_2 ) ;
V_15 -> V_59 = 0 ;
F_4 ( V_2 , 0 , V_61 ) ;
if ( V_15 -> V_37 )
F_6 ( V_15 ) ;
F_81 ( V_15 -> V_180 ) ;
F_82 ( V_2 -> V_142 , V_2 ) ;
}
static void F_83 ( struct V_1 * V_2 , struct V_206 * V_207 ,
struct V_206 * V_171 )
{
struct V_15 * V_15 = F_19 ( V_2 ) ;
struct V_3 * V_4 = & V_15 -> V_18 ;
unsigned long V_69 ;
unsigned int V_166 , V_158 ;
F_23 ( & V_2 -> V_70 , V_69 ) ;
if ( V_4 -> V_10 )
F_1 ( V_2 , V_4 ) ;
V_166 = F_84 ( V_2 , V_207 , V_171 , 300 , 4000000 ) ;
V_166 = F_71 ( V_2 , V_166 , & V_69 ) ;
if ( F_85 ( V_207 ) )
F_86 ( V_207 , V_166 , V_166 ) ;
V_158 = F_3 ( V_2 , V_208 ) ;
V_158 &= ~ V_209 ;
if ( V_207 -> V_210 & V_211 ) {
if ( V_207 -> V_210 & V_212 )
V_158 |= V_213 ;
else if ( V_207 -> V_210 & V_214 )
V_158 |= V_215 ;
else
V_158 |= V_216 ;
}
V_158 &= ~ V_217 ;
switch ( V_207 -> V_210 & V_218 ) {
case V_219 :
V_158 |= V_220 ;
break;
case V_221 :
V_158 |= V_222 ;
break;
case V_223 :
V_158 |= V_224 ;
break;
case V_225 :
default:
V_158 |= V_226 ;
break;
}
V_158 &= ~ ( V_227 | V_228 ) ;
if ( V_207 -> V_210 & V_229 )
V_158 |= V_228 ;
else
V_158 |= V_227 ;
F_4 ( V_2 , V_158 , V_208 ) ;
V_158 = F_3 ( V_2 , V_159 ) ;
V_158 &= ~ ( V_230 | V_160 ) ;
if ( V_207 -> V_210 & V_231 ) {
V_158 |= V_230 ;
V_158 |= V_160 ;
}
F_4 ( V_2 , V_158 , V_159 ) ;
V_2 -> V_108 = 0 ;
if ( V_207 -> V_232 & V_233 )
V_2 -> V_108 |= V_123 ;
if ( V_207 -> V_232 & ( V_234 | V_235 | V_236 ) )
V_2 -> V_108 |= V_109 ;
F_87 ( V_2 , V_207 -> V_210 , V_166 ) ;
F_40 ( V_15 ) ;
F_28 ( & V_2 -> V_70 , V_69 ) ;
}
static const char * F_88 ( struct V_1 * V_2 )
{
return L_6 ;
}
static void F_89 ( struct V_1 * V_2 )
{
struct V_237 * V_238 = F_90 ( V_2 -> V_6 ) ;
struct V_239 * V_240 ;
T_2 V_241 ;
V_240 = F_91 ( V_238 , V_242 , 0 ) ;
if ( F_78 ( ! V_240 ) )
return;
V_241 = F_92 ( V_240 ) ;
F_93 ( V_2 -> V_205 , V_241 ) ;
F_94 ( V_2 -> V_120 ) ;
V_2 -> V_120 = NULL ;
}
static int F_95 ( struct V_1 * V_2 )
{
struct V_237 * V_238 = F_90 ( V_2 -> V_6 ) ;
struct V_239 * V_240 ;
T_2 V_241 ;
int V_24 ;
V_240 = F_91 ( V_238 , V_242 , 0 ) ;
if ( F_78 ( ! V_240 ) )
return - V_243 ;
V_241 = F_92 ( V_240 ) ;
if ( ! F_96 ( V_2 -> V_205 , V_241 , L_7 ) )
return - V_244 ;
V_2 -> V_120 = F_97 ( V_2 -> V_205 , V_241 ) ;
if ( ! V_2 -> V_120 ) {
V_24 = - V_244 ;
goto V_245;
}
return 0 ;
V_245:
F_93 ( V_2 -> V_205 , V_241 ) ;
return V_24 ;
}
static void F_98 ( struct V_1 * V_2 , int V_69 )
{
int V_24 ;
if ( V_69 & V_246 ) {
V_2 -> type = V_247 ;
V_24 = F_95 ( V_2 ) ;
if ( V_24 )
return;
}
}
static int F_99 ( struct V_1 * V_2 , struct V_248 * V_249 )
{
if ( F_78 ( V_249 -> type != V_250 && V_249 -> type != V_247 ) )
return - V_251 ;
if ( F_78 ( V_2 -> V_142 != V_249 -> V_142 ) )
return - V_251 ;
return 0 ;
}
static void F_100 ( struct V_1 * V_2 , unsigned int V_65 ,
unsigned int V_252 )
{
struct V_15 * V_15 = F_19 ( V_2 ) ;
switch ( V_65 ) {
case 0 :
F_74 ( V_15 -> V_180 ) ;
F_74 ( V_15 -> V_197 ) ;
break;
case 3 :
F_81 ( V_15 -> V_180 ) ;
F_81 ( V_15 -> V_197 ) ;
break;
default:
F_101 ( L_8 , V_65 ) ;
}
}
static int F_102 ( struct V_1 * V_2 )
{
struct V_15 * V_15 = F_19 ( V_2 ) ;
unsigned int V_253 = V_15 -> V_37 ? V_47 : V_122 ;
if ( ! ( F_3 ( V_2 , V_53 ) & V_119 ) )
return V_254 ;
return F_3 ( V_2 , V_253 ) & 0xff ;
}
static int F_103 ( struct V_1 * V_2 )
{
int V_121 ;
static T_1 V_255 ;
static int V_9 ;
unsigned char * V_256 = ( unsigned char * ) & V_255 ;
if ( V_9 ) {
V_121 = V_256 [ sizeof( V_255 ) - V_9 ] ;
V_9 -- ;
} else if ( ! ( F_3 ( V_2 , V_53 ) & V_119 ) ) {
V_9 = F_3 ( V_2 , V_257 ) ;
V_9 = ( V_9 >> V_258 ) & V_259 ;
if ( V_9 ) {
F_4 ( V_2 , V_260 , V_58 ) ;
V_255 = F_3 ( V_2 , V_47 ) ;
V_121 = V_256 [ 0 ] ;
V_9 -- ;
F_4 ( V_2 , V_110 , V_58 ) ;
F_4 ( V_2 , 0xFFFFFF , V_112 ) ;
F_4 ( V_2 , V_111 ,
V_58 ) ;
} else {
V_121 = V_254 ;
}
} else {
V_255 = F_3 ( V_2 , V_47 ) ;
V_121 = V_256 [ 0 ] ;
V_9 = sizeof( V_255 ) - 1 ;
}
return V_121 ;
}
static int F_104 ( struct V_1 * V_2 )
{
T_1 V_59 ;
int V_121 ;
struct V_15 * V_15 = F_19 ( V_2 ) ;
V_59 = F_3 ( V_2 , V_61 ) ;
F_4 ( V_2 , 0 , V_61 ) ;
if ( V_15 -> V_37 )
V_121 = F_103 ( V_2 ) ;
else
V_121 = F_102 ( V_2 ) ;
F_4 ( V_2 , V_59 , V_61 ) ;
return V_121 ;
}
static void F_105 ( struct V_1 * V_2 , unsigned char V_121 )
{
T_1 V_59 ;
struct V_15 * V_15 = F_19 ( V_2 ) ;
V_59 = F_3 ( V_2 , V_61 ) ;
F_4 ( V_2 , 0 , V_61 ) ;
if ( V_15 -> V_37 )
F_21 ( V_2 , 1 ) ;
while ( ! ( F_3 ( V_2 , V_53 ) & V_131 ) )
F_106 () ;
F_4 ( V_2 , V_121 , V_15 -> V_37 ? V_31 : V_130 ) ;
while ( ! ( F_3 ( V_2 , V_53 ) & V_131 ) )
F_106 () ;
F_4 ( V_2 , V_59 , V_61 ) ;
}
static inline struct V_1 * F_107 ( unsigned int line )
{
return & V_261 [ line ] . V_17 ;
}
static void F_108 ( struct V_1 * V_2 , const char * V_262 ,
unsigned int V_9 , bool V_37 )
{
int V_93 ;
int V_263 = 0 ;
bool V_264 = false ;
void T_3 * V_129 ;
if ( V_37 )
V_129 = V_2 -> V_120 + V_31 ;
else
V_129 = V_2 -> V_120 + V_130 ;
for ( V_93 = 0 ; V_93 < V_9 ; V_93 ++ )
if ( V_262 [ V_93 ] == '\n' )
V_263 ++ ;
V_9 += V_263 ;
F_48 ( & V_2 -> V_70 ) ;
if ( V_37 )
F_21 ( V_2 , V_9 ) ;
V_93 = 0 ;
while ( V_93 < V_9 ) {
int V_265 ;
unsigned int V_127 ;
char V_83 [ 4 ] = { 0 } ;
if ( V_37 )
V_127 = F_51 ( V_9 - V_93 , ( unsigned int ) sizeof( V_83 ) ) ;
else
V_127 = 1 ;
for ( V_265 = 0 ; V_265 < V_127 ; V_265 ++ ) {
char V_121 = * V_262 ;
if ( V_121 == '\n' && ! V_264 ) {
V_83 [ V_265 ] = '\r' ;
V_265 ++ ;
V_264 = true ;
}
if ( V_265 < V_127 ) {
V_83 [ V_265 ] = V_121 ;
V_262 ++ ;
V_264 = false ;
}
}
while ( ! ( F_3 ( V_2 , V_53 ) & V_131 ) )
F_106 () ;
F_52 ( V_129 , V_83 , 1 ) ;
V_93 += V_127 ;
}
F_47 ( & V_2 -> V_70 ) ;
}
static void F_109 ( struct V_266 * V_267 , const char * V_262 ,
unsigned int V_9 )
{
struct V_1 * V_2 ;
struct V_15 * V_15 ;
F_110 ( V_267 -> V_268 < 0 || V_267 -> V_268 >= V_269 ) ;
V_2 = F_107 ( V_267 -> V_268 ) ;
V_15 = F_19 ( V_2 ) ;
F_108 ( V_2 , V_262 , V_9 , V_15 -> V_37 ) ;
}
static int T_5 F_111 ( struct V_266 * V_267 , char * V_270 )
{
struct V_1 * V_2 ;
int V_166 = 115200 ;
int V_271 = 8 ;
int V_272 = 'n' ;
int V_273 = 'n' ;
if ( F_78 ( V_267 -> V_268 >= V_269 || V_267 -> V_268 < 0 ) )
return - V_243 ;
V_2 = F_107 ( V_267 -> V_268 ) ;
if ( F_78 ( ! V_2 -> V_120 ) )
return - V_243 ;
F_73 ( V_2 ) ;
if ( V_270 )
F_112 ( V_270 , & V_166 , & V_272 , & V_271 , & V_273 ) ;
F_113 ( L_9 , V_2 -> line ) ;
return F_114 ( V_2 , V_267 , V_166 , V_272 , V_271 , V_273 ) ;
}
static void
F_115 ( struct V_266 * V_274 , const char * V_262 , unsigned V_275 )
{
struct V_276 * V_6 = V_274 -> V_198 ;
F_108 ( & V_6 -> V_2 , V_262 , V_275 , false ) ;
}
static int T_5
F_116 ( struct V_276 * V_5 , const char * V_277 )
{
if ( ! V_5 -> V_2 . V_120 )
return - V_278 ;
V_5 -> V_274 -> V_279 = F_115 ;
return 0 ;
}
static void
F_117 ( struct V_266 * V_274 , const char * V_262 , unsigned V_275 )
{
struct V_276 * V_6 = V_274 -> V_198 ;
F_108 ( & V_6 -> V_2 , V_262 , V_275 , true ) ;
}
static int T_5
F_118 ( struct V_276 * V_5 ,
const char * V_277 )
{
if ( ! V_5 -> V_2 . V_120 )
return - V_278 ;
V_5 -> V_274 -> V_279 = F_117 ;
return 0 ;
}
static int F_119 ( struct V_237 * V_238 )
{
struct V_15 * V_15 ;
struct V_239 * V_239 ;
struct V_1 * V_2 ;
const struct V_280 * V_281 ;
int V_142 , line ;
if ( V_238 -> V_6 . V_26 )
line = F_120 ( V_238 -> V_6 . V_26 , L_10 ) ;
else
line = V_238 -> V_281 ;
if ( line < 0 )
line = F_121 ( & V_282 ) - 1 ;
if ( F_78 ( line < 0 || line >= V_269 ) )
return - V_243 ;
F_122 ( & V_238 -> V_6 , L_11 , line ) ;
V_2 = F_107 ( line ) ;
V_2 -> V_6 = & V_238 -> V_6 ;
V_15 = F_19 ( V_2 ) ;
V_281 = F_123 ( V_283 , & V_238 -> V_6 ) ;
if ( V_281 )
V_15 -> V_37 = ( unsigned long ) V_281 -> V_198 ;
else
V_15 -> V_37 = 0 ;
V_15 -> V_180 = F_124 ( & V_238 -> V_6 , L_12 ) ;
if ( F_11 ( V_15 -> V_180 ) )
return F_125 ( V_15 -> V_180 ) ;
if ( V_15 -> V_37 ) {
V_15 -> V_197 = F_124 ( & V_238 -> V_6 , L_13 ) ;
if ( F_11 ( V_15 -> V_197 ) )
return F_125 ( V_15 -> V_197 ) ;
}
V_2 -> V_185 = F_126 ( V_15 -> V_180 ) ;
F_122 ( & V_238 -> V_6 , L_14 , V_2 -> V_185 ) ;
V_239 = F_91 ( V_238 , V_242 , 0 ) ;
if ( F_78 ( ! V_239 ) )
return - V_243 ;
V_2 -> V_205 = V_239 -> V_284 ;
V_142 = F_127 ( V_238 , 0 ) ;
if ( F_78 ( V_142 < 0 ) )
return - V_243 ;
V_2 -> V_142 = V_142 ;
F_128 ( V_238 , V_2 ) ;
return F_129 ( & V_285 , V_2 ) ;
}
static int F_130 ( struct V_237 * V_238 )
{
struct V_1 * V_2 = F_131 ( V_238 ) ;
F_132 ( & V_285 , V_2 ) ;
return 0 ;
}
static int T_5 F_133 ( void )
{
int V_24 ;
V_24 = F_134 ( & V_285 ) ;
if ( F_78 ( V_24 ) )
return V_24 ;
V_24 = F_135 ( & V_286 ) ;
if ( F_78 ( V_24 ) )
F_136 ( & V_285 ) ;
F_113 ( L_15 ) ;
return V_24 ;
}
static void T_6 F_137 ( void )
{
F_138 ( & V_286 ) ;
F_136 ( & V_285 ) ;
}
