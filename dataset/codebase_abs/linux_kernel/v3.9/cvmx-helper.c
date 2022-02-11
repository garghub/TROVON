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
T_1 F_4 ( int V_3 )
{
union V_5 V_6 ;
if ( V_3 == 2 )
return V_7 ;
if ( V_3 == 3 ) {
if ( F_2 ( V_1 )
|| F_2 ( V_2 ) )
return V_8 ;
else
return V_9 ;
}
if ( V_3 == 0
&& F_5 () -> V_10 == V_11
&& F_5 () -> V_12 == 1 ) {
return V_13 ;
}
if ( ( V_3 == 1 )
&& ( F_2 ( V_14 ) || F_2 ( V_15 )
|| F_2 ( V_16 )
|| F_2 ( V_2 ) ) )
return V_9 ;
V_6 . V_17 = F_6 ( F_7 ( V_3 ) ) ;
if ( F_2 ( V_1 ) || F_2 ( V_2 ) ) {
switch ( V_6 . V_18 . V_6 ) {
case 0 :
return V_9 ;
case 1 :
return V_19 ;
case 2 :
return V_20 ;
case 3 :
return V_21 ;
default:
return V_9 ;
}
} else {
if ( ! V_6 . V_22 . V_23 )
return V_9 ;
if ( V_6 . V_22 . type ) {
if ( F_2 ( V_24 )
|| F_2 ( V_25 ) )
return V_26 ;
else
return V_13 ;
} else
return V_27 ;
}
}
static int F_8 ( int V_28 )
{
union V_29 V_30 ;
union V_31 V_32 ;
V_30 . V_17 = F_6 ( F_9 ( V_28 ) ) ;
V_32 . V_17 = F_6 ( F_10 ( V_28 ) ) ;
V_30 . V_22 . V_33 = V_28 & 0x7 ;
V_30 . V_22 . V_6 = V_34 ;
V_32 . V_22 . V_35 = V_36 ;
V_32 . V_22 . V_37 = V_38 ;
V_32 . V_22 . V_39 = V_40 ;
V_32 . V_22 . V_41 = V_42 ;
V_32 . V_22 . V_43 = V_44 ;
V_32 . V_22 . V_45 = V_46 ;
V_32 . V_22 . V_47 = V_48 ;
V_32 . V_22 . V_49 = V_50 ;
V_32 . V_22 . V_51 = V_52 ;
V_32 . V_22 . V_53 = V_54 ;
V_32 . V_22 . V_55 = V_56 ;
V_32 . V_22 . V_57 = V_58 ;
V_32 . V_22 . V_59 = V_58 ;
V_32 . V_22 . V_60 = V_58 ;
V_32 . V_22 . V_61 = V_58 ;
V_32 . V_22 . V_62 = V_58 ;
V_32 . V_22 . V_63 = 0 ;
F_11 ( V_28 , V_30 , V_32 ) ;
if ( V_64 )
V_64 ( V_28 ) ;
return 0 ;
}
int F_12 ( int V_3 )
{
switch ( F_4 ( V_3 ) ) {
case V_9 :
case V_65 :
V_4 [ V_3 ] = 0 ;
break;
case V_19 :
V_4 [ V_3 ] =
F_13 ( V_3 ) ;
break;
case V_27 :
case V_13 :
V_4 [ V_3 ] =
F_14 ( V_3 ) ;
break;
case V_26 :
V_4 [ V_3 ] =
F_15 ( V_3 ) ;
break;
case V_20 :
case V_21 :
V_4 [ V_3 ] =
F_16 ( V_3 ) ;
break;
case V_7 :
V_4 [ V_3 ] =
F_17 ( V_3 ) ;
break;
case V_8 :
V_4 [ V_3 ] =
F_18 ( V_3 ) ;
break;
}
V_4 [ V_3 ] =
F_19 ( V_3 ,
V_4
[ V_3 ] ) ;
V_66 ;
return 0 ;
}
int F_20 ( int V_3 )
{
F_12 ( V_3 ) ;
switch ( F_4 ( V_3 ) ) {
case V_9 :
case V_65 :
break;
case V_19 :
F_21 ( V_3 ) ;
break;
case V_27 :
case V_13 :
F_22 ( V_3 ) ;
break;
case V_26 :
F_23 ( V_3 ) ;
break;
case V_20 :
case V_21 :
F_24 ( V_3 ) ;
break;
case V_7 :
F_25 ( V_3 ) ;
break;
case V_8 :
F_26 ( V_3 ) ;
break;
}
V_66 ;
return 0 ;
}
static int F_27 ( int V_3 )
{
int V_28 = F_28 ( V_3 , 0 ) ;
int V_67 = V_4 [ V_3 ] ;
while ( V_67 -- ) {
F_8 ( V_28 ) ;
V_28 ++ ;
}
return 0 ;
}
static int F_29 ( void )
{
F_30 ( V_68 / 8 ,
V_69 / 8 ,
V_70 / 8 ,
( V_69 + 8 ) / 128 ,
( V_70 + 8 ) / 128 ,
V_71 ,
V_72 ,
V_73 ) ;
return 0 ;
}
static int F_31 ( int V_3 )
{
T_2 V_74 [ 16 ] =
{ 8 , 7 , 6 , 5 , 4 , 3 , 2 , 1 , 8 , 7 , 6 , 5 , 4 , 3 , 2 , 1 } ;
int V_28 = F_28 ( V_3 , 0 ) ;
int V_67 = V_4 [ V_3 ] ;
while ( V_67 -- ) {
if ( V_75 )
V_75 ( V_28 , V_74 ) ;
F_32 ( V_28 ,
F_33 ( V_28 ,
0 ) ,
F_34 ( V_28 ) ,
V_74 ) ;
V_28 ++ ;
}
return 0 ;
}
static int F_35 ( void )
{
union V_76 V_77 ;
V_77 . V_17 = 0 ;
V_77 . V_22 . V_78 = 0xfff ;
V_77 . V_22 . V_79 = 0 ;
F_36 ( V_80 , V_77 . V_17 ) ;
return 0 ;
}
static int F_37 ( void )
{
#if V_81
int V_82 = F_1 () ;
int V_3 ;
for ( V_3 = 0 ; V_3 < V_82 ; V_3 ++ ) {
switch ( F_4 ( V_3 ) ) {
case V_9 :
case V_65 :
case V_7 :
case V_8 :
case V_19 :
break;
case V_27 :
case V_13 :
case V_26 :
case V_20 :
case V_21 :
F_38 ( V_3 , 0xf ) ;
break;
}
}
#endif
return 0 ;
}
static int F_39 ( int V_3 )
{
int V_83 = 0 ;
switch ( F_4 ( V_3 ) ) {
case V_9 :
case V_65 :
break;
case V_19 :
V_83 = F_40 ( V_3 ) ;
break;
case V_27 :
case V_13 :
V_83 = F_41 ( V_3 ) ;
break;
case V_26 :
V_83 = F_42 ( V_3 ) ;
break;
case V_20 :
case V_21 :
V_83 = F_43 ( V_3 ) ;
break;
case V_7 :
V_83 = F_44 ( V_3 ) ;
break;
case V_8 :
V_83 = F_45 ( V_3 ) ;
break;
}
V_83 |= F_46 ( V_3 ) ;
return V_83 ;
}
int F_47 ( void )
{
#define F_48 \
(CVMX_FPA_PACKET_POOL_SIZE-8-CVMX_HELPER_FIRST_MBUFF_SKIP)
#define F_49 \
(CVMX_FPA_PACKET_POOL_SIZE-8-CVMX_HELPER_NOT_FIRST_MBUFF_SKIP)
#define F_50 0
#define F_51 ( T_3 ) (port >> 4)
#define F_52 ( T_3 ) (port & 0xf)
T_2 * V_84 ;
T_4 V_85 ;
union V_86 V_87 , V_88 ;
T_5 * V_89 ;
int V_90 , V_91 = 0 , V_92 , V_93 ;
union V_94 V_95 ;
int V_96 ;
int V_97 ;
int V_98 ;
T_6 V_99 ;
T_2 V_100 =
F_6 ( F_53
( F_52 ( F_50 ) , F_51 ( F_50 ) ) ) ;
T_2 V_101 =
F_6 ( F_54 ( F_51 ( F_50 ) ) ) ;
T_2 V_102 =
F_6 ( F_55 ( F_51 ( F_50 ) ) ) ;
T_2 V_103 =
F_6 ( F_56
( F_52 ( F_50 ) , F_51 ( F_50 ) ) ) ;
T_2 V_104 =
F_6 ( F_57
( F_52 ( F_50 ) , F_51 ( F_50 ) ) ) ;
F_58 ( F_50 ) ;
F_36 ( F_55 ( F_51 ( F_50 ) ) , 0 ) ;
F_59 ( 100000000ull ) ;
for ( V_97 = 0 ; V_97 < 10 ; V_97 ++ ) {
V_96 = 100000 ;
V_92 = F_6 ( V_105 ) ;
V_93 = ( V_92 >> 7 ) & 0x7f ;
V_92 &= 0x7f ;
V_91 = ( 2 + V_93 - V_92 ) & 3 ;
if ( V_91 == 0 )
goto V_106;
V_91 += 1 ;
V_90 =
F_48 +
( ( V_91 - 1 ) * F_49 ) -
( F_49 / 2 ) ;
F_36 ( F_60 ( F_51 ( F_50 ) ) ,
1 << F_52 ( F_50 ) ) ;
V_107 ;
V_87 . V_17 = 0 ;
V_87 . V_22 . V_108 =
F_61 ( F_62 ( V_71 ) ) ;
if ( V_87 . V_22 . V_108 == 0 ) {
F_63 ( L_1
L_2 ) ;
goto V_106;
}
V_87 . V_22 . V_109 = V_71 ;
V_87 . V_22 . V_90 = V_91 ;
V_88 . V_17 = 0 ;
V_88 . V_22 . V_108 =
F_61 ( F_62 ( V_110 ) ) ;
if ( V_88 . V_22 . V_108 == 0 ) {
F_63 ( L_1
L_2 ) ;
goto V_106;
}
V_88 . V_22 . V_98 = 1 ;
V_88 . V_22 . V_109 = V_110 ;
V_88 . V_22 . V_90 = F_48 ;
V_84 = ( T_2 * ) F_64 ( V_88 . V_22 . V_108 ) ;
V_84 [ 0 ] = 0xffffffffffff0000ull ;
V_84 [ 1 ] = 0x08004510ull ;
V_84 [ 2 ] = ( ( T_2 ) ( V_90 - 14 ) << 48 ) | 0x5ae740004000ull ;
V_84 [ 3 ] = 0x3a5fc0a81073c0a8ull ;
for ( V_98 = 0 ; V_98 < V_91 ; V_98 ++ ) {
if ( V_98 > 0 )
V_88 . V_22 . V_90 =
F_49 ;
if ( V_98 == ( V_91 - 1 ) )
V_88 . V_22 . V_98 = 0 ;
* ( T_2 * ) F_64 ( V_87 . V_22 . V_108 +
8 * V_98 ) = V_88 . V_17 ;
}
V_85 . V_17 = 0 ;
V_85 . V_22 . V_111 = V_91 ;
V_85 . V_22 . V_112 = V_90 ;
V_85 . V_22 . V_113 = 0 ;
V_85 . V_22 . V_114 = 1 ;
V_95 . V_17 =
F_6 ( F_53
( F_52 ( F_50 ) ,
F_51 ( F_50 ) ) ) ;
V_95 . V_22 . V_23 = 1 ;
F_36 ( F_53
( F_52 ( F_50 ) ,
F_51 ( F_50 ) ) , V_95 . V_17 ) ;
F_36 ( F_54 ( F_51 ( F_50 ) ) ,
1 << F_52 ( F_50 ) ) ;
F_36 ( F_55 ( F_51 ( F_50 ) ) ,
1 << F_52 ( F_50 ) ) ;
F_36 ( F_56
( F_52 ( F_50 ) ,
F_51 ( F_50 ) ) , 65392 - 14 - 4 ) ;
F_36 ( F_57
( F_52 ( F_50 ) ,
F_51 ( F_50 ) ) , 65392 - 14 - 4 ) ;
F_65 ( F_50 ,
F_66
( F_50 ) ,
V_115 ) ;
F_67 ( F_50 ,
F_66
( F_50 ) , V_85 ,
V_87 , V_115 ) ;
V_107 ;
do {
V_89 = F_68 ( V_116 ) ;
V_96 -- ;
} while ( ( V_89 == NULL ) && ( V_96 > 0 ) );
if ( ! V_96 )
F_63 ( L_1
L_3 ) ;
if ( V_89 )
F_69 ( V_89 ) ;
}
V_106:
F_36 ( F_53
( F_52 ( F_50 ) , F_51 ( F_50 ) ) ,
V_100 ) ;
F_36 ( F_54 ( F_51 ( F_50 ) ) ,
V_101 ) ;
F_36 ( F_55 ( F_51 ( F_50 ) ) ,
V_102 ) ;
F_36 ( F_56
( F_52 ( F_50 ) , F_51 ( F_50 ) ) ,
V_103 ) ;
F_36 ( F_57
( F_52 ( F_50 ) , F_51 ( F_50 ) ) ,
V_104 ) ;
F_36 ( F_60 ( F_51 ( F_50 ) ) , 0 ) ;
V_99 . V_17 = 0 ;
F_70 ( F_50 , V_99 ) ;
F_71 ( F_50 ) ;
V_107 ;
if ( V_91 )
F_63 ( L_4 ) ;
return ! ! V_91 ;
}
int F_72 ( void )
{
int V_82 ;
int V_3 ;
F_73 () ;
V_82 = F_1 () ;
for ( V_3 = 0 ; V_3 < V_82 ; V_3 ++ ) {
if ( F_3 ( V_3 ) > 0 )
F_39 ( V_3 ) ;
}
F_74 () ;
if ( ( F_2 ( V_117 )
|| F_2 ( V_118 ) )
&& ( F_5 () -> V_10 != V_119 ) )
F_47 () ;
return 0 ;
}
int F_75 ( void )
{
int V_83 = 0 ;
int V_3 ;
union V_120 V_121 ;
union V_122 V_123 ;
const int V_82 = F_1 () ;
if ( F_2 ( V_124 ) )
F_76 ( 1 ) ;
V_121 . V_17 = F_6 ( V_125 ) ;
V_121 . V_22 . V_126 = 0 ;
V_121 . V_22 . V_127 = 0 ;
F_36 ( V_125 , V_121 . V_17 ) ;
V_123 . V_17 = F_6 ( F_77 ( 0 ) ) ;
if ( ! V_123 . V_22 . V_23 ) {
V_123 . V_22 . V_23 = 1 ;
F_36 ( F_77 ( 0 ) , V_123 . V_17 ) ;
}
if ( ! F_2 ( V_128 ) &&
! F_2 ( V_25 ) &&
! F_2 ( V_16 ) ) {
V_123 . V_17 = F_6 ( F_77 ( 1 ) ) ;
if ( ! V_123 . V_22 . V_23 ) {
V_123 . V_22 . V_23 = 1 ;
F_36 ( F_77 ( 1 ) , V_123 . V_17 ) ;
}
}
F_78 () ;
for ( V_3 = 0 ; V_3 < V_82 ; V_3 ++ ) {
V_83 |= F_20 ( V_3 ) ;
if ( F_3 ( V_3 ) > 0 )
F_63 ( L_5 ,
V_3 ,
F_3 ( V_3 ) ,
F_79
( F_4
( V_3 ) ) ) ;
V_83 |= F_27 ( V_3 ) ;
V_83 |= F_31 ( V_3 ) ;
}
V_83 |= F_29 () ;
V_83 |= F_35 () ;
V_83 |= F_37 () ;
#if V_129
V_83 |= F_72 () ;
#endif
return V_83 ;
}
int F_80 ( void )
{
return F_81 () ;
}
T_6 F_71 ( int V_28 )
{
T_6 V_99 ;
int V_3 = F_82 ( V_28 ) ;
int V_130 = F_83 ( V_28 ) ;
if ( V_130 >= F_3 ( V_3 ) ) {
V_99 . V_17 = 0 ;
return V_99 ;
}
V_99 = F_84 ( V_28 ) ;
if ( V_99 . V_17 == V_131 [ V_28 ] . V_17 )
return V_99 ;
F_70 ( V_28 , V_99 ) ;
return V_131 [ V_28 ] ;
}
T_6 F_84 ( int V_28 )
{
T_6 V_83 ;
int V_3 = F_82 ( V_28 ) ;
int V_130 = F_83 ( V_28 ) ;
V_83 . V_17 = 0 ;
if ( V_130 >= F_3 ( V_3 ) )
return V_83 ;
switch ( F_4 ( V_3 ) ) {
case V_9 :
case V_65 :
break;
case V_19 :
V_83 = F_85 ( V_28 ) ;
break;
case V_13 :
if ( V_130 == 0 )
V_83 = F_86 ( V_28 ) ;
else {
V_83 . V_22 . V_132 = 1 ;
V_83 . V_22 . V_133 = 1 ;
V_83 . V_22 . V_134 = 1000 ;
}
break;
case V_27 :
V_83 = F_86 ( V_28 ) ;
break;
case V_26 :
V_83 = F_87 ( V_28 ) ;
break;
case V_20 :
case V_21 :
V_83 = F_88 ( V_28 ) ;
break;
case V_7 :
case V_8 :
break;
}
return V_83 ;
}
int F_70 ( int V_28 , T_6 V_99 )
{
int V_83 = - 1 ;
int V_3 = F_82 ( V_28 ) ;
int V_130 = F_83 ( V_28 ) ;
if ( V_130 >= F_3 ( V_3 ) )
return - 1 ;
switch ( F_4 ( V_3 ) ) {
case V_9 :
case V_65 :
break;
case V_19 :
V_83 = F_89 ( V_28 , V_99 ) ;
break;
case V_27 :
case V_13 :
V_83 = F_90 ( V_28 , V_99 ) ;
break;
case V_26 :
V_83 = F_91 ( V_28 , V_99 ) ;
break;
case V_20 :
case V_21 :
V_83 = F_92 ( V_28 , V_99 ) ;
break;
case V_7 :
case V_8 :
break;
}
if ( V_83 == 0 )
V_131 [ V_28 ] . V_17 = V_99 . V_17 ;
return V_83 ;
}
int F_93 ( int V_28 , int V_135 ,
int V_136 )
{
int V_83 = - 1 ;
int V_3 = F_82 ( V_28 ) ;
int V_130 = F_83 ( V_28 ) ;
if ( V_130 >= F_3 ( V_3 ) )
return - 1 ;
switch ( F_4 ( V_3 ) ) {
case V_9 :
case V_65 :
case V_26 :
case V_7 :
case V_8 :
break;
case V_19 :
V_83 =
F_94 ( V_28 ,
V_135 ,
V_136 ) ;
break;
case V_27 :
case V_13 :
V_83 =
F_95 ( V_28 ,
V_135 ,
V_136 ) ;
break;
case V_20 :
case V_21 :
V_83 =
F_96 ( V_28 ,
V_135 ,
V_136 ) ;
break;
}
return V_83 ;
}
