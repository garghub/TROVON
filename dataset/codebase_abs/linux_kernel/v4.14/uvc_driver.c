struct V_1 * F_1 ( struct V_2 * V_3 ,
T_1 V_4 )
{
struct V_1 * V_5 ;
unsigned int V_6 ;
for ( V_6 = 0 ; V_6 < V_3 -> V_7 . V_8 ; ++ V_6 ) {
V_5 = & V_3 -> V_9 [ V_6 ] ;
if ( V_5 -> V_7 . V_10 == V_4 )
return V_5 ;
}
return NULL ;
}
static struct V_11 * F_2 ( const T_1 V_12 [ 16 ] )
{
unsigned int V_13 = F_3 ( V_14 ) ;
unsigned int V_6 ;
for ( V_6 = 0 ; V_6 < V_13 ; ++ V_6 ) {
if ( memcmp ( V_12 , V_14 [ V_6 ] . V_12 , 16 ) == 0 )
return & V_14 [ V_6 ] ;
}
return NULL ;
}
static T_2 F_4 ( const T_1 V_15 )
{
static const T_1 V_16 [] = {
0 ,
V_17 ,
V_18 ,
V_19 ,
V_20 ,
V_21 ,
} ;
if ( V_15 < F_3 ( V_16 ) )
return V_16 [ V_15 ] ;
return 0 ;
}
void F_5 ( T_3 * V_22 , T_3 * V_23 ,
unsigned int V_24 , unsigned int V_25 )
{
T_3 * V_26 ;
T_3 V_27 , V_28 , V_29 ;
unsigned int V_6 , V_30 ;
V_26 = F_6 ( V_24 * sizeof *V_26 , V_31 ) ;
if ( V_26 == NULL )
return;
V_27 = * V_22 ;
V_28 = * V_23 ;
for ( V_30 = 0 ; V_30 < V_24 && V_28 != 0 ; ++ V_30 ) {
V_26 [ V_30 ] = V_27 / V_28 ;
if ( V_26 [ V_30 ] >= V_25 ) {
if ( V_30 < 2 )
V_30 ++ ;
break;
}
V_29 = V_27 - V_26 [ V_30 ] * V_28 ;
V_27 = V_28 ;
V_28 = V_29 ;
}
V_27 = 0 ;
V_28 = 1 ;
for ( V_6 = V_30 ; V_6 > 0 ; -- V_6 ) {
V_29 = V_28 ;
V_28 = V_26 [ V_6 - 1 ] * V_28 + V_27 ;
V_27 = V_29 ;
}
* V_22 = V_28 ;
* V_23 = V_27 ;
F_7 ( V_26 ) ;
}
T_3 F_8 ( T_3 V_22 , T_3 V_23 )
{
T_3 V_32 ;
if ( V_23 == 0 ||
V_22 / V_23 >= ( ( T_3 ) - 1 ) / 10000000 )
return ( T_3 ) - 1 ;
V_32 = 10000000 ;
while ( V_22 > ( ( T_3 ) - 1 ) / V_32 ) {
V_32 /= 2 ;
V_23 /= 2 ;
}
return V_23 ? V_22 * V_32 / V_23 : 0 ;
}
struct V_33 * F_9 ( struct V_34 * V_35 , int V_36 )
{
struct V_33 * V_37 ;
F_10 (entity, &dev->entities, list) {
if ( V_37 -> V_36 == V_36 )
return V_37 ;
}
return NULL ;
}
static struct V_33 * F_11 ( struct V_34 * V_35 ,
int V_36 , struct V_33 * V_37 )
{
unsigned int V_6 ;
if ( V_37 == NULL )
V_37 = F_12 ( & V_35 -> V_38 , struct V_33 , V_39 ) ;
F_13 (entity, &dev->entities, list) {
for ( V_6 = 0 ; V_6 < V_37 -> V_40 ; ++ V_6 )
if ( V_37 -> V_41 [ V_6 ] == V_36 )
return V_37 ;
}
return NULL ;
}
static struct V_42 * F_14 ( struct V_34 * V_35 , int V_36 )
{
struct V_42 * V_43 ;
F_10 (stream, &dev->streams, list) {
if ( V_43 -> V_44 . V_45 == V_36 )
return V_43 ;
}
return NULL ;
}
static int F_15 ( struct V_34 * V_35 ,
struct V_42 * V_46 , struct V_47 * V_48 ,
T_2 * * V_49 , unsigned char * V_50 , int V_51 )
{
struct V_52 * V_53 = V_46 -> V_53 ;
struct V_2 * V_3 = V_53 -> V_54 ;
struct V_11 * V_55 ;
struct V_56 * V_57 ;
const unsigned char * V_58 = V_50 ;
unsigned int V_59 = 1 ;
unsigned int V_60 ;
unsigned int V_6 , V_30 ;
T_1 V_61 ;
V_48 -> type = V_50 [ 2 ] ;
V_48 -> V_62 = V_50 [ 3 ] ;
switch ( V_50 [ 2 ] ) {
case V_63 :
case V_64 :
V_30 = V_50 [ 2 ] == V_63 ? 27 : 28 ;
if ( V_51 < V_30 ) {
F_16 ( V_65 , L_1
L_2 ,
V_35 -> V_66 -> V_67 ,
V_3 -> V_7 . V_68 ) ;
return - V_69 ;
}
V_55 = F_2 ( & V_50 [ 5 ] ) ;
if ( V_55 != NULL ) {
F_17 ( V_48 -> V_70 , V_55 -> V_70 ,
sizeof V_48 -> V_70 ) ;
V_48 -> V_71 = V_55 -> V_71 ;
} else {
F_18 ( V_72 , L_3 ,
& V_50 [ 5 ] ) ;
snprintf ( V_48 -> V_70 , sizeof( V_48 -> V_70 ) , L_4 ,
& V_50 [ 5 ] ) ;
V_48 -> V_71 = 0 ;
}
V_48 -> V_73 = V_50 [ 21 ] ;
if ( V_35 -> V_74 & V_75 ) {
if ( V_48 -> V_71 == V_76 ) {
F_17 ( V_48 -> V_70 , L_5 ,
sizeof( V_48 -> V_70 ) ) ;
V_48 -> V_71 = V_77 ;
V_48 -> V_73 = 8 ;
V_59 = 2 ;
}
}
if ( V_50 [ 2 ] == V_63 ) {
V_61 = V_78 ;
} else {
V_61 = V_79 ;
if ( V_50 [ 27 ] )
V_48 -> V_80 = V_81 ;
}
break;
case V_82 :
if ( V_51 < 11 ) {
F_16 ( V_65 , L_1
L_2 ,
V_35 -> V_66 -> V_67 ,
V_3 -> V_7 . V_68 ) ;
return - V_69 ;
}
F_17 ( V_48 -> V_70 , L_6 , sizeof V_48 -> V_70 ) ;
V_48 -> V_71 = V_83 ;
V_48 -> V_80 = V_81 ;
V_48 -> V_73 = 0 ;
V_61 = V_84 ;
break;
case V_85 :
if ( V_51 < 9 ) {
F_16 ( V_65 , L_1
L_2 ,
V_35 -> V_66 -> V_67 ,
V_3 -> V_7 . V_68 ) ;
return - V_69 ;
}
switch ( V_50 [ 8 ] & 0x7f ) {
case 0 :
F_17 ( V_48 -> V_70 , L_7 , sizeof V_48 -> V_70 ) ;
break;
case 1 :
F_17 ( V_48 -> V_70 , L_8 , sizeof V_48 -> V_70 ) ;
break;
case 2 :
F_17 ( V_48 -> V_70 , L_9 , sizeof V_48 -> V_70 ) ;
break;
default:
F_16 ( V_65 , L_1
L_10 ,
V_35 -> V_66 -> V_67 ,
V_3 -> V_7 . V_68 , V_50 [ 8 ] ) ;
return - V_69 ;
}
F_19 ( V_48 -> V_70 , V_50 [ 8 ] & ( 1 << 7 ) ? L_11 : L_12 ,
sizeof V_48 -> V_70 ) ;
V_48 -> V_71 = V_86 ;
V_48 -> V_80 = V_81 | V_87 ;
V_48 -> V_73 = 0 ;
V_61 = 0 ;
V_57 = & V_48 -> V_57 [ 0 ] ;
memset ( & V_48 -> V_57 [ 0 ] , 0 , sizeof V_48 -> V_57 [ 0 ] ) ;
V_57 -> V_88 = 1 ;
V_57 -> V_89 = 1 ;
V_57 -> V_90 = * V_49 ;
* ( * V_49 ) ++ = 1 ;
V_48 -> V_91 = 1 ;
break;
case V_92 :
case V_93 :
default:
F_16 ( V_65 , L_1
L_13 ,
V_35 -> V_66 -> V_67 , V_3 -> V_7 . V_68 ,
V_50 [ 2 ] ) ;
return - V_69 ;
}
F_16 ( V_65 , L_14 , V_48 -> V_70 ) ;
V_51 -= V_50 [ 0 ] ;
V_50 += V_50 [ 0 ] ;
while ( V_51 > 2 && V_50 [ 1 ] == V_94 &&
V_50 [ 2 ] == V_61 ) {
V_57 = & V_48 -> V_57 [ V_48 -> V_91 ] ;
if ( V_61 != V_79 )
V_30 = V_51 > 25 ? V_50 [ 25 ] : 0 ;
else
V_30 = V_51 > 21 ? V_50 [ 21 ] : 0 ;
V_30 = V_30 ? V_30 : 3 ;
if ( V_51 < 26 + 4 * V_30 ) {
F_16 ( V_65 , L_1
L_15 , V_35 -> V_66 -> V_67 ,
V_3 -> V_7 . V_68 ) ;
return - V_69 ;
}
V_57 -> V_95 = V_50 [ 3 ] ;
V_57 -> V_96 = V_50 [ 4 ] ;
V_57 -> V_97 = F_20 ( & V_50 [ 5 ] )
* V_59 ;
V_57 -> V_98 = F_20 ( & V_50 [ 7 ] ) ;
V_57 -> V_99 = F_21 ( & V_50 [ 9 ] ) ;
V_57 -> V_100 = F_21 ( & V_50 [ 13 ] ) ;
if ( V_61 != V_79 ) {
V_57 -> V_101 =
F_21 ( & V_50 [ 17 ] ) ;
V_57 -> V_89 =
F_21 ( & V_50 [ 21 ] ) ;
V_57 -> V_88 = V_50 [ 25 ] ;
} else {
V_57 -> V_101 = 0 ;
V_57 -> V_89 =
F_21 ( & V_50 [ 17 ] ) ;
V_57 -> V_88 = V_50 [ 21 ] ;
}
V_57 -> V_90 = * V_49 ;
if ( ! ( V_48 -> V_80 & V_81 ) )
V_57 -> V_101 = V_48 -> V_73
* V_57 -> V_97 * V_57 -> V_98 / 8 ;
for ( V_6 = 0 ; V_6 < V_30 ; ++ V_6 ) {
V_60 = F_21 ( & V_50 [ 26 + 4 * V_6 ] ) ;
* ( * V_49 ) ++ = V_60 ? V_60 : 1 ;
}
V_30 -= V_57 -> V_88 ? 1 : 2 ;
V_57 -> V_89 =
F_22 ( V_57 -> V_90 [ V_30 ] ,
F_23 ( V_57 -> V_90 [ 0 ] ,
V_57 -> V_89 ) ) ;
if ( V_35 -> V_74 & V_102 ) {
V_57 -> V_88 = 1 ;
V_57 -> V_90 [ 0 ] =
V_57 -> V_89 ;
}
F_16 ( V_65 , L_16 ,
V_57 -> V_97 , V_57 -> V_98 ,
10000000 / V_57 -> V_89 ,
( 100000000 / V_57 -> V_89 ) % 10 ) ;
V_48 -> V_91 ++ ;
V_51 -= V_50 [ 0 ] ;
V_50 += V_50 [ 0 ] ;
}
if ( V_51 > 2 && V_50 [ 1 ] == V_94 &&
V_50 [ 2 ] == V_103 ) {
V_51 -= V_50 [ 0 ] ;
V_50 += V_50 [ 0 ] ;
}
if ( V_51 > 2 && V_50 [ 1 ] == V_94 &&
V_50 [ 2 ] == V_104 ) {
if ( V_51 < 6 ) {
F_16 ( V_65 , L_1
L_17 ,
V_35 -> V_66 -> V_67 ,
V_3 -> V_7 . V_68 ) ;
return - V_69 ;
}
V_48 -> V_105 = F_4 ( V_50 [ 3 ] ) ;
V_51 -= V_50 [ 0 ] ;
V_50 += V_50 [ 0 ] ;
}
return V_50 - V_58 ;
}
static int F_24 ( struct V_34 * V_35 ,
struct V_52 * V_53 )
{
struct V_42 * V_46 = NULL ;
struct V_47 * V_48 ;
struct V_56 * V_57 ;
struct V_2 * V_3 = & V_53 -> V_106 [ 0 ] ;
unsigned char * V_107 , * V_50 = V_3 -> V_108 ;
int V_109 , V_51 = V_3 -> V_110 ;
unsigned int V_111 = 0 , V_91 = 0 , V_112 = 0 ;
unsigned int V_113 , V_6 , V_30 , V_114 ;
T_2 * V_60 ;
T_4 V_115 ;
int V_116 = - V_69 ;
if ( V_53 -> V_54 -> V_7 . V_117
!= V_118 ) {
F_16 ( V_65 , L_18
L_19 , V_35 -> V_66 -> V_67 ,
V_53 -> V_106 [ 0 ] . V_7 . V_68 ) ;
return - V_69 ;
}
if ( F_25 ( & V_119 . V_120 , V_53 , V_35 ) ) {
F_16 ( V_65 , L_20
L_21 , V_35 -> V_66 -> V_67 ,
V_53 -> V_106 [ 0 ] . V_7 . V_68 ) ;
return - V_69 ;
}
V_46 = F_26 ( sizeof *V_46 , V_31 ) ;
if ( V_46 == NULL ) {
F_27 ( & V_119 . V_120 , V_53 ) ;
return - V_69 ;
}
F_28 ( & V_46 -> V_121 ) ;
V_46 -> V_35 = V_35 ;
V_46 -> V_53 = F_29 ( V_53 ) ;
V_46 -> V_122 = V_53 -> V_54 -> V_7 . V_68 ;
if ( V_51 == 0 ) {
for ( V_6 = 0 ; V_6 < V_3 -> V_7 . V_8 ; ++ V_6 ) {
struct V_1 * V_5 = & V_3 -> V_9 [ V_6 ] ;
if ( V_5 -> V_110 == 0 )
continue;
if ( V_5 -> V_110 > 2 &&
V_5 -> V_108 [ 1 ] == V_94 ) {
F_16 ( V_65 , L_22
L_23 , V_6 ) ;
V_50 = V_3 -> V_9 [ V_6 ] . V_108 ;
V_51 = V_3 -> V_9 [ V_6 ] . V_110 ;
break;
}
}
}
while ( V_51 > 2 && V_50 [ 1 ] != V_94 ) {
V_51 -= V_50 [ 0 ] ;
V_50 += V_50 [ 0 ] ;
}
if ( V_51 <= 2 ) {
F_16 ( V_65 , L_24
L_25 ) ;
goto error;
}
switch ( V_50 [ 2 ] ) {
case V_123 :
V_46 -> type = V_124 ;
V_113 = 9 ;
break;
case V_125 :
V_46 -> type = V_126 ;
V_113 = 13 ;
break;
default:
F_16 ( V_65 , L_26
L_27 , V_35 -> V_66 -> V_67 ,
V_3 -> V_7 . V_68 ) ;
goto error;
}
V_114 = V_51 >= 4 ? V_50 [ 3 ] : 0 ;
V_30 = V_51 >= V_113 ? V_50 [ V_113 - 1 ] : 0 ;
if ( V_51 < V_113 + V_114 * V_30 ) {
F_16 ( V_65 , L_1
L_28 ,
V_35 -> V_66 -> V_67 , V_3 -> V_7 . V_68 ) ;
goto error;
}
V_46 -> V_44 . V_127 = V_114 ;
V_46 -> V_44 . V_10 = V_50 [ 6 ] ;
if ( V_50 [ 2 ] == V_125 ) {
V_46 -> V_44 . V_128 = V_50 [ 7 ] ;
V_46 -> V_44 . V_45 = V_50 [ 8 ] ;
V_46 -> V_44 . V_129 = V_50 [ 9 ] ;
V_46 -> V_44 . V_130 = V_50 [ 10 ] ;
V_46 -> V_44 . V_131 = V_50 [ 11 ] ;
} else {
V_46 -> V_44 . V_45 = V_50 [ 7 ] ;
}
V_46 -> V_44 . V_132 = V_30 ;
V_46 -> V_44 . V_133 = F_30 ( & V_50 [ V_113 ] , V_114 * V_30 ,
V_31 ) ;
if ( V_46 -> V_44 . V_133 == NULL ) {
V_116 = - V_134 ;
goto error;
}
V_51 -= V_50 [ 0 ] ;
V_50 += V_50 [ 0 ] ;
V_107 = V_50 ;
V_109 = V_51 ;
while ( V_109 > 2 && V_107 [ 1 ] == V_94 ) {
switch ( V_107 [ 2 ] ) {
case V_63 :
case V_82 :
case V_64 :
V_111 ++ ;
break;
case V_85 :
V_111 ++ ;
V_91 ++ ;
V_112 ++ ;
break;
case V_92 :
case V_93 :
F_16 ( V_65 , L_1
L_29 ,
V_35 -> V_66 -> V_67 ,
V_3 -> V_7 . V_68 , V_107 [ 2 ] ) ;
break;
case V_78 :
case V_84 :
V_91 ++ ;
if ( V_109 > 25 )
V_112 += V_107 [ 25 ] ? V_107 [ 25 ] : 3 ;
break;
case V_79 :
V_91 ++ ;
if ( V_109 > 21 )
V_112 += V_107 [ 21 ] ? V_107 [ 21 ] : 3 ;
break;
}
V_109 -= V_107 [ 0 ] ;
V_107 += V_107 [ 0 ] ;
}
if ( V_111 == 0 ) {
F_16 ( V_65 , L_26
L_30 ,
V_35 -> V_66 -> V_67 , V_3 -> V_7 . V_68 ) ;
goto error;
}
V_113 = V_111 * sizeof *V_48 + V_91 * sizeof *V_57
+ V_112 * sizeof *V_60 ;
V_48 = F_26 ( V_113 , V_31 ) ;
if ( V_48 == NULL ) {
V_116 = - V_134 ;
goto error;
}
V_57 = (struct V_56 * ) & V_48 [ V_111 ] ;
V_60 = ( T_2 * ) & V_57 [ V_91 ] ;
V_46 -> V_48 = V_48 ;
V_46 -> V_111 = V_111 ;
while ( V_51 > 2 && V_50 [ 1 ] == V_94 ) {
switch ( V_50 [ 2 ] ) {
case V_63 :
case V_82 :
case V_85 :
case V_64 :
V_48 -> V_57 = V_57 ;
V_116 = F_15 ( V_35 , V_46 , V_48 ,
& V_60 , V_50 , V_51 ) ;
if ( V_116 < 0 )
goto error;
V_57 += V_48 -> V_91 ;
V_48 ++ ;
V_51 -= V_116 ;
V_50 += V_116 ;
continue;
default:
break;
}
V_51 -= V_50 [ 0 ] ;
V_50 += V_50 [ 0 ] ;
}
if ( V_51 )
F_16 ( V_65 , L_26
L_31 ,
V_35 -> V_66 -> V_67 , V_3 -> V_7 . V_68 , V_51 ) ;
for ( V_6 = 0 ; V_6 < V_53 -> V_135 ; ++ V_6 ) {
struct V_1 * V_5 ;
V_3 = & V_53 -> V_106 [ V_6 ] ;
V_5 = F_1 ( V_3 ,
V_46 -> V_44 . V_10 ) ;
if ( V_5 == NULL )
continue;
V_115 = F_31 ( V_5 -> V_7 . V_136 ) ;
V_115 = ( V_115 & 0x07ff ) * ( 1 + ( ( V_115 >> 11 ) & 3 ) ) ;
if ( V_115 > V_46 -> V_137 )
V_46 -> V_137 = V_115 ;
}
F_32 ( & V_46 -> V_39 , & V_35 -> V_138 ) ;
return 0 ;
error:
F_27 ( & V_119 . V_120 , V_53 ) ;
F_33 ( V_53 ) ;
F_7 ( V_46 -> V_48 ) ;
F_7 ( V_46 -> V_44 . V_133 ) ;
F_7 ( V_46 ) ;
return V_116 ;
}
static struct V_33 * F_34 ( T_5 type , T_6 V_36 ,
unsigned int V_139 , unsigned int V_140 )
{
struct V_33 * V_37 ;
unsigned int V_141 ;
unsigned int V_113 ;
unsigned int V_6 ;
V_140 = F_35 ( V_140 , sizeof( * V_37 -> V_142 ) ) ;
V_141 = ( type & V_143 ) ? V_139 : V_139 - 1 ;
V_113 = sizeof( * V_37 ) + V_140 + sizeof( * V_37 -> V_142 ) * V_139
+ V_141 ;
V_37 = F_26 ( V_113 , V_31 ) ;
if ( V_37 == NULL )
return NULL ;
V_37 -> V_36 = V_36 ;
V_37 -> type = type ;
V_37 -> V_144 = 0 ;
V_37 -> V_139 = V_139 ;
V_37 -> V_142 = ( ( void * ) ( V_37 + 1 ) ) + V_140 ;
for ( V_6 = 0 ; V_6 < V_141 ; ++ V_6 )
V_37 -> V_142 [ V_6 ] . V_80 = V_145 ;
if ( ! F_36 ( V_37 ) )
V_37 -> V_142 [ V_139 - 1 ] . V_80 = V_146 ;
V_37 -> V_40 = V_141 ;
V_37 -> V_41 = ( T_1 * ) ( & V_37 -> V_142 [ V_139 ] ) ;
return V_37 ;
}
static int F_37 ( struct V_34 * V_35 ,
const unsigned char * V_50 , int V_51 )
{
struct V_147 * V_66 = V_35 -> V_66 ;
struct V_2 * V_3 = V_35 -> V_53 -> V_54 ;
struct V_33 * V_148 ;
unsigned int V_30 , V_114 ;
int V_149 = 0 ;
switch ( F_31 ( V_35 -> V_66 -> V_150 . V_151 ) ) {
case 0x046d :
if ( V_50 [ 1 ] != 0x41 || V_50 [ 2 ] != 0x01 )
break;
V_114 = V_51 >= 22 ? V_50 [ 21 ] : 0 ;
V_30 = V_51 >= 25 + V_114 ? V_50 [ 22 + V_114 ] : 0 ;
if ( V_51 < 25 + V_114 + 2 * V_30 ) {
F_16 ( V_65 , L_32
L_33 ,
V_66 -> V_67 , V_3 -> V_7 . V_68 ) ;
break;
}
V_148 = F_34 ( V_152 , V_50 [ 3 ] ,
V_114 + 1 , 2 * V_30 ) ;
if ( V_148 == NULL )
return - V_134 ;
memcpy ( V_148 -> V_153 . V_154 , & V_50 [ 4 ] , 16 ) ;
V_148 -> V_153 . V_155 = V_50 [ 20 ] ;
memcpy ( V_148 -> V_41 , & V_50 [ 22 ] , V_114 ) ;
V_148 -> V_153 . V_132 = V_50 [ 22 + V_114 ] ;
V_148 -> V_153 . V_156 = ( T_1 * ) V_148 + sizeof( * V_148 ) ;
V_148 -> V_153 . V_157 = ( T_1 * ) V_148 + sizeof( * V_148 )
+ V_30 ;
memcpy ( V_148 -> V_153 . V_156 , & V_50 [ 23 + V_114 ] , 2 * V_30 ) ;
if ( V_50 [ 24 + V_114 + 2 * V_30 ] != 0 )
F_38 ( V_66 , V_50 [ 24 + V_114 + 2 * V_30 ] , V_148 -> V_70 ,
sizeof V_148 -> V_70 ) ;
else
sprintf ( V_148 -> V_70 , L_34 , V_50 [ 3 ] ) ;
F_32 ( & V_148 -> V_39 , & V_35 -> V_38 ) ;
V_149 = 1 ;
break;
}
return V_149 ;
}
static int F_39 ( struct V_34 * V_35 ,
const unsigned char * V_50 , int V_51 )
{
struct V_147 * V_66 = V_35 -> V_66 ;
struct V_33 * V_148 , * V_158 ;
struct V_52 * V_53 ;
struct V_2 * V_3 = V_35 -> V_53 -> V_54 ;
unsigned int V_6 , V_30 , V_114 , V_13 ;
T_4 type ;
switch ( V_50 [ 2 ] ) {
case V_159 :
V_30 = V_51 >= 12 ? V_50 [ 11 ] : 0 ;
if ( V_51 < 12 + V_30 ) {
F_16 ( V_65 , L_32
L_35 , V_66 -> V_67 ,
V_3 -> V_7 . V_68 ) ;
return - V_69 ;
}
V_35 -> V_160 = F_20 ( & V_50 [ 3 ] ) ;
V_35 -> V_161 = F_21 ( & V_50 [ 7 ] ) ;
for ( V_6 = 0 ; V_6 < V_30 ; ++ V_6 ) {
V_53 = F_40 ( V_66 , V_50 [ 12 + V_6 ] ) ;
if ( V_53 == NULL ) {
F_16 ( V_65 , L_36
L_37 ,
V_66 -> V_67 , V_6 ) ;
continue;
}
F_24 ( V_35 , V_53 ) ;
}
break;
case V_162 :
if ( V_51 < 8 ) {
F_16 ( V_65 , L_32
L_38 ,
V_66 -> V_67 , V_3 -> V_7 . V_68 ) ;
return - V_69 ;
}
type = F_20 ( & V_50 [ 4 ] ) ;
if ( ( type & 0xff00 ) == 0 ) {
F_16 ( V_65 , L_32
L_39
L_40 , V_66 -> V_67 ,
V_3 -> V_7 . V_68 ,
V_50 [ 3 ] , type ) ;
return 0 ;
}
V_30 = 0 ;
V_114 = 0 ;
V_13 = 8 ;
if ( type == V_163 ) {
V_30 = V_51 >= 15 ? V_50 [ 14 ] : 0 ;
V_13 = 15 ;
} else if ( type == V_164 ) {
V_30 = V_51 >= 9 ? V_50 [ 8 ] : 0 ;
V_114 = V_51 >= 10 + V_30 ? V_50 [ 9 + V_30 ] : 0 ;
V_13 = 10 ;
}
if ( V_51 < V_13 + V_30 + V_114 ) {
F_16 ( V_65 , L_32
L_38 ,
V_66 -> V_67 , V_3 -> V_7 . V_68 ) ;
return - V_69 ;
}
V_158 = F_34 ( type | V_165 , V_50 [ 3 ] ,
1 , V_30 + V_114 ) ;
if ( V_158 == NULL )
return - V_134 ;
if ( F_41 ( V_158 ) == V_163 ) {
V_158 -> V_166 . V_132 = V_30 ;
V_158 -> V_166 . V_156 = ( T_1 * ) V_158 + sizeof *V_158 ;
V_158 -> V_166 . V_167 =
F_20 ( & V_50 [ 8 ] ) ;
V_158 -> V_166 . V_168 =
F_20 ( & V_50 [ 10 ] ) ;
V_158 -> V_166 . V_169 =
F_20 ( & V_50 [ 12 ] ) ;
memcpy ( V_158 -> V_166 . V_156 , & V_50 [ 15 ] , V_30 ) ;
} else if ( F_41 ( V_158 ) ==
V_164 ) {
V_158 -> V_170 . V_132 = V_30 ;
V_158 -> V_170 . V_156 = ( T_1 * ) V_158 + sizeof *V_158 ;
V_158 -> V_170 . V_171 = V_114 ;
V_158 -> V_170 . V_172 = ( T_1 * ) V_158
+ sizeof *V_158 + V_30 ;
memcpy ( V_158 -> V_170 . V_156 , & V_50 [ 9 ] , V_30 ) ;
memcpy ( V_158 -> V_170 . V_172 , & V_50 [ 10 + V_30 ] , V_114 ) ;
}
if ( V_50 [ 7 ] != 0 )
F_38 ( V_66 , V_50 [ 7 ] , V_158 -> V_70 ,
sizeof V_158 -> V_70 ) ;
else if ( F_41 ( V_158 ) == V_163 )
sprintf ( V_158 -> V_70 , L_41 , V_50 [ 3 ] ) ;
else if ( F_41 ( V_158 ) == V_164 )
sprintf ( V_158 -> V_70 , L_42 , V_50 [ 3 ] ) ;
else
sprintf ( V_158 -> V_70 , L_43 , V_50 [ 3 ] ) ;
F_32 ( & V_158 -> V_39 , & V_35 -> V_38 ) ;
break;
case V_173 :
if ( V_51 < 9 ) {
F_16 ( V_65 , L_32
L_44 ,
V_66 -> V_67 , V_3 -> V_7 . V_68 ) ;
return - V_69 ;
}
type = F_20 ( & V_50 [ 4 ] ) ;
if ( ( type & 0xff00 ) == 0 ) {
F_16 ( V_65 , L_32
L_45
L_40 , V_66 -> V_67 ,
V_3 -> V_7 . V_68 , V_50 [ 3 ] , type ) ;
return 0 ;
}
V_158 = F_34 ( type | V_143 , V_50 [ 3 ] ,
1 , 0 ) ;
if ( V_158 == NULL )
return - V_134 ;
memcpy ( V_158 -> V_41 , & V_50 [ 7 ] , 1 ) ;
if ( V_50 [ 8 ] != 0 )
F_38 ( V_66 , V_50 [ 8 ] , V_158 -> V_70 ,
sizeof V_158 -> V_70 ) ;
else
sprintf ( V_158 -> V_70 , L_46 , V_50 [ 3 ] ) ;
F_32 ( & V_158 -> V_39 , & V_35 -> V_38 ) ;
break;
case V_174 :
V_114 = V_51 >= 5 ? V_50 [ 4 ] : 0 ;
if ( V_51 < 5 || V_51 < 6 + V_114 ) {
F_16 ( V_65 , L_32
L_47 ,
V_66 -> V_67 , V_3 -> V_7 . V_68 ) ;
return - V_69 ;
}
V_148 = F_34 ( V_50 [ 2 ] , V_50 [ 3 ] , V_114 + 1 , 0 ) ;
if ( V_148 == NULL )
return - V_134 ;
memcpy ( V_148 -> V_41 , & V_50 [ 5 ] , V_114 ) ;
if ( V_50 [ 5 + V_114 ] != 0 )
F_38 ( V_66 , V_50 [ 5 + V_114 ] , V_148 -> V_70 ,
sizeof V_148 -> V_70 ) ;
else
sprintf ( V_148 -> V_70 , L_48 , V_50 [ 3 ] ) ;
F_32 ( & V_148 -> V_39 , & V_35 -> V_38 ) ;
break;
case V_175 :
V_30 = V_51 >= 8 ? V_50 [ 7 ] : 0 ;
V_114 = V_35 -> V_160 >= 0x0110 ? 10 : 9 ;
if ( V_51 < V_114 + V_30 ) {
F_16 ( V_65 , L_32
L_49 ,
V_66 -> V_67 , V_3 -> V_7 . V_68 ) ;
return - V_69 ;
}
V_148 = F_34 ( V_50 [ 2 ] , V_50 [ 3 ] , 2 , V_30 ) ;
if ( V_148 == NULL )
return - V_134 ;
memcpy ( V_148 -> V_41 , & V_50 [ 4 ] , 1 ) ;
V_148 -> V_176 . V_177 =
F_20 ( & V_50 [ 5 ] ) ;
V_148 -> V_176 . V_132 = V_50 [ 7 ] ;
V_148 -> V_176 . V_156 = ( T_1 * ) V_148 + sizeof *V_148 ;
memcpy ( V_148 -> V_176 . V_156 , & V_50 [ 8 ] , V_30 ) ;
if ( V_35 -> V_160 >= 0x0110 )
V_148 -> V_176 . V_178 = V_50 [ 9 + V_30 ] ;
if ( V_50 [ 8 + V_30 ] != 0 )
F_38 ( V_66 , V_50 [ 8 + V_30 ] , V_148 -> V_70 ,
sizeof V_148 -> V_70 ) ;
else
sprintf ( V_148 -> V_70 , L_50 , V_50 [ 3 ] ) ;
F_32 ( & V_148 -> V_39 , & V_35 -> V_38 ) ;
break;
case V_152 :
V_114 = V_51 >= 22 ? V_50 [ 21 ] : 0 ;
V_30 = V_51 >= 24 + V_114 ? V_50 [ 22 + V_114 ] : 0 ;
if ( V_51 < 24 + V_114 + V_30 ) {
F_16 ( V_65 , L_32
L_33 ,
V_66 -> V_67 , V_3 -> V_7 . V_68 ) ;
return - V_69 ;
}
V_148 = F_34 ( V_50 [ 2 ] , V_50 [ 3 ] , V_114 + 1 , V_30 ) ;
if ( V_148 == NULL )
return - V_134 ;
memcpy ( V_148 -> V_153 . V_154 , & V_50 [ 4 ] , 16 ) ;
V_148 -> V_153 . V_155 = V_50 [ 20 ] ;
memcpy ( V_148 -> V_41 , & V_50 [ 22 ] , V_114 ) ;
V_148 -> V_153 . V_132 = V_50 [ 22 + V_114 ] ;
V_148 -> V_153 . V_156 = ( T_1 * ) V_148 + sizeof *V_148 ;
memcpy ( V_148 -> V_153 . V_156 , & V_50 [ 23 + V_114 ] , V_30 ) ;
if ( V_50 [ 23 + V_114 + V_30 ] != 0 )
F_38 ( V_66 , V_50 [ 23 + V_114 + V_30 ] , V_148 -> V_70 ,
sizeof V_148 -> V_70 ) ;
else
sprintf ( V_148 -> V_70 , L_34 , V_50 [ 3 ] ) ;
F_32 ( & V_148 -> V_39 , & V_35 -> V_38 ) ;
break;
default:
F_16 ( V_65 , L_51
L_52 , V_50 [ 2 ] ) ;
break;
}
return 0 ;
}
static int F_42 ( struct V_34 * V_35 )
{
struct V_2 * V_3 = V_35 -> V_53 -> V_54 ;
unsigned char * V_50 = V_3 -> V_108 ;
int V_51 = V_3 -> V_110 ;
int V_116 ;
while ( V_51 > 2 ) {
if ( F_37 ( V_35 , V_50 , V_51 ) ||
V_50 [ 1 ] != V_94 )
goto V_179;
if ( ( V_116 = F_39 ( V_35 , V_50 , V_51 ) ) < 0 )
return V_116 ;
V_179:
V_51 -= V_50 [ 0 ] ;
V_50 += V_50 [ 0 ] ;
}
if ( V_3 -> V_7 . V_8 == 1 &&
! ( V_35 -> V_74 & V_180 ) ) {
struct V_1 * V_5 = & V_3 -> V_9 [ 0 ] ;
struct V_181 * V_7 = & V_5 -> V_7 ;
if ( F_43 ( V_7 ) &&
F_31 ( V_7 -> V_136 ) >= 8 &&
V_7 -> V_182 != 0 ) {
F_16 ( V_65 , L_53
L_54 , V_7 -> V_10 ) ;
V_35 -> V_183 = V_5 ;
}
}
return 0 ;
}
static int F_44 ( struct V_184 * V_185 ,
struct V_33 * V_37 )
{
switch ( F_41 ( V_37 ) ) {
case V_152 :
if ( V_186 & V_187 )
F_45 ( V_188 L_55 , V_37 -> V_36 ) ;
if ( V_37 -> V_40 != 1 ) {
F_16 ( V_65 , L_56
L_57 , V_37 -> V_36 ) ;
return - 1 ;
}
break;
case V_175 :
if ( V_186 & V_187 )
F_45 ( V_188 L_58 , V_37 -> V_36 ) ;
if ( V_185 -> V_176 != NULL ) {
F_16 ( V_65 , L_59
L_60 ) ;
return - 1 ;
}
V_185 -> V_176 = V_37 ;
break;
case V_174 :
if ( V_186 & V_187 )
F_45 ( V_188 L_61 , V_37 -> V_36 ) ;
if ( V_37 -> V_40 == 1 )
break;
if ( V_185 -> V_189 != NULL ) {
F_16 ( V_65 , L_62
L_63 ) ;
return - 1 ;
}
V_185 -> V_189 = V_37 ;
break;
case V_190 :
case V_163 :
case V_164 :
if ( V_186 & V_187 )
F_45 ( V_188 L_64 , V_37 -> V_36 ) ;
break;
case V_191 :
case V_192 :
case V_193 :
if ( V_186 & V_187 )
F_45 ( V_188 L_65 , V_37 -> V_36 ) ;
break;
case V_194 :
if ( F_46 ( V_37 ) ) {
if ( V_186 & V_187 )
F_45 ( V_188 L_64 , V_37 -> V_36 ) ;
} else {
if ( V_186 & V_187 )
F_45 ( V_188 L_65 , V_37 -> V_36 ) ;
}
break;
default:
F_16 ( V_65 , L_66
L_67 , F_41 ( V_37 ) ) ;
return - 1 ;
}
F_32 ( & V_37 -> V_185 , & V_185 -> V_38 ) ;
return 0 ;
}
static int F_47 ( struct V_184 * V_185 ,
struct V_33 * V_37 , struct V_33 * V_195 )
{
struct V_33 * V_196 ;
int V_197 ;
V_196 = NULL ;
V_197 = 0 ;
while ( 1 ) {
V_196 = F_11 ( V_185 -> V_35 , V_37 -> V_36 ,
V_196 ) ;
if ( V_196 == NULL )
break;
if ( V_196 == V_195 )
continue;
switch ( F_41 ( V_196 ) ) {
case V_152 :
if ( V_196 -> V_40 != 1 ) {
F_16 ( V_65 , L_68
L_69 ,
V_37 -> V_36 ) ;
return - V_69 ;
}
F_32 ( & V_196 -> V_185 , & V_185 -> V_38 ) ;
if ( V_186 & V_187 ) {
if ( ! V_197 )
F_45 ( V_188 L_70 ) ;
F_45 ( V_188 L_71 , V_196 -> V_36 ) ;
V_197 = 1 ;
}
break;
case V_191 :
case V_192 :
case V_193 :
case V_194 :
if ( F_46 ( V_196 ) ) {
F_16 ( V_65 , L_72
L_73 , V_196 -> V_36 ) ;
return - V_69 ;
}
F_32 ( & V_196 -> V_185 , & V_185 -> V_38 ) ;
if ( V_186 & V_187 ) {
if ( ! V_197 )
F_45 ( V_188 L_70 ) ;
F_45 ( V_188 L_65 , V_196 -> V_36 ) ;
V_197 = 1 ;
}
break;
}
}
if ( V_197 )
F_45 ( V_188 L_74 ) ;
return 0 ;
}
static int F_48 ( struct V_184 * V_185 ,
struct V_33 * * V_198 )
{
struct V_33 * V_37 = * V_198 ;
struct V_33 * V_158 ;
int V_36 = - V_69 , V_6 ;
switch ( F_41 ( V_37 ) ) {
case V_152 :
case V_175 :
V_36 = V_37 -> V_41 [ 0 ] ;
break;
case V_174 :
if ( V_37 -> V_40 == 1 ) {
V_36 = V_37 -> V_41 [ 0 ] ;
break;
}
if ( V_186 & V_187 )
F_45 ( V_188 L_75 ) ;
V_185 -> V_189 = V_37 ;
for ( V_6 = 0 ; V_6 < V_37 -> V_40 ; ++ V_6 ) {
V_36 = V_37 -> V_41 [ V_6 ] ;
V_158 = F_9 ( V_185 -> V_35 , V_36 ) ;
if ( V_158 == NULL || ! F_46 ( V_158 ) ) {
F_16 ( V_65 , L_76
L_77
L_78 , V_37 -> V_36 , V_6 ) ;
return - 1 ;
}
if ( V_186 & V_187 )
F_45 ( V_188 L_79 , V_158 -> V_36 ) ;
F_32 ( & V_158 -> V_185 , & V_185 -> V_38 ) ;
F_47 ( V_185 , V_158 , V_37 ) ;
}
if ( V_186 & V_187 )
F_45 ( V_188 L_80 ) ;
V_36 = 0 ;
break;
case V_190 :
case V_163 :
case V_164 :
case V_191 :
case V_192 :
case V_193 :
case V_194 :
V_36 = F_36 ( V_37 ) ? V_37 -> V_41 [ 0 ] : 0 ;
break;
}
if ( V_36 <= 0 ) {
* V_198 = NULL ;
return V_36 ;
}
V_37 = F_9 ( V_185 -> V_35 , V_36 ) ;
if ( V_37 == NULL ) {
F_16 ( V_65 , L_81
L_82 , V_36 ) ;
return - V_69 ;
}
* V_198 = V_37 ;
return 0 ;
}
static int F_49 ( struct V_184 * V_185 ,
struct V_33 * V_158 )
{
struct V_33 * V_37 , * V_195 ;
F_16 ( V_187 , L_83 ) ;
V_37 = V_158 ;
V_195 = NULL ;
while ( V_37 != NULL ) {
if ( V_37 -> V_185 . V_199 || V_37 -> V_185 . V_195 ) {
F_16 ( V_65 , L_81
L_84 , V_37 -> V_36 ) ;
return - V_69 ;
}
if ( F_44 ( V_185 , V_37 ) < 0 )
return - V_69 ;
if ( F_47 ( V_185 , V_37 , V_195 ) < 0 )
return - V_69 ;
V_195 = V_37 ;
if ( F_48 ( V_185 , & V_37 ) < 0 )
return - V_69 ;
}
return 0 ;
}
static unsigned int F_50 ( struct V_200 * V_201 , T_5 V_202 ,
char * V_50 )
{
struct V_33 * V_158 ;
unsigned int V_203 = 0 ;
char * V_114 = V_50 ;
F_10 (term, terms, chain) {
if ( ! F_51 ( V_158 ) ||
F_52 ( V_158 ) != V_202 )
continue;
if ( V_203 )
V_114 += sprintf ( V_114 , L_85 ) ;
if ( ++ V_203 >= 4 ) {
V_114 += sprintf ( V_114 , L_86 ) ;
break;
}
V_114 += sprintf ( V_114 , L_87 , V_158 -> V_36 ) ;
}
return V_114 - V_50 ;
}
static const char * F_53 ( struct V_184 * V_185 )
{
static char V_50 [ 43 ] ;
char * V_114 = V_50 ;
V_114 += F_50 ( & V_185 -> V_38 , V_165 , V_114 ) ;
V_114 += sprintf ( V_114 , L_88 ) ;
F_50 ( & V_185 -> V_38 , V_143 , V_114 ) ;
return V_50 ;
}
static struct V_184 * F_54 ( struct V_34 * V_35 )
{
struct V_184 * V_185 ;
V_185 = F_26 ( sizeof( * V_185 ) , V_31 ) ;
if ( V_185 == NULL )
return NULL ;
F_55 ( & V_185 -> V_38 ) ;
F_28 ( & V_185 -> V_204 ) ;
V_185 -> V_35 = V_35 ;
F_56 ( & V_185 -> V_205 ) ;
return V_185 ;
}
static int F_57 ( struct V_34 * V_35 )
{
struct V_184 * V_185 ;
struct V_33 * V_206 = NULL ;
struct V_33 * V_207 = NULL ;
struct V_33 * V_37 ;
struct V_33 * V_195 ;
F_10 (entity, &dev->entities, list) {
if ( F_46 ( V_37 ) ) {
if ( V_206 )
return - V_69 ;
V_206 = V_37 ;
}
if ( F_36 ( V_37 ) ) {
if ( V_207 )
return - V_69 ;
V_207 = V_37 ;
}
}
if ( V_206 == NULL || V_207 == NULL )
return - V_69 ;
V_185 = F_54 ( V_35 ) ;
if ( V_185 == NULL )
return - V_134 ;
if ( F_44 ( V_185 , V_207 ) < 0 )
goto error;
V_195 = V_207 ;
F_58 (entity, &dev->entities, list) {
if ( V_37 -> type != V_175 &&
V_37 -> type != V_152 )
continue;
if ( V_37 -> V_139 != 2 )
continue;
if ( F_44 ( V_185 , V_37 ) < 0 )
goto error;
V_195 -> V_41 [ 0 ] = V_37 -> V_36 ;
V_195 = V_37 ;
}
if ( F_44 ( V_185 , V_206 ) < 0 )
goto error;
V_195 -> V_41 [ 0 ] = V_206 -> V_36 ;
F_32 ( & V_185 -> V_39 , & V_35 -> V_208 ) ;
F_16 ( V_187 ,
L_89 ,
F_53 ( V_185 ) ) ;
return 0 ;
error:
F_7 ( V_185 ) ;
return - V_69 ;
}
static int F_59 ( struct V_34 * V_35 )
{
struct V_184 * V_185 ;
struct V_33 * V_158 ;
F_10 (term, &dev->entities, list) {
if ( ! F_36 ( V_158 ) )
continue;
if ( V_158 -> V_185 . V_199 || V_158 -> V_185 . V_195 )
continue;
V_185 = F_54 ( V_35 ) ;
if ( V_185 == NULL )
return - V_134 ;
V_158 -> V_80 |= V_209 ;
if ( F_49 ( V_185 , V_158 ) < 0 ) {
F_7 ( V_185 ) ;
continue;
}
F_16 ( V_187 , L_90 ,
F_53 ( V_185 ) ) ;
F_32 ( & V_185 -> V_39 , & V_35 -> V_208 ) ;
}
if ( F_60 ( & V_35 -> V_208 ) )
F_57 ( V_35 ) ;
if ( F_60 ( & V_35 -> V_208 ) ) {
F_18 ( V_72 , L_91 ) ;
return - 1 ;
}
return 0 ;
}
static void F_61 ( struct V_210 * V_210 )
{
struct V_34 * V_35 = F_62 ( V_210 , struct V_34 , V_211 ) ;
struct V_200 * V_114 , * V_30 ;
F_63 ( V_35 ) ;
F_64 ( V_35 ) ;
F_33 ( V_35 -> V_53 ) ;
F_65 ( V_35 -> V_66 ) ;
if ( V_35 -> V_212 . V_35 )
F_66 ( & V_35 -> V_212 ) ;
#ifdef F_67
if ( F_68 ( V_35 -> V_213 . V_214 ) )
F_69 ( & V_35 -> V_213 ) ;
F_70 ( & V_35 -> V_213 ) ;
#endif
F_71 (p, n, &dev->chains) {
struct V_184 * V_185 ;
V_185 = F_12 ( V_114 , struct V_184 , V_39 ) ;
F_7 ( V_185 ) ;
}
F_71 (p, n, &dev->entities) {
struct V_33 * V_37 ;
V_37 = F_12 ( V_114 , struct V_33 , V_39 ) ;
#ifdef F_67
F_72 ( V_37 ) ;
#endif
F_7 ( V_37 ) ;
}
F_71 (p, n, &dev->streams) {
struct V_42 * V_46 ;
V_46 = F_12 ( V_114 , struct V_42 , V_39 ) ;
F_27 ( & V_119 . V_120 ,
V_46 -> V_53 ) ;
F_33 ( V_46 -> V_53 ) ;
F_7 ( V_46 -> V_48 ) ;
F_7 ( V_46 -> V_44 . V_133 ) ;
F_7 ( V_46 ) ;
}
F_7 ( V_35 ) ;
}
static void F_73 ( struct V_215 * V_212 )
{
struct V_42 * V_43 = F_74 ( V_212 ) ;
struct V_34 * V_35 = V_43 -> V_35 ;
F_75 ( & V_35 -> V_211 , F_61 ) ;
}
static void F_76 ( struct V_34 * V_35 )
{
struct V_42 * V_43 ;
F_77 ( & V_35 -> V_211 ) ;
F_10 (stream, &dev->streams, list) {
if ( ! F_78 ( & V_43 -> V_212 ) )
continue;
F_79 ( & V_43 -> V_212 ) ;
F_80 ( V_43 ) ;
}
F_75 ( & V_35 -> V_211 , F_61 ) ;
}
static int F_81 ( struct V_34 * V_35 ,
struct V_42 * V_43 )
{
struct V_215 * V_212 = & V_43 -> V_212 ;
int V_116 ;
V_116 = F_82 ( & V_43 -> V_216 , V_43 -> type , ! V_217 ) ;
if ( V_116 )
return V_116 ;
V_116 = F_83 ( V_43 ) ;
if ( V_116 < 0 ) {
F_18 ( V_218 , L_92
L_93 , V_116 ) ;
return V_116 ;
}
F_84 ( V_43 ) ;
V_212 -> V_219 = & V_35 -> V_212 ;
V_212 -> V_220 = & V_221 ;
V_212 -> V_222 = & V_223 ;
V_212 -> V_224 = F_73 ;
V_212 -> V_205 = & V_43 -> V_185 -> V_205 ;
if ( V_43 -> type == V_124 )
V_212 -> V_225 = V_226 ;
F_17 ( V_212 -> V_70 , V_35 -> V_70 , sizeof V_212 -> V_70 ) ;
F_85 ( V_212 , V_43 ) ;
V_116 = F_86 ( V_212 , V_227 , - 1 ) ;
if ( V_116 < 0 ) {
F_18 ( V_218 , L_94 ,
V_116 ) ;
return V_116 ;
}
if ( V_43 -> type == V_126 )
V_43 -> V_185 -> V_228 |= V_229 ;
else
V_43 -> V_185 -> V_228 |= V_230 ;
F_77 ( & V_35 -> V_211 ) ;
return 0 ;
}
static int F_87 ( struct V_34 * V_35 ,
struct V_184 * V_185 )
{
struct V_42 * V_43 ;
struct V_33 * V_158 ;
int V_116 ;
F_10 (term, &chain->entities, chain) {
if ( F_41 ( V_158 ) != V_194 )
continue;
V_43 = F_14 ( V_35 , V_158 -> V_36 ) ;
if ( V_43 == NULL ) {
F_18 ( V_72 , L_95
L_96 , V_158 -> V_36 ) ;
continue;
}
V_43 -> V_185 = V_185 ;
V_116 = F_81 ( V_35 , V_43 ) ;
if ( V_116 < 0 )
return V_116 ;
V_158 -> V_212 = & V_43 -> V_212 ;
}
return 0 ;
}
static int F_88 ( struct V_34 * V_35 )
{
struct V_184 * V_185 ;
int V_116 ;
F_10 (chain, &dev->chains, list) {
V_116 = F_87 ( V_35 , V_185 ) ;
if ( V_116 < 0 )
return V_116 ;
#ifdef F_67
V_116 = F_89 ( V_185 ) ;
if ( V_116 < 0 ) {
F_18 ( V_72 , L_97
L_93 , V_116 ) ;
}
#endif
}
return 0 ;
}
static int F_90 ( struct V_52 * V_53 ,
const struct V_231 * V_36 )
{
struct V_147 * V_66 = F_91 ( V_53 ) ;
struct V_34 * V_35 ;
int V_232 ;
int V_116 ;
if ( V_36 -> V_151 && V_36 -> V_233 )
F_16 ( V_187 , L_98
L_99 , V_66 -> V_234 , V_36 -> V_151 ,
V_36 -> V_233 ) ;
else
F_16 ( V_187 , L_100 ,
V_66 -> V_234 ) ;
if ( ( V_35 = F_26 ( sizeof *V_35 , V_31 ) ) == NULL )
return - V_134 ;
F_55 ( & V_35 -> V_38 ) ;
F_55 ( & V_35 -> V_208 ) ;
F_55 ( & V_35 -> V_138 ) ;
F_92 ( & V_35 -> V_211 ) ;
F_93 ( & V_35 -> V_235 , 0 ) ;
F_28 ( & V_35 -> V_236 ) ;
V_35 -> V_66 = F_94 ( V_66 ) ;
V_35 -> V_53 = F_29 ( V_53 ) ;
V_35 -> V_122 = V_53 -> V_54 -> V_7 . V_68 ;
V_35 -> V_74 = ( V_237 == - 1 )
? V_36 -> V_238 : V_237 ;
if ( V_66 -> V_239 != NULL )
F_17 ( V_35 -> V_70 , V_66 -> V_239 , sizeof V_35 -> V_70 ) ;
else
snprintf ( V_35 -> V_70 , sizeof V_35 -> V_70 ,
L_101 ,
F_31 ( V_66 -> V_150 . V_151 ) ,
F_31 ( V_66 -> V_150 . V_233 ) ) ;
if ( V_53 -> V_240 && V_53 -> V_240 -> V_241 != 0 )
V_232 = V_53 -> V_240 -> V_241 ;
else
V_232 = V_53 -> V_54 -> V_7 . V_242 ;
if ( V_232 != 0 ) {
T_7 V_13 ;
F_19 ( V_35 -> V_70 , L_102 , sizeof( V_35 -> V_70 ) ) ;
V_13 = strlen ( V_35 -> V_70 ) ;
F_38 ( V_66 , V_232 , V_35 -> V_70 + V_13 ,
sizeof( V_35 -> V_70 ) - V_13 ) ;
}
if ( F_42 ( V_35 ) < 0 ) {
F_16 ( V_187 , L_103
L_104 ) ;
goto error;
}
F_18 ( V_72 , L_105 ,
V_35 -> V_160 >> 8 , V_35 -> V_160 & 0xff ,
V_66 -> V_239 ? V_66 -> V_239 : L_106 ,
F_31 ( V_66 -> V_150 . V_151 ) ,
F_31 ( V_66 -> V_150 . V_233 ) ) ;
if ( V_35 -> V_74 != V_36 -> V_238 ) {
F_18 ( V_72 , L_107
L_108 , V_35 -> V_74 ) ;
F_18 ( V_72 , L_109
L_110 ) ;
}
#ifdef F_67
V_35 -> V_213 . V_35 = & V_53 -> V_35 ;
F_17 ( V_35 -> V_213 . V_243 , V_35 -> V_70 , sizeof( V_35 -> V_213 . V_243 ) ) ;
if ( V_66 -> V_244 )
F_17 ( V_35 -> V_213 . V_244 , V_66 -> V_244 ,
sizeof( V_35 -> V_213 . V_244 ) ) ;
strcpy ( V_35 -> V_213 . V_245 , V_66 -> V_234 ) ;
V_35 -> V_213 . V_246 = F_31 ( V_66 -> V_150 . V_247 ) ;
F_95 ( & V_35 -> V_213 ) ;
V_35 -> V_212 . V_213 = & V_35 -> V_213 ;
#endif
if ( F_96 ( & V_53 -> V_35 , & V_35 -> V_212 ) < 0 )
goto error;
if ( F_97 ( V_35 ) < 0 )
goto error;
if ( F_59 ( V_35 ) < 0 )
goto error;
if ( F_88 ( V_35 ) < 0 )
goto error;
#ifdef F_67
if ( F_98 ( & V_35 -> V_213 ) < 0 )
goto error;
#endif
F_99 ( V_53 , V_35 ) ;
if ( ( V_116 = F_100 ( V_35 ) ) < 0 ) {
F_18 ( V_72 , L_111
L_112
L_113 , V_116 ) ;
}
F_16 ( V_187 , L_114 ) ;
F_101 ( V_66 ) ;
return 0 ;
error:
F_76 ( V_35 ) ;
return - V_248 ;
}
static void F_102 ( struct V_52 * V_53 )
{
struct V_34 * V_35 = F_103 ( V_53 ) ;
F_99 ( V_53 , NULL ) ;
if ( V_53 -> V_54 -> V_7 . V_117 ==
V_118 )
return;
F_76 ( V_35 ) ;
}
static int F_104 ( struct V_52 * V_53 , T_8 V_249 )
{
struct V_34 * V_35 = F_103 ( V_53 ) ;
struct V_42 * V_43 ;
F_16 ( V_250 , L_115 ,
V_53 -> V_54 -> V_7 . V_68 ) ;
if ( V_53 -> V_54 -> V_7 . V_117 ==
V_251 ) {
F_105 ( & V_35 -> V_236 ) ;
if ( V_35 -> V_252 )
F_106 ( V_35 ) ;
F_107 ( & V_35 -> V_236 ) ;
return 0 ;
}
F_10 (stream, &dev->streams, list) {
if ( V_43 -> V_53 == V_53 )
return F_108 ( V_43 ) ;
}
F_16 ( V_250 , L_116
L_117 ) ;
return - V_69 ;
}
static int F_109 ( struct V_52 * V_53 , int V_253 )
{
struct V_34 * V_35 = F_103 ( V_53 ) ;
struct V_42 * V_43 ;
int V_116 = 0 ;
F_16 ( V_250 , L_118 ,
V_53 -> V_54 -> V_7 . V_68 ) ;
if ( V_53 -> V_54 -> V_7 . V_117 ==
V_251 ) {
if ( V_253 ) {
V_116 = F_110 ( V_35 ) ;
if ( V_116 < 0 )
return V_116 ;
}
F_105 ( & V_35 -> V_236 ) ;
if ( V_35 -> V_252 )
V_116 = F_111 ( V_35 , V_254 ) ;
F_107 ( & V_35 -> V_236 ) ;
return V_116 ;
}
F_10 (stream, &dev->streams, list) {
if ( V_43 -> V_53 == V_53 ) {
V_116 = F_112 ( V_43 , V_253 ) ;
if ( V_116 < 0 )
F_113 ( & V_43 -> V_216 ,
V_43 -> V_216 . V_216 . type ) ;
return V_116 ;
}
}
F_16 ( V_250 , L_119
L_117 ) ;
return - V_69 ;
}
static int F_114 ( struct V_52 * V_53 )
{
return F_109 ( V_53 , 0 ) ;
}
static int F_115 ( struct V_52 * V_53 )
{
return F_109 ( V_53 , 1 ) ;
}
static int F_116 ( char * V_50 , struct V_255 * V_256 )
{
if ( V_257 == V_258 )
return sprintf ( V_50 , L_120 ) ;
else
return sprintf ( V_50 , L_121 ) ;
}
static int F_117 ( const char * V_259 , struct V_255 * V_256 )
{
if ( strncasecmp ( V_259 , L_122 , strlen ( L_122 ) ) == 0 )
V_259 += strlen ( L_122 ) ;
if ( strcasecmp ( V_259 , L_123 ) == 0 )
V_257 = V_258 ;
else if ( strcasecmp ( V_259 , L_124 ) == 0 )
V_257 = V_260 ;
else
return - V_69 ;
return 0 ;
}
static int T_9 F_118 ( void )
{
int V_116 ;
F_119 () ;
V_116 = F_120 ( & V_119 . V_120 ) ;
if ( V_116 < 0 ) {
F_121 () ;
return V_116 ;
}
F_45 (KERN_INFO DRIVER_DESC L_125 DRIVER_VERSION L_126 ) ;
return 0 ;
}
static void T_10 F_122 ( void )
{
F_123 ( & V_119 . V_120 ) ;
F_121 () ;
}
