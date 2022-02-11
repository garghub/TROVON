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
V_29 = F_10 ( V_13 -> V_3 -> V_7 , V_13 -> V_25 ) ;
if ( V_29 ) {
memcpy ( V_13 -> V_21 , V_29 -> V_32 + V_13 -> V_22 ,
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
static int F_12 ( struct V_12 * V_13 , int V_33 )
{
int V_14 ;
switch ( V_33 ) {
case F_13 ( 'S' , 'P' ) :
V_14 = sizeof( struct V_34 ) ;
break;
case F_13 ( 'C' , 'E' ) :
V_14 = sizeof( struct V_35 ) ;
break;
case F_13 ( 'E' , 'R' ) :
V_14 = sizeof( struct V_36 ) ;
break;
case F_13 ( 'R' , 'R' ) :
V_14 = sizeof( struct V_37 ) ;
break;
case F_13 ( 'P' , 'X' ) :
V_14 = sizeof( struct V_38 ) ;
break;
case F_13 ( 'P' , 'N' ) :
V_14 = sizeof( struct V_39 ) ;
break;
case F_13 ( 'S' , 'L' ) :
V_14 = sizeof( struct V_40 ) ;
break;
case F_13 ( 'N' , 'M' ) :
V_14 = sizeof( struct V_41 ) ;
break;
case F_13 ( 'C' , 'L' ) :
V_14 = sizeof( struct V_42 ) ;
break;
case F_13 ( 'P' , 'L' ) :
V_14 = sizeof( struct V_43 ) ;
break;
case F_13 ( 'T' , 'F' ) :
V_14 = sizeof( struct V_44 ) ;
break;
case F_13 ( 'Z' , 'F' ) :
V_14 = sizeof( struct V_45 ) ;
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
V_33 , V_14 , V_13 -> V_14 ) ;
return - V_26 ;
}
return 0 ;
}
int F_14 ( struct V_10 * V_11 ,
char * V_46 , struct V_3 * V_3 )
{
struct V_12 V_13 ;
struct V_1 * V_2 ;
int V_33 ;
int V_47 = 0 ;
int V_48 = 0 ;
int V_17 = 0 ;
if ( ! F_2 ( V_3 -> V_7 ) -> V_49 )
return 0 ;
* V_46 = 0 ;
F_4 ( & V_13 , V_3 ) ;
F_3 ( V_11 , V_3 , & V_13 ) ;
V_50:
while ( V_13 . V_14 > 2 ) {
V_2 = (struct V_1 * ) V_13 . V_16 ;
if ( V_2 -> V_14 < 3 )
goto V_27;
V_33 = F_15 ( V_13 . V_16 ) ;
if ( F_12 ( & V_13 , V_33 ) )
goto V_51;
V_13 . V_16 += V_2 -> V_14 ;
V_13 . V_14 -= V_2 -> V_14 ;
if ( V_13 . V_14 < 0 )
goto V_27;
switch ( V_33 ) {
case F_13 ( 'R' , 'R' ) :
if ( ( V_2 -> V_4 . V_52 . V_53 [ 0 ] & V_54 ) == 0 )
goto V_27;
break;
case F_13 ( 'S' , 'P' ) :
if ( F_1 ( V_2 , V_3 ) )
goto V_27;
break;
case F_13 ( 'C' , 'E' ) :
V_13 . V_25 = F_16 ( V_2 -> V_4 . V_55 . V_56 ) ;
V_13 . V_22 = F_16 ( V_2 -> V_4 . V_55 . V_57 ) ;
V_13 . V_23 = F_16 ( V_2 -> V_4 . V_55 . V_58 ) ;
break;
case F_13 ( 'N' , 'M' ) :
if ( V_48 )
break;
if ( V_2 -> V_14 < 5 )
break;
if ( V_2 -> V_4 . V_59 . V_53 & 6 )
break;
if ( V_2 -> V_4 . V_59 . V_53 & ~ 1 ) {
F_8 ( L_7 ,
V_2 -> V_4 . V_59 . V_53 ) ;
break;
}
if ( ( strlen ( V_46 ) + V_2 -> V_14 - 5 ) >= 254 ) {
V_48 = 1 ;
break;
}
strncat ( V_46 , V_2 -> V_4 . V_59 . V_60 , V_2 -> V_14 - 5 ) ;
V_47 += V_2 -> V_14 - 5 ;
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
goto V_50;
if ( V_17 == 1 )
return V_47 ;
V_27:
F_7 ( V_13 . V_21 ) ;
return V_17 ;
V_51:
V_17 = - V_26 ;
goto V_27;
}
static int
F_17 ( struct V_10 * V_11 ,
struct V_3 * V_3 , int V_61 )
{
int V_62 = 0 ;
int V_63 , V_33 ;
struct V_3 * V_64 ;
struct V_1 * V_2 ;
int V_65 ;
struct V_12 V_13 ;
int V_17 = 0 ;
if ( ! F_2 ( V_3 -> V_7 ) -> V_49 )
return 0 ;
F_4 ( & V_13 , V_3 ) ;
F_3 ( V_11 , V_3 , & V_13 ) ;
if ( V_61 ) {
V_13 . V_16 += 14 ;
V_13 . V_14 -= 14 ;
if ( V_13 . V_14 < 0 )
V_13 . V_14 = 0 ;
}
V_50:
while ( V_13 . V_14 > 2 ) {
V_2 = (struct V_1 * ) V_13 . V_16 ;
if ( V_2 -> V_14 < 3 )
goto V_27;
V_33 = F_15 ( V_13 . V_16 ) ;
if ( F_12 ( & V_13 , V_33 ) )
goto V_51;
V_13 . V_16 += V_2 -> V_14 ;
V_13 . V_14 -= V_2 -> V_14 ;
if ( V_13 . V_14 < 0 )
goto V_27;
switch ( V_33 ) {
#ifndef F_18
case F_13 ( 'R' , 'R' ) :
if ( ( V_2 -> V_4 . V_52 . V_53 [ 0 ] &
( V_66 | V_67 | V_68 | V_69 ) ) == 0 )
goto V_27;
break;
#endif
case F_13 ( 'S' , 'P' ) :
if ( F_1 ( V_2 , V_3 ) )
goto V_27;
break;
case F_13 ( 'C' , 'E' ) :
V_13 . V_25 = F_16 ( V_2 -> V_4 . V_55 . V_56 ) ;
V_13 . V_22 = F_16 ( V_2 -> V_4 . V_55 . V_57 ) ;
V_13 . V_23 = F_16 ( V_2 -> V_4 . V_55 . V_58 ) ;
break;
case F_13 ( 'E' , 'R' ) :
F_2 ( V_3 -> V_7 ) -> V_49 = 1 ;
F_8 ( V_70 L_8 ) ;
{
int V_71 ;
for ( V_71 = 0 ; V_71 < V_2 -> V_4 . V_72 . V_73 ; V_71 ++ )
F_8 ( L_9 , V_2 -> V_4 . V_72 . V_74 [ V_71 ] ) ;
}
F_8 ( L_10 ) ;
break;
case F_13 ( 'P' , 'X' ) :
V_3 -> V_75 = F_16 ( V_2 -> V_4 . V_76 . V_77 ) ;
F_19 ( V_3 , F_16 ( V_2 -> V_4 . V_76 . V_78 ) ) ;
F_20 ( V_3 , F_16 ( V_2 -> V_4 . V_76 . V_79 ) ) ;
F_21 ( V_3 , F_16 ( V_2 -> V_4 . V_76 . V_80 ) ) ;
break;
case F_13 ( 'P' , 'N' ) :
{
int V_81 , V_82 ;
V_81 = F_16 ( V_2 -> V_4 . V_83 . V_84 ) ;
V_82 = F_16 ( V_2 -> V_4 . V_83 . V_85 ) ;
if ( ( V_82 & ~ 0xff ) && V_81 == 0 ) {
V_3 -> V_86 =
F_22 ( V_82 >> 8 , V_82 & 0xff ) ;
} else {
V_3 -> V_86 =
F_22 ( V_81 , V_82 ) ;
}
}
break;
case F_13 ( 'T' , 'F' ) :
V_63 = 0 ;
if ( V_2 -> V_4 . V_87 . V_53 & V_88 ) {
V_3 -> V_89 . V_90 =
F_23 ( V_2 -> V_4 . V_87 . V_91 [ V_63 ++ ] . time ,
0 ) ;
V_3 -> V_89 . V_92 = 0 ;
}
if ( V_2 -> V_4 . V_87 . V_53 & V_93 ) {
V_3 -> V_94 . V_90 =
F_23 ( V_2 -> V_4 . V_87 . V_91 [ V_63 ++ ] . time ,
0 ) ;
V_3 -> V_94 . V_92 = 0 ;
}
if ( V_2 -> V_4 . V_87 . V_53 & V_95 ) {
V_3 -> V_96 . V_90 =
F_23 ( V_2 -> V_4 . V_87 . V_91 [ V_63 ++ ] . time ,
0 ) ;
V_3 -> V_96 . V_92 = 0 ;
}
if ( V_2 -> V_4 . V_87 . V_53 & V_97 ) {
V_3 -> V_89 . V_90 =
F_23 ( V_2 -> V_4 . V_87 . V_91 [ V_63 ++ ] . time ,
0 ) ;
V_3 -> V_89 . V_92 = 0 ;
}
break;
case F_13 ( 'S' , 'L' ) :
{
int V_98 ;
struct V_99 * V_100 ;
struct V_99 * V_101 ;
V_98 = V_2 -> V_14 - 5 ;
V_100 = & V_2 -> V_4 . V_102 . V_103 ;
V_3 -> V_104 = V_62 ;
while ( V_98 > 1 ) {
V_65 = 0 ;
switch ( V_100 -> V_53 & ~ 1 ) {
case 0 :
V_3 -> V_104 +=
V_100 -> V_14 ;
break;
case 2 :
V_3 -> V_104 += 1 ;
break;
case 4 :
V_3 -> V_104 += 2 ;
break;
case 8 :
V_65 = 1 ;
V_3 -> V_104 += 1 ;
break;
default:
F_8 ( L_11
L_12 ) ;
}
V_98 -= V_100 -> V_14 + 2 ;
V_101 = V_100 ;
V_100 = (struct V_99 * )
( ( ( char * ) V_100 ) + V_100 -> V_14 + 2 ) ;
if ( V_98 < 2 ) {
if ( ( ( V_2 -> V_4 . V_102 .
V_53 & 1 ) != 0 )
&&
( ( V_101 ->
V_53 & 1 ) == 0 ) )
V_3 -> V_104 +=
1 ;
break;
}
if ( ! V_65
&& ( V_101 -> V_53 & 1 ) == 0 )
V_3 -> V_104 += 1 ;
}
}
V_62 = V_3 -> V_104 ;
break;
case F_13 ( 'R' , 'E' ) :
F_8 ( V_105 L_13
L_14 ) ;
goto V_27;
case F_13 ( 'C' , 'L' ) :
F_24 ( V_3 ) -> V_106 =
F_16 ( V_2 -> V_4 . V_107 . V_108 ) ;
V_64 =
F_25 ( V_3 -> V_7 ,
F_24 ( V_3 ) -> V_106 ,
0 ) ;
if ( F_26 ( V_64 ) ) {
V_17 = F_27 ( V_64 ) ;
goto V_27;
}
V_3 -> V_75 = V_64 -> V_75 ;
F_19 ( V_3 , V_64 -> V_109 ) ;
V_3 -> V_110 = V_64 -> V_110 ;
V_3 -> V_111 = V_64 -> V_111 ;
V_3 -> V_86 = V_64 -> V_86 ;
V_3 -> V_104 = V_64 -> V_104 ;
V_3 -> V_112 = V_64 -> V_112 ;
V_3 -> V_96 = V_64 -> V_96 ;
V_3 -> V_89 = V_64 -> V_89 ;
V_3 -> V_94 = V_64 -> V_94 ;
F_28 ( V_64 ) ;
break;
#ifdef F_18
case F_13 ( 'Z' , 'F' ) : {
int V_113 ;
if ( F_2 ( V_3 -> V_7 ) -> V_114 )
break;
V_113 = F_15 ( V_2 -> V_4 . V_115 . V_116 ) ;
if ( V_113 == F_13 ( 'p' , 'z' ) ) {
int V_117 =
F_29 ( & V_2 -> V_4 . V_115 . V_118 [ 1 ] ) ;
if ( V_117 > 17 ) {
F_8 ( V_105 L_15
L_16
L_17 ,
V_117 ) ;
} else {
F_24 ( V_3 ) -> V_119 =
V_120 ;
F_24 ( V_3 ) -> V_121 [ 0 ] =
F_29 ( & V_2 -> V_4 . V_115 . V_118 [ 0 ] ) ;
F_24 ( V_3 ) -> V_121 [ 1 ] =
F_29 ( & V_2 -> V_4 . V_115 . V_118 [ 1 ] ) ;
V_3 -> V_104 =
F_16 ( V_2 -> V_4 . V_115 .
V_122 ) ;
}
} else {
F_8 ( V_105
L_18
L_19 ,
V_2 -> V_4 . V_115 . V_116 [ 0 ] ,
V_2 -> V_4 . V_115 . V_116 [ 1 ] ) ;
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
goto V_50;
if ( V_17 == 1 )
V_17 = 0 ;
V_27:
F_7 ( V_13 . V_21 ) ;
return V_17 ;
V_51:
V_17 = - V_26 ;
goto V_27;
}
static char * F_30 ( char * V_123 , struct V_1 * V_2 , char * V_124 )
{
int V_98 ;
int V_65 ;
struct V_99 * V_101 ;
struct V_99 * V_100 ;
V_98 = V_2 -> V_14 - 5 ;
V_100 = & V_2 -> V_4 . V_102 . V_103 ;
while ( V_98 > 1 ) {
V_65 = 0 ;
switch ( V_100 -> V_53 & ~ 1 ) {
case 0 :
if ( V_100 -> V_14 > V_124 - V_123 )
return NULL ;
memcpy ( V_123 , V_100 -> V_125 , V_100 -> V_14 ) ;
V_123 += V_100 -> V_14 ;
break;
case 2 :
if ( V_123 >= V_124 )
return NULL ;
* V_123 ++ = '.' ;
break;
case 4 :
if ( 2 > V_124 - V_123 )
return NULL ;
* V_123 ++ = '.' ;
* V_123 ++ = '.' ;
break;
case 8 :
if ( V_123 >= V_124 )
return NULL ;
V_65 = 1 ;
* V_123 ++ = '/' ;
break;
default:
F_8 ( L_20 ,
V_100 -> V_53 ) ;
}
V_98 -= V_100 -> V_14 + 2 ;
V_101 = V_100 ;
V_100 = (struct V_99 * ) ( ( char * ) V_100 + V_100 -> V_14 + 2 ) ;
if ( V_98 < 2 ) {
if ( ( ! V_65 ) && ( V_2 -> V_4 . V_102 . V_53 & 1 ) &&
! ( V_101 -> V_53 & 1 ) ) {
if ( V_123 >= V_124 )
return NULL ;
* V_123 ++ = '/' ;
}
break;
}
if ( ! V_65 && ! ( V_101 -> V_53 & 1 ) ) {
if ( V_123 >= V_124 )
return NULL ;
* V_123 ++ = '/' ;
}
}
return V_123 ;
}
int F_31 ( struct V_10 * V_11 , struct V_3 * V_3 )
{
int V_126 = F_17 ( V_11 , V_3 , 0 ) ;
if ( ( F_2 ( V_3 -> V_7 ) -> V_8 == - 1 )
&& ( F_2 ( V_3 -> V_7 ) -> V_49 == 2 ) ) {
V_126 = F_17 ( V_11 , V_3 , 14 ) ;
}
return V_126 ;
}
static int F_32 ( struct V_127 * V_127 , struct V_128 * V_128 )
{
struct V_3 * V_3 = V_128 -> V_129 -> V_130 ;
struct V_131 * V_132 = F_24 ( V_3 ) ;
struct V_133 * V_134 = F_2 ( V_3 -> V_7 ) ;
char * V_103 = F_33 ( V_128 ) ;
unsigned long V_135 = F_34 ( V_3 ) ;
struct V_28 * V_29 ;
char * V_123 = V_103 ;
unsigned char * V_136 ;
struct V_10 * V_137 ;
unsigned long V_138 , V_57 ;
int V_33 ;
struct V_1 * V_2 ;
struct V_12 V_13 ;
int V_17 ;
if ( ! V_134 -> V_49 )
goto error;
F_4 ( & V_13 , V_3 ) ;
V_138 = V_132 -> V_139 ;
V_29 = F_10 ( V_3 -> V_7 , V_138 ) ;
if ( ! V_29 )
goto V_140;
V_57 = V_132 -> V_141 ;
V_136 = ( unsigned char * ) V_29 -> V_32 + V_57 ;
V_137 = (struct V_10 * ) V_136 ;
if ( V_57 + * V_136 > V_135 )
goto V_142;
F_3 ( V_137 , V_3 , & V_13 ) ;
V_50:
while ( V_13 . V_14 > 2 ) {
V_2 = (struct V_1 * ) V_13 . V_16 ;
if ( V_2 -> V_14 < 3 )
goto V_27;
V_33 = F_15 ( V_13 . V_16 ) ;
if ( F_12 ( & V_13 , V_33 ) )
goto V_27;
V_13 . V_16 += V_2 -> V_14 ;
V_13 . V_14 -= V_2 -> V_14 ;
if ( V_13 . V_14 < 0 )
goto V_27;
switch ( V_33 ) {
case F_13 ( 'R' , 'R' ) :
if ( ( V_2 -> V_4 . V_52 . V_53 [ 0 ] & V_68 ) == 0 )
goto V_27;
break;
case F_13 ( 'S' , 'P' ) :
if ( F_1 ( V_2 , V_3 ) )
goto V_27;
break;
case F_13 ( 'S' , 'L' ) :
V_123 = F_30 ( V_123 , V_2 ,
V_103 + ( V_143 - 1 ) ) ;
if ( V_123 == NULL )
goto V_27;
break;
case F_13 ( 'C' , 'E' ) :
V_13 . V_25 = F_16 ( V_2 -> V_4 . V_55 . V_56 ) ;
V_13 . V_22 = F_16 ( V_2 -> V_4 . V_55 . V_57 ) ;
V_13 . V_23 = F_16 ( V_2 -> V_4 . V_55 . V_58 ) ;
default:
break;
}
}
V_17 = F_5 ( & V_13 ) ;
if ( V_17 == 0 )
goto V_50;
if ( V_17 < 0 )
goto V_144;
if ( V_123 == V_103 )
goto V_144;
F_35 ( V_29 ) ;
* V_123 = '\0' ;
F_36 ( V_128 ) ;
F_37 ( V_128 ) ;
F_38 ( V_128 ) ;
return 0 ;
V_27:
F_7 ( V_13 . V_21 ) ;
goto V_144;
V_140:
F_8 ( L_21 ) ;
goto V_144;
V_142:
F_8 ( L_22 ) ;
V_144:
F_35 ( V_29 ) ;
error:
F_39 ( V_128 ) ;
F_37 ( V_128 ) ;
F_38 ( V_128 ) ;
return - V_26 ;
}
