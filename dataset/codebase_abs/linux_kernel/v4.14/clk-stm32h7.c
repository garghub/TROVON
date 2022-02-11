static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_6 = F_3 ( V_4 ) ;
int V_7 ;
unsigned int V_8 = V_9 ;
if ( V_10 . V_11 ( V_2 ) )
return 0 ;
V_10 . V_12 ( V_2 ) ;
do {
V_7 = ! ( F_4 ( V_4 -> V_13 ) & F_5 ( V_6 -> V_14 ) ) ;
if ( V_7 )
F_6 ( 100 ) ;
} while ( V_7 && -- V_8 );
return V_7 ;
}
static void F_7 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_6 = F_3 ( V_4 ) ;
int V_7 ;
unsigned int V_8 = V_9 ;
if ( ! V_10 . V_11 ( V_2 ) )
return;
V_10 . V_15 ( V_2 ) ;
do {
V_7 = ! ! ( F_4 ( V_4 -> V_13 ) & F_5 ( V_6 -> V_14 ) ) ;
if ( V_7 )
F_6 ( 100 ) ;
} while ( V_7 && -- V_8 );
}
static struct V_1 * F_8 ( struct V_16 * V_17 ,
const char * V_18 , const char * V_19 ,
void T_1 * V_13 , T_2 V_20 , T_2 V_14 ,
unsigned long V_21 , T_3 * V_22 )
{
struct V_5 * V_6 ;
struct V_23 V_24 = { NULL } ;
struct V_1 * V_2 ;
int V_25 ;
V_6 = F_9 ( sizeof( * V_6 ) , V_26 ) ;
if ( ! V_6 )
return F_10 ( - V_27 ) ;
V_24 . V_18 = V_18 ;
V_24 . V_28 = & V_29 ;
V_24 . V_21 = V_21 ;
V_24 . V_30 = & V_19 ;
V_24 . V_31 = 1 ;
V_6 -> V_14 = V_14 ;
V_6 -> V_4 . V_22 = V_22 ;
V_6 -> V_4 . V_13 = V_13 ;
V_6 -> V_4 . V_20 = V_20 ;
V_6 -> V_4 . V_2 . V_24 = & V_24 ;
V_2 = & V_6 -> V_4 . V_2 ;
V_25 = F_11 ( V_17 , V_2 ) ;
if ( V_25 ) {
F_12 ( V_6 ) ;
V_2 = F_10 ( V_25 ) ;
}
return V_2 ;
}
static struct V_32 * F_13 ( void T_1 * V_13 , T_2 V_33 , T_2 V_34 ,
T_4 V_21 , T_3 * V_22 )
{
struct V_32 * V_35 ;
V_35 = F_9 ( sizeof( * V_35 ) , V_26 ) ;
if ( ! V_35 )
return F_10 ( - V_27 ) ;
V_35 -> V_13 = V_13 ;
V_35 -> V_33 = V_33 ;
V_35 -> V_36 = ( 1 << V_34 ) - 1 ;
V_35 -> V_21 = V_21 ;
V_35 -> V_22 = V_22 ;
return V_35 ;
}
static struct V_37 * F_14 ( void T_1 * V_13 , T_2 V_33 , T_2 V_34 ,
T_4 V_21 , T_3 * V_22 )
{
struct V_37 * div ;
div = F_9 ( sizeof( * div ) , V_26 ) ;
if ( ! div )
return F_10 ( - V_27 ) ;
div -> V_13 = V_13 ;
div -> V_33 = V_33 ;
div -> V_34 = V_34 ;
div -> V_21 = V_21 ;
div -> V_22 = V_22 ;
return div ;
}
static struct V_3 * F_15 ( void T_1 * V_13 , T_2 V_20 , T_4 V_21 ,
T_3 * V_22 )
{
struct V_3 * V_4 ;
V_4 = F_9 ( sizeof( * V_4 ) , V_26 ) ;
if ( ! V_4 )
return F_10 ( - V_27 ) ;
V_4 -> V_13 = V_13 ;
V_4 -> V_20 = V_20 ;
V_4 -> V_21 = V_21 ;
V_4 -> V_22 = V_22 ;
return V_4 ;
}
static void F_16 ( const struct V_38 * V_39 ,
const struct V_40 * V_41 ,
struct V_42 * V_43 , T_3 * V_22 )
{
struct V_32 * V_35 = NULL ;
struct V_37 * div = NULL ;
struct V_3 * V_4 = NULL ;
const struct V_44 * V_45 , * V_46 , * V_47 ;
struct V_1 * V_48 ;
struct V_1 * V_49 ;
struct V_1 * V_50 ;
V_45 = V_46 = V_47 = NULL ;
V_48 = V_49 = V_50 = NULL ;
if ( V_39 -> V_35 && V_39 -> V_35 ) {
V_35 = F_13 ( V_51 + V_41 -> V_35 -> V_52 ,
V_41 -> V_35 -> V_33 ,
V_41 -> V_35 -> V_34 ,
V_39 -> V_35 -> V_21 , V_22 ) ;
if ( ! F_17 ( V_35 ) ) {
V_48 = & V_35 -> V_2 ;
V_45 = V_39 -> V_35 -> V_28 ?
V_39 -> V_35 -> V_28 : & V_53 ;
}
}
if ( V_39 -> div && V_41 -> div ) {
div = F_14 ( V_51 + V_41 -> div -> V_52 ,
V_41 -> div -> V_33 ,
V_41 -> div -> V_34 ,
V_39 -> div -> V_21 , V_22 ) ;
if ( ! F_17 ( div ) ) {
V_49 = & div -> V_2 ;
V_46 = V_39 -> div -> V_28 ?
V_39 -> div -> V_28 : & V_54 ;
}
}
if ( V_39 -> V_4 && V_39 -> V_4 ) {
V_4 = F_15 ( V_51 + V_41 -> V_4 -> V_52 ,
V_41 -> V_4 -> V_20 ,
V_39 -> V_4 -> V_21 , V_22 ) ;
if ( ! F_17 ( V_4 ) ) {
V_50 = & V_4 -> V_2 ;
V_47 = V_39 -> V_4 -> V_28 ?
V_39 -> V_4 -> V_28 : & V_10 ;
}
}
V_43 -> V_48 = V_48 ;
V_43 -> V_45 = V_45 ;
V_43 -> V_49 = V_49 ;
V_43 -> V_46 = V_46 ;
V_43 -> V_50 = V_50 ;
V_43 -> V_47 = V_47 ;
}
static unsigned long F_18 ( struct V_1 * V_2 ,
unsigned long V_55 )
{
struct V_56 * V_57 = F_19 ( V_2 ) ;
T_4 V_58 ;
T_4 V_59 = V_57 -> V_59 ;
T_4 V_60 ;
T_4 V_61 ;
V_58 = ( F_4 ( V_51 + V_62 ) >> 15 ) & 0x01 ;
V_60 = ( F_4 ( V_51 + V_63 ) >> V_59 ) & 0x03 ;
V_61 = 2 ;
if ( V_60 < 4 )
V_61 = 1 ;
else if ( V_58 && V_60 > 4 )
V_61 = 4 ;
return V_55 * V_61 ;
}
static struct V_1 * F_20 ( struct V_16 * V_17 ,
const char * V_18 , const char * V_19 ,
unsigned long V_21 ,
T_2 V_59 ,
T_3 * V_22 )
{
struct V_56 * V_64 ;
struct V_23 V_24 ;
struct V_1 * V_2 ;
int V_65 ;
V_64 = F_9 ( sizeof( * V_64 ) , V_26 ) ;
if ( ! V_64 )
return F_10 ( - V_27 ) ;
V_24 . V_18 = V_18 ;
V_24 . V_28 = & V_66 ;
V_24 . V_21 = V_21 ;
V_24 . V_30 = & V_19 ;
V_24 . V_31 = 1 ;
V_64 -> V_2 . V_24 = & V_24 ;
V_64 -> V_22 = V_22 ;
V_64 -> V_59 = V_59 ;
V_2 = & V_64 -> V_2 ;
V_65 = F_11 ( V_17 , V_2 ) ;
if ( V_65 ) {
F_12 ( V_64 ) ;
return F_10 ( V_65 ) ;
}
return V_2 ;
}
static void F_21 ( void )
{
V_67 [ V_68 ] = F_22 ( NULL , L_1 ,
L_2 , V_69 , V_51 + V_70 , 8 , 4 , 0 ,
V_71 , & V_72 ) ;
V_67 [ V_73 ] = F_22 ( NULL , L_3 , L_1 ,
V_69 , V_51 + V_70 , 0 , 4 , 0 ,
V_71 , & V_72 ) ;
V_67 [ V_74 ] = F_23 ( NULL , L_4 ,
L_1 , 0 , 1 , 8 ) ;
V_67 [ V_75 ] = F_22 ( NULL , L_5 , L_3 , 0 ,
V_51 + V_70 , 4 , 3 , 0 ,
V_76 , & V_72 ) ;
V_67 [ V_77 ] = F_22 ( NULL , L_6 , L_3 , 0 ,
V_51 + V_63 , 4 , 3 , 0 ,
V_76 , & V_72 ) ;
F_20 ( NULL , L_7 , L_6 , 0 ,
4 , & V_72 ) ;
V_67 [ V_78 ] = F_22 ( NULL , L_8 , L_3 , 0 ,
V_51 + V_63 , 8 , 3 , 0 , V_76 ,
& V_72 ) ;
F_20 ( NULL , L_9 , L_8 , 0 , 8 ,
& V_72 ) ;
V_67 [ V_79 ] = F_22 ( NULL , L_10 , L_3 , 0 ,
V_51 + V_80 , 4 , 3 , 0 ,
V_76 , & V_72 ) ;
}
static int F_24 ( struct V_1 * V_2 )
{
struct V_81 * V_57 = F_25 ( V_2 ) ;
struct V_1 * V_82 = & V_57 -> V_6 . V_4 . V_2 ;
F_26 ( V_82 , V_2 ) ;
return V_29 . V_11 ( V_82 ) ;
}
static int F_27 ( struct V_1 * V_2 )
{
struct V_81 * V_57 = F_25 ( V_2 ) ;
struct V_1 * V_82 = & V_57 -> V_6 . V_4 . V_2 ;
F_26 ( V_82 , V_2 ) ;
return V_29 . V_12 ( V_82 ) ;
}
static void F_28 ( struct V_1 * V_2 )
{
struct V_81 * V_57 = F_25 ( V_2 ) ;
struct V_1 * V_82 = & V_57 -> V_6 . V_4 . V_2 ;
F_26 ( V_82 , V_2 ) ;
V_29 . V_15 ( V_82 ) ;
}
static int F_29 ( struct V_1 * V_2 )
{
struct V_81 * V_57 = F_25 ( V_2 ) ;
struct V_83 * V_84 = & V_57 -> div ;
return ( F_4 ( V_84 -> V_85 ) >> V_84 -> V_86 ) & 0x01 ;
}
static unsigned long F_30 ( struct V_1 * V_2 )
{
struct V_81 * V_57 = F_25 ( V_2 ) ;
struct V_83 * V_84 = & V_57 -> div ;
return ( F_4 ( V_84 -> V_87 ) >> V_84 -> V_88 ) &
F_31 ( V_84 -> V_89 - 1 , 0 ) ;
}
static unsigned long F_32 ( struct V_1 * V_2 ,
unsigned long V_55 )
{
struct V_81 * V_57 = F_25 ( V_2 ) ;
struct V_83 * V_84 = & V_57 -> div ;
unsigned long V_90 , V_91 ;
T_4 V_92 , V_36 ;
T_5 V_93 , V_94 = 0 ;
V_92 = F_4 ( V_84 -> V_95 ) ;
V_36 = F_31 ( V_84 -> V_96 - 1 , 0 ) << V_84 -> V_97 ;
V_90 = ( V_92 & V_36 ) >> V_84 -> V_97 ;
V_92 = F_4 ( V_84 -> V_98 ) ;
V_36 = F_31 ( V_84 -> V_99 - 1 , 0 ) << V_84 -> V_100 ;
V_91 = ( ( V_92 & V_36 ) >> V_84 -> V_100 ) + 1 ;
if ( ! V_91 || ! V_90 )
return V_55 ;
V_93 = ( T_5 ) V_55 * V_91 ;
F_33 ( V_93 , V_90 ) ;
if ( F_29 ( V_2 ) ) {
V_92 = F_30 ( V_2 ) ;
V_94 = ( T_5 ) V_55 * ( T_5 ) V_92 ;
F_33 ( V_94 , ( V_90 * 8191 ) ) ;
}
return V_93 + V_94 ;
}
static struct V_1 * F_34 ( struct V_16 * V_17 ,
const char * V_18 ,
const char * V_101 ,
unsigned long V_21 ,
const struct V_102 * V_41 ,
T_3 * V_22 )
{
struct V_81 * V_103 ;
struct V_23 V_24 = { NULL } ;
struct V_1 * V_2 ;
int V_25 ;
struct V_83 * div = NULL ;
struct V_5 * V_6 ;
V_103 = F_9 ( sizeof( * V_103 ) , V_26 ) ;
if ( ! V_103 )
return F_10 ( - V_27 ) ;
V_24 . V_18 = V_18 ;
V_24 . V_28 = & V_104 ;
V_24 . V_21 = V_21 ;
V_24 . V_30 = & V_101 ;
V_24 . V_31 = 1 ;
V_103 -> V_2 . V_24 = & V_24 ;
V_2 = & V_103 -> V_2 ;
V_6 = & V_103 -> V_6 ;
V_6 -> V_14 = V_41 -> V_20 + 1 ;
V_6 -> V_4 . V_22 = V_22 ;
V_6 -> V_4 . V_13 = V_51 + V_105 ;
V_6 -> V_4 . V_20 = V_41 -> V_20 ;
div = & V_103 -> div ;
div -> V_21 = 0 ;
div -> V_95 = V_51 + V_106 ;
div -> V_97 = V_41 -> V_107 ;
div -> V_96 = 6 ;
div -> V_98 = V_51 + V_41 -> V_108 ;
div -> V_100 = 0 ;
div -> V_99 = 9 ;
div -> V_85 = V_51 + V_109 ;
div -> V_86 = V_41 -> V_110 ;
div -> V_87 = V_51 + V_41 -> V_111 ;
div -> V_88 = 3 ;
div -> V_89 = 13 ;
div -> V_22 = V_22 ;
V_25 = F_11 ( V_17 , V_2 ) ;
if ( V_25 ) {
F_12 ( V_103 ) ;
V_2 = F_10 ( V_25 ) ;
}
return V_2 ;
}
static unsigned long F_35 ( struct V_1 * V_2 ,
unsigned long V_55 )
{
return V_54 . V_112 ( V_2 , V_55 ) ;
}
static long F_36 ( struct V_1 * V_2 , unsigned long V_93 ,
unsigned long * V_113 )
{
return V_54 . V_114 ( V_2 , V_93 , V_113 ) ;
}
static int F_37 ( struct V_1 * V_2 , unsigned long V_93 ,
unsigned long V_55 )
{
struct V_1 * V_115 ;
int V_116 ;
int V_25 ;
V_115 = F_38 ( V_2 ) ;
V_116 = F_24 ( V_115 ) ;
if ( V_116 )
F_28 ( V_115 ) ;
V_25 = V_54 . V_117 ( V_2 , V_93 , V_55 ) ;
if ( V_116 )
F_27 ( V_115 ) ;
return V_25 ;
}
static int F_39 ( struct V_1 * V_2 )
{
struct V_1 * V_115 ;
int V_116 ;
int V_25 ;
if ( V_10 . V_11 ( V_2 ) )
return 0 ;
V_115 = F_38 ( V_2 ) ;
V_116 = F_24 ( V_115 ) ;
if ( V_116 )
F_28 ( V_115 ) ;
V_25 = V_10 . V_12 ( V_2 ) ;
if ( V_116 )
F_27 ( V_115 ) ;
return V_25 ;
}
static void F_40 ( struct V_1 * V_2 )
{
struct V_1 * V_115 ;
int V_116 ;
if ( ! V_10 . V_11 ( V_2 ) )
return;
V_115 = F_38 ( V_2 ) ;
V_116 = F_24 ( V_115 ) ;
if ( V_116 )
F_28 ( V_115 ) ;
V_10 . V_15 ( V_2 ) ;
if ( V_116 )
F_27 ( V_115 ) ;
}
static void T_6 F_41 ( struct V_118 * V_119 )
{
struct V_120 * V_121 ;
struct V_42 V_122 ;
int V_91 ;
const char * V_123 , * V_124 , * V_125 ;
struct V_126 * V_127 ;
V_121 = F_9 ( sizeof( * V_121 ) +
sizeof( * V_121 -> V_67 ) * V_128 ,
V_26 ) ;
if ( ! V_121 )
return;
V_121 -> V_129 = V_128 ;
V_67 = V_121 -> V_67 ;
for ( V_91 = 0 ; V_91 < V_128 ; V_91 ++ )
V_67 [ V_91 ] = F_10 ( - V_130 ) ;
V_51 = F_42 ( V_119 , 0 ) ;
if ( ! V_51 ) {
F_43 ( L_11 , V_119 -> V_18 ) ;
goto V_131;
}
V_127 = F_44 ( V_119 , L_12 ) ;
if ( F_17 ( V_127 ) )
F_45 ( L_13 , V_132 ) ;
else
F_46 ( V_127 , V_133 , V_134 , V_134 ) ;
V_123 = F_47 ( V_119 , 0 ) ;
V_124 = F_47 ( V_119 , 1 ) ;
V_125 = F_47 ( V_119 , 2 ) ;
V_135 [ 3 ] = V_125 ;
V_136 [ 3 ] = V_125 ;
F_48 ( NULL , L_14 , NULL , 0 , 64000000 ) ;
F_48 ( NULL , L_15 , NULL , 0 , 4000000 ) ;
F_48 ( NULL , L_16 , NULL , 0 , 32000 ) ;
F_48 ( NULL , L_17 , NULL , 0 , 48000 ) ;
V_67 [ V_137 ] = F_48 ( NULL , L_18 , NULL ,
0 , 0 ) ;
V_67 [ V_138 ] = F_49 ( NULL , L_19 , L_14 , 0 ,
V_51 + V_105 , 3 , 2 , V_139 ,
& V_72 ) ;
V_67 [ V_140 ] = F_49 ( NULL , L_20 , L_21 , 0 ,
V_51 + V_62 , 8 , 6 , V_141 |
V_142 ,
& V_72 ) ;
for ( V_91 = 0 ; V_91 < F_50 ( V_143 ) ; V_91 ++ )
V_67 [ V_144 + V_91 ] = F_51 ( NULL ,
V_143 [ V_91 ] . V_18 ,
V_143 [ V_91 ] . V_145 ,
V_143 [ V_91 ] . V_31 ,
V_143 [ V_91 ] . V_21 ,
V_143 [ V_91 ] . V_52 + V_51 ,
V_143 [ V_91 ] . V_33 ,
V_143 [ V_91 ] . V_34 ,
0 ,
& V_72 ) ;
F_21 () ;
for ( V_91 = 0 ; V_91 < F_50 ( V_146 ) ; V_91 ++ )
V_67 [ V_147 + V_91 ] = F_8 ( NULL ,
V_146 [ V_91 ] . V_18 ,
V_146 [ V_91 ] . V_101 ,
V_146 [ V_91 ] . V_148 + V_51 ,
V_146 [ V_91 ] . V_20 ,
V_146 [ V_91 ] . V_14 ,
V_146 [ V_91 ] . V_21 ,
& V_72 ) ;
V_67 [ V_149 ] = F_8 ( NULL ,
L_21 ,
V_123 ,
V_105 + V_51 ,
16 , 17 ,
0 ,
& V_72 ) ;
V_67 [ V_150 ] = F_8 ( NULL ,
L_22 ,
V_124 ,
V_151 + V_51 ,
0 , 1 ,
0 ,
& V_72 ) ;
V_67 [ V_152 + V_91 ] = F_23 ( NULL ,
L_23 , L_24 , 0 , 1 , 122 ) ;
for ( V_91 = 0 ; V_91 < F_50 ( V_153 ) ; V_91 ++ ) {
int V_154 ;
F_34 ( NULL , V_153 [ V_91 ] . V_18 ,
V_153 [ V_91 ] . V_19 , V_153 [ V_91 ] . V_21 ,
V_153 [ V_91 ] . V_41 ,
& V_72 ) ;
for ( V_154 = 0 ; V_154 < 3 ; V_154 ++ ) {
int V_155 = V_91 * 3 + V_154 ;
F_16 ( & V_156 , & V_157 [ V_91 ] [ V_154 ] ,
& V_122 , & V_72 ) ;
V_67 [ V_158 + V_155 ] = F_52 ( NULL ,
V_157 [ V_91 ] [ V_154 ] . V_18 ,
V_157 [ V_91 ] [ V_154 ] . V_19 ,
V_157 [ V_91 ] [ V_154 ] . V_31 ,
V_122 . V_48 , V_122 . V_45 ,
V_122 . V_49 , V_122 . V_46 ,
V_122 . V_50 , V_122 . V_47 ,
V_157 [ V_91 ] [ V_154 ] . V_21 ) ;
}
}
for ( V_91 = 0 ; V_91 < F_50 ( V_159 ) ; V_91 ++ )
V_67 [ V_160 + V_91 ] = F_53 ( NULL , V_159 [ V_91 ] . V_18 ,
V_159 [ V_91 ] . V_101 ,
V_159 [ V_91 ] . V_21 , V_51 + V_159 [ V_91 ] . V_148 ,
V_159 [ V_91 ] . V_20 , V_159 [ V_91 ] . V_21 , & V_72 ) ;
for ( V_91 = 0 ; V_91 < F_50 ( V_161 ) ; V_91 ++ ) {
F_16 ( & V_162 , & V_161 [ V_91 ] , & V_122 ,
& V_72 ) ;
V_67 [ V_163 + V_91 ] = F_52 ( NULL ,
V_161 [ V_91 ] . V_18 ,
V_161 [ V_91 ] . V_19 ,
V_161 [ V_91 ] . V_31 ,
V_122 . V_48 , V_122 . V_45 ,
V_122 . V_49 , V_122 . V_46 ,
V_122 . V_50 , V_122 . V_47 ,
V_161 [ V_91 ] . V_21 ) ;
}
F_48 ( NULL , L_25 , NULL , 0 , 0 ) ;
F_16 ( & V_164 , & V_165 , & V_122 , & V_72 ) ;
V_67 [ V_166 ] = F_52 ( NULL ,
V_165 . V_18 ,
V_165 . V_19 ,
V_165 . V_31 ,
V_122 . V_48 , V_122 . V_45 ,
V_122 . V_49 , V_122 . V_46 ,
V_122 . V_50 , V_122 . V_47 ,
V_165 . V_21 ) ;
for ( V_91 = 0 ; V_91 < F_50 ( V_167 ) ; V_91 ++ ) {
F_16 ( & V_168 , & V_167 [ V_91 ] , & V_122 ,
& V_72 ) ;
V_67 [ V_169 + V_91 ] = F_52 ( NULL ,
V_167 [ V_91 ] . V_18 ,
V_167 [ V_91 ] . V_19 ,
V_167 [ V_91 ] . V_31 ,
V_122 . V_48 , V_122 . V_45 ,
V_122 . V_49 , V_122 . V_46 ,
V_122 . V_50 , V_122 . V_47 ,
V_167 [ V_91 ] . V_21 ) ;
}
F_54 ( V_119 , V_170 , V_121 ) ;
return;
V_131:
F_12 ( V_121 ) ;
}
