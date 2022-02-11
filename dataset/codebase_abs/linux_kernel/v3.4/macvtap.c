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
V_106 = F_75 ( V_107 , V_99 , 0 , & V_104 [ V_5 ] ) ;
if ( ( V_106 != V_99 ) ||
( V_106 > V_105 - F_76 ( V_20 ) -> V_110 ) )
return - V_103 ;
V_20 -> V_93 += V_89 ;
V_20 -> V_89 += V_89 ;
V_20 -> V_111 += V_89 ;
F_77 ( V_89 , & V_20 -> V_17 -> V_112 ) ;
while ( V_89 ) {
int V_113 = V_107 & ~ V_108 ;
int V_99 = F_73 ( int , V_89 , V_92 - V_113 ) ;
F_78 ( V_20 , V_5 , V_104 [ V_5 ] , V_113 , V_99 ) ;
F_76 ( V_20 ) -> V_110 ++ ;
V_107 += V_99 ;
V_89 -= V_99 ;
V_5 ++ ;
}
V_100 = 0 ;
++ V_95 ;
}
return 0 ;
}
static int F_79 ( struct V_19 * V_20 ,
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
if ( ! F_80 ( V_20 , V_114 -> V_127 ,
V_114 -> V_128 ) )
return - V_44 ;
}
if ( V_114 -> V_115 != V_116 ) {
F_76 ( V_20 ) -> V_125 = V_114 -> V_125 ;
F_76 ( V_20 ) -> V_115 = V_115 ;
F_76 ( V_20 ) -> V_115 |= V_129 ;
F_76 ( V_20 ) -> V_130 = 0 ;
}
return 0 ;
}
static int F_81 ( const struct V_19 * V_20 ,
struct V_81 * V_114 )
{
memset ( V_114 , 0 , sizeof( * V_114 ) ) ;
if ( F_82 ( V_20 ) ) {
struct V_131 * V_132 = F_76 ( V_20 ) ;
V_114 -> V_133 = F_72 ( V_20 ) ;
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
V_114 -> V_57 = V_126 ;
V_114 -> V_127 = F_84 ( V_20 ) ;
V_114 -> V_128 = V_20 -> V_128 ;
} else if ( V_20 -> V_134 == V_136 ) {
V_114 -> V_57 = V_137 ;
}
return 0 ;
}
static T_5 F_85 ( struct V_3 * V_4 , struct V_138 * V_139 ,
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
V_12 = F_86 ( ( void * ) & V_114 , V_140 , 0 ,
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
if ( F_21 ( V_89 < V_33 ) )
goto V_12;
if ( V_139 && V_139 -> V_145 && F_87 ( & V_4 -> V_17 , V_85 ) )
V_144 = true ;
if ( V_144 ) {
V_143 = V_114 . V_133 ;
if ( ! V_143 )
V_143 = V_146 ;
} else
V_143 = V_89 ;
V_20 = F_66 ( & V_4 -> V_17 , V_147 , V_143 ,
V_114 . V_133 , V_91 , & V_12 ) ;
if ( ! V_20 )
goto V_12;
if ( V_144 ) {
V_12 = F_70 ( V_20 , V_140 , V_142 , V_97 ) ;
F_76 ( V_20 ) -> V_148 |= V_149 ;
} else
V_12 = F_88 ( V_20 , 0 , V_140 , V_142 ,
V_89 ) ;
if ( V_12 )
goto V_150;
F_89 ( V_20 , V_33 ) ;
F_90 ( V_20 ) ;
V_20 -> V_151 = F_91 ( V_20 ) -> V_152 ;
if ( V_142 ) {
V_12 = F_79 ( V_20 , & V_114 ) ;
if ( V_12 )
goto V_150;
}
F_92 () ;
V_2 = F_93 ( V_4 -> V_2 ) ;
if ( V_144 )
F_76 ( V_20 ) -> V_153 = V_139 -> V_145 ;
if ( V_2 )
F_94 ( V_20 , V_2 -> V_9 ) ;
else
F_28 ( V_20 ) ;
F_95 () ;
return V_141 ;
V_150:
F_28 ( V_20 ) ;
V_12:
F_92 () ;
V_2 = F_93 ( V_4 -> V_2 ) ;
if ( V_2 )
V_2 -> V_9 -> V_154 . V_155 ++ ;
F_95 () ;
return V_12 ;
}
static T_5 F_96 ( struct V_156 * V_157 , const struct V_94 * V_140 ,
unsigned long V_97 , T_6 V_158 )
{
struct V_10 * V_10 = V_157 -> V_159 ;
T_5 V_160 = - V_161 ;
struct V_3 * V_4 = V_10 -> V_18 ;
V_160 = F_85 ( V_4 , NULL , V_140 , F_71 ( V_140 , V_97 ) , V_97 ,
V_10 -> V_162 & V_163 ) ;
return V_160 ;
}
static T_5 F_97 ( struct V_3 * V_4 ,
const struct V_19 * V_20 ,
const struct V_94 * V_140 , int V_89 )
{
struct V_1 * V_2 ;
int V_164 ;
int V_142 = 0 ;
int V_165 = 0 ;
int V_166 ;
if ( V_4 -> V_57 & V_77 ) {
struct V_81 V_114 ;
V_142 = V_4 -> V_80 ;
if ( ( V_89 -= V_142 ) < 0 )
return - V_44 ;
V_164 = F_81 ( V_20 , & V_114 ) ;
if ( V_164 )
return V_164 ;
if ( F_98 ( V_140 , ( void * ) & V_114 , 0 , sizeof( V_114 ) ) )
return - V_103 ;
}
V_166 = V_142 ;
if ( ! F_99 ( V_20 ) )
V_89 = F_73 ( int , V_20 -> V_89 , V_89 ) ;
else {
int V_98 ;
struct {
T_7 V_167 ;
T_7 V_168 ;
} V_169 ;
V_169 . V_167 = F_100 ( V_170 ) ;
V_169 . V_168 = F_100 ( F_101 ( V_20 ) ) ;
V_165 = F_102 ( struct V_171 , V_167 ) ;
V_89 = F_73 ( int , V_20 -> V_89 + V_172 , V_89 ) ;
V_98 = F_73 ( int , V_165 , V_89 ) ;
V_164 = F_103 ( V_20 , 0 , V_140 , V_166 , V_98 ) ;
V_89 -= V_98 ;
V_166 += V_98 ;
if ( V_164 || ! V_89 )
goto V_173;
V_98 = F_73 ( int , sizeof( V_169 ) , V_89 ) ;
V_164 = F_98 ( V_140 , ( void * ) & V_169 , V_166 , V_98 ) ;
V_89 -= V_98 ;
V_166 += V_98 ;
if ( V_164 || ! V_89 )
goto V_173;
}
V_164 = F_103 ( V_20 , V_165 , V_140 , V_166 , V_89 ) ;
V_166 += V_89 ;
V_173:
F_92 () ;
V_2 = F_93 ( V_4 -> V_2 ) ;
if ( V_2 )
F_104 ( V_2 , V_166 - V_142 , V_164 == 0 , 0 ) ;
F_95 () ;
return V_164 ? V_164 : V_166 ;
}
static T_5 F_105 ( struct V_3 * V_4 , struct V_156 * V_157 ,
const struct V_94 * V_140 , unsigned long V_89 ,
int V_91 )
{
F_106 ( V_69 , V_62 ) ;
struct V_19 * V_20 ;
T_5 V_164 = 0 ;
F_107 ( F_27 ( & V_4 -> V_17 ) , & V_69 ) ;
while ( V_89 ) {
V_62 -> V_71 = V_174 ;
V_20 = F_108 ( & V_4 -> V_17 . V_26 ) ;
if ( ! V_20 ) {
if ( V_91 ) {
V_164 = - V_40 ;
break;
}
if ( F_109 ( V_62 ) ) {
V_164 = - V_175 ;
break;
}
F_110 () ;
continue;
}
V_164 = F_97 ( V_4 , V_20 , V_140 , V_89 ) ;
F_28 ( V_20 ) ;
break;
}
V_62 -> V_71 = V_176 ;
F_111 ( F_27 ( & V_4 -> V_17 ) , & V_69 ) ;
return V_164 ;
}
static T_5 F_112 ( struct V_156 * V_157 , const struct V_94 * V_140 ,
unsigned long V_97 , T_6 V_158 )
{
struct V_10 * V_10 = V_157 -> V_159 ;
struct V_3 * V_4 = V_10 -> V_18 ;
T_5 V_89 , V_164 = 0 ;
V_89 = F_71 ( V_140 , V_97 ) ;
if ( V_89 < 0 ) {
V_164 = - V_44 ;
goto V_16;
}
V_164 = F_105 ( V_4 , V_157 , V_140 , V_89 , V_10 -> V_162 & V_163 ) ;
V_164 = F_73 ( T_5 , V_164 , V_89 ) ;
V_16:
return V_164 ;
}
static long F_113 ( struct V_10 * V_10 , unsigned int V_177 ,
unsigned long V_178 )
{
struct V_3 * V_4 = V_10 -> V_18 ;
struct V_1 * V_2 ;
void T_8 * V_179 = ( void T_8 * ) V_178 ;
struct V_180 T_8 * V_181 = V_179 ;
unsigned int T_8 * V_182 = V_179 ;
unsigned int V_183 ;
int T_8 * V_184 = V_179 ;
int V_185 ;
int V_164 ;
switch ( V_177 ) {
case V_186 :
if ( F_114 ( V_183 , & V_181 -> V_187 ) )
return - V_103 ;
V_164 = 0 ;
if ( ( V_183 & ~ V_77 ) != ( V_78 | V_79 ) )
V_164 = - V_44 ;
else
V_4 -> V_57 = V_183 ;
return V_164 ;
case V_188 :
F_92 () ;
V_2 = F_93 ( V_4 -> V_2 ) ;
if ( V_2 )
F_41 ( V_2 -> V_9 ) ;
F_95 () ;
if ( ! V_2 )
return - V_161 ;
V_164 = 0 ;
if ( F_115 ( & V_181 -> V_189 , V_2 -> V_9 -> V_190 , V_191 ) ||
F_116 ( V_4 -> V_57 , & V_181 -> V_187 ) )
V_164 = - V_103 ;
F_60 ( V_2 -> V_9 ) ;
return V_164 ;
case V_192 :
if ( F_116 ( V_79 | V_78 | V_77 , V_182 ) )
return - V_103 ;
return 0 ;
case V_193 :
if ( F_114 ( V_183 , V_182 ) )
return - V_103 ;
V_4 -> V_17 . V_194 = V_183 ;
return 0 ;
case V_195 :
V_185 = V_4 -> V_80 ;
if ( F_116 ( V_185 , V_184 ) )
return - V_103 ;
return 0 ;
case V_196 :
if ( F_114 ( V_185 , V_184 ) )
return - V_103 ;
if ( V_185 < ( int ) sizeof( struct V_81 ) )
return - V_44 ;
V_4 -> V_80 = V_185 ;
return 0 ;
case V_197 :
if ( V_178 & ~ ( V_198 | V_199 | V_200 |
V_201 | V_202 ) )
return - V_44 ;
if ( ! ( V_4 -> V_57 & V_77 ) )
return - V_44 ;
return 0 ;
default:
return - V_44 ;
}
}
static long F_117 ( struct V_10 * V_10 , unsigned int V_177 ,
unsigned long V_178 )
{
return F_113 ( V_10 , V_177 , ( unsigned long ) F_118 ( V_178 ) ) ;
}
static int F_119 ( struct V_156 * V_157 , struct V_203 * V_53 ,
struct V_138 * V_139 , T_4 V_141 )
{
struct V_3 * V_4 = F_120 ( V_53 , struct V_3 , V_53 ) ;
return F_85 ( V_4 , V_139 , V_139 -> V_204 , V_141 , V_139 -> V_205 ,
V_139 -> V_206 & V_207 ) ;
}
static int F_121 ( struct V_156 * V_157 , struct V_203 * V_53 ,
struct V_138 * V_139 , T_4 V_141 ,
int V_57 )
{
struct V_3 * V_4 = F_120 ( V_53 , struct V_3 , V_53 ) ;
int V_164 ;
if ( V_57 & ~ ( V_207 | V_208 ) )
return - V_44 ;
V_164 = F_105 ( V_4 , V_157 , V_139 -> V_204 , V_141 ,
V_57 & V_207 ) ;
if ( V_164 > V_141 ) {
V_139 -> V_206 |= V_208 ;
V_164 = V_57 & V_208 ? V_164 : V_141 ;
}
return V_164 ;
}
struct V_203 * F_122 ( struct V_10 * V_10 )
{
struct V_3 * V_4 ;
if ( V_10 -> V_209 != & V_210 )
return F_123 ( - V_44 ) ;
V_4 = V_10 -> V_18 ;
if ( ! V_4 )
return F_123 ( - V_211 ) ;
return & V_4 -> V_53 ;
}
static int F_124 ( struct V_212 * V_213 ,
unsigned long V_214 , void * V_215 )
{
struct V_8 * V_9 = V_215 ;
struct V_1 * V_2 ;
struct V_216 * V_217 ;
T_9 V_218 ;
int V_12 ;
if ( V_9 -> V_219 != & V_220 )
return V_221 ;
V_2 = F_5 ( V_9 ) ;
switch ( V_214 ) {
case V_222 :
V_12 = F_31 ( V_2 ) ;
if ( V_12 )
return F_125 ( V_12 ) ;
V_218 = F_126 ( F_127 ( V_223 ) , V_2 -> V_42 ) ;
V_217 = F_128 ( V_224 , & V_9 -> V_9 , V_218 ,
V_9 , L_2 , V_9 -> V_225 ) ;
if ( F_129 ( V_217 ) ) {
F_38 ( V_2 ) ;
return F_125 ( F_130 ( V_217 ) ) ;
}
break;
case V_226 :
V_218 = F_126 ( F_127 ( V_223 ) , V_2 -> V_42 ) ;
F_131 ( V_224 , V_218 ) ;
F_38 ( V_2 ) ;
break;
}
return V_221 ;
}
static int F_132 ( void )
{
int V_12 ;
V_12 = F_133 ( & V_223 , 0 ,
V_41 , L_3 ) ;
if ( V_12 )
goto V_227;
F_134 ( & V_228 , & V_210 ) ;
V_12 = F_135 ( & V_228 , V_223 , V_41 ) ;
if ( V_12 )
goto V_229;
V_224 = F_136 ( V_230 , L_3 ) ;
if ( F_129 ( V_224 ) ) {
V_12 = F_130 ( V_224 ) ;
goto V_231;
}
V_12 = F_137 ( & V_232 ) ;
if ( V_12 )
goto V_233;
V_12 = F_138 ( & V_220 ) ;
if ( V_12 )
goto V_234;
return 0 ;
V_234:
F_139 ( & V_232 ) ;
V_233:
F_140 ( V_224 ) ;
V_231:
F_141 ( & V_228 ) ;
V_229:
F_142 ( V_223 , V_41 ) ;
V_227:
return V_12 ;
}
static void F_143 ( void )
{
F_144 ( & V_220 ) ;
F_139 ( & V_232 ) ;
F_140 ( V_224 ) ;
F_141 ( & V_228 ) ;
F_142 ( V_223 , V_41 ) ;
}
