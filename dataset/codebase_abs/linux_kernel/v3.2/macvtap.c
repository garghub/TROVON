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
V_2 -> V_15 = V_6 ;
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
static int F_30 ( struct V_1 * V_2 )
{
int V_34 = - V_35 ;
int V_36 ;
F_31 ( & V_37 ) ;
if ( F_32 ( & V_38 , V_39 ) == 0 )
goto exit;
V_34 = F_33 ( & V_38 , V_2 , 1 , & V_36 ) ;
if ( V_34 < 0 ) {
if ( V_34 == - V_40 )
V_34 = - V_35 ;
goto exit;
}
if ( V_36 < V_41 ) {
V_2 -> V_42 = V_36 ;
} else {
F_34 ( V_43 L_1 ) ;
V_34 = - V_44 ;
F_35 ( & V_38 , V_36 ) ;
}
exit:
F_36 ( & V_37 ) ;
return V_34 ;
}
static void F_37 ( struct V_1 * V_2 )
{
F_31 ( & V_37 ) ;
if ( V_2 -> V_42 ) {
F_35 ( & V_38 , V_2 -> V_42 ) ;
V_2 -> V_42 = 0 ;
}
F_36 ( & V_37 ) ;
}
static struct V_8 * F_38 ( int V_42 )
{
struct V_8 * V_9 = NULL ;
struct V_1 * V_2 ;
F_31 ( & V_37 ) ;
V_2 = F_39 ( & V_38 , V_42 ) ;
if ( V_2 ) {
V_9 = V_2 -> V_9 ;
F_40 ( V_9 ) ;
}
F_36 ( & V_37 ) ;
return V_9 ;
}
static int F_41 ( struct V_45 * V_46 ,
struct V_8 * V_9 ,
struct V_47 * V_48 [] ,
struct V_47 * V_49 [] )
{
return F_42 ( V_46 , V_9 , V_48 , V_49 ,
F_28 , F_22 ) ;
}
static void F_43 ( struct V_8 * V_9 ,
struct V_50 * V_51 )
{
F_21 ( V_9 ) ;
F_44 ( V_9 , V_51 ) ;
}
static void F_45 ( struct V_8 * V_9 )
{
F_46 ( V_9 ) ;
V_9 -> V_27 = V_52 ;
}
static void F_47 ( struct V_53 * V_17 )
{
T_2 * V_54 ;
if ( ! F_48 ( V_17 ) ||
! F_49 ( V_55 , & V_17 -> V_56 -> V_57 ) )
return;
V_54 = F_26 ( V_17 ) ;
if ( V_54 && F_50 ( V_54 ) )
F_25 ( V_54 , V_58 | V_59 | V_60 ) ;
}
static void F_51 ( struct V_53 * V_17 )
{
F_52 ( & V_17 -> V_26 ) ;
}
static int F_53 ( struct V_61 * V_61 , struct V_10 * V_10 )
{
struct V_45 * V_45 = V_62 -> V_63 -> V_64 ;
struct V_8 * V_9 = F_38 ( F_54 ( V_61 ) ) ;
struct V_3 * V_4 ;
int V_12 ;
V_12 = - V_65 ;
if ( ! V_9 )
goto V_16;
V_12 = - V_35 ;
V_4 = (struct V_3 * ) F_55 ( V_45 , V_66 , V_39 ,
& V_67 ) ;
if ( ! V_4 )
goto V_16;
V_4 -> V_53 . V_68 = & V_4 -> V_68 ;
F_56 ( & V_4 -> V_68 . V_69 ) ;
V_4 -> V_53 . type = V_70 ;
V_4 -> V_53 . V_71 = V_72 ;
V_4 -> V_53 . V_10 = V_10 ;
V_4 -> V_53 . V_73 = & V_74 ;
F_57 ( & V_4 -> V_53 , & V_4 -> V_17 ) ;
V_4 -> V_17 . V_75 = F_47 ;
V_4 -> V_17 . V_76 = F_51 ;
V_4 -> V_57 = V_77 | V_78 | V_79 ;
V_4 -> V_80 = sizeof( struct V_81 ) ;
if ( ( V_9 -> V_82 & V_83 ) && ( V_9 -> V_82 & V_84 ) )
F_58 ( & V_4 -> V_17 , V_85 ) ;
V_12 = F_4 ( V_9 , V_10 , V_4 ) ;
if ( V_12 )
F_13 ( & V_4 -> V_17 ) ;
V_16:
if ( V_9 )
F_59 ( V_9 ) ;
return V_12 ;
}
static int F_60 ( struct V_61 * V_61 , struct V_10 * V_10 )
{
struct V_3 * V_4 = V_10 -> V_18 ;
F_10 ( V_4 ) ;
return 0 ;
}
static unsigned int F_61 ( struct V_10 * V_10 , T_3 * V_69 )
{
struct V_3 * V_4 = V_10 -> V_18 ;
unsigned int V_86 = V_87 ;
if ( ! V_4 )
goto V_16;
V_86 = 0 ;
F_62 ( V_10 , & V_4 -> V_68 . V_69 , V_69 ) ;
if ( ! F_63 ( & V_4 -> V_17 . V_26 ) )
V_86 |= V_28 | V_29 ;
if ( F_48 ( & V_4 -> V_17 ) ||
( ! F_64 ( V_55 , & V_4 -> V_53 . V_57 ) &&
F_48 ( & V_4 -> V_17 ) ) )
V_86 |= V_58 | V_59 ;
V_16:
return V_86 ;
}
static inline struct V_19 * F_65 ( struct V_53 * V_17 , T_4 V_88 ,
T_4 V_89 , T_4 V_90 ,
int V_91 , int * V_12 )
{
struct V_19 * V_20 ;
if ( V_88 + V_89 < V_92 || ! V_90 )
V_90 = V_89 ;
V_20 = F_66 ( V_17 , V_88 + V_90 , V_89 - V_90 , V_91 ,
V_12 ) ;
if ( ! V_20 )
return NULL ;
F_67 ( V_20 , V_88 ) ;
F_68 ( V_20 , V_90 ) ;
V_20 -> V_93 = V_89 - V_90 ;
V_20 -> V_89 += V_89 - V_90 ;
return V_20 ;
}
static int F_69 ( struct V_19 * V_20 , const struct V_94 * V_95 ,
int V_96 , T_4 V_97 )
{
int V_89 = F_70 ( V_95 , V_97 ) - V_96 ;
int V_98 = F_71 ( V_20 ) ;
int V_99 , V_100 = 0 ;
int V_5 = 0 ;
while ( V_97 && ( V_96 >= V_95 -> V_101 ) ) {
V_96 -= V_95 -> V_101 ;
++ V_95 ;
-- V_97 ;
}
while ( V_97 && ( V_98 > 0 ) ) {
V_99 = F_72 (unsigned int, copy, from->iov_len - offset) ;
if ( F_73 ( V_20 -> V_49 + V_100 , V_95 -> V_102 + V_96 ,
V_99 ) )
return - V_103 ;
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
struct V_104 * V_104 [ V_105 ] ;
int V_106 ;
unsigned long V_107 ;
V_89 = V_95 -> V_101 - V_100 ;
if ( ! V_89 ) {
V_100 = 0 ;
++ V_95 ;
continue;
}
V_107 = ( unsigned long ) V_95 -> V_102 + V_100 ;
V_99 = ( ( V_107 & ~ V_108 ) + V_89 + ~ V_108 ) >> V_109 ;
V_106 = F_74 ( V_107 , V_99 , 0 , & V_104 [ V_5 ] ) ;
if ( ( V_106 != V_99 ) ||
( V_106 > V_105 - F_75 ( V_20 ) -> V_110 ) )
return - V_103 ;
V_20 -> V_93 += V_89 ;
V_20 -> V_89 += V_89 ;
V_20 -> V_111 += V_89 ;
F_76 ( V_89 , & V_20 -> V_17 -> V_112 ) ;
while ( V_89 ) {
int V_113 = V_107 & ~ V_108 ;
int V_99 = F_72 ( int , V_89 , V_92 - V_113 ) ;
F_77 ( V_20 , V_5 , V_104 [ V_5 ] , V_113 , V_99 ) ;
F_75 ( V_20 ) -> V_110 ++ ;
V_107 += V_99 ;
V_89 -= V_99 ;
V_5 ++ ;
}
V_100 = 0 ;
++ V_95 ;
}
return 0 ;
}
static int F_78 ( struct V_19 * V_20 ,
struct V_81 * V_114 )
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
return - V_44 ;
}
if ( V_114 -> V_115 & V_117 )
V_115 |= V_124 ;
if ( V_114 -> V_125 == 0 )
return - V_44 ;
}
if ( V_114 -> V_57 & V_126 ) {
if ( ! F_79 ( V_20 , V_114 -> V_127 ,
V_114 -> V_128 ) )
return - V_44 ;
}
if ( V_114 -> V_115 != V_116 ) {
F_75 ( V_20 ) -> V_125 = V_114 -> V_125 ;
F_75 ( V_20 ) -> V_115 = V_115 ;
F_75 ( V_20 ) -> V_115 |= V_129 ;
F_75 ( V_20 ) -> V_130 = 0 ;
}
return 0 ;
}
static int F_80 ( const struct V_19 * V_20 ,
struct V_81 * V_114 )
{
memset ( V_114 , 0 , sizeof( * V_114 ) ) ;
if ( F_81 ( V_20 ) ) {
struct V_131 * V_132 = F_75 ( V_20 ) ;
V_114 -> V_133 = F_71 ( V_20 ) ;
V_114 -> V_125 = V_132 -> V_125 ;
if ( V_132 -> V_115 & V_119 )
V_114 -> V_115 = V_118 ;
else if ( V_132 -> V_115 & V_121 )
V_114 -> V_115 = V_120 ;
else if ( V_132 -> V_115 & V_123 )
V_114 -> V_115 = V_122 ;
else
F_82 () ;
if ( V_132 -> V_115 & V_124 )
V_114 -> V_115 |= V_117 ;
} else
V_114 -> V_115 = V_116 ;
if ( V_20 -> V_134 == V_135 ) {
V_114 -> V_57 = V_126 ;
V_114 -> V_127 = F_83 ( V_20 ) ;
V_114 -> V_128 = V_20 -> V_128 ;
} else if ( V_20 -> V_134 == V_136 ) {
V_114 -> V_57 = V_137 ;
}
return 0 ;
}
static T_5 F_84 ( struct V_3 * V_4 , struct V_138 * V_139 ,
const struct V_94 * V_140 , unsigned long V_141 ,
T_4 V_97 , int V_91 )
{
struct V_19 * V_20 ;
struct V_1 * V_2 ;
unsigned long V_89 = V_141 ;
int V_12 ;
struct V_81 V_114 = { 0 } ;
int V_142 = 0 ;
int V_143 ;
bool V_144 = false ;
if ( V_4 -> V_57 & V_77 ) {
V_142 = V_4 -> V_80 ;
V_12 = - V_44 ;
if ( V_89 < V_142 )
goto V_12;
V_89 -= V_142 ;
V_12 = F_85 ( ( void * ) & V_114 , V_140 , 0 ,
sizeof( V_114 ) ) ;
if ( V_12 < 0 )
goto V_12;
if ( ( V_114 . V_57 & V_126 ) &&
V_114 . V_127 + V_114 . V_128 + 2 >
V_114 . V_133 )
V_114 . V_133 = V_114 . V_127 +
V_114 . V_128 + 2 ;
V_12 = - V_44 ;
if ( V_114 . V_133 > V_89 )
goto V_12;
}
V_12 = - V_44 ;
if ( F_19 ( V_89 < V_33 ) )
goto V_12;
if ( V_139 && V_139 -> V_145 && F_86 ( & V_4 -> V_17 , V_85 ) )
V_144 = true ;
if ( V_144 ) {
V_143 = V_114 . V_133 ;
if ( ! V_143 )
V_143 = V_146 ;
} else
V_143 = V_89 ;
V_20 = F_65 ( & V_4 -> V_17 , V_147 , V_143 ,
V_114 . V_133 , V_91 , & V_12 ) ;
if ( ! V_20 )
goto V_12;
if ( V_144 ) {
V_12 = F_69 ( V_20 , V_140 , V_142 , V_97 ) ;
F_75 ( V_20 ) -> V_148 |= V_149 ;
} else
V_12 = F_87 ( V_20 , 0 , V_140 , V_142 ,
V_89 ) ;
if ( V_12 )
goto V_150;
F_88 ( V_20 , V_33 ) ;
F_89 ( V_20 ) ;
V_20 -> V_151 = F_90 ( V_20 ) -> V_152 ;
if ( V_142 ) {
V_12 = F_78 ( V_20 , & V_114 ) ;
if ( V_12 )
goto V_150;
}
F_91 () ;
V_2 = F_92 ( V_4 -> V_2 ) ;
if ( V_144 )
F_75 ( V_20 ) -> V_153 = V_139 -> V_145 ;
if ( V_2 )
F_93 ( V_20 , V_2 -> V_9 ) ;
else
F_27 ( V_20 ) ;
F_94 () ;
return V_141 ;
V_150:
F_27 ( V_20 ) ;
V_12:
F_91 () ;
V_2 = F_92 ( V_4 -> V_2 ) ;
if ( V_2 )
V_2 -> V_9 -> V_154 . V_155 ++ ;
F_94 () ;
return V_12 ;
}
static T_5 F_95 ( struct V_156 * V_157 , const struct V_94 * V_140 ,
unsigned long V_97 , T_6 V_158 )
{
struct V_10 * V_10 = V_157 -> V_159 ;
T_5 V_160 = - V_161 ;
struct V_3 * V_4 = V_10 -> V_18 ;
V_160 = F_84 ( V_4 , NULL , V_140 , F_70 ( V_140 , V_97 ) , V_97 ,
V_10 -> V_162 & V_163 ) ;
return V_160 ;
}
static T_5 F_96 ( struct V_3 * V_4 ,
const struct V_19 * V_20 ,
const struct V_94 * V_140 , int V_89 )
{
struct V_1 * V_2 ;
int V_164 ;
int V_142 = 0 ;
if ( V_4 -> V_57 & V_77 ) {
struct V_81 V_114 ;
V_142 = V_4 -> V_80 ;
if ( ( V_89 -= V_142 ) < 0 )
return - V_44 ;
V_164 = F_80 ( V_20 , & V_114 ) ;
if ( V_164 )
return V_164 ;
if ( F_97 ( V_140 , ( void * ) & V_114 , 0 , sizeof( V_114 ) ) )
return - V_103 ;
}
V_89 = F_72 ( int , V_20 -> V_89 , V_89 ) ;
V_164 = F_98 ( V_20 , 0 , V_140 , V_142 , V_89 ) ;
F_91 () ;
V_2 = F_92 ( V_4 -> V_2 ) ;
if ( V_2 )
F_99 ( V_2 , V_89 , V_164 == 0 , 0 ) ;
F_94 () ;
return V_164 ? V_164 : ( V_89 + V_142 ) ;
}
static T_5 F_100 ( struct V_3 * V_4 , struct V_156 * V_157 ,
const struct V_94 * V_140 , unsigned long V_89 ,
int V_91 )
{
F_101 ( V_69 , V_62 ) ;
struct V_19 * V_20 ;
T_5 V_164 = 0 ;
F_102 ( F_26 ( & V_4 -> V_17 ) , & V_69 ) ;
while ( V_89 ) {
V_62 -> V_71 = V_165 ;
V_20 = F_103 ( & V_4 -> V_17 . V_26 ) ;
if ( ! V_20 ) {
if ( V_91 ) {
V_164 = - V_40 ;
break;
}
if ( F_104 ( V_62 ) ) {
V_164 = - V_166 ;
break;
}
F_105 () ;
continue;
}
V_164 = F_96 ( V_4 , V_20 , V_140 , V_89 ) ;
F_27 ( V_20 ) ;
break;
}
V_62 -> V_71 = V_167 ;
F_106 ( F_26 ( & V_4 -> V_17 ) , & V_69 ) ;
return V_164 ;
}
static T_5 F_107 ( struct V_156 * V_157 , const struct V_94 * V_140 ,
unsigned long V_97 , T_6 V_158 )
{
struct V_10 * V_10 = V_157 -> V_159 ;
struct V_3 * V_4 = V_10 -> V_18 ;
T_5 V_89 , V_164 = 0 ;
V_89 = F_70 ( V_140 , V_97 ) ;
if ( V_89 < 0 ) {
V_164 = - V_44 ;
goto V_16;
}
V_164 = F_100 ( V_4 , V_157 , V_140 , V_89 , V_10 -> V_162 & V_163 ) ;
V_164 = F_72 ( T_5 , V_164 , V_89 ) ;
V_16:
return V_164 ;
}
static long F_108 ( struct V_10 * V_10 , unsigned int V_168 ,
unsigned long V_169 )
{
struct V_3 * V_4 = V_10 -> V_18 ;
struct V_1 * V_2 ;
void T_7 * V_170 = ( void T_7 * ) V_169 ;
struct V_171 T_7 * V_172 = V_170 ;
unsigned int T_7 * V_173 = V_170 ;
unsigned int V_174 ;
int T_7 * V_175 = V_170 ;
int V_176 ;
int V_164 ;
switch ( V_168 ) {
case V_177 :
if ( F_109 ( V_174 , & V_172 -> V_178 ) )
return - V_103 ;
V_164 = 0 ;
if ( ( V_174 & ~ V_77 ) != ( V_78 | V_79 ) )
V_164 = - V_44 ;
else
V_4 -> V_57 = V_174 ;
return V_164 ;
case V_179 :
F_91 () ;
V_2 = F_92 ( V_4 -> V_2 ) ;
if ( V_2 )
F_40 ( V_2 -> V_9 ) ;
F_94 () ;
if ( ! V_2 )
return - V_161 ;
V_164 = 0 ;
if ( F_110 ( & V_172 -> V_180 , V_2 -> V_9 -> V_181 , V_182 ) ||
F_111 ( V_4 -> V_57 , & V_172 -> V_178 ) )
V_164 = - V_103 ;
F_59 ( V_2 -> V_9 ) ;
return V_164 ;
case V_183 :
if ( F_111 ( V_79 | V_78 | V_77 , V_173 ) )
return - V_103 ;
return 0 ;
case V_184 :
if ( F_109 ( V_174 , V_173 ) )
return - V_103 ;
V_4 -> V_17 . V_185 = V_174 ;
return 0 ;
case V_186 :
V_176 = V_4 -> V_80 ;
if ( F_111 ( V_176 , V_175 ) )
return - V_103 ;
return 0 ;
case V_187 :
if ( F_109 ( V_176 , V_175 ) )
return - V_103 ;
if ( V_176 < ( int ) sizeof( struct V_81 ) )
return - V_44 ;
V_4 -> V_80 = V_176 ;
return 0 ;
case V_188 :
if ( V_169 & ~ ( V_189 | V_190 | V_191 |
V_192 | V_193 ) )
return - V_44 ;
if ( ! ( V_4 -> V_57 & V_77 ) )
return - V_44 ;
return 0 ;
default:
return - V_44 ;
}
}
static long F_112 ( struct V_10 * V_10 , unsigned int V_168 ,
unsigned long V_169 )
{
return F_108 ( V_10 , V_168 , ( unsigned long ) F_113 ( V_169 ) ) ;
}
static int F_114 ( struct V_156 * V_157 , struct V_194 * V_53 ,
struct V_138 * V_139 , T_4 V_141 )
{
struct V_3 * V_4 = F_115 ( V_53 , struct V_3 , V_53 ) ;
return F_84 ( V_4 , V_139 , V_139 -> V_195 , V_141 , V_139 -> V_196 ,
V_139 -> V_197 & V_198 ) ;
}
static int F_116 ( struct V_156 * V_157 , struct V_194 * V_53 ,
struct V_138 * V_139 , T_4 V_141 ,
int V_57 )
{
struct V_3 * V_4 = F_115 ( V_53 , struct V_3 , V_53 ) ;
int V_164 ;
if ( V_57 & ~ ( V_198 | V_199 ) )
return - V_44 ;
V_164 = F_100 ( V_4 , V_157 , V_139 -> V_195 , V_141 ,
V_57 & V_198 ) ;
if ( V_164 > V_141 ) {
V_139 -> V_197 |= V_199 ;
V_164 = V_57 & V_199 ? V_164 : V_141 ;
}
return V_164 ;
}
struct V_194 * F_117 ( struct V_10 * V_10 )
{
struct V_3 * V_4 ;
if ( V_10 -> V_200 != & V_201 )
return F_118 ( - V_44 ) ;
V_4 = V_10 -> V_18 ;
if ( ! V_4 )
return F_118 ( - V_202 ) ;
return & V_4 -> V_53 ;
}
static int F_119 ( struct V_203 * V_204 ,
unsigned long V_205 , void * V_206 )
{
struct V_8 * V_9 = V_206 ;
struct V_1 * V_2 ;
struct V_207 * V_208 ;
T_8 V_209 ;
int V_12 ;
if ( V_9 -> V_210 != & V_211 )
return V_212 ;
V_2 = F_5 ( V_9 ) ;
switch ( V_205 ) {
case V_213 :
V_12 = F_30 ( V_2 ) ;
if ( V_12 )
return F_120 ( V_12 ) ;
V_209 = F_121 ( F_122 ( V_214 ) , V_2 -> V_42 ) ;
V_208 = F_123 ( V_215 , & V_9 -> V_9 , V_209 ,
V_9 , L_2 , V_9 -> V_216 ) ;
if ( F_124 ( V_208 ) ) {
F_37 ( V_2 ) ;
return F_120 ( F_125 ( V_208 ) ) ;
}
break;
case V_217 :
V_209 = F_121 ( F_122 ( V_214 ) , V_2 -> V_42 ) ;
F_126 ( V_215 , V_209 ) ;
F_37 ( V_2 ) ;
break;
}
return V_212 ;
}
static int F_127 ( void )
{
int V_12 ;
V_12 = F_128 ( & V_214 , 0 ,
V_41 , L_3 ) ;
if ( V_12 )
goto V_218;
F_129 ( & V_219 , & V_201 ) ;
V_12 = F_130 ( & V_219 , V_214 , V_41 ) ;
if ( V_12 )
goto V_220;
V_215 = F_131 ( V_221 , L_3 ) ;
if ( F_124 ( V_215 ) ) {
V_12 = F_125 ( V_215 ) ;
goto V_222;
}
V_12 = F_132 ( & V_223 ) ;
if ( V_12 )
goto V_224;
V_12 = F_133 ( & V_211 ) ;
if ( V_12 )
goto V_225;
return 0 ;
V_225:
F_134 ( & V_223 ) ;
V_224:
F_135 ( V_215 ) ;
V_222:
F_136 ( & V_219 ) ;
V_220:
F_137 ( V_214 , V_41 ) ;
V_218:
return V_12 ;
}
static void F_138 ( void )
{
F_139 ( & V_211 ) ;
F_134 ( & V_223 ) ;
F_135 ( V_215 ) ;
F_136 ( & V_219 ) ;
F_137 ( V_214 , V_41 ) ;
}
