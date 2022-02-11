T_1 F_1 ( T_2 * V_1 )
{
T_3 V_2 = 0 ;
while ( V_1 [ V_2 ] != 0 ) {
if ( ( ( ( V_1 [ V_2 ] ) & 0x7f ) == 2 ) || ( ( ( V_1 [ V_2 ] ) & 0x7f ) == 4 ) ||
( ( ( V_1 [ V_2 ] ) & 0x7f ) == 11 ) || ( ( ( V_1 [ V_2 ] ) & 0x7f ) == 22 ) )
return true ;
V_2 ++ ;
}
return false ;
}
T_1 F_2 ( T_2 * V_1 )
{
T_3 V_2 = 0 ;
while ( V_1 [ V_2 ] != 0 ) {
if ( ( ( ( V_1 [ V_2 ] ) & 0x7f ) != 2 ) && ( ( ( V_1 [ V_2 ] ) & 0x7f ) != 4 ) &&
( ( ( V_1 [ V_2 ] ) & 0x7f ) != 11 ) && ( ( ( V_1 [ V_2 ] ) & 0x7f ) != 22 ) )
return false ;
V_2 ++ ;
}
return true ;
}
T_2 * F_3 ( T_2 * V_3 , T_4 V_4 , T_1 V_5 , T_2 * V_6 , T_1 * V_7 )
{
* V_3 = ( T_2 ) V_4 ;
* ( V_3 + 1 ) = ( T_2 ) V_5 ;
if ( V_5 > 0 )
memcpy ( ( void * ) ( V_3 + 2 ) , ( void * ) V_6 , V_5 ) ;
* V_7 = * V_7 + ( V_5 + 2 ) ;
return V_3 + V_5 + 2 ;
}
T_2 * F_4 ( T_2 * V_3 , T_4 V_4 , T_4 * V_5 , T_4 V_8 )
{
T_4 V_9 , V_2 ;
T_2 * V_10 ;
if ( V_8 < 1 )
return NULL ;
V_10 = V_3 ;
V_2 = 0 ;
* V_5 = 0 ;
while ( 1 ) {
if ( * V_10 == V_4 ) {
* V_5 = * ( V_10 + 1 ) ;
return V_10 ;
} else {
V_9 = * ( V_10 + 1 ) ;
V_10 += ( V_9 + 2 ) ;
V_2 += ( V_9 + 2 ) ;
}
if ( V_2 >= V_8 )
break;
}
return NULL ;
}
static void F_5 ( T_2 * V_11 , T_1 V_12 )
{
memset ( V_11 , 0 , V_13 ) ;
switch ( V_12 ) {
case V_14 :
memcpy ( V_11 , V_15 ,
V_16 ) ;
break;
case V_17 :
case V_18 :
memcpy ( V_11 , V_19 ,
V_20 ) ;
break;
case V_21 :
memcpy ( V_11 , V_15 , V_16 ) ;
memcpy ( V_11 + V_16 , V_19 ,
V_20 ) ;
break;
}
}
static T_1 F_6 ( T_2 * V_22 )
{
T_1 V_2 = 0 ;
while ( 1 ) {
if ( ( V_22 [ V_2 ] ) == 0 )
break;
if ( V_2 > 12 )
break;
V_2 ++ ;
}
return V_2 ;
}
int F_7 ( struct V_23 * V_24 ,
struct V_25 * V_26 )
{
int V_27 = 0 , V_28 ;
struct V_29 * V_30 = & V_24 -> V_31 ;
T_2 * V_32 = V_30 -> V_33 ;
struct V_34 V_35 ;
struct V_36 V_37 ;
unsigned char V_38 [] = { 0x00 , 0x50 , 0xf2 , 0x02 , 0x00 , 0x01 , 0x00 } ;
struct V_39 * V_40 = & V_26 -> V_41 ;
struct V_42 * V_43 = & V_40 -> V_44 ;
V_27 += 8 ;
V_32 += V_27 ;
* ( V_45 * ) V_32 = F_8 ( ( V_45 ) V_30 -> V_46 . V_47 ) ;
V_27 += 2 ;
V_32 += 2 ;
* ( V_45 * ) V_32 = 0 ;
* ( V_45 * ) V_32 |= F_8 ( V_48 ) ;
if ( V_24 -> V_49 == V_50 )
* ( V_45 * ) V_32 |= F_8 ( V_51 ) ;
if ( V_30 -> V_52 )
* ( V_45 * ) V_32 |= F_8 ( V_53 ) ;
V_27 += 2 ;
V_32 += 2 ;
V_32 = F_3 ( V_32 , V_54 , V_30 -> V_55 . V_56 ,
V_30 -> V_55 . V_55 , & V_27 ) ;
F_5 ( V_30 -> V_11 ,
V_24 -> V_57 ) ;
V_28 = F_6 ( V_30 -> V_11 ) ;
if ( V_28 > 8 ) {
V_32 = F_3 ( V_32 , V_58 , 8 ,
V_30 -> V_11 , & V_27 ) ;
V_32 = F_3 ( V_32 , V_59 , ( V_28 - 8 ) ,
( V_30 -> V_11 + 8 ) , & V_27 ) ;
} else
V_32 = F_3 ( V_32 , V_58 ,
V_28 , V_30 -> V_11 , & V_27 ) ;
V_32 = F_3 ( V_32 , V_60 , 1 ,
( T_2 * ) & ( V_30 -> V_46 . V_61 ) , & V_27 ) ;
V_32 = F_3 ( V_32 , V_62 , 2 ,
( T_2 * ) & ( V_30 -> V_46 . V_63 ) , & V_27 ) ;
if ( V_24 -> V_64 == 1 ) {
if ( V_43 -> V_65 == 0 ) {
V_32 = F_3 ( V_32 , V_66 ,
V_67 , V_38 , & V_27 ) ;
V_43 -> V_65 = 1 ;
}
memset ( & V_35 , 0 , sizeof( struct V_34 ) ) ;
V_35 . V_68 = V_69 |
V_70 |
V_71 |
V_72 |
V_73 |
V_74 ;
V_35 . V_75 = ( V_76 &
0x03 ) | ( V_77 & 0x00 ) ;
V_32 = F_3 ( V_32 , V_78 ,
sizeof( struct V_34 ) ,
( unsigned char * ) & V_35 , & V_27 ) ;
memset ( & V_37 , 0 ,
sizeof( struct V_36 ) ) ;
V_37 . V_79 = V_24 -> V_80 ;
V_32 = F_3 ( V_32 , V_81 ,
sizeof( struct V_36 ) ,
( unsigned char * ) & V_37 , & V_27 ) ;
}
return V_27 ;
}
unsigned char * F_9 ( unsigned char * V_82 , int * V_83 , int V_8 )
{
int V_5 ;
V_45 V_84 ;
unsigned char V_85 [] = { 0x00 , 0x50 , 0xf2 , 0x01 } ;
T_2 * V_3 = V_82 ;
while ( 1 ) {
V_3 = F_4 ( V_3 , V_86 , & V_5 , V_8 ) ;
if ( V_3 ) {
if ( memcmp ( ( V_3 + 2 ) , V_85 ,
sizeof( V_85 ) ) )
goto V_87;
memcpy ( ( T_2 * ) & V_84 , ( V_3 + 6 ) , sizeof( V_84 ) ) ;
V_84 = F_10 ( V_84 ) ;
if ( V_84 != 0x0001 )
goto V_87;
* V_83 = * ( V_3 + 1 ) ;
return V_3 ;
} else {
* V_83 = 0 ;
return NULL ;
}
V_87:
V_8 = V_8 - ( V_3 - V_82 ) - 2 - V_5 ;
if ( V_8 <= 0 )
break;
V_3 += ( 2 + V_5 ) ;
}
* V_83 = 0 ;
return NULL ;
}
unsigned char * F_11 ( unsigned char * V_82 , int * V_88 , int V_8 )
{
return F_4 ( V_82 , V_89 , V_88 , V_8 ) ;
}
static int F_12 ( T_2 * V_90 )
{
if ( ! memcmp ( V_90 , ( void * ) V_91 , V_92 ) )
return V_93 ;
if ( ! memcmp ( V_90 , ( void * ) V_94 , V_92 ) )
return V_95 ;
if ( ! memcmp ( V_90 , ( void * ) V_96 , V_92 ) )
return V_97 ;
if ( ! memcmp ( V_90 , ( void * ) V_98 , V_92 ) )
return V_99 ;
if ( ! memcmp ( V_90 , ( void * ) V_100 , V_92 ) )
return V_101 ;
return 0 ;
}
static int F_13 ( T_2 * V_90 )
{
if ( ! memcmp ( V_90 , ( void * ) V_102 , V_103 ) )
return V_93 ;
if ( ! memcmp ( V_90 , ( void * ) V_104 , V_103 ) )
return V_95 ;
if ( ! memcmp ( V_90 , ( void * ) V_105 , V_103 ) )
return V_97 ;
if ( ! memcmp ( V_90 , ( void * ) V_106 , V_103 ) )
return V_99 ;
if ( ! memcmp ( V_90 , ( void * ) V_107 , V_103 ) )
return V_101 ;
return 0 ;
}
int F_14 ( T_2 * V_108 , int V_83 , int * V_109 ,
int * V_110 )
{
int V_2 , V_111 = V_112 ;
int V_113 , V_114 ;
T_2 * V_115 ;
if ( V_83 <= 0 ) {
return V_116 ;
}
if ( ( * V_108 != V_86 ) || ( * ( V_108 + 1 ) != ( T_2 ) ( V_83 - 2 ) )
|| ( memcmp ( V_108 + 2 , ( void * ) V_117 , V_92 ) ) )
return V_116 ;
V_115 = V_108 ;
V_115 += 8 ;
V_113 = V_83 - 8 ;
if ( V_113 >= V_92 ) {
* V_109 = F_12 ( V_115 ) ;
V_115 += V_92 ;
V_113 -= V_92 ;
} else if ( V_113 > 0 )
return V_116 ;
if ( V_113 >= 2 ) {
V_114 = F_10 ( * ( V_45 * ) V_115 ) ;
V_115 += 2 ;
V_113 -= 2 ;
if ( V_114 == 0 || V_113 < V_114 * V_92 )
return V_116 ;
for ( V_2 = 0 ; V_2 < V_114 ; V_2 ++ ) {
* V_110 |= F_12 ( V_115 ) ;
V_115 += V_92 ;
V_113 -= V_92 ;
}
} else if ( V_113 == 1 )
return V_116 ;
return V_111 ;
}
int F_15 ( T_2 * V_118 , int V_88 , int * V_109 ,
int * V_110 )
{
int V_2 , V_111 = V_112 ;
int V_113 , V_114 ;
T_2 * V_115 ;
if ( V_88 <= 0 ) {
return V_116 ;
}
if ( ( * V_118 != V_89 ) || ( * ( V_118 + 1 ) != ( T_2 ) ( V_88 - 2 ) ) )
return V_116 ;
V_115 = V_118 ;
V_115 += 4 ;
V_113 = V_88 - 4 ;
if ( V_113 >= V_103 ) {
* V_109 = F_13 ( V_115 ) ;
V_115 += V_103 ;
V_113 -= V_103 ;
} else if ( V_113 > 0 )
return V_116 ;
if ( V_113 >= 2 ) {
V_114 = F_10 ( * ( V_45 * ) V_115 ) ;
V_115 += 2 ;
V_113 -= 2 ;
if ( V_114 == 0 || V_113 < V_114 * V_103 )
return V_116 ;
for ( V_2 = 0 ; V_2 < V_114 ; V_2 ++ ) {
* V_110 |= F_13 ( V_115 ) ;
V_115 += V_103 ;
V_113 -= V_103 ;
}
} else if ( V_113 == 1 )
return V_116 ;
return V_111 ;
}
int F_16 ( T_2 * V_119 , T_1 V_120 , T_2 * V_118 , V_45 * V_121 ,
T_2 * V_108 , V_45 * V_122 )
{
T_2 V_123 , V_124 ;
T_2 V_125 [ 4 ] = { 0x0 , 0x50 , 0xf2 , 0x01 } ;
T_1 V_126 ;
V_126 = ( V_127 + V_128 + V_129 ) ;
V_124 = 0 ;
while ( V_126 < V_120 ) {
V_123 = V_119 [ V_126 ] ;
if ( ( V_123 == V_86 ) &&
( ! memcmp ( & V_119 [ V_126 + 2 ] , & V_125 [ 0 ] , 4 ) ) ) {
memcpy ( V_108 , & V_119 [ V_126 ] , V_119 [ V_126 + 1 ] + 2 ) ;
* V_122 = V_119 [ V_126 + 1 ] + 2 ;
V_126 += V_119 [ V_126 + 1 ] + 2 ;
} else {
if ( V_123 == V_89 ) {
memcpy ( V_118 , & V_119 [ V_126 ] ,
V_119 [ V_126 + 1 ] + 2 ) ;
* V_121 = V_119 [ V_126 + 1 ] + 2 ;
V_126 += V_119 [ V_126 + 1 ] + 2 ;
} else
V_126 += V_119 [ V_126 + 1 ] + 2 ;
}
}
return * V_121 + * V_122 ;
}
int F_17 ( T_2 * V_119 , T_1 V_120 , T_2 * V_130 , T_1 * V_131 )
{
int V_132 ;
T_1 V_126 ;
T_2 V_133 , V_134 [ 4 ] = { 0x0 , 0x50 , 0xf2 , 0x04 } ;
V_126 = 12 ;
V_132 = false ;
while ( V_126 < V_120 ) {
V_133 = V_119 [ V_126 ] ;
if ( ( V_133 == V_86 ) &&
( ! memcmp ( & V_119 [ V_126 + 2 ] , V_134 , 4 ) ) ) {
memcpy ( V_130 , & V_119 [ V_126 ] , V_119 [ V_126 + 1 ] + 2 ) ;
* V_131 = V_119 [ V_126 + 1 ] + 2 ;
V_126 += V_119 [ V_126 + 1 ] + 2 ;
V_132 = true ;
break;
} else
V_126 += V_119 [ V_126 + 1 ] + 2 ;
}
return V_132 ;
}
