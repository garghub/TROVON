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
V_27 = F_40 ( V_103 , V_118 ) ;
if ( ! V_27 )
goto V_121;
V_103 -> V_150 ++ ;
F_27 ( V_97 , V_99 , V_119 == V_128 , V_6 , V_101 , V_27 ) ;
if ( F_41 ( & V_27 -> V_15 ) )
F_39 ( & V_27 -> V_149 ) ;
}
return;
V_121:
V_103 -> V_108 ++ ;
}
static void F_42 ( unsigned long V_6 )
{
struct V_151 * V_152 = (struct V_151 * ) V_6 ;
struct V_153 * V_154 = & V_152 -> V_155 ;
struct V_26 * V_27 = NULL ;
unsigned long V_37 ;
F_10 ( & V_152 -> V_156 , V_37 ) ;
if ( ! F_43 ( V_154 ) ) {
V_27 = F_44 ( V_154 -> V_32 , struct V_26 , V_157 ) ;
F_45 ( & V_27 -> V_157 ) ;
F_18 ( & V_27 -> V_15 ) ;
if ( ! F_43 ( V_154 ) )
F_46 ( & V_152 -> F_42 , V_158 + 1 ) ;
}
F_20 ( & V_152 -> V_156 , V_37 ) ;
if ( V_27 ) {
F_10 ( & V_27 -> V_42 , V_37 ) ;
if ( V_27 -> V_159 & V_160 ) {
V_27 -> V_159 &= ~ V_160 ;
F_47 ( V_27 ) ;
}
F_20 ( & V_27 -> V_42 , V_37 ) ;
if ( F_41 ( & V_27 -> V_15 ) )
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
static inline T_1 F_49 ( T_1 V_6 , T_1 V_161 )
{
return V_6 >> V_161 ;
}
static inline T_1 F_50 ( T_1 V_6 , T_1 V_161 )
{
return V_6 << V_161 ;
}
static inline T_1 F_51 ( T_1 V_6 , T_1 V_19 , T_1 V_162 )
{
V_6 <<= ( ( sizeof( T_1 ) - V_19 ) * V_163 ) ;
V_6 >>= ( ( sizeof( T_1 ) - V_19 - V_162 ) * V_163 ) ;
return V_6 ;
}
static inline T_1 F_49 ( T_1 V_6 , T_1 V_161 )
{
return V_6 << V_161 ;
}
static inline T_1 F_50 ( T_1 V_6 , T_1 V_161 )
{
return V_6 >> V_161 ;
}
static inline T_1 F_51 ( T_1 V_6 , T_1 V_19 , T_1 V_162 )
{
V_6 >>= ( ( sizeof( T_1 ) - V_19 ) * V_163 ) ;
V_6 <<= ( ( sizeof( T_1 ) - V_19 - V_162 ) * V_163 ) ;
return V_6 ;
}
static void F_52 ( T_1 T_4 * V_164 , struct V_4 * V_5 ,
T_1 V_7 , unsigned V_165 )
{
T_1 V_166 = 0 ;
T_1 V_6 = 0 ;
T_1 V_167 ;
while ( 1 ) {
T_1 V_11 = V_5 -> V_10 . V_7 ;
T_1 V_162 ;
if ( V_11 > V_7 )
V_11 = V_7 ;
if ( V_11 > V_5 -> V_10 . V_12 )
V_11 = V_5 -> V_10 . V_12 ;
F_4 ( V_11 == 0 ) ;
V_162 = ( unsigned long ) V_5 -> V_10 . V_13 & ( sizeof( T_1 ) - 1 ) ;
if ( V_162 ) {
T_1 * V_62 = ( T_1 * ) ( ( unsigned long ) V_5 -> V_10 . V_13 &
~ ( sizeof( T_1 ) - 1 ) ) ;
T_1 V_168 = F_49 ( * V_62 , V_162 * V_163 ) ;
T_1 V_169 ;
V_169 = sizeof( T_1 ) - V_162 ;
if ( V_11 > V_169 )
V_11 = V_169 ;
if ( V_11 + V_166 >= sizeof( T_1 ) ) {
V_6 |= F_50 ( V_168 , V_166 *
V_163 ) ;
V_11 = sizeof( T_1 ) - V_166 ;
if ( V_11 == V_7 ) {
V_167 = V_6 ;
break;
}
F_53 ( V_6 , V_164 ) ;
V_164 ++ ;
V_166 = 0 ;
V_6 = 0 ;
} else {
V_6 |= F_51 ( V_168 , V_11 , V_166 ) ;
if ( V_11 == V_7 ) {
V_167 = V_6 ;
break;
}
V_166 += V_11 ;
}
} else if ( V_166 ) {
T_1 * V_62 = ( T_1 * ) V_5 -> V_10 . V_13 ;
int V_161 = V_166 * V_163 ;
int V_170 = 32 - V_161 ;
T_1 V_130 = V_11 ;
while ( V_130 >= sizeof( T_1 ) ) {
T_1 V_168 = * V_62 ;
V_6 |= F_50 ( V_168 , V_161 ) ;
F_53 ( V_6 , V_164 ) ;
V_6 = F_49 ( V_168 , V_170 ) ;
V_164 ++ ;
V_62 ++ ;
V_130 -= sizeof( T_1 ) ;
}
if ( V_130 ) {
T_1 V_168 = * V_62 ;
if ( V_130 + V_166 >= sizeof( T_1 ) ) {
V_6 |= F_50 ( V_168 , V_161 ) ;
V_11 -= V_130 + V_166 - sizeof( T_1 ) ;
if ( V_11 == V_7 ) {
V_167 = V_6 ;
break;
}
F_53 ( V_6 , V_164 ) ;
V_164 ++ ;
V_166 = 0 ;
V_6 = 0 ;
} else {
V_6 |= F_51 ( V_168 , V_130 , V_166 ) ;
if ( V_11 == V_7 ) {
V_167 = V_6 ;
break;
}
V_166 += V_130 ;
}
} else if ( V_11 == V_7 ) {
V_167 = V_6 ;
break;
}
} else if ( V_11 == V_7 ) {
T_1 V_171 ;
V_171 = ( V_11 + 3 ) >> 2 ;
F_54 ( V_164 , V_5 -> V_10 . V_13 , V_171 - 1 ) ;
V_164 += V_171 - 1 ;
V_167 = ( ( T_1 * ) V_5 -> V_10 . V_13 ) [ V_171 - 1 ] ;
break;
} else {
T_1 V_171 = V_11 >> 2 ;
F_54 ( V_164 , V_5 -> V_10 . V_13 , V_171 ) ;
V_164 += V_171 ;
V_166 = V_11 & ( sizeof( T_1 ) - 1 ) ;
if ( V_166 ) {
T_1 V_168 = ( ( T_1 * ) V_5 -> V_10 . V_13 ) [ V_171 ] ;
V_6 = F_51 ( V_168 , V_166 , 0 ) ;
}
}
F_48 ( V_5 , V_11 ) ;
V_7 -= V_11 ;
}
F_48 ( V_5 , V_7 ) ;
if ( V_165 ) {
F_55 () ;
F_53 ( V_167 , V_164 ) ;
F_55 () ;
} else
F_53 ( V_167 , V_164 ) ;
}
static struct V_172 * F_56 ( struct V_151 * V_152 ,
struct V_26 * V_27 , int * V_173 )
{
struct V_172 * V_174 ;
unsigned long V_37 ;
F_10 ( & V_27 -> V_42 , V_37 ) ;
F_28 ( & V_152 -> V_156 ) ;
if ( ! F_43 ( & V_152 -> V_175 ) ) {
struct V_153 * V_130 = V_152 -> V_175 . V_32 ;
F_57 ( V_130 ) ;
V_174 = F_44 ( V_130 , struct V_172 , V_176 . V_154 ) ;
* V_173 = 0 ;
} else {
if ( V_43 [ V_27 -> V_44 ] & V_107 &&
F_43 ( & V_27 -> V_157 ) ) {
V_152 -> V_177 ++ ;
V_27 -> V_159 |= V_178 ;
F_58 ( & V_27 -> V_157 , & V_152 -> V_179 ) ;
}
V_174 = NULL ;
V_27 -> V_159 &= ~ V_180 ;
* V_173 = - V_181 ;
}
F_32 ( & V_152 -> V_156 ) ;
F_20 ( & V_27 -> V_42 , V_37 ) ;
return V_174 ;
}
void F_59 ( struct V_172 * V_174 )
{
struct V_151 * V_152 ;
struct V_26 * V_27 ;
unsigned long V_37 ;
V_27 = V_174 -> V_27 ;
V_152 = F_13 ( V_27 -> V_50 . V_69 ) ;
if ( F_41 ( & V_27 -> V_15 ) )
F_39 ( & V_27 -> V_149 ) ;
if ( V_174 -> V_14 ) {
F_5 ( & V_174 -> V_14 -> V_15 ) ;
V_174 -> V_14 = NULL ;
}
if ( V_174 -> V_176 . V_37 & V_182 ) {
V_174 -> V_176 . V_37 &= ~ V_182 ;
F_60 ( & F_61 ( V_152 ) -> V_183 -> V_152 ,
V_174 -> V_176 . V_62 , V_174 -> V_184 << 2 ,
V_185 ) ;
F_62 ( V_174 -> V_186 ) ;
}
F_10 ( & V_152 -> V_156 , V_37 ) ;
F_63 ( & V_174 -> V_176 . V_154 , & V_152 -> V_175 ) ;
if ( ! F_43 ( & V_152 -> V_179 ) ) {
V_27 = F_44 ( V_152 -> V_179 . V_32 , struct V_26 , V_157 ) ;
F_45 ( & V_27 -> V_157 ) ;
F_18 ( & V_27 -> V_15 ) ;
F_20 ( & V_152 -> V_156 , V_37 ) ;
F_10 ( & V_27 -> V_42 , V_37 ) ;
if ( V_27 -> V_159 & V_178 ) {
V_27 -> V_159 &= ~ V_178 ;
F_47 ( V_27 ) ;
}
F_20 ( & V_27 -> V_42 , V_37 ) ;
if ( F_41 ( & V_27 -> V_15 ) )
F_39 ( & V_27 -> V_149 ) ;
} else
F_20 ( & V_152 -> V_156 , V_37 ) ;
}
void F_64 ( struct V_115 * V_104 , unsigned V_187 )
{
struct V_26 * V_27 , * V_188 ;
struct V_26 * V_189 [ 20 ] ;
struct V_151 * V_152 ;
unsigned V_33 , V_19 ;
V_19 = 0 ;
V_152 = & V_104 -> V_190 -> V_191 ;
F_28 ( & V_152 -> V_156 ) ;
F_65 (qp, nqp, &dev->dmawait, iowait) {
if ( V_27 -> V_75 != V_104 -> V_192 )
continue;
if ( V_19 == F_66 ( V_189 ) )
break;
if ( V_27 -> V_193 -> V_176 . V_194 > V_187 )
break;
V_187 -= V_27 -> V_193 -> V_176 . V_194 ;
F_45 ( & V_27 -> V_157 ) ;
F_18 ( & V_27 -> V_15 ) ;
V_189 [ V_19 ++ ] = V_27 ;
}
F_32 ( & V_152 -> V_156 ) ;
for ( V_33 = 0 ; V_33 < V_19 ; V_33 ++ ) {
V_27 = V_189 [ V_33 ] ;
F_28 ( & V_27 -> V_42 ) ;
if ( V_27 -> V_159 & V_195 ) {
V_27 -> V_159 &= ~ V_195 ;
F_47 ( V_27 ) ;
}
F_32 ( & V_27 -> V_42 ) ;
if ( F_41 ( & V_27 -> V_15 ) )
F_39 ( & V_27 -> V_149 ) ;
}
}
static void F_67 ( struct V_196 * V_197 , int V_198 )
{
struct V_172 * V_174 =
F_2 ( V_197 , struct V_172 , V_176 ) ;
struct V_26 * V_27 = V_174 -> V_27 ;
F_28 ( & V_27 -> V_42 ) ;
if ( V_174 -> V_31 )
F_68 ( V_27 , V_174 -> V_31 , V_199 ) ;
else if ( V_27 -> V_50 . V_51 == V_54 ) {
struct V_98 * V_99 ;
if ( V_174 -> V_176 . V_37 & V_182 )
V_99 = & V_174 -> V_186 -> V_99 ;
else {
struct V_151 * V_152 = F_13 ( V_27 -> V_50 . V_69 ) ;
V_99 = & V_152 -> V_200 [ V_174 -> V_201 ] . V_99 ;
}
F_69 ( V_27 , V_99 ) ;
}
if ( F_41 ( & V_27 -> V_202 ) ) {
if ( V_27 -> V_44 == V_203 )
F_39 ( & V_27 -> V_204 ) ;
else if ( V_27 -> V_159 & V_205 ) {
V_27 -> V_159 &= ~ V_205 ;
F_47 ( V_27 ) ;
}
}
F_32 ( & V_27 -> V_42 ) ;
F_59 ( V_174 ) ;
}
static int F_70 ( struct V_151 * V_152 , struct V_26 * V_27 )
{
unsigned long V_37 ;
int V_36 = 0 ;
F_10 ( & V_27 -> V_42 , V_37 ) ;
if ( V_43 [ V_27 -> V_44 ] & V_107 ) {
F_28 ( & V_152 -> V_156 ) ;
if ( F_43 ( & V_27 -> V_157 ) ) {
if ( F_43 ( & V_152 -> V_155 ) )
F_46 ( & V_152 -> F_42 , V_158 + 1 ) ;
V_27 -> V_159 |= V_160 ;
F_58 ( & V_27 -> V_157 , & V_152 -> V_155 ) ;
}
F_32 ( & V_152 -> V_156 ) ;
V_27 -> V_159 &= ~ V_180 ;
V_36 = - V_181 ;
}
F_20 ( & V_27 -> V_42 , V_37 ) ;
return V_36 ;
}
static int F_71 ( struct V_26 * V_27 , struct V_98 * V_99 ,
T_1 V_206 , struct V_4 * V_5 , T_1 V_11 ,
T_1 V_207 , T_1 V_208 )
{
struct V_151 * V_152 = F_13 ( V_27 -> V_50 . V_69 ) ;
struct V_209 * V_190 = F_61 ( V_152 ) ;
struct V_102 * V_103 = F_72 ( V_27 -> V_50 . V_69 , V_27 -> V_75 ) ;
struct V_115 * V_104 = F_73 ( V_103 ) ;
struct V_172 * V_174 ;
struct V_210 * V_211 ;
T_1 V_212 ;
T_1 V_25 ;
int V_36 ;
V_174 = V_27 -> V_193 ;
if ( V_174 ) {
V_27 -> V_193 = NULL ;
V_36 = F_74 ( V_104 , V_174 -> V_5 , V_174 -> V_208 , V_174 ) ;
goto V_68;
}
V_174 = F_56 ( V_152 , V_27 , & V_36 ) ;
if ( ! V_174 )
goto V_68;
V_212 = V_190 -> V_213 ( V_104 , V_207 , V_27 -> V_214 ,
F_34 ( V_99 -> V_122 [ 0 ] ) >> 12 ) ;
V_174 -> V_27 = V_27 ;
F_18 ( & V_27 -> V_15 ) ;
V_174 -> V_31 = V_27 -> V_215 ;
V_174 -> V_14 = V_27 -> V_216 ;
if ( V_27 -> V_216 )
V_27 -> V_216 = NULL ;
V_174 -> V_176 . V_217 = F_67 ;
if ( V_190 -> V_37 & V_218 )
V_174 -> V_176 . V_37 = V_219 ;
else
V_174 -> V_176 . V_37 = V_220 ;
if ( V_207 + 1 > V_190 -> V_221 )
V_174 -> V_176 . V_37 |= V_222 ;
if ( V_11 ) {
V_25 = F_7 ( V_5 , V_11 ) ;
if ( V_25 >= V_104 -> V_223 )
V_25 = 0 ;
} else
V_25 = 1 ;
if ( V_25 ) {
V_211 = & V_152 -> V_200 [ V_174 -> V_201 ] ;
V_211 -> V_224 [ 0 ] = F_75 ( V_207 ) ;
V_211 -> V_224 [ 1 ] = F_75 ( V_212 ) ;
memcpy ( & V_211 -> V_99 , V_99 , V_206 << 2 ) ;
V_174 -> V_176 . V_37 |= V_225 ;
V_174 -> V_176 . V_194 = V_25 ;
V_174 -> V_176 . V_62 = V_152 -> V_226 +
V_174 -> V_201 * sizeof( struct V_210 ) ;
V_174 -> V_184 = V_206 + 2 ;
V_36 = F_74 ( V_104 , V_5 , V_208 , V_174 ) ;
goto V_68;
}
V_174 -> V_184 = V_207 + 1 ;
V_211 = F_76 ( V_174 -> V_184 << 2 , V_227 ) ;
if ( ! V_211 )
goto V_228;
V_211 -> V_224 [ 0 ] = F_75 ( V_207 ) ;
V_211 -> V_224 [ 1 ] = F_75 ( V_212 ) ;
memcpy ( & V_211 -> V_99 , V_99 , V_206 << 2 ) ;
F_8 ( ( T_1 * ) & V_211 -> V_99 + V_206 , V_5 , V_11 ) ;
V_174 -> V_176 . V_62 = F_77 ( & V_190 -> V_183 -> V_152 , V_211 ,
V_174 -> V_184 << 2 , V_185 ) ;
if ( F_78 ( & V_190 -> V_183 -> V_152 , V_174 -> V_176 . V_62 ) )
goto V_229;
V_174 -> V_186 = V_211 ;
V_174 -> V_176 . V_37 |= V_182 ;
V_174 -> V_176 . V_194 = 1 ;
V_36 = F_74 ( V_104 , NULL , 0 , V_174 ) ;
goto V_230;
V_229:
F_62 ( V_211 ) ;
V_228:
F_59 ( V_174 ) ;
V_36 = F_70 ( V_152 , V_27 ) ;
V_230:
V_103 -> V_231 ++ ;
V_68:
return V_36 ;
}
static int F_79 ( struct V_26 * V_27 )
{
struct V_151 * V_152 = F_13 ( V_27 -> V_50 . V_69 ) ;
struct V_209 * V_190 ;
unsigned long V_37 ;
int V_36 = 0 ;
F_10 ( & V_27 -> V_42 , V_37 ) ;
if ( V_43 [ V_27 -> V_44 ] & V_107 ) {
F_28 ( & V_152 -> V_156 ) ;
if ( F_43 ( & V_27 -> V_157 ) ) {
V_152 -> V_232 ++ ;
V_27 -> V_159 |= V_233 ;
F_58 ( & V_27 -> V_157 , & V_152 -> V_234 ) ;
V_190 = F_61 ( V_152 ) ;
V_190 -> V_235 ( V_190 , 1 ) ;
}
F_32 ( & V_152 -> V_156 ) ;
V_27 -> V_159 &= ~ V_180 ;
V_36 = - V_181 ;
}
F_20 ( & V_27 -> V_42 , V_37 ) ;
return V_36 ;
}
static int F_80 ( struct V_26 * V_27 , struct V_98 * V_236 ,
T_1 V_206 , struct V_4 * V_5 , T_1 V_11 ,
T_1 V_207 , T_1 V_208 )
{
struct V_209 * V_190 = F_17 ( V_27 -> V_50 . V_69 ) ;
struct V_115 * V_104 = V_190 -> V_74 + V_27 -> V_75 - 1 ;
T_1 * V_99 = ( T_1 * ) V_236 ;
T_1 T_4 * V_237 ;
T_1 T_4 * V_164 ;
V_61 V_224 ;
unsigned long V_37 ;
unsigned V_165 ;
T_1 V_212 ;
T_1 V_238 ;
V_212 = V_190 -> V_213 ( V_104 , V_207 , V_27 -> V_214 ,
F_34 ( V_236 -> V_122 [ 0 ] ) >> 12 ) ;
V_224 = ( ( V_61 ) V_212 << 32 ) | V_207 ;
V_164 = V_190 -> V_239 ( V_104 , V_224 , & V_238 ) ;
if ( F_11 ( V_164 == NULL ) )
return F_79 ( V_27 ) ;
F_81 ( V_224 , V_164 ) ;
V_237 = V_164 ;
V_164 += 2 ;
V_165 = V_190 -> V_37 & V_240 ;
if ( V_11 == 0 ) {
if ( V_165 ) {
F_55 () ;
F_54 ( V_164 , V_99 , V_206 - 1 ) ;
F_55 () ;
F_53 ( V_99 [ V_206 - 1 ] , V_164 + V_206 - 1 ) ;
F_55 () ;
} else
F_54 ( V_164 , V_99 , V_206 ) ;
goto V_241;
}
if ( V_165 )
F_55 () ;
F_54 ( V_164 , V_99 , V_206 ) ;
V_164 += V_206 ;
if ( F_82 ( V_5 -> V_16 == 1 && V_11 <= V_5 -> V_10 . V_7 &&
! ( ( unsigned long ) V_5 -> V_10 . V_13 & ( sizeof( T_1 ) - 1 ) ) ) ) {
T_1 * V_62 = ( T_1 * ) V_5 -> V_10 . V_13 ;
F_48 ( V_5 , V_11 ) ;
if ( V_165 ) {
F_54 ( V_164 , V_62 , V_208 - 1 ) ;
F_55 () ;
F_53 ( V_62 [ V_208 - 1 ] , V_164 + V_208 - 1 ) ;
F_55 () ;
} else
F_54 ( V_164 , V_62 , V_208 ) ;
goto V_241;
}
F_52 ( V_164 , V_5 , V_11 , V_165 ) ;
V_241:
if ( V_190 -> V_37 & V_242 ) {
T_1 V_243 = ( V_238 >= V_190 -> V_244 ) ? 2047 : 1023 ;
F_55 () ;
F_53 ( 0xaebecede , V_237 + V_243 ) ;
}
F_83 ( V_190 , V_238 ) ;
if ( V_27 -> V_216 ) {
F_5 ( & V_27 -> V_216 -> V_15 ) ;
V_27 -> V_216 = NULL ;
}
if ( V_27 -> V_215 ) {
F_10 ( & V_27 -> V_42 , V_37 ) ;
F_68 ( V_27 , V_27 -> V_215 , V_199 ) ;
F_20 ( & V_27 -> V_42 , V_37 ) ;
} else if ( V_27 -> V_50 . V_51 == V_54 ) {
F_10 ( & V_27 -> V_42 , V_37 ) ;
F_69 ( V_27 , V_236 ) ;
F_20 ( & V_27 -> V_42 , V_37 ) ;
}
return 0 ;
}
int F_84 ( struct V_26 * V_27 , struct V_98 * V_99 ,
T_1 V_206 , struct V_4 * V_5 , T_1 V_11 )
{
struct V_209 * V_190 = F_17 ( V_27 -> V_50 . V_69 ) ;
T_1 V_207 ;
int V_36 ;
T_1 V_208 = ( V_11 + 3 ) >> 2 ;
V_207 = V_206 + V_208 + 1 ;
if ( V_27 -> V_50 . V_51 == V_110 ||
! ( V_190 -> V_37 & V_245 ) )
V_36 = F_80 ( V_27 , V_99 , V_206 , V_5 , V_11 ,
V_207 , V_208 ) ;
else
V_36 = F_71 ( V_27 , V_99 , V_206 , V_5 , V_11 ,
V_207 , V_208 ) ;
return V_36 ;
}
int F_85 ( struct V_115 * V_104 , V_61 * V_246 ,
V_61 * V_247 , V_61 * V_248 , V_61 * V_249 ,
V_61 * V_250 )
{
int V_36 ;
struct V_209 * V_190 = V_104 -> V_190 ;
if ( ! ( V_190 -> V_37 & V_251 ) ) {
V_36 = - V_79 ;
goto V_68;
}
* V_246 = V_190 -> V_252 ( V_104 , V_253 ) ;
* V_247 = V_190 -> V_252 ( V_104 , V_254 ) ;
* V_248 = V_190 -> V_252 ( V_104 , V_255 ) ;
* V_249 = V_190 -> V_252 ( V_104 , V_256 ) ;
* V_250 = V_190 -> V_252 ( V_104 , V_257 ) ;
V_36 = 0 ;
V_68:
return V_36 ;
}
int F_86 ( struct V_115 * V_104 ,
struct V_258 * V_259 )
{
int V_36 ;
if ( ! ( V_104 -> V_190 -> V_37 & V_251 ) ) {
V_36 = - V_79 ;
goto V_68;
}
V_259 -> V_260 =
V_104 -> V_190 -> V_252 ( V_104 , V_261 ) ;
V_259 -> V_262 =
V_104 -> V_190 -> V_252 ( V_104 , V_263 ) ;
V_259 -> V_264 =
V_104 -> V_190 -> V_252 ( V_104 , V_265 ) ;
V_259 -> V_266 =
V_104 -> V_190 -> V_252 ( V_104 , V_267 ) +
V_104 -> V_190 -> V_252 ( V_104 , V_268 ) +
V_104 -> V_190 -> V_252 ( V_104 , V_269 ) +
V_104 -> V_190 -> V_252 ( V_104 , V_270 ) +
V_104 -> V_190 -> V_252 ( V_104 , V_271 ) +
V_104 -> V_190 -> V_252 ( V_104 , V_272 ) +
V_104 -> V_190 -> V_252 ( V_104 , V_273 ) +
V_104 -> V_190 -> V_252 ( V_104 , V_274 ) +
V_104 -> V_190 -> V_252 ( V_104 , V_275 ) ;
V_259 -> V_266 +=
V_104 -> V_190 -> V_252 ( V_104 , V_276 ) ;
V_259 -> V_266 +=
V_104 -> V_190 -> V_252 ( V_104 , V_277 ) ;
V_259 -> V_278 =
V_104 -> V_190 -> V_252 ( V_104 , V_279 ) ;
V_259 -> V_280 =
V_104 -> V_190 -> V_252 ( V_104 , V_281 ) ;
V_259 -> V_282 = V_104 -> V_190 -> V_252 ( V_104 ,
V_253 ) ;
V_259 -> V_283 = V_104 -> V_190 -> V_252 ( V_104 ,
V_254 ) ;
V_259 -> V_284 = V_104 -> V_190 -> V_252 ( V_104 ,
V_255 ) ;
V_259 -> V_285 = V_104 -> V_190 -> V_252 ( V_104 ,
V_256 ) ;
V_259 -> V_286 =
V_104 -> V_190 -> V_252 ( V_104 , V_287 ) ;
V_259 -> V_288 =
V_104 -> V_190 -> V_252 ( V_104 , V_289 ) ;
V_259 -> V_290 =
V_104 -> V_190 -> V_252 ( V_104 , V_291 ) ;
V_36 = 0 ;
V_68:
return V_36 ;
}
void F_87 ( struct V_209 * V_190 )
{
struct V_151 * V_152 = & V_190 -> V_191 ;
struct V_153 * V_154 ;
struct V_26 * V_189 [ 5 ] ;
struct V_26 * V_27 ;
unsigned long V_37 ;
unsigned V_33 , V_19 ;
V_154 = & V_152 -> V_234 ;
V_19 = 0 ;
F_10 ( & V_152 -> V_156 , V_37 ) ;
while ( ! F_43 ( V_154 ) ) {
if ( V_19 == F_66 ( V_189 ) )
goto V_292;
V_27 = F_44 ( V_154 -> V_32 , struct V_26 , V_157 ) ;
F_45 ( & V_27 -> V_157 ) ;
F_18 ( & V_27 -> V_15 ) ;
V_189 [ V_19 ++ ] = V_27 ;
}
V_190 -> V_235 ( V_190 , 0 ) ;
V_292:
F_20 ( & V_152 -> V_156 , V_37 ) ;
for ( V_33 = 0 ; V_33 < V_19 ; V_33 ++ ) {
V_27 = V_189 [ V_33 ] ;
F_10 ( & V_27 -> V_42 , V_37 ) ;
if ( V_27 -> V_159 & V_233 ) {
V_27 -> V_159 &= ~ V_233 ;
F_47 ( V_27 ) ;
}
F_20 ( & V_27 -> V_42 , V_37 ) ;
if ( F_41 ( & V_27 -> V_15 ) )
F_39 ( & V_27 -> V_149 ) ;
}
}
static int F_88 ( struct V_293 * V_294 ,
struct V_295 * V_296 )
{
struct V_209 * V_190 = F_17 ( V_294 ) ;
struct V_151 * V_152 = F_13 ( V_294 ) ;
memset ( V_296 , 0 , sizeof( * V_296 ) ) ;
V_296 -> V_297 = V_298 |
V_299 | V_300 |
V_301 | V_302 |
V_303 | V_304 ;
V_296 -> V_305 = V_306 ;
V_296 -> V_307 =
V_308 << 16 | V_309 << 8 | V_310 ;
V_296 -> V_311 = V_190 -> V_312 ;
V_296 -> V_313 = V_190 -> V_314 ;
V_296 -> V_315 = V_316 ;
V_296 -> V_317 = ~ 0ULL ;
V_296 -> V_318 = V_319 ;
V_296 -> V_320 = V_321 ;
V_296 -> V_90 = V_322 ;
V_296 -> V_323 = V_324 ;
V_296 -> V_325 = V_326 ;
V_296 -> V_327 = V_328 ;
V_296 -> V_329 = V_152 -> V_70 . V_330 ;
V_296 -> V_331 = V_152 -> V_70 . V_330 ;
V_296 -> V_332 = 32767 ;
V_296 -> V_333 = V_334 ;
V_296 -> V_335 = V_336 ;
V_296 -> V_337 = 255 ;
V_296 -> V_338 = V_339 ;
V_296 -> V_340 = V_341 ;
V_296 -> V_342 = V_343 ;
V_296 -> V_344 = V_345 ;
V_296 -> V_346 = F_89 ( V_190 ) ;
V_296 -> V_347 = V_348 ;
V_296 -> V_349 = V_350 ;
V_296 -> V_351 = V_296 -> V_349 *
V_296 -> V_347 ;
return 0 ;
}
static int F_90 ( struct V_293 * V_294 , T_2 V_192 ,
struct V_352 * V_296 )
{
struct V_209 * V_190 = F_17 ( V_294 ) ;
struct V_102 * V_103 = F_72 ( V_294 , V_192 ) ;
struct V_115 * V_104 = F_73 ( V_103 ) ;
enum V_353 V_354 ;
T_3 V_120 = V_104 -> V_120 ;
memset ( V_296 , 0 , sizeof( * V_296 ) ) ;
V_296 -> V_120 = V_120 ? V_120 : F_34 ( V_355 ) ;
V_296 -> V_124 = V_104 -> V_124 ;
V_296 -> V_356 = V_103 -> V_356 ;
V_296 -> V_357 = V_103 -> V_357 ;
V_296 -> V_44 = V_190 -> V_358 ( V_104 -> V_359 ) ;
V_296 -> V_360 = V_190 -> V_361 ( V_104 -> V_359 ) ;
V_296 -> V_362 = V_103 -> V_362 ;
V_296 -> V_363 = V_364 ;
V_296 -> V_365 = 0x80000000 ;
V_296 -> V_366 = F_89 ( V_190 ) ;
V_296 -> V_367 = V_103 -> V_368 ;
V_296 -> V_369 = V_103 -> V_370 ;
V_296 -> V_371 = V_104 -> V_372 ;
V_296 -> V_373 = V_104 -> V_374 ;
V_296 -> V_375 = F_91 ( V_104 -> V_376 ) ;
V_296 -> V_377 = 0 ;
V_296 -> V_378 = V_379 ? V_379 : V_380 ;
switch ( V_104 -> V_76 ) {
case 4096 :
V_354 = V_380 ;
break;
case 2048 :
V_354 = V_381 ;
break;
case 1024 :
V_354 = V_382 ;
break;
case 512 :
V_354 = V_383 ;
break;
case 256 :
V_354 = V_384 ;
break;
default:
V_354 = V_381 ;
}
V_296 -> V_385 = V_354 ;
V_296 -> V_386 = V_103 -> V_386 ;
return 0 ;
}
static int F_92 ( struct V_293 * V_69 ,
int V_387 ,
struct V_388 * V_389 )
{
struct V_209 * V_190 = F_17 ( V_69 ) ;
unsigned V_33 ;
int V_36 ;
if ( V_387 & ~ ( V_390 |
V_391 ) ) {
V_36 = - V_392 ;
goto V_68;
}
if ( V_387 & V_391 ) {
memcpy ( V_69 -> V_393 , V_389 -> V_393 , 64 ) ;
for ( V_33 = 0 ; V_33 < V_190 -> V_394 ; V_33 ++ ) {
struct V_102 * V_103 = & V_190 -> V_74 [ V_33 ] . V_105 ;
F_93 ( V_103 ) ;
}
}
if ( V_387 & V_390 ) {
V_316 =
F_94 ( V_389 -> V_315 ) ;
for ( V_33 = 0 ; V_33 < V_190 -> V_394 ; V_33 ++ ) {
struct V_102 * V_103 = & V_190 -> V_74 [ V_33 ] . V_105 ;
F_95 ( V_103 ) ;
}
}
V_36 = 0 ;
V_68:
return V_36 ;
}
static int F_96 ( struct V_293 * V_294 , T_2 V_192 ,
int V_395 , struct V_396 * V_296 )
{
struct V_102 * V_103 = F_72 ( V_294 , V_192 ) ;
struct V_115 * V_104 = F_73 ( V_103 ) ;
V_103 -> V_362 |= V_296 -> V_397 ;
V_103 -> V_362 &= ~ V_296 -> V_398 ;
if ( V_296 -> V_397 || V_296 -> V_398 )
F_97 ( V_103 ) ;
if ( V_395 & V_399 )
F_98 ( V_104 , V_400 ) ;
if ( V_395 & V_401 )
V_103 -> V_370 = 0 ;
return 0 ;
}
static int F_99 ( struct V_293 * V_294 , T_2 V_192 ,
int V_402 , union V_403 * V_404 )
{
struct V_209 * V_190 = F_17 ( V_294 ) ;
int V_36 = 0 ;
if ( ! V_192 || V_192 > V_190 -> V_394 )
V_36 = - V_79 ;
else {
struct V_102 * V_103 = F_72 ( V_294 , V_192 ) ;
struct V_115 * V_104 = F_73 ( V_103 ) ;
V_404 -> V_405 . V_406 = V_103 -> V_407 ;
if ( V_402 == 0 )
V_404 -> V_405 . V_408 = V_104 -> V_409 ;
else if ( V_402 < V_364 )
V_404 -> V_405 . V_408 = V_103 -> V_410 [ V_402 - 1 ] ;
else
V_36 = - V_79 ;
}
return V_36 ;
}
static struct V_411 * F_100 ( struct V_293 * V_294 ,
struct V_2 * V_412 ,
struct V_413 * V_414 )
{
struct V_151 * V_152 = F_13 ( V_294 ) ;
struct V_40 * V_41 ;
struct V_411 * V_36 ;
V_41 = F_76 ( sizeof *V_41 , V_415 ) ;
if ( ! V_41 ) {
V_36 = F_101 ( - V_67 ) ;
goto V_68;
}
F_28 ( & V_152 -> V_416 ) ;
if ( V_152 -> V_417 == V_334 ) {
F_32 ( & V_152 -> V_416 ) ;
F_62 ( V_41 ) ;
V_36 = F_101 ( - V_67 ) ;
goto V_68;
}
V_152 -> V_417 ++ ;
F_32 ( & V_152 -> V_416 ) ;
V_41 -> V_418 = V_414 != NULL ;
V_36 = & V_41 -> V_419 ;
V_68:
return V_36 ;
}
static int F_102 ( struct V_411 * V_419 )
{
struct V_40 * V_41 = F_14 ( V_419 ) ;
struct V_151 * V_152 = F_13 ( V_419 -> V_69 ) ;
F_28 ( & V_152 -> V_416 ) ;
V_152 -> V_417 -- ;
F_32 ( & V_152 -> V_416 ) ;
F_62 ( V_41 ) ;
return 0 ;
}
int F_103 ( struct V_293 * V_294 , struct V_420 * V_421 )
{
if ( V_421 -> V_422 >= V_123 &&
V_421 -> V_422 != V_423 &&
! ( V_421 -> V_424 & V_425 ) )
goto V_68;
if ( ( V_421 -> V_424 & V_425 ) &&
V_421 -> V_131 . V_426 >= V_364 )
goto V_68;
if ( V_421 -> V_422 == 0 )
goto V_68;
if ( V_421 -> V_75 < 1 ||
V_421 -> V_75 > V_294 -> V_427 )
goto V_68;
if ( V_421 -> V_428 != V_429 &&
F_104 ( V_421 -> V_428 ) < 0 )
goto V_68;
if ( V_421 -> V_430 > 15 )
goto V_68;
return 0 ;
V_68:
return - V_79 ;
}
static struct V_431 * F_105 ( struct V_411 * V_41 ,
struct V_420 * V_421 )
{
struct V_432 * V_58 ;
struct V_431 * V_36 ;
struct V_151 * V_152 = F_13 ( V_41 -> V_69 ) ;
unsigned long V_37 ;
if ( F_103 ( V_41 -> V_69 , V_421 ) ) {
V_36 = F_101 ( - V_79 ) ;
goto V_68;
}
V_58 = F_76 ( sizeof *V_58 , V_227 ) ;
if ( ! V_58 ) {
V_36 = F_101 ( - V_67 ) ;
goto V_68;
}
F_10 ( & V_152 -> V_433 , V_37 ) ;
if ( V_152 -> V_434 == V_326 ) {
F_20 ( & V_152 -> V_433 , V_37 ) ;
F_62 ( V_58 ) ;
V_36 = F_101 ( - V_67 ) ;
goto V_68;
}
V_152 -> V_434 ++ ;
F_20 ( & V_152 -> V_433 , V_37 ) ;
V_58 -> V_435 = * V_421 ;
F_106 ( & V_58 -> V_15 , 0 ) ;
V_36 = & V_58 -> V_436 ;
V_68:
return V_36 ;
}
static int F_107 ( struct V_431 * V_436 )
{
struct V_151 * V_152 = F_13 ( V_436 -> V_69 ) ;
struct V_432 * V_58 = F_19 ( V_436 ) ;
unsigned long V_37 ;
if ( F_108 ( & V_58 -> V_15 ) != 0 )
return - V_181 ;
F_10 ( & V_152 -> V_433 , V_37 ) ;
V_152 -> V_434 -- ;
F_20 ( & V_152 -> V_433 , V_37 ) ;
F_62 ( V_58 ) ;
return 0 ;
}
static int F_109 ( struct V_431 * V_436 , struct V_420 * V_421 )
{
struct V_432 * V_58 = F_19 ( V_436 ) ;
if ( F_103 ( V_436 -> V_69 , V_421 ) )
return - V_79 ;
V_58 -> V_435 = * V_421 ;
return 0 ;
}
static int F_110 ( struct V_431 * V_436 , struct V_420 * V_421 )
{
struct V_432 * V_58 = F_19 ( V_436 ) ;
* V_421 = V_58 -> V_435 ;
return 0 ;
}
unsigned F_89 ( struct V_209 * V_190 )
{
return F_66 ( V_190 -> V_97 [ 0 ] -> V_437 ) ;
}
unsigned F_111 ( struct V_102 * V_103 , unsigned V_402 )
{
struct V_115 * V_104 = F_73 ( V_103 ) ;
struct V_209 * V_190 = V_104 -> V_190 ;
unsigned V_438 = V_104 -> V_439 ;
unsigned V_36 ;
if ( ! V_190 -> V_97 || V_402 >= F_66 ( V_190 -> V_97 [ V_438 ] -> V_437 ) )
V_36 = 0 ;
else
V_36 = V_190 -> V_97 [ V_438 ] -> V_437 [ V_402 ] ;
return V_36 ;
}
static int F_112 ( struct V_293 * V_294 , T_2 V_192 , T_3 V_402 ,
T_3 * V_440 )
{
struct V_209 * V_190 = F_17 ( V_294 ) ;
int V_36 ;
if ( V_402 >= F_89 ( V_190 ) ) {
V_36 = - V_79 ;
goto V_68;
}
* V_440 = F_111 ( F_72 ( V_294 , V_192 ) , V_402 ) ;
V_36 = 0 ;
V_68:
return V_36 ;
}
static struct V_2 * F_113 ( struct V_293 * V_294 ,
struct V_413 * V_414 )
{
struct V_1 * V_412 ;
struct V_2 * V_36 ;
V_412 = F_76 ( sizeof *V_412 , V_415 ) ;
if ( ! V_412 ) {
V_36 = F_101 ( - V_67 ) ;
goto V_68;
}
V_36 = & V_412 -> V_3 ;
V_68:
return V_36 ;
}
static int F_114 ( struct V_2 * V_412 )
{
F_62 ( F_1 ( V_412 ) ) ;
return 0 ;
}
static void F_115 ( struct V_115 * V_104 )
{
struct V_258 V_259 ;
struct V_102 * V_103 = & V_104 -> V_105 ;
F_116 ( & V_103 -> V_91 ) ;
V_103 -> V_407 = V_441 ;
V_103 -> V_356 = F_34 ( V_355 ) ;
V_103 -> V_362 = V_442 |
V_443 | V_444 |
V_445 | V_446 |
V_447 | V_448 |
V_449 ;
if ( V_104 -> V_190 -> V_37 & V_450 )
V_103 -> V_362 |= V_451 ;
V_103 -> V_452 [ 0 ] = V_453 ;
V_103 -> V_452 [ 1 ] = V_454 ;
V_103 -> V_452 [ 2 ] = V_455 ;
V_103 -> V_452 [ 3 ] = V_456 ;
V_103 -> V_452 [ 4 ] = V_457 ;
F_86 ( V_104 , & V_259 ) ;
V_103 -> V_458 = V_259 . V_260 ;
V_103 -> V_459 =
V_259 . V_262 ;
V_103 -> V_460 = V_259 . V_264 ;
V_103 -> V_461 = V_259 . V_266 ;
V_103 -> V_462 = V_259 . V_278 ;
V_103 -> V_463 = V_259 . V_280 ;
V_103 -> V_464 = V_259 . V_282 ;
V_103 -> V_465 = V_259 . V_283 ;
V_103 -> V_466 = V_259 . V_284 ;
V_103 -> V_467 = V_259 . V_285 ;
V_103 -> V_468 =
V_259 . V_286 ;
V_103 -> V_469 =
V_259 . V_288 ;
V_103 -> V_470 = V_259 . V_290 ;
}
int F_117 ( struct V_209 * V_190 )
{
struct V_151 * V_152 = & V_190 -> V_191 ;
struct V_293 * V_294 = & V_152 -> V_294 ;
struct V_115 * V_104 = V_190 -> V_74 ;
unsigned V_33 , V_471 ;
int V_36 ;
V_152 -> V_472 = V_473 ;
V_152 -> V_474 = F_118 ( V_152 -> V_472 * sizeof * V_152 -> V_474 ,
V_415 ) ;
if ( ! V_152 -> V_474 ) {
V_36 = - V_67 ;
goto V_475;
}
for ( V_33 = 0 ; V_33 < V_190 -> V_394 ; V_33 ++ )
F_115 ( V_104 + V_33 ) ;
F_116 ( & V_152 -> V_476 ) ;
F_116 ( & V_152 -> V_416 ) ;
F_116 ( & V_152 -> V_433 ) ;
F_116 ( & V_152 -> V_477 ) ;
F_116 ( & V_152 -> V_478 ) ;
F_116 ( & V_152 -> V_479 ) ;
F_116 ( & V_152 -> V_480 ) ;
F_119 ( & V_152 -> F_42 ) ;
V_152 -> F_42 . V_481 = F_42 ;
V_152 -> F_42 . V_6 = ( unsigned long ) V_152 ;
F_120 ( V_190 , & V_152 -> V_482 ) ;
F_116 ( & V_152 -> V_70 . V_91 ) ;
V_152 -> V_70 . V_330 = 1 << V_483 ;
V_471 = V_152 -> V_70 . V_330 * sizeof( * V_152 -> V_70 . V_484 ) ;
V_152 -> V_70 . V_484 = (struct V_485 * * )
F_121 ( V_415 , F_122 ( V_471 ) ) ;
if ( V_152 -> V_70 . V_484 == NULL ) {
V_36 = - V_67 ;
goto V_486;
}
memset ( V_152 -> V_70 . V_484 , 0 , V_471 ) ;
F_123 ( & V_152 -> V_487 ) ;
F_116 ( & V_152 -> V_156 ) ;
V_152 -> V_488 = V_306 ;
F_116 ( & V_152 -> V_489 ) ;
F_123 ( & V_152 -> V_234 ) ;
F_123 ( & V_152 -> V_490 ) ;
F_123 ( & V_152 -> V_179 ) ;
F_123 ( & V_152 -> V_155 ) ;
F_123 ( & V_152 -> V_175 ) ;
if ( V_104 -> V_223 ) {
V_152 -> V_200 = F_124 ( & V_190 -> V_183 -> V_152 ,
V_104 -> V_223 *
sizeof( struct V_210 ) ,
& V_152 -> V_226 ,
V_415 ) ;
if ( ! V_152 -> V_200 ) {
V_36 = - V_67 ;
goto V_491;
}
}
for ( V_33 = 0 ; V_33 < V_104 -> V_223 ; V_33 ++ ) {
struct V_172 * V_174 ;
V_174 = F_118 ( sizeof *V_174 , V_415 ) ;
if ( ! V_174 ) {
V_36 = - V_67 ;
goto V_228;
}
V_174 -> V_201 = V_33 ;
F_63 ( & V_174 -> V_176 . V_154 , & V_152 -> V_175 ) ;
}
if ( ! V_316 )
V_316 = V_104 -> V_409 ;
F_125 ( V_294 -> V_492 , L_1 , V_493 ) ;
V_294 -> V_494 = V_495 ;
V_294 -> V_496 = V_104 -> V_409 ;
V_294 -> V_497 = V_498 ;
V_294 -> V_499 =
( 1ull << V_500 ) |
( 1ull << V_501 ) |
( 1ull << V_502 ) |
( 1ull << V_503 ) |
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
( 1ull << V_529 ) ;
V_294 -> V_530 = V_531 ;
V_294 -> V_427 = V_190 -> V_394 ;
V_294 -> V_532 = 1 ;
V_294 -> V_533 = & V_190 -> V_183 -> V_152 ;
V_294 -> V_534 = F_88 ;
V_294 -> V_535 = F_92 ;
V_294 -> V_536 = F_90 ;
V_294 -> V_537 = F_96 ;
V_294 -> V_538 = F_112 ;
V_294 -> V_539 = F_99 ;
V_294 -> V_540 = F_113 ;
V_294 -> V_541 = F_114 ;
V_294 -> V_542 = F_100 ;
V_294 -> V_543 = F_102 ;
V_294 -> V_544 = F_105 ;
V_294 -> V_545 = F_107 ;
V_294 -> V_546 = F_109 ;
V_294 -> V_547 = F_110 ;
V_294 -> V_548 = V_549 ;
V_294 -> V_550 = V_551 ;
V_294 -> V_552 = V_553 ;
V_294 -> V_554 = V_555 ;
V_294 -> V_556 = V_557 ;
V_294 -> V_558 = V_559 ;
V_294 -> V_560 = V_561 ;
V_294 -> V_562 = V_563 ;
V_294 -> V_564 = F_21 ;
V_294 -> V_565 = F_24 ;
V_294 -> V_566 = V_567 ;
V_294 -> V_568 = V_569 ;
V_294 -> V_570 = V_571 ;
V_294 -> V_572 = V_573 ;
V_294 -> V_574 = V_575 ;
V_294 -> V_576 = V_577 ;
V_294 -> V_578 = V_579 ;
V_294 -> V_580 = V_581 ;
V_294 -> V_582 = V_583 ;
V_294 -> V_584 = V_585 ;
V_294 -> V_586 = V_587 ;
V_294 -> V_588 = V_589 ;
V_294 -> V_590 = V_591 ;
V_294 -> V_592 = V_593 ;
V_294 -> V_594 = V_595 ;
V_294 -> V_596 = V_597 ;
V_294 -> V_598 = V_599 ;
V_294 -> V_600 = V_601 ;
V_294 -> V_602 = V_603 ;
V_294 -> V_604 = V_605 ;
V_294 -> V_606 = V_607 ;
V_294 -> V_608 = & V_609 ;
snprintf ( V_294 -> V_393 , sizeof( V_294 -> V_393 ) ,
V_610 L_2 , F_126 () -> V_611 ) ;
V_36 = F_127 ( V_294 , V_612 ) ;
if ( V_36 )
goto V_613;
V_36 = F_128 ( V_152 ) ;
if ( V_36 )
goto V_614;
if ( F_129 ( V_190 ) )
goto V_615;
goto V_68;
V_615:
F_130 ( V_152 ) ;
V_614:
F_131 ( V_294 ) ;
V_613:
V_228:
while ( ! F_43 ( & V_152 -> V_175 ) ) {
struct V_153 * V_130 = V_152 -> V_175 . V_32 ;
struct V_172 * V_174 ;
F_57 ( V_130 ) ;
V_174 = F_44 ( V_130 , struct V_172 , V_176 . V_154 ) ;
F_62 ( V_174 ) ;
}
if ( V_104 -> V_223 )
F_132 ( & V_190 -> V_183 -> V_152 ,
V_104 -> V_223 *
sizeof( struct V_210 ) ,
V_152 -> V_200 , V_152 -> V_226 ) ;
V_491:
F_133 ( ( unsigned long ) V_152 -> V_70 . V_484 , F_122 ( V_471 ) ) ;
V_486:
F_62 ( V_152 -> V_474 ) ;
V_475:
F_134 ( V_190 , L_3 , - V_36 ) ;
V_68:
return V_36 ;
}
void F_135 ( struct V_209 * V_190 )
{
struct V_151 * V_152 = & V_190 -> V_191 ;
struct V_293 * V_294 = & V_152 -> V_294 ;
T_1 V_616 ;
unsigned V_471 ;
F_136 ( V_190 ) ;
F_130 ( V_152 ) ;
F_131 ( V_294 ) ;
if ( ! F_43 ( & V_152 -> V_234 ) )
F_134 ( V_190 , L_4 ) ;
if ( ! F_43 ( & V_152 -> V_490 ) )
F_134 ( V_190 , L_5 ) ;
if ( ! F_43 ( & V_152 -> V_179 ) )
F_134 ( V_190 , L_6 ) ;
if ( ! F_43 ( & V_152 -> V_155 ) )
F_134 ( V_190 , L_7 ) ;
if ( V_152 -> V_617 )
F_134 ( V_190 , L_8 ) ;
V_616 = F_137 ( V_190 ) ;
if ( V_616 )
F_134 ( V_190 , L_9 ,
V_616 ) ;
F_138 ( & V_152 -> F_42 ) ;
F_139 ( & V_152 -> V_482 ) ;
while ( ! F_43 ( & V_152 -> V_175 ) ) {
struct V_153 * V_130 = V_152 -> V_175 . V_32 ;
struct V_172 * V_174 ;
F_57 ( V_130 ) ;
V_174 = F_44 ( V_130 , struct V_172 , V_176 . V_154 ) ;
F_62 ( V_174 ) ;
}
if ( V_190 -> V_74 -> V_223 )
F_132 ( & V_190 -> V_183 -> V_152 ,
V_190 -> V_74 -> V_223 *
sizeof( struct V_210 ) ,
V_152 -> V_200 , V_152 -> V_226 ) ;
V_471 = V_152 -> V_70 . V_330 * sizeof( * V_152 -> V_70 . V_484 ) ;
F_133 ( ( unsigned long ) V_152 -> V_70 . V_484 ,
F_122 ( V_471 ) ) ;
F_62 ( V_152 -> V_474 ) ;
}
