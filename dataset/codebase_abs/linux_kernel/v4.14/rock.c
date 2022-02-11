static int F_1 ( struct V_1 * V_2 , struct V_3 * V_3 )
{
if ( V_2 -> V_4 . V_5 . V_6 [ 0 ] != 0xbe )
return - 1 ;
if ( V_2 -> V_4 . V_5 . V_6 [ 1 ] != 0xef )
return - 1 ;
F_2 ( V_3 -> V_7 ) -> V_8 = V_2 -> V_4 . V_5 . V_9 ;
return 0 ;
}
static void F_3 ( struct V_10 * V_11 ,
struct V_3 * V_3 , struct V_12 * V_13 )
{
V_13 -> V_14 = sizeof( struct V_10 ) + V_11 -> V_15 [ 0 ] ;
if ( V_13 -> V_14 & 1 )
( V_13 -> V_14 ) ++ ;
V_13 -> V_16 = ( unsigned char * ) V_11 + V_13 -> V_14 ;
V_13 -> V_14 = * ( ( unsigned char * ) V_11 ) - V_13 -> V_14 ;
if ( V_13 -> V_14 < 0 )
V_13 -> V_14 = 0 ;
if ( F_2 ( V_3 -> V_7 ) -> V_8 != - 1 ) {
V_13 -> V_14 -= F_2 ( V_3 -> V_7 ) -> V_8 ;
V_13 -> V_16 += F_2 ( V_3 -> V_7 ) -> V_8 ;
if ( V_13 -> V_14 < 0 )
V_13 -> V_14 = 0 ;
}
}
static void F_4 ( struct V_12 * V_13 , struct V_3 * V_3 )
{
memset ( V_13 , 0 , sizeof( * V_13 ) ) ;
V_13 -> V_3 = V_3 ;
}
static int F_5 ( struct V_12 * V_13 )
{
int V_17 = 1 ;
int V_18 = 1 << V_13 -> V_3 -> V_19 ;
const int V_20 = F_6 ( struct V_1 , V_4 ) ;
F_7 ( V_13 -> V_21 ) ;
V_13 -> V_21 = NULL ;
if ( ( unsigned ) V_13 -> V_22 > V_18 - V_20 ||
( unsigned ) V_13 -> V_23 > V_18 ||
( unsigned ) ( V_13 -> V_22 + V_13 -> V_23 ) > V_18 ) {
F_8 ( V_24 L_1
L_2 ,
V_13 -> V_25 , V_13 -> V_22 , V_13 -> V_23 ) ;
V_17 = - V_26 ;
goto V_27;
}
if ( V_13 -> V_25 ) {
struct V_28 * V_29 ;
V_13 -> V_21 = F_9 ( V_13 -> V_23 , V_30 ) ;
if ( ! V_13 -> V_21 ) {
V_17 = - V_31 ;
goto V_27;
}
V_17 = - V_26 ;
if ( ++ V_13 -> V_32 >= V_33 )
goto V_27;
V_29 = F_10 ( V_13 -> V_3 -> V_7 , V_13 -> V_25 ) ;
if ( V_29 ) {
memcpy ( V_13 -> V_21 , V_29 -> V_34 + V_13 -> V_22 ,
V_13 -> V_23 ) ;
F_11 ( V_29 ) ;
V_13 -> V_16 = V_13 -> V_21 ;
V_13 -> V_14 = V_13 -> V_23 ;
V_13 -> V_25 = 0 ;
V_13 -> V_23 = 0 ;
V_13 -> V_22 = 0 ;
return 0 ;
}
F_8 ( L_3 ) ;
}
V_27:
F_7 ( V_13 -> V_21 ) ;
V_13 -> V_21 = NULL ;
return V_17 ;
}
static int F_12 ( struct V_12 * V_13 , int V_35 )
{
int V_14 ;
switch ( V_35 ) {
case F_13 ( 'S' , 'P' ) :
V_14 = sizeof( struct V_36 ) ;
break;
case F_13 ( 'C' , 'E' ) :
V_14 = sizeof( struct V_37 ) ;
break;
case F_13 ( 'E' , 'R' ) :
V_14 = sizeof( struct V_38 ) ;
break;
case F_13 ( 'R' , 'R' ) :
V_14 = sizeof( struct V_39 ) ;
break;
case F_13 ( 'P' , 'X' ) :
V_14 = sizeof( struct V_40 ) ;
break;
case F_13 ( 'P' , 'N' ) :
V_14 = sizeof( struct V_41 ) ;
break;
case F_13 ( 'S' , 'L' ) :
V_14 = sizeof( struct V_42 ) ;
break;
case F_13 ( 'N' , 'M' ) :
V_14 = sizeof( struct V_43 ) ;
break;
case F_13 ( 'C' , 'L' ) :
V_14 = sizeof( struct V_44 ) ;
break;
case F_13 ( 'P' , 'L' ) :
V_14 = sizeof( struct V_45 ) ;
break;
case F_13 ( 'T' , 'F' ) :
V_14 = sizeof( struct V_46 ) ;
break;
case F_13 ( 'Z' , 'F' ) :
V_14 = sizeof( struct V_47 ) ;
break;
default:
V_14 = 0 ;
break;
}
V_14 += F_6 ( struct V_1 , V_4 ) ;
if ( V_14 > V_13 -> V_14 ) {
F_8 ( V_24 L_4
L_5 ) ;
F_8 ( V_24 L_6 ,
V_35 , V_14 , V_13 -> V_14 ) ;
return - V_26 ;
}
return 0 ;
}
int F_14 ( struct V_10 * V_11 ,
char * V_48 , struct V_3 * V_3 )
{
struct V_12 V_13 ;
struct V_1 * V_2 ;
int V_35 ;
int V_49 = 0 ;
int V_50 = 0 ;
int V_17 = 0 ;
char * V_51 ;
int V_14 ;
if ( ! F_2 ( V_3 -> V_7 ) -> V_52 )
return 0 ;
* V_48 = 0 ;
F_4 ( & V_13 , V_3 ) ;
F_3 ( V_11 , V_3 , & V_13 ) ;
V_53:
while ( V_13 . V_14 > 2 ) {
V_2 = (struct V_1 * ) V_13 . V_16 ;
if ( V_2 -> V_14 < 3 )
goto V_27;
V_35 = F_15 ( V_13 . V_16 ) ;
if ( F_12 ( & V_13 , V_35 ) )
goto V_54;
V_13 . V_16 += V_2 -> V_14 ;
V_13 . V_14 -= V_2 -> V_14 ;
if ( V_13 . V_14 < 0 )
goto V_27;
switch ( V_35 ) {
case F_13 ( 'R' , 'R' ) :
if ( ( V_2 -> V_4 . V_55 . V_56 [ 0 ] & V_57 ) == 0 )
goto V_27;
break;
case F_13 ( 'S' , 'P' ) :
if ( F_1 ( V_2 , V_3 ) )
goto V_27;
break;
case F_13 ( 'C' , 'E' ) :
V_13 . V_25 = F_16 ( V_2 -> V_4 . V_58 . V_59 ) ;
V_13 . V_22 = F_16 ( V_2 -> V_4 . V_58 . V_60 ) ;
V_13 . V_23 = F_16 ( V_2 -> V_4 . V_58 . V_61 ) ;
break;
case F_13 ( 'N' , 'M' ) :
if ( V_50 )
break;
if ( V_2 -> V_14 < 5 )
break;
if ( V_2 -> V_4 . V_62 . V_56 & 6 )
break;
if ( V_2 -> V_4 . V_62 . V_56 & ~ 1 ) {
F_8 ( L_7 ,
V_2 -> V_4 . V_62 . V_56 ) ;
break;
}
V_14 = V_2 -> V_14 - 5 ;
if ( V_49 + V_14 >= 254 ) {
V_50 = 1 ;
break;
}
V_51 = memchr ( V_2 -> V_4 . V_62 . V_63 , '\0' , V_14 ) ;
if ( F_17 ( V_51 ) )
V_14 = V_51 - V_2 -> V_4 . V_62 . V_63 ;
memcpy ( V_48 + V_49 , V_2 -> V_4 . V_62 . V_63 , V_14 ) ;
V_49 += V_14 ;
V_48 [ V_49 ] = '\0' ;
break;
case F_13 ( 'R' , 'E' ) :
F_7 ( V_13 . V_21 ) ;
return - 1 ;
default:
break;
}
}
V_17 = F_5 ( & V_13 ) ;
if ( V_17 == 0 )
goto V_53;
if ( V_17 == 1 )
return V_49 ;
V_27:
F_7 ( V_13 . V_21 ) ;
return V_17 ;
V_54:
V_17 = - V_26 ;
goto V_27;
}
static int
F_18 ( struct V_10 * V_11 ,
struct V_3 * V_3 , int V_56 )
{
int V_64 = 0 ;
int V_65 , V_35 ;
unsigned int V_66 ;
struct V_3 * V_67 ;
struct V_1 * V_2 ;
int V_68 ;
struct V_12 V_13 ;
int V_17 = 0 ;
if ( ! F_2 ( V_3 -> V_7 ) -> V_52 )
return 0 ;
F_4 ( & V_13 , V_3 ) ;
F_3 ( V_11 , V_3 , & V_13 ) ;
if ( V_56 & V_69 ) {
V_13 . V_16 += 14 ;
V_13 . V_14 -= 14 ;
if ( V_13 . V_14 < 0 )
V_13 . V_14 = 0 ;
}
V_53:
while ( V_13 . V_14 > 2 ) {
V_2 = (struct V_1 * ) V_13 . V_16 ;
if ( V_2 -> V_14 < 3 )
goto V_27;
V_35 = F_15 ( V_13 . V_16 ) ;
if ( F_12 ( & V_13 , V_35 ) )
goto V_54;
V_13 . V_16 += V_2 -> V_14 ;
V_13 . V_14 -= V_2 -> V_14 ;
if ( V_13 . V_14 < 0 )
goto V_27;
switch ( V_35 ) {
#ifndef F_19
case F_13 ( 'R' , 'R' ) :
if ( ( V_2 -> V_4 . V_55 . V_56 [ 0 ] &
( V_70 | V_71 | V_72 | V_73 ) ) == 0 )
goto V_27;
break;
#endif
case F_13 ( 'S' , 'P' ) :
if ( F_1 ( V_2 , V_3 ) )
goto V_27;
break;
case F_13 ( 'C' , 'E' ) :
V_13 . V_25 = F_16 ( V_2 -> V_4 . V_58 . V_59 ) ;
V_13 . V_22 = F_16 ( V_2 -> V_4 . V_58 . V_60 ) ;
V_13 . V_23 = F_16 ( V_2 -> V_4 . V_58 . V_61 ) ;
break;
case F_13 ( 'E' , 'R' ) :
if ( V_2 -> V_4 . V_74 . V_75 + F_6 ( struct V_1 , V_4 . V_74 . V_76 ) > V_2 -> V_14 )
goto V_27;
F_2 ( V_3 -> V_7 ) -> V_52 = 1 ;
F_8 ( V_77 L_8 ) ;
{
int V_51 ;
for ( V_51 = 0 ; V_51 < V_2 -> V_4 . V_74 . V_75 ; V_51 ++ )
F_8 ( V_78 L_9 , V_2 -> V_4 . V_74 . V_76 [ V_51 ] ) ;
}
F_8 ( V_78 L_10 ) ;
break;
case F_13 ( 'P' , 'X' ) :
V_3 -> V_79 = F_16 ( V_2 -> V_4 . V_80 . V_81 ) ;
F_20 ( V_3 , F_16 ( V_2 -> V_4 . V_80 . V_82 ) ) ;
F_21 ( V_3 , F_16 ( V_2 -> V_4 . V_80 . V_83 ) ) ;
F_22 ( V_3 , F_16 ( V_2 -> V_4 . V_80 . V_84 ) ) ;
break;
case F_13 ( 'P' , 'N' ) :
{
int V_85 , V_86 ;
V_85 = F_16 ( V_2 -> V_4 . V_87 . V_88 ) ;
V_86 = F_16 ( V_2 -> V_4 . V_87 . V_89 ) ;
if ( ( V_86 & ~ 0xff ) && V_85 == 0 ) {
V_3 -> V_90 =
F_23 ( V_86 >> 8 , V_86 & 0xff ) ;
} else {
V_3 -> V_90 =
F_23 ( V_85 , V_86 ) ;
}
}
break;
case F_13 ( 'T' , 'F' ) :
V_65 = 0 ;
if ( V_2 -> V_4 . V_91 . V_56 & V_92 ) {
V_3 -> V_93 . V_94 =
F_24 ( V_2 -> V_4 . V_91 . V_95 [ V_65 ++ ] . time ,
0 ) ;
V_3 -> V_93 . V_96 = 0 ;
}
if ( V_2 -> V_4 . V_91 . V_56 & V_97 ) {
V_3 -> V_98 . V_94 =
F_24 ( V_2 -> V_4 . V_91 . V_95 [ V_65 ++ ] . time ,
0 ) ;
V_3 -> V_98 . V_96 = 0 ;
}
if ( V_2 -> V_4 . V_91 . V_56 & V_99 ) {
V_3 -> V_100 . V_94 =
F_24 ( V_2 -> V_4 . V_91 . V_95 [ V_65 ++ ] . time ,
0 ) ;
V_3 -> V_100 . V_96 = 0 ;
}
if ( V_2 -> V_4 . V_91 . V_56 & V_101 ) {
V_3 -> V_93 . V_94 =
F_24 ( V_2 -> V_4 . V_91 . V_95 [ V_65 ++ ] . time ,
0 ) ;
V_3 -> V_93 . V_96 = 0 ;
}
break;
case F_13 ( 'S' , 'L' ) :
{
int V_102 ;
struct V_103 * V_104 ;
struct V_103 * V_105 ;
V_102 = V_2 -> V_14 - 5 ;
V_104 = & V_2 -> V_4 . V_106 . V_107 ;
V_3 -> V_108 = V_64 ;
while ( V_102 > 1 ) {
V_68 = 0 ;
switch ( V_104 -> V_56 & ~ 1 ) {
case 0 :
V_3 -> V_108 +=
V_104 -> V_14 ;
break;
case 2 :
V_3 -> V_108 += 1 ;
break;
case 4 :
V_3 -> V_108 += 2 ;
break;
case 8 :
V_68 = 1 ;
V_3 -> V_108 += 1 ;
break;
default:
F_8 ( L_11
L_12 ) ;
}
V_102 -= V_104 -> V_14 + 2 ;
V_105 = V_104 ;
V_104 = (struct V_103 * )
( ( ( char * ) V_104 ) + V_104 -> V_14 + 2 ) ;
if ( V_102 < 2 ) {
if ( ( ( V_2 -> V_4 . V_106 .
V_56 & 1 ) != 0 )
&&
( ( V_105 ->
V_56 & 1 ) == 0 ) )
V_3 -> V_108 +=
1 ;
break;
}
if ( ! V_68
&& ( V_105 -> V_56 & 1 ) == 0 )
V_3 -> V_108 += 1 ;
}
}
V_64 = V_3 -> V_108 ;
break;
case F_13 ( 'R' , 'E' ) :
F_8 ( V_109 L_13
L_14 ) ;
goto V_27;
case F_13 ( 'C' , 'L' ) :
if ( V_56 & V_110 ) {
F_8 ( V_111
L_15
L_16 ) ;
goto V_54;
}
V_66 = F_16 ( V_2 -> V_4 . V_112 . V_113 ) ;
if ( V_66 == F_25 ( V_3 ) -> V_114 &&
F_25 ( V_3 ) -> V_115 == 0 ) {
F_8 ( V_111
L_17
L_18 ) ;
goto V_54;
}
F_25 ( V_3 ) -> V_116 = V_66 ;
V_67 = F_26 ( V_3 -> V_7 , V_66 , 0 ) ;
if ( F_27 ( V_67 ) ) {
V_17 = F_28 ( V_67 ) ;
goto V_27;
}
V_3 -> V_79 = V_67 -> V_79 ;
F_20 ( V_3 , V_67 -> V_117 ) ;
V_3 -> V_118 = V_67 -> V_118 ;
V_3 -> V_119 = V_67 -> V_119 ;
V_3 -> V_90 = V_67 -> V_90 ;
V_3 -> V_108 = V_67 -> V_108 ;
V_3 -> V_120 = V_67 -> V_120 ;
V_3 -> V_100 = V_67 -> V_100 ;
V_3 -> V_93 = V_67 -> V_93 ;
V_3 -> V_98 = V_67 -> V_98 ;
F_29 ( V_67 ) ;
break;
#ifdef F_19
case F_13 ( 'Z' , 'F' ) : {
int V_121 ;
if ( F_2 ( V_3 -> V_7 ) -> V_122 )
break;
V_121 = F_15 ( V_2 -> V_4 . V_123 . V_124 ) ;
if ( V_121 == F_13 ( 'p' , 'z' ) ) {
int V_125 =
F_30 ( & V_2 -> V_4 . V_123 . V_126 [ 1 ] ) ;
if ( V_125 > 17 ) {
F_8 ( V_109 L_19
L_20
L_21 ,
V_125 ) ;
} else {
F_25 ( V_3 ) -> V_127 =
V_128 ;
F_25 ( V_3 ) -> V_129 [ 0 ] =
F_30 ( & V_2 -> V_4 . V_123 . V_126 [ 0 ] ) ;
F_25 ( V_3 ) -> V_129 [ 1 ] =
F_30 ( & V_2 -> V_4 . V_123 . V_126 [ 1 ] ) ;
V_3 -> V_108 =
F_16 ( V_2 -> V_4 . V_123 .
V_130 ) ;
}
} else {
F_8 ( V_109
L_22
L_23 ,
V_2 -> V_4 . V_123 . V_124 [ 0 ] ,
V_2 -> V_4 . V_123 . V_124 [ 1 ] ) ;
}
break;
}
#endif
default:
break;
}
}
V_17 = F_5 ( & V_13 ) ;
if ( V_17 == 0 )
goto V_53;
if ( V_17 == 1 )
V_17 = 0 ;
V_27:
F_7 ( V_13 . V_21 ) ;
return V_17 ;
V_54:
V_17 = - V_26 ;
goto V_27;
}
static char * F_31 ( char * V_131 , struct V_1 * V_2 , char * V_132 )
{
int V_102 ;
int V_68 ;
struct V_103 * V_105 ;
struct V_103 * V_104 ;
V_102 = V_2 -> V_14 - 5 ;
V_104 = & V_2 -> V_4 . V_106 . V_107 ;
while ( V_102 > 1 ) {
V_68 = 0 ;
switch ( V_104 -> V_56 & ~ 1 ) {
case 0 :
if ( V_104 -> V_14 > V_132 - V_131 )
return NULL ;
memcpy ( V_131 , V_104 -> V_133 , V_104 -> V_14 ) ;
V_131 += V_104 -> V_14 ;
break;
case 2 :
if ( V_131 >= V_132 )
return NULL ;
* V_131 ++ = '.' ;
break;
case 4 :
if ( 2 > V_132 - V_131 )
return NULL ;
* V_131 ++ = '.' ;
* V_131 ++ = '.' ;
break;
case 8 :
if ( V_131 >= V_132 )
return NULL ;
V_68 = 1 ;
* V_131 ++ = '/' ;
break;
default:
F_8 ( L_24 ,
V_104 -> V_56 ) ;
}
V_102 -= V_104 -> V_14 + 2 ;
V_105 = V_104 ;
V_104 = (struct V_103 * ) ( ( char * ) V_104 + V_104 -> V_14 + 2 ) ;
if ( V_102 < 2 ) {
if ( ( ! V_68 ) && ( V_2 -> V_4 . V_106 . V_56 & 1 ) &&
! ( V_105 -> V_56 & 1 ) ) {
if ( V_131 >= V_132 )
return NULL ;
* V_131 ++ = '/' ;
}
break;
}
if ( ! V_68 && ! ( V_105 -> V_56 & 1 ) ) {
if ( V_131 >= V_132 )
return NULL ;
* V_131 ++ = '/' ;
}
}
return V_131 ;
}
int F_32 ( struct V_10 * V_11 , struct V_3 * V_3 ,
int V_134 )
{
int V_56 = V_134 ? V_110 : 0 ;
int V_135 = F_18 ( V_11 , V_3 , V_56 ) ;
if ( ( F_2 ( V_3 -> V_7 ) -> V_8 == - 1 )
&& ( F_2 ( V_3 -> V_7 ) -> V_52 == 2 ) ) {
V_135 = F_18 ( V_11 , V_3 ,
V_56 | V_69 ) ;
}
return V_135 ;
}
static int F_33 ( struct V_136 * V_136 , struct V_137 * V_137 )
{
struct V_3 * V_3 = V_137 -> V_138 -> V_139 ;
struct V_140 * V_141 = F_25 ( V_3 ) ;
struct V_142 * V_143 = F_2 ( V_3 -> V_7 ) ;
char * V_107 = F_34 ( V_137 ) ;
unsigned long V_144 = F_35 ( V_3 ) ;
struct V_28 * V_29 ;
char * V_131 = V_107 ;
unsigned char * V_145 ;
struct V_10 * V_146 ;
unsigned long V_147 , V_60 ;
int V_35 ;
struct V_1 * V_2 ;
struct V_12 V_13 ;
int V_17 ;
if ( ! V_143 -> V_52 )
goto error;
F_4 ( & V_13 , V_3 ) ;
V_147 = V_141 -> V_114 ;
V_29 = F_10 ( V_3 -> V_7 , V_147 ) ;
if ( ! V_29 )
goto V_148;
V_60 = V_141 -> V_115 ;
V_145 = ( unsigned char * ) V_29 -> V_34 + V_60 ;
V_146 = (struct V_10 * ) V_145 ;
if ( V_60 + * V_145 > V_144 )
goto V_149;
F_3 ( V_146 , V_3 , & V_13 ) ;
V_53:
while ( V_13 . V_14 > 2 ) {
V_2 = (struct V_1 * ) V_13 . V_16 ;
if ( V_2 -> V_14 < 3 )
goto V_27;
V_35 = F_15 ( V_13 . V_16 ) ;
if ( F_12 ( & V_13 , V_35 ) )
goto V_27;
V_13 . V_16 += V_2 -> V_14 ;
V_13 . V_14 -= V_2 -> V_14 ;
if ( V_13 . V_14 < 0 )
goto V_27;
switch ( V_35 ) {
case F_13 ( 'R' , 'R' ) :
if ( ( V_2 -> V_4 . V_55 . V_56 [ 0 ] & V_72 ) == 0 )
goto V_27;
break;
case F_13 ( 'S' , 'P' ) :
if ( F_1 ( V_2 , V_3 ) )
goto V_27;
break;
case F_13 ( 'S' , 'L' ) :
V_131 = F_31 ( V_131 , V_2 ,
V_107 + ( V_150 - 1 ) ) ;
if ( V_131 == NULL )
goto V_27;
break;
case F_13 ( 'C' , 'E' ) :
V_13 . V_25 = F_16 ( V_2 -> V_4 . V_58 . V_59 ) ;
V_13 . V_22 = F_16 ( V_2 -> V_4 . V_58 . V_60 ) ;
V_13 . V_23 = F_16 ( V_2 -> V_4 . V_58 . V_61 ) ;
default:
break;
}
}
V_17 = F_5 ( & V_13 ) ;
if ( V_17 == 0 )
goto V_53;
if ( V_17 < 0 )
goto V_151;
if ( V_131 == V_107 )
goto V_151;
F_36 ( V_29 ) ;
* V_131 = '\0' ;
F_37 ( V_137 ) ;
F_38 ( V_137 ) ;
return 0 ;
V_27:
F_7 ( V_13 . V_21 ) ;
goto V_151;
V_148:
F_8 ( L_25 ) ;
goto V_151;
V_149:
F_8 ( L_26 ) ;
V_151:
F_36 ( V_29 ) ;
error:
F_39 ( V_137 ) ;
F_38 ( V_137 ) ;
return - V_26 ;
}
