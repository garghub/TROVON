long F_1 ( void )
{
return ( 60 * 60 * 2 ) ;
}
int F_2 ( T_1 * V_1 )
{
if ( ! F_3 ( V_1 ) )
return ( 0 ) ;
V_1 -> V_2 -> V_3 ( V_1 ) ;
return ( 1 ) ;
}
void F_4 ( T_1 * V_1 )
{
F_5 ( V_1 -> V_4 ) ;
F_6 ( V_1 ) ;
}
void F_7 ( T_1 * V_1 )
{
F_8 ( V_1 ) ;
if ( V_1 -> V_2 -> V_5 == V_6 )
V_1 -> V_5 = V_7 ;
else
V_1 -> V_5 = V_1 -> V_2 -> V_5 ;
}
int F_9 ( int V_8 , unsigned int * V_9 )
{
const T_2 * V_10 ;
if ( ( V_8 < 1 ) || ( ( unsigned int ) V_8 > F_10 ( V_11 ) ) )
return 0 ;
V_10 = V_11 + V_8 - 1 ;
if ( V_9 )
* V_9 = V_10 -> V_12 ;
return V_10 -> V_13 ;
}
int F_11 ( int V_13 )
{
T_3 V_14 ;
for ( V_14 = 0 ; V_14 < F_10 ( V_11 ) ; V_14 ++ ) {
if ( V_11 [ V_14 ] . V_13 == V_13 )
return V_14 + 1 ;
}
return 0 ;
}
static int F_12 ( T_1 * V_1 , int V_15 ,
const unsigned char * * V_16 , T_3 * V_17 )
{
T_3 V_18 = 0 ;
if ( V_15 ) {
* V_16 = V_1 -> V_19 -> V_20 ;
V_18 = V_1 -> V_19 -> V_21 ;
} else {
switch ( F_13 ( V_1 ) ) {
case V_22 :
* V_16 = V_23 ;
V_18 = sizeof( V_23 ) ;
break;
case V_24 :
* V_16 = V_23 ;
V_18 = 2 ;
break;
case V_25 :
* V_16 = V_23 + 2 ;
V_18 = 2 ;
break;
default:
* V_16 = V_1 -> V_20 ;
V_18 = V_1 -> V_21 ;
}
if ( ! * V_16 ) {
* V_16 = V_26 ;
V_18 = sizeof( V_26 ) ;
}
}
if ( V_18 & 1 ) {
F_14 ( V_27 , V_28 ) ;
* V_17 = 0 ;
return 0 ;
} else {
* V_17 = V_18 / 2 ;
return 1 ;
}
}
static int F_15 ( T_1 * V_1 , const unsigned char * V_29 , int V_30 )
{
const T_2 * V_10 ;
if ( V_29 [ 0 ] )
return 1 ;
if ( ( V_29 [ 1 ] < 1 ) || ( ( T_3 ) V_29 [ 1 ] > F_10 ( V_11 ) ) )
return 0 ;
V_10 = & V_11 [ V_29 [ 1 ] - 1 ] ;
# ifdef F_16
if ( V_10 -> V_12 & V_31 )
return 0 ;
# endif
return F_17 ( V_1 , V_30 , V_10 -> V_32 , V_10 -> V_13 , ( void * ) V_29 ) ;
}
int F_18 ( T_1 * V_1 , const unsigned char * V_33 , T_3 V_34 )
{
const unsigned char * V_35 ;
T_3 V_17 , V_14 ;
unsigned int V_36 = F_13 ( V_1 ) ;
if ( V_34 != 3 || V_33 [ 0 ] != V_37 )
return 0 ;
if ( V_36 ) {
unsigned long V_38 = V_1 -> V_39 -> V_40 . V_41 -> V_42 ;
if ( V_33 [ 1 ] )
return 0 ;
if ( V_38 == V_43 ) {
if ( V_33 [ 2 ] != V_44 )
return 0 ;
} else if ( V_38 == V_45 ) {
if ( V_33 [ 2 ] != V_46 )
return 0 ;
} else
return 0 ;
}
if ( ! F_12 ( V_1 , 0 , & V_35 , & V_17 ) )
return 0 ;
for ( V_14 = 0 ; V_14 < V_17 ; V_14 ++ , V_35 += 2 ) {
if ( V_33 [ 1 ] == V_35 [ 0 ] && V_33 [ 2 ] == V_35 [ 1 ] )
return F_15 ( V_1 , V_33 + 1 , V_47 ) ;
}
return 0 ;
}
int F_19 ( T_1 * V_1 , int V_48 )
{
const unsigned char * V_49 , * V_50 ;
T_3 V_51 , V_52 , V_14 , V_53 ;
int V_54 ;
if ( V_1 -> V_55 == 0 )
return - 1 ;
if ( V_48 == - 2 ) {
if ( F_13 ( V_1 ) ) {
unsigned long V_38 = V_1 -> V_39 -> V_40 . V_41 -> V_42 ;
if ( V_38 == V_43 )
return V_56 ;
if ( V_38 == V_45 )
return V_57 ;
return V_58 ;
}
V_48 = 0 ;
}
if ( ! F_12
( V_1 , ( V_1 -> V_59 & V_60 ) != 0 , & V_50 ,
& V_52 ) )
return V_48 == - 1 ? 0 : V_58 ;
if ( ! F_12
( V_1 , ! ( V_1 -> V_59 & V_60 ) , & V_49 , & V_51 ) )
return V_48 == - 1 ? 0 : V_58 ;
if ( V_52 == 0 && ( V_1 -> V_59 & V_60 ) != 0 ) {
V_50 = V_61 ;
V_52 = sizeof( V_61 ) / 2 ;
} else if ( V_51 == 0 &&
( V_1 -> V_59 & V_60 ) == 0 ) {
V_49 = V_61 ;
V_51 = sizeof( V_61 ) / 2 ;
}
V_54 = 0 ;
for ( V_14 = 0 ; V_14 < V_51 ; V_14 ++ , V_49 += 2 ) {
const unsigned char * V_62 = V_50 ;
for ( V_53 = 0 ; V_53 < V_52 ; V_53 ++ , V_62 += 2 ) {
if ( V_49 [ 0 ] == V_62 [ 0 ] && V_49 [ 1 ] == V_62 [ 1 ] ) {
if ( ! F_15 ( V_1 , V_49 , V_63 ) )
continue;
if ( V_48 == V_54 ) {
int V_42 = ( V_49 [ 0 ] << 8 ) | V_49 [ 1 ] ;
return F_9 ( V_42 , NULL ) ;
}
V_54 ++ ;
}
}
}
if ( V_48 == - 1 )
return V_54 ;
return V_58 ;
}
int F_20 ( unsigned char * * V_64 , T_3 * V_65 ,
int * V_35 , T_3 V_66 )
{
unsigned char * V_67 , * V_33 ;
T_3 V_14 ;
unsigned long V_68 = 0 ;
V_67 = F_21 ( V_66 * 2 ) ;
if ( V_67 == NULL )
return 0 ;
for ( V_14 = 0 , V_33 = V_67 ; V_14 < V_66 ; V_14 ++ ) {
unsigned long V_69 ;
int V_42 ;
V_42 = F_11 ( V_35 [ V_14 ] ) ;
V_69 = 1L << V_42 ;
if ( ! V_42 || ( V_68 & V_69 ) ) {
F_5 ( V_67 ) ;
return 0 ;
}
V_68 |= V_69 ;
F_22 ( V_42 , V_33 ) ;
}
F_5 ( * V_64 ) ;
* V_64 = V_67 ;
* V_65 = V_66 * 2 ;
return 1 ;
}
static int F_23 ( const char * V_70 , int V_34 , void * V_71 )
{
T_4 * V_72 = V_71 ;
T_3 V_14 ;
int V_13 ;
char V_73 [ 20 ] ;
if ( V_70 == NULL )
return 0 ;
if ( V_72 -> V_74 == V_75 )
return 0 ;
if ( V_34 > ( int ) ( sizeof( V_73 ) - 1 ) )
return 0 ;
memcpy ( V_73 , V_70 , V_34 ) ;
V_73 [ V_34 ] = 0 ;
V_13 = F_24 ( V_73 ) ;
if ( V_13 == V_58 )
V_13 = F_25 ( V_73 ) ;
if ( V_13 == V_58 )
V_13 = F_26 ( V_73 ) ;
if ( V_13 == V_58 )
return 0 ;
for ( V_14 = 0 ; V_14 < V_72 -> V_74 ; V_14 ++ )
if ( V_72 -> V_76 [ V_14 ] == V_13 )
return 0 ;
V_72 -> V_76 [ V_72 -> V_74 ++ ] = V_13 ;
return 1 ;
}
int F_27 ( unsigned char * * V_64 , T_3 * V_65 , const char * V_77 )
{
T_4 V_78 ;
V_78 . V_74 = 0 ;
if ( ! F_28 ( V_77 , ':' , 1 , F_23 , & V_78 ) )
return 0 ;
if ( V_64 == NULL )
return 1 ;
return F_20 ( V_64 , V_65 , V_78 . V_76 , V_78 . V_74 ) ;
}
static int F_29 ( unsigned char * V_8 , unsigned char * V_79 ,
T_5 * V_80 )
{
int V_42 ;
const T_6 * V_81 ;
if ( ! V_80 )
return 0 ;
V_81 = F_30 ( V_80 ) ;
if ( ! V_81 )
return 0 ;
V_42 = F_31 ( V_81 ) ;
V_42 = F_11 ( V_42 ) ;
if ( V_42 == 0 )
return 0 ;
V_8 [ 0 ] = 0 ;
V_8 [ 1 ] = ( unsigned char ) V_42 ;
if ( V_79 ) {
if ( F_32 ( V_80 ) == NULL )
return 0 ;
if ( F_33 ( V_80 ) == V_82 ) {
* V_79 = V_83 ;
} else {
if ( ( V_11 [ V_42 - 1 ] . V_12 & V_84 ) == V_85 )
* V_79 = V_86 ;
else
* V_79 = V_87 ;
}
}
return 1 ;
}
static int F_34 ( T_1 * V_1 ,
unsigned char * V_8 , unsigned char * V_79 )
{
const unsigned char * V_88 , * V_16 ;
T_3 V_89 , V_17 , V_14 ;
int V_53 ;
if ( V_79 && V_1 -> V_19 -> V_90 ) {
V_88 = V_1 -> V_19 -> V_90 ;
V_89 = V_1 -> V_19 -> V_91 ;
for ( V_14 = 0 ; V_14 < V_89 ; V_14 ++ , V_88 ++ ) {
if ( * V_79 == * V_88 )
break;
}
if ( V_14 == V_89 )
return 0 ;
}
if ( ! V_8 )
return 1 ;
for ( V_53 = 0 ; V_53 <= 1 ; V_53 ++ ) {
if ( ! F_12 ( V_1 , V_53 , & V_16 , & V_17 ) )
return 0 ;
if ( V_53 == 1 && V_17 == 0 ) {
break;
}
for ( V_14 = 0 ; V_14 < V_17 ; V_14 ++ , V_16 += 2 ) {
if ( V_16 [ 0 ] == V_8 [ 0 ] && V_16 [ 1 ] == V_8 [ 1 ] )
break;
}
if ( V_14 == V_17 )
return 0 ;
if ( ! V_1 -> V_55 )
break;
}
return 1 ;
}
static void F_35 ( T_1 * V_1 , const unsigned char * * V_88 ,
T_3 * V_89 )
{
if ( V_1 -> V_90 ) {
* V_88 = V_1 -> V_90 ;
* V_89 = V_1 -> V_91 ;
} else {
* V_88 = V_92 ;
if ( F_13 ( V_1 ) )
* V_89 = sizeof( V_92 ) - 1 ;
else
* V_89 = sizeof( V_92 ) ;
}
}
static int F_36 ( T_1 * V_1 , T_7 * V_93 , int V_94 )
{
unsigned char V_79 , V_8 [ 2 ] ;
T_8 * V_95 ;
int V_96 ;
V_95 = F_37 ( V_93 ) ;
if ( ! V_95 )
return 0 ;
if ( F_38 ( V_95 ) != V_97 )
return 1 ;
V_96 = F_29 ( V_8 , & V_79 , F_39 ( V_95 ) ) ;
if ( ! V_96 )
return 0 ;
V_96 = F_34 ( V_1 , V_1 -> V_55 ? V_8 : NULL , & V_79 ) ;
if ( ! V_96 )
return 0 ;
if ( V_94 && F_13 ( V_1 ) ) {
int V_98 ;
T_3 V_14 ;
T_9 * V_99 = V_1 -> V_100 ;
if ( V_8 [ 0 ] )
return 0 ;
if ( V_8 [ 1 ] == V_44 )
V_98 = V_101 ;
else if ( V_8 [ 1 ] == V_46 )
V_98 = V_102 ;
else
return 0 ;
for ( V_14 = 0 ; V_14 < V_99 -> V_103 ; V_14 ++ )
if ( V_98 == V_99 -> V_104 [ V_14 ] . V_105 )
break;
if ( V_14 == V_99 -> V_103 )
return 0 ;
if ( V_94 == 2 ) {
if ( V_98 == V_101 )
V_1 -> V_39 -> V_40 . V_106 [ V_107 ] = F_40 () ;
else
V_1 -> V_39 -> V_40 . V_106 [ V_107 ] = F_41 () ;
}
}
return V_96 ;
}
int F_42 ( T_1 * V_1 , unsigned long V_38 )
{
if ( F_13 ( V_1 ) ) {
unsigned char V_8 [ 2 ] ;
if ( V_38 == V_43 )
V_8 [ 1 ] = V_44 ;
else if ( V_38 == V_45 )
V_8 [ 1 ] = V_46 ;
else
return 0 ;
V_8 [ 0 ] = 0 ;
if ( ! F_34 ( V_1 , V_8 , NULL ) )
return 0 ;
return 1 ;
}
if ( F_19 ( V_1 , 0 ) )
return 1 ;
return 0 ;
}
static int F_36 ( T_1 * V_1 , T_7 * V_93 , int V_94 )
{
return 1 ;
}
T_3 F_43 ( T_1 * V_1 , const unsigned char * * V_108 )
{
#ifndef F_44
switch ( F_13 ( V_1 ) ) {
case V_22 :
* V_108 = V_109 ;
return sizeof( V_109 ) ;
case V_24 :
* V_108 = V_109 ;
return 2 ;
case V_25 :
* V_108 = V_109 + 2 ;
return 2 ;
}
#endif
if ( V_1 -> V_55 && V_1 -> V_100 -> V_110 ) {
* V_108 = V_1 -> V_100 -> V_110 ;
return V_1 -> V_100 -> V_111 ;
} else if ( V_1 -> V_100 -> V_112 ) {
* V_108 = V_1 -> V_100 -> V_112 ;
return V_1 -> V_100 -> V_113 ;
} else {
* V_108 = V_114 ;
return sizeof( V_114 ) ;
}
}
int F_45 ( const T_10 * * V_115 , T_1 * V_1 ,
const unsigned char * V_116 , T_8 * V_95 )
{
const unsigned char * V_117 ;
T_3 V_118 , V_14 ;
int V_119 = F_46 ( V_95 ) ;
if ( V_119 == - 1 )
return - 1 ;
if ( V_119 != ( int ) V_116 [ 1 ] ) {
F_14 ( V_120 , V_121 ) ;
return 0 ;
}
#ifndef F_44
if ( F_38 ( V_95 ) == V_97 ) {
unsigned char V_8 [ 2 ] , V_79 ;
if ( ! F_29 ( V_8 , & V_79 , F_39 ( V_95 ) ) )
return 0 ;
if ( ! V_1 -> V_55 && ! F_34 ( V_1 , V_8 , & V_79 ) ) {
F_14 ( V_120 , V_122 ) ;
return 0 ;
}
if ( F_13 ( V_1 ) ) {
if ( V_8 [ 0 ] )
return 0 ;
if ( V_8 [ 1 ] == V_44 ) {
if ( V_116 [ 0 ] != V_123 ) {
F_14 ( V_120 ,
V_124 ) ;
return 0 ;
}
} else if ( V_8 [ 1 ] == V_46 ) {
if ( V_116 [ 0 ] != V_125 ) {
F_14 ( V_120 ,
V_124 ) ;
return 0 ;
}
} else
return 0 ;
}
} else if ( F_13 ( V_1 ) )
return 0 ;
#endif
V_118 = F_43 ( V_1 , & V_117 ) ;
for ( V_14 = 0 ; V_14 < V_118 ; V_14 += 2 , V_117 += 2 ) {
if ( V_116 [ 0 ] == V_117 [ 0 ] && V_116 [ 1 ] == V_117 [ 1 ] )
break;
}
if ( V_14 == V_118
&& ( V_116 [ 0 ] != V_126
|| V_1 -> V_100 -> V_127 & V_128 ) ) {
F_14 ( V_120 , V_121 ) ;
return 0 ;
}
* V_115 = F_47 ( V_116 [ 0 ] ) ;
if ( * V_115 == NULL ) {
F_14 ( V_120 , V_129 ) ;
return 0 ;
}
if ( ! F_17 ( V_1 , V_130 ,
F_48 ( * V_115 ) * 4 , F_49 ( * V_115 ) , ( void * ) V_116 ) ) {
F_14 ( V_120 , V_121 ) ;
return 0 ;
}
V_1 -> V_39 -> V_40 . V_131 = * V_115 ;
return 1 ;
}
void F_50 ( T_1 * V_1 )
{
V_1 -> V_39 -> V_40 . V_132 = 0 ;
V_1 -> V_39 -> V_40 . V_133 = 0 ;
F_51 ( & V_1 -> V_39 -> V_40 . V_132 , V_1 , V_134 ) ;
F_52 ( V_1 , & V_1 -> V_39 -> V_40 . V_135 , & V_1 -> V_39 -> V_40 . V_136 ) ;
#ifndef F_53
if ( ! V_1 -> V_137 ) {
V_1 -> V_39 -> V_40 . V_132 |= V_138 ;
V_1 -> V_39 -> V_40 . V_133 |= V_139 ;
}
#endif
#ifndef F_54
if ( ! ( V_1 -> V_140 . V_141 & V_142 ) ) {
V_1 -> V_39 -> V_40 . V_132 |= V_143 ;
V_1 -> V_39 -> V_40 . V_133 |= V_142 ;
}
#endif
}
int F_55 ( T_1 * V_1 , const T_11 * V_99 , int V_30 )
{
if ( V_99 -> V_144 & V_1 -> V_39 -> V_40 . V_133
|| V_99 -> V_145 & V_1 -> V_39 -> V_40 . V_132 )
return 1 ;
if ( V_1 -> V_39 -> V_40 . V_136 == 0 )
return 1 ;
if ( ! F_56 ( V_1 ) && ( ( V_99 -> V_146 > V_1 -> V_39 -> V_40 . V_136 )
|| ( V_99 -> V_147 < V_1 -> V_39 -> V_40 . V_135 ) ) )
return 1 ;
if ( F_56 ( V_1 ) && ( F_57 ( V_99 -> V_148 , V_1 -> V_39 -> V_40 . V_136 )
|| F_58 ( V_99 -> V_149 , V_1 -> V_39 -> V_40 . V_135 ) ) )
return 1 ;
return ! F_17 ( V_1 , V_30 , V_99 -> V_150 , 0 , ( void * ) V_99 ) ;
}
static int F_59 ( T_1 * V_1 )
{
if ( V_1 -> V_59 & V_151 )
return 0 ;
return F_17 ( V_1 , V_152 , 0 , 0 , NULL ) ;
}
static int F_60 ( const void * V_153 , const void * V_154 )
{
unsigned int V_155 = * ( ( const unsigned int * ) V_153 ) ;
unsigned int V_156 = * ( ( const unsigned int * ) V_154 ) ;
if ( V_155 < V_156 )
return - 1 ;
else if ( V_155 > V_156 )
return 1 ;
else
return 0 ;
}
static int F_61 ( const T_12 * V_157 )
{
T_12 V_158 = * V_157 ;
T_3 V_159 = 0 , V_14 = 0 ;
unsigned int * V_160 = NULL ;
int V_161 = 0 ;
while ( F_62 ( & V_158 ) > 0 ) {
unsigned int type ;
T_12 V_162 ;
if ( ! F_63 ( & V_158 , & type ) ||
! F_64 ( & V_158 , & V_162 ) ) {
goto V_163;
}
V_159 ++ ;
}
if ( V_159 <= 1 )
return 1 ;
V_160 = F_21 ( sizeof( unsigned int ) * V_159 ) ;
if ( V_160 == NULL ) {
F_14 ( V_164 , V_165 ) ;
goto V_163;
}
V_158 = * V_157 ;
for ( V_14 = 0 ; V_14 < V_159 ; V_14 ++ ) {
T_12 V_162 ;
if ( ! F_63 ( & V_158 , & V_160 [ V_14 ] ) ||
! F_64 ( & V_158 , & V_162 ) ) {
F_14 ( V_164 , V_28 ) ;
goto V_163;
}
}
if ( F_62 ( & V_158 ) != 0 ) {
F_14 ( V_164 , V_28 ) ;
goto V_163;
}
qsort ( V_160 , V_159 , sizeof( unsigned int ) , F_60 ) ;
for ( V_14 = 1 ; V_14 < V_159 ; V_14 ++ ) {
if ( V_160 [ V_14 - 1 ] == V_160 [ V_14 ] )
goto V_163;
}
V_161 = 1 ;
V_163:
F_5 ( V_160 ) ;
return V_161 ;
}
unsigned char * F_65 ( T_1 * V_1 , unsigned char * V_166 ,
unsigned char * V_167 , int * V_168 )
{
int V_169 = 0 ;
unsigned char * V_170 = V_166 ;
unsigned char * V_161 = V_166 ;
#ifndef F_44
int V_171 = 0 ;
if ( V_1 -> V_5 >= V_172 || F_56 ( V_1 ) ) {
int V_14 ;
unsigned long V_173 , V_174 ;
F_66 ( T_11 ) * V_175 = F_67 ( V_1 ) ;
for ( V_14 = 0 ; V_14 < F_68 ( V_175 ) ; V_14 ++ ) {
const T_11 * V_99 = F_69 ( V_175 , V_14 ) ;
V_173 = V_99 -> V_144 ;
V_174 = V_99 -> V_145 ;
if ( ( V_173 & ( V_176 | V_177 ) )
|| ( V_174 & V_178 ) ) {
V_171 = 1 ;
break;
}
}
}
#endif
V_161 += 2 ;
if ( V_161 >= V_167 )
return NULL ;
if ( V_1 -> V_179 ) {
int V_180 ;
if ( ! F_70 ( V_1 , 0 , & V_180 , 0 ) ) {
F_14 ( V_181 , V_28 ) ;
return NULL ;
}
if ( ( V_167 - V_161 - 4 - V_180 ) < 0 )
return NULL ;
F_22 ( V_182 , V_161 ) ;
F_22 ( V_180 , V_161 ) ;
if ( ! F_70 ( V_1 , V_161 , & V_180 , V_180 ) ) {
F_14 ( V_181 , V_28 ) ;
return NULL ;
}
V_161 += V_180 ;
}
if ( V_1 -> V_183 == V_184 )
goto V_163;
if ( V_1 -> V_185 != NULL ) {
unsigned long V_186 ;
long V_187 ;
if ( ( V_187 = V_167 - V_161 - 9 ) < 0
|| ( V_186 = strlen ( V_1 -> V_185 ) ) > ( unsigned long ) V_187 )
return NULL ;
F_22 ( V_188 , V_161 ) ;
F_22 ( V_186 + 5 , V_161 ) ;
F_22 ( V_186 + 3 , V_161 ) ;
* ( V_161 ++ ) = ( unsigned char ) V_189 ;
F_22 ( V_186 , V_161 ) ;
memcpy ( V_161 , V_1 -> V_185 , V_186 ) ;
V_161 += V_186 ;
}
#ifndef F_54
if ( V_1 -> V_140 . V_190 != NULL ) {
int V_191 = strlen ( V_1 -> V_140 . V_190 ) ;
if ( V_191 > 255 || V_191 == 0 ) {
F_14 ( V_181 , V_28 ) ;
return NULL ;
}
if ( ( V_167 - V_161 - 5 - V_191 ) < 0 )
return NULL ;
F_22 ( V_192 , V_161 ) ;
F_22 ( V_191 + 1 , V_161 ) ;
( * V_161 ++ ) = ( unsigned char ) V_191 ;
memcpy ( V_161 , V_1 -> V_140 . V_190 , V_191 ) ;
V_161 += V_191 ;
}
#endif
#ifndef F_44
if ( V_171 ) {
long V_187 ;
const unsigned char * V_16 , * V_88 ;
T_3 V_17 , V_89 , V_193 ;
T_3 V_14 ;
unsigned char * V_73 ;
F_35 ( V_1 , & V_88 , & V_89 ) ;
if ( ( V_187 = V_167 - V_161 - 5 ) < 0 )
return NULL ;
if ( V_89 > ( T_3 ) V_187 )
return NULL ;
if ( V_89 > 255 ) {
F_14 ( V_181 , V_28 ) ;
return NULL ;
}
F_22 ( V_194 , V_161 ) ;
F_22 ( V_89 + 1 , V_161 ) ;
* ( V_161 ++ ) = ( unsigned char ) V_89 ;
memcpy ( V_161 , V_88 , V_89 ) ;
V_161 += V_89 ;
V_16 = V_1 -> V_20 ;
if ( ! F_12 ( V_1 , 0 , & V_16 , & V_17 ) )
return NULL ;
if ( ( V_187 = V_167 - V_161 - 6 ) < 0 )
return NULL ;
if ( V_17 > ( T_3 ) V_187 / 2 )
return NULL ;
if ( V_17 > 65532 / 2 ) {
F_14 ( V_181 , V_28 ) ;
return NULL ;
}
F_22 ( V_195 , V_161 ) ;
V_73 = V_161 + 4 ;
for ( V_14 = 0 ; V_14 < V_17 ; V_14 ++ , V_16 += 2 ) {
if ( F_15 ( V_1 , V_16 , V_196 ) ) {
* V_73 ++ = V_16 [ 0 ] ;
* V_73 ++ = V_16 [ 1 ] ;
}
}
V_193 = V_73 - V_161 - 4 ;
F_22 ( V_193 + 2 , V_161 ) ;
F_22 ( V_193 , V_161 ) ;
V_161 += V_193 ;
}
#endif
if ( F_59 ( V_1 ) ) {
int V_197 ;
if ( ! V_1 -> V_198 && V_1 -> V_19 && V_1 -> V_19 -> V_199 )
V_197 = V_1 -> V_19 -> V_200 ;
else if ( V_1 -> V_19 && V_1 -> V_4 &&
V_1 -> V_4 -> V_201 ) {
V_197 = V_1 -> V_4 -> V_202 ;
V_1 -> V_19 -> V_199 = F_21 ( V_197 ) ;
if ( V_1 -> V_19 -> V_199 == NULL )
return NULL ;
memcpy ( V_1 -> V_19 -> V_199 ,
V_1 -> V_4 -> V_201 , V_197 ) ;
V_1 -> V_19 -> V_200 = V_197 ;
} else
V_197 = 0 ;
if ( V_197 == 0 && V_1 -> V_4 &&
V_1 -> V_4 -> V_201 == NULL )
goto V_203;
if ( ( long ) ( V_167 - V_161 - 4 - V_197 ) < 0 )
return NULL ;
F_22 ( V_204 , V_161 ) ;
F_22 ( V_197 , V_161 ) ;
if ( V_197 ) {
memcpy ( V_161 , V_1 -> V_19 -> V_199 , V_197 ) ;
V_161 += V_197 ;
}
}
V_203:
if ( F_71 ( V_1 ) ) {
T_3 V_205 ;
const unsigned char * V_206 ;
unsigned char * V_73 ;
V_205 = F_43 ( V_1 , & V_206 ) ;
if ( ( T_3 ) ( V_167 - V_161 ) < V_205 + 6 )
return NULL ;
F_22 ( V_207 , V_161 ) ;
V_73 = V_161 ;
V_161 += 4 ;
V_205 = F_72 ( V_1 , V_161 , V_206 , V_205 ) ;
F_22 ( V_205 + 2 , V_73 ) ;
F_22 ( V_205 , V_73 ) ;
V_161 += V_205 ;
}
#ifndef F_73
if ( V_1 -> V_208 == V_209 ) {
int V_14 ;
long V_210 , V_211 , V_212 ;
T_13 * V_42 ;
V_211 = 0 ;
for ( V_14 = 0 ; V_14 < F_74 ( V_1 -> V_213 ) ; V_14 ++ ) {
V_42 = F_75 ( V_1 -> V_213 , V_14 ) ;
V_212 = F_76 ( V_42 , NULL ) ;
if ( V_212 <= 0 )
return NULL ;
V_211 += V_212 + 2 ;
}
if ( V_1 -> V_214 ) {
V_210 = F_77 ( V_1 -> V_214 , NULL ) ;
if ( V_210 < 0 )
return NULL ;
} else
V_210 = 0 ;
if ( ( long ) ( V_167 - V_161 - 7 - V_210 - V_211 ) < 0 )
return NULL ;
F_22 ( V_215 , V_161 ) ;
if ( V_210 + V_211 > 0xFFF0 )
return NULL ;
F_22 ( V_210 + V_211 + 5 , V_161 ) ;
* ( V_161 ++ ) = V_209 ;
F_22 ( V_211 , V_161 ) ;
for ( V_14 = 0 ; V_14 < F_74 ( V_1 -> V_213 ) ; V_14 ++ ) {
unsigned char * V_216 = V_161 ;
V_42 = F_75 ( V_1 -> V_213 , V_14 ) ;
V_161 += 2 ;
V_212 = F_76 ( V_42 , & V_161 ) ;
F_22 ( V_212 , V_216 ) ;
}
F_22 ( V_210 , V_161 ) ;
if ( V_210 > 0 )
F_77 ( V_1 -> V_214 , & V_161 ) ;
}
#endif
#ifndef F_78
if ( F_56 ( V_1 ) ) {
if ( ( V_167 - V_161 - 4 - 1 ) < 0 )
return NULL ;
F_22 ( V_217 , V_161 ) ;
F_22 ( 1 , V_161 ) ;
if ( V_1 -> V_218 & V_219 )
* ( V_161 ++ ) = V_220 ;
else
* ( V_161 ++ ) = V_221 ;
}
#endif
#ifndef F_79
if ( V_1 -> V_222 -> V_223 && ! V_1 -> V_39 -> V_40 . V_224 ) {
if ( V_167 - V_161 - 4 < 0 )
return NULL ;
F_22 ( V_225 , V_161 ) ;
F_22 ( 0 , V_161 ) ;
}
#endif
if ( V_1 -> V_226 && ! V_1 -> V_39 -> V_40 . V_224 ) {
if ( ( T_3 ) ( V_167 - V_161 ) < 6 + V_1 -> V_227 )
return NULL ;
F_22 ( V_228 , V_161 ) ;
F_22 ( 2 + V_1 -> V_227 , V_161 ) ;
F_22 ( V_1 -> V_227 , V_161 ) ;
memcpy ( V_161 , V_1 -> V_226 , V_1 -> V_227 ) ;
V_161 += V_1 -> V_227 ;
V_1 -> V_39 -> V_229 = 1 ;
}
#ifndef F_80
if ( F_56 ( V_1 ) && F_81 ( V_1 ) ) {
int V_180 ;
if ( F_82 ( V_1 , 0 , & V_180 , 0 ) ) {
F_14 ( V_181 , V_28 ) ;
return NULL ;
}
if ( ( V_167 - V_161 - 4 - V_180 ) < 0 )
return NULL ;
F_22 ( V_230 , V_161 ) ;
F_22 ( V_180 , V_161 ) ;
if ( F_82 ( V_1 , V_161 , & V_180 , V_180 ) ) {
F_14 ( V_181 , V_28 ) ;
return NULL ;
}
V_161 += V_180 ;
}
#endif
F_83 ( & V_1 -> V_100 -> V_231 ) ;
if ( ! F_84 ( V_1 , 0 , & V_161 , V_167 , V_168 ) )
return NULL ;
F_22 ( V_232 , V_161 ) ;
F_22 ( 0 , V_161 ) ;
#ifndef F_85
if ( V_1 -> V_233 != NULL ) {
F_22 ( V_234 , V_161 ) ;
F_22 ( 0 , V_161 ) ;
}
#endif
F_22 ( V_235 , V_161 ) ;
F_22 ( 0 , V_161 ) ;
if ( V_1 -> V_59 & V_236 ) {
int V_237 = V_161 - ( unsigned char * ) V_1 -> V_238 -> V_201 ;
if ( V_237 > 0xff && V_237 < 0x200 ) {
V_237 = 0x200 - V_237 ;
if ( V_237 >= 4 )
V_237 -= 4 ;
else
V_237 = 0 ;
F_22 ( V_239 , V_161 ) ;
F_22 ( V_237 , V_161 ) ;
memset ( V_161 , 0 , V_237 ) ;
V_161 += V_237 ;
}
}
V_163:
if ( ( V_169 = V_161 - V_170 - 2 ) == 0 )
return V_170 ;
F_22 ( V_169 , V_170 ) ;
return V_161 ;
}
unsigned char * F_86 ( T_1 * V_1 , unsigned char * V_166 ,
unsigned char * V_167 , int * V_168 )
{
int V_169 = 0 ;
unsigned char * V_170 = V_166 ;
unsigned char * V_161 = V_166 ;
#ifndef F_79
int V_240 ;
#endif
#ifndef F_44
unsigned long V_173 = V_1 -> V_39 -> V_40 . V_41 -> V_144 ;
unsigned long V_174 = V_1 -> V_39 -> V_40 . V_41 -> V_145 ;
int V_171 = ( V_173 & V_176 ) || ( V_174 & V_178 ) ;
V_171 = V_171 && ( V_1 -> V_19 -> V_90 != NULL ) ;
#endif
V_161 += 2 ;
if ( V_161 >= V_167 )
return NULL ;
if ( V_1 -> V_39 -> V_241 ) {
int V_180 ;
if ( ! F_87 ( V_1 , 0 , & V_180 , 0 ) ) {
F_14 ( V_242 , V_28 ) ;
return NULL ;
}
if ( ( V_167 - V_161 - 4 - V_180 ) < 0 )
return NULL ;
F_22 ( V_182 , V_161 ) ;
F_22 ( V_180 , V_161 ) ;
if ( ! F_87 ( V_1 , V_161 , & V_180 , V_180 ) ) {
F_14 ( V_242 , V_28 ) ;
return NULL ;
}
V_161 += V_180 ;
}
if ( V_1 -> V_5 == V_184 )
goto V_163;
if ( ! V_1 -> V_243 && V_1 -> V_244 == 1
&& V_1 -> V_19 -> V_185 != NULL ) {
if ( ( long ) ( V_167 - V_161 - 4 ) < 0 )
return NULL ;
F_22 ( V_188 , V_161 ) ;
F_22 ( 0 , V_161 ) ;
}
#ifndef F_44
if ( V_171 ) {
const unsigned char * V_245 ;
T_3 V_246 ;
long V_187 ;
F_35 ( V_1 , & V_245 , & V_246 ) ;
if ( ( V_187 = V_167 - V_161 - 5 ) < 0 )
return NULL ;
if ( V_246 > ( T_3 ) V_187 )
return NULL ;
if ( V_246 > 255 ) {
F_14 ( V_242 , V_28 ) ;
return NULL ;
}
F_22 ( V_194 , V_161 ) ;
F_22 ( V_246 + 1 , V_161 ) ;
* ( V_161 ++ ) = ( unsigned char ) V_246 ;
memcpy ( V_161 , V_245 , V_246 ) ;
V_161 += V_246 ;
}
#endif
if ( V_1 -> V_247 && F_59 ( V_1 ) ) {
if ( ( long ) ( V_167 - V_161 - 4 ) < 0 )
return NULL ;
F_22 ( V_204 , V_161 ) ;
F_22 ( 0 , V_161 ) ;
} else {
V_1 -> V_247 = 0 ;
}
if ( V_1 -> V_248 ) {
if ( ( long ) ( V_167 - V_161 - 4 ) < 0 )
return NULL ;
F_22 ( V_215 , V_161 ) ;
F_22 ( 0 , V_161 ) ;
}
#ifndef F_80
if ( F_56 ( V_1 ) && V_1 -> V_249 ) {
int V_180 ;
if ( F_88 ( V_1 , 0 , & V_180 , 0 ) ) {
F_14 ( V_242 , V_28 ) ;
return NULL ;
}
if ( ( V_167 - V_161 - 4 - V_180 ) < 0 )
return NULL ;
F_22 ( V_230 , V_161 ) ;
F_22 ( V_180 , V_161 ) ;
if ( F_88 ( V_1 , V_161 , & V_180 , V_180 ) ) {
F_14 ( V_242 , V_28 ) ;
return NULL ;
}
V_161 += V_180 ;
}
#endif
if ( ( ( V_1 -> V_39 -> V_40 . V_41 -> V_42 & 0xFFFF ) == 0x80
|| ( V_1 -> V_39 -> V_40 . V_41 -> V_42 & 0xFFFF ) == 0x81 )
&& ( F_89 ( V_1 ) & V_250 ) ) {
const unsigned char V_251 [ 36 ] = {
0xfd , 0xe8 ,
0x00 , 0x20 ,
0x30 , 0x1e , 0x30 , 0x08 , 0x06 , 0x06 , 0x2a , 0x85 ,
0x03 , 0x02 , 0x02 , 0x09 , 0x30 , 0x08 , 0x06 , 0x06 ,
0x2a , 0x85 , 0x03 , 0x02 , 0x02 , 0x16 , 0x30 , 0x08 ,
0x06 , 0x06 , 0x2a , 0x85 , 0x03 , 0x02 , 0x02 , 0x17
} ;
if ( V_167 - V_161 < 36 )
return NULL ;
memcpy ( V_161 , V_251 , 36 ) ;
V_161 += 36 ;
}
#ifndef F_78
if ( F_56 ( V_1 ) && ( V_1 -> V_218 & V_221 ) ) {
if ( ( V_167 - V_161 - 4 - 1 ) < 0 )
return NULL ;
F_22 ( V_217 , V_161 ) ;
F_22 ( 1 , V_161 ) ;
if ( V_1 -> V_218 & V_219 )
* ( V_161 ++ ) = V_220 ;
else
* ( V_161 ++ ) = V_221 ;
}
#endif
#ifndef F_79
V_240 = V_1 -> V_39 -> V_240 ;
V_1 -> V_39 -> V_240 = 0 ;
if ( V_240 && V_1 -> V_222 -> V_252 ) {
const unsigned char * V_253 ;
unsigned int V_254 ;
int V_255 ;
V_255 = V_1 -> V_222 -> V_252 ( V_1 , & V_253 , & V_254 ,
V_1 ->
V_222 -> V_256 ) ;
if ( V_255 == V_257 ) {
if ( ( long ) ( V_167 - V_161 - 4 - V_254 ) < 0 )
return NULL ;
F_22 ( V_225 , V_161 ) ;
F_22 ( V_254 , V_161 ) ;
memcpy ( V_161 , V_253 , V_254 ) ;
V_161 += V_254 ;
V_1 -> V_39 -> V_240 = 1 ;
}
}
#endif
if ( ! F_84 ( V_1 , 1 , & V_161 , V_167 , V_168 ) )
return NULL ;
if ( V_1 -> V_39 -> V_12 & V_258 ) {
if ( V_1 -> V_39 -> V_40 . V_41 -> V_259 == V_260
|| V_1 -> V_39 -> V_40 . V_41 -> V_261 == V_262
|| V_1 -> V_39 -> V_40 . V_41 -> V_261 == V_263
|| V_1 -> V_39 -> V_40 . V_41 -> V_261 == V_264 )
V_1 -> V_39 -> V_12 &= ~ V_258 ;
else {
F_22 ( V_232 , V_161 ) ;
F_22 ( 0 , V_161 ) ;
}
}
if ( V_1 -> V_39 -> V_12 & V_265 ) {
F_22 ( V_235 , V_161 ) ;
F_22 ( 0 , V_161 ) ;
}
if ( V_1 -> V_39 -> V_266 != NULL ) {
const unsigned char * V_267 = V_1 -> V_39 -> V_266 ;
unsigned int V_34 = V_1 -> V_39 -> V_268 ;
if ( ( long ) ( V_167 - V_161 - 4 - 2 - 1 - V_34 ) < 0 )
return NULL ;
F_22 ( V_228 , V_161 ) ;
F_22 ( 3 + V_34 , V_161 ) ;
F_22 ( 1 + V_34 , V_161 ) ;
* V_161 ++ = V_34 ;
memcpy ( V_161 , V_267 , V_34 ) ;
V_161 += V_34 ;
}
V_163:
if ( ( V_169 = V_161 - V_170 - 2 ) == 0 )
return V_170 ;
F_22 ( V_169 , V_170 ) ;
return V_161 ;
}
static int F_90 ( T_1 * V_1 , T_12 * V_269 , int * V_168 )
{
T_12 V_270 , V_271 , V_272 ;
* V_168 = V_273 ;
if ( ! F_91 ( V_269 , & V_270 )
|| F_62 ( & V_270 ) < 2 ) {
return 0 ;
}
V_271 = V_270 ;
do {
if ( ! F_92 ( & V_270 , & V_272 )
|| F_62 ( & V_272 ) == 0 ) {
return 0 ;
}
} while ( F_62 ( & V_270 ) != 0 );
if ( ! F_93 ( & V_271 ,
& V_1 -> V_39 -> V_274 , & V_1 -> V_39 -> V_275 ) ) {
* V_168 = V_276 ;
return 0 ;
}
return 1 ;
}
static int F_94 ( T_1 * V_1 , int * V_168 )
{
const unsigned char * V_267 = NULL ;
unsigned char V_277 = 0 ;
if ( V_1 -> V_222 -> V_278 != NULL && V_1 -> V_39 -> V_274 != NULL ) {
int V_255 = V_1 -> V_222 -> V_278 ( V_1 , & V_267 , & V_277 ,
V_1 -> V_39 -> V_274 ,
V_1 -> V_39 -> V_275 ,
V_1 -> V_222 -> V_279 ) ;
if ( V_255 == V_257 ) {
F_5 ( V_1 -> V_39 -> V_266 ) ;
V_1 -> V_39 -> V_266 = F_95 ( V_267 , V_277 ) ;
if ( V_1 -> V_39 -> V_266 == NULL ) {
* V_168 = V_280 ;
return 0 ;
}
V_1 -> V_39 -> V_268 = V_277 ;
#ifndef F_79
V_1 -> V_39 -> V_240 = 0 ;
#endif
} else {
* V_168 = V_281 ;
return 0 ;
}
}
return 1 ;
}
static void F_96 ( T_1 * V_1 , const T_12 * V_269 )
{
unsigned int type ;
T_12 V_282 , V_283 ;
T_3 V_284 ;
static const unsigned char V_285 [] = {
0x00 , 0x0a ,
0x00 , 0x08 ,
0x00 , 0x06 ,
0x00 , 0x17 ,
0x00 , 0x18 ,
0x00 , 0x19 ,
0x00 , 0x0b ,
0x00 , 0x02 ,
0x01 ,
0x00 ,
0x00 , 0x0d ,
0x00 , 0x0c ,
0x00 , 0x0a ,
0x05 , 0x01 ,
0x04 , 0x01 ,
0x02 , 0x01 ,
0x04 , 0x03 ,
0x02 , 0x03 ,
} ;
static const T_3 V_286 = 18 ;
V_283 = * V_269 ;
if ( ! F_97 ( & V_283 , 2 )
|| ! F_63 ( & V_283 , & type )
|| ! F_64 ( & V_283 , & V_282 ) ) {
return;
}
if ( type != V_188 )
return;
V_284 = F_98 ( V_1 ) >= V_287 ?
sizeof( V_285 ) : V_286 ;
V_1 -> V_39 -> V_288 = F_99 ( & V_283 , V_285 ,
V_284 ) ;
}
static int F_100 ( T_1 * V_1 , T_12 * V_269 , int * V_168 )
{
unsigned int type ;
int V_289 = 0 ;
T_12 V_158 ;
* V_168 = V_273 ;
V_1 -> V_244 = 0 ;
V_1 -> V_208 = - 1 ;
#ifndef F_79
V_1 -> V_39 -> V_240 = 0 ;
#endif
F_5 ( V_1 -> V_39 -> V_266 ) ;
V_1 -> V_39 -> V_266 = NULL ;
V_1 -> V_39 -> V_268 = 0 ;
F_5 ( V_1 -> V_39 -> V_274 ) ;
V_1 -> V_39 -> V_274 = NULL ;
V_1 -> V_39 -> V_275 = 0 ;
#ifndef F_78
V_1 -> V_218 &= ~ ( V_221 |
V_220 ) ;
#endif
#ifndef F_44
if ( V_1 -> V_59 & V_290 )
F_96 ( V_1 , V_269 ) ;
#endif
F_5 ( V_1 -> V_39 -> V_40 . V_291 ) ;
V_1 -> V_39 -> V_40 . V_291 = NULL ;
V_1 -> V_39 -> V_12 &= ~ V_258 ;
#ifndef F_54
F_5 ( V_1 -> V_140 . V_190 ) ;
V_1 -> V_140 . V_190 = NULL ;
#endif
V_1 -> V_249 = NULL ;
if ( F_62 ( V_269 ) == 0 )
goto V_292;
if ( ! F_91 ( V_269 , & V_158 ) )
return 0 ;
if ( ! F_61 ( & V_158 ) )
return 0 ;
while ( F_63 ( & V_158 , & type ) ) {
T_12 V_162 ;
if ( ! F_64 ( & V_158 , & V_162 ) )
return 0 ;
if ( V_1 -> V_293 )
V_1 -> V_293 ( V_1 , 0 , type , F_101 ( & V_162 ) ,
F_62 ( & V_162 ) ,
V_1 -> V_294 ) ;
if ( type == V_182 ) {
if ( ! F_102 ( V_1 , & V_162 , V_168 ) )
return 0 ;
V_289 = 1 ;
} else if ( V_1 -> V_5 == V_184 ) {
}
else if ( type == V_188 ) {
unsigned int V_295 ;
T_12 V_282 , V_296 ;
if ( ! F_91 ( & V_162 , & V_282 )
|| F_62 ( & V_282 ) == 0 ) {
return 0 ;
}
if ( ! F_103 ( & V_282 , & V_295 )
|| V_295 != V_189
|| ! F_91 ( & V_282 , & V_296 ) ) {
return 0 ;
}
if ( ! V_1 -> V_243 ) {
if ( F_62 ( & V_296 ) > V_297 ) {
* V_168 = V_298 ;
return 0 ;
}
if ( F_104 ( & V_296 ) ) {
* V_168 = V_298 ;
return 0 ;
}
if ( ! F_105 ( & V_296 , & V_1 -> V_19 -> V_185 ) ) {
* V_168 = V_276 ;
return 0 ;
}
V_1 -> V_244 = 1 ;
} else {
V_1 -> V_244 = V_1 -> V_19 -> V_185
&& F_99 ( & V_296 , V_1 -> V_19 -> V_185 ,
strlen ( V_1 -> V_19 -> V_185 ) ) ;
}
}
#ifndef F_54
else if ( type == V_192 ) {
T_12 V_299 ;
if ( ! F_106 ( & V_162 , & V_299 ) )
return 0 ;
if ( F_104 ( & V_299 ) )
return 0 ;
if ( ! F_105 ( & V_299 , & V_1 -> V_140 . V_190 ) ) {
* V_168 = V_276 ;
return 0 ;
}
}
#endif
#ifndef F_44
else if ( type == V_194 ) {
T_12 V_300 ;
if ( ! F_106 ( & V_162 , & V_300 )
|| F_62 ( & V_300 ) == 0 ) {
return 0 ;
}
if ( ! V_1 -> V_243 ) {
if ( ! F_93 ( & V_300 ,
& V_1 -> V_19 -> V_90 ,
& V_1 ->
V_19 -> V_91 ) ) {
* V_168 = V_276 ;
return 0 ;
}
}
} else if ( type == V_195 ) {
T_12 V_301 ;
if ( ! F_91 ( & V_162 , & V_301 )
|| F_62 ( & V_301 ) == 0
|| ( F_62 ( & V_301 ) % 2 ) != 0 ) {
return 0 ;
}
if ( ! V_1 -> V_243 ) {
if ( ! F_93 ( & V_301 ,
& V_1 -> V_19 -> V_20 ,
& V_1 ->
V_19 -> V_21 ) ) {
* V_168 = V_276 ;
return 0 ;
}
}
}
#endif
else if ( type == V_204 ) {
if ( V_1 -> V_302 &&
! V_1 -> V_302 ( V_1 , F_101 ( & V_162 ) ,
F_62 ( & V_162 ) ,
V_1 -> V_303 ) )
{
* V_168 = V_276 ;
return 0 ;
}
} else if ( type == V_207 ) {
T_12 V_304 ;
if ( ! F_91 ( & V_162 , & V_304 )
|| ( F_62 ( & V_304 ) % 2 ) != 0
|| F_62 ( & V_304 ) == 0 ) {
return 0 ;
}
if ( ! V_1 -> V_243 ) {
if ( ! F_107 ( V_1 , F_101 ( & V_304 ) ,
F_62 ( & V_304 ) ) ) {
return 0 ;
}
}
} else if ( type == V_215 ) {
if ( ! F_103 ( & V_162 ,
( unsigned int * ) & V_1 -> V_208 ) ) {
return 0 ;
}
#ifndef F_73
if ( V_1 -> V_208 == V_209 ) {
const unsigned char * V_305 ;
T_12 V_306 , V_307 ;
if ( ! F_64
( & V_162 , & V_306 ) )
return 0 ;
while ( F_62 ( & V_306 ) > 0 ) {
T_13 * V_42 ;
T_12 V_308 ;
const unsigned char * V_309 ;
if ( ! F_64 ( & V_306 ,
& V_308 )
|| F_62 ( & V_308 ) == 0 ) {
return 0 ;
}
if ( V_1 -> V_213 == NULL
&& ( V_1 -> V_213 =
F_108 () ) == NULL ) {
* V_168 = V_280 ;
return 0 ;
}
V_309 = F_101 ( & V_308 ) ;
V_42 = F_109 ( NULL , & V_309 ,
F_62 ( & V_308 ) ) ;
if ( V_42 == NULL )
return 0 ;
if ( V_309 != F_110 ( & V_308 ) ) {
F_111 ( V_42 ) ;
return 0 ;
}
if ( ! F_112 ( V_1 -> V_213 , V_42 ) ) {
F_111 ( V_42 ) ;
* V_168 = V_280 ;
return 0 ;
}
}
if ( ! F_91 ( & V_162 , & V_307 ) )
return 0 ;
if ( F_62 ( & V_307 ) > 0 ) {
V_305 = F_101 ( & V_307 ) ;
F_113 ( V_1 -> V_214 ,
V_310 ) ;
V_1 -> V_214 =
F_114 ( NULL , & V_305 ,
F_62 ( & V_307 ) ) ;
if ( V_1 -> V_214 == NULL
|| V_305 != F_110 ( & V_307 ) ) {
return 0 ;
}
}
} else
#endif
{
V_1 -> V_208 = - 1 ;
}
}
#ifndef F_78
else if ( F_56 ( V_1 ) && type == V_217 ) {
unsigned int V_311 ;
if ( ! F_103 ( & V_162 , & V_311 )
|| F_62 ( & V_162 ) ) {
* V_168 = V_273 ;
return 0 ;
}
switch ( V_311 ) {
case 0x01 :
V_1 -> V_218 |= V_221 ;
break;
case 0x02 :
V_1 -> V_218 |= V_221 ;
V_1 -> V_218 |= V_220 ;
break;
default:
* V_168 = V_312 ;
return 0 ;
}
}
#endif
#ifndef F_79
else if ( type == V_225 &&
V_1 -> V_39 -> V_40 . V_224 == 0 ) {
V_1 -> V_39 -> V_240 = 1 ;
}
#endif
else if ( type == V_228 &&
V_1 -> V_39 -> V_40 . V_224 == 0 ) {
if ( ! F_90 ( V_1 , & V_162 , V_168 ) )
return 0 ;
}
#ifndef F_80
else if ( F_56 ( V_1 ) && F_81 ( V_1 )
&& type == V_230 ) {
if ( F_115 ( V_1 , & V_162 , V_168 ) )
return 0 ;
}
#endif
else if ( type == V_232 )
V_1 -> V_39 -> V_12 |= V_258 ;
else if ( ! V_1 -> V_243 ) {
if ( F_116 ( V_1 , 1 , type , F_101 ( & V_162 ) ,
F_62 ( & V_162 ) , V_168 ) <= 0 )
return 0 ;
}
}
if ( F_62 ( V_269 ) != 0 ) {
* V_168 = V_280 ;
return 0 ;
}
V_292:
if ( ! V_289 && V_1 -> V_179 &&
! ( V_1 -> V_59 & V_313 ) ) {
* V_168 = V_314 ;
F_14 ( V_315 ,
V_316 ) ;
return 0 ;
}
return 1 ;
}
int F_117 ( T_1 * V_1 , T_12 * V_269 )
{
int V_168 = - 1 ;
F_83 ( & V_1 -> V_100 -> V_317 ) ;
if ( F_100 ( V_1 , V_269 , & V_168 ) <= 0 ) {
F_118 ( V_1 , V_318 , V_168 ) ;
return 0 ;
}
if ( F_119 ( V_1 ) <= 0 ) {
F_14 ( V_319 , V_320 ) ;
return 0 ;
}
return 1 ;
}
static char F_120 ( T_12 * V_269 )
{
T_12 V_321 ;
while ( F_62 ( V_269 ) ) {
if ( ! F_92 ( V_269 , & V_321 )
|| F_62 ( & V_321 ) == 0 )
return 0 ;
}
return 1 ;
}
static int F_121 ( T_1 * V_1 , T_12 * V_269 , int * V_168 )
{
unsigned int V_202 , type , V_322 ;
int V_323 = 0 ;
int V_289 = 0 ;
#ifndef F_79
V_1 -> V_39 -> V_240 = 0 ;
#endif
V_1 -> V_247 = 0 ;
F_5 ( V_1 -> V_39 -> V_266 ) ;
V_1 -> V_39 -> V_266 = NULL ;
#ifndef F_78
V_1 -> V_218 &= ~ ( V_221 |
V_220 ) ;
#endif
V_1 -> V_39 -> V_12 &= ~ V_258 ;
V_1 -> V_39 -> V_12 &= ~ V_265 ;
if ( ! F_63 ( V_269 , & V_202 ) )
goto V_292;
if ( F_62 ( V_269 ) != V_202 ) {
* V_168 = V_273 ;
return 0 ;
}
if ( ! F_61 ( V_269 ) ) {
* V_168 = V_273 ;
return 0 ;
}
while ( F_63 ( V_269 , & type ) && F_63 ( V_269 , & V_322 ) ) {
const unsigned char * V_201 ;
T_12 V_324 ;
if ( ! F_122 ( V_269 , & V_324 , V_322 )
|| ! F_123 ( & V_324 , & V_201 , V_322 ) )
goto V_292;
if ( V_1 -> V_293 )
V_1 -> V_293 ( V_1 , 1 , type , V_201 , V_322 , V_1 -> V_294 ) ;
if ( type == V_182 ) {
if ( ! F_124 ( V_1 , & V_324 , V_168 ) )
return 0 ;
V_289 = 1 ;
} else if ( V_1 -> V_5 == V_184 ) {
} else if ( type == V_188 ) {
if ( V_1 -> V_185 == NULL || V_322 > 0 ) {
* V_168 = V_298 ;
return 0 ;
}
V_323 = 1 ;
}
#ifndef F_44
else if ( type == V_194 ) {
unsigned int V_325 ;
if ( ! F_103 ( & V_324 , & V_325 )
|| V_325 != V_322 - 1 ) {
* V_168 = V_326 ;
return 0 ;
}
if ( ! V_1 -> V_243 ) {
V_1 -> V_19 -> V_91 = 0 ;
F_5 ( V_1 -> V_19 -> V_90 ) ;
if ( ( V_1 -> V_19 -> V_90 =
F_21 ( V_325 ) ) == NULL ) {
* V_168 = V_276 ;
return 0 ;
}
V_1 -> V_19 -> V_91 =
V_325 ;
if ( ! F_125 ( & V_324 ,
V_1 -> V_19 -> V_90 ,
V_325 ) ) {
* V_168 = V_326 ;
return 0 ;
}
}
}
#endif
else if ( type == V_204 ) {
if ( V_1 -> V_302 &&
! V_1 -> V_302 ( V_1 , V_201 , V_322 ,
V_1 -> V_303 ) )
{
* V_168 = V_276 ;
return 0 ;
}
if ( ! F_59 ( V_1 ) || ( V_322 > 0 ) ) {
* V_168 = V_327 ;
return 0 ;
}
V_1 -> V_247 = 1 ;
} else if ( type == V_215 ) {
if ( ( V_1 -> V_208 == - 1 ) || ( V_322 > 0 ) ) {
* V_168 = V_327 ;
return 0 ;
}
V_1 -> V_248 = 1 ;
}
#ifndef F_85
else if ( type == V_234 &&
V_1 -> V_233 != NULL ) {
if ( V_1 -> V_328 != NULL ) {
F_5 ( V_1 -> V_328 ) ;
V_1 -> V_328 = NULL ;
}
V_1 -> V_329 = V_322 ;
if ( V_322 > 0 ) {
V_1 -> V_328 = F_21 ( V_322 ) ;
if ( V_1 -> V_328 == NULL ) {
* V_168 = V_276 ;
return 0 ;
}
memcpy ( V_1 -> V_328 , V_201 , V_322 ) ;
}
}
#endif
#ifndef F_79
else if ( type == V_225 &&
V_1 -> V_39 -> V_40 . V_224 == 0 ) {
unsigned char * V_267 ;
unsigned char V_277 ;
if ( V_1 -> V_222 -> V_223 == NULL ) {
* V_168 = V_327 ;
return 0 ;
}
if ( ! F_120 ( & V_324 ) ) {
* V_168 = V_326 ;
return 0 ;
}
if ( V_1 -> V_222 -> V_223 ( V_1 , & V_267 , & V_277 , V_201 ,
V_322 ,
V_1 ->
V_222 -> V_330 ) !=
V_257 ) {
* V_168 = V_276 ;
return 0 ;
}
V_1 -> V_331 = F_21 ( V_277 ) ;
if ( V_1 -> V_331 == NULL ) {
* V_168 = V_276 ;
return 0 ;
}
memcpy ( V_1 -> V_331 , V_267 , V_277 ) ;
V_1 -> V_332 = V_277 ;
V_1 -> V_39 -> V_240 = 1 ;
}
#endif
else if ( type == V_228 ) {
unsigned V_34 ;
if ( ! V_1 -> V_39 -> V_229 ) {
* V_168 = V_327 ;
return 0 ;
}
if ( ! F_63 ( & V_324 , & V_34 )
|| F_62 ( & V_324 ) != V_34 || ! F_103 ( & V_324 , & V_34 )
|| F_62 ( & V_324 ) != V_34 ) {
* V_168 = V_326 ;
return 0 ;
}
F_5 ( V_1 -> V_39 -> V_266 ) ;
V_1 -> V_39 -> V_266 = F_21 ( V_34 ) ;
if ( V_1 -> V_39 -> V_266 == NULL ) {
* V_168 = V_276 ;
return 0 ;
}
if ( ! F_125 ( & V_324 , V_1 -> V_39 -> V_266 , V_34 ) ) {
* V_168 = V_326 ;
return 0 ;
}
V_1 -> V_39 -> V_268 = V_34 ;
}
#ifndef F_78
else if ( F_56 ( V_1 ) && type == V_217 ) {
unsigned int V_311 ;
if ( ! F_103 ( & V_324 , & V_311 ) ) {
* V_168 = V_273 ;
return 0 ;
}
switch ( V_311 ) {
case 0x01 :
V_1 -> V_218 |= V_221 ;
break;
case 0x02 :
V_1 -> V_218 |= V_221 ;
V_1 -> V_218 |= V_220 ;
break;
default:
* V_168 = V_312 ;
return 0 ;
}
}
#endif
#ifndef F_80
else if ( F_56 ( V_1 ) && type == V_230 ) {
if ( F_126 ( V_1 , & V_324 , V_168 ) )
return 0 ;
}
#endif
else if ( type == V_232 ) {
if ( V_1 -> V_39 -> V_40 . V_41 -> V_259 != V_260
&& V_1 -> V_39 -> V_40 . V_41 -> V_261 != V_262 )
V_1 -> V_39 -> V_12 |= V_258 ;
} else if ( type == V_235 ) {
V_1 -> V_39 -> V_12 |= V_265 ;
if ( ! V_1 -> V_243 )
V_1 -> V_19 -> V_12 |= V_333 ;
}
else if ( F_116 ( V_1 , 0 , type , V_201 , V_322 , V_168 ) <= 0 )
return 0 ;
}
if ( F_62 ( V_269 ) != 0 ) {
* V_168 = V_273 ;
return 0 ;
}
if ( ! V_1 -> V_243 && V_323 == 1 ) {
if ( V_1 -> V_185 ) {
if ( V_1 -> V_19 -> V_185 == NULL ) {
V_1 -> V_19 -> V_185 =
F_127 ( V_1 -> V_185 ) ;
if ( ! V_1 -> V_19 -> V_185 ) {
* V_168 = V_334 ;
return 0 ;
}
} else {
* V_168 = V_273 ;
return 0 ;
}
}
}
V_292:
if ( ! V_289 && ! ( V_1 -> V_59 & V_335 )
&& ! ( V_1 -> V_59 & V_313 ) ) {
* V_168 = V_314 ;
F_14 ( V_336 ,
V_316 ) ;
return 0 ;
}
if ( V_1 -> V_243 ) {
if ( ! ( V_1 -> V_39 -> V_12 & V_265 ) !=
! ( V_1 -> V_19 -> V_12 & V_333 ) ) {
* V_168 = V_314 ;
F_14 ( V_336 , V_337 ) ;
return 0 ;
}
}
return 1 ;
}
int F_128 ( T_1 * V_1 )
{
V_1 -> V_39 -> V_229 = 0 ;
return 1 ;
}
int F_129 ( T_1 * V_1 )
{
return 1 ;
}
static int F_119 ( T_1 * V_1 )
{
int V_161 = V_338 ;
int V_168 = V_334 ;
#ifndef F_44
#endif
if ( V_1 -> V_222 != NULL && V_1 -> V_222 -> V_339 != 0 )
V_161 =
V_1 -> V_222 -> V_339 ( V_1 , & V_168 ,
V_1 -> V_222 -> V_340 ) ;
else if ( V_1 -> V_341 != NULL
&& V_1 -> V_341 -> V_339 != 0 )
V_161 =
V_1 -> V_341 -> V_339 ( V_1 , & V_168 ,
V_1 ->
V_341 -> V_340 ) ;
switch ( V_161 ) {
case V_342 :
F_118 ( V_1 , V_318 , V_168 ) ;
return - 1 ;
case V_343 :
F_118 ( V_1 , V_344 , V_168 ) ;
return 1 ;
case V_338 :
V_1 -> V_244 = 0 ;
default:
return 1 ;
}
}
void F_130 ( T_1 * V_1 )
{
const T_10 * * V_115 = V_1 -> V_39 -> V_40 . V_106 ;
#ifndef F_131
V_115 [ V_345 ] = F_132 ( V_346 ) ;
#endif
#ifndef F_133
if ( F_134 ( V_1 ) )
V_115 [ V_347 ] = F_132 ( V_346 ) ;
else
V_115 [ V_347 ] = F_132 ( V_348 ) ;
V_115 [ V_349 ] = V_115 [ V_347 ] ;
#endif
#ifndef F_44
V_115 [ V_107 ] = F_132 ( V_346 ) ;
#endif
#ifndef F_135
V_115 [ V_350 ] = F_132 ( V_351 ) ;
V_115 [ V_352 ] = F_132 ( V_353 ) ;
V_115 [ V_354 ] = F_132 ( V_355 ) ;
#endif
}
int F_136 ( T_1 * V_1 )
{
int V_168 ;
T_3 V_14 ;
F_5 ( V_1 -> V_100 -> V_104 ) ;
V_1 -> V_100 -> V_104 = NULL ;
V_1 -> V_100 -> V_103 = 0 ;
for ( V_14 = 0 ; V_14 < V_356 ; V_14 ++ ) {
V_1 -> V_39 -> V_40 . V_106 [ V_14 ] = NULL ;
V_1 -> V_39 -> V_40 . V_357 [ V_14 ] = 0 ;
}
if ( V_1 -> V_39 -> V_40 . V_291 ) {
if ( ! F_137 ( V_1 ) ) {
F_14 ( V_358 , V_165 ) ;
V_168 = V_280 ;
goto V_359;
}
if ( ! V_1 -> V_100 -> V_104 ) {
F_14 ( V_358 ,
V_360 ) ;
V_168 = V_312 ;
goto V_359;
}
} else {
F_130 ( V_1 ) ;
}
return 1 ;
V_359:
F_118 ( V_1 , V_318 , V_168 ) ;
return 0 ;
}
int F_138 ( T_1 * V_1 , int * V_168 )
{
V_1 -> V_248 = 0 ;
if ( ( V_1 -> V_208 != - 1 ) && V_1 -> V_222 && V_1 -> V_222 -> V_361 ) {
int V_161 ;
T_14 * V_362 ;
V_362 = F_139 ( V_1 ) ;
if ( V_362 != NULL ) {
V_1 -> V_100 -> V_363 = V_362 ;
V_161 = V_1 -> V_222 -> V_361 ( V_1 , V_1 -> V_222 -> V_364 ) ;
switch ( V_161 ) {
case V_338 :
V_1 -> V_248 = 0 ;
break;
case V_257 :
if ( V_1 -> V_365 )
V_1 -> V_248 = 1 ;
break;
case V_342 :
default:
* V_168 = V_280 ;
return 0 ;
}
}
}
if ( ! F_94 ( V_1 , V_168 ) ) {
return 0 ;
}
return 1 ;
}
int F_140 ( T_1 * V_1 )
{
int V_161 = V_338 ;
int V_168 = V_334 ;
#ifndef F_44
unsigned long V_173 = V_1 -> V_39 -> V_40 . V_41 -> V_144 ;
unsigned long V_174 = V_1 -> V_39 -> V_40 . V_41 -> V_145 ;
if ( ( V_1 -> V_90 != NULL )
&& ( V_1 -> V_91 > 0 )
&& ( V_1 -> V_19 -> V_90 != NULL )
&& ( V_1 -> V_19 -> V_91 > 0 )
&& ( ( V_173 & V_176 ) || ( V_174 & V_178 ) ) ) {
T_3 V_14 ;
unsigned char * V_366 ;
int V_367 = 0 ;
V_366 = V_1 -> V_19 -> V_90 ;
for ( V_14 = 0 ; V_14 < V_1 -> V_19 -> V_91 ; V_14 ++ ) {
if ( * ( V_366 ++ ) == V_83 ) {
V_367 = 1 ;
break;
}
}
if ( ! V_367 ) {
F_14 ( V_368 ,
V_369 ) ;
return - 1 ;
}
}
V_161 = V_257 ;
#endif
if ( V_1 -> V_222 != NULL && V_1 -> V_222 -> V_339 != 0 )
V_161 =
V_1 -> V_222 -> V_339 ( V_1 , & V_168 ,
V_1 -> V_222 -> V_340 ) ;
else if ( V_1 -> V_341 != NULL
&& V_1 -> V_341 -> V_339 != 0 )
V_161 =
V_1 -> V_341 -> V_339 ( V_1 , & V_168 ,
V_1 ->
V_341 -> V_340 ) ;
F_5 ( V_1 -> V_365 ) ;
V_1 -> V_365 = NULL ;
V_1 -> V_370 = - 1 ;
switch ( V_161 ) {
case V_342 :
F_118 ( V_1 , V_318 , V_168 ) ;
return - 1 ;
case V_343 :
F_118 ( V_1 , V_344 , V_168 ) ;
return 1 ;
case V_338 :
V_1 -> V_244 = 0 ;
default:
return 1 ;
}
}
int F_141 ( T_1 * V_1 , T_12 * V_269 )
{
int V_168 = - 1 ;
if ( V_1 -> V_5 < V_184 )
return 1 ;
if ( F_121 ( V_1 , V_269 , & V_168 ) <= 0 ) {
F_118 ( V_1 , V_318 , V_168 ) ;
return 0 ;
}
if ( F_140 ( V_1 ) <= 0 ) {
F_14 ( V_371 , V_372 ) ;
return 0 ;
}
return 1 ;
}
int F_142 ( T_1 * V_1 , const T_12 * V_373 ,
const T_12 * V_374 ,
T_15 * * V_161 )
{
unsigned int V_14 ;
T_12 V_375 = * V_373 ;
int V_376 = - 1 ;
int V_377 = 0 ;
int V_378 = F_59 ( V_1 ) ;
* V_161 = NULL ;
V_1 -> V_247 = 0 ;
V_1 -> V_39 -> V_12 &= ~ V_265 ;
if ( ( V_1 -> V_5 <= V_184 ) )
return 0 ;
if ( ! F_63 ( & V_375 , & V_14 ) ) {
V_376 = 0 ;
goto V_379;
}
while ( F_62 ( & V_375 ) >= 4 ) {
unsigned int type , V_322 ;
if ( ! F_63 ( & V_375 , & type )
|| ! F_63 ( & V_375 , & V_322 ) ) {
V_376 = - 1 ;
goto V_379;
}
if ( F_62 ( & V_375 ) < V_322 ) {
V_376 = 0 ;
goto V_379;
}
if ( type == V_204 && V_378 ) {
int V_255 ;
const unsigned char * V_380 ;
if ( V_377 != 0 ) {
V_376 = - 1 ;
goto V_379;
}
V_377 = 1 ;
if ( V_322 == 0 ) {
V_1 -> V_247 = 1 ;
V_376 = 1 ;
continue;
}
if ( V_1 -> V_381 ) {
V_376 = 2 ;
continue;
}
if ( ! F_143 ( & V_375 , & V_380 , V_322 ) ) {
V_376 = - 1 ;
goto V_379;
}
V_255 = F_144 ( V_1 , V_380 , V_322 , F_101 ( V_374 ) ,
F_62 ( V_374 ) , V_161 ) ;
switch ( V_255 ) {
case 2 :
V_1 -> V_247 = 1 ;
V_376 = 2 ;
break;
case 3 :
V_376 = V_255 ;
break;
case 4 :
V_1 -> V_247 = 1 ;
V_376 = 3 ;
break;
default:
V_376 = - 1 ;
break;
}
continue;
} else {
if ( type == V_235 )
V_1 -> V_39 -> V_12 |= V_265 ;
if ( ! F_97 ( & V_375 , V_322 ) ) {
V_376 = - 1 ;
goto V_379;
}
}
}
if ( V_377 == 0 )
V_376 = 0 ;
V_379:
return V_376 ;
}
static int F_144 ( T_1 * V_1 , const unsigned char * V_380 ,
int V_382 , const unsigned char * V_383 ,
int V_384 , T_15 * * V_385 )
{
T_15 * V_15 ;
unsigned char * V_386 ;
const unsigned char * V_33 ;
int V_387 , V_388 , V_389 = 0 , V_161 = - 1 ;
unsigned char V_390 [ V_391 ] ;
T_16 * V_392 = NULL ;
T_17 * V_222 ;
T_18 * V_393 = V_1 -> V_341 ;
V_392 = F_145 () ;
if ( V_392 == NULL )
return - 2 ;
V_222 = F_146 () ;
if ( V_222 == NULL ) {
V_161 = - 2 ;
goto V_359;
}
if ( V_393 -> V_394 ) {
unsigned char * V_395 = ( unsigned char * ) V_380 ;
int V_96 = V_393 -> V_394 ( V_1 , V_395 , V_395 + 16 ,
V_222 , V_392 , 0 ) ;
if ( V_96 < 0 )
goto V_359;
if ( V_96 == 0 ) {
V_161 = 2 ;
goto V_359;
}
if ( V_96 == 2 )
V_389 = 1 ;
} else {
if ( memcmp ( V_380 , V_393 -> V_396 ,
sizeof( V_393 -> V_396 ) ) != 0 ) {
V_161 = 2 ;
goto V_359;
}
if ( F_147 ( V_392 , V_393 -> V_397 ,
sizeof( V_393 -> V_397 ) ,
F_40 () , NULL ) <= 0
|| F_148 ( V_222 , F_149 () , NULL ,
V_393 -> V_398 ,
V_380 + sizeof( V_393 -> V_396 ) ) <=
0 ) {
goto V_359;
}
}
V_388 = F_150 ( V_392 ) ;
if ( V_388 < 0 ) {
goto V_359;
}
if ( V_382 <=
V_399 + F_151 ( V_222 ) + V_388 ) {
V_161 = 2 ;
goto V_359;
}
V_382 -= V_388 ;
if ( F_152 ( V_392 , V_380 , V_382 ) <= 0
|| F_153 ( V_392 , V_390 , NULL ) <= 0 ) {
goto V_359;
}
F_154 ( V_392 ) ;
if ( F_155 ( V_390 , V_380 + V_382 , V_388 ) ) {
F_156 ( V_222 ) ;
return 2 ;
}
V_33 = V_380 + 16 + F_151 ( V_222 ) ;
V_382 -= 16 + F_151 ( V_222 ) ;
V_386 = F_21 ( V_382 ) ;
if ( V_386 == NULL || F_157 ( V_222 , V_386 , & V_387 , V_33 , V_382 ) <= 0 ) {
F_156 ( V_222 ) ;
F_5 ( V_386 ) ;
return - 1 ;
}
if ( F_158 ( V_222 , V_386 + V_387 , & V_388 ) <= 0 ) {
F_156 ( V_222 ) ;
F_5 ( V_386 ) ;
return 2 ;
}
V_387 += V_388 ;
F_156 ( V_222 ) ;
V_222 = NULL ;
V_33 = V_386 ;
V_15 = F_159 ( NULL , & V_33 , V_387 ) ;
F_5 ( V_386 ) ;
if ( V_15 ) {
if ( V_384 )
memcpy ( V_15 -> V_374 , V_383 , V_384 ) ;
V_15 -> V_400 = V_384 ;
* V_385 = V_15 ;
if ( V_389 )
return 4 ;
else
return 3 ;
}
F_160 () ;
return 2 ;
V_359:
F_156 ( V_222 ) ;
F_154 ( V_392 ) ;
return V_161 ;
}
static int F_161 ( int V_13 , const T_19 * V_401 , T_3 V_402 )
{
T_3 V_14 ;
for ( V_14 = 0 ; V_14 < V_402 ; V_14 ++ ) {
if ( V_401 [ V_14 ] . V_13 == V_13 )
return V_401 [ V_14 ] . V_42 ;
}
return - 1 ;
}
static int F_162 ( int V_42 , const T_19 * V_401 , T_3 V_402 )
{
T_3 V_14 ;
for ( V_14 = 0 ; V_14 < V_402 ; V_14 ++ ) {
if ( ( V_401 [ V_14 ] . V_42 ) == V_42 )
return V_401 [ V_14 ] . V_13 ;
}
return V_58 ;
}
int F_163 ( unsigned char * V_33 , const T_8 * V_403 , const T_10 * V_106 )
{
int V_404 , V_405 ;
if ( ! V_106 )
return 0 ;
V_405 = F_161 ( F_49 ( V_106 ) , V_406 , F_10 ( V_406 ) ) ;
if ( V_405 == - 1 )
return 0 ;
V_404 = F_46 ( V_403 ) ;
if ( V_404 == - 1 )
return 0 ;
V_33 [ 0 ] = ( unsigned char ) V_405 ;
V_33 [ 1 ] = ( unsigned char ) V_404 ;
return 1 ;
}
int F_46 ( const T_8 * V_403 )
{
return F_161 ( F_38 ( V_403 ) , V_407 , F_10 ( V_407 ) ) ;
}
static const T_20 * F_164 ( unsigned char V_408 )
{
unsigned int V_14 ;
if ( V_408 == 0 )
return NULL ;
for ( V_14 = 0 ; V_14 < F_10 ( V_409 ) ; V_14 ++ ) {
if ( V_409 [ V_14 ] . V_410 == V_408 )
return V_409 + V_14 ;
}
return NULL ;
}
const T_10 * F_47 ( unsigned char V_408 )
{
const T_20 * V_411 ;
if ( V_408 == V_412 && F_165 () )
return NULL ;
V_411 = F_164 ( V_408 ) ;
if ( ! V_411 )
return NULL ;
return F_132 ( V_411 -> V_413 ) ;
}
static int F_166 ( unsigned char V_414 )
{
switch ( V_414 ) {
#ifndef F_133
case V_415 :
return V_347 ;
#endif
#ifndef F_131
case V_416 :
return V_345 ;
#endif
#ifndef F_44
case V_417 :
return V_107 ;
#endif
#ifndef F_135
case V_418 :
return V_350 ;
case V_419 :
return V_352 ;
case V_420 :
return V_354 ;
#endif
}
return - 1 ;
}
static void F_167 ( int * V_421 , int * V_422 ,
int * V_423 , const unsigned char * V_201 )
{
int V_424 = V_58 , V_425 = V_58 ;
if ( ! V_421 && ! V_422 && ! V_423 )
return;
if ( V_421 || V_423 ) {
V_425 = F_162 ( V_201 [ 0 ] , V_406 , F_10 ( V_406 ) ) ;
if ( V_421 )
* V_421 = V_425 ;
}
if ( V_422 || V_423 ) {
V_424 = F_162 ( V_201 [ 1 ] , V_407 , F_10 ( V_407 ) ) ;
if ( V_422 )
* V_422 = V_424 ;
}
if ( V_423 ) {
if ( V_424 == V_58 || V_425 == V_58
|| F_168 ( V_423 , V_425 , V_424 ) <= 0 )
* V_423 = V_58 ;
}
}
static int F_169 ( T_1 * V_1 , int V_30 , const unsigned char * V_426 )
{
const T_20 * V_427 = F_164 ( V_426 [ 0 ] ) ;
if ( V_427 == NULL || F_132 ( V_427 -> V_413 ) == NULL )
return 0 ;
if ( F_166 ( V_426 [ 1 ] ) == - 1 )
return 0 ;
return F_17 ( V_1 , V_30 , V_427 -> V_32 , V_427 -> V_13 , ( void * ) V_426 ) ;
}
void F_51 ( T_21 * V_428 , T_1 * V_1 , int V_30 )
{
const unsigned char * V_429 ;
T_3 V_14 , V_430 ;
int V_431 = 0 , V_432 = 0 , V_433 = 0 ;
V_430 = F_43 ( V_1 , & V_429 ) ;
for ( V_14 = 0 ; V_14 < V_430 ; V_14 += 2 , V_429 += 2 ) {
switch ( V_429 [ 1 ] ) {
#ifndef F_133
case V_415 :
if ( ! V_431 && F_169 ( V_1 , V_30 , V_429 ) )
V_431 = 1 ;
break;
#endif
#ifndef F_131
case V_416 :
if ( ! V_432 && F_169 ( V_1 , V_30 , V_429 ) )
V_432 = 1 ;
break;
#endif
#ifndef F_44
case V_417 :
if ( ! V_433 && F_169 ( V_1 , V_30 , V_429 ) )
V_433 = 1 ;
break;
#endif
}
}
if ( ! V_431 )
* V_428 |= V_434 ;
if ( ! V_432 )
* V_428 |= V_435 ;
if ( ! V_433 )
* V_428 |= V_178 ;
}
T_3 F_72 ( T_1 * V_1 , unsigned char * V_436 ,
const unsigned char * V_437 , T_3 V_438 )
{
unsigned char * V_439 = V_436 ;
T_3 V_14 ;
for ( V_14 = 0 ; V_14 < V_438 ; V_14 += 2 , V_437 += 2 ) {
if ( F_169 ( V_1 , V_440 , V_437 ) ) {
* V_439 ++ = V_437 [ 0 ] ;
* V_439 ++ = V_437 [ 1 ] ;
}
}
return V_439 - V_436 ;
}
static int F_170 ( T_1 * V_1 , T_22 * V_441 ,
const unsigned char * V_49 , T_3 V_442 ,
const unsigned char * V_443 , T_3 V_444 )
{
const unsigned char * V_426 , * V_445 ;
T_3 V_14 , V_53 , V_48 = 0 ;
for ( V_14 = 0 , V_426 = V_49 ; V_14 < V_442 ; V_14 += 2 , V_426 += 2 ) {
if ( ! F_169 ( V_1 , V_446 , V_426 ) )
continue;
for ( V_53 = 0 , V_445 = V_443 ; V_53 < V_444 ; V_53 += 2 , V_445 += 2 ) {
if ( V_426 [ 0 ] == V_445 [ 0 ] && V_426 [ 1 ] == V_445 [ 1 ] ) {
V_48 ++ ;
if ( V_441 ) {
V_441 -> V_447 = V_426 [ 0 ] ;
V_441 -> V_448 = V_426 [ 1 ] ;
F_167 ( & V_441 -> V_425 ,
& V_441 -> V_424 ,
& V_441 -> V_105 , V_426 ) ;
V_441 ++ ;
}
break;
}
}
}
return V_48 ;
}
static int F_171 ( T_1 * V_1 )
{
const unsigned char * V_49 , * V_443 , * V_449 ;
T_3 V_442 , V_444 , V_450 ;
T_3 V_48 ;
T_22 * V_451 = NULL ;
T_9 * V_99 = V_1 -> V_100 ;
unsigned int V_452 = F_13 ( V_1 ) ;
F_5 ( V_99 -> V_104 ) ;
V_99 -> V_104 = NULL ;
V_99 -> V_103 = 0 ;
if ( ! V_1 -> V_55 && V_99 -> V_110 && ! V_452 ) {
V_449 = V_99 -> V_110 ;
V_450 = V_99 -> V_111 ;
} else if ( V_99 -> V_112 && ! V_452 ) {
V_449 = V_99 -> V_112 ;
V_450 = V_99 -> V_113 ;
} else
V_450 = F_43 ( V_1 , & V_449 ) ;
if ( V_1 -> V_59 & V_60 || V_452 ) {
V_49 = V_449 ;
V_442 = V_450 ;
V_443 = V_1 -> V_39 -> V_40 . V_291 ;
V_444 = V_1 -> V_39 -> V_40 . V_453 ;
} else {
V_443 = V_449 ;
V_444 = V_450 ;
V_49 = V_1 -> V_39 -> V_40 . V_291 ;
V_442 = V_1 -> V_39 -> V_40 . V_453 ;
}
V_48 = F_170 ( V_1 , NULL , V_49 , V_442 , V_443 , V_444 ) ;
if ( V_48 ) {
V_451 = F_21 ( V_48 * sizeof( T_22 ) ) ;
if ( V_451 == NULL )
return 0 ;
V_48 = F_170 ( V_1 , V_451 , V_49 , V_442 , V_443 , V_444 ) ;
} else {
V_451 = NULL ;
}
V_99 -> V_104 = V_451 ;
V_99 -> V_103 = V_48 ;
return 1 ;
}
int F_107 ( T_1 * V_1 , const unsigned char * V_201 , int V_454 )
{
T_9 * V_99 = V_1 -> V_100 ;
if ( ! F_134 ( V_1 ) )
return 1 ;
if ( ! V_99 )
return 0 ;
F_5 ( V_1 -> V_39 -> V_40 . V_291 ) ;
V_1 -> V_39 -> V_40 . V_291 = F_21 ( V_454 ) ;
if ( V_1 -> V_39 -> V_40 . V_291 == NULL )
return 0 ;
V_1 -> V_39 -> V_40 . V_453 = V_454 ;
memcpy ( V_1 -> V_39 -> V_40 . V_291 , V_201 , V_454 ) ;
return 1 ;
}
int F_137 ( T_1 * V_1 )
{
int V_455 ;
T_3 V_14 ;
const T_10 * V_106 ;
const T_10 * * V_115 = V_1 -> V_39 -> V_40 . V_106 ;
T_21 * V_456 = V_1 -> V_39 -> V_40 . V_357 ;
T_9 * V_99 = V_1 -> V_100 ;
T_22 * V_457 ;
if ( ! F_171 ( V_1 ) )
return 0 ;
for ( V_14 = 0 , V_457 = V_99 -> V_104 ;
V_14 < V_99 -> V_103 ; V_14 ++ , V_457 ++ ) {
V_455 = F_166 ( V_457 -> V_448 ) ;
if ( V_455 > 0 && V_115 [ V_455 ] == NULL ) {
V_106 = F_47 ( V_457 -> V_447 ) ;
V_115 [ V_455 ] = V_106 ;
V_456 [ V_455 ] = V_458 ;
if ( V_455 == V_347 ) {
V_456 [ V_349 ] = V_458 ;
V_115 [ V_349 ] = V_106 ;
}
}
}
if ( ! ( V_1 -> V_100 -> V_127 & V_128 ) ) {
#ifndef F_131
if ( V_115 [ V_345 ] == NULL )
V_115 [ V_345 ] = F_172 () ;
#endif
#ifndef F_133
if ( V_115 [ V_347 ] == NULL ) {
V_115 [ V_347 ] = F_172 () ;
V_115 [ V_349 ] = F_172 () ;
}
#endif
#ifndef F_44
if ( V_115 [ V_107 ] == NULL )
V_115 [ V_107 ] = F_172 () ;
#endif
#ifndef F_135
if ( V_115 [ V_350 ] == NULL )
V_115 [ V_350 ] = F_173 ( V_459 ) ;
if ( V_115 [ V_352 ] == NULL )
V_115 [ V_352 ] =
F_173 ( V_460 ) ;
if ( V_115 [ V_354 ] == NULL )
V_115 [ V_354 ] =
F_173 ( V_461 ) ;
#endif
}
return 1 ;
}
int F_174 ( T_1 * V_1 , int V_455 ,
int * V_462 , int * V_463 , int * V_464 ,
unsigned char * V_465 , unsigned char * V_447 )
{
const unsigned char * V_437 = V_1 -> V_39 -> V_40 . V_291 ;
if ( V_437 == NULL )
return 0 ;
if ( V_455 >= 0 ) {
V_455 <<= 1 ;
if ( V_455 >= ( int ) V_1 -> V_39 -> V_40 . V_453 )
return 0 ;
V_437 += V_455 ;
if ( V_447 )
* V_447 = V_437 [ 0 ] ;
if ( V_465 )
* V_465 = V_437 [ 1 ] ;
F_167 ( V_463 , V_462 , V_464 , V_437 ) ;
}
return V_1 -> V_39 -> V_40 . V_453 / 2 ;
}
int F_175 ( T_1 * V_1 , int V_455 ,
int * V_462 , int * V_463 , int * V_464 ,
unsigned char * V_465 , unsigned char * V_447 )
{
T_22 * V_466 = V_1 -> V_100 -> V_104 ;
if ( ! V_466 || V_455 >= ( int ) V_1 -> V_100 -> V_103 )
return 0 ;
V_466 += V_455 ;
if ( V_463 )
* V_463 = V_466 -> V_425 ;
if ( V_462 )
* V_462 = V_466 -> V_424 ;
if ( V_464 )
* V_464 = V_466 -> V_105 ;
if ( V_465 )
* V_465 = V_466 -> V_448 ;
if ( V_447 )
* V_447 = V_466 -> V_447 ;
return V_1 -> V_100 -> V_103 ;
}
static void F_176 ( int * V_437 , int * V_463 , const char * V_77 )
{
if ( strcmp ( V_77 , L_1 ) == 0 ) {
* V_437 = V_467 ;
} else if ( strcmp ( V_77 , L_2 ) == 0 ) {
* V_437 = V_468 ;
} else if ( strcmp ( V_77 , L_3 ) == 0 ) {
* V_437 = V_97 ;
} else {
* V_463 = F_25 ( V_77 ) ;
if ( * V_463 == V_58 )
* V_463 = F_26 ( V_77 ) ;
}
}
static int F_177 ( const char * V_70 , int V_34 , void * V_71 )
{
T_23 * V_469 = V_71 ;
T_3 V_14 ;
char V_73 [ 20 ] , * V_33 ;
int V_414 = V_58 , V_408 = V_58 ;
if ( V_70 == NULL )
return 0 ;
if ( V_469 -> V_470 == V_471 )
return 0 ;
if ( V_34 > ( int ) ( sizeof( V_73 ) - 1 ) )
return 0 ;
memcpy ( V_73 , V_70 , V_34 ) ;
V_73 [ V_34 ] = 0 ;
V_33 = strchr ( V_73 , '+' ) ;
if ( ! V_33 )
return 0 ;
* V_33 = 0 ;
V_33 ++ ;
if ( ! * V_33 )
return 0 ;
F_176 ( & V_414 , & V_408 , V_73 ) ;
F_176 ( & V_414 , & V_408 , V_33 ) ;
if ( V_414 == V_58 || V_408 == V_58 )
return 0 ;
for ( V_14 = 0 ; V_14 < V_469 -> V_470 ; V_14 += 2 ) {
if ( V_469 -> V_429 [ V_14 ] == V_414 && V_469 -> V_429 [ V_14 + 1 ] == V_408 )
return 0 ;
}
V_469 -> V_429 [ V_469 -> V_470 ++ ] = V_408 ;
V_469 -> V_429 [ V_469 -> V_470 ++ ] = V_414 ;
return 1 ;
}
int F_178 ( T_9 * V_99 , const char * V_77 , int V_472 )
{
T_23 V_116 ;
V_116 . V_470 = 0 ;
if ( ! F_28 ( V_77 , ':' , 1 , F_177 , & V_116 ) )
return 0 ;
if ( V_99 == NULL )
return 1 ;
return F_179 ( V_99 , V_116 . V_429 , V_116 . V_470 , V_472 ) ;
}
int F_179 ( T_9 * V_99 , const int * V_473 , T_3 V_205 , int V_472 )
{
unsigned char * V_429 , * V_474 ;
int V_447 , V_448 ;
T_3 V_14 ;
if ( V_205 & 1 )
return 0 ;
V_429 = F_21 ( V_205 ) ;
if ( V_429 == NULL )
return 0 ;
for ( V_14 = 0 , V_474 = V_429 ; V_14 < V_205 ; V_14 += 2 ) {
V_447 = F_161 ( * V_473 ++ , V_406 , F_10 ( V_406 ) ) ;
V_448 = F_161 ( * V_473 ++ , V_407 , F_10 ( V_407 ) ) ;
if ( V_447 == - 1 || V_448 == - 1 )
goto V_359;
* V_474 ++ = V_447 ;
* V_474 ++ = V_448 ;
}
if ( V_472 ) {
F_5 ( V_99 -> V_110 ) ;
V_99 -> V_110 = V_429 ;
V_99 -> V_111 = V_205 ;
} else {
F_5 ( V_99 -> V_112 ) ;
V_99 -> V_112 = V_429 ;
V_99 -> V_113 = V_205 ;
}
return 1 ;
V_359:
F_5 ( V_429 ) ;
return 0 ;
}
static int F_180 ( T_9 * V_99 , T_7 * V_93 , int V_475 )
{
int V_476 ;
T_3 V_14 ;
if ( V_475 == - 1 )
return 1 ;
V_476 = F_181 ( V_93 ) ;
if ( V_475 )
return V_476 == V_475 ? 1 : 0 ;
for ( V_14 = 0 ; V_14 < V_99 -> V_103 ; V_14 ++ )
if ( V_476 == V_99 -> V_104 [ V_14 ] . V_105 )
return 1 ;
return 0 ;
}
void F_182 ( T_1 * V_1 )
{
F_183 ( V_1 , NULL , NULL , NULL , V_349 ) ;
F_183 ( V_1 , NULL , NULL , NULL , V_347 ) ;
F_183 ( V_1 , NULL , NULL , NULL , V_345 ) ;
F_183 ( V_1 , NULL , NULL , NULL , V_107 ) ;
F_183 ( V_1 , NULL , NULL , NULL , V_350 ) ;
F_183 ( V_1 , NULL , NULL , NULL , V_352 ) ;
F_183 ( V_1 , NULL , NULL , NULL , V_354 ) ;
}
T_24 * F_184 ( T_1 * V_1 )
{
int V_477 = 80 ;
if ( V_1 -> V_100 -> V_478 == 2 )
return F_185 () ;
if ( V_1 -> V_39 -> V_40 . V_41 -> V_145 & ( V_479 | V_138 ) ) {
if ( V_1 -> V_39 -> V_40 . V_41 -> V_150 == 256 )
V_477 = 128 ;
else
V_477 = 80 ;
} else {
T_14 * V_480 = F_139 ( V_1 ) ;
V_477 = F_186 ( V_480 -> V_481 ) ;
}
if ( V_477 >= 128 ) {
T_24 * V_482 = F_187 () ;
T_25 * V_33 , * V_483 ;
if ( V_482 == NULL )
return NULL ;
V_483 = F_188 () ;
if ( V_483 != NULL )
F_189 ( V_483 , 2 ) ;
if ( V_477 >= 192 )
V_33 = F_190 ( NULL ) ;
else
V_33 = F_191 ( NULL ) ;
if ( V_33 == NULL || V_483 == NULL || ! F_192 ( V_482 , V_33 , NULL , V_483 ) ) {
F_193 ( V_482 ) ;
F_194 ( V_33 ) ;
F_194 ( V_483 ) ;
return NULL ;
}
return V_482 ;
}
if ( V_477 >= 112 )
return F_195 () ;
return F_185 () ;
}
static int F_196 ( T_1 * V_1 , T_18 * V_222 , T_7 * V_93 , int V_30 )
{
int V_32 = - 1 ;
T_8 * V_95 = F_37 ( V_93 ) ;
if ( V_95 ) {
V_32 = F_186 ( V_95 ) ;
}
if ( V_1 )
return F_17 ( V_1 , V_30 , V_32 , 0 , V_93 ) ;
else
return F_197 ( V_222 , V_30 , V_32 , 0 , V_93 ) ;
}
static int F_198 ( T_1 * V_1 , T_18 * V_222 , T_7 * V_93 , int V_30 )
{
int V_32 = - 1 , V_484 = V_58 , V_476 ;
if ( ( F_199 ( V_93 ) & V_485 ) != 0 )
return 1 ;
V_476 = F_181 ( V_93 ) ;
if ( V_476 && F_200 ( V_476 , & V_484 , NULL ) ) {
const T_10 * V_106 ;
if ( V_484 && ( V_106 = F_173 ( V_484 ) ) )
V_32 = F_48 ( V_106 ) * 4 ;
}
if ( V_1 )
return F_17 ( V_1 , V_30 , V_32 , V_484 , V_93 ) ;
else
return F_197 ( V_222 , V_30 , V_32 , V_484 , V_93 ) ;
}
int F_201 ( T_1 * V_1 , T_18 * V_222 , T_7 * V_93 , int V_486 , int V_487 )
{
if ( V_486 )
V_486 = V_488 ;
if ( V_487 ) {
if ( ! F_196 ( V_1 , V_222 , V_93 , V_489 | V_486 ) )
return V_490 ;
} else {
if ( ! F_196 ( V_1 , V_222 , V_93 , V_491 | V_486 ) )
return V_492 ;
}
if ( ! F_198 ( V_1 , V_222 , V_93 , V_493 | V_486 ) )
return V_494 ;
return 1 ;
}
