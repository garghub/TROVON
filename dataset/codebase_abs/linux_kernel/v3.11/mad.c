static inline struct V_1 *
F_1 ( struct V_2 * V_3 , int V_4 )
{
struct V_1 * V_5 ;
F_2 (entry, &ib_mad_port_list, port_list) {
if ( V_5 -> V_3 == V_3 && V_5 -> V_4 == V_4 )
return V_5 ;
}
return NULL ;
}
static inline struct V_1 *
F_3 ( struct V_2 * V_3 , int V_4 )
{
struct V_1 * V_5 ;
unsigned long V_6 ;
F_4 ( & V_7 , V_6 ) ;
V_5 = F_1 ( V_3 , V_4 ) ;
F_5 ( & V_7 , V_6 ) ;
return V_5 ;
}
static inline T_1 F_6 ( T_1 V_8 )
{
return V_8 == V_9 ?
0 : V_8 ;
}
static int F_7 ( enum V_10 V_11 )
{
switch ( V_11 )
{
case V_12 :
return 0 ;
case V_13 :
return 1 ;
default:
return - 1 ;
}
}
static int F_8 ( T_1 V_8 )
{
return V_8 - V_14 ;
}
static int F_9 ( T_1 V_8 )
{
if ( ( V_8 < V_14 ) ||
( V_8 > V_15 ) )
return 0 ;
return 1 ;
}
static int F_10 ( char * V_16 )
{
if ( V_16 [ 0 ] || V_16 [ 1 ] || V_16 [ 2 ] )
return 1 ;
return 0 ;
}
static int F_11 (
struct V_17 * V_18 ,
struct V_19 * V_20 )
{
struct V_21 * V_22 ;
int V_23 ;
for ( V_23 = 0 ; V_23 < V_24 ; V_23 ++ ) {
if ( ! memcmp ( V_18 -> V_16 [ V_23 ] , V_20 -> V_16 , 3 ) ) {
V_22 = V_18 -> V_25 [ V_23 ] ;
if ( V_22 ) {
if ( F_12 ( & V_22 , V_20 ) )
return 1 ;
else
break;
}
}
}
return 0 ;
}
int F_13 ( struct V_26 * V_27 )
{
return ( ( V_27 -> V_28 . V_22 & V_29 ) ||
( V_27 -> V_28 . V_22 == V_30 ) ||
( ( V_27 -> V_28 . V_8 == V_31 ) &&
( V_27 -> V_28 . V_32 & V_33 ) ) ) ;
}
struct V_34 * F_14 ( struct V_2 * V_3 ,
T_1 V_4 ,
enum V_10 V_11 ,
struct V_19 * V_20 ,
T_1 V_35 ,
T_2 V_36 ,
T_3 V_37 ,
void * V_38 )
{
struct V_1 * V_39 ;
struct V_34 * V_40 = F_15 ( - V_41 ) ;
struct V_42 * V_43 ;
struct V_19 * V_44 = NULL ;
struct V_45 * V_46 ;
struct V_47 * V_48 ;
struct V_17 * V_18 ;
struct V_21 * V_22 ;
int V_49 , V_50 ;
unsigned long V_6 ;
T_1 V_8 , V_51 ;
V_50 = F_7 ( V_11 ) ;
if ( V_50 == - 1 )
goto V_52;
if ( V_35 && V_35 != V_53 )
goto V_52;
if ( V_20 ) {
if ( V_20 -> V_54 >= V_55 )
goto V_52;
if ( ! V_37 )
goto V_52;
if ( V_20 -> V_8 >= V_56 ) {
if ( V_20 -> V_8 !=
V_9 )
goto V_52;
} else if ( V_20 -> V_8 == 0 ) {
goto V_52;
} else if ( F_9 ( V_20 -> V_8 ) ) {
if ( ! F_10 ( V_20 -> V_16 ) )
goto V_52;
}
if ( ! F_16 ( V_20 -> V_8 ) ) {
if ( V_35 )
goto V_52;
}
if ( V_11 == V_12 ) {
if ( ( V_20 -> V_8 !=
V_57 ) &&
( V_20 -> V_8 !=
V_9 ) )
goto V_52;
} else {
if ( ( V_20 -> V_8 ==
V_57 ) ||
( V_20 -> V_8 ==
V_9 ) )
goto V_52;
}
} else {
if ( ! V_36 )
goto V_52;
}
V_39 = F_3 ( V_3 , V_4 ) ;
if ( ! V_39 ) {
V_40 = F_15 ( - V_58 ) ;
goto V_52;
}
if ( ! V_39 -> V_59 [ V_50 ] . V_60 ) {
V_40 = F_15 ( - V_61 ) ;
goto V_52;
}
V_43 = F_17 ( sizeof *V_43 , V_62 ) ;
if ( ! V_43 ) {
V_40 = F_15 ( - V_63 ) ;
goto V_52;
}
V_43 -> V_64 . V_65 = F_18 ( V_39 -> V_59 [ V_50 ] . V_60 -> V_66 ,
V_67 ) ;
if ( F_19 ( V_43 -> V_64 . V_65 ) ) {
V_40 = F_15 ( - V_63 ) ;
goto V_68;
}
if ( V_20 ) {
V_44 = F_20 ( V_20 , sizeof *V_44 , V_62 ) ;
if ( ! V_44 ) {
V_40 = F_15 ( - V_63 ) ;
goto V_69;
}
}
V_43 -> V_59 = & V_39 -> V_59 [ V_50 ] ;
V_43 -> V_44 = V_44 ;
V_43 -> V_64 . V_35 = V_35 ;
V_43 -> V_64 . V_3 = V_3 ;
V_43 -> V_64 . V_37 = V_37 ;
V_43 -> V_64 . V_36 = V_36 ;
V_43 -> V_64 . V_38 = V_38 ;
V_43 -> V_64 . V_60 = V_39 -> V_59 [ V_50 ] . V_60 ;
V_43 -> V_64 . V_4 = V_4 ;
F_21 ( & V_43 -> V_70 ) ;
F_22 ( & V_43 -> V_71 ) ;
F_22 ( & V_43 -> V_72 ) ;
F_22 ( & V_43 -> V_73 ) ;
F_22 ( & V_43 -> V_74 ) ;
F_23 ( & V_43 -> V_75 , V_76 ) ;
F_22 ( & V_43 -> V_77 ) ;
F_24 ( & V_43 -> V_78 , V_79 ) ;
F_25 ( & V_43 -> V_80 , 1 ) ;
F_26 ( & V_43 -> V_81 ) ;
F_4 ( & V_39 -> V_82 , V_6 ) ;
V_43 -> V_64 . V_83 = ++ V_84 ;
if ( V_20 ) {
V_8 = F_6 ( V_20 -> V_8 ) ;
if ( ! F_9 ( V_8 ) ) {
V_46 = V_39 -> V_85 [ V_20 ->
V_54 ] . V_46 ;
if ( V_46 ) {
V_22 = V_46 -> V_25 [ V_8 ] ;
if ( V_22 ) {
if ( F_12 ( & V_22 ,
V_20 ) )
goto V_86;
}
}
V_49 = F_27 ( V_20 , V_43 ,
V_8 ) ;
} else {
V_48 = V_39 -> V_85 [ V_20 ->
V_54 ] . V_48 ;
if ( V_48 ) {
V_51 = F_8 ( V_8 ) ;
V_18 = V_48 -> V_18 [ V_51 ] ;
if ( V_18 ) {
if ( F_11 (
V_18 ,
V_20 ) )
goto V_86;
}
}
V_49 = F_28 ( V_20 , V_43 ) ;
}
if ( V_49 ) {
V_40 = F_15 ( V_49 ) ;
goto V_86;
}
}
F_29 ( & V_43 -> V_87 , & V_39 -> V_87 ) ;
F_5 ( & V_39 -> V_82 , V_6 ) ;
return & V_43 -> V_64 ;
V_86:
F_5 ( & V_39 -> V_82 , V_6 ) ;
F_30 ( V_44 ) ;
V_69:
F_31 ( V_43 -> V_64 . V_65 ) ;
V_68:
F_30 ( V_43 ) ;
V_52:
return V_40 ;
}
static inline int F_32 ( int V_88 )
{
return ( V_88 &
(
V_89 ) ) ;
}
static inline int F_33 ( int V_88 )
{
return ( V_88 &
( V_90 ) ) ;
}
static int F_34 ( struct V_91 * V_59 ,
struct V_92 * V_93 )
{
struct V_92 * * V_94 ;
unsigned long V_6 ;
int V_23 ;
F_4 ( & V_59 -> V_95 , V_6 ) ;
for ( V_23 = 0 ; V_23 < V_59 -> V_96 ; V_23 ++ )
if ( ! V_59 -> V_97 [ V_23 ] )
break;
if ( V_23 == V_59 -> V_96 ) {
V_94 = F_35 ( V_59 -> V_97 ,
sizeof V_93 *
( V_59 -> V_96 + 1 ) ,
V_98 ) ;
if ( ! V_94 ) {
V_23 = - V_63 ;
goto V_99;
}
V_59 -> V_97 = V_94 ;
V_59 -> V_96 ++ ;
}
V_59 -> V_97 [ V_23 ] = V_93 ;
F_36 ( & V_59 -> V_100 ) ;
V_99:
F_5 ( & V_59 -> V_95 , V_6 ) ;
return V_23 ;
}
struct V_34 * F_37 ( struct V_2 * V_3 ,
T_1 V_4 ,
enum V_10 V_11 ,
int V_88 ,
T_4 V_101 ,
T_3 V_37 ,
void * V_38 )
{
struct V_1 * V_39 ;
struct V_34 * V_40 ;
struct V_92 * V_93 ;
int V_50 ;
if ( ( F_32 ( V_88 ) && ! V_101 ) ||
( F_33 ( V_88 ) && ! V_37 ) ) {
V_40 = F_15 ( - V_41 ) ;
goto V_52;
}
V_50 = F_7 ( V_11 ) ;
if ( V_50 == - 1 ) {
V_40 = F_15 ( - V_41 ) ;
goto V_52;
}
V_39 = F_3 ( V_3 , V_4 ) ;
if ( ! V_39 ) {
V_40 = F_15 ( - V_58 ) ;
goto V_52;
}
V_93 = F_17 ( sizeof *V_93 , V_62 ) ;
if ( ! V_93 ) {
V_40 = F_15 ( - V_63 ) ;
goto V_52;
}
V_93 -> V_59 = & V_39 -> V_59 [ V_50 ] ;
V_93 -> V_64 . V_3 = V_3 ;
V_93 -> V_64 . V_37 = V_37 ;
V_93 -> V_64 . V_101 = V_101 ;
V_93 -> V_64 . V_38 = V_38 ;
V_93 -> V_64 . V_60 = V_39 -> V_59 [ V_50 ] . V_60 ;
V_93 -> V_64 . V_4 = V_4 ;
V_93 -> V_88 = V_88 ;
F_26 ( & V_93 -> V_81 ) ;
V_93 -> V_102 = F_34 (
& V_39 -> V_59 [ V_50 ] ,
V_93 ) ;
if ( V_93 -> V_102 < 0 ) {
V_40 = F_15 ( V_93 -> V_102 ) ;
goto V_68;
}
F_25 ( & V_93 -> V_80 , 1 ) ;
return & V_93 -> V_64 ;
V_68:
F_30 ( V_93 ) ;
V_52:
return V_40 ;
}
static inline void F_38 ( struct V_42 * V_43 )
{
if ( F_39 ( & V_43 -> V_80 ) )
F_40 ( & V_43 -> V_81 ) ;
}
static inline void F_41 ( struct V_92 * V_93 )
{
if ( F_39 ( & V_93 -> V_80 ) )
F_40 ( & V_93 -> V_81 ) ;
}
static void F_42 ( struct V_42 * V_43 )
{
struct V_1 * V_39 ;
unsigned long V_6 ;
F_43 ( V_43 ) ;
V_39 = V_43 -> V_59 -> V_39 ;
F_44 ( & V_43 -> V_75 ) ;
F_4 ( & V_39 -> V_82 , V_6 ) ;
F_45 ( V_43 ) ;
F_46 ( & V_43 -> V_87 ) ;
F_5 ( & V_39 -> V_82 , V_6 ) ;
F_47 ( V_39 -> V_103 ) ;
F_48 ( V_43 ) ;
F_38 ( V_43 ) ;
F_49 ( & V_43 -> V_81 ) ;
F_30 ( V_43 -> V_44 ) ;
F_31 ( V_43 -> V_64 . V_65 ) ;
F_30 ( V_43 ) ;
}
static void F_50 ( struct V_92 * V_93 )
{
struct V_91 * V_59 ;
unsigned long V_6 ;
V_59 = V_93 -> V_59 ;
F_4 ( & V_59 -> V_95 , V_6 ) ;
V_59 -> V_97 [ V_93 -> V_102 ] = NULL ;
F_51 ( & V_59 -> V_100 ) ;
F_5 ( & V_59 -> V_95 , V_6 ) ;
F_41 ( V_93 ) ;
F_49 ( & V_93 -> V_81 ) ;
F_30 ( V_93 ) ;
}
int F_52 ( struct V_34 * V_104 )
{
struct V_42 * V_43 ;
struct V_92 * V_93 ;
if ( V_104 -> V_83 ) {
V_43 = F_53 ( V_104 ,
struct V_42 ,
V_64 ) ;
F_42 ( V_43 ) ;
} else {
V_93 = F_53 ( V_104 ,
struct V_92 ,
V_64 ) ;
F_50 ( V_93 ) ;
}
return 0 ;
}
static void F_54 ( struct V_105 * V_106 )
{
struct V_107 * V_108 ;
unsigned long V_6 ;
F_55 ( ! V_106 -> V_108 ) ;
V_108 = V_106 -> V_108 ;
F_4 ( & V_108 -> V_70 , V_6 ) ;
F_46 ( & V_106 -> V_109 ) ;
V_108 -> V_110 -- ;
F_5 ( & V_108 -> V_70 , V_6 ) ;
}
static void F_56 ( struct V_91 * V_59 ,
struct V_111 * V_112 ,
struct V_113 * V_114 ,
int V_88 )
{
struct V_92 * V_93 ;
unsigned long V_6 ;
int V_23 ;
F_4 ( & V_59 -> V_95 , V_6 ) ;
for ( V_23 = 0 ; V_23 < V_59 -> V_96 ; V_23 ++ ) {
V_93 = V_59 -> V_97 [ V_23 ] ;
if ( ! V_93 ||
! ( V_93 -> V_88 & V_88 ) )
continue;
F_36 ( & V_93 -> V_80 ) ;
F_5 ( & V_59 -> V_95 , V_6 ) ;
V_93 -> V_64 . V_101 ( & V_93 -> V_64 ,
V_112 , V_114 ) ;
F_41 ( V_93 ) ;
F_4 ( & V_59 -> V_95 , V_6 ) ;
}
F_5 ( & V_59 -> V_95 , V_6 ) ;
}
static void F_57 ( struct V_91 * V_59 ,
struct V_115 * V_116 ,
int V_88 )
{
struct V_92 * V_93 ;
unsigned long V_6 ;
int V_23 ;
F_4 ( & V_59 -> V_95 , V_6 ) ;
for ( V_23 = 0 ; V_23 < V_59 -> V_96 ; V_23 ++ ) {
V_93 = V_59 -> V_97 [ V_23 ] ;
if ( ! V_93 ||
! ( V_93 -> V_88 & V_88 ) )
continue;
F_36 ( & V_93 -> V_80 ) ;
F_5 ( & V_59 -> V_95 , V_6 ) ;
V_93 -> V_64 . V_37 ( & V_93 -> V_64 ,
V_116 ) ;
F_41 ( V_93 ) ;
F_4 ( & V_59 -> V_95 , V_6 ) ;
}
F_5 ( & V_59 -> V_95 , V_6 ) ;
}
static void F_58 ( struct V_117 * V_60 ,
T_5 V_118 , T_6 V_119 , T_6 V_120 , T_1 V_4 ,
struct V_121 * V_122 )
{
memset ( V_122 , 0 , sizeof *V_122 ) ;
V_122 -> V_118 = V_118 ;
V_122 -> V_123 = V_124 ;
V_122 -> V_125 = V_126 ;
V_122 -> V_120 = V_120 ;
V_122 -> V_127 = sizeof( struct V_26 ) + sizeof( struct V_128 ) ;
V_122 -> V_129 = V_130 ;
V_122 -> V_60 = V_60 ;
V_122 -> V_119 = V_119 ;
V_122 -> V_131 = 0 ;
V_122 -> V_132 = 0 ;
V_122 -> V_4 = V_4 ;
}
static int F_59 ( struct V_42 * V_43 ,
struct V_133 * V_134 )
{
int V_40 = 0 ;
struct V_135 * V_136 = V_134 -> V_112 . V_27 ;
unsigned long V_6 ;
struct V_137 * V_138 ;
struct V_139 * V_140 ;
struct V_1 * V_39 ;
struct V_42 * V_141 = NULL ;
struct V_2 * V_3 = V_43 -> V_64 . V_3 ;
T_1 V_4 ;
struct V_121 V_142 ;
struct V_143 * V_144 = & V_134 -> V_144 ;
if ( V_3 -> V_145 == V_146 &&
V_136 -> V_8 == V_9 )
V_4 = V_144 -> V_147 . V_148 . V_4 ;
else
V_4 = V_43 -> V_64 . V_4 ;
if ( ( F_60 ( V_136 ) ? V_136 -> V_149 : V_136 -> V_150 ) ==
V_151 &&
F_61 ( V_136 , V_3 -> V_145 , V_4 ) ==
V_152 ) {
V_40 = - V_41 ;
F_62 (KERN_ERR PFX L_1 ) ;
goto V_99;
}
if ( F_63 ( V_136 , V_3 ) == V_152 &&
F_64 ( V_136 , V_3 ) == V_152 )
goto V_99;
V_138 = F_65 ( sizeof *V_138 , V_98 ) ;
if ( ! V_138 ) {
V_40 = - V_63 ;
F_62 (KERN_ERR PFX L_2 ) ;
goto V_99;
}
V_138 -> V_140 = NULL ;
V_138 -> V_141 = NULL ;
V_140 = F_66 ( V_153 , V_98 ) ;
if ( ! V_140 ) {
V_40 = - V_63 ;
F_62 (KERN_ERR PFX L_3 ) ;
F_30 ( V_138 ) ;
goto V_99;
}
F_58 ( V_43 -> V_64 . V_60 ,
V_144 -> V_118 , F_67 ( V_136 -> V_150 ) ,
V_144 -> V_147 . V_148 . V_120 ,
V_144 -> V_147 . V_148 . V_4 , & V_142 ) ;
V_40 = V_3 -> V_154 ( V_3 , 0 , V_4 , & V_142 , NULL ,
(struct V_26 * ) V_136 ,
(struct V_26 * ) & V_140 -> V_27 ) ;
switch ( V_40 )
{
case V_155 | V_156 :
if ( F_13 ( & V_140 -> V_27 . V_27 ) &&
V_43 -> V_64 . V_37 ) {
V_138 -> V_140 = V_140 ;
V_138 -> V_141 = V_43 ;
F_36 ( & V_43 -> V_80 ) ;
} else
F_68 ( V_153 , V_140 ) ;
break;
case V_155 | V_157 :
F_68 ( V_153 , V_140 ) ;
break;
case V_155 :
V_39 = F_3 ( V_43 -> V_64 . V_3 ,
V_43 -> V_64 . V_4 ) ;
if ( V_39 ) {
memcpy ( & V_140 -> V_27 . V_27 , V_136 , sizeof( struct V_26 ) ) ;
V_141 = F_69 ( V_39 ,
& V_140 -> V_27 . V_27 ) ;
}
if ( ! V_39 || ! V_141 ) {
F_68 ( V_153 , V_140 ) ;
break;
}
V_138 -> V_140 = V_140 ;
V_138 -> V_141 = V_141 ;
break;
default:
F_68 ( V_153 , V_140 ) ;
F_30 ( V_138 ) ;
V_40 = - V_41 ;
goto V_99;
}
V_138 -> V_134 = V_134 ;
F_36 ( & V_43 -> V_80 ) ;
F_4 ( & V_43 -> V_70 , V_6 ) ;
F_29 ( & V_138 -> V_158 , & V_43 -> V_77 ) ;
F_5 ( & V_43 -> V_70 , V_6 ) ;
F_70 ( V_43 -> V_59 -> V_39 -> V_103 ,
& V_43 -> V_78 ) ;
V_40 = 1 ;
V_99:
return V_40 ;
}
static int F_71 ( int V_159 , int V_160 )
{
int V_161 , V_162 ;
V_161 = sizeof( struct V_26 ) - V_159 ;
if ( V_160 && V_161 ) {
V_162 = V_161 - V_160 % V_161 ;
return V_162 == V_161 ? 0 : V_162 ;
} else
return V_161 ;
}
static void F_72 ( struct V_133 * V_134 )
{
struct V_163 * V_164 , * V_165 ;
F_73 (s, t, &mad_send_wr->rmpp_list, list) {
F_46 ( & V_164 -> V_109 ) ;
F_30 ( V_164 ) ;
}
}
static int F_74 ( struct V_133 * V_144 ,
T_7 V_166 )
{
struct V_111 * V_112 = & V_144 -> V_112 ;
struct V_167 * V_168 = V_112 -> V_27 ;
struct V_163 * V_169 = NULL ;
int V_170 , V_161 , V_162 ;
V_112 -> V_161 = sizeof ( struct V_26 ) - V_112 -> V_159 ;
V_161 = V_112 -> V_161 ;
V_162 = V_144 -> V_162 ;
for ( V_170 = V_112 -> V_160 + V_162 ; V_170 > 0 ; V_170 -= V_161 ) {
V_169 = F_65 ( sizeof ( * V_169 ) + V_161 , V_166 ) ;
if ( ! V_169 ) {
F_62 ( V_171 L_4
L_5 ,
sizeof ( * V_169 ) + V_161 , V_166 ) ;
F_72 ( V_144 ) ;
return - V_63 ;
}
V_169 -> V_172 = ++ V_112 -> V_173 ;
F_29 ( & V_169 -> V_109 , & V_144 -> V_74 ) ;
}
if ( V_162 )
memset ( V_169 -> V_174 + V_161 - V_162 , 0 , V_162 ) ;
V_168 -> V_175 . V_35 = V_144 -> V_43 ->
V_64 . V_35 ;
V_168 -> V_175 . V_176 = V_177 ;
F_75 ( & V_168 -> V_175 , V_178 ) ;
V_144 -> V_179 = F_53 ( V_144 -> V_74 . V_180 ,
struct V_163 , V_109 ) ;
V_144 -> V_181 = V_144 -> V_179 ;
return 0 ;
}
struct V_111 * F_76 ( struct V_34 * V_104 ,
T_8 V_182 , T_6 V_120 ,
int V_183 ,
int V_159 , int V_160 ,
T_7 V_166 )
{
struct V_42 * V_43 ;
struct V_133 * V_134 ;
int V_162 , V_184 , V_40 , V_185 ;
void * V_186 ;
V_43 = F_53 ( V_104 , struct V_42 ,
V_64 ) ;
V_162 = F_71 ( V_159 , V_160 ) ;
V_184 = V_159 + V_160 + V_162 ;
if ( ( ! V_104 -> V_35 &&
( V_183 || V_184 > sizeof( struct V_26 ) ) ) ||
( ! V_183 && V_184 > sizeof( struct V_26 ) ) )
return F_15 ( - V_41 ) ;
V_185 = V_183 ? V_159 : sizeof( struct V_26 ) ;
V_186 = F_17 ( sizeof *V_134 + V_185 , V_166 ) ;
if ( ! V_186 )
return F_15 ( - V_63 ) ;
V_134 = V_186 + V_185 ;
F_22 ( & V_134 -> V_74 ) ;
V_134 -> V_112 . V_27 = V_186 ;
V_134 -> V_112 . V_159 = V_159 ;
V_134 -> V_112 . V_160 = V_160 ;
V_134 -> V_162 = V_162 ;
V_134 -> V_43 = V_43 ;
V_134 -> V_187 [ 0 ] . V_188 = V_159 ;
V_134 -> V_187 [ 0 ] . V_189 = V_104 -> V_65 -> V_189 ;
V_134 -> V_187 [ 1 ] . V_188 = sizeof( struct V_26 ) - V_159 ;
V_134 -> V_187 [ 1 ] . V_189 = V_104 -> V_65 -> V_189 ;
V_134 -> V_144 . V_118 = ( unsigned long ) V_134 ;
V_134 -> V_144 . V_187 = V_134 -> V_187 ;
V_134 -> V_144 . V_190 = 2 ;
V_134 -> V_144 . V_125 = V_191 ;
V_134 -> V_144 . V_192 = V_193 ;
V_134 -> V_144 . V_147 . V_148 . V_182 = V_182 ;
V_134 -> V_144 . V_147 . V_148 . V_194 = V_195 ;
V_134 -> V_144 . V_147 . V_148 . V_120 = V_120 ;
if ( V_183 ) {
V_40 = F_74 ( V_134 , V_166 ) ;
if ( V_40 ) {
F_30 ( V_186 ) ;
return F_15 ( V_40 ) ;
}
}
V_134 -> V_112 . V_104 = V_104 ;
F_36 ( & V_43 -> V_80 ) ;
return & V_134 -> V_112 ;
}
int F_77 ( T_1 V_8 )
{
if ( V_8 == V_196 )
return V_197 ;
else if ( ( V_8 == V_198 ) ||
( V_8 == V_199 ) ||
( V_8 == V_200 ) )
return V_201 ;
else if ( ( V_8 >= V_14 ) &&
( V_8 <= V_15 ) )
return V_202 ;
else
return V_203 ;
}
int F_16 ( T_1 V_8 )
{
if ( ( V_8 == V_196 ) ||
( V_8 == V_198 ) ||
( V_8 == V_199 ) ||
( V_8 == V_200 ) ||
( ( V_8 >= V_14 ) &&
( V_8 <= V_15 ) ) )
return 1 ;
return 0 ;
}
void * F_78 ( struct V_111 * V_112 , int V_204 )
{
struct V_133 * V_134 ;
struct V_205 * V_109 ;
V_134 = F_53 ( V_112 , struct V_133 ,
V_112 ) ;
V_109 = & V_134 -> V_179 -> V_109 ;
if ( V_134 -> V_179 -> V_172 < V_204 ) {
F_2 (mad_send_wr->cur_seg, list, list)
if ( V_134 -> V_179 -> V_172 == V_204 )
break;
} else if ( V_134 -> V_179 -> V_172 > V_204 ) {
F_79 (mad_send_wr->cur_seg, list, list)
if ( V_134 -> V_179 -> V_172 == V_204 )
break;
}
return V_134 -> V_179 -> V_174 ;
}
static inline void * F_80 ( struct V_133 * V_134 )
{
if ( V_134 -> V_112 . V_173 )
return F_78 ( & V_134 -> V_112 ,
V_134 -> V_204 ) ;
else
return V_134 -> V_112 . V_27 +
V_134 -> V_112 . V_159 ;
}
void F_81 ( struct V_111 * V_112 )
{
struct V_42 * V_43 ;
struct V_133 * V_134 ;
V_43 = F_53 ( V_112 -> V_104 ,
struct V_42 , V_64 ) ;
V_134 = F_53 ( V_112 , struct V_133 ,
V_112 ) ;
F_72 ( V_134 ) ;
F_30 ( V_112 -> V_27 ) ;
F_38 ( V_43 ) ;
}
int F_82 ( struct V_133 * V_134 )
{
struct V_91 * V_59 ;
struct V_205 * V_109 ;
struct V_143 * V_206 ;
struct V_34 * V_104 ;
struct V_207 * V_208 ;
unsigned long V_6 ;
int V_40 ;
V_59 = V_134 -> V_43 -> V_59 ;
V_134 -> V_144 . V_118 = ( unsigned long ) & V_134 -> V_106 ;
V_134 -> V_106 . V_108 = & V_59 -> V_209 ;
V_104 = V_134 -> V_112 . V_104 ;
V_208 = V_134 -> V_187 ;
V_208 [ 0 ] . V_210 = F_83 ( V_104 -> V_3 ,
V_134 -> V_112 . V_27 ,
V_208 [ 0 ] . V_188 ,
V_211 ) ;
V_134 -> V_212 = V_208 [ 0 ] . V_210 ;
V_208 [ 1 ] . V_210 = F_83 ( V_104 -> V_3 ,
F_80 ( V_134 ) ,
V_208 [ 1 ] . V_188 ,
V_211 ) ;
V_134 -> V_213 = V_208 [ 1 ] . V_210 ;
F_4 ( & V_59 -> V_209 . V_70 , V_6 ) ;
if ( V_59 -> V_209 . V_110 < V_59 -> V_209 . V_214 ) {
V_40 = F_84 ( V_104 -> V_60 , & V_134 -> V_144 ,
& V_206 ) ;
V_109 = & V_59 -> V_209 . V_109 ;
} else {
V_40 = 0 ;
V_109 = & V_59 -> V_215 ;
}
if ( ! V_40 ) {
V_59 -> V_209 . V_110 ++ ;
F_29 ( & V_134 -> V_106 . V_109 , V_109 ) ;
}
F_5 ( & V_59 -> V_209 . V_70 , V_6 ) ;
if ( V_40 ) {
F_85 ( V_104 -> V_3 ,
V_134 -> V_212 ,
V_208 [ 0 ] . V_188 , V_211 ) ;
F_85 ( V_104 -> V_3 ,
V_134 -> V_213 ,
V_208 [ 1 ] . V_188 , V_211 ) ;
}
return V_40 ;
}
int F_86 ( struct V_111 * V_112 ,
struct V_111 * * V_216 )
{
struct V_42 * V_43 ;
struct V_111 * V_217 ;
struct V_133 * V_134 ;
unsigned long V_6 ;
int V_40 = - V_41 ;
for (; V_112 ; V_112 = V_217 ) {
V_134 = F_53 ( V_112 ,
struct V_133 ,
V_112 ) ;
V_43 = V_134 -> V_43 ;
if ( ! V_112 -> V_104 -> V_36 ||
( V_112 -> V_218 &&
! V_112 -> V_104 -> V_37 ) ) {
V_40 = - V_41 ;
goto error;
}
if ( ! F_16 ( ( (struct V_219 * ) V_112 -> V_27 ) -> V_8 ) ) {
if ( V_43 -> V_64 . V_35 ) {
V_40 = - V_41 ;
goto error;
}
}
V_217 = V_112 -> V_180 ;
V_134 -> V_144 . V_147 . V_148 . V_220 = V_112 -> V_220 ;
if ( ( (struct V_219 * ) V_112 -> V_27 ) -> V_8 ==
V_9 ) {
V_40 = F_59 ( V_43 ,
V_134 ) ;
if ( V_40 < 0 )
goto error;
else if ( V_40 == 1 )
continue;
}
V_134 -> V_221 = ( (struct V_219 * ) V_112 -> V_27 ) -> V_221 ;
V_134 -> V_222 = F_87 ( V_112 -> V_218 ) ;
V_134 -> V_223 = V_112 -> V_224 ;
V_134 -> V_225 = V_112 -> V_224 ;
V_112 -> V_224 = 0 ;
V_134 -> V_80 = 1 + ( V_134 -> V_222 > 0 ) ;
V_134 -> V_123 = V_124 ;
F_36 ( & V_43 -> V_80 ) ;
F_4 ( & V_43 -> V_70 , V_6 ) ;
F_29 ( & V_134 -> V_87 ,
& V_43 -> V_71 ) ;
F_5 ( & V_43 -> V_70 , V_6 ) ;
if ( V_43 -> V_64 . V_35 ) {
V_40 = F_88 ( V_134 ) ;
if ( V_40 >= 0 && V_40 != V_226 )
V_40 = F_82 ( V_134 ) ;
} else
V_40 = F_82 ( V_134 ) ;
if ( V_40 < 0 ) {
F_4 ( & V_43 -> V_70 , V_6 ) ;
F_46 ( & V_134 -> V_87 ) ;
F_5 ( & V_43 -> V_70 , V_6 ) ;
F_51 ( & V_43 -> V_80 ) ;
goto error;
}
}
return 0 ;
error:
if ( V_216 )
* V_216 = V_112 ;
return V_40 ;
}
void F_89 ( struct V_115 * V_116 )
{
struct V_227 * V_228 , * V_229 ;
struct V_230 * V_231 ;
struct V_139 * V_232 ;
struct V_205 V_233 ;
F_22 ( & V_233 ) ;
F_90 ( & V_116 -> V_74 , & V_233 ) ;
F_73 (mad_recv_buf, temp_recv_buf,
&free_list, list) {
V_116 = F_53 ( V_228 , struct V_115 ,
V_234 ) ;
V_231 = F_53 ( V_116 ,
struct V_230 ,
V_235 ) ;
V_232 = F_53 ( V_231 , struct V_139 ,
V_236 ) ;
F_68 ( V_153 , V_232 ) ;
}
}
struct V_34 * F_91 ( struct V_117 * V_60 ,
T_1 V_35 ,
T_2 V_36 ,
T_3 V_37 ,
void * V_38 )
{
return F_15 ( - V_41 ) ;
}
int F_92 ( struct V_34 * V_104 ,
struct V_121 * V_122 )
{
F_62 (KERN_ERR PFX L_6 ) ;
return 0 ;
}
static int F_12 ( struct V_21 * * V_22 ,
struct V_19 * V_20 )
{
int V_23 ;
F_93 (i, mad_reg_req->method_mask, IB_MGMT_MAX_METHODS) {
if ( ( * V_22 ) -> V_64 [ V_23 ] ) {
F_62 (KERN_ERR PFX L_7 , i) ;
return - V_41 ;
}
}
return 0 ;
}
static int F_94 ( struct V_21 * * V_22 )
{
* V_22 = F_17 ( sizeof ** V_22 , V_98 ) ;
if ( ! * V_22 ) {
F_62 (KERN_ERR PFX L_8
L_9 ) ;
return - V_63 ;
}
return 0 ;
}
static int F_95 ( struct V_21 * V_22 )
{
int V_23 ;
for ( V_23 = 0 ; V_23 < V_237 ; V_23 ++ )
if ( V_22 -> V_64 [ V_23 ] )
return 1 ;
return 0 ;
}
static int F_96 ( struct V_45 * V_46 )
{
int V_23 ;
for ( V_23 = 0 ; V_23 < V_56 ; V_23 ++ )
if ( V_46 -> V_25 [ V_23 ] )
return 1 ;
return 0 ;
}
static int F_97 ( struct V_17 * V_18 )
{
int V_23 ;
for ( V_23 = 0 ; V_23 < V_24 ; V_23 ++ )
if ( V_18 -> V_25 [ V_23 ] )
return 1 ;
return 0 ;
}
static int F_98 ( struct V_17 * V_18 ,
char * V_16 )
{
int V_23 ;
for ( V_23 = 0 ; V_23 < V_24 ; V_23 ++ )
if ( ! memcmp ( V_18 -> V_16 [ V_23 ] , V_16 , 3 ) )
return V_23 ;
return - 1 ;
}
static int F_99 ( struct V_47 * V_48 )
{
int V_23 ;
for ( V_23 = 0 ; V_23 < V_238 ; V_23 ++ )
if ( V_48 -> V_18 [ V_23 ] )
return 1 ;
return 0 ;
}
static void F_100 ( struct V_21 * V_22 ,
struct V_42 * V_64 )
{
int V_23 ;
for ( V_23 = 0 ; V_23 < V_237 ; V_23 ++ ) {
if ( V_22 -> V_64 [ V_23 ] == V_64 ) {
V_22 -> V_64 [ V_23 ] = NULL ;
}
}
}
static int F_27 ( struct V_19 * V_20 ,
struct V_42 * V_239 ,
T_1 V_8 )
{
struct V_1 * V_39 ;
struct V_45 * * V_46 ;
struct V_21 * * V_22 ;
int V_23 , V_40 ;
V_39 = V_239 -> V_59 -> V_39 ;
V_46 = & V_39 -> V_85 [ V_20 -> V_54 ] . V_46 ;
if ( ! * V_46 ) {
* V_46 = F_17 ( sizeof ** V_46 , V_98 ) ;
if ( ! * V_46 ) {
F_62 (KERN_ERR PFX L_8
L_10 ) ;
V_40 = - V_63 ;
goto V_52;
}
V_22 = & ( * V_46 ) -> V_25 [ V_8 ] ;
if ( ( V_40 = F_94 ( V_22 ) ) )
goto V_68;
} else {
V_22 = & ( * V_46 ) -> V_25 [ V_8 ] ;
if ( ! * V_22 ) {
if ( ( V_40 = F_94 ( V_22 ) ) )
goto V_52;
}
}
if ( F_12 ( V_22 , V_20 ) )
goto V_69;
F_93 ( V_23 , V_20 -> V_240 , V_237 )
( * V_22 ) -> V_64 [ V_23 ] = V_239 ;
return 0 ;
V_69:
F_100 ( * V_22 , V_239 ) ;
if ( ! F_95 ( * V_22 ) ) {
F_30 ( * V_22 ) ;
* V_22 = NULL ;
}
V_40 = - V_41 ;
goto V_52;
V_68:
F_30 ( * V_46 ) ;
* V_46 = NULL ;
V_52:
return V_40 ;
}
static int F_28 ( struct V_19 * V_20 ,
struct V_42 * V_239 )
{
struct V_1 * V_39 ;
struct V_47 * * V_241 ;
struct V_47 * V_48 = NULL ;
struct V_17 * V_18 = NULL ;
struct V_21 * * V_22 ;
int V_23 , V_40 = - V_63 ;
T_1 V_51 ;
V_51 = F_8 ( V_20 -> V_8 ) ;
V_39 = V_239 -> V_59 -> V_39 ;
V_241 = & V_39 -> V_85 [
V_20 -> V_54 ] . V_48 ;
if ( ! * V_241 ) {
V_48 = F_17 ( sizeof *V_48 , V_98 ) ;
if ( ! V_48 ) {
F_62 (KERN_ERR PFX L_8
L_11 ) ;
goto V_52;
}
* V_241 = V_48 ;
}
if ( ! ( * V_241 ) -> V_18 [ V_51 ] ) {
V_18 = F_17 ( sizeof *V_18 , V_98 ) ;
if ( ! V_18 ) {
F_62 (KERN_ERR PFX L_8
L_12 ) ;
goto V_68;
}
( * V_241 ) -> V_18 [ V_51 ] = V_18 ;
}
for ( V_23 = 0 ; V_23 < V_24 ; V_23 ++ ) {
if ( ! memcmp ( ( * V_241 ) -> V_18 [ V_51 ] -> V_16 [ V_23 ] ,
V_20 -> V_16 , 3 ) ) {
V_22 = & ( * V_241 ) -> V_18 [
V_51 ] -> V_25 [ V_23 ] ;
F_55 ( ! * V_22 ) ;
goto V_242;
}
}
for ( V_23 = 0 ; V_23 < V_24 ; V_23 ++ ) {
if ( ! F_10 ( ( * V_241 ) -> V_18 [
V_51 ] -> V_16 [ V_23 ] ) ) {
V_22 = & ( * V_241 ) -> V_18 [
V_51 ] -> V_25 [ V_23 ] ;
F_55 ( * V_22 ) ;
if ( ( V_40 = F_94 ( V_22 ) ) )
goto V_69;
memcpy ( ( * V_241 ) -> V_18 [ V_51 ] -> V_16 [ V_23 ] ,
V_20 -> V_16 , 3 ) ;
goto V_242;
}
}
F_62 (KERN_ERR PFX L_13 ) ;
goto V_69;
V_242:
if ( F_12 ( V_22 , V_20 ) )
goto V_86;
F_93 ( V_23 , V_20 -> V_240 , V_237 )
( * V_22 ) -> V_64 [ V_23 ] = V_239 ;
return 0 ;
V_86:
F_100 ( * V_22 , V_239 ) ;
if ( ! F_95 ( * V_22 ) ) {
F_30 ( * V_22 ) ;
* V_22 = NULL ;
}
V_40 = - V_41 ;
V_69:
if ( V_18 ) {
( * V_241 ) -> V_18 [ V_51 ] = NULL ;
F_30 ( V_18 ) ;
}
V_68:
if ( V_48 ) {
* V_241 = NULL ;
F_30 ( V_48 ) ;
}
V_52:
return V_40 ;
}
static void F_45 ( struct V_42 * V_239 )
{
struct V_1 * V_39 ;
struct V_45 * V_46 ;
struct V_21 * V_22 ;
struct V_47 * V_48 ;
struct V_17 * V_18 ;
int V_243 ;
T_1 V_8 ;
if ( ! V_239 -> V_44 ) {
goto V_99;
}
V_39 = V_239 -> V_59 -> V_39 ;
V_8 = F_6 ( V_239 -> V_44 -> V_8 ) ;
V_46 = V_39 -> V_85 [
V_239 -> V_44 -> V_54 ] . V_46 ;
if ( ! V_46 )
goto V_244;
V_22 = V_46 -> V_25 [ V_8 ] ;
if ( V_22 ) {
F_100 ( V_22 , V_239 ) ;
if ( ! F_95 ( V_22 ) ) {
F_30 ( V_22 ) ;
V_46 -> V_25 [ V_8 ] = NULL ;
if ( ! F_96 ( V_46 ) ) {
F_30 ( V_46 ) ;
V_39 -> V_85 [
V_239 -> V_44 ->
V_54 ] . V_46 = NULL ;
}
}
}
V_244:
if ( ! F_9 ( V_8 ) )
goto V_99;
V_8 = F_8 ( V_239 -> V_44 -> V_8 ) ;
V_48 = V_39 -> V_85 [
V_239 -> V_44 -> V_54 ] . V_48 ;
if ( ! V_48 )
goto V_99;
V_18 = V_48 -> V_18 [ V_8 ] ;
if ( V_18 ) {
V_243 = F_98 ( V_18 , V_239 -> V_44 -> V_16 ) ;
if ( V_243 < 0 )
goto V_99;
V_22 = V_18 -> V_25 [ V_243 ] ;
if ( V_22 ) {
F_100 ( V_22 , V_239 ) ;
if ( ! F_95 ( V_22 ) ) {
F_30 ( V_22 ) ;
V_18 -> V_25 [ V_243 ] = NULL ;
memset ( V_18 -> V_16 [ V_243 ] , 0 , 3 ) ;
if ( ! F_97 ( V_18 ) ) {
F_30 ( V_18 ) ;
V_48 -> V_18 [ V_8 ] = NULL ;
if ( ! F_99 ( V_48 ) ) {
F_30 ( V_48 ) ;
V_39 -> V_85 [
V_239 -> V_44 ->
V_54 ] .
V_48 = NULL ;
}
}
}
}
}
V_99:
return;
}
static struct V_42 *
F_69 ( struct V_1 * V_39 ,
struct V_26 * V_27 )
{
struct V_42 * V_104 = NULL ;
unsigned long V_6 ;
F_4 ( & V_39 -> V_82 , V_6 ) ;
if ( F_13 ( V_27 ) ) {
T_8 V_83 ;
struct V_42 * V_5 ;
V_83 = F_101 ( V_27 -> V_28 . V_221 ) >> 32 ;
F_2 (entry, &port_priv->agent_list, agent_list) {
if ( V_5 -> V_64 . V_83 == V_83 ) {
V_104 = V_5 ;
break;
}
}
} else {
struct V_45 * V_46 ;
struct V_21 * V_22 ;
struct V_47 * V_48 ;
struct V_17 * V_18 ;
struct V_245 * V_246 ;
int V_243 ;
if ( V_27 -> V_28 . V_247 >= V_55 )
goto V_99;
if ( ! F_9 ( V_27 -> V_28 . V_8 ) ) {
V_46 = V_39 -> V_85 [
V_27 -> V_28 . V_247 ] . V_46 ;
if ( ! V_46 )
goto V_99;
if ( F_6 ( V_27 -> V_28 . V_8 ) >=
V_237 )
goto V_99;
V_22 = V_46 -> V_25 [ F_6 (
V_27 -> V_28 . V_8 ) ] ;
if ( V_22 )
V_104 = V_22 -> V_64 [ V_27 -> V_28 . V_22 &
~ V_29 ] ;
} else {
V_48 = V_39 -> V_85 [
V_27 -> V_28 . V_247 ] . V_48 ;
if ( ! V_48 )
goto V_99;
V_18 = V_48 -> V_18 [ F_8 (
V_27 -> V_28 . V_8 ) ] ;
if ( ! V_18 )
goto V_99;
V_246 = (struct V_245 * ) V_27 ;
V_243 = F_98 ( V_18 , V_246 -> V_16 ) ;
if ( V_243 == - 1 )
goto V_99;
V_22 = V_18 -> V_25 [ V_243 ] ;
if ( V_22 ) {
V_104 = V_22 -> V_64 [ V_27 -> V_28 . V_22 &
~ V_29 ] ;
}
}
}
if ( V_104 ) {
if ( V_104 -> V_64 . V_37 )
F_36 ( & V_104 -> V_80 ) ;
else {
F_62 (KERN_NOTICE PFX L_14
L_15 ,
&mad_agent->agent, port_priv->port_num) ;
V_104 = NULL ;
}
}
V_99:
F_5 ( & V_39 -> V_82 , V_6 ) ;
return V_104 ;
}
static int F_102 ( struct V_26 * V_27 , T_8 V_248 )
{
int V_249 = 0 ;
if ( V_27 -> V_28 . V_250 != V_251 ) {
F_62 (KERN_ERR PFX L_16
L_17 , mad->mad_hdr.base_version) ;
goto V_99;
}
if ( ( V_27 -> V_28 . V_8 == V_57 ) ||
( V_27 -> V_28 . V_8 == V_9 ) ) {
if ( V_248 == 0 )
V_249 = 1 ;
} else {
if ( V_248 != 0 )
V_249 = 1 ;
}
V_99:
return V_249 ;
}
static int F_103 ( struct V_42 * V_43 ,
struct V_219 * V_28 )
{
struct V_167 * V_168 ;
V_168 = (struct V_167 * ) V_28 ;
return ! V_43 -> V_64 . V_35 ||
! ( F_104 ( & V_168 -> V_175 ) &
V_178 ) ||
( V_168 -> V_175 . V_176 == V_177 ) ;
}
static inline int F_105 ( struct V_133 * V_147 ,
struct V_115 * V_252 )
{
return ( (struct V_26 * ) ( V_147 -> V_112 . V_27 ) ) -> V_28 . V_8 ==
V_252 -> V_234 . V_27 -> V_28 . V_8 ;
}
static inline int F_106 ( struct V_42 * V_43 ,
struct V_133 * V_147 ,
struct V_115 * V_252 )
{
struct V_253 V_254 ;
T_1 V_255 , V_256 ;
union V_257 V_258 ;
struct V_2 * V_3 = V_43 -> V_64 . V_3 ;
T_1 V_4 = V_43 -> V_64 . V_4 ;
T_1 V_259 ;
V_255 = F_13 ( (struct V_26 * ) V_147 -> V_112 . V_27 ) ;
V_256 = F_13 ( V_252 -> V_234 . V_27 ) ;
if ( V_255 == V_256 )
return 0 ;
if ( F_107 ( V_147 -> V_112 . V_220 , & V_254 ) )
return 0 ;
if ( ! ! ( V_254 . V_260 & V_261 ) !=
! ! ( V_252 -> V_122 -> V_262 & V_263 ) )
return 0 ;
if ( ! V_255 && V_256 ) {
if ( ! ( V_254 . V_260 & V_261 ) ) {
if ( F_108 ( V_3 , V_4 , & V_259 ) )
return 0 ;
return ( ! V_259 || ! ( ( V_254 . V_264 ^
V_252 -> V_122 -> V_132 ) &
( ( 1 << V_259 ) - 1 ) ) ) ;
} else {
if ( F_109 ( V_3 , V_4 ,
V_254 . V_265 . V_266 , & V_258 ) )
return 0 ;
return ! memcmp ( V_258 . V_267 , V_252 -> V_234 . V_265 -> V_268 . V_267 ,
16 ) ;
}
}
if ( ! ( V_254 . V_260 & V_261 ) )
return V_254 . V_269 == V_252 -> V_122 -> V_119 ;
else
return ! memcmp ( V_254 . V_265 . V_268 . V_267 , V_252 -> V_234 . V_265 -> V_258 . V_267 ,
16 ) ;
}
static inline int F_110 ( T_1 V_46 )
{
return ( V_46 == V_9 ) ;
}
struct V_133 *
F_111 ( struct V_42 * V_43 ,
struct V_115 * V_122 )
{
struct V_133 * V_147 ;
struct V_26 * V_27 ;
V_27 = (struct V_26 * ) V_122 -> V_234 . V_27 ;
F_2 (wr, &mad_agent_priv->wait_list, agent_list) {
if ( ( V_147 -> V_221 == V_27 -> V_28 . V_221 ) &&
F_105 ( V_147 , V_122 ) &&
( F_110 ( V_122 -> V_234 . V_27 -> V_28 . V_8 ) ||
F_106 ( V_43 , V_147 , V_122 ) ) )
return ( V_147 -> V_123 == V_124 ) ? V_147 : NULL ;
}
F_2 (wr, &mad_agent_priv->send_list, agent_list) {
if ( F_103 ( V_43 , V_147 -> V_112 . V_27 ) &&
V_147 -> V_221 == V_27 -> V_28 . V_221 &&
V_147 -> V_222 &&
F_105 ( V_147 , V_122 ) &&
( F_110 ( V_122 -> V_234 . V_27 -> V_28 . V_8 ) ||
F_106 ( V_43 , V_147 , V_122 ) ) )
return ( V_147 -> V_123 == V_124 ) ? V_147 : NULL ;
}
return NULL ;
}
void F_112 ( struct V_133 * V_134 )
{
V_134 -> V_222 = 0 ;
if ( V_134 -> V_80 == 1 )
F_113 ( & V_134 -> V_87 ,
& V_134 -> V_43 -> V_73 ) ;
}
static void F_114 ( struct V_42 * V_43 ,
struct V_115 * V_116 )
{
struct V_133 * V_134 ;
struct V_113 V_114 ;
unsigned long V_6 ;
F_22 ( & V_116 -> V_74 ) ;
F_115 ( & V_116 -> V_234 . V_109 , & V_116 -> V_74 ) ;
if ( V_43 -> V_64 . V_35 ) {
V_116 = F_116 ( V_43 ,
V_116 ) ;
if ( ! V_116 ) {
F_38 ( V_43 ) ;
return;
}
}
if ( F_13 ( V_116 -> V_234 . V_27 ) ) {
F_4 ( & V_43 -> V_70 , V_6 ) ;
V_134 = F_111 ( V_43 , V_116 ) ;
if ( ! V_134 ) {
F_5 ( & V_43 -> V_70 , V_6 ) ;
F_89 ( V_116 ) ;
F_38 ( V_43 ) ;
return;
}
F_112 ( V_134 ) ;
F_5 ( & V_43 -> V_70 , V_6 ) ;
V_116 -> V_122 -> V_118 = ( unsigned long ) & V_134 -> V_112 ;
V_43 -> V_64 . V_37 ( & V_43 -> V_64 ,
V_116 ) ;
F_51 ( & V_43 -> V_80 ) ;
V_114 . V_123 = V_124 ;
V_114 . V_270 = 0 ;
V_114 . V_112 = & V_134 -> V_112 ;
F_117 ( V_134 , & V_114 ) ;
} else {
V_43 -> V_64 . V_37 ( & V_43 -> V_64 ,
V_116 ) ;
F_38 ( V_43 ) ;
}
}
static bool F_118 ( struct V_139 * V_271 ,
struct V_139 * V_272 )
{
if ( V_271 -> V_27 . V_27 . V_28 . V_22 == V_273 ||
V_271 -> V_27 . V_27 . V_28 . V_22 == V_274 ) {
memcpy ( V_272 , V_271 , sizeof *V_272 ) ;
V_272 -> V_236 . V_235 . V_122 = & V_272 -> V_236 . V_122 ;
V_272 -> V_236 . V_235 . V_234 . V_27 = & V_272 -> V_27 . V_27 ;
V_272 -> V_236 . V_235 . V_234 . V_265 = & V_272 -> V_265 ;
V_272 -> V_27 . V_27 . V_28 . V_22 = V_275 ;
V_272 -> V_27 . V_27 . V_28 . V_123 =
F_119 ( V_276 ) ;
if ( V_271 -> V_27 . V_27 . V_28 . V_8 == V_9 )
V_272 -> V_27 . V_27 . V_28 . V_123 |= V_277 ;
return true ;
} else {
return false ;
}
}
static void F_120 ( struct V_1 * V_39 ,
struct V_121 * V_122 )
{
struct V_91 * V_59 ;
struct V_230 * V_231 ;
struct V_139 * V_271 , * V_272 = NULL ;
struct V_105 * V_106 ;
struct V_42 * V_104 ;
int V_4 ;
int V_40 = V_155 ;
V_106 = (struct V_105 * ) ( unsigned long ) V_122 -> V_118 ;
V_59 = V_106 -> V_108 -> V_59 ;
F_54 ( V_106 ) ;
V_231 = F_53 ( V_106 , struct V_230 ,
V_106 ) ;
V_271 = F_53 ( V_231 , struct V_139 , V_236 ) ;
F_85 ( V_39 -> V_3 ,
V_271 -> V_236 . V_278 ,
sizeof( struct V_139 ) -
sizeof( struct V_230 ) ,
V_279 ) ;
V_271 -> V_236 . V_122 = * V_122 ;
V_271 -> V_236 . V_235 . V_122 = & V_271 -> V_236 . V_122 ;
V_271 -> V_236 . V_235 . V_280 = sizeof( struct V_26 ) ;
V_271 -> V_236 . V_235 . V_234 . V_27 = & V_271 -> V_27 . V_27 ;
V_271 -> V_236 . V_235 . V_234 . V_265 = & V_271 -> V_265 ;
if ( F_121 ( & V_59 -> V_100 ) )
F_57 ( V_59 , & V_271 -> V_236 . V_235 , V_90 ) ;
if ( ! F_102 ( & V_271 -> V_27 . V_27 , V_59 -> V_60 -> V_248 ) )
goto V_99;
V_272 = F_66 ( V_153 , V_62 ) ;
if ( ! V_272 ) {
F_62 (KERN_ERR PFX L_18
L_19 ) ;
goto V_99;
}
if ( V_39 -> V_3 -> V_145 == V_146 )
V_4 = V_122 -> V_4 ;
else
V_4 = V_39 -> V_4 ;
if ( V_271 -> V_27 . V_27 . V_28 . V_8 ==
V_9 ) {
enum V_281 V_282 ;
if ( F_122 ( & V_271 -> V_27 . V_136 ,
V_39 -> V_3 -> V_145 ,
V_4 ,
V_39 -> V_3 -> V_283 ) ==
V_152 )
goto V_99;
V_282 = F_123 ( & V_271 -> V_27 . V_136 ) ;
if ( V_282 == V_284 )
goto V_138;
if ( V_282 == V_285 ) {
if ( F_61 ( & V_271 -> V_27 . V_136 ,
V_39 -> V_3 -> V_145 ,
V_4 ) == V_152 )
goto V_99;
if ( F_63 ( & V_271 -> V_27 . V_136 , V_39 -> V_3 ) == V_152 )
goto V_99;
} else if ( V_39 -> V_3 -> V_145 == V_146 ) {
memcpy ( V_272 , V_271 , sizeof( * V_272 ) ) ;
V_272 -> V_236 . V_235 . V_122 = & V_272 -> V_236 . V_122 ;
V_272 -> V_236 . V_235 . V_234 . V_27 = & V_272 -> V_27 . V_27 ;
V_272 -> V_236 . V_235 . V_234 . V_265 = & V_272 -> V_265 ;
F_124 ( & V_272 -> V_27 . V_27 ,
& V_272 -> V_265 , V_122 ,
V_39 -> V_3 ,
F_125 ( & V_271 -> V_27 . V_136 ) ,
V_59 -> V_60 -> V_248 ) ;
goto V_99;
}
}
V_138:
if ( V_39 -> V_3 -> V_154 ) {
V_40 = V_39 -> V_3 -> V_154 ( V_39 -> V_3 , 0 ,
V_39 -> V_4 ,
V_122 , & V_271 -> V_265 ,
& V_271 -> V_27 . V_27 ,
& V_272 -> V_27 . V_27 ) ;
if ( V_40 & V_155 ) {
if ( V_40 & V_157 )
goto V_99;
if ( V_40 & V_156 ) {
F_124 ( & V_272 -> V_27 . V_27 ,
& V_271 -> V_265 , V_122 ,
V_39 -> V_3 ,
V_4 ,
V_59 -> V_60 -> V_248 ) ;
goto V_99;
}
}
}
V_104 = F_69 ( V_39 , & V_271 -> V_27 . V_27 ) ;
if ( V_104 ) {
F_114 ( V_104 , & V_271 -> V_236 . V_235 ) ;
V_271 = NULL ;
} else if ( ( V_40 & V_155 ) &&
F_118 ( V_271 , V_272 ) ) {
F_124 ( & V_272 -> V_27 . V_27 , & V_271 -> V_265 , V_122 ,
V_39 -> V_3 , V_4 , V_59 -> V_60 -> V_248 ) ;
}
V_99:
if ( V_272 ) {
F_126 ( V_59 , V_272 ) ;
if ( V_271 )
F_68 ( V_153 , V_271 ) ;
} else
F_126 ( V_59 , V_271 ) ;
}
static void F_127 ( struct V_42 * V_43 )
{
struct V_133 * V_134 ;
unsigned long V_286 ;
if ( F_128 ( & V_43 -> V_72 ) ) {
F_44 ( & V_43 -> V_75 ) ;
} else {
V_134 = F_129 ( V_43 -> V_72 . V_180 ,
struct V_133 ,
V_87 ) ;
if ( F_130 ( V_43 -> V_222 ,
V_134 -> V_222 ) ) {
V_43 -> V_222 = V_134 -> V_222 ;
V_286 = V_134 -> V_222 - V_287 ;
if ( ( long ) V_286 <= 0 )
V_286 = 1 ;
F_131 ( V_43 -> V_59 -> V_39 -> V_103 ,
& V_43 -> V_75 , V_286 ) ;
}
}
}
static void F_132 ( struct V_133 * V_134 )
{
struct V_42 * V_43 ;
struct V_133 * V_288 ;
struct V_205 * V_289 ;
unsigned long V_286 ;
V_43 = V_134 -> V_43 ;
F_46 ( & V_134 -> V_87 ) ;
V_286 = V_134 -> V_222 ;
V_134 -> V_222 += V_287 ;
if ( V_286 ) {
F_133 (list_item, &mad_agent_priv->wait_list) {
V_288 = F_129 ( V_289 ,
struct V_133 ,
V_87 ) ;
if ( F_130 ( V_134 -> V_222 ,
V_288 -> V_222 ) )
break;
}
}
else
V_289 = & V_43 -> V_72 ;
F_115 ( & V_134 -> V_87 , V_289 ) ;
if ( V_43 -> V_72 . V_180 == & V_134 -> V_87 )
F_131 ( V_43 -> V_59 -> V_39 -> V_103 ,
& V_43 -> V_75 , V_286 ) ;
}
void F_134 ( struct V_133 * V_134 ,
int V_218 )
{
V_134 -> V_222 = F_87 ( V_218 ) ;
F_132 ( V_134 ) ;
}
void F_117 ( struct V_133 * V_134 ,
struct V_113 * V_114 )
{
struct V_42 * V_43 ;
unsigned long V_6 ;
int V_40 ;
V_43 = V_134 -> V_43 ;
F_4 ( & V_43 -> V_70 , V_6 ) ;
if ( V_43 -> V_64 . V_35 ) {
V_40 = F_135 ( V_134 , V_114 ) ;
if ( V_40 == V_226 )
goto V_290;
} else
V_40 = V_291 ;
if ( V_114 -> V_123 != V_124 &&
V_134 -> V_123 == V_124 ) {
V_134 -> V_123 = V_114 -> V_123 ;
V_134 -> V_80 -= ( V_134 -> V_222 > 0 ) ;
}
if ( -- V_134 -> V_80 > 0 ) {
if ( V_134 -> V_80 == 1 && V_134 -> V_222 &&
V_134 -> V_123 == V_124 ) {
F_132 ( V_134 ) ;
}
goto V_290;
}
F_46 ( & V_134 -> V_87 ) ;
F_127 ( V_43 ) ;
F_5 ( & V_43 -> V_70 , V_6 ) ;
if ( V_134 -> V_123 != V_124 )
V_114 -> V_123 = V_134 -> V_123 ;
if ( V_40 == V_292 )
F_136 ( V_114 ) ;
else
V_43 -> V_64 . V_36 ( & V_43 -> V_64 ,
V_114 ) ;
F_38 ( V_43 ) ;
return;
V_290:
F_5 ( & V_43 -> V_70 , V_6 ) ;
}
static void F_137 ( struct V_1 * V_39 ,
struct V_121 * V_122 )
{
struct V_133 * V_134 , * V_293 ;
struct V_105 * V_106 ;
struct V_91 * V_59 ;
struct V_107 * V_209 ;
struct V_143 * V_206 ;
struct V_113 V_114 ;
unsigned long V_6 ;
int V_40 ;
V_106 = (struct V_105 * ) ( unsigned long ) V_122 -> V_118 ;
V_134 = F_53 ( V_106 , struct V_133 ,
V_106 ) ;
V_209 = V_106 -> V_108 ;
V_59 = V_209 -> V_59 ;
V_294:
F_85 ( V_134 -> V_112 . V_104 -> V_3 ,
V_134 -> V_212 ,
V_134 -> V_187 [ 0 ] . V_188 , V_211 ) ;
F_85 ( V_134 -> V_112 . V_104 -> V_3 ,
V_134 -> V_213 ,
V_134 -> V_187 [ 1 ] . V_188 , V_211 ) ;
V_293 = NULL ;
F_4 ( & V_209 -> V_70 , V_6 ) ;
F_46 ( & V_106 -> V_109 ) ;
if ( V_209 -> V_110 -- > V_209 -> V_214 ) {
V_106 = F_53 ( V_59 -> V_215 . V_180 ,
struct V_105 , V_109 ) ;
V_293 = F_53 ( V_106 ,
struct V_133 ,
V_106 ) ;
F_113 ( & V_106 -> V_109 , & V_209 -> V_109 ) ;
}
F_5 ( & V_209 -> V_70 , V_6 ) ;
V_114 . V_112 = & V_134 -> V_112 ;
V_114 . V_123 = V_122 -> V_123 ;
V_114 . V_270 = V_122 -> V_270 ;
if ( F_121 ( & V_59 -> V_100 ) )
F_56 ( V_59 , & V_134 -> V_112 , & V_114 ,
V_89 ) ;
F_117 ( V_134 , & V_114 ) ;
if ( V_293 ) {
V_40 = F_84 ( V_59 -> V_60 , & V_293 -> V_144 ,
& V_206 ) ;
if ( V_40 ) {
F_62 (KERN_ERR PFX L_20 , ret) ;
V_134 = V_293 ;
V_122 -> V_123 = V_295 ;
goto V_294;
}
}
}
static void F_138 ( struct V_91 * V_59 )
{
struct V_133 * V_134 ;
struct V_105 * V_106 ;
unsigned long V_6 ;
F_4 ( & V_59 -> V_209 . V_70 , V_6 ) ;
F_2 (mad_list, &qp_info->send_queue.list, list) {
V_134 = F_53 ( V_106 ,
struct V_133 ,
V_106 ) ;
V_134 -> V_294 = 1 ;
}
F_5 ( & V_59 -> V_209 . V_70 , V_6 ) ;
}
static void F_139 ( struct V_1 * V_39 ,
struct V_121 * V_122 )
{
struct V_105 * V_106 ;
struct V_91 * V_59 ;
struct V_133 * V_134 ;
int V_40 ;
V_106 = (struct V_105 * ) ( unsigned long ) V_122 -> V_118 ;
V_59 = V_106 -> V_108 -> V_59 ;
if ( V_106 -> V_108 == & V_59 -> V_296 )
return;
V_134 = F_53 ( V_106 , struct V_133 ,
V_106 ) ;
if ( V_122 -> V_123 == V_297 ) {
if ( V_134 -> V_294 ) {
struct V_143 * V_206 ;
V_134 -> V_294 = 0 ;
V_40 = F_84 ( V_59 -> V_60 , & V_134 -> V_144 ,
& V_206 ) ;
if ( V_40 )
F_137 ( V_39 , V_122 ) ;
} else
F_137 ( V_39 , V_122 ) ;
} else {
struct V_298 * V_254 ;
V_254 = F_65 ( sizeof *V_254 , V_62 ) ;
if ( V_254 ) {
V_254 -> V_299 = V_300 ;
V_254 -> V_301 = V_302 ;
V_40 = F_140 ( V_59 -> V_60 , V_254 ,
V_303 | V_304 ) ;
F_30 ( V_254 ) ;
if ( V_40 )
F_62 (KERN_ERR PFX L_21
L_22 , ret) ;
else
F_138 ( V_59 ) ;
}
F_137 ( V_39 , V_122 ) ;
}
}
static void F_141 ( struct V_305 * V_306 )
{
struct V_1 * V_39 ;
struct V_121 V_122 ;
V_39 = F_53 ( V_306 , struct V_1 , V_306 ) ;
F_142 ( V_39 -> V_307 , V_308 ) ;
while ( F_143 ( V_39 -> V_307 , 1 , & V_122 ) == 1 ) {
if ( V_122 . V_123 == V_124 ) {
switch ( V_122 . V_125 ) {
case V_309 :
F_137 ( V_39 , & V_122 ) ;
break;
case V_126 :
F_120 ( V_39 , & V_122 ) ;
break;
default:
F_55 ( 1 ) ;
break;
}
} else
F_139 ( V_39 , & V_122 ) ;
}
}
static void F_43 ( struct V_42 * V_43 )
{
unsigned long V_6 ;
struct V_133 * V_134 , * V_288 ;
struct V_113 V_114 ;
struct V_205 V_310 ;
F_22 ( & V_310 ) ;
F_4 ( & V_43 -> V_70 , V_6 ) ;
F_73 (mad_send_wr, temp_mad_send_wr,
&mad_agent_priv->send_list, agent_list) {
if ( V_134 -> V_123 == V_124 ) {
V_134 -> V_123 = V_297 ;
V_134 -> V_80 -= ( V_134 -> V_222 > 0 ) ;
}
}
F_90 ( & V_43 -> V_72 , & V_310 ) ;
F_5 ( & V_43 -> V_70 , V_6 ) ;
V_114 . V_123 = V_297 ;
V_114 . V_270 = 0 ;
F_73 (mad_send_wr, temp_mad_send_wr,
&cancel_list, agent_list) {
V_114 . V_112 = & V_134 -> V_112 ;
F_46 ( & V_134 -> V_87 ) ;
V_43 -> V_64 . V_36 ( & V_43 -> V_64 ,
& V_114 ) ;
F_51 ( & V_43 -> V_80 ) ;
}
}
static struct V_133 *
F_144 ( struct V_42 * V_43 ,
struct V_111 * V_112 )
{
struct V_133 * V_134 ;
F_2 (mad_send_wr, &mad_agent_priv->wait_list,
agent_list) {
if ( & V_134 -> V_112 == V_112 )
return V_134 ;
}
F_2 (mad_send_wr, &mad_agent_priv->send_list,
agent_list) {
if ( F_103 ( V_43 , V_134 -> V_112 . V_27 ) &&
& V_134 -> V_112 == V_112 )
return V_134 ;
}
return NULL ;
}
int F_145 ( struct V_34 * V_104 ,
struct V_111 * V_112 , T_8 V_218 )
{
struct V_42 * V_43 ;
struct V_133 * V_134 ;
unsigned long V_6 ;
int V_311 ;
V_43 = F_53 ( V_104 , struct V_42 ,
V_64 ) ;
F_4 ( & V_43 -> V_70 , V_6 ) ;
V_134 = F_144 ( V_43 , V_112 ) ;
if ( ! V_134 || V_134 -> V_123 != V_124 ) {
F_5 ( & V_43 -> V_70 , V_6 ) ;
return - V_41 ;
}
V_311 = ( ! V_134 -> V_222 || V_134 -> V_80 > 1 ) ;
if ( ! V_218 ) {
V_134 -> V_123 = V_297 ;
V_134 -> V_80 -= ( V_134 -> V_222 > 0 ) ;
}
V_134 -> V_112 . V_218 = V_218 ;
if ( V_311 )
V_134 -> V_222 = F_87 ( V_218 ) ;
else
F_134 ( V_134 , V_218 ) ;
F_5 ( & V_43 -> V_70 , V_6 ) ;
return 0 ;
}
void F_146 ( struct V_34 * V_104 ,
struct V_111 * V_112 )
{
F_145 ( V_104 , V_112 , 0 ) ;
}
static void V_79 ( struct V_305 * V_306 )
{
struct V_42 * V_43 ;
struct V_137 * V_138 ;
struct V_42 * V_141 ;
unsigned long V_6 ;
int V_312 ;
struct V_121 V_122 ;
struct V_113 V_114 ;
V_43 =
F_53 ( V_306 , struct V_42 , V_78 ) ;
F_4 ( & V_43 -> V_70 , V_6 ) ;
while ( ! F_128 ( & V_43 -> V_77 ) ) {
V_138 = F_129 ( V_43 -> V_77 . V_180 ,
struct V_137 ,
V_158 ) ;
F_46 ( & V_138 -> V_158 ) ;
F_5 ( & V_43 -> V_70 , V_6 ) ;
V_312 = 0 ;
if ( V_138 -> V_140 ) {
V_141 = V_138 -> V_141 ;
if ( ! V_141 ) {
F_62 (KERN_ERR PFX L_23 ) ;
V_312 = 1 ;
goto V_313;
}
F_58 ( V_141 -> V_64 . V_60 ,
( unsigned long ) V_138 -> V_134 ,
F_67 ( V_151 ) ,
0 , V_141 -> V_64 . V_4 , & V_122 ) ;
V_138 -> V_140 -> V_236 . V_235 . V_122 = & V_122 ;
V_138 -> V_140 -> V_236 . V_235 . V_280 =
sizeof( struct V_26 ) ;
F_22 ( & V_138 -> V_140 -> V_236 . V_235 . V_74 ) ;
F_115 ( & V_138 -> V_140 -> V_236 . V_235 . V_234 . V_109 ,
& V_138 -> V_140 -> V_236 . V_235 . V_74 ) ;
V_138 -> V_140 -> V_236 . V_235 . V_234 . V_265 = NULL ;
V_138 -> V_140 -> V_236 . V_235 . V_234 . V_27 =
& V_138 -> V_140 -> V_27 . V_27 ;
if ( F_121 ( & V_141 -> V_59 -> V_100 ) )
F_57 ( V_141 -> V_59 ,
& V_138 -> V_140 -> V_236 . V_235 ,
V_90 ) ;
V_141 -> V_64 . V_37 (
& V_141 -> V_64 ,
& V_138 -> V_140 -> V_236 . V_235 ) ;
F_4 ( & V_141 -> V_70 , V_6 ) ;
F_51 ( & V_141 -> V_80 ) ;
F_5 ( & V_141 -> V_70 , V_6 ) ;
}
V_313:
V_114 . V_123 = V_124 ;
V_114 . V_270 = 0 ;
V_114 . V_112 = & V_138 -> V_134 -> V_112 ;
if ( F_121 ( & V_43 -> V_59 -> V_100 ) )
F_56 ( V_43 -> V_59 ,
& V_138 -> V_134 -> V_112 ,
& V_114 , V_89 ) ;
V_43 -> V_64 . V_36 ( & V_43 -> V_64 ,
& V_114 ) ;
F_4 ( & V_43 -> V_70 , V_6 ) ;
F_51 ( & V_43 -> V_80 ) ;
if ( V_312 )
F_68 ( V_153 , V_138 -> V_140 ) ;
F_30 ( V_138 ) ;
}
F_5 ( & V_43 -> V_70 , V_6 ) ;
}
static int F_147 ( struct V_133 * V_134 )
{
int V_40 ;
if ( ! V_134 -> V_225 )
return - V_314 ;
V_134 -> V_225 -- ;
V_134 -> V_112 . V_224 ++ ;
V_134 -> V_222 = F_87 ( V_134 -> V_112 . V_218 ) ;
if ( V_134 -> V_43 -> V_64 . V_35 ) {
V_40 = F_148 ( V_134 ) ;
switch ( V_40 ) {
case V_291 :
V_40 = F_82 ( V_134 ) ;
break;
case V_226 :
V_40 = 0 ;
break;
default:
V_40 = - V_315 ;
break;
}
} else
V_40 = F_82 ( V_134 ) ;
if ( ! V_40 ) {
V_134 -> V_80 ++ ;
F_29 ( & V_134 -> V_87 ,
& V_134 -> V_43 -> V_71 ) ;
}
return V_40 ;
}
static void V_76 ( struct V_305 * V_306 )
{
struct V_42 * V_43 ;
struct V_133 * V_134 ;
struct V_113 V_114 ;
unsigned long V_6 , V_286 ;
V_43 = F_53 ( V_306 , struct V_42 ,
V_75 . V_306 ) ;
V_114 . V_270 = 0 ;
F_4 ( & V_43 -> V_70 , V_6 ) ;
while ( ! F_128 ( & V_43 -> V_72 ) ) {
V_134 = F_129 ( V_43 -> V_72 . V_180 ,
struct V_133 ,
V_87 ) ;
if ( F_130 ( V_134 -> V_222 , V_287 ) ) {
V_286 = V_134 -> V_222 - V_287 ;
if ( ( long ) V_286 <= 0 )
V_286 = 1 ;
F_149 ( V_43 -> V_59 ->
V_39 -> V_103 ,
& V_43 -> V_75 , V_286 ) ;
break;
}
F_46 ( & V_134 -> V_87 ) ;
if ( V_134 -> V_123 == V_124 &&
! F_147 ( V_134 ) )
continue;
F_5 ( & V_43 -> V_70 , V_6 ) ;
if ( V_134 -> V_123 == V_124 )
V_114 . V_123 = V_316 ;
else
V_114 . V_123 = V_134 -> V_123 ;
V_114 . V_112 = & V_134 -> V_112 ;
V_43 -> V_64 . V_36 ( & V_43 -> V_64 ,
& V_114 ) ;
F_51 ( & V_43 -> V_80 ) ;
F_4 ( & V_43 -> V_70 , V_6 ) ;
}
F_5 ( & V_43 -> V_70 , V_6 ) ;
}
static void F_150 ( struct V_317 * V_307 , void * V_318 )
{
struct V_1 * V_39 = V_307 -> V_319 ;
unsigned long V_6 ;
F_4 ( & V_7 , V_6 ) ;
if ( ! F_128 ( & V_39 -> V_320 ) )
F_70 ( V_39 -> V_103 , & V_39 -> V_306 ) ;
F_5 ( & V_7 , V_6 ) ;
}
static int F_126 ( struct V_91 * V_59 ,
struct V_139 * V_27 )
{
unsigned long V_6 ;
int V_321 , V_40 ;
struct V_139 * V_140 ;
struct V_207 V_187 ;
struct V_322 V_323 , * V_324 ;
struct V_107 * V_296 = & V_59 -> V_296 ;
V_187 . V_188 = sizeof *V_140 - sizeof V_140 -> V_236 ;
V_187 . V_189 = ( * V_59 -> V_39 -> V_65 ) . V_189 ;
V_323 . V_180 = NULL ;
V_323 . V_187 = & V_187 ;
V_323 . V_190 = 1 ;
do {
if ( V_27 ) {
V_140 = V_27 ;
V_27 = NULL ;
} else {
V_140 = F_66 ( V_153 , V_62 ) ;
if ( ! V_140 ) {
F_62 (KERN_ERR PFX L_24 ) ;
V_40 = - V_63 ;
break;
}
}
V_187 . V_210 = F_83 ( V_59 -> V_39 -> V_3 ,
& V_140 -> V_265 ,
sizeof *V_140 -
sizeof V_140 -> V_236 ,
V_279 ) ;
V_140 -> V_236 . V_278 = V_187 . V_210 ;
V_323 . V_118 = ( unsigned long ) & V_140 -> V_236 . V_106 ;
V_140 -> V_236 . V_106 . V_108 = V_296 ;
F_4 ( & V_296 -> V_70 , V_6 ) ;
V_321 = ( ++ V_296 -> V_110 < V_296 -> V_214 ) ;
F_29 ( & V_140 -> V_236 . V_106 . V_109 , & V_296 -> V_109 ) ;
F_5 ( & V_296 -> V_70 , V_6 ) ;
V_40 = F_151 ( V_59 -> V_60 , & V_323 , & V_324 ) ;
if ( V_40 ) {
F_4 ( & V_296 -> V_70 , V_6 ) ;
F_46 ( & V_140 -> V_236 . V_106 . V_109 ) ;
V_296 -> V_110 -- ;
F_5 ( & V_296 -> V_70 , V_6 ) ;
F_85 ( V_59 -> V_39 -> V_3 ,
V_140 -> V_236 . V_278 ,
sizeof *V_140 -
sizeof V_140 -> V_236 ,
V_279 ) ;
F_68 ( V_153 , V_140 ) ;
F_62 (KERN_ERR PFX L_25 , ret) ;
break;
}
} while ( V_321 );
return V_40 ;
}
static void F_152 ( struct V_91 * V_59 )
{
struct V_230 * V_231 ;
struct V_139 * V_271 ;
struct V_105 * V_106 ;
if ( ! V_59 -> V_60 )
return;
while ( ! F_128 ( & V_59 -> V_296 . V_109 ) ) {
V_106 = F_129 ( V_59 -> V_296 . V_109 . V_180 ,
struct V_105 , V_109 ) ;
V_231 = F_53 ( V_106 ,
struct V_230 ,
V_106 ) ;
V_271 = F_53 ( V_231 , struct V_139 ,
V_236 ) ;
F_46 ( & V_106 -> V_109 ) ;
F_85 ( V_59 -> V_39 -> V_3 ,
V_271 -> V_236 . V_278 ,
sizeof( struct V_139 ) -
sizeof( struct V_230 ) ,
V_279 ) ;
F_68 ( V_153 , V_271 ) ;
}
V_59 -> V_296 . V_110 = 0 ;
}
static int F_153 ( struct V_1 * V_39 )
{
int V_40 , V_23 ;
struct V_298 * V_254 ;
struct V_117 * V_60 ;
T_6 V_120 ;
V_254 = F_65 ( sizeof *V_254 , V_62 ) ;
if ( ! V_254 ) {
F_62 (KERN_ERR PFX L_26 ) ;
return - V_63 ;
}
V_40 = F_154 ( V_39 -> V_3 , V_39 -> V_4 ,
V_325 , & V_120 ) ;
if ( V_40 )
V_120 = 0 ;
for ( V_23 = 0 ; V_23 < V_326 ; V_23 ++ ) {
V_60 = V_39 -> V_59 [ V_23 ] . V_60 ;
if ( ! V_60 )
continue;
V_254 -> V_299 = V_327 ;
V_254 -> V_120 = V_120 ;
V_254 -> V_328 = ( V_60 -> V_248 == 0 ) ? 0 : V_329 ;
V_40 = F_140 ( V_60 , V_254 , V_303 |
V_330 | V_331 ) ;
if ( V_40 ) {
F_62 (KERN_ERR PFX L_27
L_28 , i, ret) ;
goto V_99;
}
V_254 -> V_299 = V_332 ;
V_40 = F_140 ( V_60 , V_254 , V_303 ) ;
if ( V_40 ) {
F_62 (KERN_ERR PFX L_27
L_29 , i, ret) ;
goto V_99;
}
V_254 -> V_299 = V_300 ;
V_254 -> V_333 = V_334 ;
V_40 = F_140 ( V_60 , V_254 , V_303 | V_335 ) ;
if ( V_40 ) {
F_62 (KERN_ERR PFX L_27
L_30 , i, ret) ;
goto V_99;
}
}
V_40 = F_142 ( V_39 -> V_307 , V_308 ) ;
if ( V_40 ) {
F_62 (KERN_ERR PFX L_31
L_32 , ret) ;
goto V_99;
}
for ( V_23 = 0 ; V_23 < V_326 ; V_23 ++ ) {
if ( ! V_39 -> V_59 [ V_23 ] . V_60 )
continue;
V_40 = F_126 ( & V_39 -> V_59 [ V_23 ] , NULL ) ;
if ( V_40 ) {
F_62 (KERN_ERR PFX L_33 ) ;
goto V_99;
}
}
V_99:
F_30 ( V_254 ) ;
return V_40 ;
}
static void F_155 ( struct V_336 * V_337 , void * V_338 )
{
struct V_91 * V_59 = V_338 ;
F_62 (KERN_ERR PFX L_34 ,
event->event, qp_info->qp->qp_num) ;
}
static void F_156 ( struct V_91 * V_59 ,
struct V_107 * V_108 )
{
V_108 -> V_59 = V_59 ;
V_108 -> V_110 = 0 ;
F_21 ( & V_108 -> V_70 ) ;
F_22 ( & V_108 -> V_109 ) ;
}
static void F_157 ( struct V_1 * V_39 ,
struct V_91 * V_59 )
{
V_59 -> V_39 = V_39 ;
F_156 ( V_59 , & V_59 -> V_209 ) ;
F_156 ( V_59 , & V_59 -> V_296 ) ;
F_22 ( & V_59 -> V_215 ) ;
F_21 ( & V_59 -> V_95 ) ;
V_59 -> V_97 = NULL ;
V_59 -> V_96 = 0 ;
F_25 ( & V_59 -> V_100 , 0 ) ;
}
static int F_158 ( struct V_91 * V_59 ,
enum V_10 V_11 )
{
struct V_339 V_340 ;
int V_40 ;
memset ( & V_340 , 0 , sizeof V_340 ) ;
V_340 . V_341 = V_59 -> V_39 -> V_307 ;
V_340 . V_342 = V_59 -> V_39 -> V_307 ;
V_340 . V_343 = V_344 ;
V_340 . V_345 . V_346 = V_347 ;
V_340 . V_345 . V_348 = V_349 ;
V_340 . V_345 . V_350 = V_351 ;
V_340 . V_345 . V_352 = V_353 ;
V_340 . V_11 = V_11 ;
V_340 . V_4 = V_59 -> V_39 -> V_4 ;
V_340 . V_338 = V_59 ;
V_340 . V_354 = F_155 ;
V_59 -> V_60 = F_159 ( V_59 -> V_39 -> V_66 , & V_340 ) ;
if ( F_19 ( V_59 -> V_60 ) ) {
F_62 (KERN_ERR PFX L_35 ,
get_spl_qp_index(qp_type)) ;
V_40 = F_160 ( V_59 -> V_60 ) ;
goto error;
}
V_59 -> V_209 . V_214 = V_347 ;
V_59 -> V_296 . V_214 = V_349 ;
return 0 ;
error:
return V_40 ;
}
static void F_161 ( struct V_91 * V_59 )
{
if ( ! V_59 -> V_60 )
return;
F_162 ( V_59 -> V_60 ) ;
F_30 ( V_59 -> V_97 ) ;
}
static int F_163 ( struct V_2 * V_3 ,
int V_4 )
{
int V_40 , V_355 ;
struct V_1 * V_39 ;
unsigned long V_6 ;
char V_356 [ sizeof "ib_mad123"];
int V_357 ;
V_39 = F_17 ( sizeof *V_39 , V_62 ) ;
if ( ! V_39 ) {
F_62 (KERN_ERR PFX L_36 ) ;
return - V_63 ;
}
V_39 -> V_3 = V_3 ;
V_39 -> V_4 = V_4 ;
F_21 ( & V_39 -> V_82 ) ;
F_22 ( & V_39 -> V_87 ) ;
F_157 ( V_39 , & V_39 -> V_59 [ 0 ] ) ;
F_157 ( V_39 , & V_39 -> V_59 [ 1 ] ) ;
V_355 = V_347 + V_349 ;
V_357 = F_164 ( V_3 , V_4 ) == V_358 ;
if ( V_357 )
V_355 *= 2 ;
V_39 -> V_307 = F_165 ( V_39 -> V_3 ,
F_150 ,
NULL , V_39 , V_355 , 0 ) ;
if ( F_19 ( V_39 -> V_307 ) ) {
F_62 (KERN_ERR PFX L_37 ) ;
V_40 = F_160 ( V_39 -> V_307 ) ;
goto V_69;
}
V_39 -> V_66 = F_166 ( V_3 ) ;
if ( F_19 ( V_39 -> V_66 ) ) {
F_62 (KERN_ERR PFX L_38 ) ;
V_40 = F_160 ( V_39 -> V_66 ) ;
goto V_86;
}
V_39 -> V_65 = F_18 ( V_39 -> V_66 , V_67 ) ;
if ( F_19 ( V_39 -> V_65 ) ) {
F_62 (KERN_ERR PFX L_39 ) ;
V_40 = F_160 ( V_39 -> V_65 ) ;
goto V_359;
}
if ( V_357 ) {
V_40 = F_158 ( & V_39 -> V_59 [ 0 ] , V_12 ) ;
if ( V_40 )
goto V_360;
}
V_40 = F_158 ( & V_39 -> V_59 [ 1 ] , V_13 ) ;
if ( V_40 )
goto V_361;
snprintf ( V_356 , sizeof V_356 , L_40 , V_4 ) ;
V_39 -> V_103 = F_167 ( V_356 ) ;
if ( ! V_39 -> V_103 ) {
V_40 = - V_63 ;
goto V_362;
}
F_24 ( & V_39 -> V_306 , F_141 ) ;
F_4 ( & V_7 , V_6 ) ;
F_29 ( & V_39 -> V_320 , & V_363 ) ;
F_5 ( & V_7 , V_6 ) ;
V_40 = F_153 ( V_39 ) ;
if ( V_40 ) {
F_62 (KERN_ERR PFX L_41 ) ;
goto V_364;
}
return 0 ;
V_364:
F_4 ( & V_7 , V_6 ) ;
F_168 ( & V_39 -> V_320 ) ;
F_5 ( & V_7 , V_6 ) ;
F_169 ( V_39 -> V_103 ) ;
V_362:
F_161 ( & V_39 -> V_59 [ 1 ] ) ;
V_361:
F_161 ( & V_39 -> V_59 [ 0 ] ) ;
V_360:
F_31 ( V_39 -> V_65 ) ;
V_359:
F_170 ( V_39 -> V_66 ) ;
V_86:
F_171 ( V_39 -> V_307 ) ;
F_152 ( & V_39 -> V_59 [ 1 ] ) ;
F_152 ( & V_39 -> V_59 [ 0 ] ) ;
V_69:
F_30 ( V_39 ) ;
return V_40 ;
}
static int F_172 ( struct V_2 * V_3 , int V_4 )
{
struct V_1 * V_39 ;
unsigned long V_6 ;
F_4 ( & V_7 , V_6 ) ;
V_39 = F_1 ( V_3 , V_4 ) ;
if ( V_39 == NULL ) {
F_5 ( & V_7 , V_6 ) ;
F_62 (KERN_ERR PFX L_42 , port_num) ;
return - V_58 ;
}
F_168 ( & V_39 -> V_320 ) ;
F_5 ( & V_7 , V_6 ) ;
F_169 ( V_39 -> V_103 ) ;
F_161 ( & V_39 -> V_59 [ 1 ] ) ;
F_161 ( & V_39 -> V_59 [ 0 ] ) ;
F_31 ( V_39 -> V_65 ) ;
F_170 ( V_39 -> V_66 ) ;
F_171 ( V_39 -> V_307 ) ;
F_152 ( & V_39 -> V_59 [ 1 ] ) ;
F_152 ( & V_39 -> V_59 [ 0 ] ) ;
F_30 ( V_39 ) ;
return 0 ;
}
static void F_173 ( struct V_2 * V_3 )
{
int V_365 , V_366 , V_23 ;
if ( F_174 ( V_3 -> V_145 ) != V_367 )
return;
if ( V_3 -> V_145 == V_146 ) {
V_365 = 0 ;
V_366 = 0 ;
} else {
V_365 = 1 ;
V_366 = V_3 -> V_283 ;
}
for ( V_23 = V_365 ; V_23 <= V_366 ; V_23 ++ ) {
if ( F_163 ( V_3 , V_23 ) ) {
F_62 (KERN_ERR PFX L_43 ,
device->name, i) ;
goto error;
}
if ( F_175 ( V_3 , V_23 ) ) {
F_62 (KERN_ERR PFX L_44
L_45 ,
device->name, i) ;
goto V_368;
}
}
return;
V_368:
if ( F_172 ( V_3 , V_23 ) )
F_62 (KERN_ERR PFX L_46 ,
device->name, i) ;
error:
V_23 -- ;
while ( V_23 >= V_365 ) {
if ( F_176 ( V_3 , V_23 ) )
F_62 (KERN_ERR PFX L_47
L_45 ,
device->name, i) ;
if ( F_172 ( V_3 , V_23 ) )
F_62 (KERN_ERR PFX L_46 ,
device->name, i) ;
V_23 -- ;
}
}
static void F_177 ( struct V_2 * V_3 )
{
int V_23 , V_369 , V_370 ;
if ( F_174 ( V_3 -> V_145 ) != V_367 )
return;
if ( V_3 -> V_145 == V_146 ) {
V_369 = 1 ;
V_370 = 0 ;
} else {
V_369 = V_3 -> V_283 ;
V_370 = 1 ;
}
for ( V_23 = 0 ; V_23 < V_369 ; V_23 ++ , V_370 ++ ) {
if ( F_176 ( V_3 , V_370 ) )
F_62 (KERN_ERR PFX L_47
L_45 ,
device->name, cur_port) ;
if ( F_172 ( V_3 , V_370 ) )
F_62 (KERN_ERR PFX L_46 ,
device->name, cur_port) ;
}
}
static int T_9 F_178 ( void )
{
int V_40 ;
V_349 = F_179 ( V_349 , V_371 ) ;
V_349 = F_180 ( V_349 , V_372 ) ;
V_347 = F_179 ( V_347 , V_371 ) ;
V_347 = F_180 ( V_347 , V_372 ) ;
V_153 = F_181 ( L_48 ,
sizeof( struct V_139 ) ,
0 ,
V_373 ,
NULL ) ;
if ( ! V_153 ) {
F_62 (KERN_ERR PFX L_49 ) ;
V_40 = - V_63 ;
goto V_52;
}
F_22 ( & V_363 ) ;
if ( F_182 ( & V_374 ) ) {
F_62 (KERN_ERR PFX L_50 ) ;
V_40 = - V_41 ;
goto V_68;
}
return 0 ;
V_68:
F_183 ( V_153 ) ;
V_52:
return V_40 ;
}
static void T_10 F_184 ( void )
{
F_185 ( & V_374 ) ;
F_183 ( V_153 ) ;
}
