int F_1 ( void )
{
if ( F_2 ( V_1 ) )
return 9 ;
if ( F_2 ( V_2 ) || F_2 ( V_3 ) )
return 4 ;
if ( F_2 ( V_4 ) )
return 5 ;
else
return 3 ;
}
int F_3 ( int V_5 )
{
return V_6 [ V_5 ] ;
}
static T_1 F_4 ( int V_5 )
{
union V_7 V_8 ;
switch ( V_5 ) {
case 0 :
V_8 . V_9 = F_5 ( F_6 ( 0 ) ) ;
if ( V_8 . V_10 . V_11 == 15 )
return V_12 ;
if ( V_8 . V_10 . V_8 == 2 )
return V_13 ;
else if ( V_8 . V_10 . V_8 == 3 )
return V_14 ;
else
return V_12 ;
case 2 :
case 3 :
case 4 :
V_8 . V_9 = F_5 ( F_6 ( V_5 ) ) ;
if ( V_8 . V_10 . V_11 == 15 )
return V_12 ;
if ( V_8 . V_10 . V_8 == 2 )
return V_13 ;
else if ( V_8 . V_10 . V_8 == 3 )
return V_14 ;
else
return V_12 ;
case 7 :
V_8 . V_9 = F_5 ( F_6 ( 3 ) ) ;
if ( V_8 . V_10 . V_11 == 15 ) {
return V_12 ;
} else if ( V_8 . V_10 . V_8 != 0 ) {
V_8 . V_9 = F_5 ( F_6 ( 1 ) ) ;
if ( V_8 . V_10 . V_8 != 0 )
return V_12 ;
}
return V_15 ;
case 8 :
return V_16 ;
default:
return V_12 ;
}
}
static T_1 F_7 ( int V_5 )
{
union V_17 V_18 ;
if ( F_2 ( V_1 ) )
return F_4 ( V_5 ) ;
if ( V_5 == 2 )
return V_15 ;
if ( V_5 == 3 )
return V_16 ;
if ( ( F_2 ( V_19 ) &&
( V_5 == 4 || V_5 == 5 ) ) ||
( F_2 ( V_20 ) &&
V_5 >= 4 && V_5 <= 7 ) ) {
return V_12 ;
}
if ( F_2 ( V_20 ) ) {
union V_7 V_21 ;
if ( V_5 == 0 )
V_21 . V_9 = F_5 ( F_6 ( 2 ) ) ;
else if ( V_5 == 1 )
V_21 . V_9 = F_5 ( F_6 ( 1 ) ) ;
else
return V_12 ;
if ( V_21 . V_10 . V_11 == 15 )
return V_12 ;
if ( V_21 . V_10 . V_8 == 9 )
return V_13 ;
else if ( V_21 . V_10 . V_8 == 11 )
return V_14 ;
else
return V_12 ;
} else if ( F_2 ( V_22 ) ) {
union V_7 V_8 ;
if ( V_5 == 0 ) {
V_8 . V_9 = F_5 ( F_6 ( 2 ) ) ;
if ( V_8 . V_10 . V_8 == 2 )
return V_13 ;
else if ( V_8 . V_10 . V_8 == 3 )
return V_14 ;
else
return V_12 ;
} else if ( V_5 == 1 ) {
V_8 . V_9 = F_5 ( F_6 ( 0 ) ) ;
if ( V_8 . V_10 . V_8 == 2 )
return V_13 ;
else if ( V_8 . V_10 . V_8 == 3 )
return V_14 ;
else
return V_12 ;
}
} else if ( F_2 ( V_23 ) ) {
if ( V_5 == 0 ) {
union V_7 V_8 ;
V_8 . V_9 = F_5 ( F_6 ( 0 ) ) ;
if ( V_8 . V_10 . V_8 == 2 )
return V_13 ;
}
return V_12 ;
}
if ( V_5 == 1 && F_2 ( V_19 ) )
return V_12 ;
V_18 . V_9 = F_5 ( F_8 ( V_5 ) ) ;
if ( F_2 ( V_19 ) ) {
switch ( V_18 . V_24 . V_18 ) {
case 0 :
return V_13 ;
case 1 :
return V_14 ;
default:
return V_12 ;
}
} else {
if ( ! V_18 . V_10 . V_25 )
return V_12 ;
if ( V_18 . V_10 . type )
return V_26 ;
else
return V_27 ;
}
}
static T_1 F_9 ( int V_5 )
{
union V_17 V_18 ;
V_18 . V_9 = F_5 ( F_8 ( V_5 ) ) ;
switch ( V_5 ) {
case 0 :
case 1 :
switch ( V_18 . V_28 . V_18 ) {
case 0 :
return V_12 ;
case 1 :
case 2 :
return V_13 ;
case 3 :
return V_14 ;
default:
return V_13 ;
}
case 2 :
return V_15 ;
case 3 :
return V_16 ;
case 4 :
return V_27 ;
default:
return V_12 ;
}
}
T_1 F_10 ( int V_5 )
{
union V_17 V_18 ;
if ( V_5 < 0 ||
V_5 >= F_1 () )
return V_12 ;
if ( F_2 ( V_4 ) )
return F_9 ( V_5 ) ;
if ( F_2 ( V_29 ) || F_2 ( V_23 ) )
return F_7 ( V_5 ) ;
if ( V_5 == 2 )
return V_15 ;
if ( V_5 == 3 ) {
if ( F_2 ( V_2 )
|| F_2 ( V_3 ) )
return V_16 ;
else
return V_12 ;
}
if ( V_5 == 0
&& F_11 () -> V_30 == V_31
&& F_11 () -> V_32 == 1 ) {
return V_26 ;
}
if ( ( V_5 == 1 )
&& ( F_2 ( V_33 ) || F_2 ( V_34 )
|| F_2 ( V_35 )
|| F_2 ( V_3 ) ) )
return V_12 ;
V_18 . V_9 = F_5 ( F_8 ( V_5 ) ) ;
if ( F_2 ( V_2 ) || F_2 ( V_3 ) ) {
switch ( V_18 . V_36 . V_18 ) {
case 0 :
return V_12 ;
case 1 :
return V_14 ;
case 2 :
return V_13 ;
case 3 :
return V_37 ;
default:
return V_12 ;
}
} else {
if ( ! V_18 . V_10 . V_25 )
return V_12 ;
if ( V_18 . V_10 . type ) {
if ( F_2 ( V_38 )
|| F_2 ( V_39 ) )
return V_40 ;
else
return V_26 ;
} else
return V_27 ;
}
}
static int F_12 ( int V_41 )
{
union V_42 V_43 ;
union V_44 V_45 ;
V_43 . V_9 = F_5 ( F_13 ( V_41 ) ) ;
V_45 . V_9 = F_5 ( F_14 ( V_41 ) ) ;
V_43 . V_10 . V_46 = V_41 & 0x7 ;
V_43 . V_10 . V_18 = V_47 ;
V_45 . V_10 . V_48 = V_49 ;
V_45 . V_10 . V_50 = V_51 ;
V_45 . V_10 . V_52 = V_53 ;
V_45 . V_10 . V_54 = V_55 ;
V_45 . V_10 . V_56 = V_57 ;
V_45 . V_10 . V_58 = V_59 ;
V_45 . V_10 . V_60 = V_61 ;
V_45 . V_10 . V_62 = V_63 ;
V_45 . V_10 . V_64 = V_65 ;
V_45 . V_10 . V_66 = V_67 ;
V_45 . V_10 . V_68 = V_69 ;
V_45 . V_10 . V_70 = V_71 ;
V_45 . V_10 . V_72 = V_71 ;
V_45 . V_10 . V_73 = V_71 ;
V_45 . V_10 . V_74 = V_71 ;
V_45 . V_10 . V_75 = V_71 ;
V_45 . V_10 . V_76 = 0 ;
F_15 ( V_41 , V_43 , V_45 ) ;
if ( V_77 )
V_77 ( V_41 ) ;
return 0 ;
}
int F_16 ( int V_5 )
{
switch ( F_10 ( V_5 ) ) {
case V_12 :
case V_78 :
V_6 [ V_5 ] = 0 ;
break;
case V_14 :
V_6 [ V_5 ] =
F_17 ( V_5 ) ;
break;
case V_27 :
case V_26 :
V_6 [ V_5 ] =
F_18 ( V_5 ) ;
break;
case V_40 :
V_6 [ V_5 ] =
F_19 ( V_5 ) ;
break;
case V_13 :
case V_37 :
V_6 [ V_5 ] =
F_20 ( V_5 ) ;
break;
case V_15 :
V_6 [ V_5 ] =
F_21 ( V_5 ) ;
break;
case V_16 :
V_6 [ V_5 ] =
F_22 ( V_5 ) ;
break;
}
V_6 [ V_5 ] =
F_23 ( V_5 ,
V_6
[ V_5 ] ) ;
V_79 ;
return 0 ;
}
int F_24 ( int V_5 )
{
F_16 ( V_5 ) ;
switch ( F_10 ( V_5 ) ) {
case V_12 :
case V_78 :
break;
case V_14 :
F_25 ( V_5 ) ;
break;
case V_27 :
case V_26 :
F_26 ( V_5 ) ;
break;
case V_40 :
F_27 ( V_5 ) ;
break;
case V_13 :
case V_37 :
F_28 ( V_5 ) ;
break;
case V_15 :
F_29 ( V_5 ) ;
break;
case V_16 :
F_30 ( V_5 ) ;
break;
}
V_79 ;
return 0 ;
}
static int F_31 ( int V_5 )
{
int V_41 = F_32 ( V_5 , 0 ) ;
int V_80 = V_6 [ V_5 ] ;
while ( V_80 -- ) {
F_12 ( V_41 ) ;
V_41 ++ ;
}
return 0 ;
}
static int F_33 ( void )
{
F_34 ( V_81 / 8 ,
V_82 / 8 ,
V_83 / 8 ,
( V_82 + 8 ) / 128 ,
( V_83 + 8 ) / 128 ,
V_84 ,
V_85 ,
V_86 ) ;
return 0 ;
}
static int F_35 ( int V_5 )
{
T_2 V_87 [ 16 ] =
{ 8 , 7 , 6 , 5 , 4 , 3 , 2 , 1 , 8 , 7 , 6 , 5 , 4 , 3 , 2 , 1 } ;
int V_41 = F_32 ( V_5 , 0 ) ;
int V_80 = V_6 [ V_5 ] ;
while ( V_80 -- ) {
if ( V_88 )
V_88 ( V_41 , V_87 ) ;
F_36 ( V_41 ,
F_37 ( V_41 ,
0 ) ,
F_38 ( V_41 ) ,
V_87 ) ;
V_41 ++ ;
}
return 0 ;
}
static int F_39 ( void )
{
union V_89 V_90 ;
V_90 . V_9 = 0 ;
V_90 . V_10 . V_91 = 0xfff ;
V_90 . V_10 . V_92 = 0 ;
F_40 ( V_93 , V_90 . V_9 ) ;
if ( F_2 ( V_1 ) ) {
union V_94 V_95 ;
V_95 . V_9 = 0 ;
V_95 . V_10 . V_96 = 59 ;
V_95 . V_10 . V_97 = 59 ;
V_95 . V_10 . V_98 = 59 ;
V_95 . V_10 . V_99 = 59 ;
V_95 . V_10 . V_100 = 59 ;
V_95 . V_10 . V_101 = 59 ;
V_95 . V_10 . V_102 = 59 ;
F_40 ( V_103 , V_95 . V_9 ) ;
}
return 0 ;
}
static int F_41 ( void )
{
#if V_104
int V_105 = F_1 () ;
int V_5 ;
for ( V_5 = 0 ; V_5 < V_105 ; V_5 ++ ) {
switch ( F_10 ( V_5 ) ) {
case V_12 :
case V_78 :
case V_15 :
case V_16 :
case V_14 :
break;
case V_27 :
case V_26 :
case V_40 :
case V_13 :
case V_37 :
F_42 ( V_5 , 0xf ) ;
break;
}
}
#endif
return 0 ;
}
static int F_43 ( int V_5 )
{
int V_106 = 0 ;
switch ( F_10 ( V_5 ) ) {
case V_12 :
case V_78 :
break;
case V_14 :
V_106 = F_44 ( V_5 ) ;
break;
case V_27 :
case V_26 :
V_106 = F_45 ( V_5 ) ;
break;
case V_40 :
V_106 = F_46 ( V_5 ) ;
break;
case V_13 :
case V_37 :
V_106 = F_47 ( V_5 ) ;
break;
case V_15 :
V_106 = F_48 ( V_5 ) ;
break;
case V_16 :
V_106 = F_49 ( V_5 ) ;
break;
}
V_106 |= F_50 ( V_5 ) ;
return V_106 ;
}
int F_51 ( void )
{
#define F_52 \
(CVMX_FPA_PACKET_POOL_SIZE-8-CVMX_HELPER_FIRST_MBUFF_SKIP)
#define F_53 \
(CVMX_FPA_PACKET_POOL_SIZE-8-CVMX_HELPER_NOT_FIRST_MBUFF_SKIP)
#define F_54 0
#define F_55 ( T_3 ) (port >> 4)
#define F_56 ( T_3 ) (port & 0xf)
T_2 * V_107 ;
T_4 V_108 ;
union V_109 V_110 , V_111 ;
T_5 * V_112 ;
int V_113 , V_114 = 0 , V_115 , V_116 ;
union V_117 V_118 ;
int V_119 ;
int V_120 ;
int V_121 ;
T_2 V_122 =
F_5 ( F_57
( F_56 ( F_54 ) , F_55 ( F_54 ) ) ) ;
T_2 V_123 =
F_5 ( F_58 ( F_55 ( F_54 ) ) ) ;
T_2 V_124 =
F_5 ( F_59 ( F_55 ( F_54 ) ) ) ;
T_2 V_125 =
F_5 ( F_60
( F_56 ( F_54 ) , F_55 ( F_54 ) ) ) ;
T_2 V_126 =
F_5 ( F_61
( F_56 ( F_54 ) , F_55 ( F_54 ) ) ) ;
F_62 ( F_54 ) ;
F_40 ( F_59 ( F_55 ( F_54 ) ) , 0 ) ;
F_63 ( 100000000ull ) ;
for ( V_120 = 0 ; V_120 < 10 ; V_120 ++ ) {
V_119 = 100000 ;
V_115 = F_5 ( V_127 ) ;
V_116 = ( V_115 >> 7 ) & 0x7f ;
V_115 &= 0x7f ;
V_114 = ( 2 + V_116 - V_115 ) & 3 ;
if ( V_114 == 0 )
goto V_128;
V_114 += 1 ;
V_113 =
F_52 +
( ( V_114 - 1 ) * F_53 ) -
( F_53 / 2 ) ;
F_40 ( F_64 ( F_55 ( F_54 ) ) ,
1 << F_56 ( F_54 ) ) ;
V_129 ;
V_110 . V_9 = 0 ;
V_110 . V_10 . V_130 =
F_65 ( F_66 ( V_84 ) ) ;
if ( V_110 . V_10 . V_130 == 0 ) {
F_67 ( L_1
L_2 ) ;
goto V_128;
}
V_110 . V_10 . V_131 = V_84 ;
V_110 . V_10 . V_113 = V_114 ;
V_111 . V_9 = 0 ;
V_111 . V_10 . V_130 =
F_65 ( F_66 ( V_132 ) ) ;
if ( V_111 . V_10 . V_130 == 0 ) {
F_67 ( L_1
L_2 ) ;
goto V_128;
}
V_111 . V_10 . V_121 = 1 ;
V_111 . V_10 . V_131 = V_132 ;
V_111 . V_10 . V_113 = F_52 ;
V_107 = ( T_2 * ) F_68 ( V_111 . V_10 . V_130 ) ;
V_107 [ 0 ] = 0xffffffffffff0000ull ;
V_107 [ 1 ] = 0x08004510ull ;
V_107 [ 2 ] = ( ( T_2 ) ( V_113 - 14 ) << 48 ) | 0x5ae740004000ull ;
V_107 [ 3 ] = 0x3a5fc0a81073c0a8ull ;
for ( V_121 = 0 ; V_121 < V_114 ; V_121 ++ ) {
if ( V_121 > 0 )
V_111 . V_10 . V_113 =
F_53 ;
if ( V_121 == ( V_114 - 1 ) )
V_111 . V_10 . V_121 = 0 ;
* ( T_2 * ) F_68 ( V_110 . V_10 . V_130 +
8 * V_121 ) = V_111 . V_9 ;
}
V_108 . V_9 = 0 ;
V_108 . V_10 . V_133 = V_114 ;
V_108 . V_10 . V_134 = V_113 ;
V_108 . V_10 . V_135 = 0 ;
V_108 . V_10 . V_136 = 1 ;
V_118 . V_9 =
F_5 ( F_57
( F_56 ( F_54 ) ,
F_55 ( F_54 ) ) ) ;
V_118 . V_10 . V_25 = 1 ;
F_40 ( F_57
( F_56 ( F_54 ) ,
F_55 ( F_54 ) ) , V_118 . V_9 ) ;
F_40 ( F_58 ( F_55 ( F_54 ) ) ,
1 << F_56 ( F_54 ) ) ;
F_40 ( F_59 ( F_55 ( F_54 ) ) ,
1 << F_56 ( F_54 ) ) ;
F_40 ( F_60
( F_56 ( F_54 ) ,
F_55 ( F_54 ) ) , 65392 - 14 - 4 ) ;
F_40 ( F_61
( F_56 ( F_54 ) ,
F_55 ( F_54 ) ) , 65392 - 14 - 4 ) ;
F_69 ( F_54 ,
F_70
( F_54 ) ,
V_137 ) ;
F_71 ( F_54 ,
F_70
( F_54 ) , V_108 ,
V_110 , V_137 ) ;
V_129 ;
do {
V_112 = F_72 ( V_138 ) ;
V_119 -- ;
} while ( ( V_112 == NULL ) && ( V_119 > 0 ) );
if ( ! V_119 )
F_67 ( L_1
L_3 ) ;
if ( V_112 )
F_73 ( V_112 ) ;
}
V_128:
F_40 ( F_57
( F_56 ( F_54 ) , F_55 ( F_54 ) ) ,
V_122 ) ;
F_40 ( F_58 ( F_55 ( F_54 ) ) ,
V_123 ) ;
F_40 ( F_59 ( F_55 ( F_54 ) ) ,
V_124 ) ;
F_40 ( F_60
( F_56 ( F_54 ) , F_55 ( F_54 ) ) ,
V_125 ) ;
F_40 ( F_61
( F_56 ( F_54 ) , F_55 ( F_54 ) ) ,
V_126 ) ;
F_40 ( F_64 ( F_55 ( F_54 ) ) , 0 ) ;
V_129 ;
if ( V_114 )
F_67 ( L_4 ) ;
return ! ! V_114 ;
}
int F_74 ( void )
{
int V_105 ;
int V_5 ;
F_75 () ;
V_105 = F_1 () ;
for ( V_5 = 0 ; V_5 < V_105 ; V_5 ++ ) {
if ( F_3 ( V_5 ) > 0 )
F_43 ( V_5 ) ;
}
F_76 () ;
if ( ( F_2 ( V_139 )
|| F_2 ( V_140 ) )
&& ( F_11 () -> V_30 != V_141 ) )
F_51 () ;
return 0 ;
}
int F_77 ( void )
{
int V_106 = 0 ;
int V_5 ;
union V_142 V_143 ;
union V_144 V_145 ;
const int V_105 = F_1 () ;
if ( F_2 ( V_146 ) )
F_78 ( 1 ) ;
V_143 . V_9 = F_5 ( V_147 ) ;
V_143 . V_10 . V_148 = 0 ;
V_143 . V_10 . V_149 = 0 ;
F_40 ( V_147 , V_143 . V_9 ) ;
V_145 . V_9 = F_5 ( F_79 ( 0 ) ) ;
if ( ! V_145 . V_10 . V_25 ) {
V_145 . V_10 . V_25 = 1 ;
F_40 ( F_79 ( 0 ) , V_145 . V_9 ) ;
}
if ( ! F_2 ( V_150 ) &&
! F_2 ( V_39 ) &&
! F_2 ( V_35 ) ) {
V_145 . V_9 = F_5 ( F_79 ( 1 ) ) ;
if ( ! V_145 . V_10 . V_25 ) {
V_145 . V_10 . V_25 = 1 ;
F_40 ( F_79 ( 1 ) , V_145 . V_9 ) ;
}
}
F_80 () ;
for ( V_5 = 0 ; V_5 < V_105 ; V_5 ++ ) {
V_106 |= F_24 ( V_5 ) ;
if ( F_3 ( V_5 ) > 0 )
F_67 ( L_5 ,
V_5 ,
F_3 ( V_5 ) ,
F_81
( F_10
( V_5 ) ) ) ;
V_106 |= F_31 ( V_5 ) ;
V_106 |= F_35 ( V_5 ) ;
}
V_106 |= F_33 () ;
V_106 |= F_39 () ;
V_106 |= F_41 () ;
#if V_151
V_106 |= F_74 () ;
#endif
return V_106 ;
}
int F_82 ( void )
{
return F_83 () ;
}
T_6 F_84 ( int V_41 )
{
T_6 V_152 ;
int V_5 = F_85 ( V_41 ) ;
int V_153 = F_86 ( V_41 ) ;
if ( V_153 >= F_3 ( V_5 ) ) {
V_152 . V_9 = 0 ;
return V_152 ;
}
V_152 = F_87 ( V_41 ) ;
if ( V_152 . V_9 == V_154 [ V_41 ] . V_9 )
return V_152 ;
F_88 ( V_41 , V_152 ) ;
return V_154 [ V_41 ] ;
}
T_6 F_87 ( int V_41 )
{
T_6 V_106 ;
int V_5 = F_85 ( V_41 ) ;
int V_153 = F_86 ( V_41 ) ;
V_106 . V_9 = 0 ;
if ( V_153 >= F_3 ( V_5 ) )
return V_106 ;
switch ( F_10 ( V_5 ) ) {
case V_12 :
case V_78 :
break;
case V_14 :
V_106 = F_89 ( V_41 ) ;
break;
case V_26 :
if ( V_153 == 0 )
V_106 = F_90 ( V_41 ) ;
else {
V_106 . V_10 . V_155 = 1 ;
V_106 . V_10 . V_156 = 1 ;
V_106 . V_10 . V_157 = 1000 ;
}
break;
case V_27 :
V_106 = F_90 ( V_41 ) ;
break;
case V_40 :
V_106 = F_91 ( V_41 ) ;
break;
case V_13 :
case V_37 :
V_106 = F_92 ( V_41 ) ;
break;
case V_15 :
case V_16 :
break;
}
return V_106 ;
}
int F_88 ( int V_41 , T_6 V_152 )
{
int V_106 = - 1 ;
int V_5 = F_85 ( V_41 ) ;
int V_153 = F_86 ( V_41 ) ;
if ( V_153 >= F_3 ( V_5 ) )
return - 1 ;
switch ( F_10 ( V_5 ) ) {
case V_12 :
case V_78 :
break;
case V_14 :
V_106 = F_93 ( V_41 , V_152 ) ;
break;
case V_27 :
case V_26 :
V_106 = F_94 ( V_41 , V_152 ) ;
break;
case V_40 :
V_106 = F_95 ( V_41 , V_152 ) ;
break;
case V_13 :
case V_37 :
V_106 = F_96 ( V_41 , V_152 ) ;
break;
case V_15 :
case V_16 :
break;
}
if ( V_106 == 0 )
V_154 [ V_41 ] . V_9 = V_152 . V_9 ;
return V_106 ;
}
int F_97 ( int V_41 , int V_158 ,
int V_159 )
{
int V_106 = - 1 ;
int V_5 = F_85 ( V_41 ) ;
int V_153 = F_86 ( V_41 ) ;
if ( V_153 >= F_3 ( V_5 ) )
return - 1 ;
switch ( F_10 ( V_5 ) ) {
case V_12 :
case V_78 :
case V_40 :
case V_15 :
case V_16 :
break;
case V_14 :
V_106 =
F_98 ( V_41 ,
V_158 ,
V_159 ) ;
break;
case V_27 :
case V_26 :
V_106 =
F_99 ( V_41 ,
V_158 ,
V_159 ) ;
break;
case V_13 :
case V_37 :
V_106 =
F_100 ( V_41 ,
V_158 ,
V_159 ) ;
break;
}
return V_106 ;
}
