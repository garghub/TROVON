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
struct V_1 * V_2 = F_20 ( V_18 , struct V_1 , V_18 ) ;
int V_11 ;
F_21 ( & V_2 -> V_20 ) ;
V_2 -> V_14 [ V_21 ] |= ( 1 << V_19 ) ;
V_11 = V_2 -> V_22 -> V_23 ( V_2 , V_21 , V_2 -> V_14 [ V_21 ] ) ;
F_22 ( & V_2 -> V_20 ) ;
return V_11 ;
}
static int F_23 ( struct V_17 * V_18 , unsigned V_19 )
{
struct V_1 * V_2 = F_20 ( V_18 , struct V_1 , V_18 ) ;
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
struct V_1 * V_2 = F_20 ( V_18 , struct V_1 , V_18 ) ;
unsigned V_26 = 1 << V_19 ;
F_21 ( & V_2 -> V_20 ) ;
F_24 ( V_2 , V_26 , V_27 ) ;
F_22 ( & V_2 -> V_20 ) ;
}
static int
F_26 ( struct V_17 * V_18 , unsigned V_19 , int V_27 )
{
struct V_1 * V_2 = F_20 ( V_18 , struct V_1 , V_18 ) ;
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
( V_2 -> V_40 & ~ V_31 & F_28 ( V_33 ) ) ) ) {
V_34 = F_29 ( V_2 -> V_41 , V_33 ) ;
F_30 ( V_34 ) ;
}
}
return V_36 ;
}
static int F_31 ( struct V_17 * V_18 , unsigned V_19 )
{
struct V_1 * V_2 = F_20 ( V_18 , struct V_1 , V_18 ) ;
return F_29 ( V_2 -> V_41 , V_19 ) ;
}
static void F_32 ( struct V_42 * V_4 )
{
struct V_1 * V_2 = F_33 ( V_4 ) ;
unsigned int V_43 = V_4 -> V_44 ;
V_2 -> V_14 [ V_45 ] &= ~ F_28 ( V_43 ) ;
}
static void F_34 ( struct V_42 * V_4 )
{
struct V_1 * V_2 = F_33 ( V_4 ) ;
unsigned int V_43 = V_4 -> V_44 ;
V_2 -> V_14 [ V_45 ] |= F_28 ( V_43 ) ;
}
static int F_35 ( struct V_42 * V_4 , unsigned int type )
{
struct V_1 * V_2 = F_33 ( V_4 ) ;
unsigned int V_43 = V_4 -> V_44 ;
int V_11 = 0 ;
if ( ( type & V_46 ) == V_46 ) {
V_2 -> V_14 [ V_47 ] &= ~ F_28 ( V_43 ) ;
V_2 -> V_39 |= F_28 ( V_43 ) ;
V_2 -> V_40 |= F_28 ( V_43 ) ;
} else if ( type & V_48 ) {
V_2 -> V_14 [ V_47 ] &= ~ F_28 ( V_43 ) ;
V_2 -> V_39 |= F_28 ( V_43 ) ;
V_2 -> V_40 &= ~ F_28 ( V_43 ) ;
} else if ( type & V_49 ) {
V_2 -> V_14 [ V_47 ] &= ~ F_28 ( V_43 ) ;
V_2 -> V_39 &= ~ F_28 ( V_43 ) ;
V_2 -> V_40 |= F_28 ( V_43 ) ;
} else
return - V_15 ;
return V_11 ;
}
static void F_36 ( struct V_42 * V_4 )
{
struct V_1 * V_2 = F_33 ( V_4 ) ;
F_21 ( & V_2 -> V_50 ) ;
}
static void F_37 ( struct V_42 * V_4 )
{
struct V_1 * V_2 = F_33 ( V_4 ) ;
F_21 ( & V_2 -> V_20 ) ;
V_2 -> V_22 -> V_23 ( V_2 , V_45 , V_2 -> V_14 [ V_45 ] ) ;
V_2 -> V_22 -> V_23 ( V_2 , V_51 , V_2 -> V_14 [ V_51 ] ) ;
V_2 -> V_22 -> V_23 ( V_2 , V_47 , V_2 -> V_14 [ V_47 ] ) ;
F_22 ( & V_2 -> V_20 ) ;
F_22 ( & V_2 -> V_50 ) ;
}
static int F_38 ( struct V_42 * V_4 )
{
struct V_1 * V_2 = F_33 ( V_4 ) ;
if ( F_39 ( & V_2 -> V_18 , V_4 -> V_44 ) ) {
F_40 ( V_2 -> V_18 . V_52 ,
L_1 ,
V_4 -> V_44 ) ;
return - V_15 ;
}
return 0 ;
}
static void F_41 ( struct V_42 * V_4 )
{
struct V_1 * V_2 = F_33 ( V_4 ) ;
F_42 ( & V_2 -> V_18 , V_4 -> V_44 ) ;
}
static int F_43 ( struct V_1 * V_2 )
{
struct V_17 * V_18 = & V_2 -> V_18 ;
int V_53 , V_30 , V_54 ;
unsigned long V_55 = V_56 | V_57 ;
F_44 ( & V_2 -> V_50 ) ;
V_2 -> V_41 = F_45 ( V_18 -> V_52 -> V_58 , V_18 -> V_38 ,
& V_59 , V_2 ) ;
if ( ! V_2 -> V_41 )
return - V_60 ;
if ( V_2 -> V_61 )
V_55 |= V_62 ;
else
V_55 |= V_63 ;
V_53 = F_46 ( V_18 -> V_52 , V_2 -> V_30 , NULL , F_27 ,
V_55 , F_47 ( V_18 -> V_52 ) , V_2 ) ;
if ( V_53 != 0 ) {
F_40 ( V_18 -> V_52 , L_2 ,
V_2 -> V_30 , V_53 ) ;
return V_53 ;
}
V_18 -> V_64 = F_31 ;
for ( V_54 = 0 ; V_54 < V_2 -> V_18 . V_38 ; V_54 ++ ) {
V_30 = F_48 ( V_2 -> V_41 , V_54 ) ;
F_49 ( V_30 , & V_65 ) ;
F_50 ( V_30 , V_2 ) ;
F_51 ( V_30 , & V_66 ) ;
F_52 ( V_30 , true ) ;
F_53 ( V_30 ) ;
}
return 0 ;
}
static void F_54 ( struct V_1 * V_2 )
{
unsigned int V_30 , V_33 ;
for ( V_33 = 0 ; V_33 < V_2 -> V_18 . V_38 ; V_33 ++ ) {
V_30 = F_29 ( V_2 -> V_41 , V_33 ) ;
if ( V_30 > 0 )
F_55 ( V_30 ) ;
}
F_56 ( V_2 -> V_41 ) ;
}
static void F_57 ( struct V_67 * V_68 , struct V_17 * V_18 )
{
struct V_1 * V_2 ;
char V_69 ;
int V_70 ;
unsigned V_26 ;
V_2 = F_20 ( V_18 , struct V_1 , V_18 ) ;
V_69 = '0' + ( ( V_2 -> V_12 >> 1 ) & 0x7 ) ;
F_21 ( & V_2 -> V_20 ) ;
V_70 = V_2 -> V_22 -> V_71 ( V_2 , 0 , V_2 -> V_14 , F_58 ( V_2 -> V_14 ) ) ;
if ( V_70 < 0 ) {
F_59 ( V_68 , L_3 , V_70 ) ;
goto V_72;
}
for ( V_70 = 0 , V_26 = 1 ; V_70 < V_18 -> V_38 ; V_70 ++ , V_26 <<= 1 ) {
const char * V_73 ;
V_73 = F_60 ( V_18 , V_70 ) ;
if ( ! V_73 )
continue;
F_59 ( V_68 , L_4 ,
V_18 -> V_74 + V_70 , V_69 , V_70 , V_73 ,
( V_2 -> V_14 [ V_21 ] & V_26 ) ? L_5 : L_6 ,
( V_2 -> V_14 [ V_25 ] & V_26 ) ? L_7 : L_8 ,
( V_2 -> V_14 [ V_75 ] & V_26 ) ? L_9 : L_10 ) ;
F_61 ( V_68 , L_11 ) ;
}
V_72:
F_22 ( & V_2 -> V_20 ) ;
}
static int F_62 ( struct V_1 * V_2 , struct V_76 * V_52 ,
void * V_4 , unsigned V_12 , unsigned type ,
struct V_77 * V_78 , int V_79 )
{
int V_11 ;
bool V_80 = false ;
F_44 ( & V_2 -> V_20 ) ;
V_2 -> V_4 = V_4 ;
V_2 -> V_12 = V_12 ;
V_2 -> V_61 = false ;
V_2 -> V_18 . V_81 = F_19 ;
V_2 -> V_18 . V_82 = F_23 ;
V_2 -> V_18 . V_83 = F_26 ;
V_2 -> V_18 . V_84 = F_25 ;
V_2 -> V_18 . V_85 = F_57 ;
#ifdef F_63
V_2 -> V_18 . V_86 = 2 ;
V_2 -> V_18 . V_58 = V_52 -> V_58 ;
#endif
switch ( type ) {
#ifdef F_64
case V_87 :
V_2 -> V_22 = & V_88 ;
V_2 -> V_18 . V_38 = 8 ;
V_2 -> V_18 . V_73 = L_12 ;
break;
case V_89 :
V_2 -> V_22 = & V_90 ;
V_2 -> V_18 . V_38 = 16 ;
V_2 -> V_18 . V_73 = L_13 ;
break;
#endif
#if F_65 ( V_91 )
case V_92 :
V_2 -> V_22 = & V_93 ;
V_2 -> V_18 . V_38 = 8 ;
V_2 -> V_18 . V_73 = L_14 ;
break;
case V_94 :
V_2 -> V_22 = & V_95 ;
V_2 -> V_18 . V_38 = 16 ;
V_2 -> V_18 . V_73 = L_15 ;
break;
#endif
default:
F_40 ( V_52 , L_16 , type ) ;
return - V_15 ;
}
V_2 -> V_18 . V_74 = V_78 -> V_74 ;
V_2 -> V_18 . V_96 = true ;
V_2 -> V_18 . V_52 = V_52 ;
V_2 -> V_18 . V_97 = V_98 ;
V_11 = V_2 -> V_22 -> V_24 ( V_2 , V_99 ) ;
if ( V_11 < 0 )
goto V_100;
V_2 -> V_101 = V_78 -> V_101 ;
if ( V_2 -> V_30 && V_2 -> V_101 ) {
V_2 -> V_61 =
F_66 ( V_2 -> V_18 . V_52 -> V_58 ,
L_17 ) ;
if ( type == V_94 )
V_80 = V_78 -> V_80 ;
}
if ( ( V_11 & V_102 ) || ! ( V_11 & V_103 ) || V_80 ||
V_2 -> V_61 ) {
V_11 &= ~ ( V_102 | ( V_102 << 8 ) ) ;
V_11 |= V_103 | ( V_103 << 8 ) ;
if ( V_2 -> V_61 )
V_11 |= V_104 | ( V_104 << 8 ) ;
else
V_11 &= ~ ( V_104 | ( V_104 << 8 ) ) ;
if ( V_80 )
V_11 |= V_105 | ( V_105 << 8 ) ;
V_11 = V_2 -> V_22 -> V_23 ( V_2 , V_99 , V_11 ) ;
if ( V_11 < 0 )
goto V_100;
}
V_11 = V_2 -> V_22 -> V_23 ( V_2 , V_75 , V_78 -> V_18 [ V_79 ] . V_106 ) ;
if ( V_11 < 0 )
goto V_100;
V_11 = V_2 -> V_22 -> V_71 ( V_2 , 0 , V_2 -> V_14 , F_58 ( V_2 -> V_14 ) ) ;
if ( V_11 < 0 )
goto V_100;
if ( V_2 -> V_14 [ V_107 ] != 0 ) {
V_2 -> V_14 [ V_107 ] = 0 ;
V_11 = V_2 -> V_22 -> V_23 ( V_2 , V_107 , 0 ) ;
if ( V_11 < 0 )
goto V_100;
}
if ( V_2 -> V_14 [ V_45 ] != 0 ) {
V_2 -> V_14 [ V_45 ] = 0 ;
V_11 = V_2 -> V_22 -> V_23 ( V_2 , V_45 , 0 ) ;
if ( V_11 < 0 )
goto V_100;
}
V_11 = F_67 ( & V_2 -> V_18 ) ;
if ( V_11 < 0 )
goto V_100;
if ( V_2 -> V_30 && V_2 -> V_101 ) {
V_11 = F_43 ( V_2 ) ;
if ( V_11 ) {
F_54 ( V_2 ) ;
goto V_100;
}
}
V_100:
if ( V_11 < 0 )
F_68 ( V_52 , L_18 ,
V_12 , V_11 ) ;
return V_11 ;
}
static int F_69 ( struct V_108 * V_109 ,
const struct V_110 * V_111 )
{
struct V_77 * V_78 , V_112 ;
struct V_1 * V_2 ;
int V_11 ;
const struct V_113 * V_114 ;
V_114 = F_70 ( F_71 ( V_115 ) ,
& V_109 -> V_52 ) ;
if ( V_114 ) {
V_78 = & V_112 ;
V_78 -> V_74 = - 1 ;
V_78 -> V_18 [ 0 ] . V_106 = 0 ;
V_78 -> V_101 = F_66 (
V_109 -> V_52 . V_58 ,
L_19 ) ;
V_78 -> V_80 = F_66 ( V_109 -> V_52 . V_58 ,
L_20 ) ;
V_109 -> V_30 = F_72 ( V_109 -> V_52 . V_58 , 0 ) ;
} else {
V_78 = F_73 ( & V_109 -> V_52 ) ;
if ( ! V_78 ) {
V_78 = F_74 ( & V_109 -> V_52 ,
sizeof( struct V_77 ) ,
V_116 ) ;
V_78 -> V_74 = - 1 ;
}
}
V_2 = F_75 ( sizeof( * V_2 ) , V_116 ) ;
if ( ! V_2 )
return - V_117 ;
V_2 -> V_30 = V_109 -> V_30 ;
V_11 = F_62 ( V_2 , & V_109 -> V_52 , V_109 , V_109 -> V_12 ,
V_111 -> V_118 , V_78 , 0 ) ;
if ( V_11 )
goto V_100;
F_76 ( V_109 , V_2 ) ;
return 0 ;
V_100:
F_77 ( V_2 ) ;
return V_11 ;
}
static int F_78 ( struct V_108 * V_109 )
{
struct V_1 * V_2 = F_79 ( V_109 ) ;
if ( V_109 -> V_30 && V_2 -> V_101 )
F_54 ( V_2 ) ;
F_80 ( & V_2 -> V_18 ) ;
F_77 ( V_2 ) ;
return 0 ;
}
static int T_4 F_81 ( void )
{
return F_82 ( & V_119 ) ;
}
static void F_83 ( void )
{
F_84 ( & V_119 ) ;
}
static int T_4 F_81 ( void ) { return 0 ; }
static void F_83 ( void ) { }
static int F_85 ( struct V_120 * V_121 )
{
struct V_77 * V_78 , V_112 ;
unsigned V_12 ;
int V_122 = 0 ;
struct V_123 * V_4 ;
int V_11 , type ;
unsigned V_38 = 0 ;
const struct V_113 * V_114 ;
T_5 V_124 = 0 ;
V_114 = F_70 ( F_71 ( V_125 ) , & V_121 -> V_52 ) ;
if ( V_114 ) {
type = ( int ) ( V_126 ) V_114 -> V_4 ;
V_11 = F_86 ( V_121 -> V_52 . V_58 ,
L_21 , & V_124 ) ;
if ( V_11 ) {
V_11 = F_86 ( V_121 -> V_52 . V_58 ,
L_22 , & V_124 ) ;
if ( V_11 ) {
F_40 ( & V_121 -> V_52 ,
L_23 ) ;
return - V_60 ;
}
}
if ( ( V_124 <= 0 ) || ( V_124 >= 256 ) ) {
F_40 ( & V_121 -> V_52 , L_24 ) ;
return - V_60 ;
}
V_78 = & V_112 ;
V_78 -> V_74 = - 1 ;
for ( V_12 = 0 ; V_12 < F_58 ( V_78 -> V_18 ) ; V_12 ++ ) {
V_78 -> V_18 [ V_12 ] . V_106 = 0 ;
if ( V_124 & ( 1 << V_12 ) )
V_122 ++ ;
}
V_78 -> V_101 = F_66 (
V_121 -> V_52 . V_58 ,
L_19 ) ;
V_78 -> V_80 = F_66 ( V_121 -> V_52 . V_58 ,
L_20 ) ;
} else {
type = F_87 ( V_121 ) -> V_118 ;
V_78 = F_73 ( & V_121 -> V_52 ) ;
if ( ! V_78 ) {
V_78 = F_74 ( & V_121 -> V_52 ,
sizeof( struct V_77 ) ,
V_116 ) ;
V_78 -> V_74 = - 1 ;
}
for ( V_12 = 0 ; V_12 < F_58 ( V_78 -> V_18 ) ; V_12 ++ ) {
if ( ! V_78 -> V_18 [ V_12 ] . V_127 )
continue;
V_122 ++ ;
if ( ( type == V_87 ) && ( V_12 > 3 ) ) {
F_40 ( & V_121 -> V_52 ,
L_25 ) ;
return - V_15 ;
}
V_124 |= 1 << V_12 ;
}
}
if ( ! V_122 )
return - V_60 ;
V_4 = F_74 ( & V_121 -> V_52 ,
sizeof( * V_4 ) + V_122 * sizeof( struct V_1 ) ,
V_116 ) ;
if ( ! V_4 )
return - V_117 ;
F_88 ( V_121 , V_4 ) ;
V_121 -> V_30 = F_72 ( V_121 -> V_52 . V_58 , 0 ) ;
for ( V_12 = 0 ; V_12 < F_58 ( V_78 -> V_18 ) ; V_12 ++ ) {
if ( ! ( V_124 & ( 1 << V_12 ) ) )
continue;
V_122 -- ;
V_4 -> V_2 [ V_12 ] = & V_4 -> V_18 [ V_122 ] ;
V_4 -> V_2 [ V_12 ] -> V_30 = V_121 -> V_30 ;
V_11 = F_62 ( V_4 -> V_2 [ V_12 ] , & V_121 -> V_52 , V_121 ,
0x40 | ( V_12 << 1 ) , type , V_78 ,
V_12 ) ;
if ( V_11 < 0 )
goto V_100;
if ( V_78 -> V_74 != - 1 )
V_78 -> V_74 += ( type == V_89 ) ? 16 : 8 ;
V_38 += ( type == V_89 ) ? 16 : 8 ;
}
V_4 -> V_38 = V_38 ;
return 0 ;
V_100:
for ( V_12 = 0 ; V_12 < F_58 ( V_4 -> V_2 ) ; V_12 ++ ) {
if ( ! V_4 -> V_2 [ V_12 ] )
continue;
F_80 ( & V_4 -> V_2 [ V_12 ] -> V_18 ) ;
}
return V_11 ;
}
static int F_89 ( struct V_120 * V_121 )
{
struct V_123 * V_4 = F_90 ( V_121 ) ;
unsigned V_12 ;
for ( V_12 = 0 ; V_12 < F_58 ( V_4 -> V_2 ) ; V_12 ++ ) {
if ( ! V_4 -> V_2 [ V_12 ] )
continue;
if ( V_121 -> V_30 && V_4 -> V_2 [ V_12 ] -> V_101 )
F_54 ( V_4 -> V_2 [ V_12 ] ) ;
F_80 ( & V_4 -> V_2 [ V_12 ] -> V_18 ) ;
}
return 0 ;
}
static int T_4 F_91 ( void )
{
return F_92 ( & V_128 ) ;
}
static void F_93 ( void )
{
F_94 ( & V_128 ) ;
}
static int T_4 F_91 ( void ) { return 0 ; }
static void F_93 ( void ) { }
static int T_4 F_95 ( void )
{
int V_8 ;
V_8 = F_91 () ;
if ( V_8 )
goto V_129;
V_8 = F_81 () ;
if ( V_8 )
goto V_130;
return 0 ;
V_130:
F_93 () ;
V_129:
return V_8 ;
}
static void T_6 F_96 ( void )
{
F_93 () ;
F_83 () ;
}
