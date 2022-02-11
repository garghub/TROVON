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
F_6 ( V_3 -> V_12 ) ;
F_6 ( V_3 -> V_13 ) ;
F_7 ( V_3 -> V_12 ) ;
V_3 -> V_12 = NULL ;
F_7 ( V_3 -> V_13 ) ;
V_3 -> V_13 = NULL ;
F_8 ( V_3 -> V_14 ) ;
V_3 -> V_14 = NULL ;
}
static void F_9 ( struct V_6 * V_7 )
{
struct V_2 * V_3 = V_7 -> V_15 ;
struct V_16 V_17 ;
struct V_18 V_19 ;
V_17 . V_20 . V_21 = F_10 ( sizeof( V_17 ) ) ;
V_17 . V_22 = 0 ;
V_17 . V_23 = V_3 -> V_24 ;
if ( F_11 ( V_7 , V_25 , & V_17 ) )
F_12 ( L_4 ) ;
V_7 -> V_26 = 2 ;
V_7 -> V_27 = 20 ;
F_13 ( V_7 , V_28 ,
(struct V_29 * ) NULL ) ;
V_19 . V_20 . V_21 = F_10 ( sizeof( V_19 ) ) ;
V_19 . V_22 = F_10 ( V_30 ) ;
if ( F_11 ( V_7 , V_31 , & V_19 ) ) {
F_14 ( V_7 -> V_8 , L_5 ) ;
V_7 -> V_32 &= ~ V_33 ;
} else {
if ( F_15 ( V_19 . V_34 ) == V_35 ) {
F_12 ( L_6 ) ;
} else {
V_7 -> V_32 &= ~ V_33 ;
F_14 ( V_7 -> V_8 ,
L_7 ) ;
}
}
}
static void F_16 ( unsigned long V_7 )
{
struct V_2 * V_3 = ( void * ) V_7 ;
if ( V_3 -> V_36 ) {
F_12 ( L_8 ) ;
} else {
F_17 ( L_9 ) ;
V_3 -> V_37 = 1 ;
}
F_18 ( & V_3 -> V_38 ) ;
}
static void F_19 ( struct V_6 * V_7 )
{
F_20 ( V_39 L_10 ) ;
F_21 ( 0x25 , NULL , 0 , NULL , 0 ) ;
}
static int F_22 ( struct V_40 * V_41 ,
const struct V_42 * V_43 )
{
struct V_44 * V_45 ;
struct V_46 * V_47 ;
struct V_48 * V_49 ;
struct V_6 * V_7 ;
struct V_2 * V_3 ;
int V_50 = - V_51 ;
int V_52 ;
V_45 = F_23 ( V_41 ) ;
V_3 = F_24 ( sizeof( struct V_2 ) , V_53 ) ;
if ( ! V_3 )
goto error;
F_25 ( & V_3 -> V_54 , F_16 , ( unsigned long ) V_3 ) ;
F_26 ( & V_3 -> V_38 ) ;
V_3 -> V_45 = V_45 ;
V_3 -> V_55 = ( V_56 ) V_43 -> V_57 ;
V_47 = V_41 -> V_58 ;
F_27 ( & V_45 -> V_8 , L_11
L_12 ,
F_15 ( V_45 -> V_59 . V_60 ) ,
V_45 -> V_59 . V_61 ,
V_45 -> V_59 . V_62 ,
V_45 -> V_59 . V_63 ) ;
for ( V_52 = 0 ; V_52 < V_47 -> V_64 . V_65 ; ++ V_52 ) {
V_49 = & V_47 -> V_49 [ V_52 ] . V_64 ;
if ( F_28 ( V_49 ) ) {
V_3 -> V_66 = F_15 ( V_49 -> V_67 ) ;
V_3 -> V_68 = F_29 ( V_49 ) ;
F_27 ( & V_45 -> V_8 , L_13 , V_3 -> V_68 ) ;
F_27 ( & V_45 -> V_8 , L_14 , V_3 -> V_66 ) ;
} else if ( F_30 ( V_49 ) ) {
V_3 -> V_69 = F_15 ( V_49 -> V_67 ) ;
V_3 -> V_70 = F_29 ( V_49 ) ;
F_27 ( & V_45 -> V_8 , L_15 , V_3 -> V_70 ) ;
F_27 ( & V_45 -> V_8 , L_16 , V_3 -> V_69 ) ;
}
}
if ( ! V_3 -> V_69 || ! V_3 -> V_66 ) {
F_27 ( & V_45 -> V_8 , L_17 ) ;
goto V_71;
}
if ( ! ( V_3 -> V_13 = F_31 ( 0 , V_53 ) ) ) {
F_27 ( & V_45 -> V_8 , L_18 ) ;
goto V_71;
}
if ( ! ( V_3 -> V_12 = F_31 ( 0 , V_53 ) ) ) {
F_27 ( & V_45 -> V_8 , L_19 ) ;
goto V_71;
}
V_3 -> V_14 = F_32 ( V_72 , V_53 ) ;
if ( ! V_3 -> V_14 ) {
F_27 ( & V_45 -> V_8 , L_20 ) ;
goto V_71;
}
if ( ! ( V_7 = F_33 ( V_3 , & V_41 -> V_8 ) ) )
goto V_73;
V_3 -> V_7 = V_7 ;
V_7 -> V_74 = V_75 ;
V_7 -> V_76 = NULL ;
V_7 -> V_77 = NULL ;
V_7 -> V_78 = NULL ;
V_7 -> V_79 = false ;
#ifdef F_34
if ( F_35 () )
V_7 -> V_80 = F_19 ;
#endif
V_3 -> V_24 = V_45 -> V_59 . V_81 ;
F_36 ( V_45 ) ;
F_37 ( V_41 , V_3 ) ;
V_50 = F_38 ( V_7 , & V_45 -> V_8 , V_3 -> V_55 ,
V_82 , V_83 ) ;
if ( V_50 )
goto V_84;
return 0 ;
V_84:
F_39 ( V_7 ) ;
V_73:
F_40 ( V_3 ) ;
V_71:
F_5 ( V_3 ) ;
error:
return V_50 ;
}
static void F_41 ( struct V_40 * V_41 )
{
struct V_2 * V_3 = F_42 ( V_41 ) ;
struct V_6 * V_7 = V_3 -> V_7 ;
V_3 -> V_37 = 1 ;
if ( V_7 ) {
F_43 ( V_7 ) ;
F_39 ( V_7 ) ;
}
F_5 ( V_3 ) ;
F_37 ( V_41 , NULL ) ;
F_44 ( F_23 ( V_41 ) ) ;
}
static int F_45 ( struct V_2 * V_3 )
{
struct V_85 * V_85 = V_3 -> V_14 ;
const T_1 * V_86 = V_3 -> V_87 -> V_88 ;
if ( ! V_3 -> V_89 ) {
V_3 -> V_90 = V_3 -> V_91 ;
V_3 -> V_92 -- ;
}
F_2 ( & V_3 -> V_45 -> V_8 , L_21 ,
V_3 -> V_90 ) ;
memcpy ( & V_85 -> V_20 , & V_86 [ V_3 -> V_90 ] ,
sizeof( struct V_93 ) ) ;
V_3 -> V_91 = V_3 -> V_90 ;
V_3 -> V_90 += sizeof( struct V_93 ) ;
memcpy ( V_85 -> V_88 , & V_86 [ V_3 -> V_90 ] ,
F_46 ( V_85 -> V_20 . V_94 ) ) ;
F_2 ( & V_3 -> V_45 -> V_8 , L_22 ,
F_46 ( V_85 -> V_20 . V_94 ) ) ;
V_85 -> V_95 = F_47 ( ++ V_3 -> V_92 ) ;
V_3 -> V_90 += F_46 ( V_85 -> V_20 . V_94 ) ;
F_48 ( V_3 , V_3 -> V_14 , sizeof( struct V_85 ) +
F_46 ( V_85 -> V_20 . V_94 ) ) ;
if ( V_85 -> V_20 . V_96 == F_47 ( V_97 ) ) {
F_2 ( & V_3 -> V_45 -> V_8 , L_23 ) ;
F_2 ( & V_3 -> V_45 -> V_8 , L_24 ,
V_3 -> V_92 , V_3 -> V_90 ) ;
} else if ( V_85 -> V_20 . V_96 == F_47 ( V_98 ) ) {
F_2 ( & V_3 -> V_45 -> V_8 , L_25 ) ;
F_2 ( & V_3 -> V_45 -> V_8 , L_26 ) ;
V_3 -> V_99 = 1 ;
}
F_2 ( & V_3 -> V_45 -> V_8 , L_27 ,
V_3 -> V_90 ) ;
return 0 ;
}
static int F_40 ( struct V_2 * V_3 )
{
struct V_100 * V_101 = V_3 -> V_14 + 4 ;
int V_102 ;
* ( V_103 * ) V_3 -> V_14 = F_47 ( V_104 ) ;
V_101 -> V_105 = F_10 ( V_106 ) ;
V_101 -> V_21 = F_10 ( sizeof( V_101 ) ) ;
V_101 -> V_107 = F_10 ( 0 ) ;
V_101 -> V_95 = F_10 ( 0x5a5a ) ;
F_48 ( V_3 , V_3 -> V_14 , 4 + sizeof( struct V_100 ) ) ;
F_49 ( 100 ) ;
V_102 = F_50 ( V_3 -> V_45 ) ;
F_49 ( 100 ) ;
#ifdef F_34
if ( V_102 && F_35 () )
F_19 ( NULL ) ;
#endif
return V_102 ;
}
static int F_48 ( struct V_2 * V_3 , T_1 * V_108 , T_2 V_109 )
{
int V_102 ;
if ( V_3 -> V_37 ) {
F_27 ( & V_3 -> V_45 -> V_8 , L_28 ) ;
V_102 = - V_110 ;
goto V_111;
}
F_51 ( V_3 -> V_12 , V_3 -> V_45 ,
F_52 ( V_3 -> V_45 ,
V_3 -> V_70 ) ,
V_108 , V_109 , F_1 , V_3 ) ;
V_3 -> V_12 -> V_112 |= V_113 ;
if ( ( V_102 = F_53 ( V_3 -> V_12 , V_114 ) ) ) {
F_27 ( & V_3 -> V_45 -> V_8 , L_29 , V_102 ) ;
} else {
F_2 ( & V_3 -> V_45 -> V_8 , L_30 ) ;
V_102 = 0 ;
}
V_111:
return V_102 ;
}
static int F_54 ( struct V_2 * V_3 ,
void (* F_55)( struct V_1 * V_1 ) )
{
struct V_115 * V_116 ;
int V_102 = - 1 ;
if ( ! ( V_116 = F_56 ( V_117 ) ) ) {
F_17 ( L_31 ) ;
goto V_118;
}
V_3 -> V_119 = V_116 ;
F_51 ( V_3 -> V_13 , V_3 -> V_45 ,
F_57 ( V_3 -> V_45 , V_3 -> V_68 ) ,
V_116 -> V_88 + V_120 ,
V_117 , F_55 ,
V_3 ) ;
V_3 -> V_13 -> V_112 |= V_113 ;
F_2 ( & V_3 -> V_45 -> V_8 , L_32 , V_3 -> V_13 ) ;
if ( ( V_102 = F_53 ( V_3 -> V_13 , V_114 ) ) ) {
F_27 ( & V_3 -> V_45 -> V_8 , L_33 , V_102 ) ;
F_58 ( V_116 ) ;
V_3 -> V_119 = NULL ;
V_102 = - 1 ;
} else {
F_2 ( & V_3 -> V_45 -> V_8 , L_34 ) ;
V_102 = 0 ;
}
V_118:
return V_102 ;
}
static int F_59 ( struct V_2 * V_3 )
{
return F_54 ( V_3 , & V_121 ) ;
}
static int F_60 ( struct V_2 * V_3 )
{
return F_54 ( V_3 , & V_122 ) ;
}
static void V_121 ( struct V_1 * V_1 )
{
struct V_2 * V_3 = V_1 -> V_4 ;
struct V_115 * V_116 = V_3 -> V_119 ;
struct V_123 * V_124 ;
struct V_125 V_125 ;
if ( V_1 -> V_5 ) {
F_27 ( & V_3 -> V_45 -> V_8 ,
L_35 ) ;
F_58 ( V_116 ) ;
return;
}
if ( V_3 -> V_36 ) {
V_103 * V_126 = ( V_103 * ) ( V_116 -> V_88 + V_120 ) ;
if ( V_126 [ 0 ] == F_47 ( V_127 ) &&
V_126 [ 1 ] == F_47 ( V_128 ) ) {
F_4 ( L_36 ) ;
F_18 ( & V_3 -> V_38 ) ;
} else {
F_12 ( L_37 ,
F_46 ( V_126 [ 0 ] ) , F_46 ( V_126 [ 1 ] ) ) ;
F_59 ( V_3 ) ;
}
F_58 ( V_116 ) ;
return;
}
if ( V_3 -> V_125 <= 0 ) {
memcpy ( & V_125 , V_116 -> V_88 + V_120 ,
sizeof( V_125 ) ) ;
if ( F_15 ( V_3 -> V_45 -> V_59 . V_81 ) < 0x3106 ) {
F_58 ( V_116 ) ;
F_59 ( V_3 ) ;
V_3 -> V_125 = V_129 ;
F_27 ( & V_3 -> V_45 -> V_8 ,
L_38 ) ;
return;
}
if ( V_125 . V_130 != F_47 ( V_131 ) ) {
if ( V_125 . V_130 == F_47 ( V_104 ) ||
V_125 . V_130 == F_47 ( V_132 ) ||
V_125 . V_130 == F_47 ( V_127 ) ) {
if ( ! V_3 -> V_125 )
F_4 ( L_39 ) ;
V_3 -> V_125 = - 1 ;
} else {
F_4 ( L_40 ,
F_46 ( V_125 . V_130 ) ) ;
}
} else if ( ( V_125 . V_101 != V_133 ) &&
( V_125 . V_101 != V_134 ) &&
( V_125 . V_101 != V_135 ) ) {
F_4 ( L_41 ,
V_125 . V_101 ) ;
} else if ( V_125 . V_107 != V_129 ) {
F_4 ( L_42 ,
V_125 . V_107 ) ;
} else {
V_3 -> V_125 = 1 ;
F_27 ( & V_3 -> V_45 -> V_8 ,
L_38 ) ;
}
F_58 ( V_116 ) ;
F_59 ( V_3 ) ;
return;
}
V_124 = F_61 ( V_116 -> V_88 + V_120 ,
sizeof( struct V_123 ) , V_114 ) ;
if ( ! V_124 ) {
F_27 ( & V_3 -> V_45 -> V_8 , L_43 ) ;
F_58 ( V_116 ) ;
return;
}
if ( ! V_124 -> V_101 ) {
F_2 ( & V_3 -> V_45 -> V_8 , L_44 ) ;
F_2 ( & V_3 -> V_45 -> V_8 , L_45 ,
F_46 ( V_124 -> V_95 ) ) ;
V_3 -> V_89 = 1 ;
} else {
F_27 ( & V_3 -> V_45 -> V_8 , L_46 ) ;
V_3 -> V_89 = 0 ;
}
F_58 ( V_116 ) ;
F_62 ( & V_3 -> V_54 , V_136 + ( V_137 * 5 ) ) ;
if ( V_3 -> V_99 ) {
V_3 -> V_36 = 1 ;
goto exit;
}
F_45 ( V_3 ) ;
exit:
F_59 ( V_3 ) ;
F_8 ( V_124 ) ;
}
static inline void F_63 ( int V_138 , struct V_115 * V_116 ,
struct V_2 * V_3 ,
struct V_6 * V_7 )
{
if ( V_138 > V_117 + V_139
|| V_138 < V_140 ) {
F_27 ( & V_3 -> V_45 -> V_8 , L_47 ) ;
F_58 ( V_116 ) ;
return;
}
F_64 ( V_116 , V_120 ) ;
F_65 ( V_116 , V_138 ) ;
F_66 ( V_116 , V_139 ) ;
F_67 ( V_7 , V_116 ) ;
}
static inline void F_68 ( int V_138 , T_1 * V_141 ,
struct V_115 * V_116 ,
struct V_2 * V_3 ,
struct V_6 * V_7 )
{
T_3 V_52 ;
if ( V_138 > V_142 ) {
F_27 ( & V_3 -> V_45 -> V_8 ,
L_48 ) ;
F_58 ( V_116 ) ;
return;
}
F_69 ( ! F_70 () ) ;
F_71 ( & V_7 -> V_143 ) ;
V_52 = ( V_7 -> V_144 == 0 ) ? 1 : 0 ;
F_69 ( V_7 -> V_145 [ V_52 ] ) ;
V_7 -> V_145 [ V_52 ] = ( V_138 - V_139 ) ;
memcpy ( V_7 -> V_146 [ V_52 ] , V_141 + V_139 ,
V_7 -> V_145 [ V_52 ] ) ;
F_58 ( V_116 ) ;
F_72 ( V_7 , V_52 ) ;
F_73 ( & V_7 -> V_143 ) ;
F_27 ( & V_3 -> V_45 -> V_8 ,
L_49 ) ;
}
static void V_122 ( struct V_1 * V_1 )
{
struct V_2 * V_3 = V_1 -> V_4 ;
struct V_115 * V_116 = V_3 -> V_119 ;
struct V_6 * V_7 = V_3 -> V_7 ;
int V_138 = V_1 -> V_9 ;
T_1 * V_141 = NULL ;
V_56 V_147 = 0 ;
V_103 * V_148 = ( V_103 * ) ( V_116 -> V_88 + V_120 ) ;
V_56 V_149 ;
if ( V_138 ) {
if ( V_1 -> V_5 ) {
F_27 ( & V_3 -> V_45 -> V_8 , L_50 ,
V_1 -> V_5 ) ;
F_58 ( V_116 ) ;
goto V_150;
}
V_141 = V_116 -> V_88 + V_120 ;
V_147 = F_46 ( V_148 [ 0 ] ) ;
F_27 ( & V_3 -> V_45 -> V_8 ,
L_51 ,
V_138 , V_147 ) ;
} else if ( V_1 -> V_5 ) {
F_58 ( V_116 ) ;
return;
}
switch ( V_147 ) {
case V_132 :
F_63 ( V_138 , V_116 , V_3 , V_7 ) ;
break;
case V_104 :
F_68 ( V_138 , V_141 , V_116 , V_3 , V_7 ) ;
break;
case V_127 :
V_149 = F_46 ( V_148 [ 1 ] ) ;
F_27 ( & V_3 -> V_45 -> V_8 , L_52 , V_149 ) ;
F_58 ( V_116 ) ;
if ( V_149 & 0xffff0000 ) {
T_4 V_151 = ( V_149 & 0xffff0000 ) >> 16 ;
F_74 ( V_7 , V_151 ) ;
} else
F_75 ( V_7 , V_149 & 0xFF ) ;
break;
default:
F_27 ( & V_3 -> V_45 -> V_8 , L_53 ,
V_147 ) ;
F_58 ( V_116 ) ;
break;
}
V_150:
F_60 ( V_3 ) ;
}
static int V_75 ( struct V_6 * V_7 , T_1 type ,
T_1 * V_108 , T_2 V_109 )
{
struct V_2 * V_3 = V_7 -> V_15 ;
F_27 ( & V_3 -> V_45 -> V_8 , L_54 , type ) ;
F_27 ( & V_3 -> V_45 -> V_8 , L_55 , V_109 ) ;
if ( type == V_152 ) {
* ( V_103 * ) V_3 -> V_14 = F_47 ( V_104 ) ;
V_7 -> V_10 = V_153 ;
} else {
* ( V_103 * ) V_3 -> V_14 = F_47 ( V_132 ) ;
V_7 -> V_10 = V_154 ;
}
memcpy ( ( V_3 -> V_14 + V_139 ) , V_108 , V_109 ) ;
return F_48 ( V_3 , V_3 -> V_14 , V_109 + V_139 ) ;
}
static int F_76 ( struct V_2 * V_3 , int V_155 )
{
struct V_156 * V_156 = V_3 -> V_14 ;
V_156 -> V_130 = F_47 ( V_131 ) ;
V_156 -> V_101 = V_155 ;
memset ( V_156 -> V_157 , 0 , sizeof( V_156 -> V_157 ) ) ;
F_48 ( V_3 , V_3 -> V_14 , sizeof( * V_156 ) ) ;
return 0 ;
}
static int F_77 ( const T_1 * V_88 , V_56 V_158 )
{
V_56 V_159 , exit ;
V_56 V_160 , V_161 , V_162 ;
int V_102 ;
V_102 = 1 ;
exit = V_162 = 0 ;
do {
struct V_93 * V_163 = ( void * ) V_88 ;
V_159 = F_46 ( V_163 -> V_96 ) ;
V_160 = F_46 ( V_163 -> V_94 ) ;
switch ( V_159 ) {
case V_97 :
V_161 = sizeof( struct V_93 ) + V_160 ;
V_88 += V_161 ;
V_162 += V_161 ;
if ( V_162 >= V_158 )
exit = 1 ;
break;
case V_98 :
exit = 1 ;
V_102 = 0 ;
break;
default:
exit = 1 ;
break;
}
} while ( ! exit );
if ( V_102 )
F_17 ( L_56 ) ;
else
F_78 ( L_57 ) ;
return V_102 ;
}
static void V_83 ( struct V_6 * V_7 , int V_102 ,
const struct V_86 * V_87 ,
const struct V_86 * V_164 )
{
struct V_2 * V_3 = V_7 -> V_15 ;
int V_52 = 0 ;
static int V_165 = 10 ;
if ( V_102 ) {
F_17 ( L_58 , V_102 ) ;
goto V_166;
}
V_3 -> V_87 = V_87 ;
if ( F_77 ( V_3 -> V_87 -> V_88 , V_3 -> V_87 -> V_21 ) ) {
V_102 = - V_167 ;
goto V_166;
}
F_6 ( V_3 -> V_13 ) ;
F_6 ( V_3 -> V_12 ) ;
V_3 -> V_91 = 0 ;
V_3 -> V_36 = 0 ;
V_3 -> V_90 = 0 ;
V_3 -> V_99 = 0 ;
V_3 -> V_125 = 0 ;
V_168:
if ( F_59 ( V_3 ) < 0 ) {
F_27 ( & V_3 -> V_45 -> V_8 , L_59 ) ;
V_102 = - V_169 ;
goto V_166;
}
V_3 -> V_125 = 0 ;
do {
int V_170 = 0 ;
V_52 ++ ;
F_76 ( V_3 , V_133 ) ;
do {
V_170 ++ ;
F_79 ( 100 ) ;
} while ( V_3 -> V_125 == 0 && V_170 < 10 );
} while ( V_3 -> V_125 == 0 && V_52 < 5 );
if ( V_3 -> V_125 == V_171 ) {
V_102 = - V_172 ;
F_6 ( V_3 -> V_13 ) ;
F_6 ( V_3 -> V_12 ) ;
if ( F_60 ( V_3 ) < 0 )
V_102 = - V_169 ;
goto V_166;
} else if ( V_3 -> V_125 <= 0 ) {
if ( -- V_165 >= 0 ) {
F_40 ( V_3 ) ;
goto V_168;
}
V_102 = - V_169 ;
goto V_166;
}
V_52 = 0 ;
V_3 -> V_90 = 0 ;
V_3 -> V_91 = 0 ;
V_3 -> V_89 = 1 ;
V_3 -> V_36 = 0 ;
V_3 -> V_92 = - 1 ;
V_3 -> V_90 = 0 ;
V_3 -> V_99 = 0 ;
F_45 ( V_3 ) ;
F_80 ( V_3 -> V_38 , V_3 -> V_37 || V_3 -> V_36 ) ;
F_81 ( & V_3 -> V_54 ) ;
F_6 ( V_3 -> V_13 ) ;
if ( ! V_3 -> V_36 ) {
F_4 ( L_60 ) ;
if ( -- V_165 >= 0 ) {
F_40 ( V_3 ) ;
goto V_168;
}
F_4 ( L_61 , V_52 * 100 ) ;
V_102 = - V_169 ;
goto V_166;
}
V_3 -> V_7 -> V_173 = 1 ;
F_60 ( V_3 ) ;
if ( F_82 ( V_7 ) )
goto V_166;
F_9 ( V_7 ) ;
V_7 -> V_174 = V_175 ;
if ( F_13 ( V_7 , V_7 -> V_174 , NULL ) )
V_7 -> V_176 = false ;
V_166:
V_3 -> V_87 = NULL ;
}
static int F_83 ( struct V_40 * V_41 , T_5 V_177 )
{
struct V_2 * V_3 = F_42 ( V_41 ) ;
struct V_6 * V_7 = V_3 -> V_7 ;
int V_102 ;
if ( V_7 -> V_178 != V_179 ) {
V_102 = - 1 ;
goto V_180;
}
#ifdef F_34
if ( F_35 () ) {
if ( V_7 -> V_174 == V_175 )
F_84 ( V_181 ) ;
else
F_85 ( V_181 ) ;
}
#endif
V_102 = F_86 ( V_7 ) ;
if ( V_102 )
goto V_180;
F_6 ( V_3 -> V_12 ) ;
F_6 ( V_3 -> V_13 ) ;
V_180:
return V_102 ;
}
static int F_87 ( struct V_40 * V_41 )
{
struct V_2 * V_3 = F_42 ( V_41 ) ;
struct V_6 * V_7 = V_3 -> V_7 ;
F_60 ( V_3 ) ;
F_88 ( V_7 ) ;
return 0 ;
}
