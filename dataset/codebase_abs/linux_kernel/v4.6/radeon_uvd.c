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
int V_5 , V_6 ;
if ( V_2 -> V_7 . V_61 == NULL )
return 0 ;
for ( V_5 = 0 ; V_5 < V_64 ; ++ V_5 ) {
T_1 V_70 = F_19 ( & V_2 -> V_7 . V_65 [ V_5 ] ) ;
if ( V_70 != 0 ) {
struct V_71 * V_72 ;
F_20 ( V_2 ) ;
V_6 = F_21 ( V_2 ,
V_69 , V_70 , & V_72 ) ;
if ( V_6 ) {
F_22 ( L_6 , V_6 ) ;
continue;
}
F_23 ( V_72 , false ) ;
F_24 ( & V_72 ) ;
V_2 -> V_7 . V_66 [ V_5 ] = NULL ;
F_12 ( & V_2 -> V_7 . V_65 [ V_5 ] , 0 ) ;
}
}
return 0 ;
}
int F_25 ( struct V_1 * V_2 )
{
unsigned V_55 ;
void * V_73 ;
if ( V_2 -> V_7 . V_61 == NULL )
return - V_52 ;
memcpy ( V_2 -> V_7 . V_63 , V_2 -> V_53 -> V_74 , V_2 -> V_53 -> V_55 ) ;
V_55 = F_26 ( V_2 -> V_7 . V_61 ) ;
V_55 -= V_2 -> V_53 -> V_55 ;
V_73 = V_2 -> V_7 . V_63 ;
V_73 += V_2 -> V_53 -> V_55 ;
memset ( V_73 , 0 , V_55 ) ;
return 0 ;
}
void F_27 ( struct V_75 * V_76 ,
T_1 V_77 )
{
int V_5 ;
for ( V_5 = 0 ; V_5 < V_76 -> V_78 . V_79 ; ++ V_5 ) {
V_76 -> V_80 [ V_5 ] . V_81 = 0 >> V_82 ;
V_76 -> V_80 [ V_5 ] . V_83 = ( 256 * 1024 * 1024 ) >> V_82 ;
}
if ( V_77 == V_60 )
return;
if ( V_76 -> V_78 . V_79 > 1 )
return;
V_76 -> V_80 [ 1 ] = V_76 -> V_80 [ 0 ] ;
V_76 -> V_80 [ 1 ] . V_81 += ( 256 * 1024 * 1024 ) >> V_82 ;
V_76 -> V_80 [ 1 ] . V_83 += ( 256 * 1024 * 1024 ) >> V_82 ;
V_76 -> V_78 . V_79 ++ ;
V_76 -> V_78 . V_84 ++ ;
}
void F_28 ( struct V_1 * V_2 , struct V_85 * V_66 )
{
int V_5 , V_6 ;
for ( V_5 = 0 ; V_5 < V_64 ; ++ V_5 ) {
T_1 V_70 = F_19 ( & V_2 -> V_7 . V_65 [ V_5 ] ) ;
if ( V_70 != 0 && V_2 -> V_7 . V_66 [ V_5 ] == V_66 ) {
struct V_71 * V_72 ;
F_20 ( V_2 ) ;
V_6 = F_21 ( V_2 ,
V_69 , V_70 , & V_72 ) ;
if ( V_6 ) {
F_22 ( L_6 , V_6 ) ;
continue;
}
F_23 ( V_72 , false ) ;
F_24 ( & V_72 ) ;
V_2 -> V_7 . V_66 [ V_5 ] = NULL ;
F_12 ( & V_2 -> V_7 . V_65 [ V_5 ] , 0 ) ;
}
}
}
static int F_29 ( T_1 * V_86 , unsigned V_87 [] )
{
unsigned V_88 = V_86 [ 4 ] ;
unsigned V_89 = V_86 [ 6 ] ;
unsigned V_90 = V_86 [ 7 ] ;
unsigned V_91 = V_86 [ 9 ] ;
unsigned V_92 = V_86 [ 28 ] ;
unsigned V_93 = V_89 / 16 ;
unsigned V_94 = F_30 ( V_90 / 16 , 2 ) ;
unsigned V_95 , V_96 , V_97 ;
V_95 = V_89 * V_90 ;
V_95 += V_95 / 2 ;
V_95 = F_30 ( V_95 , 1024 ) ;
switch ( V_88 ) {
case 0 :
V_97 = V_95 * 17 ;
V_97 += V_93 * V_94 * 17 * 192 ;
V_97 += V_93 * V_94 * 32 ;
break;
case 1 :
V_97 = V_95 * 3 ;
V_97 += V_93 * V_94 * 128 ;
V_97 += V_93 * 64 ;
V_97 += V_93 * 128 ;
V_96 = F_31 ( V_93 , V_94 ) ;
V_97 += F_30 ( V_96 * 7 * 16 , 64 ) ;
break;
case 3 :
V_97 = V_95 * 3 ;
break;
case 4 :
V_97 = V_95 * 3 ;
V_97 += V_93 * V_94 * 64 ;
V_97 += F_30 ( V_93 * V_94 * 32 , 64 ) ;
break;
default:
F_22 ( L_7 , V_88 ) ;
return - V_52 ;
}
if ( V_89 > V_92 ) {
F_22 ( L_8 ) ;
return - V_52 ;
}
if ( V_91 < V_97 ) {
F_22 ( L_9 ,
V_91 , V_97 ) ;
return - V_52 ;
}
V_87 [ 0x1 ] = V_91 ;
V_87 [ 0x2 ] = V_95 ;
return 0 ;
}
static int F_32 ( struct V_98 * V_99 ,
unsigned V_88 )
{
switch ( V_88 ) {
case 0 :
case 1 :
return 0 ;
case 3 :
case 4 :
if ( V_99 -> V_2 -> V_10 >= V_34 )
return 0 ;
default:
F_22 ( L_10 ,
V_88 ) ;
return - V_52 ;
}
}
static int F_33 ( struct V_98 * V_99 , struct V_75 * V_100 ,
unsigned V_101 , unsigned V_87 [] )
{
T_2 * V_86 , V_102 , V_70 ;
unsigned V_67 = 0 ;
struct V_72 * V_103 ;
void * V_73 ;
int V_5 , V_6 ;
if ( V_101 & 0x3F ) {
F_22 ( L_11 ) ;
return - V_52 ;
}
V_103 = F_34 ( V_100 -> V_104 . V_105 ) ;
if ( V_103 ) {
V_6 = F_23 ( (struct V_71 * ) V_103 , false ) ;
if ( V_6 ) {
F_22 ( L_12 , V_6 ) ;
return V_6 ;
}
}
V_6 = F_11 ( V_100 , & V_73 ) ;
if ( V_6 ) {
F_22 ( L_13 , V_6 ) ;
return V_6 ;
}
V_86 = V_73 + V_101 ;
V_102 = V_86 [ 1 ] ;
V_70 = V_86 [ 2 ] ;
if ( V_70 == 0 ) {
F_22 ( L_14 ) ;
return - V_52 ;
}
switch ( V_102 ) {
case 0 :
V_67 = V_86 [ 7 ] * V_86 [ 8 ] ;
V_6 = F_32 ( V_99 , V_86 [ 4 ] ) ;
F_14 ( V_100 ) ;
if ( V_6 )
return V_6 ;
for ( V_5 = 0 ; V_5 < V_64 ; ++ V_5 ) {
if ( F_19 ( & V_99 -> V_2 -> V_7 . V_65 [ V_5 ] ) == V_70 ) {
F_22 ( L_15 , V_70 ) ;
return - V_52 ;
}
if ( ! F_35 ( & V_99 -> V_2 -> V_7 . V_65 [ V_5 ] , 0 , V_70 ) ) {
V_99 -> V_2 -> V_7 . V_66 [ V_5 ] = V_99 -> V_66 ;
V_99 -> V_2 -> V_7 . V_67 [ V_5 ] = V_67 ;
return 0 ;
}
}
F_22 ( L_16 ) ;
return - V_52 ;
case 1 :
V_6 = F_32 ( V_99 , V_86 [ 4 ] ) ;
if ( ! V_6 )
V_6 = F_29 ( V_86 , V_87 ) ;
F_14 ( V_100 ) ;
if ( V_6 )
return V_6 ;
for ( V_5 = 0 ; V_5 < V_64 ; ++ V_5 ) {
if ( F_19 ( & V_99 -> V_2 -> V_7 . V_65 [ V_5 ] ) == V_70 ) {
if ( V_99 -> V_2 -> V_7 . V_66 [ V_5 ] != V_99 -> V_66 ) {
F_22 ( L_17 ) ;
return - V_52 ;
}
return 0 ;
}
}
F_22 ( L_18 , V_70 ) ;
return - V_106 ;
case 2 :
for ( V_5 = 0 ; V_5 < V_64 ; ++ V_5 )
F_35 ( & V_99 -> V_2 -> V_7 . V_65 [ V_5 ] , V_70 , 0 ) ;
F_14 ( V_100 ) ;
return 0 ;
default:
F_22 ( L_19 , V_102 ) ;
return - V_52 ;
}
F_36 () ;
return - V_52 ;
}
static int F_37 ( struct V_98 * V_99 ,
int V_107 , int V_108 ,
unsigned V_87 [] , bool * V_109 )
{
struct V_110 * V_111 ;
struct V_112 * V_113 ;
unsigned V_114 , V_115 , V_101 ;
T_3 V_116 , V_117 ;
int V_6 ;
V_111 = V_99 -> V_118 ;
V_101 = F_38 ( V_99 , V_107 ) ;
V_114 = F_38 ( V_99 , V_108 ) ;
if ( V_114 >= V_111 -> V_119 ) {
F_22 ( L_20 ,
V_114 , V_111 -> V_119 ) ;
return - V_52 ;
}
V_113 = & V_99 -> V_120 [ ( V_114 / 4 ) ] ;
V_116 = V_113 -> V_121 ;
V_117 = V_116 + F_26 ( V_113 -> V_122 ) ;
V_116 += V_101 ;
V_99 -> V_123 . V_73 [ V_107 ] = V_116 & 0xFFFFFFFF ;
V_99 -> V_123 . V_73 [ V_108 ] = V_116 >> 32 ;
V_115 = F_38 ( V_99 , V_99 -> V_114 ) >> 1 ;
if ( V_115 < 0x4 ) {
if ( V_117 <= V_116 ) {
F_22 ( L_21 , V_101 ) ;
return - V_52 ;
}
if ( ( V_117 - V_116 ) < V_87 [ V_115 ] ) {
F_22 ( L_22 , V_115 ,
( unsigned ) ( V_117 - V_116 ) , V_87 [ V_115 ] ) ;
return - V_52 ;
}
} else if ( V_115 != 0x100 ) {
F_22 ( L_23 , V_115 ) ;
return - V_52 ;
}
if ( ( V_116 >> 28 ) != ( ( V_117 - 1 ) >> 28 ) ) {
F_22 ( L_24 ,
V_116 , V_117 ) ;
return - V_52 ;
}
if ( ( V_115 == 0 || V_115 == 0x3 ) &&
( V_116 >> 28 ) != ( V_99 -> V_2 -> V_7 . V_62 >> 28 ) ) {
F_22 ( L_25 ,
V_116 , V_117 ) ;
return - V_52 ;
}
if ( V_115 == 0 ) {
if ( * V_109 ) {
F_22 ( L_26 ) ;
return - V_52 ;
}
* V_109 = true ;
V_6 = F_33 ( V_99 , V_113 -> V_122 , V_101 , V_87 ) ;
if ( V_6 )
return V_6 ;
} else if ( ! * V_109 ) {
F_22 ( L_27 ) ;
return - V_52 ;
}
return 0 ;
}
static int F_39 ( struct V_98 * V_99 ,
struct V_124 * V_125 ,
int * V_107 , int * V_108 ,
unsigned V_87 [] ,
bool * V_109 )
{
int V_5 , V_6 ;
V_99 -> V_114 ++ ;
for ( V_5 = 0 ; V_5 <= V_125 -> V_126 ; ++ V_5 ) {
switch ( V_125 -> V_127 + V_5 * 4 ) {
case V_128 :
* V_107 = V_99 -> V_114 ;
break;
case V_129 :
* V_108 = V_99 -> V_114 ;
break;
case V_130 :
V_6 = F_37 ( V_99 , * V_107 , * V_108 ,
V_87 , V_109 ) ;
if ( V_6 )
return V_6 ;
break;
case V_131 :
break;
default:
F_22 ( L_28 ,
V_125 -> V_127 + V_5 * 4 ) ;
return - V_52 ;
}
V_99 -> V_114 ++ ;
}
return 0 ;
}
int F_40 ( struct V_98 * V_99 )
{
struct V_124 V_125 ;
int V_6 , V_107 = 0 , V_108 = 0 ;
bool V_109 = false ;
unsigned V_87 [] = {
[ 0x00000000 ] = 2048 ,
[ 0x00000001 ] = 32 * 1024 * 1024 ,
[ 0x00000002 ] = 2048 * 1152 * 3 ,
[ 0x00000003 ] = 2048 ,
} ;
if ( V_99 -> V_132 -> V_119 % 16 ) {
F_22 ( L_29 ,
V_99 -> V_132 -> V_119 ) ;
return - V_52 ;
}
if ( V_99 -> V_118 == NULL ) {
F_22 ( L_30 ) ;
return - V_52 ;
}
do {
V_6 = F_41 ( V_99 , & V_125 , V_99 -> V_114 ) ;
if ( V_6 )
return V_6 ;
switch ( V_125 . type ) {
case V_133 :
V_6 = F_39 ( V_99 , & V_125 , & V_107 , & V_108 ,
V_87 , & V_109 ) ;
if ( V_6 )
return V_6 ;
break;
case V_134 :
V_99 -> V_114 += V_125 . V_126 + 2 ;
break;
default:
F_22 ( L_31 , V_125 . type ) ;
return - V_52 ;
}
} while ( V_99 -> V_114 < V_99 -> V_132 -> V_119 );
if ( ! V_109 ) {
F_22 ( L_32 ) ;
return - V_52 ;
}
return 0 ;
}
static int F_42 ( struct V_1 * V_2 ,
int V_68 , T_3 V_135 ,
struct V_71 * * V_72 )
{
struct V_136 V_123 ;
int V_5 , V_6 ;
V_6 = F_43 ( V_2 , V_68 , & V_123 , NULL , 64 ) ;
if ( V_6 )
return V_6 ;
V_123 . V_73 [ 0 ] = F_44 ( V_128 , 0 ) ;
V_123 . V_73 [ 1 ] = V_135 ;
V_123 . V_73 [ 2 ] = F_44 ( V_129 , 0 ) ;
V_123 . V_73 [ 3 ] = V_135 >> 32 ;
V_123 . V_73 [ 4 ] = F_44 ( V_130 , 0 ) ;
V_123 . V_73 [ 5 ] = 0 ;
for ( V_5 = 6 ; V_5 < 16 ; ++ V_5 )
V_123 . V_73 [ V_5 ] = F_45 ( 0 ) ;
V_123 . V_119 = 16 ;
V_6 = F_46 ( V_2 , & V_123 , NULL , false ) ;
if ( V_72 )
* V_72 = F_47 ( V_123 . V_72 ) ;
F_48 ( V_2 , & V_123 ) ;
return V_6 ;
}
int F_49 ( struct V_1 * V_2 , int V_68 ,
T_1 V_70 , struct V_71 * * V_72 )
{
T_3 V_137 = F_26 ( V_2 -> V_7 . V_61 ) -
V_58 ;
T_1 * V_86 = V_2 -> V_7 . V_63 + V_137 ;
T_3 V_135 = V_2 -> V_7 . V_62 + V_137 ;
int V_6 , V_5 ;
V_6 = F_7 ( V_2 -> V_7 . V_61 , true ) ;
if ( V_6 )
return V_6 ;
V_86 [ 0 ] = F_50 ( 0x00000de4 ) ;
V_86 [ 1 ] = F_50 ( 0x00000000 ) ;
V_86 [ 2 ] = F_50 ( V_70 ) ;
V_86 [ 3 ] = F_50 ( 0x00000000 ) ;
V_86 [ 4 ] = F_50 ( 0x00000000 ) ;
V_86 [ 5 ] = F_50 ( 0x00000000 ) ;
V_86 [ 6 ] = F_50 ( 0x00000000 ) ;
V_86 [ 7 ] = F_50 ( 0x00000780 ) ;
V_86 [ 8 ] = F_50 ( 0x00000440 ) ;
V_86 [ 9 ] = F_50 ( 0x00000000 ) ;
V_86 [ 10 ] = F_50 ( 0x01b37000 ) ;
for ( V_5 = 11 ; V_5 < 1024 ; ++ V_5 )
V_86 [ V_5 ] = F_50 ( 0x0 ) ;
V_6 = F_42 ( V_2 , V_68 , V_135 , V_72 ) ;
F_10 ( V_2 -> V_7 . V_61 ) ;
return V_6 ;
}
int F_21 ( struct V_1 * V_2 , int V_68 ,
T_1 V_70 , struct V_71 * * V_72 )
{
T_3 V_137 = F_26 ( V_2 -> V_7 . V_61 ) -
V_58 ;
T_1 * V_86 = V_2 -> V_7 . V_63 + V_137 ;
T_3 V_135 = V_2 -> V_7 . V_62 + V_137 ;
int V_6 , V_5 ;
V_6 = F_7 ( V_2 -> V_7 . V_61 , true ) ;
if ( V_6 )
return V_6 ;
V_86 [ 0 ] = F_50 ( 0x00000de4 ) ;
V_86 [ 1 ] = F_50 ( 0x00000002 ) ;
V_86 [ 2 ] = F_50 ( V_70 ) ;
V_86 [ 3 ] = F_50 ( 0x00000000 ) ;
for ( V_5 = 4 ; V_5 < 1024 ; ++ V_5 )
V_86 [ V_5 ] = F_50 ( 0x0 ) ;
V_6 = F_42 ( V_2 , V_68 , V_135 , V_72 ) ;
F_10 ( V_2 -> V_7 . V_61 ) ;
return V_6 ;
}
static void F_51 ( struct V_1 * V_2 ,
unsigned * V_138 , unsigned * V_139 )
{
unsigned V_5 ;
* V_138 = 0 ;
* V_139 = 0 ;
for ( V_5 = 0 ; V_5 < V_64 ; ++ V_5 ) {
if ( ! F_19 ( & V_2 -> V_7 . V_65 [ V_5 ] ) )
continue;
if ( V_2 -> V_7 . V_67 [ V_5 ] >= 720 * 576 )
++ ( * V_139 ) ;
else
++ ( * V_138 ) ;
}
}
static void V_9 ( struct V_140 * V_141 )
{
struct V_1 * V_2 =
F_52 ( V_141 , struct V_1 , V_7 . V_8 . V_141 ) ;
if ( F_53 ( V_2 , V_69 ) == 0 ) {
if ( ( V_2 -> V_142 . V_143 == V_144 ) && V_2 -> V_142 . V_145 ) {
F_51 ( V_2 , & V_2 -> V_142 . V_146 . V_138 ,
& V_2 -> V_142 . V_146 . V_139 ) ;
F_54 ( V_2 , false ) ;
} else {
F_55 ( V_2 , 0 , 0 ) ;
}
} else {
F_56 ( & V_2 -> V_7 . V_8 ,
F_57 ( V_147 ) ) ;
}
}
void F_20 ( struct V_1 * V_2 )
{
bool V_148 = false ;
bool V_149 = ! F_58 ( & V_2 -> V_7 . V_8 ) ;
V_149 &= F_56 ( & V_2 -> V_7 . V_8 ,
F_57 ( V_147 ) ) ;
if ( ( V_2 -> V_142 . V_143 == V_144 ) && V_2 -> V_142 . V_145 ) {
unsigned V_139 = 0 , V_138 = 0 ;
F_51 ( V_2 , & V_138 , & V_139 ) ;
if ( ( V_2 -> V_142 . V_146 . V_138 != V_138 ) ||
( V_2 -> V_142 . V_146 . V_139 != V_139 ) ) {
V_2 -> V_142 . V_146 . V_138 = V_138 ;
V_2 -> V_142 . V_146 . V_139 = V_139 ;
}
}
if ( V_149 || V_148 ) {
if ( ( V_2 -> V_142 . V_143 == V_144 ) && V_2 -> V_142 . V_145 ) {
F_54 ( V_2 , true ) ;
} else {
F_55 ( V_2 , 53300 , 40000 ) ;
}
}
}
static unsigned F_59 ( unsigned V_150 ,
unsigned V_151 ,
unsigned V_152 ,
unsigned V_153 )
{
unsigned V_154 = V_150 / V_151 ;
if ( V_154 < V_152 )
V_154 = V_152 ;
if ( ( V_150 / V_154 ) > V_151 )
V_154 += 1 ;
if ( V_154 > V_153 && V_154 % 2 )
V_154 += 1 ;
return V_154 ;
}
int F_60 ( struct V_1 * V_2 ,
unsigned V_155 , unsigned V_156 ,
unsigned V_157 , unsigned V_158 ,
unsigned V_159 , unsigned V_160 ,
unsigned V_152 , unsigned V_161 ,
unsigned V_153 ,
unsigned * V_162 ,
unsigned * V_163 ,
unsigned * V_164 )
{
unsigned V_150 , V_165 = V_2 -> clock . V_166 . V_167 ;
unsigned V_168 = ~ 0 ;
V_157 = F_31 ( F_31 ( V_157 , V_155 ) , V_156 ) ;
for ( V_150 = V_157 ; V_150 <= V_158 ; V_150 += 100 ) {
T_3 V_169 = ( T_3 ) V_150 * V_159 ;
unsigned V_170 , V_171 , V_172 ;
F_61 ( V_169 , V_165 ) ;
if ( V_169 > V_160 )
break;
V_169 &= V_160 ;
V_170 = F_59 ( V_150 , V_155 ,
V_152 , V_153 ) ;
if ( V_170 > V_161 )
break;
V_171 = F_59 ( V_150 , V_156 ,
V_152 , V_153 ) ;
if ( V_170 > V_161 )
break;
V_172 = V_155 - ( V_150 / V_170 ) + V_156 - ( V_150 / V_171 ) ;
if ( V_172 < V_168 ) {
* V_162 = V_169 ;
* V_163 = V_170 ;
* V_164 = V_171 ;
V_168 = V_172 ;
if ( V_168 == 0 )
break;
}
}
if ( V_168 == ~ 0 )
return - V_52 ;
return 0 ;
}
int F_62 ( struct V_1 * V_2 ,
unsigned V_173 )
{
unsigned V_5 ;
F_63 ( V_173 , 0 , ~ V_174 ) ;
F_64 ( 10 ) ;
F_63 ( V_173 , V_174 , ~ V_174 ) ;
for ( V_5 = 0 ; V_5 < 100 ; ++ V_5 ) {
T_1 V_175 = V_176 | V_177 ;
if ( ( F_65 ( V_173 ) & V_175 ) == V_175 )
break;
F_64 ( 10 ) ;
}
F_63 ( V_173 , 0 , ~ V_174 ) ;
if ( V_5 == 100 ) {
F_22 ( L_33 ) ;
return - V_178 ;
}
return 0 ;
}
