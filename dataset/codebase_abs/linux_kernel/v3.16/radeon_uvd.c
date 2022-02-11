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
case V_39 :
V_4 = V_40 ;
break;
default:
return - V_41 ;
}
V_6 = F_3 ( & V_2 -> V_42 , V_4 , V_2 -> V_43 ) ;
if ( V_6 ) {
F_4 ( V_2 -> V_43 , L_1 ,
V_4 ) ;
return V_6 ;
}
V_3 = F_5 ( V_2 -> V_42 -> V_44 + 8 ) +
V_45 + V_46 ;
V_6 = F_6 ( V_2 , V_3 , V_47 , true ,
V_48 , NULL , & V_2 -> V_7 . V_49 ) ;
if ( V_6 ) {
F_4 ( V_2 -> V_43 , L_2 , V_6 ) ;
return V_6 ;
}
V_6 = F_7 ( V_2 -> V_7 . V_49 , false ) ;
if ( V_6 ) {
F_8 ( & V_2 -> V_7 . V_49 ) ;
F_4 ( V_2 -> V_43 , L_3 , V_6 ) ;
return V_6 ;
}
V_6 = F_9 ( V_2 -> V_7 . V_49 , V_48 ,
& V_2 -> V_7 . V_50 ) ;
if ( V_6 ) {
F_10 ( V_2 -> V_7 . V_49 ) ;
F_8 ( & V_2 -> V_7 . V_49 ) ;
F_4 ( V_2 -> V_43 , L_4 , V_6 ) ;
return V_6 ;
}
V_6 = F_11 ( V_2 -> V_7 . V_49 , & V_2 -> V_7 . V_51 ) ;
if ( V_6 ) {
F_4 ( V_2 -> V_43 , L_5 , V_6 ) ;
return V_6 ;
}
F_10 ( V_2 -> V_7 . V_49 ) ;
for ( V_5 = 0 ; V_5 < V_52 ; ++ V_5 ) {
F_12 ( & V_2 -> V_7 . V_53 [ V_5 ] , 0 ) ;
V_2 -> V_7 . V_54 [ V_5 ] = NULL ;
V_2 -> V_7 . V_55 [ V_5 ] = 0 ;
}
return 0 ;
}
void F_13 ( struct V_1 * V_2 )
{
int V_6 ;
if ( V_2 -> V_7 . V_49 == NULL )
return;
V_6 = F_7 ( V_2 -> V_7 . V_49 , false ) ;
if ( ! V_6 ) {
F_14 ( V_2 -> V_7 . V_49 ) ;
F_15 ( V_2 -> V_7 . V_49 ) ;
F_10 ( V_2 -> V_7 . V_49 ) ;
}
F_8 ( & V_2 -> V_7 . V_49 ) ;
F_16 ( V_2 , & V_2 -> V_56 [ V_57 ] ) ;
F_17 ( V_2 -> V_42 ) ;
}
int F_18 ( struct V_1 * V_2 )
{
unsigned V_44 ;
void * V_58 ;
int V_5 ;
if ( V_2 -> V_7 . V_49 == NULL )
return 0 ;
for ( V_5 = 0 ; V_5 < V_52 ; ++ V_5 )
if ( F_19 ( & V_2 -> V_7 . V_53 [ V_5 ] ) )
break;
if ( V_5 == V_52 )
return 0 ;
V_44 = F_20 ( V_2 -> V_7 . V_49 ) ;
V_44 -= V_2 -> V_42 -> V_44 ;
V_58 = V_2 -> V_7 . V_51 ;
V_58 += V_2 -> V_42 -> V_44 ;
V_2 -> V_7 . V_59 = F_21 ( V_44 , V_60 ) ;
memcpy ( V_2 -> V_7 . V_59 , V_58 , V_44 ) ;
return 0 ;
}
int F_22 ( struct V_1 * V_2 )
{
unsigned V_44 ;
void * V_58 ;
if ( V_2 -> V_7 . V_49 == NULL )
return - V_41 ;
memcpy ( V_2 -> V_7 . V_51 , V_2 -> V_42 -> V_61 , V_2 -> V_42 -> V_44 ) ;
V_44 = F_20 ( V_2 -> V_7 . V_49 ) ;
V_44 -= V_2 -> V_42 -> V_44 ;
V_58 = V_2 -> V_7 . V_51 ;
V_58 += V_2 -> V_42 -> V_44 ;
if ( V_2 -> V_7 . V_59 != NULL ) {
memcpy ( V_58 , V_2 -> V_7 . V_59 , V_44 ) ;
F_23 ( V_2 -> V_7 . V_59 ) ;
V_2 -> V_7 . V_59 = NULL ;
} else
memset ( V_58 , 0 , V_44 ) ;
return 0 ;
}
void F_24 ( struct V_62 * V_63 )
{
V_63 -> V_64 . V_65 = 0 >> V_66 ;
V_63 -> V_64 . V_67 = ( 256 * 1024 * 1024 ) >> V_66 ;
}
void F_25 ( struct V_1 * V_2 , struct V_68 * V_54 )
{
int V_5 , V_6 ;
for ( V_5 = 0 ; V_5 < V_52 ; ++ V_5 ) {
T_1 V_69 = F_19 ( & V_2 -> V_7 . V_53 [ V_5 ] ) ;
if ( V_69 != 0 && V_2 -> V_7 . V_54 [ V_5 ] == V_54 ) {
struct V_70 * V_71 ;
F_26 ( V_2 ) ;
V_6 = F_27 ( V_2 ,
V_57 , V_69 , & V_71 ) ;
if ( V_6 ) {
F_28 ( L_6 , V_6 ) ;
continue;
}
F_29 ( V_71 , false ) ;
F_30 ( & V_71 ) ;
V_2 -> V_7 . V_54 [ V_5 ] = NULL ;
F_12 ( & V_2 -> V_7 . V_53 [ V_5 ] , 0 ) ;
}
}
}
static int F_31 ( T_1 * V_72 , unsigned V_73 [] )
{
unsigned V_74 = V_72 [ 4 ] ;
unsigned V_75 = V_72 [ 6 ] ;
unsigned V_76 = V_72 [ 7 ] ;
unsigned V_77 = V_72 [ 9 ] ;
unsigned V_78 = V_72 [ 28 ] ;
unsigned V_79 = V_75 / 16 ;
unsigned V_80 = F_32 ( V_76 / 16 , 2 ) ;
unsigned V_81 , V_82 , V_83 ;
V_81 = V_75 * V_76 ;
V_81 += V_81 / 2 ;
V_81 = F_32 ( V_81 , 1024 ) ;
switch ( V_74 ) {
case 0 :
V_83 = V_81 * 17 ;
V_83 += V_79 * V_80 * 17 * 192 ;
V_83 += V_79 * V_80 * 32 ;
break;
case 1 :
V_83 = V_81 * 3 ;
V_83 += V_79 * V_80 * 128 ;
V_83 += V_79 * 64 ;
V_83 += V_79 * 128 ;
V_82 = F_33 ( V_79 , V_80 ) ;
V_83 += F_32 ( V_82 * 7 * 16 , 64 ) ;
break;
case 3 :
V_83 = V_81 * 3 ;
break;
case 4 :
V_83 = V_81 * 3 ;
V_83 += V_79 * V_80 * 64 ;
V_83 += F_32 ( V_79 * V_80 * 32 , 64 ) ;
break;
default:
F_28 ( L_7 , V_74 ) ;
return - V_41 ;
}
if ( V_75 > V_78 ) {
F_28 ( L_8 ) ;
return - V_41 ;
}
if ( V_77 < V_83 ) {
F_28 ( L_9 ,
V_77 , V_83 ) ;
return - V_41 ;
}
V_73 [ 0x1 ] = V_77 ;
V_73 [ 0x2 ] = V_81 ;
return 0 ;
}
static int F_34 ( struct V_84 * V_85 , struct V_62 * V_86 ,
unsigned V_87 , unsigned V_73 [] )
{
T_2 * V_72 , V_88 , V_69 ;
unsigned V_55 = 0 ;
void * V_58 ;
int V_5 , V_6 ;
if ( V_87 & 0x3F ) {
F_28 ( L_10 ) ;
return - V_41 ;
}
if ( V_86 -> V_89 . V_90 ) {
V_6 = F_29 ( V_86 -> V_89 . V_90 , false ) ;
if ( V_6 ) {
F_28 ( L_11 , V_6 ) ;
return V_6 ;
}
}
V_6 = F_11 ( V_86 , & V_58 ) ;
if ( V_6 ) {
F_28 ( L_12 , V_6 ) ;
return V_6 ;
}
V_72 = V_58 + V_87 ;
V_88 = V_72 [ 1 ] ;
V_69 = V_72 [ 2 ] ;
if ( V_69 == 0 ) {
F_28 ( L_13 ) ;
return - V_41 ;
}
if ( V_88 == 1 ) {
V_6 = F_31 ( V_72 , V_73 ) ;
V_55 = V_72 [ 6 ] * V_72 [ 7 ] ;
F_14 ( V_86 ) ;
if ( V_6 )
return V_6 ;
} else if ( V_88 == 2 ) {
for ( V_5 = 0 ; V_5 < V_52 ; ++ V_5 )
F_35 ( & V_85 -> V_2 -> V_7 . V_53 [ V_5 ] , V_69 , 0 ) ;
F_14 ( V_86 ) ;
return 0 ;
} else {
V_55 = V_72 [ 7 ] * V_72 [ 8 ] ;
F_14 ( V_86 ) ;
if ( V_88 != 0 ) {
F_28 ( L_14 , V_88 ) ;
return - V_41 ;
}
}
for ( V_5 = 0 ; V_5 < V_52 ; ++ V_5 ) {
if ( F_19 ( & V_85 -> V_2 -> V_7 . V_53 [ V_5 ] ) == V_69 )
return 0 ;
}
for ( V_5 = 0 ; V_5 < V_52 ; ++ V_5 ) {
if ( ! F_35 ( & V_85 -> V_2 -> V_7 . V_53 [ V_5 ] , 0 , V_69 ) ) {
V_85 -> V_2 -> V_7 . V_54 [ V_5 ] = V_85 -> V_54 ;
V_85 -> V_2 -> V_7 . V_55 [ V_5 ] = V_55 ;
return 0 ;
}
}
F_28 ( L_15 ) ;
return - V_41 ;
}
static int F_36 ( struct V_84 * V_85 ,
int V_91 , int V_92 ,
unsigned V_73 [] , bool * V_93 )
{
struct V_94 * V_95 ;
struct V_96 * V_97 ;
unsigned V_98 , V_99 , V_87 ;
T_3 V_100 , V_101 ;
int V_6 ;
V_95 = & V_85 -> V_102 [ V_85 -> V_103 ] ;
V_87 = F_37 ( V_85 , V_91 ) ;
V_98 = F_37 ( V_85 , V_92 ) ;
if ( V_98 >= V_95 -> V_104 ) {
F_28 ( L_16 ,
V_98 , V_95 -> V_104 ) ;
return - V_41 ;
}
V_97 = V_85 -> V_105 [ ( V_98 / 4 ) ] ;
V_100 = V_97 -> V_106 ;
V_101 = V_100 + F_20 ( V_97 -> V_107 ) ;
V_100 += V_87 ;
V_85 -> V_108 . V_58 [ V_91 ] = V_100 & 0xFFFFFFFF ;
V_85 -> V_108 . V_58 [ V_92 ] = V_100 >> 32 ;
V_99 = F_37 ( V_85 , V_85 -> V_98 ) >> 1 ;
if ( V_99 < 0x4 ) {
if ( V_101 <= V_100 ) {
F_28 ( L_17 , V_87 ) ;
return - V_41 ;
}
if ( ( V_101 - V_100 ) < V_73 [ V_99 ] ) {
F_28 ( L_18 , V_99 ,
( unsigned ) ( V_101 - V_100 ) , V_73 [ V_99 ] ) ;
return - V_41 ;
}
} else if ( V_99 != 0x100 ) {
F_28 ( L_19 , V_99 ) ;
return - V_41 ;
}
if ( ( V_100 >> 28 ) != ( ( V_101 - 1 ) >> 28 ) ) {
F_28 ( L_20 ,
V_100 , V_101 ) ;
return - V_41 ;
}
if ( ( V_99 == 0 || V_99 == 0x3 ) &&
( V_100 >> 28 ) != ( V_85 -> V_2 -> V_7 . V_50 >> 28 ) ) {
F_28 ( L_21 ,
V_100 , V_101 ) ;
return - V_41 ;
}
if ( V_99 == 0 ) {
if ( * V_93 ) {
F_28 ( L_22 ) ;
return - V_41 ;
}
* V_93 = true ;
V_6 = F_34 ( V_85 , V_97 -> V_107 , V_87 , V_73 ) ;
if ( V_6 )
return V_6 ;
} else if ( ! * V_93 ) {
F_28 ( L_23 ) ;
return - V_41 ;
}
return 0 ;
}
static int F_38 ( struct V_84 * V_85 ,
struct V_109 * V_110 ,
int * V_91 , int * V_92 ,
unsigned V_73 [] ,
bool * V_93 )
{
int V_5 , V_6 ;
V_85 -> V_98 ++ ;
for ( V_5 = 0 ; V_5 <= V_110 -> V_111 ; ++ V_5 ) {
switch ( V_110 -> V_112 + V_5 * 4 ) {
case V_113 :
* V_91 = V_85 -> V_98 ;
break;
case V_114 :
* V_92 = V_85 -> V_98 ;
break;
case V_115 :
V_6 = F_36 ( V_85 , * V_91 , * V_92 ,
V_73 , V_93 ) ;
if ( V_6 )
return V_6 ;
break;
case V_116 :
break;
default:
F_28 ( L_24 ,
V_110 -> V_112 + V_5 * 4 ) ;
return - V_41 ;
}
V_85 -> V_98 ++ ;
}
return 0 ;
}
int F_39 ( struct V_84 * V_85 )
{
struct V_109 V_110 ;
int V_6 , V_91 = 0 , V_92 = 0 ;
bool V_93 = false ;
unsigned V_73 [] = {
[ 0x00000000 ] = 2048 ,
[ 0x00000001 ] = 32 * 1024 * 1024 ,
[ 0x00000002 ] = 2048 * 1152 * 3 ,
[ 0x00000003 ] = 2048 ,
} ;
if ( V_85 -> V_102 [ V_85 -> V_117 ] . V_104 % 16 ) {
F_28 ( L_25 ,
V_85 -> V_102 [ V_85 -> V_117 ] . V_104 ) ;
return - V_41 ;
}
if ( V_85 -> V_103 == - 1 ) {
F_28 ( L_26 ) ;
return - V_41 ;
}
do {
V_6 = F_40 ( V_85 , & V_110 , V_85 -> V_98 ) ;
if ( V_6 )
return V_6 ;
switch ( V_110 . type ) {
case V_118 :
V_6 = F_38 ( V_85 , & V_110 , & V_91 , & V_92 ,
V_73 , & V_93 ) ;
if ( V_6 )
return V_6 ;
break;
case V_119 :
V_85 -> V_98 += V_110 . V_111 + 2 ;
break;
default:
F_28 ( L_27 , V_110 . type ) ;
return - V_41 ;
}
} while ( V_85 -> V_98 < V_85 -> V_102 [ V_85 -> V_117 ] . V_104 );
if ( ! V_93 ) {
F_28 ( L_28 ) ;
return - V_41 ;
}
return 0 ;
}
static int F_41 ( struct V_1 * V_2 ,
int V_56 , struct V_62 * V_86 ,
struct V_70 * * V_71 )
{
struct V_120 V_121 ;
struct V_122 V_123 ;
struct V_124 V_125 ;
struct V_126 V_108 ;
T_3 V_127 ;
int V_5 , V_6 ;
memset ( & V_121 , 0 , sizeof( V_121 ) ) ;
V_121 . V_86 = & V_86 -> V_89 ;
F_42 ( & V_125 ) ;
F_43 ( & V_121 . V_125 , & V_125 ) ;
V_6 = F_44 ( & V_123 , & V_125 ) ;
if ( V_6 )
return V_6 ;
F_45 ( V_86 , V_48 ) ;
F_24 ( V_86 ) ;
V_6 = F_46 ( & V_86 -> V_89 , & V_86 -> V_64 , true , false ) ;
if ( V_6 )
goto V_128;
V_6 = F_47 ( V_2 , V_56 , & V_108 , NULL , 64 ) ;
if ( V_6 )
goto V_128;
V_127 = F_48 ( V_86 ) ;
V_108 . V_58 [ 0 ] = F_49 ( V_113 , 0 ) ;
V_108 . V_58 [ 1 ] = V_127 ;
V_108 . V_58 [ 2 ] = F_49 ( V_114 , 0 ) ;
V_108 . V_58 [ 3 ] = V_127 >> 32 ;
V_108 . V_58 [ 4 ] = F_49 ( V_115 , 0 ) ;
V_108 . V_58 [ 5 ] = 0 ;
for ( V_5 = 6 ; V_5 < 16 ; ++ V_5 )
V_108 . V_58 [ V_5 ] = F_50 ( 0 ) ;
V_108 . V_104 = 16 ;
V_6 = F_51 ( V_2 , & V_108 , NULL ) ;
if ( V_6 )
goto V_128;
F_52 ( & V_123 , & V_125 , V_108 . V_71 ) ;
if ( V_71 )
* V_71 = F_53 ( V_108 . V_71 ) ;
F_54 ( V_2 , & V_108 ) ;
F_8 ( & V_86 ) ;
return 0 ;
V_128:
F_55 ( & V_123 , & V_125 ) ;
return V_6 ;
}
int F_56 ( struct V_1 * V_2 , int V_56 ,
T_1 V_69 , struct V_70 * * V_71 )
{
struct V_62 * V_86 ;
T_1 * V_72 ;
int V_6 , V_5 ;
V_6 = F_6 ( V_2 , 1024 , V_47 , true ,
V_48 , NULL , & V_86 ) ;
if ( V_6 )
return V_6 ;
V_6 = F_7 ( V_86 , false ) ;
if ( V_6 ) {
F_8 ( & V_86 ) ;
return V_6 ;
}
V_6 = F_11 ( V_86 , ( void * * ) & V_72 ) ;
if ( V_6 ) {
F_10 ( V_86 ) ;
F_8 ( & V_86 ) ;
return V_6 ;
}
V_72 [ 0 ] = F_57 ( 0x00000de4 ) ;
V_72 [ 1 ] = F_57 ( 0x00000000 ) ;
V_72 [ 2 ] = F_57 ( V_69 ) ;
V_72 [ 3 ] = F_57 ( 0x00000000 ) ;
V_72 [ 4 ] = F_57 ( 0x00000000 ) ;
V_72 [ 5 ] = F_57 ( 0x00000000 ) ;
V_72 [ 6 ] = F_57 ( 0x00000000 ) ;
V_72 [ 7 ] = F_57 ( 0x00000780 ) ;
V_72 [ 8 ] = F_57 ( 0x00000440 ) ;
V_72 [ 9 ] = F_57 ( 0x00000000 ) ;
V_72 [ 10 ] = F_57 ( 0x01b37000 ) ;
for ( V_5 = 11 ; V_5 < 1024 ; ++ V_5 )
V_72 [ V_5 ] = F_57 ( 0x0 ) ;
F_14 ( V_86 ) ;
F_10 ( V_86 ) ;
return F_41 ( V_2 , V_56 , V_86 , V_71 ) ;
}
int F_27 ( struct V_1 * V_2 , int V_56 ,
T_1 V_69 , struct V_70 * * V_71 )
{
struct V_62 * V_86 ;
T_1 * V_72 ;
int V_6 , V_5 ;
V_6 = F_6 ( V_2 , 1024 , V_47 , true ,
V_48 , NULL , & V_86 ) ;
if ( V_6 )
return V_6 ;
V_6 = F_7 ( V_86 , false ) ;
if ( V_6 ) {
F_8 ( & V_86 ) ;
return V_6 ;
}
V_6 = F_11 ( V_86 , ( void * * ) & V_72 ) ;
if ( V_6 ) {
F_10 ( V_86 ) ;
F_8 ( & V_86 ) ;
return V_6 ;
}
V_72 [ 0 ] = F_57 ( 0x00000de4 ) ;
V_72 [ 1 ] = F_57 ( 0x00000002 ) ;
V_72 [ 2 ] = F_57 ( V_69 ) ;
V_72 [ 3 ] = F_57 ( 0x00000000 ) ;
for ( V_5 = 4 ; V_5 < 1024 ; ++ V_5 )
V_72 [ V_5 ] = F_57 ( 0x0 ) ;
F_14 ( V_86 ) ;
F_10 ( V_86 ) ;
return F_41 ( V_2 , V_56 , V_86 , V_71 ) ;
}
static void F_58 ( struct V_1 * V_2 ,
unsigned * V_129 , unsigned * V_130 )
{
unsigned V_5 ;
* V_129 = 0 ;
* V_130 = 0 ;
for ( V_5 = 0 ; V_5 < V_52 ; ++ V_5 ) {
if ( ! F_19 ( & V_2 -> V_7 . V_53 [ V_5 ] ) )
continue;
if ( V_2 -> V_7 . V_55 [ V_5 ] >= 720 * 576 )
++ ( * V_130 ) ;
else
++ ( * V_129 ) ;
}
}
static void V_9 ( struct V_131 * V_132 )
{
struct V_1 * V_2 =
F_59 ( V_132 , struct V_1 , V_7 . V_8 . V_132 ) ;
if ( F_60 ( V_2 , V_57 ) == 0 ) {
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
return - V_41 ;
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
F_28 ( L_29 ) ;
return - V_169 ;
}
return 0 ;
}
