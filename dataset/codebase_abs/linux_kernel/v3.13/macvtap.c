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
V_8 , 0 ) ;
if ( ! V_25 )
return NULL ;
F_76 ( V_25 , V_99 ) ;
F_77 ( V_25 , V_101 ) ;
V_25 -> V_104 = V_100 - V_101 ;
V_25 -> V_100 += V_100 - V_101 ;
return V_25 ;
}
static int F_78 ( struct V_24 * V_25 ,
struct V_93 * V_105 )
{
unsigned short V_106 = 0 ;
if ( V_105 -> V_106 != V_107 ) {
switch ( V_105 -> V_106 & ~ V_108 ) {
case V_109 :
V_106 = V_110 ;
break;
case V_111 :
V_106 = V_112 ;
break;
case V_113 :
V_106 = V_114 ;
break;
default:
return - V_9 ;
}
if ( V_105 -> V_106 & V_108 )
V_106 |= V_115 ;
if ( V_105 -> V_116 == 0 )
return - V_9 ;
}
if ( V_105 -> V_37 & V_117 ) {
if ( ! F_79 ( V_25 , V_105 -> V_118 ,
V_105 -> V_119 ) )
return - V_9 ;
}
if ( V_105 -> V_106 != V_107 ) {
F_80 ( V_25 ) -> V_116 = V_105 -> V_116 ;
F_80 ( V_25 ) -> V_106 = V_106 ;
F_80 ( V_25 ) -> V_106 |= V_120 ;
F_80 ( V_25 ) -> V_121 = 0 ;
}
return 0 ;
}
static int F_81 ( const struct V_24 * V_25 ,
struct V_93 * V_105 )
{
memset ( V_105 , 0 , sizeof( * V_105 ) ) ;
if ( F_82 ( V_25 ) ) {
struct V_122 * V_123 = F_80 ( V_25 ) ;
V_105 -> V_124 = F_83 ( V_25 ) ;
V_105 -> V_116 = V_123 -> V_116 ;
if ( V_123 -> V_106 & V_110 )
V_105 -> V_106 = V_109 ;
else if ( V_123 -> V_106 & V_112 )
V_105 -> V_106 = V_111 ;
else if ( V_123 -> V_106 & V_114 )
V_105 -> V_106 = V_113 ;
else
F_84 () ;
if ( V_123 -> V_106 & V_115 )
V_105 -> V_106 |= V_108 ;
} else
V_105 -> V_106 = V_107 ;
if ( V_25 -> V_125 == V_126 ) {
V_105 -> V_37 = V_117 ;
V_105 -> V_118 = F_85 ( V_25 ) ;
V_105 -> V_119 = V_25 -> V_119 ;
} else if ( V_25 -> V_125 == V_127 ) {
V_105 -> V_37 = V_128 ;
}
return 0 ;
}
static T_6 F_86 ( struct V_4 * V_5 , struct V_129 * V_130 ,
const struct V_131 * V_132 , unsigned long V_133 ,
T_5 V_134 , int V_102 )
{
int V_135 = F_87 ( V_136 ) ;
struct V_24 * V_25 ;
struct V_6 * V_7 ;
unsigned long V_100 = V_133 ;
int V_8 ;
struct V_93 V_105 = { 0 } ;
int V_137 = 0 ;
int V_138 = 0 ;
bool V_139 = false ;
T_5 V_101 ;
if ( V_5 -> V_37 & V_38 ) {
V_137 = V_5 -> V_92 ;
V_8 = - V_9 ;
if ( V_100 < V_137 )
goto V_8;
V_100 -= V_137 ;
V_8 = F_88 ( ( void * ) & V_105 , V_132 , 0 ,
sizeof( V_105 ) ) ;
if ( V_8 < 0 )
goto V_8;
if ( ( V_105 . V_37 & V_117 ) &&
V_105 . V_118 + V_105 . V_119 + 2 >
V_105 . V_124 )
V_105 . V_124 = V_105 . V_118 +
V_105 . V_119 + 2 ;
V_8 = - V_9 ;
if ( V_105 . V_124 > V_100 )
goto V_8;
}
V_8 = - V_9 ;
if ( F_25 ( V_100 < V_48 ) )
goto V_8;
V_8 = - V_140 ;
if ( F_25 ( V_134 > V_141 ) )
goto V_8;
if ( V_130 && V_130 -> V_142 && F_89 ( & V_5 -> V_18 , V_96 ) ) {
V_138 = V_105 . V_124 ? V_105 . V_124 : V_143 ;
if ( V_138 > V_135 )
V_138 = V_135 ;
V_101 = V_138 ;
if ( F_90 ( V_132 , V_137 + V_138 , V_134 )
<= V_144 )
V_139 = true ;
}
if ( ! V_139 ) {
V_138 = V_100 ;
if ( V_105 . V_124 > V_135 )
V_101 = V_135 ;
else
V_101 = V_105 . V_124 ;
}
V_25 = F_74 ( & V_5 -> V_18 , V_136 , V_138 ,
V_101 , V_102 , & V_8 ) ;
if ( ! V_25 )
goto V_8;
if ( V_139 )
V_8 = F_91 ( V_25 , V_132 , V_137 , V_134 ) ;
else {
V_8 = F_92 ( V_25 , 0 , V_132 , V_137 ,
V_100 ) ;
if ( ! V_8 && V_130 && V_130 -> V_142 ) {
struct V_145 * V_146 = V_130 -> V_142 ;
V_146 -> V_147 ( V_146 , false ) ;
}
}
if ( V_8 )
goto V_148;
F_93 ( V_25 , V_48 ) ;
F_94 ( V_25 ) ;
V_25 -> V_149 = F_95 ( V_25 ) -> V_150 ;
if ( V_137 ) {
V_8 = F_78 ( V_25 , & V_105 ) ;
if ( V_8 )
goto V_148;
}
F_96 ( V_25 , V_48 ) ;
F_97 () ;
V_7 = F_21 ( V_5 -> V_7 ) ;
if ( V_139 ) {
F_80 ( V_25 ) -> V_151 = V_130 -> V_142 ;
F_80 ( V_25 ) -> V_152 |= V_153 ;
F_80 ( V_25 ) -> V_152 |= V_154 ;
}
if ( V_7 ) {
F_98 () ;
F_99 ( V_25 , V_7 -> V_2 ) ;
F_100 () ;
} else {
F_34 ( V_25 ) ;
}
F_101 () ;
return V_133 ;
V_148:
F_34 ( V_25 ) ;
V_8:
F_97 () ;
V_7 = F_21 ( V_5 -> V_7 ) ;
if ( V_7 )
F_102 ( V_7 -> V_155 -> V_156 ) ;
F_101 () ;
return V_8 ;
}
static T_6 F_103 ( struct V_157 * V_158 , const struct V_131 * V_132 ,
unsigned long V_134 , T_7 V_159 )
{
struct V_3 * V_3 = V_158 -> V_160 ;
T_6 V_161 = - V_162 ;
struct V_4 * V_5 = V_3 -> V_19 ;
V_161 = F_86 ( V_5 , NULL , V_132 , F_104 ( V_132 , V_134 ) , V_134 ,
V_3 -> V_163 & V_164 ) ;
return V_161 ;
}
static T_6 F_105 ( struct V_4 * V_5 ,
const struct V_24 * V_25 ,
const struct V_131 * V_132 , int V_100 )
{
int V_165 ;
int V_137 = 0 ;
int V_166 = 0 ;
int V_167 , V_168 ;
if ( V_5 -> V_37 & V_38 ) {
struct V_93 V_105 ;
V_137 = V_5 -> V_92 ;
if ( ( V_100 -= V_137 ) < 0 )
return - V_9 ;
V_165 = F_81 ( V_25 , & V_105 ) ;
if ( V_165 )
return V_165 ;
if ( F_106 ( V_132 , ( void * ) & V_105 , 0 , sizeof( V_105 ) ) )
return - V_169 ;
}
V_168 = V_167 = V_137 ;
V_168 += V_25 -> V_100 ;
if ( ! F_107 ( V_25 ) )
V_100 = F_108 ( int , V_25 -> V_100 , V_100 ) ;
else {
int V_170 ;
struct {
T_8 V_171 ;
T_8 V_172 ;
} V_173 ;
V_173 . V_171 = V_25 -> V_174 ;
V_173 . V_172 = F_109 ( F_110 ( V_25 ) ) ;
V_166 = F_111 ( struct V_175 , V_171 ) ;
V_100 = F_108 ( int , V_25 -> V_100 + V_176 , V_100 ) ;
V_168 += V_176 ;
V_170 = F_108 ( int , V_166 , V_100 ) ;
V_165 = F_112 ( V_25 , 0 , V_132 , V_167 , V_170 ) ;
V_100 -= V_170 ;
V_167 += V_170 ;
if ( V_165 || ! V_100 )
goto V_177;
V_170 = F_108 ( int , sizeof( V_173 ) , V_100 ) ;
V_165 = F_106 ( V_132 , ( void * ) & V_173 , V_167 , V_170 ) ;
V_100 -= V_170 ;
V_167 += V_170 ;
if ( V_165 || ! V_100 )
goto V_177;
}
V_165 = F_112 ( V_25 , V_166 , V_132 , V_167 , V_100 ) ;
V_177:
return V_165 ? V_165 : V_168 ;
}
static T_6 F_113 ( struct V_4 * V_5 , struct V_157 * V_158 ,
const struct V_131 * V_132 , unsigned long V_100 ,
int V_102 )
{
F_114 ( V_82 ) ;
struct V_24 * V_25 ;
T_6 V_165 = 0 ;
while ( V_100 ) {
if ( ! V_102 )
F_115 ( F_36 ( & V_5 -> V_18 ) , & V_82 ,
V_178 ) ;
V_25 = F_116 ( & V_5 -> V_18 . V_35 ) ;
if ( ! V_25 ) {
if ( V_102 ) {
V_165 = - V_179 ;
break;
}
if ( F_117 ( V_75 ) ) {
V_165 = - V_180 ;
break;
}
F_118 () ;
continue;
}
V_165 = F_105 ( V_5 , V_25 , V_132 , V_100 ) ;
F_34 ( V_25 ) ;
break;
}
if ( ! V_102 )
F_119 ( F_36 ( & V_5 -> V_18 ) , & V_82 ) ;
return V_165 ;
}
static T_6 F_120 ( struct V_157 * V_158 , const struct V_131 * V_132 ,
unsigned long V_134 , T_7 V_159 )
{
struct V_3 * V_3 = V_158 -> V_160 ;
struct V_4 * V_5 = V_3 -> V_19 ;
T_6 V_100 , V_165 = 0 ;
V_100 = F_104 ( V_132 , V_134 ) ;
if ( V_100 < 0 ) {
V_165 = - V_9 ;
goto V_11;
}
V_165 = F_113 ( V_5 , V_158 , V_132 , V_100 , V_3 -> V_163 & V_164 ) ;
V_165 = F_108 ( T_6 , V_165 , V_100 ) ;
if ( V_165 > 0 )
V_158 -> V_181 = V_165 ;
V_11:
return V_165 ;
}
static struct V_6 * F_121 ( struct V_4 * V_5 )
{
struct V_6 * V_7 ;
F_3 () ;
V_7 = F_11 ( V_5 -> V_7 ) ;
if ( V_7 )
F_48 ( V_7 -> V_2 ) ;
return V_7 ;
}
static void F_122 ( struct V_6 * V_7 )
{
F_68 ( V_7 -> V_2 ) ;
}
static int F_123 ( struct V_3 * V_3 , unsigned int V_37 )
{
struct V_4 * V_5 = V_3 -> V_19 ;
struct V_6 * V_7 ;
int V_165 ;
V_7 = F_121 ( V_5 ) ;
if ( ! V_7 )
return - V_9 ;
if ( V_37 & V_182 )
V_165 = F_1 ( V_7 -> V_2 , V_3 , V_5 ) ;
else if ( V_37 & V_183 )
V_165 = F_10 ( V_5 ) ;
else
V_165 = - V_9 ;
F_122 ( V_7 ) ;
return V_165 ;
}
static int F_124 ( struct V_4 * V_5 , unsigned long V_184 )
{
struct V_6 * V_7 ;
T_2 V_32 ;
T_2 V_185 = 0 ;
V_7 = F_11 ( V_5 -> V_7 ) ;
if ( ! V_7 )
return - V_162 ;
V_32 = V_7 -> V_2 -> V_32 ;
if ( V_184 & V_186 ) {
V_185 = V_187 ;
if ( V_184 & ( V_188 | V_189 ) ) {
if ( V_184 & V_190 )
V_185 |= V_191 ;
if ( V_184 & V_188 )
V_185 |= V_192 ;
if ( V_184 & V_189 )
V_185 |= V_193 ;
}
if ( V_184 & V_194 )
V_185 |= V_195 ;
}
if ( V_185 & ( V_192 | V_193 | V_195 ) )
V_32 |= V_196 ;
else
V_32 &= ~ V_196 ;
V_7 -> V_39 = V_185 ;
V_7 -> V_197 = V_32 ;
F_125 ( V_7 -> V_2 ) ;
return 0 ;
}
static long F_126 ( struct V_3 * V_3 , unsigned int V_198 ,
unsigned long V_184 )
{
struct V_4 * V_5 = V_3 -> V_19 ;
struct V_6 * V_7 ;
void T_9 * V_199 = ( void T_9 * ) V_184 ;
struct V_200 T_9 * V_201 = V_199 ;
unsigned int T_9 * V_202 = V_199 ;
unsigned int V_203 ;
int T_9 * V_204 = V_199 ;
int V_205 ;
int V_165 ;
switch ( V_198 ) {
case V_206 :
if ( F_127 ( V_203 , & V_201 -> V_207 ) )
return - V_169 ;
V_165 = 0 ;
if ( ( V_203 & ~ ( V_38 | V_208 ) ) !=
( V_90 | V_91 ) )
V_165 = - V_9 ;
else
V_5 -> V_37 = V_203 ;
return V_165 ;
case V_209 :
F_6 () ;
V_7 = F_121 ( V_5 ) ;
if ( ! V_7 ) {
F_9 () ;
return - V_162 ;
}
V_165 = 0 ;
if ( F_128 ( & V_201 -> V_210 , V_7 -> V_2 -> V_211 , V_212 ) ||
F_129 ( V_5 -> V_37 , & V_201 -> V_207 ) )
V_165 = - V_169 ;
F_122 ( V_7 ) ;
F_9 () ;
return V_165 ;
case V_213 :
if ( F_127 ( V_203 , & V_201 -> V_207 ) )
return - V_169 ;
F_6 () ;
V_165 = F_123 ( V_3 , V_203 ) ;
F_9 () ;
return V_165 ;
case V_214 :
if ( F_129 ( V_91 | V_90 | V_38 |
V_208 , V_202 ) )
return - V_169 ;
return 0 ;
case V_215 :
if ( F_127 ( V_203 , V_202 ) )
return - V_169 ;
V_5 -> V_18 . V_216 = V_203 ;
return 0 ;
case V_217 :
V_205 = V_5 -> V_92 ;
if ( F_129 ( V_205 , V_204 ) )
return - V_169 ;
return 0 ;
case V_218 :
if ( F_127 ( V_205 , V_204 ) )
return - V_169 ;
if ( V_205 < ( int ) sizeof( struct V_93 ) )
return - V_9 ;
V_5 -> V_92 = V_205 ;
return 0 ;
case V_219 :
if ( V_184 & ~ ( V_186 | V_188 | V_189 |
V_190 | V_194 ) )
return - V_9 ;
F_6 () ;
V_165 = F_124 ( V_5 , V_184 ) ;
F_9 () ;
return V_165 ;
default:
return - V_9 ;
}
}
static long F_130 ( struct V_3 * V_3 , unsigned int V_198 ,
unsigned long V_184 )
{
return F_126 ( V_3 , V_198 , ( unsigned long ) F_131 ( V_184 ) ) ;
}
static int F_132 ( struct V_157 * V_158 , struct V_220 * V_67 ,
struct V_129 * V_130 , T_5 V_133 )
{
struct V_4 * V_5 = F_133 ( V_67 , struct V_4 , V_67 ) ;
return F_86 ( V_5 , V_130 , V_130 -> V_221 , V_133 , V_130 -> V_222 ,
V_130 -> V_223 & V_224 ) ;
}
static int F_134 ( struct V_157 * V_158 , struct V_220 * V_67 ,
struct V_129 * V_130 , T_5 V_133 ,
int V_37 )
{
struct V_4 * V_5 = F_133 ( V_67 , struct V_4 , V_67 ) ;
int V_165 ;
if ( V_37 & ~ ( V_224 | V_225 ) )
return - V_9 ;
V_165 = F_113 ( V_5 , V_158 , V_130 -> V_221 , V_133 ,
V_37 & V_224 ) ;
if ( V_165 > V_133 ) {
V_130 -> V_223 |= V_225 ;
V_165 = V_37 & V_225 ? V_165 : V_133 ;
}
return V_165 ;
}
struct V_220 * F_135 ( struct V_3 * V_3 )
{
struct V_4 * V_5 ;
if ( V_3 -> V_226 != & V_227 )
return F_136 ( - V_9 ) ;
V_5 = V_3 -> V_19 ;
if ( ! V_5 )
return F_136 ( - V_228 ) ;
return & V_5 -> V_67 ;
}
static int F_137 ( struct V_229 * V_230 ,
unsigned long V_231 , void * V_232 )
{
struct V_1 * V_2 = F_138 ( V_232 ) ;
struct V_6 * V_7 ;
struct V_233 * V_234 ;
T_10 V_235 ;
int V_8 ;
if ( V_2 -> V_236 != & V_237 )
return V_238 ;
V_7 = F_2 ( V_2 ) ;
switch ( V_231 ) {
case V_239 :
V_8 = F_39 ( V_7 ) ;
if ( V_8 )
return F_139 ( V_8 ) ;
V_235 = F_140 ( F_141 ( V_240 ) , V_7 -> V_55 ) ;
V_234 = F_142 ( V_241 , & V_2 -> V_2 , V_235 ,
V_2 , L_2 , V_2 -> V_242 ) ;
if ( F_32 ( V_234 ) ) {
F_44 ( V_7 ) ;
return F_139 ( F_143 ( V_234 ) ) ;
}
break;
case V_243 :
V_235 = F_140 ( F_141 ( V_240 ) , V_7 -> V_55 ) ;
F_144 ( V_241 , V_235 ) ;
F_44 ( V_7 ) ;
break;
}
return V_238 ;
}
static int F_145 ( void )
{
int V_8 ;
V_8 = F_146 ( & V_240 , 0 ,
V_53 , L_3 ) ;
if ( V_8 )
goto V_244;
F_147 ( & V_245 , & V_227 ) ;
V_8 = F_148 ( & V_245 , V_240 , V_53 ) ;
if ( V_8 )
goto V_246;
V_241 = F_149 ( V_247 , L_3 ) ;
if ( F_32 ( V_241 ) ) {
V_8 = F_143 ( V_241 ) ;
goto V_248;
}
V_8 = F_150 ( & V_249 ) ;
if ( V_8 )
goto V_250;
V_8 = F_151 ( & V_237 ) ;
if ( V_8 )
goto V_251;
return 0 ;
V_251:
F_152 ( & V_249 ) ;
V_250:
F_153 ( V_241 ) ;
V_248:
F_154 ( & V_245 ) ;
V_246:
F_155 ( V_240 , V_53 ) ;
V_244:
return V_8 ;
}
static void F_156 ( void )
{
F_157 ( & V_237 ) ;
F_152 ( & V_249 ) ;
F_153 ( V_241 ) ;
F_154 ( & V_245 ) ;
F_155 ( V_240 , V_53 ) ;
}
