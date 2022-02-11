int F_1 ( struct V_1 * V_2 )
{
unsigned long V_3 ;
const char * V_4 ;
int V_5 , V_6 ;
F_2 ( & V_2 -> V_7 . V_8 , V_9 ) ;
switch ( V_2 -> V_10 ) {
case V_11 :
case V_12 :
case V_13 :
case V_14 :
case V_15 :
V_4 = V_16 ;
break;
case V_17 :
case V_18 :
V_4 = V_19 ;
break;
case V_20 :
V_4 = V_21 ;
break;
case V_22 :
case V_23 :
case V_24 :
V_4 = V_25 ;
break;
case V_26 :
case V_27 :
case V_28 :
case V_29 :
case V_30 :
V_4 = V_31 ;
break;
case V_32 :
case V_33 :
case V_34 :
case V_35 :
case V_36 :
case V_37 :
case V_38 :
V_4 = V_39 ;
break;
case V_40 :
case V_41 :
case V_42 :
case V_43 :
case V_44 :
V_4 = V_45 ;
break;
case V_46 :
case V_47 :
case V_48 :
case V_49 :
case V_50 :
V_4 = V_51 ;
break;
default:
return - V_52 ;
}
V_6 = F_3 ( & V_2 -> V_53 , V_4 , V_2 -> V_54 ) ;
if ( V_6 ) {
F_4 ( V_2 -> V_54 , L_1 ,
V_4 ) ;
return V_6 ;
}
V_3 = F_5 ( V_2 -> V_53 -> V_55 + 8 ) +
V_56 + V_57 +
V_58 ;
V_6 = F_6 ( V_2 , V_3 , V_59 , true ,
V_60 , 0 , NULL ,
NULL , & V_2 -> V_7 . V_61 ) ;
if ( V_6 ) {
F_4 ( V_2 -> V_54 , L_2 , V_6 ) ;
return V_6 ;
}
V_6 = F_7 ( V_2 -> V_7 . V_61 , false ) ;
if ( V_6 ) {
F_8 ( & V_2 -> V_7 . V_61 ) ;
F_4 ( V_2 -> V_54 , L_3 , V_6 ) ;
return V_6 ;
}
V_6 = F_9 ( V_2 -> V_7 . V_61 , V_60 ,
& V_2 -> V_7 . V_62 ) ;
if ( V_6 ) {
F_10 ( V_2 -> V_7 . V_61 ) ;
F_8 ( & V_2 -> V_7 . V_61 ) ;
F_4 ( V_2 -> V_54 , L_4 , V_6 ) ;
return V_6 ;
}
V_6 = F_11 ( V_2 -> V_7 . V_61 , & V_2 -> V_7 . V_63 ) ;
if ( V_6 ) {
F_4 ( V_2 -> V_54 , L_5 , V_6 ) ;
return V_6 ;
}
F_10 ( V_2 -> V_7 . V_61 ) ;
for ( V_5 = 0 ; V_5 < V_64 ; ++ V_5 ) {
F_12 ( & V_2 -> V_7 . V_65 [ V_5 ] , 0 ) ;
V_2 -> V_7 . V_66 [ V_5 ] = NULL ;
V_2 -> V_7 . V_67 [ V_5 ] = 0 ;
}
return 0 ;
}
void F_13 ( struct V_1 * V_2 )
{
int V_6 ;
if ( V_2 -> V_7 . V_61 == NULL )
return;
V_6 = F_7 ( V_2 -> V_7 . V_61 , false ) ;
if ( ! V_6 ) {
F_14 ( V_2 -> V_7 . V_61 ) ;
F_15 ( V_2 -> V_7 . V_61 ) ;
F_10 ( V_2 -> V_7 . V_61 ) ;
}
F_8 ( & V_2 -> V_7 . V_61 ) ;
F_16 ( V_2 , & V_2 -> V_68 [ V_69 ] ) ;
F_17 ( V_2 -> V_53 ) ;
}
int F_18 ( struct V_1 * V_2 )
{
unsigned V_55 ;
void * V_70 ;
int V_5 ;
if ( V_2 -> V_7 . V_61 == NULL )
return 0 ;
for ( V_5 = 0 ; V_5 < V_64 ; ++ V_5 )
if ( F_19 ( & V_2 -> V_7 . V_65 [ V_5 ] ) )
break;
if ( V_5 == V_64 )
return 0 ;
V_55 = F_20 ( V_2 -> V_7 . V_61 ) ;
V_55 -= V_2 -> V_53 -> V_55 ;
V_70 = V_2 -> V_7 . V_63 ;
V_70 += V_2 -> V_53 -> V_55 ;
V_2 -> V_7 . V_71 = F_21 ( V_55 , V_72 ) ;
memcpy ( V_2 -> V_7 . V_71 , V_70 , V_55 ) ;
return 0 ;
}
int F_22 ( struct V_1 * V_2 )
{
unsigned V_55 ;
void * V_70 ;
if ( V_2 -> V_7 . V_61 == NULL )
return - V_52 ;
memcpy ( V_2 -> V_7 . V_63 , V_2 -> V_53 -> V_73 , V_2 -> V_53 -> V_55 ) ;
V_55 = F_20 ( V_2 -> V_7 . V_61 ) ;
V_55 -= V_2 -> V_53 -> V_55 ;
V_70 = V_2 -> V_7 . V_63 ;
V_70 += V_2 -> V_53 -> V_55 ;
if ( V_2 -> V_7 . V_71 != NULL ) {
memcpy ( V_70 , V_2 -> V_7 . V_71 , V_55 ) ;
F_23 ( V_2 -> V_7 . V_71 ) ;
V_2 -> V_7 . V_71 = NULL ;
} else
memset ( V_70 , 0 , V_55 ) ;
return 0 ;
}
void F_24 ( struct V_74 * V_75 ,
T_1 V_76 )
{
int V_5 ;
for ( V_5 = 0 ; V_5 < V_75 -> V_77 . V_78 ; ++ V_5 ) {
V_75 -> V_79 [ V_5 ] . V_80 = 0 >> V_81 ;
V_75 -> V_79 [ V_5 ] . V_82 = ( 256 * 1024 * 1024 ) >> V_81 ;
}
if ( V_76 == V_60 )
return;
if ( V_75 -> V_77 . V_78 > 1 )
return;
V_75 -> V_79 [ 1 ] = V_75 -> V_79 [ 0 ] ;
V_75 -> V_79 [ 1 ] . V_80 += ( 256 * 1024 * 1024 ) >> V_81 ;
V_75 -> V_79 [ 1 ] . V_82 += ( 256 * 1024 * 1024 ) >> V_81 ;
V_75 -> V_77 . V_78 ++ ;
V_75 -> V_77 . V_83 ++ ;
}
void F_25 ( struct V_1 * V_2 , struct V_84 * V_66 )
{
int V_5 , V_6 ;
for ( V_5 = 0 ; V_5 < V_64 ; ++ V_5 ) {
T_1 V_85 = F_19 ( & V_2 -> V_7 . V_65 [ V_5 ] ) ;
if ( V_85 != 0 && V_2 -> V_7 . V_66 [ V_5 ] == V_66 ) {
struct V_86 * V_87 ;
F_26 ( V_2 ) ;
V_6 = F_27 ( V_2 ,
V_69 , V_85 , & V_87 ) ;
if ( V_6 ) {
F_28 ( L_6 , V_6 ) ;
continue;
}
F_29 ( V_87 , false ) ;
F_30 ( & V_87 ) ;
V_2 -> V_7 . V_66 [ V_5 ] = NULL ;
F_12 ( & V_2 -> V_7 . V_65 [ V_5 ] , 0 ) ;
}
}
}
static int F_31 ( T_1 * V_88 , unsigned V_89 [] )
{
unsigned V_90 = V_88 [ 4 ] ;
unsigned V_91 = V_88 [ 6 ] ;
unsigned V_92 = V_88 [ 7 ] ;
unsigned V_93 = V_88 [ 9 ] ;
unsigned V_94 = V_88 [ 28 ] ;
unsigned V_95 = V_91 / 16 ;
unsigned V_96 = F_32 ( V_92 / 16 , 2 ) ;
unsigned V_97 , V_98 , V_99 ;
V_97 = V_91 * V_92 ;
V_97 += V_97 / 2 ;
V_97 = F_32 ( V_97 , 1024 ) ;
switch ( V_90 ) {
case 0 :
V_99 = V_97 * 17 ;
V_99 += V_95 * V_96 * 17 * 192 ;
V_99 += V_95 * V_96 * 32 ;
break;
case 1 :
V_99 = V_97 * 3 ;
V_99 += V_95 * V_96 * 128 ;
V_99 += V_95 * 64 ;
V_99 += V_95 * 128 ;
V_98 = F_33 ( V_95 , V_96 ) ;
V_99 += F_32 ( V_98 * 7 * 16 , 64 ) ;
break;
case 3 :
V_99 = V_97 * 3 ;
break;
case 4 :
V_99 = V_97 * 3 ;
V_99 += V_95 * V_96 * 64 ;
V_99 += F_32 ( V_95 * V_96 * 32 , 64 ) ;
break;
default:
F_28 ( L_7 , V_90 ) ;
return - V_52 ;
}
if ( V_91 > V_94 ) {
F_28 ( L_8 ) ;
return - V_52 ;
}
if ( V_93 < V_99 ) {
F_28 ( L_9 ,
V_93 , V_99 ) ;
return - V_52 ;
}
V_89 [ 0x1 ] = V_93 ;
V_89 [ 0x2 ] = V_97 ;
return 0 ;
}
static int F_34 ( struct V_100 * V_101 , struct V_74 * V_102 ,
unsigned V_103 , unsigned V_89 [] )
{
T_2 * V_88 , V_104 , V_85 ;
unsigned V_67 = 0 ;
struct V_87 * V_105 ;
void * V_70 ;
int V_5 , V_6 ;
if ( V_103 & 0x3F ) {
F_28 ( L_10 ) ;
return - V_52 ;
}
V_105 = F_35 ( V_102 -> V_106 . V_107 ) ;
if ( V_105 ) {
V_6 = F_29 ( (struct V_86 * ) V_105 , false ) ;
if ( V_6 ) {
F_28 ( L_11 , V_6 ) ;
return V_6 ;
}
}
V_6 = F_11 ( V_102 , & V_70 ) ;
if ( V_6 ) {
F_28 ( L_12 , V_6 ) ;
return V_6 ;
}
V_88 = V_70 + V_103 ;
V_104 = V_88 [ 1 ] ;
V_85 = V_88 [ 2 ] ;
if ( V_85 == 0 ) {
F_28 ( L_13 ) ;
return - V_52 ;
}
if ( V_104 == 1 ) {
V_6 = F_31 ( V_88 , V_89 ) ;
V_67 = V_88 [ 6 ] * V_88 [ 7 ] ;
F_14 ( V_102 ) ;
if ( V_6 )
return V_6 ;
} else if ( V_104 == 2 ) {
for ( V_5 = 0 ; V_5 < V_64 ; ++ V_5 )
F_36 ( & V_101 -> V_2 -> V_7 . V_65 [ V_5 ] , V_85 , 0 ) ;
F_14 ( V_102 ) ;
return 0 ;
} else {
V_67 = V_88 [ 7 ] * V_88 [ 8 ] ;
F_14 ( V_102 ) ;
if ( V_104 != 0 ) {
F_28 ( L_14 , V_104 ) ;
return - V_52 ;
}
}
for ( V_5 = 0 ; V_5 < V_64 ; ++ V_5 ) {
if ( F_19 ( & V_101 -> V_2 -> V_7 . V_65 [ V_5 ] ) == V_85 )
return 0 ;
}
for ( V_5 = 0 ; V_5 < V_64 ; ++ V_5 ) {
if ( ! F_36 ( & V_101 -> V_2 -> V_7 . V_65 [ V_5 ] , 0 , V_85 ) ) {
V_101 -> V_2 -> V_7 . V_66 [ V_5 ] = V_101 -> V_66 ;
V_101 -> V_2 -> V_7 . V_67 [ V_5 ] = V_67 ;
return 0 ;
}
}
F_28 ( L_15 ) ;
return - V_52 ;
}
static int F_37 ( struct V_100 * V_101 ,
int V_108 , int V_109 ,
unsigned V_89 [] , bool * V_110 )
{
struct V_111 * V_112 ;
struct V_113 * V_114 ;
unsigned V_115 , V_116 , V_103 ;
T_3 V_117 , V_118 ;
int V_6 ;
V_112 = & V_101 -> V_119 [ V_101 -> V_120 ] ;
V_103 = F_38 ( V_101 , V_108 ) ;
V_115 = F_38 ( V_101 , V_109 ) ;
if ( V_115 >= V_112 -> V_121 ) {
F_28 ( L_16 ,
V_115 , V_112 -> V_121 ) ;
return - V_52 ;
}
V_114 = V_101 -> V_122 [ ( V_115 / 4 ) ] ;
V_117 = V_114 -> V_123 ;
V_118 = V_117 + F_20 ( V_114 -> V_124 ) ;
V_117 += V_103 ;
V_101 -> V_125 . V_70 [ V_108 ] = V_117 & 0xFFFFFFFF ;
V_101 -> V_125 . V_70 [ V_109 ] = V_117 >> 32 ;
V_116 = F_38 ( V_101 , V_101 -> V_115 ) >> 1 ;
if ( V_116 < 0x4 ) {
if ( V_118 <= V_117 ) {
F_28 ( L_17 , V_103 ) ;
return - V_52 ;
}
if ( ( V_118 - V_117 ) < V_89 [ V_116 ] ) {
F_28 ( L_18 , V_116 ,
( unsigned ) ( V_118 - V_117 ) , V_89 [ V_116 ] ) ;
return - V_52 ;
}
} else if ( V_116 != 0x100 ) {
F_28 ( L_19 , V_116 ) ;
return - V_52 ;
}
if ( ( V_117 >> 28 ) != ( ( V_118 - 1 ) >> 28 ) ) {
F_28 ( L_20 ,
V_117 , V_118 ) ;
return - V_52 ;
}
if ( ( V_116 == 0 || V_116 == 0x3 ) &&
( V_117 >> 28 ) != ( V_101 -> V_2 -> V_7 . V_62 >> 28 ) ) {
F_28 ( L_21 ,
V_117 , V_118 ) ;
return - V_52 ;
}
if ( V_116 == 0 ) {
if ( * V_110 ) {
F_28 ( L_22 ) ;
return - V_52 ;
}
* V_110 = true ;
V_6 = F_34 ( V_101 , V_114 -> V_124 , V_103 , V_89 ) ;
if ( V_6 )
return V_6 ;
} else if ( ! * V_110 ) {
F_28 ( L_23 ) ;
return - V_52 ;
}
return 0 ;
}
static int F_39 ( struct V_100 * V_101 ,
struct V_126 * V_127 ,
int * V_108 , int * V_109 ,
unsigned V_89 [] ,
bool * V_110 )
{
int V_5 , V_6 ;
V_101 -> V_115 ++ ;
for ( V_5 = 0 ; V_5 <= V_127 -> V_128 ; ++ V_5 ) {
switch ( V_127 -> V_129 + V_5 * 4 ) {
case V_130 :
* V_108 = V_101 -> V_115 ;
break;
case V_131 :
* V_109 = V_101 -> V_115 ;
break;
case V_132 :
V_6 = F_37 ( V_101 , * V_108 , * V_109 ,
V_89 , V_110 ) ;
if ( V_6 )
return V_6 ;
break;
case V_133 :
break;
default:
F_28 ( L_24 ,
V_127 -> V_129 + V_5 * 4 ) ;
return - V_52 ;
}
V_101 -> V_115 ++ ;
}
return 0 ;
}
int F_40 ( struct V_100 * V_101 )
{
struct V_126 V_127 ;
int V_6 , V_108 = 0 , V_109 = 0 ;
bool V_110 = false ;
unsigned V_89 [] = {
[ 0x00000000 ] = 2048 ,
[ 0x00000001 ] = 32 * 1024 * 1024 ,
[ 0x00000002 ] = 2048 * 1152 * 3 ,
[ 0x00000003 ] = 2048 ,
} ;
if ( V_101 -> V_119 [ V_101 -> V_134 ] . V_121 % 16 ) {
F_28 ( L_25 ,
V_101 -> V_119 [ V_101 -> V_134 ] . V_121 ) ;
return - V_52 ;
}
if ( V_101 -> V_120 == - 1 ) {
F_28 ( L_26 ) ;
return - V_52 ;
}
do {
V_6 = F_41 ( V_101 , & V_127 , V_101 -> V_115 ) ;
if ( V_6 )
return V_6 ;
switch ( V_127 . type ) {
case V_135 :
V_6 = F_39 ( V_101 , & V_127 , & V_108 , & V_109 ,
V_89 , & V_110 ) ;
if ( V_6 )
return V_6 ;
break;
case V_136 :
V_101 -> V_115 += V_127 . V_128 + 2 ;
break;
default:
F_28 ( L_27 , V_127 . type ) ;
return - V_52 ;
}
} while ( V_101 -> V_115 < V_101 -> V_119 [ V_101 -> V_134 ] . V_121 );
if ( ! V_110 ) {
F_28 ( L_28 ) ;
return - V_52 ;
}
return 0 ;
}
static int F_42 ( struct V_1 * V_2 ,
int V_68 , T_3 V_137 ,
struct V_86 * * V_87 )
{
struct V_138 V_125 ;
int V_5 , V_6 ;
V_6 = F_43 ( V_2 , V_68 , & V_125 , NULL , 64 ) ;
if ( V_6 )
return V_6 ;
V_125 . V_70 [ 0 ] = F_44 ( V_130 , 0 ) ;
V_125 . V_70 [ 1 ] = V_137 ;
V_125 . V_70 [ 2 ] = F_44 ( V_131 , 0 ) ;
V_125 . V_70 [ 3 ] = V_137 >> 32 ;
V_125 . V_70 [ 4 ] = F_44 ( V_132 , 0 ) ;
V_125 . V_70 [ 5 ] = 0 ;
for ( V_5 = 6 ; V_5 < 16 ; ++ V_5 )
V_125 . V_70 [ V_5 ] = F_45 ( 0 ) ;
V_125 . V_121 = 16 ;
V_6 = F_46 ( V_2 , & V_125 , NULL , false ) ;
if ( V_87 )
* V_87 = F_47 ( V_125 . V_87 ) ;
F_48 ( V_2 , & V_125 ) ;
return V_6 ;
}
int F_49 ( struct V_1 * V_2 , int V_68 ,
T_1 V_85 , struct V_86 * * V_87 )
{
T_3 V_139 = F_20 ( V_2 -> V_7 . V_61 ) -
V_58 ;
T_1 * V_88 = V_2 -> V_7 . V_63 + V_139 ;
T_3 V_137 = V_2 -> V_7 . V_62 + V_139 ;
int V_6 , V_5 ;
V_6 = F_7 ( V_2 -> V_7 . V_61 , true ) ;
if ( V_6 )
return V_6 ;
V_88 [ 0 ] = F_50 ( 0x00000de4 ) ;
V_88 [ 1 ] = F_50 ( 0x00000000 ) ;
V_88 [ 2 ] = F_50 ( V_85 ) ;
V_88 [ 3 ] = F_50 ( 0x00000000 ) ;
V_88 [ 4 ] = F_50 ( 0x00000000 ) ;
V_88 [ 5 ] = F_50 ( 0x00000000 ) ;
V_88 [ 6 ] = F_50 ( 0x00000000 ) ;
V_88 [ 7 ] = F_50 ( 0x00000780 ) ;
V_88 [ 8 ] = F_50 ( 0x00000440 ) ;
V_88 [ 9 ] = F_50 ( 0x00000000 ) ;
V_88 [ 10 ] = F_50 ( 0x01b37000 ) ;
for ( V_5 = 11 ; V_5 < 1024 ; ++ V_5 )
V_88 [ V_5 ] = F_50 ( 0x0 ) ;
V_6 = F_42 ( V_2 , V_68 , V_137 , V_87 ) ;
F_10 ( V_2 -> V_7 . V_61 ) ;
return V_6 ;
}
int F_27 ( struct V_1 * V_2 , int V_68 ,
T_1 V_85 , struct V_86 * * V_87 )
{
T_3 V_139 = F_20 ( V_2 -> V_7 . V_61 ) -
V_58 ;
T_1 * V_88 = V_2 -> V_7 . V_63 + V_139 ;
T_3 V_137 = V_2 -> V_7 . V_62 + V_139 ;
int V_6 , V_5 ;
V_6 = F_7 ( V_2 -> V_7 . V_61 , true ) ;
if ( V_6 )
return V_6 ;
V_88 [ 0 ] = F_50 ( 0x00000de4 ) ;
V_88 [ 1 ] = F_50 ( 0x00000002 ) ;
V_88 [ 2 ] = F_50 ( V_85 ) ;
V_88 [ 3 ] = F_50 ( 0x00000000 ) ;
for ( V_5 = 4 ; V_5 < 1024 ; ++ V_5 )
V_88 [ V_5 ] = F_50 ( 0x0 ) ;
V_6 = F_42 ( V_2 , V_68 , V_137 , V_87 ) ;
F_10 ( V_2 -> V_7 . V_61 ) ;
return V_6 ;
}
static void F_51 ( struct V_1 * V_2 ,
unsigned * V_140 , unsigned * V_141 )
{
unsigned V_5 ;
* V_140 = 0 ;
* V_141 = 0 ;
for ( V_5 = 0 ; V_5 < V_64 ; ++ V_5 ) {
if ( ! F_19 ( & V_2 -> V_7 . V_65 [ V_5 ] ) )
continue;
if ( V_2 -> V_7 . V_67 [ V_5 ] >= 720 * 576 )
++ ( * V_141 ) ;
else
++ ( * V_140 ) ;
}
}
static void V_9 ( struct V_142 * V_143 )
{
struct V_1 * V_2 =
F_52 ( V_143 , struct V_1 , V_7 . V_8 . V_143 ) ;
if ( F_53 ( V_2 , V_69 ) == 0 ) {
if ( ( V_2 -> V_144 . V_145 == V_146 ) && V_2 -> V_144 . V_147 ) {
F_51 ( V_2 , & V_2 -> V_144 . V_148 . V_140 ,
& V_2 -> V_144 . V_148 . V_141 ) ;
F_54 ( V_2 , false ) ;
} else {
F_55 ( V_2 , 0 , 0 ) ;
}
} else {
F_56 ( & V_2 -> V_7 . V_8 ,
F_57 ( V_149 ) ) ;
}
}
void F_26 ( struct V_1 * V_2 )
{
bool V_150 = false ;
bool V_151 = ! F_58 ( & V_2 -> V_7 . V_8 ) ;
V_151 &= F_56 ( & V_2 -> V_7 . V_8 ,
F_57 ( V_149 ) ) ;
if ( ( V_2 -> V_144 . V_145 == V_146 ) && V_2 -> V_144 . V_147 ) {
unsigned V_141 = 0 , V_140 = 0 ;
F_51 ( V_2 , & V_140 , & V_141 ) ;
if ( ( V_2 -> V_144 . V_148 . V_140 != V_140 ) ||
( V_2 -> V_144 . V_148 . V_141 != V_141 ) ) {
V_2 -> V_144 . V_148 . V_140 = V_140 ;
V_2 -> V_144 . V_148 . V_141 = V_141 ;
}
}
if ( V_151 || V_150 ) {
if ( ( V_2 -> V_144 . V_145 == V_146 ) && V_2 -> V_144 . V_147 ) {
F_54 ( V_2 , true ) ;
} else {
F_55 ( V_2 , 53300 , 40000 ) ;
}
}
}
static unsigned F_59 ( unsigned V_152 ,
unsigned V_153 ,
unsigned V_154 ,
unsigned V_155 )
{
unsigned V_156 = V_152 / V_153 ;
if ( V_156 < V_154 )
V_156 = V_154 ;
if ( ( V_152 / V_156 ) > V_153 )
V_156 += 1 ;
if ( V_156 > V_155 && V_156 % 2 )
V_156 += 1 ;
return V_156 ;
}
int F_60 ( struct V_1 * V_2 ,
unsigned V_157 , unsigned V_158 ,
unsigned V_159 , unsigned V_160 ,
unsigned V_161 , unsigned V_162 ,
unsigned V_154 , unsigned V_163 ,
unsigned V_155 ,
unsigned * V_164 ,
unsigned * V_165 ,
unsigned * V_166 )
{
unsigned V_152 , V_167 = V_2 -> clock . V_168 . V_169 ;
unsigned V_170 = ~ 0 ;
V_159 = F_33 ( F_33 ( V_159 , V_157 ) , V_158 ) ;
for ( V_152 = V_159 ; V_152 <= V_160 ; V_152 += 100 ) {
T_3 V_171 = ( T_3 ) V_152 * V_161 ;
unsigned V_172 , V_173 , V_174 ;
F_61 ( V_171 , V_167 ) ;
if ( V_171 > V_162 )
break;
V_171 &= V_162 ;
V_172 = F_59 ( V_152 , V_157 ,
V_154 , V_155 ) ;
if ( V_172 > V_163 )
break;
V_173 = F_59 ( V_152 , V_158 ,
V_154 , V_155 ) ;
if ( V_172 > V_163 )
break;
V_174 = V_157 - ( V_152 / V_172 ) + V_158 - ( V_152 / V_173 ) ;
if ( V_174 < V_170 ) {
* V_164 = V_171 ;
* V_165 = V_172 ;
* V_166 = V_173 ;
V_170 = V_174 ;
if ( V_170 == 0 )
break;
}
}
if ( V_170 == ~ 0 )
return - V_52 ;
return 0 ;
}
int F_62 ( struct V_1 * V_2 ,
unsigned V_175 )
{
unsigned V_5 ;
F_63 ( V_175 , 0 , ~ V_176 ) ;
F_64 ( 10 ) ;
F_63 ( V_175 , V_176 , ~ V_176 ) ;
for ( V_5 = 0 ; V_5 < 100 ; ++ V_5 ) {
T_1 V_177 = V_178 | V_179 ;
if ( ( F_65 ( V_175 ) & V_177 ) == V_177 )
break;
F_64 ( 10 ) ;
}
F_63 ( V_175 , 0 , ~ V_176 ) ;
if ( V_5 == 100 ) {
F_28 ( L_29 ) ;
return - V_180 ;
}
return 0 ;
}
