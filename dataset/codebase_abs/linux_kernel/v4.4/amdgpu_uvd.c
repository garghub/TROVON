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
case V_32 :
V_4 = V_33 ;
break;
default:
return - V_34 ;
}
V_11 = F_4 ( & V_2 -> V_12 . V_35 , V_4 , V_2 -> V_36 ) ;
if ( V_11 ) {
F_5 ( V_2 -> V_36 , L_1 ,
V_4 ) ;
return V_11 ;
}
V_11 = F_6 ( V_2 -> V_12 . V_35 ) ;
if ( V_11 ) {
F_5 ( V_2 -> V_36 , L_2 ,
V_4 ) ;
F_7 ( V_2 -> V_12 . V_35 ) ;
V_2 -> V_12 . V_35 = NULL ;
return V_11 ;
}
V_6 = ( const struct V_5 * ) V_2 -> V_12 . V_35 -> V_37 ;
V_9 = F_8 ( V_6 -> V_38 ) & 0xff ;
V_7 = ( F_8 ( V_6 -> V_38 ) >> 24 ) & 0xff ;
V_8 = ( F_8 ( V_6 -> V_38 ) >> 8 ) & 0xff ;
F_9 ( L_3 ,
V_7 , V_8 , V_9 ) ;
V_3 = F_10 ( F_8 ( V_6 -> V_39 ) + 8 )
+ V_40 + V_41 ;
V_11 = F_11 ( V_2 , V_3 , V_42 , true ,
V_43 ,
V_44 ,
NULL , NULL , & V_2 -> V_12 . V_45 ) ;
if ( V_11 ) {
F_5 ( V_2 -> V_36 , L_4 , V_11 ) ;
return V_11 ;
}
V_11 = F_12 ( V_2 -> V_12 . V_45 , false ) ;
if ( V_11 ) {
F_13 ( & V_2 -> V_12 . V_45 ) ;
F_5 ( V_2 -> V_36 , L_5 , V_11 ) ;
return V_11 ;
}
V_11 = F_14 ( V_2 -> V_12 . V_45 , V_43 ,
& V_2 -> V_12 . V_46 ) ;
if ( V_11 ) {
F_15 ( V_2 -> V_12 . V_45 ) ;
F_13 ( & V_2 -> V_12 . V_45 ) ;
F_5 ( V_2 -> V_36 , L_6 , V_11 ) ;
return V_11 ;
}
V_11 = F_16 ( V_2 -> V_12 . V_45 , & V_2 -> V_12 . V_47 ) ;
if ( V_11 ) {
F_5 ( V_2 -> V_36 , L_7 , V_11 ) ;
return V_11 ;
}
F_15 ( V_2 -> V_12 . V_45 ) ;
for ( V_10 = 0 ; V_10 < V_48 ; ++ V_10 ) {
F_17 ( & V_2 -> V_12 . V_49 [ V_10 ] , 0 ) ;
V_2 -> V_12 . V_50 [ V_10 ] = NULL ;
}
if ( ! F_18 ( V_2 , V_51 , 5 , 0 ) )
V_2 -> V_12 . V_52 = true ;
return 0 ;
}
int F_19 ( struct V_1 * V_2 )
{
int V_11 ;
if ( V_2 -> V_12 . V_45 == NULL )
return 0 ;
V_11 = F_12 ( V_2 -> V_12 . V_45 , false ) ;
if ( ! V_11 ) {
F_20 ( V_2 -> V_12 . V_45 ) ;
F_21 ( V_2 -> V_12 . V_45 ) ;
F_15 ( V_2 -> V_12 . V_45 ) ;
}
F_13 ( & V_2 -> V_12 . V_45 ) ;
F_22 ( & V_2 -> V_12 . V_53 ) ;
F_7 ( V_2 -> V_12 . V_35 ) ;
return 0 ;
}
int F_23 ( struct V_1 * V_2 )
{
struct V_54 * V_53 = & V_2 -> V_12 . V_53 ;
int V_10 , V_11 ;
if ( V_2 -> V_12 . V_45 == NULL )
return 0 ;
for ( V_10 = 0 ; V_10 < V_48 ; ++ V_10 ) {
T_1 V_55 = F_24 ( & V_2 -> V_12 . V_49 [ V_10 ] ) ;
if ( V_55 != 0 ) {
struct V_56 * V_56 ;
F_25 ( V_2 ) ;
V_11 = F_26 ( V_53 , V_55 , & V_56 ) ;
if ( V_11 ) {
F_27 ( L_8 , V_11 ) ;
continue;
}
F_28 ( V_56 , false ) ;
F_29 ( V_56 ) ;
V_2 -> V_12 . V_50 [ V_10 ] = NULL ;
F_17 ( & V_2 -> V_12 . V_49 [ V_10 ] , 0 ) ;
}
}
return 0 ;
}
int F_30 ( struct V_1 * V_2 )
{
unsigned V_57 ;
void * V_58 ;
const struct V_5 * V_6 ;
unsigned V_59 ;
if ( V_2 -> V_12 . V_45 == NULL )
return - V_34 ;
V_6 = ( const struct V_5 * ) V_2 -> V_12 . V_35 -> V_37 ;
V_59 = F_8 ( V_6 -> V_60 ) ;
memcpy ( V_2 -> V_12 . V_47 , ( V_2 -> V_12 . V_35 -> V_37 ) + V_59 ,
( V_2 -> V_12 . V_35 -> V_57 ) - V_59 ) ;
V_57 = F_31 ( V_2 -> V_12 . V_45 ) ;
V_57 -= F_8 ( V_6 -> V_39 ) ;
V_58 = V_2 -> V_12 . V_47 ;
V_58 += F_8 ( V_6 -> V_39 ) ;
memset ( V_58 , 0 , V_57 ) ;
return 0 ;
}
void F_32 ( struct V_1 * V_2 , struct V_61 * V_50 )
{
struct V_54 * V_53 = & V_2 -> V_12 . V_53 ;
int V_10 , V_11 ;
for ( V_10 = 0 ; V_10 < V_48 ; ++ V_10 ) {
T_1 V_55 = F_24 ( & V_2 -> V_12 . V_49 [ V_10 ] ) ;
if ( V_55 != 0 && V_2 -> V_12 . V_50 [ V_10 ] == V_50 ) {
struct V_56 * V_56 ;
F_25 ( V_2 ) ;
V_11 = F_26 ( V_53 , V_55 , & V_56 ) ;
if ( V_11 ) {
F_27 ( L_8 , V_11 ) ;
continue;
}
F_28 ( V_56 , false ) ;
F_29 ( V_56 ) ;
V_2 -> V_12 . V_50 [ V_10 ] = NULL ;
F_17 ( & V_2 -> V_12 . V_49 [ V_10 ] , 0 ) ;
}
}
}
static void F_33 ( struct V_62 * V_63 )
{
int V_10 ;
for ( V_10 = 0 ; V_10 < V_63 -> V_64 . V_65 ; ++ V_10 ) {
V_63 -> V_66 [ V_10 ] . V_67 = 0 >> V_68 ;
V_63 -> V_66 [ V_10 ] . V_69 = ( 256 * 1024 * 1024 ) >> V_68 ;
}
}
static int F_34 ( struct V_70 * V_71 )
{
struct V_72 * V_73 ;
struct V_62 * V_74 ;
T_1 V_75 , V_76 , V_77 ;
T_2 V_78 ;
int V_11 = 0 ;
V_76 = F_35 ( V_71 -> V_79 , V_71 -> V_80 , V_71 -> V_81 ) ;
V_77 = F_35 ( V_71 -> V_79 , V_71 -> V_80 , V_71 -> V_82 ) ;
V_78 = ( ( T_2 ) V_76 ) | ( ( ( T_2 ) V_77 ) << 32 ) ;
V_73 = F_36 ( V_71 -> V_79 , V_78 , & V_74 ) ;
if ( V_73 == NULL ) {
F_27 ( L_9 , V_78 ) ;
return - V_34 ;
}
if ( ! V_71 -> V_79 -> V_2 -> V_12 . V_52 ) {
V_75 = F_35 ( V_71 -> V_79 , V_71 -> V_80 , V_71 -> V_83 ) >> 1 ;
if ( V_75 == 0x0 || V_75 == 0x3 ) {
T_1 V_84 = V_43 ;
F_37 ( V_74 , V_84 ) ;
}
F_33 ( V_74 ) ;
V_11 = F_38 ( & V_74 -> V_85 , & V_74 -> V_64 , false , false ) ;
}
return V_11 ;
}
static int F_39 ( T_1 * V_86 , unsigned V_87 [] )
{
unsigned V_88 = V_86 [ 4 ] ;
unsigned V_89 = V_86 [ 6 ] ;
unsigned V_90 = V_86 [ 7 ] ;
unsigned V_91 = V_86 [ 9 ] ;
unsigned V_92 = V_86 [ 28 ] ;
unsigned V_93 = V_86 [ 57 ] ;
unsigned V_94 = V_89 / 16 ;
unsigned V_95 = F_40 ( V_90 / 16 , 2 ) ;
unsigned V_96 = V_94 * V_95 ;
unsigned V_97 , V_98 , V_99 , V_100 ;
unsigned V_101 = 0 ;
V_97 = V_89 * V_90 ;
V_97 += V_97 / 2 ;
V_97 = F_40 ( V_97 , 1024 ) ;
switch ( V_88 ) {
case 0 :
case 7 :
switch( V_93 ) {
case 30 :
V_100 = 8100 / V_96 ;
break;
case 31 :
V_100 = 18000 / V_96 ;
break;
case 32 :
V_100 = 20480 / V_96 ;
break;
case 41 :
V_100 = 32768 / V_96 ;
break;
case 42 :
V_100 = 34816 / V_96 ;
break;
case 50 :
V_100 = 110400 / V_96 ;
break;
case 51 :
V_100 = 184320 / V_96 ;
break;
default:
V_100 = 184320 / V_96 ;
break;
}
V_100 ++ ;
if ( V_100 > 17 )
V_100 = 17 ;
V_99 = V_97 * V_100 ;
V_99 += V_94 * V_95 * V_100 * 192 ;
V_99 += V_94 * V_95 * 32 ;
break;
case 1 :
V_99 = V_97 * 3 ;
V_99 += V_94 * V_95 * 128 ;
V_99 += V_94 * 64 ;
V_99 += V_94 * 128 ;
V_98 = F_41 ( V_94 , V_95 ) ;
V_99 += F_40 ( V_98 * 7 * 16 , 64 ) ;
break;
case 3 :
V_99 = V_97 * 3 ;
break;
case 4 :
V_99 = V_97 * 3 ;
V_99 += V_94 * V_95 * 64 ;
V_99 += F_40 ( V_94 * V_95 * 32 , 64 ) ;
break;
case 16 :
V_97 = ( F_40 ( V_89 , 16 ) * F_40 ( V_90 , 16 ) * 3 ) / 2 ;
V_97 = F_40 ( V_97 , 256 ) ;
V_100 = ( F_8 ( V_86 [ 59 ] ) & 0xff ) + 2 ;
V_99 = V_97 * V_100 ;
V_101 = ( ( V_89 + 255 ) / 16 ) * ( ( V_90 + 255 ) / 16 )
* 16 * V_100 + 52 * 1024 ;
break;
default:
F_27 ( L_10 , V_88 ) ;
return - V_34 ;
}
if ( V_89 > V_92 ) {
F_27 ( L_11 ) ;
return - V_34 ;
}
if ( V_91 < V_99 ) {
F_27 ( L_12 ,
V_91 , V_99 ) ;
return - V_34 ;
}
V_87 [ 0x1 ] = V_91 ;
V_87 [ 0x2 ] = V_97 ;
V_87 [ 0x4 ] = V_101 ;
return 0 ;
}
static int F_42 ( struct V_70 * V_71 ,
struct V_62 * V_74 , unsigned V_59 )
{
struct V_1 * V_2 = V_71 -> V_79 -> V_2 ;
T_3 * V_86 , V_102 , V_55 ;
void * V_58 ;
long V_11 ;
int V_10 ;
if ( V_59 & 0x3F ) {
F_27 ( L_13 ) ;
return - V_34 ;
}
V_11 = F_43 ( V_74 -> V_85 . V_103 , true , false ,
V_104 ) ;
if ( V_11 < 0 ) {
F_27 ( L_14 , V_11 ) ;
return V_11 ;
}
V_11 = F_16 ( V_74 , & V_58 ) ;
if ( V_11 ) {
F_27 ( L_15 , V_11 ) ;
return V_11 ;
}
V_86 = V_58 + V_59 ;
V_102 = V_86 [ 1 ] ;
V_55 = V_86 [ 2 ] ;
if ( V_55 == 0 ) {
F_27 ( L_16 ) ;
return - V_34 ;
}
switch ( V_102 ) {
case 0 :
F_20 ( V_74 ) ;
for ( V_10 = 0 ; V_10 < V_48 ; ++ V_10 ) {
if ( F_24 ( & V_2 -> V_12 . V_49 [ V_10 ] ) == V_55 ) {
F_27 ( L_17 , V_55 ) ;
return - V_34 ;
}
if ( ! F_44 ( & V_2 -> V_12 . V_49 [ V_10 ] , 0 , V_55 ) ) {
V_2 -> V_12 . V_50 [ V_10 ] = V_71 -> V_79 -> V_50 ;
return 0 ;
}
}
F_27 ( L_18 ) ;
return - V_34 ;
case 1 :
V_11 = F_39 ( V_86 , V_71 -> V_87 ) ;
F_20 ( V_74 ) ;
if ( V_11 )
return V_11 ;
for ( V_10 = 0 ; V_10 < V_48 ; ++ V_10 ) {
if ( F_24 ( & V_2 -> V_12 . V_49 [ V_10 ] ) == V_55 ) {
if ( V_2 -> V_12 . V_50 [ V_10 ] != V_71 -> V_79 -> V_50 ) {
F_27 ( L_19 ) ;
return - V_34 ;
}
return 0 ;
}
}
F_27 ( L_20 , V_55 ) ;
return - V_105 ;
case 2 :
for ( V_10 = 0 ; V_10 < V_48 ; ++ V_10 )
F_44 ( & V_2 -> V_12 . V_49 [ V_10 ] , V_55 , 0 ) ;
F_20 ( V_74 ) ;
return 0 ;
default:
F_27 ( L_21 , V_102 ) ;
return - V_34 ;
}
F_45 () ;
return - V_34 ;
}
static int F_46 ( struct V_70 * V_71 )
{
struct V_72 * V_73 ;
struct V_62 * V_74 ;
struct V_106 * V_107 ;
T_1 V_75 , V_76 , V_77 ;
T_2 V_108 , V_109 ;
T_2 V_78 ;
int V_11 ;
V_76 = F_35 ( V_71 -> V_79 , V_71 -> V_80 , V_71 -> V_81 ) ;
V_77 = F_35 ( V_71 -> V_79 , V_71 -> V_80 , V_71 -> V_82 ) ;
V_78 = ( ( T_2 ) V_76 ) | ( ( ( T_2 ) V_77 ) << 32 ) ;
V_73 = F_36 ( V_71 -> V_79 , V_78 , & V_74 ) ;
if ( V_73 == NULL )
return - V_34 ;
V_108 = F_47 ( V_74 ) ;
V_109 = ( V_73 -> V_110 . V_111 + 1 - V_73 -> V_110 . V_108 ) ;
V_109 = V_109 * V_112 + V_108 ;
V_78 -= ( ( T_2 ) V_73 -> V_110 . V_108 ) * V_112 ;
V_108 += V_78 ;
V_107 = & V_71 -> V_79 -> V_113 [ V_71 -> V_80 ] ;
V_107 -> V_58 [ V_71 -> V_81 ] = V_108 & 0xFFFFFFFF ;
V_107 -> V_58 [ V_71 -> V_82 ] = V_108 >> 32 ;
V_75 = F_35 ( V_71 -> V_79 , V_71 -> V_80 , V_71 -> V_83 ) >> 1 ;
if ( V_75 < 0x4 ) {
if ( ( V_109 - V_108 ) < V_71 -> V_87 [ V_75 ] ) {
F_27 ( L_22 , V_75 ,
( unsigned ) ( V_109 - V_108 ) ,
V_71 -> V_87 [ V_75 ] ) ;
return - V_34 ;
}
} else if ( V_75 == 0x206 ) {
if ( ( V_109 - V_108 ) < V_71 -> V_87 [ 4 ] ) {
F_27 ( L_22 , V_75 ,
( unsigned ) ( V_109 - V_108 ) ,
V_71 -> V_87 [ 4 ] ) ;
return - V_34 ;
}
} else if ( ( V_75 != 0x100 ) && ( V_75 != 0x204 ) ) {
F_27 ( L_23 , V_75 ) ;
return - V_34 ;
}
if ( ! V_71 -> V_79 -> V_2 -> V_12 . V_52 ) {
if ( ( V_108 >> 28 ) != ( ( V_109 - 1 ) >> 28 ) ) {
F_27 ( L_24 ,
V_108 , V_109 ) ;
return - V_34 ;
}
if ( ( V_75 == 0 || V_75 == 0x3 ) &&
( V_108 >> 28 ) != ( V_71 -> V_79 -> V_2 -> V_12 . V_46 >> 28 ) ) {
F_27 ( L_25 ,
V_108 , V_109 ) ;
return - V_34 ;
}
}
if ( V_75 == 0 ) {
V_71 -> V_114 = true ;
V_11 = F_42 ( V_71 , V_74 , V_78 ) ;
if ( V_11 )
return V_11 ;
} else if ( ! V_71 -> V_114 ) {
F_27 ( L_26 ) ;
return - V_34 ;
}
return 0 ;
}
static int F_48 ( struct V_70 * V_71 ,
int (* F_49)( struct V_70 * V_71 ) )
{
struct V_106 * V_107 = & V_71 -> V_79 -> V_113 [ V_71 -> V_80 ] ;
int V_10 , V_11 ;
V_71 -> V_83 ++ ;
for ( V_10 = 0 ; V_10 <= V_71 -> V_115 ; ++ V_10 ) {
unsigned V_116 = V_71 -> V_116 + V_10 ;
if ( V_71 -> V_83 >= V_107 -> V_117 ) {
F_27 ( L_27 ) ;
return - V_34 ;
}
switch ( V_116 ) {
case V_118 :
V_71 -> V_81 = V_71 -> V_83 ;
break;
case V_119 :
V_71 -> V_82 = V_71 -> V_83 ;
break;
case V_120 :
V_11 = F_49 ( V_71 ) ;
if ( V_11 )
return V_11 ;
break;
case V_121 :
break;
default:
F_27 ( L_28 , V_116 ) ;
return - V_34 ;
}
V_71 -> V_83 ++ ;
}
return 0 ;
}
static int F_50 ( struct V_70 * V_71 ,
int (* F_49)( struct V_70 * V_71 ) )
{
struct V_106 * V_107 = & V_71 -> V_79 -> V_113 [ V_71 -> V_80 ] ;
int V_11 ;
for ( V_71 -> V_83 = 0 ; V_71 -> V_83 < V_107 -> V_117 ; ) {
T_1 V_75 = F_35 ( V_71 -> V_79 , V_71 -> V_80 , V_71 -> V_83 ) ;
unsigned type = F_51 ( V_75 ) ;
switch ( type ) {
case V_122 :
V_71 -> V_116 = F_52 ( V_75 ) ;
V_71 -> V_115 = F_53 ( V_75 ) ;
V_11 = F_48 ( V_71 , F_49 ) ;
if ( V_11 )
return V_11 ;
break;
case V_123 :
++ V_71 -> V_83 ;
break;
default:
F_27 ( L_29 , type ) ;
return - V_34 ;
}
}
return 0 ;
}
int F_54 ( struct V_124 * V_79 , T_1 V_80 )
{
struct V_70 V_71 = {} ;
unsigned V_87 [] = {
[ 0x00000000 ] = 2048 ,
[ 0x00000001 ] = 0xFFFFFFFF ,
[ 0x00000002 ] = 0xFFFFFFFF ,
[ 0x00000003 ] = 2048 ,
[ 0x00000004 ] = 0xFFFFFFFF ,
} ;
struct V_106 * V_107 = & V_79 -> V_113 [ V_80 ] ;
int V_11 ;
if ( V_107 -> V_117 % 16 ) {
F_27 ( L_30 ,
V_107 -> V_117 ) ;
return - V_34 ;
}
V_71 . V_79 = V_79 ;
V_71 . V_87 = V_87 ;
V_71 . V_80 = V_80 ;
V_11 = F_50 ( & V_71 , F_34 ) ;
if ( V_11 )
return V_11 ;
V_11 = F_50 ( & V_71 , F_46 ) ;
if ( V_11 )
return V_11 ;
if ( ! V_71 . V_114 ) {
F_27 ( L_31 ) ;
return - V_34 ;
}
F_25 ( V_71 . V_79 -> V_2 ) ;
return 0 ;
}
static int F_55 (
struct V_125 * V_126 )
{
F_56 ( V_126 -> V_2 , V_126 -> V_113 ) ;
F_57 ( V_126 -> V_113 ) ;
return 0 ;
}
static int F_58 ( struct V_54 * V_53 ,
struct V_62 * V_74 ,
struct V_56 * * V_56 )
{
struct V_127 V_128 ;
struct V_129 V_130 ;
struct V_131 V_132 ;
struct V_106 * V_107 = NULL ;
struct V_56 * V_133 = NULL ;
struct V_1 * V_2 = V_53 -> V_2 ;
T_2 V_78 ;
int V_10 , V_11 ;
memset ( & V_128 , 0 , sizeof( V_128 ) ) ;
V_128 . V_74 = & V_74 -> V_85 ;
F_59 ( & V_132 ) ;
F_60 ( & V_128 . V_132 , & V_132 ) ;
V_11 = F_61 ( & V_130 , & V_132 , true , NULL ) ;
if ( V_11 )
return V_11 ;
if ( ! V_74 -> V_2 -> V_12 . V_52 ) {
F_37 ( V_74 , V_43 ) ;
F_33 ( V_74 ) ;
}
V_11 = F_38 ( & V_74 -> V_85 , & V_74 -> V_64 , true , false ) ;
if ( V_11 )
goto V_134;
V_107 = F_62 ( sizeof( struct V_106 ) , V_135 ) ;
if ( ! V_107 ) {
V_11 = - V_136 ;
goto V_134;
}
V_11 = F_63 ( V_53 , NULL , 64 , V_107 ) ;
if ( V_11 )
goto V_137;
V_78 = F_47 ( V_74 ) ;
V_107 -> V_58 [ 0 ] = F_64 ( V_118 , 0 ) ;
V_107 -> V_58 [ 1 ] = V_78 ;
V_107 -> V_58 [ 2 ] = F_64 ( V_119 , 0 ) ;
V_107 -> V_58 [ 3 ] = V_78 >> 32 ;
V_107 -> V_58 [ 4 ] = F_64 ( V_120 , 0 ) ;
V_107 -> V_58 [ 5 ] = 0 ;
for ( V_10 = 6 ; V_10 < 16 ; ++ V_10 )
V_107 -> V_58 [ V_10 ] = F_65 ( 0 ) ;
V_107 -> V_117 = 16 ;
V_11 = F_66 ( V_2 , V_53 , V_107 , 1 ,
& F_55 ,
V_138 ,
& V_133 ) ;
if ( V_11 )
goto V_139;
F_67 ( & V_130 , & V_132 , V_133 ) ;
if ( V_56 )
* V_56 = F_68 ( V_133 ) ;
F_13 ( & V_74 ) ;
F_29 ( V_133 ) ;
if ( V_140 )
return 0 ;
F_56 ( V_53 -> V_2 , V_107 ) ;
F_57 ( V_107 ) ;
return 0 ;
V_139:
F_56 ( V_53 -> V_2 , V_107 ) ;
V_137:
F_57 ( V_107 ) ;
V_134:
F_69 ( & V_130 , & V_132 ) ;
return V_11 ;
}
int F_70 ( struct V_54 * V_53 , T_1 V_55 ,
struct V_56 * * V_56 )
{
struct V_1 * V_2 = V_53 -> V_2 ;
struct V_62 * V_74 ;
T_1 * V_86 ;
int V_11 , V_10 ;
V_11 = F_11 ( V_2 , 1024 , V_42 , true ,
V_43 ,
V_44 ,
NULL , NULL , & V_74 ) ;
if ( V_11 )
return V_11 ;
V_11 = F_12 ( V_74 , false ) ;
if ( V_11 ) {
F_13 ( & V_74 ) ;
return V_11 ;
}
V_11 = F_16 ( V_74 , ( void * * ) & V_86 ) ;
if ( V_11 ) {
F_15 ( V_74 ) ;
F_13 ( & V_74 ) ;
return V_11 ;
}
V_86 [ 0 ] = F_71 ( 0x00000de4 ) ;
V_86 [ 1 ] = F_71 ( 0x00000000 ) ;
V_86 [ 2 ] = F_71 ( V_55 ) ;
V_86 [ 3 ] = F_71 ( 0x00000000 ) ;
V_86 [ 4 ] = F_71 ( 0x00000000 ) ;
V_86 [ 5 ] = F_71 ( 0x00000000 ) ;
V_86 [ 6 ] = F_71 ( 0x00000000 ) ;
V_86 [ 7 ] = F_71 ( 0x00000780 ) ;
V_86 [ 8 ] = F_71 ( 0x00000440 ) ;
V_86 [ 9 ] = F_71 ( 0x00000000 ) ;
V_86 [ 10 ] = F_71 ( 0x01b37000 ) ;
for ( V_10 = 11 ; V_10 < 1024 ; ++ V_10 )
V_86 [ V_10 ] = F_71 ( 0x0 ) ;
F_20 ( V_74 ) ;
F_15 ( V_74 ) ;
return F_58 ( V_53 , V_74 , V_56 ) ;
}
int F_26 ( struct V_54 * V_53 , T_1 V_55 ,
struct V_56 * * V_56 )
{
struct V_1 * V_2 = V_53 -> V_2 ;
struct V_62 * V_74 ;
T_1 * V_86 ;
int V_11 , V_10 ;
V_11 = F_11 ( V_2 , 1024 , V_42 , true ,
V_43 ,
V_44 ,
NULL , NULL , & V_74 ) ;
if ( V_11 )
return V_11 ;
V_11 = F_12 ( V_74 , false ) ;
if ( V_11 ) {
F_13 ( & V_74 ) ;
return V_11 ;
}
V_11 = F_16 ( V_74 , ( void * * ) & V_86 ) ;
if ( V_11 ) {
F_15 ( V_74 ) ;
F_13 ( & V_74 ) ;
return V_11 ;
}
V_86 [ 0 ] = F_71 ( 0x00000de4 ) ;
V_86 [ 1 ] = F_71 ( 0x00000002 ) ;
V_86 [ 2 ] = F_71 ( V_55 ) ;
V_86 [ 3 ] = F_71 ( 0x00000000 ) ;
for ( V_10 = 4 ; V_10 < 1024 ; ++ V_10 )
V_86 [ V_10 ] = F_71 ( 0x0 ) ;
F_20 ( V_74 ) ;
F_15 ( V_74 ) ;
return F_58 ( V_53 , V_74 , V_56 ) ;
}
static void V_14 ( struct V_141 * V_142 )
{
struct V_1 * V_2 =
F_72 ( V_142 , struct V_1 , V_12 . V_13 . V_142 ) ;
unsigned V_10 , V_143 , V_49 = 0 ;
V_143 = F_73 ( & V_2 -> V_12 . V_53 ) ;
for ( V_10 = 0 ; V_10 < V_48 ; ++ V_10 )
if ( F_24 ( & V_2 -> V_12 . V_49 [ V_10 ] ) )
++ V_49 ;
if ( V_143 == 0 && V_49 == 0 ) {
if ( V_2 -> V_144 . V_145 ) {
F_74 ( V_2 , false ) ;
} else {
F_75 ( V_2 , 0 , 0 ) ;
}
} else {
F_76 ( & V_2 -> V_12 . V_13 ,
F_77 ( V_146 ) ) ;
}
}
static void F_25 ( struct V_1 * V_2 )
{
bool V_147 = ! F_78 ( & V_2 -> V_12 . V_13 ) ;
V_147 &= F_76 ( & V_2 -> V_12 . V_13 ,
F_77 ( V_146 ) ) ;
if ( V_147 ) {
if ( V_2 -> V_144 . V_145 ) {
F_74 ( V_2 , true ) ;
} else {
F_75 ( V_2 , 53300 , 40000 ) ;
}
}
}
