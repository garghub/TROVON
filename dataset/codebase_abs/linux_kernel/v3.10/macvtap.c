static int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
int V_5 ;
for ( V_5 = 0 ; V_5 < V_6 ; V_5 ++ ) {
if ( F_2 ( V_2 -> V_7 [ V_5 ] ,
F_3 ( & V_8 ) ) == V_4 )
return V_5 ;
}
F_4 ( 1 ) ;
}
static int F_5 ( struct V_9 * V_10 , struct V_11 * V_11 ,
struct V_3 * V_4 )
{
struct V_1 * V_2 = F_6 ( V_10 ) ;
int V_12 ;
int V_13 = - V_14 ;
F_7 ( & V_8 ) ;
if ( V_2 -> V_15 == V_6 )
goto V_16;
V_13 = 0 ;
V_12 = F_1 ( V_2 , NULL ) ;
F_8 ( V_4 -> V_2 , V_2 ) ;
F_8 ( V_2 -> V_7 [ V_12 ] , V_4 ) ;
F_9 ( & V_4 -> V_17 ) ;
V_4 -> V_11 = V_11 ;
V_11 -> V_18 = V_4 ;
V_2 -> V_15 ++ ;
V_16:
F_10 ( & V_8 ) ;
return V_13 ;
}
static void F_11 ( struct V_3 * V_4 )
{
struct V_1 * V_2 ;
F_7 ( & V_8 ) ;
V_2 = F_2 ( V_4 -> V_2 ,
F_3 ( & V_8 ) ) ;
if ( V_2 ) {
int V_12 = F_1 ( V_2 , V_4 ) ;
F_12 ( V_2 -> V_7 [ V_12 ] , NULL ) ;
F_12 ( V_4 -> V_2 , NULL ) ;
F_13 ( & V_4 -> V_17 ) ;
-- V_2 -> V_15 ;
}
F_10 ( & V_8 ) ;
F_14 () ;
F_13 ( & V_4 -> V_17 ) ;
}
static struct V_3 * F_15 ( struct V_9 * V_10 ,
struct V_19 * V_20 )
{
struct V_1 * V_2 = F_6 ( V_10 ) ;
struct V_3 * V_21 = NULL ;
int V_15 = V_2 -> V_15 ;
T_1 V_22 ;
if ( ! V_15 )
goto V_16;
V_22 = F_16 ( V_20 ) ;
if ( V_22 ) {
V_21 = F_17 ( V_2 -> V_7 [ V_22 % V_15 ] ) ;
if ( V_21 )
goto V_16;
}
if ( F_18 ( F_19 ( V_20 ) ) ) {
V_22 = F_20 ( V_20 ) ;
while ( F_21 ( V_22 >= V_15 ) )
V_22 -= V_15 ;
V_21 = F_17 ( V_2 -> V_7 [ V_22 ] ) ;
if ( V_21 )
goto V_16;
}
for ( V_22 = 0 ; V_22 < V_6 ; V_22 ++ ) {
V_21 = F_17 ( V_2 -> V_7 [ V_22 ] ) ;
if ( V_21 )
break;
}
V_16:
return V_21 ;
}
static void F_22 ( struct V_9 * V_10 )
{
struct V_1 * V_2 = F_6 ( V_10 ) ;
struct V_3 * V_4 , * V_23 [ V_6 ] ;
int V_5 , V_24 = 0 ;
F_7 ( & V_8 ) ;
for ( V_5 = 0 ; V_5 < V_6 && V_2 -> V_15 ; V_5 ++ ) {
V_4 = F_2 ( V_2 -> V_7 [ V_5 ] ,
F_3 ( & V_8 ) ) ;
if ( V_4 ) {
V_23 [ V_24 ++ ] = V_4 ;
F_12 ( V_2 -> V_7 [ V_5 ] , NULL ) ;
F_12 ( V_4 -> V_2 , NULL ) ;
V_2 -> V_15 -- ;
}
}
F_4 ( V_2 -> V_15 != 0 ) ;
V_2 -> V_15 = V_6 ;
F_10 ( & V_8 ) ;
F_14 () ;
for ( -- V_24 ; V_24 >= 0 ; V_24 -- )
F_13 ( & V_23 [ V_24 ] -> V_17 ) ;
}
static int F_23 ( struct V_9 * V_10 , struct V_19 * V_20 )
{
struct V_3 * V_4 = F_15 ( V_10 , V_20 ) ;
if ( ! V_4 )
goto V_25;
if ( F_24 ( & V_4 -> V_17 . V_26 ) >= V_10 -> V_27 )
goto V_25;
F_25 ( & V_4 -> V_17 . V_26 , V_20 ) ;
F_26 ( F_27 ( & V_4 -> V_17 ) , V_28 | V_29 | V_30 ) ;
return V_31 ;
V_25:
F_28 ( V_20 ) ;
return V_32 ;
}
static int F_29 ( struct V_19 * V_20 )
{
F_30 ( V_20 , V_33 ) ;
return F_23 ( V_20 -> V_10 , V_20 ) ;
}
static int F_31 ( struct V_1 * V_2 )
{
int V_34 = - V_35 ;
F_32 ( & V_36 ) ;
V_34 = F_33 ( & V_37 , V_2 , 1 , V_38 , V_39 ) ;
if ( V_34 >= 0 ) {
V_2 -> V_40 = V_34 ;
} else if ( V_34 == - V_41 ) {
F_34 ( V_42 L_1 ) ;
V_34 = - V_43 ;
}
F_35 ( & V_36 ) ;
return V_34 < 0 ? V_34 : 0 ;
}
static void F_36 ( struct V_1 * V_2 )
{
F_32 ( & V_36 ) ;
if ( V_2 -> V_40 ) {
F_37 ( & V_37 , V_2 -> V_40 ) ;
V_2 -> V_40 = 0 ;
}
F_35 ( & V_36 ) ;
}
static struct V_9 * F_38 ( int V_40 )
{
struct V_9 * V_10 = NULL ;
struct V_1 * V_2 ;
F_32 ( & V_36 ) ;
V_2 = F_39 ( & V_37 , V_40 ) ;
if ( V_2 ) {
V_10 = V_2 -> V_10 ;
F_40 ( V_10 ) ;
}
F_35 ( & V_36 ) ;
return V_10 ;
}
static int F_41 ( struct V_44 * V_45 ,
struct V_9 * V_10 ,
struct V_46 * V_47 [] ,
struct V_46 * V_48 [] )
{
return F_42 ( V_45 , V_10 , V_47 , V_48 ,
F_29 , F_23 ) ;
}
static void F_43 ( struct V_9 * V_10 ,
struct V_49 * V_50 )
{
F_22 ( V_10 ) ;
F_44 ( V_10 , V_50 ) ;
}
static void F_45 ( struct V_9 * V_10 )
{
F_46 ( V_10 ) ;
V_10 -> V_27 = V_51 ;
}
static void F_47 ( struct V_52 * V_17 )
{
T_2 * V_53 ;
if ( ! F_48 ( V_17 ) ||
! F_49 ( V_54 , & V_17 -> V_55 -> V_56 ) )
return;
V_53 = F_27 ( V_17 ) ;
if ( V_53 && F_50 ( V_53 ) )
F_26 ( V_53 , V_57 | V_58 | V_59 ) ;
}
static void F_51 ( struct V_52 * V_17 )
{
F_52 ( & V_17 -> V_26 ) ;
}
static int F_53 ( struct V_60 * V_60 , struct V_11 * V_11 )
{
struct V_44 * V_44 = V_61 -> V_62 -> V_63 ;
struct V_9 * V_10 = F_38 ( F_54 ( V_60 ) ) ;
struct V_3 * V_4 ;
int V_13 ;
V_13 = - V_64 ;
if ( ! V_10 )
goto V_16;
V_13 = - V_35 ;
V_4 = (struct V_3 * ) F_55 ( V_44 , V_65 , V_39 ,
& V_66 ) ;
if ( ! V_4 )
goto V_16;
V_4 -> V_52 . V_67 = & V_4 -> V_67 ;
F_56 ( & V_4 -> V_67 . V_68 ) ;
V_4 -> V_52 . type = V_69 ;
V_4 -> V_52 . V_70 = V_71 ;
V_4 -> V_52 . V_11 = V_11 ;
V_4 -> V_52 . V_72 = & V_73 ;
F_57 ( & V_4 -> V_52 , & V_4 -> V_17 ) ;
V_4 -> V_17 . V_74 = F_47 ;
V_4 -> V_17 . V_75 = F_51 ;
V_4 -> V_56 = V_76 | V_77 | V_78 ;
V_4 -> V_79 = sizeof( struct V_80 ) ;
if ( ( V_10 -> V_81 & V_82 ) && ( V_10 -> V_81 & V_83 ) )
F_58 ( & V_4 -> V_17 , V_84 ) ;
V_13 = F_5 ( V_10 , V_11 , V_4 ) ;
if ( V_13 )
F_13 ( & V_4 -> V_17 ) ;
V_16:
if ( V_10 )
F_59 ( V_10 ) ;
return V_13 ;
}
static int F_60 ( struct V_60 * V_60 , struct V_11 * V_11 )
{
struct V_3 * V_4 = V_11 -> V_18 ;
F_11 ( V_4 ) ;
return 0 ;
}
static unsigned int F_61 ( struct V_11 * V_11 , T_3 * V_68 )
{
struct V_3 * V_4 = V_11 -> V_18 ;
unsigned int V_85 = V_86 ;
if ( ! V_4 )
goto V_16;
V_85 = 0 ;
F_62 ( V_11 , & V_4 -> V_67 . V_68 , V_68 ) ;
if ( ! F_63 ( & V_4 -> V_17 . V_26 ) )
V_85 |= V_28 | V_29 ;
if ( F_48 ( & V_4 -> V_17 ) ||
( ! F_64 ( V_54 , & V_4 -> V_52 . V_56 ) &&
F_48 ( & V_4 -> V_17 ) ) )
V_85 |= V_57 | V_58 ;
V_16:
return V_85 ;
}
static inline struct V_19 * F_65 ( struct V_52 * V_17 , T_4 V_87 ,
T_4 V_88 , T_4 V_89 ,
int V_90 , int * V_13 )
{
struct V_19 * V_20 ;
if ( V_87 + V_88 < V_91 || ! V_89 )
V_89 = V_88 ;
V_20 = F_66 ( V_17 , V_87 + V_89 , V_88 - V_89 , V_90 ,
V_13 ) ;
if ( ! V_20 )
return NULL ;
F_67 ( V_20 , V_87 ) ;
F_68 ( V_20 , V_89 ) ;
V_20 -> V_92 = V_88 - V_89 ;
V_20 -> V_88 += V_88 - V_89 ;
return V_20 ;
}
static int F_69 ( struct V_19 * V_20 , const struct V_93 * V_94 ,
int V_95 , T_4 V_96 )
{
int V_88 = F_70 ( V_94 , V_96 ) - V_95 ;
int V_97 = F_71 ( V_20 ) ;
int V_98 , V_99 = 0 ;
int V_5 = 0 ;
while ( V_96 && ( V_95 >= V_94 -> V_100 ) ) {
V_95 -= V_94 -> V_100 ;
++ V_94 ;
-- V_96 ;
}
while ( V_96 && ( V_97 > 0 ) ) {
V_98 = F_72 (unsigned int, copy, from->iov_len - offset) ;
if ( F_73 ( V_20 -> V_48 + V_99 , V_94 -> V_101 + V_95 ,
V_98 ) )
return - V_102 ;
if ( V_97 > V_98 ) {
++ V_94 ;
-- V_96 ;
V_95 = 0 ;
} else
V_95 += V_98 ;
V_97 -= V_98 ;
V_99 += V_98 ;
}
if ( V_88 == V_99 )
return 0 ;
while ( V_96 -- ) {
struct V_103 * V_103 [ V_104 ] ;
int V_105 ;
unsigned long V_106 ;
unsigned long V_107 ;
V_88 = V_94 -> V_100 - V_95 ;
if ( ! V_88 ) {
V_95 = 0 ;
++ V_94 ;
continue;
}
V_106 = ( unsigned long ) V_94 -> V_101 + V_95 ;
V_98 = ( ( V_106 & ~ V_108 ) + V_88 + ~ V_108 ) >> V_109 ;
if ( V_5 + V_98 > V_104 )
return - V_110 ;
V_105 = F_74 ( V_106 , V_98 , 0 , & V_103 [ V_5 ] ) ;
if ( V_105 != V_98 ) {
int V_24 ;
for ( V_24 = 0 ; V_24 < V_105 ; V_24 ++ )
F_75 ( V_103 [ V_5 + V_24 ] ) ;
return - V_102 ;
}
V_107 = V_98 * V_91 ;
V_20 -> V_92 += V_88 ;
V_20 -> V_88 += V_88 ;
V_20 -> V_107 += V_107 ;
F_76 ( V_107 , & V_20 -> V_17 -> V_111 ) ;
while ( V_88 ) {
int V_112 = V_106 & ~ V_108 ;
int V_98 = F_72 ( int , V_88 , V_91 - V_112 ) ;
F_77 ( V_20 , V_5 , V_103 [ V_5 ] , V_112 , V_98 ) ;
F_78 ( V_20 ) -> V_113 ++ ;
V_106 += V_98 ;
V_88 -= V_98 ;
V_5 ++ ;
}
V_95 = 0 ;
++ V_94 ;
}
return 0 ;
}
static int F_79 ( struct V_19 * V_20 ,
struct V_80 * V_114 )
{
unsigned short V_115 = 0 ;
if ( V_114 -> V_115 != V_116 ) {
switch ( V_114 -> V_115 & ~ V_117 ) {
case V_118 :
V_115 = V_119 ;
break;
case V_120 :
V_115 = V_121 ;
break;
case V_122 :
V_115 = V_123 ;
break;
default:
return - V_43 ;
}
if ( V_114 -> V_115 & V_117 )
V_115 |= V_124 ;
if ( V_114 -> V_125 == 0 )
return - V_43 ;
}
if ( V_114 -> V_56 & V_126 ) {
if ( ! F_80 ( V_20 , V_114 -> V_127 ,
V_114 -> V_128 ) )
return - V_43 ;
}
if ( V_114 -> V_115 != V_116 ) {
F_78 ( V_20 ) -> V_125 = V_114 -> V_125 ;
F_78 ( V_20 ) -> V_115 = V_115 ;
F_78 ( V_20 ) -> V_115 |= V_129 ;
F_78 ( V_20 ) -> V_130 = 0 ;
}
return 0 ;
}
static int F_81 ( const struct V_19 * V_20 ,
struct V_80 * V_114 )
{
memset ( V_114 , 0 , sizeof( * V_114 ) ) ;
if ( F_82 ( V_20 ) ) {
struct V_131 * V_132 = F_78 ( V_20 ) ;
V_114 -> V_133 = F_71 ( V_20 ) ;
V_114 -> V_125 = V_132 -> V_125 ;
if ( V_132 -> V_115 & V_119 )
V_114 -> V_115 = V_118 ;
else if ( V_132 -> V_115 & V_121 )
V_114 -> V_115 = V_120 ;
else if ( V_132 -> V_115 & V_123 )
V_114 -> V_115 = V_122 ;
else
F_83 () ;
if ( V_132 -> V_115 & V_124 )
V_114 -> V_115 |= V_117 ;
} else
V_114 -> V_115 = V_116 ;
if ( V_20 -> V_134 == V_135 ) {
V_114 -> V_56 = V_126 ;
V_114 -> V_127 = F_84 ( V_20 ) ;
V_114 -> V_128 = V_20 -> V_128 ;
} else if ( V_20 -> V_134 == V_136 ) {
V_114 -> V_56 = V_137 ;
}
return 0 ;
}
static T_5 F_85 ( struct V_3 * V_4 , struct V_138 * V_139 ,
const struct V_93 * V_140 , unsigned long V_141 ,
T_4 V_96 , int V_90 )
{
struct V_19 * V_20 ;
struct V_1 * V_2 ;
unsigned long V_88 = V_141 ;
int V_13 ;
struct V_80 V_114 = { 0 } ;
int V_142 = 0 ;
int V_143 = 0 ;
bool V_144 = false ;
if ( V_4 -> V_56 & V_76 ) {
V_142 = V_4 -> V_79 ;
V_13 = - V_43 ;
if ( V_88 < V_142 )
goto V_13;
V_88 -= V_142 ;
V_13 = F_86 ( ( void * ) & V_114 , V_140 , 0 ,
sizeof( V_114 ) ) ;
if ( V_13 < 0 )
goto V_13;
if ( ( V_114 . V_56 & V_126 ) &&
V_114 . V_127 + V_114 . V_128 + 2 >
V_114 . V_133 )
V_114 . V_133 = V_114 . V_127 +
V_114 . V_128 + 2 ;
V_13 = - V_43 ;
if ( V_114 . V_133 > V_88 )
goto V_13;
}
V_13 = - V_43 ;
if ( F_21 ( V_88 < V_33 ) )
goto V_13;
V_13 = - V_110 ;
if ( F_21 ( V_96 > V_145 ) )
goto V_13;
if ( V_139 && V_139 -> V_146 && F_87 ( & V_4 -> V_17 , V_84 ) )
V_144 = true ;
if ( V_144 ) {
if ( V_96 > V_104 ) {
V_143 = F_70 ( V_140 , V_96 - V_104 ) ;
if ( V_143 < V_142 )
V_143 = 0 ;
else
V_143 -= V_142 ;
}
if ( V_143 < V_114 . V_133 )
V_143 = V_114 . V_133 ;
if ( ! V_143 )
V_143 = V_147 ;
} else
V_143 = V_88 ;
V_20 = F_65 ( & V_4 -> V_17 , V_148 , V_143 ,
V_114 . V_133 , V_90 , & V_13 ) ;
if ( ! V_20 )
goto V_13;
if ( V_144 )
V_13 = F_69 ( V_20 , V_140 , V_142 , V_96 ) ;
else
V_13 = F_88 ( V_20 , 0 , V_140 , V_142 ,
V_88 ) ;
if ( V_13 )
goto V_149;
F_89 ( V_20 , V_33 ) ;
F_90 ( V_20 ) ;
V_20 -> V_150 = F_91 ( V_20 ) -> V_151 ;
if ( V_142 ) {
V_13 = F_79 ( V_20 , & V_114 ) ;
if ( V_13 )
goto V_149;
}
F_92 ( V_20 , V_33 ) ;
F_93 () ;
V_2 = F_94 ( V_4 -> V_2 ) ;
if ( V_144 ) {
F_78 ( V_20 ) -> V_152 = V_139 -> V_146 ;
F_78 ( V_20 ) -> V_153 |= V_154 ;
F_78 ( V_20 ) -> V_153 |= V_155 ;
}
if ( V_2 )
F_95 ( V_20 , V_2 -> V_10 ) ;
else
F_28 ( V_20 ) ;
F_96 () ;
return V_141 ;
V_149:
F_28 ( V_20 ) ;
V_13:
F_93 () ;
V_2 = F_94 ( V_4 -> V_2 ) ;
if ( V_2 )
V_2 -> V_10 -> V_156 . V_157 ++ ;
F_96 () ;
return V_13 ;
}
static T_5 F_97 ( struct V_158 * V_159 , const struct V_93 * V_140 ,
unsigned long V_96 , T_6 V_160 )
{
struct V_11 * V_11 = V_159 -> V_161 ;
T_5 V_162 = - V_163 ;
struct V_3 * V_4 = V_11 -> V_18 ;
V_162 = F_85 ( V_4 , NULL , V_140 , F_70 ( V_140 , V_96 ) , V_96 ,
V_11 -> V_164 & V_165 ) ;
return V_162 ;
}
static T_5 F_98 ( struct V_3 * V_4 ,
const struct V_19 * V_20 ,
const struct V_93 * V_140 , int V_88 )
{
struct V_1 * V_2 ;
int V_166 ;
int V_142 = 0 ;
int V_167 = 0 ;
int V_168 ;
if ( V_4 -> V_56 & V_76 ) {
struct V_80 V_114 ;
V_142 = V_4 -> V_79 ;
if ( ( V_88 -= V_142 ) < 0 )
return - V_43 ;
V_166 = F_81 ( V_20 , & V_114 ) ;
if ( V_166 )
return V_166 ;
if ( F_99 ( V_140 , ( void * ) & V_114 , 0 , sizeof( V_114 ) ) )
return - V_102 ;
}
V_168 = V_142 ;
if ( ! F_100 ( V_20 ) )
V_88 = F_72 ( int , V_20 -> V_88 , V_88 ) ;
else {
int V_97 ;
struct {
T_7 V_169 ;
T_7 V_170 ;
} V_171 ;
V_171 . V_169 = F_101 ( V_172 ) ;
V_171 . V_170 = F_101 ( F_102 ( V_20 ) ) ;
V_167 = F_103 ( struct V_173 , V_169 ) ;
V_88 = F_72 ( int , V_20 -> V_88 + V_174 , V_88 ) ;
V_97 = F_72 ( int , V_167 , V_88 ) ;
V_166 = F_104 ( V_20 , 0 , V_140 , V_168 , V_97 ) ;
V_88 -= V_97 ;
V_168 += V_97 ;
if ( V_166 || ! V_88 )
goto V_175;
V_97 = F_72 ( int , sizeof( V_171 ) , V_88 ) ;
V_166 = F_99 ( V_140 , ( void * ) & V_171 , V_168 , V_97 ) ;
V_88 -= V_97 ;
V_168 += V_97 ;
if ( V_166 || ! V_88 )
goto V_175;
}
V_166 = F_104 ( V_20 , V_167 , V_140 , V_168 , V_88 ) ;
V_168 += V_88 ;
V_175:
F_93 () ;
V_2 = F_94 ( V_4 -> V_2 ) ;
if ( V_2 )
F_105 ( V_2 , V_168 - V_142 , V_166 == 0 , 0 ) ;
F_96 () ;
return V_166 ? V_166 : V_168 ;
}
static T_5 F_106 ( struct V_3 * V_4 , struct V_158 * V_159 ,
const struct V_93 * V_140 , unsigned long V_88 ,
int V_90 )
{
F_107 ( V_68 ) ;
struct V_19 * V_20 ;
T_5 V_166 = 0 ;
while ( V_88 ) {
F_108 ( F_27 ( & V_4 -> V_17 ) , & V_68 , V_176 ) ;
V_20 = F_109 ( & V_4 -> V_17 . V_26 ) ;
if ( ! V_20 ) {
if ( V_90 ) {
V_166 = - V_177 ;
break;
}
if ( F_110 ( V_61 ) ) {
V_166 = - V_178 ;
break;
}
F_111 () ;
continue;
}
V_166 = F_98 ( V_4 , V_20 , V_140 , V_88 ) ;
F_28 ( V_20 ) ;
break;
}
F_112 ( F_27 ( & V_4 -> V_17 ) , & V_68 ) ;
return V_166 ;
}
static T_5 F_113 ( struct V_158 * V_159 , const struct V_93 * V_140 ,
unsigned long V_96 , T_6 V_160 )
{
struct V_11 * V_11 = V_159 -> V_161 ;
struct V_3 * V_4 = V_11 -> V_18 ;
T_5 V_88 , V_166 = 0 ;
V_88 = F_70 ( V_140 , V_96 ) ;
if ( V_88 < 0 ) {
V_166 = - V_43 ;
goto V_16;
}
V_166 = F_106 ( V_4 , V_159 , V_140 , V_88 , V_11 -> V_164 & V_165 ) ;
V_166 = F_72 ( T_5 , V_166 , V_88 ) ;
V_16:
return V_166 ;
}
static long F_114 ( struct V_11 * V_11 , unsigned int V_179 ,
unsigned long V_180 )
{
struct V_3 * V_4 = V_11 -> V_18 ;
struct V_1 * V_2 ;
void T_8 * V_181 = ( void T_8 * ) V_180 ;
struct V_182 T_8 * V_183 = V_181 ;
unsigned int T_8 * V_184 = V_181 ;
unsigned int V_185 ;
int T_8 * V_186 = V_181 ;
int V_187 ;
int V_166 ;
switch ( V_179 ) {
case V_188 :
if ( F_115 ( V_185 , & V_183 -> V_189 ) )
return - V_102 ;
V_166 = 0 ;
if ( ( V_185 & ~ V_76 ) != ( V_77 | V_78 ) )
V_166 = - V_43 ;
else
V_4 -> V_56 = V_185 ;
return V_166 ;
case V_190 :
F_93 () ;
V_2 = F_94 ( V_4 -> V_2 ) ;
if ( V_2 )
F_40 ( V_2 -> V_10 ) ;
F_96 () ;
if ( ! V_2 )
return - V_163 ;
V_166 = 0 ;
if ( F_116 ( & V_183 -> V_191 , V_2 -> V_10 -> V_192 , V_193 ) ||
F_117 ( V_4 -> V_56 , & V_183 -> V_189 ) )
V_166 = - V_102 ;
F_59 ( V_2 -> V_10 ) ;
return V_166 ;
case V_194 :
if ( F_117 ( V_78 | V_77 | V_76 , V_184 ) )
return - V_102 ;
return 0 ;
case V_195 :
if ( F_115 ( V_185 , V_184 ) )
return - V_102 ;
V_4 -> V_17 . V_196 = V_185 ;
return 0 ;
case V_197 :
V_187 = V_4 -> V_79 ;
if ( F_117 ( V_187 , V_186 ) )
return - V_102 ;
return 0 ;
case V_198 :
if ( F_115 ( V_187 , V_186 ) )
return - V_102 ;
if ( V_187 < ( int ) sizeof( struct V_80 ) )
return - V_43 ;
V_4 -> V_79 = V_187 ;
return 0 ;
case V_199 :
if ( V_180 & ~ ( V_200 | V_201 | V_202 |
V_203 | V_204 ) )
return - V_43 ;
if ( ! ( V_4 -> V_56 & V_76 ) )
return - V_43 ;
return 0 ;
default:
return - V_43 ;
}
}
static long F_118 ( struct V_11 * V_11 , unsigned int V_179 ,
unsigned long V_180 )
{
return F_114 ( V_11 , V_179 , ( unsigned long ) F_119 ( V_180 ) ) ;
}
static int F_120 ( struct V_158 * V_159 , struct V_205 * V_52 ,
struct V_138 * V_139 , T_4 V_141 )
{
struct V_3 * V_4 = F_121 ( V_52 , struct V_3 , V_52 ) ;
return F_85 ( V_4 , V_139 , V_139 -> V_206 , V_141 , V_139 -> V_207 ,
V_139 -> V_208 & V_209 ) ;
}
static int F_122 ( struct V_158 * V_159 , struct V_205 * V_52 ,
struct V_138 * V_139 , T_4 V_141 ,
int V_56 )
{
struct V_3 * V_4 = F_121 ( V_52 , struct V_3 , V_52 ) ;
int V_166 ;
if ( V_56 & ~ ( V_209 | V_210 ) )
return - V_43 ;
V_166 = F_106 ( V_4 , V_159 , V_139 -> V_206 , V_141 ,
V_56 & V_209 ) ;
if ( V_166 > V_141 ) {
V_139 -> V_208 |= V_210 ;
V_166 = V_56 & V_210 ? V_166 : V_141 ;
}
return V_166 ;
}
struct V_205 * F_123 ( struct V_11 * V_11 )
{
struct V_3 * V_4 ;
if ( V_11 -> V_211 != & V_212 )
return F_124 ( - V_43 ) ;
V_4 = V_11 -> V_18 ;
if ( ! V_4 )
return F_124 ( - V_213 ) ;
return & V_4 -> V_52 ;
}
static int F_125 ( struct V_214 * V_215 ,
unsigned long V_216 , void * V_217 )
{
struct V_9 * V_10 = V_217 ;
struct V_1 * V_2 ;
struct V_218 * V_219 ;
T_9 V_220 ;
int V_13 ;
if ( V_10 -> V_221 != & V_222 )
return V_223 ;
V_2 = F_6 ( V_10 ) ;
switch ( V_216 ) {
case V_224 :
V_13 = F_31 ( V_2 ) ;
if ( V_13 )
return F_126 ( V_13 ) ;
V_220 = F_127 ( F_128 ( V_225 ) , V_2 -> V_40 ) ;
V_219 = F_129 ( V_226 , & V_10 -> V_10 , V_220 ,
V_10 , L_2 , V_10 -> V_227 ) ;
if ( F_130 ( V_219 ) ) {
F_36 ( V_2 ) ;
return F_126 ( F_131 ( V_219 ) ) ;
}
break;
case V_228 :
V_220 = F_127 ( F_128 ( V_225 ) , V_2 -> V_40 ) ;
F_132 ( V_226 , V_220 ) ;
F_36 ( V_2 ) ;
break;
}
return V_223 ;
}
static int F_133 ( void )
{
int V_13 ;
V_13 = F_134 ( & V_225 , 0 ,
V_38 , L_3 ) ;
if ( V_13 )
goto V_229;
F_135 ( & V_230 , & V_212 ) ;
V_13 = F_136 ( & V_230 , V_225 , V_38 ) ;
if ( V_13 )
goto V_231;
V_226 = F_137 ( V_232 , L_3 ) ;
if ( F_130 ( V_226 ) ) {
V_13 = F_131 ( V_226 ) ;
goto V_233;
}
V_13 = F_138 ( & V_234 ) ;
if ( V_13 )
goto V_235;
V_13 = F_139 ( & V_222 ) ;
if ( V_13 )
goto V_236;
return 0 ;
V_236:
F_140 ( & V_234 ) ;
V_235:
F_141 ( V_226 ) ;
V_233:
F_142 ( & V_230 ) ;
V_231:
F_143 ( V_225 , V_38 ) ;
V_229:
return V_13 ;
}
static void F_144 ( void )
{
F_145 ( & V_222 ) ;
F_140 ( & V_234 ) ;
F_141 ( V_226 ) ;
F_142 ( & V_230 ) ;
F_143 ( V_225 , V_38 ) ;
}
