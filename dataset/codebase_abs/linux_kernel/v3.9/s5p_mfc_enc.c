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
if ( V_47 -> V_49 == V_50 ) {
F_13 ( & V_37 -> V_42 , V_41 ) ;
V_38 = F_7 ( V_18 -> V_43 . V_31 ,
struct V_26 , V_32 ) ;
F_9 ( & V_38 -> V_32 ) ;
V_18 -> V_20 -- ;
F_18 ( V_38 -> V_33 , 0 ,
F_15 ( V_37 -> V_44 , V_51 , V_37 ) ) ;
F_19 ( V_38 -> V_33 , V_52 ) ;
F_16 ( & V_37 -> V_42 , V_41 ) ;
}
if ( F_20 ( V_37 ) ) {
V_18 -> V_21 = V_24 ;
} else {
V_18 -> V_21 = V_23 ;
if ( F_3 ( V_18 ) )
F_21 ( V_18 ) ;
F_15 ( V_37 -> V_44 , V_53 , V_37 ) ;
}
if ( F_20 ( V_37 ) )
V_18 -> V_54 = F_15 ( V_37 -> V_44 ,
V_55 , V_37 ) ;
return 0 ;
}
static int F_22 ( struct V_17 * V_18 )
{
struct V_36 * V_37 = V_18 -> V_37 ;
struct V_26 * V_38 ;
struct V_26 * V_56 ;
unsigned long V_41 ;
unsigned long V_57 , V_58 , V_39 ;
unsigned int V_40 ;
F_13 ( & V_37 -> V_42 , V_41 ) ;
V_56 = F_7 ( V_18 -> V_35 . V_31 , struct V_26 , V_32 ) ;
V_57 = F_8 ( V_56 -> V_33 , 0 ) ;
V_58 = F_8 ( V_56 -> V_33 , 1 ) ;
F_15 ( V_37 -> V_44 , V_59 , V_18 , V_57 ,
V_58 ) ;
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
unsigned long V_60 , V_61 ;
unsigned long V_28 , V_29 ;
int V_62 ;
unsigned int V_63 ;
unsigned long V_41 ;
V_62 = F_15 ( V_37 -> V_44 , V_64 , V_37 ) ;
V_63 = F_15 ( V_37 -> V_44 , V_51 , V_37 ) ;
F_4 ( 2 , L_9 , V_62 ) ;
F_4 ( 2 , L_10 , V_63 ) ;
F_4 ( 2 , L_11 ,
F_24 ( V_37 , V_65 ) ) ;
F_13 ( & V_37 -> V_42 , V_41 ) ;
if ( V_62 >= 0 ) {
F_15 ( V_37 -> V_44 , V_66 , V_18 ,
& V_60 , & V_61 ) ;
F_25 (mb_entry, &ctx->src_queue, list) {
V_28 = F_8 ( V_27 -> V_33 , 0 ) ;
V_29 = F_8 ( V_27 -> V_33 , 1 ) ;
if ( ( V_60 == V_28 ) &&
( V_61 == V_29 ) ) {
F_9 ( & V_27 -> V_32 ) ;
V_18 -> V_19 -- ;
F_19 ( V_27 -> V_33 ,
V_52 ) ;
break;
}
}
F_25 (mb_entry, &ctx->ref_queue, list) {
V_28 = F_8 ( V_27 -> V_33 , 0 ) ;
V_29 = F_8 ( V_27 -> V_33 , 1 ) ;
if ( ( V_60 == V_28 ) &&
( V_61 == V_29 ) ) {
F_9 ( & V_27 -> V_32 ) ;
V_18 -> V_34 -- ;
F_19 ( V_27 -> V_33 ,
V_52 ) ;
break;
}
}
}
if ( ( V_18 -> V_19 > 0 ) && ( V_18 -> V_21 == V_23 ) ) {
V_27 = F_7 ( V_18 -> V_35 . V_31 , struct V_26 ,
V_32 ) ;
if ( V_27 -> V_41 & V_67 ) {
F_9 ( & V_27 -> V_32 ) ;
V_18 -> V_19 -- ;
F_10 ( & V_27 -> V_32 , & V_18 -> V_30 ) ;
V_18 -> V_34 ++ ;
}
F_4 ( 2 , L_8 ,
V_18 -> V_19 , V_18 -> V_34 ) ;
}
if ( V_63 > 0 ) {
V_27 = F_7 ( V_18 -> V_43 . V_31 , struct V_26 ,
V_32 ) ;
F_9 ( & V_27 -> V_32 ) ;
V_18 -> V_20 -- ;
switch ( V_62 ) {
case V_68 :
V_27 -> V_33 -> V_69 . V_41 |= V_70 ;
break;
case V_71 :
V_27 -> V_33 -> V_69 . V_41 |= V_72 ;
break;
case V_73 :
V_27 -> V_33 -> V_69 . V_41 |= V_74 ;
break;
}
F_18 ( V_27 -> V_33 , 0 , V_63 ) ;
F_19 ( V_27 -> V_33 , V_52 ) ;
}
F_16 ( & V_37 -> V_42 , V_41 ) ;
if ( ( V_18 -> V_19 == 0 ) || ( V_18 -> V_20 == 0 ) )
F_26 ( V_18 ) ;
return 0 ;
}
static int F_27 ( struct V_75 * V_75 , void * V_76 ,
struct V_77 * V_78 )
{
struct V_36 * V_37 = F_28 ( V_75 ) ;
strncpy ( V_78 -> V_79 , V_37 -> V_80 -> V_81 , sizeof( V_78 -> V_79 ) - 1 ) ;
strncpy ( V_78 -> V_82 , V_37 -> V_80 -> V_81 , sizeof( V_78 -> V_82 ) - 1 ) ;
V_78 -> V_83 [ 0 ] = 0 ;
V_78 -> V_84 = F_29 ( 1 , 0 , 0 ) ;
V_78 -> V_85 = V_86 | V_87 |
V_88 |
V_89 ;
return 0 ;
}
static int F_30 ( struct V_90 * V_3 , bool V_91 , bool V_92 )
{
struct V_1 * V_9 ;
int V_5 , V_93 = 0 ;
for ( V_5 = 0 ; V_5 < F_31 ( V_7 ) ; ++ V_5 ) {
if ( V_91 && V_7 [ V_5 ] . V_94 == 1 )
continue;
else if ( ! V_91 && V_7 [ V_5 ] . V_94 > 1 )
continue;
if ( V_92 && V_7 [ V_5 ] . type != V_95 )
continue;
else if ( ! V_92 && V_7 [ V_5 ] . type != V_96 )
continue;
if ( V_93 == V_3 -> V_97 ) {
V_9 = & V_7 [ V_5 ] ;
F_32 ( V_3 -> V_98 , V_9 -> V_81 ,
sizeof( V_3 -> V_98 ) ) ;
V_3 -> V_11 = V_9 -> V_8 ;
return 0 ;
}
++ V_93 ;
}
return - V_99 ;
}
static int F_33 ( struct V_75 * V_75 , void * V_100 ,
struct V_90 * V_3 )
{
return F_30 ( V_3 , false , false ) ;
}
static int F_34 ( struct V_75 * V_75 , void * V_100 ,
struct V_90 * V_3 )
{
return F_30 ( V_3 , true , false ) ;
}
static int F_35 ( struct V_75 * V_75 , void * V_101 ,
struct V_90 * V_3 )
{
return F_30 ( V_3 , false , true ) ;
}
static int F_36 ( struct V_75 * V_75 , void * V_101 ,
struct V_90 * V_3 )
{
return F_30 ( V_3 , true , true ) ;
}
static int F_37 ( struct V_75 * V_75 , void * V_76 , struct V_2 * V_3 )
{
struct V_17 * V_18 = F_38 ( V_76 ) ;
struct V_102 * V_103 = & V_3 -> V_9 . V_10 ;
F_4 ( 2 , L_12 , V_3 -> type , V_18 -> V_21 ) ;
if ( V_3 -> type == V_104 ) {
V_103 -> V_105 = 0 ;
V_103 -> V_106 = 0 ;
V_103 -> V_107 = V_108 ;
V_103 -> V_11 = V_18 -> V_109 -> V_8 ;
V_103 -> V_94 = V_18 -> V_109 -> V_94 ;
V_103 -> V_110 [ 0 ] . V_111 = V_18 -> V_112 ;
V_103 -> V_110 [ 0 ] . V_113 = V_18 -> V_112 ;
} else if ( V_3 -> type == V_114 ) {
V_103 -> V_105 = V_18 -> V_115 ;
V_103 -> V_106 = V_18 -> V_116 ;
V_103 -> V_107 = V_108 ;
V_103 -> V_11 = V_18 -> V_117 -> V_8 ;
V_103 -> V_94 = V_18 -> V_117 -> V_94 ;
V_103 -> V_110 [ 0 ] . V_111 = V_18 -> V_118 ;
V_103 -> V_110 [ 0 ] . V_113 = V_18 -> V_119 ;
V_103 -> V_110 [ 1 ] . V_111 = V_18 -> V_118 ;
V_103 -> V_110 [ 1 ] . V_113 = V_18 -> V_120 ;
} else {
F_39 ( L_13 ) ;
return - V_99 ;
}
return 0 ;
}
static int F_40 ( struct V_75 * V_75 , void * V_76 , struct V_2 * V_3 )
{
struct V_1 * V_9 ;
struct V_102 * V_103 = & V_3 -> V_9 . V_10 ;
if ( V_3 -> type == V_104 ) {
V_9 = F_1 ( V_3 , V_96 ) ;
if ( ! V_9 ) {
F_39 ( L_14 ) ;
return - V_99 ;
}
if ( V_103 -> V_110 [ 0 ] . V_113 == 0 ) {
F_39 ( L_15 ) ;
return - V_99 ;
}
V_103 -> V_110 [ 0 ] . V_111 =
V_103 -> V_110 [ 0 ] . V_113 ;
} else if ( V_3 -> type == V_114 ) {
V_9 = F_1 ( V_3 , V_95 ) ;
if ( ! V_9 ) {
F_39 ( L_14 ) ;
return - V_99 ;
}
if ( V_9 -> V_94 != V_103 -> V_94 ) {
F_39 ( L_14 ) ;
return - V_99 ;
}
F_41 ( & V_103 -> V_105 , 8 , 1920 , 1 ,
& V_103 -> V_106 , 4 , 1080 , 1 , 0 ) ;
} else {
F_39 ( L_13 ) ;
return - V_99 ;
}
return 0 ;
}
static int F_42 ( struct V_75 * V_75 , void * V_76 , struct V_2 * V_3 )
{
struct V_36 * V_37 = F_28 ( V_75 ) ;
struct V_17 * V_18 = F_38 ( V_76 ) ;
struct V_1 * V_9 ;
struct V_102 * V_103 = & V_3 -> V_9 . V_10 ;
int V_121 = 0 ;
V_121 = F_40 ( V_75 , V_76 , V_3 ) ;
if ( V_121 )
return V_121 ;
if ( V_18 -> V_122 . V_123 || V_18 -> V_124 . V_123 ) {
F_43 ( & V_37 -> V_125 , L_16 , V_126 ) ;
V_121 = - V_127 ;
goto V_92;
}
if ( V_3 -> type == V_104 ) {
V_9 = F_1 ( V_3 , V_96 ) ;
if ( ! V_9 ) {
F_39 ( L_17 ) ;
return - V_99 ;
}
V_18 -> V_21 = V_128 ;
V_18 -> V_109 = V_9 ;
V_18 -> V_129 = V_18 -> V_109 -> V_129 ;
V_18 -> V_112 = V_103 -> V_110 [ 0 ] . V_113 ;
V_103 -> V_110 [ 0 ] . V_111 = 0 ;
V_18 -> V_130 = 0 ;
V_18 -> V_131 = V_132 ;
F_15 ( V_37 -> V_44 , V_133 , V_18 ) ;
F_21 ( V_18 ) ;
F_44 ( V_18 ) ;
F_15 ( V_37 -> V_44 , V_53 , V_37 ) ;
if ( F_45 ( V_18 , \
V_134 , 1 ) ) {
F_39 ( L_18 ) ;
F_15 ( V_37 -> V_44 , V_135 ,
V_18 ) ;
V_121 = - V_136 ;
goto V_92;
}
F_4 ( 2 , L_19 , V_18 -> V_137 ) ;
} else if ( V_3 -> type == V_114 ) {
V_9 = F_1 ( V_3 , V_95 ) ;
if ( ! V_9 ) {
F_39 ( L_20 ) ;
return - V_99 ;
}
if ( ! F_20 ( V_37 ) &&
( V_9 -> V_8 == V_138 ) ) {
F_39 ( L_21 ) ;
return - V_99 ;
} else if ( F_20 ( V_37 ) &&
( V_9 -> V_8 == V_139 ) ) {
F_39 ( L_21 ) ;
return - V_99 ;
}
if ( V_9 -> V_94 != V_103 -> V_94 ) {
F_39 ( L_20 ) ;
V_121 = - V_99 ;
goto V_92;
}
V_18 -> V_117 = V_9 ;
V_18 -> V_115 = V_103 -> V_105 ;
V_18 -> V_116 = V_103 -> V_106 ;
F_4 ( 2 , L_22 , V_18 -> V_117 -> V_129 ) ;
F_4 ( 2 , L_23 ,
V_103 -> V_105 , V_103 -> V_106 ,
V_18 -> V_115 , V_18 -> V_116 ) ;
F_15 ( V_37 -> V_44 , V_140 , V_18 ) ;
V_103 -> V_110 [ 0 ] . V_113 = V_18 -> V_119 ;
V_103 -> V_110 [ 0 ] . V_111 = V_18 -> V_118 ;
V_103 -> V_110 [ 1 ] . V_113 = V_18 -> V_120 ;
V_103 -> V_110 [ 1 ] . V_111 = V_18 -> V_118 ;
V_18 -> V_141 = 0 ;
V_18 -> V_142 = V_132 ;
} else {
F_39 ( L_13 ) ;
return - V_99 ;
}
V_92:
F_46 () ;
return V_121 ;
}
static int F_47 ( struct V_75 * V_75 , void * V_76 ,
struct V_143 * V_144 )
{
struct V_36 * V_37 = F_28 ( V_75 ) ;
struct V_17 * V_18 = F_38 ( V_76 ) ;
int V_121 = 0 ;
if ( ( V_144 -> V_145 != V_146 ) &&
( V_144 -> V_145 != V_147 ) )
return - V_99 ;
if ( V_144 -> type == V_104 ) {
if ( V_18 -> V_131 != V_132 ) {
F_39 ( L_24 ,
V_18 -> V_131 ) ;
return - V_99 ;
}
V_121 = F_48 ( & V_18 -> V_124 , V_144 ) ;
if ( V_121 != 0 ) {
F_39 ( L_25 ) ;
return V_121 ;
}
V_18 -> V_131 = V_148 ;
if ( ! F_20 ( V_37 ) ) {
V_121 = F_15 ( V_18 -> V_37 -> V_44 ,
V_149 , V_18 ) ;
if ( V_121 ) {
F_39 ( L_26 ) ;
V_144 -> V_150 = 0 ;
V_121 = F_48 ( & V_18 -> V_124 , V_144 ) ;
return - V_151 ;
}
}
} else if ( V_144 -> type == V_114 ) {
if ( V_18 -> V_142 != V_132 ) {
F_39 ( L_27 ,
V_18 -> V_142 ) ;
return - V_99 ;
}
V_121 = F_48 ( & V_18 -> V_122 , V_144 ) ;
if ( V_121 != 0 ) {
F_39 ( L_28 ) ;
return V_121 ;
}
V_18 -> V_142 = V_148 ;
} else {
F_39 ( L_13 ) ;
return - V_99 ;
}
return V_121 ;
}
static int F_49 ( struct V_75 * V_75 , void * V_76 ,
struct V_152 * V_153 )
{
struct V_17 * V_18 = F_38 ( V_76 ) ;
int V_121 = 0 ;
if ( ( V_153 -> V_145 != V_146 ) &&
( V_153 -> V_145 != V_147 ) )
return - V_99 ;
if ( V_153 -> type == V_104 ) {
if ( V_18 -> V_21 != V_22 ) {
F_39 ( L_29 , V_18 -> V_21 ) ;
return - V_99 ;
}
V_121 = F_50 ( & V_18 -> V_124 , V_153 ) ;
if ( V_121 != 0 ) {
F_39 ( L_30 ) ;
return V_121 ;
}
V_153 -> V_154 . V_155 [ 0 ] . V_154 . V_156 += V_157 ;
} else if ( V_153 -> type == V_114 ) {
V_121 = F_50 ( & V_18 -> V_122 , V_153 ) ;
if ( V_121 != 0 ) {
F_39 ( L_31 ) ;
return V_121 ;
}
} else {
F_39 ( L_13 ) ;
return - V_99 ;
}
return V_121 ;
}
static int F_51 ( struct V_75 * V_75 , void * V_76 , struct V_152 * V_153 )
{
struct V_17 * V_18 = F_38 ( V_76 ) ;
if ( V_18 -> V_21 == V_158 ) {
F_39 ( L_32 ) ;
return - V_136 ;
}
if ( V_153 -> type == V_114 ) {
if ( V_18 -> V_21 == V_25 ) {
F_39 ( L_33 ) ;
return - V_136 ;
}
return F_52 ( & V_18 -> V_122 , V_153 ) ;
} else if ( V_153 -> type == V_104 ) {
return F_52 ( & V_18 -> V_124 , V_153 ) ;
}
return - V_99 ;
}
static int F_53 ( struct V_75 * V_75 , void * V_76 , struct V_152 * V_153 )
{
const struct V_159 V_160 = {
. type = V_161
} ;
struct V_17 * V_18 = F_38 ( V_76 ) ;
int V_121 ;
if ( V_18 -> V_21 == V_158 ) {
F_39 ( L_34 ) ;
return - V_136 ;
}
if ( V_153 -> type == V_114 ) {
V_121 = F_54 ( & V_18 -> V_122 , V_153 , V_75 -> V_162 & V_163 ) ;
} else if ( V_153 -> type == V_104 ) {
V_121 = F_54 ( & V_18 -> V_124 , V_153 , V_75 -> V_162 & V_163 ) ;
if ( V_121 == 0 && V_18 -> V_21 == V_164
&& F_6 ( & V_18 -> V_124 . V_165 ) )
F_55 ( & V_18 -> V_166 , & V_160 ) ;
} else {
V_121 = - V_99 ;
}
return V_121 ;
}
static int F_56 ( struct V_75 * V_75 , void * V_76 ,
struct V_167 * V_168 )
{
struct V_17 * V_18 = F_38 ( V_76 ) ;
if ( V_168 -> type == V_114 )
return F_57 ( & V_18 -> V_122 , V_168 ) ;
if ( V_168 -> type == V_104 )
return F_57 ( & V_18 -> V_124 , V_168 ) ;
return - V_99 ;
}
static int F_58 ( struct V_75 * V_75 , void * V_76 ,
enum V_169 type )
{
struct V_17 * V_18 = F_38 ( V_76 ) ;
if ( type == V_114 )
return F_59 ( & V_18 -> V_122 , type ) ;
else if ( type == V_104 )
return F_59 ( & V_18 -> V_124 , type ) ;
return - V_99 ;
}
static int F_60 ( struct V_75 * V_75 , void * V_76 ,
enum V_169 type )
{
struct V_17 * V_18 = F_38 ( V_76 ) ;
if ( type == V_114 )
return F_61 ( & V_18 -> V_122 , type ) ;
else if ( type == V_104 )
return F_61 ( & V_18 -> V_124 , type ) ;
return - V_99 ;
}
static inline int F_62 ( enum V_170 V_171 )
{
static unsigned int V_4 [ V_172 + 1 ] = {
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
return V_4 [ V_171 ] ;
}
static inline int F_63 ( enum V_173 V_171 )
{
static unsigned int V_4 [ V_174 + 1 ] = {
0 ,
9 ,
1 ,
2 ,
3 ,
7 ,
4 ,
5 ,
} ;
return V_4 [ V_171 ] ;
}
static inline int F_64 ( enum V_175 V_176 )
{
static unsigned int V_4 [ V_177 + 1 ] = {
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
return V_4 [ V_176 ] ;
}
static int F_65 ( struct V_178 * V_179 )
{
struct V_17 * V_18 = F_66 ( V_179 ) ;
struct V_36 * V_37 = V_18 -> V_37 ;
struct V_46 * V_47 = & V_18 -> V_48 ;
int V_121 = 0 ;
switch ( V_179 -> V_12 ) {
case V_180 :
V_47 -> V_181 = V_179 -> V_182 ;
break;
case V_183 :
V_47 -> V_184 = V_179 -> V_182 ;
break;
case V_185 :
V_47 -> V_186 = V_179 -> V_182 ;
break;
case V_187 :
V_47 -> V_188 = V_179 -> V_182 * 8 ;
break;
case V_189 :
V_47 -> V_190 = V_179 -> V_182 ;
break;
case V_191 :
V_47 -> V_192 = V_179 -> V_182 ;
break;
case V_193 :
V_47 -> V_194 = ( V_179 -> V_182 >> 16 ) & 0xff ;
V_47 -> V_195 = ( V_179 -> V_182 >> 8 ) & 0xff ;
V_47 -> V_196 = ( V_179 -> V_182 >> 0 ) & 0xff ;
break;
case V_197 :
V_47 -> V_198 = V_179 -> V_182 ;
break;
case V_199 :
V_47 -> V_200 = V_179 -> V_182 ;
break;
case V_201 :
V_47 -> V_202 = V_179 -> V_182 ;
break;
case V_16 :
V_18 -> V_203 = V_179 -> V_182 ;
break;
case V_204 :
V_47 -> V_205 = V_179 -> V_182 ;
break;
case V_206 :
V_47 -> V_207 . V_208 . V_209 = V_179 -> V_182 ;
break;
case V_210 :
V_47 -> V_49 = V_179 -> V_182 ;
break;
case V_15 :
V_47 -> V_211 = V_179 -> V_182 ;
break;
case V_212 :
V_47 -> V_213 = V_179 -> V_182 ;
break;
case V_214 :
V_47 -> V_215 = V_179 -> V_182 ;
break;
case V_216 :
switch ( V_179 -> V_182 ) {
case V_217 :
V_47 -> V_207 . V_208 . V_218 =
V_219 ;
break;
case V_220 :
V_47 -> V_207 . V_208 . V_218 =
V_221 ;
break;
case V_222 :
V_47 -> V_207 . V_208 . V_218 =
V_223 ;
break;
case V_224 :
if ( F_20 ( V_37 ) )
V_47 -> V_207 . V_208 . V_218 =
V_225 ;
else
V_121 = - V_99 ;
break;
default:
V_121 = - V_99 ;
}
break;
case V_226 :
V_47 -> V_207 . V_208 . V_227 = V_179 -> V_182 ;
V_47 -> V_207 . V_208 . V_228 = F_62 ( V_179 -> V_182 ) ;
if ( V_47 -> V_207 . V_208 . V_228 < 0 ) {
F_39 ( L_35 ) ;
V_121 = V_47 -> V_207 . V_208 . V_228 ;
}
break;
case V_229 :
V_47 -> V_207 . V_230 . V_227 = V_179 -> V_182 ;
V_47 -> V_207 . V_230 . V_228 = F_63 ( V_179 -> V_182 ) ;
if ( V_47 -> V_207 . V_230 . V_228 < 0 ) {
F_39 ( L_35 ) ;
V_121 = V_47 -> V_207 . V_230 . V_228 ;
}
break;
case V_231 :
V_47 -> V_207 . V_208 . V_232 = V_179 -> V_182 ;
break;
case V_233 :
V_47 -> V_207 . V_208 . V_234 = V_179 -> V_182 ;
break;
case V_235 :
V_47 -> V_207 . V_208 . V_236 = V_179 -> V_182 ;
break;
case V_237 :
V_47 -> V_207 . V_208 . V_238 = V_179 -> V_182 ;
break;
case V_239 :
V_47 -> V_207 . V_208 . V_240 = V_179 -> V_182 ;
break;
case V_241 :
V_47 -> V_207 . V_208 . V_242 = V_179 -> V_182 ;
break;
case V_243 :
V_47 -> V_244 = V_179 -> V_182 ;
break;
case V_245 :
V_47 -> V_207 . V_208 . V_246 = V_179 -> V_182 ;
break;
case V_247 :
V_47 -> V_207 . V_208 . V_248 = V_179 -> V_182 ;
break;
case V_249 :
V_47 -> V_207 . V_208 . V_250 = V_179 -> V_182 ;
break;
case V_251 :
V_47 -> V_207 . V_208 . V_252 = V_179 -> V_182 ;
break;
case V_253 :
V_47 -> V_207 . V_208 . V_254 = V_179 -> V_182 ;
break;
case V_255 :
case V_256 :
V_47 -> V_207 . V_230 . V_246 = V_179 -> V_182 ;
break;
case V_257 :
case V_258 :
V_47 -> V_207 . V_230 . V_248 = V_179 -> V_182 ;
break;
case V_259 :
case V_260 :
V_47 -> V_207 . V_230 . V_250 = V_179 -> V_182 ;
break;
case V_261 :
case V_262 :
V_47 -> V_207 . V_230 . V_252 = V_179 -> V_182 ;
break;
case V_263 :
case V_264 :
V_47 -> V_207 . V_230 . V_254 = V_179 -> V_182 ;
break;
case V_265 :
V_47 -> V_207 . V_208 . V_266 = V_179 -> V_182 ;
break;
case V_267 :
V_47 -> V_207 . V_208 . V_268 = V_179 -> V_182 ;
break;
case V_269 :
V_47 -> V_207 . V_208 . V_270 = V_179 -> V_182 ;
break;
case V_271 :
V_47 -> V_207 . V_208 . V_272 = V_179 -> V_182 ;
break;
case V_273 :
V_47 -> V_207 . V_208 . V_274 = V_179 -> V_182 ;
break;
case V_275 :
V_47 -> V_207 . V_208 . F_64 = F_64 ( V_179 -> V_182 ) ;
break;
case V_276 :
V_47 -> V_207 . V_208 . V_277 = V_179 -> V_182 ;
break;
case V_278 :
V_47 -> V_207 . V_208 . V_279 = V_179 -> V_182 ;
break;
case V_280 :
V_47 -> V_207 . V_208 . V_281 = ! V_179 -> V_182 ;
break;
case V_282 :
V_47 -> V_207 . V_208 . V_283 = V_179 -> V_182 ;
break;
case V_284 :
switch ( V_179 -> V_182 ) {
case V_285 :
V_47 -> V_207 . V_230 . V_218 =
V_286 ;
break;
case V_287 :
V_47 -> V_207 . V_230 . V_218 =
V_288 ;
break;
default:
V_121 = - V_99 ;
}
break;
case V_289 :
V_47 -> V_207 . V_230 . V_290 = V_179 -> V_182 ;
break;
default:
F_43 ( & V_37 -> V_125 , L_36 ,
V_179 -> V_12 , V_179 -> V_182 ) ;
V_121 = - V_99 ;
}
return V_121 ;
}
static int F_67 ( struct V_75 * V_75 , void * V_76 ,
struct V_291 * V_292 )
{
struct V_17 * V_18 = F_38 ( V_76 ) ;
if ( V_292 -> type == V_114 ) {
V_18 -> V_48 . V_293 =
V_292 -> V_294 . V_295 . V_296 . V_297 ;
V_18 -> V_48 . V_298 =
V_292 -> V_294 . V_295 . V_296 . V_299 ;
} else {
F_39 ( L_37 ) ;
return - V_99 ;
}
return 0 ;
}
static int F_68 ( struct V_75 * V_75 , void * V_76 ,
struct V_291 * V_292 )
{
struct V_17 * V_18 = F_38 ( V_76 ) ;
if ( V_292 -> type == V_300 ) {
V_292 -> V_294 . V_295 . V_296 . V_297 =
V_18 -> V_48 . V_293 ;
V_292 -> V_294 . V_295 . V_296 . V_299 =
V_18 -> V_48 . V_298 ;
} else {
F_39 ( L_37 ) ;
return - V_99 ;
}
return 0 ;
}
int F_69 ( struct V_75 * V_75 , void * V_76 ,
struct V_301 * V_302 )
{
struct V_17 * V_18 = F_38 ( V_76 ) ;
struct V_36 * V_37 = V_18 -> V_37 ;
struct V_26 * V_153 ;
unsigned long V_41 ;
switch ( V_302 -> V_302 ) {
case V_303 :
if ( V_302 -> V_41 != 0 )
return - V_99 ;
if ( ! V_18 -> V_122 . V_123 )
return - V_99 ;
F_13 ( & V_37 -> V_42 , V_41 ) ;
if ( F_6 ( & V_18 -> V_35 ) ) {
F_4 ( 2 , L_38 ) ;
V_18 -> V_21 = V_25 ;
if ( F_3 ( V_18 ) )
F_21 ( V_18 ) ;
F_16 ( & V_37 -> V_42 , V_41 ) ;
F_15 ( V_37 -> V_44 , V_53 , V_37 ) ;
} else {
F_4 ( 2 , L_39 ) ;
V_153 = F_7 ( V_18 -> V_35 . V_304 ,
struct V_26 , V_32 ) ;
if ( V_153 -> V_41 & V_67 )
V_18 -> V_21 = V_25 ;
else
V_153 -> V_41 |= V_305 ;
F_16 ( & V_37 -> V_42 , V_41 ) ;
}
break;
default:
return - V_99 ;
}
return 0 ;
}
static int F_70 ( struct V_306 * V_166 ,
const struct V_307 * V_308 )
{
switch ( V_308 -> type ) {
case V_161 :
return F_71 ( V_166 , V_308 , 2 , NULL ) ;
default:
return - V_99 ;
}
}
static int F_72 ( struct V_1 * V_9 , struct V_309 * V_310 )
{
int V_5 ;
if ( ! V_9 )
return - V_99 ;
if ( V_9 -> V_94 != V_310 -> V_94 ) {
F_39 ( L_40 ) ;
return - V_99 ;
}
for ( V_5 = 0 ; V_5 < V_9 -> V_94 ; V_5 ++ ) {
if ( ! F_8 ( V_310 , V_5 ) ) {
F_39 ( L_41 ) ;
return - V_99 ;
}
F_4 ( 2 , L_42 ,
V_310 -> V_69 . V_97 , V_5 ,
F_8 ( V_310 , V_5 ) ) ;
}
return 0 ;
}
static int F_73 ( struct V_311 * V_312 ,
const struct V_2 * V_9 ,
unsigned int * V_313 , unsigned int * V_314 ,
unsigned int V_315 [] , void * V_316 [] )
{
struct V_17 * V_18 = F_38 ( V_312 -> V_317 ) ;
struct V_36 * V_37 = V_18 -> V_37 ;
if ( V_18 -> V_21 != V_22 ) {
F_39 ( L_43 , V_18 -> V_21 ) ;
return - V_99 ;
}
if ( V_312 -> type == V_104 ) {
if ( V_18 -> V_109 )
* V_314 = V_18 -> V_109 -> V_94 ;
else
* V_314 = V_318 ;
if ( * V_313 < 1 )
* V_313 = 1 ;
if ( * V_313 > V_319 )
* V_313 = V_319 ;
V_315 [ 0 ] = V_18 -> V_112 ;
V_316 [ 0 ] = V_18 -> V_37 -> V_320 [ V_321 ] ;
} else if ( V_312 -> type == V_114 ) {
if ( V_18 -> V_117 )
* V_314 = V_18 -> V_117 -> V_94 ;
else
* V_314 = V_322 ;
if ( * V_313 < 1 )
* V_313 = 1 ;
if ( * V_313 > V_319 )
* V_313 = V_319 ;
V_315 [ 0 ] = V_18 -> V_119 ;
V_315 [ 1 ] = V_18 -> V_120 ;
if ( F_20 ( V_37 ) ) {
V_316 [ 0 ] =
V_18 -> V_37 -> V_320 [ V_321 ] ;
V_316 [ 1 ] =
V_18 -> V_37 -> V_320 [ V_321 ] ;
} else {
V_316 [ 0 ] =
V_18 -> V_37 -> V_320 [ V_323 ] ;
V_316 [ 1 ] =
V_18 -> V_37 -> V_320 [ V_323 ] ;
}
} else {
F_39 ( L_44 , V_312 -> type ) ;
return - V_99 ;
}
return 0 ;
}
static void F_74 ( struct V_311 * V_324 )
{
struct V_17 * V_18 = F_38 ( V_324 -> V_317 ) ;
struct V_36 * V_37 = V_18 -> V_37 ;
F_75 ( & V_37 -> V_325 ) ;
}
static void F_76 ( struct V_311 * V_324 )
{
struct V_17 * V_18 = F_38 ( V_324 -> V_317 ) ;
struct V_36 * V_37 = V_18 -> V_37 ;
F_77 ( & V_37 -> V_325 ) ;
}
static int F_78 ( struct V_309 * V_310 )
{
struct V_311 * V_312 = V_310 -> V_311 ;
struct V_17 * V_18 = F_38 ( V_312 -> V_317 ) ;
unsigned int V_5 ;
int V_121 ;
if ( V_312 -> type == V_104 ) {
V_121 = F_72 ( V_18 -> V_109 , V_310 ) ;
if ( V_121 < 0 )
return V_121 ;
V_5 = V_310 -> V_69 . V_97 ;
V_18 -> V_326 [ V_5 ] . V_33 = V_310 ;
V_18 -> V_326 [ V_5 ] . V_327 . V_328 =
F_8 ( V_310 , 0 ) ;
V_18 -> V_130 ++ ;
} else if ( V_312 -> type == V_114 ) {
V_121 = F_72 ( V_18 -> V_117 , V_310 ) ;
if ( V_121 < 0 )
return V_121 ;
V_5 = V_310 -> V_69 . V_97 ;
V_18 -> V_329 [ V_5 ] . V_33 = V_310 ;
V_18 -> V_329 [ V_5 ] . V_327 . V_330 . V_331 =
F_8 ( V_310 , 0 ) ;
V_18 -> V_329 [ V_5 ] . V_327 . V_330 . V_332 =
F_8 ( V_310 , 1 ) ;
V_18 -> V_141 ++ ;
} else {
F_39 ( L_44 , V_312 -> type ) ;
return - V_99 ;
}
return 0 ;
}
static int F_79 ( struct V_309 * V_310 )
{
struct V_311 * V_312 = V_310 -> V_311 ;
struct V_17 * V_18 = F_38 ( V_312 -> V_317 ) ;
int V_121 ;
if ( V_312 -> type == V_104 ) {
V_121 = F_72 ( V_18 -> V_109 , V_310 ) ;
if ( V_121 < 0 )
return V_121 ;
F_4 ( 2 , L_45 ,
F_14 ( V_310 , 0 ) , V_18 -> V_112 ) ;
if ( F_14 ( V_310 , 0 ) < V_18 -> V_112 ) {
F_39 ( L_46 ) ;
return - V_99 ;
}
} else if ( V_312 -> type == V_114 ) {
V_121 = F_72 ( V_18 -> V_117 , V_310 ) ;
if ( V_121 < 0 )
return V_121 ;
F_4 ( 2 , L_47 ,
F_14 ( V_310 , 0 ) , V_18 -> V_119 ) ;
F_4 ( 2 , L_48 ,
F_14 ( V_310 , 1 ) , V_18 -> V_120 ) ;
if ( F_14 ( V_310 , 0 ) < V_18 -> V_119 ||
F_14 ( V_310 , 1 ) < V_18 -> V_120 ) {
F_39 ( L_49 ) ;
return - V_99 ;
}
} else {
F_39 ( L_44 , V_312 -> type ) ;
return - V_99 ;
}
return 0 ;
}
static int F_80 ( struct V_311 * V_324 , unsigned int V_150 )
{
struct V_17 * V_18 = F_38 ( V_324 -> V_317 ) ;
struct V_36 * V_37 = V_18 -> V_37 ;
F_81 ( & V_18 -> V_333 ) ;
if ( F_3 ( V_18 ) )
F_21 ( V_18 ) ;
F_15 ( V_37 -> V_44 , V_53 , V_37 ) ;
return 0 ;
}
static int F_82 ( struct V_311 * V_324 )
{
unsigned long V_41 ;
struct V_17 * V_18 = F_38 ( V_324 -> V_317 ) ;
struct V_36 * V_37 = V_18 -> V_37 ;
if ( ( V_18 -> V_21 == V_25 ||
V_18 -> V_21 == V_23 ) &&
V_37 -> V_334 == V_18 -> V_335 && V_37 -> V_336 ) {
V_18 -> V_21 = V_337 ;
F_45 ( V_18 , V_338 ,
0 ) ;
}
V_18 -> V_21 = V_164 ;
F_13 ( & V_37 -> V_42 , V_41 ) ;
if ( V_324 -> type == V_104 ) {
F_15 ( V_37 -> V_44 , V_339 , & V_18 -> V_43 ,
& V_18 -> V_124 ) ;
F_11 ( & V_18 -> V_43 ) ;
V_18 -> V_20 = 0 ;
}
if ( V_324 -> type == V_114 ) {
F_5 ( V_18 ) ;
F_15 ( V_37 -> V_44 , V_339 , & V_18 -> V_35 ,
& V_18 -> V_122 ) ;
F_11 ( & V_18 -> V_35 ) ;
V_18 -> V_19 = 0 ;
}
F_16 ( & V_37 -> V_42 , V_41 ) ;
return 0 ;
}
static void F_83 ( struct V_309 * V_310 )
{
struct V_311 * V_312 = V_310 -> V_311 ;
struct V_17 * V_18 = F_38 ( V_312 -> V_317 ) ;
struct V_36 * V_37 = V_18 -> V_37 ;
unsigned long V_41 ;
struct V_26 * V_340 ;
if ( V_18 -> V_21 == V_158 ) {
F_19 ( V_310 , V_341 ) ;
F_5 ( V_18 ) ;
return;
}
if ( V_312 -> type == V_104 ) {
V_340 = & V_18 -> V_326 [ V_310 -> V_69 . V_97 ] ;
V_340 -> V_41 &= ~ V_67 ;
F_13 ( & V_37 -> V_42 , V_41 ) ;
F_10 ( & V_340 -> V_32 , & V_18 -> V_43 ) ;
V_18 -> V_20 ++ ;
F_16 ( & V_37 -> V_42 , V_41 ) ;
} else if ( V_312 -> type == V_114 ) {
V_340 = & V_18 -> V_329 [ V_310 -> V_69 . V_97 ] ;
V_340 -> V_41 &= ~ V_67 ;
F_13 ( & V_37 -> V_42 , V_41 ) ;
F_10 ( & V_340 -> V_32 , & V_18 -> V_35 ) ;
V_18 -> V_19 ++ ;
F_16 ( & V_37 -> V_42 , V_41 ) ;
} else {
F_39 ( L_50 , V_312 -> type ) ;
}
if ( F_3 ( V_18 ) )
F_21 ( V_18 ) ;
F_15 ( V_37 -> V_44 , V_53 , V_37 ) ;
}
struct V_342 * F_84 ( void )
{
return & V_343 ;
}
struct V_344 * F_85 ( void )
{
return & V_345 ;
}
const struct V_346 * F_86 ( void )
{
return & V_347 ;
}
int F_87 ( struct V_17 * V_18 )
{
struct V_348 V_349 ;
int V_5 ;
F_88 ( & V_18 -> V_333 , V_350 ) ;
if ( V_18 -> V_333 . error ) {
F_39 ( L_51 ) ;
return V_18 -> V_333 . error ;
}
for ( V_5 = 0 ; V_5 < V_350 ; V_5 ++ ) {
if ( F_89 ( V_351 [ V_5 ] . V_12 ) ) {
memset ( & V_349 , 0 , sizeof( struct V_348 ) ) ;
V_349 . V_352 = & V_353 ;
V_349 . V_12 = V_351 [ V_5 ] . V_12 ;
V_349 . V_354 = V_351 [ V_5 ] . V_355 ;
V_349 . V_356 = V_351 [ V_5 ] . V_357 ;
V_349 . V_358 = V_351 [ V_5 ] . V_359 ;
V_349 . V_81 = V_351 [ V_5 ] . V_81 ;
V_349 . type = V_351 [ V_5 ] . type ;
V_349 . V_41 = 0 ;
if ( V_349 . type == V_360 ) {
V_349 . V_361 = 0 ;
V_349 . V_362 = V_349 . V_362 ;
V_349 . V_363 = F_2 ( V_349 . V_12 ) ;
} else {
V_349 . V_361 = V_351 [ V_5 ] . V_361 ;
V_349 . V_362 = 0 ;
}
V_18 -> V_364 [ V_5 ] = F_90 ( & V_18 -> V_333 ,
& V_349 , NULL ) ;
} else {
if ( V_351 [ V_5 ] . type == V_360 ) {
V_18 -> V_364 [ V_5 ] = F_91 (
& V_18 -> V_333 ,
& V_353 , V_351 [ V_5 ] . V_12 ,
V_351 [ V_5 ] . V_357 , 0 ,
V_351 [ V_5 ] . V_359 ) ;
} else {
V_18 -> V_364 [ V_5 ] = F_92 (
& V_18 -> V_333 ,
& V_353 , V_351 [ V_5 ] . V_12 ,
V_351 [ V_5 ] . V_355 ,
V_351 [ V_5 ] . V_357 , V_351 [ V_5 ] . V_361 ,
V_351 [ V_5 ] . V_359 ) ;
}
}
if ( V_18 -> V_333 . error ) {
F_39 ( L_52 , V_5 ) ;
return V_18 -> V_333 . error ;
}
if ( V_351 [ V_5 ] . V_365 && V_18 -> V_364 [ V_5 ] )
V_18 -> V_364 [ V_5 ] -> V_41 |= V_366 ;
}
return 0 ;
}
void F_93 ( struct V_17 * V_18 )
{
int V_5 ;
F_94 ( & V_18 -> V_333 ) ;
for ( V_5 = 0 ; V_5 < V_350 ; V_5 ++ )
V_18 -> V_364 [ V_5 ] = NULL ;
}
void F_95 ( struct V_17 * V_18 )
{
struct V_2 V_3 ;
V_3 . V_9 . V_10 . V_11 = V_367 ;
V_18 -> V_117 = F_1 ( & V_3 , V_95 ) ;
V_3 . V_9 . V_10 . V_11 = V_368 ;
V_18 -> V_109 = F_1 ( & V_3 , V_96 ) ;
}
