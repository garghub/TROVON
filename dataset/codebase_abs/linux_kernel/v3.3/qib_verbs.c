static inline struct V_1 * F_1 ( struct V_2
* V_3 )
{
return F_2 ( V_3 , struct V_1 , V_3 ) ;
}
void F_3 ( struct V_4 * V_5 , void * V_6 , T_1 V_7 , int V_8 )
{
struct V_9 * V_10 = & V_5 -> V_10 ;
while ( V_7 ) {
T_1 V_11 = V_10 -> V_7 ;
if ( V_11 > V_7 )
V_11 = V_7 ;
if ( V_11 > V_10 -> V_12 )
V_11 = V_10 -> V_12 ;
F_4 ( V_11 == 0 ) ;
memcpy ( V_10 -> V_13 , V_6 , V_11 ) ;
V_10 -> V_13 += V_11 ;
V_10 -> V_7 -= V_11 ;
V_10 -> V_12 -= V_11 ;
if ( V_10 -> V_12 == 0 ) {
if ( V_8 )
F_5 ( & V_10 -> V_14 -> V_15 ) ;
if ( -- V_5 -> V_16 )
* V_10 = * V_5 -> V_17 ++ ;
} else if ( V_10 -> V_7 == 0 && V_10 -> V_14 -> V_18 ) {
if ( ++ V_10 -> V_19 >= V_20 ) {
if ( ++ V_10 -> V_21 >= V_10 -> V_14 -> V_22 )
break;
V_10 -> V_19 = 0 ;
}
V_10 -> V_13 =
V_10 -> V_14 -> V_23 [ V_10 -> V_21 ] -> V_24 [ V_10 -> V_19 ] . V_13 ;
V_10 -> V_7 =
V_10 -> V_14 -> V_23 [ V_10 -> V_21 ] -> V_24 [ V_10 -> V_19 ] . V_7 ;
}
V_6 += V_11 ;
V_7 -= V_11 ;
}
}
void F_6 ( struct V_4 * V_5 , T_1 V_7 , int V_8 )
{
struct V_9 * V_10 = & V_5 -> V_10 ;
while ( V_7 ) {
T_1 V_11 = V_10 -> V_7 ;
if ( V_11 > V_7 )
V_11 = V_7 ;
if ( V_11 > V_10 -> V_12 )
V_11 = V_10 -> V_12 ;
F_4 ( V_11 == 0 ) ;
V_10 -> V_13 += V_11 ;
V_10 -> V_7 -= V_11 ;
V_10 -> V_12 -= V_11 ;
if ( V_10 -> V_12 == 0 ) {
if ( V_8 )
F_5 ( & V_10 -> V_14 -> V_15 ) ;
if ( -- V_5 -> V_16 )
* V_10 = * V_5 -> V_17 ++ ;
} else if ( V_10 -> V_7 == 0 && V_10 -> V_14 -> V_18 ) {
if ( ++ V_10 -> V_19 >= V_20 ) {
if ( ++ V_10 -> V_21 >= V_10 -> V_14 -> V_22 )
break;
V_10 -> V_19 = 0 ;
}
V_10 -> V_13 =
V_10 -> V_14 -> V_23 [ V_10 -> V_21 ] -> V_24 [ V_10 -> V_19 ] . V_13 ;
V_10 -> V_7 =
V_10 -> V_14 -> V_23 [ V_10 -> V_21 ] -> V_24 [ V_10 -> V_19 ] . V_7 ;
}
V_7 -= V_11 ;
}
}
static T_1 F_7 ( struct V_4 * V_5 , T_1 V_7 )
{
struct V_9 * V_17 = V_5 -> V_17 ;
struct V_9 V_10 = V_5 -> V_10 ;
T_2 V_16 = V_5 -> V_16 ;
T_1 V_25 = 1 ;
while ( V_7 ) {
T_1 V_11 = V_10 . V_7 ;
if ( V_11 > V_7 )
V_11 = V_7 ;
if ( V_11 > V_10 . V_12 )
V_11 = V_10 . V_12 ;
F_4 ( V_11 == 0 ) ;
if ( ( ( long ) V_10 . V_13 & ( sizeof( T_1 ) - 1 ) ) ||
( V_11 != V_7 && ( V_11 & ( sizeof( T_1 ) - 1 ) ) ) ) {
V_25 = 0 ;
break;
}
V_25 ++ ;
V_10 . V_13 += V_11 ;
V_10 . V_7 -= V_11 ;
V_10 . V_12 -= V_11 ;
if ( V_10 . V_12 == 0 ) {
if ( -- V_16 )
V_10 = * V_17 ++ ;
} else if ( V_10 . V_7 == 0 && V_10 . V_14 -> V_18 ) {
if ( ++ V_10 . V_19 >= V_20 ) {
if ( ++ V_10 . V_21 >= V_10 . V_14 -> V_22 )
break;
V_10 . V_19 = 0 ;
}
V_10 . V_13 =
V_10 . V_14 -> V_23 [ V_10 . V_21 ] -> V_24 [ V_10 . V_19 ] . V_13 ;
V_10 . V_7 =
V_10 . V_14 -> V_23 [ V_10 . V_21 ] -> V_24 [ V_10 . V_19 ] . V_7 ;
}
V_7 -= V_11 ;
}
return V_25 ;
}
static void F_8 ( void * V_6 , struct V_4 * V_5 , T_1 V_7 )
{
struct V_9 * V_10 = & V_5 -> V_10 ;
while ( V_7 ) {
T_1 V_11 = V_10 -> V_7 ;
if ( V_11 > V_7 )
V_11 = V_7 ;
if ( V_11 > V_10 -> V_12 )
V_11 = V_10 -> V_12 ;
F_4 ( V_11 == 0 ) ;
memcpy ( V_6 , V_10 -> V_13 , V_11 ) ;
V_10 -> V_13 += V_11 ;
V_10 -> V_7 -= V_11 ;
V_10 -> V_12 -= V_11 ;
if ( V_10 -> V_12 == 0 ) {
if ( -- V_5 -> V_16 )
* V_10 = * V_5 -> V_17 ++ ;
} else if ( V_10 -> V_7 == 0 && V_10 -> V_14 -> V_18 ) {
if ( ++ V_10 -> V_19 >= V_20 ) {
if ( ++ V_10 -> V_21 >= V_10 -> V_14 -> V_22 )
break;
V_10 -> V_19 = 0 ;
}
V_10 -> V_13 =
V_10 -> V_14 -> V_23 [ V_10 -> V_21 ] -> V_24 [ V_10 -> V_19 ] . V_13 ;
V_10 -> V_7 =
V_10 -> V_14 -> V_23 [ V_10 -> V_21 ] -> V_24 [ V_10 -> V_19 ] . V_7 ;
}
V_6 += V_11 ;
V_7 -= V_11 ;
}
}
static int F_9 ( struct V_26 * V_27 , struct V_28 * V_29 )
{
struct V_30 * V_31 ;
T_1 V_32 ;
int V_33 ;
int V_34 ;
int V_35 ;
int V_36 ;
unsigned long V_37 ;
struct V_38 * V_39 ;
struct V_40 * V_41 ;
F_10 ( & V_27 -> V_42 , V_37 ) ;
if ( F_11 ( ! ( V_43 [ V_27 -> V_44 ] & V_45 ) ) )
goto V_46;
if ( V_29 -> V_16 > V_27 -> V_47 )
goto V_46;
if ( V_29 -> V_48 == V_49 ) {
if ( F_12 ( V_27 , V_29 ) )
goto V_46;
} else if ( V_27 -> V_50 . V_51 == V_52 ) {
if ( ( unsigned ) V_29 -> V_48 >= V_53 )
goto V_46;
} else if ( V_27 -> V_50 . V_51 != V_54 ) {
if ( V_29 -> V_48 != V_55 &&
V_29 -> V_48 != V_56 )
goto V_46;
if ( V_27 -> V_50 . V_41 != V_29 -> V_29 . V_57 . V_58 -> V_41 )
goto V_46;
} else if ( ( unsigned ) V_29 -> V_48 > V_59 )
goto V_46;
else if ( V_29 -> V_48 >= V_60 &&
( V_29 -> V_16 == 0 ||
V_29 -> V_17 [ 0 ] . V_7 < sizeof( V_61 ) ||
V_29 -> V_17 [ 0 ] . V_62 & ( sizeof( V_61 ) - 1 ) ) )
goto V_46;
else if ( V_29 -> V_48 >= V_53 && ! V_27 -> V_63 )
goto V_46;
V_32 = V_27 -> V_64 + 1 ;
if ( V_32 >= V_27 -> V_65 )
V_32 = 0 ;
if ( V_32 == V_27 -> V_66 ) {
V_36 = - V_67 ;
goto V_68;
}
V_39 = & F_13 ( V_27 -> V_50 . V_69 ) -> V_70 ;
V_41 = F_14 ( V_27 -> V_50 . V_41 ) ;
V_31 = F_15 ( V_27 , V_27 -> V_64 ) ;
V_31 -> V_29 = * V_29 ;
V_31 -> V_7 = 0 ;
V_34 = 0 ;
if ( V_29 -> V_16 ) {
V_35 = V_29 -> V_48 >= V_53 ?
V_71 : 0 ;
for ( V_33 = 0 ; V_33 < V_29 -> V_16 ; V_33 ++ ) {
T_1 V_7 = V_29 -> V_17 [ V_33 ] . V_7 ;
int V_72 ;
if ( V_7 == 0 )
continue;
V_72 = F_16 ( V_39 , V_41 , & V_31 -> V_17 [ V_34 ] ,
& V_29 -> V_17 [ V_33 ] , V_35 ) ;
if ( ! V_72 )
goto V_73;
V_31 -> V_7 += V_7 ;
V_34 ++ ;
}
V_31 -> V_29 . V_16 = V_34 ;
}
if ( V_27 -> V_50 . V_51 == V_52 ||
V_27 -> V_50 . V_51 == V_54 ) {
if ( V_31 -> V_7 > 0x80000000U )
goto V_73;
} else if ( V_31 -> V_7 > ( F_17 ( V_27 -> V_50 . V_69 ) -> V_74 +
V_27 -> V_75 - 1 ) -> V_76 )
goto V_73;
else
F_18 ( & F_19 ( V_29 -> V_29 . V_57 . V_58 ) -> V_15 ) ;
V_31 -> V_77 = V_27 -> V_78 ++ ;
V_27 -> V_64 = V_32 ;
V_36 = 0 ;
goto V_68;
V_73:
while ( V_34 ) {
struct V_9 * V_10 = & V_31 -> V_17 [ -- V_34 ] ;
F_5 ( & V_10 -> V_14 -> V_15 ) ;
}
V_46:
V_36 = - V_79 ;
V_68:
F_20 ( & V_27 -> V_42 , V_37 ) ;
return V_36 ;
}
static int F_21 ( struct V_80 * V_50 , struct V_28 * V_29 ,
struct V_28 * * V_81 )
{
struct V_26 * V_27 = F_22 ( V_50 ) ;
int V_82 = 0 ;
for (; V_29 ; V_29 = V_29 -> V_32 ) {
V_82 = F_9 ( V_27 , V_29 ) ;
if ( V_82 ) {
* V_81 = V_29 ;
goto V_68;
}
}
F_23 ( & V_27 -> V_83 ) ;
V_68:
return V_82 ;
}
static int F_24 ( struct V_80 * V_50 , struct V_84 * V_29 ,
struct V_84 * * V_81 )
{
struct V_26 * V_27 = F_22 ( V_50 ) ;
struct V_85 * V_86 = V_27 -> V_87 . V_86 ;
unsigned long V_37 ;
int V_36 ;
if ( ! ( V_43 [ V_27 -> V_44 ] & V_88 ) || ! V_86 ) {
* V_81 = V_29 ;
V_36 = - V_79 ;
goto V_68;
}
for (; V_29 ; V_29 = V_29 -> V_32 ) {
struct V_89 * V_31 ;
T_1 V_32 ;
int V_33 ;
if ( ( unsigned ) V_29 -> V_16 > V_27 -> V_87 . V_90 ) {
* V_81 = V_29 ;
V_36 = - V_79 ;
goto V_68;
}
F_10 ( & V_27 -> V_87 . V_91 , V_37 ) ;
V_32 = V_86 -> V_92 + 1 ;
if ( V_32 >= V_27 -> V_87 . V_93 )
V_32 = 0 ;
if ( V_32 == V_86 -> V_94 ) {
F_20 ( & V_27 -> V_87 . V_91 , V_37 ) ;
* V_81 = V_29 ;
V_36 = - V_67 ;
goto V_68;
}
V_31 = F_25 ( & V_27 -> V_87 , V_86 -> V_92 ) ;
V_31 -> V_95 = V_29 -> V_95 ;
V_31 -> V_16 = V_29 -> V_16 ;
for ( V_33 = 0 ; V_33 < V_29 -> V_16 ; V_33 ++ )
V_31 -> V_17 [ V_33 ] = V_29 -> V_17 [ V_33 ] ;
F_26 () ;
V_86 -> V_92 = V_32 ;
F_20 ( & V_27 -> V_87 . V_91 , V_37 ) ;
}
V_36 = 0 ;
V_68:
return V_36 ;
}
static void F_27 ( struct V_96 * V_97 , struct V_98 * V_99 ,
int V_100 , void * V_6 , T_1 V_101 , struct V_26 * V_27 )
{
struct V_102 * V_103 = & V_97 -> V_104 -> V_105 ;
F_28 ( & V_27 -> V_106 ) ;
if ( ! ( V_43 [ V_27 -> V_44 ] & V_107 ) ) {
V_103 -> V_108 ++ ;
goto V_109;
}
switch ( V_27 -> V_50 . V_51 ) {
case V_110 :
case V_111 :
if ( V_112 )
break;
case V_113 :
F_29 ( V_103 , V_99 , V_100 , V_6 , V_101 , V_27 ) ;
break;
case V_54 :
F_30 ( V_97 , V_99 , V_100 , V_6 , V_101 , V_27 ) ;
break;
case V_52 :
F_31 ( V_103 , V_99 , V_100 , V_6 , V_101 , V_27 ) ;
break;
default:
break;
}
V_109:
F_32 ( & V_27 -> V_106 ) ;
}
void F_33 ( struct V_96 * V_97 , void * V_114 , void * V_6 , T_1 V_101 )
{
struct V_115 * V_104 = V_97 -> V_104 ;
struct V_102 * V_103 = & V_104 -> V_105 ;
struct V_98 * V_99 = V_114 ;
struct V_116 * V_117 ;
struct V_26 * V_27 ;
T_1 V_118 ;
int V_119 ;
T_2 V_48 ;
T_3 V_120 ;
if ( F_11 ( V_101 < 24 ) )
goto V_121;
V_120 = F_34 ( V_99 -> V_122 [ 1 ] ) ;
if ( V_120 < V_123 ) {
V_120 &= ~ ( ( 1 << V_104 -> V_124 ) - 1 ) ;
if ( F_11 ( V_120 != V_104 -> V_120 ) )
goto V_121;
}
V_119 = F_34 ( V_99 -> V_122 [ 0 ] ) & 3 ;
if ( V_119 == V_125 )
V_117 = & V_99 -> V_126 . V_127 ;
else if ( V_119 == V_128 ) {
T_1 V_129 ;
V_117 = & V_99 -> V_126 . V_130 . V_127 ;
if ( V_99 -> V_126 . V_130 . V_131 . V_132 != V_133 )
goto V_121;
V_129 = F_35 ( V_99 -> V_126 . V_130 . V_131 . V_134 ) ;
if ( ( V_129 >> V_135 ) != V_136 )
goto V_121;
} else
goto V_121;
V_48 = F_35 ( V_117 -> V_137 [ 0 ] ) >> 24 ;
V_103 -> V_138 [ V_48 & 0x7f ] . V_139 += V_101 ;
V_103 -> V_138 [ V_48 & 0x7f ] . V_140 ++ ;
V_118 = F_35 ( V_117 -> V_137 [ 1 ] ) & V_141 ;
if ( V_118 == V_142 ) {
struct V_143 * V_144 ;
struct V_145 * V_146 ;
if ( V_119 != V_128 )
goto V_121;
V_144 = F_36 ( V_103 , & V_99 -> V_126 . V_130 . V_131 . V_147 ) ;
if ( V_144 == NULL )
goto V_121;
V_103 -> V_148 ++ ;
F_37 (p, &mcast->qp_list, list)
F_27 ( V_97 , V_99 , 1 , V_6 , V_101 , V_146 -> V_27 ) ;
if ( F_38 ( & V_144 -> V_15 ) <= 1 )
F_39 ( & V_144 -> V_149 ) ;
} else {
if ( V_97 -> V_150 ) {
if ( V_97 -> V_151 != V_118 ) {
if ( F_40 (
& V_97 -> V_150 -> V_15 ) )
F_39 (
& V_97 -> V_150 -> V_149 ) ;
V_97 -> V_150 = NULL ;
}
}
if ( ! V_97 -> V_150 ) {
V_27 = F_41 ( V_103 , V_118 ) ;
if ( ! V_27 )
goto V_121;
V_97 -> V_150 = V_27 ;
V_97 -> V_151 = V_118 ;
} else
V_27 = V_97 -> V_150 ;
V_103 -> V_152 ++ ;
F_27 ( V_97 , V_99 , V_119 == V_128 , V_6 , V_101 , V_27 ) ;
}
return;
V_121:
V_103 -> V_108 ++ ;
}
static void F_42 ( unsigned long V_6 )
{
struct V_153 * V_154 = (struct V_153 * ) V_6 ;
struct V_155 * V_156 = & V_154 -> V_157 ;
struct V_26 * V_27 = NULL ;
unsigned long V_37 ;
F_10 ( & V_154 -> V_158 , V_37 ) ;
if ( ! F_43 ( V_156 ) ) {
V_27 = F_44 ( V_156 -> V_32 , struct V_26 , V_159 ) ;
F_45 ( & V_27 -> V_159 ) ;
F_18 ( & V_27 -> V_15 ) ;
if ( ! F_43 ( V_156 ) )
F_46 ( & V_154 -> F_42 , V_160 + 1 ) ;
}
F_20 ( & V_154 -> V_158 , V_37 ) ;
if ( V_27 ) {
F_10 ( & V_27 -> V_42 , V_37 ) ;
if ( V_27 -> V_161 & V_162 ) {
V_27 -> V_161 &= ~ V_162 ;
F_47 ( V_27 ) ;
}
F_20 ( & V_27 -> V_42 , V_37 ) ;
if ( F_40 ( & V_27 -> V_15 ) )
F_39 ( & V_27 -> V_149 ) ;
}
}
static void F_48 ( struct V_4 * V_5 , T_1 V_7 )
{
struct V_9 * V_10 = & V_5 -> V_10 ;
V_10 -> V_13 += V_7 ;
V_10 -> V_7 -= V_7 ;
V_10 -> V_12 -= V_7 ;
if ( V_10 -> V_12 == 0 ) {
if ( -- V_5 -> V_16 )
* V_10 = * V_5 -> V_17 ++ ;
} else if ( V_10 -> V_7 == 0 && V_10 -> V_14 -> V_18 ) {
if ( ++ V_10 -> V_19 >= V_20 ) {
if ( ++ V_10 -> V_21 >= V_10 -> V_14 -> V_22 )
return;
V_10 -> V_19 = 0 ;
}
V_10 -> V_13 = V_10 -> V_14 -> V_23 [ V_10 -> V_21 ] -> V_24 [ V_10 -> V_19 ] . V_13 ;
V_10 -> V_7 = V_10 -> V_14 -> V_23 [ V_10 -> V_21 ] -> V_24 [ V_10 -> V_19 ] . V_7 ;
}
}
static inline T_1 F_49 ( T_1 V_6 , T_1 V_163 )
{
return V_6 >> V_163 ;
}
static inline T_1 F_50 ( T_1 V_6 , T_1 V_163 )
{
return V_6 << V_163 ;
}
static inline T_1 F_51 ( T_1 V_6 , T_1 V_19 , T_1 V_164 )
{
V_6 <<= ( ( sizeof( T_1 ) - V_19 ) * V_165 ) ;
V_6 >>= ( ( sizeof( T_1 ) - V_19 - V_164 ) * V_165 ) ;
return V_6 ;
}
static inline T_1 F_49 ( T_1 V_6 , T_1 V_163 )
{
return V_6 << V_163 ;
}
static inline T_1 F_50 ( T_1 V_6 , T_1 V_163 )
{
return V_6 >> V_163 ;
}
static inline T_1 F_51 ( T_1 V_6 , T_1 V_19 , T_1 V_164 )
{
V_6 >>= ( ( sizeof( T_1 ) - V_19 ) * V_165 ) ;
V_6 <<= ( ( sizeof( T_1 ) - V_19 - V_164 ) * V_165 ) ;
return V_6 ;
}
static void F_52 ( T_1 T_4 * V_166 , struct V_4 * V_5 ,
T_1 V_7 , unsigned V_167 )
{
T_1 V_168 = 0 ;
T_1 V_6 = 0 ;
T_1 V_169 ;
while ( 1 ) {
T_1 V_11 = V_5 -> V_10 . V_7 ;
T_1 V_164 ;
if ( V_11 > V_7 )
V_11 = V_7 ;
if ( V_11 > V_5 -> V_10 . V_12 )
V_11 = V_5 -> V_10 . V_12 ;
F_4 ( V_11 == 0 ) ;
V_164 = ( unsigned long ) V_5 -> V_10 . V_13 & ( sizeof( T_1 ) - 1 ) ;
if ( V_164 ) {
T_1 * V_62 = ( T_1 * ) ( ( unsigned long ) V_5 -> V_10 . V_13 &
~ ( sizeof( T_1 ) - 1 ) ) ;
T_1 V_170 = F_49 ( * V_62 , V_164 * V_165 ) ;
T_1 V_171 ;
V_171 = sizeof( T_1 ) - V_164 ;
if ( V_11 > V_171 )
V_11 = V_171 ;
if ( V_11 + V_168 >= sizeof( T_1 ) ) {
V_6 |= F_50 ( V_170 , V_168 *
V_165 ) ;
V_11 = sizeof( T_1 ) - V_168 ;
if ( V_11 == V_7 ) {
V_169 = V_6 ;
break;
}
F_53 ( V_6 , V_166 ) ;
V_166 ++ ;
V_168 = 0 ;
V_6 = 0 ;
} else {
V_6 |= F_51 ( V_170 , V_11 , V_168 ) ;
if ( V_11 == V_7 ) {
V_169 = V_6 ;
break;
}
V_168 += V_11 ;
}
} else if ( V_168 ) {
T_1 * V_62 = ( T_1 * ) V_5 -> V_10 . V_13 ;
int V_163 = V_168 * V_165 ;
int V_172 = 32 - V_163 ;
T_1 V_130 = V_11 ;
while ( V_130 >= sizeof( T_1 ) ) {
T_1 V_170 = * V_62 ;
V_6 |= F_50 ( V_170 , V_163 ) ;
F_53 ( V_6 , V_166 ) ;
V_6 = F_49 ( V_170 , V_172 ) ;
V_166 ++ ;
V_62 ++ ;
V_130 -= sizeof( T_1 ) ;
}
if ( V_130 ) {
T_1 V_170 = * V_62 ;
if ( V_130 + V_168 >= sizeof( T_1 ) ) {
V_6 |= F_50 ( V_170 , V_163 ) ;
V_11 -= V_130 + V_168 - sizeof( T_1 ) ;
if ( V_11 == V_7 ) {
V_169 = V_6 ;
break;
}
F_53 ( V_6 , V_166 ) ;
V_166 ++ ;
V_168 = 0 ;
V_6 = 0 ;
} else {
V_6 |= F_51 ( V_170 , V_130 , V_168 ) ;
if ( V_11 == V_7 ) {
V_169 = V_6 ;
break;
}
V_168 += V_130 ;
}
} else if ( V_11 == V_7 ) {
V_169 = V_6 ;
break;
}
} else if ( V_11 == V_7 ) {
T_1 V_173 ;
V_173 = ( V_11 + 3 ) >> 2 ;
F_54 ( V_166 , V_5 -> V_10 . V_13 , V_173 - 1 ) ;
V_166 += V_173 - 1 ;
V_169 = ( ( T_1 * ) V_5 -> V_10 . V_13 ) [ V_173 - 1 ] ;
break;
} else {
T_1 V_173 = V_11 >> 2 ;
F_54 ( V_166 , V_5 -> V_10 . V_13 , V_173 ) ;
V_166 += V_173 ;
V_168 = V_11 & ( sizeof( T_1 ) - 1 ) ;
if ( V_168 ) {
T_1 V_170 = ( ( T_1 * ) V_5 -> V_10 . V_13 ) [ V_173 ] ;
V_6 = F_51 ( V_170 , V_168 , 0 ) ;
}
}
F_48 ( V_5 , V_11 ) ;
V_7 -= V_11 ;
}
F_48 ( V_5 , V_7 ) ;
if ( V_167 ) {
F_55 () ;
F_53 ( V_169 , V_166 ) ;
F_55 () ;
} else
F_53 ( V_169 , V_166 ) ;
}
inline struct V_174 * F_56 ( struct V_153 * V_154 ,
struct V_26 * V_27 )
{
struct V_174 * V_175 ;
unsigned long V_37 ;
F_10 ( & V_154 -> V_158 , V_37 ) ;
if ( F_57 ( ! F_43 ( & V_154 -> V_176 ) ) ) {
struct V_155 * V_130 = V_154 -> V_176 . V_32 ;
F_58 ( V_130 ) ;
F_20 ( & V_154 -> V_158 , V_37 ) ;
V_175 = F_44 ( V_130 , struct V_174 , V_177 . V_156 ) ;
} else {
F_20 ( & V_154 -> V_158 , V_37 ) ;
V_175 = F_59 ( V_154 , V_27 ) ;
}
return V_175 ;
}
void F_60 ( struct V_174 * V_175 )
{
struct V_153 * V_154 ;
struct V_26 * V_27 ;
unsigned long V_37 ;
V_27 = V_175 -> V_27 ;
V_154 = F_13 ( V_27 -> V_50 . V_69 ) ;
if ( F_40 ( & V_27 -> V_15 ) )
F_39 ( & V_27 -> V_149 ) ;
if ( V_175 -> V_14 ) {
F_5 ( & V_175 -> V_14 -> V_15 ) ;
V_175 -> V_14 = NULL ;
}
if ( V_175 -> V_177 . V_37 & V_178 ) {
V_175 -> V_177 . V_37 &= ~ V_178 ;
F_61 ( & F_62 ( V_154 ) -> V_179 -> V_154 ,
V_175 -> V_177 . V_62 , V_175 -> V_180 << 2 ,
V_181 ) ;
F_63 ( V_175 -> V_182 ) ;
}
F_10 ( & V_154 -> V_158 , V_37 ) ;
F_64 ( & V_175 -> V_177 . V_156 , & V_154 -> V_176 ) ;
if ( ! F_43 ( & V_154 -> V_183 ) ) {
V_27 = F_44 ( V_154 -> V_183 . V_32 , struct V_26 , V_159 ) ;
F_45 ( & V_27 -> V_159 ) ;
F_18 ( & V_27 -> V_15 ) ;
F_20 ( & V_154 -> V_158 , V_37 ) ;
F_10 ( & V_27 -> V_42 , V_37 ) ;
if ( V_27 -> V_161 & V_184 ) {
V_27 -> V_161 &= ~ V_184 ;
F_47 ( V_27 ) ;
}
F_20 ( & V_27 -> V_42 , V_37 ) ;
if ( F_40 ( & V_27 -> V_15 ) )
F_39 ( & V_27 -> V_149 ) ;
} else
F_20 ( & V_154 -> V_158 , V_37 ) ;
}
void F_65 ( struct V_115 * V_104 , unsigned V_185 )
{
struct V_26 * V_27 , * V_186 ;
struct V_26 * V_187 [ 20 ] ;
struct V_153 * V_154 ;
unsigned V_33 , V_19 ;
V_19 = 0 ;
V_154 = & V_104 -> V_188 -> V_189 ;
F_28 ( & V_154 -> V_158 ) ;
F_66 (qp, nqp, &dev->dmawait, iowait) {
if ( V_27 -> V_75 != V_104 -> V_190 )
continue;
if ( V_19 == F_67 ( V_187 ) )
break;
if ( V_27 -> V_191 -> V_177 . V_192 > V_185 )
break;
V_185 -= V_27 -> V_191 -> V_177 . V_192 ;
F_45 ( & V_27 -> V_159 ) ;
F_18 ( & V_27 -> V_15 ) ;
V_187 [ V_19 ++ ] = V_27 ;
}
F_32 ( & V_154 -> V_158 ) ;
for ( V_33 = 0 ; V_33 < V_19 ; V_33 ++ ) {
V_27 = V_187 [ V_33 ] ;
F_28 ( & V_27 -> V_42 ) ;
if ( V_27 -> V_161 & V_193 ) {
V_27 -> V_161 &= ~ V_193 ;
F_47 ( V_27 ) ;
}
F_32 ( & V_27 -> V_42 ) ;
if ( F_40 ( & V_27 -> V_15 ) )
F_39 ( & V_27 -> V_149 ) ;
}
}
static void F_68 ( struct V_194 * V_195 , int V_196 )
{
struct V_174 * V_175 =
F_2 ( V_195 , struct V_174 , V_177 ) ;
struct V_26 * V_27 = V_175 -> V_27 ;
F_28 ( & V_27 -> V_42 ) ;
if ( V_175 -> V_31 )
F_69 ( V_27 , V_175 -> V_31 , V_197 ) ;
else if ( V_27 -> V_50 . V_51 == V_54 ) {
struct V_98 * V_99 ;
if ( V_175 -> V_177 . V_37 & V_178 )
V_99 = & V_175 -> V_182 -> V_99 ;
else {
struct V_153 * V_154 = F_13 ( V_27 -> V_50 . V_69 ) ;
V_99 = & V_154 -> V_198 [ V_175 -> V_199 ] . V_99 ;
}
F_70 ( V_27 , V_99 ) ;
}
if ( F_40 ( & V_27 -> V_200 ) ) {
if ( V_27 -> V_44 == V_201 )
F_39 ( & V_27 -> V_202 ) ;
else if ( V_27 -> V_161 & V_203 ) {
V_27 -> V_161 &= ~ V_203 ;
F_47 ( V_27 ) ;
}
}
F_32 ( & V_27 -> V_42 ) ;
F_60 ( V_175 ) ;
}
static int F_71 ( struct V_153 * V_154 , struct V_26 * V_27 )
{
unsigned long V_37 ;
int V_36 = 0 ;
F_10 ( & V_27 -> V_42 , V_37 ) ;
if ( V_43 [ V_27 -> V_44 ] & V_107 ) {
F_28 ( & V_154 -> V_158 ) ;
if ( F_43 ( & V_27 -> V_159 ) ) {
if ( F_43 ( & V_154 -> V_157 ) )
F_46 ( & V_154 -> F_42 , V_160 + 1 ) ;
V_27 -> V_161 |= V_162 ;
F_72 ( & V_27 -> V_159 , & V_154 -> V_157 ) ;
}
F_32 ( & V_154 -> V_158 ) ;
V_27 -> V_161 &= ~ V_204 ;
V_36 = - V_205 ;
}
F_20 ( & V_27 -> V_42 , V_37 ) ;
return V_36 ;
}
static int F_73 ( struct V_26 * V_27 , struct V_98 * V_99 ,
T_1 V_206 , struct V_4 * V_5 , T_1 V_11 ,
T_1 V_207 , T_1 V_208 )
{
struct V_153 * V_154 = F_13 ( V_27 -> V_50 . V_69 ) ;
struct V_209 * V_188 = F_62 ( V_154 ) ;
struct V_102 * V_103 = F_74 ( V_27 -> V_50 . V_69 , V_27 -> V_75 ) ;
struct V_115 * V_104 = F_75 ( V_103 ) ;
struct V_174 * V_175 ;
struct V_210 * V_211 ;
T_1 V_212 ;
T_1 V_25 ;
int V_36 ;
V_175 = V_27 -> V_191 ;
if ( V_175 ) {
V_27 -> V_191 = NULL ;
V_36 = F_76 ( V_104 , V_175 -> V_5 , V_175 -> V_208 , V_175 ) ;
goto V_68;
}
V_175 = F_56 ( V_154 , V_27 ) ;
if ( F_77 ( V_175 ) )
goto V_213;
V_212 = V_188 -> V_214 ( V_104 , V_207 , V_27 -> V_215 ,
F_34 ( V_99 -> V_122 [ 0 ] ) >> 12 ) ;
V_175 -> V_27 = V_27 ;
F_18 ( & V_27 -> V_15 ) ;
V_175 -> V_31 = V_27 -> V_216 ;
V_175 -> V_14 = V_27 -> V_217 ;
if ( V_27 -> V_217 )
V_27 -> V_217 = NULL ;
V_175 -> V_177 . V_218 = F_68 ;
if ( V_188 -> V_37 & V_219 )
V_175 -> V_177 . V_37 = V_220 ;
else
V_175 -> V_177 . V_37 = V_221 ;
if ( V_207 + 1 > V_188 -> V_222 )
V_175 -> V_177 . V_37 |= V_223 ;
if ( V_11 ) {
V_25 = F_7 ( V_5 , V_11 ) ;
if ( V_25 >= V_104 -> V_224 )
V_25 = 0 ;
} else
V_25 = 1 ;
if ( V_25 ) {
V_211 = & V_154 -> V_198 [ V_175 -> V_199 ] ;
V_211 -> V_225 [ 0 ] = F_78 ( V_207 ) ;
V_211 -> V_225 [ 1 ] = F_78 ( V_212 ) ;
memcpy ( & V_211 -> V_99 , V_99 , V_206 << 2 ) ;
V_175 -> V_177 . V_37 |= V_226 ;
V_175 -> V_177 . V_192 = V_25 ;
V_175 -> V_177 . V_62 = V_154 -> V_227 +
V_175 -> V_199 * sizeof( struct V_210 ) ;
V_175 -> V_180 = V_206 + 2 ;
V_36 = F_76 ( V_104 , V_5 , V_208 , V_175 ) ;
goto V_68;
}
V_175 -> V_180 = V_207 + 1 ;
V_211 = F_79 ( V_175 -> V_180 << 2 , V_228 ) ;
if ( ! V_211 )
goto V_229;
V_211 -> V_225 [ 0 ] = F_78 ( V_207 ) ;
V_211 -> V_225 [ 1 ] = F_78 ( V_212 ) ;
memcpy ( & V_211 -> V_99 , V_99 , V_206 << 2 ) ;
F_8 ( ( T_1 * ) & V_211 -> V_99 + V_206 , V_5 , V_11 ) ;
V_175 -> V_177 . V_62 = F_80 ( & V_188 -> V_179 -> V_154 , V_211 ,
V_175 -> V_180 << 2 , V_181 ) ;
if ( F_81 ( & V_188 -> V_179 -> V_154 , V_175 -> V_177 . V_62 ) )
goto V_230;
V_175 -> V_182 = V_211 ;
V_175 -> V_177 . V_37 |= V_178 ;
V_175 -> V_177 . V_192 = 1 ;
V_36 = F_76 ( V_104 , NULL , 0 , V_175 ) ;
goto V_231;
V_230:
F_63 ( V_211 ) ;
V_229:
F_60 ( V_175 ) ;
V_36 = F_71 ( V_154 , V_27 ) ;
V_231:
V_103 -> V_232 ++ ;
V_68:
return V_36 ;
V_213:
V_36 = F_82 ( V_175 ) ;
goto V_68;
}
static int F_83 ( struct V_26 * V_27 )
{
struct V_153 * V_154 = F_13 ( V_27 -> V_50 . V_69 ) ;
struct V_209 * V_188 ;
unsigned long V_37 ;
int V_36 = 0 ;
F_10 ( & V_27 -> V_42 , V_37 ) ;
if ( V_43 [ V_27 -> V_44 ] & V_107 ) {
F_28 ( & V_154 -> V_158 ) ;
if ( F_43 ( & V_27 -> V_159 ) ) {
V_154 -> V_233 ++ ;
V_27 -> V_161 |= V_234 ;
F_72 ( & V_27 -> V_159 , & V_154 -> V_235 ) ;
V_188 = F_62 ( V_154 ) ;
V_188 -> V_236 ( V_188 , 1 ) ;
}
F_32 ( & V_154 -> V_158 ) ;
V_27 -> V_161 &= ~ V_204 ;
V_36 = - V_205 ;
}
F_20 ( & V_27 -> V_42 , V_37 ) ;
return V_36 ;
}
static int F_84 ( struct V_26 * V_27 , struct V_98 * V_237 ,
T_1 V_206 , struct V_4 * V_5 , T_1 V_11 ,
T_1 V_207 , T_1 V_208 )
{
struct V_209 * V_188 = F_17 ( V_27 -> V_50 . V_69 ) ;
struct V_115 * V_104 = V_188 -> V_74 + V_27 -> V_75 - 1 ;
T_1 * V_99 = ( T_1 * ) V_237 ;
T_1 T_4 * V_238 ;
T_1 T_4 * V_166 ;
V_61 V_225 ;
unsigned long V_37 ;
unsigned V_167 ;
T_1 V_212 ;
T_1 V_239 ;
V_212 = V_188 -> V_214 ( V_104 , V_207 , V_27 -> V_215 ,
F_34 ( V_237 -> V_122 [ 0 ] ) >> 12 ) ;
V_225 = ( ( V_61 ) V_212 << 32 ) | V_207 ;
V_166 = V_188 -> V_240 ( V_104 , V_225 , & V_239 ) ;
if ( F_11 ( V_166 == NULL ) )
return F_83 ( V_27 ) ;
F_85 ( V_225 , V_166 ) ;
V_238 = V_166 ;
V_166 += 2 ;
V_167 = V_188 -> V_37 & V_241 ;
if ( V_11 == 0 ) {
if ( V_167 ) {
F_55 () ;
F_54 ( V_166 , V_99 , V_206 - 1 ) ;
F_55 () ;
F_53 ( V_99 [ V_206 - 1 ] , V_166 + V_206 - 1 ) ;
F_55 () ;
} else
F_54 ( V_166 , V_99 , V_206 ) ;
goto V_242;
}
if ( V_167 )
F_55 () ;
F_54 ( V_166 , V_99 , V_206 ) ;
V_166 += V_206 ;
if ( F_57 ( V_5 -> V_16 == 1 && V_11 <= V_5 -> V_10 . V_7 &&
! ( ( unsigned long ) V_5 -> V_10 . V_13 & ( sizeof( T_1 ) - 1 ) ) ) ) {
T_1 * V_62 = ( T_1 * ) V_5 -> V_10 . V_13 ;
F_48 ( V_5 , V_11 ) ;
if ( V_167 ) {
F_54 ( V_166 , V_62 , V_208 - 1 ) ;
F_55 () ;
F_53 ( V_62 [ V_208 - 1 ] , V_166 + V_208 - 1 ) ;
F_55 () ;
} else
F_54 ( V_166 , V_62 , V_208 ) ;
goto V_242;
}
F_52 ( V_166 , V_5 , V_11 , V_167 ) ;
V_242:
if ( V_188 -> V_37 & V_243 ) {
T_1 V_244 = ( V_239 >= V_188 -> V_245 ) ? 2047 : 1023 ;
F_55 () ;
F_53 ( 0xaebecede , V_238 + V_244 ) ;
}
F_86 ( V_188 , V_239 ) ;
if ( V_27 -> V_217 ) {
F_5 ( & V_27 -> V_217 -> V_15 ) ;
V_27 -> V_217 = NULL ;
}
if ( V_27 -> V_216 ) {
F_10 ( & V_27 -> V_42 , V_37 ) ;
F_69 ( V_27 , V_27 -> V_216 , V_197 ) ;
F_20 ( & V_27 -> V_42 , V_37 ) ;
} else if ( V_27 -> V_50 . V_51 == V_54 ) {
F_10 ( & V_27 -> V_42 , V_37 ) ;
F_70 ( V_27 , V_237 ) ;
F_20 ( & V_27 -> V_42 , V_37 ) ;
}
return 0 ;
}
int F_87 ( struct V_26 * V_27 , struct V_98 * V_99 ,
T_1 V_206 , struct V_4 * V_5 , T_1 V_11 )
{
struct V_209 * V_188 = F_17 ( V_27 -> V_50 . V_69 ) ;
T_1 V_207 ;
int V_36 ;
T_1 V_208 = ( V_11 + 3 ) >> 2 ;
V_207 = V_206 + V_208 + 1 ;
if ( V_27 -> V_50 . V_51 == V_110 ||
! ( V_188 -> V_37 & V_246 ) )
V_36 = F_84 ( V_27 , V_99 , V_206 , V_5 , V_11 ,
V_207 , V_208 ) ;
else
V_36 = F_73 ( V_27 , V_99 , V_206 , V_5 , V_11 ,
V_207 , V_208 ) ;
return V_36 ;
}
int F_88 ( struct V_115 * V_104 , V_61 * V_247 ,
V_61 * V_248 , V_61 * V_249 , V_61 * V_250 ,
V_61 * V_251 )
{
int V_36 ;
struct V_209 * V_188 = V_104 -> V_188 ;
if ( ! ( V_188 -> V_37 & V_252 ) ) {
V_36 = - V_79 ;
goto V_68;
}
* V_247 = V_188 -> V_253 ( V_104 , V_254 ) ;
* V_248 = V_188 -> V_253 ( V_104 , V_255 ) ;
* V_249 = V_188 -> V_253 ( V_104 , V_256 ) ;
* V_250 = V_188 -> V_253 ( V_104 , V_257 ) ;
* V_251 = V_188 -> V_253 ( V_104 , V_258 ) ;
V_36 = 0 ;
V_68:
return V_36 ;
}
int F_89 ( struct V_115 * V_104 ,
struct V_259 * V_260 )
{
int V_36 ;
if ( ! ( V_104 -> V_188 -> V_37 & V_252 ) ) {
V_36 = - V_79 ;
goto V_68;
}
V_260 -> V_261 =
V_104 -> V_188 -> V_253 ( V_104 , V_262 ) ;
V_260 -> V_263 =
V_104 -> V_188 -> V_253 ( V_104 , V_264 ) ;
V_260 -> V_265 =
V_104 -> V_188 -> V_253 ( V_104 , V_266 ) ;
V_260 -> V_267 =
V_104 -> V_188 -> V_253 ( V_104 , V_268 ) +
V_104 -> V_188 -> V_253 ( V_104 , V_269 ) +
V_104 -> V_188 -> V_253 ( V_104 , V_270 ) +
V_104 -> V_188 -> V_253 ( V_104 , V_271 ) +
V_104 -> V_188 -> V_253 ( V_104 , V_272 ) +
V_104 -> V_188 -> V_253 ( V_104 , V_273 ) +
V_104 -> V_188 -> V_253 ( V_104 , V_274 ) +
V_104 -> V_188 -> V_253 ( V_104 , V_275 ) +
V_104 -> V_188 -> V_253 ( V_104 , V_276 ) ;
V_260 -> V_267 +=
V_104 -> V_188 -> V_253 ( V_104 , V_277 ) ;
V_260 -> V_267 +=
V_104 -> V_188 -> V_253 ( V_104 , V_278 ) ;
V_260 -> V_279 =
V_104 -> V_188 -> V_253 ( V_104 , V_280 ) ;
V_260 -> V_281 =
V_104 -> V_188 -> V_253 ( V_104 , V_282 ) ;
V_260 -> V_283 = V_104 -> V_188 -> V_253 ( V_104 ,
V_254 ) ;
V_260 -> V_284 = V_104 -> V_188 -> V_253 ( V_104 ,
V_255 ) ;
V_260 -> V_285 = V_104 -> V_188 -> V_253 ( V_104 ,
V_256 ) ;
V_260 -> V_286 = V_104 -> V_188 -> V_253 ( V_104 ,
V_257 ) ;
V_260 -> V_287 =
V_104 -> V_188 -> V_253 ( V_104 , V_288 ) ;
V_260 -> V_289 =
V_104 -> V_188 -> V_253 ( V_104 , V_290 ) ;
V_260 -> V_291 =
V_104 -> V_188 -> V_253 ( V_104 , V_292 ) ;
V_36 = 0 ;
V_68:
return V_36 ;
}
void F_90 ( struct V_209 * V_188 )
{
struct V_153 * V_154 = & V_188 -> V_189 ;
struct V_155 * V_156 ;
struct V_26 * V_187 [ 5 ] ;
struct V_26 * V_27 ;
unsigned long V_37 ;
unsigned V_33 , V_19 ;
V_156 = & V_154 -> V_235 ;
V_19 = 0 ;
F_10 ( & V_154 -> V_158 , V_37 ) ;
while ( ! F_43 ( V_156 ) ) {
if ( V_19 == F_67 ( V_187 ) )
goto V_293;
V_27 = F_44 ( V_156 -> V_32 , struct V_26 , V_159 ) ;
F_45 ( & V_27 -> V_159 ) ;
F_18 ( & V_27 -> V_15 ) ;
V_187 [ V_19 ++ ] = V_27 ;
}
V_188 -> V_236 ( V_188 , 0 ) ;
V_293:
F_20 ( & V_154 -> V_158 , V_37 ) ;
for ( V_33 = 0 ; V_33 < V_19 ; V_33 ++ ) {
V_27 = V_187 [ V_33 ] ;
F_10 ( & V_27 -> V_42 , V_37 ) ;
if ( V_27 -> V_161 & V_234 ) {
V_27 -> V_161 &= ~ V_234 ;
F_47 ( V_27 ) ;
}
F_20 ( & V_27 -> V_42 , V_37 ) ;
if ( F_40 ( & V_27 -> V_15 ) )
F_39 ( & V_27 -> V_149 ) ;
}
}
static int F_91 ( struct V_294 * V_295 ,
struct V_296 * V_297 )
{
struct V_209 * V_188 = F_17 ( V_295 ) ;
struct V_153 * V_154 = F_13 ( V_295 ) ;
memset ( V_297 , 0 , sizeof( * V_297 ) ) ;
V_297 -> V_298 = V_299 |
V_300 | V_301 |
V_302 | V_303 |
V_304 | V_305 ;
V_297 -> V_306 = V_307 ;
V_297 -> V_308 =
V_309 << 16 | V_310 << 8 | V_311 ;
V_297 -> V_312 = V_188 -> V_313 ;
V_297 -> V_314 = V_188 -> V_315 ;
V_297 -> V_316 = V_317 ;
V_297 -> V_318 = ~ 0ULL ;
V_297 -> V_319 = V_320 ;
V_297 -> V_321 = V_322 ;
V_297 -> V_90 = V_323 ;
V_297 -> V_324 = V_325 ;
V_297 -> V_326 = V_327 ;
V_297 -> V_328 = V_329 ;
V_297 -> V_330 = V_154 -> V_70 . V_331 ;
V_297 -> V_332 = V_154 -> V_70 . V_331 ;
V_297 -> V_333 = 32767 ;
V_297 -> V_334 = V_335 ;
V_297 -> V_336 = V_337 ;
V_297 -> V_338 = 255 ;
V_297 -> V_339 = V_340 ;
V_297 -> V_341 = V_342 ;
V_297 -> V_343 = V_344 ;
V_297 -> V_345 = V_346 ;
V_297 -> V_347 = F_92 ( V_188 ) ;
V_297 -> V_348 = V_349 ;
V_297 -> V_350 = V_351 ;
V_297 -> V_352 = V_297 -> V_350 *
V_297 -> V_348 ;
return 0 ;
}
static int F_93 ( struct V_294 * V_295 , T_2 V_190 ,
struct V_353 * V_297 )
{
struct V_209 * V_188 = F_17 ( V_295 ) ;
struct V_102 * V_103 = F_74 ( V_295 , V_190 ) ;
struct V_115 * V_104 = F_75 ( V_103 ) ;
enum V_354 V_355 ;
T_3 V_120 = V_104 -> V_120 ;
memset ( V_297 , 0 , sizeof( * V_297 ) ) ;
V_297 -> V_120 = V_120 ? V_120 : F_34 ( V_356 ) ;
V_297 -> V_124 = V_104 -> V_124 ;
V_297 -> V_357 = V_103 -> V_357 ;
V_297 -> V_358 = V_103 -> V_358 ;
V_297 -> V_44 = V_188 -> V_359 ( V_104 -> V_360 ) ;
V_297 -> V_361 = V_188 -> V_362 ( V_104 -> V_360 ) ;
V_297 -> V_363 = V_103 -> V_363 ;
V_297 -> V_364 = V_365 ;
V_297 -> V_366 = 0x80000000 ;
V_297 -> V_367 = F_92 ( V_188 ) ;
V_297 -> V_368 = V_103 -> V_369 ;
V_297 -> V_370 = V_103 -> V_371 ;
V_297 -> V_372 = V_104 -> V_373 ;
V_297 -> V_374 = V_104 -> V_375 ;
V_297 -> V_376 = F_94 ( V_104 -> V_377 ) ;
V_297 -> V_378 = 0 ;
V_297 -> V_379 = V_380 ? V_380 : V_381 ;
switch ( V_104 -> V_76 ) {
case 4096 :
V_355 = V_381 ;
break;
case 2048 :
V_355 = V_382 ;
break;
case 1024 :
V_355 = V_383 ;
break;
case 512 :
V_355 = V_384 ;
break;
case 256 :
V_355 = V_385 ;
break;
default:
V_355 = V_382 ;
}
V_297 -> V_386 = V_355 ;
V_297 -> V_387 = V_103 -> V_387 ;
return 0 ;
}
static int F_95 ( struct V_294 * V_69 ,
int V_388 ,
struct V_389 * V_390 )
{
struct V_209 * V_188 = F_17 ( V_69 ) ;
unsigned V_33 ;
int V_36 ;
if ( V_388 & ~ ( V_391 |
V_392 ) ) {
V_36 = - V_393 ;
goto V_68;
}
if ( V_388 & V_392 ) {
memcpy ( V_69 -> V_394 , V_390 -> V_394 , 64 ) ;
for ( V_33 = 0 ; V_33 < V_188 -> V_395 ; V_33 ++ ) {
struct V_102 * V_103 = & V_188 -> V_74 [ V_33 ] . V_105 ;
F_96 ( V_103 ) ;
}
}
if ( V_388 & V_391 ) {
V_317 =
F_97 ( V_390 -> V_316 ) ;
for ( V_33 = 0 ; V_33 < V_188 -> V_395 ; V_33 ++ ) {
struct V_102 * V_103 = & V_188 -> V_74 [ V_33 ] . V_105 ;
F_98 ( V_103 ) ;
}
}
V_36 = 0 ;
V_68:
return V_36 ;
}
static int F_99 ( struct V_294 * V_295 , T_2 V_190 ,
int V_396 , struct V_397 * V_297 )
{
struct V_102 * V_103 = F_74 ( V_295 , V_190 ) ;
struct V_115 * V_104 = F_75 ( V_103 ) ;
V_103 -> V_363 |= V_297 -> V_398 ;
V_103 -> V_363 &= ~ V_297 -> V_399 ;
if ( V_297 -> V_398 || V_297 -> V_399 )
F_100 ( V_103 ) ;
if ( V_396 & V_400 )
F_101 ( V_104 , V_401 ) ;
if ( V_396 & V_402 )
V_103 -> V_371 = 0 ;
return 0 ;
}
static int F_102 ( struct V_294 * V_295 , T_2 V_190 ,
int V_403 , union V_404 * V_405 )
{
struct V_209 * V_188 = F_17 ( V_295 ) ;
int V_36 = 0 ;
if ( ! V_190 || V_190 > V_188 -> V_395 )
V_36 = - V_79 ;
else {
struct V_102 * V_103 = F_74 ( V_295 , V_190 ) ;
struct V_115 * V_104 = F_75 ( V_103 ) ;
V_405 -> V_406 . V_407 = V_103 -> V_408 ;
if ( V_403 == 0 )
V_405 -> V_406 . V_409 = V_104 -> V_410 ;
else if ( V_403 < V_365 )
V_405 -> V_406 . V_409 = V_103 -> V_411 [ V_403 - 1 ] ;
else
V_36 = - V_79 ;
}
return V_36 ;
}
static struct V_412 * F_103 ( struct V_294 * V_295 ,
struct V_2 * V_413 ,
struct V_414 * V_415 )
{
struct V_153 * V_154 = F_13 ( V_295 ) ;
struct V_40 * V_41 ;
struct V_412 * V_36 ;
V_41 = F_79 ( sizeof *V_41 , V_416 ) ;
if ( ! V_41 ) {
V_36 = F_104 ( - V_67 ) ;
goto V_68;
}
F_28 ( & V_154 -> V_417 ) ;
if ( V_154 -> V_418 == V_335 ) {
F_32 ( & V_154 -> V_417 ) ;
F_63 ( V_41 ) ;
V_36 = F_104 ( - V_67 ) ;
goto V_68;
}
V_154 -> V_418 ++ ;
F_32 ( & V_154 -> V_417 ) ;
V_41 -> V_419 = V_415 != NULL ;
V_36 = & V_41 -> V_420 ;
V_68:
return V_36 ;
}
static int F_105 ( struct V_412 * V_420 )
{
struct V_40 * V_41 = F_14 ( V_420 ) ;
struct V_153 * V_154 = F_13 ( V_420 -> V_69 ) ;
F_28 ( & V_154 -> V_417 ) ;
V_154 -> V_418 -- ;
F_32 ( & V_154 -> V_417 ) ;
F_63 ( V_41 ) ;
return 0 ;
}
int F_106 ( struct V_294 * V_295 , struct V_421 * V_422 )
{
if ( V_422 -> V_423 >= V_123 &&
V_422 -> V_423 != V_424 &&
! ( V_422 -> V_425 & V_426 ) )
goto V_68;
if ( ( V_422 -> V_425 & V_426 ) &&
V_422 -> V_131 . V_427 >= V_365 )
goto V_68;
if ( V_422 -> V_423 == 0 )
goto V_68;
if ( V_422 -> V_75 < 1 ||
V_422 -> V_75 > V_295 -> V_428 )
goto V_68;
if ( V_422 -> V_429 != V_430 &&
F_107 ( V_422 -> V_429 ) < 0 )
goto V_68;
if ( V_422 -> V_431 > 15 )
goto V_68;
return 0 ;
V_68:
return - V_79 ;
}
static struct V_432 * F_108 ( struct V_412 * V_41 ,
struct V_421 * V_422 )
{
struct V_433 * V_58 ;
struct V_432 * V_36 ;
struct V_153 * V_154 = F_13 ( V_41 -> V_69 ) ;
unsigned long V_37 ;
if ( F_106 ( V_41 -> V_69 , V_422 ) ) {
V_36 = F_104 ( - V_79 ) ;
goto V_68;
}
V_58 = F_79 ( sizeof *V_58 , V_228 ) ;
if ( ! V_58 ) {
V_36 = F_104 ( - V_67 ) ;
goto V_68;
}
F_10 ( & V_154 -> V_434 , V_37 ) ;
if ( V_154 -> V_435 == V_327 ) {
F_20 ( & V_154 -> V_434 , V_37 ) ;
F_63 ( V_58 ) ;
V_36 = F_104 ( - V_67 ) ;
goto V_68;
}
V_154 -> V_435 ++ ;
F_20 ( & V_154 -> V_434 , V_37 ) ;
V_58 -> V_436 = * V_422 ;
F_109 ( & V_58 -> V_15 , 0 ) ;
V_36 = & V_58 -> V_437 ;
V_68:
return V_36 ;
}
static int F_110 ( struct V_432 * V_437 )
{
struct V_153 * V_154 = F_13 ( V_437 -> V_69 ) ;
struct V_433 * V_58 = F_19 ( V_437 ) ;
unsigned long V_37 ;
if ( F_111 ( & V_58 -> V_15 ) != 0 )
return - V_205 ;
F_10 ( & V_154 -> V_434 , V_37 ) ;
V_154 -> V_435 -- ;
F_20 ( & V_154 -> V_434 , V_37 ) ;
F_63 ( V_58 ) ;
return 0 ;
}
static int F_112 ( struct V_432 * V_437 , struct V_421 * V_422 )
{
struct V_433 * V_58 = F_19 ( V_437 ) ;
if ( F_106 ( V_437 -> V_69 , V_422 ) )
return - V_79 ;
V_58 -> V_436 = * V_422 ;
return 0 ;
}
static int F_113 ( struct V_432 * V_437 , struct V_421 * V_422 )
{
struct V_433 * V_58 = F_19 ( V_437 ) ;
* V_422 = V_58 -> V_436 ;
return 0 ;
}
unsigned F_92 ( struct V_209 * V_188 )
{
return F_67 ( V_188 -> V_97 [ 0 ] -> V_438 ) ;
}
unsigned F_114 ( struct V_102 * V_103 , unsigned V_403 )
{
struct V_115 * V_104 = F_75 ( V_103 ) ;
struct V_209 * V_188 = V_104 -> V_188 ;
unsigned V_439 = V_104 -> V_440 ;
unsigned V_36 ;
if ( ! V_188 -> V_97 || V_403 >= F_67 ( V_188 -> V_97 [ V_439 ] -> V_438 ) )
V_36 = 0 ;
else
V_36 = V_188 -> V_97 [ V_439 ] -> V_438 [ V_403 ] ;
return V_36 ;
}
static int F_115 ( struct V_294 * V_295 , T_2 V_190 , T_3 V_403 ,
T_3 * V_441 )
{
struct V_209 * V_188 = F_17 ( V_295 ) ;
int V_36 ;
if ( V_403 >= F_92 ( V_188 ) ) {
V_36 = - V_79 ;
goto V_68;
}
* V_441 = F_114 ( F_74 ( V_295 , V_190 ) , V_403 ) ;
V_36 = 0 ;
V_68:
return V_36 ;
}
static struct V_2 * F_116 ( struct V_294 * V_295 ,
struct V_414 * V_415 )
{
struct V_1 * V_413 ;
struct V_2 * V_36 ;
V_413 = F_79 ( sizeof *V_413 , V_416 ) ;
if ( ! V_413 ) {
V_36 = F_104 ( - V_67 ) ;
goto V_68;
}
V_36 = & V_413 -> V_3 ;
V_68:
return V_36 ;
}
static int F_117 ( struct V_2 * V_413 )
{
F_63 ( F_1 ( V_413 ) ) ;
return 0 ;
}
static void F_118 ( struct V_115 * V_104 )
{
struct V_259 V_260 ;
struct V_102 * V_103 = & V_104 -> V_105 ;
F_119 ( & V_103 -> V_91 ) ;
V_103 -> V_408 = V_442 ;
V_103 -> V_357 = F_34 ( V_356 ) ;
V_103 -> V_363 = V_443 |
V_444 | V_445 |
V_446 | V_447 |
V_448 | V_449 |
V_450 ;
if ( V_104 -> V_188 -> V_37 & V_451 )
V_103 -> V_363 |= V_452 ;
V_103 -> V_453 [ 0 ] = V_454 ;
V_103 -> V_453 [ 1 ] = V_455 ;
V_103 -> V_453 [ 2 ] = V_456 ;
V_103 -> V_453 [ 3 ] = V_457 ;
V_103 -> V_453 [ 4 ] = V_458 ;
F_89 ( V_104 , & V_260 ) ;
V_103 -> V_459 = V_260 . V_261 ;
V_103 -> V_460 =
V_260 . V_263 ;
V_103 -> V_461 = V_260 . V_265 ;
V_103 -> V_462 = V_260 . V_267 ;
V_103 -> V_463 = V_260 . V_279 ;
V_103 -> V_464 = V_260 . V_281 ;
V_103 -> V_465 = V_260 . V_283 ;
V_103 -> V_466 = V_260 . V_284 ;
V_103 -> V_467 = V_260 . V_285 ;
V_103 -> V_468 = V_260 . V_286 ;
V_103 -> V_469 =
V_260 . V_287 ;
V_103 -> V_470 =
V_260 . V_289 ;
V_103 -> V_471 = V_260 . V_291 ;
F_120 ( V_103 -> V_472 , NULL ) ;
F_120 ( V_103 -> V_473 , NULL ) ;
}
int F_121 ( struct V_209 * V_188 )
{
struct V_153 * V_154 = & V_188 -> V_189 ;
struct V_294 * V_295 = & V_154 -> V_295 ;
struct V_115 * V_104 = V_188 -> V_74 ;
unsigned V_33 , V_474 ;
int V_36 ;
V_154 -> V_475 = V_476 ;
F_122 ( & V_154 -> V_477 , sizeof( V_154 -> V_477 ) ) ;
V_154 -> V_478 = F_79 ( V_154 -> V_475 * sizeof * V_154 -> V_478 ,
V_416 ) ;
if ( ! V_154 -> V_478 ) {
V_36 = - V_67 ;
goto V_479;
}
for ( V_33 = 0 ; V_33 < V_154 -> V_475 ; V_33 ++ )
F_120 ( V_154 -> V_478 [ V_33 ] , NULL ) ;
for ( V_33 = 0 ; V_33 < V_188 -> V_395 ; V_33 ++ )
F_118 ( V_104 + V_33 ) ;
F_119 ( & V_154 -> V_480 ) ;
F_119 ( & V_154 -> V_417 ) ;
F_119 ( & V_154 -> V_434 ) ;
F_119 ( & V_154 -> V_481 ) ;
F_119 ( & V_154 -> V_482 ) ;
F_119 ( & V_154 -> V_483 ) ;
F_119 ( & V_154 -> V_484 ) ;
F_123 ( & V_154 -> F_42 ) ;
V_154 -> F_42 . V_485 = F_42 ;
V_154 -> F_42 . V_6 = ( unsigned long ) V_154 ;
F_124 ( V_188 , & V_154 -> V_486 ) ;
F_119 ( & V_154 -> V_70 . V_91 ) ;
V_154 -> V_70 . V_331 = 1 << V_487 ;
V_474 = V_154 -> V_70 . V_331 * sizeof( * V_154 -> V_70 . V_488 ) ;
V_154 -> V_70 . V_488 = (struct V_489 * * )
F_125 ( V_416 , F_126 ( V_474 ) ) ;
if ( V_154 -> V_70 . V_488 == NULL ) {
V_36 = - V_67 ;
goto V_490;
}
memset ( V_154 -> V_70 . V_488 , 0 , V_474 ) ;
F_127 ( & V_154 -> V_491 ) ;
F_119 ( & V_154 -> V_158 ) ;
V_154 -> V_492 = V_307 ;
F_119 ( & V_154 -> V_493 ) ;
F_127 ( & V_154 -> V_235 ) ;
F_127 ( & V_154 -> V_494 ) ;
F_127 ( & V_154 -> V_183 ) ;
F_127 ( & V_154 -> V_157 ) ;
F_127 ( & V_154 -> V_176 ) ;
if ( V_104 -> V_224 ) {
V_154 -> V_198 = F_128 ( & V_188 -> V_179 -> V_154 ,
V_104 -> V_224 *
sizeof( struct V_210 ) ,
& V_154 -> V_227 ,
V_416 ) ;
if ( ! V_154 -> V_198 ) {
V_36 = - V_67 ;
goto V_495;
}
}
for ( V_33 = 0 ; V_33 < V_104 -> V_224 ; V_33 ++ ) {
struct V_174 * V_175 ;
V_175 = F_129 ( sizeof *V_175 , V_416 ) ;
if ( ! V_175 ) {
V_36 = - V_67 ;
goto V_229;
}
V_175 -> V_199 = V_33 ;
F_64 ( & V_175 -> V_177 . V_156 , & V_154 -> V_176 ) ;
}
if ( ! V_317 )
V_317 = V_104 -> V_410 ;
F_130 ( V_295 -> V_496 , L_1 , V_497 ) ;
V_295 -> V_498 = V_499 ;
V_295 -> V_500 = V_104 -> V_410 ;
V_295 -> V_501 = V_502 ;
V_295 -> V_503 =
( 1ull << V_504 ) |
( 1ull << V_505 ) |
( 1ull << V_506 ) |
( 1ull << V_507 ) |
( 1ull << V_508 ) |
( 1ull << V_509 ) |
( 1ull << V_510 ) |
( 1ull << V_511 ) |
( 1ull << V_512 ) |
( 1ull << V_513 ) |
( 1ull << V_514 ) |
( 1ull << V_515 ) |
( 1ull << V_516 ) |
( 1ull << V_517 ) |
( 1ull << V_518 ) |
( 1ull << V_519 ) |
( 1ull << V_520 ) |
( 1ull << V_521 ) |
( 1ull << V_522 ) |
( 1ull << V_523 ) |
( 1ull << V_524 ) |
( 1ull << V_525 ) |
( 1ull << V_526 ) |
( 1ull << V_527 ) |
( 1ull << V_528 ) |
( 1ull << V_529 ) |
( 1ull << V_530 ) |
( 1ull << V_531 ) |
( 1ull << V_532 ) |
( 1ull << V_533 ) ;
V_295 -> V_534 = V_535 ;
V_295 -> V_428 = V_188 -> V_395 ;
V_295 -> V_536 = 1 ;
V_295 -> V_537 = & V_188 -> V_179 -> V_154 ;
V_295 -> V_538 = F_91 ;
V_295 -> V_539 = F_95 ;
V_295 -> V_540 = F_93 ;
V_295 -> V_541 = F_99 ;
V_295 -> V_542 = F_115 ;
V_295 -> V_543 = F_102 ;
V_295 -> V_544 = F_116 ;
V_295 -> V_545 = F_117 ;
V_295 -> V_546 = F_103 ;
V_295 -> V_547 = F_105 ;
V_295 -> V_548 = F_108 ;
V_295 -> V_549 = F_110 ;
V_295 -> V_550 = F_112 ;
V_295 -> V_551 = F_113 ;
V_295 -> V_552 = V_553 ;
V_295 -> V_554 = V_555 ;
V_295 -> V_556 = V_557 ;
V_295 -> V_558 = V_559 ;
V_295 -> V_560 = V_561 ;
V_295 -> V_562 = V_563 ;
V_295 -> V_564 = V_565 ;
V_295 -> V_566 = V_567 ;
V_295 -> V_568 = F_21 ;
V_295 -> V_569 = F_24 ;
V_295 -> V_570 = V_571 ;
V_295 -> V_572 = V_573 ;
V_295 -> V_574 = V_575 ;
V_295 -> V_576 = V_577 ;
V_295 -> V_578 = V_579 ;
V_295 -> V_580 = V_581 ;
V_295 -> V_582 = V_583 ;
V_295 -> V_584 = V_585 ;
V_295 -> V_586 = V_587 ;
V_295 -> V_588 = V_589 ;
V_295 -> V_590 = V_591 ;
V_295 -> V_592 = V_593 ;
V_295 -> V_594 = V_595 ;
V_295 -> V_596 = V_597 ;
V_295 -> V_598 = V_599 ;
V_295 -> V_600 = V_601 ;
V_295 -> V_602 = V_603 ;
V_295 -> V_604 = V_605 ;
V_295 -> V_606 = V_607 ;
V_295 -> V_608 = V_609 ;
V_295 -> V_610 = V_611 ;
V_295 -> V_612 = & V_613 ;
snprintf ( V_295 -> V_394 , sizeof( V_295 -> V_394 ) ,
V_614 L_2 , F_131 () -> V_615 ) ;
V_36 = F_132 ( V_295 , V_616 ) ;
if ( V_36 )
goto V_617;
V_36 = F_133 ( V_154 ) ;
if ( V_36 )
goto V_618;
if ( F_134 ( V_188 ) )
goto V_619;
goto V_68;
V_619:
F_135 ( V_154 ) ;
V_618:
F_136 ( V_295 ) ;
V_617:
V_229:
while ( ! F_43 ( & V_154 -> V_176 ) ) {
struct V_155 * V_130 = V_154 -> V_176 . V_32 ;
struct V_174 * V_175 ;
F_58 ( V_130 ) ;
V_175 = F_44 ( V_130 , struct V_174 , V_177 . V_156 ) ;
F_63 ( V_175 ) ;
}
if ( V_104 -> V_224 )
F_137 ( & V_188 -> V_179 -> V_154 ,
V_104 -> V_224 *
sizeof( struct V_210 ) ,
V_154 -> V_198 , V_154 -> V_227 ) ;
V_495:
F_138 ( ( unsigned long ) V_154 -> V_70 . V_488 , F_126 ( V_474 ) ) ;
V_490:
F_63 ( V_154 -> V_478 ) ;
V_479:
F_139 ( V_188 , L_3 , - V_36 ) ;
V_68:
return V_36 ;
}
void F_140 ( struct V_209 * V_188 )
{
struct V_153 * V_154 = & V_188 -> V_189 ;
struct V_294 * V_295 = & V_154 -> V_295 ;
T_1 V_620 ;
unsigned V_474 ;
F_141 ( V_188 ) ;
F_135 ( V_154 ) ;
F_136 ( V_295 ) ;
if ( ! F_43 ( & V_154 -> V_235 ) )
F_139 ( V_188 , L_4 ) ;
if ( ! F_43 ( & V_154 -> V_494 ) )
F_139 ( V_188 , L_5 ) ;
if ( ! F_43 ( & V_154 -> V_183 ) )
F_139 ( V_188 , L_6 ) ;
if ( ! F_43 ( & V_154 -> V_157 ) )
F_139 ( V_188 , L_7 ) ;
if ( V_154 -> V_621 )
F_139 ( V_188 , L_8 ) ;
V_620 = F_142 ( V_188 ) ;
if ( V_620 )
F_139 ( V_188 , L_9 ,
V_620 ) ;
F_143 ( & V_154 -> F_42 ) ;
F_144 ( & V_154 -> V_486 ) ;
while ( ! F_43 ( & V_154 -> V_176 ) ) {
struct V_155 * V_130 = V_154 -> V_176 . V_32 ;
struct V_174 * V_175 ;
F_58 ( V_130 ) ;
V_175 = F_44 ( V_130 , struct V_174 , V_177 . V_156 ) ;
F_63 ( V_175 ) ;
}
if ( V_188 -> V_74 -> V_224 )
F_137 ( & V_188 -> V_179 -> V_154 ,
V_188 -> V_74 -> V_224 *
sizeof( struct V_210 ) ,
V_154 -> V_198 , V_154 -> V_227 ) ;
V_474 = V_154 -> V_70 . V_331 * sizeof( * V_154 -> V_70 . V_488 ) ;
F_138 ( ( unsigned long ) V_154 -> V_70 . V_488 ,
F_126 ( V_474 ) ) ;
F_63 ( V_154 -> V_478 ) ;
}
