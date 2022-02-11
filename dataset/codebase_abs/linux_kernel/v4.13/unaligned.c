static int T_1 F_1 ( char * V_1 )
{
long V_2 ;
if ( F_2 ( V_1 , 0 , & V_2 ) != 0 )
return 0 ;
V_3 = V_2 ;
F_3 ( L_1 ,
V_3 ? L_2 : L_3 ) ;
return 1 ;
}
static bool F_4 ( T_2 V_4 )
{
return ( ( ( F_5 ( V_4 ) ==
V_5 ) &&
( F_6 ( V_4 ) ==
V_6 ) &&
( F_7 ( V_4 ) ==
V_7 ) ) ||
( ( F_5 ( V_4 ) ==
V_8 ) &&
( F_6 ( V_4 ) ==
V_6 ) &&
( F_7 ( V_4 ) ==
V_7 ) ) ) ;
}
static bool F_8 ( T_2 V_4 )
{
return ( ( ( F_9 ( V_4 ) ==
V_9 ) &&
( F_10 ( V_4 ) ==
V_10 ) &&
( F_11 ( V_4 ) ==
V_11 ) ) ||
( ( F_9 ( V_4 ) ==
V_12 ) &&
( F_10 ( V_4 ) ==
V_10 ) &&
( F_11 ( V_4 ) ==
V_11 ) ) ) ;
}
static bool F_12 ( T_2 V_4 )
{
return ( ( ( F_13 ( V_4 ) ==
V_13 ) &&
( F_14 ( V_4 ) ==
V_14 ) &&
( F_15 ( V_4 ) ==
V_15 ) ) ||
( ( F_13 ( V_4 ) ==
V_16 ) &&
( F_14 ( V_4 ) ==
V_14 ) &&
( F_15 ( V_4 ) ==
V_15 ) ) ) ;
}
static bool F_16 ( T_2 V_4 )
{
return ( ( ( F_17 ( V_4 ) ==
V_17 ) &&
( F_18 ( V_4 ) ==
V_18 ) &&
( F_19 ( V_4 ) ==
V_19 ) ) ||
( ( F_17 ( V_4 ) ==
V_20 ) &&
( F_18 ( V_4 ) ==
V_18 ) &&
( F_19 ( V_4 ) ==
V_19 ) ) ) ;
}
static bool F_20 ( T_2 V_4 )
{
return F_12 ( V_4 ) && F_16 ( V_4 ) ;
}
static bool F_21 ( T_2 V_4 )
{
return F_4 ( V_4 ) && F_8 ( V_4 ) ;
}
static void F_22 ( T_2 V_4 , T_3 * V_21 , T_3 * V_22 ,
T_3 * V_23 , T_3 * V_24 , T_3 * V_25 ,
T_3 * V_26 , bool * V_27 )
{
int V_28 ;
T_3 V_29 ;
T_3 V_30 = 0 , V_31 = 0 , V_32 ;
bool V_33 = false ;
if ( V_4 & V_34 ) {
V_29 = F_23 ( V_4 ) ;
V_30 |= 1ULL << V_29 ;
* V_22 = V_29 ;
V_29 = F_24 ( V_4 ) ;
V_30 |= 1ULL << V_29 ;
if ( V_21 ) {
* V_21 = V_29 ;
V_31 = ( 1ULL << * V_21 ) | ( 1ULL << * V_22 ) ;
} else {
* V_23 = V_29 ;
V_31 = ( 1ULL << * V_22 ) | ( 1ULL << * V_23 ) ;
}
if ( ! F_16 ( V_4 ) ) {
V_29 = F_25 ( V_4 ) ;
V_30 |= ( 1ULL << V_29 ) ;
V_32 = ( 1ULL << V_29 ) ;
V_29 = F_26 ( V_4 ) ;
V_30 |= ( 1ULL << V_29 ) ;
V_32 |= ( 1ULL << V_29 ) ;
V_29 = F_27 ( V_4 ) ;
V_30 |= ( 1ULL << V_29 ) ;
V_32 |= ( 1ULL << V_29 ) ;
if ( V_32 & V_31 )
V_33 = true ;
}
if ( ! F_12 ( V_4 ) ) {
V_29 = F_28 ( V_4 ) ;
V_30 |= ( 1ULL << V_29 ) ;
V_32 = ( 1ULL << V_29 ) ;
V_29 = F_29 ( V_4 ) ;
V_30 |= ( 1ULL << V_29 ) ;
V_32 |= ( 1ULL << V_29 ) ;
V_29 = F_30 ( V_4 ) ;
V_30 |= ( 1ULL << V_29 ) ;
V_32 |= ( 1ULL << V_29 ) ;
if ( V_32 & V_31 )
V_33 = true ;
}
} else {
V_29 = F_31 ( V_4 ) ;
V_30 |= ( 1ULL << V_29 ) ;
* V_22 = V_29 ;
if ( V_21 ) {
V_29 = F_32 ( V_4 ) ;
V_30 |= ( 1ULL << V_29 ) ;
* V_21 = V_29 ;
V_31 = ( 1ULL << * V_21 ) | ( 1ULL << * V_22 ) ;
} else {
V_29 = F_33 ( V_4 ) ;
V_30 |= ( 1ULL << V_29 ) ;
* V_23 = V_29 ;
V_31 = ( 1ULL << * V_22 ) | ( 1ULL << * V_23 ) ;
}
if ( ! F_4 ( V_4 ) ) {
V_29 = F_34 ( V_4 ) ;
V_30 |= ( 1ULL << V_29 ) ;
V_32 = ( 1ULL << V_29 ) ;
V_29 = F_35 ( V_4 ) ;
V_30 |= ( 1ULL << V_29 ) ;
V_32 |= ( 1ULL << V_29 ) ;
V_29 = F_36 ( V_4 ) ;
V_30 |= ( 1ULL << V_29 ) ;
V_32 |= ( 1ULL << V_29 ) ;
if ( V_32 & V_31 )
V_33 = true ;
}
}
* V_27 = V_33 ;
V_30 ^= - 1ULL ;
for ( V_28 = 0 ; V_28 < V_35 ; V_28 ++ ) {
if ( V_30 & ( 0x1ULL << V_28 ) ) {
if ( * V_24 == - 1 ) {
* V_24 = V_28 ;
} else if ( * V_25 == - 1 ) {
* V_25 = V_28 ;
} else if ( * V_26 == - 1 ) {
* V_26 = V_28 ;
return;
}
}
}
}
static bool F_37 ( T_3 V_21 , T_3 V_22 , T_3 V_23 ,
T_3 V_24 , T_3 V_25 , T_3 V_26 )
{
bool V_36 = false ;
if ( ( V_22 >= 56 ) && ( V_22 != V_37 ) )
V_36 = true ;
if ( ( V_24 >= 56 ) || ( V_25 >= 56 ) || ( V_26 >= 56 ) )
V_36 = true ;
if ( V_21 != - 1 ) {
if ( ( V_21 >= 56 ) && ( V_21 != V_37 ) )
V_36 = true ;
} else {
if ( ( V_23 >= 56 ) && ( V_23 != V_37 ) )
V_36 = true ;
}
return V_36 ;
}
static T_2 F_38 ( int V_38 , int V_29 )
{
extern T_2 V_39 ;
return ( F_39 ( V_39 ) & V_40 ) |
F_40 ( V_38 ) | F_41 ( V_29 ) ;
}
static T_2 F_42 ( int V_29 , int V_38 )
{
extern T_2 V_41 ;
return ( F_39 ( V_41 ) & V_40 ) |
F_43 ( V_38 ) | F_44 ( V_29 ) ;
}
static T_2 F_45 ( int V_21 , int V_22 , int V_42 )
{
extern T_2 V_43 ;
return ( F_39 ( V_43 ) & V_44 ) |
F_46 ( V_21 ) | F_47 ( V_22 ) |
F_48 ( V_42 ) ;
}
static T_2 F_49 ( int V_21 , int V_22 )
{
extern T_2 V_45 ;
return ( F_39 ( V_45 ) & V_40 ) |
F_44 ( V_21 ) | F_41 ( V_22 ) ;
}
static T_2 F_50 ( int V_21 , int V_22 , int V_23 )
{
extern T_2 V_46 ;
return ( F_39 ( V_46 ) & V_44 ) |
F_46 ( V_21 ) | F_47 ( V_22 ) |
F_51 ( V_23 ) ;
}
static T_2 F_52 ( void )
{
extern T_2 V_47 ;
return F_39 ( V_47 ) & V_40 ;
}
static T_2 F_53 ( void )
{
extern T_2 V_48 ;
return F_39 ( V_48 ) & V_44 ;
}
static T_2 F_54 ( void )
{
extern T_2 V_48 ;
return F_39 ( V_48 ) & V_40 ;
}
static T_2 F_55 ( void )
{
extern T_2 V_49 ;
return F_39 ( V_49 ) & V_50 ;
}
static T_2 F_56 ( void )
{
extern T_2 V_49 ;
return F_39 ( V_49 ) & V_51 ;
}
static T_2 F_57 ( int V_22 , int V_23 , int V_42 )
{
extern T_2 V_52 ;
return ( F_39 ( V_52 ) &
( ~ F_41 ( - 1 ) ) &
V_40 ) | F_41 ( V_22 ) |
F_58 ( V_23 ) | F_59 ( V_42 ) ;
}
static T_2 F_60 ( int V_22 , int V_23 )
{
extern T_2 V_53 ;
return ( F_39 ( V_53 ) & V_40 ) |
F_41 ( V_22 ) | F_58 ( V_23 ) ;
}
static T_2 F_61 ( int V_22 , int V_23 , int V_42 )
{
extern T_2 V_54 ;
return ( F_39 ( V_54 ) &
( ~ F_41 ( - 1 ) ) &
V_40 ) | F_41 ( V_22 ) |
F_58 ( V_23 ) | F_59 ( V_42 ) ;
}
static T_2 F_62 ( int V_21 , int V_22 )
{
extern T_2 V_55 ;
return ( F_39 ( V_55 ) & V_40 ) |
F_44 ( V_21 ) | F_41 ( V_22 ) ;
}
static T_2 F_63 ( int V_21 , int V_22 , int V_42 )
{
extern T_2 V_56 ;
return ( F_39 ( V_56 ) &
( ~ F_44 ( - 1 ) ) &
V_40 ) | F_44 ( V_21 ) |
F_41 ( V_22 ) | F_64 ( V_42 ) ;
}
static T_2 F_65 ( int V_21 , int V_22 , int V_57 , int V_58 )
{
extern T_2 V_59 ;
return ( F_39 ( V_59 ) &
V_44 ) |
F_46 ( V_21 ) | F_47 ( V_22 ) |
F_66 ( V_57 ) | F_67 ( V_58 ) ;
}
static T_2 F_68 ( int V_21 , int V_22 , int V_57 , int V_58 )
{
extern T_2 V_60 ;
return ( F_39 ( V_60 ) &
V_44 ) |
F_46 ( V_21 ) | F_47 ( V_22 ) |
F_66 ( V_57 ) | F_67 ( V_58 ) ;
}
static T_2 F_69 ( int V_21 , int V_22 , int V_42 )
{
extern T_2 V_61 ;
return ( F_39 ( V_61 ) & V_40 ) |
F_44 ( V_21 ) | F_41 ( V_22 ) |
F_64 ( V_42 ) ;
}
static T_2 F_70 ( int V_21 , int V_22 , int V_62 )
{
extern T_2 V_63 ;
return ( F_39 ( V_63 ) &
V_44 ) |
F_46 ( V_21 ) | F_47 ( V_22 ) |
F_71 ( V_62 ) ;
}
static T_2 F_72 ( int V_21 , int V_22 , int V_62 )
{
extern T_2 V_64 ;
return ( F_39 ( V_64 ) &
V_44 ) |
F_46 ( V_21 ) | F_47 ( V_22 ) |
F_71 ( V_62 ) ;
}
static T_2 F_73 ( int V_22 , int V_65 )
{
extern T_2 V_66 ;
return ( F_39 ( V_66 ) &
V_40 ) |
F_41 ( V_22 ) | F_74 ( V_65 ) ;
}
static
void F_75 ( struct V_67 * V_68 , T_2 V_4 ,
int V_69 )
{
struct V_70 * V_71 = F_76 () ;
struct V_72 V_73 ;
struct V_72 * V_74 ;
T_2 V_75 = 0 ;
bool V_76 = true ;
T_3 V_22 = - 1 , V_23 = - 1 , V_21 = - 1 , V_24 = - 1 , V_25 = - 1 , V_26 = - 1 ;
bool V_33 = false ;
bool V_77 = true ;
bool V_78 = false ;
unsigned int V_79 = 8 ;
bool V_80 = false ;
int V_81 = 0 ;
bool V_82 = false ;
int V_83 = 0 ;
bool V_84 = false ;
int V_85 = 0 ;
bool V_36 = false ;
int V_86 = 0 , V_87 ;
V_74 =
(struct V_72 * ) ( V_71 -> V_88 ) ;
memset ( ( void * ) & V_73 , 0 , sizeof( V_73 ) ) ;
if ( V_4 & V_34 ) {
unsigned int V_89 , V_90 ;
if ( F_19 ( V_4 ) == V_19 &&
F_18 ( V_4 ) ==
V_18 ) {
V_90 = F_17 ( V_4 ) ;
switch ( V_90 ) {
case V_91 :
case V_92 :
V_82 = true ;
V_83 = 55 ;
case V_93 :
case V_94 :
V_80 = true ;
V_81 = F_25 ( V_4 ) ;
break;
case V_95 :
V_82 = true ;
V_83 = F_27 ( V_4 ) ;
break;
}
}
V_90 = F_77 ( V_4 ) ;
V_89 = F_78 ( V_4 ) ;
V_75 = ( V_4 & ( ~ V_50 ) ) | F_55 () ;
if ( V_80 || V_82 ) {
V_75 &= ~ ( V_51 ) ;
V_75 |= F_56 () ;
}
if ( F_20 ( V_75 ) )
V_76 = false ;
if ( V_89 == V_96 ) {
V_77 = false ;
V_79 = 1 << V_90 ;
V_78 = false ;
F_22 ( V_4 , 0 , & V_22 , & V_23 , & V_24 , & V_25 ,
& V_26 , & V_33 ) ;
if ( V_79 > 8 )
V_36 = true ;
} else {
V_77 = true ;
if ( V_89 == V_97 ) {
switch ( V_90 ) {
case V_98 :
V_78 = false ;
V_79 = 8 ;
break;
case V_99 :
V_78 = true ;
V_79 = 4 ;
break;
case V_100 :
V_78 = false ;
V_79 = 4 ;
break;
default:
V_36 = true ;
}
} else if ( V_89 == V_101 ) {
if ( V_90 == V_102 ) {
V_78 = true ;
V_79 = 2 ;
} else if ( V_90 == V_103 ) {
V_78 = false ;
V_79 = 2 ;
} else
V_36 = true ;
} else
V_36 = true ;
F_22 ( V_4 , & V_21 , & V_22 , & V_23 , & V_24 , & V_25 ,
& V_26 , & V_33 ) ;
}
} else {
unsigned int V_90 ;
V_75 = ( V_4 & ( ~ V_40 ) ) | F_54 () ;
if ( F_21 ( V_75 ) )
V_76 = false ;
if ( F_11 ( V_4 ) == V_11 ) {
V_90 = F_9 ( V_4 ) ;
if ( F_10 ( V_4 ) ==
V_10 ) {
V_77 = true ;
F_22 ( V_4 , & V_21 , & V_22 , & V_23 , & V_24 ,
& V_25 , & V_26 , & V_33 ) ;
switch ( V_90 ) {
case V_104 :
V_78 = false ;
V_79 = 8 ;
break;
case V_105 :
V_78 = true ;
case V_106 :
V_79 = 4 ;
break;
case V_107 :
V_78 = true ;
case V_108 :
V_79 = 2 ;
break;
default:
V_36 = true ;
}
} else {
V_77 = false ;
V_78 = false ;
F_22 ( V_4 , 0 , & V_22 , & V_23 ,
& V_24 , & V_25 , & V_26 ,
& V_33 ) ;
V_90 = F_10 ( V_4 ) ;
switch ( V_90 ) {
case V_109 :
V_79 = 8 ;
break;
case V_110 :
V_79 = 4 ;
break;
case V_111 :
V_79 = 2 ;
break;
default:
V_36 = true ;
}
}
} else if ( F_11 ( V_4 ) == V_112 ) {
V_77 = true ;
V_90 = F_79 ( V_4 ) ;
switch ( V_90 ) {
case V_113 :
V_79 = 8 ;
break;
case V_114 :
V_78 = true ;
case V_115 :
V_79 = 4 ;
break;
case V_116 :
V_78 = true ;
case V_117 :
V_79 = 2 ;
break;
case V_118 :
V_77 = false ;
V_79 = 8 ;
break;
case V_119 :
V_77 = false ;
V_79 = 4 ;
break;
case V_120 :
V_77 = false ;
V_79 = 2 ;
break;
default:
V_36 = true ;
}
if ( ! V_36 ) {
V_84 = true ;
if ( V_77 )
V_85 = F_80 ( V_4 ) ;
else
V_85 = F_81 ( V_4 ) ;
}
F_22 ( V_4 , V_77 ? ( & V_21 ) : NULL ,
& V_22 , & V_23 , & V_24 , & V_25 , & V_26 , & V_33 ) ;
} else
V_36 = true ;
}
if ( F_37 ( V_21 , V_22 , V_23 , V_24 , V_25 , V_26 ) == true )
V_36 = true ;
if ( ! V_36 )
F_82 ( ! ( ( V_79 - 1 ) & ( V_68 -> V_68 [ V_22 ] ) ) ) ;
if ( F_83 ( V_68 -> V_121 ) != V_122 ) {
unsigned long V_123 = 0 ;
unsigned long V_124 = 0 , V_125 = 0 ;
if ( V_80 || V_82 || V_84 ||
( V_78 !=
( V_77 && V_79 == 4 ) ) ) {
V_36 = true ;
} else if ( ! V_36 ) {
if ( V_4 & V_34 ) {
if ( ( F_19 ( V_4 ) == V_126 )
&& ( F_25 ( V_4 ) == V_37 ) &&
( F_84 ( V_4 ) == 0 ) &&
F_12 ( V_4 ) ) {
V_123 = F_27 ( V_4 ) ;
} else if ( ( F_15 ( V_4 ) ==
V_127 ) &&
( F_28 ( V_4 ) == V_37 ) &&
( F_85 ( V_4 ) == 0 ) &&
F_16 ( V_4 ) ) {
V_123 = F_30 ( V_4 ) ;
} else {
V_36 = true ;
}
} else {
if ( ( F_7 ( V_4 ) == V_128 )
&& ( F_86 ( V_4 ) ==
V_129 ) &&
( F_34 ( V_4 ) == V_37 ) &&
( F_87 ( V_4 ) == 0 ) ) {
V_123 = F_36 ( V_4 ) ;
} else {
V_36 = true ;
}
}
if ( ! V_36 && ( V_123 >= 56 ) )
V_36 = true ;
}
if ( ! F_88 ( V_68 -> V_130 ) ) {
V_36 = true ;
}
if ( V_36 ) {
struct V_131 * V_132 = F_89 () ;
F_90 ( 1 ) ;
F_91 ( V_68 ) ;
if ( F_92 ( V_132 -> V_133 < 2 ) ) {
F_93 ( L_4 ,
V_132 -> V_133 ? L_5 : L_6 ) ;
}
#ifdef F_94
F_95 ( L_7 , V_68 ) ;
#endif
F_90 ( 1 ) ;
F_96 ( V_134 ) ;
} else {
unsigned long V_28 , V_135 = 0 ;
unsigned char * V_136 =
( unsigned char * ) V_68 -> V_68 [ V_22 ] ;
if ( V_77 ) {
for ( V_28 = 0 ; V_28 < V_79 ; V_28 ++ ) {
V_125 = F_97 ( V_135 , V_136 ++ ) ;
if ( ! V_125 ) {
#ifdef F_98
V_124 |= ( V_135 << ( 8 * V_28 ) ) ;
#else
V_124 <<= 8 ;
V_124 |= V_135 ;
#endif
} else {
V_124 = 0 ;
break;
}
}
if ( V_79 == 4 )
V_124 = ( long ) ( int ) V_124 ;
V_68 -> V_68 [ V_21 ] = V_124 ;
V_68 -> V_68 [ V_123 ] = V_125 ;
V_68 -> V_130 += 8 ;
} else {
V_124 = V_68 -> V_68 [ V_23 ] ;
#ifdef F_98
V_135 = V_124 ;
#else
switch ( V_79 ) {
case 8 :
V_135 = F_99 ( V_124 ) ;
break;
case 4 :
V_135 = F_100 ( V_124 ) ;
break;
case 2 :
V_135 = F_101 ( V_124 ) ;
break;
}
#endif
for ( V_28 = 0 ; V_28 < V_79 ; V_28 ++ ) {
V_125 = F_102 ( V_135 , V_136 ++ ) ;
if ( V_125 )
break;
V_135 >>= 8 ;
}
V_68 -> V_68 [ V_123 ] = V_125 ;
V_68 -> V_130 += 8 ;
}
}
V_137 ++ ;
if ( V_3 ) {
F_3 ( L_8 ,
V_138 -> V_139 , V_138 -> V_133 , V_68 -> V_68 [ V_22 ] ) ;
}
return;
}
if ( ( V_69 == 0 ) || V_36 ) {
T_4 V_71 = {
. V_140 = V_141 ,
. V_142 = V_143 ,
. V_144 = ( unsigned char V_145 * ) 0
} ;
if ( V_3 )
F_3 ( L_9 ,
( unsigned long long ) V_68 -> V_130 ,
( unsigned long long ) V_4 ) ;
if ( V_22 < 56 ) {
unsigned long V_146 = ( unsigned long ) V_68 -> V_68 [ V_22 ] ;
V_71 . V_144 = ( unsigned char V_145 * ) V_146 ;
}
V_137 ++ ;
F_103 ( L_10 , V_68 ,
( unsigned long ) V_71 . V_144 , V_141 ) ;
F_104 ( V_71 . V_140 , & V_71 , V_138 ) ;
return;
}
#ifdef F_98
#define F_105 1
#define F_106 ( T_5 ) 0
#define F_107 ( T_5 ) (8 * (_B_) - 1)
#else
#define F_105 -1
#define F_106 ( T_5 ) (64 - 8 * (_B_))
#define F_107 ( T_5 ) 63
#endif
if ( ( V_22 != V_23 ) && ( V_21 != V_35 ) && ! V_33 &&
! V_80 && ! V_82 && ! V_84 ) {
if ( ! V_77 ) {
#ifdef F_108
V_73 . V_147 [ V_86 ++ ] =
F_45 ( V_22 , V_22 , V_79 - 1 ) |
F_54 () ;
#endif
for ( V_87 = 0 ; V_87 < V_79 ; V_87 ++ ) {
V_73 . V_147 [ V_86 ++ ] =
F_72 ( V_23 , V_23 , 56 ) |
F_57 ( V_22 , V_23 ,
F_105 ) ;
}
#ifdef F_108
V_73 . V_147 [ V_86 ] = F_69 ( V_22 , V_22 , 1 ) ;
#else
V_73 . V_147 [ V_86 ] = F_69 ( V_22 , V_22 ,
- 1 * V_79 ) ;
#endif
if ( V_79 == 8 ) {
V_73 . V_147 [ V_86 ] |= F_53 () ;
} else if ( V_79 == 4 ) {
V_73 . V_147 [ V_86 ] |= F_72 ( V_23 , V_23 , 32 ) ;
} else {
V_73 . V_147 [ V_86 ] |= F_72 ( V_23 , V_23 , 16 ) ;
}
V_86 ++ ;
if ( V_76 )
V_73 . V_147 [ V_86 ++ ] = V_75 ;
V_73 . V_147 [ V_86 ++ ] = F_53 () | F_52 () ;
} else {
if ( V_21 == V_22 ) {
V_73 . V_147 [ V_86 ++ ] =
F_45 ( V_35 , V_35 , - 16 ) |
F_54 () ;
V_73 . V_147 [ V_86 ++ ] =
F_45 ( V_24 , V_22 , 7 ) |
F_61 ( V_35 , V_24 , - 8 ) ;
V_73 . V_147 [ V_86 ++ ] =
F_45 ( V_25 , V_22 , 0 ) |
F_60 ( V_35 , V_25 ) ;
V_73 . V_147 [ V_86 ++ ] =
F_53 () |
F_49 ( V_21 , V_22 ) ;
V_73 . V_147 [ V_86 ++ ] =
F_53 () |
F_49 ( V_24 , V_24 ) ;
V_73 . V_147 [ V_86 ++ ] =
F_50 ( V_21 , V_24 , V_25 ) |
F_63 ( V_25 , V_35 , 8 ) ;
V_73 . V_147 [ V_86 ++ ] =
F_53 () |
F_63 ( V_24 , V_35 , 16 ) ;
} else {
V_73 . V_147 [ V_86 ++ ] =
F_45 ( V_35 , V_35 , - 16 ) |
F_54 () ;
V_73 . V_147 [ V_86 ++ ] =
F_45 ( V_24 , V_22 , 7 ) |
F_60 ( V_35 , V_24 ) ;
V_73 . V_147 [ V_86 ++ ] =
F_53 () |
F_49 ( V_21 , V_22 ) ;
V_73 . V_147 [ V_86 ++ ] =
F_53 () |
F_49 ( V_24 , V_24 ) ;
V_73 . V_147 [ V_86 ++ ] =
F_50 ( V_21 , V_24 , V_22 ) |
F_63 ( V_24 , V_35 , 16 ) ;
}
if ( V_76 )
V_73 . V_147 [ V_86 ++ ] = V_75 ;
if ( V_79 == 4 ) {
if ( V_78 )
V_73 . V_147 [ V_86 ++ ] =
F_65 (
V_21 , V_21 ,
F_106 ( 4 ) ,
F_107 ( 4 ) ) |
F_54 () ;
else
V_73 . V_147 [ V_86 ++ ] =
F_68 (
V_21 , V_21 ,
F_106 ( 4 ) ,
F_107 ( 4 ) ) |
F_54 () ;
} else if ( V_79 == 2 ) {
if ( V_78 )
V_73 . V_147 [ V_86 ++ ] =
F_65 (
V_21 , V_21 ,
F_106 ( 2 ) ,
F_107 ( 2 ) ) |
F_54 () ;
else
V_73 . V_147 [ V_86 ++ ] =
F_68 (
V_21 , V_21 ,
F_106 ( 2 ) ,
F_107 ( 2 ) ) |
F_54 () ;
}
V_73 . V_147 [ V_86 ++ ] =
F_53 () |
F_52 () ;
}
} else if ( ! V_77 ) {
V_73 . V_147 [ V_86 ++ ] =
F_45 ( V_35 , V_35 , - 32 ) |
F_54 () ;
V_73 . V_147 [ V_86 ++ ] =
F_45 ( V_26 , V_35 , 16 ) |
F_61 ( V_35 , V_26 , 8 ) ;
#ifdef F_98
V_73 . V_147 [ V_86 ++ ] =
F_45 ( V_24 , V_22 , 0 ) |
F_61 ( V_35 , V_24 , 8 ) ;
#else
V_73 . V_147 [ V_86 ++ ] =
F_45 ( V_24 , V_22 , V_79 - 1 ) |
F_61 ( V_35 , V_24 , 8 ) ;
#endif
if ( V_79 == 8 ) {
V_73 . V_147 [ V_86 ++ ] =
F_45 ( V_25 , V_37 , 7 ) |
F_61 ( V_35 , V_25 , 16 ) ;
V_73 . V_147 [ V_86 ++ ] =
F_72 ( V_23 , V_23 , 56 ) |
F_57 ( V_24 , V_23 , F_105 ) ;
V_73 . V_147 [ V_86 ++ ] =
F_45 ( V_25 , V_25 , - 1 ) |
F_73 ( V_25 , - 1 ) ;
V_73 . V_147 [ V_86 ++ ] =
F_53 () |
F_69 ( V_25 , V_81 , 0 ) ;
} else if ( V_79 == 4 ) {
V_73 . V_147 [ V_86 ++ ] =
F_45 ( V_25 , V_37 , 3 ) |
F_61 ( V_35 , V_25 , 16 ) ;
V_73 . V_147 [ V_86 ++ ] =
F_72 ( V_23 , V_23 , 56 ) |
F_57 ( V_24 , V_23 , F_105 ) ;
V_73 . V_147 [ V_86 ++ ] =
F_45 ( V_25 , V_25 , - 1 ) |
F_73 ( V_25 , - 1 ) ;
V_73 . V_147 [ V_86 ++ ] = F_72 ( V_23 , V_23 , 32 ) |
F_69 ( V_25 , V_81 , 0 ) ;
} else {
V_73 . V_147 [ V_86 ++ ] =
F_45 ( V_25 , V_23 , 0 ) |
F_61 ( V_35 , V_25 , 16 ) ;
for ( V_87 = 0 ; V_87 < 2 ; V_87 ++ ) {
V_73 . V_147 [ V_86 ++ ] =
F_70 ( V_23 , V_23 , 8 ) |
F_57 ( V_24 , V_23 ,
F_105 ) ;
}
V_73 . V_147 [ V_86 ++ ] =
F_45 ( V_23 , V_25 , 0 ) |
F_69 ( V_25 , V_81 , 0 ) ;
}
if ( V_76 )
V_73 . V_147 [ V_86 ++ ] = V_75 ;
if ( V_82 ) {
V_73 . V_147 [ V_86 ++ ] =
F_53 () |
F_42 ( V_83 ,
V_148 ) ;
}
if ( V_80 ) {
V_73 . V_147 [ V_86 ++ ] =
F_53 () |
F_38 ( V_148 ,
V_25 ) ;
}
if ( V_84 ) {
V_73 . V_147 [ V_86 ++ ] =
F_45 ( V_22 , V_22 , V_85 ) |
F_63 ( V_25 , V_26 , - 8 ) ;
} else {
V_73 . V_147 [ V_86 ++ ] =
F_53 () |
F_63 ( V_25 , V_26 , - 8 ) ;
}
V_73 . V_147 [ V_86 ++ ] =
F_53 () |
F_63 ( V_24 , V_26 , - 8 ) ;
V_73 . V_147 [ V_86 ++ ] = F_53 () | F_62 ( V_26 , V_26 ) ;
V_73 . V_147 [ V_86 ++ ] = F_53 () | F_52 () ;
} else {
V_73 . V_147 [ V_86 ++ ] =
F_45 ( V_35 , V_35 , - 32 ) |
F_54 () ;
V_73 . V_147 [ V_86 ++ ] =
F_45 ( V_26 , V_35 , 16 ) |
F_61 ( V_35 , V_26 , 8 ) ;
V_73 . V_147 [ V_86 ++ ] =
F_45 ( V_25 , V_22 , 0 ) |
F_61 ( V_35 , V_25 , 8 ) ;
if ( V_80 ) {
V_73 . V_147 [ V_86 ++ ] =
F_45 ( V_24 , V_81 , 0 ) |
F_61 ( V_35 , V_24 , 16 ) ;
} else {
V_73 . V_147 [ V_86 ++ ] =
F_53 () |
F_61 ( V_35 , V_24 , 16 ) ;
}
if ( V_76 )
V_73 . V_147 [ V_86 ++ ] = V_75 ;
if ( V_82 ) {
V_73 . V_147 [ V_86 ++ ] =
F_53 () |
F_42 ( V_83 ,
V_148 ) ;
}
if ( V_80 ) {
V_73 . V_147 [ V_86 ++ ] =
F_53 () |
F_38 ( V_148 ,
V_24 ) ;
}
V_73 . V_147 [ V_86 ++ ] =
F_45 ( V_24 , V_25 , 7 ) |
F_49 ( V_21 , V_25 ) ;
V_73 . V_147 [ V_86 ++ ] =
F_53 () |
F_49 ( V_24 , V_24 ) ;
V_73 . V_147 [ V_86 ++ ] =
F_50 ( V_21 , V_24 , V_25 ) |
F_63 ( V_24 , V_26 , - 8 ) ;
if ( V_84 ) {
V_73 . V_147 [ V_86 ++ ] =
F_45 ( V_22 , V_22 , V_85 ) |
F_63 ( V_25 , V_26 , - 8 ) ;
} else {
V_73 . V_147 [ V_86 ++ ] =
F_53 () |
F_63 ( V_25 , V_26 , - 8 ) ;
}
V_73 . V_147 [ V_86 ++ ] =
F_53 () |
F_62 ( V_26 , V_26 ) ;
if ( V_79 == 4 ) {
if ( V_78 )
V_73 . V_147 [ V_86 ++ ] =
F_65 (
V_21 , V_21 ,
F_106 ( 4 ) ,
F_107 ( 4 ) ) |
F_54 () ;
else
V_73 . V_147 [ V_86 ++ ] =
F_68 (
V_21 , V_21 ,
F_106 ( 4 ) ,
F_107 ( 4 ) ) |
F_54 () ;
} else if ( V_79 == 2 ) {
if ( V_78 )
V_73 . V_147 [ V_86 ++ ] =
F_65 (
V_21 , V_21 ,
F_106 ( 2 ) ,
F_107 ( 2 ) ) |
F_54 () ;
else
V_73 . V_147 [ V_86 ++ ] =
F_68 (
V_21 , V_21 ,
F_106 ( 2 ) ,
F_107 ( 2 ) ) |
F_54 () ;
}
V_73 . V_147 [ V_86 ++ ] = F_53 () | F_52 () ;
}
F_82 ( V_86 > 14 ) ;
if ( ! V_36 ) {
int V_149 = 0 ;
int V_150 = ( V_68 -> V_130 >> 3 ) &
( ( 1ULL << ( V_151 - V_152 ) ) - 1 ) ;
V_73 . V_130 = V_68 -> V_130 ;
V_73 . V_4 = V_4 ;
if ( V_3 ) {
F_3 ( L_11 ,
V_138 -> V_139 , V_138 -> V_133 ,
( unsigned long ) V_73 . V_130 ,
( unsigned long ) V_73 . V_4 ,
( int ) V_33 , ( int ) V_21 , ( int ) V_22 ,
( int ) V_23 , ( int ) V_76 ,
( int ) V_82 , ( int ) V_80 , ( int ) V_84 ) ;
for ( V_87 = 0 ; V_87 < V_86 ; V_87 += 2 )
F_3 ( L_12 ,
V_87 , ( unsigned long long ) V_73 . V_147 [ V_87 ] ,
( unsigned long long ) V_73 . V_147 [ V_87 + 1 ] ) ;
}
#ifdef F_108
V_73 . V_4 = F_39 ( V_73 . V_4 ) ;
for ( V_87 = 0 ; V_87 < V_86 ; V_87 ++ )
V_73 . V_147 [ V_87 ] = F_39 ( V_73 . V_147 [ V_87 ] ) ;
#endif
V_149 = F_109 ( ( void V_145 * ) & V_74 [ V_150 ] ,
& V_73 , sizeof( V_73 ) ) ;
if ( V_149 ) {
T_4 V_71 = {
. V_140 = V_153 ,
. V_142 = V_154 ,
. V_144 = ( void V_145 * ) & V_74 [ V_150 ]
} ;
F_110 ( L_13 ,
V_138 -> V_133 , V_138 -> V_139 ,
( unsigned long long ) & V_74 [ V_150 ] ) ;
F_103 ( L_14 ,
V_68 ,
( unsigned long ) V_71 . V_144 ,
V_153 ) ;
F_104 ( V_71 . V_140 , & V_71 , V_138 ) ;
return;
}
V_137 ++ ;
F_111 ( ( unsigned long ) & V_74 [ V_150 ] ,
( unsigned long ) & V_74 [ V_150 ] +
sizeof( V_73 ) ) ;
F_112 ( V_148 , V_68 -> V_130 + 8 ) ;
F_112 ( V_155 , F_113 ( V_122 , 0 ) ) ;
V_68 -> V_130 = ( unsigned long ) & V_74 [ V_150 ] . V_147 [ 0 ] ;
V_68 -> V_121 = F_113 ( V_122 , 1 ) ;
}
}
void F_114 ( struct V_67 * V_68 , int V_156 )
{
T_2 V_145 * V_130 ;
T_2 V_4 ;
struct V_70 * V_71 = F_76 () ;
int V_69 ;
V_69 = V_157 ;
switch ( F_115 ( V_138 ) -> V_69 ) {
case V_158 :
V_69 = 1 ;
break;
case V_159 :
V_69 = 0 ;
break;
}
F_116 () ;
if ( F_83 ( V_68 -> V_121 ) != V_122 ) {
if ( V_69 < 1 ) {
V_137 ++ ;
if ( F_117 ( V_68 ) ) {
if ( V_3 )
F_3 ( L_15 ,
( int ) V_157 ,
( unsigned long long ) V_68 -> V_121 ,
( unsigned long long ) V_68 -> V_130 ) ;
} else {
F_93 ( L_16 ,
V_68 -> V_130 ) ;
}
} else {
V_4 = F_39 (
* ( ( T_2 * ) ( V_68 -> V_130 ) ) ) ;
F_75 ( V_68 , V_4 , V_69 ) ;
}
return;
}
if ( ( V_68 -> V_160 & 0x7 ) || ( V_68 -> V_121 ) || ( V_69 < 0 ) ) {
T_4 V_71 = {
. V_140 = V_141 ,
. V_142 = V_143 ,
. V_144 = ( unsigned char V_145 * ) 0
} ;
if ( V_3 )
F_3 ( L_15 ,
( int ) V_157 ,
( unsigned long long ) V_68 -> V_121 ,
( unsigned long long ) V_68 -> V_130 ) ;
V_137 ++ ;
F_103 ( L_10 , V_68 , 0 , V_141 ) ;
F_104 ( V_71 . V_140 , & V_71 , V_138 ) ;
return;
}
V_130 = ( T_2 V_145 * ) ( V_68 -> V_130 ) ;
if ( F_97 ( V_4 , V_130 ) != 0 ) {
T_4 V_71 = {
. V_140 = V_153 ,
. V_142 = V_154 ,
. V_144 = ( void V_145 * ) V_130
} ;
F_118 ( L_17 , V_130 ) ;
F_103 ( L_14 , V_68 ,
( unsigned long ) V_71 . V_144 , V_153 ) ;
F_104 ( V_71 . V_140 , & V_71 , V_138 ) ;
return;
}
if ( ! V_71 -> V_88 ) {
void V_145 * V_161 ;
if ( F_119 () )
V_161 = NULL ;
else
V_161 = ( void V_145 * ) ( V_162 - ( 1UL << 36 ) ) +
( V_138 -> V_133 << V_151 ) ;
V_161 = ( void V_145 * ) F_120 ( NULL ,
( unsigned long ) V_161 ,
V_163 ,
V_164 | V_165 |
V_166 ,
#ifdef F_121
V_167 |
#endif
V_168 |
V_169 ,
0 ) ;
if ( F_122 ( ( void V_170 * ) V_161 ) ) {
F_118 ( L_18 ) ;
return;
}
V_71 -> V_88 = V_161 ;
if ( V_3 )
F_3 ( L_19 ,
F_123 () , V_138 -> V_133 ,
( unsigned long long ) V_161 ) ;
}
F_75 ( V_68 , F_39 ( V_4 ) , V_69 ) ;
}
