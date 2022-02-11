static inline int F_1 ( const struct V_1 * V_2 ,
const struct V_3 * V_4 )
{
return ( * ( short * ) ( & V_4 -> V_5 [ 0 ] ) ==
* ( short * ) ( & V_2 -> V_6 . V_7 [ V_8 ] . V_9 . V_5 [ 0 ] )
&& * ( short * ) ( & V_4 -> V_5 [ 2 ] ) ==
* ( short * ) ( & V_2 -> V_6 . V_7 [ V_8 ] . V_9 . V_5 [ 2 ] )
&& * ( short * ) ( & V_4 -> V_5 [ 4 ] ) ==
* ( short * ) ( & V_2 -> V_6 . V_7 [ V_8 ] . V_9 . V_5 [ 4 ] ) ) ;
}
static inline int F_2 ( const struct V_3 * V_4 )
{
return * ( V_10 * ) ( & V_4 -> V_5 [ 0 ] ) == 0xffff &&
* ( V_10 * ) ( & V_4 -> V_5 [ 2 ] ) == 0xffff &&
* ( V_10 * ) ( & V_4 -> V_5 [ 4 ] ) == 0xffff ;
}
static inline int F_3 ( const struct V_3 * V_4 )
{
return ! ( V_4 -> V_5 [ 0 ] & V_11 ) ;
}
static inline int F_4 ( const struct V_3 * V_12 ,
const struct V_3 * V_13 )
{
return * ( V_10 * ) ( & V_12 -> V_5 [ 0 ] ) == * ( V_10 * ) ( & V_13 -> V_5 [ 0 ] ) &&
* ( V_10 * ) ( & V_12 -> V_5 [ 2 ] ) == * ( V_10 * ) ( & V_13 -> V_5 [ 2 ] ) &&
* ( V_10 * ) ( & V_12 -> V_5 [ 4 ] ) == * ( V_10 * ) ( & V_13 -> V_5 [ 4 ] ) ;
}
void F_5 ( struct V_1 * V_2 )
{
int V_14 ;
V_2 -> V_6 . V_7 [ V_8 ] . V_9 = V_2 -> V_15 . V_16 ;
V_2 -> V_6 . V_17 . V_18 [ 0 ] = 0 ;
V_2 -> V_6 . V_17 . V_18 [ 1 ] = 0 ;
F_6 ( V_2 , & V_2 -> V_6 . V_17 . V_19 ) ;
for ( V_14 = 0 ; V_14 < 6 ; V_14 ++ ) {
V_2 -> V_6 . V_17 . V_19 . V_5 [ V_14 ] =
F_7 ( V_2 -> V_6 . V_17 . V_19 . V_5 [ V_14 ] ) ;
}
V_2 -> V_6 . V_20 [ 0 ] =
V_2 -> V_6 . V_17 . V_19 . V_5 [ 0 ] ;
V_2 -> V_6 . V_20 [ 1 ] =
V_2 -> V_6 . V_17 . V_19 . V_5 [ 1 ] ;
V_2 -> V_6 . V_20 [ 2 ] =
V_2 -> V_6 . V_17 . V_19 . V_5 [ 2 ] ;
V_2 -> V_21 . V_22 = 0 ;
V_2 -> V_6 . V_7 [ V_8 ] . V_23 = V_24 ;
V_2 -> V_6 . V_7 [ V_8 ] . V_25 = FALSE ;
#ifndef F_8
F_9 ( V_2 ) ;
F_10 ( V_2 ) ;
#endif
for ( V_14 = 0 ; V_14 < V_26 ; V_14 ++ )
V_2 -> V_21 . V_27 [ V_14 ] = 0 ;
V_2 -> V_21 . V_28 = 0 ;
V_2 -> V_21 . V_29 = 0 ;
}
void F_11 ( struct V_1 * V_2 )
{
F_12 ( V_2 , & V_2 -> V_21 . V_30 , ( V_31 ) 1000000L ,
F_13 ( V_32 , V_33 ) ) ;
F_14 ( L_1 , 0 , 0 ) ;
}
void F_15 ( struct V_1 * V_2 , int V_34 )
{
V_31 V_35 ;
V_31 time ;
time = F_16 () ;
V_35 = ( ( time - V_2 -> V_21 . V_36 [ V_34 ] ) *
100 ) / V_37 ;
if ( V_2 -> V_15 . V_38 ) {
V_2 -> V_6 . V_7 [ V_34 ] . V_39 += V_35 ;
}
V_2 -> V_21 . V_36 [ V_34 ] = time ;
}
void F_17 ( struct V_1 * V_2 , int V_40 )
{
V_31 time ;
#ifndef F_18
int V_14 ;
#endif
if ( V_2 -> V_21 . V_28 ) {
V_2 -> V_21 . V_28 -- ;
if ( V_2 -> V_21 . V_28 == 0 ) {
F_19 ( V_2 , V_41 , V_42 ) ;
}
}
if ( V_40 == V_43 )
return ;
F_20 ( V_2 ) ;
F_21 ( V_2 ) ;
#ifndef F_8
#ifndef F_22
#ifdef F_23
F_24 ( V_2 ) ;
#endif
#endif
#ifdef F_25
F_26 ( V_2 ) ;
#endif
F_27 ( V_2 , 0 , 0 , 0 ) ;
#endif
time = F_16 () ;
if ( time - V_2 -> V_21 . V_44 >= V_37 * 8 ) {
struct V_45 * V_6 ;
V_31 V_46 ;
V_31 V_47 ;
int V_48 ;
int V_49 ;
struct V_50 * V_51 ;
F_28 ( V_2 ) ;
V_2 -> V_21 . V_44 = time ;
#ifndef F_8
F_29 ( V_2 ) ;
V_6 = V_2 -> V_6 . V_7 ;
V_46 =
( V_6 -> V_52 - V_6 -> V_53 ) +
( V_6 -> V_54 - V_6 -> V_55 ) ;
V_47 =
( V_6 -> V_56 - V_6 -> V_57 ) +
( V_6 -> V_52 - V_6 -> V_53 ) ;
V_6 -> V_58 = F_30 ( V_46 , V_47 ) ;
V_48 =
( ( ! V_6 -> V_59 &&
V_6 -> V_54 != V_6 -> V_55 ) ||
( V_6 -> V_58 >
V_6 -> V_59 ) ) ;
if ( V_48 != V_6 -> V_60 )
F_27 ( V_2 , V_61 ,
V_62 , V_48 ) ;
V_46 =
( V_6 -> V_63 - V_6 -> V_64 ) ;
V_47 =
V_46 +
( V_6 -> V_65 - V_6 -> V_66 ) ;
V_6 -> V_67 = F_30 ( V_46 , V_47 ) ;
V_48 =
( ( ! V_6 -> V_68 &&
V_6 -> V_63 !=
V_6 -> V_64 ) ||
( V_6 -> V_67 >
V_6 -> V_68 ) ) ;
if ( V_48 != V_6 -> V_69 )
F_27 ( V_2 , V_70 ,
V_62 , V_48 ) ;
V_6 -> V_57 = V_6 -> V_56 ;
V_6 -> V_66 = V_6 -> V_65 ;
V_6 -> V_55 = V_6 -> V_54 ;
V_6 -> V_53 = V_6 -> V_52 ;
V_6 -> V_64 = V_6 -> V_63 ;
for ( V_49 = 0 ; V_49 < V_71 ; V_49 ++ ) {
V_51 = & V_2 -> V_72 [ V_49 ] ;
if ( ! V_51 -> V_6 -> V_73 ) {
continue;
}
V_48 = ( V_51 -> V_6 -> V_74 -
V_51 -> V_6 -> V_75 > 5 ) ;
F_27 ( V_2 , V_76 ,
( int ) ( V_77 + V_51 -> V_78 ) , V_48 ) ;
V_51 -> V_6 -> V_75 =
V_51 -> V_6 -> V_74 ;
}
#endif
}
#ifndef F_8
if ( time - V_2 -> V_21 . V_79 >= ( V_31 )
( V_2 -> V_6 . V_80 * V_37 ) ) {
if ( ! V_2 -> V_21 . V_27 [ V_81 ] )
V_2 -> V_21 . V_27 [ V_81 ] = F_31 ( V_2 ) ;
F_32 ( V_2 , & V_82 , V_83 ,
V_2 -> V_21 . V_27 [ V_81 ] , V_84 , 0 ) ;
V_2 -> V_21 . V_79 = time ;
}
if ( V_2 -> V_21 . V_85 &&
time - V_2 -> V_21 . V_85 > 228 * V_37 ) {
F_14 ( L_2 , 0 , 0 ) ;
V_2 -> V_21 . V_85 = 0 ;
if ( ! F_4 ( & V_2 -> V_6 . V_7 [ V_8 ] . V_86 ,
& V_87 ) ) {
V_2 -> V_6 . V_7 [ V_8 ] . V_88 =
V_2 -> V_6 . V_7 [ V_8 ] . V_86 ;
}
V_2 -> V_6 . V_7 [ V_8 ] . V_86 = V_87 ;
V_2 -> V_6 . V_7 [ V_8 ] . V_25 = FALSE ;
F_33 ( V_2 , 0 ) ;
F_27 ( V_2 , V_89 ,
V_62 , 0 ) ;
}
if ( V_2 -> V_21 . V_90 &&
time - V_2 -> V_21 . V_90 > 228 * V_37 ) {
F_14 ( L_3 , 0 , 0 ) ;
V_2 -> V_21 . V_90 = 0 ;
if ( ! F_4 ( & V_2 -> V_6 . V_7 [ V_8 ] . V_91 ,
& V_87 ) ) {
V_2 -> V_6 . V_7 [ V_8 ] . V_92 =
V_2 -> V_6 . V_7 [ V_8 ] . V_91 ;
}
V_2 -> V_6 . V_7 [ V_8 ] . V_91 = V_87 ;
F_27 ( V_2 , V_89 ,
V_62 , 0 ) ;
}
#endif
#ifndef F_18
for ( V_14 = V_8 ; V_14 < V_93 ; V_14 ++ ) {
if ( time - V_2 -> V_21 . V_36 [ V_14 ] > 2 * V_37 ) {
F_15 ( V_2 , V_14 ) ;
}
}
#endif
F_12 ( V_2 , & V_2 -> V_21 . V_30 , ( V_31 ) 1000000L ,
F_13 ( V_32 , V_33 ) ) ;
}
static int F_30 ( V_31 V_46 , V_31 V_47 )
{
if ( ( V_46 << 16L ) < V_46 )
V_46 = 0xffff0000L ;
else
V_46 <<= 16L ;
if ( ! V_47 )
return 0 ;
return ( int ) ( V_46 / V_47 ) ;
}
void F_34 ( struct V_1 * V_2 , T_1 * V_94 , int V_95 )
{
struct V_96 * V_21 ;
int V_97 ;
int V_98 = 0 ;
switch ( F_35 ( V_94 ) ) {
case V_99 :
case V_100 :
case V_101 :
case V_83 :
break ;
default :
F_36 ( V_2 , V_94 ) ;
return ;
}
V_2 -> V_6 . V_7 [ V_8 ] . V_102 ++ ;
V_21 = F_37 ( V_94 , struct V_96 * ) ;
V_97 = ( ( V_95 & V_103 ) != 0 ) ;
F_38 ( V_2 , ( char * ) V_21 , 12 ) ;
if ( F_3 ( & V_21 -> V_104 ) && ! F_1 ( V_2 , & V_21 -> V_104 ) ) {
F_36 ( V_2 , V_94 ) ;
return ;
}
#if 0
if (is_my_addr(smc,&sm->smt_source) && !local) {
smt_free_mbuf(smc,mb) ;
return ;
}
#endif
F_39 ( V_21 , ( int ) V_94 -> V_105 , 1 ) ;
F_14 ( L_4 ,
V_106 [ F_35 ( V_94 ) & 0xf ] , V_21 ) ;
F_14 ( L_5 , V_21 -> V_107 ,
V_108 [ ( V_21 -> V_109 > V_110 ) ? 0 : V_21 -> V_109 ] ) ;
#ifdef F_25
if ( F_35 ( V_94 ) == V_83 && V_21 -> V_109 == V_111 &&
( V_21 -> V_112 == V_113 || V_21 -> V_112 == V_84 ) ) {
V_2 -> V_114 . V_21 = V_21 ;
V_114 ( V_2 , V_115 ) ;
}
#endif
if ( ( V_95 & V_116 ) && F_35 ( V_94 ) == V_83 ) {
F_14 ( L_6 ,
F_40 ( & V_21 -> V_117 ) , 0 ) ;
F_36 ( V_2 , V_94 ) ;
return ;
}
if ( ( ( V_21 -> V_109 == V_118 ) && ( V_21 -> V_119 > V_120 ) ) ||
( ( V_21 -> V_109 != V_118 ) && ( V_21 -> V_119 > V_121 ) ) ) {
F_36 ( V_2 , V_94 ) ;
return ;
}
switch ( V_21 -> V_109 ) {
case V_111 :
case V_122 :
case V_123 :
case V_118 :
if ( V_21 -> V_107 != V_124 )
V_98 = 1 ;
break ;
default :
if ( V_21 -> V_107 != V_125 )
V_98 = 1 ;
break ;
}
if ( V_98 ) {
F_14 ( L_7 ,
V_21 -> V_107 , F_40 ( & V_21 -> V_117 ) ) ;
F_41 ( V_2 , V_94 , F_35 ( V_94 ) , V_126 , V_97 ) ;
F_36 ( V_2 , V_94 ) ;
return ;
}
if ( ( V_21 -> V_119 > V_94 -> V_105 - sizeof( struct V_96 ) ) ||
( ( V_21 -> V_119 & 3 ) && ( V_21 -> V_109 != V_118 ) ) ) {
F_14 ( L_8 , V_21 -> V_119 , 0 ) ;
F_41 ( V_2 , V_94 , F_35 ( V_94 ) , V_127 , V_97 ) ;
F_36 ( V_2 , V_94 ) ;
return ;
}
switch ( V_21 -> V_109 ) {
case V_111 :
if ( F_42 ( V_2 , V_21 , V_128 ) ) {
F_14 ( L_9 , 0 , 0 ) ;
break ;
}
switch ( V_21 -> V_112 ) {
case V_113 :
case V_84 :
if ( ! ( V_95 & V_129 ) && F_35 ( V_94 ) == V_83
&& F_2 ( & V_21 -> V_104 ) ) {
struct V_130 * V_131 ;
if ( ! F_4 (
& V_2 -> V_6 . V_7 [ V_8 ] . V_86 ,
& V_21 -> V_117 ) ) {
F_14 ( L_10 ,
F_40 ( & V_21 -> V_117 ) , 0 ) ;
if ( ! F_4 ( & V_2 -> V_6 . V_7 [ V_8 ] .
V_86 , & V_87 ) ) {
V_2 -> V_6 . V_7 [ V_8 ] . V_88 =
V_2 -> V_6 . V_7 [ V_8 ] . V_86 ;
}
V_2 -> V_6 . V_7 [ V_8 ] . V_86 =
V_21 -> V_117 ;
F_27 ( V_2 ,
V_89 ,
V_62 , 0 ) ;
F_43 ( V_2 , 0 ) ;
}
V_2 -> V_21 . V_85 = F_16 () ;
V_131 = (struct V_130 * )
F_44 ( V_2 , V_21 , V_132 ) ;
if ( V_131 ) {
V_2 -> V_6 . V_7 [ V_8 ] . V_25 =
( V_131 -> V_133 & V_134 ) ?
TRUE : FALSE ;
F_33 ( V_2 , 1 ) ;
}
}
if ( ( V_21 -> V_112 == V_84 ) &&
F_3 ( & V_21 -> V_117 ) &&
( ( ! ( V_95 & V_116 ) && F_35 ( V_94 ) == V_83 ) ||
( F_35 ( V_94 ) != V_83 ) ) ) {
F_14 ( L_11 ,
F_40 ( & V_21 -> V_117 ) , 0 ) ;
F_32 ( V_2 , & V_21 -> V_117 ,
V_99 ,
V_21 -> V_22 ,
V_135 , V_97 ) ;
}
break ;
case V_135 :
F_14 ( L_12 ,
F_40 ( & V_21 -> V_117 ) , 0 ) ;
if ( V_95 & V_116 ) {
V_2 -> V_21 . V_27 [ V_81 ] = 0 ;
F_14 ( L_13 , 0 , 0 ) ;
V_2 -> V_6 . V_7 [ V_8 ] . V_23 =
V_136 ;
V_2 -> V_137 . V_138 = V_136 ;
F_19 ( V_2 , V_139 , V_140 ) ;
V_2 -> V_6 . V_7 [ V_8 ] . V_141 = TRUE ;
F_33 ( V_2 , 1 ) ;
break ;
}
if ( V_21 -> V_22 == V_2 -> V_21 . V_27 [ V_81 ] ) {
V_2 -> V_21 . V_27 [ V_81 ] = 0 ;
if ( ! F_4 (
& V_2 -> V_6 . V_7 [ V_8 ] . V_91 ,
& V_21 -> V_117 ) ) {
F_14 ( L_14 , 0 , 0 ) ;
if ( ! F_4 ( & V_2 -> V_6 . V_7 [ V_8 ] .
V_91 , & V_87 ) ) {
V_2 -> V_6 . V_7 [ V_8 ] . V_92 =
V_2 -> V_6 . V_7 [ V_8 ] . V_91 ;
}
V_2 -> V_6 . V_7 [ V_8 ] . V_91 =
V_21 -> V_117 ;
F_27 ( V_2 ,
V_89 ,
V_62 , 0 ) ;
F_43 ( V_2 , 1 ) ;
}
V_2 -> V_6 . V_7 [ V_8 ] . V_141 = FALSE ;
F_33 ( V_2 , 1 ) ;
V_2 -> V_21 . V_90 = F_16 () ;
V_2 -> V_6 . V_7 [ V_8 ] . V_23 =
V_142 ;
if ( V_2 -> V_137 . V_138 != V_142 ) {
V_2 -> V_137 . V_138 = V_142 ;
F_19 ( V_2 , V_139 , V_140 ) ;
}
}
else if ( V_21 -> V_22 ==
V_2 -> V_21 . V_27 [ V_143 ] ) {
F_14 ( L_15 , 0 , 0 ) ;
}
else {
F_14 ( L_16 ,
V_2 -> V_21 . V_27 [ V_81 ] , V_21 -> V_22 ) ;
}
break ;
default :
V_98 = 2 ;
break ;
}
break ;
case V_122 :
if ( V_21 -> V_112 != V_84 )
break ;
F_14 ( L_17 ,
F_40 ( & V_21 -> V_117 ) , 0 ) ;
F_45 ( V_2 , & V_21 -> V_117 , V_21 -> V_22 , V_97 ) ;
break ;
case V_123 :
if ( V_21 -> V_112 != V_84 )
break ;
F_14 ( L_18 ,
F_40 ( & V_21 -> V_117 ) , 0 ) ;
F_46 ( V_2 , & V_21 -> V_117 , V_21 -> V_22 , V_97 ) ;
break ;
case V_118 :
switch ( V_21 -> V_112 ) {
case V_135 :
V_2 -> V_6 . V_144 . V_145 ++ ;
F_14 ( L_19 ,
F_40 ( & V_21 -> V_117 ) , 0 ) ;
if ( F_44 ( V_2 , V_21 , V_146 ) == NULL ) {
F_14 ( L_20 , 0 , 0 ) ;
break ;
}
if ( V_21 -> V_22 == V_2 -> V_21 . V_27 [ V_147 ] ) {
F_14 ( L_21 , 0 , 0 ) ;
}
else if ( V_21 -> V_22 == V_2 -> V_21 . V_27 [ V_148 ] ) {
F_14 ( L_22 , 0 , 0 ) ;
}
else if ( V_21 -> V_22 == V_2 -> V_21 . V_27 [ V_149 ] ) {
F_14 ( L_23 , 0 , 0 ) ;
}
else {
F_14 ( L_16 ,
V_2 -> V_21 . V_27 [ V_147 ] ,
V_21 -> V_22 ) ;
}
break ;
case V_84 :
V_2 -> V_6 . V_144 . V_150 ++ ;
{
if ( V_21 -> V_119 && ! F_44 ( V_2 , V_21 , V_146 ) ) {
F_14 ( L_24 , 0 , 0 ) ;
F_41 ( V_2 , V_94 , F_35 ( V_94 ) , V_127 ,
V_97 ) ;
break ;
}
F_14 ( L_25 ,
F_40 ( & V_21 -> V_117 ) , 0 ) ;
V_21 -> V_104 = V_21 -> V_117 ;
V_21 -> V_112 = V_135 ;
F_47 ( V_2 , V_21 , L_26 ) ;
V_2 -> V_6 . V_144 . V_151 ++ ;
F_48 ( V_2 , V_94 , V_99 , V_97 ) ;
return ;
}
default :
V_98 = 1 ;
break ;
}
break ;
#ifndef F_22
case V_152 :
#ifdef F_23
F_49 ( 2 , L_27 , 0 , 0 ) ;
V_95 = F_50 ( V_2 , V_94 , V_21 , V_95 ) ;
#endif
#ifdef F_25
F_51 ( 2 , L_28 , 0 , 0 ) ;
F_52 ( V_2 , V_21 , V_95 ) ;
#endif
break ;
case V_153 :
V_2 -> V_6 . V_144 . V_154 ++ ;
break ;
case V_155 :
if ( V_21 -> V_112 == V_84 ) {
F_14 ( L_29 , 0 , 0 ) ;
F_41 ( V_2 , V_94 , F_35 ( V_94 ) , V_156 , V_97 ) ;
}
break ;
case V_157 :
case V_158 :
if ( V_21 -> V_112 != V_84 )
break ;
if ( V_21 -> V_109 == V_157 )
V_2 -> V_6 . V_144 . V_159 ++ ;
else
V_2 -> V_6 . V_144 . V_160 ++ ;
if ( ( V_21 -> V_109 == V_158 ) &&
! F_3 ( & V_21 -> V_104 ) ) {
F_14 ( L_30 , 0 , 0 ) ;
break ;
}
F_53 ( V_2 , V_94 , V_97 ) ;
break ;
case V_161 :
F_47 ( V_2 , V_21 , L_31 ) ;
break ;
default :
if ( V_21 -> V_112 != V_84 )
break ;
F_14 ( L_32 ,
V_21 -> V_109 , F_40 ( & V_21 -> V_117 ) ) ;
F_41 ( V_2 , V_94 , F_35 ( V_94 ) , V_156 , V_97 ) ;
break ;
#endif
}
if ( V_98 ) {
F_14 ( L_33 ,
V_98 , 0 ) ;
}
F_36 ( V_2 , V_94 ) ;
}
static void F_33 ( struct V_1 * V_2 , int V_162 )
{
int V_48 ;
V_48 = ( V_2 -> V_6 . V_7 [ V_8 ] . V_25 |
V_2 -> V_6 . V_7 [ V_8 ] . V_141 ) != 0 ;
if ( V_162 && ( V_48 != V_2 -> V_6 . V_7 [ V_8 ] . V_163 ) )
F_27 ( V_2 , V_164 , V_62 , V_48 ) ;
else
V_2 -> V_6 . V_7 [ V_8 ] . V_163 = V_48 ;
}
void F_48 ( struct V_1 * V_2 , T_1 * V_94 , int V_165 , int V_97 )
{
struct V_96 * V_21 ;
if ( ! V_2 -> V_137 . V_166 && ! V_97 ) {
F_36 ( V_2 , V_94 ) ;
return ;
}
V_21 = F_37 ( V_94 , struct V_96 * ) ;
V_21 -> V_117 = V_2 -> V_6 . V_7 [ V_8 ] . V_9 ;
V_21 -> V_167 = V_2 -> V_6 . V_17 ;
F_39 ( V_21 , ( int ) V_94 -> V_105 , 0 ) ;
F_38 ( V_2 , ( char * ) V_21 , 12 ) ;
V_2 -> V_6 . V_7 [ V_8 ] . V_168 ++ ;
F_54 ( V_2 , V_94 , V_97 ? V_101 : V_165 ) ;
}
static void F_41 ( struct V_1 * V_2 , T_1 * V_169 , int V_165 , int V_170 ,
int V_97 )
{
T_1 * V_94 ;
struct V_96 * V_21 ;
struct V_171 * V_172 ;
int V_173 ;
int V_174 ;
V_21 = F_37 ( V_169 , struct V_96 * ) ;
if ( V_21 -> V_112 != V_84 )
return ;
F_14 ( L_34 ,
F_40 ( & V_21 -> V_117 ) , V_170 ) ;
V_174 = V_169 -> V_105 ;
if ( ! ( V_94 = F_55 ( V_2 , V_153 , V_135 , sizeof( struct V_171 ) ) ) )
return ;
V_172 = F_37 ( V_94 , struct V_171 * ) ;
V_172 -> V_175 . V_22 = V_21 -> V_22 ;
V_172 -> V_175 . V_104 = V_21 -> V_117 ;
V_172 -> V_170 . V_176 . V_177 = V_178 ;
V_172 -> V_170 . V_176 . V_179 = sizeof( struct V_180 ) - V_181 ;
V_172 -> V_170 . V_182 = V_170 ;
V_172 -> V_183 . V_176 . V_177 = V_184 ;
V_172 -> V_183 . V_176 . V_179 = sizeof( struct V_185 ) - V_181 ;
V_172 -> V_183 . V_186 = 0 ;
V_172 -> V_183 . V_187 = 1 ;
V_172 -> V_183 . V_188 = 1 ;
V_172 -> V_183 . V_189 [ 0 ] = V_125 ;
V_172 -> V_183 . V_190 = 0 ;
if ( ( unsigned int ) V_174 <= V_121 - sizeof( * V_172 ) +
2 * sizeof( struct V_96 ) )
V_173 = V_174 ;
else
V_173 = V_121 - sizeof( * V_172 ) +
2 * sizeof( struct V_96 ) ;
V_173 &= ~ 3 ;
V_172 -> V_191 . V_176 . V_177 = V_192 ;
V_172 -> V_191 . V_176 . V_179 = V_173 + 4 ;
V_172 -> V_191 . V_193 = V_165 ;
F_39 ( V_21 , V_174 , 0 ) ;
memcpy ( ( char * ) & V_172 -> V_191 . V_194 , ( char * ) V_21 , V_173 ) ;
V_173 -= sizeof( struct V_96 ) ;
V_94 -> V_105 += V_173 ;
V_172 -> V_175 . V_119 += V_173 ;
F_47 ( V_2 , (struct V_96 * ) V_172 , L_35 ) ;
V_2 -> V_6 . V_144 . V_195 ++ ;
F_48 ( V_2 , V_94 , V_99 , V_97 ) ;
}
static void F_32 ( struct V_1 * V_2 , const struct V_3 * V_196 ,
int V_165 , V_31 V_197 , int type , int V_97 )
{
struct V_198 * V_199 ;
T_1 * V_94 ;
if ( ! ( V_94 = F_55 ( V_2 , V_111 , type , sizeof( struct V_198 ) ) ) )
return ;
V_199 = F_37 ( V_94 , struct V_198 * ) ;
F_56 ( V_2 , & V_199 -> V_200 ) ;
F_57 ( V_2 , & V_199 -> V_201 ) ;
F_58 ( V_2 , & V_199 -> V_202 ) ;
#ifdef F_59
F_60 ( V_2 , & V_199 -> V_203 ) ;
#endif
V_199 -> V_175 . V_104 = * V_196 ;
V_199 -> V_175 . V_22 = V_197 ;
F_47 ( V_2 , (struct V_96 * ) V_199 , L_36 ) ;
F_48 ( V_2 , V_94 , V_165 , V_97 ) ;
}
static void F_61 ( struct V_1 * V_2 , struct V_3 * V_196 )
{
V_2 -> V_21 . V_27 [ V_143 ] = F_31 ( V_2 ) ;
F_32 ( V_2 , V_196 , V_99 , V_2 -> V_21 . V_27 [ V_143 ] ,
V_84 , 0 ) ;
}
static void F_62 ( struct V_1 * V_2 , struct V_3 * V_196 ,
int V_173 )
{
V_2 -> V_21 . V_27 [ V_147 ] = F_31 ( V_2 ) ;
F_63 ( V_2 , V_196 , V_99 , V_2 -> V_21 . V_27 [ V_147 ] ,
V_84 , V_173 ) ;
}
static void F_43 ( struct V_1 * V_2 , int V_204 )
{
V_31 V_197 ;
V_2 -> V_21 . V_27 [ V_204 ? V_149 : V_148 ] =
V_197 = F_31 ( V_2 ) ;
F_63 ( V_2 , V_204 ?
& V_2 -> V_6 . V_7 [ V_8 ] . V_91 :
& V_2 -> V_6 . V_7 [ V_8 ] . V_86 ,
V_99 , V_197 , V_84 , ( V_205 & ~ 3 ) - 8 ) ;
}
static void F_63 ( struct V_1 * V_2 , struct V_3 * V_196 , int V_165 ,
V_31 V_197 , int type , int V_173 )
{
struct V_206 * V_207 ;
T_1 * V_94 ;
if ( ! ( V_94 = F_55 ( V_2 , V_118 , type , V_208 + V_173 ) ) )
return ;
V_207 = F_37 ( V_94 , struct V_206 * ) ;
F_64 ( V_2 , & V_207 -> V_209 , V_197 , V_173 ) ;
V_207 -> V_175 . V_104 = * V_196 ;
V_207 -> V_175 . V_22 = V_197 ;
V_2 -> V_6 . V_144 . V_210 ++ ;
F_48 ( V_2 , V_94 , V_165 , 0 ) ;
}
static void F_45 ( struct V_1 * V_2 , struct V_3 * V_196 ,
V_31 V_197 , int V_97 )
{
struct V_211 * V_212 ;
T_1 * V_94 ;
int V_173 ;
if ( ! ( V_94 = F_55 ( V_2 , V_122 , V_135 ,
V_213 ) ) )
return ;
V_212 = F_37 ( V_94 , struct V_211 * ) ;
F_65 ( V_2 , & V_212 -> V_214 ) ;
F_57 ( V_2 , & V_212 -> V_201 ) ;
F_66 ( V_2 , & V_212 -> V_183 ) ;
F_58 ( V_2 , & V_212 -> V_202 ) ;
F_67 ( V_2 , & V_212 -> V_215 ) ;
F_68 ( V_2 , & V_212 -> V_216 ) ;
F_69 ( V_2 , & V_212 -> V_217 ) ;
F_70 ( V_2 , & V_212 -> V_218 ) ;
V_173 = F_71 ( V_2 , & V_212 -> V_219 ) ;
V_212 -> V_175 . V_104 = * V_196 ;
V_212 -> V_175 . V_22 = V_197 ;
F_72 ( V_94 , V_173 ) ;
F_47 ( V_2 , (struct V_96 * ) V_212 , L_37 ) ;
F_48 ( V_2 , V_94 , V_99 , V_97 ) ;
}
static void F_46 ( struct V_1 * V_2 , struct V_3 * V_196 ,
V_31 V_197 , int V_97 )
{
struct V_220 * V_212 ;
T_1 * V_94 ;
int V_221 ;
int V_14 ;
V_221 = V_71 ;
#ifndef F_73
if ( V_2 -> V_222 . V_223 == V_224 )
V_221 = 1 ;
#endif
if ( ! ( V_94 = F_55 ( V_2 , V_123 , V_135 ,
V_225 + V_221 * sizeof( struct V_226 ) ) ) )
return ;
V_212 = F_37 ( V_94 , struct V_220 * ) ;
F_65 ( V_2 , & V_212 -> V_214 ) ;
F_74 ( V_2 , & V_212 -> V_227 ) ;
F_75 ( V_2 , & V_212 -> V_228 ) ;
F_76 ( V_2 , & V_212 -> V_229 ) ;
F_77 ( V_2 , & V_212 -> V_230 ) ;
F_78 ( V_2 , & V_212 -> V_231 ) ;
F_70 ( V_2 , & V_212 -> V_218 ) ;
if ( V_221 == 1 ) {
F_79 ( V_2 , V_212 -> V_232 , V_233 ) ;
}
else {
for ( V_14 = 0 ; V_14 < V_221 ; V_14 ++ ) {
F_79 ( V_2 , & V_212 -> V_232 [ V_14 ] , V_14 ) ;
}
}
V_212 -> V_175 . V_104 = * V_196 ;
V_212 -> V_175 . V_22 = V_197 ;
F_47 ( V_2 , (struct V_96 * ) V_212 , L_38 ) ;
F_48 ( V_2 , V_94 , V_99 , V_97 ) ;
}
T_1 * F_55 ( struct V_1 * V_2 , int V_234 , int type ,
int V_235 )
{
T_1 * V_94 ;
struct V_96 * V_175 ;
#if 0
if (!smc->r.sm_ma_avail) {
return 0;
}
#endif
if ( ! ( V_94 = F_80 ( V_2 ) ) )
return V_94 ;
V_94 -> V_105 = V_235 ;
V_175 = F_37 ( V_94 , struct V_96 * ) ;
V_175 -> V_104 = V_82 ;
V_175 -> V_109 = V_234 ;
V_175 -> V_112 = type ;
switch ( V_234 ) {
case V_111 :
case V_122 :
case V_123 :
case V_118 :
V_175 -> V_107 = V_124 ;
break ;
default :
V_175 -> V_107 = V_125 ;
break ;
}
V_175 -> V_22 = F_31 ( V_2 ) ;
V_175 -> V_236 = 0 ;
V_175 -> V_119 = V_235 - sizeof( struct V_96 ) ;
return V_94 ;
}
static void F_72 ( T_1 * V_94 , int V_173 )
{
struct V_96 * V_175 ;
V_175 = F_37 ( V_94 , struct V_96 * ) ;
V_175 -> V_119 += V_173 ;
V_94 -> V_105 += V_173 ;
}
static void F_56 ( struct V_1 * V_2 , struct V_237 * V_200 )
{
F_81 ( V_200 , V_238 ) ;
V_200 -> V_239 = 0 ;
V_200 -> V_240 = V_2 -> V_6 . V_7 [ V_8 ] . V_86 ;
}
static void F_57 ( struct V_1 * V_2 , struct V_241 * V_201 )
{
F_81 ( V_201 , V_242 ) ;
V_201 -> V_243 = V_2 -> V_6 . V_244 ;
V_201 -> V_245 = V_2 -> V_6 . V_246 ;
V_201 -> V_247 = V_93 ;
#ifdef F_73
V_201 -> V_248 = V_249 ;
#else
V_201 -> V_248 = V_250 ;
#endif
}
static void F_58 ( struct V_1 * V_2 , struct V_130 * V_202 )
{
int V_251 ;
int V_252 ;
F_81 ( V_202 , V_132 ) ;
V_202 -> V_253 = 0 ;
V_251 = 0 ;
if ( V_2 -> V_6 . V_254 ) {
V_251 |= V_255 ;
}
#ifdef F_73
if ( F_82 ( V_2 ) ) {
V_251 |= V_256 ;
}
#endif
if ( ( V_252 = F_83 ( V_2 ) ) & 1 ) {
V_251 |= V_257 ;
}
if ( V_252 & 2 ) {
V_251 |= V_258 ;
}
#ifdef F_84
V_251 |= V_259 ;
#endif
if ( F_85 ( V_2 ) )
V_251 |= V_260 ;
if ( V_2 -> V_6 . V_5 [ 0 ] . V_261 != 0 )
V_251 |= V_262 ;
V_202 -> V_263 = V_251 ;
V_202 -> V_133 =
( ( V_2 -> V_6 . V_7 [ V_8 ] . V_141 ? V_134 : 0 ) |
( V_2 -> V_6 . V_7 [ V_8 ] . V_25 ? V_264 : 0 ) ) ;
}
static void F_65 ( struct V_1 * V_2 , struct V_265 * V_214 )
{
F_81 ( V_214 , V_266 ) ;
F_86 ( V_2 , V_214 -> V_267 ) ;
}
void F_86 ( struct V_1 * V_2 , T_2 * V_268 )
{
V_31 time ;
V_31 V_269 ;
V_269 = F_16 () ;
time = V_269 * 100 ;
time /= V_37 ;
V_268 [ 0 ] = 0 ;
V_268 [ 1 ] = ( T_2 ) ( ( time >> ( 8 + 8 + 8 + 8 - 1 ) ) & 1 ) ;
V_268 [ 2 ] = ( T_2 ) ( time >> ( 8 + 8 + 8 - 1 ) ) ;
V_268 [ 3 ] = ( T_2 ) ( time >> ( 8 + 8 - 1 ) ) ;
V_268 [ 4 ] = ( T_2 ) ( time >> ( 8 - 1 ) ) ;
V_268 [ 5 ] = ( T_2 ) ( time << 1 ) ;
V_268 [ 6 ] = ( T_2 ) ( V_2 -> V_21 . V_29 >> 8 ) ;
V_268 [ 7 ] = ( T_2 ) V_2 -> V_21 . V_29 ;
if ( V_269 != V_2 -> V_21 . V_270 ) {
V_2 -> V_21 . V_29 = 0 ;
}
V_2 -> V_21 . V_29 ++ ;
V_2 -> V_21 . V_270 = V_269 ;
}
static void F_67 ( struct V_1 * V_2 , struct V_271 * V_215 )
{
int V_14 ;
const T_2 * V_272 ;
V_10 V_273 ;
V_10 V_274 ;
static const T_2 V_275 [ 16 ] = {
0 , 7 , 5 , 3 , 8 , 1 , 6 , 4 , 9 , 10 , 2 , 11 , 12 , 13 , 14 , 15
} ;
F_81 ( V_215 , V_276 ) ;
V_274 = 0 ;
V_273 = V_2 -> V_6 . V_277 ;
for ( V_14 = 0 , V_272 = V_275 ; V_14 < 16 ; V_14 ++ ) {
if ( V_273 & 1 )
V_274 |= ( 1 << * V_272 ) ;
V_273 >>= 1 ;
V_272 ++ ;
}
V_215 -> V_278 = V_2 -> V_6 . V_279 ;
V_215 -> V_280 = V_274 ;
}
static void F_68 ( struct V_1 * V_2 , struct V_281 * V_216 )
{
F_81 ( V_216 , V_282 ) ;
V_216 -> V_283 = F_87 ( V_2 , 0 ) ;
V_216 -> V_284 = 10 ;
if ( V_2 -> V_222 . V_223 == V_285 ) {
V_216 -> V_286 = F_87 ( V_2 , 1 ) ;
V_216 -> V_287 = 10 ;
}
else {
V_216 -> V_286 = 0 ;
V_216 -> V_287 = 0 ;
}
}
static void F_69 ( struct V_1 * V_2 , struct V_288 * V_217 )
{
F_81 ( V_217 , V_289 ) ;
V_217 -> V_290 = V_62 ;
V_217 -> V_291 = V_34 ( V_2 , 1 ) ;
V_217 -> V_292 = V_2 -> V_6 . V_7 [ V_8 ] . V_86 ;
V_217 -> V_293 = V_2 -> V_6 . V_7 [ V_8 ] . V_91 ;
}
static int F_71 ( struct V_1 * V_2 , struct V_294 * V_219 )
{
F_88 ( int , type ) ;
F_88 ( int , V_202 ) ;
F_88 ( int , V_295 ) ;
F_88 ( int , V_296 ) ;
int V_173 ;
int V_268 ;
int V_297 ;
struct V_298 * V_51 ;
struct V_299 * V_300 ;
V_173 = V_181 +
sizeof( struct V_299 ) * V_93 +
sizeof( struct V_298 ) * V_301 ;
V_219 -> V_176 . V_177 = V_302 ;
V_219 -> V_176 . V_179 = V_173 - V_181 ;
for ( V_268 = 0 , V_51 = V_219 -> V_303 ; V_268 < V_301 ; V_268 ++ , V_51 ++ ) {
V_297 = V_268 ;
#ifndef F_73
if ( V_2 -> V_222 . V_223 == V_224 )
V_297 = V_233 ;
#endif
F_89 ( V_2 , V_297 , & type , & V_202 , & V_295 , & V_296 ) ;
#ifdef F_90
V_51 -> V_304 = F_91 ( ( V_10 ) V_268 + V_77 ) ;
#else
V_51 -> V_304 = V_268 + V_77 ;
#endif
V_51 -> V_305 = type ;
V_51 -> V_306 = V_202 ;
V_51 -> V_307 = V_295 ;
V_51 -> V_308 = V_296 ;
V_51 -> V_309 = F_92 ( V_2 , V_268 ) ;
}
V_300 = (struct V_299 * ) V_51 ;
V_300 -> V_310 = V_2 -> V_6 . V_7 [ V_8 ] . V_9 ;
V_300 -> V_311 = F_93 ( V_2 , 1 ) ;
return V_173 ;
}
static void F_74 ( struct V_1 * V_2 , struct V_312 * V_131 )
{
F_81 ( V_131 , V_313 ) ;
V_131 -> V_314 = V_62 ;
V_131 -> V_315 = V_34 ( V_2 , 1 ) ;
F_29 ( V_2 ) ;
V_131 -> V_316 = V_2 -> V_6 . V_7 [ V_8 ] . V_317 ;
V_131 -> V_318 = V_2 -> V_6 . V_7 [ V_8 ] . V_319 ;
V_131 -> V_320 = V_2 -> V_6 . V_7 [ V_8 ] . V_321 ;
V_131 -> V_322 = V_2 -> V_6 . V_7 [ V_8 ] . V_323 ;
V_131 -> V_324 = V_2 -> V_6 . V_7 [ V_8 ] . V_325 ;
V_131 -> V_326 = V_2 -> V_6 . V_5 [ V_327 ] . V_261 ;
V_131 -> V_328 = V_2 -> V_6 . V_7 [ V_8 ] . V_56 ;
V_131 -> V_329 = V_2 -> V_6 . V_7 [ V_8 ] . V_54 ;
V_131 -> V_330 = V_2 -> V_6 . V_7 [ V_8 ] . V_52 ;
}
static void F_79 ( struct V_1 * V_2 , struct V_226 * V_232 , int V_51 )
{
struct V_331 * V_6 ;
V_6 = V_2 -> V_72 [ V_51 ] . V_6 ;
F_81 ( V_232 , V_332 ) ;
V_232 -> V_333 = V_51 + V_77 ;
V_232 -> V_334 = F_87 ( V_2 , V_51 ) ;
V_232 -> V_335 = 0 ;
V_232 -> V_336 = V_6 -> V_337 ;
V_232 -> V_338 = V_6 -> V_339 ;
V_232 -> V_340 = V_6 -> V_341 ;
V_232 -> V_342 = V_6 -> V_343 ;
V_232 -> V_344 = V_6 -> V_345 ;
}
static void F_66 ( struct V_1 * V_2 , struct V_185 * V_346 )
{
F_94 ( V_2 ) ;
F_81 ( V_346 , V_184 ) ;
V_346 -> V_186 = 0 ;
V_346 -> V_187 = 1 ;
V_346 -> V_188 = 1 ;
V_346 -> V_189 [ 0 ] = V_125 ;
V_346 -> V_190 = 0 ;
}
static void F_60 ( struct V_1 * V_2 , struct V_347 * V_203 )
{
F_94 ( V_2 ) ;
F_81 ( V_203 , V_348 ) ;
V_203 -> V_349 = 0 ;
V_203 -> V_350 = V_62 ;
V_203 -> V_351 = 0 ;
V_203 -> V_352 = V_353 ;
#ifdef F_90
V_203 -> V_350 = F_91 ( V_62 ) ;
V_203 -> V_352 = F_91 ( V_353 ) ;
#endif
}
static void F_75 ( struct V_1 * V_2 , struct V_354 * V_228 )
{
F_81 ( V_228 , V_355 ) ;
V_228 -> V_356 = V_62 ;
V_228 -> V_357 = V_34 ( V_2 , 1 ) ;
V_228 -> V_358 = V_2 -> V_6 . V_7 [ V_8 ] . V_65 ;
V_228 -> V_359 = V_2 -> V_6 . V_7 [ V_8 ] . V_360 ;
}
static void F_76 ( struct V_1 * V_2 , struct V_361 * V_229 )
{
F_81 ( V_229 , V_362 ) ;
V_229 -> V_363 = V_62 ;
V_229 -> V_364 = V_34 ( V_2 , 1 ) ;
V_229 -> V_365 = V_2 -> V_6 . V_7 [ V_8 ] . V_63 ;
}
static void F_77 ( struct V_1 * V_2 ,
struct V_366 * V_230 )
{
F_81 ( V_230 , V_367 ) ;
memcpy ( ( char * ) V_230 -> V_368 ,
( char * ) V_2 -> V_6 . V_20 ,
sizeof( V_230 -> V_368 ) ) ;
}
static void F_78 ( struct V_1 * V_2 , struct V_369 * V_231 )
{
F_81 ( V_231 , V_370 ) ;
memcpy ( ( char * ) V_231 -> V_371 ,
( char * ) V_2 -> V_6 . V_372 ,
sizeof( V_231 -> V_371 ) ) ;
}
static void F_70 ( struct V_1 * V_2 , struct V_373 * V_218 )
{
F_94 ( V_2 ) ;
F_81 ( V_218 , V_374 ) ;
V_218 -> V_35 = V_2 -> V_6 . V_375 . V_35 ;
memcpy ( ( char * ) V_218 -> V_376 ,
( char * ) V_2 -> V_6 . V_375 . V_376 , 8 ) ;
}
static void F_64 ( struct V_1 * V_2 , struct V_377 * V_378 , V_31 V_379 ,
int V_173 )
{
T_2 * V_268 ;
F_94 ( V_2 ) ;
F_81 ( V_378 , V_146 ) ;
V_378 -> V_176 . V_179 = V_173 ;
for ( V_268 = V_378 -> V_380 ; V_173 ; V_173 -- ) {
* V_268 ++ = ( T_2 ) V_379 ;
V_379 += 13 ;
}
}
static void F_9 ( struct V_1 * V_2 )
{
V_2 -> V_6 . V_7 [ V_8 ] . V_86 = V_87 ;
V_2 -> V_6 . V_7 [ V_8 ] . V_91 = V_87 ;
}
static void F_10 ( struct V_1 * V_2 )
{
V_2 -> V_6 . V_7 [ V_8 ] . V_88 = V_87 ;
V_2 -> V_6 . V_7 [ V_8 ] . V_92 = V_87 ;
}
V_31 F_31 ( struct V_1 * V_2 )
{
V_31 V_197 ;
while ( ( V_197 = ++ ( V_2 -> V_21 . V_22 ) ^ V_381 ) == 0 )
;
return V_197 & 0x3fffffffL ;
}
int F_42 ( struct V_1 * V_2 , struct V_96 * V_21 ,
const V_10 V_382 [] )
{
const V_10 * V_268 = V_382 ;
while ( * V_268 ) {
if ( ! F_44 ( V_2 , V_21 , ( int ) * V_268 ) ) {
F_14 ( L_39 , * V_268 , 0 ) ;
return - 1 ;
}
V_268 ++ ;
}
return 0 ;
}
void * F_44 ( struct V_1 * V_2 , struct V_96 * V_21 , int V_176 )
{
char * V_268 ;
int V_173 ;
int V_383 ;
void * V_384 = NULL ;
F_94 ( V_2 ) ;
V_173 = V_21 -> V_119 ;
V_268 = ( char * ) ( V_21 + 1 ) ;
while ( V_173 > 0 ) {
if ( ( (struct V_385 * ) V_268 ) -> V_177 == V_176 )
V_384 = ( void * ) V_268 ;
V_383 = ( (struct V_385 * ) V_268 ) -> V_179 + V_181 ;
V_268 += V_383 ;
V_173 -= V_383 ;
if ( V_173 < 0 ) {
F_14 ( L_40 , V_383 , 0 ) ;
return NULL ;
}
if ( ( V_383 & 3 ) && ( V_176 != V_146 ) ) {
F_14 ( L_41 , V_383 , 0 ) ;
return NULL ;
}
if ( V_384 )
return V_384 ;
}
return NULL ;
}
char * F_40 ( struct V_3 * V_4 )
{
int V_14 ;
static char string [ 6 * 3 ] = L_42 ;
for ( V_14 = 0 ; V_14 < 6 ; V_14 ++ ) {
string [ V_14 * 3 ] = F_95 ( V_4 -> V_5 [ V_14 ] ) ;
string [ V_14 * 3 + 1 ] = F_96 ( V_4 -> V_5 [ V_14 ] ) ;
string [ V_14 * 3 + 2 ] = ':' ;
}
string [ 5 * 3 + 2 ] = 0 ;
return string ;
}
static int V_34 ( struct V_1 * V_2 , int V_296 )
{
F_94 ( V_296 ) ;
#ifdef F_73
F_94 ( V_2 ) ;
return V_71 + 1 ;
#else
return ( V_2 -> V_222 . V_223 == V_224 ) ? 2 : 3 ;
#endif
}
static int F_87 ( struct V_1 * V_2 , int V_51 )
{
F_94 ( V_2 ) ;
return V_51 + 1 ;
}
static int F_93 ( struct V_1 * V_2 , int V_296 )
{
#ifdef F_73
F_94 ( V_2 ) ;
F_94 ( V_296 ) ;
return F_97 ( V_2 , F_98 ( V_2 , V_386 ) ) ;
#else
F_94 ( V_296 ) ;
switch ( V_2 -> V_6 . V_387 ) {
case V_388 :
case V_389 :
case V_390 :
return 1 ;
case V_391 :
case V_392 :
return 2 ;
}
return V_2 -> V_222 . V_223 == V_224 ? 2 : 3 ;
#endif
}
static int F_92 ( struct V_1 * V_2 , int V_51 )
{
#ifdef F_73
return F_97 ( V_2 , F_98 ( V_2 , F_99 ( V_51 ) ) ) ;
#else
switch ( V_2 -> V_6 . V_387 ) {
case V_388 :
return V_51 == V_393 ? 3 : 2 ;
case V_391 :
return V_51 == V_393 ? 1 : 3 ;
case V_392 :
return V_51 == V_393 ? 3 : 1 ;
case V_389 :
return V_51 == V_393 ? 2 : 3 ;
case V_390 :
return 2 ;
}
return V_51 ;
#endif
}
static int F_97 ( struct V_1 * V_2 , int V_394 )
{
if ( V_394 == V_386 )
return V_34 ( V_2 , 1 ) ;
else
return F_87 ( V_2 , V_394 - F_99 ( 0 ) ) ;
}
static int F_91 ( V_10 V_222 )
{
return ( ( V_222 >> 8 ) & 0xff ) | ( ( V_222 & 0xff ) << 8 ) ;
}
void F_39 ( struct V_96 * V_21 , int V_173 , int V_395 )
{
struct V_385 * V_396 ;
const struct V_397 * V_398 ;
char * V_268 ;
int V_383 ;
int type ;
int V_14 ;
F_100 ( ( char * ) V_21 , V_399 , V_173 ) ;
V_173 -= sizeof( struct V_96 ) ;
V_268 = ( char * ) ( V_21 + 1 ) ;
while ( V_173 > 0 ) {
V_396 = (struct V_385 * ) V_268 ;
V_383 = V_396 -> V_179 ;
type = V_396 -> V_177 ;
V_396 -> V_177 = F_91 ( V_396 -> V_177 ) ;
V_396 -> V_179 = F_91 ( V_396 -> V_179 ) ;
if ( V_395 ) {
V_383 = V_396 -> V_179 ;
type = V_396 -> V_177 ;
}
if ( V_383 < 0 )
break ;
V_383 += V_181 ;
for ( V_14 = V_400 , V_398 = V_397 ; V_14 ; V_14 -- , V_398 ++ ) {
if ( V_398 -> V_401 == type )
break ;
}
if ( V_14 && V_398 -> V_402 ) {
F_100 ( V_268 + V_181 , V_398 -> V_402 , V_173 ) ;
}
V_173 -= V_383 ;
V_268 += V_383 ;
}
}
static void F_100 ( char * V_403 , const char * V_404 , int V_173 )
{
const char * V_405 = NULL ;
int V_406 ;
while ( V_173 > 0 && * V_404 ) {
switch ( * V_404 ) {
case '[' :
V_405 = V_404 ;
break ;
case ']' :
V_404 = V_405 ;
break ;
case '1' :
case '2' :
case '3' :
case '4' :
case '5' :
case '6' :
case '7' :
case '8' :
case '9' :
V_403 += * V_404 - '0' ;
V_173 -= * V_404 - '0' ;
break ;
case 'c' :
V_403 ++ ;
V_173 -- ;
break ;
case 's' :
V_406 = V_403 [ 0 ] ;
V_403 [ 0 ] = V_403 [ 1 ] ;
V_403 [ 1 ] = V_406 ;
V_403 += 2 ;
V_173 -= 2 ;
break ;
case 'l' :
V_406 = V_403 [ 0 ] ;
V_403 [ 0 ] = V_403 [ 3 ] ;
V_403 [ 3 ] = V_406 ;
V_406 = V_403 [ 1 ] ;
V_403 [ 1 ] = V_403 [ 2 ] ;
V_403 [ 2 ] = V_406 ;
V_403 += 4 ;
V_173 -= 4 ;
break ;
}
V_404 ++ ;
}
}
void F_39 ( struct V_96 * V_21 , int V_173 , int V_395 )
{
F_94 ( V_21 ) ;
F_94 ( V_173 ) ;
F_94 ( V_395 ) ;
}
int F_101 ( struct V_1 * V_2 , int V_234 , int V_407 , int V_408 )
{
int V_40 ;
int V_49 ;
F_14 ( L_43 , V_234 , V_407 ) ;
switch( V_234 ) {
case V_409 :
switch( V_407 ) {
case V_410 :
V_2 -> V_6 . V_411 = FALSE ;
F_19 ( V_2 , V_41 , V_42 ) ;
break ;
case V_412 :
F_19 ( V_2 , V_41 , V_413 ) ;
V_2 -> V_6 . V_411 = TRUE ;
F_102 ( V_2 , V_414 ) ;
F_103 ( V_2 , ( V_31 ) V_415 , ( V_31 )
V_416 , ( V_31 ) V_417 ,
F_104 ( V_2 ) ) ;
break ;
case V_418 :
F_103 ( V_2 , ( V_31 ) V_415 , ( V_31 )
V_416 , ( V_31 ) V_419 ,
F_104 ( V_2 ) ) ;
break ;
case V_420 :
F_103 ( V_2 , ( V_31 ) V_415 , ( V_31 )
V_416 , ( V_31 ) V_421 ,
F_104 ( V_2 ) ) ;
break ;
case V_422 :
if ( V_2 -> V_72 [ V_393 ] . V_423 == V_424 ) {
F_102 ( V_2 , V_425 ) ;
F_19 ( V_2 , V_426 + V_393 , V_427 ) ;
}
break ;
case V_428 :
if ( V_2 -> V_72 [ V_429 ] . V_423 == V_424 ) {
F_102 ( V_2 , V_425 ) ;
F_19 ( V_2 , V_426 + V_429 , V_427 ) ;
}
break ;
case V_430 :
for ( V_49 = 0 ; V_49 < V_71 ; V_49 ++ ) {
if ( V_2 -> V_6 . V_268 [ V_49 ] . V_431 != V_432 )
continue ;
F_102 ( V_2 , V_425 ) ;
F_19 ( V_2 , V_426 + V_49 , V_427 ) ;
}
break ;
default :
return 1 ;
}
break ;
case V_433 :
switch( V_407 ) {
case V_434 :
V_40 = V_435 ;
break ;
case V_436 :
V_40 = V_427 ;
break ;
case V_437 :
V_40 = V_438 ;
break ;
case V_439 :
V_40 = V_440 ;
break ;
case V_441 :
V_40 = V_442 ;
break ;
default :
return 1 ;
}
F_19 ( V_2 , V_426 + V_408 , V_40 ) ;
break ;
default :
return 1 ;
}
return 0 ;
}
static void F_38 ( struct V_1 * V_2 , char * V_403 , int V_173 )
{
int V_14 ;
F_94 ( V_2 ) ;
for ( V_14 = V_173 ; V_14 ; V_14 -- , V_403 ++ )
* V_403 = F_7 ( * V_403 ) ;
}
