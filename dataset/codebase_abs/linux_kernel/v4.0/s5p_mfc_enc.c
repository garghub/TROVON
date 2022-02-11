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
V_79 -> V_85 = V_86 | V_87 ;
V_79 -> V_88 = V_79 -> V_85 | V_89 ;
return 0 ;
}
static int F_30 ( struct V_76 * V_76 , struct V_90 * V_3 ,
bool V_91 )
{
struct V_33 * V_34 = F_29 ( V_76 ) ;
struct V_1 * V_9 ;
int V_5 , V_92 = 0 ;
for ( V_5 = 0 ; V_5 < F_31 ( V_7 ) ; ++ V_5 ) {
if ( V_91 && V_7 [ V_5 ] . type != V_93 )
continue;
else if ( ! V_91 && V_7 [ V_5 ] . type != V_94 )
continue;
else if ( ( V_34 -> V_95 -> V_96 & V_7 [ V_5 ] . V_97 ) == 0 )
continue;
if ( V_92 == V_3 -> V_98 ) {
V_9 = & V_7 [ V_5 ] ;
F_32 ( V_3 -> V_99 , V_9 -> V_82 ,
sizeof( V_3 -> V_99 ) ) ;
V_3 -> V_11 = V_9 -> V_8 ;
return 0 ;
}
++ V_92 ;
}
return - V_100 ;
}
static int F_33 ( struct V_76 * V_76 , void * V_101 ,
struct V_90 * V_3 )
{
return F_30 ( V_76 , V_3 , false ) ;
}
static int F_34 ( struct V_76 * V_76 , void * V_102 ,
struct V_90 * V_3 )
{
return F_30 ( V_76 , V_3 , true ) ;
}
static int F_35 ( struct V_76 * V_76 , void * V_77 , struct V_2 * V_3 )
{
struct V_17 * V_18 = F_36 ( V_77 ) ;
struct V_103 * V_104 = & V_3 -> V_9 . V_10 ;
F_4 ( 2 , L_12 , V_3 -> type , V_18 -> V_21 ) ;
if ( V_3 -> type == V_105 ) {
V_104 -> V_106 = 0 ;
V_104 -> V_107 = 0 ;
V_104 -> V_108 = V_109 ;
V_104 -> V_11 = V_18 -> V_110 -> V_8 ;
V_104 -> V_111 = V_18 -> V_110 -> V_111 ;
V_104 -> V_112 [ 0 ] . V_113 = V_18 -> V_114 ;
V_104 -> V_112 [ 0 ] . V_115 = V_18 -> V_114 ;
} else if ( V_3 -> type == V_116 ) {
V_104 -> V_106 = V_18 -> V_117 ;
V_104 -> V_107 = V_18 -> V_118 ;
V_104 -> V_108 = V_109 ;
V_104 -> V_11 = V_18 -> V_119 -> V_8 ;
V_104 -> V_111 = V_18 -> V_119 -> V_111 ;
V_104 -> V_112 [ 0 ] . V_113 = V_18 -> V_120 ;
V_104 -> V_112 [ 0 ] . V_115 = V_18 -> V_121 ;
V_104 -> V_112 [ 1 ] . V_113 = V_18 -> V_120 ;
V_104 -> V_112 [ 1 ] . V_115 = V_18 -> V_122 ;
} else {
F_37 ( L_13 ) ;
return - V_100 ;
}
return 0 ;
}
static int F_38 ( struct V_76 * V_76 , void * V_77 , struct V_2 * V_3 )
{
struct V_33 * V_34 = F_29 ( V_76 ) ;
struct V_1 * V_9 ;
struct V_103 * V_104 = & V_3 -> V_9 . V_10 ;
if ( V_3 -> type == V_105 ) {
V_9 = F_1 ( V_3 , V_94 ) ;
if ( ! V_9 ) {
F_37 ( L_14 ) ;
return - V_100 ;
}
if ( V_104 -> V_112 [ 0 ] . V_115 == 0 ) {
F_37 ( L_15 ) ;
return - V_100 ;
}
if ( ( V_34 -> V_95 -> V_96 & V_9 -> V_97 ) == 0 ) {
F_37 ( L_16 ) ;
return - V_100 ;
}
V_104 -> V_112 [ 0 ] . V_113 =
V_104 -> V_112 [ 0 ] . V_115 ;
} else if ( V_3 -> type == V_116 ) {
V_9 = F_1 ( V_3 , V_93 ) ;
if ( ! V_9 ) {
F_37 ( L_14 ) ;
return - V_100 ;
}
if ( V_9 -> V_111 != V_104 -> V_111 ) {
F_37 ( L_14 ) ;
return - V_100 ;
}
if ( ( V_34 -> V_95 -> V_96 & V_9 -> V_97 ) == 0 ) {
F_37 ( L_16 ) ;
return - V_100 ;
}
F_39 ( & V_104 -> V_106 , 8 , 1920 , 1 ,
& V_104 -> V_107 , 4 , 1080 , 1 , 0 ) ;
} else {
F_37 ( L_13 ) ;
return - V_100 ;
}
return 0 ;
}
static int F_40 ( struct V_76 * V_76 , void * V_77 , struct V_2 * V_3 )
{
struct V_33 * V_34 = F_29 ( V_76 ) ;
struct V_17 * V_18 = F_36 ( V_77 ) ;
struct V_103 * V_104 = & V_3 -> V_9 . V_10 ;
int V_123 = 0 ;
V_123 = F_38 ( V_76 , V_77 , V_3 ) ;
if ( V_123 )
return V_123 ;
if ( V_18 -> V_124 . V_125 || V_18 -> V_126 . V_125 ) {
F_41 ( & V_34 -> V_127 , L_17 , V_128 ) ;
V_123 = - V_129 ;
goto V_91;
}
if ( V_3 -> type == V_105 ) {
V_18 -> V_110 = F_1 ( V_3 , V_94 ) ;
V_18 -> V_21 = V_130 ;
V_18 -> V_131 = V_18 -> V_110 -> V_131 ;
V_18 -> V_114 = V_104 -> V_112 [ 0 ] . V_115 ;
V_104 -> V_112 [ 0 ] . V_113 = 0 ;
V_18 -> V_132 = 0 ;
V_18 -> V_133 = V_134 ;
V_123 = F_42 ( V_34 , V_18 ) ;
} else if ( V_3 -> type == V_116 ) {
V_18 -> V_119 = F_1 ( V_3 , V_93 ) ;
V_18 -> V_117 = V_104 -> V_106 ;
V_18 -> V_118 = V_104 -> V_107 ;
F_4 ( 2 , L_18 , V_18 -> V_119 -> V_131 ) ;
F_4 ( 2 , L_19 ,
V_104 -> V_106 , V_104 -> V_107 ,
V_18 -> V_117 , V_18 -> V_118 ) ;
F_15 ( V_34 -> V_42 , V_135 , V_18 ) ;
V_104 -> V_112 [ 0 ] . V_115 = V_18 -> V_121 ;
V_104 -> V_112 [ 0 ] . V_113 = V_18 -> V_120 ;
V_104 -> V_112 [ 1 ] . V_115 = V_18 -> V_122 ;
V_104 -> V_112 [ 1 ] . V_113 = V_18 -> V_120 ;
V_18 -> V_136 = 0 ;
V_18 -> V_137 = V_134 ;
} else {
F_37 ( L_13 ) ;
V_123 = - V_100 ;
}
V_91:
F_43 () ;
return V_123 ;
}
static int F_44 ( struct V_76 * V_76 , void * V_77 ,
struct V_138 * V_139 )
{
struct V_33 * V_34 = F_29 ( V_76 ) ;
struct V_17 * V_18 = F_36 ( V_77 ) ;
int V_123 = 0 ;
if ( ( V_139 -> V_140 != V_141 ) &&
( V_139 -> V_140 != V_142 ) )
return - V_100 ;
if ( V_139 -> type == V_105 ) {
if ( V_139 -> V_143 == 0 ) {
V_123 = F_45 ( & V_18 -> V_126 , V_139 ) ;
V_18 -> V_133 = V_134 ;
return V_123 ;
}
if ( V_18 -> V_133 != V_134 ) {
F_37 ( L_20 ,
V_18 -> V_133 ) ;
return - V_100 ;
}
V_123 = F_45 ( & V_18 -> V_126 , V_139 ) ;
if ( V_123 != 0 ) {
F_37 ( L_21 ) ;
return V_123 ;
}
V_18 -> V_133 = V_144 ;
V_123 = F_19 ( V_18 -> V_34 -> V_42 ,
V_145 , V_18 ) ;
if ( V_123 ) {
F_37 ( L_22 ) ;
V_139 -> V_143 = 0 ;
V_123 = F_45 ( & V_18 -> V_126 , V_139 ) ;
return - V_146 ;
}
} else if ( V_139 -> type == V_116 ) {
if ( V_139 -> V_143 == 0 ) {
F_4 ( 2 , L_23 ) ;
V_123 = F_45 ( & V_18 -> V_124 , V_139 ) ;
F_15 ( V_34 -> V_42 , V_147 ,
V_18 ) ;
V_18 -> V_137 = V_134 ;
return V_123 ;
}
if ( V_18 -> V_137 != V_134 ) {
F_37 ( L_24 ,
V_18 -> V_137 ) ;
return - V_100 ;
}
if ( F_21 ( V_34 ) ) {
if ( V_18 -> V_54 &&
( V_139 -> V_143 < V_18 -> V_54 ) ) {
V_139 -> V_143 = V_18 -> V_54 ;
F_4 ( 2 , L_25 ,
V_18 -> V_54 ) ;
} else {
V_18 -> V_54 = V_139 -> V_143 ;
}
}
V_123 = F_45 ( & V_18 -> V_124 , V_139 ) ;
if ( V_123 != 0 ) {
F_37 ( L_26 ) ;
return V_123 ;
}
V_18 -> V_137 = V_144 ;
} else {
F_37 ( L_13 ) ;
return - V_100 ;
}
return V_123 ;
}
static int F_46 ( struct V_76 * V_76 , void * V_77 ,
struct V_148 * V_149 )
{
struct V_17 * V_18 = F_36 ( V_77 ) ;
int V_123 = 0 ;
if ( ( V_149 -> V_140 != V_141 ) &&
( V_149 -> V_140 != V_142 ) )
return - V_100 ;
if ( V_149 -> type == V_105 ) {
if ( V_18 -> V_21 != V_22 ) {
F_37 ( L_27 , V_18 -> V_21 ) ;
return - V_100 ;
}
V_123 = F_47 ( & V_18 -> V_126 , V_149 ) ;
if ( V_123 != 0 ) {
F_37 ( L_28 ) ;
return V_123 ;
}
V_149 -> V_150 . V_151 [ 0 ] . V_150 . V_152 += V_153 ;
} else if ( V_149 -> type == V_116 ) {
V_123 = F_47 ( & V_18 -> V_124 , V_149 ) ;
if ( V_123 != 0 ) {
F_37 ( L_29 ) ;
return V_123 ;
}
} else {
F_37 ( L_13 ) ;
return - V_100 ;
}
return V_123 ;
}
static int F_48 ( struct V_76 * V_76 , void * V_77 , struct V_148 * V_149 )
{
struct V_17 * V_18 = F_36 ( V_77 ) ;
if ( V_18 -> V_21 == V_154 ) {
F_37 ( L_30 ) ;
return - V_155 ;
}
if ( V_149 -> type == V_116 ) {
if ( V_18 -> V_21 == V_25 ) {
F_37 ( L_31 ) ;
return - V_155 ;
}
return F_49 ( & V_18 -> V_124 , V_149 ) ;
} else if ( V_149 -> type == V_105 ) {
return F_49 ( & V_18 -> V_126 , V_149 ) ;
}
return - V_100 ;
}
static int F_50 ( struct V_76 * V_76 , void * V_77 , struct V_148 * V_149 )
{
const struct V_156 V_157 = {
. type = V_158
} ;
struct V_17 * V_18 = F_36 ( V_77 ) ;
int V_123 ;
if ( V_18 -> V_21 == V_154 ) {
F_37 ( L_32 ) ;
return - V_155 ;
}
if ( V_149 -> type == V_116 ) {
V_123 = F_51 ( & V_18 -> V_124 , V_149 , V_76 -> V_159 & V_160 ) ;
} else if ( V_149 -> type == V_105 ) {
V_123 = F_51 ( & V_18 -> V_126 , V_149 , V_76 -> V_159 & V_160 ) ;
if ( V_123 == 0 && V_18 -> V_21 == V_161
&& F_6 ( & V_18 -> V_126 . V_162 ) )
F_52 ( & V_18 -> V_163 , & V_157 ) ;
} else {
V_123 = - V_100 ;
}
return V_123 ;
}
static int F_53 ( struct V_76 * V_76 , void * V_77 ,
struct V_164 * V_165 )
{
struct V_17 * V_18 = F_36 ( V_77 ) ;
if ( V_165 -> type == V_116 )
return F_54 ( & V_18 -> V_124 , V_165 ) ;
if ( V_165 -> type == V_105 )
return F_54 ( & V_18 -> V_126 , V_165 ) ;
return - V_100 ;
}
static int F_55 ( struct V_76 * V_76 , void * V_77 ,
enum V_166 type )
{
struct V_17 * V_18 = F_36 ( V_77 ) ;
if ( type == V_116 )
return F_56 ( & V_18 -> V_124 , type ) ;
else if ( type == V_105 )
return F_56 ( & V_18 -> V_126 , type ) ;
return - V_100 ;
}
static int F_57 ( struct V_76 * V_76 , void * V_77 ,
enum V_166 type )
{
struct V_17 * V_18 = F_36 ( V_77 ) ;
if ( type == V_116 )
return F_58 ( & V_18 -> V_124 , type ) ;
else if ( type == V_105 )
return F_58 ( & V_18 -> V_126 , type ) ;
return - V_100 ;
}
static inline int F_59 ( enum V_167 V_168 )
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
static inline int F_60 ( enum V_170 V_168 )
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
static inline int F_61 ( enum V_172 V_173 )
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
static int F_62 ( struct V_175 * V_176 )
{
struct V_17 * V_18 = F_63 ( V_176 ) ;
struct V_33 * V_34 = V_18 -> V_34 ;
struct V_44 * V_45 = & V_18 -> V_46 ;
int V_123 = 0 ;
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
V_123 = - V_100 ;
break;
default:
V_123 = - V_100 ;
}
break;
case V_227 :
V_45 -> V_208 . V_209 . V_228 = V_176 -> V_179 ;
V_45 -> V_208 . V_209 . V_229 = F_59 ( V_176 -> V_179 ) ;
if ( V_45 -> V_208 . V_209 . V_229 < 0 ) {
F_37 ( L_33 ) ;
V_123 = V_45 -> V_208 . V_209 . V_229 ;
}
break;
case V_230 :
V_45 -> V_208 . V_231 . V_228 = V_176 -> V_179 ;
V_45 -> V_208 . V_231 . V_229 = F_60 ( V_176 -> V_179 ) ;
if ( V_45 -> V_208 . V_231 . V_229 < 0 ) {
F_37 ( L_33 ) ;
V_123 = V_45 -> V_208 . V_231 . V_229 ;
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
V_45 -> V_208 . V_209 . F_61 = F_61 ( V_176 -> V_179 ) ;
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
V_123 = - V_100 ;
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
F_41 ( & V_34 -> V_127 , L_34 ,
V_176 -> V_12 , V_176 -> V_179 ) ;
V_123 = - V_100 ;
}
return V_123 ;
}
static int F_64 ( struct V_175 * V_176 )
{
struct V_17 * V_18 = F_63 ( V_176 ) ;
struct V_33 * V_34 = V_18 -> V_34 ;
switch ( V_176 -> V_12 ) {
case V_312 :
if ( V_18 -> V_21 >= V_313 &&
V_18 -> V_21 < V_314 ) {
V_176 -> V_179 = V_18 -> V_54 ;
break;
} else if ( V_18 -> V_21 != V_130 ) {
F_41 ( & V_34 -> V_127 , L_35 ) ;
return - V_100 ;
}
F_65 ( V_18 ,
V_315 , 0 ) ;
if ( V_18 -> V_21 >= V_313 &&
V_18 -> V_21 < V_314 ) {
V_176 -> V_179 = V_18 -> V_54 ;
} else {
F_41 ( & V_34 -> V_127 , L_35 ) ;
return - V_100 ;
}
break;
}
return 0 ;
}
static int F_66 ( struct V_76 * V_76 , void * V_77 ,
struct V_316 * V_317 )
{
struct V_17 * V_18 = F_36 ( V_77 ) ;
if ( V_317 -> type == V_116 ) {
V_18 -> V_46 . V_318 =
V_317 -> V_319 . V_320 . V_321 . V_322 ;
V_18 -> V_46 . V_323 =
V_317 -> V_319 . V_320 . V_321 . V_324 ;
} else {
F_37 ( L_36 ) ;
return - V_100 ;
}
return 0 ;
}
static int F_67 ( struct V_76 * V_76 , void * V_77 ,
struct V_316 * V_317 )
{
struct V_17 * V_18 = F_36 ( V_77 ) ;
if ( V_317 -> type == V_325 ) {
V_317 -> V_319 . V_320 . V_321 . V_322 =
V_18 -> V_46 . V_318 ;
V_317 -> V_319 . V_320 . V_321 . V_324 =
V_18 -> V_46 . V_323 ;
} else {
F_37 ( L_36 ) ;
return - V_100 ;
}
return 0 ;
}
static int F_68 ( struct V_76 * V_76 , void * V_77 ,
struct V_326 * V_327 )
{
struct V_17 * V_18 = F_36 ( V_77 ) ;
struct V_33 * V_34 = V_18 -> V_34 ;
struct V_26 * V_149 ;
unsigned long V_38 ;
switch ( V_327 -> V_327 ) {
case V_328 :
if ( V_327 -> V_38 != 0 )
return - V_100 ;
if ( ! V_18 -> V_124 . V_125 )
return - V_100 ;
F_12 ( & V_34 -> V_39 , V_38 ) ;
if ( F_6 ( & V_18 -> V_32 ) ) {
F_4 ( 2 , L_37 ) ;
V_18 -> V_21 = V_25 ;
if ( F_3 ( V_18 ) )
F_22 ( V_18 ) ;
F_16 ( & V_34 -> V_39 , V_38 ) ;
F_15 ( V_34 -> V_42 , V_52 , V_34 ) ;
} else {
F_4 ( 2 , L_38 ) ;
V_149 = F_7 ( V_18 -> V_32 . V_329 ,
struct V_26 , V_30 ) ;
if ( V_149 -> V_38 & V_68 )
V_18 -> V_21 = V_25 ;
else
V_149 -> V_38 |= V_330 ;
F_16 ( & V_34 -> V_39 , V_38 ) ;
}
break;
default:
return - V_100 ;
}
return 0 ;
}
static int F_69 ( struct V_331 * V_163 ,
const struct V_332 * V_333 )
{
switch ( V_333 -> type ) {
case V_158 :
return F_70 ( V_163 , V_333 , 2 , NULL ) ;
default:
return - V_100 ;
}
}
static int F_71 ( struct V_1 * V_9 , struct V_334 * V_335 )
{
int V_5 ;
if ( ! V_9 )
return - V_100 ;
if ( V_9 -> V_111 != V_335 -> V_111 ) {
F_37 ( L_39 ) ;
return - V_100 ;
}
for ( V_5 = 0 ; V_5 < V_9 -> V_111 ; V_5 ++ ) {
T_2 V_336 = F_13 ( V_335 , V_5 ) ;
if ( ! V_336 ) {
F_37 ( L_40 ) ;
return - V_100 ;
}
F_4 ( 2 , L_41 ,
V_335 -> V_70 . V_98 , V_5 , & V_336 ) ;
}
return 0 ;
}
static int F_72 ( struct V_337 * V_338 ,
const struct V_2 * V_9 ,
unsigned int * V_339 , unsigned int * V_340 ,
unsigned int V_341 [] , void * V_342 [] )
{
struct V_17 * V_18 = F_36 ( V_338 -> V_343 ) ;
struct V_33 * V_34 = V_18 -> V_34 ;
if ( V_18 -> V_21 != V_22 ) {
F_37 ( L_42 , V_18 -> V_21 ) ;
return - V_100 ;
}
if ( V_338 -> type == V_105 ) {
if ( V_18 -> V_110 )
* V_340 = V_18 -> V_110 -> V_111 ;
else
* V_340 = V_344 ;
if ( * V_339 < 1 )
* V_339 = 1 ;
if ( * V_339 > V_345 )
* V_339 = V_345 ;
V_341 [ 0 ] = V_18 -> V_114 ;
V_342 [ 0 ] = V_18 -> V_34 -> V_346 [ V_347 ] ;
} else if ( V_338 -> type == V_116 ) {
if ( V_18 -> V_119 )
* V_340 = V_18 -> V_119 -> V_111 ;
else
* V_340 = V_348 ;
if ( * V_339 < 1 )
* V_339 = 1 ;
if ( * V_339 > V_345 )
* V_339 = V_345 ;
V_341 [ 0 ] = V_18 -> V_121 ;
V_341 [ 1 ] = V_18 -> V_122 ;
if ( F_21 ( V_34 ) ) {
V_342 [ 0 ] =
V_18 -> V_34 -> V_346 [ V_347 ] ;
V_342 [ 1 ] =
V_18 -> V_34 -> V_346 [ V_347 ] ;
} else {
V_342 [ 0 ] =
V_18 -> V_34 -> V_346 [ V_349 ] ;
V_342 [ 1 ] =
V_18 -> V_34 -> V_346 [ V_349 ] ;
}
} else {
F_37 ( L_43 , V_338 -> type ) ;
return - V_100 ;
}
return 0 ;
}
static int F_73 ( struct V_334 * V_335 )
{
struct V_337 * V_338 = V_335 -> V_337 ;
struct V_17 * V_18 = F_36 ( V_338 -> V_343 ) ;
unsigned int V_5 ;
int V_123 ;
if ( V_338 -> type == V_105 ) {
V_123 = F_71 ( V_18 -> V_110 , V_335 ) ;
if ( V_123 < 0 )
return V_123 ;
V_5 = V_335 -> V_70 . V_98 ;
V_18 -> V_350 [ V_5 ] . V_41 = V_335 ;
V_18 -> V_350 [ V_5 ] . V_351 . V_352 =
F_13 ( V_335 , 0 ) ;
V_18 -> V_132 ++ ;
} else if ( V_338 -> type == V_116 ) {
V_123 = F_71 ( V_18 -> V_119 , V_335 ) ;
if ( V_123 < 0 )
return V_123 ;
V_5 = V_335 -> V_70 . V_98 ;
V_18 -> V_353 [ V_5 ] . V_41 = V_335 ;
V_18 -> V_353 [ V_5 ] . V_351 . V_354 . V_355 =
F_13 ( V_335 , 0 ) ;
V_18 -> V_353 [ V_5 ] . V_351 . V_354 . V_356 =
F_13 ( V_335 , 1 ) ;
V_18 -> V_136 ++ ;
} else {
F_37 ( L_43 , V_338 -> type ) ;
return - V_100 ;
}
return 0 ;
}
static int F_74 ( struct V_334 * V_335 )
{
struct V_337 * V_338 = V_335 -> V_337 ;
struct V_17 * V_18 = F_36 ( V_338 -> V_343 ) ;
int V_123 ;
if ( V_338 -> type == V_105 ) {
V_123 = F_71 ( V_18 -> V_110 , V_335 ) ;
if ( V_123 < 0 )
return V_123 ;
F_4 ( 2 , L_44 ,
F_14 ( V_335 , 0 ) , V_18 -> V_114 ) ;
if ( F_14 ( V_335 , 0 ) < V_18 -> V_114 ) {
F_37 ( L_45 ) ;
return - V_100 ;
}
} else if ( V_338 -> type == V_116 ) {
V_123 = F_71 ( V_18 -> V_119 , V_335 ) ;
if ( V_123 < 0 )
return V_123 ;
F_4 ( 2 , L_46 ,
F_14 ( V_335 , 0 ) , V_18 -> V_121 ) ;
F_4 ( 2 , L_47 ,
F_14 ( V_335 , 1 ) , V_18 -> V_122 ) ;
if ( F_14 ( V_335 , 0 ) < V_18 -> V_121 ||
F_14 ( V_335 , 1 ) < V_18 -> V_122 ) {
F_37 ( L_48 ) ;
return - V_100 ;
}
} else {
F_37 ( L_43 , V_338 -> type ) ;
return - V_100 ;
}
return 0 ;
}
static int F_75 ( struct V_337 * V_357 , unsigned int V_143 )
{
struct V_17 * V_18 = F_36 ( V_357 -> V_343 ) ;
struct V_33 * V_34 = V_18 -> V_34 ;
if ( F_21 ( V_34 ) &&
( V_357 -> type == V_105 ) ) {
if ( ( V_18 -> V_21 == V_22 ) &&
( V_34 -> V_358 == V_18 -> V_359 ) && V_34 -> V_360 ) {
F_65 ( V_18 ,
V_315 ,
0 ) ;
}
if ( V_18 -> V_136 < V_18 -> V_54 ) {
F_37 ( L_49 ,
V_18 -> V_54 ) ;
return - V_361 ;
}
}
if ( F_3 ( V_18 ) )
F_22 ( V_18 ) ;
F_15 ( V_34 -> V_42 , V_52 , V_34 ) ;
return 0 ;
}
static void F_76 ( struct V_337 * V_357 )
{
unsigned long V_38 ;
struct V_17 * V_18 = F_36 ( V_357 -> V_343 ) ;
struct V_33 * V_34 = V_18 -> V_34 ;
if ( ( V_18 -> V_21 == V_25 ||
V_18 -> V_21 == V_23 ) &&
V_34 -> V_358 == V_18 -> V_359 && V_34 -> V_360 ) {
V_18 -> V_21 = V_314 ;
F_65 ( V_18 , V_362 ,
0 ) ;
}
V_18 -> V_21 = V_161 ;
F_12 ( & V_34 -> V_39 , V_38 ) ;
if ( V_357 -> type == V_105 ) {
F_15 ( V_34 -> V_42 , V_363 ,
& V_18 -> V_40 , & V_18 -> V_126 ) ;
F_10 ( & V_18 -> V_40 ) ;
V_18 -> V_20 = 0 ;
}
if ( V_357 -> type == V_116 ) {
F_5 ( V_18 ) ;
F_15 ( V_34 -> V_42 , V_363 , & V_18 -> V_32 ,
& V_18 -> V_124 ) ;
F_10 ( & V_18 -> V_32 ) ;
V_18 -> V_19 = 0 ;
}
F_16 ( & V_34 -> V_39 , V_38 ) ;
}
static void F_77 ( struct V_334 * V_335 )
{
struct V_337 * V_338 = V_335 -> V_337 ;
struct V_17 * V_18 = F_36 ( V_338 -> V_343 ) ;
struct V_33 * V_34 = V_18 -> V_34 ;
unsigned long V_38 ;
struct V_26 * V_364 ;
if ( V_18 -> V_21 == V_154 ) {
F_20 ( V_335 , V_365 ) ;
F_5 ( V_18 ) ;
return;
}
if ( V_338 -> type == V_105 ) {
V_364 = & V_18 -> V_350 [ V_335 -> V_70 . V_98 ] ;
V_364 -> V_38 &= ~ V_68 ;
F_12 ( & V_34 -> V_39 , V_38 ) ;
F_9 ( & V_364 -> V_30 , & V_18 -> V_40 ) ;
V_18 -> V_20 ++ ;
F_16 ( & V_34 -> V_39 , V_38 ) ;
} else if ( V_338 -> type == V_116 ) {
V_364 = & V_18 -> V_353 [ V_335 -> V_70 . V_98 ] ;
V_364 -> V_38 &= ~ V_68 ;
F_12 ( & V_34 -> V_39 , V_38 ) ;
F_9 ( & V_364 -> V_30 , & V_18 -> V_32 ) ;
V_18 -> V_19 ++ ;
F_16 ( & V_34 -> V_39 , V_38 ) ;
} else {
F_37 ( L_50 , V_338 -> type ) ;
}
if ( F_3 ( V_18 ) )
F_22 ( V_18 ) ;
F_15 ( V_34 -> V_42 , V_52 , V_34 ) ;
}
struct V_366 * F_78 ( void )
{
return & V_367 ;
}
struct V_368 * F_79 ( void )
{
return & V_369 ;
}
const struct V_370 * F_80 ( void )
{
return & V_371 ;
}
int F_81 ( struct V_17 * V_18 )
{
struct V_372 V_373 ;
int V_5 ;
F_82 ( & V_18 -> V_374 , V_375 ) ;
if ( V_18 -> V_374 . error ) {
F_37 ( L_51 ) ;
return V_18 -> V_374 . error ;
}
for ( V_5 = 0 ; V_5 < V_375 ; V_5 ++ ) {
if ( F_83 ( V_376 [ V_5 ] . V_12 ) ) {
memset ( & V_373 , 0 , sizeof( struct V_372 ) ) ;
V_373 . V_377 = & V_378 ;
V_373 . V_12 = V_376 [ V_5 ] . V_12 ;
V_373 . V_379 = V_376 [ V_5 ] . V_380 ;
V_373 . V_381 = V_376 [ V_5 ] . V_382 ;
V_373 . V_383 = V_376 [ V_5 ] . V_384 ;
V_373 . V_82 = V_376 [ V_5 ] . V_82 ;
V_373 . type = V_376 [ V_5 ] . type ;
V_373 . V_38 = 0 ;
if ( V_373 . type == V_385 ) {
V_373 . V_386 = 0 ;
V_373 . V_387 = V_373 . V_387 ;
V_373 . V_388 = F_2 ( V_373 . V_12 ) ;
} else {
V_373 . V_386 = V_376 [ V_5 ] . V_386 ;
V_373 . V_387 = 0 ;
}
V_18 -> V_389 [ V_5 ] = F_84 ( & V_18 -> V_374 ,
& V_373 , NULL ) ;
} else {
if ( ( V_376 [ V_5 ] . type == V_385 ) ||
( V_376 [ V_5 ] . type ==
V_390 ) ) {
V_18 -> V_389 [ V_5 ] = F_85 (
& V_18 -> V_374 ,
& V_378 , V_376 [ V_5 ] . V_12 ,
V_376 [ V_5 ] . V_382 , 0 ,
V_376 [ V_5 ] . V_384 ) ;
} else {
V_18 -> V_389 [ V_5 ] = F_86 (
& V_18 -> V_374 ,
& V_378 , V_376 [ V_5 ] . V_12 ,
V_376 [ V_5 ] . V_380 ,
V_376 [ V_5 ] . V_382 , V_376 [ V_5 ] . V_386 ,
V_376 [ V_5 ] . V_384 ) ;
}
}
if ( V_18 -> V_374 . error ) {
F_37 ( L_52 , V_5 ) ;
return V_18 -> V_374 . error ;
}
if ( V_376 [ V_5 ] . V_391 && V_18 -> V_389 [ V_5 ] )
V_18 -> V_389 [ V_5 ] -> V_38 |= V_392 ;
}
F_87 ( & V_18 -> V_374 ) ;
return 0 ;
}
void F_88 ( struct V_17 * V_18 )
{
int V_5 ;
F_89 ( & V_18 -> V_374 ) ;
for ( V_5 = 0 ; V_5 < V_375 ; V_5 ++ )
V_18 -> V_389 [ V_5 ] = NULL ;
}
void F_90 ( struct V_17 * V_18 )
{
struct V_2 V_3 ;
V_3 . V_9 . V_10 . V_11 = V_393 ;
V_18 -> V_119 = F_1 ( & V_3 , V_93 ) ;
V_3 . V_9 . V_10 . V_11 = V_394 ;
V_18 -> V_110 = F_1 ( & V_3 , V_94 ) ;
}
