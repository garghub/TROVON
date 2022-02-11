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
struct V_6 * V_7 = V_3 -> V_7 ;
F_6 ( V_85 ) ;
V_3 -> V_38 = 1 ;
if ( V_7 ) {
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
struct V_86 * V_86 = V_3 -> V_15 ;
const T_1 * V_87 = V_3 -> V_88 -> V_89 ;
if ( ! V_3 -> V_90 ) {
V_3 -> V_91 = V_3 -> V_92 ;
V_3 -> V_93 -- ;
}
F_2 ( & V_3 -> V_46 -> V_8 , L_21 ,
V_3 -> V_91 ) ;
memcpy ( & V_86 -> V_21 , & V_87 [ V_3 -> V_91 ] ,
sizeof( struct V_94 ) ) ;
V_3 -> V_92 = V_3 -> V_91 ;
V_3 -> V_91 += sizeof( struct V_94 ) ;
memcpy ( V_86 -> V_89 , & V_87 [ V_3 -> V_91 ] ,
F_48 ( V_86 -> V_21 . V_95 ) ) ;
F_2 ( & V_3 -> V_46 -> V_8 , L_22 ,
F_48 ( V_86 -> V_21 . V_95 ) ) ;
V_86 -> V_96 = F_49 ( ++ V_3 -> V_93 ) ;
V_3 -> V_91 += F_48 ( V_86 -> V_21 . V_95 ) ;
F_50 ( V_3 , V_3 -> V_15 , sizeof( struct V_86 ) +
F_48 ( V_86 -> V_21 . V_95 ) ) ;
if ( V_86 -> V_21 . V_97 == F_49 ( V_98 ) ) {
F_2 ( & V_3 -> V_46 -> V_8 , L_23 ) ;
F_2 ( & V_3 -> V_46 -> V_8 , L_24 ,
V_3 -> V_93 , V_3 -> V_91 ) ;
} else if ( V_86 -> V_21 . V_97 == F_49 ( V_99 ) ) {
F_2 ( & V_3 -> V_46 -> V_8 , L_25 ) ;
F_2 ( & V_3 -> V_46 -> V_8 , L_26 ) ;
V_3 -> V_100 = 1 ;
}
F_2 ( & V_3 -> V_46 -> V_8 , L_27 ,
V_3 -> V_91 ) ;
return 0 ;
}
static int F_42 ( struct V_2 * V_3 )
{
struct V_101 * V_102 = V_3 -> V_15 + 4 ;
int V_103 ;
F_6 ( V_12 ) ;
* ( V_104 * ) V_3 -> V_15 = F_49 ( V_105 ) ;
V_102 -> V_106 = F_12 ( V_107 ) ;
V_102 -> V_22 = F_12 ( sizeof( V_102 ) ) ;
V_102 -> V_108 = F_12 ( 0 ) ;
V_102 -> V_96 = F_12 ( 0x5a5a ) ;
F_50 ( V_3 , V_3 -> V_15 , 4 + sizeof( struct V_101 ) ) ;
F_51 ( 100 ) ;
V_103 = F_52 ( V_3 -> V_46 ) ;
F_51 ( 100 ) ;
#ifdef F_36
if ( V_103 && F_37 () )
F_21 ( NULL ) ;
#endif
F_53 ( V_12 , L_28 , V_103 ) ;
return V_103 ;
}
static int F_50 ( struct V_2 * V_3 , T_1 * V_109 , T_2 V_110 )
{
int V_103 ;
if ( V_3 -> V_38 ) {
F_29 ( & V_3 -> V_46 -> V_8 , L_29 ) ;
V_103 = - V_111 ;
goto V_112;
}
F_54 ( V_3 -> V_13 , V_3 -> V_46 ,
F_55 ( V_3 -> V_46 ,
V_3 -> V_71 ) ,
V_109 , V_110 , F_1 , V_3 ) ;
V_3 -> V_13 -> V_113 |= V_114 ;
if ( ( V_103 = F_56 ( V_3 -> V_13 , V_115 ) ) ) {
F_29 ( & V_3 -> V_46 -> V_8 , L_30 , V_103 ) ;
} else {
F_2 ( & V_3 -> V_46 -> V_8 , L_31 ) ;
V_103 = 0 ;
}
V_112:
return V_103 ;
}
static int F_57 ( struct V_2 * V_3 ,
void (* F_58)( struct V_1 * V_1 ) )
{
struct V_116 * V_117 ;
int V_103 = - 1 ;
if ( ! ( V_117 = F_59 ( V_118 ) ) ) {
F_19 ( L_32 ) ;
goto V_119;
}
V_3 -> V_120 = V_117 ;
F_54 ( V_3 -> V_14 , V_3 -> V_46 ,
F_60 ( V_3 -> V_46 , V_3 -> V_69 ) ,
V_117 -> V_89 + V_121 ,
V_118 , F_58 ,
V_3 ) ;
V_3 -> V_14 -> V_113 |= V_114 ;
F_2 ( & V_3 -> V_46 -> V_8 , L_33 , V_3 -> V_14 ) ;
if ( ( V_103 = F_56 ( V_3 -> V_14 , V_115 ) ) ) {
F_29 ( & V_3 -> V_46 -> V_8 , L_34 , V_103 ) ;
F_61 ( V_117 ) ;
V_3 -> V_120 = NULL ;
V_103 = - 1 ;
} else {
F_2 ( & V_3 -> V_46 -> V_8 , L_35 ) ;
V_103 = 0 ;
}
V_119:
return V_103 ;
}
static int F_62 ( struct V_2 * V_3 )
{
return F_57 ( V_3 , & V_122 ) ;
}
static int F_63 ( struct V_2 * V_3 )
{
return F_57 ( V_3 , & V_123 ) ;
}
static void V_122 ( struct V_1 * V_1 )
{
struct V_2 * V_3 = V_1 -> V_4 ;
struct V_116 * V_117 = V_3 -> V_120 ;
struct V_124 * V_125 ;
struct V_126 V_126 ;
if ( V_1 -> V_5 ) {
F_29 ( & V_3 -> V_46 -> V_8 ,
L_36 ) ;
F_61 ( V_117 ) ;
return;
}
if ( V_3 -> V_37 ) {
V_104 * V_127 = ( V_104 * ) ( V_117 -> V_89 + V_121 ) ;
if ( V_127 [ 0 ] == F_49 ( V_128 ) &&
V_127 [ 1 ] == F_49 ( V_129 ) ) {
F_4 ( L_37 ) ;
F_20 ( & V_3 -> V_39 ) ;
} else {
F_14 ( L_38 ,
F_48 ( V_127 [ 0 ] ) , F_48 ( V_127 [ 1 ] ) ) ;
F_62 ( V_3 ) ;
}
F_61 ( V_117 ) ;
return;
}
if ( V_3 -> V_126 <= 0 ) {
memcpy ( & V_126 , V_117 -> V_89 + V_121 ,
sizeof( V_126 ) ) ;
if ( F_17 ( V_3 -> V_46 -> V_60 . V_81 ) < 0x3106 ) {
F_61 ( V_117 ) ;
F_62 ( V_3 ) ;
V_3 -> V_126 = V_130 ;
F_29 ( & V_3 -> V_46 -> V_8 ,
L_39 ) ;
return;
}
if ( V_126 . V_131 != F_49 ( V_132 ) ) {
if ( V_126 . V_131 == F_49 ( V_105 ) ||
V_126 . V_131 == F_49 ( V_133 ) ||
V_126 . V_131 == F_49 ( V_128 ) ) {
if ( ! V_3 -> V_126 )
F_4 ( L_40 ) ;
V_3 -> V_126 = - 1 ;
} else {
F_4 ( L_41 ,
F_48 ( V_126 . V_131 ) ) ;
}
} else if ( ( V_126 . V_102 != V_134 ) &&
( V_126 . V_102 != V_135 ) &&
( V_126 . V_102 != V_136 ) ) {
F_4 ( L_42 ,
V_126 . V_102 ) ;
} else if ( V_126 . V_108 != V_130 ) {
F_4 ( L_43 ,
V_126 . V_108 ) ;
} else {
V_3 -> V_126 = 1 ;
F_29 ( & V_3 -> V_46 -> V_8 ,
L_39 ) ;
}
F_61 ( V_117 ) ;
F_62 ( V_3 ) ;
return;
}
V_125 = F_64 ( V_117 -> V_89 + V_121 ,
sizeof( struct V_124 ) , V_115 ) ;
if ( ! V_125 ) {
F_29 ( & V_3 -> V_46 -> V_8 , L_44 ) ;
F_61 ( V_117 ) ;
return;
}
if ( ! V_125 -> V_102 ) {
F_2 ( & V_3 -> V_46 -> V_8 , L_45 ) ;
F_2 ( & V_3 -> V_46 -> V_8 , L_46 ,
F_48 ( V_125 -> V_96 ) ) ;
V_3 -> V_90 = 1 ;
} else {
F_29 ( & V_3 -> V_46 -> V_8 , L_47 ) ;
V_3 -> V_90 = 0 ;
}
F_61 ( V_117 ) ;
F_65 ( & V_3 -> V_55 , V_137 + ( V_138 * 5 ) ) ;
if ( V_3 -> V_100 ) {
V_3 -> V_37 = 1 ;
goto exit;
}
F_47 ( V_3 ) ;
exit:
F_62 ( V_3 ) ;
F_9 ( V_125 ) ;
}
static inline void F_66 ( int V_139 , struct V_116 * V_117 ,
struct V_2 * V_3 ,
struct V_6 * V_7 )
{
if ( V_139 > V_118 + V_140
|| V_139 < V_141 ) {
F_29 ( & V_3 -> V_46 -> V_8 , L_48 ) ;
F_61 ( V_117 ) ;
return;
}
F_67 ( V_117 , V_121 ) ;
F_68 ( V_117 , V_139 ) ;
F_69 ( V_117 , V_140 ) ;
F_70 ( V_7 , V_117 ) ;
}
static inline void F_71 ( int V_139 , T_1 * V_142 ,
struct V_116 * V_117 ,
struct V_2 * V_3 ,
struct V_6 * V_7 )
{
T_3 V_53 ;
if ( V_139 > V_143 ) {
F_29 ( & V_3 -> V_46 -> V_8 ,
L_49 ) ;
F_61 ( V_117 ) ;
return;
}
F_72 ( ! F_73 () ) ;
F_74 ( & V_7 -> V_144 ) ;
V_53 = ( V_7 -> V_145 == 0 ) ? 1 : 0 ;
F_72 ( V_7 -> V_146 [ V_53 ] ) ;
V_7 -> V_146 [ V_53 ] = ( V_139 - V_140 ) ;
memcpy ( V_7 -> V_147 [ V_53 ] , V_142 + V_140 ,
V_7 -> V_146 [ V_53 ] ) ;
F_61 ( V_117 ) ;
F_75 ( V_7 , V_53 ) ;
F_76 ( & V_7 -> V_144 ) ;
F_29 ( & V_3 -> V_46 -> V_8 ,
L_50 ) ;
}
static void V_123 ( struct V_1 * V_1 )
{
struct V_2 * V_3 = V_1 -> V_4 ;
struct V_116 * V_117 = V_3 -> V_120 ;
struct V_6 * V_7 = V_3 -> V_7 ;
int V_139 = V_1 -> V_9 ;
T_1 * V_142 = NULL ;
V_57 V_148 = 0 ;
V_104 * V_149 = ( V_104 * ) ( V_117 -> V_89 + V_121 ) ;
V_57 V_150 ;
F_6 ( V_12 ) ;
if ( V_139 ) {
if ( V_1 -> V_5 ) {
F_29 ( & V_3 -> V_46 -> V_8 , L_51 ,
V_1 -> V_5 ) ;
F_61 ( V_117 ) ;
goto V_151;
}
V_142 = V_117 -> V_89 + V_121 ;
V_148 = F_48 ( V_149 [ 0 ] ) ;
F_29 ( & V_3 -> V_46 -> V_8 ,
L_52 ,
V_139 , V_148 ) ;
} else if ( V_1 -> V_5 ) {
F_61 ( V_117 ) ;
goto V_152;
}
switch ( V_148 ) {
case V_133 :
F_66 ( V_139 , V_117 , V_3 , V_7 ) ;
break;
case V_105 :
F_71 ( V_139 , V_142 , V_117 , V_3 , V_7 ) ;
break;
case V_128 :
V_150 = F_48 ( V_149 [ 1 ] ) ;
F_29 ( & V_3 -> V_46 -> V_8 , L_53 , V_150 ) ;
F_61 ( V_117 ) ;
if ( V_150 & 0xffff0000 ) {
T_4 V_153 = ( V_150 & 0xffff0000 ) >> 16 ;
F_77 ( V_7 , V_153 ) ;
} else
F_78 ( V_7 , V_150 & 0xFF ) ;
break;
default:
F_29 ( & V_3 -> V_46 -> V_8 , L_54 ,
V_148 ) ;
F_61 ( V_117 ) ;
break;
}
V_151:
F_63 ( V_3 ) ;
V_152:
F_10 ( V_12 ) ;
}
static int V_76 ( struct V_6 * V_7 , T_1 type ,
T_1 * V_109 , T_2 V_110 )
{
struct V_2 * V_3 = V_7 -> V_16 ;
F_29 ( & V_3 -> V_46 -> V_8 , L_55 , type ) ;
F_29 ( & V_3 -> V_46 -> V_8 , L_56 , V_110 ) ;
if ( type == V_154 ) {
* ( V_104 * ) V_3 -> V_15 = F_49 ( V_105 ) ;
V_7 -> V_10 = V_155 ;
} else {
* ( V_104 * ) V_3 -> V_15 = F_49 ( V_133 ) ;
V_7 -> V_10 = V_156 ;
}
memcpy ( ( V_3 -> V_15 + V_140 ) , V_109 , V_110 ) ;
return F_50 ( V_3 , V_3 -> V_15 , V_110 + V_140 ) ;
}
static int F_79 ( struct V_2 * V_3 , int V_157 )
{
struct V_158 * V_158 = V_3 -> V_15 ;
V_158 -> V_131 = F_49 ( V_132 ) ;
V_158 -> V_102 = V_157 ;
memset ( V_158 -> V_159 , 0 , sizeof( V_158 -> V_159 ) ) ;
F_50 ( V_3 , V_3 -> V_15 , sizeof( * V_158 ) ) ;
return 0 ;
}
static int F_80 ( const T_1 * V_89 , V_57 V_160 )
{
V_57 V_161 , exit ;
V_57 V_162 , V_163 , V_164 ;
int V_103 ;
V_103 = 1 ;
exit = V_164 = 0 ;
do {
struct V_94 * V_165 = ( void * ) V_89 ;
V_161 = F_48 ( V_165 -> V_97 ) ;
V_162 = F_48 ( V_165 -> V_95 ) ;
switch ( V_161 ) {
case V_98 :
V_163 = sizeof( struct V_94 ) + V_162 ;
V_89 += V_163 ;
V_164 += V_163 ;
if ( V_164 >= V_160 )
exit = 1 ;
break;
case V_99 :
exit = 1 ;
V_103 = 0 ;
break;
default:
exit = 1 ;
break;
}
} while ( ! exit );
if ( V_103 )
F_19 ( L_57 ) ;
else
F_81 ( L_58 ) ;
return V_103 ;
}
static void V_83 ( struct V_6 * V_7 , int V_103 ,
const struct V_87 * V_88 ,
const struct V_87 * V_166 )
{
struct V_2 * V_3 = V_7 -> V_16 ;
int V_53 = 0 ;
static int V_167 = 10 ;
F_6 ( V_12 ) ;
if ( V_103 ) {
F_19 ( L_59 , V_103 ) ;
goto V_168;
}
V_3 -> V_88 = V_88 ;
if ( F_80 ( V_3 -> V_88 -> V_89 , V_3 -> V_88 -> V_22 ) ) {
V_103 = - V_169 ;
goto V_170;
}
F_7 ( V_3 -> V_14 ) ;
F_7 ( V_3 -> V_13 ) ;
V_3 -> V_92 = 0 ;
V_3 -> V_37 = 0 ;
V_3 -> V_91 = 0 ;
V_3 -> V_100 = 0 ;
V_3 -> V_126 = 0 ;
V_171:
if ( F_62 ( V_3 ) < 0 ) {
F_29 ( & V_3 -> V_46 -> V_8 , L_60 ) ;
V_103 = - V_172 ;
goto V_170;
}
V_3 -> V_126 = 0 ;
do {
int V_173 = 0 ;
V_53 ++ ;
F_79 ( V_3 , V_134 ) ;
do {
V_173 ++ ;
F_82 ( 100 ) ;
} while ( V_3 -> V_126 == 0 && V_173 < 10 );
} while ( V_3 -> V_126 == 0 && V_53 < 5 );
if ( V_3 -> V_126 == V_174 ) {
V_103 = - V_175 ;
F_7 ( V_3 -> V_14 ) ;
F_7 ( V_3 -> V_13 ) ;
if ( F_63 ( V_3 ) < 0 )
V_103 = - V_172 ;
goto V_170;
} else if ( V_3 -> V_126 <= 0 ) {
if ( -- V_167 >= 0 ) {
F_42 ( V_3 ) ;
goto V_171;
}
V_103 = - V_172 ;
goto V_170;
}
V_53 = 0 ;
V_3 -> V_91 = 0 ;
V_3 -> V_92 = 0 ;
V_3 -> V_90 = 1 ;
V_3 -> V_37 = 0 ;
V_3 -> V_93 = - 1 ;
V_3 -> V_91 = 0 ;
V_3 -> V_100 = 0 ;
F_47 ( V_3 ) ;
F_83 ( V_3 -> V_39 , V_3 -> V_38 || V_3 -> V_37 ) ;
F_84 ( & V_3 -> V_55 ) ;
F_7 ( V_3 -> V_14 ) ;
if ( ! V_3 -> V_37 ) {
F_4 ( L_61 ) ;
if ( -- V_167 >= 0 ) {
F_42 ( V_3 ) ;
goto V_171;
}
F_4 ( L_62 , V_53 * 100 ) ;
V_103 = - V_172 ;
goto V_170;
}
V_3 -> V_7 -> V_176 = 1 ;
F_63 ( V_3 ) ;
if ( F_85 ( V_7 ) )
goto V_170;
F_11 ( V_7 ) ;
V_7 -> V_177 = V_178 ;
if ( F_15 ( V_7 , V_7 -> V_177 , NULL ) )
V_7 -> V_179 = false ;
V_170:
F_86 ( V_3 -> V_88 ) ;
V_3 -> V_88 = NULL ;
V_168:
F_10 ( V_12 ) ;
}
static int F_87 ( struct V_41 * V_42 , T_5 V_180 )
{
struct V_2 * V_3 = F_44 ( V_42 ) ;
struct V_6 * V_7 = V_3 -> V_7 ;
int V_103 ;
F_6 ( V_12 ) ;
if ( V_7 -> V_181 != V_182 ) {
V_103 = - 1 ;
goto V_183;
}
#ifdef F_36
if ( F_37 () ) {
if ( V_7 -> V_177 == V_178 )
F_88 ( V_184 ) ;
else
F_89 ( V_184 ) ;
}
#endif
V_103 = F_90 ( V_7 ) ;
if ( V_103 )
goto V_183;
F_7 ( V_3 -> V_13 ) ;
F_7 ( V_3 -> V_14 ) ;
V_183:
F_10 ( V_12 ) ;
return V_103 ;
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
