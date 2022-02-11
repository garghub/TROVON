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
default:
return - V_30 ;
}
V_11 = F_4 ( & V_2 -> V_12 . V_31 , V_4 , V_2 -> V_32 ) ;
if ( V_11 ) {
F_5 ( V_2 -> V_32 , L_1 ,
V_4 ) ;
return V_11 ;
}
V_11 = F_6 ( V_2 -> V_12 . V_31 ) ;
if ( V_11 ) {
F_5 ( V_2 -> V_32 , L_2 ,
V_4 ) ;
F_7 ( V_2 -> V_12 . V_31 ) ;
V_2 -> V_12 . V_31 = NULL ;
return V_11 ;
}
V_6 = ( const struct V_5 * ) V_2 -> V_12 . V_31 -> V_33 ;
V_9 = F_8 ( V_6 -> V_34 ) & 0xff ;
V_7 = ( F_8 ( V_6 -> V_34 ) >> 24 ) & 0xff ;
V_8 = ( F_8 ( V_6 -> V_34 ) >> 8 ) & 0xff ;
F_9 ( L_3 ,
V_7 , V_8 , V_9 ) ;
V_3 = F_10 ( F_8 ( V_6 -> V_35 ) + 8 )
+ V_36 + V_37 ;
V_11 = F_11 ( V_2 , V_3 , V_38 , true ,
V_39 , 0 , NULL , & V_2 -> V_12 . V_40 ) ;
if ( V_11 ) {
F_5 ( V_2 -> V_32 , L_4 , V_11 ) ;
return V_11 ;
}
V_11 = F_12 ( V_2 -> V_12 . V_40 , false ) ;
if ( V_11 ) {
F_13 ( & V_2 -> V_12 . V_40 ) ;
F_5 ( V_2 -> V_32 , L_5 , V_11 ) ;
return V_11 ;
}
V_11 = F_14 ( V_2 -> V_12 . V_40 , V_39 ,
& V_2 -> V_12 . V_41 ) ;
if ( V_11 ) {
F_15 ( V_2 -> V_12 . V_40 ) ;
F_13 ( & V_2 -> V_12 . V_40 ) ;
F_5 ( V_2 -> V_32 , L_6 , V_11 ) ;
return V_11 ;
}
V_11 = F_16 ( V_2 -> V_12 . V_40 , & V_2 -> V_12 . V_42 ) ;
if ( V_11 ) {
F_5 ( V_2 -> V_32 , L_7 , V_11 ) ;
return V_11 ;
}
F_15 ( V_2 -> V_12 . V_40 ) ;
for ( V_10 = 0 ; V_10 < V_43 ; ++ V_10 ) {
F_17 ( & V_2 -> V_12 . V_44 [ V_10 ] , 0 ) ;
V_2 -> V_12 . V_45 [ V_10 ] = NULL ;
}
if ( ! F_18 ( V_2 , V_46 , 5 , 0 ) )
V_2 -> V_12 . V_47 = true ;
return 0 ;
}
int F_19 ( struct V_1 * V_2 )
{
int V_11 ;
if ( V_2 -> V_12 . V_40 == NULL )
return 0 ;
V_11 = F_12 ( V_2 -> V_12 . V_40 , false ) ;
if ( ! V_11 ) {
F_20 ( V_2 -> V_12 . V_40 ) ;
F_21 ( V_2 -> V_12 . V_40 ) ;
F_15 ( V_2 -> V_12 . V_40 ) ;
}
F_13 ( & V_2 -> V_12 . V_40 ) ;
F_22 ( & V_2 -> V_12 . V_48 ) ;
F_7 ( V_2 -> V_12 . V_31 ) ;
return 0 ;
}
int F_23 ( struct V_1 * V_2 )
{
unsigned V_49 ;
void * V_50 ;
const struct V_5 * V_6 ;
int V_10 ;
if ( V_2 -> V_12 . V_40 == NULL )
return 0 ;
for ( V_10 = 0 ; V_10 < V_43 ; ++ V_10 )
if ( F_24 ( & V_2 -> V_12 . V_44 [ V_10 ] ) )
break;
if ( V_10 == V_43 )
return 0 ;
V_6 = ( const struct V_5 * ) V_2 -> V_12 . V_31 -> V_33 ;
V_49 = F_25 ( V_2 -> V_12 . V_40 ) ;
V_49 -= F_8 ( V_6 -> V_35 ) ;
V_50 = V_2 -> V_12 . V_42 ;
V_50 += F_8 ( V_6 -> V_35 ) ;
V_2 -> V_12 . V_51 = F_26 ( V_49 , V_52 ) ;
memcpy ( V_2 -> V_12 . V_51 , V_50 , V_49 ) ;
return 0 ;
}
int F_27 ( struct V_1 * V_2 )
{
unsigned V_49 ;
void * V_50 ;
const struct V_5 * V_6 ;
unsigned V_53 ;
if ( V_2 -> V_12 . V_40 == NULL )
return - V_30 ;
V_6 = ( const struct V_5 * ) V_2 -> V_12 . V_31 -> V_33 ;
V_53 = F_8 ( V_6 -> V_54 ) ;
memcpy ( V_2 -> V_12 . V_42 , ( V_2 -> V_12 . V_31 -> V_33 ) + V_53 ,
( V_2 -> V_12 . V_31 -> V_49 ) - V_53 ) ;
V_49 = F_25 ( V_2 -> V_12 . V_40 ) ;
V_49 -= F_8 ( V_6 -> V_35 ) ;
V_50 = V_2 -> V_12 . V_42 ;
V_50 += F_8 ( V_6 -> V_35 ) ;
if ( V_2 -> V_12 . V_51 != NULL ) {
memcpy ( V_50 , V_2 -> V_12 . V_51 , V_49 ) ;
F_28 ( V_2 -> V_12 . V_51 ) ;
V_2 -> V_12 . V_51 = NULL ;
} else
memset ( V_50 , 0 , V_49 ) ;
return 0 ;
}
void F_29 ( struct V_1 * V_2 , struct V_55 * V_45 )
{
struct V_56 * V_48 = & V_2 -> V_12 . V_48 ;
int V_10 , V_11 ;
for ( V_10 = 0 ; V_10 < V_43 ; ++ V_10 ) {
T_1 V_57 = F_24 ( & V_2 -> V_12 . V_44 [ V_10 ] ) ;
if ( V_57 != 0 && V_2 -> V_12 . V_45 [ V_10 ] == V_45 ) {
struct V_58 * V_59 ;
F_30 ( V_2 ) ;
V_11 = F_31 ( V_48 , V_57 , & V_59 ) ;
if ( V_11 ) {
F_32 ( L_8 , V_11 ) ;
continue;
}
F_33 ( V_59 , false ) ;
F_34 ( & V_59 ) ;
V_2 -> V_12 . V_45 [ V_10 ] = NULL ;
F_17 ( & V_2 -> V_12 . V_44 [ V_10 ] , 0 ) ;
}
}
}
static void F_35 ( struct V_60 * V_61 )
{
int V_10 ;
for ( V_10 = 0 ; V_10 < V_61 -> V_62 . V_63 ; ++ V_10 ) {
V_61 -> V_64 [ V_10 ] . V_65 = 0 >> V_66 ;
V_61 -> V_64 [ V_10 ] . V_67 = ( 256 * 1024 * 1024 ) >> V_66 ;
}
}
static int F_36 ( struct V_68 * V_69 )
{
struct V_70 * V_71 ;
struct V_60 * V_72 ;
T_1 V_73 , V_74 , V_75 ;
T_2 V_76 ;
int V_11 = 0 ;
V_74 = F_37 ( V_69 -> V_77 , V_69 -> V_78 , V_69 -> V_79 ) ;
V_75 = F_37 ( V_69 -> V_77 , V_69 -> V_78 , V_69 -> V_80 ) ;
V_76 = ( ( T_2 ) V_74 ) | ( ( ( T_2 ) V_75 ) << 32 ) ;
V_71 = F_38 ( V_69 -> V_77 , V_76 , & V_72 ) ;
if ( V_71 == NULL ) {
F_32 ( L_9 , V_76 ) ;
return - V_30 ;
}
if ( ! V_69 -> V_77 -> V_2 -> V_12 . V_47 ) {
V_73 = F_37 ( V_69 -> V_77 , V_69 -> V_78 , V_69 -> V_81 ) >> 1 ;
if ( V_73 == 0x0 || V_73 == 0x3 ) {
T_1 V_82 = V_39 ;
F_39 ( V_72 , V_82 ) ;
}
F_35 ( V_72 ) ;
V_11 = F_40 ( & V_72 -> V_83 , & V_72 -> V_62 , false , false ) ;
}
return V_11 ;
}
static int F_41 ( T_1 * V_84 , unsigned V_85 [] )
{
unsigned V_86 = V_84 [ 4 ] ;
unsigned V_87 = V_84 [ 6 ] ;
unsigned V_88 = V_84 [ 7 ] ;
unsigned V_89 = V_84 [ 9 ] ;
unsigned V_90 = V_84 [ 28 ] ;
unsigned V_91 = V_84 [ 57 ] ;
unsigned V_92 = V_87 / 16 ;
unsigned V_93 = F_42 ( V_88 / 16 , 2 ) ;
unsigned V_94 = V_92 * V_93 ;
unsigned V_95 , V_96 , V_97 , V_98 , V_99 ;
V_95 = V_87 * V_88 ;
V_95 += V_95 / 2 ;
V_95 = F_42 ( V_95 , 1024 ) ;
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
V_96 = F_43 ( V_92 , V_93 ) ;
V_97 += F_42 ( V_96 * 7 * 16 , 64 ) ;
break;
case 3 :
V_97 = V_95 * 3 ;
break;
case 4 :
V_97 = V_95 * 3 ;
V_97 += V_92 * V_93 * 64 ;
V_97 += F_42 ( V_92 * V_93 * 32 , 64 ) ;
break;
case 16 :
V_95 = ( F_42 ( V_87 , 16 ) * F_42 ( V_88 , 16 ) * 3 ) / 2 ;
V_95 = F_42 ( V_95 , 256 ) ;
V_98 = ( F_8 ( V_84 [ 59 ] ) & 0xff ) + 2 ;
V_97 = V_95 * V_98 ;
V_99 = ( ( V_87 + 255 ) / 16 ) * ( ( V_88 + 255 ) / 16 )
* 16 * V_98 + 52 * 1024 ;
break;
default:
F_32 ( L_10 , V_86 ) ;
return - V_30 ;
}
if ( V_87 > V_90 ) {
F_32 ( L_11 ) ;
return - V_30 ;
}
if ( V_89 < V_97 ) {
F_32 ( L_12 ,
V_89 , V_97 ) ;
return - V_30 ;
}
V_85 [ 0x1 ] = V_89 ;
V_85 [ 0x2 ] = V_95 ;
V_85 [ 0x4 ] = V_99 ;
return 0 ;
}
static int F_44 ( struct V_68 * V_69 ,
struct V_60 * V_72 , unsigned V_53 )
{
struct V_1 * V_2 = V_69 -> V_77 -> V_2 ;
T_3 * V_84 , V_100 , V_57 ;
struct V_59 * V_101 ;
void * V_50 ;
int V_10 , V_11 ;
if ( V_53 & 0x3F ) {
F_32 ( L_13 ) ;
return - V_30 ;
}
V_101 = F_45 ( V_72 -> V_83 . V_102 ) ;
if ( V_101 ) {
V_11 = F_33 ( (struct V_58 * ) V_101 , false ) ;
if ( V_11 ) {
F_32 ( L_14 , V_11 ) ;
return V_11 ;
}
}
V_11 = F_16 ( V_72 , & V_50 ) ;
if ( V_11 ) {
F_32 ( L_15 , V_11 ) ;
return V_11 ;
}
V_84 = V_50 + V_53 ;
V_100 = V_84 [ 1 ] ;
V_57 = V_84 [ 2 ] ;
if ( V_57 == 0 ) {
F_32 ( L_16 ) ;
return - V_30 ;
}
if ( V_100 == 1 ) {
V_11 = F_41 ( V_84 , V_69 -> V_85 ) ;
F_20 ( V_72 ) ;
if ( V_11 )
return V_11 ;
} else if ( V_100 == 2 ) {
for ( V_10 = 0 ; V_10 < V_43 ; ++ V_10 )
F_46 ( & V_2 -> V_12 . V_44 [ V_10 ] , V_57 , 0 ) ;
F_20 ( V_72 ) ;
return 0 ;
} else {
F_20 ( V_72 ) ;
if ( V_100 != 0 ) {
F_32 ( L_17 , V_100 ) ;
return - V_30 ;
}
}
for ( V_10 = 0 ; V_10 < V_43 ; ++ V_10 ) {
if ( F_24 ( & V_2 -> V_12 . V_44 [ V_10 ] ) == V_57 )
return 0 ;
}
for ( V_10 = 0 ; V_10 < V_43 ; ++ V_10 ) {
if ( ! F_46 ( & V_2 -> V_12 . V_44 [ V_10 ] , 0 , V_57 ) ) {
V_2 -> V_12 . V_45 [ V_10 ] = V_69 -> V_77 -> V_45 ;
return 0 ;
}
}
F_32 ( L_18 ) ;
return - V_30 ;
}
static int F_47 ( struct V_68 * V_69 )
{
struct V_70 * V_71 ;
struct V_60 * V_72 ;
struct V_103 * V_104 ;
T_1 V_73 , V_74 , V_75 ;
T_2 V_105 , V_106 ;
T_2 V_76 ;
int V_11 ;
V_74 = F_37 ( V_69 -> V_77 , V_69 -> V_78 , V_69 -> V_79 ) ;
V_75 = F_37 ( V_69 -> V_77 , V_69 -> V_78 , V_69 -> V_80 ) ;
V_76 = ( ( T_2 ) V_74 ) | ( ( ( T_2 ) V_75 ) << 32 ) ;
V_71 = F_38 ( V_69 -> V_77 , V_76 , & V_72 ) ;
if ( V_71 == NULL )
return - V_30 ;
V_105 = F_48 ( V_72 ) ;
V_106 = ( V_71 -> V_107 . V_108 + 1 - V_71 -> V_107 . V_105 ) ;
V_106 = V_106 * V_109 + V_105 ;
V_76 -= ( ( T_2 ) V_71 -> V_107 . V_105 ) * V_109 ;
V_105 += V_76 ;
V_104 = & V_69 -> V_77 -> V_110 [ V_69 -> V_78 ] ;
V_104 -> V_50 [ V_69 -> V_79 ] = V_105 & 0xFFFFFFFF ;
V_104 -> V_50 [ V_69 -> V_80 ] = V_105 >> 32 ;
V_73 = F_37 ( V_69 -> V_77 , V_69 -> V_78 , V_69 -> V_81 ) >> 1 ;
if ( V_73 < 0x4 ) {
if ( ( V_106 - V_105 ) < V_69 -> V_85 [ V_73 ] ) {
F_32 ( L_19 , V_73 ,
( unsigned ) ( V_106 - V_105 ) ,
V_69 -> V_85 [ V_73 ] ) ;
return - V_30 ;
}
} else if ( V_73 == 0x206 ) {
if ( ( V_106 - V_105 ) < V_69 -> V_85 [ 4 ] ) {
F_32 ( L_19 , V_73 ,
( unsigned ) ( V_106 - V_105 ) ,
V_69 -> V_85 [ 4 ] ) ;
return - V_30 ;
}
} else if ( ( V_73 != 0x100 ) && ( V_73 != 0x204 ) ) {
F_32 ( L_20 , V_73 ) ;
return - V_30 ;
}
if ( ! V_69 -> V_77 -> V_2 -> V_12 . V_47 ) {
if ( ( V_105 >> 28 ) != ( ( V_106 - 1 ) >> 28 ) ) {
F_32 ( L_21 ,
V_105 , V_106 ) ;
return - V_30 ;
}
if ( ( V_73 == 0 || V_73 == 0x3 ) &&
( V_105 >> 28 ) != ( V_69 -> V_77 -> V_2 -> V_12 . V_41 >> 28 ) ) {
F_32 ( L_22 ,
V_105 , V_106 ) ;
return - V_30 ;
}
}
if ( V_73 == 0 ) {
V_69 -> V_111 = true ;
V_11 = F_44 ( V_69 , V_72 , V_76 ) ;
if ( V_11 )
return V_11 ;
} else if ( ! V_69 -> V_111 ) {
F_32 ( L_23 ) ;
return - V_30 ;
}
return 0 ;
}
static int F_49 ( struct V_68 * V_69 ,
int (* F_50)( struct V_68 * V_69 ) )
{
struct V_103 * V_104 = & V_69 -> V_77 -> V_110 [ V_69 -> V_78 ] ;
int V_10 , V_11 ;
V_69 -> V_81 ++ ;
for ( V_10 = 0 ; V_10 <= V_69 -> V_112 ; ++ V_10 ) {
unsigned V_113 = V_69 -> V_113 + V_10 ;
if ( V_69 -> V_81 >= V_104 -> V_114 ) {
F_32 ( L_24 ) ;
return - V_30 ;
}
switch ( V_113 ) {
case V_115 :
V_69 -> V_79 = V_69 -> V_81 ;
break;
case V_116 :
V_69 -> V_80 = V_69 -> V_81 ;
break;
case V_117 :
V_11 = F_50 ( V_69 ) ;
if ( V_11 )
return V_11 ;
break;
case V_118 :
break;
default:
F_32 ( L_25 , V_113 ) ;
return - V_30 ;
}
V_69 -> V_81 ++ ;
}
return 0 ;
}
static int F_51 ( struct V_68 * V_69 ,
int (* F_50)( struct V_68 * V_69 ) )
{
struct V_103 * V_104 = & V_69 -> V_77 -> V_110 [ V_69 -> V_78 ] ;
int V_11 ;
for ( V_69 -> V_81 = 0 ; V_69 -> V_81 < V_104 -> V_114 ; ) {
T_1 V_73 = F_37 ( V_69 -> V_77 , V_69 -> V_78 , V_69 -> V_81 ) ;
unsigned type = F_52 ( V_73 ) ;
switch ( type ) {
case V_119 :
V_69 -> V_113 = F_53 ( V_73 ) ;
V_69 -> V_112 = F_54 ( V_73 ) ;
V_11 = F_49 ( V_69 , F_50 ) ;
if ( V_11 )
return V_11 ;
break;
case V_120 :
++ V_69 -> V_81 ;
break;
default:
F_32 ( L_26 , type ) ;
return - V_30 ;
}
}
return 0 ;
}
int F_55 ( struct V_121 * V_77 , T_1 V_78 )
{
struct V_68 V_69 = {} ;
unsigned V_85 [] = {
[ 0x00000000 ] = 2048 ,
[ 0x00000001 ] = 0xFFFFFFFF ,
[ 0x00000002 ] = 0xFFFFFFFF ,
[ 0x00000003 ] = 2048 ,
[ 0x00000004 ] = 0xFFFFFFFF ,
} ;
struct V_103 * V_104 = & V_77 -> V_110 [ V_78 ] ;
int V_11 ;
if ( V_104 -> V_114 % 16 ) {
F_32 ( L_27 ,
V_104 -> V_114 ) ;
return - V_30 ;
}
V_69 . V_77 = V_77 ;
V_69 . V_85 = V_85 ;
V_69 . V_78 = V_78 ;
V_11 = F_51 ( & V_69 , F_36 ) ;
if ( V_11 )
return V_11 ;
V_11 = F_51 ( & V_69 , F_47 ) ;
if ( V_11 )
return V_11 ;
if ( ! V_69 . V_111 ) {
F_32 ( L_28 ) ;
return - V_30 ;
}
F_30 ( V_69 . V_77 -> V_2 ) ;
return 0 ;
}
static int F_56 ( struct V_56 * V_48 ,
struct V_60 * V_72 ,
struct V_58 * * V_59 )
{
struct V_122 V_123 ;
struct V_124 V_125 ;
struct V_126 V_127 ;
struct V_103 V_104 ;
T_2 V_76 ;
int V_10 , V_11 ;
memset ( & V_123 , 0 , sizeof( V_123 ) ) ;
V_123 . V_72 = & V_72 -> V_83 ;
F_57 ( & V_127 ) ;
F_58 ( & V_123 . V_127 , & V_127 ) ;
V_11 = F_59 ( & V_125 , & V_127 , true , NULL ) ;
if ( V_11 )
return V_11 ;
if ( ! V_72 -> V_2 -> V_12 . V_47 ) {
F_39 ( V_72 , V_39 ) ;
F_35 ( V_72 ) ;
}
V_11 = F_40 ( & V_72 -> V_83 , & V_72 -> V_62 , true , false ) ;
if ( V_11 )
goto V_128;
V_11 = F_60 ( V_48 , NULL , 64 , & V_104 ) ;
if ( V_11 )
goto V_128;
V_76 = F_48 ( V_72 ) ;
V_104 . V_50 [ 0 ] = F_61 ( V_115 , 0 ) ;
V_104 . V_50 [ 1 ] = V_76 ;
V_104 . V_50 [ 2 ] = F_61 ( V_116 , 0 ) ;
V_104 . V_50 [ 3 ] = V_76 >> 32 ;
V_104 . V_50 [ 4 ] = F_61 ( V_117 , 0 ) ;
V_104 . V_50 [ 5 ] = 0 ;
for ( V_10 = 6 ; V_10 < 16 ; ++ V_10 )
V_104 . V_50 [ V_10 ] = F_62 ( 0 ) ;
V_104 . V_114 = 16 ;
V_11 = F_63 ( V_48 -> V_2 , 1 , & V_104 , V_129 ) ;
if ( V_11 )
goto V_128;
F_64 ( & V_125 , & V_127 , & V_104 . V_59 -> V_130 ) ;
if ( V_59 )
* V_59 = F_65 ( V_104 . V_59 ) ;
F_66 ( V_48 -> V_2 , & V_104 ) ;
F_13 ( & V_72 ) ;
return 0 ;
V_128:
F_67 ( & V_125 , & V_127 ) ;
return V_11 ;
}
int F_68 ( struct V_56 * V_48 , T_1 V_57 ,
struct V_58 * * V_59 )
{
struct V_1 * V_2 = V_48 -> V_2 ;
struct V_60 * V_72 ;
T_1 * V_84 ;
int V_11 , V_10 ;
V_11 = F_11 ( V_2 , 1024 , V_38 , true ,
V_39 , 0 , NULL , & V_72 ) ;
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
V_84 [ 0 ] = F_69 ( 0x00000de4 ) ;
V_84 [ 1 ] = F_69 ( 0x00000000 ) ;
V_84 [ 2 ] = F_69 ( V_57 ) ;
V_84 [ 3 ] = F_69 ( 0x00000000 ) ;
V_84 [ 4 ] = F_69 ( 0x00000000 ) ;
V_84 [ 5 ] = F_69 ( 0x00000000 ) ;
V_84 [ 6 ] = F_69 ( 0x00000000 ) ;
V_84 [ 7 ] = F_69 ( 0x00000780 ) ;
V_84 [ 8 ] = F_69 ( 0x00000440 ) ;
V_84 [ 9 ] = F_69 ( 0x00000000 ) ;
V_84 [ 10 ] = F_69 ( 0x01b37000 ) ;
for ( V_10 = 11 ; V_10 < 1024 ; ++ V_10 )
V_84 [ V_10 ] = F_69 ( 0x0 ) ;
F_20 ( V_72 ) ;
F_15 ( V_72 ) ;
return F_56 ( V_48 , V_72 , V_59 ) ;
}
int F_31 ( struct V_56 * V_48 , T_1 V_57 ,
struct V_58 * * V_59 )
{
struct V_1 * V_2 = V_48 -> V_2 ;
struct V_60 * V_72 ;
T_1 * V_84 ;
int V_11 , V_10 ;
V_11 = F_11 ( V_2 , 1024 , V_38 , true ,
V_39 , 0 , NULL , & V_72 ) ;
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
V_84 [ 0 ] = F_69 ( 0x00000de4 ) ;
V_84 [ 1 ] = F_69 ( 0x00000002 ) ;
V_84 [ 2 ] = F_69 ( V_57 ) ;
V_84 [ 3 ] = F_69 ( 0x00000000 ) ;
for ( V_10 = 4 ; V_10 < 1024 ; ++ V_10 )
V_84 [ V_10 ] = F_69 ( 0x0 ) ;
F_20 ( V_72 ) ;
F_15 ( V_72 ) ;
return F_56 ( V_48 , V_72 , V_59 ) ;
}
static void V_14 ( struct V_131 * V_132 )
{
struct V_1 * V_2 =
F_70 ( V_132 , struct V_1 , V_12 . V_13 . V_132 ) ;
unsigned V_10 , V_133 , V_44 = 0 ;
V_133 = F_71 ( & V_2 -> V_12 . V_48 ) ;
for ( V_10 = 0 ; V_10 < V_43 ; ++ V_10 )
if ( F_24 ( & V_2 -> V_12 . V_44 [ V_10 ] ) )
++ V_44 ;
if ( V_133 == 0 && V_44 == 0 ) {
if ( V_2 -> V_134 . V_135 ) {
F_72 ( V_2 , false ) ;
} else {
F_73 ( V_2 , 0 , 0 ) ;
}
} else {
F_74 ( & V_2 -> V_12 . V_13 ,
F_75 ( V_136 ) ) ;
}
}
static void F_30 ( struct V_1 * V_2 )
{
bool V_137 = ! F_76 ( & V_2 -> V_12 . V_13 ) ;
V_137 &= F_74 ( & V_2 -> V_12 . V_13 ,
F_75 ( V_136 ) ) ;
if ( V_137 ) {
if ( V_2 -> V_134 . V_135 ) {
F_72 ( V_2 , true ) ;
} else {
F_73 ( V_2 , 53300 , 40000 ) ;
}
}
}
