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
int V_223 = V_50 -> V_224 ;
unsigned int V_225 = V_50 -> V_226 ? V_50 -> V_220 : 0 ;
F_138 () ;
V_135 = F_139 ( V_3 , V_140 + V_222 + V_223 , 0 , V_182 ) ;
if ( V_135 == NULL )
return - V_227 ;
F_140 ( V_135 , V_222 ) ;
F_141 ( V_135 ) ;
if ( V_225 ) {
V_135 -> V_43 -= V_225 ;
V_135 -> V_228 -= V_225 ;
if ( V_140 < V_225 )
F_141 ( V_135 ) ;
}
V_56 = F_142 ( F_143 ( V_135 , V_140 ) , V_205 -> V_229 , V_140 ) ;
if ( V_56 )
goto V_230;
goto V_212;
}
if ( V_140 > ( V_50 -> V_219 + V_50 -> V_220 ) ) {
struct V_231 * V_232 ;
F_144 ( V_135 ) ;
V_232 = F_145 ( V_135 ) ;
if ( V_232 -> V_233 != F_146 ( V_234 ) ) {
V_56 = - V_218 ;
goto V_214;
}
}
V_135 -> V_200 = V_208 ;
V_135 -> V_50 = V_50 ;
V_135 -> V_235 = V_3 -> V_236 ;
V_135 -> V_237 = V_3 -> V_238 ;
V_56 = F_147 ( V_3 , & F_148 ( V_135 ) -> V_239 ) ;
if ( V_56 < 0 )
goto V_214;
F_149 ( V_135 ) ;
F_138 () ;
return V_140 ;
V_214:
F_138 () ;
V_230:
F_107 ( V_135 ) ;
return V_56 ;
}
static unsigned int F_150 ( const struct V_141 * V_135 ,
const struct V_2 * V_3 ,
unsigned int V_240 )
{
struct V_241 * V_242 ;
F_135 () ;
V_242 = F_151 ( V_3 -> V_241 ) ;
if ( V_242 != NULL )
V_240 = F_152 ( V_242 , V_135 ) ;
F_138 () ;
return V_240 ;
}
static int F_153 ( struct V_141 * V_135 , struct V_49 * V_50 ,
struct V_162 * V_163 , struct V_49 * V_164 )
{
struct V_2 * V_3 ;
struct V_243 * V_244 ;
struct V_1 * V_4 ;
T_2 * V_245 = V_135 -> V_43 ;
int V_246 = V_135 -> V_140 ;
unsigned int V_247 , V_240 ;
if ( V_135 -> V_190 == V_191 )
goto V_248;
V_3 = V_163 -> V_165 ;
V_4 = F_1 ( V_3 ) ;
if ( ! F_104 ( F_105 ( V_50 ) , F_34 ( V_3 ) ) )
goto V_248;
V_135 -> V_50 = V_50 ;
if ( V_50 -> V_226 ) {
if ( V_3 -> V_249 != V_250 )
F_130 ( V_135 , V_135 -> V_43 - F_131 ( V_135 ) ) ;
else if ( V_135 -> V_190 == V_251 ) {
F_154 ( V_135 , F_155 ( V_135 ) ) ;
}
}
V_247 = V_135 -> V_140 ;
V_240 = F_150 ( V_135 , V_3 , V_247 ) ;
if ( ! V_240 )
goto V_252;
if ( V_247 > V_240 )
V_247 = V_240 ;
if ( F_47 ( & V_3 -> V_146 ) >= V_3 -> V_253 )
goto V_254;
if ( F_156 ( V_135 ) ) {
struct V_141 * V_255 = F_157 ( V_135 , V_192 ) ;
if ( V_255 == NULL )
goto V_254;
if ( V_245 != V_135 -> V_43 ) {
V_135 -> V_43 = V_245 ;
V_135 -> V_140 = V_246 ;
}
F_107 ( V_135 ) ;
V_135 = V_255 ;
}
F_158 ( sizeof( * F_129 ( V_135 ) ) + V_256 - 8 >
sizeof( V_135 -> V_257 ) ) ;
V_244 = & F_129 ( V_135 ) -> V_194 . V_258 ;
V_244 -> V_259 = V_260 ;
V_244 -> V_261 = V_50 -> type ;
V_244 -> V_262 = V_135 -> V_200 ;
V_244 -> V_263 = V_135 -> V_190 ;
if ( F_35 ( V_4 -> V_264 ) )
V_244 -> V_265 = V_164 -> V_57 ;
else
V_244 -> V_265 = V_50 -> V_57 ;
V_244 -> V_266 = F_159 ( V_135 , V_244 -> V_267 ) ;
F_129 ( V_135 ) -> V_268 = V_135 -> V_140 ;
if ( F_160 ( V_135 , V_247 ) )
goto V_254;
F_161 ( V_135 , V_3 ) ;
V_135 -> V_50 = NULL ;
F_127 ( V_135 ) ;
F_128 ( V_135 ) ;
F_12 ( & V_3 -> V_94 . V_41 ) ;
V_4 -> V_113 . V_269 ++ ;
V_135 -> V_270 = F_47 ( & V_3 -> V_271 ) ;
F_162 ( & V_3 -> V_94 , V_135 ) ;
F_10 ( & V_3 -> V_94 . V_41 ) ;
V_3 -> V_272 ( V_3 , V_135 -> V_140 ) ;
return 0 ;
V_254:
F_12 ( & V_3 -> V_94 . V_41 ) ;
V_4 -> V_113 . V_114 ++ ;
F_79 ( & V_3 -> V_271 ) ;
F_10 ( & V_3 -> V_94 . V_41 ) ;
V_252:
if ( V_245 != V_135 -> V_43 && F_156 ( V_135 ) ) {
V_135 -> V_43 = V_245 ;
V_135 -> V_140 = V_246 ;
}
V_248:
F_163 ( V_135 ) ;
return 0 ;
}
static int F_164 ( struct V_141 * V_135 , struct V_49 * V_50 ,
struct V_162 * V_163 , struct V_49 * V_164 )
{
struct V_2 * V_3 ;
struct V_1 * V_4 ;
struct V_243 * V_244 ;
union {
struct V_12 * V_13 ;
struct V_14 * V_15 ;
struct V_108 * V_273 ;
void * V_16 ;
} V_17 ;
T_2 * V_245 = V_135 -> V_43 ;
int V_246 = V_135 -> V_140 ;
unsigned int V_247 , V_240 ;
unsigned long V_11 = V_107 ;
unsigned short V_274 , V_275 , V_80 ;
struct V_141 * V_276 = NULL ;
struct V_277 V_278 ;
struct V_123 V_124 ;
struct V_279 * V_280 = F_165 ( V_135 ) ;
if ( V_135 -> V_190 == V_191 )
goto V_248;
V_3 = V_163 -> V_165 ;
V_4 = F_1 ( V_3 ) ;
if ( ! F_104 ( F_105 ( V_50 ) , F_34 ( V_3 ) ) )
goto V_248;
if ( V_50 -> V_226 ) {
if ( V_3 -> V_249 != V_250 )
F_130 ( V_135 , V_135 -> V_43 - F_131 ( V_135 ) ) ;
else if ( V_135 -> V_190 == V_251 ) {
F_154 ( V_135 , F_155 ( V_135 ) ) ;
}
}
if ( V_135 -> V_281 == V_282 )
V_11 |= V_283 ;
V_247 = V_135 -> V_140 ;
V_240 = F_150 ( V_135 , V_3 , V_247 ) ;
if ( ! V_240 )
goto V_252;
if ( V_247 > V_240 )
V_247 = V_240 ;
if ( V_3 -> V_249 == V_250 ) {
V_274 = V_275 = F_166 ( V_4 -> V_81 ) + 16 +
V_4 -> V_284 ;
} else {
unsigned V_285 = F_155 ( V_135 ) ;
V_275 = F_166 ( V_4 -> V_81 +
( V_285 < 16 ? 16 : V_285 ) ) +
V_4 -> V_284 ;
V_274 = V_275 - V_285 ;
}
if ( V_4 -> V_18 <= V_21 ) {
if ( V_274 + V_247 > V_4 -> V_40 . V_31 ) {
if ( V_4 -> V_286 &&
F_47 ( & V_3 -> V_146 ) < V_3 -> V_253 ) {
if ( F_156 ( V_135 ) ) {
V_276 = F_157 ( V_135 , V_192 ) ;
} else {
V_276 = F_167 ( V_135 ) ;
V_245 = V_135 -> V_43 ;
}
if ( V_276 )
F_161 ( V_276 , V_3 ) ;
}
V_247 = V_4 -> V_40 . V_31 - V_274 ;
if ( ( int ) V_247 < 0 )
V_247 = 0 ;
}
}
F_12 ( & V_3 -> V_94 . V_41 ) ;
V_17 . V_16 = F_82 ( V_4 , V_135 ,
V_128 , ( V_274 + V_247 ) ) ;
if ( ! V_17 . V_16 )
goto V_287;
if ( V_4 -> V_18 <= V_21 ) {
F_89 ( V_4 , & V_4 -> V_40 ) ;
if ( V_4 -> V_113 . V_114 )
V_11 |= V_115 ;
}
V_4 -> V_113 . V_269 ++ ;
if ( V_276 ) {
V_11 |= V_288 ;
F_162 ( & V_3 -> V_94 , V_276 ) ;
}
F_10 ( & V_3 -> V_94 . V_41 ) ;
F_168 ( V_135 , 0 , V_17 . V_16 + V_274 , V_247 ) ;
switch ( V_4 -> V_18 ) {
case V_19 :
V_17 . V_13 -> V_289 = V_135 -> V_140 ;
V_17 . V_13 -> V_290 = V_247 ;
V_17 . V_13 -> V_291 = V_274 ;
V_17 . V_13 -> V_292 = V_275 ;
if ( ( V_4 -> V_293 & V_294 )
&& V_280 -> V_295 . V_296 )
V_278 = F_169 ( V_280 -> V_295 ) ;
else if ( ( V_4 -> V_293 & V_297 )
&& V_280 -> V_298 . V_296 )
V_278 = F_169 ( V_280 -> V_298 ) ;
else if ( V_135 -> V_299 . V_296 )
V_278 = F_169 ( V_135 -> V_299 ) ;
else
F_170 ( & V_278 ) ;
V_17 . V_13 -> V_120 = V_278 . V_125 ;
V_17 . V_13 -> V_300 = V_278 . V_301 ;
V_80 = sizeof( * V_17 . V_13 ) ;
break;
case V_21 :
V_17 . V_15 -> V_289 = V_135 -> V_140 ;
V_17 . V_15 -> V_290 = V_247 ;
V_17 . V_15 -> V_291 = V_274 ;
V_17 . V_15 -> V_292 = V_275 ;
if ( ( V_4 -> V_293 & V_294 )
&& V_280 -> V_295 . V_296 )
V_124 = F_171 ( V_280 -> V_295 ) ;
else if ( ( V_4 -> V_293 & V_297 )
&& V_280 -> V_298 . V_296 )
V_124 = F_171 ( V_280 -> V_298 ) ;
else if ( V_135 -> V_299 . V_296 )
V_124 = F_171 ( V_135 -> V_299 ) ;
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
V_17 . V_15 -> V_302 = 0 ;
V_80 = sizeof( * V_17 . V_15 ) ;
break;
case V_22 :
V_17 . V_273 -> V_20 |= V_11 ;
V_17 . V_273 -> V_289 = V_135 -> V_140 ;
V_17 . V_273 -> V_290 = V_247 ;
V_17 . V_273 -> V_291 = V_274 ;
V_17 . V_273 -> V_292 = V_275 ;
if ( ( V_4 -> V_293 & V_294 )
&& V_280 -> V_295 . V_296 )
V_124 = F_171 ( V_280 -> V_295 ) ;
else if ( ( V_4 -> V_293 & V_297 )
&& V_280 -> V_298 . V_296 )
V_124 = F_171 ( V_280 -> V_298 ) ;
else if ( V_135 -> V_299 . V_296 )
V_124 = F_171 ( V_135 -> V_299 ) ;
else
F_56 ( & V_124 ) ;
V_17 . V_273 -> V_120 = V_124 . V_125 ;
V_17 . V_273 -> V_122 = V_124 . V_126 ;
V_80 = sizeof( * V_17 . V_273 ) ;
break;
default:
F_18 () ;
}
V_244 = V_17 . V_16 + F_166 ( V_80 ) ;
V_244 -> V_266 = F_159 ( V_135 , V_244 -> V_267 ) ;
V_244 -> V_259 = V_260 ;
V_244 -> V_261 = V_50 -> type ;
V_244 -> V_262 = V_135 -> V_200 ;
V_244 -> V_263 = V_135 -> V_190 ;
if ( F_35 ( V_4 -> V_264 ) )
V_244 -> V_265 = V_164 -> V_57 ;
else
V_244 -> V_265 = V_50 -> V_57 ;
F_81 () ;
#if V_101 == 1
{
T_2 * V_102 , * V_103 ;
if ( V_4 -> V_18 <= V_21 ) {
V_103 = ( T_2 * ) F_53 ( ( unsigned long ) V_17 . V_16
+ V_274 + V_247 ) ;
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
V_3 -> V_272 ( V_3 , 0 ) ;
V_252:
if ( V_245 != V_135 -> V_43 && F_156 ( V_135 ) ) {
V_135 -> V_43 = V_245 ;
V_135 -> V_140 = V_246 ;
}
V_248:
F_107 ( V_135 ) ;
return 0 ;
V_287:
V_4 -> V_113 . V_114 ++ ;
F_10 ( & V_3 -> V_94 . V_41 ) ;
V_3 -> V_272 ( V_3 , 0 ) ;
F_107 ( V_276 ) ;
goto V_252;
}
static void F_172 ( struct V_141 * V_135 )
{
struct V_1 * V_4 = F_1 ( V_135 -> V_3 ) ;
void * V_303 ;
if ( F_59 ( V_4 -> V_36 . V_29 ) ) {
V_303 = F_148 ( V_135 ) -> V_304 ;
F_109 ( F_20 ( V_4 , V_303 ) != V_305 ) ;
F_109 ( F_47 ( & V_4 -> V_36 . V_306 ) == 0 ) ;
F_69 ( & V_4 -> V_36 . V_306 ) ;
F_14 ( V_4 , V_303 , V_307 ) ;
}
F_173 ( V_135 ) ;
}
static int F_174 ( struct V_1 * V_4 , struct V_141 * V_135 ,
void * V_10 , struct V_49 * V_50 , int V_308 ,
T_6 V_208 , unsigned char * V_309 , int V_310 )
{
union {
struct V_12 * V_13 ;
struct V_14 * V_15 ;
void * V_16 ;
} V_303 ;
int V_311 , V_312 , V_140 , V_289 , V_313 , V_314 ;
struct V_203 * V_2 = V_4 -> V_3 . V_315 ;
struct V_316 * V_316 ;
void * V_43 ;
int V_56 ;
V_303 . V_16 = V_10 ;
V_135 -> V_200 = V_208 ;
V_135 -> V_50 = V_50 ;
V_135 -> V_235 = V_4 -> V_3 . V_236 ;
V_135 -> V_237 = V_4 -> V_3 . V_238 ;
F_148 ( V_135 ) -> V_304 = V_303 . V_16 ;
switch ( V_4 -> V_18 ) {
case V_21 :
V_289 = V_303 . V_15 -> V_289 ;
break;
default:
V_289 = V_303 . V_13 -> V_289 ;
break;
}
if ( F_35 ( V_289 > V_308 ) ) {
F_95 ( L_6 , V_289 , V_308 ) ;
return - V_218 ;
}
F_140 ( V_135 , V_310 ) ;
F_141 ( V_135 ) ;
V_43 = V_303 . V_16 + V_4 -> V_81 - sizeof( struct V_243 ) ;
V_311 = V_289 ;
if ( V_2 -> type == V_250 ) {
V_56 = F_175 ( V_135 , V_50 , F_176 ( V_208 ) , V_309 ,
NULL , V_289 ) ;
if ( F_35 ( V_56 < 0 ) )
return - V_178 ;
} else if ( V_50 -> V_220 ) {
if ( F_35 ( V_289 <= V_50 -> V_220 ) ) {
F_95 ( L_7 ,
V_289 , V_50 -> V_220 ) ;
return - V_178 ;
}
F_130 ( V_135 , V_50 -> V_220 ) ;
V_56 = F_177 ( V_135 , 0 , V_43 ,
V_50 -> V_220 ) ;
if ( F_35 ( V_56 ) )
return V_56 ;
V_43 += V_50 -> V_220 ;
V_311 -= V_50 -> V_220 ;
}
V_56 = - V_317 ;
V_312 = F_178 ( V_43 ) ;
V_314 = V_104 - V_312 ;
V_140 = ( ( V_311 > V_314 ) ? V_314 : V_311 ) ;
V_135 -> V_318 = V_311 ;
V_135 -> V_140 += V_311 ;
V_135 -> V_319 += V_311 ;
F_179 ( V_311 , & V_4 -> V_3 . V_147 ) ;
while ( F_59 ( V_311 ) ) {
V_313 = F_148 ( V_135 ) -> V_313 ;
if ( F_35 ( V_313 >= V_320 ) ) {
F_95 ( L_8 ,
V_320 ) ;
return - V_317 ;
}
V_316 = F_16 ( V_43 ) ;
V_43 += V_140 ;
F_15 ( V_316 ) ;
F_180 ( V_316 ) ;
F_181 ( V_135 , V_313 , V_316 , V_312 , V_140 ) ;
V_311 -= V_140 ;
V_312 = 0 ;
V_314 = V_104 ;
V_140 = ( ( V_311 > V_314 ) ? V_314 : V_311 ) ;
}
return V_289 ;
}
static int F_182 ( struct V_1 * V_4 , struct V_204 * V_205 )
{
struct V_141 * V_135 ;
struct V_49 * V_50 ;
T_6 V_208 ;
bool V_321 = false ;
int V_56 , V_322 = 0 ;
void * V_303 ;
struct V_243 * V_206 = (struct V_243 * ) V_205 -> V_207 ;
int V_289 , V_308 ;
unsigned char * V_309 ;
int V_323 = 0 ;
int V_11 = 0 ;
int V_310 , V_223 ;
F_111 ( & V_4 -> V_324 ) ;
V_56 = - V_325 ;
if ( V_206 == NULL ) {
V_50 = V_4 -> V_7 . V_50 ;
V_208 = V_4 -> V_151 ;
V_309 = NULL ;
} else {
V_56 = - V_178 ;
if ( V_205 -> V_209 < sizeof( struct V_243 ) )
goto V_95;
if ( V_205 -> V_209 < ( V_206 -> V_266
+ F_183 ( struct V_243 ,
V_267 ) ) )
goto V_95;
V_208 = V_206 -> V_262 ;
V_309 = V_206 -> V_267 ;
V_50 = F_184 ( F_34 ( & V_4 -> V_3 ) , V_206 -> V_265 ) ;
V_321 = true ;
}
V_56 = - V_326 ;
if ( F_35 ( V_50 == NULL ) )
goto V_95;
V_322 = V_50 -> V_220 ;
V_56 = - V_215 ;
if ( F_35 ( ! ( V_50 -> V_216 & V_217 ) ) )
goto V_327;
V_308 = V_4 -> V_36 . V_31
- ( V_4 -> V_81 - sizeof( struct V_243 ) ) ;
if ( V_308 > V_50 -> V_219 + V_322 )
V_308 = V_50 -> V_219 + V_322 ;
do {
V_303 = F_23 ( V_4 , & V_4 -> V_36 ,
V_328 ) ;
if ( F_35 ( V_303 == NULL ) ) {
F_185 () ;
continue;
}
V_11 = V_328 ;
V_310 = F_137 ( V_50 ) ;
V_223 = V_50 -> V_224 ;
V_135 = F_186 ( & V_4 -> V_3 ,
V_310 + V_223 + sizeof( struct V_243 ) ,
0 , & V_56 ) ;
if ( F_35 ( V_135 == NULL ) )
goto V_329;
V_289 = F_174 ( V_4 , V_135 , V_303 , V_50 , V_308 , V_208 ,
V_309 , V_310 ) ;
if ( F_35 ( V_289 < 0 ) ) {
if ( V_4 -> V_330 ) {
F_14 ( V_4 , V_303 ,
V_307 ) ;
F_90 ( & V_4 -> V_36 ) ;
F_107 ( V_135 ) ;
continue;
} else {
V_11 = V_331 ;
V_56 = V_289 ;
goto V_329;
}
}
V_135 -> V_332 = F_172 ;
F_14 ( V_4 , V_303 , V_305 ) ;
F_79 ( & V_4 -> V_36 . V_306 ) ;
V_11 = V_328 ;
V_56 = F_149 ( V_135 ) ;
if ( F_35 ( V_56 > 0 ) ) {
V_56 = F_187 ( V_56 ) ;
if ( V_56 && F_20 ( V_4 , V_303 ) ==
V_307 ) {
V_135 = NULL ;
goto V_329;
}
V_56 = 0 ;
}
F_90 ( & V_4 -> V_36 ) ;
V_323 += V_289 ;
} while ( F_59 ( ( V_303 != NULL ) ||
( ( ! ( V_205 -> V_333 & V_334 ) ) &&
( F_47 ( & V_4 -> V_36 . V_306 ) ) ) )
);
V_56 = V_323 ;
goto V_327;
V_329:
F_14 ( V_4 , V_303 , V_11 ) ;
F_107 ( V_135 ) ;
V_327:
if ( V_321 )
F_188 ( V_50 ) ;
V_95:
F_119 ( & V_4 -> V_324 ) ;
return V_56 ;
}
static struct V_141 * F_189 ( struct V_2 * V_3 , T_5 V_335 ,
T_5 V_322 , T_5 V_140 ,
T_5 V_336 , int V_337 ,
int * V_56 )
{
struct V_141 * V_135 ;
if ( V_335 + V_140 < V_104 || ! V_336 )
V_336 = V_140 ;
V_135 = F_190 ( V_3 , V_335 + V_336 , V_140 - V_336 , V_337 ,
V_56 ) ;
if ( ! V_135 )
return NULL ;
F_140 ( V_135 , V_322 ) ;
F_143 ( V_135 , V_336 ) ;
V_135 -> V_318 = V_140 - V_336 ;
V_135 -> V_140 += V_140 - V_336 ;
return V_135 ;
}
static int F_191 ( struct V_203 * V_2 ,
struct V_204 * V_205 , T_5 V_140 )
{
struct V_2 * V_3 = V_2 -> V_3 ;
struct V_243 * V_206 = (struct V_243 * ) V_205 -> V_207 ;
struct V_141 * V_135 ;
struct V_49 * V_50 ;
T_6 V_208 ;
bool V_321 = false ;
unsigned char * V_309 ;
int V_56 , V_322 = 0 ;
struct V_338 V_339 = { 0 } ;
int V_312 = 0 ;
int V_340 ;
struct V_1 * V_4 = F_1 ( V_3 ) ;
unsigned short V_341 = 0 ;
int V_310 , V_223 ;
if ( V_206 == NULL ) {
V_50 = V_4 -> V_7 . V_50 ;
V_208 = V_4 -> V_151 ;
V_309 = NULL ;
} else {
V_56 = - V_178 ;
if ( V_205 -> V_209 < sizeof( struct V_243 ) )
goto V_95;
if ( V_205 -> V_209 < ( V_206 -> V_266 + F_183 ( struct V_243 , V_267 ) ) )
goto V_95;
V_208 = V_206 -> V_262 ;
V_309 = V_206 -> V_267 ;
V_50 = F_184 ( F_34 ( V_3 ) , V_206 -> V_265 ) ;
V_321 = true ;
}
V_56 = - V_326 ;
if ( V_50 == NULL )
goto V_214;
if ( V_2 -> type == V_342 )
V_322 = V_50 -> V_220 ;
V_56 = - V_215 ;
if ( ! ( V_50 -> V_216 & V_217 ) )
goto V_214;
if ( V_4 -> V_343 ) {
V_340 = sizeof( V_339 ) ;
V_56 = - V_178 ;
if ( V_140 < V_340 )
goto V_214;
V_140 -= V_340 ;
V_56 = F_142 ( ( void * ) & V_339 , V_205 -> V_229 ,
V_340 ) ;
if ( V_56 < 0 )
goto V_214;
if ( ( V_339 . V_216 & V_344 ) &&
( V_339 . V_345 + V_339 . V_346 + 2 >
V_339 . V_347 ) )
V_339 . V_347 = V_339 . V_345 +
V_339 . V_346 + 2 ;
V_56 = - V_178 ;
if ( V_339 . V_347 > V_140 )
goto V_214;
if ( V_339 . V_341 != V_348 ) {
switch ( V_339 . V_341 & ~ V_349 ) {
case V_350 :
V_341 = V_351 ;
break;
case V_352 :
V_341 = V_353 ;
break;
case V_354 :
V_341 = V_355 ;
break;
default:
goto V_214;
}
if ( V_339 . V_341 & V_349 )
V_341 |= V_356 ;
if ( V_339 . V_357 == 0 )
goto V_214;
}
}
V_56 = - V_218 ;
if ( ! V_341 && ( V_140 > V_50 -> V_219 + V_322 + V_221 ) )
goto V_214;
V_56 = - V_227 ;
V_310 = F_137 ( V_50 ) ;
V_223 = V_50 -> V_224 ;
V_135 = F_189 ( V_3 , V_310 + V_223 , V_310 , V_140 , V_339 . V_347 ,
V_205 -> V_333 & V_334 , & V_56 ) ;
if ( V_135 == NULL )
goto V_214;
F_192 ( V_135 , V_322 ) ;
V_56 = - V_178 ;
if ( V_2 -> type == V_250 &&
( V_312 = F_175 ( V_135 , V_50 , F_176 ( V_208 ) , V_309 , NULL , V_140 ) ) < 0 )
goto V_230;
V_56 = F_193 ( V_135 , V_312 , V_205 -> V_229 , 0 , V_140 ) ;
if ( V_56 )
goto V_230;
V_56 = F_147 ( V_3 , & F_148 ( V_135 ) -> V_239 ) ;
if ( V_56 < 0 )
goto V_230;
if ( ! V_341 && ( V_140 > V_50 -> V_219 + V_322 ) ) {
struct V_231 * V_232 ;
F_144 ( V_135 ) ;
V_232 = F_145 ( V_135 ) ;
if ( V_232 -> V_233 != F_146 ( V_234 ) ) {
V_56 = - V_218 ;
goto V_230;
}
}
V_135 -> V_200 = V_208 ;
V_135 -> V_50 = V_50 ;
V_135 -> V_235 = V_3 -> V_236 ;
V_135 -> V_237 = V_3 -> V_238 ;
if ( V_4 -> V_343 ) {
if ( V_339 . V_216 & V_344 ) {
if ( ! F_194 ( V_135 , V_339 . V_345 ,
V_339 . V_346 ) ) {
V_56 = - V_178 ;
goto V_230;
}
}
F_148 ( V_135 ) -> V_357 = V_339 . V_357 ;
F_148 ( V_135 ) -> V_341 = V_341 ;
F_148 ( V_135 ) -> V_341 |= V_358 ;
F_148 ( V_135 ) -> V_359 = 0 ;
V_140 += V_340 ;
}
V_56 = F_149 ( V_135 ) ;
if ( V_56 > 0 && ( V_56 = F_187 ( V_56 ) ) != 0 )
goto V_214;
if ( V_321 )
F_188 ( V_50 ) ;
return V_140 ;
V_230:
F_107 ( V_135 ) ;
V_214:
if ( V_50 && V_321 )
F_188 ( V_50 ) ;
V_95:
return V_56 ;
}
static int F_195 ( struct V_201 * V_202 , struct V_203 * V_2 ,
struct V_204 * V_205 , T_5 V_140 )
{
struct V_2 * V_3 = V_2 -> V_3 ;
struct V_1 * V_4 = F_1 ( V_3 ) ;
if ( V_4 -> V_36 . V_29 )
return F_182 ( V_4 , V_205 ) ;
else
return F_191 ( V_2 , V_205 , V_140 ) ;
}
static int F_196 ( struct V_203 * V_2 )
{
struct V_2 * V_3 = V_2 -> V_3 ;
struct V_1 * V_4 ;
struct V_167 * V_167 ;
union V_65 V_66 ;
if ( ! V_3 )
return 0 ;
V_167 = F_34 ( V_3 ) ;
V_4 = F_1 ( V_3 ) ;
F_197 ( & V_167 -> V_360 . V_361 ) ;
F_198 ( V_3 ) ;
F_199 ( V_167 , V_3 -> V_362 , - 1 ) ;
F_200 ( & V_167 -> V_360 . V_361 ) ;
F_12 ( & V_4 -> V_9 ) ;
F_13 ( V_3 , false ) ;
if ( V_4 -> V_7 . V_50 ) {
F_188 ( V_4 -> V_7 . V_50 ) ;
V_4 -> V_7 . V_50 = NULL ;
}
F_10 ( & V_4 -> V_9 ) ;
F_201 ( V_3 ) ;
memset ( & V_66 , 0 , sizeof( V_66 ) ) ;
if ( V_4 -> V_40 . V_29 )
F_202 ( V_3 , & V_66 , 1 , 0 ) ;
if ( V_4 -> V_36 . V_29 )
F_202 ( V_3 , & V_66 , 1 , 1 ) ;
F_120 ( V_3 ) ;
F_11 () ;
F_203 ( V_3 ) ;
V_2 -> V_3 = NULL ;
F_92 ( & V_3 -> V_94 ) ;
F_204 ( V_3 ) ;
F_205 ( V_3 ) ;
return 0 ;
}
static int F_206 ( struct V_2 * V_3 , struct V_49 * V_50 , T_6 V_200 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
if ( V_4 -> V_6 ) {
if ( V_50 )
F_188 ( V_50 ) ;
return - V_178 ;
}
F_207 ( V_3 ) ;
F_12 ( & V_4 -> V_9 ) ;
F_13 ( V_3 , true ) ;
V_4 -> V_151 = V_200 ;
V_4 -> V_7 . type = V_200 ;
if ( V_4 -> V_7 . V_50 )
F_188 ( V_4 -> V_7 . V_50 ) ;
V_4 -> V_7 . V_50 = V_50 ;
V_4 -> V_57 = V_50 ? V_50 -> V_57 : 0 ;
if ( V_200 == 0 )
goto V_214;
if ( ! V_50 || ( V_50 -> V_216 & V_217 ) ) {
F_2 ( V_3 ) ;
} else {
V_3 -> V_363 = V_215 ;
if ( ! F_94 ( V_3 , V_148 ) )
V_3 -> V_364 ( V_3 ) ;
}
V_214:
F_10 ( & V_4 -> V_9 ) ;
F_208 ( V_3 ) ;
return 0 ;
}
static int F_209 ( struct V_203 * V_2 , struct V_210 * V_365 ,
int V_366 )
{
struct V_2 * V_3 = V_2 -> V_3 ;
char V_198 [ 15 ] ;
struct V_49 * V_50 ;
int V_56 = - V_213 ;
if ( V_366 != sizeof( struct V_210 ) )
return - V_178 ;
F_132 ( V_198 , V_365 -> V_367 , sizeof( V_198 ) ) ;
V_50 = F_210 ( F_34 ( V_3 ) , V_198 ) ;
if ( V_50 )
V_56 = F_206 ( V_3 , V_50 , F_1 ( V_3 ) -> V_151 ) ;
return V_56 ;
}
static int F_211 ( struct V_203 * V_2 , struct V_210 * V_365 , int V_366 )
{
struct V_243 * V_244 = (struct V_243 * ) V_365 ;
struct V_2 * V_3 = V_2 -> V_3 ;
struct V_49 * V_50 = NULL ;
int V_56 ;
if ( V_366 < sizeof( struct V_243 ) )
return - V_178 ;
if ( V_244 -> V_259 != V_260 )
return - V_178 ;
if ( V_244 -> V_265 ) {
V_56 = - V_213 ;
V_50 = F_184 ( F_34 ( V_3 ) , V_244 -> V_265 ) ;
if ( V_50 == NULL )
goto V_95;
}
V_56 = F_206 ( V_3 , V_50 , V_244 -> V_262 ? : F_1 ( V_3 ) -> V_151 ) ;
V_95:
return V_56 ;
}
static int F_212 ( struct V_167 * V_167 , struct V_203 * V_2 , int V_200 ,
int V_368 )
{
struct V_2 * V_3 ;
struct V_1 * V_4 ;
T_6 V_208 = ( V_369 T_6 ) V_200 ;
int V_56 ;
if ( ! F_213 ( V_370 ) )
return - V_371 ;
if ( V_2 -> type != V_250 && V_2 -> type != V_342 &&
V_2 -> type != V_372 )
return - V_373 ;
V_2 -> V_374 = V_375 ;
V_56 = - V_227 ;
V_3 = F_214 ( V_167 , V_376 , V_182 , & V_377 ) ;
if ( V_3 == NULL )
goto V_95;
V_2 -> V_378 = & V_379 ;
if ( V_2 -> type == V_372 )
V_2 -> V_378 = & V_380 ;
F_215 ( V_2 , V_3 ) ;
V_4 = F_1 ( V_3 ) ;
V_3 -> V_381 = V_376 ;
V_4 -> V_151 = V_208 ;
V_3 -> V_382 = F_91 ;
F_216 ( V_3 ) ;
F_117 ( & V_4 -> V_9 ) ;
F_217 ( & V_4 -> V_324 ) ;
V_4 -> V_7 . F_28 = F_153 ;
if ( V_2 -> type == V_372 )
V_4 -> V_7 . F_28 = F_125 ;
V_4 -> V_7 . V_165 = V_3 ;
if ( V_208 ) {
V_4 -> V_7 . type = V_208 ;
F_2 ( V_3 ) ;
}
F_197 ( & V_167 -> V_360 . V_361 ) ;
F_218 ( V_3 , & V_167 -> V_360 . V_383 ) ;
F_199 ( V_167 , & V_377 , 1 ) ;
F_200 ( & V_167 -> V_360 . V_361 ) ;
return 0 ;
V_95:
return V_56 ;
}
static int F_219 ( struct V_2 * V_3 , struct V_204 * V_205 , int V_140 )
{
struct V_384 * V_385 ;
struct V_141 * V_135 , * V_386 ;
int V_387 , V_56 ;
V_56 = - V_388 ;
V_135 = F_220 ( & V_3 -> V_145 ) ;
if ( V_135 == NULL )
goto V_95;
V_387 = V_135 -> V_140 ;
if ( V_387 > V_140 ) {
V_205 -> V_333 |= V_389 ;
V_387 = V_140 ;
}
V_56 = F_221 ( V_135 , 0 , V_205 -> V_229 , V_387 ) ;
if ( V_56 )
goto V_390;
F_222 ( V_205 , V_3 , V_135 ) ;
V_385 = F_223 ( V_135 ) ;
F_224 ( V_205 , V_391 , V_392 ,
sizeof( V_385 -> V_393 ) , & V_385 -> V_393 ) ;
V_205 -> V_333 |= V_394 ;
V_56 = V_387 ;
F_197 ( & V_3 -> V_145 . V_41 ) ;
V_3 -> V_363 = 0 ;
if ( ( V_386 = F_225 ( & V_3 -> V_145 ) ) != NULL ) {
V_3 -> V_363 = F_223 ( V_386 ) -> V_393 . V_395 ;
F_200 ( & V_3 -> V_145 . V_41 ) ;
V_3 -> V_364 ( V_3 ) ;
} else
F_200 ( & V_3 -> V_145 . V_41 ) ;
V_390:
F_107 ( V_135 ) ;
V_95:
return V_56 ;
}
static int F_226 ( struct V_201 * V_202 , struct V_203 * V_2 ,
struct V_204 * V_205 , T_5 V_140 , int V_216 )
{
struct V_2 * V_3 = V_2 -> V_3 ;
struct V_141 * V_135 ;
int V_387 , V_56 ;
struct V_243 * V_244 ;
int V_340 = 0 ;
V_56 = - V_178 ;
if ( V_216 & ~ ( V_396 | V_334 | V_389 | V_397 | V_394 ) )
goto V_95;
#if 0
if (pkt_sk(sk)->ifindex < 0)
return -ENODEV;
#endif
if ( V_216 & V_394 ) {
V_56 = F_219 ( V_3 , V_205 , V_140 ) ;
goto V_95;
}
V_135 = F_227 ( V_3 , V_216 , V_216 & V_334 , & V_56 ) ;
if ( V_135 == NULL )
goto V_95;
if ( F_1 ( V_3 ) -> V_343 ) {
struct V_338 V_339 = { 0 } ;
V_56 = - V_178 ;
V_340 = sizeof( V_339 ) ;
if ( V_140 < V_340 )
goto V_230;
V_140 -= V_340 ;
if ( F_228 ( V_135 ) ) {
struct V_398 * V_399 = F_148 ( V_135 ) ;
V_339 . V_347 = F_229 ( V_135 ) ;
V_339 . V_357 = V_399 -> V_357 ;
if ( V_399 -> V_341 & V_351 )
V_339 . V_341 = V_350 ;
else if ( V_399 -> V_341 & V_353 )
V_339 . V_341 = V_352 ;
else if ( V_399 -> V_341 & V_355 )
V_339 . V_341 = V_354 ;
else if ( V_399 -> V_341 & V_400 )
goto V_230;
else
F_18 () ;
if ( V_399 -> V_341 & V_356 )
V_339 . V_341 |= V_349 ;
} else
V_339 . V_341 = V_348 ;
if ( V_135 -> V_281 == V_282 ) {
V_339 . V_216 = V_344 ;
V_339 . V_345 = F_230 ( V_135 ) ;
V_339 . V_346 = V_135 -> V_346 ;
} else if ( V_135 -> V_281 == V_401 ) {
V_339 . V_216 = V_402 ;
}
V_56 = F_231 ( V_205 -> V_229 , ( void * ) & V_339 ,
V_340 ) ;
if ( V_56 < 0 )
goto V_230;
}
V_244 = & F_129 ( V_135 ) -> V_194 . V_258 ;
if ( V_2 -> type == V_372 )
V_205 -> V_209 = sizeof( struct V_188 ) ;
else
V_205 -> V_209 = V_244 -> V_266 + F_183 ( struct V_243 , V_267 ) ;
V_387 = V_135 -> V_140 ;
if ( V_387 > V_140 ) {
V_387 = V_140 ;
V_205 -> V_333 |= V_389 ;
}
V_56 = F_221 ( V_135 , 0 , V_205 -> V_229 , V_387 ) ;
if ( V_56 )
goto V_230;
F_232 ( V_205 , V_3 , V_135 ) ;
if ( V_205 -> V_207 )
memcpy ( V_205 -> V_207 , & F_129 ( V_135 ) -> V_194 ,
V_205 -> V_209 ) ;
if ( F_1 ( V_3 ) -> V_403 ) {
struct V_404 V_405 ;
V_405 . V_20 = V_107 ;
if ( V_135 -> V_281 == V_282 )
V_405 . V_20 |= V_283 ;
V_405 . V_289 = F_129 ( V_135 ) -> V_268 ;
V_405 . V_290 = V_135 -> V_140 ;
V_405 . V_291 = 0 ;
V_405 . V_292 = F_155 ( V_135 ) ;
if ( F_74 ( V_135 ) ) {
V_405 . V_136 = F_75 ( V_135 ) ;
V_405 . V_20 |= V_137 ;
} else {
V_405 . V_136 = 0 ;
}
V_405 . V_302 = 0 ;
F_224 ( V_205 , V_391 , V_406 , sizeof( V_405 ) , & V_405 ) ;
}
V_56 = V_340 + ( ( V_216 & V_389 ) ? V_135 -> V_140 : V_387 ) ;
V_230:
F_233 ( V_3 , V_135 ) ;
V_95:
return V_56 ;
}
static int F_234 ( struct V_203 * V_2 , struct V_210 * V_365 ,
int * V_407 , int V_408 )
{
struct V_49 * V_50 ;
struct V_2 * V_3 = V_2 -> V_3 ;
if ( V_408 )
return - V_409 ;
V_365 -> V_410 = V_260 ;
F_135 () ;
V_50 = F_235 ( F_34 ( V_3 ) , F_1 ( V_3 ) -> V_57 ) ;
if ( V_50 )
strncpy ( V_365 -> V_367 , V_50 -> V_198 , 14 ) ;
else
memset ( V_365 -> V_367 , 0 , 14 ) ;
F_138 () ;
* V_407 = sizeof( * V_365 ) ;
return 0 ;
}
static int F_236 ( struct V_203 * V_2 , struct V_210 * V_365 ,
int * V_407 , int V_408 )
{
struct V_49 * V_50 ;
struct V_2 * V_3 = V_2 -> V_3 ;
struct V_1 * V_4 = F_1 ( V_3 ) ;
F_237 ( struct V_243 * , V_244 , V_365 ) ;
if ( V_408 )
return - V_409 ;
V_244 -> V_259 = V_260 ;
V_244 -> V_265 = V_4 -> V_57 ;
V_244 -> V_262 = V_4 -> V_151 ;
V_244 -> V_263 = 0 ;
F_135 () ;
V_50 = F_235 ( F_34 ( V_3 ) , V_4 -> V_57 ) ;
if ( V_50 ) {
V_244 -> V_261 = V_50 -> type ;
V_244 -> V_266 = V_50 -> V_366 ;
memcpy ( V_244 -> V_267 , V_50 -> V_411 , V_50 -> V_366 ) ;
} else {
V_244 -> V_261 = 0 ;
V_244 -> V_266 = 0 ;
}
F_138 () ;
* V_407 = F_183 ( struct V_243 , V_267 ) + V_244 -> V_266 ;
return 0 ;
}
static int F_238 ( struct V_49 * V_50 , struct V_412 * V_173 ,
int V_413 )
{
switch ( V_173 -> type ) {
case V_414 :
if ( V_173 -> V_415 != V_50 -> V_366 )
return - V_178 ;
if ( V_413 > 0 )
return F_239 ( V_50 , V_173 -> V_309 ) ;
else
return F_240 ( V_50 , V_173 -> V_309 ) ;
break;
case V_416 :
return F_241 ( V_50 , V_413 ) ;
break;
case V_417 :
return F_242 ( V_50 , V_413 ) ;
break;
case V_418 :
if ( V_173 -> V_415 != V_50 -> V_366 )
return - V_178 ;
if ( V_413 > 0 )
return F_243 ( V_50 , V_173 -> V_309 ) ;
else
return F_244 ( V_50 , V_173 -> V_309 ) ;
break;
default:
break;
}
return 0 ;
}
static void F_245 ( struct V_49 * V_50 , struct V_412 * V_173 , int V_413 )
{
for ( ; V_173 ; V_173 = V_173 -> V_419 ) {
if ( V_173 -> V_57 == V_50 -> V_57 )
F_238 ( V_50 , V_173 , V_413 ) ;
}
}
static int F_246 ( struct V_2 * V_3 , struct V_420 * V_421 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
struct V_412 * V_422 , * V_173 ;
struct V_49 * V_50 ;
int V_56 ;
F_32 () ;
V_56 = - V_213 ;
V_50 = F_33 ( F_34 ( V_3 ) , V_421 -> V_423 ) ;
if ( ! V_50 )
goto V_424;
V_56 = - V_178 ;
if ( V_421 -> V_425 > V_50 -> V_366 )
goto V_424;
V_56 = - V_227 ;
V_173 = F_247 ( sizeof( * V_173 ) , V_182 ) ;
if ( V_173 == NULL )
goto V_424;
V_56 = 0 ;
for ( V_422 = V_4 -> V_426 ; V_422 ; V_422 = V_422 -> V_419 ) {
if ( V_422 -> V_57 == V_421 -> V_423 &&
V_422 -> type == V_421 -> V_427 &&
V_422 -> V_415 == V_421 -> V_425 &&
memcmp ( V_422 -> V_309 , V_421 -> V_428 , V_422 -> V_415 ) == 0 ) {
V_422 -> V_429 ++ ;
F_124 ( V_173 ) ;
goto V_424;
}
}
V_173 -> type = V_421 -> V_427 ;
V_173 -> V_57 = V_421 -> V_423 ;
V_173 -> V_415 = V_421 -> V_425 ;
memcpy ( V_173 -> V_309 , V_421 -> V_428 , V_173 -> V_415 ) ;
V_173 -> V_429 = 1 ;
V_173 -> V_419 = V_4 -> V_426 ;
V_4 -> V_426 = V_173 ;
V_56 = F_238 ( V_50 , V_173 , 1 ) ;
if ( V_56 ) {
V_4 -> V_426 = V_173 -> V_419 ;
F_124 ( V_173 ) ;
}
V_424:
F_36 () ;
return V_56 ;
}
static int F_248 ( struct V_2 * V_3 , struct V_420 * V_421 )
{
struct V_412 * V_422 , * * V_430 ;
F_32 () ;
for ( V_430 = & F_1 ( V_3 ) -> V_426 ; ( V_422 = * V_430 ) != NULL ; V_430 = & V_422 -> V_419 ) {
if ( V_422 -> V_57 == V_421 -> V_423 &&
V_422 -> type == V_421 -> V_427 &&
V_422 -> V_415 == V_421 -> V_425 &&
memcmp ( V_422 -> V_309 , V_421 -> V_428 , V_422 -> V_415 ) == 0 ) {
if ( -- V_422 -> V_429 == 0 ) {
struct V_49 * V_50 ;
* V_430 = V_422 -> V_419 ;
V_50 = F_33 ( F_34 ( V_3 ) , V_422 -> V_57 ) ;
if ( V_50 )
F_238 ( V_50 , V_422 , - 1 ) ;
F_124 ( V_422 ) ;
}
F_36 () ;
return 0 ;
}
}
F_36 () ;
return - V_431 ;
}
static void F_201 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
struct V_412 * V_422 ;
if ( ! V_4 -> V_426 )
return;
F_32 () ;
while ( ( V_422 = V_4 -> V_426 ) != NULL ) {
struct V_49 * V_50 ;
V_4 -> V_426 = V_422 -> V_419 ;
V_50 = F_33 ( F_34 ( V_3 ) , V_422 -> V_57 ) ;
if ( V_50 != NULL )
F_238 ( V_50 , V_422 , - 1 ) ;
F_124 ( V_422 ) ;
}
F_36 () ;
}
static int
F_249 ( struct V_203 * V_2 , int V_432 , int V_433 , char T_7 * V_434 , unsigned int V_435 )
{
struct V_2 * V_3 = V_2 -> V_3 ;
struct V_1 * V_4 = F_1 ( V_3 ) ;
int V_436 ;
if ( V_432 != V_391 )
return - V_437 ;
switch ( V_433 ) {
case V_438 :
case V_439 :
{
struct V_420 V_421 ;
int V_140 = V_435 ;
memset ( & V_421 , 0 , sizeof( V_421 ) ) ;
if ( V_140 < sizeof( struct V_440 ) )
return - V_178 ;
if ( V_140 > sizeof( V_421 ) )
V_140 = sizeof( V_421 ) ;
if ( F_250 ( & V_421 , V_434 , V_140 ) )
return - V_317 ;
if ( V_140 < ( V_421 . V_425 + F_183 ( struct V_440 , V_428 ) ) )
return - V_178 ;
if ( V_433 == V_438 )
V_436 = F_246 ( V_3 , & V_421 ) ;
else
V_436 = F_248 ( V_3 , & V_421 ) ;
return V_436 ;
}
case V_441 :
case V_442 :
{
union V_65 V_66 ;
int V_140 ;
switch ( V_4 -> V_18 ) {
case V_19 :
case V_21 :
V_140 = sizeof( V_66 . V_443 ) ;
break;
case V_22 :
default:
V_140 = sizeof( V_66 . V_68 ) ;
break;
}
if ( V_435 < V_140 )
return - V_178 ;
if ( F_1 ( V_3 ) -> V_343 )
return - V_178 ;
if ( F_250 ( & V_66 . V_443 , V_434 , V_140 ) )
return - V_317 ;
return F_202 ( V_3 , & V_66 , 0 ,
V_433 == V_442 ) ;
}
case V_444 :
{
int V_445 ;
if ( V_435 != sizeof( V_445 ) )
return - V_178 ;
if ( F_250 ( & V_445 , V_434 , sizeof( V_445 ) ) )
return - V_317 ;
F_1 ( V_3 ) -> V_286 = V_445 ;
return 0 ;
}
case V_446 :
{
int V_445 ;
if ( V_435 != sizeof( V_445 ) )
return - V_178 ;
if ( V_4 -> V_40 . V_29 || V_4 -> V_36 . V_29 )
return - V_325 ;
if ( F_250 ( & V_445 , V_434 , sizeof( V_445 ) ) )
return - V_317 ;
switch ( V_445 ) {
case V_19 :
case V_21 :
case V_22 :
V_4 -> V_18 = V_445 ;
return 0 ;
default:
return - V_178 ;
}
}
case V_447 :
{
unsigned int V_445 ;
if ( V_435 != sizeof( V_445 ) )
return - V_178 ;
if ( V_4 -> V_40 . V_29 || V_4 -> V_36 . V_29 )
return - V_325 ;
if ( F_250 ( & V_445 , V_434 , sizeof( V_445 ) ) )
return - V_317 ;
V_4 -> V_284 = V_445 ;
return 0 ;
}
case V_448 :
{
unsigned int V_445 ;
if ( V_435 != sizeof( V_445 ) )
return - V_178 ;
if ( V_4 -> V_40 . V_29 || V_4 -> V_36 . V_29 )
return - V_325 ;
if ( F_250 ( & V_445 , V_434 , sizeof( V_445 ) ) )
return - V_317 ;
V_4 -> V_330 = ! ! V_445 ;
return 0 ;
}
case V_406 :
{
int V_445 ;
if ( V_435 < sizeof( V_445 ) )
return - V_178 ;
if ( F_250 ( & V_445 , V_434 , sizeof( V_445 ) ) )
return - V_317 ;
V_4 -> V_403 = ! ! V_445 ;
return 0 ;
}
case V_449 :
{
int V_445 ;
if ( V_435 < sizeof( V_445 ) )
return - V_178 ;
if ( F_250 ( & V_445 , V_434 , sizeof( V_445 ) ) )
return - V_317 ;
V_4 -> V_264 = ! ! V_445 ;
return 0 ;
}
case V_450 :
{
int V_445 ;
if ( V_2 -> type != V_342 )
return - V_178 ;
if ( V_4 -> V_40 . V_29 || V_4 -> V_36 . V_29 )
return - V_325 ;
if ( V_435 < sizeof( V_445 ) )
return - V_178 ;
if ( F_250 ( & V_445 , V_434 , sizeof( V_445 ) ) )
return - V_317 ;
V_4 -> V_343 = ! ! V_445 ;
return 0 ;
}
case V_451 :
{
int V_445 ;
if ( V_435 != sizeof( V_445 ) )
return - V_178 ;
if ( F_250 ( & V_445 , V_434 , sizeof( V_445 ) ) )
return - V_317 ;
V_4 -> V_293 = V_445 ;
return 0 ;
}
case V_452 :
{
int V_445 ;
if ( V_435 != sizeof( V_445 ) )
return - V_178 ;
if ( F_250 ( & V_445 , V_434 , sizeof( V_445 ) ) )
return - V_317 ;
return F_110 ( V_3 , V_445 & 0xffff , V_445 >> 16 ) ;
}
default:
return - V_437 ;
}
}
static int F_251 ( struct V_203 * V_2 , int V_432 , int V_433 ,
char T_7 * V_434 , int T_7 * V_435 )
{
int V_140 ;
int V_445 ;
struct V_2 * V_3 = V_2 -> V_3 ;
struct V_1 * V_4 = F_1 ( V_3 ) ;
void * V_43 ;
struct V_453 V_454 ;
union V_455 V_456 ;
if ( V_432 != V_391 )
return - V_437 ;
if ( F_252 ( V_140 , V_435 ) )
return - V_317 ;
if ( V_140 < 0 )
return - V_178 ;
switch ( V_433 ) {
case V_457 :
if ( V_4 -> V_18 == V_22 ) {
V_140 = sizeof( struct V_458 ) ;
} else {
if ( V_140 > sizeof( struct V_453 ) )
V_140 = sizeof( struct V_453 ) ;
}
F_197 ( & V_3 -> V_94 . V_41 ) ;
if ( V_4 -> V_18 == V_22 ) {
memcpy ( & V_456 . V_85 , & V_4 -> V_113 ,
sizeof( struct V_453 ) ) ;
V_456 . V_85 . V_86 =
V_4 -> V_84 . V_85 . V_86 ;
V_456 . V_85 . V_269 += V_4 -> V_113 . V_114 ;
V_43 = & V_456 . V_85 ;
} else {
V_454 = V_4 -> V_113 ;
V_454 . V_269 += V_454 . V_114 ;
V_43 = & V_454 ;
}
memset ( & V_4 -> V_113 , 0 , sizeof( V_454 ) ) ;
F_200 ( & V_3 -> V_94 . V_41 ) ;
break;
case V_406 :
if ( V_140 > sizeof( int ) )
V_140 = sizeof( int ) ;
V_445 = V_4 -> V_403 ;
V_43 = & V_445 ;
break;
case V_449 :
if ( V_140 > sizeof( int ) )
V_140 = sizeof( int ) ;
V_445 = V_4 -> V_264 ;
V_43 = & V_445 ;
break;
case V_450 :
if ( V_140 > sizeof( int ) )
V_140 = sizeof( int ) ;
V_445 = V_4 -> V_343 ;
V_43 = & V_445 ;
break;
case V_446 :
if ( V_140 > sizeof( int ) )
V_140 = sizeof( int ) ;
V_445 = V_4 -> V_18 ;
V_43 = & V_445 ;
break;
case V_459 :
if ( V_140 > sizeof( int ) )
V_140 = sizeof( int ) ;
if ( F_250 ( & V_445 , V_434 , V_140 ) )
return - V_317 ;
switch ( V_445 ) {
case V_19 :
V_445 = sizeof( struct V_12 ) ;
break;
case V_21 :
V_445 = sizeof( struct V_14 ) ;
break;
case V_22 :
V_445 = sizeof( struct V_108 ) ;
break;
default:
return - V_178 ;
}
V_43 = & V_445 ;
break;
case V_447 :
if ( V_140 > sizeof( unsigned int ) )
V_140 = sizeof( unsigned int ) ;
V_445 = V_4 -> V_284 ;
V_43 = & V_445 ;
break;
case V_448 :
if ( V_140 > sizeof( unsigned int ) )
V_140 = sizeof( unsigned int ) ;
V_445 = V_4 -> V_330 ;
V_43 = & V_445 ;
break;
case V_451 :
if ( V_140 > sizeof( int ) )
V_140 = sizeof( int ) ;
V_445 = V_4 -> V_293 ;
V_43 = & V_445 ;
break;
case V_452 :
if ( V_140 > sizeof( int ) )
V_140 = sizeof( int ) ;
V_445 = ( V_4 -> V_6 ?
( ( T_3 ) V_4 -> V_6 -> V_174 |
( ( T_3 ) V_4 -> V_6 -> type << 16 ) ) :
0 ) ;
V_43 = & V_445 ;
break;
default:
return - V_437 ;
}
if ( F_253 ( V_140 , V_435 ) )
return - V_317 ;
if ( F_254 ( V_434 , V_43 , V_140 ) )
return - V_317 ;
return 0 ;
}
static int F_255 ( struct V_460 * V_461 , unsigned long V_205 , void * V_43 )
{
struct V_2 * V_3 ;
struct V_462 * V_463 ;
struct V_49 * V_50 = V_43 ;
struct V_167 * V_167 = F_105 ( V_50 ) ;
F_135 () ;
F_256 (sk, node, &net->packet.sklist) {
struct V_1 * V_4 = F_1 ( V_3 ) ;
switch ( V_205 ) {
case V_464 :
if ( V_4 -> V_426 )
F_245 ( V_50 , V_4 -> V_426 , - 1 ) ;
case V_465 :
if ( V_50 -> V_57 == V_4 -> V_57 ) {
F_12 ( & V_4 -> V_9 ) ;
if ( V_4 -> V_5 ) {
F_6 ( V_3 , false ) ;
V_3 -> V_363 = V_215 ;
if ( ! F_94 ( V_3 , V_148 ) )
V_3 -> V_364 ( V_3 ) ;
}
if ( V_205 == V_464 ) {
V_4 -> V_57 = - 1 ;
if ( V_4 -> V_7 . V_50 )
F_188 ( V_4 -> V_7 . V_50 ) ;
V_4 -> V_7 . V_50 = NULL ;
}
F_10 ( & V_4 -> V_9 ) ;
}
break;
case V_466 :
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
return V_467 ;
}
static int F_257 ( struct V_203 * V_2 , unsigned int V_468 ,
unsigned long V_469 )
{
struct V_2 * V_3 = V_2 -> V_3 ;
switch ( V_468 ) {
case V_470 :
{
int V_471 = F_258 ( V_3 ) ;
return F_253 ( V_471 , ( int T_7 * ) V_469 ) ;
}
case V_472 :
{
struct V_141 * V_135 ;
int V_471 = 0 ;
F_197 ( & V_3 -> V_94 . V_41 ) ;
V_135 = F_225 ( & V_3 -> V_94 ) ;
if ( V_135 )
V_471 = V_135 -> V_140 ;
F_200 ( & V_3 -> V_94 . V_41 ) ;
return F_253 ( V_471 , ( int T_7 * ) V_469 ) ;
}
case V_473 :
return F_259 ( V_3 , (struct V_277 T_7 * ) V_469 ) ;
case V_474 :
return F_260 ( V_3 , (struct V_123 T_7 * ) V_469 ) ;
#ifdef F_261
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
case V_486 :
case V_487 :
case V_488 :
return V_489 . V_490 ( V_2 , V_468 , V_469 ) ;
#endif
default:
return - V_491 ;
}
return 0 ;
}
static unsigned int F_262 ( struct V_492 * V_492 , struct V_203 * V_2 ,
T_8 * V_493 )
{
struct V_2 * V_3 = V_2 -> V_3 ;
struct V_1 * V_4 = F_1 ( V_3 ) ;
unsigned int V_494 = F_263 ( V_492 , V_2 , V_493 ) ;
F_197 ( & V_3 -> V_94 . V_41 ) ;
if ( V_4 -> V_40 . V_29 ) {
if ( ! F_87 ( V_4 , & V_4 -> V_40 ,
V_128 ) )
V_494 |= V_495 | V_496 ;
}
F_200 ( & V_3 -> V_94 . V_41 ) ;
F_197 ( & V_3 -> V_497 . V_41 ) ;
if ( V_4 -> V_36 . V_29 ) {
if ( F_23 ( V_4 , & V_4 -> V_36 , V_307 ) )
V_494 |= V_498 | V_499 ;
}
F_200 ( & V_3 -> V_497 . V_41 ) ;
return V_494 ;
}
static void F_264 ( struct V_500 * V_501 )
{
struct V_492 * V_492 = V_501 -> V_502 ;
struct V_203 * V_2 = V_492 -> V_503 ;
struct V_2 * V_3 = V_2 -> V_3 ;
if ( V_3 )
F_79 ( & F_1 ( V_3 ) -> V_504 ) ;
}
static void F_265 ( struct V_500 * V_501 )
{
struct V_492 * V_492 = V_501 -> V_502 ;
struct V_203 * V_2 = V_492 -> V_503 ;
struct V_2 * V_3 = V_2 -> V_3 ;
if ( V_3 )
F_69 ( & F_1 ( V_3 ) -> V_504 ) ;
}
static void F_266 ( struct V_70 * V_29 , unsigned int V_505 ,
unsigned int V_140 )
{
int V_173 ;
for ( V_173 = 0 ; V_173 < V_140 ; V_173 ++ ) {
if ( F_59 ( V_29 [ V_173 ] . V_30 ) ) {
if ( F_267 ( V_29 [ V_173 ] . V_30 ) )
F_268 ( V_29 [ V_173 ] . V_30 ) ;
else
F_269 ( ( unsigned long ) V_29 [ V_173 ] . V_30 ,
V_505 ) ;
V_29 [ V_173 ] . V_30 = NULL ;
}
}
F_124 ( V_29 ) ;
}
static char * F_270 ( unsigned long V_505 )
{
char * V_30 = NULL ;
T_9 V_506 = V_182 | V_507 |
V_508 | V_509 | V_510 ;
V_30 = ( char * ) F_271 ( V_506 , V_505 ) ;
if ( V_30 )
return V_30 ;
V_30 = F_272 ( ( 1 << V_505 ) * V_104 ) ;
if ( V_30 )
return V_30 ;
V_506 &= ~ V_510 ;
V_30 = ( char * ) F_271 ( V_506 , V_505 ) ;
if ( V_30 )
return V_30 ;
return NULL ;
}
static struct V_70 * F_273 ( struct V_511 * V_443 , int V_505 )
{
unsigned int V_512 = V_443 -> V_79 ;
struct V_70 * V_29 ;
int V_173 ;
V_29 = F_274 ( V_512 , sizeof( struct V_70 ) , V_182 ) ;
if ( F_35 ( ! V_29 ) )
goto V_95;
for ( V_173 = 0 ; V_173 < V_512 ; V_173 ++ ) {
V_29 [ V_173 ] . V_30 = F_270 ( V_505 ) ;
if ( F_35 ( ! V_29 [ V_173 ] . V_30 ) )
goto V_513;
}
V_95:
return V_29 ;
V_513:
F_266 ( V_29 , V_505 , V_512 ) ;
V_29 = NULL ;
goto V_95;
}
static int F_202 ( struct V_2 * V_3 , union V_65 * V_66 ,
int V_514 , int V_36 )
{
struct V_70 * V_29 = NULL ;
struct V_1 * V_4 = F_1 ( V_3 ) ;
int V_515 , V_505 = 0 ;
struct V_23 * V_24 ;
struct V_37 * V_38 ;
T_6 V_151 ;
int V_56 = - V_178 ;
struct V_511 * V_443 = & V_66 -> V_443 ;
if ( ! V_514 && V_36 && ( V_4 -> V_18 > V_21 ) ) {
F_17 ( 1 , L_9 ) ;
goto V_95;
}
V_24 = V_36 ? & V_4 -> V_36 : & V_4 -> V_40 ;
V_38 = V_36 ? & V_3 -> V_497 : & V_3 -> V_94 ;
V_56 = - V_325 ;
if ( ! V_514 ) {
if ( F_47 ( & V_4 -> V_504 ) )
goto V_95;
if ( F_47 ( & V_24 -> V_306 ) )
goto V_95;
}
if ( V_443 -> V_79 ) {
V_56 = - V_325 ;
if ( F_35 ( V_24 -> V_29 ) )
goto V_95;
switch ( V_4 -> V_18 ) {
case V_19 :
V_4 -> V_81 = V_516 ;
break;
case V_21 :
V_4 -> V_81 = V_517 ;
break;
case V_22 :
V_4 -> V_81 = V_518 ;
break;
}
V_56 = - V_178 ;
if ( F_35 ( ( int ) V_443 -> V_77 <= 0 ) )
goto V_95;
if ( F_35 ( V_443 -> V_77 & ( V_104 - 1 ) ) )
goto V_95;
if ( F_35 ( V_443 -> V_519 < V_4 -> V_81 +
V_4 -> V_284 ) )
goto V_95;
if ( F_35 ( V_443 -> V_519 & ( V_520 - 1 ) ) )
goto V_95;
V_24 -> V_28 = V_443 -> V_77 / V_443 -> V_519 ;
if ( F_35 ( V_24 -> V_28 <= 0 ) )
goto V_95;
if ( F_35 ( ( V_24 -> V_28 * V_443 -> V_79 ) !=
V_443 -> V_521 ) )
goto V_95;
V_56 = - V_181 ;
V_505 = F_275 ( V_443 -> V_77 ) ;
V_29 = F_273 ( V_443 , V_505 ) ;
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
if ( F_35 ( V_443 -> V_521 ) )
goto V_95;
}
F_207 ( V_3 ) ;
F_12 ( & V_4 -> V_9 ) ;
V_515 = V_4 -> V_5 ;
V_151 = V_4 -> V_151 ;
if ( V_515 ) {
V_4 -> V_151 = 0 ;
F_6 ( V_3 , false ) ;
}
F_10 ( & V_4 -> V_9 ) ;
F_11 () ;
V_56 = - V_325 ;
F_111 ( & V_4 -> V_324 ) ;
if ( V_514 || F_47 ( & V_4 -> V_504 ) == 0 ) {
V_56 = 0 ;
F_197 ( & V_38 -> V_41 ) ;
F_276 ( V_24 -> V_29 , V_29 ) ;
V_24 -> V_143 = ( V_443 -> V_521 - 1 ) ;
V_24 -> V_32 = 0 ;
V_24 -> V_31 = V_443 -> V_519 ;
F_200 ( & V_38 -> V_41 ) ;
F_276 ( V_24 -> V_522 , V_505 ) ;
F_276 ( V_24 -> V_523 , V_443 -> V_79 ) ;
V_24 -> V_524 = V_443 -> V_77 / V_104 ;
V_4 -> V_7 . F_28 = ( V_4 -> V_40 . V_29 ) ?
F_164 : F_153 ;
F_92 ( V_38 ) ;
if ( F_47 ( & V_4 -> V_504 ) )
F_95 ( L_10 ,
F_47 ( & V_4 -> V_504 ) ) ;
}
F_119 ( & V_4 -> V_324 ) ;
F_12 ( & V_4 -> V_9 ) ;
if ( V_515 ) {
V_4 -> V_151 = V_151 ;
F_2 ( V_3 ) ;
}
F_10 ( & V_4 -> V_9 ) ;
if ( V_514 && ( V_4 -> V_18 > V_21 ) ) {
if ( ! V_36 )
F_26 ( V_4 , V_36 , V_38 ) ;
}
F_208 ( V_3 ) ;
if ( V_29 )
F_266 ( V_29 , V_505 , V_443 -> V_79 ) ;
V_95:
return V_56 ;
}
static int F_277 ( struct V_492 * V_492 , struct V_203 * V_2 ,
struct V_500 * V_501 )
{
struct V_2 * V_3 = V_2 -> V_3 ;
struct V_1 * V_4 = F_1 ( V_3 ) ;
unsigned long V_525 , V_526 ;
struct V_23 * V_24 ;
unsigned long V_102 ;
int V_56 = - V_178 ;
int V_173 ;
if ( V_501 -> V_527 )
return - V_178 ;
F_111 ( & V_4 -> V_324 ) ;
V_526 = 0 ;
for ( V_24 = & V_4 -> V_40 ; V_24 <= & V_4 -> V_36 ; V_24 ++ ) {
if ( V_24 -> V_29 ) {
V_526 += V_24 -> V_523
* V_24 -> V_524
* V_104 ;
}
}
if ( V_526 == 0 )
goto V_95;
V_525 = V_501 -> V_528 - V_501 -> V_529 ;
if ( V_525 != V_526 )
goto V_95;
V_102 = V_501 -> V_529 ;
for ( V_24 = & V_4 -> V_40 ; V_24 <= & V_4 -> V_36 ; V_24 ++ ) {
if ( V_24 -> V_29 == NULL )
continue;
for ( V_173 = 0 ; V_173 < V_24 -> V_523 ; V_173 ++ ) {
struct V_316 * V_316 ;
void * V_530 = V_24 -> V_29 [ V_173 ] . V_30 ;
int V_531 ;
for ( V_531 = 0 ; V_531 < V_24 -> V_524 ; V_531 ++ ) {
V_316 = F_16 ( V_530 ) ;
V_56 = F_278 ( V_501 , V_102 , V_316 ) ;
if ( F_35 ( V_56 ) )
goto V_95;
V_102 += V_104 ;
V_530 += V_104 ;
}
}
}
F_79 ( & V_4 -> V_504 ) ;
V_501 -> V_532 = & V_533 ;
V_56 = 0 ;
V_95:
F_119 ( & V_4 -> V_324 ) ;
return V_56 ;
}
static void * F_279 ( struct V_534 * V_535 , T_10 * V_536 )
__acquires( T_11 )
{
struct V_167 * V_167 = F_280 ( V_535 ) ;
F_135 () ;
return F_281 ( & V_167 -> V_360 . V_383 , * V_536 ) ;
}
static void * F_282 ( struct V_534 * V_535 , void * V_537 , T_10 * V_536 )
{
struct V_167 * V_167 = F_280 ( V_535 ) ;
return F_283 ( V_537 , & V_167 -> V_360 . V_383 , V_536 ) ;
}
static void F_284 ( struct V_534 * V_535 , void * V_537 )
__releases( T_11 )
{
F_138 () ;
}
static int F_285 ( struct V_534 * V_535 , void * V_537 )
{
if ( V_537 == V_538 )
F_286 ( V_535 , L_11 ) ;
else {
struct V_2 * V_539 = F_287 ( V_537 ) ;
const struct V_1 * V_4 = F_1 ( V_539 ) ;
F_288 ( V_535 ,
L_12 ,
V_539 ,
F_47 ( & V_539 -> V_540 ) ,
V_539 -> V_249 ,
F_176 ( V_4 -> V_151 ) ,
V_4 -> V_57 ,
V_4 -> V_5 ,
F_47 ( & V_539 -> V_146 ) ,
F_289 ( V_539 ) ,
F_290 ( V_539 ) ) ;
}
return 0 ;
}
static int F_291 ( struct V_541 * V_541 , struct V_492 * V_492 )
{
return F_292 ( V_541 , V_492 , & V_542 ,
sizeof( struct V_543 ) ) ;
}
static int T_12 F_293 ( struct V_167 * V_167 )
{
F_117 ( & V_167 -> V_360 . V_361 ) ;
F_294 ( & V_167 -> V_360 . V_383 ) ;
if ( ! F_295 ( V_167 , L_13 , 0 , & V_544 ) )
return - V_181 ;
return 0 ;
}
static void T_13 F_296 ( struct V_167 * V_167 )
{
F_297 ( V_167 , L_13 ) ;
}
static void T_14 F_298 ( void )
{
F_299 ( & V_545 ) ;
F_300 ( & V_546 ) ;
F_301 ( V_376 ) ;
F_302 ( & V_377 ) ;
}
static int T_15 F_303 ( void )
{
int V_547 = F_304 ( & V_377 , 0 ) ;
if ( V_547 != 0 )
goto V_95;
F_305 ( & V_548 ) ;
F_306 ( & V_546 ) ;
F_307 ( & V_545 ) ;
V_95:
return V_547 ;
}
