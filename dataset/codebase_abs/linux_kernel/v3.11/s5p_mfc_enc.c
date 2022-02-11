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
if ( V_104 -> V_111 [ 0 ] . V_114 == 0 ) {
F_39 ( L_15 ) ;
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
if ( V_9 -> V_8 == V_122 ) {
F_39 ( L_16 ) ;
return - V_100 ;
}
} else if ( F_20 ( V_37 ) ) {
if ( V_9 -> V_8 == V_123 ) {
F_39 ( L_16 ) ;
return - V_100 ;
}
}
if ( V_9 -> V_95 != V_104 -> V_95 ) {
F_39 ( L_14 ) ;
return - V_100 ;
}
F_41 ( & V_104 -> V_106 , 8 , 1920 , 1 ,
& V_104 -> V_107 , 4 , 1080 , 1 , 0 ) ;
} else {
F_39 ( L_13 ) ;
return - V_100 ;
}
return 0 ;
}
static int F_42 ( struct V_76 * V_76 , void * V_77 , struct V_2 * V_3 )
{
struct V_36 * V_37 = F_28 ( V_76 ) ;
struct V_17 * V_18 = F_38 ( V_77 ) ;
struct V_103 * V_104 = & V_3 -> V_9 . V_10 ;
int V_124 = 0 ;
V_124 = F_40 ( V_76 , V_77 , V_3 ) ;
if ( V_124 )
return V_124 ;
if ( V_18 -> V_125 . V_126 || V_18 -> V_127 . V_126 ) {
F_43 ( & V_37 -> V_128 , L_17 , V_129 ) ;
V_124 = - V_130 ;
goto V_93;
}
if ( V_3 -> type == V_105 ) {
V_18 -> V_110 = F_1 ( V_3 , V_97 ) ;
V_18 -> V_21 = V_131 ;
V_18 -> V_132 = V_18 -> V_110 -> V_132 ;
V_18 -> V_113 = V_104 -> V_111 [ 0 ] . V_114 ;
V_104 -> V_111 [ 0 ] . V_112 = 0 ;
V_18 -> V_133 = 0 ;
V_18 -> V_134 = V_135 ;
F_15 ( V_37 -> V_44 , V_136 , V_18 ) ;
F_21 ( V_18 ) ;
F_44 ( V_18 ) ;
F_15 ( V_37 -> V_44 , V_54 , V_37 ) ;
if ( F_45 ( V_18 , \
V_137 , 1 ) ) {
F_39 ( L_18 ) ;
F_15 ( V_37 -> V_44 , V_138 ,
V_18 ) ;
V_124 = - V_139 ;
goto V_93;
}
F_4 ( 2 , L_19 , V_18 -> V_140 ) ;
} else if ( V_3 -> type == V_115 ) {
V_18 -> V_118 = F_1 ( V_3 , V_96 ) ;
V_18 -> V_116 = V_104 -> V_106 ;
V_18 -> V_117 = V_104 -> V_107 ;
F_4 ( 2 , L_20 , V_18 -> V_118 -> V_132 ) ;
F_4 ( 2 , L_21 ,
V_104 -> V_106 , V_104 -> V_107 ,
V_18 -> V_116 , V_18 -> V_117 ) ;
F_15 ( V_37 -> V_44 , V_141 , V_18 ) ;
V_104 -> V_111 [ 0 ] . V_114 = V_18 -> V_120 ;
V_104 -> V_111 [ 0 ] . V_112 = V_18 -> V_119 ;
V_104 -> V_111 [ 1 ] . V_114 = V_18 -> V_121 ;
V_104 -> V_111 [ 1 ] . V_112 = V_18 -> V_119 ;
V_18 -> V_142 = 0 ;
V_18 -> V_143 = V_135 ;
} else {
F_39 ( L_13 ) ;
return - V_100 ;
}
V_93:
F_46 () ;
return V_124 ;
}
static int F_47 ( struct V_76 * V_76 , void * V_77 ,
struct V_144 * V_145 )
{
struct V_36 * V_37 = F_28 ( V_76 ) ;
struct V_17 * V_18 = F_38 ( V_77 ) ;
int V_124 = 0 ;
if ( ( V_145 -> V_146 != V_147 ) &&
( V_145 -> V_146 != V_148 ) )
return - V_100 ;
if ( V_145 -> type == V_105 ) {
if ( V_18 -> V_134 != V_135 ) {
F_39 ( L_22 ,
V_18 -> V_134 ) ;
return - V_100 ;
}
V_124 = F_48 ( & V_18 -> V_127 , V_145 ) ;
if ( V_124 != 0 ) {
F_39 ( L_23 ) ;
return V_124 ;
}
V_18 -> V_134 = V_149 ;
V_124 = F_15 ( V_18 -> V_37 -> V_44 ,
V_150 , V_18 ) ;
if ( V_124 ) {
F_39 ( L_24 ) ;
V_145 -> V_151 = 0 ;
V_124 = F_48 ( & V_18 -> V_127 , V_145 ) ;
return - V_152 ;
}
} else if ( V_145 -> type == V_115 ) {
if ( V_18 -> V_143 != V_135 ) {
F_39 ( L_25 ,
V_18 -> V_143 ) ;
return - V_100 ;
}
if ( F_20 ( V_37 ) ) {
if ( V_18 -> V_56 &&
( V_145 -> V_151 < V_18 -> V_56 ) ) {
V_145 -> V_151 = V_18 -> V_56 ;
F_4 ( 2 , L_26 ,
V_18 -> V_56 ) ;
} else {
V_18 -> V_56 = V_145 -> V_151 ;
}
}
V_124 = F_48 ( & V_18 -> V_125 , V_145 ) ;
if ( V_124 != 0 ) {
F_39 ( L_27 ) ;
return V_124 ;
}
V_18 -> V_143 = V_149 ;
} else {
F_39 ( L_13 ) ;
return - V_100 ;
}
return V_124 ;
}
static int F_49 ( struct V_76 * V_76 , void * V_77 ,
struct V_153 * V_154 )
{
struct V_17 * V_18 = F_38 ( V_77 ) ;
int V_124 = 0 ;
if ( ( V_154 -> V_146 != V_147 ) &&
( V_154 -> V_146 != V_148 ) )
return - V_100 ;
if ( V_154 -> type == V_105 ) {
if ( V_18 -> V_21 != V_22 ) {
F_39 ( L_28 , V_18 -> V_21 ) ;
return - V_100 ;
}
V_124 = F_50 ( & V_18 -> V_127 , V_154 ) ;
if ( V_124 != 0 ) {
F_39 ( L_29 ) ;
return V_124 ;
}
V_154 -> V_155 . V_156 [ 0 ] . V_155 . V_157 += V_158 ;
} else if ( V_154 -> type == V_115 ) {
V_124 = F_50 ( & V_18 -> V_125 , V_154 ) ;
if ( V_124 != 0 ) {
F_39 ( L_30 ) ;
return V_124 ;
}
} else {
F_39 ( L_13 ) ;
return - V_100 ;
}
return V_124 ;
}
static int F_51 ( struct V_76 * V_76 , void * V_77 , struct V_153 * V_154 )
{
struct V_17 * V_18 = F_38 ( V_77 ) ;
if ( V_18 -> V_21 == V_159 ) {
F_39 ( L_31 ) ;
return - V_139 ;
}
if ( V_154 -> type == V_115 ) {
if ( V_18 -> V_21 == V_25 ) {
F_39 ( L_32 ) ;
return - V_139 ;
}
return F_52 ( & V_18 -> V_125 , V_154 ) ;
} else if ( V_154 -> type == V_105 ) {
return F_52 ( & V_18 -> V_127 , V_154 ) ;
}
return - V_100 ;
}
static int F_53 ( struct V_76 * V_76 , void * V_77 , struct V_153 * V_154 )
{
const struct V_160 V_161 = {
. type = V_162
} ;
struct V_17 * V_18 = F_38 ( V_77 ) ;
int V_124 ;
if ( V_18 -> V_21 == V_159 ) {
F_39 ( L_33 ) ;
return - V_139 ;
}
if ( V_154 -> type == V_115 ) {
V_124 = F_54 ( & V_18 -> V_125 , V_154 , V_76 -> V_163 & V_164 ) ;
} else if ( V_154 -> type == V_105 ) {
V_124 = F_54 ( & V_18 -> V_127 , V_154 , V_76 -> V_163 & V_164 ) ;
if ( V_124 == 0 && V_18 -> V_21 == V_165
&& F_6 ( & V_18 -> V_127 . V_166 ) )
F_55 ( & V_18 -> V_167 , & V_161 ) ;
} else {
V_124 = - V_100 ;
}
return V_124 ;
}
static int F_56 ( struct V_76 * V_76 , void * V_77 ,
struct V_168 * V_169 )
{
struct V_17 * V_18 = F_38 ( V_77 ) ;
if ( V_169 -> type == V_115 )
return F_57 ( & V_18 -> V_125 , V_169 ) ;
if ( V_169 -> type == V_105 )
return F_57 ( & V_18 -> V_127 , V_169 ) ;
return - V_100 ;
}
static int F_58 ( struct V_76 * V_76 , void * V_77 ,
enum V_170 type )
{
struct V_17 * V_18 = F_38 ( V_77 ) ;
if ( type == V_115 )
return F_59 ( & V_18 -> V_125 , type ) ;
else if ( type == V_105 )
return F_59 ( & V_18 -> V_127 , type ) ;
return - V_100 ;
}
static int F_60 ( struct V_76 * V_76 , void * V_77 ,
enum V_170 type )
{
struct V_17 * V_18 = F_38 ( V_77 ) ;
if ( type == V_115 )
return F_61 ( & V_18 -> V_125 , type ) ;
else if ( type == V_105 )
return F_61 ( & V_18 -> V_127 , type ) ;
return - V_100 ;
}
static inline int F_62 ( enum V_171 V_172 )
{
static unsigned int V_4 [ V_173 + 1 ] = {
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
return V_4 [ V_172 ] ;
}
static inline int F_63 ( enum V_174 V_172 )
{
static unsigned int V_4 [ V_175 + 1 ] = {
0 ,
9 ,
1 ,
2 ,
3 ,
7 ,
4 ,
5 ,
} ;
return V_4 [ V_172 ] ;
}
static inline int F_64 ( enum V_176 V_177 )
{
static unsigned int V_4 [ V_178 + 1 ] = {
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
return V_4 [ V_177 ] ;
}
static int F_65 ( struct V_179 * V_180 )
{
struct V_17 * V_18 = F_66 ( V_180 ) ;
struct V_36 * V_37 = V_18 -> V_37 ;
struct V_46 * V_47 = & V_18 -> V_48 ;
int V_124 = 0 ;
switch ( V_180 -> V_12 ) {
case V_181 :
V_47 -> V_182 = V_180 -> V_183 ;
break;
case V_184 :
V_47 -> V_185 = V_180 -> V_183 ;
break;
case V_186 :
V_47 -> V_187 = V_180 -> V_183 ;
break;
case V_188 :
V_47 -> V_189 = V_180 -> V_183 * 8 ;
break;
case V_190 :
V_47 -> V_191 = V_180 -> V_183 ;
break;
case V_192 :
V_47 -> V_193 = V_180 -> V_183 ;
break;
case V_194 :
V_47 -> V_195 = ( V_180 -> V_183 >> 16 ) & 0xff ;
V_47 -> V_196 = ( V_180 -> V_183 >> 8 ) & 0xff ;
V_47 -> V_197 = ( V_180 -> V_183 >> 0 ) & 0xff ;
break;
case V_198 :
V_47 -> V_199 = V_180 -> V_183 ;
break;
case V_200 :
V_47 -> V_201 = V_180 -> V_183 ;
break;
case V_202 :
V_47 -> V_203 = V_180 -> V_183 ;
break;
case V_16 :
V_18 -> V_204 = V_180 -> V_183 ;
break;
case V_205 :
V_47 -> V_206 = V_180 -> V_183 ;
break;
case V_207 :
V_47 -> V_208 . V_209 . V_210 = V_180 -> V_183 ;
break;
case V_211 :
V_47 -> V_50 = V_180 -> V_183 ;
break;
case V_15 :
V_47 -> V_212 = V_180 -> V_183 ;
break;
case V_213 :
V_47 -> V_214 = V_180 -> V_183 ;
break;
case V_215 :
V_47 -> V_216 = V_180 -> V_183 ;
break;
case V_217 :
switch ( V_180 -> V_183 ) {
case V_218 :
V_47 -> V_208 . V_209 . V_219 =
V_220 ;
break;
case V_221 :
V_47 -> V_208 . V_209 . V_219 =
V_222 ;
break;
case V_223 :
V_47 -> V_208 . V_209 . V_219 =
V_224 ;
break;
case V_225 :
if ( F_20 ( V_37 ) )
V_47 -> V_208 . V_209 . V_219 =
V_226 ;
else
V_124 = - V_100 ;
break;
default:
V_124 = - V_100 ;
}
break;
case V_227 :
V_47 -> V_208 . V_209 . V_228 = V_180 -> V_183 ;
V_47 -> V_208 . V_209 . V_229 = F_62 ( V_180 -> V_183 ) ;
if ( V_47 -> V_208 . V_209 . V_229 < 0 ) {
F_39 ( L_34 ) ;
V_124 = V_47 -> V_208 . V_209 . V_229 ;
}
break;
case V_230 :
V_47 -> V_208 . V_231 . V_228 = V_180 -> V_183 ;
V_47 -> V_208 . V_231 . V_229 = F_63 ( V_180 -> V_183 ) ;
if ( V_47 -> V_208 . V_231 . V_229 < 0 ) {
F_39 ( L_34 ) ;
V_124 = V_47 -> V_208 . V_231 . V_229 ;
}
break;
case V_232 :
V_47 -> V_208 . V_209 . V_233 = V_180 -> V_183 ;
break;
case V_234 :
V_47 -> V_208 . V_209 . V_235 = V_180 -> V_183 ;
break;
case V_236 :
V_47 -> V_208 . V_209 . V_237 = V_180 -> V_183 ;
break;
case V_238 :
V_47 -> V_208 . V_209 . V_239 = V_180 -> V_183 ;
break;
case V_240 :
V_47 -> V_208 . V_209 . V_241 = V_180 -> V_183 ;
break;
case V_242 :
V_47 -> V_208 . V_209 . V_243 = V_180 -> V_183 ;
break;
case V_244 :
V_47 -> V_245 = V_180 -> V_183 ;
break;
case V_246 :
V_47 -> V_208 . V_209 . V_247 = V_180 -> V_183 ;
break;
case V_248 :
V_47 -> V_208 . V_209 . V_249 = V_180 -> V_183 ;
break;
case V_250 :
V_47 -> V_208 . V_209 . V_251 = V_180 -> V_183 ;
break;
case V_252 :
V_47 -> V_208 . V_209 . V_253 = V_180 -> V_183 ;
break;
case V_254 :
V_47 -> V_208 . V_209 . V_255 = V_180 -> V_183 ;
break;
case V_256 :
case V_257 :
V_47 -> V_208 . V_231 . V_247 = V_180 -> V_183 ;
break;
case V_258 :
case V_259 :
V_47 -> V_208 . V_231 . V_249 = V_180 -> V_183 ;
break;
case V_260 :
case V_261 :
V_47 -> V_208 . V_231 . V_251 = V_180 -> V_183 ;
break;
case V_262 :
case V_263 :
V_47 -> V_208 . V_231 . V_253 = V_180 -> V_183 ;
break;
case V_264 :
case V_265 :
V_47 -> V_208 . V_231 . V_255 = V_180 -> V_183 ;
break;
case V_266 :
V_47 -> V_208 . V_209 . V_267 = V_180 -> V_183 ;
break;
case V_268 :
V_47 -> V_208 . V_209 . V_269 = V_180 -> V_183 ;
break;
case V_270 :
V_47 -> V_208 . V_209 . V_271 = V_180 -> V_183 ;
break;
case V_272 :
V_47 -> V_208 . V_209 . V_273 = V_180 -> V_183 ;
break;
case V_274 :
V_47 -> V_208 . V_209 . V_275 = V_180 -> V_183 ;
break;
case V_276 :
V_47 -> V_208 . V_209 . F_64 = F_64 ( V_180 -> V_183 ) ;
break;
case V_277 :
V_47 -> V_208 . V_209 . V_278 = V_180 -> V_183 ;
break;
case V_279 :
V_47 -> V_208 . V_209 . V_280 = V_180 -> V_183 ;
break;
case V_281 :
V_47 -> V_208 . V_209 . V_282 = ! V_180 -> V_183 ;
break;
case V_283 :
V_47 -> V_208 . V_209 . V_284 = V_180 -> V_183 ;
break;
case V_285 :
switch ( V_180 -> V_183 ) {
case V_286 :
V_47 -> V_208 . V_231 . V_219 =
V_287 ;
break;
case V_288 :
V_47 -> V_208 . V_231 . V_219 =
V_289 ;
break;
default:
V_124 = - V_100 ;
}
break;
case V_290 :
V_47 -> V_208 . V_231 . V_291 = V_180 -> V_183 ;
break;
default:
F_43 ( & V_37 -> V_128 , L_35 ,
V_180 -> V_12 , V_180 -> V_183 ) ;
V_124 = - V_100 ;
}
return V_124 ;
}
static int F_67 ( struct V_76 * V_76 , void * V_77 ,
struct V_292 * V_293 )
{
struct V_17 * V_18 = F_38 ( V_77 ) ;
if ( V_293 -> type == V_115 ) {
V_18 -> V_48 . V_294 =
V_293 -> V_295 . V_296 . V_297 . V_298 ;
V_18 -> V_48 . V_299 =
V_293 -> V_295 . V_296 . V_297 . V_300 ;
} else {
F_39 ( L_36 ) ;
return - V_100 ;
}
return 0 ;
}
static int F_68 ( struct V_76 * V_76 , void * V_77 ,
struct V_292 * V_293 )
{
struct V_17 * V_18 = F_38 ( V_77 ) ;
if ( V_293 -> type == V_301 ) {
V_293 -> V_295 . V_296 . V_297 . V_298 =
V_18 -> V_48 . V_294 ;
V_293 -> V_295 . V_296 . V_297 . V_300 =
V_18 -> V_48 . V_299 ;
} else {
F_39 ( L_36 ) ;
return - V_100 ;
}
return 0 ;
}
int F_69 ( struct V_76 * V_76 , void * V_77 ,
struct V_302 * V_303 )
{
struct V_17 * V_18 = F_38 ( V_77 ) ;
struct V_36 * V_37 = V_18 -> V_37 ;
struct V_26 * V_154 ;
unsigned long V_41 ;
switch ( V_303 -> V_303 ) {
case V_304 :
if ( V_303 -> V_41 != 0 )
return - V_100 ;
if ( ! V_18 -> V_125 . V_126 )
return - V_100 ;
F_13 ( & V_37 -> V_42 , V_41 ) ;
if ( F_6 ( & V_18 -> V_35 ) ) {
F_4 ( 2 , L_37 ) ;
V_18 -> V_21 = V_25 ;
if ( F_3 ( V_18 ) )
F_21 ( V_18 ) ;
F_16 ( & V_37 -> V_42 , V_41 ) ;
F_15 ( V_37 -> V_44 , V_54 , V_37 ) ;
} else {
F_4 ( 2 , L_38 ) ;
V_154 = F_7 ( V_18 -> V_35 . V_305 ,
struct V_26 , V_32 ) ;
if ( V_154 -> V_41 & V_68 )
V_18 -> V_21 = V_25 ;
else
V_154 -> V_41 |= V_306 ;
F_16 ( & V_37 -> V_42 , V_41 ) ;
}
break;
default:
return - V_100 ;
}
return 0 ;
}
static int F_70 ( struct V_307 * V_167 ,
const struct V_308 * V_309 )
{
switch ( V_309 -> type ) {
case V_162 :
return F_71 ( V_167 , V_309 , 2 , NULL ) ;
default:
return - V_100 ;
}
}
static int F_72 ( struct V_1 * V_9 , struct V_310 * V_311 )
{
int V_5 ;
if ( ! V_9 )
return - V_100 ;
if ( V_9 -> V_95 != V_311 -> V_95 ) {
F_39 ( L_39 ) ;
return - V_100 ;
}
for ( V_5 = 0 ; V_5 < V_9 -> V_95 ; V_5 ++ ) {
if ( ! F_8 ( V_311 , V_5 ) ) {
F_39 ( L_40 ) ;
return - V_100 ;
}
F_4 ( 2 , L_41 ,
V_311 -> V_70 . V_98 , V_5 ,
F_8 ( V_311 , V_5 ) ) ;
}
return 0 ;
}
static int F_73 ( struct V_312 * V_313 ,
const struct V_2 * V_9 ,
unsigned int * V_314 , unsigned int * V_315 ,
unsigned int V_316 [] , void * V_317 [] )
{
struct V_17 * V_18 = F_38 ( V_313 -> V_318 ) ;
struct V_36 * V_37 = V_18 -> V_37 ;
if ( V_18 -> V_21 != V_22 ) {
F_39 ( L_42 , V_18 -> V_21 ) ;
return - V_100 ;
}
if ( V_313 -> type == V_105 ) {
if ( V_18 -> V_110 )
* V_315 = V_18 -> V_110 -> V_95 ;
else
* V_315 = V_319 ;
if ( * V_314 < 1 )
* V_314 = 1 ;
if ( * V_314 > V_320 )
* V_314 = V_320 ;
V_316 [ 0 ] = V_18 -> V_113 ;
V_317 [ 0 ] = V_18 -> V_37 -> V_321 [ V_322 ] ;
} else if ( V_313 -> type == V_115 ) {
if ( V_18 -> V_118 )
* V_315 = V_18 -> V_118 -> V_95 ;
else
* V_315 = V_323 ;
if ( * V_314 < 1 )
* V_314 = 1 ;
if ( * V_314 > V_320 )
* V_314 = V_320 ;
V_316 [ 0 ] = V_18 -> V_120 ;
V_316 [ 1 ] = V_18 -> V_121 ;
if ( F_20 ( V_37 ) ) {
V_317 [ 0 ] =
V_18 -> V_37 -> V_321 [ V_322 ] ;
V_317 [ 1 ] =
V_18 -> V_37 -> V_321 [ V_322 ] ;
} else {
V_317 [ 0 ] =
V_18 -> V_37 -> V_321 [ V_324 ] ;
V_317 [ 1 ] =
V_18 -> V_37 -> V_321 [ V_324 ] ;
}
} else {
F_39 ( L_43 , V_313 -> type ) ;
return - V_100 ;
}
return 0 ;
}
static void F_74 ( struct V_312 * V_325 )
{
struct V_17 * V_18 = F_38 ( V_325 -> V_318 ) ;
struct V_36 * V_37 = V_18 -> V_37 ;
F_75 ( & V_37 -> V_326 ) ;
}
static void F_76 ( struct V_312 * V_325 )
{
struct V_17 * V_18 = F_38 ( V_325 -> V_318 ) ;
struct V_36 * V_37 = V_18 -> V_37 ;
F_77 ( & V_37 -> V_326 ) ;
}
static int F_78 ( struct V_310 * V_311 )
{
struct V_312 * V_313 = V_311 -> V_312 ;
struct V_17 * V_18 = F_38 ( V_313 -> V_318 ) ;
unsigned int V_5 ;
int V_124 ;
if ( V_313 -> type == V_105 ) {
V_124 = F_72 ( V_18 -> V_110 , V_311 ) ;
if ( V_124 < 0 )
return V_124 ;
V_5 = V_311 -> V_70 . V_98 ;
V_18 -> V_327 [ V_5 ] . V_33 = V_311 ;
V_18 -> V_327 [ V_5 ] . V_328 . V_329 =
F_8 ( V_311 , 0 ) ;
V_18 -> V_133 ++ ;
} else if ( V_313 -> type == V_115 ) {
V_124 = F_72 ( V_18 -> V_118 , V_311 ) ;
if ( V_124 < 0 )
return V_124 ;
V_5 = V_311 -> V_70 . V_98 ;
V_18 -> V_330 [ V_5 ] . V_33 = V_311 ;
V_18 -> V_330 [ V_5 ] . V_328 . V_331 . V_332 =
F_8 ( V_311 , 0 ) ;
V_18 -> V_330 [ V_5 ] . V_328 . V_331 . V_333 =
F_8 ( V_311 , 1 ) ;
V_18 -> V_142 ++ ;
} else {
F_39 ( L_43 , V_313 -> type ) ;
return - V_100 ;
}
return 0 ;
}
static int F_79 ( struct V_310 * V_311 )
{
struct V_312 * V_313 = V_311 -> V_312 ;
struct V_17 * V_18 = F_38 ( V_313 -> V_318 ) ;
int V_124 ;
if ( V_313 -> type == V_105 ) {
V_124 = F_72 ( V_18 -> V_110 , V_311 ) ;
if ( V_124 < 0 )
return V_124 ;
F_4 ( 2 , L_44 ,
F_14 ( V_311 , 0 ) , V_18 -> V_113 ) ;
if ( F_14 ( V_311 , 0 ) < V_18 -> V_113 ) {
F_39 ( L_45 ) ;
return - V_100 ;
}
} else if ( V_313 -> type == V_115 ) {
V_124 = F_72 ( V_18 -> V_118 , V_311 ) ;
if ( V_124 < 0 )
return V_124 ;
F_4 ( 2 , L_46 ,
F_14 ( V_311 , 0 ) , V_18 -> V_120 ) ;
F_4 ( 2 , L_47 ,
F_14 ( V_311 , 1 ) , V_18 -> V_121 ) ;
if ( F_14 ( V_311 , 0 ) < V_18 -> V_120 ||
F_14 ( V_311 , 1 ) < V_18 -> V_121 ) {
F_39 ( L_48 ) ;
return - V_100 ;
}
} else {
F_39 ( L_43 , V_313 -> type ) ;
return - V_100 ;
}
return 0 ;
}
static int F_80 ( struct V_312 * V_325 , unsigned int V_151 )
{
struct V_17 * V_18 = F_38 ( V_325 -> V_318 ) ;
struct V_36 * V_37 = V_18 -> V_37 ;
if ( F_20 ( V_37 ) && ( V_325 -> type == V_105 ) ) {
if ( ( V_18 -> V_21 == V_22 ) &&
( V_37 -> V_334 == V_18 -> V_335 ) && V_37 -> V_336 ) {
F_45 ( V_18 ,
V_337 ,
0 ) ;
}
if ( V_18 -> V_142 < V_18 -> V_56 ) {
F_39 ( L_49 ,
V_18 -> V_56 ) ;
return - V_100 ;
}
}
if ( F_3 ( V_18 ) )
F_21 ( V_18 ) ;
F_15 ( V_37 -> V_44 , V_54 , V_37 ) ;
return 0 ;
}
static int F_81 ( struct V_312 * V_325 )
{
unsigned long V_41 ;
struct V_17 * V_18 = F_38 ( V_325 -> V_318 ) ;
struct V_36 * V_37 = V_18 -> V_37 ;
if ( ( V_18 -> V_21 == V_25 ||
V_18 -> V_21 == V_23 ) &&
V_37 -> V_334 == V_18 -> V_335 && V_37 -> V_336 ) {
V_18 -> V_21 = V_338 ;
F_45 ( V_18 , V_339 ,
0 ) ;
}
V_18 -> V_21 = V_165 ;
F_13 ( & V_37 -> V_42 , V_41 ) ;
if ( V_325 -> type == V_105 ) {
F_15 ( V_37 -> V_44 , V_340 , & V_18 -> V_43 ,
& V_18 -> V_127 ) ;
F_11 ( & V_18 -> V_43 ) ;
V_18 -> V_20 = 0 ;
}
if ( V_325 -> type == V_115 ) {
F_5 ( V_18 ) ;
F_15 ( V_37 -> V_44 , V_340 , & V_18 -> V_35 ,
& V_18 -> V_125 ) ;
F_11 ( & V_18 -> V_35 ) ;
V_18 -> V_19 = 0 ;
}
F_16 ( & V_37 -> V_42 , V_41 ) ;
return 0 ;
}
static void F_82 ( struct V_310 * V_311 )
{
struct V_312 * V_313 = V_311 -> V_312 ;
struct V_17 * V_18 = F_38 ( V_313 -> V_318 ) ;
struct V_36 * V_37 = V_18 -> V_37 ;
unsigned long V_41 ;
struct V_26 * V_341 ;
if ( V_18 -> V_21 == V_159 ) {
F_19 ( V_311 , V_342 ) ;
F_5 ( V_18 ) ;
return;
}
if ( V_313 -> type == V_105 ) {
V_341 = & V_18 -> V_327 [ V_311 -> V_70 . V_98 ] ;
V_341 -> V_41 &= ~ V_68 ;
F_13 ( & V_37 -> V_42 , V_41 ) ;
F_10 ( & V_341 -> V_32 , & V_18 -> V_43 ) ;
V_18 -> V_20 ++ ;
F_16 ( & V_37 -> V_42 , V_41 ) ;
} else if ( V_313 -> type == V_115 ) {
V_341 = & V_18 -> V_330 [ V_311 -> V_70 . V_98 ] ;
V_341 -> V_41 &= ~ V_68 ;
F_13 ( & V_37 -> V_42 , V_41 ) ;
F_10 ( & V_341 -> V_32 , & V_18 -> V_35 ) ;
V_18 -> V_19 ++ ;
F_16 ( & V_37 -> V_42 , V_41 ) ;
} else {
F_39 ( L_50 , V_313 -> type ) ;
}
if ( F_3 ( V_18 ) )
F_21 ( V_18 ) ;
F_15 ( V_37 -> V_44 , V_54 , V_37 ) ;
}
struct V_343 * F_83 ( void )
{
return & V_344 ;
}
struct V_345 * F_84 ( void )
{
return & V_346 ;
}
const struct V_347 * F_85 ( void )
{
return & V_348 ;
}
int F_86 ( struct V_17 * V_18 )
{
struct V_349 V_350 ;
int V_5 ;
F_87 ( & V_18 -> V_351 , V_352 ) ;
if ( V_18 -> V_351 . error ) {
F_39 ( L_51 ) ;
return V_18 -> V_351 . error ;
}
for ( V_5 = 0 ; V_5 < V_352 ; V_5 ++ ) {
if ( F_88 ( V_353 [ V_5 ] . V_12 ) ) {
memset ( & V_350 , 0 , sizeof( struct V_349 ) ) ;
V_350 . V_354 = & V_355 ;
V_350 . V_12 = V_353 [ V_5 ] . V_12 ;
V_350 . V_356 = V_353 [ V_5 ] . V_357 ;
V_350 . V_358 = V_353 [ V_5 ] . V_359 ;
V_350 . V_360 = V_353 [ V_5 ] . V_361 ;
V_350 . V_82 = V_353 [ V_5 ] . V_82 ;
V_350 . type = V_353 [ V_5 ] . type ;
V_350 . V_41 = 0 ;
if ( V_350 . type == V_362 ) {
V_350 . V_363 = 0 ;
V_350 . V_364 = V_350 . V_364 ;
V_350 . V_365 = F_2 ( V_350 . V_12 ) ;
} else {
V_350 . V_363 = V_353 [ V_5 ] . V_363 ;
V_350 . V_364 = 0 ;
}
V_18 -> V_366 [ V_5 ] = F_89 ( & V_18 -> V_351 ,
& V_350 , NULL ) ;
} else {
if ( V_353 [ V_5 ] . type == V_362 ) {
V_18 -> V_366 [ V_5 ] = F_90 (
& V_18 -> V_351 ,
& V_355 , V_353 [ V_5 ] . V_12 ,
V_353 [ V_5 ] . V_359 , 0 ,
V_353 [ V_5 ] . V_361 ) ;
} else {
V_18 -> V_366 [ V_5 ] = F_91 (
& V_18 -> V_351 ,
& V_355 , V_353 [ V_5 ] . V_12 ,
V_353 [ V_5 ] . V_357 ,
V_353 [ V_5 ] . V_359 , V_353 [ V_5 ] . V_363 ,
V_353 [ V_5 ] . V_361 ) ;
}
}
if ( V_18 -> V_351 . error ) {
F_39 ( L_52 , V_5 ) ;
return V_18 -> V_351 . error ;
}
if ( V_353 [ V_5 ] . V_367 && V_18 -> V_366 [ V_5 ] )
V_18 -> V_366 [ V_5 ] -> V_41 |= V_368 ;
}
F_92 ( & V_18 -> V_351 ) ;
return 0 ;
}
void F_93 ( struct V_17 * V_18 )
{
int V_5 ;
F_94 ( & V_18 -> V_351 ) ;
for ( V_5 = 0 ; V_5 < V_352 ; V_5 ++ )
V_18 -> V_366 [ V_5 ] = NULL ;
}
void F_95 ( struct V_17 * V_18 )
{
struct V_2 V_3 ;
V_3 . V_9 . V_10 . V_11 = V_369 ;
V_18 -> V_118 = F_1 ( & V_3 , V_96 ) ;
V_3 . V_9 . V_10 . V_11 = V_370 ;
V_18 -> V_110 = F_1 ( & V_3 , V_97 ) ;
}
