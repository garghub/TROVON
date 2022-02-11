static void F_1 ( struct V_1 * V_1 )
{
F_2 ( V_1 , V_2 , V_3 ) ;
V_1 -> V_4 = 1 ;
V_1 -> V_5 = 0 ;
}
static int F_3 ( struct V_1 * V_1 )
{
if ( ! V_1 -> V_4 )
return 0 ;
if ( ! V_1 -> V_5 )
F_2 ( V_1 , V_2 , 0 ) ;
if ( V_1 -> V_5 ++ >= 8 )
V_1 -> V_4 = 0 ;
return 1 ;
}
void F_4 ( struct V_1 * V_1 )
{
F_2 ( V_1 , V_6 , V_7 ) ;
F_5 ( & V_1 -> V_8 ) ;
}
static void F_6 ( struct V_1 * V_1 , T_1 V_9 ,
int V_10 , int V_11 , int V_12 , int V_13 , int V_14 )
{
if ( V_9 >= V_1 -> V_15 )
return;
F_2 ( V_1 , F_7 ( V_9 ) ,
F_8 ( V_9 ) |
F_9 ( V_10 ) |
F_10 ( V_12 ) |
F_11 ( V_14 ) ) ;
F_2 ( V_1 , F_12 ( V_9 ) ,
F_13 ( V_11 ) |
F_14 ( V_13 ) ) ;
}
static int F_15 ( struct V_1 * V_1 , T_1 V_16 , int V_17 )
{
T_1 V_9 = V_16 * 4 ;
if ( V_9 >= V_1 -> V_15 )
return - V_18 ;
if ( ! V_17 ) {
T_1 V_19 ;
for ( V_19 = V_9 ; V_19 < V_9 + 4 ; V_19 ++ )
F_6 ( V_1 , V_19 , V_1 -> V_20 ,
F_16 ( V_1 ) ,
V_1 -> V_20 ,
F_16 ( V_1 ) , 0 ) ;
return 0 ;
}
F_6 ( V_1 , V_9 , 0 , 0 , V_1 -> V_20 / 2 ,
F_16 ( V_1 ) / 2 , 3 ) ;
F_6 ( V_1 , V_9 + 1 , V_1 -> V_20 / 2 , 0 ,
V_1 -> V_20 , F_16 ( V_1 ) / 2 , 3 ) ;
F_6 ( V_1 , V_9 + 2 , 0 , F_16 ( V_1 ) / 2 ,
V_1 -> V_20 / 2 , F_16 ( V_1 ) , 3 ) ;
F_6 ( V_1 , V_9 + 3 , V_1 -> V_20 / 2 ,
F_16 ( V_1 ) / 2 , V_1 -> V_20 ,
F_16 ( V_1 ) , 3 ) ;
return 0 ;
}
static int F_17 ( struct V_1 * V_1 , int V_17 )
{
int V_11 , V_21 , V_22 , V_19 ;
if ( ! V_17 ) {
for ( V_19 = 0 ; V_19 < 16 ; V_19 ++ )
F_6 ( V_1 , V_19 , V_1 -> V_20 ,
F_16 ( V_1 ) ,
V_1 -> V_20 ,
F_16 ( V_1 ) , 0 ) ;
return 0 ;
}
V_21 = F_16 ( V_1 ) / 4 ;
V_22 = V_1 -> V_20 / 4 ;
for ( V_11 = 0 , V_19 = 0 ; V_19 < 4 ; V_19 ++ , V_11 += V_21 ) {
F_6 ( V_1 , V_19 * 4 , 0 , V_11 , V_22 ,
V_11 + V_21 , 5 ) ;
F_6 ( V_1 , ( V_19 * 4 ) + 1 , V_22 , V_11 ,
V_22 * 2 , V_11 + V_21 , 5 ) ;
F_6 ( V_1 , ( V_19 * 4 ) + 2 , V_22 * 2 , V_11 ,
V_22 * 3 , V_11 + V_21 , 5 ) ;
F_6 ( V_1 , ( V_19 * 4 ) + 3 , V_22 * 3 , V_11 ,
V_1 -> V_20 , V_11 + V_21 , 5 ) ;
}
return 0 ;
}
static int F_18 ( struct V_1 * V_1 , T_1 V_9 , int V_17 )
{
T_1 V_23 ;
if ( V_9 < V_1 -> V_15 ) {
F_6 ( V_1 , V_9 , V_17 ? 0 : V_1 -> V_20 ,
V_17 ? 0 : F_16 ( V_1 ) ,
V_1 -> V_20 , F_16 ( V_1 ) ,
V_17 ? 1 : 0 ) ;
return 0 ;
}
if ( V_9 >= V_1 -> V_15 + V_1 -> V_24 )
return - V_18 ;
V_23 = V_9 - V_1 -> V_15 ;
if ( V_23 < 4 )
return F_15 ( V_1 , V_23 , V_17 ) ;
return F_17 ( V_1 , V_17 ) ;
}
static int F_19 ( struct V_1 * V_1 , T_1 V_9 )
{
if ( V_9 >= V_1 -> V_15 + V_1 -> V_24 )
return - V_18 ;
F_1 ( V_1 ) ;
F_18 ( V_1 , V_1 -> V_25 , 0 ) ;
F_18 ( V_1 , V_9 , 1 ) ;
V_1 -> V_25 = V_9 ;
return 0 ;
}
static void F_20 ( struct V_26 * V_27 )
{
memset ( V_27 -> V_28 , 0 , sizeof( * V_27 -> V_28 ) ) ;
V_27 -> V_29 = 1 ;
}
static int F_21 ( struct V_26 * V_27 )
{
int V_30 ;
if ( ! V_27 -> V_29 )
return 0 ;
V_30 = F_22 ( V_27 -> V_1 , V_31 ,
V_27 -> V_28 , V_27 -> V_29 ) ;
F_20 ( V_27 ) ;
return V_30 ;
}
static int F_23 ( struct V_26 * V_27 , T_2 V_32 ,
T_3 V_33 , int V_34 , int V_35 , int V_36 )
{
if ( V_27 -> V_29 >= V_37 ) {
int V_30 = F_21 ( V_27 ) ;
if ( V_30 )
return V_30 ;
}
F_24 ( & V_27 -> V_28 [ V_27 -> V_29 ] , 0 , V_32 , V_33 ,
V_34 , V_35 , V_36 ) ;
V_27 -> V_29 ++ ;
return 0 ;
}
static void F_25 ( struct V_26 * V_27 ,
struct V_38 * V_39 )
{
struct V_1 * V_1 = V_27 -> V_1 ;
struct V_40 * V_41 ;
unsigned int V_42 ;
int error = 1 ;
int V_19 ;
struct V_43 * V_44 ;
T_2 V_45 ;
int V_46 ;
V_41 = F_26 ( V_39 ) ;
if ( ! V_41 )
goto V_47;
if ( F_3 ( V_1 ) ) {
int V_19 ;
F_27 (vbuf->sglist, sg, vbuf->sglen, i) {
void * V_48 = F_28 ( V_44 ) ;
T_4 V_49 = F_29 ( V_44 ) ;
for ( V_19 = 0 ; V_19 < V_49 ; V_19 += 2 ) {
( ( T_1 * ) V_48 ) [ V_19 ] = 0x80 ;
( ( T_1 * ) V_48 ) [ V_19 + 1 ] = 0x00 ;
}
}
error = 0 ;
goto V_47;
}
F_20 ( V_27 ) ;
V_44 = V_41 -> V_50 ;
V_45 = F_30 ( V_44 ) ;
V_46 = F_29 ( V_44 ) ;
V_42 = V_51 + ( V_27 -> V_52 *
( V_53 * F_16 ( V_1 ) ) ) ;
for ( V_19 = 0 ; V_19 < F_16 ( V_1 ) ; V_19 ++ ) {
int V_54 = F_31 ( V_1 ) ;
int V_55 ;
if ( ! V_46 ) {
V_44 = F_32 ( V_44 ) ;
if ( V_44 == NULL )
goto V_47;
V_45 = F_30 ( V_44 ) ;
V_46 = F_29 ( V_44 ) ;
}
if ( V_46 < V_54 ) {
int V_56 = V_42 ;
while ( V_54 > 0 ) {
int V_57 ;
if ( ! V_46 ) {
V_44 = F_32 ( V_44 ) ;
if ( V_44 == NULL )
goto V_47;
V_45 = F_30 ( V_44 ) ;
V_46 = F_29 ( V_44 ) ;
}
V_57 = F_33 ( V_46 , V_54 ) ;
if ( F_23 ( V_27 , V_45 , V_56 ,
V_57 , 0 , 0 ) )
goto V_47;
V_54 -= V_57 ;
V_46 -= V_57 ;
V_45 += V_57 ;
V_56 += V_57 ;
}
V_42 += V_53 ;
continue;
}
V_55 = F_33 ( V_46 / V_54 ,
F_16 ( V_1 ) - V_19 ) ;
if ( F_23 ( V_27 , V_45 , V_42 , V_54 ,
V_55 - 1 , V_53 ) )
goto V_47;
V_19 += V_55 - 1 ;
V_42 += V_53 * V_55 ;
V_45 += V_55 * V_54 ;
V_46 -= V_55 * V_54 ;
}
error = F_21 ( V_27 ) ;
V_47:
if ( error ) {
V_39 -> V_58 = V_59 ;
} else {
V_39 -> V_34 = F_16 ( V_1 ) * F_31 ( V_1 ) ;
V_39 -> V_58 = V_60 ;
V_39 -> V_61 ++ ;
F_34 ( & V_39 -> V_62 ) ;
}
F_35 ( & V_39 -> V_63 ) ;
return;
}
static void F_36 ( struct V_26 * V_27 )
{
struct V_38 * V_39 ;
unsigned int V_64 ;
for (; ; ) {
F_37 ( & V_27 -> V_65 ) ;
if ( F_38 ( & V_27 -> V_66 ) )
break;
V_39 = F_39 ( & V_27 -> V_66 , struct V_38 ,
V_67 ) ;
if ( ! F_40 ( & V_39 -> V_63 ) )
break;
V_64 = F_41 ( F_42 ( V_27 -> V_1 ,
V_68 ) ) ;
if ( V_64 == V_27 -> V_52 )
break;
V_27 -> V_52 = V_64 ;
F_43 ( & V_39 -> V_67 ) ;
F_44 ( & V_27 -> V_65 ) ;
F_25 ( V_27 , V_39 ) ;
}
F_45 ( & V_27 -> V_65 ) ;
F_44 ( & V_27 -> V_65 ) ;
}
static int F_46 ( void * V_69 )
{
struct V_26 * V_27 = V_69 ;
struct V_1 * V_1 = V_27 -> V_1 ;
F_47 ( V_70 , V_71 ) ;
F_48 () ;
F_49 ( & V_1 -> V_8 , & V_70 ) ;
for (; ; ) {
long V_72 = F_50 ( V_73 ) ;
if ( V_72 == - V_74 || F_51 () )
break;
F_36 ( V_27 ) ;
F_52 () ;
}
F_53 ( & V_1 -> V_8 , & V_70 ) ;
return 0 ;
}
static int F_54 ( struct V_26 * V_27 )
{
V_27 -> V_75 = F_55 ( F_46 , V_27 , V_76 L_1 ) ;
if ( F_56 ( V_27 -> V_75 ) )
return F_57 ( V_27 -> V_75 ) ;
return 0 ;
}
static void F_58 ( struct V_26 * V_27 )
{
if ( V_27 -> V_75 ) {
F_59 ( V_27 -> V_75 ) ;
V_27 -> V_75 = NULL ;
}
}
static int F_60 ( struct V_77 * V_78 , unsigned int * V_79 ,
unsigned int * V_34 )
{
struct V_26 * V_27 = V_78 -> V_80 ;
struct V_1 * V_1 = V_27 -> V_1 ;
* V_34 = F_61 ( V_1 ) ;
if ( * V_79 < V_81 )
* V_79 = V_81 ;
return 0 ;
}
static int F_62 ( struct V_77 * V_78 ,
struct V_38 * V_39 , enum V_82 V_83 )
{
struct V_26 * V_27 = V_78 -> V_80 ;
struct V_1 * V_1 = V_27 -> V_1 ;
V_39 -> V_34 = F_61 ( V_1 ) ;
if ( V_39 -> V_84 != 0 && V_39 -> V_85 < V_39 -> V_34 )
return - V_18 ;
V_39 -> V_86 = V_1 -> V_20 ;
V_39 -> V_87 = F_16 ( V_1 ) ;
V_39 -> V_88 = F_31 ( V_1 ) ;
V_39 -> V_83 = V_83 ;
if ( V_39 -> V_58 == V_89 ) {
int V_90 = F_63 ( V_78 , V_39 , NULL ) ;
if ( V_90 < 0 ) {
struct V_40 * V_91 = F_26 ( V_39 ) ;
F_64 ( V_78 -> V_92 , V_91 ) ;
F_65 ( V_91 ) ;
V_39 -> V_58 = V_89 ;
return V_90 ;
}
}
V_39 -> V_58 = V_93 ;
return 0 ;
}
static void F_66 ( struct V_77 * V_78 ,
struct V_38 * V_39 )
{
struct V_26 * V_27 = V_78 -> V_80 ;
struct V_1 * V_1 = V_27 -> V_1 ;
V_39 -> V_58 = V_94 ;
F_67 ( & V_39 -> V_67 , & V_27 -> V_66 ) ;
F_5 ( & V_1 -> V_8 ) ;
}
static void F_68 ( struct V_77 * V_78 ,
struct V_38 * V_39 )
{
struct V_40 * V_91 = F_26 ( V_39 ) ;
F_64 ( V_78 -> V_92 , V_91 ) ;
F_65 ( V_91 ) ;
V_39 -> V_58 = V_89 ;
}
static unsigned int F_69 ( struct V_95 * V_95 ,
struct V_96 * V_70 )
{
struct V_26 * V_27 = V_95 -> V_97 ;
return F_70 ( V_95 , & V_27 -> V_98 , V_70 ) ;
}
static int F_71 ( struct V_95 * V_95 , struct V_99 * V_100 )
{
struct V_26 * V_27 = V_95 -> V_97 ;
return F_72 ( & V_27 -> V_98 , V_100 ) ;
}
static int F_73 ( struct V_95 * V_95 )
{
struct V_1 * V_1 = F_74 ( V_95 ) ;
struct V_26 * V_27 ;
int V_30 ;
V_27 = F_75 ( sizeof( * V_27 ) , V_101 ) ;
if ( V_27 == NULL )
return - V_102 ;
F_76 ( & V_27 -> V_65 ) ;
F_77 ( & V_27 -> V_66 ) ;
V_27 -> V_1 = V_1 ;
V_95 -> V_97 = V_27 ;
V_30 = F_54 ( V_27 ) ;
if ( V_30 ) {
F_78 ( V_27 ) ;
return V_30 ;
}
F_79 ( & V_27 -> V_98 , & V_103 ,
& V_1 -> V_104 -> V_92 , & V_27 -> V_65 ,
V_105 ,
V_106 ,
sizeof( struct V_38 ) , V_27 , NULL ) ;
return 0 ;
}
static T_5 F_80 ( struct V_95 * V_95 , char T_6 * V_69 ,
T_4 V_79 , T_7 * V_107 )
{
struct V_26 * V_27 = V_95 -> V_97 ;
return F_81 ( & V_27 -> V_98 , V_69 , V_79 , V_107 , 0 ,
V_95 -> V_108 & V_109 ) ;
}
static int F_82 ( struct V_95 * V_95 )
{
struct V_26 * V_27 = V_95 -> V_97 ;
F_83 ( & V_27 -> V_98 ) ;
F_84 ( & V_27 -> V_98 ) ;
F_58 ( V_27 ) ;
F_78 ( V_27 ) ;
return 0 ;
}
static int F_85 ( struct V_95 * V_95 , void * V_110 ,
struct V_111 * V_112 )
{
struct V_26 * V_27 = V_110 ;
struct V_1 * V_1 = V_27 -> V_1 ;
strcpy ( V_112 -> V_113 , V_76 ) ;
strcpy ( V_112 -> V_114 , L_2 ) ;
snprintf ( V_112 -> V_115 , sizeof( V_112 -> V_115 ) , L_3 ,
F_86 ( V_1 -> V_104 ) ) ;
V_112 -> V_116 = V_117 ;
V_112 -> V_118 = V_119 |
V_120 |
V_121 ;
return 0 ;
}
static int F_87 ( struct V_1 * V_1 ,
struct V_122 * V_123 )
{
static const char * V_124 [] = { L_4 } ;
static const char * V_125 [] = { L_5 , L_6 } ;
static const char * V_126 [] = {
L_5 , L_6 , L_7 , L_8 , L_9
} ;
const char * * V_127 ;
if ( V_123 -> V_128 >= ( V_1 -> V_15 + V_1 -> V_24 ) )
return - V_18 ;
if ( V_1 -> V_24 == 5 )
V_127 = V_126 ;
else if ( V_1 -> V_24 == 2 )
V_127 = V_125 ;
else
V_127 = V_124 ;
snprintf ( V_123 -> V_129 , sizeof( V_123 -> V_129 ) , L_10 ,
V_127 [ V_123 -> V_128 - V_1 -> V_15 ] ) ;
return 0 ;
}
static int F_88 ( struct V_95 * V_95 , void * V_110 ,
struct V_122 * V_123 )
{
struct V_26 * V_27 = V_110 ;
struct V_1 * V_1 = V_27 -> V_1 ;
if ( V_123 -> V_128 >= V_1 -> V_15 ) {
int V_30 = F_87 ( V_1 , V_123 ) ;
if ( V_30 < 0 )
return V_30 ;
} else {
snprintf ( V_123 -> V_129 , sizeof( V_123 -> V_129 ) , L_11 ,
V_123 -> V_128 + 1 ) ;
if ( ! F_89 ( V_1 , V_123 -> V_128 ) )
V_123 -> V_130 = V_131 ;
}
V_123 -> type = V_132 ;
if ( V_1 -> V_133 == V_134 )
V_123 -> V_135 = V_136 ;
else
V_123 -> V_135 = V_137 ;
return 0 ;
}
static int F_90 ( struct V_95 * V_95 , void * V_110 , unsigned int V_128 )
{
struct V_26 * V_27 = V_110 ;
return F_19 ( V_27 -> V_1 , V_128 ) ;
}
static int F_91 ( struct V_95 * V_95 , void * V_110 , unsigned int * V_128 )
{
struct V_26 * V_27 = V_110 ;
* V_128 = V_27 -> V_1 -> V_25 ;
return 0 ;
}
static int F_92 ( struct V_95 * V_95 , void * V_110 ,
struct V_138 * V_139 )
{
if ( V_139 -> V_128 )
return - V_18 ;
V_139 -> V_140 = V_141 ;
F_93 ( V_139 -> V_142 , L_12 , sizeof( V_139 -> V_142 ) ) ;
return 0 ;
}
static int F_94 ( struct V_95 * V_95 , void * V_110 ,
struct V_143 * V_139 )
{
struct V_26 * V_27 = V_110 ;
struct V_1 * V_1 = V_27 -> V_1 ;
struct V_144 * V_145 = & V_139 -> V_146 . V_145 ;
int V_147 = F_61 ( V_1 ) ;
if ( V_145 -> V_86 != V_1 -> V_20 )
V_145 -> V_86 = V_1 -> V_20 ;
if ( V_145 -> V_87 != F_16 ( V_1 ) )
V_145 -> V_87 = F_16 ( V_1 ) ;
if ( V_145 -> V_148 != V_147 )
V_145 -> V_148 = V_147 ;
if ( V_145 -> V_83 == V_149 )
V_145 -> V_83 = V_106 ;
if ( V_145 -> V_140 != V_141 ||
V_145 -> V_83 != V_106 ||
V_145 -> V_150 != V_151 )
return - V_18 ;
return 0 ;
}
static int F_95 ( struct V_95 * V_95 , void * V_110 ,
struct V_143 * V_139 )
{
struct V_26 * V_27 = V_110 ;
if ( F_96 ( & V_27 -> V_98 ) )
return - V_152 ;
return F_94 ( V_95 , V_110 , V_139 ) ;
}
static int F_97 ( struct V_95 * V_95 , void * V_110 ,
struct V_143 * V_139 )
{
struct V_26 * V_27 = V_110 ;
struct V_1 * V_1 = V_27 -> V_1 ;
struct V_144 * V_145 = & V_139 -> V_146 . V_145 ;
V_145 -> V_86 = V_1 -> V_20 ;
V_145 -> V_87 = F_16 ( V_1 ) ;
V_145 -> V_140 = V_141 ;
V_145 -> V_83 = V_106 ;
V_145 -> V_148 = F_61 ( V_1 ) ;
V_145 -> V_150 = V_151 ;
V_145 -> V_88 = F_31 ( V_1 ) ;
return 0 ;
}
static int F_98 ( struct V_95 * V_95 , void * V_110 ,
struct V_153 * V_154 )
{
struct V_26 * V_27 = V_110 ;
return F_99 ( & V_27 -> V_98 , V_154 ) ;
}
static int F_100 ( struct V_95 * V_95 , void * V_110 , struct V_155 * V_156 )
{
struct V_26 * V_27 = V_110 ;
return F_101 ( & V_27 -> V_98 , V_156 ) ;
}
static int F_102 ( struct V_95 * V_95 , void * V_110 , struct V_155 * V_156 )
{
struct V_26 * V_27 = V_110 ;
return F_103 ( & V_27 -> V_98 , V_156 ) ;
}
static int F_104 ( struct V_95 * V_95 , void * V_110 , struct V_155 * V_156 )
{
struct V_26 * V_27 = V_110 ;
return F_105 ( & V_27 -> V_98 , V_156 , V_95 -> V_108 & V_109 ) ;
}
static int F_106 ( struct V_95 * V_95 , void * V_110 , enum V_157 V_19 )
{
struct V_26 * V_27 = V_110 ;
if ( V_19 != V_105 )
return - V_18 ;
return F_107 ( & V_27 -> V_98 ) ;
}
static int F_108 ( struct V_95 * V_95 , void * V_110 , enum V_157 V_19 )
{
struct V_26 * V_27 = V_110 ;
if ( V_19 != V_105 )
return - V_18 ;
return F_109 ( & V_27 -> V_98 ) ;
}
static int F_110 ( struct V_95 * V_95 , void * V_110 , T_8 * V_19 )
{
return 0 ;
}
static int F_111 ( struct V_95 * V_95 , void * V_110 ,
struct V_158 * V_159 )
{
V_159 -> V_160 = F_112 ( V_161 , V_159 -> V_160 ) ;
if ( ! V_159 -> V_160 )
return - V_18 ;
switch ( V_159 -> V_160 ) {
#ifdef F_113
case V_162 :
V_159 -> type = V_163 ;
V_159 -> V_164 = 0 ;
V_159 -> V_165 = V_159 -> V_166 = 1 ;
V_159 -> V_167 = 0 ;
F_93 ( V_159 -> V_129 , L_13 , sizeof( V_159 -> V_129 ) ) ;
return 0 ;
#else
case V_162 :
return F_114 ( V_159 , 0 , 1 , 1 , 0 ) ;
#endif
}
return - V_18 ;
}
static int F_115 ( struct V_95 * V_95 , void * V_110 ,
struct V_168 * V_169 )
{
struct V_26 * V_27 = V_110 ;
struct V_1 * V_1 = V_27 -> V_1 ;
switch ( V_169 -> V_160 ) {
case V_162 :
V_169 -> V_170 = F_42 ( V_1 , V_171 )
? 1 : 0 ;
return 0 ;
}
return - V_18 ;
}
static int F_116 ( struct V_95 * V_95 , void * V_110 ,
struct V_168 * V_169 )
{
struct V_26 * V_27 = V_110 ;
struct V_1 * V_1 = V_27 -> V_1 ;
switch ( V_169 -> V_160 ) {
case V_162 :
if ( V_169 -> V_170 ) {
F_2 ( V_1 , V_172 ,
V_173 |
F_117 ( 0x20 ) |
F_118 ( 0x10 ) |
F_119 ( 0x10 ) ) ;
F_2 ( V_1 , V_171 ,
V_174 |
F_117 ( 0x10 ) |
F_118 ( 0x80 ) |
F_119 ( 0x10 ) ) ;
} else {
F_2 ( V_1 , V_172 , 0 ) ;
F_2 ( V_1 , V_171 , 0 ) ;
}
return 0 ;
}
return - V_18 ;
}
int F_120 ( struct V_1 * V_1 )
{
int V_30 ;
int V_19 ;
F_121 ( & V_1 -> V_8 ) ;
V_1 -> V_175 = F_122 () ;
if ( ! V_1 -> V_175 )
return - V_102 ;
* V_1 -> V_175 = V_176 ;
V_1 -> V_175 -> V_177 = & V_1 -> V_104 -> V_92 ;
V_30 = F_123 ( V_1 -> V_175 , V_178 , V_179 ) ;
if ( V_30 < 0 ) {
F_124 ( V_1 -> V_175 ) ;
V_1 -> V_175 = NULL ;
return V_30 ;
}
F_125 ( V_1 -> V_175 , V_1 ) ;
snprintf ( V_1 -> V_175 -> V_129 , sizeof( V_1 -> V_175 -> V_129 ) , L_14 ,
V_76 , V_1 -> V_175 -> V_180 ) ;
if ( V_179 != - 1 )
V_179 ++ ;
F_126 ( & V_1 -> V_104 -> V_92 , L_15
L_16 , V_1 -> V_175 -> V_180 ,
V_1 -> V_15 , V_1 -> V_24 ) ;
for ( V_19 = 0 ; V_19 < V_1 -> V_15 ; V_19 ++ ) {
F_19 ( V_1 , V_19 ) ;
while ( F_3 ( V_1 ) )
;
}
F_19 ( V_1 , 0 ) ;
while ( F_3 ( V_1 ) )
;
F_127 ( V_1 , V_7 ) ;
return 0 ;
}
void F_128 ( struct V_1 * V_1 )
{
F_129 ( V_1 , V_7 ) ;
if ( V_1 -> V_175 ) {
F_130 ( V_1 -> V_175 ) ;
V_1 -> V_175 = NULL ;
}
}
