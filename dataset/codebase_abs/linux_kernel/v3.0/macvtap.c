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
static int F_30 ( struct V_34 * V_35 ,
struct V_8 * V_9 ,
struct V_36 * V_37 [] ,
struct V_36 * V_38 [] )
{
struct V_39 * V_40 ;
T_2 V_41 ;
int V_12 ;
V_12 = F_31 ( V_35 , V_9 , V_37 , V_38 ,
F_28 , F_22 ) ;
if ( V_12 )
goto V_16;
V_41 = F_32 ( F_33 ( V_42 ) , V_9 -> V_43 ) ;
V_40 = F_34 ( V_44 , & V_9 -> V_9 , V_41 ,
V_9 , L_1 , V_9 -> V_43 ) ;
if ( F_35 ( V_40 ) ) {
V_12 = F_36 ( V_40 ) ;
F_21 ( V_9 ) ;
}
V_16:
return V_12 ;
}
static void F_37 ( struct V_8 * V_9 ,
struct V_45 * V_46 )
{
F_38 ( V_44 ,
F_32 ( F_33 ( V_42 ) , V_9 -> V_43 ) ) ;
F_21 ( V_9 ) ;
F_39 ( V_9 , V_46 ) ;
}
static void F_40 ( struct V_8 * V_9 )
{
F_41 ( V_9 ) ;
V_9 -> V_27 = V_47 ;
}
static void F_42 ( struct V_48 * V_17 )
{
T_3 * V_49 ;
if ( ! F_43 ( V_17 ) ||
! F_44 ( V_50 , & V_17 -> V_51 -> V_52 ) )
return;
V_49 = F_26 ( V_17 ) ;
if ( V_49 && F_45 ( V_49 ) )
F_25 ( V_49 , V_53 | V_54 | V_55 ) ;
}
static int F_46 ( struct V_56 * V_56 , struct V_10 * V_10 )
{
struct V_34 * V_34 = V_57 -> V_58 -> V_59 ;
struct V_8 * V_9 = F_47 ( V_34 , F_48 ( V_56 ) ) ;
struct V_3 * V_4 ;
int V_12 ;
V_12 = - V_60 ;
if ( ! V_9 )
goto V_16;
V_12 = - V_61 ;
if ( V_9 -> V_62 != & V_63 )
goto V_16;
V_12 = - V_64 ;
V_4 = (struct V_3 * ) F_49 ( V_34 , V_65 , V_66 ,
& V_67 ) ;
if ( ! V_4 )
goto V_16;
V_4 -> V_48 . V_68 = & V_4 -> V_68 ;
F_50 ( & V_4 -> V_68 . V_69 ) ;
V_4 -> V_48 . type = V_70 ;
V_4 -> V_48 . V_71 = V_72 ;
V_4 -> V_48 . V_10 = V_10 ;
V_4 -> V_48 . V_73 = & V_74 ;
F_51 ( & V_4 -> V_48 , & V_4 -> V_17 ) ;
V_4 -> V_17 . V_75 = F_42 ;
V_4 -> V_52 = V_76 | V_77 | V_78 ;
V_4 -> V_79 = sizeof( struct V_80 ) ;
V_12 = F_4 ( V_9 , V_10 , V_4 ) ;
if ( V_12 )
F_13 ( & V_4 -> V_17 ) ;
V_16:
if ( V_9 )
F_52 ( V_9 ) ;
return V_12 ;
}
static int F_53 ( struct V_56 * V_56 , struct V_10 * V_10 )
{
struct V_3 * V_4 = V_10 -> V_18 ;
F_10 ( V_4 ) ;
return 0 ;
}
static unsigned int F_54 ( struct V_10 * V_10 , T_4 * V_69 )
{
struct V_3 * V_4 = V_10 -> V_18 ;
unsigned int V_81 = V_82 ;
if ( ! V_4 )
goto V_16;
V_81 = 0 ;
F_55 ( V_10 , & V_4 -> V_68 . V_69 , V_69 ) ;
if ( ! F_56 ( & V_4 -> V_17 . V_26 ) )
V_81 |= V_28 | V_29 ;
if ( F_43 ( & V_4 -> V_17 ) ||
( ! F_57 ( V_50 , & V_4 -> V_48 . V_52 ) &&
F_43 ( & V_4 -> V_17 ) ) )
V_81 |= V_53 | V_54 ;
V_16:
return V_81 ;
}
static inline struct V_19 * F_58 ( struct V_48 * V_17 , T_5 V_83 ,
T_5 V_84 , T_5 V_85 ,
int V_86 , int * V_12 )
{
struct V_19 * V_20 ;
if ( V_83 + V_84 < V_87 || ! V_85 )
V_85 = V_84 ;
V_20 = F_59 ( V_17 , V_83 + V_85 , V_84 - V_85 , V_86 ,
V_12 ) ;
if ( ! V_20 )
return NULL ;
F_60 ( V_20 , V_83 ) ;
F_61 ( V_20 , V_85 ) ;
V_20 -> V_88 = V_84 - V_85 ;
V_20 -> V_84 += V_84 - V_85 ;
return V_20 ;
}
static int F_62 ( struct V_19 * V_20 ,
struct V_80 * V_89 )
{
unsigned short V_90 = 0 ;
if ( V_89 -> V_90 != V_91 ) {
switch ( V_89 -> V_90 & ~ V_92 ) {
case V_93 :
V_90 = V_94 ;
break;
case V_95 :
V_90 = V_96 ;
break;
case V_97 :
V_90 = V_98 ;
break;
default:
return - V_61 ;
}
if ( V_89 -> V_90 & V_92 )
V_90 |= V_99 ;
if ( V_89 -> V_100 == 0 )
return - V_61 ;
}
if ( V_89 -> V_52 & V_101 ) {
if ( ! F_63 ( V_20 , V_89 -> V_102 ,
V_89 -> V_103 ) )
return - V_61 ;
}
if ( V_89 -> V_90 != V_91 ) {
F_64 ( V_20 ) -> V_100 = V_89 -> V_100 ;
F_64 ( V_20 ) -> V_90 = V_90 ;
F_64 ( V_20 ) -> V_90 |= V_104 ;
F_64 ( V_20 ) -> V_105 = 0 ;
}
return 0 ;
}
static int F_65 ( const struct V_19 * V_20 ,
struct V_80 * V_89 )
{
memset ( V_89 , 0 , sizeof( * V_89 ) ) ;
if ( F_66 ( V_20 ) ) {
struct V_106 * V_107 = F_64 ( V_20 ) ;
V_89 -> V_108 = F_67 ( V_20 ) ;
V_89 -> V_100 = V_107 -> V_100 ;
if ( V_107 -> V_90 & V_94 )
V_89 -> V_90 = V_93 ;
else if ( V_107 -> V_90 & V_96 )
V_89 -> V_90 = V_95 ;
else if ( V_107 -> V_90 & V_98 )
V_89 -> V_90 = V_97 ;
else
F_68 () ;
if ( V_107 -> V_90 & V_99 )
V_89 -> V_90 |= V_92 ;
} else
V_89 -> V_90 = V_91 ;
if ( V_20 -> V_109 == V_110 ) {
V_89 -> V_52 = V_101 ;
V_89 -> V_102 = F_69 ( V_20 ) ;
V_89 -> V_103 = V_20 -> V_103 ;
}
return 0 ;
}
static T_6 F_70 ( struct V_3 * V_4 ,
const struct V_111 * V_112 , T_5 V_113 ,
int V_86 )
{
struct V_19 * V_20 ;
struct V_1 * V_2 ;
T_5 V_84 = V_113 ;
int V_12 ;
struct V_80 V_89 = { 0 } ;
int V_114 = 0 ;
if ( V_4 -> V_52 & V_76 ) {
V_114 = V_4 -> V_79 ;
V_12 = - V_61 ;
if ( V_84 < V_114 )
goto V_12;
V_84 -= V_114 ;
V_12 = F_71 ( ( void * ) & V_89 , V_112 , 0 ,
sizeof( V_89 ) ) ;
if ( V_12 < 0 )
goto V_12;
if ( ( V_89 . V_52 & V_101 ) &&
V_89 . V_102 + V_89 . V_103 + 2 >
V_89 . V_108 )
V_89 . V_108 = V_89 . V_102 +
V_89 . V_103 + 2 ;
V_12 = - V_61 ;
if ( V_89 . V_108 > V_84 )
goto V_12;
}
V_12 = - V_61 ;
if ( F_19 ( V_84 < V_33 ) )
goto V_12;
V_20 = F_58 ( & V_4 -> V_17 , V_115 , V_84 , V_89 . V_108 ,
V_86 , & V_12 ) ;
if ( ! V_20 )
goto V_12;
V_12 = F_72 ( V_20 , 0 , V_112 , V_114 , V_84 ) ;
if ( V_12 )
goto V_116;
F_73 ( V_20 , V_33 ) ;
F_74 ( V_20 ) ;
V_20 -> V_117 = F_75 ( V_20 ) -> V_118 ;
if ( V_114 ) {
V_12 = F_62 ( V_20 , & V_89 ) ;
if ( V_12 )
goto V_116;
}
F_76 () ;
V_2 = F_77 ( V_4 -> V_2 ) ;
if ( V_2 )
F_78 ( V_20 , V_2 -> V_9 ) ;
else
F_27 ( V_20 ) ;
F_79 () ;
return V_113 ;
V_116:
F_27 ( V_20 ) ;
V_12:
F_76 () ;
V_2 = F_77 ( V_4 -> V_2 ) ;
if ( V_2 )
V_2 -> V_9 -> V_119 . V_120 ++ ;
F_79 () ;
return V_12 ;
}
static T_6 F_80 ( struct V_121 * V_122 , const struct V_111 * V_112 ,
unsigned long V_113 , T_7 V_123 )
{
struct V_10 * V_10 = V_122 -> V_124 ;
T_6 V_125 = - V_126 ;
struct V_3 * V_4 = V_10 -> V_18 ;
V_125 = F_70 ( V_4 , V_112 , F_81 ( V_112 , V_113 ) ,
V_10 -> V_127 & V_128 ) ;
return V_125 ;
}
static T_6 F_82 ( struct V_3 * V_4 ,
const struct V_19 * V_20 ,
const struct V_111 * V_112 , int V_84 )
{
struct V_1 * V_2 ;
int V_129 ;
int V_114 = 0 ;
if ( V_4 -> V_52 & V_76 ) {
struct V_80 V_89 ;
V_114 = V_4 -> V_79 ;
if ( ( V_84 -= V_114 ) < 0 )
return - V_61 ;
V_129 = F_65 ( V_20 , & V_89 ) ;
if ( V_129 )
return V_129 ;
if ( F_83 ( V_112 , ( void * ) & V_89 , 0 , sizeof( V_89 ) ) )
return - V_130 ;
}
V_84 = F_84 ( int , V_20 -> V_84 , V_84 ) ;
V_129 = F_85 ( V_20 , 0 , V_112 , V_114 , V_84 ) ;
F_76 () ;
V_2 = F_77 ( V_4 -> V_2 ) ;
if ( V_2 )
F_86 ( V_2 , V_84 , V_129 == 0 , 0 ) ;
F_79 () ;
return V_129 ? V_129 : ( V_84 + V_114 ) ;
}
static T_6 F_87 ( struct V_3 * V_4 , struct V_121 * V_122 ,
const struct V_111 * V_112 , unsigned long V_84 ,
int V_86 )
{
F_88 ( V_69 , V_57 ) ;
struct V_19 * V_20 ;
T_6 V_129 = 0 ;
F_89 ( F_26 ( & V_4 -> V_17 ) , & V_69 ) ;
while ( V_84 ) {
V_57 -> V_71 = V_131 ;
V_20 = F_90 ( & V_4 -> V_17 . V_26 ) ;
if ( ! V_20 ) {
if ( V_86 ) {
V_129 = - V_132 ;
break;
}
if ( F_91 ( V_57 ) ) {
V_129 = - V_133 ;
break;
}
F_92 () ;
continue;
}
V_129 = F_82 ( V_4 , V_20 , V_112 , V_84 ) ;
F_27 ( V_20 ) ;
break;
}
V_57 -> V_71 = V_134 ;
F_93 ( F_26 ( & V_4 -> V_17 ) , & V_69 ) ;
return V_129 ;
}
static T_6 F_94 ( struct V_121 * V_122 , const struct V_111 * V_112 ,
unsigned long V_113 , T_7 V_123 )
{
struct V_10 * V_10 = V_122 -> V_124 ;
struct V_3 * V_4 = V_10 -> V_18 ;
T_6 V_84 , V_129 = 0 ;
V_84 = F_81 ( V_112 , V_113 ) ;
if ( V_84 < 0 ) {
V_129 = - V_61 ;
goto V_16;
}
V_129 = F_87 ( V_4 , V_122 , V_112 , V_84 , V_10 -> V_127 & V_128 ) ;
V_129 = F_84 ( T_6 , V_129 , V_84 ) ;
V_16:
return V_129 ;
}
static long F_95 ( struct V_10 * V_10 , unsigned int V_135 ,
unsigned long V_136 )
{
struct V_3 * V_4 = V_10 -> V_18 ;
struct V_1 * V_2 ;
void T_8 * V_137 = ( void T_8 * ) V_136 ;
struct V_138 T_8 * V_139 = V_137 ;
unsigned int T_8 * V_140 = V_137 ;
unsigned int V_141 ;
int T_8 * V_142 = V_137 ;
int V_143 ;
int V_129 ;
switch ( V_135 ) {
case V_144 :
if ( F_96 ( V_141 , & V_139 -> V_145 ) )
return - V_130 ;
V_129 = 0 ;
if ( ( V_141 & ~ V_76 ) != ( V_77 | V_78 ) )
V_129 = - V_61 ;
else
V_4 -> V_52 = V_141 ;
return V_129 ;
case V_146 :
F_76 () ;
V_2 = F_77 ( V_4 -> V_2 ) ;
if ( V_2 )
F_97 ( V_2 -> V_9 ) ;
F_79 () ;
if ( ! V_2 )
return - V_126 ;
V_129 = 0 ;
if ( F_98 ( & V_139 -> V_147 , V_2 -> V_9 -> V_148 , V_149 ) ||
F_99 ( V_4 -> V_52 , & V_139 -> V_145 ) )
V_129 = - V_130 ;
F_52 ( V_2 -> V_9 ) ;
return V_129 ;
case V_150 :
if ( F_99 ( V_78 | V_77 | V_76 , V_140 ) )
return - V_130 ;
return 0 ;
case V_151 :
if ( F_96 ( V_141 , V_140 ) )
return - V_130 ;
V_4 -> V_17 . V_152 = V_141 ;
return 0 ;
case V_153 :
V_143 = V_4 -> V_79 ;
if ( F_99 ( V_143 , V_142 ) )
return - V_130 ;
return 0 ;
case V_154 :
if ( F_96 ( V_143 , V_142 ) )
return - V_130 ;
if ( V_143 < ( int ) sizeof( struct V_80 ) )
return - V_61 ;
V_4 -> V_79 = V_143 ;
return 0 ;
case V_155 :
if ( V_136 & ~ ( V_156 | V_157 | V_158 |
V_159 | V_160 ) )
return - V_61 ;
if ( ! ( V_4 -> V_52 & V_76 ) )
return - V_61 ;
return 0 ;
default:
return - V_61 ;
}
}
static long F_100 ( struct V_10 * V_10 , unsigned int V_135 ,
unsigned long V_136 )
{
return F_95 ( V_10 , V_135 , ( unsigned long ) F_101 ( V_136 ) ) ;
}
static int F_102 ( struct V_121 * V_122 , struct V_161 * V_48 ,
struct V_162 * V_163 , T_5 V_164 )
{
struct V_3 * V_4 = F_103 ( V_48 , struct V_3 , V_48 ) ;
return F_70 ( V_4 , V_163 -> V_165 , V_164 ,
V_163 -> V_166 & V_167 ) ;
}
static int F_104 ( struct V_121 * V_122 , struct V_161 * V_48 ,
struct V_162 * V_163 , T_5 V_164 ,
int V_52 )
{
struct V_3 * V_4 = F_103 ( V_48 , struct V_3 , V_48 ) ;
int V_129 ;
if ( V_52 & ~ ( V_167 | V_168 ) )
return - V_61 ;
V_129 = F_87 ( V_4 , V_122 , V_163 -> V_165 , V_164 ,
V_52 & V_167 ) ;
if ( V_129 > V_164 ) {
V_163 -> V_166 |= V_168 ;
V_129 = V_52 & V_168 ? V_129 : V_164 ;
}
return V_129 ;
}
struct V_161 * F_105 ( struct V_10 * V_10 )
{
struct V_3 * V_4 ;
if ( V_10 -> V_169 != & V_170 )
return F_106 ( - V_61 ) ;
V_4 = V_10 -> V_18 ;
if ( ! V_4 )
return F_106 ( - V_171 ) ;
return & V_4 -> V_48 ;
}
static int F_107 ( void )
{
int V_12 ;
V_12 = F_108 ( & V_42 , 0 ,
V_172 , L_2 ) ;
if ( V_12 )
goto V_173;
F_109 ( & V_174 , & V_170 ) ;
V_12 = F_110 ( & V_174 , V_42 , V_172 ) ;
if ( V_12 )
goto V_175;
V_44 = F_111 ( V_176 , L_2 ) ;
if ( F_35 ( V_44 ) ) {
V_12 = F_36 ( V_44 ) ;
goto V_177;
}
V_12 = F_112 ( & V_63 ) ;
if ( V_12 )
goto V_178;
return 0 ;
V_178:
F_113 ( V_44 ) ;
V_177:
F_114 ( & V_174 ) ;
V_175:
F_115 ( V_42 , V_172 ) ;
V_173:
return V_12 ;
}
static void F_116 ( void )
{
F_117 ( & V_63 ) ;
F_113 ( V_44 ) ;
F_114 ( & V_174 ) ;
F_115 ( V_42 , V_172 ) ;
}
