int F_1 ( void )
{
if ( F_2 ( V_1 ) )
return 9 ;
if ( F_2 ( V_2 ) || F_2 ( V_3 ) )
return 4 ;
else
return 3 ;
}
int F_3 ( int V_4 )
{
return V_5 [ V_4 ] ;
}
static T_1 F_4 ( int V_4 )
{
union V_6 V_7 ;
switch ( V_4 ) {
case 0 :
V_7 . V_8 = F_5 ( F_6 ( 0 ) ) ;
if ( V_7 . V_9 . V_10 == 15 )
return V_11 ;
if ( V_7 . V_9 . V_7 == 2 )
return V_12 ;
else if ( V_7 . V_9 . V_7 == 3 )
return V_13 ;
else
return V_11 ;
case 2 :
case 3 :
case 4 :
V_7 . V_8 = F_5 ( F_6 ( V_4 ) ) ;
if ( V_7 . V_9 . V_10 == 15 )
return V_11 ;
if ( V_7 . V_9 . V_7 == 2 )
return V_12 ;
else if ( V_7 . V_9 . V_7 == 3 )
return V_13 ;
else
return V_11 ;
case 7 :
V_7 . V_8 = F_5 ( F_6 ( 3 ) ) ;
if ( V_7 . V_9 . V_10 == 15 ) {
return V_11 ;
} else if ( V_7 . V_9 . V_7 != 0 ) {
V_7 . V_8 = F_5 ( F_6 ( 1 ) ) ;
if ( V_7 . V_9 . V_7 != 0 )
return V_11 ;
}
return V_14 ;
case 8 :
return V_15 ;
default:
return V_11 ;
}
}
static T_1 F_7 ( int V_4 )
{
union V_16 V_17 ;
if ( F_2 ( V_1 ) )
return F_4 ( V_4 ) ;
if ( V_4 == 2 )
return V_14 ;
if ( V_4 == 3 )
return V_15 ;
if ( ( F_2 ( V_18 ) &&
( V_4 == 4 || V_4 == 5 ) ) ||
( F_2 ( V_19 ) &&
V_4 >= 4 && V_4 <= 7 ) ) {
return V_11 ;
}
if ( F_2 ( V_19 ) ) {
union V_6 V_20 ;
if ( V_4 == 0 )
V_20 . V_8 = F_5 ( F_6 ( 2 ) ) ;
else if ( V_4 == 1 )
V_20 . V_8 = F_5 ( F_6 ( 1 ) ) ;
else
return V_11 ;
if ( V_20 . V_9 . V_10 == 15 )
return V_11 ;
if ( V_20 . V_9 . V_7 == 9 )
return V_12 ;
else if ( V_20 . V_9 . V_7 == 11 )
return V_13 ;
else
return V_11 ;
} else if ( F_2 ( V_21 ) ) {
union V_6 V_7 ;
if ( V_4 == 0 ) {
V_7 . V_8 = F_5 ( F_6 ( 2 ) ) ;
if ( V_7 . V_9 . V_7 == 2 )
return V_12 ;
else if ( V_7 . V_9 . V_7 == 3 )
return V_13 ;
else
return V_11 ;
} else if ( V_4 == 1 ) {
V_7 . V_8 = F_5 ( F_6 ( 0 ) ) ;
if ( V_7 . V_9 . V_7 == 2 )
return V_12 ;
else if ( V_7 . V_9 . V_7 == 3 )
return V_13 ;
else
return V_11 ;
}
} else if ( F_2 ( V_22 ) ) {
if ( V_4 == 0 ) {
union V_6 V_7 ;
V_7 . V_8 = F_5 ( F_6 ( 0 ) ) ;
if ( V_7 . V_9 . V_7 == 2 )
return V_12 ;
}
return V_11 ;
}
if ( V_4 == 1 && F_2 ( V_18 ) )
return V_11 ;
V_17 . V_8 = F_5 ( F_8 ( V_4 ) ) ;
if ( F_2 ( V_18 ) ) {
switch ( V_17 . V_23 . V_17 ) {
case 0 :
return V_12 ;
case 1 :
return V_13 ;
default:
return V_11 ;
}
} else {
if ( ! V_17 . V_9 . V_24 )
return V_11 ;
if ( V_17 . V_9 . type )
return V_25 ;
else
return V_26 ;
}
}
T_1 F_9 ( int V_4 )
{
union V_16 V_17 ;
if ( V_4 < 0 ||
V_4 >= F_1 () )
return V_11 ;
if ( F_2 ( V_27 ) || F_2 ( V_22 ) )
return F_7 ( V_4 ) ;
if ( V_4 == 2 )
return V_14 ;
if ( V_4 == 3 ) {
if ( F_2 ( V_2 )
|| F_2 ( V_3 ) )
return V_15 ;
else
return V_11 ;
}
if ( V_4 == 0
&& F_10 () -> V_28 == V_29
&& F_10 () -> V_30 == 1 ) {
return V_25 ;
}
if ( ( V_4 == 1 )
&& ( F_2 ( V_31 ) || F_2 ( V_32 )
|| F_2 ( V_33 )
|| F_2 ( V_3 ) ) )
return V_11 ;
V_17 . V_8 = F_5 ( F_8 ( V_4 ) ) ;
if ( F_2 ( V_2 ) || F_2 ( V_3 ) ) {
switch ( V_17 . V_34 . V_17 ) {
case 0 :
return V_11 ;
case 1 :
return V_13 ;
case 2 :
return V_12 ;
case 3 :
return V_35 ;
default:
return V_11 ;
}
} else {
if ( ! V_17 . V_9 . V_24 )
return V_11 ;
if ( V_17 . V_9 . type ) {
if ( F_2 ( V_36 )
|| F_2 ( V_37 ) )
return V_38 ;
else
return V_25 ;
} else
return V_26 ;
}
}
static int F_11 ( int V_39 )
{
union V_40 V_41 ;
union V_42 V_43 ;
V_41 . V_8 = F_5 ( F_12 ( V_39 ) ) ;
V_43 . V_8 = F_5 ( F_13 ( V_39 ) ) ;
V_41 . V_9 . V_44 = V_39 & 0x7 ;
V_41 . V_9 . V_17 = V_45 ;
V_43 . V_9 . V_46 = V_47 ;
V_43 . V_9 . V_48 = V_49 ;
V_43 . V_9 . V_50 = V_51 ;
V_43 . V_9 . V_52 = V_53 ;
V_43 . V_9 . V_54 = V_55 ;
V_43 . V_9 . V_56 = V_57 ;
V_43 . V_9 . V_58 = V_59 ;
V_43 . V_9 . V_60 = V_61 ;
V_43 . V_9 . V_62 = V_63 ;
V_43 . V_9 . V_64 = V_65 ;
V_43 . V_9 . V_66 = V_67 ;
V_43 . V_9 . V_68 = V_69 ;
V_43 . V_9 . V_70 = V_69 ;
V_43 . V_9 . V_71 = V_69 ;
V_43 . V_9 . V_72 = V_69 ;
V_43 . V_9 . V_73 = V_69 ;
V_43 . V_9 . V_74 = 0 ;
F_14 ( V_39 , V_41 , V_43 ) ;
if ( V_75 )
V_75 ( V_39 ) ;
return 0 ;
}
int F_15 ( int V_4 )
{
switch ( F_9 ( V_4 ) ) {
case V_11 :
case V_76 :
V_5 [ V_4 ] = 0 ;
break;
case V_13 :
V_5 [ V_4 ] =
F_16 ( V_4 ) ;
break;
case V_26 :
case V_25 :
V_5 [ V_4 ] =
F_17 ( V_4 ) ;
break;
case V_38 :
V_5 [ V_4 ] =
F_18 ( V_4 ) ;
break;
case V_12 :
case V_35 :
V_5 [ V_4 ] =
F_19 ( V_4 ) ;
break;
case V_14 :
V_5 [ V_4 ] =
F_20 ( V_4 ) ;
break;
case V_15 :
V_5 [ V_4 ] =
F_21 ( V_4 ) ;
break;
}
V_5 [ V_4 ] =
F_22 ( V_4 ,
V_5
[ V_4 ] ) ;
V_77 ;
return 0 ;
}
int F_23 ( int V_4 )
{
F_15 ( V_4 ) ;
switch ( F_9 ( V_4 ) ) {
case V_11 :
case V_76 :
break;
case V_13 :
F_24 ( V_4 ) ;
break;
case V_26 :
case V_25 :
F_25 ( V_4 ) ;
break;
case V_38 :
F_26 ( V_4 ) ;
break;
case V_12 :
case V_35 :
F_27 ( V_4 ) ;
break;
case V_14 :
F_28 ( V_4 ) ;
break;
case V_15 :
F_29 ( V_4 ) ;
break;
}
V_77 ;
return 0 ;
}
static int F_30 ( int V_4 )
{
int V_39 = F_31 ( V_4 , 0 ) ;
int V_78 = V_5 [ V_4 ] ;
while ( V_78 -- ) {
F_11 ( V_39 ) ;
V_39 ++ ;
}
return 0 ;
}
static int F_32 ( void )
{
F_33 ( V_79 / 8 ,
V_80 / 8 ,
V_81 / 8 ,
( V_80 + 8 ) / 128 ,
( V_81 + 8 ) / 128 ,
V_82 ,
V_83 ,
V_84 ) ;
return 0 ;
}
static int F_34 ( int V_4 )
{
T_2 V_85 [ 16 ] =
{ 8 , 7 , 6 , 5 , 4 , 3 , 2 , 1 , 8 , 7 , 6 , 5 , 4 , 3 , 2 , 1 } ;
int V_39 = F_31 ( V_4 , 0 ) ;
int V_78 = V_5 [ V_4 ] ;
while ( V_78 -- ) {
if ( V_86 )
V_86 ( V_39 , V_85 ) ;
F_35 ( V_39 ,
F_36 ( V_39 ,
0 ) ,
F_37 ( V_39 ) ,
V_85 ) ;
V_39 ++ ;
}
return 0 ;
}
static int F_38 ( void )
{
union V_87 V_88 ;
V_88 . V_8 = 0 ;
V_88 . V_9 . V_89 = 0xfff ;
V_88 . V_9 . V_90 = 0 ;
F_39 ( V_91 , V_88 . V_8 ) ;
if ( F_2 ( V_1 ) ) {
union V_92 V_93 ;
V_93 . V_8 = 0 ;
V_93 . V_9 . V_94 = 59 ;
V_93 . V_9 . V_95 = 59 ;
V_93 . V_9 . V_96 = 59 ;
V_93 . V_9 . V_97 = 59 ;
V_93 . V_9 . V_98 = 59 ;
V_93 . V_9 . V_99 = 59 ;
V_93 . V_9 . V_100 = 59 ;
F_39 ( V_101 , V_93 . V_8 ) ;
}
return 0 ;
}
static int F_40 ( void )
{
#if V_102
int V_103 = F_1 () ;
int V_4 ;
for ( V_4 = 0 ; V_4 < V_103 ; V_4 ++ ) {
switch ( F_9 ( V_4 ) ) {
case V_11 :
case V_76 :
case V_14 :
case V_15 :
case V_13 :
break;
case V_26 :
case V_25 :
case V_38 :
case V_12 :
case V_35 :
F_41 ( V_4 , 0xf ) ;
break;
}
}
#endif
return 0 ;
}
static int F_42 ( int V_4 )
{
int V_104 = 0 ;
switch ( F_9 ( V_4 ) ) {
case V_11 :
case V_76 :
break;
case V_13 :
V_104 = F_43 ( V_4 ) ;
break;
case V_26 :
case V_25 :
V_104 = F_44 ( V_4 ) ;
break;
case V_38 :
V_104 = F_45 ( V_4 ) ;
break;
case V_12 :
case V_35 :
V_104 = F_46 ( V_4 ) ;
break;
case V_14 :
V_104 = F_47 ( V_4 ) ;
break;
case V_15 :
V_104 = F_48 ( V_4 ) ;
break;
}
V_104 |= F_49 ( V_4 ) ;
return V_104 ;
}
int F_50 ( void )
{
#define F_51 \
(CVMX_FPA_PACKET_POOL_SIZE-8-CVMX_HELPER_FIRST_MBUFF_SKIP)
#define F_52 \
(CVMX_FPA_PACKET_POOL_SIZE-8-CVMX_HELPER_NOT_FIRST_MBUFF_SKIP)
#define F_53 0
#define F_54 ( T_3 ) (port >> 4)
#define F_55 ( T_3 ) (port & 0xf)
T_2 * V_105 ;
T_4 V_106 ;
union V_107 V_108 , V_109 ;
T_5 * V_110 ;
int V_111 , V_112 = 0 , V_113 , V_114 ;
union V_115 V_116 ;
int V_117 ;
int V_118 ;
int V_119 ;
T_6 V_120 ;
T_2 V_121 =
F_5 ( F_56
( F_55 ( F_53 ) , F_54 ( F_53 ) ) ) ;
T_2 V_122 =
F_5 ( F_57 ( F_54 ( F_53 ) ) ) ;
T_2 V_123 =
F_5 ( F_58 ( F_54 ( F_53 ) ) ) ;
T_2 V_124 =
F_5 ( F_59
( F_55 ( F_53 ) , F_54 ( F_53 ) ) ) ;
T_2 V_125 =
F_5 ( F_60
( F_55 ( F_53 ) , F_54 ( F_53 ) ) ) ;
F_61 ( F_53 ) ;
F_39 ( F_58 ( F_54 ( F_53 ) ) , 0 ) ;
F_62 ( 100000000ull ) ;
for ( V_118 = 0 ; V_118 < 10 ; V_118 ++ ) {
V_117 = 100000 ;
V_113 = F_5 ( V_126 ) ;
V_114 = ( V_113 >> 7 ) & 0x7f ;
V_113 &= 0x7f ;
V_112 = ( 2 + V_114 - V_113 ) & 3 ;
if ( V_112 == 0 )
goto V_127;
V_112 += 1 ;
V_111 =
F_51 +
( ( V_112 - 1 ) * F_52 ) -
( F_52 / 2 ) ;
F_39 ( F_63 ( F_54 ( F_53 ) ) ,
1 << F_55 ( F_53 ) ) ;
V_128 ;
V_108 . V_8 = 0 ;
V_108 . V_9 . V_129 =
F_64 ( F_65 ( V_82 ) ) ;
if ( V_108 . V_9 . V_129 == 0 ) {
F_66 ( L_1
L_2 ) ;
goto V_127;
}
V_108 . V_9 . V_130 = V_82 ;
V_108 . V_9 . V_111 = V_112 ;
V_109 . V_8 = 0 ;
V_109 . V_9 . V_129 =
F_64 ( F_65 ( V_131 ) ) ;
if ( V_109 . V_9 . V_129 == 0 ) {
F_66 ( L_1
L_2 ) ;
goto V_127;
}
V_109 . V_9 . V_119 = 1 ;
V_109 . V_9 . V_130 = V_131 ;
V_109 . V_9 . V_111 = F_51 ;
V_105 = ( T_2 * ) F_67 ( V_109 . V_9 . V_129 ) ;
V_105 [ 0 ] = 0xffffffffffff0000ull ;
V_105 [ 1 ] = 0x08004510ull ;
V_105 [ 2 ] = ( ( T_2 ) ( V_111 - 14 ) << 48 ) | 0x5ae740004000ull ;
V_105 [ 3 ] = 0x3a5fc0a81073c0a8ull ;
for ( V_119 = 0 ; V_119 < V_112 ; V_119 ++ ) {
if ( V_119 > 0 )
V_109 . V_9 . V_111 =
F_52 ;
if ( V_119 == ( V_112 - 1 ) )
V_109 . V_9 . V_119 = 0 ;
* ( T_2 * ) F_67 ( V_108 . V_9 . V_129 +
8 * V_119 ) = V_109 . V_8 ;
}
V_106 . V_8 = 0 ;
V_106 . V_9 . V_132 = V_112 ;
V_106 . V_9 . V_133 = V_111 ;
V_106 . V_9 . V_134 = 0 ;
V_106 . V_9 . V_135 = 1 ;
V_116 . V_8 =
F_5 ( F_56
( F_55 ( F_53 ) ,
F_54 ( F_53 ) ) ) ;
V_116 . V_9 . V_24 = 1 ;
F_39 ( F_56
( F_55 ( F_53 ) ,
F_54 ( F_53 ) ) , V_116 . V_8 ) ;
F_39 ( F_57 ( F_54 ( F_53 ) ) ,
1 << F_55 ( F_53 ) ) ;
F_39 ( F_58 ( F_54 ( F_53 ) ) ,
1 << F_55 ( F_53 ) ) ;
F_39 ( F_59
( F_55 ( F_53 ) ,
F_54 ( F_53 ) ) , 65392 - 14 - 4 ) ;
F_39 ( F_60
( F_55 ( F_53 ) ,
F_54 ( F_53 ) ) , 65392 - 14 - 4 ) ;
F_68 ( F_53 ,
F_69
( F_53 ) ,
V_136 ) ;
F_70 ( F_53 ,
F_69
( F_53 ) , V_106 ,
V_108 , V_136 ) ;
V_128 ;
do {
V_110 = F_71 ( V_137 ) ;
V_117 -- ;
} while ( ( V_110 == NULL ) && ( V_117 > 0 ) );
if ( ! V_117 )
F_66 ( L_1
L_3 ) ;
if ( V_110 )
F_72 ( V_110 ) ;
}
V_127:
F_39 ( F_56
( F_55 ( F_53 ) , F_54 ( F_53 ) ) ,
V_121 ) ;
F_39 ( F_57 ( F_54 ( F_53 ) ) ,
V_122 ) ;
F_39 ( F_58 ( F_54 ( F_53 ) ) ,
V_123 ) ;
F_39 ( F_59
( F_55 ( F_53 ) , F_54 ( F_53 ) ) ,
V_124 ) ;
F_39 ( F_60
( F_55 ( F_53 ) , F_54 ( F_53 ) ) ,
V_125 ) ;
F_39 ( F_63 ( F_54 ( F_53 ) ) , 0 ) ;
V_120 . V_8 = 0 ;
F_73 ( F_53 , V_120 ) ;
F_74 ( F_53 ) ;
V_128 ;
if ( V_112 )
F_66 ( L_4 ) ;
return ! ! V_112 ;
}
int F_75 ( void )
{
int V_103 ;
int V_4 ;
F_76 () ;
V_103 = F_1 () ;
for ( V_4 = 0 ; V_4 < V_103 ; V_4 ++ ) {
if ( F_3 ( V_4 ) > 0 )
F_42 ( V_4 ) ;
}
F_77 () ;
if ( ( F_2 ( V_138 )
|| F_2 ( V_139 ) )
&& ( F_10 () -> V_28 != V_140 ) )
F_50 () ;
return 0 ;
}
int F_78 ( void )
{
int V_104 = 0 ;
int V_4 ;
union V_141 V_142 ;
union V_143 V_144 ;
const int V_103 = F_1 () ;
if ( F_2 ( V_145 ) )
F_79 ( 1 ) ;
V_142 . V_8 = F_5 ( V_146 ) ;
V_142 . V_9 . V_147 = 0 ;
V_142 . V_9 . V_148 = 0 ;
F_39 ( V_146 , V_142 . V_8 ) ;
V_144 . V_8 = F_5 ( F_80 ( 0 ) ) ;
if ( ! V_144 . V_9 . V_24 ) {
V_144 . V_9 . V_24 = 1 ;
F_39 ( F_80 ( 0 ) , V_144 . V_8 ) ;
}
if ( ! F_2 ( V_149 ) &&
! F_2 ( V_37 ) &&
! F_2 ( V_33 ) ) {
V_144 . V_8 = F_5 ( F_80 ( 1 ) ) ;
if ( ! V_144 . V_9 . V_24 ) {
V_144 . V_9 . V_24 = 1 ;
F_39 ( F_80 ( 1 ) , V_144 . V_8 ) ;
}
}
F_81 () ;
for ( V_4 = 0 ; V_4 < V_103 ; V_4 ++ ) {
V_104 |= F_23 ( V_4 ) ;
if ( F_3 ( V_4 ) > 0 )
F_66 ( L_5 ,
V_4 ,
F_3 ( V_4 ) ,
F_82
( F_9
( V_4 ) ) ) ;
V_104 |= F_30 ( V_4 ) ;
V_104 |= F_34 ( V_4 ) ;
}
V_104 |= F_32 () ;
V_104 |= F_38 () ;
V_104 |= F_40 () ;
#if V_150
V_104 |= F_75 () ;
#endif
return V_104 ;
}
int F_83 ( void )
{
return F_84 () ;
}
T_6 F_74 ( int V_39 )
{
T_6 V_120 ;
int V_4 = F_85 ( V_39 ) ;
int V_151 = F_86 ( V_39 ) ;
if ( V_151 >= F_3 ( V_4 ) ) {
V_120 . V_8 = 0 ;
return V_120 ;
}
V_120 = F_87 ( V_39 ) ;
if ( V_120 . V_8 == V_152 [ V_39 ] . V_8 )
return V_120 ;
F_73 ( V_39 , V_120 ) ;
return V_152 [ V_39 ] ;
}
T_6 F_87 ( int V_39 )
{
T_6 V_104 ;
int V_4 = F_85 ( V_39 ) ;
int V_151 = F_86 ( V_39 ) ;
V_104 . V_8 = 0 ;
if ( V_151 >= F_3 ( V_4 ) )
return V_104 ;
switch ( F_9 ( V_4 ) ) {
case V_11 :
case V_76 :
break;
case V_13 :
V_104 = F_88 ( V_39 ) ;
break;
case V_25 :
if ( V_151 == 0 )
V_104 = F_89 ( V_39 ) ;
else {
V_104 . V_9 . V_153 = 1 ;
V_104 . V_9 . V_154 = 1 ;
V_104 . V_9 . V_155 = 1000 ;
}
break;
case V_26 :
V_104 = F_89 ( V_39 ) ;
break;
case V_38 :
V_104 = F_90 ( V_39 ) ;
break;
case V_12 :
case V_35 :
V_104 = F_91 ( V_39 ) ;
break;
case V_14 :
case V_15 :
break;
}
return V_104 ;
}
int F_73 ( int V_39 , T_6 V_120 )
{
int V_104 = - 1 ;
int V_4 = F_85 ( V_39 ) ;
int V_151 = F_86 ( V_39 ) ;
if ( V_151 >= F_3 ( V_4 ) )
return - 1 ;
switch ( F_9 ( V_4 ) ) {
case V_11 :
case V_76 :
break;
case V_13 :
V_104 = F_92 ( V_39 , V_120 ) ;
break;
case V_26 :
case V_25 :
V_104 = F_93 ( V_39 , V_120 ) ;
break;
case V_38 :
V_104 = F_94 ( V_39 , V_120 ) ;
break;
case V_12 :
case V_35 :
V_104 = F_95 ( V_39 , V_120 ) ;
break;
case V_14 :
case V_15 :
break;
}
if ( V_104 == 0 )
V_152 [ V_39 ] . V_8 = V_120 . V_8 ;
return V_104 ;
}
int F_96 ( int V_39 , int V_156 ,
int V_157 )
{
int V_104 = - 1 ;
int V_4 = F_85 ( V_39 ) ;
int V_151 = F_86 ( V_39 ) ;
if ( V_151 >= F_3 ( V_4 ) )
return - 1 ;
switch ( F_9 ( V_4 ) ) {
case V_11 :
case V_76 :
case V_38 :
case V_14 :
case V_15 :
break;
case V_13 :
V_104 =
F_97 ( V_39 ,
V_156 ,
V_157 ) ;
break;
case V_26 :
case V_25 :
V_104 =
F_98 ( V_39 ,
V_156 ,
V_157 ) ;
break;
case V_12 :
case V_35 :
V_104 =
F_99 ( V_39 ,
V_156 ,
V_157 ) ;
break;
}
return V_104 ;
}
