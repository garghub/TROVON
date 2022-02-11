static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
struct V_5 * V_6 ;
F_2 ( & V_2 -> V_6 , L_1 ) ;
V_6 = F_3 ( sizeof( struct V_3 ) ) ;
if ( ! V_6 )
return - V_7 ;
V_4 = F_4 ( V_6 ) ;
V_2 -> V_8 = V_6 ;
V_4 -> V_9 = V_2 ;
V_4 -> V_10 = NULL ;
V_2 -> V_11 [ 0 ] -> V_12 = 32 ;
V_2 -> V_11 [ 0 ] -> V_13 |= V_14 ;
V_2 -> V_15 |= V_16 ;
V_6 -> V_17 = & V_18 ;
V_6 -> V_19 = V_20 ;
V_6 -> V_21 = & V_22 ;
return F_5 ( V_2 ) ;
}
static void F_6 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = V_2 -> V_8 ;
F_2 ( & V_2 -> V_6 , L_2 ) ;
F_7 ( V_6 ) ;
F_8 ( V_2 ) ;
F_9 ( V_6 ) ;
}
static int F_10 ( struct V_1 * V_2 )
{
int V_23 , V_24 ;
static const unsigned int V_25 [ 5 ] =
{ 0x3f8 , 0x2f8 , 0x3e8 , 0x2e8 , 0x0 } ;
for ( V_23 = 0 ; V_23 < 5 ; V_23 ++ ) {
V_2 -> V_11 [ 1 ] -> V_26 = V_25 [ V_23 ] ;
V_2 -> V_11 [ 1 ] -> V_13 |= V_27 ;
if ( V_2 -> V_11 [ 1 ] -> V_26 == 0 ) {
V_2 -> V_11 [ 1 ] -> V_12 = 0 ;
F_11 ( L_3 ) ;
}
V_24 = F_12 ( V_2 ) ;
if ( V_24 == 0 )
return V_24 ;
}
return V_24 ;
}
static int F_13 ( struct V_1 * V_2 )
{
int V_24 ;
unsigned int V_28 ;
for ( V_28 = 0x300 ; V_28 < 0x3e0 ; V_28 += 0x20 ) {
V_2 -> V_11 [ 0 ] -> V_26 = V_28 ;
V_24 = F_12 ( V_2 ) ;
if ( V_24 == 0 ) {
V_2 -> V_29 =
( ( V_2 -> V_11 [ 0 ] -> V_26 & 0x0f0 ) >> 3 ) | 0x22 ;
return V_24 ;
}
}
return V_24 ;
}
static int F_14 ( struct V_1 * V_9 , void * V_30 )
{
return 0 ;
}
static int F_5 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = V_2 -> V_8 ;
struct V_3 * V_4 = F_4 ( V_6 ) ;
int V_23 , V_24 ;
unsigned int V_28 ;
enum V_31 V_31 ;
char * V_32 = L_4 ;
T_1 * V_33 ;
T_2 V_34 ;
T_3 V_35 [ 32 ] ;
F_2 ( & V_2 -> V_6 , L_5 ) ;
V_2 -> V_36 = 5 ;
V_34 = F_15 ( V_2 , V_37 , & V_33 ) ;
F_16 ( V_33 ) ;
if ( V_34 ) {
V_24 = F_17 ( V_2 , F_14 , NULL ) ;
if ( V_24 != 0 )
goto V_38;
switch ( V_2 -> V_39 ) {
case V_40 :
V_31 = V_41 ;
if ( V_2 -> V_42 == V_43 ||
V_2 -> V_42 == V_44 ||
V_2 -> V_42 == V_45 ) {
V_2 -> V_46 = 0x800 ;
V_2 -> V_29 = 0x47 ;
V_2 -> V_11 [ 1 ] -> V_12 = 8 ;
}
break;
case V_47 :
V_31 = V_48 ;
V_2 -> V_46 = 0x800 ;
V_2 -> V_29 = 0x47 ;
V_2 -> V_11 [ 1 ] -> V_12 = 8 ;
break;
case V_49 :
V_31 = V_50 ;
V_2 -> V_46 = 0x800 ;
V_2 -> V_29 = 0x47 ;
V_2 -> V_11 [ 1 ] -> V_12 = 8 ;
break;
case V_51 :
V_31 = V_52 ;
break;
case V_53 :
if ( V_2 -> V_46 == 0x0fe0 )
V_31 = V_54 ;
else if ( V_2 -> V_42 == V_55 )
V_31 = V_56 ;
else if ( V_2 -> V_42 == V_57 )
V_31 = V_56 ;
else
V_31 = V_58 ;
break;
default:
V_31 = V_56 ;
}
} else {
switch ( V_2 -> V_39 ) {
case V_53 :
if ( V_2 -> V_42 == V_57 ) {
V_31 = V_59 ;
V_2 -> V_29 = 0x20 ;
} else {
V_31 = V_54 ;
V_2 -> V_29 = 1 ;
}
break;
case V_60 :
V_31 = V_61 ;
break;
default:
V_31 = V_54 ;
V_2 -> V_29 = 1 ;
}
}
if ( V_2 -> V_11 [ 1 ] -> V_12 != 0 ) {
V_24 = F_10 ( V_2 ) ;
if ( V_24 != 0 ) goto V_38;
} else if ( V_31 == V_61 ) {
V_24 = F_13 ( V_2 ) ;
if ( V_24 != 0 ) goto V_38;
} else {
V_24 = F_12 ( V_2 ) ;
if ( V_24 )
goto V_38;
}
V_24 = F_18 ( V_2 , V_62 ) ;
if ( V_24 )
goto V_38;
V_24 = F_19 ( V_2 ) ;
if ( V_24 )
goto V_38;
V_6 -> V_63 = V_2 -> V_63 ;
V_6 -> V_64 = V_2 -> V_11 [ 0 ] -> V_26 ;
if ( F_20 ( V_2 -> V_11 [ 1 ] ) != 0 ) {
V_24 = F_21 ( V_2 ) ;
if ( V_24 != 0 ) goto V_38;
}
V_28 = V_6 -> V_64 ;
if ( V_65 == 0 )
F_22 ( V_66 , V_28 + V_67 ) ;
else
F_22 ( V_68 , V_28 + V_67 ) ;
if ( V_31 == V_54 )
F_22 ( V_69 , V_28 + V_70 ) ;
else
F_22 ( V_71 , V_28 + V_70 ) ;
switch ( V_31 ) {
case V_56 :
case V_41 :
case V_58 :
case V_52 :
case V_48 :
case V_50 :
if ( V_31 == V_56 ) {
V_32 = L_6 ;
V_34 = F_15 ( V_2 , V_37 , & V_33 ) ;
if ( V_34 < 11 ) {
F_16 ( V_33 ) ;
goto V_38;
}
for ( V_23 = 5 ; V_23 < 11 ; V_23 ++ )
V_6 -> V_72 [ V_23 ] = V_33 [ V_23 ] ;
F_16 ( V_33 ) ;
} else {
if ( F_23 ( V_2 , V_6 ) )
goto V_38;
if( V_31 == V_41 ) {
V_32 = L_7 ;
} else if( V_31 == V_58 ) {
V_32 = L_8 ;
} else if( V_31 == V_48 ) {
V_32 = L_9 ;
} else if( V_31 == V_50 ) {
V_32 = L_10 ;
} else {
V_32 = L_11 ;
}
}
break;
case V_61 :
for ( V_23 = 0 ; V_23 < 6 ; V_23 ++ )
V_6 -> V_72 [ V_23 ] = F_24 ( V_28 + V_73 + V_23 ) ;
V_32 = L_12 ;
break;
case V_59 :
if ( F_25 ( V_2 , V_35 ) == - 1 ) {
F_11 ( L_13 ) ;
goto V_38;
}
for ( V_23 = 0 ; V_23 < 6 ; V_23 ++ ) {
V_6 -> V_72 [ V_23 ] = V_35 [ V_23 ] ;
}
V_32 = L_6 ;
break;
case V_54 :
default:
for ( V_23 = 0 ; V_23 < 6 ; V_23 ++ )
V_6 -> V_72 [ V_23 ] = F_24 ( V_28 + V_74 + V_23 ) ;
V_32 = L_14 ;
break;
}
V_4 -> V_31 = V_31 ;
F_26 ( V_6 , & V_2 -> V_6 ) ;
if ( F_27 ( V_6 ) != 0 ) {
F_11 ( L_15 ) ;
goto V_38;
}
F_28 ( V_6 , L_16 ,
V_32 , V_65 == 0 ? L_17 : L_18 ,
V_6 -> V_64 , V_6 -> V_63 , V_6 -> V_72 ) ;
return 0 ;
V_38:
F_8 ( V_2 ) ;
return - V_75 ;
}
static int F_25 ( struct V_1 * V_2 , T_3 * V_76 )
{
T_3 T_4 * V_10 ;
int V_23 , V_77 ;
V_2 -> V_11 [ 2 ] -> V_13 |= V_78 | V_79 | V_80 ;
V_2 -> V_11 [ 2 ] -> V_26 = 0 ; V_2 -> V_11 [ 2 ] -> V_12 = 0 ;
V_23 = F_29 ( V_2 , V_2 -> V_11 [ 2 ] , 0 ) ;
if ( V_23 != 0 )
return - 1 ;
V_10 = F_30 ( V_2 -> V_11 [ 2 ] -> V_26 , F_20 ( V_2 -> V_11 [ 2 ] ) ) ;
F_31 ( V_2 , V_2 -> V_11 [ 2 ] , 0 ) ;
for ( V_23 = 0 ; V_23 < 0x200 ; V_23 ++ ) {
if ( F_32 ( V_10 + V_23 * 2 ) == 0x22 ) {
if ( F_32 ( V_10 + ( V_23 - 1 ) * 2 ) == 0xff &&
F_32 ( V_10 + ( V_23 + 5 ) * 2 ) == 0x04 &&
F_32 ( V_10 + ( V_23 + 6 ) * 2 ) == 0x06 &&
F_32 ( V_10 + ( V_23 + 13 ) * 2 ) == 0xff )
break;
}
}
if ( V_23 != 0x200 ) {
for ( V_77 = 0 ; V_77 < 6 ; V_77 ++ , V_23 ++ ) {
V_76 [ V_77 ] = F_32 ( V_10 + ( V_23 + 7 ) * 2 ) ;
}
}
F_33 ( V_10 ) ;
V_77 = F_34 ( V_2 , V_2 -> V_11 [ 2 ] ) ;
return ( V_23 != 0x200 ) ? 0 : - 1 ;
}
static int F_21 ( struct V_1 * V_2 )
{
int V_23 ;
struct V_5 * V_6 = V_2 -> V_8 ;
unsigned int V_28 ;
struct V_3 * V_4 = F_4 ( V_6 ) ;
V_2 -> V_11 [ 3 ] -> V_13 = V_78 | V_79 | V_80 ;
V_2 -> V_11 [ 3 ] -> V_26 = V_2 -> V_11 [ 3 ] -> V_12 = 0 ;
V_23 = F_29 ( V_2 , V_2 -> V_11 [ 3 ] , 0 ) ;
if ( V_23 != 0 )
return - 1 ;
V_4 -> V_10 = F_30 ( V_2 -> V_11 [ 3 ] -> V_26 ,
F_20 ( V_2 -> V_11 [ 3 ] ) ) ;
if ( V_4 -> V_10 == NULL ) {
F_35 ( V_6 , L_19 ) ;
return - 1 ;
}
V_23 = F_31 ( V_2 , V_2 -> V_11 [ 3 ] , 0 ) ;
if ( V_23 != 0 ) {
F_33 ( V_4 -> V_10 ) ;
V_4 -> V_10 = NULL ;
return - 1 ;
}
V_28 = V_6 -> V_64 ;
F_36 ( 0x47 , V_4 -> V_10 + 0x800 ) ;
F_36 ( 0x0 , V_4 -> V_10 + 0x802 ) ;
F_36 ( V_28 & 0xff , V_4 -> V_10 + 0x80a ) ;
F_36 ( ( V_28 >> 8 ) & 0xff , V_4 -> V_10 + 0x80c ) ;
F_36 ( 0x45 , V_4 -> V_10 + 0x820 ) ;
F_36 ( 0x8 , V_4 -> V_10 + 0x822 ) ;
return 0 ;
}
static void F_8 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = V_2 -> V_8 ;
struct V_3 * V_4 = F_4 ( V_6 ) ;
T_3 T_4 * V_81 ;
F_2 ( & V_2 -> V_6 , L_20 ) ;
if ( V_4 -> V_10 != NULL ) {
V_81 = V_4 -> V_10 ;
V_4 -> V_10 = NULL ;
F_33 ( V_81 ) ;
}
F_37 ( V_2 ) ;
}
static int F_38 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = V_2 -> V_8 ;
if ( V_2 -> V_82 )
F_39 ( V_6 ) ;
return 0 ;
}
static int F_40 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = V_2 -> V_8 ;
if ( V_2 -> V_82 ) {
F_41 ( V_6 ) ;
F_42 ( V_6 ) ;
}
return 0 ;
}
static T_5 V_62 ( int V_83 , void * V_84 )
{
struct V_5 * V_6 = V_84 ;
struct V_3 * V_4 = F_4 ( V_6 ) ;
unsigned int V_28 ;
unsigned short V_85 , V_86 ;
V_28 = V_6 -> V_64 ;
F_43 ( 0x0000 , V_28 + V_87 ) ;
F_44 ( 1 ) ;
V_85 = F_24 ( V_28 + V_88 ) ;
V_86 = F_24 ( V_28 + V_89 ) ;
F_22 ( V_85 , V_28 + V_88 ) ;
F_22 ( V_86 , V_28 + V_89 ) ;
F_45 ( L_21 , V_6 -> V_90 , V_86 ) ;
F_45 ( L_22 , V_85 ) ;
if ( V_86 || ( F_24 ( V_28 + V_91 ) & V_92 ) == 0 ) {
F_46 ( V_6 ) ;
}
if ( V_85 & V_93 ) {
V_6 -> V_94 . V_95 += V_4 -> V_96 ;
V_4 -> V_96 = 0 ;
if ( V_4 -> V_97 ) {
F_22 ( V_98 | V_4 -> V_97 , V_28 + V_99 ) ;
V_4 -> V_96 = V_4 -> V_97 ;
V_4 -> V_97 = 0 ;
V_4 -> V_100 = 0 ;
V_6 -> V_101 = V_102 ;
} else {
V_4 -> V_103 = 0 ;
}
F_47 ( V_6 ) ;
}
F_45 ( L_23 , V_6 -> V_90 ) ;
F_45 ( L_24 , V_85 , V_86 ) ;
F_22 ( V_104 , V_28 + V_87 ) ;
F_22 ( V_105 , V_28 + V_106 ) ;
if ( V_4 -> V_10 != NULL ) {
F_36 ( 0x01 , V_4 -> V_10 + 0x802 ) ;
F_36 ( 0x09 , V_4 -> V_10 + 0x822 ) ;
}
return V_107 ;
}
static void F_48 ( struct V_5 * V_6 )
{
struct V_3 * V_4 = F_4 ( V_6 ) ;
unsigned int V_28 = V_6 -> V_64 ;
F_35 ( V_6 , L_25 ,
F_49 ( F_50 ( V_28 + V_88 ) ) ,
F_24 ( V_28 + V_88 ) & V_93
? L_26 : L_27 ) ;
F_35 ( V_6 , L_28
L_29 ,
F_49 ( F_50 ( V_28 + 0 ) ) , F_49 ( F_50 ( V_28 + 2 ) ) ,
F_49 ( F_50 ( V_28 + 4 ) ) , F_49 ( F_50 ( V_28 + 6 ) ) ,
F_49 ( F_50 ( V_28 + 8 ) ) , F_49 ( F_50 ( V_28 + 10 ) ) ,
F_49 ( F_50 ( V_28 + 12 ) ) , F_49 ( F_50 ( V_28 + 14 ) ) ) ;
V_6 -> V_94 . V_108 ++ ;
F_51 () ;
F_41 ( V_6 ) ;
V_4 -> V_103 = 0 ;
V_4 -> V_97 = 0 ;
V_4 -> V_100 = 0 ;
V_4 -> V_96 = 0 ;
V_4 -> V_109 = V_102 ;
F_52 () ;
F_47 ( V_6 ) ;
}
static T_6 F_53 ( struct V_110 * V_111 ,
struct V_5 * V_6 )
{
struct V_3 * V_4 = F_4 ( V_6 ) ;
unsigned int V_28 = V_6 -> V_64 ;
short V_112 = V_111 -> V_34 ;
if ( V_112 < V_113 )
{
if ( F_54 ( V_111 , V_113 ) )
return V_114 ;
V_112 = V_113 ;
}
F_55 ( V_6 ) ;
{
unsigned char * V_33 = V_111 -> V_115 ;
if ( V_112 > V_116 ) {
F_35 ( V_6 , L_30 ,
V_112 ) ;
return V_117 ;
}
F_56 ( V_6 , L_31 ,
( unsigned long ) V_111 -> V_34 ) ;
V_6 -> V_94 . V_118 += V_111 -> V_34 ;
F_43 ( 0x0000 , V_28 + V_87 ) ;
F_44 ( 1 ) ;
F_43 ( V_112 , V_28 + V_119 ) ;
F_57 ( V_28 + V_119 , V_33 , ( V_112 + 1 ) >> 1 ) ;
V_4 -> V_97 ++ ;
V_4 -> V_100 += ( ( V_112 + 3 ) & ~ 1 ) ;
if ( V_4 -> V_103 == 0 ) {
F_22 ( V_98 | V_4 -> V_97 , V_28 + V_99 ) ;
V_4 -> V_96 = V_4 -> V_97 ;
V_4 -> V_97 = 0 ;
V_4 -> V_100 = 0 ;
V_4 -> V_103 = 1 ;
F_58 ( V_6 ) ;
} else {
if( V_65 == 0 ) {
if ( V_4 -> V_100 < ( 4096 - ( V_116 + 2 ) ) )
F_58 ( V_6 ) ;
} else {
if ( V_4 -> V_100 < ( 8192 - ( V_116 + 2 ) ) &&
V_4 -> V_97 < 127 )
F_58 ( V_6 ) ;
}
}
F_22 ( V_104 , V_28 + V_87 ) ;
F_22 ( V_105 , V_28 + V_106 ) ;
}
F_59 ( V_111 ) ;
return V_114 ;
}
static void F_41 ( struct V_5 * V_6 )
{
struct V_3 * V_4 = F_4 ( V_6 ) ;
unsigned int V_28 = V_6 -> V_64 ;
int V_23 ;
F_56 ( V_6 , L_32 ) ;
if( V_65 == 0 )
F_22 ( V_66 , V_28 + V_67 ) ;
else
F_22 ( V_68 , V_28 + V_67 ) ;
if ( V_4 -> V_31 == V_54 )
F_22 ( V_69 , V_28 + V_70 ) ;
else
F_22 ( V_71 , V_28 + V_70 ) ;
F_22 ( V_120 , V_28 + V_121 ) ;
F_22 ( V_122 , V_28 + V_91 ) ;
for ( V_23 = 0 ; V_23 < 6 ; V_23 ++ )
F_22 ( V_6 -> V_72 [ V_23 ] , V_28 + V_123 + V_23 ) ;
F_60 ( V_6 ) ;
if ( V_4 -> V_31 == V_54 )
F_22 ( V_124 , V_28 + V_70 ) ;
else
F_22 ( V_125 , V_28 + V_70 ) ;
if( V_4 -> V_31 == V_41 || V_4 -> V_31 == V_52 )
F_22 ( V_126 , V_28 + V_127 ) ;
else
F_22 ( V_128 , V_28 + V_127 ) ;
F_22 ( 0x00 , V_28 + V_129 ) ;
F_22 ( 0x00 , V_28 + V_130 ) ;
F_22 ( 0x01 , V_28 + V_131 ) ;
if( V_65 == 0 )
F_22 ( V_132 , V_28 + V_67 ) ;
else
F_22 ( V_133 , V_28 + V_67 ) ;
F_50 ( V_28 + V_119 ) ;
F_50 ( V_28 + V_119 ) ;
F_22 ( 0xff , V_28 + V_88 ) ;
F_22 ( 0xff , V_28 + V_89 ) ;
if ( V_4 -> V_31 == V_54 )
F_22 ( V_134 , V_28 + V_135 ) ;
F_22 ( V_104 , V_28 + V_87 ) ;
F_22 ( V_105 , V_28 + V_106 ) ;
if ( V_4 -> V_31 == V_54 )
F_22 ( V_136 , V_28 + V_135 ) ;
}
static void F_46 ( struct V_5 * V_6 )
{
unsigned int V_28 = V_6 -> V_64 ;
int V_137 = 10 ;
F_45 ( L_33 ,
V_6 -> V_90 , F_24 ( V_28 + V_89 ) ) ;
while ( ( F_24 ( V_28 + V_91 ) & V_92 ) == 0 ) {
T_7 V_138 = F_50 ( V_28 + V_119 ) ;
F_56 ( V_6 , L_34 ,
F_24 ( V_28 + V_91 ) , V_138 ) ;
#ifndef F_61
if ( V_138 == 0 ) {
F_22 ( V_139 , V_28 + V_131 ) ;
break;
}
#endif
if ( ( V_138 & 0xF0 ) != 0x20 ) {
V_6 -> V_94 . V_140 ++ ;
if ( V_138 & V_141 ) V_6 -> V_94 . V_142 ++ ;
if ( V_138 & V_143 ) V_6 -> V_94 . V_144 ++ ;
if ( V_138 & V_145 ) V_6 -> V_94 . V_146 ++ ;
if ( V_138 & V_147 ) V_6 -> V_94 . V_148 ++ ;
} else {
T_7 V_149 = F_50 ( V_28 + V_119 ) ;
struct V_110 * V_111 ;
if ( V_149 > 1550 ) {
F_35 ( V_6 , L_35 ,
V_149 ) ;
F_22 ( V_139 , V_28 + V_131 ) ;
V_6 -> V_94 . V_140 ++ ;
break;
}
V_111 = F_62 ( V_6 , V_149 + 2 ) ;
if ( V_111 == NULL ) {
F_22 ( V_139 , V_28 + V_131 ) ;
V_6 -> V_94 . V_150 ++ ;
break;
}
F_63 ( V_111 , 2 ) ;
F_64 ( V_28 + V_119 , F_65 ( V_111 , V_149 ) ,
( V_149 + 1 ) >> 1 ) ;
V_111 -> V_151 = F_66 ( V_111 , V_6 ) ;
{
int V_23 ;
F_45 ( L_36 ,
V_6 -> V_90 , V_149 ) ;
for ( V_23 = 0 ; V_23 < 14 ; V_23 ++ )
F_45 ( L_37 , V_111 -> V_115 [ V_23 ] ) ;
F_45 ( L_38 ) ;
}
F_67 ( V_111 ) ;
V_6 -> V_94 . V_152 ++ ;
V_6 -> V_94 . V_153 += V_149 ;
}
if ( -- V_137 <= 0 )
break;
}
}
static void F_68 ( struct V_5 * V_6 ,
struct V_154 * V_155 )
{
F_69 ( V_155 -> V_156 , V_157 , sizeof( V_155 -> V_156 ) ) ;
F_69 ( V_155 -> V_158 , V_159 , sizeof( V_155 -> V_158 ) ) ;
snprintf ( V_155 -> V_160 , sizeof( V_155 -> V_160 ) ,
L_39 , V_6 -> V_64 ) ;
}
static int F_70 ( struct V_5 * V_6 , struct V_161 * V_162 ) {
return 0 ;
}
static int F_71 ( struct V_5 * V_6 )
{
struct V_3 * V_4 = F_4 ( V_6 ) ;
struct V_1 * V_2 = V_4 -> V_9 ;
F_45 ( L_40 , V_6 -> V_90 ) ;
if ( ! F_72 ( V_2 ) )
return - V_75 ;
V_2 -> V_82 ++ ;
F_41 ( V_6 ) ;
V_4 -> V_103 = 0 ;
V_4 -> V_97 = 0 ;
V_4 -> V_100 = 0 ;
V_4 -> V_109 = V_102 ;
F_58 ( V_6 ) ;
return 0 ;
}
static int F_73 ( struct V_5 * V_6 )
{
struct V_3 * V_4 = F_4 ( V_6 ) ;
struct V_1 * V_2 = V_4 -> V_9 ;
unsigned int V_28 = V_6 -> V_64 ;
F_45 ( L_41 , V_6 -> V_90 ) ;
V_4 -> V_109 = 0 ;
F_55 ( V_6 ) ;
if( V_65 == 0 )
F_22 ( V_66 , V_28 + V_67 ) ;
else
F_22 ( V_68 , V_28 + V_67 ) ;
F_22 ( V_163 , V_28 + V_70 ) ;
if ( V_4 -> V_31 == V_54 )
F_22 ( V_134 , V_28 + V_135 ) ;
V_2 -> V_82 -- ;
return 0 ;
}
static void F_60 ( struct V_5 * V_6 )
{
unsigned int V_28 = V_6 -> V_64 ;
T_3 V_164 [ 8 ] ;
T_8 V_13 ;
int V_23 ;
int V_165 ;
int V_166 = F_24 ( V_28 + V_67 ) ;
F_74 ( V_13 ) ;
if ( V_65 == 0 )
F_22 ( V_66 , V_28 + V_67 ) ;
else
F_22 ( V_68 , V_28 + V_67 ) ;
if ( V_6 -> V_13 & V_167 ) {
memset ( V_164 , 0xff , sizeof( V_164 ) ) ;
F_22 ( 3 , V_28 + V_91 ) ;
} else if ( F_75 ( V_6 ) > V_168 ||
( V_6 -> V_13 & V_169 ) ) {
memset ( V_164 , 0xff , sizeof( V_164 ) ) ;
F_22 ( 2 , V_28 + V_91 ) ;
} else if ( F_76 ( V_6 ) ) {
memset ( V_164 , 0x00 , sizeof( V_164 ) ) ;
F_22 ( 1 , V_28 + V_91 ) ;
} else {
struct V_170 * V_171 ;
memset ( V_164 , 0 , sizeof( V_164 ) ) ;
F_77 (ha, dev) {
unsigned int V_172 = F_78 ( V_173 , V_171 -> V_174 ) >> 26 ;
V_164 [ V_172 >> 3 ] |= ( 1 << ( V_172 & 7 ) ) ;
}
F_22 ( 2 , V_28 + V_91 ) ;
}
V_165 = F_24 ( V_28 + V_70 ) ;
F_22 ( 0xe4 , V_28 + V_70 ) ;
for ( V_23 = 0 ; V_23 < 8 ; V_23 ++ )
F_22 ( V_164 [ V_23 ] , V_28 + V_175 + V_23 ) ;
F_22 ( V_165 , V_28 + V_70 ) ;
F_22 ( V_166 , V_28 + V_67 ) ;
F_79 ( V_13 ) ;
}
