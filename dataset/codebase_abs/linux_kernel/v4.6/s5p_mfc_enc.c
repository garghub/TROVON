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
strncpy ( V_78 -> V_79 , V_34 -> V_80 -> V_81 , sizeof( V_78 -> V_79 ) - 1 ) ;
strncpy ( V_78 -> V_82 , V_34 -> V_80 -> V_81 , sizeof( V_78 -> V_82 ) - 1 ) ;
V_78 -> V_83 [ 0 ] = 0 ;
V_78 -> V_84 = V_85 | V_86 ;
V_78 -> V_87 = V_78 -> V_84 | V_88 ;
return 0 ;
}
static int F_27 ( struct V_75 * V_75 , struct V_89 * V_3 ,
bool V_90 )
{
struct V_33 * V_34 = F_26 ( V_75 ) ;
struct V_1 * V_9 ;
int V_5 , V_91 = 0 ;
for ( V_5 = 0 ; V_5 < F_28 ( V_7 ) ; ++ V_5 ) {
if ( V_90 && V_7 [ V_5 ] . type != V_92 )
continue;
else if ( ! V_90 && V_7 [ V_5 ] . type != V_93 )
continue;
else if ( ( V_34 -> V_94 -> V_95 & V_7 [ V_5 ] . V_96 ) == 0 )
continue;
if ( V_91 == V_3 -> V_97 ) {
V_9 = & V_7 [ V_5 ] ;
F_29 ( V_3 -> V_98 , V_9 -> V_81 ,
sizeof( V_3 -> V_98 ) ) ;
V_3 -> V_11 = V_9 -> V_8 ;
return 0 ;
}
++ V_91 ;
}
return - V_99 ;
}
static int F_30 ( struct V_75 * V_75 , void * V_100 ,
struct V_89 * V_3 )
{
return F_27 ( V_75 , V_3 , false ) ;
}
static int F_31 ( struct V_75 * V_75 , void * V_101 ,
struct V_89 * V_3 )
{
return F_27 ( V_75 , V_3 , true ) ;
}
static int F_32 ( struct V_75 * V_75 , void * V_76 , struct V_2 * V_3 )
{
struct V_17 * V_18 = F_33 ( V_76 ) ;
struct V_102 * V_103 = & V_3 -> V_9 . V_10 ;
F_4 ( 2 , L_12 , V_3 -> type , V_18 -> V_21 ) ;
if ( V_3 -> type == V_104 ) {
V_103 -> V_105 = 0 ;
V_103 -> V_106 = 0 ;
V_103 -> V_107 = V_108 ;
V_103 -> V_11 = V_18 -> V_109 -> V_8 ;
V_103 -> V_110 = V_18 -> V_109 -> V_110 ;
V_103 -> V_111 [ 0 ] . V_112 = V_18 -> V_113 ;
V_103 -> V_111 [ 0 ] . V_114 = V_18 -> V_113 ;
} else if ( V_3 -> type == V_115 ) {
V_103 -> V_105 = V_18 -> V_116 ;
V_103 -> V_106 = V_18 -> V_117 ;
V_103 -> V_107 = V_108 ;
V_103 -> V_11 = V_18 -> V_118 -> V_8 ;
V_103 -> V_110 = V_18 -> V_118 -> V_110 ;
V_103 -> V_111 [ 0 ] . V_112 = V_18 -> V_119 ;
V_103 -> V_111 [ 0 ] . V_114 = V_18 -> V_120 ;
V_103 -> V_111 [ 1 ] . V_112 = V_18 -> V_119 ;
V_103 -> V_111 [ 1 ] . V_114 = V_18 -> V_121 ;
} else {
F_34 ( L_13 ) ;
return - V_99 ;
}
return 0 ;
}
static int F_35 ( struct V_75 * V_75 , void * V_76 , struct V_2 * V_3 )
{
struct V_33 * V_34 = F_26 ( V_75 ) ;
struct V_1 * V_9 ;
struct V_102 * V_103 = & V_3 -> V_9 . V_10 ;
if ( V_3 -> type == V_104 ) {
V_9 = F_1 ( V_3 , V_93 ) ;
if ( ! V_9 ) {
F_34 ( L_14 ) ;
return - V_99 ;
}
if ( V_103 -> V_111 [ 0 ] . V_114 == 0 ) {
F_34 ( L_15 ) ;
return - V_99 ;
}
if ( ( V_34 -> V_94 -> V_95 & V_9 -> V_96 ) == 0 ) {
F_34 ( L_16 ) ;
return - V_99 ;
}
V_103 -> V_111 [ 0 ] . V_112 =
V_103 -> V_111 [ 0 ] . V_114 ;
} else if ( V_3 -> type == V_115 ) {
V_9 = F_1 ( V_3 , V_92 ) ;
if ( ! V_9 ) {
F_34 ( L_14 ) ;
return - V_99 ;
}
if ( V_9 -> V_110 != V_103 -> V_110 ) {
F_34 ( L_14 ) ;
return - V_99 ;
}
if ( ( V_34 -> V_94 -> V_95 & V_9 -> V_96 ) == 0 ) {
F_34 ( L_16 ) ;
return - V_99 ;
}
F_36 ( & V_103 -> V_105 , 8 , 1920 , 1 ,
& V_103 -> V_106 , 4 , 1080 , 1 , 0 ) ;
} else {
F_34 ( L_13 ) ;
return - V_99 ;
}
return 0 ;
}
static int F_37 ( struct V_75 * V_75 , void * V_76 , struct V_2 * V_3 )
{
struct V_33 * V_34 = F_26 ( V_75 ) ;
struct V_17 * V_18 = F_33 ( V_76 ) ;
struct V_102 * V_103 = & V_3 -> V_9 . V_10 ;
int V_122 = 0 ;
V_122 = F_35 ( V_75 , V_76 , V_3 ) ;
if ( V_122 )
return V_122 ;
if ( V_18 -> V_123 . V_124 || V_18 -> V_125 . V_124 ) {
F_38 ( & V_34 -> V_126 , L_17 , V_127 ) ;
V_122 = - V_128 ;
goto V_90;
}
if ( V_3 -> type == V_104 ) {
V_18 -> V_109 = F_1 ( V_3 , V_93 ) ;
V_18 -> V_21 = V_129 ;
V_18 -> V_130 = V_18 -> V_109 -> V_130 ;
V_18 -> V_113 = V_103 -> V_111 [ 0 ] . V_114 ;
V_103 -> V_111 [ 0 ] . V_112 = 0 ;
V_18 -> V_131 = 0 ;
V_18 -> V_132 = V_133 ;
V_122 = F_39 ( V_34 , V_18 ) ;
} else if ( V_3 -> type == V_115 ) {
V_18 -> V_118 = F_1 ( V_3 , V_92 ) ;
V_18 -> V_116 = V_103 -> V_105 ;
V_18 -> V_117 = V_103 -> V_106 ;
F_4 ( 2 , L_18 , V_18 -> V_118 -> V_130 ) ;
F_4 ( 2 , L_19 ,
V_103 -> V_105 , V_103 -> V_106 ,
V_18 -> V_116 , V_18 -> V_117 ) ;
F_14 ( V_34 -> V_41 , V_134 , V_18 ) ;
V_103 -> V_111 [ 0 ] . V_114 = V_18 -> V_120 ;
V_103 -> V_111 [ 0 ] . V_112 = V_18 -> V_119 ;
V_103 -> V_111 [ 1 ] . V_114 = V_18 -> V_121 ;
V_103 -> V_111 [ 1 ] . V_112 = V_18 -> V_119 ;
V_18 -> V_135 = 0 ;
V_18 -> V_136 = V_133 ;
} else {
F_34 ( L_13 ) ;
V_122 = - V_99 ;
}
V_90:
F_40 () ;
return V_122 ;
}
static int F_41 ( struct V_75 * V_75 , void * V_76 ,
struct V_137 * V_138 )
{
struct V_33 * V_34 = F_26 ( V_75 ) ;
struct V_17 * V_18 = F_33 ( V_76 ) ;
int V_122 = 0 ;
if ( ( V_138 -> V_139 != V_140 ) &&
( V_138 -> V_139 != V_141 ) )
return - V_99 ;
if ( V_138 -> type == V_104 ) {
if ( V_138 -> V_142 == 0 ) {
V_122 = F_42 ( & V_18 -> V_125 , V_138 ) ;
V_18 -> V_132 = V_133 ;
return V_122 ;
}
if ( V_18 -> V_132 != V_133 ) {
F_34 ( L_20 ,
V_18 -> V_132 ) ;
return - V_99 ;
}
V_122 = F_42 ( & V_18 -> V_125 , V_138 ) ;
if ( V_122 != 0 ) {
F_34 ( L_21 ) ;
return V_122 ;
}
V_18 -> V_132 = V_143 ;
V_122 = F_14 ( V_18 -> V_34 -> V_41 ,
V_144 , V_18 ) ;
if ( V_122 ) {
F_34 ( L_22 ) ;
V_138 -> V_142 = 0 ;
V_122 = F_42 ( & V_18 -> V_125 , V_138 ) ;
return - V_145 ;
}
} else if ( V_138 -> type == V_115 ) {
if ( V_138 -> V_142 == 0 ) {
F_4 ( 2 , L_23 ) ;
V_122 = F_42 ( & V_18 -> V_123 , V_138 ) ;
F_14 ( V_34 -> V_41 , V_146 ,
V_18 ) ;
V_18 -> V_136 = V_133 ;
return V_122 ;
}
if ( V_18 -> V_136 != V_133 ) {
F_34 ( L_24 ,
V_18 -> V_136 ) ;
return - V_99 ;
}
if ( F_18 ( V_34 ) ) {
if ( V_18 -> V_53 &&
( V_138 -> V_142 < V_18 -> V_53 ) ) {
V_138 -> V_142 = V_18 -> V_53 ;
F_4 ( 2 , L_25 ,
V_18 -> V_53 ) ;
} else {
V_18 -> V_53 = V_138 -> V_142 ;
}
}
V_122 = F_42 ( & V_18 -> V_123 , V_138 ) ;
if ( V_122 != 0 ) {
F_34 ( L_26 ) ;
return V_122 ;
}
V_18 -> V_136 = V_143 ;
} else {
F_34 ( L_13 ) ;
return - V_99 ;
}
return V_122 ;
}
static int F_43 ( struct V_75 * V_75 , void * V_76 ,
struct V_147 * V_148 )
{
struct V_17 * V_18 = F_33 ( V_76 ) ;
int V_122 = 0 ;
if ( ( V_148 -> V_139 != V_140 ) &&
( V_148 -> V_139 != V_141 ) )
return - V_99 ;
if ( V_148 -> type == V_104 ) {
if ( V_18 -> V_21 != V_22 ) {
F_34 ( L_27 , V_18 -> V_21 ) ;
return - V_99 ;
}
V_122 = F_44 ( & V_18 -> V_125 , V_148 ) ;
if ( V_122 != 0 ) {
F_34 ( L_28 ) ;
return V_122 ;
}
V_148 -> V_149 . V_150 [ 0 ] . V_149 . V_151 += V_152 ;
} else if ( V_148 -> type == V_115 ) {
V_122 = F_44 ( & V_18 -> V_123 , V_148 ) ;
if ( V_122 != 0 ) {
F_34 ( L_29 ) ;
return V_122 ;
}
} else {
F_34 ( L_13 ) ;
return - V_99 ;
}
return V_122 ;
}
static int F_45 ( struct V_75 * V_75 , void * V_76 , struct V_147 * V_148 )
{
struct V_17 * V_18 = F_33 ( V_76 ) ;
if ( V_18 -> V_21 == V_153 ) {
F_34 ( L_30 ) ;
return - V_154 ;
}
if ( V_148 -> type == V_115 ) {
if ( V_18 -> V_21 == V_25 ) {
F_34 ( L_31 ) ;
return - V_154 ;
}
return F_46 ( & V_18 -> V_123 , V_148 ) ;
} else if ( V_148 -> type == V_104 ) {
return F_46 ( & V_18 -> V_125 , V_148 ) ;
}
return - V_99 ;
}
static int F_47 ( struct V_75 * V_75 , void * V_76 , struct V_147 * V_148 )
{
const struct V_155 V_156 = {
. type = V_157
} ;
struct V_17 * V_18 = F_33 ( V_76 ) ;
int V_122 ;
if ( V_18 -> V_21 == V_153 ) {
F_34 ( L_32 ) ;
return - V_154 ;
}
if ( V_148 -> type == V_115 ) {
V_122 = F_48 ( & V_18 -> V_123 , V_148 , V_75 -> V_158 & V_159 ) ;
} else if ( V_148 -> type == V_104 ) {
V_122 = F_48 ( & V_18 -> V_125 , V_148 , V_75 -> V_158 & V_159 ) ;
if ( V_122 == 0 && V_18 -> V_21 == V_160
&& F_6 ( & V_18 -> V_125 . V_161 ) )
F_49 ( & V_18 -> V_162 , & V_156 ) ;
} else {
V_122 = - V_99 ;
}
return V_122 ;
}
static int F_50 ( struct V_75 * V_75 , void * V_76 ,
struct V_163 * V_164 )
{
struct V_17 * V_18 = F_33 ( V_76 ) ;
if ( V_164 -> type == V_115 )
return F_51 ( & V_18 -> V_123 , V_164 ) ;
if ( V_164 -> type == V_104 )
return F_51 ( & V_18 -> V_125 , V_164 ) ;
return - V_99 ;
}
static int F_52 ( struct V_75 * V_75 , void * V_76 ,
enum V_165 type )
{
struct V_17 * V_18 = F_33 ( V_76 ) ;
if ( type == V_115 )
return F_53 ( & V_18 -> V_123 , type ) ;
else if ( type == V_104 )
return F_53 ( & V_18 -> V_125 , type ) ;
return - V_99 ;
}
static int F_54 ( struct V_75 * V_75 , void * V_76 ,
enum V_165 type )
{
struct V_17 * V_18 = F_33 ( V_76 ) ;
if ( type == V_115 )
return F_55 ( & V_18 -> V_123 , type ) ;
else if ( type == V_104 )
return F_55 ( & V_18 -> V_125 , type ) ;
return - V_99 ;
}
static inline int F_56 ( enum V_166 V_167 )
{
static unsigned int V_4 [ V_168 + 1 ] = {
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
return V_4 [ V_167 ] ;
}
static inline int F_57 ( enum V_169 V_167 )
{
static unsigned int V_4 [ V_170 + 1 ] = {
0 ,
9 ,
1 ,
2 ,
3 ,
7 ,
4 ,
5 ,
} ;
return V_4 [ V_167 ] ;
}
static inline int F_58 ( enum V_171 V_172 )
{
static unsigned int V_4 [ V_173 + 1 ] = {
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
return V_4 [ V_172 ] ;
}
static int F_59 ( struct V_174 * V_175 )
{
struct V_17 * V_18 = F_60 ( V_175 ) ;
struct V_33 * V_34 = V_18 -> V_34 ;
struct V_43 * V_44 = & V_18 -> V_45 ;
int V_122 = 0 ;
switch ( V_175 -> V_12 ) {
case V_176 :
V_44 -> V_177 = V_175 -> V_178 ;
break;
case V_179 :
V_44 -> V_180 = V_175 -> V_178 ;
break;
case V_181 :
V_44 -> V_182 = V_175 -> V_178 ;
break;
case V_183 :
V_44 -> V_184 = V_175 -> V_178 * 8 ;
break;
case V_185 :
V_44 -> V_186 = V_175 -> V_178 ;
break;
case V_187 :
V_44 -> V_188 = V_175 -> V_178 ;
break;
case V_189 :
V_44 -> V_190 = ( V_175 -> V_178 >> 16 ) & 0xff ;
V_44 -> V_191 = ( V_175 -> V_178 >> 8 ) & 0xff ;
V_44 -> V_192 = ( V_175 -> V_178 >> 0 ) & 0xff ;
break;
case V_193 :
V_44 -> V_194 = V_175 -> V_178 ;
break;
case V_195 :
V_44 -> V_196 = V_175 -> V_178 ;
break;
case V_197 :
V_44 -> V_198 = V_175 -> V_178 ;
break;
case V_16 :
V_18 -> V_199 = V_175 -> V_178 ;
break;
case V_200 :
V_18 -> V_199 =
V_201 ;
break;
case V_202 :
V_44 -> V_203 = V_175 -> V_178 ;
break;
case V_204 :
V_44 -> V_205 = V_175 -> V_178 ;
break;
case V_206 :
V_44 -> V_207 = V_175 -> V_178 ;
break;
case V_208 :
V_44 -> V_209 . V_210 . V_211 = V_175 -> V_178 ;
break;
case V_212 :
V_44 -> V_47 = V_175 -> V_178 ;
break;
case V_15 :
V_44 -> V_213 = V_175 -> V_178 ;
break;
case V_214 :
V_44 -> V_215 = V_175 -> V_178 ;
break;
case V_216 :
V_44 -> V_217 = V_175 -> V_178 ;
break;
case V_218 :
switch ( V_175 -> V_178 ) {
case V_219 :
V_44 -> V_209 . V_210 . V_220 =
V_221 ;
break;
case V_222 :
V_44 -> V_209 . V_210 . V_220 =
V_223 ;
break;
case V_224 :
V_44 -> V_209 . V_210 . V_220 =
V_225 ;
break;
case V_226 :
if ( F_18 ( V_34 ) )
V_44 -> V_209 . V_210 . V_220 =
V_227 ;
else
V_122 = - V_99 ;
break;
default:
V_122 = - V_99 ;
}
break;
case V_228 :
V_44 -> V_209 . V_210 . V_229 = V_175 -> V_178 ;
V_44 -> V_209 . V_210 . V_230 = F_56 ( V_175 -> V_178 ) ;
if ( V_44 -> V_209 . V_210 . V_230 < 0 ) {
F_34 ( L_33 ) ;
V_122 = V_44 -> V_209 . V_210 . V_230 ;
}
break;
case V_231 :
V_44 -> V_209 . V_232 . V_229 = V_175 -> V_178 ;
V_44 -> V_209 . V_232 . V_230 = F_57 ( V_175 -> V_178 ) ;
if ( V_44 -> V_209 . V_232 . V_230 < 0 ) {
F_34 ( L_33 ) ;
V_122 = V_44 -> V_209 . V_232 . V_230 ;
}
break;
case V_233 :
V_44 -> V_209 . V_210 . V_234 = V_175 -> V_178 ;
break;
case V_235 :
V_44 -> V_209 . V_210 . V_236 = V_175 -> V_178 ;
break;
case V_237 :
V_44 -> V_209 . V_210 . V_238 = V_175 -> V_178 ;
break;
case V_239 :
V_44 -> V_209 . V_210 . V_240 = V_175 -> V_178 ;
break;
case V_241 :
V_44 -> V_209 . V_210 . V_242 = V_175 -> V_178 ;
break;
case V_243 :
V_44 -> V_209 . V_210 . V_244 = V_175 -> V_178 ;
break;
case V_245 :
V_44 -> V_246 = V_175 -> V_178 ;
break;
case V_247 :
V_44 -> V_209 . V_210 . V_248 = V_175 -> V_178 ;
break;
case V_249 :
V_44 -> V_209 . V_210 . V_250 = V_175 -> V_178 ;
break;
case V_251 :
V_44 -> V_209 . V_210 . V_252 = V_175 -> V_178 ;
break;
case V_253 :
V_44 -> V_209 . V_210 . V_254 = V_175 -> V_178 ;
break;
case V_255 :
V_44 -> V_209 . V_210 . V_256 = V_175 -> V_178 ;
break;
case V_257 :
case V_258 :
V_44 -> V_209 . V_232 . V_248 = V_175 -> V_178 ;
break;
case V_259 :
case V_260 :
V_44 -> V_209 . V_232 . V_250 = V_175 -> V_178 ;
break;
case V_261 :
case V_262 :
V_44 -> V_209 . V_232 . V_252 = V_175 -> V_178 ;
break;
case V_263 :
case V_264 :
V_44 -> V_209 . V_232 . V_254 = V_175 -> V_178 ;
break;
case V_265 :
case V_266 :
V_44 -> V_209 . V_232 . V_256 = V_175 -> V_178 ;
break;
case V_267 :
V_44 -> V_209 . V_210 . V_268 = V_175 -> V_178 ;
break;
case V_269 :
V_44 -> V_209 . V_210 . V_270 = V_175 -> V_178 ;
break;
case V_271 :
V_44 -> V_209 . V_210 . V_272 = V_175 -> V_178 ;
break;
case V_273 :
V_44 -> V_209 . V_210 . V_274 = V_175 -> V_178 ;
break;
case V_275 :
V_44 -> V_209 . V_210 . V_276 = V_175 -> V_178 ;
break;
case V_277 :
V_44 -> V_209 . V_210 . F_58 = F_58 ( V_175 -> V_178 ) ;
break;
case V_278 :
V_44 -> V_209 . V_210 . V_279 = V_175 -> V_178 ;
break;
case V_280 :
V_44 -> V_209 . V_210 . V_281 = V_175 -> V_178 ;
break;
case V_282 :
V_44 -> V_209 . V_210 . V_283 = ! V_175 -> V_178 ;
break;
case V_284 :
V_44 -> V_209 . V_210 . V_285 = V_175 -> V_178 ;
break;
case V_286 :
switch ( V_175 -> V_178 ) {
case V_287 :
V_44 -> V_209 . V_232 . V_220 =
V_288 ;
break;
case V_289 :
V_44 -> V_209 . V_232 . V_220 =
V_290 ;
break;
default:
V_122 = - V_99 ;
}
break;
case V_291 :
V_44 -> V_209 . V_232 . V_292 = V_175 -> V_178 ;
break;
case V_293 :
V_44 -> V_209 . V_294 . V_295 = V_175 -> V_178 ;
break;
case V_296 :
V_44 -> V_209 . V_294 . V_297 = V_175 -> V_178 ;
break;
case V_298 :
V_44 -> V_209 . V_294 . V_299 = V_175 -> V_178 ;
break;
case V_300 :
V_44 -> V_209 . V_294 . V_301 = V_175 -> V_178 ;
break;
case V_302 :
V_44 -> V_209 . V_294 . V_303 = V_175 -> V_178 ;
break;
case V_304 :
V_44 -> V_209 . V_294 . V_305 = V_175 -> V_178 ;
break;
case V_306 :
V_44 -> V_209 . V_294 . V_307 = V_175 -> V_178 ;
break;
case V_308 :
V_44 -> V_209 . V_294 . V_250 = V_175 -> V_178 ;
break;
case V_309 :
V_44 -> V_209 . V_294 . V_252 = V_175 -> V_178 ;
break;
case V_310 :
V_44 -> V_209 . V_294 . V_248 = V_175 -> V_178 ;
break;
case V_311 :
V_44 -> V_209 . V_294 . V_254 = V_175 -> V_178 ;
break;
case V_312 :
V_44 -> V_209 . V_294 . V_220 = V_175 -> V_178 ;
break;
default:
F_38 ( & V_34 -> V_126 , L_34 ,
V_175 -> V_12 , V_175 -> V_178 ) ;
V_122 = - V_99 ;
}
return V_122 ;
}
static int F_61 ( struct V_174 * V_175 )
{
struct V_17 * V_18 = F_60 ( V_175 ) ;
struct V_33 * V_34 = V_18 -> V_34 ;
switch ( V_175 -> V_12 ) {
case V_313 :
if ( V_18 -> V_21 >= V_314 &&
V_18 -> V_21 < V_315 ) {
V_175 -> V_178 = V_18 -> V_53 ;
break;
} else if ( V_18 -> V_21 != V_129 ) {
F_38 ( & V_34 -> V_126 , L_35 ) ;
return - V_99 ;
}
F_62 ( V_18 ,
V_316 , 0 ) ;
if ( V_18 -> V_21 >= V_314 &&
V_18 -> V_21 < V_315 ) {
V_175 -> V_178 = V_18 -> V_53 ;
} else {
F_38 ( & V_34 -> V_126 , L_35 ) ;
return - V_99 ;
}
break;
}
return 0 ;
}
static int F_63 ( struct V_75 * V_75 , void * V_76 ,
struct V_317 * V_318 )
{
struct V_17 * V_18 = F_33 ( V_76 ) ;
if ( V_318 -> type == V_115 ) {
V_18 -> V_45 . V_319 =
V_318 -> V_320 . V_321 . V_322 . V_323 ;
V_18 -> V_45 . V_324 =
V_318 -> V_320 . V_321 . V_322 . V_325 ;
} else {
F_34 ( L_36 ) ;
return - V_99 ;
}
return 0 ;
}
static int F_64 ( struct V_75 * V_75 , void * V_76 ,
struct V_317 * V_318 )
{
struct V_17 * V_18 = F_33 ( V_76 ) ;
if ( V_318 -> type == V_326 ) {
V_318 -> V_320 . V_321 . V_322 . V_323 =
V_18 -> V_45 . V_319 ;
V_318 -> V_320 . V_321 . V_322 . V_325 =
V_18 -> V_45 . V_324 ;
} else {
F_34 ( L_36 ) ;
return - V_99 ;
}
return 0 ;
}
static int F_65 ( struct V_75 * V_75 , void * V_76 ,
struct V_327 * V_328 )
{
struct V_17 * V_18 = F_33 ( V_76 ) ;
struct V_33 * V_34 = V_18 -> V_34 ;
struct V_26 * V_148 ;
unsigned long V_67 ;
switch ( V_328 -> V_328 ) {
case V_329 :
if ( V_328 -> V_67 != 0 )
return - V_99 ;
if ( ! V_18 -> V_123 . V_124 )
return - V_99 ;
F_66 ( & V_34 -> V_330 , V_67 ) ;
if ( F_6 ( & V_18 -> V_32 ) ) {
F_4 ( 2 , L_37 ) ;
V_18 -> V_21 = V_25 ;
if ( F_3 ( V_18 ) )
F_19 ( V_18 ) ;
F_67 ( & V_34 -> V_330 , V_67 ) ;
F_14 ( V_34 -> V_41 , V_51 , V_34 ) ;
} else {
F_4 ( 2 , L_38 ) ;
V_148 = F_7 ( V_18 -> V_32 . V_331 ,
struct V_26 , V_30 ) ;
if ( V_148 -> V_67 & V_68 )
V_18 -> V_21 = V_25 ;
else
V_148 -> V_67 |= V_332 ;
F_67 ( & V_34 -> V_330 , V_67 ) ;
}
break;
default:
return - V_99 ;
}
return 0 ;
}
static int F_68 ( struct V_333 * V_162 ,
const struct V_334 * V_335 )
{
switch ( V_335 -> type ) {
case V_157 :
return F_69 ( V_162 , V_335 , 2 , NULL ) ;
default:
return - V_99 ;
}
}
static int F_70 ( struct V_1 * V_9 , struct V_336 * V_337 )
{
int V_5 ;
if ( ! V_9 )
return - V_99 ;
if ( V_9 -> V_110 != V_337 -> V_110 ) {
F_34 ( L_39 ) ;
return - V_99 ;
}
for ( V_5 = 0 ; V_5 < V_9 -> V_110 ; V_5 ++ ) {
T_2 V_338 = F_12 ( V_337 , V_5 ) ;
if ( ! V_338 ) {
F_34 ( L_40 ) ;
return - V_99 ;
}
F_4 ( 2 , L_41 ,
V_337 -> V_97 , V_5 , & V_338 ) ;
}
return 0 ;
}
static int F_71 ( struct V_339 * V_340 ,
unsigned int * V_341 , unsigned int * V_342 ,
unsigned int V_343 [] , void * V_344 [] )
{
struct V_17 * V_18 = F_33 ( V_340 -> V_345 ) ;
struct V_33 * V_34 = V_18 -> V_34 ;
if ( V_340 -> type == V_104 ) {
if ( V_18 -> V_21 != V_22 ) {
F_34 ( L_42 , V_18 -> V_21 ) ;
return - V_99 ;
}
if ( V_18 -> V_109 )
* V_342 = V_18 -> V_109 -> V_110 ;
else
* V_342 = V_346 ;
if ( * V_341 < 1 )
* V_341 = 1 ;
if ( * V_341 > V_347 )
* V_341 = V_347 ;
V_343 [ 0 ] = V_18 -> V_113 ;
V_344 [ 0 ] = V_18 -> V_34 -> V_348 [ V_349 ] ;
} else if ( V_340 -> type == V_115 ) {
if ( V_18 -> V_118 )
* V_342 = V_18 -> V_118 -> V_110 ;
else
* V_342 = V_350 ;
if ( * V_341 < 1 )
* V_341 = 1 ;
if ( * V_341 > V_347 )
* V_341 = V_347 ;
V_343 [ 0 ] = V_18 -> V_120 ;
V_343 [ 1 ] = V_18 -> V_121 ;
if ( F_18 ( V_34 ) ) {
V_344 [ 0 ] =
V_18 -> V_34 -> V_348 [ V_349 ] ;
V_344 [ 1 ] =
V_18 -> V_34 -> V_348 [ V_349 ] ;
} else {
V_344 [ 0 ] =
V_18 -> V_34 -> V_348 [ V_351 ] ;
V_344 [ 1 ] =
V_18 -> V_34 -> V_348 [ V_351 ] ;
}
} else {
F_34 ( L_43 , V_340 -> type ) ;
return - V_99 ;
}
return 0 ;
}
static int F_72 ( struct V_336 * V_337 )
{
struct V_352 * V_353 = F_73 ( V_337 ) ;
struct V_339 * V_340 = V_337 -> V_339 ;
struct V_17 * V_18 = F_33 ( V_340 -> V_345 ) ;
unsigned int V_5 ;
int V_122 ;
if ( V_340 -> type == V_104 ) {
V_122 = F_70 ( V_18 -> V_109 , V_337 ) ;
if ( V_122 < 0 )
return V_122 ;
V_5 = V_337 -> V_97 ;
V_18 -> V_354 [ V_5 ] . V_39 = V_353 ;
V_18 -> V_354 [ V_5 ] . V_355 . V_356 =
F_12 ( V_337 , 0 ) ;
V_18 -> V_131 ++ ;
} else if ( V_340 -> type == V_115 ) {
V_122 = F_70 ( V_18 -> V_118 , V_337 ) ;
if ( V_122 < 0 )
return V_122 ;
V_5 = V_337 -> V_97 ;
V_18 -> V_357 [ V_5 ] . V_39 = V_353 ;
V_18 -> V_357 [ V_5 ] . V_355 . V_358 . V_359 =
F_12 ( V_337 , 0 ) ;
V_18 -> V_357 [ V_5 ] . V_355 . V_358 . V_360 =
F_12 ( V_337 , 1 ) ;
V_18 -> V_135 ++ ;
} else {
F_34 ( L_43 , V_340 -> type ) ;
return - V_99 ;
}
return 0 ;
}
static int F_74 ( struct V_336 * V_337 )
{
struct V_339 * V_340 = V_337 -> V_339 ;
struct V_17 * V_18 = F_33 ( V_340 -> V_345 ) ;
int V_122 ;
if ( V_340 -> type == V_104 ) {
V_122 = F_70 ( V_18 -> V_109 , V_337 ) ;
if ( V_122 < 0 )
return V_122 ;
F_4 ( 2 , L_44 ,
F_13 ( V_337 , 0 ) , V_18 -> V_113 ) ;
if ( F_13 ( V_337 , 0 ) < V_18 -> V_113 ) {
F_34 ( L_45 ) ;
return - V_99 ;
}
} else if ( V_340 -> type == V_115 ) {
V_122 = F_70 ( V_18 -> V_118 , V_337 ) ;
if ( V_122 < 0 )
return V_122 ;
F_4 ( 2 , L_46 ,
F_13 ( V_337 , 0 ) , V_18 -> V_120 ) ;
F_4 ( 2 , L_47 ,
F_13 ( V_337 , 1 ) , V_18 -> V_121 ) ;
if ( F_13 ( V_337 , 0 ) < V_18 -> V_120 ||
F_13 ( V_337 , 1 ) < V_18 -> V_121 ) {
F_34 ( L_48 ) ;
return - V_99 ;
}
} else {
F_34 ( L_43 , V_340 -> type ) ;
return - V_99 ;
}
return 0 ;
}
static int F_75 ( struct V_339 * V_361 , unsigned int V_142 )
{
struct V_17 * V_18 = F_33 ( V_361 -> V_345 ) ;
struct V_33 * V_34 = V_18 -> V_34 ;
if ( F_18 ( V_34 ) &&
( V_361 -> type == V_104 ) ) {
if ( ( V_18 -> V_21 == V_22 ) &&
( V_34 -> V_362 == V_18 -> V_363 ) && V_34 -> V_364 ) {
F_62 ( V_18 ,
V_316 ,
0 ) ;
}
if ( V_18 -> V_135 < V_18 -> V_53 ) {
F_34 ( L_49 ,
V_18 -> V_53 ) ;
return - V_365 ;
}
}
if ( F_3 ( V_18 ) )
F_19 ( V_18 ) ;
F_14 ( V_34 -> V_41 , V_51 , V_34 ) ;
return 0 ;
}
static void F_76 ( struct V_339 * V_361 )
{
unsigned long V_67 ;
struct V_17 * V_18 = F_33 ( V_361 -> V_345 ) ;
struct V_33 * V_34 = V_18 -> V_34 ;
if ( ( V_18 -> V_21 == V_25 ||
V_18 -> V_21 == V_23 ) &&
V_34 -> V_362 == V_18 -> V_363 && V_34 -> V_364 ) {
V_18 -> V_21 = V_315 ;
F_62 ( V_18 , V_366 ,
0 ) ;
}
V_18 -> V_21 = V_160 ;
F_66 ( & V_34 -> V_330 , V_67 ) ;
if ( V_361 -> type == V_104 ) {
F_77 ( & V_18 -> V_38 , & V_18 -> V_125 ) ;
F_10 ( & V_18 -> V_38 ) ;
V_18 -> V_20 = 0 ;
}
if ( V_361 -> type == V_115 ) {
F_5 ( V_18 ) ;
F_77 ( & V_18 -> V_32 , & V_18 -> V_123 ) ;
F_10 ( & V_18 -> V_32 ) ;
V_18 -> V_19 = 0 ;
}
F_67 ( & V_34 -> V_330 , V_67 ) ;
}
static void F_78 ( struct V_336 * V_337 )
{
struct V_339 * V_340 = V_337 -> V_339 ;
struct V_17 * V_18 = F_33 ( V_340 -> V_345 ) ;
struct V_33 * V_34 = V_18 -> V_34 ;
unsigned long V_67 ;
struct V_26 * V_367 ;
if ( V_18 -> V_21 == V_153 ) {
F_17 ( V_337 , V_368 ) ;
F_5 ( V_18 ) ;
return;
}
if ( V_340 -> type == V_104 ) {
V_367 = & V_18 -> V_354 [ V_337 -> V_97 ] ;
V_367 -> V_67 &= ~ V_68 ;
F_66 ( & V_34 -> V_330 , V_67 ) ;
F_9 ( & V_367 -> V_30 , & V_18 -> V_38 ) ;
V_18 -> V_20 ++ ;
F_67 ( & V_34 -> V_330 , V_67 ) ;
} else if ( V_340 -> type == V_115 ) {
V_367 = & V_18 -> V_357 [ V_337 -> V_97 ] ;
V_367 -> V_67 &= ~ V_68 ;
F_66 ( & V_34 -> V_330 , V_67 ) ;
F_9 ( & V_367 -> V_30 , & V_18 -> V_32 ) ;
V_18 -> V_19 ++ ;
F_67 ( & V_34 -> V_330 , V_67 ) ;
} else {
F_34 ( L_50 , V_340 -> type ) ;
}
if ( F_3 ( V_18 ) )
F_19 ( V_18 ) ;
F_14 ( V_34 -> V_41 , V_51 , V_34 ) ;
}
const struct V_369 * F_79 ( void )
{
return & V_370 ;
}
struct V_371 * F_80 ( void )
{
return & V_372 ;
}
const struct V_373 * F_81 ( void )
{
return & V_374 ;
}
int F_82 ( struct V_17 * V_18 )
{
struct V_375 V_376 ;
int V_5 ;
F_83 ( & V_18 -> V_377 , V_378 ) ;
if ( V_18 -> V_377 . error ) {
F_34 ( L_51 ) ;
return V_18 -> V_377 . error ;
}
for ( V_5 = 0 ; V_5 < V_378 ; V_5 ++ ) {
if ( F_84 ( V_379 [ V_5 ] . V_12 ) ) {
memset ( & V_376 , 0 , sizeof( struct V_375 ) ) ;
V_376 . V_380 = & V_381 ;
V_376 . V_12 = V_379 [ V_5 ] . V_12 ;
V_376 . V_382 = V_379 [ V_5 ] . V_383 ;
V_376 . V_384 = V_379 [ V_5 ] . V_385 ;
V_376 . V_386 = V_379 [ V_5 ] . V_387 ;
V_376 . V_81 = V_379 [ V_5 ] . V_81 ;
V_376 . type = V_379 [ V_5 ] . type ;
V_376 . V_67 = 0 ;
if ( V_376 . type == V_388 ) {
V_376 . V_389 = 0 ;
V_376 . V_390 = V_376 . V_390 ;
V_376 . V_391 = F_2 ( V_376 . V_12 ) ;
} else {
V_376 . V_389 = V_379 [ V_5 ] . V_389 ;
V_376 . V_390 = 0 ;
}
V_18 -> V_392 [ V_5 ] = F_85 ( & V_18 -> V_377 ,
& V_376 , NULL ) ;
} else {
if ( ( V_379 [ V_5 ] . type == V_388 ) ||
( V_379 [ V_5 ] . type ==
V_393 ) ) {
V_18 -> V_392 [ V_5 ] = F_86 (
& V_18 -> V_377 ,
& V_381 , V_379 [ V_5 ] . V_12 ,
V_379 [ V_5 ] . V_385 , 0 ,
V_379 [ V_5 ] . V_387 ) ;
} else {
V_18 -> V_392 [ V_5 ] = F_87 (
& V_18 -> V_377 ,
& V_381 , V_379 [ V_5 ] . V_12 ,
V_379 [ V_5 ] . V_383 ,
V_379 [ V_5 ] . V_385 , V_379 [ V_5 ] . V_389 ,
V_379 [ V_5 ] . V_387 ) ;
}
}
if ( V_18 -> V_377 . error ) {
F_34 ( L_52 , V_5 ) ;
return V_18 -> V_377 . error ;
}
if ( V_379 [ V_5 ] . V_394 && V_18 -> V_392 [ V_5 ] )
V_18 -> V_392 [ V_5 ] -> V_67 |= V_395 ;
}
F_88 ( & V_18 -> V_377 ) ;
return 0 ;
}
void F_89 ( struct V_17 * V_18 )
{
int V_5 ;
F_90 ( & V_18 -> V_377 ) ;
for ( V_5 = 0 ; V_5 < V_378 ; V_5 ++ )
V_18 -> V_392 [ V_5 ] = NULL ;
}
void F_91 ( struct V_17 * V_18 )
{
struct V_2 V_3 ;
V_3 . V_9 . V_10 . V_11 = V_396 ;
V_18 -> V_118 = F_1 ( & V_3 , V_92 ) ;
V_3 . V_9 . V_10 . V_11 = V_397 ;
V_18 -> V_109 = F_1 ( & V_3 , V_93 ) ;
}
