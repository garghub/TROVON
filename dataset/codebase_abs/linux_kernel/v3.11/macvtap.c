static int F_1 ( struct V_1 * V_2 , struct V_3 * V_3 ,
struct V_4 * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
int V_8 = - V_9 ;
F_3 () ;
if ( V_5 -> V_10 )
goto V_11;
V_8 = 0 ;
F_4 ( V_7 -> V_12 [ V_7 -> V_13 ] , V_5 ) ;
V_5 -> V_14 = V_7 -> V_13 ;
V_5 -> V_10 = true ;
V_7 -> V_13 ++ ;
V_11:
return V_8 ;
}
static int F_5 ( struct V_1 * V_2 , struct V_3 * V_3 ,
struct V_4 * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
int V_8 = - V_15 ;
F_6 () ;
if ( V_7 -> V_16 == V_17 )
goto V_11;
V_8 = 0 ;
F_4 ( V_5 -> V_7 , V_7 ) ;
F_4 ( V_7 -> V_12 [ V_7 -> V_13 ] , V_5 ) ;
F_7 ( & V_5 -> V_18 ) ;
V_5 -> V_3 = V_3 ;
V_5 -> V_14 = V_7 -> V_13 ;
V_5 -> V_10 = true ;
V_3 -> V_19 = V_5 ;
F_8 ( & V_5 -> V_20 , & V_7 -> V_21 ) ;
V_7 -> V_13 ++ ;
V_7 -> V_16 ++ ;
V_11:
F_9 () ;
return V_8 ;
}
static int F_10 ( struct V_4 * V_5 )
{
struct V_6 * V_7 ;
struct V_4 * V_22 ;
F_3 () ;
if ( ! V_5 -> V_10 )
return - V_9 ;
V_7 = F_11 ( V_5 -> V_7 ) ;
if ( V_7 ) {
int V_23 = V_5 -> V_14 ;
F_12 ( V_23 >= V_7 -> V_13 ) ;
V_22 = F_11 ( V_7 -> V_12 [ V_7 -> V_13 - 1 ] ) ;
V_22 -> V_14 = V_23 ;
F_4 ( V_7 -> V_12 [ V_23 ] , V_22 ) ;
F_13 ( V_7 -> V_12 [ V_7 -> V_13 - 1 ] , NULL ) ;
V_5 -> V_10 = false ;
V_7 -> V_13 -- ;
}
return 0 ;
}
static void F_14 ( struct V_4 * V_5 )
{
struct V_6 * V_7 ;
F_6 () ;
V_7 = F_11 ( V_5 -> V_7 ) ;
if ( V_7 ) {
if ( V_5 -> V_10 )
F_12 ( F_10 ( V_5 ) ) ;
V_7 -> V_16 -- ;
F_13 ( V_5 -> V_7 , NULL ) ;
F_15 ( & V_5 -> V_18 ) ;
F_16 ( & V_5 -> V_20 ) ;
}
F_9 () ;
F_17 () ;
F_15 ( & V_5 -> V_18 ) ;
}
static struct V_4 * F_18 ( struct V_1 * V_2 ,
struct V_24 * V_25 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_4 * V_26 = NULL ;
int V_13 = F_19 ( V_7 -> V_13 ) ;
T_1 V_27 ;
if ( ! V_13 )
goto V_11;
V_27 = F_20 ( V_25 ) ;
if ( V_27 ) {
V_26 = F_21 ( V_7 -> V_12 [ V_27 % V_13 ] ) ;
goto V_11;
}
if ( F_22 ( F_23 ( V_25 ) ) ) {
V_27 = F_24 ( V_25 ) ;
while ( F_25 ( V_27 >= V_13 ) )
V_27 -= V_13 ;
V_26 = F_21 ( V_7 -> V_12 [ V_27 ] ) ;
goto V_11;
}
V_26 = F_21 ( V_7 -> V_12 [ 0 ] ) ;
V_11:
return V_26 ;
}
static void F_26 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_4 * V_5 , * V_28 , * V_29 [ V_17 ] ;
int V_30 , V_31 = 0 ;
F_3 () ;
F_27 (q, tmp, &vlan->queue_list, next) {
F_16 ( & V_5 -> V_20 ) ;
V_29 [ V_31 ++ ] = V_5 ;
F_13 ( V_5 -> V_7 , NULL ) ;
if ( V_5 -> V_10 )
V_7 -> V_13 -- ;
V_7 -> V_16 -- ;
}
for ( V_30 = 0 ; V_30 < V_7 -> V_13 ; V_30 ++ )
F_13 ( V_7 -> V_12 [ V_30 ] , NULL ) ;
F_12 ( V_7 -> V_13 ) ;
F_12 ( V_7 -> V_16 ) ;
V_7 -> V_13 = V_17 ;
for ( -- V_31 ; V_31 >= 0 ; V_31 -- )
F_15 ( & V_29 [ V_31 ] -> V_18 ) ;
}
static int F_28 ( struct V_1 * V_2 , struct V_24 * V_25 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_4 * V_5 = F_18 ( V_2 , V_25 ) ;
T_2 V_32 = V_33 ;
if ( ! V_5 )
goto V_34;
if ( F_29 ( & V_5 -> V_18 . V_35 ) >= V_2 -> V_36 )
goto V_34;
V_25 -> V_2 = V_2 ;
if ( V_5 -> V_37 & V_38 )
V_32 |= V_7 -> V_39 ;
if ( F_30 ( V_25 , V_32 ) ) {
struct V_24 * V_40 = F_31 ( V_25 , V_32 , false ) ;
if ( F_32 ( V_40 ) )
goto V_34;
if ( ! V_40 ) {
F_33 ( & V_5 -> V_18 . V_35 , V_25 ) ;
goto V_41;
}
F_34 ( V_25 ) ;
while ( V_40 ) {
struct V_24 * V_42 = V_40 -> V_20 ;
V_40 -> V_20 = NULL ;
F_33 ( & V_5 -> V_18 . V_35 , V_40 ) ;
V_40 = V_42 ;
}
} else {
F_33 ( & V_5 -> V_18 . V_35 , V_25 ) ;
}
V_41:
F_35 ( F_36 ( & V_5 -> V_18 ) , V_43 | V_44 | V_45 ) ;
return V_46 ;
V_34:
F_34 ( V_25 ) ;
return V_47 ;
}
static int F_37 ( struct V_24 * V_25 )
{
F_38 ( V_25 , V_48 ) ;
return F_28 ( V_25 -> V_2 , V_25 ) ;
}
static int F_39 ( struct V_6 * V_7 )
{
int V_49 = - V_50 ;
F_40 ( & V_51 ) ;
V_49 = F_41 ( & V_52 , V_7 , 1 , V_53 , V_54 ) ;
if ( V_49 >= 0 ) {
V_7 -> V_55 = V_49 ;
} else if ( V_49 == - V_56 ) {
F_42 ( V_57 L_1 ) ;
V_49 = - V_9 ;
}
F_43 ( & V_51 ) ;
return V_49 < 0 ? V_49 : 0 ;
}
static void F_44 ( struct V_6 * V_7 )
{
F_40 ( & V_51 ) ;
if ( V_7 -> V_55 ) {
F_45 ( & V_52 , V_7 -> V_55 ) ;
V_7 -> V_55 = 0 ;
}
F_43 ( & V_51 ) ;
}
static struct V_1 * F_46 ( int V_55 )
{
struct V_1 * V_2 = NULL ;
struct V_6 * V_7 ;
F_40 ( & V_51 ) ;
V_7 = F_47 ( & V_52 , V_55 ) ;
if ( V_7 ) {
V_2 = V_7 -> V_2 ;
F_48 ( V_2 ) ;
}
F_43 ( & V_51 ) ;
return V_2 ;
}
static int F_49 ( struct V_58 * V_59 ,
struct V_1 * V_2 ,
struct V_60 * V_61 [] ,
struct V_60 * V_62 [] )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
F_50 ( & V_7 -> V_21 ) ;
V_7 -> V_39 = V_63 ;
return F_51 ( V_59 , V_2 , V_61 , V_62 ,
F_37 , F_28 ) ;
}
static void F_52 ( struct V_1 * V_2 ,
struct V_64 * V_65 )
{
F_26 ( V_2 ) ;
F_53 ( V_2 , V_65 ) ;
}
static void F_54 ( struct V_1 * V_2 )
{
F_55 ( V_2 ) ;
V_2 -> V_36 = V_66 ;
}
static void F_56 ( struct V_67 * V_18 )
{
T_3 * V_68 ;
if ( ! F_57 ( V_18 ) ||
! F_58 ( V_69 , & V_18 -> V_70 -> V_37 ) )
return;
V_68 = F_36 ( V_18 ) ;
if ( V_68 && F_59 ( V_68 ) )
F_35 ( V_68 , V_71 | V_72 | V_73 ) ;
}
static void F_60 ( struct V_67 * V_18 )
{
F_61 ( & V_18 -> V_35 ) ;
}
static int F_62 ( struct V_74 * V_74 , struct V_3 * V_3 )
{
struct V_58 * V_58 = V_75 -> V_76 -> V_77 ;
struct V_1 * V_2 = F_46 ( F_63 ( V_74 ) ) ;
struct V_4 * V_5 ;
int V_8 ;
V_8 = - V_78 ;
if ( ! V_2 )
goto V_11;
V_8 = - V_50 ;
V_5 = (struct V_4 * ) F_64 ( V_58 , V_79 , V_54 ,
& V_80 ) ;
if ( ! V_5 )
goto V_11;
F_13 ( V_5 -> V_67 . V_81 , & V_5 -> V_81 ) ;
F_65 ( & V_5 -> V_81 . V_82 ) ;
V_5 -> V_67 . type = V_83 ;
V_5 -> V_67 . V_84 = V_85 ;
V_5 -> V_67 . V_3 = V_3 ;
V_5 -> V_67 . V_86 = & V_87 ;
F_66 ( & V_5 -> V_67 , & V_5 -> V_18 ) ;
V_5 -> V_18 . V_88 = F_56 ;
V_5 -> V_18 . V_89 = F_60 ;
V_5 -> V_37 = V_38 | V_90 | V_91 ;
V_5 -> V_92 = sizeof( struct V_93 ) ;
if ( ( V_2 -> V_32 & V_94 ) && ( V_2 -> V_32 & V_95 ) )
F_67 ( & V_5 -> V_18 , V_96 ) ;
V_8 = F_5 ( V_2 , V_3 , V_5 ) ;
if ( V_8 )
F_15 ( & V_5 -> V_18 ) ;
V_11:
if ( V_2 )
F_68 ( V_2 ) ;
return V_8 ;
}
static int F_69 ( struct V_74 * V_74 , struct V_3 * V_3 )
{
struct V_4 * V_5 = V_3 -> V_19 ;
F_14 ( V_5 ) ;
return 0 ;
}
static unsigned int F_70 ( struct V_3 * V_3 , T_4 * V_82 )
{
struct V_4 * V_5 = V_3 -> V_19 ;
unsigned int V_97 = V_98 ;
if ( ! V_5 )
goto V_11;
V_97 = 0 ;
F_71 ( V_3 , & V_5 -> V_81 . V_82 , V_82 ) ;
if ( ! F_72 ( & V_5 -> V_18 . V_35 ) )
V_97 |= V_43 | V_44 ;
if ( F_57 ( & V_5 -> V_18 ) ||
( ! F_73 ( V_69 , & V_5 -> V_67 . V_37 ) &&
F_57 ( & V_5 -> V_18 ) ) )
V_97 |= V_71 | V_72 ;
V_11:
return V_97 ;
}
static inline struct V_24 * F_74 ( struct V_67 * V_18 , T_5 V_99 ,
T_5 V_100 , T_5 V_101 ,
int V_102 , int * V_8 )
{
struct V_24 * V_25 ;
if ( V_99 + V_100 < V_103 || ! V_101 )
V_101 = V_100 ;
V_25 = F_75 ( V_18 , V_99 + V_101 , V_100 - V_101 , V_102 ,
V_8 ) ;
if ( ! V_25 )
return NULL ;
F_76 ( V_25 , V_99 ) ;
F_77 ( V_25 , V_101 ) ;
V_25 -> V_104 = V_100 - V_101 ;
V_25 -> V_100 += V_100 - V_101 ;
return V_25 ;
}
static int F_78 ( struct V_24 * V_25 , const struct V_105 * V_106 ,
int V_107 , T_5 V_108 )
{
int V_100 = F_79 ( V_106 , V_108 ) - V_107 ;
int V_109 = F_80 ( V_25 ) ;
int V_110 , V_111 = 0 ;
int V_30 = 0 ;
while ( V_108 && ( V_107 >= V_106 -> V_112 ) ) {
V_107 -= V_106 -> V_112 ;
++ V_106 ;
-- V_108 ;
}
while ( V_108 && ( V_109 > 0 ) ) {
V_110 = F_81 (unsigned int, copy, from->iov_len - offset) ;
if ( F_82 ( V_25 -> V_62 + V_111 , V_106 -> V_113 + V_107 ,
V_110 ) )
return - V_114 ;
if ( V_109 > V_110 ) {
++ V_106 ;
-- V_108 ;
V_107 = 0 ;
} else
V_107 += V_110 ;
V_109 -= V_110 ;
V_111 += V_110 ;
}
if ( V_100 == V_111 )
return 0 ;
while ( V_108 -- ) {
struct V_115 * V_115 [ V_116 ] ;
int V_117 ;
unsigned long V_118 ;
unsigned long V_119 ;
V_100 = V_106 -> V_112 - V_107 ;
if ( ! V_100 ) {
V_107 = 0 ;
++ V_106 ;
continue;
}
V_118 = ( unsigned long ) V_106 -> V_113 + V_107 ;
V_110 = ( ( V_118 & ~ V_120 ) + V_100 + ~ V_120 ) >> V_121 ;
if ( V_30 + V_110 > V_116 )
return - V_122 ;
V_117 = F_83 ( V_118 , V_110 , 0 , & V_115 [ V_30 ] ) ;
if ( V_117 != V_110 ) {
int V_31 ;
for ( V_31 = 0 ; V_31 < V_117 ; V_31 ++ )
F_84 ( V_115 [ V_30 + V_31 ] ) ;
return - V_114 ;
}
V_119 = V_110 * V_103 ;
V_25 -> V_104 += V_100 ;
V_25 -> V_100 += V_100 ;
V_25 -> V_119 += V_119 ;
F_85 ( V_119 , & V_25 -> V_18 -> V_123 ) ;
while ( V_100 ) {
int V_124 = V_118 & ~ V_120 ;
int V_110 = F_81 ( int , V_100 , V_103 - V_124 ) ;
F_86 ( V_25 , V_30 , V_115 [ V_30 ] , V_124 , V_110 ) ;
F_87 ( V_25 ) -> V_125 ++ ;
V_118 += V_110 ;
V_100 -= V_110 ;
V_30 ++ ;
}
V_107 = 0 ;
++ V_106 ;
}
return 0 ;
}
static int F_88 ( struct V_24 * V_25 ,
struct V_93 * V_126 )
{
unsigned short V_127 = 0 ;
if ( V_126 -> V_127 != V_128 ) {
switch ( V_126 -> V_127 & ~ V_129 ) {
case V_130 :
V_127 = V_131 ;
break;
case V_132 :
V_127 = V_133 ;
break;
case V_134 :
V_127 = V_135 ;
break;
default:
return - V_9 ;
}
if ( V_126 -> V_127 & V_129 )
V_127 |= V_136 ;
if ( V_126 -> V_137 == 0 )
return - V_9 ;
}
if ( V_126 -> V_37 & V_138 ) {
if ( ! F_89 ( V_25 , V_126 -> V_139 ,
V_126 -> V_140 ) )
return - V_9 ;
}
if ( V_126 -> V_127 != V_128 ) {
F_87 ( V_25 ) -> V_137 = V_126 -> V_137 ;
F_87 ( V_25 ) -> V_127 = V_127 ;
F_87 ( V_25 ) -> V_127 |= V_141 ;
F_87 ( V_25 ) -> V_142 = 0 ;
}
return 0 ;
}
static int F_90 ( const struct V_24 * V_25 ,
struct V_93 * V_126 )
{
memset ( V_126 , 0 , sizeof( * V_126 ) ) ;
if ( F_91 ( V_25 ) ) {
struct V_143 * V_144 = F_87 ( V_25 ) ;
V_126 -> V_145 = F_80 ( V_25 ) ;
V_126 -> V_137 = V_144 -> V_137 ;
if ( V_144 -> V_127 & V_131 )
V_126 -> V_127 = V_130 ;
else if ( V_144 -> V_127 & V_133 )
V_126 -> V_127 = V_132 ;
else if ( V_144 -> V_127 & V_135 )
V_126 -> V_127 = V_134 ;
else
F_92 () ;
if ( V_144 -> V_127 & V_136 )
V_126 -> V_127 |= V_129 ;
} else
V_126 -> V_127 = V_128 ;
if ( V_25 -> V_146 == V_147 ) {
V_126 -> V_37 = V_138 ;
V_126 -> V_139 = F_93 ( V_25 ) ;
V_126 -> V_140 = V_25 -> V_140 ;
} else if ( V_25 -> V_146 == V_148 ) {
V_126 -> V_37 = V_149 ;
}
return 0 ;
}
static unsigned long F_94 ( const struct V_105 * V_150 , int V_107 ,
unsigned long V_151 )
{
unsigned long V_152 , V_118 ;
int V_153 = 0 , V_100 , V_110 ;
while ( V_151 && ( V_107 >= V_150 -> V_112 ) ) {
V_107 -= V_150 -> V_112 ;
++ V_150 ;
-- V_151 ;
}
for ( V_152 = 0 ; V_152 < V_151 ; V_152 ++ ) {
V_118 = ( unsigned long ) V_150 [ V_152 ] . V_113 + V_107 ;
V_100 = V_150 [ V_152 ] . V_112 - V_107 ;
V_110 = ( ( V_118 & ~ V_120 ) + V_100 + ~ V_120 ) >> V_121 ;
V_153 += V_110 ;
V_107 = 0 ;
}
return V_153 ;
}
static T_6 F_95 ( struct V_4 * V_5 , struct V_154 * V_155 ,
const struct V_105 * V_150 , unsigned long V_156 ,
T_5 V_108 , int V_102 )
{
struct V_24 * V_25 ;
struct V_6 * V_7 ;
unsigned long V_100 = V_156 ;
int V_8 ;
struct V_93 V_126 = { 0 } ;
int V_157 = 0 ;
int V_158 = 0 ;
bool V_159 = false ;
T_5 V_101 ;
if ( V_5 -> V_37 & V_38 ) {
V_157 = V_5 -> V_92 ;
V_8 = - V_9 ;
if ( V_100 < V_157 )
goto V_8;
V_100 -= V_157 ;
V_8 = F_96 ( ( void * ) & V_126 , V_150 , 0 ,
sizeof( V_126 ) ) ;
if ( V_8 < 0 )
goto V_8;
if ( ( V_126 . V_37 & V_138 ) &&
V_126 . V_139 + V_126 . V_140 + 2 >
V_126 . V_145 )
V_126 . V_145 = V_126 . V_139 +
V_126 . V_140 + 2 ;
V_8 = - V_9 ;
if ( V_126 . V_145 > V_100 )
goto V_8;
}
V_8 = - V_9 ;
if ( F_25 ( V_100 < V_48 ) )
goto V_8;
V_8 = - V_122 ;
if ( F_25 ( V_108 > V_160 ) )
goto V_8;
if ( V_155 && V_155 -> V_161 && F_97 ( & V_5 -> V_18 , V_96 ) ) {
V_158 = V_126 . V_145 ? V_126 . V_145 : V_162 ;
V_101 = V_158 ;
if ( F_94 ( V_150 , V_157 + V_158 , V_108 )
<= V_116 )
V_159 = true ;
}
if ( ! V_159 ) {
V_158 = V_100 ;
V_101 = V_126 . V_145 ;
}
V_25 = F_74 ( & V_5 -> V_18 , V_163 , V_158 ,
V_101 , V_102 , & V_8 ) ;
if ( ! V_25 )
goto V_8;
if ( V_159 )
V_8 = F_78 ( V_25 , V_150 , V_157 , V_108 ) ;
else {
V_8 = F_98 ( V_25 , 0 , V_150 , V_157 ,
V_100 ) ;
if ( ! V_8 && V_155 && V_155 -> V_161 ) {
struct V_164 * V_165 = V_155 -> V_161 ;
V_165 -> V_166 ( V_165 , false ) ;
}
}
if ( V_8 )
goto V_167;
F_99 ( V_25 , V_48 ) ;
F_100 ( V_25 ) ;
V_25 -> V_168 = F_101 ( V_25 ) -> V_169 ;
if ( V_157 ) {
V_8 = F_88 ( V_25 , & V_126 ) ;
if ( V_8 )
goto V_167;
}
F_102 ( V_25 , V_48 ) ;
F_103 () ;
V_7 = F_21 ( V_5 -> V_7 ) ;
if ( V_159 ) {
F_87 ( V_25 ) -> V_170 = V_155 -> V_161 ;
F_87 ( V_25 ) -> V_171 |= V_172 ;
F_87 ( V_25 ) -> V_171 |= V_173 ;
}
if ( V_7 ) {
F_104 () ;
F_105 ( V_25 , V_7 -> V_2 ) ;
F_106 () ;
} else {
F_34 ( V_25 ) ;
}
F_107 () ;
return V_156 ;
V_167:
F_34 ( V_25 ) ;
V_8:
F_103 () ;
V_7 = F_21 ( V_5 -> V_7 ) ;
if ( V_7 )
V_7 -> V_2 -> V_174 . V_175 ++ ;
F_107 () ;
return V_8 ;
}
static T_6 F_108 ( struct V_176 * V_177 , const struct V_105 * V_150 ,
unsigned long V_108 , T_7 V_178 )
{
struct V_3 * V_3 = V_177 -> V_179 ;
T_6 V_180 = - V_181 ;
struct V_4 * V_5 = V_3 -> V_19 ;
V_180 = F_95 ( V_5 , NULL , V_150 , F_79 ( V_150 , V_108 ) , V_108 ,
V_3 -> V_182 & V_183 ) ;
return V_180 ;
}
static T_6 F_109 ( struct V_4 * V_5 ,
const struct V_24 * V_25 ,
const struct V_105 * V_150 , int V_100 )
{
struct V_6 * V_7 ;
int V_184 ;
int V_157 = 0 ;
int V_185 = 0 ;
int V_186 ;
if ( V_5 -> V_37 & V_38 ) {
struct V_93 V_126 ;
V_157 = V_5 -> V_92 ;
if ( ( V_100 -= V_157 ) < 0 )
return - V_9 ;
V_184 = F_90 ( V_25 , & V_126 ) ;
if ( V_184 )
return V_184 ;
if ( F_110 ( V_150 , ( void * ) & V_126 , 0 , sizeof( V_126 ) ) )
return - V_114 ;
}
V_186 = V_157 ;
if ( ! F_111 ( V_25 ) )
V_100 = F_81 ( int , V_25 -> V_100 , V_100 ) ;
else {
int V_109 ;
struct {
T_8 V_187 ;
T_8 V_188 ;
} V_189 ;
V_189 . V_187 = V_25 -> V_190 ;
V_189 . V_188 = F_112 ( F_113 ( V_25 ) ) ;
V_185 = F_114 ( struct V_191 , V_187 ) ;
V_100 = F_81 ( int , V_25 -> V_100 + V_192 , V_100 ) ;
V_109 = F_81 ( int , V_185 , V_100 ) ;
V_184 = F_115 ( V_25 , 0 , V_150 , V_186 , V_109 ) ;
V_100 -= V_109 ;
V_186 += V_109 ;
if ( V_184 || ! V_100 )
goto V_193;
V_109 = F_81 ( int , sizeof( V_189 ) , V_100 ) ;
V_184 = F_110 ( V_150 , ( void * ) & V_189 , V_186 , V_109 ) ;
V_100 -= V_109 ;
V_186 += V_109 ;
if ( V_184 || ! V_100 )
goto V_193;
}
V_184 = F_115 ( V_25 , V_185 , V_150 , V_186 , V_100 ) ;
V_186 += V_100 ;
V_193:
F_103 () ;
V_7 = F_21 ( V_5 -> V_7 ) ;
if ( V_7 ) {
F_116 () ;
F_117 ( V_7 , V_186 - V_157 , V_184 == 0 , 0 ) ;
F_118 () ;
}
F_107 () ;
return V_184 ? V_184 : V_186 ;
}
static T_6 F_119 ( struct V_4 * V_5 , struct V_176 * V_177 ,
const struct V_105 * V_150 , unsigned long V_100 ,
int V_102 )
{
F_120 ( V_82 ) ;
struct V_24 * V_25 ;
T_6 V_184 = 0 ;
while ( V_100 ) {
if ( ! V_102 )
F_121 ( F_36 ( & V_5 -> V_18 ) , & V_82 ,
V_194 ) ;
V_25 = F_122 ( & V_5 -> V_18 . V_35 ) ;
if ( ! V_25 ) {
if ( V_102 ) {
V_184 = - V_195 ;
break;
}
if ( F_123 ( V_75 ) ) {
V_184 = - V_196 ;
break;
}
F_124 () ;
continue;
}
V_184 = F_109 ( V_5 , V_25 , V_150 , V_100 ) ;
F_34 ( V_25 ) ;
break;
}
if ( ! V_102 )
F_125 ( F_36 ( & V_5 -> V_18 ) , & V_82 ) ;
return V_184 ;
}
static T_6 F_126 ( struct V_176 * V_177 , const struct V_105 * V_150 ,
unsigned long V_108 , T_7 V_178 )
{
struct V_3 * V_3 = V_177 -> V_179 ;
struct V_4 * V_5 = V_3 -> V_19 ;
T_6 V_100 , V_184 = 0 ;
V_100 = F_79 ( V_150 , V_108 ) ;
if ( V_100 < 0 ) {
V_184 = - V_9 ;
goto V_11;
}
V_184 = F_119 ( V_5 , V_177 , V_150 , V_100 , V_3 -> V_182 & V_183 ) ;
V_184 = F_81 ( T_6 , V_184 , V_100 ) ;
V_11:
return V_184 ;
}
static struct V_6 * F_127 ( struct V_4 * V_5 )
{
struct V_6 * V_7 ;
F_3 () ;
V_7 = F_11 ( V_5 -> V_7 ) ;
if ( V_7 )
F_48 ( V_7 -> V_2 ) ;
return V_7 ;
}
static void F_128 ( struct V_6 * V_7 )
{
F_68 ( V_7 -> V_2 ) ;
}
static int F_129 ( struct V_3 * V_3 , unsigned int V_37 )
{
struct V_4 * V_5 = V_3 -> V_19 ;
struct V_6 * V_7 ;
int V_184 ;
V_7 = F_127 ( V_5 ) ;
if ( ! V_7 )
return - V_9 ;
if ( V_37 & V_197 )
V_184 = F_1 ( V_7 -> V_2 , V_3 , V_5 ) ;
else if ( V_37 & V_198 )
V_184 = F_10 ( V_5 ) ;
else
V_184 = - V_9 ;
F_128 ( V_7 ) ;
return V_184 ;
}
static int F_130 ( struct V_4 * V_5 , unsigned long V_199 )
{
struct V_6 * V_7 ;
T_2 V_32 ;
T_2 V_200 = 0 ;
V_7 = F_11 ( V_5 -> V_7 ) ;
if ( ! V_7 )
return - V_181 ;
V_32 = V_7 -> V_2 -> V_32 ;
if ( V_199 & V_201 ) {
V_200 = V_202 ;
if ( V_199 & ( V_203 | V_204 ) ) {
if ( V_199 & V_205 )
V_200 |= V_206 ;
if ( V_199 & V_203 )
V_200 |= V_207 ;
if ( V_199 & V_204 )
V_200 |= V_208 ;
}
if ( V_199 & V_209 )
V_200 |= V_210 ;
}
if ( V_200 & ( V_207 | V_208 | V_210 ) )
V_32 |= V_211 ;
else
V_32 &= ~ V_211 ;
V_7 -> V_39 = V_200 ;
V_7 -> V_212 = V_32 ;
F_131 ( V_7 -> V_2 ) ;
return 0 ;
}
static long F_132 ( struct V_3 * V_3 , unsigned int V_213 ,
unsigned long V_199 )
{
struct V_4 * V_5 = V_3 -> V_19 ;
struct V_6 * V_7 ;
void T_9 * V_214 = ( void T_9 * ) V_199 ;
struct V_215 T_9 * V_216 = V_214 ;
unsigned int T_9 * V_217 = V_214 ;
unsigned int V_218 ;
int T_9 * V_219 = V_214 ;
int V_220 ;
int V_184 ;
switch ( V_213 ) {
case V_221 :
if ( F_133 ( V_218 , & V_216 -> V_222 ) )
return - V_114 ;
V_184 = 0 ;
if ( ( V_218 & ~ ( V_38 | V_223 ) ) !=
( V_90 | V_91 ) )
V_184 = - V_9 ;
else
V_5 -> V_37 = V_218 ;
return V_184 ;
case V_224 :
F_6 () ;
V_7 = F_127 ( V_5 ) ;
if ( ! V_7 ) {
F_9 () ;
return - V_181 ;
}
V_184 = 0 ;
if ( F_134 ( & V_216 -> V_225 , V_7 -> V_2 -> V_226 , V_227 ) ||
F_135 ( V_5 -> V_37 , & V_216 -> V_222 ) )
V_184 = - V_114 ;
F_128 ( V_7 ) ;
F_9 () ;
return V_184 ;
case V_228 :
if ( F_133 ( V_218 , & V_216 -> V_222 ) )
return - V_114 ;
F_6 () ;
V_184 = F_129 ( V_3 , V_218 ) ;
F_9 () ;
return V_184 ;
case V_229 :
if ( F_135 ( V_91 | V_90 | V_38 |
V_223 , V_217 ) )
return - V_114 ;
return 0 ;
case V_230 :
if ( F_133 ( V_218 , V_217 ) )
return - V_114 ;
V_5 -> V_18 . V_231 = V_218 ;
return 0 ;
case V_232 :
V_220 = V_5 -> V_92 ;
if ( F_135 ( V_220 , V_219 ) )
return - V_114 ;
return 0 ;
case V_233 :
if ( F_133 ( V_220 , V_219 ) )
return - V_114 ;
if ( V_220 < ( int ) sizeof( struct V_93 ) )
return - V_9 ;
V_5 -> V_92 = V_220 ;
return 0 ;
case V_234 :
if ( V_199 & ~ ( V_201 | V_203 | V_204 |
V_205 | V_209 ) )
return - V_9 ;
F_6 () ;
V_184 = F_130 ( V_5 , V_199 ) ;
F_9 () ;
return V_184 ;
default:
return - V_9 ;
}
}
static long F_136 ( struct V_3 * V_3 , unsigned int V_213 ,
unsigned long V_199 )
{
return F_132 ( V_3 , V_213 , ( unsigned long ) F_137 ( V_199 ) ) ;
}
static int F_138 ( struct V_176 * V_177 , struct V_235 * V_67 ,
struct V_154 * V_155 , T_5 V_156 )
{
struct V_4 * V_5 = F_139 ( V_67 , struct V_4 , V_67 ) ;
return F_95 ( V_5 , V_155 , V_155 -> V_236 , V_156 , V_155 -> V_237 ,
V_155 -> V_238 & V_239 ) ;
}
static int F_140 ( struct V_176 * V_177 , struct V_235 * V_67 ,
struct V_154 * V_155 , T_5 V_156 ,
int V_37 )
{
struct V_4 * V_5 = F_139 ( V_67 , struct V_4 , V_67 ) ;
int V_184 ;
if ( V_37 & ~ ( V_239 | V_240 ) )
return - V_9 ;
V_184 = F_119 ( V_5 , V_177 , V_155 -> V_236 , V_156 ,
V_37 & V_239 ) ;
if ( V_184 > V_156 ) {
V_155 -> V_238 |= V_240 ;
V_184 = V_37 & V_240 ? V_184 : V_156 ;
}
return V_184 ;
}
struct V_235 * F_141 ( struct V_3 * V_3 )
{
struct V_4 * V_5 ;
if ( V_3 -> V_241 != & V_242 )
return F_142 ( - V_9 ) ;
V_5 = V_3 -> V_19 ;
if ( ! V_5 )
return F_142 ( - V_243 ) ;
return & V_5 -> V_67 ;
}
static int F_143 ( struct V_244 * V_245 ,
unsigned long V_246 , void * V_247 )
{
struct V_1 * V_2 = F_144 ( V_247 ) ;
struct V_6 * V_7 ;
struct V_248 * V_249 ;
T_10 V_250 ;
int V_8 ;
if ( V_2 -> V_251 != & V_252 )
return V_253 ;
V_7 = F_2 ( V_2 ) ;
switch ( V_246 ) {
case V_254 :
V_8 = F_39 ( V_7 ) ;
if ( V_8 )
return F_145 ( V_8 ) ;
V_250 = F_146 ( F_147 ( V_255 ) , V_7 -> V_55 ) ;
V_249 = F_148 ( V_256 , & V_2 -> V_2 , V_250 ,
V_2 , L_2 , V_2 -> V_257 ) ;
if ( F_32 ( V_249 ) ) {
F_44 ( V_7 ) ;
return F_145 ( F_149 ( V_249 ) ) ;
}
break;
case V_258 :
V_250 = F_146 ( F_147 ( V_255 ) , V_7 -> V_55 ) ;
F_150 ( V_256 , V_250 ) ;
F_44 ( V_7 ) ;
break;
}
return V_253 ;
}
static int F_151 ( void )
{
int V_8 ;
V_8 = F_152 ( & V_255 , 0 ,
V_53 , L_3 ) ;
if ( V_8 )
goto V_259;
F_153 ( & V_260 , & V_242 ) ;
V_8 = F_154 ( & V_260 , V_255 , V_53 ) ;
if ( V_8 )
goto V_261;
V_256 = F_155 ( V_262 , L_3 ) ;
if ( F_32 ( V_256 ) ) {
V_8 = F_149 ( V_256 ) ;
goto V_263;
}
V_8 = F_156 ( & V_264 ) ;
if ( V_8 )
goto V_265;
V_8 = F_157 ( & V_252 ) ;
if ( V_8 )
goto V_266;
return 0 ;
V_266:
F_158 ( & V_264 ) ;
V_265:
F_159 ( V_256 ) ;
V_263:
F_160 ( & V_260 ) ;
V_261:
F_161 ( V_255 , V_53 ) ;
V_259:
return V_8 ;
}
static void F_162 ( void )
{
F_163 ( & V_252 ) ;
F_158 ( & V_264 ) ;
F_159 ( V_256 ) ;
F_160 ( & V_260 ) ;
F_161 ( V_255 , V_53 ) ;
}
