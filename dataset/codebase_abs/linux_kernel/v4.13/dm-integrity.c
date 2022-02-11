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
if ( ! F_7 ( & V_7 -> V_9 , 0 , V_8 ) )
F_8 ( L_4 , V_5 , V_8 ) ;
}
static int F_9 ( struct V_6 * V_7 )
{
return F_10 ( V_7 -> V_9 ) ;
}
static T_4 F_11 ( struct V_6 * V_7 , unsigned V_10 ,
unsigned V_11 , unsigned char V_1 )
{
return V_7 -> V_12 [ V_1 ] ^ F_12 ( ( ( V_13 ) V_10 << 32 ) ^ V_11 ) ;
}
static void F_13 ( struct V_6 * V_7 , T_5 V_14 ,
T_5 * V_15 , T_5 * V_16 )
{
T_1 V_17 = V_7 -> V_18 -> V_17 ;
* V_15 = V_14 >> V_17 ;
* V_16 = ( unsigned ) V_14 & ( ( 1U << V_17 ) - 1 ) ;
}
static V_13 F_14 ( struct V_6 * V_7 , T_5 V_15 ,
T_5 V_16 , unsigned * V_19 )
{
V_13 V_20 ;
unsigned V_21 ;
V_20 = V_15 << V_7 -> V_18 -> V_17 ;
if ( F_15 ( V_7 -> V_22 >= 0 ) )
V_20 += V_15 << V_7 -> V_22 ;
else
V_20 += V_15 * V_7 -> V_23 ;
V_20 >>= V_7 -> V_24 ;
F_16 ( V_7 , V_16 ) ;
if ( F_15 ( V_7 -> V_25 >= 0 ) ) {
V_20 += V_16 >> ( V_26 + V_7 -> V_24 - V_7 -> V_25 ) ;
V_21 = ( V_16 << V_7 -> V_25 ) & ( ( 1U << V_26 << V_7 -> V_24 ) - 1 ) ;
} else {
V_20 += ( V_13 ) V_16 * V_7 -> V_27 >> ( V_26 + V_7 -> V_24 ) ;
V_21 = ( V_16 * V_7 -> V_27 ) & ( ( 1U << V_26 << V_7 -> V_24 ) - 1 ) ;
}
* V_19 = V_21 ;
return V_20 ;
}
static T_5 F_17 ( struct V_6 * V_7 , T_5 V_15 , T_5 V_16 )
{
T_5 V_28 ;
V_28 = V_15 << V_7 -> V_18 -> V_17 ;
if ( F_15 ( V_7 -> V_22 >= 0 ) )
V_28 += ( V_15 + 1 ) << V_7 -> V_22 ;
else
V_28 += ( V_15 + 1 ) * V_7 -> V_23 ;
V_28 += ( T_5 ) V_7 -> V_29 + V_16 ;
return V_28 ;
}
static void F_18 ( struct V_6 * V_7 , unsigned * V_30 )
{
if ( F_19 ( * V_30 >= V_7 -> V_31 ) )
* V_30 -= V_7 -> V_31 ;
}
static int F_20 ( struct V_6 * V_7 , int V_32 , int V_33 )
{
struct V_34 V_35 ;
struct V_36 V_37 ;
V_35 . V_38 = V_32 ;
V_35 . V_39 = V_33 ;
V_35 . V_40 . type = V_41 ;
V_35 . V_40 . V_42 . V_43 = V_7 -> V_18 ;
V_35 . V_44 . V_45 = NULL ;
V_35 . V_46 = V_7 -> V_47 ;
V_37 . V_48 = V_7 -> V_49 -> V_48 ;
V_37 . V_50 = V_7 -> V_51 ;
V_37 . V_52 = V_53 ;
return F_21 ( & V_35 , 1 , & V_37 , NULL ) ;
}
static void F_22 ( struct V_6 * V_7 , unsigned V_54 , unsigned V_16 ,
bool V_55 , const char * V_56 )
{
#if F_23 ( V_57 ) || F_23 ( V_58 )
unsigned V_59 = V_55 ? V_7 -> V_60 : V_7 -> V_61 ;
if ( F_19 ( V_54 >= V_7 -> V_31 ) ||
F_19 ( V_16 >= V_59 ) ) {
F_24 ( V_62 L_5 ,
V_56 , V_54 , V_16 , V_7 -> V_31 , V_59 ) ;
F_25 () ;
}
#endif
}
static void F_26 ( struct V_6 * V_7 , unsigned V_54 , unsigned V_16 ,
unsigned * V_63 , unsigned * V_64 )
{
unsigned V_50 ;
F_22 ( V_7 , V_54 , V_16 , false , L_6 ) ;
V_50 = V_54 * V_7 -> V_61 + V_16 ;
* V_63 = V_50 >> ( V_65 - V_26 ) ;
* V_64 = ( V_50 << V_26 ) & ( V_66 - 1 ) ;
}
static struct V_67 * F_27 ( struct V_6 * V_7 , struct V_68 * V_69 ,
unsigned V_54 , unsigned V_16 , unsigned * V_70 )
{
unsigned V_63 , V_64 ;
char * V_71 ;
F_26 ( V_7 , V_54 , V_16 , & V_63 , & V_64 ) ;
if ( V_70 )
* V_70 = ( V_66 - V_64 ) >> V_26 ;
V_71 = F_28 ( V_69 [ V_63 ] . V_72 ) ;
return (struct V_67 * ) ( V_71 + V_64 ) ;
}
static struct V_67 * F_29 ( struct V_6 * V_7 , unsigned V_54 , unsigned V_16 )
{
return F_27 ( V_7 , V_7 -> V_73 , V_54 , V_16 , NULL ) ;
}
static struct V_74 * F_30 ( struct V_6 * V_7 , unsigned V_54 , unsigned V_75 )
{
unsigned V_76 , V_16 ;
struct V_67 * V_77 ;
F_22 ( V_7 , V_54 , V_75 , true , L_7 ) ;
V_76 = V_75 % V_78 ;
V_16 = V_75 / V_78 ;
V_77 = F_29 ( V_7 , V_54 , V_76 ) ;
return (struct V_74 * ) ( ( char * ) V_77 + V_16 * V_7 -> V_79 ) ;
}
static struct V_67 * F_31 ( struct V_6 * V_7 , unsigned V_54 , unsigned V_75 )
{
V_75 <<= V_7 -> V_18 -> V_80 ;
V_75 += V_78 ;
F_22 ( V_7 , V_54 , V_75 , false , L_8 ) ;
return F_29 ( V_7 , V_54 , V_75 ) ;
}
static void F_32 ( struct V_6 * V_7 , unsigned V_54 , T_1 V_28 [ V_81 ] )
{
F_33 ( V_82 , V_7 -> V_83 ) ;
int V_84 ;
unsigned V_11 , V_85 ;
V_82 -> V_86 = V_7 -> V_83 ;
V_82 -> V_87 = V_88 ;
V_84 = F_34 ( V_82 ) ;
if ( F_19 ( V_84 ) ) {
F_6 ( V_7 , L_9 , V_84 ) ;
goto V_8;
}
for ( V_11 = 0 ; V_11 < V_7 -> V_60 ; V_11 ++ ) {
struct V_74 * V_89 = F_30 ( V_7 , V_54 , V_11 ) ;
V_84 = F_35 ( V_82 , ( T_1 * ) & V_89 -> V_90 . V_50 , sizeof V_89 -> V_90 . V_50 ) ;
if ( F_19 ( V_84 ) ) {
F_6 ( V_7 , L_10 , V_84 ) ;
goto V_8;
}
}
V_85 = F_36 ( V_7 -> V_83 ) ;
if ( F_15 ( V_85 <= V_81 ) ) {
V_84 = F_37 ( V_82 , V_28 ) ;
if ( F_19 ( V_84 ) ) {
F_6 ( V_7 , L_11 , V_84 ) ;
goto V_8;
}
memset ( V_28 + V_85 , 0 , V_81 - V_85 ) ;
} else {
T_1 V_91 [ V_85 ] ;
V_84 = F_37 ( V_82 , V_91 ) ;
if ( F_19 ( V_84 ) ) {
F_6 ( V_7 , L_11 , V_84 ) ;
goto V_8;
}
memcpy ( V_28 , V_91 , V_81 ) ;
}
return;
V_8:
memset ( V_28 , 0 , V_81 ) ;
}
static void F_38 ( struct V_6 * V_7 , unsigned V_54 , bool V_92 )
{
T_1 V_28 [ V_81 ] ;
unsigned V_11 ;
if ( ! V_7 -> V_83 )
return;
F_32 ( V_7 , V_54 , V_28 ) ;
for ( V_11 = 0 ; V_11 < V_78 ; V_11 ++ ) {
struct V_67 * V_77 = F_29 ( V_7 , V_54 , V_11 ) ;
if ( F_15 ( V_92 ) )
memcpy ( & V_77 -> V_93 , V_28 + ( V_11 * V_94 ) , V_94 ) ;
else {
if ( memcmp ( & V_77 -> V_93 , V_28 + ( V_11 * V_94 ) , V_94 ) )
F_6 ( V_7 , L_12 , - V_95 ) ;
}
}
}
static void F_39 ( void * V_96 )
{
struct V_97 * V_98 = V_96 ;
F_40 ( ! F_41 ( & V_98 -> V_99 ) ) ;
if ( F_15 ( F_42 ( & V_98 -> V_99 ) ) )
F_43 ( & V_98 -> V_98 ) ;
}
static void F_44 ( struct V_6 * V_7 , bool V_100 , unsigned V_54 ,
unsigned V_101 , struct V_97 * V_98 )
{
struct V_102 V_103 ;
T_2 V_104 = ( T_2 ) ( V_101 * V_7 -> V_61 ) << V_26 ;
unsigned V_63 , V_64 , V_105 ;
struct V_68 * V_106 , * V_107 ;
if ( F_15 ( V_100 ) ) {
V_106 = V_7 -> V_73 ;
V_107 = V_7 -> V_108 ;
} else {
V_106 = V_7 -> V_108 ;
V_107 = V_7 -> V_73 ;
}
F_26 ( V_7 , V_54 , 0 , & V_63 , & V_64 ) ;
F_45 ( F_46 ( V_64 + V_104 , V_66 ) >> V_65 , & V_98 -> V_99 ) ;
F_47 ( & V_103 , V_109 , NULL , F_39 , V_98 , NULL ) ;
V_105 = V_63 ;
do {
T_2 V_110 ;
struct V_72 * V_111 [ 2 ] ;
struct V_72 * V_112 ;
while ( F_19 ( V_63 == V_105 ) ) {
unsigned V_113 ;
if ( F_15 ( V_100 ) )
F_38 ( V_7 , V_54 , true ) ;
V_54 ++ ;
V_101 -- ;
if ( ! V_101 )
break;
F_26 ( V_7 , V_54 , 0 , & V_105 , & V_113 ) ;
}
V_110 = F_48 ( V_104 , ( T_2 ) V_66 - V_64 ) ;
V_112 = V_107 [ V_63 ] . V_72 ;
V_111 [ 0 ] = V_106 [ V_63 ] . V_72 ;
V_111 [ 1 ] = V_7 -> V_114 [ V_63 ] . V_72 ;
F_49 ( V_112 , V_111 , V_64 , 2 , V_110 , & V_103 ) ;
V_63 ++ ;
V_64 = 0 ;
V_104 -= V_110 ;
} while ( V_104 );
F_40 ( V_101 ) ;
F_50 () ;
}
static void F_51 ( struct V_115 * V_116 , int V_8 )
{
struct V_97 * V_98 = V_116 -> V_117 ;
if ( F_19 ( V_8 ) ) {
if ( F_15 ( V_8 == - V_118 ) ) {
F_43 ( & V_98 -> V_7 -> V_119 ) ;
return;
}
F_6 ( V_98 -> V_7 , L_13 , V_8 ) ;
}
F_39 ( V_98 ) ;
}
static bool F_52 ( bool V_100 , struct V_120 * V_116 , struct V_97 * V_98 )
{
int V_84 ;
F_53 ( V_116 , V_121 | V_88 ,
F_51 , V_98 ) ;
if ( F_15 ( V_100 ) )
V_84 = F_54 ( V_116 ) ;
else
V_84 = F_55 ( V_116 ) ;
if ( F_15 ( ! V_84 ) )
return false ;
if ( F_15 ( V_84 == - V_118 ) )
return true ;
if ( F_15 ( V_84 == - V_122 ) ) {
F_56 ( & V_98 -> V_7 -> V_119 ) ;
F_57 ( & V_98 -> V_7 -> V_119 ) ;
return true ;
}
F_6 ( V_98 -> V_7 , L_14 , V_84 ) ;
return false ;
}
static void F_58 ( struct V_6 * V_7 , bool V_100 , unsigned V_54 ,
unsigned V_101 , struct V_97 * V_98 )
{
struct V_123 * * V_124 ;
struct V_123 * * V_125 ;
F_45 ( 2 , & V_98 -> V_99 ) ;
if ( F_15 ( V_100 ) ) {
V_124 = V_7 -> V_126 ;
V_125 = V_7 -> V_127 ;
} else {
V_124 = V_7 -> V_127 ;
V_125 = V_7 -> V_126 ;
}
do {
struct V_120 * V_116 ;
unsigned V_128 ;
char * V_129 ;
if ( F_15 ( V_100 ) )
F_38 ( V_7 , V_54 , true ) ;
V_116 = V_7 -> V_130 [ V_54 ] ;
V_128 = F_59 ( V_7 -> V_131 ) ;
V_129 = V_116 -> V_129 ;
memcpy ( V_129 , V_129 + V_128 , V_128 ) ;
V_116 -> V_132 = V_124 [ V_54 ] ;
V_116 -> V_133 = V_125 [ V_54 ] ;
if ( F_19 ( F_52 ( V_100 , V_116 , V_98 ) ) )
F_60 ( & V_98 -> V_99 ) ;
V_54 ++ ;
V_101 -- ;
} while ( V_101 );
F_61 ( & V_98 -> V_99 ) ;
F_39 ( V_98 ) ;
}
static void F_62 ( struct V_6 * V_7 , bool V_100 , unsigned V_54 ,
unsigned V_101 , struct V_97 * V_98 )
{
if ( V_7 -> V_114 )
return F_44 ( V_7 , V_100 , V_54 , V_101 , V_98 ) ;
else
return F_58 ( V_7 , V_100 , V_54 , V_101 , V_98 ) ;
}
static void F_63 ( unsigned long error , void * V_96 )
{
struct V_97 * V_98 = V_96 ;
if ( F_19 ( error != 0 ) )
F_6 ( V_98 -> V_7 , L_15 , - V_134 ) ;
F_39 ( V_98 ) ;
}
static void F_64 ( struct V_6 * V_7 , int V_32 , int V_33 , unsigned V_54 ,
unsigned V_101 , struct V_97 * V_98 )
{
struct V_34 V_35 ;
struct V_36 V_37 ;
unsigned V_50 , V_70 , V_63 , V_64 ;
int V_84 ;
if ( F_19 ( F_9 ( V_7 ) ) ) {
if ( V_98 )
F_63 ( - 1UL , V_98 ) ;
return;
}
V_50 = V_54 * V_7 -> V_61 ;
V_70 = V_101 * V_7 -> V_61 ;
V_63 = V_50 >> ( V_65 - V_26 ) ;
V_64 = ( V_50 << V_26 ) & ( V_66 - 1 ) ;
V_35 . V_38 = V_32 ;
V_35 . V_39 = V_33 ;
V_35 . V_40 . type = V_135 ;
if ( V_7 -> V_108 )
V_35 . V_40 . V_42 . V_69 = & V_7 -> V_108 [ V_63 ] ;
else
V_35 . V_40 . V_42 . V_69 = & V_7 -> V_73 [ V_63 ] ;
V_35 . V_40 . V_16 = V_64 ;
if ( F_15 ( V_98 != NULL ) ) {
V_35 . V_44 . V_45 = F_63 ;
V_35 . V_44 . V_96 = V_98 ;
} else {
V_35 . V_44 . V_45 = NULL ;
}
V_35 . V_46 = V_7 -> V_47 ;
V_37 . V_48 = V_7 -> V_49 -> V_48 ;
V_37 . V_50 = V_7 -> V_51 + V_53 + V_50 ;
V_37 . V_52 = V_70 ;
V_84 = F_21 ( & V_35 , 1 , & V_37 , NULL ) ;
if ( F_19 ( V_84 ) ) {
F_6 ( V_7 , V_32 == V_136 ? L_16 : L_15 , V_84 ) ;
if ( V_98 ) {
F_65 ( 1 , L_17 , V_84 ) ;
F_63 ( - 1UL , V_98 ) ;
}
}
}
static void F_66 ( struct V_6 * V_7 , unsigned V_137 , unsigned V_138 )
{
struct V_97 V_139 ;
struct V_97 V_140 ;
struct V_97 V_141 ;
unsigned V_10 ;
V_139 . V_7 = V_7 ;
V_139 . V_98 = F_67 ( V_139 . V_98 ) ;
if ( V_137 + V_138 <= V_7 -> V_31 ) {
V_139 . V_99 = ( V_142 ) F_68 ( 1 ) ;
if ( V_7 -> V_108 ) {
V_140 . V_7 = V_7 ;
V_140 . V_98 = F_67 ( V_140 . V_98 ) ;
V_140 . V_99 = ( V_142 ) F_68 ( 0 ) ;
F_62 ( V_7 , true , V_137 , V_138 , & V_140 ) ;
F_69 ( & V_140 . V_98 ) ;
} else {
for ( V_10 = 0 ; V_10 < V_138 ; V_10 ++ )
F_38 ( V_7 , V_137 + V_10 , true ) ;
}
F_64 ( V_7 , V_143 , V_144 | V_145 , V_137 ,
V_138 , & V_139 ) ;
} else {
unsigned V_146 ;
V_139 . V_99 = ( V_142 ) F_68 ( 2 ) ;
V_146 = V_7 -> V_31 - V_137 ;
if ( V_7 -> V_108 ) {
V_140 . V_7 = V_7 ;
V_140 . V_98 = F_67 ( V_140 . V_98 ) ;
V_140 . V_99 = ( V_142 ) F_68 ( 0 ) ;
F_62 ( V_7 , true , V_137 , V_146 , & V_140 ) ;
if ( F_70 ( & V_140 . V_98 ) ) {
F_64 ( V_7 , V_143 , V_144 , V_137 , V_146 , & V_139 ) ;
V_140 . V_98 = F_67 ( V_140 . V_98 ) ;
V_140 . V_99 = ( V_142 ) F_68 ( 0 ) ;
F_62 ( V_7 , true , 0 , V_138 - V_146 , & V_140 ) ;
F_69 ( & V_140 . V_98 ) ;
} else {
V_141 . V_7 = V_7 ;
V_141 . V_98 = F_67 ( V_141 . V_98 ) ;
V_141 . V_99 = ( V_142 ) F_68 ( 0 ) ;
F_62 ( V_7 , true , 0 , V_138 - V_146 , & V_141 ) ;
F_69 ( & V_140 . V_98 ) ;
F_64 ( V_7 , V_143 , V_144 , V_137 , V_146 , & V_139 ) ;
F_69 ( & V_141 . V_98 ) ;
}
} else {
for ( V_10 = 0 ; V_10 < V_146 ; V_10 ++ )
F_38 ( V_7 , V_137 + V_10 , true ) ;
F_64 ( V_7 , V_143 , V_144 , V_137 , V_146 , & V_139 ) ;
for ( V_10 = 0 ; V_10 < V_138 - V_146 ; V_10 ++ )
F_38 ( V_7 , V_10 , true ) ;
}
F_64 ( V_7 , V_143 , V_144 , 0 , V_138 - V_146 , & V_139 ) ;
}
F_69 ( & V_139 . V_98 ) ;
}
static void F_71 ( struct V_6 * V_7 , unsigned V_54 , unsigned V_16 ,
unsigned V_70 , T_5 V_147 , T_6 V_45 , void * V_117 )
{
struct V_34 V_35 ;
struct V_36 V_37 ;
int V_84 ;
unsigned V_50 , V_63 , V_64 ;
F_40 ( ( V_147 | V_70 | V_16 ) & ( unsigned ) ( V_7 -> V_148 - 1 ) ) ;
if ( F_19 ( F_9 ( V_7 ) ) ) {
V_45 ( - 1UL , V_117 ) ;
return;
}
V_50 = V_54 * V_7 -> V_61 + V_78 + V_16 ;
V_63 = V_50 >> ( V_65 - V_26 ) ;
V_64 = ( V_50 << V_26 ) & ( V_66 - 1 ) ;
V_35 . V_38 = V_143 ;
V_35 . V_39 = 0 ;
V_35 . V_40 . type = V_135 ;
V_35 . V_40 . V_42 . V_69 = & V_7 -> V_73 [ V_63 ] ;
V_35 . V_40 . V_16 = V_64 ;
V_35 . V_44 . V_45 = V_45 ;
V_35 . V_44 . V_96 = V_117 ;
V_35 . V_46 = V_7 -> V_47 ;
V_37 . V_48 = V_7 -> V_49 -> V_48 ;
V_37 . V_50 = V_7 -> V_51 + V_147 ;
V_37 . V_52 = V_70 ;
V_84 = F_21 ( & V_35 , 1 , & V_37 , NULL ) ;
if ( F_19 ( V_84 ) ) {
F_65 ( 1 , L_17 , V_84 ) ;
V_45 ( - 1UL , V_117 ) ;
}
}
static bool F_72 ( struct V_6 * V_7 , struct V_149 * V_150 )
{
struct V_151 * * V_75 = & V_7 -> V_152 . V_151 ;
struct V_151 * V_153 ;
F_40 ( ( V_150 -> V_154 | V_150 -> V_70 ) & ( unsigned ) ( V_7 -> V_148 - 1 ) ) ;
V_153 = NULL ;
while ( * V_75 ) {
struct V_149 * V_155 = F_73 ( * V_75 , struct V_149 , V_156 ) ;
V_153 = * V_75 ;
if ( V_150 -> V_154 + V_150 -> V_70 <= V_155 -> V_154 ) {
V_75 = & V_155 -> V_156 . V_157 ;
} else if ( V_150 -> V_154 >= V_155 -> V_154 + V_155 -> V_70 ) {
V_75 = & V_155 -> V_156 . V_158 ;
} else {
return false ;
}
}
F_74 ( & V_150 -> V_156 , V_153 , V_75 ) ;
F_75 ( & V_150 -> V_156 , & V_7 -> V_152 ) ;
return true ;
}
static void F_76 ( struct V_6 * V_7 , struct V_149 * V_155 )
{
F_77 ( & V_155 -> V_156 , & V_7 -> V_152 ) ;
F_78 ( & V_7 -> V_159 ) ;
}
static void F_79 ( struct V_6 * V_7 , struct V_149 * V_155 )
{
unsigned long V_87 ;
F_80 ( & V_7 -> V_159 . V_160 , V_87 ) ;
F_76 ( V_7 , V_155 ) ;
F_81 ( & V_7 -> V_159 . V_160 , V_87 ) ;
}
static void F_82 ( struct V_161 * V_156 )
{
F_83 ( & V_156 -> V_156 ) ;
V_156 -> V_50 = ( T_5 ) - 1 ;
}
static void F_84 ( struct V_6 * V_7 , struct V_161 * V_156 , T_5 V_50 )
{
struct V_151 * * V_162 ;
struct V_151 * V_153 ;
V_156 -> V_50 = V_50 ;
F_40 ( ! F_85 ( & V_156 -> V_156 ) ) ;
V_162 = & V_7 -> V_163 . V_151 ;
V_153 = NULL ;
while ( * V_162 ) {
struct V_161 * V_11 ;
V_153 = * V_162 ;
V_11 = F_73 ( V_153 , struct V_161 , V_156 ) ;
if ( V_50 < V_11 -> V_50 )
V_162 = & V_11 -> V_156 . V_157 ;
else
V_162 = & V_11 -> V_156 . V_158 ;
}
F_74 ( & V_156 -> V_156 , V_153 , V_162 ) ;
F_75 ( & V_156 -> V_156 , & V_7 -> V_163 ) ;
}
static void F_86 ( struct V_6 * V_7 , struct V_161 * V_156 )
{
F_40 ( F_85 ( & V_156 -> V_156 ) ) ;
F_77 ( & V_156 -> V_156 , & V_7 -> V_163 ) ;
F_82 ( V_156 ) ;
}
static unsigned F_87 ( struct V_6 * V_7 , T_5 V_50 , T_5 * V_164 )
{
struct V_151 * V_75 = V_7 -> V_163 . V_151 ;
unsigned V_165 = V_166 ;
* V_164 = ( T_5 ) - 1 ;
while ( V_75 ) {
struct V_161 * V_11 = F_73 ( V_75 , struct V_161 , V_156 ) ;
if ( V_50 == V_11 -> V_50 ) {
V_165 = V_11 - V_7 -> V_167 ;
}
if ( V_50 < V_11 -> V_50 ) {
* V_164 = V_11 -> V_50 ;
V_75 = V_11 -> V_156 . V_157 ;
} else {
V_75 = V_11 -> V_156 . V_158 ;
}
}
return V_165 ;
}
static bool F_88 ( struct V_6 * V_7 , unsigned V_168 , T_5 V_50 )
{
struct V_161 * V_156 , * V_169 ;
struct V_151 * V_170 ;
if ( F_19 ( V_168 >= V_7 -> V_171 ) )
return false ;
V_156 = & V_7 -> V_167 [ V_168 ] ;
if ( F_19 ( F_85 ( & V_156 -> V_156 ) ) )
return false ;
if ( F_19 ( V_156 -> V_50 != V_50 ) )
return false ;
V_170 = F_89 ( & V_156 -> V_156 ) ;
if ( F_19 ( ! V_170 ) )
return true ;
V_169 = F_73 ( V_170 , struct V_161 , V_156 ) ;
return V_169 -> V_50 != V_50 ;
}
static bool F_90 ( struct V_6 * V_7 , struct V_161 * V_156 )
{
struct V_151 * V_170 ;
struct V_161 * V_169 ;
unsigned V_172 ;
F_40 ( F_85 ( & V_156 -> V_156 ) ) ;
V_170 = F_89 ( & V_156 -> V_156 ) ;
if ( F_19 ( ! V_170 ) )
return false ;
V_169 = F_73 ( V_170 , struct V_161 , V_156 ) ;
if ( V_169 -> V_50 != V_156 -> V_50 )
return false ;
V_172 = ( unsigned ) ( V_169 - V_7 -> V_167 ) / V_7 -> V_60 ;
if ( V_172 >= V_7 -> V_173 &&
V_172 < V_7 -> V_173 + V_7 -> V_174 )
return true ;
if ( V_172 + V_7 -> V_31 < V_7 -> V_173 + V_7 -> V_174 )
return true ;
return false ;
}
static int F_91 ( struct V_6 * V_7 , unsigned char * V_175 , T_5 * V_176 ,
unsigned * V_19 , unsigned V_177 , int V_32 )
{
do {
unsigned char * V_117 , * V_178 ;
struct V_179 * V_180 ;
unsigned V_181 ;
int V_84 ;
V_84 = F_9 ( V_7 ) ;
if ( F_19 ( V_84 ) )
return V_84 ;
V_117 = F_92 ( V_7 -> V_182 , * V_176 , & V_180 ) ;
if ( F_19 ( F_93 ( V_117 ) ) )
return F_94 ( V_117 ) ;
V_181 = F_48 ( ( 1U << V_26 << V_7 -> V_24 ) - * V_19 , V_177 ) ;
V_178 = V_117 + * V_19 ;
if ( V_32 == V_183 ) {
memcpy ( V_175 , V_178 , V_181 ) ;
} else if ( V_32 == V_184 ) {
memcpy ( V_178 , V_175 , V_181 ) ;
F_95 ( V_180 ) ;
} else {
if ( F_19 ( memcmp ( V_178 , V_175 , V_181 ) ) ) {
unsigned V_10 ;
for ( V_10 = 0 ; V_10 < V_181 ; V_10 ++ ) {
if ( V_178 [ V_10 ] != V_175 [ V_10 ] )
break;
V_177 -- ;
}
F_96 ( V_180 ) ;
return V_177 ;
}
}
F_96 ( V_180 ) ;
V_175 += V_181 ;
* V_19 += V_181 ;
if ( F_19 ( * V_19 == 1U << V_26 << V_7 -> V_24 ) ) {
( * V_176 ) ++ ;
* V_19 = 0 ;
}
V_177 -= V_181 ;
} while ( F_19 ( V_177 ) );
return 0 ;
}
static void F_97 ( struct V_6 * V_7 )
{
int V_84 ;
V_84 = F_98 ( V_7 -> V_182 ) ;
if ( F_19 ( V_84 ) )
F_6 ( V_7 , L_18 , V_84 ) ;
}
static void F_99 ( struct V_6 * V_7 )
{
F_100 ( V_185 , V_186 ) ;
F_101 ( & V_7 -> V_159 , & V_185 ) ;
F_102 ( V_187 ) ;
F_103 ( & V_7 -> V_159 . V_160 ) ;
F_104 () ;
F_105 ( & V_7 -> V_159 . V_160 ) ;
F_106 ( & V_7 -> V_159 , & V_185 ) ;
}
static void F_107 ( unsigned long V_117 )
{
struct V_6 * V_7 = (struct V_6 * ) V_117 ;
if ( F_15 ( ! F_9 ( V_7 ) ) )
F_108 ( V_7 -> V_188 , & V_7 -> V_189 ) ;
}
static void F_109 ( struct V_6 * V_7 )
{
if ( ! F_110 ( & V_7 -> V_190 ) )
F_111 ( & V_7 -> V_190 , V_191 + V_7 -> V_192 ) ;
}
static void F_112 ( struct V_6 * V_7 , struct V_193 * V_194 )
{
struct V_195 * V_195 ;
unsigned long V_87 ;
F_80 ( & V_7 -> V_159 . V_160 , V_87 ) ;
V_195 = F_113 ( V_194 , sizeof( struct V_193 ) ) ;
F_114 ( & V_7 -> V_196 , V_195 ) ;
F_81 ( & V_7 -> V_159 . V_160 , V_87 ) ;
F_108 ( V_7 -> V_188 , & V_7 -> V_189 ) ;
}
static void F_115 ( struct V_6 * V_7 , struct V_195 * V_195 )
{
int V_84 = F_9 ( V_7 ) ;
if ( F_19 ( V_84 ) && ! V_195 -> V_197 )
V_195 -> V_197 = F_116 ( V_84 ) ;
F_117 ( V_195 ) ;
}
static void F_118 ( struct V_6 * V_7 , struct V_193 * V_194 )
{
struct V_195 * V_195 = F_113 ( V_194 , sizeof( struct V_193 ) ) ;
if ( F_19 ( V_194 -> V_198 ) && F_15 ( ! V_195 -> V_197 ) && F_15 ( ! F_9 ( V_7 ) ) )
F_112 ( V_7 , V_194 ) ;
else
F_115 ( V_7 , V_195 ) ;
}
static void F_119 ( struct V_193 * V_194 )
{
if ( F_42 ( & V_194 -> V_99 ) ) {
struct V_6 * V_7 = V_194 -> V_7 ;
struct V_195 * V_195 ;
F_79 ( V_7 , & V_194 -> V_155 ) ;
if ( F_19 ( V_194 -> V_199 ) )
F_109 ( V_7 ) ;
V_195 = F_113 ( V_194 , sizeof( struct V_193 ) ) ;
if ( F_19 ( V_194 -> V_197 ) && ! V_195 -> V_197 )
V_195 -> V_197 = V_194 -> V_197 ;
if ( F_15 ( ! V_195 -> V_197 ) && F_19 ( F_120 ( V_195 ) != V_194 -> V_155 . V_70 ) ) {
V_194 -> V_155 . V_154 += V_194 -> V_155 . V_70 ;
F_121 ( V_195 , V_194 -> V_155 . V_70 << V_26 ) ;
F_122 ( & V_194 -> V_200 , V_201 ) ;
F_108 ( V_7 -> V_202 , & V_194 -> V_200 ) ;
return;
}
F_118 ( V_7 , V_194 ) ;
}
}
static void F_123 ( struct V_195 * V_195 )
{
struct V_193 * V_194 = F_124 ( V_195 , sizeof( struct V_193 ) ) ;
V_195 -> V_203 = V_194 -> V_204 ;
V_195 -> V_205 = V_194 -> V_206 ;
if ( V_194 -> V_207 ) {
V_195 -> V_208 = V_194 -> V_207 ;
V_195 -> V_209 |= V_210 ;
}
V_195 -> V_211 = V_194 -> V_212 ;
if ( V_194 -> V_213 )
F_43 ( V_194 -> V_213 ) ;
F_119 ( V_194 ) ;
}
static void F_125 ( struct V_6 * V_7 , T_5 V_50 ,
const char * V_117 , char * V_28 )
{
V_13 V_214 = F_12 ( V_50 ) ;
F_33 ( V_116 , V_7 -> V_215 ) ;
int V_84 ;
unsigned V_216 ;
V_116 -> V_86 = V_7 -> V_215 ;
V_116 -> V_87 = 0 ;
V_84 = F_34 ( V_116 ) ;
if ( F_19 ( V_84 < 0 ) ) {
F_6 ( V_7 , L_9 , V_84 ) ;
goto V_9;
}
V_84 = F_35 ( V_116 , ( const T_1 * ) & V_214 , sizeof V_214 ) ;
if ( F_19 ( V_84 < 0 ) ) {
F_6 ( V_7 , L_10 , V_84 ) ;
goto V_9;
}
V_84 = F_35 ( V_116 , V_117 , V_7 -> V_148 << V_26 ) ;
if ( F_19 ( V_84 < 0 ) ) {
F_6 ( V_7 , L_10 , V_84 ) ;
goto V_9;
}
V_84 = F_37 ( V_116 , V_28 ) ;
if ( F_19 ( V_84 < 0 ) ) {
F_6 ( V_7 , L_11 , V_84 ) ;
goto V_9;
}
V_216 = F_36 ( V_7 -> V_215 ) ;
if ( F_19 ( V_216 < V_7 -> V_27 ) )
memset ( V_28 + V_216 , 0 , V_7 -> V_27 - V_216 ) ;
return;
V_9:
F_126 ( V_28 , V_7 -> V_27 ) ;
}
static void F_127 ( struct V_217 * V_218 )
{
struct V_193 * V_194 = F_73 ( V_218 , struct V_193 , V_200 ) ;
struct V_6 * V_7 = V_194 -> V_7 ;
int V_84 ;
if ( V_7 -> V_215 ) {
struct V_219 V_220 ;
struct V_221 V_222 ;
unsigned V_216 = F_36 ( V_7 -> V_215 ) ;
struct V_195 * V_195 = F_113 ( V_194 , sizeof( struct V_193 ) ) ;
char * V_223 ;
unsigned V_224 = F_19 ( V_216 > V_7 -> V_27 ) ? V_216 - V_7 -> V_27 : 0 ;
char V_225 [ V_7 -> V_27 + V_224 ] ;
unsigned V_226 = V_194 -> V_155 . V_70 ;
T_5 V_50 = V_194 -> V_155 . V_154 ;
if ( F_19 ( V_7 -> V_227 == 'R' ) )
goto V_228;
V_223 = F_128 ( ( V_66 >> V_26 >> V_7 -> V_18 -> V_80 ) * V_7 -> V_27 + V_224 ,
V_229 | V_230 | V_231 ) ;
if ( ! V_223 )
V_223 = V_225 ;
F_129 (bv, bio, iter, dio->orig_bi_iter) {
unsigned V_168 ;
char * V_40 , * V_232 ;
V_233:
V_40 = ( char * ) F_130 ( V_222 . V_234 ) + V_222 . V_235 ;
V_168 = 0 ;
V_232 = V_223 ;
do {
F_125 ( V_7 , V_50 , V_40 + V_168 , V_232 ) ;
V_232 += V_7 -> V_27 ;
V_226 -= V_7 -> V_148 ;
V_168 += V_7 -> V_148 << V_26 ;
V_50 += V_7 -> V_148 ;
} while ( V_168 < V_222 . V_236 && V_226 && V_223 != V_225 );
F_131 ( V_40 ) ;
V_84 = F_91 ( V_7 , V_223 , & V_194 -> V_176 , & V_194 -> V_19 ,
V_232 - V_223 , ! V_194 -> V_199 ? V_237 : V_184 ) ;
if ( F_19 ( V_84 ) ) {
if ( V_84 > 0 ) {
F_8 ( L_19 ,
( unsigned long long ) ( V_50 - ( ( V_84 + V_7 -> V_27 - 1 ) / V_7 -> V_27 ) ) ) ;
V_84 = - V_95 ;
}
if ( F_15 ( V_223 != V_225 ) )
F_132 ( V_223 ) ;
goto error;
}
if ( ! V_226 )
break;
if ( F_19 ( V_168 < V_222 . V_236 ) ) {
V_222 . V_235 += V_168 ;
V_222 . V_236 -= V_168 ;
goto V_233;
}
}
if ( F_15 ( V_223 != V_225 ) )
F_132 ( V_223 ) ;
} else {
struct V_238 * V_239 = V_194 -> V_207 ;
if ( V_239 ) {
struct V_221 V_240 ;
struct V_219 V_220 ;
unsigned V_241 = V_194 -> V_155 . V_70 ;
F_16 ( V_7 , V_241 ) ;
V_241 *= V_7 -> V_27 ;
F_133 (biv, bip, iter) {
unsigned char * V_175 ;
unsigned V_242 ;
F_40 ( F_134 ( V_240 . V_234 ) ) ;
V_175 = F_28 ( V_240 . V_234 ) + V_240 . V_235 ;
V_242 = F_48 ( V_240 . V_236 , V_241 ) ;
V_84 = F_91 ( V_7 , V_175 , & V_194 -> V_176 , & V_194 -> V_19 ,
V_242 , ! V_194 -> V_199 ? V_183 : V_184 ) ;
if ( F_19 ( V_84 ) )
goto error;
V_241 -= V_242 ;
if ( ! V_241 )
break;
}
}
}
V_228:
F_119 ( V_194 ) ;
return;
error:
V_194 -> V_197 = F_116 ( V_84 ) ;
F_119 ( V_194 ) ;
}
static int F_135 ( struct V_243 * V_244 , struct V_195 * V_195 )
{
struct V_6 * V_7 = V_244 -> V_245 ;
struct V_193 * V_194 = F_124 ( V_195 , sizeof( struct V_193 ) ) ;
struct V_238 * V_239 ;
T_5 V_15 , V_16 ;
V_194 -> V_7 = V_7 ;
V_194 -> V_197 = 0 ;
if ( F_19 ( V_195 -> V_209 & V_246 ) ) {
F_112 ( V_7 , V_194 ) ;
return V_247 ;
}
V_194 -> V_155 . V_154 = F_136 ( V_244 , V_195 -> V_203 . V_248 ) ;
V_194 -> V_199 = F_137 ( V_195 ) == V_143 ;
V_194 -> V_198 = V_194 -> V_199 && V_195 -> V_209 & V_144 ;
if ( F_19 ( V_194 -> V_198 ) ) {
V_195 -> V_209 &= ~ V_144 ;
}
if ( F_19 ( V_194 -> V_155 . V_154 + F_120 ( V_195 ) > V_7 -> V_249 ) ) {
F_8 ( L_20 ,
( unsigned long long ) V_194 -> V_155 . V_154 , F_120 ( V_195 ) ,
( unsigned long long ) V_7 -> V_249 ) ;
return V_250 ;
}
if ( F_19 ( ( V_194 -> V_155 . V_154 | F_120 ( V_195 ) ) & ( unsigned ) ( V_7 -> V_148 - 1 ) ) ) {
F_8 ( L_21 ,
V_7 -> V_148 ,
( unsigned long long ) V_194 -> V_155 . V_154 , F_120 ( V_195 ) ) ;
return V_250 ;
}
if ( V_7 -> V_148 > 1 ) {
struct V_219 V_220 ;
struct V_221 V_222 ;
F_138 (bv, bio, iter) {
if ( F_19 ( ( V_222 . V_235 | V_222 . V_236 ) & ( ( V_7 -> V_148 << V_26 ) - 1 ) ) ) {
F_8 ( L_22 ,
V_222 . V_235 , V_222 . V_236 , V_7 -> V_148 ) ;
return V_250 ;
}
}
}
V_239 = F_139 ( V_195 ) ;
if ( ! V_7 -> V_215 ) {
if ( V_239 ) {
unsigned V_251 = F_120 ( V_195 ) >> V_7 -> V_18 -> V_80 ;
if ( V_7 -> V_25 >= 0 )
V_251 <<= V_7 -> V_25 ;
else
V_251 *= V_7 -> V_27 ;
if ( F_19 ( V_251 != V_239 -> V_252 . V_253 ) ) {
F_8 ( L_23 , V_239 -> V_252 . V_253 , V_251 ) ;
return V_250 ;
}
}
} else {
if ( F_19 ( V_239 != NULL ) ) {
F_8 ( L_24 ) ;
return V_250 ;
}
}
if ( F_19 ( V_7 -> V_227 == 'R' ) && F_19 ( V_194 -> V_199 ) )
return V_250 ;
F_13 ( V_7 , V_194 -> V_155 . V_154 , & V_15 , & V_16 ) ;
V_194 -> V_176 = F_14 ( V_7 , V_15 , V_16 , & V_194 -> V_19 ) ;
V_195 -> V_203 . V_248 = F_17 ( V_7 , V_15 , V_16 ) ;
F_140 ( V_194 , true ) ;
return V_247 ;
}
static bool F_141 ( struct V_193 * V_194 , struct V_195 * V_195 ,
unsigned V_254 , unsigned V_74 )
{
struct V_6 * V_7 = V_194 -> V_7 ;
T_5 V_154 ;
unsigned V_70 ;
V_154 = V_194 -> V_155 . V_154 ;
V_70 = V_194 -> V_155 . V_70 ;
do {
struct V_221 V_222 = F_142 ( V_195 ) ;
char * V_40 ;
if ( F_19 ( V_222 . V_236 >> V_26 > V_70 ) )
V_222 . V_236 = V_70 << V_26 ;
V_70 -= V_222 . V_236 >> V_26 ;
F_143 ( V_195 , & V_195 -> V_203 , V_222 . V_236 ) ;
V_255:
V_40 = F_130 ( V_222 . V_234 ) ;
if ( F_15 ( V_194 -> V_199 ) )
F_144 ( V_222 . V_234 ) ;
do {
struct V_74 * V_89 = F_30 ( V_7 , V_254 , V_74 ) ;
if ( F_19 ( ! V_194 -> V_199 ) ) {
struct V_67 * V_77 ;
char * V_256 ;
unsigned V_257 ;
if ( F_19 ( F_145 ( V_89 ) ) ) {
F_144 ( V_222 . V_234 ) ;
F_131 ( V_40 ) ;
F_146 ( V_7 -> V_258 , ! F_145 ( V_89 ) ) ;
goto V_255;
}
F_147 () ;
F_40 ( F_148 ( V_89 ) != V_154 ) ;
V_77 = F_31 ( V_7 , V_254 , V_74 ) ;
V_256 = V_40 + V_222 . V_235 ;
V_257 = 0 ;
do {
memcpy ( V_256 , V_77 , V_259 ) ;
* ( T_4 * ) ( V_256 + V_259 ) = V_89 -> V_260 [ V_257 ] ;
V_77 ++ ;
V_256 += 1 << V_26 ;
} while ( ++ V_257 < V_7 -> V_148 );
#ifdef V_58
if ( V_7 -> V_215 ) {
char V_225 [ F_149 ( F_36 ( V_7 -> V_215 ) , V_7 -> V_27 ) ] ;
F_125 ( V_7 , V_154 , V_40 + V_222 . V_235 , V_225 ) ;
if ( F_19 ( memcmp ( V_225 , F_150 ( V_7 , V_89 ) , V_7 -> V_27 ) ) ) {
F_8 ( L_25 ,
( unsigned long long ) V_154 ) ;
}
}
#endif
}
if ( ! V_7 -> V_215 ) {
struct V_238 * V_239 = F_139 ( V_195 ) ;
unsigned V_261 = V_7 -> V_27 ;
char * V_262 = F_150 ( V_7 , V_89 ) ;
if ( V_239 ) do {
struct V_221 V_240 = F_151 ( V_239 -> V_263 , V_239 -> V_252 ) ;
unsigned V_264 = F_48 ( V_240 . V_236 , V_261 ) ;
char * V_265 ;
F_40 ( F_134 ( V_240 . V_234 ) ) ;
V_265 = F_28 ( V_240 . V_234 ) + V_240 . V_235 ;
if ( F_15 ( V_194 -> V_199 ) )
memcpy ( V_262 , V_265 , V_264 ) ;
else
memcpy ( V_265 , V_262 , V_264 ) ;
F_152 ( V_239 -> V_263 , & V_239 -> V_252 , V_264 ) ;
V_262 += V_264 ;
V_261 -= V_264 ;
} while ( F_19 ( V_261 ) ); else {
if ( F_15 ( V_194 -> V_199 ) )
memset ( V_262 , 0 , V_261 ) ;
}
}
if ( F_15 ( V_194 -> V_199 ) ) {
struct V_67 * V_77 ;
unsigned V_257 ;
V_77 = F_31 ( V_7 , V_254 , V_74 ) ;
memcpy ( V_77 , V_40 + V_222 . V_235 , V_7 -> V_148 << V_26 ) ;
V_257 = 0 ;
do {
V_89 -> V_260 [ V_257 ] = V_77 [ V_257 ] . V_266 ;
} while ( ++ V_257 < V_7 -> V_148 );
if ( V_7 -> V_215 ) {
unsigned V_216 = F_36 ( V_7 -> V_215 ) ;
if ( F_19 ( V_216 > V_7 -> V_27 ) ) {
char V_225 [ V_216 ] ;
F_125 ( V_7 , V_154 , ( char * ) V_77 , V_225 ) ;
memcpy ( F_150 ( V_7 , V_89 ) , V_225 , V_7 -> V_27 ) ;
} else
F_125 ( V_7 , V_154 , ( char * ) V_77 , F_150 ( V_7 , V_89 ) ) ;
}
F_153 ( V_89 , V_154 ) ;
}
V_154 += V_7 -> V_148 ;
V_74 ++ ;
if ( F_19 ( V_74 == V_7 -> V_60 ) ) {
V_74 = 0 ;
V_254 ++ ;
F_18 ( V_7 , & V_254 ) ;
}
V_222 . V_235 += V_7 -> V_148 << V_26 ;
} while ( V_222 . V_236 -= V_7 -> V_148 << V_26 );
if ( F_19 ( ! V_194 -> V_199 ) )
F_144 ( V_222 . V_234 ) ;
F_131 ( V_40 ) ;
} while ( V_70 );
if ( F_15 ( V_194 -> V_199 ) ) {
F_154 () ;
if ( F_19 ( F_155 ( & V_7 -> V_258 ) ) )
F_156 ( & V_7 -> V_258 ) ;
if ( F_10 ( V_7 -> V_267 ) <= V_7 -> V_268 ) {
F_108 ( V_7 -> V_188 , & V_7 -> V_189 ) ;
} else {
F_109 ( V_7 ) ;
}
} else {
F_79 ( V_7 , & V_194 -> V_155 ) ;
}
if ( F_19 ( V_195 -> V_203 . V_253 ) ) {
T_5 V_15 , V_16 ;
V_194 -> V_155 . V_154 = V_154 ;
F_13 ( V_7 , V_194 -> V_155 . V_154 , & V_15 , & V_16 ) ;
V_194 -> V_176 = F_14 ( V_7 , V_15 , V_16 , & V_194 -> V_19 ) ;
return true ;
}
return false ;
}
static void F_140 ( struct V_193 * V_194 , bool V_269 )
{
struct V_6 * V_7 = V_194 -> V_7 ;
struct V_195 * V_195 = F_113 ( V_194 , sizeof( struct V_193 ) ) ;
unsigned V_254 , V_74 ;
unsigned V_270 ;
struct V_213 V_271 ;
bool V_272 = V_7 -> V_215 && ! V_194 -> V_199 ;
if ( V_272 && V_269 ) {
F_122 ( & V_194 -> V_200 , V_201 ) ;
F_108 ( V_7 -> V_273 , & V_194 -> V_200 ) ;
return;
}
V_274:
F_105 ( & V_7 -> V_159 . V_160 ) ;
V_275:
if ( F_19 ( F_9 ( V_7 ) ) ) {
F_103 ( & V_7 -> V_159 . V_160 ) ;
F_115 ( V_7 , V_195 ) ;
return;
}
V_194 -> V_155 . V_70 = F_120 ( V_195 ) ;
V_270 = V_166 ;
if ( F_15 ( V_7 -> V_227 == 'J' ) ) {
if ( V_194 -> V_199 ) {
unsigned V_276 , V_10 , V_168 ;
unsigned V_277 , V_278 , V_279 ;
V_194 -> V_155 . V_70 = F_48 ( V_194 -> V_155 . V_70 ,
V_7 -> V_267 << V_7 -> V_18 -> V_80 ) ;
if ( F_19 ( ! V_194 -> V_155 . V_70 ) )
goto V_280;
V_279 = V_194 -> V_155 . V_70 >> V_7 -> V_18 -> V_80 ;
V_7 -> V_267 -= V_279 ;
V_254 = V_7 -> V_281 ;
V_74 = V_7 -> V_282 ;
V_276 = V_7 -> V_282 + V_279 ;
V_7 -> V_282 = V_276 % V_7 -> V_60 ;
V_7 -> V_281 += V_276 / V_7 -> V_60 ;
V_7 -> V_283 += V_276 / V_7 -> V_60 ;
F_18 ( V_7 , & V_7 -> V_281 ) ;
V_168 = V_254 * V_7 -> V_60 + V_74 ;
V_277 = V_254 ;
V_278 = V_74 ;
V_10 = 0 ;
do {
struct V_74 * V_89 ;
F_84 ( V_7 , & V_7 -> V_167 [ V_168 ] , V_194 -> V_155 . V_154 + V_10 ) ;
V_168 ++ ;
if ( F_19 ( V_168 >= V_7 -> V_171 ) )
V_168 = 0 ;
V_89 = F_30 ( V_7 , V_277 , V_278 ) ;
F_40 ( ! F_157 ( V_89 ) ) ;
F_158 ( V_89 ) ;
V_278 ++ ;
if ( F_19 ( V_278 == V_7 -> V_60 ) ) {
V_278 = 0 ;
V_277 ++ ;
F_18 ( V_7 , & V_277 ) ;
}
} while ( ( V_10 += V_7 -> V_148 ) < V_194 -> V_155 . V_70 );
F_103 ( & V_7 -> V_159 . V_160 ) ;
goto V_284;
} else {
T_5 V_164 ;
V_270 = F_87 ( V_7 , V_194 -> V_155 . V_154 , & V_164 ) ;
if ( F_15 ( V_270 == V_166 ) ) {
if ( F_19 ( V_194 -> V_155 . V_70 > V_164 - V_194 -> V_155 . V_154 ) )
V_194 -> V_155 . V_70 = V_164 - V_194 -> V_155 . V_154 ;
} else {
unsigned V_10 ;
unsigned V_285 = V_270 + 1 ;
for ( V_10 = V_7 -> V_148 ; V_10 < V_194 -> V_155 . V_70 ; V_10 += V_7 -> V_148 , V_285 ++ ) {
if ( ! F_88 ( V_7 , V_285 , V_194 -> V_155 . V_154 + V_10 ) )
break;
}
V_194 -> V_155 . V_70 = V_10 ;
}
}
}
if ( F_19 ( ! F_72 ( V_7 , & V_194 -> V_155 ) ) ) {
V_280:
if ( V_269 ) {
F_103 ( & V_7 -> V_159 . V_160 ) ;
F_122 ( & V_194 -> V_200 , V_201 ) ;
F_108 ( V_7 -> V_202 , & V_194 -> V_200 ) ;
return;
} else {
F_99 ( V_7 ) ;
goto V_275;
}
}
F_103 ( & V_7 -> V_159 . V_160 ) ;
if ( F_19 ( V_270 != V_166 ) ) {
V_254 = V_270 / V_7 -> V_60 ;
V_74 = V_270 % V_7 -> V_60 ;
goto V_284;
}
V_194 -> V_99 = ( V_142 ) F_68 ( 2 ) ;
if ( V_272 ) {
V_271 = F_67 ( V_271 ) ;
V_194 -> V_213 = & V_271 ;
} else
V_194 -> V_213 = NULL ;
V_194 -> V_204 = V_195 -> V_203 ;
V_194 -> V_206 = V_195 -> V_205 ;
V_195 -> V_205 = V_7 -> V_49 -> V_48 ;
V_194 -> V_207 = F_139 ( V_195 ) ;
V_195 -> V_208 = NULL ;
V_195 -> V_209 &= ~ V_210 ;
V_194 -> V_212 = V_195 -> V_211 ;
V_195 -> V_211 = F_123 ;
V_195 -> V_203 . V_253 = V_194 -> V_155 . V_70 << V_26 ;
V_195 -> V_203 . V_248 += V_7 -> V_51 ;
F_159 ( V_195 ) ;
if ( V_272 ) {
F_69 ( & V_271 ) ;
F_127 ( & V_194 -> V_200 ) ;
} else {
F_122 ( & V_194 -> V_200 , F_127 ) ;
F_108 ( V_7 -> V_273 , & V_194 -> V_200 ) ;
}
return;
V_284:
if ( F_19 ( F_141 ( V_194 , V_195 , V_254 , V_74 ) ) )
goto V_274;
F_118 ( V_7 , V_194 ) ;
}
static void V_201 ( struct V_217 * V_218 )
{
struct V_193 * V_194 = F_73 ( V_218 , struct V_193 , V_200 ) ;
F_140 ( V_194 , false ) ;
}
static void F_160 ( struct V_6 * V_7 )
{
if ( V_7 -> V_282 ) {
V_7 -> V_267 -= V_7 -> V_60 - V_7 -> V_282 ;
V_7 -> V_282 = 0 ;
V_7 -> V_281 ++ ;
F_18 ( V_7 , & V_7 -> V_281 ) ;
V_7 -> V_283 ++ ;
}
F_161 ( V_7 -> V_31 * V_7 -> V_60 !=
( V_7 -> V_283 + V_7 -> V_174 ) * V_7 -> V_60 + V_7 -> V_267 ) ;
}
static void F_162 ( struct V_217 * V_218 )
{
struct V_6 * V_7 = F_73 ( V_218 , struct V_6 , V_189 ) ;
unsigned V_137 , V_138 ;
unsigned V_10 , V_11 , V_75 ;
struct V_195 * V_286 ;
F_163 ( & V_7 -> V_190 ) ;
F_105 ( & V_7 -> V_159 . V_160 ) ;
V_286 = F_164 ( & V_7 -> V_196 ) ;
if ( F_19 ( V_7 -> V_227 != 'J' ) ) {
F_103 ( & V_7 -> V_159 . V_160 ) ;
F_97 ( V_7 ) ;
goto V_287;
}
F_160 ( V_7 ) ;
V_137 = V_7 -> V_288 ;
V_138 = V_7 -> V_283 ;
F_103 ( & V_7 -> V_159 . V_160 ) ;
if ( ! V_138 )
goto V_287;
V_10 = V_137 ;
for ( V_75 = 0 ; V_75 < V_138 ; V_75 ++ ) {
for ( V_11 = 0 ; V_11 < V_7 -> V_60 ; V_11 ++ ) {
struct V_74 * V_89 ;
V_89 = F_30 ( V_7 , V_10 , V_11 ) ;
F_165 ( V_7 -> V_258 , ! F_145 ( V_89 ) ) ;
}
for ( V_11 = 0 ; V_11 < V_7 -> V_61 ; V_11 ++ ) {
struct V_67 * V_77 ;
V_77 = F_29 ( V_7 , V_10 , V_11 ) ;
V_77 -> V_266 = F_11 ( V_7 , V_10 , V_11 , V_7 -> V_289 ) ;
}
V_10 ++ ;
if ( F_19 ( V_10 >= V_7 -> V_31 ) )
V_7 -> V_289 = F_2 ( V_7 -> V_289 ) ;
F_18 ( V_7 , & V_10 ) ;
}
F_147 () ;
F_66 ( V_7 , V_137 , V_138 ) ;
F_105 ( & V_7 -> V_159 . V_160 ) ;
V_7 -> V_288 += V_138 ;
F_18 ( V_7 , & V_7 -> V_288 ) ;
V_7 -> V_283 -= V_138 ;
V_7 -> V_174 += V_138 ;
F_103 ( & V_7 -> V_159 . V_160 ) ;
if ( F_10 ( V_7 -> V_267 ) <= V_7 -> V_268 )
F_108 ( V_7 -> V_290 , & V_7 -> V_291 ) ;
V_287:
while ( V_286 ) {
struct V_195 * V_170 = V_286 -> V_292 ;
V_286 -> V_292 = NULL ;
F_115 ( V_7 , V_286 ) ;
V_286 = V_170 ;
}
}
static void F_166 ( unsigned long error , void * V_96 )
{
struct V_108 * V_47 = V_96 ;
struct V_97 * V_98 = V_47 -> V_98 ;
struct V_6 * V_7 = V_98 -> V_7 ;
F_79 ( V_7 , & V_47 -> V_155 ) ;
F_167 ( V_47 , V_7 -> V_293 ) ;
if ( F_19 ( error != 0 ) )
F_6 ( V_7 , L_26 , - V_134 ) ;
F_39 ( V_98 ) ;
}
static void F_168 ( struct V_6 * V_7 , struct V_67 * V_77 ,
struct V_74 * V_89 )
{
unsigned V_257 = 0 ;
do {
V_77 -> V_266 = V_89 -> V_260 [ V_257 ] ;
V_77 ++ ;
} while ( ++ V_257 < V_7 -> V_148 );
}
static void F_169 ( struct V_6 * V_7 , unsigned V_294 ,
unsigned V_295 , bool V_296 )
{
unsigned V_10 , V_11 , V_75 ;
struct V_97 V_98 ;
struct V_297 V_298 ;
F_170 ( & V_298 ) ;
V_98 . V_7 = V_7 ;
V_98 . V_99 = ( V_142 ) F_68 ( 1 ) ;
V_98 . V_98 = F_67 ( V_98 . V_98 ) ;
V_10 = V_294 ;
for ( V_75 = 0 ; V_75 < V_295 ; V_75 ++ , V_10 ++ , F_18 ( V_7 , & V_10 ) ) {
#ifndef V_58
if ( F_19 ( V_296 ) )
#endif
F_38 ( V_7 , V_10 , false ) ;
for ( V_11 = 0 ; V_11 < V_7 -> V_60 ; V_11 ++ ) {
struct V_74 * V_89 = F_30 ( V_7 , V_10 , V_11 ) ;
T_5 V_299 , V_15 , V_16 ;
unsigned V_300 , V_301 , V_302 ;
T_5 V_176 ;
unsigned V_19 ;
struct V_108 * V_47 ;
if ( F_157 ( V_89 ) )
continue;
F_40 ( F_19 ( F_145 ( V_89 ) ) && ! V_296 ) ;
V_299 = F_148 ( V_89 ) ;
if ( F_19 ( V_296 ) ) {
if ( F_19 ( V_299 & ( unsigned ) ( V_7 -> V_148 - 1 ) ) ) {
F_6 ( V_7 , L_27 , - V_134 ) ;
V_299 &= ~ ( T_5 ) ( V_7 -> V_148 - 1 ) ;
}
}
F_13 ( V_7 , V_299 , & V_15 , & V_16 ) ;
F_168 ( V_7 , F_31 ( V_7 , V_10 , V_11 ) , V_89 ) ;
for ( V_300 = V_11 + 1 ; V_300 < V_7 -> V_60 ; V_300 ++ ) {
struct V_74 * V_303 = F_30 ( V_7 , V_10 , V_300 ) ;
T_5 V_304 , V_305 , V_306 ;
if ( F_157 ( V_303 ) )
break;
F_40 ( F_19 ( F_145 ( V_303 ) ) && ! V_296 ) ;
V_304 = F_148 ( V_303 ) ;
F_13 ( V_7 , V_304 , & V_305 , & V_306 ) ;
if ( V_305 != V_15 || V_306 != V_16 + ( ( V_300 - V_11 ) << V_7 -> V_18 -> V_80 ) )
break;
F_168 ( V_7 , F_31 ( V_7 , V_10 , V_300 ) , V_303 ) ;
}
V_302 = V_300 - 1 ;
V_47 = F_171 ( V_7 -> V_293 , V_229 ) ;
V_47 -> V_98 = & V_98 ;
V_47 -> V_155 . V_154 = V_299 ;
V_47 -> V_155 . V_70 = ( V_300 - V_11 ) << V_7 -> V_18 -> V_80 ;
F_105 ( & V_7 -> V_159 . V_160 ) ;
while ( F_19 ( ! F_72 ( V_7 , & V_47 -> V_155 ) ) )
F_99 ( V_7 ) ;
if ( F_15 ( ! V_296 ) ) {
struct V_161 * V_307 = & V_7 -> V_167 [ V_10 * V_7 -> V_60 ] ;
while ( V_11 < V_300 && F_90 ( V_7 , & V_307 [ V_11 ] ) ) {
struct V_74 * V_303 = F_30 ( V_7 , V_10 , V_11 ) ;
F_172 ( V_303 ) ;
F_86 ( V_7 , & V_307 [ V_11 ] ) ;
V_11 ++ ;
V_299 += V_7 -> V_148 ;
V_16 += V_7 -> V_148 ;
}
while ( V_11 < V_300 && F_90 ( V_7 , & V_307 [ V_300 - 1 ] ) ) {
struct V_74 * V_303 = F_30 ( V_7 , V_10 , V_300 - 1 ) ;
F_172 ( V_303 ) ;
F_86 ( V_7 , & V_307 [ V_300 - 1 ] ) ;
V_300 -- ;
}
if ( V_11 == V_300 ) {
F_76 ( V_7 , & V_47 -> V_155 ) ;
F_103 ( & V_7 -> V_159 . V_160 ) ;
F_167 ( V_47 , V_7 -> V_293 ) ;
goto V_228;
}
for ( V_301 = V_11 ; V_301 < V_300 ; V_301 ++ ) {
F_86 ( V_7 , & V_307 [ V_301 ] ) ;
}
}
F_103 ( & V_7 -> V_159 . V_160 ) ;
V_176 = F_14 ( V_7 , V_15 , V_16 , & V_19 ) ;
for ( V_301 = V_11 ; V_301 < V_300 ; V_301 ++ ) {
int V_84 ;
struct V_74 * V_303 = F_30 ( V_7 , V_10 , V_301 ) ;
if (
#ifndef V_58
F_19 ( V_296 ) &&
#endif
V_7 -> V_215 ) {
char V_308 [ F_149 ( F_36 ( V_7 -> V_215 ) , V_7 -> V_27 ) ] ;
F_125 ( V_7 , V_299 + ( ( V_301 - V_11 ) << V_7 -> V_18 -> V_80 ) ,
( char * ) F_31 ( V_7 , V_10 , V_301 ) , V_308 ) ;
if ( F_19 ( memcmp ( V_308 , F_150 ( V_7 , V_303 ) , V_7 -> V_27 ) ) )
F_6 ( V_7 , L_28 , - V_95 ) ;
}
F_172 ( V_303 ) ;
V_84 = F_91 ( V_7 , F_150 ( V_7 , V_303 ) , & V_176 , & V_19 ,
V_7 -> V_27 , V_184 ) ;
if ( F_19 ( V_84 ) ) {
F_6 ( V_7 , L_29 , V_84 ) ;
}
}
F_60 ( & V_98 . V_99 ) ;
F_71 ( V_7 , V_10 , V_11 << V_7 -> V_18 -> V_80 ,
( V_300 - V_11 ) << V_7 -> V_18 -> V_80 ,
F_17 ( V_7 , V_15 , V_16 ) ,
F_166 , V_47 ) ;
V_228:
V_11 = V_302 ;
}
}
F_173 ( V_7 -> V_182 ) ;
F_174 ( & V_298 ) ;
F_39 ( & V_98 ) ;
F_69 ( & V_98 . V_98 ) ;
F_97 ( V_7 ) ;
}
static void F_175 ( struct V_217 * V_218 )
{
struct V_6 * V_7 = F_73 ( V_218 , struct V_6 , V_291 ) ;
unsigned V_294 , V_295 ;
unsigned V_309 ;
if ( F_10 ( V_7 -> V_310 ) )
return;
F_105 ( & V_7 -> V_159 . V_160 ) ;
V_294 = V_7 -> V_173 ;
V_295 = V_7 -> V_174 ;
F_103 ( & V_7 -> V_159 . V_160 ) ;
if ( ! V_295 )
return;
F_169 ( V_7 , V_294 , V_295 , false ) ;
F_105 ( & V_7 -> V_159 . V_160 ) ;
V_7 -> V_173 += V_295 ;
F_18 ( V_7 , & V_7 -> V_173 ) ;
V_7 -> V_174 -= V_295 ;
V_309 = V_7 -> V_267 ;
V_7 -> V_267 += V_295 * V_7 -> V_60 ;
if ( F_19 ( ! V_309 ) )
F_78 ( & V_7 -> V_159 ) ;
F_103 ( & V_7 -> V_159 . V_160 ) ;
}
static void F_176 ( struct V_6 * V_7 , unsigned V_311 ,
unsigned V_101 , unsigned char V_289 )
{
unsigned V_10 , V_11 , V_75 ;
if ( ! V_101 )
return;
for ( V_75 = 0 ; V_75 < V_101 ; V_75 ++ ) {
V_10 = V_311 + V_75 ;
F_18 ( V_7 , & V_10 ) ;
for ( V_11 = 0 ; V_11 < V_7 -> V_61 ; V_11 ++ ) {
struct V_67 * V_77 = F_29 ( V_7 , V_10 , V_11 ) ;
memset ( & V_77 -> V_312 , 0 , V_259 ) ;
V_77 -> V_266 = F_11 ( V_7 , V_10 , V_11 , V_289 ) ;
}
for ( V_11 = 0 ; V_11 < V_7 -> V_60 ; V_11 ++ ) {
struct V_74 * V_89 = F_30 ( V_7 , V_10 , V_11 ) ;
F_172 ( V_89 ) ;
}
}
F_66 ( V_7 , V_311 , V_101 ) ;
}
static int F_177 ( struct V_6 * V_7 , unsigned V_10 , unsigned V_11 , T_4 V_313 )
{
unsigned char V_300 ;
for ( V_300 = 0 ; V_300 < V_2 ; V_300 ++ ) {
if ( F_11 ( V_7 , V_10 , V_11 , V_300 ) == V_313 )
return V_300 ;
}
F_6 ( V_7 , L_30 , - V_134 ) ;
return - V_134 ;
}
static void F_178 ( struct V_6 * V_7 )
{
unsigned V_10 , V_11 ;
bool V_314 [ V_2 ] ;
unsigned V_315 [ V_2 ] ;
unsigned V_294 , V_295 ;
unsigned V_316 ;
bool V_317 ;
unsigned char V_318 , V_319 , V_320 ;
if ( V_7 -> V_227 == 'R' )
return;
if ( V_7 -> V_321 )
return;
V_319 = 0 ;
V_294 = 0 ;
if ( ! V_7 -> V_322 ) {
F_179 ( L_31 ) ;
F_64 ( V_7 , V_136 , 0 , 0 , V_7 -> V_31 , NULL ) ;
if ( V_7 -> V_108 )
F_180 ( F_28 ( V_7 -> V_108 [ 0 ] . V_72 ) , 64 , L_32 ) ;
if ( V_7 -> V_108 ) {
struct V_97 V_323 ;
V_323 . V_7 = V_7 ;
V_323 . V_98 = F_67 ( V_323 . V_98 ) ;
V_323 . V_99 = ( V_142 ) F_68 ( 0 ) ;
F_62 ( V_7 , false , 0 , V_7 -> V_31 , & V_323 ) ;
F_56 ( & V_323 . V_98 ) ;
}
F_180 ( F_28 ( V_7 -> V_73 [ 0 ] . V_72 ) , 64 , L_33 ) ;
}
if ( F_9 ( V_7 ) )
goto V_324;
V_317 = true ;
memset ( V_314 , 0 , sizeof V_314 ) ;
memset ( V_315 , 0 , sizeof V_315 ) ;
for ( V_10 = 0 ; V_10 < V_7 -> V_31 ; V_10 ++ ) {
for ( V_11 = 0 ; V_11 < V_7 -> V_61 ; V_11 ++ ) {
int V_300 ;
struct V_67 * V_77 = F_29 ( V_7 , V_10 , V_11 ) ;
V_300 = F_177 ( V_7 , V_10 , V_11 , V_77 -> V_266 ) ;
if ( V_300 < 0 )
goto V_324;
V_314 [ V_300 ] = true ;
V_315 [ V_300 ] = V_10 ;
}
if ( V_317 ) {
for ( V_11 = 0 ; V_11 < V_7 -> V_60 ; V_11 ++ ) {
struct V_74 * V_89 = F_30 ( V_7 , V_10 , V_11 ) ;
if ( ! F_157 ( V_89 ) ) {
V_317 = false ;
break;
}
}
}
}
if ( ! V_314 [ V_2 - 1 ] ) {
V_318 = V_2 - 1 ;
while ( V_318 && ! V_314 [ V_318 - 1 ] )
V_318 -- ;
} else {
for ( V_318 = 0 ; V_318 < V_2 ; V_318 ++ )
if ( ! V_314 [ V_318 ] )
break;
if ( V_318 == V_2 ) {
F_6 ( V_7 , L_34 , - V_134 ) ;
goto V_324;
}
}
F_179 ( L_35 ,
V_318 , V_314 [ 0 ] , V_314 [ 1 ] ,
V_314 [ 2 ] , V_314 [ 3 ] ) ;
V_319 = F_1 ( V_318 ) ;
V_320 = F_1 ( V_319 ) ;
if ( ! V_314 [ V_320 ] && V_314 [ F_1 ( V_320 ) ] )
V_317 = true ;
V_294 = V_315 [ V_319 ] + 1 ;
if ( F_19 ( V_294 >= V_7 -> V_31 ) )
V_320 = F_2 ( V_320 ) ;
F_18 ( V_7 , & V_294 ) ;
V_10 = V_294 ;
for ( V_295 = 0 ; V_295 < V_7 -> V_31 ; V_295 ++ ) {
for ( V_11 = 0 ; V_11 < V_7 -> V_61 ; V_11 ++ ) {
struct V_67 * V_77 = F_29 ( V_7 , V_10 , V_11 ) ;
if ( V_77 -> V_266 != F_11 ( V_7 , V_10 , V_11 , V_320 ) ) {
F_179 ( L_36 ,
V_10 , V_11 , F_177 ( V_7 , V_10 , V_11 , V_77 -> V_266 ) , V_320 ) ;
goto V_325;
}
}
V_10 ++ ;
if ( F_19 ( V_10 >= V_7 -> V_31 ) )
V_320 = F_2 ( V_320 ) ;
F_18 ( V_7 , & V_10 ) ;
}
V_325:
if ( ! V_317 ) {
F_179 ( L_37 ,
V_295 , V_294 , V_320 ) ;
F_169 ( V_7 , V_294 , V_295 , true ) ;
}
if ( V_295 == V_7 -> V_31 && ( V_7 -> V_227 == 'J' || V_317 ) ) {
V_316 = V_294 ;
V_7 -> V_289 = V_320 ;
F_179 ( L_38 , V_294 , V_7 -> V_289 ) ;
} else {
unsigned V_257 ;
unsigned char V_326 ;
V_324:
F_179 ( L_39 ) ;
V_326 = F_1 ( F_1 ( V_319 ) ) ;
V_257 = V_294 ;
F_176 ( V_7 , V_257 , 1 , V_326 ) ;
V_257 ++ ;
F_18 ( V_7 , & V_257 ) ;
if ( V_7 -> V_31 >= 2 ) {
F_176 ( V_7 , V_257 , V_7 -> V_31 - 2 , V_326 ) ;
V_257 += V_7 -> V_31 - 2 ;
F_18 ( V_7 , & V_257 ) ;
F_176 ( V_7 , V_257 , 1 , V_326 ) ;
}
V_316 = 0 ;
V_7 -> V_289 = F_2 ( V_326 ) ;
}
V_7 -> V_173 = V_316 ;
V_7 -> V_174 = 0 ;
V_7 -> V_288 = V_316 ;
V_7 -> V_283 = 0 ;
V_7 -> V_281 = V_316 ;
V_7 -> V_282 = 0 ;
V_7 -> V_267 = V_7 -> V_171 ;
V_7 -> V_163 = V_327 ;
for ( V_10 = 0 ; V_10 < V_7 -> V_171 ; V_10 ++ )
F_82 ( & V_7 -> V_167 [ V_10 ] ) ;
}
static void F_181 ( struct V_243 * V_244 )
{
struct V_6 * V_7 = (struct V_6 * ) V_244 -> V_245 ;
F_182 ( & V_7 -> V_190 ) ;
V_7 -> V_310 = true ;
F_108 ( V_7 -> V_188 , & V_7 -> V_189 ) ;
F_183 ( V_7 -> V_188 ) ;
if ( V_7 -> V_227 == 'J' ) {
F_183 ( V_7 -> V_290 ) ;
F_97 ( V_7 ) ;
}
V_7 -> V_310 = false ;
F_40 ( ! F_184 ( & V_7 -> V_152 ) ) ;
V_7 -> V_321 = true ;
}
static void F_185 ( struct V_243 * V_244 )
{
struct V_6 * V_7 = (struct V_6 * ) V_244 -> V_245 ;
F_178 ( V_7 ) ;
}
static void F_186 ( struct V_243 * V_244 , T_7 type ,
unsigned V_328 , char * V_28 , unsigned V_329 )
{
struct V_6 * V_7 = (struct V_6 * ) V_244 -> V_245 ;
unsigned V_330 ;
T_2 V_331 = 0 ;
switch ( type ) {
case V_332 :
V_28 [ 0 ] = '\0' ;
break;
case V_333 : {
V_13 V_334 = ( V_13 ) ( V_7 -> V_171 - V_7 -> V_268 ) * 100 ;
V_334 += V_7 -> V_171 / 2 ;
F_187 ( V_334 , V_7 -> V_171 ) ;
V_330 = 5 ;
V_330 += V_7 -> V_148 != 1 ;
V_330 += ! ! V_7 -> V_335 . V_336 ;
V_330 += ! ! V_7 -> V_337 . V_336 ;
V_330 += ! ! V_7 -> V_338 . V_336 ;
F_188 ( L_40 , V_7 -> V_49 -> V_339 , ( unsigned long long ) V_7 -> V_51 ,
V_7 -> V_27 , V_7 -> V_227 , V_330 ) ;
F_188 ( L_41 , V_7 -> V_29 - V_53 ) ;
F_188 ( L_42 , 1U << V_7 -> V_18 -> V_17 ) ;
F_188 ( L_43 , 1U << V_7 -> V_24 ) ;
F_188 ( L_44 , ( unsigned ) V_334 ) ;
F_188 ( L_45 , V_7 -> V_340 ) ;
if ( V_7 -> V_148 != 1 )
F_188 ( L_46 , V_7 -> V_148 << V_26 ) ;
#define F_189 ( T_8 , V_75 ) \
do { \
if (ic->a.alg_string) { \
DMEMIT(" %s:%s", n, ic->a.alg_string); \
if (ic->a.key_string) \
DMEMIT(":%s", ic->a.key_string);\
} \
} while (0)
F_189 ( V_335 , L_47 ) ;
F_189 ( V_337 , L_48 ) ;
F_189 ( V_338 , L_49 ) ;
break;
}
}
}
static int F_190 ( struct V_243 * V_244 ,
T_9 V_45 , void * V_117 )
{
struct V_6 * V_7 = V_244 -> V_245 ;
return V_45 ( V_244 , V_7 -> V_49 , V_7 -> V_51 + V_7 -> V_29 + V_7 -> V_23 , V_244 -> V_4 , V_117 ) ;
}
static void F_191 ( struct V_243 * V_244 , struct V_341 * V_342 )
{
struct V_6 * V_7 = V_244 -> V_245 ;
if ( V_7 -> V_148 > 1 ) {
V_342 -> V_343 = V_7 -> V_148 << V_26 ;
V_342 -> V_344 = V_7 -> V_148 << V_26 ;
F_192 ( V_342 , V_7 -> V_148 << V_26 ) ;
}
}
static void F_193 ( struct V_6 * V_7 )
{
unsigned V_345 = V_259 ;
V_7 -> V_31 = F_194 ( V_7 -> V_18 -> V_31 ) ;
V_7 -> V_79 = F_46 ( F_195 ( struct V_74 , V_260 [ V_7 -> V_148 ] ) + V_7 -> V_27 ,
V_346 ) ;
if ( V_7 -> V_18 -> V_87 & F_196 ( V_347 ) )
V_345 -= V_94 ;
V_7 -> V_348 = V_345 / V_7 -> V_79 ;
V_7 -> V_60 = V_7 -> V_348 * V_78 ;
V_7 -> V_61 = ( V_7 -> V_60 << V_7 -> V_18 -> V_80 ) + V_78 ;
V_7 -> V_171 = V_7 -> V_60 * V_7 -> V_31 ;
}
static int F_197 ( struct V_6 * V_7 )
{
V_13 V_29 ;
T_5 V_349 , V_350 , V_351 ;
F_193 ( V_7 ) ;
V_29 = V_53 + ( V_13 ) V_7 -> V_61 * V_7 -> V_31 ;
if ( V_29 + V_352 >= V_7 -> V_353 || V_29 > V_354 )
return - V_355 ;
V_7 -> V_29 = V_29 ;
V_7 -> V_23 = F_46 ( ( V_13 ) V_7 -> V_27 << ( V_7 -> V_18 -> V_17 - V_7 -> V_18 -> V_80 ) ,
( V_13 ) ( 1 << V_26 << V_352 ) ) >> V_26 ;
if ( ! ( V_7 -> V_23 & ( V_7 -> V_23 - 1 ) ) )
V_7 -> V_22 = F_198 ( V_7 -> V_23 ) ;
else
V_7 -> V_22 = - 1 ;
F_13 ( V_7 , V_7 -> V_249 - 1 , & V_350 , & V_351 ) ;
V_349 = F_17 ( V_7 , V_350 , V_351 ) ;
if ( V_7 -> V_51 + V_349 < V_349 || V_7 -> V_51 + V_349 >= V_7 -> V_353 )
return - V_355 ;
return 0 ;
}
static int F_199 ( struct V_6 * V_7 , unsigned V_356 , unsigned V_357 )
{
unsigned V_31 ;
int V_358 ;
memset ( V_7 -> V_18 , 0 , V_53 << V_26 ) ;
memcpy ( V_7 -> V_18 -> V_359 , V_360 , 8 ) ;
V_7 -> V_18 -> V_361 = V_362 ;
V_7 -> V_18 -> V_363 = F_200 ( V_7 -> V_27 ) ;
V_7 -> V_18 -> V_80 = F_198 ( V_7 -> V_148 ) ;
if ( V_7 -> V_338 . V_336 )
V_7 -> V_18 -> V_87 |= F_196 ( V_347 ) ;
F_193 ( V_7 ) ;
V_31 = V_356 / V_7 -> V_61 ;
if ( ! V_31 )
V_31 = 1 ;
V_7 -> V_18 -> V_31 = F_196 ( V_31 ) ;
if ( ! V_357 )
V_357 = V_364 ;
V_7 -> V_18 -> V_17 = F_201 ( V_357 ) ;
V_7 -> V_18 -> V_17 = F_149 ( ( T_1 ) V_365 , V_7 -> V_18 -> V_17 ) ;
V_7 -> V_18 -> V_17 = F_48 ( ( T_1 ) V_366 , V_7 -> V_18 -> V_17 ) ;
V_7 -> V_249 = 0 ;
for ( V_358 = F_202 ( V_7 -> V_353 ) - 1 ; V_358 >= 3 ; V_358 -- ) {
V_13 V_367 = V_7 -> V_249 ;
V_7 -> V_249 |= ( T_5 ) 1 << V_358 ;
if ( F_197 ( V_7 ) )
V_7 -> V_249 = V_367 ;
}
if ( ! V_7 -> V_249 )
return - V_355 ;
V_7 -> V_18 -> V_249 = F_12 ( V_7 -> V_249 ) ;
return 0 ;
}
static void F_203 ( struct V_243 * V_244 , struct V_6 * V_7 )
{
struct V_368 * V_369 = F_204 ( F_205 ( V_244 -> V_370 ) ) ;
struct V_371 V_372 ;
memset ( & V_372 , 0 , sizeof( V_372 ) ) ;
V_372 . V_373 = & V_374 ;
V_372 . V_375 = V_7 -> V_27 ;
V_372 . V_27 = V_372 . V_375 ;
V_372 . V_376 = V_7 -> V_18 -> V_80 + V_26 ;
F_206 ( V_369 , & V_372 ) ;
F_207 ( V_369 -> V_377 , V_354 ) ;
}
static void F_208 ( struct V_6 * V_7 , struct V_68 * V_69 )
{
unsigned V_10 ;
if ( ! V_69 )
return;
for ( V_10 = 0 ; V_10 < V_7 -> V_378 ; V_10 ++ )
if ( V_69 [ V_10 ] . V_72 )
F_209 ( V_69 [ V_10 ] . V_72 ) ;
F_210 ( V_69 ) ;
}
static struct V_68 * F_211 ( struct V_6 * V_7 )
{
T_2 V_379 = V_7 -> V_378 * sizeof( struct V_68 ) ;
struct V_68 * V_69 ;
unsigned V_10 ;
V_69 = F_212 ( V_379 , V_380 | V_381 ) ;
if ( ! V_69 )
return NULL ;
for ( V_10 = 0 ; V_10 < V_7 -> V_378 ; V_10 ++ ) {
V_69 [ V_10 ] . V_72 = F_213 ( V_380 ) ;
if ( ! V_69 [ V_10 ] . V_72 ) {
F_208 ( V_7 , V_69 ) ;
return NULL ;
}
if ( V_10 )
V_69 [ V_10 - 1 ] . V_170 = & V_69 [ V_10 ] ;
}
return V_69 ;
}
static void F_214 ( struct V_6 * V_7 , struct V_123 * * V_382 )
{
unsigned V_10 ;
for ( V_10 = 0 ; V_10 < V_7 -> V_31 ; V_10 ++ )
F_210 ( V_382 [ V_10 ] ) ;
F_132 ( V_382 ) ;
}
static struct V_123 * * F_215 ( struct V_6 * V_7 , struct V_68 * V_69 )
{
struct V_123 * * V_382 ;
unsigned V_10 ;
V_382 = F_212 ( V_7 -> V_31 * sizeof( struct V_123 * ) , V_380 | V_381 ) ;
if ( ! V_382 )
return NULL ;
for ( V_10 = 0 ; V_10 < V_7 -> V_31 ; V_10 ++ ) {
struct V_123 * V_257 ;
unsigned V_383 , V_384 ;
unsigned V_385 , V_386 ;
unsigned V_387 ;
unsigned V_388 ;
F_26 ( V_7 , V_10 , 0 , & V_383 , & V_384 ) ;
F_26 ( V_7 , V_10 , V_7 -> V_61 - 1 , & V_385 , & V_386 ) ;
V_387 = ( V_385 - V_383 + 1 ) ;
V_257 = F_212 ( V_387 * sizeof( struct V_123 ) , V_380 ) ;
if ( ! V_257 ) {
F_214 ( V_7 , V_382 ) ;
return NULL ;
}
F_216 ( V_257 , V_387 ) ;
for ( V_388 = V_383 ; V_388 <= V_385 ; V_388 ++ ) {
char * V_71 = F_28 ( V_69 [ V_388 ] . V_72 ) ;
unsigned V_51 = 0 , V_389 = V_66 ;
if ( V_388 == V_383 )
V_51 = V_384 ;
if ( V_388 == V_385 )
V_389 = V_386 + ( 1 << V_26 ) ;
F_217 ( & V_257 [ V_388 - V_383 ] , V_71 + V_51 , V_389 - V_51 ) ;
}
V_382 [ V_10 ] = V_257 ;
}
return V_382 ;
}
static void F_218 ( struct V_390 * T_8 )
{
F_219 ( T_8 -> V_336 ) ;
F_219 ( T_8 -> V_391 ) ;
memset ( T_8 , 0 , sizeof *T_8 ) ;
}
static int F_220 ( const char * V_392 , struct V_390 * T_8 , char * * error , char * V_393 )
{
char * V_300 ;
F_218 ( T_8 ) ;
T_8 -> V_336 = F_221 ( strchr ( V_392 , ':' ) + 1 , V_380 ) ;
if ( ! T_8 -> V_336 )
goto V_394;
V_300 = strchr ( T_8 -> V_336 , ':' ) ;
if ( V_300 ) {
* V_300 = 0 ;
T_8 -> V_395 = V_300 + 1 ;
if ( strlen ( T_8 -> V_395 ) & 1 )
goto V_396;
T_8 -> V_397 = strlen ( T_8 -> V_395 ) / 2 ;
T_8 -> V_391 = F_128 ( T_8 -> V_397 , V_380 ) ;
if ( ! T_8 -> V_391 )
goto V_394;
if ( F_222 ( T_8 -> V_391 , T_8 -> V_395 , T_8 -> V_397 ) )
goto V_396;
}
return 0 ;
V_396:
* error = V_393 ;
return - V_355 ;
V_394:
* error = L_50 ;
return - V_398 ;
}
static int F_223 ( struct V_399 * * V_400 , struct V_390 * T_8 , char * * error ,
char * V_401 , char * V_402 )
{
int V_84 ;
if ( T_8 -> V_336 ) {
* V_400 = F_224 ( T_8 -> V_336 , 0 , V_403 ) ;
if ( F_93 ( * V_400 ) ) {
* error = V_401 ;
V_84 = F_94 ( * V_400 ) ;
* V_400 = NULL ;
return V_84 ;
}
if ( T_8 -> V_391 ) {
V_84 = F_225 ( * V_400 , T_8 -> V_391 , T_8 -> V_397 ) ;
if ( V_84 ) {
* error = V_402 ;
return V_84 ;
}
}
}
return 0 ;
}
static int F_226 ( struct V_6 * V_7 , char * * error )
{
int V_84 = 0 ;
unsigned V_10 ;
V_13 V_378 , V_404 , V_405 ;
unsigned char * V_406 = NULL ;
V_7 -> V_12 [ 0 ] = F_12 ( 0x1111111111111111ULL ) ;
V_7 -> V_12 [ 1 ] = F_12 ( 0x2222222222222222ULL ) ;
V_7 -> V_12 [ 2 ] = F_12 ( 0x3333333333333333ULL ) ;
V_7 -> V_12 [ 3 ] = F_12 ( 0x4444444444444444ULL ) ;
V_378 = F_46 ( ( V_13 ) V_7 -> V_31 * V_7 -> V_61 ,
V_66 >> V_26 ) >> ( V_65 - V_26 ) ;
V_404 = V_378 * sizeof( struct V_68 ) ;
if ( V_378 >= V_407 - V_408 || V_404 > V_409 ) {
* error = L_51 ;
V_84 = - V_398 ;
goto V_410;
}
V_7 -> V_378 = V_378 ;
V_7 -> V_73 = F_211 ( V_7 ) ;
if ( ! V_7 -> V_73 ) {
* error = L_52 ;
V_84 = - V_398 ;
goto V_410;
}
if ( V_7 -> V_337 . V_336 ) {
unsigned V_128 , V_411 ;
struct V_97 V_98 ;
V_98 . V_7 = V_7 ;
V_7 -> V_131 = F_227 ( V_7 -> V_337 . V_336 , 0 , 0 ) ;
if ( F_93 ( V_7 -> V_131 ) ) {
* error = L_53 ;
V_84 = F_94 ( V_7 -> V_131 ) ;
V_7 -> V_131 = NULL ;
goto V_410;
}
V_128 = F_59 ( V_7 -> V_131 ) ;
V_411 = F_228 ( V_7 -> V_131 ) ;
if ( V_7 -> V_337 . V_391 ) {
V_84 = F_229 ( V_7 -> V_131 , V_7 -> V_337 . V_391 ,
V_7 -> V_337 . V_397 ) ;
if ( V_84 ) {
* error = L_54 ;
goto V_410;
}
}
F_179 ( L_55 ,
V_7 -> V_337 . V_336 , V_411 , V_128 ) ;
V_7 -> V_108 = F_211 ( V_7 ) ;
if ( ! V_7 -> V_108 ) {
* error = L_56 ;
V_84 = - V_398 ;
goto V_410;
}
if ( V_411 == 1 ) {
struct V_123 * V_412 ;
F_230 ( V_116 , V_7 -> V_131 ) ;
unsigned char V_129 [ V_128 ] ;
F_231 ( V_116 , V_7 -> V_131 ) ;
V_7 -> V_114 = F_211 ( V_7 ) ;
if ( ! V_7 -> V_114 ) {
* error = L_57 ;
V_84 = - V_398 ;
goto V_410;
}
V_412 = F_212 ( ( V_7 -> V_378 + 1 ) * sizeof( struct V_123 ) , V_380 ) ;
if ( ! V_412 ) {
* error = L_58 ;
V_84 = - V_398 ;
goto V_410;
}
F_216 ( V_412 , V_7 -> V_378 + 1 ) ;
for ( V_10 = 0 ; V_10 < V_7 -> V_378 ; V_10 ++ ) {
char * V_71 = F_28 ( V_7 -> V_114 [ V_10 ] . V_72 ) ;
F_232 ( V_71 ) ;
F_217 ( & V_412 [ V_10 ] , V_71 , V_66 ) ;
}
F_217 ( & V_412 [ V_10 ] , & V_7 -> V_12 , sizeof V_7 -> V_12 ) ;
memset ( V_129 , 0x00 , V_128 ) ;
F_233 ( V_116 , V_412 , V_412 , V_66 * V_7 -> V_378 + sizeof V_7 -> V_12 , V_129 ) ;
V_98 . V_98 = F_67 ( V_98 . V_98 ) ;
V_98 . V_99 = ( V_142 ) F_68 ( 1 ) ;
if ( F_52 ( true , V_116 , & V_98 ) )
F_56 ( & V_98 . V_98 ) ;
F_210 ( V_412 ) ;
V_84 = F_9 ( V_7 ) ;
if ( V_84 ) {
* error = L_59 ;
goto V_410;
}
F_180 ( F_28 ( V_7 -> V_114 [ 0 ] . V_72 ) , 64 , L_60 ) ;
F_234 ( V_7 -> V_131 ) ;
V_7 -> V_131 = NULL ;
} else {
F_230 ( V_116 , V_7 -> V_131 ) ;
unsigned char V_129 [ V_128 ] ;
unsigned V_413 = F_46 ( V_128 , V_411 ) ;
V_406 = F_128 ( V_413 , V_380 ) ;
if ( ! V_406 ) {
* error = L_61 ;
V_84 = - V_398 ;
goto V_410;
}
F_231 ( V_116 , V_7 -> V_131 ) ;
V_7 -> V_126 = F_215 ( V_7 , V_7 -> V_73 ) ;
if ( ! V_7 -> V_126 ) {
* error = L_58 ;
V_84 = - V_398 ;
goto V_410;
}
V_7 -> V_127 = F_215 ( V_7 , V_7 -> V_108 ) ;
if ( ! V_7 -> V_127 ) {
* error = L_58 ;
V_84 = - V_398 ;
goto V_410;
}
V_7 -> V_130 = F_212 ( V_7 -> V_31 * sizeof( struct V_120 * ) , V_380 | V_381 ) ;
if ( ! V_7 -> V_130 ) {
* error = L_62 ;
V_84 = - V_398 ;
goto V_410;
}
for ( V_10 = 0 ; V_10 < V_7 -> V_31 ; V_10 ++ ) {
struct V_123 V_412 ;
struct V_120 * V_414 ;
T_10 V_415 = F_196 ( V_10 ) ;
memset ( V_129 , 0x00 , V_128 ) ;
memset ( V_406 , 0x00 , V_413 ) ;
memcpy ( V_406 , & V_415 , F_48 ( ( T_2 ) V_413 , sizeof( V_415 ) ) ) ;
F_235 ( & V_412 , V_406 , V_413 ) ;
F_233 ( V_116 , & V_412 , & V_412 , V_413 , V_129 ) ;
V_98 . V_98 = F_67 ( V_98 . V_98 ) ;
V_98 . V_99 = ( V_142 ) F_68 ( 1 ) ;
if ( F_52 ( true , V_116 , & V_98 ) )
F_56 ( & V_98 . V_98 ) ;
V_84 = F_9 ( V_7 ) ;
if ( V_84 ) {
* error = L_63 ;
goto V_410;
}
V_414 = F_236 ( V_7 -> V_131 , V_380 ) ;
if ( ! V_414 ) {
* error = L_64 ;
V_84 = - V_398 ;
goto V_410;
}
V_414 -> V_129 = F_128 ( V_128 * 2 , V_380 ) ;
if ( ! V_414 -> V_129 ) {
F_237 ( V_414 ) ;
* error = L_65 ;
V_84 = - V_398 ;
goto V_410;
}
memcpy ( V_414 -> V_129 + V_128 , V_406 , V_128 ) ;
V_414 -> V_416 = ( T_2 ) V_7 -> V_61 << V_26 ;
V_7 -> V_130 [ V_10 ] = V_414 ;
F_180 ( V_406 , V_128 , L_66 , V_10 ) ;
}
}
}
for ( V_10 = 0 ; V_10 < V_2 ; V_10 ++ ) {
unsigned V_11 ;
V_417:
for ( V_11 = 0 ; V_11 < V_10 ; V_11 ++ ) {
if ( V_7 -> V_12 [ V_11 ] == V_7 -> V_12 [ V_10 ] ) {
V_7 -> V_12 [ V_10 ] = F_12 ( F_238 ( V_7 -> V_12 [ V_10 ] ) + 1 ) ;
goto V_417;
}
}
F_179 ( L_67 , V_10 , V_7 -> V_12 [ V_10 ] ) ;
}
V_405 = ( V_13 ) V_7 -> V_171 * sizeof( struct V_161 ) ;
if ( V_405 > V_409 ) {
* error = L_51 ;
V_84 = - V_398 ;
goto V_410;
}
V_7 -> V_167 = F_212 ( V_405 , V_380 ) ;
if ( ! V_7 -> V_167 ) {
* error = L_68 ;
V_84 = - V_398 ;
}
V_410:
F_132 ( V_406 ) ;
return V_84 ;
}
static int F_239 ( struct V_243 * V_244 , unsigned V_418 , char * * V_419 )
{
struct V_6 * V_7 ;
char V_113 ;
int V_84 ;
unsigned V_420 ;
struct V_421 V_422 ;
static struct V_423 V_424 [] = {
{ 0 , 9 , L_69 } ,
} ;
unsigned V_356 , V_357 , V_425 , V_426 , V_427 ;
bool V_428 ;
V_13 V_429 ;
unsigned long long V_51 ;
#define F_240 4
if ( V_418 <= F_240 ) {
V_244 -> error = L_70 ;
return - V_355 ;
}
V_7 = F_241 ( sizeof( struct V_6 ) , V_380 ) ;
if ( ! V_7 ) {
V_244 -> error = L_71 ;
return - V_398 ;
}
V_244 -> V_245 = V_7 ;
V_244 -> V_430 = sizeof( struct V_193 ) ;
V_7 -> V_152 = V_327 ;
F_242 ( & V_7 -> V_159 ) ;
F_243 ( & V_7 -> V_196 ) ;
F_242 ( & V_7 -> V_258 ) ;
F_244 ( & V_7 -> V_119 ) ;
V_84 = F_245 ( V_244 , V_419 [ 0 ] , F_246 ( V_244 -> V_370 ) , & V_7 -> V_49 ) ;
if ( V_84 ) {
V_244 -> error = L_72 ;
goto V_410;
}
if ( sscanf ( V_419 [ 1 ] , L_73 , & V_51 , & V_113 ) != 1 || V_51 != ( T_5 ) V_51 ) {
V_244 -> error = L_74 ;
V_84 = - V_355 ;
goto V_410;
}
V_7 -> V_51 = V_51 ;
if ( strcmp ( V_419 [ 2 ] , L_75 ) ) {
if ( sscanf ( V_419 [ 2 ] , L_76 , & V_7 -> V_27 , & V_113 ) != 1 || ! V_7 -> V_27 ) {
V_244 -> error = L_77 ;
V_84 = - V_355 ;
goto V_410;
}
}
if ( ! strcmp ( V_419 [ 3 ] , L_78 ) || ! strcmp ( V_419 [ 3 ] , L_79 ) || ! strcmp ( V_419 [ 3 ] , L_80 ) )
V_7 -> V_227 = V_419 [ 3 ] [ 0 ] ;
else {
V_244 -> error = L_81 ;
V_84 = - V_355 ;
goto V_410;
}
V_7 -> V_353 = F_247 ( V_7 -> V_49 -> V_48 -> V_431 ) >> V_26 ;
V_356 = F_48 ( ( T_5 ) V_432 ,
V_7 -> V_353 >> V_433 ) ;
V_357 = V_364 ;
V_425 = V_434 ;
V_426 = V_435 ;
V_427 = V_436 ;
V_7 -> V_148 = 1 ;
V_422 . V_418 = V_418 - F_240 ;
V_422 . V_419 = V_419 + F_240 ;
V_84 = F_248 ( V_424 , & V_422 , & V_420 , & V_244 -> error ) ;
if ( V_84 )
goto V_410;
while ( V_420 -- ) {
const char * V_437 ;
unsigned V_438 ;
V_437 = F_249 ( & V_422 ) ;
if ( ! V_437 ) {
V_84 = - V_355 ;
V_244 -> error = L_82 ;
goto V_410;
}
if ( sscanf ( V_437 , L_83 , & V_438 , & V_113 ) == 1 )
V_356 = V_438 ;
else if ( sscanf ( V_437 , L_84 , & V_438 , & V_113 ) == 1 )
V_357 = V_438 ;
else if ( sscanf ( V_437 , L_85 , & V_438 , & V_113 ) == 1 )
V_425 = V_438 ;
else if ( sscanf ( V_437 , L_86 , & V_438 , & V_113 ) == 1 && V_438 <= 100 )
V_426 = V_438 ;
else if ( sscanf ( V_437 , L_87 , & V_438 , & V_113 ) == 1 )
V_427 = V_438 ;
else if ( sscanf ( V_437 , L_88 , & V_438 , & V_113 ) == 1 ) {
if ( V_438 < 1 << V_26 ||
V_438 > V_439 << V_26 ||
( V_438 & ( V_438 - 1 ) ) ) {
V_84 = - V_355 ;
V_244 -> error = L_89 ;
goto V_410;
}
V_7 -> V_148 = V_438 >> V_26 ;
} else if ( ! memcmp ( V_437 , L_90 , strlen ( L_90 ) ) ) {
V_84 = F_220 ( V_437 , & V_7 -> V_335 , & V_244 -> error ,
L_91 ) ;
if ( V_84 )
goto V_410;
} else if ( ! memcmp ( V_437 , L_92 , strlen ( L_92 ) ) ) {
V_84 = F_220 ( V_437 , & V_7 -> V_337 , & V_244 -> error ,
L_93 ) ;
if ( V_84 )
goto V_410;
} else if ( ! memcmp ( V_437 , L_94 , strlen ( L_94 ) ) ) {
V_84 = F_220 ( V_437 , & V_7 -> V_338 , & V_244 -> error ,
L_95 ) ;
if ( V_84 )
goto V_410;
} else {
V_84 = - V_355 ;
V_244 -> error = L_96 ;
goto V_410;
}
}
V_84 = F_223 ( & V_7 -> V_215 , & V_7 -> V_335 , & V_244 -> error ,
L_97 , L_98 ) ;
if ( V_84 )
goto V_410;
V_84 = F_223 ( & V_7 -> V_83 , & V_7 -> V_338 , & V_244 -> error ,
L_99 , L_100 ) ;
if ( V_84 )
goto V_410;
if ( ! V_7 -> V_27 ) {
if ( ! V_7 -> V_215 ) {
V_244 -> error = L_101 ;
V_84 = - V_355 ;
goto V_410;
}
V_7 -> V_27 = F_36 ( V_7 -> V_215 ) ;
}
if ( V_7 -> V_27 > V_440 ) {
V_244 -> error = L_102 ;
V_84 = - V_355 ;
goto V_410;
}
if ( ! ( V_7 -> V_27 & ( V_7 -> V_27 - 1 ) ) )
V_7 -> V_25 = F_198 ( V_7 -> V_27 ) ;
else
V_7 -> V_25 = - 1 ;
V_7 -> V_192 = F_250 ( V_427 ) ;
V_7 -> V_340 = V_427 ;
F_251 ( & V_7 -> V_190 , F_107 , ( unsigned long ) V_7 ) ;
V_7 -> V_47 = F_252 () ;
if ( F_93 ( V_7 -> V_47 ) ) {
V_84 = F_94 ( V_7 -> V_47 ) ;
V_7 -> V_47 = NULL ;
V_244 -> error = L_103 ;
goto V_410;
}
V_7 -> V_293 = F_253 ( V_441 , V_442 ) ;
if ( ! V_7 -> V_293 ) {
V_84 = - V_398 ;
V_244 -> error = L_104 ;
goto V_410;
}
V_7 -> V_273 = F_254 ( L_105 ,
V_443 , V_444 ) ;
if ( ! V_7 -> V_273 ) {
V_244 -> error = L_106 ;
V_84 = - V_398 ;
goto V_410;
}
V_7 -> V_202 = F_254 ( L_107 , V_443 | V_445 , 1 ) ;
if ( ! V_7 -> V_202 ) {
V_244 -> error = L_106 ;
V_84 = - V_398 ;
goto V_410;
}
V_7 -> V_188 = F_254 ( L_108 , V_443 , 1 ) ;
if ( ! V_7 -> V_188 ) {
V_244 -> error = L_106 ;
V_84 = - V_398 ;
goto V_410;
}
F_122 ( & V_7 -> V_189 , F_162 ) ;
if ( V_7 -> V_227 == 'J' ) {
V_7 -> V_290 = F_254 ( L_109 , V_443 , 1 ) ;
if ( ! V_7 -> V_290 ) {
V_244 -> error = L_106 ;
V_84 = - V_398 ;
goto V_410;
}
F_122 ( & V_7 -> V_291 , F_175 ) ;
}
V_7 -> V_18 = F_255 ( V_53 << V_26 , V_380 ) ;
if ( ! V_7 -> V_18 ) {
V_84 = - V_398 ;
V_244 -> error = L_110 ;
goto V_410;
}
V_84 = F_20 ( V_7 , V_136 , 0 ) ;
if ( V_84 ) {
V_244 -> error = L_111 ;
goto V_410;
}
V_428 = false ;
if ( memcmp ( V_7 -> V_18 -> V_359 , V_360 , 8 ) ) {
if ( V_7 -> V_227 != 'R' ) {
if ( F_256 ( V_7 -> V_18 , 0 , V_53 << V_26 ) ) {
V_84 = - V_355 ;
V_244 -> error = L_112 ;
goto V_410;
}
}
V_84 = F_199 ( V_7 , V_356 , V_357 ) ;
if ( V_84 ) {
V_244 -> error = L_113 ;
goto V_410;
}
if ( V_7 -> V_227 != 'R' )
V_428 = true ;
}
if ( V_7 -> V_18 -> V_361 != V_362 ) {
V_84 = - V_355 ;
V_244 -> error = L_114 ;
goto V_410;
}
if ( F_257 ( V_7 -> V_18 -> V_363 ) != V_7 -> V_27 ) {
V_84 = - V_355 ;
V_244 -> error = L_115 ;
goto V_410;
}
if ( V_7 -> V_18 -> V_80 != F_198 ( V_7 -> V_148 ) ) {
V_84 = - V_355 ;
V_244 -> error = L_116 ;
goto V_410;
}
if ( ! F_194 ( V_7 -> V_18 -> V_31 ) ) {
V_84 = - V_355 ;
V_244 -> error = L_117 ;
goto V_410;
}
if ( V_7 -> V_18 -> V_17 < V_365 ||
V_7 -> V_18 -> V_17 > V_366 ) {
V_84 = - V_355 ;
V_244 -> error = L_118 ;
goto V_410;
}
V_7 -> V_249 = F_238 ( V_7 -> V_18 -> V_249 ) ;
if ( V_7 -> V_249 != F_238 ( V_7 -> V_18 -> V_249 ) ) {
V_84 = - V_355 ;
V_244 -> error = L_119 ;
goto V_410;
}
if ( ! ! ( V_7 -> V_18 -> V_87 & F_196 ( V_347 ) ) != ! ! V_7 -> V_338 . V_336 ) {
V_84 = - V_355 ;
V_244 -> error = L_120 ;
goto V_410;
}
V_84 = F_197 ( V_7 ) ;
if ( V_84 ) {
V_244 -> error = L_121 ;
goto V_410;
}
if ( V_244 -> V_4 > V_7 -> V_249 ) {
V_84 = - V_355 ;
V_244 -> error = L_122 ;
goto V_410;
}
if ( ! V_425 )
V_425 = 1 ;
V_7 -> V_24 = F_258 ( ( int ) F_201 ( V_425 ) , ( int ) F_198 ( V_7 -> V_23 ) , 31 - V_26 ) ;
V_429 = ( V_13 ) V_7 -> V_171 * ( 100 - V_426 ) ;
V_429 += 50 ;
F_187 ( V_429 , 100 ) ;
V_7 -> V_268 = V_429 ;
F_179 ( L_123 ) ;
F_179 ( L_124 , F_257 ( V_7 -> V_18 -> V_363 ) ) ;
F_179 ( L_125 , V_7 -> V_79 ) ;
F_179 ( L_126 , V_7 -> V_348 ) ;
F_179 ( L_127 , V_7 -> V_60 ) ;
F_179 ( L_128 , V_7 -> V_61 ) ;
F_179 ( L_129 , ( unsigned ) F_194 ( V_7 -> V_18 -> V_31 ) ) ;
F_179 ( L_130 , V_7 -> V_171 ) ;
F_179 ( L_131 , V_7 -> V_18 -> V_17 ) ;
F_179 ( L_132 , ( unsigned long long ) V_7 -> V_353 ) ;
F_179 ( L_133 , V_7 -> V_29 ) ;
F_179 ( L_134 , V_7 -> V_23 ) ;
F_179 ( L_135 , V_7 -> V_22 ) ;
F_179 ( L_136 , ( unsigned long long ) V_7 -> V_249 ,
( unsigned long long ) V_7 -> V_249 ) ;
F_179 ( L_137 , V_7 -> V_24 ) ;
V_7 -> V_182 = F_259 ( V_7 -> V_49 -> V_48 , 1U << ( V_26 + V_7 -> V_24 ) ,
1 , 0 , NULL , NULL ) ;
if ( F_93 ( V_7 -> V_182 ) ) {
V_84 = F_94 ( V_7 -> V_182 ) ;
V_244 -> error = L_138 ;
V_7 -> V_182 = NULL ;
goto V_410;
}
F_260 ( V_7 -> V_182 , V_7 -> V_51 + V_7 -> V_29 ) ;
if ( V_7 -> V_227 != 'R' ) {
V_84 = F_226 ( V_7 , & V_244 -> error ) ;
if ( V_84 )
goto V_410;
}
if ( V_428 ) {
int V_84 ;
F_176 ( V_7 , 0 , V_7 -> V_31 , 0 ) ;
V_84 = F_9 ( V_7 ) ;
if ( F_19 ( V_84 ) ) {
V_244 -> error = L_139 ;
goto V_410;
}
V_84 = F_20 ( V_7 , V_143 , V_144 ) ;
if ( V_84 ) {
V_244 -> error = L_140 ;
goto V_410;
}
V_7 -> V_322 = true ;
}
V_84 = F_261 ( V_244 , 1U << V_7 -> V_18 -> V_17 ) ;
if ( V_84 )
goto V_410;
if ( ! V_7 -> V_215 )
F_203 ( V_244 , V_7 ) ;
V_244 -> V_446 = 1 ;
V_244 -> V_447 = true ;
return 0 ;
V_410:
F_262 ( V_244 ) ;
return V_84 ;
}
static void F_262 ( struct V_243 * V_244 )
{
struct V_6 * V_7 = V_244 -> V_245 ;
F_40 ( ! F_184 ( & V_7 -> V_152 ) ) ;
if ( V_7 -> V_273 )
F_263 ( V_7 -> V_273 ) ;
if ( V_7 -> V_202 )
F_263 ( V_7 -> V_202 ) ;
if ( V_7 -> V_188 )
F_263 ( V_7 -> V_188 ) ;
if ( V_7 -> V_290 )
F_263 ( V_7 -> V_290 ) ;
if ( V_7 -> V_182 )
F_264 ( V_7 -> V_182 ) ;
F_265 ( V_7 -> V_293 ) ;
if ( V_7 -> V_47 )
F_266 ( V_7 -> V_47 ) ;
if ( V_7 -> V_49 )
F_267 ( V_244 , V_7 -> V_49 ) ;
F_208 ( V_7 , V_7 -> V_73 ) ;
F_208 ( V_7 , V_7 -> V_108 ) ;
F_208 ( V_7 , V_7 -> V_114 ) ;
if ( V_7 -> V_126 )
F_214 ( V_7 , V_7 -> V_126 ) ;
if ( V_7 -> V_127 )
F_214 ( V_7 , V_7 -> V_127 ) ;
if ( V_7 -> V_130 ) {
unsigned V_10 ;
for ( V_10 = 0 ; V_10 < V_7 -> V_31 ; V_10 ++ ) {
struct V_120 * V_116 = V_7 -> V_130 [ V_10 ] ;
if ( V_116 ) {
F_219 ( V_116 -> V_129 ) ;
F_237 ( V_116 ) ;
}
}
F_210 ( V_7 -> V_130 ) ;
}
F_210 ( V_7 -> V_167 ) ;
if ( V_7 -> V_18 )
F_268 ( V_7 -> V_18 , V_53 << V_26 ) ;
if ( V_7 -> V_215 )
F_269 ( V_7 -> V_215 ) ;
F_218 ( & V_7 -> V_335 ) ;
if ( V_7 -> V_131 )
F_234 ( V_7 -> V_131 ) ;
F_218 ( & V_7 -> V_337 ) ;
if ( V_7 -> V_83 )
F_269 ( V_7 -> V_83 ) ;
F_218 ( & V_7 -> V_338 ) ;
F_132 ( V_7 ) ;
}
int T_11 F_270 ( void )
{
int V_84 ;
V_442 = F_271 ( L_141 ,
sizeof( struct V_108 ) , 0 , 0 , NULL ) ;
if ( ! V_442 ) {
F_8 ( L_142 ) ;
return - V_398 ;
}
V_84 = F_272 ( & V_448 ) ;
if ( V_84 < 0 )
F_8 ( L_143 , V_84 ) ;
return V_84 ;
}
void F_273 ( void )
{
F_274 ( & V_448 ) ;
F_275 ( V_442 ) ;
}
