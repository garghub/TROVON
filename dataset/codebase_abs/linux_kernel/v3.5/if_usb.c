static void F_1 ( struct V_1 * V_1 )
{
struct V_2 * V_3 = (struct V_2 * ) V_1 -> V_4 ;
if ( V_1 -> V_5 == 0 ) {
struct V_6 * V_7 = V_3 -> V_7 ;
F_2 ( & V_1 -> V_8 -> V_8 , L_1 ) ;
F_2 ( & V_1 -> V_8 -> V_8 , L_2 ,
V_1 -> V_9 ) ;
if ( V_7 && V_7 -> V_10 != V_11 )
F_3 ( V_7 ) ;
} else {
F_4 ( L_3 , V_1 -> V_5 ) ;
}
}
static void F_5 ( struct V_2 * V_3 )
{
F_6 ( V_12 ) ;
F_7 ( V_3 -> V_13 ) ;
F_7 ( V_3 -> V_14 ) ;
F_8 ( V_3 -> V_13 ) ;
V_3 -> V_13 = NULL ;
F_8 ( V_3 -> V_14 ) ;
V_3 -> V_14 = NULL ;
F_9 ( V_3 -> V_15 ) ;
V_3 -> V_15 = NULL ;
F_10 ( V_12 ) ;
}
static void F_11 ( struct V_6 * V_7 )
{
struct V_2 * V_3 = V_7 -> V_16 ;
struct V_17 V_18 ;
struct V_19 V_20 ;
V_18 . V_21 . V_22 = F_12 ( sizeof( V_18 ) ) ;
V_18 . V_23 = 0 ;
V_18 . V_24 = V_3 -> V_25 ;
if ( F_13 ( V_7 , V_26 , & V_18 ) )
F_14 ( L_4 ) ;
V_7 -> V_27 = 2 ;
V_7 -> V_28 = 20 ;
F_15 ( V_7 , V_29 ,
(struct V_30 * ) NULL ) ;
V_20 . V_21 . V_22 = F_12 ( sizeof( V_20 ) ) ;
V_20 . V_23 = F_12 ( V_31 ) ;
if ( F_13 ( V_7 , V_32 , & V_20 ) ) {
F_16 ( V_7 -> V_8 , L_5 ) ;
V_7 -> V_33 &= ~ V_34 ;
} else {
if ( F_17 ( V_20 . V_35 ) == V_36 ) {
F_14 ( L_6 ) ;
} else {
V_7 -> V_33 &= ~ V_34 ;
F_16 ( V_7 -> V_8 ,
L_7 ) ;
}
}
}
static void F_18 ( unsigned long V_7 )
{
struct V_2 * V_3 = ( void * ) V_7 ;
if ( V_3 -> V_37 ) {
F_14 ( L_8 ) ;
} else {
F_19 ( L_9 ) ;
V_3 -> V_38 = 1 ;
}
F_20 ( & V_3 -> V_39 ) ;
}
static void F_21 ( struct V_6 * V_7 )
{
F_22 ( V_40 L_10 ) ;
F_23 ( 0x25 , NULL , 0 , NULL , 0 ) ;
}
static int F_24 ( struct V_41 * V_42 ,
const struct V_43 * V_44 )
{
struct V_45 * V_46 ;
struct V_47 * V_48 ;
struct V_49 * V_50 ;
struct V_6 * V_7 ;
struct V_2 * V_3 ;
int V_51 = - V_52 ;
int V_53 ;
V_46 = F_25 ( V_42 ) ;
V_3 = F_26 ( sizeof( struct V_2 ) , V_54 ) ;
if ( ! V_3 )
goto error;
F_27 ( & V_3 -> V_55 , F_18 , ( unsigned long ) V_3 ) ;
F_28 ( & V_3 -> V_39 ) ;
V_3 -> V_46 = V_46 ;
V_3 -> V_56 = ( V_57 ) V_44 -> V_58 ;
V_48 = V_42 -> V_59 ;
F_29 ( & V_46 -> V_8 , L_11
L_12 ,
F_17 ( V_46 -> V_60 . V_61 ) ,
V_46 -> V_60 . V_62 ,
V_46 -> V_60 . V_63 ,
V_46 -> V_60 . V_64 ) ;
for ( V_53 = 0 ; V_53 < V_48 -> V_65 . V_66 ; ++ V_53 ) {
V_50 = & V_48 -> V_50 [ V_53 ] . V_65 ;
if ( F_30 ( V_50 ) ) {
V_3 -> V_67 = F_17 ( V_50 -> V_68 ) ;
V_3 -> V_69 = F_31 ( V_50 ) ;
F_29 ( & V_46 -> V_8 , L_13 , V_3 -> V_69 ) ;
F_29 ( & V_46 -> V_8 , L_14 , V_3 -> V_67 ) ;
} else if ( F_32 ( V_50 ) ) {
V_3 -> V_70 = F_17 ( V_50 -> V_68 ) ;
V_3 -> V_71 = F_31 ( V_50 ) ;
F_29 ( & V_46 -> V_8 , L_15 , V_3 -> V_71 ) ;
F_29 ( & V_46 -> V_8 , L_16 , V_3 -> V_70 ) ;
}
}
if ( ! V_3 -> V_70 || ! V_3 -> V_67 ) {
F_29 ( & V_46 -> V_8 , L_17 ) ;
goto V_72;
}
if ( ! ( V_3 -> V_14 = F_33 ( 0 , V_54 ) ) ) {
F_29 ( & V_46 -> V_8 , L_18 ) ;
goto V_72;
}
if ( ! ( V_3 -> V_13 = F_33 ( 0 , V_54 ) ) ) {
F_29 ( & V_46 -> V_8 , L_19 ) ;
goto V_72;
}
V_3 -> V_15 = F_34 ( V_73 , V_54 ) ;
if ( ! V_3 -> V_15 ) {
F_29 ( & V_46 -> V_8 , L_20 ) ;
goto V_72;
}
if ( ! ( V_7 = F_35 ( V_3 , & V_42 -> V_8 ) ) )
goto V_74;
V_3 -> V_7 = V_7 ;
V_7 -> V_75 = V_76 ;
V_7 -> V_77 = NULL ;
V_7 -> V_78 = NULL ;
V_7 -> V_79 = NULL ;
#ifdef F_36
if ( F_37 () )
V_7 -> V_80 = F_21 ;
#endif
V_3 -> V_25 = V_46 -> V_60 . V_81 ;
F_38 ( V_46 ) ;
F_39 ( V_42 , V_3 ) ;
V_51 = F_40 ( V_7 , & V_46 -> V_8 , V_3 -> V_56 ,
V_82 , V_83 ) ;
if ( V_51 )
goto V_84;
return 0 ;
V_84:
F_41 ( V_7 ) ;
V_74:
F_42 ( V_3 ) ;
V_72:
F_5 ( V_3 ) ;
error:
return V_51 ;
}
static void F_43 ( struct V_41 * V_42 )
{
struct V_2 * V_3 = F_44 ( V_42 ) ;
struct V_6 * V_7 = (struct V_6 * ) V_3 -> V_7 ;
F_6 ( V_85 ) ;
V_3 -> V_38 = 1 ;
if ( V_7 ) {
V_7 -> V_86 = 1 ;
F_45 ( V_7 ) ;
F_41 ( V_7 ) ;
}
F_5 ( V_3 ) ;
F_39 ( V_42 , NULL ) ;
F_46 ( F_25 ( V_42 ) ) ;
F_10 ( V_85 ) ;
}
static int F_47 ( struct V_2 * V_3 )
{
struct V_87 * V_87 = V_3 -> V_15 ;
const T_1 * V_88 = V_3 -> V_89 -> V_90 ;
if ( ! V_3 -> V_91 ) {
V_3 -> V_92 = V_3 -> V_93 ;
V_3 -> V_94 -- ;
}
F_2 ( & V_3 -> V_46 -> V_8 , L_21 ,
V_3 -> V_92 ) ;
memcpy ( & V_87 -> V_21 , & V_88 [ V_3 -> V_92 ] ,
sizeof( struct V_95 ) ) ;
V_3 -> V_93 = V_3 -> V_92 ;
V_3 -> V_92 += sizeof( struct V_95 ) ;
memcpy ( V_87 -> V_90 , & V_88 [ V_3 -> V_92 ] ,
F_48 ( V_87 -> V_21 . V_96 ) ) ;
F_2 ( & V_3 -> V_46 -> V_8 , L_22 ,
F_48 ( V_87 -> V_21 . V_96 ) ) ;
V_87 -> V_97 = F_49 ( ++ V_3 -> V_94 ) ;
V_3 -> V_92 += F_48 ( V_87 -> V_21 . V_96 ) ;
F_50 ( V_3 , V_3 -> V_15 , sizeof( struct V_87 ) +
F_48 ( V_87 -> V_21 . V_96 ) ) ;
if ( V_87 -> V_21 . V_98 == F_49 ( V_99 ) ) {
F_2 ( & V_3 -> V_46 -> V_8 , L_23 ) ;
F_2 ( & V_3 -> V_46 -> V_8 , L_24 ,
V_3 -> V_94 , V_3 -> V_92 ) ;
} else if ( V_87 -> V_21 . V_98 == F_49 ( V_100 ) ) {
F_2 ( & V_3 -> V_46 -> V_8 , L_25 ) ;
F_2 ( & V_3 -> V_46 -> V_8 , L_26 ) ;
V_3 -> V_101 = 1 ;
}
F_2 ( & V_3 -> V_46 -> V_8 , L_27 ,
V_3 -> V_92 ) ;
return 0 ;
}
static int F_42 ( struct V_2 * V_3 )
{
struct V_102 * V_103 = V_3 -> V_15 + 4 ;
int V_104 ;
F_6 ( V_12 ) ;
* ( V_105 * ) V_3 -> V_15 = F_49 ( V_106 ) ;
V_103 -> V_107 = F_12 ( V_108 ) ;
V_103 -> V_22 = F_12 ( sizeof( V_103 ) ) ;
V_103 -> V_109 = F_12 ( 0 ) ;
V_103 -> V_97 = F_12 ( 0x5a5a ) ;
F_50 ( V_3 , V_3 -> V_15 , 4 + sizeof( struct V_102 ) ) ;
F_51 ( 100 ) ;
V_104 = F_52 ( V_3 -> V_46 ) ;
F_51 ( 100 ) ;
#ifdef F_36
if ( V_104 && F_37 () )
F_21 ( NULL ) ;
#endif
F_53 ( V_12 , L_28 , V_104 ) ;
return V_104 ;
}
static int F_50 ( struct V_2 * V_3 , T_1 * V_110 , T_2 V_111 )
{
int V_104 ;
if ( V_3 -> V_38 ) {
F_29 ( & V_3 -> V_46 -> V_8 , L_29 ) ;
V_104 = - V_112 ;
goto V_113;
}
F_54 ( V_3 -> V_13 , V_3 -> V_46 ,
F_55 ( V_3 -> V_46 ,
V_3 -> V_71 ) ,
V_110 , V_111 , F_1 , V_3 ) ;
V_3 -> V_13 -> V_114 |= V_115 ;
if ( ( V_104 = F_56 ( V_3 -> V_13 , V_116 ) ) ) {
F_29 ( & V_3 -> V_46 -> V_8 , L_30 , V_104 ) ;
} else {
F_2 ( & V_3 -> V_46 -> V_8 , L_31 ) ;
V_104 = 0 ;
}
V_113:
return V_104 ;
}
static int F_57 ( struct V_2 * V_3 ,
void (* F_58)( struct V_1 * V_1 ) )
{
struct V_117 * V_118 ;
int V_104 = - 1 ;
if ( ! ( V_118 = F_59 ( V_119 ) ) ) {
F_19 ( L_32 ) ;
goto V_120;
}
V_3 -> V_121 = V_118 ;
F_54 ( V_3 -> V_14 , V_3 -> V_46 ,
F_60 ( V_3 -> V_46 , V_3 -> V_69 ) ,
V_118 -> V_90 + V_122 ,
V_119 , F_58 ,
V_3 ) ;
V_3 -> V_14 -> V_114 |= V_115 ;
F_2 ( & V_3 -> V_46 -> V_8 , L_33 , V_3 -> V_14 ) ;
if ( ( V_104 = F_56 ( V_3 -> V_14 , V_116 ) ) ) {
F_29 ( & V_3 -> V_46 -> V_8 , L_34 , V_104 ) ;
F_61 ( V_118 ) ;
V_3 -> V_121 = NULL ;
V_104 = - 1 ;
} else {
F_2 ( & V_3 -> V_46 -> V_8 , L_35 ) ;
V_104 = 0 ;
}
V_120:
return V_104 ;
}
static int F_62 ( struct V_2 * V_3 )
{
return F_57 ( V_3 , & V_123 ) ;
}
static int F_63 ( struct V_2 * V_3 )
{
return F_57 ( V_3 , & V_124 ) ;
}
static void V_123 ( struct V_1 * V_1 )
{
struct V_2 * V_3 = V_1 -> V_4 ;
struct V_117 * V_118 = V_3 -> V_121 ;
struct V_125 * V_126 ;
struct V_127 V_127 ;
if ( V_1 -> V_5 ) {
F_29 ( & V_3 -> V_46 -> V_8 ,
L_36 ) ;
F_61 ( V_118 ) ;
return;
}
if ( V_3 -> V_37 ) {
V_105 * V_128 = ( V_105 * ) ( V_118 -> V_90 + V_122 ) ;
if ( V_128 [ 0 ] == F_49 ( V_129 ) &&
V_128 [ 1 ] == F_49 ( V_130 ) ) {
F_4 ( L_37 ) ;
F_20 ( & V_3 -> V_39 ) ;
} else {
F_14 ( L_38 ,
F_48 ( V_128 [ 0 ] ) , F_48 ( V_128 [ 1 ] ) ) ;
F_62 ( V_3 ) ;
}
F_61 ( V_118 ) ;
return;
}
if ( V_3 -> V_127 <= 0 ) {
memcpy ( & V_127 , V_118 -> V_90 + V_122 ,
sizeof( V_127 ) ) ;
if ( F_17 ( V_3 -> V_46 -> V_60 . V_81 ) < 0x3106 ) {
F_61 ( V_118 ) ;
F_62 ( V_3 ) ;
V_3 -> V_127 = V_131 ;
F_29 ( & V_3 -> V_46 -> V_8 ,
L_39 ) ;
return;
}
if ( V_127 . V_132 != F_49 ( V_133 ) ) {
if ( V_127 . V_132 == F_49 ( V_106 ) ||
V_127 . V_132 == F_49 ( V_134 ) ||
V_127 . V_132 == F_49 ( V_129 ) ) {
if ( ! V_3 -> V_127 )
F_4 ( L_40 ) ;
V_3 -> V_127 = - 1 ;
} else {
F_4 ( L_41 ,
F_48 ( V_127 . V_132 ) ) ;
}
} else if ( ( V_127 . V_103 != V_135 ) &&
( V_127 . V_103 != V_136 ) &&
( V_127 . V_103 != V_137 ) ) {
F_4 ( L_42 ,
V_127 . V_103 ) ;
} else if ( V_127 . V_109 != V_131 ) {
F_4 ( L_43 ,
V_127 . V_109 ) ;
} else {
V_3 -> V_127 = 1 ;
F_29 ( & V_3 -> V_46 -> V_8 ,
L_39 ) ;
}
F_61 ( V_118 ) ;
F_62 ( V_3 ) ;
return;
}
V_126 = F_64 ( V_118 -> V_90 + V_122 ,
sizeof( struct V_125 ) , V_116 ) ;
if ( ! V_126 ) {
F_29 ( & V_3 -> V_46 -> V_8 , L_44 ) ;
F_61 ( V_118 ) ;
return;
}
if ( ! V_126 -> V_103 ) {
F_2 ( & V_3 -> V_46 -> V_8 , L_45 ) ;
F_2 ( & V_3 -> V_46 -> V_8 , L_46 ,
F_48 ( V_126 -> V_97 ) ) ;
V_3 -> V_91 = 1 ;
} else {
F_29 ( & V_3 -> V_46 -> V_8 , L_47 ) ;
V_3 -> V_91 = 0 ;
}
F_61 ( V_118 ) ;
F_65 ( & V_3 -> V_55 , V_138 + ( V_139 * 5 ) ) ;
if ( V_3 -> V_101 ) {
V_3 -> V_37 = 1 ;
goto exit;
}
F_47 ( V_3 ) ;
exit:
F_62 ( V_3 ) ;
F_9 ( V_126 ) ;
}
static inline void F_66 ( int V_140 , struct V_117 * V_118 ,
struct V_2 * V_3 ,
struct V_6 * V_7 )
{
if ( V_140 > V_119 + V_141
|| V_140 < V_142 ) {
F_29 ( & V_3 -> V_46 -> V_8 , L_48 ) ;
F_61 ( V_118 ) ;
return;
}
F_67 ( V_118 , V_122 ) ;
F_68 ( V_118 , V_140 ) ;
F_69 ( V_118 , V_141 ) ;
F_70 ( V_7 , V_118 ) ;
}
static inline void F_71 ( int V_140 , T_1 * V_143 ,
struct V_117 * V_118 ,
struct V_2 * V_3 ,
struct V_6 * V_7 )
{
T_3 V_53 ;
if ( V_140 > V_144 ) {
F_29 ( & V_3 -> V_46 -> V_8 ,
L_49 ) ;
F_61 ( V_118 ) ;
return;
}
F_72 ( ! F_73 () ) ;
F_74 ( & V_7 -> V_145 ) ;
V_53 = ( V_7 -> V_146 == 0 ) ? 1 : 0 ;
F_72 ( V_7 -> V_147 [ V_53 ] ) ;
V_7 -> V_147 [ V_53 ] = ( V_140 - V_141 ) ;
memcpy ( V_7 -> V_148 [ V_53 ] , V_143 + V_141 ,
V_7 -> V_147 [ V_53 ] ) ;
F_61 ( V_118 ) ;
F_75 ( V_7 , V_53 ) ;
F_76 ( & V_7 -> V_145 ) ;
F_29 ( & V_3 -> V_46 -> V_8 ,
L_50 ) ;
}
static void V_124 ( struct V_1 * V_1 )
{
struct V_2 * V_3 = V_1 -> V_4 ;
struct V_117 * V_118 = V_3 -> V_121 ;
struct V_6 * V_7 = V_3 -> V_7 ;
int V_140 = V_1 -> V_9 ;
T_1 * V_143 = NULL ;
V_57 V_149 = 0 ;
V_105 * V_150 = ( V_105 * ) ( V_118 -> V_90 + V_122 ) ;
V_57 V_151 ;
F_6 ( V_12 ) ;
if ( V_140 ) {
if ( V_1 -> V_5 ) {
F_29 ( & V_3 -> V_46 -> V_8 , L_51 ,
V_1 -> V_5 ) ;
F_61 ( V_118 ) ;
goto V_152;
}
V_143 = V_118 -> V_90 + V_122 ;
V_149 = F_48 ( V_150 [ 0 ] ) ;
F_29 ( & V_3 -> V_46 -> V_8 ,
L_52 ,
V_140 , V_149 ) ;
} else if ( V_1 -> V_5 ) {
F_61 ( V_118 ) ;
goto V_153;
}
switch ( V_149 ) {
case V_134 :
F_66 ( V_140 , V_118 , V_3 , V_7 ) ;
break;
case V_106 :
F_71 ( V_140 , V_143 , V_118 , V_3 , V_7 ) ;
break;
case V_129 :
V_151 = F_48 ( V_150 [ 1 ] ) ;
F_29 ( & V_3 -> V_46 -> V_8 , L_53 , V_151 ) ;
F_61 ( V_118 ) ;
if ( V_151 & 0xffff0000 ) {
T_4 V_154 = ( V_151 & 0xffff0000 ) >> 16 ;
F_77 ( V_7 , V_154 ) ;
} else
F_78 ( V_7 , V_151 & 0xFF ) ;
break;
default:
F_29 ( & V_3 -> V_46 -> V_8 , L_54 ,
V_149 ) ;
F_61 ( V_118 ) ;
break;
}
V_152:
F_63 ( V_3 ) ;
V_153:
F_10 ( V_12 ) ;
}
static int V_76 ( struct V_6 * V_7 , T_1 type ,
T_1 * V_110 , T_2 V_111 )
{
struct V_2 * V_3 = V_7 -> V_16 ;
F_29 ( & V_3 -> V_46 -> V_8 , L_55 , type ) ;
F_29 ( & V_3 -> V_46 -> V_8 , L_56 , V_111 ) ;
if ( type == V_155 ) {
* ( V_105 * ) V_3 -> V_15 = F_49 ( V_106 ) ;
V_7 -> V_10 = V_156 ;
} else {
* ( V_105 * ) V_3 -> V_15 = F_49 ( V_134 ) ;
V_7 -> V_10 = V_157 ;
}
memcpy ( ( V_3 -> V_15 + V_141 ) , V_110 , V_111 ) ;
return F_50 ( V_3 , V_3 -> V_15 , V_111 + V_141 ) ;
}
static int F_79 ( struct V_2 * V_3 , int V_158 )
{
struct V_159 * V_159 = V_3 -> V_15 ;
V_159 -> V_132 = F_49 ( V_133 ) ;
V_159 -> V_103 = V_158 ;
memset ( V_159 -> V_160 , 0 , sizeof( V_159 -> V_160 ) ) ;
F_50 ( V_3 , V_3 -> V_15 , sizeof( * V_159 ) ) ;
return 0 ;
}
static int F_80 ( const T_1 * V_90 , V_57 V_161 )
{
V_57 V_162 , exit ;
V_57 V_163 , V_164 , V_165 ;
int V_104 ;
V_104 = 1 ;
exit = V_165 = 0 ;
do {
struct V_95 * V_166 = ( void * ) V_90 ;
V_162 = F_48 ( V_166 -> V_98 ) ;
V_163 = F_48 ( V_166 -> V_96 ) ;
switch ( V_162 ) {
case V_99 :
V_164 = sizeof( struct V_95 ) + V_163 ;
V_90 += V_164 ;
V_165 += V_164 ;
if ( V_165 >= V_161 )
exit = 1 ;
break;
case V_100 :
exit = 1 ;
V_104 = 0 ;
break;
default:
exit = 1 ;
break;
}
} while ( ! exit );
if ( V_104 )
F_19 ( L_57 ) ;
else
F_81 ( L_58 ) ;
return V_104 ;
}
static void V_83 ( struct V_6 * V_7 , int V_104 ,
const struct V_88 * V_89 ,
const struct V_88 * V_167 )
{
struct V_2 * V_3 = V_7 -> V_16 ;
int V_53 = 0 ;
static int V_168 = 10 ;
F_6 ( V_12 ) ;
if ( V_104 ) {
F_19 ( L_59 , V_104 ) ;
goto V_169;
}
V_3 -> V_89 = V_89 ;
if ( F_80 ( V_3 -> V_89 -> V_90 , V_3 -> V_89 -> V_22 ) ) {
V_104 = - V_170 ;
goto V_171;
}
F_7 ( V_3 -> V_14 ) ;
F_7 ( V_3 -> V_13 ) ;
V_3 -> V_93 = 0 ;
V_3 -> V_37 = 0 ;
V_3 -> V_92 = 0 ;
V_3 -> V_101 = 0 ;
V_3 -> V_127 = 0 ;
V_172:
if ( F_62 ( V_3 ) < 0 ) {
F_29 ( & V_3 -> V_46 -> V_8 , L_60 ) ;
V_104 = - V_173 ;
goto V_171;
}
V_3 -> V_127 = 0 ;
do {
int V_174 = 0 ;
V_53 ++ ;
F_79 ( V_3 , V_135 ) ;
do {
V_174 ++ ;
F_82 ( 100 ) ;
} while ( V_3 -> V_127 == 0 && V_174 < 10 );
} while ( V_3 -> V_127 == 0 && V_53 < 5 );
if ( V_3 -> V_127 == V_175 ) {
V_104 = - V_176 ;
F_7 ( V_3 -> V_14 ) ;
F_7 ( V_3 -> V_13 ) ;
if ( F_63 ( V_3 ) < 0 )
V_104 = - V_173 ;
goto V_171;
} else if ( V_3 -> V_127 <= 0 ) {
if ( -- V_168 >= 0 ) {
F_42 ( V_3 ) ;
goto V_172;
}
V_104 = - V_173 ;
goto V_171;
}
V_53 = 0 ;
V_3 -> V_92 = 0 ;
V_3 -> V_93 = 0 ;
V_3 -> V_91 = 1 ;
V_3 -> V_37 = 0 ;
V_3 -> V_94 = - 1 ;
V_3 -> V_92 = 0 ;
V_3 -> V_101 = 0 ;
F_47 ( V_3 ) ;
F_83 ( V_3 -> V_39 , V_3 -> V_38 || V_3 -> V_37 ) ;
F_84 ( & V_3 -> V_55 ) ;
F_7 ( V_3 -> V_14 ) ;
if ( ! V_3 -> V_37 ) {
F_4 ( L_61 ) ;
if ( -- V_168 >= 0 ) {
F_42 ( V_3 ) ;
goto V_172;
}
F_4 ( L_62 , V_53 * 100 ) ;
V_104 = - V_173 ;
goto V_171;
}
V_3 -> V_7 -> V_177 = 1 ;
F_63 ( V_3 ) ;
if ( F_85 ( V_7 ) )
goto V_171;
F_11 ( V_7 ) ;
V_7 -> V_178 = V_179 ;
if ( F_15 ( V_7 , V_7 -> V_178 , NULL ) )
V_7 -> V_180 = false ;
V_171:
F_86 ( V_3 -> V_89 ) ;
V_3 -> V_89 = NULL ;
V_169:
F_10 ( V_12 ) ;
}
static int F_87 ( struct V_41 * V_42 , T_5 V_181 )
{
struct V_2 * V_3 = F_44 ( V_42 ) ;
struct V_6 * V_7 = V_3 -> V_7 ;
int V_104 ;
F_6 ( V_12 ) ;
if ( V_7 -> V_182 != V_183 ) {
V_104 = - 1 ;
goto V_184;
}
#ifdef F_36
if ( F_37 () ) {
if ( V_7 -> V_178 == V_179 )
F_88 ( V_185 ) ;
else
F_89 ( V_185 ) ;
}
#endif
V_104 = F_90 ( V_7 ) ;
if ( V_104 )
goto V_184;
F_7 ( V_3 -> V_13 ) ;
F_7 ( V_3 -> V_14 ) ;
V_184:
F_10 ( V_12 ) ;
return V_104 ;
}
static int F_91 ( struct V_41 * V_42 )
{
struct V_2 * V_3 = F_44 ( V_42 ) ;
struct V_6 * V_7 = V_3 -> V_7 ;
F_6 ( V_12 ) ;
F_63 ( V_3 ) ;
F_92 ( V_7 ) ;
F_10 ( V_12 ) ;
return 0 ;
}
