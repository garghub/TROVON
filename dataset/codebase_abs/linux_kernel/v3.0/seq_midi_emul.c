void
F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 )
{
struct V_7 * V_8 ;
void * V_9 ;
int V_10 = 0 ;
if ( V_4 == NULL || V_6 == NULL ) {
F_2 ( L_1 ) ;
return;
}
if ( V_6 -> V_11 == NULL )
return;
if ( F_3 ( V_4 ) ) {
V_10 = V_4 -> V_12 . V_13 . V_14 ;
if ( V_10 >= V_6 -> V_15 ) {
F_2 ( L_2 ,
V_10 , V_6 -> V_15 ) ;
return;
}
}
V_8 = V_6 -> V_11 + V_10 ;
V_9 = V_6 -> V_16 ;
if ( V_4 -> type == V_17 )
return;
if ( V_4 -> type == V_18 && V_4 -> V_12 . V_13 . V_19 == 0 )
V_4 -> type = V_20 ;
if ( V_4 -> type == V_18 ||
V_4 -> type == V_20 ||
V_4 -> type == V_21 ) {
if ( V_4 -> V_12 . V_13 . V_13 >= 128 )
return;
}
switch ( V_4 -> type ) {
case V_18 :
if ( V_8 -> V_13 [ V_4 -> V_12 . V_13 . V_13 ] & V_22 ) {
if ( V_2 -> V_23 )
V_2 -> V_23 ( V_9 , V_4 -> V_12 . V_13 . V_13 , 0 , V_8 ) ;
}
V_8 -> V_13 [ V_4 -> V_12 . V_13 . V_13 ] = V_22 ;
if ( V_2 -> V_24 )
V_2 -> V_24 ( V_9 , V_4 -> V_12 . V_13 . V_13 , V_4 -> V_12 . V_13 . V_19 , V_8 ) ;
break;
case V_20 :
if ( ! ( V_8 -> V_13 [ V_4 -> V_12 . V_13 . V_13 ] & V_22 ) )
break;
if ( V_2 -> V_23 )
V_23 ( V_2 , V_9 , V_8 , V_4 -> V_12 . V_13 . V_13 , V_4 -> V_12 . V_13 . V_19 ) ;
break;
case V_21 :
if ( V_2 -> V_25 )
V_2 -> V_25 ( V_9 , V_4 -> V_12 . V_13 . V_13 , V_4 -> V_12 . V_13 . V_19 , V_8 ) ;
break;
case V_26 :
F_4 ( V_2 , V_9 , V_6 , V_8 ,
V_4 -> V_12 . V_27 . V_28 , V_4 -> V_12 . V_27 . V_29 ) ;
break;
case V_30 :
V_8 -> V_31 = V_4 -> V_12 . V_27 . V_29 ;
break;
case V_32 :
V_8 -> V_33 = V_4 -> V_12 . V_27 . V_29 ;
if ( V_2 -> V_27 )
V_2 -> V_27 ( V_9 , V_34 , V_8 ) ;
break;
case V_35 :
V_8 -> V_36 = V_4 -> V_12 . V_27 . V_29 ;
if ( V_2 -> V_27 )
V_2 -> V_27 ( V_9 , V_37 , V_8 ) ;
break;
case V_38 :
if ( V_4 -> V_12 . V_27 . V_28 < 32 ) {
V_8 -> V_27 [ V_4 -> V_12 . V_27 . V_28 + 32 ] =
V_4 -> V_12 . V_27 . V_29 & 0x7f ;
F_4 ( V_2 , V_9 , V_6 , V_8 ,
V_4 -> V_12 . V_27 . V_28 ,
( ( V_4 -> V_12 . V_27 . V_29 >> 7 ) & 0x7f ) ) ;
} else
F_4 ( V_2 , V_9 , V_6 , V_8 ,
V_4 -> V_12 . V_27 . V_28 ,
V_4 -> V_12 . V_27 . V_29 ) ;
break;
case V_39 :
V_8 -> V_40 = V_41 ;
V_8 -> V_27 [ V_42 ]
= ( V_4 -> V_12 . V_27 . V_29 >> 7 ) & 0x7f ;
V_8 -> V_27 [ V_43 ]
= V_4 -> V_12 . V_27 . V_29 & 0x7f ;
V_8 -> V_27 [ V_44 ]
= ( V_4 -> V_12 . V_27 . V_28 >> 7 ) & 0x7f ;
V_8 -> V_27 [ V_45 ]
= V_4 -> V_12 . V_27 . V_28 & 0x7f ;
F_5 ( V_2 , V_9 , V_8 , V_6 ) ;
break;
case V_46 :
V_8 -> V_40 = V_47 ;
V_8 -> V_27 [ V_42 ]
= ( V_4 -> V_12 . V_27 . V_29 >> 7 ) & 0x7f ;
V_8 -> V_27 [ V_43 ]
= V_4 -> V_12 . V_27 . V_29 & 0x7f ;
V_8 -> V_27 [ V_48 ]
= ( V_4 -> V_12 . V_27 . V_28 >> 7 ) & 0x7f ;
V_8 -> V_27 [ V_49 ]
= V_4 -> V_12 . V_27 . V_28 & 0x7f ;
F_6 ( V_2 , V_9 , V_8 , V_6 ) ;
break;
case V_50 :
if ( ( V_4 -> V_51 & V_52 ) == V_53 ) {
unsigned char V_54 [ 64 ] ;
int V_55 ;
V_55 = F_7 ( V_4 , sizeof( V_54 ) , V_54 , 1 , 0 ) ;
if ( V_55 > 0 )
F_8 ( V_2 , V_9 , V_54 , V_55 , V_6 ) ;
}
break;
case V_56 :
case V_57 :
case V_58 :
case V_59 :
case V_60 :
case V_61 :
case V_62 :
case V_63 :
case V_64 :
case V_65 :
goto V_66;
case V_67 :
break;
case V_68 :
case V_69 :
case V_70 :
case V_71 :
case V_72 :
case V_73 :
case V_74 :
V_66:
default:
break;
}
}
static void
V_23 ( struct V_1 * V_2 , void * V_9 , struct V_7 * V_8 ,
int V_13 , int V_75 )
{
if ( V_8 -> V_76 ) {
V_8 -> V_13 [ V_13 ] |= V_77 ;
} else if ( V_8 -> V_13 [ V_13 ] & V_78 ) {
V_8 -> V_13 [ V_13 ] |= V_77 ;
} else {
V_8 -> V_13 [ V_13 ] = 0 ;
if ( V_2 -> V_23 )
V_2 -> V_23 ( V_9 , V_13 , V_75 , V_8 ) ;
}
}
static void
F_4 ( struct V_1 * V_2 , void * V_9 , struct V_5 * V_79 ,
struct V_7 * V_8 , int V_27 , int V_29 )
{
int V_80 ;
if ( ( V_27 >= 64 && V_27 <= 69 ) || ( V_27 >= 80 && V_27 <= 83 ) ) {
V_29 = ( V_29 >= 64 ) ? 127 : 0 ;
}
V_8 -> V_27 [ V_27 ] = V_29 ;
switch ( V_27 ) {
case V_81 :
if ( V_29 == 0 ) {
for ( V_80 = 0 ; V_80 < 128 ; V_80 ++ ) {
if ( V_8 -> V_13 [ V_80 ] & V_77 ) {
V_8 -> V_13 [ V_80 ] = V_82 ;
if ( V_2 -> V_23 )
V_2 -> V_23 ( V_9 , V_80 , 0 , V_8 ) ;
}
}
}
break;
case V_83 :
break;
case V_84 :
if ( V_29 ) {
for ( V_80 = 0 ; V_80 < 128 ; V_80 ++ ) {
if ( V_8 -> V_13 [ V_80 ] & V_22 )
V_8 -> V_13 [ V_80 ] |= V_78 ;
}
} else {
for ( V_80 = 0 ; V_80 < 128 ; V_80 ++ ) {
if ( V_8 -> V_13 [ V_80 ] & V_78 ) {
V_8 -> V_13 [ V_80 ] &= ~ V_78 ;
if ( V_8 -> V_13 [ V_80 ] & V_77 ) {
V_8 -> V_13 [ V_80 ] = V_82 ;
if ( V_2 -> V_23 )
V_2 -> V_23 ( V_9 , V_80 , 0 , V_8 ) ;
}
}
}
}
break;
case V_42 :
V_8 -> V_27 [ V_43 ] = 0 ;
case V_43 :
if ( V_8 -> V_40 == V_47 )
F_6 ( V_2 , V_9 , V_8 , V_79 ) ;
else
F_5 ( V_2 , V_9 , V_8 , V_79 ) ;
break;
case V_49 :
case V_48 :
V_8 -> V_40 = V_47 ;
break;
case V_45 :
case V_44 :
V_8 -> V_40 = V_41 ;
break;
case V_85 :
F_9 ( V_2 , V_9 , V_8 ) ;
break;
case V_86 :
F_10 ( V_2 , V_9 , V_8 ) ;
break;
case V_87 :
if ( V_79 -> V_88 == V_89 ) {
if ( V_29 == 127 )
V_8 -> V_90 = 1 ;
else
V_8 -> V_90 = 0 ;
}
break;
case V_91 :
break;
case V_92 :
F_11 ( V_8 ) ;
break;
case V_93 :
case V_94 :
case V_95 :
case V_96 :
case V_97 :
case V_98 :
case V_99 :
case V_100 :
case V_101 :
case V_102 :
case V_103 :
case V_104 :
case V_105 :
goto V_106;
V_106:
default:
if ( V_2 -> V_27 )
V_2 -> V_27 ( V_9 , V_27 , V_8 ) ;
break;
}
}
void
F_12 ( struct V_5 * V_79 )
{
int V_80 ;
V_79 -> V_88 = V_107 ;
V_79 -> V_108 = 127 ;
for ( V_80 = 0 ; V_80 < V_79 -> V_15 ; V_80 ++ ) {
struct V_7 * V_8 = V_79 -> V_11 + V_80 ;
memset ( V_8 -> V_13 , 0 , sizeof( V_8 -> V_13 ) ) ;
V_8 -> V_109 = 0 ;
V_8 -> V_36 = 0 ;
V_8 -> V_31 = 0 ;
V_8 -> V_33 = 0 ;
F_11 ( V_8 ) ;
V_8 -> V_110 = 256 ;
V_8 -> V_111 = 0 ;
V_8 -> V_112 = 0 ;
if ( V_80 == 9 )
V_8 -> V_90 = 1 ;
else
V_8 -> V_90 = 0 ;
}
}
static void
F_6 ( struct V_1 * V_2 , void * V_9 , struct V_7 * V_8 ,
struct V_5 * V_79 )
{
int type ;
int V_113 ;
if ( V_79 -> V_88 != V_114 ) {
type = ( V_8 -> V_27 [ V_48 ] << 8 ) |
V_8 -> V_27 [ V_49 ] ;
V_113 = ( V_8 -> V_27 [ V_42 ] << 7 ) |
V_8 -> V_27 [ V_43 ] ;
switch ( type ) {
case 0x0000 :
V_8 -> V_110 = V_113 ;
break;
case 0x0001 :
V_8 -> V_111 = V_113 - 8192 ;
break;
case 0x0002 :
V_8 -> V_112 = V_113 - 8192 ;
break;
case 0x7F7F :
break;
}
}
}
static void
F_5 ( struct V_1 * V_2 , void * V_9 , struct V_7 * V_8 ,
struct V_5 * V_79 )
{
if ( V_2 -> F_5 )
V_2 -> F_5 ( V_9 , V_8 , V_79 ) ;
}
static int
F_13 ( unsigned char V_115 )
{
int V_116 = V_115 & 0x0f ;
if ( V_116 == 0 )
V_116 = 9 ;
else if ( V_116 < 10 )
V_116 -- ;
return V_116 ;
}
static void
F_8 ( struct V_1 * V_2 , void * V_117 , unsigned char * V_118 , int V_55 ,
struct V_5 * V_79 )
{
static unsigned char V_119 [] = {
0x7e , 0x7f , 0x09 , 0x01 ,
} ;
static unsigned char V_120 [] = {
0x43 , 0x10 , 0x4c , 0x00 , 0x00 , 0x7e , 0x00 ,
} ;
static unsigned char V_121 [] = {
0x41 , 0x10 , 0x42 , 0x12 , 0x40 ,
} ;
int V_122 = V_123 ;
if ( V_55 <= 0 || V_118 [ 0 ] != 0xf0 )
return;
V_118 ++ ;
V_55 -- ;
if ( V_55 >= ( int ) sizeof( V_119 ) &&
memcmp ( V_118 , V_119 , sizeof( V_119 ) ) == 0 ) {
if ( V_79 -> V_88 != V_124 &&
V_79 -> V_88 != V_89 ) {
V_79 -> V_88 = V_107 ;
F_14 ( V_79 ) ;
V_122 = V_125 ;
}
}
else if ( V_55 >= 8 &&
memcmp ( V_118 , V_121 , sizeof( V_121 ) ) == 0 ) {
if ( V_79 -> V_88 != V_124 &&
V_79 -> V_88 != V_89 )
V_79 -> V_88 = V_124 ;
if ( V_118 [ 5 ] == 0x00 && V_118 [ 6 ] == 0x7f && V_118 [ 7 ] == 0x00 ) {
V_122 = V_126 ;
F_14 ( V_79 ) ;
}
else if ( ( V_118 [ 5 ] & 0xf0 ) == 0x10 && V_118 [ 6 ] == 0x15 ) {
int V_116 = F_13 ( V_118 [ 5 ] ) ;
if ( V_116 < V_79 -> V_15 ) {
V_122 = V_127 ;
if ( V_118 [ 7 ] )
V_79 -> V_11 [ V_116 ] . V_90 = 1 ;
else
V_79 -> V_11 [ V_116 ] . V_90 = 0 ;
}
} else if ( ( V_118 [ 5 ] & 0xf0 ) == 0x10 && V_118 [ 6 ] == 0x21 ) {
int V_116 = F_13 ( V_118 [ 5 ] ) ;
if ( V_116 < V_79 -> V_15 &&
! V_79 -> V_11 [ V_116 ] . V_90 ) {
V_122 = V_127 ;
V_79 -> V_11 [ V_116 ] . V_31 = V_118 [ 7 ] ;
}
} else if ( V_118 [ 5 ] == 0x01 && V_118 [ 6 ] == 0x30 ) {
V_122 = V_128 ;
V_79 -> V_129 = V_118 [ 7 ] ;
} else if ( V_118 [ 5 ] == 0x01 && V_118 [ 6 ] == 0x38 ) {
V_122 = V_130 ;
V_79 -> V_131 = V_118 [ 7 ] ;
} else if ( V_118 [ 5 ] == 0x00 && V_118 [ 6 ] == 0x04 ) {
V_122 = V_132 ;
V_79 -> V_108 = V_118 [ 7 ] ;
}
}
else if ( V_55 >= ( int ) sizeof( V_120 ) &&
memcmp ( V_118 , V_120 , sizeof( V_120 ) ) == 0 ) {
int V_80 ;
V_79 -> V_88 = V_89 ;
V_122 = V_133 ;
for ( V_80 = 0 ; V_80 < V_79 -> V_15 ; V_80 ++ ) {
if ( V_79 -> V_11 [ V_80 ] . V_90 )
V_79 -> V_11 [ V_80 ] . V_27 [ V_87 ] = 127 ;
else
V_79 -> V_11 [ V_80 ] . V_27 [ V_87 ] = 0 ;
}
}
if ( V_2 -> F_8 )
V_2 -> F_8 ( V_117 , V_118 - 1 , V_55 + 1 , V_122 , V_79 ) ;
}
static void
F_9 ( struct V_1 * V_2 , void * V_9 , struct V_7 * V_8 )
{
int V_134 ;
if ( ! V_2 -> V_135 )
return;
for ( V_134 = 0 ; V_134 < 128 ; V_134 ++ ) {
if ( V_8 -> V_13 [ V_134 ] ) {
V_2 -> V_135 ( V_9 , V_134 , V_8 ) ;
V_8 -> V_13 [ V_134 ] = 0 ;
}
}
}
static void
F_10 ( struct V_1 * V_2 , void * V_9 , struct V_7 * V_8 )
{
int V_134 ;
if ( ! V_2 -> V_23 )
return;
for ( V_134 = 0 ; V_134 < 128 ; V_134 ++ ) {
if ( V_8 -> V_13 [ V_134 ] == V_22 )
V_23 ( V_2 , V_9 , V_8 , V_134 , 0 ) ;
}
}
static void F_15 ( struct V_7 * V_116 , int V_134 )
{
if ( V_116 == NULL )
return;
memset ( V_116 , 0 , sizeof( struct V_7 ) ) ;
V_116 -> V_117 = NULL ;
V_116 -> V_136 = V_134 ;
F_11 ( V_116 ) ;
V_116 -> V_110 = 256 ;
V_116 -> V_111 = 0 ;
V_116 -> V_112 = 0 ;
if ( V_134 == 9 )
V_116 -> V_90 = 1 ;
}
static struct V_7 * F_16 ( int V_134 )
{
struct V_7 * V_8 ;
int V_80 ;
V_8 = F_17 ( V_134 * sizeof( struct V_7 ) , V_137 ) ;
if ( V_8 ) {
for ( V_80 = 0 ; V_80 < V_134 ; V_80 ++ )
F_15 ( V_8 + V_80 , V_80 ) ;
}
return V_8 ;
}
static void
F_14 ( struct V_5 * V_79 )
{
int V_138 ;
for ( V_138 = 0 ; V_138 < V_79 -> V_15 ; V_138 ++ ) {
struct V_7 * V_8 = V_79 -> V_11 + V_138 ;
F_11 ( V_8 ) ;
V_8 -> V_110 = 256 ;
V_8 -> V_111 = 0 ;
V_8 -> V_112 = 0 ;
if ( V_138 == 9 )
V_8 -> V_90 = 1 ;
else
V_8 -> V_90 = 0 ;
}
}
struct V_5 * F_18 ( int V_134 )
{
struct V_5 * V_79 ;
V_79 = F_17 ( sizeof( * V_79 ) , V_137 ) ;
if ( V_79 ) {
V_79 -> V_11 = F_16 ( V_134 ) ;
V_79 -> V_16 = NULL ;
V_79 -> V_15 = V_134 ;
}
return V_79 ;
}
static void F_11 ( struct V_7 * V_8 )
{
memset ( V_8 -> V_27 , 0 , sizeof( V_8 -> V_27 ) ) ;
V_8 -> V_139 = 127 ;
V_8 -> V_140 = 127 ;
V_8 -> V_141 = 64 ;
}
void F_19 ( struct V_5 * V_79 )
{
if ( V_79 == NULL )
return;
F_20 ( V_79 -> V_11 ) ;
F_20 ( V_79 ) ;
}
static int T_1 F_21 ( void )
{
return 0 ;
}
static void T_2 F_22 ( void )
{
}
