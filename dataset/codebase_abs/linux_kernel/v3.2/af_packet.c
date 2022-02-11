static struct V_1 * F_1 ( struct V_2 * V_3 )
{
return (struct V_1 * ) V_3 ;
}
static void F_2 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
if ( ! V_4 -> V_5 ) {
if ( V_4 -> V_6 )
F_3 ( V_3 , V_4 ) ;
else
F_4 ( & V_4 -> V_7 ) ;
F_5 ( V_3 ) ;
V_4 -> V_5 = 1 ;
}
}
static void F_6 ( struct V_2 * V_3 , bool V_8 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
V_4 -> V_5 = 0 ;
if ( V_4 -> V_6 )
F_7 ( V_3 , V_4 ) ;
else
F_8 ( & V_4 -> V_7 ) ;
F_9 ( V_3 ) ;
if ( V_8 ) {
F_10 ( & V_4 -> V_9 ) ;
F_11 () ;
F_12 ( & V_4 -> V_9 ) ;
}
}
static void F_13 ( struct V_2 * V_3 , bool V_8 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
if ( V_4 -> V_5 )
F_6 ( V_3 , V_8 ) ;
}
void F_14 ( struct V_1 * V_4 , void * V_10 , int V_11 )
{
union {
struct V_12 * V_13 ;
struct V_14 * V_15 ;
void * V_16 ;
} V_17 ;
V_17 . V_16 = V_10 ;
switch ( V_4 -> V_18 ) {
case V_19 :
V_17 . V_13 -> V_20 = V_11 ;
F_15 ( F_16 ( & V_17 . V_13 -> V_20 ) ) ;
break;
case V_21 :
V_17 . V_15 -> V_20 = V_11 ;
F_15 ( F_16 ( & V_17 . V_15 -> V_20 ) ) ;
break;
case V_22 :
default:
F_17 ( 1 , L_1 ) ;
F_18 () ;
}
F_19 () ;
}
static int F_20 ( struct V_1 * V_4 , void * V_10 )
{
union {
struct V_12 * V_13 ;
struct V_14 * V_15 ;
void * V_16 ;
} V_17 ;
F_21 () ;
V_17 . V_16 = V_10 ;
switch ( V_4 -> V_18 ) {
case V_19 :
F_15 ( F_16 ( & V_17 . V_13 -> V_20 ) ) ;
return V_17 . V_13 -> V_20 ;
case V_21 :
F_15 ( F_16 ( & V_17 . V_15 -> V_20 ) ) ;
return V_17 . V_15 -> V_20 ;
case V_22 :
default:
F_17 ( 1 , L_1 ) ;
F_18 () ;
return 0 ;
}
}
static void * F_22 ( struct V_1 * V_4 ,
struct V_23 * V_24 ,
unsigned int V_25 ,
int V_11 )
{
unsigned int V_26 , V_27 ;
union {
struct V_12 * V_13 ;
struct V_14 * V_15 ;
void * V_16 ;
} V_17 ;
V_26 = V_25 / V_24 -> V_28 ;
V_27 = V_25 % V_24 -> V_28 ;
V_17 . V_16 = V_24 -> V_29 [ V_26 ] . V_30 +
( V_27 * V_24 -> V_31 ) ;
if ( V_11 != F_20 ( V_4 , V_17 . V_16 ) )
return NULL ;
return V_17 . V_16 ;
}
static void * F_23 ( struct V_1 * V_4 ,
struct V_23 * V_24 ,
int V_11 )
{
return F_22 ( V_4 , V_24 , V_24 -> V_32 , V_11 ) ;
}
static void F_24 ( struct V_33 * V_34 )
{
F_25 ( & V_34 -> V_35 ) ;
}
static void F_26 ( struct V_1 * V_4 ,
int V_36 ,
struct V_37 * V_38 )
{
struct V_33 * V_34 ;
V_34 = V_36 ? & V_4 -> V_36 . V_39 : & V_4 -> V_40 . V_39 ;
F_12 ( & V_38 -> V_41 ) ;
V_34 -> V_42 = 1 ;
F_10 ( & V_38 -> V_41 ) ;
F_24 ( V_34 ) ;
}
static void F_27 ( struct V_1 * V_4 ,
struct V_33 * V_34 ,
void (* F_28) ( unsigned long ) )
{
F_29 ( & V_34 -> V_35 ) ;
V_34 -> V_35 . V_43 = ( long ) V_4 ;
V_34 -> V_35 . V_44 = F_28 ;
V_34 -> V_35 . V_45 = V_46 ;
}
static void F_30 ( struct V_1 * V_4 , int V_36 )
{
struct V_33 * V_34 ;
if ( V_36 )
F_18 () ;
V_34 = V_36 ? & V_4 -> V_36 . V_39 : & V_4 -> V_40 . V_39 ;
F_27 ( V_4 , V_34 , V_47 ) ;
}
static int F_31 ( struct V_1 * V_4 ,
int V_48 )
{
struct V_49 * V_50 ;
unsigned int V_51 = 0 , V_52 = 0 , div = 0 , V_53 = 0 ;
struct V_54 V_55 ;
int V_56 ;
F_32 () ;
V_50 = F_33 ( F_34 ( & V_4 -> V_3 ) , V_4 -> V_57 ) ;
if ( F_35 ( ! V_50 ) ) {
F_36 () ;
return V_58 ;
}
V_56 = F_37 ( V_50 , & V_55 ) ;
F_36 () ;
if ( ! V_56 ) {
switch ( V_55 . V_59 ) {
case V_60 :
V_52 = 1 ;
div = 10000 / 1000 ;
break;
case V_61 :
V_52 = 1 ;
div = 1000 / 1000 ;
break;
case V_62 :
case V_63 :
default:
return V_58 ;
}
}
V_51 = ( V_48 * 8 ) / ( 1024 * 1024 ) ;
if ( div )
V_51 /= div ;
V_53 = V_51 * V_52 ;
if ( div )
return V_53 + 1 ;
return V_53 ;
}
static void F_38 ( struct V_33 * V_64 ,
union V_65 * V_66 )
{
V_64 -> V_67 = V_66 -> V_68 . V_69 ;
}
static void F_39 ( struct V_1 * V_4 ,
struct V_23 * V_24 ,
struct V_70 * V_29 ,
union V_65 * V_66 , int V_36 )
{
struct V_33 * V_64 = & V_24 -> V_39 ;
struct V_71 * V_72 ;
memset ( V_64 , 0x0 , sizeof( * V_64 ) ) ;
V_64 -> V_73 = 1 ;
V_64 -> V_74 = V_29 ;
V_72 = (struct V_71 * ) V_29 [ 0 ] . V_30 ;
V_64 -> V_75 = ( char * ) V_29 [ 0 ] . V_30 ;
V_64 -> V_76 = V_66 -> V_68 . V_77 ;
V_64 -> V_78 = V_66 -> V_68 . V_79 ;
V_64 -> V_80 = V_4 -> V_81 ;
V_64 -> V_82 = V_4 -> V_18 ;
V_64 -> V_83 = 0 ;
V_4 -> V_84 . V_85 . V_86 = 0 ;
if ( V_66 -> V_68 . V_87 )
V_64 -> V_88 = V_66 -> V_68 . V_87 ;
else
V_64 -> V_88 = F_31 ( V_4 ,
V_66 -> V_68 . V_77 ) ;
V_64 -> V_89 = F_40 ( V_64 -> V_88 ) ;
V_64 -> V_90 = V_66 -> V_68 . V_91 ;
F_38 ( V_64 , V_66 ) ;
F_30 ( V_4 , V_36 ) ;
F_41 ( V_64 , V_72 ) ;
}
static void F_42 ( struct V_33 * V_34 )
{
F_43 ( & V_34 -> V_35 ,
V_46 + V_34 -> V_89 ) ;
V_34 -> V_83 = V_34 -> V_92 ;
}
static void V_47 ( unsigned long V_43 )
{
struct V_1 * V_4 = (struct V_1 * ) V_43 ;
struct V_33 * V_34 = & V_4 -> V_40 . V_39 ;
unsigned int V_93 ;
struct V_71 * V_72 ;
F_12 ( & V_4 -> V_3 . V_94 . V_41 ) ;
V_93 = F_44 ( V_34 ) ;
V_72 = F_45 ( V_34 ) ;
if ( F_35 ( V_34 -> V_42 ) )
goto V_95;
if ( F_46 ( V_72 ) ) {
while ( F_47 ( & V_34 -> V_96 ) ) {
F_48 () ;
}
}
if ( V_34 -> V_83 == V_34 -> V_92 ) {
if ( ! V_93 ) {
F_49 ( V_34 , V_4 , V_97 ) ;
if ( ! F_50 ( V_34 , V_4 ) )
goto V_98;
else
goto V_95;
} else {
if ( F_51 ( V_34 , V_72 ) ) {
goto V_98;
} else {
F_41 ( V_34 , V_72 ) ;
goto V_95;
}
}
}
V_98:
F_42 ( V_34 ) ;
V_95:
F_10 ( & V_4 -> V_3 . V_94 . V_41 ) ;
}
static void F_52 ( struct V_33 * V_99 ,
struct V_71 * V_100 , T_1 V_11 )
{
#if V_101 == 1
T_2 * V_102 , * V_103 ;
V_102 = ( T_2 * ) V_100 ;
V_102 += V_104 ;
V_103 = ( T_2 * ) F_53 ( ( unsigned long ) V_99 -> V_105 ) ;
for (; V_102 < V_103 ; V_102 += V_104 )
F_15 ( F_16 ( V_102 ) ) ;
F_19 () ;
#endif
F_54 ( V_100 ) = V_11 ;
#if V_101 == 1
V_102 = ( T_2 * ) V_100 ;
F_15 ( F_16 ( V_102 ) ) ;
F_19 () ;
#endif
}
static void F_55 ( struct V_33 * V_99 ,
struct V_71 * V_100 ,
struct V_1 * V_4 , unsigned int V_106 )
{
T_1 V_11 = V_107 | V_106 ;
struct V_108 * V_109 ;
struct V_110 * V_13 = & V_100 -> V_111 . V_112 ;
if ( V_4 -> V_113 . V_114 )
V_11 |= V_115 ;
V_109 = (struct V_108 * ) V_99 -> V_116 ;
V_109 -> V_117 = 0 ;
if ( F_46 ( V_100 ) ) {
V_13 -> V_118 . V_119 = V_109 -> V_120 ;
V_13 -> V_118 . V_121 = V_109 -> V_122 ;
} else {
struct V_123 V_124 ;
F_56 ( & V_124 ) ;
V_13 -> V_118 . V_119 = V_124 . V_125 ;
V_13 -> V_118 . V_121 = V_124 . V_126 ;
}
F_19 () ;
F_52 ( V_99 , V_100 , V_11 ) ;
V_99 -> V_92 = F_57 ( V_99 ) ;
}
static void F_58 ( struct V_33 * V_34 )
{
V_34 -> V_127 = 0 ;
}
static void F_41 ( struct V_33 * V_99 ,
struct V_71 * V_100 )
{
struct V_123 V_124 ;
struct V_110 * V_13 = & V_100 -> V_111 . V_112 ;
F_21 () ;
if ( F_59 ( V_128 == F_54 ( V_100 ) ) ) {
F_60 ( V_100 ) = V_99 -> V_73 ++ ;
F_46 ( V_100 ) = 0 ;
F_61 ( V_100 ) = F_62 ( V_99 -> V_90 ) ;
F_56 ( & V_124 ) ;
V_13 -> V_129 . V_119 = V_124 . V_125 ;
V_13 -> V_129 . V_121 = V_124 . V_126 ;
V_99 -> V_75 = ( char * ) V_100 ;
V_99 -> V_130 = ( char * ) ( V_99 -> V_75 +
F_62 ( V_99 -> V_90 ) ) ;
F_63 ( V_100 ) = ( T_1 ) F_62 ( V_99 -> V_90 ) ;
F_64 ( V_100 ) = V_131 ;
V_100 -> V_82 = V_99 -> V_82 ;
V_99 -> V_116 = V_99 -> V_130 ;
V_99 -> V_105 = V_99 -> V_75 + V_99 -> V_76 ;
F_58 ( V_99 ) ;
F_42 ( V_99 ) ;
F_19 () ;
return;
}
F_17 ( 1 , L_2 ,
V_100 , F_54 ( V_100 ) , V_99 -> V_92 ) ;
F_65 () ;
F_18 () ;
}
static void F_66 ( struct V_33 * V_34 ,
struct V_1 * V_4 )
{
V_34 -> V_127 = 1 ;
V_4 -> V_84 . V_85 . V_86 ++ ;
}
static void * F_50 ( struct V_33 * V_34 ,
struct V_1 * V_4 )
{
struct V_71 * V_72 ;
F_21 () ;
V_72 = F_45 ( V_34 ) ;
if ( V_107 & F_54 ( V_72 ) ) {
F_66 ( V_34 , V_4 ) ;
return NULL ;
}
F_41 ( V_34 , V_72 ) ;
return ( void * ) V_34 -> V_130 ;
}
static void F_49 ( struct V_33 * V_34 ,
struct V_1 * V_4 , unsigned int V_11 )
{
struct V_71 * V_72 = F_45 ( V_34 ) ;
if ( F_59 ( V_128 == F_54 ( V_72 ) ) ) {
if ( ! ( V_11 & V_97 ) ) {
while ( F_47 ( & V_34 -> V_96 ) ) {
F_48 () ;
}
}
F_55 ( V_34 , V_72 , V_4 , V_11 ) ;
return;
}
F_17 ( 1 , L_3 , V_34 -> V_92 , V_72 ) ;
F_65 () ;
F_18 () ;
}
static int F_51 ( struct V_33 * V_34 ,
struct V_71 * V_72 )
{
return V_107 & F_54 ( V_72 ) ;
}
static int F_44 ( struct V_33 * V_34 )
{
return V_34 -> V_127 ;
}
static void F_67 ( struct V_23 * V_24 )
{
struct V_33 * V_34 = F_68 ( V_24 ) ;
F_69 ( & V_34 -> V_96 ) ;
}
static void F_70 ( struct V_33 * V_34 ,
struct V_108 * V_132 )
{
V_132 -> V_133 . V_134 = F_71 ( V_34 -> V_135 ) ;
}
static void F_72 ( struct V_33 * V_34 ,
struct V_108 * V_132 )
{
V_132 -> V_133 . V_134 = 0 ;
}
static void F_73 ( struct V_33 * V_34 ,
struct V_108 * V_132 )
{
if ( F_74 ( V_34 -> V_135 ) ) {
V_132 -> V_133 . V_136 = F_75 ( V_34 -> V_135 ) ;
V_132 -> V_20 = V_137 ;
} else {
V_132 -> V_133 . V_136 = V_132 -> V_20 = 0 ;
}
}
static void F_76 ( struct V_33 * V_34 ,
struct V_108 * V_132 )
{
F_73 ( V_34 , V_132 ) ;
if ( V_34 -> V_67 & V_138 )
F_70 ( V_34 , V_132 ) ;
else
F_72 ( V_34 , V_132 ) ;
}
static void F_77 ( char * V_139 ,
struct V_33 * V_34 ,
struct V_71 * V_72 ,
unsigned int V_140 )
{
struct V_108 * V_132 ;
V_132 = (struct V_108 * ) V_139 ;
V_132 -> V_117 = F_78 ( V_140 ) ;
V_34 -> V_116 = V_139 ;
V_34 -> V_130 += F_78 ( V_140 ) ;
F_61 ( V_72 ) += F_78 ( V_140 ) ;
F_46 ( V_72 ) += 1 ;
F_79 ( & V_34 -> V_96 ) ;
F_76 ( V_34 , V_132 ) ;
}
static void * F_80 ( struct V_1 * V_4 ,
struct V_141 * V_135 ,
int V_11 ,
unsigned int V_140
)
{
struct V_33 * V_34 ;
struct V_71 * V_72 ;
char * V_139 , * V_103 ;
V_34 = F_68 ( ( (struct V_23 * ) & V_4 -> V_40 ) ) ;
V_72 = F_45 ( V_34 ) ;
if ( F_44 ( V_34 ) ) {
if ( F_51 ( V_34 , V_72 ) ) {
return NULL ;
} else {
F_41 ( V_34 , V_72 ) ;
}
}
F_81 () ;
V_139 = V_34 -> V_130 ;
V_34 -> V_135 = V_135 ;
V_103 = ( char * ) ( ( char * ) V_72 + V_34 -> V_76 ) ;
if ( V_139 + F_78 ( V_140 ) < V_103 ) {
F_77 ( V_139 , V_34 , V_72 , V_140 ) ;
return ( void * ) V_139 ;
}
F_49 ( V_34 , V_4 , 0 ) ;
V_139 = ( char * ) F_50 ( V_34 , V_4 ) ;
if ( V_139 ) {
V_72 = F_45 ( V_34 ) ;
F_77 ( V_139 , V_34 , V_72 , V_140 ) ;
return ( void * ) V_139 ;
}
return NULL ;
}
static void * F_82 ( struct V_1 * V_4 ,
struct V_141 * V_135 ,
int V_11 , unsigned int V_140 )
{
char * V_139 = NULL ;
switch ( V_4 -> V_18 ) {
case V_19 :
case V_21 :
V_139 = F_22 ( V_4 , & V_4 -> V_40 ,
V_4 -> V_40 . V_32 , V_11 ) ;
return V_139 ;
case V_22 :
return F_80 ( V_4 , V_135 , V_11 , V_140 ) ;
default:
F_17 ( 1 , L_4 ) ;
F_18 () ;
return 0 ;
}
}
static void * F_83 ( struct V_1 * V_4 ,
struct V_23 * V_24 ,
unsigned int V_142 ,
int V_11 )
{
struct V_33 * V_34 = F_68 ( V_24 ) ;
struct V_71 * V_72 = F_84 ( V_34 , V_142 ) ;
if ( V_11 != F_54 ( V_72 ) )
return NULL ;
return V_72 ;
}
static int F_85 ( struct V_23 * V_24 )
{
unsigned int V_116 ;
if ( V_24 -> V_39 . V_92 )
V_116 = V_24 -> V_39 . V_92 - 1 ;
else
V_116 = V_24 -> V_39 . V_78 - 1 ;
return V_116 ;
}
static void * F_86 ( struct V_1 * V_4 ,
struct V_23 * V_24 ,
int V_11 )
{
unsigned int V_142 = F_85 ( V_24 ) ;
return F_83 ( V_4 , V_24 , V_142 , V_11 ) ;
}
static void * F_87 ( struct V_1 * V_4 ,
struct V_23 * V_24 ,
int V_11 )
{
if ( V_4 -> V_18 <= V_21 )
return F_88 ( V_4 , V_24 , V_11 ) ;
return F_86 ( V_4 , V_24 , V_11 ) ;
}
static void F_89 ( struct V_1 * V_4 ,
struct V_23 * V_24 )
{
switch ( V_4 -> V_18 ) {
case V_19 :
case V_21 :
return F_90 ( V_24 ) ;
case V_22 :
default:
F_17 ( 1 , L_1 ) ;
F_18 () ;
return;
}
}
static void * F_88 ( struct V_1 * V_4 ,
struct V_23 * V_24 ,
int V_11 )
{
unsigned int V_142 = V_24 -> V_32 ? V_24 -> V_32 - 1 : V_24 -> V_143 ;
return F_22 ( V_4 , V_24 , V_142 , V_11 ) ;
}
static void F_90 ( struct V_23 * V_144 )
{
V_144 -> V_32 = V_144 -> V_32 != V_144 -> V_143 ? V_144 -> V_32 + 1 : 0 ;
}
static void F_91 ( struct V_2 * V_3 )
{
F_92 ( & V_3 -> V_145 ) ;
F_93 ( F_47 ( & V_3 -> V_146 ) ) ;
F_93 ( F_47 ( & V_3 -> V_147 ) ) ;
if ( ! F_94 ( V_3 , V_148 ) ) {
F_95 ( L_5 , V_3 ) ;
return;
}
F_96 ( V_3 ) ;
}
static int F_97 ( struct V_149 * V_150 , unsigned int V_151 )
{
int V_152 = F_47 ( & V_150 -> V_153 ) + 1 ;
if ( V_152 >= V_151 )
V_152 = 0 ;
return V_152 ;
}
static struct V_2 * F_98 ( struct V_149 * V_150 , struct V_141 * V_135 , unsigned int V_151 )
{
T_3 V_154 , V_155 = V_135 -> V_156 ;
V_154 = ( ( V_157 ) V_155 * V_151 ) >> 32 ;
return V_150 -> V_158 [ V_154 ] ;
}
static struct V_2 * F_99 ( struct V_149 * V_150 , struct V_141 * V_135 , unsigned int V_151 )
{
int V_159 , V_160 ;
V_159 = F_47 ( & V_150 -> V_153 ) ;
while ( ( V_160 = F_100 ( & V_150 -> V_153 , V_159 ,
F_97 ( V_150 , V_151 ) ) ) != V_159 )
V_159 = V_160 ;
return V_150 -> V_158 [ V_159 ] ;
}
static struct V_2 * F_101 ( struct V_149 * V_150 , struct V_141 * V_135 , unsigned int V_151 )
{
unsigned int V_161 = F_102 () ;
return V_150 -> V_158 [ V_161 % V_151 ] ;
}
static int F_103 ( struct V_141 * V_135 , struct V_49 * V_50 ,
struct V_162 * V_163 , struct V_49 * V_164 )
{
struct V_149 * V_150 = V_163 -> V_165 ;
unsigned int V_151 = V_150 -> V_166 ;
struct V_1 * V_4 ;
struct V_2 * V_3 ;
if ( ! F_104 ( F_105 ( V_50 ) , F_106 ( & V_150 -> V_167 ) ) ||
! V_151 ) {
F_107 ( V_135 ) ;
return 0 ;
}
switch ( V_150 -> type ) {
case V_168 :
default:
if ( V_150 -> V_169 ) {
V_135 = F_108 ( V_135 , V_170 ) ;
if ( ! V_135 )
return 0 ;
}
F_71 ( V_135 ) ;
V_3 = F_98 ( V_150 , V_135 , V_151 ) ;
break;
case V_171 :
V_3 = F_99 ( V_150 , V_135 , V_151 ) ;
break;
case V_172 :
V_3 = F_101 ( V_150 , V_135 , V_151 ) ;
break;
}
V_4 = F_1 ( V_3 ) ;
return V_4 -> V_7 . F_28 ( V_135 , V_50 , & V_4 -> V_7 , V_164 ) ;
}
static void F_3 ( struct V_2 * V_3 , struct V_1 * V_4 )
{
struct V_149 * V_150 = V_4 -> V_6 ;
F_12 ( & V_150 -> V_41 ) ;
V_150 -> V_158 [ V_150 -> V_166 ] = V_3 ;
F_19 () ;
V_150 -> V_166 ++ ;
F_10 ( & V_150 -> V_41 ) ;
}
static void F_7 ( struct V_2 * V_3 , struct V_1 * V_4 )
{
struct V_149 * V_150 = V_4 -> V_6 ;
int V_173 ;
F_12 ( & V_150 -> V_41 ) ;
for ( V_173 = 0 ; V_173 < V_150 -> V_166 ; V_173 ++ ) {
if ( V_150 -> V_158 [ V_173 ] == V_3 )
break;
}
F_109 ( V_173 >= V_150 -> V_166 ) ;
V_150 -> V_158 [ V_173 ] = V_150 -> V_158 [ V_150 -> V_166 - 1 ] ;
V_150 -> V_166 -- ;
F_10 ( & V_150 -> V_41 ) ;
}
static int F_110 ( struct V_2 * V_3 , T_4 V_174 , T_4 V_175 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
struct V_149 * V_150 , * V_176 ;
T_2 type = V_175 & 0xff ;
T_2 V_169 = ( V_175 & V_177 ) ? 1 : 0 ;
int V_56 ;
switch ( type ) {
case V_168 :
case V_171 :
case V_172 :
break;
default:
return - V_178 ;
}
if ( ! V_4 -> V_5 )
return - V_178 ;
if ( V_4 -> V_6 )
return - V_179 ;
F_111 ( & V_180 ) ;
V_176 = NULL ;
F_112 (f, &fanout_list, list) {
if ( V_150 -> V_174 == V_174 &&
F_106 ( & V_150 -> V_167 ) == F_34 ( V_3 ) ) {
V_176 = V_150 ;
break;
}
}
V_56 = - V_178 ;
if ( V_176 && V_176 -> V_169 != V_169 )
goto V_95;
if ( ! V_176 ) {
V_56 = - V_181 ;
V_176 = F_113 ( sizeof( * V_176 ) , V_182 ) ;
if ( ! V_176 )
goto V_95;
F_114 ( & V_176 -> V_167 , F_34 ( V_3 ) ) ;
V_176 -> V_174 = V_174 ;
V_176 -> type = type ;
V_176 -> V_169 = V_169 ;
F_115 ( & V_176 -> V_153 , 0 ) ;
F_116 ( & V_176 -> V_183 ) ;
F_117 ( & V_176 -> V_41 ) ;
F_115 ( & V_176 -> V_184 , 0 ) ;
V_176 -> V_7 . type = V_4 -> V_7 . type ;
V_176 -> V_7 . V_50 = V_4 -> V_7 . V_50 ;
V_176 -> V_7 . F_28 = F_103 ;
V_176 -> V_7 . V_165 = V_176 ;
F_4 ( & V_176 -> V_7 ) ;
F_118 ( & V_176 -> V_183 , & V_185 ) ;
}
V_56 = - V_178 ;
if ( V_176 -> type == type &&
V_176 -> V_7 . type == V_4 -> V_7 . type &&
V_176 -> V_7 . V_50 == V_4 -> V_7 . V_50 ) {
V_56 = - V_186 ;
if ( F_47 ( & V_176 -> V_184 ) < V_187 ) {
F_8 ( & V_4 -> V_7 ) ;
V_4 -> V_6 = V_176 ;
F_79 ( & V_176 -> V_184 ) ;
F_3 ( V_3 , V_4 ) ;
V_56 = 0 ;
}
}
V_95:
F_119 ( & V_180 ) ;
return V_56 ;
}
static void F_120 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
struct V_149 * V_150 ;
V_150 = V_4 -> V_6 ;
if ( ! V_150 )
return;
V_4 -> V_6 = NULL ;
F_111 ( & V_180 ) ;
if ( F_121 ( & V_150 -> V_184 ) ) {
F_122 ( & V_150 -> V_183 ) ;
F_123 ( & V_150 -> V_7 ) ;
F_124 ( V_150 ) ;
}
F_119 ( & V_180 ) ;
}
static int F_125 ( struct V_141 * V_135 , struct V_49 * V_50 ,
struct V_162 * V_163 , struct V_49 * V_164 )
{
struct V_2 * V_3 ;
struct V_188 * V_189 ;
V_3 = V_163 -> V_165 ;
if ( V_135 -> V_190 == V_191 )
goto V_95;
if ( ! F_104 ( F_105 ( V_50 ) , F_34 ( V_3 ) ) )
goto V_95;
V_135 = F_126 ( V_135 , V_192 ) ;
if ( V_135 == NULL )
goto V_193;
F_127 ( V_135 ) ;
F_128 ( V_135 ) ;
V_189 = & F_129 ( V_135 ) -> V_194 . V_195 ;
F_130 ( V_135 , V_135 -> V_43 - F_131 ( V_135 ) ) ;
V_189 -> V_196 = V_50 -> type ;
F_132 ( V_189 -> V_197 , V_50 -> V_198 , sizeof( V_189 -> V_197 ) ) ;
V_189 -> V_199 = V_135 -> V_200 ;
if ( F_133 ( V_3 , V_135 ) == 0 )
return 0 ;
V_95:
F_107 ( V_135 ) ;
V_193:
return 0 ;
}
static int F_134 ( struct V_201 * V_202 , struct V_203 * V_2 ,
struct V_204 * V_205 , T_5 V_140 )
{
struct V_2 * V_3 = V_2 -> V_3 ;
struct V_188 * V_206 = (struct V_188 * ) V_205 -> V_207 ;
struct V_141 * V_135 = NULL ;
struct V_49 * V_50 ;
T_6 V_208 = 0 ;
int V_56 ;
if ( V_206 ) {
if ( V_205 -> V_209 < sizeof( struct V_210 ) )
return - V_178 ;
if ( V_205 -> V_209 == sizeof( struct V_188 ) )
V_208 = V_206 -> V_199 ;
} else
return - V_211 ;
V_206 -> V_197 [ 13 ] = 0 ;
V_212:
F_135 () ;
V_50 = F_136 ( F_34 ( V_3 ) , V_206 -> V_197 ) ;
V_56 = - V_213 ;
if ( V_50 == NULL )
goto V_214;
V_56 = - V_215 ;
if ( ! ( V_50 -> V_216 & V_217 ) )
goto V_214;
V_56 = - V_218 ;
if ( V_140 > V_50 -> V_219 + V_50 -> V_220 + V_221 )
goto V_214;
if ( ! V_135 ) {
T_5 V_222 = F_137 ( V_50 ) ;
unsigned int V_223 = V_50 -> V_224 ? V_50 -> V_220 : 0 ;
F_138 () ;
V_135 = F_139 ( V_3 , V_140 + V_222 , 0 , V_182 ) ;
if ( V_135 == NULL )
return - V_225 ;
F_140 ( V_135 , V_222 ) ;
F_141 ( V_135 ) ;
if ( V_223 ) {
V_135 -> V_43 -= V_223 ;
V_135 -> V_226 -= V_223 ;
if ( V_140 < V_223 )
F_141 ( V_135 ) ;
}
V_56 = F_142 ( F_143 ( V_135 , V_140 ) , V_205 -> V_227 , V_140 ) ;
if ( V_56 )
goto V_228;
goto V_212;
}
if ( V_140 > ( V_50 -> V_219 + V_50 -> V_220 ) ) {
struct V_229 * V_230 ;
F_144 ( V_135 ) ;
V_230 = F_145 ( V_135 ) ;
if ( V_230 -> V_231 != F_146 ( V_232 ) ) {
V_56 = - V_218 ;
goto V_214;
}
}
V_135 -> V_200 = V_208 ;
V_135 -> V_50 = V_50 ;
V_135 -> V_233 = V_3 -> V_234 ;
V_135 -> V_235 = V_3 -> V_236 ;
V_56 = F_147 ( V_3 , & F_148 ( V_135 ) -> V_237 ) ;
if ( V_56 < 0 )
goto V_214;
F_149 ( V_135 ) ;
F_138 () ;
return V_140 ;
V_214:
F_138 () ;
V_228:
F_107 ( V_135 ) ;
return V_56 ;
}
static unsigned int F_150 ( const struct V_141 * V_135 ,
const struct V_2 * V_3 ,
unsigned int V_238 )
{
struct V_239 * V_240 ;
F_135 () ;
V_240 = F_151 ( V_3 -> V_239 ) ;
if ( V_240 != NULL )
V_238 = F_152 ( V_240 , V_135 ) ;
F_138 () ;
return V_238 ;
}
static int F_153 ( struct V_141 * V_135 , struct V_49 * V_50 ,
struct V_162 * V_163 , struct V_49 * V_164 )
{
struct V_2 * V_3 ;
struct V_241 * V_242 ;
struct V_1 * V_4 ;
T_2 * V_243 = V_135 -> V_43 ;
int V_244 = V_135 -> V_140 ;
unsigned int V_245 , V_238 ;
if ( V_135 -> V_190 == V_191 )
goto V_246;
V_3 = V_163 -> V_165 ;
V_4 = F_1 ( V_3 ) ;
if ( ! F_104 ( F_105 ( V_50 ) , F_34 ( V_3 ) ) )
goto V_246;
V_135 -> V_50 = V_50 ;
if ( V_50 -> V_224 ) {
if ( V_3 -> V_247 != V_248 )
F_130 ( V_135 , V_135 -> V_43 - F_131 ( V_135 ) ) ;
else if ( V_135 -> V_190 == V_249 ) {
F_154 ( V_135 , F_155 ( V_135 ) ) ;
}
}
V_245 = V_135 -> V_140 ;
V_238 = F_150 ( V_135 , V_3 , V_245 ) ;
if ( ! V_238 )
goto V_250;
if ( V_245 > V_238 )
V_245 = V_238 ;
if ( F_47 ( & V_3 -> V_146 ) >= V_3 -> V_251 )
goto V_252;
if ( F_156 ( V_135 ) ) {
struct V_141 * V_253 = F_157 ( V_135 , V_192 ) ;
if ( V_253 == NULL )
goto V_252;
if ( V_243 != V_135 -> V_43 ) {
V_135 -> V_43 = V_243 ;
V_135 -> V_140 = V_244 ;
}
F_107 ( V_135 ) ;
V_135 = V_253 ;
}
F_158 ( sizeof( * F_129 ( V_135 ) ) + V_254 - 8 >
sizeof( V_135 -> V_255 ) ) ;
V_242 = & F_129 ( V_135 ) -> V_194 . V_256 ;
V_242 -> V_257 = V_258 ;
V_242 -> V_259 = V_50 -> type ;
V_242 -> V_260 = V_135 -> V_200 ;
V_242 -> V_261 = V_135 -> V_190 ;
if ( F_35 ( V_4 -> V_262 ) )
V_242 -> V_263 = V_164 -> V_57 ;
else
V_242 -> V_263 = V_50 -> V_57 ;
V_242 -> V_264 = F_159 ( V_135 , V_242 -> V_265 ) ;
F_129 ( V_135 ) -> V_266 = V_135 -> V_140 ;
if ( F_160 ( V_135 , V_245 ) )
goto V_252;
F_161 ( V_135 , V_3 ) ;
V_135 -> V_50 = NULL ;
F_127 ( V_135 ) ;
F_128 ( V_135 ) ;
F_12 ( & V_3 -> V_94 . V_41 ) ;
V_4 -> V_113 . V_267 ++ ;
V_135 -> V_268 = F_47 ( & V_3 -> V_269 ) ;
F_162 ( & V_3 -> V_94 , V_135 ) ;
F_10 ( & V_3 -> V_94 . V_41 ) ;
V_3 -> V_270 ( V_3 , V_135 -> V_140 ) ;
return 0 ;
V_252:
F_12 ( & V_3 -> V_94 . V_41 ) ;
V_4 -> V_113 . V_114 ++ ;
F_79 ( & V_3 -> V_269 ) ;
F_10 ( & V_3 -> V_94 . V_41 ) ;
V_250:
if ( V_243 != V_135 -> V_43 && F_156 ( V_135 ) ) {
V_135 -> V_43 = V_243 ;
V_135 -> V_140 = V_244 ;
}
V_246:
F_163 ( V_135 ) ;
return 0 ;
}
static int F_164 ( struct V_141 * V_135 , struct V_49 * V_50 ,
struct V_162 * V_163 , struct V_49 * V_164 )
{
struct V_2 * V_3 ;
struct V_1 * V_4 ;
struct V_241 * V_242 ;
union {
struct V_12 * V_13 ;
struct V_14 * V_15 ;
struct V_108 * V_271 ;
void * V_16 ;
} V_17 ;
T_2 * V_243 = V_135 -> V_43 ;
int V_244 = V_135 -> V_140 ;
unsigned int V_245 , V_238 ;
unsigned long V_11 = V_107 ;
unsigned short V_272 , V_273 , V_80 ;
struct V_141 * V_274 = NULL ;
struct V_275 V_276 ;
struct V_123 V_124 ;
struct V_277 * V_278 = F_165 ( V_135 ) ;
if ( V_135 -> V_190 == V_191 )
goto V_246;
V_3 = V_163 -> V_165 ;
V_4 = F_1 ( V_3 ) ;
if ( ! F_104 ( F_105 ( V_50 ) , F_34 ( V_3 ) ) )
goto V_246;
if ( V_50 -> V_224 ) {
if ( V_3 -> V_247 != V_248 )
F_130 ( V_135 , V_135 -> V_43 - F_131 ( V_135 ) ) ;
else if ( V_135 -> V_190 == V_249 ) {
F_154 ( V_135 , F_155 ( V_135 ) ) ;
}
}
if ( V_135 -> V_279 == V_280 )
V_11 |= V_281 ;
V_245 = V_135 -> V_140 ;
V_238 = F_150 ( V_135 , V_3 , V_245 ) ;
if ( ! V_238 )
goto V_250;
if ( V_245 > V_238 )
V_245 = V_238 ;
if ( V_3 -> V_247 == V_248 ) {
V_272 = V_273 = F_166 ( V_4 -> V_81 ) + 16 +
V_4 -> V_282 ;
} else {
unsigned V_283 = F_155 ( V_135 ) ;
V_273 = F_166 ( V_4 -> V_81 +
( V_283 < 16 ? 16 : V_283 ) ) +
V_4 -> V_282 ;
V_272 = V_273 - V_283 ;
}
if ( V_4 -> V_18 <= V_21 ) {
if ( V_272 + V_245 > V_4 -> V_40 . V_31 ) {
if ( V_4 -> V_284 &&
F_47 ( & V_3 -> V_146 ) < V_3 -> V_251 ) {
if ( F_156 ( V_135 ) ) {
V_274 = F_157 ( V_135 , V_192 ) ;
} else {
V_274 = F_167 ( V_135 ) ;
V_243 = V_135 -> V_43 ;
}
if ( V_274 )
F_161 ( V_274 , V_3 ) ;
}
V_245 = V_4 -> V_40 . V_31 - V_272 ;
if ( ( int ) V_245 < 0 )
V_245 = 0 ;
}
}
F_12 ( & V_3 -> V_94 . V_41 ) ;
V_17 . V_16 = F_82 ( V_4 , V_135 ,
V_128 , ( V_272 + V_245 ) ) ;
if ( ! V_17 . V_16 )
goto V_285;
if ( V_4 -> V_18 <= V_21 ) {
F_89 ( V_4 , & V_4 -> V_40 ) ;
if ( V_4 -> V_113 . V_114 )
V_11 |= V_115 ;
}
V_4 -> V_113 . V_267 ++ ;
if ( V_274 ) {
V_11 |= V_286 ;
F_162 ( & V_3 -> V_94 , V_274 ) ;
}
F_10 ( & V_3 -> V_94 . V_41 ) ;
F_168 ( V_135 , 0 , V_17 . V_16 + V_272 , V_245 ) ;
switch ( V_4 -> V_18 ) {
case V_19 :
V_17 . V_13 -> V_287 = V_135 -> V_140 ;
V_17 . V_13 -> V_288 = V_245 ;
V_17 . V_13 -> V_289 = V_272 ;
V_17 . V_13 -> V_290 = V_273 ;
if ( ( V_4 -> V_291 & V_292 )
&& V_278 -> V_293 . V_294 )
V_276 = F_169 ( V_278 -> V_293 ) ;
else if ( ( V_4 -> V_291 & V_295 )
&& V_278 -> V_296 . V_294 )
V_276 = F_169 ( V_278 -> V_296 ) ;
else if ( V_135 -> V_297 . V_294 )
V_276 = F_169 ( V_135 -> V_297 ) ;
else
F_170 ( & V_276 ) ;
V_17 . V_13 -> V_120 = V_276 . V_125 ;
V_17 . V_13 -> V_298 = V_276 . V_299 ;
V_80 = sizeof( * V_17 . V_13 ) ;
break;
case V_21 :
V_17 . V_15 -> V_287 = V_135 -> V_140 ;
V_17 . V_15 -> V_288 = V_245 ;
V_17 . V_15 -> V_289 = V_272 ;
V_17 . V_15 -> V_290 = V_273 ;
if ( ( V_4 -> V_291 & V_292 )
&& V_278 -> V_293 . V_294 )
V_124 = F_171 ( V_278 -> V_293 ) ;
else if ( ( V_4 -> V_291 & V_295 )
&& V_278 -> V_296 . V_294 )
V_124 = F_171 ( V_278 -> V_296 ) ;
else if ( V_135 -> V_297 . V_294 )
V_124 = F_171 ( V_135 -> V_297 ) ;
else
F_56 ( & V_124 ) ;
V_17 . V_15 -> V_120 = V_124 . V_125 ;
V_17 . V_15 -> V_122 = V_124 . V_126 ;
if ( F_74 ( V_135 ) ) {
V_17 . V_15 -> V_136 = F_75 ( V_135 ) ;
V_11 |= V_137 ;
} else {
V_17 . V_15 -> V_136 = 0 ;
}
V_17 . V_15 -> V_300 = 0 ;
V_80 = sizeof( * V_17 . V_15 ) ;
break;
case V_22 :
V_17 . V_271 -> V_20 |= V_11 ;
V_17 . V_271 -> V_287 = V_135 -> V_140 ;
V_17 . V_271 -> V_288 = V_245 ;
V_17 . V_271 -> V_289 = V_272 ;
V_17 . V_271 -> V_290 = V_273 ;
if ( ( V_4 -> V_291 & V_292 )
&& V_278 -> V_293 . V_294 )
V_124 = F_171 ( V_278 -> V_293 ) ;
else if ( ( V_4 -> V_291 & V_295 )
&& V_278 -> V_296 . V_294 )
V_124 = F_171 ( V_278 -> V_296 ) ;
else if ( V_135 -> V_297 . V_294 )
V_124 = F_171 ( V_135 -> V_297 ) ;
else
F_56 ( & V_124 ) ;
V_17 . V_271 -> V_120 = V_124 . V_125 ;
V_17 . V_271 -> V_122 = V_124 . V_126 ;
V_80 = sizeof( * V_17 . V_271 ) ;
break;
default:
F_18 () ;
}
V_242 = V_17 . V_16 + F_166 ( V_80 ) ;
V_242 -> V_264 = F_159 ( V_135 , V_242 -> V_265 ) ;
V_242 -> V_257 = V_258 ;
V_242 -> V_259 = V_50 -> type ;
V_242 -> V_260 = V_135 -> V_200 ;
V_242 -> V_261 = V_135 -> V_190 ;
if ( F_35 ( V_4 -> V_262 ) )
V_242 -> V_263 = V_164 -> V_57 ;
else
V_242 -> V_263 = V_50 -> V_57 ;
F_81 () ;
#if V_101 == 1
{
T_2 * V_102 , * V_103 ;
if ( V_4 -> V_18 <= V_21 ) {
V_103 = ( T_2 * ) F_53 ( ( unsigned long ) V_17 . V_16
+ V_272 + V_245 ) ;
for ( V_102 = V_17 . V_16 ; V_102 < V_103 ; V_102 += V_104 )
F_15 ( F_16 ( V_102 ) ) ;
}
F_19 () ;
}
#endif
if ( V_4 -> V_18 <= V_21 )
F_14 ( V_4 , V_17 . V_16 , V_11 ) ;
else
F_67 ( & V_4 -> V_40 ) ;
V_3 -> V_270 ( V_3 , 0 ) ;
V_250:
if ( V_243 != V_135 -> V_43 && F_156 ( V_135 ) ) {
V_135 -> V_43 = V_243 ;
V_135 -> V_140 = V_244 ;
}
V_246:
F_107 ( V_135 ) ;
return 0 ;
V_285:
V_4 -> V_113 . V_114 ++ ;
F_10 ( & V_3 -> V_94 . V_41 ) ;
V_3 -> V_270 ( V_3 , 0 ) ;
F_107 ( V_274 ) ;
goto V_250;
}
static void F_172 ( struct V_141 * V_135 )
{
struct V_1 * V_4 = F_1 ( V_135 -> V_3 ) ;
void * V_301 ;
if ( F_59 ( V_4 -> V_36 . V_29 ) ) {
V_301 = F_148 ( V_135 ) -> V_302 ;
F_109 ( F_20 ( V_4 , V_301 ) != V_303 ) ;
F_109 ( F_47 ( & V_4 -> V_36 . V_304 ) == 0 ) ;
F_69 ( & V_4 -> V_36 . V_304 ) ;
F_14 ( V_4 , V_301 , V_305 ) ;
}
F_173 ( V_135 ) ;
}
static int F_174 ( struct V_1 * V_4 , struct V_141 * V_135 ,
void * V_10 , struct V_49 * V_50 , int V_306 ,
T_6 V_208 , unsigned char * V_307 )
{
union {
struct V_12 * V_13 ;
struct V_14 * V_15 ;
void * V_16 ;
} V_301 ;
int V_308 , V_309 , V_140 , V_287 , V_310 , V_311 ;
struct V_203 * V_2 = V_4 -> V_3 . V_312 ;
struct V_313 * V_313 ;
void * V_43 ;
int V_56 ;
V_301 . V_16 = V_10 ;
V_135 -> V_200 = V_208 ;
V_135 -> V_50 = V_50 ;
V_135 -> V_233 = V_4 -> V_3 . V_234 ;
V_135 -> V_235 = V_4 -> V_3 . V_236 ;
F_148 ( V_135 ) -> V_302 = V_301 . V_16 ;
switch ( V_4 -> V_18 ) {
case V_21 :
V_287 = V_301 . V_15 -> V_287 ;
break;
default:
V_287 = V_301 . V_13 -> V_287 ;
break;
}
if ( F_35 ( V_287 > V_306 ) ) {
F_95 ( L_6 , V_287 , V_306 ) ;
return - V_218 ;
}
F_140 ( V_135 , F_137 ( V_50 ) ) ;
F_141 ( V_135 ) ;
V_43 = V_301 . V_16 + V_4 -> V_81 - sizeof( struct V_241 ) ;
V_308 = V_287 ;
if ( V_2 -> type == V_248 ) {
V_56 = F_175 ( V_135 , V_50 , F_176 ( V_208 ) , V_307 ,
NULL , V_287 ) ;
if ( F_35 ( V_56 < 0 ) )
return - V_178 ;
} else if ( V_50 -> V_220 ) {
if ( F_35 ( V_287 <= V_50 -> V_220 ) ) {
F_95 ( L_7 ,
V_287 , V_50 -> V_220 ) ;
return - V_178 ;
}
F_130 ( V_135 , V_50 -> V_220 ) ;
V_56 = F_177 ( V_135 , 0 , V_43 ,
V_50 -> V_220 ) ;
if ( F_35 ( V_56 ) )
return V_56 ;
V_43 += V_50 -> V_220 ;
V_308 -= V_50 -> V_220 ;
}
V_56 = - V_314 ;
V_309 = F_178 ( V_43 ) ;
V_311 = V_104 - V_309 ;
V_140 = ( ( V_308 > V_311 ) ? V_311 : V_308 ) ;
V_135 -> V_315 = V_308 ;
V_135 -> V_140 += V_308 ;
V_135 -> V_316 += V_308 ;
F_179 ( V_308 , & V_4 -> V_3 . V_147 ) ;
while ( F_59 ( V_308 ) ) {
V_310 = F_148 ( V_135 ) -> V_310 ;
if ( F_35 ( V_310 >= V_317 ) ) {
F_95 ( L_8 ,
V_317 ) ;
return - V_314 ;
}
V_313 = F_16 ( V_43 ) ;
V_43 += V_140 ;
F_15 ( V_313 ) ;
F_180 ( V_313 ) ;
F_181 ( V_135 , V_310 , V_313 , V_309 , V_140 ) ;
V_308 -= V_140 ;
V_309 = 0 ;
V_311 = V_104 ;
V_140 = ( ( V_308 > V_311 ) ? V_311 : V_308 ) ;
}
return V_287 ;
}
static int F_182 ( struct V_1 * V_4 , struct V_204 * V_205 )
{
struct V_141 * V_135 ;
struct V_49 * V_50 ;
T_6 V_208 ;
bool V_318 = false ;
int V_56 , V_319 = 0 ;
void * V_301 ;
struct V_241 * V_206 = (struct V_241 * ) V_205 -> V_207 ;
int V_287 , V_306 ;
unsigned char * V_307 ;
int V_320 = 0 ;
int V_11 = 0 ;
F_111 ( & V_4 -> V_321 ) ;
V_56 = - V_322 ;
if ( V_206 == NULL ) {
V_50 = V_4 -> V_7 . V_50 ;
V_208 = V_4 -> V_151 ;
V_307 = NULL ;
} else {
V_56 = - V_178 ;
if ( V_205 -> V_209 < sizeof( struct V_241 ) )
goto V_95;
if ( V_205 -> V_209 < ( V_206 -> V_264
+ F_183 ( struct V_241 ,
V_265 ) ) )
goto V_95;
V_208 = V_206 -> V_260 ;
V_307 = V_206 -> V_265 ;
V_50 = F_184 ( F_34 ( & V_4 -> V_3 ) , V_206 -> V_263 ) ;
V_318 = true ;
}
V_56 = - V_323 ;
if ( F_35 ( V_50 == NULL ) )
goto V_95;
V_319 = V_50 -> V_220 ;
V_56 = - V_215 ;
if ( F_35 ( ! ( V_50 -> V_216 & V_217 ) ) )
goto V_324;
V_306 = V_4 -> V_36 . V_31
- ( V_4 -> V_81 - sizeof( struct V_241 ) ) ;
if ( V_306 > V_50 -> V_219 + V_319 )
V_306 = V_50 -> V_219 + V_319 ;
do {
V_301 = F_23 ( V_4 , & V_4 -> V_36 ,
V_325 ) ;
if ( F_35 ( V_301 == NULL ) ) {
F_185 () ;
continue;
}
V_11 = V_325 ;
V_135 = F_186 ( & V_4 -> V_3 ,
F_187 ( V_50 )
+ sizeof( struct V_241 ) ,
0 , & V_56 ) ;
if ( F_35 ( V_135 == NULL ) )
goto V_326;
V_287 = F_174 ( V_4 , V_135 , V_301 , V_50 , V_306 , V_208 ,
V_307 ) ;
if ( F_35 ( V_287 < 0 ) ) {
if ( V_4 -> V_327 ) {
F_14 ( V_4 , V_301 ,
V_305 ) ;
F_90 ( & V_4 -> V_36 ) ;
F_107 ( V_135 ) ;
continue;
} else {
V_11 = V_328 ;
V_56 = V_287 ;
goto V_326;
}
}
V_135 -> V_329 = F_172 ;
F_14 ( V_4 , V_301 , V_303 ) ;
F_79 ( & V_4 -> V_36 . V_304 ) ;
V_11 = V_325 ;
V_56 = F_149 ( V_135 ) ;
if ( F_35 ( V_56 > 0 ) ) {
V_56 = F_188 ( V_56 ) ;
if ( V_56 && F_20 ( V_4 , V_301 ) ==
V_305 ) {
V_135 = NULL ;
goto V_326;
}
V_56 = 0 ;
}
F_90 ( & V_4 -> V_36 ) ;
V_320 += V_287 ;
} while ( F_59 ( ( V_301 != NULL ) ||
( ( ! ( V_205 -> V_330 & V_331 ) ) &&
( F_47 ( & V_4 -> V_36 . V_304 ) ) ) )
);
V_56 = V_320 ;
goto V_324;
V_326:
F_14 ( V_4 , V_301 , V_11 ) ;
F_107 ( V_135 ) ;
V_324:
if ( V_318 )
F_189 ( V_50 ) ;
V_95:
F_119 ( & V_4 -> V_321 ) ;
return V_56 ;
}
static struct V_141 * F_190 ( struct V_2 * V_3 , T_5 V_332 ,
T_5 V_319 , T_5 V_140 ,
T_5 V_333 , int V_334 ,
int * V_56 )
{
struct V_141 * V_135 ;
if ( V_332 + V_140 < V_104 || ! V_333 )
V_333 = V_140 ;
V_135 = F_191 ( V_3 , V_332 + V_333 , V_140 - V_333 , V_334 ,
V_56 ) ;
if ( ! V_135 )
return NULL ;
F_140 ( V_135 , V_319 ) ;
F_143 ( V_135 , V_333 ) ;
V_135 -> V_315 = V_140 - V_333 ;
V_135 -> V_140 += V_140 - V_333 ;
return V_135 ;
}
static int F_192 ( struct V_203 * V_2 ,
struct V_204 * V_205 , T_5 V_140 )
{
struct V_2 * V_3 = V_2 -> V_3 ;
struct V_241 * V_206 = (struct V_241 * ) V_205 -> V_207 ;
struct V_141 * V_135 ;
struct V_49 * V_50 ;
T_6 V_208 ;
bool V_318 = false ;
unsigned char * V_307 ;
int V_56 , V_319 = 0 ;
struct V_335 V_336 = { 0 } ;
int V_309 = 0 ;
int V_337 ;
struct V_1 * V_4 = F_1 ( V_3 ) ;
unsigned short V_338 = 0 ;
if ( V_206 == NULL ) {
V_50 = V_4 -> V_7 . V_50 ;
V_208 = V_4 -> V_151 ;
V_307 = NULL ;
} else {
V_56 = - V_178 ;
if ( V_205 -> V_209 < sizeof( struct V_241 ) )
goto V_95;
if ( V_205 -> V_209 < ( V_206 -> V_264 + F_183 ( struct V_241 , V_265 ) ) )
goto V_95;
V_208 = V_206 -> V_260 ;
V_307 = V_206 -> V_265 ;
V_50 = F_184 ( F_34 ( V_3 ) , V_206 -> V_263 ) ;
V_318 = true ;
}
V_56 = - V_323 ;
if ( V_50 == NULL )
goto V_214;
if ( V_2 -> type == V_339 )
V_319 = V_50 -> V_220 ;
V_56 = - V_215 ;
if ( ! ( V_50 -> V_216 & V_217 ) )
goto V_214;
if ( V_4 -> V_340 ) {
V_337 = sizeof( V_336 ) ;
V_56 = - V_178 ;
if ( V_140 < V_337 )
goto V_214;
V_140 -= V_337 ;
V_56 = F_142 ( ( void * ) & V_336 , V_205 -> V_227 ,
V_337 ) ;
if ( V_56 < 0 )
goto V_214;
if ( ( V_336 . V_216 & V_341 ) &&
( V_336 . V_342 + V_336 . V_343 + 2 >
V_336 . V_344 ) )
V_336 . V_344 = V_336 . V_342 +
V_336 . V_343 + 2 ;
V_56 = - V_178 ;
if ( V_336 . V_344 > V_140 )
goto V_214;
if ( V_336 . V_338 != V_345 ) {
switch ( V_336 . V_338 & ~ V_346 ) {
case V_347 :
V_338 = V_348 ;
break;
case V_349 :
V_338 = V_350 ;
break;
case V_351 :
V_338 = V_352 ;
break;
default:
goto V_214;
}
if ( V_336 . V_338 & V_346 )
V_338 |= V_353 ;
if ( V_336 . V_354 == 0 )
goto V_214;
}
}
V_56 = - V_218 ;
if ( ! V_338 && ( V_140 > V_50 -> V_219 + V_319 + V_221 ) )
goto V_214;
V_56 = - V_225 ;
V_135 = F_190 ( V_3 , F_187 ( V_50 ) ,
F_137 ( V_50 ) , V_140 , V_336 . V_344 ,
V_205 -> V_330 & V_331 , & V_56 ) ;
if ( V_135 == NULL )
goto V_214;
F_193 ( V_135 , V_319 ) ;
V_56 = - V_178 ;
if ( V_2 -> type == V_248 &&
( V_309 = F_175 ( V_135 , V_50 , F_176 ( V_208 ) , V_307 , NULL , V_140 ) ) < 0 )
goto V_228;
V_56 = F_194 ( V_135 , V_309 , V_205 -> V_227 , 0 , V_140 ) ;
if ( V_56 )
goto V_228;
V_56 = F_147 ( V_3 , & F_148 ( V_135 ) -> V_237 ) ;
if ( V_56 < 0 )
goto V_228;
if ( ! V_338 && ( V_140 > V_50 -> V_219 + V_319 ) ) {
struct V_229 * V_230 ;
F_144 ( V_135 ) ;
V_230 = F_145 ( V_135 ) ;
if ( V_230 -> V_231 != F_146 ( V_232 ) ) {
V_56 = - V_218 ;
goto V_228;
}
}
V_135 -> V_200 = V_208 ;
V_135 -> V_50 = V_50 ;
V_135 -> V_233 = V_3 -> V_234 ;
V_135 -> V_235 = V_3 -> V_236 ;
if ( V_4 -> V_340 ) {
if ( V_336 . V_216 & V_341 ) {
if ( ! F_195 ( V_135 , V_336 . V_342 ,
V_336 . V_343 ) ) {
V_56 = - V_178 ;
goto V_228;
}
}
F_148 ( V_135 ) -> V_354 = V_336 . V_354 ;
F_148 ( V_135 ) -> V_338 = V_338 ;
F_148 ( V_135 ) -> V_338 |= V_355 ;
F_148 ( V_135 ) -> V_356 = 0 ;
V_140 += V_337 ;
}
V_56 = F_149 ( V_135 ) ;
if ( V_56 > 0 && ( V_56 = F_188 ( V_56 ) ) != 0 )
goto V_214;
if ( V_318 )
F_189 ( V_50 ) ;
return V_140 ;
V_228:
F_107 ( V_135 ) ;
V_214:
if ( V_50 && V_318 )
F_189 ( V_50 ) ;
V_95:
return V_56 ;
}
static int F_196 ( struct V_201 * V_202 , struct V_203 * V_2 ,
struct V_204 * V_205 , T_5 V_140 )
{
struct V_2 * V_3 = V_2 -> V_3 ;
struct V_1 * V_4 = F_1 ( V_3 ) ;
if ( V_4 -> V_36 . V_29 )
return F_182 ( V_4 , V_205 ) ;
else
return F_192 ( V_2 , V_205 , V_140 ) ;
}
static int F_197 ( struct V_203 * V_2 )
{
struct V_2 * V_3 = V_2 -> V_3 ;
struct V_1 * V_4 ;
struct V_167 * V_167 ;
union V_65 V_66 ;
if ( ! V_3 )
return 0 ;
V_167 = F_34 ( V_3 ) ;
V_4 = F_1 ( V_3 ) ;
F_198 ( & V_167 -> V_357 . V_358 ) ;
F_199 ( V_3 ) ;
F_200 ( V_167 , V_3 -> V_359 , - 1 ) ;
F_201 ( & V_167 -> V_357 . V_358 ) ;
F_12 ( & V_4 -> V_9 ) ;
F_13 ( V_3 , false ) ;
if ( V_4 -> V_7 . V_50 ) {
F_189 ( V_4 -> V_7 . V_50 ) ;
V_4 -> V_7 . V_50 = NULL ;
}
F_10 ( & V_4 -> V_9 ) ;
F_202 ( V_3 ) ;
memset ( & V_66 , 0 , sizeof( V_66 ) ) ;
if ( V_4 -> V_40 . V_29 )
F_203 ( V_3 , & V_66 , 1 , 0 ) ;
if ( V_4 -> V_36 . V_29 )
F_203 ( V_3 , & V_66 , 1 , 1 ) ;
F_120 ( V_3 ) ;
F_11 () ;
F_204 ( V_3 ) ;
V_2 -> V_3 = NULL ;
F_92 ( & V_3 -> V_94 ) ;
F_205 ( V_3 ) ;
F_206 ( V_3 ) ;
return 0 ;
}
static int F_207 ( struct V_2 * V_3 , struct V_49 * V_50 , T_6 V_200 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
if ( V_4 -> V_6 ) {
if ( V_50 )
F_189 ( V_50 ) ;
return - V_178 ;
}
F_208 ( V_3 ) ;
F_12 ( & V_4 -> V_9 ) ;
F_13 ( V_3 , true ) ;
V_4 -> V_151 = V_200 ;
V_4 -> V_7 . type = V_200 ;
if ( V_4 -> V_7 . V_50 )
F_189 ( V_4 -> V_7 . V_50 ) ;
V_4 -> V_7 . V_50 = V_50 ;
V_4 -> V_57 = V_50 ? V_50 -> V_57 : 0 ;
if ( V_200 == 0 )
goto V_214;
if ( ! V_50 || ( V_50 -> V_216 & V_217 ) ) {
F_2 ( V_3 ) ;
} else {
V_3 -> V_360 = V_215 ;
if ( ! F_94 ( V_3 , V_148 ) )
V_3 -> V_361 ( V_3 ) ;
}
V_214:
F_10 ( & V_4 -> V_9 ) ;
F_209 ( V_3 ) ;
return 0 ;
}
static int F_210 ( struct V_203 * V_2 , struct V_210 * V_362 ,
int V_363 )
{
struct V_2 * V_3 = V_2 -> V_3 ;
char V_198 [ 15 ] ;
struct V_49 * V_50 ;
int V_56 = - V_213 ;
if ( V_363 != sizeof( struct V_210 ) )
return - V_178 ;
F_132 ( V_198 , V_362 -> V_364 , sizeof( V_198 ) ) ;
V_50 = F_211 ( F_34 ( V_3 ) , V_198 ) ;
if ( V_50 )
V_56 = F_207 ( V_3 , V_50 , F_1 ( V_3 ) -> V_151 ) ;
return V_56 ;
}
static int F_212 ( struct V_203 * V_2 , struct V_210 * V_362 , int V_363 )
{
struct V_241 * V_242 = (struct V_241 * ) V_362 ;
struct V_2 * V_3 = V_2 -> V_3 ;
struct V_49 * V_50 = NULL ;
int V_56 ;
if ( V_363 < sizeof( struct V_241 ) )
return - V_178 ;
if ( V_242 -> V_257 != V_258 )
return - V_178 ;
if ( V_242 -> V_263 ) {
V_56 = - V_213 ;
V_50 = F_184 ( F_34 ( V_3 ) , V_242 -> V_263 ) ;
if ( V_50 == NULL )
goto V_95;
}
V_56 = F_207 ( V_3 , V_50 , V_242 -> V_260 ? : F_1 ( V_3 ) -> V_151 ) ;
V_95:
return V_56 ;
}
static int F_213 ( struct V_167 * V_167 , struct V_203 * V_2 , int V_200 ,
int V_365 )
{
struct V_2 * V_3 ;
struct V_1 * V_4 ;
T_6 V_208 = ( V_366 T_6 ) V_200 ;
int V_56 ;
if ( ! F_214 ( V_367 ) )
return - V_368 ;
if ( V_2 -> type != V_248 && V_2 -> type != V_339 &&
V_2 -> type != V_369 )
return - V_370 ;
V_2 -> V_371 = V_372 ;
V_56 = - V_225 ;
V_3 = F_215 ( V_167 , V_373 , V_182 , & V_374 ) ;
if ( V_3 == NULL )
goto V_95;
V_2 -> V_375 = & V_376 ;
if ( V_2 -> type == V_369 )
V_2 -> V_375 = & V_377 ;
F_216 ( V_2 , V_3 ) ;
V_4 = F_1 ( V_3 ) ;
V_3 -> V_378 = V_373 ;
V_4 -> V_151 = V_208 ;
V_3 -> V_379 = F_91 ;
F_217 ( V_3 ) ;
F_117 ( & V_4 -> V_9 ) ;
F_218 ( & V_4 -> V_321 ) ;
V_4 -> V_7 . F_28 = F_153 ;
if ( V_2 -> type == V_369 )
V_4 -> V_7 . F_28 = F_125 ;
V_4 -> V_7 . V_165 = V_3 ;
if ( V_208 ) {
V_4 -> V_7 . type = V_208 ;
F_2 ( V_3 ) ;
}
F_198 ( & V_167 -> V_357 . V_358 ) ;
F_219 ( V_3 , & V_167 -> V_357 . V_380 ) ;
F_200 ( V_167 , & V_374 , 1 ) ;
F_201 ( & V_167 -> V_357 . V_358 ) ;
return 0 ;
V_95:
return V_56 ;
}
static int F_220 ( struct V_2 * V_3 , struct V_204 * V_205 , int V_140 )
{
struct V_381 * V_382 ;
struct V_141 * V_135 , * V_383 ;
int V_384 , V_56 ;
V_56 = - V_385 ;
V_135 = F_221 ( & V_3 -> V_145 ) ;
if ( V_135 == NULL )
goto V_95;
V_384 = V_135 -> V_140 ;
if ( V_384 > V_140 ) {
V_205 -> V_330 |= V_386 ;
V_384 = V_140 ;
}
V_56 = F_222 ( V_135 , 0 , V_205 -> V_227 , V_384 ) ;
if ( V_56 )
goto V_387;
F_223 ( V_205 , V_3 , V_135 ) ;
V_382 = F_224 ( V_135 ) ;
F_225 ( V_205 , V_388 , V_389 ,
sizeof( V_382 -> V_390 ) , & V_382 -> V_390 ) ;
V_205 -> V_330 |= V_391 ;
V_56 = V_384 ;
F_198 ( & V_3 -> V_145 . V_41 ) ;
V_3 -> V_360 = 0 ;
if ( ( V_383 = F_226 ( & V_3 -> V_145 ) ) != NULL ) {
V_3 -> V_360 = F_224 ( V_383 ) -> V_390 . V_392 ;
F_201 ( & V_3 -> V_145 . V_41 ) ;
V_3 -> V_361 ( V_3 ) ;
} else
F_201 ( & V_3 -> V_145 . V_41 ) ;
V_387:
F_107 ( V_135 ) ;
V_95:
return V_56 ;
}
static int F_227 ( struct V_201 * V_202 , struct V_203 * V_2 ,
struct V_204 * V_205 , T_5 V_140 , int V_216 )
{
struct V_2 * V_3 = V_2 -> V_3 ;
struct V_141 * V_135 ;
int V_384 , V_56 ;
struct V_241 * V_242 ;
int V_337 = 0 ;
V_56 = - V_178 ;
if ( V_216 & ~ ( V_393 | V_331 | V_386 | V_394 | V_391 ) )
goto V_95;
#if 0
if (pkt_sk(sk)->ifindex < 0)
return -ENODEV;
#endif
if ( V_216 & V_391 ) {
V_56 = F_220 ( V_3 , V_205 , V_140 ) ;
goto V_95;
}
V_135 = F_228 ( V_3 , V_216 , V_216 & V_331 , & V_56 ) ;
if ( V_135 == NULL )
goto V_95;
if ( F_1 ( V_3 ) -> V_340 ) {
struct V_335 V_336 = { 0 } ;
V_56 = - V_178 ;
V_337 = sizeof( V_336 ) ;
if ( V_140 < V_337 )
goto V_228;
V_140 -= V_337 ;
if ( F_229 ( V_135 ) ) {
struct V_395 * V_396 = F_148 ( V_135 ) ;
V_336 . V_344 = F_230 ( V_135 ) ;
V_336 . V_354 = V_396 -> V_354 ;
if ( V_396 -> V_338 & V_348 )
V_336 . V_338 = V_347 ;
else if ( V_396 -> V_338 & V_350 )
V_336 . V_338 = V_349 ;
else if ( V_396 -> V_338 & V_352 )
V_336 . V_338 = V_351 ;
else if ( V_396 -> V_338 & V_397 )
goto V_228;
else
F_18 () ;
if ( V_396 -> V_338 & V_353 )
V_336 . V_338 |= V_346 ;
} else
V_336 . V_338 = V_345 ;
if ( V_135 -> V_279 == V_280 ) {
V_336 . V_216 = V_341 ;
V_336 . V_342 = F_231 ( V_135 ) ;
V_336 . V_343 = V_135 -> V_343 ;
} else if ( V_135 -> V_279 == V_398 ) {
V_336 . V_216 = V_399 ;
}
V_56 = F_232 ( V_205 -> V_227 , ( void * ) & V_336 ,
V_337 ) ;
if ( V_56 < 0 )
goto V_228;
}
V_242 = & F_129 ( V_135 ) -> V_194 . V_256 ;
if ( V_2 -> type == V_369 )
V_205 -> V_209 = sizeof( struct V_188 ) ;
else
V_205 -> V_209 = V_242 -> V_264 + F_183 ( struct V_241 , V_265 ) ;
V_384 = V_135 -> V_140 ;
if ( V_384 > V_140 ) {
V_384 = V_140 ;
V_205 -> V_330 |= V_386 ;
}
V_56 = F_222 ( V_135 , 0 , V_205 -> V_227 , V_384 ) ;
if ( V_56 )
goto V_228;
F_233 ( V_205 , V_3 , V_135 ) ;
if ( V_205 -> V_207 )
memcpy ( V_205 -> V_207 , & F_129 ( V_135 ) -> V_194 ,
V_205 -> V_209 ) ;
if ( F_1 ( V_3 ) -> V_400 ) {
struct V_401 V_402 ;
V_402 . V_20 = V_107 ;
if ( V_135 -> V_279 == V_280 )
V_402 . V_20 |= V_281 ;
V_402 . V_287 = F_129 ( V_135 ) -> V_266 ;
V_402 . V_288 = V_135 -> V_140 ;
V_402 . V_289 = 0 ;
V_402 . V_290 = F_155 ( V_135 ) ;
if ( F_74 ( V_135 ) ) {
V_402 . V_136 = F_75 ( V_135 ) ;
V_402 . V_20 |= V_137 ;
} else {
V_402 . V_136 = 0 ;
}
V_402 . V_300 = 0 ;
F_225 ( V_205 , V_388 , V_403 , sizeof( V_402 ) , & V_402 ) ;
}
V_56 = V_337 + ( ( V_216 & V_386 ) ? V_135 -> V_140 : V_384 ) ;
V_228:
F_234 ( V_3 , V_135 ) ;
V_95:
return V_56 ;
}
static int F_235 ( struct V_203 * V_2 , struct V_210 * V_362 ,
int * V_404 , int V_405 )
{
struct V_49 * V_50 ;
struct V_2 * V_3 = V_2 -> V_3 ;
if ( V_405 )
return - V_406 ;
V_362 -> V_407 = V_258 ;
F_135 () ;
V_50 = F_236 ( F_34 ( V_3 ) , F_1 ( V_3 ) -> V_57 ) ;
if ( V_50 )
strncpy ( V_362 -> V_364 , V_50 -> V_198 , 14 ) ;
else
memset ( V_362 -> V_364 , 0 , 14 ) ;
F_138 () ;
* V_404 = sizeof( * V_362 ) ;
return 0 ;
}
static int F_237 ( struct V_203 * V_2 , struct V_210 * V_362 ,
int * V_404 , int V_405 )
{
struct V_49 * V_50 ;
struct V_2 * V_3 = V_2 -> V_3 ;
struct V_1 * V_4 = F_1 ( V_3 ) ;
F_238 ( struct V_241 * , V_242 , V_362 ) ;
if ( V_405 )
return - V_406 ;
V_242 -> V_257 = V_258 ;
V_242 -> V_263 = V_4 -> V_57 ;
V_242 -> V_260 = V_4 -> V_151 ;
V_242 -> V_261 = 0 ;
F_135 () ;
V_50 = F_236 ( F_34 ( V_3 ) , V_4 -> V_57 ) ;
if ( V_50 ) {
V_242 -> V_259 = V_50 -> type ;
V_242 -> V_264 = V_50 -> V_363 ;
memcpy ( V_242 -> V_265 , V_50 -> V_408 , V_50 -> V_363 ) ;
} else {
V_242 -> V_259 = 0 ;
V_242 -> V_264 = 0 ;
}
F_138 () ;
* V_404 = F_183 ( struct V_241 , V_265 ) + V_242 -> V_264 ;
return 0 ;
}
static int F_239 ( struct V_49 * V_50 , struct V_409 * V_173 ,
int V_410 )
{
switch ( V_173 -> type ) {
case V_411 :
if ( V_173 -> V_412 != V_50 -> V_363 )
return - V_178 ;
if ( V_410 > 0 )
return F_240 ( V_50 , V_173 -> V_307 ) ;
else
return F_241 ( V_50 , V_173 -> V_307 ) ;
break;
case V_413 :
return F_242 ( V_50 , V_410 ) ;
break;
case V_414 :
return F_243 ( V_50 , V_410 ) ;
break;
case V_415 :
if ( V_173 -> V_412 != V_50 -> V_363 )
return - V_178 ;
if ( V_410 > 0 )
return F_244 ( V_50 , V_173 -> V_307 ) ;
else
return F_245 ( V_50 , V_173 -> V_307 ) ;
break;
default:
break;
}
return 0 ;
}
static void F_246 ( struct V_49 * V_50 , struct V_409 * V_173 , int V_410 )
{
for ( ; V_173 ; V_173 = V_173 -> V_416 ) {
if ( V_173 -> V_57 == V_50 -> V_57 )
F_239 ( V_50 , V_173 , V_410 ) ;
}
}
static int F_247 ( struct V_2 * V_3 , struct V_417 * V_418 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
struct V_409 * V_419 , * V_173 ;
struct V_49 * V_50 ;
int V_56 ;
F_32 () ;
V_56 = - V_213 ;
V_50 = F_33 ( F_34 ( V_3 ) , V_418 -> V_420 ) ;
if ( ! V_50 )
goto V_421;
V_56 = - V_178 ;
if ( V_418 -> V_422 > V_50 -> V_363 )
goto V_421;
V_56 = - V_225 ;
V_173 = F_248 ( sizeof( * V_173 ) , V_182 ) ;
if ( V_173 == NULL )
goto V_421;
V_56 = 0 ;
for ( V_419 = V_4 -> V_423 ; V_419 ; V_419 = V_419 -> V_416 ) {
if ( V_419 -> V_57 == V_418 -> V_420 &&
V_419 -> type == V_418 -> V_424 &&
V_419 -> V_412 == V_418 -> V_422 &&
memcmp ( V_419 -> V_307 , V_418 -> V_425 , V_419 -> V_412 ) == 0 ) {
V_419 -> V_426 ++ ;
F_124 ( V_173 ) ;
goto V_421;
}
}
V_173 -> type = V_418 -> V_424 ;
V_173 -> V_57 = V_418 -> V_420 ;
V_173 -> V_412 = V_418 -> V_422 ;
memcpy ( V_173 -> V_307 , V_418 -> V_425 , V_173 -> V_412 ) ;
V_173 -> V_426 = 1 ;
V_173 -> V_416 = V_4 -> V_423 ;
V_4 -> V_423 = V_173 ;
V_56 = F_239 ( V_50 , V_173 , 1 ) ;
if ( V_56 ) {
V_4 -> V_423 = V_173 -> V_416 ;
F_124 ( V_173 ) ;
}
V_421:
F_36 () ;
return V_56 ;
}
static int F_249 ( struct V_2 * V_3 , struct V_417 * V_418 )
{
struct V_409 * V_419 , * * V_427 ;
F_32 () ;
for ( V_427 = & F_1 ( V_3 ) -> V_423 ; ( V_419 = * V_427 ) != NULL ; V_427 = & V_419 -> V_416 ) {
if ( V_419 -> V_57 == V_418 -> V_420 &&
V_419 -> type == V_418 -> V_424 &&
V_419 -> V_412 == V_418 -> V_422 &&
memcmp ( V_419 -> V_307 , V_418 -> V_425 , V_419 -> V_412 ) == 0 ) {
if ( -- V_419 -> V_426 == 0 ) {
struct V_49 * V_50 ;
* V_427 = V_419 -> V_416 ;
V_50 = F_33 ( F_34 ( V_3 ) , V_419 -> V_57 ) ;
if ( V_50 )
F_239 ( V_50 , V_419 , - 1 ) ;
F_124 ( V_419 ) ;
}
F_36 () ;
return 0 ;
}
}
F_36 () ;
return - V_428 ;
}
static void F_202 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
struct V_409 * V_419 ;
if ( ! V_4 -> V_423 )
return;
F_32 () ;
while ( ( V_419 = V_4 -> V_423 ) != NULL ) {
struct V_49 * V_50 ;
V_4 -> V_423 = V_419 -> V_416 ;
V_50 = F_33 ( F_34 ( V_3 ) , V_419 -> V_57 ) ;
if ( V_50 != NULL )
F_239 ( V_50 , V_419 , - 1 ) ;
F_124 ( V_419 ) ;
}
F_36 () ;
}
static int
F_250 ( struct V_203 * V_2 , int V_429 , int V_430 , char T_7 * V_431 , unsigned int V_432 )
{
struct V_2 * V_3 = V_2 -> V_3 ;
struct V_1 * V_4 = F_1 ( V_3 ) ;
int V_433 ;
if ( V_429 != V_388 )
return - V_434 ;
switch ( V_430 ) {
case V_435 :
case V_436 :
{
struct V_417 V_418 ;
int V_140 = V_432 ;
memset ( & V_418 , 0 , sizeof( V_418 ) ) ;
if ( V_140 < sizeof( struct V_437 ) )
return - V_178 ;
if ( V_140 > sizeof( V_418 ) )
V_140 = sizeof( V_418 ) ;
if ( F_251 ( & V_418 , V_431 , V_140 ) )
return - V_314 ;
if ( V_140 < ( V_418 . V_422 + F_183 ( struct V_437 , V_425 ) ) )
return - V_178 ;
if ( V_430 == V_435 )
V_433 = F_247 ( V_3 , & V_418 ) ;
else
V_433 = F_249 ( V_3 , & V_418 ) ;
return V_433 ;
}
case V_438 :
case V_439 :
{
union V_65 V_66 ;
int V_140 ;
switch ( V_4 -> V_18 ) {
case V_19 :
case V_21 :
V_140 = sizeof( V_66 . V_440 ) ;
break;
case V_22 :
default:
V_140 = sizeof( V_66 . V_68 ) ;
break;
}
if ( V_432 < V_140 )
return - V_178 ;
if ( F_1 ( V_3 ) -> V_340 )
return - V_178 ;
if ( F_251 ( & V_66 . V_440 , V_431 , V_140 ) )
return - V_314 ;
return F_203 ( V_3 , & V_66 , 0 ,
V_430 == V_439 ) ;
}
case V_441 :
{
int V_442 ;
if ( V_432 != sizeof( V_442 ) )
return - V_178 ;
if ( F_251 ( & V_442 , V_431 , sizeof( V_442 ) ) )
return - V_314 ;
F_1 ( V_3 ) -> V_284 = V_442 ;
return 0 ;
}
case V_443 :
{
int V_442 ;
if ( V_432 != sizeof( V_442 ) )
return - V_178 ;
if ( V_4 -> V_40 . V_29 || V_4 -> V_36 . V_29 )
return - V_322 ;
if ( F_251 ( & V_442 , V_431 , sizeof( V_442 ) ) )
return - V_314 ;
switch ( V_442 ) {
case V_19 :
case V_21 :
case V_22 :
V_4 -> V_18 = V_442 ;
return 0 ;
default:
return - V_178 ;
}
}
case V_444 :
{
unsigned int V_442 ;
if ( V_432 != sizeof( V_442 ) )
return - V_178 ;
if ( V_4 -> V_40 . V_29 || V_4 -> V_36 . V_29 )
return - V_322 ;
if ( F_251 ( & V_442 , V_431 , sizeof( V_442 ) ) )
return - V_314 ;
V_4 -> V_282 = V_442 ;
return 0 ;
}
case V_445 :
{
unsigned int V_442 ;
if ( V_432 != sizeof( V_442 ) )
return - V_178 ;
if ( V_4 -> V_40 . V_29 || V_4 -> V_36 . V_29 )
return - V_322 ;
if ( F_251 ( & V_442 , V_431 , sizeof( V_442 ) ) )
return - V_314 ;
V_4 -> V_327 = ! ! V_442 ;
return 0 ;
}
case V_403 :
{
int V_442 ;
if ( V_432 < sizeof( V_442 ) )
return - V_178 ;
if ( F_251 ( & V_442 , V_431 , sizeof( V_442 ) ) )
return - V_314 ;
V_4 -> V_400 = ! ! V_442 ;
return 0 ;
}
case V_446 :
{
int V_442 ;
if ( V_432 < sizeof( V_442 ) )
return - V_178 ;
if ( F_251 ( & V_442 , V_431 , sizeof( V_442 ) ) )
return - V_314 ;
V_4 -> V_262 = ! ! V_442 ;
return 0 ;
}
case V_447 :
{
int V_442 ;
if ( V_2 -> type != V_339 )
return - V_178 ;
if ( V_4 -> V_40 . V_29 || V_4 -> V_36 . V_29 )
return - V_322 ;
if ( V_432 < sizeof( V_442 ) )
return - V_178 ;
if ( F_251 ( & V_442 , V_431 , sizeof( V_442 ) ) )
return - V_314 ;
V_4 -> V_340 = ! ! V_442 ;
return 0 ;
}
case V_448 :
{
int V_442 ;
if ( V_432 != sizeof( V_442 ) )
return - V_178 ;
if ( F_251 ( & V_442 , V_431 , sizeof( V_442 ) ) )
return - V_314 ;
V_4 -> V_291 = V_442 ;
return 0 ;
}
case V_449 :
{
int V_442 ;
if ( V_432 != sizeof( V_442 ) )
return - V_178 ;
if ( F_251 ( & V_442 , V_431 , sizeof( V_442 ) ) )
return - V_314 ;
return F_110 ( V_3 , V_442 & 0xffff , V_442 >> 16 ) ;
}
default:
return - V_434 ;
}
}
static int F_252 ( struct V_203 * V_2 , int V_429 , int V_430 ,
char T_7 * V_431 , int T_7 * V_432 )
{
int V_140 ;
int V_442 ;
struct V_2 * V_3 = V_2 -> V_3 ;
struct V_1 * V_4 = F_1 ( V_3 ) ;
void * V_43 ;
struct V_450 V_451 ;
union V_452 V_453 ;
if ( V_429 != V_388 )
return - V_434 ;
if ( F_253 ( V_140 , V_432 ) )
return - V_314 ;
if ( V_140 < 0 )
return - V_178 ;
switch ( V_430 ) {
case V_454 :
if ( V_4 -> V_18 == V_22 ) {
V_140 = sizeof( struct V_455 ) ;
} else {
if ( V_140 > sizeof( struct V_450 ) )
V_140 = sizeof( struct V_450 ) ;
}
F_198 ( & V_3 -> V_94 . V_41 ) ;
if ( V_4 -> V_18 == V_22 ) {
memcpy ( & V_453 . V_85 , & V_4 -> V_113 ,
sizeof( struct V_450 ) ) ;
V_453 . V_85 . V_86 =
V_4 -> V_84 . V_85 . V_86 ;
V_453 . V_85 . V_267 += V_4 -> V_113 . V_114 ;
V_43 = & V_453 . V_85 ;
} else {
V_451 = V_4 -> V_113 ;
V_451 . V_267 += V_451 . V_114 ;
V_43 = & V_451 ;
}
memset ( & V_4 -> V_113 , 0 , sizeof( V_451 ) ) ;
F_201 ( & V_3 -> V_94 . V_41 ) ;
break;
case V_403 :
if ( V_140 > sizeof( int ) )
V_140 = sizeof( int ) ;
V_442 = V_4 -> V_400 ;
V_43 = & V_442 ;
break;
case V_446 :
if ( V_140 > sizeof( int ) )
V_140 = sizeof( int ) ;
V_442 = V_4 -> V_262 ;
V_43 = & V_442 ;
break;
case V_447 :
if ( V_140 > sizeof( int ) )
V_140 = sizeof( int ) ;
V_442 = V_4 -> V_340 ;
V_43 = & V_442 ;
break;
case V_443 :
if ( V_140 > sizeof( int ) )
V_140 = sizeof( int ) ;
V_442 = V_4 -> V_18 ;
V_43 = & V_442 ;
break;
case V_456 :
if ( V_140 > sizeof( int ) )
V_140 = sizeof( int ) ;
if ( F_251 ( & V_442 , V_431 , V_140 ) )
return - V_314 ;
switch ( V_442 ) {
case V_19 :
V_442 = sizeof( struct V_12 ) ;
break;
case V_21 :
V_442 = sizeof( struct V_14 ) ;
break;
case V_22 :
V_442 = sizeof( struct V_108 ) ;
break;
default:
return - V_178 ;
}
V_43 = & V_442 ;
break;
case V_444 :
if ( V_140 > sizeof( unsigned int ) )
V_140 = sizeof( unsigned int ) ;
V_442 = V_4 -> V_282 ;
V_43 = & V_442 ;
break;
case V_445 :
if ( V_140 > sizeof( unsigned int ) )
V_140 = sizeof( unsigned int ) ;
V_442 = V_4 -> V_327 ;
V_43 = & V_442 ;
break;
case V_448 :
if ( V_140 > sizeof( int ) )
V_140 = sizeof( int ) ;
V_442 = V_4 -> V_291 ;
V_43 = & V_442 ;
break;
case V_449 :
if ( V_140 > sizeof( int ) )
V_140 = sizeof( int ) ;
V_442 = ( V_4 -> V_6 ?
( ( T_3 ) V_4 -> V_6 -> V_174 |
( ( T_3 ) V_4 -> V_6 -> type << 16 ) ) :
0 ) ;
V_43 = & V_442 ;
break;
default:
return - V_434 ;
}
if ( F_254 ( V_140 , V_432 ) )
return - V_314 ;
if ( F_255 ( V_431 , V_43 , V_140 ) )
return - V_314 ;
return 0 ;
}
static int F_256 ( struct V_457 * V_458 , unsigned long V_205 , void * V_43 )
{
struct V_2 * V_3 ;
struct V_459 * V_460 ;
struct V_49 * V_50 = V_43 ;
struct V_167 * V_167 = F_105 ( V_50 ) ;
F_135 () ;
F_257 (sk, node, &net->packet.sklist) {
struct V_1 * V_4 = F_1 ( V_3 ) ;
switch ( V_205 ) {
case V_461 :
if ( V_4 -> V_423 )
F_246 ( V_50 , V_4 -> V_423 , - 1 ) ;
case V_462 :
if ( V_50 -> V_57 == V_4 -> V_57 ) {
F_12 ( & V_4 -> V_9 ) ;
if ( V_4 -> V_5 ) {
F_6 ( V_3 , false ) ;
V_3 -> V_360 = V_215 ;
if ( ! F_94 ( V_3 , V_148 ) )
V_3 -> V_361 ( V_3 ) ;
}
if ( V_205 == V_461 ) {
V_4 -> V_57 = - 1 ;
if ( V_4 -> V_7 . V_50 )
F_189 ( V_4 -> V_7 . V_50 ) ;
V_4 -> V_7 . V_50 = NULL ;
}
F_10 ( & V_4 -> V_9 ) ;
}
break;
case V_463 :
if ( V_50 -> V_57 == V_4 -> V_57 ) {
F_12 ( & V_4 -> V_9 ) ;
if ( V_4 -> V_151 )
F_2 ( V_3 ) ;
F_10 ( & V_4 -> V_9 ) ;
}
break;
}
}
F_138 () ;
return V_464 ;
}
static int F_258 ( struct V_203 * V_2 , unsigned int V_465 ,
unsigned long V_466 )
{
struct V_2 * V_3 = V_2 -> V_3 ;
switch ( V_465 ) {
case V_467 :
{
int V_468 = F_259 ( V_3 ) ;
return F_254 ( V_468 , ( int T_7 * ) V_466 ) ;
}
case V_469 :
{
struct V_141 * V_135 ;
int V_468 = 0 ;
F_198 ( & V_3 -> V_94 . V_41 ) ;
V_135 = F_226 ( & V_3 -> V_94 ) ;
if ( V_135 )
V_468 = V_135 -> V_140 ;
F_201 ( & V_3 -> V_94 . V_41 ) ;
return F_254 ( V_468 , ( int T_7 * ) V_466 ) ;
}
case V_470 :
return F_260 ( V_3 , (struct V_275 T_7 * ) V_466 ) ;
case V_471 :
return F_261 ( V_3 , (struct V_123 T_7 * ) V_466 ) ;
#ifdef F_262
case V_472 :
case V_473 :
case V_474 :
case V_475 :
case V_476 :
case V_477 :
case V_478 :
case V_479 :
case V_480 :
case V_481 :
case V_482 :
case V_483 :
case V_484 :
case V_485 :
return V_486 . V_487 ( V_2 , V_465 , V_466 ) ;
#endif
default:
return - V_488 ;
}
return 0 ;
}
static unsigned int F_263 ( struct V_489 * V_489 , struct V_203 * V_2 ,
T_8 * V_490 )
{
struct V_2 * V_3 = V_2 -> V_3 ;
struct V_1 * V_4 = F_1 ( V_3 ) ;
unsigned int V_491 = F_264 ( V_489 , V_2 , V_490 ) ;
F_198 ( & V_3 -> V_94 . V_41 ) ;
if ( V_4 -> V_40 . V_29 ) {
if ( ! F_87 ( V_4 , & V_4 -> V_40 ,
V_128 ) )
V_491 |= V_492 | V_493 ;
}
F_201 ( & V_3 -> V_94 . V_41 ) ;
F_198 ( & V_3 -> V_494 . V_41 ) ;
if ( V_4 -> V_36 . V_29 ) {
if ( F_23 ( V_4 , & V_4 -> V_36 , V_305 ) )
V_491 |= V_495 | V_496 ;
}
F_201 ( & V_3 -> V_494 . V_41 ) ;
return V_491 ;
}
static void F_265 ( struct V_497 * V_498 )
{
struct V_489 * V_489 = V_498 -> V_499 ;
struct V_203 * V_2 = V_489 -> V_500 ;
struct V_2 * V_3 = V_2 -> V_3 ;
if ( V_3 )
F_79 ( & F_1 ( V_3 ) -> V_501 ) ;
}
static void F_266 ( struct V_497 * V_498 )
{
struct V_489 * V_489 = V_498 -> V_499 ;
struct V_203 * V_2 = V_489 -> V_500 ;
struct V_2 * V_3 = V_2 -> V_3 ;
if ( V_3 )
F_69 ( & F_1 ( V_3 ) -> V_501 ) ;
}
static void F_267 ( struct V_70 * V_29 , unsigned int V_502 ,
unsigned int V_140 )
{
int V_173 ;
for ( V_173 = 0 ; V_173 < V_140 ; V_173 ++ ) {
if ( F_59 ( V_29 [ V_173 ] . V_30 ) ) {
if ( F_268 ( V_29 [ V_173 ] . V_30 ) )
F_269 ( V_29 [ V_173 ] . V_30 ) ;
else
F_270 ( ( unsigned long ) V_29 [ V_173 ] . V_30 ,
V_502 ) ;
V_29 [ V_173 ] . V_30 = NULL ;
}
}
F_124 ( V_29 ) ;
}
static char * F_271 ( unsigned long V_502 )
{
char * V_30 = NULL ;
T_9 V_503 = V_182 | V_504 |
V_505 | V_506 | V_507 ;
V_30 = ( char * ) F_272 ( V_503 , V_502 ) ;
if ( V_30 )
return V_30 ;
V_30 = F_273 ( ( 1 << V_502 ) * V_104 ) ;
if ( V_30 )
return V_30 ;
V_503 &= ~ V_507 ;
V_30 = ( char * ) F_272 ( V_503 , V_502 ) ;
if ( V_30 )
return V_30 ;
return NULL ;
}
static struct V_70 * F_274 ( struct V_508 * V_440 , int V_502 )
{
unsigned int V_509 = V_440 -> V_79 ;
struct V_70 * V_29 ;
int V_173 ;
V_29 = F_275 ( V_509 , sizeof( struct V_70 ) , V_182 ) ;
if ( F_35 ( ! V_29 ) )
goto V_95;
for ( V_173 = 0 ; V_173 < V_509 ; V_173 ++ ) {
V_29 [ V_173 ] . V_30 = F_271 ( V_502 ) ;
if ( F_35 ( ! V_29 [ V_173 ] . V_30 ) )
goto V_510;
}
V_95:
return V_29 ;
V_510:
F_267 ( V_29 , V_502 , V_509 ) ;
V_29 = NULL ;
goto V_95;
}
static int F_203 ( struct V_2 * V_3 , union V_65 * V_66 ,
int V_511 , int V_36 )
{
struct V_70 * V_29 = NULL ;
struct V_1 * V_4 = F_1 ( V_3 ) ;
int V_512 , V_502 = 0 ;
struct V_23 * V_24 ;
struct V_37 * V_38 ;
T_6 V_151 ;
int V_56 = - V_178 ;
struct V_508 * V_440 = & V_66 -> V_440 ;
if ( ! V_511 && V_36 && ( V_4 -> V_18 > V_21 ) ) {
F_17 ( 1 , L_9 ) ;
goto V_95;
}
V_24 = V_36 ? & V_4 -> V_36 : & V_4 -> V_40 ;
V_38 = V_36 ? & V_3 -> V_494 : & V_3 -> V_94 ;
V_56 = - V_322 ;
if ( ! V_511 ) {
if ( F_47 ( & V_4 -> V_501 ) )
goto V_95;
if ( F_47 ( & V_24 -> V_304 ) )
goto V_95;
}
if ( V_440 -> V_79 ) {
V_56 = - V_322 ;
if ( F_35 ( V_24 -> V_29 ) )
goto V_95;
switch ( V_4 -> V_18 ) {
case V_19 :
V_4 -> V_81 = V_513 ;
break;
case V_21 :
V_4 -> V_81 = V_514 ;
break;
case V_22 :
V_4 -> V_81 = V_515 ;
break;
}
V_56 = - V_178 ;
if ( F_35 ( ( int ) V_440 -> V_77 <= 0 ) )
goto V_95;
if ( F_35 ( V_440 -> V_77 & ( V_104 - 1 ) ) )
goto V_95;
if ( F_35 ( V_440 -> V_516 < V_4 -> V_81 +
V_4 -> V_282 ) )
goto V_95;
if ( F_35 ( V_440 -> V_516 & ( V_517 - 1 ) ) )
goto V_95;
V_24 -> V_28 = V_440 -> V_77 / V_440 -> V_516 ;
if ( F_35 ( V_24 -> V_28 <= 0 ) )
goto V_95;
if ( F_35 ( ( V_24 -> V_28 * V_440 -> V_79 ) !=
V_440 -> V_518 ) )
goto V_95;
V_56 = - V_181 ;
V_502 = F_276 ( V_440 -> V_77 ) ;
V_29 = F_274 ( V_440 , V_502 ) ;
if ( F_35 ( ! V_29 ) )
goto V_95;
switch ( V_4 -> V_18 ) {
case V_22 :
if ( ! V_36 )
F_39 ( V_4 , V_24 , V_29 , V_66 , V_36 ) ;
break;
default:
break;
}
}
else {
V_56 = - V_178 ;
if ( F_35 ( V_440 -> V_518 ) )
goto V_95;
}
F_208 ( V_3 ) ;
F_12 ( & V_4 -> V_9 ) ;
V_512 = V_4 -> V_5 ;
V_151 = V_4 -> V_151 ;
if ( V_512 ) {
V_4 -> V_151 = 0 ;
F_6 ( V_3 , false ) ;
}
F_10 ( & V_4 -> V_9 ) ;
F_11 () ;
V_56 = - V_322 ;
F_111 ( & V_4 -> V_321 ) ;
if ( V_511 || F_47 ( & V_4 -> V_501 ) == 0 ) {
V_56 = 0 ;
F_198 ( & V_38 -> V_41 ) ;
F_277 ( V_24 -> V_29 , V_29 ) ;
V_24 -> V_143 = ( V_440 -> V_518 - 1 ) ;
V_24 -> V_32 = 0 ;
V_24 -> V_31 = V_440 -> V_516 ;
F_201 ( & V_38 -> V_41 ) ;
F_277 ( V_24 -> V_519 , V_502 ) ;
F_277 ( V_24 -> V_520 , V_440 -> V_79 ) ;
V_24 -> V_521 = V_440 -> V_77 / V_104 ;
V_4 -> V_7 . F_28 = ( V_4 -> V_40 . V_29 ) ?
F_164 : F_153 ;
F_92 ( V_38 ) ;
if ( F_47 ( & V_4 -> V_501 ) )
F_95 ( L_10 ,
F_47 ( & V_4 -> V_501 ) ) ;
}
F_119 ( & V_4 -> V_321 ) ;
F_12 ( & V_4 -> V_9 ) ;
if ( V_512 ) {
V_4 -> V_151 = V_151 ;
F_2 ( V_3 ) ;
}
F_10 ( & V_4 -> V_9 ) ;
if ( V_511 && ( V_4 -> V_18 > V_21 ) ) {
if ( ! V_36 )
F_26 ( V_4 , V_36 , V_38 ) ;
}
F_209 ( V_3 ) ;
if ( V_29 )
F_267 ( V_29 , V_502 , V_440 -> V_79 ) ;
V_95:
return V_56 ;
}
static int F_278 ( struct V_489 * V_489 , struct V_203 * V_2 ,
struct V_497 * V_498 )
{
struct V_2 * V_3 = V_2 -> V_3 ;
struct V_1 * V_4 = F_1 ( V_3 ) ;
unsigned long V_522 , V_523 ;
struct V_23 * V_24 ;
unsigned long V_102 ;
int V_56 = - V_178 ;
int V_173 ;
if ( V_498 -> V_524 )
return - V_178 ;
F_111 ( & V_4 -> V_321 ) ;
V_523 = 0 ;
for ( V_24 = & V_4 -> V_40 ; V_24 <= & V_4 -> V_36 ; V_24 ++ ) {
if ( V_24 -> V_29 ) {
V_523 += V_24 -> V_520
* V_24 -> V_521
* V_104 ;
}
}
if ( V_523 == 0 )
goto V_95;
V_522 = V_498 -> V_525 - V_498 -> V_526 ;
if ( V_522 != V_523 )
goto V_95;
V_102 = V_498 -> V_526 ;
for ( V_24 = & V_4 -> V_40 ; V_24 <= & V_4 -> V_36 ; V_24 ++ ) {
if ( V_24 -> V_29 == NULL )
continue;
for ( V_173 = 0 ; V_173 < V_24 -> V_520 ; V_173 ++ ) {
struct V_313 * V_313 ;
void * V_527 = V_24 -> V_29 [ V_173 ] . V_30 ;
int V_528 ;
for ( V_528 = 0 ; V_528 < V_24 -> V_521 ; V_528 ++ ) {
V_313 = F_16 ( V_527 ) ;
V_56 = F_279 ( V_498 , V_102 , V_313 ) ;
if ( F_35 ( V_56 ) )
goto V_95;
V_102 += V_104 ;
V_527 += V_104 ;
}
}
}
F_79 ( & V_4 -> V_501 ) ;
V_498 -> V_529 = & V_530 ;
V_56 = 0 ;
V_95:
F_119 ( & V_4 -> V_321 ) ;
return V_56 ;
}
static void * F_280 ( struct V_531 * V_532 , T_10 * V_533 )
__acquires( T_11 )
{
struct V_167 * V_167 = F_281 ( V_532 ) ;
F_135 () ;
return F_282 ( & V_167 -> V_357 . V_380 , * V_533 ) ;
}
static void * F_283 ( struct V_531 * V_532 , void * V_534 , T_10 * V_533 )
{
struct V_167 * V_167 = F_281 ( V_532 ) ;
return F_284 ( V_534 , & V_167 -> V_357 . V_380 , V_533 ) ;
}
static void F_285 ( struct V_531 * V_532 , void * V_534 )
__releases( T_11 )
{
F_138 () ;
}
static int F_286 ( struct V_531 * V_532 , void * V_534 )
{
if ( V_534 == V_535 )
F_287 ( V_532 , L_11 ) ;
else {
struct V_2 * V_536 = F_288 ( V_534 ) ;
const struct V_1 * V_4 = F_1 ( V_536 ) ;
F_289 ( V_532 ,
L_12 ,
V_536 ,
F_47 ( & V_536 -> V_537 ) ,
V_536 -> V_247 ,
F_176 ( V_4 -> V_151 ) ,
V_4 -> V_57 ,
V_4 -> V_5 ,
F_47 ( & V_536 -> V_146 ) ,
F_290 ( V_536 ) ,
F_291 ( V_536 ) ) ;
}
return 0 ;
}
static int F_292 ( struct V_538 * V_538 , struct V_489 * V_489 )
{
return F_293 ( V_538 , V_489 , & V_539 ,
sizeof( struct V_540 ) ) ;
}
static int T_12 F_294 ( struct V_167 * V_167 )
{
F_117 ( & V_167 -> V_357 . V_358 ) ;
F_295 ( & V_167 -> V_357 . V_380 ) ;
if ( ! F_296 ( V_167 , L_13 , 0 , & V_541 ) )
return - V_181 ;
return 0 ;
}
static void T_13 F_297 ( struct V_167 * V_167 )
{
F_298 ( V_167 , L_13 ) ;
}
static void T_14 F_299 ( void )
{
F_300 ( & V_542 ) ;
F_301 ( & V_543 ) ;
F_302 ( V_373 ) ;
F_303 ( & V_374 ) ;
}
static int T_15 F_304 ( void )
{
int V_544 = F_305 ( & V_374 , 0 ) ;
if ( V_544 != 0 )
goto V_95;
F_306 ( & V_545 ) ;
F_307 ( & V_543 ) ;
F_308 ( & V_542 ) ;
V_95:
return V_544 ;
}
