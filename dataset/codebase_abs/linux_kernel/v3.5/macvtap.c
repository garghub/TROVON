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
F_13 ( V_2 -> V_7 [ V_11 ] , NULL ) ;
F_13 ( V_4 -> V_2 , NULL ) ;
F_14 ( & V_4 -> V_17 ) ;
-- V_2 -> V_15 ;
}
F_9 ( & V_14 ) ;
F_15 () ;
F_14 ( & V_4 -> V_17 ) ;
}
static struct V_3 * F_16 ( struct V_8 * V_9 ,
struct V_19 * V_20 )
{
struct V_1 * V_2 = F_5 ( V_9 ) ;
struct V_3 * V_21 = NULL ;
int V_15 = V_2 -> V_15 ;
T_1 V_22 ;
if ( ! V_15 )
goto V_16;
V_22 = F_17 ( V_20 ) ;
if ( V_22 ) {
V_21 = F_2 ( V_2 -> V_7 [ V_22 % V_15 ] ) ;
if ( V_21 )
goto V_16;
}
if ( F_18 ( F_19 ( V_20 ) ) ) {
V_22 = F_20 ( V_20 ) ;
while ( F_21 ( V_22 >= V_15 ) )
V_22 -= V_15 ;
V_21 = F_2 ( V_2 -> V_7 [ V_22 ] ) ;
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
static void F_22 ( struct V_8 * V_9 )
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
F_13 ( V_2 -> V_7 [ V_5 ] , NULL ) ;
F_13 ( V_4 -> V_2 , NULL ) ;
V_2 -> V_15 -- ;
}
}
F_3 ( V_2 -> V_15 != 0 ) ;
V_2 -> V_15 = V_6 ;
F_9 ( & V_14 ) ;
F_15 () ;
for ( -- V_24 ; V_24 >= 0 ; V_24 -- )
F_14 ( & V_23 [ V_24 ] -> V_17 ) ;
}
static int F_23 ( struct V_8 * V_9 , struct V_19 * V_20 )
{
struct V_3 * V_4 = F_16 ( V_9 , V_20 ) ;
if ( ! V_4 )
goto V_25;
if ( F_24 ( & V_4 -> V_17 . V_26 ) >= V_9 -> V_27 )
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
return F_23 ( V_20 -> V_9 , V_20 ) ;
}
static int F_31 ( struct V_1 * V_2 )
{
int V_34 = - V_35 ;
int V_36 ;
F_32 ( & V_37 ) ;
if ( F_33 ( & V_38 , V_39 ) == 0 )
goto exit;
V_34 = F_34 ( & V_38 , V_2 , 1 , & V_36 ) ;
if ( V_34 < 0 ) {
if ( V_34 == - V_40 )
V_34 = - V_35 ;
goto exit;
}
if ( V_36 < V_41 ) {
V_2 -> V_42 = V_36 ;
} else {
F_35 ( V_43 L_1 ) ;
V_34 = - V_44 ;
F_36 ( & V_38 , V_36 ) ;
}
exit:
F_37 ( & V_37 ) ;
return V_34 ;
}
static void F_38 ( struct V_1 * V_2 )
{
F_32 ( & V_37 ) ;
if ( V_2 -> V_42 ) {
F_36 ( & V_38 , V_2 -> V_42 ) ;
V_2 -> V_42 = 0 ;
}
F_37 ( & V_37 ) ;
}
static struct V_8 * F_39 ( int V_42 )
{
struct V_8 * V_9 = NULL ;
struct V_1 * V_2 ;
F_32 ( & V_37 ) ;
V_2 = F_40 ( & V_38 , V_42 ) ;
if ( V_2 ) {
V_9 = V_2 -> V_9 ;
F_41 ( V_9 ) ;
}
F_37 ( & V_37 ) ;
return V_9 ;
}
static int F_42 ( struct V_45 * V_46 ,
struct V_8 * V_9 ,
struct V_47 * V_48 [] ,
struct V_47 * V_49 [] )
{
return F_43 ( V_46 , V_9 , V_48 , V_49 ,
F_29 , F_23 ) ;
}
static void F_44 ( struct V_8 * V_9 ,
struct V_50 * V_51 )
{
F_22 ( V_9 ) ;
F_45 ( V_9 , V_51 ) ;
}
static void F_46 ( struct V_8 * V_9 )
{
F_47 ( V_9 ) ;
V_9 -> V_27 = V_52 ;
}
static void F_48 ( struct V_53 * V_17 )
{
T_2 * V_54 ;
if ( ! F_49 ( V_17 ) ||
! F_50 ( V_55 , & V_17 -> V_56 -> V_57 ) )
return;
V_54 = F_27 ( V_17 ) ;
if ( V_54 && F_51 ( V_54 ) )
F_26 ( V_54 , V_58 | V_59 | V_60 ) ;
}
static void F_52 ( struct V_53 * V_17 )
{
F_53 ( & V_17 -> V_26 ) ;
}
static int F_54 ( struct V_61 * V_61 , struct V_10 * V_10 )
{
struct V_45 * V_45 = V_62 -> V_63 -> V_64 ;
struct V_8 * V_9 = F_39 ( F_55 ( V_61 ) ) ;
struct V_3 * V_4 ;
int V_12 ;
V_12 = - V_65 ;
if ( ! V_9 )
goto V_16;
V_12 = - V_35 ;
V_4 = (struct V_3 * ) F_56 ( V_45 , V_66 , V_39 ,
& V_67 ) ;
if ( ! V_4 )
goto V_16;
V_4 -> V_53 . V_68 = & V_4 -> V_68 ;
F_57 ( & V_4 -> V_68 . V_69 ) ;
V_4 -> V_53 . type = V_70 ;
V_4 -> V_53 . V_71 = V_72 ;
V_4 -> V_53 . V_10 = V_10 ;
V_4 -> V_53 . V_73 = & V_74 ;
F_58 ( & V_4 -> V_53 , & V_4 -> V_17 ) ;
V_4 -> V_17 . V_75 = F_48 ;
V_4 -> V_17 . V_76 = F_52 ;
V_4 -> V_57 = V_77 | V_78 | V_79 ;
V_4 -> V_80 = sizeof( struct V_81 ) ;
if ( ( V_9 -> V_82 & V_83 ) && ( V_9 -> V_82 & V_84 ) )
F_59 ( & V_4 -> V_17 , V_85 ) ;
V_12 = F_4 ( V_9 , V_10 , V_4 ) ;
if ( V_12 )
F_14 ( & V_4 -> V_17 ) ;
V_16:
if ( V_9 )
F_60 ( V_9 ) ;
return V_12 ;
}
static int F_61 ( struct V_61 * V_61 , struct V_10 * V_10 )
{
struct V_3 * V_4 = V_10 -> V_18 ;
F_10 ( V_4 ) ;
return 0 ;
}
static unsigned int F_62 ( struct V_10 * V_10 , T_3 * V_69 )
{
struct V_3 * V_4 = V_10 -> V_18 ;
unsigned int V_86 = V_87 ;
if ( ! V_4 )
goto V_16;
V_86 = 0 ;
F_63 ( V_10 , & V_4 -> V_68 . V_69 , V_69 ) ;
if ( ! F_64 ( & V_4 -> V_17 . V_26 ) )
V_86 |= V_28 | V_29 ;
if ( F_49 ( & V_4 -> V_17 ) ||
( ! F_65 ( V_55 , & V_4 -> V_53 . V_57 ) &&
F_49 ( & V_4 -> V_17 ) ) )
V_86 |= V_58 | V_59 ;
V_16:
return V_86 ;
}
static inline struct V_19 * F_66 ( struct V_53 * V_17 , T_4 V_88 ,
T_4 V_89 , T_4 V_90 ,
int V_91 , int * V_12 )
{
struct V_19 * V_20 ;
if ( V_88 + V_89 < V_92 || ! V_90 )
V_90 = V_89 ;
V_20 = F_67 ( V_17 , V_88 + V_90 , V_89 - V_90 , V_91 ,
V_12 ) ;
if ( ! V_20 )
return NULL ;
F_68 ( V_20 , V_88 ) ;
F_69 ( V_20 , V_90 ) ;
V_20 -> V_93 = V_89 - V_90 ;
V_20 -> V_89 += V_89 - V_90 ;
return V_20 ;
}
static int F_70 ( struct V_19 * V_20 , const struct V_94 * V_95 ,
int V_96 , T_4 V_97 )
{
int V_89 = F_71 ( V_95 , V_97 ) - V_96 ;
int V_98 = F_72 ( V_20 ) ;
int V_99 , V_100 = 0 ;
int V_5 = 0 ;
while ( V_97 && ( V_96 >= V_95 -> V_101 ) ) {
V_96 -= V_95 -> V_101 ;
++ V_95 ;
-- V_97 ;
}
while ( V_97 && ( V_98 > 0 ) ) {
V_99 = F_73 (unsigned int, copy, from->iov_len - offset) ;
if ( F_74 ( V_20 -> V_49 + V_100 , V_95 -> V_102 + V_96 ,
V_99 ) )
return - V_103 ;
if ( V_98 > V_99 ) {
++ V_95 ;
-- V_97 ;
V_96 = 0 ;
} else
V_96 += V_99 ;
V_98 -= V_99 ;
V_100 += V_99 ;
}
if ( V_89 == V_100 )
return 0 ;
while ( V_97 -- ) {
struct V_104 * V_104 [ V_105 ] ;
int V_106 ;
unsigned long V_107 ;
unsigned long V_108 ;
V_89 = V_95 -> V_101 - V_96 ;
if ( ! V_89 ) {
V_96 = 0 ;
++ V_95 ;
continue;
}
V_107 = ( unsigned long ) V_95 -> V_102 + V_96 ;
V_99 = ( ( V_107 & ~ V_109 ) + V_89 + ~ V_109 ) >> V_110 ;
if ( V_5 + V_99 > V_105 )
return - V_111 ;
V_106 = F_75 ( V_107 , V_99 , 0 , & V_104 [ V_5 ] ) ;
if ( V_106 != V_99 ) {
for ( V_5 = 0 ; V_5 < V_106 ; V_5 ++ )
F_76 ( V_104 [ V_5 ] ) ;
return - V_103 ;
}
V_108 = V_99 * V_92 ;
V_20 -> V_93 += V_89 ;
V_20 -> V_89 += V_89 ;
V_20 -> V_108 += V_108 ;
F_77 ( V_108 , & V_20 -> V_17 -> V_112 ) ;
while ( V_89 ) {
int V_113 = V_107 & ~ V_109 ;
int V_99 = F_73 ( int , V_89 , V_92 - V_113 ) ;
F_78 ( V_20 , V_5 , V_104 [ V_5 ] , V_113 , V_99 ) ;
F_79 ( V_20 ) -> V_114 ++ ;
V_107 += V_99 ;
V_89 -= V_99 ;
V_5 ++ ;
}
V_96 = 0 ;
++ V_95 ;
}
return 0 ;
}
static int F_80 ( struct V_19 * V_20 ,
struct V_81 * V_115 )
{
unsigned short V_116 = 0 ;
if ( V_115 -> V_116 != V_117 ) {
switch ( V_115 -> V_116 & ~ V_118 ) {
case V_119 :
V_116 = V_120 ;
break;
case V_121 :
V_116 = V_122 ;
break;
case V_123 :
V_116 = V_124 ;
break;
default:
return - V_44 ;
}
if ( V_115 -> V_116 & V_118 )
V_116 |= V_125 ;
if ( V_115 -> V_126 == 0 )
return - V_44 ;
}
if ( V_115 -> V_57 & V_127 ) {
if ( ! F_81 ( V_20 , V_115 -> V_128 ,
V_115 -> V_129 ) )
return - V_44 ;
}
if ( V_115 -> V_116 != V_117 ) {
F_79 ( V_20 ) -> V_126 = V_115 -> V_126 ;
F_79 ( V_20 ) -> V_116 = V_116 ;
F_79 ( V_20 ) -> V_116 |= V_130 ;
F_79 ( V_20 ) -> V_131 = 0 ;
}
return 0 ;
}
static int F_82 ( const struct V_19 * V_20 ,
struct V_81 * V_115 )
{
memset ( V_115 , 0 , sizeof( * V_115 ) ) ;
if ( F_83 ( V_20 ) ) {
struct V_132 * V_133 = F_79 ( V_20 ) ;
V_115 -> V_134 = F_72 ( V_20 ) ;
V_115 -> V_126 = V_133 -> V_126 ;
if ( V_133 -> V_116 & V_120 )
V_115 -> V_116 = V_119 ;
else if ( V_133 -> V_116 & V_122 )
V_115 -> V_116 = V_121 ;
else if ( V_133 -> V_116 & V_124 )
V_115 -> V_116 = V_123 ;
else
F_84 () ;
if ( V_133 -> V_116 & V_125 )
V_115 -> V_116 |= V_118 ;
} else
V_115 -> V_116 = V_117 ;
if ( V_20 -> V_135 == V_136 ) {
V_115 -> V_57 = V_127 ;
V_115 -> V_128 = F_85 ( V_20 ) ;
V_115 -> V_129 = V_20 -> V_129 ;
} else if ( V_20 -> V_135 == V_137 ) {
V_115 -> V_57 = V_138 ;
}
return 0 ;
}
static T_5 F_86 ( struct V_3 * V_4 , struct V_139 * V_140 ,
const struct V_94 * V_141 , unsigned long V_142 ,
T_4 V_97 , int V_91 )
{
struct V_19 * V_20 ;
struct V_1 * V_2 ;
unsigned long V_89 = V_142 ;
int V_12 ;
struct V_81 V_115 = { 0 } ;
int V_143 = 0 ;
int V_144 = 0 ;
bool V_145 = false ;
if ( V_4 -> V_57 & V_77 ) {
V_143 = V_4 -> V_80 ;
V_12 = - V_44 ;
if ( V_89 < V_143 )
goto V_12;
V_89 -= V_143 ;
V_12 = F_87 ( ( void * ) & V_115 , V_141 , 0 ,
sizeof( V_115 ) ) ;
if ( V_12 < 0 )
goto V_12;
if ( ( V_115 . V_57 & V_127 ) &&
V_115 . V_128 + V_115 . V_129 + 2 >
V_115 . V_134 )
V_115 . V_134 = V_115 . V_128 +
V_115 . V_129 + 2 ;
V_12 = - V_44 ;
if ( V_115 . V_134 > V_89 )
goto V_12;
}
V_12 = - V_44 ;
if ( F_21 ( V_89 < V_33 ) )
goto V_12;
V_12 = - V_111 ;
if ( F_21 ( V_97 > V_146 ) )
goto V_12;
if ( V_140 && V_140 -> V_147 && F_88 ( & V_4 -> V_17 , V_85 ) )
V_145 = true ;
if ( V_145 ) {
if ( V_97 > V_105 ) {
V_144 = F_71 ( V_141 , V_97 - V_105 ) ;
if ( V_144 < V_143 )
V_144 = 0 ;
else
V_144 -= V_143 ;
}
if ( V_144 < V_115 . V_134 )
V_144 = V_115 . V_134 ;
if ( ! V_144 )
V_144 = V_148 ;
} else
V_144 = V_89 ;
V_20 = F_66 ( & V_4 -> V_17 , V_149 , V_144 ,
V_115 . V_134 , V_91 , & V_12 ) ;
if ( ! V_20 )
goto V_12;
if ( V_145 )
V_12 = F_70 ( V_20 , V_141 , V_143 , V_97 ) ;
else
V_12 = F_89 ( V_20 , 0 , V_141 , V_143 ,
V_89 ) ;
if ( V_12 )
goto V_150;
F_90 ( V_20 , V_33 ) ;
F_91 ( V_20 ) ;
V_20 -> V_151 = F_92 ( V_20 ) -> V_152 ;
if ( V_143 ) {
V_12 = F_80 ( V_20 , & V_115 ) ;
if ( V_12 )
goto V_150;
}
F_93 () ;
V_2 = F_94 ( V_4 -> V_2 ) ;
if ( V_145 ) {
F_79 ( V_20 ) -> V_153 = V_140 -> V_147 ;
F_79 ( V_20 ) -> V_154 |= V_155 ;
}
if ( V_2 )
F_95 ( V_20 , V_2 -> V_9 ) ;
else
F_28 ( V_20 ) ;
F_96 () ;
return V_142 ;
V_150:
F_28 ( V_20 ) ;
V_12:
F_93 () ;
V_2 = F_94 ( V_4 -> V_2 ) ;
if ( V_2 )
V_2 -> V_9 -> V_156 . V_157 ++ ;
F_96 () ;
return V_12 ;
}
static T_5 F_97 ( struct V_158 * V_159 , const struct V_94 * V_141 ,
unsigned long V_97 , T_6 V_160 )
{
struct V_10 * V_10 = V_159 -> V_161 ;
T_5 V_162 = - V_163 ;
struct V_3 * V_4 = V_10 -> V_18 ;
V_162 = F_86 ( V_4 , NULL , V_141 , F_71 ( V_141 , V_97 ) , V_97 ,
V_10 -> V_164 & V_165 ) ;
return V_162 ;
}
static T_5 F_98 ( struct V_3 * V_4 ,
const struct V_19 * V_20 ,
const struct V_94 * V_141 , int V_89 )
{
struct V_1 * V_2 ;
int V_166 ;
int V_143 = 0 ;
int V_167 = 0 ;
int V_168 ;
if ( V_4 -> V_57 & V_77 ) {
struct V_81 V_115 ;
V_143 = V_4 -> V_80 ;
if ( ( V_89 -= V_143 ) < 0 )
return - V_44 ;
V_166 = F_82 ( V_20 , & V_115 ) ;
if ( V_166 )
return V_166 ;
if ( F_99 ( V_141 , ( void * ) & V_115 , 0 , sizeof( V_115 ) ) )
return - V_103 ;
}
V_168 = V_143 ;
if ( ! F_100 ( V_20 ) )
V_89 = F_73 ( int , V_20 -> V_89 , V_89 ) ;
else {
int V_98 ;
struct {
T_7 V_169 ;
T_7 V_170 ;
} V_171 ;
V_171 . V_169 = F_101 ( V_172 ) ;
V_171 . V_170 = F_101 ( F_102 ( V_20 ) ) ;
V_167 = F_103 ( struct V_173 , V_169 ) ;
V_89 = F_73 ( int , V_20 -> V_89 + V_174 , V_89 ) ;
V_98 = F_73 ( int , V_167 , V_89 ) ;
V_166 = F_104 ( V_20 , 0 , V_141 , V_168 , V_98 ) ;
V_89 -= V_98 ;
V_168 += V_98 ;
if ( V_166 || ! V_89 )
goto V_175;
V_98 = F_73 ( int , sizeof( V_171 ) , V_89 ) ;
V_166 = F_99 ( V_141 , ( void * ) & V_171 , V_168 , V_98 ) ;
V_89 -= V_98 ;
V_168 += V_98 ;
if ( V_166 || ! V_89 )
goto V_175;
}
V_166 = F_104 ( V_20 , V_167 , V_141 , V_168 , V_89 ) ;
V_168 += V_89 ;
V_175:
F_93 () ;
V_2 = F_94 ( V_4 -> V_2 ) ;
if ( V_2 )
F_105 ( V_2 , V_168 - V_143 , V_166 == 0 , 0 ) ;
F_96 () ;
return V_166 ? V_166 : V_168 ;
}
static T_5 F_106 ( struct V_3 * V_4 , struct V_158 * V_159 ,
const struct V_94 * V_141 , unsigned long V_89 ,
int V_91 )
{
F_107 ( V_69 , V_62 ) ;
struct V_19 * V_20 ;
T_5 V_166 = 0 ;
F_108 ( F_27 ( & V_4 -> V_17 ) , & V_69 ) ;
while ( V_89 ) {
V_62 -> V_71 = V_176 ;
V_20 = F_109 ( & V_4 -> V_17 . V_26 ) ;
if ( ! V_20 ) {
if ( V_91 ) {
V_166 = - V_40 ;
break;
}
if ( F_110 ( V_62 ) ) {
V_166 = - V_177 ;
break;
}
F_111 () ;
continue;
}
V_166 = F_98 ( V_4 , V_20 , V_141 , V_89 ) ;
F_28 ( V_20 ) ;
break;
}
V_62 -> V_71 = V_178 ;
F_112 ( F_27 ( & V_4 -> V_17 ) , & V_69 ) ;
return V_166 ;
}
static T_5 F_113 ( struct V_158 * V_159 , const struct V_94 * V_141 ,
unsigned long V_97 , T_6 V_160 )
{
struct V_10 * V_10 = V_159 -> V_161 ;
struct V_3 * V_4 = V_10 -> V_18 ;
T_5 V_89 , V_166 = 0 ;
V_89 = F_71 ( V_141 , V_97 ) ;
if ( V_89 < 0 ) {
V_166 = - V_44 ;
goto V_16;
}
V_166 = F_106 ( V_4 , V_159 , V_141 , V_89 , V_10 -> V_164 & V_165 ) ;
V_166 = F_73 ( T_5 , V_166 , V_89 ) ;
V_16:
return V_166 ;
}
static long F_114 ( struct V_10 * V_10 , unsigned int V_179 ,
unsigned long V_180 )
{
struct V_3 * V_4 = V_10 -> V_18 ;
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
return - V_103 ;
V_166 = 0 ;
if ( ( V_185 & ~ V_77 ) != ( V_78 | V_79 ) )
V_166 = - V_44 ;
else
V_4 -> V_57 = V_185 ;
return V_166 ;
case V_190 :
F_93 () ;
V_2 = F_94 ( V_4 -> V_2 ) ;
if ( V_2 )
F_41 ( V_2 -> V_9 ) ;
F_96 () ;
if ( ! V_2 )
return - V_163 ;
V_166 = 0 ;
if ( F_116 ( & V_183 -> V_191 , V_2 -> V_9 -> V_192 , V_193 ) ||
F_117 ( V_4 -> V_57 , & V_183 -> V_189 ) )
V_166 = - V_103 ;
F_60 ( V_2 -> V_9 ) ;
return V_166 ;
case V_194 :
if ( F_117 ( V_79 | V_78 | V_77 , V_184 ) )
return - V_103 ;
return 0 ;
case V_195 :
if ( F_115 ( V_185 , V_184 ) )
return - V_103 ;
V_4 -> V_17 . V_196 = V_185 ;
return 0 ;
case V_197 :
V_187 = V_4 -> V_80 ;
if ( F_117 ( V_187 , V_186 ) )
return - V_103 ;
return 0 ;
case V_198 :
if ( F_115 ( V_187 , V_186 ) )
return - V_103 ;
if ( V_187 < ( int ) sizeof( struct V_81 ) )
return - V_44 ;
V_4 -> V_80 = V_187 ;
return 0 ;
case V_199 :
if ( V_180 & ~ ( V_200 | V_201 | V_202 |
V_203 | V_204 ) )
return - V_44 ;
if ( ! ( V_4 -> V_57 & V_77 ) )
return - V_44 ;
return 0 ;
default:
return - V_44 ;
}
}
static long F_118 ( struct V_10 * V_10 , unsigned int V_179 ,
unsigned long V_180 )
{
return F_114 ( V_10 , V_179 , ( unsigned long ) F_119 ( V_180 ) ) ;
}
static int F_120 ( struct V_158 * V_159 , struct V_205 * V_53 ,
struct V_139 * V_140 , T_4 V_142 )
{
struct V_3 * V_4 = F_121 ( V_53 , struct V_3 , V_53 ) ;
return F_86 ( V_4 , V_140 , V_140 -> V_206 , V_142 , V_140 -> V_207 ,
V_140 -> V_208 & V_209 ) ;
}
static int F_122 ( struct V_158 * V_159 , struct V_205 * V_53 ,
struct V_139 * V_140 , T_4 V_142 ,
int V_57 )
{
struct V_3 * V_4 = F_121 ( V_53 , struct V_3 , V_53 ) ;
int V_166 ;
if ( V_57 & ~ ( V_209 | V_210 ) )
return - V_44 ;
V_166 = F_106 ( V_4 , V_159 , V_140 -> V_206 , V_142 ,
V_57 & V_209 ) ;
if ( V_166 > V_142 ) {
V_140 -> V_208 |= V_210 ;
V_166 = V_57 & V_210 ? V_166 : V_142 ;
}
return V_166 ;
}
struct V_205 * F_123 ( struct V_10 * V_10 )
{
struct V_3 * V_4 ;
if ( V_10 -> V_211 != & V_212 )
return F_124 ( - V_44 ) ;
V_4 = V_10 -> V_18 ;
if ( ! V_4 )
return F_124 ( - V_213 ) ;
return & V_4 -> V_53 ;
}
static int F_125 ( struct V_214 * V_215 ,
unsigned long V_216 , void * V_217 )
{
struct V_8 * V_9 = V_217 ;
struct V_1 * V_2 ;
struct V_218 * V_219 ;
T_9 V_220 ;
int V_12 ;
if ( V_9 -> V_221 != & V_222 )
return V_223 ;
V_2 = F_5 ( V_9 ) ;
switch ( V_216 ) {
case V_224 :
V_12 = F_31 ( V_2 ) ;
if ( V_12 )
return F_126 ( V_12 ) ;
V_220 = F_127 ( F_128 ( V_225 ) , V_2 -> V_42 ) ;
V_219 = F_129 ( V_226 , & V_9 -> V_9 , V_220 ,
V_9 , L_2 , V_9 -> V_227 ) ;
if ( F_130 ( V_219 ) ) {
F_38 ( V_2 ) ;
return F_126 ( F_131 ( V_219 ) ) ;
}
break;
case V_228 :
V_220 = F_127 ( F_128 ( V_225 ) , V_2 -> V_42 ) ;
F_132 ( V_226 , V_220 ) ;
F_38 ( V_2 ) ;
break;
}
return V_223 ;
}
static int F_133 ( void )
{
int V_12 ;
V_12 = F_134 ( & V_225 , 0 ,
V_41 , L_3 ) ;
if ( V_12 )
goto V_229;
F_135 ( & V_230 , & V_212 ) ;
V_12 = F_136 ( & V_230 , V_225 , V_41 ) ;
if ( V_12 )
goto V_231;
V_226 = F_137 ( V_232 , L_3 ) ;
if ( F_130 ( V_226 ) ) {
V_12 = F_131 ( V_226 ) ;
goto V_233;
}
V_12 = F_138 ( & V_234 ) ;
if ( V_12 )
goto V_235;
V_12 = F_139 ( & V_222 ) ;
if ( V_12 )
goto V_236;
return 0 ;
V_236:
F_140 ( & V_234 ) ;
V_235:
F_141 ( V_226 ) ;
V_233:
F_142 ( & V_230 ) ;
V_231:
F_143 ( V_225 , V_41 ) ;
V_229:
return V_12 ;
}
static void F_144 ( void )
{
F_145 ( & V_222 ) ;
F_140 ( & V_234 ) ;
F_141 ( V_226 ) ;
F_142 ( & V_230 ) ;
F_143 ( V_225 , V_41 ) ;
}
