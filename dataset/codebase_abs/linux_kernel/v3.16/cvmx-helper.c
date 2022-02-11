int F_1 ( void )
{
if ( F_2 ( V_1 ) || F_2 ( V_2 ) )
return 4 ;
else
return 3 ;
}
int F_3 ( int V_3 )
{
return V_4 [ V_3 ] ;
}
static T_1 F_4 ( int V_3 )
{
union V_5 V_6 ;
switch ( V_3 ) {
case 0 :
V_6 . V_7 = F_5 ( F_6 ( 0 ) ) ;
if ( V_6 . V_8 . V_9 == 15 )
return V_10 ;
if ( V_6 . V_8 . V_6 == 2 )
return V_11 ;
else if ( V_6 . V_8 . V_6 == 3 )
return V_12 ;
else
return V_10 ;
case 2 :
case 3 :
case 4 :
V_6 . V_7 = F_5 ( F_6 ( V_3 ) ) ;
if ( V_6 . V_8 . V_9 == 15 )
return V_10 ;
if ( V_6 . V_8 . V_6 == 2 )
return V_11 ;
else if ( V_6 . V_8 . V_6 == 3 )
return V_12 ;
else
return V_10 ;
case 7 :
V_6 . V_7 = F_5 ( F_6 ( 3 ) ) ;
if ( V_6 . V_8 . V_9 == 15 ) {
return V_10 ;
} else if ( V_6 . V_8 . V_6 != 0 ) {
V_6 . V_7 = F_5 ( F_6 ( 1 ) ) ;
if ( V_6 . V_8 . V_6 != 0 )
return V_10 ;
}
return V_13 ;
case 8 :
return V_14 ;
default:
return V_10 ;
}
}
static T_1 F_7 ( int V_3 )
{
union V_15 V_16 ;
if ( F_2 ( V_17 ) )
return F_4 ( V_3 ) ;
if ( V_3 == 2 )
return V_13 ;
if ( V_3 == 3 )
return V_14 ;
if ( ( F_2 ( V_18 ) &&
( V_3 == 4 || V_3 == 5 ) ) ||
( F_2 ( V_19 ) &&
V_3 >= 4 && V_3 <= 7 ) ) {
return V_10 ;
}
if ( F_2 ( V_19 ) ) {
union V_5 V_20 ;
if ( V_3 == 0 )
V_20 . V_7 = F_5 ( F_6 ( 2 ) ) ;
else if ( V_3 == 1 )
V_20 . V_7 = F_5 ( F_6 ( 1 ) ) ;
else
return V_10 ;
if ( V_20 . V_8 . V_9 == 15 )
return V_10 ;
if ( V_20 . V_8 . V_6 == 9 )
return V_11 ;
else if ( V_20 . V_8 . V_6 == 11 )
return V_12 ;
else
return V_10 ;
} else if ( F_2 ( V_21 ) ) {
union V_5 V_6 ;
if ( V_3 == 0 ) {
V_6 . V_7 = F_5 ( F_6 ( 2 ) ) ;
if ( V_6 . V_8 . V_6 == 2 )
return V_11 ;
else if ( V_6 . V_8 . V_6 == 3 )
return V_12 ;
else
return V_10 ;
} else if ( V_3 == 1 ) {
V_6 . V_7 = F_5 ( F_6 ( 0 ) ) ;
if ( V_6 . V_8 . V_6 == 2 )
return V_11 ;
else if ( V_6 . V_8 . V_6 == 3 )
return V_12 ;
else
return V_10 ;
}
} else if ( F_2 ( V_22 ) ) {
if ( V_3 == 0 ) {
union V_5 V_6 ;
V_6 . V_7 = F_5 ( F_6 ( 0 ) ) ;
if ( V_6 . V_8 . V_6 == 2 )
return V_11 ;
}
return V_10 ;
}
if ( V_3 == 1 && F_2 ( V_18 ) )
return V_10 ;
V_16 . V_7 = F_5 ( F_8 ( V_3 ) ) ;
if ( F_2 ( V_18 ) ) {
switch ( V_16 . V_23 . V_16 ) {
case 0 :
return V_11 ;
case 1 :
return V_12 ;
default:
return V_10 ;
}
} else {
if ( ! V_16 . V_8 . V_24 )
return V_10 ;
if ( V_16 . V_8 . type )
return V_25 ;
else
return V_26 ;
}
}
T_1 F_9 ( int V_3 )
{
union V_15 V_16 ;
if ( V_3 < 0 ||
V_3 >= F_1 () )
return V_10 ;
if ( F_2 ( V_27 ) || F_2 ( V_22 ) )
return F_7 ( V_3 ) ;
if ( V_3 == 2 )
return V_13 ;
if ( V_3 == 3 ) {
if ( F_2 ( V_1 )
|| F_2 ( V_2 ) )
return V_14 ;
else
return V_10 ;
}
if ( V_3 == 0
&& F_10 () -> V_28 == V_29
&& F_10 () -> V_30 == 1 ) {
return V_25 ;
}
if ( ( V_3 == 1 )
&& ( F_2 ( V_31 ) || F_2 ( V_32 )
|| F_2 ( V_33 )
|| F_2 ( V_2 ) ) )
return V_10 ;
V_16 . V_7 = F_5 ( F_8 ( V_3 ) ) ;
if ( F_2 ( V_1 ) || F_2 ( V_2 ) ) {
switch ( V_16 . V_34 . V_16 ) {
case 0 :
return V_10 ;
case 1 :
return V_12 ;
case 2 :
return V_11 ;
case 3 :
return V_35 ;
default:
return V_10 ;
}
} else {
if ( ! V_16 . V_8 . V_24 )
return V_10 ;
if ( V_16 . V_8 . type ) {
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
V_41 . V_7 = F_5 ( F_12 ( V_39 ) ) ;
V_43 . V_7 = F_5 ( F_13 ( V_39 ) ) ;
V_41 . V_8 . V_44 = V_39 & 0x7 ;
V_41 . V_8 . V_16 = V_45 ;
V_43 . V_8 . V_46 = V_47 ;
V_43 . V_8 . V_48 = V_49 ;
V_43 . V_8 . V_50 = V_51 ;
V_43 . V_8 . V_52 = V_53 ;
V_43 . V_8 . V_54 = V_55 ;
V_43 . V_8 . V_56 = V_57 ;
V_43 . V_8 . V_58 = V_59 ;
V_43 . V_8 . V_60 = V_61 ;
V_43 . V_8 . V_62 = V_63 ;
V_43 . V_8 . V_64 = V_65 ;
V_43 . V_8 . V_66 = V_67 ;
V_43 . V_8 . V_68 = V_69 ;
V_43 . V_8 . V_70 = V_69 ;
V_43 . V_8 . V_71 = V_69 ;
V_43 . V_8 . V_72 = V_69 ;
V_43 . V_8 . V_73 = V_69 ;
V_43 . V_8 . V_74 = 0 ;
F_14 ( V_39 , V_41 , V_43 ) ;
if ( V_75 )
V_75 ( V_39 ) ;
return 0 ;
}
int F_15 ( int V_3 )
{
switch ( F_9 ( V_3 ) ) {
case V_10 :
case V_76 :
V_4 [ V_3 ] = 0 ;
break;
case V_12 :
V_4 [ V_3 ] =
F_16 ( V_3 ) ;
break;
case V_26 :
case V_25 :
V_4 [ V_3 ] =
F_17 ( V_3 ) ;
break;
case V_38 :
V_4 [ V_3 ] =
F_18 ( V_3 ) ;
break;
case V_11 :
case V_35 :
V_4 [ V_3 ] =
F_19 ( V_3 ) ;
break;
case V_13 :
V_4 [ V_3 ] =
F_20 ( V_3 ) ;
break;
case V_14 :
V_4 [ V_3 ] =
F_21 ( V_3 ) ;
break;
}
V_4 [ V_3 ] =
F_22 ( V_3 ,
V_4
[ V_3 ] ) ;
V_77 ;
return 0 ;
}
int F_23 ( int V_3 )
{
F_15 ( V_3 ) ;
switch ( F_9 ( V_3 ) ) {
case V_10 :
case V_76 :
break;
case V_12 :
F_24 ( V_3 ) ;
break;
case V_26 :
case V_25 :
F_25 ( V_3 ) ;
break;
case V_38 :
F_26 ( V_3 ) ;
break;
case V_11 :
case V_35 :
F_27 ( V_3 ) ;
break;
case V_13 :
F_28 ( V_3 ) ;
break;
case V_14 :
F_29 ( V_3 ) ;
break;
}
V_77 ;
return 0 ;
}
static int F_30 ( int V_3 )
{
int V_39 = F_31 ( V_3 , 0 ) ;
int V_78 = V_4 [ V_3 ] ;
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
static int F_34 ( int V_3 )
{
T_2 V_85 [ 16 ] =
{ 8 , 7 , 6 , 5 , 4 , 3 , 2 , 1 , 8 , 7 , 6 , 5 , 4 , 3 , 2 , 1 } ;
int V_39 = F_31 ( V_3 , 0 ) ;
int V_78 = V_4 [ V_3 ] ;
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
V_88 . V_7 = 0 ;
V_88 . V_8 . V_89 = 0xfff ;
V_88 . V_8 . V_90 = 0 ;
F_39 ( V_91 , V_88 . V_7 ) ;
return 0 ;
}
static int F_40 ( void )
{
#if V_92
int V_93 = F_1 () ;
int V_3 ;
for ( V_3 = 0 ; V_3 < V_93 ; V_3 ++ ) {
switch ( F_9 ( V_3 ) ) {
case V_10 :
case V_76 :
case V_13 :
case V_14 :
case V_12 :
break;
case V_26 :
case V_25 :
case V_38 :
case V_11 :
case V_35 :
F_41 ( V_3 , 0xf ) ;
break;
}
}
#endif
return 0 ;
}
static int F_42 ( int V_3 )
{
int V_94 = 0 ;
switch ( F_9 ( V_3 ) ) {
case V_10 :
case V_76 :
break;
case V_12 :
V_94 = F_43 ( V_3 ) ;
break;
case V_26 :
case V_25 :
V_94 = F_44 ( V_3 ) ;
break;
case V_38 :
V_94 = F_45 ( V_3 ) ;
break;
case V_11 :
case V_35 :
V_94 = F_46 ( V_3 ) ;
break;
case V_13 :
V_94 = F_47 ( V_3 ) ;
break;
case V_14 :
V_94 = F_48 ( V_3 ) ;
break;
}
V_94 |= F_49 ( V_3 ) ;
return V_94 ;
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
T_2 * V_95 ;
T_4 V_96 ;
union V_97 V_98 , V_99 ;
T_5 * V_100 ;
int V_101 , V_102 = 0 , V_103 , V_104 ;
union V_105 V_106 ;
int V_107 ;
int V_108 ;
int V_109 ;
T_6 V_110 ;
T_2 V_111 =
F_5 ( F_56
( F_55 ( F_53 ) , F_54 ( F_53 ) ) ) ;
T_2 V_112 =
F_5 ( F_57 ( F_54 ( F_53 ) ) ) ;
T_2 V_113 =
F_5 ( F_58 ( F_54 ( F_53 ) ) ) ;
T_2 V_114 =
F_5 ( F_59
( F_55 ( F_53 ) , F_54 ( F_53 ) ) ) ;
T_2 V_115 =
F_5 ( F_60
( F_55 ( F_53 ) , F_54 ( F_53 ) ) ) ;
F_61 ( F_53 ) ;
F_39 ( F_58 ( F_54 ( F_53 ) ) , 0 ) ;
F_62 ( 100000000ull ) ;
for ( V_108 = 0 ; V_108 < 10 ; V_108 ++ ) {
V_107 = 100000 ;
V_103 = F_5 ( V_116 ) ;
V_104 = ( V_103 >> 7 ) & 0x7f ;
V_103 &= 0x7f ;
V_102 = ( 2 + V_104 - V_103 ) & 3 ;
if ( V_102 == 0 )
goto V_117;
V_102 += 1 ;
V_101 =
F_51 +
( ( V_102 - 1 ) * F_52 ) -
( F_52 / 2 ) ;
F_39 ( F_63 ( F_54 ( F_53 ) ) ,
1 << F_55 ( F_53 ) ) ;
V_118 ;
V_98 . V_7 = 0 ;
V_98 . V_8 . V_119 =
F_64 ( F_65 ( V_82 ) ) ;
if ( V_98 . V_8 . V_119 == 0 ) {
F_66 ( L_1
L_2 ) ;
goto V_117;
}
V_98 . V_8 . V_120 = V_82 ;
V_98 . V_8 . V_101 = V_102 ;
V_99 . V_7 = 0 ;
V_99 . V_8 . V_119 =
F_64 ( F_65 ( V_121 ) ) ;
if ( V_99 . V_8 . V_119 == 0 ) {
F_66 ( L_1
L_2 ) ;
goto V_117;
}
V_99 . V_8 . V_109 = 1 ;
V_99 . V_8 . V_120 = V_121 ;
V_99 . V_8 . V_101 = F_51 ;
V_95 = ( T_2 * ) F_67 ( V_99 . V_8 . V_119 ) ;
V_95 [ 0 ] = 0xffffffffffff0000ull ;
V_95 [ 1 ] = 0x08004510ull ;
V_95 [ 2 ] = ( ( T_2 ) ( V_101 - 14 ) << 48 ) | 0x5ae740004000ull ;
V_95 [ 3 ] = 0x3a5fc0a81073c0a8ull ;
for ( V_109 = 0 ; V_109 < V_102 ; V_109 ++ ) {
if ( V_109 > 0 )
V_99 . V_8 . V_101 =
F_52 ;
if ( V_109 == ( V_102 - 1 ) )
V_99 . V_8 . V_109 = 0 ;
* ( T_2 * ) F_67 ( V_98 . V_8 . V_119 +
8 * V_109 ) = V_99 . V_7 ;
}
V_96 . V_7 = 0 ;
V_96 . V_8 . V_122 = V_102 ;
V_96 . V_8 . V_123 = V_101 ;
V_96 . V_8 . V_124 = 0 ;
V_96 . V_8 . V_125 = 1 ;
V_106 . V_7 =
F_5 ( F_56
( F_55 ( F_53 ) ,
F_54 ( F_53 ) ) ) ;
V_106 . V_8 . V_24 = 1 ;
F_39 ( F_56
( F_55 ( F_53 ) ,
F_54 ( F_53 ) ) , V_106 . V_7 ) ;
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
V_126 ) ;
F_70 ( F_53 ,
F_69
( F_53 ) , V_96 ,
V_98 , V_126 ) ;
V_118 ;
do {
V_100 = F_71 ( V_127 ) ;
V_107 -- ;
} while ( ( V_100 == NULL ) && ( V_107 > 0 ) );
if ( ! V_107 )
F_66 ( L_1
L_3 ) ;
if ( V_100 )
F_72 ( V_100 ) ;
}
V_117:
F_39 ( F_56
( F_55 ( F_53 ) , F_54 ( F_53 ) ) ,
V_111 ) ;
F_39 ( F_57 ( F_54 ( F_53 ) ) ,
V_112 ) ;
F_39 ( F_58 ( F_54 ( F_53 ) ) ,
V_113 ) ;
F_39 ( F_59
( F_55 ( F_53 ) , F_54 ( F_53 ) ) ,
V_114 ) ;
F_39 ( F_60
( F_55 ( F_53 ) , F_54 ( F_53 ) ) ,
V_115 ) ;
F_39 ( F_63 ( F_54 ( F_53 ) ) , 0 ) ;
V_110 . V_7 = 0 ;
F_73 ( F_53 , V_110 ) ;
F_74 ( F_53 ) ;
V_118 ;
if ( V_102 )
F_66 ( L_4 ) ;
return ! ! V_102 ;
}
int F_75 ( void )
{
int V_93 ;
int V_3 ;
F_76 () ;
V_93 = F_1 () ;
for ( V_3 = 0 ; V_3 < V_93 ; V_3 ++ ) {
if ( F_3 ( V_3 ) > 0 )
F_42 ( V_3 ) ;
}
F_77 () ;
if ( ( F_2 ( V_128 )
|| F_2 ( V_129 ) )
&& ( F_10 () -> V_28 != V_130 ) )
F_50 () ;
return 0 ;
}
int F_78 ( void )
{
int V_94 = 0 ;
int V_3 ;
union V_131 V_132 ;
union V_133 V_134 ;
const int V_93 = F_1 () ;
if ( F_2 ( V_135 ) )
F_79 ( 1 ) ;
V_132 . V_7 = F_5 ( V_136 ) ;
V_132 . V_8 . V_137 = 0 ;
V_132 . V_8 . V_138 = 0 ;
F_39 ( V_136 , V_132 . V_7 ) ;
V_134 . V_7 = F_5 ( F_80 ( 0 ) ) ;
if ( ! V_134 . V_8 . V_24 ) {
V_134 . V_8 . V_24 = 1 ;
F_39 ( F_80 ( 0 ) , V_134 . V_7 ) ;
}
if ( ! F_2 ( V_139 ) &&
! F_2 ( V_37 ) &&
! F_2 ( V_33 ) ) {
V_134 . V_7 = F_5 ( F_80 ( 1 ) ) ;
if ( ! V_134 . V_8 . V_24 ) {
V_134 . V_8 . V_24 = 1 ;
F_39 ( F_80 ( 1 ) , V_134 . V_7 ) ;
}
}
F_81 () ;
for ( V_3 = 0 ; V_3 < V_93 ; V_3 ++ ) {
V_94 |= F_23 ( V_3 ) ;
if ( F_3 ( V_3 ) > 0 )
F_66 ( L_5 ,
V_3 ,
F_3 ( V_3 ) ,
F_82
( F_9
( V_3 ) ) ) ;
V_94 |= F_30 ( V_3 ) ;
V_94 |= F_34 ( V_3 ) ;
}
V_94 |= F_32 () ;
V_94 |= F_38 () ;
V_94 |= F_40 () ;
#if V_140
V_94 |= F_75 () ;
#endif
return V_94 ;
}
int F_83 ( void )
{
return F_84 () ;
}
T_6 F_74 ( int V_39 )
{
T_6 V_110 ;
int V_3 = F_85 ( V_39 ) ;
int V_141 = F_86 ( V_39 ) ;
if ( V_141 >= F_3 ( V_3 ) ) {
V_110 . V_7 = 0 ;
return V_110 ;
}
V_110 = F_87 ( V_39 ) ;
if ( V_110 . V_7 == V_142 [ V_39 ] . V_7 )
return V_110 ;
F_73 ( V_39 , V_110 ) ;
return V_142 [ V_39 ] ;
}
T_6 F_87 ( int V_39 )
{
T_6 V_94 ;
int V_3 = F_85 ( V_39 ) ;
int V_141 = F_86 ( V_39 ) ;
V_94 . V_7 = 0 ;
if ( V_141 >= F_3 ( V_3 ) )
return V_94 ;
switch ( F_9 ( V_3 ) ) {
case V_10 :
case V_76 :
break;
case V_12 :
V_94 = F_88 ( V_39 ) ;
break;
case V_25 :
if ( V_141 == 0 )
V_94 = F_89 ( V_39 ) ;
else {
V_94 . V_8 . V_143 = 1 ;
V_94 . V_8 . V_144 = 1 ;
V_94 . V_8 . V_145 = 1000 ;
}
break;
case V_26 :
V_94 = F_89 ( V_39 ) ;
break;
case V_38 :
V_94 = F_90 ( V_39 ) ;
break;
case V_11 :
case V_35 :
V_94 = F_91 ( V_39 ) ;
break;
case V_13 :
case V_14 :
break;
}
return V_94 ;
}
int F_73 ( int V_39 , T_6 V_110 )
{
int V_94 = - 1 ;
int V_3 = F_85 ( V_39 ) ;
int V_141 = F_86 ( V_39 ) ;
if ( V_141 >= F_3 ( V_3 ) )
return - 1 ;
switch ( F_9 ( V_3 ) ) {
case V_10 :
case V_76 :
break;
case V_12 :
V_94 = F_92 ( V_39 , V_110 ) ;
break;
case V_26 :
case V_25 :
V_94 = F_93 ( V_39 , V_110 ) ;
break;
case V_38 :
V_94 = F_94 ( V_39 , V_110 ) ;
break;
case V_11 :
case V_35 :
V_94 = F_95 ( V_39 , V_110 ) ;
break;
case V_13 :
case V_14 :
break;
}
if ( V_94 == 0 )
V_142 [ V_39 ] . V_7 = V_110 . V_7 ;
return V_94 ;
}
int F_96 ( int V_39 , int V_146 ,
int V_147 )
{
int V_94 = - 1 ;
int V_3 = F_85 ( V_39 ) ;
int V_141 = F_86 ( V_39 ) ;
if ( V_141 >= F_3 ( V_3 ) )
return - 1 ;
switch ( F_9 ( V_3 ) ) {
case V_10 :
case V_76 :
case V_38 :
case V_13 :
case V_14 :
break;
case V_12 :
V_94 =
F_97 ( V_39 ,
V_146 ,
V_147 ) ;
break;
case V_26 :
case V_25 :
V_94 =
F_98 ( V_39 ,
V_146 ,
V_147 ) ;
break;
case V_11 :
case V_35 :
V_94 =
F_99 ( V_39 ,
V_146 ,
V_147 ) ;
break;
}
return V_94 ;
}
