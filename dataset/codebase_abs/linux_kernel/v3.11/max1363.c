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
static int F_3 ( struct V_11 * V_12 ,
unsigned char V_13 ,
unsigned char V_14 )
{
T_1 V_15 [ 2 ] = { V_13 , V_14 } ;
return F_4 ( V_12 , V_15 , 2 ) ;
}
static int F_5 ( struct V_16 * V_17 )
{
V_17 -> V_18 &= ~ ( V_19
| V_20
| V_21 ) ;
V_17 -> V_18 |= V_17 -> V_22 -> V_23 ;
return F_3 ( V_17 -> V_12 ,
V_17 -> V_24 ,
V_17 -> V_18 ) ;
}
static int F_6 ( struct V_25 * V_26 ,
struct V_27 const * V_28 ,
int * V_29 ,
long V_30 )
{
int V_31 = 0 ;
T_2 V_32 ;
T_1 V_33 [ 2 ] ;
struct V_16 * V_17 = F_7 ( V_26 ) ;
struct V_11 * V_12 = V_17 -> V_12 ;
F_8 ( & V_26 -> V_34 ) ;
if ( V_17 -> V_35 || F_9 ( V_26 ) ) {
V_31 = - V_36 ;
goto V_37;
}
if ( V_17 -> V_22 != & V_7 [ V_28 -> V_38 ] ) {
V_17 -> V_22 = & V_7 [ V_28 -> V_38 ] ;
V_31 = F_5 ( V_17 ) ;
if ( V_31 < 0 )
goto V_37;
}
if ( V_17 -> V_39 -> V_40 != 8 ) {
V_32 = F_10 ( V_12 , V_33 , 2 ) ;
if ( V_32 < 0 ) {
V_31 = V_32 ;
goto V_37;
}
V_32 = ( V_33 [ 1 ] | V_33 [ 0 ] << 8 ) &
( ( 1 << V_17 -> V_39 -> V_40 ) - 1 ) ;
} else {
V_32 = F_10 ( V_12 , V_33 , 1 ) ;
if ( V_32 < 0 ) {
V_31 = V_32 ;
goto V_37;
}
V_32 = V_33 [ 0 ] ;
}
* V_29 = V_32 ;
V_37:
F_11 ( & V_26 -> V_34 ) ;
return V_31 ;
}
static int F_12 ( struct V_25 * V_26 ,
struct V_27 const * V_28 ,
int * V_29 ,
int * V_41 ,
long V_30 )
{
struct V_16 * V_17 = F_7 ( V_26 ) ;
int V_31 ;
unsigned long V_42 ;
switch ( V_30 ) {
case V_43 :
V_31 = F_6 ( V_26 , V_28 , V_29 , V_30 ) ;
if ( V_31 < 0 )
return V_31 ;
return V_44 ;
case V_45 :
V_42 = V_17 -> V_46 >> V_17 -> V_39 -> V_40 ;
* V_29 = V_42 / 1000 ;
* V_41 = ( V_42 % 1000 ) * 1000 ;
return V_47 ;
default:
return - V_48 ;
}
return 0 ;
}
static T_3 F_13 ( struct V_49 * V_50 ,
struct V_51 * V_52 ,
char * V_53 )
{
struct V_16 * V_17 = F_7 ( F_14 ( V_50 ) ) ;
return sprintf ( V_53 , L_1 , V_54 [ V_17 -> V_55 ] ) ;
}
static T_3 F_15 ( struct V_49 * V_50 ,
struct V_51 * V_52 ,
const char * V_53 ,
T_4 V_56 )
{
struct V_25 * V_26 = F_14 ( V_50 ) ;
struct V_16 * V_17 = F_7 ( V_26 ) ;
int V_5 , V_31 ;
unsigned long V_29 ;
bool V_57 = false ;
V_31 = F_16 ( V_53 , 10 , & V_29 ) ;
if ( V_31 )
return - V_48 ;
for ( V_5 = 0 ; V_5 < F_17 ( V_54 ) ; V_5 ++ )
if ( V_29 == V_54 [ V_5 ] ) {
V_57 = true ;
break;
}
if ( ! V_57 )
return - V_48 ;
F_8 ( & V_26 -> V_34 ) ;
V_17 -> V_55 = V_5 ;
F_11 ( & V_26 -> V_34 ) ;
return 0 ;
}
static int F_18 ( struct V_25 * V_26 ,
T_5 V_58 ,
int * V_29 )
{
struct V_16 * V_17 = F_7 ( V_26 ) ;
if ( F_19 ( V_58 ) == V_59 )
* V_29 = V_17 -> V_60 [ F_20 ( V_58 ) ] ;
else
* V_29 = V_17 -> V_61 [ F_20 ( V_58 ) ] ;
return 0 ;
}
static int F_21 ( struct V_25 * V_26 ,
T_5 V_58 ,
int V_29 )
{
struct V_16 * V_17 = F_7 ( V_26 ) ;
switch ( V_17 -> V_39 -> V_40 ) {
case 10 :
if ( V_29 > 0x3FF )
return - V_48 ;
break;
case 12 :
if ( V_29 > 0xFFF )
return - V_48 ;
break;
}
switch ( F_19 ( V_58 ) ) {
case V_59 :
V_17 -> V_60 [ F_20 ( V_58 ) ] = V_29 ;
break;
case V_62 :
V_17 -> V_61 [ F_20 ( V_58 ) ] = V_29 ;
break;
}
return 0 ;
}
static T_6 F_22 ( int V_63 , void * V_64 )
{
struct V_25 * V_26 = V_64 ;
struct V_16 * V_17 = F_7 ( V_26 ) ;
T_7 V_65 = F_23 () ;
unsigned long V_2 , V_66 ;
T_1 V_67 ;
T_1 V_68 [ 2 ] = { V_17 -> V_24 ,
V_69 | ( V_17 -> V_55 << 1 ) | 0xF0 } ;
F_10 ( V_17 -> V_12 , & V_67 , 1 ) ;
V_2 = V_67 ;
F_24 (loc, &mask, 8 )
F_25 ( V_26 , V_70 [ V_66 ] , V_65 ) ;
F_4 ( V_17 -> V_12 , V_68 , 2 ) ;
return V_71 ;
}
static int F_26 ( struct V_25 * V_26 ,
T_5 V_58 )
{
struct V_16 * V_17 = F_7 ( V_26 ) ;
int V_29 ;
int V_72 = F_20 ( V_58 ) ;
F_8 ( & V_26 -> V_34 ) ;
if ( F_19 ( V_58 ) == V_59 )
V_29 = ( 1 << V_72 ) & V_17 -> V_73 ;
else
V_29 = ( 1 << V_72 ) & V_17 -> V_74 ;
F_11 ( & V_26 -> V_34 ) ;
return V_29 ;
}
static int F_27 ( struct V_16 * V_17 , int V_75 )
{
T_1 * V_15 ;
int V_31 , V_5 = 3 , V_76 ;
unsigned long V_77 ;
int V_56 ;
const long * V_9 ;
if ( ! V_75 ) {
V_17 -> V_24 &= ~ V_78 ;
V_17 -> V_18 &= ~ V_20 ;
V_17 -> V_35 = false ;
return F_3 ( V_17 -> V_12 ,
V_17 -> V_24 ,
V_17 -> V_18 ) ;
}
V_17 -> V_24 |= V_78 ;
V_17 -> V_18 &= ~ ( V_19
| V_20
| V_21 ) ;
V_17 -> V_18 |= V_79 ;
if ( ( V_17 -> V_73 | V_17 -> V_74 ) & 0x0F ) {
V_17 -> V_18 |= V_7 [ V_80 ] . V_23 ;
V_9 = V_7 [ V_80 ] . V_9 ;
} else if ( ( V_17 -> V_73 | V_17 -> V_74 ) & 0x30 ) {
V_17 -> V_18 |= V_7 [ V_81 ] . V_23 ;
V_9 = V_7 [ V_81 ] . V_9 ;
} else {
V_17 -> V_18 |= V_7 [ V_82 ] . V_23 ;
V_9 = V_7 [ V_82 ] . V_9 ;
}
V_77 = F_28 ( V_9 , V_10 ) ;
V_56 = 3 * V_77 + 3 ;
V_15 = F_29 ( V_56 , V_83 ) ;
if ( ! V_15 ) {
V_31 = - V_84 ;
goto V_37;
}
V_15 [ 0 ] = V_17 -> V_18 ;
V_15 [ 1 ] = V_17 -> V_24 ;
V_15 [ 2 ] = ( V_17 -> V_55 << 1 ) ;
for ( V_76 = 0 ; V_76 < 8 ; V_76 ++ )
if ( F_30 ( V_76 , V_9 ) ) {
if ( V_17 -> V_73 & ( 1 << V_76 ) ) {
V_15 [ V_5 ] = ( V_17 -> V_60 [ V_76 ] >> 4 ) & 0xFF ;
V_15 [ V_5 + 1 ] = ( V_17 -> V_60 [ V_76 ] << 4 ) & 0xF0 ;
} else if ( V_76 < 4 ) {
V_15 [ V_5 ] = 0 ;
V_15 [ V_5 + 1 ] = 0 ;
} else {
V_15 [ V_5 ] = 0x80 ;
V_15 [ V_5 + 1 ] = 0 ;
}
if ( V_17 -> V_74 & ( 1 << V_76 ) ) {
V_15 [ V_5 + 1 ] |=
( V_17 -> V_61 [ V_76 ] >> 8 ) & 0x0F ;
V_15 [ V_5 + 2 ] = V_17 -> V_61 [ V_76 ] & 0xFF ;
} else if ( V_76 < 4 ) {
V_15 [ V_5 + 1 ] |= 0x0F ;
V_15 [ V_5 + 2 ] = 0xFF ;
} else {
V_15 [ V_5 + 1 ] |= 0x07 ;
V_15 [ V_5 + 2 ] = 0xFF ;
}
V_5 += 3 ;
}
V_31 = F_4 ( V_17 -> V_12 , V_15 , V_56 ) ;
if ( V_31 < 0 )
goto V_37;
if ( V_31 != V_56 ) {
V_31 = - V_85 ;
goto V_37;
}
V_15 [ 0 ] = V_17 -> V_24 ;
V_15 [ 1 ] = V_69 | ( V_17 -> V_55 << 1 ) | 0xF0 ;
V_31 = F_4 ( V_17 -> V_12 , V_15 , 2 ) ;
if ( V_31 < 0 )
goto V_37;
if ( V_31 != 2 ) {
V_31 = - V_85 ;
goto V_37;
}
V_31 = 0 ;
V_17 -> V_35 = true ;
V_37:
F_31 ( V_15 ) ;
return V_31 ;
}
static inline int F_32 ( int V_86 , int V_87 )
{
int V_31 = 0 ;
if ( V_86 < 4 ) {
if ( V_87 & ~ 0x0F ) {
V_31 = - V_36 ;
goto V_37;
}
} else if ( V_86 < 6 ) {
if ( V_87 & ~ 0x30 ) {
V_31 = - V_36 ;
goto V_37;
}
} else if ( V_87 & ~ 0xC0 )
V_31 = - V_36 ;
V_37:
return V_31 ;
}
static int F_33 ( struct V_25 * V_26 ,
T_5 V_58 ,
int V_88 )
{
int V_31 = 0 ;
struct V_16 * V_17 = F_7 ( V_26 ) ;
T_8 V_89 ;
int V_72 = F_20 ( V_58 ) ;
F_8 ( & V_26 -> V_34 ) ;
V_89 = V_17 -> V_73 | V_17 -> V_74 ;
if ( F_19 ( V_58 ) == V_59 ) {
if ( V_88 == 0 )
V_17 -> V_73 &= ~ ( 1 << V_72 ) ;
else {
V_31 = F_32 ( ( 1 << V_72 ) ,
V_89 ) ;
if ( V_31 )
goto V_37;
V_17 -> V_73 |= ( 1 << V_72 ) ;
}
} else {
if ( V_88 == 0 )
V_17 -> V_74 &= ~ ( 1 << V_72 ) ;
else {
V_31 = F_32 ( ( 1 << V_72 ) ,
V_89 ) ;
if ( V_31 )
goto V_37;
V_17 -> V_74 |= ( 1 << V_72 ) ;
}
}
F_27 ( V_17 , ! ! ( V_17 -> V_74 | V_17 -> V_73 ) ) ;
V_37:
F_11 ( & V_26 -> V_34 ) ;
return V_31 ;
}
static int F_34 ( struct V_25 * V_26 ,
const unsigned long * V_90 )
{
struct V_16 * V_17 = F_7 ( V_26 ) ;
V_17 -> V_22 = F_1 ( V_90 , V_17 -> V_39 ) ;
if ( ! V_17 -> V_22 )
return - V_48 ;
F_5 ( V_17 ) ;
return 0 ;
}
static int F_35 ( struct V_16 * V_17 )
{
V_17 -> V_24 = V_91
| V_92
| V_93 ;
if ( V_17 -> V_94 )
V_17 -> V_24 |= V_95 ;
else
V_17 -> V_24 |= V_96
| V_97 ;
V_17 -> V_24 = F_36 ( V_17 -> V_24 ) ;
V_17 -> V_22 = & V_7 [ V_17 -> V_39 -> V_98 ] ;
V_17 -> V_18 = F_37 ( V_17 -> V_18 ) ;
return F_5 ( V_17 ) ;
}
static int F_38 ( struct V_25 * V_26 )
{
struct V_16 * V_17 = F_7 ( V_26 ) ;
unsigned long * V_99 ;
int V_5 ;
V_99 = F_39 ( & V_26 -> V_50 ,
F_40 ( V_10 ) * sizeof( long ) *
( V_17 -> V_39 -> V_6 + 1 ) , V_83 ) ;
if ( ! V_99 )
return - V_84 ;
for ( V_5 = 0 ; V_5 < V_17 -> V_39 -> V_6 ; V_5 ++ )
F_41 ( V_99 + F_40 ( V_10 ) * V_5 ,
V_7 [ V_17 -> V_39 -> V_8 [ V_5 ] ]
. V_9 , V_10 ) ;
V_26 -> V_100 = V_99 ;
return 0 ;
}
static T_6 F_42 ( int V_63 , void * V_101 )
{
struct V_102 * V_103 = V_101 ;
struct V_25 * V_26 = V_103 -> V_26 ;
struct V_16 * V_17 = F_7 ( V_26 ) ;
T_7 V_104 ;
T_9 * V_33 ;
int V_105 ;
T_4 V_106 ;
unsigned long V_107 = F_28 ( V_17 -> V_22 -> V_9 ,
V_10 ) ;
if ( V_17 -> V_39 -> V_40 != 8 )
V_106 = V_107 * 2 ;
else
V_106 = V_107 ;
if ( V_26 -> V_108 ) {
V_106 += sizeof( T_7 ) ;
if ( V_106 % sizeof( T_7 ) )
V_106 += sizeof( T_7 ) - ( V_106 % sizeof( T_7 ) ) ;
}
if ( V_107 == 0 )
goto V_109;
V_33 = F_29 ( V_106 , V_83 ) ;
if ( V_33 == NULL )
goto V_109;
if ( V_17 -> V_39 -> V_40 != 8 )
V_105 = F_10 ( V_17 -> V_12 , V_33 , V_107 * 2 ) ;
else
V_105 = F_10 ( V_17 -> V_12 , V_33 , V_107 ) ;
if ( V_105 < 0 )
goto V_110;
V_104 = F_23 () ;
if ( V_26 -> V_108 )
memcpy ( V_33 + V_106 - sizeof( T_7 ) , & V_104 , sizeof( V_104 ) ) ;
F_43 ( V_26 , V_33 ) ;
V_110:
F_31 ( V_33 ) ;
V_109:
F_44 ( V_26 -> V_111 ) ;
return V_71 ;
}
static int F_45 ( struct V_11 * V_12 ,
const struct V_112 * V_113 )
{
int V_31 ;
struct V_16 * V_17 ;
struct V_25 * V_26 ;
struct V_114 * V_94 ;
V_26 = F_46 ( sizeof( struct V_16 ) ) ;
if ( V_26 == NULL ) {
V_31 = - V_84 ;
goto V_115;
}
V_26 -> V_50 . V_116 = V_12 -> V_50 . V_116 ;
V_31 = F_47 ( V_26 , V_12 -> V_50 . V_117 ) ;
if ( V_31 < 0 )
goto V_118;
V_17 = F_7 ( V_26 ) ;
V_17 -> V_119 = F_48 ( & V_12 -> V_50 , L_2 ) ;
if ( F_49 ( V_17 -> V_119 ) ) {
V_31 = F_50 ( V_17 -> V_119 ) ;
goto V_120;
}
V_31 = F_51 ( V_17 -> V_119 ) ;
if ( V_31 )
goto V_120;
F_52 ( V_12 , V_26 ) ;
V_17 -> V_39 = & V_121 [ V_113 -> V_122 ] ;
V_17 -> V_12 = V_12 ;
V_17 -> V_46 = V_17 -> V_39 -> V_123 * 1000 ;
V_94 = F_48 ( & V_12 -> V_50 , L_3 ) ;
if ( ! F_49 ( V_94 ) ) {
int V_46 ;
V_31 = F_51 ( V_94 ) ;
if ( V_31 )
goto V_124;
V_17 -> V_94 = V_94 ;
V_46 = F_53 ( V_94 ) ;
if ( V_46 <= 0 ) {
V_31 = - V_48 ;
goto V_124;
}
V_17 -> V_46 = V_46 ;
}
V_31 = F_38 ( V_26 ) ;
if ( V_31 )
goto V_124;
V_26 -> V_50 . V_125 = & V_12 -> V_50 ;
V_26 -> V_126 = V_113 -> V_126 ;
V_26 -> V_127 = V_17 -> V_39 -> V_127 ;
V_26 -> V_128 = V_17 -> V_39 -> V_128 ;
V_26 -> V_129 = V_17 -> V_39 -> V_129 ;
V_26 -> V_130 = V_131 ;
V_31 = F_35 ( V_17 ) ;
if ( V_31 < 0 )
goto V_124;
V_31 = F_54 ( V_26 , NULL ,
& F_42 , & V_132 ) ;
if ( V_31 )
goto V_124;
if ( V_12 -> V_63 ) {
V_31 = F_55 ( & V_12 -> V_50 , V_17 -> V_12 -> V_63 ,
NULL ,
& F_22 ,
V_133 | V_134 ,
L_4 ,
V_26 ) ;
if ( V_31 )
goto V_135;
}
V_31 = F_56 ( V_26 ) ;
if ( V_31 < 0 )
goto V_135;
return 0 ;
V_135:
F_57 ( V_26 ) ;
V_124:
if ( V_17 -> V_94 )
F_58 ( V_17 -> V_94 ) ;
F_58 ( V_17 -> V_119 ) ;
V_120:
F_59 ( V_26 ) ;
V_118:
F_60 ( V_26 ) ;
V_115:
return V_31 ;
}
static int F_61 ( struct V_11 * V_12 )
{
struct V_25 * V_26 = F_62 ( V_12 ) ;
struct V_16 * V_17 = F_7 ( V_26 ) ;
F_63 ( V_26 ) ;
F_57 ( V_26 ) ;
if ( V_17 -> V_94 )
F_58 ( V_17 -> V_94 ) ;
F_58 ( V_17 -> V_119 ) ;
F_59 ( V_26 ) ;
F_60 ( V_26 ) ;
return 0 ;
}
