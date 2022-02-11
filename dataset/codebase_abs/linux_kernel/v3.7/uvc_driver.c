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
unsigned int V_59 ;
unsigned int V_6 , V_30 ;
T_1 V_60 ;
V_48 -> type = V_50 [ 2 ] ;
V_48 -> V_61 = V_50 [ 3 ] ;
switch ( V_50 [ 2 ] ) {
case V_62 :
case V_63 :
V_30 = V_50 [ 2 ] == V_62 ? 27 : 28 ;
if ( V_51 < V_30 ) {
F_16 ( V_64 , L_1
L_2 ,
V_35 -> V_65 -> V_66 ,
V_3 -> V_7 . V_67 ) ;
return - V_68 ;
}
V_55 = F_2 ( & V_50 [ 5 ] ) ;
if ( V_55 != NULL ) {
F_17 ( V_48 -> V_69 , V_55 -> V_69 ,
sizeof V_48 -> V_69 ) ;
V_48 -> V_70 = V_55 -> V_70 ;
} else {
F_18 ( V_71 , L_3 ,
& V_50 [ 5 ] ) ;
snprintf ( V_48 -> V_69 , sizeof( V_48 -> V_69 ) , L_4 ,
& V_50 [ 5 ] ) ;
V_48 -> V_70 = 0 ;
}
V_48 -> V_72 = V_50 [ 21 ] ;
if ( V_50 [ 2 ] == V_62 ) {
V_60 = V_73 ;
} else {
V_60 = V_74 ;
if ( V_50 [ 27 ] )
V_48 -> V_75 = V_76 ;
}
break;
case V_77 :
if ( V_51 < 11 ) {
F_16 ( V_64 , L_1
L_2 ,
V_35 -> V_65 -> V_66 ,
V_3 -> V_7 . V_67 ) ;
return - V_68 ;
}
F_17 ( V_48 -> V_69 , L_5 , sizeof V_48 -> V_69 ) ;
V_48 -> V_70 = V_78 ;
V_48 -> V_75 = V_76 ;
V_48 -> V_72 = 0 ;
V_60 = V_79 ;
break;
case V_80 :
if ( V_51 < 9 ) {
F_16 ( V_64 , L_1
L_2 ,
V_35 -> V_65 -> V_66 ,
V_3 -> V_7 . V_67 ) ;
return - V_68 ;
}
switch ( V_50 [ 8 ] & 0x7f ) {
case 0 :
F_17 ( V_48 -> V_69 , L_6 , sizeof V_48 -> V_69 ) ;
break;
case 1 :
F_17 ( V_48 -> V_69 , L_7 , sizeof V_48 -> V_69 ) ;
break;
case 2 :
F_17 ( V_48 -> V_69 , L_8 , sizeof V_48 -> V_69 ) ;
break;
default:
F_16 ( V_64 , L_1
L_9 ,
V_35 -> V_65 -> V_66 ,
V_3 -> V_7 . V_67 , V_50 [ 8 ] ) ;
return - V_68 ;
}
F_19 ( V_48 -> V_69 , V_50 [ 8 ] & ( 1 << 7 ) ? L_10 : L_11 ,
sizeof V_48 -> V_69 ) ;
V_48 -> V_70 = V_81 ;
V_48 -> V_75 = V_76 | V_82 ;
V_48 -> V_72 = 0 ;
V_60 = 0 ;
V_57 = & V_48 -> V_57 [ 0 ] ;
memset ( & V_48 -> V_57 [ 0 ] , 0 , sizeof V_48 -> V_57 [ 0 ] ) ;
V_57 -> V_83 = 1 ;
V_57 -> V_84 = 1 ;
V_57 -> V_85 = * V_49 ;
* ( * V_49 ) ++ = 1 ;
V_48 -> V_86 = 1 ;
break;
case V_87 :
case V_88 :
default:
F_16 ( V_64 , L_1
L_12 ,
V_35 -> V_65 -> V_66 , V_3 -> V_7 . V_67 ,
V_50 [ 2 ] ) ;
return - V_68 ;
}
F_16 ( V_64 , L_13 , V_48 -> V_69 ) ;
V_51 -= V_50 [ 0 ] ;
V_50 += V_50 [ 0 ] ;
while ( V_51 > 2 && V_50 [ 1 ] == V_89 &&
V_50 [ 2 ] == V_60 ) {
V_57 = & V_48 -> V_57 [ V_48 -> V_86 ] ;
if ( V_60 != V_74 )
V_30 = V_51 > 25 ? V_50 [ 25 ] : 0 ;
else
V_30 = V_51 > 21 ? V_50 [ 21 ] : 0 ;
V_30 = V_30 ? V_30 : 3 ;
if ( V_51 < 26 + 4 * V_30 ) {
F_16 ( V_64 , L_1
L_14 , V_35 -> V_65 -> V_66 ,
V_3 -> V_7 . V_67 ) ;
return - V_68 ;
}
V_57 -> V_90 = V_50 [ 3 ] ;
V_57 -> V_91 = V_50 [ 4 ] ;
V_57 -> V_92 = F_20 ( & V_50 [ 5 ] ) ;
V_57 -> V_93 = F_20 ( & V_50 [ 7 ] ) ;
V_57 -> V_94 = F_21 ( & V_50 [ 9 ] ) ;
V_57 -> V_95 = F_21 ( & V_50 [ 13 ] ) ;
if ( V_60 != V_74 ) {
V_57 -> V_96 =
F_21 ( & V_50 [ 17 ] ) ;
V_57 -> V_84 =
F_21 ( & V_50 [ 21 ] ) ;
V_57 -> V_83 = V_50 [ 25 ] ;
} else {
V_57 -> V_96 = 0 ;
V_57 -> V_84 =
F_21 ( & V_50 [ 17 ] ) ;
V_57 -> V_83 = V_50 [ 21 ] ;
}
V_57 -> V_85 = * V_49 ;
if ( ! ( V_48 -> V_75 & V_76 ) )
V_57 -> V_96 = V_48 -> V_72
* V_57 -> V_92 * V_57 -> V_93 / 8 ;
for ( V_6 = 0 ; V_6 < V_30 ; ++ V_6 ) {
V_59 = F_21 ( & V_50 [ 26 + 4 * V_6 ] ) ;
* ( * V_49 ) ++ = V_59 ? V_59 : 1 ;
}
V_30 -= V_57 -> V_83 ? 1 : 2 ;
V_57 -> V_84 =
F_22 ( V_57 -> V_85 [ V_30 ] ,
F_23 ( V_57 -> V_85 [ 0 ] ,
V_57 -> V_84 ) ) ;
if ( V_35 -> V_97 & V_98 ) {
V_57 -> V_83 = 1 ;
V_57 -> V_85 [ 0 ] =
V_57 -> V_84 ;
}
F_16 ( V_64 , L_15 ,
V_57 -> V_92 , V_57 -> V_93 ,
10000000 / V_57 -> V_84 ,
( 100000000 / V_57 -> V_84 ) % 10 ) ;
V_48 -> V_86 ++ ;
V_51 -= V_50 [ 0 ] ;
V_50 += V_50 [ 0 ] ;
}
if ( V_51 > 2 && V_50 [ 1 ] == V_89 &&
V_50 [ 2 ] == V_99 ) {
V_51 -= V_50 [ 0 ] ;
V_50 += V_50 [ 0 ] ;
}
if ( V_51 > 2 && V_50 [ 1 ] == V_89 &&
V_50 [ 2 ] == V_100 ) {
if ( V_51 < 6 ) {
F_16 ( V_64 , L_1
L_16 ,
V_35 -> V_65 -> V_66 ,
V_3 -> V_7 . V_67 ) ;
return - V_68 ;
}
V_48 -> V_101 = F_4 ( V_50 [ 3 ] ) ;
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
struct V_2 * V_3 = & V_53 -> V_102 [ 0 ] ;
unsigned char * V_103 , * V_50 = V_3 -> V_104 ;
int V_105 , V_51 = V_3 -> V_106 ;
unsigned int V_107 = 0 , V_86 = 0 , V_108 = 0 ;
unsigned int V_109 , V_6 , V_30 , V_110 ;
T_2 * V_59 ;
T_4 V_111 ;
int V_112 = - V_68 ;
if ( V_53 -> V_54 -> V_7 . V_113
!= V_114 ) {
F_16 ( V_64 , L_17
L_18 , V_35 -> V_65 -> V_66 ,
V_53 -> V_102 [ 0 ] . V_7 . V_67 ) ;
return - V_68 ;
}
if ( F_25 ( & V_115 . V_116 , V_53 , V_35 ) ) {
F_16 ( V_64 , L_19
L_20 , V_35 -> V_65 -> V_66 ,
V_53 -> V_102 [ 0 ] . V_7 . V_67 ) ;
return - V_68 ;
}
V_46 = F_26 ( sizeof *V_46 , V_31 ) ;
if ( V_46 == NULL ) {
F_27 ( & V_115 . V_116 , V_53 ) ;
return - V_68 ;
}
F_28 ( & V_46 -> V_117 ) ;
V_46 -> V_35 = V_35 ;
V_46 -> V_53 = F_29 ( V_53 ) ;
V_46 -> V_118 = V_53 -> V_54 -> V_7 . V_67 ;
if ( V_51 == 0 ) {
for ( V_6 = 0 ; V_6 < V_3 -> V_7 . V_8 ; ++ V_6 ) {
struct V_1 * V_5 = & V_3 -> V_9 [ V_6 ] ;
if ( V_5 -> V_106 == 0 )
continue;
if ( V_5 -> V_106 > 2 &&
V_5 -> V_104 [ 1 ] == V_89 ) {
F_16 ( V_64 , L_21
L_22 , V_6 ) ;
V_50 = V_3 -> V_9 [ V_6 ] . V_104 ;
V_51 = V_3 -> V_9 [ V_6 ] . V_106 ;
break;
}
}
}
while ( V_51 > 2 && V_50 [ 1 ] != V_89 ) {
V_51 -= V_50 [ 0 ] ;
V_50 += V_50 [ 0 ] ;
}
if ( V_51 <= 2 ) {
F_16 ( V_64 , L_23
L_24 ) ;
goto error;
}
switch ( V_50 [ 2 ] ) {
case V_119 :
V_46 -> type = V_120 ;
V_109 = 9 ;
break;
case V_121 :
V_46 -> type = V_122 ;
V_109 = 13 ;
break;
default:
F_16 ( V_64 , L_25
L_26 , V_35 -> V_65 -> V_66 ,
V_3 -> V_7 . V_67 ) ;
goto error;
}
V_110 = V_51 >= 4 ? V_50 [ 3 ] : 0 ;
V_30 = V_51 >= V_109 ? V_50 [ V_109 - 1 ] : 0 ;
if ( V_51 < V_109 + V_110 * V_30 ) {
F_16 ( V_64 , L_1
L_27 ,
V_35 -> V_65 -> V_66 , V_3 -> V_7 . V_67 ) ;
goto error;
}
V_46 -> V_44 . V_123 = V_110 ;
V_46 -> V_44 . V_10 = V_50 [ 6 ] ;
if ( V_50 [ 2 ] == V_121 ) {
V_46 -> V_44 . V_124 = V_50 [ 7 ] ;
V_46 -> V_44 . V_45 = V_50 [ 8 ] ;
V_46 -> V_44 . V_125 = V_50 [ 9 ] ;
V_46 -> V_44 . V_126 = V_50 [ 10 ] ;
V_46 -> V_44 . V_127 = V_50 [ 11 ] ;
} else {
V_46 -> V_44 . V_45 = V_50 [ 7 ] ;
}
V_46 -> V_44 . V_128 = V_30 ;
V_46 -> V_44 . V_129 = F_30 ( & V_50 [ V_109 ] , V_110 * V_30 ,
V_31 ) ;
if ( V_46 -> V_44 . V_129 == NULL ) {
V_112 = - V_130 ;
goto error;
}
V_51 -= V_50 [ 0 ] ;
V_50 += V_50 [ 0 ] ;
V_103 = V_50 ;
V_105 = V_51 ;
while ( V_105 > 2 && V_103 [ 1 ] == V_89 ) {
switch ( V_103 [ 2 ] ) {
case V_62 :
case V_77 :
case V_63 :
V_107 ++ ;
break;
case V_80 :
V_107 ++ ;
V_86 ++ ;
V_108 ++ ;
break;
case V_87 :
case V_88 :
F_16 ( V_64 , L_1
L_28 ,
V_35 -> V_65 -> V_66 ,
V_3 -> V_7 . V_67 , V_103 [ 2 ] ) ;
break;
case V_73 :
case V_79 :
V_86 ++ ;
if ( V_105 > 25 )
V_108 += V_103 [ 25 ] ? V_103 [ 25 ] : 3 ;
break;
case V_74 :
V_86 ++ ;
if ( V_105 > 21 )
V_108 += V_103 [ 21 ] ? V_103 [ 21 ] : 3 ;
break;
}
V_105 -= V_103 [ 0 ] ;
V_103 += V_103 [ 0 ] ;
}
if ( V_107 == 0 ) {
F_16 ( V_64 , L_25
L_29 ,
V_35 -> V_65 -> V_66 , V_3 -> V_7 . V_67 ) ;
goto error;
}
V_109 = V_107 * sizeof *V_48 + V_86 * sizeof *V_57
+ V_108 * sizeof *V_59 ;
V_48 = F_26 ( V_109 , V_31 ) ;
if ( V_48 == NULL ) {
V_112 = - V_130 ;
goto error;
}
V_57 = (struct V_56 * ) & V_48 [ V_107 ] ;
V_59 = ( T_2 * ) & V_57 [ V_86 ] ;
V_46 -> V_48 = V_48 ;
V_46 -> V_107 = V_107 ;
while ( V_51 > 2 && V_50 [ 1 ] == V_89 ) {
switch ( V_50 [ 2 ] ) {
case V_62 :
case V_77 :
case V_80 :
case V_63 :
V_48 -> V_57 = V_57 ;
V_112 = F_15 ( V_35 , V_46 , V_48 ,
& V_59 , V_50 , V_51 ) ;
if ( V_112 < 0 )
goto error;
V_57 += V_48 -> V_86 ;
V_48 ++ ;
V_51 -= V_112 ;
V_50 += V_112 ;
continue;
default:
break;
}
V_51 -= V_50 [ 0 ] ;
V_50 += V_50 [ 0 ] ;
}
if ( V_51 )
F_16 ( V_64 , L_25
L_30 ,
V_35 -> V_65 -> V_66 , V_3 -> V_7 . V_67 , V_51 ) ;
for ( V_6 = 0 ; V_6 < V_53 -> V_131 ; ++ V_6 ) {
struct V_1 * V_5 ;
V_3 = & V_53 -> V_102 [ V_6 ] ;
V_5 = F_1 ( V_3 ,
V_46 -> V_44 . V_10 ) ;
if ( V_5 == NULL )
continue;
V_111 = F_31 ( V_5 -> V_7 . V_132 ) ;
V_111 = ( V_111 & 0x07ff ) * ( 1 + ( ( V_111 >> 11 ) & 3 ) ) ;
if ( V_111 > V_46 -> V_133 )
V_46 -> V_133 = V_111 ;
}
F_32 ( & V_46 -> V_39 , & V_35 -> V_134 ) ;
return 0 ;
error:
F_27 ( & V_115 . V_116 , V_53 ) ;
F_33 ( V_53 ) ;
F_7 ( V_46 -> V_48 ) ;
F_7 ( V_46 -> V_44 . V_129 ) ;
F_7 ( V_46 ) ;
return V_112 ;
}
static struct V_33 * F_34 ( T_5 type , T_6 V_36 ,
unsigned int V_135 , unsigned int V_136 )
{
struct V_33 * V_37 ;
unsigned int V_137 ;
unsigned int V_109 ;
unsigned int V_6 ;
V_136 = F_35 ( V_136 , sizeof( * V_37 -> V_138 ) ) ;
V_137 = ( type & V_139 ) ? V_135 : V_135 - 1 ;
V_109 = sizeof( * V_37 ) + V_136 + sizeof( * V_37 -> V_138 ) * V_135
+ V_137 ;
V_37 = F_26 ( V_109 , V_31 ) ;
if ( V_37 == NULL )
return NULL ;
V_37 -> V_36 = V_36 ;
V_37 -> type = type ;
V_37 -> V_140 = 0 ;
V_37 -> V_135 = V_135 ;
V_37 -> V_138 = ( ( void * ) ( V_37 + 1 ) ) + V_136 ;
for ( V_6 = 0 ; V_6 < V_137 ; ++ V_6 )
V_37 -> V_138 [ V_6 ] . V_75 = V_141 ;
if ( ! F_36 ( V_37 ) )
V_37 -> V_138 [ V_135 - 1 ] . V_75 = V_142 ;
V_37 -> V_40 = V_137 ;
V_37 -> V_41 = ( T_1 * ) ( & V_37 -> V_138 [ V_135 ] ) ;
return V_37 ;
}
static int F_37 ( struct V_34 * V_35 ,
const unsigned char * V_50 , int V_51 )
{
struct V_143 * V_65 = V_35 -> V_65 ;
struct V_2 * V_3 = V_35 -> V_53 -> V_54 ;
struct V_33 * V_144 ;
unsigned int V_30 , V_110 ;
int V_145 = 0 ;
switch ( F_31 ( V_35 -> V_65 -> V_146 . V_147 ) ) {
case 0x046d :
if ( V_50 [ 1 ] != 0x41 || V_50 [ 2 ] != 0x01 )
break;
V_110 = V_51 >= 22 ? V_50 [ 21 ] : 0 ;
V_30 = V_51 >= 25 + V_110 ? V_50 [ 22 + V_110 ] : 0 ;
if ( V_51 < 25 + V_110 + 2 * V_30 ) {
F_16 ( V_64 , L_31
L_32 ,
V_65 -> V_66 , V_3 -> V_7 . V_67 ) ;
break;
}
V_144 = F_34 ( V_148 , V_50 [ 3 ] ,
V_110 + 1 , 2 * V_30 ) ;
if ( V_144 == NULL )
return - V_130 ;
memcpy ( V_144 -> V_149 . V_150 , & V_50 [ 4 ] , 16 ) ;
V_144 -> V_149 . V_151 = V_50 [ 20 ] ;
memcpy ( V_144 -> V_41 , & V_50 [ 22 ] , V_110 ) ;
V_144 -> V_149 . V_128 = V_50 [ 22 + V_110 ] ;
V_144 -> V_149 . V_152 = ( T_1 * ) V_144 + sizeof( * V_144 ) ;
V_144 -> V_149 . V_153 = ( T_1 * ) V_144 + sizeof( * V_144 )
+ V_30 ;
memcpy ( V_144 -> V_149 . V_152 , & V_50 [ 23 + V_110 ] , 2 * V_30 ) ;
if ( V_50 [ 24 + V_110 + 2 * V_30 ] != 0 )
F_38 ( V_65 , V_50 [ 24 + V_110 + 2 * V_30 ] , V_144 -> V_69 ,
sizeof V_144 -> V_69 ) ;
else
sprintf ( V_144 -> V_69 , L_33 , V_50 [ 3 ] ) ;
F_32 ( & V_144 -> V_39 , & V_35 -> V_38 ) ;
V_145 = 1 ;
break;
}
return V_145 ;
}
static int F_39 ( struct V_34 * V_35 ,
const unsigned char * V_50 , int V_51 )
{
struct V_143 * V_65 = V_35 -> V_65 ;
struct V_33 * V_144 , * V_154 ;
struct V_52 * V_53 ;
struct V_2 * V_3 = V_35 -> V_53 -> V_54 ;
unsigned int V_6 , V_30 , V_110 , V_13 ;
T_4 type ;
switch ( V_50 [ 2 ] ) {
case V_155 :
V_30 = V_51 >= 12 ? V_50 [ 11 ] : 0 ;
if ( V_51 < 12 || V_51 < 12 + V_30 ) {
F_16 ( V_64 , L_31
L_34 , V_65 -> V_66 ,
V_3 -> V_7 . V_67 ) ;
return - V_68 ;
}
V_35 -> V_156 = F_20 ( & V_50 [ 3 ] ) ;
V_35 -> V_157 = F_21 ( & V_50 [ 7 ] ) ;
for ( V_6 = 0 ; V_6 < V_30 ; ++ V_6 ) {
V_53 = F_40 ( V_65 , V_50 [ 12 + V_6 ] ) ;
if ( V_53 == NULL ) {
F_16 ( V_64 , L_35
L_36 ,
V_65 -> V_66 , V_6 ) ;
continue;
}
F_24 ( V_35 , V_53 ) ;
}
break;
case V_158 :
if ( V_51 < 8 ) {
F_16 ( V_64 , L_31
L_37 ,
V_65 -> V_66 , V_3 -> V_7 . V_67 ) ;
return - V_68 ;
}
type = F_20 ( & V_50 [ 4 ] ) ;
if ( ( type & 0xff00 ) == 0 ) {
F_16 ( V_64 , L_31
L_38
L_39 , V_65 -> V_66 ,
V_3 -> V_7 . V_67 ,
V_50 [ 3 ] , type ) ;
return 0 ;
}
V_30 = 0 ;
V_110 = 0 ;
V_13 = 8 ;
if ( type == V_159 ) {
V_30 = V_51 >= 15 ? V_50 [ 14 ] : 0 ;
V_13 = 15 ;
} else if ( type == V_160 ) {
V_30 = V_51 >= 9 ? V_50 [ 8 ] : 0 ;
V_110 = V_51 >= 10 + V_30 ? V_50 [ 9 + V_30 ] : 0 ;
V_13 = 10 ;
}
if ( V_51 < V_13 + V_30 + V_110 ) {
F_16 ( V_64 , L_31
L_37 ,
V_65 -> V_66 , V_3 -> V_7 . V_67 ) ;
return - V_68 ;
}
V_154 = F_34 ( type | V_161 , V_50 [ 3 ] ,
1 , V_30 + V_110 ) ;
if ( V_154 == NULL )
return - V_130 ;
if ( F_41 ( V_154 ) == V_159 ) {
V_154 -> V_162 . V_128 = V_30 ;
V_154 -> V_162 . V_152 = ( T_1 * ) V_154 + sizeof *V_154 ;
V_154 -> V_162 . V_163 =
F_20 ( & V_50 [ 8 ] ) ;
V_154 -> V_162 . V_164 =
F_20 ( & V_50 [ 10 ] ) ;
V_154 -> V_162 . V_165 =
F_20 ( & V_50 [ 12 ] ) ;
memcpy ( V_154 -> V_162 . V_152 , & V_50 [ 15 ] , V_30 ) ;
} else if ( F_41 ( V_154 ) ==
V_160 ) {
V_154 -> V_166 . V_128 = V_30 ;
V_154 -> V_166 . V_152 = ( T_1 * ) V_154 + sizeof *V_154 ;
V_154 -> V_166 . V_167 = V_110 ;
V_154 -> V_166 . V_168 = ( T_1 * ) V_154
+ sizeof *V_154 + V_30 ;
memcpy ( V_154 -> V_166 . V_152 , & V_50 [ 9 ] , V_30 ) ;
memcpy ( V_154 -> V_166 . V_168 , & V_50 [ 10 + V_30 ] , V_110 ) ;
}
if ( V_50 [ 7 ] != 0 )
F_38 ( V_65 , V_50 [ 7 ] , V_154 -> V_69 ,
sizeof V_154 -> V_69 ) ;
else if ( F_41 ( V_154 ) == V_159 )
sprintf ( V_154 -> V_69 , L_40 , V_50 [ 3 ] ) ;
else if ( F_41 ( V_154 ) == V_160 )
sprintf ( V_154 -> V_69 , L_41 , V_50 [ 3 ] ) ;
else
sprintf ( V_154 -> V_69 , L_42 , V_50 [ 3 ] ) ;
F_32 ( & V_154 -> V_39 , & V_35 -> V_38 ) ;
break;
case V_169 :
if ( V_51 < 9 ) {
F_16 ( V_64 , L_31
L_43 ,
V_65 -> V_66 , V_3 -> V_7 . V_67 ) ;
return - V_68 ;
}
type = F_20 ( & V_50 [ 4 ] ) ;
if ( ( type & 0xff00 ) == 0 ) {
F_16 ( V_64 , L_31
L_44
L_39 , V_65 -> V_66 ,
V_3 -> V_7 . V_67 , V_50 [ 3 ] , type ) ;
return 0 ;
}
V_154 = F_34 ( type | V_139 , V_50 [ 3 ] ,
1 , 0 ) ;
if ( V_154 == NULL )
return - V_130 ;
memcpy ( V_154 -> V_41 , & V_50 [ 7 ] , 1 ) ;
if ( V_50 [ 8 ] != 0 )
F_38 ( V_65 , V_50 [ 8 ] , V_154 -> V_69 ,
sizeof V_154 -> V_69 ) ;
else
sprintf ( V_154 -> V_69 , L_45 , V_50 [ 3 ] ) ;
F_32 ( & V_154 -> V_39 , & V_35 -> V_38 ) ;
break;
case V_170 :
V_110 = V_51 >= 5 ? V_50 [ 4 ] : 0 ;
if ( V_51 < 5 || V_51 < 6 + V_110 ) {
F_16 ( V_64 , L_31
L_46 ,
V_65 -> V_66 , V_3 -> V_7 . V_67 ) ;
return - V_68 ;
}
V_144 = F_34 ( V_50 [ 2 ] , V_50 [ 3 ] , V_110 + 1 , 0 ) ;
if ( V_144 == NULL )
return - V_130 ;
memcpy ( V_144 -> V_41 , & V_50 [ 5 ] , V_110 ) ;
if ( V_50 [ 5 + V_110 ] != 0 )
F_38 ( V_65 , V_50 [ 5 + V_110 ] , V_144 -> V_69 ,
sizeof V_144 -> V_69 ) ;
else
sprintf ( V_144 -> V_69 , L_47 , V_50 [ 3 ] ) ;
F_32 ( & V_144 -> V_39 , & V_35 -> V_38 ) ;
break;
case V_171 :
V_30 = V_51 >= 8 ? V_50 [ 7 ] : 0 ;
V_110 = V_35 -> V_156 >= 0x0110 ? 10 : 9 ;
if ( V_51 < V_110 + V_30 ) {
F_16 ( V_64 , L_31
L_48 ,
V_65 -> V_66 , V_3 -> V_7 . V_67 ) ;
return - V_68 ;
}
V_144 = F_34 ( V_50 [ 2 ] , V_50 [ 3 ] , 2 , V_30 ) ;
if ( V_144 == NULL )
return - V_130 ;
memcpy ( V_144 -> V_41 , & V_50 [ 4 ] , 1 ) ;
V_144 -> V_172 . V_173 =
F_20 ( & V_50 [ 5 ] ) ;
V_144 -> V_172 . V_128 = V_50 [ 7 ] ;
V_144 -> V_172 . V_152 = ( T_1 * ) V_144 + sizeof *V_144 ;
memcpy ( V_144 -> V_172 . V_152 , & V_50 [ 8 ] , V_30 ) ;
if ( V_35 -> V_156 >= 0x0110 )
V_144 -> V_172 . V_174 = V_50 [ 9 + V_30 ] ;
if ( V_50 [ 8 + V_30 ] != 0 )
F_38 ( V_65 , V_50 [ 8 + V_30 ] , V_144 -> V_69 ,
sizeof V_144 -> V_69 ) ;
else
sprintf ( V_144 -> V_69 , L_49 , V_50 [ 3 ] ) ;
F_32 ( & V_144 -> V_39 , & V_35 -> V_38 ) ;
break;
case V_148 :
V_110 = V_51 >= 22 ? V_50 [ 21 ] : 0 ;
V_30 = V_51 >= 24 + V_110 ? V_50 [ 22 + V_110 ] : 0 ;
if ( V_51 < 24 + V_110 + V_30 ) {
F_16 ( V_64 , L_31
L_32 ,
V_65 -> V_66 , V_3 -> V_7 . V_67 ) ;
return - V_68 ;
}
V_144 = F_34 ( V_50 [ 2 ] , V_50 [ 3 ] , V_110 + 1 , V_30 ) ;
if ( V_144 == NULL )
return - V_130 ;
memcpy ( V_144 -> V_149 . V_150 , & V_50 [ 4 ] , 16 ) ;
V_144 -> V_149 . V_151 = V_50 [ 20 ] ;
memcpy ( V_144 -> V_41 , & V_50 [ 22 ] , V_110 ) ;
V_144 -> V_149 . V_128 = V_50 [ 22 + V_110 ] ;
V_144 -> V_149 . V_152 = ( T_1 * ) V_144 + sizeof *V_144 ;
memcpy ( V_144 -> V_149 . V_152 , & V_50 [ 23 + V_110 ] , V_30 ) ;
if ( V_50 [ 23 + V_110 + V_30 ] != 0 )
F_38 ( V_65 , V_50 [ 23 + V_110 + V_30 ] , V_144 -> V_69 ,
sizeof V_144 -> V_69 ) ;
else
sprintf ( V_144 -> V_69 , L_33 , V_50 [ 3 ] ) ;
F_32 ( & V_144 -> V_39 , & V_35 -> V_38 ) ;
break;
default:
F_16 ( V_64 , L_50
L_51 , V_50 [ 2 ] ) ;
break;
}
return 0 ;
}
static int F_42 ( struct V_34 * V_35 )
{
struct V_2 * V_3 = V_35 -> V_53 -> V_54 ;
unsigned char * V_50 = V_3 -> V_104 ;
int V_51 = V_3 -> V_106 ;
int V_112 ;
while ( V_51 > 2 ) {
if ( F_37 ( V_35 , V_50 , V_51 ) ||
V_50 [ 1 ] != V_89 )
goto V_175;
if ( ( V_112 = F_39 ( V_35 , V_50 , V_51 ) ) < 0 )
return V_112 ;
V_175:
V_51 -= V_50 [ 0 ] ;
V_50 += V_50 [ 0 ] ;
}
if ( V_3 -> V_7 . V_8 == 1 &&
! ( V_35 -> V_97 & V_176 ) ) {
struct V_1 * V_5 = & V_3 -> V_9 [ 0 ] ;
struct V_177 * V_7 = & V_5 -> V_7 ;
if ( F_43 ( V_7 ) &&
F_31 ( V_7 -> V_132 ) >= 8 &&
V_7 -> V_178 != 0 ) {
F_16 ( V_64 , L_52
L_53 , V_7 -> V_10 ) ;
V_35 -> V_179 = V_5 ;
}
}
return 0 ;
}
static int F_44 ( struct V_180 * V_181 ,
struct V_33 * V_37 )
{
switch ( F_41 ( V_37 ) ) {
case V_148 :
if ( V_182 & V_183 )
F_45 ( L_54 , V_37 -> V_36 ) ;
if ( V_37 -> V_40 != 1 ) {
F_16 ( V_64 , L_55
L_56 , V_37 -> V_36 ) ;
return - 1 ;
}
break;
case V_171 :
if ( V_182 & V_183 )
F_45 ( L_57 , V_37 -> V_36 ) ;
if ( V_181 -> V_172 != NULL ) {
F_16 ( V_64 , L_58
L_59 ) ;
return - 1 ;
}
V_181 -> V_172 = V_37 ;
break;
case V_170 :
if ( V_182 & V_183 )
F_45 ( L_60 , V_37 -> V_36 ) ;
if ( V_37 -> V_40 == 1 )
break;
if ( V_181 -> V_184 != NULL ) {
F_16 ( V_64 , L_61
L_62 ) ;
return - 1 ;
}
V_181 -> V_184 = V_37 ;
break;
case V_185 :
case V_159 :
case V_160 :
if ( V_182 & V_183 )
F_45 ( L_63 , V_37 -> V_36 ) ;
break;
case V_186 :
case V_187 :
case V_188 :
if ( V_182 & V_183 )
F_45 ( L_64 , V_37 -> V_36 ) ;
break;
case V_189 :
if ( F_46 ( V_37 ) ) {
if ( V_182 & V_183 )
F_45 ( L_63 , V_37 -> V_36 ) ;
} else {
if ( V_182 & V_183 )
F_45 ( L_64 , V_37 -> V_36 ) ;
}
break;
default:
F_16 ( V_64 , L_65
L_66 , F_41 ( V_37 ) ) ;
return - 1 ;
}
F_32 ( & V_37 -> V_181 , & V_181 -> V_38 ) ;
return 0 ;
}
static int F_47 ( struct V_180 * V_181 ,
struct V_33 * V_37 , struct V_33 * V_190 )
{
struct V_33 * V_191 ;
int V_192 ;
V_191 = NULL ;
V_192 = 0 ;
while ( 1 ) {
V_191 = F_11 ( V_181 -> V_35 , V_37 -> V_36 ,
V_191 ) ;
if ( V_191 == NULL )
break;
if ( V_191 == V_190 )
continue;
switch ( F_41 ( V_191 ) ) {
case V_148 :
if ( V_191 -> V_40 != 1 ) {
F_16 ( V_64 , L_67
L_68 ,
V_37 -> V_36 ) ;
return - V_68 ;
}
F_32 ( & V_191 -> V_181 , & V_181 -> V_38 ) ;
if ( V_182 & V_183 ) {
if ( ! V_192 )
F_45 ( L_69 ) ;
F_45 ( L_70 , V_191 -> V_36 ) ;
V_192 = 1 ;
}
break;
case V_186 :
case V_187 :
case V_188 :
case V_189 :
if ( F_46 ( V_191 ) ) {
F_16 ( V_64 , L_71
L_72 , V_191 -> V_36 ) ;
return - V_68 ;
}
F_32 ( & V_191 -> V_181 , & V_181 -> V_38 ) ;
if ( V_182 & V_183 ) {
if ( ! V_192 )
F_45 ( L_69 ) ;
F_45 ( L_64 , V_191 -> V_36 ) ;
V_192 = 1 ;
}
break;
}
}
if ( V_192 )
F_45 ( L_73 ) ;
return 0 ;
}
static int F_48 ( struct V_180 * V_181 ,
struct V_33 * * V_193 )
{
struct V_33 * V_37 = * V_193 ;
struct V_33 * V_154 ;
int V_36 = - V_68 , V_6 ;
switch ( F_41 ( V_37 ) ) {
case V_148 :
case V_171 :
V_36 = V_37 -> V_41 [ 0 ] ;
break;
case V_170 :
if ( V_37 -> V_40 == 1 ) {
V_36 = V_37 -> V_41 [ 0 ] ;
break;
}
if ( V_182 & V_183 )
F_45 ( L_74 ) ;
V_181 -> V_184 = V_37 ;
for ( V_6 = 0 ; V_6 < V_37 -> V_40 ; ++ V_6 ) {
V_36 = V_37 -> V_41 [ V_6 ] ;
V_154 = F_9 ( V_181 -> V_35 , V_36 ) ;
if ( V_154 == NULL || ! F_46 ( V_154 ) ) {
F_16 ( V_64 , L_75
L_76
L_77 , V_37 -> V_36 , V_6 ) ;
return - 1 ;
}
if ( V_182 & V_183 )
F_45 ( L_78 , V_154 -> V_36 ) ;
F_32 ( & V_154 -> V_181 , & V_181 -> V_38 ) ;
F_47 ( V_181 , V_154 , V_37 ) ;
}
if ( V_182 & V_183 )
F_45 ( L_79 ) ;
V_36 = 0 ;
break;
case V_185 :
case V_159 :
case V_160 :
case V_186 :
case V_187 :
case V_188 :
case V_189 :
V_36 = F_36 ( V_37 ) ? V_37 -> V_41 [ 0 ] : 0 ;
break;
}
if ( V_36 <= 0 ) {
* V_193 = NULL ;
return V_36 ;
}
V_37 = F_9 ( V_181 -> V_35 , V_36 ) ;
if ( V_37 == NULL ) {
F_16 ( V_64 , L_80
L_81 , V_36 ) ;
return - V_68 ;
}
* V_193 = V_37 ;
return 0 ;
}
static int F_49 ( struct V_180 * V_181 ,
struct V_33 * V_154 )
{
struct V_33 * V_37 , * V_190 ;
F_16 ( V_183 , L_82 ) ;
V_37 = V_154 ;
V_190 = NULL ;
while ( V_37 != NULL ) {
if ( V_37 -> V_181 . V_194 || V_37 -> V_181 . V_190 ) {
F_16 ( V_64 , L_80
L_83 , V_37 -> V_36 ) ;
return - V_68 ;
}
if ( F_44 ( V_181 , V_37 ) < 0 )
return - V_68 ;
if ( F_47 ( V_181 , V_37 , V_190 ) < 0 )
return - V_68 ;
V_190 = V_37 ;
if ( F_48 ( V_181 , & V_37 ) < 0 )
return - V_68 ;
}
return 0 ;
}
static unsigned int F_50 ( struct V_195 * V_196 , T_5 V_197 ,
char * V_50 )
{
struct V_33 * V_154 ;
unsigned int V_198 = 0 ;
char * V_110 = V_50 ;
F_10 (term, terms, chain) {
if ( ! F_51 ( V_154 ) ||
F_52 ( V_154 ) != V_197 )
continue;
if ( V_198 )
V_110 += sprintf ( V_110 , L_84 ) ;
if ( ++ V_198 >= 4 ) {
V_110 += sprintf ( V_110 , L_85 ) ;
break;
}
V_110 += sprintf ( V_110 , L_86 , V_154 -> V_36 ) ;
}
return V_110 - V_50 ;
}
static const char * F_53 ( struct V_180 * V_181 )
{
static char V_50 [ 43 ] ;
char * V_110 = V_50 ;
V_110 += F_50 ( & V_181 -> V_38 , V_161 , V_110 ) ;
V_110 += sprintf ( V_110 , L_87 ) ;
F_50 ( & V_181 -> V_38 , V_139 , V_110 ) ;
return V_50 ;
}
static int F_54 ( struct V_34 * V_35 )
{
struct V_180 * V_181 ;
struct V_33 * V_154 ;
F_10 (term, &dev->entities, list) {
if ( ! F_36 ( V_154 ) )
continue;
if ( V_154 -> V_181 . V_194 || V_154 -> V_181 . V_190 )
continue;
V_181 = F_26 ( sizeof( * V_181 ) , V_31 ) ;
if ( V_181 == NULL )
return - V_130 ;
F_55 ( & V_181 -> V_38 ) ;
F_28 ( & V_181 -> V_199 ) ;
V_181 -> V_35 = V_35 ;
if ( F_49 ( V_181 , V_154 ) < 0 ) {
F_7 ( V_181 ) ;
continue;
}
F_16 ( V_183 , L_88 ,
F_53 ( V_181 ) ) ;
F_32 ( & V_181 -> V_39 , & V_35 -> V_200 ) ;
}
if ( F_56 ( & V_35 -> V_200 ) ) {
F_18 ( V_71 , L_89 ) ;
return - 1 ;
}
return 0 ;
}
static void F_57 ( struct V_34 * V_35 )
{
struct V_195 * V_110 , * V_30 ;
F_33 ( V_35 -> V_53 ) ;
F_58 ( V_35 -> V_65 ) ;
F_59 ( V_35 ) ;
F_60 ( V_35 ) ;
if ( V_35 -> V_201 . V_35 )
F_61 ( & V_35 -> V_201 ) ;
#ifdef F_62
if ( F_63 ( & V_35 -> V_202 . V_203 ) )
F_64 ( & V_35 -> V_202 ) ;
#endif
F_65 (p, n, &dev->chains) {
struct V_180 * V_181 ;
V_181 = F_12 ( V_110 , struct V_180 , V_39 ) ;
F_7 ( V_181 ) ;
}
F_65 (p, n, &dev->entities) {
struct V_33 * V_37 ;
V_37 = F_12 ( V_110 , struct V_33 , V_39 ) ;
#ifdef F_62
F_66 ( V_37 ) ;
#endif
if ( V_37 -> V_201 ) {
F_67 ( V_37 -> V_201 ) ;
V_37 -> V_201 = NULL ;
}
F_7 ( V_37 ) ;
}
F_65 (p, n, &dev->streams) {
struct V_42 * V_46 ;
V_46 = F_12 ( V_110 , struct V_42 , V_39 ) ;
F_27 ( & V_115 . V_116 ,
V_46 -> V_53 ) ;
F_33 ( V_46 -> V_53 ) ;
F_7 ( V_46 -> V_48 ) ;
F_7 ( V_46 -> V_44 . V_129 ) ;
F_7 ( V_46 ) ;
}
F_7 ( V_35 ) ;
}
static void F_68 ( struct V_204 * V_201 )
{
struct V_42 * V_43 = F_69 ( V_201 ) ;
struct V_34 * V_35 = V_43 -> V_35 ;
if ( F_70 ( & V_35 -> V_205 ) )
F_57 ( V_35 ) ;
}
static void F_71 ( struct V_34 * V_35 )
{
struct V_42 * V_43 ;
F_72 ( & V_35 -> V_205 ) ;
F_10 (stream, &dev->streams, list) {
if ( V_43 -> V_201 == NULL )
continue;
F_73 ( V_43 -> V_201 ) ;
V_43 -> V_201 = NULL ;
F_74 ( V_43 ) ;
}
if ( F_70 ( & V_35 -> V_205 ) )
F_57 ( V_35 ) ;
}
static int F_75 ( struct V_34 * V_35 ,
struct V_42 * V_43 )
{
struct V_204 * V_201 ;
int V_112 ;
V_112 = F_76 ( V_43 ) ;
if ( V_112 < 0 ) {
F_18 ( V_206 , L_90
L_91 , V_112 ) ;
return V_112 ;
}
F_77 ( V_43 ) ;
V_201 = F_78 () ;
if ( V_201 == NULL ) {
F_18 ( V_206 , L_92 ,
V_112 ) ;
return - V_130 ;
}
V_201 -> V_207 = & V_35 -> V_201 ;
V_201 -> V_208 = & V_209 ;
V_201 -> V_210 = F_68 ;
if ( V_43 -> type == V_120 )
V_201 -> V_211 = V_212 ;
F_17 ( V_201 -> V_69 , V_35 -> V_69 , sizeof V_201 -> V_69 ) ;
V_43 -> V_201 = V_201 ;
F_79 ( V_201 , V_43 ) ;
V_112 = F_80 ( V_201 , V_213 , - 1 ) ;
if ( V_112 < 0 ) {
F_18 ( V_206 , L_93 ,
V_112 ) ;
V_43 -> V_201 = NULL ;
F_67 ( V_201 ) ;
return V_112 ;
}
F_72 ( & V_35 -> V_205 ) ;
return 0 ;
}
static int F_81 ( struct V_34 * V_35 ,
struct V_180 * V_181 )
{
struct V_42 * V_43 ;
struct V_33 * V_154 ;
int V_112 ;
F_10 (term, &chain->entities, chain) {
if ( F_41 ( V_154 ) != V_189 )
continue;
V_43 = F_14 ( V_35 , V_154 -> V_36 ) ;
if ( V_43 == NULL ) {
F_18 ( V_71 , L_94
L_95 , V_154 -> V_36 ) ;
continue;
}
V_43 -> V_181 = V_181 ;
V_112 = F_75 ( V_35 , V_43 ) ;
if ( V_112 < 0 )
return V_112 ;
V_154 -> V_201 = V_43 -> V_201 ;
}
return 0 ;
}
static int F_82 ( struct V_34 * V_35 )
{
struct V_180 * V_181 ;
int V_112 ;
F_10 (chain, &dev->chains, list) {
V_112 = F_81 ( V_35 , V_181 ) ;
if ( V_112 < 0 )
return V_112 ;
#ifdef F_62
V_112 = F_83 ( V_181 ) ;
if ( V_112 < 0 ) {
F_18 ( V_71 , L_96
L_91 , V_112 ) ;
}
#endif
}
return 0 ;
}
static int F_84 ( struct V_52 * V_53 ,
const struct V_214 * V_36 )
{
struct V_143 * V_65 = F_85 ( V_53 ) ;
struct V_34 * V_35 ;
int V_112 ;
if ( V_36 -> V_147 && V_36 -> V_215 )
F_16 ( V_183 , L_97
L_98 , V_65 -> V_216 , V_36 -> V_147 ,
V_36 -> V_215 ) ;
else
F_16 ( V_183 , L_99 ,
V_65 -> V_216 ) ;
if ( ( V_35 = F_26 ( sizeof *V_35 , V_31 ) ) == NULL )
return - V_130 ;
F_55 ( & V_35 -> V_38 ) ;
F_55 ( & V_35 -> V_200 ) ;
F_55 ( & V_35 -> V_134 ) ;
F_86 ( & V_35 -> V_205 , 0 ) ;
F_86 ( & V_35 -> V_217 , 0 ) ;
F_86 ( & V_35 -> V_218 , 0 ) ;
V_35 -> V_65 = F_87 ( V_65 ) ;
V_35 -> V_53 = F_29 ( V_53 ) ;
V_35 -> V_118 = V_53 -> V_54 -> V_7 . V_67 ;
V_35 -> V_97 = ( V_219 == - 1 )
? V_36 -> V_220 : V_219 ;
if ( V_65 -> V_221 != NULL )
F_17 ( V_35 -> V_69 , V_65 -> V_221 , sizeof V_35 -> V_69 ) ;
else
snprintf ( V_35 -> V_69 , sizeof V_35 -> V_69 ,
L_100 ,
F_31 ( V_65 -> V_146 . V_147 ) ,
F_31 ( V_65 -> V_146 . V_215 ) ) ;
if ( F_42 ( V_35 ) < 0 ) {
F_16 ( V_183 , L_101
L_102 ) ;
goto error;
}
F_18 ( V_71 , L_103 ,
V_35 -> V_156 >> 8 , V_35 -> V_156 & 0xff ,
V_65 -> V_221 ? V_65 -> V_221 : L_104 ,
F_31 ( V_65 -> V_146 . V_147 ) ,
F_31 ( V_65 -> V_146 . V_215 ) ) ;
if ( V_35 -> V_97 != V_36 -> V_220 ) {
F_18 ( V_71 , L_105
L_106 , V_35 -> V_97 ) ;
F_18 ( V_71 , L_107
L_108 ) ;
}
#ifdef F_62
V_35 -> V_202 . V_35 = & V_53 -> V_35 ;
F_17 ( V_35 -> V_202 . V_222 , V_35 -> V_69 , sizeof( V_35 -> V_202 . V_222 ) ) ;
if ( V_65 -> V_223 )
F_17 ( V_35 -> V_202 . V_223 , V_65 -> V_223 ,
sizeof( V_35 -> V_202 . V_223 ) ) ;
strcpy ( V_35 -> V_202 . V_224 , V_65 -> V_216 ) ;
V_35 -> V_202 . V_225 = F_31 ( V_65 -> V_146 . V_226 ) ;
V_35 -> V_202 . V_227 = V_228 ;
if ( F_88 ( & V_35 -> V_202 ) < 0 )
goto error;
V_35 -> V_201 . V_202 = & V_35 -> V_202 ;
#endif
if ( F_89 ( & V_53 -> V_35 , & V_35 -> V_201 ) < 0 )
goto error;
if ( F_90 ( V_35 ) < 0 )
goto error;
if ( F_54 ( V_35 ) < 0 )
goto error;
if ( F_82 ( V_35 ) < 0 )
goto error;
F_91 ( V_53 , V_35 ) ;
if ( ( V_112 = F_92 ( V_35 ) ) < 0 ) {
F_18 ( V_71 , L_109
L_110
L_111 , V_112 ) ;
}
F_16 ( V_183 , L_112 ) ;
F_93 ( V_65 ) ;
return 0 ;
error:
F_71 ( V_35 ) ;
return - V_229 ;
}
static void F_94 ( struct V_52 * V_53 )
{
struct V_34 * V_35 = F_95 ( V_53 ) ;
F_91 ( V_53 , NULL ) ;
if ( V_53 -> V_54 -> V_7 . V_113 ==
V_114 )
return;
V_35 -> V_230 |= V_231 ;
F_71 ( V_35 ) ;
}
static int F_96 ( struct V_52 * V_53 , T_7 V_232 )
{
struct V_34 * V_35 = F_95 ( V_53 ) ;
struct V_42 * V_43 ;
F_16 ( V_233 , L_113 ,
V_53 -> V_54 -> V_7 . V_67 ) ;
if ( V_53 -> V_54 -> V_7 . V_113 ==
V_234 )
return F_97 ( V_35 ) ;
F_10 (stream, &dev->streams, list) {
if ( V_43 -> V_53 == V_53 )
return F_98 ( V_43 ) ;
}
F_16 ( V_233 , L_114
L_115 ) ;
return - V_68 ;
}
static int F_99 ( struct V_52 * V_53 , int V_235 )
{
struct V_34 * V_35 = F_95 ( V_53 ) ;
struct V_42 * V_43 ;
F_16 ( V_233 , L_116 ,
V_53 -> V_54 -> V_7 . V_67 ) ;
if ( V_53 -> V_54 -> V_7 . V_113 ==
V_234 ) {
if ( V_235 ) {
int V_112 = F_100 ( V_35 ) ;
if ( V_112 < 0 )
return V_112 ;
}
return F_101 ( V_35 ) ;
}
F_10 (stream, &dev->streams, list) {
if ( V_43 -> V_53 == V_53 )
return F_102 ( V_43 , V_235 ) ;
}
F_16 ( V_233 , L_117
L_115 ) ;
return - V_68 ;
}
static int F_103 ( struct V_52 * V_53 )
{
return F_99 ( V_53 , 0 ) ;
}
static int F_104 ( struct V_52 * V_53 )
{
return F_99 ( V_53 , 1 ) ;
}
static int F_105 ( char * V_50 , struct V_236 * V_237 )
{
if ( V_238 == V_239 )
return sprintf ( V_50 , L_118 ) ;
else
return sprintf ( V_50 , L_119 ) ;
}
static int F_106 ( const char * V_240 , struct V_236 * V_237 )
{
if ( strncasecmp ( V_240 , L_120 , strlen ( L_120 ) ) == 0 )
V_240 += strlen ( L_120 ) ;
if ( strcasecmp ( V_240 , L_121 ) == 0 )
V_238 = V_239 ;
else if ( strcasecmp ( V_240 , L_122 ) == 0 )
V_238 = V_241 ;
else
return - V_68 ;
return 0 ;
}
static int T_8 F_107 ( void )
{
int V_112 ;
F_108 () ;
V_112 = F_109 ( & V_115 . V_116 ) ;
if ( V_112 < 0 ) {
F_110 () ;
return V_112 ;
}
F_45 (KERN_INFO DRIVER_DESC L_123 DRIVER_VERSION L_124 ) ;
return 0 ;
}
static void T_9 F_111 ( void )
{
F_112 ( & V_115 . V_116 ) ;
F_110 () ;
}
