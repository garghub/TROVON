static int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
int V_5 ;
for ( V_5 = 0 ; V_5 < V_6 ; V_5 ++ ) {
if ( F_2 ( V_2 -> V_7 [ V_5 ] ) == V_4 )
return V_5 ;
}
F_3 ( 1 ) ;
}
static int F_4 ( struct V_8 * V_9 , struct V_10 * V_10 ,
struct V_3 * V_4 )
{
struct V_1 * V_2 = F_5 ( V_9 ) ;
int V_11 ;
int V_12 = - V_13 ;
F_6 ( & V_14 ) ;
if ( V_2 -> V_15 == V_6 )
goto V_16;
V_12 = 0 ;
V_11 = F_1 ( V_2 , NULL ) ;
F_7 ( V_4 -> V_2 , V_2 ) ;
F_7 ( V_2 -> V_7 [ V_11 ] , V_4 ) ;
F_8 ( & V_4 -> V_17 ) ;
V_4 -> V_10 = V_10 ;
V_10 -> V_18 = V_4 ;
V_2 -> V_15 ++ ;
V_16:
F_9 ( & V_14 ) ;
return V_12 ;
}
static void F_10 ( struct V_3 * V_4 )
{
struct V_1 * V_2 ;
F_6 ( & V_14 ) ;
V_2 = F_11 ( V_4 -> V_2 ,
F_12 ( & V_14 ) ) ;
if ( V_2 ) {
int V_11 = F_1 ( V_2 , V_4 ) ;
F_7 ( V_2 -> V_7 [ V_11 ] , NULL ) ;
F_7 ( V_4 -> V_2 , NULL ) ;
F_13 ( & V_4 -> V_17 ) ;
-- V_2 -> V_15 ;
}
F_9 ( & V_14 ) ;
F_14 () ;
F_13 ( & V_4 -> V_17 ) ;
}
static struct V_3 * F_15 ( struct V_8 * V_9 ,
struct V_19 * V_20 )
{
struct V_1 * V_2 = F_5 ( V_9 ) ;
struct V_3 * V_21 = NULL ;
int V_15 = V_2 -> V_15 ;
T_1 V_22 ;
if ( ! V_15 )
goto V_16;
if ( F_16 ( F_17 ( V_20 ) ) ) {
V_22 = F_18 ( V_20 ) ;
while ( F_19 ( V_22 >= V_15 ) )
V_22 -= V_15 ;
V_21 = F_2 ( V_2 -> V_7 [ V_22 ] ) ;
if ( V_21 )
goto V_16;
}
V_22 = F_20 ( V_20 ) ;
if ( V_22 ) {
V_21 = F_2 ( V_2 -> V_7 [ V_22 % V_15 ] ) ;
if ( V_21 )
goto V_16;
}
for ( V_22 = 0 ; V_22 < V_6 ; V_22 ++ ) {
V_21 = F_2 ( V_2 -> V_7 [ V_22 ] ) ;
if ( V_21 )
break;
}
V_16:
return V_21 ;
}
static void F_21 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = F_5 ( V_9 ) ;
struct V_3 * V_4 , * V_23 [ V_6 ] ;
int V_5 , V_24 = 0 ;
F_6 ( & V_14 ) ;
for ( V_5 = 0 ; V_5 < V_6 && V_2 -> V_15 ; V_5 ++ ) {
V_4 = F_11 ( V_2 -> V_7 [ V_5 ] ,
F_12 ( & V_14 ) ) ;
if ( V_4 ) {
V_23 [ V_24 ++ ] = V_4 ;
F_7 ( V_2 -> V_7 [ V_5 ] , NULL ) ;
F_7 ( V_4 -> V_2 , NULL ) ;
V_2 -> V_15 -- ;
}
}
F_3 ( V_2 -> V_15 != 0 ) ;
F_9 ( & V_14 ) ;
F_14 () ;
for ( -- V_24 ; V_24 >= 0 ; V_24 -- )
F_13 ( & V_23 [ V_24 ] -> V_17 ) ;
}
static int F_22 ( struct V_8 * V_9 , struct V_19 * V_20 )
{
struct V_3 * V_4 = F_15 ( V_9 , V_20 ) ;
if ( ! V_4 )
goto V_25;
if ( F_23 ( & V_4 -> V_17 . V_26 ) >= V_9 -> V_27 )
goto V_25;
F_24 ( & V_4 -> V_17 . V_26 , V_20 ) ;
F_25 ( F_26 ( & V_4 -> V_17 ) , V_28 | V_29 | V_30 ) ;
return V_31 ;
V_25:
F_27 ( V_20 ) ;
return V_32 ;
}
static int F_28 ( struct V_19 * V_20 )
{
F_29 ( V_20 , V_33 ) ;
return F_22 ( V_20 -> V_9 , V_20 ) ;
}
static int F_30 ( struct V_34 * V_35 ,
struct V_8 * V_9 ,
struct V_36 * V_37 [] ,
struct V_36 * V_38 [] )
{
struct V_39 * V_40 ;
T_2 V_41 ;
int V_12 ;
V_12 = F_31 ( V_35 , V_9 , V_37 , V_38 ,
F_28 , F_22 ) ;
if ( V_12 )
goto V_16;
V_41 = F_32 ( F_33 ( V_42 ) , V_9 -> V_43 ) ;
V_40 = F_34 ( V_44 , & V_9 -> V_9 , V_41 ,
V_9 , L_1 , V_9 -> V_43 ) ;
if ( F_35 ( V_40 ) ) {
V_12 = F_36 ( V_40 ) ;
F_21 ( V_9 ) ;
}
V_16:
return V_12 ;
}
static void F_37 ( struct V_8 * V_9 ,
struct V_45 * V_46 )
{
F_38 ( V_44 ,
F_32 ( F_33 ( V_42 ) , V_9 -> V_43 ) ) ;
F_21 ( V_9 ) ;
F_39 ( V_9 , V_46 ) ;
}
static void F_40 ( struct V_8 * V_9 )
{
F_41 ( V_9 ) ;
V_9 -> V_27 = V_47 ;
}
static void F_42 ( struct V_48 * V_17 )
{
T_3 * V_49 ;
if ( ! F_43 ( V_17 ) ||
! F_44 ( V_50 , & V_17 -> V_51 -> V_52 ) )
return;
V_49 = F_26 ( V_17 ) ;
if ( V_49 && F_45 ( V_49 ) )
F_25 ( V_49 , V_53 | V_54 | V_55 ) ;
}
static int F_46 ( struct V_56 * V_56 , struct V_10 * V_10 )
{
struct V_34 * V_34 = V_57 -> V_58 -> V_59 ;
struct V_8 * V_9 = F_47 ( V_34 , F_48 ( V_56 ) ) ;
struct V_1 * V_2 = F_5 ( V_9 ) ;
struct V_3 * V_4 ;
int V_12 ;
V_12 = - V_60 ;
if ( ! V_9 )
goto V_16;
V_12 = - V_61 ;
if ( V_9 -> V_62 != & V_63 )
goto V_16;
V_12 = - V_64 ;
V_4 = (struct V_3 * ) F_49 ( V_34 , V_65 , V_66 ,
& V_67 ) ;
if ( ! V_4 )
goto V_16;
V_4 -> V_48 . V_68 = & V_4 -> V_68 ;
F_50 ( & V_4 -> V_68 . V_69 ) ;
V_4 -> V_48 . type = V_70 ;
V_4 -> V_48 . V_71 = V_72 ;
V_4 -> V_48 . V_10 = V_10 ;
V_4 -> V_48 . V_73 = & V_74 ;
F_51 ( & V_4 -> V_48 , & V_4 -> V_17 ) ;
V_4 -> V_17 . V_75 = F_42 ;
V_4 -> V_52 = V_76 | V_77 | V_78 ;
V_4 -> V_79 = sizeof( struct V_80 ) ;
if ( V_2 ) {
if ( ( V_2 -> V_81 -> V_82 & V_83 ) &&
( V_2 -> V_81 -> V_82 & V_84 ) )
F_52 ( & V_4 -> V_17 , V_85 ) ;
}
V_12 = F_4 ( V_9 , V_10 , V_4 ) ;
if ( V_12 )
F_13 ( & V_4 -> V_17 ) ;
V_16:
if ( V_9 )
F_53 ( V_9 ) ;
return V_12 ;
}
static int F_54 ( struct V_56 * V_56 , struct V_10 * V_10 )
{
struct V_3 * V_4 = V_10 -> V_18 ;
F_10 ( V_4 ) ;
return 0 ;
}
static unsigned int F_55 ( struct V_10 * V_10 , T_4 * V_69 )
{
struct V_3 * V_4 = V_10 -> V_18 ;
unsigned int V_86 = V_87 ;
if ( ! V_4 )
goto V_16;
V_86 = 0 ;
F_56 ( V_10 , & V_4 -> V_68 . V_69 , V_69 ) ;
if ( ! F_57 ( & V_4 -> V_17 . V_26 ) )
V_86 |= V_28 | V_29 ;
if ( F_43 ( & V_4 -> V_17 ) ||
( ! F_58 ( V_50 , & V_4 -> V_48 . V_52 ) &&
F_43 ( & V_4 -> V_17 ) ) )
V_86 |= V_53 | V_54 ;
V_16:
return V_86 ;
}
static inline struct V_19 * F_59 ( struct V_48 * V_17 , T_5 V_88 ,
T_5 V_89 , T_5 V_90 ,
int V_91 , int * V_12 )
{
struct V_19 * V_20 ;
if ( V_88 + V_89 < V_92 || ! V_90 )
V_90 = V_89 ;
V_20 = F_60 ( V_17 , V_88 + V_90 , V_89 - V_90 , V_91 ,
V_12 ) ;
if ( ! V_20 )
return NULL ;
F_61 ( V_20 , V_88 ) ;
F_62 ( V_20 , V_90 ) ;
V_20 -> V_93 = V_89 - V_90 ;
V_20 -> V_89 += V_89 - V_90 ;
return V_20 ;
}
static int F_63 ( struct V_19 * V_20 , const struct V_94 * V_95 ,
int V_96 , T_5 V_97 )
{
int V_89 = F_64 ( V_95 , V_97 ) - V_96 ;
int V_98 = F_65 ( V_20 ) ;
int V_99 , V_100 = 0 ;
int V_5 = 0 ;
T_6 * V_101 ;
while ( V_97 && ( V_96 >= V_95 -> V_102 ) ) {
V_96 -= V_95 -> V_102 ;
++ V_95 ;
-- V_97 ;
}
while ( V_97 && ( V_98 > 0 ) ) {
V_99 = F_66 (unsigned int, copy, from->iov_len - offset) ;
if ( F_67 ( V_20 -> V_38 + V_100 , V_95 -> V_103 + V_96 ,
V_99 ) )
return - V_104 ;
if ( V_98 > V_99 ) {
++ V_95 ;
-- V_97 ;
}
V_98 -= V_99 ;
V_100 += V_99 ;
V_96 = 0 ;
}
if ( V_89 == V_100 )
return 0 ;
while ( V_97 -- ) {
struct V_105 * V_105 [ V_106 ] ;
int V_107 ;
unsigned long V_108 ;
V_89 = V_95 -> V_102 - V_100 ;
if ( ! V_89 ) {
V_100 = 0 ;
++ V_95 ;
continue;
}
V_108 = ( unsigned long ) V_95 -> V_103 + V_100 ;
V_99 = ( ( V_108 & ~ V_109 ) + V_89 + ~ V_109 ) >> V_110 ;
V_107 = F_68 ( V_108 , V_99 , 0 , & V_105 [ V_5 ] ) ;
if ( ( V_107 != V_99 ) ||
( V_107 > V_106 - F_69 ( V_20 ) -> V_111 ) )
return - V_104 ;
V_20 -> V_93 += V_89 ;
V_20 -> V_89 += V_89 ;
V_20 -> V_112 += V_89 ;
F_70 ( V_89 , & V_20 -> V_17 -> V_113 ) ;
while ( V_89 ) {
V_101 = & F_69 ( V_20 ) -> V_114 [ V_5 ] ;
V_101 -> V_105 = V_105 [ V_5 ] ;
V_101 -> V_115 = V_108 & ~ V_109 ;
V_101 -> V_99 = F_66 ( int , V_89 , V_92 - V_101 -> V_115 ) ;
F_69 ( V_20 ) -> V_111 ++ ;
V_108 += V_101 -> V_99 ;
V_89 -= V_101 -> V_99 ;
V_5 ++ ;
}
V_100 = 0 ;
++ V_95 ;
}
return 0 ;
}
static int F_71 ( struct V_19 * V_20 ,
struct V_80 * V_116 )
{
unsigned short V_117 = 0 ;
if ( V_116 -> V_117 != V_118 ) {
switch ( V_116 -> V_117 & ~ V_119 ) {
case V_120 :
V_117 = V_121 ;
break;
case V_122 :
V_117 = V_123 ;
break;
case V_124 :
V_117 = V_125 ;
break;
default:
return - V_61 ;
}
if ( V_116 -> V_117 & V_119 )
V_117 |= V_126 ;
if ( V_116 -> V_127 == 0 )
return - V_61 ;
}
if ( V_116 -> V_52 & V_128 ) {
if ( ! F_72 ( V_20 , V_116 -> V_129 ,
V_116 -> V_130 ) )
return - V_61 ;
}
if ( V_116 -> V_117 != V_118 ) {
F_69 ( V_20 ) -> V_127 = V_116 -> V_127 ;
F_69 ( V_20 ) -> V_117 = V_117 ;
F_69 ( V_20 ) -> V_117 |= V_131 ;
F_69 ( V_20 ) -> V_132 = 0 ;
}
return 0 ;
}
static int F_73 ( const struct V_19 * V_20 ,
struct V_80 * V_116 )
{
memset ( V_116 , 0 , sizeof( * V_116 ) ) ;
if ( F_74 ( V_20 ) ) {
struct V_133 * V_134 = F_69 ( V_20 ) ;
V_116 -> V_135 = F_65 ( V_20 ) ;
V_116 -> V_127 = V_134 -> V_127 ;
if ( V_134 -> V_117 & V_121 )
V_116 -> V_117 = V_120 ;
else if ( V_134 -> V_117 & V_123 )
V_116 -> V_117 = V_122 ;
else if ( V_134 -> V_117 & V_125 )
V_116 -> V_117 = V_124 ;
else
F_75 () ;
if ( V_134 -> V_117 & V_126 )
V_116 -> V_117 |= V_119 ;
} else
V_116 -> V_117 = V_118 ;
if ( V_20 -> V_136 == V_137 ) {
V_116 -> V_52 = V_128 ;
V_116 -> V_129 = F_76 ( V_20 ) ;
V_116 -> V_130 = V_20 -> V_130 ;
} else if ( V_20 -> V_136 == V_138 ) {
V_116 -> V_52 = V_139 ;
}
return 0 ;
}
static T_7 F_77 ( struct V_3 * V_4 , struct V_140 * V_141 ,
const struct V_94 * V_142 , unsigned long V_143 ,
T_5 V_97 , int V_91 )
{
struct V_19 * V_20 ;
struct V_1 * V_2 ;
unsigned long V_89 = V_143 ;
int V_12 ;
struct V_80 V_116 = { 0 } ;
int V_144 = 0 ;
int V_145 ;
bool V_146 = false ;
if ( V_4 -> V_52 & V_76 ) {
V_144 = V_4 -> V_79 ;
V_12 = - V_61 ;
if ( V_89 < V_144 )
goto V_12;
V_89 -= V_144 ;
V_12 = F_78 ( ( void * ) & V_116 , V_142 , 0 ,
sizeof( V_116 ) ) ;
if ( V_12 < 0 )
goto V_12;
if ( ( V_116 . V_52 & V_128 ) &&
V_116 . V_129 + V_116 . V_130 + 2 >
V_116 . V_135 )
V_116 . V_135 = V_116 . V_129 +
V_116 . V_130 + 2 ;
V_12 = - V_61 ;
if ( V_116 . V_135 > V_89 )
goto V_12;
}
V_12 = - V_61 ;
if ( F_19 ( V_89 < V_33 ) )
goto V_12;
if ( V_141 && V_141 -> V_147 && F_79 ( & V_4 -> V_17 , V_85 ) )
V_146 = true ;
if ( V_146 ) {
V_145 = V_116 . V_135 ;
if ( ! V_145 )
V_145 = V_148 ;
} else
V_145 = V_89 ;
V_20 = F_59 ( & V_4 -> V_17 , V_149 , V_145 ,
V_116 . V_135 , V_91 , & V_12 ) ;
if ( ! V_20 )
goto V_12;
if ( V_146 ) {
V_12 = F_63 ( V_20 , V_142 , V_144 , V_97 ) ;
F_69 ( V_20 ) -> V_150 |= V_151 ;
} else
V_12 = F_80 ( V_20 , 0 , V_142 , V_144 ,
V_89 ) ;
if ( V_12 )
goto V_152;
F_81 ( V_20 , V_33 ) ;
F_82 ( V_20 ) ;
V_20 -> V_153 = F_83 ( V_20 ) -> V_154 ;
if ( V_144 ) {
V_12 = F_71 ( V_20 , & V_116 ) ;
if ( V_12 )
goto V_152;
}
F_84 () ;
V_2 = F_85 ( V_4 -> V_2 ) ;
if ( V_146 )
F_69 ( V_20 ) -> V_155 = V_141 -> V_147 ;
if ( V_2 )
F_86 ( V_20 , V_2 -> V_9 ) ;
else
F_27 ( V_20 ) ;
F_87 () ;
return V_143 ;
V_152:
F_27 ( V_20 ) ;
V_12:
F_84 () ;
V_2 = F_85 ( V_4 -> V_2 ) ;
if ( V_2 )
V_2 -> V_9 -> V_156 . V_157 ++ ;
F_87 () ;
return V_12 ;
}
static T_7 F_88 ( struct V_158 * V_159 , const struct V_94 * V_142 ,
unsigned long V_97 , T_8 V_160 )
{
struct V_10 * V_10 = V_159 -> V_161 ;
T_7 V_162 = - V_163 ;
struct V_3 * V_4 = V_10 -> V_18 ;
V_162 = F_77 ( V_4 , NULL , V_142 , F_64 ( V_142 , V_97 ) , V_97 ,
V_10 -> V_164 & V_165 ) ;
return V_162 ;
}
static T_7 F_89 ( struct V_3 * V_4 ,
const struct V_19 * V_20 ,
const struct V_94 * V_142 , int V_89 )
{
struct V_1 * V_2 ;
int V_166 ;
int V_144 = 0 ;
if ( V_4 -> V_52 & V_76 ) {
struct V_80 V_116 ;
V_144 = V_4 -> V_79 ;
if ( ( V_89 -= V_144 ) < 0 )
return - V_61 ;
V_166 = F_73 ( V_20 , & V_116 ) ;
if ( V_166 )
return V_166 ;
if ( F_90 ( V_142 , ( void * ) & V_116 , 0 , sizeof( V_116 ) ) )
return - V_104 ;
}
V_89 = F_66 ( int , V_20 -> V_89 , V_89 ) ;
V_166 = F_91 ( V_20 , 0 , V_142 , V_144 , V_89 ) ;
F_84 () ;
V_2 = F_85 ( V_4 -> V_2 ) ;
if ( V_2 )
F_92 ( V_2 , V_89 , V_166 == 0 , 0 ) ;
F_87 () ;
return V_166 ? V_166 : ( V_89 + V_144 ) ;
}
static T_7 F_93 ( struct V_3 * V_4 , struct V_158 * V_159 ,
const struct V_94 * V_142 , unsigned long V_89 ,
int V_91 )
{
F_94 ( V_69 , V_57 ) ;
struct V_19 * V_20 ;
T_7 V_166 = 0 ;
F_95 ( F_26 ( & V_4 -> V_17 ) , & V_69 ) ;
while ( V_89 ) {
V_57 -> V_71 = V_167 ;
V_20 = F_96 ( & V_4 -> V_17 . V_26 ) ;
if ( ! V_20 ) {
if ( V_91 ) {
V_166 = - V_168 ;
break;
}
if ( F_97 ( V_57 ) ) {
V_166 = - V_169 ;
break;
}
F_98 () ;
continue;
}
V_166 = F_89 ( V_4 , V_20 , V_142 , V_89 ) ;
F_27 ( V_20 ) ;
break;
}
V_57 -> V_71 = V_170 ;
F_99 ( F_26 ( & V_4 -> V_17 ) , & V_69 ) ;
return V_166 ;
}
static T_7 F_100 ( struct V_158 * V_159 , const struct V_94 * V_142 ,
unsigned long V_97 , T_8 V_160 )
{
struct V_10 * V_10 = V_159 -> V_161 ;
struct V_3 * V_4 = V_10 -> V_18 ;
T_7 V_89 , V_166 = 0 ;
V_89 = F_64 ( V_142 , V_97 ) ;
if ( V_89 < 0 ) {
V_166 = - V_61 ;
goto V_16;
}
V_166 = F_93 ( V_4 , V_159 , V_142 , V_89 , V_10 -> V_164 & V_165 ) ;
V_166 = F_66 ( T_7 , V_166 , V_89 ) ;
V_16:
return V_166 ;
}
static long F_101 ( struct V_10 * V_10 , unsigned int V_171 ,
unsigned long V_172 )
{
struct V_3 * V_4 = V_10 -> V_18 ;
struct V_1 * V_2 ;
void T_9 * V_173 = ( void T_9 * ) V_172 ;
struct V_174 T_9 * V_175 = V_173 ;
unsigned int T_9 * V_176 = V_173 ;
unsigned int V_177 ;
int T_9 * V_178 = V_173 ;
int V_179 ;
int V_166 ;
switch ( V_171 ) {
case V_180 :
if ( F_102 ( V_177 , & V_175 -> V_181 ) )
return - V_104 ;
V_166 = 0 ;
if ( ( V_177 & ~ V_76 ) != ( V_77 | V_78 ) )
V_166 = - V_61 ;
else
V_4 -> V_52 = V_177 ;
return V_166 ;
case V_182 :
F_84 () ;
V_2 = F_85 ( V_4 -> V_2 ) ;
if ( V_2 )
F_103 ( V_2 -> V_9 ) ;
F_87 () ;
if ( ! V_2 )
return - V_163 ;
V_166 = 0 ;
if ( F_104 ( & V_175 -> V_183 , V_2 -> V_9 -> V_184 , V_185 ) ||
F_105 ( V_4 -> V_52 , & V_175 -> V_181 ) )
V_166 = - V_104 ;
F_53 ( V_2 -> V_9 ) ;
return V_166 ;
case V_186 :
if ( F_105 ( V_78 | V_77 | V_76 , V_176 ) )
return - V_104 ;
return 0 ;
case V_187 :
if ( F_102 ( V_177 , V_176 ) )
return - V_104 ;
V_4 -> V_17 . V_188 = V_177 ;
return 0 ;
case V_189 :
V_179 = V_4 -> V_79 ;
if ( F_105 ( V_179 , V_178 ) )
return - V_104 ;
return 0 ;
case V_190 :
if ( F_102 ( V_179 , V_178 ) )
return - V_104 ;
if ( V_179 < ( int ) sizeof( struct V_80 ) )
return - V_61 ;
V_4 -> V_79 = V_179 ;
return 0 ;
case V_191 :
if ( V_172 & ~ ( V_192 | V_193 | V_194 |
V_195 | V_196 ) )
return - V_61 ;
if ( ! ( V_4 -> V_52 & V_76 ) )
return - V_61 ;
return 0 ;
default:
return - V_61 ;
}
}
static long F_106 ( struct V_10 * V_10 , unsigned int V_171 ,
unsigned long V_172 )
{
return F_101 ( V_10 , V_171 , ( unsigned long ) F_107 ( V_172 ) ) ;
}
static int F_108 ( struct V_158 * V_159 , struct V_197 * V_48 ,
struct V_140 * V_141 , T_5 V_143 )
{
struct V_3 * V_4 = F_109 ( V_48 , struct V_3 , V_48 ) ;
return F_77 ( V_4 , V_141 , V_141 -> V_198 , V_143 , V_141 -> V_199 ,
V_141 -> V_200 & V_201 ) ;
}
static int F_110 ( struct V_158 * V_159 , struct V_197 * V_48 ,
struct V_140 * V_141 , T_5 V_143 ,
int V_52 )
{
struct V_3 * V_4 = F_109 ( V_48 , struct V_3 , V_48 ) ;
int V_166 ;
if ( V_52 & ~ ( V_201 | V_202 ) )
return - V_61 ;
V_166 = F_93 ( V_4 , V_159 , V_141 -> V_198 , V_143 ,
V_52 & V_201 ) ;
if ( V_166 > V_143 ) {
V_141 -> V_200 |= V_202 ;
V_166 = V_52 & V_202 ? V_166 : V_143 ;
}
return V_166 ;
}
struct V_197 * F_111 ( struct V_10 * V_10 )
{
struct V_3 * V_4 ;
if ( V_10 -> V_203 != & V_204 )
return F_112 ( - V_61 ) ;
V_4 = V_10 -> V_18 ;
if ( ! V_4 )
return F_112 ( - V_205 ) ;
return & V_4 -> V_48 ;
}
static int F_113 ( void )
{
int V_12 ;
V_12 = F_114 ( & V_42 , 0 ,
V_206 , L_2 ) ;
if ( V_12 )
goto V_207;
F_115 ( & V_208 , & V_204 ) ;
V_12 = F_116 ( & V_208 , V_42 , V_206 ) ;
if ( V_12 )
goto V_209;
V_44 = F_117 ( V_210 , L_2 ) ;
if ( F_35 ( V_44 ) ) {
V_12 = F_36 ( V_44 ) ;
goto V_211;
}
V_12 = F_118 ( & V_63 ) ;
if ( V_12 )
goto V_212;
return 0 ;
V_212:
F_119 ( V_44 ) ;
V_211:
F_120 ( & V_208 ) ;
V_209:
F_121 ( V_42 , V_206 ) ;
V_207:
return V_12 ;
}
static void F_122 ( void )
{
F_123 ( & V_63 ) ;
F_119 ( V_44 ) ;
F_120 ( & V_208 ) ;
F_121 ( V_42 , V_206 ) ;
}
