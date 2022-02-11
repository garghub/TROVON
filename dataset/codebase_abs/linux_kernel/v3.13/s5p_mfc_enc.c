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
unsigned long V_28 , V_29 ;
while ( ! F_6 ( & V_18 -> V_30 ) ) {
V_27 = F_7 ( ( & V_18 -> V_30 ) -> V_31 ,
struct V_26 , V_32 ) ;
V_28 = F_8 ( V_27 -> V_33 , 0 ) ;
V_29 = F_8 ( V_27 -> V_33 , 1 ) ;
F_9 ( & V_27 -> V_32 ) ;
V_18 -> V_34 -- ;
F_10 ( & V_27 -> V_32 , & V_18 -> V_35 ) ;
V_18 -> V_19 ++ ;
}
F_4 ( 2 , L_8 ,
V_18 -> V_19 , V_18 -> V_34 ) ;
F_11 ( & V_18 -> V_30 ) ;
V_18 -> V_34 = 0 ;
}
static int F_12 ( struct V_17 * V_18 )
{
struct V_36 * V_37 = V_18 -> V_37 ;
struct V_26 * V_38 ;
unsigned long V_39 ;
unsigned int V_40 ;
unsigned long V_41 ;
F_13 ( & V_37 -> V_42 , V_41 ) ;
V_38 = F_7 ( V_18 -> V_43 . V_31 , struct V_26 , V_32 ) ;
V_39 = F_8 ( V_38 -> V_33 , 0 ) ;
V_40 = F_14 ( V_38 -> V_33 , 0 ) ;
F_15 ( V_37 -> V_44 , V_45 , V_18 , V_39 ,
V_40 ) ;
F_16 ( & V_37 -> V_42 , V_41 ) ;
return 0 ;
}
static int F_17 ( struct V_17 * V_18 )
{
struct V_36 * V_37 = V_18 -> V_37 ;
struct V_46 * V_47 = & V_18 -> V_48 ;
struct V_26 * V_38 ;
unsigned long V_41 ;
unsigned int V_49 ;
if ( V_47 -> V_50 == V_51 ) {
F_13 ( & V_37 -> V_42 , V_41 ) ;
V_38 = F_7 ( V_18 -> V_43 . V_31 ,
struct V_26 , V_32 ) ;
F_9 ( & V_38 -> V_32 ) ;
V_18 -> V_20 -- ;
F_18 ( V_38 -> V_33 , 0 ,
F_15 ( V_37 -> V_44 , V_52 , V_37 ) ) ;
F_19 ( V_38 -> V_33 , V_53 ) ;
F_16 ( & V_37 -> V_42 , V_41 ) ;
}
if ( ! F_20 ( V_37 ) ) {
V_18 -> V_21 = V_23 ;
if ( F_3 ( V_18 ) )
F_21 ( V_18 ) ;
F_15 ( V_37 -> V_44 , V_54 , V_37 ) ;
} else {
V_49 = F_15 ( V_37 -> V_44 ,
V_55 , V_37 ) ;
if ( V_18 -> V_56 < V_49 )
V_18 -> V_56 = V_49 ;
V_18 -> V_21 = V_24 ;
}
return 0 ;
}
static int F_22 ( struct V_17 * V_18 )
{
struct V_36 * V_37 = V_18 -> V_37 ;
struct V_26 * V_38 ;
struct V_26 * V_57 ;
unsigned long V_41 ;
unsigned long V_58 , V_59 , V_39 ;
unsigned int V_40 ;
F_13 ( & V_37 -> V_42 , V_41 ) ;
V_57 = F_7 ( V_18 -> V_35 . V_31 , struct V_26 , V_32 ) ;
V_58 = F_8 ( V_57 -> V_33 , 0 ) ;
V_59 = F_8 ( V_57 -> V_33 , 1 ) ;
F_15 ( V_37 -> V_44 , V_60 , V_18 , V_58 ,
V_59 ) ;
F_16 ( & V_37 -> V_42 , V_41 ) ;
F_13 ( & V_37 -> V_42 , V_41 ) ;
V_38 = F_7 ( V_18 -> V_43 . V_31 , struct V_26 , V_32 ) ;
V_39 = F_8 ( V_38 -> V_33 , 0 ) ;
V_40 = F_14 ( V_38 -> V_33 , 0 ) ;
F_15 ( V_37 -> V_44 , V_45 , V_18 , V_39 ,
V_40 ) ;
F_16 ( & V_37 -> V_42 , V_41 ) ;
return 0 ;
}
static int F_23 ( struct V_17 * V_18 )
{
struct V_36 * V_37 = V_18 -> V_37 ;
struct V_26 * V_27 ;
unsigned long V_61 , V_62 ;
unsigned long V_28 , V_29 ;
int V_63 ;
unsigned int V_64 ;
unsigned long V_41 ;
V_63 = F_15 ( V_37 -> V_44 , V_65 , V_37 ) ;
V_64 = F_15 ( V_37 -> V_44 , V_52 , V_37 ) ;
F_4 ( 2 , L_9 , V_63 ) ;
F_4 ( 2 , L_10 , V_64 ) ;
F_4 ( 2 , L_11 ,
F_24 ( V_37 , V_66 ) ) ;
F_13 ( & V_37 -> V_42 , V_41 ) ;
if ( V_63 >= 0 ) {
F_15 ( V_37 -> V_44 , V_67 , V_18 ,
& V_61 , & V_62 ) ;
F_25 (mb_entry, &ctx->src_queue, list) {
V_28 = F_8 ( V_27 -> V_33 , 0 ) ;
V_29 = F_8 ( V_27 -> V_33 , 1 ) ;
if ( ( V_61 == V_28 ) &&
( V_62 == V_29 ) ) {
F_9 ( & V_27 -> V_32 ) ;
V_18 -> V_19 -- ;
F_19 ( V_27 -> V_33 ,
V_53 ) ;
break;
}
}
F_25 (mb_entry, &ctx->ref_queue, list) {
V_28 = F_8 ( V_27 -> V_33 , 0 ) ;
V_29 = F_8 ( V_27 -> V_33 , 1 ) ;
if ( ( V_61 == V_28 ) &&
( V_62 == V_29 ) ) {
F_9 ( & V_27 -> V_32 ) ;
V_18 -> V_34 -- ;
F_19 ( V_27 -> V_33 ,
V_53 ) ;
break;
}
}
}
if ( ( V_18 -> V_19 > 0 ) && ( V_18 -> V_21 == V_23 ) ) {
V_27 = F_7 ( V_18 -> V_35 . V_31 , struct V_26 ,
V_32 ) ;
if ( V_27 -> V_41 & V_68 ) {
F_9 ( & V_27 -> V_32 ) ;
V_18 -> V_19 -- ;
F_10 ( & V_27 -> V_32 , & V_18 -> V_30 ) ;
V_18 -> V_34 ++ ;
}
F_4 ( 2 , L_8 ,
V_18 -> V_19 , V_18 -> V_34 ) ;
}
if ( V_64 > 0 ) {
V_27 = F_7 ( V_18 -> V_43 . V_31 , struct V_26 ,
V_32 ) ;
F_9 ( & V_27 -> V_32 ) ;
V_18 -> V_20 -- ;
switch ( V_63 ) {
case V_69 :
V_27 -> V_33 -> V_70 . V_41 |= V_71 ;
break;
case V_72 :
V_27 -> V_33 -> V_70 . V_41 |= V_73 ;
break;
case V_74 :
V_27 -> V_33 -> V_70 . V_41 |= V_75 ;
break;
}
F_18 ( V_27 -> V_33 , 0 , V_64 ) ;
F_19 ( V_27 -> V_33 , V_53 ) ;
}
F_16 ( & V_37 -> V_42 , V_41 ) ;
if ( ( V_18 -> V_19 == 0 ) || ( V_18 -> V_20 == 0 ) )
F_26 ( V_18 ) ;
return 0 ;
}
static int F_27 ( struct V_76 * V_76 , void * V_77 ,
struct V_78 * V_79 )
{
struct V_36 * V_37 = F_28 ( V_76 ) ;
strncpy ( V_79 -> V_80 , V_37 -> V_81 -> V_82 , sizeof( V_79 -> V_80 ) - 1 ) ;
strncpy ( V_79 -> V_83 , V_37 -> V_81 -> V_82 , sizeof( V_79 -> V_83 ) - 1 ) ;
V_79 -> V_84 [ 0 ] = 0 ;
V_79 -> V_85 = F_29 ( 1 , 0 , 0 ) ;
V_79 -> V_86 = V_87 | V_88 |
V_89 |
V_90 ;
return 0 ;
}
static int F_30 ( struct V_91 * V_3 , bool V_92 , bool V_93 )
{
struct V_1 * V_9 ;
int V_5 , V_94 = 0 ;
for ( V_5 = 0 ; V_5 < F_31 ( V_7 ) ; ++ V_5 ) {
if ( V_92 && V_7 [ V_5 ] . V_95 == 1 )
continue;
else if ( ! V_92 && V_7 [ V_5 ] . V_95 > 1 )
continue;
if ( V_93 && V_7 [ V_5 ] . type != V_96 )
continue;
else if ( ! V_93 && V_7 [ V_5 ] . type != V_97 )
continue;
if ( V_94 == V_3 -> V_98 ) {
V_9 = & V_7 [ V_5 ] ;
F_32 ( V_3 -> V_99 , V_9 -> V_82 ,
sizeof( V_3 -> V_99 ) ) ;
V_3 -> V_11 = V_9 -> V_8 ;
return 0 ;
}
++ V_94 ;
}
return - V_100 ;
}
static int F_33 ( struct V_76 * V_76 , void * V_101 ,
struct V_91 * V_3 )
{
return F_30 ( V_3 , false , false ) ;
}
static int F_34 ( struct V_76 * V_76 , void * V_101 ,
struct V_91 * V_3 )
{
return F_30 ( V_3 , true , false ) ;
}
static int F_35 ( struct V_76 * V_76 , void * V_102 ,
struct V_91 * V_3 )
{
return F_30 ( V_3 , false , true ) ;
}
static int F_36 ( struct V_76 * V_76 , void * V_102 ,
struct V_91 * V_3 )
{
return F_30 ( V_3 , true , true ) ;
}
static int F_37 ( struct V_76 * V_76 , void * V_77 , struct V_2 * V_3 )
{
struct V_17 * V_18 = F_38 ( V_77 ) ;
struct V_103 * V_104 = & V_3 -> V_9 . V_10 ;
F_4 ( 2 , L_12 , V_3 -> type , V_18 -> V_21 ) ;
if ( V_3 -> type == V_105 ) {
V_104 -> V_106 = 0 ;
V_104 -> V_107 = 0 ;
V_104 -> V_108 = V_109 ;
V_104 -> V_11 = V_18 -> V_110 -> V_8 ;
V_104 -> V_95 = V_18 -> V_110 -> V_95 ;
V_104 -> V_111 [ 0 ] . V_112 = V_18 -> V_113 ;
V_104 -> V_111 [ 0 ] . V_114 = V_18 -> V_113 ;
} else if ( V_3 -> type == V_115 ) {
V_104 -> V_106 = V_18 -> V_116 ;
V_104 -> V_107 = V_18 -> V_117 ;
V_104 -> V_108 = V_109 ;
V_104 -> V_11 = V_18 -> V_118 -> V_8 ;
V_104 -> V_95 = V_18 -> V_118 -> V_95 ;
V_104 -> V_111 [ 0 ] . V_112 = V_18 -> V_119 ;
V_104 -> V_111 [ 0 ] . V_114 = V_18 -> V_120 ;
V_104 -> V_111 [ 1 ] . V_112 = V_18 -> V_119 ;
V_104 -> V_111 [ 1 ] . V_114 = V_18 -> V_121 ;
} else {
F_39 ( L_13 ) ;
return - V_100 ;
}
return 0 ;
}
static int F_40 ( struct V_76 * V_76 , void * V_77 , struct V_2 * V_3 )
{
struct V_36 * V_37 = F_28 ( V_76 ) ;
struct V_1 * V_9 ;
struct V_103 * V_104 = & V_3 -> V_9 . V_10 ;
if ( V_3 -> type == V_105 ) {
V_9 = F_1 ( V_3 , V_97 ) ;
if ( ! V_9 ) {
F_39 ( L_14 ) ;
return - V_100 ;
}
if ( ! F_41 ( V_37 ) && ( V_9 -> V_8 == V_122 ) ) {
F_39 ( L_15 ) ;
return - V_100 ;
}
if ( V_104 -> V_111 [ 0 ] . V_114 == 0 ) {
F_39 ( L_16 ) ;
return - V_100 ;
}
V_104 -> V_111 [ 0 ] . V_112 =
V_104 -> V_111 [ 0 ] . V_114 ;
} else if ( V_3 -> type == V_115 ) {
V_9 = F_1 ( V_3 , V_96 ) ;
if ( ! V_9 ) {
F_39 ( L_14 ) ;
return - V_100 ;
}
if ( ! F_20 ( V_37 ) ) {
if ( V_9 -> V_8 == V_123 ) {
F_39 ( L_17 ) ;
return - V_100 ;
}
} else if ( F_20 ( V_37 ) ) {
if ( V_9 -> V_8 == V_124 ) {
F_39 ( L_17 ) ;
return - V_100 ;
}
}
if ( V_9 -> V_95 != V_104 -> V_95 ) {
F_39 ( L_14 ) ;
return - V_100 ;
}
F_42 ( & V_104 -> V_106 , 8 , 1920 , 1 ,
& V_104 -> V_107 , 4 , 1080 , 1 , 0 ) ;
} else {
F_39 ( L_13 ) ;
return - V_100 ;
}
return 0 ;
}
static int F_43 ( struct V_76 * V_76 , void * V_77 , struct V_2 * V_3 )
{
struct V_36 * V_37 = F_28 ( V_76 ) ;
struct V_17 * V_18 = F_38 ( V_77 ) ;
struct V_103 * V_104 = & V_3 -> V_9 . V_10 ;
int V_125 = 0 ;
V_125 = F_40 ( V_76 , V_77 , V_3 ) ;
if ( V_125 )
return V_125 ;
if ( V_18 -> V_126 . V_127 || V_18 -> V_128 . V_127 ) {
F_44 ( & V_37 -> V_129 , L_18 , V_130 ) ;
V_125 = - V_131 ;
goto V_93;
}
if ( V_3 -> type == V_105 ) {
V_18 -> V_110 = F_1 ( V_3 , V_97 ) ;
V_18 -> V_21 = V_132 ;
V_18 -> V_133 = V_18 -> V_110 -> V_133 ;
V_18 -> V_113 = V_104 -> V_111 [ 0 ] . V_114 ;
V_104 -> V_111 [ 0 ] . V_112 = 0 ;
V_18 -> V_134 = 0 ;
V_18 -> V_135 = V_136 ;
F_15 ( V_37 -> V_44 , V_137 , V_18 ) ;
F_21 ( V_18 ) ;
F_45 ( V_18 ) ;
F_15 ( V_37 -> V_44 , V_54 , V_37 ) ;
if ( F_46 ( V_18 , \
V_138 , 1 ) ) {
F_39 ( L_19 ) ;
F_15 ( V_37 -> V_44 , V_139 ,
V_18 ) ;
V_125 = - V_140 ;
goto V_93;
}
F_4 ( 2 , L_20 , V_18 -> V_141 ) ;
} else if ( V_3 -> type == V_115 ) {
V_18 -> V_118 = F_1 ( V_3 , V_96 ) ;
V_18 -> V_116 = V_104 -> V_106 ;
V_18 -> V_117 = V_104 -> V_107 ;
F_4 ( 2 , L_21 , V_18 -> V_118 -> V_133 ) ;
F_4 ( 2 , L_22 ,
V_104 -> V_106 , V_104 -> V_107 ,
V_18 -> V_116 , V_18 -> V_117 ) ;
F_15 ( V_37 -> V_44 , V_142 , V_18 ) ;
V_104 -> V_111 [ 0 ] . V_114 = V_18 -> V_120 ;
V_104 -> V_111 [ 0 ] . V_112 = V_18 -> V_119 ;
V_104 -> V_111 [ 1 ] . V_114 = V_18 -> V_121 ;
V_104 -> V_111 [ 1 ] . V_112 = V_18 -> V_119 ;
V_18 -> V_143 = 0 ;
V_18 -> V_144 = V_136 ;
} else {
F_39 ( L_13 ) ;
return - V_100 ;
}
V_93:
F_47 () ;
return V_125 ;
}
static int F_48 ( struct V_76 * V_76 , void * V_77 ,
struct V_145 * V_146 )
{
struct V_36 * V_37 = F_28 ( V_76 ) ;
struct V_17 * V_18 = F_38 ( V_77 ) ;
int V_125 = 0 ;
if ( ( V_146 -> V_147 != V_148 ) &&
( V_146 -> V_147 != V_149 ) )
return - V_100 ;
if ( V_146 -> type == V_105 ) {
if ( V_18 -> V_135 != V_136 ) {
F_39 ( L_23 ,
V_18 -> V_135 ) ;
return - V_100 ;
}
V_125 = F_49 ( & V_18 -> V_128 , V_146 ) ;
if ( V_125 != 0 ) {
F_39 ( L_24 ) ;
return V_125 ;
}
V_18 -> V_135 = V_150 ;
V_125 = F_15 ( V_18 -> V_37 -> V_44 ,
V_151 , V_18 ) ;
if ( V_125 ) {
F_39 ( L_25 ) ;
V_146 -> V_152 = 0 ;
V_125 = F_49 ( & V_18 -> V_128 , V_146 ) ;
return - V_153 ;
}
} else if ( V_146 -> type == V_115 ) {
if ( V_18 -> V_144 != V_136 ) {
F_39 ( L_26 ,
V_18 -> V_144 ) ;
return - V_100 ;
}
if ( F_20 ( V_37 ) ) {
if ( V_18 -> V_56 &&
( V_146 -> V_152 < V_18 -> V_56 ) ) {
V_146 -> V_152 = V_18 -> V_56 ;
F_4 ( 2 , L_27 ,
V_18 -> V_56 ) ;
} else {
V_18 -> V_56 = V_146 -> V_152 ;
}
}
V_125 = F_49 ( & V_18 -> V_126 , V_146 ) ;
if ( V_125 != 0 ) {
F_39 ( L_28 ) ;
return V_125 ;
}
V_18 -> V_144 = V_150 ;
} else {
F_39 ( L_13 ) ;
return - V_100 ;
}
return V_125 ;
}
static int F_50 ( struct V_76 * V_76 , void * V_77 ,
struct V_154 * V_155 )
{
struct V_17 * V_18 = F_38 ( V_77 ) ;
int V_125 = 0 ;
if ( ( V_155 -> V_147 != V_148 ) &&
( V_155 -> V_147 != V_149 ) )
return - V_100 ;
if ( V_155 -> type == V_105 ) {
if ( V_18 -> V_21 != V_22 ) {
F_39 ( L_29 , V_18 -> V_21 ) ;
return - V_100 ;
}
V_125 = F_51 ( & V_18 -> V_128 , V_155 ) ;
if ( V_125 != 0 ) {
F_39 ( L_30 ) ;
return V_125 ;
}
V_155 -> V_156 . V_157 [ 0 ] . V_156 . V_158 += V_159 ;
} else if ( V_155 -> type == V_115 ) {
V_125 = F_51 ( & V_18 -> V_126 , V_155 ) ;
if ( V_125 != 0 ) {
F_39 ( L_31 ) ;
return V_125 ;
}
} else {
F_39 ( L_13 ) ;
return - V_100 ;
}
return V_125 ;
}
static int F_52 ( struct V_76 * V_76 , void * V_77 , struct V_154 * V_155 )
{
struct V_17 * V_18 = F_38 ( V_77 ) ;
if ( V_18 -> V_21 == V_160 ) {
F_39 ( L_32 ) ;
return - V_140 ;
}
if ( V_155 -> type == V_115 ) {
if ( V_18 -> V_21 == V_25 ) {
F_39 ( L_33 ) ;
return - V_140 ;
}
return F_53 ( & V_18 -> V_126 , V_155 ) ;
} else if ( V_155 -> type == V_105 ) {
return F_53 ( & V_18 -> V_128 , V_155 ) ;
}
return - V_100 ;
}
static int F_54 ( struct V_76 * V_76 , void * V_77 , struct V_154 * V_155 )
{
const struct V_161 V_162 = {
. type = V_163
} ;
struct V_17 * V_18 = F_38 ( V_77 ) ;
int V_125 ;
if ( V_18 -> V_21 == V_160 ) {
F_39 ( L_34 ) ;
return - V_140 ;
}
if ( V_155 -> type == V_115 ) {
V_125 = F_55 ( & V_18 -> V_126 , V_155 , V_76 -> V_164 & V_165 ) ;
} else if ( V_155 -> type == V_105 ) {
V_125 = F_55 ( & V_18 -> V_128 , V_155 , V_76 -> V_164 & V_165 ) ;
if ( V_125 == 0 && V_18 -> V_21 == V_166
&& F_6 ( & V_18 -> V_128 . V_167 ) )
F_56 ( & V_18 -> V_168 , & V_162 ) ;
} else {
V_125 = - V_100 ;
}
return V_125 ;
}
static int F_57 ( struct V_76 * V_76 , void * V_77 ,
struct V_169 * V_170 )
{
struct V_17 * V_18 = F_38 ( V_77 ) ;
if ( V_170 -> type == V_115 )
return F_58 ( & V_18 -> V_126 , V_170 ) ;
if ( V_170 -> type == V_105 )
return F_58 ( & V_18 -> V_128 , V_170 ) ;
return - V_100 ;
}
static int F_59 ( struct V_76 * V_76 , void * V_77 ,
enum V_171 type )
{
struct V_17 * V_18 = F_38 ( V_77 ) ;
if ( type == V_115 )
return F_60 ( & V_18 -> V_126 , type ) ;
else if ( type == V_105 )
return F_60 ( & V_18 -> V_128 , type ) ;
return - V_100 ;
}
static int F_61 ( struct V_76 * V_76 , void * V_77 ,
enum V_171 type )
{
struct V_17 * V_18 = F_38 ( V_77 ) ;
if ( type == V_115 )
return F_62 ( & V_18 -> V_126 , type ) ;
else if ( type == V_105 )
return F_62 ( & V_18 -> V_128 , type ) ;
return - V_100 ;
}
static inline int F_63 ( enum V_172 V_173 )
{
static unsigned int V_4 [ V_174 + 1 ] = {
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
return V_4 [ V_173 ] ;
}
static inline int F_64 ( enum V_175 V_173 )
{
static unsigned int V_4 [ V_176 + 1 ] = {
0 ,
9 ,
1 ,
2 ,
3 ,
7 ,
4 ,
5 ,
} ;
return V_4 [ V_173 ] ;
}
static inline int F_65 ( enum V_177 V_178 )
{
static unsigned int V_4 [ V_179 + 1 ] = {
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
return V_4 [ V_178 ] ;
}
static int F_66 ( struct V_180 * V_181 )
{
struct V_17 * V_18 = F_67 ( V_181 ) ;
struct V_36 * V_37 = V_18 -> V_37 ;
struct V_46 * V_47 = & V_18 -> V_48 ;
int V_125 = 0 ;
switch ( V_181 -> V_12 ) {
case V_182 :
V_47 -> V_183 = V_181 -> V_184 ;
break;
case V_185 :
V_47 -> V_186 = V_181 -> V_184 ;
break;
case V_187 :
V_47 -> V_188 = V_181 -> V_184 ;
break;
case V_189 :
V_47 -> V_190 = V_181 -> V_184 * 8 ;
break;
case V_191 :
V_47 -> V_192 = V_181 -> V_184 ;
break;
case V_193 :
V_47 -> V_194 = V_181 -> V_184 ;
break;
case V_195 :
V_47 -> V_196 = ( V_181 -> V_184 >> 16 ) & 0xff ;
V_47 -> V_197 = ( V_181 -> V_184 >> 8 ) & 0xff ;
V_47 -> V_198 = ( V_181 -> V_184 >> 0 ) & 0xff ;
break;
case V_199 :
V_47 -> V_200 = V_181 -> V_184 ;
break;
case V_201 :
V_47 -> V_202 = V_181 -> V_184 ;
break;
case V_203 :
V_47 -> V_204 = V_181 -> V_184 ;
break;
case V_16 :
V_18 -> V_205 = V_181 -> V_184 ;
break;
case V_206 :
V_47 -> V_207 = V_181 -> V_184 ;
break;
case V_208 :
V_47 -> V_209 . V_210 . V_211 = V_181 -> V_184 ;
break;
case V_212 :
V_47 -> V_50 = V_181 -> V_184 ;
break;
case V_15 :
V_47 -> V_213 = V_181 -> V_184 ;
break;
case V_214 :
V_47 -> V_215 = V_181 -> V_184 ;
break;
case V_216 :
V_47 -> V_217 = V_181 -> V_184 ;
break;
case V_218 :
switch ( V_181 -> V_184 ) {
case V_219 :
V_47 -> V_209 . V_210 . V_220 =
V_221 ;
break;
case V_222 :
V_47 -> V_209 . V_210 . V_220 =
V_223 ;
break;
case V_224 :
V_47 -> V_209 . V_210 . V_220 =
V_225 ;
break;
case V_226 :
if ( F_20 ( V_37 ) )
V_47 -> V_209 . V_210 . V_220 =
V_227 ;
else
V_125 = - V_100 ;
break;
default:
V_125 = - V_100 ;
}
break;
case V_228 :
V_47 -> V_209 . V_210 . V_229 = V_181 -> V_184 ;
V_47 -> V_209 . V_210 . V_230 = F_63 ( V_181 -> V_184 ) ;
if ( V_47 -> V_209 . V_210 . V_230 < 0 ) {
F_39 ( L_35 ) ;
V_125 = V_47 -> V_209 . V_210 . V_230 ;
}
break;
case V_231 :
V_47 -> V_209 . V_232 . V_229 = V_181 -> V_184 ;
V_47 -> V_209 . V_232 . V_230 = F_64 ( V_181 -> V_184 ) ;
if ( V_47 -> V_209 . V_232 . V_230 < 0 ) {
F_39 ( L_35 ) ;
V_125 = V_47 -> V_209 . V_232 . V_230 ;
}
break;
case V_233 :
V_47 -> V_209 . V_210 . V_234 = V_181 -> V_184 ;
break;
case V_235 :
V_47 -> V_209 . V_210 . V_236 = V_181 -> V_184 ;
break;
case V_237 :
V_47 -> V_209 . V_210 . V_238 = V_181 -> V_184 ;
break;
case V_239 :
V_47 -> V_209 . V_210 . V_240 = V_181 -> V_184 ;
break;
case V_241 :
V_47 -> V_209 . V_210 . V_242 = V_181 -> V_184 ;
break;
case V_243 :
V_47 -> V_209 . V_210 . V_244 = V_181 -> V_184 ;
break;
case V_245 :
V_47 -> V_246 = V_181 -> V_184 ;
break;
case V_247 :
V_47 -> V_209 . V_210 . V_248 = V_181 -> V_184 ;
break;
case V_249 :
V_47 -> V_209 . V_210 . V_250 = V_181 -> V_184 ;
break;
case V_251 :
V_47 -> V_209 . V_210 . V_252 = V_181 -> V_184 ;
break;
case V_253 :
V_47 -> V_209 . V_210 . V_254 = V_181 -> V_184 ;
break;
case V_255 :
V_47 -> V_209 . V_210 . V_256 = V_181 -> V_184 ;
break;
case V_257 :
case V_258 :
V_47 -> V_209 . V_232 . V_248 = V_181 -> V_184 ;
break;
case V_259 :
case V_260 :
V_47 -> V_209 . V_232 . V_250 = V_181 -> V_184 ;
break;
case V_261 :
case V_262 :
V_47 -> V_209 . V_232 . V_252 = V_181 -> V_184 ;
break;
case V_263 :
case V_264 :
V_47 -> V_209 . V_232 . V_254 = V_181 -> V_184 ;
break;
case V_265 :
case V_266 :
V_47 -> V_209 . V_232 . V_256 = V_181 -> V_184 ;
break;
case V_267 :
V_47 -> V_209 . V_210 . V_268 = V_181 -> V_184 ;
break;
case V_269 :
V_47 -> V_209 . V_210 . V_270 = V_181 -> V_184 ;
break;
case V_271 :
V_47 -> V_209 . V_210 . V_272 = V_181 -> V_184 ;
break;
case V_273 :
V_47 -> V_209 . V_210 . V_274 = V_181 -> V_184 ;
break;
case V_275 :
V_47 -> V_209 . V_210 . V_276 = V_181 -> V_184 ;
break;
case V_277 :
V_47 -> V_209 . V_210 . F_65 = F_65 ( V_181 -> V_184 ) ;
break;
case V_278 :
V_47 -> V_209 . V_210 . V_279 = V_181 -> V_184 ;
break;
case V_280 :
V_47 -> V_209 . V_210 . V_281 = V_181 -> V_184 ;
break;
case V_282 :
V_47 -> V_209 . V_210 . V_283 = ! V_181 -> V_184 ;
break;
case V_284 :
V_47 -> V_209 . V_210 . V_285 = V_181 -> V_184 ;
break;
case V_286 :
switch ( V_181 -> V_184 ) {
case V_287 :
V_47 -> V_209 . V_232 . V_220 =
V_288 ;
break;
case V_289 :
V_47 -> V_209 . V_232 . V_220 =
V_290 ;
break;
default:
V_125 = - V_100 ;
}
break;
case V_291 :
V_47 -> V_209 . V_232 . V_292 = V_181 -> V_184 ;
break;
case V_293 :
V_47 -> V_209 . V_294 . V_295 = V_181 -> V_184 ;
break;
case V_296 :
V_47 -> V_209 . V_294 . V_297 = V_181 -> V_184 ;
break;
case V_298 :
V_47 -> V_209 . V_294 . V_299 = V_181 -> V_184 ;
break;
case V_300 :
V_47 -> V_209 . V_294 . V_301 = V_181 -> V_184 ;
break;
case V_302 :
V_47 -> V_209 . V_294 . V_303 = V_181 -> V_184 ;
break;
case V_304 :
V_47 -> V_209 . V_294 . V_305 = V_181 -> V_184 ;
break;
case V_306 :
V_47 -> V_209 . V_294 . V_307 = V_181 -> V_184 ;
break;
default:
F_44 ( & V_37 -> V_129 , L_36 ,
V_181 -> V_12 , V_181 -> V_184 ) ;
V_125 = - V_100 ;
}
return V_125 ;
}
static int F_68 ( struct V_76 * V_76 , void * V_77 ,
struct V_308 * V_309 )
{
struct V_17 * V_18 = F_38 ( V_77 ) ;
if ( V_309 -> type == V_115 ) {
V_18 -> V_48 . V_310 =
V_309 -> V_311 . V_312 . V_313 . V_314 ;
V_18 -> V_48 . V_315 =
V_309 -> V_311 . V_312 . V_313 . V_316 ;
} else {
F_39 ( L_37 ) ;
return - V_100 ;
}
return 0 ;
}
static int F_69 ( struct V_76 * V_76 , void * V_77 ,
struct V_308 * V_309 )
{
struct V_17 * V_18 = F_38 ( V_77 ) ;
if ( V_309 -> type == V_317 ) {
V_309 -> V_311 . V_312 . V_313 . V_314 =
V_18 -> V_48 . V_310 ;
V_309 -> V_311 . V_312 . V_313 . V_316 =
V_18 -> V_48 . V_315 ;
} else {
F_39 ( L_37 ) ;
return - V_100 ;
}
return 0 ;
}
int F_70 ( struct V_76 * V_76 , void * V_77 ,
struct V_318 * V_319 )
{
struct V_17 * V_18 = F_38 ( V_77 ) ;
struct V_36 * V_37 = V_18 -> V_37 ;
struct V_26 * V_155 ;
unsigned long V_41 ;
switch ( V_319 -> V_319 ) {
case V_320 :
if ( V_319 -> V_41 != 0 )
return - V_100 ;
if ( ! V_18 -> V_126 . V_127 )
return - V_100 ;
F_13 ( & V_37 -> V_42 , V_41 ) ;
if ( F_6 ( & V_18 -> V_35 ) ) {
F_4 ( 2 , L_38 ) ;
V_18 -> V_21 = V_25 ;
if ( F_3 ( V_18 ) )
F_21 ( V_18 ) ;
F_16 ( & V_37 -> V_42 , V_41 ) ;
F_15 ( V_37 -> V_44 , V_54 , V_37 ) ;
} else {
F_4 ( 2 , L_39 ) ;
V_155 = F_7 ( V_18 -> V_35 . V_321 ,
struct V_26 , V_32 ) ;
if ( V_155 -> V_41 & V_68 )
V_18 -> V_21 = V_25 ;
else
V_155 -> V_41 |= V_322 ;
F_16 ( & V_37 -> V_42 , V_41 ) ;
}
break;
default:
return - V_100 ;
}
return 0 ;
}
static int F_71 ( struct V_323 * V_168 ,
const struct V_324 * V_325 )
{
switch ( V_325 -> type ) {
case V_163 :
return F_72 ( V_168 , V_325 , 2 , NULL ) ;
default:
return - V_100 ;
}
}
static int F_73 ( struct V_1 * V_9 , struct V_326 * V_327 )
{
int V_5 ;
if ( ! V_9 )
return - V_100 ;
if ( V_9 -> V_95 != V_327 -> V_95 ) {
F_39 ( L_40 ) ;
return - V_100 ;
}
for ( V_5 = 0 ; V_5 < V_9 -> V_95 ; V_5 ++ ) {
if ( ! F_8 ( V_327 , V_5 ) ) {
F_39 ( L_41 ) ;
return - V_100 ;
}
F_4 ( 2 , L_42 ,
V_327 -> V_70 . V_98 , V_5 ,
F_8 ( V_327 , V_5 ) ) ;
}
return 0 ;
}
static int F_74 ( struct V_328 * V_329 ,
const struct V_2 * V_9 ,
unsigned int * V_330 , unsigned int * V_331 ,
unsigned int V_332 [] , void * V_333 [] )
{
struct V_17 * V_18 = F_38 ( V_329 -> V_334 ) ;
struct V_36 * V_37 = V_18 -> V_37 ;
if ( V_18 -> V_21 != V_22 ) {
F_39 ( L_43 , V_18 -> V_21 ) ;
return - V_100 ;
}
if ( V_329 -> type == V_105 ) {
if ( V_18 -> V_110 )
* V_331 = V_18 -> V_110 -> V_95 ;
else
* V_331 = V_335 ;
if ( * V_330 < 1 )
* V_330 = 1 ;
if ( * V_330 > V_336 )
* V_330 = V_336 ;
V_332 [ 0 ] = V_18 -> V_113 ;
V_333 [ 0 ] = V_18 -> V_37 -> V_337 [ V_338 ] ;
} else if ( V_329 -> type == V_115 ) {
if ( V_18 -> V_118 )
* V_331 = V_18 -> V_118 -> V_95 ;
else
* V_331 = V_339 ;
if ( * V_330 < 1 )
* V_330 = 1 ;
if ( * V_330 > V_336 )
* V_330 = V_336 ;
V_332 [ 0 ] = V_18 -> V_120 ;
V_332 [ 1 ] = V_18 -> V_121 ;
if ( F_20 ( V_37 ) ) {
V_333 [ 0 ] =
V_18 -> V_37 -> V_337 [ V_338 ] ;
V_333 [ 1 ] =
V_18 -> V_37 -> V_337 [ V_338 ] ;
} else {
V_333 [ 0 ] =
V_18 -> V_37 -> V_337 [ V_340 ] ;
V_333 [ 1 ] =
V_18 -> V_37 -> V_337 [ V_340 ] ;
}
} else {
F_39 ( L_44 , V_329 -> type ) ;
return - V_100 ;
}
return 0 ;
}
static void F_75 ( struct V_328 * V_341 )
{
struct V_17 * V_18 = F_38 ( V_341 -> V_334 ) ;
struct V_36 * V_37 = V_18 -> V_37 ;
F_76 ( & V_37 -> V_342 ) ;
}
static void F_77 ( struct V_328 * V_341 )
{
struct V_17 * V_18 = F_38 ( V_341 -> V_334 ) ;
struct V_36 * V_37 = V_18 -> V_37 ;
F_78 ( & V_37 -> V_342 ) ;
}
static int F_79 ( struct V_326 * V_327 )
{
struct V_328 * V_329 = V_327 -> V_328 ;
struct V_17 * V_18 = F_38 ( V_329 -> V_334 ) ;
unsigned int V_5 ;
int V_125 ;
if ( V_329 -> type == V_105 ) {
V_125 = F_73 ( V_18 -> V_110 , V_327 ) ;
if ( V_125 < 0 )
return V_125 ;
V_5 = V_327 -> V_70 . V_98 ;
V_18 -> V_343 [ V_5 ] . V_33 = V_327 ;
V_18 -> V_343 [ V_5 ] . V_344 . V_345 =
F_8 ( V_327 , 0 ) ;
V_18 -> V_134 ++ ;
} else if ( V_329 -> type == V_115 ) {
V_125 = F_73 ( V_18 -> V_118 , V_327 ) ;
if ( V_125 < 0 )
return V_125 ;
V_5 = V_327 -> V_70 . V_98 ;
V_18 -> V_346 [ V_5 ] . V_33 = V_327 ;
V_18 -> V_346 [ V_5 ] . V_344 . V_347 . V_348 =
F_8 ( V_327 , 0 ) ;
V_18 -> V_346 [ V_5 ] . V_344 . V_347 . V_349 =
F_8 ( V_327 , 1 ) ;
V_18 -> V_143 ++ ;
} else {
F_39 ( L_44 , V_329 -> type ) ;
return - V_100 ;
}
return 0 ;
}
static int F_80 ( struct V_326 * V_327 )
{
struct V_328 * V_329 = V_327 -> V_328 ;
struct V_17 * V_18 = F_38 ( V_329 -> V_334 ) ;
int V_125 ;
if ( V_329 -> type == V_105 ) {
V_125 = F_73 ( V_18 -> V_110 , V_327 ) ;
if ( V_125 < 0 )
return V_125 ;
F_4 ( 2 , L_45 ,
F_14 ( V_327 , 0 ) , V_18 -> V_113 ) ;
if ( F_14 ( V_327 , 0 ) < V_18 -> V_113 ) {
F_39 ( L_46 ) ;
return - V_100 ;
}
} else if ( V_329 -> type == V_115 ) {
V_125 = F_73 ( V_18 -> V_118 , V_327 ) ;
if ( V_125 < 0 )
return V_125 ;
F_4 ( 2 , L_47 ,
F_14 ( V_327 , 0 ) , V_18 -> V_120 ) ;
F_4 ( 2 , L_48 ,
F_14 ( V_327 , 1 ) , V_18 -> V_121 ) ;
if ( F_14 ( V_327 , 0 ) < V_18 -> V_120 ||
F_14 ( V_327 , 1 ) < V_18 -> V_121 ) {
F_39 ( L_49 ) ;
return - V_100 ;
}
} else {
F_39 ( L_44 , V_329 -> type ) ;
return - V_100 ;
}
return 0 ;
}
static int F_81 ( struct V_328 * V_341 , unsigned int V_152 )
{
struct V_17 * V_18 = F_38 ( V_341 -> V_334 ) ;
struct V_36 * V_37 = V_18 -> V_37 ;
if ( F_20 ( V_37 ) &&
( V_341 -> type == V_105 ) ) {
if ( ( V_18 -> V_21 == V_22 ) &&
( V_37 -> V_350 == V_18 -> V_351 ) && V_37 -> V_352 ) {
F_46 ( V_18 ,
V_353 ,
0 ) ;
}
if ( V_18 -> V_143 < V_18 -> V_56 ) {
F_39 ( L_50 ,
V_18 -> V_56 ) ;
return - V_100 ;
}
}
if ( F_3 ( V_18 ) )
F_21 ( V_18 ) ;
F_15 ( V_37 -> V_44 , V_54 , V_37 ) ;
return 0 ;
}
static int F_82 ( struct V_328 * V_341 )
{
unsigned long V_41 ;
struct V_17 * V_18 = F_38 ( V_341 -> V_334 ) ;
struct V_36 * V_37 = V_18 -> V_37 ;
if ( ( V_18 -> V_21 == V_25 ||
V_18 -> V_21 == V_23 ) &&
V_37 -> V_350 == V_18 -> V_351 && V_37 -> V_352 ) {
V_18 -> V_21 = V_354 ;
F_46 ( V_18 , V_355 ,
0 ) ;
}
V_18 -> V_21 = V_166 ;
F_13 ( & V_37 -> V_42 , V_41 ) ;
if ( V_341 -> type == V_105 ) {
F_15 ( V_37 -> V_44 , V_356 , & V_18 -> V_43 ,
& V_18 -> V_128 ) ;
F_11 ( & V_18 -> V_43 ) ;
V_18 -> V_20 = 0 ;
}
if ( V_341 -> type == V_115 ) {
F_5 ( V_18 ) ;
F_15 ( V_37 -> V_44 , V_356 , & V_18 -> V_35 ,
& V_18 -> V_126 ) ;
F_11 ( & V_18 -> V_35 ) ;
V_18 -> V_19 = 0 ;
}
F_16 ( & V_37 -> V_42 , V_41 ) ;
return 0 ;
}
static void F_83 ( struct V_326 * V_327 )
{
struct V_328 * V_329 = V_327 -> V_328 ;
struct V_17 * V_18 = F_38 ( V_329 -> V_334 ) ;
struct V_36 * V_37 = V_18 -> V_37 ;
unsigned long V_41 ;
struct V_26 * V_357 ;
if ( V_18 -> V_21 == V_160 ) {
F_19 ( V_327 , V_358 ) ;
F_5 ( V_18 ) ;
return;
}
if ( V_329 -> type == V_105 ) {
V_357 = & V_18 -> V_343 [ V_327 -> V_70 . V_98 ] ;
V_357 -> V_41 &= ~ V_68 ;
F_13 ( & V_37 -> V_42 , V_41 ) ;
F_10 ( & V_357 -> V_32 , & V_18 -> V_43 ) ;
V_18 -> V_20 ++ ;
F_16 ( & V_37 -> V_42 , V_41 ) ;
} else if ( V_329 -> type == V_115 ) {
V_357 = & V_18 -> V_346 [ V_327 -> V_70 . V_98 ] ;
V_357 -> V_41 &= ~ V_68 ;
F_13 ( & V_37 -> V_42 , V_41 ) ;
F_10 ( & V_357 -> V_32 , & V_18 -> V_35 ) ;
V_18 -> V_19 ++ ;
F_16 ( & V_37 -> V_42 , V_41 ) ;
} else {
F_39 ( L_51 , V_329 -> type ) ;
}
if ( F_3 ( V_18 ) )
F_21 ( V_18 ) ;
F_15 ( V_37 -> V_44 , V_54 , V_37 ) ;
}
struct V_359 * F_84 ( void )
{
return & V_360 ;
}
struct V_361 * F_85 ( void )
{
return & V_362 ;
}
const struct V_363 * F_86 ( void )
{
return & V_364 ;
}
int F_87 ( struct V_17 * V_18 )
{
struct V_365 V_366 ;
int V_5 ;
F_88 ( & V_18 -> V_367 , V_368 ) ;
if ( V_18 -> V_367 . error ) {
F_39 ( L_52 ) ;
return V_18 -> V_367 . error ;
}
for ( V_5 = 0 ; V_5 < V_368 ; V_5 ++ ) {
if ( F_89 ( V_369 [ V_5 ] . V_12 ) ) {
memset ( & V_366 , 0 , sizeof( struct V_365 ) ) ;
V_366 . V_370 = & V_371 ;
V_366 . V_12 = V_369 [ V_5 ] . V_12 ;
V_366 . V_372 = V_369 [ V_5 ] . V_373 ;
V_366 . V_374 = V_369 [ V_5 ] . V_375 ;
V_366 . V_376 = V_369 [ V_5 ] . V_377 ;
V_366 . V_82 = V_369 [ V_5 ] . V_82 ;
V_366 . type = V_369 [ V_5 ] . type ;
V_366 . V_41 = 0 ;
if ( V_366 . type == V_378 ) {
V_366 . V_379 = 0 ;
V_366 . V_380 = V_366 . V_380 ;
V_366 . V_381 = F_2 ( V_366 . V_12 ) ;
} else {
V_366 . V_379 = V_369 [ V_5 ] . V_379 ;
V_366 . V_380 = 0 ;
}
V_18 -> V_382 [ V_5 ] = F_90 ( & V_18 -> V_367 ,
& V_366 , NULL ) ;
} else {
if ( ( V_369 [ V_5 ] . type == V_378 ) ||
( V_369 [ V_5 ] . type ==
V_383 ) ) {
V_18 -> V_382 [ V_5 ] = F_91 (
& V_18 -> V_367 ,
& V_371 , V_369 [ V_5 ] . V_12 ,
V_369 [ V_5 ] . V_375 , 0 ,
V_369 [ V_5 ] . V_377 ) ;
} else {
V_18 -> V_382 [ V_5 ] = F_92 (
& V_18 -> V_367 ,
& V_371 , V_369 [ V_5 ] . V_12 ,
V_369 [ V_5 ] . V_373 ,
V_369 [ V_5 ] . V_375 , V_369 [ V_5 ] . V_379 ,
V_369 [ V_5 ] . V_377 ) ;
}
}
if ( V_18 -> V_367 . error ) {
F_39 ( L_53 , V_5 ) ;
return V_18 -> V_367 . error ;
}
if ( V_369 [ V_5 ] . V_384 && V_18 -> V_382 [ V_5 ] )
V_18 -> V_382 [ V_5 ] -> V_41 |= V_385 ;
}
F_93 ( & V_18 -> V_367 ) ;
return 0 ;
}
void F_94 ( struct V_17 * V_18 )
{
int V_5 ;
F_95 ( & V_18 -> V_367 ) ;
for ( V_5 = 0 ; V_5 < V_368 ; V_5 ++ )
V_18 -> V_382 [ V_5 ] = NULL ;
}
void F_96 ( struct V_17 * V_18 )
{
struct V_2 V_3 ;
V_3 . V_9 . V_10 . V_11 = V_386 ;
V_18 -> V_118 = F_1 ( & V_3 , V_96 ) ;
V_3 . V_9 . V_10 . V_11 = V_387 ;
V_18 -> V_110 = F_1 ( & V_3 , V_97 ) ;
}
