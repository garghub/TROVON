static const char *
F_1 ( int V_1 )
{
int V_2 ;
for ( V_2 = 0 ; V_3 [ V_2 ] . V_4 ; V_2 ++ ) {
if ( V_3 [ V_2 ] . V_5 == V_1 ) {
return V_3 [ V_2 ] . V_4 ;
}
}
return L_1 ;
}
static struct V_6 *
F_2 ( int V_7 )
{
int V_2 ;
for ( V_2 = 0 ; V_8 [ V_2 ] . V_7 != 0 ; V_2 ++ ) {
if ( V_7 == V_8 [ V_2 ] . V_7 ) {
return & V_8 [ V_2 ] ;
}
}
return NULL ;
}
static inline int
F_3 ( T_1 * V_9 )
{
return F_4 ( V_9 -> V_10 ) ;
}
static int
F_5 ( int V_11 )
{
F_6 ( V_11 ) ;
return F_7 ( V_12 ) ;
}
static int
F_8 ( T_1 * V_9 , int V_13 )
{
int V_2 ;
for ( V_2 = 0 ; V_2 < V_14 ; V_2 += 5 ) {
if ( F_3 ( V_9 ) & V_13 ) {
return 1 ;
}
F_9 ( 5 ) ;
}
for ( V_2 = 0 ; V_2 < V_15 ; V_2 ++ ) {
if ( F_3 ( V_9 ) & V_13 ) {
return 1 ;
}
if ( F_5 ( V_16 / V_17 ) ) {
return ( 0 ) ;
}
}
return ( 0 ) ;
}
static int
F_10 ( T_1 * V_9 )
{
if ( F_8 ( V_9 , V_18 ) )
return F_4 ( V_9 -> V_19 ) ;
F_11 ( V_20 , L_2 ) ;
return - 1 ;
}
static int
F_12 ( T_1 * V_9 , unsigned char V_21 )
{
if ( F_8 ( V_9 , V_22 ) ) {
F_13 ( V_21 , V_9 -> V_19 ) ;
return 0 ;
}
F_11 ( V_20 , L_3 ) ;
return - 1 ;
}
int
F_14 ( T_1 * V_9 ,
int V_7 , unsigned char * V_23 , unsigned char * V_24 )
{
int V_25 ;
unsigned int V_2 ;
int V_26 ;
struct V_6 * V_27 ;
if ( ( V_27 = F_2 ( V_7 ) ) == NULL ) {
F_15 ( L_4 ,
V_7 ) ;
return 1 ;
}
if ( V_7 == V_28 ) {
V_27 -> V_29 = ( unsigned long ) V_23 ;
V_23 = NULL ;
}
F_11 ( V_30 , L_5 ,
V_7 , V_27 -> V_31 , V_27 -> V_32 ,
V_27 -> V_29 , V_27 -> V_33 ) ;
if ( F_12 ( V_9 , V_7 ) ) {
F_11 ( ( V_34 | V_30 ) , L_6
L_7 ,
V_7 , V_27 -> V_31 ) ;
return 1 ;
}
if ( V_27 -> V_29 > 0 ) {
F_11 ( V_20 , L_8
L_9 ,
V_27 -> V_29 , V_7 ) ;
for ( V_2 = 0 ; V_2 < V_27 -> V_29 ; V_2 ++ ) {
if ( F_12 ( V_9 , V_24 [ V_2 ] ) ) {
F_11 ( V_34 , L_10
L_11 ,
V_2 , V_7 , V_27 -> V_31 ) ;
return 1 ;
}
F_11 ( V_20 , L_12 ,
V_2 , V_24 [ V_2 ] ) ;
}
}
if ( V_27 -> V_32 > 0 ) {
F_11 ( V_20 , L_13
L_9 ,
V_27 -> V_32 , V_7 ) ;
for ( V_2 = 0 ; V_2 < V_27 -> V_32 ; V_2 ++ ) {
if ( ( V_26 = F_10 ( V_9 ) ) == - 1 ) {
F_11 ( V_34 , L_14
L_11 ,
V_2 , V_7 , V_27 -> V_31 ) ;
return 1 ;
}
if ( V_26 == 0xff ) {
if ( ( V_26 = F_10 ( V_9 ) ) == - 1 ) {
F_11 ( V_34 , L_15
L_16
L_17
L_18 ,
V_2 , V_7 ,
V_27 -> V_31 ) ;
return 1 ;
}
if ( V_26 == 1 &&
V_27 -> V_7 == V_35 ) {
V_23 [ 0 ] = V_36 ;
return ( 0 ) ;
} else if ( V_26 == 3 &&
V_27 -> V_7 == V_37 ) {
return 3 ;
} else if ( V_26 == 1 &&
V_27 -> V_7 == V_38 ) {
return 1 ;
} else {
F_11 ( V_34 , L_19
L_20
L_21
L_22
L_23 ,
V_26 ,
F_1 ( V_26 ) ,
V_2 , V_7 ,
V_27 -> V_31 ) ;
return 1 ;
}
} else {
V_23 [ V_2 ] = V_26 ;
}
F_11 ( V_20 , L_24 , V_2 , V_23 [ V_2 ] ) ;
}
}
if ( ( V_27 -> V_32 == 0 && V_27 -> V_29 == 0 ) || V_27 -> V_33 ) {
F_11 ( V_30 , L_25 , V_7 ) ;
if ( ( V_25 = F_10 ( V_9 ) ) == 0 ) {
V_25 = V_39 ;
}
if ( V_25 != V_39 ) {
if ( V_25 == - 1 ) {
F_11 ( V_34 , L_26
L_7 ,
V_7 , V_27 -> V_31 ) ;
return 1 ;
} else {
int V_40 = - 1 ;
if ( V_25 == 0xff ) {
if ( ( V_40 = F_10 ( V_9 ) ) == - 1 ) {
F_11 ( V_20 ,
L_27
L_28 ,
V_7 , V_27 -> V_31 ) ;
}
}
F_11 ( V_34 , L_29
L_30 ,
V_7 , V_27 -> V_31 , V_25 , V_40 ,
F_1 ( V_40 ) ) ;
return - V_40 ;
}
}
F_11 ( V_20 , L_31
L_32 ,
V_7 , V_27 -> V_31 ) ;
} else {
F_11 ( V_30 , L_33
L_34 ,
V_7 , V_27 -> V_31 , V_27 -> V_32 ,
V_27 -> V_29 , V_27 -> V_33 ) ;
}
return 0 ;
}
static unsigned char *
F_16 ( unsigned int V_41 ,
unsigned char * V_42 ,
unsigned int V_43 )
{
unsigned int V_2 ;
for ( V_2 = 0 ; V_2 < V_43 ; V_2 ++ ) {
* V_42 = V_41 & 0x7F ;
V_41 = V_41 >> 7 ;
V_42 ++ ;
}
return V_42 ;
}
static int
F_17 ( unsigned char * V_41 , int V_44 )
{
int V_2 ;
int V_45 = 0 ;
for ( V_2 = V_44 - 1 ; V_2 >= 0 ; V_2 -- ) {
V_45 = ( V_45 << 7 ) + V_41 [ V_2 ] ;
}
return V_45 ;
}
static
unsigned char *
F_18 ( unsigned char * V_41 , unsigned char * V_42 , unsigned int V_43 )
{
unsigned int V_2 ;
unsigned int V_46 = V_43 / 2 ;
for ( V_2 = 0 ; V_2 < V_46 ; V_2 ++ ) {
* V_42 ++ = V_41 [ V_2 ] & 0x7f ;
* V_42 ++ = V_41 [ V_2 ] >> 7 ;
}
return V_42 ;
}
static
unsigned char *
F_19 ( unsigned char * V_41 , unsigned char * V_42 , unsigned int V_47 )
{
int V_2 ;
unsigned char * V_48 = V_41 + V_47 ;
V_48 = V_41 + V_47 ;
for ( V_2 = 0 ; V_41 != V_48 ; V_2 ++ ) {
V_42 [ V_2 ] = * V_41 ++ ;
V_42 [ V_2 ] |= ( * V_41 ++ ) << 7 ;
}
return V_42 ;
}
static int
F_20 ( T_1 * V_9 , int V_49 )
{
unsigned char V_24 [ 2 ] ;
int V_50 ;
V_24 [ 0 ] = V_49 & 0x7f ;
V_24 [ 1 ] = V_49 >> 7 ;
if ( ( V_50 = F_14 ( V_9 , V_51 , NULL , V_24 ) ) == 0 ) {
V_9 -> V_52 [ V_49 ] = V_36 ;
}
return V_50 ;
}
static int
F_21 ( T_1 * V_9 , int V_53 )
{
int V_2 ;
unsigned char V_23 [ 32 ] , V_24 [ 32 ] ;
unsigned int V_54 , V_55 , V_56 ;
if ( F_14 ( V_9 , V_57 , V_23 , V_24 ) ) {
F_15 ( L_35 ) ;
return - 1 ;
}
V_54 = V_55 = V_56 = V_9 -> V_58 = 0 ;
for ( V_2 = 0 ; V_2 < V_59 ; V_2 ++ ) {
V_24 [ 0 ] = V_2 & 0x7f ;
V_24 [ 1 ] = V_2 >> 7 ;
if ( F_14 ( V_9 , V_35 , V_23 , V_24 ) ) {
F_15 ( V_60 L_36
L_37 , V_2 ) ;
V_9 -> V_52 [ V_2 ] = V_36 ;
continue;
}
V_9 -> V_52 [ V_2 ] = ( V_61 | V_23 [ 0 ] ) ;
if ( V_53 ) {
V_9 -> V_52 [ V_2 ] |= V_62 ;
}
switch ( V_23 [ 0 ] & V_63 ) {
case V_64 :
V_54 ++ ;
break;
case V_65 :
V_56 ++ ;
break;
case V_66 :
V_55 ++ ;
break;
case V_36 :
break;
default:
F_15 ( L_38
L_39 ,
V_2 , V_23 [ 0 ] ) ;
}
if ( V_23 [ 0 ] != V_36 ) {
V_9 -> V_58 ++ ;
}
}
F_15 ( L_40
L_41 , V_9 -> V_58 , V_54 , V_55 , V_56 ,
V_59 - V_9 -> V_58 ) ;
return ( 0 ) ;
}
static int
F_22 ( T_1 * V_9 )
{
unsigned char V_67 [ V_68 ] ;
unsigned char V_69 [ 2 ] ;
T_2 * V_70 ;
int V_2 , V_50 , V_71 , V_72 ;
for ( V_2 = 0 ; V_2 < V_73 ; V_2 ++ ) {
V_69 [ 0 ] = V_2 & 0x7f ;
V_69 [ 1 ] = V_2 >> 7 ;
if ( ( V_50 = F_14 ( V_9 , V_37 , V_67 ,
V_69 ) ) == 0 ) {
V_9 -> V_74 [ V_2 ] |= V_61 ;
V_70 = ( T_2 * ) V_67 ;
V_9 -> V_52
[ V_70 -> V_75 | ( V_70 -> V_76 << 7 ) ] |=
V_77 ;
} else if ( V_50 == 3 ) {
V_9 -> V_74 [ V_2 ] = 0 ;
} else {
F_15 ( L_42
L_43 , V_50 ) ;
V_9 -> V_74 [ V_2 ] = 0 ;
return 1 ;
}
}
for ( V_2 = 0 , V_71 = 0 , V_72 = 0 ; V_2 < V_73 ; V_2 ++ ) {
if ( V_9 -> V_74 [ V_2 ] & V_61 ) {
V_71 ++ ;
}
if ( V_9 -> V_74 [ V_2 ] & V_77 ) {
V_72 ++ ;
}
}
F_15 ( L_44 , V_71 , V_72 ) ;
return ( 0 ) ;
}
static int
F_23 ( T_1 * V_9 )
{
unsigned char V_78 [ V_79 ] ;
T_3 V_80 ;
unsigned char V_81 ;
int V_2 , V_50 , V_82 , V_71 ;
for ( V_2 = 0 ; V_2 < V_83 ; V_2 ++ ) {
V_81 = V_2 ;
if ( ( V_50 = F_14 ( V_9 , V_38 , V_78 ,
& V_81 ) ) == 0 ) {
V_9 -> V_84 [ V_2 ] |= V_77 ;
F_19 ( V_78 , ( unsigned char * ) & V_80 ,
V_79 ) ;
for ( V_82 = 0 ; V_82 < V_85 ; V_82 ++ ) {
if ( V_80 . V_86 [ V_82 ] . V_87 ) {
V_9 -> V_74
[ V_80 . V_86 [ V_82 ] . V_88 ] |=
V_77 ;
}
}
} else if ( V_50 == 1 ) {
V_9 -> V_84 [ V_2 ] = 0 ;
} else {
F_15 ( L_45
L_43 , V_50 ) ;
V_9 -> V_84 [ V_2 ] = 0 ;
}
}
for ( V_2 = 0 , V_71 = 0 ; V_2 < V_83 ; V_2 ++ ) {
if ( V_9 -> V_84 [ V_2 ] ) {
V_71 ++ ;
}
}
F_15 ( L_46 , V_71 ) ;
return ( 0 ) ;
}
static int
F_24 ( T_1 * V_9 , T_4 * V_89 )
{
unsigned char V_90 [ V_68 + 2 ] ;
unsigned char * V_91 ;
F_11 ( V_92 , L_47 ,
V_89 -> V_93 ) ;
V_9 -> V_74 [ V_89 -> V_93 ] |= V_61 ;
V_91 = V_90 ;
V_91 = F_16 ( V_89 -> V_93 , V_90 , 2 ) ;
F_18 ( ( unsigned char * ) & V_89 -> V_94 . V_70 , V_91 , V_68 ) ;
if ( F_14 ( V_9 , V_95 , NULL , V_90 ) ) {
F_15 ( L_48 ) ;
return - ( V_96 ) ;
}
return ( 0 ) ;
}
static int
F_25 ( T_1 * V_9 , T_4 * V_89 )
{
unsigned char V_90 [ V_79 + 1 ] ;
int V_2 ;
F_11 ( V_92 , L_49 ,
V_89 -> V_93 ) ;
V_9 -> V_84 [ V_89 -> V_93 ] = V_77 ;
for ( V_2 = 0 ; V_2 < V_85 ; V_2 ++ ) {
if ( V_89 -> V_94 . V_97 . V_86 [ V_2 ] . V_87 ) {
V_9 -> V_74 [ V_89 -> V_94 . V_97 . V_86 [ V_2 ] . V_88 ] |=
V_77 ;
}
}
V_90 [ 0 ] = V_89 -> V_93 ;
F_18 ( ( unsigned char * ) & V_89 -> V_94 . V_97 , & V_90 [ 1 ] , V_79 ) ;
if ( F_14 ( V_9 , V_98 , NULL , V_90 ) ) {
F_15 ( L_48 ) ;
return - ( V_96 ) ;
}
return ( 0 ) ;
}
static int
F_26 ( T_1 * V_9 )
{
char V_23 [ 8 ] ;
if ( F_14 ( V_9 , V_99 , V_23 , NULL ) ) {
F_15 ( L_50 ) ;
return - 1 ;
} else {
return F_17 ( V_23 , 4 ) ;
}
}
static int
F_27 ( T_1 * V_9 ,
T_4 * V_89 ,
T_5 T_6 * V_100 ,
int V_101 )
{
T_5 V_102 = 0 ;
T_7 V_103 ;
T_5 T_6 * V_104 = NULL ;
unsigned int V_2 ;
const unsigned int V_105 = 4096 / 2 ;
unsigned int V_106 ;
unsigned int V_107 ;
int V_108 ;
int V_109 ;
unsigned char V_110 [ V_111 ] ;
unsigned char * V_112 ;
int V_113 = 0 ;
int V_114 = 0 ;
F_11 ( V_92 , L_51
L_52 ,
V_89 -> V_115 ? L_53 : L_54 ,
V_89 -> V_93 , V_89 -> V_116 ,
V_89 -> V_115 ,
( unsigned long ) V_89 -> V_100 ) ;
if ( V_89 -> V_93 == V_117 ) {
int V_50 ;
if ( ( V_50 = F_28 ( V_9 ) ) < 0 ) {
return - V_118 ;
}
F_15 ( L_55 , V_50 ) ;
V_89 -> V_93 = V_50 ;
}
if ( V_89 -> V_115 ) {
if ( V_9 -> V_119 ) {
if ( V_9 -> V_52 [ V_89 -> V_93 ] & V_62 ) {
F_15 ( L_56
L_57 ,
V_89 -> V_93 ) ;
return - V_120 ;
}
}
F_20 ( V_9 , V_89 -> V_93 ) ;
}
if ( V_89 -> V_115 ) {
V_9 -> V_121 = F_26 ( V_9 ) ;
if ( V_9 -> V_121 < ( int ) V_89 -> V_115 ) {
F_15 ( L_58
L_59 ,
V_89 -> V_115 ) ;
return - V_118 ;
}
}
V_113 = F_29 ( & V_89 -> V_94 . V_122 ) ;
if ( V_113 > 0 && V_89 -> V_94 . V_122 . V_123 != V_124 ) {
F_15 ( L_60
L_61 ) ;
return - ( V_125 ) ;
}
switch ( V_113 ) {
case 0 :
V_114 = 0 ;
V_113 = 1 ;
break;
case 1 :
V_114 = 0 ;
V_113 = 2 ;
break;
case 2 :
V_114 = 1 ;
V_113 = 2 ;
break;
case 3 :
V_114 = 2 ;
V_113 = 3 ;
break;
case 4 :
V_114 = 3 ;
V_113 = 4 ;
break;
case 5 :
V_114 = 4 ;
V_113 = 5 ;
break;
case 6 :
V_114 = 5 ;
V_113 = 6 ;
break;
}
F_11 ( V_92 , L_62
L_63 ,
F_29 ( & V_89 -> V_94 . V_122 ) ,
V_114 , V_113 ) ;
F_30 ( & V_89 -> V_94 . V_122 , 0 ) ;
V_103 = V_89 -> V_115 / 2 ;
V_112 = & V_110 [ 0 ] ;
V_112 = F_16 ( V_89 -> V_93 , V_112 , 2 ) ;
if ( V_89 -> V_115 ) {
V_112 = F_16 ( V_103 , V_112 , 4 ) ;
}
V_112 = F_16 ( * ( ( T_7 * ) & V_89 -> V_94 . V_122 . V_126 ) ,
V_112 , 4 ) ;
V_112 = F_16 ( * ( ( T_7 * ) & V_89 -> V_94 . V_122 . V_127 ) ,
V_112 , 4 ) ;
V_112 = F_16 ( * ( ( T_7 * ) & V_89 -> V_94 . V_122 . V_128 ) ,
V_112 , 4 ) ;
V_112 = F_16 ( * ( ( T_7 * ) & V_89 -> V_94 . V_122 . V_129 ) ,
V_112 , 4 ) ;
V_112 = F_16 ( V_89 -> V_94 . V_122 . V_130 , V_112 , 3 ) ;
V_112 = F_16 ( * ( & V_89 -> V_94 . V_122 . V_130 + 1 ) ,
V_112 , 2 ) ;
if ( F_14 ( V_9 ,
V_89 -> V_115 ?
V_131 : V_132 ,
NULL , V_110 ) ) {
F_15 ( L_64 ,
V_89 -> V_115 ? L_53 : L_54 ) ;
return - ( V_96 ) ;
}
if ( V_89 -> V_115 == 0 ) {
goto V_133;
}
V_104 = V_100 + V_103 ;
V_100 += V_114 ;
for ( V_106 = 0 , V_109 = 0 ;
V_106 < V_103 ; V_106 += V_105 , V_109 ++ ) {
if ( ( V_103 - V_106 ) > V_105 ) {
V_107 = V_105 ;
} else {
V_107 = F_31 ( V_103 - V_106 , 8 ) ;
}
if ( F_14 ( V_9 , V_134 , NULL , NULL ) ) {
F_15 ( L_65
L_66 ) ;
return - ( V_96 ) ;
}
for ( V_2 = 0 ; V_2 < V_107 ; V_2 ++ ) {
if ( V_100 < V_104 ) {
F_32 ( V_102 , V_100 ) ;
V_100 += V_113 ;
if ( V_101 ) {
if ( F_33 ( & V_89 -> V_94 . V_122 ) ) {
( ( unsigned char * )
& V_102 ) [ 0 ] += 0x7f ;
( ( unsigned char * )
& V_102 ) [ 1 ] += 0x7f ;
} else {
V_102 += 0x7fff ;
}
}
} else {
}
if ( V_2 < V_107 - 1 ) {
F_34 ( V_102 , V_9 -> V_135 ) ;
} else {
F_34 ( V_102 , V_9 -> V_136 ) ;
}
}
if ( ( V_108 = F_10 ( V_9 ) ) != V_137 ) {
if ( V_108 == - 1 ) {
F_15 ( L_67
L_68 ) ;
return - ( V_96 ) ;
} else {
F_15 ( L_67
L_69 ,
V_108 ) ;
return - ( V_96 ) ;
}
}
}
V_9 -> V_52 [ V_89 -> V_93 ] = ( V_61 | V_64 ) ;
V_133:
return ( 0 ) ;
}
static int
F_35 ( T_1 * V_9 , T_4 * V_89 )
{
unsigned char V_138 [ V_139 ] ;
F_11 ( V_92 , L_70
L_71 ,
V_89 -> V_93 ,
V_89 -> V_94 . V_140 . V_141 ) ;
F_16 ( V_89 -> V_93 , & V_138 [ 0 ] , 2 ) ;
F_16 ( V_89 -> V_94 . V_140 . V_141 , & V_138 [ 2 ] , 2 ) ;
F_16 ( * ( ( unsigned int * ) & V_89 -> V_94 . V_140 . V_126 ) ,
& V_138 [ 4 ] , 4 ) ;
F_16 ( * ( ( unsigned int * ) & V_89 -> V_94 . V_140 . V_127 ) ,
& V_138 [ 8 ] , 4 ) ;
F_16 ( * ( ( unsigned int * ) & V_89 -> V_94 . V_140 . V_128 ) ,
& V_138 [ 12 ] , 4 ) ;
F_16 ( * ( ( unsigned int * ) & V_89 -> V_94 . V_140 . V_129 ) ,
& V_138 [ 16 ] , 4 ) ;
F_16 ( V_89 -> V_94 . V_140 . V_130 , & V_138 [ 20 ] , 3 ) ;
F_16 ( * ( & V_89 -> V_94 . V_140 . V_130 + 1 ) , & V_138 [ 23 ] , 2 ) ;
if ( F_14 ( V_9 , V_142 , NULL , V_138 ) ) {
F_15 ( L_72 ) ;
return - ( V_96 ) ;
}
V_9 -> V_52 [ V_89 -> V_93 ] = ( V_61 | V_66 ) ;
return ( 0 ) ;
}
static int
F_36 ( T_1 * V_9 , T_4 * V_89 )
{
int V_2 ;
int V_143 ;
unsigned char * V_144 ;
V_144 = F_37 ( V_145 , V_146 ) ;
if ( ! V_144 )
return - V_118 ;
F_16 ( V_89 -> V_93 , & V_144 [ 0 ] , 2 ) ;
V_143 = ( 1 << ( V_89 -> V_94 . V_147 . V_148 & 7 ) ) ;
V_144 [ 2 ] = ( unsigned char ) V_89 -> V_94 . V_147 . V_148 ;
F_11 ( V_92 , L_73 ,
V_89 -> V_93 ,
V_89 -> V_94 . V_147 . V_148 ,
V_143 ) ;
for ( V_2 = 0 ; V_2 < V_143 ; V_2 ++ ) {
F_11 ( V_92 | V_20 , L_74 ,
V_2 , V_89 -> V_94 . V_147 . V_149 [ V_2 ] ) ;
F_16 ( V_89 -> V_94 . V_147 . V_149 [ V_2 ] ,
& V_144 [ 3 + ( V_2 * 2 ) ] , 2 ) ;
}
if ( F_14 ( V_9 , V_28 ,
( unsigned char * ) ( long ) ( ( V_143 * 2 ) + 3 ) ,
V_144 ) ) {
F_15 ( L_75 ) ;
F_38 ( V_144 ) ;
return - ( V_96 ) ;
}
V_9 -> V_52 [ V_89 -> V_93 ] = ( V_61 | V_65 ) ;
F_38 ( V_144 ) ;
return ( 0 ) ;
}
static int
F_39 ( T_1 * V_9 ,
T_4 * V_89 )
{
int V_2 ;
unsigned char V_150 [ 1 ] ;
unsigned char V_93 [ 2 ] ;
int V_143 ;
F_16 ( V_89 -> V_93 , V_93 , 2 ) ;
if ( F_14 ( V_9 , V_151 , V_150 , V_93 ) ) {
F_15 ( L_76 ) ;
return - ( V_96 ) ;
}
F_11 ( V_20 , L_77 ,
V_89 -> V_93 , V_150 [ 0 ] ) ;
V_89 -> V_94 . V_147 . V_148 = V_150 [ 0 ] ;
V_143 = ( 1 << V_150 [ 0 ] ) ;
for ( V_2 = 0 ; V_2 < V_143 ; V_2 ++ ) {
char V_152 [ 2 ] ;
int V_153 ;
if ( ( V_153 = F_10 ( V_9 ) ) == - 1 ) {
F_15 ( L_78
L_79 ) ;
return - ( V_96 ) ;
}
V_152 [ 0 ] = V_153 ;
if ( ( V_153 = F_10 ( V_9 ) ) == - 1 ) {
F_15 ( L_78
L_79 ) ;
return - ( V_96 ) ;
}
V_152 [ 1 ] = V_153 ;
V_89 -> V_94 . V_147 . V_149 [ V_2 ] =
F_17 ( ( unsigned char * ) V_152 , 2 ) ;
F_11 ( V_20 , L_80 ,
V_2 , V_89 -> V_94 . V_147 . V_149 [ V_2 ] ) ;
}
return ( 0 ) ;
}
static int
F_40 ( T_1 * V_9 , T_4 * V_89 )
{
unsigned char V_154 [ V_155 ] ;
T_8 * V_156 = & V_89 -> V_94 . V_152 ;
int V_2 ;
F_11 ( V_92 , L_81
L_82 ,
V_89 -> V_93 , V_156 -> V_157 ) ;
V_154 [ 0 ] = V_89 -> V_93 & 0x7f ;
for ( V_2 = 0 ; V_2 < 4 ; V_2 ++ ) {
F_16 ( ( ( unsigned char * ) V_156 ) [ V_2 ] , & V_154 [ 1 + ( V_2 * 2 ) ] , 2 ) ;
}
if ( F_14 ( V_9 , V_158 , NULL , V_154 ) ) {
F_15 ( L_83 ) ;
return - ( V_96 ) ;
}
return ( 0 ) ;
}
static int
F_28 ( T_1 * V_9 )
{
int V_2 ;
for ( V_2 = 0 ; V_2 < V_59 ; V_2 ++ ) {
if ( ! ( V_9 -> V_52 [ V_2 ] & V_61 ) ) {
return V_2 ;
}
}
F_15 ( L_84 ) ;
return - 1 ;
}
static int
F_41 ( T_1 * V_9 , const char T_6 * V_159 )
{
T_4 * V_89 ;
int V_40 ;
V_89 = F_37 ( sizeof( * V_89 ) , V_146 ) ;
if ( ! V_89 )
return - V_118 ;
if ( F_42 ( V_89 , V_159 , sizeof( T_4 ) -
sizeof( V_160 ) ) ) {
F_15 ( L_85 ) ;
V_40 = - V_161 ;
goto V_162;
}
F_11 ( V_92 , L_86
L_87
L_88
L_89 ,
V_89 -> V_116 ,
V_89 -> V_93 ,
V_89 -> V_115 ) ;
switch ( V_89 -> V_116 ) {
case V_64 :
if ( F_42 ( & V_89 -> V_94 . V_122 , V_89 -> V_163 ,
sizeof ( V_164 ) ) ) {
V_40 = - V_161 ;
break;
}
V_40 = F_27 ( V_9 , V_89 , V_89 -> V_100 , 0 ) ;
break;
case V_65 :
if ( F_42 ( & V_89 -> V_94 . V_122 , V_89 -> V_163 ,
sizeof ( V_165 ) ) ) {
V_40 = - V_161 ;
break;
}
V_40 = F_36 ( V_9 , V_89 ) ;
break;
case V_66 :
if ( F_42 ( & V_89 -> V_94 . V_140 , V_89 -> V_163 ,
sizeof ( V_166 ) ) ) {
V_40 = - V_161 ;
break;
}
V_40 = F_35 ( V_9 , V_89 ) ;
break;
case V_167 :
if ( F_42 ( & V_89 -> V_94 . V_152 , V_89 -> V_163 ,
sizeof ( T_8 ) ) ) {
V_40 = - V_161 ;
break;
}
V_40 = F_40 ( V_9 , V_89 ) ;
break;
case V_168 :
if ( F_42 ( & V_89 -> V_94 . V_70 , V_89 -> V_163 ,
sizeof ( T_2 ) ) ) {
V_40 = - V_161 ;
break;
}
V_40 = F_24 ( V_9 , V_89 ) ;
break;
case V_169 :
if ( F_42 ( & V_89 -> V_94 . V_97 , V_89 -> V_163 ,
sizeof ( T_3 ) ) ) {
V_40 = - V_161 ;
break;
}
V_40 = F_25 ( V_9 , V_89 ) ;
break;
default:
F_15 ( L_90 ,
V_89 -> V_116 ) ;
V_40 = - V_125 ;
break;
}
V_162:
F_38 ( V_89 ) ;
return V_40 ;
}
static void
F_43 ( T_9 * V_90 )
{
V_164 V_122 ;
T_9 * V_170 ;
V_170 = V_90 ;
* ( ( T_7 * ) & V_122 . V_126 ) = F_17 ( V_170 , 4 ) ; V_170 += 4 ;
* ( ( T_7 * ) & V_122 . V_127 ) = F_17 ( V_170 , 4 ) ; V_170 += 4 ;
* ( ( T_7 * ) & V_122 . V_128 ) = F_17 ( V_170 , 4 ) ; V_170 += 4 ;
* ( ( T_7 * ) & V_122 . V_129 ) = F_17 ( V_170 , 4 ) ; V_170 += 4 ;
* ( ( T_7 * ) & V_122 . V_130 ) = F_17 ( V_170 , 3 ) ; V_170 += 3 ;
V_122 . V_123 = * V_170 & 0x3 ;
V_122 . V_171 = * V_170 & 0x8 ;
V_122 . V_172 = * V_170 & 0x10 ;
V_122 . V_173 = * V_170 & 0x40 ;
memcpy ( V_90 , ( unsigned char * ) & V_122 , sizeof ( V_164 ) ) ;
}
static int
F_44 ( T_10 * V_174 ,
T_11 * V_175 )
{
T_1 * V_9 = & V_174 -> V_176 ;
unsigned char V_177 [ 2 ] ;
int V_2 ;
F_11 ( V_30 , L_91
L_92 , V_175 -> V_7 ) ;
switch ( V_175 -> V_7 ) {
case V_178 :
F_15 ( L_93 ) ;
F_13 ( 0x80 | 0x20 , V_9 -> V_179 ) ;
V_9 -> V_180 = 1 ;
return 0 ;
case V_181 :
F_15 ( L_94 ) ;
F_13 ( 0x80 | 0x40 | 0x20 , V_9 -> V_179 ) ;
V_9 -> V_180 = 1 ;
return 0 ;
case V_182 :
V_175 -> V_23 [ 0 ] = V_9 -> V_180 ;
return 0 ;
case V_183 :
V_9 -> V_119 = V_175 -> V_24 [ 0 ] ;
V_175 -> V_184 = 0 ;
return 0 ;
case V_185 :
V_2 = V_175 -> V_24 [ 0 ] | ( V_175 -> V_24 [ 1 ] << 7 ) ;
if ( V_2 < 0 || V_2 >= V_59 ) {
F_15 ( L_95 ,
V_2 ) ;
V_175 -> V_184 = V_125 ;
return - V_125 ;
}
V_175 -> V_23 [ 0 ] = V_9 -> V_52 [ V_2 ] ;
V_175 -> V_184 = 0 ;
return 0 ;
case V_186 :
V_9 -> V_187 = V_175 -> V_24 [ 0 ] ;
F_15 ( L_96 , V_9 -> V_187 ) ;
return 0 ;
case V_37 :
F_16 ( * ( ( T_7 * ) V_175 -> V_24 ) , V_177 , 2 ) ;
memcpy ( V_175 -> V_24 , V_177 , 2 ) ;
break;
case V_151 :
V_175 -> V_184 = F_39
( V_9 , ( T_4 * ) V_175 -> V_23 ) ;
return 0 ;
case V_188 :
F_15 ( L_97
L_98 ) ;
V_175 -> V_184 = V_125 ;
return - V_125 ;
}
V_175 -> V_184 = F_14 ( V_9 , V_175 -> V_7 , V_175 -> V_23 , V_175 -> V_24 ) ;
if ( V_175 -> V_184 == 0 ) {
switch ( V_175 -> V_7 ) {
case V_99 :
V_9 -> V_121 = F_17 ( V_175 -> V_23 , 4 ) ;
break;
case V_37 :
F_19 ( V_175 -> V_23 , V_175 -> V_23 , V_68 ) ;
break;
case V_38 :
F_19 ( V_175 -> V_23 , V_175 -> V_23 , V_79 ) ;
break;
case V_189 :
F_19 ( V_175 -> V_23 , V_175 -> V_23 , V_155 - 1 ) ;
break;
case V_190 :
F_43 ( V_175 -> V_23 ) ;
break;
case V_188 :
F_15 ( L_99
L_100
L_98 ) ;
break;
case V_191 :
F_45 ( V_174 ) ;
break;
case V_192 :
F_46 ( V_174 ) ;
break;
}
}
return 0 ;
}
int
F_47 ( struct V_193 * V_194 , struct V_195 * V_195 )
{
if ( ! F_48 ( V_194 -> V_196 -> V_197 ) )
return - V_161 ;
V_195 -> V_198 = V_194 ;
return 0 ;
}
int
F_49 ( struct V_193 * V_194 , struct V_195 * V_195 )
{
F_50 ( V_194 -> V_196 -> V_197 ) ;
return 0 ;
}
int
F_51 ( struct V_193 * V_194 , struct V_195 * V_195 ,
unsigned int V_7 , unsigned long V_199 )
{
struct V_200 * V_196 ;
T_1 * V_9 ;
T_10 * V_174 ;
T_11 * V_175 ;
void T_6 * V_201 = ( void T_6 * ) V_199 ;
int V_40 ;
V_196 = (struct V_200 * ) V_194 -> V_196 ;
if ( F_52 ( ! V_196 ) )
return - V_202 ;
if ( F_52 ( ! V_196 -> V_198 ) )
return - V_202 ;
V_174 = V_196 -> V_198 ;
V_9 = & V_174 -> V_176 ;
switch ( V_7 ) {
case V_203 :
if ( F_41 ( V_9 , V_201 ) != 0 ) {
return - V_96 ;
}
break;
case V_204 :
V_175 = F_53 ( V_201 , sizeof( * V_175 ) ) ;
if ( F_54 ( V_175 ) )
return F_55 ( V_175 ) ;
if ( F_44 ( V_174 , V_175 ) < 0 )
V_40 = - V_96 ;
else if ( F_56 ( V_201 , V_175 , sizeof ( * V_175 ) ) )
V_40 = - V_161 ;
else
V_40 = 0 ;
F_38 ( V_175 ) ;
return V_40 ;
default:
return - V_125 ;
}
return 0 ;
}
void
F_57 ( T_10 * V_196 )
{
T_1 * V_9 = & V_196 -> V_176 ;
if ( ( F_3 ( V_9 ) & ( V_205 | V_206 ) ) == 0 ) {
return;
}
F_58 ( & V_9 -> V_207 ) ;
V_9 -> V_208 = 1 ;
V_9 -> V_209 ++ ;
F_59 ( & V_9 -> V_207 ) ;
F_60 ( & V_9 -> V_210 ) ;
}
static int
F_61 ( int V_211 )
{
int V_212 ;
switch ( V_211 ) {
case 9 :
V_212 = 0x00 ;
break;
case 5 :
V_212 = 0x08 ;
break;
case 12 :
V_212 = 0x10 ;
break;
case 15 :
V_212 = 0x18 ;
break;
default:
F_15 ( L_101 , V_211 ) ;
V_212 = - 1 ;
}
return V_212 ;
}
static void
F_62 ( T_1 * V_9 ,
int V_153 , int V_213 , unsigned long V_214 )
{
T_12 V_215 ;
F_63 ( & V_215 , V_12 ) ;
F_64 ( & V_9 -> V_207 ) ;
F_65 ( & V_9 -> V_210 , & V_215 ) ;
V_9 -> V_208 = 0 ;
F_13 ( V_153 , V_213 ) ;
F_66 ( & V_9 -> V_207 ) ;
while ( ! V_9 -> V_208 && F_67 ( V_216 , V_214 ) ) {
F_68 ( 1 ) ;
F_69 () ;
}
}
static int
F_70 ( T_1 * V_9 )
{
int V_212 ;
int V_217 [ 2 ] ;
V_212 = F_61 ( V_9 -> V_211 ) ;
F_13 ( 0x0 , V_9 -> V_179 ) ;
F_13 ( 0x80 | 0x40 | V_212 , V_9 -> V_19 ) ;
F_62 ( V_9 , 0x80 | 0x40 | 0x10 | 0x1 ,
V_9 -> V_179 ,
( V_218 * V_16 ) / 100 ) ;
if ( ! V_9 -> V_208 ) {
F_15 ( L_102 ) ;
goto V_219;
}
F_62 ( V_9 , V_220 ,
V_9 -> V_19 , V_221 * V_16 ) ;
if ( ! V_9 -> V_208 ) {
F_15 ( L_103 ) ;
goto V_219;
}
if ( ! F_8 ( V_9 , V_18 ) ) {
F_15 ( L_104 ) ;
goto V_219;
}
if ( ( V_217 [ 0 ] = F_10 ( V_9 ) ) == - 1 ) {
F_15 ( L_105 ) ;
goto V_219;
}
if ( V_217 [ 0 ] == 0xFF ) {
if ( ( V_217 [ 0 ] = F_10 ( V_9 ) ) == - 1 ) {
F_15 ( L_106
L_107 ) ;
} else {
F_15 ( L_106
L_108 ,
V_217 [ 0 ] ) ;
}
goto V_219;
}
if ( ( V_217 [ 1 ] = F_10 ( V_9 ) ) == - 1 ) {
F_15 ( L_109 ) ;
goto V_219;
}
F_15 ( L_110 ,
V_217 [ 0 ] , V_217 [ 1 ] ) ;
return 0 ;
V_219:
return ( 1 ) ;
}
static int
F_71 ( T_1 * V_9 , char * V_222 )
{
const unsigned char * V_90 ;
int V_223 , V_40 ;
int V_224 = 0 ;
const struct V_225 * V_225 ;
V_40 = F_72 ( & V_225 , V_222 , V_9 -> V_196 -> V_9 ) ;
if ( V_40 < 0 ) {
F_15 ( V_226 L_111 , V_222 ) ;
return 1 ;
}
V_223 = 0 ;
V_90 = V_225 -> V_21 ;
for (; ; ) {
int V_227 = * ( signed char * ) V_90 ;
if ( V_227 == 0 )
break;
if ( V_227 < 0 || V_227 > V_228 ) {
F_15 ( V_226
L_112 ,
V_227 ) ;
goto V_229;
}
V_90 ++ ;
V_223 ++ ;
if ( V_225 -> V_115 < V_223 + V_227 ) {
F_15 ( V_226 L_113 ) ;
goto V_229;
}
if ( F_12 ( V_9 , V_230 ) )
goto V_229;
for (; V_227 ; V_227 -- ) {
if ( F_12 ( V_9 , * V_90 ) )
goto V_229;
V_90 ++ ;
V_223 ++ ;
}
if ( ! F_8 ( V_9 , V_18 ) ) {
F_15 ( V_226 L_114 ) ;
goto V_229;
}
V_40 = F_4 ( V_9 -> V_19 ) ;
if ( V_40 != V_39 ) {
F_15 ( V_226
L_115
L_116 ,
V_224 + 1 , V_40 ) ;
goto V_229;
}
V_224 ++ ;
}
F_73 ( V_225 ) ;
return 0 ;
V_229:
F_73 ( V_225 ) ;
F_15 ( V_226 L_117 ) ;
return 1 ;
}
static int
F_74 ( T_1 * V_9 )
{
char V_231 [ 1 ] ;
if ( F_70 ( V_9 ) ) {
F_15 ( L_118 ) ;
goto V_219;
}
if ( V_9 -> V_232 ) {
if ( F_71 ( V_9 , V_233 ) ) {
goto V_219;
}
V_9 -> V_232 = 0 ;
F_62 ( V_9 , V_234 ,
V_9 -> V_19 ,
( V_235 * V_16 ) ) ;
if ( ! V_9 -> V_208 ) {
F_15 ( L_119 ) ;
goto V_219;
}
F_62 ( V_9 , V_234 ,
V_9 -> V_19 , ( 10 * V_16 ) ) ;
if ( ! V_9 -> V_208 ) {
F_15 ( L_120 ) ;
goto V_219;
}
F_13 ( 0x80 | 0x40 , V_9 -> V_179 ) ;
}
if ( ( V_9 -> V_121 = F_26 ( V_9 ) ) < 0 ) {
goto V_219;
}
F_15 ( L_121 , V_9 -> V_121 / 1024 ) ;
if ( F_12 ( V_9 , 0xf0 ) ||
F_12 ( V_9 , 1 ) ||
( F_10 ( V_9 ) < 0 ) ) {
V_9 -> V_187 = 0 ;
F_15 ( L_122 ) ;
goto V_219;
}
V_231 [ 0 ] = 32 ;
if ( F_14 ( V_9 , V_236 , NULL , V_231 ) ) {
F_15 ( L_123 ) ;
goto V_219;
}
return 0 ;
V_219:
F_13 ( 0x0 , V_9 -> V_179 ) ;
V_9 -> V_180 = 0 ;
return 1 ;
}
int
F_75 ( T_1 * V_9 )
{
int V_237 ;
if ( V_9 -> V_232 ) {
V_237 = 1 ;
} else {
V_237 = 0 ;
}
if ( V_9 -> V_232 || V_238 ) {
if ( F_74 ( V_9 ) ) {
return - 1 ;
}
}
V_9 -> V_239 = ( F_76 ( V_9 ) == 0 ) ;
if ( V_9 -> V_239 && V_238 ) {
F_77 ( V_9 ) ;
}
F_21 ( V_9 , V_237 ) ;
F_23 ( V_9 ) ;
F_22 ( V_9 ) ;
F_13 ( 0x80 | 0x40 | 0x20 , V_9 -> V_179 ) ;
return ( 0 ) ;
}
int
F_78 ( T_10 * V_196 )
{
unsigned char V_23 [ 4 ] , V_24 [ 4 ] ;
T_1 * V_9 = & V_196 -> V_176 ;
V_9 -> V_232 = 0 ;
V_9 -> V_239 = 0 ;
V_9 -> V_187 = V_240 ;
V_9 -> V_180 = 0 ;
V_9 -> V_209 = 0 ;
V_9 -> V_119 = 1 ;
if ( F_14 ( V_9 , V_241 , V_23 , V_24 ) == 0 ) {
V_9 -> V_242 [ 0 ] = V_23 [ 0 ] ;
V_9 -> V_242 [ 1 ] = V_23 [ 1 ] ;
F_15 ( L_124 ,
V_23 [ 0 ] , V_23 [ 1 ] ) ;
if ( F_14 ( V_9 , V_220 ,
V_23 , V_24 ) == 0 ) {
V_9 -> V_243 [ 0 ] = V_23 [ 0 ] ;
V_9 -> V_243 [ 1 ] = V_23 [ 1 ] ;
} else {
F_15 ( L_125
L_126 ) ;
return - 1 ;
}
if ( ! V_244 ) {
return 0 ;
} else {
F_15 ( L_127 ) ;
V_9 -> V_232 = 1 ;
}
} else {
V_9 -> V_232 = 1 ;
F_15 ( L_128 ) ;
}
return 0 ;
}
