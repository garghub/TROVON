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
case V_37 :
V_4 = V_38 ;
break;
default:
return - V_39 ;
}
V_6 = F_3 ( & V_2 -> V_40 , V_4 , V_2 -> V_41 ) ;
if ( V_6 ) {
F_4 ( V_2 -> V_41 , L_1 ,
V_4 ) ;
return V_6 ;
}
V_3 = F_5 ( V_2 -> V_40 -> V_42 + 8 ) +
V_43 + V_44 ;
V_6 = F_6 ( V_2 , V_3 , V_45 , true ,
V_46 , NULL , & V_2 -> V_7 . V_47 ) ;
if ( V_6 ) {
F_4 ( V_2 -> V_41 , L_2 , V_6 ) ;
return V_6 ;
}
V_6 = F_7 ( V_2 -> V_7 . V_47 , false ) ;
if ( V_6 ) {
F_8 ( & V_2 -> V_7 . V_47 ) ;
F_4 ( V_2 -> V_41 , L_3 , V_6 ) ;
return V_6 ;
}
V_6 = F_9 ( V_2 -> V_7 . V_47 , V_46 ,
& V_2 -> V_7 . V_48 ) ;
if ( V_6 ) {
F_10 ( V_2 -> V_7 . V_47 ) ;
F_8 ( & V_2 -> V_7 . V_47 ) ;
F_4 ( V_2 -> V_41 , L_4 , V_6 ) ;
return V_6 ;
}
V_6 = F_11 ( V_2 -> V_7 . V_47 , & V_2 -> V_7 . V_49 ) ;
if ( V_6 ) {
F_4 ( V_2 -> V_41 , L_5 , V_6 ) ;
return V_6 ;
}
F_10 ( V_2 -> V_7 . V_47 ) ;
for ( V_5 = 0 ; V_5 < V_50 ; ++ V_5 ) {
F_12 ( & V_2 -> V_7 . V_51 [ V_5 ] , 0 ) ;
V_2 -> V_7 . V_52 [ V_5 ] = NULL ;
V_2 -> V_7 . V_53 [ V_5 ] = 0 ;
}
return 0 ;
}
void F_13 ( struct V_1 * V_2 )
{
int V_6 ;
if ( V_2 -> V_7 . V_47 == NULL )
return;
V_6 = F_7 ( V_2 -> V_7 . V_47 , false ) ;
if ( ! V_6 ) {
F_14 ( V_2 -> V_7 . V_47 ) ;
F_15 ( V_2 -> V_7 . V_47 ) ;
F_10 ( V_2 -> V_7 . V_47 ) ;
}
F_8 ( & V_2 -> V_7 . V_47 ) ;
F_16 ( V_2 -> V_40 ) ;
}
int F_17 ( struct V_1 * V_2 )
{
unsigned V_42 ;
void * V_54 ;
int V_5 ;
if ( V_2 -> V_7 . V_47 == NULL )
return 0 ;
for ( V_5 = 0 ; V_5 < V_50 ; ++ V_5 )
if ( F_18 ( & V_2 -> V_7 . V_51 [ V_5 ] ) )
break;
if ( V_5 == V_50 )
return 0 ;
V_42 = F_19 ( V_2 -> V_7 . V_47 ) ;
V_42 -= V_2 -> V_40 -> V_42 ;
V_54 = V_2 -> V_7 . V_49 ;
V_54 += V_2 -> V_40 -> V_42 ;
V_2 -> V_7 . V_55 = F_20 ( V_42 , V_56 ) ;
memcpy ( V_2 -> V_7 . V_55 , V_54 , V_42 ) ;
return 0 ;
}
int F_21 ( struct V_1 * V_2 )
{
unsigned V_42 ;
void * V_54 ;
if ( V_2 -> V_7 . V_47 == NULL )
return - V_39 ;
memcpy ( V_2 -> V_7 . V_49 , V_2 -> V_40 -> V_57 , V_2 -> V_40 -> V_42 ) ;
V_42 = F_19 ( V_2 -> V_7 . V_47 ) ;
V_42 -= V_2 -> V_40 -> V_42 ;
V_54 = V_2 -> V_7 . V_49 ;
V_54 += V_2 -> V_40 -> V_42 ;
if ( V_2 -> V_7 . V_55 != NULL ) {
memcpy ( V_54 , V_2 -> V_7 . V_55 , V_42 ) ;
F_22 ( V_2 -> V_7 . V_55 ) ;
V_2 -> V_7 . V_55 = NULL ;
} else
memset ( V_54 , 0 , V_42 ) ;
return 0 ;
}
void F_23 ( struct V_58 * V_59 )
{
V_59 -> V_60 . V_61 = 0 >> V_62 ;
V_59 -> V_60 . V_63 = ( 256 * 1024 * 1024 ) >> V_62 ;
}
void F_24 ( struct V_1 * V_2 , struct V_64 * V_52 )
{
int V_5 , V_6 ;
for ( V_5 = 0 ; V_5 < V_50 ; ++ V_5 ) {
T_1 V_65 = F_18 ( & V_2 -> V_7 . V_51 [ V_5 ] ) ;
if ( V_65 != 0 && V_2 -> V_7 . V_52 [ V_5 ] == V_52 ) {
struct V_66 * V_67 ;
F_25 ( V_2 ) ;
V_6 = F_26 ( V_2 ,
V_68 , V_65 , & V_67 ) ;
if ( V_6 ) {
F_27 ( L_6 , V_6 ) ;
continue;
}
F_28 ( V_67 , false ) ;
F_29 ( & V_67 ) ;
V_2 -> V_7 . V_52 [ V_5 ] = NULL ;
F_12 ( & V_2 -> V_7 . V_51 [ V_5 ] , 0 ) ;
}
}
}
static int F_30 ( T_1 * V_69 , unsigned V_70 [] )
{
unsigned V_71 = V_69 [ 4 ] ;
unsigned V_72 = V_69 [ 6 ] ;
unsigned V_73 = V_69 [ 7 ] ;
unsigned V_74 = V_69 [ 9 ] ;
unsigned V_75 = V_69 [ 28 ] ;
unsigned V_76 = V_72 / 16 ;
unsigned V_77 = F_31 ( V_73 / 16 , 2 ) ;
unsigned V_78 , V_79 , V_80 ;
V_78 = V_72 * V_73 ;
V_78 += V_78 / 2 ;
V_78 = F_31 ( V_78 , 1024 ) ;
switch ( V_71 ) {
case 0 :
V_80 = V_78 * 17 ;
V_80 += V_76 * V_77 * 17 * 192 ;
V_80 += V_76 * V_77 * 32 ;
break;
case 1 :
V_80 = V_78 * 3 ;
V_80 += V_76 * V_77 * 128 ;
V_80 += V_76 * 64 ;
V_80 += V_76 * 128 ;
V_79 = F_32 ( V_76 , V_77 ) ;
V_80 += F_31 ( V_79 * 7 * 16 , 64 ) ;
break;
case 3 :
V_80 = V_78 * 3 ;
break;
case 4 :
V_80 = V_78 * 3 ;
V_80 += V_76 * V_77 * 64 ;
V_80 += F_31 ( V_76 * V_77 * 32 , 64 ) ;
break;
default:
F_27 ( L_7 , V_71 ) ;
return - V_39 ;
}
if ( V_72 > V_75 ) {
F_27 ( L_8 ) ;
return - V_39 ;
}
if ( V_74 < V_80 ) {
F_27 ( L_9 ,
V_74 , V_80 ) ;
return - V_39 ;
}
V_70 [ 0x1 ] = V_74 ;
V_70 [ 0x2 ] = V_78 ;
return 0 ;
}
static int F_33 ( struct V_81 * V_82 , struct V_58 * V_83 ,
unsigned V_84 , unsigned V_70 [] )
{
T_2 * V_69 , V_85 , V_65 ;
unsigned V_53 = 0 ;
void * V_54 ;
int V_5 , V_6 ;
if ( V_84 & 0x3F ) {
F_27 ( L_10 ) ;
return - V_39 ;
}
if ( V_83 -> V_86 . V_87 ) {
V_6 = F_28 ( V_83 -> V_86 . V_87 , false ) ;
if ( V_6 ) {
F_27 ( L_11 , V_6 ) ;
return V_6 ;
}
}
V_6 = F_11 ( V_83 , & V_54 ) ;
if ( V_6 ) {
F_27 ( L_12 , V_6 ) ;
return V_6 ;
}
V_69 = V_54 + V_84 ;
V_85 = V_69 [ 1 ] ;
V_65 = V_69 [ 2 ] ;
if ( V_65 == 0 ) {
F_27 ( L_13 ) ;
return - V_39 ;
}
if ( V_85 == 1 ) {
V_6 = F_30 ( V_69 , V_70 ) ;
V_53 = V_69 [ 6 ] * V_69 [ 7 ] ;
F_14 ( V_83 ) ;
if ( V_6 )
return V_6 ;
} else if ( V_85 == 2 ) {
for ( V_5 = 0 ; V_5 < V_50 ; ++ V_5 )
F_34 ( & V_82 -> V_2 -> V_7 . V_51 [ V_5 ] , V_65 , 0 ) ;
F_14 ( V_83 ) ;
return 0 ;
} else {
V_53 = V_69 [ 7 ] * V_69 [ 8 ] ;
F_14 ( V_83 ) ;
if ( V_85 != 0 ) {
F_27 ( L_14 , V_85 ) ;
return - V_39 ;
}
}
for ( V_5 = 0 ; V_5 < V_50 ; ++ V_5 ) {
if ( F_18 ( & V_82 -> V_2 -> V_7 . V_51 [ V_5 ] ) == V_65 )
return 0 ;
}
for ( V_5 = 0 ; V_5 < V_50 ; ++ V_5 ) {
if ( ! F_34 ( & V_82 -> V_2 -> V_7 . V_51 [ V_5 ] , 0 , V_65 ) ) {
V_82 -> V_2 -> V_7 . V_52 [ V_5 ] = V_82 -> V_52 ;
V_82 -> V_2 -> V_7 . V_53 [ V_5 ] = V_53 ;
return 0 ;
}
}
F_27 ( L_15 ) ;
return - V_39 ;
}
static int F_35 ( struct V_81 * V_82 ,
int V_88 , int V_89 ,
unsigned V_70 [] , bool * V_90 )
{
struct V_91 * V_92 ;
struct V_93 * V_94 ;
unsigned V_95 , V_96 , V_84 ;
T_3 V_97 , V_98 ;
int V_6 ;
V_92 = & V_82 -> V_99 [ V_82 -> V_100 ] ;
V_84 = F_36 ( V_82 , V_88 ) ;
V_95 = F_36 ( V_82 , V_89 ) ;
if ( V_95 >= V_92 -> V_101 ) {
F_27 ( L_16 ,
V_95 , V_92 -> V_101 ) ;
return - V_39 ;
}
V_94 = V_82 -> V_102 [ ( V_95 / 4 ) ] ;
V_97 = V_94 -> V_103 . V_104 ;
V_98 = V_97 + F_19 ( V_94 -> V_105 ) ;
V_97 += V_84 ;
V_82 -> V_106 . V_54 [ V_88 ] = V_97 & 0xFFFFFFFF ;
V_82 -> V_106 . V_54 [ V_89 ] = V_97 >> 32 ;
V_96 = F_36 ( V_82 , V_82 -> V_95 ) >> 1 ;
if ( V_96 < 0x4 ) {
if ( ( V_98 - V_97 ) < V_70 [ V_96 ] ) {
F_27 ( L_17 , V_96 ,
( unsigned ) ( V_98 - V_97 ) , V_70 [ V_96 ] ) ;
return - V_39 ;
}
} else if ( V_96 != 0x100 ) {
F_27 ( L_18 , V_96 ) ;
return - V_39 ;
}
if ( ( V_97 >> 28 ) != ( ( V_98 - 1 ) >> 28 ) ) {
F_27 ( L_19 ,
V_97 , V_98 ) ;
return - V_39 ;
}
if ( ( V_96 == 0 || V_96 == 0x3 ) &&
( V_97 >> 28 ) != ( V_82 -> V_2 -> V_7 . V_48 >> 28 ) ) {
F_27 ( L_20 ,
V_97 , V_98 ) ;
return - V_39 ;
}
if ( V_96 == 0 ) {
if ( * V_90 ) {
F_27 ( L_21 ) ;
return - V_39 ;
}
* V_90 = true ;
V_6 = F_33 ( V_82 , V_94 -> V_105 , V_84 , V_70 ) ;
if ( V_6 )
return V_6 ;
} else if ( ! * V_90 ) {
F_27 ( L_22 ) ;
return - V_39 ;
}
return 0 ;
}
static int F_37 ( struct V_81 * V_82 ,
struct V_107 * V_108 ,
int * V_88 , int * V_89 ,
unsigned V_70 [] ,
bool * V_90 )
{
int V_5 , V_6 ;
V_82 -> V_95 ++ ;
for ( V_5 = 0 ; V_5 <= V_108 -> V_109 ; ++ V_5 ) {
switch ( V_108 -> V_110 + V_5 * 4 ) {
case V_111 :
* V_88 = V_82 -> V_95 ;
break;
case V_112 :
* V_89 = V_82 -> V_95 ;
break;
case V_113 :
V_6 = F_35 ( V_82 , * V_88 , * V_89 ,
V_70 , V_90 ) ;
if ( V_6 )
return V_6 ;
break;
case V_114 :
break;
default:
F_27 ( L_23 ,
V_108 -> V_110 + V_5 * 4 ) ;
return - V_39 ;
}
V_82 -> V_95 ++ ;
}
return 0 ;
}
int F_38 ( struct V_81 * V_82 )
{
struct V_107 V_108 ;
int V_6 , V_88 = 0 , V_89 = 0 ;
bool V_90 = false ;
unsigned V_70 [] = {
[ 0x00000000 ] = 2048 ,
[ 0x00000001 ] = 32 * 1024 * 1024 ,
[ 0x00000002 ] = 2048 * 1152 * 3 ,
[ 0x00000003 ] = 2048 ,
} ;
if ( V_82 -> V_99 [ V_82 -> V_115 ] . V_101 % 16 ) {
F_27 ( L_24 ,
V_82 -> V_99 [ V_82 -> V_115 ] . V_101 ) ;
return - V_39 ;
}
if ( V_82 -> V_100 == - 1 ) {
F_27 ( L_25 ) ;
return - V_39 ;
}
do {
V_6 = F_39 ( V_82 , & V_108 , V_82 -> V_95 ) ;
if ( V_6 )
return V_6 ;
switch ( V_108 . type ) {
case V_116 :
V_6 = F_37 ( V_82 , & V_108 , & V_88 , & V_89 ,
V_70 , & V_90 ) ;
if ( V_6 )
return V_6 ;
break;
case V_117 :
V_82 -> V_95 += V_108 . V_109 + 2 ;
break;
default:
F_27 ( L_26 , V_108 . type ) ;
return - V_39 ;
}
} while ( V_82 -> V_95 < V_82 -> V_99 [ V_82 -> V_115 ] . V_101 );
if ( ! V_90 ) {
F_27 ( L_27 ) ;
return - V_39 ;
}
return 0 ;
}
static int F_40 ( struct V_1 * V_2 ,
int V_118 , struct V_58 * V_83 ,
struct V_66 * * V_67 )
{
struct V_119 V_120 ;
struct V_121 V_122 ;
struct V_123 V_124 ;
struct V_125 V_106 ;
T_3 V_126 ;
int V_5 , V_6 ;
memset ( & V_120 , 0 , sizeof( V_120 ) ) ;
V_120 . V_83 = & V_83 -> V_86 ;
F_41 ( & V_124 ) ;
F_42 ( & V_120 . V_124 , & V_124 ) ;
V_6 = F_43 ( & V_122 , & V_124 ) ;
if ( V_6 )
return V_6 ;
F_44 ( V_83 , V_46 ) ;
F_23 ( V_83 ) ;
V_6 = F_45 ( & V_83 -> V_86 , & V_83 -> V_60 , true , false ) ;
if ( V_6 )
goto V_127;
V_6 = F_46 ( V_2 , V_118 , & V_106 , NULL , 64 ) ;
if ( V_6 )
goto V_127;
V_126 = F_47 ( V_83 ) ;
V_106 . V_54 [ 0 ] = F_48 ( V_111 , 0 ) ;
V_106 . V_54 [ 1 ] = V_126 ;
V_106 . V_54 [ 2 ] = F_48 ( V_112 , 0 ) ;
V_106 . V_54 [ 3 ] = V_126 >> 32 ;
V_106 . V_54 [ 4 ] = F_48 ( V_113 , 0 ) ;
V_106 . V_54 [ 5 ] = 0 ;
for ( V_5 = 6 ; V_5 < 16 ; ++ V_5 )
V_106 . V_54 [ V_5 ] = F_49 ( 0 ) ;
V_106 . V_101 = 16 ;
V_6 = F_50 ( V_2 , & V_106 , NULL ) ;
if ( V_6 )
goto V_127;
F_51 ( & V_122 , & V_124 , V_106 . V_67 ) ;
if ( V_67 )
* V_67 = F_52 ( V_106 . V_67 ) ;
F_53 ( V_2 , & V_106 ) ;
F_8 ( & V_83 ) ;
return 0 ;
V_127:
F_54 ( & V_122 , & V_124 ) ;
return V_6 ;
}
int F_55 ( struct V_1 * V_2 , int V_118 ,
T_1 V_65 , struct V_66 * * V_67 )
{
struct V_58 * V_83 ;
T_1 * V_69 ;
int V_6 , V_5 ;
V_6 = F_6 ( V_2 , 1024 , V_45 , true ,
V_46 , NULL , & V_83 ) ;
if ( V_6 )
return V_6 ;
V_6 = F_7 ( V_83 , false ) ;
if ( V_6 ) {
F_8 ( & V_83 ) ;
return V_6 ;
}
V_6 = F_11 ( V_83 , ( void * * ) & V_69 ) ;
if ( V_6 ) {
F_10 ( V_83 ) ;
F_8 ( & V_83 ) ;
return V_6 ;
}
V_69 [ 0 ] = F_56 ( 0x00000de4 ) ;
V_69 [ 1 ] = F_56 ( 0x00000000 ) ;
V_69 [ 2 ] = F_56 ( V_65 ) ;
V_69 [ 3 ] = F_56 ( 0x00000000 ) ;
V_69 [ 4 ] = F_56 ( 0x00000000 ) ;
V_69 [ 5 ] = F_56 ( 0x00000000 ) ;
V_69 [ 6 ] = F_56 ( 0x00000000 ) ;
V_69 [ 7 ] = F_56 ( 0x00000780 ) ;
V_69 [ 8 ] = F_56 ( 0x00000440 ) ;
V_69 [ 9 ] = F_56 ( 0x00000000 ) ;
V_69 [ 10 ] = F_56 ( 0x01b37000 ) ;
for ( V_5 = 11 ; V_5 < 1024 ; ++ V_5 )
V_69 [ V_5 ] = F_56 ( 0x0 ) ;
F_14 ( V_83 ) ;
F_10 ( V_83 ) ;
return F_40 ( V_2 , V_118 , V_83 , V_67 ) ;
}
int F_26 ( struct V_1 * V_2 , int V_118 ,
T_1 V_65 , struct V_66 * * V_67 )
{
struct V_58 * V_83 ;
T_1 * V_69 ;
int V_6 , V_5 ;
V_6 = F_6 ( V_2 , 1024 , V_45 , true ,
V_46 , NULL , & V_83 ) ;
if ( V_6 )
return V_6 ;
V_6 = F_7 ( V_83 , false ) ;
if ( V_6 ) {
F_8 ( & V_83 ) ;
return V_6 ;
}
V_6 = F_11 ( V_83 , ( void * * ) & V_69 ) ;
if ( V_6 ) {
F_10 ( V_83 ) ;
F_8 ( & V_83 ) ;
return V_6 ;
}
V_69 [ 0 ] = F_56 ( 0x00000de4 ) ;
V_69 [ 1 ] = F_56 ( 0x00000002 ) ;
V_69 [ 2 ] = F_56 ( V_65 ) ;
V_69 [ 3 ] = F_56 ( 0x00000000 ) ;
for ( V_5 = 4 ; V_5 < 1024 ; ++ V_5 )
V_69 [ V_5 ] = F_56 ( 0x0 ) ;
F_14 ( V_83 ) ;
F_10 ( V_83 ) ;
return F_40 ( V_2 , V_118 , V_83 , V_67 ) ;
}
static void F_57 ( struct V_1 * V_2 ,
unsigned * V_128 , unsigned * V_129 )
{
unsigned V_5 ;
* V_128 = 0 ;
* V_129 = 0 ;
for ( V_5 = 0 ; V_5 < V_50 ; ++ V_5 ) {
if ( ! F_18 ( & V_2 -> V_7 . V_51 [ V_5 ] ) )
continue;
if ( V_2 -> V_7 . V_53 [ V_5 ] >= 720 * 576 )
++ ( * V_129 ) ;
else
++ ( * V_128 ) ;
}
}
static void V_9 ( struct V_130 * V_131 )
{
struct V_1 * V_2 =
F_58 ( V_131 , struct V_1 , V_7 . V_8 . V_131 ) ;
if ( F_59 ( V_2 , V_68 ) == 0 ) {
if ( ( V_2 -> V_132 . V_133 == V_134 ) && V_2 -> V_132 . V_135 ) {
F_60 ( V_2 , false ) ;
} else {
F_61 ( V_2 , 0 , 0 ) ;
}
} else {
F_62 ( & V_2 -> V_7 . V_8 ,
F_63 ( V_136 ) ) ;
}
}
void F_25 ( struct V_1 * V_2 )
{
bool V_137 = false ;
bool V_138 = ! F_64 ( & V_2 -> V_7 . V_8 ) ;
V_138 &= F_62 ( & V_2 -> V_7 . V_8 ,
F_63 ( V_136 ) ) ;
if ( ( V_2 -> V_132 . V_133 == V_134 ) && V_2 -> V_132 . V_135 ) {
unsigned V_129 = 0 , V_128 = 0 ;
F_57 ( V_2 , & V_128 , & V_129 ) ;
if ( ( V_2 -> V_132 . V_139 . V_128 != V_128 ) ||
( V_2 -> V_132 . V_139 . V_129 != V_129 ) ) {
V_2 -> V_132 . V_139 . V_128 = V_128 ;
V_2 -> V_132 . V_139 . V_129 = V_129 ;
}
}
if ( V_138 || V_137 ) {
if ( ( V_2 -> V_132 . V_133 == V_134 ) && V_2 -> V_132 . V_135 ) {
F_60 ( V_2 , true ) ;
} else {
F_61 ( V_2 , 53300 , 40000 ) ;
}
}
}
static unsigned F_65 ( unsigned V_140 ,
unsigned V_141 ,
unsigned V_142 ,
unsigned V_143 )
{
unsigned V_144 = V_140 / V_141 ;
if ( V_144 < V_142 )
V_144 = V_142 ;
if ( ( V_140 / V_144 ) > V_141 )
V_144 += 1 ;
if ( V_144 > V_143 && V_144 % 2 )
V_144 += 1 ;
return V_144 ;
}
int F_66 ( struct V_1 * V_2 ,
unsigned V_145 , unsigned V_146 ,
unsigned V_147 , unsigned V_148 ,
unsigned V_149 , unsigned V_150 ,
unsigned V_142 , unsigned V_151 ,
unsigned V_143 ,
unsigned * V_152 ,
unsigned * V_153 ,
unsigned * V_154 )
{
unsigned V_140 , V_155 = V_2 -> clock . V_156 . V_157 ;
unsigned V_158 = ~ 0 ;
V_147 = F_32 ( F_32 ( V_147 , V_145 ) , V_146 ) ;
for ( V_140 = V_147 ; V_140 <= V_148 ; V_140 += 100 ) {
T_3 V_159 = ( T_3 ) V_140 * V_149 ;
unsigned V_160 , V_161 , V_162 ;
F_67 ( V_159 , V_155 ) ;
if ( V_159 > V_150 )
break;
V_159 &= V_150 ;
V_160 = F_65 ( V_140 , V_145 ,
V_142 , V_143 ) ;
if ( V_160 > V_151 )
break;
V_161 = F_65 ( V_140 , V_146 ,
V_142 , V_143 ) ;
if ( V_160 > V_151 )
break;
V_162 = V_145 - ( V_140 / V_160 ) + V_146 - ( V_140 / V_161 ) ;
if ( V_162 < V_158 ) {
* V_152 = V_159 ;
* V_153 = V_160 ;
* V_154 = V_161 ;
V_158 = V_162 ;
if ( V_158 == 0 )
break;
}
}
if ( V_158 == ~ 0 )
return - V_39 ;
return 0 ;
}
int F_68 ( struct V_1 * V_2 ,
unsigned V_163 )
{
unsigned V_5 ;
F_69 ( V_163 , 0 , ~ V_164 ) ;
F_70 ( 10 ) ;
F_69 ( V_163 , V_164 , ~ V_164 ) ;
for ( V_5 = 0 ; V_5 < 100 ; ++ V_5 ) {
T_1 V_165 = V_166 | V_167 ;
if ( ( F_71 ( V_163 ) & V_165 ) == V_165 )
break;
F_70 ( 10 ) ;
}
F_69 ( V_163 , 0 , ~ V_164 ) ;
if ( V_5 == 100 ) {
F_27 ( L_28 ) ;
return - V_168 ;
}
return 0 ;
}
