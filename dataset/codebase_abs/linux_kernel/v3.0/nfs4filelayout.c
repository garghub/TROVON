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
( unsigned long ) V_51 -> V_11 -> V_58 ) ;
}
static void F_19 ( struct V_22 * V_23 , void * V_46 )
{
struct V_45 * V_59 = (struct V_45 * ) V_46 ;
V_59 -> V_60 = F_13 ;
if ( F_20 ( V_59 -> V_47 -> V_38 ,
& V_59 -> args . V_61 , & V_59 -> V_53 . V_62 ,
0 , V_23 ) )
return;
F_21 ( V_23 ) ;
}
static void F_22 ( struct V_22 * V_23 , void * V_46 )
{
struct V_45 * V_59 = (struct V_45 * ) V_46 ;
F_7 ( L_9 , V_18 , V_23 -> V_29 ) ;
V_59 -> V_63 -> V_64 ( V_23 , V_46 ) ;
}
static void F_23 ( void * V_46 )
{
struct V_45 * V_59 = (struct V_45 * ) V_46 ;
V_59 -> V_63 -> V_65 ( V_46 ) ;
}
static int F_24 ( struct V_22 * V_23 ,
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
F_25 ( V_23 , V_46 ) ;
V_27 = F_15 ( V_46 -> V_49 ) -> V_26 ;
} else
V_27 = V_46 -> V_47 ;
F_16 ( V_23 , V_27 ) ;
return - V_44 ;
}
F_17 ( V_46 ) ;
return 0 ;
}
static void F_26 ( struct V_50 * V_46 )
{
struct V_66 * V_67 = F_27 ( V_46 -> V_68 . V_69 ) ;
V_46 -> V_23 . V_29 = 0 ;
memcpy ( V_46 -> V_54 . V_70 , V_67 -> V_71 . V_70 ,
sizeof( V_67 -> V_71 . V_70 ) ) ;
V_46 -> V_54 . V_70 [ 0 ] ++ ;
}
static int F_28 ( struct V_22 * V_23 ,
struct V_50 * V_46 )
{
int V_28 = 0 ;
if ( F_10 ( V_23 , V_46 -> args . V_48 -> V_25 ,
V_46 -> V_47 , & V_28 ) == - V_44 ) {
F_7 ( L_7 ,
V_18 , V_46 -> V_47 , V_46 -> V_47 -> V_38 ) ;
if ( V_28 ) {
F_26 ( V_46 ) ;
F_6 ( V_46 -> V_11 ) ;
} else
F_16 ( V_23 , V_46 -> V_47 ) ;
return - V_44 ;
}
return 0 ;
}
static void F_29 ( struct V_22 * V_23 , void * V_46 )
{
struct V_50 * V_51 = (struct V_50 * ) V_46 ;
if ( F_20 ( V_51 -> V_47 -> V_38 ,
& V_51 -> args . V_61 , & V_51 -> V_53 . V_62 ,
0 , V_23 ) )
return;
F_21 ( V_23 ) ;
}
static void F_30 ( struct V_22 * V_23 , void * V_46 )
{
struct V_50 * V_51 = (struct V_50 * ) V_46 ;
V_51 -> V_63 -> V_64 ( V_23 , V_46 ) ;
}
static void F_31 ( void * V_46 )
{
struct V_50 * V_51 = (struct V_50 * ) V_46 ;
V_51 -> V_63 -> V_65 ( V_46 ) ;
}
static void F_32 ( void * V_46 )
{
struct V_50 * V_51 = (struct V_50 * ) V_46 ;
F_33 ( V_51 ) ;
if ( F_34 ( & F_35 ( V_51 -> V_49 ) -> V_72 ) )
F_36 ( F_35 ( V_51 -> V_49 ) ) ;
F_37 ( V_51 ) ;
}
static enum V_73
F_38 ( struct V_45 * V_46 )
{
struct V_10 * V_11 = V_46 -> V_11 ;
struct V_74 * V_75 ;
T_1 V_3 = V_46 -> args . V_3 ;
T_2 V_76 , V_77 ;
struct V_78 * V_79 ;
int V_80 ;
F_7 ( L_10 ,
V_18 , V_46 -> V_49 -> V_57 ,
V_46 -> args . V_81 , ( V_82 ) V_46 -> args . V_83 , V_3 ) ;
V_76 = F_39 ( V_11 , V_3 ) ;
V_77 = F_40 ( V_11 , V_76 ) ;
V_75 = F_41 ( V_11 , V_77 ) ;
if ( ! V_75 ) {
F_8 ( F_9 ( V_17 ) , & V_11 -> V_19 -> V_20 ) ;
F_8 ( F_9 ( V_21 ) , & V_11 -> V_19 -> V_20 ) ;
return V_84 ;
}
F_7 ( L_11 , V_18 ,
F_42 ( V_75 -> V_85 ) , F_43 ( V_75 -> V_86 ) ) ;
V_46 -> V_47 = V_75 -> V_47 ;
V_79 = F_44 ( V_11 , V_76 ) ;
if ( V_79 )
V_46 -> args . V_79 = V_79 ;
V_46 -> args . V_3 = F_3 ( V_11 , V_3 ) ;
V_46 -> V_87 = V_3 ;
V_80 = F_45 ( V_46 , V_75 -> V_47 -> V_88 ,
& V_89 ) ;
F_46 ( V_80 != 0 ) ;
return V_90 ;
}
static enum V_73
F_47 ( struct V_50 * V_46 , int V_91 )
{
struct V_10 * V_11 = V_46 -> V_11 ;
struct V_74 * V_75 ;
T_1 V_3 = V_46 -> args . V_3 ;
T_2 V_76 , V_77 ;
struct V_78 * V_79 ;
int V_80 ;
V_76 = F_39 ( V_11 , V_3 ) ;
V_77 = F_40 ( V_11 , V_76 ) ;
V_75 = F_41 ( V_11 , V_77 ) ;
if ( ! V_75 ) {
F_48 ( V_92 L_12 , V_18 ) ;
F_8 ( F_9 ( V_17 ) , & V_11 -> V_19 -> V_20 ) ;
F_8 ( F_9 ( V_21 ) , & V_11 -> V_19 -> V_20 ) ;
return V_84 ;
}
F_7 ( L_13 , V_18 ,
V_46 -> V_49 -> V_57 , V_91 , ( V_82 ) V_46 -> args . V_83 , V_3 ,
F_42 ( V_75 -> V_85 ) , F_43 ( V_75 -> V_86 ) ) ;
V_46 -> V_93 = F_24 ;
V_46 -> V_47 = V_75 -> V_47 ;
V_79 = F_44 ( V_11 , V_76 ) ;
if ( V_79 )
V_46 -> args . V_79 = V_79 ;
V_46 -> args . V_3 = F_3 ( V_11 , V_3 ) ;
V_80 = F_49 ( V_46 , V_75 -> V_47 -> V_88 ,
& V_94 , V_91 ) ;
F_46 ( V_80 != 0 ) ;
return V_90 ;
}
static int
F_50 ( struct V_95 * V_96 ,
struct V_1 * V_97 ,
struct V_98 * V_99 ,
struct V_100 * V_101 ,
T_4 V_102 )
{
struct V_103 * V_104 ;
struct V_105 * V_6 ;
int V_80 = - V_106 ;
struct V_107 * V_108 = F_15 ( V_96 -> V_109 ) ;
F_7 ( L_14 , V_18 ) ;
if ( V_97 -> V_9 > V_99 -> V_110 . V_3 ) {
F_7 ( L_15 ,
V_18 , V_97 -> V_9 ) ;
goto V_111;
}
if ( ! V_97 -> V_5 || V_97 -> V_5 % V_112 ) {
F_7 ( L_16 ,
V_18 , V_97 -> V_5 ) ;
goto V_111;
}
V_104 = F_51 ( F_15 ( V_96 -> V_109 ) -> V_113 ,
F_15 ( V_96 -> V_109 ) -> V_26 , V_101 ) ;
if ( V_104 == NULL ) {
V_6 = F_52 ( V_96 -> V_109 , V_101 , V_102 ) ;
if ( V_6 == NULL )
goto V_111;
} else
V_6 = F_53 ( V_104 , struct V_105 , V_114 ) ;
V_97 -> V_6 = V_6 ;
if ( V_97 -> V_115 < 0 ||
V_97 -> V_115 >= V_6 -> V_7 ) {
F_7 ( L_17 ,
V_18 , V_97 -> V_115 ) ;
goto V_116;
}
if ( ( V_97 -> V_12 == V_13 &&
V_97 -> V_117 > 1 && V_97 -> V_117 != V_6 -> V_118 ) ||
( V_97 -> V_12 == V_14 &&
V_97 -> V_117 != V_6 -> V_7 ) ) {
F_7 ( L_18 ,
V_18 , V_97 -> V_117 ) ;
goto V_116;
}
if ( V_97 -> V_5 % V_108 -> V_119 || V_97 -> V_5 % V_108 -> V_120 ) {
F_7 ( L_19
L_20 , V_18 , V_97 -> V_5 , V_108 -> V_119 ,
V_108 -> V_120 ) ;
}
V_80 = 0 ;
V_111:
F_7 ( L_21 , V_18 , V_80 ) ;
return V_80 ;
V_116:
F_54 ( V_6 ) ;
goto V_111;
}
static void F_55 ( struct V_1 * V_97 )
{
int V_121 ;
for ( V_121 = 0 ; V_121 < V_97 -> V_117 ; V_121 ++ ) {
if ( ! V_97 -> V_122 [ V_121 ] )
break;
F_56 ( V_97 -> V_122 [ V_121 ] ) ;
}
F_56 ( V_97 -> V_122 ) ;
V_97 -> V_122 = NULL ;
}
static void
F_57 ( struct V_1 * V_97 )
{
F_55 ( V_97 ) ;
F_56 ( V_97 ) ;
}
static int
F_58 ( struct V_95 * V_123 ,
struct V_1 * V_97 ,
struct V_98 * V_99 ,
struct V_100 * V_101 ,
T_4 V_102 )
{
struct V_124 V_125 ;
struct V_126 V_127 ;
struct V_128 * V_129 ;
T_5 * V_130 ;
T_6 V_131 ;
int V_121 ;
F_7 ( L_22 , V_18 ) ;
V_129 = F_59 ( V_102 ) ;
if ( ! V_129 )
return - V_132 ;
F_60 ( & V_125 , & V_127 , V_99 -> V_133 -> V_68 , V_99 -> V_133 -> V_134 ) ;
F_61 ( & V_125 , F_62 ( V_129 ) , V_112 ) ;
V_130 = F_63 ( & V_125 , V_135 + 20 ) ;
if ( F_64 ( ! V_130 ) )
goto V_136;
memcpy ( V_101 , V_130 , sizeof( * V_101 ) ) ;
V_130 += F_65 ( V_135 ) ;
F_66 ( V_101 ) ;
V_131 = F_67 ( V_130 ++ ) ;
if ( V_131 & V_137 )
V_97 -> V_52 = 1 ;
if ( V_131 & V_138 )
V_97 -> V_12 = V_14 ;
else
V_97 -> V_12 = V_13 ;
V_97 -> V_5 = V_131 & ~ V_139 ;
V_97 -> V_115 = F_67 ( V_130 ++ ) ;
V_130 = F_68 ( V_130 , & V_97 -> V_9 ) ;
V_97 -> V_117 = F_67 ( V_130 ++ ) ;
F_7 ( L_23 ,
V_18 , V_131 , V_97 -> V_117 , V_97 -> V_115 ,
V_97 -> V_9 ) ;
if ( V_97 -> V_117 < 0 || V_97 -> V_117 >
F_69 ( V_140 , V_141 ) )
goto V_136;
if ( V_97 -> V_117 > 0 ) {
V_97 -> V_122 = F_70 ( V_97 -> V_117 * sizeof( struct V_78 * ) ,
V_102 ) ;
if ( ! V_97 -> V_122 )
goto V_136;
}
for ( V_121 = 0 ; V_121 < V_97 -> V_117 ; V_121 ++ ) {
V_97 -> V_122 [ V_121 ] = F_71 ( sizeof( struct V_78 ) , V_102 ) ;
if ( ! V_97 -> V_122 [ V_121 ] )
goto V_142;
V_130 = F_63 ( & V_125 , 4 ) ;
if ( F_64 ( ! V_130 ) )
goto V_142;
V_97 -> V_122 [ V_121 ] -> V_143 = F_67 ( V_130 ++ ) ;
if ( sizeof( struct V_78 ) < V_97 -> V_122 [ V_121 ] -> V_143 ) {
F_48 ( V_92 L_24 ,
V_121 , V_97 -> V_122 [ V_121 ] -> V_143 ) ;
goto V_142;
}
V_130 = F_63 ( & V_125 , V_97 -> V_122 [ V_121 ] -> V_143 ) ;
if ( F_64 ( ! V_130 ) )
goto V_142;
memcpy ( V_97 -> V_122 [ V_121 ] -> V_46 , V_130 , V_97 -> V_122 [ V_121 ] -> V_143 ) ;
F_7 ( L_25 , V_18 ,
V_97 -> V_122 [ V_121 ] -> V_143 ) ;
}
F_72 ( V_129 ) ;
return 0 ;
V_142:
F_55 ( V_97 ) ;
V_136:
F_72 ( V_129 ) ;
return - V_144 ;
}
static void
F_73 ( struct V_10 * V_11 )
{
struct V_1 * V_97 = F_4 ( V_11 ) ;
F_7 ( L_14 , V_18 ) ;
F_54 ( V_97 -> V_6 ) ;
F_56 ( V_97 -> V_145 ) ;
F_57 ( V_97 ) ;
}
static struct V_10 *
F_74 ( struct V_95 * V_146 ,
struct V_98 * V_99 ,
T_4 V_102 )
{
struct V_1 * V_97 ;
int V_147 ;
struct V_100 V_101 ;
F_7 ( L_14 , V_18 ) ;
V_97 = F_70 ( sizeof( * V_97 ) , V_102 ) ;
if ( ! V_97 )
return NULL ;
V_147 = F_58 ( V_146 , V_97 , V_99 , & V_101 , V_102 ) ;
if ( V_147 != 0 || F_50 ( V_146 , V_97 , V_99 , & V_101 , V_102 ) ) {
F_57 ( V_97 ) ;
return NULL ;
}
if ( ( ! V_97 -> V_52 ) && ( V_99 -> V_110 . V_16 == V_17 ) ) {
int V_121 ;
int V_143 = ( V_97 -> V_12 == V_13 ) ?
V_97 -> V_6 -> V_118 : V_97 -> V_6 -> V_7 ;
V_97 -> V_145 = F_75 ( V_143 , sizeof( struct V_148 ) , V_102 ) ;
if ( ! V_97 -> V_145 ) {
F_73 ( & V_97 -> V_149 ) ;
return NULL ;
}
V_97 -> V_150 = V_143 ;
for ( V_121 = 0 ; V_121 < V_143 ; V_121 ++ )
F_76 ( & V_97 -> V_145 [ V_121 ] ) ;
}
return & V_97 -> V_149 ;
}
bool
F_77 ( struct V_151 * V_152 , struct V_66 * V_153 ,
struct V_66 * V_154 )
{
T_3 V_155 , V_156 ;
T_2 V_5 ;
if ( ! F_78 ( V_152 , V_153 , V_154 ) ||
! F_79 ( V_152 , V_153 , V_154 ) )
return false ;
if ( ! V_152 -> V_157 )
return 1 ;
V_155 = ( T_3 ) V_153 -> V_158 << V_159 ;
V_156 = ( T_3 ) V_154 -> V_158 << V_159 ;
V_5 = F_4 ( V_152 -> V_157 ) -> V_5 ;
F_2 ( V_155 , V_5 ) ;
F_2 ( V_156 , V_5 ) ;
return ( V_155 == V_156 ) ;
}
static bool F_80 ( struct V_10 * V_11 )
{
return ! F_4 ( V_11 ) -> V_52 ;
}
static T_2 F_81 ( struct V_1 * V_97 , T_2 V_76 )
{
if ( V_97 -> V_12 == V_13 )
return F_40 ( & V_97 -> V_149 , V_76 ) ;
else
return V_76 ;
}
struct V_148 * F_82 ( struct V_66 * V_154 )
{
struct V_10 * V_11 = V_154 -> V_160 ;
struct V_1 * V_97 = F_4 ( V_11 ) ;
T_2 V_121 , V_76 ;
struct V_148 * V_161 ;
V_76 = F_39 ( V_11 ,
( T_1 ) V_154 -> V_158 << V_159 ) ;
V_121 = F_81 ( V_97 , V_76 ) ;
V_161 = & V_97 -> V_145 [ V_121 ] ;
if ( F_83 ( V_161 ) ) {
F_84 ( V_11 ) ;
}
return V_161 ;
}
static T_2 F_85 ( struct V_10 * V_11 , T_2 V_121 )
{
struct V_1 * V_2 = F_4 ( V_11 ) ;
if ( V_2 -> V_12 == V_13 )
return V_121 ;
else
return F_40 ( V_11 , V_121 ) ;
}
static struct V_78 *
F_86 ( struct V_10 * V_11 , T_2 V_121 )
{
struct V_1 * V_2 = F_4 ( V_11 ) ;
if ( V_2 -> V_12 == V_13 ) {
if ( V_2 -> V_117 == 1 )
V_121 = 0 ;
else if ( V_2 -> V_117 == 0 )
return NULL ;
}
return V_2 -> V_122 [ V_121 ] ;
}
static int F_87 ( struct V_50 * V_46 , int V_162 )
{
struct V_10 * V_11 = V_46 -> V_11 ;
struct V_74 * V_75 ;
T_2 V_77 ;
struct V_78 * V_79 ;
V_77 = F_85 ( V_11 , V_46 -> V_163 ) ;
V_75 = F_41 ( V_11 , V_77 ) ;
if ( ! V_75 ) {
F_48 ( V_92 L_12 , V_18 ) ;
F_8 ( F_9 ( V_17 ) , & V_11 -> V_19 -> V_20 ) ;
F_8 ( F_9 ( V_21 ) , & V_11 -> V_19 -> V_20 ) ;
F_26 ( V_46 ) ;
V_46 -> V_63 -> V_65 ( V_46 ) ;
return - V_44 ;
}
F_7 ( L_26 , V_18 , V_46 -> V_49 -> V_57 , V_162 ) ;
V_46 -> V_93 = F_28 ;
V_46 -> V_47 = V_75 -> V_47 ;
V_79 = F_86 ( V_11 , V_46 -> V_163 ) ;
if ( V_79 )
V_46 -> args . V_79 = V_79 ;
return F_88 ( V_46 , V_75 -> V_47 -> V_88 ,
& V_164 , V_162 ) ;
}
static struct V_10 * F_89 ( struct V_49 * V_49 )
{
struct V_10 * V_11 , * V_165 = NULL ;
F_90 ( & V_49 -> V_166 ) ;
F_91 (lseg, &NFS_I(inode)->layout->plh_segs, pls_list)
if ( V_11 -> V_15 . V_16 == V_17 )
V_165 = F_84 ( V_11 ) ;
F_92 ( & V_49 -> V_166 ) ;
return V_165 ;
}
static int F_93 ( struct V_49 * V_49 , struct V_148 * V_161 )
{
struct V_10 * V_11 ;
struct V_1 * V_97 ;
struct V_50 * V_46 ;
int V_121 , V_76 ;
V_11 = F_89 ( V_49 ) ;
if ( ! V_11 )
return 0 ;
V_97 = F_4 ( V_11 ) ;
for ( V_121 = 0 ; V_121 < V_97 -> V_150 ; V_121 ++ ) {
if ( F_83 ( & V_97 -> V_145 [ V_121 ] ) )
continue;
V_46 = F_94 () ;
if ( ! V_46 )
goto V_167;
V_46 -> V_163 = V_121 ;
V_46 -> V_11 = V_11 ;
F_95 ( & V_46 -> V_68 , V_161 ) ;
}
F_96 ( V_11 ) ;
return 0 ;
V_167:
for ( V_76 = V_121 ; V_76 < V_97 -> V_150 ; V_76 ++ ) {
if ( F_83 ( & V_97 -> V_145 [ V_121 ] ) )
continue;
F_97 ( & V_97 -> V_145 [ V_121 ] , V_11 ) ;
F_96 ( V_11 ) ;
}
F_96 ( V_11 ) ;
return - V_132 ;
}
static int
F_98 ( struct V_49 * V_49 , struct V_148 * V_168 ,
int V_162 )
{
struct V_50 * V_46 , * V_8 ;
F_99 ( V_161 ) ;
if ( ! F_83 ( V_168 ) ) {
V_46 = F_94 () ;
if ( ! V_46 )
goto V_167;
V_46 -> V_11 = NULL ;
F_95 ( & V_46 -> V_68 , & V_161 ) ;
}
if ( F_93 ( V_49 , & V_161 ) )
goto V_167;
F_100 (data, tmp, &list, pages) {
F_101 ( & V_46 -> V_68 ) ;
F_102 ( & F_35 ( V_49 ) -> V_72 ) ;
if ( ! V_46 -> V_11 ) {
F_103 ( V_46 , V_168 , NULL ) ;
F_88 ( V_46 , F_104 ( V_49 ) ,
V_46 -> V_63 , V_162 ) ;
} else {
F_103 ( V_46 , & F_4 ( V_46 -> V_11 ) -> V_145 [ V_46 -> V_163 ] , V_46 -> V_11 ) ;
F_87 ( V_46 , V_162 ) ;
}
}
return 0 ;
V_167:
F_100 (data, tmp, &list, pages) {
F_97 ( & V_46 -> V_68 , V_46 -> V_11 ) ;
F_101 ( & V_46 -> V_68 ) ;
F_105 ( V_46 ) ;
}
F_97 ( V_168 , NULL ) ;
F_36 ( F_35 ( V_49 ) ) ;
return - V_132 ;
}
static void
F_106 ( struct V_103 * V_104 )
{
F_107 ( F_53 ( V_104 , struct V_105 , V_114 ) ) ;
}
static int T_7 F_108 ( void )
{
F_48 ( V_169 L_27 ,
V_18 ) ;
return F_109 ( & V_170 ) ;
}
static void T_8 F_110 ( void )
{
F_48 ( V_169 L_28 ,
V_18 ) ;
F_111 ( & V_170 ) ;
}
