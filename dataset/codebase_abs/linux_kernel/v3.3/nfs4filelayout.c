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
if ( V_17 -> V_23 >= 0 )
return 0 ;
* V_22 = 0 ;
switch ( V_17 -> V_23 ) {
case - V_24 :
case - V_25 :
case - V_26 :
case - V_27 :
case - V_28 :
case - V_29 :
case - V_30 :
F_8 ( L_1
L_2 , V_31 , V_17 -> V_23 ,
V_21 -> V_32 ) ;
F_9 ( V_21 -> V_33 ) ;
break;
case - V_34 :
case - V_35 :
case - V_36 :
F_10 ( V_17 , V_37 ) ;
break;
case - V_38 :
break;
default:
F_8 ( L_3 , V_31 ,
V_17 -> V_23 ) ;
* V_22 = 1 ;
break;
}
V_17 -> V_23 = 0 ;
return - V_39 ;
}
static int F_11 ( struct V_16 * V_17 ,
struct V_40 * V_41 )
{
int V_22 = 0 ;
F_8 ( L_4 , V_31 ) ;
if ( F_7 ( V_17 , V_41 -> args . V_42 -> V_19 ,
V_41 -> V_43 , & V_22 ) == - V_39 ) {
F_8 ( L_5 ,
V_31 , V_41 -> V_43 , V_41 -> V_43 -> V_33 ) ;
if ( V_22 ) {
F_12 ( V_41 -> V_12 ) ;
F_13 ( V_17 , V_41 ) ;
}
F_14 ( V_17 ) ;
return - V_39 ;
}
return 0 ;
}
static void
F_15 ( struct V_44 * V_45 )
{
if ( F_5 ( V_45 -> V_12 ) -> V_46 ||
V_45 -> V_47 . V_48 -> V_49 == V_50 )
return;
F_16 ( V_45 ) ;
F_8 ( L_6 , V_31 , V_45 -> V_51 -> V_52 ,
( unsigned long ) F_17 ( V_45 -> V_51 ) -> V_53 -> V_54 ) ;
}
static void F_18 ( struct V_16 * V_17 , void * V_41 )
{
struct V_40 * V_55 = (struct V_40 * ) V_41 ;
V_55 -> V_56 = F_11 ;
if ( F_19 ( V_55 -> V_43 -> V_33 ,
& V_55 -> args . V_57 , & V_55 -> V_47 . V_58 ,
0 , V_17 ) )
return;
F_20 ( V_17 ) ;
}
static void F_21 ( struct V_16 * V_17 , void * V_41 )
{
struct V_40 * V_55 = (struct V_40 * ) V_41 ;
F_8 ( L_7 , V_31 , V_17 -> V_23 ) ;
V_55 -> V_59 -> V_60 ( V_17 , V_41 ) ;
}
static void F_22 ( void * V_41 )
{
struct V_40 * V_55 = (struct V_40 * ) V_41 ;
V_55 -> V_59 -> V_61 ( V_41 ) ;
}
static int F_23 ( struct V_16 * V_17 ,
struct V_44 * V_41 )
{
int V_22 = 0 ;
if ( F_7 ( V_17 , V_41 -> args . V_42 -> V_19 ,
V_41 -> V_43 , & V_22 ) == - V_39 ) {
F_8 ( L_5 ,
V_31 , V_41 -> V_43 , V_41 -> V_43 -> V_33 ) ;
if ( V_22 ) {
F_12 ( V_41 -> V_12 ) ;
F_24 ( V_17 , V_41 ) ;
}
F_14 ( V_17 ) ;
return - V_39 ;
}
F_15 ( V_41 ) ;
return 0 ;
}
static void F_25 ( struct V_44 * V_41 )
{
struct V_62 * V_63 = F_26 ( V_41 -> V_64 . V_65 ) ;
V_41 -> V_17 . V_23 = 0 ;
memcpy ( V_41 -> V_48 . V_66 , V_63 -> V_67 . V_66 ,
sizeof( V_63 -> V_67 . V_66 ) ) ;
V_41 -> V_48 . V_66 [ 0 ] ++ ;
}
static int F_27 ( struct V_16 * V_17 ,
struct V_44 * V_41 )
{
int V_22 = 0 ;
if ( F_7 ( V_17 , V_41 -> args . V_42 -> V_19 ,
V_41 -> V_43 , & V_22 ) == - V_39 ) {
F_8 ( L_5 ,
V_31 , V_41 -> V_43 , V_41 -> V_43 -> V_33 ) ;
if ( V_22 ) {
F_25 ( V_41 ) ;
F_12 ( V_41 -> V_12 ) ;
} else
F_14 ( V_17 ) ;
return - V_39 ;
}
return 0 ;
}
static void F_28 ( struct V_16 * V_17 , void * V_41 )
{
struct V_44 * V_45 = (struct V_44 * ) V_41 ;
if ( F_19 ( V_45 -> V_43 -> V_33 ,
& V_45 -> args . V_57 , & V_45 -> V_47 . V_58 ,
0 , V_17 ) )
return;
F_20 ( V_17 ) ;
}
static void F_29 ( struct V_16 * V_17 , void * V_41 )
{
struct V_44 * V_45 = (struct V_44 * ) V_41 ;
V_45 -> V_59 -> V_60 ( V_17 , V_41 ) ;
}
static void F_30 ( void * V_41 )
{
struct V_44 * V_45 = (struct V_44 * ) V_41 ;
V_45 -> V_59 -> V_61 ( V_41 ) ;
}
static void F_31 ( void * V_41 )
{
struct V_44 * V_45 = (struct V_44 * ) V_41 ;
F_32 ( V_45 ) ;
if ( F_33 ( & F_17 ( V_45 -> V_51 ) -> V_68 ) )
F_34 ( F_17 ( V_45 -> V_51 ) ) ;
F_35 ( V_45 ) ;
}
static enum V_69
F_36 ( struct V_40 * V_41 )
{
struct V_11 * V_12 = V_41 -> V_12 ;
struct V_70 * V_71 ;
T_1 V_3 = V_41 -> args . V_3 ;
T_2 V_72 , V_73 ;
struct V_74 * V_75 ;
int V_76 ;
F_8 ( L_8 ,
V_31 , V_41 -> V_51 -> V_52 ,
V_41 -> args . V_77 , ( V_78 ) V_41 -> args . V_79 , V_3 ) ;
if ( F_37 ( V_80 , & F_38 ( V_12 ) -> V_81 ) )
return V_82 ;
V_72 = F_39 ( V_12 , V_3 ) ;
V_73 = F_40 ( V_12 , V_72 ) ;
V_71 = F_41 ( V_12 , V_73 ) ;
if ( ! V_71 ) {
F_42 ( F_43 ( V_83 ) , & V_12 -> V_84 -> V_85 ) ;
F_42 ( F_43 ( V_86 ) , & V_12 -> V_84 -> V_85 ) ;
return V_82 ;
}
F_8 ( L_9 , V_31 , V_71 -> V_87 ) ;
V_41 -> V_43 = V_71 -> V_43 ;
V_75 = F_44 ( V_12 , V_72 ) ;
if ( V_75 )
V_41 -> args . V_75 = V_75 ;
V_41 -> args . V_3 = F_4 ( V_12 , V_3 ) ;
V_41 -> V_88 = V_3 ;
V_76 = F_45 ( V_41 , V_71 -> V_43 -> V_89 ,
& V_90 ) ;
F_46 ( V_76 != 0 ) ;
return V_91 ;
}
static enum V_69
F_47 ( struct V_44 * V_41 , int V_92 )
{
struct V_11 * V_12 = V_41 -> V_12 ;
struct V_70 * V_71 ;
T_1 V_3 = V_41 -> args . V_3 ;
T_2 V_72 , V_73 ;
struct V_74 * V_75 ;
int V_76 ;
if ( F_37 ( V_80 , & F_38 ( V_12 ) -> V_81 ) )
return V_82 ;
V_72 = F_39 ( V_12 , V_3 ) ;
V_73 = F_40 ( V_12 , V_72 ) ;
V_71 = F_41 ( V_12 , V_73 ) ;
if ( ! V_71 ) {
F_48 ( V_93 L_10 , V_31 ) ;
F_42 ( F_43 ( V_83 ) , & V_12 -> V_84 -> V_85 ) ;
F_42 ( F_43 ( V_86 ) , & V_12 -> V_84 -> V_85 ) ;
return V_82 ;
}
F_8 ( L_11 , V_31 ,
V_41 -> V_51 -> V_52 , V_92 , ( V_78 ) V_41 -> args . V_79 , V_3 ,
V_71 -> V_87 ) ;
V_41 -> V_94 = F_23 ;
V_41 -> V_43 = V_71 -> V_43 ;
V_75 = F_44 ( V_12 , V_72 ) ;
if ( V_75 )
V_41 -> args . V_75 = V_75 ;
V_41 -> args . V_3 = F_4 ( V_12 , V_3 ) ;
V_76 = F_49 ( V_41 , V_71 -> V_43 -> V_89 ,
& V_95 , V_92 ) ;
F_46 ( V_76 != 0 ) ;
return V_91 ;
}
static int
F_50 ( struct V_96 * V_97 ,
struct V_1 * V_98 ,
struct V_99 * V_100 ,
struct V_101 * V_102 ,
T_4 V_103 )
{
struct V_104 * V_105 ;
struct V_106 * V_6 ;
int V_76 = - V_107 ;
struct V_108 * V_109 = F_51 ( V_97 -> V_110 ) ;
F_8 ( L_12 , V_31 ) ;
if ( V_100 -> V_111 . V_3 != 0 ||
V_100 -> V_111 . V_112 != V_113 ) {
F_8 ( L_13 ,
V_31 ) ;
goto V_114;
}
if ( V_98 -> V_10 > V_100 -> V_111 . V_3 ) {
F_8 ( L_14 ,
V_31 , V_98 -> V_10 ) ;
goto V_114;
}
if ( ! V_98 -> V_5 || V_98 -> V_5 % V_115 ) {
F_8 ( L_15 ,
V_31 , V_98 -> V_5 ) ;
goto V_114;
}
V_105 = F_52 ( F_51 ( V_97 -> V_110 ) -> V_116 ,
F_51 ( V_97 -> V_110 ) -> V_20 , V_102 ) ;
if ( V_105 == NULL ) {
V_6 = F_53 ( V_97 -> V_110 , V_102 , V_103 ) ;
if ( V_6 == NULL )
goto V_114;
} else
V_6 = F_54 ( V_105 , struct V_106 , V_117 ) ;
if ( F_37 ( V_80 , & V_6 -> V_117 . V_81 ) )
goto V_118;
V_98 -> V_6 = V_6 ;
if ( V_98 -> V_119 >= V_6 -> V_7 ) {
F_8 ( L_16 ,
V_31 , V_98 -> V_119 ) ;
goto V_118;
}
if ( ( V_98 -> V_13 == V_14 &&
V_98 -> V_120 > 1 && V_98 -> V_120 != V_6 -> V_121 ) ||
( V_98 -> V_13 == V_15 &&
V_98 -> V_120 != V_6 -> V_7 ) ) {
F_8 ( L_17 ,
V_31 , V_98 -> V_120 ) ;
goto V_118;
}
if ( V_98 -> V_5 % V_109 -> V_122 || V_98 -> V_5 % V_109 -> V_123 ) {
F_8 ( L_18
L_19 , V_31 , V_98 -> V_5 , V_109 -> V_122 ,
V_109 -> V_123 ) ;
}
V_76 = 0 ;
V_114:
F_8 ( L_20 , V_31 , V_76 ) ;
return V_76 ;
V_118:
F_55 ( V_6 ) ;
goto V_114;
}
static void F_56 ( struct V_1 * V_98 )
{
int V_124 ;
for ( V_124 = 0 ; V_124 < V_98 -> V_120 ; V_124 ++ ) {
if ( ! V_98 -> V_125 [ V_124 ] )
break;
F_57 ( V_98 -> V_125 [ V_124 ] ) ;
}
F_57 ( V_98 -> V_125 ) ;
V_98 -> V_125 = NULL ;
}
static void
F_58 ( struct V_1 * V_98 )
{
F_56 ( V_98 ) ;
F_57 ( V_98 ) ;
}
static int
F_59 ( struct V_96 * V_126 ,
struct V_1 * V_98 ,
struct V_99 * V_100 ,
struct V_101 * V_102 ,
T_4 V_103 )
{
struct V_127 V_128 ;
struct V_129 V_130 ;
struct V_131 * V_132 ;
T_5 * V_133 ;
T_6 V_134 ;
int V_124 ;
F_8 ( L_21 , V_31 ) ;
V_132 = F_60 ( V_103 ) ;
if ( ! V_132 )
return - V_135 ;
F_61 ( & V_128 , & V_130 , V_100 -> V_136 -> V_64 , V_100 -> V_136 -> V_137 ) ;
F_62 ( & V_128 , F_63 ( V_132 ) , V_115 ) ;
V_133 = F_64 ( & V_128 , V_138 + 20 ) ;
if ( F_65 ( ! V_133 ) )
goto V_139;
memcpy ( V_102 , V_133 , sizeof( * V_102 ) ) ;
V_133 += F_66 ( V_138 ) ;
F_67 ( V_102 ) ;
V_134 = F_68 ( V_133 ++ ) ;
if ( V_134 & V_140 )
V_98 -> V_46 = 1 ;
if ( V_134 & V_141 )
V_98 -> V_13 = V_15 ;
else
V_98 -> V_13 = V_14 ;
V_98 -> V_5 = V_134 & ~ V_142 ;
V_98 -> V_119 = F_68 ( V_133 ++ ) ;
V_133 = F_69 ( V_133 , & V_98 -> V_10 ) ;
V_98 -> V_120 = F_68 ( V_133 ++ ) ;
F_8 ( L_22 ,
V_31 , V_134 , V_98 -> V_120 , V_98 -> V_119 ,
V_98 -> V_10 ) ;
if ( V_98 -> V_120 >
F_70 ( V_143 , V_144 ) )
goto V_139;
if ( V_98 -> V_120 > 0 ) {
V_98 -> V_125 = F_71 ( V_98 -> V_120 * sizeof( struct V_74 * ) ,
V_103 ) ;
if ( ! V_98 -> V_125 )
goto V_139;
}
for ( V_124 = 0 ; V_124 < V_98 -> V_120 ; V_124 ++ ) {
V_98 -> V_125 [ V_124 ] = F_72 ( sizeof( struct V_74 ) , V_103 ) ;
if ( ! V_98 -> V_125 [ V_124 ] )
goto V_145;
V_133 = F_64 ( & V_128 , 4 ) ;
if ( F_65 ( ! V_133 ) )
goto V_145;
V_98 -> V_125 [ V_124 ] -> V_146 = F_68 ( V_133 ++ ) ;
if ( sizeof( struct V_74 ) < V_98 -> V_125 [ V_124 ] -> V_146 ) {
F_48 ( V_93 L_23 ,
V_124 , V_98 -> V_125 [ V_124 ] -> V_146 ) ;
goto V_145;
}
V_133 = F_64 ( & V_128 , V_98 -> V_125 [ V_124 ] -> V_146 ) ;
if ( F_65 ( ! V_133 ) )
goto V_145;
memcpy ( V_98 -> V_125 [ V_124 ] -> V_41 , V_133 , V_98 -> V_125 [ V_124 ] -> V_146 ) ;
F_8 ( L_24 , V_31 ,
V_98 -> V_125 [ V_124 ] -> V_146 ) ;
}
F_73 ( V_132 ) ;
return 0 ;
V_145:
F_56 ( V_98 ) ;
V_139:
F_73 ( V_132 ) ;
return - V_147 ;
}
static void
F_74 ( struct V_11 * V_12 )
{
struct V_1 * V_98 = F_5 ( V_12 ) ;
F_8 ( L_12 , V_31 ) ;
F_55 ( V_98 -> V_6 ) ;
F_57 ( V_98 -> V_148 ) ;
F_58 ( V_98 ) ;
}
static struct V_11 *
F_75 ( struct V_96 * V_149 ,
struct V_99 * V_100 ,
T_4 V_103 )
{
struct V_1 * V_98 ;
int V_150 ;
struct V_101 V_102 ;
F_8 ( L_12 , V_31 ) ;
V_98 = F_71 ( sizeof( * V_98 ) , V_103 ) ;
if ( ! V_98 )
return NULL ;
V_150 = F_59 ( V_149 , V_98 , V_100 , & V_102 , V_103 ) ;
if ( V_150 != 0 || F_50 ( V_149 , V_98 , V_100 , & V_102 , V_103 ) ) {
F_58 ( V_98 ) ;
return NULL ;
}
if ( ( ! V_98 -> V_46 ) && ( V_100 -> V_111 . V_151 == V_83 ) ) {
int V_124 ;
int V_146 = ( V_98 -> V_13 == V_14 ) ?
V_98 -> V_6 -> V_121 : V_98 -> V_6 -> V_7 ;
V_98 -> V_148 = F_76 ( V_146 , sizeof( struct V_152 ) , V_103 ) ;
if ( ! V_98 -> V_148 ) {
F_74 ( & V_98 -> V_153 ) ;
return NULL ;
}
V_98 -> V_154 = V_146 ;
for ( V_124 = 0 ; V_124 < V_146 ; V_124 ++ )
F_77 ( & V_98 -> V_148 [ V_124 ] ) ;
}
return & V_98 -> V_153 ;
}
static bool
F_78 ( struct V_155 * V_156 , struct V_62 * V_157 ,
struct V_62 * V_158 )
{
T_3 V_159 , V_160 ;
T_2 V_5 ;
if ( ! F_79 ( V_156 , V_157 , V_158 ) ||
! F_80 ( V_156 , V_157 , V_158 ) )
return false ;
V_159 = ( T_3 ) V_157 -> V_161 << V_162 ;
V_160 = ( T_3 ) V_158 -> V_161 << V_162 ;
V_5 = F_5 ( V_156 -> V_163 ) -> V_5 ;
F_81 ( V_159 , V_5 ) ;
F_81 ( V_160 , V_5 ) ;
return ( V_159 == V_160 ) ;
}
void
F_82 ( struct V_155 * V_156 ,
struct V_62 * V_158 )
{
F_46 ( V_156 -> V_163 != NULL ) ;
V_156 -> V_163 = F_83 ( V_156 -> V_164 ,
V_158 -> V_165 ,
0 ,
V_113 ,
V_86 ,
V_166 ) ;
if ( V_156 -> V_163 == NULL )
F_84 ( V_156 ) ;
}
void
F_85 ( struct V_155 * V_156 ,
struct V_62 * V_158 )
{
F_46 ( V_156 -> V_163 != NULL ) ;
V_156 -> V_163 = F_83 ( V_156 -> V_164 ,
V_158 -> V_165 ,
0 ,
V_113 ,
V_83 ,
V_167 ) ;
if ( V_156 -> V_163 == NULL )
F_86 ( V_156 ) ;
}
static bool F_87 ( struct V_11 * V_12 )
{
return ! F_5 ( V_12 ) -> V_46 ;
}
static T_2 F_88 ( struct V_1 * V_98 , T_2 V_72 )
{
if ( V_98 -> V_13 == V_14 )
return F_40 ( & V_98 -> V_153 , V_72 ) ;
else
return V_72 ;
}
struct V_152 * F_89 ( struct V_62 * V_158 )
{
struct V_11 * V_12 = V_158 -> V_168 ;
struct V_1 * V_98 = F_5 ( V_12 ) ;
T_2 V_124 , V_72 ;
struct V_152 * V_169 ;
V_72 = F_39 ( V_12 ,
( T_1 ) V_158 -> V_161 << V_162 ) ;
V_124 = F_88 ( V_98 , V_72 ) ;
V_169 = & V_98 -> V_148 [ V_124 ] ;
if ( F_90 ( V_169 ) ) {
F_91 ( V_12 ) ;
}
return V_169 ;
}
static T_2 F_92 ( struct V_11 * V_12 , T_2 V_124 )
{
struct V_1 * V_2 = F_5 ( V_12 ) ;
if ( V_2 -> V_13 == V_14 )
return V_124 ;
else
return F_40 ( V_12 , V_124 ) ;
}
static struct V_74 *
F_93 ( struct V_11 * V_12 , T_2 V_124 )
{
struct V_1 * V_2 = F_5 ( V_12 ) ;
if ( V_2 -> V_13 == V_14 ) {
if ( V_2 -> V_120 == 1 )
V_124 = 0 ;
else if ( V_2 -> V_120 == 0 )
return NULL ;
}
return V_2 -> V_125 [ V_124 ] ;
}
static int F_94 ( struct V_44 * V_41 , int V_170 )
{
struct V_11 * V_12 = V_41 -> V_12 ;
struct V_70 * V_71 ;
T_2 V_73 ;
struct V_74 * V_75 ;
V_73 = F_92 ( V_12 , V_41 -> V_171 ) ;
V_71 = F_41 ( V_12 , V_73 ) ;
if ( ! V_71 ) {
F_48 ( V_93 L_10 , V_31 ) ;
F_42 ( F_43 ( V_83 ) , & V_12 -> V_84 -> V_85 ) ;
F_42 ( F_43 ( V_86 ) , & V_12 -> V_84 -> V_85 ) ;
F_25 ( V_41 ) ;
V_41 -> V_59 -> V_61 ( V_41 ) ;
return - V_39 ;
}
F_8 ( L_25 , V_31 , V_41 -> V_51 -> V_52 , V_170 ) ;
V_41 -> V_94 = F_27 ;
V_41 -> V_43 = V_71 -> V_43 ;
V_75 = F_93 ( V_12 , V_41 -> V_171 ) ;
if ( V_75 )
V_41 -> args . V_75 = V_75 ;
return F_95 ( V_41 , V_71 -> V_43 -> V_89 ,
& V_172 , V_170 ) ;
}
static struct V_11 * F_96 ( struct V_51 * V_51 )
{
struct V_11 * V_12 , * V_173 = NULL ;
F_97 ( & V_51 -> V_174 ) ;
F_98 (lseg, &NFS_I(inode)->layout->plh_segs, pls_list)
if ( V_12 -> V_175 . V_151 == V_83 )
V_173 = F_91 ( V_12 ) ;
F_99 ( & V_51 -> V_174 ) ;
return V_173 ;
}
static int F_100 ( struct V_51 * V_51 , struct V_152 * V_169 )
{
struct V_11 * V_12 ;
struct V_1 * V_98 ;
struct V_44 * V_41 ;
int V_124 , V_72 ;
V_12 = F_96 ( V_51 ) ;
if ( ! V_12 )
return 0 ;
V_98 = F_5 ( V_12 ) ;
for ( V_124 = 0 ; V_124 < V_98 -> V_154 ; V_124 ++ ) {
if ( F_90 ( & V_98 -> V_148 [ V_124 ] ) )
continue;
V_41 = F_101 () ;
if ( ! V_41 )
goto V_176;
V_41 -> V_171 = V_124 ;
V_41 -> V_12 = V_12 ;
F_102 ( & V_41 -> V_64 , V_169 ) ;
}
F_103 ( V_12 ) ;
return 0 ;
V_176:
for ( V_72 = V_124 ; V_72 < V_98 -> V_154 ; V_72 ++ ) {
if ( F_90 ( & V_98 -> V_148 [ V_124 ] ) )
continue;
F_104 ( & V_98 -> V_148 [ V_124 ] , V_12 ) ;
F_103 ( V_12 ) ;
}
F_103 ( V_12 ) ;
return - V_135 ;
}
static int
F_105 ( struct V_51 * V_51 , struct V_152 * V_177 ,
int V_170 )
{
struct V_44 * V_41 , * V_178 ;
F_106 ( V_169 ) ;
if ( ! F_90 ( V_177 ) ) {
V_41 = F_101 () ;
if ( ! V_41 )
goto V_176;
V_41 -> V_12 = NULL ;
F_102 ( & V_41 -> V_64 , & V_169 ) ;
}
if ( F_100 ( V_51 , & V_169 ) )
goto V_176;
F_107 (data, tmp, &list, pages) {
F_108 ( & V_41 -> V_64 ) ;
F_109 ( & F_17 ( V_51 ) -> V_68 ) ;
if ( ! V_41 -> V_12 ) {
F_110 ( V_41 , V_177 , NULL ) ;
F_95 ( V_41 , F_111 ( V_51 ) ,
V_41 -> V_59 , V_170 ) ;
} else {
F_110 ( V_41 , & F_5 ( V_41 -> V_12 ) -> V_148 [ V_41 -> V_171 ] , V_41 -> V_12 ) ;
F_94 ( V_41 , V_170 ) ;
}
}
return 0 ;
V_176:
F_107 (data, tmp, &list, pages) {
F_104 ( & V_41 -> V_64 , V_41 -> V_12 ) ;
F_108 ( & V_41 -> V_64 ) ;
F_112 ( V_41 ) ;
}
F_104 ( V_177 , NULL ) ;
F_34 ( F_17 ( V_51 ) ) ;
return - V_135 ;
}
static void
F_113 ( struct V_104 * V_105 )
{
F_114 ( F_54 ( V_105 , struct V_106 , V_117 ) ) ;
}
static int T_7 F_115 ( void )
{
F_48 ( V_179 L_26 ,
V_31 ) ;
return F_116 ( & V_180 ) ;
}
static void T_8 F_117 ( void )
{
F_48 ( V_179 L_27 ,
V_31 ) ;
F_118 ( & V_180 ) ;
}
