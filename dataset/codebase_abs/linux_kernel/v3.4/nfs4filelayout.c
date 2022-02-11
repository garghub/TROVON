static T_1
F_1 ( struct V_1 * V_2 ,
T_1 V_3 )
{
T_2 V_4 = V_2 -> V_5 * V_2 -> V_6 -> V_7 ;
T_3 V_8 ;
T_2 V_9 ;
V_3 -= V_2 -> V_10 ;
V_8 = F_2 ( V_3 , V_4 ) ;
F_3 ( V_3 , V_2 -> V_5 , & V_9 ) ;
return V_8 * V_2 -> V_5 + V_9 ;
}
static T_1
F_4 ( struct V_11 * V_12 , T_1 V_3 )
{
struct V_1 * V_2 = F_5 ( V_12 ) ;
switch ( V_2 -> V_13 ) {
case V_14 :
return V_3 ;
case V_15 :
return F_1 ( V_2 , V_3 ) ;
}
F_6 () ;
}
static int F_7 ( struct V_16 * V_17 ,
struct V_18 * V_19 ,
struct V_20 * V_21 ,
int * V_22 )
{
struct V_23 * V_24 = F_8 ( V_19 -> V_25 ) ;
struct V_20 * V_26 = V_24 -> V_20 ;
if ( V_17 -> V_27 >= 0 )
return 0 ;
* V_22 = 0 ;
switch ( V_17 -> V_27 ) {
case - V_28 :
case - V_29 :
case - V_30 :
F_9 ( V_19 -> V_25 ) ;
case - V_31 :
F_10 ( V_24 , V_19 ) ;
goto V_32;
case - V_33 :
F_10 ( V_24 , V_19 ) ;
F_11 ( V_26 ) ;
goto V_32;
case - V_34 :
case - V_35 :
case - V_36 :
case - V_37 :
case - V_38 :
case - V_39 :
case - V_40 :
F_12 ( L_1
L_2 , V_41 , V_17 -> V_27 ,
V_21 -> V_42 ) ;
F_13 ( V_21 -> V_43 ) ;
break;
case - V_44 :
case - V_45 :
case - V_46 :
F_14 ( V_17 , V_47 ) ;
break;
case - V_48 :
break;
default:
F_12 ( L_3 , V_41 ,
V_17 -> V_27 ) ;
* V_22 = 1 ;
break;
}
V_49:
V_17 -> V_27 = 0 ;
return - V_50 ;
V_32:
F_15 ( & V_26 -> V_51 , V_17 , NULL ) ;
if ( F_16 ( V_52 , & V_26 -> V_53 ) == 0 )
F_17 ( & V_26 -> V_51 , V_17 ) ;
goto V_49;
}
static int F_18 ( struct V_16 * V_17 ,
struct V_54 * V_55 )
{
int V_22 = 0 ;
F_12 ( L_4 , V_41 ) ;
if ( F_7 ( V_17 , V_55 -> args . V_56 -> V_19 ,
V_55 -> V_57 , & V_22 ) == - V_50 ) {
F_12 ( L_5 ,
V_41 , V_55 -> V_57 , V_55 -> V_57 -> V_43 ) ;
if ( V_22 ) {
F_19 ( V_55 -> V_12 ) ;
F_20 ( V_17 , V_55 ) ;
}
F_21 ( V_17 ) ;
return - V_50 ;
}
return 0 ;
}
static void
F_22 ( struct V_58 * V_59 )
{
if ( F_5 ( V_59 -> V_12 ) -> V_60 ||
V_59 -> V_61 . V_62 -> V_63 == V_64 )
return;
F_23 ( V_59 ) ;
F_12 ( L_6 , V_41 , V_59 -> V_25 -> V_65 ,
( unsigned long ) F_24 ( V_59 -> V_25 ) -> V_66 -> V_67 ) ;
}
static void F_25 ( struct V_16 * V_17 , void * V_55 )
{
struct V_54 * V_68 = (struct V_54 * ) V_55 ;
V_68 -> V_69 = F_18 ;
if ( F_26 ( V_68 -> V_57 -> V_43 ,
& V_68 -> args . V_70 , & V_68 -> V_61 . V_71 ,
V_17 ) )
return;
F_27 ( V_17 ) ;
}
static void F_28 ( struct V_16 * V_17 , void * V_55 )
{
struct V_54 * V_68 = (struct V_54 * ) V_55 ;
F_12 ( L_7 , V_41 , V_17 -> V_27 ) ;
V_68 -> V_72 -> V_73 ( V_17 , V_55 ) ;
}
static void F_29 ( struct V_16 * V_17 , void * V_55 )
{
struct V_54 * V_68 = (struct V_54 * ) V_55 ;
F_30 ( V_17 , F_8 ( V_68 -> V_25 ) -> V_74 -> V_75 ) ;
}
static void F_31 ( void * V_55 )
{
struct V_54 * V_68 = (struct V_54 * ) V_55 ;
F_32 ( V_68 -> V_12 ) ;
V_68 -> V_72 -> V_76 ( V_55 ) ;
}
static int F_33 ( struct V_16 * V_17 ,
struct V_58 * V_55 )
{
int V_22 = 0 ;
if ( F_7 ( V_17 , V_55 -> args . V_56 -> V_19 ,
V_55 -> V_57 , & V_22 ) == - V_50 ) {
F_12 ( L_5 ,
V_41 , V_55 -> V_57 , V_55 -> V_57 -> V_43 ) ;
if ( V_22 ) {
F_19 ( V_55 -> V_12 ) ;
F_34 ( V_17 , V_55 ) ;
}
F_21 ( V_17 ) ;
return - V_50 ;
}
F_22 ( V_55 ) ;
return 0 ;
}
static void F_35 ( struct V_58 * V_55 )
{
struct V_77 * V_78 = F_36 ( V_55 -> V_79 . V_80 ) ;
V_55 -> V_17 . V_27 = 0 ;
memcpy ( V_55 -> V_62 . V_81 , V_78 -> V_82 . V_81 ,
sizeof( V_78 -> V_82 . V_81 ) ) ;
V_55 -> V_62 . V_81 [ 0 ] ++ ;
}
static int F_37 ( struct V_16 * V_17 ,
struct V_58 * V_55 )
{
int V_22 = 0 ;
if ( F_7 ( V_17 , V_55 -> args . V_56 -> V_19 ,
V_55 -> V_57 , & V_22 ) == - V_50 ) {
F_12 ( L_5 ,
V_41 , V_55 -> V_57 , V_55 -> V_57 -> V_43 ) ;
if ( V_22 ) {
F_35 ( V_55 ) ;
F_19 ( V_55 -> V_12 ) ;
} else
F_21 ( V_17 ) ;
return - V_50 ;
}
return 0 ;
}
static void F_38 ( struct V_16 * V_17 , void * V_55 )
{
struct V_58 * V_59 = (struct V_58 * ) V_55 ;
if ( F_26 ( V_59 -> V_57 -> V_43 ,
& V_59 -> args . V_70 , & V_59 -> V_61 . V_71 ,
V_17 ) )
return;
F_27 ( V_17 ) ;
}
static void F_39 ( struct V_16 * V_17 , void * V_55 )
{
struct V_58 * V_59 = (struct V_58 * ) V_55 ;
V_59 -> V_72 -> V_73 ( V_17 , V_55 ) ;
}
static void F_40 ( struct V_16 * V_17 , void * V_55 )
{
struct V_58 * V_59 = (struct V_58 * ) V_55 ;
F_30 ( V_17 , F_8 ( V_59 -> V_25 ) -> V_74 -> V_75 ) ;
}
static void F_41 ( void * V_55 )
{
struct V_58 * V_59 = (struct V_58 * ) V_55 ;
F_32 ( V_59 -> V_12 ) ;
V_59 -> V_72 -> V_76 ( V_55 ) ;
}
static void F_42 ( void * V_55 )
{
struct V_58 * V_59 = (struct V_58 * ) V_55 ;
F_43 ( V_59 ) ;
if ( F_44 ( & F_24 ( V_59 -> V_25 ) -> V_83 ) )
F_45 ( F_24 ( V_59 -> V_25 ) ) ;
F_32 ( V_59 -> V_12 ) ;
F_46 ( V_59 ) ;
}
static enum V_84
F_47 ( struct V_54 * V_55 )
{
struct V_11 * V_12 = V_55 -> V_12 ;
struct V_85 * V_86 ;
T_1 V_3 = V_55 -> args . V_3 ;
T_2 V_87 , V_88 ;
struct V_89 * V_90 ;
int V_91 ;
F_12 ( L_8 ,
V_41 , V_55 -> V_25 -> V_65 ,
V_55 -> args . V_92 , ( V_93 ) V_55 -> args . V_94 , V_3 ) ;
if ( F_16 ( V_95 , & F_48 ( V_12 ) -> V_96 ) )
return V_97 ;
V_87 = F_49 ( V_12 , V_3 ) ;
V_88 = F_50 ( V_12 , V_87 ) ;
V_86 = F_51 ( V_12 , V_88 ) ;
if ( ! V_86 ) {
F_52 ( F_53 ( V_98 ) , & V_12 -> V_99 -> V_100 ) ;
F_52 ( F_53 ( V_101 ) , & V_12 -> V_99 -> V_100 ) ;
return V_97 ;
}
F_12 ( L_9 , V_41 , V_86 -> V_102 ) ;
V_55 -> V_57 = V_86 -> V_57 ;
V_90 = F_54 ( V_12 , V_87 ) ;
if ( V_90 )
V_55 -> args . V_90 = V_90 ;
V_55 -> args . V_3 = F_4 ( V_12 , V_3 ) ;
V_55 -> V_103 = V_3 ;
V_91 = F_55 ( V_55 , V_86 -> V_57 -> V_104 ,
& V_105 ) ;
F_56 ( V_91 != 0 ) ;
return V_106 ;
}
static enum V_84
F_57 ( struct V_58 * V_55 , int V_107 )
{
struct V_11 * V_12 = V_55 -> V_12 ;
struct V_85 * V_86 ;
T_1 V_3 = V_55 -> args . V_3 ;
T_2 V_87 , V_88 ;
struct V_89 * V_90 ;
int V_91 ;
if ( F_16 ( V_95 , & F_48 ( V_12 ) -> V_96 ) )
return V_97 ;
V_87 = F_49 ( V_12 , V_3 ) ;
V_88 = F_50 ( V_12 , V_87 ) ;
V_86 = F_51 ( V_12 , V_88 ) ;
if ( ! V_86 ) {
F_58 ( V_108 L_10 ,
V_41 ) ;
F_52 ( F_53 ( V_98 ) , & V_12 -> V_99 -> V_100 ) ;
F_52 ( F_53 ( V_101 ) , & V_12 -> V_99 -> V_100 ) ;
return V_97 ;
}
F_12 ( L_11 , V_41 ,
V_55 -> V_25 -> V_65 , V_107 , ( V_93 ) V_55 -> args . V_94 , V_3 ,
V_86 -> V_102 ) ;
V_55 -> V_109 = F_33 ;
V_55 -> V_57 = V_86 -> V_57 ;
V_90 = F_54 ( V_12 , V_87 ) ;
if ( V_90 )
V_55 -> args . V_90 = V_90 ;
V_55 -> args . V_3 = F_4 ( V_12 , V_3 ) ;
V_91 = F_59 ( V_55 , V_86 -> V_57 -> V_104 ,
& V_110 , V_107 ) ;
F_56 ( V_91 != 0 ) ;
return V_106 ;
}
static int
F_60 ( struct V_111 * V_112 ,
struct V_1 * V_113 ,
struct V_114 * V_115 ,
struct V_116 * V_117 ,
T_4 V_118 )
{
struct V_119 * V_120 ;
struct V_121 * V_6 ;
int V_91 = - V_122 ;
struct V_23 * V_123 = F_8 ( V_112 -> V_124 ) ;
F_12 ( L_12 , V_41 ) ;
if ( V_115 -> V_125 . V_3 != 0 ||
V_115 -> V_125 . V_126 != V_127 ) {
F_12 ( L_13 ,
V_41 ) ;
goto V_49;
}
if ( V_113 -> V_10 > V_115 -> V_125 . V_3 ) {
F_12 ( L_14 ,
V_41 , V_113 -> V_10 ) ;
goto V_49;
}
if ( ! V_113 -> V_5 || V_113 -> V_5 % V_128 ) {
F_12 ( L_15 ,
V_41 , V_113 -> V_5 ) ;
goto V_49;
}
V_120 = F_61 ( F_8 ( V_112 -> V_124 ) -> V_129 ,
F_8 ( V_112 -> V_124 ) -> V_20 , V_117 ) ;
if ( V_120 == NULL ) {
V_6 = F_62 ( V_112 -> V_124 , V_117 , V_118 ) ;
if ( V_6 == NULL )
goto V_49;
} else
V_6 = F_63 ( V_120 , struct V_121 , V_130 ) ;
if ( F_16 ( V_95 , & V_6 -> V_130 . V_96 ) )
goto V_131;
V_113 -> V_6 = V_6 ;
if ( V_113 -> V_132 >= V_6 -> V_7 ) {
F_12 ( L_16 ,
V_41 , V_113 -> V_132 ) ;
goto V_131;
}
if ( ( V_113 -> V_13 == V_14 &&
V_113 -> V_133 > 1 && V_113 -> V_133 != V_6 -> V_134 ) ||
( V_113 -> V_13 == V_15 &&
V_113 -> V_133 != V_6 -> V_7 ) ) {
F_12 ( L_17 ,
V_41 , V_113 -> V_133 ) ;
goto V_131;
}
if ( V_113 -> V_5 % V_123 -> V_135 || V_113 -> V_5 % V_123 -> V_136 ) {
F_12 ( L_18
L_19 , V_41 , V_113 -> V_5 , V_123 -> V_135 ,
V_123 -> V_136 ) ;
}
V_91 = 0 ;
V_49:
F_12 ( L_20 , V_41 , V_91 ) ;
return V_91 ;
V_131:
F_64 ( V_6 ) ;
goto V_49;
}
static void F_65 ( struct V_1 * V_113 )
{
int V_137 ;
for ( V_137 = 0 ; V_137 < V_113 -> V_133 ; V_137 ++ ) {
if ( ! V_113 -> V_138 [ V_137 ] )
break;
F_66 ( V_113 -> V_138 [ V_137 ] ) ;
}
F_66 ( V_113 -> V_138 ) ;
V_113 -> V_138 = NULL ;
}
static void
F_67 ( struct V_1 * V_113 )
{
F_65 ( V_113 ) ;
F_66 ( V_113 ) ;
}
static int
F_68 ( struct V_111 * V_139 ,
struct V_1 * V_113 ,
struct V_114 * V_115 ,
struct V_116 * V_117 ,
T_4 V_118 )
{
struct V_140 V_141 ;
struct V_142 V_143 ;
struct V_144 * V_145 ;
T_5 * V_146 ;
T_6 V_147 ;
int V_137 ;
F_12 ( L_21 , V_41 ) ;
V_145 = F_69 ( V_118 ) ;
if ( ! V_145 )
return - V_148 ;
F_70 ( & V_141 , & V_143 , V_115 -> V_149 -> V_79 , V_115 -> V_149 -> V_150 ) ;
F_71 ( & V_141 , F_72 ( V_145 ) , V_128 ) ;
V_146 = F_73 ( & V_141 , V_151 + 20 ) ;
if ( F_74 ( ! V_146 ) )
goto V_152;
memcpy ( V_117 , V_146 , sizeof( * V_117 ) ) ;
V_146 += F_75 ( V_151 ) ;
F_76 ( V_117 ) ;
V_147 = F_77 ( V_146 ++ ) ;
if ( V_147 & V_153 )
V_113 -> V_60 = 1 ;
if ( V_147 & V_154 )
V_113 -> V_13 = V_15 ;
else
V_113 -> V_13 = V_14 ;
V_113 -> V_5 = V_147 & ~ V_155 ;
V_113 -> V_132 = F_77 ( V_146 ++ ) ;
V_146 = F_78 ( V_146 , & V_113 -> V_10 ) ;
V_113 -> V_133 = F_77 ( V_146 ++ ) ;
F_12 ( L_22 ,
V_41 , V_147 , V_113 -> V_133 , V_113 -> V_132 ,
V_113 -> V_10 ) ;
if ( V_113 -> V_133 >
F_79 ( V_156 , V_157 ) )
goto V_152;
if ( V_113 -> V_133 > 0 ) {
V_113 -> V_138 = F_80 ( V_113 -> V_133 * sizeof( struct V_89 * ) ,
V_118 ) ;
if ( ! V_113 -> V_138 )
goto V_152;
}
for ( V_137 = 0 ; V_137 < V_113 -> V_133 ; V_137 ++ ) {
V_113 -> V_138 [ V_137 ] = F_81 ( sizeof( struct V_89 ) , V_118 ) ;
if ( ! V_113 -> V_138 [ V_137 ] )
goto V_158;
V_146 = F_73 ( & V_141 , 4 ) ;
if ( F_74 ( ! V_146 ) )
goto V_158;
V_113 -> V_138 [ V_137 ] -> V_159 = F_77 ( V_146 ++ ) ;
if ( sizeof( struct V_89 ) < V_113 -> V_138 [ V_137 ] -> V_159 ) {
F_58 ( V_108 L_23 ,
V_137 , V_113 -> V_138 [ V_137 ] -> V_159 ) ;
goto V_158;
}
V_146 = F_73 ( & V_141 , V_113 -> V_138 [ V_137 ] -> V_159 ) ;
if ( F_74 ( ! V_146 ) )
goto V_158;
memcpy ( V_113 -> V_138 [ V_137 ] -> V_55 , V_146 , V_113 -> V_138 [ V_137 ] -> V_159 ) ;
F_12 ( L_24 , V_41 ,
V_113 -> V_138 [ V_137 ] -> V_159 ) ;
}
F_82 ( V_145 ) ;
return 0 ;
V_158:
F_65 ( V_113 ) ;
V_152:
F_82 ( V_145 ) ;
return - V_160 ;
}
static void
F_83 ( struct V_11 * V_12 )
{
struct V_1 * V_113 = F_5 ( V_12 ) ;
F_12 ( L_12 , V_41 ) ;
F_64 ( V_113 -> V_6 ) ;
F_66 ( V_113 -> V_161 ) ;
F_67 ( V_113 ) ;
}
static struct V_11 *
F_84 ( struct V_111 * V_162 ,
struct V_114 * V_115 ,
T_4 V_118 )
{
struct V_1 * V_113 ;
int V_163 ;
struct V_116 V_117 ;
F_12 ( L_12 , V_41 ) ;
V_113 = F_80 ( sizeof( * V_113 ) , V_118 ) ;
if ( ! V_113 )
return NULL ;
V_163 = F_68 ( V_162 , V_113 , V_115 , & V_117 , V_118 ) ;
if ( V_163 != 0 || F_60 ( V_162 , V_113 , V_115 , & V_117 , V_118 ) ) {
F_67 ( V_113 ) ;
return NULL ;
}
if ( ( ! V_113 -> V_60 ) && ( V_115 -> V_125 . V_164 == V_98 ) ) {
int V_137 ;
int V_159 = ( V_113 -> V_13 == V_14 ) ?
V_113 -> V_6 -> V_134 : V_113 -> V_6 -> V_7 ;
V_113 -> V_161 = F_85 ( V_159 , sizeof( struct V_165 ) , V_118 ) ;
if ( ! V_113 -> V_161 ) {
F_83 ( & V_113 -> V_166 ) ;
return NULL ;
}
V_113 -> V_167 = V_159 ;
for ( V_137 = 0 ; V_137 < V_159 ; V_137 ++ ) {
F_86 ( & V_113 -> V_161 [ V_137 ] . V_168 ) ;
F_86 ( & V_113 -> V_161 [ V_137 ] . V_169 ) ;
}
}
return & V_113 -> V_166 ;
}
static bool
F_87 ( struct V_170 * V_171 , struct V_77 * V_172 ,
struct V_77 * V_173 )
{
T_3 V_174 , V_175 ;
T_2 V_5 ;
if ( ! F_88 ( V_171 , V_172 , V_173 ) ||
! F_89 ( V_171 , V_172 , V_173 ) )
return false ;
V_174 = ( T_3 ) V_172 -> V_176 << V_177 ;
V_175 = ( T_3 ) V_173 -> V_176 << V_177 ;
V_5 = F_5 ( V_171 -> V_178 ) -> V_5 ;
F_90 ( V_174 , V_5 ) ;
F_90 ( V_175 , V_5 ) ;
return ( V_174 == V_175 ) ;
}
static void
F_91 ( struct V_170 * V_171 ,
struct V_77 * V_173 )
{
F_56 ( V_171 -> V_178 != NULL ) ;
V_171 -> V_178 = F_92 ( V_171 -> V_179 ,
V_173 -> V_180 ,
0 ,
V_127 ,
V_101 ,
V_181 ) ;
if ( V_171 -> V_178 == NULL )
F_93 ( V_171 ) ;
}
static void
F_94 ( struct V_170 * V_171 ,
struct V_77 * V_173 )
{
F_56 ( V_171 -> V_178 != NULL ) ;
V_171 -> V_178 = F_92 ( V_171 -> V_179 ,
V_173 -> V_180 ,
0 ,
V_127 ,
V_98 ,
V_182 ) ;
if ( V_171 -> V_178 == NULL )
F_95 ( V_171 ) ;
}
static T_2 F_96 ( struct V_1 * V_113 , T_2 V_87 )
{
if ( V_113 -> V_13 == V_14 )
return F_50 ( & V_113 -> V_166 , V_87 ) ;
else
return V_87 ;
}
static void
F_97 ( struct V_77 * V_173 )
{
struct V_11 * V_183 = NULL ;
struct V_25 * V_25 = V_173 -> V_180 -> V_184 -> V_185 ;
F_98 ( & V_25 -> V_186 ) ;
if ( ! F_99 ( V_187 , & V_173 -> V_188 ) )
goto V_49;
if ( F_100 ( & V_173 -> V_189 ) ) {
struct V_11 * V_12 ;
F_101 (lseg, &NFS_I(inode)->layout->plh_segs, pls_list) {
if ( V_12 -> V_190 . V_164 == V_98 ) {
V_183 = V_12 ;
break;
}
}
}
V_49:
F_102 ( V_173 ) ;
F_103 ( & V_25 -> V_186 ) ;
F_32 ( V_183 ) ;
}
static struct V_191 *
F_104 ( struct V_77 * V_173 ,
struct V_11 * V_12 )
{
struct V_1 * V_113 = F_5 ( V_12 ) ;
T_2 V_137 , V_87 ;
struct V_191 * V_192 ;
if ( V_113 -> V_60 )
return & F_24 ( V_173 -> V_180 -> V_184 -> V_185 ) -> V_193 ;
V_87 = F_49 ( V_12 ,
( T_1 ) V_173 -> V_176 << V_177 ) ;
V_137 = F_96 ( V_113 , V_87 ) ;
V_192 = & V_113 -> V_161 [ V_137 ] . V_168 ;
if ( F_105 ( V_192 ) ) {
F_106 ( V_12 ) ;
}
F_52 ( V_187 , & V_173 -> V_188 ) ;
return V_192 ;
}
static void
F_107 ( struct V_77 * V_173 ,
struct V_11 * V_12 )
{
struct V_191 * V_192 ;
V_192 = F_104 ( V_173 , V_12 ) ;
F_108 ( V_173 , V_192 ) ;
}
static T_2 F_109 ( struct V_11 * V_12 , T_2 V_137 )
{
struct V_1 * V_2 = F_5 ( V_12 ) ;
if ( V_2 -> V_13 == V_14 )
return V_137 ;
else
return F_50 ( V_12 , V_137 ) ;
}
static struct V_89 *
F_110 ( struct V_11 * V_12 , T_2 V_137 )
{
struct V_1 * V_2 = F_5 ( V_12 ) ;
if ( V_2 -> V_13 == V_14 ) {
if ( V_2 -> V_133 == 1 )
V_137 = 0 ;
else if ( V_2 -> V_133 == 0 )
return NULL ;
}
return V_2 -> V_138 [ V_137 ] ;
}
static int F_111 ( struct V_58 * V_55 , int V_194 )
{
struct V_11 * V_12 = V_55 -> V_12 ;
struct V_85 * V_86 ;
T_2 V_88 ;
struct V_89 * V_90 ;
V_88 = F_109 ( V_12 , V_55 -> V_195 ) ;
V_86 = F_51 ( V_12 , V_88 ) ;
if ( ! V_86 ) {
F_58 ( V_108 L_10 ,
V_41 ) ;
F_52 ( F_53 ( V_98 ) , & V_12 -> V_99 -> V_100 ) ;
F_52 ( F_53 ( V_101 ) , & V_12 -> V_99 -> V_100 ) ;
F_35 ( V_55 ) ;
F_42 ( V_55 ) ;
return - V_50 ;
}
F_12 ( L_25 , V_41 , V_55 -> V_25 -> V_65 , V_194 ) ;
V_55 -> V_109 = F_37 ;
V_55 -> V_57 = V_86 -> V_57 ;
V_90 = F_110 ( V_12 , V_55 -> V_195 ) ;
if ( V_90 )
V_55 -> args . V_90 = V_90 ;
return F_112 ( V_55 , V_86 -> V_57 -> V_104 ,
& V_196 , V_194 ) ;
}
static struct V_11 *
F_113 ( struct V_25 * V_25 )
{
struct V_11 * V_12 ;
F_101 (lseg, &NFS_I(inode)->layout->plh_segs, pls_list)
if ( V_12 -> V_190 . V_164 == V_98 )
return V_12 ;
return NULL ;
}
static struct V_11 * F_114 ( struct V_25 * V_25 )
{
struct V_11 * V_197 ;
F_98 ( & V_25 -> V_186 ) ;
V_197 = F_113 ( V_25 ) ;
if ( V_197 )
F_106 ( V_197 ) ;
F_103 ( & V_25 -> V_186 ) ;
return V_197 ;
}
static int
F_115 ( struct V_165 * V_198 , int F_79 ,
T_7 * V_199 )
{
struct V_191 * V_200 = & V_198 -> V_168 ;
struct V_191 * V_201 = & V_198 -> V_169 ;
struct V_77 * V_173 , * V_202 ;
int V_203 = 0 ;
F_116 (req, tmp, src, wb_list) {
if ( ! F_117 ( V_173 ) )
continue;
if ( F_118 ( V_199 ) )
F_119 ( V_173 , V_202 , V_189 ) ;
F_102 ( V_173 ) ;
F_120 ( V_187 , & V_173 -> V_188 ) ;
F_121 ( V_173 , V_201 ) ;
V_203 ++ ;
if ( V_203 == F_79 )
break;
}
return V_203 ;
}
static int F_122 ( struct V_25 * V_25 , int F_79 ,
T_7 * V_199 )
{
struct V_11 * V_12 ;
struct V_1 * V_113 ;
int V_137 , V_197 = 0 , V_204 ;
V_12 = F_113 ( V_25 ) ;
if ( ! V_12 )
goto V_205;
V_113 = F_5 ( V_12 ) ;
if ( V_113 -> V_60 )
goto V_205;
for ( V_137 = 0 ; V_137 < V_113 -> V_167 && F_79 != 0 ; V_137 ++ ) {
V_204 = F_115 ( & V_113 -> V_161 [ V_137 ] ,
F_79 , V_199 ) ;
F_79 -= V_204 ;
V_197 += V_204 ;
}
V_205:
return V_197 ;
}
static unsigned int
F_123 ( struct V_25 * V_25 , struct V_191 * V_192 )
{
struct V_11 * V_12 ;
struct V_1 * V_113 ;
struct V_58 * V_55 ;
int V_137 , V_87 ;
unsigned int V_206 = 0 ;
V_12 = F_114 ( V_25 ) ;
if ( ! V_12 )
return 0 ;
V_113 = F_5 ( V_12 ) ;
for ( V_137 = 0 ; V_137 < V_113 -> V_167 ; V_137 ++ ) {
if ( F_105 ( & V_113 -> V_161 [ V_137 ] . V_169 ) )
continue;
V_55 = F_124 () ;
if ( ! V_55 )
break;
V_55 -> V_195 = V_137 ;
V_55 -> V_12 = V_12 ;
F_125 ( & V_55 -> V_79 , V_192 ) ;
V_206 ++ ;
}
for ( V_87 = V_137 ; V_87 < V_113 -> V_167 ; V_87 ++ ) {
if ( F_105 ( & V_113 -> V_161 [ V_137 ] . V_169 ) )
continue;
F_126 ( & V_113 -> V_161 [ V_137 ] . V_169 , V_12 ) ;
F_32 ( V_12 ) ;
}
F_32 ( V_12 ) ;
return V_206 ;
}
static int
F_127 ( struct V_25 * V_25 , struct V_191 * V_207 ,
int V_194 )
{
struct V_58 * V_55 , * V_202 ;
F_128 ( V_192 ) ;
unsigned int V_206 = 0 ;
if ( ! F_105 ( V_207 ) ) {
V_55 = F_124 () ;
if ( V_55 != NULL ) {
V_55 -> V_12 = NULL ;
F_125 ( & V_55 -> V_79 , & V_192 ) ;
V_206 ++ ;
} else
F_126 ( V_207 , NULL ) ;
}
V_206 += F_123 ( V_25 , & V_192 ) ;
if ( V_206 == 0 ) {
F_45 ( F_24 ( V_25 ) ) ;
goto V_49;
}
F_129 ( V_206 , & F_24 ( V_25 ) -> V_83 ) ;
F_116 (data, tmp, &list, pages) {
F_130 ( & V_55 -> V_79 ) ;
if ( ! V_55 -> V_12 ) {
F_131 ( V_55 , V_207 , NULL ) ;
F_112 ( V_55 , F_132 ( V_25 ) ,
V_55 -> V_72 , V_194 ) ;
} else {
F_131 ( V_55 , & F_5 ( V_55 -> V_12 ) -> V_161 [ V_55 -> V_195 ] . V_169 , V_55 -> V_12 ) ;
F_111 ( V_55 , V_194 ) ;
}
}
V_49:
return V_106 ;
}
static void
F_133 ( struct V_119 * V_120 )
{
F_134 ( F_63 ( V_120 , struct V_121 , V_130 ) ) ;
}
static int T_8 F_135 ( void )
{
F_58 ( V_208 L_26 ,
V_41 ) ;
return F_136 ( & V_209 ) ;
}
static void T_9 F_137 ( void )
{
F_58 ( V_208 L_27 ,
V_41 ) ;
F_138 ( & V_209 ) ;
}
