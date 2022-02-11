static int F_1 ( struct V_1 * V_2 , unsigned V_3 )
{
return F_2 ( V_2 -> V_4 , V_3 ) ;
}
static int F_3 ( struct V_1 * V_2 , unsigned V_3 , unsigned V_5 )
{
return F_4 ( V_2 -> V_4 , V_3 , V_5 ) ;
}
static int
F_5 ( struct V_1 * V_2 , unsigned V_3 , T_1 * V_6 , unsigned V_7 )
{
while ( V_7 -- ) {
int V_8 = F_1 ( V_2 , V_3 ++ ) ;
if ( V_8 < 0 )
return V_8 ;
* V_6 ++ = V_8 ;
}
return 0 ;
}
static int F_6 ( struct V_1 * V_2 , unsigned V_3 )
{
return F_7 ( V_2 -> V_4 , V_3 << 1 ) ;
}
static int F_8 ( struct V_1 * V_2 , unsigned V_3 , unsigned V_5 )
{
return F_9 ( V_2 -> V_4 , V_3 << 1 , V_5 ) ;
}
static int
F_10 ( struct V_1 * V_2 , unsigned V_3 , T_1 * V_6 , unsigned V_7 )
{
while ( V_7 -- ) {
int V_8 = F_6 ( V_2 , V_3 ++ ) ;
if ( V_8 < 0 )
return V_8 ;
* V_6 ++ = V_8 ;
}
return 0 ;
}
static int F_11 ( struct V_1 * V_2 , unsigned V_3 )
{
T_2 V_9 [ 2 ] , V_10 [ 1 ] ;
int V_11 ;
V_9 [ 0 ] = V_2 -> V_12 | 0x01 ;
V_9 [ 1 ] = V_3 ;
V_11 = F_12 ( V_2 -> V_4 , V_9 , sizeof( V_9 ) , V_10 , sizeof( V_10 ) ) ;
return ( V_11 < 0 ) ? V_11 : V_10 [ 0 ] ;
}
static int F_13 ( struct V_1 * V_2 , unsigned V_3 , unsigned V_5 )
{
T_2 V_9 [ 3 ] ;
V_9 [ 0 ] = V_2 -> V_12 ;
V_9 [ 1 ] = V_3 ;
V_9 [ 2 ] = V_5 ;
return F_12 ( V_2 -> V_4 , V_9 , sizeof( V_9 ) , NULL , 0 ) ;
}
static int
F_14 ( struct V_1 * V_2 , unsigned V_3 , T_1 * V_6 , unsigned V_7 )
{
T_2 V_9 [ 2 ] , * V_13 ;
int V_11 ;
if ( ( V_7 + V_3 ) > sizeof( V_2 -> V_14 ) )
return - V_15 ;
V_9 [ 0 ] = V_2 -> V_12 | 0x01 ;
V_9 [ 1 ] = V_3 ;
V_13 = ( T_2 * ) V_6 ;
V_11 = F_12 ( V_2 -> V_4 , V_9 , sizeof( V_9 ) , V_13 , V_7 ) ;
if ( V_11 >= 0 ) {
while ( V_7 -- )
V_6 [ V_7 ] = V_13 [ V_7 ] ;
}
return V_11 ;
}
static int F_15 ( struct V_1 * V_2 , unsigned V_3 )
{
T_2 V_9 [ 2 ] , V_10 [ 2 ] ;
int V_11 ;
V_9 [ 0 ] = V_2 -> V_12 | 0x01 ;
V_9 [ 1 ] = V_3 << 1 ;
V_11 = F_12 ( V_2 -> V_4 , V_9 , sizeof( V_9 ) , V_10 , sizeof( V_10 ) ) ;
return ( V_11 < 0 ) ? V_11 : ( V_10 [ 0 ] | ( V_10 [ 1 ] << 8 ) ) ;
}
static int F_16 ( struct V_1 * V_2 , unsigned V_3 , unsigned V_5 )
{
T_2 V_9 [ 4 ] ;
V_9 [ 0 ] = V_2 -> V_12 ;
V_9 [ 1 ] = V_3 << 1 ;
V_9 [ 2 ] = V_5 ;
V_9 [ 3 ] = V_5 >> 8 ;
return F_12 ( V_2 -> V_4 , V_9 , sizeof( V_9 ) , NULL , 0 ) ;
}
static int
F_17 ( struct V_1 * V_2 , unsigned V_3 , T_1 * V_6 , unsigned V_7 )
{
T_2 V_9 [ 2 ] ;
int V_11 ;
if ( ( V_7 + V_3 ) > sizeof( V_2 -> V_14 ) )
return - V_15 ;
V_9 [ 0 ] = V_2 -> V_12 | 0x01 ;
V_9 [ 1 ] = V_3 << 1 ;
V_11 = F_12 ( V_2 -> V_4 , V_9 , sizeof( V_9 ) ,
( T_2 * ) V_6 , V_7 * 2 ) ;
if ( V_11 >= 0 ) {
while ( V_7 -- )
V_6 [ V_7 ] = F_18 ( ( V_16 ) V_6 [ V_7 ] ) ;
}
return V_11 ;
}
static int F_19 ( struct V_17 * V_18 , unsigned V_19 )
{
struct V_1 * V_2 = F_20 ( V_18 ) ;
int V_11 ;
F_21 ( & V_2 -> V_20 ) ;
V_2 -> V_14 [ V_21 ] |= ( 1 << V_19 ) ;
V_11 = V_2 -> V_22 -> V_23 ( V_2 , V_21 , V_2 -> V_14 [ V_21 ] ) ;
F_22 ( & V_2 -> V_20 ) ;
return V_11 ;
}
static int F_23 ( struct V_17 * V_18 , unsigned V_19 )
{
struct V_1 * V_2 = F_20 ( V_18 ) ;
int V_11 ;
F_21 ( & V_2 -> V_20 ) ;
V_11 = V_2 -> V_22 -> V_24 ( V_2 , V_25 ) ;
if ( V_11 < 0 )
V_11 = 0 ;
else {
V_2 -> V_14 [ V_25 ] = V_11 ;
V_11 = ! ! ( V_11 & ( 1 << V_19 ) ) ;
}
F_22 ( & V_2 -> V_20 ) ;
return V_11 ;
}
static int F_24 ( struct V_1 * V_2 , unsigned V_26 , int V_27 )
{
unsigned V_28 = V_2 -> V_14 [ V_29 ] ;
if ( V_27 )
V_28 |= V_26 ;
else
V_28 &= ~ V_26 ;
V_2 -> V_14 [ V_29 ] = V_28 ;
return V_2 -> V_22 -> V_23 ( V_2 , V_29 , V_28 ) ;
}
static void F_25 ( struct V_17 * V_18 , unsigned V_19 , int V_27 )
{
struct V_1 * V_2 = F_20 ( V_18 ) ;
unsigned V_26 = 1 << V_19 ;
F_21 ( & V_2 -> V_20 ) ;
F_24 ( V_2 , V_26 , V_27 ) ;
F_22 ( & V_2 -> V_20 ) ;
}
static int
F_26 ( struct V_17 * V_18 , unsigned V_19 , int V_27 )
{
struct V_1 * V_2 = F_20 ( V_18 ) ;
unsigned V_26 = 1 << V_19 ;
int V_11 ;
F_21 ( & V_2 -> V_20 ) ;
V_11 = F_24 ( V_2 , V_26 , V_27 ) ;
if ( V_11 == 0 ) {
V_2 -> V_14 [ V_21 ] &= ~ V_26 ;
V_11 = V_2 -> V_22 -> V_23 ( V_2 , V_21 , V_2 -> V_14 [ V_21 ] ) ;
}
F_22 ( & V_2 -> V_20 ) ;
return V_11 ;
}
static T_3 F_27 ( int V_30 , void * V_4 )
{
struct V_1 * V_2 = V_4 ;
int V_31 , V_32 , V_33 ;
unsigned int V_34 ;
F_21 ( & V_2 -> V_20 ) ;
V_32 = V_2 -> V_22 -> V_24 ( V_2 , V_35 ) ;
if ( V_32 < 0 ) {
F_22 ( & V_2 -> V_20 ) ;
return V_36 ;
}
V_2 -> V_14 [ V_35 ] = V_32 ;
V_31 = V_2 -> V_22 -> V_24 ( V_2 , V_37 ) ;
if ( V_31 < 0 ) {
F_22 ( & V_2 -> V_20 ) ;
return V_36 ;
}
V_2 -> V_14 [ V_37 ] = V_31 ;
F_22 ( & V_2 -> V_20 ) ;
for ( V_33 = 0 ; V_33 < V_2 -> V_18 . V_38 ; V_33 ++ ) {
if ( ( F_28 ( V_33 ) & V_2 -> V_14 [ V_35 ] ) &&
( ( F_28 ( V_33 ) & V_31 & V_2 -> V_39 ) ||
( V_2 -> V_40 & ~ V_31 & F_28 ( V_33 ) ) ||
( F_28 ( V_33 ) & V_2 -> V_14 [ V_41 ] ) ) ) {
V_34 = F_29 ( V_2 -> V_18 . V_42 , V_33 ) ;
F_30 ( V_34 ) ;
}
}
return V_36 ;
}
static void F_31 ( struct V_43 * V_4 )
{
struct V_17 * V_44 = F_32 ( V_4 ) ;
struct V_1 * V_2 = F_20 ( V_44 ) ;
unsigned int V_45 = V_4 -> V_46 ;
V_2 -> V_14 [ V_47 ] &= ~ F_28 ( V_45 ) ;
}
static void F_33 ( struct V_43 * V_4 )
{
struct V_17 * V_44 = F_32 ( V_4 ) ;
struct V_1 * V_2 = F_20 ( V_44 ) ;
unsigned int V_45 = V_4 -> V_46 ;
V_2 -> V_14 [ V_47 ] |= F_28 ( V_45 ) ;
}
static int F_34 ( struct V_43 * V_4 , unsigned int type )
{
struct V_17 * V_44 = F_32 ( V_4 ) ;
struct V_1 * V_2 = F_20 ( V_44 ) ;
unsigned int V_45 = V_4 -> V_46 ;
int V_11 = 0 ;
if ( ( type & V_48 ) == V_48 ) {
V_2 -> V_14 [ V_41 ] &= ~ F_28 ( V_45 ) ;
V_2 -> V_39 |= F_28 ( V_45 ) ;
V_2 -> V_40 |= F_28 ( V_45 ) ;
} else if ( type & V_49 ) {
V_2 -> V_14 [ V_41 ] &= ~ F_28 ( V_45 ) ;
V_2 -> V_39 |= F_28 ( V_45 ) ;
V_2 -> V_40 &= ~ F_28 ( V_45 ) ;
} else if ( type & V_50 ) {
V_2 -> V_14 [ V_41 ] &= ~ F_28 ( V_45 ) ;
V_2 -> V_39 &= ~ F_28 ( V_45 ) ;
V_2 -> V_40 |= F_28 ( V_45 ) ;
} else if ( type & V_51 ) {
V_2 -> V_14 [ V_41 ] |= F_28 ( V_45 ) ;
V_2 -> V_14 [ V_52 ] &= ~ F_28 ( V_45 ) ;
} else if ( type & V_53 ) {
V_2 -> V_14 [ V_41 ] |= F_28 ( V_45 ) ;
V_2 -> V_14 [ V_52 ] |= F_28 ( V_45 ) ;
} else
return - V_15 ;
return V_11 ;
}
static void F_35 ( struct V_43 * V_4 )
{
struct V_17 * V_44 = F_32 ( V_4 ) ;
struct V_1 * V_2 = F_20 ( V_44 ) ;
F_21 ( & V_2 -> V_54 ) ;
}
static void F_36 ( struct V_43 * V_4 )
{
struct V_17 * V_44 = F_32 ( V_4 ) ;
struct V_1 * V_2 = F_20 ( V_44 ) ;
F_21 ( & V_2 -> V_20 ) ;
V_2 -> V_22 -> V_23 ( V_2 , V_47 , V_2 -> V_14 [ V_47 ] ) ;
V_2 -> V_22 -> V_23 ( V_2 , V_52 , V_2 -> V_14 [ V_52 ] ) ;
V_2 -> V_22 -> V_23 ( V_2 , V_41 , V_2 -> V_14 [ V_41 ] ) ;
F_22 ( & V_2 -> V_20 ) ;
F_22 ( & V_2 -> V_54 ) ;
}
static int F_37 ( struct V_1 * V_2 )
{
struct V_17 * V_18 = & V_2 -> V_18 ;
int V_55 ;
unsigned long V_56 = V_57 | V_58 ;
F_38 ( & V_2 -> V_54 ) ;
if ( V_2 -> V_59 )
V_56 |= V_60 ;
else
V_56 |= V_61 ;
V_55 = F_39 ( V_18 -> V_62 , V_2 -> V_30 , NULL ,
F_27 ,
V_56 , F_40 ( V_18 -> V_62 ) , V_2 ) ;
if ( V_55 != 0 ) {
F_41 ( V_18 -> V_62 , L_1 ,
V_2 -> V_30 , V_55 ) ;
return V_55 ;
}
V_55 = F_42 ( V_18 ,
& V_63 ,
0 ,
V_64 ,
V_65 ) ;
if ( V_55 ) {
F_41 ( V_18 -> V_62 ,
L_2 , V_55 ) ;
return V_55 ;
}
F_43 ( V_18 ,
& V_63 ,
V_2 -> V_30 ) ;
return 0 ;
}
static void F_44 ( struct V_66 * V_67 , struct V_17 * V_18 )
{
struct V_1 * V_2 ;
char V_68 ;
int V_69 ;
unsigned V_26 ;
V_2 = F_20 ( V_18 ) ;
V_68 = '0' + ( ( V_2 -> V_12 >> 1 ) & 0x7 ) ;
F_21 ( & V_2 -> V_20 ) ;
V_69 = V_2 -> V_22 -> V_70 ( V_2 , 0 , V_2 -> V_14 , F_45 ( V_2 -> V_14 ) ) ;
if ( V_69 < 0 ) {
F_46 ( V_67 , L_3 , V_69 ) ;
goto V_71;
}
for ( V_69 = 0 , V_26 = 1 ; V_69 < V_18 -> V_38 ; V_69 ++ , V_26 <<= 1 ) {
const char * V_72 ;
V_72 = F_47 ( V_18 , V_69 ) ;
if ( ! V_72 )
continue;
F_46 ( V_67 , L_4 ,
V_18 -> V_73 + V_69 , V_68 , V_69 , V_72 ,
( V_2 -> V_14 [ V_21 ] & V_26 ) ? L_5 : L_6 ,
( V_2 -> V_14 [ V_25 ] & V_26 ) ? L_7 : L_8 ,
( V_2 -> V_14 [ V_74 ] & V_26 ) ? L_9 : L_10 ) ;
F_48 ( V_67 , L_11 ) ;
}
V_71:
F_22 ( & V_2 -> V_20 ) ;
}
static int F_49 ( struct V_1 * V_2 , struct V_75 * V_76 ,
void * V_4 , unsigned V_12 , unsigned type ,
struct V_77 * V_78 , int V_79 )
{
int V_11 ;
bool V_80 = false ;
F_38 ( & V_2 -> V_20 ) ;
V_2 -> V_4 = V_4 ;
V_2 -> V_12 = V_12 ;
V_2 -> V_59 = false ;
V_2 -> V_18 . V_81 = F_19 ;
V_2 -> V_18 . V_82 = F_23 ;
V_2 -> V_18 . V_83 = F_26 ;
V_2 -> V_18 . V_84 = F_25 ;
V_2 -> V_18 . V_85 = F_44 ;
#ifdef F_50
V_2 -> V_18 . V_86 = 2 ;
V_2 -> V_18 . V_87 = V_76 -> V_87 ;
#endif
switch ( type ) {
#ifdef F_51
case V_88 :
V_2 -> V_22 = & V_89 ;
V_2 -> V_18 . V_38 = 8 ;
V_2 -> V_18 . V_72 = L_12 ;
break;
case V_90 :
V_2 -> V_22 = & V_91 ;
V_2 -> V_18 . V_38 = 16 ;
V_2 -> V_18 . V_72 = L_13 ;
break;
case V_92 :
V_2 -> V_22 = & V_91 ;
V_2 -> V_18 . V_38 = 16 ;
V_2 -> V_18 . V_72 = L_14 ;
break;
#endif
#if F_52 ( V_93 )
case V_94 :
V_2 -> V_22 = & V_95 ;
V_2 -> V_18 . V_38 = 8 ;
V_2 -> V_18 . V_72 = L_15 ;
break;
case V_96 :
V_2 -> V_22 = & V_97 ;
V_2 -> V_18 . V_38 = 16 ;
V_2 -> V_18 . V_72 = L_16 ;
break;
#endif
default:
F_41 ( V_76 , L_17 , type ) ;
return - V_15 ;
}
V_2 -> V_18 . V_73 = V_78 -> V_73 ;
V_2 -> V_18 . V_98 = true ;
V_2 -> V_18 . V_62 = V_76 ;
V_2 -> V_18 . V_99 = V_100 ;
V_11 = V_2 -> V_22 -> V_24 ( V_2 , V_101 ) ;
if ( V_11 < 0 )
goto V_102;
V_2 -> V_103 = V_78 -> V_103 ;
if ( V_2 -> V_30 && V_2 -> V_103 ) {
V_2 -> V_59 =
F_53 ( V_2 -> V_18 . V_62 -> V_87 ,
L_18 ) ;
V_80 = V_78 -> V_80 ;
}
if ( ( V_11 & V_104 ) || ! ( V_11 & V_105 ) || V_80 ||
V_2 -> V_59 ) {
V_11 &= ~ ( V_104 | ( V_104 << 8 ) ) ;
V_11 |= V_105 | ( V_105 << 8 ) ;
if ( V_2 -> V_59 )
V_11 |= V_106 | ( V_106 << 8 ) ;
else
V_11 &= ~ ( V_106 | ( V_106 << 8 ) ) ;
if ( V_80 )
V_11 |= V_107 | ( V_107 << 8 ) ;
if ( type == V_92 )
V_11 |= V_108 | ( V_108 << 8 ) ;
V_11 = V_2 -> V_22 -> V_23 ( V_2 , V_101 , V_11 ) ;
if ( V_11 < 0 )
goto V_102;
}
V_11 = V_2 -> V_22 -> V_23 ( V_2 , V_74 , V_78 -> V_18 [ V_79 ] . V_109 ) ;
if ( V_11 < 0 )
goto V_102;
V_11 = V_2 -> V_22 -> V_70 ( V_2 , 0 , V_2 -> V_14 , F_45 ( V_2 -> V_14 ) ) ;
if ( V_11 < 0 )
goto V_102;
if ( V_2 -> V_14 [ V_110 ] != 0 ) {
V_2 -> V_14 [ V_110 ] = 0 ;
V_11 = V_2 -> V_22 -> V_23 ( V_2 , V_110 , 0 ) ;
if ( V_11 < 0 )
goto V_102;
}
if ( V_2 -> V_14 [ V_47 ] != 0 ) {
V_2 -> V_14 [ V_47 ] = 0 ;
V_11 = V_2 -> V_22 -> V_23 ( V_2 , V_47 , 0 ) ;
if ( V_11 < 0 )
goto V_102;
}
V_11 = F_54 ( & V_2 -> V_18 , V_2 ) ;
if ( V_11 < 0 )
goto V_102;
if ( V_2 -> V_30 && V_2 -> V_103 ) {
V_11 = F_37 ( V_2 ) ;
if ( V_11 ) {
goto V_102;
}
}
V_102:
if ( V_11 < 0 )
F_55 ( V_76 , L_19 ,
V_12 , V_11 ) ;
return V_11 ;
}
static int F_56 ( struct V_111 * V_112 ,
const struct V_113 * V_114 )
{
struct V_77 * V_78 , V_115 ;
struct V_1 * V_2 ;
int V_11 ;
const struct V_116 * V_117 ;
V_117 = F_57 ( F_58 ( V_118 ) ,
& V_112 -> V_76 ) ;
if ( V_117 ) {
V_78 = & V_115 ;
V_78 -> V_73 = - 1 ;
V_78 -> V_18 [ 0 ] . V_109 = 0 ;
V_78 -> V_103 = F_53 (
V_112 -> V_76 . V_87 ,
L_20 ) ;
V_78 -> V_80 = F_53 ( V_112 -> V_76 . V_87 ,
L_21 ) ;
V_112 -> V_30 = F_59 ( V_112 -> V_76 . V_87 , 0 ) ;
} else {
V_78 = F_60 ( & V_112 -> V_76 ) ;
if ( ! V_78 ) {
V_78 = F_61 ( & V_112 -> V_76 ,
sizeof( struct V_77 ) ,
V_119 ) ;
if ( ! V_78 )
return - V_120 ;
V_78 -> V_73 = - 1 ;
}
}
V_2 = F_62 ( sizeof( * V_2 ) , V_119 ) ;
if ( ! V_2 )
return - V_120 ;
V_2 -> V_30 = V_112 -> V_30 ;
V_11 = F_49 ( V_2 , & V_112 -> V_76 , V_112 , V_112 -> V_12 ,
V_114 -> V_121 , V_78 , 0 ) ;
if ( V_11 )
goto V_102;
F_63 ( V_112 , V_2 ) ;
return 0 ;
V_102:
F_64 ( V_2 ) ;
return V_11 ;
}
static int F_65 ( struct V_111 * V_112 )
{
struct V_1 * V_2 = F_66 ( V_112 ) ;
F_67 ( & V_2 -> V_18 ) ;
F_64 ( V_2 ) ;
return 0 ;
}
static int T_4 F_68 ( void )
{
return F_69 ( & V_122 ) ;
}
static void F_70 ( void )
{
F_71 ( & V_122 ) ;
}
static int T_4 F_68 ( void ) { return 0 ; }
static void F_70 ( void ) { }
static int F_72 ( struct V_123 * V_124 )
{
struct V_77 * V_78 , V_115 ;
unsigned V_12 ;
int V_125 = 0 ;
struct V_126 * V_4 ;
int V_11 , type ;
unsigned V_38 = 0 ;
const struct V_116 * V_117 ;
T_5 V_127 = 0 ;
V_117 = F_57 ( F_58 ( V_128 ) , & V_124 -> V_76 ) ;
if ( V_117 ) {
type = ( int ) ( V_129 ) V_117 -> V_4 ;
V_11 = F_73 ( V_124 -> V_76 . V_87 ,
L_22 , & V_127 ) ;
if ( V_11 ) {
V_11 = F_73 ( V_124 -> V_76 . V_87 ,
L_23 , & V_127 ) ;
if ( V_11 ) {
F_41 ( & V_124 -> V_76 ,
L_24 ) ;
return - V_130 ;
}
}
if ( ( V_127 <= 0 ) || ( V_127 >= 256 ) ) {
F_41 ( & V_124 -> V_76 , L_25 ) ;
return - V_130 ;
}
V_78 = & V_115 ;
V_78 -> V_73 = - 1 ;
for ( V_12 = 0 ; V_12 < F_45 ( V_78 -> V_18 ) ; V_12 ++ ) {
V_78 -> V_18 [ V_12 ] . V_109 = 0 ;
if ( V_127 & ( 1 << V_12 ) )
V_125 ++ ;
}
V_78 -> V_103 = F_53 (
V_124 -> V_76 . V_87 ,
L_20 ) ;
V_78 -> V_80 = F_53 ( V_124 -> V_76 . V_87 ,
L_21 ) ;
} else {
type = F_74 ( V_124 ) -> V_121 ;
V_78 = F_60 ( & V_124 -> V_76 ) ;
if ( ! V_78 ) {
V_78 = F_61 ( & V_124 -> V_76 ,
sizeof( struct V_77 ) ,
V_119 ) ;
V_78 -> V_73 = - 1 ;
}
for ( V_12 = 0 ; V_12 < F_45 ( V_78 -> V_18 ) ; V_12 ++ ) {
if ( ! V_78 -> V_18 [ V_12 ] . V_131 )
continue;
V_125 ++ ;
if ( ( type == V_88 ) && ( V_12 > 3 ) ) {
F_41 ( & V_124 -> V_76 ,
L_26 ) ;
return - V_15 ;
}
V_127 |= 1 << V_12 ;
}
}
if ( ! V_125 )
return - V_130 ;
V_4 = F_61 ( & V_124 -> V_76 ,
sizeof( * V_4 ) + V_125 * sizeof( struct V_1 ) ,
V_119 ) ;
if ( ! V_4 )
return - V_120 ;
F_75 ( V_124 , V_4 ) ;
V_124 -> V_30 = F_59 ( V_124 -> V_76 . V_87 , 0 ) ;
for ( V_12 = 0 ; V_12 < F_45 ( V_78 -> V_18 ) ; V_12 ++ ) {
if ( ! ( V_127 & ( 1 << V_12 ) ) )
continue;
V_125 -- ;
V_4 -> V_2 [ V_12 ] = & V_4 -> V_18 [ V_125 ] ;
V_4 -> V_2 [ V_12 ] -> V_30 = V_124 -> V_30 ;
V_11 = F_49 ( V_4 -> V_2 [ V_12 ] , & V_124 -> V_76 , V_124 ,
0x40 | ( V_12 << 1 ) , type , V_78 ,
V_12 ) ;
if ( V_11 < 0 )
goto V_102;
if ( V_78 -> V_73 != - 1 )
V_78 -> V_73 += V_4 -> V_2 [ V_12 ] -> V_18 . V_38 ;
V_38 += V_4 -> V_2 [ V_12 ] -> V_18 . V_38 ;
}
V_4 -> V_38 = V_38 ;
return 0 ;
V_102:
for ( V_12 = 0 ; V_12 < F_45 ( V_4 -> V_2 ) ; V_12 ++ ) {
if ( ! V_4 -> V_2 [ V_12 ] )
continue;
F_67 ( & V_4 -> V_2 [ V_12 ] -> V_18 ) ;
}
return V_11 ;
}
static int F_76 ( struct V_123 * V_124 )
{
struct V_126 * V_4 = F_77 ( V_124 ) ;
unsigned V_12 ;
for ( V_12 = 0 ; V_12 < F_45 ( V_4 -> V_2 ) ; V_12 ++ ) {
if ( ! V_4 -> V_2 [ V_12 ] )
continue;
F_67 ( & V_4 -> V_2 [ V_12 ] -> V_18 ) ;
}
return 0 ;
}
static int T_4 F_78 ( void )
{
return F_79 ( & V_132 ) ;
}
static void F_80 ( void )
{
F_81 ( & V_132 ) ;
}
static int T_4 F_78 ( void ) { return 0 ; }
static void F_80 ( void ) { }
static int T_4 F_82 ( void )
{
int V_8 ;
V_8 = F_78 () ;
if ( V_8 )
goto V_133;
V_8 = F_68 () ;
if ( V_8 )
goto V_134;
return 0 ;
V_134:
F_80 () ;
V_133:
return V_8 ;
}
static void T_6 F_83 ( void )
{
F_80 () ;
F_70 () ;
}
