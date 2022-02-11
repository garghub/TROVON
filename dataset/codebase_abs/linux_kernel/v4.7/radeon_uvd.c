int F_1 ( struct V_1 * V_2 )
{
unsigned long V_3 ;
const char * V_4 = NULL , * V_5 = NULL ;
int V_6 , V_7 ;
F_2 ( & V_2 -> V_8 . V_9 , V_10 ) ;
switch ( V_2 -> V_11 ) {
case V_12 :
case V_13 :
case V_14 :
case V_15 :
case V_16 :
V_5 = V_17 ;
break;
case V_18 :
case V_19 :
V_5 = V_20 ;
break;
case V_21 :
V_5 = V_22 ;
break;
case V_23 :
case V_24 :
case V_25 :
V_5 = V_26 ;
break;
case V_27 :
case V_28 :
case V_29 :
case V_30 :
case V_31 :
V_5 = V_32 ;
break;
case V_33 :
case V_34 :
case V_35 :
case V_36 :
case V_37 :
case V_38 :
case V_39 :
V_5 = V_40 ;
break;
case V_41 :
case V_42 :
case V_43 :
case V_44 :
case V_45 :
V_5 = V_46 ;
break;
case V_47 :
case V_48 :
case V_49 :
case V_50 :
case V_51 :
V_5 = V_52 ;
V_4 = V_53 ;
break;
default:
return - V_54 ;
}
V_2 -> V_8 . V_55 = false ;
V_2 -> V_8 . V_56 = V_57 ;
if ( V_4 ) {
V_7 = F_3 ( & V_2 -> V_58 , V_4 , V_2 -> V_59 ) ;
if ( V_7 ) {
F_4 ( V_2 -> V_59 , L_1 ,
V_4 ) ;
} else {
struct V_60 * V_61 = ( void * ) V_2 -> V_58 -> V_62 ;
unsigned V_63 , V_64 , V_65 ;
V_7 = F_5 ( V_2 -> V_58 ) ;
if ( V_7 )
return V_7 ;
V_2 -> V_8 . V_55 = true ;
V_65 = F_6 ( V_61 -> V_66 ) & 0xff ;
V_63 = ( F_6 ( V_61 -> V_66 ) >> 24 ) & 0xff ;
V_64 = ( F_6 ( V_61 -> V_66 ) >> 8 ) & 0xff ;
F_7 ( L_2 ,
V_63 , V_64 , V_65 ) ;
if ( ( V_63 >= 0x01 ) && ( V_64 >= 0x37 ) )
V_2 -> V_8 . V_56 = V_67 ;
}
}
if ( ! V_4 || V_7 ) {
V_7 = F_3 ( & V_2 -> V_58 , V_5 , V_2 -> V_59 ) ;
if ( V_7 ) {
F_4 ( V_2 -> V_59 , L_1 ,
V_5 ) ;
return V_7 ;
}
}
V_3 = F_8 ( V_2 -> V_58 -> V_68 + 8 ) +
V_69 + V_70 +
V_71 * V_2 -> V_8 . V_56 ;
V_7 = F_9 ( V_2 , V_3 , V_72 , true ,
V_73 , 0 , NULL ,
NULL , & V_2 -> V_8 . V_74 ) ;
if ( V_7 ) {
F_4 ( V_2 -> V_59 , L_3 , V_7 ) ;
return V_7 ;
}
V_7 = F_10 ( V_2 -> V_8 . V_74 , false ) ;
if ( V_7 ) {
F_11 ( & V_2 -> V_8 . V_74 ) ;
F_4 ( V_2 -> V_59 , L_4 , V_7 ) ;
return V_7 ;
}
V_7 = F_12 ( V_2 -> V_8 . V_74 , V_73 ,
& V_2 -> V_8 . V_75 ) ;
if ( V_7 ) {
F_13 ( V_2 -> V_8 . V_74 ) ;
F_11 ( & V_2 -> V_8 . V_74 ) ;
F_4 ( V_2 -> V_59 , L_5 , V_7 ) ;
return V_7 ;
}
V_7 = F_14 ( V_2 -> V_8 . V_74 , & V_2 -> V_8 . V_76 ) ;
if ( V_7 ) {
F_4 ( V_2 -> V_59 , L_6 , V_7 ) ;
return V_7 ;
}
F_13 ( V_2 -> V_8 . V_74 ) ;
for ( V_6 = 0 ; V_6 < V_2 -> V_8 . V_56 ; ++ V_6 ) {
F_15 ( & V_2 -> V_8 . V_77 [ V_6 ] , 0 ) ;
V_2 -> V_8 . V_78 [ V_6 ] = NULL ;
V_2 -> V_8 . V_79 [ V_6 ] = 0 ;
}
return 0 ;
}
void F_16 ( struct V_1 * V_2 )
{
int V_7 ;
if ( V_2 -> V_8 . V_74 == NULL )
return;
V_7 = F_10 ( V_2 -> V_8 . V_74 , false ) ;
if ( ! V_7 ) {
F_17 ( V_2 -> V_8 . V_74 ) ;
F_18 ( V_2 -> V_8 . V_74 ) ;
F_13 ( V_2 -> V_8 . V_74 ) ;
}
F_11 ( & V_2 -> V_8 . V_74 ) ;
F_19 ( V_2 , & V_2 -> V_80 [ V_81 ] ) ;
F_20 ( V_2 -> V_58 ) ;
}
int F_21 ( struct V_1 * V_2 )
{
int V_6 , V_7 ;
if ( V_2 -> V_8 . V_74 == NULL )
return 0 ;
for ( V_6 = 0 ; V_6 < V_2 -> V_8 . V_56 ; ++ V_6 ) {
T_1 V_82 = F_22 ( & V_2 -> V_8 . V_77 [ V_6 ] ) ;
if ( V_82 != 0 ) {
struct V_83 * V_84 ;
F_23 ( V_2 ) ;
V_7 = F_24 ( V_2 ,
V_81 , V_82 , & V_84 ) ;
if ( V_7 ) {
F_25 ( L_7 , V_7 ) ;
continue;
}
F_26 ( V_84 , false ) ;
F_27 ( & V_84 ) ;
V_2 -> V_8 . V_78 [ V_6 ] = NULL ;
F_15 ( & V_2 -> V_8 . V_77 [ V_6 ] , 0 ) ;
}
}
return 0 ;
}
int F_28 ( struct V_1 * V_2 )
{
unsigned V_68 ;
void * V_85 ;
if ( V_2 -> V_8 . V_74 == NULL )
return - V_54 ;
memcpy ( V_2 -> V_8 . V_76 , V_2 -> V_58 -> V_62 , V_2 -> V_58 -> V_68 ) ;
V_68 = F_29 ( V_2 -> V_8 . V_74 ) ;
V_68 -= V_2 -> V_58 -> V_68 ;
V_85 = V_2 -> V_8 . V_76 ;
V_85 += V_2 -> V_58 -> V_68 ;
memset ( V_85 , 0 , V_68 ) ;
return 0 ;
}
void F_30 ( struct V_86 * V_87 ,
T_1 V_88 )
{
int V_6 ;
for ( V_6 = 0 ; V_6 < V_87 -> V_89 . V_90 ; ++ V_6 ) {
V_87 -> V_91 [ V_6 ] . V_92 = 0 >> V_93 ;
V_87 -> V_91 [ V_6 ] . V_94 = ( 256 * 1024 * 1024 ) >> V_93 ;
}
if ( V_88 == V_73 )
return;
if ( V_87 -> V_89 . V_90 > 1 )
return;
V_87 -> V_91 [ 1 ] = V_87 -> V_91 [ 0 ] ;
V_87 -> V_91 [ 1 ] . V_92 += ( 256 * 1024 * 1024 ) >> V_93 ;
V_87 -> V_91 [ 1 ] . V_94 += ( 256 * 1024 * 1024 ) >> V_93 ;
V_87 -> V_89 . V_90 ++ ;
V_87 -> V_89 . V_95 ++ ;
}
void F_31 ( struct V_1 * V_2 , struct V_96 * V_78 )
{
int V_6 , V_7 ;
for ( V_6 = 0 ; V_6 < V_2 -> V_8 . V_56 ; ++ V_6 ) {
T_1 V_82 = F_22 ( & V_2 -> V_8 . V_77 [ V_6 ] ) ;
if ( V_82 != 0 && V_2 -> V_8 . V_78 [ V_6 ] == V_78 ) {
struct V_83 * V_84 ;
F_23 ( V_2 ) ;
V_7 = F_24 ( V_2 ,
V_81 , V_82 , & V_84 ) ;
if ( V_7 ) {
F_25 ( L_7 , V_7 ) ;
continue;
}
F_26 ( V_84 , false ) ;
F_27 ( & V_84 ) ;
V_2 -> V_8 . V_78 [ V_6 ] = NULL ;
F_15 ( & V_2 -> V_8 . V_77 [ V_6 ] , 0 ) ;
}
}
}
static int F_32 ( T_1 * V_97 , unsigned V_98 [] )
{
unsigned V_99 = V_97 [ 4 ] ;
unsigned V_100 = V_97 [ 6 ] ;
unsigned V_101 = V_97 [ 7 ] ;
unsigned V_102 = V_97 [ 9 ] ;
unsigned V_103 = V_97 [ 28 ] ;
unsigned V_104 = V_100 / 16 ;
unsigned V_105 = F_33 ( V_101 / 16 , 2 ) ;
unsigned V_106 , V_107 , V_108 ;
V_106 = V_100 * V_101 ;
V_106 += V_106 / 2 ;
V_106 = F_33 ( V_106 , 1024 ) ;
switch ( V_99 ) {
case 0 :
V_108 = V_106 * 17 ;
V_108 += V_104 * V_105 * 17 * 192 ;
V_108 += V_104 * V_105 * 32 ;
break;
case 1 :
V_108 = V_106 * 3 ;
V_108 += V_104 * V_105 * 128 ;
V_108 += V_104 * 64 ;
V_108 += V_104 * 128 ;
V_107 = F_34 ( V_104 , V_105 ) ;
V_108 += F_33 ( V_107 * 7 * 16 , 64 ) ;
break;
case 3 :
V_108 = V_106 * 3 ;
break;
case 4 :
V_108 = V_106 * 3 ;
V_108 += V_104 * V_105 * 64 ;
V_108 += F_33 ( V_104 * V_105 * 32 , 64 ) ;
break;
default:
F_25 ( L_8 , V_99 ) ;
return - V_54 ;
}
if ( V_100 > V_103 ) {
F_25 ( L_9 ) ;
return - V_54 ;
}
if ( V_102 < V_108 ) {
F_25 ( L_10 ,
V_102 , V_108 ) ;
return - V_54 ;
}
V_98 [ 0x1 ] = V_102 ;
V_98 [ 0x2 ] = V_106 ;
return 0 ;
}
static int F_35 ( struct V_109 * V_110 ,
unsigned V_99 )
{
switch ( V_99 ) {
case 0 :
case 1 :
return 0 ;
case 3 :
case 4 :
if ( V_110 -> V_2 -> V_11 >= V_35 )
return 0 ;
default:
F_25 ( L_11 ,
V_99 ) ;
return - V_54 ;
}
}
static int F_36 ( struct V_109 * V_110 , struct V_86 * V_111 ,
unsigned V_112 , unsigned V_98 [] )
{
T_2 * V_97 , V_113 , V_82 ;
unsigned V_79 = 0 ;
struct V_84 * V_114 ;
void * V_85 ;
int V_6 , V_7 ;
if ( V_112 & 0x3F ) {
F_25 ( L_12 ) ;
return - V_54 ;
}
V_114 = F_37 ( V_111 -> V_115 . V_116 ) ;
if ( V_114 ) {
V_7 = F_26 ( (struct V_83 * ) V_114 , false ) ;
if ( V_7 ) {
F_25 ( L_13 , V_7 ) ;
return V_7 ;
}
}
V_7 = F_14 ( V_111 , & V_85 ) ;
if ( V_7 ) {
F_25 ( L_14 , V_7 ) ;
return V_7 ;
}
V_97 = V_85 + V_112 ;
V_113 = V_97 [ 1 ] ;
V_82 = V_97 [ 2 ] ;
if ( V_82 == 0 ) {
F_25 ( L_15 ) ;
return - V_54 ;
}
switch ( V_113 ) {
case 0 :
V_79 = V_97 [ 7 ] * V_97 [ 8 ] ;
V_7 = F_35 ( V_110 , V_97 [ 4 ] ) ;
F_17 ( V_111 ) ;
if ( V_7 )
return V_7 ;
for ( V_6 = 0 ; V_6 < V_110 -> V_2 -> V_8 . V_56 ; ++ V_6 ) {
if ( F_22 ( & V_110 -> V_2 -> V_8 . V_77 [ V_6 ] ) == V_82 ) {
F_25 ( L_16 , V_82 ) ;
return - V_54 ;
}
if ( ! F_38 ( & V_110 -> V_2 -> V_8 . V_77 [ V_6 ] , 0 , V_82 ) ) {
V_110 -> V_2 -> V_8 . V_78 [ V_6 ] = V_110 -> V_78 ;
V_110 -> V_2 -> V_8 . V_79 [ V_6 ] = V_79 ;
return 0 ;
}
}
F_25 ( L_17 ) ;
return - V_54 ;
case 1 :
V_7 = F_35 ( V_110 , V_97 [ 4 ] ) ;
if ( ! V_7 )
V_7 = F_32 ( V_97 , V_98 ) ;
F_17 ( V_111 ) ;
if ( V_7 )
return V_7 ;
for ( V_6 = 0 ; V_6 < V_110 -> V_2 -> V_8 . V_56 ; ++ V_6 ) {
if ( F_22 ( & V_110 -> V_2 -> V_8 . V_77 [ V_6 ] ) == V_82 ) {
if ( V_110 -> V_2 -> V_8 . V_78 [ V_6 ] != V_110 -> V_78 ) {
F_25 ( L_18 ) ;
return - V_54 ;
}
return 0 ;
}
}
F_25 ( L_19 , V_82 ) ;
return - V_117 ;
case 2 :
for ( V_6 = 0 ; V_6 < V_110 -> V_2 -> V_8 . V_56 ; ++ V_6 )
F_38 ( & V_110 -> V_2 -> V_8 . V_77 [ V_6 ] , V_82 , 0 ) ;
F_17 ( V_111 ) ;
return 0 ;
default:
F_25 ( L_20 , V_113 ) ;
return - V_54 ;
}
F_39 () ;
return - V_54 ;
}
static int F_40 ( struct V_109 * V_110 ,
int V_118 , int V_119 ,
unsigned V_98 [] , bool * V_120 )
{
struct V_121 * V_122 ;
struct V_123 * V_124 ;
unsigned V_125 , V_126 , V_112 ;
T_3 V_127 , V_128 ;
int V_7 ;
V_122 = V_110 -> V_129 ;
V_112 = F_41 ( V_110 , V_118 ) ;
V_125 = F_41 ( V_110 , V_119 ) ;
if ( V_125 >= V_122 -> V_130 ) {
F_25 ( L_21 ,
V_125 , V_122 -> V_130 ) ;
return - V_54 ;
}
V_124 = & V_110 -> V_131 [ ( V_125 / 4 ) ] ;
V_127 = V_124 -> V_132 ;
V_128 = V_127 + F_29 ( V_124 -> V_133 ) ;
V_127 += V_112 ;
V_110 -> V_134 . V_85 [ V_118 ] = V_127 & 0xFFFFFFFF ;
V_110 -> V_134 . V_85 [ V_119 ] = V_127 >> 32 ;
V_126 = F_41 ( V_110 , V_110 -> V_125 ) >> 1 ;
if ( V_126 < 0x4 ) {
if ( V_128 <= V_127 ) {
F_25 ( L_22 , V_112 ) ;
return - V_54 ;
}
if ( ( V_128 - V_127 ) < V_98 [ V_126 ] ) {
F_25 ( L_23 , V_126 ,
( unsigned ) ( V_128 - V_127 ) , V_98 [ V_126 ] ) ;
return - V_54 ;
}
} else if ( V_126 != 0x100 ) {
F_25 ( L_24 , V_126 ) ;
return - V_54 ;
}
if ( ( V_127 >> 28 ) != ( ( V_128 - 1 ) >> 28 ) ) {
F_25 ( L_25 ,
V_127 , V_128 ) ;
return - V_54 ;
}
if ( ( V_126 == 0 || V_126 == 0x3 ) &&
( V_127 >> 28 ) != ( V_110 -> V_2 -> V_8 . V_75 >> 28 ) ) {
F_25 ( L_26 ,
V_127 , V_128 ) ;
return - V_54 ;
}
if ( V_126 == 0 ) {
if ( * V_120 ) {
F_25 ( L_27 ) ;
return - V_54 ;
}
* V_120 = true ;
V_7 = F_36 ( V_110 , V_124 -> V_133 , V_112 , V_98 ) ;
if ( V_7 )
return V_7 ;
} else if ( ! * V_120 ) {
F_25 ( L_28 ) ;
return - V_54 ;
}
return 0 ;
}
static int F_42 ( struct V_109 * V_110 ,
struct V_135 * V_136 ,
int * V_118 , int * V_119 ,
unsigned V_98 [] ,
bool * V_120 )
{
int V_6 , V_7 ;
V_110 -> V_125 ++ ;
for ( V_6 = 0 ; V_6 <= V_136 -> V_137 ; ++ V_6 ) {
switch ( V_136 -> V_138 + V_6 * 4 ) {
case V_139 :
* V_118 = V_110 -> V_125 ;
break;
case V_140 :
* V_119 = V_110 -> V_125 ;
break;
case V_141 :
V_7 = F_40 ( V_110 , * V_118 , * V_119 ,
V_98 , V_120 ) ;
if ( V_7 )
return V_7 ;
break;
case V_142 :
break;
default:
F_25 ( L_29 ,
V_136 -> V_138 + V_6 * 4 ) ;
return - V_54 ;
}
V_110 -> V_125 ++ ;
}
return 0 ;
}
int F_43 ( struct V_109 * V_110 )
{
struct V_135 V_136 ;
int V_7 , V_118 = 0 , V_119 = 0 ;
bool V_120 = false ;
unsigned V_98 [] = {
[ 0x00000000 ] = 2048 ,
[ 0x00000001 ] = 32 * 1024 * 1024 ,
[ 0x00000002 ] = 2048 * 1152 * 3 ,
[ 0x00000003 ] = 2048 ,
} ;
if ( V_110 -> V_143 -> V_130 % 16 ) {
F_25 ( L_30 ,
V_110 -> V_143 -> V_130 ) ;
return - V_54 ;
}
if ( V_110 -> V_129 == NULL ) {
F_25 ( L_31 ) ;
return - V_54 ;
}
do {
V_7 = F_44 ( V_110 , & V_136 , V_110 -> V_125 ) ;
if ( V_7 )
return V_7 ;
switch ( V_136 . type ) {
case V_144 :
V_7 = F_42 ( V_110 , & V_136 , & V_118 , & V_119 ,
V_98 , & V_120 ) ;
if ( V_7 )
return V_7 ;
break;
case V_145 :
V_110 -> V_125 += V_136 . V_137 + 2 ;
break;
default:
F_25 ( L_32 , V_136 . type ) ;
return - V_54 ;
}
} while ( V_110 -> V_125 < V_110 -> V_143 -> V_130 );
if ( ! V_120 ) {
F_25 ( L_33 ) ;
return - V_54 ;
}
return 0 ;
}
static int F_45 ( struct V_1 * V_2 ,
int V_80 , T_3 V_146 ,
struct V_83 * * V_84 )
{
struct V_147 V_134 ;
int V_6 , V_7 ;
V_7 = F_46 ( V_2 , V_80 , & V_134 , NULL , 64 ) ;
if ( V_7 )
return V_7 ;
V_134 . V_85 [ 0 ] = F_47 ( V_139 , 0 ) ;
V_134 . V_85 [ 1 ] = V_146 ;
V_134 . V_85 [ 2 ] = F_47 ( V_140 , 0 ) ;
V_134 . V_85 [ 3 ] = V_146 >> 32 ;
V_134 . V_85 [ 4 ] = F_47 ( V_141 , 0 ) ;
V_134 . V_85 [ 5 ] = 0 ;
for ( V_6 = 6 ; V_6 < 16 ; ++ V_6 )
V_134 . V_85 [ V_6 ] = F_48 ( 0 ) ;
V_134 . V_130 = 16 ;
V_7 = F_49 ( V_2 , & V_134 , NULL , false ) ;
if ( V_84 )
* V_84 = F_50 ( V_134 . V_84 ) ;
F_51 ( V_2 , & V_134 ) ;
return V_7 ;
}
int F_52 ( struct V_1 * V_2 , int V_80 ,
T_1 V_82 , struct V_83 * * V_84 )
{
T_3 V_148 = F_29 ( V_2 -> V_8 . V_74 ) -
V_149 ;
T_1 * V_97 = V_2 -> V_8 . V_76 + V_148 ;
T_3 V_146 = V_2 -> V_8 . V_75 + V_148 ;
int V_7 , V_6 ;
V_7 = F_10 ( V_2 -> V_8 . V_74 , true ) ;
if ( V_7 )
return V_7 ;
V_97 [ 0 ] = F_53 ( 0x00000de4 ) ;
V_97 [ 1 ] = F_53 ( 0x00000000 ) ;
V_97 [ 2 ] = F_53 ( V_82 ) ;
V_97 [ 3 ] = F_53 ( 0x00000000 ) ;
V_97 [ 4 ] = F_53 ( 0x00000000 ) ;
V_97 [ 5 ] = F_53 ( 0x00000000 ) ;
V_97 [ 6 ] = F_53 ( 0x00000000 ) ;
V_97 [ 7 ] = F_53 ( 0x00000780 ) ;
V_97 [ 8 ] = F_53 ( 0x00000440 ) ;
V_97 [ 9 ] = F_53 ( 0x00000000 ) ;
V_97 [ 10 ] = F_53 ( 0x01b37000 ) ;
for ( V_6 = 11 ; V_6 < 1024 ; ++ V_6 )
V_97 [ V_6 ] = F_53 ( 0x0 ) ;
V_7 = F_45 ( V_2 , V_80 , V_146 , V_84 ) ;
F_13 ( V_2 -> V_8 . V_74 ) ;
return V_7 ;
}
int F_24 ( struct V_1 * V_2 , int V_80 ,
T_1 V_82 , struct V_83 * * V_84 )
{
T_3 V_148 = F_29 ( V_2 -> V_8 . V_74 ) -
V_149 ;
T_1 * V_97 = V_2 -> V_8 . V_76 + V_148 ;
T_3 V_146 = V_2 -> V_8 . V_75 + V_148 ;
int V_7 , V_6 ;
V_7 = F_10 ( V_2 -> V_8 . V_74 , true ) ;
if ( V_7 )
return V_7 ;
V_97 [ 0 ] = F_53 ( 0x00000de4 ) ;
V_97 [ 1 ] = F_53 ( 0x00000002 ) ;
V_97 [ 2 ] = F_53 ( V_82 ) ;
V_97 [ 3 ] = F_53 ( 0x00000000 ) ;
for ( V_6 = 4 ; V_6 < 1024 ; ++ V_6 )
V_97 [ V_6 ] = F_53 ( 0x0 ) ;
V_7 = F_45 ( V_2 , V_80 , V_146 , V_84 ) ;
F_13 ( V_2 -> V_8 . V_74 ) ;
return V_7 ;
}
static void F_54 ( struct V_1 * V_2 ,
unsigned * V_150 , unsigned * V_151 )
{
unsigned V_6 ;
* V_150 = 0 ;
* V_151 = 0 ;
for ( V_6 = 0 ; V_6 < V_2 -> V_8 . V_56 ; ++ V_6 ) {
if ( ! F_22 ( & V_2 -> V_8 . V_77 [ V_6 ] ) )
continue;
if ( V_2 -> V_8 . V_79 [ V_6 ] >= 720 * 576 )
++ ( * V_151 ) ;
else
++ ( * V_150 ) ;
}
}
static void V_10 ( struct V_152 * V_153 )
{
struct V_1 * V_2 =
F_55 ( V_153 , struct V_1 , V_8 . V_9 . V_153 ) ;
if ( F_56 ( V_2 , V_81 ) == 0 ) {
if ( ( V_2 -> V_154 . V_155 == V_156 ) && V_2 -> V_154 . V_157 ) {
F_54 ( V_2 , & V_2 -> V_154 . V_158 . V_150 ,
& V_2 -> V_154 . V_158 . V_151 ) ;
F_57 ( V_2 , false ) ;
} else {
F_58 ( V_2 , 0 , 0 ) ;
}
} else {
F_59 ( & V_2 -> V_8 . V_9 ,
F_60 ( V_159 ) ) ;
}
}
void F_23 ( struct V_1 * V_2 )
{
bool V_160 = false ;
bool V_161 = ! F_61 ( & V_2 -> V_8 . V_9 ) ;
V_161 &= F_59 ( & V_2 -> V_8 . V_9 ,
F_60 ( V_159 ) ) ;
if ( ( V_2 -> V_154 . V_155 == V_156 ) && V_2 -> V_154 . V_157 ) {
unsigned V_151 = 0 , V_150 = 0 ;
F_54 ( V_2 , & V_150 , & V_151 ) ;
if ( ( V_2 -> V_154 . V_158 . V_150 != V_150 ) ||
( V_2 -> V_154 . V_158 . V_151 != V_151 ) ) {
V_2 -> V_154 . V_158 . V_150 = V_150 ;
V_2 -> V_154 . V_158 . V_151 = V_151 ;
}
}
if ( V_161 || V_160 ) {
if ( ( V_2 -> V_154 . V_155 == V_156 ) && V_2 -> V_154 . V_157 ) {
F_57 ( V_2 , true ) ;
} else {
F_58 ( V_2 , 53300 , 40000 ) ;
}
}
}
static unsigned F_62 ( unsigned V_162 ,
unsigned V_163 ,
unsigned V_164 ,
unsigned V_165 )
{
unsigned V_166 = V_162 / V_163 ;
if ( V_166 < V_164 )
V_166 = V_164 ;
if ( ( V_162 / V_166 ) > V_163 )
V_166 += 1 ;
if ( V_166 > V_165 && V_166 % 2 )
V_166 += 1 ;
return V_166 ;
}
int F_63 ( struct V_1 * V_2 ,
unsigned V_167 , unsigned V_168 ,
unsigned V_169 , unsigned V_170 ,
unsigned V_171 , unsigned V_172 ,
unsigned V_164 , unsigned V_173 ,
unsigned V_165 ,
unsigned * V_174 ,
unsigned * V_175 ,
unsigned * V_176 )
{
unsigned V_162 , V_177 = V_2 -> clock . V_178 . V_179 ;
unsigned V_180 = ~ 0 ;
V_169 = F_34 ( F_34 ( V_169 , V_167 ) , V_168 ) ;
for ( V_162 = V_169 ; V_162 <= V_170 ; V_162 += 100 ) {
T_3 V_181 = ( T_3 ) V_162 * V_171 ;
unsigned V_182 , V_183 , V_184 ;
F_64 ( V_181 , V_177 ) ;
if ( V_181 > V_172 )
break;
V_181 &= V_172 ;
V_182 = F_62 ( V_162 , V_167 ,
V_164 , V_165 ) ;
if ( V_182 > V_173 )
break;
V_183 = F_62 ( V_162 , V_168 ,
V_164 , V_165 ) ;
if ( V_182 > V_173 )
break;
V_184 = V_167 - ( V_162 / V_182 ) + V_168 - ( V_162 / V_183 ) ;
if ( V_184 < V_180 ) {
* V_174 = V_181 ;
* V_175 = V_182 ;
* V_176 = V_183 ;
V_180 = V_184 ;
if ( V_180 == 0 )
break;
}
}
if ( V_180 == ~ 0 )
return - V_54 ;
return 0 ;
}
int F_65 ( struct V_1 * V_2 ,
unsigned V_185 )
{
unsigned V_6 ;
F_66 ( V_185 , 0 , ~ V_186 ) ;
F_67 ( 10 ) ;
F_66 ( V_185 , V_186 , ~ V_186 ) ;
for ( V_6 = 0 ; V_6 < 100 ; ++ V_6 ) {
T_1 V_187 = V_188 | V_189 ;
if ( ( F_68 ( V_185 ) & V_187 ) == V_187 )
break;
F_67 ( 10 ) ;
}
F_66 ( V_185 , 0 , ~ V_186 ) ;
if ( V_6 == 100 ) {
F_25 ( L_34 ) ;
return - V_190 ;
}
return 0 ;
}
