int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
unsigned long V_5 ;
const char * V_6 ;
int V_7 , V_8 ;
F_2 ( & V_2 -> V_9 . V_10 , V_11 ) ;
V_4 = F_3 ( L_1 , 0 , NULL , 0 ) ;
V_8 = F_4 ( V_4 ) ;
if ( V_8 ) {
F_5 ( V_2 -> V_12 , L_2 ) ;
return - V_13 ;
}
switch ( V_2 -> V_14 ) {
case V_15 :
case V_16 :
case V_17 :
V_6 = V_18 ;
break;
case V_19 :
case V_20 :
case V_21 :
case V_22 :
case V_23 :
V_6 = V_24 ;
break;
case V_25 :
case V_26 :
case V_27 :
case V_28 :
case V_29 :
case V_30 :
case V_31 :
V_6 = V_32 ;
break;
case V_33 :
case V_34 :
case V_35 :
case V_36 :
V_6 = V_37 ;
break;
default:
return - V_13 ;
}
V_8 = F_6 ( & V_2 -> V_38 , V_6 , & V_4 -> V_12 ) ;
if ( V_8 ) {
F_5 ( V_2 -> V_12 , L_3 ,
V_6 ) ;
F_7 ( V_4 ) ;
return V_8 ;
}
F_7 ( V_4 ) ;
V_5 = F_8 ( V_2 -> V_38 -> V_39 + 8 ) +
V_40 + V_41 ;
V_8 = F_9 ( V_2 , V_5 , V_42 , true ,
V_43 , NULL , & V_2 -> V_9 . V_44 ) ;
if ( V_8 ) {
F_5 ( V_2 -> V_12 , L_4 , V_8 ) ;
return V_8 ;
}
V_8 = F_10 ( V_2 ) ;
if ( V_8 )
return V_8 ;
memset ( V_2 -> V_9 . V_45 , 0 , V_5 ) ;
memcpy ( V_2 -> V_9 . V_45 , V_2 -> V_38 -> V_46 , V_2 -> V_38 -> V_39 ) ;
V_8 = F_11 ( V_2 ) ;
if ( V_8 )
return V_8 ;
for ( V_7 = 0 ; V_7 < V_47 ; ++ V_7 ) {
F_12 ( & V_2 -> V_9 . V_48 [ V_7 ] , 0 ) ;
V_2 -> V_9 . V_49 [ V_7 ] = NULL ;
}
return 0 ;
}
void F_13 ( struct V_1 * V_2 )
{
F_11 ( V_2 ) ;
F_14 ( & V_2 -> V_9 . V_44 ) ;
}
int F_11 ( struct V_1 * V_2 )
{
int V_8 ;
if ( V_2 -> V_9 . V_44 == NULL )
return 0 ;
V_8 = F_15 ( V_2 -> V_9 . V_44 , false ) ;
if ( ! V_8 ) {
F_16 ( V_2 -> V_9 . V_44 ) ;
F_17 ( V_2 -> V_9 . V_44 ) ;
V_2 -> V_9 . V_45 = NULL ;
if ( ! F_18 ( V_2 -> V_9 . V_44 , V_50 , NULL ) ) {
F_19 ( V_2 -> V_9 . V_44 , & V_2 -> V_9 . V_45 ) ;
}
F_20 ( V_2 -> V_9 . V_44 ) ;
if ( V_2 -> V_9 . V_45 ) {
F_21 ( V_2 , V_51 ) ;
} else {
V_2 -> V_52 [ V_51 ] . V_45 = NULL ;
}
}
return V_8 ;
}
int F_10 ( struct V_1 * V_2 )
{
int V_8 ;
if ( V_2 -> V_9 . V_44 == NULL )
return - V_13 ;
V_8 = F_15 ( V_2 -> V_9 . V_44 , false ) ;
if ( V_8 ) {
F_14 ( & V_2 -> V_9 . V_44 ) ;
F_5 ( V_2 -> V_12 , L_5 , V_8 ) ;
return V_8 ;
}
F_16 ( V_2 -> V_9 . V_44 ) ;
F_17 ( V_2 -> V_9 . V_44 ) ;
V_8 = F_18 ( V_2 -> V_9 . V_44 , V_43 ,
& V_2 -> V_9 . V_53 ) ;
if ( V_8 ) {
F_20 ( V_2 -> V_9 . V_44 ) ;
F_14 ( & V_2 -> V_9 . V_44 ) ;
F_5 ( V_2 -> V_12 , L_6 , V_8 ) ;
return V_8 ;
}
V_8 = F_19 ( V_2 -> V_9 . V_44 , & V_2 -> V_9 . V_45 ) ;
if ( V_8 ) {
F_5 ( V_2 -> V_12 , L_7 , V_8 ) ;
return V_8 ;
}
F_20 ( V_2 -> V_9 . V_44 ) ;
return 0 ;
}
void F_22 ( struct V_54 * V_55 )
{
V_55 -> V_56 . V_57 = 0 >> V_58 ;
V_55 -> V_56 . V_59 = ( 256 * 1024 * 1024 ) >> V_58 ;
}
void F_23 ( struct V_1 * V_2 , struct V_60 * V_49 )
{
int V_7 , V_8 ;
for ( V_7 = 0 ; V_7 < V_47 ; ++ V_7 ) {
if ( V_2 -> V_9 . V_49 [ V_7 ] == V_49 ) {
T_1 V_61 = F_24 ( & V_2 -> V_9 . V_48 [ V_7 ] ) ;
struct V_62 * V_63 ;
V_8 = F_25 ( V_2 ,
V_51 , V_61 , & V_63 ) ;
if ( V_8 ) {
F_26 ( L_8 , V_8 ) ;
continue;
}
F_27 ( V_63 , false ) ;
F_28 ( & V_63 ) ;
V_2 -> V_9 . V_49 [ V_7 ] = NULL ;
F_12 ( & V_2 -> V_9 . V_48 [ V_7 ] , 0 ) ;
}
}
}
static int F_29 ( T_1 * V_64 , unsigned V_65 [] )
{
unsigned V_66 = V_64 [ 4 ] ;
unsigned V_67 = V_64 [ 6 ] ;
unsigned V_68 = V_64 [ 7 ] ;
unsigned V_69 = V_64 [ 9 ] ;
unsigned V_70 = V_64 [ 28 ] ;
unsigned V_71 = V_67 / 16 ;
unsigned V_72 = F_30 ( V_68 / 16 , 2 ) ;
unsigned V_73 , V_74 , V_75 ;
V_73 = V_67 * V_68 ;
V_73 += V_73 / 2 ;
V_73 = F_30 ( V_73 , 1024 ) ;
switch ( V_66 ) {
case 0 :
V_75 = V_73 * 17 ;
V_75 += V_71 * V_72 * 17 * 192 ;
V_75 += V_71 * V_72 * 32 ;
break;
case 1 :
V_75 = V_73 * 3 ;
V_75 += V_71 * V_72 * 128 ;
V_75 += V_71 * 64 ;
V_75 += V_71 * 128 ;
V_74 = F_31 ( V_71 , V_72 ) ;
V_75 += F_30 ( V_74 * 7 * 16 , 64 ) ;
break;
case 3 :
V_75 = V_73 * 3 ;
break;
case 4 :
V_75 = V_73 * 3 ;
V_75 += V_71 * V_72 * 64 ;
V_75 += F_30 ( V_71 * V_72 * 32 , 64 ) ;
break;
default:
F_26 ( L_9 , V_66 ) ;
return - V_13 ;
}
if ( V_67 > V_70 ) {
F_26 ( L_10 ) ;
return - V_13 ;
}
if ( V_69 < V_75 ) {
F_26 ( L_11 ,
V_69 , V_75 ) ;
return - V_13 ;
}
V_65 [ 0x1 ] = V_69 ;
V_65 [ 0x2 ] = V_73 ;
return 0 ;
}
static int F_32 ( struct V_76 * V_77 , struct V_54 * V_78 ,
unsigned V_79 , unsigned V_65 [] )
{
T_2 * V_64 , V_80 , V_61 ;
void * V_81 ;
int V_7 , V_8 ;
if ( V_79 & 0x3F ) {
F_26 ( L_12 ) ;
return - V_13 ;
}
V_8 = F_19 ( V_78 , & V_81 ) ;
if ( V_8 )
return V_8 ;
V_64 = V_81 + V_79 ;
V_80 = V_64 [ 1 ] ;
V_61 = V_64 [ 2 ] ;
if ( V_61 == 0 ) {
F_26 ( L_13 ) ;
return - V_13 ;
}
if ( V_80 == 1 ) {
V_8 = F_29 ( V_64 , V_65 ) ;
F_16 ( V_78 ) ;
if ( V_8 )
return V_8 ;
} else if ( V_80 == 2 ) {
for ( V_7 = 0 ; V_7 < V_47 ; ++ V_7 )
F_33 ( & V_77 -> V_2 -> V_9 . V_48 [ V_7 ] , V_61 , 0 ) ;
F_16 ( V_78 ) ;
return 0 ;
} else {
F_16 ( V_78 ) ;
}
for ( V_7 = 0 ; V_7 < V_47 ; ++ V_7 ) {
if ( F_24 ( & V_77 -> V_2 -> V_9 . V_48 [ V_7 ] ) == V_61 )
return 0 ;
}
for ( V_7 = 0 ; V_7 < V_47 ; ++ V_7 ) {
if ( ! F_33 ( & V_77 -> V_2 -> V_9 . V_48 [ V_7 ] , 0 , V_61 ) ) {
V_77 -> V_2 -> V_9 . V_49 [ V_7 ] = V_77 -> V_49 ;
return 0 ;
}
}
F_26 ( L_14 ) ;
return - V_13 ;
}
static int F_34 ( struct V_76 * V_77 ,
int V_82 , int V_83 ,
unsigned V_65 [] )
{
struct V_84 * V_85 ;
struct V_86 * V_87 ;
unsigned V_88 , V_89 , V_79 ;
T_3 V_90 , V_91 ;
int V_8 ;
V_85 = & V_77 -> V_92 [ V_77 -> V_93 ] ;
V_79 = F_35 ( V_77 , V_82 ) ;
V_88 = F_35 ( V_77 , V_83 ) ;
if ( V_88 >= V_85 -> V_94 ) {
F_26 ( L_15 ,
V_88 , V_85 -> V_94 ) ;
return - V_13 ;
}
V_87 = V_77 -> V_95 [ ( V_88 / 4 ) ] ;
V_90 = V_87 -> V_96 . V_97 ;
V_91 = V_90 + F_36 ( V_87 -> V_98 ) ;
V_90 += V_79 ;
V_77 -> V_99 . V_81 [ V_82 ] = V_90 & 0xFFFFFFFF ;
V_77 -> V_99 . V_81 [ V_83 ] = V_90 >> 32 ;
V_89 = F_35 ( V_77 , V_77 -> V_88 ) >> 1 ;
if ( V_89 < 0x4 ) {
if ( ( V_91 - V_90 ) < V_65 [ V_89 ] ) {
F_26 ( L_16 ,
( unsigned ) ( V_91 - V_90 ) , V_65 [ V_89 ] ) ;
return - V_13 ;
}
} else if ( V_89 != 0x100 ) {
F_26 ( L_17 , V_89 ) ;
return - V_13 ;
}
if ( ( V_90 >> 28 ) != ( V_91 >> 28 ) ) {
F_26 ( L_18 ,
V_90 , V_91 ) ;
return - V_13 ;
}
if ( ( V_89 == 0 || V_89 == 0x3 ) &&
( V_90 >> 28 ) != ( V_77 -> V_2 -> V_9 . V_53 >> 28 ) ) {
F_26 ( L_19 ,
V_90 , V_91 ) ;
return - V_13 ;
}
if ( V_89 == 0 ) {
V_8 = F_32 ( V_77 , V_87 -> V_98 , V_79 , V_65 ) ;
if ( V_8 )
return V_8 ;
}
return 0 ;
}
static int F_37 ( struct V_76 * V_77 ,
struct V_100 * V_101 ,
int * V_82 , int * V_83 ,
unsigned V_65 [] )
{
int V_7 , V_8 ;
V_77 -> V_88 ++ ;
for ( V_7 = 0 ; V_7 <= V_101 -> V_102 ; ++ V_7 ) {
switch ( V_101 -> V_103 + V_7 * 4 ) {
case V_104 :
* V_82 = V_77 -> V_88 ;
break;
case V_105 :
* V_83 = V_77 -> V_88 ;
break;
case V_106 :
V_8 = F_34 ( V_77 , * V_82 , * V_83 , V_65 ) ;
if ( V_8 )
return V_8 ;
break;
case V_107 :
break;
default:
F_26 ( L_20 ,
V_101 -> V_103 + V_7 * 4 ) ;
return - V_13 ;
}
V_77 -> V_88 ++ ;
}
return 0 ;
}
int F_38 ( struct V_76 * V_77 )
{
struct V_100 V_101 ;
int V_8 , V_82 = 0 , V_83 = 0 ;
unsigned V_65 [] = {
[ 0x00000000 ] = 2048 ,
[ 0x00000001 ] = 32 * 1024 * 1024 ,
[ 0x00000002 ] = 2048 * 1152 * 3 ,
[ 0x00000003 ] = 2048 ,
} ;
if ( V_77 -> V_92 [ V_77 -> V_108 ] . V_94 % 16 ) {
F_26 ( L_21 ,
V_77 -> V_92 [ V_77 -> V_108 ] . V_94 ) ;
return - V_13 ;
}
if ( V_77 -> V_93 == - 1 ) {
F_26 ( L_22 ) ;
return - V_13 ;
}
do {
V_8 = F_39 ( V_77 , & V_101 , V_77 -> V_88 ) ;
if ( V_8 )
return V_8 ;
switch ( V_101 . type ) {
case V_109 :
V_8 = F_37 ( V_77 , & V_101 , & V_82 ,
& V_83 , V_65 ) ;
if ( V_8 )
return V_8 ;
break;
case V_110 :
V_77 -> V_88 += V_101 . V_102 + 2 ;
break;
default:
F_26 ( L_23 , V_101 . type ) ;
return - V_13 ;
}
} while ( V_77 -> V_88 < V_77 -> V_92 [ V_77 -> V_108 ] . V_94 );
return 0 ;
}
static int F_40 ( struct V_1 * V_2 ,
int V_111 , struct V_54 * V_78 ,
struct V_62 * * V_63 )
{
struct V_112 V_113 ;
struct V_114 V_115 ;
struct V_116 V_99 ;
T_3 V_117 ;
int V_7 , V_8 ;
memset ( & V_113 , 0 , sizeof( V_113 ) ) ;
V_113 . V_78 = & V_78 -> V_118 ;
F_41 ( & V_115 ) ;
F_42 ( & V_113 . V_115 , & V_115 ) ;
V_8 = F_43 ( & V_115 ) ;
if ( V_8 )
return V_8 ;
F_44 ( V_78 , V_43 ) ;
F_22 ( V_78 ) ;
V_8 = F_45 ( & V_78 -> V_118 , & V_78 -> V_56 , true , false ) ;
if ( V_8 ) {
F_46 ( & V_115 ) ;
return V_8 ;
}
V_8 = F_47 ( V_2 , V_111 , & V_99 , NULL , 16 ) ;
if ( V_8 ) {
F_46 ( & V_115 ) ;
return V_8 ;
}
V_117 = F_48 ( V_78 ) ;
V_99 . V_81 [ 0 ] = F_49 ( V_104 , 0 ) ;
V_99 . V_81 [ 1 ] = V_117 ;
V_99 . V_81 [ 2 ] = F_49 ( V_105 , 0 ) ;
V_99 . V_81 [ 3 ] = V_117 >> 32 ;
V_99 . V_81 [ 4 ] = F_49 ( V_106 , 0 ) ;
V_99 . V_81 [ 5 ] = 0 ;
for ( V_7 = 6 ; V_7 < 16 ; ++ V_7 )
V_99 . V_81 [ V_7 ] = F_50 ( 0 ) ;
V_99 . V_94 = 16 ;
V_8 = F_51 ( V_2 , & V_99 , NULL ) ;
if ( V_8 ) {
F_46 ( & V_115 ) ;
return V_8 ;
}
F_52 ( & V_115 , V_99 . V_63 ) ;
if ( V_63 )
* V_63 = F_53 ( V_99 . V_63 ) ;
F_54 ( V_2 , & V_99 ) ;
F_14 ( & V_78 ) ;
return 0 ;
}
int F_55 ( struct V_1 * V_2 , int V_111 ,
T_1 V_61 , struct V_62 * * V_63 )
{
struct V_54 * V_78 ;
T_1 * V_64 ;
int V_8 , V_7 ;
V_8 = F_9 ( V_2 , 1024 , V_42 , true ,
V_43 , NULL , & V_78 ) ;
if ( V_8 )
return V_8 ;
V_8 = F_15 ( V_78 , false ) ;
if ( V_8 ) {
F_14 ( & V_78 ) ;
return V_8 ;
}
V_8 = F_19 ( V_78 , ( void * * ) & V_64 ) ;
if ( V_8 ) {
F_20 ( V_78 ) ;
F_14 ( & V_78 ) ;
return V_8 ;
}
V_64 [ 0 ] = F_56 ( 0x00000de4 ) ;
V_64 [ 1 ] = F_56 ( 0x00000000 ) ;
V_64 [ 2 ] = F_56 ( V_61 ) ;
V_64 [ 3 ] = F_56 ( 0x00000000 ) ;
V_64 [ 4 ] = F_56 ( 0x00000000 ) ;
V_64 [ 5 ] = F_56 ( 0x00000000 ) ;
V_64 [ 6 ] = F_56 ( 0x00000000 ) ;
V_64 [ 7 ] = F_56 ( 0x00000780 ) ;
V_64 [ 8 ] = F_56 ( 0x00000440 ) ;
V_64 [ 9 ] = F_56 ( 0x00000000 ) ;
V_64 [ 10 ] = F_56 ( 0x01b37000 ) ;
for ( V_7 = 11 ; V_7 < 1024 ; ++ V_7 )
V_64 [ V_7 ] = F_56 ( 0x0 ) ;
F_16 ( V_78 ) ;
F_20 ( V_78 ) ;
return F_40 ( V_2 , V_111 , V_78 , V_63 ) ;
}
int F_25 ( struct V_1 * V_2 , int V_111 ,
T_1 V_61 , struct V_62 * * V_63 )
{
struct V_54 * V_78 ;
T_1 * V_64 ;
int V_8 , V_7 ;
V_8 = F_9 ( V_2 , 1024 , V_42 , true ,
V_43 , NULL , & V_78 ) ;
if ( V_8 )
return V_8 ;
V_8 = F_15 ( V_78 , false ) ;
if ( V_8 ) {
F_14 ( & V_78 ) ;
return V_8 ;
}
V_8 = F_19 ( V_78 , ( void * * ) & V_64 ) ;
if ( V_8 ) {
F_20 ( V_78 ) ;
F_14 ( & V_78 ) ;
return V_8 ;
}
V_64 [ 0 ] = F_56 ( 0x00000de4 ) ;
V_64 [ 1 ] = F_56 ( 0x00000002 ) ;
V_64 [ 2 ] = F_56 ( V_61 ) ;
V_64 [ 3 ] = F_56 ( 0x00000000 ) ;
for ( V_7 = 4 ; V_7 < 1024 ; ++ V_7 )
V_64 [ V_7 ] = F_56 ( 0x0 ) ;
F_16 ( V_78 ) ;
F_20 ( V_78 ) ;
return F_40 ( V_2 , V_111 , V_78 , V_63 ) ;
}
static void V_11 ( struct V_119 * V_120 )
{
struct V_1 * V_2 =
F_57 ( V_120 , struct V_1 , V_9 . V_10 . V_120 ) ;
if ( F_58 ( V_2 , V_51 ) == 0 )
F_59 ( V_2 , 0 , 0 ) ;
else
F_60 ( & V_2 -> V_9 . V_10 ,
F_61 ( V_121 ) ) ;
}
void F_62 ( struct V_1 * V_2 )
{
bool V_122 = ! F_63 ( & V_2 -> V_9 . V_10 ) ;
V_122 &= F_60 ( & V_2 -> V_9 . V_10 ,
F_61 ( V_121 ) ) ;
if ( V_122 )
F_59 ( V_2 , 53300 , 40000 ) ;
}
static unsigned F_64 ( unsigned V_123 ,
unsigned V_124 ,
unsigned V_125 ,
unsigned V_126 )
{
unsigned V_127 = V_123 / V_124 ;
if ( V_127 < V_125 )
V_127 = V_125 ;
if ( ( V_123 / V_127 ) > V_124 )
V_127 += 1 ;
if ( V_127 > V_126 && V_127 % 2 )
V_127 += 1 ;
return V_127 ;
}
int F_65 ( struct V_1 * V_2 ,
unsigned V_128 , unsigned V_129 ,
unsigned V_130 , unsigned V_131 ,
unsigned V_132 , unsigned V_133 ,
unsigned V_125 , unsigned V_134 ,
unsigned V_126 ,
unsigned * V_135 ,
unsigned * V_136 ,
unsigned * V_137 )
{
unsigned V_123 , V_138 = V_2 -> clock . V_139 . V_140 ;
unsigned V_141 = ~ 0 ;
V_130 = F_31 ( F_31 ( V_130 , V_128 ) , V_129 ) ;
for ( V_123 = V_130 ; V_123 <= V_131 ; V_123 += 100 ) {
T_3 V_142 = ( T_3 ) V_123 * V_132 ;
unsigned V_143 , V_144 , V_145 ;
F_66 ( V_142 , V_138 ) ;
if ( V_142 > V_133 )
break;
V_142 &= V_133 ;
V_143 = F_64 ( V_123 , V_128 ,
V_125 , V_126 ) ;
if ( V_143 > V_134 )
break;
V_144 = F_64 ( V_123 , V_129 ,
V_125 , V_126 ) ;
if ( V_143 > V_134 )
break;
V_145 = V_128 - ( V_123 / V_143 ) + V_129 - ( V_123 / V_144 ) ;
if ( V_145 < V_141 ) {
* V_135 = V_142 ;
* V_136 = V_143 ;
* V_137 = V_144 ;
V_141 = V_145 ;
if ( V_141 == 0 )
break;
}
}
if ( V_141 == ~ 0 )
return - V_13 ;
return 0 ;
}
int F_67 ( struct V_1 * V_2 ,
unsigned V_146 )
{
unsigned V_7 ;
F_68 ( V_146 , 0 , ~ V_147 ) ;
F_69 ( 10 ) ;
F_68 ( V_146 , V_147 , ~ V_147 ) ;
for ( V_7 = 0 ; V_7 < 100 ; ++ V_7 ) {
T_1 V_148 = V_149 | V_150 ;
if ( ( F_70 ( V_146 ) & V_148 ) == V_148 )
break;
F_69 ( 10 ) ;
}
F_68 ( V_146 , 0 , ~ V_147 ) ;
if ( V_7 == 100 ) {
F_26 ( L_24 ) ;
return - V_151 ;
}
return 0 ;
}
