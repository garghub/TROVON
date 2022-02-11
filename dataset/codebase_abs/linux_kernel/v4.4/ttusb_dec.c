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
& V_3 -> V_46 -> V_47 -> V_47 . V_49 ) ;
return 0 ;
}
static int F_17 ( void * V_44 , unsigned char * V_45 )
{
struct V_2 * V_3 = V_44 ;
V_3 -> V_50 -> V_47 -> V_48 . V_49 ( V_45 , 188 , NULL , 0 ,
& V_3 -> V_50 -> V_47 -> V_47 . V_49 ) ;
return 0 ;
}
static void F_18 ( struct V_2 * V_3 )
{
T_2 V_29 [] = { 0x00 , 0x00 , 0x00 , 0x00 ,
0x00 , 0x00 , 0xff , 0xff ,
0xff , 0xff , 0xff , 0xff } ;
T_5 V_51 = F_19 ( V_3 -> V_52 [ V_53 ] ) ;
T_5 V_54 = F_19 ( V_3 -> V_52 [ V_55 ] ) ;
T_5 V_56 = F_19 ( V_3 -> V_52 [ V_57 ] ) ;
F_2 ( L_5 , V_13 ) ;
memcpy ( & V_29 [ 0 ] , & V_51 , 2 ) ;
memcpy ( & V_29 [ 2 ] , & V_54 , 2 ) ;
memcpy ( & V_29 [ 4 ] , & V_56 , 2 ) ;
F_8 ( V_3 , 0x50 , sizeof( V_29 ) , V_29 , NULL , NULL ) ;
F_20 ( & V_3 -> V_58 , V_3 -> V_52 [ V_55 ] ,
F_16 , V_3 ) ;
F_20 ( & V_3 -> V_59 , V_3 -> V_52 [ V_57 ] ,
F_17 , V_3 ) ;
V_3 -> V_60 = 0 ;
V_3 -> V_61 = 0 ;
}
static void F_21 ( struct V_2 * V_3 , T_2 * V_62 , int V_63 )
{
if ( V_63 < 8 ) {
F_6 ( L_13 , V_13 ) ;
return;
}
if ( V_63 > 8 + V_64 ) {
F_6 ( L_14 , V_13 ) ;
return;
}
switch ( V_62 [ 2 ] ) {
case 0x01 : {
int V_65 = V_62 [ 5 ] & 0x03 ;
int V_66 = ( V_62 [ 5 ] & 0x0c ) >> 2 ;
T_5 V_67 ;
if ( V_68 ) {
V_3 -> V_50 -> V_47 -> V_48 . V_49 ( V_62 , V_63 , NULL , 0 ,
& V_3 -> V_50 -> V_47 -> V_47 . V_49 ) ;
return;
}
if ( V_3 -> V_61 > 0 &&
V_3 -> V_61 == V_65 ) {
memcpy ( & V_3 -> V_69 [ V_3 -> V_60 ] ,
& V_62 [ 12 ] , V_65 ) ;
F_22 ( & V_3 -> V_59 , V_3 -> V_69 ,
V_3 -> V_60 + V_65 , 1 ) ;
}
if ( V_62 [ 5 ] & 0x10 ) {
V_3 -> V_69 [ 7 ] = 0x80 ;
V_3 -> V_69 [ 8 ] = 0x05 ;
V_3 -> V_69 [ 9 ] = 0x21 | ( ( V_62 [ 8 ] & 0xc0 ) >> 5 ) ;
V_3 -> V_69 [ 10 ] = ( ( V_62 [ 8 ] & 0x3f ) << 2 ) |
( ( V_62 [ 9 ] & 0xc0 ) >> 6 ) ;
V_3 -> V_69 [ 11 ] = 0x01 |
( ( V_62 [ 9 ] & 0x3f ) << 2 ) |
( ( V_62 [ 10 ] & 0x80 ) >> 6 ) ;
V_3 -> V_69 [ 12 ] = ( ( V_62 [ 10 ] & 0x7f ) << 1 ) |
( ( V_62 [ 11 ] & 0xc0 ) >> 7 ) ;
V_3 -> V_69 [ 13 ] = 0x01 | ( ( V_62 [ 11 ] & 0x7f ) << 1 ) ;
memcpy ( & V_3 -> V_69 [ 14 ] , & V_62 [ 12 + V_65 ] ,
V_63 - 12 - V_65 ) ;
V_3 -> V_60 = 14 + V_63 - 12 - V_65 ;
} else {
V_3 -> V_69 [ 7 ] = 0x00 ;
V_3 -> V_69 [ 8 ] = 0x00 ;
memcpy ( & V_3 -> V_69 [ 9 ] , & V_62 [ 8 ] , V_63 - 8 ) ;
V_3 -> V_60 = 9 + V_63 - 8 ;
}
V_3 -> V_61 = V_66 ;
if ( V_3 -> V_69 [ 9 + V_3 -> V_69 [ 8 ] ] == 0x00 &&
V_3 -> V_69 [ 10 + V_3 -> V_69 [ 8 ] ] == 0x00 &&
V_3 -> V_69 [ 11 + V_3 -> V_69 [ 8 ] ] == 0x01 )
V_3 -> V_69 [ 6 ] = 0x84 ;
else
V_3 -> V_69 [ 6 ] = 0x80 ;
V_67 = F_19 ( V_3 -> V_60 - 6 +
V_66 ) ;
memcpy ( & V_3 -> V_69 [ 4 ] , & V_67 , 2 ) ;
if ( V_66 == 0 )
F_22 ( & V_3 -> V_59 , V_3 -> V_69 ,
V_3 -> V_60 , 1 ) ;
break;
}
case 0x02 :
if ( V_68 ) {
V_3 -> V_46 -> V_47 -> V_48 . V_49 ( V_62 , V_63 , NULL , 0 ,
& V_3 -> V_46 -> V_47 -> V_47 . V_49 ) ;
return;
}
F_22 ( & V_3 -> V_58 , & V_62 [ 8 ] , V_63 - 8 ,
V_62 [ 5 ] & 0x10 ) ;
break;
default:
F_6 ( L_15 , V_13 ,
V_62 [ 2 ] ) ;
break;
}
}
static void F_23 ( struct V_2 * V_3 , T_2 * V_70 ,
int V_63 )
{
struct V_71 * V_72 ;
struct V_73 * V_74 ;
struct V_75 * V_76 = NULL ;
unsigned long V_77 ;
T_2 V_78 ;
V_78 = V_70 [ 1 ] ;
F_24 ( & V_3 -> V_79 , V_77 ) ;
for ( V_72 = V_3 -> V_80 . V_81 ; V_72 != & V_3 -> V_80 ;
V_72 = V_72 -> V_81 ) {
V_74 = F_25 ( V_72 , struct V_73 , V_80 ) ;
if ( V_74 -> V_82 == V_78 ) {
V_76 = V_74 -> V_76 ;
break;
}
}
F_26 ( & V_3 -> V_79 , V_77 ) ;
if ( V_76 )
V_76 -> V_47 -> V_48 . V_83 ( & V_70 [ 2 ] , V_63 - 2 , NULL , 0 ,
& V_76 -> V_76 ) ;
}
static void F_27 ( struct V_2 * V_3 )
{
int V_28 ;
T_1 V_84 = 0 ;
T_1 V_85 ;
if ( V_3 -> V_86 % 2 ) {
F_6 ( L_16 , V_13 ) ;
return;
}
for ( V_28 = 0 ; V_28 < V_3 -> V_86 ; V_28 += 2 )
V_84 ^= ( ( V_3 -> V_70 [ V_28 ] << 8 ) + V_3 -> V_70 [ V_28 + 1 ] ) ;
if ( V_84 ) {
F_6 ( L_17 , V_13 ) ;
return;
}
V_85 = V_3 -> V_70 [ V_3 -> V_86 - 4 ] << 8 ;
V_85 += V_3 -> V_70 [ V_3 -> V_86 - 3 ] ;
if ( ( V_85 != V_3 -> V_87 ) && V_3 -> V_87 ) {
F_6 ( L_18 ,
V_13 , V_3 -> V_87 - 1 , V_85 ) ;
}
if ( V_85 == 0xffff )
V_3 -> V_87 = 0x8000 ;
else
V_3 -> V_87 = V_85 + 1 ;
switch ( V_3 -> V_88 ) {
case V_89 :
if ( V_3 -> V_90 )
F_21 ( V_3 , V_3 -> V_70 ,
V_3 -> V_91 ) ;
break;
case V_92 :
if ( V_3 -> V_93 )
F_23 ( V_3 , V_3 -> V_70 ,
V_3 -> V_91 ) ;
break;
case V_94 :
break;
}
}
static void F_28 ( T_2 * V_29 , int V_63 )
{
V_63 -= V_63 % 2 ;
for (; V_63 ; V_29 += 2 , V_63 -= 2 )
F_29 ( * V_29 , * ( V_29 + 1 ) ) ;
}
static void F_30 ( struct V_2 * V_3 , T_2 * V_29 ,
int V_63 )
{
F_28 ( V_29 , V_63 ) ;
while ( V_63 ) {
switch ( V_3 -> V_95 ) {
case 0 :
case 1 :
case 2 :
if ( * V_29 ++ == 0xaa )
V_3 -> V_95 ++ ;
else
V_3 -> V_95 = 0 ;
V_63 -- ;
break;
case 3 :
if ( * V_29 == 0x00 ) {
V_3 -> V_95 ++ ;
V_3 -> V_86 = 0 ;
} else if ( * V_29 != 0xaa ) {
V_3 -> V_95 = 0 ;
}
V_29 ++ ;
V_63 -- ;
break;
case 4 :
V_3 -> V_70 [ V_3 -> V_86 ++ ] = * V_29 ++ ;
if ( V_3 -> V_86 == 2 ) {
if ( V_3 -> V_70 [ 0 ] == 'A' &&
V_3 -> V_70 [ 1 ] == 'V' ) {
V_3 -> V_88 =
V_89 ;
V_3 -> V_95 ++ ;
} else if ( V_3 -> V_70 [ 0 ] == 'S' ) {
V_3 -> V_88 =
V_92 ;
V_3 -> V_95 ++ ;
} else if ( V_3 -> V_70 [ 0 ] == 0x00 ) {
V_3 -> V_88 =
V_94 ;
V_3 -> V_91 = 2 ;
V_3 -> V_95 = 7 ;
} else {
F_6 ( L_19
L_20 , V_13 ,
V_3 -> V_70 [ 0 ] , V_3 -> V_70 [ 1 ] ) ;
V_3 -> V_95 = 0 ;
}
}
V_63 -- ;
break;
case 5 :
V_3 -> V_70 [ V_3 -> V_86 ++ ] = * V_29 ++ ;
if ( V_3 -> V_88 == V_89 &&
V_3 -> V_86 == 8 ) {
V_3 -> V_95 ++ ;
V_3 -> V_91 = 8 +
( V_3 -> V_70 [ 6 ] << 8 ) +
V_3 -> V_70 [ 7 ] ;
} else if ( V_3 -> V_88 ==
V_92 &&
V_3 -> V_86 == 5 ) {
V_3 -> V_95 ++ ;
V_3 -> V_91 = 5 +
( ( V_3 -> V_70 [ 3 ] & 0x0f ) << 8 ) +
V_3 -> V_70 [ 4 ] ;
}
V_63 -- ;
break;
case 6 : {
int V_96 = V_3 -> V_91 -
V_3 -> V_86 ;
if ( V_63 >= V_96 ) {
memcpy ( V_3 -> V_70 + V_3 -> V_86 ,
V_29 , V_96 ) ;
V_3 -> V_86 += V_96 ;
V_29 += V_96 ;
V_63 -= V_96 ;
V_3 -> V_95 ++ ;
} else {
memcpy ( & V_3 -> V_70 [ V_3 -> V_86 ] ,
V_29 , V_63 ) ;
V_3 -> V_86 += V_63 ;
V_63 = 0 ;
}
break;
}
case 7 : {
int V_97 = 4 ;
V_3 -> V_70 [ V_3 -> V_86 ++ ] = * V_29 ++ ;
if ( V_3 -> V_88 == V_92 &&
V_3 -> V_91 % 2 )
V_97 ++ ;
if ( V_3 -> V_86 ==
V_3 -> V_91 + V_97 ) {
F_27 ( V_3 ) ;
V_3 -> V_95 = 0 ;
}
V_63 -- ;
break;
}
default:
F_6 ( L_21 ,
V_13 ) ;
V_3 -> V_95 = 0 ;
}
}
}
static void F_31 ( unsigned long V_45 )
{
struct V_2 * V_3 = (struct V_2 * ) V_45 ;
struct V_71 * V_72 ;
struct V_98 * V_99 ;
unsigned long V_77 ;
while ( 1 ) {
F_24 ( & V_3 -> V_100 , V_77 ) ;
if ( ( V_72 = V_3 -> V_101 . V_81 ) != & V_3 -> V_101 ) {
V_99 = F_25 ( V_72 , struct V_98 ,
V_101 ) ;
F_32 ( & V_99 -> V_101 ) ;
} else {
F_26 ( & V_3 -> V_100 ,
V_77 ) ;
return;
}
F_26 ( & V_3 -> V_100 , V_77 ) ;
F_30 ( V_3 , V_99 -> V_45 , V_99 -> V_63 ) ;
F_11 ( V_99 ) ;
}
}
static void F_33 ( struct V_1 * V_1 )
{
struct V_2 * V_3 = V_1 -> V_4 ;
if ( ! V_1 -> V_8 ) {
int V_28 ;
for ( V_28 = 0 ; V_28 < V_102 ; V_28 ++ ) {
struct V_103 * V_104 ;
T_2 * V_29 ;
int V_63 ;
struct V_98 * V_99 ;
V_104 = & V_1 -> V_105 [ V_28 ] ;
V_29 = V_1 -> V_106 + V_104 -> V_107 ;
V_63 = V_104 -> V_108 ;
if ( ( V_99 = F_9 ( sizeof( struct V_98 ) ,
V_16 ) ) ) {
unsigned long V_77 ;
memcpy ( V_99 -> V_45 , V_29 , V_63 ) ;
V_99 -> V_63 = V_63 ;
F_24 ( & V_3 -> V_100 ,
V_77 ) ;
F_34 ( & V_99 -> V_101 ,
& V_3 -> V_101 ) ;
F_26 ( & V_3 -> V_100 ,
V_77 ) ;
F_35 ( & V_3 -> V_109 ) ;
}
}
} else {
if ( V_1 -> V_8 != - V_10 )
F_2 ( L_22 , V_13 ,
V_1 -> V_8 ) ;
}
if ( V_3 -> V_110 )
F_5 ( V_1 , V_16 ) ;
}
static void F_36 ( struct V_2 * V_3 )
{
int V_28 , V_111 , V_112 = 0 ;
F_2 ( L_5 , V_13 ) ;
for ( V_28 = 0 ; V_28 < V_113 ; V_28 ++ ) {
int V_114 = 0 ;
struct V_1 * V_1 = V_3 -> V_115 [ V_28 ] ;
V_1 -> V_116 = V_3 -> V_36 ;
V_1 -> V_4 = V_3 ;
V_1 -> V_117 = F_33 ;
V_1 -> V_118 = V_3 -> V_119 ;
V_1 -> V_120 = V_121 ;
V_1 -> V_122 = 1 ;
V_1 -> V_123 = V_102 ;
V_1 -> V_124 = V_125 *
V_102 ;
V_1 -> V_106 = V_3 -> V_126 + V_112 ;
V_112 += V_125 * V_102 ;
for ( V_111 = 0 ; V_111 < V_102 ; V_111 ++ ) {
V_1 -> V_105 [ V_111 ] . V_107 = V_114 ;
V_1 -> V_105 [ V_111 ] . V_63 = V_125 ;
V_114 += V_125 ;
}
}
}
static void F_37 ( struct V_2 * V_3 )
{
int V_28 ;
F_2 ( L_5 , V_13 ) ;
if ( F_10 ( & V_3 -> V_127 ) )
return;
V_3 -> V_110 -- ;
if ( ! V_3 -> V_110 ) {
for ( V_28 = 0 ; V_28 < V_113 ; V_28 ++ )
F_38 ( V_3 -> V_115 [ V_28 ] ) ;
}
F_13 ( & V_3 -> V_127 ) ;
}
static int F_39 ( struct V_2 * V_3 ,
enum V_128 V_129 )
{
int V_26 = 0 ;
T_2 V_29 [] = { 0x05 } ;
if ( V_129 != V_3 -> V_129 ) {
switch ( V_129 ) {
case V_130 :
V_26 = F_40 ( V_3 -> V_36 , 0 , 0 ) ;
break;
case V_131 :
V_26 = F_8 ( V_3 , 0x80 , sizeof( V_29 ) ,
V_29 , NULL , NULL ) ;
if ( V_26 )
return V_26 ;
V_26 = F_40 ( V_3 -> V_36 , 0 , 8 ) ;
break;
case V_132 :
V_26 = F_40 ( V_3 -> V_36 , 0 , 1 ) ;
break;
}
if ( V_26 )
return V_26 ;
V_3 -> V_129 = V_129 ;
}
return 0 ;
}
static int F_41 ( struct V_2 * V_3 )
{
int V_28 , V_26 ;
F_2 ( L_5 , V_13 ) ;
if ( F_10 ( & V_3 -> V_127 ) )
return - V_133 ;
if ( ! V_3 -> V_110 ) {
F_36 ( V_3 ) ;
V_3 -> V_95 = 0 ;
V_3 -> V_61 = 0 ;
V_3 -> V_87 = 0 ;
for ( V_28 = 0 ; V_28 < V_113 ; V_28 ++ ) {
if ( ( V_26 = F_5 ( V_3 -> V_115 [ V_28 ] ,
V_16 ) ) ) {
F_6 ( L_23
L_24 , V_13 , V_28 , V_26 ) ;
while ( V_28 ) {
F_38 ( V_3 -> V_115 [ V_28 - 1 ] ) ;
V_28 -- ;
}
F_13 ( & V_3 -> V_127 ) ;
return V_26 ;
}
}
}
V_3 -> V_110 ++ ;
F_13 ( & V_3 -> V_127 ) ;
return 0 ;
}
static int F_42 ( struct V_134 * V_135 )
{
struct V_136 * V_137 = V_135 -> V_138 ;
struct V_2 * V_3 = V_137 -> V_44 ;
T_2 V_139 [] = { 0x05 } ;
int V_26 = 0 ;
F_2 ( L_5 , V_13 ) ;
F_2 ( L_25 ) ;
if ( V_135 -> V_140 & V_141 )
F_2 ( L_26 ) ;
if ( V_135 -> V_140 & V_142 )
F_2 ( L_27 ) ;
if ( V_135 -> V_140 & V_143 )
F_2 ( L_28 ) ;
F_2 ( L_9 ) ;
switch ( V_135 -> V_144 ) {
case V_57 :
F_2 ( L_29 ) ;
V_3 -> V_52 [ V_53 ] = V_135 -> V_52 ;
V_3 -> V_52 [ V_57 ] = V_135 -> V_52 ;
V_3 -> V_50 = V_135 -> V_76 ;
F_18 ( V_3 ) ;
break;
case V_55 :
F_2 ( L_30 ) ;
V_3 -> V_52 [ V_55 ] = V_135 -> V_52 ;
V_3 -> V_46 = V_135 -> V_76 ;
F_18 ( V_3 ) ;
break;
case V_145 :
V_3 -> V_52 [ V_145 ] = V_135 -> V_52 ;
F_2 ( L_31 ) ;
return - V_146 ;
case V_53 :
F_2 ( L_32 ) ;
V_3 -> V_52 [ V_53 ] = V_135 -> V_52 ;
F_18 ( V_3 ) ;
break;
case V_147 :
F_2 ( L_33 ) ;
return - V_146 ;
default:
F_2 ( L_34 , V_135 -> V_144 ) ;
return - V_148 ;
}
V_26 = F_8 ( V_3 , 0x80 , sizeof( V_139 ) , V_139 , NULL , NULL ) ;
if ( V_26 )
return V_26 ;
V_3 -> V_90 ++ ;
return F_41 ( V_3 ) ;
}
static int F_43 ( struct V_134 * V_135 )
{
struct V_2 * V_3 = V_135 -> V_138 -> V_44 ;
T_2 V_139 [] = { 0x00 , 0x00 , 0x00 , 0x01 ,
0x00 , 0x00 , 0x00 , 0x00 ,
0x00 , 0x00 , 0x00 , 0x00 ,
0x00 , 0x00 , 0x00 , 0x00 ,
0x00 , 0xff , 0x00 , 0x00 ,
0x00 , 0x00 , 0x00 , 0x00 ,
0x00 , 0x00 , 0x00 , 0x00 ,
0x00 } ;
T_5 V_52 ;
T_2 V_42 [ V_30 ] ;
int V_43 ;
int V_26 ;
struct V_73 * V_74 ;
unsigned long V_77 ;
T_2 V_149 = 1 ;
F_2 ( L_5 , V_13 ) ;
V_52 = F_19 ( V_135 -> V_52 ) ;
memcpy ( & V_139 [ 0 ] , & V_52 , 2 ) ;
memcpy ( & V_139 [ 4 ] , & V_149 , 1 ) ;
memcpy ( & V_139 [ 5 ] , & V_135 -> V_76 -> V_76 . V_150 [ 0 ] , 1 ) ;
V_26 = F_8 ( V_3 , 0x60 , sizeof( V_139 ) , V_139 ,
& V_43 , V_42 ) ;
if ( ! V_26 ) {
if ( V_43 == 2 ) {
if ( ! ( V_74 = F_9 ( sizeof( struct V_73 ) ,
V_16 ) ) )
return - V_32 ;
V_74 -> V_82 = V_42 [ 1 ] ;
V_74 -> V_76 = V_135 -> V_76 ;
F_24 ( & V_3 -> V_79 , V_77 ) ;
F_34 ( & V_74 -> V_80 ,
& V_3 -> V_80 ) ;
F_26 ( & V_3 -> V_79 ,
V_77 ) ;
V_135 -> V_44 = V_74 ;
V_3 -> V_93 ++ ;
return F_41 ( V_3 ) ;
}
return - V_133 ;
} else
return V_26 ;
}
static int F_44 ( struct V_134 * V_135 )
{
struct V_136 * V_137 = V_135 -> V_138 ;
F_2 ( L_5 , V_13 ) ;
if ( ! V_137 -> V_151 . V_152 )
return - V_148 ;
F_2 ( L_35 , V_135 -> V_52 ) ;
switch ( V_135 -> type ) {
case V_153 :
return F_42 ( V_135 ) ;
break;
case V_154 :
return F_43 ( V_135 ) ;
break;
default:
F_2 ( L_36 , V_135 -> type ) ;
return - V_148 ;
}
}
static int F_45 ( struct V_134 * V_135 )
{
struct V_2 * V_3 = V_135 -> V_138 -> V_44 ;
T_2 V_139 [] = { 0x00 } ;
F_8 ( V_3 , 0x81 , sizeof( V_139 ) , V_139 , NULL , NULL ) ;
V_3 -> V_90 -- ;
F_37 ( V_3 ) ;
return 0 ;
}
static int F_46 ( struct V_134 * V_135 )
{
struct V_2 * V_3 = V_135 -> V_138 -> V_44 ;
T_2 V_139 [] = { 0x00 , 0x00 } ;
struct V_73 * V_74 = (struct V_73 * ) V_135 -> V_44 ;
unsigned long V_77 ;
V_139 [ 1 ] = V_74 -> V_82 ;
F_24 ( & V_3 -> V_79 , V_77 ) ;
F_32 ( & V_74 -> V_80 ) ;
F_26 ( & V_3 -> V_79 , V_77 ) ;
F_11 ( V_74 ) ;
F_8 ( V_3 , 0x62 , sizeof( V_139 ) , V_139 , NULL , NULL ) ;
V_3 -> V_93 -- ;
F_37 ( V_3 ) ;
return 0 ;
}
static int F_47 ( struct V_134 * V_135 )
{
F_2 ( L_5 , V_13 ) ;
switch ( V_135 -> type ) {
case V_153 :
return F_45 ( V_135 ) ;
break;
case V_154 :
return F_46 ( V_135 ) ;
break;
}
return 0 ;
}
static void F_48 ( struct V_2 * V_3 )
{
int V_28 ;
F_2 ( L_5 , V_13 ) ;
for ( V_28 = 0 ; V_28 < V_113 ; V_28 ++ )
F_49 ( V_3 -> V_115 [ V_28 ] ) ;
F_50 ( NULL ,
V_125 * ( V_102 *
V_113 ) ,
V_3 -> V_126 , V_3 -> V_155 ) ;
}
static int F_51 ( struct V_2 * V_3 )
{
int V_28 ;
F_2 ( L_5 , V_13 ) ;
V_3 -> V_126 = F_52 ( NULL ,
V_125 * ( V_102 * V_113 ) ,
& V_3 -> V_155 ) ;
if ( ! V_3 -> V_126 ) {
F_2 ( L_37 ,
V_13 ) ;
return - V_32 ;
}
for ( V_28 = 0 ; V_28 < V_113 ; V_28 ++ ) {
struct V_1 * V_1 ;
if ( ! ( V_1 = F_53 ( V_102 , V_16 ) ) ) {
F_48 ( V_3 ) ;
return - V_32 ;
}
V_3 -> V_115 [ V_28 ] = V_1 ;
}
F_36 ( V_3 ) ;
return 0 ;
}
static void F_54 ( struct V_2 * V_3 )
{
F_55 ( & V_3 -> V_100 ) ;
F_56 ( & V_3 -> V_101 ) ;
F_57 ( & V_3 -> V_109 , F_31 ,
( unsigned long ) V_3 ) ;
}
static int F_58 ( struct V_2 * V_3 )
{
struct V_156 * V_156 ;
T_2 V_29 [] = { 0x00 , 0x01 } ;
int V_28 ;
int V_157 ;
F_59 ( V_3 -> V_36 , V_3 -> V_158 , sizeof( V_3 -> V_158 ) ) ;
F_60 ( V_3 -> V_158 , L_38 , sizeof( V_3 -> V_158 ) ) ;
V_156 = F_61 () ;
if ( ! V_156 )
return - V_32 ;
V_156 -> V_159 = L_39 ;
V_156 -> V_160 = V_3 -> V_158 ;
V_156 -> V_161 [ 0 ] = F_62 ( V_162 ) ;
V_156 -> V_163 = sizeof( T_1 ) ;
V_156 -> V_164 = 0x1a ;
V_156 -> V_165 = V_15 ;
for ( V_28 = 0 ; V_28 < F_63 ( V_15 ) ; V_28 ++ )
F_64 ( V_15 [ V_28 ] , V_156 -> V_166 ) ;
V_157 = F_65 ( V_156 ) ;
if ( V_157 ) {
F_66 ( V_156 ) ;
return V_157 ;
}
V_3 -> V_14 = V_156 ;
if ( F_5 ( V_3 -> V_167 , V_31 ) )
F_6 ( L_40 , V_13 ) ;
F_8 ( V_3 , 0xb0 , sizeof( V_29 ) , V_29 , NULL , NULL ) ;
return 0 ;
}
static void F_67 ( struct V_2 * V_3 )
{
F_2 ( L_5 , V_13 ) ;
V_3 -> V_69 [ 0 ] = 0x00 ;
V_3 -> V_69 [ 1 ] = 0x00 ;
V_3 -> V_69 [ 2 ] = 0x01 ;
V_3 -> V_69 [ 3 ] = 0xe0 ;
}
static int F_68 ( struct V_2 * V_3 )
{
int V_26 ;
F_2 ( L_5 , V_13 ) ;
F_69 ( & V_3 -> V_33 ) ;
F_69 ( & V_3 -> V_127 ) ;
V_3 -> V_37 = F_70 ( V_3 -> V_36 , V_168 ) ;
V_3 -> V_38 = F_71 ( V_3 -> V_36 , V_169 ) ;
V_3 -> V_119 = F_72 ( V_3 -> V_36 , V_170 ) ;
V_3 -> V_171 = F_73 ( V_3 -> V_36 , V_172 ) ;
V_3 -> V_173 = F_74 ( V_3 -> V_36 , V_174 ) ;
if( V_175 ) {
V_3 -> V_167 = F_53 ( 0 , V_31 ) ;
if( ! V_3 -> V_167 ) {
return - V_32 ;
}
V_3 -> V_6 = F_75 ( V_3 -> V_36 , V_176 ,
V_31 , & V_3 -> V_177 ) ;
if( ! V_3 -> V_6 ) {
F_49 ( V_3 -> V_167 ) ;
return - V_32 ;
}
F_76 ( V_3 -> V_167 , V_3 -> V_36 , V_3 -> V_173 ,
V_3 -> V_6 , V_176 ,
F_1 , V_3 , 1 ) ;
V_3 -> V_167 -> V_178 = V_3 -> V_177 ;
V_3 -> V_167 -> V_120 |= V_179 ;
}
V_26 = F_51 ( V_3 ) ;
if ( V_26 ) {
F_49 ( V_3 -> V_167 ) ;
F_77 ( V_3 -> V_36 , V_176 ,
V_3 -> V_6 , V_3 -> V_177 ) ;
}
return V_26 ;
}
static int F_78 ( struct V_2 * V_3 )
{
int V_28 , V_111 , V_27 , V_26 , V_180 , V_34 ;
T_2 V_139 [] = { 0x00 , 0x00 , 0x00 , 0x00 ,
0x00 , 0x00 , 0x00 , 0x00 ,
0x61 , 0x00 } ;
T_2 V_181 [] = { 0x61 } ;
T_2 * V_29 ;
char V_182 [ 21 ] ;
const T_2 * V_183 = NULL ;
T_3 V_184 = 0 ;
T_1 V_185 = 0 ;
T_5 V_186 ;
T_4 V_187 ;
T_6 V_188 , V_189 ;
T_4 V_20 ;
const struct V_183 * V_190 = NULL ;
F_2 ( L_5 , V_13 ) ;
V_26 = F_79 ( & V_190 , V_3 -> V_191 , & V_3 -> V_36 -> V_116 ) ;
if ( V_26 ) {
F_6 ( V_192 L_41 ,
V_13 , V_3 -> V_191 ) ;
return V_26 ;
}
V_183 = V_190 -> V_45 ;
V_184 = V_190 -> V_180 ;
if ( V_184 < 60 ) {
F_6 ( L_42 ,
V_13 , V_184 ) ;
F_80 ( V_190 ) ;
return - V_10 ;
}
V_188 = F_81 ( ~ 0L , V_183 , 56 ) ^ ~ 0L ;
memcpy ( & V_20 , & V_183 [ 56 ] , 4 ) ;
V_189 = F_15 ( V_20 ) ;
if ( V_188 != V_189 ) {
F_6 ( L_43
L_44 ,
V_13 , V_188 , V_189 ) ;
F_80 ( V_190 ) ;
return - V_10 ;
}
memcpy ( V_182 , & V_183 [ 36 ] , 20 ) ;
V_182 [ 20 ] = '\0' ;
F_6 ( V_193 L_45 , V_182 ) ;
V_187 = F_82 ( V_184 ) ;
memcpy ( V_139 , & V_187 , 4 ) ;
V_185 = F_7 ( ~ 0 , V_183 , V_184 ) ^ ~ 0 ;
V_186 = F_19 ( V_185 ) ;
memcpy ( & V_139 [ 6 ] , & V_186 , 2 ) ;
V_26 = F_8 ( V_3 , 0x41 , sizeof( V_139 ) , V_139 , NULL , NULL ) ;
if ( V_26 ) {
F_80 ( V_190 ) ;
return V_26 ;
}
V_34 = 0 ;
V_111 = 0 ;
V_29 = F_9 ( V_194 , V_31 ) ;
if ( V_29 == NULL ) {
F_80 ( V_190 ) ;
return - V_32 ;
}
for ( V_28 = 0 ; V_28 < V_184 ; V_28 += V_30 ) {
V_180 = V_184 - V_28 ;
if ( V_180 > V_30 )
V_180 = V_30 ;
V_29 [ V_111 + 0 ] = 0xaa ;
V_29 [ V_111 + 1 ] = V_34 ++ ;
V_29 [ V_111 + 2 ] = 0xf0 ;
V_29 [ V_111 + 3 ] = V_180 ;
memcpy ( & V_29 [ V_111 + 4 ] , & V_183 [ V_28 ] , V_180 ) ;
V_111 += V_30 + 4 ;
if ( V_111 >= V_194 ) {
V_26 = F_12 ( V_3 -> V_36 , V_3 -> V_37 , V_29 ,
V_194 , & V_27 ,
100 ) ;
V_111 = 0 ;
} else if ( V_180 < V_30 ) {
V_26 = F_12 ( V_3 -> V_36 , V_3 -> V_37 , V_29 ,
V_111 - V_30 + V_180 ,
& V_27 , 100 ) ;
}
}
V_26 = F_8 ( V_3 , 0x43 , sizeof( V_181 ) , V_181 , NULL , NULL ) ;
F_80 ( V_190 ) ;
F_11 ( V_29 ) ;
return V_26 ;
}
static int F_83 ( struct V_2 * V_3 )
{
int V_26 ;
unsigned int V_39 = 0 , V_40 = 0 , V_41 = 0 ;
F_2 ( L_5 , V_13 ) ;
V_26 = F_14 ( V_3 , & V_39 , & V_40 , & V_41 ) ;
if ( V_26 )
return V_26 ;
if ( ! V_39 ) {
if ( V_41 == 0xABCDEFAB )
F_6 ( V_193 L_46
L_47 ) ;
else
F_6 ( V_193 L_48
L_49 ,
V_41 >> 24 , ( V_41 >> 16 ) & 0xff ,
( V_41 >> 8 ) & 0xff , V_41 & 0xff ) ;
V_26 = F_78 ( V_3 ) ;
if ( V_26 )
return V_26 ;
} else {
switch ( V_40 ) {
case 0x00070001 :
case 0x00070008 :
case 0x0007000c :
F_84 ( V_3 , V_195 ) ;
break;
case 0x00070009 :
case 0x00070013 :
F_84 ( V_3 , V_196 ) ;
break;
case 0x00070011 :
F_84 ( V_3 , V_197 ) ;
break;
default:
F_6 ( V_192 L_50
L_51 ,
V_13 , V_40 ) ;
return - V_10 ;
}
if ( V_41 >= 0x01770000 )
V_3 -> V_198 = 1 ;
}
return 0 ;
}
static int F_85 ( struct V_2 * V_3 )
{
int V_26 ;
F_2 ( L_5 , V_13 ) ;
if ( ( V_26 = F_86 ( & V_3 -> V_199 ,
V_3 -> V_200 , V_201 ,
& V_3 -> V_36 -> V_116 ,
V_202 ) ) < 0 ) {
F_6 ( L_52 ,
V_13 , V_26 ) ;
return V_26 ;
}
V_3 -> V_138 . V_151 . V_203 = V_204 | V_205 ;
V_3 -> V_138 . V_44 = ( void * ) V_3 ;
V_3 -> V_138 . V_206 = 31 ;
V_3 -> V_138 . V_207 = 31 ;
V_3 -> V_138 . V_208 = F_44 ;
V_3 -> V_138 . V_209 = F_47 ;
V_3 -> V_138 . V_210 = NULL ;
if ( ( V_26 = F_87 ( & V_3 -> V_138 ) ) < 0 ) {
F_6 ( L_53 , V_13 ,
V_26 ) ;
F_88 ( & V_3 -> V_199 ) ;
return V_26 ;
}
V_3 -> V_211 . V_206 = 32 ;
V_3 -> V_211 . V_138 = & V_3 -> V_138 . V_151 ;
V_3 -> V_211 . V_203 = 0 ;
if ( ( V_26 = F_89 ( & V_3 -> V_211 , & V_3 -> V_199 ) ) < 0 ) {
F_6 ( L_54 ,
V_13 , V_26 ) ;
F_90 ( & V_3 -> V_138 ) ;
F_88 ( & V_3 -> V_199 ) ;
return V_26 ;
}
V_3 -> V_152 . V_212 = V_213 ;
if ( ( V_26 = V_3 -> V_138 . V_151 . V_214 ( & V_3 -> V_138 . V_151 ,
& V_3 -> V_152 ) ) < 0 ) {
F_6 ( L_53 , V_13 ,
V_26 ) ;
F_91 ( & V_3 -> V_211 ) ;
F_90 ( & V_3 -> V_138 ) ;
F_88 ( & V_3 -> V_199 ) ;
return V_26 ;
}
if ( ( V_26 = V_3 -> V_138 . V_151 . V_215 ( & V_3 -> V_138 . V_151 ,
& V_3 -> V_152 ) ) < 0 ) {
F_6 ( L_53 , V_13 ,
V_26 ) ;
V_3 -> V_138 . V_151 . V_216 ( & V_3 -> V_138 . V_151 , & V_3 -> V_152 ) ;
F_91 ( & V_3 -> V_211 ) ;
F_90 ( & V_3 -> V_138 ) ;
F_88 ( & V_3 -> V_199 ) ;
return V_26 ;
}
F_92 ( & V_3 -> V_199 , & V_3 -> V_217 , & V_3 -> V_138 . V_151 ) ;
return 0 ;
}
static void F_93 ( struct V_2 * V_3 )
{
F_2 ( L_5 , V_13 ) ;
F_94 ( & V_3 -> V_217 ) ;
V_3 -> V_138 . V_151 . V_218 ( & V_3 -> V_138 . V_151 ) ;
V_3 -> V_138 . V_151 . V_216 ( & V_3 -> V_138 . V_151 , & V_3 -> V_152 ) ;
F_91 ( & V_3 -> V_211 ) ;
F_90 ( & V_3 -> V_138 ) ;
if ( V_3 -> V_219 ) {
F_95 ( V_3 -> V_219 ) ;
if ( V_3 -> V_219 -> V_220 . V_221 )
V_3 -> V_219 -> V_220 . V_221 ( V_3 -> V_219 ) ;
}
F_88 ( & V_3 -> V_199 ) ;
}
static void F_96 ( struct V_2 * V_3 )
{
F_2 ( L_5 , V_13 ) ;
if ( V_3 -> V_14 ) {
F_97 ( V_3 -> V_14 ) ;
V_3 -> V_14 = NULL ;
}
}
static void F_98 ( struct V_2 * V_3 )
{
int V_28 ;
F_2 ( L_5 , V_13 ) ;
if ( V_175 ) {
if ( V_3 -> V_129 == V_131 )
F_38 ( V_3 -> V_167 ) ;
F_49 ( V_3 -> V_167 ) ;
F_77 ( V_3 -> V_36 , V_176 ,
V_3 -> V_6 , V_3 -> V_177 ) ;
}
V_3 -> V_110 = 0 ;
for ( V_28 = 0 ; V_28 < V_113 ; V_28 ++ )
F_38 ( V_3 -> V_115 [ V_28 ] ) ;
F_48 ( V_3 ) ;
}
static void F_99 ( struct V_2 * V_3 )
{
struct V_71 * V_72 ;
struct V_98 * V_99 ;
F_100 ( & V_3 -> V_109 ) ;
while ( ( V_72 = V_3 -> V_101 . V_81 ) != & V_3 -> V_101 ) {
V_99 = F_25 ( V_72 , struct V_98 , V_101 ) ;
F_32 ( & V_99 -> V_101 ) ;
F_11 ( V_99 ) ;
}
}
static void F_101 ( struct V_2 * V_3 )
{
F_56 ( & V_3 -> V_80 ) ;
F_55 ( & V_3 -> V_79 ) ;
}
static void F_102 ( struct V_2 * V_3 )
{
struct V_71 * V_72 ;
struct V_73 * V_74 ;
while ( ( V_72 = V_3 -> V_80 . V_81 ) != & V_3 -> V_80 ) {
V_74 = F_25 ( V_72 , struct V_73 , V_80 ) ;
F_32 ( & V_74 -> V_80 ) ;
F_11 ( V_74 ) ;
}
}
static int F_103 ( struct V_222 * V_219 , const T_2 V_21 ,
int V_22 , const T_2 V_23 [] ,
int * V_24 , T_2 V_25 [] )
{
struct V_2 * V_3 = V_219 -> V_223 -> V_44 ;
return F_8 ( V_3 , V_21 , V_22 , V_23 , V_24 , V_25 ) ;
}
static int F_104 ( struct V_224 * V_225 ,
const struct V_226 * V_227 )
{
struct V_228 * V_36 ;
struct V_2 * V_3 ;
int V_26 ;
F_2 ( L_5 , V_13 ) ;
V_36 = F_105 ( V_225 ) ;
if ( ! ( V_3 = F_106 ( sizeof( struct V_2 ) , V_31 ) ) ) {
F_6 ( L_55 , V_13 ) ;
return - V_32 ;
}
F_107 ( V_225 , ( void * ) V_3 ) ;
switch ( V_227 -> V_229 ) {
case 0x1006 :
F_84 ( V_3 , V_195 ) ;
break;
case 0x1008 :
F_84 ( V_3 , V_196 ) ;
break;
case 0x1009 :
F_84 ( V_3 , V_197 ) ;
break;
}
V_3 -> V_36 = V_36 ;
V_26 = F_68 ( V_3 ) ;
if ( V_26 )
goto V_230;
V_26 = F_83 ( V_3 ) ;
if ( V_26 )
goto V_231;
V_26 = F_85 ( V_3 ) ;
if ( V_26 )
goto V_231;
V_3 -> V_199 . V_44 = V_3 ;
switch ( V_227 -> V_229 ) {
case 0x1006 :
V_3 -> V_219 = F_108 ( & V_232 ) ;
break;
case 0x1008 :
case 0x1009 :
V_3 -> V_219 = F_109 ( & V_232 ) ;
break;
}
if ( V_3 -> V_219 == NULL ) {
F_6 ( L_56 ,
F_110 ( V_3 -> V_36 -> V_233 . V_234 ) ,
F_110 ( V_3 -> V_36 -> V_233 . V_229 ) ) ;
} else {
if ( F_111 ( & V_3 -> V_199 , V_3 -> V_219 ) ) {
F_6 ( L_57 ) ;
if ( V_3 -> V_219 -> V_220 . V_221 )
V_3 -> V_219 -> V_220 . V_221 ( V_3 -> V_219 ) ;
V_3 -> V_219 = NULL ;
}
}
F_67 ( V_3 ) ;
F_101 ( V_3 ) ;
F_54 ( V_3 ) ;
V_3 -> V_235 = 1 ;
F_39 ( V_3 , V_131 ) ;
if ( V_175 )
F_58 ( V_3 ) ;
return 0 ;
V_231:
F_98 ( V_3 ) ;
V_230:
F_11 ( V_3 ) ;
return V_26 ;
}
static void F_112 ( struct V_224 * V_225 )
{
struct V_2 * V_3 = F_113 ( V_225 ) ;
F_107 ( V_225 , NULL ) ;
F_2 ( L_5 , V_13 ) ;
if ( V_3 -> V_235 ) {
F_99 ( V_3 ) ;
F_102 ( V_3 ) ;
if( V_175 )
F_96 ( V_3 ) ;
F_98 ( V_3 ) ;
F_93 ( V_3 ) ;
}
F_11 ( V_3 ) ;
}
static void F_84 ( struct V_2 * V_3 ,
enum V_236 V_40 )
{
V_3 -> V_40 = V_40 ;
switch ( V_40 ) {
case V_196 :
V_3 -> V_200 = L_58 ;
V_3 -> V_191 = L_59 ;
break;
case V_197 :
V_3 -> V_200 = L_60 ;
V_3 -> V_191 = L_61 ;
break;
case V_195 :
V_3 -> V_200 = L_62 ;
V_3 -> V_191 = L_63 ;
break;
}
}
