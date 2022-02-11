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
unsigned long V_38 ;
F_12 ( & V_34 -> V_39 , V_38 ) ;
V_35 = F_7 ( V_18 -> V_40 . V_29 , struct V_26 , V_30 ) ;
V_36 = F_13 ( V_35 -> V_41 , 0 ) ;
V_37 = F_14 ( V_35 -> V_41 , 0 ) ;
F_15 ( V_34 -> V_42 , V_43 , V_18 , V_36 ,
V_37 ) ;
F_16 ( & V_34 -> V_39 , V_38 ) ;
return 0 ;
}
static int F_17 ( struct V_17 * V_18 )
{
struct V_33 * V_34 = V_18 -> V_34 ;
struct V_44 * V_45 = & V_18 -> V_46 ;
struct V_26 * V_35 ;
unsigned long V_38 ;
unsigned int V_47 ;
if ( V_45 -> V_48 == V_49 ) {
F_12 ( & V_34 -> V_39 , V_38 ) ;
if ( ! F_6 ( & V_18 -> V_40 ) ) {
V_35 = F_7 ( V_18 -> V_40 . V_29 ,
struct V_26 , V_30 ) ;
F_8 ( & V_35 -> V_30 ) ;
V_18 -> V_20 -- ;
F_18 ( V_35 -> V_41 , 0 ,
F_19 ( V_34 -> V_42 , V_50 ,
V_34 ) ) ;
F_20 ( V_35 -> V_41 , V_51 ) ;
}
F_16 ( & V_34 -> V_39 , V_38 ) ;
}
if ( ! F_21 ( V_34 ) ) {
V_18 -> V_21 = V_23 ;
if ( F_3 ( V_18 ) )
F_22 ( V_18 ) ;
F_15 ( V_34 -> V_42 , V_52 , V_34 ) ;
} else {
V_47 = F_19 ( V_34 -> V_42 ,
V_53 , V_34 ) ;
if ( V_18 -> V_54 < V_47 )
V_18 -> V_54 = V_47 ;
V_18 -> V_21 = V_24 ;
}
return 0 ;
}
static int F_23 ( struct V_17 * V_18 )
{
struct V_33 * V_34 = V_18 -> V_34 ;
struct V_26 * V_35 ;
struct V_26 * V_55 ;
unsigned long V_38 ;
unsigned long V_56 , V_57 , V_36 ;
unsigned int V_37 ;
F_12 ( & V_34 -> V_39 , V_38 ) ;
V_55 = F_7 ( V_18 -> V_32 . V_29 , struct V_26 , V_30 ) ;
V_56 = F_13 ( V_55 -> V_41 , 0 ) ;
V_57 = F_13 ( V_55 -> V_41 , 1 ) ;
F_15 ( V_34 -> V_42 , V_58 , V_18 ,
V_56 , V_57 ) ;
F_16 ( & V_34 -> V_39 , V_38 ) ;
F_12 ( & V_34 -> V_39 , V_38 ) ;
V_35 = F_7 ( V_18 -> V_40 . V_29 , struct V_26 , V_30 ) ;
V_36 = F_13 ( V_35 -> V_41 , 0 ) ;
V_37 = F_14 ( V_35 -> V_41 , 0 ) ;
F_15 ( V_34 -> V_42 , V_43 , V_18 , V_36 ,
V_37 ) ;
F_16 ( & V_34 -> V_39 , V_38 ) ;
return 0 ;
}
static int F_24 ( struct V_17 * V_18 )
{
struct V_33 * V_34 = V_18 -> V_34 ;
struct V_26 * V_27 ;
unsigned long V_59 , V_60 ;
unsigned long V_61 , V_62 ;
int V_63 ;
unsigned int V_64 ;
unsigned long V_38 ;
V_63 = F_19 ( V_34 -> V_42 , V_65 , V_34 ) ;
V_64 = F_19 ( V_34 -> V_42 , V_50 , V_34 ) ;
F_4 ( 2 , L_9 , V_63 ) ;
F_4 ( 2 , L_10 , V_64 ) ;
F_4 ( 2 , L_11 ,
F_25 ( V_34 , V_66 ) ) ;
F_12 ( & V_34 -> V_39 , V_38 ) ;
if ( V_63 >= 0 ) {
F_15 ( V_34 -> V_42 , V_67 , V_18 ,
& V_59 , & V_60 ) ;
F_26 (mb_entry, &ctx->src_queue, list) {
V_61 = F_13 ( V_27 -> V_41 , 0 ) ;
V_62 = F_13 ( V_27 -> V_41 , 1 ) ;
if ( ( V_59 == V_61 ) &&
( V_60 == V_62 ) ) {
F_8 ( & V_27 -> V_30 ) ;
V_18 -> V_19 -- ;
F_20 ( V_27 -> V_41 ,
V_51 ) ;
break;
}
}
F_26 (mb_entry, &ctx->ref_queue, list) {
V_61 = F_13 ( V_27 -> V_41 , 0 ) ;
V_62 = F_13 ( V_27 -> V_41 , 1 ) ;
if ( ( V_59 == V_61 ) &&
( V_60 == V_62 ) ) {
F_8 ( & V_27 -> V_30 ) ;
V_18 -> V_31 -- ;
F_20 ( V_27 -> V_41 ,
V_51 ) ;
break;
}
}
}
if ( ( V_18 -> V_19 > 0 ) && ( V_18 -> V_21 == V_23 ) ) {
V_27 = F_7 ( V_18 -> V_32 . V_29 , struct V_26 ,
V_30 ) ;
if ( V_27 -> V_38 & V_68 ) {
F_8 ( & V_27 -> V_30 ) ;
V_18 -> V_19 -- ;
F_9 ( & V_27 -> V_30 , & V_18 -> V_28 ) ;
V_18 -> V_31 ++ ;
}
F_4 ( 2 , L_8 ,
V_18 -> V_19 , V_18 -> V_31 ) ;
}
if ( ( V_18 -> V_20 > 0 ) && ( V_64 > 0 ) ) {
V_27 = F_7 ( V_18 -> V_40 . V_29 , struct V_26 ,
V_30 ) ;
F_8 ( & V_27 -> V_30 ) ;
V_18 -> V_20 -- ;
switch ( V_63 ) {
case V_69 :
V_27 -> V_41 -> V_70 . V_38 |= V_71 ;
break;
case V_72 :
V_27 -> V_41 -> V_70 . V_38 |= V_73 ;
break;
case V_74 :
V_27 -> V_41 -> V_70 . V_38 |= V_75 ;
break;
}
F_18 ( V_27 -> V_41 , 0 , V_64 ) ;
F_20 ( V_27 -> V_41 , V_51 ) ;
}
F_16 ( & V_34 -> V_39 , V_38 ) ;
if ( ( V_18 -> V_19 == 0 ) || ( V_18 -> V_20 == 0 ) )
F_27 ( V_18 ) ;
return 0 ;
}
static int F_28 ( struct V_76 * V_76 , void * V_77 ,
struct V_78 * V_79 )
{
struct V_33 * V_34 = F_29 ( V_76 ) ;
strncpy ( V_79 -> V_80 , V_34 -> V_81 -> V_82 , sizeof( V_79 -> V_80 ) - 1 ) ;
strncpy ( V_79 -> V_83 , V_34 -> V_81 -> V_82 , sizeof( V_79 -> V_83 ) - 1 ) ;
V_79 -> V_84 [ 0 ] = 0 ;
V_79 -> V_85 = F_30 ( 1 , 0 , 0 ) ;
V_79 -> V_86 = V_87 | V_88 |
V_89 |
V_90 ;
return 0 ;
}
static int F_31 ( struct V_76 * V_76 , struct V_91 * V_3 ,
bool V_92 )
{
struct V_33 * V_34 = F_29 ( V_76 ) ;
struct V_1 * V_9 ;
int V_5 , V_93 = 0 ;
for ( V_5 = 0 ; V_5 < F_32 ( V_7 ) ; ++ V_5 ) {
if ( V_92 && V_7 [ V_5 ] . type != V_94 )
continue;
else if ( ! V_92 && V_7 [ V_5 ] . type != V_95 )
continue;
else if ( ( V_34 -> V_96 -> V_97 & V_7 [ V_5 ] . V_98 ) == 0 )
continue;
if ( V_93 == V_3 -> V_99 ) {
V_9 = & V_7 [ V_5 ] ;
F_33 ( V_3 -> V_100 , V_9 -> V_82 ,
sizeof( V_3 -> V_100 ) ) ;
V_3 -> V_11 = V_9 -> V_8 ;
return 0 ;
}
++ V_93 ;
}
return - V_101 ;
}
static int F_34 ( struct V_76 * V_76 , void * V_102 ,
struct V_91 * V_3 )
{
return F_31 ( V_76 , V_3 , false ) ;
}
static int F_35 ( struct V_76 * V_76 , void * V_103 ,
struct V_91 * V_3 )
{
return F_31 ( V_76 , V_3 , true ) ;
}
static int F_36 ( struct V_76 * V_76 , void * V_77 , struct V_2 * V_3 )
{
struct V_17 * V_18 = F_37 ( V_77 ) ;
struct V_104 * V_105 = & V_3 -> V_9 . V_10 ;
F_4 ( 2 , L_12 , V_3 -> type , V_18 -> V_21 ) ;
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
F_38 ( L_13 ) ;
return - V_101 ;
}
return 0 ;
}
static int F_39 ( struct V_76 * V_76 , void * V_77 , struct V_2 * V_3 )
{
struct V_33 * V_34 = F_29 ( V_76 ) ;
struct V_1 * V_9 ;
struct V_104 * V_105 = & V_3 -> V_9 . V_10 ;
if ( V_3 -> type == V_106 ) {
V_9 = F_1 ( V_3 , V_95 ) ;
if ( ! V_9 ) {
F_38 ( L_14 ) ;
return - V_101 ;
}
if ( V_105 -> V_113 [ 0 ] . V_116 == 0 ) {
F_38 ( L_15 ) ;
return - V_101 ;
}
if ( ( V_34 -> V_96 -> V_97 & V_9 -> V_98 ) == 0 ) {
F_38 ( L_16 ) ;
return - V_101 ;
}
V_105 -> V_113 [ 0 ] . V_114 =
V_105 -> V_113 [ 0 ] . V_116 ;
} else if ( V_3 -> type == V_117 ) {
V_9 = F_1 ( V_3 , V_94 ) ;
if ( ! V_9 ) {
F_38 ( L_14 ) ;
return - V_101 ;
}
if ( V_9 -> V_112 != V_105 -> V_112 ) {
F_38 ( L_14 ) ;
return - V_101 ;
}
if ( ( V_34 -> V_96 -> V_97 & V_9 -> V_98 ) == 0 ) {
F_38 ( L_16 ) ;
return - V_101 ;
}
F_40 ( & V_105 -> V_107 , 8 , 1920 , 1 ,
& V_105 -> V_108 , 4 , 1080 , 1 , 0 ) ;
} else {
F_38 ( L_13 ) ;
return - V_101 ;
}
return 0 ;
}
static int F_41 ( struct V_76 * V_76 , void * V_77 , struct V_2 * V_3 )
{
struct V_33 * V_34 = F_29 ( V_76 ) ;
struct V_17 * V_18 = F_37 ( V_77 ) ;
struct V_104 * V_105 = & V_3 -> V_9 . V_10 ;
int V_124 = 0 ;
V_124 = F_39 ( V_76 , V_77 , V_3 ) ;
if ( V_124 )
return V_124 ;
if ( V_18 -> V_125 . V_126 || V_18 -> V_127 . V_126 ) {
F_42 ( & V_34 -> V_128 , L_17 , V_129 ) ;
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
V_124 = F_43 ( V_34 , V_18 ) ;
} else if ( V_3 -> type == V_117 ) {
V_18 -> V_120 = F_1 ( V_3 , V_94 ) ;
V_18 -> V_118 = V_105 -> V_107 ;
V_18 -> V_119 = V_105 -> V_108 ;
F_4 ( 2 , L_18 , V_18 -> V_120 -> V_132 ) ;
F_4 ( 2 , L_19 ,
V_105 -> V_107 , V_105 -> V_108 ,
V_18 -> V_118 , V_18 -> V_119 ) ;
F_15 ( V_34 -> V_42 , V_136 , V_18 ) ;
V_105 -> V_113 [ 0 ] . V_116 = V_18 -> V_122 ;
V_105 -> V_113 [ 0 ] . V_114 = V_18 -> V_121 ;
V_105 -> V_113 [ 1 ] . V_116 = V_18 -> V_123 ;
V_105 -> V_113 [ 1 ] . V_114 = V_18 -> V_121 ;
V_18 -> V_137 = 0 ;
V_18 -> V_138 = V_135 ;
} else {
F_38 ( L_13 ) ;
V_124 = - V_101 ;
}
V_92:
F_44 () ;
return V_124 ;
}
static int F_45 ( struct V_76 * V_76 , void * V_77 ,
struct V_139 * V_140 )
{
struct V_33 * V_34 = F_29 ( V_76 ) ;
struct V_17 * V_18 = F_37 ( V_77 ) ;
int V_124 = 0 ;
if ( ( V_140 -> V_141 != V_142 ) &&
( V_140 -> V_141 != V_143 ) )
return - V_101 ;
if ( V_140 -> type == V_106 ) {
if ( V_18 -> V_134 != V_135 ) {
F_38 ( L_20 ,
V_18 -> V_134 ) ;
return - V_101 ;
}
V_124 = F_46 ( & V_18 -> V_127 , V_140 ) ;
if ( V_124 != 0 ) {
F_38 ( L_21 ) ;
return V_124 ;
}
V_18 -> V_134 = V_144 ;
V_124 = F_19 ( V_18 -> V_34 -> V_42 ,
V_145 , V_18 ) ;
if ( V_124 ) {
F_38 ( L_22 ) ;
V_140 -> V_146 = 0 ;
V_124 = F_46 ( & V_18 -> V_127 , V_140 ) ;
return - V_147 ;
}
} else if ( V_140 -> type == V_117 ) {
if ( V_18 -> V_138 != V_135 ) {
F_38 ( L_23 ,
V_18 -> V_138 ) ;
return - V_101 ;
}
if ( F_21 ( V_34 ) ) {
if ( V_18 -> V_54 &&
( V_140 -> V_146 < V_18 -> V_54 ) ) {
V_140 -> V_146 = V_18 -> V_54 ;
F_4 ( 2 , L_24 ,
V_18 -> V_54 ) ;
} else {
V_18 -> V_54 = V_140 -> V_146 ;
}
}
V_124 = F_46 ( & V_18 -> V_125 , V_140 ) ;
if ( V_124 != 0 ) {
F_38 ( L_25 ) ;
return V_124 ;
}
V_18 -> V_138 = V_144 ;
} else {
F_38 ( L_13 ) ;
return - V_101 ;
}
return V_124 ;
}
static int F_47 ( struct V_76 * V_76 , void * V_77 ,
struct V_148 * V_149 )
{
struct V_17 * V_18 = F_37 ( V_77 ) ;
int V_124 = 0 ;
if ( ( V_149 -> V_141 != V_142 ) &&
( V_149 -> V_141 != V_143 ) )
return - V_101 ;
if ( V_149 -> type == V_106 ) {
if ( V_18 -> V_21 != V_22 ) {
F_38 ( L_26 , V_18 -> V_21 ) ;
return - V_101 ;
}
V_124 = F_48 ( & V_18 -> V_127 , V_149 ) ;
if ( V_124 != 0 ) {
F_38 ( L_27 ) ;
return V_124 ;
}
V_149 -> V_150 . V_151 [ 0 ] . V_150 . V_152 += V_153 ;
} else if ( V_149 -> type == V_117 ) {
V_124 = F_48 ( & V_18 -> V_125 , V_149 ) ;
if ( V_124 != 0 ) {
F_38 ( L_28 ) ;
return V_124 ;
}
} else {
F_38 ( L_13 ) ;
return - V_101 ;
}
return V_124 ;
}
static int F_49 ( struct V_76 * V_76 , void * V_77 , struct V_148 * V_149 )
{
struct V_17 * V_18 = F_37 ( V_77 ) ;
if ( V_18 -> V_21 == V_154 ) {
F_38 ( L_29 ) ;
return - V_155 ;
}
if ( V_149 -> type == V_117 ) {
if ( V_18 -> V_21 == V_25 ) {
F_38 ( L_30 ) ;
return - V_155 ;
}
return F_50 ( & V_18 -> V_125 , V_149 ) ;
} else if ( V_149 -> type == V_106 ) {
return F_50 ( & V_18 -> V_127 , V_149 ) ;
}
return - V_101 ;
}
static int F_51 ( struct V_76 * V_76 , void * V_77 , struct V_148 * V_149 )
{
const struct V_156 V_157 = {
. type = V_158
} ;
struct V_17 * V_18 = F_37 ( V_77 ) ;
int V_124 ;
if ( V_18 -> V_21 == V_154 ) {
F_38 ( L_31 ) ;
return - V_155 ;
}
if ( V_149 -> type == V_117 ) {
V_124 = F_52 ( & V_18 -> V_125 , V_149 , V_76 -> V_159 & V_160 ) ;
} else if ( V_149 -> type == V_106 ) {
V_124 = F_52 ( & V_18 -> V_127 , V_149 , V_76 -> V_159 & V_160 ) ;
if ( V_124 == 0 && V_18 -> V_21 == V_161
&& F_6 ( & V_18 -> V_127 . V_162 ) )
F_53 ( & V_18 -> V_163 , & V_157 ) ;
} else {
V_124 = - V_101 ;
}
return V_124 ;
}
static int F_54 ( struct V_76 * V_76 , void * V_77 ,
struct V_164 * V_165 )
{
struct V_17 * V_18 = F_37 ( V_77 ) ;
if ( V_165 -> type == V_117 )
return F_55 ( & V_18 -> V_125 , V_165 ) ;
if ( V_165 -> type == V_106 )
return F_55 ( & V_18 -> V_127 , V_165 ) ;
return - V_101 ;
}
static int F_56 ( struct V_76 * V_76 , void * V_77 ,
enum V_166 type )
{
struct V_17 * V_18 = F_37 ( V_77 ) ;
if ( type == V_117 )
return F_57 ( & V_18 -> V_125 , type ) ;
else if ( type == V_106 )
return F_57 ( & V_18 -> V_127 , type ) ;
return - V_101 ;
}
static int F_58 ( struct V_76 * V_76 , void * V_77 ,
enum V_166 type )
{
struct V_17 * V_18 = F_37 ( V_77 ) ;
if ( type == V_117 )
return F_59 ( & V_18 -> V_125 , type ) ;
else if ( type == V_106 )
return F_59 ( & V_18 -> V_127 , type ) ;
return - V_101 ;
}
static inline int F_60 ( enum V_167 V_168 )
{
static unsigned int V_4 [ V_169 + 1 ] = {
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
return V_4 [ V_168 ] ;
}
static inline int F_61 ( enum V_170 V_168 )
{
static unsigned int V_4 [ V_171 + 1 ] = {
0 ,
9 ,
1 ,
2 ,
3 ,
7 ,
4 ,
5 ,
} ;
return V_4 [ V_168 ] ;
}
static inline int F_62 ( enum V_172 V_173 )
{
static unsigned int V_4 [ V_174 + 1 ] = {
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
return V_4 [ V_173 ] ;
}
static int F_63 ( struct V_175 * V_176 )
{
struct V_17 * V_18 = F_64 ( V_176 ) ;
struct V_33 * V_34 = V_18 -> V_34 ;
struct V_44 * V_45 = & V_18 -> V_46 ;
int V_124 = 0 ;
switch ( V_176 -> V_12 ) {
case V_177 :
V_45 -> V_178 = V_176 -> V_179 ;
break;
case V_180 :
V_45 -> V_181 = V_176 -> V_179 ;
break;
case V_182 :
V_45 -> V_183 = V_176 -> V_179 ;
break;
case V_184 :
V_45 -> V_185 = V_176 -> V_179 * 8 ;
break;
case V_186 :
V_45 -> V_187 = V_176 -> V_179 ;
break;
case V_188 :
V_45 -> V_189 = V_176 -> V_179 ;
break;
case V_190 :
V_45 -> V_191 = ( V_176 -> V_179 >> 16 ) & 0xff ;
V_45 -> V_192 = ( V_176 -> V_179 >> 8 ) & 0xff ;
V_45 -> V_193 = ( V_176 -> V_179 >> 0 ) & 0xff ;
break;
case V_194 :
V_45 -> V_195 = V_176 -> V_179 ;
break;
case V_196 :
V_45 -> V_197 = V_176 -> V_179 ;
break;
case V_198 :
V_45 -> V_199 = V_176 -> V_179 ;
break;
case V_16 :
V_18 -> V_200 = V_176 -> V_179 ;
break;
case V_201 :
V_45 -> V_202 = V_176 -> V_179 ;
break;
case V_203 :
V_45 -> V_204 = V_176 -> V_179 ;
break;
case V_205 :
V_45 -> V_206 = V_176 -> V_179 ;
break;
case V_207 :
V_45 -> V_208 . V_209 . V_210 = V_176 -> V_179 ;
break;
case V_211 :
V_45 -> V_48 = V_176 -> V_179 ;
break;
case V_15 :
V_45 -> V_212 = V_176 -> V_179 ;
break;
case V_213 :
V_45 -> V_214 = V_176 -> V_179 ;
break;
case V_215 :
V_45 -> V_216 = V_176 -> V_179 ;
break;
case V_217 :
switch ( V_176 -> V_179 ) {
case V_218 :
V_45 -> V_208 . V_209 . V_219 =
V_220 ;
break;
case V_221 :
V_45 -> V_208 . V_209 . V_219 =
V_222 ;
break;
case V_223 :
V_45 -> V_208 . V_209 . V_219 =
V_224 ;
break;
case V_225 :
if ( F_21 ( V_34 ) )
V_45 -> V_208 . V_209 . V_219 =
V_226 ;
else
V_124 = - V_101 ;
break;
default:
V_124 = - V_101 ;
}
break;
case V_227 :
V_45 -> V_208 . V_209 . V_228 = V_176 -> V_179 ;
V_45 -> V_208 . V_209 . V_229 = F_60 ( V_176 -> V_179 ) ;
if ( V_45 -> V_208 . V_209 . V_229 < 0 ) {
F_38 ( L_32 ) ;
V_124 = V_45 -> V_208 . V_209 . V_229 ;
}
break;
case V_230 :
V_45 -> V_208 . V_231 . V_228 = V_176 -> V_179 ;
V_45 -> V_208 . V_231 . V_229 = F_61 ( V_176 -> V_179 ) ;
if ( V_45 -> V_208 . V_231 . V_229 < 0 ) {
F_38 ( L_32 ) ;
V_124 = V_45 -> V_208 . V_231 . V_229 ;
}
break;
case V_232 :
V_45 -> V_208 . V_209 . V_233 = V_176 -> V_179 ;
break;
case V_234 :
V_45 -> V_208 . V_209 . V_235 = V_176 -> V_179 ;
break;
case V_236 :
V_45 -> V_208 . V_209 . V_237 = V_176 -> V_179 ;
break;
case V_238 :
V_45 -> V_208 . V_209 . V_239 = V_176 -> V_179 ;
break;
case V_240 :
V_45 -> V_208 . V_209 . V_241 = V_176 -> V_179 ;
break;
case V_242 :
V_45 -> V_208 . V_209 . V_243 = V_176 -> V_179 ;
break;
case V_244 :
V_45 -> V_245 = V_176 -> V_179 ;
break;
case V_246 :
V_45 -> V_208 . V_209 . V_247 = V_176 -> V_179 ;
break;
case V_248 :
V_45 -> V_208 . V_209 . V_249 = V_176 -> V_179 ;
break;
case V_250 :
V_45 -> V_208 . V_209 . V_251 = V_176 -> V_179 ;
break;
case V_252 :
V_45 -> V_208 . V_209 . V_253 = V_176 -> V_179 ;
break;
case V_254 :
V_45 -> V_208 . V_209 . V_255 = V_176 -> V_179 ;
break;
case V_256 :
case V_257 :
V_45 -> V_208 . V_231 . V_247 = V_176 -> V_179 ;
break;
case V_258 :
case V_259 :
V_45 -> V_208 . V_231 . V_249 = V_176 -> V_179 ;
break;
case V_260 :
case V_261 :
V_45 -> V_208 . V_231 . V_251 = V_176 -> V_179 ;
break;
case V_262 :
case V_263 :
V_45 -> V_208 . V_231 . V_253 = V_176 -> V_179 ;
break;
case V_264 :
case V_265 :
V_45 -> V_208 . V_231 . V_255 = V_176 -> V_179 ;
break;
case V_266 :
V_45 -> V_208 . V_209 . V_267 = V_176 -> V_179 ;
break;
case V_268 :
V_45 -> V_208 . V_209 . V_269 = V_176 -> V_179 ;
break;
case V_270 :
V_45 -> V_208 . V_209 . V_271 = V_176 -> V_179 ;
break;
case V_272 :
V_45 -> V_208 . V_209 . V_273 = V_176 -> V_179 ;
break;
case V_274 :
V_45 -> V_208 . V_209 . V_275 = V_176 -> V_179 ;
break;
case V_276 :
V_45 -> V_208 . V_209 . F_62 = F_62 ( V_176 -> V_179 ) ;
break;
case V_277 :
V_45 -> V_208 . V_209 . V_278 = V_176 -> V_179 ;
break;
case V_279 :
V_45 -> V_208 . V_209 . V_280 = V_176 -> V_179 ;
break;
case V_281 :
V_45 -> V_208 . V_209 . V_282 = ! V_176 -> V_179 ;
break;
case V_283 :
V_45 -> V_208 . V_209 . V_284 = V_176 -> V_179 ;
break;
case V_285 :
switch ( V_176 -> V_179 ) {
case V_286 :
V_45 -> V_208 . V_231 . V_219 =
V_287 ;
break;
case V_288 :
V_45 -> V_208 . V_231 . V_219 =
V_289 ;
break;
default:
V_124 = - V_101 ;
}
break;
case V_290 :
V_45 -> V_208 . V_231 . V_291 = V_176 -> V_179 ;
break;
case V_292 :
V_45 -> V_208 . V_293 . V_294 = V_176 -> V_179 ;
break;
case V_295 :
V_45 -> V_208 . V_293 . V_296 = V_176 -> V_179 ;
break;
case V_297 :
V_45 -> V_208 . V_293 . V_298 = V_176 -> V_179 ;
break;
case V_299 :
V_45 -> V_208 . V_293 . V_300 = V_176 -> V_179 ;
break;
case V_301 :
V_45 -> V_208 . V_293 . V_302 = V_176 -> V_179 ;
break;
case V_303 :
V_45 -> V_208 . V_293 . V_304 = V_176 -> V_179 ;
break;
case V_305 :
V_45 -> V_208 . V_293 . V_306 = V_176 -> V_179 ;
break;
case V_307 :
V_45 -> V_208 . V_293 . V_249 = V_176 -> V_179 ;
break;
case V_308 :
V_45 -> V_208 . V_293 . V_251 = V_176 -> V_179 ;
break;
case V_309 :
V_45 -> V_208 . V_293 . V_247 = V_176 -> V_179 ;
break;
case V_310 :
V_45 -> V_208 . V_293 . V_253 = V_176 -> V_179 ;
break;
case V_311 :
V_45 -> V_208 . V_293 . V_219 = V_176 -> V_179 ;
break;
default:
F_42 ( & V_34 -> V_128 , L_33 ,
V_176 -> V_12 , V_176 -> V_179 ) ;
V_124 = - V_101 ;
}
return V_124 ;
}
static int F_65 ( struct V_76 * V_76 , void * V_77 ,
struct V_312 * V_313 )
{
struct V_17 * V_18 = F_37 ( V_77 ) ;
if ( V_313 -> type == V_117 ) {
V_18 -> V_46 . V_314 =
V_313 -> V_315 . V_316 . V_317 . V_318 ;
V_18 -> V_46 . V_319 =
V_313 -> V_315 . V_316 . V_317 . V_320 ;
} else {
F_38 ( L_34 ) ;
return - V_101 ;
}
return 0 ;
}
static int F_66 ( struct V_76 * V_76 , void * V_77 ,
struct V_312 * V_313 )
{
struct V_17 * V_18 = F_37 ( V_77 ) ;
if ( V_313 -> type == V_321 ) {
V_313 -> V_315 . V_316 . V_317 . V_318 =
V_18 -> V_46 . V_314 ;
V_313 -> V_315 . V_316 . V_317 . V_320 =
V_18 -> V_46 . V_319 ;
} else {
F_38 ( L_34 ) ;
return - V_101 ;
}
return 0 ;
}
static int F_67 ( struct V_76 * V_76 , void * V_77 ,
struct V_322 * V_323 )
{
struct V_17 * V_18 = F_37 ( V_77 ) ;
struct V_33 * V_34 = V_18 -> V_34 ;
struct V_26 * V_149 ;
unsigned long V_38 ;
switch ( V_323 -> V_323 ) {
case V_324 :
if ( V_323 -> V_38 != 0 )
return - V_101 ;
if ( ! V_18 -> V_125 . V_126 )
return - V_101 ;
F_12 ( & V_34 -> V_39 , V_38 ) ;
if ( F_6 ( & V_18 -> V_32 ) ) {
F_4 ( 2 , L_35 ) ;
V_18 -> V_21 = V_25 ;
if ( F_3 ( V_18 ) )
F_22 ( V_18 ) ;
F_16 ( & V_34 -> V_39 , V_38 ) ;
F_15 ( V_34 -> V_42 , V_52 , V_34 ) ;
} else {
F_4 ( 2 , L_36 ) ;
V_149 = F_7 ( V_18 -> V_32 . V_325 ,
struct V_26 , V_30 ) ;
if ( V_149 -> V_38 & V_68 )
V_18 -> V_21 = V_25 ;
else
V_149 -> V_38 |= V_326 ;
F_16 ( & V_34 -> V_39 , V_38 ) ;
}
break;
default:
return - V_101 ;
}
return 0 ;
}
static int F_68 ( struct V_327 * V_163 ,
const struct V_328 * V_329 )
{
switch ( V_329 -> type ) {
case V_158 :
return F_69 ( V_163 , V_329 , 2 , NULL ) ;
default:
return - V_101 ;
}
}
static int F_70 ( struct V_1 * V_9 , struct V_330 * V_331 )
{
int V_5 ;
if ( ! V_9 )
return - V_101 ;
if ( V_9 -> V_112 != V_331 -> V_112 ) {
F_38 ( L_37 ) ;
return - V_101 ;
}
for ( V_5 = 0 ; V_5 < V_9 -> V_112 ; V_5 ++ ) {
T_2 V_332 = F_13 ( V_331 , V_5 ) ;
if ( ! V_332 ) {
F_38 ( L_38 ) ;
return - V_101 ;
}
F_4 ( 2 , L_39 ,
V_331 -> V_70 . V_99 , V_5 , & V_332 ) ;
}
return 0 ;
}
static int F_71 ( struct V_333 * V_334 ,
const struct V_2 * V_9 ,
unsigned int * V_335 , unsigned int * V_336 ,
unsigned int V_337 [] , void * V_338 [] )
{
struct V_17 * V_18 = F_37 ( V_334 -> V_339 ) ;
struct V_33 * V_34 = V_18 -> V_34 ;
if ( V_18 -> V_21 != V_22 ) {
F_38 ( L_40 , V_18 -> V_21 ) ;
return - V_101 ;
}
if ( V_334 -> type == V_106 ) {
if ( V_18 -> V_111 )
* V_336 = V_18 -> V_111 -> V_112 ;
else
* V_336 = V_340 ;
if ( * V_335 < 1 )
* V_335 = 1 ;
if ( * V_335 > V_341 )
* V_335 = V_341 ;
V_337 [ 0 ] = V_18 -> V_115 ;
V_338 [ 0 ] = V_18 -> V_34 -> V_342 [ V_343 ] ;
} else if ( V_334 -> type == V_117 ) {
if ( V_18 -> V_120 )
* V_336 = V_18 -> V_120 -> V_112 ;
else
* V_336 = V_344 ;
if ( * V_335 < 1 )
* V_335 = 1 ;
if ( * V_335 > V_341 )
* V_335 = V_341 ;
V_337 [ 0 ] = V_18 -> V_122 ;
V_337 [ 1 ] = V_18 -> V_123 ;
if ( F_21 ( V_34 ) ) {
V_338 [ 0 ] =
V_18 -> V_34 -> V_342 [ V_343 ] ;
V_338 [ 1 ] =
V_18 -> V_34 -> V_342 [ V_343 ] ;
} else {
V_338 [ 0 ] =
V_18 -> V_34 -> V_342 [ V_345 ] ;
V_338 [ 1 ] =
V_18 -> V_34 -> V_342 [ V_345 ] ;
}
} else {
F_38 ( L_41 , V_334 -> type ) ;
return - V_101 ;
}
return 0 ;
}
static void F_72 ( struct V_333 * V_346 )
{
struct V_17 * V_18 = F_37 ( V_346 -> V_339 ) ;
struct V_33 * V_34 = V_18 -> V_34 ;
F_73 ( & V_34 -> V_347 ) ;
}
static void F_74 ( struct V_333 * V_346 )
{
struct V_17 * V_18 = F_37 ( V_346 -> V_339 ) ;
struct V_33 * V_34 = V_18 -> V_34 ;
F_75 ( & V_34 -> V_347 ) ;
}
static int F_76 ( struct V_330 * V_331 )
{
struct V_333 * V_334 = V_331 -> V_333 ;
struct V_17 * V_18 = F_37 ( V_334 -> V_339 ) ;
unsigned int V_5 ;
int V_124 ;
if ( V_334 -> type == V_106 ) {
V_124 = F_70 ( V_18 -> V_111 , V_331 ) ;
if ( V_124 < 0 )
return V_124 ;
V_5 = V_331 -> V_70 . V_99 ;
V_18 -> V_348 [ V_5 ] . V_41 = V_331 ;
V_18 -> V_348 [ V_5 ] . V_349 . V_350 =
F_13 ( V_331 , 0 ) ;
V_18 -> V_133 ++ ;
} else if ( V_334 -> type == V_117 ) {
V_124 = F_70 ( V_18 -> V_120 , V_331 ) ;
if ( V_124 < 0 )
return V_124 ;
V_5 = V_331 -> V_70 . V_99 ;
V_18 -> V_351 [ V_5 ] . V_41 = V_331 ;
V_18 -> V_351 [ V_5 ] . V_349 . V_352 . V_353 =
F_13 ( V_331 , 0 ) ;
V_18 -> V_351 [ V_5 ] . V_349 . V_352 . V_354 =
F_13 ( V_331 , 1 ) ;
V_18 -> V_137 ++ ;
} else {
F_38 ( L_41 , V_334 -> type ) ;
return - V_101 ;
}
return 0 ;
}
static int F_77 ( struct V_330 * V_331 )
{
struct V_333 * V_334 = V_331 -> V_333 ;
struct V_17 * V_18 = F_37 ( V_334 -> V_339 ) ;
int V_124 ;
if ( V_334 -> type == V_106 ) {
V_124 = F_70 ( V_18 -> V_111 , V_331 ) ;
if ( V_124 < 0 )
return V_124 ;
F_4 ( 2 , L_42 ,
F_14 ( V_331 , 0 ) , V_18 -> V_115 ) ;
if ( F_14 ( V_331 , 0 ) < V_18 -> V_115 ) {
F_38 ( L_43 ) ;
return - V_101 ;
}
} else if ( V_334 -> type == V_117 ) {
V_124 = F_70 ( V_18 -> V_120 , V_331 ) ;
if ( V_124 < 0 )
return V_124 ;
F_4 ( 2 , L_44 ,
F_14 ( V_331 , 0 ) , V_18 -> V_122 ) ;
F_4 ( 2 , L_45 ,
F_14 ( V_331 , 1 ) , V_18 -> V_123 ) ;
if ( F_14 ( V_331 , 0 ) < V_18 -> V_122 ||
F_14 ( V_331 , 1 ) < V_18 -> V_123 ) {
F_38 ( L_46 ) ;
return - V_101 ;
}
} else {
F_38 ( L_41 , V_334 -> type ) ;
return - V_101 ;
}
return 0 ;
}
static int F_78 ( struct V_333 * V_346 , unsigned int V_146 )
{
struct V_17 * V_18 = F_37 ( V_346 -> V_339 ) ;
struct V_33 * V_34 = V_18 -> V_34 ;
if ( F_21 ( V_34 ) &&
( V_346 -> type == V_106 ) ) {
if ( ( V_18 -> V_21 == V_22 ) &&
( V_34 -> V_355 == V_18 -> V_356 ) && V_34 -> V_357 ) {
F_79 ( V_18 ,
V_358 ,
0 ) ;
}
if ( V_18 -> V_137 < V_18 -> V_54 ) {
F_38 ( L_47 ,
V_18 -> V_54 ) ;
return - V_359 ;
}
}
if ( F_3 ( V_18 ) )
F_22 ( V_18 ) ;
F_15 ( V_34 -> V_42 , V_52 , V_34 ) ;
return 0 ;
}
static void F_80 ( struct V_333 * V_346 )
{
unsigned long V_38 ;
struct V_17 * V_18 = F_37 ( V_346 -> V_339 ) ;
struct V_33 * V_34 = V_18 -> V_34 ;
if ( ( V_18 -> V_21 == V_25 ||
V_18 -> V_21 == V_23 ) &&
V_34 -> V_355 == V_18 -> V_356 && V_34 -> V_357 ) {
V_18 -> V_21 = V_360 ;
F_79 ( V_18 , V_361 ,
0 ) ;
}
V_18 -> V_21 = V_161 ;
F_12 ( & V_34 -> V_39 , V_38 ) ;
if ( V_346 -> type == V_106 ) {
F_15 ( V_34 -> V_42 , V_362 ,
& V_18 -> V_40 , & V_18 -> V_127 ) ;
F_10 ( & V_18 -> V_40 ) ;
V_18 -> V_20 = 0 ;
}
if ( V_346 -> type == V_117 ) {
F_5 ( V_18 ) ;
F_15 ( V_34 -> V_42 , V_362 , & V_18 -> V_32 ,
& V_18 -> V_125 ) ;
F_10 ( & V_18 -> V_32 ) ;
V_18 -> V_19 = 0 ;
}
F_16 ( & V_34 -> V_39 , V_38 ) ;
}
static void F_81 ( struct V_330 * V_331 )
{
struct V_333 * V_334 = V_331 -> V_333 ;
struct V_17 * V_18 = F_37 ( V_334 -> V_339 ) ;
struct V_33 * V_34 = V_18 -> V_34 ;
unsigned long V_38 ;
struct V_26 * V_363 ;
if ( V_18 -> V_21 == V_154 ) {
F_20 ( V_331 , V_364 ) ;
F_5 ( V_18 ) ;
return;
}
if ( V_334 -> type == V_106 ) {
V_363 = & V_18 -> V_348 [ V_331 -> V_70 . V_99 ] ;
V_363 -> V_38 &= ~ V_68 ;
F_12 ( & V_34 -> V_39 , V_38 ) ;
F_9 ( & V_363 -> V_30 , & V_18 -> V_40 ) ;
V_18 -> V_20 ++ ;
F_16 ( & V_34 -> V_39 , V_38 ) ;
} else if ( V_334 -> type == V_117 ) {
V_363 = & V_18 -> V_351 [ V_331 -> V_70 . V_99 ] ;
V_363 -> V_38 &= ~ V_68 ;
F_12 ( & V_34 -> V_39 , V_38 ) ;
F_9 ( & V_363 -> V_30 , & V_18 -> V_32 ) ;
V_18 -> V_19 ++ ;
F_16 ( & V_34 -> V_39 , V_38 ) ;
} else {
F_38 ( L_48 , V_334 -> type ) ;
}
if ( F_3 ( V_18 ) )
F_22 ( V_18 ) ;
F_15 ( V_34 -> V_42 , V_52 , V_34 ) ;
}
struct V_365 * F_82 ( void )
{
return & V_366 ;
}
struct V_367 * F_83 ( void )
{
return & V_368 ;
}
const struct V_369 * F_84 ( void )
{
return & V_370 ;
}
int F_85 ( struct V_17 * V_18 )
{
struct V_371 V_372 ;
int V_5 ;
F_86 ( & V_18 -> V_373 , V_374 ) ;
if ( V_18 -> V_373 . error ) {
F_38 ( L_49 ) ;
return V_18 -> V_373 . error ;
}
for ( V_5 = 0 ; V_5 < V_374 ; V_5 ++ ) {
if ( F_87 ( V_375 [ V_5 ] . V_12 ) ) {
memset ( & V_372 , 0 , sizeof( struct V_371 ) ) ;
V_372 . V_376 = & V_377 ;
V_372 . V_12 = V_375 [ V_5 ] . V_12 ;
V_372 . V_378 = V_375 [ V_5 ] . V_379 ;
V_372 . V_380 = V_375 [ V_5 ] . V_381 ;
V_372 . V_382 = V_375 [ V_5 ] . V_383 ;
V_372 . V_82 = V_375 [ V_5 ] . V_82 ;
V_372 . type = V_375 [ V_5 ] . type ;
V_372 . V_38 = 0 ;
if ( V_372 . type == V_384 ) {
V_372 . V_385 = 0 ;
V_372 . V_386 = V_372 . V_386 ;
V_372 . V_387 = F_2 ( V_372 . V_12 ) ;
} else {
V_372 . V_385 = V_375 [ V_5 ] . V_385 ;
V_372 . V_386 = 0 ;
}
V_18 -> V_388 [ V_5 ] = F_88 ( & V_18 -> V_373 ,
& V_372 , NULL ) ;
} else {
if ( ( V_375 [ V_5 ] . type == V_384 ) ||
( V_375 [ V_5 ] . type ==
V_389 ) ) {
V_18 -> V_388 [ V_5 ] = F_89 (
& V_18 -> V_373 ,
& V_377 , V_375 [ V_5 ] . V_12 ,
V_375 [ V_5 ] . V_381 , 0 ,
V_375 [ V_5 ] . V_383 ) ;
} else {
V_18 -> V_388 [ V_5 ] = F_90 (
& V_18 -> V_373 ,
& V_377 , V_375 [ V_5 ] . V_12 ,
V_375 [ V_5 ] . V_379 ,
V_375 [ V_5 ] . V_381 , V_375 [ V_5 ] . V_385 ,
V_375 [ V_5 ] . V_383 ) ;
}
}
if ( V_18 -> V_373 . error ) {
F_38 ( L_50 , V_5 ) ;
return V_18 -> V_373 . error ;
}
if ( V_375 [ V_5 ] . V_390 && V_18 -> V_388 [ V_5 ] )
V_18 -> V_388 [ V_5 ] -> V_38 |= V_391 ;
}
F_91 ( & V_18 -> V_373 ) ;
return 0 ;
}
void F_92 ( struct V_17 * V_18 )
{
int V_5 ;
F_93 ( & V_18 -> V_373 ) ;
for ( V_5 = 0 ; V_5 < V_374 ; V_5 ++ )
V_18 -> V_388 [ V_5 ] = NULL ;
}
void F_94 ( struct V_17 * V_18 )
{
struct V_2 V_3 ;
V_3 . V_9 . V_10 . V_11 = V_392 ;
V_18 -> V_120 = F_1 ( & V_3 , V_94 ) ;
V_3 . V_9 . V_10 . V_11 = V_393 ;
V_18 -> V_111 = F_1 ( & V_3 , V_95 ) ;
}
