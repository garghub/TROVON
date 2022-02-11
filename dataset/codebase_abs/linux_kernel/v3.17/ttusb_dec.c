static void F_1 ( struct V_1 * V_1 )
{
struct V_2 * V_3 = V_1 -> V_4 ;
char * V_5 = V_3 -> V_6 ;
int V_7 ;
switch( V_1 -> V_8 ) {
case 0 :
break;
case - V_9 :
case - V_10 :
case - V_11 :
case - V_12 :
F_2 ( L_1 ,
V_13 , V_1 -> V_8 ) ;
return;
default:
F_2 ( L_2 ,
V_13 , V_1 -> V_8 ) ;
goto exit;
}
if( ( V_5 [ 0 ] == 0x1 ) && ( V_5 [ 2 ] == 0x15 ) ) {
F_2 ( L_3 , V_13 , V_5 [ 4 ] ) ;
F_3 ( V_3 -> V_14 , V_15 [ V_5 [ 4 ] - 1 ] , 1 ) ;
F_4 ( V_3 -> V_14 ) ;
F_3 ( V_3 -> V_14 , V_15 [ V_5 [ 4 ] - 1 ] , 0 ) ;
F_4 ( V_3 -> V_14 ) ;
}
exit: V_7 = F_5 ( V_1 , V_16 ) ;
if( V_7 )
F_6 ( L_4 ,
V_13 , V_7 ) ;
}
static T_1 F_7 ( T_1 V_17 , const T_2 * V_18 , T_3 V_19 )
{
T_1 V_20 ;
while ( V_19 -- ) {
V_17 ^= * V_18 ++ ;
V_17 ^= ( T_2 ) V_17 >> 4 ;
V_20 = ( T_2 ) V_17 ;
V_17 ^= ( V_20 ^ ( V_20 << 1 ) ) << 4 ;
}
return V_17 ;
}
static int F_8 ( struct V_2 * V_3 , const T_2 V_21 ,
int V_22 , const T_2 V_23 [] ,
int * V_24 , T_2 V_25 [] )
{
int V_26 , V_27 , V_28 ;
T_2 * V_29 ;
F_2 ( L_5 , V_13 ) ;
V_29 = F_9 ( V_30 + 4 , V_31 ) ;
if ( ! V_29 )
return - V_32 ;
if ( ( V_26 = F_10 ( & V_3 -> V_33 ) ) ) {
F_11 ( V_29 ) ;
F_6 ( L_6 , V_13 ) ;
return V_26 ;
}
V_29 [ 0 ] = 0xaa ;
V_29 [ 1 ] = ++ V_3 -> V_34 ;
V_29 [ 2 ] = V_21 ;
V_29 [ 3 ] = V_22 ;
if ( V_23 )
memcpy ( & V_29 [ 4 ] , V_23 , V_22 ) ;
if ( V_35 ) {
F_6 ( L_7 , V_13 ) ;
for ( V_28 = 0 ; V_28 < V_22 + 4 ; V_28 ++ )
F_6 ( L_8 , V_29 [ V_28 ] ) ;
F_6 ( L_9 ) ;
}
V_26 = F_12 ( V_3 -> V_36 , V_3 -> V_37 , V_29 ,
V_30 + 4 , & V_27 , 1000 ) ;
if ( V_26 ) {
F_6 ( L_10 ,
V_13 , V_26 ) ;
F_13 ( & V_3 -> V_33 ) ;
F_11 ( V_29 ) ;
return V_26 ;
}
V_26 = F_12 ( V_3 -> V_36 , V_3 -> V_38 , V_29 ,
V_30 + 4 , & V_27 , 1000 ) ;
if ( V_26 ) {
F_6 ( L_11 ,
V_13 , V_26 ) ;
F_13 ( & V_3 -> V_33 ) ;
F_11 ( V_29 ) ;
return V_26 ;
} else {
if ( V_35 ) {
F_6 ( L_12 , V_13 ) ;
for ( V_28 = 0 ; V_28 < V_27 ; V_28 ++ )
F_6 ( L_8 , V_29 [ V_28 ] ) ;
F_6 ( L_9 ) ;
}
if ( V_24 )
* V_24 = V_29 [ 3 ] ;
if ( V_25 && V_29 [ 3 ] > 0 )
memcpy ( V_25 , & V_29 [ 4 ] , V_29 [ 3 ] ) ;
F_13 ( & V_3 -> V_33 ) ;
F_11 ( V_29 ) ;
return 0 ;
}
}
static int F_14 ( struct V_2 * V_3 , unsigned int * V_39 ,
unsigned int * V_40 , unsigned int * V_41 )
{
T_2 V_42 [ V_30 ] ;
int V_43 ;
int V_26 ;
T_4 V_20 ;
F_2 ( L_5 , V_13 ) ;
V_26 = F_8 ( V_3 , 0x08 , 0 , NULL , & V_43 , V_42 ) ;
if ( V_26 )
return V_26 ;
if ( V_43 >= 0x0c ) {
if ( V_39 != NULL ) {
memcpy ( & V_20 , V_42 , 4 ) ;
* V_39 = F_15 ( V_20 ) ;
}
if ( V_40 != NULL ) {
memcpy ( & V_20 , & V_42 [ 4 ] , 4 ) ;
* V_40 = F_15 ( V_20 ) ;
}
if ( V_41 != NULL ) {
memcpy ( & V_20 , & V_42 [ 8 ] , 4 ) ;
* V_41 = F_15 ( V_20 ) ;
}
return 0 ;
} else {
return - V_10 ;
}
}
static int F_16 ( void * V_44 , unsigned char * V_45 )
{
struct V_2 * V_3 = V_44 ;
V_3 -> V_46 -> V_47 -> V_48 . V_49 ( V_45 , 188 , NULL , 0 ,
& V_3 -> V_46 -> V_47 -> V_47 . V_49 ,
V_50 ) ;
return 0 ;
}
static int F_17 ( void * V_44 , unsigned char * V_45 )
{
struct V_2 * V_3 = V_44 ;
V_3 -> V_51 -> V_47 -> V_48 . V_49 ( V_45 , 188 , NULL , 0 ,
& V_3 -> V_51 -> V_47 -> V_47 . V_49 ,
V_50 ) ;
return 0 ;
}
static void F_18 ( struct V_2 * V_3 )
{
T_2 V_29 [] = { 0x00 , 0x00 , 0x00 , 0x00 ,
0x00 , 0x00 , 0xff , 0xff ,
0xff , 0xff , 0xff , 0xff } ;
T_5 V_52 = F_19 ( V_3 -> V_53 [ V_54 ] ) ;
T_5 V_55 = F_19 ( V_3 -> V_53 [ V_56 ] ) ;
T_5 V_57 = F_19 ( V_3 -> V_53 [ V_58 ] ) ;
F_2 ( L_5 , V_13 ) ;
memcpy ( & V_29 [ 0 ] , & V_52 , 2 ) ;
memcpy ( & V_29 [ 2 ] , & V_55 , 2 ) ;
memcpy ( & V_29 [ 4 ] , & V_57 , 2 ) ;
F_8 ( V_3 , 0x50 , sizeof( V_29 ) , V_29 , NULL , NULL ) ;
F_20 ( & V_3 -> V_59 , V_3 -> V_53 [ V_56 ] ,
F_16 , V_3 ) ;
F_20 ( & V_3 -> V_60 , V_3 -> V_53 [ V_58 ] ,
F_17 , V_3 ) ;
V_3 -> V_61 = 0 ;
V_3 -> V_62 = 0 ;
}
static void F_21 ( struct V_2 * V_3 , T_2 * V_63 , int V_64 )
{
if ( V_64 < 8 ) {
F_6 ( L_13 , V_13 ) ;
return;
}
if ( V_64 > 8 + V_65 ) {
F_6 ( L_14 , V_13 ) ;
return;
}
switch ( V_63 [ 2 ] ) {
case 0x01 : {
int V_66 = V_63 [ 5 ] & 0x03 ;
int V_67 = ( V_63 [ 5 ] & 0x0c ) >> 2 ;
T_5 V_68 ;
if ( V_69 ) {
V_3 -> V_51 -> V_47 -> V_48 . V_49 ( V_63 , V_64 , NULL , 0 ,
& V_3 -> V_51 -> V_47 -> V_47 . V_49 , V_50 ) ;
return;
}
if ( V_3 -> V_62 > 0 &&
V_3 -> V_62 == V_66 ) {
memcpy ( & V_3 -> V_70 [ V_3 -> V_61 ] ,
& V_63 [ 12 ] , V_66 ) ;
F_22 ( & V_3 -> V_60 , V_3 -> V_70 ,
V_3 -> V_61 + V_66 , 1 ) ;
}
if ( V_63 [ 5 ] & 0x10 ) {
V_3 -> V_70 [ 7 ] = 0x80 ;
V_3 -> V_70 [ 8 ] = 0x05 ;
V_3 -> V_70 [ 9 ] = 0x21 | ( ( V_63 [ 8 ] & 0xc0 ) >> 5 ) ;
V_3 -> V_70 [ 10 ] = ( ( V_63 [ 8 ] & 0x3f ) << 2 ) |
( ( V_63 [ 9 ] & 0xc0 ) >> 6 ) ;
V_3 -> V_70 [ 11 ] = 0x01 |
( ( V_63 [ 9 ] & 0x3f ) << 2 ) |
( ( V_63 [ 10 ] & 0x80 ) >> 6 ) ;
V_3 -> V_70 [ 12 ] = ( ( V_63 [ 10 ] & 0x7f ) << 1 ) |
( ( V_63 [ 11 ] & 0xc0 ) >> 7 ) ;
V_3 -> V_70 [ 13 ] = 0x01 | ( ( V_63 [ 11 ] & 0x7f ) << 1 ) ;
memcpy ( & V_3 -> V_70 [ 14 ] , & V_63 [ 12 + V_66 ] ,
V_64 - 12 - V_66 ) ;
V_3 -> V_61 = 14 + V_64 - 12 - V_66 ;
} else {
V_3 -> V_70 [ 7 ] = 0x00 ;
V_3 -> V_70 [ 8 ] = 0x00 ;
memcpy ( & V_3 -> V_70 [ 9 ] , & V_63 [ 8 ] , V_64 - 8 ) ;
V_3 -> V_61 = 9 + V_64 - 8 ;
}
V_3 -> V_62 = V_67 ;
if ( V_3 -> V_70 [ 9 + V_3 -> V_70 [ 8 ] ] == 0x00 &&
V_3 -> V_70 [ 10 + V_3 -> V_70 [ 8 ] ] == 0x00 &&
V_3 -> V_70 [ 11 + V_3 -> V_70 [ 8 ] ] == 0x01 )
V_3 -> V_70 [ 6 ] = 0x84 ;
else
V_3 -> V_70 [ 6 ] = 0x80 ;
V_68 = F_19 ( V_3 -> V_61 - 6 +
V_67 ) ;
memcpy ( & V_3 -> V_70 [ 4 ] , & V_68 , 2 ) ;
if ( V_67 == 0 )
F_22 ( & V_3 -> V_60 , V_3 -> V_70 ,
V_3 -> V_61 , 1 ) ;
break;
}
case 0x02 :
if ( V_69 ) {
V_3 -> V_46 -> V_47 -> V_48 . V_49 ( V_63 , V_64 , NULL , 0 ,
& V_3 -> V_46 -> V_47 -> V_47 . V_49 , V_50 ) ;
return;
}
F_22 ( & V_3 -> V_59 , & V_63 [ 8 ] , V_64 - 8 ,
V_63 [ 5 ] & 0x10 ) ;
break;
default:
F_6 ( L_15 , V_13 ,
V_63 [ 2 ] ) ;
break;
}
}
static void F_23 ( struct V_2 * V_3 , T_2 * V_71 ,
int V_64 )
{
struct V_72 * V_73 ;
struct V_74 * V_75 ;
struct V_76 * V_77 = NULL ;
unsigned long V_78 ;
T_2 V_79 ;
V_79 = V_71 [ 1 ] ;
F_24 ( & V_3 -> V_80 , V_78 ) ;
for ( V_73 = V_3 -> V_81 . V_82 ; V_73 != & V_3 -> V_81 ;
V_73 = V_73 -> V_82 ) {
V_75 = F_25 ( V_73 , struct V_74 , V_81 ) ;
if ( V_75 -> V_83 == V_79 ) {
V_77 = V_75 -> V_77 ;
break;
}
}
F_26 ( & V_3 -> V_80 , V_78 ) ;
if ( V_77 )
V_77 -> V_47 -> V_48 . V_84 ( & V_71 [ 2 ] , V_64 - 2 , NULL , 0 ,
& V_77 -> V_77 , V_50 ) ;
}
static void F_27 ( struct V_2 * V_3 )
{
int V_28 ;
T_1 V_85 = 0 ;
T_1 V_86 ;
if ( V_3 -> V_87 % 2 ) {
F_6 ( L_16 , V_13 ) ;
return;
}
for ( V_28 = 0 ; V_28 < V_3 -> V_87 ; V_28 += 2 )
V_85 ^= ( ( V_3 -> V_71 [ V_28 ] << 8 ) + V_3 -> V_71 [ V_28 + 1 ] ) ;
if ( V_85 ) {
F_6 ( L_17 , V_13 ) ;
return;
}
V_86 = V_3 -> V_71 [ V_3 -> V_87 - 4 ] << 8 ;
V_86 += V_3 -> V_71 [ V_3 -> V_87 - 3 ] ;
if ( ( V_86 != V_3 -> V_88 ) && V_3 -> V_88 ) {
F_6 ( L_18 ,
V_13 , V_3 -> V_88 - 1 , V_86 ) ;
}
if ( V_86 == 0xffff )
V_3 -> V_88 = 0x8000 ;
else
V_3 -> V_88 = V_86 + 1 ;
switch ( V_3 -> V_89 ) {
case V_90 :
if ( V_3 -> V_91 )
F_21 ( V_3 , V_3 -> V_71 ,
V_3 -> V_92 ) ;
break;
case V_93 :
if ( V_3 -> V_94 )
F_23 ( V_3 , V_3 -> V_71 ,
V_3 -> V_92 ) ;
break;
case V_95 :
break;
}
}
static void F_28 ( T_2 * V_29 , int V_64 )
{
T_2 V_42 ;
V_64 -= V_64 % 2 ;
for (; V_64 ; V_29 += 2 , V_64 -= 2 ) {
V_42 = * V_29 ;
* V_29 = * ( V_29 + 1 ) ;
* ( V_29 + 1 ) = V_42 ;
}
}
static void F_29 ( struct V_2 * V_3 , T_2 * V_29 ,
int V_64 )
{
F_28 ( V_29 , V_64 ) ;
while ( V_64 ) {
switch ( V_3 -> V_96 ) {
case 0 :
case 1 :
case 2 :
if ( * V_29 ++ == 0xaa )
V_3 -> V_96 ++ ;
else
V_3 -> V_96 = 0 ;
V_64 -- ;
break;
case 3 :
if ( * V_29 == 0x00 ) {
V_3 -> V_96 ++ ;
V_3 -> V_87 = 0 ;
} else if ( * V_29 != 0xaa ) {
V_3 -> V_96 = 0 ;
}
V_29 ++ ;
V_64 -- ;
break;
case 4 :
V_3 -> V_71 [ V_3 -> V_87 ++ ] = * V_29 ++ ;
if ( V_3 -> V_87 == 2 ) {
if ( V_3 -> V_71 [ 0 ] == 'A' &&
V_3 -> V_71 [ 1 ] == 'V' ) {
V_3 -> V_89 =
V_90 ;
V_3 -> V_96 ++ ;
} else if ( V_3 -> V_71 [ 0 ] == 'S' ) {
V_3 -> V_89 =
V_93 ;
V_3 -> V_96 ++ ;
} else if ( V_3 -> V_71 [ 0 ] == 0x00 ) {
V_3 -> V_89 =
V_95 ;
V_3 -> V_92 = 2 ;
V_3 -> V_96 = 7 ;
} else {
F_6 ( L_19
L_20 , V_13 ,
V_3 -> V_71 [ 0 ] , V_3 -> V_71 [ 1 ] ) ;
V_3 -> V_96 = 0 ;
}
}
V_64 -- ;
break;
case 5 :
V_3 -> V_71 [ V_3 -> V_87 ++ ] = * V_29 ++ ;
if ( V_3 -> V_89 == V_90 &&
V_3 -> V_87 == 8 ) {
V_3 -> V_96 ++ ;
V_3 -> V_92 = 8 +
( V_3 -> V_71 [ 6 ] << 8 ) +
V_3 -> V_71 [ 7 ] ;
} else if ( V_3 -> V_89 ==
V_93 &&
V_3 -> V_87 == 5 ) {
V_3 -> V_96 ++ ;
V_3 -> V_92 = 5 +
( ( V_3 -> V_71 [ 3 ] & 0x0f ) << 8 ) +
V_3 -> V_71 [ 4 ] ;
}
V_64 -- ;
break;
case 6 : {
int V_97 = V_3 -> V_92 -
V_3 -> V_87 ;
if ( V_64 >= V_97 ) {
memcpy ( V_3 -> V_71 + V_3 -> V_87 ,
V_29 , V_97 ) ;
V_3 -> V_87 += V_97 ;
V_29 += V_97 ;
V_64 -= V_97 ;
V_3 -> V_96 ++ ;
} else {
memcpy ( & V_3 -> V_71 [ V_3 -> V_87 ] ,
V_29 , V_64 ) ;
V_3 -> V_87 += V_64 ;
V_64 = 0 ;
}
break;
}
case 7 : {
int V_98 = 4 ;
V_3 -> V_71 [ V_3 -> V_87 ++ ] = * V_29 ++ ;
if ( V_3 -> V_89 == V_93 &&
V_3 -> V_92 % 2 )
V_98 ++ ;
if ( V_3 -> V_87 ==
V_3 -> V_92 + V_98 ) {
F_27 ( V_3 ) ;
V_3 -> V_96 = 0 ;
}
V_64 -- ;
break;
}
default:
F_6 ( L_21 ,
V_13 ) ;
V_3 -> V_96 = 0 ;
}
}
}
static void F_30 ( unsigned long V_45 )
{
struct V_2 * V_3 = (struct V_2 * ) V_45 ;
struct V_72 * V_73 ;
struct V_99 * V_100 ;
unsigned long V_78 ;
while ( 1 ) {
F_24 ( & V_3 -> V_101 , V_78 ) ;
if ( ( V_73 = V_3 -> V_102 . V_82 ) != & V_3 -> V_102 ) {
V_100 = F_25 ( V_73 , struct V_99 ,
V_102 ) ;
F_31 ( & V_100 -> V_102 ) ;
} else {
F_26 ( & V_3 -> V_101 ,
V_78 ) ;
return;
}
F_26 ( & V_3 -> V_101 , V_78 ) ;
F_29 ( V_3 , V_100 -> V_45 , V_100 -> V_64 ) ;
F_11 ( V_100 ) ;
}
}
static void F_32 ( struct V_1 * V_1 )
{
struct V_2 * V_3 = V_1 -> V_4 ;
if ( ! V_1 -> V_8 ) {
int V_28 ;
for ( V_28 = 0 ; V_28 < V_103 ; V_28 ++ ) {
struct V_104 * V_105 ;
T_2 * V_29 ;
int V_64 ;
struct V_99 * V_100 ;
V_105 = & V_1 -> V_106 [ V_28 ] ;
V_29 = V_1 -> V_107 + V_105 -> V_108 ;
V_64 = V_105 -> V_109 ;
if ( ( V_100 = F_9 ( sizeof( struct V_99 ) ,
V_16 ) ) ) {
unsigned long V_78 ;
memcpy ( V_100 -> V_45 , V_29 , V_64 ) ;
V_100 -> V_64 = V_64 ;
F_24 ( & V_3 -> V_101 ,
V_78 ) ;
F_33 ( & V_100 -> V_102 ,
& V_3 -> V_102 ) ;
F_26 ( & V_3 -> V_101 ,
V_78 ) ;
F_34 ( & V_3 -> V_110 ) ;
}
}
} else {
if ( V_1 -> V_8 != - V_10 )
F_2 ( L_22 , V_13 ,
V_1 -> V_8 ) ;
}
if ( V_3 -> V_111 )
F_5 ( V_1 , V_16 ) ;
}
static void F_35 ( struct V_2 * V_3 )
{
int V_28 , V_112 , V_113 = 0 ;
F_2 ( L_5 , V_13 ) ;
for ( V_28 = 0 ; V_28 < V_114 ; V_28 ++ ) {
int V_115 = 0 ;
struct V_1 * V_1 = V_3 -> V_116 [ V_28 ] ;
V_1 -> V_117 = V_3 -> V_36 ;
V_1 -> V_4 = V_3 ;
V_1 -> V_118 = F_32 ;
V_1 -> V_119 = V_3 -> V_120 ;
V_1 -> V_121 = V_122 ;
V_1 -> V_123 = 1 ;
V_1 -> V_124 = V_103 ;
V_1 -> V_125 = V_126 *
V_103 ;
V_1 -> V_107 = V_3 -> V_127 + V_113 ;
V_113 += V_126 * V_103 ;
for ( V_112 = 0 ; V_112 < V_103 ; V_112 ++ ) {
V_1 -> V_106 [ V_112 ] . V_108 = V_115 ;
V_1 -> V_106 [ V_112 ] . V_64 = V_126 ;
V_115 += V_126 ;
}
}
}
static void F_36 ( struct V_2 * V_3 )
{
int V_28 ;
F_2 ( L_5 , V_13 ) ;
if ( F_10 ( & V_3 -> V_128 ) )
return;
V_3 -> V_111 -- ;
if ( ! V_3 -> V_111 ) {
for ( V_28 = 0 ; V_28 < V_114 ; V_28 ++ )
F_37 ( V_3 -> V_116 [ V_28 ] ) ;
}
F_13 ( & V_3 -> V_128 ) ;
}
static int F_38 ( struct V_2 * V_3 ,
enum V_129 V_130 )
{
int V_26 = 0 ;
T_2 V_29 [] = { 0x05 } ;
if ( V_130 != V_3 -> V_130 ) {
switch ( V_130 ) {
case V_131 :
V_26 = F_39 ( V_3 -> V_36 , 0 , 0 ) ;
break;
case V_132 :
V_26 = F_8 ( V_3 , 0x80 , sizeof( V_29 ) ,
V_29 , NULL , NULL ) ;
if ( V_26 )
return V_26 ;
V_26 = F_39 ( V_3 -> V_36 , 0 , 8 ) ;
break;
case V_133 :
V_26 = F_39 ( V_3 -> V_36 , 0 , 1 ) ;
break;
}
if ( V_26 )
return V_26 ;
V_3 -> V_130 = V_130 ;
}
return 0 ;
}
static int F_40 ( struct V_2 * V_3 )
{
int V_28 , V_26 ;
F_2 ( L_5 , V_13 ) ;
if ( F_10 ( & V_3 -> V_128 ) )
return - V_134 ;
if ( ! V_3 -> V_111 ) {
F_35 ( V_3 ) ;
V_3 -> V_96 = 0 ;
V_3 -> V_62 = 0 ;
V_3 -> V_88 = 0 ;
for ( V_28 = 0 ; V_28 < V_114 ; V_28 ++ ) {
if ( ( V_26 = F_5 ( V_3 -> V_116 [ V_28 ] ,
V_16 ) ) ) {
F_6 ( L_23
L_24 , V_13 , V_28 , V_26 ) ;
while ( V_28 ) {
F_37 ( V_3 -> V_116 [ V_28 - 1 ] ) ;
V_28 -- ;
}
F_13 ( & V_3 -> V_128 ) ;
return V_26 ;
}
}
}
V_3 -> V_111 ++ ;
F_13 ( & V_3 -> V_128 ) ;
return 0 ;
}
static int F_41 ( struct V_135 * V_136 )
{
struct V_137 * V_138 = V_136 -> V_139 ;
struct V_2 * V_3 = V_138 -> V_44 ;
T_2 V_140 [] = { 0x05 } ;
int V_26 = 0 ;
F_2 ( L_5 , V_13 ) ;
F_2 ( L_25 ) ;
if ( V_136 -> V_141 & V_142 )
F_2 ( L_26 ) ;
if ( V_136 -> V_141 & V_143 )
F_2 ( L_27 ) ;
if ( V_136 -> V_141 & V_144 )
F_2 ( L_28 ) ;
F_2 ( L_9 ) ;
switch ( V_136 -> V_145 ) {
case V_58 :
F_2 ( L_29 ) ;
V_3 -> V_53 [ V_54 ] = V_136 -> V_53 ;
V_3 -> V_53 [ V_58 ] = V_136 -> V_53 ;
V_3 -> V_51 = V_136 -> V_77 ;
F_18 ( V_3 ) ;
break;
case V_56 :
F_2 ( L_30 ) ;
V_3 -> V_53 [ V_56 ] = V_136 -> V_53 ;
V_3 -> V_46 = V_136 -> V_77 ;
F_18 ( V_3 ) ;
break;
case V_146 :
V_3 -> V_53 [ V_146 ] = V_136 -> V_53 ;
F_2 ( L_31 ) ;
return - V_147 ;
case V_54 :
F_2 ( L_32 ) ;
V_3 -> V_53 [ V_54 ] = V_136 -> V_53 ;
F_18 ( V_3 ) ;
break;
case V_148 :
F_2 ( L_33 ) ;
return - V_147 ;
default:
F_2 ( L_34 , V_136 -> V_145 ) ;
return - V_149 ;
}
V_26 = F_8 ( V_3 , 0x80 , sizeof( V_140 ) , V_140 , NULL , NULL ) ;
if ( V_26 )
return V_26 ;
V_3 -> V_91 ++ ;
return F_40 ( V_3 ) ;
}
static int F_42 ( struct V_135 * V_136 )
{
struct V_2 * V_3 = V_136 -> V_139 -> V_44 ;
T_2 V_140 [] = { 0x00 , 0x00 , 0x00 , 0x01 ,
0x00 , 0x00 , 0x00 , 0x00 ,
0x00 , 0x00 , 0x00 , 0x00 ,
0x00 , 0x00 , 0x00 , 0x00 ,
0x00 , 0xff , 0x00 , 0x00 ,
0x00 , 0x00 , 0x00 , 0x00 ,
0x00 , 0x00 , 0x00 , 0x00 ,
0x00 } ;
T_5 V_53 ;
T_2 V_42 [ V_30 ] ;
int V_43 ;
int V_26 ;
struct V_74 * V_75 ;
unsigned long V_78 ;
T_2 V_150 = 1 ;
F_2 ( L_5 , V_13 ) ;
V_53 = F_19 ( V_136 -> V_53 ) ;
memcpy ( & V_140 [ 0 ] , & V_53 , 2 ) ;
memcpy ( & V_140 [ 4 ] , & V_150 , 1 ) ;
memcpy ( & V_140 [ 5 ] , & V_136 -> V_77 -> V_77 . V_151 [ 0 ] , 1 ) ;
V_26 = F_8 ( V_3 , 0x60 , sizeof( V_140 ) , V_140 ,
& V_43 , V_42 ) ;
if ( ! V_26 ) {
if ( V_43 == 2 ) {
if ( ! ( V_75 = F_9 ( sizeof( struct V_74 ) ,
V_16 ) ) )
return - V_32 ;
V_75 -> V_83 = V_42 [ 1 ] ;
V_75 -> V_77 = V_136 -> V_77 ;
F_24 ( & V_3 -> V_80 , V_78 ) ;
F_33 ( & V_75 -> V_81 ,
& V_3 -> V_81 ) ;
F_26 ( & V_3 -> V_80 ,
V_78 ) ;
V_136 -> V_44 = V_75 ;
V_3 -> V_94 ++ ;
return F_40 ( V_3 ) ;
}
return - V_134 ;
} else
return V_26 ;
}
static int F_43 ( struct V_135 * V_136 )
{
struct V_137 * V_138 = V_136 -> V_139 ;
F_2 ( L_5 , V_13 ) ;
if ( ! V_138 -> V_152 . V_153 )
return - V_149 ;
F_2 ( L_35 , V_136 -> V_53 ) ;
switch ( V_136 -> type ) {
case V_154 :
return F_41 ( V_136 ) ;
break;
case V_155 :
return F_42 ( V_136 ) ;
break;
default:
F_2 ( L_36 , V_136 -> type ) ;
return - V_149 ;
}
}
static int F_44 ( struct V_135 * V_136 )
{
struct V_2 * V_3 = V_136 -> V_139 -> V_44 ;
T_2 V_140 [] = { 0x00 } ;
F_8 ( V_3 , 0x81 , sizeof( V_140 ) , V_140 , NULL , NULL ) ;
V_3 -> V_91 -- ;
F_36 ( V_3 ) ;
return 0 ;
}
static int F_45 ( struct V_135 * V_136 )
{
struct V_2 * V_3 = V_136 -> V_139 -> V_44 ;
T_2 V_140 [] = { 0x00 , 0x00 } ;
struct V_74 * V_75 = (struct V_74 * ) V_136 -> V_44 ;
unsigned long V_78 ;
V_140 [ 1 ] = V_75 -> V_83 ;
F_24 ( & V_3 -> V_80 , V_78 ) ;
F_31 ( & V_75 -> V_81 ) ;
F_26 ( & V_3 -> V_80 , V_78 ) ;
F_11 ( V_75 ) ;
F_8 ( V_3 , 0x62 , sizeof( V_140 ) , V_140 , NULL , NULL ) ;
V_3 -> V_94 -- ;
F_36 ( V_3 ) ;
return 0 ;
}
static int F_46 ( struct V_135 * V_136 )
{
F_2 ( L_5 , V_13 ) ;
switch ( V_136 -> type ) {
case V_154 :
return F_44 ( V_136 ) ;
break;
case V_155 :
return F_45 ( V_136 ) ;
break;
}
return 0 ;
}
static void F_47 ( struct V_2 * V_3 )
{
int V_28 ;
F_2 ( L_5 , V_13 ) ;
for ( V_28 = 0 ; V_28 < V_114 ; V_28 ++ )
F_48 ( V_3 -> V_116 [ V_28 ] ) ;
F_49 ( NULL ,
V_126 * ( V_103 *
V_114 ) ,
V_3 -> V_127 , V_3 -> V_156 ) ;
}
static int F_50 ( struct V_2 * V_3 )
{
int V_28 ;
F_2 ( L_5 , V_13 ) ;
V_3 -> V_127 = F_51 ( NULL ,
V_126 * ( V_103 * V_114 ) ,
& V_3 -> V_156 ) ;
if ( ! V_3 -> V_127 ) {
F_2 ( L_37 ,
V_13 ) ;
return - V_32 ;
}
for ( V_28 = 0 ; V_28 < V_114 ; V_28 ++ ) {
struct V_1 * V_1 ;
if ( ! ( V_1 = F_52 ( V_103 , V_16 ) ) ) {
F_47 ( V_3 ) ;
return - V_32 ;
}
V_3 -> V_116 [ V_28 ] = V_1 ;
}
F_35 ( V_3 ) ;
return 0 ;
}
static void F_53 ( struct V_2 * V_3 )
{
F_54 ( & V_3 -> V_101 ) ;
F_55 ( & V_3 -> V_102 ) ;
F_56 ( & V_3 -> V_110 , F_30 ,
( unsigned long ) V_3 ) ;
}
static int F_57 ( struct V_2 * V_3 )
{
struct V_157 * V_157 ;
T_2 V_29 [] = { 0x00 , 0x01 } ;
int V_28 ;
int V_158 ;
F_58 ( V_3 -> V_36 , V_3 -> V_159 , sizeof( V_3 -> V_159 ) ) ;
F_59 ( V_3 -> V_159 , L_38 , sizeof( V_3 -> V_159 ) ) ;
V_157 = F_60 () ;
if ( ! V_157 )
return - V_32 ;
V_157 -> V_160 = L_39 ;
V_157 -> V_161 = V_3 -> V_159 ;
V_157 -> V_162 [ 0 ] = F_61 ( V_163 ) ;
V_157 -> V_164 = sizeof( T_1 ) ;
V_157 -> V_165 = 0x1a ;
V_157 -> V_166 = V_15 ;
for ( V_28 = 0 ; V_28 < F_62 ( V_15 ) ; V_28 ++ )
F_63 ( V_15 [ V_28 ] , V_157 -> V_167 ) ;
V_158 = F_64 ( V_157 ) ;
if ( V_158 ) {
F_65 ( V_157 ) ;
return V_158 ;
}
V_3 -> V_14 = V_157 ;
if ( F_5 ( V_3 -> V_168 , V_31 ) )
F_6 ( L_40 , V_13 ) ;
F_8 ( V_3 , 0xb0 , sizeof( V_29 ) , V_29 , NULL , NULL ) ;
return 0 ;
}
static void F_66 ( struct V_2 * V_3 )
{
F_2 ( L_5 , V_13 ) ;
V_3 -> V_70 [ 0 ] = 0x00 ;
V_3 -> V_70 [ 1 ] = 0x00 ;
V_3 -> V_70 [ 2 ] = 0x01 ;
V_3 -> V_70 [ 3 ] = 0xe0 ;
}
static int F_67 ( struct V_2 * V_3 )
{
int V_26 ;
F_2 ( L_5 , V_13 ) ;
F_68 ( & V_3 -> V_33 ) ;
F_68 ( & V_3 -> V_128 ) ;
V_3 -> V_37 = F_69 ( V_3 -> V_36 , V_169 ) ;
V_3 -> V_38 = F_70 ( V_3 -> V_36 , V_170 ) ;
V_3 -> V_120 = F_71 ( V_3 -> V_36 , V_171 ) ;
V_3 -> V_172 = F_72 ( V_3 -> V_36 , V_173 ) ;
V_3 -> V_174 = F_73 ( V_3 -> V_36 , V_175 ) ;
if( V_176 ) {
V_3 -> V_168 = F_52 ( 0 , V_31 ) ;
if( ! V_3 -> V_168 ) {
return - V_32 ;
}
V_3 -> V_6 = F_74 ( V_3 -> V_36 , V_177 ,
V_31 , & V_3 -> V_178 ) ;
if( ! V_3 -> V_6 ) {
F_48 ( V_3 -> V_168 ) ;
return - V_32 ;
}
F_75 ( V_3 -> V_168 , V_3 -> V_36 , V_3 -> V_174 ,
V_3 -> V_6 , V_177 ,
F_1 , V_3 , 1 ) ;
V_3 -> V_168 -> V_179 = V_3 -> V_178 ;
V_3 -> V_168 -> V_121 |= V_180 ;
}
V_26 = F_50 ( V_3 ) ;
if ( V_26 ) {
F_48 ( V_3 -> V_168 ) ;
F_76 ( V_3 -> V_36 , V_177 ,
V_3 -> V_6 , V_3 -> V_178 ) ;
}
return V_26 ;
}
static int F_77 ( struct V_2 * V_3 )
{
int V_28 , V_112 , V_27 , V_26 , V_181 , V_34 ;
T_2 V_140 [] = { 0x00 , 0x00 , 0x00 , 0x00 ,
0x00 , 0x00 , 0x00 , 0x00 ,
0x61 , 0x00 } ;
T_2 V_182 [] = { 0x61 } ;
T_2 * V_29 ;
char V_183 [ 21 ] ;
const T_2 * V_184 = NULL ;
T_3 V_185 = 0 ;
T_1 V_186 = 0 ;
T_5 V_187 ;
T_4 V_188 ;
T_6 V_189 , V_190 ;
T_4 V_20 ;
const struct V_184 * V_191 = NULL ;
F_2 ( L_5 , V_13 ) ;
V_26 = F_78 ( & V_191 , V_3 -> V_192 , & V_3 -> V_36 -> V_117 ) ;
if ( V_26 ) {
F_6 ( V_193 L_41 ,
V_13 , V_3 -> V_192 ) ;
return V_26 ;
}
V_184 = V_191 -> V_45 ;
V_185 = V_191 -> V_181 ;
if ( V_185 < 60 ) {
F_6 ( L_42 ,
V_13 , V_185 ) ;
F_79 ( V_191 ) ;
return - V_10 ;
}
V_189 = F_80 ( ~ 0L , V_184 , 56 ) ^ ~ 0L ;
memcpy ( & V_20 , & V_184 [ 56 ] , 4 ) ;
V_190 = F_15 ( V_20 ) ;
if ( V_189 != V_190 ) {
F_6 ( L_43
L_44 ,
V_13 , V_189 , V_190 ) ;
F_79 ( V_191 ) ;
return - V_10 ;
}
memcpy ( V_183 , & V_184 [ 36 ] , 20 ) ;
V_183 [ 20 ] = '\0' ;
F_6 ( V_194 L_45 , V_183 ) ;
V_188 = F_81 ( V_185 ) ;
memcpy ( V_140 , & V_188 , 4 ) ;
V_186 = F_7 ( ~ 0 , V_184 , V_185 ) ^ ~ 0 ;
V_187 = F_19 ( V_186 ) ;
memcpy ( & V_140 [ 6 ] , & V_187 , 2 ) ;
V_26 = F_8 ( V_3 , 0x41 , sizeof( V_140 ) , V_140 , NULL , NULL ) ;
if ( V_26 ) {
F_79 ( V_191 ) ;
return V_26 ;
}
V_34 = 0 ;
V_112 = 0 ;
V_29 = F_9 ( V_195 , V_31 ) ;
if ( V_29 == NULL ) {
F_79 ( V_191 ) ;
return - V_32 ;
}
for ( V_28 = 0 ; V_28 < V_185 ; V_28 += V_30 ) {
V_181 = V_185 - V_28 ;
if ( V_181 > V_30 )
V_181 = V_30 ;
V_29 [ V_112 + 0 ] = 0xaa ;
V_29 [ V_112 + 1 ] = V_34 ++ ;
V_29 [ V_112 + 2 ] = 0xf0 ;
V_29 [ V_112 + 3 ] = V_181 ;
memcpy ( & V_29 [ V_112 + 4 ] , & V_184 [ V_28 ] , V_181 ) ;
V_112 += V_30 + 4 ;
if ( V_112 >= V_195 ) {
V_26 = F_12 ( V_3 -> V_36 , V_3 -> V_37 , V_29 ,
V_195 , & V_27 ,
100 ) ;
V_112 = 0 ;
} else if ( V_181 < V_30 ) {
V_26 = F_12 ( V_3 -> V_36 , V_3 -> V_37 , V_29 ,
V_112 - V_30 + V_181 ,
& V_27 , 100 ) ;
}
}
V_26 = F_8 ( V_3 , 0x43 , sizeof( V_182 ) , V_182 , NULL , NULL ) ;
F_79 ( V_191 ) ;
F_11 ( V_29 ) ;
return V_26 ;
}
static int F_82 ( struct V_2 * V_3 )
{
int V_26 ;
unsigned int V_39 = 0 , V_40 = 0 , V_41 = 0 ;
F_2 ( L_5 , V_13 ) ;
V_26 = F_14 ( V_3 , & V_39 , & V_40 , & V_41 ) ;
if ( V_26 )
return V_26 ;
if ( ! V_39 ) {
if ( V_41 == 0xABCDEFAB )
F_6 ( V_194 L_46
L_47 ) ;
else
F_6 ( V_194 L_48
L_49 ,
V_41 >> 24 , ( V_41 >> 16 ) & 0xff ,
( V_41 >> 8 ) & 0xff , V_41 & 0xff ) ;
V_26 = F_77 ( V_3 ) ;
if ( V_26 )
return V_26 ;
} else {
switch ( V_40 ) {
case 0x00070001 :
case 0x00070008 :
case 0x0007000c :
F_83 ( V_3 , V_196 ) ;
break;
case 0x00070009 :
case 0x00070013 :
F_83 ( V_3 , V_197 ) ;
break;
case 0x00070011 :
F_83 ( V_3 , V_198 ) ;
break;
default:
F_6 ( V_193 L_50
L_51 ,
V_13 , V_40 ) ;
return - V_10 ;
}
if ( V_41 >= 0x01770000 )
V_3 -> V_199 = 1 ;
}
return 0 ;
}
static int F_84 ( struct V_2 * V_3 )
{
int V_26 ;
F_2 ( L_5 , V_13 ) ;
if ( ( V_26 = F_85 ( & V_3 -> V_200 ,
V_3 -> V_201 , V_202 ,
& V_3 -> V_36 -> V_117 ,
V_203 ) ) < 0 ) {
F_6 ( L_52 ,
V_13 , V_26 ) ;
return V_26 ;
}
V_3 -> V_139 . V_152 . V_204 = V_205 | V_206 ;
V_3 -> V_139 . V_44 = ( void * ) V_3 ;
V_3 -> V_139 . V_207 = 31 ;
V_3 -> V_139 . V_208 = 31 ;
V_3 -> V_139 . V_209 = F_43 ;
V_3 -> V_139 . V_210 = F_46 ;
V_3 -> V_139 . V_211 = NULL ;
if ( ( V_26 = F_86 ( & V_3 -> V_139 ) ) < 0 ) {
F_6 ( L_53 , V_13 ,
V_26 ) ;
F_87 ( & V_3 -> V_200 ) ;
return V_26 ;
}
V_3 -> V_212 . V_207 = 32 ;
V_3 -> V_212 . V_139 = & V_3 -> V_139 . V_152 ;
V_3 -> V_212 . V_204 = 0 ;
if ( ( V_26 = F_88 ( & V_3 -> V_212 , & V_3 -> V_200 ) ) < 0 ) {
F_6 ( L_54 ,
V_13 , V_26 ) ;
F_89 ( & V_3 -> V_139 ) ;
F_87 ( & V_3 -> V_200 ) ;
return V_26 ;
}
V_3 -> V_153 . V_213 = V_214 ;
if ( ( V_26 = V_3 -> V_139 . V_152 . V_215 ( & V_3 -> V_139 . V_152 ,
& V_3 -> V_153 ) ) < 0 ) {
F_6 ( L_53 , V_13 ,
V_26 ) ;
F_90 ( & V_3 -> V_212 ) ;
F_89 ( & V_3 -> V_139 ) ;
F_87 ( & V_3 -> V_200 ) ;
return V_26 ;
}
if ( ( V_26 = V_3 -> V_139 . V_152 . V_216 ( & V_3 -> V_139 . V_152 ,
& V_3 -> V_153 ) ) < 0 ) {
F_6 ( L_53 , V_13 ,
V_26 ) ;
V_3 -> V_139 . V_152 . V_217 ( & V_3 -> V_139 . V_152 , & V_3 -> V_153 ) ;
F_90 ( & V_3 -> V_212 ) ;
F_89 ( & V_3 -> V_139 ) ;
F_87 ( & V_3 -> V_200 ) ;
return V_26 ;
}
F_91 ( & V_3 -> V_200 , & V_3 -> V_218 , & V_3 -> V_139 . V_152 ) ;
return 0 ;
}
static void F_92 ( struct V_2 * V_3 )
{
F_2 ( L_5 , V_13 ) ;
F_93 ( & V_3 -> V_218 ) ;
V_3 -> V_139 . V_152 . V_219 ( & V_3 -> V_139 . V_152 ) ;
V_3 -> V_139 . V_152 . V_217 ( & V_3 -> V_139 . V_152 , & V_3 -> V_153 ) ;
F_90 ( & V_3 -> V_212 ) ;
F_89 ( & V_3 -> V_139 ) ;
if ( V_3 -> V_220 ) {
F_94 ( V_3 -> V_220 ) ;
if ( V_3 -> V_220 -> V_221 . V_222 )
V_3 -> V_220 -> V_221 . V_222 ( V_3 -> V_220 ) ;
}
F_87 ( & V_3 -> V_200 ) ;
}
static void F_95 ( struct V_2 * V_3 )
{
F_2 ( L_5 , V_13 ) ;
if ( V_3 -> V_14 ) {
F_96 ( V_3 -> V_14 ) ;
V_3 -> V_14 = NULL ;
}
}
static void F_97 ( struct V_2 * V_3 )
{
int V_28 ;
F_2 ( L_5 , V_13 ) ;
if ( V_176 ) {
if ( V_3 -> V_130 == V_132 )
F_37 ( V_3 -> V_168 ) ;
F_48 ( V_3 -> V_168 ) ;
F_76 ( V_3 -> V_36 , V_177 ,
V_3 -> V_6 , V_3 -> V_178 ) ;
}
V_3 -> V_111 = 0 ;
for ( V_28 = 0 ; V_28 < V_114 ; V_28 ++ )
F_37 ( V_3 -> V_116 [ V_28 ] ) ;
F_47 ( V_3 ) ;
}
static void F_98 ( struct V_2 * V_3 )
{
struct V_72 * V_73 ;
struct V_99 * V_100 ;
F_99 ( & V_3 -> V_110 ) ;
while ( ( V_73 = V_3 -> V_102 . V_82 ) != & V_3 -> V_102 ) {
V_100 = F_25 ( V_73 , struct V_99 , V_102 ) ;
F_31 ( & V_100 -> V_102 ) ;
F_11 ( V_100 ) ;
}
}
static void F_100 ( struct V_2 * V_3 )
{
F_55 ( & V_3 -> V_81 ) ;
F_54 ( & V_3 -> V_80 ) ;
}
static void F_101 ( struct V_2 * V_3 )
{
struct V_72 * V_73 ;
struct V_74 * V_75 ;
while ( ( V_73 = V_3 -> V_81 . V_82 ) != & V_3 -> V_81 ) {
V_75 = F_25 ( V_73 , struct V_74 , V_81 ) ;
F_31 ( & V_75 -> V_81 ) ;
F_11 ( V_75 ) ;
}
}
static int F_102 ( struct V_223 * V_220 , const T_2 V_21 ,
int V_22 , const T_2 V_23 [] ,
int * V_24 , T_2 V_25 [] )
{
struct V_2 * V_3 = V_220 -> V_224 -> V_44 ;
return F_8 ( V_3 , V_21 , V_22 , V_23 , V_24 , V_25 ) ;
}
static int F_103 ( struct V_225 * V_226 ,
const struct V_227 * V_228 )
{
struct V_229 * V_36 ;
struct V_2 * V_3 ;
int V_26 ;
F_2 ( L_5 , V_13 ) ;
V_36 = F_104 ( V_226 ) ;
if ( ! ( V_3 = F_105 ( sizeof( struct V_2 ) , V_31 ) ) ) {
F_6 ( L_55 , V_13 ) ;
return - V_32 ;
}
F_106 ( V_226 , ( void * ) V_3 ) ;
switch ( V_228 -> V_230 ) {
case 0x1006 :
F_83 ( V_3 , V_196 ) ;
break;
case 0x1008 :
F_83 ( V_3 , V_197 ) ;
break;
case 0x1009 :
F_83 ( V_3 , V_198 ) ;
break;
}
V_3 -> V_36 = V_36 ;
V_26 = F_67 ( V_3 ) ;
if ( V_26 )
goto V_231;
V_26 = F_82 ( V_3 ) ;
if ( V_26 )
goto V_232;
V_26 = F_84 ( V_3 ) ;
if ( V_26 )
goto V_232;
V_3 -> V_200 . V_44 = V_3 ;
switch ( V_228 -> V_230 ) {
case 0x1006 :
V_3 -> V_220 = F_107 ( & V_233 ) ;
break;
case 0x1008 :
case 0x1009 :
V_3 -> V_220 = F_108 ( & V_233 ) ;
break;
}
if ( V_3 -> V_220 == NULL ) {
F_6 ( L_56 ,
F_109 ( V_3 -> V_36 -> V_234 . V_235 ) ,
F_109 ( V_3 -> V_36 -> V_234 . V_230 ) ) ;
} else {
if ( F_110 ( & V_3 -> V_200 , V_3 -> V_220 ) ) {
F_6 ( L_57 ) ;
if ( V_3 -> V_220 -> V_221 . V_222 )
V_3 -> V_220 -> V_221 . V_222 ( V_3 -> V_220 ) ;
V_3 -> V_220 = NULL ;
}
}
F_66 ( V_3 ) ;
F_100 ( V_3 ) ;
F_53 ( V_3 ) ;
V_3 -> V_236 = 1 ;
F_38 ( V_3 , V_132 ) ;
if ( V_176 )
F_57 ( V_3 ) ;
return 0 ;
V_232:
F_97 ( V_3 ) ;
V_231:
F_11 ( V_3 ) ;
return V_26 ;
}
static void F_111 ( struct V_225 * V_226 )
{
struct V_2 * V_3 = F_112 ( V_226 ) ;
F_106 ( V_226 , NULL ) ;
F_2 ( L_5 , V_13 ) ;
if ( V_3 -> V_236 ) {
F_98 ( V_3 ) ;
F_101 ( V_3 ) ;
if( V_176 )
F_95 ( V_3 ) ;
F_97 ( V_3 ) ;
F_92 ( V_3 ) ;
}
F_11 ( V_3 ) ;
}
static void F_83 ( struct V_2 * V_3 ,
enum V_237 V_40 )
{
V_3 -> V_40 = V_40 ;
switch ( V_40 ) {
case V_197 :
V_3 -> V_201 = L_58 ;
V_3 -> V_192 = L_59 ;
break;
case V_198 :
V_3 -> V_201 = L_60 ;
V_3 -> V_192 = L_61 ;
break;
case V_196 :
V_3 -> V_201 = L_62 ;
V_3 -> V_192 = L_63 ;
break;
}
}
