static void F_1 ( struct V_1 * V_2 , char * V_3 ,
int V_4 )
{
int V_5 , V_6 = 0 ;
T_1 V_7 ;
T_1 V_8 ;
T_1 V_9 ;
T_1 type ;
T_1 V_10 = 0 ;
T_2 V_11 = 0 ;
T_3 V_12 = 0 ;
int V_13 = 0 ;
T_3 V_14 = 0 ;
T_3 V_15 [ V_16 ] ;
T_3 V_17 [ V_16 ] ;
char V_18 = 'x' ;
char V_19 [ 12 ] ;
int V_20 = 0 ;
char V_21 [ 10 ] = L_1 ;
F_2 ( L_2 ) ;
while ( V_6 < V_4 ) {
V_7 = V_3 [ V_6 ] ;
V_6 ++ ;
V_8 = F_3 ( V_7 ) ;
switch ( V_8 ) {
case 1 :
V_10 = V_3 [ V_6 ] ;
break;
case 2 :
V_11 = F_4 ( & V_3 [ V_6 ] ) ;
break;
case 3 :
V_8 = 4 ;
V_12 = F_5 ( & V_3 [ V_6 ] ) ;
break;
}
V_6 += V_8 ;
V_9 = F_6 ( V_7 ) ;
type = F_7 ( V_7 ) ;
switch ( type ) {
case V_22 :
strcpy ( V_19 , L_1 ) ;
switch ( V_9 ) {
case V_23 :
V_18 = 'I' ;
if ( V_10 == 2 )
strcpy ( V_19 , L_3 ) ;
else if ( V_10 == 3 )
strcpy ( V_19 , L_4 ) ;
F_2 ( L_5 ,
V_15 [ V_24 ] , V_13 ,
V_15 [ V_25 ] , V_15 [ V_25 ] ,
V_15 [ V_26 ] , V_15 [ V_26 ] ,
V_15 [ V_27 ] * V_15 [ V_28 ] ) ;
switch ( V_13 ) {
case 0 :
F_2 ( L_6 , V_14 ) ;
if ( V_2 -> V_29 == 0 ) {
V_2 -> V_29 = V_15 [ V_25 ] ;
V_2 -> V_30 = V_15 [ V_26 ] ;
}
break;
case 1 :
F_2 ( L_7 , V_14 ) ;
if ( V_2 -> V_31 == 0 ) {
V_2 -> V_31 = V_15 [ V_25 ] ;
V_2 -> V_32 = V_15 [ V_26 ] ;
}
break;
default:
if ( V_14 == V_33 ) {
if ( V_2 -> V_34 == 0 ) {
V_2 -> V_34 = V_15 [ V_25 ] ;
V_2 -> V_35 = V_15 [ V_26 ] ;
}
}
if ( V_14 == V_36 ) {
if ( V_2 -> V_37 == 0 ) {
V_2 -> V_37 = V_15 [ V_25 ] ;
V_2 -> V_38 = V_15 [ V_26 ] ;
}
}
if ( V_14 == V_39 ) {
if ( V_2 -> V_40 == 0 ) {
V_2 -> V_40 = V_15 [ V_25 ] ;
V_2 -> V_41 = V_15 [ V_26 ] ;
}
}
break;
}
V_13 ++ ;
break;
case V_42 :
V_18 = 'O' ;
break;
case V_43 :
V_18 = 'F' ;
break;
case V_44 :
V_18 = 'S' ;
if ( V_10 == 0 ) {
F_2 ( L_8 ) ;
strcpy ( V_19 , L_9 ) ;
} else
F_2 ( L_10 ) ;
V_20 ++ ;
for ( V_5 = 0 ; V_5 < V_20 ; V_5 ++ )
V_21 [ V_5 ] = '-' ;
V_21 [ V_5 ] = 0 ;
for ( V_5 = 0 ; V_5 < V_16 ; V_5 ++ )
V_17 [ V_5 ] = V_15 [ V_5 ] ;
break;
case V_45 :
F_2 ( L_11 ) ;
V_18 = 'E' ;
V_20 -- ;
for ( V_5 = 0 ; V_5 < V_20 ; V_5 ++ )
V_21 [ V_5 ] = '-' ;
V_21 [ V_5 ] = 0 ;
for ( V_5 = 0 ; V_5 < V_16 ; V_5 ++ )
V_15 [ V_5 ] = V_17 [ V_5 ] ;
break;
}
switch ( V_8 ) {
case 1 :
F_2 ( L_12 ,
V_21 , V_9 , V_18 , V_8 , V_19 , V_10 ) ;
break;
case 2 :
F_2 ( L_12 ,
V_21 , V_9 , V_18 , V_8 , V_19 , V_11 ) ;
break;
case 4 :
F_2 ( L_12 ,
V_21 , V_9 , V_18 , V_8 , V_19 , V_12 ) ;
break;
}
break;
case V_46 :
switch ( V_9 ) {
case V_47 :
if ( V_2 -> V_14 == 0 )
V_2 -> V_14 = V_10 ;
strcpy ( V_19 , L_13 ) ;
break;
case V_26 :
strcpy ( V_19 , L_14 ) ;
break;
case V_25 :
strcpy ( V_19 , L_15 ) ;
break;
case V_48 :
strcpy ( V_19 , L_16 ) ;
break;
case V_49 :
strcpy ( V_19 , L_17 ) ;
break;
case V_50 :
strcpy ( V_19 , L_18 ) ;
break;
case V_51 :
strcpy ( V_19 , L_19 ) ;
break;
case V_27 :
strcpy ( V_19 , L_20 ) ;
break;
case V_24 :
strcpy ( V_19 , L_21 ) ;
V_13 = 0 ;
break;
case V_28 :
strcpy ( V_19 , L_22 ) ;
break;
case V_52 :
strcpy ( V_19 , L_23 ) ;
break;
case V_53 :
strcpy ( V_19 , L_24 ) ;
break;
}
if ( V_9 < V_16 ) {
switch ( V_8 ) {
case 1 :
F_2 ( L_25 ,
V_21 , V_19 , V_9 , V_8 , V_10 ) ;
V_15 [ V_9 ] = V_10 ;
break;
case 2 :
F_2 ( L_25 ,
V_21 , V_19 , V_9 , V_8 , V_11 ) ;
V_15 [ V_9 ] = V_11 ;
break;
case 4 :
F_2 ( L_25 ,
V_21 , V_19 , V_9 , V_8 , V_12 ) ;
V_15 [ V_9 ] = V_12 ;
break;
}
} else {
F_2 ( L_26 ,
V_21 , V_9 , V_8 ) ;
}
break;
case V_54 :
switch ( V_9 ) {
case V_47 :
strcpy ( V_19 , L_13 ) ;
V_14 = V_10 ;
break;
case V_26 :
strcpy ( V_19 , L_27 ) ;
break;
case V_25 :
strcpy ( V_19 , L_28 ) ;
break;
default:
strcpy ( V_19 , L_29 ) ;
break;
}
switch ( V_8 ) {
case 1 :
F_2 ( L_30 ,
V_21 , V_9 , V_19 , V_8 , V_10 ) ;
break;
case 2 :
F_2 ( L_30 ,
V_21 , V_9 , V_19 , V_8 , V_11 ) ;
break;
case 4 :
F_2 ( L_30 ,
V_21 , V_9 , V_19 , V_8 , V_12 ) ;
break;
}
break;
}
}
}
static int F_8 ( struct V_55 * V_56 )
{
struct V_1 * V_2 = F_9 ( V_56 ) ;
V_2 -> V_57 -> V_58 = V_2 -> V_59 ;
if ( F_10 ( V_2 -> V_57 , V_60 ) )
return - V_61 ;
return 0 ;
}
static void F_11 ( struct V_55 * V_56 )
{
struct V_1 * V_2 = F_9 ( V_56 ) ;
F_12 ( V_2 -> V_57 ) ;
}
static void F_13 ( struct V_55 * V_56 )
{
struct V_1 * V_2 = F_9 ( V_56 ) ;
V_56 -> V_62 [ 0 ] = F_14 ( V_63 ) | F_14 ( V_64 ) |
F_14 ( V_65 ) ;
V_56 -> V_66 [ 0 ] = F_14 ( V_67 ) | F_14 ( V_68 ) |
F_14 ( V_69 ) ;
F_15 ( V_56 , V_70 , V_2 -> V_30 , V_2 -> V_29 ,
0 , 0 ) ;
F_15 ( V_56 , V_71 , V_2 -> V_32 , V_2 -> V_31 ,
0 , 0 ) ;
F_15 ( V_56 , V_72 , 0 , 1 , 0 , 0 ) ;
F_15 ( V_56 , V_73 , V_2 -> V_35 ,
V_2 -> V_34 , 0 , 0 ) ;
F_15 ( V_56 , V_74 , V_2 -> V_38 ,
V_2 -> V_37 , 0 , 0 ) ;
F_15 ( V_56 , V_75 , V_2 -> V_41 ,
V_2 -> V_40 , 0 , 0 ) ;
F_15 ( V_56 , V_76 , 0 , 0xFF , 0 , 0 ) ;
}
static void F_16 ( struct V_77 * V_57 )
{
struct V_1 * V_2 = V_57 -> V_78 ;
struct V_55 * V_56 ;
int V_79 ;
T_4 V_80 = 0 ;
T_5 V_81 = 0 ;
char V_82 [ 2 ] ;
V_56 = V_2 -> V_83 ;
if ( V_57 -> V_84 == - V_85 ||
V_57 -> V_84 == - V_86 ||
V_57 -> V_84 == - V_87 ) {
return;
}
if ( V_57 -> V_84 != 0 ) {
goto V_88;
}
if ( V_56 -> V_89 . V_90 == V_91 ||
V_56 -> V_89 . V_90 == V_92 ||
V_56 -> V_89 . V_90 == V_93 ) {
switch ( V_2 -> V_94 [ 0 ] ) {
case 5 :
V_80 = ( ( V_95 ) ( V_2 -> V_94 [ 8 ] ) << 1 ) ;
V_80 |= ( V_95 ) ( V_2 -> V_94 [ 7 ] >> 7 ) ;
F_17 ( V_56 , V_75 ,
V_2 -> V_94 [ 8 ] ) ;
V_2 -> V_94 [ 7 ] = ( V_96 ) ( ( V_2 -> V_94 [ 7 ] ) & 0x7F ) ;
case 4 :
if ( V_2 -> V_94 [ 6 ] & 0x40 )
V_2 -> V_94 [ 6 ] |= 0x80 ;
if ( V_2 -> V_94 [ 7 ] & 0x40 )
V_2 -> V_94 [ 7 ] |= 0x80 ;
V_81 = ( V_2 -> V_94 [ 6 ] ) ;
F_17 ( V_56 , V_73 , ( V_97 ) V_81 ) ;
V_81 = ( V_2 -> V_94 [ 7 ] ) ;
F_17 ( V_56 , V_74 , ( V_97 ) V_81 ) ;
case 2 :
case 3 :
V_80 = ( V_2 -> V_94 [ 5 ] ) & V_98 ;
F_18 ( V_56 , V_65 , V_68 , V_80 ) ;
case 1 :
V_80 = F_4 ( & V_2 -> V_94 [ 1 ] ) ;
F_17 ( V_56 , V_70 , V_80 ) ;
V_80 = F_4 ( & V_2 -> V_94 [ 3 ] ) ;
F_17 ( V_56 , V_71 , V_80 ) ;
V_80 = V_2 -> V_94 [ 5 ] & V_99 ? 1 : 0 ;
F_17 ( V_56 , V_72 , V_80 ) ;
if ( V_2 -> V_94 [ 0 ] == 1 ) {
V_80 = V_2 -> V_94 [ 5 ] & V_98 ;
F_2 ( L_31 ,
V_80 , V_80 ) ;
F_18 ( V_56 , V_65 , V_68 , V_80 ) ;
}
break;
case 7 :
F_18 ( V_56 , V_65 , V_67 ,
V_2 -> V_94 [ 1 ] ) ;
break;
}
}
if ( V_56 -> V_89 . V_90 == V_100 ||
V_56 -> V_89 . V_90 == V_101 ) {
if ( V_2 -> V_94 [ 0 ] == 2 ) {
F_18 ( V_56 , V_65 , V_67 , V_2 -> V_94 [ 1 ] ) ;
}
if ( V_2 -> V_94 [ 0 ] == 1 ) {
char V_102 ;
if ( V_2 -> V_29 > 0x10000 ) {
V_80 = ( V_95 ) ( ( ( V_95 ) ( V_2 -> V_94 [ 2 ] << 8 ) ) | ( V_96 ) V_2 -> V_94 [ 1 ] ) ;
V_80 |= ( T_4 ) ( ( ( V_96 ) V_2 -> V_94 [ 3 ] & 0x1 ) << 16 ) ;
F_17 ( V_56 , V_70 , V_80 ) ;
V_82 [ 0 ] = ( V_96 ) ( ( V_96 ) ( V_2 -> V_94 [ 3 ] ) >> 1 ) ;
V_82 [ 0 ] |= ( V_96 ) ( ( V_2 -> V_94 [ 3 ] & 0x1 ) << 7 ) ;
V_82 [ 1 ] = ( V_96 ) ( V_2 -> V_94 [ 4 ] >> 1 ) ;
V_82 [ 1 ] |= ( V_96 ) ( ( V_2 -> V_94 [ 5 ] & 0x1 ) << 7 ) ;
V_80 = F_4 ( V_82 ) ;
F_17 ( V_56 , V_71 , V_80 ) ;
V_102 = V_2 -> V_94 [ 5 ] >> 1 ;
} else {
V_80 = F_4 ( & V_2 -> V_94 [ 1 ] ) ;
F_17 ( V_56 , V_70 , V_80 ) ;
V_80 = F_4 ( & V_2 -> V_94 [ 3 ] ) ;
F_17 ( V_56 , V_71 , V_80 ) ;
V_102 = V_2 -> V_94 [ 5 ] ;
}
V_80 = V_102 & V_99 ? 1 : 0 ;
F_17 ( V_56 , V_72 , V_80 ) ;
V_80 = V_102 & 0x0F ;
#ifdef F_19
for ( V_6 = 0 ; V_6 < 5 ; V_6 ++ )
F_20 ( V_56 , V_103 + V_6 , V_80 & ( 1 << V_6 ) ) ;
#else
F_18 ( V_56 , V_65 , V_68 , V_80 ) ;
#endif
F_17 ( V_56 , V_76 , V_2 -> V_94 [ 6 ] ) ;
}
}
F_18 ( V_56 , V_65 , V_69 , V_2 -> V_94 [ 0 ] ) ;
F_21 ( V_56 ) ;
V_88:
V_79 = F_10 ( V_57 , V_104 ) ;
if ( V_79 != 0 )
F_22 ( L_32 , V_79 ) ;
}
static int F_23 ( struct V_105 * V_106 ,
const struct V_107 * V_89 )
{
struct V_1 * V_1 ;
struct V_55 * V_55 ;
struct V_108 * V_109 ;
char * V_3 ;
int V_110 = 0 , V_111 ;
int error ;
struct V_112 * V_113 ;
V_1 = F_24 ( sizeof( struct V_1 ) , V_60 ) ;
V_55 = F_25 () ;
if ( ! V_1 || ! V_55 ) {
F_22 ( L_33 ) ;
error = - V_114 ;
goto V_115;
}
V_1 -> V_83 = V_55 ;
V_1 -> V_59 = F_26 ( F_27 ( V_106 ) ) ;
V_1 -> V_94 = F_28 ( V_1 -> V_59 , V_116 ,
V_60 , & V_1 -> V_117 ) ;
if ( ! V_1 -> V_94 ) {
F_22 ( L_34 ) ;
error = - V_114 ;
goto V_115;
}
V_1 -> V_57 = F_29 ( 0 , V_60 ) ;
if ( ! V_1 -> V_57 ) {
F_22 ( L_35 ) ;
error = - V_114 ;
goto V_118;
}
V_113 = & V_106 -> V_119 [ 0 ] . V_113 [ 0 ] . V_120 ;
F_2 ( L_36 , V_106 -> V_121 ) ;
F_2 ( L_37 , V_106 -> V_122 -> V_120 . V_123 ) ;
F_2 ( L_38 , V_106 -> V_122 -> V_120 . V_124 ) ;
F_2 ( L_39 , V_113 -> V_125 , V_113 -> V_126 ) ;
if ( F_30 ( V_113 ) )
F_2 ( L_40 ) ;
F_2 ( L_41 , V_106 -> V_119 [ 0 ] . V_127 ) ;
if ( F_31 ( V_106 -> V_122 ,
V_128 , & V_109 ) != 0 ) {
F_22 ( L_42 ) ;
error = - V_61 ;
goto V_129;
}
F_2 ( L_43 ,
V_109 -> V_126 , V_109 -> V_130 ) ;
V_3 = F_24 ( F_32 ( V_109 -> V_130 ) , V_60 ) ;
if ( ! V_3 ) {
F_22 ( L_44 ) ;
error = - V_114 ;
goto V_129;
}
for ( V_111 = 0 ; V_111 < 3 ; V_111 ++ ) {
V_110 = F_33 ( V_1 -> V_59 ,
F_34 ( V_1 -> V_59 , 0 ) ,
V_131 ,
V_132 | V_133 ,
V_134 << 8 ,
0 ,
V_3 ,
F_32 ( V_109 -> V_130 ) ,
5000 ) ;
F_2 ( L_45 , V_110 ) ;
if ( V_110 == F_32 ( V_109 -> V_130 ) ) {
F_1 ( V_1 , V_3 , V_110 ) ;
break;
}
}
F_35 ( V_3 ) ;
if ( V_110 != F_32 ( V_109 -> V_130 ) ) {
F_22 ( L_46 ,
V_109 -> V_130 ) ;
error = - V_61 ;
goto V_129;
}
F_36 ( V_1 -> V_59 , V_1 -> V_135 , sizeof( V_1 -> V_135 ) ) ;
F_37 ( V_1 -> V_135 , L_47 , sizeof( V_1 -> V_135 ) ) ;
V_55 -> V_136 = F_8 ;
V_55 -> V_137 = F_11 ;
V_55 -> V_138 = L_48 ;
V_55 -> V_139 = V_1 -> V_135 ;
F_38 ( V_55 , V_1 ) ;
F_13 ( V_55 ) ;
F_39 ( V_1 -> V_59 , & V_55 -> V_89 ) ;
V_55 -> V_58 . V_140 = & V_106 -> V_58 ;
V_113 = & V_106 -> V_119 [ 0 ] . V_113 [ 0 ] . V_120 ;
F_40 ( V_1 -> V_57 ,
V_1 -> V_59 ,
F_41 ( V_1 -> V_59 ,
V_113 -> V_141 ) ,
V_1 -> V_94 ,
V_116 ,
F_16 ,
V_1 ,
V_113 -> V_142 ) ;
V_1 -> V_57 -> V_143 = V_1 -> V_117 ;
V_1 -> V_57 -> V_144 |= V_145 ;
F_42 ( V_106 , V_1 ) ;
error = F_43 ( V_55 ) ;
if ( error )
goto V_129;
return 0 ;
V_129:
F_44 ( V_1 -> V_57 ) ;
V_118:
F_45 ( V_1 -> V_59 , V_116 ,
V_1 -> V_94 , V_1 -> V_117 ) ;
V_115:
F_46 ( V_55 ) ;
F_35 ( V_1 ) ;
return error ;
}
static void F_47 ( struct V_105 * V_146 )
{
struct V_1 * V_1 = F_48 ( V_146 ) ;
if ( V_1 ) {
F_49 ( V_1 -> V_83 ) ;
F_12 ( V_1 -> V_57 ) ;
F_44 ( V_1 -> V_57 ) ;
F_45 ( V_1 -> V_59 , V_116 ,
V_1 -> V_94 , V_1 -> V_117 ) ;
F_35 ( V_1 ) ;
}
F_50 ( & V_146 -> V_58 , L_49 ) ;
}
static int T_6 F_51 ( void )
{
int error ;
error = F_52 ( & V_147 ) ;
if ( error ) {
F_22 ( L_50 , error ) ;
return error ;
}
F_53 ( L_51 , V_148 ) ;
return 0 ;
}
static void T_7 F_54 ( void )
{
F_55 ( & V_147 ) ;
}
