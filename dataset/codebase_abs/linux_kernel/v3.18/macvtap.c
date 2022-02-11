static struct V_1 * F_1 ( const struct V_2 * V_3 )
{
return F_2 ( V_3 -> V_4 ) ;
}
static int F_3 ( struct V_2 * V_3 , struct V_5 * V_5 ,
struct V_6 * V_7 )
{
struct V_1 * V_8 = F_4 ( V_3 ) ;
int V_9 = - V_10 ;
F_5 () ;
if ( V_7 -> V_11 )
goto V_12;
V_9 = 0 ;
F_6 ( V_8 -> V_13 [ V_8 -> V_14 ] , V_7 ) ;
V_7 -> V_15 = V_8 -> V_14 ;
V_7 -> V_11 = true ;
V_8 -> V_14 ++ ;
V_12:
return V_9 ;
}
static int F_7 ( struct V_2 * V_3 , struct V_5 * V_5 ,
struct V_6 * V_7 )
{
struct V_1 * V_8 = F_4 ( V_3 ) ;
if ( V_8 -> V_16 == V_17 )
return - V_18 ;
F_6 ( V_7 -> V_8 , V_8 ) ;
F_6 ( V_8 -> V_13 [ V_8 -> V_14 ] , V_7 ) ;
F_8 ( & V_7 -> V_19 ) ;
V_7 -> V_5 = V_5 ;
V_7 -> V_15 = V_8 -> V_14 ;
V_7 -> V_11 = true ;
V_5 -> V_20 = V_7 ;
F_9 ( & V_7 -> V_21 , & V_8 -> V_22 ) ;
V_8 -> V_14 ++ ;
V_8 -> V_16 ++ ;
return 0 ;
}
static int F_10 ( struct V_6 * V_7 )
{
struct V_1 * V_8 ;
struct V_6 * V_23 ;
F_5 () ;
if ( ! V_7 -> V_11 )
return - V_10 ;
V_8 = F_11 ( V_7 -> V_8 ) ;
if ( V_8 ) {
int V_24 = V_7 -> V_15 ;
F_12 ( V_24 >= V_8 -> V_14 ) ;
V_23 = F_11 ( V_8 -> V_13 [ V_8 -> V_14 - 1 ] ) ;
V_23 -> V_15 = V_24 ;
F_6 ( V_8 -> V_13 [ V_24 ] , V_23 ) ;
F_13 ( V_8 -> V_13 [ V_8 -> V_14 - 1 ] , NULL ) ;
V_7 -> V_11 = false ;
V_8 -> V_14 -- ;
}
return 0 ;
}
static void F_14 ( struct V_6 * V_7 )
{
struct V_1 * V_8 ;
F_15 () ;
V_8 = F_11 ( V_7 -> V_8 ) ;
if ( V_8 ) {
if ( V_7 -> V_11 )
F_12 ( F_10 ( V_7 ) ) ;
V_8 -> V_16 -- ;
F_13 ( V_7 -> V_8 , NULL ) ;
F_16 ( & V_7 -> V_19 ) ;
F_17 ( & V_7 -> V_21 ) ;
}
F_18 () ;
F_19 () ;
F_16 ( & V_7 -> V_19 ) ;
}
static struct V_6 * F_20 ( struct V_2 * V_3 ,
struct V_25 * V_26 )
{
struct V_1 * V_8 = F_4 ( V_3 ) ;
struct V_6 * V_27 = NULL ;
int V_14 = F_21 ( V_8 -> V_14 ) ;
T_1 V_28 ;
if ( ! V_14 )
goto V_12;
V_28 = F_22 ( V_26 ) ;
if ( V_28 ) {
V_27 = F_2 ( V_8 -> V_13 [ V_28 % V_14 ] ) ;
goto V_12;
}
if ( F_23 ( F_24 ( V_26 ) ) ) {
V_28 = F_25 ( V_26 ) ;
while ( F_26 ( V_28 >= V_14 ) )
V_28 -= V_14 ;
V_27 = F_2 ( V_8 -> V_13 [ V_28 ] ) ;
goto V_12;
}
V_27 = F_2 ( V_8 -> V_13 [ 0 ] ) ;
V_12:
return V_27 ;
}
static void F_27 ( struct V_2 * V_3 )
{
struct V_1 * V_8 = F_4 ( V_3 ) ;
struct V_6 * V_7 , * V_29 , * V_30 [ V_17 ] ;
int V_31 , V_32 = 0 ;
F_5 () ;
F_28 (q, tmp, &vlan->queue_list, next) {
F_17 ( & V_7 -> V_21 ) ;
V_30 [ V_32 ++ ] = V_7 ;
F_13 ( V_7 -> V_8 , NULL ) ;
if ( V_7 -> V_11 )
V_8 -> V_14 -- ;
V_8 -> V_16 -- ;
}
for ( V_31 = 0 ; V_31 < V_8 -> V_14 ; V_31 ++ )
F_13 ( V_8 -> V_13 [ V_31 ] , NULL ) ;
F_12 ( V_8 -> V_14 ) ;
F_12 ( V_8 -> V_16 ) ;
V_8 -> V_14 = V_17 ;
for ( -- V_32 ; V_32 >= 0 ; V_32 -- )
F_16 ( & V_30 [ V_32 ] -> V_19 ) ;
}
static T_2 F_29 ( struct V_25 * * V_33 )
{
struct V_25 * V_26 = * V_33 ;
struct V_2 * V_3 = V_26 -> V_3 ;
struct V_1 * V_8 ;
struct V_6 * V_7 ;
T_3 V_34 = V_35 ;
V_8 = F_1 ( V_3 ) ;
if ( ! V_8 )
return V_36 ;
V_7 = F_20 ( V_3 , V_26 ) ;
if ( ! V_7 )
return V_36 ;
if ( F_30 ( & V_7 -> V_19 . V_37 ) >= V_3 -> V_38 )
goto V_39;
F_31 ( V_26 , V_40 ) ;
if ( V_7 -> V_41 & V_42 )
V_34 |= V_8 -> V_43 ;
if ( F_32 ( V_3 , V_26 , V_34 ) ) {
struct V_25 * V_44 = F_33 ( V_26 , V_34 , false ) ;
if ( F_34 ( V_44 ) )
goto V_39;
if ( ! V_44 ) {
F_35 ( & V_7 -> V_19 . V_37 , V_26 ) ;
goto V_45;
}
F_36 ( V_26 ) ;
while ( V_44 ) {
struct V_25 * V_46 = V_44 -> V_21 ;
V_44 -> V_21 = NULL ;
F_35 ( & V_7 -> V_19 . V_37 , V_44 ) ;
V_44 = V_46 ;
}
} else {
if ( V_26 -> V_47 == V_48 &&
! ( V_34 & V_49 ) &&
F_37 ( V_26 ) )
goto V_39;
F_35 ( & V_7 -> V_19 . V_37 , V_26 ) ;
}
V_45:
F_38 ( F_39 ( & V_7 -> V_19 ) , V_50 | V_51 | V_52 ) ;
return V_53 ;
V_39:
F_40 ( V_8 , 0 , 0 , 0 ) ;
F_36 ( V_26 ) ;
return V_53 ;
}
static int F_41 ( struct V_1 * V_8 )
{
int V_54 = - V_55 ;
F_42 ( & V_56 ) ;
V_54 = F_43 ( & V_57 , V_8 , 1 , V_58 , V_59 ) ;
if ( V_54 >= 0 ) {
V_8 -> V_60 = V_54 ;
} else if ( V_54 == - V_61 ) {
F_44 ( V_62 L_1 ) ;
V_54 = - V_10 ;
}
F_45 ( & V_56 ) ;
return V_54 < 0 ? V_54 : 0 ;
}
static void F_46 ( struct V_1 * V_8 )
{
F_42 ( & V_56 ) ;
if ( V_8 -> V_60 ) {
F_47 ( & V_57 , V_8 -> V_60 ) ;
V_8 -> V_60 = 0 ;
}
F_45 ( & V_56 ) ;
}
static struct V_2 * F_48 ( int V_60 )
{
struct V_2 * V_3 = NULL ;
struct V_1 * V_8 ;
F_42 ( & V_56 ) ;
V_8 = F_49 ( & V_57 , V_60 ) ;
if ( V_8 ) {
V_3 = V_8 -> V_3 ;
F_50 ( V_3 ) ;
}
F_45 ( & V_56 ) ;
return V_3 ;
}
static int F_51 ( struct V_63 * V_64 ,
struct V_2 * V_3 ,
struct V_65 * V_66 [] ,
struct V_65 * V_67 [] )
{
struct V_1 * V_8 = F_4 ( V_3 ) ;
int V_9 ;
F_52 ( & V_8 -> V_22 ) ;
V_8 -> V_43 = V_68 ;
V_9 = F_53 ( V_3 , F_29 , V_8 ) ;
if ( V_9 )
return V_9 ;
return F_54 ( V_64 , V_3 , V_66 , V_67 ) ;
}
static void F_55 ( struct V_2 * V_3 ,
struct V_69 * V_70 )
{
F_56 ( V_3 ) ;
F_27 ( V_3 ) ;
F_57 ( V_3 , V_70 ) ;
}
static void F_58 ( struct V_2 * V_3 )
{
F_59 ( V_3 ) ;
V_3 -> V_38 = V_71 ;
}
static void F_60 ( struct V_72 * V_19 )
{
T_4 * V_73 ;
if ( ! F_61 ( V_19 ) ||
! F_62 ( V_74 , & V_19 -> V_75 -> V_41 ) )
return;
V_73 = F_39 ( V_19 ) ;
if ( V_73 && F_63 ( V_73 ) )
F_38 ( V_73 , V_76 | V_77 | V_78 ) ;
}
static void F_64 ( struct V_72 * V_19 )
{
F_65 ( & V_19 -> V_37 ) ;
}
static int F_66 ( struct V_79 * V_79 , struct V_5 * V_5 )
{
struct V_63 * V_63 = V_80 -> V_81 -> V_82 ;
struct V_2 * V_3 ;
struct V_6 * V_7 ;
int V_9 = - V_83 ;
F_15 () ;
V_3 = F_48 ( F_67 ( V_79 ) ) ;
if ( ! V_3 )
goto V_12;
V_9 = - V_55 ;
V_7 = (struct V_6 * ) F_68 ( V_63 , V_84 , V_59 ,
& V_85 ) ;
if ( ! V_7 )
goto V_12;
F_13 ( V_7 -> V_72 . V_86 , & V_7 -> V_86 ) ;
F_69 ( & V_7 -> V_86 . V_87 ) ;
V_7 -> V_72 . type = V_88 ;
V_7 -> V_72 . V_89 = V_90 ;
V_7 -> V_72 . V_5 = V_5 ;
V_7 -> V_72 . V_91 = & V_92 ;
F_70 ( & V_7 -> V_72 , & V_7 -> V_19 ) ;
V_7 -> V_19 . V_93 = F_60 ;
V_7 -> V_19 . V_94 = F_64 ;
V_7 -> V_41 = V_42 | V_95 | V_96 ;
V_7 -> V_97 = sizeof( struct V_98 ) ;
if ( ( V_3 -> V_34 & V_99 ) && ( V_3 -> V_34 & V_100 ) )
F_71 ( & V_7 -> V_19 , V_101 ) ;
V_9 = F_7 ( V_3 , V_5 , V_7 ) ;
if ( V_9 )
F_16 ( & V_7 -> V_19 ) ;
V_12:
if ( V_3 )
F_72 ( V_3 ) ;
F_18 () ;
return V_9 ;
}
static int F_73 ( struct V_79 * V_79 , struct V_5 * V_5 )
{
struct V_6 * V_7 = V_5 -> V_20 ;
F_14 ( V_7 ) ;
return 0 ;
}
static unsigned int F_74 ( struct V_5 * V_5 , T_5 * V_87 )
{
struct V_6 * V_7 = V_5 -> V_20 ;
unsigned int V_102 = V_103 ;
if ( ! V_7 )
goto V_12;
V_102 = 0 ;
F_75 ( V_5 , & V_7 -> V_86 . V_87 , V_87 ) ;
if ( ! F_76 ( & V_7 -> V_19 . V_37 ) )
V_102 |= V_50 | V_51 ;
if ( F_61 ( & V_7 -> V_19 ) ||
( ! F_77 ( V_74 , & V_7 -> V_72 . V_41 ) &&
F_61 ( & V_7 -> V_19 ) ) )
V_102 |= V_76 | V_77 ;
V_12:
return V_102 ;
}
static inline struct V_25 * F_78 ( struct V_72 * V_19 , T_6 V_104 ,
T_6 V_105 , T_6 V_106 ,
int V_107 , int * V_9 )
{
struct V_25 * V_26 ;
if ( V_104 + V_105 < V_108 || ! V_106 )
V_106 = V_105 ;
V_26 = F_79 ( V_19 , V_104 + V_106 , V_105 - V_106 , V_107 ,
V_9 , 0 ) ;
if ( ! V_26 )
return NULL ;
F_80 ( V_26 , V_104 ) ;
F_81 ( V_26 , V_106 ) ;
V_26 -> V_109 = V_105 - V_106 ;
V_26 -> V_105 += V_105 - V_106 ;
return V_26 ;
}
static int F_82 ( struct V_25 * V_26 ,
struct V_98 * V_110 )
{
unsigned short V_111 = 0 ;
if ( V_110 -> V_111 != V_112 ) {
switch ( V_110 -> V_111 & ~ V_113 ) {
case V_114 :
V_111 = V_115 ;
break;
case V_116 :
V_111 = V_117 ;
break;
case V_118 :
F_83 ( L_2 ,
V_80 -> V_119 ) ;
V_111 = V_120 ;
if ( V_26 -> V_121 == F_84 ( V_122 ) )
F_85 ( V_26 ) ;
break;
default:
return - V_10 ;
}
if ( V_110 -> V_111 & V_113 )
V_111 |= V_123 ;
if ( V_110 -> V_124 == 0 )
return - V_10 ;
}
if ( V_110 -> V_41 & V_125 ) {
if ( ! F_86 ( V_26 , V_110 -> V_126 ,
V_110 -> V_127 ) )
return - V_10 ;
}
if ( V_110 -> V_111 != V_112 ) {
F_87 ( V_26 ) -> V_124 = V_110 -> V_124 ;
F_87 ( V_26 ) -> V_111 = V_111 ;
F_87 ( V_26 ) -> V_111 |= V_128 ;
F_87 ( V_26 ) -> V_129 = 0 ;
}
return 0 ;
}
static void F_88 ( const struct V_25 * V_26 ,
struct V_98 * V_110 )
{
memset ( V_110 , 0 , sizeof( * V_110 ) ) ;
if ( F_89 ( V_26 ) ) {
struct V_130 * V_131 = F_87 ( V_26 ) ;
V_110 -> V_132 = F_90 ( V_26 ) ;
V_110 -> V_124 = V_131 -> V_124 ;
if ( V_131 -> V_111 & V_115 )
V_110 -> V_111 = V_114 ;
else if ( V_131 -> V_111 & V_117 )
V_110 -> V_111 = V_116 ;
else
F_91 () ;
if ( V_131 -> V_111 & V_123 )
V_110 -> V_111 |= V_113 ;
} else
V_110 -> V_111 = V_112 ;
if ( V_26 -> V_47 == V_48 ) {
V_110 -> V_41 = V_125 ;
V_110 -> V_126 = F_92 ( V_26 ) ;
if ( F_93 ( V_26 ) )
V_110 -> V_126 += V_133 ;
V_110 -> V_127 = V_26 -> V_127 ;
} else if ( V_26 -> V_47 == V_134 ) {
V_110 -> V_41 = V_135 ;
}
}
static T_7 F_94 ( struct V_6 * V_7 , struct V_136 * V_137 ,
const struct V_138 * V_139 , unsigned long V_140 ,
T_6 V_141 , int V_107 )
{
int V_142 = F_95 ( V_143 ) ;
struct V_25 * V_26 ;
struct V_1 * V_8 ;
unsigned long V_105 = V_140 ;
int V_9 ;
struct V_98 V_110 = { 0 } ;
int V_144 = 0 ;
int V_145 = 0 ;
bool V_146 = false ;
T_6 V_106 ;
if ( V_7 -> V_41 & V_42 ) {
V_144 = V_7 -> V_97 ;
V_9 = - V_10 ;
if ( V_105 < V_144 )
goto V_9;
V_105 -= V_144 ;
V_9 = F_96 ( ( void * ) & V_110 , V_139 , 0 ,
sizeof( V_110 ) ) ;
if ( V_9 < 0 )
goto V_9;
if ( ( V_110 . V_41 & V_125 ) &&
V_110 . V_126 + V_110 . V_127 + 2 >
V_110 . V_132 )
V_110 . V_132 = V_110 . V_126 +
V_110 . V_127 + 2 ;
V_9 = - V_10 ;
if ( V_110 . V_132 > V_105 )
goto V_9;
}
V_9 = - V_10 ;
if ( F_26 ( V_105 < V_40 ) )
goto V_9;
V_9 = - V_147 ;
if ( F_26 ( V_141 > V_148 ) )
goto V_9;
if ( V_137 && V_137 -> V_149 && F_97 ( & V_7 -> V_19 , V_101 ) ) {
V_145 = V_110 . V_132 ? V_110 . V_132 : V_150 ;
if ( V_145 > V_142 )
V_145 = V_142 ;
V_106 = V_145 ;
if ( F_98 ( V_139 , V_144 + V_145 , V_141 )
<= V_151 )
V_146 = true ;
}
if ( ! V_146 ) {
V_145 = V_105 ;
if ( V_110 . V_132 > V_142 )
V_106 = V_142 ;
else
V_106 = V_110 . V_132 ;
}
V_26 = F_78 ( & V_7 -> V_19 , V_143 , V_145 ,
V_106 , V_107 , & V_9 ) ;
if ( ! V_26 )
goto V_9;
if ( V_146 )
V_9 = F_99 ( V_26 , V_139 , V_144 , V_141 ) ;
else {
V_9 = F_100 ( V_26 , 0 , V_139 , V_144 ,
V_105 ) ;
if ( ! V_9 && V_137 && V_137 -> V_149 ) {
struct V_152 * V_153 = V_137 -> V_149 ;
V_153 -> V_154 ( V_153 , false ) ;
}
}
if ( V_9 )
goto V_155;
F_101 ( V_26 , V_40 ) ;
F_102 ( V_26 ) ;
V_26 -> V_121 = F_103 ( V_26 ) -> V_156 ;
if ( V_144 ) {
V_9 = F_82 ( V_26 , & V_110 ) ;
if ( V_9 )
goto V_155;
}
F_104 ( V_26 , V_40 ) ;
F_105 () ;
V_8 = F_2 ( V_7 -> V_8 ) ;
if ( V_146 ) {
F_87 ( V_26 ) -> V_157 = V_137 -> V_149 ;
F_87 ( V_26 ) -> V_158 |= V_159 ;
F_87 ( V_26 ) -> V_158 |= V_160 ;
}
if ( V_8 ) {
V_26 -> V_3 = V_8 -> V_3 ;
F_106 ( V_26 ) ;
} else {
F_36 ( V_26 ) ;
}
F_107 () ;
return V_140 ;
V_155:
F_36 ( V_26 ) ;
V_9:
F_105 () ;
V_8 = F_2 ( V_7 -> V_8 ) ;
if ( V_8 )
F_108 ( V_8 -> V_161 -> V_162 ) ;
F_107 () ;
return V_9 ;
}
static T_7 F_109 ( struct V_163 * V_164 , const struct V_138 * V_139 ,
unsigned long V_141 , T_8 V_165 )
{
struct V_5 * V_5 = V_164 -> V_166 ;
T_7 V_167 = - V_168 ;
struct V_6 * V_7 = V_5 -> V_20 ;
V_167 = F_94 ( V_7 , NULL , V_139 , F_110 ( V_139 , V_141 ) , V_141 ,
V_5 -> V_169 & V_170 ) ;
return V_167 ;
}
static T_7 F_111 ( struct V_6 * V_7 ,
const struct V_25 * V_26 ,
const struct V_138 * V_139 , int V_105 )
{
int V_171 ;
int V_144 = 0 ;
int V_172 = 0 ;
int V_173 , V_174 ;
if ( V_7 -> V_41 & V_42 ) {
struct V_98 V_110 ;
V_144 = V_7 -> V_97 ;
if ( ( V_105 -= V_144 ) < 0 )
return - V_10 ;
F_88 ( V_26 , & V_110 ) ;
if ( F_112 ( V_139 , ( void * ) & V_110 , 0 , sizeof( V_110 ) ) )
return - V_175 ;
}
V_174 = V_173 = V_144 ;
V_174 += V_26 -> V_105 ;
if ( ! F_93 ( V_26 ) )
V_105 = F_113 ( int , V_26 -> V_105 , V_105 ) ;
else {
int V_176 ;
struct {
T_9 V_177 ;
T_9 V_178 ;
} V_179 ;
V_179 . V_177 = V_26 -> V_180 ;
V_179 . V_178 = F_84 ( F_114 ( V_26 ) ) ;
V_172 = F_115 ( struct V_181 , V_177 ) ;
V_105 = F_113 ( int , V_26 -> V_105 + V_133 , V_105 ) ;
V_174 += V_133 ;
V_176 = F_113 ( int , V_172 , V_105 ) ;
V_171 = F_116 ( V_26 , 0 , V_139 , V_173 , V_176 ) ;
V_105 -= V_176 ;
V_173 += V_176 ;
if ( V_171 || ! V_105 )
goto V_182;
V_176 = F_113 ( int , sizeof( V_179 ) , V_105 ) ;
V_171 = F_112 ( V_139 , ( void * ) & V_179 , V_173 , V_176 ) ;
V_105 -= V_176 ;
V_173 += V_176 ;
if ( V_171 || ! V_105 )
goto V_182;
}
V_171 = F_116 ( V_26 , V_172 , V_139 , V_173 , V_105 ) ;
V_182:
return V_171 ? V_171 : V_174 ;
}
static T_7 F_117 ( struct V_6 * V_7 ,
const struct V_138 * V_139 , unsigned long V_105 ,
int V_107 )
{
F_118 ( V_87 ) ;
struct V_25 * V_26 ;
T_7 V_171 = 0 ;
while ( V_105 ) {
if ( ! V_107 )
F_119 ( F_39 ( & V_7 -> V_19 ) , & V_87 ,
V_183 ) ;
V_26 = F_120 ( & V_7 -> V_19 . V_37 ) ;
if ( ! V_26 ) {
if ( V_107 ) {
V_171 = - V_184 ;
break;
}
if ( F_121 ( V_80 ) ) {
V_171 = - V_185 ;
break;
}
F_122 () ;
continue;
}
V_171 = F_111 ( V_7 , V_26 , V_139 , V_105 ) ;
F_36 ( V_26 ) ;
break;
}
if ( ! V_107 )
F_123 ( F_39 ( & V_7 -> V_19 ) , & V_87 ) ;
return V_171 ;
}
static T_7 F_124 ( struct V_163 * V_164 , const struct V_138 * V_139 ,
unsigned long V_141 , T_8 V_165 )
{
struct V_5 * V_5 = V_164 -> V_166 ;
struct V_6 * V_7 = V_5 -> V_20 ;
T_7 V_105 , V_171 = 0 ;
V_105 = F_110 ( V_139 , V_141 ) ;
if ( V_105 < 0 ) {
V_171 = - V_10 ;
goto V_12;
}
V_171 = F_117 ( V_7 , V_139 , V_105 , V_5 -> V_169 & V_170 ) ;
V_171 = F_113 ( T_7 , V_171 , V_105 ) ;
if ( V_171 > 0 )
V_164 -> V_186 = V_171 ;
V_12:
return V_171 ;
}
static struct V_1 * F_125 ( struct V_6 * V_7 )
{
struct V_1 * V_8 ;
F_5 () ;
V_8 = F_11 ( V_7 -> V_8 ) ;
if ( V_8 )
F_50 ( V_8 -> V_3 ) ;
return V_8 ;
}
static void F_126 ( struct V_1 * V_8 )
{
F_72 ( V_8 -> V_3 ) ;
}
static int F_127 ( struct V_5 * V_5 , unsigned int V_41 )
{
struct V_6 * V_7 = V_5 -> V_20 ;
struct V_1 * V_8 ;
int V_171 ;
V_8 = F_125 ( V_7 ) ;
if ( ! V_8 )
return - V_10 ;
if ( V_41 & V_187 )
V_171 = F_3 ( V_8 -> V_3 , V_5 , V_7 ) ;
else if ( V_41 & V_188 )
V_171 = F_10 ( V_7 ) ;
else
V_171 = - V_10 ;
F_126 ( V_8 ) ;
return V_171 ;
}
static int F_128 ( struct V_6 * V_7 , unsigned long V_189 )
{
struct V_1 * V_8 ;
T_3 V_34 ;
T_3 V_190 = 0 ;
V_8 = F_11 ( V_7 -> V_8 ) ;
if ( ! V_8 )
return - V_168 ;
V_34 = V_8 -> V_3 -> V_34 ;
if ( V_189 & V_191 ) {
V_190 = V_192 ;
if ( V_189 & ( V_193 | V_194 ) ) {
if ( V_189 & V_195 )
V_190 |= V_196 ;
if ( V_189 & V_193 )
V_190 |= V_197 ;
if ( V_189 & V_194 )
V_190 |= V_198 ;
}
}
if ( V_190 & ( V_197 | V_198 ) )
V_34 |= V_199 ;
else
V_34 &= ~ V_199 ;
V_8 -> V_43 = V_190 ;
V_8 -> V_200 = V_34 ;
F_129 ( V_8 -> V_3 ) ;
return 0 ;
}
static long F_130 ( struct V_5 * V_5 , unsigned int V_201 ,
unsigned long V_189 )
{
struct V_6 * V_7 = V_5 -> V_20 ;
struct V_1 * V_8 ;
void T_10 * V_202 = ( void T_10 * ) V_189 ;
struct V_203 T_10 * V_204 = V_202 ;
unsigned int T_10 * V_205 = V_202 ;
unsigned int V_206 ;
int T_10 * V_207 = V_202 ;
int V_208 ;
int V_171 ;
switch ( V_201 ) {
case V_209 :
if ( F_131 ( V_206 , & V_204 -> V_210 ) )
return - V_175 ;
V_171 = 0 ;
if ( ( V_206 & ~ ( V_42 | V_211 ) ) !=
( V_95 | V_96 ) )
V_171 = - V_10 ;
else
V_7 -> V_41 = V_206 ;
return V_171 ;
case V_212 :
F_15 () ;
V_8 = F_125 ( V_7 ) ;
if ( ! V_8 ) {
F_18 () ;
return - V_168 ;
}
V_171 = 0 ;
if ( F_132 ( & V_204 -> V_213 , V_8 -> V_3 -> V_214 , V_215 ) ||
F_133 ( V_7 -> V_41 , & V_204 -> V_210 ) )
V_171 = - V_175 ;
F_126 ( V_8 ) ;
F_18 () ;
return V_171 ;
case V_216 :
if ( F_131 ( V_206 , & V_204 -> V_210 ) )
return - V_175 ;
F_15 () ;
V_171 = F_127 ( V_5 , V_206 ) ;
F_18 () ;
return V_171 ;
case V_217 :
if ( F_133 ( V_96 | V_95 | V_42 |
V_211 , V_205 ) )
return - V_175 ;
return 0 ;
case V_218 :
if ( F_131 ( V_206 , V_205 ) )
return - V_175 ;
V_7 -> V_19 . V_219 = V_206 ;
return 0 ;
case V_220 :
V_208 = V_7 -> V_97 ;
if ( F_133 ( V_208 , V_207 ) )
return - V_175 ;
return 0 ;
case V_221 :
if ( F_131 ( V_208 , V_207 ) )
return - V_175 ;
if ( V_208 < ( int ) sizeof( struct V_98 ) )
return - V_10 ;
V_7 -> V_97 = V_208 ;
return 0 ;
case V_222 :
if ( V_189 & ~ ( V_191 | V_193 | V_194 |
V_195 ) )
return - V_10 ;
F_15 () ;
V_171 = F_128 ( V_7 , V_189 ) ;
F_18 () ;
return V_171 ;
default:
return - V_10 ;
}
}
static long F_134 ( struct V_5 * V_5 , unsigned int V_201 ,
unsigned long V_189 )
{
return F_130 ( V_5 , V_201 , ( unsigned long ) F_135 ( V_189 ) ) ;
}
static int F_136 ( struct V_163 * V_164 , struct V_223 * V_72 ,
struct V_136 * V_137 , T_6 V_140 )
{
struct V_6 * V_7 = F_137 ( V_72 , struct V_6 , V_72 ) ;
return F_94 ( V_7 , V_137 , V_137 -> V_224 , V_140 , V_137 -> V_225 ,
V_137 -> V_226 & V_227 ) ;
}
static int F_138 ( struct V_163 * V_164 , struct V_223 * V_72 ,
struct V_136 * V_137 , T_6 V_140 ,
int V_41 )
{
struct V_6 * V_7 = F_137 ( V_72 , struct V_6 , V_72 ) ;
int V_171 ;
if ( V_41 & ~ ( V_227 | V_228 ) )
return - V_10 ;
V_171 = F_117 ( V_7 , V_137 -> V_224 , V_140 ,
V_41 & V_227 ) ;
if ( V_171 > V_140 ) {
V_137 -> V_226 |= V_228 ;
V_171 = V_41 & V_228 ? V_171 : V_140 ;
}
return V_171 ;
}
struct V_223 * F_139 ( struct V_5 * V_5 )
{
struct V_6 * V_7 ;
if ( V_5 -> V_229 != & V_230 )
return F_140 ( - V_10 ) ;
V_7 = V_5 -> V_20 ;
if ( ! V_7 )
return F_140 ( - V_231 ) ;
return & V_7 -> V_72 ;
}
static int F_141 ( struct V_232 * V_233 ,
unsigned long V_234 , void * V_235 )
{
struct V_2 * V_3 = F_142 ( V_235 ) ;
struct V_1 * V_8 ;
struct V_236 * V_237 ;
T_11 V_238 ;
int V_9 ;
if ( V_3 -> V_239 != & V_240 )
return V_241 ;
V_8 = F_4 ( V_3 ) ;
switch ( V_234 ) {
case V_242 :
V_9 = F_41 ( V_8 ) ;
if ( V_9 )
return F_143 ( V_9 ) ;
V_238 = F_144 ( F_145 ( V_243 ) , V_8 -> V_60 ) ;
V_237 = F_146 ( V_244 , & V_3 -> V_3 , V_238 ,
V_3 , L_3 , V_3 -> V_245 ) ;
if ( F_34 ( V_237 ) ) {
F_46 ( V_8 ) ;
return F_143 ( F_147 ( V_237 ) ) ;
}
break;
case V_246 :
V_238 = F_144 ( F_145 ( V_243 ) , V_8 -> V_60 ) ;
F_148 ( V_244 , V_238 ) ;
F_46 ( V_8 ) ;
break;
}
return V_241 ;
}
static int F_149 ( void )
{
int V_9 ;
V_9 = F_150 ( & V_243 , 0 ,
V_58 , L_4 ) ;
if ( V_9 )
goto V_247;
F_151 ( & V_248 , & V_230 ) ;
V_9 = F_152 ( & V_248 , V_243 , V_58 ) ;
if ( V_9 )
goto V_249;
V_244 = F_153 ( V_250 , L_4 ) ;
if ( F_34 ( V_244 ) ) {
V_9 = F_147 ( V_244 ) ;
goto V_251;
}
V_9 = F_154 ( & V_252 ) ;
if ( V_9 )
goto V_253;
V_9 = F_155 ( & V_240 ) ;
if ( V_9 )
goto V_254;
return 0 ;
V_254:
F_156 ( & V_252 ) ;
V_253:
F_157 ( V_244 ) ;
V_251:
F_158 ( & V_248 ) ;
V_249:
F_159 ( V_243 , V_58 ) ;
V_247:
return V_9 ;
}
static void F_160 ( void )
{
F_161 ( & V_240 ) ;
F_156 ( & V_252 ) ;
F_157 ( V_244 ) ;
F_158 ( & V_248 ) ;
F_159 ( V_243 , V_58 ) ;
}
