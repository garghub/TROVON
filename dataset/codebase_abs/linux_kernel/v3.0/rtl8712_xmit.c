T_1 F_1 ( struct V_1 * V_2 , T_2 V_3 )
{
V_2 -> V_3 = V_3 ;
switch ( V_3 ) {
case V_4 :
V_2 -> V_5 = V_6 ;
break;
case V_7 :
V_2 -> V_5 = V_8 ;
break;
case V_9 :
V_2 -> V_5 = V_10 ;
break;
case V_11 :
V_2 -> V_5 = V_12 ;
break;
case V_13 :
V_2 -> V_5 = V_6 ;
break;
}
return V_14 ;
}
int F_2 ( struct V_15 * V_16 ,
struct V_17 * V_18 )
{
struct V_19 * V_20 ;
struct V_21 * V_22 ;
int V_23 = V_18 -> V_23 ;
V_20 = V_18 -> V_20 ;
switch ( V_23 ) {
case 1 :
case 2 :
V_22 = & ( V_20 -> V_24 . V_25 ) ;
break;
case 4 :
case 5 :
V_22 = & ( V_20 -> V_24 . V_26 ) ;
break;
case 6 :
case 7 :
V_22 = & ( V_20 -> V_24 . V_27 ) ;
break;
case 0 :
case 3 :
default:
V_22 = & ( V_20 -> V_24 . V_28 ) ;
break;
}
return V_22 -> V_29 ;
}
static T_3 F_3 ( struct V_30 * V_31 )
{
T_3 V_32 = 0 ;
struct V_17 * V_18 = & V_31 -> V_33 ;
struct V_15 * V_16 = V_31 -> V_16 ;
struct V_34 * V_35 = (struct V_34 * ) & V_16 -> V_36 ;
if ( V_31 -> V_37 == V_38 )
V_32 = V_39 ;
else if ( V_31 -> V_37 == V_40 )
V_32 = V_41 ;
else if ( V_35 -> V_42 == 6 ) {
switch ( V_18 -> V_23 ) {
case 0 :
case 3 :
V_32 = V_6 ;
break;
case 1 :
case 2 :
V_32 = V_8 ;
break;
case 4 :
case 5 :
V_32 = V_10 ;
break;
case 6 :
case 7 :
V_32 = V_12 ;
break;
case 0x10 :
case 0x11 :
case 0x12 :
case 0x13 :
V_32 = V_39 ;
break;
default:
V_32 = V_6 ;
break;
}
} else if ( V_35 -> V_42 == 4 ) {
switch ( V_18 -> V_43 ) {
case 0 :
case 3 :
case 1 :
case 2 :
V_32 = V_6 ;
break;
case 4 :
case 5 :
case 6 :
case 7 :
V_32 = V_12 ;
break;
case 0x10 :
case 0x11 :
case 0x12 :
case 0x13 :
V_32 = V_39 ;
break;
default:
V_32 = V_6 ;
break;
}
}
return V_32 ;
}
static struct V_30 * F_4 ( struct V_44 * V_45 ,
struct V_46 * V_47 ,
struct V_21 * V_22 ,
struct V_48 * V_49 )
{
struct V_50 * V_51 , * V_52 ;
struct V_30 * V_31 = NULL ;
V_52 = F_5 ( V_49 ) ;
V_51 = F_6 ( V_52 ) ;
if ( ( F_7 ( V_52 , V_51 ) ) == false ) {
V_31 = F_8 ( V_51 ,
struct V_30 , V_53 ) ;
F_9 ( & V_31 -> V_53 ) ;
V_22 -> V_29 -- ;
V_47 -> V_54 ++ ;
}
return V_31 ;
}
static struct V_30 * F_10 ( struct V_44 * V_45 ,
struct V_46 * V_55 , T_1 V_56 )
{
unsigned long V_57 ;
struct V_50 * V_58 , * V_59 ;
struct V_46 * V_47 ;
struct V_21 * V_22 = NULL ;
struct V_48 * V_49 = NULL ;
struct V_30 * V_31 = NULL ;
int V_60 , V_61 [ 4 ] ;
int V_62 , V_63 , V_64 [ 4 ] ;
V_61 [ 0 ] = 0 ; V_64 [ 0 ] = V_45 -> V_65 ;
V_61 [ 1 ] = 1 ; V_64 [ 1 ] = V_45 -> V_66 ;
V_61 [ 2 ] = 2 ; V_64 [ 2 ] = V_45 -> V_67 ;
V_61 [ 3 ] = 3 ; V_64 [ 3 ] = V_45 -> V_68 ;
for ( V_60 = 0 ; V_60 < 4 ; V_60 ++ ) {
for ( V_62 = V_60 + 1 ; V_62 < 4 ; V_62 ++ ) {
if ( V_64 [ V_62 ] < V_64 [ V_60 ] ) {
V_63 = V_64 [ V_60 ] ;
V_64 [ V_60 ] = V_64 [ V_62 ] ;
V_64 [ V_62 ] = V_63 ;
V_63 = V_61 [ V_60 ] ;
V_61 [ V_60 ] = V_61 [ V_62 ] ;
V_61 [ V_62 ] = V_63 ;
}
}
}
F_11 ( & V_45 -> V_69 , V_57 ) ;
for ( V_60 = 0 ; V_60 < V_56 ; V_60 ++ ) {
V_47 = V_55 + V_61 [ V_60 ] ;
V_59 = F_5 ( V_47 -> V_70 ) ;
V_58 = F_6 ( V_59 ) ;
while ( ( F_7 ( V_59 , V_58 ) ) == false ) {
V_22 = F_8 ( V_58 , struct V_21 ,
V_71 ) ;
V_49 = & V_22 -> V_72 ;
V_31 = F_4 ( V_45 , V_47 ,
V_22 , V_49 ) ;
if ( V_31 ) {
V_47 -> V_73 -- ;
goto V_74;
}
V_58 = F_6 ( V_58 ) ;
if ( F_12 ( V_49 ) ) {
F_9 ( & V_22 -> V_71 ) ;
}
}
}
V_74:
F_13 ( & V_45 -> V_69 , V_57 ) ;
return V_31 ;
}
void F_14 ( struct V_15 * V_16 ,
struct V_17 * V_18 )
{
T_2 V_43 = 0 ;
struct V_34 * V_35 = (struct V_34 * ) & V_16 -> V_36 ;
if ( V_35 -> V_42 == 6 )
V_43 = V_18 -> V_23 ;
else if ( V_35 -> V_42 == 4 )
V_43 = V_18 -> V_23 ;
V_18 -> V_43 = V_43 ;
}
static void F_15 ( struct V_30 * V_31 , T_4 * V_75 , int V_76 )
{
T_4 V_43 ;
struct V_15 * V_16 = V_31 -> V_16 ;
struct V_77 * V_78 = & V_16 -> V_79 ;
struct V_80 * V_81 = & V_78 -> V_82 ;
struct V_83 * V_84 = & V_16 -> V_85 ;
struct V_17 * V_18 = & V_31 -> V_33 ;
struct V_86 * V_87 = (struct V_86 * ) V_75 ;
struct V_34 * V_35 = (struct V_34 * ) & V_16 -> V_36 ;
T_2 V_88 ;
T_1 V_89 = F_16 ( V_18 -> V_90 ) ;
struct V_91 * V_92 = & V_78 -> V_93 ;
struct V_86 V_94 ;
memcpy ( & V_94 , V_87 , sizeof( struct V_86 ) ) ;
memset ( V_87 , 0 , sizeof( struct V_86 ) ) ;
V_87 -> V_95 |= F_17 ( V_76 & 0x0000ffff ) ;
if ( V_35 -> V_96 ) {
if ( ( ( V_76 + V_97 ) % 512 ) == 0 )
V_88 = 1 ;
else
V_88 = 0 ;
} else {
if ( ( ( V_76 + V_97 ) % 64 ) == 0 )
V_88 = 1 ;
else
V_88 = 0 ;
}
if ( V_88 ) {
V_87 -> V_95 |= F_17 ( ( ( V_97 + V_98 + 8 ) <<
V_99 ) & 0x00ff0000 ) ;
} else {
V_87 -> V_95 |= F_17 ( ( ( V_97 + V_98 ) <<
V_99 ) & 0x00ff0000 ) ;
}
V_87 -> V_95 |= F_17 ( V_100 | V_101 | V_102 ) ;
if ( V_31 -> V_37 == V_103 ) {
V_87 -> V_104 |= F_17 ( ( V_18 -> V_105 ) & 0x1f ) ;
V_43 = ( T_4 ) ( V_18 -> V_43 & 0x0000001f ) ;
V_87 -> V_104 |= F_17 ( ( V_43 << V_106 ) & 0x00001f00 ) ;
if ( ! V_81 -> V_107 )
V_87 -> V_104 |= F_17 ( F_18 ( 16 ) ) ;
if ( ( V_18 -> V_108 > 0 ) && ! V_18 -> V_109 ) {
switch ( V_18 -> V_108 ) {
case V_110 :
case V_111 :
V_87 -> V_104 |= F_17 ( ( 0x01 << 22 ) &
0x00c00000 ) ;
V_87 -> V_104 |= F_17 ( ( V_84 ->
V_112 << 17 ) &
0x00060000 ) ;
break;
case V_113 :
case V_114 :
V_87 -> V_104 |= F_17 ( ( 0x02 << 22 ) &
0x00c00000 ) ;
break;
case V_115 :
V_87 -> V_104 |= F_17 ( ( 0x03 << 22 ) &
0x00c00000 ) ;
break;
case V_116 :
default:
break;
}
}
if ( V_89 )
V_87 -> V_117 |= F_17 ( V_118 ) ;
V_87 -> V_119 = F_17 ( ( V_18 -> V_23 << V_120 ) &
0x0fff0000 ) ;
if ( ( V_18 -> V_121 != 0x888e ) &&
( V_18 -> V_121 != 0x0806 ) &&
( V_18 -> V_122 != 1 ) ) {
if ( V_92 -> V_123 == 1 ) {
if ( V_92 -> V_124 != true )
V_87 -> V_117 |= F_17 ( V_125 ) ;
}
} else {
V_87 -> V_126 = F_17 ( 0x80000000 ) ;
V_87 -> V_127 = F_17 ( 0x001f8000 ) ;
}
if ( V_18 -> V_128 == 1 ) {
struct V_86 * V_129 ;
V_129 = & V_94 ;
V_87 -> V_117 = F_17 ( V_129 -> V_117 ) ;
if ( V_89 )
V_87 -> V_117 |= F_17 ( V_118 ) ;
V_87 -> V_117 |= F_17 ( V_125 ) ;
V_87 -> V_126 = F_17 ( V_129 -> V_126 ) ;
V_87 -> V_127 = F_17 ( V_129 -> V_127 ) ;
V_18 -> V_128 = 0 ;
}
} else if ( V_31 -> V_37 == V_40 ) {
V_87 -> V_104 |= ( 0x05 ) & 0x1f ;
V_43 = ( T_4 ) ( V_18 -> V_43 & 0x0000001f ) ;
V_87 -> V_104 |= F_17 ( ( V_43 << V_106 ) & 0x00001f00 ) ;
V_87 -> V_104 |= F_17 ( F_18 ( 16 ) ) ;
if ( V_89 )
V_87 -> V_117 |= F_17 ( V_118 ) ;
V_87 -> V_119 = F_17 ( ( V_18 -> V_23 << V_120 ) &
0x0fff0000 ) ;
V_87 -> V_126 = F_17 ( 0x80002040 ) ;
V_87 -> V_127 = F_17 ( 0x001f8000 ) ;
} else if ( V_31 -> V_37 == V_38 ) {
V_43 = 0x13 ;
V_87 -> V_104 |= F_17 ( ( V_43 << V_106 ) & 0x00001f00 ) ;
} else {
V_43 = ( T_4 ) ( V_18 -> V_23 & 0x0000001f ) ;
V_87 -> V_104 |= F_17 ( ( V_43 << V_106 ) & 0x00001f00 ) ;
V_87 -> V_119 = F_17 ( ( V_18 -> V_130 << V_120 ) &
0x0fff0000 ) ;
V_87 -> V_126 = F_17 ( 0x80002040 ) ;
V_87 -> V_127 = F_17 ( 0x001f9600 ) ;
}
}
int F_19 ( struct V_15 * V_16 ,
struct V_44 * V_45 ,
struct V_131 * V_132 )
{
struct V_46 * V_133 ;
T_1 V_134 ;
struct V_30 * V_31 = NULL ;
int V_135 = V_14 , V_136 = 0 ;
V_133 = V_45 -> V_137 ;
V_134 = V_45 -> V_138 ;
if ( V_132 == NULL ) {
V_132 = F_20 ( V_45 ) ;
if ( ! V_132 )
return false ;
}
do {
V_31 = F_10 ( V_45 , V_133 , V_134 ) ;
if ( V_31 ) {
V_31 -> V_132 = V_132 ;
V_31 -> V_139 [ 0 ] = V_132 -> V_139 [ 0 ] ;
V_31 -> V_140 = V_132 -> V_141 ;
if ( V_31 -> V_37 == V_103 ) {
if ( V_31 -> V_33 . V_23 <= 15 )
V_135 = F_21 ( V_16 ,
V_31 -> V_142 , V_31 ) ;
F_22 ( V_16 , V_31 ) ;
}
if ( V_135 == V_14 )
F_23 ( V_16 , V_31 ) ;
else
F_24 ( V_45 , V_31 ) ;
V_136 ++ ;
} else {
F_25 ( V_45 , V_132 ) ;
return false ;
}
break;
} while ( 0 );
return true ;
}
static void F_23 ( struct V_15 * V_16 ,
struct V_30 * V_31 )
{
int V_143 , V_76 , V_144 ;
T_2 * V_145 ;
T_3 V_5 ;
struct V_17 * V_18 = & V_31 -> V_33 ;
struct V_44 * V_45 = & V_16 -> V_146 ;
struct V_83 * V_84 = & V_16 -> V_85 ;
if ( V_31 -> V_33 . V_121 != 0x0806 ) {
if ( V_31 -> V_33 . V_121 != 0x888e )
F_26 ( V_16 , V_18 -> V_23 ) ;
}
V_145 = V_31 -> V_140 ;
for ( V_143 = 0 ; V_143 < V_18 -> V_147 ; V_143 ++ ) {
if ( V_143 != ( V_18 -> V_147 - 1 ) ) {
V_76 = V_45 -> V_148 ;
V_76 = V_76 - 4 - ( V_84 -> V_149 ? 0 :
V_18 -> V_150 ) ;
V_31 -> V_151 [ V_143 ] = 0 ;
} else {
V_76 = V_18 -> V_152 ;
V_31 -> V_151 [ V_143 ] = 1 ;
}
F_15 ( V_31 , ( T_4 * ) V_145 , V_76 ) ;
V_144 = V_76 + V_97 ;
V_31 -> V_145 = V_145 ;
V_31 -> V_153 [ V_143 ] = false ;
V_5 = F_3 ( V_31 ) ;
F_27 ( V_16 , V_5 , V_144 ,
( unsigned char * ) V_31 ) ;
V_145 += V_144 ;
V_145 = ( T_2 * ) F_28 ( ( ( V_154 ) ( V_145 ) ) ) ;
}
}
int F_29 ( struct V_15 * V_16 , struct V_30 * V_31 )
{
int V_135 = V_14 ;
V_135 = F_21 ( V_16 , V_31 -> V_142 , V_31 ) ;
V_31 -> V_142 = NULL ;
if ( V_135 == V_14 )
F_23 ( V_16 , V_31 ) ;
return V_135 ;
}
int F_30 ( struct V_15 * V_16 , struct V_30 * V_31 )
{
if ( F_31 ( V_16 , V_31 ) == V_155 ) {
V_31 -> V_142 = NULL ;
return V_155 ;
}
return V_14 ;
}
