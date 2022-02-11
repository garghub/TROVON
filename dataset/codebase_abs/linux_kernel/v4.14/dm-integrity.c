static unsigned char F_1 ( unsigned char V_1 )
{
return ( V_1 + V_2 - 1 ) % V_2 ;
}
static unsigned char F_2 ( unsigned char V_1 )
{
return ( V_1 + 1 ) % V_2 ;
}
static void F_3 ( T_1 * V_3 , T_2 V_4 , const char * V_5 , ... )
{
T_3 args ;
va_start ( args , V_5 ) ;
F_4 ( V_5 , args ) ;
va_end ( args ) ;
if ( V_4 )
F_5 ( L_1 ) ;
while ( V_4 ) {
F_5 ( L_2 , * V_3 ) ;
V_3 ++ ;
V_4 -- ;
}
F_5 ( L_3 ) ;
}
static void F_6 ( struct V_6 * V_7 , const char * V_5 , int V_8 )
{
if ( V_8 == - V_9 )
F_7 ( & V_7 -> V_10 ) ;
if ( ! F_8 ( & V_7 -> V_11 , 0 , V_8 ) )
F_9 ( L_4 , V_5 , V_8 ) ;
}
static int F_10 ( struct V_6 * V_7 )
{
return F_11 ( V_7 -> V_11 ) ;
}
static T_4 F_12 ( struct V_6 * V_7 , unsigned V_12 ,
unsigned V_13 , unsigned char V_1 )
{
return V_7 -> V_14 [ V_1 ] ^ F_13 ( ( ( V_15 ) V_12 << 32 ) ^ V_13 ) ;
}
static void F_14 ( struct V_6 * V_7 , T_5 V_16 ,
T_5 * V_17 , T_5 * V_18 )
{
T_1 V_19 = V_7 -> V_20 -> V_19 ;
* V_17 = V_16 >> V_19 ;
* V_18 = ( unsigned ) V_16 & ( ( 1U << V_19 ) - 1 ) ;
}
static V_15 F_15 ( struct V_6 * V_7 , T_5 V_17 ,
T_5 V_18 , unsigned * V_21 )
{
V_15 V_22 ;
unsigned V_23 ;
V_22 = V_17 << V_7 -> V_20 -> V_19 ;
if ( F_16 ( V_7 -> V_24 >= 0 ) )
V_22 += V_17 << V_7 -> V_24 ;
else
V_22 += V_17 * V_7 -> V_25 ;
V_22 >>= V_7 -> V_26 ;
F_17 ( V_7 , V_18 ) ;
if ( F_16 ( V_7 -> V_27 >= 0 ) ) {
V_22 += V_18 >> ( V_28 + V_7 -> V_26 - V_7 -> V_27 ) ;
V_23 = ( V_18 << V_7 -> V_27 ) & ( ( 1U << V_28 << V_7 -> V_26 ) - 1 ) ;
} else {
V_22 += ( V_15 ) V_18 * V_7 -> V_29 >> ( V_28 + V_7 -> V_26 ) ;
V_23 = ( V_18 * V_7 -> V_29 ) & ( ( 1U << V_28 << V_7 -> V_26 ) - 1 ) ;
}
* V_21 = V_23 ;
return V_22 ;
}
static T_5 F_18 ( struct V_6 * V_7 , T_5 V_17 , T_5 V_18 )
{
T_5 V_30 ;
V_30 = V_17 << V_7 -> V_20 -> V_19 ;
if ( F_16 ( V_7 -> V_24 >= 0 ) )
V_30 += ( V_17 + 1 ) << V_7 -> V_24 ;
else
V_30 += ( V_17 + 1 ) * V_7 -> V_25 ;
V_30 += ( T_5 ) V_7 -> V_31 + V_18 ;
return V_30 ;
}
static void F_19 ( struct V_6 * V_7 , unsigned * V_32 )
{
if ( F_20 ( * V_32 >= V_7 -> V_33 ) )
* V_32 -= V_7 -> V_33 ;
}
static int F_21 ( struct V_6 * V_7 , int V_34 , int V_35 )
{
struct V_36 V_37 ;
struct V_38 V_39 ;
V_37 . V_40 = V_34 ;
V_37 . V_41 = V_35 ;
V_37 . V_42 . type = V_43 ;
V_37 . V_42 . V_44 . V_45 = V_7 -> V_20 ;
V_37 . V_46 . V_47 = NULL ;
V_37 . V_48 = V_7 -> V_49 ;
V_39 . V_50 = V_7 -> V_51 -> V_50 ;
V_39 . V_52 = V_7 -> V_53 ;
V_39 . V_54 = V_55 ;
return F_22 ( & V_37 , 1 , & V_39 , NULL ) ;
}
static void F_23 ( struct V_6 * V_7 , unsigned V_56 , unsigned V_18 ,
bool V_57 , const char * V_58 )
{
#if F_24 ( V_59 ) || F_24 ( V_60 )
unsigned V_61 = V_57 ? V_7 -> V_62 : V_7 -> V_63 ;
if ( F_20 ( V_56 >= V_7 -> V_33 ) ||
F_20 ( V_18 >= V_61 ) ) {
F_25 ( V_64 L_5 ,
V_58 , V_56 , V_18 , V_7 -> V_33 , V_61 ) ;
F_26 () ;
}
#endif
}
static void F_27 ( struct V_6 * V_7 , unsigned V_56 , unsigned V_18 ,
unsigned * V_65 , unsigned * V_66 )
{
unsigned V_52 ;
F_23 ( V_7 , V_56 , V_18 , false , L_6 ) ;
V_52 = V_56 * V_7 -> V_63 + V_18 ;
* V_65 = V_52 >> ( V_67 - V_28 ) ;
* V_66 = ( V_52 << V_28 ) & ( V_68 - 1 ) ;
}
static struct V_69 * F_28 ( struct V_6 * V_7 , struct V_70 * V_71 ,
unsigned V_56 , unsigned V_18 , unsigned * V_72 )
{
unsigned V_65 , V_66 ;
char * V_73 ;
F_27 ( V_7 , V_56 , V_18 , & V_65 , & V_66 ) ;
if ( V_72 )
* V_72 = ( V_68 - V_66 ) >> V_28 ;
V_73 = F_29 ( V_71 [ V_65 ] . V_74 ) ;
return (struct V_69 * ) ( V_73 + V_66 ) ;
}
static struct V_69 * F_30 ( struct V_6 * V_7 , unsigned V_56 , unsigned V_18 )
{
return F_28 ( V_7 , V_7 -> V_75 , V_56 , V_18 , NULL ) ;
}
static struct V_76 * F_31 ( struct V_6 * V_7 , unsigned V_56 , unsigned V_77 )
{
unsigned V_78 , V_18 ;
struct V_69 * V_79 ;
F_23 ( V_7 , V_56 , V_77 , true , L_7 ) ;
V_78 = V_77 % V_80 ;
V_18 = V_77 / V_80 ;
V_79 = F_30 ( V_7 , V_56 , V_78 ) ;
return (struct V_76 * ) ( ( char * ) V_79 + V_18 * V_7 -> V_81 ) ;
}
static struct V_69 * F_32 ( struct V_6 * V_7 , unsigned V_56 , unsigned V_77 )
{
V_77 <<= V_7 -> V_20 -> V_82 ;
V_77 += V_80 ;
F_23 ( V_7 , V_56 , V_77 , false , L_8 ) ;
return F_30 ( V_7 , V_56 , V_77 ) ;
}
static void F_33 ( struct V_6 * V_7 , unsigned V_56 , T_1 V_30 [ V_83 ] )
{
F_34 ( V_84 , V_7 -> V_85 ) ;
int V_86 ;
unsigned V_13 , V_87 ;
V_84 -> V_88 = V_7 -> V_85 ;
V_84 -> V_89 = V_90 ;
V_86 = F_35 ( V_84 ) ;
if ( F_20 ( V_86 ) ) {
F_6 ( V_7 , L_9 , V_86 ) ;
goto V_8;
}
for ( V_13 = 0 ; V_13 < V_7 -> V_62 ; V_13 ++ ) {
struct V_76 * V_91 = F_31 ( V_7 , V_56 , V_13 ) ;
V_86 = F_36 ( V_84 , ( T_1 * ) & V_91 -> V_92 . V_52 , sizeof V_91 -> V_92 . V_52 ) ;
if ( F_20 ( V_86 ) ) {
F_6 ( V_7 , L_10 , V_86 ) ;
goto V_8;
}
}
V_87 = F_37 ( V_7 -> V_85 ) ;
if ( F_16 ( V_87 <= V_83 ) ) {
V_86 = F_38 ( V_84 , V_30 ) ;
if ( F_20 ( V_86 ) ) {
F_6 ( V_7 , L_11 , V_86 ) ;
goto V_8;
}
memset ( V_30 + V_87 , 0 , V_83 - V_87 ) ;
} else {
T_1 V_93 [ V_87 ] ;
V_86 = F_38 ( V_84 , V_93 ) ;
if ( F_20 ( V_86 ) ) {
F_6 ( V_7 , L_11 , V_86 ) ;
goto V_8;
}
memcpy ( V_30 , V_93 , V_83 ) ;
}
return;
V_8:
memset ( V_30 , 0 , V_83 ) ;
}
static void F_39 ( struct V_6 * V_7 , unsigned V_56 , bool V_94 )
{
T_1 V_30 [ V_83 ] ;
unsigned V_13 ;
if ( ! V_7 -> V_85 )
return;
F_33 ( V_7 , V_56 , V_30 ) ;
for ( V_13 = 0 ; V_13 < V_80 ; V_13 ++ ) {
struct V_69 * V_79 = F_30 ( V_7 , V_56 , V_13 ) ;
if ( F_16 ( V_94 ) )
memcpy ( & V_79 -> V_95 , V_30 + ( V_13 * V_96 ) , V_96 ) ;
else {
if ( memcmp ( & V_79 -> V_95 , V_30 + ( V_13 * V_96 ) , V_96 ) )
F_6 ( V_7 , L_12 , - V_9 ) ;
}
}
}
static void F_40 ( void * V_97 )
{
struct V_98 * V_99 = V_97 ;
F_41 ( ! F_42 ( & V_99 -> V_100 ) ) ;
if ( F_16 ( F_43 ( & V_99 -> V_100 ) ) )
F_44 ( & V_99 -> V_99 ) ;
}
static void F_45 ( struct V_6 * V_7 , bool V_101 , unsigned V_56 ,
unsigned V_102 , struct V_98 * V_99 )
{
struct V_103 V_104 ;
T_2 V_105 = ( T_2 ) ( V_102 * V_7 -> V_63 ) << V_28 ;
unsigned V_65 , V_66 , V_106 ;
struct V_70 * V_107 , * V_108 ;
if ( F_16 ( V_101 ) ) {
V_107 = V_7 -> V_75 ;
V_108 = V_7 -> V_109 ;
} else {
V_107 = V_7 -> V_109 ;
V_108 = V_7 -> V_75 ;
}
F_27 ( V_7 , V_56 , 0 , & V_65 , & V_66 ) ;
F_46 ( F_47 ( V_66 + V_105 , V_68 ) >> V_67 , & V_99 -> V_100 ) ;
F_48 ( & V_104 , V_110 , NULL , F_40 , V_99 , NULL ) ;
V_106 = V_65 ;
do {
T_2 V_111 ;
struct V_74 * V_112 [ 2 ] ;
struct V_74 * V_113 ;
while ( F_20 ( V_65 == V_106 ) ) {
unsigned V_114 ;
if ( F_16 ( V_101 ) )
F_39 ( V_7 , V_56 , true ) ;
V_56 ++ ;
V_102 -- ;
if ( ! V_102 )
break;
F_27 ( V_7 , V_56 , 0 , & V_106 , & V_114 ) ;
}
V_111 = F_49 ( V_105 , ( T_2 ) V_68 - V_66 ) ;
V_113 = V_108 [ V_65 ] . V_74 ;
V_112 [ 0 ] = V_107 [ V_65 ] . V_74 ;
V_112 [ 1 ] = V_7 -> V_115 [ V_65 ] . V_74 ;
F_50 ( V_113 , V_112 , V_66 , 2 , V_111 , & V_104 ) ;
V_65 ++ ;
V_66 = 0 ;
V_105 -= V_111 ;
} while ( V_105 );
F_41 ( V_102 ) ;
F_51 () ;
}
static void F_52 ( struct V_116 * V_117 , int V_8 )
{
struct V_98 * V_99 = V_117 -> V_118 ;
if ( F_20 ( V_8 ) ) {
if ( F_16 ( V_8 == - V_119 ) ) {
F_44 ( & V_99 -> V_7 -> V_120 ) ;
return;
}
F_6 ( V_99 -> V_7 , L_13 , V_8 ) ;
}
F_40 ( V_99 ) ;
}
static bool F_53 ( bool V_101 , struct V_121 * V_117 , struct V_98 * V_99 )
{
int V_86 ;
F_54 ( V_117 , V_122 | V_90 ,
F_52 , V_99 ) ;
if ( F_16 ( V_101 ) )
V_86 = F_55 ( V_117 ) ;
else
V_86 = F_56 ( V_117 ) ;
if ( F_16 ( ! V_86 ) )
return false ;
if ( F_16 ( V_86 == - V_119 ) )
return true ;
if ( F_16 ( V_86 == - V_123 ) ) {
F_57 ( & V_99 -> V_7 -> V_120 ) ;
F_58 ( & V_99 -> V_7 -> V_120 ) ;
return true ;
}
F_6 ( V_99 -> V_7 , L_14 , V_86 ) ;
return false ;
}
static void F_59 ( struct V_6 * V_7 , bool V_101 , unsigned V_56 ,
unsigned V_102 , struct V_98 * V_99 )
{
struct V_124 * * V_125 ;
struct V_124 * * V_126 ;
F_46 ( 2 , & V_99 -> V_100 ) ;
if ( F_16 ( V_101 ) ) {
V_125 = V_7 -> V_127 ;
V_126 = V_7 -> V_128 ;
} else {
V_125 = V_7 -> V_128 ;
V_126 = V_7 -> V_127 ;
}
do {
struct V_121 * V_117 ;
unsigned V_129 ;
char * V_130 ;
if ( F_16 ( V_101 ) )
F_39 ( V_7 , V_56 , true ) ;
V_117 = V_7 -> V_131 [ V_56 ] ;
V_129 = F_60 ( V_7 -> V_132 ) ;
V_130 = V_117 -> V_130 ;
memcpy ( V_130 , V_130 + V_129 , V_129 ) ;
V_117 -> V_133 = V_125 [ V_56 ] ;
V_117 -> V_134 = V_126 [ V_56 ] ;
if ( F_20 ( F_53 ( V_101 , V_117 , V_99 ) ) )
F_61 ( & V_99 -> V_100 ) ;
V_56 ++ ;
V_102 -- ;
} while ( V_102 );
F_62 ( & V_99 -> V_100 ) ;
F_40 ( V_99 ) ;
}
static void F_63 ( struct V_6 * V_7 , bool V_101 , unsigned V_56 ,
unsigned V_102 , struct V_98 * V_99 )
{
if ( V_7 -> V_115 )
return F_45 ( V_7 , V_101 , V_56 , V_102 , V_99 ) ;
else
return F_59 ( V_7 , V_101 , V_56 , V_102 , V_99 ) ;
}
static void F_64 ( unsigned long error , void * V_97 )
{
struct V_98 * V_99 = V_97 ;
if ( F_20 ( error != 0 ) )
F_6 ( V_99 -> V_7 , L_15 , - V_135 ) ;
F_40 ( V_99 ) ;
}
static void F_65 ( struct V_6 * V_7 , int V_34 , int V_35 , unsigned V_56 ,
unsigned V_102 , struct V_98 * V_99 )
{
struct V_36 V_37 ;
struct V_38 V_39 ;
unsigned V_52 , V_72 , V_65 , V_66 ;
int V_86 ;
if ( F_20 ( F_10 ( V_7 ) ) ) {
if ( V_99 )
F_64 ( - 1UL , V_99 ) ;
return;
}
V_52 = V_56 * V_7 -> V_63 ;
V_72 = V_102 * V_7 -> V_63 ;
V_65 = V_52 >> ( V_67 - V_28 ) ;
V_66 = ( V_52 << V_28 ) & ( V_68 - 1 ) ;
V_37 . V_40 = V_34 ;
V_37 . V_41 = V_35 ;
V_37 . V_42 . type = V_136 ;
if ( V_7 -> V_109 )
V_37 . V_42 . V_44 . V_71 = & V_7 -> V_109 [ V_65 ] ;
else
V_37 . V_42 . V_44 . V_71 = & V_7 -> V_75 [ V_65 ] ;
V_37 . V_42 . V_18 = V_66 ;
if ( F_16 ( V_99 != NULL ) ) {
V_37 . V_46 . V_47 = F_64 ;
V_37 . V_46 . V_97 = V_99 ;
} else {
V_37 . V_46 . V_47 = NULL ;
}
V_37 . V_48 = V_7 -> V_49 ;
V_39 . V_50 = V_7 -> V_51 -> V_50 ;
V_39 . V_52 = V_7 -> V_53 + V_55 + V_52 ;
V_39 . V_54 = V_72 ;
V_86 = F_22 ( & V_37 , 1 , & V_39 , NULL ) ;
if ( F_20 ( V_86 ) ) {
F_6 ( V_7 , V_34 == V_137 ? L_16 : L_15 , V_86 ) ;
if ( V_99 ) {
F_66 ( 1 , L_17 , V_86 ) ;
F_64 ( - 1UL , V_99 ) ;
}
}
}
static void F_67 ( struct V_6 * V_7 , unsigned V_138 , unsigned V_139 )
{
struct V_98 V_140 ;
struct V_98 V_141 ;
struct V_98 V_142 ;
unsigned V_12 ;
V_140 . V_7 = V_7 ;
F_68 ( & V_140 . V_99 ) ;
if ( V_138 + V_139 <= V_7 -> V_33 ) {
V_140 . V_100 = ( V_143 ) F_69 ( 1 ) ;
if ( V_7 -> V_109 ) {
V_141 . V_7 = V_7 ;
F_68 ( & V_141 . V_99 ) ;
V_141 . V_100 = ( V_143 ) F_69 ( 0 ) ;
F_63 ( V_7 , true , V_138 , V_139 , & V_141 ) ;
F_70 ( & V_141 . V_99 ) ;
} else {
for ( V_12 = 0 ; V_12 < V_139 ; V_12 ++ )
F_39 ( V_7 , V_138 + V_12 , true ) ;
}
F_65 ( V_7 , V_144 , V_145 | V_146 , V_138 ,
V_139 , & V_140 ) ;
} else {
unsigned V_147 ;
V_140 . V_100 = ( V_143 ) F_69 ( 2 ) ;
V_147 = V_7 -> V_33 - V_138 ;
if ( V_7 -> V_109 ) {
V_141 . V_7 = V_7 ;
F_68 ( & V_141 . V_99 ) ;
V_141 . V_100 = ( V_143 ) F_69 ( 0 ) ;
F_63 ( V_7 , true , V_138 , V_147 , & V_141 ) ;
if ( F_71 ( & V_141 . V_99 ) ) {
F_65 ( V_7 , V_144 , V_145 , V_138 , V_147 , & V_140 ) ;
F_58 ( & V_141 . V_99 ) ;
V_141 . V_100 = ( V_143 ) F_69 ( 0 ) ;
F_63 ( V_7 , true , 0 , V_139 - V_147 , & V_141 ) ;
F_70 ( & V_141 . V_99 ) ;
} else {
V_142 . V_7 = V_7 ;
F_68 ( & V_142 . V_99 ) ;
V_142 . V_100 = ( V_143 ) F_69 ( 0 ) ;
F_63 ( V_7 , true , 0 , V_139 - V_147 , & V_142 ) ;
F_70 ( & V_141 . V_99 ) ;
F_65 ( V_7 , V_144 , V_145 , V_138 , V_147 , & V_140 ) ;
F_70 ( & V_142 . V_99 ) ;
}
} else {
for ( V_12 = 0 ; V_12 < V_147 ; V_12 ++ )
F_39 ( V_7 , V_138 + V_12 , true ) ;
F_65 ( V_7 , V_144 , V_145 , V_138 , V_147 , & V_140 ) ;
for ( V_12 = 0 ; V_12 < V_139 - V_147 ; V_12 ++ )
F_39 ( V_7 , V_12 , true ) ;
}
F_65 ( V_7 , V_144 , V_145 , 0 , V_139 - V_147 , & V_140 ) ;
}
F_70 ( & V_140 . V_99 ) ;
}
static void F_72 ( struct V_6 * V_7 , unsigned V_56 , unsigned V_18 ,
unsigned V_72 , T_5 V_148 , T_6 V_47 , void * V_118 )
{
struct V_36 V_37 ;
struct V_38 V_39 ;
int V_86 ;
unsigned V_52 , V_65 , V_66 ;
F_41 ( ( V_148 | V_72 | V_18 ) & ( unsigned ) ( V_7 -> V_149 - 1 ) ) ;
if ( F_20 ( F_10 ( V_7 ) ) ) {
V_47 ( - 1UL , V_118 ) ;
return;
}
V_52 = V_56 * V_7 -> V_63 + V_80 + V_18 ;
V_65 = V_52 >> ( V_67 - V_28 ) ;
V_66 = ( V_52 << V_28 ) & ( V_68 - 1 ) ;
V_37 . V_40 = V_144 ;
V_37 . V_41 = 0 ;
V_37 . V_42 . type = V_136 ;
V_37 . V_42 . V_44 . V_71 = & V_7 -> V_75 [ V_65 ] ;
V_37 . V_42 . V_18 = V_66 ;
V_37 . V_46 . V_47 = V_47 ;
V_37 . V_46 . V_97 = V_118 ;
V_37 . V_48 = V_7 -> V_49 ;
V_39 . V_50 = V_7 -> V_51 -> V_50 ;
V_39 . V_52 = V_7 -> V_53 + V_148 ;
V_39 . V_54 = V_72 ;
V_86 = F_22 ( & V_37 , 1 , & V_39 , NULL ) ;
if ( F_20 ( V_86 ) ) {
F_66 ( 1 , L_17 , V_86 ) ;
V_47 ( - 1UL , V_118 ) ;
}
}
static bool F_73 ( struct V_6 * V_7 , struct V_150 * V_151 )
{
struct V_152 * * V_77 = & V_7 -> V_153 . V_152 ;
struct V_152 * V_154 ;
F_41 ( ( V_151 -> V_155 | V_151 -> V_72 ) & ( unsigned ) ( V_7 -> V_149 - 1 ) ) ;
V_154 = NULL ;
while ( * V_77 ) {
struct V_150 * V_156 = F_74 ( * V_77 , struct V_150 , V_157 ) ;
V_154 = * V_77 ;
if ( V_151 -> V_155 + V_151 -> V_72 <= V_156 -> V_155 ) {
V_77 = & V_156 -> V_157 . V_158 ;
} else if ( V_151 -> V_155 >= V_156 -> V_155 + V_156 -> V_72 ) {
V_77 = & V_156 -> V_157 . V_159 ;
} else {
return false ;
}
}
F_75 ( & V_151 -> V_157 , V_154 , V_77 ) ;
F_76 ( & V_151 -> V_157 , & V_7 -> V_153 ) ;
return true ;
}
static void F_77 ( struct V_6 * V_7 , struct V_150 * V_156 )
{
F_78 ( & V_156 -> V_157 , & V_7 -> V_153 ) ;
F_79 ( & V_7 -> V_160 ) ;
}
static void F_80 ( struct V_6 * V_7 , struct V_150 * V_156 )
{
unsigned long V_89 ;
F_81 ( & V_7 -> V_160 . V_161 , V_89 ) ;
F_77 ( V_7 , V_156 ) ;
F_82 ( & V_7 -> V_160 . V_161 , V_89 ) ;
}
static void F_83 ( struct V_162 * V_157 )
{
F_84 ( & V_157 -> V_157 ) ;
V_157 -> V_52 = ( T_5 ) - 1 ;
}
static void F_85 ( struct V_6 * V_7 , struct V_162 * V_157 , T_5 V_52 )
{
struct V_152 * * V_163 ;
struct V_152 * V_154 ;
V_157 -> V_52 = V_52 ;
F_41 ( ! F_86 ( & V_157 -> V_157 ) ) ;
V_163 = & V_7 -> V_164 . V_152 ;
V_154 = NULL ;
while ( * V_163 ) {
struct V_162 * V_13 ;
V_154 = * V_163 ;
V_13 = F_74 ( V_154 , struct V_162 , V_157 ) ;
if ( V_52 < V_13 -> V_52 )
V_163 = & V_13 -> V_157 . V_158 ;
else
V_163 = & V_13 -> V_157 . V_159 ;
}
F_75 ( & V_157 -> V_157 , V_154 , V_163 ) ;
F_76 ( & V_157 -> V_157 , & V_7 -> V_164 ) ;
}
static void F_87 ( struct V_6 * V_7 , struct V_162 * V_157 )
{
F_41 ( F_86 ( & V_157 -> V_157 ) ) ;
F_78 ( & V_157 -> V_157 , & V_7 -> V_164 ) ;
F_83 ( V_157 ) ;
}
static unsigned F_88 ( struct V_6 * V_7 , T_5 V_52 , T_5 * V_165 )
{
struct V_152 * V_77 = V_7 -> V_164 . V_152 ;
unsigned V_166 = V_167 ;
* V_165 = ( T_5 ) - 1 ;
while ( V_77 ) {
struct V_162 * V_13 = F_74 ( V_77 , struct V_162 , V_157 ) ;
if ( V_52 == V_13 -> V_52 ) {
V_166 = V_13 - V_7 -> V_168 ;
}
if ( V_52 < V_13 -> V_52 ) {
* V_165 = V_13 -> V_52 ;
V_77 = V_13 -> V_157 . V_158 ;
} else {
V_77 = V_13 -> V_157 . V_159 ;
}
}
return V_166 ;
}
static bool F_89 ( struct V_6 * V_7 , unsigned V_169 , T_5 V_52 )
{
struct V_162 * V_157 , * V_170 ;
struct V_152 * V_171 ;
if ( F_20 ( V_169 >= V_7 -> V_172 ) )
return false ;
V_157 = & V_7 -> V_168 [ V_169 ] ;
if ( F_20 ( F_86 ( & V_157 -> V_157 ) ) )
return false ;
if ( F_20 ( V_157 -> V_52 != V_52 ) )
return false ;
V_171 = F_90 ( & V_157 -> V_157 ) ;
if ( F_20 ( ! V_171 ) )
return true ;
V_170 = F_74 ( V_171 , struct V_162 , V_157 ) ;
return V_170 -> V_52 != V_52 ;
}
static bool F_91 ( struct V_6 * V_7 , struct V_162 * V_157 )
{
struct V_152 * V_171 ;
struct V_162 * V_170 ;
unsigned V_173 ;
F_41 ( F_86 ( & V_157 -> V_157 ) ) ;
V_171 = F_90 ( & V_157 -> V_157 ) ;
if ( F_20 ( ! V_171 ) )
return false ;
V_170 = F_74 ( V_171 , struct V_162 , V_157 ) ;
if ( V_170 -> V_52 != V_157 -> V_52 )
return false ;
V_173 = ( unsigned ) ( V_170 - V_7 -> V_168 ) / V_7 -> V_62 ;
if ( V_173 >= V_7 -> V_174 &&
V_173 < V_7 -> V_174 + V_7 -> V_175 )
return true ;
if ( V_173 + V_7 -> V_33 < V_7 -> V_174 + V_7 -> V_175 )
return true ;
return false ;
}
static int F_92 ( struct V_6 * V_7 , unsigned char * V_176 , T_5 * V_177 ,
unsigned * V_21 , unsigned V_178 , int V_34 )
{
do {
unsigned char * V_118 , * V_179 ;
struct V_180 * V_181 ;
unsigned V_182 ;
int V_86 ;
V_86 = F_10 ( V_7 ) ;
if ( F_20 ( V_86 ) )
return V_86 ;
V_118 = F_93 ( V_7 -> V_183 , * V_177 , & V_181 ) ;
if ( F_20 ( F_94 ( V_118 ) ) )
return F_95 ( V_118 ) ;
V_182 = F_49 ( ( 1U << V_28 << V_7 -> V_26 ) - * V_21 , V_178 ) ;
V_179 = V_118 + * V_21 ;
if ( V_34 == V_184 ) {
memcpy ( V_176 , V_179 , V_182 ) ;
} else if ( V_34 == V_185 ) {
memcpy ( V_179 , V_176 , V_182 ) ;
F_96 ( V_181 , * V_21 , * V_21 + V_182 ) ;
} else {
if ( F_20 ( memcmp ( V_179 , V_176 , V_182 ) ) ) {
unsigned V_12 ;
for ( V_12 = 0 ; V_12 < V_182 ; V_12 ++ ) {
if ( V_179 [ V_12 ] != V_176 [ V_12 ] )
break;
V_178 -- ;
}
F_97 ( V_181 ) ;
return V_178 ;
}
}
F_97 ( V_181 ) ;
V_176 += V_182 ;
* V_21 += V_182 ;
if ( F_20 ( * V_21 == 1U << V_28 << V_7 -> V_26 ) ) {
( * V_177 ) ++ ;
* V_21 = 0 ;
}
V_178 -= V_182 ;
} while ( F_20 ( V_178 ) );
return 0 ;
}
static void F_98 ( struct V_6 * V_7 )
{
int V_86 ;
V_86 = F_99 ( V_7 -> V_183 ) ;
if ( F_20 ( V_86 ) )
F_6 ( V_7 , L_18 , V_86 ) ;
}
static void F_100 ( struct V_6 * V_7 )
{
F_101 ( V_186 , V_187 ) ;
F_102 ( & V_7 -> V_160 , & V_186 ) ;
F_103 ( V_188 ) ;
F_104 ( & V_7 -> V_160 . V_161 ) ;
F_105 () ;
F_106 ( & V_7 -> V_160 . V_161 ) ;
F_107 ( & V_7 -> V_160 , & V_186 ) ;
}
static void F_108 ( unsigned long V_118 )
{
struct V_6 * V_7 = (struct V_6 * ) V_118 ;
if ( F_16 ( ! F_10 ( V_7 ) ) )
F_109 ( V_7 -> V_189 , & V_7 -> V_190 ) ;
}
static void F_110 ( struct V_6 * V_7 )
{
if ( ! F_111 ( & V_7 -> V_191 ) )
F_112 ( & V_7 -> V_191 , V_192 + V_7 -> V_193 ) ;
}
static void F_113 ( struct V_6 * V_7 , struct V_194 * V_195 )
{
struct V_196 * V_196 ;
unsigned long V_89 ;
F_81 ( & V_7 -> V_160 . V_161 , V_89 ) ;
V_196 = F_114 ( V_195 , sizeof( struct V_194 ) ) ;
F_115 ( & V_7 -> V_197 , V_196 ) ;
F_82 ( & V_7 -> V_160 . V_161 , V_89 ) ;
F_109 ( V_7 -> V_189 , & V_7 -> V_190 ) ;
}
static void F_116 ( struct V_6 * V_7 , struct V_196 * V_196 )
{
int V_86 = F_10 ( V_7 ) ;
if ( F_20 ( V_86 ) && ! V_196 -> V_198 )
V_196 -> V_198 = F_117 ( V_86 ) ;
F_118 ( V_196 ) ;
}
static void F_119 ( struct V_6 * V_7 , struct V_194 * V_195 )
{
struct V_196 * V_196 = F_114 ( V_195 , sizeof( struct V_194 ) ) ;
if ( F_20 ( V_195 -> V_199 ) && F_16 ( ! V_196 -> V_198 ) && F_16 ( ! F_10 ( V_7 ) ) )
F_113 ( V_7 , V_195 ) ;
else
F_116 ( V_7 , V_196 ) ;
}
static void F_120 ( struct V_194 * V_195 )
{
if ( F_43 ( & V_195 -> V_100 ) ) {
struct V_6 * V_7 = V_195 -> V_7 ;
struct V_196 * V_196 ;
F_80 ( V_7 , & V_195 -> V_156 ) ;
if ( F_20 ( V_195 -> V_200 ) )
F_110 ( V_7 ) ;
V_196 = F_114 ( V_195 , sizeof( struct V_194 ) ) ;
if ( F_20 ( V_195 -> V_198 ) && ! V_196 -> V_198 )
V_196 -> V_198 = V_195 -> V_198 ;
if ( F_16 ( ! V_196 -> V_198 ) && F_20 ( F_121 ( V_196 ) != V_195 -> V_156 . V_72 ) ) {
V_195 -> V_156 . V_155 += V_195 -> V_156 . V_72 ;
F_122 ( V_196 , V_195 -> V_156 . V_72 << V_28 ) ;
F_123 ( & V_195 -> V_201 , V_202 ) ;
F_109 ( V_7 -> V_203 , & V_195 -> V_201 ) ;
return;
}
F_119 ( V_7 , V_195 ) ;
}
}
static void F_124 ( struct V_196 * V_196 )
{
struct V_194 * V_195 = F_125 ( V_196 , sizeof( struct V_194 ) ) ;
V_196 -> V_204 = V_195 -> V_205 ;
V_196 -> V_206 = V_195 -> V_207 ;
V_196 -> V_208 = V_195 -> V_209 ;
if ( V_195 -> V_210 ) {
V_196 -> V_211 = V_195 -> V_210 ;
V_196 -> V_212 |= V_213 ;
}
V_196 -> V_214 = V_195 -> V_215 ;
if ( V_195 -> V_216 )
F_44 ( V_195 -> V_216 ) ;
F_120 ( V_195 ) ;
}
static void F_126 ( struct V_6 * V_7 , T_5 V_52 ,
const char * V_118 , char * V_30 )
{
V_15 V_217 = F_13 ( V_52 ) ;
F_34 ( V_117 , V_7 -> V_218 ) ;
int V_86 ;
unsigned V_219 ;
V_117 -> V_88 = V_7 -> V_218 ;
V_117 -> V_89 = 0 ;
V_86 = F_35 ( V_117 ) ;
if ( F_20 ( V_86 < 0 ) ) {
F_6 ( V_7 , L_9 , V_86 ) ;
goto V_11;
}
V_86 = F_36 ( V_117 , ( const T_1 * ) & V_217 , sizeof V_217 ) ;
if ( F_20 ( V_86 < 0 ) ) {
F_6 ( V_7 , L_10 , V_86 ) ;
goto V_11;
}
V_86 = F_36 ( V_117 , V_118 , V_7 -> V_149 << V_28 ) ;
if ( F_20 ( V_86 < 0 ) ) {
F_6 ( V_7 , L_10 , V_86 ) ;
goto V_11;
}
V_86 = F_38 ( V_117 , V_30 ) ;
if ( F_20 ( V_86 < 0 ) ) {
F_6 ( V_7 , L_11 , V_86 ) ;
goto V_11;
}
V_219 = F_37 ( V_7 -> V_218 ) ;
if ( F_20 ( V_219 < V_7 -> V_29 ) )
memset ( V_30 + V_219 , 0 , V_7 -> V_29 - V_219 ) ;
return;
V_11:
F_127 ( V_30 , V_7 -> V_29 ) ;
}
static void F_128 ( struct V_220 * V_221 )
{
struct V_194 * V_195 = F_74 ( V_221 , struct V_194 , V_201 ) ;
struct V_6 * V_7 = V_195 -> V_7 ;
int V_86 ;
if ( V_7 -> V_218 ) {
struct V_222 V_223 ;
struct V_224 V_225 ;
unsigned V_219 = F_37 ( V_7 -> V_218 ) ;
struct V_196 * V_196 = F_114 ( V_195 , sizeof( struct V_194 ) ) ;
char * V_226 ;
unsigned V_227 = F_20 ( V_219 > V_7 -> V_29 ) ? V_219 - V_7 -> V_29 : 0 ;
char V_228 [ V_7 -> V_29 + V_227 ] ;
unsigned V_229 = V_195 -> V_156 . V_72 ;
T_5 V_52 = V_195 -> V_156 . V_155 ;
if ( F_20 ( V_7 -> V_230 == 'R' ) )
goto V_231;
V_226 = F_129 ( ( V_68 >> V_28 >> V_7 -> V_20 -> V_82 ) * V_7 -> V_29 + V_227 ,
V_232 | V_233 | V_234 ) ;
if ( ! V_226 )
V_226 = V_228 ;
F_130 (bv, bio, iter, dio->orig_bi_iter) {
unsigned V_169 ;
char * V_42 , * V_235 ;
V_236:
V_42 = ( char * ) F_131 ( V_225 . V_237 ) + V_225 . V_238 ;
V_169 = 0 ;
V_235 = V_226 ;
do {
F_126 ( V_7 , V_52 , V_42 + V_169 , V_235 ) ;
V_235 += V_7 -> V_29 ;
V_229 -= V_7 -> V_149 ;
V_169 += V_7 -> V_149 << V_28 ;
V_52 += V_7 -> V_149 ;
} while ( V_169 < V_225 . V_239 && V_229 && V_226 != V_228 );
F_132 ( V_42 ) ;
V_86 = F_92 ( V_7 , V_226 , & V_195 -> V_177 , & V_195 -> V_21 ,
V_235 - V_226 , ! V_195 -> V_200 ? V_240 : V_185 ) ;
if ( F_20 ( V_86 ) ) {
if ( V_86 > 0 ) {
F_9 ( L_19 ,
( unsigned long long ) ( V_52 - ( ( V_86 + V_7 -> V_29 - 1 ) / V_7 -> V_29 ) ) ) ;
V_86 = - V_9 ;
F_7 ( & V_7 -> V_10 ) ;
}
if ( F_16 ( V_226 != V_228 ) )
F_133 ( V_226 ) ;
goto error;
}
if ( ! V_229 )
break;
if ( F_20 ( V_169 < V_225 . V_239 ) ) {
V_225 . V_238 += V_169 ;
V_225 . V_239 -= V_169 ;
goto V_236;
}
}
if ( F_16 ( V_226 != V_228 ) )
F_133 ( V_226 ) ;
} else {
struct V_241 * V_242 = V_195 -> V_210 ;
if ( V_242 ) {
struct V_224 V_243 ;
struct V_222 V_223 ;
unsigned V_244 = V_195 -> V_156 . V_72 ;
F_17 ( V_7 , V_244 ) ;
V_244 *= V_7 -> V_29 ;
F_134 (biv, bip, iter) {
unsigned char * V_176 ;
unsigned V_245 ;
F_41 ( F_135 ( V_243 . V_237 ) ) ;
V_176 = F_29 ( V_243 . V_237 ) + V_243 . V_238 ;
V_245 = F_49 ( V_243 . V_239 , V_244 ) ;
V_86 = F_92 ( V_7 , V_176 , & V_195 -> V_177 , & V_195 -> V_21 ,
V_245 , ! V_195 -> V_200 ? V_184 : V_185 ) ;
if ( F_20 ( V_86 ) )
goto error;
V_244 -= V_245 ;
if ( ! V_244 )
break;
}
}
}
V_231:
F_120 ( V_195 ) ;
return;
error:
V_195 -> V_198 = F_117 ( V_86 ) ;
F_120 ( V_195 ) ;
}
static int F_136 ( struct V_246 * V_247 , struct V_196 * V_196 )
{
struct V_6 * V_7 = V_247 -> V_248 ;
struct V_194 * V_195 = F_125 ( V_196 , sizeof( struct V_194 ) ) ;
struct V_241 * V_242 ;
T_5 V_17 , V_18 ;
V_195 -> V_7 = V_7 ;
V_195 -> V_198 = 0 ;
if ( F_20 ( V_196 -> V_212 & V_249 ) ) {
F_113 ( V_7 , V_195 ) ;
return V_250 ;
}
V_195 -> V_156 . V_155 = F_137 ( V_247 , V_196 -> V_204 . V_251 ) ;
V_195 -> V_200 = F_138 ( V_196 ) == V_144 ;
V_195 -> V_199 = V_195 -> V_200 && V_196 -> V_212 & V_145 ;
if ( F_20 ( V_195 -> V_199 ) ) {
V_196 -> V_212 &= ~ V_145 ;
}
if ( F_20 ( V_195 -> V_156 . V_155 + F_121 ( V_196 ) > V_7 -> V_252 ) ) {
F_9 ( L_20 ,
( unsigned long long ) V_195 -> V_156 . V_155 , F_121 ( V_196 ) ,
( unsigned long long ) V_7 -> V_252 ) ;
return V_253 ;
}
if ( F_20 ( ( V_195 -> V_156 . V_155 | F_121 ( V_196 ) ) & ( unsigned ) ( V_7 -> V_149 - 1 ) ) ) {
F_9 ( L_21 ,
V_7 -> V_149 ,
( unsigned long long ) V_195 -> V_156 . V_155 , F_121 ( V_196 ) ) ;
return V_253 ;
}
if ( V_7 -> V_149 > 1 ) {
struct V_222 V_223 ;
struct V_224 V_225 ;
F_139 (bv, bio, iter) {
if ( F_20 ( ( V_225 . V_238 | V_225 . V_239 ) & ( ( V_7 -> V_149 << V_28 ) - 1 ) ) ) {
F_9 ( L_22 ,
V_225 . V_238 , V_225 . V_239 , V_7 -> V_149 ) ;
return V_253 ;
}
}
}
V_242 = F_140 ( V_196 ) ;
if ( ! V_7 -> V_218 ) {
if ( V_242 ) {
unsigned V_254 = F_121 ( V_196 ) >> V_7 -> V_20 -> V_82 ;
if ( V_7 -> V_27 >= 0 )
V_254 <<= V_7 -> V_27 ;
else
V_254 *= V_7 -> V_29 ;
if ( F_20 ( V_254 != V_242 -> V_255 . V_256 ) ) {
F_9 ( L_23 , V_242 -> V_255 . V_256 , V_254 ) ;
return V_253 ;
}
}
} else {
if ( F_20 ( V_242 != NULL ) ) {
F_9 ( L_24 ) ;
return V_253 ;
}
}
if ( F_20 ( V_7 -> V_230 == 'R' ) && F_20 ( V_195 -> V_200 ) )
return V_253 ;
F_14 ( V_7 , V_195 -> V_156 . V_155 , & V_17 , & V_18 ) ;
V_195 -> V_177 = F_15 ( V_7 , V_17 , V_18 , & V_195 -> V_21 ) ;
V_196 -> V_204 . V_251 = F_18 ( V_7 , V_17 , V_18 ) ;
F_141 ( V_195 , true ) ;
return V_250 ;
}
static bool F_142 ( struct V_194 * V_195 , struct V_196 * V_196 ,
unsigned V_257 , unsigned V_76 )
{
struct V_6 * V_7 = V_195 -> V_7 ;
T_5 V_155 ;
unsigned V_72 ;
V_155 = V_195 -> V_156 . V_155 ;
V_72 = V_195 -> V_156 . V_72 ;
do {
struct V_224 V_225 = F_143 ( V_196 ) ;
char * V_42 ;
if ( F_20 ( V_225 . V_239 >> V_28 > V_72 ) )
V_225 . V_239 = V_72 << V_28 ;
V_72 -= V_225 . V_239 >> V_28 ;
F_144 ( V_196 , & V_196 -> V_204 , V_225 . V_239 ) ;
V_258:
V_42 = F_131 ( V_225 . V_237 ) ;
if ( F_16 ( V_195 -> V_200 ) )
F_145 ( V_225 . V_237 ) ;
do {
struct V_76 * V_91 = F_31 ( V_7 , V_257 , V_76 ) ;
if ( F_20 ( ! V_195 -> V_200 ) ) {
struct V_69 * V_79 ;
char * V_259 ;
unsigned V_260 ;
if ( F_20 ( F_146 ( V_91 ) ) ) {
F_145 ( V_225 . V_237 ) ;
F_132 ( V_42 ) ;
F_147 ( V_7 -> V_261 , ! F_146 ( V_91 ) ) ;
goto V_258;
}
F_148 () ;
F_41 ( F_149 ( V_91 ) != V_155 ) ;
V_79 = F_32 ( V_7 , V_257 , V_76 ) ;
V_259 = V_42 + V_225 . V_238 ;
V_260 = 0 ;
do {
memcpy ( V_259 , V_79 , V_262 ) ;
* ( T_4 * ) ( V_259 + V_262 ) = V_91 -> V_263 [ V_260 ] ;
V_79 ++ ;
V_259 += 1 << V_28 ;
} while ( ++ V_260 < V_7 -> V_149 );
#ifdef V_60
if ( V_7 -> V_218 ) {
char V_228 [ F_150 ( F_37 ( V_7 -> V_218 ) , V_7 -> V_29 ) ] ;
F_126 ( V_7 , V_155 , V_42 + V_225 . V_238 , V_228 ) ;
if ( F_20 ( memcmp ( V_228 , F_151 ( V_7 , V_91 ) , V_7 -> V_29 ) ) ) {
F_9 ( L_25 ,
( unsigned long long ) V_155 ) ;
}
}
#endif
}
if ( ! V_7 -> V_218 ) {
struct V_241 * V_242 = F_140 ( V_196 ) ;
unsigned V_264 = V_7 -> V_29 ;
char * V_265 = F_151 ( V_7 , V_91 ) ;
if ( V_242 ) do {
struct V_224 V_243 = F_152 ( V_242 -> V_266 , V_242 -> V_255 ) ;
unsigned V_267 = F_49 ( V_243 . V_239 , V_264 ) ;
char * V_268 ;
F_41 ( F_135 ( V_243 . V_237 ) ) ;
V_268 = F_29 ( V_243 . V_237 ) + V_243 . V_238 ;
if ( F_16 ( V_195 -> V_200 ) )
memcpy ( V_265 , V_268 , V_267 ) ;
else
memcpy ( V_268 , V_265 , V_267 ) ;
F_153 ( V_242 -> V_266 , & V_242 -> V_255 , V_267 ) ;
V_265 += V_267 ;
V_264 -= V_267 ;
} while ( F_20 ( V_264 ) ); else {
if ( F_16 ( V_195 -> V_200 ) )
memset ( V_265 , 0 , V_264 ) ;
}
}
if ( F_16 ( V_195 -> V_200 ) ) {
struct V_69 * V_79 ;
unsigned V_260 ;
V_79 = F_32 ( V_7 , V_257 , V_76 ) ;
memcpy ( V_79 , V_42 + V_225 . V_238 , V_7 -> V_149 << V_28 ) ;
V_260 = 0 ;
do {
V_91 -> V_263 [ V_260 ] = V_79 [ V_260 ] . V_269 ;
} while ( ++ V_260 < V_7 -> V_149 );
if ( V_7 -> V_218 ) {
unsigned V_219 = F_37 ( V_7 -> V_218 ) ;
if ( F_20 ( V_219 > V_7 -> V_29 ) ) {
char V_228 [ V_219 ] ;
F_126 ( V_7 , V_155 , ( char * ) V_79 , V_228 ) ;
memcpy ( F_151 ( V_7 , V_91 ) , V_228 , V_7 -> V_29 ) ;
} else
F_126 ( V_7 , V_155 , ( char * ) V_79 , F_151 ( V_7 , V_91 ) ) ;
}
F_154 ( V_91 , V_155 ) ;
}
V_155 += V_7 -> V_149 ;
V_76 ++ ;
if ( F_20 ( V_76 == V_7 -> V_62 ) ) {
V_76 = 0 ;
V_257 ++ ;
F_19 ( V_7 , & V_257 ) ;
}
V_225 . V_238 += V_7 -> V_149 << V_28 ;
} while ( V_225 . V_239 -= V_7 -> V_149 << V_28 );
if ( F_20 ( ! V_195 -> V_200 ) )
F_145 ( V_225 . V_237 ) ;
F_132 ( V_42 ) ;
} while ( V_72 );
if ( F_16 ( V_195 -> V_200 ) ) {
F_155 () ;
if ( F_20 ( F_156 ( & V_7 -> V_261 ) ) )
F_157 ( & V_7 -> V_261 ) ;
if ( F_11 ( V_7 -> V_270 ) <= V_7 -> V_271 ) {
F_109 ( V_7 -> V_189 , & V_7 -> V_190 ) ;
} else {
F_110 ( V_7 ) ;
}
} else {
F_80 ( V_7 , & V_195 -> V_156 ) ;
}
if ( F_20 ( V_196 -> V_204 . V_256 ) ) {
T_5 V_17 , V_18 ;
V_195 -> V_156 . V_155 = V_155 ;
F_14 ( V_7 , V_195 -> V_156 . V_155 , & V_17 , & V_18 ) ;
V_195 -> V_177 = F_15 ( V_7 , V_17 , V_18 , & V_195 -> V_21 ) ;
return true ;
}
return false ;
}
static void F_141 ( struct V_194 * V_195 , bool V_272 )
{
struct V_6 * V_7 = V_195 -> V_7 ;
struct V_196 * V_196 = F_114 ( V_195 , sizeof( struct V_194 ) ) ;
unsigned V_257 , V_76 ;
unsigned V_273 ;
struct V_216 V_274 ;
bool V_275 = V_7 -> V_218 && ! V_195 -> V_200 ;
if ( V_275 && V_272 ) {
F_123 ( & V_195 -> V_201 , V_202 ) ;
F_109 ( V_7 -> V_276 , & V_195 -> V_201 ) ;
return;
}
V_277:
F_106 ( & V_7 -> V_160 . V_161 ) ;
V_278:
if ( F_20 ( F_10 ( V_7 ) ) ) {
F_104 ( & V_7 -> V_160 . V_161 ) ;
F_116 ( V_7 , V_196 ) ;
return;
}
V_195 -> V_156 . V_72 = F_121 ( V_196 ) ;
V_273 = V_167 ;
if ( F_16 ( V_7 -> V_230 == 'J' ) ) {
if ( V_195 -> V_200 ) {
unsigned V_279 , V_12 , V_169 ;
unsigned V_280 , V_281 , V_282 ;
V_195 -> V_156 . V_72 = F_49 ( V_195 -> V_156 . V_72 ,
V_7 -> V_270 << V_7 -> V_20 -> V_82 ) ;
if ( F_20 ( ! V_195 -> V_156 . V_72 ) )
goto V_283;
V_282 = V_195 -> V_156 . V_72 >> V_7 -> V_20 -> V_82 ;
V_7 -> V_270 -= V_282 ;
V_257 = V_7 -> V_284 ;
V_76 = V_7 -> V_285 ;
V_279 = V_7 -> V_285 + V_282 ;
V_7 -> V_285 = V_279 % V_7 -> V_62 ;
V_7 -> V_284 += V_279 / V_7 -> V_62 ;
V_7 -> V_286 += V_279 / V_7 -> V_62 ;
F_19 ( V_7 , & V_7 -> V_284 ) ;
V_169 = V_257 * V_7 -> V_62 + V_76 ;
V_280 = V_257 ;
V_281 = V_76 ;
V_12 = 0 ;
do {
struct V_76 * V_91 ;
F_85 ( V_7 , & V_7 -> V_168 [ V_169 ] , V_195 -> V_156 . V_155 + V_12 ) ;
V_169 ++ ;
if ( F_20 ( V_169 >= V_7 -> V_172 ) )
V_169 = 0 ;
V_91 = F_31 ( V_7 , V_280 , V_281 ) ;
F_41 ( ! F_158 ( V_91 ) ) ;
F_159 ( V_91 ) ;
V_281 ++ ;
if ( F_20 ( V_281 == V_7 -> V_62 ) ) {
V_281 = 0 ;
V_280 ++ ;
F_19 ( V_7 , & V_280 ) ;
}
} while ( ( V_12 += V_7 -> V_149 ) < V_195 -> V_156 . V_72 );
F_104 ( & V_7 -> V_160 . V_161 ) ;
goto V_287;
} else {
T_5 V_165 ;
V_273 = F_88 ( V_7 , V_195 -> V_156 . V_155 , & V_165 ) ;
if ( F_16 ( V_273 == V_167 ) ) {
if ( F_20 ( V_195 -> V_156 . V_72 > V_165 - V_195 -> V_156 . V_155 ) )
V_195 -> V_156 . V_72 = V_165 - V_195 -> V_156 . V_155 ;
} else {
unsigned V_12 ;
unsigned V_288 = V_273 + 1 ;
for ( V_12 = V_7 -> V_149 ; V_12 < V_195 -> V_156 . V_72 ; V_12 += V_7 -> V_149 , V_288 ++ ) {
if ( ! F_89 ( V_7 , V_288 , V_195 -> V_156 . V_155 + V_12 ) )
break;
}
V_195 -> V_156 . V_72 = V_12 ;
}
}
}
if ( F_20 ( ! F_73 ( V_7 , & V_195 -> V_156 ) ) ) {
V_283:
if ( V_272 ) {
F_104 ( & V_7 -> V_160 . V_161 ) ;
F_123 ( & V_195 -> V_201 , V_202 ) ;
F_109 ( V_7 -> V_203 , & V_195 -> V_201 ) ;
return;
} else {
F_100 ( V_7 ) ;
goto V_278;
}
}
F_104 ( & V_7 -> V_160 . V_161 ) ;
if ( F_20 ( V_273 != V_167 ) ) {
V_257 = V_273 / V_7 -> V_62 ;
V_76 = V_273 % V_7 -> V_62 ;
goto V_287;
}
V_195 -> V_100 = ( V_143 ) F_69 ( 2 ) ;
if ( V_275 ) {
F_68 ( & V_274 ) ;
V_195 -> V_216 = & V_274 ;
} else
V_195 -> V_216 = NULL ;
V_195 -> V_205 = V_196 -> V_204 ;
V_195 -> V_207 = V_196 -> V_206 ;
V_195 -> V_209 = V_196 -> V_208 ;
F_160 ( V_196 , V_7 -> V_51 -> V_50 ) ;
V_195 -> V_210 = F_140 ( V_196 ) ;
V_196 -> V_211 = NULL ;
V_196 -> V_212 &= ~ V_213 ;
V_195 -> V_215 = V_196 -> V_214 ;
V_196 -> V_214 = F_124 ;
V_196 -> V_204 . V_256 = V_195 -> V_156 . V_72 << V_28 ;
V_196 -> V_204 . V_251 += V_7 -> V_53 ;
F_161 ( V_196 ) ;
if ( V_275 ) {
F_70 ( & V_274 ) ;
if ( F_16 ( ! V_196 -> V_198 ) )
F_128 ( & V_195 -> V_201 ) ;
else
F_120 ( V_195 ) ;
} else {
F_123 ( & V_195 -> V_201 , F_128 ) ;
F_109 ( V_7 -> V_276 , & V_195 -> V_201 ) ;
}
return;
V_287:
if ( F_20 ( F_142 ( V_195 , V_196 , V_257 , V_76 ) ) )
goto V_277;
F_119 ( V_7 , V_195 ) ;
}
static void V_202 ( struct V_220 * V_221 )
{
struct V_194 * V_195 = F_74 ( V_221 , struct V_194 , V_201 ) ;
F_141 ( V_195 , false ) ;
}
static void F_162 ( struct V_6 * V_7 )
{
if ( V_7 -> V_285 ) {
V_7 -> V_270 -= V_7 -> V_62 - V_7 -> V_285 ;
V_7 -> V_285 = 0 ;
V_7 -> V_284 ++ ;
F_19 ( V_7 , & V_7 -> V_284 ) ;
V_7 -> V_286 ++ ;
}
F_163 ( V_7 -> V_33 * V_7 -> V_62 !=
( V_7 -> V_286 + V_7 -> V_175 ) * V_7 -> V_62 + V_7 -> V_270 ) ;
}
static void F_164 ( struct V_220 * V_221 )
{
struct V_6 * V_7 = F_74 ( V_221 , struct V_6 , V_190 ) ;
unsigned V_138 , V_139 ;
unsigned V_12 , V_13 , V_77 ;
struct V_196 * V_289 ;
F_165 ( & V_7 -> V_191 ) ;
F_106 ( & V_7 -> V_160 . V_161 ) ;
V_289 = F_166 ( & V_7 -> V_197 ) ;
if ( F_20 ( V_7 -> V_230 != 'J' ) ) {
F_104 ( & V_7 -> V_160 . V_161 ) ;
F_98 ( V_7 ) ;
goto V_290;
}
F_162 ( V_7 ) ;
V_138 = V_7 -> V_291 ;
V_139 = V_7 -> V_286 ;
F_104 ( & V_7 -> V_160 . V_161 ) ;
if ( ! V_139 )
goto V_290;
V_12 = V_138 ;
for ( V_77 = 0 ; V_77 < V_139 ; V_77 ++ ) {
for ( V_13 = 0 ; V_13 < V_7 -> V_62 ; V_13 ++ ) {
struct V_76 * V_91 ;
V_91 = F_31 ( V_7 , V_12 , V_13 ) ;
F_167 ( V_7 -> V_261 , ! F_146 ( V_91 ) ) ;
}
for ( V_13 = 0 ; V_13 < V_7 -> V_63 ; V_13 ++ ) {
struct V_69 * V_79 ;
V_79 = F_30 ( V_7 , V_12 , V_13 ) ;
V_79 -> V_269 = F_12 ( V_7 , V_12 , V_13 , V_7 -> V_292 ) ;
}
V_12 ++ ;
if ( F_20 ( V_12 >= V_7 -> V_33 ) )
V_7 -> V_292 = F_2 ( V_7 -> V_292 ) ;
F_19 ( V_7 , & V_12 ) ;
}
F_148 () ;
F_67 ( V_7 , V_138 , V_139 ) ;
F_106 ( & V_7 -> V_160 . V_161 ) ;
V_7 -> V_291 += V_139 ;
F_19 ( V_7 , & V_7 -> V_291 ) ;
V_7 -> V_286 -= V_139 ;
V_7 -> V_175 += V_139 ;
F_104 ( & V_7 -> V_160 . V_161 ) ;
if ( F_11 ( V_7 -> V_270 ) <= V_7 -> V_271 )
F_109 ( V_7 -> V_293 , & V_7 -> V_294 ) ;
V_290:
while ( V_289 ) {
struct V_196 * V_171 = V_289 -> V_295 ;
V_289 -> V_295 = NULL ;
F_116 ( V_7 , V_289 ) ;
V_289 = V_171 ;
}
}
static void F_168 ( unsigned long error , void * V_97 )
{
struct V_109 * V_49 = V_97 ;
struct V_98 * V_99 = V_49 -> V_99 ;
struct V_6 * V_7 = V_99 -> V_7 ;
F_80 ( V_7 , & V_49 -> V_156 ) ;
F_169 ( V_49 , V_7 -> V_296 ) ;
if ( F_20 ( error != 0 ) )
F_6 ( V_7 , L_26 , - V_135 ) ;
F_40 ( V_99 ) ;
}
static void F_170 ( struct V_6 * V_7 , struct V_69 * V_79 ,
struct V_76 * V_91 )
{
unsigned V_260 = 0 ;
do {
V_79 -> V_269 = V_91 -> V_263 [ V_260 ] ;
V_79 ++ ;
} while ( ++ V_260 < V_7 -> V_149 );
}
static void F_171 ( struct V_6 * V_7 , unsigned V_297 ,
unsigned V_298 , bool V_299 )
{
unsigned V_12 , V_13 , V_77 ;
struct V_98 V_99 ;
struct V_300 V_301 ;
F_172 ( & V_301 ) ;
V_99 . V_7 = V_7 ;
V_99 . V_100 = ( V_143 ) F_69 ( 1 ) ;
F_68 ( & V_99 . V_99 ) ;
V_12 = V_297 ;
for ( V_77 = 0 ; V_77 < V_298 ; V_77 ++ , V_12 ++ , F_19 ( V_7 , & V_12 ) ) {
#ifndef V_60
if ( F_20 ( V_299 ) )
#endif
F_39 ( V_7 , V_12 , false ) ;
for ( V_13 = 0 ; V_13 < V_7 -> V_62 ; V_13 ++ ) {
struct V_76 * V_91 = F_31 ( V_7 , V_12 , V_13 ) ;
T_5 V_302 , V_17 , V_18 ;
unsigned V_303 , V_304 , V_305 ;
T_5 V_177 ;
unsigned V_21 ;
struct V_109 * V_49 ;
if ( F_158 ( V_91 ) )
continue;
F_41 ( F_20 ( F_146 ( V_91 ) ) && ! V_299 ) ;
V_302 = F_149 ( V_91 ) ;
if ( F_20 ( V_299 ) ) {
if ( F_20 ( V_302 & ( unsigned ) ( V_7 -> V_149 - 1 ) ) ) {
F_6 ( V_7 , L_27 , - V_135 ) ;
V_302 &= ~ ( T_5 ) ( V_7 -> V_149 - 1 ) ;
}
}
F_14 ( V_7 , V_302 , & V_17 , & V_18 ) ;
F_170 ( V_7 , F_32 ( V_7 , V_12 , V_13 ) , V_91 ) ;
for ( V_303 = V_13 + 1 ; V_303 < V_7 -> V_62 ; V_303 ++ ) {
struct V_76 * V_306 = F_31 ( V_7 , V_12 , V_303 ) ;
T_5 V_307 , V_308 , V_309 ;
if ( F_158 ( V_306 ) )
break;
F_41 ( F_20 ( F_146 ( V_306 ) ) && ! V_299 ) ;
V_307 = F_149 ( V_306 ) ;
F_14 ( V_7 , V_307 , & V_308 , & V_309 ) ;
if ( V_308 != V_17 || V_309 != V_18 + ( ( V_303 - V_13 ) << V_7 -> V_20 -> V_82 ) )
break;
F_170 ( V_7 , F_32 ( V_7 , V_12 , V_303 ) , V_306 ) ;
}
V_305 = V_303 - 1 ;
V_49 = F_173 ( V_7 -> V_296 , V_232 ) ;
V_49 -> V_99 = & V_99 ;
V_49 -> V_156 . V_155 = V_302 ;
V_49 -> V_156 . V_72 = ( V_303 - V_13 ) << V_7 -> V_20 -> V_82 ;
F_106 ( & V_7 -> V_160 . V_161 ) ;
while ( F_20 ( ! F_73 ( V_7 , & V_49 -> V_156 ) ) )
F_100 ( V_7 ) ;
if ( F_16 ( ! V_299 ) ) {
struct V_162 * V_310 = & V_7 -> V_168 [ V_12 * V_7 -> V_62 ] ;
while ( V_13 < V_303 && F_91 ( V_7 , & V_310 [ V_13 ] ) ) {
struct V_76 * V_306 = F_31 ( V_7 , V_12 , V_13 ) ;
F_174 ( V_306 ) ;
F_87 ( V_7 , & V_310 [ V_13 ] ) ;
V_13 ++ ;
V_302 += V_7 -> V_149 ;
V_18 += V_7 -> V_149 ;
}
while ( V_13 < V_303 && F_91 ( V_7 , & V_310 [ V_303 - 1 ] ) ) {
struct V_76 * V_306 = F_31 ( V_7 , V_12 , V_303 - 1 ) ;
F_174 ( V_306 ) ;
F_87 ( V_7 , & V_310 [ V_303 - 1 ] ) ;
V_303 -- ;
}
if ( V_13 == V_303 ) {
F_77 ( V_7 , & V_49 -> V_156 ) ;
F_104 ( & V_7 -> V_160 . V_161 ) ;
F_169 ( V_49 , V_7 -> V_296 ) ;
goto V_231;
}
for ( V_304 = V_13 ; V_304 < V_303 ; V_304 ++ ) {
F_87 ( V_7 , & V_310 [ V_304 ] ) ;
}
}
F_104 ( & V_7 -> V_160 . V_161 ) ;
V_177 = F_15 ( V_7 , V_17 , V_18 , & V_21 ) ;
for ( V_304 = V_13 ; V_304 < V_303 ; V_304 ++ ) {
int V_86 ;
struct V_76 * V_306 = F_31 ( V_7 , V_12 , V_304 ) ;
if (
#ifndef V_60
F_20 ( V_299 ) &&
#endif
V_7 -> V_218 ) {
char V_311 [ F_150 ( F_37 ( V_7 -> V_218 ) , V_7 -> V_29 ) ] ;
F_126 ( V_7 , V_302 + ( ( V_304 - V_13 ) << V_7 -> V_20 -> V_82 ) ,
( char * ) F_32 ( V_7 , V_12 , V_304 ) , V_311 ) ;
if ( F_20 ( memcmp ( V_311 , F_151 ( V_7 , V_306 ) , V_7 -> V_29 ) ) )
F_6 ( V_7 , L_28 , - V_9 ) ;
}
F_174 ( V_306 ) ;
V_86 = F_92 ( V_7 , F_151 ( V_7 , V_306 ) , & V_177 , & V_21 ,
V_7 -> V_29 , V_185 ) ;
if ( F_20 ( V_86 ) ) {
F_6 ( V_7 , L_29 , V_86 ) ;
}
}
F_61 ( & V_99 . V_100 ) ;
F_72 ( V_7 , V_12 , V_13 << V_7 -> V_20 -> V_82 ,
( V_303 - V_13 ) << V_7 -> V_20 -> V_82 ,
F_18 ( V_7 , V_17 , V_18 ) ,
F_168 , V_49 ) ;
V_231:
V_13 = V_305 ;
}
}
F_175 ( V_7 -> V_183 ) ;
F_176 ( & V_301 ) ;
F_40 ( & V_99 ) ;
F_70 ( & V_99 . V_99 ) ;
F_98 ( V_7 ) ;
}
static void F_177 ( struct V_220 * V_221 )
{
struct V_6 * V_7 = F_74 ( V_221 , struct V_6 , V_294 ) ;
unsigned V_297 , V_298 ;
unsigned V_312 ;
if ( F_11 ( V_7 -> V_313 ) )
return;
F_106 ( & V_7 -> V_160 . V_161 ) ;
V_297 = V_7 -> V_174 ;
V_298 = V_7 -> V_175 ;
F_104 ( & V_7 -> V_160 . V_161 ) ;
if ( ! V_298 )
return;
F_171 ( V_7 , V_297 , V_298 , false ) ;
F_106 ( & V_7 -> V_160 . V_161 ) ;
V_7 -> V_174 += V_298 ;
F_19 ( V_7 , & V_7 -> V_174 ) ;
V_7 -> V_175 -= V_298 ;
V_312 = V_7 -> V_270 ;
V_7 -> V_270 += V_298 * V_7 -> V_62 ;
if ( F_20 ( ! V_312 ) )
F_79 ( & V_7 -> V_160 ) ;
F_104 ( & V_7 -> V_160 . V_161 ) ;
}
static void F_178 ( struct V_6 * V_7 , unsigned V_314 ,
unsigned V_102 , unsigned char V_292 )
{
unsigned V_12 , V_13 , V_77 ;
if ( ! V_102 )
return;
for ( V_77 = 0 ; V_77 < V_102 ; V_77 ++ ) {
V_12 = V_314 + V_77 ;
F_19 ( V_7 , & V_12 ) ;
for ( V_13 = 0 ; V_13 < V_7 -> V_63 ; V_13 ++ ) {
struct V_69 * V_79 = F_30 ( V_7 , V_12 , V_13 ) ;
memset ( & V_79 -> V_315 , 0 , V_262 ) ;
V_79 -> V_269 = F_12 ( V_7 , V_12 , V_13 , V_292 ) ;
}
for ( V_13 = 0 ; V_13 < V_7 -> V_62 ; V_13 ++ ) {
struct V_76 * V_91 = F_31 ( V_7 , V_12 , V_13 ) ;
F_174 ( V_91 ) ;
}
}
F_67 ( V_7 , V_314 , V_102 ) ;
}
static int F_179 ( struct V_6 * V_7 , unsigned V_12 , unsigned V_13 , T_4 V_316 )
{
unsigned char V_303 ;
for ( V_303 = 0 ; V_303 < V_2 ; V_303 ++ ) {
if ( F_12 ( V_7 , V_12 , V_13 , V_303 ) == V_316 )
return V_303 ;
}
F_6 ( V_7 , L_30 , - V_135 ) ;
return - V_135 ;
}
static void F_180 ( struct V_6 * V_7 )
{
unsigned V_12 , V_13 ;
bool V_317 [ V_2 ] ;
unsigned V_318 [ V_2 ] ;
unsigned V_297 , V_298 ;
unsigned V_319 ;
bool V_320 ;
unsigned char V_321 , V_322 , V_323 ;
if ( V_7 -> V_230 == 'R' )
return;
if ( V_7 -> V_324 )
return;
V_322 = 0 ;
V_297 = 0 ;
if ( ! V_7 -> V_325 ) {
F_181 ( L_31 ) ;
F_65 ( V_7 , V_137 , 0 , 0 , V_7 -> V_33 , NULL ) ;
if ( V_7 -> V_109 )
F_182 ( F_29 ( V_7 -> V_109 [ 0 ] . V_74 ) , 64 , L_32 ) ;
if ( V_7 -> V_109 ) {
struct V_98 V_326 ;
V_326 . V_7 = V_7 ;
F_68 ( & V_326 . V_99 ) ;
V_326 . V_100 = ( V_143 ) F_69 ( 0 ) ;
F_63 ( V_7 , false , 0 , V_7 -> V_33 , & V_326 ) ;
F_57 ( & V_326 . V_99 ) ;
}
F_182 ( F_29 ( V_7 -> V_75 [ 0 ] . V_74 ) , 64 , L_33 ) ;
}
if ( F_10 ( V_7 ) )
goto V_327;
V_320 = true ;
memset ( V_317 , 0 , sizeof V_317 ) ;
memset ( V_318 , 0 , sizeof V_318 ) ;
for ( V_12 = 0 ; V_12 < V_7 -> V_33 ; V_12 ++ ) {
for ( V_13 = 0 ; V_13 < V_7 -> V_63 ; V_13 ++ ) {
int V_303 ;
struct V_69 * V_79 = F_30 ( V_7 , V_12 , V_13 ) ;
V_303 = F_179 ( V_7 , V_12 , V_13 , V_79 -> V_269 ) ;
if ( V_303 < 0 )
goto V_327;
V_317 [ V_303 ] = true ;
V_318 [ V_303 ] = V_12 ;
}
if ( V_320 ) {
for ( V_13 = 0 ; V_13 < V_7 -> V_62 ; V_13 ++ ) {
struct V_76 * V_91 = F_31 ( V_7 , V_12 , V_13 ) ;
if ( ! F_158 ( V_91 ) ) {
V_320 = false ;
break;
}
}
}
}
if ( ! V_317 [ V_2 - 1 ] ) {
V_321 = V_2 - 1 ;
while ( V_321 && ! V_317 [ V_321 - 1 ] )
V_321 -- ;
} else {
for ( V_321 = 0 ; V_321 < V_2 ; V_321 ++ )
if ( ! V_317 [ V_321 ] )
break;
if ( V_321 == V_2 ) {
F_6 ( V_7 , L_34 , - V_135 ) ;
goto V_327;
}
}
F_181 ( L_35 ,
V_321 , V_317 [ 0 ] , V_317 [ 1 ] ,
V_317 [ 2 ] , V_317 [ 3 ] ) ;
V_322 = F_1 ( V_321 ) ;
V_323 = F_1 ( V_322 ) ;
if ( ! V_317 [ V_323 ] && V_317 [ F_1 ( V_323 ) ] )
V_320 = true ;
V_297 = V_318 [ V_322 ] + 1 ;
if ( F_20 ( V_297 >= V_7 -> V_33 ) )
V_323 = F_2 ( V_323 ) ;
F_19 ( V_7 , & V_297 ) ;
V_12 = V_297 ;
for ( V_298 = 0 ; V_298 < V_7 -> V_33 ; V_298 ++ ) {
for ( V_13 = 0 ; V_13 < V_7 -> V_63 ; V_13 ++ ) {
struct V_69 * V_79 = F_30 ( V_7 , V_12 , V_13 ) ;
if ( V_79 -> V_269 != F_12 ( V_7 , V_12 , V_13 , V_323 ) ) {
F_181 ( L_36 ,
V_12 , V_13 , F_179 ( V_7 , V_12 , V_13 , V_79 -> V_269 ) , V_323 ) ;
goto V_328;
}
}
V_12 ++ ;
if ( F_20 ( V_12 >= V_7 -> V_33 ) )
V_323 = F_2 ( V_323 ) ;
F_19 ( V_7 , & V_12 ) ;
}
V_328:
if ( ! V_320 ) {
F_181 ( L_37 ,
V_298 , V_297 , V_323 ) ;
F_171 ( V_7 , V_297 , V_298 , true ) ;
}
if ( V_298 == V_7 -> V_33 && ( V_7 -> V_230 == 'J' || V_320 ) ) {
V_319 = V_297 ;
V_7 -> V_292 = V_323 ;
F_181 ( L_38 , V_297 , V_7 -> V_292 ) ;
} else {
unsigned V_260 ;
unsigned char V_329 ;
V_327:
F_181 ( L_39 ) ;
V_329 = F_1 ( F_1 ( V_322 ) ) ;
V_260 = V_297 ;
F_178 ( V_7 , V_260 , 1 , V_329 ) ;
V_260 ++ ;
F_19 ( V_7 , & V_260 ) ;
if ( V_7 -> V_33 >= 2 ) {
F_178 ( V_7 , V_260 , V_7 -> V_33 - 2 , V_329 ) ;
V_260 += V_7 -> V_33 - 2 ;
F_19 ( V_7 , & V_260 ) ;
F_178 ( V_7 , V_260 , 1 , V_329 ) ;
}
V_319 = 0 ;
V_7 -> V_292 = F_2 ( V_329 ) ;
}
V_7 -> V_174 = V_319 ;
V_7 -> V_175 = 0 ;
V_7 -> V_291 = V_319 ;
V_7 -> V_286 = 0 ;
V_7 -> V_284 = V_319 ;
V_7 -> V_285 = 0 ;
V_7 -> V_270 = V_7 -> V_172 ;
V_7 -> V_164 = V_330 ;
for ( V_12 = 0 ; V_12 < V_7 -> V_172 ; V_12 ++ )
F_83 ( & V_7 -> V_168 [ V_12 ] ) ;
}
static void F_183 ( struct V_246 * V_247 )
{
struct V_6 * V_7 = (struct V_6 * ) V_247 -> V_248 ;
F_184 ( & V_7 -> V_191 ) ;
V_7 -> V_313 = true ;
F_109 ( V_7 -> V_189 , & V_7 -> V_190 ) ;
F_185 ( V_7 -> V_189 ) ;
if ( V_7 -> V_230 == 'J' ) {
F_185 ( V_7 -> V_293 ) ;
F_98 ( V_7 ) ;
}
V_7 -> V_313 = false ;
F_41 ( ! F_186 ( & V_7 -> V_153 ) ) ;
V_7 -> V_324 = true ;
}
static void F_187 ( struct V_246 * V_247 )
{
struct V_6 * V_7 = (struct V_6 * ) V_247 -> V_248 ;
F_180 ( V_7 ) ;
}
static void F_188 ( struct V_246 * V_247 , T_7 type ,
unsigned V_331 , char * V_30 , unsigned V_332 )
{
struct V_6 * V_7 = (struct V_6 * ) V_247 -> V_248 ;
unsigned V_333 ;
T_2 V_334 = 0 ;
switch ( type ) {
case V_335 :
F_189 ( L_40 , ( unsigned long long ) F_190 ( & V_7 -> V_10 ) ) ;
break;
case V_336 : {
V_15 V_337 = ( V_15 ) ( V_7 -> V_172 - V_7 -> V_271 ) * 100 ;
V_337 += V_7 -> V_172 / 2 ;
F_191 ( V_337 , V_7 -> V_172 ) ;
V_333 = 5 ;
V_333 += V_7 -> V_149 != 1 ;
V_333 += ! ! V_7 -> V_338 . V_339 ;
V_333 += ! ! V_7 -> V_340 . V_339 ;
V_333 += ! ! V_7 -> V_341 . V_339 ;
F_189 ( L_41 , V_7 -> V_51 -> V_342 , ( unsigned long long ) V_7 -> V_53 ,
V_7 -> V_29 , V_7 -> V_230 , V_333 ) ;
F_189 ( L_42 , V_7 -> V_31 - V_55 ) ;
F_189 ( L_43 , 1U << V_7 -> V_20 -> V_19 ) ;
F_189 ( L_44 , 1U << V_7 -> V_26 ) ;
F_189 ( L_45 , ( unsigned ) V_337 ) ;
F_189 ( L_46 , V_7 -> V_343 ) ;
if ( V_7 -> V_149 != 1 )
F_189 ( L_47 , V_7 -> V_149 << V_28 ) ;
#define F_192 ( T_8 , V_77 ) \
do { \
if (ic->a.alg_string) { \
DMEMIT(" %s:%s", n, ic->a.alg_string); \
if (ic->a.key_string) \
DMEMIT(":%s", ic->a.key_string);\
} \
} while (0)
F_192 ( V_338 , L_48 ) ;
F_192 ( V_340 , L_49 ) ;
F_192 ( V_341 , L_50 ) ;
break;
}
}
}
static int F_193 ( struct V_246 * V_247 ,
T_9 V_47 , void * V_118 )
{
struct V_6 * V_7 = V_247 -> V_248 ;
return V_47 ( V_247 , V_7 -> V_51 , V_7 -> V_53 + V_7 -> V_31 + V_7 -> V_25 , V_247 -> V_4 , V_118 ) ;
}
static void F_194 ( struct V_246 * V_247 , struct V_344 * V_345 )
{
struct V_6 * V_7 = V_247 -> V_248 ;
if ( V_7 -> V_149 > 1 ) {
V_345 -> V_346 = V_7 -> V_149 << V_28 ;
V_345 -> V_347 = V_7 -> V_149 << V_28 ;
F_195 ( V_345 , V_7 -> V_149 << V_28 ) ;
}
}
static void F_196 ( struct V_6 * V_7 )
{
unsigned V_348 = V_262 ;
V_7 -> V_33 = F_197 ( V_7 -> V_20 -> V_33 ) ;
V_7 -> V_81 = F_47 ( F_198 ( struct V_76 , V_263 [ V_7 -> V_149 ] ) + V_7 -> V_29 ,
V_349 ) ;
if ( V_7 -> V_20 -> V_89 & F_199 ( V_350 ) )
V_348 -= V_96 ;
V_7 -> V_351 = V_348 / V_7 -> V_81 ;
V_7 -> V_62 = V_7 -> V_351 * V_80 ;
V_7 -> V_63 = ( V_7 -> V_62 << V_7 -> V_20 -> V_82 ) + V_80 ;
V_7 -> V_172 = V_7 -> V_62 * V_7 -> V_33 ;
}
static int F_200 ( struct V_6 * V_7 )
{
V_15 V_31 ;
T_5 V_352 , V_353 , V_354 ;
F_196 ( V_7 ) ;
V_31 = V_55 + ( V_15 ) V_7 -> V_63 * V_7 -> V_33 ;
if ( V_31 + V_355 >= V_7 -> V_356 || V_31 > V_357 )
return - V_358 ;
V_7 -> V_31 = V_31 ;
V_7 -> V_25 = F_47 ( ( V_15 ) V_7 -> V_29 << ( V_7 -> V_20 -> V_19 - V_7 -> V_20 -> V_82 ) ,
( V_15 ) ( 1 << V_28 << V_355 ) ) >> V_28 ;
if ( ! ( V_7 -> V_25 & ( V_7 -> V_25 - 1 ) ) )
V_7 -> V_24 = F_201 ( V_7 -> V_25 ) ;
else
V_7 -> V_24 = - 1 ;
F_14 ( V_7 , V_7 -> V_252 - 1 , & V_353 , & V_354 ) ;
V_352 = F_18 ( V_7 , V_353 , V_354 ) ;
if ( V_7 -> V_53 + V_352 < V_352 || V_7 -> V_53 + V_352 >= V_7 -> V_356 )
return - V_358 ;
return 0 ;
}
static int F_202 ( struct V_6 * V_7 , unsigned V_359 , unsigned V_360 )
{
unsigned V_33 ;
int V_361 ;
memset ( V_7 -> V_20 , 0 , V_55 << V_28 ) ;
memcpy ( V_7 -> V_20 -> V_362 , V_363 , 8 ) ;
V_7 -> V_20 -> V_364 = V_365 ;
V_7 -> V_20 -> V_366 = F_203 ( V_7 -> V_29 ) ;
V_7 -> V_20 -> V_82 = F_201 ( V_7 -> V_149 ) ;
if ( V_7 -> V_341 . V_339 )
V_7 -> V_20 -> V_89 |= F_199 ( V_350 ) ;
F_196 ( V_7 ) ;
V_33 = V_359 / V_7 -> V_63 ;
if ( ! V_33 )
V_33 = 1 ;
V_7 -> V_20 -> V_33 = F_199 ( V_33 ) ;
if ( ! V_360 )
V_360 = V_367 ;
V_7 -> V_20 -> V_19 = F_204 ( V_360 ) ;
V_7 -> V_20 -> V_19 = F_150 ( ( T_1 ) V_368 , V_7 -> V_20 -> V_19 ) ;
V_7 -> V_20 -> V_19 = F_49 ( ( T_1 ) V_369 , V_7 -> V_20 -> V_19 ) ;
V_7 -> V_252 = 0 ;
for ( V_361 = F_205 ( V_7 -> V_356 ) - 1 ; V_361 >= 3 ; V_361 -- ) {
V_15 V_370 = V_7 -> V_252 ;
V_7 -> V_252 |= ( T_5 ) 1 << V_361 ;
if ( F_200 ( V_7 ) )
V_7 -> V_252 = V_370 ;
}
if ( ! V_7 -> V_252 )
return - V_358 ;
V_7 -> V_20 -> V_252 = F_13 ( V_7 -> V_252 ) ;
return 0 ;
}
static void F_206 ( struct V_246 * V_247 , struct V_6 * V_7 )
{
struct V_371 * V_372 = F_207 ( F_208 ( V_247 -> V_373 ) ) ;
struct V_374 V_375 ;
memset ( & V_375 , 0 , sizeof( V_375 ) ) ;
V_375 . V_376 = & V_377 ;
V_375 . V_378 = V_7 -> V_29 ;
V_375 . V_29 = V_375 . V_378 ;
V_375 . V_379 = V_7 -> V_20 -> V_82 + V_28 ;
F_209 ( V_372 , & V_375 ) ;
F_210 ( V_372 -> V_380 , V_357 ) ;
}
static void F_211 ( struct V_6 * V_7 , struct V_70 * V_71 )
{
unsigned V_12 ;
if ( ! V_71 )
return;
for ( V_12 = 0 ; V_12 < V_7 -> V_381 ; V_12 ++ )
if ( V_71 [ V_12 ] . V_74 )
F_212 ( V_71 [ V_12 ] . V_74 ) ;
F_213 ( V_71 ) ;
}
static struct V_70 * F_214 ( struct V_6 * V_7 )
{
T_2 V_382 = V_7 -> V_381 * sizeof( struct V_70 ) ;
struct V_70 * V_71 ;
unsigned V_12 ;
V_71 = F_215 ( V_382 , V_383 | V_384 ) ;
if ( ! V_71 )
return NULL ;
for ( V_12 = 0 ; V_12 < V_7 -> V_381 ; V_12 ++ ) {
V_71 [ V_12 ] . V_74 = F_216 ( V_383 ) ;
if ( ! V_71 [ V_12 ] . V_74 ) {
F_211 ( V_7 , V_71 ) ;
return NULL ;
}
if ( V_12 )
V_71 [ V_12 - 1 ] . V_171 = & V_71 [ V_12 ] ;
}
return V_71 ;
}
static void F_217 ( struct V_6 * V_7 , struct V_124 * * V_385 )
{
unsigned V_12 ;
for ( V_12 = 0 ; V_12 < V_7 -> V_33 ; V_12 ++ )
F_213 ( V_385 [ V_12 ] ) ;
F_133 ( V_385 ) ;
}
static struct V_124 * * F_218 ( struct V_6 * V_7 , struct V_70 * V_71 )
{
struct V_124 * * V_385 ;
unsigned V_12 ;
V_385 = F_215 ( V_7 -> V_33 * sizeof( struct V_124 * ) , V_383 | V_384 ) ;
if ( ! V_385 )
return NULL ;
for ( V_12 = 0 ; V_12 < V_7 -> V_33 ; V_12 ++ ) {
struct V_124 * V_260 ;
unsigned V_386 , V_387 ;
unsigned V_388 , V_389 ;
unsigned V_390 ;
unsigned V_391 ;
F_27 ( V_7 , V_12 , 0 , & V_386 , & V_387 ) ;
F_27 ( V_7 , V_12 , V_7 -> V_63 - 1 , & V_388 , & V_389 ) ;
V_390 = ( V_388 - V_386 + 1 ) ;
V_260 = F_215 ( V_390 * sizeof( struct V_124 ) , V_383 ) ;
if ( ! V_260 ) {
F_217 ( V_7 , V_385 ) ;
return NULL ;
}
F_219 ( V_260 , V_390 ) ;
for ( V_391 = V_386 ; V_391 <= V_388 ; V_391 ++ ) {
char * V_73 = F_29 ( V_71 [ V_391 ] . V_74 ) ;
unsigned V_53 = 0 , V_392 = V_68 ;
if ( V_391 == V_386 )
V_53 = V_387 ;
if ( V_391 == V_388 )
V_392 = V_389 + ( 1 << V_28 ) ;
F_220 ( & V_260 [ V_391 - V_386 ] , V_73 + V_53 , V_392 - V_53 ) ;
}
V_385 [ V_12 ] = V_260 ;
}
return V_385 ;
}
static void F_221 ( struct V_393 * T_8 )
{
F_222 ( T_8 -> V_339 ) ;
F_222 ( T_8 -> V_394 ) ;
memset ( T_8 , 0 , sizeof *T_8 ) ;
}
static int F_223 ( const char * V_395 , struct V_393 * T_8 , char * * error , char * V_396 )
{
char * V_303 ;
F_221 ( T_8 ) ;
T_8 -> V_339 = F_224 ( strchr ( V_395 , ':' ) + 1 , V_383 ) ;
if ( ! T_8 -> V_339 )
goto V_397;
V_303 = strchr ( T_8 -> V_339 , ':' ) ;
if ( V_303 ) {
* V_303 = 0 ;
T_8 -> V_398 = V_303 + 1 ;
if ( strlen ( T_8 -> V_398 ) & 1 )
goto V_399;
T_8 -> V_400 = strlen ( T_8 -> V_398 ) / 2 ;
T_8 -> V_394 = F_129 ( T_8 -> V_400 , V_383 ) ;
if ( ! T_8 -> V_394 )
goto V_397;
if ( F_225 ( T_8 -> V_394 , T_8 -> V_398 , T_8 -> V_400 ) )
goto V_399;
}
return 0 ;
V_399:
* error = V_396 ;
return - V_358 ;
V_397:
* error = L_51 ;
return - V_401 ;
}
static int F_226 ( struct V_402 * * V_403 , struct V_393 * T_8 , char * * error ,
char * V_404 , char * V_405 )
{
int V_86 ;
if ( T_8 -> V_339 ) {
* V_403 = F_227 ( T_8 -> V_339 , 0 , V_406 ) ;
if ( F_94 ( * V_403 ) ) {
* error = V_404 ;
V_86 = F_95 ( * V_403 ) ;
* V_403 = NULL ;
return V_86 ;
}
if ( T_8 -> V_394 ) {
V_86 = F_228 ( * V_403 , T_8 -> V_394 , T_8 -> V_400 ) ;
if ( V_86 ) {
* error = V_405 ;
return V_86 ;
}
}
}
return 0 ;
}
static int F_229 ( struct V_6 * V_7 , char * * error )
{
int V_86 = 0 ;
unsigned V_12 ;
V_15 V_381 , V_407 , V_408 ;
unsigned char * V_409 = NULL ;
V_7 -> V_14 [ 0 ] = F_13 ( 0x1111111111111111ULL ) ;
V_7 -> V_14 [ 1 ] = F_13 ( 0x2222222222222222ULL ) ;
V_7 -> V_14 [ 2 ] = F_13 ( 0x3333333333333333ULL ) ;
V_7 -> V_14 [ 3 ] = F_13 ( 0x4444444444444444ULL ) ;
V_381 = F_47 ( ( V_15 ) V_7 -> V_33 * V_7 -> V_63 ,
V_68 >> V_28 ) >> ( V_67 - V_28 ) ;
V_407 = V_381 * sizeof( struct V_70 ) ;
if ( V_381 >= V_410 - V_411 || V_407 > V_412 ) {
* error = L_52 ;
V_86 = - V_401 ;
goto V_413;
}
V_7 -> V_381 = V_381 ;
V_7 -> V_75 = F_214 ( V_7 ) ;
if ( ! V_7 -> V_75 ) {
* error = L_53 ;
V_86 = - V_401 ;
goto V_413;
}
if ( V_7 -> V_340 . V_339 ) {
unsigned V_129 , V_414 ;
struct V_98 V_99 ;
V_99 . V_7 = V_7 ;
V_7 -> V_132 = F_230 ( V_7 -> V_340 . V_339 , 0 , 0 ) ;
if ( F_94 ( V_7 -> V_132 ) ) {
* error = L_54 ;
V_86 = F_95 ( V_7 -> V_132 ) ;
V_7 -> V_132 = NULL ;
goto V_413;
}
V_129 = F_60 ( V_7 -> V_132 ) ;
V_414 = F_231 ( V_7 -> V_132 ) ;
if ( V_7 -> V_340 . V_394 ) {
V_86 = F_232 ( V_7 -> V_132 , V_7 -> V_340 . V_394 ,
V_7 -> V_340 . V_400 ) ;
if ( V_86 ) {
* error = L_55 ;
goto V_413;
}
}
F_181 ( L_56 ,
V_7 -> V_340 . V_339 , V_414 , V_129 ) ;
V_7 -> V_109 = F_214 ( V_7 ) ;
if ( ! V_7 -> V_109 ) {
* error = L_57 ;
V_86 = - V_401 ;
goto V_413;
}
if ( V_414 == 1 ) {
struct V_124 * V_415 ;
F_233 ( V_117 , V_7 -> V_132 ) ;
unsigned char V_130 [ V_129 ] ;
F_234 ( V_117 , V_7 -> V_132 ) ;
V_7 -> V_115 = F_214 ( V_7 ) ;
if ( ! V_7 -> V_115 ) {
* error = L_58 ;
V_86 = - V_401 ;
goto V_413;
}
V_415 = F_215 ( ( V_7 -> V_381 + 1 ) * sizeof( struct V_124 ) , V_383 ) ;
if ( ! V_415 ) {
* error = L_59 ;
V_86 = - V_401 ;
goto V_413;
}
F_219 ( V_415 , V_7 -> V_381 + 1 ) ;
for ( V_12 = 0 ; V_12 < V_7 -> V_381 ; V_12 ++ ) {
char * V_73 = F_29 ( V_7 -> V_115 [ V_12 ] . V_74 ) ;
F_235 ( V_73 ) ;
F_220 ( & V_415 [ V_12 ] , V_73 , V_68 ) ;
}
F_220 ( & V_415 [ V_12 ] , & V_7 -> V_14 , sizeof V_7 -> V_14 ) ;
memset ( V_130 , 0x00 , V_129 ) ;
F_236 ( V_117 , V_415 , V_415 , V_68 * V_7 -> V_381 + sizeof V_7 -> V_14 , V_130 ) ;
F_68 ( & V_99 . V_99 ) ;
V_99 . V_100 = ( V_143 ) F_69 ( 1 ) ;
if ( F_53 ( true , V_117 , & V_99 ) )
F_57 ( & V_99 . V_99 ) ;
F_213 ( V_415 ) ;
V_86 = F_10 ( V_7 ) ;
if ( V_86 ) {
* error = L_60 ;
goto V_413;
}
F_182 ( F_29 ( V_7 -> V_115 [ 0 ] . V_74 ) , 64 , L_61 ) ;
F_237 ( V_7 -> V_132 ) ;
V_7 -> V_132 = NULL ;
} else {
F_233 ( V_117 , V_7 -> V_132 ) ;
unsigned char V_130 [ V_129 ] ;
unsigned V_416 = F_47 ( V_129 , V_414 ) ;
V_409 = F_129 ( V_416 , V_383 ) ;
if ( ! V_409 ) {
* error = L_62 ;
V_86 = - V_401 ;
goto V_413;
}
F_234 ( V_117 , V_7 -> V_132 ) ;
V_7 -> V_127 = F_218 ( V_7 , V_7 -> V_75 ) ;
if ( ! V_7 -> V_127 ) {
* error = L_59 ;
V_86 = - V_401 ;
goto V_413;
}
V_7 -> V_128 = F_218 ( V_7 , V_7 -> V_109 ) ;
if ( ! V_7 -> V_128 ) {
* error = L_59 ;
V_86 = - V_401 ;
goto V_413;
}
V_7 -> V_131 = F_215 ( V_7 -> V_33 * sizeof( struct V_121 * ) , V_383 | V_384 ) ;
if ( ! V_7 -> V_131 ) {
* error = L_63 ;
V_86 = - V_401 ;
goto V_413;
}
for ( V_12 = 0 ; V_12 < V_7 -> V_33 ; V_12 ++ ) {
struct V_124 V_415 ;
struct V_121 * V_417 ;
T_10 V_418 = F_199 ( V_12 ) ;
memset ( V_130 , 0x00 , V_129 ) ;
memset ( V_409 , 0x00 , V_416 ) ;
memcpy ( V_409 , & V_418 , F_49 ( ( T_2 ) V_416 , sizeof( V_418 ) ) ) ;
F_238 ( & V_415 , V_409 , V_416 ) ;
F_236 ( V_117 , & V_415 , & V_415 , V_416 , V_130 ) ;
F_68 ( & V_99 . V_99 ) ;
V_99 . V_100 = ( V_143 ) F_69 ( 1 ) ;
if ( F_53 ( true , V_117 , & V_99 ) )
F_57 ( & V_99 . V_99 ) ;
V_86 = F_10 ( V_7 ) ;
if ( V_86 ) {
* error = L_64 ;
goto V_413;
}
V_417 = F_239 ( V_7 -> V_132 , V_383 ) ;
if ( ! V_417 ) {
* error = L_65 ;
V_86 = - V_401 ;
goto V_413;
}
V_417 -> V_130 = F_129 ( V_129 * 2 , V_383 ) ;
if ( ! V_417 -> V_130 ) {
F_240 ( V_417 ) ;
* error = L_66 ;
V_86 = - V_401 ;
goto V_413;
}
memcpy ( V_417 -> V_130 + V_129 , V_409 , V_129 ) ;
V_417 -> V_419 = ( T_2 ) V_7 -> V_63 << V_28 ;
V_7 -> V_131 [ V_12 ] = V_417 ;
F_182 ( V_409 , V_129 , L_67 , V_12 ) ;
}
}
}
for ( V_12 = 0 ; V_12 < V_2 ; V_12 ++ ) {
unsigned V_13 ;
V_420:
for ( V_13 = 0 ; V_13 < V_12 ; V_13 ++ ) {
if ( V_7 -> V_14 [ V_13 ] == V_7 -> V_14 [ V_12 ] ) {
V_7 -> V_14 [ V_12 ] = F_13 ( F_241 ( V_7 -> V_14 [ V_12 ] ) + 1 ) ;
goto V_420;
}
}
F_181 ( L_68 , V_12 , V_7 -> V_14 [ V_12 ] ) ;
}
V_408 = ( V_15 ) V_7 -> V_172 * sizeof( struct V_162 ) ;
if ( V_408 > V_412 ) {
* error = L_52 ;
V_86 = - V_401 ;
goto V_413;
}
V_7 -> V_168 = F_215 ( V_408 , V_383 ) ;
if ( ! V_7 -> V_168 ) {
* error = L_69 ;
V_86 = - V_401 ;
}
V_413:
F_133 ( V_409 ) ;
return V_86 ;
}
static int F_242 ( struct V_246 * V_247 , unsigned V_421 , char * * V_422 )
{
struct V_6 * V_7 ;
char V_114 ;
int V_86 ;
unsigned V_423 ;
struct V_424 V_425 ;
static const struct V_426 V_427 [] = {
{ 0 , 9 , L_70 } ,
} ;
unsigned V_359 , V_360 , V_428 , V_429 , V_430 ;
bool V_431 ;
V_15 V_432 ;
unsigned long long V_53 ;
#define F_243 4
if ( V_421 <= F_243 ) {
V_247 -> error = L_71 ;
return - V_358 ;
}
V_7 = F_244 ( sizeof( struct V_6 ) , V_383 ) ;
if ( ! V_7 ) {
V_247 -> error = L_72 ;
return - V_401 ;
}
V_247 -> V_248 = V_7 ;
V_247 -> V_433 = sizeof( struct V_194 ) ;
V_7 -> V_153 = V_330 ;
F_245 ( & V_7 -> V_160 ) ;
F_246 ( & V_7 -> V_197 ) ;
F_245 ( & V_7 -> V_261 ) ;
F_68 ( & V_7 -> V_120 ) ;
F_247 ( & V_7 -> V_10 , 0 ) ;
V_86 = F_248 ( V_247 , V_422 [ 0 ] , F_249 ( V_247 -> V_373 ) , & V_7 -> V_51 ) ;
if ( V_86 ) {
V_247 -> error = L_73 ;
goto V_413;
}
if ( sscanf ( V_422 [ 1 ] , L_74 , & V_53 , & V_114 ) != 1 || V_53 != ( T_5 ) V_53 ) {
V_247 -> error = L_75 ;
V_86 = - V_358 ;
goto V_413;
}
V_7 -> V_53 = V_53 ;
if ( strcmp ( V_422 [ 2 ] , L_76 ) ) {
if ( sscanf ( V_422 [ 2 ] , L_77 , & V_7 -> V_29 , & V_114 ) != 1 || ! V_7 -> V_29 ) {
V_247 -> error = L_78 ;
V_86 = - V_358 ;
goto V_413;
}
}
if ( ! strcmp ( V_422 [ 3 ] , L_79 ) || ! strcmp ( V_422 [ 3 ] , L_80 ) || ! strcmp ( V_422 [ 3 ] , L_81 ) )
V_7 -> V_230 = V_422 [ 3 ] [ 0 ] ;
else {
V_247 -> error = L_82 ;
V_86 = - V_358 ;
goto V_413;
}
V_7 -> V_356 = F_250 ( V_7 -> V_51 -> V_50 -> V_434 ) >> V_28 ;
V_359 = F_49 ( ( T_5 ) V_435 ,
V_7 -> V_356 >> V_436 ) ;
V_360 = V_367 ;
V_428 = V_437 ;
V_429 = V_438 ;
V_430 = V_439 ;
V_7 -> V_149 = 1 ;
V_425 . V_421 = V_421 - F_243 ;
V_425 . V_422 = V_422 + F_243 ;
V_86 = F_251 ( V_427 , & V_425 , & V_423 , & V_247 -> error ) ;
if ( V_86 )
goto V_413;
while ( V_423 -- ) {
const char * V_440 ;
unsigned V_441 ;
V_440 = F_252 ( & V_425 ) ;
if ( ! V_440 ) {
V_86 = - V_358 ;
V_247 -> error = L_83 ;
goto V_413;
}
if ( sscanf ( V_440 , L_84 , & V_441 , & V_114 ) == 1 )
V_359 = V_441 ;
else if ( sscanf ( V_440 , L_85 , & V_441 , & V_114 ) == 1 )
V_360 = V_441 ;
else if ( sscanf ( V_440 , L_86 , & V_441 , & V_114 ) == 1 )
V_428 = V_441 ;
else if ( sscanf ( V_440 , L_87 , & V_441 , & V_114 ) == 1 && V_441 <= 100 )
V_429 = V_441 ;
else if ( sscanf ( V_440 , L_88 , & V_441 , & V_114 ) == 1 )
V_430 = V_441 ;
else if ( sscanf ( V_440 , L_89 , & V_441 , & V_114 ) == 1 ) {
if ( V_441 < 1 << V_28 ||
V_441 > V_442 << V_28 ||
( V_441 & ( V_441 - 1 ) ) ) {
V_86 = - V_358 ;
V_247 -> error = L_90 ;
goto V_413;
}
V_7 -> V_149 = V_441 >> V_28 ;
} else if ( ! memcmp ( V_440 , L_91 , strlen ( L_91 ) ) ) {
V_86 = F_223 ( V_440 , & V_7 -> V_338 , & V_247 -> error ,
L_92 ) ;
if ( V_86 )
goto V_413;
} else if ( ! memcmp ( V_440 , L_93 , strlen ( L_93 ) ) ) {
V_86 = F_223 ( V_440 , & V_7 -> V_340 , & V_247 -> error ,
L_94 ) ;
if ( V_86 )
goto V_413;
} else if ( ! memcmp ( V_440 , L_95 , strlen ( L_95 ) ) ) {
V_86 = F_223 ( V_440 , & V_7 -> V_341 , & V_247 -> error ,
L_96 ) ;
if ( V_86 )
goto V_413;
} else {
V_86 = - V_358 ;
V_247 -> error = L_97 ;
goto V_413;
}
}
V_86 = F_226 ( & V_7 -> V_218 , & V_7 -> V_338 , & V_247 -> error ,
L_98 , L_99 ) ;
if ( V_86 )
goto V_413;
V_86 = F_226 ( & V_7 -> V_85 , & V_7 -> V_341 , & V_247 -> error ,
L_100 , L_101 ) ;
if ( V_86 )
goto V_413;
if ( ! V_7 -> V_29 ) {
if ( ! V_7 -> V_218 ) {
V_247 -> error = L_102 ;
V_86 = - V_358 ;
goto V_413;
}
V_7 -> V_29 = F_37 ( V_7 -> V_218 ) ;
}
if ( V_7 -> V_29 > V_443 ) {
V_247 -> error = L_103 ;
V_86 = - V_358 ;
goto V_413;
}
if ( ! ( V_7 -> V_29 & ( V_7 -> V_29 - 1 ) ) )
V_7 -> V_27 = F_201 ( V_7 -> V_29 ) ;
else
V_7 -> V_27 = - 1 ;
V_7 -> V_193 = F_253 ( V_430 ) ;
V_7 -> V_343 = V_430 ;
F_254 ( & V_7 -> V_191 , F_108 , ( unsigned long ) V_7 ) ;
V_7 -> V_49 = F_255 () ;
if ( F_94 ( V_7 -> V_49 ) ) {
V_86 = F_95 ( V_7 -> V_49 ) ;
V_7 -> V_49 = NULL ;
V_247 -> error = L_104 ;
goto V_413;
}
V_7 -> V_296 = F_256 ( V_444 , V_445 ) ;
if ( ! V_7 -> V_296 ) {
V_86 = - V_401 ;
V_247 -> error = L_105 ;
goto V_413;
}
V_7 -> V_276 = F_257 ( L_106 ,
V_446 , V_447 ) ;
if ( ! V_7 -> V_276 ) {
V_247 -> error = L_107 ;
V_86 = - V_401 ;
goto V_413;
}
V_7 -> V_203 = F_257 ( L_108 , V_446 | V_448 , 1 ) ;
if ( ! V_7 -> V_203 ) {
V_247 -> error = L_107 ;
V_86 = - V_401 ;
goto V_413;
}
V_7 -> V_189 = F_257 ( L_109 , V_446 , 1 ) ;
if ( ! V_7 -> V_189 ) {
V_247 -> error = L_107 ;
V_86 = - V_401 ;
goto V_413;
}
F_123 ( & V_7 -> V_190 , F_164 ) ;
if ( V_7 -> V_230 == 'J' ) {
V_7 -> V_293 = F_257 ( L_110 , V_446 , 1 ) ;
if ( ! V_7 -> V_293 ) {
V_247 -> error = L_107 ;
V_86 = - V_401 ;
goto V_413;
}
F_123 ( & V_7 -> V_294 , F_177 ) ;
}
V_7 -> V_20 = F_258 ( V_55 << V_28 , V_383 ) ;
if ( ! V_7 -> V_20 ) {
V_86 = - V_401 ;
V_247 -> error = L_111 ;
goto V_413;
}
V_86 = F_21 ( V_7 , V_137 , 0 ) ;
if ( V_86 ) {
V_247 -> error = L_112 ;
goto V_413;
}
V_431 = false ;
if ( memcmp ( V_7 -> V_20 -> V_362 , V_363 , 8 ) ) {
if ( V_7 -> V_230 != 'R' ) {
if ( F_259 ( V_7 -> V_20 , 0 , V_55 << V_28 ) ) {
V_86 = - V_358 ;
V_247 -> error = L_113 ;
goto V_413;
}
}
V_86 = F_202 ( V_7 , V_359 , V_360 ) ;
if ( V_86 ) {
V_247 -> error = L_114 ;
goto V_413;
}
if ( V_7 -> V_230 != 'R' )
V_431 = true ;
}
if ( V_7 -> V_20 -> V_364 != V_365 ) {
V_86 = - V_358 ;
V_247 -> error = L_115 ;
goto V_413;
}
if ( F_260 ( V_7 -> V_20 -> V_366 ) != V_7 -> V_29 ) {
V_86 = - V_358 ;
V_247 -> error = L_116 ;
goto V_413;
}
if ( V_7 -> V_20 -> V_82 != F_201 ( V_7 -> V_149 ) ) {
V_86 = - V_358 ;
V_247 -> error = L_117 ;
goto V_413;
}
if ( ! F_197 ( V_7 -> V_20 -> V_33 ) ) {
V_86 = - V_358 ;
V_247 -> error = L_118 ;
goto V_413;
}
if ( V_7 -> V_20 -> V_19 < V_368 ||
V_7 -> V_20 -> V_19 > V_369 ) {
V_86 = - V_358 ;
V_247 -> error = L_119 ;
goto V_413;
}
V_7 -> V_252 = F_241 ( V_7 -> V_20 -> V_252 ) ;
if ( V_7 -> V_252 != F_241 ( V_7 -> V_20 -> V_252 ) ) {
V_86 = - V_358 ;
V_247 -> error = L_120 ;
goto V_413;
}
if ( ! ! ( V_7 -> V_20 -> V_89 & F_199 ( V_350 ) ) != ! ! V_7 -> V_341 . V_339 ) {
V_86 = - V_358 ;
V_247 -> error = L_121 ;
goto V_413;
}
V_86 = F_200 ( V_7 ) ;
if ( V_86 ) {
V_247 -> error = L_122 ;
goto V_413;
}
if ( V_247 -> V_4 > V_7 -> V_252 ) {
V_86 = - V_358 ;
V_247 -> error = L_123 ;
goto V_413;
}
if ( ! V_428 )
V_428 = 1 ;
V_7 -> V_26 = F_261 ( ( int ) F_204 ( V_428 ) , ( int ) F_201 ( V_7 -> V_25 ) , 31 - V_28 ) ;
V_432 = ( V_15 ) V_7 -> V_172 * ( 100 - V_429 ) ;
V_432 += 50 ;
F_191 ( V_432 , 100 ) ;
V_7 -> V_271 = V_432 ;
F_181 ( L_124 ) ;
F_181 ( L_125 , F_260 ( V_7 -> V_20 -> V_366 ) ) ;
F_181 ( L_126 , V_7 -> V_81 ) ;
F_181 ( L_127 , V_7 -> V_351 ) ;
F_181 ( L_128 , V_7 -> V_62 ) ;
F_181 ( L_129 , V_7 -> V_63 ) ;
F_181 ( L_130 , ( unsigned ) F_197 ( V_7 -> V_20 -> V_33 ) ) ;
F_181 ( L_131 , V_7 -> V_172 ) ;
F_181 ( L_132 , V_7 -> V_20 -> V_19 ) ;
F_181 ( L_133 , ( unsigned long long ) V_7 -> V_356 ) ;
F_181 ( L_134 , V_7 -> V_31 ) ;
F_181 ( L_135 , V_7 -> V_25 ) ;
F_181 ( L_136 , V_7 -> V_24 ) ;
F_181 ( L_137 , ( unsigned long long ) V_7 -> V_252 ,
( unsigned long long ) V_7 -> V_252 ) ;
F_181 ( L_138 , V_7 -> V_26 ) ;
V_7 -> V_183 = F_262 ( V_7 -> V_51 -> V_50 , 1U << ( V_28 + V_7 -> V_26 ) ,
1 , 0 , NULL , NULL ) ;
if ( F_94 ( V_7 -> V_183 ) ) {
V_86 = F_95 ( V_7 -> V_183 ) ;
V_247 -> error = L_139 ;
V_7 -> V_183 = NULL ;
goto V_413;
}
F_263 ( V_7 -> V_183 , V_7 -> V_53 + V_7 -> V_31 ) ;
if ( V_7 -> V_230 != 'R' ) {
V_86 = F_229 ( V_7 , & V_247 -> error ) ;
if ( V_86 )
goto V_413;
}
if ( V_431 ) {
int V_86 ;
F_178 ( V_7 , 0 , V_7 -> V_33 , 0 ) ;
V_86 = F_10 ( V_7 ) ;
if ( F_20 ( V_86 ) ) {
V_247 -> error = L_140 ;
goto V_413;
}
V_86 = F_21 ( V_7 , V_144 , V_145 ) ;
if ( V_86 ) {
V_247 -> error = L_141 ;
goto V_413;
}
V_7 -> V_325 = true ;
}
V_86 = F_264 ( V_247 , 1U << V_7 -> V_20 -> V_19 ) ;
if ( V_86 )
goto V_413;
if ( ! V_7 -> V_218 )
F_206 ( V_247 , V_7 ) ;
V_247 -> V_449 = 1 ;
V_247 -> V_450 = true ;
return 0 ;
V_413:
F_265 ( V_247 ) ;
return V_86 ;
}
static void F_265 ( struct V_246 * V_247 )
{
struct V_6 * V_7 = V_247 -> V_248 ;
F_41 ( ! F_186 ( & V_7 -> V_153 ) ) ;
if ( V_7 -> V_276 )
F_266 ( V_7 -> V_276 ) ;
if ( V_7 -> V_203 )
F_266 ( V_7 -> V_203 ) ;
if ( V_7 -> V_189 )
F_266 ( V_7 -> V_189 ) ;
if ( V_7 -> V_293 )
F_266 ( V_7 -> V_293 ) ;
if ( V_7 -> V_183 )
F_267 ( V_7 -> V_183 ) ;
F_268 ( V_7 -> V_296 ) ;
if ( V_7 -> V_49 )
F_269 ( V_7 -> V_49 ) ;
if ( V_7 -> V_51 )
F_270 ( V_247 , V_7 -> V_51 ) ;
F_211 ( V_7 , V_7 -> V_75 ) ;
F_211 ( V_7 , V_7 -> V_109 ) ;
F_211 ( V_7 , V_7 -> V_115 ) ;
if ( V_7 -> V_127 )
F_217 ( V_7 , V_7 -> V_127 ) ;
if ( V_7 -> V_128 )
F_217 ( V_7 , V_7 -> V_128 ) ;
if ( V_7 -> V_131 ) {
unsigned V_12 ;
for ( V_12 = 0 ; V_12 < V_7 -> V_33 ; V_12 ++ ) {
struct V_121 * V_117 = V_7 -> V_131 [ V_12 ] ;
if ( V_117 ) {
F_222 ( V_117 -> V_130 ) ;
F_240 ( V_117 ) ;
}
}
F_213 ( V_7 -> V_131 ) ;
}
F_213 ( V_7 -> V_168 ) ;
if ( V_7 -> V_20 )
F_271 ( V_7 -> V_20 , V_55 << V_28 ) ;
if ( V_7 -> V_218 )
F_272 ( V_7 -> V_218 ) ;
F_221 ( & V_7 -> V_338 ) ;
if ( V_7 -> V_132 )
F_237 ( V_7 -> V_132 ) ;
F_221 ( & V_7 -> V_340 ) ;
if ( V_7 -> V_85 )
F_272 ( V_7 -> V_85 ) ;
F_221 ( & V_7 -> V_341 ) ;
F_133 ( V_7 ) ;
}
int T_11 F_273 ( void )
{
int V_86 ;
V_445 = F_274 ( L_142 ,
sizeof( struct V_109 ) , 0 , 0 , NULL ) ;
if ( ! V_445 ) {
F_9 ( L_143 ) ;
return - V_401 ;
}
V_86 = F_275 ( & V_451 ) ;
if ( V_86 < 0 )
F_9 ( L_144 , V_86 ) ;
return V_86 ;
}
void F_276 ( void )
{
F_277 ( & V_451 ) ;
F_278 ( V_445 ) ;
}
