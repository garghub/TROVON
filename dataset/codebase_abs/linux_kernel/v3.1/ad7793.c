static int F_1 ( struct V_1 * V_2 , bool V_3 ,
bool V_4 , unsigned char V_5 ,
unsigned V_6 , unsigned V_7 )
{
T_1 * V_8 = V_2 -> V_8 ;
struct V_9 V_10 = {
. V_11 = V_8 ,
. V_12 = V_6 + 1 ,
. V_4 = V_4 ,
} ;
struct V_13 V_14 ;
V_8 [ 0 ] = V_15 | F_2 ( V_5 ) ;
switch ( V_6 ) {
case 3 :
V_8 [ 1 ] = V_7 >> 16 ;
V_8 [ 2 ] = V_7 >> 8 ;
V_8 [ 3 ] = V_7 ;
break;
case 2 :
V_8 [ 1 ] = V_7 >> 8 ;
V_8 [ 2 ] = V_7 ;
break;
case 1 :
V_8 [ 1 ] = V_7 ;
break;
default:
return - V_16 ;
}
F_3 ( & V_14 ) ;
F_4 ( & V_10 , & V_14 ) ;
if ( V_3 )
return F_5 ( V_2 -> V_17 , & V_14 ) ;
else
return F_6 ( V_2 -> V_17 , & V_14 ) ;
}
static int F_7 ( struct V_1 * V_2 ,
unsigned V_5 , unsigned V_6 , unsigned V_7 )
{
return F_1 ( V_2 , false , false , V_5 , V_6 , V_7 ) ;
}
static int F_8 ( struct V_1 * V_2 , bool V_3 ,
bool V_4 , unsigned char V_5 ,
int * V_7 , unsigned V_6 )
{
T_1 * V_8 = V_2 -> V_8 ;
int V_18 ;
struct V_9 V_10 [] = {
{
. V_11 = V_8 ,
. V_12 = 1 ,
} , {
. V_19 = V_8 ,
. V_12 = V_6 ,
. V_4 = V_4 ,
} ,
} ;
struct V_13 V_14 ;
V_8 [ 0 ] = V_20 | F_2 ( V_5 ) ;
F_3 ( & V_14 ) ;
F_4 ( & V_10 [ 0 ] , & V_14 ) ;
F_4 ( & V_10 [ 1 ] , & V_14 ) ;
if ( V_3 )
V_18 = F_5 ( V_2 -> V_17 , & V_14 ) ;
else
V_18 = F_6 ( V_2 -> V_17 , & V_14 ) ;
if ( V_18 < 0 )
return V_18 ;
switch ( V_6 ) {
case 3 :
* V_7 = V_8 [ 0 ] << 16 | V_8 [ 1 ] << 8 | V_8 [ 2 ] ;
break;
case 2 :
* V_7 = V_8 [ 0 ] << 8 | V_8 [ 1 ] ;
break;
case 1 :
* V_7 = V_8 [ 0 ] ;
break;
default:
return - V_16 ;
}
return 0 ;
}
static int F_9 ( struct V_1 * V_2 ,
unsigned V_5 , int * V_7 , unsigned V_6 )
{
return F_8 ( V_2 , 0 , 0 , V_5 , V_7 , V_6 ) ;
}
static int F_10 ( struct V_1 * V_2 , unsigned V_21 ,
unsigned V_12 , int * V_7 )
{
int V_18 ;
V_2 -> V_22 = ( V_2 -> V_22 & ~ F_11 ( - 1 ) ) | F_11 ( V_21 ) ;
V_2 -> V_23 = ( V_2 -> V_23 & ~ F_12 ( - 1 ) ) |
F_12 ( V_24 ) ;
F_7 ( V_2 , V_25 , sizeof( V_2 -> V_22 ) , V_2 -> V_22 ) ;
F_13 ( V_2 -> V_17 -> V_26 ) ;
V_2 -> V_27 = false ;
V_18 = F_1 ( V_2 , 1 , 1 , V_28 ,
sizeof( V_2 -> V_23 ) , V_2 -> V_23 ) ;
if ( V_18 < 0 )
goto V_29;
V_2 -> V_30 = false ;
F_14 ( V_2 -> V_17 -> V_31 ) ;
F_15 ( V_2 -> V_32 , V_2 -> V_27 ) ;
V_18 = F_8 ( V_2 , 1 , 0 , V_33 , V_7 , V_12 ) ;
V_29:
F_16 ( V_2 -> V_17 -> V_26 ) ;
return V_18 ;
}
static int F_17 ( struct V_1 * V_2 , unsigned V_23 , unsigned V_21 )
{
int V_18 ;
V_2 -> V_22 = ( V_2 -> V_22 & ~ F_11 ( - 1 ) ) | F_11 ( V_21 ) ;
V_2 -> V_23 = ( V_2 -> V_23 & ~ F_12 ( - 1 ) ) | F_12 ( V_23 ) ;
F_7 ( V_2 , V_25 , sizeof( V_2 -> V_22 ) , V_2 -> V_22 ) ;
F_13 ( V_2 -> V_17 -> V_26 ) ;
V_2 -> V_27 = false ;
V_18 = F_1 ( V_2 , 1 , 1 , V_28 ,
sizeof( V_2 -> V_23 ) , V_2 -> V_23 ) ;
if ( V_18 < 0 )
goto V_29;
V_2 -> V_30 = false ;
F_14 ( V_2 -> V_17 -> V_31 ) ;
F_15 ( V_2 -> V_32 , V_2 -> V_27 ) ;
V_2 -> V_23 = ( V_2 -> V_23 & ~ F_12 ( - 1 ) ) |
F_12 ( V_34 ) ;
V_18 = F_1 ( V_2 , 1 , 0 , V_28 ,
sizeof( V_2 -> V_23 ) , V_2 -> V_23 ) ;
V_29:
F_16 ( V_2 -> V_17 -> V_26 ) ;
return V_18 ;
}
static int F_18 ( struct V_1 * V_2 )
{
int V_35 , V_18 ;
for ( V_35 = 0 ; V_35 < F_19 ( V_36 ) ; V_35 ++ ) {
V_18 = F_17 ( V_2 , V_36 [ V_35 ] [ 0 ] ,
V_36 [ V_35 ] [ 1 ] ) ;
if ( V_18 )
goto V_29;
}
return 0 ;
V_29:
F_20 ( & V_2 -> V_17 -> V_37 , L_1 ) ;
return V_18 ;
}
static int F_21 ( struct V_1 * V_2 )
{
int V_35 , V_18 = - 1 ;
unsigned long long V_38 ;
T_2 V_39 ;
V_18 = F_22 ( V_2 -> V_17 , ( T_1 * ) & V_18 , sizeof( V_18 ) ) ;
if ( V_18 < 0 )
goto V_29;
F_23 ( 1 ) ;
V_18 = F_9 ( V_2 , V_40 , & V_39 , 1 ) ;
if ( V_18 )
goto V_29;
V_39 &= V_41 ;
if ( ! ( ( V_39 == V_42 ) || ( V_39 == V_43 ) ) ) {
F_20 ( & V_2 -> V_17 -> V_37 , L_2 ) ;
goto V_29;
}
V_2 -> V_23 = ( V_2 -> V_44 -> V_23 & ~ F_12 ( - 1 ) ) |
F_12 ( V_34 ) ;
V_2 -> V_22 = V_2 -> V_44 -> V_22 & ~ F_11 ( - 1 ) ;
V_18 = F_7 ( V_2 , V_28 , sizeof( V_2 -> V_23 ) , V_2 -> V_23 ) ;
if ( V_18 )
goto V_29;
V_18 = F_7 ( V_2 , V_25 , sizeof( V_2 -> V_22 ) , V_2 -> V_22 ) ;
if ( V_18 )
goto V_29;
V_18 = F_7 ( V_2 , V_45 ,
sizeof( V_2 -> V_44 -> V_46 ) , V_2 -> V_44 -> V_46 ) ;
if ( V_18 )
goto V_29;
V_18 = F_18 ( V_2 ) ;
if ( V_18 )
goto V_29;
for ( V_35 = 0 ; V_35 < F_19 ( V_2 -> V_47 ) ; V_35 ++ ) {
V_38 = ( ( V_48 ) V_2 -> V_49 * 100000000 )
>> ( V_2 -> V_50 -> V_51 [ 0 ] . V_52 . V_53 -
( ! ! ( V_2 -> V_22 & V_54 ) ? 0 : 1 ) ) ;
V_38 >>= V_35 ;
V_2 -> V_47 [ V_35 ] [ 1 ] = F_24 ( V_38 , 100000000 ) * 10 ;
V_2 -> V_47 [ V_35 ] [ 0 ] = V_38 ;
}
return 0 ;
V_29:
F_20 ( & V_2 -> V_17 -> V_37 , L_3 ) ;
return V_18 ;
}
static int F_25 ( struct V_1 * V_2 , unsigned V_21 , int * V_7 )
{
struct V_55 * V_56 = F_26 ( V_2 ) -> V_56 ;
int V_18 ;
T_3 V_57 [ 2 ] ;
T_2 * V_58 = ( T_2 * ) V_57 ;
if ( ! ( V_56 -> V_59 & ( 1 << V_21 ) ) )
return - V_60 ;
V_18 = V_56 -> V_61 -> V_62 ( V_56 , ( T_1 * ) & V_57 ) ;
if ( V_18 )
return V_18 ;
* V_7 = * V_58 ;
return 0 ;
}
static int F_27 ( struct V_63 * V_64 )
{
struct V_1 * V_2 = F_28 ( V_64 ) ;
struct V_55 * V_56 = V_64 -> V_56 ;
T_4 V_65 ;
unsigned V_51 ;
if ( ! V_56 -> V_66 )
return - V_16 ;
V_51 = F_29 ( V_56 -> V_59 ) ;
V_65 = V_56 -> V_66 *
V_64 -> V_67 [ 0 ] . V_52 . V_68 / 8 ;
if ( V_56 -> V_69 ) {
V_65 += sizeof( T_3 ) ;
if ( V_65 % sizeof( T_3 ) )
V_65 += sizeof( T_3 ) - ( V_65 % sizeof( T_3 ) ) ;
}
if ( V_64 -> V_56 -> V_61 -> V_70 )
V_64 -> V_56 -> V_61 -> V_70 ( V_64 -> V_56 ,
V_65 ) ;
V_2 -> V_23 = ( V_2 -> V_23 & ~ F_12 ( - 1 ) ) |
F_12 ( V_71 ) ;
V_2 -> V_22 = ( V_2 -> V_22 & ~ F_11 ( - 1 ) ) |
F_11 ( V_64 -> V_67 [ V_51 ] . V_72 ) ;
F_7 ( V_2 , V_25 , sizeof( V_2 -> V_22 ) , V_2 -> V_22 ) ;
F_13 ( V_2 -> V_17 -> V_26 ) ;
F_1 ( V_2 , 1 , 1 , V_28 ,
sizeof( V_2 -> V_23 ) , V_2 -> V_23 ) ;
V_2 -> V_30 = false ;
F_14 ( V_2 -> V_17 -> V_31 ) ;
return 0 ;
}
static int F_30 ( struct V_63 * V_64 )
{
struct V_1 * V_2 = F_28 ( V_64 ) ;
V_2 -> V_23 = ( V_2 -> V_23 & ~ F_12 ( - 1 ) ) |
F_12 ( V_34 ) ;
V_2 -> V_27 = false ;
F_15 ( V_2 -> V_32 , V_2 -> V_27 ) ;
if ( ! V_2 -> V_30 )
F_31 ( V_2 -> V_17 -> V_31 ) ;
F_1 ( V_2 , 1 , 0 , V_28 ,
sizeof( V_2 -> V_23 ) , V_2 -> V_23 ) ;
return F_16 ( V_2 -> V_17 -> V_26 ) ;
}
static T_5 F_32 ( int V_31 , void * V_73 )
{
struct V_74 * V_75 = V_73 ;
struct V_63 * V_64 = V_75 -> V_76 ;
struct V_55 * V_56 = V_64 -> V_56 ;
struct V_1 * V_2 = F_28 ( V_64 ) ;
T_3 V_57 [ 2 ] ;
T_6 * V_58 = ( T_6 * ) V_57 ;
if ( V_56 -> V_66 )
F_8 ( V_2 , 1 , 1 , V_33 ,
V_58 ,
V_64 -> V_67 [ 0 ] . V_52 . V_53 / 8 ) ;
if ( V_56 -> V_69 )
V_57 [ 1 ] = V_75 -> V_77 ;
V_56 -> V_61 -> V_78 ( V_56 , ( T_1 * ) V_57 , V_75 -> V_77 ) ;
F_33 ( V_64 -> V_79 ) ;
V_2 -> V_30 = false ;
F_14 ( V_2 -> V_17 -> V_31 ) ;
return V_80 ;
}
static int F_34 ( struct V_63 * V_64 )
{
int V_18 ;
V_64 -> V_56 = F_35 ( V_64 ) ;
if ( ! V_64 -> V_56 ) {
V_18 = - V_81 ;
goto V_82;
}
V_64 -> V_56 -> V_61 = & V_83 ;
V_64 -> V_84 = F_36 ( & V_85 ,
& F_32 ,
V_86 ,
V_64 ,
L_4 ,
V_64 -> V_39 ) ;
if ( V_64 -> V_84 == NULL ) {
V_18 = - V_81 ;
goto V_87;
}
V_64 -> V_56 -> V_88 = & V_89 ;
V_64 -> V_90 |= V_91 ;
return 0 ;
V_87:
F_37 ( V_64 -> V_56 ) ;
V_82:
return V_18 ;
}
static void F_38 ( struct V_63 * V_64 )
{
if ( V_64 -> V_79 ) {
F_39 ( V_64 -> V_79 ) ;
F_40 ( V_64 -> V_79 ,
V_64 -> V_84 ) ;
}
F_41 ( V_64 -> V_84 ) ;
F_37 ( V_64 -> V_56 ) ;
}
static T_5 F_42 ( int V_31 , void * V_92 )
{
struct V_1 * V_2 = F_28 ( V_92 ) ;
V_2 -> V_27 = true ;
F_43 ( & V_2 -> V_32 ) ;
F_31 ( V_31 ) ;
V_2 -> V_30 = true ;
F_44 ( V_2 -> V_79 , F_45 () ) ;
return V_80 ;
}
static int F_46 ( struct V_63 * V_64 )
{
struct V_1 * V_2 = F_28 ( V_64 ) ;
int V_18 ;
V_2 -> V_79 = F_47 ( L_5 ,
F_48 ( V_2 -> V_17 ) -> V_93 ,
V_64 -> V_39 ) ;
if ( V_2 -> V_79 == NULL ) {
V_18 = - V_81 ;
goto V_82;
}
V_18 = F_49 ( V_2 -> V_17 -> V_31 ,
F_42 ,
V_94 ,
F_48 ( V_2 -> V_17 ) -> V_93 ,
V_64 ) ;
if ( V_18 )
goto V_95;
F_31 ( V_2 -> V_17 -> V_31 ) ;
V_2 -> V_30 = true ;
V_2 -> V_79 -> V_37 . V_96 = & V_2 -> V_17 -> V_37 ;
V_2 -> V_79 -> V_97 = V_98 ;
V_2 -> V_79 -> V_76 = V_64 ;
V_18 = F_50 ( V_2 -> V_79 ) ;
V_64 -> V_79 = V_2 -> V_79 ;
if ( V_18 )
goto V_99;
return 0 ;
V_99:
F_51 ( V_2 -> V_17 -> V_31 , V_64 ) ;
V_95:
F_52 ( V_2 -> V_79 ) ;
V_82:
return V_18 ;
}
static void F_53 ( struct V_63 * V_64 )
{
struct V_1 * V_2 = F_28 ( V_64 ) ;
F_54 ( V_2 -> V_79 ) ;
F_51 ( V_2 -> V_17 -> V_31 , V_64 ) ;
F_52 ( V_2 -> V_79 ) ;
}
static T_7 F_55 ( struct V_100 * V_37 ,
struct V_101 * V_102 ,
char * V_103 )
{
struct V_63 * V_64 = F_56 ( V_37 ) ;
struct V_1 * V_2 = F_28 ( V_64 ) ;
return sprintf ( V_103 , L_6 ,
V_104 [ F_57 ( V_2 -> V_23 ) ] ) ;
}
static T_7 F_58 ( struct V_100 * V_37 ,
struct V_101 * V_102 ,
const char * V_103 ,
T_4 V_12 )
{
struct V_63 * V_64 = F_56 ( V_37 ) ;
struct V_1 * V_2 = F_28 ( V_64 ) ;
long V_105 ;
int V_35 , V_18 ;
F_59 ( & V_64 -> V_106 ) ;
if ( F_60 ( V_64 ) ) {
F_61 ( & V_64 -> V_106 ) ;
return - V_60 ;
}
F_61 ( & V_64 -> V_106 ) ;
V_18 = F_62 ( V_103 , 10 , & V_105 ) ;
if ( V_18 )
return V_18 ;
V_18 = - V_16 ;
for ( V_35 = 0 ; V_35 < F_19 ( V_104 ) ; V_35 ++ )
if ( V_105 == V_104 [ V_35 ] ) {
F_59 ( & V_64 -> V_106 ) ;
V_2 -> V_23 &= ~ F_57 ( - 1 ) ;
V_2 -> V_23 |= F_57 ( V_35 ) ;
F_7 ( V_2 , V_28 ,
sizeof( V_2 -> V_23 ) , V_2 -> V_23 ) ;
F_61 ( & V_64 -> V_106 ) ;
V_18 = 0 ;
}
return V_18 ? V_18 : V_12 ;
}
static T_7 F_63 ( struct V_100 * V_37 ,
struct V_101 * V_102 , char * V_103 )
{
struct V_63 * V_64 = F_56 ( V_37 ) ;
struct V_1 * V_2 = F_28 ( V_64 ) ;
int V_35 , V_12 = 0 ;
for ( V_35 = 0 ; V_35 < F_19 ( V_2 -> V_47 ) ; V_35 ++ )
V_12 += sprintf ( V_103 + V_12 , L_7 , V_2 -> V_47 [ V_35 ] [ 0 ] ,
V_2 -> V_47 [ V_35 ] [ 1 ] ) ;
V_12 += sprintf ( V_103 + V_12 , L_8 ) ;
return V_12 ;
}
static int F_64 ( struct V_63 * V_64 ,
struct V_107 const * V_108 ,
int * V_7 ,
int * V_109 ,
long V_14 )
{
struct V_1 * V_2 = F_28 ( V_64 ) ;
int V_18 , V_110 = 0 ;
unsigned long long V_38 ;
bool V_111 = ! ! ( V_2 -> V_22 & V_54 ) ;
switch ( V_14 ) {
case 0 :
F_59 ( & V_64 -> V_106 ) ;
if ( F_60 ( V_64 ) )
V_18 = F_25 ( V_2 ,
V_108 -> V_112 , & V_110 ) ;
else
V_18 = F_10 ( V_2 , V_108 -> V_72 ,
V_108 -> V_52 . V_53 / 8 , & V_110 ) ;
F_61 ( & V_64 -> V_106 ) ;
if ( V_18 < 0 )
return V_18 ;
* V_7 = ( V_110 >> V_108 -> V_52 . V_113 ) &
( ( 1 << ( V_108 -> V_52 . V_53 ) ) - 1 ) ;
if ( ! V_111 )
* V_7 -= ( 1 << ( V_108 -> V_52 . V_53 - 1 ) ) ;
return V_114 ;
case ( 1 << V_115 ) :
* V_7 = V_2 -> V_47 [ ( V_2 -> V_22 >> 8 ) & 0x7 ] [ 0 ] ;
* V_109 = V_2 -> V_47 [ ( V_2 -> V_22 >> 8 ) & 0x7 ] [ 1 ] ;
return V_116 ;
case ( 1 << V_117 ) :
switch ( V_108 -> type ) {
case V_118 :
V_38 = ( 1170ULL * 100000000ULL * 6ULL )
>> ( V_108 -> V_52 . V_53 -
( V_111 ? 0 : 1 ) ) ;
break;
case V_119 :
V_38 = ( 2500ULL * 100000000ULL )
>> ( V_108 -> V_52 . V_53 -
( V_111 ? 0 : 1 ) ) ;
break;
default:
return - V_16 ;
}
* V_109 = F_24 ( V_38 , 100000000 ) * 10 ;
* V_7 = V_38 ;
return V_116 ;
}
return - V_16 ;
}
static int F_65 ( struct V_63 * V_64 ,
struct V_107 const * V_108 ,
int V_7 ,
int V_109 ,
long V_120 )
{
struct V_1 * V_2 = F_28 ( V_64 ) ;
int V_18 , V_35 ;
unsigned int V_121 ;
F_59 ( & V_64 -> V_106 ) ;
if ( F_60 ( V_64 ) ) {
F_61 ( & V_64 -> V_106 ) ;
return - V_60 ;
}
switch ( V_120 ) {
case ( 1 << V_115 ) :
V_18 = - V_16 ;
for ( V_35 = 0 ; V_35 < F_19 ( V_2 -> V_47 ) ; V_35 ++ )
if ( V_109 == V_2 -> V_47 [ V_35 ] [ 1 ] ) {
V_121 = V_2 -> V_22 ;
V_2 -> V_22 &= ~ F_66 ( - 1 ) ;
V_2 -> V_22 |= F_66 ( V_35 ) ;
if ( V_121 != V_2 -> V_22 ) {
F_7 ( V_2 , V_25 ,
sizeof( V_2 -> V_22 ) ,
V_2 -> V_22 ) ;
F_18 ( V_2 ) ;
}
V_18 = 0 ;
}
default:
V_18 = - V_16 ;
}
F_61 ( & V_64 -> V_106 ) ;
return V_18 ;
}
static int F_67 ( struct V_63 * V_64 ,
struct V_122 * V_79 )
{
if ( V_64 -> V_79 != V_79 )
return - V_16 ;
return 0 ;
}
static int F_68 ( struct V_63 * V_64 ,
struct V_107 const * V_108 ,
long V_120 )
{
return V_116 ;
}
static int T_8 F_69 ( struct V_123 * V_17 )
{
struct V_124 * V_44 = V_17 -> V_37 . V_125 ;
struct V_1 * V_2 ;
struct V_63 * V_64 ;
int V_18 , V_35 , V_126 = 0 , V_127 = 0 ;
if ( ! V_44 ) {
F_20 ( & V_17 -> V_37 , L_9 ) ;
return - V_128 ;
}
if ( ! V_17 -> V_31 ) {
F_20 ( & V_17 -> V_37 , L_10 ) ;
return - V_128 ;
}
V_64 = F_70 ( sizeof( * V_2 ) ) ;
if ( V_64 == NULL )
return - V_81 ;
V_2 = F_28 ( V_64 ) ;
V_2 -> V_5 = F_71 ( & V_17 -> V_37 , L_11 ) ;
if ( ! F_72 ( V_2 -> V_5 ) ) {
V_18 = F_73 ( V_2 -> V_5 ) ;
if ( V_18 )
goto V_129;
V_126 = F_74 ( V_2 -> V_5 ) ;
}
V_2 -> V_50 =
& V_130 [ F_48 ( V_17 ) -> V_131 ] ;
V_2 -> V_44 = V_44 ;
if ( V_44 && V_44 -> V_132 )
V_2 -> V_49 = V_44 -> V_132 ;
else if ( V_126 )
V_2 -> V_49 = V_126 / 1000 ;
else
V_2 -> V_49 = 2500 ;
F_75 ( V_17 , V_64 ) ;
V_2 -> V_17 = V_17 ;
V_64 -> V_37 . V_96 = & V_17 -> V_37 ;
V_64 -> V_93 = F_48 ( V_17 ) -> V_93 ;
V_64 -> V_90 = V_133 ;
V_64 -> V_67 = V_2 -> V_50 -> V_51 ;
V_64 -> V_134 = V_2 -> V_134 ;
V_64 -> V_135 = 7 ;
V_64 -> V_136 = & V_137 ;
for ( V_35 = 0 ; V_35 < V_64 -> V_135 ; V_35 ++ )
V_2 -> V_134 [ V_35 ] = ( 1 << V_35 ) | ( 1 <<
V_64 -> V_67 [ V_64 -> V_135 - 1 ] .
V_112 ) ;
F_76 ( & V_2 -> V_32 ) ;
V_18 = F_34 ( V_64 ) ;
if ( V_18 )
goto V_138;
V_18 = F_77 ( V_64 ) ;
if ( V_18 )
goto V_139;
V_127 = 1 ;
V_18 = F_46 ( V_64 ) ;
if ( V_18 )
goto V_139;
V_18 = F_78 ( V_64 -> V_56 , 0 ,
V_64 -> V_67 ,
V_64 -> V_135 ) ;
if ( V_18 )
goto V_140;
V_18 = F_21 ( V_2 ) ;
if ( V_18 )
goto V_141;
return 0 ;
V_141:
F_79 ( V_64 -> V_56 ) ;
V_140:
F_53 ( V_64 ) ;
V_139:
F_38 ( V_64 ) ;
V_138:
if ( ! F_72 ( V_2 -> V_5 ) )
F_80 ( V_2 -> V_5 ) ;
V_129:
if ( ! F_72 ( V_2 -> V_5 ) )
F_81 ( V_2 -> V_5 ) ;
if ( V_127 )
F_82 ( V_64 ) ;
else
F_83 ( V_64 ) ;
return V_18 ;
}
static int F_84 ( struct V_123 * V_17 )
{
struct V_63 * V_64 = F_85 ( V_17 ) ;
struct V_1 * V_2 = F_28 ( V_64 ) ;
F_79 ( V_64 -> V_56 ) ;
F_53 ( V_64 ) ;
F_38 ( V_64 ) ;
if ( ! F_72 ( V_2 -> V_5 ) ) {
F_80 ( V_2 -> V_5 ) ;
F_81 ( V_2 -> V_5 ) ;
}
F_82 ( V_64 ) ;
return 0 ;
}
static int T_9 F_86 ( void )
{
return F_87 ( & V_142 ) ;
}
static void T_10 F_88 ( void )
{
F_89 ( & V_142 ) ;
}
