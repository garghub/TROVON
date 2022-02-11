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
case 0 :
V_31 = F_6 ( V_26 , V_28 , V_29 , V_30 ) ;
if ( V_31 < 0 )
return V_31 ;
return V_42 ;
case V_43 :
if ( ( 1 << ( V_17 -> V_39 -> V_40 + 1 ) ) >
V_17 -> V_39 -> V_44 ) {
* V_29 = 0 ;
* V_41 = 500000 ;
return V_45 ;
} else {
* V_29 = ( V_17 -> V_39 -> V_44 )
>> V_17 -> V_39 -> V_40 ;
return V_42 ;
}
default:
return - V_46 ;
}
return 0 ;
}
static T_3 F_13 ( struct V_47 * V_48 ,
struct V_49 * V_50 ,
char * V_51 )
{
struct V_16 * V_17 = F_7 ( F_14 ( V_48 ) ) ;
return sprintf ( V_51 , L_1 , V_52 [ V_17 -> V_53 ] ) ;
}
static T_3 F_15 ( struct V_47 * V_48 ,
struct V_49 * V_50 ,
const char * V_51 ,
T_4 V_54 )
{
struct V_25 * V_26 = F_14 ( V_48 ) ;
struct V_16 * V_17 = F_7 ( V_26 ) ;
int V_5 , V_31 ;
unsigned long V_29 ;
bool V_55 = false ;
V_31 = F_16 ( V_51 , 10 , & V_29 ) ;
if ( V_31 )
return - V_46 ;
for ( V_5 = 0 ; V_5 < F_17 ( V_52 ) ; V_5 ++ )
if ( V_29 == V_52 [ V_5 ] ) {
V_55 = true ;
break;
}
if ( ! V_55 )
return - V_46 ;
F_8 ( & V_26 -> V_34 ) ;
V_17 -> V_53 = V_5 ;
F_11 ( & V_26 -> V_34 ) ;
return 0 ;
}
static int F_18 ( struct V_25 * V_26 ,
T_5 V_56 ,
int * V_29 )
{
struct V_16 * V_17 = F_7 ( V_26 ) ;
if ( F_19 ( V_56 ) == V_57 )
* V_29 = V_17 -> V_58 [ F_20 ( V_56 ) ] ;
else
* V_29 = V_17 -> V_59 [ F_20 ( V_56 ) ] ;
return 0 ;
}
static int F_21 ( struct V_25 * V_26 ,
T_5 V_56 ,
int V_29 )
{
struct V_16 * V_17 = F_7 ( V_26 ) ;
switch ( V_17 -> V_39 -> V_40 ) {
case 10 :
if ( V_29 > 0x3FF )
return - V_46 ;
break;
case 12 :
if ( V_29 > 0xFFF )
return - V_46 ;
break;
}
switch ( F_19 ( V_56 ) ) {
case V_57 :
V_17 -> V_58 [ F_20 ( V_56 ) ] = V_29 ;
break;
case V_60 :
V_17 -> V_59 [ F_20 ( V_56 ) ] = V_29 ;
break;
}
return 0 ;
}
static T_6 F_22 ( int V_61 , void * V_62 )
{
struct V_25 * V_26 = V_62 ;
struct V_16 * V_17 = F_7 ( V_26 ) ;
T_7 V_63 = F_23 () ;
unsigned long V_2 , V_64 ;
T_1 V_65 ;
T_1 V_66 [ 2 ] = { V_17 -> V_24 ,
V_67 | ( V_17 -> V_53 << 1 ) | 0xF0 } ;
F_10 ( V_17 -> V_12 , & V_65 , 1 ) ;
V_2 = V_65 ;
F_24 (loc, &mask, 8 )
F_25 ( V_26 , V_68 [ V_64 ] , V_63 ) ;
F_4 ( V_17 -> V_12 , V_66 , 2 ) ;
return V_69 ;
}
static int F_26 ( struct V_25 * V_26 ,
T_5 V_56 )
{
struct V_16 * V_17 = F_7 ( V_26 ) ;
int V_29 ;
int V_70 = F_20 ( V_56 ) ;
F_8 ( & V_26 -> V_34 ) ;
if ( F_19 ( V_56 ) == V_57 )
V_29 = ( 1 << V_70 ) & V_17 -> V_71 ;
else
V_29 = ( 1 << V_70 ) & V_17 -> V_72 ;
F_11 ( & V_26 -> V_34 ) ;
return V_29 ;
}
static int F_27 ( struct V_16 * V_17 , int V_73 )
{
T_1 * V_15 ;
int V_31 , V_5 = 3 , V_74 ;
unsigned long V_75 ;
int V_54 ;
const long * V_9 ;
if ( ! V_73 ) {
V_17 -> V_24 &= ~ V_76 ;
V_17 -> V_18 &= ~ V_20 ;
V_17 -> V_35 = false ;
return F_3 ( V_17 -> V_12 ,
V_17 -> V_24 ,
V_17 -> V_18 ) ;
}
V_17 -> V_24 |= V_76 ;
V_17 -> V_18 &= ~ ( V_19
| V_20
| V_21 ) ;
V_17 -> V_18 |= V_77 ;
if ( ( V_17 -> V_71 | V_17 -> V_72 ) & 0x0F ) {
V_17 -> V_18 |= V_7 [ V_78 ] . V_23 ;
V_9 = V_7 [ V_78 ] . V_9 ;
} else if ( ( V_17 -> V_71 | V_17 -> V_72 ) & 0x30 ) {
V_17 -> V_18 |= V_7 [ V_79 ] . V_23 ;
V_9 = V_7 [ V_79 ] . V_9 ;
} else {
V_17 -> V_18 |= V_7 [ V_80 ] . V_23 ;
V_9 = V_7 [ V_80 ] . V_9 ;
}
V_75 = F_28 ( V_9 , V_10 ) ;
V_54 = 3 * V_75 + 3 ;
V_15 = F_29 ( V_54 , V_81 ) ;
if ( ! V_15 ) {
V_31 = - V_82 ;
goto V_37;
}
V_15 [ 0 ] = V_17 -> V_18 ;
V_15 [ 1 ] = V_17 -> V_24 ;
V_15 [ 2 ] = ( V_17 -> V_53 << 1 ) ;
for ( V_74 = 0 ; V_74 < 8 ; V_74 ++ )
if ( F_30 ( V_74 , V_9 ) ) {
if ( V_17 -> V_71 & ( 1 << V_74 ) ) {
V_15 [ V_5 ] = ( V_17 -> V_58 [ V_74 ] >> 4 ) & 0xFF ;
V_15 [ V_5 + 1 ] = ( V_17 -> V_58 [ V_74 ] << 4 ) & 0xF0 ;
} else if ( V_74 < 4 ) {
V_15 [ V_5 ] = 0 ;
V_15 [ V_5 + 1 ] = 0 ;
} else {
V_15 [ V_5 ] = 0x80 ;
V_15 [ V_5 + 1 ] = 0 ;
}
if ( V_17 -> V_72 & ( 1 << V_74 ) ) {
V_15 [ V_5 + 1 ] |=
( V_17 -> V_59 [ V_74 ] >> 8 ) & 0x0F ;
V_15 [ V_5 + 2 ] = V_17 -> V_59 [ V_74 ] & 0xFF ;
} else if ( V_74 < 4 ) {
V_15 [ V_5 + 1 ] |= 0x0F ;
V_15 [ V_5 + 2 ] = 0xFF ;
} else {
V_15 [ V_5 + 1 ] |= 0x07 ;
V_15 [ V_5 + 2 ] = 0xFF ;
}
V_5 += 3 ;
}
V_31 = F_4 ( V_17 -> V_12 , V_15 , V_54 ) ;
if ( V_31 < 0 )
goto V_37;
if ( V_31 != V_54 ) {
V_31 = - V_83 ;
goto V_37;
}
V_15 [ 0 ] = V_17 -> V_24 ;
V_15 [ 1 ] = V_67 | ( V_17 -> V_53 << 1 ) | 0xF0 ;
V_31 = F_4 ( V_17 -> V_12 , V_15 , 2 ) ;
if ( V_31 < 0 )
goto V_37;
if ( V_31 != 2 ) {
V_31 = - V_83 ;
goto V_37;
}
V_31 = 0 ;
V_17 -> V_35 = true ;
V_37:
F_31 ( V_15 ) ;
return V_31 ;
}
static inline int F_32 ( int V_84 , int V_85 )
{
int V_31 = 0 ;
if ( V_84 < 4 ) {
if ( V_85 & ~ 0x0F ) {
V_31 = - V_36 ;
goto V_37;
}
} else if ( V_84 < 6 ) {
if ( V_85 & ~ 0x30 ) {
V_31 = - V_36 ;
goto V_37;
}
} else if ( V_85 & ~ 0xC0 )
V_31 = - V_36 ;
V_37:
return V_31 ;
}
static int F_33 ( struct V_25 * V_26 ,
T_5 V_56 ,
int V_86 )
{
int V_31 = 0 ;
struct V_16 * V_17 = F_7 ( V_26 ) ;
T_8 V_87 ;
int V_70 = F_20 ( V_56 ) ;
F_8 ( & V_26 -> V_34 ) ;
V_87 = V_17 -> V_71 | V_17 -> V_72 ;
if ( F_19 ( V_56 ) == V_57 ) {
if ( V_86 == 0 )
V_17 -> V_71 &= ~ ( 1 << V_70 ) ;
else {
V_31 = F_32 ( ( 1 << V_70 ) ,
V_87 ) ;
if ( V_31 )
goto V_37;
V_17 -> V_71 |= ( 1 << V_70 ) ;
}
} else {
if ( V_86 == 0 )
V_17 -> V_72 &= ~ ( 1 << V_70 ) ;
else {
V_31 = F_32 ( ( 1 << V_70 ) ,
V_87 ) ;
if ( V_31 )
goto V_37;
V_17 -> V_72 |= ( 1 << V_70 ) ;
}
}
F_27 ( V_17 , ! ! ( V_17 -> V_72 | V_17 -> V_71 ) ) ;
V_37:
F_11 ( & V_26 -> V_34 ) ;
return V_31 ;
}
static int F_34 ( struct V_16 * V_17 )
{
V_17 -> V_24 = V_88
| V_89
| V_90
| V_91
| V_92 ;
V_17 -> V_24 = F_35 ( V_17 -> V_24 ) ;
V_17 -> V_22 = & V_7 [ V_17 -> V_39 -> V_93 ] ;
V_17 -> V_18 = F_36 ( V_17 -> V_18 ) ;
return F_5 ( V_17 ) ;
}
static int T_9 F_37 ( struct V_25 * V_26 )
{
struct V_16 * V_17 = F_7 ( V_26 ) ;
unsigned long * V_94 ;
int V_5 ;
V_94 = F_38 ( F_39 ( V_10 ) * sizeof( long ) *
( V_17 -> V_39 -> V_6 + 1 ) , V_81 ) ;
if ( ! V_94 )
return - V_82 ;
for ( V_5 = 0 ; V_5 < V_17 -> V_39 -> V_6 ; V_5 ++ )
F_40 ( V_94 + F_39 ( V_10 ) * V_5 ,
V_7 [ V_17 -> V_39 -> V_8 [ V_5 ] ]
. V_9 , V_10 ) ;
V_26 -> V_95 = V_94 ;
return 0 ;
}
static int T_9 F_41 ( struct V_11 * V_12 ,
const struct V_96 * V_97 )
{
int V_31 ;
struct V_16 * V_17 ;
struct V_25 * V_26 ;
struct V_98 * V_99 ;
V_99 = F_42 ( & V_12 -> V_48 , L_2 ) ;
if ( F_43 ( V_99 ) ) {
V_31 = F_44 ( V_99 ) ;
goto V_100;
}
V_31 = F_45 ( V_99 ) ;
if ( V_31 )
goto V_101;
V_26 = F_46 ( sizeof( struct V_16 ) ) ;
if ( V_26 == NULL ) {
V_31 = - V_82 ;
goto V_102;
}
V_17 = F_7 ( V_26 ) ;
V_17 -> V_99 = V_99 ;
F_47 ( V_12 , V_26 ) ;
V_17 -> V_39 = & V_103 [ V_97 -> V_104 ] ;
V_17 -> V_12 = V_12 ;
V_31 = F_37 ( V_26 ) ;
if ( V_31 )
goto V_105;
V_26 -> V_48 . V_106 = & V_12 -> V_48 ;
V_26 -> V_107 = V_97 -> V_107 ;
V_26 -> V_108 = V_17 -> V_39 -> V_108 ;
V_26 -> V_109 = V_17 -> V_39 -> V_109 ;
V_26 -> V_110 = V_17 -> V_39 -> V_110 ;
V_26 -> V_111 = V_112 ;
V_26 -> V_108 = V_17 -> V_39 -> V_108 ;
V_26 -> V_109 = V_17 -> V_39 -> V_109 ;
V_31 = F_34 ( V_17 ) ;
if ( V_31 < 0 )
goto V_113;
V_31 = F_48 ( V_26 ) ;
if ( V_31 )
goto V_113;
V_31 = F_49 ( V_26 ,
V_17 -> V_39 -> V_108 ,
V_17 -> V_39 -> V_109 ) ;
if ( V_31 )
goto V_114;
if ( V_12 -> V_61 ) {
V_31 = F_50 ( V_17 -> V_12 -> V_61 ,
NULL ,
& F_22 ,
V_115 | V_116 ,
L_3 ,
V_26 ) ;
if ( V_31 )
goto V_117;
}
V_31 = F_51 ( V_26 ) ;
if ( V_31 < 0 )
goto V_118;
return 0 ;
V_118:
F_52 ( V_17 -> V_12 -> V_61 , V_26 ) ;
V_117:
F_53 ( V_26 ) ;
V_114:
F_54 ( V_26 ) ;
V_113:
F_31 ( V_26 -> V_95 ) ;
V_105:
F_55 ( V_26 ) ;
V_102:
F_56 ( V_99 ) ;
V_101:
F_57 ( V_99 ) ;
V_100:
return V_31 ;
}
static int F_58 ( struct V_11 * V_12 )
{
struct V_25 * V_26 = F_59 ( V_12 ) ;
struct V_16 * V_17 = F_7 ( V_26 ) ;
struct V_98 * V_99 = V_17 -> V_99 ;
F_60 ( V_26 ) ;
if ( V_12 -> V_61 )
F_52 ( V_17 -> V_12 -> V_61 , V_26 ) ;
F_53 ( V_26 ) ;
F_54 ( V_26 ) ;
F_31 ( V_26 -> V_95 ) ;
if ( ! F_43 ( V_99 ) ) {
F_56 ( V_99 ) ;
F_57 ( V_99 ) ;
}
F_55 ( V_26 ) ;
return 0 ;
}
