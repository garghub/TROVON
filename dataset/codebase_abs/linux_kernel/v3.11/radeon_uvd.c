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
V_4 = V_14 ;
break;
case V_15 :
case V_16 :
case V_17 :
case V_18 :
case V_19 :
V_4 = V_20 ;
break;
case V_21 :
case V_22 :
case V_23 :
case V_24 :
case V_25 :
case V_26 :
case V_27 :
V_4 = V_28 ;
break;
case V_29 :
case V_30 :
case V_31 :
case V_32 :
V_4 = V_33 ;
break;
case V_34 :
case V_35 :
case V_36 :
V_4 = V_37 ;
break;
default:
return - V_38 ;
}
V_6 = F_3 ( & V_2 -> V_39 , V_4 , V_2 -> V_40 ) ;
if ( V_6 ) {
F_4 ( V_2 -> V_40 , L_1 ,
V_4 ) ;
return V_6 ;
}
V_3 = F_5 ( V_2 -> V_39 -> V_41 + 8 ) +
V_42 + V_43 ;
V_6 = F_6 ( V_2 , V_3 , V_44 , true ,
V_45 , NULL , & V_2 -> V_7 . V_46 ) ;
if ( V_6 ) {
F_4 ( V_2 -> V_40 , L_2 , V_6 ) ;
return V_6 ;
}
V_6 = F_7 ( V_2 -> V_7 . V_46 , false ) ;
if ( V_6 ) {
F_8 ( & V_2 -> V_7 . V_46 ) ;
F_4 ( V_2 -> V_40 , L_3 , V_6 ) ;
return V_6 ;
}
V_6 = F_9 ( V_2 -> V_7 . V_46 , V_45 ,
& V_2 -> V_7 . V_47 ) ;
if ( V_6 ) {
F_10 ( V_2 -> V_7 . V_46 ) ;
F_8 ( & V_2 -> V_7 . V_46 ) ;
F_4 ( V_2 -> V_40 , L_4 , V_6 ) ;
return V_6 ;
}
V_6 = F_11 ( V_2 -> V_7 . V_46 , & V_2 -> V_7 . V_48 ) ;
if ( V_6 ) {
F_4 ( V_2 -> V_40 , L_5 , V_6 ) ;
return V_6 ;
}
F_10 ( V_2 -> V_7 . V_46 ) ;
for ( V_5 = 0 ; V_5 < V_49 ; ++ V_5 ) {
F_12 ( & V_2 -> V_7 . V_50 [ V_5 ] , 0 ) ;
V_2 -> V_7 . V_51 [ V_5 ] = NULL ;
}
return 0 ;
}
void F_13 ( struct V_1 * V_2 )
{
int V_6 ;
if ( V_2 -> V_7 . V_46 == NULL )
return;
V_6 = F_7 ( V_2 -> V_7 . V_46 , false ) ;
if ( ! V_6 ) {
F_14 ( V_2 -> V_7 . V_46 ) ;
F_15 ( V_2 -> V_7 . V_46 ) ;
F_10 ( V_2 -> V_7 . V_46 ) ;
}
F_8 ( & V_2 -> V_7 . V_46 ) ;
F_16 ( V_2 -> V_39 ) ;
}
int F_17 ( struct V_1 * V_2 )
{
unsigned V_41 ;
void * V_52 ;
int V_5 ;
if ( V_2 -> V_7 . V_46 == NULL )
return 0 ;
for ( V_5 = 0 ; V_5 < V_49 ; ++ V_5 )
if ( F_18 ( & V_2 -> V_7 . V_50 [ V_5 ] ) )
break;
if ( V_5 == V_49 )
return 0 ;
V_41 = F_19 ( V_2 -> V_7 . V_46 ) ;
V_41 -= V_2 -> V_39 -> V_41 ;
V_52 = V_2 -> V_7 . V_48 ;
V_52 += V_2 -> V_39 -> V_41 ;
V_2 -> V_7 . V_53 = F_20 ( V_41 , V_54 ) ;
memcpy ( V_2 -> V_7 . V_53 , V_52 , V_41 ) ;
return 0 ;
}
int F_21 ( struct V_1 * V_2 )
{
unsigned V_41 ;
void * V_52 ;
if ( V_2 -> V_7 . V_46 == NULL )
return - V_38 ;
memcpy ( V_2 -> V_7 . V_48 , V_2 -> V_39 -> V_55 , V_2 -> V_39 -> V_41 ) ;
V_41 = F_19 ( V_2 -> V_7 . V_46 ) ;
V_41 -= V_2 -> V_39 -> V_41 ;
V_52 = V_2 -> V_7 . V_48 ;
V_52 += V_2 -> V_39 -> V_41 ;
if ( V_2 -> V_7 . V_53 != NULL ) {
memcpy ( V_52 , V_2 -> V_7 . V_53 , V_41 ) ;
F_22 ( V_2 -> V_7 . V_53 ) ;
V_2 -> V_7 . V_53 = NULL ;
} else
memset ( V_52 , 0 , V_41 ) ;
return 0 ;
}
void F_23 ( struct V_56 * V_57 )
{
V_57 -> V_58 . V_59 = 0 >> V_60 ;
V_57 -> V_58 . V_61 = ( 256 * 1024 * 1024 ) >> V_60 ;
}
void F_24 ( struct V_1 * V_2 , struct V_62 * V_51 )
{
int V_5 , V_6 ;
for ( V_5 = 0 ; V_5 < V_49 ; ++ V_5 ) {
T_1 V_63 = F_18 ( & V_2 -> V_7 . V_50 [ V_5 ] ) ;
if ( V_63 != 0 && V_2 -> V_7 . V_51 [ V_5 ] == V_51 ) {
struct V_64 * V_65 ;
V_6 = F_25 ( V_2 ,
V_66 , V_63 , & V_65 ) ;
if ( V_6 ) {
F_26 ( L_6 , V_6 ) ;
continue;
}
F_27 ( V_65 , false ) ;
F_28 ( & V_65 ) ;
V_2 -> V_7 . V_51 [ V_5 ] = NULL ;
F_12 ( & V_2 -> V_7 . V_50 [ V_5 ] , 0 ) ;
}
}
}
static int F_29 ( T_1 * V_67 , unsigned V_68 [] )
{
unsigned V_69 = V_67 [ 4 ] ;
unsigned V_70 = V_67 [ 6 ] ;
unsigned V_71 = V_67 [ 7 ] ;
unsigned V_72 = V_67 [ 9 ] ;
unsigned V_73 = V_67 [ 28 ] ;
unsigned V_74 = V_70 / 16 ;
unsigned V_75 = F_30 ( V_71 / 16 , 2 ) ;
unsigned V_76 , V_77 , V_78 ;
V_76 = V_70 * V_71 ;
V_76 += V_76 / 2 ;
V_76 = F_30 ( V_76 , 1024 ) ;
switch ( V_69 ) {
case 0 :
V_78 = V_76 * 17 ;
V_78 += V_74 * V_75 * 17 * 192 ;
V_78 += V_74 * V_75 * 32 ;
break;
case 1 :
V_78 = V_76 * 3 ;
V_78 += V_74 * V_75 * 128 ;
V_78 += V_74 * 64 ;
V_78 += V_74 * 128 ;
V_77 = F_31 ( V_74 , V_75 ) ;
V_78 += F_30 ( V_77 * 7 * 16 , 64 ) ;
break;
case 3 :
V_78 = V_76 * 3 ;
break;
case 4 :
V_78 = V_76 * 3 ;
V_78 += V_74 * V_75 * 64 ;
V_78 += F_30 ( V_74 * V_75 * 32 , 64 ) ;
break;
default:
F_26 ( L_7 , V_69 ) ;
return - V_38 ;
}
if ( V_70 > V_73 ) {
F_26 ( L_8 ) ;
return - V_38 ;
}
if ( V_72 < V_78 ) {
F_26 ( L_9 ,
V_72 , V_78 ) ;
return - V_38 ;
}
V_68 [ 0x1 ] = V_72 ;
V_68 [ 0x2 ] = V_76 ;
return 0 ;
}
static int F_32 ( struct V_79 * V_80 , struct V_56 * V_81 ,
unsigned V_82 , unsigned V_68 [] )
{
T_2 * V_67 , V_83 , V_63 ;
void * V_52 ;
int V_5 , V_6 ;
if ( V_82 & 0x3F ) {
F_26 ( L_10 ) ;
return - V_38 ;
}
if ( V_81 -> V_84 . V_85 ) {
V_6 = F_27 ( V_81 -> V_84 . V_85 , false ) ;
if ( V_6 ) {
F_26 ( L_11 , V_6 ) ;
return V_6 ;
}
}
V_6 = F_11 ( V_81 , & V_52 ) ;
if ( V_6 ) {
F_26 ( L_12 , V_6 ) ;
return V_6 ;
}
V_67 = V_52 + V_82 ;
V_83 = V_67 [ 1 ] ;
V_63 = V_67 [ 2 ] ;
if ( V_63 == 0 ) {
F_26 ( L_13 ) ;
return - V_38 ;
}
if ( V_83 == 1 ) {
V_6 = F_29 ( V_67 , V_68 ) ;
F_14 ( V_81 ) ;
if ( V_6 )
return V_6 ;
} else if ( V_83 == 2 ) {
for ( V_5 = 0 ; V_5 < V_49 ; ++ V_5 )
F_33 ( & V_80 -> V_2 -> V_7 . V_50 [ V_5 ] , V_63 , 0 ) ;
F_14 ( V_81 ) ;
return 0 ;
} else {
F_14 ( V_81 ) ;
if ( V_83 != 0 ) {
F_26 ( L_14 , V_83 ) ;
return - V_38 ;
}
}
for ( V_5 = 0 ; V_5 < V_49 ; ++ V_5 ) {
if ( F_18 ( & V_80 -> V_2 -> V_7 . V_50 [ V_5 ] ) == V_63 )
return 0 ;
}
for ( V_5 = 0 ; V_5 < V_49 ; ++ V_5 ) {
if ( ! F_33 ( & V_80 -> V_2 -> V_7 . V_50 [ V_5 ] , 0 , V_63 ) ) {
V_80 -> V_2 -> V_7 . V_51 [ V_5 ] = V_80 -> V_51 ;
return 0 ;
}
}
F_26 ( L_15 ) ;
return - V_38 ;
}
static int F_34 ( struct V_79 * V_80 ,
int V_86 , int V_87 ,
unsigned V_68 [] , bool * V_88 )
{
struct V_89 * V_90 ;
struct V_91 * V_92 ;
unsigned V_93 , V_94 , V_82 ;
T_3 V_95 , V_96 ;
int V_6 ;
V_90 = & V_80 -> V_97 [ V_80 -> V_98 ] ;
V_82 = F_35 ( V_80 , V_86 ) ;
V_93 = F_35 ( V_80 , V_87 ) ;
if ( V_93 >= V_90 -> V_99 ) {
F_26 ( L_16 ,
V_93 , V_90 -> V_99 ) ;
return - V_38 ;
}
V_92 = V_80 -> V_100 [ ( V_93 / 4 ) ] ;
V_95 = V_92 -> V_101 . V_102 ;
V_96 = V_95 + F_19 ( V_92 -> V_103 ) ;
V_95 += V_82 ;
V_80 -> V_104 . V_52 [ V_86 ] = V_95 & 0xFFFFFFFF ;
V_80 -> V_104 . V_52 [ V_87 ] = V_95 >> 32 ;
V_94 = F_35 ( V_80 , V_80 -> V_93 ) >> 1 ;
if ( V_94 < 0x4 ) {
if ( ( V_96 - V_95 ) < V_68 [ V_94 ] ) {
F_26 ( L_17 , V_94 ,
( unsigned ) ( V_96 - V_95 ) , V_68 [ V_94 ] ) ;
return - V_38 ;
}
} else if ( V_94 != 0x100 ) {
F_26 ( L_18 , V_94 ) ;
return - V_38 ;
}
if ( ( V_95 >> 28 ) != ( V_96 >> 28 ) ) {
F_26 ( L_19 ,
V_95 , V_96 ) ;
return - V_38 ;
}
if ( ( V_94 == 0 || V_94 == 0x3 ) &&
( V_95 >> 28 ) != ( V_80 -> V_2 -> V_7 . V_47 >> 28 ) ) {
F_26 ( L_20 ,
V_95 , V_96 ) ;
return - V_38 ;
}
if ( V_94 == 0 ) {
if ( * V_88 ) {
F_26 ( L_21 ) ;
return - V_38 ;
}
* V_88 = true ;
V_6 = F_32 ( V_80 , V_92 -> V_103 , V_82 , V_68 ) ;
if ( V_6 )
return V_6 ;
} else if ( ! * V_88 ) {
F_26 ( L_22 ) ;
return - V_38 ;
}
return 0 ;
}
static int F_36 ( struct V_79 * V_80 ,
struct V_105 * V_106 ,
int * V_86 , int * V_87 ,
unsigned V_68 [] ,
bool * V_88 )
{
int V_5 , V_6 ;
V_80 -> V_93 ++ ;
for ( V_5 = 0 ; V_5 <= V_106 -> V_107 ; ++ V_5 ) {
switch ( V_106 -> V_108 + V_5 * 4 ) {
case V_109 :
* V_86 = V_80 -> V_93 ;
break;
case V_110 :
* V_87 = V_80 -> V_93 ;
break;
case V_111 :
V_6 = F_34 ( V_80 , * V_86 , * V_87 ,
V_68 , V_88 ) ;
if ( V_6 )
return V_6 ;
break;
case V_112 :
break;
default:
F_26 ( L_23 ,
V_106 -> V_108 + V_5 * 4 ) ;
return - V_38 ;
}
V_80 -> V_93 ++ ;
}
return 0 ;
}
int F_37 ( struct V_79 * V_80 )
{
struct V_105 V_106 ;
int V_6 , V_86 = 0 , V_87 = 0 ;
bool V_88 = false ;
unsigned V_68 [] = {
[ 0x00000000 ] = 2048 ,
[ 0x00000001 ] = 32 * 1024 * 1024 ,
[ 0x00000002 ] = 2048 * 1152 * 3 ,
[ 0x00000003 ] = 2048 ,
} ;
if ( V_80 -> V_97 [ V_80 -> V_113 ] . V_99 % 16 ) {
F_26 ( L_24 ,
V_80 -> V_97 [ V_80 -> V_113 ] . V_99 ) ;
return - V_38 ;
}
if ( V_80 -> V_98 == - 1 ) {
F_26 ( L_25 ) ;
return - V_38 ;
}
do {
V_6 = F_38 ( V_80 , & V_106 , V_80 -> V_93 ) ;
if ( V_6 )
return V_6 ;
switch ( V_106 . type ) {
case V_114 :
V_6 = F_36 ( V_80 , & V_106 , & V_86 , & V_87 ,
V_68 , & V_88 ) ;
if ( V_6 )
return V_6 ;
break;
case V_115 :
V_80 -> V_93 += V_106 . V_107 + 2 ;
break;
default:
F_26 ( L_26 , V_106 . type ) ;
return - V_38 ;
}
} while ( V_80 -> V_93 < V_80 -> V_97 [ V_80 -> V_113 ] . V_99 );
if ( ! V_88 ) {
F_26 ( L_27 ) ;
return - V_38 ;
}
return 0 ;
}
static int F_39 ( struct V_1 * V_2 ,
int V_116 , struct V_56 * V_81 ,
struct V_64 * * V_65 )
{
struct V_117 V_118 ;
struct V_119 V_120 ;
struct V_121 V_122 ;
struct V_123 V_104 ;
T_3 V_124 ;
int V_5 , V_6 ;
memset ( & V_118 , 0 , sizeof( V_118 ) ) ;
V_118 . V_81 = & V_81 -> V_84 ;
F_40 ( & V_122 ) ;
F_41 ( & V_118 . V_122 , & V_122 ) ;
V_6 = F_42 ( & V_120 , & V_122 ) ;
if ( V_6 )
return V_6 ;
F_43 ( V_81 , V_45 ) ;
F_23 ( V_81 ) ;
V_6 = F_44 ( & V_81 -> V_84 , & V_81 -> V_58 , true , false ) ;
if ( V_6 )
goto V_125;
V_6 = F_45 ( V_2 , V_116 , & V_104 , NULL , 16 ) ;
if ( V_6 )
goto V_125;
V_124 = F_46 ( V_81 ) ;
V_104 . V_52 [ 0 ] = F_47 ( V_109 , 0 ) ;
V_104 . V_52 [ 1 ] = V_124 ;
V_104 . V_52 [ 2 ] = F_47 ( V_110 , 0 ) ;
V_104 . V_52 [ 3 ] = V_124 >> 32 ;
V_104 . V_52 [ 4 ] = F_47 ( V_111 , 0 ) ;
V_104 . V_52 [ 5 ] = 0 ;
for ( V_5 = 6 ; V_5 < 16 ; ++ V_5 )
V_104 . V_52 [ V_5 ] = F_48 ( 0 ) ;
V_104 . V_99 = 16 ;
V_6 = F_49 ( V_2 , & V_104 , NULL ) ;
if ( V_6 )
goto V_125;
F_50 ( & V_120 , & V_122 , V_104 . V_65 ) ;
if ( V_65 )
* V_65 = F_51 ( V_104 . V_65 ) ;
F_52 ( V_2 , & V_104 ) ;
F_8 ( & V_81 ) ;
return 0 ;
V_125:
F_53 ( & V_120 , & V_122 ) ;
return V_6 ;
}
int F_54 ( struct V_1 * V_2 , int V_116 ,
T_1 V_63 , struct V_64 * * V_65 )
{
struct V_56 * V_81 ;
T_1 * V_67 ;
int V_6 , V_5 ;
V_6 = F_6 ( V_2 , 1024 , V_44 , true ,
V_45 , NULL , & V_81 ) ;
if ( V_6 )
return V_6 ;
V_6 = F_7 ( V_81 , false ) ;
if ( V_6 ) {
F_8 ( & V_81 ) ;
return V_6 ;
}
V_6 = F_11 ( V_81 , ( void * * ) & V_67 ) ;
if ( V_6 ) {
F_10 ( V_81 ) ;
F_8 ( & V_81 ) ;
return V_6 ;
}
V_67 [ 0 ] = F_55 ( 0x00000de4 ) ;
V_67 [ 1 ] = F_55 ( 0x00000000 ) ;
V_67 [ 2 ] = F_55 ( V_63 ) ;
V_67 [ 3 ] = F_55 ( 0x00000000 ) ;
V_67 [ 4 ] = F_55 ( 0x00000000 ) ;
V_67 [ 5 ] = F_55 ( 0x00000000 ) ;
V_67 [ 6 ] = F_55 ( 0x00000000 ) ;
V_67 [ 7 ] = F_55 ( 0x00000780 ) ;
V_67 [ 8 ] = F_55 ( 0x00000440 ) ;
V_67 [ 9 ] = F_55 ( 0x00000000 ) ;
V_67 [ 10 ] = F_55 ( 0x01b37000 ) ;
for ( V_5 = 11 ; V_5 < 1024 ; ++ V_5 )
V_67 [ V_5 ] = F_55 ( 0x0 ) ;
F_14 ( V_81 ) ;
F_10 ( V_81 ) ;
return F_39 ( V_2 , V_116 , V_81 , V_65 ) ;
}
int F_25 ( struct V_1 * V_2 , int V_116 ,
T_1 V_63 , struct V_64 * * V_65 )
{
struct V_56 * V_81 ;
T_1 * V_67 ;
int V_6 , V_5 ;
V_6 = F_6 ( V_2 , 1024 , V_44 , true ,
V_45 , NULL , & V_81 ) ;
if ( V_6 )
return V_6 ;
V_6 = F_7 ( V_81 , false ) ;
if ( V_6 ) {
F_8 ( & V_81 ) ;
return V_6 ;
}
V_6 = F_11 ( V_81 , ( void * * ) & V_67 ) ;
if ( V_6 ) {
F_10 ( V_81 ) ;
F_8 ( & V_81 ) ;
return V_6 ;
}
V_67 [ 0 ] = F_55 ( 0x00000de4 ) ;
V_67 [ 1 ] = F_55 ( 0x00000002 ) ;
V_67 [ 2 ] = F_55 ( V_63 ) ;
V_67 [ 3 ] = F_55 ( 0x00000000 ) ;
for ( V_5 = 4 ; V_5 < 1024 ; ++ V_5 )
V_67 [ V_5 ] = F_55 ( 0x0 ) ;
F_14 ( V_81 ) ;
F_10 ( V_81 ) ;
return F_39 ( V_2 , V_116 , V_81 , V_65 ) ;
}
static void V_9 ( struct V_126 * V_127 )
{
struct V_1 * V_2 =
F_56 ( V_127 , struct V_1 , V_7 . V_8 . V_127 ) ;
if ( F_57 ( V_2 , V_66 ) == 0 ) {
if ( ( V_2 -> V_128 . V_129 == V_130 ) && V_2 -> V_128 . V_131 ) {
F_58 ( & V_2 -> V_128 . V_132 ) ;
V_2 -> V_128 . V_133 . V_134 = false ;
F_59 ( & V_2 -> V_128 . V_132 ) ;
F_60 ( V_2 ) ;
} else {
F_61 ( V_2 , 0 , 0 ) ;
}
} else {
F_62 ( & V_2 -> V_7 . V_8 ,
F_63 ( V_135 ) ) ;
}
}
void F_64 ( struct V_1 * V_2 )
{
bool V_136 = ! F_65 ( & V_2 -> V_7 . V_8 ) ;
V_136 &= F_62 ( & V_2 -> V_7 . V_8 ,
F_63 ( V_135 ) ) ;
if ( V_136 ) {
if ( ( V_2 -> V_128 . V_129 == V_130 ) && V_2 -> V_128 . V_131 ) {
F_66 ( V_2 , V_137 ) ;
} else {
F_61 ( V_2 , 53300 , 40000 ) ;
}
}
}
static unsigned F_67 ( unsigned V_138 ,
unsigned V_139 ,
unsigned V_140 ,
unsigned V_141 )
{
unsigned V_142 = V_138 / V_139 ;
if ( V_142 < V_140 )
V_142 = V_140 ;
if ( ( V_138 / V_142 ) > V_139 )
V_142 += 1 ;
if ( V_142 > V_141 && V_142 % 2 )
V_142 += 1 ;
return V_142 ;
}
int F_68 ( struct V_1 * V_2 ,
unsigned V_143 , unsigned V_144 ,
unsigned V_145 , unsigned V_146 ,
unsigned V_147 , unsigned V_148 ,
unsigned V_140 , unsigned V_149 ,
unsigned V_141 ,
unsigned * V_150 ,
unsigned * V_151 ,
unsigned * V_152 )
{
unsigned V_138 , V_153 = V_2 -> clock . V_154 . V_155 ;
unsigned V_156 = ~ 0 ;
V_145 = F_31 ( F_31 ( V_145 , V_143 ) , V_144 ) ;
for ( V_138 = V_145 ; V_138 <= V_146 ; V_138 += 100 ) {
T_3 V_157 = ( T_3 ) V_138 * V_147 ;
unsigned V_158 , V_159 , V_160 ;
F_69 ( V_157 , V_153 ) ;
if ( V_157 > V_148 )
break;
V_157 &= V_148 ;
V_158 = F_67 ( V_138 , V_143 ,
V_140 , V_141 ) ;
if ( V_158 > V_149 )
break;
V_159 = F_67 ( V_138 , V_144 ,
V_140 , V_141 ) ;
if ( V_158 > V_149 )
break;
V_160 = V_143 - ( V_138 / V_158 ) + V_144 - ( V_138 / V_159 ) ;
if ( V_160 < V_156 ) {
* V_150 = V_157 ;
* V_151 = V_158 ;
* V_152 = V_159 ;
V_156 = V_160 ;
if ( V_156 == 0 )
break;
}
}
if ( V_156 == ~ 0 )
return - V_38 ;
return 0 ;
}
int F_70 ( struct V_1 * V_2 ,
unsigned V_161 )
{
unsigned V_5 ;
F_71 ( V_161 , 0 , ~ V_162 ) ;
F_72 ( 10 ) ;
F_71 ( V_161 , V_162 , ~ V_162 ) ;
for ( V_5 = 0 ; V_5 < 100 ; ++ V_5 ) {
T_1 V_163 = V_164 | V_165 ;
if ( ( F_73 ( V_161 ) & V_163 ) == V_163 )
break;
F_72 ( 10 ) ;
}
F_71 ( V_161 , 0 , ~ V_162 ) ;
if ( V_5 == 100 ) {
F_26 ( L_28 ) ;
return - V_166 ;
}
return 0 ;
}
