void F_1 ( struct V_1 * V_2 )
{
F_2 ( & V_2 -> V_3 ) ;
F_3 ( & V_2 -> V_4 ) ;
}
int F_4 ( struct V_5 * V_6 ,
struct V_7 * V_8 )
{
struct V_9 * V_10 ;
int V_11 ;
int V_12 = V_13 ;
F_2 ( & V_6 -> V_3 ) ;
F_3 ( & V_6 -> V_14 ) ;
F_3 ( & V_6 -> V_15 ) ;
F_3 ( & V_6 -> V_16 ) ;
V_6 -> V_17 = V_8 ;
for ( V_11 = 0 ; V_11 < V_18 ; V_11 ++ ) {
V_10 = F_5 ( sizeof( struct V_9 ) , V_19 ) ;
if ( ! V_10 )
break;
F_6 ( & V_10 -> V_20 ) ;
F_7 ( & V_10 -> V_20 ,
& V_6 -> V_14 . V_21 ) ;
V_10 -> V_17 = V_8 ;
V_10 ++ ;
}
V_6 -> V_22 = V_11 ;
V_6 -> V_23 = 1 ;
V_12 = F_8 ( V_8 ) ;
F_9 ( & V_6 -> V_24 , V_25 ,
( unsigned long ) V_8 ) ;
V_6 -> V_26 = 1000 ;
F_10 ( V_6 ) ;
return V_12 ;
}
void F_11 ( struct V_5 * V_6 )
{
struct V_7 * V_8 = V_6 -> V_17 ;
struct V_9 * V_10 ;
struct V_27 * V_28 , * V_29 ;
F_12 ( V_8 ) ;
F_13 (plist, ptmp, &precvpriv->free_recv_queue.queue) {
V_10 = F_14 ( V_28 , struct V_9 , V_20 ) ;
F_15 ( & V_10 -> V_20 ) ;
F_16 ( V_10 ) ;
}
F_17 ( V_8 ) ;
}
struct V_9 * F_18 ( struct V_30 * V_31 )
{
struct V_9 * V_32 ;
struct V_27 * V_28 , * V_33 ;
struct V_7 * V_8 ;
struct V_5 * V_6 ;
F_19 ( & V_31 -> V_3 ) ;
if ( F_20 ( & V_31 -> V_21 ) )
V_32 = NULL ;
else {
V_33 = F_21 ( V_31 ) ;
V_28 = V_33 -> V_34 ;
V_32 = F_14 ( V_28 , struct V_9 , V_20 ) ;
F_15 ( & V_32 -> V_20 ) ;
V_8 = V_32 -> V_17 ;
if ( V_8 ) {
V_6 = & V_8 -> V_35 ;
if ( V_31 == & V_6 -> V_14 )
V_6 -> V_22 -- ;
}
}
F_22 ( & V_31 -> V_3 ) ;
return V_32 ;
}
int F_23 ( struct V_9 * V_10 )
{
struct V_7 * V_8 = V_10 -> V_17 ;
struct V_5 * V_6 = & V_8 -> V_35 ;
struct V_30 * V_31 ;
if ( V_10 -> V_36 ) {
F_24 ( V_10 -> V_36 ) ;
V_10 -> V_36 = NULL ;
}
V_31 = & V_6 -> V_14 ;
F_19 ( & V_31 -> V_3 ) ;
F_15 ( & V_10 -> V_20 ) ;
F_7 ( & V_10 -> V_20 , F_21 ( V_31 ) ) ;
if ( V_8 ) {
if ( V_31 == & V_6 -> V_14 )
V_6 -> V_22 ++ ;
}
F_22 ( & V_31 -> V_3 ) ;
return V_13 ;
}
int F_25 ( struct V_9 * V_10 , struct V_30 * V_21 )
{
struct V_7 * V_8 = V_10 -> V_17 ;
struct V_5 * V_6 = & V_8 -> V_35 ;
F_19 ( & V_21 -> V_3 ) ;
F_15 ( & V_10 -> V_20 ) ;
F_7 ( & V_10 -> V_20 , F_21 ( V_21 ) ) ;
if ( V_8 ) {
if ( V_21 == & V_6 -> V_14 )
V_6 -> V_22 ++ ;
}
F_22 ( & V_21 -> V_3 ) ;
return V_13 ;
}
static void F_26 ( struct V_30 * V_37 )
{
struct V_9 * V_38 ;
struct V_27 * V_28 , * V_33 , * V_29 ;
F_27 ( & V_37 -> V_3 ) ;
V_33 = F_21 ( V_37 ) ;
V_28 = V_33 -> V_34 ;
F_13 (plist, ptmp, phead) {
V_38 = F_14 ( V_28 , struct V_9 , V_20 ) ;
F_23 ( V_38 ) ;
}
F_28 ( & V_37 -> V_3 ) ;
}
T_1 F_12 ( struct V_7 * V_17 )
{
T_1 V_39 = 0 ;
struct V_9 * V_40 ;
while ( ( V_40 = F_18 ( & V_17 -> V_35 . V_16 ) ) ) {
F_23 ( V_40 ) ;
F_29 ( L_1 , V_41 ) ;
V_39 ++ ;
}
return V_39 ;
}
int F_30 ( struct V_42 * V_43 , struct V_30 * V_21 )
{
F_19 ( & V_21 -> V_3 ) ;
F_15 ( & V_43 -> V_20 ) ;
F_31 ( & V_43 -> V_20 , F_21 ( V_21 ) ) ;
F_22 ( & V_21 -> V_3 ) ;
return V_13 ;
}
int F_32 ( struct V_42 * V_43 , struct V_30 * V_21 )
{
unsigned long V_44 ;
F_33 ( & V_21 -> V_3 , V_44 ) ;
F_15 ( & V_43 -> V_20 ) ;
F_7 ( & V_43 -> V_20 , F_21 ( V_21 ) ) ;
F_34 ( & V_21 -> V_3 , V_44 ) ;
return V_13 ;
}
struct V_42 * F_35 ( struct V_30 * V_21 )
{
unsigned long V_44 ;
struct V_42 * V_43 ;
struct V_27 * V_28 , * V_33 ;
F_33 ( & V_21 -> V_3 , V_44 ) ;
if ( F_20 ( & V_21 -> V_21 ) ) {
V_43 = NULL ;
} else {
V_33 = F_21 ( V_21 ) ;
V_28 = V_33 -> V_34 ;
V_43 = F_14 ( V_28 , struct V_42 , V_20 ) ;
F_15 ( & V_43 -> V_20 ) ;
}
F_34 ( & V_21 -> V_3 , V_44 ) ;
return V_43 ;
}
int F_36 ( struct V_7 * V_17 ,
struct V_9 * V_10 ) {
int V_11 , V_12 = V_13 ;
T_1 V_45 ;
T_2 V_46 [ 8 ] ;
T_2 V_47 = false , V_48 = true ;
T_2 * V_32 , * V_49 , * V_50 ;
T_2 * V_51 ;
struct V_52 * V_53 ;
struct V_54 * V_55 = & V_10 -> V_56 ;
struct V_57 * V_58 = & V_17 -> V_59 ;
struct V_60 * V_61 = & V_17 -> V_62 ;
struct V_63 * V_64 = & V_61 -> V_65 ;
V_53 = F_37 ( & V_17 -> V_66 , & V_55 -> V_67 [ 0 ] ) ;
if ( V_55 -> V_68 == V_69 ) {
F_38 ( V_70 , V_71 ,
L_2 ) ;
F_38 ( V_70 , V_71 ,
L_3 , V_55 -> V_72 ) ;
if ( V_53 != NULL ) {
if ( F_39 ( V_55 -> V_72 ) ) {
V_51 = & V_58 -> V_73 [ V_55 -> V_74 ] . V_75 [ 0 ] ;
F_38 ( V_70 , V_71 ,
L_4 ) ;
if ( ! V_58 -> V_76 ) {
V_12 = V_77 ;
F_38 ( V_70 ,
V_78 ,
L_5 ) ;
F_29 ( L_6
L_7 ) ;
goto exit;
}
} else {
V_51 = & V_53 -> V_79 . V_75 [ 0 ] ;
F_38 ( V_70 , V_78 ,
L_8 ) ;
}
V_45 = V_10 -> V_36 -> V_80 - V_55 ->
V_81 - V_55 -> V_82 - V_55 -> V_83 - 8 ;
V_32 = V_10 -> V_36 -> V_84 ;
V_49 = V_32 + V_55 -> V_81 +
V_55 -> V_82 ;
F_38 ( V_70 , V_71 ,
L_9 ,
V_55 -> V_82 , V_55 -> V_83 ) ;
F_40 ( V_51 , V_32 , V_49 ,
V_45 , & V_46 [ 0 ] ,
( unsigned char ) V_55 -> V_85 ) ;
V_50 = V_49 + V_45 ;
V_47 = false ;
for ( V_11 = 0 ; V_11 < 8 ; V_11 ++ ) {
if ( V_46 [ V_11 ] != * ( V_50 + V_11 ) ) {
F_38 ( V_70 ,
V_78 ,
L_10 ,
V_11 , V_46 [ V_11 ] ,
V_11 , * ( V_50 + V_11 ) ) ;
V_47 = true ;
}
}
if ( V_47 == true ) {
int V_11 ;
F_38 ( V_70 , V_78 ,
L_11 ,
* ( V_50 - 8 ) , * ( V_50 - 7 ) ,
* ( V_50 - 6 ) , * ( V_50 - 5 ) ,
* ( V_50 - 4 ) , * ( V_50 - 3 ) ,
* ( V_50 - 2 ) , * ( V_50 - 1 ) ) ;
F_38 ( V_70 , V_78 ,
L_12 ,
* ( V_50 - 16 ) , * ( V_50 - 15 ) ,
* ( V_50 - 14 ) , * ( V_50 - 13 ) ,
* ( V_50 - 12 ) , * ( V_50 - 11 ) ,
* ( V_50 - 10 ) , * ( V_50 - 9 ) ) ;
F_38 ( V_70 , V_78 ,
L_13 ,
V_10 -> V_36 -> V_80 ) ;
for ( V_11 = 0 ; V_11 < V_10 -> V_36 -> V_80 ; V_11 = V_11 + 8 ) {
F_38 ( V_70 ,
V_78 ,
L_14 ,
* ( V_10 -> V_36 -> V_84 + V_11 ) ,
* ( V_10 -> V_36 -> V_84 + V_11 + 1 ) ,
* ( V_10 -> V_36 -> V_84 + V_11 + 2 ) ,
* ( V_10 -> V_36 -> V_84 + V_11 + 3 ) ,
* ( V_10 -> V_36 -> V_84 + V_11 + 4 ) ,
* ( V_10 -> V_36 -> V_84 + V_11 + 5 ) ,
* ( V_10 -> V_36 -> V_84 + V_11 + 6 ) ,
* ( V_10 -> V_36 -> V_84 + V_11 + 7 ) ) ;
}
F_38 ( V_70 , V_78 ,
L_15 ,
V_10 -> V_36 -> V_80 ) ;
F_38 ( V_70 , V_78 ,
L_16 , V_55 -> V_81 ) ;
F_38 ( V_70 , V_78 ,
L_17 ,
V_55 -> V_72 ,
V_58 -> V_76 ) ;
if ( ( F_39 ( V_55 -> V_72 ) ) &&
( V_55 -> V_74 !=
V_64 -> V_74 ) )
V_48 = false ;
if ( ( V_55 -> V_86 == true ) &&
( V_48 == true ) ) {
F_41 ( V_17 , ( T_2 ) F_39 ( V_55 -> V_72 ) ) ;
F_38 ( V_70 , V_78 ,
L_18 ,
V_55 -> V_86 ) ;
F_29 ( L_19
L_20 ,
V_55 -> V_86 ) ;
} else {
F_38 ( V_70 ,
V_78 ,
L_18 ,
V_55 -> V_86 ) ;
F_29 ( L_19
L_20 ,
V_55 -> V_86 ) ;
}
V_12 = V_77 ;
} else {
if ( ! V_58 -> V_87 &&
F_39 ( V_55 -> V_72 ) ) {
V_58 -> V_87 = 1 ;
F_38 ( V_70 ,
V_78 ,
L_21 ) ;
}
}
} else {
F_38 ( V_70 , V_78 ,
L_22 ) ;
}
F_42 ( V_10 -> V_36 , V_10 -> V_36 -> V_80 - 8 ) ;
}
exit:
return V_12 ;
}
struct V_9 * F_43 ( struct V_7 * V_8 ,
struct V_9 * V_88 )
{
struct V_54 * V_55 = & V_88 -> V_56 ;
struct V_57 * V_58 = & V_8 -> V_59 ;
struct V_9 * V_89 = V_88 ;
int V_12 = V_13 ;
F_38 ( V_70 , V_71 ,
L_23 ,
V_55 -> V_86 , V_55 -> V_68 ) ;
if ( V_55 -> V_68 > 0 ) {
T_2 * V_90 = V_88 -> V_36 -> V_84 + V_55 -> V_81 ;
V_55 -> V_74 = ( ( ( V_90 [ 3 ] ) >> 6 ) & 0x3 ) ;
if ( V_55 -> V_74 > V_91 ) {
F_29 ( L_24 ,
V_55 -> V_74 ) ;
switch ( V_55 -> V_68 ) {
case V_92 :
case V_93 :
V_55 -> V_74 =
V_58 -> V_94 ;
break;
case V_69 :
case V_95 :
default:
V_55 -> V_74 =
V_58 -> V_96 ;
break;
}
}
}
if ( ( V_55 -> V_68 > 0 ) && ( ( V_55 -> V_86 == 0 ) ) ) {
V_58 -> V_97 = 0 ;
switch ( V_55 -> V_68 ) {
case V_92 :
case V_93 :
F_44 ( V_8 , V_88 ) ;
break;
case V_69 :
V_12 = F_45 ( V_8 , V_88 ) ;
break;
case V_95 :
V_12 = F_46 ( V_8 , V_88 ) ;
break;
default:
break;
}
} else if ( V_55 -> V_86 == 1 && V_55 -> V_68 > 0 &&
( V_58 -> V_98 == 1 ||
V_55 -> V_68 != V_69 ) ) {
V_58 -> V_97 = 1 ;
}
if ( V_12 == V_77 ) {
F_23 ( V_89 ) ;
V_89 = NULL ;
}
return V_89 ;
}
static struct V_9 * F_47 ( struct V_7 * V_17 ,
struct V_9 * V_88 )
{
T_2 * V_99 , * V_100 ;
T_3 V_101 ;
struct V_9 * V_102 ;
struct V_52 * V_103 ;
struct V_104 * V_105 ;
struct V_9 * V_106 ;
T_4 V_107 ;
T_4 V_108 = V_109 ;
struct V_54 * V_110 ;
V_105 = & V_17 -> V_66 ;
V_101 = V_17 -> V_59 . V_111 ;
V_102 = V_88 ;
V_110 = & V_102 -> V_56 ;
V_99 = V_110 -> V_67 ;
V_103 = F_37 ( V_105 , V_99 ) ;
F_38 ( V_70 , V_71 ,
L_25 ,
V_17 -> V_59 . V_111 ) ;
V_106 = V_88 ;
if ( V_101 == V_112 ) {
V_100 = V_102 -> V_36 -> V_84 + V_102 -> V_56 . V_81 ;
V_107 = ( V_100 [ 6 ] << 8 ) | V_100 [ 7 ] ;
if ( V_103 && V_103 -> V_113 ) {
F_38 ( V_70 , V_71 ,
L_26 ) ;
if ( V_107 != V_108 ) {
F_23 ( V_88 ) ;
V_106 = NULL ;
}
}
}
return V_106 ;
}
int F_48 ( struct V_9 * V_88 , T_2 V_114 ,
struct V_115 * V_116 )
{
int V_117 = V_88 -> V_56 . V_85 ;
T_4 V_118 = ( ( V_88 -> V_56 . V_119 & 0xffff ) << 4 ) |
( V_88 -> V_56 . V_120 & 0xf ) ;
if ( V_117 > 15 ) {
F_38 ( V_70 , V_121 ,
L_27 ,
V_118 , V_117 ) ;
return V_77 ;
}
if ( 1 ) {
if ( V_118 == V_116 -> V_122 [ V_117 ] ) {
F_38 ( V_70 , V_121 ,
L_28 ,
V_118 , V_117 , V_116 -> V_122 [ V_117 ] ) ;
return V_77 ;
}
}
V_116 -> V_122 [ V_117 ] = V_118 ;
return V_13 ;
}
void F_49 ( struct V_7 * V_8 ,
struct V_9 * V_88 )
{
#ifdef F_50
unsigned char V_123 ;
struct V_124 * V_125 = V_88 -> V_36 ;
struct V_126 * V_38 = (struct V_126 * ) V_125 -> V_84 ;
struct V_54 * V_110 = & V_88 -> V_56 ;
struct V_104 * V_105 = & V_8 -> V_66 ;
struct V_52 * V_103 = NULL ;
V_103 = F_37 ( V_105 , V_110 -> V_127 ) ;
if ( V_103 ) {
V_123 = F_51 ( V_38 -> V_128 ) ;
if ( V_123 ) {
if ( ! ( V_103 -> V_129 & V_130 ) )
F_52 ( V_8 , V_103 ) ;
} else {
if ( V_103 -> V_129 & V_130 )
F_53 ( V_8 , V_103 ) ;
}
}
#endif
}
void F_54 ( struct V_7 * V_8 ,
struct V_9 * V_88 )
{
#ifdef F_50
struct V_54 * V_110 = & V_88 -> V_56 ;
struct V_104 * V_105 = & V_8 -> V_66 ;
struct V_52 * V_103 = NULL ;
V_103 = F_37 ( V_105 , V_110 -> V_127 ) ;
if ( ! V_103 )
return;
if ( ! V_103 -> V_131 )
return;
if ( ! ( V_103 -> V_132 & 0xf ) )
return;
if ( V_103 -> V_129 & V_130 ) {
T_2 V_133 = 0 ;
switch ( V_110 -> V_85 ) {
case 1 :
case 2 :
V_133 = V_103 -> V_134 & F_55 ( 1 ) ;
break;
case 4 :
case 5 :
V_133 = V_103 -> V_135 & F_55 ( 1 ) ;
break;
case 6 :
case 7 :
V_133 = V_103 -> V_136 & F_55 ( 1 ) ;
break;
case 0 :
case 3 :
default:
V_133 = V_103 -> V_137 & F_55 ( 1 ) ;
break;
}
if ( V_133 ) {
if ( V_103 -> V_138 > 0 ) {
F_56 ( V_8 , V_103 ) ;
} else {
F_57 ( V_8 , V_103 -> V_139 ,
( T_4 ) V_110 -> V_85 ,
0 , 0 ) ;
}
}
}
#endif
}
static void F_58 ( struct V_7 * V_8 ,
struct V_9 * V_140 , struct V_52 * V_141 )
{
int V_142 ;
struct V_52 * V_103 = NULL ;
struct V_143 * V_144 = NULL ;
struct V_54 * V_110 = & V_140 -> V_56 ;
struct V_5 * V_6 = & V_8 -> V_35 ;
V_142 = V_140 -> V_36 -> V_80 ;
V_6 -> V_145 += V_142 ;
V_8 -> V_146 . V_147 . V_148 ++ ;
if ( ( ! F_59 ( V_110 -> V_149 ) ) &&
( ! F_39 ( V_110 -> V_149 ) ) )
V_8 -> V_146 . V_147 . V_150 ++ ;
if ( V_141 )
V_103 = V_141 ;
else
V_103 = V_140 -> V_103 ;
if ( V_103 ) {
V_144 = & V_103 -> V_151 ;
V_144 -> V_152 ++ ;
V_144 -> V_145 += V_142 ;
}
}
static int F_60 ( struct V_7 * V_17 ,
struct V_9 * V_88 ,
struct V_52 * * V_103 )
{
struct V_124 * V_125 = V_88 -> V_36 ;
struct V_126 * V_38 = (struct V_126 * ) V_125 -> V_84 ;
int V_153 = V_13 ;
struct V_54 * V_110 = & V_88 -> V_56 ;
struct V_104 * V_105 = & V_17 -> V_66 ;
struct V_154 * V_155 = & V_17 -> V_146 ;
T_2 * V_156 = F_61 ( V_155 ) ;
T_2 * V_157 = F_62 ( & V_17 -> V_158 ) ;
T_2 * V_159 = NULL ;
int V_160 = F_39 ( V_110 -> V_149 ) ;
if ( F_63 ( V_155 , V_161 ) ||
F_63 ( V_155 , V_162 ) ) {
if ( F_64 ( V_157 , V_110 -> V_127 ) ) {
F_38 ( V_70 , V_78 ,
L_29 ) ;
V_153 = V_77 ;
goto exit;
}
if ( ! F_64 ( V_157 , V_110 -> V_149 ) && ! V_160 ) {
V_153 = V_77 ;
goto exit;
}
if ( F_64 ( V_110 -> V_163 , L_30 ) ||
F_64 ( V_156 , L_30 ) ||
! F_64 ( V_110 -> V_163 , V_156 ) ) {
V_153 = V_77 ;
goto exit;
}
V_159 = V_110 -> V_127 ;
} else if ( F_63 ( V_155 , V_164 ) ) {
if ( ! F_64 ( V_110 -> V_163 , V_110 -> V_127 ) ) {
F_38 ( V_70 , V_78 ,
L_31 ) ;
V_153 = V_77 ;
goto exit;
}
V_159 = V_110 -> V_163 ;
} else if ( F_63 ( V_155 , V_165 ) ) {
if ( V_160 ) {
if ( ! F_39 ( V_110 -> V_163 ) ) {
V_153 = V_77 ;
goto exit;
}
} else {
if ( ! F_64 ( V_110 -> V_163 , V_110 -> V_149 ) ) {
V_153 = V_77 ;
goto exit;
}
V_159 = V_110 -> V_127 ;
}
} else if ( F_63 ( V_155 , V_166 ) ) {
F_65 ( V_110 -> V_149 , V_38 -> V_167 ) ;
F_65 ( V_110 -> V_127 , V_38 -> V_168 ) ;
F_65 ( V_110 -> V_163 , V_38 -> V_169 ) ;
F_65 ( V_110 -> V_72 , V_110 -> V_149 ) ;
F_65 ( V_110 -> V_67 , V_110 -> V_127 ) ;
V_159 = V_156 ;
} else {
V_153 = V_77 ;
}
if ( V_160 )
* V_103 = F_66 ( V_17 ) ;
else
* V_103 = F_37 ( V_105 , V_159 ) ;
if ( * V_103 == NULL ) {
F_38 ( V_70 , V_78 ,
L_32 ) ;
V_153 = V_77 ;
goto exit;
}
exit:
return V_153 ;
}
int F_67 ( struct V_7 * V_17 ,
struct V_9 * V_88 ,
struct V_52 * * V_103 )
{
struct V_124 * V_125 = V_88 -> V_36 ;
struct V_126 * V_38 = (struct V_126 * ) V_125 -> V_84 ;
struct V_54 * V_110 = & V_88 -> V_56 ;
int V_153 = V_13 ;
struct V_104 * V_105 = & V_17 -> V_66 ;
struct V_154 * V_155 = & V_17 -> V_146 ;
T_2 * V_156 = F_61 ( V_155 ) ;
T_2 * V_157 = F_62 ( & V_17 -> V_158 ) ;
int V_160 = F_39 ( V_110 -> V_149 ) ;
if ( F_63 ( V_155 , V_164 ) &&
( F_63 ( V_155 , V_170 ) ||
F_63 ( V_155 , V_171 ) ) ) {
if ( F_64 ( V_157 , V_110 -> V_127 ) ) {
F_38 ( V_70 , V_78 ,
L_29 ) ;
V_153 = V_77 ;
goto exit;
}
if ( ! F_64 ( V_157 , V_110 -> V_149 ) && ! V_160 ) {
F_38 ( V_70 , V_71 ,
L_33 ,
V_110 -> V_149 ) ;
V_153 = V_77 ;
goto exit;
}
if ( F_64 ( V_110 -> V_163 , L_30 ) ||
F_64 ( V_156 , L_30 ) ||
! F_64 ( V_110 -> V_163 , V_156 ) ) {
F_38 ( V_70 , V_71 ,
L_34 ,
V_110 -> V_163 ) ;
F_38 ( V_70 , V_71 ,
L_35 , V_156 ) ;
if ( ! V_160 ) {
F_29 ( L_36 ,
V_110 -> V_163 ) ;
F_68 ( V_17 , V_110 -> V_163 ,
V_172 ) ;
}
V_153 = V_77 ;
goto exit;
}
if ( V_160 )
* V_103 = F_66 ( V_17 ) ;
else
* V_103 = F_37 ( V_105 , V_110 -> V_163 ) ;
if ( * V_103 == NULL ) {
F_38 ( V_70 , V_78 ,
L_37 ) ;
V_153 = V_77 ;
goto exit;
}
if ( F_69 ( V_38 -> V_128 ) ) {
F_58 ( V_17 , V_88 , * V_103 ) ;
V_153 = V_173 ;
goto exit;
}
} else if ( F_63 ( V_155 , V_166 ) &&
F_63 ( V_155 , V_170 ) ) {
F_65 ( V_110 -> V_149 , V_38 -> V_167 ) ;
F_65 ( V_110 -> V_127 , V_38 -> V_168 ) ;
F_65 ( V_110 -> V_163 , V_38 -> V_169 ) ;
F_65 ( V_110 -> V_72 , V_110 -> V_149 ) ;
F_65 ( V_110 -> V_67 , V_110 -> V_127 ) ;
F_65 ( V_110 -> V_163 , V_156 ) ;
* V_103 = F_37 ( V_105 , V_110 -> V_163 ) ;
if ( * V_103 == NULL ) {
F_38 ( V_70 , V_78 ,
L_38 ) ;
V_153 = V_77 ;
goto exit;
}
} else if ( F_63 ( V_155 , V_165 ) ) {
V_153 = V_173 ;
goto exit;
} else {
if ( F_64 ( V_157 , V_110 -> V_149 ) && ! V_160 ) {
* V_103 = F_37 ( V_105 , V_110 -> V_163 ) ;
if ( * V_103 == NULL ) {
F_29 ( L_39 ,
V_110 -> V_163 ) ;
F_68 ( V_17 , V_110 -> V_163 ,
V_172 ) ;
}
}
V_153 = V_77 ;
}
exit:
return V_153 ;
}
int F_70 ( struct V_7 * V_17 ,
struct V_9 * V_88 ,
struct V_52 * * V_103 )
{
struct V_124 * V_125 = V_88 -> V_36 ;
struct V_126 * V_38 = (struct V_126 * ) V_125 -> V_84 ;
struct V_54 * V_110 = & V_88 -> V_56 ;
struct V_104 * V_105 = & V_17 -> V_66 ;
struct V_154 * V_155 = & V_17 -> V_146 ;
unsigned char * V_156 = F_61 ( V_155 ) ;
int V_153 = V_13 ;
if ( F_63 ( V_155 , V_165 ) ) {
if ( ! F_64 ( V_110 -> V_163 , V_156 ) ) {
V_153 = V_77 ;
goto exit;
}
* V_103 = F_37 ( V_105 , V_110 -> V_127 ) ;
if ( * V_103 == NULL ) {
F_38 ( V_70 , V_78 ,
L_40 ) ;
F_29 ( L_41 ,
V_110 -> V_127 ) ;
F_68 ( V_17 , V_110 -> V_127 ,
V_172 ) ;
V_153 = V_173 ;
goto exit;
}
F_49 ( V_17 , V_88 ) ;
if ( F_71 ( V_38 -> V_128 ) )
F_54 ( V_17 , V_88 ) ;
if ( F_69 ( V_38 -> V_128 ) ) {
F_58 ( V_17 , V_88 , * V_103 ) ;
V_153 = V_173 ;
goto exit;
}
} else {
T_2 * V_157 = F_62 ( & V_17 -> V_158 ) ;
if ( ! F_64 ( V_110 -> V_72 , V_157 ) ) {
V_153 = V_173 ;
goto exit;
}
F_29 ( L_41 ,
V_110 -> V_127 ) ;
F_68 ( V_17 , V_110 -> V_127 ,
V_172 ) ;
V_153 = V_173 ;
goto exit;
}
exit:
return V_153 ;
}
static int F_72 ( struct V_7 * V_8 ,
struct V_9 * V_88 )
{
#ifdef F_50
struct V_54 * V_110 = & V_88 -> V_56 ;
struct V_104 * V_105 = & V_8 -> V_66 ;
struct V_124 * V_125 = V_88 -> V_36 ;
struct V_126 * V_38 = (struct V_126 * ) V_125 -> V_84 ;
if ( ! F_73 ( V_38 -> V_128 ) )
return V_77 ;
if ( ! F_64 ( V_38 -> V_167 , F_62 ( & V_8 -> V_158 ) ) )
return V_77 ;
if ( F_74 ( V_38 -> V_128 ) ) {
struct V_174 * V_175 = (struct V_174 * ) V_38 ;
T_4 V_176 ;
T_2 V_133 = 0 ;
struct V_52 * V_103 = NULL ;
V_176 = F_75 ( V_175 -> V_176 ) & 0x3fff ;
V_103 = F_37 ( V_105 , V_38 -> V_168 ) ;
if ( ! V_103 || V_103 -> V_176 != V_176 )
return V_77 ;
V_103 -> V_151 . V_177 ++ ;
switch ( V_110 -> V_85 ) {
case 1 :
case 2 :
V_133 = V_103 -> V_134 & F_55 ( 0 ) ;
break;
case 4 :
case 5 :
V_133 = V_103 -> V_135 & F_55 ( 0 ) ;
break;
case 6 :
case 7 :
V_133 = V_103 -> V_136 & F_55 ( 0 ) ;
break;
case 0 :
case 3 :
default:
V_133 = V_103 -> V_137 & F_55 ( 0 ) ;
break;
}
if ( V_133 )
return V_77 ;
if ( V_103 -> V_129 & V_178 ) {
F_29 ( L_42 , V_41 ) ;
V_103 -> V_179 = V_105 -> V_179 ;
V_103 -> V_129 ^= V_178 ;
}
if ( ( V_103 -> V_129 & V_130 ) &&
( V_105 -> V_180 & F_76 ( V_103 -> V_176 ) ) ) {
struct V_27 * V_181 , * V_182 ;
struct V_183 * V_184 ;
struct V_185 * V_186 = & V_8 -> V_187 ;
F_19 ( & V_186 -> V_3 ) ;
V_182 = F_21 ( & V_103 -> V_188 ) ;
V_181 = V_182 -> V_34 ;
if ( ! F_20 ( V_182 ) ) {
V_184 = F_14 ( V_181 ,
struct V_183 ,
V_20 ) ;
V_181 = V_181 -> V_34 ;
F_15 ( & V_184 -> V_20 ) ;
V_103 -> V_189 -- ;
if ( V_103 -> V_189 > 0 )
V_184 -> V_56 . V_190 = 1 ;
else
V_184 -> V_56 . V_190 = 0 ;
V_184 -> V_56 . V_191 = 1 ;
F_77 ( V_8 ,
V_184 ) ;
if ( V_103 -> V_189 == 0 ) {
V_105 -> V_192 &= ~ F_76 ( V_103 -> V_176 ) ;
F_78 ( V_8 , V_193 ,
NULL , false ) ;
}
F_22 ( & V_186 -> V_3 ) ;
} else {
F_22 ( & V_186 -> V_3 ) ;
if ( V_105 -> V_192 & F_76 ( V_103 -> V_176 ) ) {
if ( V_103 -> V_189 == 0 ) {
F_29 ( L_43
L_44 ) ;
F_79 ( V_8 ,
V_103 -> V_139 ,
0 , 0 , 0 ) ;
} else {
F_29 ( L_45
L_46 ,
V_103 -> V_189 ) ;
V_103 -> V_189 = 0 ;
}
V_105 -> V_192 &= ~ F_76 ( V_103 -> V_176 ) ;
F_78 ( V_8 , V_193 ,
NULL , false ) ;
}
}
}
}
#endif
return V_77 ;
}
static int F_80 ( struct V_7 * V_8 ,
struct V_9 * V_88 )
{
struct V_52 * V_103 ;
struct V_124 * V_125 ;
struct V_126 * V_38 ;
F_38 ( V_70 , V_71 ,
L_47 ) ;
V_88 = F_81 ( V_8 , V_88 ) ;
if ( V_88 == NULL ) {
F_38 ( V_70 , V_121 ,
L_48 , V_41 ) ;
return V_13 ;
}
V_125 = V_88 -> V_36 ;
V_38 = (struct V_126 * ) V_125 -> V_84 ;
V_103 = F_37 ( & V_8 -> V_66 , V_38 -> V_168 ) ;
if ( V_103 ) {
V_103 -> V_151 . V_194 ++ ;
if ( F_82 ( V_38 -> V_128 ) )
V_103 -> V_151 . V_195 ++ ;
else if ( F_83 ( V_38 -> V_128 ) )
V_103 -> V_151 . V_196 ++ ;
else if ( F_84 ( V_38 -> V_128 ) ) {
if ( F_64 ( V_8 -> V_158 . V_197 ,
V_38 -> V_167 ) )
V_103 -> V_151 . V_198 ++ ;
else if ( F_59 ( V_38 -> V_167 ) ||
F_39 ( V_38 -> V_167 ) )
V_103 -> V_151 . V_199 ++ ;
else
V_103 -> V_151 . V_200 ++ ;
}
}
F_85 ( V_8 , V_88 ) ;
return V_13 ;
}
static int F_86 ( struct V_7 * V_17 ,
struct V_9 * V_88 )
{
T_2 V_114 ;
T_2 * V_201 , * V_202 ;
struct V_52 * V_103 = NULL ;
struct V_54 * V_110 = & V_88 -> V_56 ;
struct V_57 * V_58 = & V_17 -> V_59 ;
int V_153 = V_13 ;
struct V_124 * V_125 = V_88 -> V_36 ;
struct V_126 * V_38 = (struct V_126 * ) V_125 -> V_84 ;
V_114 = F_87 ( V_38 -> V_128 ) ;
V_202 = F_88 ( V_38 ) ;
V_201 = F_89 ( V_38 ) ;
F_65 ( V_110 -> V_149 , V_202 ) ;
F_65 ( V_110 -> V_127 , V_201 ) ;
switch ( V_38 -> V_128 &
F_90 ( V_203 | V_204 ) ) {
case F_90 ( 0 ) :
F_65 ( V_110 -> V_163 , V_38 -> V_169 ) ;
F_65 ( V_110 -> V_72 , V_202 ) ;
F_65 ( V_110 -> V_67 , V_201 ) ;
V_153 = F_60 ( V_17 , V_88 , & V_103 ) ;
break;
case F_90 ( V_204 ) :
F_65 ( V_110 -> V_163 , V_38 -> V_168 ) ;
F_65 ( V_110 -> V_72 , V_202 ) ;
F_65 ( V_110 -> V_67 , V_38 -> V_168 ) ;
V_153 = F_67 ( V_17 , V_88 , & V_103 ) ;
break;
case F_90 ( V_203 ) :
F_65 ( V_110 -> V_163 , V_38 -> V_167 ) ;
F_65 ( V_110 -> V_72 , V_38 -> V_167 ) ;
F_65 ( V_110 -> V_67 , V_201 ) ;
V_153 = F_70 ( V_17 , V_88 , & V_103 ) ;
break;
case F_90 ( V_203 | V_204 ) :
F_65 ( V_110 -> V_163 , V_38 -> V_167 ) ;
F_65 ( V_110 -> V_72 , V_38 -> V_167 ) ;
F_65 ( V_110 -> V_67 , V_38 -> V_168 ) ;
V_153 = V_77 ;
F_38 ( V_70 , V_78 , L_49 ) ;
break;
}
if ( ( V_153 == V_77 ) || ( V_153 == V_173 ) )
goto exit;
if ( ! V_103 ) {
F_38 ( V_70 , V_78 ,
L_50 ) ;
V_153 = V_77 ;
goto exit;
}
V_88 -> V_103 = V_103 ;
V_110 -> V_81 = sizeof( struct V_205 ) ;
if ( F_91 ( V_38 -> V_128 ) )
V_110 -> V_81 += V_206 ;
if ( V_110 -> V_207 == 1 ) {
T_5 * V_208 = ( T_5 * ) F_92 ( V_38 ) ;
T_4 V_209 = F_75 ( * V_208 ) ;
V_110 -> V_85 = V_209 & V_210 ;
V_110 -> V_211 = ( V_209 >> 5 ) & 3 ;
V_110 -> V_212 =
( V_209 & V_213 ) >> 7 ;
V_110 -> V_81 += V_214 ;
if ( V_110 -> V_85 != 0 && V_110 -> V_85 != 3 ) {
V_17 -> V_35 . V_215 = true ;
}
} else {
V_110 -> V_85 = 0 ;
V_110 -> V_211 = 0 ;
V_110 -> V_212 = 0 ;
}
if ( V_110 -> V_216 ) {
V_110 -> V_81 += 4 ;
}
V_88 -> V_217 = & V_103 -> V_218 [ V_110 -> V_85 ] ;
if ( F_48 ( V_88 , V_114 , & V_103 -> V_219 . V_220 ) ==
V_77 ) {
F_38 ( V_70 , V_78 ,
L_51 ) ;
V_153 = V_77 ;
goto exit;
}
if ( V_110 -> V_221 ) {
F_38 ( V_70 , V_71 ,
L_52 ,
V_110 -> V_221 ) ;
F_38 ( V_70 , V_71 ,
L_53 ,
V_110 -> V_72 [ 0 ] ,
F_39 ( V_110 -> V_72 ) ) ;
F_93 ( V_58 , V_103 , V_110 -> V_68 ,
F_39 ( V_110 -> V_72 ) ) ;
F_38 ( V_70 , V_71 ,
L_54 , V_110 -> V_68 ) ;
switch ( V_110 -> V_68 ) {
case V_92 :
case V_93 :
V_110 -> V_82 = V_222 ;
V_110 -> V_83 = V_223 ;
break;
case V_69 :
V_110 -> V_82 = V_224 ;
V_110 -> V_83 = V_225 ;
break;
case V_95 :
V_110 -> V_82 = V_226 ;
V_110 -> V_83 = V_227 ;
break;
default:
V_110 -> V_82 = 0 ;
V_110 -> V_83 = 0 ;
break;
}
} else {
V_110 -> V_68 = 0 ;
V_110 -> V_82 = 0 ;
V_110 -> V_83 = 0 ;
}
exit:
return V_153 ;
}
static void F_94 ( struct V_124 * V_125 , T_4 type , int V_228 )
{
int V_11 ;
T_2 * V_100 ;
if ( ( V_228 == 1 ) ||
( ( V_228 == 2 ) && ( type == V_229 ) ) ||
( ( V_228 == 3 ) && ( type == V_230 ) ) ) {
V_100 = V_125 -> V_84 ;
F_29 ( L_55 ) ;
for ( V_11 = 0 ; V_11 < 64 ; V_11 = V_11 + 8 )
F_29 ( L_56 ,
* ( V_100 + V_11 ) , * ( V_100 + V_11 + 1 ) , * ( V_100 + V_11 + 2 ) ,
* ( V_100 + V_11 + 3 ) , * ( V_100 + V_11 + 4 ) ,
* ( V_100 + V_11 + 5 ) , * ( V_100 + V_11 + 6 ) ,
* ( V_100 + V_11 + 7 ) ) ;
F_29 ( L_55 ) ;
}
}
static int F_95 ( struct V_7 * V_17 ,
struct V_9 * V_88 )
{
T_2 type ;
T_2 V_231 ;
int V_232 = V_13 ;
struct V_54 * V_110 = & V_88 -> V_56 ;
struct V_124 * V_125 = V_88 -> V_36 ;
struct V_126 * V_38 = (struct V_126 * ) V_125 -> V_84 ;
T_2 V_233 ;
T_2 V_234 ;
T_4 V_118 , V_235 ;
V_235 = F_75 ( V_38 -> V_128 ) ;
V_233 = V_235 & V_236 ;
type = V_235 & V_237 ;
V_231 = V_235 & V_238 ;
if ( V_233 != 0 ) {
F_38 ( V_70 , V_78 ,
L_57 ) ;
V_232 = V_77 ;
goto exit;
}
V_118 = F_75 ( V_38 -> V_118 ) ;
V_110 -> V_120 = V_118 & V_239 ;
V_110 -> V_119 = V_118 >> 4 ;
V_110 -> V_240 = F_51 ( V_38 -> V_128 ) ;
V_110 -> V_241 = F_96 ( V_38 -> V_128 ) ;
V_110 -> V_190 = F_97 ( V_38 -> V_128 ) ;
V_110 -> V_221 = F_98 ( V_38 -> V_128 ) ;
V_110 -> V_216 = F_99 ( V_38 -> V_128 ) ;
F_100 ( V_17 , V_242 , & V_234 ) ;
if ( F_101 ( V_234 == 1 ) )
F_94 ( V_125 , type , V_234 ) ;
switch ( type ) {
case V_229 :
V_232 = F_80 ( V_17 , V_88 ) ;
if ( V_232 == V_77 ) {
F_38 ( V_70 , V_78 ,
L_58 ) ;
}
V_232 = V_77 ;
break;
case V_243 :
V_232 = F_72 ( V_17 , V_88 ) ;
if ( V_232 == V_77 ) {
F_38 ( V_70 , V_78 ,
L_59 ) ;
}
V_232 = V_77 ;
break;
case V_230 :
V_110 -> V_207 = ( V_231 & V_244 ) ? 1 : 0 ;
V_232 = F_86 ( V_17 , V_88 ) ;
if ( V_232 == V_77 ) {
struct V_5 * V_6 = & V_17 -> V_35 ;
V_6 -> V_245 ++ ;
}
break;
default:
F_38 ( V_70 , V_78 ,
L_60 , type ) ;
V_232 = V_77 ;
break;
}
exit:
return V_232 ;
}
static int F_102 ( struct V_9 * V_10 )
{
T_4 V_246 , V_80 , V_81 ;
T_2 V_247 ;
T_2 * V_248 ;
struct V_7 * V_17 = V_10 -> V_17 ;
struct V_154 * V_155 = & V_17 -> V_146 ;
struct V_124 * V_125 = V_10 -> V_36 ;
T_2 * V_100 ;
struct V_54 * V_110 = & V_10 -> V_56 ;
V_100 = V_125 -> V_84 ;
V_81 = V_110 -> V_81 ;
V_248 = V_100 + V_81 ;
V_246 = ( V_248 [ 6 ] << 8 ) | V_248 [ 7 ] ;
if ( ( F_64 ( V_248 , V_249 ) &&
V_246 != V_250 && V_246 != V_251 ) ||
F_64 ( V_248 , V_252 ) ) {
V_247 = true ;
V_81 += V_253 ;
} else {
V_247 = false ;
V_246 = ( V_248 [ 0 ] << 8 ) | V_248 [ 1 ] ;
}
V_80 = V_125 -> V_80 - V_81 ;
F_38 ( V_70 , V_71 ,
L_61 ,
V_110 -> V_81 , V_110 -> V_82 ) ;
V_110 -> V_246 = V_246 ;
if ( F_63 ( V_155 , V_166 ) ) {
V_100 += V_81 ;
* V_100 = 0x87 ;
* ( V_100 + 1 ) = 0x12 ;
V_246 = 0x8712 ;
V_100 = F_103 ( V_125 , ( V_81 - sizeof( struct V_254 ) + 2 ) - 24 ) ;
memcpy ( V_100 , V_125 -> V_255 , 24 ) ;
V_100 += 24 ;
} else {
V_100 = F_103 ( V_125 , ( V_81 - sizeof( struct V_254 ) +
( V_247 ? 2 : 0 ) ) ) ;
}
F_65 ( V_100 , V_110 -> V_149 ) ;
F_65 ( V_100 + V_206 , V_110 -> V_127 ) ;
if ( ! V_247 ) {
V_80 = F_104 ( V_80 ) ;
memcpy ( V_100 + 12 , & V_80 , 2 ) ;
}
return V_13 ;
}
struct V_9 * F_105 ( struct V_7 * V_17 ,
struct V_30 * V_4 )
{
struct V_27 * V_28 , * V_33 , * V_29 ;
T_2 * V_84 , V_256 ;
T_2 V_257 ;
struct V_9 * V_258 ;
struct V_9 * V_140 , * V_259 ;
struct V_30 * V_31 ;
struct V_124 * V_125 ;
V_257 = 0 ;
V_31 = & V_17 -> V_35 . V_14 ;
V_33 = F_21 ( V_4 ) ;
V_28 = V_33 -> V_34 ;
V_140 = F_14 ( V_28 , struct V_9 , V_20 ) ;
F_15 ( & V_140 -> V_20 ) ;
V_125 = V_140 -> V_36 ;
if ( V_257 != V_140 -> V_56 . V_120 ) {
F_23 ( V_140 ) ;
F_26 ( V_4 ) ;
return NULL ;
}
V_257 ++ ;
V_33 = F_21 ( V_4 ) ;
V_84 = V_140 -> V_36 -> V_84 ;
F_13 (plist, ptmp, phead) {
V_258 = F_14 ( V_28 , struct V_9 , V_20 ) ;
V_259 = (struct V_9 * ) V_258 ;
if ( V_257 != V_258 -> V_56 . V_120 ) {
F_23 ( V_140 ) ;
F_26 ( V_4 ) ;
return NULL ;
}
V_257 ++ ;
V_256 = V_258 -> V_56 . V_81 + V_258 -> V_56 . V_82 ;
F_103 ( V_258 -> V_36 , V_256 ) ;
F_42 ( V_125 , V_125 -> V_80 - V_140 -> V_56 . V_83 ) ;
memcpy ( F_106 ( V_125 ) , V_258 -> V_36 -> V_84 ,
V_258 -> V_36 -> V_80 ) ;
F_107 ( V_125 , V_258 -> V_36 -> V_80 ) ;
V_140 -> V_56 . V_83 = V_258 -> V_56 . V_83 ;
}
F_26 ( V_4 ) ;
F_38 ( V_70 , V_71 ,
L_62 ) ;
return V_140 ;
}
struct V_9 * F_81 ( struct V_7 * V_8 ,
struct V_9 * V_88 )
{
T_2 V_260 ;
T_2 V_261 ;
T_2 * V_99 ;
struct V_9 * V_102 ;
struct V_52 * V_103 ;
struct V_104 * V_105 ;
struct V_27 * V_33 ;
struct V_9 * V_106 = NULL ;
struct V_30 * V_31 , * V_262 ;
V_105 = & V_8 -> V_66 ;
V_102 = V_88 ;
V_31 = & V_8 -> V_35 . V_14 ;
V_260 = V_102 -> V_56 . V_241 ;
V_261 = V_102 -> V_56 . V_120 ;
V_99 = V_102 -> V_56 . V_67 ;
V_103 = F_37 ( V_105 , V_99 ) ;
if ( ! V_103 ) {
struct V_126 * V_38 =
(struct V_126 * ) V_102 -> V_36 -> V_84 ;
if ( ! F_108 ( V_38 -> V_128 ) ) {
V_103 = F_66 ( V_8 ) ;
V_262 = & V_103 -> V_219 . V_4 ;
} else
V_262 = NULL ;
} else
V_262 = & V_103 -> V_219 . V_4 ;
if ( ( V_260 == 0 ) && ( V_261 == 0 ) ) {
V_106 = V_88 ;
}
if ( V_260 == 1 ) {
if ( V_262 != NULL ) {
if ( V_261 == 0 ) {
if ( ! F_20 ( & V_262 -> V_21 ) ) {
F_26 ( V_262 ) ;
}
}
V_33 = F_21 ( V_262 ) ;
F_7 ( & V_102 -> V_20 , V_33 ) ;
F_38 ( V_70 , V_71 ,
L_63 ,
V_260 , V_261 ) ;
V_106 = NULL ;
} else {
F_23 ( V_88 ) ;
V_106 = NULL ;
F_38 ( V_70 , V_78 ,
L_64 ,
V_260 , V_261 ) ;
}
}
if ( ( V_260 == 0 ) && ( V_261 != 0 ) ) {
if ( V_262 != NULL ) {
V_33 = F_21 ( V_262 ) ;
F_7 ( & V_102 -> V_20 , V_33 ) ;
F_38 ( V_70 , V_71 ,
L_65 ,
V_260 , V_261 ) ;
V_88 = F_105 ( V_8 , V_262 ) ;
V_106 = V_88 ;
} else {
F_23 ( V_88 ) ;
V_106 = NULL ;
F_38 ( V_70 , V_78 ,
L_64 ,
V_260 , V_261 ) ;
}
}
if ( ( V_106 != NULL ) && ( V_106 -> V_56 . V_221 ) ) {
if ( F_36 ( V_8 , V_106 ) == V_77 ) {
F_38 ( V_70 , V_78 ,
L_66 ) ;
F_23 ( V_106 ) ;
V_106 = NULL ;
}
}
return V_106 ;
}
int F_109 ( struct V_7 * V_8 , struct V_9 * V_140 )
{
struct V_54 * V_110 ;
struct V_124 * V_125 , * V_263 ;
struct V_264 V_265 ;
V_110 = & V_140 -> V_56 ;
V_125 = V_140 -> V_36 ;
F_103 ( V_125 , V_140 -> V_56 . V_81 ) ;
F_110 ( & V_265 ) ;
F_111 ( V_125 , & V_265 , NULL , 0 , 0 , false ) ;
while ( ! F_112 ( & V_265 ) ) {
V_263 = F_113 ( & V_265 ) ;
V_263 -> V_266 = F_114 ( V_263 , V_8 -> V_267 ) ;
V_263 -> V_268 = V_8 -> V_267 ;
V_263 -> V_269 = V_270 ;
F_115 ( V_263 ) ;
}
V_140 -> V_36 = NULL ;
F_23 ( V_140 ) ;
return V_13 ;
}
int F_116 ( struct V_271 * V_217 , T_4 V_119 )
{
T_2 V_272 = V_217 -> V_273 ;
T_4 V_274 = ( V_217 -> V_275 + V_272 - 1 ) & 0xFFF ;
if ( V_217 -> V_275 == 0xFFFF )
V_217 -> V_275 = V_119 ;
if ( F_117 ( V_119 , V_217 -> V_275 ) )
return false ;
if ( F_118 ( V_119 , V_217 -> V_275 ) ) {
V_217 -> V_275 =
( V_217 -> V_275 + 1 ) & 0xFFF ;
} else if ( F_117 ( V_274 , V_119 ) ) {
if ( V_119 >= ( V_272 - 1 ) )
V_217 -> V_275 = V_119 + 1 - V_272 ;
else
V_217 -> V_275 = 0xFFF - ( V_272 - ( V_119 + 1 ) ) + 1 ;
}
return true ;
}
static int F_119 ( struct V_271 * V_217 ,
struct V_9 * V_140 )
{
struct V_54 * V_110 = & V_140 -> V_56 ;
struct V_30 * V_276 ;
struct V_27 * V_33 , * V_28 , * V_29 ;
struct V_9 * V_38 ;
struct V_54 * V_277 ;
V_276 = & V_217 -> V_278 ;
V_33 = F_21 ( V_276 ) ;
F_13 (plist, ptmp, phead) {
V_38 = F_14 ( V_28 , struct V_9 , V_20 ) ;
V_277 = & V_38 -> V_56 ;
if ( F_117 ( V_277 -> V_119 , V_110 -> V_119 ) ) {
continue;
} else if ( F_118 ( V_277 -> V_119 , V_110 -> V_119 ) ) {
return false ;
} else {
break;
}
}
F_15 ( & V_140 -> V_20 ) ;
F_7 ( & V_140 -> V_20 , V_28 ) ;
return true ;
}
int F_120 ( struct V_7 * V_8 ,
struct V_271 * V_217 ,
int V_279 )
{
struct V_27 * V_33 , * V_28 ;
struct V_9 * V_140 ;
struct V_54 * V_110 ;
int V_280 = false ;
struct V_5 * V_6 ;
struct V_30 * V_276 ;
V_6 = & V_8 -> V_35 ;
V_276 = & V_217 -> V_278 ;
V_33 = F_21 ( V_276 ) ;
V_28 = V_33 -> V_34 ;
if ( V_279 ) {
if ( F_20 ( V_33 ) ) {
return true ;
}
V_140 = F_14 ( V_28 , struct V_9 , V_20 ) ;
V_110 = & V_140 -> V_56 ;
V_217 -> V_275 = V_110 -> V_119 ;
}
while ( ! F_20 ( V_33 ) ) {
V_140 = F_14 ( V_28 , struct V_9 , V_20 ) ;
V_110 = & V_140 -> V_56 ;
if ( ! F_117 ( V_217 -> V_275 , V_110 -> V_119 ) ) {
F_38 ( V_70 , V_121 ,
L_67 ,
V_217 -> V_275 ,
V_110 -> V_119 , V_110 -> V_212 ) ;
V_28 = V_28 -> V_34 ;
F_15 ( & V_140 -> V_20 ) ;
if ( F_118 ( V_217 -> V_275 ,
V_110 -> V_119 ) ) {
V_217 -> V_275 =
( V_217 -> V_275 + 1 ) & 0xFFF ;
}
if ( ! V_110 -> V_212 ) {
if ( ( V_8 -> V_281 == false ) &&
( V_8 -> V_282 == false ) ) {
F_121 ( V_8 , V_140 ) ;
}
} else {
if ( F_109 ( V_8 , V_140 ) !=
V_13 )
F_23 ( V_140 ) ;
}
V_280 = false ;
} else {
V_280 = true ;
break;
}
}
return V_280 ;
}
int F_122 ( struct V_7 * V_8 ,
struct V_9 * V_140 )
{
int V_232 = V_13 ;
struct V_54 * V_110 ;
struct V_271 * V_217 ;
struct V_30 * V_276 ;
V_110 = & V_140 -> V_56 ;
V_217 = V_140 -> V_217 ;
V_276 = & V_217 -> V_278 ;
if ( ! V_110 -> V_212 ) {
F_102 ( V_140 ) ;
if ( ( V_110 -> V_207 != 1 ) || ( V_110 -> V_246 == V_283 ) ||
( V_110 -> V_211 != 0 ) ) {
if ( ( V_8 -> V_281 == false ) &&
( V_8 -> V_282 == false ) ) {
F_38 ( V_70 , V_121 ,
L_68 ) ;
F_121 ( V_8 , V_140 ) ;
return V_13 ;
}
return V_77 ;
}
if ( V_217 -> V_284 == false ) {
V_217 -> V_275 = V_110 -> V_119 ;
F_121 ( V_8 , V_140 ) ;
V_217 -> V_275 =
( V_217 -> V_275 + 1 ) % 4096 ;
return V_13 ;
}
} else {
if ( V_217 -> V_284 == false ) {
V_217 -> V_275 = V_110 -> V_119 ;
V_232 = F_109 ( V_8 , V_140 ) ;
V_217 -> V_275 =
( V_217 -> V_275 + 1 ) % 4096 ;
return V_232 ;
}
}
F_19 ( & V_276 -> V_3 ) ;
F_38 ( V_70 , V_121 ,
L_69 ,
V_217 -> V_275 , V_110 -> V_119 ) ;
if ( ! F_116 ( V_217 , V_110 -> V_119 ) ) {
goto V_285;
}
if ( ! F_119 ( V_217 , V_140 ) ) {
goto V_285;
}
if ( F_120 ( V_8 , V_217 , false ) == true ) {
F_123 ( & V_217 -> V_286 ,
V_287 + F_124 ( V_288 ) ) ;
F_22 ( & V_276 -> V_3 ) ;
} else {
F_22 ( & V_276 -> V_3 ) ;
F_125 ( & V_217 -> V_286 ) ;
}
return V_13 ;
V_285:
F_22 ( & V_276 -> V_3 ) ;
return V_77 ;
}
void F_126 ( unsigned long V_289 )
{
struct V_271 * V_217 ;
struct V_7 * V_8 ;
struct V_30 * V_276 ;
V_217 = (struct V_271 * ) V_289 ;
V_8 = V_217 -> V_8 ;
V_276 = & V_217 -> V_278 ;
if ( V_8 -> V_281 || V_8 -> V_282 ) {
return;
}
F_19 ( & V_276 -> V_3 ) ;
if ( F_120 ( V_8 , V_217 , true ) == true ) {
F_123 ( & V_217 -> V_286 ,
V_287 + F_124 ( V_288 ) ) ;
}
F_22 ( & V_276 -> V_3 ) ;
}
int F_127 ( struct V_7 * V_8 ,
struct V_9 * V_140 )
{
int V_232 = V_13 ;
struct V_154 * V_155 = & V_8 -> V_146 ;
struct V_290 * V_291 = & V_155 -> V_292 ;
if ( V_291 -> V_293 == true ) {
if ( F_122 ( V_8 , V_140 ) != V_13 ) {
if ( ( V_8 -> V_281 == false ) &&
( V_8 -> V_282 == false ) ) {
V_232 = V_77 ;
return V_232 ;
}
}
} else {
V_232 = F_102 ( V_140 ) ;
if ( V_232 != V_13 ) {
F_38 ( V_70 , V_78 ,
L_70 ) ;
return V_232 ;
}
if ( ( V_8 -> V_281 == false ) &&
( V_8 -> V_282 == false ) ) {
F_38 ( V_70 , V_121 ,
L_71 ) ;
F_121 ( V_8 , V_140 ) ;
} else {
F_38 ( V_70 , V_121 ,
L_72 ) ;
F_38 ( V_70 , V_121 ,
L_73 ,
V_8 -> V_281 ,
V_8 -> V_282 ) ;
V_232 = V_77 ;
return V_232 ;
}
}
return V_232 ;
}
static int F_128 ( struct V_7 * V_8 ,
struct V_9 * V_294 )
{
int V_153 = V_13 ;
V_153 = F_95 ( V_8 , V_294 ) ;
if ( V_153 != V_13 ) {
F_38 ( V_70 , V_71 ,
L_74 ) ;
F_23 ( V_294 ) ;
goto exit;
}
exit:
return V_153 ;
}
static int F_129 ( struct V_7 * V_8 ,
struct V_9 * V_140 )
{
int V_153 = V_13 ;
struct V_9 * V_295 = V_140 ;
struct V_5 * V_6 = & V_8 -> V_35 ;
V_140 = F_43 ( V_8 , V_140 ) ;
if ( V_140 == NULL ) {
F_38 ( V_70 , V_78 ,
L_75 ) ;
V_153 = V_77 ;
goto V_296;
}
V_140 = F_81 ( V_8 , V_140 ) ;
if ( ! V_140 ) {
F_38 ( V_70 , V_78 ,
L_76 ) ;
goto V_296;
}
if ( V_140 -> V_56 . V_82 > 0 ) {
F_103 ( V_140 -> V_36 , V_140 -> V_56 . V_82 ) ;
}
if ( V_140 -> V_56 . V_83 > 0 ) {
F_42 ( V_140 -> V_36 ,
V_140 -> V_36 -> V_80 - V_140 -> V_56 . V_83 ) ;
}
V_140 = F_47 ( V_8 , V_140 ) ;
if ( ! V_140 ) {
F_38 ( V_70 , V_78 ,
L_77 ) ;
V_153 = V_77 ;
goto V_296;
}
F_58 ( V_8 , V_140 , NULL ) ;
V_153 = F_127 ( V_8 , V_140 ) ;
if ( V_153 != V_13 ) {
F_38 ( V_70 , V_78 ,
L_78 ) ;
F_23 ( V_295 ) ;
goto V_296;
}
return V_153 ;
V_296:
V_6 -> V_245 ++ ;
return V_153 ;
}
int F_130 ( struct V_9 * V_294 )
{
int V_153 , V_297 ;
struct V_7 * V_8 = V_294 -> V_17 ;
struct V_54 * V_55 = & V_294 -> V_56 ;
struct V_5 * V_35 = & V_8 -> V_35 ;
struct V_57 * V_58 = & V_8 -> V_59 ;
struct V_154 * V_146 = & V_8 -> V_146 ;
if ( F_63 ( V_146 , V_164 ) &&
V_58 -> V_98 ) {
struct V_9 * V_40 ;
while ( ( V_40 = F_18 ( & V_8 -> V_35 . V_16 ) ) ) {
V_297 = F_129 ( V_8 , V_40 ) ;
if ( V_297 == V_13 )
F_29 ( L_1 , V_41 ) ;
}
}
V_153 = F_128 ( V_8 , V_294 ) ;
if ( V_153 == V_13 ) {
if ( F_63 ( V_146 , V_164 ) &&
! F_39 ( V_55 -> V_72 ) &&
V_55 -> V_68 > 0 &&
( V_55 -> V_86 == 0 ) &&
! F_131 ( V_58 -> V_298 ) &&
! V_58 -> V_98 ) {
F_25 ( V_294 , & V_8 -> V_35 . V_16 ) ;
F_29 ( L_79 , V_41 ) ;
goto exit;
}
V_153 = F_129 ( V_8 , V_294 ) ;
V_35 -> V_299 ++ ;
}
exit:
return V_153 ;
}
void V_25 ( unsigned long V_84 )
{
struct V_7 * V_17 = (struct V_7 * ) V_84 ;
struct V_5 * V_35 = & V_17 -> V_35 ;
T_1 V_300 , V_301 ;
T_2 V_302 = 0 ;
T_2 V_303 = 0 ;
T_1 V_304 = 0 ;
T_1 V_305 = 0 ;
T_2 V_306 = 3 ;
if ( V_35 -> V_307 . V_308 == 0 ) {
V_302 = V_35 -> V_307 . V_309 ;
V_304 = V_35 -> V_307 . V_310 ;
V_35 -> V_307 . V_308 = 1 ;
}
if ( V_35 -> V_311 . V_308 == 0 ) {
V_303 = V_35 -> V_311 . V_309 ;
V_305 = V_35 -> V_311 . V_310 ;
V_35 -> V_311 . V_308 = 1 ;
}
if ( ! F_63 ( & V_17 -> V_146 , V_312 ) ) {
V_300 = V_302 + ( V_306 - 1 ) *
V_35 -> V_313 ;
if ( V_300 % V_306 )
V_300 = V_300 / V_306 + 1 ;
else
V_300 = V_300 / V_306 ;
if ( V_300 > 100 )
V_300 = 100 ;
V_301 = V_303 + ( V_306 - 1 ) * V_35 -> V_314 ;
if ( V_301 % V_306 )
V_301 = V_301 / V_306 + 1 ;
else
V_301 = V_301 / V_306 ;
if ( V_301 > 100 )
V_301 = 100 ;
V_35 -> V_313 = V_300 ;
V_35 -> V_314 = V_301 ;
F_29 ( L_80
L_81 ,
V_41 , V_35 -> V_313 ,
V_35 -> V_314 , V_304 ,
V_305 ) ;
}
F_10 ( V_35 ) ;
}
