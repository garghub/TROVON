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
V_2 -> V_7 . V_52 [ V_5 ] = 0 ;
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
void * V_53 ;
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
V_53 = V_2 -> V_7 . V_48 ;
V_53 += V_2 -> V_39 -> V_41 ;
V_2 -> V_7 . V_54 = F_20 ( V_41 , V_55 ) ;
memcpy ( V_2 -> V_7 . V_54 , V_53 , V_41 ) ;
return 0 ;
}
int F_21 ( struct V_1 * V_2 )
{
unsigned V_41 ;
void * V_53 ;
if ( V_2 -> V_7 . V_46 == NULL )
return - V_38 ;
memcpy ( V_2 -> V_7 . V_48 , V_2 -> V_39 -> V_56 , V_2 -> V_39 -> V_41 ) ;
V_41 = F_19 ( V_2 -> V_7 . V_46 ) ;
V_41 -= V_2 -> V_39 -> V_41 ;
V_53 = V_2 -> V_7 . V_48 ;
V_53 += V_2 -> V_39 -> V_41 ;
if ( V_2 -> V_7 . V_54 != NULL ) {
memcpy ( V_53 , V_2 -> V_7 . V_54 , V_41 ) ;
F_22 ( V_2 -> V_7 . V_54 ) ;
V_2 -> V_7 . V_54 = NULL ;
} else
memset ( V_53 , 0 , V_41 ) ;
return 0 ;
}
void F_23 ( struct V_57 * V_58 )
{
V_58 -> V_59 . V_60 = 0 >> V_61 ;
V_58 -> V_59 . V_62 = ( 256 * 1024 * 1024 ) >> V_61 ;
}
void F_24 ( struct V_1 * V_2 , struct V_63 * V_51 )
{
int V_5 , V_6 ;
for ( V_5 = 0 ; V_5 < V_49 ; ++ V_5 ) {
T_1 V_64 = F_18 ( & V_2 -> V_7 . V_50 [ V_5 ] ) ;
if ( V_64 != 0 && V_2 -> V_7 . V_51 [ V_5 ] == V_51 ) {
struct V_65 * V_66 ;
V_6 = F_25 ( V_2 ,
V_67 , V_64 , & V_66 ) ;
if ( V_6 ) {
F_26 ( L_6 , V_6 ) ;
continue;
}
F_27 ( V_66 , false ) ;
F_28 ( & V_66 ) ;
V_2 -> V_7 . V_51 [ V_5 ] = NULL ;
F_12 ( & V_2 -> V_7 . V_50 [ V_5 ] , 0 ) ;
}
}
}
static int F_29 ( T_1 * V_68 , unsigned V_69 [] )
{
unsigned V_70 = V_68 [ 4 ] ;
unsigned V_71 = V_68 [ 6 ] ;
unsigned V_72 = V_68 [ 7 ] ;
unsigned V_73 = V_68 [ 9 ] ;
unsigned V_74 = V_68 [ 28 ] ;
unsigned V_75 = V_71 / 16 ;
unsigned V_76 = F_30 ( V_72 / 16 , 2 ) ;
unsigned V_77 , V_78 , V_79 ;
V_77 = V_71 * V_72 ;
V_77 += V_77 / 2 ;
V_77 = F_30 ( V_77 , 1024 ) ;
switch ( V_70 ) {
case 0 :
V_79 = V_77 * 17 ;
V_79 += V_75 * V_76 * 17 * 192 ;
V_79 += V_75 * V_76 * 32 ;
break;
case 1 :
V_79 = V_77 * 3 ;
V_79 += V_75 * V_76 * 128 ;
V_79 += V_75 * 64 ;
V_79 += V_75 * 128 ;
V_78 = F_31 ( V_75 , V_76 ) ;
V_79 += F_30 ( V_78 * 7 * 16 , 64 ) ;
break;
case 3 :
V_79 = V_77 * 3 ;
break;
case 4 :
V_79 = V_77 * 3 ;
V_79 += V_75 * V_76 * 64 ;
V_79 += F_30 ( V_75 * V_76 * 32 , 64 ) ;
break;
default:
F_26 ( L_7 , V_70 ) ;
return - V_38 ;
}
if ( V_71 > V_74 ) {
F_26 ( L_8 ) ;
return - V_38 ;
}
if ( V_73 < V_79 ) {
F_26 ( L_9 ,
V_73 , V_79 ) ;
return - V_38 ;
}
V_69 [ 0x1 ] = V_73 ;
V_69 [ 0x2 ] = V_77 ;
return 0 ;
}
static int F_32 ( struct V_80 * V_81 , struct V_57 * V_82 ,
unsigned V_83 , unsigned V_69 [] )
{
T_2 * V_68 , V_84 , V_64 ;
unsigned V_52 = 0 ;
void * V_53 ;
int V_5 , V_6 ;
if ( V_83 & 0x3F ) {
F_26 ( L_10 ) ;
return - V_38 ;
}
if ( V_82 -> V_85 . V_86 ) {
V_6 = F_27 ( V_82 -> V_85 . V_86 , false ) ;
if ( V_6 ) {
F_26 ( L_11 , V_6 ) ;
return V_6 ;
}
}
V_6 = F_11 ( V_82 , & V_53 ) ;
if ( V_6 ) {
F_26 ( L_12 , V_6 ) ;
return V_6 ;
}
V_68 = V_53 + V_83 ;
V_84 = V_68 [ 1 ] ;
V_64 = V_68 [ 2 ] ;
if ( V_64 == 0 ) {
F_26 ( L_13 ) ;
return - V_38 ;
}
if ( V_84 == 1 ) {
V_6 = F_29 ( V_68 , V_69 ) ;
V_52 = V_68 [ 6 ] * V_68 [ 7 ] ;
F_14 ( V_82 ) ;
if ( V_6 )
return V_6 ;
} else if ( V_84 == 2 ) {
for ( V_5 = 0 ; V_5 < V_49 ; ++ V_5 )
F_33 ( & V_81 -> V_2 -> V_7 . V_50 [ V_5 ] , V_64 , 0 ) ;
F_14 ( V_82 ) ;
return 0 ;
} else {
V_52 = V_68 [ 7 ] * V_68 [ 8 ] ;
F_14 ( V_82 ) ;
if ( V_84 != 0 ) {
F_26 ( L_14 , V_84 ) ;
return - V_38 ;
}
}
for ( V_5 = 0 ; V_5 < V_49 ; ++ V_5 ) {
if ( F_18 ( & V_81 -> V_2 -> V_7 . V_50 [ V_5 ] ) == V_64 )
return 0 ;
}
for ( V_5 = 0 ; V_5 < V_49 ; ++ V_5 ) {
if ( ! F_33 ( & V_81 -> V_2 -> V_7 . V_50 [ V_5 ] , 0 , V_64 ) ) {
V_81 -> V_2 -> V_7 . V_51 [ V_5 ] = V_81 -> V_51 ;
V_81 -> V_2 -> V_7 . V_52 [ V_5 ] = V_52 ;
return 0 ;
}
}
F_26 ( L_15 ) ;
return - V_38 ;
}
static int F_34 ( struct V_80 * V_81 ,
int V_87 , int V_88 ,
unsigned V_69 [] , bool * V_89 )
{
struct V_90 * V_91 ;
struct V_92 * V_93 ;
unsigned V_94 , V_95 , V_83 ;
T_3 V_96 , V_97 ;
int V_6 ;
V_91 = & V_81 -> V_98 [ V_81 -> V_99 ] ;
V_83 = F_35 ( V_81 , V_87 ) ;
V_94 = F_35 ( V_81 , V_88 ) ;
if ( V_94 >= V_91 -> V_100 ) {
F_26 ( L_16 ,
V_94 , V_91 -> V_100 ) ;
return - V_38 ;
}
V_93 = V_81 -> V_101 [ ( V_94 / 4 ) ] ;
V_96 = V_93 -> V_102 . V_103 ;
V_97 = V_96 + F_19 ( V_93 -> V_104 ) ;
V_96 += V_83 ;
V_81 -> V_105 . V_53 [ V_87 ] = V_96 & 0xFFFFFFFF ;
V_81 -> V_105 . V_53 [ V_88 ] = V_96 >> 32 ;
V_95 = F_35 ( V_81 , V_81 -> V_94 ) >> 1 ;
if ( V_95 < 0x4 ) {
if ( ( V_97 - V_96 ) < V_69 [ V_95 ] ) {
F_26 ( L_17 , V_95 ,
( unsigned ) ( V_97 - V_96 ) , V_69 [ V_95 ] ) ;
return - V_38 ;
}
} else if ( V_95 != 0x100 ) {
F_26 ( L_18 , V_95 ) ;
return - V_38 ;
}
if ( ( V_96 >> 28 ) != ( V_97 >> 28 ) ) {
F_26 ( L_19 ,
V_96 , V_97 ) ;
return - V_38 ;
}
if ( ( V_95 == 0 || V_95 == 0x3 ) &&
( V_96 >> 28 ) != ( V_81 -> V_2 -> V_7 . V_47 >> 28 ) ) {
F_26 ( L_20 ,
V_96 , V_97 ) ;
return - V_38 ;
}
if ( V_95 == 0 ) {
if ( * V_89 ) {
F_26 ( L_21 ) ;
return - V_38 ;
}
* V_89 = true ;
V_6 = F_32 ( V_81 , V_93 -> V_104 , V_83 , V_69 ) ;
if ( V_6 )
return V_6 ;
} else if ( ! * V_89 ) {
F_26 ( L_22 ) ;
return - V_38 ;
}
return 0 ;
}
static int F_36 ( struct V_80 * V_81 ,
struct V_106 * V_107 ,
int * V_87 , int * V_88 ,
unsigned V_69 [] ,
bool * V_89 )
{
int V_5 , V_6 ;
V_81 -> V_94 ++ ;
for ( V_5 = 0 ; V_5 <= V_107 -> V_108 ; ++ V_5 ) {
switch ( V_107 -> V_109 + V_5 * 4 ) {
case V_110 :
* V_87 = V_81 -> V_94 ;
break;
case V_111 :
* V_88 = V_81 -> V_94 ;
break;
case V_112 :
V_6 = F_34 ( V_81 , * V_87 , * V_88 ,
V_69 , V_89 ) ;
if ( V_6 )
return V_6 ;
break;
case V_113 :
break;
default:
F_26 ( L_23 ,
V_107 -> V_109 + V_5 * 4 ) ;
return - V_38 ;
}
V_81 -> V_94 ++ ;
}
return 0 ;
}
int F_37 ( struct V_80 * V_81 )
{
struct V_106 V_107 ;
int V_6 , V_87 = 0 , V_88 = 0 ;
bool V_89 = false ;
unsigned V_69 [] = {
[ 0x00000000 ] = 2048 ,
[ 0x00000001 ] = 32 * 1024 * 1024 ,
[ 0x00000002 ] = 2048 * 1152 * 3 ,
[ 0x00000003 ] = 2048 ,
} ;
if ( V_81 -> V_98 [ V_81 -> V_114 ] . V_100 % 16 ) {
F_26 ( L_24 ,
V_81 -> V_98 [ V_81 -> V_114 ] . V_100 ) ;
return - V_38 ;
}
if ( V_81 -> V_99 == - 1 ) {
F_26 ( L_25 ) ;
return - V_38 ;
}
do {
V_6 = F_38 ( V_81 , & V_107 , V_81 -> V_94 ) ;
if ( V_6 )
return V_6 ;
switch ( V_107 . type ) {
case V_115 :
V_6 = F_36 ( V_81 , & V_107 , & V_87 , & V_88 ,
V_69 , & V_89 ) ;
if ( V_6 )
return V_6 ;
break;
case V_116 :
V_81 -> V_94 += V_107 . V_108 + 2 ;
break;
default:
F_26 ( L_26 , V_107 . type ) ;
return - V_38 ;
}
} while ( V_81 -> V_94 < V_81 -> V_98 [ V_81 -> V_114 ] . V_100 );
if ( ! V_89 ) {
F_26 ( L_27 ) ;
return - V_38 ;
}
return 0 ;
}
static int F_39 ( struct V_1 * V_2 ,
int V_117 , struct V_57 * V_82 ,
struct V_65 * * V_66 )
{
struct V_118 V_119 ;
struct V_120 V_121 ;
struct V_122 V_123 ;
struct V_124 V_105 ;
T_3 V_125 ;
int V_5 , V_6 ;
memset ( & V_119 , 0 , sizeof( V_119 ) ) ;
V_119 . V_82 = & V_82 -> V_85 ;
F_40 ( & V_123 ) ;
F_41 ( & V_119 . V_123 , & V_123 ) ;
V_6 = F_42 ( & V_121 , & V_123 ) ;
if ( V_6 )
return V_6 ;
F_43 ( V_82 , V_45 ) ;
F_23 ( V_82 ) ;
V_6 = F_44 ( & V_82 -> V_85 , & V_82 -> V_59 , true , false ) ;
if ( V_6 )
goto V_126;
V_6 = F_45 ( V_2 , V_117 , & V_105 , NULL , 16 ) ;
if ( V_6 )
goto V_126;
V_125 = F_46 ( V_82 ) ;
V_105 . V_53 [ 0 ] = F_47 ( V_110 , 0 ) ;
V_105 . V_53 [ 1 ] = V_125 ;
V_105 . V_53 [ 2 ] = F_47 ( V_111 , 0 ) ;
V_105 . V_53 [ 3 ] = V_125 >> 32 ;
V_105 . V_53 [ 4 ] = F_47 ( V_112 , 0 ) ;
V_105 . V_53 [ 5 ] = 0 ;
for ( V_5 = 6 ; V_5 < 16 ; ++ V_5 )
V_105 . V_53 [ V_5 ] = F_48 ( 0 ) ;
V_105 . V_100 = 16 ;
V_6 = F_49 ( V_2 , & V_105 , NULL ) ;
if ( V_6 )
goto V_126;
F_50 ( & V_121 , & V_123 , V_105 . V_66 ) ;
if ( V_66 )
* V_66 = F_51 ( V_105 . V_66 ) ;
F_52 ( V_2 , & V_105 ) ;
F_8 ( & V_82 ) ;
return 0 ;
V_126:
F_53 ( & V_121 , & V_123 ) ;
return V_6 ;
}
int F_54 ( struct V_1 * V_2 , int V_117 ,
T_1 V_64 , struct V_65 * * V_66 )
{
struct V_57 * V_82 ;
T_1 * V_68 ;
int V_6 , V_5 ;
V_6 = F_6 ( V_2 , 1024 , V_44 , true ,
V_45 , NULL , & V_82 ) ;
if ( V_6 )
return V_6 ;
V_6 = F_7 ( V_82 , false ) ;
if ( V_6 ) {
F_8 ( & V_82 ) ;
return V_6 ;
}
V_6 = F_11 ( V_82 , ( void * * ) & V_68 ) ;
if ( V_6 ) {
F_10 ( V_82 ) ;
F_8 ( & V_82 ) ;
return V_6 ;
}
V_68 [ 0 ] = F_55 ( 0x00000de4 ) ;
V_68 [ 1 ] = F_55 ( 0x00000000 ) ;
V_68 [ 2 ] = F_55 ( V_64 ) ;
V_68 [ 3 ] = F_55 ( 0x00000000 ) ;
V_68 [ 4 ] = F_55 ( 0x00000000 ) ;
V_68 [ 5 ] = F_55 ( 0x00000000 ) ;
V_68 [ 6 ] = F_55 ( 0x00000000 ) ;
V_68 [ 7 ] = F_55 ( 0x00000780 ) ;
V_68 [ 8 ] = F_55 ( 0x00000440 ) ;
V_68 [ 9 ] = F_55 ( 0x00000000 ) ;
V_68 [ 10 ] = F_55 ( 0x01b37000 ) ;
for ( V_5 = 11 ; V_5 < 1024 ; ++ V_5 )
V_68 [ V_5 ] = F_55 ( 0x0 ) ;
F_14 ( V_82 ) ;
F_10 ( V_82 ) ;
return F_39 ( V_2 , V_117 , V_82 , V_66 ) ;
}
int F_25 ( struct V_1 * V_2 , int V_117 ,
T_1 V_64 , struct V_65 * * V_66 )
{
struct V_57 * V_82 ;
T_1 * V_68 ;
int V_6 , V_5 ;
V_6 = F_6 ( V_2 , 1024 , V_44 , true ,
V_45 , NULL , & V_82 ) ;
if ( V_6 )
return V_6 ;
V_6 = F_7 ( V_82 , false ) ;
if ( V_6 ) {
F_8 ( & V_82 ) ;
return V_6 ;
}
V_6 = F_11 ( V_82 , ( void * * ) & V_68 ) ;
if ( V_6 ) {
F_10 ( V_82 ) ;
F_8 ( & V_82 ) ;
return V_6 ;
}
V_68 [ 0 ] = F_55 ( 0x00000de4 ) ;
V_68 [ 1 ] = F_55 ( 0x00000002 ) ;
V_68 [ 2 ] = F_55 ( V_64 ) ;
V_68 [ 3 ] = F_55 ( 0x00000000 ) ;
for ( V_5 = 4 ; V_5 < 1024 ; ++ V_5 )
V_68 [ V_5 ] = F_55 ( 0x0 ) ;
F_14 ( V_82 ) ;
F_10 ( V_82 ) ;
return F_39 ( V_2 , V_117 , V_82 , V_66 ) ;
}
static void F_56 ( struct V_1 * V_2 ,
unsigned * V_127 , unsigned * V_128 )
{
unsigned V_5 ;
* V_127 = 0 ;
* V_128 = 0 ;
for ( V_5 = 0 ; V_5 < V_49 ; ++ V_5 ) {
if ( ! F_18 ( & V_2 -> V_7 . V_50 [ V_5 ] ) )
continue;
if ( V_2 -> V_7 . V_52 [ V_5 ] >= 720 * 576 )
++ ( * V_128 ) ;
else
++ ( * V_127 ) ;
}
}
static void V_9 ( struct V_129 * V_130 )
{
struct V_1 * V_2 =
F_57 ( V_130 , struct V_1 , V_7 . V_8 . V_130 ) ;
if ( F_58 ( V_2 , V_67 ) == 0 ) {
if ( ( V_2 -> V_131 . V_132 == V_133 ) && V_2 -> V_131 . V_134 ) {
F_59 ( V_2 , false ) ;
} else {
F_60 ( V_2 , 0 , 0 ) ;
}
} else {
F_61 ( & V_2 -> V_7 . V_8 ,
F_62 ( V_135 ) ) ;
}
}
void F_63 ( struct V_1 * V_2 )
{
bool V_136 = false ;
bool V_137 = ! F_64 ( & V_2 -> V_7 . V_8 ) ;
V_137 &= F_61 ( & V_2 -> V_7 . V_8 ,
F_62 ( V_135 ) ) ;
if ( ( V_2 -> V_131 . V_132 == V_133 ) && V_2 -> V_131 . V_134 ) {
unsigned V_128 = 0 , V_127 = 0 ;
F_56 ( V_2 , & V_127 , & V_128 ) ;
if ( ( V_2 -> V_131 . V_138 . V_127 != V_127 ) ||
( V_2 -> V_131 . V_138 . V_128 != V_128 ) ) {
V_2 -> V_131 . V_138 . V_127 = V_127 ;
V_2 -> V_131 . V_138 . V_128 = V_128 ;
}
}
if ( V_137 || V_136 ) {
if ( ( V_2 -> V_131 . V_132 == V_133 ) && V_2 -> V_131 . V_134 ) {
F_59 ( V_2 , true ) ;
} else {
F_60 ( V_2 , 53300 , 40000 ) ;
}
}
}
static unsigned F_65 ( unsigned V_139 ,
unsigned V_140 ,
unsigned V_141 ,
unsigned V_142 )
{
unsigned V_143 = V_139 / V_140 ;
if ( V_143 < V_141 )
V_143 = V_141 ;
if ( ( V_139 / V_143 ) > V_140 )
V_143 += 1 ;
if ( V_143 > V_142 && V_143 % 2 )
V_143 += 1 ;
return V_143 ;
}
int F_66 ( struct V_1 * V_2 ,
unsigned V_144 , unsigned V_145 ,
unsigned V_146 , unsigned V_147 ,
unsigned V_148 , unsigned V_149 ,
unsigned V_141 , unsigned V_150 ,
unsigned V_142 ,
unsigned * V_151 ,
unsigned * V_152 ,
unsigned * V_153 )
{
unsigned V_139 , V_154 = V_2 -> clock . V_155 . V_156 ;
unsigned V_157 = ~ 0 ;
V_146 = F_31 ( F_31 ( V_146 , V_144 ) , V_145 ) ;
for ( V_139 = V_146 ; V_139 <= V_147 ; V_139 += 100 ) {
T_3 V_158 = ( T_3 ) V_139 * V_148 ;
unsigned V_159 , V_160 , V_161 ;
F_67 ( V_158 , V_154 ) ;
if ( V_158 > V_149 )
break;
V_158 &= V_149 ;
V_159 = F_65 ( V_139 , V_144 ,
V_141 , V_142 ) ;
if ( V_159 > V_150 )
break;
V_160 = F_65 ( V_139 , V_145 ,
V_141 , V_142 ) ;
if ( V_159 > V_150 )
break;
V_161 = V_144 - ( V_139 / V_159 ) + V_145 - ( V_139 / V_160 ) ;
if ( V_161 < V_157 ) {
* V_151 = V_158 ;
* V_152 = V_159 ;
* V_153 = V_160 ;
V_157 = V_161 ;
if ( V_157 == 0 )
break;
}
}
if ( V_157 == ~ 0 )
return - V_38 ;
return 0 ;
}
int F_68 ( struct V_1 * V_2 ,
unsigned V_162 )
{
unsigned V_5 ;
F_69 ( V_162 , 0 , ~ V_163 ) ;
F_70 ( 10 ) ;
F_69 ( V_162 , V_163 , ~ V_163 ) ;
for ( V_5 = 0 ; V_5 < 100 ; ++ V_5 ) {
T_1 V_164 = V_165 | V_166 ;
if ( ( F_71 ( V_162 ) & V_164 ) == V_164 )
break;
F_70 ( 10 ) ;
}
F_69 ( V_162 , 0 , ~ V_163 ) ;
if ( V_5 == 100 ) {
F_26 ( L_28 ) ;
return - V_167 ;
}
return 0 ;
}
