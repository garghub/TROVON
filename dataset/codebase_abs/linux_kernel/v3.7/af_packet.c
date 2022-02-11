static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
if ( ! V_4 -> V_5 ) {
if ( V_4 -> V_6 )
F_3 ( V_2 , V_4 ) ;
else
F_4 ( & V_4 -> V_7 ) ;
F_5 ( V_2 ) ;
V_4 -> V_5 = 1 ;
}
}
static void F_6 ( struct V_1 * V_2 , bool V_8 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
V_4 -> V_5 = 0 ;
if ( V_4 -> V_6 )
F_7 ( V_2 , V_4 ) ;
else
F_8 ( & V_4 -> V_7 ) ;
F_9 ( V_2 ) ;
if ( V_8 ) {
F_10 ( & V_4 -> V_9 ) ;
F_11 () ;
F_12 ( & V_4 -> V_9 ) ;
}
}
static void F_13 ( struct V_1 * V_2 , bool V_8 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
if ( V_4 -> V_5 )
F_6 ( V_2 , V_8 ) ;
}
void F_14 ( struct V_3 * V_4 , void * V_10 , int V_11 )
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
static int F_20 ( struct V_3 * V_4 , void * V_10 )
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
static void * F_22 ( struct V_3 * V_4 ,
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
static void * F_23 ( struct V_3 * V_4 ,
struct V_23 * V_24 ,
int V_11 )
{
return F_22 ( V_4 , V_24 , V_24 -> V_32 , V_11 ) ;
}
static void F_24 ( struct V_33 * V_34 )
{
F_25 ( & V_34 -> V_35 ) ;
}
static void F_26 ( struct V_3 * V_4 ,
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
static void F_27 ( struct V_3 * V_4 ,
struct V_33 * V_34 ,
void (* F_28) ( unsigned long ) )
{
F_29 ( & V_34 -> V_35 ) ;
V_34 -> V_35 . V_43 = ( long ) V_4 ;
V_34 -> V_35 . V_44 = F_28 ;
V_34 -> V_35 . V_45 = V_46 ;
}
static void F_30 ( struct V_3 * V_4 , int V_36 )
{
struct V_33 * V_34 ;
if ( V_36 )
F_18 () ;
V_34 = V_36 ? & V_4 -> V_36 . V_39 : & V_4 -> V_40 . V_39 ;
F_27 ( V_4 , V_34 , V_47 ) ;
}
static int F_31 ( struct V_3 * V_4 ,
int V_48 )
{
struct V_49 * V_50 ;
unsigned int V_51 = 0 , V_52 = 0 , div = 0 , V_53 = 0 ;
struct V_54 V_55 ;
int V_56 ;
T_1 V_57 ;
F_32 () ;
V_50 = F_33 ( F_34 ( & V_4 -> V_2 ) , V_4 -> V_58 ) ;
if ( F_35 ( ! V_50 ) ) {
F_36 () ;
return V_59 ;
}
V_56 = F_37 ( V_50 , & V_55 ) ;
V_57 = F_38 ( & V_55 ) ;
F_36 () ;
if ( ! V_56 ) {
if ( V_57 < V_60 || V_57 == V_61 ) {
return V_59 ;
} else {
V_52 = 1 ;
div = V_57 / 1000 ;
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
static void F_39 ( struct V_33 * V_62 ,
union V_63 * V_64 )
{
V_62 -> V_65 = V_64 -> V_66 . V_67 ;
}
static void F_40 ( struct V_3 * V_4 ,
struct V_23 * V_24 ,
struct V_68 * V_29 ,
union V_63 * V_64 , int V_36 )
{
struct V_33 * V_62 = & V_24 -> V_39 ;
struct V_69 * V_70 ;
memset ( V_62 , 0x0 , sizeof( * V_62 ) ) ;
V_62 -> V_71 = 1 ;
V_62 -> V_72 = V_29 ;
V_70 = (struct V_69 * ) V_29 [ 0 ] . V_30 ;
V_62 -> V_73 = V_29 [ 0 ] . V_30 ;
V_62 -> V_74 = V_64 -> V_66 . V_75 ;
V_62 -> V_76 = V_64 -> V_66 . V_77 ;
V_62 -> V_78 = V_4 -> V_79 ;
V_62 -> V_80 = V_4 -> V_18 ;
V_62 -> V_81 = 0 ;
V_4 -> V_82 . V_83 . V_84 = 0 ;
if ( V_64 -> V_66 . V_85 )
V_62 -> V_86 = V_64 -> V_66 . V_85 ;
else
V_62 -> V_86 = F_31 ( V_4 ,
V_64 -> V_66 . V_75 ) ;
V_62 -> V_87 = F_41 ( V_62 -> V_86 ) ;
V_62 -> V_88 = V_64 -> V_66 . V_89 ;
F_39 ( V_62 , V_64 ) ;
F_30 ( V_4 , V_36 ) ;
F_42 ( V_62 , V_70 ) ;
}
static void F_43 ( struct V_33 * V_34 )
{
F_44 ( & V_34 -> V_35 ,
V_46 + V_34 -> V_87 ) ;
V_34 -> V_81 = V_34 -> V_90 ;
}
static void V_47 ( unsigned long V_43 )
{
struct V_3 * V_4 = (struct V_3 * ) V_43 ;
struct V_33 * V_34 = & V_4 -> V_40 . V_39 ;
unsigned int V_91 ;
struct V_69 * V_70 ;
F_12 ( & V_4 -> V_2 . V_92 . V_41 ) ;
V_91 = F_45 ( V_34 ) ;
V_70 = F_46 ( V_34 ) ;
if ( F_35 ( V_34 -> V_42 ) )
goto V_93;
if ( F_47 ( V_70 ) ) {
while ( F_48 ( & V_34 -> V_94 ) ) {
F_49 () ;
}
}
if ( V_34 -> V_81 == V_34 -> V_90 ) {
if ( ! V_91 ) {
F_50 ( V_34 , V_4 , V_95 ) ;
if ( ! F_51 ( V_34 , V_4 ) )
goto V_96;
else
goto V_93;
} else {
if ( F_52 ( V_34 , V_70 ) ) {
goto V_96;
} else {
F_42 ( V_34 , V_70 ) ;
goto V_93;
}
}
}
V_96:
F_43 ( V_34 ) ;
V_93:
F_10 ( & V_4 -> V_2 . V_92 . V_41 ) ;
}
static void F_53 ( struct V_33 * V_97 ,
struct V_69 * V_98 , T_2 V_11 )
{
#if V_99 == 1
T_3 * V_100 , * V_101 ;
V_100 = ( T_3 * ) V_98 ;
V_100 += V_102 ;
V_101 = ( T_3 * ) F_54 ( ( unsigned long ) V_97 -> V_103 ) ;
for (; V_100 < V_101 ; V_100 += V_102 )
F_15 ( F_16 ( V_100 ) ) ;
F_19 () ;
#endif
F_55 ( V_98 ) = V_11 ;
#if V_99 == 1
V_100 = ( T_3 * ) V_98 ;
F_15 ( F_16 ( V_100 ) ) ;
F_19 () ;
#endif
}
static void F_56 ( struct V_33 * V_97 ,
struct V_69 * V_98 ,
struct V_3 * V_4 , unsigned int V_104 )
{
T_2 V_11 = V_105 | V_104 ;
struct V_106 * V_107 ;
struct V_108 * V_13 = & V_98 -> V_109 . V_110 ;
if ( V_4 -> V_111 . V_112 )
V_11 |= V_113 ;
V_107 = (struct V_106 * ) V_97 -> V_114 ;
V_107 -> V_115 = 0 ;
if ( F_47 ( V_98 ) ) {
V_13 -> V_116 . V_117 = V_107 -> V_118 ;
V_13 -> V_116 . V_119 = V_107 -> V_120 ;
} else {
struct V_121 V_122 ;
F_57 ( & V_122 ) ;
V_13 -> V_116 . V_117 = V_122 . V_123 ;
V_13 -> V_116 . V_119 = V_122 . V_124 ;
}
F_19 () ;
F_53 ( V_97 , V_98 , V_11 ) ;
V_97 -> V_90 = F_58 ( V_97 ) ;
}
static void F_59 ( struct V_33 * V_34 )
{
V_34 -> V_125 = 0 ;
}
static void F_42 ( struct V_33 * V_97 ,
struct V_69 * V_98 )
{
struct V_121 V_122 ;
struct V_108 * V_13 = & V_98 -> V_109 . V_110 ;
F_21 () ;
if ( F_60 ( V_126 == F_55 ( V_98 ) ) ) {
F_61 ( V_98 ) = V_97 -> V_71 ++ ;
F_47 ( V_98 ) = 0 ;
F_62 ( V_98 ) = F_63 ( V_97 -> V_88 ) ;
F_57 ( & V_122 ) ;
V_13 -> V_127 . V_117 = V_122 . V_123 ;
V_13 -> V_127 . V_119 = V_122 . V_124 ;
V_97 -> V_73 = ( char * ) V_98 ;
V_97 -> V_128 = V_97 -> V_73 + F_63 ( V_97 -> V_88 ) ;
F_64 ( V_98 ) = ( T_2 ) F_63 ( V_97 -> V_88 ) ;
F_65 ( V_98 ) = V_129 ;
V_98 -> V_80 = V_97 -> V_80 ;
V_97 -> V_114 = V_97 -> V_128 ;
V_97 -> V_103 = V_97 -> V_73 + V_97 -> V_74 ;
F_59 ( V_97 ) ;
F_43 ( V_97 ) ;
F_19 () ;
return;
}
F_17 ( 1 , L_2 ,
V_98 , F_55 ( V_98 ) , V_97 -> V_90 ) ;
F_66 () ;
F_18 () ;
}
static void F_67 ( struct V_33 * V_34 ,
struct V_3 * V_4 )
{
V_34 -> V_125 = 1 ;
V_4 -> V_82 . V_83 . V_84 ++ ;
}
static void * F_51 ( struct V_33 * V_34 ,
struct V_3 * V_4 )
{
struct V_69 * V_70 ;
F_21 () ;
V_70 = F_46 ( V_34 ) ;
if ( V_105 & F_55 ( V_70 ) ) {
F_67 ( V_34 , V_4 ) ;
return NULL ;
}
F_42 ( V_34 , V_70 ) ;
return ( void * ) V_34 -> V_128 ;
}
static void F_50 ( struct V_33 * V_34 ,
struct V_3 * V_4 , unsigned int V_11 )
{
struct V_69 * V_70 = F_46 ( V_34 ) ;
if ( F_60 ( V_126 == F_55 ( V_70 ) ) ) {
if ( ! ( V_11 & V_95 ) ) {
while ( F_48 ( & V_34 -> V_94 ) ) {
F_49 () ;
}
}
F_56 ( V_34 , V_70 , V_4 , V_11 ) ;
return;
}
F_17 ( 1 , L_3 , V_34 -> V_90 , V_70 ) ;
F_66 () ;
F_18 () ;
}
static int F_52 ( struct V_33 * V_34 ,
struct V_69 * V_70 )
{
return V_105 & F_55 ( V_70 ) ;
}
static int F_45 ( struct V_33 * V_34 )
{
return V_34 -> V_125 ;
}
static void F_68 ( struct V_23 * V_24 )
{
struct V_33 * V_34 = F_69 ( V_24 ) ;
F_70 ( & V_34 -> V_94 ) ;
}
static void F_71 ( struct V_33 * V_34 ,
struct V_106 * V_130 )
{
V_130 -> V_131 . V_132 = F_72 ( V_34 -> V_133 ) ;
}
static void F_73 ( struct V_33 * V_34 ,
struct V_106 * V_130 )
{
V_130 -> V_131 . V_132 = 0 ;
}
static void F_74 ( struct V_33 * V_34 ,
struct V_106 * V_130 )
{
if ( F_75 ( V_34 -> V_133 ) ) {
V_130 -> V_131 . V_134 = F_76 ( V_34 -> V_133 ) ;
V_130 -> V_20 = V_135 ;
} else {
V_130 -> V_131 . V_134 = 0 ;
V_130 -> V_20 = V_136 ;
}
}
static void F_77 ( struct V_33 * V_34 ,
struct V_106 * V_130 )
{
F_74 ( V_34 , V_130 ) ;
if ( V_34 -> V_65 & V_137 )
F_71 ( V_34 , V_130 ) ;
else
F_73 ( V_34 , V_130 ) ;
}
static void F_78 ( char * V_138 ,
struct V_33 * V_34 ,
struct V_69 * V_70 ,
unsigned int V_139 )
{
struct V_106 * V_130 ;
V_130 = (struct V_106 * ) V_138 ;
V_130 -> V_115 = F_79 ( V_139 ) ;
V_34 -> V_114 = V_138 ;
V_34 -> V_128 += F_79 ( V_139 ) ;
F_62 ( V_70 ) += F_79 ( V_139 ) ;
F_47 ( V_70 ) += 1 ;
F_80 ( & V_34 -> V_94 ) ;
F_77 ( V_34 , V_130 ) ;
}
static void * F_81 ( struct V_3 * V_4 ,
struct V_140 * V_133 ,
int V_11 ,
unsigned int V_139
)
{
struct V_33 * V_34 ;
struct V_69 * V_70 ;
char * V_138 , * V_101 ;
V_34 = F_69 ( & V_4 -> V_40 ) ;
V_70 = F_46 ( V_34 ) ;
if ( F_45 ( V_34 ) ) {
if ( F_52 ( V_34 , V_70 ) ) {
return NULL ;
} else {
F_42 ( V_34 , V_70 ) ;
}
}
F_82 () ;
V_138 = V_34 -> V_128 ;
V_34 -> V_133 = V_133 ;
V_101 = ( char * ) V_70 + V_34 -> V_74 ;
if ( V_138 + F_79 ( V_139 ) < V_101 ) {
F_78 ( V_138 , V_34 , V_70 , V_139 ) ;
return ( void * ) V_138 ;
}
F_50 ( V_34 , V_4 , 0 ) ;
V_138 = ( char * ) F_51 ( V_34 , V_4 ) ;
if ( V_138 ) {
V_70 = F_46 ( V_34 ) ;
F_78 ( V_138 , V_34 , V_70 , V_139 ) ;
return ( void * ) V_138 ;
}
return NULL ;
}
static void * F_83 ( struct V_3 * V_4 ,
struct V_140 * V_133 ,
int V_11 , unsigned int V_139 )
{
char * V_138 = NULL ;
switch ( V_4 -> V_18 ) {
case V_19 :
case V_21 :
V_138 = F_22 ( V_4 , & V_4 -> V_40 ,
V_4 -> V_40 . V_32 , V_11 ) ;
return V_138 ;
case V_22 :
return F_81 ( V_4 , V_133 , V_11 , V_139 ) ;
default:
F_17 ( 1 , L_4 ) ;
F_18 () ;
return NULL ;
}
}
static void * F_84 ( struct V_3 * V_4 ,
struct V_23 * V_24 ,
unsigned int V_141 ,
int V_11 )
{
struct V_33 * V_34 = F_69 ( V_24 ) ;
struct V_69 * V_70 = F_85 ( V_34 , V_141 ) ;
if ( V_11 != F_55 ( V_70 ) )
return NULL ;
return V_70 ;
}
static int F_86 ( struct V_23 * V_24 )
{
unsigned int V_114 ;
if ( V_24 -> V_39 . V_90 )
V_114 = V_24 -> V_39 . V_90 - 1 ;
else
V_114 = V_24 -> V_39 . V_76 - 1 ;
return V_114 ;
}
static void * F_87 ( struct V_3 * V_4 ,
struct V_23 * V_24 ,
int V_11 )
{
unsigned int V_141 = F_86 ( V_24 ) ;
return F_84 ( V_4 , V_24 , V_141 , V_11 ) ;
}
static void * F_88 ( struct V_3 * V_4 ,
struct V_23 * V_24 ,
int V_11 )
{
if ( V_4 -> V_18 <= V_21 )
return F_89 ( V_4 , V_24 , V_11 ) ;
return F_87 ( V_4 , V_24 , V_11 ) ;
}
static void F_90 ( struct V_3 * V_4 ,
struct V_23 * V_24 )
{
switch ( V_4 -> V_18 ) {
case V_19 :
case V_21 :
return F_91 ( V_24 ) ;
case V_22 :
default:
F_17 ( 1 , L_1 ) ;
F_18 () ;
return;
}
}
static void * F_89 ( struct V_3 * V_4 ,
struct V_23 * V_24 ,
int V_11 )
{
unsigned int V_141 = V_24 -> V_32 ? V_24 -> V_32 - 1 : V_24 -> V_142 ;
return F_22 ( V_4 , V_24 , V_141 , V_11 ) ;
}
static void F_91 ( struct V_23 * V_143 )
{
V_143 -> V_32 = V_143 -> V_32 != V_143 -> V_142 ? V_143 -> V_32 + 1 : 0 ;
}
static void F_92 ( struct V_1 * V_2 )
{
F_93 ( & V_2 -> V_144 ) ;
F_94 ( F_48 ( & V_2 -> V_145 ) ) ;
F_94 ( F_48 ( & V_2 -> V_146 ) ) ;
if ( ! F_95 ( V_2 , V_147 ) ) {
F_96 ( L_5 , V_2 ) ;
return;
}
F_97 ( V_2 ) ;
}
static int F_98 ( struct V_148 * V_149 , unsigned int V_150 )
{
int V_151 = F_48 ( & V_149 -> V_152 ) + 1 ;
if ( V_151 >= V_150 )
V_151 = 0 ;
return V_151 ;
}
static struct V_1 * F_99 ( struct V_148 * V_149 , struct V_140 * V_133 , unsigned int V_150 )
{
T_1 V_153 , V_154 = V_133 -> V_155 ;
V_153 = ( ( V_156 ) V_154 * V_150 ) >> 32 ;
return V_149 -> V_157 [ V_153 ] ;
}
static struct V_1 * F_100 ( struct V_148 * V_149 , struct V_140 * V_133 , unsigned int V_150 )
{
int V_158 , V_159 ;
V_158 = F_48 ( & V_149 -> V_152 ) ;
while ( ( V_159 = F_101 ( & V_149 -> V_152 , V_158 ,
F_98 ( V_149 , V_150 ) ) ) != V_158 )
V_158 = V_159 ;
return V_149 -> V_157 [ V_158 ] ;
}
static struct V_1 * F_102 ( struct V_148 * V_149 , struct V_140 * V_133 , unsigned int V_150 )
{
unsigned int V_160 = F_103 () ;
return V_149 -> V_157 [ V_160 % V_150 ] ;
}
static int F_104 ( struct V_140 * V_133 , struct V_49 * V_50 ,
struct V_161 * V_162 , struct V_49 * V_163 )
{
struct V_148 * V_149 = V_162 -> V_164 ;
unsigned int V_150 = V_149 -> V_165 ;
struct V_3 * V_4 ;
struct V_1 * V_2 ;
if ( ! F_105 ( F_106 ( V_50 ) , F_107 ( & V_149 -> V_166 ) ) ||
! V_150 ) {
F_108 ( V_133 ) ;
return 0 ;
}
switch ( V_149 -> type ) {
case V_167 :
default:
if ( V_149 -> V_168 ) {
V_133 = F_109 ( V_133 , V_169 ) ;
if ( ! V_133 )
return 0 ;
}
F_72 ( V_133 ) ;
V_2 = F_99 ( V_149 , V_133 , V_150 ) ;
break;
case V_170 :
V_2 = F_100 ( V_149 , V_133 , V_150 ) ;
break;
case V_171 :
V_2 = F_102 ( V_149 , V_133 , V_150 ) ;
break;
}
V_4 = F_2 ( V_2 ) ;
return V_4 -> V_7 . F_28 ( V_133 , V_50 , & V_4 -> V_7 , V_163 ) ;
}
static void F_3 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_148 * V_149 = V_4 -> V_6 ;
F_12 ( & V_149 -> V_41 ) ;
V_149 -> V_157 [ V_149 -> V_165 ] = V_2 ;
F_19 () ;
V_149 -> V_165 ++ ;
F_10 ( & V_149 -> V_41 ) ;
}
static void F_7 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_148 * V_149 = V_4 -> V_6 ;
int V_172 ;
F_12 ( & V_149 -> V_41 ) ;
for ( V_172 = 0 ; V_172 < V_149 -> V_165 ; V_172 ++ ) {
if ( V_149 -> V_157 [ V_172 ] == V_2 )
break;
}
F_110 ( V_172 >= V_149 -> V_165 ) ;
V_149 -> V_157 [ V_172 ] = V_149 -> V_157 [ V_149 -> V_165 - 1 ] ;
V_149 -> V_165 -- ;
F_10 ( & V_149 -> V_41 ) ;
}
static bool F_111 ( struct V_161 * V_173 , struct V_1 * V_2 )
{
if ( V_173 -> V_164 == ( void * ) ( (struct V_3 * ) V_2 ) -> V_6 )
return true ;
return false ;
}
static int F_112 ( struct V_1 * V_2 , T_4 V_174 , T_4 V_175 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_148 * V_149 , * V_176 ;
T_3 type = V_175 & 0xff ;
T_3 V_168 = ( V_175 & V_177 ) ? 1 : 0 ;
int V_56 ;
switch ( type ) {
case V_167 :
case V_170 :
case V_171 :
break;
default:
return - V_178 ;
}
if ( ! V_4 -> V_5 )
return - V_178 ;
if ( V_4 -> V_6 )
return - V_179 ;
F_113 ( & V_180 ) ;
V_176 = NULL ;
F_114 (f, &fanout_list, list) {
if ( V_149 -> V_174 == V_174 &&
F_107 ( & V_149 -> V_166 ) == F_34 ( V_2 ) ) {
V_176 = V_149 ;
break;
}
}
V_56 = - V_178 ;
if ( V_176 && V_176 -> V_168 != V_168 )
goto V_93;
if ( ! V_176 ) {
V_56 = - V_181 ;
V_176 = F_115 ( sizeof( * V_176 ) , V_182 ) ;
if ( ! V_176 )
goto V_93;
F_116 ( & V_176 -> V_166 , F_34 ( V_2 ) ) ;
V_176 -> V_174 = V_174 ;
V_176 -> type = type ;
V_176 -> V_168 = V_168 ;
F_117 ( & V_176 -> V_152 , 0 ) ;
F_118 ( & V_176 -> V_183 ) ;
F_119 ( & V_176 -> V_41 ) ;
F_117 ( & V_176 -> V_184 , 0 ) ;
V_176 -> V_7 . type = V_4 -> V_7 . type ;
V_176 -> V_7 . V_50 = V_4 -> V_7 . V_50 ;
V_176 -> V_7 . F_28 = F_104 ;
V_176 -> V_7 . V_164 = V_176 ;
V_176 -> V_7 . V_185 = F_111 ;
F_4 ( & V_176 -> V_7 ) ;
F_120 ( & V_176 -> V_183 , & V_186 ) ;
}
V_56 = - V_178 ;
if ( V_176 -> type == type &&
V_176 -> V_7 . type == V_4 -> V_7 . type &&
V_176 -> V_7 . V_50 == V_4 -> V_7 . V_50 ) {
V_56 = - V_187 ;
if ( F_48 ( & V_176 -> V_184 ) < V_188 ) {
F_8 ( & V_4 -> V_7 ) ;
V_4 -> V_6 = V_176 ;
F_80 ( & V_176 -> V_184 ) ;
F_3 ( V_2 , V_4 ) ;
V_56 = 0 ;
}
}
V_93:
F_121 ( & V_180 ) ;
return V_56 ;
}
static void F_122 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_148 * V_149 ;
V_149 = V_4 -> V_6 ;
if ( ! V_149 )
return;
F_113 ( & V_180 ) ;
V_4 -> V_6 = NULL ;
if ( F_123 ( & V_149 -> V_184 ) ) {
F_124 ( & V_149 -> V_183 ) ;
F_125 ( & V_149 -> V_7 ) ;
F_126 ( V_149 ) ;
}
F_121 ( & V_180 ) ;
}
static int F_127 ( struct V_140 * V_133 , struct V_49 * V_50 ,
struct V_161 * V_162 , struct V_49 * V_163 )
{
struct V_1 * V_2 ;
struct V_189 * V_190 ;
V_2 = V_162 -> V_164 ;
if ( V_133 -> V_191 == V_192 )
goto V_93;
if ( ! F_105 ( F_106 ( V_50 ) , F_34 ( V_2 ) ) )
goto V_93;
V_133 = F_128 ( V_133 , V_193 ) ;
if ( V_133 == NULL )
goto V_194;
F_129 ( V_133 ) ;
F_130 ( V_133 ) ;
V_190 = & F_131 ( V_133 ) -> V_195 . V_196 ;
F_132 ( V_133 , V_133 -> V_43 - F_133 ( V_133 ) ) ;
V_190 -> V_197 = V_50 -> type ;
F_134 ( V_190 -> V_198 , V_50 -> V_199 , sizeof( V_190 -> V_198 ) ) ;
V_190 -> V_200 = V_133 -> V_201 ;
if ( F_135 ( V_2 , V_133 ) == 0 )
return 0 ;
V_93:
F_108 ( V_133 ) ;
V_194:
return 0 ;
}
static int F_136 ( struct V_202 * V_203 , struct V_204 * V_1 ,
struct V_205 * V_206 , T_5 V_139 )
{
struct V_1 * V_2 = V_1 -> V_2 ;
struct V_189 * V_207 = (struct V_189 * ) V_206 -> V_208 ;
struct V_140 * V_133 = NULL ;
struct V_49 * V_50 ;
T_6 V_209 = 0 ;
int V_56 ;
int V_210 = 0 ;
if ( V_207 ) {
if ( V_206 -> V_211 < sizeof( struct V_212 ) )
return - V_178 ;
if ( V_206 -> V_211 == sizeof( struct V_189 ) )
V_209 = V_207 -> V_200 ;
} else
return - V_213 ;
V_207 -> V_198 [ sizeof( V_207 -> V_198 ) - 1 ] = 0 ;
V_214:
F_137 () ;
V_50 = F_138 ( F_34 ( V_2 ) , V_207 -> V_198 ) ;
V_56 = - V_215 ;
if ( V_50 == NULL )
goto V_216;
V_56 = - V_217 ;
if ( ! ( V_50 -> V_218 & V_219 ) )
goto V_216;
if ( F_35 ( F_95 ( V_2 , V_220 ) ) ) {
if ( ! F_139 ( V_50 ) ) {
V_56 = - V_221 ;
goto V_216;
}
V_210 = 4 ;
}
V_56 = - V_222 ;
if ( V_139 > V_50 -> V_223 + V_50 -> V_224 + V_225 + V_210 )
goto V_216;
if ( ! V_133 ) {
T_5 V_226 = F_140 ( V_50 ) ;
int V_227 = V_50 -> V_228 ;
unsigned int V_229 = V_50 -> V_230 ? V_50 -> V_224 : 0 ;
F_141 () ;
V_133 = F_142 ( V_2 , V_139 + V_226 + V_227 , 0 , V_182 ) ;
if ( V_133 == NULL )
return - V_231 ;
F_143 ( V_133 , V_226 ) ;
F_144 ( V_133 ) ;
if ( V_229 ) {
V_133 -> V_43 -= V_229 ;
V_133 -> V_232 -= V_229 ;
if ( V_139 < V_229 )
F_144 ( V_133 ) ;
}
V_56 = F_145 ( F_146 ( V_133 , V_139 ) , V_206 -> V_233 , V_139 ) ;
if ( V_56 )
goto V_234;
goto V_214;
}
if ( V_139 > ( V_50 -> V_223 + V_50 -> V_224 + V_210 ) ) {
struct V_235 * V_236 ;
F_147 ( V_133 ) ;
V_236 = F_148 ( V_133 ) ;
if ( V_236 -> V_237 != F_149 ( V_238 ) ) {
V_56 = - V_222 ;
goto V_216;
}
}
V_133 -> V_201 = V_209 ;
V_133 -> V_50 = V_50 ;
V_133 -> V_239 = V_2 -> V_240 ;
V_133 -> V_241 = V_2 -> V_242 ;
V_56 = F_150 ( V_2 , & F_151 ( V_133 ) -> V_243 ) ;
if ( V_56 < 0 )
goto V_216;
if ( F_35 ( V_210 == 4 ) )
V_133 -> V_244 = 1 ;
F_152 ( V_133 ) ;
F_141 () ;
return V_139 ;
V_216:
F_141 () ;
V_234:
F_108 ( V_133 ) ;
return V_56 ;
}
static unsigned int F_153 ( const struct V_140 * V_133 ,
const struct V_1 * V_2 ,
unsigned int V_245 )
{
struct V_246 * V_247 ;
F_137 () ;
V_247 = F_154 ( V_2 -> V_246 ) ;
if ( V_247 != NULL )
V_245 = F_155 ( V_247 , V_133 ) ;
F_141 () ;
return V_245 ;
}
static int F_156 ( struct V_140 * V_133 , struct V_49 * V_50 ,
struct V_161 * V_162 , struct V_49 * V_163 )
{
struct V_1 * V_2 ;
struct V_248 * V_249 ;
struct V_3 * V_4 ;
T_3 * V_250 = V_133 -> V_43 ;
int V_251 = V_133 -> V_139 ;
unsigned int V_252 , V_245 ;
if ( V_133 -> V_191 == V_192 )
goto V_253;
V_2 = V_162 -> V_164 ;
V_4 = F_2 ( V_2 ) ;
if ( ! F_105 ( F_106 ( V_50 ) , F_34 ( V_2 ) ) )
goto V_253;
V_133 -> V_50 = V_50 ;
if ( V_50 -> V_230 ) {
if ( V_2 -> V_254 != V_255 )
F_132 ( V_133 , V_133 -> V_43 - F_133 ( V_133 ) ) ;
else if ( V_133 -> V_191 == V_256 ) {
F_157 ( V_133 , F_158 ( V_133 ) ) ;
}
}
V_252 = V_133 -> V_139 ;
V_245 = F_153 ( V_133 , V_2 , V_252 ) ;
if ( ! V_245 )
goto V_257;
if ( V_252 > V_245 )
V_252 = V_245 ;
if ( F_48 ( & V_2 -> V_145 ) >= V_2 -> V_258 )
goto V_259;
if ( F_159 ( V_133 ) ) {
struct V_140 * V_260 = F_160 ( V_133 , V_193 ) ;
if ( V_260 == NULL )
goto V_259;
if ( V_250 != V_133 -> V_43 ) {
V_133 -> V_43 = V_250 ;
V_133 -> V_139 = V_251 ;
}
F_161 ( V_133 ) ;
V_133 = V_260 ;
}
F_162 ( sizeof( * F_131 ( V_133 ) ) + V_261 - 8 >
sizeof( V_133 -> V_262 ) ) ;
V_249 = & F_131 ( V_133 ) -> V_195 . V_263 ;
V_249 -> V_264 = V_265 ;
V_249 -> V_266 = V_50 -> type ;
V_249 -> V_267 = V_133 -> V_201 ;
V_249 -> V_268 = V_133 -> V_191 ;
if ( F_35 ( V_4 -> V_269 ) )
V_249 -> V_270 = V_163 -> V_58 ;
else
V_249 -> V_270 = V_50 -> V_58 ;
V_249 -> V_271 = F_163 ( V_133 , V_249 -> V_272 ) ;
F_131 ( V_133 ) -> V_273 = V_133 -> V_139 ;
if ( F_164 ( V_133 , V_252 ) )
goto V_259;
F_165 ( V_133 , V_2 ) ;
V_133 -> V_50 = NULL ;
F_129 ( V_133 ) ;
F_130 ( V_133 ) ;
F_12 ( & V_2 -> V_92 . V_41 ) ;
V_4 -> V_111 . V_274 ++ ;
V_133 -> V_275 = F_48 ( & V_2 -> V_276 ) ;
F_166 ( & V_2 -> V_92 , V_133 ) ;
F_10 ( & V_2 -> V_92 . V_41 ) ;
V_2 -> V_277 ( V_2 , V_133 -> V_139 ) ;
return 0 ;
V_259:
F_12 ( & V_2 -> V_92 . V_41 ) ;
V_4 -> V_111 . V_112 ++ ;
F_80 ( & V_2 -> V_276 ) ;
F_10 ( & V_2 -> V_92 . V_41 ) ;
V_257:
if ( V_250 != V_133 -> V_43 && F_159 ( V_133 ) ) {
V_133 -> V_43 = V_250 ;
V_133 -> V_139 = V_251 ;
}
V_253:
F_161 ( V_133 ) ;
return 0 ;
}
static int F_167 ( struct V_140 * V_133 , struct V_49 * V_50 ,
struct V_161 * V_162 , struct V_49 * V_163 )
{
struct V_1 * V_2 ;
struct V_3 * V_4 ;
struct V_248 * V_249 ;
union {
struct V_12 * V_13 ;
struct V_14 * V_15 ;
struct V_106 * V_278 ;
void * V_16 ;
} V_17 ;
T_3 * V_250 = V_133 -> V_43 ;
int V_251 = V_133 -> V_139 ;
unsigned int V_252 , V_245 ;
unsigned long V_11 = V_105 ;
unsigned short V_279 , V_280 , V_78 ;
struct V_140 * V_281 = NULL ;
struct V_282 V_283 ;
struct V_121 V_122 ;
struct V_284 * V_285 = F_168 ( V_133 ) ;
if ( V_133 -> V_191 == V_192 )
goto V_253;
V_2 = V_162 -> V_164 ;
V_4 = F_2 ( V_2 ) ;
if ( ! F_105 ( F_106 ( V_50 ) , F_34 ( V_2 ) ) )
goto V_253;
if ( V_50 -> V_230 ) {
if ( V_2 -> V_254 != V_255 )
F_132 ( V_133 , V_133 -> V_43 - F_133 ( V_133 ) ) ;
else if ( V_133 -> V_191 == V_256 ) {
F_157 ( V_133 , F_158 ( V_133 ) ) ;
}
}
if ( V_133 -> V_286 == V_287 )
V_11 |= V_288 ;
V_252 = V_133 -> V_139 ;
V_245 = F_153 ( V_133 , V_2 , V_252 ) ;
if ( ! V_245 )
goto V_257;
if ( V_252 > V_245 )
V_252 = V_245 ;
if ( V_2 -> V_254 == V_255 ) {
V_279 = V_280 = F_169 ( V_4 -> V_79 ) + 16 +
V_4 -> V_289 ;
} else {
unsigned int V_290 = F_158 ( V_133 ) ;
V_280 = F_169 ( V_4 -> V_79 +
( V_290 < 16 ? 16 : V_290 ) ) +
V_4 -> V_289 ;
V_279 = V_280 - V_290 ;
}
if ( V_4 -> V_18 <= V_21 ) {
if ( V_279 + V_252 > V_4 -> V_40 . V_31 ) {
if ( V_4 -> V_291 &&
F_48 ( & V_2 -> V_145 ) < V_2 -> V_258 ) {
if ( F_159 ( V_133 ) ) {
V_281 = F_160 ( V_133 , V_193 ) ;
} else {
V_281 = F_170 ( V_133 ) ;
V_250 = V_133 -> V_43 ;
}
if ( V_281 )
F_165 ( V_281 , V_2 ) ;
}
V_252 = V_4 -> V_40 . V_31 - V_279 ;
if ( ( int ) V_252 < 0 )
V_252 = 0 ;
}
}
F_12 ( & V_2 -> V_92 . V_41 ) ;
V_17 . V_16 = F_83 ( V_4 , V_133 ,
V_126 , ( V_279 + V_252 ) ) ;
if ( ! V_17 . V_16 )
goto V_292;
if ( V_4 -> V_18 <= V_21 ) {
F_90 ( V_4 , & V_4 -> V_40 ) ;
if ( V_4 -> V_111 . V_112 )
V_11 |= V_113 ;
}
V_4 -> V_111 . V_274 ++ ;
if ( V_281 ) {
V_11 |= V_293 ;
F_166 ( & V_2 -> V_92 , V_281 ) ;
}
F_10 ( & V_2 -> V_92 . V_41 ) ;
F_171 ( V_133 , 0 , V_17 . V_16 + V_279 , V_252 ) ;
switch ( V_4 -> V_18 ) {
case V_19 :
V_17 . V_13 -> V_294 = V_133 -> V_139 ;
V_17 . V_13 -> V_295 = V_252 ;
V_17 . V_13 -> V_296 = V_279 ;
V_17 . V_13 -> V_297 = V_280 ;
if ( ( V_4 -> V_298 & V_299 )
&& V_285 -> V_300 . V_301 )
V_283 = F_172 ( V_285 -> V_300 ) ;
else if ( ( V_4 -> V_298 & V_302 )
&& V_285 -> V_303 . V_301 )
V_283 = F_172 ( V_285 -> V_303 ) ;
else if ( V_133 -> V_304 . V_301 )
V_283 = F_172 ( V_133 -> V_304 ) ;
else
F_173 ( & V_283 ) ;
V_17 . V_13 -> V_118 = V_283 . V_123 ;
V_17 . V_13 -> V_305 = V_283 . V_306 ;
V_78 = sizeof( * V_17 . V_13 ) ;
break;
case V_21 :
V_17 . V_15 -> V_294 = V_133 -> V_139 ;
V_17 . V_15 -> V_295 = V_252 ;
V_17 . V_15 -> V_296 = V_279 ;
V_17 . V_15 -> V_297 = V_280 ;
if ( ( V_4 -> V_298 & V_299 )
&& V_285 -> V_300 . V_301 )
V_122 = F_174 ( V_285 -> V_300 ) ;
else if ( ( V_4 -> V_298 & V_302 )
&& V_285 -> V_303 . V_301 )
V_122 = F_174 ( V_285 -> V_303 ) ;
else if ( V_133 -> V_304 . V_301 )
V_122 = F_174 ( V_133 -> V_304 ) ;
else
F_57 ( & V_122 ) ;
V_17 . V_15 -> V_118 = V_122 . V_123 ;
V_17 . V_15 -> V_120 = V_122 . V_124 ;
if ( F_75 ( V_133 ) ) {
V_17 . V_15 -> V_134 = F_76 ( V_133 ) ;
V_11 |= V_135 ;
} else {
V_17 . V_15 -> V_134 = 0 ;
}
V_17 . V_15 -> V_307 = 0 ;
V_78 = sizeof( * V_17 . V_15 ) ;
break;
case V_22 :
V_17 . V_278 -> V_20 |= V_11 ;
V_17 . V_278 -> V_294 = V_133 -> V_139 ;
V_17 . V_278 -> V_295 = V_252 ;
V_17 . V_278 -> V_296 = V_279 ;
V_17 . V_278 -> V_297 = V_280 ;
if ( ( V_4 -> V_298 & V_299 )
&& V_285 -> V_300 . V_301 )
V_122 = F_174 ( V_285 -> V_300 ) ;
else if ( ( V_4 -> V_298 & V_302 )
&& V_285 -> V_303 . V_301 )
V_122 = F_174 ( V_285 -> V_303 ) ;
else if ( V_133 -> V_304 . V_301 )
V_122 = F_174 ( V_133 -> V_304 ) ;
else
F_57 ( & V_122 ) ;
V_17 . V_278 -> V_118 = V_122 . V_123 ;
V_17 . V_278 -> V_120 = V_122 . V_124 ;
V_78 = sizeof( * V_17 . V_278 ) ;
break;
default:
F_18 () ;
}
V_249 = V_17 . V_16 + F_169 ( V_78 ) ;
V_249 -> V_271 = F_163 ( V_133 , V_249 -> V_272 ) ;
V_249 -> V_264 = V_265 ;
V_249 -> V_266 = V_50 -> type ;
V_249 -> V_267 = V_133 -> V_201 ;
V_249 -> V_268 = V_133 -> V_191 ;
if ( F_35 ( V_4 -> V_269 ) )
V_249 -> V_270 = V_163 -> V_58 ;
else
V_249 -> V_270 = V_50 -> V_58 ;
F_82 () ;
#if V_99 == 1
{
T_3 * V_100 , * V_101 ;
if ( V_4 -> V_18 <= V_21 ) {
V_101 = ( T_3 * ) F_54 ( ( unsigned long ) V_17 . V_16
+ V_279 + V_252 ) ;
for ( V_100 = V_17 . V_16 ; V_100 < V_101 ; V_100 += V_102 )
F_15 ( F_16 ( V_100 ) ) ;
}
F_19 () ;
}
#endif
if ( V_4 -> V_18 <= V_21 )
F_14 ( V_4 , V_17 . V_16 , V_11 ) ;
else
F_68 ( & V_4 -> V_40 ) ;
V_2 -> V_277 ( V_2 , 0 ) ;
V_257:
if ( V_250 != V_133 -> V_43 && F_159 ( V_133 ) ) {
V_133 -> V_43 = V_250 ;
V_133 -> V_139 = V_251 ;
}
V_253:
F_108 ( V_133 ) ;
return 0 ;
V_292:
V_4 -> V_111 . V_112 ++ ;
F_10 ( & V_2 -> V_92 . V_41 ) ;
V_2 -> V_277 ( V_2 , 0 ) ;
F_108 ( V_281 ) ;
goto V_257;
}
static void F_175 ( struct V_140 * V_133 )
{
struct V_3 * V_4 = F_2 ( V_133 -> V_2 ) ;
void * V_308 ;
if ( F_60 ( V_4 -> V_36 . V_29 ) ) {
V_308 = F_151 ( V_133 ) -> V_309 ;
F_110 ( F_48 ( & V_4 -> V_36 . V_310 ) == 0 ) ;
F_70 ( & V_4 -> V_36 . V_310 ) ;
F_14 ( V_4 , V_308 , V_136 ) ;
}
F_176 ( V_133 ) ;
}
static int F_177 ( struct V_3 * V_4 , struct V_140 * V_133 ,
void * V_10 , struct V_49 * V_50 , int V_311 ,
T_6 V_209 , unsigned char * V_312 , int V_313 )
{
union {
struct V_12 * V_13 ;
struct V_14 * V_15 ;
void * V_16 ;
} V_308 ;
int V_314 , V_315 , V_139 , V_294 , V_316 , V_317 ;
struct V_204 * V_1 = V_4 -> V_2 . V_318 ;
struct V_319 * V_319 ;
void * V_43 ;
int V_56 ;
V_308 . V_16 = V_10 ;
V_133 -> V_201 = V_209 ;
V_133 -> V_50 = V_50 ;
V_133 -> V_239 = V_4 -> V_2 . V_240 ;
V_133 -> V_241 = V_4 -> V_2 . V_242 ;
F_151 ( V_133 ) -> V_309 = V_308 . V_16 ;
switch ( V_4 -> V_18 ) {
case V_21 :
V_294 = V_308 . V_15 -> V_294 ;
break;
default:
V_294 = V_308 . V_13 -> V_294 ;
break;
}
if ( F_35 ( V_294 > V_311 ) ) {
F_96 ( L_6 , V_294 , V_311 ) ;
return - V_222 ;
}
F_143 ( V_133 , V_313 ) ;
F_144 ( V_133 ) ;
V_43 = V_308 . V_16 + V_4 -> V_79 - sizeof( struct V_248 ) ;
V_314 = V_294 ;
if ( V_1 -> type == V_255 ) {
V_56 = F_178 ( V_133 , V_50 , F_179 ( V_209 ) , V_312 ,
NULL , V_294 ) ;
if ( F_35 ( V_56 < 0 ) )
return - V_178 ;
} else if ( V_50 -> V_224 ) {
if ( F_35 ( V_294 <= V_50 -> V_224 ) ) {
F_96 ( L_7 ,
V_294 , V_50 -> V_224 ) ;
return - V_178 ;
}
F_132 ( V_133 , V_50 -> V_224 ) ;
V_56 = F_180 ( V_133 , 0 , V_43 ,
V_50 -> V_224 ) ;
if ( F_35 ( V_56 ) )
return V_56 ;
V_43 += V_50 -> V_224 ;
V_314 -= V_50 -> V_224 ;
}
V_56 = - V_320 ;
V_315 = F_181 ( V_43 ) ;
V_317 = V_102 - V_315 ;
V_139 = ( ( V_314 > V_317 ) ? V_317 : V_314 ) ;
V_133 -> V_321 = V_314 ;
V_133 -> V_139 += V_314 ;
V_133 -> V_322 += V_314 ;
F_182 ( V_314 , & V_4 -> V_2 . V_146 ) ;
while ( F_60 ( V_314 ) ) {
V_316 = F_151 ( V_133 ) -> V_316 ;
if ( F_35 ( V_316 >= V_323 ) ) {
F_96 ( L_8 ,
V_323 ) ;
return - V_320 ;
}
V_319 = F_16 ( V_43 ) ;
V_43 += V_139 ;
F_15 ( V_319 ) ;
F_183 ( V_319 ) ;
F_184 ( V_133 , V_316 , V_319 , V_315 , V_139 ) ;
V_314 -= V_139 ;
V_315 = 0 ;
V_317 = V_102 ;
V_139 = ( ( V_314 > V_317 ) ? V_317 : V_314 ) ;
}
return V_294 ;
}
static int F_185 ( struct V_3 * V_4 , struct V_205 * V_206 )
{
struct V_140 * V_133 ;
struct V_49 * V_50 ;
T_6 V_209 ;
bool V_324 = false ;
int V_56 , V_325 = 0 ;
void * V_308 ;
struct V_248 * V_207 = (struct V_248 * ) V_206 -> V_208 ;
int V_294 , V_311 ;
unsigned char * V_312 ;
int V_326 = 0 ;
int V_11 = V_136 ;
int V_313 , V_227 ;
F_113 ( & V_4 -> V_327 ) ;
V_56 = - V_328 ;
if ( V_207 == NULL ) {
V_50 = V_4 -> V_7 . V_50 ;
V_209 = V_4 -> V_150 ;
V_312 = NULL ;
} else {
V_56 = - V_178 ;
if ( V_206 -> V_211 < sizeof( struct V_248 ) )
goto V_93;
if ( V_206 -> V_211 < ( V_207 -> V_271
+ F_186 ( struct V_248 ,
V_272 ) ) )
goto V_93;
V_209 = V_207 -> V_267 ;
V_312 = V_207 -> V_272 ;
V_50 = F_187 ( F_34 ( & V_4 -> V_2 ) , V_207 -> V_270 ) ;
V_324 = true ;
}
V_56 = - V_329 ;
if ( F_35 ( V_50 == NULL ) )
goto V_93;
V_325 = V_50 -> V_224 ;
V_56 = - V_217 ;
if ( F_35 ( ! ( V_50 -> V_218 & V_219 ) ) )
goto V_330;
V_311 = V_4 -> V_36 . V_31
- ( V_4 -> V_79 - sizeof( struct V_248 ) ) ;
if ( V_311 > V_50 -> V_223 + V_325 )
V_311 = V_50 -> V_223 + V_325 ;
do {
V_308 = F_23 ( V_4 , & V_4 -> V_36 ,
V_331 ) ;
if ( F_35 ( V_308 == NULL ) ) {
F_188 () ;
continue;
}
V_11 = V_331 ;
V_313 = F_140 ( V_50 ) ;
V_227 = V_50 -> V_228 ;
V_133 = F_189 ( & V_4 -> V_2 ,
V_313 + V_227 + sizeof( struct V_248 ) ,
0 , & V_56 ) ;
if ( F_35 ( V_133 == NULL ) )
goto V_332;
V_294 = F_177 ( V_4 , V_133 , V_308 , V_50 , V_311 , V_209 ,
V_312 , V_313 ) ;
if ( F_35 ( V_294 < 0 ) ) {
if ( V_4 -> V_333 ) {
F_14 ( V_4 , V_308 ,
V_136 ) ;
F_91 ( & V_4 -> V_36 ) ;
F_108 ( V_133 ) ;
continue;
} else {
V_11 = V_334 ;
V_56 = V_294 ;
goto V_332;
}
}
V_133 -> V_335 = F_175 ;
F_14 ( V_4 , V_308 , V_336 ) ;
F_80 ( & V_4 -> V_36 . V_310 ) ;
V_11 = V_331 ;
V_56 = F_152 ( V_133 ) ;
if ( F_35 ( V_56 > 0 ) ) {
V_56 = F_190 ( V_56 ) ;
if ( V_56 && F_20 ( V_4 , V_308 ) ==
V_136 ) {
V_133 = NULL ;
goto V_332;
}
V_56 = 0 ;
}
F_91 ( & V_4 -> V_36 ) ;
V_326 += V_294 ;
} while ( F_60 ( ( V_308 != NULL ) ||
( ( ! ( V_206 -> V_337 & V_338 ) ) &&
( F_48 ( & V_4 -> V_36 . V_310 ) ) ) )
);
V_56 = V_326 ;
goto V_330;
V_332:
F_14 ( V_4 , V_308 , V_11 ) ;
F_108 ( V_133 ) ;
V_330:
if ( V_324 )
F_191 ( V_50 ) ;
V_93:
F_121 ( & V_4 -> V_327 ) ;
return V_56 ;
}
static struct V_140 * F_192 ( struct V_1 * V_2 , T_5 V_339 ,
T_5 V_325 , T_5 V_139 ,
T_5 V_340 , int V_341 ,
int * V_56 )
{
struct V_140 * V_133 ;
if ( V_339 + V_139 < V_102 || ! V_340 )
V_340 = V_139 ;
V_133 = F_193 ( V_2 , V_339 + V_340 , V_139 - V_340 , V_341 ,
V_56 ) ;
if ( ! V_133 )
return NULL ;
F_143 ( V_133 , V_325 ) ;
F_146 ( V_133 , V_340 ) ;
V_133 -> V_321 = V_139 - V_340 ;
V_133 -> V_139 += V_139 - V_340 ;
return V_133 ;
}
static int F_194 ( struct V_204 * V_1 ,
struct V_205 * V_206 , T_5 V_139 )
{
struct V_1 * V_2 = V_1 -> V_2 ;
struct V_248 * V_207 = (struct V_248 * ) V_206 -> V_208 ;
struct V_140 * V_133 ;
struct V_49 * V_50 ;
T_6 V_209 ;
bool V_324 = false ;
unsigned char * V_312 ;
int V_56 , V_325 = 0 ;
struct V_342 V_343 = { 0 } ;
int V_315 = 0 ;
int V_344 ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
unsigned short V_345 = 0 ;
int V_313 , V_227 ;
int V_210 = 0 ;
if ( V_207 == NULL ) {
V_50 = V_4 -> V_7 . V_50 ;
V_209 = V_4 -> V_150 ;
V_312 = NULL ;
} else {
V_56 = - V_178 ;
if ( V_206 -> V_211 < sizeof( struct V_248 ) )
goto V_93;
if ( V_206 -> V_211 < ( V_207 -> V_271 + F_186 ( struct V_248 , V_272 ) ) )
goto V_93;
V_209 = V_207 -> V_267 ;
V_312 = V_207 -> V_272 ;
V_50 = F_187 ( F_34 ( V_2 ) , V_207 -> V_270 ) ;
V_324 = true ;
}
V_56 = - V_329 ;
if ( V_50 == NULL )
goto V_216;
if ( V_1 -> type == V_346 )
V_325 = V_50 -> V_224 ;
V_56 = - V_217 ;
if ( ! ( V_50 -> V_218 & V_219 ) )
goto V_216;
if ( V_4 -> V_347 ) {
V_344 = sizeof( V_343 ) ;
V_56 = - V_178 ;
if ( V_139 < V_344 )
goto V_216;
V_139 -= V_344 ;
V_56 = F_145 ( ( void * ) & V_343 , V_206 -> V_233 ,
V_344 ) ;
if ( V_56 < 0 )
goto V_216;
if ( ( V_343 . V_218 & V_348 ) &&
( V_343 . V_349 + V_343 . V_350 + 2 >
V_343 . V_351 ) )
V_343 . V_351 = V_343 . V_349 +
V_343 . V_350 + 2 ;
V_56 = - V_178 ;
if ( V_343 . V_351 > V_139 )
goto V_216;
if ( V_343 . V_345 != V_352 ) {
switch ( V_343 . V_345 & ~ V_353 ) {
case V_354 :
V_345 = V_355 ;
break;
case V_356 :
V_345 = V_357 ;
break;
case V_358 :
V_345 = V_359 ;
break;
default:
goto V_216;
}
if ( V_343 . V_345 & V_353 )
V_345 |= V_360 ;
if ( V_343 . V_361 == 0 )
goto V_216;
}
}
if ( F_35 ( F_95 ( V_2 , V_220 ) ) ) {
if ( ! F_139 ( V_50 ) ) {
V_56 = - V_221 ;
goto V_216;
}
V_210 = 4 ;
}
V_56 = - V_222 ;
if ( ! V_345 && ( V_139 > V_50 -> V_223 + V_325 + V_225 + V_210 ) )
goto V_216;
V_56 = - V_231 ;
V_313 = F_140 ( V_50 ) ;
V_227 = V_50 -> V_228 ;
V_133 = F_192 ( V_2 , V_313 + V_227 , V_313 , V_139 , V_343 . V_351 ,
V_206 -> V_337 & V_338 , & V_56 ) ;
if ( V_133 == NULL )
goto V_216;
F_195 ( V_133 , V_325 ) ;
V_56 = - V_178 ;
if ( V_1 -> type == V_255 &&
( V_315 = F_178 ( V_133 , V_50 , F_179 ( V_209 ) , V_312 , NULL , V_139 ) ) < 0 )
goto V_234;
V_56 = F_196 ( V_133 , V_315 , V_206 -> V_233 , 0 , V_139 ) ;
if ( V_56 )
goto V_234;
V_56 = F_150 ( V_2 , & F_151 ( V_133 ) -> V_243 ) ;
if ( V_56 < 0 )
goto V_234;
if ( ! V_345 && ( V_139 > V_50 -> V_223 + V_325 + V_210 ) ) {
struct V_235 * V_236 ;
F_147 ( V_133 ) ;
V_236 = F_148 ( V_133 ) ;
if ( V_236 -> V_237 != F_149 ( V_238 ) ) {
V_56 = - V_222 ;
goto V_234;
}
}
V_133 -> V_201 = V_209 ;
V_133 -> V_50 = V_50 ;
V_133 -> V_239 = V_2 -> V_240 ;
V_133 -> V_241 = V_2 -> V_242 ;
if ( V_4 -> V_347 ) {
if ( V_343 . V_218 & V_348 ) {
if ( ! F_197 ( V_133 , V_343 . V_349 ,
V_343 . V_350 ) ) {
V_56 = - V_178 ;
goto V_234;
}
}
F_151 ( V_133 ) -> V_361 = V_343 . V_361 ;
F_151 ( V_133 ) -> V_345 = V_345 ;
F_151 ( V_133 ) -> V_345 |= V_362 ;
F_151 ( V_133 ) -> V_363 = 0 ;
V_139 += V_344 ;
}
if ( F_35 ( V_210 == 4 ) )
V_133 -> V_244 = 1 ;
V_56 = F_152 ( V_133 ) ;
if ( V_56 > 0 && ( V_56 = F_190 ( V_56 ) ) != 0 )
goto V_216;
if ( V_324 )
F_191 ( V_50 ) ;
return V_139 ;
V_234:
F_108 ( V_133 ) ;
V_216:
if ( V_50 && V_324 )
F_191 ( V_50 ) ;
V_93:
return V_56 ;
}
static int F_198 ( struct V_202 * V_203 , struct V_204 * V_1 ,
struct V_205 * V_206 , T_5 V_139 )
{
struct V_1 * V_2 = V_1 -> V_2 ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
if ( V_4 -> V_36 . V_29 )
return F_185 ( V_4 , V_206 ) ;
else
return F_194 ( V_1 , V_206 , V_139 ) ;
}
static int F_199 ( struct V_204 * V_1 )
{
struct V_1 * V_2 = V_1 -> V_2 ;
struct V_3 * V_4 ;
struct V_166 * V_166 ;
union V_63 V_64 ;
if ( ! V_2 )
return 0 ;
V_166 = F_34 ( V_2 ) ;
V_4 = F_2 ( V_2 ) ;
F_113 ( & V_166 -> V_364 . V_365 ) ;
F_200 ( V_2 ) ;
F_121 ( & V_166 -> V_364 . V_365 ) ;
F_201 () ;
F_202 ( V_166 , V_2 -> V_366 , - 1 ) ;
F_203 () ;
F_12 ( & V_4 -> V_9 ) ;
F_13 ( V_2 , false ) ;
if ( V_4 -> V_7 . V_50 ) {
F_191 ( V_4 -> V_7 . V_50 ) ;
V_4 -> V_7 . V_50 = NULL ;
}
F_10 ( & V_4 -> V_9 ) ;
F_204 ( V_2 ) ;
memset ( & V_64 , 0 , sizeof( V_64 ) ) ;
if ( V_4 -> V_40 . V_29 )
F_205 ( V_2 , & V_64 , 1 , 0 ) ;
if ( V_4 -> V_36 . V_29 )
F_205 ( V_2 , & V_64 , 1 , 1 ) ;
F_122 ( V_2 ) ;
F_11 () ;
F_206 ( V_2 ) ;
V_1 -> V_2 = NULL ;
F_93 ( & V_2 -> V_92 ) ;
F_207 ( V_2 ) ;
F_208 ( V_2 ) ;
return 0 ;
}
static int F_209 ( struct V_1 * V_2 , struct V_49 * V_50 , T_6 V_201 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
if ( V_4 -> V_6 ) {
if ( V_50 )
F_191 ( V_50 ) ;
return - V_178 ;
}
F_210 ( V_2 ) ;
F_12 ( & V_4 -> V_9 ) ;
F_13 ( V_2 , true ) ;
V_4 -> V_150 = V_201 ;
V_4 -> V_7 . type = V_201 ;
if ( V_4 -> V_7 . V_50 )
F_191 ( V_4 -> V_7 . V_50 ) ;
V_4 -> V_7 . V_50 = V_50 ;
V_4 -> V_58 = V_50 ? V_50 -> V_58 : 0 ;
if ( V_201 == 0 )
goto V_216;
if ( ! V_50 || ( V_50 -> V_218 & V_219 ) ) {
F_1 ( V_2 ) ;
} else {
V_2 -> V_367 = V_217 ;
if ( ! F_95 ( V_2 , V_147 ) )
V_2 -> V_368 ( V_2 ) ;
}
V_216:
F_10 ( & V_4 -> V_9 ) ;
F_211 ( V_2 ) ;
return 0 ;
}
static int F_212 ( struct V_204 * V_1 , struct V_212 * V_369 ,
int V_370 )
{
struct V_1 * V_2 = V_1 -> V_2 ;
char V_199 [ 15 ] ;
struct V_49 * V_50 ;
int V_56 = - V_215 ;
if ( V_370 != sizeof( struct V_212 ) )
return - V_178 ;
F_134 ( V_199 , V_369 -> V_371 , sizeof( V_199 ) ) ;
V_50 = F_213 ( F_34 ( V_2 ) , V_199 ) ;
if ( V_50 )
V_56 = F_209 ( V_2 , V_50 , F_2 ( V_2 ) -> V_150 ) ;
return V_56 ;
}
static int F_214 ( struct V_204 * V_1 , struct V_212 * V_369 , int V_370 )
{
struct V_248 * V_249 = (struct V_248 * ) V_369 ;
struct V_1 * V_2 = V_1 -> V_2 ;
struct V_49 * V_50 = NULL ;
int V_56 ;
if ( V_370 < sizeof( struct V_248 ) )
return - V_178 ;
if ( V_249 -> V_264 != V_265 )
return - V_178 ;
if ( V_249 -> V_270 ) {
V_56 = - V_215 ;
V_50 = F_187 ( F_34 ( V_2 ) , V_249 -> V_270 ) ;
if ( V_50 == NULL )
goto V_93;
}
V_56 = F_209 ( V_2 , V_50 , V_249 -> V_267 ? : F_2 ( V_2 ) -> V_150 ) ;
V_93:
return V_56 ;
}
static int F_215 ( struct V_166 * V_166 , struct V_204 * V_1 , int V_201 ,
int V_372 )
{
struct V_1 * V_2 ;
struct V_3 * V_4 ;
T_6 V_209 = ( V_373 T_6 ) V_201 ;
int V_56 ;
if ( ! F_216 ( V_374 ) )
return - V_375 ;
if ( V_1 -> type != V_255 && V_1 -> type != V_346 &&
V_1 -> type != V_376 )
return - V_377 ;
V_1 -> V_378 = V_379 ;
V_56 = - V_231 ;
V_2 = F_217 ( V_166 , V_380 , V_182 , & V_381 ) ;
if ( V_2 == NULL )
goto V_93;
V_1 -> V_382 = & V_383 ;
if ( V_1 -> type == V_376 )
V_1 -> V_382 = & V_384 ;
F_218 ( V_1 , V_2 ) ;
V_4 = F_2 ( V_2 ) ;
V_2 -> V_385 = V_380 ;
V_4 -> V_150 = V_209 ;
V_2 -> V_386 = F_92 ;
F_219 ( V_2 ) ;
F_119 ( & V_4 -> V_9 ) ;
F_220 ( & V_4 -> V_327 ) ;
V_4 -> V_7 . F_28 = F_156 ;
if ( V_1 -> type == V_376 )
V_4 -> V_7 . F_28 = F_127 ;
V_4 -> V_7 . V_164 = V_2 ;
if ( V_209 ) {
V_4 -> V_7 . type = V_209 ;
F_1 ( V_2 ) ;
}
F_113 ( & V_166 -> V_364 . V_365 ) ;
F_221 ( V_2 , & V_166 -> V_364 . V_387 ) ;
F_121 ( & V_166 -> V_364 . V_365 ) ;
F_201 () ;
F_202 ( V_166 , & V_381 , 1 ) ;
F_203 () ;
return 0 ;
V_93:
return V_56 ;
}
static int F_222 ( struct V_1 * V_2 , struct V_205 * V_206 , int V_139 )
{
struct V_388 * V_389 ;
struct V_140 * V_133 , * V_390 ;
int V_391 , V_56 ;
V_56 = - V_392 ;
V_133 = F_223 ( & V_2 -> V_144 ) ;
if ( V_133 == NULL )
goto V_93;
V_391 = V_133 -> V_139 ;
if ( V_391 > V_139 ) {
V_206 -> V_337 |= V_393 ;
V_391 = V_139 ;
}
V_56 = F_224 ( V_133 , 0 , V_206 -> V_233 , V_391 ) ;
if ( V_56 )
goto V_394;
F_225 ( V_206 , V_2 , V_133 ) ;
V_389 = F_226 ( V_133 ) ;
F_227 ( V_206 , V_395 , V_396 ,
sizeof( V_389 -> V_397 ) , & V_389 -> V_397 ) ;
V_206 -> V_337 |= V_398 ;
V_56 = V_391 ;
F_228 ( & V_2 -> V_144 . V_41 ) ;
V_2 -> V_367 = 0 ;
if ( ( V_390 = F_229 ( & V_2 -> V_144 ) ) != NULL ) {
V_2 -> V_367 = F_226 ( V_390 ) -> V_397 . V_399 ;
F_230 ( & V_2 -> V_144 . V_41 ) ;
V_2 -> V_368 ( V_2 ) ;
} else
F_230 ( & V_2 -> V_144 . V_41 ) ;
V_394:
F_108 ( V_133 ) ;
V_93:
return V_56 ;
}
static int F_231 ( struct V_202 * V_203 , struct V_204 * V_1 ,
struct V_205 * V_206 , T_5 V_139 , int V_218 )
{
struct V_1 * V_2 = V_1 -> V_2 ;
struct V_140 * V_133 ;
int V_391 , V_56 ;
struct V_248 * V_249 ;
int V_344 = 0 ;
V_56 = - V_178 ;
if ( V_218 & ~ ( V_400 | V_338 | V_393 | V_401 | V_398 ) )
goto V_93;
#if 0
if (pkt_sk(sk)->ifindex < 0)
return -ENODEV;
#endif
if ( V_218 & V_398 ) {
V_56 = F_222 ( V_2 , V_206 , V_139 ) ;
goto V_93;
}
V_133 = F_232 ( V_2 , V_218 , V_218 & V_338 , & V_56 ) ;
if ( V_133 == NULL )
goto V_93;
if ( F_2 ( V_2 ) -> V_347 ) {
struct V_342 V_343 = { 0 } ;
V_56 = - V_178 ;
V_344 = sizeof( V_343 ) ;
if ( V_139 < V_344 )
goto V_234;
V_139 -= V_344 ;
if ( F_233 ( V_133 ) ) {
struct V_402 * V_403 = F_151 ( V_133 ) ;
V_343 . V_351 = F_234 ( V_133 ) ;
V_343 . V_361 = V_403 -> V_361 ;
if ( V_403 -> V_345 & V_355 )
V_343 . V_345 = V_354 ;
else if ( V_403 -> V_345 & V_357 )
V_343 . V_345 = V_356 ;
else if ( V_403 -> V_345 & V_359 )
V_343 . V_345 = V_358 ;
else if ( V_403 -> V_345 & V_404 )
goto V_234;
else
F_18 () ;
if ( V_403 -> V_345 & V_360 )
V_343 . V_345 |= V_353 ;
} else
V_343 . V_345 = V_352 ;
if ( V_133 -> V_286 == V_287 ) {
V_343 . V_218 = V_348 ;
V_343 . V_349 = F_235 ( V_133 ) ;
V_343 . V_350 = V_133 -> V_350 ;
} else if ( V_133 -> V_286 == V_405 ) {
V_343 . V_218 = V_406 ;
}
V_56 = F_236 ( V_206 -> V_233 , ( void * ) & V_343 ,
V_344 ) ;
if ( V_56 < 0 )
goto V_234;
}
V_249 = & F_131 ( V_133 ) -> V_195 . V_263 ;
if ( V_1 -> type == V_376 )
V_206 -> V_211 = sizeof( struct V_189 ) ;
else
V_206 -> V_211 = V_249 -> V_271 + F_186 ( struct V_248 , V_272 ) ;
V_391 = V_133 -> V_139 ;
if ( V_391 > V_139 ) {
V_391 = V_139 ;
V_206 -> V_337 |= V_393 ;
}
V_56 = F_224 ( V_133 , 0 , V_206 -> V_233 , V_391 ) ;
if ( V_56 )
goto V_234;
F_237 ( V_206 , V_2 , V_133 ) ;
if ( V_206 -> V_208 )
memcpy ( V_206 -> V_208 , & F_131 ( V_133 ) -> V_195 ,
V_206 -> V_211 ) ;
if ( F_2 ( V_2 ) -> V_407 ) {
struct V_408 V_409 ;
V_409 . V_20 = V_105 ;
if ( V_133 -> V_286 == V_287 )
V_409 . V_20 |= V_288 ;
V_409 . V_294 = F_131 ( V_133 ) -> V_273 ;
V_409 . V_295 = V_133 -> V_139 ;
V_409 . V_296 = 0 ;
V_409 . V_297 = F_158 ( V_133 ) ;
if ( F_75 ( V_133 ) ) {
V_409 . V_134 = F_76 ( V_133 ) ;
V_409 . V_20 |= V_135 ;
} else {
V_409 . V_134 = 0 ;
}
V_409 . V_307 = 0 ;
F_227 ( V_206 , V_395 , V_410 , sizeof( V_409 ) , & V_409 ) ;
}
V_56 = V_344 + ( ( V_218 & V_393 ) ? V_133 -> V_139 : V_391 ) ;
V_234:
F_238 ( V_2 , V_133 ) ;
V_93:
return V_56 ;
}
static int F_239 ( struct V_204 * V_1 , struct V_212 * V_369 ,
int * V_411 , int V_412 )
{
struct V_49 * V_50 ;
struct V_1 * V_2 = V_1 -> V_2 ;
if ( V_412 )
return - V_413 ;
V_369 -> V_414 = V_265 ;
F_137 () ;
V_50 = F_240 ( F_34 ( V_2 ) , F_2 ( V_2 ) -> V_58 ) ;
if ( V_50 )
strncpy ( V_369 -> V_371 , V_50 -> V_199 , 14 ) ;
else
memset ( V_369 -> V_371 , 0 , 14 ) ;
F_141 () ;
* V_411 = sizeof( * V_369 ) ;
return 0 ;
}
static int F_241 ( struct V_204 * V_1 , struct V_212 * V_369 ,
int * V_411 , int V_412 )
{
struct V_49 * V_50 ;
struct V_1 * V_2 = V_1 -> V_2 ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
F_242 ( struct V_248 * , V_249 , V_369 ) ;
if ( V_412 )
return - V_413 ;
V_249 -> V_264 = V_265 ;
V_249 -> V_270 = V_4 -> V_58 ;
V_249 -> V_267 = V_4 -> V_150 ;
V_249 -> V_268 = 0 ;
F_137 () ;
V_50 = F_240 ( F_34 ( V_2 ) , V_4 -> V_58 ) ;
if ( V_50 ) {
V_249 -> V_266 = V_50 -> type ;
V_249 -> V_271 = V_50 -> V_370 ;
memcpy ( V_249 -> V_272 , V_50 -> V_415 , V_50 -> V_370 ) ;
} else {
V_249 -> V_266 = 0 ;
V_249 -> V_271 = 0 ;
}
F_141 () ;
* V_411 = F_186 ( struct V_248 , V_272 ) + V_249 -> V_271 ;
return 0 ;
}
static int F_243 ( struct V_49 * V_50 , struct V_416 * V_172 ,
int V_417 )
{
switch ( V_172 -> type ) {
case V_418 :
if ( V_172 -> V_419 != V_50 -> V_370 )
return - V_178 ;
if ( V_417 > 0 )
return F_244 ( V_50 , V_172 -> V_312 ) ;
else
return F_245 ( V_50 , V_172 -> V_312 ) ;
break;
case V_420 :
return F_246 ( V_50 , V_417 ) ;
break;
case V_421 :
return F_247 ( V_50 , V_417 ) ;
break;
case V_422 :
if ( V_172 -> V_419 != V_50 -> V_370 )
return - V_178 ;
if ( V_417 > 0 )
return F_248 ( V_50 , V_172 -> V_312 ) ;
else
return F_249 ( V_50 , V_172 -> V_312 ) ;
break;
default:
break;
}
return 0 ;
}
static void F_250 ( struct V_49 * V_50 , struct V_416 * V_172 , int V_417 )
{
for ( ; V_172 ; V_172 = V_172 -> V_423 ) {
if ( V_172 -> V_58 == V_50 -> V_58 )
F_243 ( V_50 , V_172 , V_417 ) ;
}
}
static int F_251 ( struct V_1 * V_2 , struct V_424 * V_425 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_416 * V_426 , * V_172 ;
struct V_49 * V_50 ;
int V_56 ;
F_32 () ;
V_56 = - V_215 ;
V_50 = F_33 ( F_34 ( V_2 ) , V_425 -> V_427 ) ;
if ( ! V_50 )
goto V_428;
V_56 = - V_178 ;
if ( V_425 -> V_429 > V_50 -> V_370 )
goto V_428;
V_56 = - V_231 ;
V_172 = F_252 ( sizeof( * V_172 ) , V_182 ) ;
if ( V_172 == NULL )
goto V_428;
V_56 = 0 ;
for ( V_426 = V_4 -> V_430 ; V_426 ; V_426 = V_426 -> V_423 ) {
if ( V_426 -> V_58 == V_425 -> V_427 &&
V_426 -> type == V_425 -> V_431 &&
V_426 -> V_419 == V_425 -> V_429 &&
memcmp ( V_426 -> V_312 , V_425 -> V_432 , V_426 -> V_419 ) == 0 ) {
V_426 -> V_433 ++ ;
F_126 ( V_172 ) ;
goto V_428;
}
}
V_172 -> type = V_425 -> V_431 ;
V_172 -> V_58 = V_425 -> V_427 ;
V_172 -> V_419 = V_425 -> V_429 ;
memcpy ( V_172 -> V_312 , V_425 -> V_432 , V_172 -> V_419 ) ;
V_172 -> V_433 = 1 ;
V_172 -> V_423 = V_4 -> V_430 ;
V_4 -> V_430 = V_172 ;
V_56 = F_243 ( V_50 , V_172 , 1 ) ;
if ( V_56 ) {
V_4 -> V_430 = V_172 -> V_423 ;
F_126 ( V_172 ) ;
}
V_428:
F_36 () ;
return V_56 ;
}
static int F_253 ( struct V_1 * V_2 , struct V_424 * V_425 )
{
struct V_416 * V_426 , * * V_434 ;
F_32 () ;
for ( V_434 = & F_2 ( V_2 ) -> V_430 ; ( V_426 = * V_434 ) != NULL ; V_434 = & V_426 -> V_423 ) {
if ( V_426 -> V_58 == V_425 -> V_427 &&
V_426 -> type == V_425 -> V_431 &&
V_426 -> V_419 == V_425 -> V_429 &&
memcmp ( V_426 -> V_312 , V_425 -> V_432 , V_426 -> V_419 ) == 0 ) {
if ( -- V_426 -> V_433 == 0 ) {
struct V_49 * V_50 ;
* V_434 = V_426 -> V_423 ;
V_50 = F_33 ( F_34 ( V_2 ) , V_426 -> V_58 ) ;
if ( V_50 )
F_243 ( V_50 , V_426 , - 1 ) ;
F_126 ( V_426 ) ;
}
F_36 () ;
return 0 ;
}
}
F_36 () ;
return - V_435 ;
}
static void F_204 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_416 * V_426 ;
if ( ! V_4 -> V_430 )
return;
F_32 () ;
while ( ( V_426 = V_4 -> V_430 ) != NULL ) {
struct V_49 * V_50 ;
V_4 -> V_430 = V_426 -> V_423 ;
V_50 = F_33 ( F_34 ( V_2 ) , V_426 -> V_58 ) ;
if ( V_50 != NULL )
F_243 ( V_50 , V_426 , - 1 ) ;
F_126 ( V_426 ) ;
}
F_36 () ;
}
static int
F_254 ( struct V_204 * V_1 , int V_436 , int V_437 , char T_7 * V_438 , unsigned int V_439 )
{
struct V_1 * V_2 = V_1 -> V_2 ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_440 ;
if ( V_436 != V_395 )
return - V_441 ;
switch ( V_437 ) {
case V_442 :
case V_443 :
{
struct V_424 V_425 ;
int V_139 = V_439 ;
memset ( & V_425 , 0 , sizeof( V_425 ) ) ;
if ( V_139 < sizeof( struct V_444 ) )
return - V_178 ;
if ( V_139 > sizeof( V_425 ) )
V_139 = sizeof( V_425 ) ;
if ( F_255 ( & V_425 , V_438 , V_139 ) )
return - V_320 ;
if ( V_139 < ( V_425 . V_429 + F_186 ( struct V_444 , V_432 ) ) )
return - V_178 ;
if ( V_437 == V_442 )
V_440 = F_251 ( V_2 , & V_425 ) ;
else
V_440 = F_253 ( V_2 , & V_425 ) ;
return V_440 ;
}
case V_445 :
case V_446 :
{
union V_63 V_64 ;
int V_139 ;
switch ( V_4 -> V_18 ) {
case V_19 :
case V_21 :
V_139 = sizeof( V_64 . V_447 ) ;
break;
case V_22 :
default:
V_139 = sizeof( V_64 . V_66 ) ;
break;
}
if ( V_439 < V_139 )
return - V_178 ;
if ( F_2 ( V_2 ) -> V_347 )
return - V_178 ;
if ( F_255 ( & V_64 . V_447 , V_438 , V_139 ) )
return - V_320 ;
return F_205 ( V_2 , & V_64 , 0 ,
V_437 == V_446 ) ;
}
case V_448 :
{
int V_449 ;
if ( V_439 != sizeof( V_449 ) )
return - V_178 ;
if ( F_255 ( & V_449 , V_438 , sizeof( V_449 ) ) )
return - V_320 ;
F_2 ( V_2 ) -> V_291 = V_449 ;
return 0 ;
}
case V_450 :
{
int V_449 ;
if ( V_439 != sizeof( V_449 ) )
return - V_178 ;
if ( V_4 -> V_40 . V_29 || V_4 -> V_36 . V_29 )
return - V_328 ;
if ( F_255 ( & V_449 , V_438 , sizeof( V_449 ) ) )
return - V_320 ;
switch ( V_449 ) {
case V_19 :
case V_21 :
case V_22 :
V_4 -> V_18 = V_449 ;
return 0 ;
default:
return - V_178 ;
}
}
case V_451 :
{
unsigned int V_449 ;
if ( V_439 != sizeof( V_449 ) )
return - V_178 ;
if ( V_4 -> V_40 . V_29 || V_4 -> V_36 . V_29 )
return - V_328 ;
if ( F_255 ( & V_449 , V_438 , sizeof( V_449 ) ) )
return - V_320 ;
V_4 -> V_289 = V_449 ;
return 0 ;
}
case V_452 :
{
unsigned int V_449 ;
if ( V_439 != sizeof( V_449 ) )
return - V_178 ;
if ( V_4 -> V_40 . V_29 || V_4 -> V_36 . V_29 )
return - V_328 ;
if ( F_255 ( & V_449 , V_438 , sizeof( V_449 ) ) )
return - V_320 ;
V_4 -> V_333 = ! ! V_449 ;
return 0 ;
}
case V_410 :
{
int V_449 ;
if ( V_439 < sizeof( V_449 ) )
return - V_178 ;
if ( F_255 ( & V_449 , V_438 , sizeof( V_449 ) ) )
return - V_320 ;
V_4 -> V_407 = ! ! V_449 ;
return 0 ;
}
case V_453 :
{
int V_449 ;
if ( V_439 < sizeof( V_449 ) )
return - V_178 ;
if ( F_255 ( & V_449 , V_438 , sizeof( V_449 ) ) )
return - V_320 ;
V_4 -> V_269 = ! ! V_449 ;
return 0 ;
}
case V_454 :
{
int V_449 ;
if ( V_1 -> type != V_346 )
return - V_178 ;
if ( V_4 -> V_40 . V_29 || V_4 -> V_36 . V_29 )
return - V_328 ;
if ( V_439 < sizeof( V_449 ) )
return - V_178 ;
if ( F_255 ( & V_449 , V_438 , sizeof( V_449 ) ) )
return - V_320 ;
V_4 -> V_347 = ! ! V_449 ;
return 0 ;
}
case V_455 :
{
int V_449 ;
if ( V_439 != sizeof( V_449 ) )
return - V_178 ;
if ( F_255 ( & V_449 , V_438 , sizeof( V_449 ) ) )
return - V_320 ;
V_4 -> V_298 = V_449 ;
return 0 ;
}
case V_456 :
{
int V_449 ;
if ( V_439 != sizeof( V_449 ) )
return - V_178 ;
if ( F_255 ( & V_449 , V_438 , sizeof( V_449 ) ) )
return - V_320 ;
return F_112 ( V_2 , V_449 & 0xffff , V_449 >> 16 ) ;
}
default:
return - V_441 ;
}
}
static int F_256 ( struct V_204 * V_1 , int V_436 , int V_437 ,
char T_7 * V_438 , int T_7 * V_439 )
{
int V_139 ;
int V_449 , V_457 = sizeof( V_449 ) ;
struct V_1 * V_2 = V_1 -> V_2 ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
void * V_43 = & V_449 ;
struct V_458 V_459 ;
union V_460 V_461 ;
if ( V_436 != V_395 )
return - V_441 ;
if ( F_257 ( V_139 , V_439 ) )
return - V_320 ;
if ( V_139 < 0 )
return - V_178 ;
switch ( V_437 ) {
case V_462 :
F_228 ( & V_2 -> V_92 . V_41 ) ;
if ( V_4 -> V_18 == V_22 ) {
V_457 = sizeof( struct V_463 ) ;
memcpy ( & V_461 . V_83 , & V_4 -> V_111 ,
sizeof( struct V_458 ) ) ;
V_461 . V_83 . V_84 =
V_4 -> V_82 . V_83 . V_84 ;
V_461 . V_83 . V_274 += V_4 -> V_111 . V_112 ;
V_43 = & V_461 . V_83 ;
} else {
V_457 = sizeof( struct V_458 ) ;
V_459 = V_4 -> V_111 ;
V_459 . V_274 += V_459 . V_112 ;
V_43 = & V_459 ;
}
memset ( & V_4 -> V_111 , 0 , sizeof( V_459 ) ) ;
F_230 ( & V_2 -> V_92 . V_41 ) ;
break;
case V_410 :
V_449 = V_4 -> V_407 ;
break;
case V_453 :
V_449 = V_4 -> V_269 ;
break;
case V_454 :
V_449 = V_4 -> V_347 ;
break;
case V_450 :
V_449 = V_4 -> V_18 ;
break;
case V_464 :
if ( V_139 > sizeof( int ) )
V_139 = sizeof( int ) ;
if ( F_255 ( & V_449 , V_438 , V_139 ) )
return - V_320 ;
switch ( V_449 ) {
case V_19 :
V_449 = sizeof( struct V_12 ) ;
break;
case V_21 :
V_449 = sizeof( struct V_14 ) ;
break;
case V_22 :
V_449 = sizeof( struct V_106 ) ;
break;
default:
return - V_178 ;
}
break;
case V_451 :
V_449 = V_4 -> V_289 ;
break;
case V_452 :
V_449 = V_4 -> V_333 ;
break;
case V_455 :
V_449 = V_4 -> V_298 ;
break;
case V_456 :
V_449 = ( V_4 -> V_6 ?
( ( T_1 ) V_4 -> V_6 -> V_174 |
( ( T_1 ) V_4 -> V_6 -> type << 16 ) ) :
0 ) ;
break;
default:
return - V_441 ;
}
if ( V_139 > V_457 )
V_139 = V_457 ;
if ( F_258 ( V_139 , V_439 ) )
return - V_320 ;
if ( F_259 ( V_438 , V_43 , V_139 ) )
return - V_320 ;
return 0 ;
}
static int F_260 ( struct V_465 * V_466 , unsigned long V_206 , void * V_43 )
{
struct V_1 * V_2 ;
struct V_467 * V_468 ;
struct V_49 * V_50 = V_43 ;
struct V_166 * V_166 = F_106 ( V_50 ) ;
F_137 () ;
F_261 (sk, node, &net->packet.sklist) {
struct V_3 * V_4 = F_2 ( V_2 ) ;
switch ( V_206 ) {
case V_469 :
if ( V_4 -> V_430 )
F_250 ( V_50 , V_4 -> V_430 , - 1 ) ;
case V_470 :
if ( V_50 -> V_58 == V_4 -> V_58 ) {
F_12 ( & V_4 -> V_9 ) ;
if ( V_4 -> V_5 ) {
F_6 ( V_2 , false ) ;
V_2 -> V_367 = V_217 ;
if ( ! F_95 ( V_2 , V_147 ) )
V_2 -> V_368 ( V_2 ) ;
}
if ( V_206 == V_469 ) {
V_4 -> V_58 = - 1 ;
if ( V_4 -> V_7 . V_50 )
F_191 ( V_4 -> V_7 . V_50 ) ;
V_4 -> V_7 . V_50 = NULL ;
}
F_10 ( & V_4 -> V_9 ) ;
}
break;
case V_471 :
if ( V_50 -> V_58 == V_4 -> V_58 ) {
F_12 ( & V_4 -> V_9 ) ;
if ( V_4 -> V_150 )
F_1 ( V_2 ) ;
F_10 ( & V_4 -> V_9 ) ;
}
break;
}
}
F_141 () ;
return V_472 ;
}
static int F_262 ( struct V_204 * V_1 , unsigned int V_473 ,
unsigned long V_474 )
{
struct V_1 * V_2 = V_1 -> V_2 ;
switch ( V_473 ) {
case V_475 :
{
int V_476 = F_263 ( V_2 ) ;
return F_258 ( V_476 , ( int T_7 * ) V_474 ) ;
}
case V_477 :
{
struct V_140 * V_133 ;
int V_476 = 0 ;
F_228 ( & V_2 -> V_92 . V_41 ) ;
V_133 = F_229 ( & V_2 -> V_92 ) ;
if ( V_133 )
V_476 = V_133 -> V_139 ;
F_230 ( & V_2 -> V_92 . V_41 ) ;
return F_258 ( V_476 , ( int T_7 * ) V_474 ) ;
}
case V_478 :
return F_264 ( V_2 , (struct V_282 T_7 * ) V_474 ) ;
case V_479 :
return F_265 ( V_2 , (struct V_121 T_7 * ) V_474 ) ;
#ifdef F_266
case V_480 :
case V_481 :
case V_482 :
case V_483 :
case V_484 :
case V_485 :
case V_486 :
case V_487 :
case V_488 :
case V_489 :
case V_490 :
case V_491 :
case V_492 :
case V_493 :
return V_494 . V_495 ( V_1 , V_473 , V_474 ) ;
#endif
default:
return - V_496 ;
}
return 0 ;
}
static unsigned int F_267 ( struct V_497 * V_497 , struct V_204 * V_1 ,
T_8 * V_498 )
{
struct V_1 * V_2 = V_1 -> V_2 ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
unsigned int V_499 = F_268 ( V_497 , V_1 , V_498 ) ;
F_228 ( & V_2 -> V_92 . V_41 ) ;
if ( V_4 -> V_40 . V_29 ) {
if ( ! F_88 ( V_4 , & V_4 -> V_40 ,
V_126 ) )
V_499 |= V_500 | V_501 ;
}
F_230 ( & V_2 -> V_92 . V_41 ) ;
F_228 ( & V_2 -> V_502 . V_41 ) ;
if ( V_4 -> V_36 . V_29 ) {
if ( F_23 ( V_4 , & V_4 -> V_36 , V_136 ) )
V_499 |= V_503 | V_504 ;
}
F_230 ( & V_2 -> V_502 . V_41 ) ;
return V_499 ;
}
static void F_269 ( struct V_505 * V_506 )
{
struct V_497 * V_497 = V_506 -> V_507 ;
struct V_204 * V_1 = V_497 -> V_508 ;
struct V_1 * V_2 = V_1 -> V_2 ;
if ( V_2 )
F_80 ( & F_2 ( V_2 ) -> V_509 ) ;
}
static void F_270 ( struct V_505 * V_506 )
{
struct V_497 * V_497 = V_506 -> V_507 ;
struct V_204 * V_1 = V_497 -> V_508 ;
struct V_1 * V_2 = V_1 -> V_2 ;
if ( V_2 )
F_70 ( & F_2 ( V_2 ) -> V_509 ) ;
}
static void F_271 ( struct V_68 * V_29 , unsigned int V_510 ,
unsigned int V_139 )
{
int V_172 ;
for ( V_172 = 0 ; V_172 < V_139 ; V_172 ++ ) {
if ( F_60 ( V_29 [ V_172 ] . V_30 ) ) {
if ( F_272 ( V_29 [ V_172 ] . V_30 ) )
F_273 ( V_29 [ V_172 ] . V_30 ) ;
else
F_274 ( ( unsigned long ) V_29 [ V_172 ] . V_30 ,
V_510 ) ;
V_29 [ V_172 ] . V_30 = NULL ;
}
}
F_126 ( V_29 ) ;
}
static char * F_275 ( unsigned long V_510 )
{
char * V_30 = NULL ;
T_9 V_511 = V_182 | V_512 |
V_513 | V_514 | V_515 ;
V_30 = ( char * ) F_276 ( V_511 , V_510 ) ;
if ( V_30 )
return V_30 ;
V_30 = F_277 ( ( 1 << V_510 ) * V_102 ) ;
if ( V_30 )
return V_30 ;
V_511 &= ~ V_515 ;
V_30 = ( char * ) F_276 ( V_511 , V_510 ) ;
if ( V_30 )
return V_30 ;
return NULL ;
}
static struct V_68 * F_278 ( struct V_516 * V_447 , int V_510 )
{
unsigned int V_517 = V_447 -> V_77 ;
struct V_68 * V_29 ;
int V_172 ;
V_29 = F_279 ( V_517 , sizeof( struct V_68 ) , V_182 ) ;
if ( F_35 ( ! V_29 ) )
goto V_93;
for ( V_172 = 0 ; V_172 < V_517 ; V_172 ++ ) {
V_29 [ V_172 ] . V_30 = F_275 ( V_510 ) ;
if ( F_35 ( ! V_29 [ V_172 ] . V_30 ) )
goto V_518;
}
V_93:
return V_29 ;
V_518:
F_271 ( V_29 , V_510 , V_517 ) ;
V_29 = NULL ;
goto V_93;
}
static int F_205 ( struct V_1 * V_2 , union V_63 * V_64 ,
int V_519 , int V_36 )
{
struct V_68 * V_29 = NULL ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_520 , V_510 = 0 ;
struct V_23 * V_24 ;
struct V_37 * V_38 ;
T_6 V_150 ;
int V_56 = - V_178 ;
struct V_516 * V_447 = & V_64 -> V_447 ;
if ( ! V_519 && V_36 && ( V_4 -> V_18 > V_21 ) ) {
F_17 ( 1 , L_9 ) ;
goto V_93;
}
V_24 = V_36 ? & V_4 -> V_36 : & V_4 -> V_40 ;
V_38 = V_36 ? & V_2 -> V_502 : & V_2 -> V_92 ;
V_56 = - V_328 ;
if ( ! V_519 ) {
if ( F_48 ( & V_4 -> V_509 ) )
goto V_93;
if ( F_48 ( & V_24 -> V_310 ) )
goto V_93;
}
if ( V_447 -> V_77 ) {
V_56 = - V_328 ;
if ( F_35 ( V_24 -> V_29 ) )
goto V_93;
switch ( V_4 -> V_18 ) {
case V_19 :
V_4 -> V_79 = V_521 ;
break;
case V_21 :
V_4 -> V_79 = V_522 ;
break;
case V_22 :
V_4 -> V_79 = V_523 ;
break;
}
V_56 = - V_178 ;
if ( F_35 ( ( int ) V_447 -> V_75 <= 0 ) )
goto V_93;
if ( F_35 ( V_447 -> V_75 & ( V_102 - 1 ) ) )
goto V_93;
if ( F_35 ( V_447 -> V_524 < V_4 -> V_79 +
V_4 -> V_289 ) )
goto V_93;
if ( F_35 ( V_447 -> V_524 & ( V_525 - 1 ) ) )
goto V_93;
V_24 -> V_28 = V_447 -> V_75 / V_447 -> V_524 ;
if ( F_35 ( V_24 -> V_28 <= 0 ) )
goto V_93;
if ( F_35 ( ( V_24 -> V_28 * V_447 -> V_77 ) !=
V_447 -> V_526 ) )
goto V_93;
V_56 = - V_181 ;
V_510 = F_280 ( V_447 -> V_75 ) ;
V_29 = F_278 ( V_447 , V_510 ) ;
if ( F_35 ( ! V_29 ) )
goto V_93;
switch ( V_4 -> V_18 ) {
case V_22 :
if ( ! V_36 )
F_40 ( V_4 , V_24 , V_29 , V_64 , V_36 ) ;
break;
default:
break;
}
}
else {
V_56 = - V_178 ;
if ( F_35 ( V_447 -> V_526 ) )
goto V_93;
}
F_210 ( V_2 ) ;
F_12 ( & V_4 -> V_9 ) ;
V_520 = V_4 -> V_5 ;
V_150 = V_4 -> V_150 ;
if ( V_520 ) {
V_4 -> V_150 = 0 ;
F_6 ( V_2 , false ) ;
}
F_10 ( & V_4 -> V_9 ) ;
F_11 () ;
V_56 = - V_328 ;
F_113 ( & V_4 -> V_327 ) ;
if ( V_519 || F_48 ( & V_4 -> V_509 ) == 0 ) {
V_56 = 0 ;
F_228 ( & V_38 -> V_41 ) ;
F_281 ( V_24 -> V_29 , V_29 ) ;
V_24 -> V_142 = ( V_447 -> V_526 - 1 ) ;
V_24 -> V_32 = 0 ;
V_24 -> V_31 = V_447 -> V_524 ;
F_230 ( & V_38 -> V_41 ) ;
F_281 ( V_24 -> V_527 , V_510 ) ;
F_281 ( V_24 -> V_528 , V_447 -> V_77 ) ;
V_24 -> V_529 = V_447 -> V_75 / V_102 ;
V_4 -> V_7 . F_28 = ( V_4 -> V_40 . V_29 ) ?
F_167 : F_156 ;
F_93 ( V_38 ) ;
if ( F_48 ( & V_4 -> V_509 ) )
F_96 ( L_10 ,
F_48 ( & V_4 -> V_509 ) ) ;
}
F_121 ( & V_4 -> V_327 ) ;
F_12 ( & V_4 -> V_9 ) ;
if ( V_520 ) {
V_4 -> V_150 = V_150 ;
F_1 ( V_2 ) ;
}
F_10 ( & V_4 -> V_9 ) ;
if ( V_519 && ( V_4 -> V_18 > V_21 ) ) {
if ( ! V_36 )
F_26 ( V_4 , V_36 , V_38 ) ;
}
F_211 ( V_2 ) ;
if ( V_29 )
F_271 ( V_29 , V_510 , V_447 -> V_77 ) ;
V_93:
return V_56 ;
}
static int F_282 ( struct V_497 * V_497 , struct V_204 * V_1 ,
struct V_505 * V_506 )
{
struct V_1 * V_2 = V_1 -> V_2 ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
unsigned long V_530 , V_531 ;
struct V_23 * V_24 ;
unsigned long V_100 ;
int V_56 = - V_178 ;
int V_172 ;
if ( V_506 -> V_532 )
return - V_178 ;
F_113 ( & V_4 -> V_327 ) ;
V_531 = 0 ;
for ( V_24 = & V_4 -> V_40 ; V_24 <= & V_4 -> V_36 ; V_24 ++ ) {
if ( V_24 -> V_29 ) {
V_531 += V_24 -> V_528
* V_24 -> V_529
* V_102 ;
}
}
if ( V_531 == 0 )
goto V_93;
V_530 = V_506 -> V_533 - V_506 -> V_534 ;
if ( V_530 != V_531 )
goto V_93;
V_100 = V_506 -> V_534 ;
for ( V_24 = & V_4 -> V_40 ; V_24 <= & V_4 -> V_36 ; V_24 ++ ) {
if ( V_24 -> V_29 == NULL )
continue;
for ( V_172 = 0 ; V_172 < V_24 -> V_528 ; V_172 ++ ) {
struct V_319 * V_319 ;
void * V_535 = V_24 -> V_29 [ V_172 ] . V_30 ;
int V_536 ;
for ( V_536 = 0 ; V_536 < V_24 -> V_529 ; V_536 ++ ) {
V_319 = F_16 ( V_535 ) ;
V_56 = F_283 ( V_506 , V_100 , V_319 ) ;
if ( F_35 ( V_56 ) )
goto V_93;
V_100 += V_102 ;
V_535 += V_102 ;
}
}
}
F_80 ( & V_4 -> V_509 ) ;
V_506 -> V_537 = & V_538 ;
V_56 = 0 ;
V_93:
F_121 ( & V_4 -> V_327 ) ;
return V_56 ;
}
static void * F_284 ( struct V_539 * V_540 , T_10 * V_541 )
__acquires( T_11 )
{
struct V_166 * V_166 = F_285 ( V_540 ) ;
F_137 () ;
return F_286 ( & V_166 -> V_364 . V_387 , * V_541 ) ;
}
static void * F_287 ( struct V_539 * V_540 , void * V_542 , T_10 * V_541 )
{
struct V_166 * V_166 = F_285 ( V_540 ) ;
return F_288 ( V_542 , & V_166 -> V_364 . V_387 , V_541 ) ;
}
static void F_289 ( struct V_539 * V_540 , void * V_542 )
__releases( T_11 )
{
F_141 () ;
}
static int F_290 ( struct V_539 * V_540 , void * V_542 )
{
if ( V_542 == V_543 )
F_291 ( V_540 , L_11 ) ;
else {
struct V_1 * V_544 = F_292 ( V_542 ) ;
const struct V_3 * V_4 = F_2 ( V_544 ) ;
F_293 ( V_540 ,
L_12 ,
V_544 ,
F_48 ( & V_544 -> V_545 ) ,
V_544 -> V_254 ,
F_179 ( V_4 -> V_150 ) ,
V_4 -> V_58 ,
V_4 -> V_5 ,
F_48 ( & V_544 -> V_145 ) ,
F_294 ( F_295 ( V_540 ) , F_296 ( V_544 ) ) ,
F_297 ( V_544 ) ) ;
}
return 0 ;
}
static int F_298 ( struct V_546 * V_546 , struct V_497 * V_497 )
{
return F_299 ( V_546 , V_497 , & V_547 ,
sizeof( struct V_548 ) ) ;
}
static int T_12 F_300 ( struct V_166 * V_166 )
{
F_220 ( & V_166 -> V_364 . V_365 ) ;
F_301 ( & V_166 -> V_364 . V_387 ) ;
if ( ! F_302 ( V_166 , L_13 , 0 , & V_549 ) )
return - V_181 ;
return 0 ;
}
static void T_13 F_303 ( struct V_166 * V_166 )
{
F_304 ( V_166 , L_13 ) ;
}
static void T_14 F_305 ( void )
{
F_306 ( & V_550 ) ;
F_307 ( & V_551 ) ;
F_308 ( V_380 ) ;
F_309 ( & V_381 ) ;
}
static int T_15 F_310 ( void )
{
int V_552 = F_311 ( & V_381 , 0 ) ;
if ( V_552 != 0 )
goto V_93;
F_312 ( & V_553 ) ;
F_313 ( & V_551 ) ;
F_314 ( & V_550 ) ;
V_93:
return V_552 ;
}
