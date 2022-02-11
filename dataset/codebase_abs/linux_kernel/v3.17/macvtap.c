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
if ( F_32 ( V_26 , V_34 ) ) {
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
V_111 = V_119 ;
break;
default:
return - V_10 ;
}
if ( V_110 -> V_111 & V_113 )
V_111 |= V_120 ;
if ( V_110 -> V_121 == 0 )
return - V_10 ;
}
if ( V_110 -> V_41 & V_122 ) {
if ( ! F_83 ( V_26 , V_110 -> V_123 ,
V_110 -> V_124 ) )
return - V_10 ;
}
if ( V_110 -> V_111 != V_112 ) {
F_84 ( V_26 ) -> V_121 = V_110 -> V_121 ;
F_84 ( V_26 ) -> V_111 = V_111 ;
F_84 ( V_26 ) -> V_111 |= V_125 ;
F_84 ( V_26 ) -> V_126 = 0 ;
}
return 0 ;
}
static void F_85 ( const struct V_25 * V_26 ,
struct V_98 * V_110 )
{
memset ( V_110 , 0 , sizeof( * V_110 ) ) ;
if ( F_86 ( V_26 ) ) {
struct V_127 * V_128 = F_84 ( V_26 ) ;
V_110 -> V_129 = F_87 ( V_26 ) ;
V_110 -> V_121 = V_128 -> V_121 ;
if ( V_128 -> V_111 & V_115 )
V_110 -> V_111 = V_114 ;
else if ( V_128 -> V_111 & V_117 )
V_110 -> V_111 = V_116 ;
else if ( V_128 -> V_111 & V_119 )
V_110 -> V_111 = V_118 ;
else
F_88 () ;
if ( V_128 -> V_111 & V_120 )
V_110 -> V_111 |= V_113 ;
} else
V_110 -> V_111 = V_112 ;
if ( V_26 -> V_47 == V_48 ) {
V_110 -> V_41 = V_122 ;
V_110 -> V_123 = F_89 ( V_26 ) ;
V_110 -> V_124 = V_26 -> V_124 ;
} else if ( V_26 -> V_47 == V_130 ) {
V_110 -> V_41 = V_131 ;
}
}
static T_7 F_90 ( struct V_6 * V_7 , struct V_132 * V_133 ,
const struct V_134 * V_135 , unsigned long V_136 ,
T_6 V_137 , int V_107 )
{
int V_138 = F_91 ( V_139 ) ;
struct V_25 * V_26 ;
struct V_1 * V_8 ;
unsigned long V_105 = V_136 ;
int V_9 ;
struct V_98 V_110 = { 0 } ;
int V_140 = 0 ;
int V_141 = 0 ;
bool V_142 = false ;
T_6 V_106 ;
if ( V_7 -> V_41 & V_42 ) {
V_140 = V_7 -> V_97 ;
V_9 = - V_10 ;
if ( V_105 < V_140 )
goto V_9;
V_105 -= V_140 ;
V_9 = F_92 ( ( void * ) & V_110 , V_135 , 0 ,
sizeof( V_110 ) ) ;
if ( V_9 < 0 )
goto V_9;
if ( ( V_110 . V_41 & V_122 ) &&
V_110 . V_123 + V_110 . V_124 + 2 >
V_110 . V_129 )
V_110 . V_129 = V_110 . V_123 +
V_110 . V_124 + 2 ;
V_9 = - V_10 ;
if ( V_110 . V_129 > V_105 )
goto V_9;
}
V_9 = - V_10 ;
if ( F_26 ( V_105 < V_40 ) )
goto V_9;
V_9 = - V_143 ;
if ( F_26 ( V_137 > V_144 ) )
goto V_9;
if ( V_133 && V_133 -> V_145 && F_93 ( & V_7 -> V_19 , V_101 ) ) {
V_141 = V_110 . V_129 ? V_110 . V_129 : V_146 ;
if ( V_141 > V_138 )
V_141 = V_138 ;
V_106 = V_141 ;
if ( F_94 ( V_135 , V_140 + V_141 , V_137 )
<= V_147 )
V_142 = true ;
}
if ( ! V_142 ) {
V_141 = V_105 ;
if ( V_110 . V_129 > V_138 )
V_106 = V_138 ;
else
V_106 = V_110 . V_129 ;
}
V_26 = F_78 ( & V_7 -> V_19 , V_139 , V_141 ,
V_106 , V_107 , & V_9 ) ;
if ( ! V_26 )
goto V_9;
if ( V_142 )
V_9 = F_95 ( V_26 , V_135 , V_140 , V_137 ) ;
else {
V_9 = F_96 ( V_26 , 0 , V_135 , V_140 ,
V_105 ) ;
if ( ! V_9 && V_133 && V_133 -> V_145 ) {
struct V_148 * V_149 = V_133 -> V_145 ;
V_149 -> V_150 ( V_149 , false ) ;
}
}
if ( V_9 )
goto V_151;
F_97 ( V_26 , V_40 ) ;
F_98 ( V_26 ) ;
V_26 -> V_152 = F_99 ( V_26 ) -> V_153 ;
if ( V_140 ) {
V_9 = F_82 ( V_26 , & V_110 ) ;
if ( V_9 )
goto V_151;
}
F_100 ( V_26 , V_40 ) ;
F_101 () ;
V_8 = F_2 ( V_7 -> V_8 ) ;
if ( V_142 ) {
F_84 ( V_26 ) -> V_154 = V_133 -> V_145 ;
F_84 ( V_26 ) -> V_155 |= V_156 ;
F_84 ( V_26 ) -> V_155 |= V_157 ;
}
if ( V_8 ) {
V_26 -> V_3 = V_8 -> V_3 ;
F_102 ( V_26 ) ;
} else {
F_36 ( V_26 ) ;
}
F_103 () ;
return V_136 ;
V_151:
F_36 ( V_26 ) ;
V_9:
F_101 () ;
V_8 = F_2 ( V_7 -> V_8 ) ;
if ( V_8 )
F_104 ( V_8 -> V_158 -> V_159 ) ;
F_103 () ;
return V_9 ;
}
static T_7 F_105 ( struct V_160 * V_161 , const struct V_134 * V_135 ,
unsigned long V_137 , T_8 V_162 )
{
struct V_5 * V_5 = V_161 -> V_163 ;
T_7 V_164 = - V_165 ;
struct V_6 * V_7 = V_5 -> V_20 ;
V_164 = F_90 ( V_7 , NULL , V_135 , F_106 ( V_135 , V_137 ) , V_137 ,
V_5 -> V_166 & V_167 ) ;
return V_164 ;
}
static T_7 F_107 ( struct V_6 * V_7 ,
const struct V_25 * V_26 ,
const struct V_134 * V_135 , int V_105 )
{
int V_168 ;
int V_140 = 0 ;
int V_169 = 0 ;
int V_170 , V_171 ;
if ( V_7 -> V_41 & V_42 ) {
struct V_98 V_110 ;
V_140 = V_7 -> V_97 ;
if ( ( V_105 -= V_140 ) < 0 )
return - V_10 ;
F_85 ( V_26 , & V_110 ) ;
if ( F_108 ( V_135 , ( void * ) & V_110 , 0 , sizeof( V_110 ) ) )
return - V_172 ;
}
V_171 = V_170 = V_140 ;
V_171 += V_26 -> V_105 ;
if ( ! F_109 ( V_26 ) )
V_105 = F_110 ( int , V_26 -> V_105 , V_105 ) ;
else {
int V_173 ;
struct {
T_9 V_174 ;
T_9 V_175 ;
} V_176 ;
V_176 . V_174 = V_26 -> V_177 ;
V_176 . V_175 = F_111 ( F_112 ( V_26 ) ) ;
V_169 = F_113 ( struct V_178 , V_174 ) ;
V_105 = F_110 ( int , V_26 -> V_105 + V_179 , V_105 ) ;
V_171 += V_179 ;
V_173 = F_110 ( int , V_169 , V_105 ) ;
V_168 = F_114 ( V_26 , 0 , V_135 , V_170 , V_173 ) ;
V_105 -= V_173 ;
V_170 += V_173 ;
if ( V_168 || ! V_105 )
goto V_180;
V_173 = F_110 ( int , sizeof( V_176 ) , V_105 ) ;
V_168 = F_108 ( V_135 , ( void * ) & V_176 , V_170 , V_173 ) ;
V_105 -= V_173 ;
V_170 += V_173 ;
if ( V_168 || ! V_105 )
goto V_180;
}
V_168 = F_114 ( V_26 , V_169 , V_135 , V_170 , V_105 ) ;
V_180:
return V_168 ? V_168 : V_171 ;
}
static T_7 F_115 ( struct V_6 * V_7 ,
const struct V_134 * V_135 , unsigned long V_105 ,
int V_107 )
{
F_116 ( V_87 ) ;
struct V_25 * V_26 ;
T_7 V_168 = 0 ;
while ( V_105 ) {
if ( ! V_107 )
F_117 ( F_39 ( & V_7 -> V_19 ) , & V_87 ,
V_181 ) ;
V_26 = F_118 ( & V_7 -> V_19 . V_37 ) ;
if ( ! V_26 ) {
if ( V_107 ) {
V_168 = - V_182 ;
break;
}
if ( F_119 ( V_80 ) ) {
V_168 = - V_183 ;
break;
}
F_120 () ;
continue;
}
V_168 = F_107 ( V_7 , V_26 , V_135 , V_105 ) ;
F_36 ( V_26 ) ;
break;
}
if ( ! V_107 )
F_121 ( F_39 ( & V_7 -> V_19 ) , & V_87 ) ;
return V_168 ;
}
static T_7 F_122 ( struct V_160 * V_161 , const struct V_134 * V_135 ,
unsigned long V_137 , T_8 V_162 )
{
struct V_5 * V_5 = V_161 -> V_163 ;
struct V_6 * V_7 = V_5 -> V_20 ;
T_7 V_105 , V_168 = 0 ;
V_105 = F_106 ( V_135 , V_137 ) ;
if ( V_105 < 0 ) {
V_168 = - V_10 ;
goto V_12;
}
V_168 = F_115 ( V_7 , V_135 , V_105 , V_5 -> V_166 & V_167 ) ;
V_168 = F_110 ( T_7 , V_168 , V_105 ) ;
if ( V_168 > 0 )
V_161 -> V_184 = V_168 ;
V_12:
return V_168 ;
}
static struct V_1 * F_123 ( struct V_6 * V_7 )
{
struct V_1 * V_8 ;
F_5 () ;
V_8 = F_11 ( V_7 -> V_8 ) ;
if ( V_8 )
F_50 ( V_8 -> V_3 ) ;
return V_8 ;
}
static void F_124 ( struct V_1 * V_8 )
{
F_72 ( V_8 -> V_3 ) ;
}
static int F_125 ( struct V_5 * V_5 , unsigned int V_41 )
{
struct V_6 * V_7 = V_5 -> V_20 ;
struct V_1 * V_8 ;
int V_168 ;
V_8 = F_123 ( V_7 ) ;
if ( ! V_8 )
return - V_10 ;
if ( V_41 & V_185 )
V_168 = F_3 ( V_8 -> V_3 , V_5 , V_7 ) ;
else if ( V_41 & V_186 )
V_168 = F_10 ( V_7 ) ;
else
V_168 = - V_10 ;
F_124 ( V_8 ) ;
return V_168 ;
}
static int F_126 ( struct V_6 * V_7 , unsigned long V_187 )
{
struct V_1 * V_8 ;
T_3 V_34 ;
T_3 V_188 = 0 ;
V_8 = F_11 ( V_7 -> V_8 ) ;
if ( ! V_8 )
return - V_165 ;
V_34 = V_8 -> V_3 -> V_34 ;
if ( V_187 & V_189 ) {
V_188 = V_190 ;
if ( V_187 & ( V_191 | V_192 ) ) {
if ( V_187 & V_193 )
V_188 |= V_194 ;
if ( V_187 & V_191 )
V_188 |= V_195 ;
if ( V_187 & V_192 )
V_188 |= V_196 ;
}
if ( V_187 & V_197 )
V_188 |= V_198 ;
}
if ( V_188 & ( V_195 | V_196 | V_198 ) )
V_34 |= V_199 ;
else
V_34 &= ~ V_199 ;
V_8 -> V_43 = V_188 ;
V_8 -> V_200 = V_34 ;
F_127 ( V_8 -> V_3 ) ;
return 0 ;
}
static long F_128 ( struct V_5 * V_5 , unsigned int V_201 ,
unsigned long V_187 )
{
struct V_6 * V_7 = V_5 -> V_20 ;
struct V_1 * V_8 ;
void T_10 * V_202 = ( void T_10 * ) V_187 ;
struct V_203 T_10 * V_204 = V_202 ;
unsigned int T_10 * V_205 = V_202 ;
unsigned int V_206 ;
int T_10 * V_207 = V_202 ;
int V_208 ;
int V_168 ;
switch ( V_201 ) {
case V_209 :
if ( F_129 ( V_206 , & V_204 -> V_210 ) )
return - V_172 ;
V_168 = 0 ;
if ( ( V_206 & ~ ( V_42 | V_211 ) ) !=
( V_95 | V_96 ) )
V_168 = - V_10 ;
else
V_7 -> V_41 = V_206 ;
return V_168 ;
case V_212 :
F_15 () ;
V_8 = F_123 ( V_7 ) ;
if ( ! V_8 ) {
F_18 () ;
return - V_165 ;
}
V_168 = 0 ;
if ( F_130 ( & V_204 -> V_213 , V_8 -> V_3 -> V_214 , V_215 ) ||
F_131 ( V_7 -> V_41 , & V_204 -> V_210 ) )
V_168 = - V_172 ;
F_124 ( V_8 ) ;
F_18 () ;
return V_168 ;
case V_216 :
if ( F_129 ( V_206 , & V_204 -> V_210 ) )
return - V_172 ;
F_15 () ;
V_168 = F_125 ( V_5 , V_206 ) ;
F_18 () ;
return V_168 ;
case V_217 :
if ( F_131 ( V_96 | V_95 | V_42 |
V_211 , V_205 ) )
return - V_172 ;
return 0 ;
case V_218 :
if ( F_129 ( V_206 , V_205 ) )
return - V_172 ;
V_7 -> V_19 . V_219 = V_206 ;
return 0 ;
case V_220 :
V_208 = V_7 -> V_97 ;
if ( F_131 ( V_208 , V_207 ) )
return - V_172 ;
return 0 ;
case V_221 :
if ( F_129 ( V_208 , V_207 ) )
return - V_172 ;
if ( V_208 < ( int ) sizeof( struct V_98 ) )
return - V_10 ;
V_7 -> V_97 = V_208 ;
return 0 ;
case V_222 :
if ( V_187 & ~ ( V_189 | V_191 | V_192 |
V_193 | V_197 ) )
return - V_10 ;
F_15 () ;
V_168 = F_126 ( V_7 , V_187 ) ;
F_18 () ;
return V_168 ;
default:
return - V_10 ;
}
}
static long F_132 ( struct V_5 * V_5 , unsigned int V_201 ,
unsigned long V_187 )
{
return F_128 ( V_5 , V_201 , ( unsigned long ) F_133 ( V_187 ) ) ;
}
static int F_134 ( struct V_160 * V_161 , struct V_223 * V_72 ,
struct V_132 * V_133 , T_6 V_136 )
{
struct V_6 * V_7 = F_135 ( V_72 , struct V_6 , V_72 ) ;
return F_90 ( V_7 , V_133 , V_133 -> V_224 , V_136 , V_133 -> V_225 ,
V_133 -> V_226 & V_227 ) ;
}
static int F_136 ( struct V_160 * V_161 , struct V_223 * V_72 ,
struct V_132 * V_133 , T_6 V_136 ,
int V_41 )
{
struct V_6 * V_7 = F_135 ( V_72 , struct V_6 , V_72 ) ;
int V_168 ;
if ( V_41 & ~ ( V_227 | V_228 ) )
return - V_10 ;
V_168 = F_115 ( V_7 , V_133 -> V_224 , V_136 ,
V_41 & V_227 ) ;
if ( V_168 > V_136 ) {
V_133 -> V_226 |= V_228 ;
V_168 = V_41 & V_228 ? V_168 : V_136 ;
}
return V_168 ;
}
struct V_223 * F_137 ( struct V_5 * V_5 )
{
struct V_6 * V_7 ;
if ( V_5 -> V_229 != & V_230 )
return F_138 ( - V_10 ) ;
V_7 = V_5 -> V_20 ;
if ( ! V_7 )
return F_138 ( - V_231 ) ;
return & V_7 -> V_72 ;
}
static int F_139 ( struct V_232 * V_233 ,
unsigned long V_234 , void * V_235 )
{
struct V_2 * V_3 = F_140 ( V_235 ) ;
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
return F_141 ( V_9 ) ;
V_238 = F_142 ( F_143 ( V_243 ) , V_8 -> V_60 ) ;
V_237 = F_144 ( V_244 , & V_3 -> V_3 , V_238 ,
V_3 , L_2 , V_3 -> V_245 ) ;
if ( F_34 ( V_237 ) ) {
F_46 ( V_8 ) ;
return F_141 ( F_145 ( V_237 ) ) ;
}
break;
case V_246 :
V_238 = F_142 ( F_143 ( V_243 ) , V_8 -> V_60 ) ;
F_146 ( V_244 , V_238 ) ;
F_46 ( V_8 ) ;
break;
}
return V_241 ;
}
static int F_147 ( void )
{
int V_9 ;
V_9 = F_148 ( & V_243 , 0 ,
V_58 , L_3 ) ;
if ( V_9 )
goto V_247;
F_149 ( & V_248 , & V_230 ) ;
V_9 = F_150 ( & V_248 , V_243 , V_58 ) ;
if ( V_9 )
goto V_249;
V_244 = F_151 ( V_250 , L_3 ) ;
if ( F_34 ( V_244 ) ) {
V_9 = F_145 ( V_244 ) ;
goto V_251;
}
V_9 = F_152 ( & V_252 ) ;
if ( V_9 )
goto V_253;
V_9 = F_153 ( & V_240 ) ;
if ( V_9 )
goto V_254;
return 0 ;
V_254:
F_154 ( & V_252 ) ;
V_253:
F_155 ( V_244 ) ;
V_251:
F_156 ( & V_248 ) ;
V_249:
F_157 ( V_243 , V_58 ) ;
V_247:
return V_9 ;
}
static void F_158 ( void )
{
F_159 ( & V_240 ) ;
F_154 ( & V_252 ) ;
F_155 ( V_244 ) ;
F_156 ( & V_248 ) ;
F_157 ( V_243 , V_58 ) ;
}
