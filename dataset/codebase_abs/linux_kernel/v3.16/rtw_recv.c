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
( L_2 ) ) ;
F_38 ( V_70 , V_71 ,
( L_3
L_4 , V_55 -> V_72 [ 0 ] ,
V_55 -> V_72 [ 1 ] , V_55 -> V_72 [ 2 ] , V_55 -> V_72 [ 3 ] ,
V_55 -> V_72 [ 4 ] , V_55 -> V_72 [ 5 ] ) ) ;
if ( V_53 != NULL ) {
if ( F_39 ( V_55 -> V_72 ) ) {
V_51 = & V_58 -> V_73 [ V_55 -> V_74 ] . V_75 [ 0 ] ;
F_38 ( V_70 , V_71 ,
( L_5 ) ) ;
if ( ! V_58 -> V_76 ) {
V_12 = V_77 ;
F_38 ( V_70 ,
V_78 ,
( L_6
L_7 ) ) ;
F_29 ( L_6
L_7 ) ;
goto exit;
}
} else {
V_51 = & V_53 -> V_79 . V_75 [ 0 ] ;
F_38 ( V_70 , V_78 ,
( L_8
L_9 ) ) ;
}
V_45 = V_10 -> V_36 -> V_80 - V_55 ->
V_81 - V_55 -> V_82 - V_55 -> V_83 - 8 ;
V_32 = V_10 -> V_36 -> V_84 ;
V_49 = V_32 + V_55 -> V_81 +
V_55 -> V_82 ;
F_38 ( V_70 , V_71 ,
( L_10
L_11 , V_55 -> V_82 ,
V_55 -> V_83 ) ) ;
F_40 ( V_51 , V_32 , V_49 ,
V_45 , & V_46 [ 0 ] ,
( unsigned char ) V_55 -> V_85 ) ;
V_50 = V_49 + V_45 ;
V_47 = false ;
for ( V_11 = 0 ; V_11 < 8 ; V_11 ++ ) {
if ( V_46 [ V_11 ] != * ( V_50 + V_11 ) ) {
F_38 ( V_70 ,
V_78 ,
( L_12
L_13
L_14 , V_11 , V_46 [ V_11 ] ,
V_11 , * ( V_50 + V_11 ) ) ) ;
V_47 = true ;
}
}
if ( V_47 == true ) {
int V_11 ;
F_38 ( V_70 , V_78 ,
( L_15
L_16
L_17 ,
* ( V_50 - 8 ) , * ( V_50 - 7 ) ,
* ( V_50 - 6 ) , * ( V_50 - 5 ) ,
* ( V_50 - 4 ) , * ( V_50 - 3 ) ,
* ( V_50 - 2 ) , * ( V_50 - 1 ) ) ) ;
F_38 ( V_70 , V_78 ,
( L_18
L_16
L_17 ,
* ( V_50 - 16 ) , * ( V_50 - 15 ) ,
* ( V_50 - 14 ) , * ( V_50 - 13 ) ,
* ( V_50 - 12 ) , * ( V_50 - 11 ) ,
* ( V_50 - 10 ) , * ( V_50 - 9 ) ) ) ;
F_38 ( V_70 , V_78 ,
( L_19
L_20 , V_10 -> V_36 -> V_80 ) ) ;
for ( V_11 = 0 ; V_11 < V_10 -> V_36 -> V_80 ; V_11 = V_11 + 8 ) {
F_38 ( V_70 ,
V_78 , ( L_21
L_22
L_23
L_24 ,
* ( V_10 -> V_36 -> V_84 + V_11 ) , * ( V_10 -> V_36 -> V_84 + V_11 + 1 ) ,
* ( V_10 -> V_36 -> V_84 + V_11 + 2 ) , * ( V_10 -> V_36 -> V_84 + V_11 + 3 ) ,
* ( V_10 -> V_36 -> V_84 + V_11 + 4 ) , * ( V_10 -> V_36 -> V_84 + V_11 + 5 ) ,
* ( V_10 -> V_36 -> V_84 + V_11 + 6 ) , * ( V_10 -> V_36 -> V_84 + V_11 + 7 ) ) ) ;
}
F_38 ( V_70 , V_78 ,
( L_25
L_26 , V_10 -> V_36 -> V_80 ) ) ;
F_38 ( V_70 , V_78 ,
( L_27 ,
V_55 -> V_81 ) ) ;
F_38 ( V_70 , V_78 ,
( L_28
L_29
L_30 ,
V_55 -> V_72 [ 0 ] , V_55 -> V_72 [ 1 ] ,
V_55 -> V_72 [ 2 ] , V_55 -> V_72 [ 3 ] ,
V_55 -> V_72 [ 4 ] , V_55 -> V_72 [ 5 ] ,
V_58 -> V_76 ) ) ;
if ( ( F_39 ( V_55 -> V_72 ) ) &&
( V_55 -> V_74 !=
V_64 -> V_74 ) )
V_48 = false ;
if ( ( V_55 -> V_86 == true ) &&
( V_48 == true ) ) {
F_41 ( V_17 , ( T_2 ) F_39 ( V_55 -> V_72 ) ) ;
F_38 ( V_70 , V_78 , ( L_31 , V_55 -> V_86 ) ) ;
F_29 ( L_32
L_33 ,
V_55 -> V_86 ) ;
} else {
F_38 ( V_70 ,
V_78 ,
( L_32
L_34 ,
V_55 -> V_86 ) ) ;
F_29 ( L_32
L_33 ,
V_55 -> V_86 ) ;
}
V_12 = V_77 ;
} else {
if ( ! V_58 -> V_87 &&
F_39 ( V_55 -> V_72 ) ) {
V_58 -> V_87 = 1 ;
F_38 ( V_70 ,
V_78 ,
( L_35
L_36 ) ) ;
}
}
} else {
F_38 ( V_70 , V_78 ,
( L_37
L_38 ) ) ;
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
( L_39 ,
V_55 -> V_86 , V_55 -> V_68 ) ) ;
if ( V_55 -> V_68 > 0 ) {
T_2 * V_90 = V_88 -> V_36 -> V_84 + V_55 -> V_81 ;
V_55 -> V_74 = ( ( ( V_90 [ 3 ] ) >> 6 ) & 0x3 ) ;
if ( V_55 -> V_74 > V_91 ) {
F_29 ( L_40 ,
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
( L_41
L_11 , V_17 -> V_59 . V_111 ) ) ;
if ( V_101 == V_112 ) {
V_100 = V_102 -> V_36 -> V_84 + V_102 -> V_56 . V_81 ;
V_107 = ( V_100 [ 6 ] << 8 ) | V_100 [ 7 ] ;
if ( ( V_103 != NULL ) && ( V_103 -> V_113 ) ) {
F_38 ( V_70 , V_71 ,
( L_42
L_43 ) ) ;
if ( V_107 == V_108 ) {
V_106 = V_88 ;
} else {
F_23 ( V_88 ) ;
V_106 = NULL ;
}
} else {
F_38 ( V_70 , V_71 ,
( L_42
L_44 ) ) ;
F_38 ( V_70 , V_71 ,
( L_45
L_46 , V_88 -> V_56 . V_114 ) ) ;
if ( V_110 -> V_86 == 0 ) {
F_38 ( V_70 , V_71 ,
( L_47 ,
V_110 -> V_86 ) ) ;
}
V_106 = V_88 ;
if ( V_107 == V_108 ) {
F_38 ( V_70 , V_115 ,
( L_48
L_49 ) ) ;
V_106 = V_88 ;
} else {
F_38 ( V_70 , V_71 ,
( L_50
L_20 , V_107 ) ) ;
}
}
} else {
V_106 = V_88 ;
}
return V_106 ;
}
int F_48 ( struct V_9 * V_88 , T_2 V_116 ,
struct V_117 * V_118 )
{
int V_119 = V_88 -> V_56 . V_85 ;
T_4 V_120 = ( ( V_88 -> V_56 . V_121 & 0xffff ) << 4 ) |
( V_88 -> V_56 . V_122 & 0xf ) ;
if ( V_119 > 15 ) {
F_38 ( V_70 , V_115 ,
( L_51 ,
V_120 , V_119 ) ) ;
return V_77 ;
}
if ( 1 ) {
if ( V_120 == V_118 -> V_123 [ V_119 ] ) {
F_38 ( V_70 , V_115 ,
( L_52
L_53 ,
V_120 , V_119 , V_118 -> V_123 [ V_119 ] ) ) ;
return V_77 ;
}
}
V_118 -> V_123 [ V_119 ] = V_120 ;
return V_13 ;
}
void F_49 ( struct V_7 * V_8 ,
struct V_9 * V_88 )
{
#ifdef F_50
unsigned char V_124 ;
struct V_125 * V_126 = V_88 -> V_36 ;
struct V_127 * V_38 = (struct V_127 * ) V_126 -> V_84 ;
struct V_54 * V_110 = & V_88 -> V_56 ;
struct V_104 * V_105 = & V_8 -> V_66 ;
struct V_52 * V_103 = NULL ;
V_103 = F_37 ( V_105 , V_110 -> V_128 ) ;
if ( V_103 ) {
V_124 = F_51 ( V_38 -> V_129 ) ;
if ( V_124 ) {
if ( ! ( V_103 -> V_130 & V_131 ) )
F_52 ( V_8 , V_103 ) ;
} else {
if ( V_103 -> V_130 & V_131 )
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
V_103 = F_37 ( V_105 , V_110 -> V_128 ) ;
if ( ! V_103 )
return;
if ( ! V_103 -> V_132 )
return;
if ( ! ( V_103 -> V_133 & 0xf ) )
return;
if ( V_103 -> V_130 & V_131 ) {
T_2 V_134 = 0 ;
switch ( V_110 -> V_85 ) {
case 1 :
case 2 :
V_134 = V_103 -> V_135 & F_55 ( 1 ) ;
break;
case 4 :
case 5 :
V_134 = V_103 -> V_136 & F_55 ( 1 ) ;
break;
case 6 :
case 7 :
V_134 = V_103 -> V_137 & F_55 ( 1 ) ;
break;
case 0 :
case 3 :
default:
V_134 = V_103 -> V_138 & F_55 ( 1 ) ;
break;
}
if ( V_134 ) {
if ( V_103 -> V_139 > 0 ) {
F_56 ( V_8 , V_103 ) ;
} else {
F_57 ( V_8 , V_103 -> V_140 ,
( T_4 ) V_110 -> V_85 ,
0 , 0 ) ;
}
}
}
#endif
}
static void F_58 ( struct V_7 * V_8 ,
struct V_9 * V_141 , struct V_52 * V_142 )
{
int V_143 ;
struct V_52 * V_103 = NULL ;
struct V_144 * V_145 = NULL ;
struct V_54 * V_110 = & V_141 -> V_56 ;
struct V_5 * V_6 = & V_8 -> V_35 ;
V_143 = V_141 -> V_36 -> V_80 ;
V_6 -> V_146 += V_143 ;
V_8 -> V_147 . V_148 . V_149 ++ ;
if ( ( ! F_59 ( V_110 -> V_150 ) ) &&
( ! F_39 ( V_110 -> V_150 ) ) )
V_8 -> V_147 . V_148 . V_151 ++ ;
if ( V_142 )
V_103 = V_142 ;
else
V_103 = V_141 -> V_103 ;
if ( V_103 ) {
V_145 = & V_103 -> V_152 ;
V_145 -> V_153 ++ ;
V_145 -> V_146 += V_143 ;
}
}
static int F_60 ( struct V_7 * V_17 ,
struct V_9 * V_88 ,
struct V_52 * * V_103 )
{
struct V_125 * V_126 = V_88 -> V_36 ;
struct V_127 * V_38 = (struct V_127 * ) V_126 -> V_84 ;
int V_154 = V_13 ;
struct V_54 * V_110 = & V_88 -> V_56 ;
struct V_104 * V_105 = & V_17 -> V_66 ;
struct V_155 * V_156 = & V_17 -> V_147 ;
T_2 * V_157 = F_61 ( V_156 ) ;
T_2 * V_158 = F_62 ( & V_17 -> V_159 ) ;
T_2 * V_160 = NULL ;
int V_161 = F_39 ( V_110 -> V_150 ) ;
if ( F_63 ( V_156 , V_162 ) ||
F_63 ( V_156 , V_163 ) ) {
if ( F_64 ( V_158 , V_110 -> V_128 ) ) {
F_38 ( V_70 , V_78 ,
( L_54 ) ) ;
V_154 = V_77 ;
goto exit;
}
if ( ! F_64 ( V_158 , V_110 -> V_150 ) && ! V_161 ) {
V_154 = V_77 ;
goto exit;
}
if ( F_64 ( V_110 -> V_164 , L_55 ) ||
F_64 ( V_157 , L_55 ) ||
! F_64 ( V_110 -> V_164 , V_157 ) ) {
V_154 = V_77 ;
goto exit;
}
V_160 = V_110 -> V_128 ;
} else if ( F_63 ( V_156 , V_165 ) ) {
if ( ! F_64 ( V_110 -> V_164 , V_110 -> V_128 ) ) {
F_38 ( V_70 , V_78 ,
( L_56
L_57 ) ) ;
V_154 = V_77 ;
goto exit;
}
V_160 = V_110 -> V_164 ;
} else if ( F_63 ( V_156 , V_166 ) ) {
if ( V_161 ) {
if ( ! F_39 ( V_110 -> V_164 ) ) {
V_154 = V_77 ;
goto exit;
}
} else {
if ( ! F_64 ( V_110 -> V_164 , V_110 -> V_150 ) ) {
V_154 = V_77 ;
goto exit;
}
V_160 = V_110 -> V_128 ;
}
} else if ( F_63 ( V_156 , V_167 ) ) {
F_65 ( V_110 -> V_150 , V_38 -> V_168 ) ;
F_65 ( V_110 -> V_128 , V_38 -> V_169 ) ;
F_65 ( V_110 -> V_164 , V_38 -> V_170 ) ;
F_65 ( V_110 -> V_72 , V_110 -> V_150 ) ;
F_65 ( V_110 -> V_67 , V_110 -> V_128 ) ;
V_160 = V_157 ;
} else {
V_154 = V_77 ;
}
if ( V_161 )
* V_103 = F_66 ( V_17 ) ;
else
* V_103 = F_37 ( V_105 , V_160 ) ;
if ( * V_103 == NULL ) {
F_38 ( V_70 , V_78 , ( L_58 ) ) ;
V_154 = V_77 ;
goto exit;
}
exit:
return V_154 ;
}
int F_67 ( struct V_7 * V_17 ,
struct V_9 * V_88 ,
struct V_52 * * V_103 )
{
struct V_125 * V_126 = V_88 -> V_36 ;
struct V_127 * V_38 = (struct V_127 * ) V_126 -> V_84 ;
struct V_54 * V_110 = & V_88 -> V_56 ;
int V_154 = V_13 ;
struct V_104 * V_105 = & V_17 -> V_66 ;
struct V_155 * V_156 = & V_17 -> V_147 ;
T_2 * V_157 = F_61 ( V_156 ) ;
T_2 * V_158 = F_62 ( & V_17 -> V_159 ) ;
int V_161 = F_39 ( V_110 -> V_150 ) ;
if ( F_63 ( V_156 , V_165 ) &&
( F_63 ( V_156 , V_171 ) ||
F_63 ( V_156 , V_172 ) ) ) {
if ( F_64 ( V_158 , V_110 -> V_128 ) ) {
F_38 ( V_70 , V_78 ,
( L_54 ) ) ;
V_154 = V_77 ;
goto exit;
}
if ( ! F_64 ( V_158 , V_110 -> V_150 ) && ! V_161 ) {
F_38 ( V_70 , V_71 ,
( L_59
V_173 L_20 , F_68 ( V_110 -> V_150 ) ) ) ;
V_154 = V_77 ;
goto exit;
}
if ( F_64 ( V_110 -> V_164 , L_55 ) ||
F_64 ( V_157 , L_55 ) ||
! F_64 ( V_110 -> V_164 , V_157 ) ) {
F_38 ( V_70 , V_71 ,
( L_60
L_61 V_173 L_20 , F_68 ( V_110 -> V_164 ) ) ) ;
F_38 ( V_70 , V_71 ,
( L_62 V_173 L_20 , F_68 ( V_157 ) ) ) ;
if ( ! V_161 ) {
F_29 ( L_63
L_64 V_173 L_65 ,
F_68 ( V_110 -> V_164 ) ) ;
F_69 ( V_17 , V_110 -> V_164 ,
V_174 ) ;
}
V_154 = V_77 ;
goto exit;
}
if ( V_161 )
* V_103 = F_66 ( V_17 ) ;
else
* V_103 = F_37 ( V_105 , V_110 -> V_164 ) ;
if ( * V_103 == NULL ) {
F_38 ( V_70 , V_78 ,
( L_66
L_67 ) ) ;
V_154 = V_77 ;
goto exit;
}
if ( F_70 ( V_38 -> V_129 ) ) {
F_58 ( V_17 , V_88 , * V_103 ) ;
V_154 = V_175 ;
goto exit;
}
} else if ( F_63 ( V_156 , V_167 ) &&
F_63 ( V_156 , V_171 ) ) {
F_65 ( V_110 -> V_150 , V_38 -> V_168 ) ;
F_65 ( V_110 -> V_128 , V_38 -> V_169 ) ;
F_65 ( V_110 -> V_164 , V_38 -> V_170 ) ;
F_65 ( V_110 -> V_72 , V_110 -> V_150 ) ;
F_65 ( V_110 -> V_67 , V_110 -> V_128 ) ;
F_65 ( V_110 -> V_164 , V_157 ) ;
* V_103 = F_37 ( V_105 , V_110 -> V_164 ) ;
if ( * V_103 == NULL ) {
F_38 ( V_70 , V_78 ,
( L_68 ) ) ;
V_154 = V_77 ;
goto exit;
}
} else if ( F_63 ( V_156 , V_166 ) ) {
V_154 = V_175 ;
goto exit;
} else {
if ( F_64 ( V_158 , V_110 -> V_150 ) && ! V_161 ) {
* V_103 = F_37 ( V_105 , V_110 -> V_164 ) ;
if ( * V_103 == NULL ) {
F_29 ( L_69 V_173
L_65 ,
F_68 ( V_110 -> V_164 ) ) ;
F_69 ( V_17 , V_110 -> V_164 ,
V_174 ) ;
}
}
V_154 = V_77 ;
}
exit:
return V_154 ;
}
int F_71 ( struct V_7 * V_17 ,
struct V_9 * V_88 ,
struct V_52 * * V_103 )
{
struct V_125 * V_126 = V_88 -> V_36 ;
struct V_127 * V_38 = (struct V_127 * ) V_126 -> V_84 ;
struct V_54 * V_110 = & V_88 -> V_56 ;
struct V_104 * V_105 = & V_17 -> V_66 ;
struct V_155 * V_156 = & V_17 -> V_147 ;
unsigned char * V_157 = F_61 ( V_156 ) ;
int V_154 = V_13 ;
if ( F_63 ( V_156 , V_166 ) ) {
if ( ! F_64 ( V_110 -> V_164 , V_157 ) ) {
V_154 = V_77 ;
goto exit;
}
* V_103 = F_37 ( V_105 , V_110 -> V_128 ) ;
if ( * V_103 == NULL ) {
F_38 ( V_70 , V_78 ,
( L_70 ) ) ;
F_29 ( L_71 V_173
L_65 ,
F_68 ( V_110 -> V_128 ) ) ;
F_69 ( V_17 , V_110 -> V_128 ,
V_174 ) ;
V_154 = V_175 ;
goto exit;
}
F_49 ( V_17 , V_88 ) ;
if ( F_72 ( V_38 -> V_129 ) )
F_54 ( V_17 , V_88 ) ;
if ( F_70 ( V_38 -> V_129 ) ) {
F_58 ( V_17 , V_88 , * V_103 ) ;
V_154 = V_175 ;
goto exit;
}
} else {
T_2 * V_158 = F_62 ( & V_17 -> V_159 ) ;
if ( ! F_64 ( V_110 -> V_72 , V_158 ) ) {
V_154 = V_175 ;
goto exit;
}
F_29 ( L_71 V_173 L_65 ,
F_68 ( V_110 -> V_128 ) ) ;
F_69 ( V_17 , V_110 -> V_128 ,
V_174 ) ;
V_154 = V_175 ;
goto exit;
}
exit:
return V_154 ;
}
static int F_73 ( struct V_7 * V_8 ,
struct V_9 * V_88 )
{
#ifdef F_50
struct V_54 * V_110 = & V_88 -> V_56 ;
struct V_104 * V_105 = & V_8 -> V_66 ;
struct V_125 * V_126 = V_88 -> V_36 ;
struct V_127 * V_38 = (struct V_127 * ) V_126 -> V_84 ;
if ( ! F_74 ( V_38 -> V_129 ) )
return V_77 ;
if ( ! F_64 ( V_38 -> V_168 , F_62 ( & V_8 -> V_159 ) ) )
return V_77 ;
if ( F_75 ( V_38 -> V_129 ) ) {
struct V_176 * V_177 = (struct V_176 * ) V_38 ;
T_4 V_178 ;
T_2 V_134 = 0 ;
struct V_52 * V_103 = NULL ;
V_178 = F_76 ( V_177 -> V_178 ) & 0x3fff ;
V_103 = F_37 ( V_105 , V_38 -> V_169 ) ;
if ( ! V_103 || V_103 -> V_178 != V_178 )
return V_77 ;
V_103 -> V_152 . V_179 ++ ;
switch ( V_110 -> V_85 ) {
case 1 :
case 2 :
V_134 = V_103 -> V_135 & F_55 ( 0 ) ;
break;
case 4 :
case 5 :
V_134 = V_103 -> V_136 & F_55 ( 0 ) ;
break;
case 6 :
case 7 :
V_134 = V_103 -> V_137 & F_55 ( 0 ) ;
break;
case 0 :
case 3 :
default:
V_134 = V_103 -> V_138 & F_55 ( 0 ) ;
break;
}
if ( V_134 )
return V_77 ;
if ( V_103 -> V_130 & V_180 ) {
F_29 ( L_72 , V_41 ) ;
V_103 -> V_181 = V_105 -> V_181 ;
V_103 -> V_130 ^= V_180 ;
}
if ( ( V_103 -> V_130 & V_131 ) &&
( V_105 -> V_182 & F_77 ( V_103 -> V_178 ) ) ) {
struct V_27 * V_183 , * V_184 ;
struct V_185 * V_186 ;
struct V_187 * V_188 = & V_8 -> V_189 ;
F_19 ( & V_188 -> V_3 ) ;
V_184 = F_21 ( & V_103 -> V_190 ) ;
V_183 = V_184 -> V_34 ;
if ( ! F_20 ( V_184 ) ) {
V_186 = F_14 ( V_183 ,
struct V_185 ,
V_20 ) ;
V_183 = V_183 -> V_34 ;
F_15 ( & V_186 -> V_20 ) ;
V_103 -> V_191 -- ;
if ( V_103 -> V_191 > 0 )
V_186 -> V_56 . V_192 = 1 ;
else
V_186 -> V_56 . V_192 = 0 ;
V_186 -> V_56 . V_193 = 1 ;
F_78 ( V_8 ,
V_186 ) ;
if ( V_103 -> V_191 == 0 ) {
V_105 -> V_194 &= ~ F_77 ( V_103 -> V_178 ) ;
F_79 ( V_8 , V_195 ,
NULL , false ) ;
}
F_22 ( & V_188 -> V_3 ) ;
} else {
F_22 ( & V_188 -> V_3 ) ;
if ( V_105 -> V_194 & F_77 ( V_103 -> V_178 ) ) {
if ( V_103 -> V_191 == 0 ) {
F_29 ( L_73
L_74 ) ;
F_80 ( V_8 ,
V_103 -> V_140 ,
0 , 0 , 0 ) ;
} else {
F_29 ( L_75
L_76 ,
V_103 -> V_191 ) ;
V_103 -> V_191 = 0 ;
}
V_105 -> V_194 &= ~ F_77 ( V_103 -> V_178 ) ;
F_79 ( V_8 , V_195 ,
NULL , false ) ;
}
}
}
}
#endif
return V_77 ;
}
static int F_81 ( struct V_7 * V_8 ,
struct V_9 * V_88 )
{
struct V_52 * V_103 ;
struct V_125 * V_126 ;
struct V_127 * V_38 ;
F_38 ( V_70 , V_71 ,
( L_77 ) ) ;
V_88 = F_82 ( V_8 , V_88 ) ;
if ( V_88 == NULL ) {
F_38 ( V_70 , V_115 ,
( L_78 , V_41 ) ) ;
return V_13 ;
}
V_126 = V_88 -> V_36 ;
V_38 = (struct V_127 * ) V_126 -> V_84 ;
V_103 = F_37 ( & V_8 -> V_66 , V_38 -> V_169 ) ;
if ( V_103 ) {
V_103 -> V_152 . V_196 ++ ;
if ( F_83 ( V_38 -> V_129 ) )
V_103 -> V_152 . V_197 ++ ;
else if ( F_84 ( V_38 -> V_129 ) )
V_103 -> V_152 . V_198 ++ ;
else if ( F_85 ( V_38 -> V_129 ) ) {
if ( F_64 ( V_8 -> V_159 . V_199 ,
V_38 -> V_168 ) )
V_103 -> V_152 . V_200 ++ ;
else if ( F_59 ( V_38 -> V_168 ) ||
F_39 ( V_38 -> V_168 ) )
V_103 -> V_152 . V_201 ++ ;
else
V_103 -> V_152 . V_202 ++ ;
}
}
F_86 ( V_8 , V_88 ) ;
return V_13 ;
}
static int F_87 ( struct V_7 * V_17 ,
struct V_9 * V_88 )
{
T_2 V_116 ;
T_2 * V_203 , * V_204 ;
struct V_52 * V_103 = NULL ;
struct V_54 * V_110 = & V_88 -> V_56 ;
struct V_57 * V_58 = & V_17 -> V_59 ;
int V_154 = V_13 ;
struct V_125 * V_126 = V_88 -> V_36 ;
struct V_127 * V_38 = (struct V_127 * ) V_126 -> V_84 ;
V_116 = F_88 ( V_38 -> V_129 ) ;
V_204 = F_89 ( V_38 ) ;
V_203 = F_90 ( V_38 ) ;
F_65 ( V_110 -> V_150 , V_204 ) ;
F_65 ( V_110 -> V_128 , V_203 ) ;
switch ( V_38 -> V_129 &
F_91 ( V_205 | V_206 ) ) {
case F_91 ( 0 ) :
F_65 ( V_110 -> V_164 , V_38 -> V_170 ) ;
F_65 ( V_110 -> V_72 , V_204 ) ;
F_65 ( V_110 -> V_67 , V_203 ) ;
V_154 = F_60 ( V_17 , V_88 , & V_103 ) ;
break;
case F_91 ( V_206 ) :
F_65 ( V_110 -> V_164 , V_38 -> V_169 ) ;
F_65 ( V_110 -> V_72 , V_204 ) ;
F_65 ( V_110 -> V_67 , V_38 -> V_169 ) ;
V_154 = F_67 ( V_17 , V_88 , & V_103 ) ;
break;
case F_91 ( V_205 ) :
F_65 ( V_110 -> V_164 , V_38 -> V_168 ) ;
F_65 ( V_110 -> V_72 , V_38 -> V_168 ) ;
F_65 ( V_110 -> V_67 , V_203 ) ;
V_154 = F_71 ( V_17 , V_88 , & V_103 ) ;
break;
case F_91 ( V_205 | V_206 ) :
F_65 ( V_110 -> V_164 , V_38 -> V_168 ) ;
F_65 ( V_110 -> V_72 , V_38 -> V_168 ) ;
F_65 ( V_110 -> V_67 , V_38 -> V_169 ) ;
V_154 = V_77 ;
F_38 ( V_70 , V_78 , ( L_79 ) ) ;
break;
}
if ( ( V_154 == V_77 ) || ( V_154 == V_175 ) )
goto exit;
if ( ! V_103 ) {
F_38 ( V_70 , V_78 ,
( L_80 ) ) ;
V_154 = V_77 ;
goto exit;
}
V_88 -> V_103 = V_103 ;
V_110 -> V_81 = sizeof( struct V_207 ) ;
if ( F_92 ( V_38 -> V_129 ) )
V_110 -> V_81 += V_208 ;
if ( V_110 -> V_209 == 1 ) {
T_5 * V_210 = ( T_5 * ) F_93 ( V_38 ) ;
T_4 V_211 = F_76 ( * V_210 ) ;
V_110 -> V_85 = V_211 & V_212 ;
V_110 -> V_213 = ( V_211 >> 5 ) & 3 ;
V_110 -> V_214 =
( V_211 & V_215 ) >> 7 ;
V_110 -> V_81 += V_216 ;
if ( V_110 -> V_85 != 0 && V_110 -> V_85 != 3 ) {
V_17 -> V_35 . V_217 = true ;
}
} else {
V_110 -> V_85 = 0 ;
V_110 -> V_213 = 0 ;
V_110 -> V_214 = 0 ;
}
if ( V_110 -> V_218 ) {
V_110 -> V_81 += 4 ;
}
V_88 -> V_219 = & V_103 -> V_220 [ V_110 -> V_85 ] ;
if ( F_48 ( V_88 , V_116 , & V_103 -> V_221 . V_222 ) ==
V_77 ) {
F_38 ( V_70 , V_78 ,
( L_81 ) ) ;
V_154 = V_77 ;
goto exit;
}
if ( V_110 -> V_114 ) {
F_38 ( V_70 , V_71 ,
( L_82 ,
V_110 -> V_114 ) ) ;
F_38 ( V_70 , V_71 ,
( L_83
L_84 ,
V_110 -> V_72 [ 0 ] ,
F_39 ( V_110 -> V_72 ) ) ) ;
F_94 ( V_58 , V_103 , V_110 -> V_68 ,
F_39 ( V_110 -> V_72 ) ) ;
F_38 ( V_70 , V_71 ,
( L_85 , V_110 -> V_68 ) ) ;
switch ( V_110 -> V_68 )
{
case V_92 :
case V_93 :
V_110 -> V_82 = V_223 ;
V_110 -> V_83 = V_224 ;
break;
case V_69 :
V_110 -> V_82 = V_225 ;
V_110 -> V_83 = V_226 ;
break;
case V_95 :
V_110 -> V_82 = V_227 ;
V_110 -> V_83 = V_228 ;
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
return V_154 ;
}
static void F_95 ( struct V_125 * V_126 , T_4 type , int V_229 )
{
int V_11 ;
T_2 * V_100 ;
if ( ( V_229 == 1 ) ||
( ( V_229 == 2 ) && ( type == V_230 ) ) ||
( ( V_229 == 3 ) && ( type == V_231 ) ) ) {
V_100 = V_126 -> V_84 ;
F_29 ( L_86 ) ;
for ( V_11 = 0 ; V_11 < 64 ; V_11 = V_11 + 8 )
F_29 ( L_87 ,
* ( V_100 + V_11 ) , * ( V_100 + V_11 + 1 ) , * ( V_100 + V_11 + 2 ) ,
* ( V_100 + V_11 + 3 ) , * ( V_100 + V_11 + 4 ) ,
* ( V_100 + V_11 + 5 ) , * ( V_100 + V_11 + 6 ) ,
* ( V_100 + V_11 + 7 ) ) ;
F_29 ( L_86 ) ;
}
}
static int F_96 ( struct V_7 * V_17 ,
struct V_9 * V_88 )
{
T_2 type ;
T_2 V_232 ;
int V_233 = V_13 ;
struct V_54 * V_110 = & V_88 -> V_56 ;
struct V_125 * V_126 = V_88 -> V_36 ;
struct V_127 * V_38 = (struct V_127 * ) V_126 -> V_84 ;
T_2 V_234 ;
T_2 V_235 ;
T_4 V_120 , V_236 ;
V_236 = F_76 ( V_38 -> V_129 ) ;
V_234 = V_236 & V_237 ;
type = V_236 & V_238 ;
V_232 = V_236 & V_239 ;
if ( V_234 != 0 ) {
F_38 ( V_70 , V_78 ,
( L_88 ) ) ;
V_233 = V_77 ;
goto exit;
}
V_120 = F_76 ( V_38 -> V_120 ) ;
V_110 -> V_122 = V_120 & V_240 ;
V_110 -> V_121 = V_120 >> 4 ;
V_110 -> V_241 = F_51 ( V_38 -> V_129 ) ;
V_110 -> V_242 = F_97 ( V_38 -> V_129 ) ;
V_110 -> V_192 = F_98 ( V_38 -> V_129 ) ;
V_110 -> V_114 = F_99 ( V_38 -> V_129 ) ;
V_110 -> V_218 = F_100 ( V_38 -> V_129 ) ;
F_101 ( V_17 , V_243 , & V_235 ) ;
if ( F_102 ( V_235 == 1 ) )
F_95 ( V_126 , type , V_235 ) ;
switch ( type )
{
case V_230 :
V_233 = F_81 ( V_17 , V_88 ) ;
if ( V_233 == V_77 ) {
F_38 ( V_70 , V_78 ,
( L_89 ) ) ;
}
V_233 = V_77 ;
break;
case V_244 :
V_233 = F_73 ( V_17 , V_88 ) ;
if ( V_233 == V_77 ) {
F_38 ( V_70 , V_78 ,
( L_90 ) ) ;
}
V_233 = V_77 ;
break;
case V_231 :
F_103 ( V_17 , V_245 ) ;
V_110 -> V_209 = ( V_232 & V_246 ) ? 1 : 0 ;
V_233 = F_87 ( V_17 , V_88 ) ;
if ( V_233 == V_77 ) {
struct V_5 * V_6 = & V_17 -> V_35 ;
V_6 -> V_247 ++ ;
}
break;
default:
F_38 ( V_70 , V_78 ,
( L_91 , type ) ) ;
V_233 = V_77 ;
break;
}
exit:
return V_233 ;
}
static int F_104 ( struct V_9 * V_10 )
{
T_4 V_248 , V_80 , V_81 ;
T_2 V_249 ;
T_2 * V_250 ;
int V_154 = V_13 ;
struct V_7 * V_17 = V_10 -> V_17 ;
struct V_155 * V_156 = & V_17 -> V_147 ;
struct V_125 * V_126 = V_10 -> V_36 ;
T_2 * V_100 ;
struct V_54 * V_110 = & V_10 -> V_56 ;
V_100 = V_126 -> V_84 ;
V_81 = V_110 -> V_81 ;
V_250 = V_100 + V_81 ;
V_248 = ( V_250 [ 6 ] << 8 ) | V_250 [ 7 ] ;
if ( ( F_64 ( V_250 , V_251 ) &&
V_248 != V_252 && V_248 != V_253 ) ||
F_64 ( V_250 , V_254 ) ) {
V_249 = true ;
V_81 += V_255 ;
} else {
V_249 = false ;
V_248 = ( V_250 [ 0 ] << 8 ) | V_250 [ 1 ] ;
}
V_80 = V_126 -> V_80 - V_81 ;
F_38 ( V_70 , V_71 ,
( L_92 ,
V_110 -> V_81 , V_110 -> V_82 ) ) ;
V_110 -> V_248 = V_248 ;
if ( F_63 ( V_156 , V_167 ) ) {
V_100 += V_81 ;
* V_100 = 0x87 ;
* ( V_100 + 1 ) = 0x12 ;
V_248 = 0x8712 ;
V_100 = F_105 ( V_126 , ( V_81 - sizeof( struct V_256 ) + 2 ) - 24 ) ;
memcpy ( V_100 , V_126 -> V_257 , 24 ) ;
V_100 += 24 ;
} else {
V_100 = F_105 ( V_126 , ( V_81 - sizeof( struct V_256 ) +
( V_249 ? 2 : 0 ) ) ) ;
}
F_65 ( V_100 , V_110 -> V_150 ) ;
F_65 ( V_100 + V_208 , V_110 -> V_128 ) ;
if ( ! V_249 ) {
V_80 = F_106 ( V_80 ) ;
memcpy ( V_100 + 12 , & V_80 , 2 ) ;
}
return V_154 ;
}
struct V_9 * F_107 ( struct V_7 * V_17 ,
struct V_30 * V_4 )
{
struct V_27 * V_28 , * V_33 , * V_29 ;
T_2 * V_84 , V_258 ;
T_2 V_259 ;
struct V_9 * V_260 ;
struct V_9 * V_141 , * V_261 ;
struct V_30 * V_31 ;
struct V_125 * V_126 ;
V_259 = 0 ;
V_31 = & V_17 -> V_35 . V_14 ;
V_33 = F_21 ( V_4 ) ;
V_28 = V_33 -> V_34 ;
V_141 = F_14 ( V_28 , struct V_9 , V_20 ) ;
F_15 ( & V_141 -> V_20 ) ;
V_126 = V_141 -> V_36 ;
if ( V_259 != V_141 -> V_56 . V_122 ) {
F_23 ( V_141 ) ;
F_26 ( V_4 ) ;
return NULL ;
}
V_259 ++ ;
V_33 = F_21 ( V_4 ) ;
V_84 = V_141 -> V_36 -> V_84 ;
F_13 (plist, ptmp, phead) {
V_260 = F_14 ( V_28 , struct V_9 , V_20 ) ;
V_261 = (struct V_9 * ) V_260 ;
if ( V_259 != V_260 -> V_56 . V_122 ) {
F_23 ( V_141 ) ;
F_26 ( V_4 ) ;
return NULL ;
}
V_259 ++ ;
V_258 = V_260 -> V_56 . V_81 + V_260 -> V_56 . V_82 ;
F_105 ( V_260 -> V_36 , V_258 ) ;
F_42 ( V_126 , V_126 -> V_80 - V_141 -> V_56 . V_83 ) ;
memcpy ( F_108 ( V_126 ) , V_260 -> V_36 -> V_84 ,
V_260 -> V_36 -> V_80 ) ;
F_109 ( V_126 , V_260 -> V_36 -> V_80 ) ;
V_141 -> V_56 . V_83 = V_260 -> V_56 . V_83 ;
} ;
F_26 ( V_4 ) ;
F_38 ( V_70 , V_71 ,
( L_93 ) ) ;
return V_141 ;
}
struct V_9 * F_82 ( struct V_7 * V_8 ,
struct V_9 * V_88 )
{
T_2 V_262 ;
T_2 V_263 ;
T_2 * V_99 ;
struct V_9 * V_102 ;
struct V_52 * V_103 ;
struct V_104 * V_105 ;
struct V_27 * V_33 ;
struct V_9 * V_106 = NULL ;
struct V_30 * V_31 , * V_264 ;
V_105 = & V_8 -> V_66 ;
V_102 = V_88 ;
V_31 = & V_8 -> V_35 . V_14 ;
V_262 = V_102 -> V_56 . V_242 ;
V_263 = V_102 -> V_56 . V_122 ;
V_99 = V_102 -> V_56 . V_67 ;
V_103 = F_37 ( V_105 , V_99 ) ;
if ( ! V_103 ) {
struct V_127 * V_38 =
(struct V_127 * ) V_102 -> V_36 -> V_84 ;
if ( ! F_110 ( V_38 -> V_129 ) ) {
V_103 = F_66 ( V_8 ) ;
V_264 = & V_103 -> V_221 . V_4 ;
} else
V_264 = NULL ;
} else
V_264 = & V_103 -> V_221 . V_4 ;
if ( ( V_262 == 0 ) && ( V_263 == 0 ) ) {
V_106 = V_88 ;
}
if ( V_262 == 1 ) {
if ( V_264 != NULL ) {
if ( V_263 == 0 ) {
if ( ! F_20 ( & V_264 -> V_21 ) ) {
F_26 ( V_264 ) ;
}
}
V_33 = F_21 ( V_264 ) ;
F_7 ( & V_102 -> V_20 , V_33 ) ;
F_38 ( V_70 , V_71 ,
( L_94 ,
V_262 , V_263 ) ) ;
V_106 = NULL ;
} else {
F_23 ( V_88 ) ;
V_106 = NULL ;
F_38 ( V_70 , V_78 ,
( L_95
L_96 , V_262 , V_263 ) ) ;
}
}
if ( ( V_262 == 0 ) && ( V_263 != 0 ) ) {
if ( V_264 != NULL ) {
V_33 = F_21 ( V_264 ) ;
F_7 ( & V_102 -> V_20 , V_33 ) ;
F_38 ( V_70 , V_71 ,
( L_97 ,
V_262 , V_263 ) ) ;
V_88 = F_107 ( V_8 , V_264 ) ;
V_106 = V_88 ;
} else {
F_23 ( V_88 ) ;
V_106 = NULL ;
F_38 ( V_70 , V_78 ,
( L_95
L_96 , V_262 , V_263 ) ) ;
}
}
if ( ( V_106 != NULL ) && ( V_106 -> V_56 . V_114 ) ) {
if ( F_36 ( V_8 , V_106 ) == V_77 ) {
F_38 ( V_70 , V_78 ,
( L_98
L_99 ) ) ;
F_23 ( V_106 ) ;
V_106 = NULL ;
}
}
return V_106 ;
}
int F_111 ( struct V_7 * V_8 , struct V_9 * V_141 )
{
struct V_54 * V_110 ;
struct V_125 * V_126 , * V_265 ;
struct V_266 V_267 ;
V_110 = & V_141 -> V_56 ;
V_126 = V_141 -> V_36 ;
F_105 ( V_126 , V_141 -> V_56 . V_81 ) ;
F_112 ( & V_267 ) ;
F_113 ( V_126 , & V_267 , NULL , 0 , 0 , false ) ;
while ( ! F_114 ( & V_267 ) ) {
V_265 = F_115 ( & V_267 ) ;
V_265 -> V_268 = F_116 ( V_265 , V_8 -> V_269 ) ;
V_265 -> V_270 = V_8 -> V_269 ;
V_265 -> V_271 = V_272 ;
F_117 ( V_265 ) ;
}
V_141 -> V_36 = NULL ;
F_23 ( V_141 ) ;
return V_13 ;
}
int F_118 ( struct V_273 * V_219 , T_4 V_121 )
{
T_2 V_274 = V_219 -> V_275 ;
T_4 V_276 = ( V_219 -> V_277 + V_274 - 1 ) & 0xFFF ;
if ( V_219 -> V_277 == 0xFFFF )
V_219 -> V_277 = V_121 ;
if ( F_119 ( V_121 , V_219 -> V_277 ) )
return false ;
if ( F_120 ( V_121 , V_219 -> V_277 ) ) {
V_219 -> V_277 =
( V_219 -> V_277 + 1 ) & 0xFFF ;
} else if ( F_119 ( V_276 , V_121 ) ) {
if ( V_121 >= ( V_274 - 1 ) )
V_219 -> V_277 = V_121 + 1 - V_274 ;
else
V_219 -> V_277 = 0xFFF - ( V_274 - ( V_121 + 1 ) ) + 1 ;
}
return true ;
}
static int F_121 ( struct V_273 * V_219 ,
struct V_9 * V_141 )
{
struct V_54 * V_110 = & V_141 -> V_56 ;
struct V_30 * V_278 ;
struct V_27 * V_33 , * V_28 , * V_29 ;
struct V_9 * V_38 ;
struct V_54 * V_279 ;
V_278 = & V_219 -> V_280 ;
V_33 = F_21 ( V_278 ) ;
F_13 (plist, ptmp, phead) {
V_38 = F_14 ( V_28 , struct V_9 , V_20 ) ;
V_279 = & V_38 -> V_56 ;
if ( F_119 ( V_279 -> V_121 , V_110 -> V_121 ) ) {
continue;
} else if ( F_120 ( V_279 -> V_121 , V_110 -> V_121 ) ) {
return false ;
} else {
break;
}
}
F_15 ( & V_141 -> V_20 ) ;
F_7 ( & V_141 -> V_20 , V_28 ) ;
return true ;
}
int F_122 ( struct V_7 * V_8 ,
struct V_273 * V_219 ,
int V_281 )
{
struct V_27 * V_33 , * V_28 ;
struct V_9 * V_141 ;
struct V_54 * V_110 ;
int V_282 = false ;
struct V_5 * V_6 ;
struct V_30 * V_278 ;
V_6 = & V_8 -> V_35 ;
V_278 = & V_219 -> V_280 ;
V_33 = F_21 ( V_278 ) ;
V_28 = V_33 -> V_34 ;
if ( V_281 ) {
if ( F_20 ( V_33 ) ) {
return true ;
}
V_141 = F_14 ( V_28 , struct V_9 , V_20 ) ;
V_110 = & V_141 -> V_56 ;
V_219 -> V_277 = V_110 -> V_121 ;
}
while ( ! F_20 ( V_33 ) ) {
V_141 = F_14 ( V_28 , struct V_9 , V_20 ) ;
V_110 = & V_141 -> V_56 ;
if ( ! F_119 ( V_219 -> V_277 , V_110 -> V_121 ) ) {
F_38 ( V_70 , V_115 ,
( L_100
L_101 ,
V_219 -> V_277 ,
V_110 -> V_121 , V_110 -> V_214 ) ) ;
V_28 = V_28 -> V_34 ;
F_15 ( & V_141 -> V_20 ) ;
if ( F_120 ( V_219 -> V_277 ,
V_110 -> V_121 ) ) {
V_219 -> V_277 =
( V_219 -> V_277 + 1 ) & 0xFFF ;
}
if ( ! V_110 -> V_214 ) {
if ( ( V_8 -> V_283 == false ) &&
( V_8 -> V_284 == false ) ) {
F_123 ( V_8 , V_141 ) ;
}
} else {
if ( F_111 ( V_8 , V_141 ) !=
V_13 )
F_23 ( V_141 ) ;
}
V_282 = false ;
} else {
V_282 = true ;
break;
}
}
return V_282 ;
}
int F_124 ( struct V_7 * V_8 ,
struct V_9 * V_141 )
{
int V_233 = V_13 ;
struct V_54 * V_110 ;
struct V_273 * V_219 ;
struct V_30 * V_278 ;
V_110 = & V_141 -> V_56 ;
V_219 = V_141 -> V_219 ;
V_278 = & V_219 -> V_280 ;
if ( ! V_110 -> V_214 ) {
F_104 ( V_141 ) ;
if ( ( V_110 -> V_209 != 1 ) || ( V_110 -> V_248 == V_285 ) ||
( V_110 -> V_213 != 0 ) ) {
if ( ( V_8 -> V_283 == false ) &&
( V_8 -> V_284 == false ) ) {
F_38 ( V_70 , V_115 ,
( L_102
L_103 ) ) ;
F_123 ( V_8 , V_141 ) ;
return V_13 ;
}
return V_77 ;
}
if ( V_219 -> V_286 == false ) {
V_219 -> V_277 = V_110 -> V_121 ;
F_123 ( V_8 , V_141 ) ;
V_219 -> V_277 =
( V_219 -> V_277 + 1 ) % 4096 ;
return V_13 ;
}
} else {
if ( V_219 -> V_286 == false ) {
V_219 -> V_277 = V_110 -> V_121 ;
V_233 = F_111 ( V_8 , V_141 ) ;
V_219 -> V_277 =
( V_219 -> V_277 + 1 ) % 4096 ;
return V_233 ;
}
}
F_19 ( & V_278 -> V_3 ) ;
F_38 ( V_70 , V_115 ,
( L_104 ,
V_219 -> V_277 , V_110 -> V_121 ) ) ;
if ( ! F_118 ( V_219 , V_110 -> V_121 ) ) {
goto V_287;
}
if ( ! F_121 ( V_219 , V_141 ) ) {
goto V_287;
}
if ( F_122 ( V_8 , V_219 , false ) == true ) {
F_125 ( & V_219 -> V_288 ,
V_289 + F_126 ( V_290 ) ) ;
F_22 ( & V_278 -> V_3 ) ;
} else {
F_22 ( & V_278 -> V_3 ) ;
F_127 ( & V_219 -> V_288 ) ;
}
return V_13 ;
V_287:
F_22 ( & V_278 -> V_3 ) ;
return V_77 ;
}
void F_128 ( unsigned long V_291 )
{
struct V_273 * V_219 ;
struct V_7 * V_8 ;
struct V_30 * V_278 ;
V_219 = (struct V_273 * ) V_291 ;
V_8 = V_219 -> V_8 ;
V_278 = & V_219 -> V_280 ;
if ( V_8 -> V_283 || V_8 -> V_284 ) {
return;
}
F_19 ( & V_278 -> V_3 ) ;
if ( F_122 ( V_8 , V_219 , true ) == true ) {
F_125 ( & V_219 -> V_288 ,
V_289 + F_126 ( V_290 ) ) ;
}
F_22 ( & V_278 -> V_3 ) ;
}
int F_129 ( struct V_7 * V_8 ,
struct V_9 * V_141 )
{
int V_233 = V_13 ;
struct V_155 * V_156 = & V_8 -> V_147 ;
struct V_292 * V_293 = & V_156 -> V_294 ;
if ( V_293 -> V_295 == true ) {
if ( F_124 ( V_8 , V_141 ) != V_13 ) {
if ( ( V_8 -> V_283 == false ) &&
( V_8 -> V_284 == false ) ) {
V_233 = V_77 ;
return V_233 ;
}
}
} else
{
V_233 = F_104 ( V_141 ) ;
if ( V_233 != V_13 ) {
F_38 ( V_70 , V_78 ,
( L_105 ) ) ;
return V_233 ;
}
if ( ( V_8 -> V_283 == false ) &&
( V_8 -> V_284 == false ) ) {
F_38 ( V_70 , V_115 ,
( L_106
L_103 ) ) ;
F_123 ( V_8 , V_141 ) ;
} else {
F_38 ( V_70 , V_115 ,
( L_106
L_107 ) ) ;
F_38 ( V_70 , V_115 ,
( L_108
L_109 ,
V_8 -> V_283 ,
V_8 -> V_284 ) ) ;
V_233 = V_77 ;
return V_233 ;
}
}
return V_233 ;
}
static int F_130 ( struct V_7 * V_8 ,
struct V_9 * V_296 )
{
int V_154 = V_13 ;
V_154 = F_96 ( V_8 , V_296 ) ;
if ( V_154 != V_13 ) {
F_38 ( V_70 , V_71 ,
( L_110 ) ) ;
F_23 ( V_296 ) ;
goto exit;
}
exit:
return V_154 ;
}
static int F_131 ( struct V_7 * V_8 ,
struct V_9 * V_141 )
{
int V_154 = V_13 ;
struct V_9 * V_297 = V_141 ;
struct V_5 * V_6 = & V_8 -> V_35 ;
F_103 ( V_8 , V_245 ) ;
V_141 = F_43 ( V_8 , V_141 ) ;
if ( V_141 == NULL ) {
F_38 ( V_70 , V_78 ,
( L_111 ) ) ;
V_154 = V_77 ;
goto V_298;
}
V_141 = F_82 ( V_8 , V_141 ) ;
if ( ! V_141 ) {
F_38 ( V_70 , V_78 ,
( L_112 ) ) ;
goto V_298;
}
if ( V_141 -> V_56 . V_82 > 0 ) {
F_105 ( V_141 -> V_36 , V_141 -> V_56 . V_82 ) ;
}
if ( V_141 -> V_56 . V_83 > 0 ) {
F_42 ( V_141 -> V_36 ,
V_141 -> V_36 -> V_80 - V_141 -> V_56 . V_83 ) ;
}
V_141 = F_47 ( V_8 , V_141 ) ;
if ( ! V_141 ) {
F_38 ( V_70 , V_78 ,
( L_113 ) ) ;
V_154 = V_77 ;
goto V_298;
}
F_58 ( V_8 , V_141 , NULL ) ;
V_154 = F_129 ( V_8 , V_141 ) ;
if ( V_154 != V_13 ) {
F_38 ( V_70 , V_78 ,
( L_114 ) ) ;
F_23 ( V_297 ) ;
goto V_298;
}
return V_154 ;
V_298:
V_6 -> V_247 ++ ;
return V_154 ;
}
int F_132 ( struct V_9 * V_296 )
{
int V_154 , V_299 ;
struct V_7 * V_8 = V_296 -> V_17 ;
struct V_54 * V_55 = & V_296 -> V_56 ;
struct V_5 * V_35 = & V_8 -> V_35 ;
struct V_57 * V_58 = & V_8 -> V_59 ;
struct V_155 * V_147 = & V_8 -> V_147 ;
if ( F_63 ( V_147 , V_165 ) &&
V_58 -> V_98 ) {
struct V_9 * V_40 ;
while ( ( V_40 = F_18 ( & V_8 -> V_35 . V_16 ) ) ) {
V_299 = F_131 ( V_8 , V_40 ) ;
if ( V_299 == V_13 )
F_29 ( L_1 , V_41 ) ;
}
}
V_154 = F_130 ( V_8 , V_296 ) ;
if ( V_154 == V_13 ) {
if ( F_63 ( V_147 , V_165 ) &&
! F_39 ( V_55 -> V_72 ) &&
V_55 -> V_68 > 0 &&
( V_55 -> V_86 == 0 ) &&
! F_133 ( V_58 -> V_300 ) &&
! V_58 -> V_98 ) {
F_25 ( V_296 , & V_8 -> V_35 . V_16 ) ;
F_29 ( L_115 , V_41 ) ;
goto exit;
}
V_154 = F_131 ( V_8 , V_296 ) ;
V_35 -> V_301 ++ ;
}
exit:
return V_154 ;
}
void V_25 ( unsigned long V_84 )
{
struct V_7 * V_17 = (struct V_7 * ) V_84 ;
struct V_5 * V_35 = & V_17 -> V_35 ;
T_1 V_302 , V_303 ;
T_2 V_304 = 0 ;
T_2 V_305 = 0 ;
T_1 V_306 = 0 ;
T_1 V_307 = 0 ;
T_2 V_308 = 3 ;
if ( V_17 -> V_35 . V_309 ) {
V_17 -> V_35 . V_310 =
V_17 -> V_35 . V_311 ;
V_17 -> V_35 . V_312 =
( V_313 ) F_134 ( ( T_2 ) V_17 -> V_35 . V_311 ) ;
} else {
if ( V_35 -> V_314 . V_315 == 0 ) {
V_304 =
V_35 -> V_314 . V_316 ;
V_306 =
V_35 -> V_314 . V_317 ;
V_35 -> V_314 . V_315 = 1 ;
}
if ( V_35 -> V_318 . V_315 == 0 ) {
V_305 = V_35 -> V_318 . V_316 ;
V_307 = V_35 -> V_318 . V_317 ;
V_35 -> V_318 . V_315 = 1 ;
}
if ( ! F_63 ( & V_17 -> V_147 , V_319 ) ) {
V_302 = ( V_304 + ( V_308 - 1 ) *
V_35 -> V_310 ) ;
if ( V_302 % V_308 )
V_302 = V_302 / V_308 + 1 ;
else
V_302 = V_302 / V_308 ;
if ( V_302 > 100 )
V_302 = 100 ;
V_303 = ( V_305 + ( V_308 - 1 ) *
V_35 -> V_320 ) ;
if ( V_303 % V_308 )
V_303 = V_303 / V_308 + 1 ;
else
V_303 = V_303 / V_308 ;
if ( V_303 > 100 )
V_303 = 100 ;
V_35 -> V_310 = V_302 ;
V_35 -> V_312 = ( V_313 ) F_134 ( V_302 ) ;
V_35 -> V_320 = V_303 ;
F_29 ( L_116
L_117
L_118 ,
V_41 , V_35 -> V_310 ,
V_35 -> V_312 , V_35 -> V_320 ,
V_306 , V_307
) ;
}
}
F_10 ( V_35 ) ;
}
