static int F_1 ( union V_1 * V_2 , struct V_3 * V_4 ,
T_1 * V_5 )
{
int V_6 ;
T_2 V_7 ;
switch ( V_4 -> V_8 ) {
case V_9 :
if ( V_4 -> V_10 & V_11 )
V_2 -> V_12 . V_13 = V_14 ;
else
V_2 -> V_12 . V_13 = V_15 ;
V_2 -> V_12 . V_16 = 0 ;
break;
case V_17 :
if ( V_4 -> V_10 & V_11 )
V_2 -> V_12 . V_13 = V_18 ;
else
V_2 -> V_12 . V_13 = V_19 ;
V_2 -> V_12 . V_16 = F_2 ( V_4 -> V_20 . V_21 ) ;
break;
default:
return - V_22 ;
}
if ( V_4 -> V_23 > V_24 )
return - V_22 ;
V_2 -> V_12 . V_25 [ 0 ] = 0 ;
V_2 -> V_12 . V_25 [ 1 ] = 0 ;
V_2 -> V_12 . V_25 [ 2 ] = 0 ;
V_7 = 0 ;
for ( V_6 = 0 ; V_6 < V_4 -> V_23 ; V_6 ++ ) {
if ( ( V_7 + V_4 -> V_26 [ V_6 ] . V_27 ) < V_7 )
return - V_28 ;
V_7 += V_4 -> V_26 [ V_6 ] . V_27 ;
V_2 -> V_12 . V_29 [ V_6 ] . V_30 = F_2 ( V_4 -> V_26 [ V_6 ] . V_31 ) ;
V_2 -> V_12 . V_29 [ V_6 ] . V_32 = F_2 ( V_4 -> V_26 [ V_6 ] . V_27 ) ;
V_2 -> V_12 . V_29 [ V_6 ] . V_33 = F_3 ( V_4 -> V_26 [ V_6 ] . V_34 ) ;
}
V_2 -> V_12 . V_35 = F_2 ( V_4 -> V_23 ) ;
* V_5 = 4 + ( ( V_4 -> V_23 ) << 1 ) ;
V_2 -> V_12 . V_7 = F_2 ( V_7 ) ;
return 0 ;
}
static int F_4 ( union V_1 * V_2 , struct V_3 * V_4 ,
T_1 * V_5 )
{
int V_6 ;
T_2 V_7 ;
if ( V_4 -> V_23 > V_24 )
return - V_22 ;
V_2 -> V_36 . V_13 = V_37 ;
V_2 -> V_36 . V_25 [ 0 ] = 0 ;
V_2 -> V_36 . V_25 [ 1 ] = 0 ;
V_2 -> V_36 . V_25 [ 2 ] = 0 ;
V_2 -> V_36 . V_38 = F_2 ( F_5 ( V_4 ) -> V_39 ) ;
V_2 -> V_36 . V_40 = F_3 ( F_5 ( V_4 ) -> V_41 ) ;
if ( V_4 -> V_8 == V_42 ) {
V_7 = 4 ;
V_2 -> V_36 . V_29 [ 0 ] . V_30 = V_4 -> V_20 . V_43 ;
V_2 -> V_36 . V_29 [ 0 ] . V_32 = F_2 ( 0 ) ;
V_2 -> V_36 . V_35 = F_2 ( 0 ) ;
* V_5 = 6 ;
} else {
V_7 = 0 ;
for ( V_6 = 0 ; V_6 < V_4 -> V_23 ; V_6 ++ ) {
if ( ( V_7 + V_4 -> V_26 [ V_6 ] . V_27 ) < V_7 ) {
return - V_28 ;
}
V_7 += V_4 -> V_26 [ V_6 ] . V_27 ;
V_2 -> V_36 . V_29 [ V_6 ] . V_30 =
F_2 ( V_4 -> V_26 [ V_6 ] . V_31 ) ;
V_2 -> V_36 . V_29 [ V_6 ] . V_32 =
F_2 ( V_4 -> V_26 [ V_6 ] . V_27 ) ;
V_2 -> V_36 . V_29 [ V_6 ] . V_33 =
F_3 ( V_4 -> V_26 [ V_6 ] . V_34 ) ;
}
V_2 -> V_36 . V_35 = F_2 ( V_4 -> V_23 ) ;
* V_5 = 5 + ( ( V_4 -> V_23 ) << 1 ) ;
}
V_2 -> V_36 . V_7 = F_2 ( V_7 ) ;
return 0 ;
}
static int F_6 ( union V_1 * V_2 , struct V_3 * V_4 ,
T_1 * V_5 )
{
if ( V_4 -> V_23 > 1 )
return - V_22 ;
V_2 -> V_44 . V_13 = V_45 ;
if ( V_4 -> V_8 == V_46 )
V_2 -> V_44 . V_47 = 1 ;
else
V_2 -> V_44 . V_47 = 0 ;
V_2 -> V_44 . V_25 [ 0 ] = 0 ;
V_2 -> V_44 . V_25 [ 1 ] = 0 ;
V_2 -> V_44 . V_16 = F_2 ( F_5 ( V_4 ) -> V_39 ) ;
V_2 -> V_44 . V_48 = F_3 ( F_5 ( V_4 ) -> V_41 ) ;
V_2 -> V_44 . V_49 = F_2 ( V_4 -> V_26 [ 0 ] . V_31 ) ;
V_2 -> V_44 . V_50 = F_2 ( V_4 -> V_26 [ 0 ] . V_27 ) ;
V_2 -> V_44 . V_51 = F_3 ( V_4 -> V_26 [ 0 ] . V_34 ) ;
* V_5 = sizeof( struct V_52 ) >> 3 ;
return 0 ;
}
static int F_7 ( union V_1 * V_2 , struct V_53 * V_4 ,
T_1 * V_5 , int * V_54 , struct V_55 * V_56 )
{
struct V_57 * V_58 = F_8 ( V_4 -> V_59 ) ;
int V_6 ;
T_3 * V_60 ;
if ( V_58 -> V_61 > V_62 )
return - V_22 ;
* V_54 = 1 ;
V_2 -> V_63 . V_30 = F_2 ( V_4 -> V_64 ) ;
V_2 -> V_63 . V_32 = F_2 ( V_58 -> V_65 . V_27 ) ;
V_2 -> V_63 . V_66 = F_2 ( V_58 -> V_65 . V_67 >> 32 ) ;
V_2 -> V_63 . V_68 =
F_2 ( V_58 -> V_65 . V_67 & 0xffffffff ) ;
V_2 -> V_63 . V_69 = F_2 (
F_9 ( V_58 -> V_61 ) |
F_10 ( F_11 ( V_4 -> V_59 -> V_70 ) - 12 ) |
F_12 ( V_71 ) |
F_13 ( F_14 ( V_4 -> V_72 ) ) ) ;
V_60 = & V_2 -> V_63 . V_73 [ 0 ] ;
for ( V_6 = 0 ; V_6 < V_58 -> V_61 ; V_6 ++ , V_60 ++ ) {
if ( V_6 == V_74 ) {
* V_54 = 2 ;
V_2 = (union V_1 * ) ( V_56 -> V_75 +
F_15 ( ( V_56 -> V_76 + 1 ) , V_56 -> V_77 ) ) ;
F_16 ( ( void * ) V_2 , V_78 , 0 ,
F_17 ( V_56 -> V_76 + 1 , V_56 -> V_77 ) ,
0 , 1 + V_58 -> V_61 - V_74 ,
V_79 ) ;
V_60 = & V_2 -> V_80 . V_73 [ 0 ] ;
}
* V_60 = F_3 ( ( V_81 ) V_58 -> V_82 [ V_6 ] ) ;
}
* V_5 = 5 + V_58 -> V_61 ;
if ( * V_5 > 15 )
* V_5 = 15 ;
return 0 ;
}
static int F_18 ( union V_1 * V_2 , struct V_3 * V_4 ,
T_1 * V_5 )
{
V_2 -> V_47 . V_30 = F_2 ( V_4 -> V_20 . V_21 ) ;
V_2 -> V_47 . V_25 = 0 ;
* V_5 = sizeof( struct V_83 ) >> 3 ;
return 0 ;
}
static int F_19 ( struct V_84 * V_85 , struct V_86 * V_26 ,
T_2 V_35 , T_2 * V_87 , T_1 * V_70 )
{
int V_6 ;
struct V_57 * V_58 ;
V_81 V_88 ;
for ( V_6 = 0 ; V_6 < V_35 ; V_6 ++ ) {
V_58 = F_20 ( V_85 , ( V_26 [ V_6 ] . V_31 ) >> 8 ) ;
if ( ! V_58 ) {
F_21 ( L_1 , V_89 , __LINE__ ) ;
return - V_90 ;
}
if ( ! V_58 -> V_91 . V_92 ) {
F_21 ( L_1 , V_89 , __LINE__ ) ;
return - V_90 ;
}
if ( V_58 -> V_91 . V_93 ) {
F_21 ( L_1 , V_89 , __LINE__ ) ;
return - V_90 ;
}
if ( V_26 [ V_6 ] . V_34 < V_58 -> V_91 . V_94 ) {
F_21 ( L_1 , V_89 , __LINE__ ) ;
return - V_22 ;
}
if ( V_26 [ V_6 ] . V_34 + ( ( V_81 ) V_26 [ V_6 ] . V_27 ) <
V_26 [ V_6 ] . V_34 ) {
F_21 ( L_1 , V_89 , __LINE__ ) ;
return - V_22 ;
}
if ( V_26 [ V_6 ] . V_34 + ( ( V_81 ) V_26 [ V_6 ] . V_27 ) >
V_58 -> V_91 . V_94 + ( ( V_81 ) V_58 -> V_91 . V_32 ) ) {
F_21 ( L_1 , V_89 , __LINE__ ) ;
return - V_22 ;
}
V_88 = V_26 [ V_6 ] . V_34 - V_58 -> V_91 . V_94 ;
V_88 += V_58 -> V_91 . V_94 &
( ( 1UL << ( 12 + V_58 -> V_91 . V_70 ) ) - 1 ) ;
V_87 [ V_6 ] = ( ( V_58 -> V_91 . V_87 -
V_85 -> V_95 . V_96 . V_97 ) >> 3 ) +
( V_88 >> ( 12 + V_58 -> V_91 . V_70 ) ) ;
V_70 [ V_6 ] = V_58 -> V_91 . V_70 ;
}
return 0 ;
}
static int F_22 ( struct V_98 * V_99 , union V_1 * V_2 ,
struct V_100 * V_4 )
{
int V_6 , V_101 = 0 ;
T_2 V_87 [ V_24 ] ;
T_1 V_70 [ V_24 ] ;
V_101 = F_19 ( V_99 -> V_85 , V_4 -> V_26 , V_4 -> V_23 , V_87 ,
V_70 ) ;
if ( V_101 )
return V_101 ;
V_2 -> V_102 . V_103 [ 0 ] = V_70 [ 0 ] ;
V_2 -> V_102 . V_103 [ 1 ] = V_70 [ 1 ] ;
V_2 -> V_102 . V_103 [ 2 ] = V_70 [ 2 ] ;
V_2 -> V_102 . V_103 [ 3 ] = V_70 [ 3 ] ;
V_2 -> V_102 . V_35 = F_2 ( V_4 -> V_23 ) ;
for ( V_6 = 0 ; V_6 < V_4 -> V_23 ; V_6 ++ ) {
V_2 -> V_102 . V_29 [ V_6 ] . V_30 = F_2 ( V_4 -> V_26 [ V_6 ] . V_31 ) ;
V_2 -> V_102 . V_29 [ V_6 ] . V_32 = F_2 ( V_4 -> V_26 [ V_6 ] . V_27 ) ;
V_2 -> V_102 . V_29 [ V_6 ] . V_33 = F_3 ( ( ( T_2 ) V_4 -> V_26 [ V_6 ] . V_34 ) &
( ( 1UL << ( 12 + V_70 [ V_6 ] ) ) - 1 ) ) ;
V_2 -> V_102 . V_87 [ V_6 ] = F_2 ( V_87 [ V_6 ] ) ;
}
for (; V_6 < V_24 ; V_6 ++ ) {
V_2 -> V_102 . V_29 [ V_6 ] . V_30 = 0 ;
V_2 -> V_102 . V_29 [ V_6 ] . V_32 = 0 ;
V_2 -> V_102 . V_29 [ V_6 ] . V_33 = 0 ;
V_2 -> V_102 . V_87 [ V_6 ] = 0 ;
}
V_99 -> V_56 . V_104 [ F_15 ( V_99 -> V_56 . V_105 ,
V_99 -> V_56 . V_106 ) ] . V_107 = V_4 -> V_107 ;
V_99 -> V_56 . V_104 [ F_15 ( V_99 -> V_56 . V_105 ,
V_99 -> V_56 . V_106 ) ] . V_87 = 0 ;
return 0 ;
}
static int F_23 ( struct V_98 * V_99 , union V_1 * V_2 ,
struct V_100 * V_4 )
{
int V_6 ;
T_2 V_87 ;
T_2 V_108 ;
V_87 = F_24 ( & V_99 -> V_85 -> V_95 , V_109 ) ;
if ( ! V_87 )
return - V_110 ;
V_108 = ( V_87 - V_99 -> V_85 -> V_95 . V_96 . V_97 ) >> 3 ;
V_2 -> V_102 . V_35 = F_2 ( V_4 -> V_23 ) ;
for ( V_6 = 0 ; V_6 < V_4 -> V_23 ; V_6 ++ ) {
if ( V_4 -> V_26 [ V_6 ] . V_27 > V_111 )
return - V_22 ;
V_2 -> V_102 . V_103 [ V_6 ] = V_112 ;
if ( V_4 -> V_26 [ V_6 ] . V_31 != 0 )
return - V_22 ;
V_2 -> V_102 . V_29 [ V_6 ] . V_30 = 0 ;
V_2 -> V_102 . V_29 [ V_6 ] . V_32 = F_2 ( V_4 -> V_26 [ V_6 ] . V_27 ) ;
V_2 -> V_102 . V_29 [ V_6 ] . V_33 = F_3 ( V_4 -> V_26 [ V_6 ] . V_34 ) ;
V_2 -> V_102 . V_87 [ V_6 ] = F_2 ( V_108 ) ;
V_108 += 2 ;
}
for (; V_6 < V_24 ; V_6 ++ ) {
V_2 -> V_102 . V_103 [ V_6 ] = 0 ;
V_2 -> V_102 . V_29 [ V_6 ] . V_30 = 0 ;
V_2 -> V_102 . V_29 [ V_6 ] . V_32 = 0 ;
V_2 -> V_102 . V_29 [ V_6 ] . V_33 = 0 ;
V_2 -> V_102 . V_87 [ V_6 ] = 0 ;
}
V_99 -> V_56 . V_104 [ F_15 ( V_99 -> V_56 . V_105 ,
V_99 -> V_56 . V_106 ) ] . V_107 = V_4 -> V_107 ;
V_99 -> V_56 . V_104 [ F_15 ( V_99 -> V_56 . V_105 ,
V_99 -> V_56 . V_106 ) ] . V_87 = V_87 ;
return 0 ;
}
int F_25 ( struct V_113 * V_114 , struct V_3 * V_4 ,
struct V_3 * * V_115 )
{
int V_101 = 0 ;
T_1 V_116 ( V_117 ) ;
enum V_118 V_118 = 0 ;
enum V_119 V_119 ;
struct V_98 * V_99 ;
T_2 V_120 ;
union V_1 * V_2 ;
T_2 V_121 ;
unsigned long V_122 ;
struct V_123 * V_124 ;
int V_54 = 1 ;
V_99 = F_26 ( V_114 ) ;
F_27 ( & V_99 -> V_125 , V_122 ) ;
if ( V_99 -> V_91 . V_92 > V_126 ) {
F_28 ( & V_99 -> V_125 , V_122 ) ;
V_101 = - V_22 ;
goto V_127;
}
V_121 = F_29 ( V_99 -> V_56 . V_128 , V_99 -> V_56 . V_129 ,
V_99 -> V_56 . V_130 ) ;
if ( V_121 == 0 ) {
F_28 ( & V_99 -> V_125 , V_122 ) ;
V_101 = - V_110 ;
goto V_127;
}
while ( V_4 ) {
if ( V_121 == 0 ) {
V_101 = - V_110 ;
break;
}
V_120 = F_15 ( V_99 -> V_56 . V_76 , V_99 -> V_56 . V_77 ) ;
V_2 = (union V_1 * ) ( V_99 -> V_56 . V_75 + V_120 ) ;
V_119 = 0 ;
if ( V_4 -> V_10 & V_11 )
V_119 |= V_131 ;
if ( V_4 -> V_10 & V_132 )
V_119 |= V_133 ;
V_124 = V_99 -> V_56 . V_134 +
F_15 ( V_99 -> V_56 . V_129 , V_99 -> V_56 . V_130 ) ;
switch ( V_4 -> V_8 ) {
case V_9 :
case V_17 :
if ( V_4 -> V_10 & V_135 )
V_119 |= V_136 ;
V_118 = V_137 ;
V_101 = F_1 ( V_2 , V_4 , & V_117 ) ;
break;
case V_138 :
case V_42 :
V_118 = V_139 ;
V_101 = F_4 ( V_2 , V_4 , & V_117 ) ;
break;
case V_140 :
case V_46 :
V_118 = V_141 ;
V_119 = 0 ;
V_101 = F_6 ( V_2 , V_4 , & V_117 ) ;
if ( V_101 )
break;
V_124 -> V_142 = V_2 -> V_44 . V_50 ;
if ( ! V_99 -> V_56 . V_143 )
V_99 -> V_56 . V_143 = V_124 ;
break;
case V_144 :
V_118 = V_78 ;
V_101 = F_7 ( V_2 , F_30 ( V_4 ) , & V_117 ,
& V_54 , & V_99 -> V_56 ) ;
break;
case V_145 :
if ( V_4 -> V_10 & V_135 )
V_119 |= V_146 ;
V_118 = V_147 ;
V_101 = F_18 ( V_2 , V_4 , & V_117 ) ;
break;
default:
F_21 ( L_2 , V_89 ,
V_4 -> V_8 ) ;
V_101 = - V_22 ;
}
if ( V_101 )
break;
V_2 -> V_12 . V_148 . V_149 . V_150 = V_99 -> V_56 . V_129 ;
V_124 -> V_107 = V_4 -> V_107 ;
V_124 -> V_8 = F_31 ( V_118 ) ;
V_124 -> V_129 = V_99 -> V_56 . V_129 ;
V_124 -> V_151 = 0 ;
V_124 -> V_152 = ( V_4 -> V_10 & V_132 ) ;
F_16 ( ( void * ) V_2 , V_118 , V_119 ,
F_17 ( V_99 -> V_56 . V_76 , V_99 -> V_56 . V_77 ) ,
0 , V_117 ,
( V_54 == 1 ) ? V_153 : V_154 ) ;
F_21 ( L_3 ,
V_89 , ( unsigned long long ) V_4 -> V_107 , V_120 ,
F_15 ( V_99 -> V_56 . V_129 , V_99 -> V_56 . V_130 ) ,
V_124 -> V_8 ) ;
V_4 = V_4 -> V_155 ;
V_121 -- ;
V_99 -> V_56 . V_76 += V_54 ;
++ ( V_99 -> V_56 . V_129 ) ;
}
F_28 ( & V_99 -> V_125 , V_122 ) ;
if ( F_32 ( & V_99 -> V_56 ) )
F_33 ( V_99 -> V_56 . V_156 , V_99 -> V_56 . V_157 ) ;
V_127:
if ( V_101 )
* V_115 = V_4 ;
return V_101 ;
}
int F_34 ( struct V_113 * V_114 , struct V_100 * V_4 ,
struct V_100 * * V_115 )
{
int V_101 = 0 ;
struct V_98 * V_99 ;
T_2 V_120 ;
union V_1 * V_2 ;
T_2 V_121 ;
unsigned long V_122 ;
V_99 = F_26 ( V_114 ) ;
F_27 ( & V_99 -> V_125 , V_122 ) ;
if ( V_99 -> V_91 . V_92 > V_126 ) {
F_28 ( & V_99 -> V_125 , V_122 ) ;
V_101 = - V_22 ;
goto V_127;
}
V_121 = F_29 ( V_99 -> V_56 . V_158 , V_99 -> V_56 . V_105 ,
V_99 -> V_56 . V_106 ) - 1 ;
if ( ! V_4 ) {
F_28 ( & V_99 -> V_125 , V_122 ) ;
V_101 = - V_110 ;
goto V_127;
}
while ( V_4 ) {
if ( V_4 -> V_23 > V_24 ) {
V_101 = - V_22 ;
break;
}
V_120 = F_15 ( V_99 -> V_56 . V_76 , V_99 -> V_56 . V_77 ) ;
V_2 = (union V_1 * ) ( V_99 -> V_56 . V_75 + V_120 ) ;
if ( V_121 )
if ( V_4 -> V_26 [ 0 ] . V_31 )
V_101 = F_22 ( V_99 , V_2 , V_4 ) ;
else
V_101 = F_23 ( V_99 , V_2 , V_4 ) ;
else
V_101 = - V_110 ;
if ( V_101 )
break;
F_16 ( ( void * ) V_2 , V_159 , V_133 ,
F_17 ( V_99 -> V_56 . V_76 , V_99 -> V_56 . V_77 ) ,
0 , sizeof( struct V_160 ) >> 3 , V_153 ) ;
F_21 ( L_4 ,
V_89 , ( unsigned long long ) V_4 -> V_107 ,
V_120 , V_99 -> V_56 . V_105 , V_99 -> V_56 . V_158 , V_2 ) ;
++ ( V_99 -> V_56 . V_105 ) ;
++ ( V_99 -> V_56 . V_76 ) ;
V_4 = V_4 -> V_155 ;
V_121 -- ;
}
F_28 ( & V_99 -> V_125 , V_122 ) ;
if ( F_32 ( & V_99 -> V_56 ) )
F_33 ( V_99 -> V_56 . V_156 , V_99 -> V_56 . V_157 ) ;
V_127:
if ( V_101 )
* V_115 = V_4 ;
return V_101 ;
}
static inline void F_35 ( struct V_161 * V_162 ,
T_1 * V_163 , T_1 * V_164 )
{
int V_165 = V_166 ;
int V_167 = 0 ;
int V_8 = - 1 ;
int V_168 = 0 ;
int V_169 = 0 ;
if ( V_162 ) {
V_165 = F_36 ( V_162 -> V_170 ) ;
V_8 = F_37 ( V_162 -> V_170 ) ;
V_168 = F_38 ( V_162 -> V_170 ) ;
V_169 = ( V_8 == V_19 ) ||
( V_8 == V_18 ) ;
V_167 = ( V_8 == V_37 ) ||
( V_168 && ( V_8 == V_171 ) ) ;
}
switch ( V_165 ) {
case V_172 :
if ( V_169 ) {
* V_163 = V_173 | V_174 ;
* V_164 = V_175 ;
} else {
* V_163 = V_173 | V_176 ;
* V_164 = V_177 ;
}
break;
case V_178 :
* V_163 = V_173 | V_176 ;
if ( ( V_8 == V_19 ) ||
( V_8 == V_18 ) )
* V_164 = V_175 ;
else
* V_164 = V_179 ;
break;
case V_180 :
* V_163 = V_173 | V_176 ;
* V_164 = V_179 ;
break;
case V_181 :
* V_163 = V_173 | V_176 ;
* V_164 = V_182 ;
break;
case V_183 :
* V_163 = V_173 | V_176 ;
* V_164 = V_184 ;
break;
case V_185 :
if ( V_167 ) {
* V_163 = V_186 | V_187 ;
* V_164 = V_188 ;
} else {
* V_163 = V_173 | V_176 ;
* V_164 = V_189 ;
}
break;
case V_190 :
case V_191 :
* V_163 = V_173 | V_174 ;
* V_164 = V_175 ;
break;
case V_192 :
case V_193 :
case V_166 :
* V_163 = V_173 | V_194 ;
* V_164 = 0 ;
break;
case V_195 :
* V_163 = V_186 | V_196 ;
* V_164 = V_197 ;
break;
case V_198 :
* V_163 = V_186 | V_187 ;
* V_164 = V_188 ;
break;
case V_199 :
* V_163 = V_200 | V_201 ;
* V_164 = V_202 ;
break;
case V_203 :
* V_163 = V_200 | V_201 ;
* V_164 = V_204 ;
break;
case V_205 :
* V_163 = V_186 | V_196 ;
* V_164 = V_206 ;
break;
case V_207 :
if ( V_167 ) {
* V_163 = V_186 | V_187 ;
* V_164 = V_208 ;
} else {
* V_163 = V_186 | V_196 ;
* V_164 = V_209 ;
}
break;
case V_210 :
* V_163 = V_173 | V_174 ;
* V_164 = V_211 ;
break;
case V_212 :
* V_163 = V_173 | V_174 ;
* V_164 = V_213 ;
break;
case V_214 :
* V_163 = V_186 | V_196 ;
* V_164 = V_215 ;
break;
case V_216 :
case V_217 :
case V_218 :
case V_219 :
* V_163 = V_186 | V_196 ;
* V_164 = V_220 ;
break;
case V_221 :
* V_163 = V_186 | V_222 ;
* V_164 = 0 ;
break;
case V_223 :
* V_163 = V_186 | V_196 ;
* V_164 = V_224 ;
break;
default:
* V_163 = V_173 | V_222 ;
* V_164 = 0 ;
break;
}
}
int F_39 ( struct V_225 * V_226 )
{
union V_1 * V_2 ;
struct V_227 * V_228 ;
T_1 V_5 = sizeof( struct V_52 ) >> 3 ;
F_21 ( L_5 , V_89 ) ;
V_228 = F_40 ( 40 , V_229 ) ;
if ( ! V_228 ) {
F_41 ( L_6 , V_89 ) ;
return - V_110 ;
}
V_2 = (union V_1 * ) F_42 ( V_228 , sizeof( struct V_52 ) ) ;
memset ( V_2 , 0 , sizeof( struct V_52 ) ) ;
V_2 -> V_44 . V_13 = V_45 ;
V_2 -> V_44 . V_25 [ 0 ] = 0 ;
V_2 -> V_44 . V_25 [ 1 ] = 0 ;
V_2 -> V_44 . V_16 = F_2 ( 1 ) ;
V_2 -> V_44 . V_48 = F_3 ( 1 ) ;
V_2 -> V_44 . V_49 = F_2 ( 1 ) ;
V_2 -> V_44 . V_50 = F_2 ( 0 ) ;
V_2 -> V_44 . V_51 = F_3 ( 1 ) ;
V_2 -> V_12 . V_230 . V_231 = F_2 ( F_43 ( V_141 ) ) ;
V_2 -> V_12 . V_230 . V_232 = F_2 ( F_44 ( V_226 -> V_233 ) |
F_45 ( V_5 ) ) ;
V_228 -> V_234 = V_235 ;
return F_46 ( V_226 -> V_236 . V_237 -> V_85 -> V_95 . V_238 , V_228 ) ;
}
int F_47 ( struct V_98 * V_99 , struct V_161 * V_162 )
{
union V_1 * V_2 ;
struct V_239 * V_240 ;
struct V_227 * V_228 ;
F_21 ( L_1 , V_89 , __LINE__ ) ;
V_228 = F_40 ( 40 , V_241 ) ;
if ( ! V_228 ) {
F_41 ( L_7 , V_89 ) ;
return - V_110 ;
}
V_2 = (union V_1 * ) F_42 ( V_228 , 40 ) ;
memset ( V_2 , 0 , 40 ) ;
V_2 -> V_12 . V_13 = V_242 ;
V_2 -> V_12 . V_7 = F_48 ( 4 ) ;
V_240 = (struct V_239 * ) V_2 -> V_12 . V_29 ;
F_35 ( V_162 , & V_240 -> V_243 , & V_240 -> V_164 ) ;
V_2 -> V_12 . V_230 . V_231 = F_2 ( F_43 ( V_137 ) |
F_49 ( V_133 | V_244 ) ) ;
V_2 -> V_12 . V_230 . V_232 = F_2 ( F_44 ( V_99 -> V_226 -> V_233 ) ) ;
V_228 -> V_234 = V_235 ;
return F_46 ( V_99 -> V_85 -> V_95 . V_238 , V_228 ) ;
}
static void F_50 ( struct V_98 * V_99 , struct V_245 * V_246 ,
struct V_245 * V_247 )
{
int V_248 ;
int V_249 ;
F_21 ( L_8 , V_89 , V_99 , V_246 , V_247 ) ;
F_51 ( & V_99 -> V_250 ) ;
F_52 ( & V_99 -> V_125 ) ;
F_53 ( & V_246 -> V_125 ) ;
F_53 ( & V_99 -> V_125 ) ;
F_54 ( & V_246 -> V_251 ) ;
F_55 ( & V_246 -> V_251 , & V_99 -> V_56 , & V_248 ) ;
V_249 = F_56 ( & V_99 -> V_56 , & V_246 -> V_251 , V_248 ) ;
F_52 ( & V_99 -> V_125 ) ;
F_52 ( & V_246 -> V_125 ) ;
if ( V_249 ) {
F_53 ( & V_246 -> V_252 ) ;
(* V_246 -> V_253 . V_254 )( & V_246 -> V_253 , V_246 -> V_253 . V_255 ) ;
F_52 ( & V_246 -> V_252 ) ;
}
F_53 ( & V_247 -> V_125 ) ;
F_53 ( & V_99 -> V_125 ) ;
F_54 ( & V_247 -> V_251 ) ;
F_57 ( & V_247 -> V_251 , & V_99 -> V_56 , & V_248 ) ;
V_249 = F_58 ( & V_99 -> V_56 , & V_247 -> V_251 , V_248 ) ;
F_52 ( & V_99 -> V_125 ) ;
F_52 ( & V_247 -> V_125 ) ;
if ( V_249 ) {
F_53 ( & V_247 -> V_252 ) ;
(* V_247 -> V_253 . V_254 )( & V_247 -> V_253 , V_247 -> V_253 . V_255 ) ;
F_52 ( & V_247 -> V_252 ) ;
}
if ( F_59 ( & V_99 -> V_250 ) )
F_60 ( & V_99 -> V_256 ) ;
F_53 ( & V_99 -> V_125 ) ;
}
static void F_61 ( struct V_98 * V_99 )
{
struct V_245 * V_246 , * V_247 ;
V_246 = F_62 ( V_99 -> V_85 , V_99 -> V_91 . V_257 ) ;
V_247 = F_62 ( V_99 -> V_85 , V_99 -> V_91 . V_258 ) ;
if ( V_99 -> V_114 . V_259 ) {
F_63 ( & V_99 -> V_56 ) ;
F_64 ( & V_246 -> V_251 ) ;
F_53 ( & V_246 -> V_252 ) ;
(* V_246 -> V_253 . V_254 )( & V_246 -> V_253 , V_246 -> V_253 . V_255 ) ;
F_52 ( & V_246 -> V_252 ) ;
if ( V_247 != V_246 ) {
F_64 ( & V_247 -> V_251 ) ;
F_53 ( & V_247 -> V_252 ) ;
(* V_247 -> V_253 . V_254 )( & V_247 -> V_253 ,
V_247 -> V_253 . V_255 ) ;
F_52 ( & V_247 -> V_252 ) ;
}
return;
}
F_50 ( V_99 , V_246 , V_247 ) ;
}
T_4 F_65 ( struct V_98 * V_99 )
{
union V_1 * V_2 = V_99 -> V_56 . V_75 ;
T_4 V_248 = 0 ;
while ( V_248 < V_260 && F_66 ( (struct V_261 * ) V_2 ) == V_159 ) {
V_248 ++ ;
V_2 ++ ;
}
F_21 ( L_9 , V_89 , V_99 , V_248 ) ;
return V_248 ;
}
static int F_67 ( struct V_84 * V_85 , struct V_98 * V_99 ,
enum V_262 V_263 ,
struct V_264 * V_265 )
{
struct V_266 V_267 ;
int V_268 ;
V_267 . V_269 = V_99 -> V_226 -> V_233 ;
V_267 . V_157 = V_99 -> V_56 . V_157 ;
V_267 . V_270 = V_99 -> V_91 . V_271 ;
V_267 . V_272 = V_99 -> V_91 . V_258 ;
V_267 . V_273 = V_99 -> V_91 . V_257 ;
V_267 . V_274 = V_99 -> V_56 . V_274 ;
V_267 . V_275 = 1 << V_99 -> V_56 . V_106 ;
V_267 . V_276 = V_277 |
V_99 -> V_91 . V_278 . V_279 |
( V_99 -> V_91 . V_278 . V_280 << 1 ) |
( V_99 -> V_91 . V_278 . V_281 << 2 ) ;
V_267 . V_282 = V_283 |
V_284 |
V_285 ;
if ( ! V_99 -> V_114 . V_259 )
V_267 . V_282 |= V_286 |
V_287 ;
V_267 . V_288 = V_99 -> V_226 -> V_289 ;
V_267 . V_290 = V_99 -> V_91 . V_291 ;
V_267 . V_292 = V_99 -> V_91 . V_293 ;
V_267 . V_294 = V_99 -> V_56 . V_295 ;
V_267 . V_296 = ( 1UL << V_99 -> V_56 . V_77 ) ;
V_267 . V_297 = F_65 ( V_99 ) ;
V_267 . V_298 = V_99 -> V_91 . V_278 . V_299 ? V_300 : 0 ;
V_267 . V_301 = V_99 -> V_226 -> V_302 -> V_303 ;
if ( V_304 ) {
V_267 . V_305 = V_306 ;
if ( V_267 . V_290 == 0 && V_99 -> V_91 . V_278 . V_299 )
V_267 . V_290 = 1 ;
if ( V_267 . V_292 == 0 && ! V_99 -> V_91 . V_278 . V_299 )
V_267 . V_292 = 1 ;
} else
V_267 . V_305 = 0 ;
V_267 . V_307 = V_99 -> V_226 -> V_308 ;
F_21 ( L_10 ,
V_89 ,
V_267 . V_274 , V_267 . V_275 ,
V_267 . V_298 , V_267 . V_282 ) ;
V_268 = F_68 ( & V_85 -> V_95 , & V_267 ) ;
F_21 ( L_11 , V_89 , V_268 ) ;
return V_268 ;
}
int F_69 ( struct V_84 * V_85 , struct V_98 * V_99 ,
enum V_262 V_263 ,
struct V_264 * V_265 ,
int V_309 )
{
int V_268 = 0 ;
struct V_264 V_310 = V_99 -> V_91 ;
unsigned long V_122 ;
int V_311 = 0 ;
int V_312 = 0 ;
int abort = 0 ;
int free = 0 ;
struct V_225 * V_226 = NULL ;
F_21 ( L_12 , V_89 ,
V_99 , V_99 -> V_56 . V_157 , V_99 -> V_226 , V_99 -> V_91 . V_92 ,
( V_263 & V_313 ) ? V_265 -> V_314 : - 1 ) ;
F_27 ( & V_99 -> V_125 , V_122 ) ;
if ( V_263 & V_315 ) {
if ( V_99 -> V_91 . V_92 != V_316 ) {
V_268 = - V_90 ;
goto V_127;
}
if ( V_263 & V_317 )
V_310 . V_318 = V_265 -> V_318 ;
if ( V_263 & V_319 )
V_310 . V_320 = V_265 -> V_320 ;
if ( V_263 & V_321 )
V_310 . V_322 = V_265 -> V_322 ;
if ( V_263 & V_323 ) {
if ( V_265 -> V_291 >
V_85 -> V_91 . V_324 ) {
V_268 = - V_22 ;
goto V_127;
}
V_310 . V_291 = V_265 -> V_291 ;
}
if ( V_263 & V_325 ) {
if ( V_265 -> V_293 >
V_85 -> V_91 . V_326 ) {
V_268 = - V_22 ;
goto V_127;
}
V_310 . V_293 = V_265 -> V_293 ;
}
V_99 -> V_91 = V_310 ;
}
if ( ! ( V_263 & V_313 ) )
goto V_127;
if ( V_99 -> V_91 . V_92 == V_265 -> V_314 )
goto V_127;
switch ( V_99 -> V_91 . V_92 ) {
case V_316 :
switch ( V_265 -> V_314 ) {
case V_126 :
if ( ! ( V_263 & V_327 ) ) {
V_268 = - V_22 ;
goto V_127;
}
if ( ! ( V_263 & V_328 ) ) {
V_268 = - V_22 ;
goto V_127;
}
V_99 -> V_91 . V_278 = V_265 -> V_278 ;
V_99 -> V_91 . V_329 = V_265 -> V_329 ;
V_99 -> V_226 = V_99 -> V_91 . V_329 ;
V_99 -> V_91 . V_92 = V_126 ;
F_70 ( & V_99 -> V_226 -> V_236 ) ;
F_28 ( & V_99 -> V_125 , V_122 ) ;
V_268 = F_67 ( V_85 , V_99 , V_263 , V_265 ) ;
F_27 ( & V_99 -> V_125 , V_122 ) ;
if ( V_268 )
goto V_101;
break;
case V_330 :
V_99 -> V_91 . V_92 = V_330 ;
F_61 ( V_99 ) ;
break;
default:
V_268 = - V_22 ;
goto V_127;
}
break;
case V_126 :
switch ( V_265 -> V_314 ) {
case V_331 :
F_71 ( F_72 ( & V_99 -> V_226 -> V_236 . V_332 ) < 2 ) ;
V_99 -> V_91 . V_92 = V_331 ;
if ( ! V_309 ) {
abort = 0 ;
V_311 = 1 ;
V_226 = V_99 -> V_226 ;
F_70 ( & V_226 -> V_236 ) ;
}
break;
case V_333 :
V_99 -> V_91 . V_92 = V_333 ;
if ( V_99 -> V_114 . V_259 )
F_63 ( & V_99 -> V_56 ) ;
if ( ! V_309 )
V_312 = 1 ;
break;
case V_330 :
V_99 -> V_91 . V_92 = V_330 ;
if ( ! V_309 ) {
abort = 1 ;
V_311 = 1 ;
V_226 = V_99 -> V_226 ;
F_70 ( & V_226 -> V_236 ) ;
}
goto V_101;
break;
default:
V_268 = - V_22 ;
goto V_127;
}
break;
case V_331 :
if ( ! V_309 ) {
V_268 = - V_22 ;
goto V_127;
}
switch ( V_265 -> V_314 ) {
case V_316 :
F_61 ( V_99 ) ;
V_99 -> V_91 . V_92 = V_316 ;
V_99 -> V_91 . V_329 = NULL ;
F_73 ( & V_99 -> V_226 -> V_236 ) ;
V_99 -> V_226 = NULL ;
F_60 ( & V_99 -> V_256 ) ;
break;
case V_330 :
goto V_101;
default:
V_268 = - V_22 ;
goto V_101;
}
break;
case V_330 :
if ( V_265 -> V_314 != V_316 ) {
V_268 = - V_22 ;
goto V_127;
}
if ( ! F_74 ( V_99 -> V_56 . V_128 , V_99 -> V_56 . V_129 ) ||
! F_74 ( V_99 -> V_56 . V_158 , V_99 -> V_56 . V_105 ) ) {
V_268 = - V_22 ;
goto V_127;
}
V_99 -> V_91 . V_92 = V_316 ;
break;
case V_333 :
if ( ! V_309 ) {
V_268 = - V_22 ;
goto V_127;
}
goto V_101;
break;
default:
F_41 ( L_13 , V_89 , V_99 -> V_91 . V_92 ) ;
V_268 = - V_22 ;
goto V_101;
break;
}
goto V_127;
V_101:
F_21 ( L_14 , V_89 , V_99 -> V_226 ,
V_99 -> V_56 . V_157 ) ;
V_99 -> V_91 . V_329 = NULL ;
V_226 = V_99 -> V_226 ;
V_99 -> V_226 = NULL ;
V_99 -> V_91 . V_92 = V_330 ;
free = 1 ;
F_60 ( & V_99 -> V_256 ) ;
F_71 ( ! V_226 ) ;
F_61 ( V_99 ) ;
V_127:
F_28 ( & V_99 -> V_125 , V_122 ) ;
if ( V_312 )
F_47 ( V_99 , NULL ) ;
if ( V_311 ) {
F_75 ( V_226 , abort , V_229 ) ;
F_73 ( & V_226 -> V_236 ) ;
}
if ( free )
F_73 ( & V_226 -> V_236 ) ;
F_21 ( L_15 , V_89 , V_99 -> V_91 . V_92 ) ;
return V_268 ;
}
