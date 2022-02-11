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
int V_9 = - V_16 ;
F_8 () ;
if ( V_8 -> V_17 == V_18 )
goto V_12;
V_9 = 0 ;
F_6 ( V_7 -> V_8 , V_8 ) ;
F_6 ( V_8 -> V_13 [ V_8 -> V_14 ] , V_7 ) ;
F_9 ( & V_7 -> V_19 ) ;
V_7 -> V_5 = V_5 ;
V_7 -> V_15 = V_8 -> V_14 ;
V_7 -> V_11 = true ;
V_5 -> V_20 = V_7 ;
F_10 ( & V_7 -> V_21 , & V_8 -> V_22 ) ;
V_8 -> V_14 ++ ;
V_8 -> V_17 ++ ;
V_12:
F_11 () ;
return V_9 ;
}
static int F_12 ( struct V_6 * V_7 )
{
struct V_1 * V_8 ;
struct V_6 * V_23 ;
F_5 () ;
if ( ! V_7 -> V_11 )
return - V_10 ;
V_8 = F_13 ( V_7 -> V_8 ) ;
if ( V_8 ) {
int V_24 = V_7 -> V_15 ;
F_14 ( V_24 >= V_8 -> V_14 ) ;
V_23 = F_13 ( V_8 -> V_13 [ V_8 -> V_14 - 1 ] ) ;
V_23 -> V_15 = V_24 ;
F_6 ( V_8 -> V_13 [ V_24 ] , V_23 ) ;
F_15 ( V_8 -> V_13 [ V_8 -> V_14 - 1 ] , NULL ) ;
V_7 -> V_11 = false ;
V_8 -> V_14 -- ;
}
return 0 ;
}
static void F_16 ( struct V_6 * V_7 )
{
struct V_1 * V_8 ;
F_8 () ;
V_8 = F_13 ( V_7 -> V_8 ) ;
if ( V_8 ) {
if ( V_7 -> V_11 )
F_14 ( F_12 ( V_7 ) ) ;
V_8 -> V_17 -- ;
F_15 ( V_7 -> V_8 , NULL ) ;
F_17 ( & V_7 -> V_19 ) ;
F_18 ( & V_7 -> V_21 ) ;
}
F_11 () ;
F_19 () ;
F_17 ( & V_7 -> V_19 ) ;
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
struct V_6 * V_7 , * V_29 , * V_30 [ V_18 ] ;
int V_31 , V_32 = 0 ;
F_5 () ;
F_28 (q, tmp, &vlan->queue_list, next) {
F_18 ( & V_7 -> V_21 ) ;
V_30 [ V_32 ++ ] = V_7 ;
F_15 ( V_7 -> V_8 , NULL ) ;
if ( V_7 -> V_11 )
V_8 -> V_14 -- ;
V_8 -> V_17 -- ;
}
for ( V_31 = 0 ; V_31 < V_8 -> V_14 ; V_31 ++ )
F_15 ( V_8 -> V_13 [ V_31 ] , NULL ) ;
F_14 ( V_8 -> V_14 ) ;
F_14 ( V_8 -> V_17 ) ;
V_8 -> V_14 = V_18 ;
for ( -- V_32 ; V_32 >= 0 ; V_32 -- )
F_17 ( & V_30 [ V_32 ] -> V_19 ) ;
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
F_35 ( & V_7 -> V_19 . V_37 , V_26 ) ;
}
V_45:
F_37 ( F_38 ( & V_7 -> V_19 ) , V_47 | V_48 | V_49 ) ;
return V_50 ;
V_39:
F_39 ( V_8 , 0 , 0 , 0 ) ;
F_36 ( V_26 ) ;
return V_50 ;
}
static int F_40 ( struct V_1 * V_8 )
{
int V_51 = - V_52 ;
F_41 ( & V_53 ) ;
V_51 = F_42 ( & V_54 , V_8 , 1 , V_55 , V_56 ) ;
if ( V_51 >= 0 ) {
V_8 -> V_57 = V_51 ;
} else if ( V_51 == - V_58 ) {
F_43 ( V_59 L_1 ) ;
V_51 = - V_10 ;
}
F_44 ( & V_53 ) ;
return V_51 < 0 ? V_51 : 0 ;
}
static void F_45 ( struct V_1 * V_8 )
{
F_41 ( & V_53 ) ;
if ( V_8 -> V_57 ) {
F_46 ( & V_54 , V_8 -> V_57 ) ;
V_8 -> V_57 = 0 ;
}
F_44 ( & V_53 ) ;
}
static struct V_2 * F_47 ( int V_57 )
{
struct V_2 * V_3 = NULL ;
struct V_1 * V_8 ;
F_41 ( & V_53 ) ;
V_8 = F_48 ( & V_54 , V_57 ) ;
if ( V_8 ) {
V_3 = V_8 -> V_3 ;
F_49 ( V_3 ) ;
}
F_44 ( & V_53 ) ;
return V_3 ;
}
static int F_50 ( struct V_60 * V_61 ,
struct V_2 * V_3 ,
struct V_62 * V_63 [] ,
struct V_62 * V_64 [] )
{
struct V_1 * V_8 = F_4 ( V_3 ) ;
int V_9 ;
F_51 ( & V_8 -> V_22 ) ;
V_8 -> V_43 = V_65 ;
V_9 = F_52 ( V_3 , F_29 , V_8 ) ;
if ( V_9 )
return V_9 ;
return F_53 ( V_61 , V_3 , V_63 , V_64 ) ;
}
static void F_54 ( struct V_2 * V_3 ,
struct V_66 * V_67 )
{
F_55 ( V_3 ) ;
F_27 ( V_3 ) ;
F_56 ( V_3 , V_67 ) ;
}
static void F_57 ( struct V_2 * V_3 )
{
F_58 ( V_3 ) ;
V_3 -> V_38 = V_68 ;
}
static void F_59 ( struct V_69 * V_19 )
{
T_4 * V_70 ;
if ( ! F_60 ( V_19 ) ||
! F_61 ( V_71 , & V_19 -> V_72 -> V_41 ) )
return;
V_70 = F_38 ( V_19 ) ;
if ( V_70 && F_62 ( V_70 ) )
F_37 ( V_70 , V_73 | V_74 | V_75 ) ;
}
static void F_63 ( struct V_69 * V_19 )
{
F_64 ( & V_19 -> V_37 ) ;
}
static int F_65 ( struct V_76 * V_76 , struct V_5 * V_5 )
{
struct V_60 * V_60 = V_77 -> V_78 -> V_79 ;
struct V_2 * V_3 = F_47 ( F_66 ( V_76 ) ) ;
struct V_6 * V_7 ;
int V_9 ;
V_9 = - V_80 ;
if ( ! V_3 )
goto V_12;
V_9 = - V_52 ;
V_7 = (struct V_6 * ) F_67 ( V_60 , V_81 , V_56 ,
& V_82 ) ;
if ( ! V_7 )
goto V_12;
F_15 ( V_7 -> V_69 . V_83 , & V_7 -> V_83 ) ;
F_68 ( & V_7 -> V_83 . V_84 ) ;
V_7 -> V_69 . type = V_85 ;
V_7 -> V_69 . V_86 = V_87 ;
V_7 -> V_69 . V_5 = V_5 ;
V_7 -> V_69 . V_88 = & V_89 ;
F_69 ( & V_7 -> V_69 , & V_7 -> V_19 ) ;
V_7 -> V_19 . V_90 = F_59 ;
V_7 -> V_19 . V_91 = F_63 ;
V_7 -> V_41 = V_42 | V_92 | V_93 ;
V_7 -> V_94 = sizeof( struct V_95 ) ;
if ( ( V_3 -> V_34 & V_96 ) && ( V_3 -> V_34 & V_97 ) )
F_70 ( & V_7 -> V_19 , V_98 ) ;
V_9 = F_7 ( V_3 , V_5 , V_7 ) ;
if ( V_9 )
F_17 ( & V_7 -> V_19 ) ;
V_12:
if ( V_3 )
F_71 ( V_3 ) ;
return V_9 ;
}
static int F_72 ( struct V_76 * V_76 , struct V_5 * V_5 )
{
struct V_6 * V_7 = V_5 -> V_20 ;
F_16 ( V_7 ) ;
return 0 ;
}
static unsigned int F_73 ( struct V_5 * V_5 , T_5 * V_84 )
{
struct V_6 * V_7 = V_5 -> V_20 ;
unsigned int V_99 = V_100 ;
if ( ! V_7 )
goto V_12;
V_99 = 0 ;
F_74 ( V_5 , & V_7 -> V_83 . V_84 , V_84 ) ;
if ( ! F_75 ( & V_7 -> V_19 . V_37 ) )
V_99 |= V_47 | V_48 ;
if ( F_60 ( & V_7 -> V_19 ) ||
( ! F_76 ( V_71 , & V_7 -> V_69 . V_41 ) &&
F_60 ( & V_7 -> V_19 ) ) )
V_99 |= V_73 | V_74 ;
V_12:
return V_99 ;
}
static inline struct V_25 * F_77 ( struct V_69 * V_19 , T_6 V_101 ,
T_6 V_102 , T_6 V_103 ,
int V_104 , int * V_9 )
{
struct V_25 * V_26 ;
if ( V_101 + V_102 < V_105 || ! V_103 )
V_103 = V_102 ;
V_26 = F_78 ( V_19 , V_101 + V_103 , V_102 - V_103 , V_104 ,
V_9 , 0 ) ;
if ( ! V_26 )
return NULL ;
F_79 ( V_26 , V_101 ) ;
F_80 ( V_26 , V_103 ) ;
V_26 -> V_106 = V_102 - V_103 ;
V_26 -> V_102 += V_102 - V_103 ;
return V_26 ;
}
static int F_81 ( struct V_25 * V_26 ,
struct V_95 * V_107 )
{
unsigned short V_108 = 0 ;
if ( V_107 -> V_108 != V_109 ) {
switch ( V_107 -> V_108 & ~ V_110 ) {
case V_111 :
V_108 = V_112 ;
break;
case V_113 :
V_108 = V_114 ;
break;
case V_115 :
V_108 = V_116 ;
break;
default:
return - V_10 ;
}
if ( V_107 -> V_108 & V_110 )
V_108 |= V_117 ;
if ( V_107 -> V_118 == 0 )
return - V_10 ;
}
if ( V_107 -> V_41 & V_119 ) {
if ( ! F_82 ( V_26 , V_107 -> V_120 ,
V_107 -> V_121 ) )
return - V_10 ;
}
if ( V_107 -> V_108 != V_109 ) {
F_83 ( V_26 ) -> V_118 = V_107 -> V_118 ;
F_83 ( V_26 ) -> V_108 = V_108 ;
F_83 ( V_26 ) -> V_108 |= V_122 ;
F_83 ( V_26 ) -> V_123 = 0 ;
}
return 0 ;
}
static void F_84 ( const struct V_25 * V_26 ,
struct V_95 * V_107 )
{
memset ( V_107 , 0 , sizeof( * V_107 ) ) ;
if ( F_85 ( V_26 ) ) {
struct V_124 * V_125 = F_83 ( V_26 ) ;
V_107 -> V_126 = F_86 ( V_26 ) ;
V_107 -> V_118 = V_125 -> V_118 ;
if ( V_125 -> V_108 & V_112 )
V_107 -> V_108 = V_111 ;
else if ( V_125 -> V_108 & V_114 )
V_107 -> V_108 = V_113 ;
else if ( V_125 -> V_108 & V_116 )
V_107 -> V_108 = V_115 ;
else
F_87 () ;
if ( V_125 -> V_108 & V_117 )
V_107 -> V_108 |= V_110 ;
} else
V_107 -> V_108 = V_109 ;
if ( V_26 -> V_127 == V_128 ) {
V_107 -> V_41 = V_119 ;
V_107 -> V_120 = F_88 ( V_26 ) ;
V_107 -> V_121 = V_26 -> V_121 ;
} else if ( V_26 -> V_127 == V_129 ) {
V_107 -> V_41 = V_130 ;
}
}
static T_7 F_89 ( struct V_6 * V_7 , struct V_131 * V_132 ,
const struct V_133 * V_134 , unsigned long V_135 ,
T_6 V_136 , int V_104 )
{
int V_137 = F_90 ( V_138 ) ;
struct V_25 * V_26 ;
struct V_1 * V_8 ;
unsigned long V_102 = V_135 ;
int V_9 ;
struct V_95 V_107 = { 0 } ;
int V_139 = 0 ;
int V_140 = 0 ;
bool V_141 = false ;
T_6 V_103 ;
if ( V_7 -> V_41 & V_42 ) {
V_139 = V_7 -> V_94 ;
V_9 = - V_10 ;
if ( V_102 < V_139 )
goto V_9;
V_102 -= V_139 ;
V_9 = F_91 ( ( void * ) & V_107 , V_134 , 0 ,
sizeof( V_107 ) ) ;
if ( V_9 < 0 )
goto V_9;
if ( ( V_107 . V_41 & V_119 ) &&
V_107 . V_120 + V_107 . V_121 + 2 >
V_107 . V_126 )
V_107 . V_126 = V_107 . V_120 +
V_107 . V_121 + 2 ;
V_9 = - V_10 ;
if ( V_107 . V_126 > V_102 )
goto V_9;
}
V_9 = - V_10 ;
if ( F_26 ( V_102 < V_40 ) )
goto V_9;
V_9 = - V_142 ;
if ( F_26 ( V_136 > V_143 ) )
goto V_9;
if ( V_132 && V_132 -> V_144 && F_92 ( & V_7 -> V_19 , V_98 ) ) {
V_140 = V_107 . V_126 ? V_107 . V_126 : V_145 ;
if ( V_140 > V_137 )
V_140 = V_137 ;
V_103 = V_140 ;
if ( F_93 ( V_134 , V_139 + V_140 , V_136 )
<= V_146 )
V_141 = true ;
}
if ( ! V_141 ) {
V_140 = V_102 ;
if ( V_107 . V_126 > V_137 )
V_103 = V_137 ;
else
V_103 = V_107 . V_126 ;
}
V_26 = F_77 ( & V_7 -> V_19 , V_138 , V_140 ,
V_103 , V_104 , & V_9 ) ;
if ( ! V_26 )
goto V_9;
if ( V_141 )
V_9 = F_94 ( V_26 , V_134 , V_139 , V_136 ) ;
else {
V_9 = F_95 ( V_26 , 0 , V_134 , V_139 ,
V_102 ) ;
if ( ! V_9 && V_132 && V_132 -> V_144 ) {
struct V_147 * V_148 = V_132 -> V_144 ;
V_148 -> V_149 ( V_148 , false ) ;
}
}
if ( V_9 )
goto V_150;
F_96 ( V_26 , V_40 ) ;
F_97 ( V_26 ) ;
V_26 -> V_151 = F_98 ( V_26 ) -> V_152 ;
if ( V_139 ) {
V_9 = F_81 ( V_26 , & V_107 ) ;
if ( V_9 )
goto V_150;
}
F_99 ( V_26 , V_40 ) ;
F_100 () ;
V_8 = F_2 ( V_7 -> V_8 ) ;
if ( V_141 ) {
F_83 ( V_26 ) -> V_153 = V_132 -> V_144 ;
F_83 ( V_26 ) -> V_154 |= V_155 ;
F_83 ( V_26 ) -> V_154 |= V_156 ;
}
if ( V_8 ) {
V_26 -> V_3 = V_8 -> V_3 ;
F_101 ( V_26 ) ;
} else {
F_36 ( V_26 ) ;
}
F_102 () ;
return V_135 ;
V_150:
F_36 ( V_26 ) ;
V_9:
F_100 () ;
V_8 = F_2 ( V_7 -> V_8 ) ;
if ( V_8 )
F_103 ( V_8 -> V_157 -> V_158 ) ;
F_102 () ;
return V_9 ;
}
static T_7 F_104 ( struct V_159 * V_160 , const struct V_133 * V_134 ,
unsigned long V_136 , T_8 V_161 )
{
struct V_5 * V_5 = V_160 -> V_162 ;
T_7 V_163 = - V_164 ;
struct V_6 * V_7 = V_5 -> V_20 ;
V_163 = F_89 ( V_7 , NULL , V_134 , F_105 ( V_134 , V_136 ) , V_136 ,
V_5 -> V_165 & V_166 ) ;
return V_163 ;
}
static T_7 F_106 ( struct V_6 * V_7 ,
const struct V_25 * V_26 ,
const struct V_133 * V_134 , int V_102 )
{
int V_167 ;
int V_139 = 0 ;
int V_168 = 0 ;
int V_169 , V_170 ;
if ( V_7 -> V_41 & V_42 ) {
struct V_95 V_107 ;
V_139 = V_7 -> V_94 ;
if ( ( V_102 -= V_139 ) < 0 )
return - V_10 ;
F_84 ( V_26 , & V_107 ) ;
if ( F_107 ( V_134 , ( void * ) & V_107 , 0 , sizeof( V_107 ) ) )
return - V_171 ;
}
V_170 = V_169 = V_139 ;
V_170 += V_26 -> V_102 ;
if ( ! F_108 ( V_26 ) )
V_102 = F_109 ( int , V_26 -> V_102 , V_102 ) ;
else {
int V_172 ;
struct {
T_9 V_173 ;
T_9 V_174 ;
} V_175 ;
V_175 . V_173 = V_26 -> V_176 ;
V_175 . V_174 = F_110 ( F_111 ( V_26 ) ) ;
V_168 = F_112 ( struct V_177 , V_173 ) ;
V_102 = F_109 ( int , V_26 -> V_102 + V_178 , V_102 ) ;
V_170 += V_178 ;
V_172 = F_109 ( int , V_168 , V_102 ) ;
V_167 = F_113 ( V_26 , 0 , V_134 , V_169 , V_172 ) ;
V_102 -= V_172 ;
V_169 += V_172 ;
if ( V_167 || ! V_102 )
goto V_179;
V_172 = F_109 ( int , sizeof( V_175 ) , V_102 ) ;
V_167 = F_107 ( V_134 , ( void * ) & V_175 , V_169 , V_172 ) ;
V_102 -= V_172 ;
V_169 += V_172 ;
if ( V_167 || ! V_102 )
goto V_179;
}
V_167 = F_113 ( V_26 , V_168 , V_134 , V_169 , V_102 ) ;
V_179:
return V_167 ? V_167 : V_170 ;
}
static T_7 F_114 ( struct V_6 * V_7 ,
const struct V_133 * V_134 , unsigned long V_102 ,
int V_104 )
{
F_115 ( V_84 ) ;
struct V_25 * V_26 ;
T_7 V_167 = 0 ;
while ( V_102 ) {
if ( ! V_104 )
F_116 ( F_38 ( & V_7 -> V_19 ) , & V_84 ,
V_180 ) ;
V_26 = F_117 ( & V_7 -> V_19 . V_37 ) ;
if ( ! V_26 ) {
if ( V_104 ) {
V_167 = - V_181 ;
break;
}
if ( F_118 ( V_77 ) ) {
V_167 = - V_182 ;
break;
}
F_119 () ;
continue;
}
V_167 = F_106 ( V_7 , V_26 , V_134 , V_102 ) ;
F_36 ( V_26 ) ;
break;
}
if ( ! V_104 )
F_120 ( F_38 ( & V_7 -> V_19 ) , & V_84 ) ;
return V_167 ;
}
static T_7 F_121 ( struct V_159 * V_160 , const struct V_133 * V_134 ,
unsigned long V_136 , T_8 V_161 )
{
struct V_5 * V_5 = V_160 -> V_162 ;
struct V_6 * V_7 = V_5 -> V_20 ;
T_7 V_102 , V_167 = 0 ;
V_102 = F_105 ( V_134 , V_136 ) ;
if ( V_102 < 0 ) {
V_167 = - V_10 ;
goto V_12;
}
V_167 = F_114 ( V_7 , V_134 , V_102 , V_5 -> V_165 & V_166 ) ;
V_167 = F_109 ( T_7 , V_167 , V_102 ) ;
if ( V_167 > 0 )
V_160 -> V_183 = V_167 ;
V_12:
return V_167 ;
}
static struct V_1 * F_122 ( struct V_6 * V_7 )
{
struct V_1 * V_8 ;
F_5 () ;
V_8 = F_13 ( V_7 -> V_8 ) ;
if ( V_8 )
F_49 ( V_8 -> V_3 ) ;
return V_8 ;
}
static void F_123 ( struct V_1 * V_8 )
{
F_71 ( V_8 -> V_3 ) ;
}
static int F_124 ( struct V_5 * V_5 , unsigned int V_41 )
{
struct V_6 * V_7 = V_5 -> V_20 ;
struct V_1 * V_8 ;
int V_167 ;
V_8 = F_122 ( V_7 ) ;
if ( ! V_8 )
return - V_10 ;
if ( V_41 & V_184 )
V_167 = F_3 ( V_8 -> V_3 , V_5 , V_7 ) ;
else if ( V_41 & V_185 )
V_167 = F_12 ( V_7 ) ;
else
V_167 = - V_10 ;
F_123 ( V_8 ) ;
return V_167 ;
}
static int F_125 ( struct V_6 * V_7 , unsigned long V_186 )
{
struct V_1 * V_8 ;
T_3 V_34 ;
T_3 V_187 = 0 ;
V_8 = F_13 ( V_7 -> V_8 ) ;
if ( ! V_8 )
return - V_164 ;
V_34 = V_8 -> V_3 -> V_34 ;
if ( V_186 & V_188 ) {
V_187 = V_189 ;
if ( V_186 & ( V_190 | V_191 ) ) {
if ( V_186 & V_192 )
V_187 |= V_193 ;
if ( V_186 & V_190 )
V_187 |= V_194 ;
if ( V_186 & V_191 )
V_187 |= V_195 ;
}
if ( V_186 & V_196 )
V_187 |= V_197 ;
}
if ( V_187 & ( V_194 | V_195 | V_197 ) )
V_34 |= V_198 ;
else
V_34 &= ~ V_198 ;
V_8 -> V_43 = V_187 ;
V_8 -> V_199 = V_34 ;
F_126 ( V_8 -> V_3 ) ;
return 0 ;
}
static long F_127 ( struct V_5 * V_5 , unsigned int V_200 ,
unsigned long V_186 )
{
struct V_6 * V_7 = V_5 -> V_20 ;
struct V_1 * V_8 ;
void T_10 * V_201 = ( void T_10 * ) V_186 ;
struct V_202 T_10 * V_203 = V_201 ;
unsigned int T_10 * V_204 = V_201 ;
unsigned int V_205 ;
int T_10 * V_206 = V_201 ;
int V_207 ;
int V_167 ;
switch ( V_200 ) {
case V_208 :
if ( F_128 ( V_205 , & V_203 -> V_209 ) )
return - V_171 ;
V_167 = 0 ;
if ( ( V_205 & ~ ( V_42 | V_210 ) ) !=
( V_92 | V_93 ) )
V_167 = - V_10 ;
else
V_7 -> V_41 = V_205 ;
return V_167 ;
case V_211 :
F_8 () ;
V_8 = F_122 ( V_7 ) ;
if ( ! V_8 ) {
F_11 () ;
return - V_164 ;
}
V_167 = 0 ;
if ( F_129 ( & V_203 -> V_212 , V_8 -> V_3 -> V_213 , V_214 ) ||
F_130 ( V_7 -> V_41 , & V_203 -> V_209 ) )
V_167 = - V_171 ;
F_123 ( V_8 ) ;
F_11 () ;
return V_167 ;
case V_215 :
if ( F_128 ( V_205 , & V_203 -> V_209 ) )
return - V_171 ;
F_8 () ;
V_167 = F_124 ( V_5 , V_205 ) ;
F_11 () ;
return V_167 ;
case V_216 :
if ( F_130 ( V_93 | V_92 | V_42 |
V_210 , V_204 ) )
return - V_171 ;
return 0 ;
case V_217 :
if ( F_128 ( V_205 , V_204 ) )
return - V_171 ;
V_7 -> V_19 . V_218 = V_205 ;
return 0 ;
case V_219 :
V_207 = V_7 -> V_94 ;
if ( F_130 ( V_207 , V_206 ) )
return - V_171 ;
return 0 ;
case V_220 :
if ( F_128 ( V_207 , V_206 ) )
return - V_171 ;
if ( V_207 < ( int ) sizeof( struct V_95 ) )
return - V_10 ;
V_7 -> V_94 = V_207 ;
return 0 ;
case V_221 :
if ( V_186 & ~ ( V_188 | V_190 | V_191 |
V_192 | V_196 ) )
return - V_10 ;
F_8 () ;
V_167 = F_125 ( V_7 , V_186 ) ;
F_11 () ;
return V_167 ;
default:
return - V_10 ;
}
}
static long F_131 ( struct V_5 * V_5 , unsigned int V_200 ,
unsigned long V_186 )
{
return F_127 ( V_5 , V_200 , ( unsigned long ) F_132 ( V_186 ) ) ;
}
static int F_133 ( struct V_159 * V_160 , struct V_222 * V_69 ,
struct V_131 * V_132 , T_6 V_135 )
{
struct V_6 * V_7 = F_134 ( V_69 , struct V_6 , V_69 ) ;
return F_89 ( V_7 , V_132 , V_132 -> V_223 , V_135 , V_132 -> V_224 ,
V_132 -> V_225 & V_226 ) ;
}
static int F_135 ( struct V_159 * V_160 , struct V_222 * V_69 ,
struct V_131 * V_132 , T_6 V_135 ,
int V_41 )
{
struct V_6 * V_7 = F_134 ( V_69 , struct V_6 , V_69 ) ;
int V_167 ;
if ( V_41 & ~ ( V_226 | V_227 ) )
return - V_10 ;
V_167 = F_114 ( V_7 , V_132 -> V_223 , V_135 ,
V_41 & V_226 ) ;
if ( V_167 > V_135 ) {
V_132 -> V_225 |= V_227 ;
V_167 = V_41 & V_227 ? V_167 : V_135 ;
}
return V_167 ;
}
struct V_222 * F_136 ( struct V_5 * V_5 )
{
struct V_6 * V_7 ;
if ( V_5 -> V_228 != & V_229 )
return F_137 ( - V_10 ) ;
V_7 = V_5 -> V_20 ;
if ( ! V_7 )
return F_137 ( - V_230 ) ;
return & V_7 -> V_69 ;
}
static int F_138 ( struct V_231 * V_232 ,
unsigned long V_233 , void * V_234 )
{
struct V_2 * V_3 = F_139 ( V_234 ) ;
struct V_1 * V_8 ;
struct V_235 * V_236 ;
T_11 V_237 ;
int V_9 ;
if ( V_3 -> V_238 != & V_239 )
return V_240 ;
V_8 = F_4 ( V_3 ) ;
switch ( V_233 ) {
case V_241 :
V_9 = F_40 ( V_8 ) ;
if ( V_9 )
return F_140 ( V_9 ) ;
V_237 = F_141 ( F_142 ( V_242 ) , V_8 -> V_57 ) ;
V_236 = F_143 ( V_243 , & V_3 -> V_3 , V_237 ,
V_3 , L_2 , V_3 -> V_244 ) ;
if ( F_34 ( V_236 ) ) {
F_45 ( V_8 ) ;
return F_140 ( F_144 ( V_236 ) ) ;
}
break;
case V_245 :
V_237 = F_141 ( F_142 ( V_242 ) , V_8 -> V_57 ) ;
F_145 ( V_243 , V_237 ) ;
F_45 ( V_8 ) ;
break;
}
return V_240 ;
}
static int F_146 ( void )
{
int V_9 ;
V_9 = F_147 ( & V_242 , 0 ,
V_55 , L_3 ) ;
if ( V_9 )
goto V_246;
F_148 ( & V_247 , & V_229 ) ;
V_9 = F_149 ( & V_247 , V_242 , V_55 ) ;
if ( V_9 )
goto V_248;
V_243 = F_150 ( V_249 , L_3 ) ;
if ( F_34 ( V_243 ) ) {
V_9 = F_144 ( V_243 ) ;
goto V_250;
}
V_9 = F_151 ( & V_251 ) ;
if ( V_9 )
goto V_252;
V_9 = F_152 ( & V_239 ) ;
if ( V_9 )
goto V_253;
return 0 ;
V_253:
F_153 ( & V_251 ) ;
V_252:
F_154 ( V_243 ) ;
V_250:
F_155 ( & V_247 ) ;
V_248:
F_156 ( V_242 , V_55 ) ;
V_246:
return V_9 ;
}
static void F_157 ( void )
{
F_158 ( & V_239 ) ;
F_153 ( & V_251 ) ;
F_154 ( V_243 ) ;
F_155 ( & V_247 ) ;
F_156 ( V_242 , V_55 ) ;
}
