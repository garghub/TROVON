static int
F_1 ( struct V_1 * V_2 , unsigned int V_3 ,
enum V_4 type , struct V_5 * V_6 , int V_7 )
{
int V_8 , V_9 = 0 , V_10 ;
int V_11 ;
struct V_12 * * V_13 ;
if ( V_3 == 0 && V_2 -> V_14 [ 0 ] . V_15 ) {
V_6 [ V_9 ] . V_16 = NULL ;
V_6 [ V_9 ] . V_17 = V_2 -> V_14 [ 0 ] . V_18 ;
V_6 [ V_9 ] . V_19 = V_2 -> V_14 [ 0 ] . V_15 ;
++ V_9 ;
}
V_8 = V_2 -> V_20 ;
V_13 = V_2 -> V_21 + ( V_2 -> V_11 >> V_22 ) ;
V_11 = V_2 -> V_11 & ~ V_23 ;
V_10 = 0 ;
while ( V_8 && V_9 < V_7 ) {
if ( ! V_13 [ V_10 ] ) {
V_13 [ V_10 ] = F_2 ( V_24 ) ;
if ( ! V_13 [ V_10 ] )
return - V_25 ;
}
V_6 [ V_9 ] . V_16 = V_13 [ V_10 ] ;
V_6 [ V_9 ] . V_17 = ( void * ) ( unsigned long ) V_11 ;
V_6 [ V_9 ] . V_19 = F_3 ( V_26 , V_27 - V_11 , V_8 ) ;
if ( V_6 [ V_9 ] . V_19 > V_27 )
return - V_28 ;
V_8 -= V_6 [ V_9 ] . V_19 ;
++ V_9 ;
++ V_10 ;
V_11 = 0 ;
}
if ( V_8 && V_9 == V_7 )
return - V_28 ;
if ( V_2 -> V_29 [ 0 ] . V_15 ) {
if ( V_2 -> V_29 [ 0 ] . V_15 < 4 && V_30 )
return V_9 ;
if ( V_9 == V_7 )
return - V_28 ;
V_6 [ V_9 ] . V_16 = NULL ;
V_6 [ V_9 ] . V_17 = V_2 -> V_29 [ 0 ] . V_18 ;
V_6 [ V_9 ] . V_19 = V_2 -> V_29 [ 0 ] . V_15 ;
++ V_9 ;
}
return V_9 ;
}
static T_1
F_4 ( struct V_31 * V_32 , struct V_1 * V_33 ,
struct V_34 * V_35 , enum V_4 type )
{
struct V_36 * V_37 = F_5 ( V_32 ) ;
struct V_38 * V_39 = F_6 ( V_32 -> V_40 ) ;
int V_9 , V_7 , V_41 = 0 ;
unsigned int V_3 ;
struct V_5 * V_6 = V_37 -> V_42 ;
struct V_43 * V_44 = NULL ;
struct V_45 * V_46 = NULL ;
struct V_47 * V_48 = NULL ;
T_2 * V_49 = V_35 -> V_50 . V_51 ;
int (* F_7)( struct V_38 * , struct V_5 * , int , bool );
if ( type == V_52 || type == V_53 ) {
V_44 = (struct V_43 * ) V_49 ;
} else {
* V_49 ++ = V_54 ;
if ( type == V_55 )
* V_49 ++ = V_54 ;
V_46 = (struct V_45 * ) V_49 ;
V_48 = (struct V_47 * ) ( V_46 + 1 ) ;
}
if ( type == V_55 || type == V_53 )
V_3 = 0 ;
else
V_3 = V_33 -> V_14 [ 0 ] . V_15 ;
V_7 = F_1 ( V_33 , V_3 , type , V_6 , V_56 ) ;
if ( V_7 < 0 )
return V_7 ;
F_7 = V_39 -> V_57 . V_58 -> V_59 ;
do {
V_9 = F_7 ( V_39 , V_6 , V_7 , V_48 != NULL ) ;
if ( V_9 <= 0 )
goto V_60;
if ( V_44 ) {
V_44 -> V_61 = V_62 ;
V_44 -> V_63 = F_8 ( V_3 ) ;
V_44 -> V_64 . V_65 =
F_8 ( V_6 -> V_66 ) ;
V_44 -> V_64 . V_67 =
F_8 ( V_6 -> V_19 ) ;
F_9 (
( T_2 * ) & V_44 -> V_64 . V_68 ,
V_6 -> V_69 ) ;
F_10 ( L_1
L_2 , V_70 ,
V_6 -> V_19 , ( unsigned long long ) V_6 -> V_69 ,
V_6 -> V_66 , V_3 , V_9 < V_7 ? L_3 : L_4 ) ;
V_44 ++ ;
V_39 -> V_71 . V_72 ++ ;
} else {
V_48 -> V_73 . V_65 =
F_8 ( V_6 -> V_66 ) ;
V_48 -> V_73 . V_67 =
F_8 ( V_6 -> V_19 ) ;
F_9 (
( T_2 * ) & V_48 -> V_73 . V_68 ,
V_6 -> V_69 ) ;
F_10 ( L_5
L_6 , V_70 ,
( type == V_55 ) ? L_7 : L_8 ,
V_6 -> V_19 , ( unsigned long long ) V_6 -> V_69 ,
V_6 -> V_66 , V_9 < V_7 ? L_3 : L_4 ) ;
V_48 ++ ;
if ( type == V_55 )
V_39 -> V_71 . V_74 ++ ;
else
V_39 -> V_71 . V_75 ++ ;
V_39 -> V_71 . V_76 += V_6 -> V_19 ;
}
V_41 ++ ;
V_6 += V_9 ;
V_7 -= V_9 ;
} while ( V_7 );
V_37 -> V_77 = V_41 ;
if ( V_44 ) {
V_49 = ( T_2 * ) V_44 ;
* V_49 ++ = V_54 ;
* V_49 ++ = V_54 ;
* V_49 ++ = V_54 ;
} else {
V_46 -> V_78 = V_62 ;
V_46 -> V_79 = F_8 ( V_41 ) ;
V_49 = ( T_2 * ) V_48 ;
if ( type == V_80 ) {
* V_49 ++ = V_54 ;
* V_49 ++ = V_54 ;
}
}
return ( unsigned char * ) V_49 - ( unsigned char * ) V_35 ;
V_60:
for ( V_3 = 0 ; V_41 -- ; )
V_3 += V_39 -> V_57 . V_58 -> V_81 ( V_39 ,
& V_37 -> V_42 [ V_3 ] ) ;
return V_9 ;
}
static int
F_11 ( struct V_31 * V_32 , int V_82 )
{
int V_83 , V_84 , V_85 ;
int V_86 ;
unsigned char * V_87 , * V_88 ;
struct V_38 * V_39 = F_6 ( V_32 -> V_40 ) ;
int V_11 ;
struct V_12 * * V_13 ;
V_88 = V_32 -> V_89 [ 0 ] . V_18 ;
V_85 = V_32 -> V_89 [ 0 ] . V_15 ;
V_88 += V_85 ;
V_82 -= ( V_85 + 36 ) ;
if ( V_82 < 0 || V_32 -> V_90 - V_85 < V_91 )
V_82 = 0 ;
F_10 ( L_9 ,
V_70 , V_82 , V_88 , V_32 -> V_90 , V_85 ) ;
V_86 = V_32 -> V_92 . V_20 ;
if ( V_32 -> V_92 . V_29 [ 0 ] . V_15 ) {
V_85 = V_32 -> V_92 . V_29 [ 0 ] . V_15 ;
if ( V_88 + V_86 != V_32 -> V_92 . V_29 [ 0 ] . V_18 ) {
memmove ( V_88 + V_86 ,
V_32 -> V_92 . V_29 [ 0 ] . V_18 , V_85 ) ;
V_39 -> V_71 . V_93 += V_85 ;
}
F_10 ( L_10 ,
V_70 , V_88 + V_86 , V_85 ) ;
V_32 -> V_89 [ 0 ] . V_15 += V_85 ;
}
V_39 -> V_71 . V_93 += V_86 ;
V_11 = V_32 -> V_92 . V_11 ;
V_13 = V_32 -> V_92 . V_21 + ( V_11 >> V_22 ) ;
V_11 &= ~ V_23 ;
V_84 = F_12 ( V_11 + V_86 ) >> V_22 ;
for ( V_83 = 0 ; V_86 && V_83 < V_84 ; V_83 ++ ) {
V_85 = V_27 - V_11 ;
if ( V_85 > V_86 )
V_85 = V_86 ;
F_10 ( L_11 ,
V_70 , V_83 , V_88 , V_86 , V_85 ) ;
V_87 = F_13 ( V_13 [ V_83 ] ) ;
memcpy ( V_88 , V_87 + V_11 , V_85 ) ;
F_14 ( V_87 ) ;
V_32 -> V_89 [ 0 ] . V_15 += V_85 ;
V_88 += V_85 ;
V_86 -= V_85 ;
V_11 = 0 ;
}
return V_82 ;
}
int
F_15 ( struct V_31 * V_32 )
{
struct V_94 * V_95 = V_32 -> V_40 ;
struct V_38 * V_39 = F_6 ( V_95 ) ;
struct V_36 * V_37 = F_5 ( V_32 ) ;
char * V_96 ;
T_3 V_97 , V_98 ;
T_1 V_99 ;
enum V_4 V_100 , V_101 ;
struct V_34 * V_35 ;
V_96 = V_32 -> V_89 [ 0 ] . V_18 ;
V_97 = V_32 -> V_89 [ 0 ] . V_15 ;
V_35 = F_16 ( V_37 -> V_102 ) ;
V_35 -> V_103 = V_32 -> V_104 ;
V_35 -> V_105 = V_106 ;
V_35 -> V_107 = F_8 ( V_39 -> V_108 . V_109 ) ;
V_35 -> V_110 = V_111 ;
if ( V_32 -> V_112 . V_113 <= F_17 ( V_32 ) )
V_101 = V_114 ;
else if ( V_32 -> V_112 . V_20 == 0 )
V_101 = V_55 ;
else if ( V_32 -> V_112 . V_115 & V_116 )
V_101 = V_80 ;
else
V_101 = V_55 ;
if ( V_32 -> V_92 . V_8 <= F_18 ( V_32 ) )
V_100 = V_114 ;
else if ( V_32 -> V_92 . V_20 == 0 )
V_100 = V_53 ;
else
V_100 = V_52 ;
if ( V_100 != V_114 && V_101 == V_55 )
V_101 = V_114 ;
if ( V_100 != V_114 && V_101 != V_114 ) {
F_10 ( L_12 ,
V_70 ) ;
return - V_28 ;
}
V_99 = V_117 ;
V_98 = 0 ;
if ( V_100 == V_114 ) {
V_98 = F_11 ( V_32 ,
F_19 ( V_32 ) ) ;
if ( V_98 ) {
V_35 -> V_110 = V_118 ;
V_35 -> V_50 . V_119 . V_120 =
F_8 ( F_19 ( V_32 ) ) ;
V_35 -> V_50 . V_119 . V_121 =
F_8 ( V_91 ) ;
V_35 -> V_50 . V_119 . V_122 [ 0 ] = V_54 ;
V_35 -> V_50 . V_119 . V_122 [ 1 ] = V_54 ;
V_35 -> V_50 . V_119 . V_122 [ 2 ] = V_54 ;
V_99 += 2 * sizeof( V_26 ) ;
if ( V_101 != V_114 ) {
F_10 ( L_13 ,
V_70 ) ;
return - V_28 ;
}
} else {
V_35 -> V_50 . V_123 . V_124 [ 0 ] = V_54 ;
V_35 -> V_50 . V_123 . V_124 [ 1 ] = V_54 ;
V_35 -> V_50 . V_123 . V_124 [ 2 ] = V_54 ;
V_97 = V_32 -> V_89 [ 0 ] . V_15 ;
if ( V_101 == V_114 )
V_101 = V_55 ;
}
}
if ( V_100 != V_114 ) {
V_99 = F_4 ( V_32 , & V_32 -> V_92 ,
V_35 , V_100 ) ;
V_101 = V_100 ;
} else if ( V_101 != V_114 ) {
V_99 = F_4 ( V_32 , & V_32 -> V_112 ,
V_35 , V_101 ) ;
}
if ( V_99 < 0 )
return V_99 ;
F_10 ( L_14
L_15 ,
V_70 , V_125 [ V_101 ] , V_99 , V_97 , V_98 ,
V_35 , V_96 , F_20 ( V_37 -> V_102 ) ) ;
V_37 -> V_126 [ 0 ] . V_127 = F_21 ( V_37 -> V_102 ) ;
V_37 -> V_126 [ 0 ] . V_128 = V_99 ;
V_37 -> V_126 [ 0 ] . V_129 = F_20 ( V_37 -> V_102 ) ;
V_37 -> V_126 [ 1 ] . V_127 = F_21 ( V_37 -> V_130 ) ;
V_37 -> V_126 [ 1 ] . V_128 = V_97 ;
V_37 -> V_126 [ 1 ] . V_129 = F_20 ( V_37 -> V_130 ) ;
V_37 -> V_131 = 2 ;
if ( V_98 ) {
struct V_132 * V_133 = & V_39 -> V_134 ;
V_37 -> V_126 [ 2 ] . V_127 = F_21 ( V_133 -> V_135 ) ;
V_37 -> V_126 [ 2 ] . V_128 = V_98 ;
V_37 -> V_126 [ 2 ] . V_129 = F_20 ( V_133 -> V_135 ) ;
V_37 -> V_126 [ 3 ] . V_127 = V_37 -> V_126 [ 1 ] . V_127 + V_97 ;
V_37 -> V_126 [ 3 ] . V_128 = V_32 -> V_90 - V_97 ;
V_37 -> V_126 [ 3 ] . V_129 = F_20 ( V_37 -> V_130 ) ;
V_37 -> V_131 = 4 ;
}
return 0 ;
}
static int
F_22 ( struct V_136 * V_137 , unsigned int V_138 , int V_139 , T_2 * * V_140 )
{
unsigned int V_83 , V_141 ;
struct V_47 * V_48 ;
char * V_96 = ( char * ) F_16 ( V_137 -> V_142 ) ;
V_83 = F_23 ( * * V_140 ) ;
if ( V_83 > V_138 )
return - 1 ;
V_48 = (struct V_47 * ) ( * V_140 + 1 ) ;
V_141 = 0 ;
while ( V_83 -- ) {
struct V_143 * V_6 = & V_48 -> V_73 ;
F_24 (FACILITY) {
T_4 V_144 ;
F_25 ( ( T_2 * ) & V_6 -> V_68 , & V_144 ) ;
F_10 ( L_16 ,
V_70 ,
F_23 ( V_6 -> V_67 ) ,
( unsigned long long ) V_144 ,
F_23 ( V_6 -> V_65 ) ) ;
}
V_141 += F_23 ( V_6 -> V_67 ) ;
++ V_48 ;
}
if ( V_139 ) {
T_2 * V_145 = ( T_2 * ) V_48 ;
if ( * V_145 ++ != V_54 )
return - 1 ;
V_48 = (struct V_47 * ) V_145 ;
}
if ( ( char * ) V_48 > V_96 + V_137 -> V_146 )
return - 1 ;
* V_140 = ( T_2 * ) V_48 ;
return V_141 ;
}
static void
F_26 ( struct V_31 * V_32 , char * V_87 , int V_86 , int V_82 )
{
int V_83 , V_84 , V_85 , V_147 ;
char * V_88 ;
struct V_12 * * V_13 ;
int V_11 ;
V_85 = V_32 -> V_112 . V_14 [ 0 ] . V_15 ;
if ( V_85 > V_86 ) {
V_85 = V_86 ;
V_32 -> V_112 . V_14 [ 0 ] . V_15 = V_85 ;
}
F_10 ( L_17 ,
V_70 , V_87 , V_86 , V_85 ) ;
V_32 -> V_112 . V_14 [ 0 ] . V_18 = V_87 ;
V_87 += V_85 ;
V_86 -= V_85 ;
V_147 = V_86 ;
V_83 = 0 ;
F_6 ( V_32 -> V_40 ) -> V_71 . V_148 += V_147 ;
V_11 = V_32 -> V_112 . V_11 ;
V_13 = V_32 -> V_112 . V_21 + ( V_11 >> V_22 ) ;
V_11 &= ~ V_23 ;
if ( V_86 && V_32 -> V_112 . V_20 ) {
V_84 = F_12 ( V_11 +
V_32 -> V_112 . V_20 ) >> V_22 ;
for (; V_83 < V_84 ; V_83 ++ ) {
V_85 = V_27 - V_11 ;
if ( V_85 > V_86 )
V_85 = V_86 ;
F_10 ( L_18
L_19 ,
V_70 , V_83 , V_87 , V_86 , V_85 ) ;
V_88 = F_13 ( V_13 [ V_83 ] ) ;
memcpy ( V_88 + V_11 , V_87 , V_85 ) ;
F_27 ( V_13 [ V_83 ] ) ;
F_14 ( V_88 ) ;
V_87 += V_85 ;
V_86 -= V_85 ;
if ( V_86 == 0 )
break;
V_11 = 0 ;
}
}
if ( V_86 && V_32 -> V_112 . V_29 [ 0 ] . V_15 ) {
V_85 = V_86 ;
if ( V_85 > V_32 -> V_112 . V_29 [ 0 ] . V_15 )
V_85 = V_32 -> V_112 . V_29 [ 0 ] . V_15 ;
if ( V_32 -> V_112 . V_29 [ 0 ] . V_18 != V_87 )
memmove ( V_32 -> V_112 . V_29 [ 0 ] . V_18 , V_87 , V_85 ) ;
F_10 ( L_20 ,
V_70 , V_87 , V_86 , V_85 ) ;
V_32 -> V_112 . V_29 [ 0 ] . V_15 = V_85 ;
V_86 -= V_85 ; ++ V_83 ;
} else
V_32 -> V_112 . V_29 [ 0 ] . V_15 = 0 ;
if ( V_82 ) {
unsigned char * V_10 = V_32 -> V_112 . V_29 [ 0 ] . V_18 ;
while ( V_82 -- )
V_10 [ V_32 -> V_112 . V_29 [ 0 ] . V_15 ++ ] = 0 ;
}
if ( V_86 )
F_10 ( L_21
L_22 ,
V_70 , V_147 , V_83 , V_86 ) ;
V_32 -> V_149 = V_32 -> V_112 ;
}
void
F_28 ( struct V_150 * V_151 )
{
struct V_132 * V_133 =
F_29 ( V_151 , struct V_132 , V_152 . V_151 ) ;
struct V_38 * V_39 =
F_29 ( V_133 , struct V_38 , V_134 ) ;
struct V_94 * V_95 = & V_39 -> V_153 ;
F_30 ( & V_95 -> V_154 ) ;
if ( ++ V_95 -> V_155 == 0 )
++ V_95 -> V_155 ;
if ( V_133 -> V_156 > 0 ) {
if ( ! F_31 ( V_95 ) )
F_32 ( V_95 , 0 ) ;
} else {
if ( F_33 ( V_95 ) )
F_32 ( V_95 , - V_157 ) ;
}
F_34 ( & V_95 -> V_154 ) ;
}
void
F_35 ( struct V_132 * V_133 )
{
F_36 ( & V_133 -> V_152 , 0 ) ;
}
void
F_37 ( struct V_136 * V_137 )
{
struct V_34 * V_35 ;
struct V_36 * V_37 ;
struct V_31 * V_32 ;
struct V_38 * V_39 = V_137 -> V_158 ;
struct V_94 * V_95 = & V_39 -> V_153 ;
T_2 * V_49 ;
int V_159 , V_160 ;
unsigned long V_161 ;
V_26 V_162 ;
if ( V_137 -> V_146 == ~ 0U ) {
F_38 ( V_137 ) ;
if ( V_39 -> V_134 . V_156 == 1 ) {
V_39 -> V_134 . V_156 = - V_28 ;
F_35 ( & V_39 -> V_134 ) ;
}
return;
}
if ( V_137 -> V_146 < V_117 ) {
F_10 ( L_23 , V_70 ) ;
goto V_163;
}
V_35 = F_16 ( V_137 -> V_142 ) ;
if ( V_35 -> V_105 != V_106 ) {
F_10 ( L_24 ,
V_70 , F_23 ( V_35 -> V_105 ) ) ;
goto V_163;
}
F_39 ( & V_95 -> V_154 ) ;
V_32 = F_40 ( V_95 , V_35 -> V_103 ) ;
if ( V_32 == NULL ) {
F_41 ( & V_95 -> V_154 ) ;
F_10 ( L_25
L_26 ,
V_70 , V_137 , F_23 ( V_35 -> V_103 ) ,
V_137 -> V_146 ) ;
V_163:
V_39 -> V_71 . V_164 ++ ;
if ( F_42 ( & V_39 -> V_57 , & V_39 -> V_134 , V_137 ) )
F_38 ( V_137 ) ;
return;
}
V_37 = F_5 ( V_32 ) ;
if ( V_37 -> V_165 ) {
F_41 ( & V_95 -> V_154 ) ;
F_10 ( L_27
L_28 , V_70 , V_137 , V_37 ,
F_23 ( V_35 -> V_103 ) ) ;
goto V_163;
}
F_10 ( L_29
L_30 ,
V_70 , V_137 , V_37 , V_32 ,
F_23 ( V_35 -> V_103 ) ) ;
V_37 -> V_165 = V_137 ;
V_95 -> V_166 = 0 ;
switch ( V_35 -> V_110 ) {
case V_111 :
if ( V_35 -> V_50 . V_51 [ 0 ] != V_54 ||
( V_35 -> V_50 . V_51 [ 1 ] == V_54 &&
V_35 -> V_50 . V_51 [ 2 ] != V_54 ) ||
( V_35 -> V_50 . V_51 [ 1 ] != V_54 &&
V_37 -> V_77 == 0 ) )
goto V_167;
if ( V_35 -> V_50 . V_51 [ 1 ] != V_54 ) {
V_49 = & V_35 -> V_50 . V_51 [ 2 ] ;
V_159 = F_22 ( V_137 ,
V_37 -> V_77 , 1 , & V_49 ) ;
if ( V_159 < 0 || * V_49 ++ != V_54 )
goto V_167;
V_137 -> V_146 -=
( ( unsigned char * ) V_49 - ( unsigned char * ) V_35 ) ;
V_160 = V_137 -> V_146 + V_159 ;
V_39 -> V_71 . V_168 += V_159 ;
if ( V_159 &= 3 ) {
V_159 = 4 - V_159 ;
V_160 += V_159 ;
}
} else {
V_159 = 0 ;
V_49 = ( T_2 * ) ( ( unsigned char * ) V_35 +
V_117 ) ;
V_137 -> V_146 -= V_117 ;
V_160 = V_137 -> V_146 ;
}
F_26 ( V_32 , ( char * ) V_49 , V_137 -> V_146 , V_159 ) ;
break;
case V_169 :
if ( V_35 -> V_50 . V_51 [ 0 ] != V_54 ||
V_35 -> V_50 . V_51 [ 1 ] != V_54 ||
V_35 -> V_50 . V_51 [ 2 ] != V_62 ||
V_37 -> V_77 == 0 )
goto V_167;
V_49 = ( T_2 * ) ( ( unsigned char * ) V_35 +
V_117 ) ;
V_159 = F_22 ( V_137 , V_37 -> V_77 , 0 , & V_49 ) ;
if ( V_159 < 0 )
goto V_167;
V_39 -> V_71 . V_168 += V_159 ;
V_160 = V_159 ;
break;
V_167:
default:
F_10 ( L_31
L_32
L_33 ,
V_70 , F_23 ( V_35 -> V_110 ) ,
V_35 -> V_50 . V_51 [ 0 ] ,
V_35 -> V_50 . V_51 [ 1 ] ,
V_35 -> V_50 . V_51 [ 2 ] ,
V_37 -> V_77 ) ;
V_160 = - V_28 ;
V_39 -> V_71 . V_164 ++ ;
break;
}
V_162 = F_23 ( V_35 -> V_107 ) ;
if ( V_162 == 0 )
V_162 = 1 ;
else if ( V_162 > V_39 -> V_108 . V_109 )
V_162 = V_39 -> V_108 . V_109 ;
V_161 = V_95 -> V_161 ;
V_95 -> V_161 = V_162 << V_170 ;
if ( V_95 -> V_161 > V_161 )
F_43 ( V_32 -> V_171 ) ;
F_10 ( L_34 ,
V_70 , V_95 , V_32 , V_160 ) ;
F_44 ( V_32 -> V_171 , V_160 ) ;
F_41 ( & V_95 -> V_154 ) ;
}
