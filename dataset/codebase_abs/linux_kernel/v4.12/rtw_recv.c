void F_1 ( struct V_1 * V_2 )
{
memset ( ( V_3 * ) V_2 , 0 , sizeof( struct V_1 ) ) ;
F_2 ( & V_2 -> V_4 ) ;
F_3 ( & V_2 -> V_5 ) ;
}
int F_4 ( struct V_6 * V_7 , struct V_8 * V_9 )
{
int V_10 ;
struct V_11 * V_12 ;
int V_13 = V_14 ;
F_3 ( & V_7 -> V_15 ) ;
F_3 ( & V_7 -> V_16 ) ;
F_3 ( & V_7 -> V_17 ) ;
V_7 -> V_8 = V_9 ;
V_7 -> V_18 = F_5 ( V_19 * sizeof( struct V_11 ) + V_20 ) ;
if ( ! V_7 -> V_18 )
return V_21 ;
V_12 = F_6 ( V_7 -> V_18 , V_20 ) ;
for ( V_10 = 0 ; V_10 < V_19 ; V_10 ++ ) {
F_7 ( & ( V_12 -> V_22 ) ) ;
F_8 ( & ( V_12 -> V_22 ) ,
& ( V_7 -> V_15 . V_23 ) ) ;
V_12 -> V_24 = NULL ;
V_12 -> V_8 = V_9 ;
V_12 ++ ;
}
V_13 = F_9 ( V_9 ) ;
F_10 ( & V_7 -> V_25 ,
V_26 ,
( unsigned long ) V_9 ) ;
V_7 -> V_27 = 1000 ;
F_11 ( V_7 ) ;
return V_13 ;
}
void F_12 ( struct V_6 * V_7 )
{
struct V_8 * V_9 = V_7 -> V_8 ;
F_13 ( V_9 ) ;
F_14 ( V_7 -> V_18 ) ;
F_15 ( V_9 ) ;
}
struct V_11 * F_16 ( struct V_28 * V_29 )
{
struct V_11 * V_30 ;
V_30 = F_17 ( & V_29 -> V_23 ,
struct V_11 , V_22 ) ;
if ( V_30 )
F_18 ( & V_30 -> V_22 ) ;
return V_30 ;
}
struct V_11 * F_19 ( struct V_28 * V_29 )
{
struct V_11 * V_12 ;
F_20 ( & V_29 -> V_4 ) ;
V_12 = F_16 ( V_29 ) ;
F_21 ( & V_29 -> V_4 ) ;
return V_12 ;
}
int F_22 ( struct V_11 * V_12 ,
struct V_28 * V_29 )
{
if ( ! V_12 )
return V_21 ;
if ( V_12 -> V_24 ) {
F_23 ( V_12 -> V_24 ) ;
V_12 -> V_24 = NULL ;
}
F_20 ( & V_29 -> V_4 ) ;
F_18 ( & ( V_12 -> V_22 ) ) ;
F_8 ( & ( V_12 -> V_22 ) , F_24 ( V_29 ) ) ;
F_21 ( & V_29 -> V_4 ) ;
return V_14 ;
}
int F_25 ( struct V_11 * V_12 , struct V_28 * V_23 )
{
F_18 ( & ( V_12 -> V_22 ) ) ;
F_8 ( & ( V_12 -> V_22 ) , F_24 ( V_23 ) ) ;
return V_14 ;
}
int F_26 ( struct V_11 * V_12 , struct V_28 * V_23 )
{
int V_31 ;
F_20 ( & V_23 -> V_4 ) ;
V_31 = F_25 ( V_12 , V_23 ) ;
F_21 ( & V_23 -> V_4 ) ;
return V_31 ;
}
void F_27 ( struct V_28 * V_32 , struct V_28 * V_29 )
{
struct V_11 * V_30 ;
struct V_33 * V_34 , * V_35 ;
F_28 ( & V_32 -> V_4 ) ;
V_35 = F_24 ( V_32 ) ;
V_34 = V_35 -> V_36 ;
while ( V_35 != V_34 ) {
V_30 = F_29 ( V_34 , struct V_11 , V_22 ) ;
V_34 = V_34 -> V_36 ;
F_22 ( V_30 , V_29 ) ;
}
F_30 ( & V_32 -> V_4 ) ;
}
T_1 F_13 ( struct V_8 * V_8 )
{
T_1 V_37 = 0 ;
struct V_11 * V_38 ;
while ( ( V_38 = F_19 ( & V_8 -> V_39 . V_17 ) ) ) {
F_22 ( V_38 , & V_8 -> V_39 . V_15 ) ;
F_31 ( L_1 , V_40 ) ;
V_37 ++ ;
}
return V_37 ;
}
static int F_32 ( struct V_8 * V_8 ,
struct V_11 * V_12 )
{
int V_10 , V_13 = V_14 ;
T_1 V_41 ;
V_3 V_42 [ 8 ] ;
V_3 V_43 = false , V_44 = true ;
V_3 * V_45 , * V_46 , * V_47 ;
V_3 * V_48 ;
struct V_49 * V_50 ;
struct V_51 * V_52 = & V_12 -> V_53 ;
struct V_54 * V_55 = & V_8 -> V_56 ;
struct V_57 * V_58 = & V_8 -> V_59 ;
struct V_60 * V_61 = & ( V_58 -> V_62 ) ;
V_50 = F_33 ( & V_8 -> V_63 , & V_52 -> V_64 [ 0 ] ) ;
if ( V_52 -> V_65 == V_66 ) {
F_34 ( V_67 , V_68 , ( L_2 ) ) ;
F_34 ( V_67 , V_68 , ( L_3 ,
V_52 -> V_69 [ 0 ] , V_52 -> V_69 [ 1 ] , V_52 -> V_69 [ 2 ] , V_52 -> V_69 [ 3 ] , V_52 -> V_69 [ 4 ] , V_52 -> V_69 [ 5 ] ) ) ;
if ( V_50 != NULL ) {
if ( F_35 ( V_52 -> V_69 ) ) {
if ( ! V_55 ) {
V_13 = V_21 ;
F_34 ( V_67 , V_70 , ( L_4 ) ) ;
F_31 ( L_4 ) ;
goto exit;
}
V_48 = & V_55 -> V_71 [ V_52 -> V_72 ] . V_73 [ 0 ] ;
F_34 ( V_67 , V_68 , ( L_5 ) ) ;
} else {
V_48 = & V_50 -> V_74 . V_73 [ 0 ] ;
F_34 ( V_67 , V_70 , ( L_6 ) ) ;
}
V_41 = V_12 -> V_24 -> V_75 - V_52 -> V_76 -
V_52 -> V_77 - V_52 -> V_78 - 8 ;
V_45 = V_12 -> V_24 -> V_79 ;
V_46 = V_45 + V_52 -> V_76 + V_52 -> V_77 ;
F_34 ( V_67 , V_68 , ( L_7 , V_52 -> V_77 , V_52 -> V_78 ) ) ;
F_36 ( V_48 , V_45 , V_46 , V_41 , & V_42 [ 0 ] ,
( unsigned char ) V_52 -> V_80 ) ;
V_47 = V_46 + V_41 ;
V_43 = false ;
for ( V_10 = 0 ; V_10 < 8 ; V_10 ++ ) {
if ( V_42 [ V_10 ] != * ( V_47 + V_10 ) ) {
F_34 ( V_67 , V_70 ,
( L_8 ,
V_10 , V_42 [ V_10 ] , V_10 , * ( V_47 + V_10 ) ) ) ;
V_43 = true ;
}
}
if ( V_43 ) {
F_34 ( V_67 , V_70 ,
( L_9 ,
* ( V_47 - 8 ) , * ( V_47 - 7 ) , * ( V_47 - 6 ) ,
* ( V_47 - 5 ) , * ( V_47 - 4 ) , * ( V_47 - 3 ) ,
* ( V_47 - 2 ) , * ( V_47 - 1 ) ) ) ;
F_34 ( V_67 , V_70 ,
( L_10 ,
* ( V_47 - 16 ) , * ( V_47 - 15 ) , * ( V_47 - 14 ) ,
* ( V_47 - 13 ) , * ( V_47 - 12 ) , * ( V_47 - 11 ) ,
* ( V_47 - 10 ) , * ( V_47 - 9 ) ) ) ;
{
T_2 V_10 ;
F_34 ( V_67 , V_70 ,
( L_11 ,
V_12 -> V_24 -> V_75 ) ) ;
for ( V_10 = 0 ; V_10 < V_12 -> V_24 -> V_75 ; V_10 += 8 ) {
F_34 ( V_67 ,
V_70 ,
( L_12 ,
* ( V_12 -> V_24 -> V_79 + V_10 ) ,
* ( V_12 -> V_24 -> V_79 + V_10 + 1 ) ,
* ( V_12 -> V_24 -> V_79 + V_10 + 2 ) ,
* ( V_12 -> V_24 -> V_79 + V_10 + 3 ) ,
* ( V_12 -> V_24 -> V_79 + V_10 + 4 ) ,
* ( V_12 -> V_24 -> V_79 + V_10 + 5 ) ,
* ( V_12 -> V_24 -> V_79 + V_10 + 6 ) ,
* ( V_12 -> V_24 -> V_79 + V_10 + 7 ) ) ) ;
}
F_34 ( V_67 ,
V_70 ,
( L_13 ,
V_12 -> V_24 -> V_75 ) ) ;
F_34 ( V_67 ,
V_70 ,
( L_14 ,
V_52 -> V_76 ) ) ;
}
F_34 ( V_67 , V_70 ,
( L_15 ,
V_52 -> V_69 [ 0 ] , V_52 -> V_69 [ 1 ] , V_52 -> V_69 [ 2 ] ,
V_52 -> V_69 [ 3 ] , V_52 -> V_69 [ 4 ] , V_52 -> V_69 [ 5 ] , V_55 -> V_81 ) ) ;
if ( ( F_35 ( V_52 -> V_69 ) == true ) && ( V_52 -> V_72 != V_61 -> V_72 ) )
V_44 = false ;
if ( ( V_52 -> V_82 ) && ( V_44 ) ) {
F_37 ( V_8 , ( V_3 ) F_35 ( V_52 -> V_69 ) ) ;
F_34 ( V_67 , V_70 , ( L_16 , V_52 -> V_82 ) ) ;
F_31 ( L_17 , V_52 -> V_82 ) ;
} else {
F_34 ( V_67 , V_70 , ( L_16 , V_52 -> V_82 ) ) ;
F_31 ( L_17 , V_52 -> V_82 ) ;
}
V_13 = V_21 ;
} else {
if ( ( ! V_55 -> V_83 ) && ( F_35 ( V_52 -> V_69 ) ) ) {
V_55 -> V_83 = true ;
F_34 ( V_67 , V_70 , ( L_18 ) ) ;
}
}
} else {
F_34 ( V_67 , V_70 , ( L_19 ) ) ;
}
F_38 ( V_12 -> V_24 , V_12 -> V_24 -> V_75 - 8 ) ;
}
exit:
return V_13 ;
}
static struct V_11 * F_39 ( struct V_8 * V_9 ,
struct V_11 * V_84 )
{
struct V_51 * V_52 = & V_84 -> V_53 ;
struct V_54 * V_55 = & V_9 -> V_56 ;
struct V_11 * V_85 = V_84 ;
T_1 V_13 = V_14 ;
F_34 ( V_67 , V_68 , ( L_20 , V_52 -> V_82 , V_52 -> V_65 ) ) ;
if ( V_52 -> V_65 > 0 ) {
V_3 * V_86 = V_84 -> V_24 -> V_79 + V_52 -> V_76 ;
V_52 -> V_72 = ( ( ( V_86 [ 3 ] ) >> 6 ) & 0x3 ) ;
if ( V_52 -> V_72 > V_87 ) {
F_31 ( L_21 , V_52 -> V_72 ) ;
switch ( V_52 -> V_65 ) {
case V_88 :
case V_89 :
V_52 -> V_72 = V_55 -> V_90 ;
break;
case V_66 :
case V_91 :
default:
V_52 -> V_72 = V_55 -> V_92 ;
break;
}
}
}
if ( ( V_52 -> V_65 > 0 ) && ( V_52 -> V_82 == 0 ) ) {
V_55 -> V_93 = false ;
switch ( V_52 -> V_65 ) {
case V_88 :
case V_89 :
F_40 ( V_9 , ( V_3 * ) V_84 ) ;
break;
case V_66 :
V_13 = F_41 ( V_9 , ( V_3 * ) V_84 ) ;
break;
case V_91 :
V_13 = F_42 ( V_9 , ( V_3 * ) V_84 ) ;
break;
default:
break;
}
} else if ( V_52 -> V_82 == 1 && V_52 -> V_65 > 0 &&
( V_55 -> V_94 == 1 || V_52 -> V_65 != V_66 ) )
V_55 -> V_93 = true ;
if ( V_13 == V_21 ) {
F_22 ( V_85 , & V_9 -> V_39 . V_15 ) ;
V_85 = NULL ;
}
return V_85 ;
}
static struct V_11 * F_43 ( struct V_8 * V_8 ,
struct V_11 * V_84 )
{
V_3 * V_95 , * V_96 ;
T_2 V_97 ;
struct V_11 * V_98 ;
struct V_49 * V_99 ;
struct V_100 * V_101 ;
struct V_11 * V_102 ;
T_3 V_103 ;
T_3 V_104 = 0x888e ;
struct V_51 * V_105 ;
T_4 V_106 ;
V_101 = & V_8 -> V_63 ;
V_97 = V_8 -> V_56 . V_107 ;
V_96 = V_84 -> V_24 -> V_79 ;
V_98 = V_84 ;
V_105 = & V_98 -> V_53 ;
V_95 = V_105 -> V_64 ;
V_99 = F_33 ( V_101 , V_95 ) ;
V_102 = NULL ;
F_34 ( V_67 , V_68 , ( L_22 , V_8 -> V_56 . V_107 ) ) ;
if ( V_97 == 2 ) {
V_96 = V_96 + V_98 -> V_53 . V_76 + V_108 + V_98 -> V_53 . V_77 ;
memcpy ( & V_106 , V_96 , 2 ) ;
V_103 = F_44 ( V_106 ) ;
if ( ( V_99 != NULL ) && ( V_99 -> V_109 ) ) {
F_34 ( V_67 , V_68 , ( L_23 ) ) ;
if ( V_103 == V_104 ) {
V_102 = V_84 ;
} else {
F_22 ( V_84 , & V_8 -> V_39 . V_15 ) ;
V_102 = NULL ;
}
} else {
F_34 ( V_67 , V_68 , ( L_24 ) ) ;
F_34 ( V_67 , V_68 ,
( L_25 ,
V_84 -> V_53 . V_110 ) ) ;
if ( V_105 -> V_82 == 0 )
F_34 ( V_67 , V_68 , ( L_26 , V_105 -> V_82 ) ) ;
V_102 = V_84 ;
if ( V_103 == V_104 ) {
F_34 ( V_67 , V_111 , ( L_27 ) ) ;
V_102 = V_84 ;
} else {
F_34 ( V_67 , V_68 , ( L_28 , V_103 ) ) ;
}
}
} else {
V_102 = V_84 ;
}
return V_102 ;
}
static int F_45 ( struct V_11 * V_84 , V_3 V_112 ,
struct V_113 * V_114 )
{
int V_115 = V_84 -> V_53 . V_80 ;
T_3 V_116 = ( ( V_84 -> V_53 . V_117 & 0xffff ) << 4 ) |
( V_84 -> V_53 . V_118 & 0xf ) ;
if ( V_115 > 15 ) {
F_34 ( V_67 , V_111 , ( L_29 , V_116 , V_115 ) ) ;
return V_21 ;
}
if ( 1 ) {
if ( V_116 == V_114 -> V_119 [ V_115 ] ) {
F_34 ( V_67 , V_111 , ( L_30 , V_116 , V_115 , V_114 -> V_119 [ V_115 ] ) ) ;
return V_21 ;
}
}
V_114 -> V_119 [ V_115 ] = V_116 ;
return V_14 ;
}
static void F_46 ( struct V_8 * V_9 ,
struct V_11 * V_84 )
{
#ifdef F_47
unsigned char V_120 ;
V_3 * V_96 = V_84 -> V_24 -> V_79 ;
struct V_51 * V_105 = & V_84 -> V_53 ;
struct V_100 * V_101 = & V_9 -> V_63 ;
struct V_49 * V_99 = NULL ;
V_99 = F_33 ( V_101 , V_105 -> V_121 ) ;
V_120 = F_48 ( V_96 ) ;
if ( V_99 ) {
if ( V_120 ) {
if ( ! ( V_99 -> V_122 & V_123 ) )
F_49 ( V_9 , V_99 ) ;
} else {
if ( V_99 -> V_122 & V_123 )
F_50 ( V_9 , V_99 ) ;
}
}
#endif
}
static void F_51 ( struct V_8 * V_9 ,
struct V_11 * V_84 )
{
#ifdef F_47
struct V_51 * V_105 = & V_84 -> V_53 ;
struct V_100 * V_101 = & V_9 -> V_63 ;
struct V_49 * V_99 = NULL ;
V_99 = F_33 ( V_101 , V_105 -> V_121 ) ;
if ( ! V_99 )
return;
if ( ! V_99 -> V_124 )
return;
if ( ! ( V_99 -> V_125 & 0xf ) )
return;
if ( V_99 -> V_122 & V_123 ) {
V_3 V_126 = 0 ;
switch ( V_105 -> V_80 ) {
case 1 :
case 2 :
V_126 = V_99 -> V_127 & F_52 ( 1 ) ;
break;
case 4 :
case 5 :
V_126 = V_99 -> V_128 & F_52 ( 1 ) ;
break;
case 6 :
case 7 :
V_126 = V_99 -> V_129 & F_52 ( 1 ) ;
break;
case 0 :
case 3 :
default:
V_126 = V_99 -> V_130 & F_52 ( 1 ) ;
break;
}
if ( V_126 ) {
if ( V_99 -> V_131 > 0 ) {
F_53 ( V_9 , V_99 ) ;
} else {
F_54 ( V_9 , V_99 -> V_132 , ( T_3 ) V_105 -> V_80 , 0 , 0 ) ;
}
}
}
#endif
}
static void F_55 ( struct V_8 * V_9 ,
struct V_11 * V_133 ,
struct V_49 * V_134 )
{
int V_135 ;
struct V_49 * V_99 = NULL ;
struct V_136 * V_137 = NULL ;
struct V_51 * V_105 = & V_133 -> V_53 ;
struct V_6 * V_7 = & V_9 -> V_39 ;
V_135 = V_133 -> V_24 -> V_75 ;
V_7 -> V_138 += V_135 ;
V_9 -> V_139 . V_140 . V_141 ++ ;
if ( ( ! F_56 ( V_105 -> V_142 ) ) && ( ! F_35 ( V_105 -> V_142 ) ) )
V_9 -> V_139 . V_140 . V_143 ++ ;
if ( V_134 )
V_99 = V_134 ;
else
V_99 = V_133 -> V_99 ;
if ( V_99 ) {
V_137 = & V_99 -> V_144 ;
V_137 -> V_145 ++ ;
V_137 -> V_138 += V_135 ;
}
}
int F_57 ( struct V_8 * V_8 , struct V_11 * V_84 ,
struct V_49 * * V_99 )
{
int V_31 = V_14 ;
struct V_51 * V_105 = & V_84 -> V_53 ;
struct V_100 * V_101 = & V_8 -> V_63 ;
struct V_146 * V_147 = & V_8 -> V_139 ;
V_3 * V_148 = F_58 ( V_147 ) ;
V_3 * V_149 = F_59 ( & V_8 -> V_150 ) ;
V_3 * V_151 = NULL ;
int V_152 = F_35 ( V_105 -> V_142 ) ;
if ( ( F_60 ( V_147 , V_153 ) == true ) ||
( F_60 ( V_147 , V_154 ) == true ) ) {
if ( ! memcmp ( V_149 , V_105 -> V_121 , V_155 ) ) {
F_34 ( V_67 , V_70 , ( L_31 ) ) ;
V_31 = V_21 ;
goto exit;
}
if ( ( memcmp ( V_149 , V_105 -> V_142 , V_155 ) ) && ( ! V_152 ) ) {
V_31 = V_21 ;
goto exit;
}
if ( ! memcmp ( V_105 -> V_156 , L_32 , V_155 ) ||
! memcmp ( V_148 , L_32 , V_155 ) ||
memcmp ( V_105 -> V_156 , V_148 , V_155 ) ) {
V_31 = V_21 ;
goto exit;
}
V_151 = V_105 -> V_121 ;
} else if ( F_60 ( V_147 , V_157 ) ) {
if ( memcmp ( V_105 -> V_156 , V_105 -> V_121 , V_155 ) ) {
F_34 ( V_67 , V_70 , ( L_33 ) ) ;
V_31 = V_21 ;
goto exit;
}
V_151 = V_105 -> V_156 ;
} else if ( F_60 ( V_147 , V_158 ) ) {
if ( V_152 ) {
if ( ! F_35 ( V_105 -> V_156 ) ) {
V_31 = V_21 ;
goto exit;
}
} else {
if ( memcmp ( V_105 -> V_156 , V_105 -> V_142 , V_155 ) ) {
V_31 = V_21 ;
goto exit;
}
V_151 = V_105 -> V_121 ;
}
} else {
V_31 = V_21 ;
}
if ( V_152 )
* V_99 = F_61 ( V_8 ) ;
else
* V_99 = F_33 ( V_101 , V_151 ) ;
if ( * V_99 == NULL ) {
F_34 ( V_67 , V_70 , ( L_34 ) ) ;
V_31 = V_21 ;
goto exit;
}
exit:
return V_31 ;
}
static int F_62 (
struct V_8 * V_8 ,
struct V_11 * V_84 ,
struct V_49 * * V_99 )
{
V_3 * V_96 = V_84 -> V_24 -> V_79 ;
struct V_51 * V_105 = & V_84 -> V_53 ;
int V_31 = V_14 ;
struct V_100 * V_101 = & V_8 -> V_63 ;
struct V_146 * V_147 = & V_8 -> V_139 ;
V_3 * V_148 = F_58 ( V_147 ) ;
V_3 * V_149 = F_59 ( & V_8 -> V_150 ) ;
int V_152 = F_35 ( V_105 -> V_142 ) ;
if ( ( F_60 ( V_147 , V_157 ) == true ) &&
( F_60 ( V_147 , V_159 ) == true ||
F_60 ( V_147 , V_160 ) ) ) {
if ( ! memcmp ( V_149 , V_105 -> V_121 , V_155 ) ) {
F_34 ( V_67 , V_70 , ( L_31 ) ) ;
V_31 = V_21 ;
goto exit;
}
if ( ( memcmp ( V_149 , V_105 -> V_142 , V_155 ) ) && ( ! V_152 ) ) {
F_34 ( V_67 , V_68 ,
( L_35 , ( V_105 -> V_142 ) ) ) ;
V_31 = V_21 ;
goto exit;
}
if ( ! memcmp ( V_105 -> V_156 , L_32 , V_155 ) ||
! memcmp ( V_148 , L_32 , V_155 ) ||
( memcmp ( V_105 -> V_156 , V_148 , V_155 ) ) ) {
F_34 ( V_67 , V_68 ,
( L_36 , ( V_105 -> V_156 ) ) ) ;
F_34 ( V_67 , V_68 , ( L_37 , ( V_148 ) ) ) ;
if ( ! V_152 ) {
F_31 ( L_38 , ( V_105 -> V_156 ) ) ;
F_63 ( V_8 , V_105 -> V_156 , V_161 ) ;
}
V_31 = V_21 ;
goto exit;
}
if ( V_152 )
* V_99 = F_61 ( V_8 ) ;
else
* V_99 = F_33 ( V_101 , V_105 -> V_156 ) ;
if ( * V_99 == NULL ) {
F_34 ( V_67 , V_70 , ( L_39 ) ) ;
V_31 = V_21 ;
goto exit;
}
if ( F_64 ( V_96 ) & F_52 ( 6 ) ) {
F_55 ( V_8 , V_84 , * V_99 ) ;
V_31 = V_162 ;
goto exit;
}
} else if ( F_60 ( V_147 , V_158 ) ) {
V_31 = V_162 ;
goto exit;
} else {
if ( ! memcmp ( V_149 , V_105 -> V_142 , V_155 ) && ( ! V_152 ) ) {
* V_99 = F_33 ( V_101 , V_105 -> V_156 ) ;
if ( * V_99 == NULL ) {
F_31 ( L_40 , ( V_105 -> V_156 ) ) ;
F_63 ( V_8 , V_105 -> V_156 , V_161 ) ;
}
}
V_31 = V_21 ;
}
exit:
return V_31 ;
}
static int F_65 ( struct V_8 * V_8 ,
struct V_11 * V_84 ,
struct V_49 * * V_99 )
{
struct V_51 * V_105 = & V_84 -> V_53 ;
struct V_100 * V_101 = & V_8 -> V_63 ;
struct V_146 * V_147 = & V_8 -> V_139 ;
V_3 * V_96 = V_84 -> V_24 -> V_79 ;
unsigned char * V_148 = F_58 ( V_147 ) ;
int V_31 = V_14 ;
if ( F_60 ( V_147 , V_158 ) == true ) {
if ( memcmp ( V_105 -> V_156 , V_148 , V_155 ) ) {
V_31 = V_21 ;
goto exit;
}
* V_99 = F_33 ( V_101 , V_105 -> V_121 ) ;
if ( * V_99 == NULL ) {
F_34 ( V_67 , V_70 , ( L_41 ) ) ;
F_31 ( L_42 , ( V_105 -> V_121 ) ) ;
F_63 ( V_8 , V_105 -> V_121 , V_161 ) ;
V_31 = V_162 ;
goto exit;
}
F_46 ( V_8 , V_84 ) ;
if ( ( F_64 ( V_96 ) & V_163 ) == V_163 )
F_51 ( V_8 , V_84 ) ;
if ( F_64 ( V_96 ) & F_52 ( 6 ) ) {
F_55 ( V_8 , V_84 , * V_99 ) ;
V_31 = V_162 ;
goto exit;
}
} else {
V_3 * V_149 = F_59 ( & V_8 -> V_150 ) ;
if ( memcmp ( V_105 -> V_69 , V_149 , V_155 ) ) {
V_31 = V_162 ;
goto exit;
}
F_31 ( L_42 , ( V_105 -> V_121 ) ) ;
F_63 ( V_8 , V_105 -> V_121 , V_161 ) ;
V_31 = V_162 ;
goto exit;
}
exit:
return V_31 ;
}
static int F_66 ( struct V_8 * V_9 ,
struct V_11 * V_84 )
{
#ifdef F_47
struct V_51 * V_105 = & V_84 -> V_53 ;
struct V_100 * V_101 = & V_9 -> V_63 ;
V_3 * V_45 = V_84 -> V_24 -> V_79 ;
if ( F_67 ( V_45 ) != V_164 )
return V_21 ;
if ( memcmp ( F_68 ( V_45 ) , F_59 ( & V_9 -> V_150 ) , V_155 ) )
return V_21 ;
if ( F_64 ( V_45 ) == V_165 ) {
T_3 V_166 ;
V_3 V_126 = 0 ;
struct V_49 * V_99 = NULL ;
V_166 = F_69 ( V_45 ) ;
V_99 = F_33 ( V_101 , F_70 ( V_45 ) ) ;
if ( ( V_99 == NULL ) || ( V_99 -> V_166 != V_166 ) )
return V_21 ;
V_99 -> V_144 . V_167 ++ ;
switch ( V_105 -> V_80 ) {
case 1 :
case 2 :
V_126 = V_99 -> V_127 & F_52 ( 0 ) ;
break;
case 4 :
case 5 :
V_126 = V_99 -> V_128 & F_52 ( 0 ) ;
break;
case 6 :
case 7 :
V_126 = V_99 -> V_129 & F_52 ( 0 ) ;
break;
case 0 :
case 3 :
default:
V_126 = V_99 -> V_130 & F_52 ( 0 ) ;
break;
}
if ( V_126 )
return V_21 ;
if ( V_99 -> V_122 & V_168 ) {
F_31 ( L_43 , V_40 ) ;
V_99 -> V_169 = V_101 -> V_169 ;
V_99 -> V_122 ^= V_168 ;
}
if ( ( V_99 -> V_122 & V_123 ) && ( V_101 -> V_170 & F_52 ( V_99 -> V_166 ) ) ) {
struct V_33 * V_171 , * V_172 ;
struct V_173 * V_174 = NULL ;
F_20 ( & V_99 -> V_175 . V_4 ) ;
V_172 = F_24 ( & V_99 -> V_175 ) ;
V_171 = V_172 -> V_36 ;
if ( V_172 != V_171 ) {
V_174 = F_29 ( V_171 , struct V_173 , V_22 ) ;
V_171 = V_171 -> V_36 ;
F_18 ( & V_174 -> V_22 ) ;
V_99 -> V_176 -- ;
if ( V_99 -> V_176 > 0 )
V_174 -> V_53 . V_177 = 1 ;
else
V_174 -> V_53 . V_177 = 0 ;
V_174 -> V_53 . V_178 = 1 ;
F_21 ( & V_99 -> V_175 . V_4 ) ;
if ( F_71 ( V_9 , V_174 ) == true )
F_72 ( V_9 , V_174 ) ;
F_20 ( & V_99 -> V_175 . V_4 ) ;
if ( V_99 -> V_176 == 0 ) {
V_101 -> V_179 &= ~ F_52 ( V_99 -> V_166 ) ;
F_73 ( V_9 , V_180 , NULL , false ) ;
}
} else {
if ( V_101 -> V_179 & F_52 ( V_99 -> V_166 ) ) {
if ( V_99 -> V_176 == 0 ) {
F_31 ( L_44 ) ;
F_74 ( V_9 , V_99 -> V_132 , 0 , 0 , 0 ) ;
} else {
F_31 ( L_45 , V_99 -> V_176 ) ;
V_99 -> V_176 = 0 ;
}
V_101 -> V_179 &= ~ F_52 ( V_99 -> V_166 ) ;
F_73 ( V_9 , V_180 , NULL , false ) ;
}
}
F_21 ( & V_99 -> V_175 . V_4 ) ;
}
}
#endif
return V_21 ;
}
static int F_75 ( struct V_8 * V_9 ,
struct V_11 * V_84 )
{
struct V_49 * V_99 ;
F_34 ( V_67 , V_68 , ( L_46 ) ) ;
V_84 = F_76 ( V_9 , V_84 ) ;
if ( V_84 == NULL ) {
F_34 ( V_67 , V_111 , ( L_47 , V_40 ) ) ;
return V_14 ;
}
V_99 = F_33 ( & V_9 -> V_63 ,
F_70 ( V_84 -> V_24 -> V_79 ) ) ;
if ( V_99 ) {
V_99 -> V_144 . V_181 ++ ;
if ( F_64 ( V_84 -> V_24 -> V_79 ) == V_182 ) {
V_99 -> V_144 . V_183 ++ ;
} else if ( F_64 ( V_84 -> V_24 -> V_79 ) == V_184 ) {
V_99 -> V_144 . V_185 ++ ;
} else if ( F_64 ( V_84 -> V_24 -> V_79 ) == V_186 ) {
if ( ! memcmp ( V_9 -> V_150 . V_187 ,
F_68 ( V_84 -> V_24 -> V_79 ) , V_155 ) )
V_99 -> V_144 . V_188 ++ ;
else if ( F_77 ( F_68 ( V_84 -> V_24 -> V_79 ) ) ||
F_78 ( F_68 ( V_84 -> V_24 -> V_79 ) ) )
V_99 -> V_144 . V_189 ++ ;
else
V_99 -> V_144 . V_190 ++ ;
}
}
F_79 ( V_9 , V_84 ) ;
return V_14 ;
}
static int F_80 ( struct V_8 * V_8 ,
struct V_11 * V_84 )
{
V_3 V_112 ;
V_3 * V_191 , * V_192 , * V_193 ;
struct V_49 * V_99 = NULL ;
V_3 * V_96 = V_84 -> V_24 -> V_79 ;
struct V_51 * V_105 = & V_84 -> V_53 ;
struct V_54 * V_55 = & V_8 -> V_56 ;
int V_31 = V_14 ;
V_112 = F_81 ( V_96 ) ;
V_192 = F_82 ( V_96 ) ;
V_191 = F_83 ( V_96 ) ;
V_193 = F_84 ( V_96 ) ;
if ( V_193 == NULL ) {
V_31 = V_21 ;
goto exit;
}
memcpy ( V_105 -> V_142 , V_192 , V_155 ) ;
memcpy ( V_105 -> V_121 , V_191 , V_155 ) ;
memcpy ( V_105 -> V_156 , V_193 , V_155 ) ;
switch ( V_105 -> V_194 ) {
case 0 :
memcpy ( V_105 -> V_69 , V_192 , V_155 ) ;
memcpy ( V_105 -> V_64 , V_191 , V_155 ) ;
V_31 = F_57 ( V_8 , V_84 , & V_99 ) ;
break;
case 1 :
memcpy ( V_105 -> V_69 , V_192 , V_155 ) ;
memcpy ( V_105 -> V_64 , V_193 , V_155 ) ;
V_31 = F_62 ( V_8 , V_84 , & V_99 ) ;
break;
case 2 :
memcpy ( V_105 -> V_69 , V_193 , V_155 ) ;
memcpy ( V_105 -> V_64 , V_191 , V_155 ) ;
V_31 = F_65 ( V_8 , V_84 , & V_99 ) ;
break;
case 3 :
memcpy ( V_105 -> V_69 , F_68 ( V_96 ) , V_155 ) ;
memcpy ( V_105 -> V_64 , F_70 ( V_96 ) , V_155 ) ;
V_31 = V_21 ;
F_34 ( V_67 , V_70 , ( L_48 ) ) ;
break;
default:
V_31 = V_21 ;
break;
}
if ( V_31 == V_21 )
goto exit;
else if ( V_31 == V_162 )
goto exit;
if ( V_99 == NULL ) {
F_34 ( V_67 , V_70 , ( L_49 ) ) ;
V_31 = V_21 ;
goto exit;
}
V_84 -> V_99 = V_99 ;
V_105 -> V_195 = 0 ;
V_105 -> V_196 = 0 ;
if ( V_105 -> V_197 == 1 ) {
V_105 -> V_80 = F_85 ( ( V_96 + 24 ) ) ;
V_105 -> V_196 = F_86 ( ( V_96 + 24 ) ) ;
V_105 -> V_195 = F_87 ( ( V_96 + 24 ) ) ;
V_105 -> V_76 = V_105 -> V_194 == 3 ? 32 : 26 ;
if ( V_105 -> V_80 != 0 && V_105 -> V_80 != 3 )
V_8 -> V_39 . V_198 = true ;
} else {
V_105 -> V_80 = 0 ;
V_105 -> V_76 = V_105 -> V_194 == 3 ? 30 : 24 ;
}
if ( V_105 -> V_199 )
V_105 -> V_76 += 4 ;
V_84 -> V_200 = & V_99 -> V_201 [ V_105 -> V_80 ] ;
if ( F_45 ( V_84 , V_112 , & V_99 -> V_202 . V_203 ) == V_21 ) {
F_34 ( V_67 , V_70 , ( L_50 ) ) ;
V_31 = V_21 ;
goto exit;
}
if ( V_105 -> V_110 ) {
F_34 ( V_67 , V_68 , ( L_51 , V_105 -> V_110 ) ) ;
F_34 ( V_67 , V_68 , ( L_52 , V_105 -> V_69 [ 0 ] , F_35 ( V_105 -> V_69 ) ) ) ;
F_88 ( V_55 , V_99 , V_105 -> V_65 , F_35 ( V_105 -> V_69 ) ) ;
F_34 ( V_67 , V_68 , ( L_53 , V_105 -> V_65 ) ) ;
F_89 ( V_105 -> V_77 , V_105 -> V_78 , V_105 -> V_65 ) ;
} else {
V_105 -> V_65 = 0 ;
V_105 -> V_77 = 0 ;
V_105 -> V_78 = 0 ;
}
exit:
return V_31 ;
}
static int F_90 ( struct V_8 * V_8 ,
struct V_11 * V_84 )
{
V_3 type ;
V_3 V_204 ;
int V_205 = V_14 ;
V_3 V_206 ;
struct V_51 * V_105 = & V_84 -> V_53 ;
V_3 * V_96 = V_84 -> V_24 -> V_79 ;
V_3 V_207 = ( unsigned char ) ( * V_96 ) & 0x3 ;
struct V_57 * V_58 = & V_8 -> V_59 ;
if ( V_58 -> V_208 . V_122 == V_209 ) {
int V_210 = F_91 ( V_58 -> V_211 , F_92 ( V_8 ) ) ;
if ( V_210 >= 0 )
V_58 -> V_211 [ V_210 ] . V_212 ++ ;
}
if ( V_207 != 0 ) {
F_34 ( V_67 , V_70 , ( L_54 ) ) ;
V_205 = V_21 ;
goto exit;
}
type = F_67 ( V_96 ) ;
V_204 = F_64 ( V_96 ) ;
V_105 -> V_194 = F_93 ( V_96 ) ;
V_105 -> V_118 = F_94 ( V_96 ) ;
V_105 -> V_117 = F_95 ( V_96 ) ;
V_105 -> V_213 = F_48 ( V_96 ) ;
V_105 -> V_214 = F_96 ( V_96 ) ;
V_105 -> V_177 = F_97 ( V_96 ) ;
V_105 -> V_110 = F_98 ( V_96 ) ;
V_105 -> V_199 = F_99 ( V_96 ) ;
F_100 ( V_8 , V_215 , & ( V_206 ) ) ;
if ( V_206 == 1 ) {
if ( V_70 <= V_216 ) {
F_101 ( V_217 L_55 ) ;
F_102 ( V_218 , V_217 , V_219 ,
16 , 1 , V_96 , 64 , false ) ;
F_101 ( V_217 L_55 ) ;
}
} else if ( V_206 == 2 ) {
if ( ( V_70 <= V_216 ) && ( type == V_220 ) ) {
F_101 ( V_217 L_55 ) ;
F_102 ( V_218 , V_217 , V_219 ,
16 , 1 , V_96 , 64 , false ) ;
F_101 ( V_217 L_55 ) ;
}
} else if ( V_206 == 3 ) {
if ( ( V_70 <= V_216 ) && ( type == V_221 ) ) {
F_101 ( V_217 L_55 ) ;
F_102 ( V_218 , V_217 , V_219 ,
16 , 1 , V_96 , 64 , false ) ;
F_101 ( V_217 L_55 ) ;
}
}
switch ( type ) {
case V_220 :
V_205 = F_75 ( V_8 , V_84 ) ;
if ( V_205 == V_21 )
F_34 ( V_67 , V_70 , ( L_56 ) ) ;
V_205 = V_21 ;
break;
case V_164 :
V_205 = F_66 ( V_8 , V_84 ) ;
if ( V_205 == V_21 )
F_34 ( V_67 , V_70 , ( L_57 ) ) ;
V_205 = V_21 ;
break;
case V_221 :
F_103 ( V_8 , V_222 ) ;
V_105 -> V_197 = ( V_204 & F_52 ( 7 ) ) ? 1 : 0 ;
V_205 = F_80 ( V_8 , V_84 ) ;
if ( V_205 == V_21 ) {
struct V_6 * V_7 = & V_8 -> V_39 ;
V_7 -> V_223 ++ ;
}
break;
default:
F_34 ( V_67 , V_70 , ( L_58 , type ) ) ;
V_205 = V_21 ;
break;
}
F_104 ( V_8 -> V_224 , V_84 ) ;
exit:
return V_205 ;
}
static int F_105 ( struct V_11 * V_12 )
{
int V_225 ;
T_3 V_226 , V_75 ;
T_4 V_106 ;
V_3 V_227 ;
V_3 * V_228 ;
struct V_229 * V_230 ;
V_3 * V_96 = V_12 -> V_24 -> V_79 ;
struct V_51 * V_105 = & V_12 -> V_53 ;
if ( V_105 -> V_65 )
F_38 ( V_12 -> V_24 , V_12 -> V_24 -> V_75 - V_105 -> V_78 ) ;
V_230 = (struct V_229 * ) ( V_96 + V_105 -> V_76 + V_105 -> V_77 ) ;
V_228 = V_96 + V_105 -> V_76 + V_105 -> V_77 + V_231 ;
if ( ( ! memcmp ( V_230 , V_232 , V_231 ) &&
( ! memcmp ( V_228 , V_233 , 2 ) == false ) &&
( ! memcmp ( V_228 , V_234 , 2 ) == false ) ) ||
! memcmp ( V_230 , V_235 , V_231 ) ) {
V_227 = true ;
} else {
V_227 = false ;
}
V_225 = V_105 -> V_76 + V_105 -> V_77 + ( V_227 ? V_231 : 0 ) ;
V_75 = V_12 -> V_24 -> V_75 - V_225 ;
F_34 ( V_67 , V_68 ,
( L_59 , V_105 -> V_76 , V_105 -> V_77 ) ) ;
memcpy ( & V_106 , V_96 + V_225 , 2 ) ;
V_226 = F_44 ( V_106 ) ;
V_105 -> V_226 = V_226 ;
V_96 = F_106 ( V_12 -> V_24 , V_225 - sizeof( struct V_236 ) + ( V_227 ? 2 : 0 ) ) ;
if ( ! V_96 )
return V_21 ;
memcpy ( V_96 , V_105 -> V_142 , V_155 ) ;
memcpy ( V_96 + V_155 , V_105 -> V_121 , V_155 ) ;
if ( ! V_227 ) {
V_106 = F_107 ( V_75 ) ;
memcpy ( V_96 + 12 , & V_106 , 2 ) ;
}
return V_14 ;
}
static struct V_11 * F_108 ( struct V_8 * V_8 ,
struct V_28 * V_5 )
{
struct V_33 * V_34 , * V_35 ;
V_3 V_237 ;
V_3 V_238 ;
struct V_11 * V_98 , * V_239 ;
struct V_11 * V_133 , * V_240 ;
struct V_28 * V_29 ;
V_238 = 0 ;
V_29 = & V_8 -> V_39 . V_15 ;
V_35 = F_24 ( V_5 ) ;
V_34 = V_35 -> V_36 ;
V_98 = F_29 ( V_34 , struct V_11 , V_22 ) ;
V_133 = V_98 ;
F_18 ( & ( V_133 -> V_22 ) ) ;
if ( V_238 != V_98 -> V_53 . V_118 ) {
F_22 ( V_133 , V_29 ) ;
F_27 ( V_5 , V_29 ) ;
return NULL ;
}
V_238 ++ ;
V_34 = F_24 ( V_5 ) ;
V_34 = V_34 -> V_36 ;
while ( V_35 != V_34 ) {
V_239 = F_29 ( V_34 , struct V_11 , V_22 ) ;
V_240 = V_239 ;
if ( V_238 != V_239 -> V_53 . V_118 ) {
F_22 ( V_133 , V_29 ) ;
F_27 ( V_5 , V_29 ) ;
return NULL ;
}
V_238 ++ ;
V_237 = V_239 -> V_53 . V_76 + V_239 -> V_53 . V_77 ;
F_106 ( V_240 -> V_24 , V_237 ) ;
F_38 ( V_133 -> V_24 , V_133 -> V_24 -> V_75 - V_98 -> V_53 . V_78 ) ;
memcpy ( F_109 ( V_98 -> V_24 ) , V_239 -> V_24 -> V_79 ,
V_239 -> V_24 -> V_75 ) ;
F_110 ( V_133 -> V_24 , V_239 -> V_24 -> V_75 ) ;
V_98 -> V_53 . V_78 = V_239 -> V_53 . V_78 ;
V_34 = V_34 -> V_36 ;
}
F_27 ( V_5 , V_29 ) ;
F_34 ( V_67 , V_68 , ( L_60 ) ) ;
return V_133 ;
}
struct V_11 * F_76 ( struct V_8 * V_9 ,
struct V_11 * V_84 )
{
V_3 V_241 ;
V_3 V_242 ;
V_3 * V_95 ;
struct V_11 * V_98 ;
struct V_49 * V_99 ;
struct V_100 * V_101 ;
struct V_33 * V_35 ;
struct V_11 * V_102 = NULL ;
struct V_28 * V_29 , * V_243 ;
V_101 = & V_9 -> V_63 ;
V_98 = V_84 ;
V_29 = & V_9 -> V_39 . V_15 ;
V_241 = V_98 -> V_53 . V_214 ;
V_242 = V_98 -> V_53 . V_118 ;
V_95 = V_98 -> V_53 . V_64 ;
V_99 = F_33 ( V_101 , V_95 ) ;
if ( V_99 == NULL ) {
V_3 type = F_67 ( V_98 -> V_24 -> V_79 ) ;
if ( type != V_221 ) {
V_99 = F_61 ( V_9 ) ;
V_243 = & V_99 -> V_202 . V_5 ;
} else {
V_243 = NULL ;
}
} else {
V_243 = & V_99 -> V_202 . V_5 ;
}
if ( ( V_241 == 0 ) && ( V_242 == 0 ) )
V_102 = V_84 ;
if ( V_241 == 1 ) {
if ( V_243 != NULL ) {
if ( V_242 == 0 ) {
if ( ! F_111 ( & V_243 -> V_23 ) )
F_27 ( V_243 , V_29 ) ;
}
V_35 = F_24 ( V_243 ) ;
F_8 ( & V_98 -> V_22 , V_35 ) ;
F_34 ( V_67 , V_68 , ( L_61 , V_241 , V_242 ) ) ;
V_102 = NULL ;
} else {
F_22 ( V_84 , V_29 ) ;
V_102 = NULL ;
F_34 ( V_67 , V_70 , ( L_62 , V_241 , V_242 ) ) ;
}
}
if ( ( V_241 == 0 ) && ( V_242 != 0 ) ) {
if ( V_243 != NULL ) {
V_35 = F_24 ( V_243 ) ;
F_8 ( & V_98 -> V_22 , V_35 ) ;
F_34 ( V_67 , V_68 , ( L_63 , V_241 , V_242 ) ) ;
V_84 = F_108 ( V_9 , V_243 ) ;
V_102 = V_84 ;
} else {
F_22 ( V_84 , V_29 ) ;
V_102 = NULL ;
F_34 ( V_67 , V_70 , ( L_62 , V_241 , V_242 ) ) ;
}
}
if ( ( V_102 != NULL ) && ( V_102 -> V_53 . V_110 ) ) {
if ( F_32 ( V_9 , V_102 ) == V_21 ) {
F_34 ( V_67 , V_70 , ( L_64 ) ) ;
F_22 ( V_102 , V_29 ) ;
V_102 = NULL ;
}
}
return V_102 ;
}
static int F_112 ( struct V_8 * V_9 , struct V_11 * V_133 )
{
int V_244 , V_245 ;
T_3 V_226 , V_246 ;
V_3 V_247 , V_10 ;
unsigned char * V_248 ;
struct V_51 * V_105 ;
unsigned char * V_249 ;
struct V_250 * V_251 , * V_252 [ V_253 ] ;
struct V_6 * V_7 = & V_9 -> V_39 ;
struct V_28 * V_29 = & ( V_7 -> V_15 ) ;
V_247 = 0 ;
V_105 = & V_133 -> V_53 ;
F_106 ( V_133 -> V_24 , V_133 -> V_53 . V_76 ) ;
if ( V_133 -> V_53 . V_77 > 0 )
F_106 ( V_133 -> V_24 , V_133 -> V_53 . V_77 ) ;
V_244 = V_133 -> V_24 -> V_75 ;
V_248 = V_133 -> V_24 -> V_79 ;
while ( V_244 > V_254 ) {
V_246 = F_113 ( V_248 + 12 ) ;
if ( V_244 < ( V_255 + V_246 ) ) {
F_31 ( L_65 , V_244 , V_246 ) ;
goto exit;
}
V_248 += V_254 ;
V_244 -= V_254 ;
V_251 = F_114 ( V_246 + 12 ) ;
if ( V_251 ) {
F_115 ( V_251 , 12 ) ;
V_249 = ( V_3 * ) F_110 ( V_251 , V_246 ) ;
memcpy ( V_249 , V_248 , V_246 ) ;
} else {
V_251 = F_116 ( V_133 -> V_24 , V_256 ) ;
if ( V_251 ) {
V_251 -> V_79 = V_248 ;
V_251 -> V_75 = V_246 ;
F_117 ( V_251 , V_246 ) ;
} else {
F_31 ( L_66 , V_247 ) ;
break;
}
}
V_252 [ V_247 ++ ] = V_251 ;
if ( V_247 >= V_253 ) {
F_31 ( L_67 ) ;
break;
}
V_248 += V_246 ;
V_244 -= V_246 ;
if ( V_244 != 0 ) {
V_245 = 4 - ( ( V_246 + V_254 ) & ( 4 - 1 ) ) ;
if ( V_245 == 4 )
V_245 = 0 ;
if ( V_244 < V_245 )
goto exit;
V_248 += V_245 ;
V_244 -= V_245 ;
}
}
for ( V_10 = 0 ; V_10 < V_247 ; V_10 ++ ) {
V_251 = V_252 [ V_10 ] ;
V_226 = F_113 ( & V_251 -> V_79 [ 6 ] ) ;
if ( V_251 -> V_75 >= 8 &&
( ( ! memcmp ( V_251 -> V_79 , V_232 , V_231 ) &&
V_226 != V_257 && V_226 != V_258 ) ||
! memcmp ( V_251 -> V_79 , V_235 , V_231 ) ) ) {
F_106 ( V_251 , V_231 ) ;
memcpy ( F_118 ( V_251 , V_155 ) , V_105 -> V_121 , V_155 ) ;
memcpy ( F_118 ( V_251 , V_155 ) , V_105 -> V_142 , V_155 ) ;
} else {
T_4 V_75 ;
V_75 = F_107 ( V_251 -> V_75 ) ;
memcpy ( F_118 ( V_251 , 2 ) , & V_75 , 2 ) ;
memcpy ( F_118 ( V_251 , V_155 ) , V_105 -> V_121 , V_155 ) ;
memcpy ( F_118 ( V_251 , V_155 ) , V_105 -> V_142 , V_155 ) ;
}
V_251 -> V_259 = F_119 ( V_251 , V_9 -> V_260 ) ;
V_251 -> V_261 = V_9 -> V_260 ;
V_251 -> V_262 = V_263 ;
F_120 ( V_251 ) ;
}
exit:
F_22 ( V_133 , V_29 ) ;
return V_14 ;
}
static int F_121 ( struct V_264 * V_200 , T_3 V_117 )
{
V_3 V_265 = V_200 -> V_266 ;
T_3 V_267 = ( V_200 -> V_268 + V_265 - 1 ) & 0xFFF ;
if ( V_200 -> V_268 == 0xFFFF )
V_200 -> V_268 = V_117 ;
if ( F_122 ( V_117 , V_200 -> V_268 ) )
return false ;
if ( F_123 ( V_117 , V_200 -> V_268 ) ) {
V_200 -> V_268 = ( V_200 -> V_268 + 1 ) & 0xFFF ;
} else if ( F_122 ( V_267 , V_117 ) ) {
if ( V_117 >= ( V_265 - 1 ) )
V_200 -> V_268 = V_117 + 1 - V_265 ;
else
V_200 -> V_268 = 0xFFF - ( V_265 - ( V_117 + 1 ) ) + 1 ;
}
return true ;
}
static int F_124 ( struct V_264 * V_200 ,
struct V_11 * V_133 )
{
struct V_51 * V_105 = & V_133 -> V_53 ;
struct V_28 * V_269 = & V_200 -> V_270 ;
struct V_33 * V_35 , * V_34 ;
struct V_11 * V_30 ;
struct V_51 * V_271 ;
V_35 = F_24 ( V_269 ) ;
V_34 = V_35 -> V_36 ;
while ( V_35 != V_34 ) {
V_30 = F_29 ( V_34 , struct V_11 , V_22 ) ;
V_271 = & V_30 -> V_53 ;
if ( F_122 ( V_271 -> V_117 , V_105 -> V_117 ) )
V_34 = V_34 -> V_36 ;
else if ( F_123 ( V_271 -> V_117 , V_105 -> V_117 ) )
return false ;
else
break;
}
F_18 ( & ( V_133 -> V_22 ) ) ;
F_8 ( & ( V_133 -> V_22 ) , V_34 ) ;
return true ;
}
static int F_125 ( struct V_8 * V_9 , struct V_264 * V_200 , int V_272 )
{
struct V_33 * V_35 , * V_34 ;
struct V_11 * V_133 ;
struct V_11 * V_273 ;
struct V_51 * V_105 ;
int V_274 = false ;
struct V_6 * V_7 = & V_9 -> V_39 ;
struct V_28 * V_269 = & V_200 -> V_270 ;
V_35 = F_24 ( V_269 ) ;
V_34 = V_35 -> V_36 ;
if ( V_272 ) {
if ( F_111 ( V_35 ) )
return true ;
V_273 = F_29 ( V_34 , struct V_11 , V_22 ) ;
V_105 = & V_273 -> V_53 ;
V_200 -> V_268 = V_105 -> V_117 ;
}
while ( ! F_111 ( V_35 ) ) {
V_273 = F_29 ( V_34 , struct V_11 , V_22 ) ;
V_133 = V_273 ;
V_105 = & V_133 -> V_53 ;
if ( ! F_122 ( V_200 -> V_268 , V_105 -> V_117 ) ) {
F_34 ( V_67 , V_111 ,
( L_68 ,
V_200 -> V_268 , V_105 -> V_117 , V_105 -> V_195 ) ) ;
V_34 = V_34 -> V_36 ;
F_18 ( & ( V_133 -> V_22 ) ) ;
if ( F_123 ( V_200 -> V_268 , V_105 -> V_117 ) )
V_200 -> V_268 = ( V_200 -> V_268 + 1 ) & 0xFFF ;
if ( ! V_105 -> V_195 ) {
if ( ( ! V_9 -> V_275 ) &&
( ! V_9 -> V_276 ) )
F_126 ( V_9 , V_133 ) ;
} else if ( V_105 -> V_195 == 1 ) {
if ( F_112 ( V_9 , V_133 ) != V_14 )
F_22 ( V_133 , & V_7 -> V_15 ) ;
} else {
}
V_274 = false ;
} else {
V_274 = true ;
break;
}
}
return V_274 ;
}
static int F_127 ( struct V_8 * V_9 ,
struct V_11 * V_133 )
{
int V_205 = V_14 ;
struct V_51 * V_105 = & V_133 -> V_53 ;
struct V_264 * V_200 = V_133 -> V_200 ;
struct V_28 * V_269 = & V_200 -> V_270 ;
if ( ! V_105 -> V_195 ) {
F_105 ( V_133 ) ;
if ( ( V_105 -> V_197 != 1 ) || ( V_105 -> V_226 == 0x0806 ) ||
( V_105 -> V_196 != 0 ) ) {
if ( ( ! V_9 -> V_275 ) &&
( ! V_9 -> V_276 ) ) {
F_34 ( V_67 , V_111 , ( L_69 ) ) ;
F_126 ( V_9 , V_133 ) ;
return V_14 ;
}
return V_21 ;
}
if ( ! V_200 -> V_277 ) {
V_200 -> V_268 = V_105 -> V_117 ;
F_126 ( V_9 , V_133 ) ;
V_200 -> V_268 = ( V_200 -> V_268 + 1 ) % 4096 ;
return V_14 ;
}
} else if ( V_105 -> V_195 == 1 ) {
if ( ! V_200 -> V_277 ) {
V_200 -> V_268 = V_105 -> V_117 ;
V_205 = F_112 ( V_9 , V_133 ) ;
V_200 -> V_268 = ( V_200 -> V_268 + 1 ) % 4096 ;
return V_205 ;
}
}
F_20 ( & V_269 -> V_4 ) ;
F_34 ( V_67 , V_111 ,
( L_70 ,
V_200 -> V_268 , V_105 -> V_117 ) ) ;
if ( ! F_121 ( V_200 , V_105 -> V_117 ) ) {
F_126 ( V_9 , V_133 ) ;
F_21 ( & V_269 -> V_4 ) ;
goto V_278;
}
if ( ! F_124 ( V_200 , V_133 ) )
goto V_279;
if ( F_125 ( V_9 , V_200 , false ) ) {
F_128 ( & V_200 -> V_280 ,
V_281 + F_129 ( V_282 ) ) ;
F_21 ( & V_269 -> V_4 ) ;
} else {
F_21 ( & V_269 -> V_4 ) ;
F_130 ( & V_200 -> V_280 ) ;
}
V_278:
return V_14 ;
V_279:
F_21 ( & V_269 -> V_4 ) ;
return V_21 ;
}
void F_131 ( unsigned long V_79 )
{
struct V_264 * V_200 = (struct V_264 * ) V_79 ;
struct V_8 * V_9 = V_200 -> V_9 ;
struct V_28 * V_269 = & V_200 -> V_270 ;
if ( V_9 -> V_275 || V_9 -> V_276 )
return;
F_20 ( & V_269 -> V_4 ) ;
if ( F_125 ( V_9 , V_200 , true ) == true )
F_128 ( & V_200 -> V_280 ,
V_281 + F_129 ( V_282 ) ) ;
F_21 ( & V_269 -> V_4 ) ;
}
static int F_132 ( struct V_8 * V_9 ,
struct V_11 * V_133 )
{
int V_205 = V_14 ;
struct V_146 * V_147 = & V_9 -> V_139 ;
struct V_283 * V_284 = & V_147 -> V_285 ;
if ( V_284 -> V_286 ) {
if ( F_127 ( V_9 , V_133 ) != V_14 ) {
if ( ( ! V_9 -> V_275 ) &&
( ! V_9 -> V_276 ) ) {
V_205 = V_21 ;
return V_205 ;
}
}
} else {
V_205 = F_105 ( V_133 ) ;
if ( V_205 != V_14 ) {
F_34 ( V_67 , V_70 , ( L_71 ) ) ;
return V_205 ;
}
if ( ( ! V_9 -> V_275 ) &&
( ! V_9 -> V_276 ) ) {
F_34 ( V_67 , V_111 , ( L_72 ) ) ;
F_126 ( V_9 , V_133 ) ;
} else {
F_34 ( V_67 , V_111 , ( L_73 ) ) ;
F_34 ( V_67 , V_111 , ( L_74 , V_9 -> V_275 , V_9 -> V_276 ) ) ;
V_205 = V_21 ;
return V_205 ;
}
}
return V_205 ;
}
static int F_133 ( struct V_8 * V_9 ,
struct V_11 * V_287 )
{
int V_31 = V_14 ;
struct V_28 * V_29 = & V_9 -> V_39 . V_15 ;
V_31 = F_90 ( V_9 , V_287 ) ;
if ( V_31 != V_14 ) {
F_34 ( V_67 , V_68 , ( L_75 ) ) ;
F_22 ( V_287 , V_29 ) ;
goto exit;
}
exit:
return V_31 ;
}
static int F_134 ( struct V_8 * V_9 ,
struct V_11 * V_133 )
{
int V_31 = V_14 ;
struct V_11 * V_288 = V_133 ;
struct V_6 * V_7 = & V_9 -> V_39 ;
struct V_28 * V_29 = & V_9 -> V_39 . V_15 ;
F_103 ( V_9 , V_222 ) ;
V_133 = F_39 ( V_9 , V_133 ) ;
if ( V_133 == NULL ) {
F_34 ( V_67 , V_70 , ( L_76 ) ) ;
V_31 = V_21 ;
goto V_289;
}
V_133 = F_76 ( V_9 , V_133 ) ;
if ( V_133 == NULL ) {
F_34 ( V_67 , V_70 , ( L_77 ) ) ;
goto V_289;
}
V_133 = F_43 ( V_9 , V_133 ) ;
if ( V_133 == NULL ) {
F_34 ( V_67 , V_70 , ( L_78 ) ) ;
V_31 = V_21 ;
goto V_289;
}
F_55 ( V_9 , V_133 , NULL ) ;
V_31 = F_132 ( V_9 , V_133 ) ;
if ( V_31 != V_14 ) {
F_34 ( V_67 , V_70 , ( L_79 ) ) ;
F_22 ( V_288 , V_29 ) ;
goto V_289;
}
return V_31 ;
V_289:
V_7 -> V_223 ++ ;
return V_31 ;
}
static int F_135 ( struct V_8 * V_9 , struct V_11 * V_287 )
{
int V_31 ;
struct V_51 * V_52 = & V_287 -> V_53 ;
struct V_54 * V_55 = & V_9 -> V_56 ;
struct V_146 * V_139 = & V_9 -> V_139 ;
if ( F_60 ( V_139 , V_157 ) && V_55 -> V_94 ) {
struct V_11 * V_38 ;
while ( ( V_38 = F_19 ( & V_9 -> V_39 . V_17 ) ) ) {
if ( F_134 ( V_9 , V_38 ) == V_14 )
F_31 ( L_1 , V_40 ) ;
}
}
V_31 = F_133 ( V_9 , V_287 ) ;
if ( V_31 == V_14 ) {
if ( F_60 ( V_139 , V_157 ) &&
! F_35 ( V_52 -> V_69 ) && V_52 -> V_65 > 0 &&
V_52 -> V_82 == 0 &&
! F_136 ( V_55 -> V_290 ) &&
! V_55 -> V_94 ) {
F_26 ( V_287 , & V_9 -> V_39 . V_17 ) ;
F_31 ( L_80 , V_40 ) ;
goto exit;
}
V_31 = F_134 ( V_9 , V_287 ) ;
}
exit:
return V_31 ;
}
T_5 F_137 ( struct V_11 * V_12 )
{
struct V_8 * V_9 ;
struct V_6 * V_7 ;
T_5 V_31 = V_14 ;
V_9 = V_12 -> V_8 ;
V_7 = & V_9 -> V_39 ;
V_31 = F_135 ( V_9 , V_12 ) ;
if ( V_31 == V_21 ) {
F_34 ( V_67 , V_68 , ( L_81 ) ) ;
goto V_291;
}
V_7 -> V_292 ++ ;
return V_31 ;
V_291:
return V_31 ;
}
static void V_26 ( unsigned long V_79 )
{
struct V_8 * V_8 = (struct V_8 * ) V_79 ;
struct V_6 * V_39 = & V_8 -> V_39 ;
T_1 V_293 , V_294 ;
V_3 V_295 = 0 ;
V_3 V_296 = 0 ;
V_3 V_297 = 3 ;
if ( V_39 -> V_298 . V_299 == 0 ) {
V_295 = V_39 -> V_298 . V_300 ;
V_39 -> V_298 . V_299 = 1 ;
}
if ( V_39 -> V_301 . V_299 == 0 ) {
V_296 = V_39 -> V_301 . V_300 ;
V_39 -> V_301 . V_299 = 1 ;
}
if ( F_60 ( & V_8 -> V_139 , V_302 ) == false ) {
V_293 = V_295 +
( V_297 - 1 ) * V_39 -> V_303 ;
V_293 = F_138 ( V_293 , V_297 ) ;
if ( V_293 > 100 )
V_293 = 100 ;
V_294 = V_296 +
( V_297 - 1 ) * V_39 -> V_304 ;
V_294 = F_138 ( V_294 , V_297 ) ;
if ( V_294 > 100 )
V_294 = 100 ;
V_39 -> V_303 = V_293 ;
V_39 -> V_305 = ( V_306 ) F_139 ( V_293 ) ;
V_39 -> V_304 = V_294 ;
}
F_11 ( V_39 ) ;
}
