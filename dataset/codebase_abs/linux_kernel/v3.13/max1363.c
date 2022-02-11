static const struct V_1
* F_1 ( const unsigned long * V_2 ,
const struct V_3 * V_4 )
{
int V_5 ;
if ( V_2 )
for ( V_5 = 0 ; V_5 < V_4 -> V_6 ; V_5 ++ )
if ( F_2 ( V_2 ,
V_7 [ V_4 -> V_8 [ V_5 ] ] .
V_9 ,
V_10 ) )
return & V_7 [ V_4 -> V_8 [ V_5 ] ] ;
return NULL ;
}
static int F_3 ( const struct V_11 * V_12 , const char * V_13 ,
int V_14 )
{
int V_5 , V_15 ;
for ( V_5 = V_15 = 0 ; V_15 == 0 && V_5 < V_14 ; ++ V_5 )
V_15 = F_4 ( V_12 , V_13 [ V_5 ] ) ;
return V_15 ? V_15 : V_14 ;
}
static int F_5 ( const struct V_11 * V_12 , char * V_13 ,
int V_14 )
{
int V_5 , V_16 ;
for ( V_5 = 0 ; V_5 < V_14 ; ++ V_5 ) {
V_16 = F_6 ( V_12 ) ;
if ( V_16 < 0 )
return V_16 ;
V_13 [ V_5 ] = V_16 ;
}
return V_14 ;
}
static int F_7 ( struct V_17 * V_18 )
{
T_1 V_19 [ 2 ] = { V_18 -> V_20 , V_18 -> V_21 } ;
return V_18 -> V_22 ( V_18 -> V_12 , V_19 , 2 ) ;
}
static int F_8 ( struct V_17 * V_18 )
{
V_18 -> V_21 &= ~ ( V_23
| V_24
| V_25 ) ;
V_18 -> V_21 |= V_18 -> V_26 -> V_27 ;
return F_7 ( V_18 ) ;
}
static int F_9 ( struct V_28 * V_29 ,
struct V_30 const * V_31 ,
int * V_32 ,
long V_33 )
{
int V_16 = 0 ;
T_2 V_34 ;
T_1 V_35 [ 2 ] ;
struct V_17 * V_18 = F_10 ( V_29 ) ;
struct V_11 * V_12 = V_18 -> V_12 ;
F_11 ( & V_29 -> V_36 ) ;
if ( V_18 -> V_37 || F_12 ( V_29 ) ) {
V_16 = - V_38 ;
goto V_39;
}
if ( V_18 -> V_26 != & V_7 [ V_31 -> V_40 ] ) {
V_18 -> V_26 = & V_7 [ V_31 -> V_40 ] ;
V_16 = F_8 ( V_18 ) ;
if ( V_16 < 0 )
goto V_39;
}
if ( V_18 -> V_41 -> V_42 != 8 ) {
V_34 = V_18 -> V_43 ( V_12 , V_35 , 2 ) ;
if ( V_34 < 0 ) {
V_16 = V_34 ;
goto V_39;
}
V_34 = ( V_35 [ 1 ] | V_35 [ 0 ] << 8 ) &
( ( 1 << V_18 -> V_41 -> V_42 ) - 1 ) ;
} else {
V_34 = V_18 -> V_43 ( V_12 , V_35 , 1 ) ;
if ( V_34 < 0 ) {
V_16 = V_34 ;
goto V_39;
}
V_34 = V_35 [ 0 ] ;
}
* V_32 = V_34 ;
V_39:
F_13 ( & V_29 -> V_36 ) ;
return V_16 ;
}
static int F_14 ( struct V_28 * V_29 ,
struct V_30 const * V_31 ,
int * V_32 ,
int * V_44 ,
long V_33 )
{
struct V_17 * V_18 = F_10 ( V_29 ) ;
int V_16 ;
switch ( V_33 ) {
case V_45 :
V_16 = F_9 ( V_29 , V_31 , V_32 , V_33 ) ;
if ( V_16 < 0 )
return V_16 ;
return V_46 ;
case V_47 :
* V_32 = V_18 -> V_48 / 1000 ;
* V_44 = V_18 -> V_41 -> V_42 ;
return V_49 ;
default:
return - V_50 ;
}
return 0 ;
}
static T_3 F_15 ( struct V_51 * V_52 ,
struct V_53 * V_54 ,
char * V_13 )
{
struct V_17 * V_18 = F_10 ( F_16 ( V_52 ) ) ;
return sprintf ( V_13 , L_1 , V_55 [ V_18 -> V_56 ] ) ;
}
static T_3 F_17 ( struct V_51 * V_52 ,
struct V_53 * V_54 ,
const char * V_13 ,
T_4 V_57 )
{
struct V_28 * V_29 = F_16 ( V_52 ) ;
struct V_17 * V_18 = F_10 ( V_29 ) ;
int V_5 , V_16 ;
unsigned long V_32 ;
bool V_58 = false ;
V_16 = F_18 ( V_13 , 10 , & V_32 ) ;
if ( V_16 )
return - V_50 ;
for ( V_5 = 0 ; V_5 < F_19 ( V_55 ) ; V_5 ++ )
if ( V_32 == V_55 [ V_5 ] ) {
V_58 = true ;
break;
}
if ( ! V_58 )
return - V_50 ;
F_11 ( & V_29 -> V_36 ) ;
V_18 -> V_56 = V_5 ;
F_13 ( & V_29 -> V_36 ) ;
return 0 ;
}
static int F_20 ( struct V_28 * V_29 ,
const struct V_30 * V_31 , enum V_59 type ,
enum V_60 V_61 , enum V_62 V_63 , int * V_32 ,
int * V_44 )
{
struct V_17 * V_18 = F_10 ( V_29 ) ;
if ( V_61 == V_64 )
* V_32 = V_18 -> V_65 [ V_31 -> V_66 ] ;
else
* V_32 = V_18 -> V_67 [ V_31 -> V_66 ] ;
return V_46 ;
}
static int F_21 ( struct V_28 * V_29 ,
const struct V_30 * V_31 , enum V_59 type ,
enum V_60 V_61 , enum V_62 V_63 , int V_32 ,
int V_44 )
{
struct V_17 * V_18 = F_10 ( V_29 ) ;
switch ( V_18 -> V_41 -> V_42 ) {
case 10 :
if ( V_32 > 0x3FF )
return - V_50 ;
break;
case 12 :
if ( V_32 > 0xFFF )
return - V_50 ;
break;
}
switch ( V_61 ) {
case V_64 :
V_18 -> V_65 [ V_31 -> V_66 ] = V_32 ;
break;
case V_68 :
V_18 -> V_67 [ V_31 -> V_66 ] = V_32 ;
break;
default:
return - V_50 ;
}
return 0 ;
}
static T_5 F_22 ( int V_69 , void * V_70 )
{
struct V_28 * V_29 = V_70 ;
struct V_17 * V_18 = F_10 ( V_29 ) ;
T_6 V_71 = F_23 () ;
unsigned long V_2 , V_72 ;
T_1 V_73 ;
T_1 V_74 [ 2 ] = { V_18 -> V_20 ,
V_75 | ( V_18 -> V_56 << 1 ) | 0xF0 } ;
V_18 -> V_43 ( V_18 -> V_12 , & V_73 , 1 ) ;
V_2 = V_73 ;
F_24 (loc, &mask, 8 )
F_25 ( V_29 , V_76 [ V_72 ] , V_71 ) ;
V_18 -> V_22 ( V_18 -> V_12 , V_74 , 2 ) ;
return V_77 ;
}
static int F_26 ( struct V_28 * V_29 ,
const struct V_30 * V_31 , enum V_59 type ,
enum V_60 V_61 )
{
struct V_17 * V_18 = F_10 ( V_29 ) ;
int V_32 ;
int V_78 = V_31 -> V_66 ;
F_11 ( & V_29 -> V_36 ) ;
if ( V_61 == V_64 )
V_32 = ( 1 << V_78 ) & V_18 -> V_79 ;
else
V_32 = ( 1 << V_78 ) & V_18 -> V_80 ;
F_13 ( & V_29 -> V_36 ) ;
return V_32 ;
}
static int F_27 ( struct V_17 * V_18 , int V_81 )
{
T_1 * V_19 ;
int V_16 , V_5 = 3 , V_82 ;
unsigned long V_83 ;
int V_57 ;
const long * V_9 ;
if ( ! V_81 ) {
V_18 -> V_20 &= ~ V_84 ;
V_18 -> V_21 &= ~ V_24 ;
V_18 -> V_37 = false ;
return F_7 ( V_18 ) ;
}
V_18 -> V_20 |= V_84 ;
V_18 -> V_21 &= ~ ( V_23
| V_24
| V_25 ) ;
V_18 -> V_21 |= V_85 ;
if ( ( V_18 -> V_79 | V_18 -> V_80 ) & 0x0F ) {
V_18 -> V_21 |= V_7 [ V_86 ] . V_27 ;
V_9 = V_7 [ V_86 ] . V_9 ;
} else if ( ( V_18 -> V_79 | V_18 -> V_80 ) & 0x30 ) {
V_18 -> V_21 |= V_7 [ V_87 ] . V_27 ;
V_9 = V_7 [ V_87 ] . V_9 ;
} else {
V_18 -> V_21 |= V_7 [ V_88 ] . V_27 ;
V_9 = V_7 [ V_88 ] . V_9 ;
}
V_83 = F_28 ( V_9 , V_10 ) ;
V_57 = 3 * V_83 + 3 ;
V_19 = F_29 ( V_57 , V_89 ) ;
if ( ! V_19 ) {
V_16 = - V_90 ;
goto V_39;
}
V_19 [ 0 ] = V_18 -> V_21 ;
V_19 [ 1 ] = V_18 -> V_20 ;
V_19 [ 2 ] = ( V_18 -> V_56 << 1 ) ;
for ( V_82 = 0 ; V_82 < 8 ; V_82 ++ )
if ( F_30 ( V_82 , V_9 ) ) {
if ( V_18 -> V_79 & ( 1 << V_82 ) ) {
V_19 [ V_5 ] = ( V_18 -> V_65 [ V_82 ] >> 4 ) & 0xFF ;
V_19 [ V_5 + 1 ] = ( V_18 -> V_65 [ V_82 ] << 4 ) & 0xF0 ;
} else if ( V_82 < 4 ) {
V_19 [ V_5 ] = 0 ;
V_19 [ V_5 + 1 ] = 0 ;
} else {
V_19 [ V_5 ] = 0x80 ;
V_19 [ V_5 + 1 ] = 0 ;
}
if ( V_18 -> V_80 & ( 1 << V_82 ) ) {
V_19 [ V_5 + 1 ] |=
( V_18 -> V_67 [ V_82 ] >> 8 ) & 0x0F ;
V_19 [ V_5 + 2 ] = V_18 -> V_67 [ V_82 ] & 0xFF ;
} else if ( V_82 < 4 ) {
V_19 [ V_5 + 1 ] |= 0x0F ;
V_19 [ V_5 + 2 ] = 0xFF ;
} else {
V_19 [ V_5 + 1 ] |= 0x07 ;
V_19 [ V_5 + 2 ] = 0xFF ;
}
V_5 += 3 ;
}
V_16 = V_18 -> V_22 ( V_18 -> V_12 , V_19 , V_57 ) ;
if ( V_16 < 0 )
goto V_39;
if ( V_16 != V_57 ) {
V_16 = - V_91 ;
goto V_39;
}
V_19 [ 0 ] = V_18 -> V_20 ;
V_19 [ 1 ] = V_75 | ( V_18 -> V_56 << 1 ) | 0xF0 ;
V_16 = V_18 -> V_22 ( V_18 -> V_12 , V_19 , 2 ) ;
if ( V_16 < 0 )
goto V_39;
if ( V_16 != 2 ) {
V_16 = - V_91 ;
goto V_39;
}
V_16 = 0 ;
V_18 -> V_37 = true ;
V_39:
F_31 ( V_19 ) ;
return V_16 ;
}
static inline int F_32 ( int V_92 , int V_93 )
{
int V_16 = 0 ;
if ( V_92 < 4 ) {
if ( V_93 & ~ 0x0F ) {
V_16 = - V_38 ;
goto V_39;
}
} else if ( V_92 < 6 ) {
if ( V_93 & ~ 0x30 ) {
V_16 = - V_38 ;
goto V_39;
}
} else if ( V_93 & ~ 0xC0 )
V_16 = - V_38 ;
V_39:
return V_16 ;
}
static int F_33 ( struct V_28 * V_29 ,
const struct V_30 * V_31 , enum V_59 type ,
enum V_60 V_61 , int V_94 )
{
int V_16 = 0 ;
struct V_17 * V_18 = F_10 ( V_29 ) ;
T_7 V_95 ;
int V_78 = V_31 -> V_66 ;
F_11 ( & V_29 -> V_36 ) ;
V_95 = V_18 -> V_79 | V_18 -> V_80 ;
if ( V_61 == V_64 ) {
if ( V_94 == 0 )
V_18 -> V_79 &= ~ ( 1 << V_78 ) ;
else {
V_16 = F_32 ( ( 1 << V_78 ) ,
V_95 ) ;
if ( V_16 )
goto V_39;
V_18 -> V_79 |= ( 1 << V_78 ) ;
}
} else {
if ( V_94 == 0 )
V_18 -> V_80 &= ~ ( 1 << V_78 ) ;
else {
V_16 = F_32 ( ( 1 << V_78 ) ,
V_95 ) ;
if ( V_16 )
goto V_39;
V_18 -> V_80 |= ( 1 << V_78 ) ;
}
}
F_27 ( V_18 , ! ! ( V_18 -> V_80 | V_18 -> V_79 ) ) ;
V_39:
F_13 ( & V_29 -> V_36 ) ;
return V_16 ;
}
static int F_34 ( struct V_28 * V_29 ,
const unsigned long * V_96 )
{
struct V_17 * V_18 = F_10 ( V_29 ) ;
V_18 -> V_26 = F_1 ( V_96 , V_18 -> V_41 ) ;
if ( ! V_18 -> V_26 )
return - V_50 ;
F_8 ( V_18 ) ;
return 0 ;
}
static int F_35 ( struct V_17 * V_18 )
{
V_18 -> V_20 = V_97
| V_98
| V_99 ;
if ( V_18 -> V_100 )
V_18 -> V_20 |= V_101 ;
else
V_18 -> V_20 |= V_102
| V_103 ;
V_18 -> V_20 = F_36 ( V_18 -> V_20 ) ;
V_18 -> V_26 = & V_7 [ V_18 -> V_41 -> V_104 ] ;
V_18 -> V_21 = F_37 ( V_18 -> V_21 ) ;
return F_8 ( V_18 ) ;
}
static int F_38 ( struct V_28 * V_29 )
{
struct V_17 * V_18 = F_10 ( V_29 ) ;
unsigned long * V_105 ;
int V_5 ;
V_105 = F_39 ( & V_29 -> V_52 ,
F_40 ( V_10 ) * sizeof( long ) *
( V_18 -> V_41 -> V_6 + 1 ) , V_89 ) ;
if ( ! V_105 )
return - V_90 ;
for ( V_5 = 0 ; V_5 < V_18 -> V_41 -> V_6 ; V_5 ++ )
F_41 ( V_105 + F_40 ( V_10 ) * V_5 ,
V_7 [ V_18 -> V_41 -> V_8 [ V_5 ] ]
. V_9 , V_10 ) ;
V_29 -> V_106 = V_105 ;
return 0 ;
}
static T_5 F_42 ( int V_69 , void * V_107 )
{
struct V_108 * V_109 = V_107 ;
struct V_28 * V_29 = V_109 -> V_29 ;
struct V_17 * V_18 = F_10 ( V_29 ) ;
T_8 * V_35 ;
int V_110 ;
T_4 V_111 ;
unsigned long V_112 = F_28 ( V_18 -> V_26 -> V_9 ,
V_10 ) ;
if ( V_18 -> V_41 -> V_42 != 8 )
V_111 = V_112 * 2 ;
else
V_111 = V_112 ;
if ( V_29 -> V_113 ) {
V_111 += sizeof( T_6 ) ;
if ( V_111 % sizeof( T_6 ) )
V_111 += sizeof( T_6 ) - ( V_111 % sizeof( T_6 ) ) ;
}
if ( V_112 == 0 )
goto V_114;
V_35 = F_29 ( V_111 , V_89 ) ;
if ( V_35 == NULL )
goto V_114;
if ( V_18 -> V_41 -> V_42 != 8 )
V_110 = V_18 -> V_43 ( V_18 -> V_12 , V_35 , V_112 * 2 ) ;
else
V_110 = V_18 -> V_43 ( V_18 -> V_12 , V_35 , V_112 ) ;
if ( V_110 < 0 )
goto V_115;
F_43 ( V_29 , V_35 , F_23 () ) ;
V_115:
F_31 ( V_35 ) ;
V_114:
F_44 ( V_29 -> V_116 ) ;
return V_77 ;
}
static int F_45 ( struct V_11 * V_12 ,
const struct V_117 * V_118 )
{
int V_16 ;
struct V_17 * V_18 ;
struct V_28 * V_29 ;
struct V_119 * V_100 ;
V_29 = F_46 ( & V_12 -> V_52 ,
sizeof( struct V_17 ) ) ;
if ( ! V_29 )
return - V_90 ;
V_29 -> V_52 . V_120 = V_12 -> V_52 . V_120 ;
V_16 = F_47 ( V_29 , V_12 -> V_52 . V_121 ) ;
if ( V_16 < 0 )
return V_16 ;
V_18 = F_10 ( V_29 ) ;
V_18 -> V_122 = F_48 ( & V_12 -> V_52 , L_2 ) ;
if ( F_49 ( V_18 -> V_122 ) ) {
V_16 = F_50 ( V_18 -> V_122 ) ;
goto V_123;
}
V_16 = F_51 ( V_18 -> V_122 ) ;
if ( V_16 )
goto V_123;
F_52 ( V_12 , V_29 ) ;
V_18 -> V_41 = & V_124 [ V_118 -> V_125 ] ;
V_18 -> V_12 = V_12 ;
V_18 -> V_48 = V_18 -> V_41 -> V_126 * 1000 ;
V_100 = F_48 ( & V_12 -> V_52 , L_3 ) ;
if ( ! F_49 ( V_100 ) ) {
int V_48 ;
V_16 = F_51 ( V_100 ) ;
if ( V_16 )
goto V_127;
V_18 -> V_100 = V_100 ;
V_48 = F_53 ( V_100 ) ;
if ( V_48 <= 0 ) {
V_16 = - V_50 ;
goto V_127;
}
V_18 -> V_48 = V_48 ;
}
if ( F_54 ( V_12 -> V_128 , V_129 ) ) {
V_18 -> V_22 = V_130 ;
V_18 -> V_43 = V_131 ;
} else if ( F_54 ( V_12 -> V_128 , V_132 )
&& V_18 -> V_41 -> V_42 == 8 ) {
V_18 -> V_22 = F_3 ;
V_18 -> V_43 = F_5 ;
} else {
V_16 = - V_133 ;
goto V_127;
}
V_16 = F_38 ( V_29 ) ;
if ( V_16 )
goto V_127;
V_29 -> V_52 . V_134 = & V_12 -> V_52 ;
V_29 -> V_135 = V_118 -> V_135 ;
V_29 -> V_136 = V_18 -> V_41 -> V_136 ;
V_29 -> V_137 = V_18 -> V_41 -> V_137 ;
V_29 -> V_63 = V_18 -> V_41 -> V_63 ;
V_29 -> V_138 = V_139 ;
V_16 = F_35 ( V_18 ) ;
if ( V_16 < 0 )
goto V_127;
V_16 = F_55 ( V_29 , NULL ,
& F_42 , NULL ) ;
if ( V_16 )
goto V_127;
if ( V_12 -> V_69 ) {
V_16 = F_56 ( & V_12 -> V_52 , V_18 -> V_12 -> V_69 ,
NULL ,
& F_22 ,
V_140 | V_141 ,
L_4 ,
V_29 ) ;
if ( V_16 )
goto V_142;
}
V_16 = F_57 ( V_29 ) ;
if ( V_16 < 0 )
goto V_142;
return 0 ;
V_142:
F_58 ( V_29 ) ;
V_127:
if ( V_18 -> V_100 )
F_59 ( V_18 -> V_100 ) ;
F_59 ( V_18 -> V_122 ) ;
V_123:
F_60 ( V_29 ) ;
return V_16 ;
}
static int F_61 ( struct V_11 * V_12 )
{
struct V_28 * V_29 = F_62 ( V_12 ) ;
struct V_17 * V_18 = F_10 ( V_29 ) ;
F_63 ( V_29 ) ;
F_58 ( V_29 ) ;
if ( V_18 -> V_100 )
F_59 ( V_18 -> V_100 ) ;
F_59 ( V_18 -> V_122 ) ;
F_60 ( V_29 ) ;
return 0 ;
}
