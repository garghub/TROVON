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
struct V_24 * V_25 ;
struct V_6 * V_7 ;
unsigned long V_100 = V_133 ;
int V_8 ;
struct V_93 V_105 = { 0 } ;
int V_135 = 0 ;
int V_136 = 0 ;
bool V_137 = false ;
T_5 V_101 ;
if ( V_5 -> V_37 & V_38 ) {
V_135 = V_5 -> V_92 ;
V_8 = - V_9 ;
if ( V_100 < V_135 )
goto V_8;
V_100 -= V_135 ;
V_8 = F_87 ( ( void * ) & V_105 , V_132 , 0 ,
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
V_8 = - V_138 ;
if ( F_25 ( V_134 > V_139 ) )
goto V_8;
if ( V_130 && V_130 -> V_140 && F_88 ( & V_5 -> V_18 , V_96 ) ) {
V_136 = V_105 . V_124 ? V_105 . V_124 : V_141 ;
V_101 = V_136 ;
if ( F_89 ( V_132 , V_135 + V_136 , V_134 )
<= V_142 )
V_137 = true ;
}
if ( ! V_137 ) {
V_136 = V_100 ;
V_101 = V_105 . V_124 ;
}
V_25 = F_74 ( & V_5 -> V_18 , V_143 , V_136 ,
V_101 , V_102 , & V_8 ) ;
if ( ! V_25 )
goto V_8;
if ( V_137 )
V_8 = F_90 ( V_25 , V_132 , V_135 , V_134 ) ;
else {
V_8 = F_91 ( V_25 , 0 , V_132 , V_135 ,
V_100 ) ;
if ( ! V_8 && V_130 && V_130 -> V_140 ) {
struct V_144 * V_145 = V_130 -> V_140 ;
V_145 -> V_146 ( V_145 , false ) ;
}
}
if ( V_8 )
goto V_147;
F_92 ( V_25 , V_48 ) ;
F_93 ( V_25 ) ;
V_25 -> V_148 = F_94 ( V_25 ) -> V_149 ;
if ( V_135 ) {
V_8 = F_78 ( V_25 , & V_105 ) ;
if ( V_8 )
goto V_147;
}
F_95 ( V_25 , V_48 ) ;
F_96 () ;
V_7 = F_21 ( V_5 -> V_7 ) ;
if ( V_137 ) {
F_80 ( V_25 ) -> V_150 = V_130 -> V_140 ;
F_80 ( V_25 ) -> V_151 |= V_152 ;
F_80 ( V_25 ) -> V_151 |= V_153 ;
}
if ( V_7 ) {
F_97 () ;
F_98 ( V_25 , V_7 -> V_2 ) ;
F_99 () ;
} else {
F_34 ( V_25 ) ;
}
F_100 () ;
return V_133 ;
V_147:
F_34 ( V_25 ) ;
V_8:
F_96 () ;
V_7 = F_21 ( V_5 -> V_7 ) ;
if ( V_7 )
V_7 -> V_2 -> V_154 . V_155 ++ ;
F_100 () ;
return V_8 ;
}
static T_6 F_101 ( struct V_156 * V_157 , const struct V_131 * V_132 ,
unsigned long V_134 , T_7 V_158 )
{
struct V_3 * V_3 = V_157 -> V_159 ;
T_6 V_160 = - V_161 ;
struct V_4 * V_5 = V_3 -> V_19 ;
V_160 = F_86 ( V_5 , NULL , V_132 , F_102 ( V_132 , V_134 ) , V_134 ,
V_3 -> V_162 & V_163 ) ;
return V_160 ;
}
static T_6 F_103 ( struct V_4 * V_5 ,
const struct V_24 * V_25 ,
const struct V_131 * V_132 , int V_100 )
{
struct V_6 * V_7 ;
int V_164 ;
int V_135 = 0 ;
int V_165 = 0 ;
int V_166 ;
if ( V_5 -> V_37 & V_38 ) {
struct V_93 V_105 ;
V_135 = V_5 -> V_92 ;
if ( ( V_100 -= V_135 ) < 0 )
return - V_9 ;
V_164 = F_81 ( V_25 , & V_105 ) ;
if ( V_164 )
return V_164 ;
if ( F_104 ( V_132 , ( void * ) & V_105 , 0 , sizeof( V_105 ) ) )
return - V_167 ;
}
V_166 = V_135 ;
if ( ! F_105 ( V_25 ) )
V_100 = F_106 ( int , V_25 -> V_100 , V_100 ) ;
else {
int V_168 ;
struct {
T_8 V_169 ;
T_8 V_170 ;
} V_171 ;
V_171 . V_169 = V_25 -> V_172 ;
V_171 . V_170 = F_107 ( F_108 ( V_25 ) ) ;
V_165 = F_109 ( struct V_173 , V_169 ) ;
V_100 = F_106 ( int , V_25 -> V_100 + V_174 , V_100 ) ;
V_168 = F_106 ( int , V_165 , V_100 ) ;
V_164 = F_110 ( V_25 , 0 , V_132 , V_166 , V_168 ) ;
V_100 -= V_168 ;
V_166 += V_168 ;
if ( V_164 || ! V_100 )
goto V_175;
V_168 = F_106 ( int , sizeof( V_171 ) , V_100 ) ;
V_164 = F_104 ( V_132 , ( void * ) & V_171 , V_166 , V_168 ) ;
V_100 -= V_168 ;
V_166 += V_168 ;
if ( V_164 || ! V_100 )
goto V_175;
}
V_164 = F_110 ( V_25 , V_165 , V_132 , V_166 , V_100 ) ;
V_166 += V_100 ;
V_175:
F_96 () ;
V_7 = F_21 ( V_5 -> V_7 ) ;
if ( V_7 ) {
F_111 () ;
F_112 ( V_7 , V_166 - V_135 , V_164 == 0 , 0 ) ;
F_113 () ;
}
F_100 () ;
return V_164 ? V_164 : V_166 ;
}
static T_6 F_114 ( struct V_4 * V_5 , struct V_156 * V_157 ,
const struct V_131 * V_132 , unsigned long V_100 ,
int V_102 )
{
F_115 ( V_82 ) ;
struct V_24 * V_25 ;
T_6 V_164 = 0 ;
while ( V_100 ) {
if ( ! V_102 )
F_116 ( F_36 ( & V_5 -> V_18 ) , & V_82 ,
V_176 ) ;
V_25 = F_117 ( & V_5 -> V_18 . V_35 ) ;
if ( ! V_25 ) {
if ( V_102 ) {
V_164 = - V_177 ;
break;
}
if ( F_118 ( V_75 ) ) {
V_164 = - V_178 ;
break;
}
F_119 () ;
continue;
}
V_164 = F_103 ( V_5 , V_25 , V_132 , V_100 ) ;
F_34 ( V_25 ) ;
break;
}
if ( ! V_102 )
F_120 ( F_36 ( & V_5 -> V_18 ) , & V_82 ) ;
return V_164 ;
}
static T_6 F_121 ( struct V_156 * V_157 , const struct V_131 * V_132 ,
unsigned long V_134 , T_7 V_158 )
{
struct V_3 * V_3 = V_157 -> V_159 ;
struct V_4 * V_5 = V_3 -> V_19 ;
T_6 V_100 , V_164 = 0 ;
V_100 = F_102 ( V_132 , V_134 ) ;
if ( V_100 < 0 ) {
V_164 = - V_9 ;
goto V_11;
}
V_164 = F_114 ( V_5 , V_157 , V_132 , V_100 , V_3 -> V_162 & V_163 ) ;
V_164 = F_106 ( T_6 , V_164 , V_100 ) ;
V_11:
return V_164 ;
}
static struct V_6 * F_122 ( struct V_4 * V_5 )
{
struct V_6 * V_7 ;
F_3 () ;
V_7 = F_11 ( V_5 -> V_7 ) ;
if ( V_7 )
F_48 ( V_7 -> V_2 ) ;
return V_7 ;
}
static void F_123 ( struct V_6 * V_7 )
{
F_68 ( V_7 -> V_2 ) ;
}
static int F_124 ( struct V_3 * V_3 , unsigned int V_37 )
{
struct V_4 * V_5 = V_3 -> V_19 ;
struct V_6 * V_7 ;
int V_164 ;
V_7 = F_122 ( V_5 ) ;
if ( ! V_7 )
return - V_9 ;
if ( V_37 & V_179 )
V_164 = F_1 ( V_7 -> V_2 , V_3 , V_5 ) ;
else if ( V_37 & V_180 )
V_164 = F_10 ( V_5 ) ;
else
V_164 = - V_9 ;
F_123 ( V_7 ) ;
return V_164 ;
}
static int F_125 ( struct V_4 * V_5 , unsigned long V_181 )
{
struct V_6 * V_7 ;
T_2 V_32 ;
T_2 V_182 = 0 ;
V_7 = F_11 ( V_5 -> V_7 ) ;
if ( ! V_7 )
return - V_161 ;
V_32 = V_7 -> V_2 -> V_32 ;
if ( V_181 & V_183 ) {
V_182 = V_184 ;
if ( V_181 & ( V_185 | V_186 ) ) {
if ( V_181 & V_187 )
V_182 |= V_188 ;
if ( V_181 & V_185 )
V_182 |= V_189 ;
if ( V_181 & V_186 )
V_182 |= V_190 ;
}
if ( V_181 & V_191 )
V_182 |= V_192 ;
}
if ( V_182 & ( V_189 | V_190 | V_192 ) )
V_32 |= V_193 ;
else
V_32 &= ~ V_193 ;
V_7 -> V_39 = V_182 ;
V_7 -> V_194 = V_32 ;
F_126 ( V_7 -> V_2 ) ;
return 0 ;
}
static long F_127 ( struct V_3 * V_3 , unsigned int V_195 ,
unsigned long V_181 )
{
struct V_4 * V_5 = V_3 -> V_19 ;
struct V_6 * V_7 ;
void T_9 * V_196 = ( void T_9 * ) V_181 ;
struct V_197 T_9 * V_198 = V_196 ;
unsigned int T_9 * V_199 = V_196 ;
unsigned int V_200 ;
int T_9 * V_201 = V_196 ;
int V_202 ;
int V_164 ;
switch ( V_195 ) {
case V_203 :
if ( F_128 ( V_200 , & V_198 -> V_204 ) )
return - V_167 ;
V_164 = 0 ;
if ( ( V_200 & ~ ( V_38 | V_205 ) ) !=
( V_90 | V_91 ) )
V_164 = - V_9 ;
else
V_5 -> V_37 = V_200 ;
return V_164 ;
case V_206 :
F_6 () ;
V_7 = F_122 ( V_5 ) ;
if ( ! V_7 ) {
F_9 () ;
return - V_161 ;
}
V_164 = 0 ;
if ( F_129 ( & V_198 -> V_207 , V_7 -> V_2 -> V_208 , V_209 ) ||
F_130 ( V_5 -> V_37 , & V_198 -> V_204 ) )
V_164 = - V_167 ;
F_123 ( V_7 ) ;
F_9 () ;
return V_164 ;
case V_210 :
if ( F_128 ( V_200 , & V_198 -> V_204 ) )
return - V_167 ;
F_6 () ;
V_164 = F_124 ( V_3 , V_200 ) ;
F_9 () ;
return V_164 ;
case V_211 :
if ( F_130 ( V_91 | V_90 | V_38 |
V_205 , V_199 ) )
return - V_167 ;
return 0 ;
case V_212 :
if ( F_128 ( V_200 , V_199 ) )
return - V_167 ;
V_5 -> V_18 . V_213 = V_200 ;
return 0 ;
case V_214 :
V_202 = V_5 -> V_92 ;
if ( F_130 ( V_202 , V_201 ) )
return - V_167 ;
return 0 ;
case V_215 :
if ( F_128 ( V_202 , V_201 ) )
return - V_167 ;
if ( V_202 < ( int ) sizeof( struct V_93 ) )
return - V_9 ;
V_5 -> V_92 = V_202 ;
return 0 ;
case V_216 :
if ( V_181 & ~ ( V_183 | V_185 | V_186 |
V_187 | V_191 ) )
return - V_9 ;
F_6 () ;
V_164 = F_125 ( V_5 , V_181 ) ;
F_9 () ;
return V_164 ;
default:
return - V_9 ;
}
}
static long F_131 ( struct V_3 * V_3 , unsigned int V_195 ,
unsigned long V_181 )
{
return F_127 ( V_3 , V_195 , ( unsigned long ) F_132 ( V_181 ) ) ;
}
static int F_133 ( struct V_156 * V_157 , struct V_217 * V_67 ,
struct V_129 * V_130 , T_5 V_133 )
{
struct V_4 * V_5 = F_134 ( V_67 , struct V_4 , V_67 ) ;
return F_86 ( V_5 , V_130 , V_130 -> V_218 , V_133 , V_130 -> V_219 ,
V_130 -> V_220 & V_221 ) ;
}
static int F_135 ( struct V_156 * V_157 , struct V_217 * V_67 ,
struct V_129 * V_130 , T_5 V_133 ,
int V_37 )
{
struct V_4 * V_5 = F_134 ( V_67 , struct V_4 , V_67 ) ;
int V_164 ;
if ( V_37 & ~ ( V_221 | V_222 ) )
return - V_9 ;
V_164 = F_114 ( V_5 , V_157 , V_130 -> V_218 , V_133 ,
V_37 & V_221 ) ;
if ( V_164 > V_133 ) {
V_130 -> V_220 |= V_222 ;
V_164 = V_37 & V_222 ? V_164 : V_133 ;
}
return V_164 ;
}
struct V_217 * F_136 ( struct V_3 * V_3 )
{
struct V_4 * V_5 ;
if ( V_3 -> V_223 != & V_224 )
return F_137 ( - V_9 ) ;
V_5 = V_3 -> V_19 ;
if ( ! V_5 )
return F_137 ( - V_225 ) ;
return & V_5 -> V_67 ;
}
static int F_138 ( struct V_226 * V_227 ,
unsigned long V_228 , void * V_229 )
{
struct V_1 * V_2 = F_139 ( V_229 ) ;
struct V_6 * V_7 ;
struct V_230 * V_231 ;
T_10 V_232 ;
int V_8 ;
if ( V_2 -> V_233 != & V_234 )
return V_235 ;
V_7 = F_2 ( V_2 ) ;
switch ( V_228 ) {
case V_236 :
V_8 = F_39 ( V_7 ) ;
if ( V_8 )
return F_140 ( V_8 ) ;
V_232 = F_141 ( F_142 ( V_237 ) , V_7 -> V_55 ) ;
V_231 = F_143 ( V_238 , & V_2 -> V_2 , V_232 ,
V_2 , L_2 , V_2 -> V_239 ) ;
if ( F_32 ( V_231 ) ) {
F_44 ( V_7 ) ;
return F_140 ( F_144 ( V_231 ) ) ;
}
break;
case V_240 :
V_232 = F_141 ( F_142 ( V_237 ) , V_7 -> V_55 ) ;
F_145 ( V_238 , V_232 ) ;
F_44 ( V_7 ) ;
break;
}
return V_235 ;
}
static int F_146 ( void )
{
int V_8 ;
V_8 = F_147 ( & V_237 , 0 ,
V_53 , L_3 ) ;
if ( V_8 )
goto V_241;
F_148 ( & V_242 , & V_224 ) ;
V_8 = F_149 ( & V_242 , V_237 , V_53 ) ;
if ( V_8 )
goto V_243;
V_238 = F_150 ( V_244 , L_3 ) ;
if ( F_32 ( V_238 ) ) {
V_8 = F_144 ( V_238 ) ;
goto V_245;
}
V_8 = F_151 ( & V_246 ) ;
if ( V_8 )
goto V_247;
V_8 = F_152 ( & V_234 ) ;
if ( V_8 )
goto V_248;
return 0 ;
V_248:
F_153 ( & V_246 ) ;
V_247:
F_154 ( V_238 ) ;
V_245:
F_155 ( & V_242 ) ;
V_243:
F_156 ( V_237 , V_53 ) ;
V_241:
return V_8 ;
}
static void F_157 ( void )
{
F_158 ( & V_234 ) ;
F_153 ( & V_246 ) ;
F_154 ( V_238 ) ;
F_155 ( & V_242 ) ;
F_156 ( V_237 , V_53 ) ;
}
