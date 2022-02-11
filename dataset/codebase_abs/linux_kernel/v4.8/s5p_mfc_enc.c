static struct V_1 * F_1 ( struct V_2 * V_3 , unsigned int V_4 )
{
unsigned int V_5 ;
for ( V_5 = 0 ; V_5 < V_6 ; V_5 ++ ) {
if ( V_7 [ V_5 ] . V_8 == V_3 -> V_9 . V_10 . V_11 &&
V_7 [ V_5 ] . type == V_4 )
return & V_7 [ V_5 ] ;
}
return NULL ;
}
static const char * const * F_2 ( T_1 V_12 )
{
static const char * const V_13 [] = {
L_1 ,
L_2 ,
L_3 ,
NULL ,
} ;
static const char * const V_14 [] = {
L_1 ,
L_4 ,
L_5 ,
NULL ,
} ;
switch ( V_12 ) {
case V_15 :
return V_13 ;
case V_16 :
return V_14 ;
}
return NULL ;
}
static int F_3 ( struct V_17 * V_18 )
{
F_4 ( 2 , L_6 ,
V_18 -> V_19 , V_18 -> V_20 , V_18 -> V_21 ) ;
if ( V_18 -> V_21 == V_22 && V_18 -> V_20 >= 1 )
return 1 ;
if ( ( V_18 -> V_21 == V_23 ||
V_18 -> V_21 == V_24 ) &&
V_18 -> V_19 >= 1 && V_18 -> V_20 >= 1 )
return 1 ;
if ( V_18 -> V_21 == V_25 &&
V_18 -> V_20 >= 1 )
return 1 ;
F_4 ( 2 , L_7 ) ;
return 0 ;
}
static void F_5 ( struct V_17 * V_18 )
{
struct V_26 * V_27 ;
while ( ! F_6 ( & V_18 -> V_28 ) ) {
V_27 = F_7 ( ( & V_18 -> V_28 ) -> V_29 ,
struct V_26 , V_30 ) ;
F_8 ( & V_27 -> V_30 ) ;
V_18 -> V_31 -- ;
F_9 ( & V_27 -> V_30 , & V_18 -> V_32 ) ;
V_18 -> V_19 ++ ;
}
F_4 ( 2 , L_8 ,
V_18 -> V_19 , V_18 -> V_31 ) ;
F_10 ( & V_18 -> V_28 ) ;
V_18 -> V_31 = 0 ;
}
static int F_11 ( struct V_17 * V_18 )
{
struct V_33 * V_34 = V_18 -> V_34 ;
struct V_26 * V_35 ;
unsigned long V_36 ;
unsigned int V_37 ;
V_35 = F_7 ( V_18 -> V_38 . V_29 , struct V_26 , V_30 ) ;
V_36 = F_12 ( & V_35 -> V_39 -> V_40 , 0 ) ;
V_37 = F_13 ( & V_35 -> V_39 -> V_40 , 0 ) ;
F_14 ( V_34 -> V_41 , V_42 , V_18 , V_36 ,
V_37 ) ;
return 0 ;
}
static int F_15 ( struct V_17 * V_18 )
{
struct V_33 * V_34 = V_18 -> V_34 ;
struct V_43 * V_44 = & V_18 -> V_45 ;
struct V_26 * V_35 ;
unsigned int V_46 ;
if ( V_44 -> V_47 == V_48 ) {
if ( ! F_6 ( & V_18 -> V_38 ) ) {
V_35 = F_7 ( V_18 -> V_38 . V_29 ,
struct V_26 , V_30 ) ;
F_8 ( & V_35 -> V_30 ) ;
V_18 -> V_20 -- ;
F_16 ( & V_35 -> V_39 -> V_40 , 0 ,
F_14 ( V_34 -> V_41 , V_49 ,
V_34 ) ) ;
F_17 ( & V_35 -> V_39 -> V_40 ,
V_50 ) ;
}
}
if ( ! F_18 ( V_34 ) ) {
V_18 -> V_21 = V_23 ;
if ( F_3 ( V_18 ) )
F_19 ( V_18 ) ;
F_14 ( V_34 -> V_41 , V_51 , V_34 ) ;
} else {
V_46 = F_14 ( V_34 -> V_41 ,
V_52 , V_34 ) ;
if ( V_18 -> V_53 < V_46 )
V_18 -> V_53 = V_46 ;
V_18 -> V_21 = V_24 ;
}
return 0 ;
}
static int F_20 ( struct V_17 * V_18 )
{
struct V_33 * V_34 = V_18 -> V_34 ;
struct V_26 * V_35 ;
struct V_26 * V_54 ;
unsigned long V_55 , V_56 , V_36 ;
unsigned int V_37 ;
V_54 = F_7 ( V_18 -> V_32 . V_29 , struct V_26 , V_30 ) ;
V_55 = F_12 ( & V_54 -> V_39 -> V_40 , 0 ) ;
V_56 = F_12 ( & V_54 -> V_39 -> V_40 , 1 ) ;
F_14 ( V_34 -> V_41 , V_57 , V_18 ,
V_55 , V_56 ) ;
V_35 = F_7 ( V_18 -> V_38 . V_29 , struct V_26 , V_30 ) ;
V_36 = F_12 ( & V_35 -> V_39 -> V_40 , 0 ) ;
V_37 = F_13 ( & V_35 -> V_39 -> V_40 , 0 ) ;
F_14 ( V_34 -> V_41 , V_42 , V_18 , V_36 ,
V_37 ) ;
return 0 ;
}
static int F_21 ( struct V_17 * V_18 )
{
struct V_33 * V_34 = V_18 -> V_34 ;
struct V_26 * V_27 ;
unsigned long V_58 , V_59 ;
unsigned long V_60 , V_61 ;
int V_62 ;
unsigned int V_63 ;
V_62 = F_14 ( V_34 -> V_41 , V_64 , V_34 ) ;
V_63 = F_14 ( V_34 -> V_41 , V_49 , V_34 ) ;
F_4 ( 2 , L_9 , V_62 ) ;
F_4 ( 2 , L_10 , V_63 ) ;
F_4 ( 2 , L_11 ,
F_22 ( V_34 , V_65 ) ) ;
if ( V_62 >= 0 ) {
F_14 ( V_34 -> V_41 , V_66 , V_18 ,
& V_58 , & V_59 ) ;
F_23 (mb_entry, &ctx->src_queue, list) {
V_60 = F_12 (
& V_27 -> V_39 -> V_40 , 0 ) ;
V_61 = F_12 (
& V_27 -> V_39 -> V_40 , 1 ) ;
if ( ( V_58 == V_60 ) &&
( V_59 == V_61 ) ) {
F_8 ( & V_27 -> V_30 ) ;
V_18 -> V_19 -- ;
F_17 ( & V_27 -> V_39 -> V_40 ,
V_50 ) ;
break;
}
}
F_23 (mb_entry, &ctx->ref_queue, list) {
V_60 = F_12 (
& V_27 -> V_39 -> V_40 , 0 ) ;
V_61 = F_12 (
& V_27 -> V_39 -> V_40 , 1 ) ;
if ( ( V_58 == V_60 ) &&
( V_59 == V_61 ) ) {
F_8 ( & V_27 -> V_30 ) ;
V_18 -> V_31 -- ;
F_17 ( & V_27 -> V_39 -> V_40 ,
V_50 ) ;
break;
}
}
}
if ( ( V_18 -> V_19 > 0 ) && ( V_18 -> V_21 == V_23 ) ) {
V_27 = F_7 ( V_18 -> V_32 . V_29 , struct V_26 ,
V_30 ) ;
if ( V_27 -> V_67 & V_68 ) {
F_8 ( & V_27 -> V_30 ) ;
V_18 -> V_19 -- ;
F_9 ( & V_27 -> V_30 , & V_18 -> V_28 ) ;
V_18 -> V_31 ++ ;
}
}
F_4 ( 2 , L_8 ,
V_18 -> V_19 , V_18 -> V_31 ) ;
if ( ( V_18 -> V_20 > 0 ) && ( V_63 > 0 ) ) {
V_27 = F_7 ( V_18 -> V_38 . V_29 , struct V_26 ,
V_30 ) ;
F_8 ( & V_27 -> V_30 ) ;
V_18 -> V_20 -- ;
switch ( V_62 ) {
case V_69 :
V_27 -> V_39 -> V_67 |= V_70 ;
break;
case V_71 :
V_27 -> V_39 -> V_67 |= V_72 ;
break;
case V_73 :
V_27 -> V_39 -> V_67 |= V_74 ;
break;
}
F_16 ( & V_27 -> V_39 -> V_40 , 0 , V_63 ) ;
F_17 ( & V_27 -> V_39 -> V_40 , V_50 ) ;
}
if ( ( V_18 -> V_19 == 0 ) || ( V_18 -> V_20 == 0 ) )
F_24 ( V_18 ) ;
return 0 ;
}
static int F_25 ( struct V_75 * V_75 , void * V_76 ,
struct V_77 * V_78 )
{
struct V_33 * V_34 = F_26 ( V_75 ) ;
strncpy ( V_78 -> V_79 , V_80 , sizeof( V_78 -> V_79 ) - 1 ) ;
strncpy ( V_78 -> V_81 , V_34 -> V_82 -> V_83 , sizeof( V_78 -> V_81 ) - 1 ) ;
snprintf ( V_78 -> V_84 , sizeof( V_78 -> V_84 ) , L_12 ,
F_27 ( & V_34 -> V_85 -> V_34 ) ) ;
V_78 -> V_86 = V_87 | V_88 ;
V_78 -> V_89 = V_78 -> V_86 | V_90 ;
return 0 ;
}
static int F_28 ( struct V_75 * V_75 , struct V_91 * V_3 ,
bool V_92 )
{
struct V_33 * V_34 = F_26 ( V_75 ) ;
struct V_1 * V_9 ;
int V_5 , V_93 = 0 ;
for ( V_5 = 0 ; V_5 < F_29 ( V_7 ) ; ++ V_5 ) {
if ( V_92 && V_7 [ V_5 ] . type != V_94 )
continue;
else if ( ! V_92 && V_7 [ V_5 ] . type != V_95 )
continue;
else if ( ( V_34 -> V_96 -> V_97 & V_7 [ V_5 ] . V_98 ) == 0 )
continue;
if ( V_93 == V_3 -> V_99 ) {
V_9 = & V_7 [ V_5 ] ;
F_30 ( V_3 -> V_100 , V_9 -> V_83 ,
sizeof( V_3 -> V_100 ) ) ;
V_3 -> V_11 = V_9 -> V_8 ;
return 0 ;
}
++ V_93 ;
}
return - V_101 ;
}
static int F_31 ( struct V_75 * V_75 , void * V_102 ,
struct V_91 * V_3 )
{
return F_28 ( V_75 , V_3 , false ) ;
}
static int F_32 ( struct V_75 * V_75 , void * V_103 ,
struct V_91 * V_3 )
{
return F_28 ( V_75 , V_3 , true ) ;
}
static int F_33 ( struct V_75 * V_75 , void * V_76 , struct V_2 * V_3 )
{
struct V_17 * V_18 = F_34 ( V_76 ) ;
struct V_104 * V_105 = & V_3 -> V_9 . V_10 ;
F_4 ( 2 , L_13 , V_3 -> type , V_18 -> V_21 ) ;
if ( V_3 -> type == V_106 ) {
V_105 -> V_107 = 0 ;
V_105 -> V_108 = 0 ;
V_105 -> V_109 = V_110 ;
V_105 -> V_11 = V_18 -> V_111 -> V_8 ;
V_105 -> V_112 = V_18 -> V_111 -> V_112 ;
V_105 -> V_113 [ 0 ] . V_114 = V_18 -> V_115 ;
V_105 -> V_113 [ 0 ] . V_116 = V_18 -> V_115 ;
} else if ( V_3 -> type == V_117 ) {
V_105 -> V_107 = V_18 -> V_118 ;
V_105 -> V_108 = V_18 -> V_119 ;
V_105 -> V_109 = V_110 ;
V_105 -> V_11 = V_18 -> V_120 -> V_8 ;
V_105 -> V_112 = V_18 -> V_120 -> V_112 ;
V_105 -> V_113 [ 0 ] . V_114 = V_18 -> V_121 ;
V_105 -> V_113 [ 0 ] . V_116 = V_18 -> V_122 ;
V_105 -> V_113 [ 1 ] . V_114 = V_18 -> V_121 ;
V_105 -> V_113 [ 1 ] . V_116 = V_18 -> V_123 ;
} else {
F_35 ( L_14 ) ;
return - V_101 ;
}
return 0 ;
}
static int F_36 ( struct V_75 * V_75 , void * V_76 , struct V_2 * V_3 )
{
struct V_33 * V_34 = F_26 ( V_75 ) ;
struct V_1 * V_9 ;
struct V_104 * V_105 = & V_3 -> V_9 . V_10 ;
if ( V_3 -> type == V_106 ) {
V_9 = F_1 ( V_3 , V_95 ) ;
if ( ! V_9 ) {
F_35 ( L_15 ) ;
return - V_101 ;
}
if ( ( V_34 -> V_96 -> V_97 & V_9 -> V_98 ) == 0 ) {
F_35 ( L_16 ) ;
return - V_101 ;
}
V_105 -> V_113 [ 0 ] . V_114 =
V_105 -> V_113 [ 0 ] . V_116 ;
} else if ( V_3 -> type == V_117 ) {
V_9 = F_1 ( V_3 , V_94 ) ;
if ( ! V_9 ) {
F_35 ( L_15 ) ;
return - V_101 ;
}
if ( ( V_34 -> V_96 -> V_97 & V_9 -> V_98 ) == 0 ) {
F_35 ( L_16 ) ;
return - V_101 ;
}
F_37 ( & V_105 -> V_107 , 8 , 1920 , 1 ,
& V_105 -> V_108 , 4 , 1080 , 1 , 0 ) ;
} else {
F_35 ( L_14 ) ;
return - V_101 ;
}
return 0 ;
}
static int F_38 ( struct V_75 * V_75 , void * V_76 , struct V_2 * V_3 )
{
struct V_33 * V_34 = F_26 ( V_75 ) ;
struct V_17 * V_18 = F_34 ( V_76 ) ;
struct V_104 * V_105 = & V_3 -> V_9 . V_10 ;
int V_124 = 0 ;
V_124 = F_36 ( V_75 , V_76 , V_3 ) ;
if ( V_124 )
return V_124 ;
if ( V_18 -> V_125 . V_126 || V_18 -> V_127 . V_126 ) {
F_39 ( & V_34 -> V_128 , L_17 , V_129 ) ;
V_124 = - V_130 ;
goto V_92;
}
if ( V_3 -> type == V_106 ) {
V_18 -> V_111 = F_1 ( V_3 , V_95 ) ;
V_18 -> V_21 = V_131 ;
V_18 -> V_132 = V_18 -> V_111 -> V_132 ;
V_18 -> V_115 = V_105 -> V_113 [ 0 ] . V_116 ;
V_105 -> V_113 [ 0 ] . V_114 = 0 ;
V_18 -> V_133 = 0 ;
V_18 -> V_134 = V_135 ;
V_124 = F_40 ( V_34 , V_18 ) ;
} else if ( V_3 -> type == V_117 ) {
V_18 -> V_120 = F_1 ( V_3 , V_94 ) ;
V_18 -> V_118 = V_105 -> V_107 ;
V_18 -> V_119 = V_105 -> V_108 ;
F_4 ( 2 , L_18 , V_18 -> V_120 -> V_132 ) ;
F_4 ( 2 , L_19 ,
V_105 -> V_107 , V_105 -> V_108 ,
V_18 -> V_118 , V_18 -> V_119 ) ;
F_14 ( V_34 -> V_41 , V_136 , V_18 ) ;
V_105 -> V_113 [ 0 ] . V_116 = V_18 -> V_122 ;
V_105 -> V_113 [ 0 ] . V_114 = V_18 -> V_121 ;
V_105 -> V_113 [ 1 ] . V_116 = V_18 -> V_123 ;
V_105 -> V_113 [ 1 ] . V_114 = V_18 -> V_121 ;
V_18 -> V_137 = 0 ;
V_18 -> V_138 = V_135 ;
} else {
F_35 ( L_14 ) ;
V_124 = - V_101 ;
}
V_92:
F_41 () ;
return V_124 ;
}
static int F_42 ( struct V_75 * V_75 , void * V_76 ,
struct V_139 * V_140 )
{
struct V_33 * V_34 = F_26 ( V_75 ) ;
struct V_17 * V_18 = F_34 ( V_76 ) ;
int V_124 = 0 ;
if ( ( V_140 -> V_141 != V_142 ) &&
( V_140 -> V_141 != V_143 ) )
return - V_101 ;
if ( V_140 -> type == V_106 ) {
if ( V_140 -> V_144 == 0 ) {
F_4 ( 2 , L_20 ) ;
V_124 = F_43 ( & V_18 -> V_127 , V_140 ) ;
F_14 ( V_34 -> V_41 , V_145 ,
V_18 ) ;
V_18 -> V_134 = V_135 ;
return V_124 ;
}
if ( V_18 -> V_134 != V_135 ) {
F_35 ( L_21 ,
V_18 -> V_134 ) ;
return - V_101 ;
}
V_124 = F_43 ( & V_18 -> V_127 , V_140 ) ;
if ( V_124 != 0 ) {
F_35 ( L_22 ) ;
return V_124 ;
}
V_18 -> V_134 = V_146 ;
V_124 = F_14 ( V_18 -> V_34 -> V_41 ,
V_147 , V_18 ) ;
if ( V_124 ) {
F_35 ( L_23 ) ;
V_140 -> V_144 = 0 ;
V_124 = F_43 ( & V_18 -> V_127 , V_140 ) ;
return - V_148 ;
}
} else if ( V_140 -> type == V_117 ) {
if ( V_140 -> V_144 == 0 ) {
F_4 ( 2 , L_20 ) ;
V_124 = F_43 ( & V_18 -> V_125 , V_140 ) ;
F_14 ( V_34 -> V_41 , V_145 ,
V_18 ) ;
V_18 -> V_138 = V_135 ;
return V_124 ;
}
if ( V_18 -> V_138 != V_135 ) {
F_35 ( L_24 ,
V_18 -> V_138 ) ;
return - V_101 ;
}
if ( F_18 ( V_34 ) ) {
if ( V_18 -> V_53 &&
( V_140 -> V_144 < V_18 -> V_53 ) ) {
V_140 -> V_144 = V_18 -> V_53 ;
F_4 ( 2 , L_25 ,
V_18 -> V_53 ) ;
} else {
V_18 -> V_53 = V_140 -> V_144 ;
}
}
V_124 = F_43 ( & V_18 -> V_125 , V_140 ) ;
if ( V_124 != 0 ) {
F_35 ( L_26 ) ;
return V_124 ;
}
V_18 -> V_138 = V_146 ;
} else {
F_35 ( L_14 ) ;
return - V_101 ;
}
return V_124 ;
}
static int F_44 ( struct V_75 * V_75 , void * V_76 ,
struct V_149 * V_150 )
{
struct V_17 * V_18 = F_34 ( V_76 ) ;
int V_124 = 0 ;
if ( ( V_150 -> V_141 != V_142 ) &&
( V_150 -> V_141 != V_143 ) )
return - V_101 ;
if ( V_150 -> type == V_106 ) {
if ( V_18 -> V_21 != V_22 ) {
F_35 ( L_27 , V_18 -> V_21 ) ;
return - V_101 ;
}
V_124 = F_45 ( & V_18 -> V_127 , V_150 ) ;
if ( V_124 != 0 ) {
F_35 ( L_28 ) ;
return V_124 ;
}
V_150 -> V_151 . V_152 [ 0 ] . V_151 . V_153 += V_154 ;
} else if ( V_150 -> type == V_117 ) {
V_124 = F_45 ( & V_18 -> V_125 , V_150 ) ;
if ( V_124 != 0 ) {
F_35 ( L_29 ) ;
return V_124 ;
}
} else {
F_35 ( L_14 ) ;
return - V_101 ;
}
return V_124 ;
}
static int F_46 ( struct V_75 * V_75 , void * V_76 , struct V_149 * V_150 )
{
struct V_17 * V_18 = F_34 ( V_76 ) ;
if ( V_18 -> V_21 == V_155 ) {
F_35 ( L_30 ) ;
return - V_156 ;
}
if ( V_150 -> type == V_117 ) {
if ( V_18 -> V_21 == V_25 ) {
F_35 ( L_31 ) ;
return - V_156 ;
}
return F_47 ( & V_18 -> V_125 , V_150 ) ;
} else if ( V_150 -> type == V_106 ) {
return F_47 ( & V_18 -> V_127 , V_150 ) ;
}
return - V_101 ;
}
static int F_48 ( struct V_75 * V_75 , void * V_76 , struct V_149 * V_150 )
{
const struct V_157 V_158 = {
. type = V_159
} ;
struct V_17 * V_18 = F_34 ( V_76 ) ;
int V_124 ;
if ( V_18 -> V_21 == V_155 ) {
F_35 ( L_32 ) ;
return - V_156 ;
}
if ( V_150 -> type == V_117 ) {
V_124 = F_49 ( & V_18 -> V_125 , V_150 , V_75 -> V_160 & V_161 ) ;
} else if ( V_150 -> type == V_106 ) {
V_124 = F_49 ( & V_18 -> V_127 , V_150 , V_75 -> V_160 & V_161 ) ;
if ( V_124 == 0 && V_18 -> V_21 == V_162
&& F_6 ( & V_18 -> V_127 . V_163 ) )
F_50 ( & V_18 -> V_164 , & V_158 ) ;
} else {
V_124 = - V_101 ;
}
return V_124 ;
}
static int F_51 ( struct V_75 * V_75 , void * V_76 ,
struct V_165 * V_166 )
{
struct V_17 * V_18 = F_34 ( V_76 ) ;
if ( V_166 -> type == V_117 )
return F_52 ( & V_18 -> V_125 , V_166 ) ;
if ( V_166 -> type == V_106 )
return F_52 ( & V_18 -> V_127 , V_166 ) ;
return - V_101 ;
}
static int F_53 ( struct V_75 * V_75 , void * V_76 ,
enum V_167 type )
{
struct V_17 * V_18 = F_34 ( V_76 ) ;
if ( type == V_117 )
return F_54 ( & V_18 -> V_125 , type ) ;
else if ( type == V_106 )
return F_54 ( & V_18 -> V_127 , type ) ;
return - V_101 ;
}
static int F_55 ( struct V_75 * V_75 , void * V_76 ,
enum V_167 type )
{
struct V_17 * V_18 = F_34 ( V_76 ) ;
if ( type == V_117 )
return F_56 ( & V_18 -> V_125 , type ) ;
else if ( type == V_106 )
return F_56 ( & V_18 -> V_127 , type ) ;
return - V_101 ;
}
static inline int F_57 ( enum V_168 V_169 )
{
static unsigned int V_4 [ V_170 + 1 ] = {
10 ,
9 ,
11 ,
12 ,
13 ,
20 ,
21 ,
22 ,
30 ,
31 ,
32 ,
40 ,
} ;
return V_4 [ V_169 ] ;
}
static inline int F_58 ( enum V_171 V_169 )
{
static unsigned int V_4 [ V_172 + 1 ] = {
0 ,
9 ,
1 ,
2 ,
3 ,
7 ,
4 ,
5 ,
} ;
return V_4 [ V_169 ] ;
}
static inline int F_59 ( enum V_173 V_174 )
{
static unsigned int V_4 [ V_175 + 1 ] = {
0 ,
1 ,
2 ,
3 ,
4 ,
5 ,
6 ,
7 ,
8 ,
9 ,
10 ,
11 ,
12 ,
13 ,
14 ,
15 ,
16 ,
255 ,
} ;
return V_4 [ V_174 ] ;
}
static int F_60 ( struct V_176 * V_177 )
{
struct V_17 * V_18 = F_61 ( V_177 ) ;
struct V_33 * V_34 = V_18 -> V_34 ;
struct V_43 * V_44 = & V_18 -> V_45 ;
int V_124 = 0 ;
switch ( V_177 -> V_12 ) {
case V_178 :
V_44 -> V_179 = V_177 -> V_180 ;
break;
case V_181 :
V_44 -> V_182 = V_177 -> V_180 ;
break;
case V_183 :
V_44 -> V_184 = V_177 -> V_180 ;
break;
case V_185 :
V_44 -> V_186 = V_177 -> V_180 * 8 ;
break;
case V_187 :
V_44 -> V_188 = V_177 -> V_180 ;
break;
case V_189 :
V_44 -> V_190 = V_177 -> V_180 ;
break;
case V_191 :
V_44 -> V_192 = ( V_177 -> V_180 >> 16 ) & 0xff ;
V_44 -> V_193 = ( V_177 -> V_180 >> 8 ) & 0xff ;
V_44 -> V_194 = ( V_177 -> V_180 >> 0 ) & 0xff ;
break;
case V_195 :
V_44 -> V_196 = V_177 -> V_180 ;
break;
case V_197 :
V_44 -> V_198 = V_177 -> V_180 ;
break;
case V_199 :
V_44 -> V_200 = V_177 -> V_180 ;
break;
case V_16 :
V_18 -> V_201 = V_177 -> V_180 ;
break;
case V_202 :
V_18 -> V_201 =
V_203 ;
break;
case V_204 :
V_44 -> V_205 = V_177 -> V_180 ;
break;
case V_206 :
V_44 -> V_207 = V_177 -> V_180 ;
break;
case V_208 :
V_44 -> V_209 = V_177 -> V_180 ;
break;
case V_210 :
V_44 -> V_211 . V_212 . V_213 = V_177 -> V_180 ;
break;
case V_214 :
V_44 -> V_47 = V_177 -> V_180 ;
break;
case V_15 :
V_44 -> V_215 = V_177 -> V_180 ;
break;
case V_216 :
V_44 -> V_217 = V_177 -> V_180 ;
break;
case V_218 :
V_44 -> V_219 = V_177 -> V_180 ;
break;
case V_220 :
switch ( V_177 -> V_180 ) {
case V_221 :
V_44 -> V_211 . V_212 . V_222 =
V_223 ;
break;
case V_224 :
V_44 -> V_211 . V_212 . V_222 =
V_225 ;
break;
case V_226 :
V_44 -> V_211 . V_212 . V_222 =
V_227 ;
break;
case V_228 :
if ( F_18 ( V_34 ) )
V_44 -> V_211 . V_212 . V_222 =
V_229 ;
else
V_124 = - V_101 ;
break;
default:
V_124 = - V_101 ;
}
break;
case V_230 :
V_44 -> V_211 . V_212 . V_231 = V_177 -> V_180 ;
V_44 -> V_211 . V_212 . V_232 = F_57 ( V_177 -> V_180 ) ;
if ( V_44 -> V_211 . V_212 . V_232 < 0 ) {
F_35 ( L_33 ) ;
V_124 = V_44 -> V_211 . V_212 . V_232 ;
}
break;
case V_233 :
V_44 -> V_211 . V_234 . V_231 = V_177 -> V_180 ;
V_44 -> V_211 . V_234 . V_232 = F_58 ( V_177 -> V_180 ) ;
if ( V_44 -> V_211 . V_234 . V_232 < 0 ) {
F_35 ( L_33 ) ;
V_124 = V_44 -> V_211 . V_234 . V_232 ;
}
break;
case V_235 :
V_44 -> V_211 . V_212 . V_236 = V_177 -> V_180 ;
break;
case V_237 :
V_44 -> V_211 . V_212 . V_238 = V_177 -> V_180 ;
break;
case V_239 :
V_44 -> V_211 . V_212 . V_240 = V_177 -> V_180 ;
break;
case V_241 :
V_44 -> V_211 . V_212 . V_242 = V_177 -> V_180 ;
break;
case V_243 :
V_44 -> V_211 . V_212 . V_244 = V_177 -> V_180 ;
break;
case V_245 :
V_44 -> V_211 . V_212 . V_246 = V_177 -> V_180 ;
break;
case V_247 :
V_44 -> V_248 = V_177 -> V_180 ;
break;
case V_249 :
V_44 -> V_211 . V_212 . V_250 = V_177 -> V_180 ;
break;
case V_251 :
V_44 -> V_211 . V_212 . V_252 = V_177 -> V_180 ;
break;
case V_253 :
V_44 -> V_211 . V_212 . V_254 = V_177 -> V_180 ;
break;
case V_255 :
V_44 -> V_211 . V_212 . V_256 = V_177 -> V_180 ;
break;
case V_257 :
V_44 -> V_211 . V_212 . V_258 = V_177 -> V_180 ;
break;
case V_259 :
case V_260 :
V_44 -> V_211 . V_234 . V_250 = V_177 -> V_180 ;
break;
case V_261 :
case V_262 :
V_44 -> V_211 . V_234 . V_252 = V_177 -> V_180 ;
break;
case V_263 :
case V_264 :
V_44 -> V_211 . V_234 . V_254 = V_177 -> V_180 ;
break;
case V_265 :
case V_266 :
V_44 -> V_211 . V_234 . V_256 = V_177 -> V_180 ;
break;
case V_267 :
case V_268 :
V_44 -> V_211 . V_234 . V_258 = V_177 -> V_180 ;
break;
case V_269 :
V_44 -> V_211 . V_212 . V_270 = V_177 -> V_180 ;
break;
case V_271 :
V_44 -> V_211 . V_212 . V_272 = V_177 -> V_180 ;
break;
case V_273 :
V_44 -> V_211 . V_212 . V_274 = V_177 -> V_180 ;
break;
case V_275 :
V_44 -> V_211 . V_212 . V_276 = V_177 -> V_180 ;
break;
case V_277 :
V_44 -> V_211 . V_212 . V_278 = V_177 -> V_180 ;
break;
case V_279 :
V_44 -> V_211 . V_212 . F_59 = F_59 ( V_177 -> V_180 ) ;
break;
case V_280 :
V_44 -> V_211 . V_212 . V_281 = V_177 -> V_180 ;
break;
case V_282 :
V_44 -> V_211 . V_212 . V_283 = V_177 -> V_180 ;
break;
case V_284 :
V_44 -> V_211 . V_212 . V_285 = ! V_177 -> V_180 ;
break;
case V_286 :
V_44 -> V_211 . V_212 . V_287 = V_177 -> V_180 ;
break;
case V_288 :
switch ( V_177 -> V_180 ) {
case V_289 :
V_44 -> V_211 . V_234 . V_222 =
V_290 ;
break;
case V_291 :
V_44 -> V_211 . V_234 . V_222 =
V_292 ;
break;
default:
V_124 = - V_101 ;
}
break;
case V_293 :
V_44 -> V_211 . V_234 . V_294 = V_177 -> V_180 ;
break;
case V_295 :
V_44 -> V_211 . V_296 . V_297 = V_177 -> V_180 ;
break;
case V_298 :
V_44 -> V_211 . V_296 . V_299 = V_177 -> V_180 ;
break;
case V_300 :
V_44 -> V_211 . V_296 . V_301 = V_177 -> V_180 ;
break;
case V_302 :
V_44 -> V_211 . V_296 . V_303 = V_177 -> V_180 ;
break;
case V_304 :
V_44 -> V_211 . V_296 . V_305 = V_177 -> V_180 ;
break;
case V_306 :
V_44 -> V_211 . V_296 . V_307 = V_177 -> V_180 ;
break;
case V_308 :
V_44 -> V_211 . V_296 . V_309 = V_177 -> V_180 ;
break;
case V_310 :
V_44 -> V_211 . V_296 . V_252 = V_177 -> V_180 ;
break;
case V_311 :
V_44 -> V_211 . V_296 . V_254 = V_177 -> V_180 ;
break;
case V_312 :
V_44 -> V_211 . V_296 . V_250 = V_177 -> V_180 ;
break;
case V_313 :
V_44 -> V_211 . V_296 . V_256 = V_177 -> V_180 ;
break;
case V_314 :
V_44 -> V_211 . V_296 . V_222 = V_177 -> V_180 ;
break;
default:
F_39 ( & V_34 -> V_128 , L_34 ,
V_177 -> V_12 , V_177 -> V_180 ) ;
V_124 = - V_101 ;
}
return V_124 ;
}
static int F_62 ( struct V_176 * V_177 )
{
struct V_17 * V_18 = F_61 ( V_177 ) ;
struct V_33 * V_34 = V_18 -> V_34 ;
switch ( V_177 -> V_12 ) {
case V_315 :
if ( V_18 -> V_21 >= V_316 &&
V_18 -> V_21 < V_317 ) {
V_177 -> V_180 = V_18 -> V_53 ;
break;
} else if ( V_18 -> V_21 != V_131 ) {
F_39 ( & V_34 -> V_128 , L_35 ) ;
return - V_101 ;
}
F_63 ( V_18 ,
V_318 , 0 ) ;
if ( V_18 -> V_21 >= V_316 &&
V_18 -> V_21 < V_317 ) {
V_177 -> V_180 = V_18 -> V_53 ;
} else {
F_39 ( & V_34 -> V_128 , L_35 ) ;
return - V_101 ;
}
break;
}
return 0 ;
}
static int F_64 ( struct V_75 * V_75 , void * V_76 ,
struct V_319 * V_320 )
{
struct V_17 * V_18 = F_34 ( V_76 ) ;
if ( V_320 -> type == V_117 ) {
V_18 -> V_45 . V_321 =
V_320 -> V_322 . V_323 . V_324 . V_325 ;
V_18 -> V_45 . V_326 =
V_320 -> V_322 . V_323 . V_324 . V_327 ;
} else {
F_35 ( L_36 ) ;
return - V_101 ;
}
return 0 ;
}
static int F_65 ( struct V_75 * V_75 , void * V_76 ,
struct V_319 * V_320 )
{
struct V_17 * V_18 = F_34 ( V_76 ) ;
if ( V_320 -> type == V_328 ) {
V_320 -> V_322 . V_323 . V_324 . V_325 =
V_18 -> V_45 . V_321 ;
V_320 -> V_322 . V_323 . V_324 . V_327 =
V_18 -> V_45 . V_326 ;
} else {
F_35 ( L_36 ) ;
return - V_101 ;
}
return 0 ;
}
static int F_66 ( struct V_75 * V_75 , void * V_76 ,
struct V_329 * V_330 )
{
struct V_17 * V_18 = F_34 ( V_76 ) ;
struct V_33 * V_34 = V_18 -> V_34 ;
struct V_26 * V_150 ;
unsigned long V_67 ;
switch ( V_330 -> V_330 ) {
case V_331 :
if ( V_330 -> V_67 != 0 )
return - V_101 ;
if ( ! V_18 -> V_125 . V_126 )
return - V_101 ;
F_67 ( & V_34 -> V_332 , V_67 ) ;
if ( F_6 ( & V_18 -> V_32 ) ) {
F_4 ( 2 , L_37 ) ;
V_18 -> V_21 = V_25 ;
if ( F_3 ( V_18 ) )
F_19 ( V_18 ) ;
F_68 ( & V_34 -> V_332 , V_67 ) ;
F_14 ( V_34 -> V_41 , V_51 , V_34 ) ;
} else {
F_4 ( 2 , L_38 ) ;
V_150 = F_7 ( V_18 -> V_32 . V_333 ,
struct V_26 , V_30 ) ;
if ( V_150 -> V_67 & V_68 )
V_18 -> V_21 = V_25 ;
else
V_150 -> V_67 |= V_334 ;
F_68 ( & V_34 -> V_332 , V_67 ) ;
}
break;
default:
return - V_101 ;
}
return 0 ;
}
static int F_69 ( struct V_335 * V_164 ,
const struct V_336 * V_337 )
{
switch ( V_337 -> type ) {
case V_159 :
return F_70 ( V_164 , V_337 , 2 , NULL ) ;
default:
return - V_101 ;
}
}
static int F_71 ( struct V_1 * V_9 , struct V_338 * V_339 )
{
int V_5 ;
if ( ! V_9 )
return - V_101 ;
if ( V_9 -> V_112 != V_339 -> V_112 ) {
F_35 ( L_39 ) ;
return - V_101 ;
}
for ( V_5 = 0 ; V_5 < V_9 -> V_112 ; V_5 ++ ) {
T_2 V_340 = F_12 ( V_339 , V_5 ) ;
if ( ! V_340 ) {
F_35 ( L_40 ) ;
return - V_101 ;
}
F_4 ( 2 , L_41 ,
V_339 -> V_99 , V_5 , & V_340 ) ;
}
return 0 ;
}
static int F_72 ( struct V_341 * V_342 ,
unsigned int * V_343 , unsigned int * V_344 ,
unsigned int V_345 [] , struct V_346 * V_347 [] )
{
struct V_17 * V_18 = F_34 ( V_342 -> V_348 ) ;
struct V_33 * V_34 = V_18 -> V_34 ;
if ( V_342 -> type == V_106 ) {
if ( V_18 -> V_21 != V_22 ) {
F_35 ( L_42 , V_18 -> V_21 ) ;
return - V_101 ;
}
if ( V_18 -> V_111 )
* V_344 = V_18 -> V_111 -> V_112 ;
else
* V_344 = V_349 ;
if ( * V_343 < 1 )
* V_343 = 1 ;
if ( * V_343 > V_350 )
* V_343 = V_350 ;
V_345 [ 0 ] = V_18 -> V_115 ;
V_347 [ 0 ] = V_18 -> V_34 -> V_351 ;
} else if ( V_342 -> type == V_117 ) {
if ( V_18 -> V_120 )
* V_344 = V_18 -> V_120 -> V_112 ;
else
* V_344 = V_352 ;
if ( * V_343 < 1 )
* V_343 = 1 ;
if ( * V_343 > V_350 )
* V_343 = V_350 ;
V_345 [ 0 ] = V_18 -> V_122 ;
V_345 [ 1 ] = V_18 -> V_123 ;
if ( F_18 ( V_34 ) ) {
V_347 [ 0 ] = V_18 -> V_34 -> V_351 ;
V_347 [ 1 ] = V_18 -> V_34 -> V_351 ;
} else {
V_347 [ 0 ] = V_18 -> V_34 -> V_353 ;
V_347 [ 1 ] = V_18 -> V_34 -> V_353 ;
}
} else {
F_35 ( L_43 , V_342 -> type ) ;
return - V_101 ;
}
return 0 ;
}
static int F_73 ( struct V_338 * V_339 )
{
struct V_354 * V_355 = F_74 ( V_339 ) ;
struct V_341 * V_342 = V_339 -> V_341 ;
struct V_17 * V_18 = F_34 ( V_342 -> V_348 ) ;
unsigned int V_5 ;
int V_124 ;
if ( V_342 -> type == V_106 ) {
V_124 = F_71 ( V_18 -> V_111 , V_339 ) ;
if ( V_124 < 0 )
return V_124 ;
V_5 = V_339 -> V_99 ;
V_18 -> V_356 [ V_5 ] . V_39 = V_355 ;
V_18 -> V_356 [ V_5 ] . V_357 . V_358 =
F_12 ( V_339 , 0 ) ;
V_18 -> V_133 ++ ;
} else if ( V_342 -> type == V_117 ) {
V_124 = F_71 ( V_18 -> V_120 , V_339 ) ;
if ( V_124 < 0 )
return V_124 ;
V_5 = V_339 -> V_99 ;
V_18 -> V_359 [ V_5 ] . V_39 = V_355 ;
V_18 -> V_359 [ V_5 ] . V_357 . V_360 . V_361 =
F_12 ( V_339 , 0 ) ;
V_18 -> V_359 [ V_5 ] . V_357 . V_360 . V_362 =
F_12 ( V_339 , 1 ) ;
V_18 -> V_137 ++ ;
} else {
F_35 ( L_43 , V_342 -> type ) ;
return - V_101 ;
}
return 0 ;
}
static int F_75 ( struct V_338 * V_339 )
{
struct V_341 * V_342 = V_339 -> V_341 ;
struct V_17 * V_18 = F_34 ( V_342 -> V_348 ) ;
int V_124 ;
if ( V_342 -> type == V_106 ) {
V_124 = F_71 ( V_18 -> V_111 , V_339 ) ;
if ( V_124 < 0 )
return V_124 ;
F_4 ( 2 , L_44 ,
F_13 ( V_339 , 0 ) , V_18 -> V_115 ) ;
if ( F_13 ( V_339 , 0 ) < V_18 -> V_115 ) {
F_35 ( L_45 ) ;
return - V_101 ;
}
} else if ( V_342 -> type == V_117 ) {
V_124 = F_71 ( V_18 -> V_120 , V_339 ) ;
if ( V_124 < 0 )
return V_124 ;
F_4 ( 2 , L_46 ,
F_13 ( V_339 , 0 ) , V_18 -> V_122 ) ;
F_4 ( 2 , L_47 ,
F_13 ( V_339 , 1 ) , V_18 -> V_123 ) ;
if ( F_13 ( V_339 , 0 ) < V_18 -> V_122 ||
F_13 ( V_339 , 1 ) < V_18 -> V_123 ) {
F_35 ( L_48 ) ;
return - V_101 ;
}
} else {
F_35 ( L_43 , V_342 -> type ) ;
return - V_101 ;
}
return 0 ;
}
static int F_76 ( struct V_341 * V_363 , unsigned int V_144 )
{
struct V_17 * V_18 = F_34 ( V_363 -> V_348 ) ;
struct V_33 * V_34 = V_18 -> V_34 ;
if ( F_18 ( V_34 ) &&
( V_363 -> type == V_106 ) ) {
if ( ( V_18 -> V_21 == V_22 ) &&
( V_34 -> V_364 == V_18 -> V_365 ) && V_34 -> V_366 ) {
F_63 ( V_18 ,
V_318 ,
0 ) ;
}
if ( V_18 -> V_137 < V_18 -> V_53 ) {
F_35 ( L_49 ,
V_18 -> V_53 ) ;
return - V_367 ;
}
}
if ( F_3 ( V_18 ) )
F_19 ( V_18 ) ;
F_14 ( V_34 -> V_41 , V_51 , V_34 ) ;
return 0 ;
}
static void F_77 ( struct V_341 * V_363 )
{
unsigned long V_67 ;
struct V_17 * V_18 = F_34 ( V_363 -> V_348 ) ;
struct V_33 * V_34 = V_18 -> V_34 ;
if ( ( V_18 -> V_21 == V_25 ||
V_18 -> V_21 == V_23 ) &&
V_34 -> V_364 == V_18 -> V_365 && V_34 -> V_366 ) {
V_18 -> V_21 = V_317 ;
F_63 ( V_18 , V_368 ,
0 ) ;
}
V_18 -> V_21 = V_162 ;
F_67 ( & V_34 -> V_332 , V_67 ) ;
if ( V_363 -> type == V_106 ) {
F_78 ( & V_18 -> V_38 , & V_18 -> V_127 ) ;
F_10 ( & V_18 -> V_38 ) ;
V_18 -> V_20 = 0 ;
}
if ( V_363 -> type == V_117 ) {
F_5 ( V_18 ) ;
F_78 ( & V_18 -> V_32 , & V_18 -> V_125 ) ;
F_10 ( & V_18 -> V_32 ) ;
V_18 -> V_19 = 0 ;
}
F_68 ( & V_34 -> V_332 , V_67 ) ;
}
static void F_79 ( struct V_338 * V_339 )
{
struct V_341 * V_342 = V_339 -> V_341 ;
struct V_17 * V_18 = F_34 ( V_342 -> V_348 ) ;
struct V_33 * V_34 = V_18 -> V_34 ;
unsigned long V_67 ;
struct V_26 * V_369 ;
if ( V_18 -> V_21 == V_155 ) {
F_17 ( V_339 , V_370 ) ;
F_5 ( V_18 ) ;
return;
}
if ( V_342 -> type == V_106 ) {
V_369 = & V_18 -> V_356 [ V_339 -> V_99 ] ;
V_369 -> V_67 &= ~ V_68 ;
F_67 ( & V_34 -> V_332 , V_67 ) ;
F_9 ( & V_369 -> V_30 , & V_18 -> V_38 ) ;
V_18 -> V_20 ++ ;
F_68 ( & V_34 -> V_332 , V_67 ) ;
} else if ( V_342 -> type == V_117 ) {
V_369 = & V_18 -> V_359 [ V_339 -> V_99 ] ;
V_369 -> V_67 &= ~ V_68 ;
F_67 ( & V_34 -> V_332 , V_67 ) ;
F_9 ( & V_369 -> V_30 , & V_18 -> V_32 ) ;
V_18 -> V_19 ++ ;
F_68 ( & V_34 -> V_332 , V_67 ) ;
} else {
F_35 ( L_50 , V_342 -> type ) ;
}
if ( F_3 ( V_18 ) )
F_19 ( V_18 ) ;
F_14 ( V_34 -> V_41 , V_51 , V_34 ) ;
}
const struct V_371 * F_80 ( void )
{
return & V_372 ;
}
struct V_373 * F_81 ( void )
{
return & V_374 ;
}
const struct V_375 * F_82 ( void )
{
return & V_376 ;
}
int F_83 ( struct V_17 * V_18 )
{
struct V_377 V_378 ;
int V_5 ;
F_84 ( & V_18 -> V_379 , V_380 ) ;
if ( V_18 -> V_379 . error ) {
F_35 ( L_51 ) ;
return V_18 -> V_379 . error ;
}
for ( V_5 = 0 ; V_5 < V_380 ; V_5 ++ ) {
if ( F_85 ( V_381 [ V_5 ] . V_12 ) ) {
memset ( & V_378 , 0 , sizeof( struct V_377 ) ) ;
V_378 . V_382 = & V_383 ;
V_378 . V_12 = V_381 [ V_5 ] . V_12 ;
V_378 . V_384 = V_381 [ V_5 ] . V_385 ;
V_378 . V_386 = V_381 [ V_5 ] . V_387 ;
V_378 . V_388 = V_381 [ V_5 ] . V_389 ;
V_378 . V_83 = V_381 [ V_5 ] . V_83 ;
V_378 . type = V_381 [ V_5 ] . type ;
V_378 . V_67 = 0 ;
if ( V_378 . type == V_390 ) {
V_378 . V_391 = 0 ;
V_378 . V_392 = V_378 . V_392 ;
V_378 . V_393 = F_2 ( V_378 . V_12 ) ;
} else {
V_378 . V_391 = V_381 [ V_5 ] . V_391 ;
V_378 . V_392 = 0 ;
}
V_18 -> V_394 [ V_5 ] = F_86 ( & V_18 -> V_379 ,
& V_378 , NULL ) ;
} else {
if ( ( V_381 [ V_5 ] . type == V_390 ) ||
( V_381 [ V_5 ] . type ==
V_395 ) ) {
V_18 -> V_394 [ V_5 ] = F_87 (
& V_18 -> V_379 ,
& V_383 , V_381 [ V_5 ] . V_12 ,
V_381 [ V_5 ] . V_387 , 0 ,
V_381 [ V_5 ] . V_389 ) ;
} else {
V_18 -> V_394 [ V_5 ] = F_88 (
& V_18 -> V_379 ,
& V_383 , V_381 [ V_5 ] . V_12 ,
V_381 [ V_5 ] . V_385 ,
V_381 [ V_5 ] . V_387 , V_381 [ V_5 ] . V_391 ,
V_381 [ V_5 ] . V_389 ) ;
}
}
if ( V_18 -> V_379 . error ) {
F_35 ( L_52 , V_5 ) ;
return V_18 -> V_379 . error ;
}
if ( V_381 [ V_5 ] . V_396 && V_18 -> V_394 [ V_5 ] )
V_18 -> V_394 [ V_5 ] -> V_67 |= V_397 ;
}
F_89 ( & V_18 -> V_379 ) ;
return 0 ;
}
void F_90 ( struct V_17 * V_18 )
{
int V_5 ;
F_91 ( & V_18 -> V_379 ) ;
for ( V_5 = 0 ; V_5 < V_380 ; V_5 ++ )
V_18 -> V_394 [ V_5 ] = NULL ;
}
void F_92 ( struct V_17 * V_18 )
{
struct V_2 V_3 ;
V_3 . V_9 . V_10 . V_11 = V_398 ;
V_18 -> V_120 = F_1 ( & V_3 , V_94 ) ;
V_3 . V_9 . V_10 . V_11 = V_399 ;
V_18 -> V_111 = F_1 ( & V_3 , V_95 ) ;
}
