static T_1
F_1 ( struct V_1 * V_2 ,
T_1 V_3 )
{
T_2 V_4 = V_2 -> V_5 * V_2 -> V_6 -> V_7 ;
T_3 V_8 ;
V_3 -= V_2 -> V_9 ;
V_8 = V_3 ;
F_2 ( V_8 , V_4 ) ;
return V_8 * V_2 -> V_5 + F_2 ( V_3 , V_2 -> V_5 ) ;
}
static T_1
F_3 ( struct V_10 * V_11 , T_1 V_3 )
{
struct V_1 * V_2 = F_4 ( V_11 ) ;
switch ( V_2 -> V_12 ) {
case V_13 :
return V_3 ;
case V_14 :
return F_1 ( V_2 , V_3 ) ;
}
F_5 () ;
}
static void
F_6 ( struct V_10 * V_11 )
{
if ( V_11 -> V_15 . V_16 == V_17 ) {
F_7 ( L_1 , V_18 ) ;
F_8 ( F_9 ( V_17 ) , & V_11 -> V_19 -> V_20 ) ;
} else {
F_7 ( L_2 , V_18 ) ;
F_8 ( F_9 ( V_21 ) , & V_11 -> V_19 -> V_20 ) ;
}
}
static int F_10 ( struct V_22 * V_23 ,
struct V_24 * V_25 ,
struct V_26 * V_27 ,
int * V_28 )
{
if ( V_23 -> V_29 >= 0 )
return 0 ;
* V_28 = 0 ;
switch ( V_23 -> V_29 ) {
case - V_30 :
case - V_31 :
case - V_32 :
case - V_33 :
case - V_34 :
case - V_35 :
case - V_36 :
F_7 ( L_3
L_4 , V_18 , V_23 -> V_29 ,
V_27 -> V_37 ) ;
F_11 ( V_27 -> V_38 ) ;
break;
case - V_39 :
case - V_40 :
case - V_41 :
F_12 ( V_23 , V_42 ) ;
break;
case - V_43 :
break;
default:
F_7 ( L_5 , V_18 ,
V_23 -> V_29 ) ;
* V_28 = 1 ;
break;
}
V_23 -> V_29 = 0 ;
return - V_44 ;
}
static int F_13 ( struct V_22 * V_23 ,
struct V_45 * V_46 )
{
struct V_26 * V_27 = V_46 -> V_47 ;
int V_28 = 0 ;
F_7 ( L_6 , V_18 ) ;
if ( F_10 ( V_23 , V_46 -> args . V_48 -> V_25 ,
V_46 -> V_47 , & V_28 ) == - V_44 ) {
F_7 ( L_7 ,
V_18 , V_46 -> V_47 , V_46 -> V_47 -> V_38 ) ;
if ( V_28 ) {
F_6 ( V_46 -> V_11 ) ;
F_14 ( V_23 , V_46 ) ;
V_27 = F_15 ( V_46 -> V_49 ) -> V_26 ;
}
F_16 ( V_23 , V_27 ) ;
return - V_44 ;
}
return 0 ;
}
static void
F_17 ( struct V_50 * V_51 )
{
if ( F_4 ( V_51 -> V_11 ) -> V_52 ||
V_51 -> V_53 . V_54 -> V_55 == V_56 )
return;
F_18 ( V_51 ) ;
F_7 ( L_8 , V_18 , V_51 -> V_49 -> V_57 ,
( unsigned long ) F_19 ( V_51 -> V_49 ) -> V_58 -> V_59 ) ;
}
static void F_20 ( struct V_22 * V_23 , void * V_46 )
{
struct V_45 * V_60 = (struct V_45 * ) V_46 ;
V_60 -> V_61 = F_13 ;
if ( F_21 ( V_60 -> V_47 -> V_38 ,
& V_60 -> args . V_62 , & V_60 -> V_53 . V_63 ,
0 , V_23 ) )
return;
F_22 ( V_23 ) ;
}
static void F_23 ( struct V_22 * V_23 , void * V_46 )
{
struct V_45 * V_60 = (struct V_45 * ) V_46 ;
F_7 ( L_9 , V_18 , V_23 -> V_29 ) ;
V_60 -> V_64 -> V_65 ( V_23 , V_46 ) ;
}
static void F_24 ( void * V_46 )
{
struct V_45 * V_60 = (struct V_45 * ) V_46 ;
V_60 -> V_64 -> V_66 ( V_46 ) ;
}
static int F_25 ( struct V_22 * V_23 ,
struct V_50 * V_46 )
{
int V_28 = 0 ;
if ( F_10 ( V_23 , V_46 -> args . V_48 -> V_25 ,
V_46 -> V_47 , & V_28 ) == - V_44 ) {
struct V_26 * V_27 ;
F_7 ( L_7 ,
V_18 , V_46 -> V_47 , V_46 -> V_47 -> V_38 ) ;
if ( V_28 ) {
F_6 ( V_46 -> V_11 ) ;
F_26 ( V_23 , V_46 ) ;
V_27 = F_15 ( V_46 -> V_49 ) -> V_26 ;
} else
V_27 = V_46 -> V_47 ;
F_16 ( V_23 , V_27 ) ;
return - V_44 ;
}
F_17 ( V_46 ) ;
return 0 ;
}
static void F_27 ( struct V_50 * V_46 )
{
struct V_67 * V_68 = F_28 ( V_46 -> V_69 . V_70 ) ;
V_46 -> V_23 . V_29 = 0 ;
memcpy ( V_46 -> V_54 . V_71 , V_68 -> V_72 . V_71 ,
sizeof( V_68 -> V_72 . V_71 ) ) ;
V_46 -> V_54 . V_71 [ 0 ] ++ ;
}
static int F_29 ( struct V_22 * V_23 ,
struct V_50 * V_46 )
{
int V_28 = 0 ;
if ( F_10 ( V_23 , V_46 -> args . V_48 -> V_25 ,
V_46 -> V_47 , & V_28 ) == - V_44 ) {
F_7 ( L_7 ,
V_18 , V_46 -> V_47 , V_46 -> V_47 -> V_38 ) ;
if ( V_28 ) {
F_27 ( V_46 ) ;
F_6 ( V_46 -> V_11 ) ;
} else
F_16 ( V_23 , V_46 -> V_47 ) ;
return - V_44 ;
}
return 0 ;
}
static void F_30 ( struct V_22 * V_23 , void * V_46 )
{
struct V_50 * V_51 = (struct V_50 * ) V_46 ;
if ( F_21 ( V_51 -> V_47 -> V_38 ,
& V_51 -> args . V_62 , & V_51 -> V_53 . V_63 ,
0 , V_23 ) )
return;
F_22 ( V_23 ) ;
}
static void F_31 ( struct V_22 * V_23 , void * V_46 )
{
struct V_50 * V_51 = (struct V_50 * ) V_46 ;
V_51 -> V_64 -> V_65 ( V_23 , V_46 ) ;
}
static void F_32 ( void * V_46 )
{
struct V_50 * V_51 = (struct V_50 * ) V_46 ;
V_51 -> V_64 -> V_66 ( V_46 ) ;
}
static void F_33 ( void * V_46 )
{
struct V_50 * V_51 = (struct V_50 * ) V_46 ;
F_34 ( V_51 ) ;
if ( F_35 ( & F_19 ( V_51 -> V_49 ) -> V_73 ) )
F_36 ( F_19 ( V_51 -> V_49 ) ) ;
F_37 ( V_51 ) ;
}
static enum V_74
F_38 ( struct V_45 * V_46 )
{
struct V_10 * V_11 = V_46 -> V_11 ;
struct V_75 * V_76 ;
T_1 V_3 = V_46 -> args . V_3 ;
T_2 V_77 , V_78 ;
struct V_79 * V_80 ;
int V_81 ;
F_7 ( L_10 ,
V_18 , V_46 -> V_49 -> V_57 ,
V_46 -> args . V_82 , ( V_83 ) V_46 -> args . V_84 , V_3 ) ;
if ( F_39 ( V_85 , & F_40 ( V_11 ) -> V_86 ) )
return V_87 ;
V_77 = F_41 ( V_11 , V_3 ) ;
V_78 = F_42 ( V_11 , V_77 ) ;
V_76 = F_43 ( V_11 , V_78 ) ;
if ( ! V_76 ) {
F_8 ( F_9 ( V_17 ) , & V_11 -> V_19 -> V_20 ) ;
F_8 ( F_9 ( V_21 ) , & V_11 -> V_19 -> V_20 ) ;
return V_87 ;
}
F_7 ( L_11 , V_18 , V_76 -> V_88 ) ;
V_46 -> V_47 = V_76 -> V_47 ;
V_80 = F_44 ( V_11 , V_77 ) ;
if ( V_80 )
V_46 -> args . V_80 = V_80 ;
V_46 -> args . V_3 = F_3 ( V_11 , V_3 ) ;
V_46 -> V_89 = V_3 ;
V_81 = F_45 ( V_46 , V_76 -> V_47 -> V_90 ,
& V_91 ) ;
F_46 ( V_81 != 0 ) ;
return V_92 ;
}
static enum V_74
F_47 ( struct V_50 * V_46 , int V_93 )
{
struct V_10 * V_11 = V_46 -> V_11 ;
struct V_75 * V_76 ;
T_1 V_3 = V_46 -> args . V_3 ;
T_2 V_77 , V_78 ;
struct V_79 * V_80 ;
int V_81 ;
if ( F_39 ( V_85 , & F_40 ( V_11 ) -> V_86 ) )
return V_87 ;
V_77 = F_41 ( V_11 , V_3 ) ;
V_78 = F_42 ( V_11 , V_77 ) ;
V_76 = F_43 ( V_11 , V_78 ) ;
if ( ! V_76 ) {
F_48 ( V_94 L_12 , V_18 ) ;
F_8 ( F_9 ( V_17 ) , & V_11 -> V_19 -> V_20 ) ;
F_8 ( F_9 ( V_21 ) , & V_11 -> V_19 -> V_20 ) ;
return V_87 ;
}
F_7 ( L_13 , V_18 ,
V_46 -> V_49 -> V_57 , V_93 , ( V_83 ) V_46 -> args . V_84 , V_3 ,
V_76 -> V_88 ) ;
V_46 -> V_95 = F_25 ;
V_46 -> V_47 = V_76 -> V_47 ;
V_80 = F_44 ( V_11 , V_77 ) ;
if ( V_80 )
V_46 -> args . V_80 = V_80 ;
V_46 -> args . V_3 = F_3 ( V_11 , V_3 ) ;
V_81 = F_49 ( V_46 , V_76 -> V_47 -> V_90 ,
& V_96 , V_93 ) ;
F_46 ( V_81 != 0 ) ;
return V_92 ;
}
static int
F_50 ( struct V_97 * V_98 ,
struct V_1 * V_99 ,
struct V_100 * V_101 ,
struct V_102 * V_103 ,
T_4 V_104 )
{
struct V_105 * V_106 ;
struct V_107 * V_6 ;
int V_81 = - V_108 ;
struct V_109 * V_110 = F_15 ( V_98 -> V_111 ) ;
F_7 ( L_14 , V_18 ) ;
if ( V_101 -> V_112 . V_3 != 0 ||
V_101 -> V_112 . V_113 != V_114 ) {
F_7 ( L_15 ,
V_18 ) ;
goto V_115;
}
if ( V_99 -> V_9 > V_101 -> V_112 . V_3 ) {
F_7 ( L_16 ,
V_18 , V_99 -> V_9 ) ;
goto V_115;
}
if ( ! V_99 -> V_5 || V_99 -> V_5 % V_116 ) {
F_7 ( L_17 ,
V_18 , V_99 -> V_5 ) ;
goto V_115;
}
V_106 = F_51 ( F_15 ( V_98 -> V_111 ) -> V_117 ,
F_15 ( V_98 -> V_111 ) -> V_26 , V_103 ) ;
if ( V_106 == NULL ) {
V_6 = F_52 ( V_98 -> V_111 , V_103 , V_104 ) ;
if ( V_6 == NULL )
goto V_115;
} else
V_6 = F_53 ( V_106 , struct V_107 , V_118 ) ;
if ( F_39 ( V_85 , & V_6 -> V_118 . V_86 ) )
goto V_119;
V_99 -> V_6 = V_6 ;
if ( V_99 -> V_120 < 0 ||
V_99 -> V_120 >= V_6 -> V_7 ) {
F_7 ( L_18 ,
V_18 , V_99 -> V_120 ) ;
goto V_119;
}
if ( ( V_99 -> V_12 == V_13 &&
V_99 -> V_121 > 1 && V_99 -> V_121 != V_6 -> V_122 ) ||
( V_99 -> V_12 == V_14 &&
V_99 -> V_121 != V_6 -> V_7 ) ) {
F_7 ( L_19 ,
V_18 , V_99 -> V_121 ) ;
goto V_119;
}
if ( V_99 -> V_5 % V_110 -> V_123 || V_99 -> V_5 % V_110 -> V_124 ) {
F_7 ( L_20
L_21 , V_18 , V_99 -> V_5 , V_110 -> V_123 ,
V_110 -> V_124 ) ;
}
V_81 = 0 ;
V_115:
F_7 ( L_22 , V_18 , V_81 ) ;
return V_81 ;
V_119:
F_54 ( V_6 ) ;
goto V_115;
}
static void F_55 ( struct V_1 * V_99 )
{
int V_125 ;
for ( V_125 = 0 ; V_125 < V_99 -> V_121 ; V_125 ++ ) {
if ( ! V_99 -> V_126 [ V_125 ] )
break;
F_56 ( V_99 -> V_126 [ V_125 ] ) ;
}
F_56 ( V_99 -> V_126 ) ;
V_99 -> V_126 = NULL ;
}
static void
F_57 ( struct V_1 * V_99 )
{
F_55 ( V_99 ) ;
F_56 ( V_99 ) ;
}
static int
F_58 ( struct V_97 * V_127 ,
struct V_1 * V_99 ,
struct V_100 * V_101 ,
struct V_102 * V_103 ,
T_4 V_104 )
{
struct V_128 V_129 ;
struct V_130 V_131 ;
struct V_132 * V_133 ;
T_5 * V_134 ;
T_6 V_135 ;
int V_125 ;
F_7 ( L_23 , V_18 ) ;
V_133 = F_59 ( V_104 ) ;
if ( ! V_133 )
return - V_136 ;
F_60 ( & V_129 , & V_131 , V_101 -> V_137 -> V_69 , V_101 -> V_137 -> V_138 ) ;
F_61 ( & V_129 , F_62 ( V_133 ) , V_116 ) ;
V_134 = F_63 ( & V_129 , V_139 + 20 ) ;
if ( F_64 ( ! V_134 ) )
goto V_140;
memcpy ( V_103 , V_134 , sizeof( * V_103 ) ) ;
V_134 += F_65 ( V_139 ) ;
F_66 ( V_103 ) ;
V_135 = F_67 ( V_134 ++ ) ;
if ( V_135 & V_141 )
V_99 -> V_52 = 1 ;
if ( V_135 & V_142 )
V_99 -> V_12 = V_14 ;
else
V_99 -> V_12 = V_13 ;
V_99 -> V_5 = V_135 & ~ V_143 ;
V_99 -> V_120 = F_67 ( V_134 ++ ) ;
V_134 = F_68 ( V_134 , & V_99 -> V_9 ) ;
V_99 -> V_121 = F_67 ( V_134 ++ ) ;
F_7 ( L_24 ,
V_18 , V_135 , V_99 -> V_121 , V_99 -> V_120 ,
V_99 -> V_9 ) ;
if ( V_99 -> V_121 < 0 || V_99 -> V_121 >
F_69 ( V_144 , V_145 ) )
goto V_140;
if ( V_99 -> V_121 > 0 ) {
V_99 -> V_126 = F_70 ( V_99 -> V_121 * sizeof( struct V_79 * ) ,
V_104 ) ;
if ( ! V_99 -> V_126 )
goto V_140;
}
for ( V_125 = 0 ; V_125 < V_99 -> V_121 ; V_125 ++ ) {
V_99 -> V_126 [ V_125 ] = F_71 ( sizeof( struct V_79 ) , V_104 ) ;
if ( ! V_99 -> V_126 [ V_125 ] )
goto V_146;
V_134 = F_63 ( & V_129 , 4 ) ;
if ( F_64 ( ! V_134 ) )
goto V_146;
V_99 -> V_126 [ V_125 ] -> V_147 = F_67 ( V_134 ++ ) ;
if ( sizeof( struct V_79 ) < V_99 -> V_126 [ V_125 ] -> V_147 ) {
F_48 ( V_94 L_25 ,
V_125 , V_99 -> V_126 [ V_125 ] -> V_147 ) ;
goto V_146;
}
V_134 = F_63 ( & V_129 , V_99 -> V_126 [ V_125 ] -> V_147 ) ;
if ( F_64 ( ! V_134 ) )
goto V_146;
memcpy ( V_99 -> V_126 [ V_125 ] -> V_46 , V_134 , V_99 -> V_126 [ V_125 ] -> V_147 ) ;
F_7 ( L_26 , V_18 ,
V_99 -> V_126 [ V_125 ] -> V_147 ) ;
}
F_72 ( V_133 ) ;
return 0 ;
V_146:
F_55 ( V_99 ) ;
V_140:
F_72 ( V_133 ) ;
return - V_148 ;
}
static void
F_73 ( struct V_10 * V_11 )
{
struct V_1 * V_99 = F_4 ( V_11 ) ;
F_7 ( L_14 , V_18 ) ;
F_54 ( V_99 -> V_6 ) ;
F_56 ( V_99 -> V_149 ) ;
F_57 ( V_99 ) ;
}
static struct V_10 *
F_74 ( struct V_97 * V_150 ,
struct V_100 * V_101 ,
T_4 V_104 )
{
struct V_1 * V_99 ;
int V_151 ;
struct V_102 V_103 ;
F_7 ( L_14 , V_18 ) ;
V_99 = F_70 ( sizeof( * V_99 ) , V_104 ) ;
if ( ! V_99 )
return NULL ;
V_151 = F_58 ( V_150 , V_99 , V_101 , & V_103 , V_104 ) ;
if ( V_151 != 0 || F_50 ( V_150 , V_99 , V_101 , & V_103 , V_104 ) ) {
F_57 ( V_99 ) ;
return NULL ;
}
if ( ( ! V_99 -> V_52 ) && ( V_101 -> V_112 . V_16 == V_17 ) ) {
int V_125 ;
int V_147 = ( V_99 -> V_12 == V_13 ) ?
V_99 -> V_6 -> V_122 : V_99 -> V_6 -> V_7 ;
V_99 -> V_149 = F_75 ( V_147 , sizeof( struct V_152 ) , V_104 ) ;
if ( ! V_99 -> V_149 ) {
F_73 ( & V_99 -> V_153 ) ;
return NULL ;
}
V_99 -> V_154 = V_147 ;
for ( V_125 = 0 ; V_125 < V_147 ; V_125 ++ )
F_76 ( & V_99 -> V_149 [ V_125 ] ) ;
}
return & V_99 -> V_153 ;
}
static bool
F_77 ( struct V_155 * V_156 , struct V_67 * V_157 ,
struct V_67 * V_158 )
{
T_3 V_159 , V_160 ;
T_2 V_5 ;
if ( ! F_78 ( V_156 , V_157 , V_158 ) ||
! F_79 ( V_156 , V_157 , V_158 ) )
return false ;
V_159 = ( T_3 ) V_157 -> V_161 << V_162 ;
V_160 = ( T_3 ) V_158 -> V_161 << V_162 ;
V_5 = F_4 ( V_156 -> V_163 ) -> V_5 ;
F_2 ( V_159 , V_5 ) ;
F_2 ( V_160 , V_5 ) ;
return ( V_159 == V_160 ) ;
}
void
F_80 ( struct V_155 * V_156 ,
struct V_67 * V_158 )
{
F_46 ( V_156 -> V_163 != NULL ) ;
V_156 -> V_163 = F_81 ( V_156 -> V_164 ,
V_158 -> V_165 ,
0 ,
V_114 ,
V_21 ,
V_166 ) ;
if ( V_156 -> V_163 == NULL )
F_82 ( V_156 ) ;
}
void
F_83 ( struct V_155 * V_156 ,
struct V_67 * V_158 )
{
F_46 ( V_156 -> V_163 != NULL ) ;
V_156 -> V_163 = F_81 ( V_156 -> V_164 ,
V_158 -> V_165 ,
0 ,
V_114 ,
V_17 ,
V_167 ) ;
if ( V_156 -> V_163 == NULL )
F_84 ( V_156 ) ;
}
static bool F_85 ( struct V_10 * V_11 )
{
return ! F_4 ( V_11 ) -> V_52 ;
}
static T_2 F_86 ( struct V_1 * V_99 , T_2 V_77 )
{
if ( V_99 -> V_12 == V_13 )
return F_42 ( & V_99 -> V_153 , V_77 ) ;
else
return V_77 ;
}
struct V_152 * F_87 ( struct V_67 * V_158 )
{
struct V_10 * V_11 = V_158 -> V_168 ;
struct V_1 * V_99 = F_4 ( V_11 ) ;
T_2 V_125 , V_77 ;
struct V_152 * V_169 ;
V_77 = F_41 ( V_11 ,
( T_1 ) V_158 -> V_161 << V_162 ) ;
V_125 = F_86 ( V_99 , V_77 ) ;
V_169 = & V_99 -> V_149 [ V_125 ] ;
if ( F_88 ( V_169 ) ) {
F_89 ( V_11 ) ;
}
return V_169 ;
}
static T_2 F_90 ( struct V_10 * V_11 , T_2 V_125 )
{
struct V_1 * V_2 = F_4 ( V_11 ) ;
if ( V_2 -> V_12 == V_13 )
return V_125 ;
else
return F_42 ( V_11 , V_125 ) ;
}
static struct V_79 *
F_91 ( struct V_10 * V_11 , T_2 V_125 )
{
struct V_1 * V_2 = F_4 ( V_11 ) ;
if ( V_2 -> V_12 == V_13 ) {
if ( V_2 -> V_121 == 1 )
V_125 = 0 ;
else if ( V_2 -> V_121 == 0 )
return NULL ;
}
return V_2 -> V_126 [ V_125 ] ;
}
static int F_92 ( struct V_50 * V_46 , int V_170 )
{
struct V_10 * V_11 = V_46 -> V_11 ;
struct V_75 * V_76 ;
T_2 V_78 ;
struct V_79 * V_80 ;
V_78 = F_90 ( V_11 , V_46 -> V_171 ) ;
V_76 = F_43 ( V_11 , V_78 ) ;
if ( ! V_76 ) {
F_48 ( V_94 L_12 , V_18 ) ;
F_8 ( F_9 ( V_17 ) , & V_11 -> V_19 -> V_20 ) ;
F_8 ( F_9 ( V_21 ) , & V_11 -> V_19 -> V_20 ) ;
F_27 ( V_46 ) ;
V_46 -> V_64 -> V_66 ( V_46 ) ;
return - V_44 ;
}
F_7 ( L_27 , V_18 , V_46 -> V_49 -> V_57 , V_170 ) ;
V_46 -> V_95 = F_29 ;
V_46 -> V_47 = V_76 -> V_47 ;
V_80 = F_91 ( V_11 , V_46 -> V_171 ) ;
if ( V_80 )
V_46 -> args . V_80 = V_80 ;
return F_93 ( V_46 , V_76 -> V_47 -> V_90 ,
& V_172 , V_170 ) ;
}
static struct V_10 * F_94 ( struct V_49 * V_49 )
{
struct V_10 * V_11 , * V_173 = NULL ;
F_95 ( & V_49 -> V_174 ) ;
F_96 (lseg, &NFS_I(inode)->layout->plh_segs, pls_list)
if ( V_11 -> V_15 . V_16 == V_17 )
V_173 = F_89 ( V_11 ) ;
F_97 ( & V_49 -> V_174 ) ;
return V_173 ;
}
static int F_98 ( struct V_49 * V_49 , struct V_152 * V_169 )
{
struct V_10 * V_11 ;
struct V_1 * V_99 ;
struct V_50 * V_46 ;
int V_125 , V_77 ;
V_11 = F_94 ( V_49 ) ;
if ( ! V_11 )
return 0 ;
V_99 = F_4 ( V_11 ) ;
for ( V_125 = 0 ; V_125 < V_99 -> V_154 ; V_125 ++ ) {
if ( F_88 ( & V_99 -> V_149 [ V_125 ] ) )
continue;
V_46 = F_99 () ;
if ( ! V_46 )
goto V_175;
V_46 -> V_171 = V_125 ;
V_46 -> V_11 = V_11 ;
F_100 ( & V_46 -> V_69 , V_169 ) ;
}
F_101 ( V_11 ) ;
return 0 ;
V_175:
for ( V_77 = V_125 ; V_77 < V_99 -> V_154 ; V_77 ++ ) {
if ( F_88 ( & V_99 -> V_149 [ V_125 ] ) )
continue;
F_102 ( & V_99 -> V_149 [ V_125 ] , V_11 ) ;
F_101 ( V_11 ) ;
}
F_101 ( V_11 ) ;
return - V_136 ;
}
static int
F_103 ( struct V_49 * V_49 , struct V_152 * V_176 ,
int V_170 )
{
struct V_50 * V_46 , * V_8 ;
F_104 ( V_169 ) ;
if ( ! F_88 ( V_176 ) ) {
V_46 = F_99 () ;
if ( ! V_46 )
goto V_175;
V_46 -> V_11 = NULL ;
F_100 ( & V_46 -> V_69 , & V_169 ) ;
}
if ( F_98 ( V_49 , & V_169 ) )
goto V_175;
F_105 (data, tmp, &list, pages) {
F_106 ( & V_46 -> V_69 ) ;
F_107 ( & F_19 ( V_49 ) -> V_73 ) ;
if ( ! V_46 -> V_11 ) {
F_108 ( V_46 , V_176 , NULL ) ;
F_93 ( V_46 , F_109 ( V_49 ) ,
V_46 -> V_64 , V_170 ) ;
} else {
F_108 ( V_46 , & F_4 ( V_46 -> V_11 ) -> V_149 [ V_46 -> V_171 ] , V_46 -> V_11 ) ;
F_92 ( V_46 , V_170 ) ;
}
}
return 0 ;
V_175:
F_105 (data, tmp, &list, pages) {
F_102 ( & V_46 -> V_69 , V_46 -> V_11 ) ;
F_106 ( & V_46 -> V_69 ) ;
F_110 ( V_46 ) ;
}
F_102 ( V_176 , NULL ) ;
F_36 ( F_19 ( V_49 ) ) ;
return - V_136 ;
}
static void
F_111 ( struct V_105 * V_106 )
{
F_112 ( F_53 ( V_106 , struct V_107 , V_118 ) ) ;
}
static int T_7 F_113 ( void )
{
F_48 ( V_177 L_28 ,
V_18 ) ;
return F_114 ( & V_178 ) ;
}
static void T_8 F_115 ( void )
{
F_48 ( V_177 L_29 ,
V_18 ) ;
F_116 ( & V_178 ) ;
}
