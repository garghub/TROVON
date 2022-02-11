const struct V_1
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
int F_5 ( struct V_16 * V_17 )
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
char V_33 [ 2 ] ;
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
V_32 = ( T_2 ) ( V_33 [ 1 ] ) | ( ( T_2 ) ( V_33 [ 0 ] & 0x0F ) ) << 8 ;
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
switch ( V_30 ) {
case V_42 :
V_31 = F_6 ( V_26 , V_28 , V_29 , V_30 ) ;
if ( V_31 < 0 )
return V_31 ;
return V_43 ;
case V_44 :
if ( ( 1 << ( V_17 -> V_39 -> V_40 + 1 ) ) >
V_17 -> V_39 -> V_45 ) {
* V_29 = 0 ;
* V_41 = 500000 ;
return V_46 ;
} else {
* V_29 = ( V_17 -> V_39 -> V_45 )
>> V_17 -> V_39 -> V_40 ;
return V_43 ;
}
default:
return - V_47 ;
}
return 0 ;
}
static T_3 F_13 ( struct V_48 * V_49 ,
struct V_50 * V_51 ,
char * V_52 )
{
struct V_16 * V_17 = F_7 ( F_14 ( V_49 ) ) ;
return sprintf ( V_52 , L_1 , V_53 [ V_17 -> V_54 ] ) ;
}
static T_3 F_15 ( struct V_48 * V_49 ,
struct V_50 * V_51 ,
const char * V_52 ,
T_4 V_55 )
{
struct V_25 * V_26 = F_14 ( V_49 ) ;
struct V_16 * V_17 = F_7 ( V_26 ) ;
int V_5 , V_31 ;
unsigned long V_29 ;
bool V_56 = false ;
V_31 = F_16 ( V_52 , 10 , & V_29 ) ;
if ( V_31 )
return - V_47 ;
for ( V_5 = 0 ; V_5 < F_17 ( V_53 ) ; V_5 ++ )
if ( V_29 == V_53 [ V_5 ] ) {
V_56 = true ;
break;
}
if ( ! V_56 )
return - V_47 ;
F_8 ( & V_26 -> V_34 ) ;
V_17 -> V_54 = V_5 ;
F_11 ( & V_26 -> V_34 ) ;
return 0 ;
}
static int F_18 ( struct V_25 * V_26 ,
T_5 V_57 ,
int * V_29 )
{
struct V_16 * V_17 = F_7 ( V_26 ) ;
if ( F_19 ( V_57 ) == V_58 )
* V_29 = V_17 -> V_59 [ F_20 ( V_57 ) ] ;
else
* V_29 = V_17 -> V_60 [ F_20 ( V_57 ) ] ;
return 0 ;
}
static int F_21 ( struct V_25 * V_26 ,
T_5 V_57 ,
int V_29 )
{
struct V_16 * V_17 = F_7 ( V_26 ) ;
switch ( V_17 -> V_39 -> V_40 ) {
case 10 :
if ( V_29 > 0x3FF )
return - V_47 ;
break;
case 12 :
if ( V_29 > 0xFFF )
return - V_47 ;
break;
}
switch ( F_19 ( V_57 ) ) {
case V_58 :
V_17 -> V_59 [ F_20 ( V_57 ) ] = V_29 ;
break;
case V_61 :
V_17 -> V_60 [ F_20 ( V_57 ) ] = V_29 ;
break;
}
return 0 ;
}
static T_6 F_22 ( int V_62 , void * V_63 )
{
struct V_25 * V_26 = V_63 ;
struct V_16 * V_17 = F_7 ( V_26 ) ;
T_7 V_64 = F_23 () ;
unsigned long V_2 , V_65 ;
T_1 V_66 ;
T_1 V_67 [ 2 ] = { V_17 -> V_24 ,
V_68 | ( V_17 -> V_54 << 1 ) | 0xF0 } ;
F_10 ( V_17 -> V_12 , & V_66 , 1 ) ;
V_2 = V_66 ;
F_24 (loc, &mask, 8 )
F_25 ( V_26 , V_69 [ V_65 ] , V_64 ) ;
F_4 ( V_17 -> V_12 , V_67 , 2 ) ;
return V_70 ;
}
static int F_26 ( struct V_25 * V_26 ,
T_5 V_57 )
{
struct V_16 * V_17 = F_7 ( V_26 ) ;
int V_29 ;
int V_71 = F_20 ( V_57 ) ;
F_8 ( & V_26 -> V_34 ) ;
if ( F_19 ( V_57 ) == V_58 )
V_29 = ( 1 << V_71 ) & V_17 -> V_72 ;
else
V_29 = ( 1 << V_71 ) & V_17 -> V_73 ;
F_11 ( & V_26 -> V_34 ) ;
return V_29 ;
}
static int F_27 ( struct V_16 * V_17 , int V_74 )
{
T_1 * V_15 ;
int V_31 , V_5 = 3 , V_75 ;
unsigned long V_76 ;
int V_55 ;
const long * V_9 ;
if ( ! V_74 ) {
V_17 -> V_24 &= ~ V_77 ;
V_17 -> V_18 &= ~ V_20 ;
V_17 -> V_35 = false ;
return F_3 ( V_17 -> V_12 ,
V_17 -> V_24 ,
V_17 -> V_18 ) ;
}
V_17 -> V_24 |= V_77 ;
V_17 -> V_18 &= ~ ( V_19
| V_20
| V_21 ) ;
V_17 -> V_18 |= V_78 ;
if ( ( V_17 -> V_72 | V_17 -> V_73 ) & 0x0F ) {
V_17 -> V_18 |= V_7 [ V_79 ] . V_23 ;
V_9 = V_7 [ V_79 ] . V_9 ;
} else if ( ( V_17 -> V_72 | V_17 -> V_73 ) & 0x30 ) {
V_17 -> V_18 |= V_7 [ V_80 ] . V_23 ;
V_9 = V_7 [ V_80 ] . V_9 ;
} else {
V_17 -> V_18 |= V_7 [ V_81 ] . V_23 ;
V_9 = V_7 [ V_81 ] . V_9 ;
}
V_76 = F_28 ( V_9 , V_10 ) ;
V_55 = 3 * V_76 + 3 ;
V_15 = F_29 ( V_55 , V_82 ) ;
if ( ! V_15 ) {
V_31 = - V_83 ;
goto V_37;
}
V_15 [ 0 ] = V_17 -> V_18 ;
V_15 [ 1 ] = V_17 -> V_24 ;
V_15 [ 2 ] = ( V_17 -> V_54 << 1 ) ;
for ( V_75 = 0 ; V_75 < 8 ; V_75 ++ )
if ( F_30 ( V_75 , V_9 ) ) {
if ( V_17 -> V_72 & ( 1 << V_75 ) ) {
V_15 [ V_5 ] = ( V_17 -> V_59 [ V_75 ] >> 4 ) & 0xFF ;
V_15 [ V_5 + 1 ] = ( V_17 -> V_59 [ V_75 ] << 4 ) & 0xF0 ;
} else if ( V_75 < 4 ) {
V_15 [ V_5 ] = 0 ;
V_15 [ V_5 + 1 ] = 0 ;
} else {
V_15 [ V_5 ] = 0x80 ;
V_15 [ V_5 + 1 ] = 0 ;
}
if ( V_17 -> V_73 & ( 1 << V_75 ) ) {
V_15 [ V_5 + 1 ] |=
( V_17 -> V_60 [ V_75 ] >> 8 ) & 0x0F ;
V_15 [ V_5 + 2 ] = V_17 -> V_60 [ V_75 ] & 0xFF ;
} else if ( V_75 < 4 ) {
V_15 [ V_5 + 1 ] |= 0x0F ;
V_15 [ V_5 + 2 ] = 0xFF ;
} else {
V_15 [ V_5 + 1 ] |= 0x07 ;
V_15 [ V_5 + 2 ] = 0xFF ;
}
V_5 += 3 ;
}
V_31 = F_4 ( V_17 -> V_12 , V_15 , V_55 ) ;
if ( V_31 < 0 )
goto V_37;
if ( V_31 != V_55 ) {
V_31 = - V_84 ;
goto V_37;
}
V_15 [ 0 ] = V_17 -> V_24 ;
V_15 [ 1 ] = V_68 | ( V_17 -> V_54 << 1 ) | 0xF0 ;
V_31 = F_4 ( V_17 -> V_12 , V_15 , 2 ) ;
if ( V_31 < 0 )
goto V_37;
if ( V_31 != 2 ) {
V_31 = - V_84 ;
goto V_37;
}
V_31 = 0 ;
V_17 -> V_35 = true ;
V_37:
F_31 ( V_15 ) ;
return V_31 ;
}
static inline int F_32 ( int V_85 , int V_86 )
{
int V_31 = 0 ;
if ( V_85 < 4 ) {
if ( V_86 & ~ 0x0F ) {
V_31 = - V_36 ;
goto V_37;
}
} else if ( V_85 < 6 ) {
if ( V_86 & ~ 0x30 ) {
V_31 = - V_36 ;
goto V_37;
}
} else if ( V_86 & ~ 0xC0 )
V_31 = - V_36 ;
V_37:
return V_31 ;
}
static int F_33 ( struct V_25 * V_26 ,
T_5 V_57 ,
int V_87 )
{
int V_31 = 0 ;
struct V_16 * V_17 = F_7 ( V_26 ) ;
T_8 V_88 ;
int V_71 = F_20 ( V_57 ) ;
F_8 ( & V_26 -> V_34 ) ;
V_88 = V_17 -> V_72 | V_17 -> V_73 ;
if ( F_19 ( V_57 ) == V_58 ) {
if ( V_87 == 0 )
V_17 -> V_72 &= ~ ( 1 << V_71 ) ;
else {
V_31 = F_32 ( ( 1 << V_71 ) ,
V_88 ) ;
if ( V_31 )
goto V_37;
V_17 -> V_72 |= ( 1 << V_71 ) ;
}
} else {
if ( V_87 == 0 )
V_17 -> V_73 &= ~ ( 1 << V_71 ) ;
else {
V_31 = F_32 ( ( 1 << V_71 ) ,
V_88 ) ;
if ( V_31 )
goto V_37;
V_17 -> V_73 |= ( 1 << V_71 ) ;
}
}
F_27 ( V_17 , ! ! ( V_17 -> V_73 | V_17 -> V_72 ) ) ;
V_37:
F_11 ( & V_26 -> V_34 ) ;
return V_31 ;
}
static int F_34 ( struct V_16 * V_17 )
{
V_17 -> V_24 = V_89
| V_90
| V_91
| V_92
| V_93 ;
V_17 -> V_24 = F_35 ( V_17 -> V_24 ) ;
V_17 -> V_22 = & V_7 [ V_17 -> V_39 -> V_94 ] ;
V_17 -> V_18 = F_36 ( V_17 -> V_18 ) ;
return F_5 ( V_17 ) ;
}
static int T_9 F_37 ( struct V_25 * V_26 )
{
struct V_16 * V_17 = F_7 ( V_26 ) ;
unsigned long * V_95 ;
int V_5 ;
V_95 = F_38 ( F_39 ( V_10 ) * sizeof( long ) *
( V_17 -> V_39 -> V_6 + 1 ) , V_82 ) ;
if ( ! V_95 )
return - V_83 ;
for ( V_5 = 0 ; V_5 < V_17 -> V_39 -> V_6 ; V_5 ++ )
F_40 ( V_95 + F_39 ( V_10 ) * V_5 ,
V_7 [ V_17 -> V_39 -> V_8 [ V_5 ] ]
. V_9 , V_10 ) ;
V_26 -> V_96 = V_95 ;
return 0 ;
}
static int T_9 F_41 ( struct V_11 * V_12 ,
const struct V_97 * V_98 )
{
int V_31 ;
struct V_16 * V_17 ;
struct V_25 * V_26 ;
struct V_99 * V_100 ;
V_100 = F_42 ( & V_12 -> V_49 , L_2 ) ;
if ( F_43 ( V_100 ) ) {
V_31 = F_44 ( V_100 ) ;
goto V_101;
}
V_31 = F_45 ( V_100 ) ;
if ( V_31 )
goto V_102;
V_26 = F_46 ( sizeof( struct V_16 ) ) ;
if ( V_26 == NULL ) {
V_31 = - V_83 ;
goto V_103;
}
V_31 = F_47 ( V_26 , V_12 -> V_49 . V_104 ) ;
if ( V_31 < 0 )
goto V_105;
V_17 = F_7 ( V_26 ) ;
V_17 -> V_100 = V_100 ;
F_48 ( V_12 , V_26 ) ;
V_17 -> V_39 = & V_106 [ V_98 -> V_107 ] ;
V_17 -> V_12 = V_12 ;
V_31 = F_37 ( V_26 ) ;
if ( V_31 )
goto V_108;
V_26 -> V_49 . V_109 = & V_12 -> V_49 ;
V_26 -> V_110 = V_98 -> V_110 ;
V_26 -> V_111 = V_17 -> V_39 -> V_111 ;
V_26 -> V_112 = V_17 -> V_39 -> V_112 ;
V_26 -> V_113 = V_17 -> V_39 -> V_113 ;
V_26 -> V_114 = V_115 ;
V_26 -> V_111 = V_17 -> V_39 -> V_111 ;
V_26 -> V_112 = V_17 -> V_39 -> V_112 ;
V_31 = F_34 ( V_17 ) ;
if ( V_31 < 0 )
goto V_116;
V_31 = F_49 ( V_26 ) ;
if ( V_31 )
goto V_116;
V_31 = F_50 ( V_26 ,
V_17 -> V_39 -> V_111 ,
V_17 -> V_39 -> V_112 ) ;
if ( V_31 )
goto V_117;
if ( V_12 -> V_62 ) {
V_31 = F_51 ( V_17 -> V_12 -> V_62 ,
NULL ,
& F_22 ,
V_118 | V_119 ,
L_3 ,
V_26 ) ;
if ( V_31 )
goto V_120;
}
V_31 = F_52 ( V_26 ) ;
if ( V_31 < 0 )
goto V_121;
return 0 ;
V_121:
F_53 ( V_17 -> V_12 -> V_62 , V_26 ) ;
V_120:
F_54 ( V_26 ) ;
V_117:
F_55 ( V_26 ) ;
V_116:
F_31 ( V_26 -> V_96 ) ;
V_108:
F_56 ( V_26 , V_12 -> V_49 . V_104 ) ;
V_105:
F_57 ( V_26 ) ;
V_103:
F_58 ( V_100 ) ;
V_102:
F_59 ( V_100 ) ;
V_101:
return V_31 ;
}
static int F_60 ( struct V_11 * V_12 )
{
struct V_25 * V_26 = F_61 ( V_12 ) ;
struct V_16 * V_17 = F_7 ( V_26 ) ;
struct V_99 * V_100 = V_17 -> V_100 ;
F_62 ( V_26 ) ;
if ( V_12 -> V_62 )
F_53 ( V_17 -> V_12 -> V_62 , V_26 ) ;
F_54 ( V_26 ) ;
F_55 ( V_26 ) ;
F_31 ( V_26 -> V_96 ) ;
if ( ! F_43 ( V_100 ) ) {
F_58 ( V_100 ) ;
F_59 ( V_100 ) ;
}
F_56 ( V_26 , V_12 -> V_49 . V_104 ) ;
F_57 ( V_26 ) ;
return 0 ;
}
