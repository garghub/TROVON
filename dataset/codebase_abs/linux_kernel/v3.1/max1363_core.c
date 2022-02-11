const struct V_1
* F_1 ( T_1 V_2 , const struct V_3 * V_4 )
{
int V_5 ;
if ( V_2 )
for ( V_5 = 0 ; V_5 < V_4 -> V_6 ; V_5 ++ )
if ( ! ( ( ~ V_7 [ V_4 -> V_8 [ V_5 ] ] . V_9 ) &
V_2 ) )
return & V_7 [ V_4 -> V_8 [ V_5 ] ] ;
return NULL ;
}
static int F_2 ( struct V_10 * V_11 ,
unsigned char V_12 ,
unsigned char V_13 )
{
T_2 V_14 [ 2 ] = { V_12 , V_13 } ;
return F_3 ( V_11 , V_14 , 2 ) ;
}
int F_4 ( struct V_15 * V_16 )
{
V_16 -> V_17 &= ~ ( V_18
| V_19
| V_20 ) ;
V_16 -> V_17 |= V_16 -> V_21 -> V_22 ;
return F_2 ( V_16 -> V_11 ,
V_16 -> V_23 ,
V_16 -> V_17 ) ;
}
static int F_5 ( struct V_24 * V_25 ,
struct V_26 const * V_27 ,
int * V_28 ,
long V_29 )
{
int V_30 = 0 ;
T_3 V_31 ;
char V_32 [ 2 ] ;
long V_2 ;
struct V_15 * V_16 = F_6 ( V_25 ) ;
struct V_10 * V_11 = V_16 -> V_11 ;
F_7 ( & V_25 -> V_33 ) ;
if ( V_16 -> V_34 ) {
V_30 = - V_35 ;
goto V_36;
}
if ( F_8 ( V_25 ) ) {
V_2 = V_7 [ V_27 -> V_37 ] . V_9 ;
V_31 = F_9 ( V_2 , V_16 ) ;
if ( V_31 < 0 ) {
V_30 = V_31 ;
goto V_36;
}
} else {
if ( V_16 -> V_21 != & V_7 [ V_27 -> V_37 ] ) {
V_16 -> V_21 = & V_7 [ V_27 -> V_37 ] ;
V_30 = F_4 ( V_16 ) ;
if ( V_30 < 0 )
goto V_36;
}
if ( V_16 -> V_38 -> V_39 != 8 ) {
V_31 = F_10 ( V_11 , V_32 , 2 ) ;
if ( V_31 < 0 ) {
V_30 = V_31 ;
goto V_36;
}
V_31 = ( T_3 ) ( V_32 [ 1 ] ) | ( ( T_3 ) ( V_32 [ 0 ] & 0x0F ) ) << 8 ;
} else {
V_31 = F_10 ( V_11 , V_32 , 1 ) ;
if ( V_31 < 0 ) {
V_30 = V_31 ;
goto V_36;
}
V_31 = V_32 [ 0 ] ;
}
}
* V_28 = V_31 ;
V_36:
F_11 ( & V_25 -> V_33 ) ;
return V_30 ;
}
static int F_12 ( struct V_24 * V_25 ,
struct V_26 const * V_27 ,
int * V_28 ,
int * V_40 ,
long V_29 )
{
struct V_15 * V_16 = F_6 ( V_25 ) ;
int V_30 ;
switch ( V_29 ) {
case 0 :
V_30 = F_5 ( V_25 , V_27 , V_28 , V_29 ) ;
if ( V_30 )
return V_30 ;
return V_41 ;
case ( 1 << V_42 ) :
if ( ( 1 << ( V_16 -> V_38 -> V_39 + 1 ) ) >
V_16 -> V_38 -> V_43 ) {
* V_28 = 0 ;
* V_40 = 500000 ;
return V_44 ;
} else {
* V_28 = ( V_16 -> V_38 -> V_43 )
>> V_16 -> V_38 -> V_39 ;
return V_41 ;
}
default:
return - V_45 ;
}
return 0 ;
}
static T_4 F_13 ( struct V_46 * V_47 ,
struct V_48 * V_49 ,
char * V_50 )
{
struct V_15 * V_16 = F_6 ( F_14 ( V_47 ) ) ;
return sprintf ( V_50 , L_1 , V_51 [ V_16 -> V_52 ] ) ;
}
static T_4 F_15 ( struct V_46 * V_47 ,
struct V_48 * V_49 ,
const char * V_50 ,
T_5 V_53 )
{
struct V_24 * V_25 = F_14 ( V_47 ) ;
struct V_15 * V_16 = F_6 ( V_25 ) ;
int V_5 , V_30 ;
unsigned long V_28 ;
bool V_54 = false ;
V_30 = F_16 ( V_50 , 10 , & V_28 ) ;
if ( V_30 )
return - V_45 ;
for ( V_5 = 0 ; V_5 < F_17 ( V_51 ) ; V_5 ++ )
if ( V_28 == V_51 [ V_5 ] ) {
V_54 = true ;
break;
}
if ( ! V_54 )
return - V_45 ;
F_7 ( & V_25 -> V_33 ) ;
V_16 -> V_52 = V_5 ;
F_11 ( & V_25 -> V_33 ) ;
return 0 ;
}
static int F_18 ( struct V_24 * V_25 ,
int V_55 ,
int * V_28 )
{
struct V_15 * V_16 = F_6 ( V_25 ) ;
if ( F_19 ( V_55 ) == V_56 )
* V_28 = V_16 -> V_57 [ F_20 ( V_55 ) ] ;
else
* V_28 = V_16 -> V_58 [ F_20 ( V_55 ) ] ;
return 0 ;
}
static int F_21 ( struct V_24 * V_25 ,
int V_55 ,
int V_28 )
{
struct V_15 * V_16 = F_6 ( V_25 ) ;
switch ( V_16 -> V_38 -> V_39 ) {
case 10 :
if ( V_28 > 0x3FF )
return - V_45 ;
break;
case 12 :
if ( V_28 > 0xFFF )
return - V_45 ;
break;
}
switch ( F_19 ( V_55 ) ) {
case V_56 :
V_16 -> V_57 [ F_20 ( V_55 ) ] = V_28 ;
break;
case V_59 :
V_16 -> V_58 [ F_20 ( V_55 ) ] = V_28 ;
break;
}
return 0 ;
}
static T_6 F_22 ( int V_60 , void * V_61 )
{
struct V_24 * V_25 = V_61 ;
struct V_15 * V_16 = F_6 ( V_25 ) ;
T_7 V_62 = F_23 () ;
unsigned long V_2 , V_63 ;
T_2 V_64 ;
T_2 V_65 [ 2 ] = { V_16 -> V_23 ,
V_66 | ( V_16 -> V_52 << 1 ) | 0xF0 } ;
F_10 ( V_16 -> V_11 , & V_64 , 1 ) ;
V_2 = V_64 ;
F_24 (loc, &mask, 8 )
F_25 ( V_25 , 0 , V_67 [ V_63 ] ,
V_62 ) ;
F_3 ( V_16 -> V_11 , V_65 , 2 ) ;
return V_68 ;
}
static int F_26 ( struct V_24 * V_25 ,
int V_55 )
{
struct V_15 * V_16 = F_6 ( V_25 ) ;
int V_28 ;
int V_69 = F_20 ( V_55 ) ;
F_7 ( & V_25 -> V_33 ) ;
if ( F_19 ( V_55 ) == V_56 )
V_28 = ( 1 << V_69 ) & V_16 -> V_70 ;
else
V_28 = ( 1 << V_69 ) & V_16 -> V_71 ;
F_11 ( & V_25 -> V_33 ) ;
return V_28 ;
}
static int F_27 ( struct V_15 * V_16 , int V_72 )
{
T_2 * V_14 ;
int V_30 , V_5 = 3 , V_73 ;
unsigned long V_74 ;
int V_53 ;
long V_9 ;
if ( ! V_72 ) {
V_16 -> V_23 &= ~ V_75 ;
V_16 -> V_17 &= ~ V_19 ;
V_16 -> V_34 = false ;
return F_2 ( V_16 -> V_11 ,
V_16 -> V_23 ,
V_16 -> V_17 ) ;
}
V_16 -> V_23 |= V_75 ;
V_16 -> V_17 &= ~ ( V_18
| V_19
| V_20 ) ;
V_16 -> V_17 |= V_76 ;
if ( ( V_16 -> V_70 | V_16 -> V_71 ) & 0x0F ) {
V_16 -> V_17 |= V_7 [ V_77 ] . V_22 ;
V_9 = V_7 [ V_77 ] . V_9 ;
} else if ( ( V_16 -> V_70 | V_16 -> V_71 ) & 0x30 ) {
V_16 -> V_17 |= V_7 [ V_78 ] . V_22 ;
V_9 = V_7 [ V_78 ] . V_9 ;
} else {
V_16 -> V_17 |= V_7 [ V_79 ] . V_22 ;
V_9 = V_7 [ V_79 ] . V_9 ;
}
V_74 = F_28 ( V_9 ) ;
V_53 = 3 * V_74 + 3 ;
V_14 = F_29 ( V_53 , V_80 ) ;
if ( ! V_14 ) {
V_30 = - V_81 ;
goto V_36;
}
V_14 [ 0 ] = V_16 -> V_17 ;
V_14 [ 1 ] = V_16 -> V_23 ;
V_14 [ 2 ] = ( V_16 -> V_52 << 1 ) ;
for ( V_73 = 0 ; V_73 < 8 ; V_73 ++ )
if ( V_9 & ( 1 << V_73 ) ) {
if ( V_16 -> V_70 & ( 1 << V_73 ) ) {
V_14 [ V_5 ] = ( V_16 -> V_57 [ V_73 ] >> 4 ) & 0xFF ;
V_14 [ V_5 + 1 ] = ( V_16 -> V_57 [ V_73 ] << 4 ) & 0xF0 ;
} else if ( V_73 < 4 ) {
V_14 [ V_5 ] = 0 ;
V_14 [ V_5 + 1 ] = 0 ;
} else {
V_14 [ V_5 ] = 0x80 ;
V_14 [ V_5 + 1 ] = 0 ;
}
if ( V_16 -> V_71 & ( 1 << V_73 ) ) {
V_14 [ V_5 + 1 ] |=
( V_16 -> V_58 [ V_73 ] >> 8 ) & 0x0F ;
V_14 [ V_5 + 2 ] = V_16 -> V_58 [ V_73 ] & 0xFF ;
} else if ( V_73 < 4 ) {
V_14 [ V_5 + 1 ] |= 0x0F ;
V_14 [ V_5 + 2 ] = 0xFF ;
} else {
V_14 [ V_5 + 1 ] |= 0x07 ;
V_14 [ V_5 + 2 ] = 0xFF ;
}
V_5 += 3 ;
}
V_30 = F_3 ( V_16 -> V_11 , V_14 , V_53 ) ;
if ( V_30 < 0 )
goto V_36;
if ( V_30 != V_53 ) {
V_30 = - V_82 ;
goto V_36;
}
V_14 [ 0 ] = V_16 -> V_23 ;
V_14 [ 1 ] = V_66 | ( V_16 -> V_52 << 1 ) | 0xF0 ;
V_30 = F_3 ( V_16 -> V_11 , V_14 , 2 ) ;
if ( V_30 < 0 )
goto V_36;
if ( V_30 != 2 ) {
V_30 = - V_82 ;
goto V_36;
}
V_30 = 0 ;
V_16 -> V_34 = true ;
V_36:
F_30 ( V_14 ) ;
return V_30 ;
}
static inline int F_31 ( int V_83 , int V_84 )
{
int V_30 = 0 ;
if ( V_83 < 4 ) {
if ( V_84 & ~ 0x0F ) {
V_30 = - V_35 ;
goto V_36;
}
} else if ( V_83 < 6 ) {
if ( V_84 & ~ 0x30 ) {
V_30 = - V_35 ;
goto V_36;
}
} else if ( V_84 & ~ 0xC0 )
V_30 = - V_35 ;
V_36:
return V_30 ;
}
static int F_32 ( struct V_24 * V_25 ,
int V_55 ,
int V_85 )
{
int V_30 = 0 ;
struct V_15 * V_16 = F_6 ( V_25 ) ;
T_8 V_86 ;
int V_69 = F_20 ( V_55 ) ;
F_7 ( & V_25 -> V_33 ) ;
V_86 = V_16 -> V_70 | V_16 -> V_71 ;
if ( F_19 ( V_55 ) == V_56 ) {
if ( V_85 == 0 )
V_16 -> V_70 &= ~ ( 1 << V_69 ) ;
else {
V_30 = F_31 ( ( 1 << V_69 ) ,
V_86 ) ;
if ( V_30 )
goto V_36;
V_16 -> V_70 |= ( 1 << V_69 ) ;
}
} else {
if ( V_85 == 0 )
V_16 -> V_71 &= ~ ( 1 << V_69 ) ;
else {
V_30 = F_31 ( ( 1 << V_69 ) ,
V_86 ) ;
if ( V_30 )
goto V_36;
V_16 -> V_71 |= ( 1 << V_69 ) ;
}
}
F_27 ( V_16 , ! ! ( V_16 -> V_71 | V_16 -> V_70 ) ) ;
V_36:
F_11 ( & V_25 -> V_33 ) ;
return V_30 ;
}
static int F_33 ( struct V_15 * V_16 )
{
V_16 -> V_23 = V_87
| V_88
| V_89
| V_90
| V_91 ;
V_16 -> V_23 = F_34 ( V_16 -> V_23 ) ;
V_16 -> V_21 = & V_7 [ V_16 -> V_38 -> V_92 ] ;
V_16 -> V_17 = F_35 ( V_16 -> V_17 ) ;
return F_4 ( V_16 ) ;
}
static int T_9 F_36 ( struct V_10 * V_11 ,
const struct V_93 * V_94 )
{
int V_30 , V_5 , V_95 = 0 ;
struct V_15 * V_16 ;
struct V_24 * V_25 ;
struct V_96 * V_97 ;
V_97 = F_37 ( & V_11 -> V_47 , L_2 ) ;
if ( F_38 ( V_97 ) ) {
V_30 = F_39 ( V_97 ) ;
goto V_98;
}
V_30 = F_40 ( V_97 ) ;
if ( V_30 )
goto V_99;
V_25 = F_41 ( sizeof( struct V_15 ) ) ;
if ( V_25 == NULL ) {
V_30 = - V_81 ;
goto V_100;
}
V_16 = F_6 ( V_25 ) ;
V_16 -> V_97 = V_97 ;
F_42 ( V_11 , V_25 ) ;
V_16 -> V_38 = & V_101 [ V_94 -> V_102 ] ;
V_16 -> V_11 = V_11 ;
V_25 -> V_103
= F_43 ( sizeof( * V_25 -> V_103 ) *
( V_16 -> V_38 -> V_6 + 1 ) , V_80 ) ;
if ( ! V_25 -> V_103 ) {
V_30 = - V_81 ;
goto V_104;
}
for ( V_5 = 0 ; V_5 < V_16 -> V_38 -> V_6 ; V_5 ++ )
V_25 -> V_103 [ V_5 ] =
V_7 [ V_16 -> V_38 -> V_8 [ V_5 ] ]
. V_9 ;
V_25 -> V_47 . V_105 = & V_11 -> V_47 ;
V_25 -> V_106 = V_94 -> V_106 ;
V_25 -> V_107 = V_16 -> V_38 -> V_107 ;
V_25 -> V_108 = V_109 ;
V_30 = F_33 ( V_16 ) ;
if ( V_30 < 0 )
goto V_110;
V_30 = F_44 ( V_25 ) ;
if ( V_30 )
goto V_110;
V_30 = F_45 ( V_25 ) ;
if ( V_30 )
goto V_111;
V_95 = 1 ;
V_30 = F_46 ( V_25 -> V_112 , 0 ,
V_16 -> V_38 -> V_113 ,
V_16 -> V_38 -> V_114 ) ;
if ( V_30 )
goto V_111;
if ( V_11 -> V_60 ) {
V_30 = F_47 ( V_16 -> V_11 -> V_60 ,
NULL ,
& F_22 ,
V_115 | V_116 ,
L_3 ,
V_25 ) ;
if ( V_30 )
goto V_117;
}
return 0 ;
V_117:
F_48 ( V_25 -> V_112 ) ;
V_111:
F_49 ( V_25 ) ;
V_110:
F_30 ( V_25 -> V_103 ) ;
V_104:
if ( ! V_95 )
F_50 ( V_25 ) ;
else
F_51 ( V_25 ) ;
V_100:
F_52 ( V_97 ) ;
V_99:
F_53 ( V_97 ) ;
V_98:
return V_30 ;
}
static int F_54 ( struct V_10 * V_11 )
{
struct V_24 * V_25 = F_55 ( V_11 ) ;
struct V_15 * V_16 = F_6 ( V_25 ) ;
struct V_96 * V_97 = V_16 -> V_97 ;
if ( V_11 -> V_60 )
F_56 ( V_16 -> V_11 -> V_60 , V_25 ) ;
F_48 ( V_25 -> V_112 ) ;
F_49 ( V_25 ) ;
F_30 ( V_25 -> V_103 ) ;
if ( ! F_38 ( V_97 ) ) {
F_52 ( V_97 ) ;
F_53 ( V_97 ) ;
}
F_51 ( V_25 ) ;
return 0 ;
}
static T_10 int F_57 ( void )
{
return F_58 ( & V_118 ) ;
}
static T_11 void F_59 ( void )
{
F_60 ( & V_118 ) ;
}
