static inline struct V_1 * F_1 ( struct V_2
* V_3 )
{
return F_2 ( V_3 , struct V_1 , V_3 ) ;
}
void F_3 ( struct V_4 * V_5 , void * V_6 , T_1 V_7 )
{
struct V_8 * V_9 = & V_5 -> V_9 ;
while ( V_7 ) {
T_1 V_10 = V_9 -> V_7 ;
if ( V_10 > V_7 )
V_10 = V_7 ;
if ( V_10 > V_9 -> V_11 )
V_10 = V_9 -> V_11 ;
F_4 ( V_10 == 0 ) ;
memcpy ( V_9 -> V_12 , V_6 , V_10 ) ;
V_9 -> V_12 += V_10 ;
V_9 -> V_7 -= V_10 ;
V_9 -> V_11 -= V_10 ;
if ( V_9 -> V_11 == 0 ) {
if ( -- V_5 -> V_13 )
* V_9 = * V_5 -> V_14 ++ ;
} else if ( V_9 -> V_7 == 0 && V_9 -> V_15 != NULL ) {
if ( ++ V_9 -> V_16 >= V_17 ) {
if ( ++ V_9 -> V_18 >= V_9 -> V_15 -> V_19 )
break;
V_9 -> V_16 = 0 ;
}
V_9 -> V_12 =
V_9 -> V_15 -> V_20 [ V_9 -> V_18 ] -> V_21 [ V_9 -> V_16 ] . V_12 ;
V_9 -> V_7 =
V_9 -> V_15 -> V_20 [ V_9 -> V_18 ] -> V_21 [ V_9 -> V_16 ] . V_7 ;
}
V_6 += V_10 ;
V_7 -= V_10 ;
}
}
void F_5 ( struct V_4 * V_5 , T_1 V_7 )
{
struct V_8 * V_9 = & V_5 -> V_9 ;
while ( V_7 ) {
T_1 V_10 = V_9 -> V_7 ;
if ( V_10 > V_7 )
V_10 = V_7 ;
if ( V_10 > V_9 -> V_11 )
V_10 = V_9 -> V_11 ;
F_4 ( V_10 == 0 ) ;
V_9 -> V_12 += V_10 ;
V_9 -> V_7 -= V_10 ;
V_9 -> V_11 -= V_10 ;
if ( V_9 -> V_11 == 0 ) {
if ( -- V_5 -> V_13 )
* V_9 = * V_5 -> V_14 ++ ;
} else if ( V_9 -> V_7 == 0 && V_9 -> V_15 != NULL ) {
if ( ++ V_9 -> V_16 >= V_17 ) {
if ( ++ V_9 -> V_18 >= V_9 -> V_15 -> V_19 )
break;
V_9 -> V_16 = 0 ;
}
V_9 -> V_12 =
V_9 -> V_15 -> V_20 [ V_9 -> V_18 ] -> V_21 [ V_9 -> V_16 ] . V_12 ;
V_9 -> V_7 =
V_9 -> V_15 -> V_20 [ V_9 -> V_18 ] -> V_21 [ V_9 -> V_16 ] . V_7 ;
}
V_7 -= V_10 ;
}
}
static T_1 F_6 ( struct V_4 * V_5 , T_1 V_7 )
{
struct V_8 * V_14 = V_5 -> V_14 ;
struct V_8 V_9 = V_5 -> V_9 ;
T_2 V_13 = V_5 -> V_13 ;
T_1 V_22 = 1 ;
while ( V_7 ) {
T_1 V_10 = V_9 . V_7 ;
if ( V_10 > V_7 )
V_10 = V_7 ;
if ( V_10 > V_9 . V_11 )
V_10 = V_9 . V_11 ;
F_4 ( V_10 == 0 ) ;
if ( ( ( long ) V_9 . V_12 & ( sizeof( T_1 ) - 1 ) ) ||
( V_10 != V_7 && ( V_10 & ( sizeof( T_1 ) - 1 ) ) ) ) {
V_22 = 0 ;
break;
}
V_22 ++ ;
V_9 . V_12 += V_10 ;
V_9 . V_7 -= V_10 ;
V_9 . V_11 -= V_10 ;
if ( V_9 . V_11 == 0 ) {
if ( -- V_13 )
V_9 = * V_14 ++ ;
} else if ( V_9 . V_7 == 0 && V_9 . V_15 != NULL ) {
if ( ++ V_9 . V_16 >= V_17 ) {
if ( ++ V_9 . V_18 >= V_9 . V_15 -> V_19 )
break;
V_9 . V_16 = 0 ;
}
V_9 . V_12 =
V_9 . V_15 -> V_20 [ V_9 . V_18 ] -> V_21 [ V_9 . V_16 ] . V_12 ;
V_9 . V_7 =
V_9 . V_15 -> V_20 [ V_9 . V_18 ] -> V_21 [ V_9 . V_16 ] . V_7 ;
}
V_7 -= V_10 ;
}
return V_22 ;
}
static void F_7 ( void * V_6 , struct V_4 * V_5 ,
T_1 V_7 )
{
struct V_8 * V_9 = & V_5 -> V_9 ;
while ( V_7 ) {
T_1 V_10 = V_9 -> V_7 ;
if ( V_10 > V_7 )
V_10 = V_7 ;
if ( V_10 > V_9 -> V_11 )
V_10 = V_9 -> V_11 ;
F_4 ( V_10 == 0 ) ;
memcpy ( V_6 , V_9 -> V_12 , V_10 ) ;
V_9 -> V_12 += V_10 ;
V_9 -> V_7 -= V_10 ;
V_9 -> V_11 -= V_10 ;
if ( V_9 -> V_11 == 0 ) {
if ( -- V_5 -> V_13 )
* V_9 = * V_5 -> V_14 ++ ;
} else if ( V_9 -> V_7 == 0 && V_9 -> V_15 != NULL ) {
if ( ++ V_9 -> V_16 >= V_17 ) {
if ( ++ V_9 -> V_18 >= V_9 -> V_15 -> V_19 )
break;
V_9 -> V_16 = 0 ;
}
V_9 -> V_12 =
V_9 -> V_15 -> V_20 [ V_9 -> V_18 ] -> V_21 [ V_9 -> V_16 ] . V_12 ;
V_9 -> V_7 =
V_9 -> V_15 -> V_20 [ V_9 -> V_18 ] -> V_21 [ V_9 -> V_16 ] . V_7 ;
}
V_6 += V_10 ;
V_7 -= V_10 ;
}
}
static int F_8 ( struct V_23 * V_24 , struct V_25 * V_26 )
{
struct V_27 * V_28 ;
T_1 V_29 ;
int V_30 ;
int V_31 ;
int V_32 ;
int V_33 ;
unsigned long V_34 ;
struct V_35 * V_36 = F_9 ( V_24 -> V_37 . V_38 ) -> V_36 ;
F_10 ( & V_24 -> V_39 , V_34 ) ;
if ( V_24 -> V_37 . V_40 != V_41 &&
! ( V_36 -> V_42 & V_43 ) ) {
V_33 = - V_44 ;
goto V_45;
}
if ( F_11 ( ! ( V_46 [ V_24 -> V_47 ] & V_48 ) ) )
goto V_49;
if ( V_26 -> V_13 > V_24 -> V_50 )
goto V_49;
if ( V_24 -> V_37 . V_40 == V_51 ) {
if ( ( unsigned ) V_26 -> V_52 >= V_53 )
goto V_49;
} else if ( V_24 -> V_37 . V_40 == V_54 ) {
if ( V_26 -> V_52 != V_55 &&
V_26 -> V_52 != V_56 )
goto V_49;
if ( V_24 -> V_37 . V_57 != F_12 ( V_26 ) -> V_58 -> V_57 )
goto V_49;
} else if ( ( unsigned ) V_26 -> V_52 > V_59 )
goto V_49;
else if ( V_26 -> V_52 >= V_60 &&
( V_26 -> V_13 == 0 ||
V_26 -> V_14 [ 0 ] . V_7 < sizeof( V_61 ) ||
V_26 -> V_14 [ 0 ] . V_62 & ( sizeof( V_61 ) - 1 ) ) )
goto V_49;
else if ( V_26 -> V_52 >= V_53 && ! V_24 -> V_63 )
goto V_49;
V_29 = V_24 -> V_64 + 1 ;
if ( V_29 >= V_24 -> V_65 )
V_29 = 0 ;
if ( V_29 == V_24 -> V_66 ) {
V_33 = - V_67 ;
goto V_45;
}
V_28 = F_13 ( V_24 , V_24 -> V_64 ) ;
if ( V_24 -> V_37 . V_40 != V_51 &&
V_24 -> V_37 . V_40 != V_68 )
memcpy ( & V_28 -> F_12 , F_12 ( V_26 ) , sizeof( V_28 -> F_12 ) ) ;
else if ( V_26 -> V_52 == V_69 ||
V_26 -> V_52 == V_70 ||
V_26 -> V_52 == V_53 )
memcpy ( & V_28 -> V_71 , V_71 ( V_26 ) , sizeof( V_28 -> V_71 ) ) ;
else if ( V_26 -> V_52 == V_60 ||
V_26 -> V_52 == V_59 )
memcpy ( & V_28 -> V_72 , V_72 ( V_26 ) , sizeof( V_28 -> V_72 ) ) ;
else
memcpy ( & V_28 -> V_26 , V_26 , sizeof( V_28 -> V_26 ) ) ;
V_28 -> V_7 = 0 ;
if ( V_26 -> V_13 ) {
V_32 = V_26 -> V_52 >= V_53 ?
V_73 : 0 ;
for ( V_30 = 0 , V_31 = 0 ; V_30 < V_26 -> V_13 ; V_30 ++ ) {
T_1 V_7 = V_26 -> V_14 [ V_30 ] . V_7 ;
int V_74 ;
if ( V_7 == 0 )
continue;
V_74 = F_14 ( V_24 , & V_28 -> V_14 [ V_31 ] ,
& V_26 -> V_14 [ V_30 ] , V_32 ) ;
if ( ! V_74 )
goto V_49;
V_28 -> V_7 += V_7 ;
V_31 ++ ;
}
V_28 -> V_26 . V_13 = V_31 ;
}
if ( V_24 -> V_37 . V_40 == V_51 ||
V_24 -> V_37 . V_40 == V_68 ) {
if ( V_28 -> V_7 > 0x80000000U )
goto V_49;
} else if ( V_28 -> V_7 > F_9 ( V_24 -> V_37 . V_38 ) -> V_36 -> V_75 )
goto V_49;
V_28 -> V_76 = V_24 -> V_77 ++ ;
V_24 -> V_64 = V_29 ;
V_33 = 0 ;
goto V_45;
V_49:
V_33 = - V_78 ;
V_45:
F_15 ( & V_24 -> V_39 , V_34 ) ;
return V_33 ;
}
static int F_16 ( struct V_79 * V_37 , struct V_25 * V_26 ,
struct V_25 * * V_80 )
{
struct V_23 * V_24 = F_17 ( V_37 ) ;
int V_81 = 0 ;
for (; V_26 ; V_26 = V_26 -> V_29 ) {
V_81 = F_8 ( V_24 , V_26 ) ;
if ( V_81 ) {
* V_80 = V_26 ;
goto V_45;
}
}
F_18 ( ( unsigned long ) V_24 ) ;
V_45:
return V_81 ;
}
static int F_19 ( struct V_79 * V_37 , struct V_82 * V_26 ,
struct V_82 * * V_80 )
{
struct V_23 * V_24 = F_17 ( V_37 ) ;
struct V_83 * V_84 = V_24 -> V_85 . V_84 ;
unsigned long V_34 ;
int V_33 ;
if ( ! ( V_46 [ V_24 -> V_47 ] & V_86 ) || ! V_84 ) {
* V_80 = V_26 ;
V_33 = - V_78 ;
goto V_45;
}
for (; V_26 ; V_26 = V_26 -> V_29 ) {
struct V_87 * V_28 ;
T_1 V_29 ;
int V_30 ;
if ( ( unsigned ) V_26 -> V_13 > V_24 -> V_85 . V_88 ) {
* V_80 = V_26 ;
V_33 = - V_78 ;
goto V_45;
}
F_10 ( & V_24 -> V_85 . V_89 , V_34 ) ;
V_29 = V_84 -> V_90 + 1 ;
if ( V_29 >= V_24 -> V_85 . V_91 )
V_29 = 0 ;
if ( V_29 == V_84 -> V_92 ) {
F_15 ( & V_24 -> V_85 . V_89 , V_34 ) ;
* V_80 = V_26 ;
V_33 = - V_67 ;
goto V_45;
}
V_28 = F_20 ( & V_24 -> V_85 , V_84 -> V_90 ) ;
V_28 -> V_93 = V_26 -> V_93 ;
V_28 -> V_13 = V_26 -> V_13 ;
for ( V_30 = 0 ; V_30 < V_26 -> V_13 ; V_30 ++ )
V_28 -> V_14 [ V_30 ] = V_26 -> V_14 [ V_30 ] ;
F_21 () ;
V_84 -> V_90 = V_29 ;
F_15 ( & V_24 -> V_85 . V_89 , V_34 ) ;
}
V_33 = 0 ;
V_45:
return V_33 ;
}
static void F_22 ( struct V_94 * V_95 ,
struct V_96 * V_97 , int V_98 ,
void * V_6 , T_1 V_99 , struct V_23 * V_24 )
{
if ( ! ( V_46 [ V_24 -> V_47 ] & V_100 ) ) {
V_95 -> V_101 ++ ;
return;
}
switch ( V_24 -> V_37 . V_40 ) {
case V_41 :
case V_102 :
if ( V_103 )
break;
case V_54 :
F_23 ( V_95 , V_97 , V_98 , V_6 , V_99 , V_24 ) ;
break;
case V_68 :
F_24 ( V_95 , V_97 , V_98 , V_6 , V_99 , V_24 ) ;
break;
case V_51 :
F_25 ( V_95 , V_97 , V_98 , V_6 , V_99 , V_24 ) ;
break;
default:
break;
}
}
void F_26 ( struct V_94 * V_95 , void * V_104 , void * V_6 ,
T_1 V_99 )
{
struct V_96 * V_97 = V_104 ;
struct V_105 * V_106 ;
struct V_23 * V_24 ;
T_1 V_107 ;
int V_108 ;
T_2 V_52 ;
T_3 V_109 ;
if ( F_11 ( V_95 == NULL ) )
goto V_45;
if ( F_11 ( V_99 < 24 ) ) {
V_95 -> V_110 ++ ;
goto V_45;
}
V_109 = F_27 ( V_97 -> V_111 [ 1 ] ) ;
if ( V_109 < V_112 ) {
V_109 &= ~ ( ( 1 << V_95 -> V_36 -> V_113 ) - 1 ) ;
if ( F_11 ( V_109 != V_95 -> V_36 -> V_114 ) ) {
V_95 -> V_110 ++ ;
goto V_45;
}
}
V_108 = F_27 ( V_97 -> V_111 [ 0 ] ) & 3 ;
if ( V_108 == V_115 )
V_106 = & V_97 -> V_116 . V_117 ;
else if ( V_108 == V_118 )
V_106 = & V_97 -> V_116 . V_119 . V_117 ;
else {
V_95 -> V_110 ++ ;
goto V_45;
}
V_52 = ( F_28 ( V_106 -> V_120 [ 0 ] ) >> 24 ) & 0x7f ;
V_95 -> V_121 [ V_52 ] . V_122 += V_99 ;
V_95 -> V_121 [ V_52 ] . V_123 ++ ;
V_107 = F_28 ( V_106 -> V_120 [ 1 ] ) & V_124 ;
if ( V_107 == V_125 ) {
struct V_126 * V_127 ;
struct V_128 * V_129 ;
if ( V_108 != V_118 ) {
V_95 -> V_101 ++ ;
goto V_45;
}
V_127 = F_29 ( & V_97 -> V_116 . V_119 . V_130 . V_131 ) ;
if ( V_127 == NULL ) {
V_95 -> V_101 ++ ;
goto V_45;
}
V_95 -> V_132 ++ ;
F_30 (p, &mcast->qp_list, list)
F_22 ( V_95 , V_97 , 1 , V_6 , V_99 , V_129 -> V_24 ) ;
if ( F_31 ( & V_127 -> V_133 ) <= 1 )
F_32 ( & V_127 -> V_134 ) ;
} else {
V_24 = F_33 ( & V_95 -> V_135 , V_107 ) ;
if ( V_24 ) {
V_95 -> V_136 ++ ;
F_22 ( V_95 , V_97 , V_108 == V_118 , V_6 ,
V_99 , V_24 ) ;
if ( F_34 ( & V_24 -> V_133 ) )
F_32 ( & V_24 -> V_134 ) ;
} else
V_95 -> V_101 ++ ;
}
V_45: ;
}
static void F_35 ( struct V_94 * V_95 )
{
struct V_23 * V_137 = NULL ;
struct V_23 * V_138 = NULL ;
struct V_139 * V_140 ;
struct V_23 * V_24 ;
unsigned long V_34 ;
if ( V_95 == NULL )
return;
F_10 ( & V_95 -> V_141 , V_34 ) ;
if ( ++ V_95 -> V_142 >= F_36 ( V_95 -> V_143 ) )
V_95 -> V_142 = 0 ;
V_140 = & V_95 -> V_143 [ V_95 -> V_142 ] ;
while ( ! F_37 ( V_140 ) ) {
V_24 = F_38 ( V_140 -> V_29 , struct V_23 , V_144 ) ;
F_39 ( & V_24 -> V_144 ) ;
V_24 -> V_145 = V_137 ;
V_137 = V_24 ;
F_40 ( & V_24 -> V_133 ) ;
}
V_140 = & V_95 -> V_146 ;
if ( ! F_37 ( V_140 ) ) {
V_24 = F_38 ( V_140 -> V_29 , struct V_23 , V_144 ) ;
if ( -- V_24 -> V_147 == 0 ) {
do {
F_39 ( & V_24 -> V_144 ) ;
V_24 -> V_145 = V_138 ;
V_138 = V_24 ;
F_40 ( & V_24 -> V_133 ) ;
if ( F_37 ( V_140 ) )
break;
V_24 = F_38 ( V_140 -> V_29 , struct V_23 ,
V_144 ) ;
} while ( V_24 -> V_147 == 0 );
}
}
if ( V_95 -> V_148 == V_149 &&
-- V_95 -> V_150 == 0 ) {
V_95 -> V_148 = V_151 ;
F_41 ( V_95 -> V_36 , & V_95 -> V_152 ,
& V_95 -> V_153 ,
& V_95 -> V_154 ,
& V_95 -> V_155 ,
& V_95 -> V_156 ) ;
}
if ( V_95 -> V_148 == V_151 ) {
if ( V_95 -> V_157 == 0 ) {
V_61 V_158 , V_159 , V_160 , V_161 , V_162 ;
V_95 -> V_148 = V_163 ;
F_41 ( V_95 -> V_36 , & V_158 , & V_159 ,
& V_160 , & V_161 , & V_162 ) ;
V_95 -> V_152 = V_158 - V_95 -> V_152 ;
V_95 -> V_153 = V_159 - V_95 -> V_153 ;
V_95 -> V_154 = V_160 - V_95 -> V_154 ;
V_95 -> V_155 = V_161 - V_95 -> V_155 ;
V_95 -> V_156 = V_162 - V_95 -> V_156 ;
} else {
V_95 -> V_157 -- ;
}
}
F_15 ( & V_95 -> V_141 , V_34 ) ;
while ( V_137 != NULL ) {
V_24 = V_137 ;
V_137 = V_24 -> V_145 ;
F_10 ( & V_24 -> V_39 , V_34 ) ;
if ( V_24 -> V_66 != V_24 -> V_164 &&
V_46 [ V_24 -> V_47 ] & V_165 ) {
V_95 -> V_166 ++ ;
F_42 ( V_24 , V_24 -> V_167 + 1 ) ;
}
F_15 ( & V_24 -> V_39 , V_34 ) ;
if ( F_34 ( & V_24 -> V_133 ) )
F_32 ( & V_24 -> V_134 ) ;
}
while ( V_138 != NULL ) {
V_24 = V_138 ;
V_138 = V_24 -> V_145 ;
F_10 ( & V_24 -> V_39 , V_34 ) ;
if ( V_46 [ V_24 -> V_47 ] & V_165 )
F_43 ( V_24 ) ;
F_15 ( & V_24 -> V_39 , V_34 ) ;
if ( F_34 ( & V_24 -> V_133 ) )
F_32 ( & V_24 -> V_134 ) ;
}
}
static void F_44 ( struct V_4 * V_5 , T_1 V_7 )
{
struct V_8 * V_9 = & V_5 -> V_9 ;
V_9 -> V_12 += V_7 ;
V_9 -> V_7 -= V_7 ;
V_9 -> V_11 -= V_7 ;
if ( V_9 -> V_11 == 0 ) {
if ( -- V_5 -> V_13 )
* V_9 = * V_5 -> V_14 ++ ;
} else if ( V_9 -> V_7 == 0 && V_9 -> V_15 != NULL ) {
if ( ++ V_9 -> V_16 >= V_17 ) {
if ( ++ V_9 -> V_18 >= V_9 -> V_15 -> V_19 )
return;
V_9 -> V_16 = 0 ;
}
V_9 -> V_12 = V_9 -> V_15 -> V_20 [ V_9 -> V_18 ] -> V_21 [ V_9 -> V_16 ] . V_12 ;
V_9 -> V_7 = V_9 -> V_15 -> V_20 [ V_9 -> V_18 ] -> V_21 [ V_9 -> V_16 ] . V_7 ;
}
}
static inline T_1 F_45 ( T_1 V_6 , T_1 V_168 )
{
return V_6 >> V_168 ;
}
static inline T_1 F_46 ( T_1 V_6 , T_1 V_168 )
{
return V_6 << V_168 ;
}
static inline T_1 F_47 ( T_1 V_6 , T_1 V_16 , T_1 V_169 )
{
V_6 <<= ( ( sizeof( T_1 ) - V_16 ) * V_170 ) ;
V_6 >>= ( ( sizeof( T_1 ) - V_16 - V_169 ) * V_170 ) ;
return V_6 ;
}
static inline T_1 F_45 ( T_1 V_6 , T_1 V_168 )
{
return V_6 << V_168 ;
}
static inline T_1 F_46 ( T_1 V_6 , T_1 V_168 )
{
return V_6 >> V_168 ;
}
static inline T_1 F_47 ( T_1 V_6 , T_1 V_16 , T_1 V_169 )
{
V_6 >>= ( ( sizeof( T_1 ) - V_16 ) * V_170 ) ;
V_6 <<= ( ( sizeof( T_1 ) - V_16 - V_169 ) * V_170 ) ;
return V_6 ;
}
static void F_48 ( T_1 T_4 * V_171 , struct V_4 * V_5 ,
T_1 V_7 , unsigned V_172 )
{
T_1 V_173 = 0 ;
T_1 V_6 = 0 ;
T_1 V_140 ;
while ( 1 ) {
T_1 V_10 = V_5 -> V_9 . V_7 ;
T_1 V_169 ;
if ( V_10 > V_7 )
V_10 = V_7 ;
if ( V_10 > V_5 -> V_9 . V_11 )
V_10 = V_5 -> V_9 . V_11 ;
F_4 ( V_10 == 0 ) ;
V_169 = ( unsigned long ) V_5 -> V_9 . V_12 & ( sizeof( T_1 ) - 1 ) ;
if ( V_169 ) {
T_1 * V_62 = ( T_1 * ) ( ( unsigned long ) V_5 -> V_9 . V_12 &
~ ( sizeof( T_1 ) - 1 ) ) ;
T_1 V_174 = F_45 ( * V_62 , V_169 * V_170 ) ;
T_1 V_175 ;
V_175 = sizeof( T_1 ) - V_169 ;
if ( V_10 > V_175 )
V_10 = V_175 ;
if ( V_10 + V_173 >= sizeof( T_1 ) ) {
V_6 |= F_46 ( V_174 , V_173 *
V_170 ) ;
V_10 = sizeof( T_1 ) - V_173 ;
if ( V_10 == V_7 ) {
V_140 = V_6 ;
break;
}
F_49 ( V_6 , V_171 ) ;
V_171 ++ ;
V_173 = 0 ;
V_6 = 0 ;
} else {
V_6 |= F_47 ( V_174 , V_10 , V_173 ) ;
if ( V_10 == V_7 ) {
V_140 = V_6 ;
break;
}
V_173 += V_10 ;
}
} else if ( V_173 ) {
T_1 * V_62 = ( T_1 * ) V_5 -> V_9 . V_12 ;
int V_168 = V_173 * V_170 ;
int V_176 = 32 - V_168 ;
T_1 V_119 = V_10 ;
while ( V_119 >= sizeof( T_1 ) ) {
T_1 V_174 = * V_62 ;
V_6 |= F_46 ( V_174 , V_168 ) ;
F_49 ( V_6 , V_171 ) ;
V_6 = F_45 ( V_174 , V_176 ) ;
V_171 ++ ;
V_62 ++ ;
V_119 -= sizeof( T_1 ) ;
}
if ( V_119 ) {
T_1 V_174 = * V_62 ;
if ( V_119 + V_173 >= sizeof( T_1 ) ) {
V_6 |= F_46 ( V_174 , V_168 ) ;
V_10 -= V_119 + V_173 - sizeof( T_1 ) ;
if ( V_10 == V_7 ) {
V_140 = V_6 ;
break;
}
F_49 ( V_6 , V_171 ) ;
V_171 ++ ;
V_173 = 0 ;
V_6 = 0 ;
} else {
V_6 |= F_47 ( V_174 , V_119 ,
V_173 ) ;
if ( V_10 == V_7 ) {
V_140 = V_6 ;
break;
}
V_173 += V_119 ;
}
} else if ( V_10 == V_7 ) {
V_140 = V_6 ;
break;
}
} else if ( V_10 == V_7 ) {
T_1 V_177 ;
V_177 = ( V_10 + 3 ) >> 2 ;
F_50 ( V_171 , V_5 -> V_9 . V_12 , V_177 - 1 ) ;
V_171 += V_177 - 1 ;
V_140 = ( ( T_1 * ) V_5 -> V_9 . V_12 ) [ V_177 - 1 ] ;
break;
} else {
T_1 V_177 = V_10 >> 2 ;
F_50 ( V_171 , V_5 -> V_9 . V_12 , V_177 ) ;
V_171 += V_177 ;
V_173 = V_10 & ( sizeof( T_1 ) - 1 ) ;
if ( V_173 ) {
T_1 V_174 = ( ( T_1 * ) V_5 -> V_9 . V_12 ) [ V_177 ] ;
V_6 = F_47 ( V_174 , V_173 , 0 ) ;
}
}
F_44 ( V_5 , V_10 ) ;
V_7 -= V_10 ;
}
F_44 ( V_5 , V_7 ) ;
if ( V_172 ) {
F_51 () ;
F_49 ( V_140 , V_171 ) ;
F_51 () ;
} else
F_49 ( V_140 , V_171 ) ;
}
unsigned F_52 ( enum V_178 V_179 )
{
switch ( V_179 ) {
case V_180 : return 8 ;
case V_181 : return 4 ;
case V_182 : return 2 ;
case V_183 : return 1 ;
default: return 0 ;
}
}
static enum V_178 F_53 ( unsigned V_184 )
{
switch ( V_184 ) {
case 8 : return V_180 ;
case 4 : return V_181 ;
case 2 : return V_182 ;
case 1 : return V_183 ;
default: return V_185 ;
}
}
static inline struct V_186 * F_54 ( struct V_94 * V_95 )
{
struct V_186 * V_187 = NULL ;
unsigned long V_34 ;
F_10 ( & V_95 -> V_141 , V_34 ) ;
if ( ! F_37 ( & V_95 -> V_188 ) ) {
struct V_139 * V_119 = V_95 -> V_188 . V_29 ;
F_55 ( V_119 ) ;
V_187 = F_38 ( V_119 , struct V_186 , V_189 . V_190 ) ;
}
F_15 ( & V_95 -> V_141 , V_34 ) ;
return V_187 ;
}
static inline void F_56 ( struct V_94 * V_95 ,
struct V_186 * V_187 )
{
unsigned long V_34 ;
F_10 ( & V_95 -> V_141 , V_34 ) ;
F_57 ( & V_187 -> V_189 . V_190 , & V_95 -> V_188 ) ;
F_15 ( & V_95 -> V_141 , V_34 ) ;
}
static void F_58 ( void * V_191 , int V_192 )
{
struct V_186 * V_187 = V_191 ;
struct V_23 * V_24 = V_187 -> V_24 ;
struct V_94 * V_95 = F_9 ( V_24 -> V_37 . V_38 ) ;
unsigned long V_34 ;
enum V_193 V_194 = V_192 == V_195 ?
V_196 : V_197 ;
if ( F_34 ( & V_24 -> V_198 ) ) {
F_10 ( & V_24 -> V_39 , V_34 ) ;
if ( V_187 -> V_28 )
F_59 ( V_24 , V_187 -> V_28 , V_194 ) ;
if ( ( V_46 [ V_24 -> V_47 ] & V_199 &&
V_24 -> V_66 != V_24 -> V_64 ) ||
( V_24 -> V_200 & V_201 ) )
F_43 ( V_24 ) ;
F_15 ( & V_24 -> V_39 , V_34 ) ;
F_32 ( & V_24 -> V_202 ) ;
} else if ( V_187 -> V_28 ) {
F_10 ( & V_24 -> V_39 , V_34 ) ;
F_59 ( V_24 , V_187 -> V_28 , V_194 ) ;
F_15 ( & V_24 -> V_39 , V_34 ) ;
}
if ( V_187 -> V_189 . V_34 & V_203 )
F_60 ( V_187 -> V_189 . V_204 ) ;
F_56 ( V_95 , V_187 ) ;
if ( F_34 ( & V_24 -> V_133 ) )
F_32 ( & V_24 -> V_134 ) ;
}
static void F_61 ( struct V_23 * V_24 )
{
unsigned long V_34 ;
if ( F_34 ( & V_24 -> V_198 ) ) {
F_10 ( & V_24 -> V_39 , V_34 ) ;
if ( ( V_46 [ V_24 -> V_47 ] & V_199 &&
V_24 -> V_66 != V_24 -> V_64 ) ||
( V_24 -> V_200 & V_201 ) )
F_43 ( V_24 ) ;
F_15 ( & V_24 -> V_39 , V_34 ) ;
F_32 ( & V_24 -> V_202 ) ;
}
}
static inline unsigned F_62 ( T_1 V_205 , T_2 V_206 , T_2 V_207 )
{
return ( V_207 > V_206 ) ?
( V_205 * ( V_207 - V_206 ) + 1 ) >> 1 : 0 ;
}
static int F_63 ( struct V_23 * V_24 ,
struct V_96 * V_97 , T_1 V_208 ,
struct V_4 * V_5 , T_1 V_10 ,
T_1 V_205 , T_1 V_209 )
{
struct V_94 * V_95 = F_9 ( V_24 -> V_37 . V_38 ) ;
struct V_35 * V_36 = V_95 -> V_36 ;
struct V_186 * V_187 ;
T_1 * V_171 ;
T_1 V_210 ;
T_1 V_22 ;
int V_33 ;
V_187 = V_24 -> V_211 ;
if ( V_187 ) {
V_24 -> V_211 = NULL ;
F_40 ( & V_24 -> V_198 ) ;
V_33 = F_64 ( V_36 , V_187 -> V_5 , V_187 -> V_10 , V_187 ) ;
if ( V_33 ) {
V_24 -> V_211 = V_187 ;
F_61 ( V_24 ) ;
}
goto V_45;
}
V_187 = F_54 ( V_95 ) ;
if ( ! V_187 ) {
V_33 = - V_212 ;
goto V_45;
}
V_210 = V_24 -> V_213 ;
V_24 -> V_213 = F_62 ( V_205 , V_36 -> V_214 , V_24 -> V_215 ) ;
V_187 -> V_24 = V_24 ;
F_40 ( & V_24 -> V_133 ) ;
V_187 -> V_28 = V_24 -> V_216 ;
V_187 -> V_189 . V_217 = F_58 ;
V_187 -> V_189 . V_218 = V_187 ;
V_187 -> V_189 . V_34 = V_219 |
V_220 | V_221 ;
if ( V_205 + 1 >= V_222 )
V_187 -> V_189 . V_34 |= V_223 ;
if ( ( F_27 ( V_97 -> V_111 [ 0 ] ) >> 12 ) == 15 ) {
V_210 |= 1ULL << 31 ;
V_187 -> V_189 . V_34 |= V_224 ;
}
if ( V_10 ) {
V_22 = F_6 ( V_5 , V_10 ) ;
if ( V_22 >= V_36 -> V_225 )
V_22 = 0 ;
} else
V_22 = 1 ;
if ( V_22 ) {
V_187 -> V_97 . V_226 [ 0 ] = F_65 ( V_205 ) ;
V_187 -> V_97 . V_226 [ 1 ] = F_65 ( V_210 ) ;
memcpy ( & V_187 -> V_97 . V_97 , V_97 , V_208 << 2 ) ;
V_187 -> V_189 . V_227 = V_22 ;
V_187 -> V_228 = ( V_208 + 2 ) << 2 ;
V_187 -> V_189 . V_204 = & V_187 -> V_97 ;
F_40 ( & V_24 -> V_198 ) ;
V_33 = F_64 ( V_36 , V_5 , V_209 , V_187 ) ;
if ( V_33 ) {
V_187 -> V_5 = V_5 ;
V_187 -> V_10 = V_209 ;
V_24 -> V_211 = V_187 ;
F_61 ( V_24 ) ;
}
goto V_45;
}
V_187 -> V_228 = ( V_205 + 1 ) << 2 ;
V_171 = F_66 ( V_187 -> V_228 , V_229 ) ;
if ( F_11 ( V_171 == NULL ) ) {
V_33 = - V_212 ;
goto V_230;
}
V_187 -> V_189 . V_204 = V_171 ;
V_187 -> V_189 . V_34 |= V_203 ;
V_187 -> V_189 . V_227 = 1 ;
* V_171 ++ = ( V_231 T_1 ) F_65 ( V_205 ) ;
* V_171 ++ = ( V_231 T_1 ) F_65 ( V_210 ) ;
memcpy ( V_171 , V_97 , V_208 << 2 ) ;
F_7 ( V_171 + V_208 , V_5 , V_10 ) ;
F_40 ( & V_24 -> V_198 ) ;
V_33 = F_64 ( V_36 , NULL , 0 , V_187 ) ;
if ( V_33 ) {
V_187 -> V_5 = NULL ;
V_187 -> V_10 = 0 ;
V_24 -> V_211 = V_187 ;
F_61 ( V_24 ) ;
}
V_95 -> V_232 ++ ;
goto V_45;
V_230:
if ( F_34 ( & V_24 -> V_133 ) )
F_32 ( & V_24 -> V_134 ) ;
F_56 ( V_95 , V_187 ) ;
V_45:
return V_33 ;
}
static int F_67 ( struct V_23 * V_24 ,
struct V_96 * V_233 , T_1 V_208 ,
struct V_4 * V_5 , T_1 V_10 ,
T_1 V_205 , T_1 V_209 )
{
struct V_35 * V_36 = F_9 ( V_24 -> V_37 . V_38 ) -> V_36 ;
T_1 * V_97 = ( T_1 * ) V_233 ;
T_1 T_4 * V_171 ;
unsigned V_172 ;
T_1 V_210 ;
int V_33 ;
unsigned long V_34 ;
V_171 = F_68 ( V_36 , V_205 , NULL ) ;
if ( F_11 ( V_171 == NULL ) ) {
V_33 = - V_212 ;
goto V_45;
}
V_210 = V_24 -> V_213 ;
V_24 -> V_213 = F_62 ( V_205 , V_36 -> V_214 , V_24 -> V_215 ) ;
if ( ( F_27 ( V_233 -> V_111 [ 0 ] ) >> 12 ) == 15 )
V_210 |= 1ULL << 31 ;
F_69 ( ( ( V_61 ) V_210 << 32 ) | V_205 , V_171 ) ;
V_171 += 2 ;
V_172 = V_36 -> V_42 & V_234 ;
if ( V_10 == 0 ) {
if ( V_172 ) {
F_51 () ;
F_50 ( V_171 , V_97 , V_208 - 1 ) ;
F_51 () ;
F_49 ( V_97 [ V_208 - 1 ] , V_171 + V_208 - 1 ) ;
F_51 () ;
} else
F_50 ( V_171 , V_97 , V_208 ) ;
goto V_235;
}
if ( V_172 )
F_51 () ;
F_50 ( V_171 , V_97 , V_208 ) ;
V_171 += V_208 ;
if ( F_70 ( V_5 -> V_13 == 1 && V_10 <= V_5 -> V_9 . V_7 &&
! ( ( unsigned long ) V_5 -> V_9 . V_12 & ( sizeof( T_1 ) - 1 ) ) ) ) {
T_1 * V_62 = ( T_1 * ) V_5 -> V_9 . V_12 ;
F_44 ( V_5 , V_10 ) ;
if ( V_172 ) {
F_50 ( V_171 , V_62 , V_209 - 1 ) ;
F_51 () ;
F_49 ( V_62 [ V_209 - 1 ] , V_171 + V_209 - 1 ) ;
F_51 () ;
} else
F_50 ( V_171 , V_62 , V_209 ) ;
goto V_235;
}
F_48 ( V_171 , V_5 , V_10 , V_172 ) ;
V_235:
if ( V_24 -> V_216 ) {
F_10 ( & V_24 -> V_39 , V_34 ) ;
F_59 ( V_24 , V_24 -> V_216 , V_196 ) ;
F_15 ( & V_24 -> V_39 , V_34 ) ;
}
V_33 = 0 ;
V_45:
return V_33 ;
}
int F_71 ( struct V_23 * V_24 , struct V_96 * V_97 ,
T_1 V_208 , struct V_4 * V_5 , T_1 V_10 )
{
struct V_35 * V_36 = F_9 ( V_24 -> V_37 . V_38 ) -> V_36 ;
T_1 V_205 ;
int V_33 ;
T_1 V_209 = ( V_10 + 3 ) >> 2 ;
V_205 = V_208 + V_209 + 1 ;
if ( V_24 -> V_37 . V_40 == V_41 ||
! ( V_36 -> V_42 & V_236 ) )
V_33 = F_67 ( V_24 , V_97 , V_208 , V_5 , V_10 ,
V_205 , V_209 ) ;
else
V_33 = F_63 ( V_24 , V_97 , V_208 , V_5 , V_10 ,
V_205 , V_209 ) ;
return V_33 ;
}
int F_41 ( struct V_35 * V_36 , V_61 * V_237 ,
V_61 * V_238 , V_61 * V_239 , V_61 * V_240 ,
V_61 * V_241 )
{
int V_33 ;
if ( ! ( V_36 -> V_42 & V_242 ) ) {
V_33 = - V_78 ;
goto V_45;
}
* V_237 = F_72 ( V_36 , V_36 -> V_243 -> V_244 ) ;
* V_238 = F_72 ( V_36 , V_36 -> V_243 -> V_245 ) ;
* V_239 = F_72 ( V_36 , V_36 -> V_243 -> V_246 ) ;
* V_240 = F_72 ( V_36 , V_36 -> V_243 -> V_247 ) ;
* V_241 = F_72 ( V_36 , V_36 -> V_243 -> V_248 ) ;
V_33 = 0 ;
V_45:
return V_33 ;
}
int F_73 ( struct V_35 * V_36 ,
struct V_249 * V_250 )
{
struct V_243 const * V_251 = V_36 -> V_243 ;
int V_33 ;
if ( ! ( V_36 -> V_42 & V_242 ) ) {
V_33 = - V_78 ;
goto V_45;
}
V_250 -> V_252 =
F_72 ( V_36 , V_251 -> V_253 ) ;
V_250 -> V_254 =
F_72 ( V_36 , V_251 -> V_255 ) ;
V_250 -> V_256 =
F_72 ( V_36 , V_251 -> V_257 ) ;
V_250 -> V_258 =
F_72 ( V_36 , V_251 -> V_259 ) +
F_72 ( V_36 , V_251 -> V_260 ) +
F_72 ( V_36 , V_251 -> V_261 ) +
F_72 ( V_36 , V_251 -> V_262 ) +
F_72 ( V_36 , V_251 -> V_263 ) +
F_72 ( V_36 , V_251 -> V_264 ) +
F_72 ( V_36 , V_251 -> V_265 ) +
F_72 ( V_36 , V_251 -> V_266 ) +
F_72 ( V_36 , V_251 -> V_267 ) +
F_72 ( V_36 , V_251 -> V_268 ) +
V_36 -> V_269 ;
if ( V_251 -> V_270 )
V_250 -> V_258 +=
F_72 ( V_36 , V_251 -> V_270 ) ;
if ( V_251 -> V_271 )
V_250 -> V_258 +=
F_72 ( V_36 , V_251 -> V_271 ) ;
V_250 -> V_272 =
F_72 ( V_36 , V_251 -> V_273 ) ;
V_250 -> V_274 = F_72 ( V_36 , V_251 -> V_275 ) ;
V_250 -> V_276 = F_72 ( V_36 , V_251 -> V_244 ) ;
V_250 -> V_277 = F_72 ( V_36 , V_251 -> V_245 ) ;
V_250 -> V_278 = F_72 ( V_36 , V_251 -> V_246 ) ;
V_250 -> V_279 = F_72 ( V_36 , V_251 -> V_247 ) ;
V_250 -> V_280 =
V_251 -> V_281 ?
F_72 ( V_36 , V_251 -> V_281 ) :
( ( V_36 -> V_42 & V_282 ) ?
V_36 -> V_283 : V_36 -> V_284 ) ;
V_250 -> V_285 =
V_251 -> V_286 ?
F_72 ( V_36 , V_251 -> V_286 ) :
V_36 -> V_287 ;
V_250 -> V_288 = V_251 -> V_289 ?
F_72 ( V_36 , V_251 -> V_289 ) : 0 ;
V_33 = 0 ;
V_45:
return V_33 ;
}
int F_74 ( struct V_94 * V_95 )
{
struct V_139 * V_190 ;
struct V_23 * V_290 ;
struct V_23 * V_24 ;
unsigned long V_34 ;
if ( V_95 == NULL )
goto V_45;
V_190 = & V_95 -> V_291 ;
V_290 = NULL ;
F_10 ( & V_95 -> V_141 , V_34 ) ;
while ( ! F_37 ( V_190 ) ) {
V_24 = F_38 ( V_190 -> V_29 , struct V_23 , V_291 ) ;
F_39 ( & V_24 -> V_291 ) ;
V_24 -> V_292 = V_290 ;
V_290 = V_24 ;
F_40 ( & V_24 -> V_133 ) ;
}
F_15 ( & V_95 -> V_141 , V_34 ) ;
while ( V_290 != NULL ) {
V_24 = V_290 ;
V_290 = V_24 -> V_292 ;
F_10 ( & V_24 -> V_39 , V_34 ) ;
if ( V_46 [ V_24 -> V_47 ] & V_165 )
F_43 ( V_24 ) ;
F_15 ( & V_24 -> V_39 , V_34 ) ;
if ( F_34 ( & V_24 -> V_133 ) )
F_32 ( & V_24 -> V_134 ) ;
}
V_45:
return 0 ;
}
static int F_75 ( struct V_293 * V_294 , struct V_295 * V_296 ,
struct V_297 * V_298 )
{
struct V_94 * V_95 = F_9 ( V_294 ) ;
if ( V_298 -> V_299 || V_298 -> V_300 )
return - V_78 ;
memset ( V_296 , 0 , sizeof( * V_296 ) ) ;
V_296 -> V_301 = V_302 |
V_303 | V_304 |
V_305 | V_306 |
V_307 | V_308 ;
V_296 -> V_309 = V_310 ;
V_296 -> V_311 =
V_312 << 16 | V_313 << 8 | V_314 ;
V_296 -> V_315 = V_95 -> V_36 -> V_316 ;
V_296 -> V_317 = V_95 -> V_36 -> V_318 ;
V_296 -> V_319 = V_95 -> V_319 ;
V_296 -> V_320 = ~ 0ull ;
V_296 -> V_321 = V_322 ;
V_296 -> V_323 = V_324 ;
V_296 -> V_88 = V_325 ;
V_296 -> V_326 = V_325 ;
V_296 -> V_327 = V_328 ;
V_296 -> V_329 = V_330 ;
V_296 -> V_331 = V_332 ;
V_296 -> V_333 = V_95 -> V_334 . V_335 ;
V_296 -> V_336 = V_95 -> V_334 . V_335 ;
V_296 -> V_337 = 32767 ;
V_296 -> V_338 = V_339 ;
V_296 -> V_340 = V_341 ;
V_296 -> V_342 = 255 ;
V_296 -> V_343 = V_344 ;
V_296 -> V_345 = V_346 ;
V_296 -> V_347 = V_348 ;
V_296 -> V_349 = V_350 ;
V_296 -> V_351 = F_76 ( V_95 -> V_36 ) ;
V_296 -> V_352 = V_353 ;
V_296 -> V_354 = V_355 ;
V_296 -> V_356 = V_296 -> V_354 *
V_296 -> V_352 ;
return 0 ;
}
T_1 F_77 ( struct V_35 * V_36 )
{
return F_78 ( V_36 , V_36 -> V_243 -> V_357 ) ;
}
static int F_79 ( struct V_293 * V_294 ,
T_2 V_358 , struct V_359 * V_296 )
{
struct V_94 * V_95 = F_9 ( V_294 ) ;
struct V_35 * V_36 = V_95 -> V_36 ;
enum V_360 V_361 ;
T_3 V_109 = V_36 -> V_114 ;
V_61 V_362 ;
memset ( V_296 , 0 , sizeof( * V_296 ) ) ;
V_296 -> V_109 = V_109 ? V_109 : F_27 ( V_363 ) ;
V_296 -> V_364 = V_36 -> V_113 ;
V_296 -> V_365 = V_95 -> V_365 ;
V_296 -> V_366 = V_95 -> V_366 ;
V_362 = V_36 -> V_367 ;
V_296 -> V_47 = F_80 ( V_36 , V_362 ) + 1 ;
V_296 -> V_368 =
V_369 [ V_36 -> V_367 &
V_36 -> V_370 ] ;
V_296 -> V_371 = V_95 -> V_371 ;
V_296 -> V_372 = 1 ;
V_296 -> V_373 = 0x80000000 ;
V_296 -> V_374 = F_76 ( V_36 ) ;
V_296 -> V_375 = F_77 ( V_36 ) -
V_95 -> V_376 ;
V_296 -> V_377 = V_95 -> V_378 ;
V_296 -> V_379 = V_36 -> V_380 ;
V_296 -> V_381 = V_36 -> V_382 ;
V_296 -> V_383 = 1 ;
V_296 -> V_384 = 0 ;
V_296 -> V_385 = V_386 ? V_387 : V_388 ;
switch ( V_36 -> V_75 ) {
case 4096 :
V_361 = V_387 ;
break;
case 2048 :
V_361 = V_388 ;
break;
case 1024 :
V_361 = V_389 ;
break;
case 512 :
V_361 = V_390 ;
break;
case 256 :
V_361 = V_391 ;
break;
default:
V_361 = V_388 ;
}
V_296 -> V_392 = V_361 ;
V_296 -> V_393 = V_95 -> V_393 ;
return 0 ;
}
static int F_81 ( struct V_293 * V_38 ,
int V_394 ,
struct V_395 * V_396 )
{
int V_33 ;
if ( V_394 & ~ ( V_397 |
V_398 ) ) {
V_33 = - V_399 ;
goto V_45;
}
if ( V_394 & V_398 )
memcpy ( V_38 -> V_400 , V_396 -> V_400 , 64 ) ;
if ( V_394 & V_397 )
F_9 ( V_38 ) -> V_319 =
F_82 ( V_396 -> V_319 ) ;
V_33 = 0 ;
V_45:
return V_33 ;
}
static int F_83 ( struct V_293 * V_294 ,
T_2 V_358 , int V_401 ,
struct V_402 * V_296 )
{
struct V_94 * V_95 = F_9 ( V_294 ) ;
V_95 -> V_371 |= V_296 -> V_403 ;
V_95 -> V_371 &= ~ V_296 -> V_404 ;
if ( V_401 & V_405 )
F_84 ( V_95 -> V_36 , V_406 ) ;
if ( V_401 & V_407 )
V_95 -> V_378 = 0 ;
return 0 ;
}
static int F_85 ( struct V_293 * V_294 , T_2 V_358 ,
int V_408 , union V_409 * V_410 )
{
struct V_94 * V_95 = F_9 ( V_294 ) ;
int V_33 ;
if ( V_408 >= 1 ) {
V_33 = - V_78 ;
goto V_45;
}
V_410 -> V_411 . V_412 = V_95 -> V_413 ;
V_410 -> V_411 . V_414 = V_95 -> V_36 -> V_415 ;
V_33 = 0 ;
V_45:
return V_33 ;
}
static struct V_416 * F_86 ( struct V_293 * V_294 ,
struct V_2 * V_417 ,
struct V_297 * V_418 )
{
struct V_94 * V_95 = F_9 ( V_294 ) ;
struct V_419 * V_57 ;
struct V_416 * V_33 ;
V_57 = F_66 ( sizeof *V_57 , V_420 ) ;
if ( ! V_57 ) {
V_33 = F_87 ( - V_67 ) ;
goto V_45;
}
F_88 ( & V_95 -> V_421 ) ;
if ( V_95 -> V_422 == V_339 ) {
F_89 ( & V_95 -> V_421 ) ;
F_60 ( V_57 ) ;
V_33 = F_87 ( - V_67 ) ;
goto V_45;
}
V_95 -> V_422 ++ ;
F_89 ( & V_95 -> V_421 ) ;
V_57 -> V_423 = V_418 != NULL ;
V_33 = & V_57 -> V_424 ;
V_45:
return V_33 ;
}
static int F_90 ( struct V_416 * V_424 )
{
struct V_419 * V_57 = F_91 ( V_424 ) ;
struct V_94 * V_95 = F_9 ( V_424 -> V_38 ) ;
F_88 ( & V_95 -> V_421 ) ;
V_95 -> V_422 -- ;
F_89 ( & V_95 -> V_421 ) ;
F_60 ( V_57 ) ;
return 0 ;
}
static struct V_425 * F_92 ( struct V_416 * V_57 ,
struct V_426 * V_427 )
{
struct V_428 * V_58 ;
struct V_425 * V_33 ;
struct V_94 * V_95 = F_9 ( V_57 -> V_38 ) ;
unsigned long V_34 ;
if ( V_427 -> V_429 >= V_112 &&
V_427 -> V_429 != V_430 &&
! ( V_427 -> V_431 & V_432 ) ) {
V_33 = F_87 ( - V_78 ) ;
goto V_45;
}
if ( V_427 -> V_429 == 0 ) {
V_33 = F_87 ( - V_78 ) ;
goto V_45;
}
if ( V_427 -> V_433 < 1 ||
V_427 -> V_433 > V_57 -> V_38 -> V_434 ) {
V_33 = F_87 ( - V_78 ) ;
goto V_45;
}
V_58 = F_66 ( sizeof *V_58 , V_229 ) ;
if ( ! V_58 ) {
V_33 = F_87 ( - V_67 ) ;
goto V_45;
}
F_10 ( & V_95 -> V_435 , V_34 ) ;
if ( V_95 -> V_436 == V_330 ) {
F_15 ( & V_95 -> V_435 , V_34 ) ;
F_60 ( V_58 ) ;
V_33 = F_87 ( - V_67 ) ;
goto V_45;
}
V_95 -> V_436 ++ ;
F_15 ( & V_95 -> V_435 , V_34 ) ;
V_58 -> V_437 = * V_427 ;
V_58 -> V_437 . V_438 = F_52 ( V_427 -> V_438 ) ;
V_33 = & V_58 -> V_439 ;
V_45:
return V_33 ;
}
static int F_93 ( struct V_425 * V_439 )
{
struct V_94 * V_95 = F_9 ( V_439 -> V_38 ) ;
struct V_428 * V_58 = F_94 ( V_439 ) ;
unsigned long V_34 ;
F_10 ( & V_95 -> V_435 , V_34 ) ;
V_95 -> V_436 -- ;
F_15 ( & V_95 -> V_435 , V_34 ) ;
F_60 ( V_58 ) ;
return 0 ;
}
static int F_95 ( struct V_425 * V_439 , struct V_426 * V_427 )
{
struct V_428 * V_58 = F_94 ( V_439 ) ;
* V_427 = V_58 -> V_437 ;
V_427 -> V_438 = F_53 ( V_58 -> V_437 . V_438 ) ;
return 0 ;
}
unsigned F_76 ( struct V_35 * V_36 )
{
return F_36 ( V_36 -> V_419 [ 0 ] -> V_440 ) ;
}
unsigned F_96 ( struct V_35 * V_36 , unsigned V_408 )
{
unsigned V_33 ;
if ( V_408 >= F_36 ( V_36 -> V_419 [ 0 ] -> V_440 ) )
V_33 = 0 ;
else
V_33 = V_36 -> V_419 [ 0 ] -> V_440 [ V_408 ] ;
return V_33 ;
}
static int F_97 ( struct V_293 * V_294 , T_2 V_358 , T_3 V_408 ,
T_3 * V_441 )
{
struct V_94 * V_95 = F_9 ( V_294 ) ;
int V_33 ;
if ( V_408 >= F_76 ( V_95 -> V_36 ) ) {
V_33 = - V_78 ;
goto V_45;
}
* V_441 = F_96 ( V_95 -> V_36 , V_408 ) ;
V_33 = 0 ;
V_45:
return V_33 ;
}
static struct V_2 * F_98 ( struct V_293 * V_294 ,
struct V_297 * V_418 )
{
struct V_1 * V_417 ;
struct V_2 * V_33 ;
V_417 = F_66 ( sizeof *V_417 , V_420 ) ;
if ( ! V_417 ) {
V_33 = F_87 ( - V_67 ) ;
goto V_45;
}
V_33 = & V_417 -> V_3 ;
V_45:
return V_33 ;
}
static int F_99 ( struct V_2 * V_417 )
{
F_60 ( F_1 ( V_417 ) ) ;
return 0 ;
}
static void F_100 ( unsigned long V_442 )
{
struct V_35 * V_36 = (struct V_35 * ) V_442 ;
F_35 ( V_36 -> V_443 ) ;
F_101 ( & V_36 -> V_444 , V_445 + 1 ) ;
}
static int F_102 ( struct V_35 * V_36 )
{
if ( V_36 -> V_42 & V_446 ) {
F_103 ( V_36 , V_36 -> V_447 -> V_448 ,
0x2074076542310ULL ) ;
V_36 -> V_449 |= ( V_61 ) ( 1 << V_450 ) ;
F_103 ( V_36 , V_36 -> V_447 -> V_451 ,
V_36 -> V_449 ) ;
}
F_104 ( & V_36 -> V_444 , F_100 , ( unsigned long ) V_36 ) ;
V_36 -> V_444 . V_452 = V_445 + 1 ;
F_105 ( & V_36 -> V_444 ) ;
return 0 ;
}
static int F_106 ( struct V_35 * V_36 )
{
if ( V_36 -> V_42 & V_446 ) {
V_36 -> V_449 &= ~ ( ( V_61 ) ( 1 << V_450 ) ) ;
F_103 ( V_36 , V_36 -> V_447 -> V_451 ,
V_36 -> V_449 ) ;
}
F_107 ( & V_36 -> V_444 ) ;
return 0 ;
}
static int F_108 ( struct V_293 * V_294 , T_2 V_433 ,
struct V_453 * V_454 )
{
struct V_359 V_437 ;
int V_81 ;
V_81 = F_79 ( V_294 , V_433 , & V_437 ) ;
if ( V_81 )
return V_81 ;
V_454 -> V_374 = V_437 . V_374 ;
V_454 -> V_372 = V_437 . V_372 ;
V_454 -> V_455 = V_456 ;
V_454 -> V_457 = V_458 ;
return 0 ;
}
int F_109 ( struct V_35 * V_36 )
{
struct V_249 V_250 ;
struct V_94 * V_459 ;
struct V_293 * V_95 ;
struct V_186 * V_187 ;
unsigned V_30 ;
int V_33 ;
V_459 = (struct V_94 * ) F_110 ( sizeof *V_459 ) ;
if ( V_459 == NULL ) {
V_33 = - V_67 ;
goto V_45;
}
V_95 = & V_459 -> V_294 ;
if ( V_36 -> V_225 ) {
V_187 = F_111 ( V_36 -> V_225 , sizeof *V_187 ,
V_420 ) ;
if ( V_187 == NULL ) {
V_33 = - V_67 ;
goto V_230;
}
} else
V_187 = NULL ;
V_459 -> V_460 = V_187 ;
F_112 ( & V_459 -> V_421 ) ;
F_112 ( & V_459 -> V_435 ) ;
F_112 ( & V_459 -> V_461 ) ;
F_112 ( & V_459 -> V_462 ) ;
F_112 ( & V_459 -> V_463 ) ;
F_112 ( & V_459 -> V_464 ) ;
F_112 ( & V_459 -> V_135 . V_89 ) ;
F_112 ( & V_459 -> V_334 . V_89 ) ;
V_459 -> V_365 = F_27 ( V_363 ) ;
V_459 -> V_413 = F_82 ( 0xfe80000000000000ULL ) ;
V_33 = F_113 ( V_459 , V_465 ) ;
if ( V_33 )
goto V_466;
V_459 -> V_334 . V_335 = 1 << V_467 ;
V_459 -> V_334 . V_468 = F_114 ( V_459 -> V_334 . V_335 ,
sizeof( * V_459 -> V_334 . V_468 ) ,
V_420 ) ;
if ( V_459 -> V_334 . V_468 == NULL ) {
V_33 = - V_67 ;
goto V_469;
}
F_115 ( & V_459 -> V_470 ) ;
F_112 ( & V_459 -> V_141 ) ;
V_459 -> V_471 = V_310 ;
F_112 ( & V_459 -> V_472 ) ;
F_115 ( & V_459 -> V_143 [ 0 ] ) ;
F_115 ( & V_459 -> V_143 [ 1 ] ) ;
F_115 ( & V_459 -> V_143 [ 2 ] ) ;
F_115 ( & V_459 -> V_291 ) ;
F_115 ( & V_459 -> V_146 ) ;
F_115 ( & V_459 -> V_188 ) ;
V_459 -> V_142 = 0 ;
V_459 -> V_371 =
V_473 | V_474 ;
if ( V_36 -> V_42 & V_475 )
V_459 -> V_371 |= V_476 ;
V_459 -> V_477 [ 0 ] = V_478 ;
V_459 -> V_477 [ 1 ] = V_479 ;
V_459 -> V_477 [ 2 ] = V_480 ;
V_459 -> V_477 [ 3 ] = V_481 ;
V_459 -> V_477 [ 4 ] = V_482 ;
F_73 ( V_36 , & V_250 ) ;
V_459 -> V_483 = V_250 . V_252 ;
V_459 -> V_484 =
V_250 . V_254 ;
V_459 -> V_485 = V_250 . V_256 ;
V_459 -> V_486 = V_250 . V_258 ;
V_459 -> V_487 =
V_250 . V_272 ;
V_459 -> V_488 = V_250 . V_274 ;
V_459 -> V_489 = V_250 . V_276 ;
V_459 -> V_490 = V_250 . V_277 ;
V_459 -> V_491 = V_250 . V_278 ;
V_459 -> V_492 = V_250 . V_279 ;
V_459 -> V_493 =
V_250 . V_280 ;
V_459 -> V_494 =
V_250 . V_285 ;
V_459 -> V_495 = V_250 . V_288 ;
for ( V_30 = 0 ; V_30 < V_36 -> V_225 ; V_30 ++ , V_187 ++ )
F_57 ( & V_187 -> V_189 . V_190 , & V_459 -> V_188 ) ;
if ( ! V_319 )
V_319 = V_36 -> V_415 ;
V_459 -> V_319 = V_319 ;
V_459 -> V_496 = V_36 -> V_497 ;
V_459 -> V_36 = V_36 ;
F_116 ( V_95 -> V_498 , L_1 , V_499 ) ;
V_95 -> V_500 = V_501 ;
V_95 -> V_502 = V_36 -> V_415 ;
V_95 -> V_503 = V_504 ;
V_95 -> V_505 =
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
( 1ull << V_533 ) |
( 1ull << V_534 ) ;
V_95 -> V_535 = V_536 ;
V_95 -> V_434 = 1 ;
V_95 -> V_537 = 1 ;
V_95 -> V_538 = & V_36 -> V_539 -> V_95 ;
V_95 -> V_540 = F_75 ;
V_95 -> V_541 = F_81 ;
V_95 -> V_542 = F_79 ;
V_95 -> V_543 = F_83 ;
V_95 -> V_544 = F_97 ;
V_95 -> V_545 = F_85 ;
V_95 -> V_546 = F_98 ;
V_95 -> V_547 = F_99 ;
V_95 -> V_548 = F_86 ;
V_95 -> V_549 = F_90 ;
V_95 -> V_550 = F_92 ;
V_95 -> V_551 = F_93 ;
V_95 -> V_552 = F_95 ;
V_95 -> V_553 = V_554 ;
V_95 -> V_555 = V_556 ;
V_95 -> V_557 = V_558 ;
V_95 -> V_559 = V_560 ;
V_95 -> V_561 = V_562 ;
V_95 -> V_563 = V_564 ;
V_95 -> V_565 = V_566 ;
V_95 -> V_567 = V_568 ;
V_95 -> V_569 = F_16 ;
V_95 -> V_570 = F_19 ;
V_95 -> V_571 = V_572 ;
V_95 -> V_573 = V_574 ;
V_95 -> V_575 = V_576 ;
V_95 -> V_577 = V_578 ;
V_95 -> V_579 = V_580 ;
V_95 -> V_581 = V_582 ;
V_95 -> V_583 = V_584 ;
V_95 -> V_585 = V_586 ;
V_95 -> V_587 = V_588 ;
V_95 -> V_589 = V_590 ;
V_95 -> V_591 = V_592 ;
V_95 -> V_593 = V_594 ;
V_95 -> V_595 = V_596 ;
V_95 -> V_597 = V_598 ;
V_95 -> V_599 = V_600 ;
V_95 -> V_601 = V_602 ;
V_95 -> V_603 = V_604 ;
V_95 -> V_605 = V_606 ;
V_95 -> V_607 = & V_608 ;
V_95 -> V_609 = F_108 ;
snprintf ( V_95 -> V_400 , sizeof( V_95 -> V_400 ) ,
V_610 L_2 , F_117 () -> V_611 ) ;
V_33 = F_118 ( V_95 , NULL ) ;
if ( V_33 )
goto V_612;
V_33 = F_119 ( V_95 ) ;
if ( V_33 )
goto V_613;
F_102 ( V_36 ) ;
goto V_45;
V_613:
F_120 ( V_95 ) ;
V_612:
F_60 ( V_459 -> V_334 . V_468 ) ;
V_469:
F_60 ( V_459 -> V_135 . V_468 ) ;
V_466:
F_60 ( V_459 -> V_460 ) ;
V_230:
F_121 ( V_95 ) ;
F_122 ( V_36 , L_3 , - V_33 ) ;
V_459 = NULL ;
V_45:
V_36 -> V_443 = V_459 ;
return V_33 ;
}
void F_123 ( struct V_94 * V_95 )
{
struct V_293 * V_294 = & V_95 -> V_294 ;
T_1 V_614 ;
F_120 ( V_294 ) ;
F_106 ( V_95 -> V_36 ) ;
if ( ! F_37 ( & V_95 -> V_143 [ 0 ] ) ||
! F_37 ( & V_95 -> V_143 [ 1 ] ) ||
! F_37 ( & V_95 -> V_143 [ 2 ] ) )
F_122 ( V_95 -> V_36 , L_4 ) ;
if ( ! F_37 ( & V_95 -> V_291 ) )
F_122 ( V_95 -> V_36 , L_5 ) ;
if ( ! F_37 ( & V_95 -> V_146 ) )
F_122 ( V_95 -> V_36 , L_6 ) ;
if ( ! F_124 () )
F_122 ( V_95 -> V_36 , L_7 ) ;
V_614 = F_125 ( & V_95 -> V_135 ) ;
if ( V_614 )
F_122 ( V_95 -> V_36 , L_8 ,
V_614 ) ;
F_60 ( V_95 -> V_135 . V_468 ) ;
F_60 ( V_95 -> V_334 . V_468 ) ;
F_60 ( V_95 -> V_460 ) ;
F_121 ( V_294 ) ;
}
static T_5 F_126 ( struct V_38 * V_38 , struct V_615 * V_437 ,
char * V_616 )
{
struct V_94 * V_95 =
F_2 ( V_38 , struct V_94 , V_294 . V_95 ) ;
return sprintf ( V_616 , L_9 , V_95 -> V_36 -> V_318 ) ;
}
static T_5 F_127 ( struct V_38 * V_38 , struct V_615 * V_437 ,
char * V_616 )
{
struct V_94 * V_95 =
F_2 ( V_38 , struct V_94 , V_294 . V_95 ) ;
int V_33 ;
V_33 = V_95 -> V_36 -> V_617 ( V_95 -> V_36 , V_616 , 128 ) ;
if ( V_33 < 0 )
goto V_45;
strcat ( V_616 , L_10 ) ;
V_33 = strlen ( V_616 ) ;
V_45:
return V_33 ;
}
static T_5 F_128 ( struct V_38 * V_38 , struct V_615 * V_437 ,
char * V_616 )
{
struct V_94 * V_95 =
F_2 ( V_38 , struct V_94 , V_294 . V_95 ) ;
int V_30 ;
int V_10 ;
V_10 = sprintf ( V_616 ,
L_11
L_12
L_13
L_14
L_15
L_16
L_17
L_18
L_19
L_20
L_21
L_22
L_23 ,
V_95 -> V_618 , V_95 -> V_619 , V_95 -> V_620 ,
V_95 -> V_621 , V_95 -> V_622 , V_95 -> V_623 ,
V_95 -> V_624 , V_95 -> V_166 ,
V_95 -> V_625 , V_95 -> V_626 , V_95 -> V_232 ,
V_95 -> V_101 , V_95 -> V_627 ) ;
for ( V_30 = 0 ; V_30 < F_36 ( V_95 -> V_121 ) ; V_30 ++ ) {
const struct V_628 * V_629 = & V_95 -> V_121 [ V_30 ] ;
if ( ! V_629 -> V_123 && ! V_629 -> V_122 )
continue;
V_10 += sprintf ( V_616 + V_10 , L_24 , V_30 ,
( unsigned long long ) V_629 -> V_123 ,
( unsigned long long ) V_629 -> V_122 ) ;
}
return V_10 ;
}
static int F_119 ( struct V_293 * V_95 )
{
int V_30 ;
int V_33 ;
for ( V_30 = 0 ; V_30 < F_36 ( V_630 ) ; ++ V_30 ) {
V_33 = F_129 ( & V_95 -> V_95 ,
V_630 [ V_30 ] ) ;
if ( V_33 )
goto V_45;
}
return 0 ;
V_45:
for ( V_30 = 0 ; V_30 < F_36 ( V_630 ) ; ++ V_30 )
F_130 ( & V_95 -> V_95 , V_630 [ V_30 ] ) ;
return V_33 ;
}
