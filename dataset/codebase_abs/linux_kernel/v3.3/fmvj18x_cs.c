static int F_1 ( struct V_1 * V_2 )
{
T_1 * V_3 ;
struct V_4 * V_5 ;
F_2 ( & V_2 -> V_5 , L_1 ) ;
V_5 = F_3 ( sizeof( T_1 ) ) ;
if ( ! V_5 )
return - V_6 ;
V_3 = F_4 ( V_5 ) ;
V_2 -> V_7 = V_5 ;
V_3 -> V_8 = V_2 ;
V_3 -> V_9 = NULL ;
V_2 -> V_10 [ 0 ] -> V_11 = 32 ;
V_2 -> V_10 [ 0 ] -> V_12 |= V_13 ;
V_2 -> V_14 |= V_15 ;
V_5 -> V_16 = & V_17 ;
V_5 -> V_18 = V_19 ;
F_5 ( V_5 , & V_20 ) ;
return F_6 ( V_2 ) ;
}
static void F_7 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_7 ;
F_2 ( & V_2 -> V_5 , L_2 ) ;
F_8 ( V_5 ) ;
F_9 ( V_2 ) ;
F_10 ( V_5 ) ;
}
static int F_11 ( struct V_1 * V_2 )
{
int V_21 , V_22 ;
static const unsigned int V_23 [ 5 ] =
{ 0x3f8 , 0x2f8 , 0x3e8 , 0x2e8 , 0x0 } ;
for ( V_21 = 0 ; V_21 < 5 ; V_21 ++ ) {
V_2 -> V_10 [ 1 ] -> V_24 = V_23 [ V_21 ] ;
V_2 -> V_10 [ 1 ] -> V_12 |= V_25 ;
if ( V_2 -> V_10 [ 1 ] -> V_24 == 0 ) {
V_2 -> V_10 [ 1 ] -> V_11 = 0 ;
F_12 ( L_3 ) ;
}
V_22 = F_13 ( V_2 ) ;
if ( V_22 == 0 )
return V_22 ;
}
return V_22 ;
}
static int F_14 ( struct V_1 * V_2 )
{
int V_22 ;
unsigned int V_26 ;
for ( V_26 = 0x300 ; V_26 < 0x3e0 ; V_26 += 0x20 ) {
V_2 -> V_10 [ 0 ] -> V_24 = V_26 ;
V_22 = F_13 ( V_2 ) ;
if ( V_22 == 0 ) {
V_2 -> V_27 =
( ( V_2 -> V_10 [ 0 ] -> V_24 & 0x0f0 ) >> 3 ) | 0x22 ;
return V_22 ;
}
}
return V_22 ;
}
static int F_15 ( struct V_1 * V_8 , void * V_28 )
{
return 0 ;
}
static int F_6 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_7 ;
T_1 * V_3 = F_4 ( V_5 ) ;
int V_21 , V_22 ;
unsigned int V_26 ;
T_2 V_29 ;
char * V_30 = L_4 ;
T_3 * V_31 ;
T_4 V_32 ;
T_5 V_33 [ 32 ] ;
F_2 ( & V_2 -> V_5 , L_5 ) ;
V_2 -> V_34 = 5 ;
V_32 = F_16 ( V_2 , V_35 , & V_31 ) ;
F_17 ( V_31 ) ;
if ( V_32 ) {
V_22 = F_18 ( V_2 , F_15 , NULL ) ;
if ( V_22 != 0 )
goto V_36;
switch ( V_2 -> V_37 ) {
case V_38 :
V_29 = V_39 ;
if ( V_2 -> V_40 == V_41 ||
V_2 -> V_40 == V_42 ||
V_2 -> V_40 == V_43 ) {
V_2 -> V_44 = 0x800 ;
V_2 -> V_27 = 0x47 ;
V_2 -> V_10 [ 1 ] -> V_11 = 8 ;
}
break;
case V_45 :
V_29 = V_46 ;
V_2 -> V_44 = 0x800 ;
V_2 -> V_27 = 0x47 ;
V_2 -> V_10 [ 1 ] -> V_11 = 8 ;
break;
case V_47 :
V_29 = V_48 ;
V_2 -> V_44 = 0x800 ;
V_2 -> V_27 = 0x47 ;
V_2 -> V_10 [ 1 ] -> V_11 = 8 ;
break;
case V_49 :
V_29 = V_50 ;
break;
case V_51 :
if ( V_2 -> V_44 == 0x0fe0 )
V_29 = V_52 ;
else if ( V_2 -> V_40 == V_53 )
V_29 = V_54 ;
else if ( V_2 -> V_40 == V_55 )
V_29 = V_54 ;
else
V_29 = V_56 ;
break;
default:
V_29 = V_54 ;
}
} else {
switch ( V_2 -> V_37 ) {
case V_51 :
if ( V_2 -> V_40 == V_55 ) {
V_29 = V_57 ;
V_2 -> V_27 = 0x20 ;
} else {
V_29 = V_52 ;
V_2 -> V_27 = 1 ;
}
break;
case V_58 :
V_29 = V_59 ;
break;
default:
V_29 = V_52 ;
V_2 -> V_27 = 1 ;
}
}
if ( V_2 -> V_10 [ 1 ] -> V_11 != 0 ) {
V_22 = F_11 ( V_2 ) ;
if ( V_22 != 0 ) goto V_36;
} else if ( V_29 == V_59 ) {
V_22 = F_14 ( V_2 ) ;
if ( V_22 != 0 ) goto V_36;
} else {
V_22 = F_13 ( V_2 ) ;
if ( V_22 )
goto V_36;
}
V_22 = F_19 ( V_2 , V_60 ) ;
if ( V_22 )
goto V_36;
V_22 = F_20 ( V_2 ) ;
if ( V_22 )
goto V_36;
V_5 -> V_61 = V_2 -> V_61 ;
V_5 -> V_62 = V_2 -> V_10 [ 0 ] -> V_24 ;
if ( F_21 ( V_2 -> V_10 [ 1 ] ) != 0 ) {
V_22 = F_22 ( V_2 ) ;
if ( V_22 != 0 ) goto V_36;
}
V_26 = V_5 -> V_62 ;
if ( V_63 == 0 )
F_23 ( V_64 , V_26 + V_65 ) ;
else
F_23 ( V_66 , V_26 + V_65 ) ;
if ( V_29 == V_52 )
F_23 ( V_67 , V_26 + V_68 ) ;
else
F_23 ( V_69 , V_26 + V_68 ) ;
switch ( V_29 ) {
case V_54 :
case V_39 :
case V_56 :
case V_50 :
case V_46 :
case V_48 :
if ( V_29 == V_54 ) {
V_30 = L_6 ;
V_32 = F_16 ( V_2 , V_35 , & V_31 ) ;
if ( V_32 < 11 ) {
F_17 ( V_31 ) ;
goto V_36;
}
for ( V_21 = 5 ; V_21 < 11 ; V_21 ++ )
V_5 -> V_70 [ V_21 ] = V_31 [ V_21 ] ;
F_17 ( V_31 ) ;
} else {
if ( F_24 ( V_2 , V_5 ) )
goto V_36;
if( V_29 == V_39 ) {
V_30 = L_7 ;
} else if( V_29 == V_56 ) {
V_30 = L_8 ;
} else if( V_29 == V_46 ) {
V_30 = L_9 ;
} else if( V_29 == V_48 ) {
V_30 = L_10 ;
} else {
V_30 = L_11 ;
}
}
break;
case V_59 :
for ( V_21 = 0 ; V_21 < 6 ; V_21 ++ )
V_5 -> V_70 [ V_21 ] = F_25 ( V_26 + V_71 + V_21 ) ;
V_30 = L_12 ;
break;
case V_57 :
if ( F_26 ( V_2 , V_33 ) == - 1 ) {
F_12 ( L_13 ) ;
goto V_36;
}
for ( V_21 = 0 ; V_21 < 6 ; V_21 ++ ) {
V_5 -> V_70 [ V_21 ] = V_33 [ V_21 ] ;
}
V_30 = L_6 ;
break;
case V_52 :
default:
for ( V_21 = 0 ; V_21 < 6 ; V_21 ++ )
V_5 -> V_70 [ V_21 ] = F_25 ( V_26 + V_72 + V_21 ) ;
V_30 = L_14 ;
break;
}
V_3 -> V_29 = V_29 ;
F_27 ( V_5 , & V_2 -> V_5 ) ;
if ( F_28 ( V_5 ) != 0 ) {
F_12 ( L_15 ) ;
goto V_36;
}
F_29 ( V_5 , L_16 ,
V_30 , V_63 == 0 ? L_17 : L_18 ,
V_5 -> V_62 , V_5 -> V_61 , V_5 -> V_70 ) ;
return 0 ;
V_36:
F_9 ( V_2 ) ;
return - V_73 ;
}
static int F_26 ( struct V_1 * V_2 , T_5 * V_74 )
{
T_5 T_6 * V_9 ;
int V_21 , V_75 ;
V_2 -> V_10 [ 2 ] -> V_12 |= V_76 | V_77 | V_78 ;
V_2 -> V_10 [ 2 ] -> V_24 = 0 ; V_2 -> V_10 [ 2 ] -> V_11 = 0 ;
V_21 = F_30 ( V_2 , V_2 -> V_10 [ 2 ] , 0 ) ;
if ( V_21 != 0 )
return - 1 ;
V_9 = F_31 ( V_2 -> V_10 [ 2 ] -> V_24 , F_21 ( V_2 -> V_10 [ 2 ] ) ) ;
F_32 ( V_2 , V_2 -> V_10 [ 2 ] , 0 ) ;
for ( V_21 = 0 ; V_21 < 0x200 ; V_21 ++ ) {
if ( F_33 ( V_9 + V_21 * 2 ) == 0x22 ) {
if ( F_33 ( V_9 + ( V_21 - 1 ) * 2 ) == 0xff &&
F_33 ( V_9 + ( V_21 + 5 ) * 2 ) == 0x04 &&
F_33 ( V_9 + ( V_21 + 6 ) * 2 ) == 0x06 &&
F_33 ( V_9 + ( V_21 + 13 ) * 2 ) == 0xff )
break;
}
}
if ( V_21 != 0x200 ) {
for ( V_75 = 0 ; V_75 < 6 ; V_75 ++ , V_21 ++ ) {
V_74 [ V_75 ] = F_33 ( V_9 + ( V_21 + 7 ) * 2 ) ;
}
}
F_34 ( V_9 ) ;
V_75 = F_35 ( V_2 , V_2 -> V_10 [ 2 ] ) ;
return ( V_21 != 0x200 ) ? 0 : - 1 ;
}
static int F_22 ( struct V_1 * V_2 )
{
int V_21 ;
struct V_4 * V_5 = V_2 -> V_7 ;
unsigned int V_26 ;
T_1 * V_3 = F_4 ( V_5 ) ;
V_2 -> V_10 [ 3 ] -> V_12 = V_76 | V_77 | V_78 ;
V_2 -> V_10 [ 3 ] -> V_24 = V_2 -> V_10 [ 3 ] -> V_11 = 0 ;
V_21 = F_30 ( V_2 , V_2 -> V_10 [ 3 ] , 0 ) ;
if ( V_21 != 0 )
return - 1 ;
V_3 -> V_9 = F_31 ( V_2 -> V_10 [ 3 ] -> V_24 ,
F_21 ( V_2 -> V_10 [ 3 ] ) ) ;
if ( V_3 -> V_9 == NULL ) {
F_36 ( V_5 , L_19 ) ;
return - 1 ;
}
V_21 = F_32 ( V_2 , V_2 -> V_10 [ 3 ] , 0 ) ;
if ( V_21 != 0 ) {
F_34 ( V_3 -> V_9 ) ;
V_3 -> V_9 = NULL ;
return - 1 ;
}
V_26 = V_5 -> V_62 ;
F_37 ( 0x47 , V_3 -> V_9 + 0x800 ) ;
F_37 ( 0x0 , V_3 -> V_9 + 0x802 ) ;
F_37 ( V_26 & 0xff , V_3 -> V_9 + 0x80a ) ;
F_37 ( ( V_26 >> 8 ) & 0xff , V_3 -> V_9 + 0x80c ) ;
F_37 ( 0x45 , V_3 -> V_9 + 0x820 ) ;
F_37 ( 0x8 , V_3 -> V_9 + 0x822 ) ;
return 0 ;
}
static void F_9 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_7 ;
T_1 * V_3 = F_4 ( V_5 ) ;
T_5 T_6 * V_79 ;
F_2 ( & V_2 -> V_5 , L_20 ) ;
if ( V_3 -> V_9 != NULL ) {
V_79 = V_3 -> V_9 ;
V_3 -> V_9 = NULL ;
F_34 ( V_79 ) ;
}
F_38 ( V_2 ) ;
}
static int F_39 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_7 ;
if ( V_2 -> V_80 )
F_40 ( V_5 ) ;
return 0 ;
}
static int F_41 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_7 ;
if ( V_2 -> V_80 ) {
F_42 ( V_5 ) ;
F_43 ( V_5 ) ;
}
return 0 ;
}
static int T_7 F_44 ( void )
{
return F_45 ( & V_81 ) ;
}
static void T_8 F_46 ( void )
{
F_47 ( & V_81 ) ;
}
static T_9 V_60 ( int V_82 , void * V_83 )
{
struct V_4 * V_5 = V_83 ;
T_1 * V_3 = F_4 ( V_5 ) ;
unsigned int V_26 ;
unsigned short V_84 , V_85 ;
V_26 = V_5 -> V_62 ;
F_48 ( 0x0000 , V_26 + V_86 ) ;
F_49 ( 1 ) ;
V_84 = F_25 ( V_26 + V_87 ) ;
V_85 = F_25 ( V_26 + V_88 ) ;
F_23 ( V_84 , V_26 + V_87 ) ;
F_23 ( V_85 , V_26 + V_88 ) ;
F_50 ( L_21 , V_5 -> V_89 , V_85 ) ;
F_50 ( L_22 , V_84 ) ;
if ( V_85 || ( F_25 ( V_26 + V_90 ) & V_91 ) == 0 ) {
F_51 ( V_5 ) ;
}
if ( V_84 & V_92 ) {
V_5 -> V_93 . V_94 += V_3 -> V_95 ;
V_3 -> V_95 = 0 ;
if ( V_3 -> V_96 ) {
F_23 ( V_97 | V_3 -> V_96 , V_26 + V_98 ) ;
V_3 -> V_95 = V_3 -> V_96 ;
V_3 -> V_96 = 0 ;
V_3 -> V_99 = 0 ;
V_5 -> V_100 = V_101 ;
} else {
V_3 -> V_102 = 0 ;
}
F_52 ( V_5 ) ;
}
F_50 ( L_23 , V_5 -> V_89 ) ;
F_50 ( L_24 , V_84 , V_85 ) ;
F_23 ( V_103 , V_26 + V_86 ) ;
F_23 ( V_104 , V_26 + V_105 ) ;
if ( V_3 -> V_9 != NULL ) {
F_37 ( 0x01 , V_3 -> V_9 + 0x802 ) ;
F_37 ( 0x09 , V_3 -> V_9 + 0x822 ) ;
}
return V_106 ;
}
static void F_53 ( struct V_4 * V_5 )
{
struct T_1 * V_3 = F_4 ( V_5 ) ;
unsigned int V_26 = V_5 -> V_62 ;
F_36 ( V_5 , L_25 ,
F_54 ( F_55 ( V_26 + V_87 ) ) ,
F_25 ( V_26 + V_87 ) & V_92
? L_26 : L_27 ) ;
F_36 ( V_5 , L_28
L_29 ,
F_54 ( F_55 ( V_26 + 0 ) ) , F_54 ( F_55 ( V_26 + 2 ) ) ,
F_54 ( F_55 ( V_26 + 4 ) ) , F_54 ( F_55 ( V_26 + 6 ) ) ,
F_54 ( F_55 ( V_26 + 8 ) ) , F_54 ( F_55 ( V_26 + 10 ) ) ,
F_54 ( F_55 ( V_26 + 12 ) ) , F_54 ( F_55 ( V_26 + 14 ) ) ) ;
V_5 -> V_93 . V_107 ++ ;
F_56 () ;
F_42 ( V_5 ) ;
V_3 -> V_102 = 0 ;
V_3 -> V_96 = 0 ;
V_3 -> V_99 = 0 ;
V_3 -> V_95 = 0 ;
V_3 -> V_108 = V_101 ;
F_57 () ;
F_52 ( V_5 ) ;
}
static T_10 F_58 ( struct V_109 * V_110 ,
struct V_4 * V_5 )
{
struct T_1 * V_3 = F_4 ( V_5 ) ;
unsigned int V_26 = V_5 -> V_62 ;
short V_111 = V_110 -> V_32 ;
if ( V_111 < V_112 )
{
if ( F_59 ( V_110 , V_112 ) )
return V_113 ;
V_111 = V_112 ;
}
F_60 ( V_5 ) ;
{
unsigned char * V_31 = V_110 -> V_114 ;
if ( V_111 > V_115 ) {
F_36 ( V_5 , L_30 ,
V_111 ) ;
return V_116 ;
}
F_61 ( V_5 , L_31 ,
( unsigned long ) V_110 -> V_32 ) ;
V_5 -> V_93 . V_117 += V_110 -> V_32 ;
F_48 ( 0x0000 , V_26 + V_86 ) ;
F_49 ( 1 ) ;
F_48 ( V_111 , V_26 + V_118 ) ;
F_62 ( V_26 + V_118 , V_31 , ( V_111 + 1 ) >> 1 ) ;
V_3 -> V_96 ++ ;
V_3 -> V_99 += ( ( V_111 + 3 ) & ~ 1 ) ;
if ( V_3 -> V_102 == 0 ) {
F_23 ( V_97 | V_3 -> V_96 , V_26 + V_98 ) ;
V_3 -> V_95 = V_3 -> V_96 ;
V_3 -> V_96 = 0 ;
V_3 -> V_99 = 0 ;
V_3 -> V_102 = 1 ;
F_63 ( V_5 ) ;
} else {
if( V_63 == 0 ) {
if ( V_3 -> V_99 < ( 4096 - ( V_115 + 2 ) ) )
F_63 ( V_5 ) ;
} else {
if ( V_3 -> V_99 < ( 8192 - ( V_115 + 2 ) ) &&
V_3 -> V_96 < 127 )
F_63 ( V_5 ) ;
}
}
F_23 ( V_103 , V_26 + V_86 ) ;
F_23 ( V_104 , V_26 + V_105 ) ;
}
F_64 ( V_110 ) ;
return V_113 ;
}
static void F_42 ( struct V_4 * V_5 )
{
struct T_1 * V_3 = F_4 ( V_5 ) ;
unsigned int V_26 = V_5 -> V_62 ;
int V_21 ;
F_61 ( V_5 , L_32 ) ;
if( V_63 == 0 )
F_23 ( V_64 , V_26 + V_65 ) ;
else
F_23 ( V_66 , V_26 + V_65 ) ;
if ( V_3 -> V_29 == V_52 )
F_23 ( V_67 , V_26 + V_68 ) ;
else
F_23 ( V_69 , V_26 + V_68 ) ;
F_23 ( V_119 , V_26 + V_120 ) ;
F_23 ( V_121 , V_26 + V_90 ) ;
for ( V_21 = 0 ; V_21 < 6 ; V_21 ++ )
F_23 ( V_5 -> V_70 [ V_21 ] , V_26 + V_122 + V_21 ) ;
F_65 ( V_5 ) ;
if ( V_3 -> V_29 == V_52 )
F_23 ( V_123 , V_26 + V_68 ) ;
else
F_23 ( V_124 , V_26 + V_68 ) ;
if( V_3 -> V_29 == V_39 || V_3 -> V_29 == V_50 )
F_23 ( V_125 , V_26 + V_126 ) ;
else
F_23 ( V_127 , V_26 + V_126 ) ;
F_23 ( 0x00 , V_26 + V_128 ) ;
F_23 ( 0x00 , V_26 + V_129 ) ;
F_23 ( 0x01 , V_26 + V_130 ) ;
if( V_63 == 0 )
F_23 ( V_131 , V_26 + V_65 ) ;
else
F_23 ( V_132 , V_26 + V_65 ) ;
F_55 ( V_26 + V_118 ) ;
F_55 ( V_26 + V_118 ) ;
F_23 ( 0xff , V_26 + V_87 ) ;
F_23 ( 0xff , V_26 + V_88 ) ;
if ( V_3 -> V_29 == V_52 )
F_23 ( V_133 , V_26 + V_134 ) ;
F_23 ( V_103 , V_26 + V_86 ) ;
F_23 ( V_104 , V_26 + V_105 ) ;
if ( V_3 -> V_29 == V_52 )
F_23 ( V_135 , V_26 + V_134 ) ;
}
static void F_51 ( struct V_4 * V_5 )
{
unsigned int V_26 = V_5 -> V_62 ;
int V_136 = 10 ;
F_50 ( L_33 ,
V_5 -> V_89 , F_25 ( V_26 + V_88 ) ) ;
while ( ( F_25 ( V_26 + V_90 ) & V_91 ) == 0 ) {
T_11 V_137 = F_55 ( V_26 + V_118 ) ;
F_61 ( V_5 , L_34 ,
F_25 ( V_26 + V_90 ) , V_137 ) ;
#ifndef F_66
if ( V_137 == 0 ) {
F_23 ( V_138 , V_26 + V_130 ) ;
break;
}
#endif
if ( ( V_137 & 0xF0 ) != 0x20 ) {
V_5 -> V_93 . V_139 ++ ;
if ( V_137 & V_140 ) V_5 -> V_93 . V_141 ++ ;
if ( V_137 & V_142 ) V_5 -> V_93 . V_143 ++ ;
if ( V_137 & V_144 ) V_5 -> V_93 . V_145 ++ ;
if ( V_137 & V_146 ) V_5 -> V_93 . V_147 ++ ;
} else {
T_11 V_148 = F_55 ( V_26 + V_118 ) ;
struct V_109 * V_110 ;
if ( V_148 > 1550 ) {
F_36 ( V_5 , L_35 ,
V_148 ) ;
F_23 ( V_138 , V_26 + V_130 ) ;
V_5 -> V_93 . V_139 ++ ;
break;
}
V_110 = F_67 ( V_148 + 2 ) ;
if ( V_110 == NULL ) {
F_36 ( V_5 , L_36 ,
V_148 ) ;
F_23 ( V_138 , V_26 + V_130 ) ;
V_5 -> V_93 . V_149 ++ ;
break;
}
F_68 ( V_110 , 2 ) ;
F_69 ( V_26 + V_118 , F_70 ( V_110 , V_148 ) ,
( V_148 + 1 ) >> 1 ) ;
V_110 -> V_150 = F_71 ( V_110 , V_5 ) ;
{
int V_21 ;
F_50 ( L_37 ,
V_5 -> V_89 , V_148 ) ;
for ( V_21 = 0 ; V_21 < 14 ; V_21 ++ )
F_50 ( L_38 , V_110 -> V_114 [ V_21 ] ) ;
F_50 ( L_39 ) ;
}
F_72 ( V_110 ) ;
V_5 -> V_93 . V_151 ++ ;
V_5 -> V_93 . V_152 += V_148 ;
}
if ( -- V_136 <= 0 )
break;
}
}
static void F_73 ( struct V_4 * V_5 ,
struct V_153 * V_154 )
{
F_74 ( V_154 -> V_155 , V_156 , sizeof( V_154 -> V_155 ) ) ;
F_74 ( V_154 -> V_157 , V_158 , sizeof( V_154 -> V_157 ) ) ;
snprintf ( V_154 -> V_159 , sizeof( V_154 -> V_159 ) ,
L_40 , V_5 -> V_62 ) ;
}
static int F_75 ( struct V_4 * V_5 , struct V_160 * V_161 ) {
return 0 ;
}
static int F_76 ( struct V_4 * V_5 )
{
struct T_1 * V_3 = F_4 ( V_5 ) ;
struct V_1 * V_2 = V_3 -> V_8 ;
F_50 ( L_41 , V_5 -> V_89 ) ;
if ( ! F_77 ( V_2 ) )
return - V_73 ;
V_2 -> V_80 ++ ;
F_42 ( V_5 ) ;
V_3 -> V_102 = 0 ;
V_3 -> V_96 = 0 ;
V_3 -> V_99 = 0 ;
V_3 -> V_108 = V_101 ;
F_63 ( V_5 ) ;
return 0 ;
}
static int F_78 ( struct V_4 * V_5 )
{
struct T_1 * V_3 = F_4 ( V_5 ) ;
struct V_1 * V_2 = V_3 -> V_8 ;
unsigned int V_26 = V_5 -> V_62 ;
F_50 ( L_42 , V_5 -> V_89 ) ;
V_3 -> V_108 = 0 ;
F_60 ( V_5 ) ;
if( V_63 == 0 )
F_23 ( V_64 , V_26 + V_65 ) ;
else
F_23 ( V_66 , V_26 + V_65 ) ;
F_23 ( V_162 , V_26 + V_68 ) ;
if ( V_3 -> V_29 == V_52 )
F_23 ( V_133 , V_26 + V_134 ) ;
V_2 -> V_80 -- ;
return 0 ;
}
static void F_65 ( struct V_4 * V_5 )
{
unsigned int V_26 = V_5 -> V_62 ;
T_5 V_163 [ 8 ] ;
T_12 V_12 ;
int V_21 ;
int V_164 ;
int V_165 = F_25 ( V_26 + V_65 ) ;
F_79 ( V_12 ) ;
if ( V_63 == 0 )
F_23 ( V_64 , V_26 + V_65 ) ;
else
F_23 ( V_66 , V_26 + V_65 ) ;
if ( V_5 -> V_12 & V_166 ) {
memset ( V_163 , 0xff , sizeof( V_163 ) ) ;
F_23 ( 3 , V_26 + V_90 ) ;
} else if ( F_80 ( V_5 ) > V_167 ||
( V_5 -> V_12 & V_168 ) ) {
memset ( V_163 , 0xff , sizeof( V_163 ) ) ;
F_23 ( 2 , V_26 + V_90 ) ;
} else if ( F_81 ( V_5 ) ) {
memset ( V_163 , 0x00 , sizeof( V_163 ) ) ;
F_23 ( 1 , V_26 + V_90 ) ;
} else {
struct V_169 * V_170 ;
memset ( V_163 , 0 , sizeof( V_163 ) ) ;
F_82 (ha, dev) {
unsigned int V_171 = F_83 ( V_172 , V_170 -> V_173 ) >> 26 ;
V_163 [ V_171 >> 3 ] |= ( 1 << ( V_171 & 7 ) ) ;
}
F_23 ( 2 , V_26 + V_90 ) ;
}
V_164 = F_25 ( V_26 + V_68 ) ;
F_23 ( 0xe4 , V_26 + V_68 ) ;
for ( V_21 = 0 ; V_21 < 8 ; V_21 ++ )
F_23 ( V_163 [ V_21 ] , V_26 + V_174 + V_21 ) ;
F_23 ( V_164 , V_26 + V_68 ) ;
F_23 ( V_165 , V_26 + V_65 ) ;
F_84 ( V_12 ) ;
}
