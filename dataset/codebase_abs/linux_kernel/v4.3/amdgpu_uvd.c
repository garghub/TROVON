int F_1 ( struct V_1 * V_2 )
{
unsigned long V_3 ;
const char * V_4 ;
const struct V_5 * V_6 ;
unsigned V_7 , V_8 , V_9 ;
int V_10 , V_11 ;
F_2 ( & V_2 -> V_12 . V_13 , V_14 ) ;
switch ( V_2 -> V_15 ) {
#ifdef F_3
case V_16 :
V_4 = V_17 ;
break;
case V_18 :
V_4 = V_19 ;
break;
case V_20 :
V_4 = V_21 ;
break;
case V_22 :
V_4 = V_23 ;
break;
case V_24 :
V_4 = V_25 ;
break;
#endif
case V_26 :
V_4 = V_27 ;
break;
case V_28 :
V_4 = V_29 ;
break;
case V_30 :
V_4 = V_31 ;
break;
default:
return - V_32 ;
}
V_11 = F_4 ( & V_2 -> V_12 . V_33 , V_4 , V_2 -> V_34 ) ;
if ( V_11 ) {
F_5 ( V_2 -> V_34 , L_1 ,
V_4 ) ;
return V_11 ;
}
V_11 = F_6 ( V_2 -> V_12 . V_33 ) ;
if ( V_11 ) {
F_5 ( V_2 -> V_34 , L_2 ,
V_4 ) ;
F_7 ( V_2 -> V_12 . V_33 ) ;
V_2 -> V_12 . V_33 = NULL ;
return V_11 ;
}
V_6 = ( const struct V_5 * ) V_2 -> V_12 . V_33 -> V_35 ;
V_9 = F_8 ( V_6 -> V_36 ) & 0xff ;
V_7 = ( F_8 ( V_6 -> V_36 ) >> 24 ) & 0xff ;
V_8 = ( F_8 ( V_6 -> V_36 ) >> 8 ) & 0xff ;
F_9 ( L_3 ,
V_7 , V_8 , V_9 ) ;
V_3 = F_10 ( F_8 ( V_6 -> V_37 ) + 8 )
+ V_38 + V_39 ;
V_11 = F_11 ( V_2 , V_3 , V_40 , true ,
V_41 ,
V_42 ,
NULL , NULL , & V_2 -> V_12 . V_43 ) ;
if ( V_11 ) {
F_5 ( V_2 -> V_34 , L_4 , V_11 ) ;
return V_11 ;
}
V_11 = F_12 ( V_2 -> V_12 . V_43 , false ) ;
if ( V_11 ) {
F_13 ( & V_2 -> V_12 . V_43 ) ;
F_5 ( V_2 -> V_34 , L_5 , V_11 ) ;
return V_11 ;
}
V_11 = F_14 ( V_2 -> V_12 . V_43 , V_41 ,
& V_2 -> V_12 . V_44 ) ;
if ( V_11 ) {
F_15 ( V_2 -> V_12 . V_43 ) ;
F_13 ( & V_2 -> V_12 . V_43 ) ;
F_5 ( V_2 -> V_34 , L_6 , V_11 ) ;
return V_11 ;
}
V_11 = F_16 ( V_2 -> V_12 . V_43 , & V_2 -> V_12 . V_45 ) ;
if ( V_11 ) {
F_5 ( V_2 -> V_34 , L_7 , V_11 ) ;
return V_11 ;
}
F_15 ( V_2 -> V_12 . V_43 ) ;
for ( V_10 = 0 ; V_10 < V_46 ; ++ V_10 ) {
F_17 ( & V_2 -> V_12 . V_47 [ V_10 ] , 0 ) ;
V_2 -> V_12 . V_48 [ V_10 ] = NULL ;
}
if ( ! F_18 ( V_2 , V_49 , 5 , 0 ) )
V_2 -> V_12 . V_50 = true ;
return 0 ;
}
int F_19 ( struct V_1 * V_2 )
{
int V_11 ;
if ( V_2 -> V_12 . V_43 == NULL )
return 0 ;
V_11 = F_12 ( V_2 -> V_12 . V_43 , false ) ;
if ( ! V_11 ) {
F_20 ( V_2 -> V_12 . V_43 ) ;
F_21 ( V_2 -> V_12 . V_43 ) ;
F_15 ( V_2 -> V_12 . V_43 ) ;
}
F_13 ( & V_2 -> V_12 . V_43 ) ;
F_22 ( & V_2 -> V_12 . V_51 ) ;
F_7 ( V_2 -> V_12 . V_33 ) ;
return 0 ;
}
int F_23 ( struct V_1 * V_2 )
{
struct V_52 * V_51 = & V_2 -> V_12 . V_51 ;
int V_10 , V_11 ;
if ( V_2 -> V_12 . V_43 == NULL )
return 0 ;
for ( V_10 = 0 ; V_10 < V_46 ; ++ V_10 ) {
T_1 V_53 = F_24 ( & V_2 -> V_12 . V_47 [ V_10 ] ) ;
if ( V_53 != 0 ) {
struct V_54 * V_54 ;
F_25 ( V_2 ) ;
V_11 = F_26 ( V_51 , V_53 , & V_54 ) ;
if ( V_11 ) {
F_27 ( L_8 , V_11 ) ;
continue;
}
F_28 ( V_54 , false ) ;
F_29 ( V_54 ) ;
V_2 -> V_12 . V_48 [ V_10 ] = NULL ;
F_17 ( & V_2 -> V_12 . V_47 [ V_10 ] , 0 ) ;
}
}
return 0 ;
}
int F_30 ( struct V_1 * V_2 )
{
unsigned V_55 ;
void * V_56 ;
const struct V_5 * V_6 ;
unsigned V_57 ;
if ( V_2 -> V_12 . V_43 == NULL )
return - V_32 ;
V_6 = ( const struct V_5 * ) V_2 -> V_12 . V_33 -> V_35 ;
V_57 = F_8 ( V_6 -> V_58 ) ;
memcpy ( V_2 -> V_12 . V_45 , ( V_2 -> V_12 . V_33 -> V_35 ) + V_57 ,
( V_2 -> V_12 . V_33 -> V_55 ) - V_57 ) ;
V_55 = F_31 ( V_2 -> V_12 . V_43 ) ;
V_55 -= F_8 ( V_6 -> V_37 ) ;
V_56 = V_2 -> V_12 . V_45 ;
V_56 += F_8 ( V_6 -> V_37 ) ;
memset ( V_56 , 0 , V_55 ) ;
return 0 ;
}
void F_32 ( struct V_1 * V_2 , struct V_59 * V_48 )
{
struct V_52 * V_51 = & V_2 -> V_12 . V_51 ;
int V_10 , V_11 ;
for ( V_10 = 0 ; V_10 < V_46 ; ++ V_10 ) {
T_1 V_53 = F_24 ( & V_2 -> V_12 . V_47 [ V_10 ] ) ;
if ( V_53 != 0 && V_2 -> V_12 . V_48 [ V_10 ] == V_48 ) {
struct V_54 * V_54 ;
F_25 ( V_2 ) ;
V_11 = F_26 ( V_51 , V_53 , & V_54 ) ;
if ( V_11 ) {
F_27 ( L_8 , V_11 ) ;
continue;
}
F_28 ( V_54 , false ) ;
F_29 ( V_54 ) ;
V_2 -> V_12 . V_48 [ V_10 ] = NULL ;
F_17 ( & V_2 -> V_12 . V_47 [ V_10 ] , 0 ) ;
}
}
}
static void F_33 ( struct V_60 * V_61 )
{
int V_10 ;
for ( V_10 = 0 ; V_10 < V_61 -> V_62 . V_63 ; ++ V_10 ) {
V_61 -> V_64 [ V_10 ] . V_65 = 0 >> V_66 ;
V_61 -> V_64 [ V_10 ] . V_67 = ( 256 * 1024 * 1024 ) >> V_66 ;
}
}
static int F_34 ( struct V_68 * V_69 )
{
struct V_70 * V_71 ;
struct V_60 * V_72 ;
T_1 V_73 , V_74 , V_75 ;
T_2 V_76 ;
int V_11 = 0 ;
V_74 = F_35 ( V_69 -> V_77 , V_69 -> V_78 , V_69 -> V_79 ) ;
V_75 = F_35 ( V_69 -> V_77 , V_69 -> V_78 , V_69 -> V_80 ) ;
V_76 = ( ( T_2 ) V_74 ) | ( ( ( T_2 ) V_75 ) << 32 ) ;
V_71 = F_36 ( V_69 -> V_77 , V_76 , & V_72 ) ;
if ( V_71 == NULL ) {
F_27 ( L_9 , V_76 ) ;
return - V_32 ;
}
if ( ! V_69 -> V_77 -> V_2 -> V_12 . V_50 ) {
V_73 = F_35 ( V_69 -> V_77 , V_69 -> V_78 , V_69 -> V_81 ) >> 1 ;
if ( V_73 == 0x0 || V_73 == 0x3 ) {
T_1 V_82 = V_41 ;
F_37 ( V_72 , V_82 ) ;
}
F_33 ( V_72 ) ;
V_11 = F_38 ( & V_72 -> V_83 , & V_72 -> V_62 , false , false ) ;
}
return V_11 ;
}
static int F_39 ( T_1 * V_84 , unsigned V_85 [] )
{
unsigned V_86 = V_84 [ 4 ] ;
unsigned V_87 = V_84 [ 6 ] ;
unsigned V_88 = V_84 [ 7 ] ;
unsigned V_89 = V_84 [ 9 ] ;
unsigned V_90 = V_84 [ 28 ] ;
unsigned V_91 = V_84 [ 57 ] ;
unsigned V_92 = V_87 / 16 ;
unsigned V_93 = F_40 ( V_88 / 16 , 2 ) ;
unsigned V_94 = V_92 * V_93 ;
unsigned V_95 , V_96 , V_97 , V_98 ;
unsigned V_99 = 0 ;
V_95 = V_87 * V_88 ;
V_95 += V_95 / 2 ;
V_95 = F_40 ( V_95 , 1024 ) ;
switch ( V_86 ) {
case 0 :
case 7 :
switch( V_91 ) {
case 30 :
V_98 = 8100 / V_94 ;
break;
case 31 :
V_98 = 18000 / V_94 ;
break;
case 32 :
V_98 = 20480 / V_94 ;
break;
case 41 :
V_98 = 32768 / V_94 ;
break;
case 42 :
V_98 = 34816 / V_94 ;
break;
case 50 :
V_98 = 110400 / V_94 ;
break;
case 51 :
V_98 = 184320 / V_94 ;
break;
default:
V_98 = 184320 / V_94 ;
break;
}
V_98 ++ ;
if ( V_98 > 17 )
V_98 = 17 ;
V_97 = V_95 * V_98 ;
V_97 += V_92 * V_93 * V_98 * 192 ;
V_97 += V_92 * V_93 * 32 ;
break;
case 1 :
V_97 = V_95 * 3 ;
V_97 += V_92 * V_93 * 128 ;
V_97 += V_92 * 64 ;
V_97 += V_92 * 128 ;
V_96 = F_41 ( V_92 , V_93 ) ;
V_97 += F_40 ( V_96 * 7 * 16 , 64 ) ;
break;
case 3 :
V_97 = V_95 * 3 ;
break;
case 4 :
V_97 = V_95 * 3 ;
V_97 += V_92 * V_93 * 64 ;
V_97 += F_40 ( V_92 * V_93 * 32 , 64 ) ;
break;
case 16 :
V_95 = ( F_40 ( V_87 , 16 ) * F_40 ( V_88 , 16 ) * 3 ) / 2 ;
V_95 = F_40 ( V_95 , 256 ) ;
V_98 = ( F_8 ( V_84 [ 59 ] ) & 0xff ) + 2 ;
V_97 = V_95 * V_98 ;
V_99 = ( ( V_87 + 255 ) / 16 ) * ( ( V_88 + 255 ) / 16 )
* 16 * V_98 + 52 * 1024 ;
break;
default:
F_27 ( L_10 , V_86 ) ;
return - V_32 ;
}
if ( V_87 > V_90 ) {
F_27 ( L_11 ) ;
return - V_32 ;
}
if ( V_89 < V_97 ) {
F_27 ( L_12 ,
V_89 , V_97 ) ;
return - V_32 ;
}
V_85 [ 0x1 ] = V_89 ;
V_85 [ 0x2 ] = V_95 ;
V_85 [ 0x4 ] = V_99 ;
return 0 ;
}
static int F_42 ( struct V_68 * V_69 ,
struct V_60 * V_72 , unsigned V_57 )
{
struct V_1 * V_2 = V_69 -> V_77 -> V_2 ;
T_3 * V_84 , V_100 , V_53 ;
void * V_56 ;
long V_11 ;
int V_10 ;
if ( V_57 & 0x3F ) {
F_27 ( L_13 ) ;
return - V_32 ;
}
V_11 = F_43 ( V_72 -> V_83 . V_101 , true , false ,
V_102 ) ;
if ( V_11 < 0 ) {
F_27 ( L_14 , V_11 ) ;
return V_11 ;
}
V_11 = F_16 ( V_72 , & V_56 ) ;
if ( V_11 ) {
F_27 ( L_15 , V_11 ) ;
return V_11 ;
}
V_84 = V_56 + V_57 ;
V_100 = V_84 [ 1 ] ;
V_53 = V_84 [ 2 ] ;
if ( V_53 == 0 ) {
F_27 ( L_16 ) ;
return - V_32 ;
}
switch ( V_100 ) {
case 0 :
F_20 ( V_72 ) ;
for ( V_10 = 0 ; V_10 < V_46 ; ++ V_10 ) {
if ( F_24 ( & V_2 -> V_12 . V_47 [ V_10 ] ) == V_53 ) {
F_27 ( L_17 , V_53 ) ;
return - V_32 ;
}
if ( ! F_44 ( & V_2 -> V_12 . V_47 [ V_10 ] , 0 , V_53 ) ) {
V_2 -> V_12 . V_48 [ V_10 ] = V_69 -> V_77 -> V_48 ;
return 0 ;
}
}
F_27 ( L_18 ) ;
return - V_32 ;
case 1 :
V_11 = F_39 ( V_84 , V_69 -> V_85 ) ;
F_20 ( V_72 ) ;
if ( V_11 )
return V_11 ;
for ( V_10 = 0 ; V_10 < V_46 ; ++ V_10 ) {
if ( F_24 ( & V_2 -> V_12 . V_47 [ V_10 ] ) == V_53 ) {
if ( V_2 -> V_12 . V_48 [ V_10 ] != V_69 -> V_77 -> V_48 ) {
F_27 ( L_19 ) ;
return - V_32 ;
}
return 0 ;
}
}
F_27 ( L_20 , V_53 ) ;
return - V_103 ;
case 2 :
for ( V_10 = 0 ; V_10 < V_46 ; ++ V_10 )
F_44 ( & V_2 -> V_12 . V_47 [ V_10 ] , V_53 , 0 ) ;
F_20 ( V_72 ) ;
return 0 ;
default:
F_27 ( L_21 , V_100 ) ;
return - V_32 ;
}
F_45 () ;
return - V_32 ;
}
static int F_46 ( struct V_68 * V_69 )
{
struct V_70 * V_71 ;
struct V_60 * V_72 ;
struct V_104 * V_105 ;
T_1 V_73 , V_74 , V_75 ;
T_2 V_106 , V_107 ;
T_2 V_76 ;
int V_11 ;
V_74 = F_35 ( V_69 -> V_77 , V_69 -> V_78 , V_69 -> V_79 ) ;
V_75 = F_35 ( V_69 -> V_77 , V_69 -> V_78 , V_69 -> V_80 ) ;
V_76 = ( ( T_2 ) V_74 ) | ( ( ( T_2 ) V_75 ) << 32 ) ;
V_71 = F_36 ( V_69 -> V_77 , V_76 , & V_72 ) ;
if ( V_71 == NULL )
return - V_32 ;
V_106 = F_47 ( V_72 ) ;
V_107 = ( V_71 -> V_108 . V_109 + 1 - V_71 -> V_108 . V_106 ) ;
V_107 = V_107 * V_110 + V_106 ;
V_76 -= ( ( T_2 ) V_71 -> V_108 . V_106 ) * V_110 ;
V_106 += V_76 ;
V_105 = & V_69 -> V_77 -> V_111 [ V_69 -> V_78 ] ;
V_105 -> V_56 [ V_69 -> V_79 ] = V_106 & 0xFFFFFFFF ;
V_105 -> V_56 [ V_69 -> V_80 ] = V_106 >> 32 ;
V_73 = F_35 ( V_69 -> V_77 , V_69 -> V_78 , V_69 -> V_81 ) >> 1 ;
if ( V_73 < 0x4 ) {
if ( ( V_107 - V_106 ) < V_69 -> V_85 [ V_73 ] ) {
F_27 ( L_22 , V_73 ,
( unsigned ) ( V_107 - V_106 ) ,
V_69 -> V_85 [ V_73 ] ) ;
return - V_32 ;
}
} else if ( V_73 == 0x206 ) {
if ( ( V_107 - V_106 ) < V_69 -> V_85 [ 4 ] ) {
F_27 ( L_22 , V_73 ,
( unsigned ) ( V_107 - V_106 ) ,
V_69 -> V_85 [ 4 ] ) ;
return - V_32 ;
}
} else if ( ( V_73 != 0x100 ) && ( V_73 != 0x204 ) ) {
F_27 ( L_23 , V_73 ) ;
return - V_32 ;
}
if ( ! V_69 -> V_77 -> V_2 -> V_12 . V_50 ) {
if ( ( V_106 >> 28 ) != ( ( V_107 - 1 ) >> 28 ) ) {
F_27 ( L_24 ,
V_106 , V_107 ) ;
return - V_32 ;
}
if ( ( V_73 == 0 || V_73 == 0x3 ) &&
( V_106 >> 28 ) != ( V_69 -> V_77 -> V_2 -> V_12 . V_44 >> 28 ) ) {
F_27 ( L_25 ,
V_106 , V_107 ) ;
return - V_32 ;
}
}
if ( V_73 == 0 ) {
V_69 -> V_112 = true ;
V_11 = F_42 ( V_69 , V_72 , V_76 ) ;
if ( V_11 )
return V_11 ;
} else if ( ! V_69 -> V_112 ) {
F_27 ( L_26 ) ;
return - V_32 ;
}
return 0 ;
}
static int F_48 ( struct V_68 * V_69 ,
int (* F_49)( struct V_68 * V_69 ) )
{
struct V_104 * V_105 = & V_69 -> V_77 -> V_111 [ V_69 -> V_78 ] ;
int V_10 , V_11 ;
V_69 -> V_81 ++ ;
for ( V_10 = 0 ; V_10 <= V_69 -> V_113 ; ++ V_10 ) {
unsigned V_114 = V_69 -> V_114 + V_10 ;
if ( V_69 -> V_81 >= V_105 -> V_115 ) {
F_27 ( L_27 ) ;
return - V_32 ;
}
switch ( V_114 ) {
case V_116 :
V_69 -> V_79 = V_69 -> V_81 ;
break;
case V_117 :
V_69 -> V_80 = V_69 -> V_81 ;
break;
case V_118 :
V_11 = F_49 ( V_69 ) ;
if ( V_11 )
return V_11 ;
break;
case V_119 :
break;
default:
F_27 ( L_28 , V_114 ) ;
return - V_32 ;
}
V_69 -> V_81 ++ ;
}
return 0 ;
}
static int F_50 ( struct V_68 * V_69 ,
int (* F_49)( struct V_68 * V_69 ) )
{
struct V_104 * V_105 = & V_69 -> V_77 -> V_111 [ V_69 -> V_78 ] ;
int V_11 ;
for ( V_69 -> V_81 = 0 ; V_69 -> V_81 < V_105 -> V_115 ; ) {
T_1 V_73 = F_35 ( V_69 -> V_77 , V_69 -> V_78 , V_69 -> V_81 ) ;
unsigned type = F_51 ( V_73 ) ;
switch ( type ) {
case V_120 :
V_69 -> V_114 = F_52 ( V_73 ) ;
V_69 -> V_113 = F_53 ( V_73 ) ;
V_11 = F_48 ( V_69 , F_49 ) ;
if ( V_11 )
return V_11 ;
break;
case V_121 :
++ V_69 -> V_81 ;
break;
default:
F_27 ( L_29 , type ) ;
return - V_32 ;
}
}
return 0 ;
}
int F_54 ( struct V_122 * V_77 , T_1 V_78 )
{
struct V_68 V_69 = {} ;
unsigned V_85 [] = {
[ 0x00000000 ] = 2048 ,
[ 0x00000001 ] = 0xFFFFFFFF ,
[ 0x00000002 ] = 0xFFFFFFFF ,
[ 0x00000003 ] = 2048 ,
[ 0x00000004 ] = 0xFFFFFFFF ,
} ;
struct V_104 * V_105 = & V_77 -> V_111 [ V_78 ] ;
int V_11 ;
if ( V_105 -> V_115 % 16 ) {
F_27 ( L_30 ,
V_105 -> V_115 ) ;
return - V_32 ;
}
V_69 . V_77 = V_77 ;
V_69 . V_85 = V_85 ;
V_69 . V_78 = V_78 ;
V_11 = F_50 ( & V_69 , F_34 ) ;
if ( V_11 )
return V_11 ;
V_11 = F_50 ( & V_69 , F_46 ) ;
if ( V_11 )
return V_11 ;
if ( ! V_69 . V_112 ) {
F_27 ( L_31 ) ;
return - V_32 ;
}
F_25 ( V_69 . V_77 -> V_2 ) ;
return 0 ;
}
static int F_55 (
struct V_123 * V_124 )
{
F_56 ( V_124 -> V_2 , V_124 -> V_111 ) ;
F_57 ( V_124 -> V_111 ) ;
return 0 ;
}
static int F_58 ( struct V_52 * V_51 ,
struct V_60 * V_72 ,
struct V_54 * * V_54 )
{
struct V_125 V_126 ;
struct V_127 V_128 ;
struct V_129 V_130 ;
struct V_104 * V_105 = NULL ;
struct V_54 * V_131 = NULL ;
struct V_1 * V_2 = V_51 -> V_2 ;
T_2 V_76 ;
int V_10 , V_11 ;
memset ( & V_126 , 0 , sizeof( V_126 ) ) ;
V_126 . V_72 = & V_72 -> V_83 ;
F_59 ( & V_130 ) ;
F_60 ( & V_126 . V_130 , & V_130 ) ;
V_11 = F_61 ( & V_128 , & V_130 , true , NULL ) ;
if ( V_11 )
return V_11 ;
if ( ! V_72 -> V_2 -> V_12 . V_50 ) {
F_37 ( V_72 , V_41 ) ;
F_33 ( V_72 ) ;
}
V_11 = F_38 ( & V_72 -> V_83 , & V_72 -> V_62 , true , false ) ;
if ( V_11 )
goto V_132;
V_105 = F_62 ( sizeof( struct V_104 ) , V_133 ) ;
if ( ! V_105 ) {
V_11 = - V_134 ;
goto V_132;
}
V_11 = F_63 ( V_51 , NULL , 64 , V_105 ) ;
if ( V_11 )
goto V_135;
V_76 = F_47 ( V_72 ) ;
V_105 -> V_56 [ 0 ] = F_64 ( V_116 , 0 ) ;
V_105 -> V_56 [ 1 ] = V_76 ;
V_105 -> V_56 [ 2 ] = F_64 ( V_117 , 0 ) ;
V_105 -> V_56 [ 3 ] = V_76 >> 32 ;
V_105 -> V_56 [ 4 ] = F_64 ( V_118 , 0 ) ;
V_105 -> V_56 [ 5 ] = 0 ;
for ( V_10 = 6 ; V_10 < 16 ; ++ V_10 )
V_105 -> V_56 [ V_10 ] = F_65 ( 0 ) ;
V_105 -> V_115 = 16 ;
V_11 = F_66 ( V_2 , V_51 , V_105 , 1 ,
& F_55 ,
V_136 ,
& V_131 ) ;
if ( V_11 )
goto V_137;
F_67 ( & V_128 , & V_130 , V_131 ) ;
if ( V_54 )
* V_54 = F_68 ( V_131 ) ;
F_13 ( & V_72 ) ;
F_29 ( V_131 ) ;
if ( V_138 )
return 0 ;
F_56 ( V_51 -> V_2 , V_105 ) ;
F_57 ( V_105 ) ;
return 0 ;
V_137:
F_56 ( V_51 -> V_2 , V_105 ) ;
V_135:
F_57 ( V_105 ) ;
V_132:
F_69 ( & V_128 , & V_130 ) ;
return V_11 ;
}
int F_70 ( struct V_52 * V_51 , T_1 V_53 ,
struct V_54 * * V_54 )
{
struct V_1 * V_2 = V_51 -> V_2 ;
struct V_60 * V_72 ;
T_1 * V_84 ;
int V_11 , V_10 ;
V_11 = F_11 ( V_2 , 1024 , V_40 , true ,
V_41 ,
V_42 ,
NULL , NULL , & V_72 ) ;
if ( V_11 )
return V_11 ;
V_11 = F_12 ( V_72 , false ) ;
if ( V_11 ) {
F_13 ( & V_72 ) ;
return V_11 ;
}
V_11 = F_16 ( V_72 , ( void * * ) & V_84 ) ;
if ( V_11 ) {
F_15 ( V_72 ) ;
F_13 ( & V_72 ) ;
return V_11 ;
}
V_84 [ 0 ] = F_71 ( 0x00000de4 ) ;
V_84 [ 1 ] = F_71 ( 0x00000000 ) ;
V_84 [ 2 ] = F_71 ( V_53 ) ;
V_84 [ 3 ] = F_71 ( 0x00000000 ) ;
V_84 [ 4 ] = F_71 ( 0x00000000 ) ;
V_84 [ 5 ] = F_71 ( 0x00000000 ) ;
V_84 [ 6 ] = F_71 ( 0x00000000 ) ;
V_84 [ 7 ] = F_71 ( 0x00000780 ) ;
V_84 [ 8 ] = F_71 ( 0x00000440 ) ;
V_84 [ 9 ] = F_71 ( 0x00000000 ) ;
V_84 [ 10 ] = F_71 ( 0x01b37000 ) ;
for ( V_10 = 11 ; V_10 < 1024 ; ++ V_10 )
V_84 [ V_10 ] = F_71 ( 0x0 ) ;
F_20 ( V_72 ) ;
F_15 ( V_72 ) ;
return F_58 ( V_51 , V_72 , V_54 ) ;
}
int F_26 ( struct V_52 * V_51 , T_1 V_53 ,
struct V_54 * * V_54 )
{
struct V_1 * V_2 = V_51 -> V_2 ;
struct V_60 * V_72 ;
T_1 * V_84 ;
int V_11 , V_10 ;
V_11 = F_11 ( V_2 , 1024 , V_40 , true ,
V_41 ,
V_42 ,
NULL , NULL , & V_72 ) ;
if ( V_11 )
return V_11 ;
V_11 = F_12 ( V_72 , false ) ;
if ( V_11 ) {
F_13 ( & V_72 ) ;
return V_11 ;
}
V_11 = F_16 ( V_72 , ( void * * ) & V_84 ) ;
if ( V_11 ) {
F_15 ( V_72 ) ;
F_13 ( & V_72 ) ;
return V_11 ;
}
V_84 [ 0 ] = F_71 ( 0x00000de4 ) ;
V_84 [ 1 ] = F_71 ( 0x00000002 ) ;
V_84 [ 2 ] = F_71 ( V_53 ) ;
V_84 [ 3 ] = F_71 ( 0x00000000 ) ;
for ( V_10 = 4 ; V_10 < 1024 ; ++ V_10 )
V_84 [ V_10 ] = F_71 ( 0x0 ) ;
F_20 ( V_72 ) ;
F_15 ( V_72 ) ;
return F_58 ( V_51 , V_72 , V_54 ) ;
}
static void V_14 ( struct V_139 * V_140 )
{
struct V_1 * V_2 =
F_72 ( V_140 , struct V_1 , V_12 . V_13 . V_140 ) ;
unsigned V_10 , V_141 , V_47 = 0 ;
V_141 = F_73 ( & V_2 -> V_12 . V_51 ) ;
for ( V_10 = 0 ; V_10 < V_46 ; ++ V_10 )
if ( F_24 ( & V_2 -> V_12 . V_47 [ V_10 ] ) )
++ V_47 ;
if ( V_141 == 0 && V_47 == 0 ) {
if ( V_2 -> V_142 . V_143 ) {
F_74 ( V_2 , false ) ;
} else {
F_75 ( V_2 , 0 , 0 ) ;
}
} else {
F_76 ( & V_2 -> V_12 . V_13 ,
F_77 ( V_144 ) ) ;
}
}
static void F_25 ( struct V_1 * V_2 )
{
bool V_145 = ! F_78 ( & V_2 -> V_12 . V_13 ) ;
V_145 &= F_76 ( & V_2 -> V_12 . V_13 ,
F_77 ( V_144 ) ) ;
if ( V_145 ) {
if ( V_2 -> V_142 . V_143 ) {
F_74 ( V_2 , true ) ;
} else {
F_75 ( V_2 , 53300 , 40000 ) ;
}
}
}
