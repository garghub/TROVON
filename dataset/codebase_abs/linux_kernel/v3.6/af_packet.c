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
T_1 V_57 ;
F_32 () ;
V_50 = F_33 ( F_34 ( & V_4 -> V_3 ) , V_4 -> V_58 ) ;
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
static void F_40 ( struct V_1 * V_4 ,
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
struct V_1 * V_4 = (struct V_1 * ) V_43 ;
struct V_33 * V_34 = & V_4 -> V_40 . V_39 ;
unsigned int V_91 ;
struct V_69 * V_70 ;
F_12 ( & V_4 -> V_3 . V_92 . V_41 ) ;
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
F_10 ( & V_4 -> V_3 . V_92 . V_41 ) ;
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
struct V_1 * V_4 , unsigned int V_104 )
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
struct V_1 * V_4 )
{
V_34 -> V_125 = 1 ;
V_4 -> V_82 . V_83 . V_84 ++ ;
}
static void * F_51 ( struct V_33 * V_34 ,
struct V_1 * V_4 )
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
struct V_1 * V_4 , unsigned int V_11 )
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
V_130 -> V_131 . V_134 = V_130 -> V_20 = 0 ;
}
}
static void F_77 ( struct V_33 * V_34 ,
struct V_106 * V_130 )
{
F_74 ( V_34 , V_130 ) ;
if ( V_34 -> V_65 & V_136 )
F_71 ( V_34 , V_130 ) ;
else
F_73 ( V_34 , V_130 ) ;
}
static void F_78 ( char * V_137 ,
struct V_33 * V_34 ,
struct V_69 * V_70 ,
unsigned int V_138 )
{
struct V_106 * V_130 ;
V_130 = (struct V_106 * ) V_137 ;
V_130 -> V_115 = F_79 ( V_138 ) ;
V_34 -> V_114 = V_137 ;
V_34 -> V_128 += F_79 ( V_138 ) ;
F_62 ( V_70 ) += F_79 ( V_138 ) ;
F_47 ( V_70 ) += 1 ;
F_80 ( & V_34 -> V_94 ) ;
F_77 ( V_34 , V_130 ) ;
}
static void * F_81 ( struct V_1 * V_4 ,
struct V_139 * V_133 ,
int V_11 ,
unsigned int V_138
)
{
struct V_33 * V_34 ;
struct V_69 * V_70 ;
char * V_137 , * V_101 ;
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
V_137 = V_34 -> V_128 ;
V_34 -> V_133 = V_133 ;
V_101 = ( char * ) V_70 + V_34 -> V_74 ;
if ( V_137 + F_79 ( V_138 ) < V_101 ) {
F_78 ( V_137 , V_34 , V_70 , V_138 ) ;
return ( void * ) V_137 ;
}
F_50 ( V_34 , V_4 , 0 ) ;
V_137 = ( char * ) F_51 ( V_34 , V_4 ) ;
if ( V_137 ) {
V_70 = F_46 ( V_34 ) ;
F_78 ( V_137 , V_34 , V_70 , V_138 ) ;
return ( void * ) V_137 ;
}
return NULL ;
}
static void * F_83 ( struct V_1 * V_4 ,
struct V_139 * V_133 ,
int V_11 , unsigned int V_138 )
{
char * V_137 = NULL ;
switch ( V_4 -> V_18 ) {
case V_19 :
case V_21 :
V_137 = F_22 ( V_4 , & V_4 -> V_40 ,
V_4 -> V_40 . V_32 , V_11 ) ;
return V_137 ;
case V_22 :
return F_81 ( V_4 , V_133 , V_11 , V_138 ) ;
default:
F_17 ( 1 , L_4 ) ;
F_18 () ;
return NULL ;
}
}
static void * F_84 ( struct V_1 * V_4 ,
struct V_23 * V_24 ,
unsigned int V_140 ,
int V_11 )
{
struct V_33 * V_34 = F_69 ( V_24 ) ;
struct V_69 * V_70 = F_85 ( V_34 , V_140 ) ;
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
static void * F_87 ( struct V_1 * V_4 ,
struct V_23 * V_24 ,
int V_11 )
{
unsigned int V_140 = F_86 ( V_24 ) ;
return F_84 ( V_4 , V_24 , V_140 , V_11 ) ;
}
static void * F_88 ( struct V_1 * V_4 ,
struct V_23 * V_24 ,
int V_11 )
{
if ( V_4 -> V_18 <= V_21 )
return F_89 ( V_4 , V_24 , V_11 ) ;
return F_87 ( V_4 , V_24 , V_11 ) ;
}
static void F_90 ( struct V_1 * V_4 ,
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
static void * F_89 ( struct V_1 * V_4 ,
struct V_23 * V_24 ,
int V_11 )
{
unsigned int V_140 = V_24 -> V_32 ? V_24 -> V_32 - 1 : V_24 -> V_141 ;
return F_22 ( V_4 , V_24 , V_140 , V_11 ) ;
}
static void F_91 ( struct V_23 * V_142 )
{
V_142 -> V_32 = V_142 -> V_32 != V_142 -> V_141 ? V_142 -> V_32 + 1 : 0 ;
}
static void F_92 ( struct V_2 * V_3 )
{
F_93 ( & V_3 -> V_143 ) ;
F_94 ( F_48 ( & V_3 -> V_144 ) ) ;
F_94 ( F_48 ( & V_3 -> V_145 ) ) ;
if ( ! F_95 ( V_3 , V_146 ) ) {
F_96 ( L_5 , V_3 ) ;
return;
}
F_97 ( V_3 ) ;
}
static int F_98 ( struct V_147 * V_148 , unsigned int V_149 )
{
int V_150 = F_48 ( & V_148 -> V_151 ) + 1 ;
if ( V_150 >= V_149 )
V_150 = 0 ;
return V_150 ;
}
static struct V_2 * F_99 ( struct V_147 * V_148 , struct V_139 * V_133 , unsigned int V_149 )
{
T_1 V_152 , V_153 = V_133 -> V_154 ;
V_152 = ( ( V_155 ) V_153 * V_149 ) >> 32 ;
return V_148 -> V_156 [ V_152 ] ;
}
static struct V_2 * F_100 ( struct V_147 * V_148 , struct V_139 * V_133 , unsigned int V_149 )
{
int V_157 , V_158 ;
V_157 = F_48 ( & V_148 -> V_151 ) ;
while ( ( V_158 = F_101 ( & V_148 -> V_151 , V_157 ,
F_98 ( V_148 , V_149 ) ) ) != V_157 )
V_157 = V_158 ;
return V_148 -> V_156 [ V_157 ] ;
}
static struct V_2 * F_102 ( struct V_147 * V_148 , struct V_139 * V_133 , unsigned int V_149 )
{
unsigned int V_159 = F_103 () ;
return V_148 -> V_156 [ V_159 % V_149 ] ;
}
static int F_104 ( struct V_139 * V_133 , struct V_49 * V_50 ,
struct V_160 * V_161 , struct V_49 * V_162 )
{
struct V_147 * V_148 = V_161 -> V_163 ;
unsigned int V_149 = V_148 -> V_164 ;
struct V_1 * V_4 ;
struct V_2 * V_3 ;
if ( ! F_105 ( F_106 ( V_50 ) , F_107 ( & V_148 -> V_165 ) ) ||
! V_149 ) {
F_108 ( V_133 ) ;
return 0 ;
}
switch ( V_148 -> type ) {
case V_166 :
default:
if ( V_148 -> V_167 ) {
V_133 = F_109 ( V_133 , V_168 ) ;
if ( ! V_133 )
return 0 ;
}
F_72 ( V_133 ) ;
V_3 = F_99 ( V_148 , V_133 , V_149 ) ;
break;
case V_169 :
V_3 = F_100 ( V_148 , V_133 , V_149 ) ;
break;
case V_170 :
V_3 = F_102 ( V_148 , V_133 , V_149 ) ;
break;
}
V_4 = F_1 ( V_3 ) ;
return V_4 -> V_7 . F_28 ( V_133 , V_50 , & V_4 -> V_7 , V_162 ) ;
}
static void F_3 ( struct V_2 * V_3 , struct V_1 * V_4 )
{
struct V_147 * V_148 = V_4 -> V_6 ;
F_12 ( & V_148 -> V_41 ) ;
V_148 -> V_156 [ V_148 -> V_164 ] = V_3 ;
F_19 () ;
V_148 -> V_164 ++ ;
F_10 ( & V_148 -> V_41 ) ;
}
static void F_7 ( struct V_2 * V_3 , struct V_1 * V_4 )
{
struct V_147 * V_148 = V_4 -> V_6 ;
int V_171 ;
F_12 ( & V_148 -> V_41 ) ;
for ( V_171 = 0 ; V_171 < V_148 -> V_164 ; V_171 ++ ) {
if ( V_148 -> V_156 [ V_171 ] == V_3 )
break;
}
F_110 ( V_171 >= V_148 -> V_164 ) ;
V_148 -> V_156 [ V_171 ] = V_148 -> V_156 [ V_148 -> V_164 - 1 ] ;
V_148 -> V_164 -- ;
F_10 ( & V_148 -> V_41 ) ;
}
static bool F_111 ( struct V_160 * V_172 , struct V_2 * V_3 )
{
if ( V_172 -> V_163 == ( void * ) ( (struct V_1 * ) V_3 ) -> V_6 )
return true ;
return false ;
}
static int F_112 ( struct V_2 * V_3 , T_4 V_173 , T_4 V_174 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
struct V_147 * V_148 , * V_175 ;
T_3 type = V_174 & 0xff ;
T_3 V_167 = ( V_174 & V_176 ) ? 1 : 0 ;
int V_56 ;
switch ( type ) {
case V_166 :
case V_169 :
case V_170 :
break;
default:
return - V_177 ;
}
if ( ! V_4 -> V_5 )
return - V_177 ;
if ( V_4 -> V_6 )
return - V_178 ;
F_113 ( & V_179 ) ;
V_175 = NULL ;
F_114 (f, &fanout_list, list) {
if ( V_148 -> V_173 == V_173 &&
F_107 ( & V_148 -> V_165 ) == F_34 ( V_3 ) ) {
V_175 = V_148 ;
break;
}
}
V_56 = - V_177 ;
if ( V_175 && V_175 -> V_167 != V_167 )
goto V_93;
if ( ! V_175 ) {
V_56 = - V_180 ;
V_175 = F_115 ( sizeof( * V_175 ) , V_181 ) ;
if ( ! V_175 )
goto V_93;
F_116 ( & V_175 -> V_165 , F_34 ( V_3 ) ) ;
V_175 -> V_173 = V_173 ;
V_175 -> type = type ;
V_175 -> V_167 = V_167 ;
F_117 ( & V_175 -> V_151 , 0 ) ;
F_118 ( & V_175 -> V_182 ) ;
F_119 ( & V_175 -> V_41 ) ;
F_117 ( & V_175 -> V_183 , 0 ) ;
V_175 -> V_7 . type = V_4 -> V_7 . type ;
V_175 -> V_7 . V_50 = V_4 -> V_7 . V_50 ;
V_175 -> V_7 . F_28 = F_104 ;
V_175 -> V_7 . V_163 = V_175 ;
V_175 -> V_7 . V_184 = F_111 ;
F_4 ( & V_175 -> V_7 ) ;
F_120 ( & V_175 -> V_182 , & V_185 ) ;
}
V_56 = - V_177 ;
if ( V_175 -> type == type &&
V_175 -> V_7 . type == V_4 -> V_7 . type &&
V_175 -> V_7 . V_50 == V_4 -> V_7 . V_50 ) {
V_56 = - V_186 ;
if ( F_48 ( & V_175 -> V_183 ) < V_187 ) {
F_8 ( & V_4 -> V_7 ) ;
V_4 -> V_6 = V_175 ;
F_80 ( & V_175 -> V_183 ) ;
F_3 ( V_3 , V_4 ) ;
V_56 = 0 ;
}
}
V_93:
F_121 ( & V_179 ) ;
return V_56 ;
}
static void F_122 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
struct V_147 * V_148 ;
V_148 = V_4 -> V_6 ;
if ( ! V_148 )
return;
V_4 -> V_6 = NULL ;
F_113 ( & V_179 ) ;
if ( F_123 ( & V_148 -> V_183 ) ) {
F_124 ( & V_148 -> V_182 ) ;
F_125 ( & V_148 -> V_7 ) ;
F_126 ( V_148 ) ;
}
F_121 ( & V_179 ) ;
}
static int F_127 ( struct V_139 * V_133 , struct V_49 * V_50 ,
struct V_160 * V_161 , struct V_49 * V_162 )
{
struct V_2 * V_3 ;
struct V_188 * V_189 ;
V_3 = V_161 -> V_163 ;
if ( V_133 -> V_190 == V_191 )
goto V_93;
if ( ! F_105 ( F_106 ( V_50 ) , F_34 ( V_3 ) ) )
goto V_93;
V_133 = F_128 ( V_133 , V_192 ) ;
if ( V_133 == NULL )
goto V_193;
F_129 ( V_133 ) ;
F_130 ( V_133 ) ;
V_189 = & F_131 ( V_133 ) -> V_194 . V_195 ;
F_132 ( V_133 , V_133 -> V_43 - F_133 ( V_133 ) ) ;
V_189 -> V_196 = V_50 -> type ;
F_134 ( V_189 -> V_197 , V_50 -> V_198 , sizeof( V_189 -> V_197 ) ) ;
V_189 -> V_199 = V_133 -> V_200 ;
if ( F_135 ( V_3 , V_133 ) == 0 )
return 0 ;
V_93:
F_108 ( V_133 ) ;
V_193:
return 0 ;
}
static int F_136 ( struct V_201 * V_202 , struct V_203 * V_2 ,
struct V_204 * V_205 , T_5 V_138 )
{
struct V_2 * V_3 = V_2 -> V_3 ;
struct V_188 * V_206 = (struct V_188 * ) V_205 -> V_207 ;
struct V_139 * V_133 = NULL ;
struct V_49 * V_50 ;
T_6 V_208 = 0 ;
int V_56 ;
int V_209 = 0 ;
if ( V_206 ) {
if ( V_205 -> V_210 < sizeof( struct V_211 ) )
return - V_177 ;
if ( V_205 -> V_210 == sizeof( struct V_188 ) )
V_208 = V_206 -> V_199 ;
} else
return - V_212 ;
V_206 -> V_197 [ sizeof( V_206 -> V_197 ) - 1 ] = 0 ;
V_213:
F_137 () ;
V_50 = F_138 ( F_34 ( V_3 ) , V_206 -> V_197 ) ;
V_56 = - V_214 ;
if ( V_50 == NULL )
goto V_215;
V_56 = - V_216 ;
if ( ! ( V_50 -> V_217 & V_218 ) )
goto V_215;
if ( F_35 ( F_95 ( V_3 , V_219 ) ) ) {
if ( ! F_139 ( V_50 ) ) {
V_56 = - V_220 ;
goto V_215;
}
V_209 = 4 ;
}
V_56 = - V_221 ;
if ( V_138 > V_50 -> V_222 + V_50 -> V_223 + V_224 + V_209 )
goto V_215;
if ( ! V_133 ) {
T_5 V_225 = F_140 ( V_50 ) ;
int V_226 = V_50 -> V_227 ;
unsigned int V_228 = V_50 -> V_229 ? V_50 -> V_223 : 0 ;
F_141 () ;
V_133 = F_142 ( V_3 , V_138 + V_225 + V_226 , 0 , V_181 ) ;
if ( V_133 == NULL )
return - V_230 ;
F_143 ( V_133 , V_225 ) ;
F_144 ( V_133 ) ;
if ( V_228 ) {
V_133 -> V_43 -= V_228 ;
V_133 -> V_231 -= V_228 ;
if ( V_138 < V_228 )
F_144 ( V_133 ) ;
}
V_56 = F_145 ( F_146 ( V_133 , V_138 ) , V_205 -> V_232 , V_138 ) ;
if ( V_56 )
goto V_233;
goto V_213;
}
if ( V_138 > ( V_50 -> V_222 + V_50 -> V_223 + V_209 ) ) {
struct V_234 * V_235 ;
F_147 ( V_133 ) ;
V_235 = F_148 ( V_133 ) ;
if ( V_235 -> V_236 != F_149 ( V_237 ) ) {
V_56 = - V_221 ;
goto V_215;
}
}
V_133 -> V_200 = V_208 ;
V_133 -> V_50 = V_50 ;
V_133 -> V_238 = V_3 -> V_239 ;
V_133 -> V_240 = V_3 -> V_241 ;
V_56 = F_150 ( V_3 , & F_151 ( V_133 ) -> V_242 ) ;
if ( V_56 < 0 )
goto V_215;
if ( F_35 ( V_209 == 4 ) )
V_133 -> V_243 = 1 ;
F_152 ( V_133 ) ;
F_141 () ;
return V_138 ;
V_215:
F_141 () ;
V_233:
F_108 ( V_133 ) ;
return V_56 ;
}
static unsigned int F_153 ( const struct V_139 * V_133 ,
const struct V_2 * V_3 ,
unsigned int V_244 )
{
struct V_245 * V_246 ;
F_137 () ;
V_246 = F_154 ( V_3 -> V_245 ) ;
if ( V_246 != NULL )
V_244 = F_155 ( V_246 , V_133 ) ;
F_141 () ;
return V_244 ;
}
static int F_156 ( struct V_139 * V_133 , struct V_49 * V_50 ,
struct V_160 * V_161 , struct V_49 * V_162 )
{
struct V_2 * V_3 ;
struct V_247 * V_248 ;
struct V_1 * V_4 ;
T_3 * V_249 = V_133 -> V_43 ;
int V_250 = V_133 -> V_138 ;
unsigned int V_251 , V_244 ;
if ( V_133 -> V_190 == V_191 )
goto V_252;
V_3 = V_161 -> V_163 ;
V_4 = F_1 ( V_3 ) ;
if ( ! F_105 ( F_106 ( V_50 ) , F_34 ( V_3 ) ) )
goto V_252;
V_133 -> V_50 = V_50 ;
if ( V_50 -> V_229 ) {
if ( V_3 -> V_253 != V_254 )
F_132 ( V_133 , V_133 -> V_43 - F_133 ( V_133 ) ) ;
else if ( V_133 -> V_190 == V_255 ) {
F_157 ( V_133 , F_158 ( V_133 ) ) ;
}
}
V_251 = V_133 -> V_138 ;
V_244 = F_153 ( V_133 , V_3 , V_251 ) ;
if ( ! V_244 )
goto V_256;
if ( V_251 > V_244 )
V_251 = V_244 ;
if ( F_48 ( & V_3 -> V_144 ) >= V_3 -> V_257 )
goto V_258;
if ( F_159 ( V_133 ) ) {
struct V_139 * V_259 = F_160 ( V_133 , V_192 ) ;
if ( V_259 == NULL )
goto V_258;
if ( V_249 != V_133 -> V_43 ) {
V_133 -> V_43 = V_249 ;
V_133 -> V_138 = V_250 ;
}
F_161 ( V_133 ) ;
V_133 = V_259 ;
}
F_162 ( sizeof( * F_131 ( V_133 ) ) + V_260 - 8 >
sizeof( V_133 -> V_261 ) ) ;
V_248 = & F_131 ( V_133 ) -> V_194 . V_262 ;
V_248 -> V_263 = V_264 ;
V_248 -> V_265 = V_50 -> type ;
V_248 -> V_266 = V_133 -> V_200 ;
V_248 -> V_267 = V_133 -> V_190 ;
if ( F_35 ( V_4 -> V_268 ) )
V_248 -> V_269 = V_162 -> V_58 ;
else
V_248 -> V_269 = V_50 -> V_58 ;
V_248 -> V_270 = F_163 ( V_133 , V_248 -> V_271 ) ;
F_131 ( V_133 ) -> V_272 = V_133 -> V_138 ;
if ( F_164 ( V_133 , V_251 ) )
goto V_258;
F_165 ( V_133 , V_3 ) ;
V_133 -> V_50 = NULL ;
F_129 ( V_133 ) ;
F_130 ( V_133 ) ;
F_12 ( & V_3 -> V_92 . V_41 ) ;
V_4 -> V_111 . V_273 ++ ;
V_133 -> V_274 = F_48 ( & V_3 -> V_275 ) ;
F_166 ( & V_3 -> V_92 , V_133 ) ;
F_10 ( & V_3 -> V_92 . V_41 ) ;
V_3 -> V_276 ( V_3 , V_133 -> V_138 ) ;
return 0 ;
V_258:
F_12 ( & V_3 -> V_92 . V_41 ) ;
V_4 -> V_111 . V_112 ++ ;
F_80 ( & V_3 -> V_275 ) ;
F_10 ( & V_3 -> V_92 . V_41 ) ;
V_256:
if ( V_249 != V_133 -> V_43 && F_159 ( V_133 ) ) {
V_133 -> V_43 = V_249 ;
V_133 -> V_138 = V_250 ;
}
V_252:
F_161 ( V_133 ) ;
return 0 ;
}
static int F_167 ( struct V_139 * V_133 , struct V_49 * V_50 ,
struct V_160 * V_161 , struct V_49 * V_162 )
{
struct V_2 * V_3 ;
struct V_1 * V_4 ;
struct V_247 * V_248 ;
union {
struct V_12 * V_13 ;
struct V_14 * V_15 ;
struct V_106 * V_277 ;
void * V_16 ;
} V_17 ;
T_3 * V_249 = V_133 -> V_43 ;
int V_250 = V_133 -> V_138 ;
unsigned int V_251 , V_244 ;
unsigned long V_11 = V_105 ;
unsigned short V_278 , V_279 , V_78 ;
struct V_139 * V_280 = NULL ;
struct V_281 V_282 ;
struct V_121 V_122 ;
struct V_283 * V_284 = F_168 ( V_133 ) ;
if ( V_133 -> V_190 == V_191 )
goto V_252;
V_3 = V_161 -> V_163 ;
V_4 = F_1 ( V_3 ) ;
if ( ! F_105 ( F_106 ( V_50 ) , F_34 ( V_3 ) ) )
goto V_252;
if ( V_50 -> V_229 ) {
if ( V_3 -> V_253 != V_254 )
F_132 ( V_133 , V_133 -> V_43 - F_133 ( V_133 ) ) ;
else if ( V_133 -> V_190 == V_255 ) {
F_157 ( V_133 , F_158 ( V_133 ) ) ;
}
}
if ( V_133 -> V_285 == V_286 )
V_11 |= V_287 ;
V_251 = V_133 -> V_138 ;
V_244 = F_153 ( V_133 , V_3 , V_251 ) ;
if ( ! V_244 )
goto V_256;
if ( V_251 > V_244 )
V_251 = V_244 ;
if ( V_3 -> V_253 == V_254 ) {
V_278 = V_279 = F_169 ( V_4 -> V_79 ) + 16 +
V_4 -> V_288 ;
} else {
unsigned int V_289 = F_158 ( V_133 ) ;
V_279 = F_169 ( V_4 -> V_79 +
( V_289 < 16 ? 16 : V_289 ) ) +
V_4 -> V_288 ;
V_278 = V_279 - V_289 ;
}
if ( V_4 -> V_18 <= V_21 ) {
if ( V_278 + V_251 > V_4 -> V_40 . V_31 ) {
if ( V_4 -> V_290 &&
F_48 ( & V_3 -> V_144 ) < V_3 -> V_257 ) {
if ( F_159 ( V_133 ) ) {
V_280 = F_160 ( V_133 , V_192 ) ;
} else {
V_280 = F_170 ( V_133 ) ;
V_249 = V_133 -> V_43 ;
}
if ( V_280 )
F_165 ( V_280 , V_3 ) ;
}
V_251 = V_4 -> V_40 . V_31 - V_278 ;
if ( ( int ) V_251 < 0 )
V_251 = 0 ;
}
}
F_12 ( & V_3 -> V_92 . V_41 ) ;
V_17 . V_16 = F_83 ( V_4 , V_133 ,
V_126 , ( V_278 + V_251 ) ) ;
if ( ! V_17 . V_16 )
goto V_291;
if ( V_4 -> V_18 <= V_21 ) {
F_90 ( V_4 , & V_4 -> V_40 ) ;
if ( V_4 -> V_111 . V_112 )
V_11 |= V_113 ;
}
V_4 -> V_111 . V_273 ++ ;
if ( V_280 ) {
V_11 |= V_292 ;
F_166 ( & V_3 -> V_92 , V_280 ) ;
}
F_10 ( & V_3 -> V_92 . V_41 ) ;
F_171 ( V_133 , 0 , V_17 . V_16 + V_278 , V_251 ) ;
switch ( V_4 -> V_18 ) {
case V_19 :
V_17 . V_13 -> V_293 = V_133 -> V_138 ;
V_17 . V_13 -> V_294 = V_251 ;
V_17 . V_13 -> V_295 = V_278 ;
V_17 . V_13 -> V_296 = V_279 ;
if ( ( V_4 -> V_297 & V_298 )
&& V_284 -> V_299 . V_300 )
V_282 = F_172 ( V_284 -> V_299 ) ;
else if ( ( V_4 -> V_297 & V_301 )
&& V_284 -> V_302 . V_300 )
V_282 = F_172 ( V_284 -> V_302 ) ;
else if ( V_133 -> V_303 . V_300 )
V_282 = F_172 ( V_133 -> V_303 ) ;
else
F_173 ( & V_282 ) ;
V_17 . V_13 -> V_118 = V_282 . V_123 ;
V_17 . V_13 -> V_304 = V_282 . V_305 ;
V_78 = sizeof( * V_17 . V_13 ) ;
break;
case V_21 :
V_17 . V_15 -> V_293 = V_133 -> V_138 ;
V_17 . V_15 -> V_294 = V_251 ;
V_17 . V_15 -> V_295 = V_278 ;
V_17 . V_15 -> V_296 = V_279 ;
if ( ( V_4 -> V_297 & V_298 )
&& V_284 -> V_299 . V_300 )
V_122 = F_174 ( V_284 -> V_299 ) ;
else if ( ( V_4 -> V_297 & V_301 )
&& V_284 -> V_302 . V_300 )
V_122 = F_174 ( V_284 -> V_302 ) ;
else if ( V_133 -> V_303 . V_300 )
V_122 = F_174 ( V_133 -> V_303 ) ;
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
V_17 . V_15 -> V_306 = 0 ;
V_78 = sizeof( * V_17 . V_15 ) ;
break;
case V_22 :
V_17 . V_277 -> V_20 |= V_11 ;
V_17 . V_277 -> V_293 = V_133 -> V_138 ;
V_17 . V_277 -> V_294 = V_251 ;
V_17 . V_277 -> V_295 = V_278 ;
V_17 . V_277 -> V_296 = V_279 ;
if ( ( V_4 -> V_297 & V_298 )
&& V_284 -> V_299 . V_300 )
V_122 = F_174 ( V_284 -> V_299 ) ;
else if ( ( V_4 -> V_297 & V_301 )
&& V_284 -> V_302 . V_300 )
V_122 = F_174 ( V_284 -> V_302 ) ;
else if ( V_133 -> V_303 . V_300 )
V_122 = F_174 ( V_133 -> V_303 ) ;
else
F_57 ( & V_122 ) ;
V_17 . V_277 -> V_118 = V_122 . V_123 ;
V_17 . V_277 -> V_120 = V_122 . V_124 ;
V_78 = sizeof( * V_17 . V_277 ) ;
break;
default:
F_18 () ;
}
V_248 = V_17 . V_16 + F_169 ( V_78 ) ;
V_248 -> V_270 = F_163 ( V_133 , V_248 -> V_271 ) ;
V_248 -> V_263 = V_264 ;
V_248 -> V_265 = V_50 -> type ;
V_248 -> V_266 = V_133 -> V_200 ;
V_248 -> V_267 = V_133 -> V_190 ;
if ( F_35 ( V_4 -> V_268 ) )
V_248 -> V_269 = V_162 -> V_58 ;
else
V_248 -> V_269 = V_50 -> V_58 ;
F_82 () ;
#if V_99 == 1
{
T_3 * V_100 , * V_101 ;
if ( V_4 -> V_18 <= V_21 ) {
V_101 = ( T_3 * ) F_54 ( ( unsigned long ) V_17 . V_16
+ V_278 + V_251 ) ;
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
V_3 -> V_276 ( V_3 , 0 ) ;
V_256:
if ( V_249 != V_133 -> V_43 && F_159 ( V_133 ) ) {
V_133 -> V_43 = V_249 ;
V_133 -> V_138 = V_250 ;
}
V_252:
F_108 ( V_133 ) ;
return 0 ;
V_291:
V_4 -> V_111 . V_112 ++ ;
F_10 ( & V_3 -> V_92 . V_41 ) ;
V_3 -> V_276 ( V_3 , 0 ) ;
F_108 ( V_280 ) ;
goto V_256;
}
static void F_175 ( struct V_139 * V_133 )
{
struct V_1 * V_4 = F_1 ( V_133 -> V_3 ) ;
void * V_307 ;
if ( F_60 ( V_4 -> V_36 . V_29 ) ) {
V_307 = F_151 ( V_133 ) -> V_308 ;
F_110 ( F_48 ( & V_4 -> V_36 . V_309 ) == 0 ) ;
F_70 ( & V_4 -> V_36 . V_309 ) ;
F_14 ( V_4 , V_307 , V_310 ) ;
}
F_176 ( V_133 ) ;
}
static int F_177 ( struct V_1 * V_4 , struct V_139 * V_133 ,
void * V_10 , struct V_49 * V_50 , int V_311 ,
T_6 V_208 , unsigned char * V_312 , int V_313 )
{
union {
struct V_12 * V_13 ;
struct V_14 * V_15 ;
void * V_16 ;
} V_307 ;
int V_314 , V_315 , V_138 , V_293 , V_316 , V_317 ;
struct V_203 * V_2 = V_4 -> V_3 . V_318 ;
struct V_319 * V_319 ;
void * V_43 ;
int V_56 ;
V_307 . V_16 = V_10 ;
V_133 -> V_200 = V_208 ;
V_133 -> V_50 = V_50 ;
V_133 -> V_238 = V_4 -> V_3 . V_239 ;
V_133 -> V_240 = V_4 -> V_3 . V_241 ;
F_151 ( V_133 ) -> V_308 = V_307 . V_16 ;
switch ( V_4 -> V_18 ) {
case V_21 :
V_293 = V_307 . V_15 -> V_293 ;
break;
default:
V_293 = V_307 . V_13 -> V_293 ;
break;
}
if ( F_35 ( V_293 > V_311 ) ) {
F_96 ( L_6 , V_293 , V_311 ) ;
return - V_221 ;
}
F_143 ( V_133 , V_313 ) ;
F_144 ( V_133 ) ;
V_43 = V_307 . V_16 + V_4 -> V_79 - sizeof( struct V_247 ) ;
V_314 = V_293 ;
if ( V_2 -> type == V_254 ) {
V_56 = F_178 ( V_133 , V_50 , F_179 ( V_208 ) , V_312 ,
NULL , V_293 ) ;
if ( F_35 ( V_56 < 0 ) )
return - V_177 ;
} else if ( V_50 -> V_223 ) {
if ( F_35 ( V_293 <= V_50 -> V_223 ) ) {
F_96 ( L_7 ,
V_293 , V_50 -> V_223 ) ;
return - V_177 ;
}
F_132 ( V_133 , V_50 -> V_223 ) ;
V_56 = F_180 ( V_133 , 0 , V_43 ,
V_50 -> V_223 ) ;
if ( F_35 ( V_56 ) )
return V_56 ;
V_43 += V_50 -> V_223 ;
V_314 -= V_50 -> V_223 ;
}
V_56 = - V_320 ;
V_315 = F_181 ( V_43 ) ;
V_317 = V_102 - V_315 ;
V_138 = ( ( V_314 > V_317 ) ? V_317 : V_314 ) ;
V_133 -> V_321 = V_314 ;
V_133 -> V_138 += V_314 ;
V_133 -> V_322 += V_314 ;
F_182 ( V_314 , & V_4 -> V_3 . V_145 ) ;
while ( F_60 ( V_314 ) ) {
V_316 = F_151 ( V_133 ) -> V_316 ;
if ( F_35 ( V_316 >= V_323 ) ) {
F_96 ( L_8 ,
V_323 ) ;
return - V_320 ;
}
V_319 = F_16 ( V_43 ) ;
V_43 += V_138 ;
F_15 ( V_319 ) ;
F_183 ( V_319 ) ;
F_184 ( V_133 , V_316 , V_319 , V_315 , V_138 ) ;
V_314 -= V_138 ;
V_315 = 0 ;
V_317 = V_102 ;
V_138 = ( ( V_314 > V_317 ) ? V_317 : V_314 ) ;
}
return V_293 ;
}
static int F_185 ( struct V_1 * V_4 , struct V_204 * V_205 )
{
struct V_139 * V_133 ;
struct V_49 * V_50 ;
T_6 V_208 ;
bool V_324 = false ;
int V_56 , V_325 = 0 ;
void * V_307 ;
struct V_247 * V_206 = (struct V_247 * ) V_205 -> V_207 ;
int V_293 , V_311 ;
unsigned char * V_312 ;
int V_326 = 0 ;
int V_11 = 0 ;
int V_313 , V_226 ;
F_113 ( & V_4 -> V_327 ) ;
V_56 = - V_328 ;
if ( V_206 == NULL ) {
V_50 = V_4 -> V_7 . V_50 ;
V_208 = V_4 -> V_149 ;
V_312 = NULL ;
} else {
V_56 = - V_177 ;
if ( V_205 -> V_210 < sizeof( struct V_247 ) )
goto V_93;
if ( V_205 -> V_210 < ( V_206 -> V_270
+ F_186 ( struct V_247 ,
V_271 ) ) )
goto V_93;
V_208 = V_206 -> V_266 ;
V_312 = V_206 -> V_271 ;
V_50 = F_187 ( F_34 ( & V_4 -> V_3 ) , V_206 -> V_269 ) ;
V_324 = true ;
}
V_56 = - V_329 ;
if ( F_35 ( V_50 == NULL ) )
goto V_93;
V_325 = V_50 -> V_223 ;
V_56 = - V_216 ;
if ( F_35 ( ! ( V_50 -> V_217 & V_218 ) ) )
goto V_330;
V_311 = V_4 -> V_36 . V_31
- ( V_4 -> V_79 - sizeof( struct V_247 ) ) ;
if ( V_311 > V_50 -> V_222 + V_325 )
V_311 = V_50 -> V_222 + V_325 ;
do {
V_307 = F_23 ( V_4 , & V_4 -> V_36 ,
V_331 ) ;
if ( F_35 ( V_307 == NULL ) ) {
F_188 () ;
continue;
}
V_11 = V_331 ;
V_313 = F_140 ( V_50 ) ;
V_226 = V_50 -> V_227 ;
V_133 = F_189 ( & V_4 -> V_3 ,
V_313 + V_226 + sizeof( struct V_247 ) ,
0 , & V_56 ) ;
if ( F_35 ( V_133 == NULL ) )
goto V_332;
V_293 = F_177 ( V_4 , V_133 , V_307 , V_50 , V_311 , V_208 ,
V_312 , V_313 ) ;
if ( F_35 ( V_293 < 0 ) ) {
if ( V_4 -> V_333 ) {
F_14 ( V_4 , V_307 ,
V_310 ) ;
F_91 ( & V_4 -> V_36 ) ;
F_108 ( V_133 ) ;
continue;
} else {
V_11 = V_334 ;
V_56 = V_293 ;
goto V_332;
}
}
V_133 -> V_335 = F_175 ;
F_14 ( V_4 , V_307 , V_336 ) ;
F_80 ( & V_4 -> V_36 . V_309 ) ;
V_11 = V_331 ;
V_56 = F_152 ( V_133 ) ;
if ( F_35 ( V_56 > 0 ) ) {
V_56 = F_190 ( V_56 ) ;
if ( V_56 && F_20 ( V_4 , V_307 ) ==
V_310 ) {
V_133 = NULL ;
goto V_332;
}
V_56 = 0 ;
}
F_91 ( & V_4 -> V_36 ) ;
V_326 += V_293 ;
} while ( F_60 ( ( V_307 != NULL ) ||
( ( ! ( V_205 -> V_337 & V_338 ) ) &&
( F_48 ( & V_4 -> V_36 . V_309 ) ) ) )
);
V_56 = V_326 ;
goto V_330;
V_332:
F_14 ( V_4 , V_307 , V_11 ) ;
F_108 ( V_133 ) ;
V_330:
if ( V_324 )
F_191 ( V_50 ) ;
V_93:
F_121 ( & V_4 -> V_327 ) ;
return V_56 ;
}
static struct V_139 * F_192 ( struct V_2 * V_3 , T_5 V_339 ,
T_5 V_325 , T_5 V_138 ,
T_5 V_340 , int V_341 ,
int * V_56 )
{
struct V_139 * V_133 ;
if ( V_339 + V_138 < V_102 || ! V_340 )
V_340 = V_138 ;
V_133 = F_193 ( V_3 , V_339 + V_340 , V_138 - V_340 , V_341 ,
V_56 ) ;
if ( ! V_133 )
return NULL ;
F_143 ( V_133 , V_325 ) ;
F_146 ( V_133 , V_340 ) ;
V_133 -> V_321 = V_138 - V_340 ;
V_133 -> V_138 += V_138 - V_340 ;
return V_133 ;
}
static int F_194 ( struct V_203 * V_2 ,
struct V_204 * V_205 , T_5 V_138 )
{
struct V_2 * V_3 = V_2 -> V_3 ;
struct V_247 * V_206 = (struct V_247 * ) V_205 -> V_207 ;
struct V_139 * V_133 ;
struct V_49 * V_50 ;
T_6 V_208 ;
bool V_324 = false ;
unsigned char * V_312 ;
int V_56 , V_325 = 0 ;
struct V_342 V_343 = { 0 } ;
int V_315 = 0 ;
int V_344 ;
struct V_1 * V_4 = F_1 ( V_3 ) ;
unsigned short V_345 = 0 ;
int V_313 , V_226 ;
int V_209 = 0 ;
if ( V_206 == NULL ) {
V_50 = V_4 -> V_7 . V_50 ;
V_208 = V_4 -> V_149 ;
V_312 = NULL ;
} else {
V_56 = - V_177 ;
if ( V_205 -> V_210 < sizeof( struct V_247 ) )
goto V_93;
if ( V_205 -> V_210 < ( V_206 -> V_270 + F_186 ( struct V_247 , V_271 ) ) )
goto V_93;
V_208 = V_206 -> V_266 ;
V_312 = V_206 -> V_271 ;
V_50 = F_187 ( F_34 ( V_3 ) , V_206 -> V_269 ) ;
V_324 = true ;
}
V_56 = - V_329 ;
if ( V_50 == NULL )
goto V_215;
if ( V_2 -> type == V_346 )
V_325 = V_50 -> V_223 ;
V_56 = - V_216 ;
if ( ! ( V_50 -> V_217 & V_218 ) )
goto V_215;
if ( V_4 -> V_347 ) {
V_344 = sizeof( V_343 ) ;
V_56 = - V_177 ;
if ( V_138 < V_344 )
goto V_215;
V_138 -= V_344 ;
V_56 = F_145 ( ( void * ) & V_343 , V_205 -> V_232 ,
V_344 ) ;
if ( V_56 < 0 )
goto V_215;
if ( ( V_343 . V_217 & V_348 ) &&
( V_343 . V_349 + V_343 . V_350 + 2 >
V_343 . V_351 ) )
V_343 . V_351 = V_343 . V_349 +
V_343 . V_350 + 2 ;
V_56 = - V_177 ;
if ( V_343 . V_351 > V_138 )
goto V_215;
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
goto V_215;
}
if ( V_343 . V_345 & V_353 )
V_345 |= V_360 ;
if ( V_343 . V_361 == 0 )
goto V_215;
}
}
if ( F_35 ( F_95 ( V_3 , V_219 ) ) ) {
if ( ! F_139 ( V_50 ) ) {
V_56 = - V_220 ;
goto V_215;
}
V_209 = 4 ;
}
V_56 = - V_221 ;
if ( ! V_345 && ( V_138 > V_50 -> V_222 + V_325 + V_224 + V_209 ) )
goto V_215;
V_56 = - V_230 ;
V_313 = F_140 ( V_50 ) ;
V_226 = V_50 -> V_227 ;
V_133 = F_192 ( V_3 , V_313 + V_226 , V_313 , V_138 , V_343 . V_351 ,
V_205 -> V_337 & V_338 , & V_56 ) ;
if ( V_133 == NULL )
goto V_215;
F_195 ( V_133 , V_325 ) ;
V_56 = - V_177 ;
if ( V_2 -> type == V_254 &&
( V_315 = F_178 ( V_133 , V_50 , F_179 ( V_208 ) , V_312 , NULL , V_138 ) ) < 0 )
goto V_233;
V_56 = F_196 ( V_133 , V_315 , V_205 -> V_232 , 0 , V_138 ) ;
if ( V_56 )
goto V_233;
V_56 = F_150 ( V_3 , & F_151 ( V_133 ) -> V_242 ) ;
if ( V_56 < 0 )
goto V_233;
if ( ! V_345 && ( V_138 > V_50 -> V_222 + V_325 + V_209 ) ) {
struct V_234 * V_235 ;
F_147 ( V_133 ) ;
V_235 = F_148 ( V_133 ) ;
if ( V_235 -> V_236 != F_149 ( V_237 ) ) {
V_56 = - V_221 ;
goto V_233;
}
}
V_133 -> V_200 = V_208 ;
V_133 -> V_50 = V_50 ;
V_133 -> V_238 = V_3 -> V_239 ;
V_133 -> V_240 = V_3 -> V_241 ;
if ( V_4 -> V_347 ) {
if ( V_343 . V_217 & V_348 ) {
if ( ! F_197 ( V_133 , V_343 . V_349 ,
V_343 . V_350 ) ) {
V_56 = - V_177 ;
goto V_233;
}
}
F_151 ( V_133 ) -> V_361 = V_343 . V_361 ;
F_151 ( V_133 ) -> V_345 = V_345 ;
F_151 ( V_133 ) -> V_345 |= V_362 ;
F_151 ( V_133 ) -> V_363 = 0 ;
V_138 += V_344 ;
}
if ( F_35 ( V_209 == 4 ) )
V_133 -> V_243 = 1 ;
V_56 = F_152 ( V_133 ) ;
if ( V_56 > 0 && ( V_56 = F_190 ( V_56 ) ) != 0 )
goto V_215;
if ( V_324 )
F_191 ( V_50 ) ;
return V_138 ;
V_233:
F_108 ( V_133 ) ;
V_215:
if ( V_50 && V_324 )
F_191 ( V_50 ) ;
V_93:
return V_56 ;
}
static int F_198 ( struct V_201 * V_202 , struct V_203 * V_2 ,
struct V_204 * V_205 , T_5 V_138 )
{
struct V_2 * V_3 = V_2 -> V_3 ;
struct V_1 * V_4 = F_1 ( V_3 ) ;
if ( V_4 -> V_36 . V_29 )
return F_185 ( V_4 , V_205 ) ;
else
return F_194 ( V_2 , V_205 , V_138 ) ;
}
static int F_199 ( struct V_203 * V_2 )
{
struct V_2 * V_3 = V_2 -> V_3 ;
struct V_1 * V_4 ;
struct V_165 * V_165 ;
union V_63 V_64 ;
if ( ! V_3 )
return 0 ;
V_165 = F_34 ( V_3 ) ;
V_4 = F_1 ( V_3 ) ;
F_200 ( & V_165 -> V_364 . V_365 ) ;
F_201 ( V_3 ) ;
F_202 ( V_165 , V_3 -> V_366 , - 1 ) ;
F_203 ( & V_165 -> V_364 . V_365 ) ;
F_12 ( & V_4 -> V_9 ) ;
F_13 ( V_3 , false ) ;
if ( V_4 -> V_7 . V_50 ) {
F_191 ( V_4 -> V_7 . V_50 ) ;
V_4 -> V_7 . V_50 = NULL ;
}
F_10 ( & V_4 -> V_9 ) ;
F_204 ( V_3 ) ;
memset ( & V_64 , 0 , sizeof( V_64 ) ) ;
if ( V_4 -> V_40 . V_29 )
F_205 ( V_3 , & V_64 , 1 , 0 ) ;
if ( V_4 -> V_36 . V_29 )
F_205 ( V_3 , & V_64 , 1 , 1 ) ;
F_122 ( V_3 ) ;
F_11 () ;
F_206 ( V_3 ) ;
V_2 -> V_3 = NULL ;
F_93 ( & V_3 -> V_92 ) ;
F_207 ( V_3 ) ;
F_208 ( V_3 ) ;
return 0 ;
}
static int F_209 ( struct V_2 * V_3 , struct V_49 * V_50 , T_6 V_200 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
if ( V_4 -> V_6 ) {
if ( V_50 )
F_191 ( V_50 ) ;
return - V_177 ;
}
F_210 ( V_3 ) ;
F_12 ( & V_4 -> V_9 ) ;
F_13 ( V_3 , true ) ;
V_4 -> V_149 = V_200 ;
V_4 -> V_7 . type = V_200 ;
if ( V_4 -> V_7 . V_50 )
F_191 ( V_4 -> V_7 . V_50 ) ;
V_4 -> V_7 . V_50 = V_50 ;
V_4 -> V_58 = V_50 ? V_50 -> V_58 : 0 ;
if ( V_200 == 0 )
goto V_215;
if ( ! V_50 || ( V_50 -> V_217 & V_218 ) ) {
F_2 ( V_3 ) ;
} else {
V_3 -> V_367 = V_216 ;
if ( ! F_95 ( V_3 , V_146 ) )
V_3 -> V_368 ( V_3 ) ;
}
V_215:
F_10 ( & V_4 -> V_9 ) ;
F_211 ( V_3 ) ;
return 0 ;
}
static int F_212 ( struct V_203 * V_2 , struct V_211 * V_369 ,
int V_370 )
{
struct V_2 * V_3 = V_2 -> V_3 ;
char V_198 [ 15 ] ;
struct V_49 * V_50 ;
int V_56 = - V_214 ;
if ( V_370 != sizeof( struct V_211 ) )
return - V_177 ;
F_134 ( V_198 , V_369 -> V_371 , sizeof( V_198 ) ) ;
V_50 = F_213 ( F_34 ( V_3 ) , V_198 ) ;
if ( V_50 )
V_56 = F_209 ( V_3 , V_50 , F_1 ( V_3 ) -> V_149 ) ;
return V_56 ;
}
static int F_214 ( struct V_203 * V_2 , struct V_211 * V_369 , int V_370 )
{
struct V_247 * V_248 = (struct V_247 * ) V_369 ;
struct V_2 * V_3 = V_2 -> V_3 ;
struct V_49 * V_50 = NULL ;
int V_56 ;
if ( V_370 < sizeof( struct V_247 ) )
return - V_177 ;
if ( V_248 -> V_263 != V_264 )
return - V_177 ;
if ( V_248 -> V_269 ) {
V_56 = - V_214 ;
V_50 = F_187 ( F_34 ( V_3 ) , V_248 -> V_269 ) ;
if ( V_50 == NULL )
goto V_93;
}
V_56 = F_209 ( V_3 , V_50 , V_248 -> V_266 ? : F_1 ( V_3 ) -> V_149 ) ;
V_93:
return V_56 ;
}
static int F_215 ( struct V_165 * V_165 , struct V_203 * V_2 , int V_200 ,
int V_372 )
{
struct V_2 * V_3 ;
struct V_1 * V_4 ;
T_6 V_208 = ( V_373 T_6 ) V_200 ;
int V_56 ;
if ( ! F_216 ( V_374 ) )
return - V_375 ;
if ( V_2 -> type != V_254 && V_2 -> type != V_346 &&
V_2 -> type != V_376 )
return - V_377 ;
V_2 -> V_378 = V_379 ;
V_56 = - V_230 ;
V_3 = F_217 ( V_165 , V_380 , V_181 , & V_381 ) ;
if ( V_3 == NULL )
goto V_93;
V_2 -> V_382 = & V_383 ;
if ( V_2 -> type == V_376 )
V_2 -> V_382 = & V_384 ;
F_218 ( V_2 , V_3 ) ;
V_4 = F_1 ( V_3 ) ;
V_3 -> V_385 = V_380 ;
V_4 -> V_149 = V_208 ;
V_3 -> V_386 = F_92 ;
F_219 ( V_3 ) ;
F_119 ( & V_4 -> V_9 ) ;
F_220 ( & V_4 -> V_327 ) ;
V_4 -> V_7 . F_28 = F_156 ;
if ( V_2 -> type == V_376 )
V_4 -> V_7 . F_28 = F_127 ;
V_4 -> V_7 . V_163 = V_3 ;
if ( V_208 ) {
V_4 -> V_7 . type = V_208 ;
F_2 ( V_3 ) ;
}
F_200 ( & V_165 -> V_364 . V_365 ) ;
F_221 ( V_3 , & V_165 -> V_364 . V_387 ) ;
F_202 ( V_165 , & V_381 , 1 ) ;
F_203 ( & V_165 -> V_364 . V_365 ) ;
return 0 ;
V_93:
return V_56 ;
}
static int F_222 ( struct V_2 * V_3 , struct V_204 * V_205 , int V_138 )
{
struct V_388 * V_389 ;
struct V_139 * V_133 , * V_390 ;
int V_391 , V_56 ;
V_56 = - V_392 ;
V_133 = F_223 ( & V_3 -> V_143 ) ;
if ( V_133 == NULL )
goto V_93;
V_391 = V_133 -> V_138 ;
if ( V_391 > V_138 ) {
V_205 -> V_337 |= V_393 ;
V_391 = V_138 ;
}
V_56 = F_224 ( V_133 , 0 , V_205 -> V_232 , V_391 ) ;
if ( V_56 )
goto V_394;
F_225 ( V_205 , V_3 , V_133 ) ;
V_389 = F_226 ( V_133 ) ;
F_227 ( V_205 , V_395 , V_396 ,
sizeof( V_389 -> V_397 ) , & V_389 -> V_397 ) ;
V_205 -> V_337 |= V_398 ;
V_56 = V_391 ;
F_200 ( & V_3 -> V_143 . V_41 ) ;
V_3 -> V_367 = 0 ;
if ( ( V_390 = F_228 ( & V_3 -> V_143 ) ) != NULL ) {
V_3 -> V_367 = F_226 ( V_390 ) -> V_397 . V_399 ;
F_203 ( & V_3 -> V_143 . V_41 ) ;
V_3 -> V_368 ( V_3 ) ;
} else
F_203 ( & V_3 -> V_143 . V_41 ) ;
V_394:
F_108 ( V_133 ) ;
V_93:
return V_56 ;
}
static int F_229 ( struct V_201 * V_202 , struct V_203 * V_2 ,
struct V_204 * V_205 , T_5 V_138 , int V_217 )
{
struct V_2 * V_3 = V_2 -> V_3 ;
struct V_139 * V_133 ;
int V_391 , V_56 ;
struct V_247 * V_248 ;
int V_344 = 0 ;
V_56 = - V_177 ;
if ( V_217 & ~ ( V_400 | V_338 | V_393 | V_401 | V_398 ) )
goto V_93;
#if 0
if (pkt_sk(sk)->ifindex < 0)
return -ENODEV;
#endif
if ( V_217 & V_398 ) {
V_56 = F_222 ( V_3 , V_205 , V_138 ) ;
goto V_93;
}
V_133 = F_230 ( V_3 , V_217 , V_217 & V_338 , & V_56 ) ;
if ( V_133 == NULL )
goto V_93;
if ( F_1 ( V_3 ) -> V_347 ) {
struct V_342 V_343 = { 0 } ;
V_56 = - V_177 ;
V_344 = sizeof( V_343 ) ;
if ( V_138 < V_344 )
goto V_233;
V_138 -= V_344 ;
if ( F_231 ( V_133 ) ) {
struct V_402 * V_403 = F_151 ( V_133 ) ;
V_343 . V_351 = F_232 ( V_133 ) ;
V_343 . V_361 = V_403 -> V_361 ;
if ( V_403 -> V_345 & V_355 )
V_343 . V_345 = V_354 ;
else if ( V_403 -> V_345 & V_357 )
V_343 . V_345 = V_356 ;
else if ( V_403 -> V_345 & V_359 )
V_343 . V_345 = V_358 ;
else if ( V_403 -> V_345 & V_404 )
goto V_233;
else
F_18 () ;
if ( V_403 -> V_345 & V_360 )
V_343 . V_345 |= V_353 ;
} else
V_343 . V_345 = V_352 ;
if ( V_133 -> V_285 == V_286 ) {
V_343 . V_217 = V_348 ;
V_343 . V_349 = F_233 ( V_133 ) ;
V_343 . V_350 = V_133 -> V_350 ;
} else if ( V_133 -> V_285 == V_405 ) {
V_343 . V_217 = V_406 ;
}
V_56 = F_234 ( V_205 -> V_232 , ( void * ) & V_343 ,
V_344 ) ;
if ( V_56 < 0 )
goto V_233;
}
V_248 = & F_131 ( V_133 ) -> V_194 . V_262 ;
if ( V_2 -> type == V_376 )
V_205 -> V_210 = sizeof( struct V_188 ) ;
else
V_205 -> V_210 = V_248 -> V_270 + F_186 ( struct V_247 , V_271 ) ;
V_391 = V_133 -> V_138 ;
if ( V_391 > V_138 ) {
V_391 = V_138 ;
V_205 -> V_337 |= V_393 ;
}
V_56 = F_224 ( V_133 , 0 , V_205 -> V_232 , V_391 ) ;
if ( V_56 )
goto V_233;
F_235 ( V_205 , V_3 , V_133 ) ;
if ( V_205 -> V_207 )
memcpy ( V_205 -> V_207 , & F_131 ( V_133 ) -> V_194 ,
V_205 -> V_210 ) ;
if ( F_1 ( V_3 ) -> V_407 ) {
struct V_408 V_409 ;
V_409 . V_20 = V_105 ;
if ( V_133 -> V_285 == V_286 )
V_409 . V_20 |= V_287 ;
V_409 . V_293 = F_131 ( V_133 ) -> V_272 ;
V_409 . V_294 = V_133 -> V_138 ;
V_409 . V_295 = 0 ;
V_409 . V_296 = F_158 ( V_133 ) ;
if ( F_75 ( V_133 ) ) {
V_409 . V_134 = F_76 ( V_133 ) ;
V_409 . V_20 |= V_135 ;
} else {
V_409 . V_134 = 0 ;
}
V_409 . V_306 = 0 ;
F_227 ( V_205 , V_395 , V_410 , sizeof( V_409 ) , & V_409 ) ;
}
V_56 = V_344 + ( ( V_217 & V_393 ) ? V_133 -> V_138 : V_391 ) ;
V_233:
F_236 ( V_3 , V_133 ) ;
V_93:
return V_56 ;
}
static int F_237 ( struct V_203 * V_2 , struct V_211 * V_369 ,
int * V_411 , int V_412 )
{
struct V_49 * V_50 ;
struct V_2 * V_3 = V_2 -> V_3 ;
if ( V_412 )
return - V_413 ;
V_369 -> V_414 = V_264 ;
F_137 () ;
V_50 = F_238 ( F_34 ( V_3 ) , F_1 ( V_3 ) -> V_58 ) ;
if ( V_50 )
strncpy ( V_369 -> V_371 , V_50 -> V_198 , 14 ) ;
else
memset ( V_369 -> V_371 , 0 , 14 ) ;
F_141 () ;
* V_411 = sizeof( * V_369 ) ;
return 0 ;
}
static int F_239 ( struct V_203 * V_2 , struct V_211 * V_369 ,
int * V_411 , int V_412 )
{
struct V_49 * V_50 ;
struct V_2 * V_3 = V_2 -> V_3 ;
struct V_1 * V_4 = F_1 ( V_3 ) ;
F_240 ( struct V_247 * , V_248 , V_369 ) ;
if ( V_412 )
return - V_413 ;
V_248 -> V_263 = V_264 ;
V_248 -> V_269 = V_4 -> V_58 ;
V_248 -> V_266 = V_4 -> V_149 ;
V_248 -> V_267 = 0 ;
F_137 () ;
V_50 = F_238 ( F_34 ( V_3 ) , V_4 -> V_58 ) ;
if ( V_50 ) {
V_248 -> V_265 = V_50 -> type ;
V_248 -> V_270 = V_50 -> V_370 ;
memcpy ( V_248 -> V_271 , V_50 -> V_415 , V_50 -> V_370 ) ;
} else {
V_248 -> V_265 = 0 ;
V_248 -> V_270 = 0 ;
}
F_141 () ;
* V_411 = F_186 ( struct V_247 , V_271 ) + V_248 -> V_270 ;
return 0 ;
}
static int F_241 ( struct V_49 * V_50 , struct V_416 * V_171 ,
int V_417 )
{
switch ( V_171 -> type ) {
case V_418 :
if ( V_171 -> V_419 != V_50 -> V_370 )
return - V_177 ;
if ( V_417 > 0 )
return F_242 ( V_50 , V_171 -> V_312 ) ;
else
return F_243 ( V_50 , V_171 -> V_312 ) ;
break;
case V_420 :
return F_244 ( V_50 , V_417 ) ;
break;
case V_421 :
return F_245 ( V_50 , V_417 ) ;
break;
case V_422 :
if ( V_171 -> V_419 != V_50 -> V_370 )
return - V_177 ;
if ( V_417 > 0 )
return F_246 ( V_50 , V_171 -> V_312 ) ;
else
return F_247 ( V_50 , V_171 -> V_312 ) ;
break;
default:
break;
}
return 0 ;
}
static void F_248 ( struct V_49 * V_50 , struct V_416 * V_171 , int V_417 )
{
for ( ; V_171 ; V_171 = V_171 -> V_423 ) {
if ( V_171 -> V_58 == V_50 -> V_58 )
F_241 ( V_50 , V_171 , V_417 ) ;
}
}
static int F_249 ( struct V_2 * V_3 , struct V_424 * V_425 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
struct V_416 * V_426 , * V_171 ;
struct V_49 * V_50 ;
int V_56 ;
F_32 () ;
V_56 = - V_214 ;
V_50 = F_33 ( F_34 ( V_3 ) , V_425 -> V_427 ) ;
if ( ! V_50 )
goto V_428;
V_56 = - V_177 ;
if ( V_425 -> V_429 > V_50 -> V_370 )
goto V_428;
V_56 = - V_230 ;
V_171 = F_250 ( sizeof( * V_171 ) , V_181 ) ;
if ( V_171 == NULL )
goto V_428;
V_56 = 0 ;
for ( V_426 = V_4 -> V_430 ; V_426 ; V_426 = V_426 -> V_423 ) {
if ( V_426 -> V_58 == V_425 -> V_427 &&
V_426 -> type == V_425 -> V_431 &&
V_426 -> V_419 == V_425 -> V_429 &&
memcmp ( V_426 -> V_312 , V_425 -> V_432 , V_426 -> V_419 ) == 0 ) {
V_426 -> V_433 ++ ;
F_126 ( V_171 ) ;
goto V_428;
}
}
V_171 -> type = V_425 -> V_431 ;
V_171 -> V_58 = V_425 -> V_427 ;
V_171 -> V_419 = V_425 -> V_429 ;
memcpy ( V_171 -> V_312 , V_425 -> V_432 , V_171 -> V_419 ) ;
V_171 -> V_433 = 1 ;
V_171 -> V_423 = V_4 -> V_430 ;
V_4 -> V_430 = V_171 ;
V_56 = F_241 ( V_50 , V_171 , 1 ) ;
if ( V_56 ) {
V_4 -> V_430 = V_171 -> V_423 ;
F_126 ( V_171 ) ;
}
V_428:
F_36 () ;
return V_56 ;
}
static int F_251 ( struct V_2 * V_3 , struct V_424 * V_425 )
{
struct V_416 * V_426 , * * V_434 ;
F_32 () ;
for ( V_434 = & F_1 ( V_3 ) -> V_430 ; ( V_426 = * V_434 ) != NULL ; V_434 = & V_426 -> V_423 ) {
if ( V_426 -> V_58 == V_425 -> V_427 &&
V_426 -> type == V_425 -> V_431 &&
V_426 -> V_419 == V_425 -> V_429 &&
memcmp ( V_426 -> V_312 , V_425 -> V_432 , V_426 -> V_419 ) == 0 ) {
if ( -- V_426 -> V_433 == 0 ) {
struct V_49 * V_50 ;
* V_434 = V_426 -> V_423 ;
V_50 = F_33 ( F_34 ( V_3 ) , V_426 -> V_58 ) ;
if ( V_50 )
F_241 ( V_50 , V_426 , - 1 ) ;
F_126 ( V_426 ) ;
}
F_36 () ;
return 0 ;
}
}
F_36 () ;
return - V_435 ;
}
static void F_204 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
struct V_416 * V_426 ;
if ( ! V_4 -> V_430 )
return;
F_32 () ;
while ( ( V_426 = V_4 -> V_430 ) != NULL ) {
struct V_49 * V_50 ;
V_4 -> V_430 = V_426 -> V_423 ;
V_50 = F_33 ( F_34 ( V_3 ) , V_426 -> V_58 ) ;
if ( V_50 != NULL )
F_241 ( V_50 , V_426 , - 1 ) ;
F_126 ( V_426 ) ;
}
F_36 () ;
}
static int
F_252 ( struct V_203 * V_2 , int V_436 , int V_437 , char T_7 * V_438 , unsigned int V_439 )
{
struct V_2 * V_3 = V_2 -> V_3 ;
struct V_1 * V_4 = F_1 ( V_3 ) ;
int V_440 ;
if ( V_436 != V_395 )
return - V_441 ;
switch ( V_437 ) {
case V_442 :
case V_443 :
{
struct V_424 V_425 ;
int V_138 = V_439 ;
memset ( & V_425 , 0 , sizeof( V_425 ) ) ;
if ( V_138 < sizeof( struct V_444 ) )
return - V_177 ;
if ( V_138 > sizeof( V_425 ) )
V_138 = sizeof( V_425 ) ;
if ( F_253 ( & V_425 , V_438 , V_138 ) )
return - V_320 ;
if ( V_138 < ( V_425 . V_429 + F_186 ( struct V_444 , V_432 ) ) )
return - V_177 ;
if ( V_437 == V_442 )
V_440 = F_249 ( V_3 , & V_425 ) ;
else
V_440 = F_251 ( V_3 , & V_425 ) ;
return V_440 ;
}
case V_445 :
case V_446 :
{
union V_63 V_64 ;
int V_138 ;
switch ( V_4 -> V_18 ) {
case V_19 :
case V_21 :
V_138 = sizeof( V_64 . V_447 ) ;
break;
case V_22 :
default:
V_138 = sizeof( V_64 . V_66 ) ;
break;
}
if ( V_439 < V_138 )
return - V_177 ;
if ( F_1 ( V_3 ) -> V_347 )
return - V_177 ;
if ( F_253 ( & V_64 . V_447 , V_438 , V_138 ) )
return - V_320 ;
return F_205 ( V_3 , & V_64 , 0 ,
V_437 == V_446 ) ;
}
case V_448 :
{
int V_449 ;
if ( V_439 != sizeof( V_449 ) )
return - V_177 ;
if ( F_253 ( & V_449 , V_438 , sizeof( V_449 ) ) )
return - V_320 ;
F_1 ( V_3 ) -> V_290 = V_449 ;
return 0 ;
}
case V_450 :
{
int V_449 ;
if ( V_439 != sizeof( V_449 ) )
return - V_177 ;
if ( V_4 -> V_40 . V_29 || V_4 -> V_36 . V_29 )
return - V_328 ;
if ( F_253 ( & V_449 , V_438 , sizeof( V_449 ) ) )
return - V_320 ;
switch ( V_449 ) {
case V_19 :
case V_21 :
case V_22 :
V_4 -> V_18 = V_449 ;
return 0 ;
default:
return - V_177 ;
}
}
case V_451 :
{
unsigned int V_449 ;
if ( V_439 != sizeof( V_449 ) )
return - V_177 ;
if ( V_4 -> V_40 . V_29 || V_4 -> V_36 . V_29 )
return - V_328 ;
if ( F_253 ( & V_449 , V_438 , sizeof( V_449 ) ) )
return - V_320 ;
V_4 -> V_288 = V_449 ;
return 0 ;
}
case V_452 :
{
unsigned int V_449 ;
if ( V_439 != sizeof( V_449 ) )
return - V_177 ;
if ( V_4 -> V_40 . V_29 || V_4 -> V_36 . V_29 )
return - V_328 ;
if ( F_253 ( & V_449 , V_438 , sizeof( V_449 ) ) )
return - V_320 ;
V_4 -> V_333 = ! ! V_449 ;
return 0 ;
}
case V_410 :
{
int V_449 ;
if ( V_439 < sizeof( V_449 ) )
return - V_177 ;
if ( F_253 ( & V_449 , V_438 , sizeof( V_449 ) ) )
return - V_320 ;
V_4 -> V_407 = ! ! V_449 ;
return 0 ;
}
case V_453 :
{
int V_449 ;
if ( V_439 < sizeof( V_449 ) )
return - V_177 ;
if ( F_253 ( & V_449 , V_438 , sizeof( V_449 ) ) )
return - V_320 ;
V_4 -> V_268 = ! ! V_449 ;
return 0 ;
}
case V_454 :
{
int V_449 ;
if ( V_2 -> type != V_346 )
return - V_177 ;
if ( V_4 -> V_40 . V_29 || V_4 -> V_36 . V_29 )
return - V_328 ;
if ( V_439 < sizeof( V_449 ) )
return - V_177 ;
if ( F_253 ( & V_449 , V_438 , sizeof( V_449 ) ) )
return - V_320 ;
V_4 -> V_347 = ! ! V_449 ;
return 0 ;
}
case V_455 :
{
int V_449 ;
if ( V_439 != sizeof( V_449 ) )
return - V_177 ;
if ( F_253 ( & V_449 , V_438 , sizeof( V_449 ) ) )
return - V_320 ;
V_4 -> V_297 = V_449 ;
return 0 ;
}
case V_456 :
{
int V_449 ;
if ( V_439 != sizeof( V_449 ) )
return - V_177 ;
if ( F_253 ( & V_449 , V_438 , sizeof( V_449 ) ) )
return - V_320 ;
return F_112 ( V_3 , V_449 & 0xffff , V_449 >> 16 ) ;
}
default:
return - V_441 ;
}
}
static int F_254 ( struct V_203 * V_2 , int V_436 , int V_437 ,
char T_7 * V_438 , int T_7 * V_439 )
{
int V_138 ;
int V_449 , V_457 = sizeof( V_449 ) ;
struct V_2 * V_3 = V_2 -> V_3 ;
struct V_1 * V_4 = F_1 ( V_3 ) ;
void * V_43 = & V_449 ;
struct V_458 V_459 ;
union V_460 V_461 ;
if ( V_436 != V_395 )
return - V_441 ;
if ( F_255 ( V_138 , V_439 ) )
return - V_320 ;
if ( V_138 < 0 )
return - V_177 ;
switch ( V_437 ) {
case V_462 :
F_200 ( & V_3 -> V_92 . V_41 ) ;
if ( V_4 -> V_18 == V_22 ) {
V_457 = sizeof( struct V_463 ) ;
memcpy ( & V_461 . V_83 , & V_4 -> V_111 ,
sizeof( struct V_458 ) ) ;
V_461 . V_83 . V_84 =
V_4 -> V_82 . V_83 . V_84 ;
V_461 . V_83 . V_273 += V_4 -> V_111 . V_112 ;
V_43 = & V_461 . V_83 ;
} else {
V_457 = sizeof( struct V_458 ) ;
V_459 = V_4 -> V_111 ;
V_459 . V_273 += V_459 . V_112 ;
V_43 = & V_459 ;
}
memset ( & V_4 -> V_111 , 0 , sizeof( V_459 ) ) ;
F_203 ( & V_3 -> V_92 . V_41 ) ;
break;
case V_410 :
V_449 = V_4 -> V_407 ;
break;
case V_453 :
V_449 = V_4 -> V_268 ;
break;
case V_454 :
V_449 = V_4 -> V_347 ;
break;
case V_450 :
V_449 = V_4 -> V_18 ;
break;
case V_464 :
if ( V_138 > sizeof( int ) )
V_138 = sizeof( int ) ;
if ( F_253 ( & V_449 , V_438 , V_138 ) )
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
return - V_177 ;
}
break;
case V_451 :
V_449 = V_4 -> V_288 ;
break;
case V_452 :
V_449 = V_4 -> V_333 ;
break;
case V_455 :
V_449 = V_4 -> V_297 ;
break;
case V_456 :
V_449 = ( V_4 -> V_6 ?
( ( T_1 ) V_4 -> V_6 -> V_173 |
( ( T_1 ) V_4 -> V_6 -> type << 16 ) ) :
0 ) ;
break;
default:
return - V_441 ;
}
if ( V_138 > V_457 )
V_138 = V_457 ;
if ( F_256 ( V_138 , V_439 ) )
return - V_320 ;
if ( F_257 ( V_438 , V_43 , V_138 ) )
return - V_320 ;
return 0 ;
}
static int F_258 ( struct V_465 * V_466 , unsigned long V_205 , void * V_43 )
{
struct V_2 * V_3 ;
struct V_467 * V_468 ;
struct V_49 * V_50 = V_43 ;
struct V_165 * V_165 = F_106 ( V_50 ) ;
F_137 () ;
F_259 (sk, node, &net->packet.sklist) {
struct V_1 * V_4 = F_1 ( V_3 ) ;
switch ( V_205 ) {
case V_469 :
if ( V_4 -> V_430 )
F_248 ( V_50 , V_4 -> V_430 , - 1 ) ;
case V_470 :
if ( V_50 -> V_58 == V_4 -> V_58 ) {
F_12 ( & V_4 -> V_9 ) ;
if ( V_4 -> V_5 ) {
F_6 ( V_3 , false ) ;
V_3 -> V_367 = V_216 ;
if ( ! F_95 ( V_3 , V_146 ) )
V_3 -> V_368 ( V_3 ) ;
}
if ( V_205 == V_469 ) {
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
if ( V_4 -> V_149 )
F_2 ( V_3 ) ;
F_10 ( & V_4 -> V_9 ) ;
}
break;
}
}
F_141 () ;
return V_472 ;
}
static int F_260 ( struct V_203 * V_2 , unsigned int V_473 ,
unsigned long V_474 )
{
struct V_2 * V_3 = V_2 -> V_3 ;
switch ( V_473 ) {
case V_475 :
{
int V_476 = F_261 ( V_3 ) ;
return F_256 ( V_476 , ( int T_7 * ) V_474 ) ;
}
case V_477 :
{
struct V_139 * V_133 ;
int V_476 = 0 ;
F_200 ( & V_3 -> V_92 . V_41 ) ;
V_133 = F_228 ( & V_3 -> V_92 ) ;
if ( V_133 )
V_476 = V_133 -> V_138 ;
F_203 ( & V_3 -> V_92 . V_41 ) ;
return F_256 ( V_476 , ( int T_7 * ) V_474 ) ;
}
case V_478 :
return F_262 ( V_3 , (struct V_281 T_7 * ) V_474 ) ;
case V_479 :
return F_263 ( V_3 , (struct V_121 T_7 * ) V_474 ) ;
#ifdef F_264
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
return V_494 . V_495 ( V_2 , V_473 , V_474 ) ;
#endif
default:
return - V_496 ;
}
return 0 ;
}
static unsigned int F_265 ( struct V_497 * V_497 , struct V_203 * V_2 ,
T_8 * V_498 )
{
struct V_2 * V_3 = V_2 -> V_3 ;
struct V_1 * V_4 = F_1 ( V_3 ) ;
unsigned int V_499 = F_266 ( V_497 , V_2 , V_498 ) ;
F_200 ( & V_3 -> V_92 . V_41 ) ;
if ( V_4 -> V_40 . V_29 ) {
if ( ! F_88 ( V_4 , & V_4 -> V_40 ,
V_126 ) )
V_499 |= V_500 | V_501 ;
}
F_203 ( & V_3 -> V_92 . V_41 ) ;
F_200 ( & V_3 -> V_502 . V_41 ) ;
if ( V_4 -> V_36 . V_29 ) {
if ( F_23 ( V_4 , & V_4 -> V_36 , V_310 ) )
V_499 |= V_503 | V_504 ;
}
F_203 ( & V_3 -> V_502 . V_41 ) ;
return V_499 ;
}
static void F_267 ( struct V_505 * V_506 )
{
struct V_497 * V_497 = V_506 -> V_507 ;
struct V_203 * V_2 = V_497 -> V_508 ;
struct V_2 * V_3 = V_2 -> V_3 ;
if ( V_3 )
F_80 ( & F_1 ( V_3 ) -> V_509 ) ;
}
static void F_268 ( struct V_505 * V_506 )
{
struct V_497 * V_497 = V_506 -> V_507 ;
struct V_203 * V_2 = V_497 -> V_508 ;
struct V_2 * V_3 = V_2 -> V_3 ;
if ( V_3 )
F_70 ( & F_1 ( V_3 ) -> V_509 ) ;
}
static void F_269 ( struct V_68 * V_29 , unsigned int V_510 ,
unsigned int V_138 )
{
int V_171 ;
for ( V_171 = 0 ; V_171 < V_138 ; V_171 ++ ) {
if ( F_60 ( V_29 [ V_171 ] . V_30 ) ) {
if ( F_270 ( V_29 [ V_171 ] . V_30 ) )
F_271 ( V_29 [ V_171 ] . V_30 ) ;
else
F_272 ( ( unsigned long ) V_29 [ V_171 ] . V_30 ,
V_510 ) ;
V_29 [ V_171 ] . V_30 = NULL ;
}
}
F_126 ( V_29 ) ;
}
static char * F_273 ( unsigned long V_510 )
{
char * V_30 = NULL ;
T_9 V_511 = V_181 | V_512 |
V_513 | V_514 | V_515 ;
V_30 = ( char * ) F_274 ( V_511 , V_510 ) ;
if ( V_30 )
return V_30 ;
V_30 = F_275 ( ( 1 << V_510 ) * V_102 ) ;
if ( V_30 )
return V_30 ;
V_511 &= ~ V_515 ;
V_30 = ( char * ) F_274 ( V_511 , V_510 ) ;
if ( V_30 )
return V_30 ;
return NULL ;
}
static struct V_68 * F_276 ( struct V_516 * V_447 , int V_510 )
{
unsigned int V_517 = V_447 -> V_77 ;
struct V_68 * V_29 ;
int V_171 ;
V_29 = F_277 ( V_517 , sizeof( struct V_68 ) , V_181 ) ;
if ( F_35 ( ! V_29 ) )
goto V_93;
for ( V_171 = 0 ; V_171 < V_517 ; V_171 ++ ) {
V_29 [ V_171 ] . V_30 = F_273 ( V_510 ) ;
if ( F_35 ( ! V_29 [ V_171 ] . V_30 ) )
goto V_518;
}
V_93:
return V_29 ;
V_518:
F_269 ( V_29 , V_510 , V_517 ) ;
V_29 = NULL ;
goto V_93;
}
static int F_205 ( struct V_2 * V_3 , union V_63 * V_64 ,
int V_519 , int V_36 )
{
struct V_68 * V_29 = NULL ;
struct V_1 * V_4 = F_1 ( V_3 ) ;
int V_520 , V_510 = 0 ;
struct V_23 * V_24 ;
struct V_37 * V_38 ;
T_6 V_149 ;
int V_56 = - V_177 ;
struct V_516 * V_447 = & V_64 -> V_447 ;
if ( ! V_519 && V_36 && ( V_4 -> V_18 > V_21 ) ) {
F_17 ( 1 , L_9 ) ;
goto V_93;
}
V_24 = V_36 ? & V_4 -> V_36 : & V_4 -> V_40 ;
V_38 = V_36 ? & V_3 -> V_502 : & V_3 -> V_92 ;
V_56 = - V_328 ;
if ( ! V_519 ) {
if ( F_48 ( & V_4 -> V_509 ) )
goto V_93;
if ( F_48 ( & V_24 -> V_309 ) )
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
V_56 = - V_177 ;
if ( F_35 ( ( int ) V_447 -> V_75 <= 0 ) )
goto V_93;
if ( F_35 ( V_447 -> V_75 & ( V_102 - 1 ) ) )
goto V_93;
if ( F_35 ( V_447 -> V_524 < V_4 -> V_79 +
V_4 -> V_288 ) )
goto V_93;
if ( F_35 ( V_447 -> V_524 & ( V_525 - 1 ) ) )
goto V_93;
V_24 -> V_28 = V_447 -> V_75 / V_447 -> V_524 ;
if ( F_35 ( V_24 -> V_28 <= 0 ) )
goto V_93;
if ( F_35 ( ( V_24 -> V_28 * V_447 -> V_77 ) !=
V_447 -> V_526 ) )
goto V_93;
V_56 = - V_180 ;
V_510 = F_278 ( V_447 -> V_75 ) ;
V_29 = F_276 ( V_447 , V_510 ) ;
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
V_56 = - V_177 ;
if ( F_35 ( V_447 -> V_526 ) )
goto V_93;
}
F_210 ( V_3 ) ;
F_12 ( & V_4 -> V_9 ) ;
V_520 = V_4 -> V_5 ;
V_149 = V_4 -> V_149 ;
if ( V_520 ) {
V_4 -> V_149 = 0 ;
F_6 ( V_3 , false ) ;
}
F_10 ( & V_4 -> V_9 ) ;
F_11 () ;
V_56 = - V_328 ;
F_113 ( & V_4 -> V_327 ) ;
if ( V_519 || F_48 ( & V_4 -> V_509 ) == 0 ) {
V_56 = 0 ;
F_200 ( & V_38 -> V_41 ) ;
F_279 ( V_24 -> V_29 , V_29 ) ;
V_24 -> V_141 = ( V_447 -> V_526 - 1 ) ;
V_24 -> V_32 = 0 ;
V_24 -> V_31 = V_447 -> V_524 ;
F_203 ( & V_38 -> V_41 ) ;
F_279 ( V_24 -> V_527 , V_510 ) ;
F_279 ( V_24 -> V_528 , V_447 -> V_77 ) ;
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
V_4 -> V_149 = V_149 ;
F_2 ( V_3 ) ;
}
F_10 ( & V_4 -> V_9 ) ;
if ( V_519 && ( V_4 -> V_18 > V_21 ) ) {
if ( ! V_36 )
F_26 ( V_4 , V_36 , V_38 ) ;
}
F_211 ( V_3 ) ;
if ( V_29 )
F_269 ( V_29 , V_510 , V_447 -> V_77 ) ;
V_93:
return V_56 ;
}
static int F_280 ( struct V_497 * V_497 , struct V_203 * V_2 ,
struct V_505 * V_506 )
{
struct V_2 * V_3 = V_2 -> V_3 ;
struct V_1 * V_4 = F_1 ( V_3 ) ;
unsigned long V_530 , V_531 ;
struct V_23 * V_24 ;
unsigned long V_100 ;
int V_56 = - V_177 ;
int V_171 ;
if ( V_506 -> V_532 )
return - V_177 ;
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
for ( V_171 = 0 ; V_171 < V_24 -> V_528 ; V_171 ++ ) {
struct V_319 * V_319 ;
void * V_535 = V_24 -> V_29 [ V_171 ] . V_30 ;
int V_536 ;
for ( V_536 = 0 ; V_536 < V_24 -> V_529 ; V_536 ++ ) {
V_319 = F_16 ( V_535 ) ;
V_56 = F_281 ( V_506 , V_100 , V_319 ) ;
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
static void * F_282 ( struct V_539 * V_540 , T_10 * V_541 )
__acquires( T_11 )
{
struct V_165 * V_165 = F_283 ( V_540 ) ;
F_137 () ;
return F_284 ( & V_165 -> V_364 . V_387 , * V_541 ) ;
}
static void * F_285 ( struct V_539 * V_540 , void * V_542 , T_10 * V_541 )
{
struct V_165 * V_165 = F_283 ( V_540 ) ;
return F_286 ( V_542 , & V_165 -> V_364 . V_387 , V_541 ) ;
}
static void F_287 ( struct V_539 * V_540 , void * V_542 )
__releases( T_11 )
{
F_141 () ;
}
static int F_288 ( struct V_539 * V_540 , void * V_542 )
{
if ( V_542 == V_543 )
F_289 ( V_540 , L_11 ) ;
else {
struct V_2 * V_544 = F_290 ( V_542 ) ;
const struct V_1 * V_4 = F_1 ( V_544 ) ;
F_291 ( V_540 ,
L_12 ,
V_544 ,
F_48 ( & V_544 -> V_545 ) ,
V_544 -> V_253 ,
F_179 ( V_4 -> V_149 ) ,
V_4 -> V_58 ,
V_4 -> V_5 ,
F_48 ( & V_544 -> V_144 ) ,
F_292 ( V_544 ) ,
F_293 ( V_544 ) ) ;
}
return 0 ;
}
static int F_294 ( struct V_546 * V_546 , struct V_497 * V_497 )
{
return F_295 ( V_546 , V_497 , & V_547 ,
sizeof( struct V_548 ) ) ;
}
static int T_12 F_296 ( struct V_165 * V_165 )
{
F_119 ( & V_165 -> V_364 . V_365 ) ;
F_297 ( & V_165 -> V_364 . V_387 ) ;
if ( ! F_298 ( V_165 , L_13 , 0 , & V_549 ) )
return - V_180 ;
return 0 ;
}
static void T_13 F_299 ( struct V_165 * V_165 )
{
F_300 ( V_165 , L_13 ) ;
}
static void T_14 F_301 ( void )
{
F_302 ( & V_550 ) ;
F_303 ( & V_551 ) ;
F_304 ( V_380 ) ;
F_305 ( & V_381 ) ;
}
static int T_15 F_306 ( void )
{
int V_552 = F_307 ( & V_381 , 0 ) ;
if ( V_552 != 0 )
goto V_93;
F_308 ( & V_553 ) ;
F_309 ( & V_551 ) ;
F_310 ( & V_550 ) ;
V_93:
return V_552 ;
}
