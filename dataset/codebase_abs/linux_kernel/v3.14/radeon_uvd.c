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
case V_33 :
V_4 = V_34 ;
break;
case V_35 :
case V_36 :
case V_37 :
case V_38 :
V_4 = V_39 ;
break;
default:
return - V_40 ;
}
V_6 = F_3 ( & V_2 -> V_41 , V_4 , V_2 -> V_42 ) ;
if ( V_6 ) {
F_4 ( V_2 -> V_42 , L_1 ,
V_4 ) ;
return V_6 ;
}
V_3 = F_5 ( V_2 -> V_41 -> V_43 + 8 ) +
V_44 + V_45 ;
V_6 = F_6 ( V_2 , V_3 , V_46 , true ,
V_47 , NULL , & V_2 -> V_7 . V_48 ) ;
if ( V_6 ) {
F_4 ( V_2 -> V_42 , L_2 , V_6 ) ;
return V_6 ;
}
V_6 = F_7 ( V_2 -> V_7 . V_48 , false ) ;
if ( V_6 ) {
F_8 ( & V_2 -> V_7 . V_48 ) ;
F_4 ( V_2 -> V_42 , L_3 , V_6 ) ;
return V_6 ;
}
V_6 = F_9 ( V_2 -> V_7 . V_48 , V_47 ,
& V_2 -> V_7 . V_49 ) ;
if ( V_6 ) {
F_10 ( V_2 -> V_7 . V_48 ) ;
F_8 ( & V_2 -> V_7 . V_48 ) ;
F_4 ( V_2 -> V_42 , L_4 , V_6 ) ;
return V_6 ;
}
V_6 = F_11 ( V_2 -> V_7 . V_48 , & V_2 -> V_7 . V_50 ) ;
if ( V_6 ) {
F_4 ( V_2 -> V_42 , L_5 , V_6 ) ;
return V_6 ;
}
F_10 ( V_2 -> V_7 . V_48 ) ;
for ( V_5 = 0 ; V_5 < V_51 ; ++ V_5 ) {
F_12 ( & V_2 -> V_7 . V_52 [ V_5 ] , 0 ) ;
V_2 -> V_7 . V_53 [ V_5 ] = NULL ;
V_2 -> V_7 . V_54 [ V_5 ] = 0 ;
}
return 0 ;
}
void F_13 ( struct V_1 * V_2 )
{
int V_6 ;
if ( V_2 -> V_7 . V_48 == NULL )
return;
V_6 = F_7 ( V_2 -> V_7 . V_48 , false ) ;
if ( ! V_6 ) {
F_14 ( V_2 -> V_7 . V_48 ) ;
F_15 ( V_2 -> V_7 . V_48 ) ;
F_10 ( V_2 -> V_7 . V_48 ) ;
}
F_8 ( & V_2 -> V_7 . V_48 ) ;
F_16 ( V_2 , & V_2 -> V_55 [ V_56 ] ) ;
F_17 ( V_2 -> V_41 ) ;
}
int F_18 ( struct V_1 * V_2 )
{
unsigned V_43 ;
void * V_57 ;
int V_5 ;
if ( V_2 -> V_7 . V_48 == NULL )
return 0 ;
for ( V_5 = 0 ; V_5 < V_51 ; ++ V_5 )
if ( F_19 ( & V_2 -> V_7 . V_52 [ V_5 ] ) )
break;
if ( V_5 == V_51 )
return 0 ;
V_43 = F_20 ( V_2 -> V_7 . V_48 ) ;
V_43 -= V_2 -> V_41 -> V_43 ;
V_57 = V_2 -> V_7 . V_50 ;
V_57 += V_2 -> V_41 -> V_43 ;
V_2 -> V_7 . V_58 = F_21 ( V_43 , V_59 ) ;
memcpy ( V_2 -> V_7 . V_58 , V_57 , V_43 ) ;
return 0 ;
}
int F_22 ( struct V_1 * V_2 )
{
unsigned V_43 ;
void * V_57 ;
if ( V_2 -> V_7 . V_48 == NULL )
return - V_40 ;
memcpy ( V_2 -> V_7 . V_50 , V_2 -> V_41 -> V_60 , V_2 -> V_41 -> V_43 ) ;
V_43 = F_20 ( V_2 -> V_7 . V_48 ) ;
V_43 -= V_2 -> V_41 -> V_43 ;
V_57 = V_2 -> V_7 . V_50 ;
V_57 += V_2 -> V_41 -> V_43 ;
if ( V_2 -> V_7 . V_58 != NULL ) {
memcpy ( V_57 , V_2 -> V_7 . V_58 , V_43 ) ;
F_23 ( V_2 -> V_7 . V_58 ) ;
V_2 -> V_7 . V_58 = NULL ;
} else
memset ( V_57 , 0 , V_43 ) ;
return 0 ;
}
void F_24 ( struct V_61 * V_62 )
{
V_62 -> V_63 . V_64 = 0 >> V_65 ;
V_62 -> V_63 . V_66 = ( 256 * 1024 * 1024 ) >> V_65 ;
}
void F_25 ( struct V_1 * V_2 , struct V_67 * V_53 )
{
int V_5 , V_6 ;
for ( V_5 = 0 ; V_5 < V_51 ; ++ V_5 ) {
T_1 V_68 = F_19 ( & V_2 -> V_7 . V_52 [ V_5 ] ) ;
if ( V_68 != 0 && V_2 -> V_7 . V_53 [ V_5 ] == V_53 ) {
struct V_69 * V_70 ;
F_26 ( V_2 ) ;
V_6 = F_27 ( V_2 ,
V_56 , V_68 , & V_70 ) ;
if ( V_6 ) {
F_28 ( L_6 , V_6 ) ;
continue;
}
F_29 ( V_70 , false ) ;
F_30 ( & V_70 ) ;
V_2 -> V_7 . V_53 [ V_5 ] = NULL ;
F_12 ( & V_2 -> V_7 . V_52 [ V_5 ] , 0 ) ;
}
}
}
static int F_31 ( T_1 * V_71 , unsigned V_72 [] )
{
unsigned V_73 = V_71 [ 4 ] ;
unsigned V_74 = V_71 [ 6 ] ;
unsigned V_75 = V_71 [ 7 ] ;
unsigned V_76 = V_71 [ 9 ] ;
unsigned V_77 = V_71 [ 28 ] ;
unsigned V_78 = V_74 / 16 ;
unsigned V_79 = F_32 ( V_75 / 16 , 2 ) ;
unsigned V_80 , V_81 , V_82 ;
V_80 = V_74 * V_75 ;
V_80 += V_80 / 2 ;
V_80 = F_32 ( V_80 , 1024 ) ;
switch ( V_73 ) {
case 0 :
V_82 = V_80 * 17 ;
V_82 += V_78 * V_79 * 17 * 192 ;
V_82 += V_78 * V_79 * 32 ;
break;
case 1 :
V_82 = V_80 * 3 ;
V_82 += V_78 * V_79 * 128 ;
V_82 += V_78 * 64 ;
V_82 += V_78 * 128 ;
V_81 = F_33 ( V_78 , V_79 ) ;
V_82 += F_32 ( V_81 * 7 * 16 , 64 ) ;
break;
case 3 :
V_82 = V_80 * 3 ;
break;
case 4 :
V_82 = V_80 * 3 ;
V_82 += V_78 * V_79 * 64 ;
V_82 += F_32 ( V_78 * V_79 * 32 , 64 ) ;
break;
default:
F_28 ( L_7 , V_73 ) ;
return - V_40 ;
}
if ( V_74 > V_77 ) {
F_28 ( L_8 ) ;
return - V_40 ;
}
if ( V_76 < V_82 ) {
F_28 ( L_9 ,
V_76 , V_82 ) ;
return - V_40 ;
}
V_72 [ 0x1 ] = V_76 ;
V_72 [ 0x2 ] = V_80 ;
return 0 ;
}
static int F_34 ( struct V_83 * V_84 , struct V_61 * V_85 ,
unsigned V_86 , unsigned V_72 [] )
{
T_2 * V_71 , V_87 , V_68 ;
unsigned V_54 = 0 ;
void * V_57 ;
int V_5 , V_6 ;
if ( V_86 & 0x3F ) {
F_28 ( L_10 ) ;
return - V_40 ;
}
if ( V_85 -> V_88 . V_89 ) {
V_6 = F_29 ( V_85 -> V_88 . V_89 , false ) ;
if ( V_6 ) {
F_28 ( L_11 , V_6 ) ;
return V_6 ;
}
}
V_6 = F_11 ( V_85 , & V_57 ) ;
if ( V_6 ) {
F_28 ( L_12 , V_6 ) ;
return V_6 ;
}
V_71 = V_57 + V_86 ;
V_87 = V_71 [ 1 ] ;
V_68 = V_71 [ 2 ] ;
if ( V_68 == 0 ) {
F_28 ( L_13 ) ;
return - V_40 ;
}
if ( V_87 == 1 ) {
V_6 = F_31 ( V_71 , V_72 ) ;
V_54 = V_71 [ 6 ] * V_71 [ 7 ] ;
F_14 ( V_85 ) ;
if ( V_6 )
return V_6 ;
} else if ( V_87 == 2 ) {
for ( V_5 = 0 ; V_5 < V_51 ; ++ V_5 )
F_35 ( & V_84 -> V_2 -> V_7 . V_52 [ V_5 ] , V_68 , 0 ) ;
F_14 ( V_85 ) ;
return 0 ;
} else {
V_54 = V_71 [ 7 ] * V_71 [ 8 ] ;
F_14 ( V_85 ) ;
if ( V_87 != 0 ) {
F_28 ( L_14 , V_87 ) ;
return - V_40 ;
}
}
for ( V_5 = 0 ; V_5 < V_51 ; ++ V_5 ) {
if ( F_19 ( & V_84 -> V_2 -> V_7 . V_52 [ V_5 ] ) == V_68 )
return 0 ;
}
for ( V_5 = 0 ; V_5 < V_51 ; ++ V_5 ) {
if ( ! F_35 ( & V_84 -> V_2 -> V_7 . V_52 [ V_5 ] , 0 , V_68 ) ) {
V_84 -> V_2 -> V_7 . V_53 [ V_5 ] = V_84 -> V_53 ;
V_84 -> V_2 -> V_7 . V_54 [ V_5 ] = V_54 ;
return 0 ;
}
}
F_28 ( L_15 ) ;
return - V_40 ;
}
static int F_36 ( struct V_83 * V_84 ,
int V_90 , int V_91 ,
unsigned V_72 [] , bool * V_92 )
{
struct V_93 * V_94 ;
struct V_95 * V_96 ;
unsigned V_97 , V_98 , V_86 ;
T_3 V_99 , V_100 ;
int V_6 ;
V_94 = & V_84 -> V_101 [ V_84 -> V_102 ] ;
V_86 = F_37 ( V_84 , V_90 ) ;
V_97 = F_37 ( V_84 , V_91 ) ;
if ( V_97 >= V_94 -> V_103 ) {
F_28 ( L_16 ,
V_97 , V_94 -> V_103 ) ;
return - V_40 ;
}
V_96 = V_84 -> V_104 [ ( V_97 / 4 ) ] ;
V_99 = V_96 -> V_105 . V_106 ;
V_100 = V_99 + F_20 ( V_96 -> V_107 ) ;
V_99 += V_86 ;
V_84 -> V_108 . V_57 [ V_90 ] = V_99 & 0xFFFFFFFF ;
V_84 -> V_108 . V_57 [ V_91 ] = V_99 >> 32 ;
V_98 = F_37 ( V_84 , V_84 -> V_97 ) >> 1 ;
if ( V_98 < 0x4 ) {
if ( ( V_100 - V_99 ) < V_72 [ V_98 ] ) {
F_28 ( L_17 , V_98 ,
( unsigned ) ( V_100 - V_99 ) , V_72 [ V_98 ] ) ;
return - V_40 ;
}
} else if ( V_98 != 0x100 ) {
F_28 ( L_18 , V_98 ) ;
return - V_40 ;
}
if ( ( V_99 >> 28 ) != ( ( V_100 - 1 ) >> 28 ) ) {
F_28 ( L_19 ,
V_99 , V_100 ) ;
return - V_40 ;
}
if ( ( V_98 == 0 || V_98 == 0x3 ) &&
( V_99 >> 28 ) != ( V_84 -> V_2 -> V_7 . V_49 >> 28 ) ) {
F_28 ( L_20 ,
V_99 , V_100 ) ;
return - V_40 ;
}
if ( V_98 == 0 ) {
if ( * V_92 ) {
F_28 ( L_21 ) ;
return - V_40 ;
}
* V_92 = true ;
V_6 = F_34 ( V_84 , V_96 -> V_107 , V_86 , V_72 ) ;
if ( V_6 )
return V_6 ;
} else if ( ! * V_92 ) {
F_28 ( L_22 ) ;
return - V_40 ;
}
return 0 ;
}
static int F_38 ( struct V_83 * V_84 ,
struct V_109 * V_110 ,
int * V_90 , int * V_91 ,
unsigned V_72 [] ,
bool * V_92 )
{
int V_5 , V_6 ;
V_84 -> V_97 ++ ;
for ( V_5 = 0 ; V_5 <= V_110 -> V_111 ; ++ V_5 ) {
switch ( V_110 -> V_112 + V_5 * 4 ) {
case V_113 :
* V_90 = V_84 -> V_97 ;
break;
case V_114 :
* V_91 = V_84 -> V_97 ;
break;
case V_115 :
V_6 = F_36 ( V_84 , * V_90 , * V_91 ,
V_72 , V_92 ) ;
if ( V_6 )
return V_6 ;
break;
case V_116 :
break;
default:
F_28 ( L_23 ,
V_110 -> V_112 + V_5 * 4 ) ;
return - V_40 ;
}
V_84 -> V_97 ++ ;
}
return 0 ;
}
int F_39 ( struct V_83 * V_84 )
{
struct V_109 V_110 ;
int V_6 , V_90 = 0 , V_91 = 0 ;
bool V_92 = false ;
unsigned V_72 [] = {
[ 0x00000000 ] = 2048 ,
[ 0x00000001 ] = 32 * 1024 * 1024 ,
[ 0x00000002 ] = 2048 * 1152 * 3 ,
[ 0x00000003 ] = 2048 ,
} ;
if ( V_84 -> V_101 [ V_84 -> V_117 ] . V_103 % 16 ) {
F_28 ( L_24 ,
V_84 -> V_101 [ V_84 -> V_117 ] . V_103 ) ;
return - V_40 ;
}
if ( V_84 -> V_102 == - 1 ) {
F_28 ( L_25 ) ;
return - V_40 ;
}
do {
V_6 = F_40 ( V_84 , & V_110 , V_84 -> V_97 ) ;
if ( V_6 )
return V_6 ;
switch ( V_110 . type ) {
case V_118 :
V_6 = F_38 ( V_84 , & V_110 , & V_90 , & V_91 ,
V_72 , & V_92 ) ;
if ( V_6 )
return V_6 ;
break;
case V_119 :
V_84 -> V_97 += V_110 . V_111 + 2 ;
break;
default:
F_28 ( L_26 , V_110 . type ) ;
return - V_40 ;
}
} while ( V_84 -> V_97 < V_84 -> V_101 [ V_84 -> V_117 ] . V_103 );
if ( ! V_92 ) {
F_28 ( L_27 ) ;
return - V_40 ;
}
return 0 ;
}
static int F_41 ( struct V_1 * V_2 ,
int V_55 , struct V_61 * V_85 ,
struct V_69 * * V_70 )
{
struct V_120 V_121 ;
struct V_122 V_123 ;
struct V_124 V_125 ;
struct V_126 V_108 ;
T_3 V_127 ;
int V_5 , V_6 ;
memset ( & V_121 , 0 , sizeof( V_121 ) ) ;
V_121 . V_85 = & V_85 -> V_88 ;
F_42 ( & V_125 ) ;
F_43 ( & V_121 . V_125 , & V_125 ) ;
V_6 = F_44 ( & V_123 , & V_125 ) ;
if ( V_6 )
return V_6 ;
F_45 ( V_85 , V_47 ) ;
F_24 ( V_85 ) ;
V_6 = F_46 ( & V_85 -> V_88 , & V_85 -> V_63 , true , false ) ;
if ( V_6 )
goto V_128;
V_6 = F_47 ( V_2 , V_55 , & V_108 , NULL , 64 ) ;
if ( V_6 )
goto V_128;
V_127 = F_48 ( V_85 ) ;
V_108 . V_57 [ 0 ] = F_49 ( V_113 , 0 ) ;
V_108 . V_57 [ 1 ] = V_127 ;
V_108 . V_57 [ 2 ] = F_49 ( V_114 , 0 ) ;
V_108 . V_57 [ 3 ] = V_127 >> 32 ;
V_108 . V_57 [ 4 ] = F_49 ( V_115 , 0 ) ;
V_108 . V_57 [ 5 ] = 0 ;
for ( V_5 = 6 ; V_5 < 16 ; ++ V_5 )
V_108 . V_57 [ V_5 ] = F_50 ( 0 ) ;
V_108 . V_103 = 16 ;
V_6 = F_51 ( V_2 , & V_108 , NULL ) ;
if ( V_6 )
goto V_128;
F_52 ( & V_123 , & V_125 , V_108 . V_70 ) ;
if ( V_70 )
* V_70 = F_53 ( V_108 . V_70 ) ;
F_54 ( V_2 , & V_108 ) ;
F_8 ( & V_85 ) ;
return 0 ;
V_128:
F_55 ( & V_123 , & V_125 ) ;
return V_6 ;
}
int F_56 ( struct V_1 * V_2 , int V_55 ,
T_1 V_68 , struct V_69 * * V_70 )
{
struct V_61 * V_85 ;
T_1 * V_71 ;
int V_6 , V_5 ;
V_6 = F_6 ( V_2 , 1024 , V_46 , true ,
V_47 , NULL , & V_85 ) ;
if ( V_6 )
return V_6 ;
V_6 = F_7 ( V_85 , false ) ;
if ( V_6 ) {
F_8 ( & V_85 ) ;
return V_6 ;
}
V_6 = F_11 ( V_85 , ( void * * ) & V_71 ) ;
if ( V_6 ) {
F_10 ( V_85 ) ;
F_8 ( & V_85 ) ;
return V_6 ;
}
V_71 [ 0 ] = F_57 ( 0x00000de4 ) ;
V_71 [ 1 ] = F_57 ( 0x00000000 ) ;
V_71 [ 2 ] = F_57 ( V_68 ) ;
V_71 [ 3 ] = F_57 ( 0x00000000 ) ;
V_71 [ 4 ] = F_57 ( 0x00000000 ) ;
V_71 [ 5 ] = F_57 ( 0x00000000 ) ;
V_71 [ 6 ] = F_57 ( 0x00000000 ) ;
V_71 [ 7 ] = F_57 ( 0x00000780 ) ;
V_71 [ 8 ] = F_57 ( 0x00000440 ) ;
V_71 [ 9 ] = F_57 ( 0x00000000 ) ;
V_71 [ 10 ] = F_57 ( 0x01b37000 ) ;
for ( V_5 = 11 ; V_5 < 1024 ; ++ V_5 )
V_71 [ V_5 ] = F_57 ( 0x0 ) ;
F_14 ( V_85 ) ;
F_10 ( V_85 ) ;
return F_41 ( V_2 , V_55 , V_85 , V_70 ) ;
}
int F_27 ( struct V_1 * V_2 , int V_55 ,
T_1 V_68 , struct V_69 * * V_70 )
{
struct V_61 * V_85 ;
T_1 * V_71 ;
int V_6 , V_5 ;
V_6 = F_6 ( V_2 , 1024 , V_46 , true ,
V_47 , NULL , & V_85 ) ;
if ( V_6 )
return V_6 ;
V_6 = F_7 ( V_85 , false ) ;
if ( V_6 ) {
F_8 ( & V_85 ) ;
return V_6 ;
}
V_6 = F_11 ( V_85 , ( void * * ) & V_71 ) ;
if ( V_6 ) {
F_10 ( V_85 ) ;
F_8 ( & V_85 ) ;
return V_6 ;
}
V_71 [ 0 ] = F_57 ( 0x00000de4 ) ;
V_71 [ 1 ] = F_57 ( 0x00000002 ) ;
V_71 [ 2 ] = F_57 ( V_68 ) ;
V_71 [ 3 ] = F_57 ( 0x00000000 ) ;
for ( V_5 = 4 ; V_5 < 1024 ; ++ V_5 )
V_71 [ V_5 ] = F_57 ( 0x0 ) ;
F_14 ( V_85 ) ;
F_10 ( V_85 ) ;
return F_41 ( V_2 , V_55 , V_85 , V_70 ) ;
}
static void F_58 ( struct V_1 * V_2 ,
unsigned * V_129 , unsigned * V_130 )
{
unsigned V_5 ;
* V_129 = 0 ;
* V_130 = 0 ;
for ( V_5 = 0 ; V_5 < V_51 ; ++ V_5 ) {
if ( ! F_19 ( & V_2 -> V_7 . V_52 [ V_5 ] ) )
continue;
if ( V_2 -> V_7 . V_54 [ V_5 ] >= 720 * 576 )
++ ( * V_130 ) ;
else
++ ( * V_129 ) ;
}
}
static void V_9 ( struct V_131 * V_132 )
{
struct V_1 * V_2 =
F_59 ( V_132 , struct V_1 , V_7 . V_8 . V_132 ) ;
if ( F_60 ( V_2 , V_56 ) == 0 ) {
if ( ( V_2 -> V_133 . V_134 == V_135 ) && V_2 -> V_133 . V_136 ) {
F_58 ( V_2 , & V_2 -> V_133 . V_137 . V_129 ,
& V_2 -> V_133 . V_137 . V_130 ) ;
F_61 ( V_2 , false ) ;
} else {
F_62 ( V_2 , 0 , 0 ) ;
}
} else {
F_63 ( & V_2 -> V_7 . V_8 ,
F_64 ( V_138 ) ) ;
}
}
void F_26 ( struct V_1 * V_2 )
{
bool V_139 = false ;
bool V_140 = ! F_65 ( & V_2 -> V_7 . V_8 ) ;
V_140 &= F_63 ( & V_2 -> V_7 . V_8 ,
F_64 ( V_138 ) ) ;
if ( ( V_2 -> V_133 . V_134 == V_135 ) && V_2 -> V_133 . V_136 ) {
unsigned V_130 = 0 , V_129 = 0 ;
F_58 ( V_2 , & V_129 , & V_130 ) ;
if ( ( V_2 -> V_133 . V_137 . V_129 != V_129 ) ||
( V_2 -> V_133 . V_137 . V_130 != V_130 ) ) {
V_2 -> V_133 . V_137 . V_129 = V_129 ;
V_2 -> V_133 . V_137 . V_130 = V_130 ;
}
}
if ( V_140 || V_139 ) {
if ( ( V_2 -> V_133 . V_134 == V_135 ) && V_2 -> V_133 . V_136 ) {
F_61 ( V_2 , true ) ;
} else {
F_62 ( V_2 , 53300 , 40000 ) ;
}
}
}
static unsigned F_66 ( unsigned V_141 ,
unsigned V_142 ,
unsigned V_143 ,
unsigned V_144 )
{
unsigned V_145 = V_141 / V_142 ;
if ( V_145 < V_143 )
V_145 = V_143 ;
if ( ( V_141 / V_145 ) > V_142 )
V_145 += 1 ;
if ( V_145 > V_144 && V_145 % 2 )
V_145 += 1 ;
return V_145 ;
}
int F_67 ( struct V_1 * V_2 ,
unsigned V_146 , unsigned V_147 ,
unsigned V_148 , unsigned V_149 ,
unsigned V_150 , unsigned V_151 ,
unsigned V_143 , unsigned V_152 ,
unsigned V_144 ,
unsigned * V_153 ,
unsigned * V_154 ,
unsigned * V_155 )
{
unsigned V_141 , V_156 = V_2 -> clock . V_157 . V_158 ;
unsigned V_159 = ~ 0 ;
V_148 = F_33 ( F_33 ( V_148 , V_146 ) , V_147 ) ;
for ( V_141 = V_148 ; V_141 <= V_149 ; V_141 += 100 ) {
T_3 V_160 = ( T_3 ) V_141 * V_150 ;
unsigned V_161 , V_162 , V_163 ;
F_68 ( V_160 , V_156 ) ;
if ( V_160 > V_151 )
break;
V_160 &= V_151 ;
V_161 = F_66 ( V_141 , V_146 ,
V_143 , V_144 ) ;
if ( V_161 > V_152 )
break;
V_162 = F_66 ( V_141 , V_147 ,
V_143 , V_144 ) ;
if ( V_161 > V_152 )
break;
V_163 = V_146 - ( V_141 / V_161 ) + V_147 - ( V_141 / V_162 ) ;
if ( V_163 < V_159 ) {
* V_153 = V_160 ;
* V_154 = V_161 ;
* V_155 = V_162 ;
V_159 = V_163 ;
if ( V_159 == 0 )
break;
}
}
if ( V_159 == ~ 0 )
return - V_40 ;
return 0 ;
}
int F_69 ( struct V_1 * V_2 ,
unsigned V_164 )
{
unsigned V_5 ;
F_70 ( V_164 , 0 , ~ V_165 ) ;
F_71 ( 10 ) ;
F_70 ( V_164 , V_165 , ~ V_165 ) ;
for ( V_5 = 0 ; V_5 < 100 ; ++ V_5 ) {
T_1 V_166 = V_167 | V_168 ;
if ( ( F_72 ( V_164 ) & V_166 ) == V_166 )
break;
F_71 ( 10 ) ;
}
F_70 ( V_164 , 0 , ~ V_165 ) ;
if ( V_5 == 100 ) {
F_28 ( L_28 ) ;
return - V_169 ;
}
return 0 ;
}
