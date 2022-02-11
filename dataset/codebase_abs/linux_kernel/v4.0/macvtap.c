static inline T_1 F_1 ( struct V_1 * V_2 , T_2 V_3 )
{
return F_2 ( V_2 -> V_4 & V_5 , V_3 ) ;
}
static inline T_2 F_3 ( struct V_1 * V_2 , T_1 V_3 )
{
return F_4 ( V_2 -> V_4 & V_5 , V_3 ) ;
}
static struct V_6 * F_5 ( const struct V_7 * V_8 )
{
return F_6 ( V_8 -> V_9 ) ;
}
static int F_7 ( struct V_7 * V_8 , struct V_10 * V_10 ,
struct V_1 * V_2 )
{
struct V_6 * V_11 = F_8 ( V_8 ) ;
int V_12 = - V_13 ;
F_9 () ;
if ( V_2 -> V_14 )
goto V_15;
V_12 = 0 ;
F_10 ( V_11 -> V_16 [ V_11 -> V_17 ] , V_2 ) ;
V_2 -> V_18 = V_11 -> V_17 ;
V_2 -> V_14 = true ;
V_11 -> V_17 ++ ;
V_15:
return V_12 ;
}
static int F_11 ( struct V_7 * V_8 , struct V_10 * V_10 ,
struct V_1 * V_2 )
{
struct V_6 * V_11 = F_8 ( V_8 ) ;
if ( V_11 -> V_19 == V_20 )
return - V_21 ;
F_10 ( V_2 -> V_11 , V_11 ) ;
F_10 ( V_11 -> V_16 [ V_11 -> V_17 ] , V_2 ) ;
F_12 ( & V_2 -> V_22 ) ;
V_2 -> V_10 = V_10 ;
V_2 -> V_18 = V_11 -> V_17 ;
V_2 -> V_14 = true ;
V_10 -> V_23 = V_2 ;
F_13 ( & V_2 -> V_24 , & V_11 -> V_25 ) ;
V_11 -> V_17 ++ ;
V_11 -> V_19 ++ ;
return 0 ;
}
static int F_14 ( struct V_1 * V_2 )
{
struct V_6 * V_11 ;
struct V_1 * V_26 ;
F_9 () ;
if ( ! V_2 -> V_14 )
return - V_13 ;
V_11 = F_15 ( V_2 -> V_11 ) ;
if ( V_11 ) {
int V_27 = V_2 -> V_18 ;
F_16 ( V_27 >= V_11 -> V_17 ) ;
V_26 = F_15 ( V_11 -> V_16 [ V_11 -> V_17 - 1 ] ) ;
V_26 -> V_18 = V_27 ;
F_10 ( V_11 -> V_16 [ V_27 ] , V_26 ) ;
F_17 ( V_11 -> V_16 [ V_11 -> V_17 - 1 ] , NULL ) ;
V_2 -> V_14 = false ;
V_11 -> V_17 -- ;
}
return 0 ;
}
static void F_18 ( struct V_1 * V_2 )
{
struct V_6 * V_11 ;
F_19 () ;
V_11 = F_15 ( V_2 -> V_11 ) ;
if ( V_11 ) {
if ( V_2 -> V_14 )
F_16 ( F_14 ( V_2 ) ) ;
V_11 -> V_19 -- ;
F_17 ( V_2 -> V_11 , NULL ) ;
F_20 ( & V_2 -> V_22 ) ;
F_21 ( & V_2 -> V_24 ) ;
}
F_22 () ;
F_23 () ;
F_20 ( & V_2 -> V_22 ) ;
}
static struct V_1 * F_24 ( struct V_7 * V_8 ,
struct V_28 * V_29 )
{
struct V_6 * V_11 = F_8 ( V_8 ) ;
struct V_1 * V_30 = NULL ;
int V_17 = F_25 ( V_11 -> V_17 ) ;
T_3 V_31 ;
if ( ! V_17 )
goto V_15;
V_31 = F_26 ( V_29 ) ;
if ( V_31 ) {
V_30 = F_6 ( V_11 -> V_16 [ V_31 % V_17 ] ) ;
goto V_15;
}
if ( F_27 ( F_28 ( V_29 ) ) ) {
V_31 = F_29 ( V_29 ) ;
while ( F_30 ( V_31 >= V_17 ) )
V_31 -= V_17 ;
V_30 = F_6 ( V_11 -> V_16 [ V_31 ] ) ;
goto V_15;
}
V_30 = F_6 ( V_11 -> V_16 [ 0 ] ) ;
V_15:
return V_30 ;
}
static void F_31 ( struct V_7 * V_8 )
{
struct V_6 * V_11 = F_8 ( V_8 ) ;
struct V_1 * V_2 , * V_32 , * V_33 [ V_20 ] ;
int V_34 , V_35 = 0 ;
F_9 () ;
F_32 (q, tmp, &vlan->queue_list, next) {
F_21 ( & V_2 -> V_24 ) ;
V_33 [ V_35 ++ ] = V_2 ;
F_17 ( V_2 -> V_11 , NULL ) ;
if ( V_2 -> V_14 )
V_11 -> V_17 -- ;
V_11 -> V_19 -- ;
}
for ( V_34 = 0 ; V_34 < V_11 -> V_17 ; V_34 ++ )
F_17 ( V_11 -> V_16 [ V_34 ] , NULL ) ;
F_16 ( V_11 -> V_17 ) ;
F_16 ( V_11 -> V_19 ) ;
V_11 -> V_17 = V_20 ;
for ( -- V_35 ; V_35 >= 0 ; V_35 -- )
F_20 ( & V_33 [ V_35 ] -> V_22 ) ;
}
static T_4 F_33 ( struct V_28 * * V_36 )
{
struct V_28 * V_29 = * V_36 ;
struct V_7 * V_8 = V_29 -> V_8 ;
struct V_6 * V_11 ;
struct V_1 * V_2 ;
T_5 V_37 = V_38 ;
V_11 = F_5 ( V_8 ) ;
if ( ! V_11 )
return V_39 ;
V_2 = F_24 ( V_8 , V_29 ) ;
if ( ! V_2 )
return V_39 ;
if ( F_34 ( & V_2 -> V_22 . V_40 ) >= V_8 -> V_41 )
goto V_42;
F_35 ( V_29 , V_43 ) ;
if ( V_2 -> V_4 & V_44 )
V_37 |= V_11 -> V_45 ;
if ( F_36 ( V_8 , V_29 , V_37 ) ) {
struct V_28 * V_46 = F_37 ( V_29 , V_37 , false ) ;
if ( F_38 ( V_46 ) )
goto V_42;
if ( ! V_46 ) {
F_39 ( & V_2 -> V_22 . V_40 , V_29 ) ;
goto V_47;
}
F_40 ( V_29 ) ;
while ( V_46 ) {
struct V_28 * V_48 = V_46 -> V_24 ;
V_46 -> V_24 = NULL ;
F_39 ( & V_2 -> V_22 . V_40 , V_46 ) ;
V_46 = V_48 ;
}
} else {
if ( V_29 -> V_49 == V_50 &&
! ( V_37 & V_51 ) &&
F_41 ( V_29 ) )
goto V_42;
F_39 ( & V_2 -> V_22 . V_40 , V_29 ) ;
}
V_47:
F_42 ( F_43 ( & V_2 -> V_22 ) , V_52 | V_53 | V_54 ) ;
return V_55 ;
V_42:
F_44 ( V_11 , 0 , 0 , 0 ) ;
F_40 ( V_29 ) ;
return V_55 ;
}
static int F_45 ( struct V_6 * V_11 )
{
int V_56 = - V_57 ;
F_46 ( & V_58 ) ;
V_56 = F_47 ( & V_59 , V_11 , 1 , V_60 , V_61 ) ;
if ( V_56 >= 0 ) {
V_11 -> V_62 = V_56 ;
} else if ( V_56 == - V_63 ) {
F_48 ( V_64 L_1 ) ;
V_56 = - V_13 ;
}
F_49 ( & V_58 ) ;
return V_56 < 0 ? V_56 : 0 ;
}
static void F_50 ( struct V_6 * V_11 )
{
F_46 ( & V_58 ) ;
if ( V_11 -> V_62 ) {
F_51 ( & V_59 , V_11 -> V_62 ) ;
V_11 -> V_62 = 0 ;
}
F_49 ( & V_58 ) ;
}
static struct V_7 * F_52 ( int V_62 )
{
struct V_7 * V_8 = NULL ;
struct V_6 * V_11 ;
F_46 ( & V_58 ) ;
V_11 = F_53 ( & V_59 , V_62 ) ;
if ( V_11 ) {
V_8 = V_11 -> V_8 ;
F_54 ( V_8 ) ;
}
F_49 ( & V_58 ) ;
return V_8 ;
}
static int F_55 ( struct V_65 * V_66 ,
struct V_7 * V_8 ,
struct V_67 * V_68 [] ,
struct V_67 * V_69 [] )
{
struct V_6 * V_11 = F_8 ( V_8 ) ;
int V_12 ;
F_56 ( & V_11 -> V_25 ) ;
V_11 -> V_45 = V_70 ;
V_12 = F_57 ( V_8 , F_33 , V_11 ) ;
if ( V_12 )
return V_12 ;
return F_58 ( V_66 , V_8 , V_68 , V_69 ) ;
}
static void F_59 ( struct V_7 * V_8 ,
struct V_71 * V_72 )
{
F_60 ( V_8 ) ;
F_31 ( V_8 ) ;
F_61 ( V_8 , V_72 ) ;
}
static void F_62 ( struct V_7 * V_8 )
{
F_63 ( V_8 ) ;
V_8 -> V_41 = V_73 ;
}
static void F_64 ( struct V_74 * V_22 )
{
T_6 * V_75 ;
if ( ! F_65 ( V_22 ) ||
! F_66 ( V_76 , & V_22 -> V_77 -> V_4 ) )
return;
V_75 = F_43 ( V_22 ) ;
if ( V_75 && F_67 ( V_75 ) )
F_42 ( V_75 , V_78 | V_79 | V_80 ) ;
}
static void F_68 ( struct V_74 * V_22 )
{
F_69 ( & V_22 -> V_40 ) ;
}
static int F_70 ( struct V_81 * V_81 , struct V_10 * V_10 )
{
struct V_65 * V_65 = V_82 -> V_83 -> V_84 ;
struct V_7 * V_8 ;
struct V_1 * V_2 ;
int V_12 = - V_85 ;
F_19 () ;
V_8 = F_52 ( F_71 ( V_81 ) ) ;
if ( ! V_8 )
goto V_15;
V_12 = - V_57 ;
V_2 = (struct V_1 * ) F_72 ( V_65 , V_86 , V_61 ,
& V_87 ) ;
if ( ! V_2 )
goto V_15;
F_17 ( V_2 -> V_74 . V_88 , & V_2 -> V_88 ) ;
F_73 ( & V_2 -> V_88 . V_89 ) ;
V_2 -> V_74 . type = V_90 ;
V_2 -> V_74 . V_91 = V_92 ;
V_2 -> V_74 . V_10 = V_10 ;
V_2 -> V_74 . V_93 = & V_94 ;
F_74 ( & V_2 -> V_74 , & V_2 -> V_22 ) ;
V_2 -> V_22 . V_95 = F_64 ;
V_2 -> V_22 . V_96 = F_68 ;
V_2 -> V_4 = V_44 | V_97 | V_98 ;
V_2 -> V_99 = sizeof( struct V_100 ) ;
if ( ( V_8 -> V_37 & V_101 ) && ( V_8 -> V_37 & V_102 ) )
F_75 ( & V_2 -> V_22 , V_103 ) ;
V_12 = F_11 ( V_8 , V_10 , V_2 ) ;
if ( V_12 )
F_20 ( & V_2 -> V_22 ) ;
V_15:
if ( V_8 )
F_76 ( V_8 ) ;
F_22 () ;
return V_12 ;
}
static int F_77 ( struct V_81 * V_81 , struct V_10 * V_10 )
{
struct V_1 * V_2 = V_10 -> V_23 ;
F_18 ( V_2 ) ;
return 0 ;
}
static unsigned int F_78 ( struct V_10 * V_10 , T_7 * V_89 )
{
struct V_1 * V_2 = V_10 -> V_23 ;
unsigned int V_104 = V_105 ;
if ( ! V_2 )
goto V_15;
V_104 = 0 ;
F_79 ( V_10 , & V_2 -> V_88 . V_89 , V_89 ) ;
if ( ! F_80 ( & V_2 -> V_22 . V_40 ) )
V_104 |= V_52 | V_53 ;
if ( F_65 ( & V_2 -> V_22 ) ||
( ! F_81 ( V_76 , & V_2 -> V_74 . V_4 ) &&
F_65 ( & V_2 -> V_22 ) ) )
V_104 |= V_78 | V_79 ;
V_15:
return V_104 ;
}
static inline struct V_28 * F_82 ( struct V_74 * V_22 , T_8 V_106 ,
T_8 V_107 , T_8 V_108 ,
int V_109 , int * V_12 )
{
struct V_28 * V_29 ;
if ( V_106 + V_107 < V_110 || ! V_108 )
V_108 = V_107 ;
V_29 = F_83 ( V_22 , V_106 + V_108 , V_107 - V_108 , V_109 ,
V_12 , 0 ) ;
if ( ! V_29 )
return NULL ;
F_84 ( V_29 , V_106 ) ;
F_85 ( V_29 , V_108 ) ;
V_29 -> V_111 = V_107 - V_108 ;
V_29 -> V_107 += V_107 - V_108 ;
return V_29 ;
}
static int F_86 ( struct V_1 * V_2 ,
struct V_28 * V_29 ,
struct V_100 * V_112 )
{
unsigned short V_113 = 0 ;
if ( V_112 -> V_113 != V_114 ) {
switch ( V_112 -> V_113 & ~ V_115 ) {
case V_116 :
V_113 = V_117 ;
break;
case V_118 :
V_113 = V_119 ;
break;
case V_120 :
V_113 = V_121 ;
break;
default:
return - V_13 ;
}
if ( V_112 -> V_113 & V_115 )
V_113 |= V_122 ;
if ( V_112 -> V_123 == 0 )
return - V_13 ;
}
if ( V_112 -> V_4 & V_124 ) {
if ( ! F_87 ( V_29 , F_1 ( V_2 , V_112 -> V_125 ) ,
F_1 ( V_2 , V_112 -> V_126 ) ) )
return - V_13 ;
}
if ( V_112 -> V_113 != V_114 ) {
F_88 ( V_29 ) -> V_123 = F_1 ( V_2 , V_112 -> V_123 ) ;
F_88 ( V_29 ) -> V_113 = V_113 ;
F_88 ( V_29 ) -> V_113 |= V_127 ;
F_88 ( V_29 ) -> V_128 = 0 ;
}
return 0 ;
}
static void F_89 ( struct V_1 * V_2 ,
const struct V_28 * V_29 ,
struct V_100 * V_112 )
{
memset ( V_112 , 0 , sizeof( * V_112 ) ) ;
if ( F_90 ( V_29 ) ) {
struct V_129 * V_130 = F_88 ( V_29 ) ;
V_112 -> V_131 = F_3 ( V_2 , F_91 ( V_29 ) ) ;
V_112 -> V_123 = F_3 ( V_2 , V_130 -> V_123 ) ;
if ( V_130 -> V_113 & V_117 )
V_112 -> V_113 = V_116 ;
else if ( V_130 -> V_113 & V_119 )
V_112 -> V_113 = V_118 ;
else if ( V_130 -> V_113 & V_121 )
V_112 -> V_113 = V_120 ;
else
F_92 () ;
if ( V_130 -> V_113 & V_122 )
V_112 -> V_113 |= V_115 ;
} else
V_112 -> V_113 = V_114 ;
if ( V_29 -> V_49 == V_50 ) {
V_112 -> V_4 = V_124 ;
if ( F_93 ( V_29 ) )
V_112 -> V_125 = F_3 ( V_2 ,
F_94 ( V_29 ) + V_132 ) ;
else
V_112 -> V_125 = F_3 ( V_2 ,
F_94 ( V_29 ) ) ;
V_112 -> V_126 = F_3 ( V_2 , V_29 -> V_126 ) ;
} else if ( V_29 -> V_49 == V_133 ) {
V_112 -> V_4 = V_134 ;
}
}
static T_9 F_95 ( struct V_1 * V_2 , struct V_135 * V_136 ,
struct V_137 * V_138 , int V_109 )
{
int V_139 = F_96 ( V_140 ) ;
struct V_28 * V_29 ;
struct V_6 * V_11 ;
unsigned long V_141 = F_97 ( V_138 ) ;
unsigned long V_107 = V_141 ;
int V_12 ;
struct V_100 V_112 = { 0 } ;
int V_142 = 0 ;
int V_143 = 0 ;
bool V_144 = false ;
T_8 V_108 ;
T_9 V_145 ;
if ( V_2 -> V_4 & V_44 ) {
V_142 = V_2 -> V_99 ;
V_12 = - V_13 ;
if ( V_107 < V_142 )
goto V_12;
V_107 -= V_142 ;
V_12 = - V_146 ;
V_145 = F_98 ( & V_112 , sizeof( V_112 ) , V_138 ) ;
if ( V_145 != sizeof( V_112 ) )
goto V_12;
F_99 ( V_138 , V_142 - sizeof( V_112 ) ) ;
if ( ( V_112 . V_4 & V_124 ) &&
F_1 ( V_2 , V_112 . V_125 ) +
F_1 ( V_2 , V_112 . V_126 ) + 2 >
F_1 ( V_2 , V_112 . V_131 ) )
V_112 . V_131 = F_3 ( V_2 ,
F_1 ( V_2 , V_112 . V_125 ) +
F_1 ( V_2 , V_112 . V_126 ) + 2 ) ;
V_12 = - V_13 ;
if ( F_1 ( V_2 , V_112 . V_131 ) > V_107 )
goto V_12;
}
V_12 = - V_13 ;
if ( F_30 ( V_107 < V_43 ) )
goto V_12;
if ( V_136 && V_136 -> V_147 && F_100 ( & V_2 -> V_22 , V_103 ) ) {
struct V_137 V_34 ;
V_143 = V_112 . V_131 ?
F_1 ( V_2 , V_112 . V_131 ) : V_148 ;
if ( V_143 > V_139 )
V_143 = V_139 ;
V_108 = V_143 ;
V_34 = * V_138 ;
F_99 ( & V_34 , V_143 ) ;
if ( F_101 ( & V_34 , V_149 ) <= V_150 )
V_144 = true ;
}
if ( ! V_144 ) {
V_143 = V_107 ;
if ( F_1 ( V_2 , V_112 . V_131 ) > V_139 )
V_108 = V_139 ;
else
V_108 = F_1 ( V_2 , V_112 . V_131 ) ;
}
V_29 = F_82 ( & V_2 -> V_22 , V_140 , V_143 ,
V_108 , V_109 , & V_12 ) ;
if ( ! V_29 )
goto V_12;
if ( V_144 )
V_12 = F_102 ( V_29 , V_138 ) ;
else {
V_12 = F_103 ( V_29 , 0 , V_138 , V_107 ) ;
if ( ! V_12 && V_136 && V_136 -> V_147 ) {
struct V_151 * V_152 = V_136 -> V_147 ;
V_152 -> V_153 ( V_152 , false ) ;
}
}
if ( V_12 )
goto V_154;
F_104 ( V_29 , V_43 ) ;
F_105 ( V_29 ) ;
V_29 -> V_155 = F_106 ( V_29 ) -> V_156 ;
if ( V_142 ) {
V_12 = F_86 ( V_2 , V_29 , & V_112 ) ;
if ( V_12 )
goto V_154;
}
F_107 ( V_29 , V_43 ) ;
F_108 () ;
V_11 = F_6 ( V_2 -> V_11 ) ;
if ( V_144 ) {
F_88 ( V_29 ) -> V_157 = V_136 -> V_147 ;
F_88 ( V_29 ) -> V_158 |= V_159 ;
F_88 ( V_29 ) -> V_158 |= V_160 ;
}
if ( V_11 ) {
V_29 -> V_8 = V_11 -> V_8 ;
F_109 ( V_29 ) ;
} else {
F_40 ( V_29 ) ;
}
F_110 () ;
return V_141 ;
V_154:
F_40 ( V_29 ) ;
V_12:
F_108 () ;
V_11 = F_6 ( V_2 -> V_11 ) ;
if ( V_11 )
F_111 ( V_11 -> V_161 -> V_162 ) ;
F_110 () ;
return V_12 ;
}
static T_9 F_112 ( struct V_163 * V_164 , struct V_137 * V_138 )
{
struct V_10 * V_10 = V_164 -> V_165 ;
struct V_1 * V_2 = V_10 -> V_23 ;
return F_95 ( V_2 , NULL , V_138 , V_10 -> V_166 & V_167 ) ;
}
static T_9 F_113 ( struct V_1 * V_2 ,
const struct V_28 * V_29 ,
struct V_137 * V_168 )
{
int V_169 ;
int V_142 = 0 ;
int V_170 = 0 ;
int V_171 ;
if ( V_2 -> V_4 & V_44 ) {
struct V_100 V_112 ;
V_142 = V_2 -> V_99 ;
if ( F_97 ( V_168 ) < V_142 )
return - V_13 ;
F_89 ( V_2 , V_29 , & V_112 ) ;
if ( F_114 ( & V_112 , sizeof( V_112 ) , V_168 ) !=
sizeof( V_112 ) )
return - V_146 ;
F_99 ( V_168 , V_142 - sizeof( V_112 ) ) ;
}
V_171 = V_142 ;
V_171 += V_29 -> V_107 ;
if ( F_93 ( V_29 ) ) {
struct {
T_10 V_172 ;
T_10 V_173 ;
} V_174 ;
V_174 . V_172 = V_29 -> V_175 ;
V_174 . V_173 = F_115 ( F_116 ( V_29 ) ) ;
V_170 = F_117 ( struct V_176 , V_172 ) ;
V_171 += V_132 ;
V_169 = F_118 ( V_29 , 0 , V_168 , V_170 ) ;
if ( V_169 || ! F_97 ( V_168 ) )
goto V_177;
V_169 = F_114 ( & V_174 , sizeof( V_174 ) , V_168 ) ;
if ( V_169 != sizeof( V_174 ) || ! F_97 ( V_168 ) )
goto V_177;
}
V_169 = F_118 ( V_29 , V_170 , V_168 ,
V_29 -> V_107 - V_170 ) ;
V_177:
return V_169 ? V_169 : V_171 ;
}
static T_9 F_119 ( struct V_1 * V_2 ,
struct V_137 * V_178 ,
int V_109 )
{
F_120 ( V_89 ) ;
struct V_28 * V_29 ;
T_9 V_169 = 0 ;
if ( ! F_97 ( V_178 ) )
return 0 ;
while ( 1 ) {
if ( ! V_109 )
F_121 ( F_43 ( & V_2 -> V_22 ) , & V_89 ,
V_179 ) ;
V_29 = F_122 ( & V_2 -> V_22 . V_40 ) ;
if ( V_29 )
break;
if ( V_109 ) {
V_169 = - V_180 ;
break;
}
if ( F_123 ( V_82 ) ) {
V_169 = - V_181 ;
break;
}
F_124 () ;
}
if ( V_29 ) {
V_169 = F_113 ( V_2 , V_29 , V_178 ) ;
if ( F_30 ( V_169 < 0 ) )
F_40 ( V_29 ) ;
else
F_125 ( V_29 ) ;
}
if ( ! V_109 )
F_126 ( F_43 ( & V_2 -> V_22 ) , & V_89 ) ;
return V_169 ;
}
static T_9 F_127 ( struct V_163 * V_164 , struct V_137 * V_178 )
{
struct V_10 * V_10 = V_164 -> V_165 ;
struct V_1 * V_2 = V_10 -> V_23 ;
T_9 V_107 = F_97 ( V_178 ) , V_169 ;
V_169 = F_119 ( V_2 , V_178 , V_10 -> V_166 & V_167 ) ;
V_169 = F_128 ( T_9 , V_169 , V_107 ) ;
if ( V_169 > 0 )
V_164 -> V_182 = V_169 ;
return V_169 ;
}
static struct V_6 * F_129 ( struct V_1 * V_2 )
{
struct V_6 * V_11 ;
F_9 () ;
V_11 = F_15 ( V_2 -> V_11 ) ;
if ( V_11 )
F_54 ( V_11 -> V_8 ) ;
return V_11 ;
}
static void F_130 ( struct V_6 * V_11 )
{
F_76 ( V_11 -> V_8 ) ;
}
static int F_131 ( struct V_10 * V_10 , unsigned int V_4 )
{
struct V_1 * V_2 = V_10 -> V_23 ;
struct V_6 * V_11 ;
int V_169 ;
V_11 = F_129 ( V_2 ) ;
if ( ! V_11 )
return - V_13 ;
if ( V_4 & V_183 )
V_169 = F_7 ( V_11 -> V_8 , V_10 , V_2 ) ;
else if ( V_4 & V_184 )
V_169 = F_14 ( V_2 ) ;
else
V_169 = - V_13 ;
F_130 ( V_11 ) ;
return V_169 ;
}
static int F_132 ( struct V_1 * V_2 , unsigned long V_185 )
{
struct V_6 * V_11 ;
T_5 V_37 ;
T_5 V_186 = 0 ;
V_11 = F_15 ( V_2 -> V_11 ) ;
if ( ! V_11 )
return - V_187 ;
V_37 = V_11 -> V_8 -> V_37 ;
if ( V_185 & V_188 ) {
V_186 = V_189 ;
if ( V_185 & ( V_190 | V_191 ) ) {
if ( V_185 & V_192 )
V_186 |= V_193 ;
if ( V_185 & V_190 )
V_186 |= V_194 ;
if ( V_185 & V_191 )
V_186 |= V_195 ;
}
if ( V_185 & V_196 )
V_186 |= V_197 ;
}
if ( V_186 & ( V_194 | V_195 | V_197 ) )
V_37 |= V_198 ;
else
V_37 &= ~ V_198 ;
V_11 -> V_45 = V_186 ;
V_11 -> V_199 = V_37 ;
F_133 ( V_11 -> V_8 ) ;
return 0 ;
}
static long F_134 ( struct V_10 * V_10 , unsigned int V_200 ,
unsigned long V_185 )
{
struct V_1 * V_2 = V_10 -> V_23 ;
struct V_6 * V_11 ;
void T_11 * V_201 = ( void T_11 * ) V_185 ;
struct V_202 T_11 * V_203 = V_201 ;
unsigned int T_11 * V_204 = V_201 ;
unsigned short V_205 ;
int T_11 * V_206 = V_201 ;
int V_207 ;
int V_169 ;
switch ( V_200 ) {
case V_208 :
if ( F_135 ( V_205 , & V_203 -> V_209 ) )
return - V_146 ;
V_169 = 0 ;
if ( ( V_205 & ~ V_210 ) != ( V_97 | V_98 ) )
V_169 = - V_13 ;
else
V_2 -> V_4 = ( V_2 -> V_4 & ~ V_210 ) | V_205 ;
return V_169 ;
case V_211 :
F_19 () ;
V_11 = F_129 ( V_2 ) ;
if ( ! V_11 ) {
F_22 () ;
return - V_187 ;
}
V_169 = 0 ;
V_205 = V_2 -> V_4 ;
if ( F_136 ( & V_203 -> V_212 , V_11 -> V_8 -> V_213 , V_214 ) ||
F_137 ( V_205 , & V_203 -> V_209 ) )
V_169 = - V_146 ;
F_130 ( V_11 ) ;
F_22 () ;
return V_169 ;
case V_215 :
if ( F_135 ( V_205 , & V_203 -> V_209 ) )
return - V_146 ;
F_19 () ;
V_169 = F_131 ( V_10 , V_205 ) ;
F_22 () ;
return V_169 ;
case V_216 :
if ( F_137 ( V_98 | V_97 | V_210 , V_204 ) )
return - V_146 ;
return 0 ;
case V_217 :
if ( F_135 ( V_205 , V_204 ) )
return - V_146 ;
V_2 -> V_22 . V_218 = V_205 ;
return 0 ;
case V_219 :
V_207 = V_2 -> V_99 ;
if ( F_137 ( V_207 , V_206 ) )
return - V_146 ;
return 0 ;
case V_220 :
if ( F_135 ( V_207 , V_206 ) )
return - V_146 ;
if ( V_207 < ( int ) sizeof( struct V_100 ) )
return - V_13 ;
V_2 -> V_99 = V_207 ;
return 0 ;
case V_221 :
V_207 = ! ! ( V_2 -> V_4 & V_5 ) ;
if ( F_137 ( V_207 , V_206 ) )
return - V_146 ;
return 0 ;
case V_222 :
if ( F_135 ( V_207 , V_206 ) )
return - V_146 ;
if ( V_207 )
V_2 -> V_4 |= V_5 ;
else
V_2 -> V_4 &= ~ V_5 ;
return 0 ;
case V_223 :
if ( V_185 & ~ ( V_188 | V_190 | V_191 |
V_192 | V_196 ) )
return - V_13 ;
F_19 () ;
V_169 = F_132 ( V_2 , V_185 ) ;
F_22 () ;
return V_169 ;
default:
return - V_13 ;
}
}
static long F_138 ( struct V_10 * V_10 , unsigned int V_200 ,
unsigned long V_185 )
{
return F_134 ( V_10 , V_200 , ( unsigned long ) F_139 ( V_185 ) ) ;
}
static int F_140 ( struct V_163 * V_164 , struct V_224 * V_74 ,
struct V_135 * V_136 , T_8 V_141 )
{
struct V_1 * V_2 = F_141 ( V_74 , struct V_1 , V_74 ) ;
return F_95 ( V_2 , V_136 , & V_136 -> V_225 , V_136 -> V_226 & V_227 ) ;
}
static int F_142 ( struct V_163 * V_164 , struct V_224 * V_74 ,
struct V_135 * V_136 , T_8 V_141 ,
int V_4 )
{
struct V_1 * V_2 = F_141 ( V_74 , struct V_1 , V_74 ) ;
int V_169 ;
if ( V_4 & ~ ( V_227 | V_228 ) )
return - V_13 ;
V_169 = F_119 ( V_2 , & V_136 -> V_225 , V_4 & V_227 ) ;
if ( V_169 > V_141 ) {
V_136 -> V_226 |= V_228 ;
V_169 = V_4 & V_228 ? V_169 : V_141 ;
}
return V_169 ;
}
struct V_224 * F_143 ( struct V_10 * V_10 )
{
struct V_1 * V_2 ;
if ( V_10 -> V_229 != & V_230 )
return F_144 ( - V_13 ) ;
V_2 = V_10 -> V_23 ;
if ( ! V_2 )
return F_144 ( - V_231 ) ;
return & V_2 -> V_74 ;
}
static int F_145 ( struct V_232 * V_233 ,
unsigned long V_234 , void * V_235 )
{
struct V_7 * V_8 = F_146 ( V_235 ) ;
struct V_6 * V_11 ;
struct V_236 * V_237 ;
T_12 V_238 ;
int V_12 ;
if ( V_8 -> V_239 != & V_240 )
return V_241 ;
V_11 = F_8 ( V_8 ) ;
switch ( V_234 ) {
case V_242 :
V_12 = F_45 ( V_11 ) ;
if ( V_12 )
return F_147 ( V_12 ) ;
V_238 = F_148 ( F_149 ( V_243 ) , V_11 -> V_62 ) ;
V_237 = F_150 ( V_244 , & V_8 -> V_8 , V_238 ,
V_8 , L_2 , V_8 -> V_245 ) ;
if ( F_38 ( V_237 ) ) {
F_50 ( V_11 ) ;
return F_147 ( F_151 ( V_237 ) ) ;
}
break;
case V_246 :
V_238 = F_148 ( F_149 ( V_243 ) , V_11 -> V_62 ) ;
F_152 ( V_244 , V_238 ) ;
F_50 ( V_11 ) ;
break;
}
return V_241 ;
}
static int F_153 ( void )
{
int V_12 ;
V_12 = F_154 ( & V_243 , 0 ,
V_60 , L_3 ) ;
if ( V_12 )
goto V_247;
F_155 ( & V_248 , & V_230 ) ;
V_12 = F_156 ( & V_248 , V_243 , V_60 ) ;
if ( V_12 )
goto V_249;
V_244 = F_157 ( V_250 , L_3 ) ;
if ( F_38 ( V_244 ) ) {
V_12 = F_151 ( V_244 ) ;
goto V_251;
}
V_12 = F_158 ( & V_252 ) ;
if ( V_12 )
goto V_253;
V_12 = F_159 ( & V_240 ) ;
if ( V_12 )
goto V_254;
return 0 ;
V_254:
F_160 ( & V_252 ) ;
V_253:
F_161 ( V_244 ) ;
V_251:
F_162 ( & V_248 ) ;
V_249:
F_163 ( V_243 , V_60 ) ;
V_247:
return V_12 ;
}
static void F_164 ( void )
{
F_165 ( & V_240 ) ;
F_160 ( & V_252 ) ;
F_161 ( V_244 ) ;
F_162 ( & V_248 ) ;
F_163 ( V_243 , V_60 ) ;
}
