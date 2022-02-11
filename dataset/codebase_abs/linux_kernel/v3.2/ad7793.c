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
struct V_55 * V_56 = F_26 ( V_2 ) -> V_57 ;
int V_18 ;
T_3 V_58 [ 2 ] ;
T_2 * V_59 = ( T_2 * ) V_58 ;
if ( ! ( F_27 ( V_21 , V_56 -> V_60 ) ) )
return - V_61 ;
V_18 = V_56 -> V_62 -> V_63 ( V_56 , ( T_1 * ) & V_58 ) ;
if ( V_18 )
return V_18 ;
* V_7 = * V_59 ;
return 0 ;
}
static int F_28 ( struct V_64 * V_65 )
{
struct V_1 * V_2 = F_29 ( V_65 ) ;
struct V_55 * V_56 = V_65 -> V_57 ;
T_4 V_66 ;
unsigned V_51 ;
if ( ! V_56 -> V_67 )
return - V_16 ;
V_51 = F_30 ( V_56 -> V_60 ,
V_65 -> V_68 ) ;
V_66 = V_56 -> V_67 *
V_65 -> V_69 [ 0 ] . V_52 . V_70 / 8 ;
if ( V_56 -> V_71 ) {
V_66 += sizeof( T_3 ) ;
if ( V_66 % sizeof( T_3 ) )
V_66 += sizeof( T_3 ) - ( V_66 % sizeof( T_3 ) ) ;
}
if ( V_65 -> V_57 -> V_62 -> V_72 )
V_65 -> V_57 -> V_62 ->
V_72 ( V_65 -> V_57 , V_66 ) ;
V_2 -> V_23 = ( V_2 -> V_23 & ~ F_12 ( - 1 ) ) |
F_12 ( V_73 ) ;
V_2 -> V_22 = ( V_2 -> V_22 & ~ F_11 ( - 1 ) ) |
F_11 ( V_65 -> V_69 [ V_51 ] . V_74 ) ;
F_7 ( V_2 , V_25 , sizeof( V_2 -> V_22 ) , V_2 -> V_22 ) ;
F_13 ( V_2 -> V_17 -> V_26 ) ;
F_1 ( V_2 , 1 , 1 , V_28 ,
sizeof( V_2 -> V_23 ) , V_2 -> V_23 ) ;
V_2 -> V_30 = false ;
F_14 ( V_2 -> V_17 -> V_31 ) ;
return 0 ;
}
static int F_31 ( struct V_64 * V_65 )
{
struct V_1 * V_2 = F_29 ( V_65 ) ;
V_2 -> V_23 = ( V_2 -> V_23 & ~ F_12 ( - 1 ) ) |
F_12 ( V_34 ) ;
V_2 -> V_27 = false ;
F_15 ( V_2 -> V_32 , V_2 -> V_27 ) ;
if ( ! V_2 -> V_30 )
F_32 ( V_2 -> V_17 -> V_31 ) ;
F_1 ( V_2 , 1 , 0 , V_28 ,
sizeof( V_2 -> V_23 ) , V_2 -> V_23 ) ;
return F_16 ( V_2 -> V_17 -> V_26 ) ;
}
static T_5 F_33 ( int V_31 , void * V_75 )
{
struct V_76 * V_77 = V_75 ;
struct V_64 * V_65 = V_77 -> V_65 ;
struct V_55 * V_56 = V_65 -> V_57 ;
struct V_1 * V_2 = F_29 ( V_65 ) ;
T_3 V_58 [ 2 ] ;
T_6 * V_59 = ( T_6 * ) V_58 ;
if ( V_56 -> V_67 )
F_8 ( V_2 , 1 , 1 , V_33 ,
V_59 ,
V_65 -> V_69 [ 0 ] . V_52 . V_53 / 8 ) ;
if ( V_56 -> V_71 )
V_58 [ 1 ] = V_77 -> V_78 ;
V_56 -> V_62 -> V_79 ( V_56 , ( T_1 * ) V_58 , V_77 -> V_78 ) ;
F_34 ( V_65 -> V_80 ) ;
V_2 -> V_30 = false ;
F_14 ( V_2 -> V_17 -> V_31 ) ;
return V_81 ;
}
static int F_35 ( struct V_64 * V_65 )
{
int V_18 ;
V_65 -> V_57 = F_36 ( V_65 ) ;
if ( ! V_65 -> V_57 ) {
V_18 = - V_82 ;
goto V_83;
}
V_65 -> V_57 -> V_62 = & V_84 ;
V_65 -> V_85 = F_37 ( & V_86 ,
& F_33 ,
V_87 ,
V_65 ,
L_4 ,
V_65 -> V_39 ) ;
if ( V_65 -> V_85 == NULL ) {
V_18 = - V_82 ;
goto V_88;
}
V_65 -> V_57 -> V_89 = & V_90 ;
V_65 -> V_91 |= V_92 ;
return 0 ;
V_88:
F_38 ( V_65 -> V_57 ) ;
V_83:
return V_18 ;
}
static void F_39 ( struct V_64 * V_65 )
{
F_40 ( V_65 -> V_85 ) ;
F_38 ( V_65 -> V_57 ) ;
}
static T_5 F_41 ( int V_31 , void * V_93 )
{
struct V_1 * V_2 = F_29 ( V_93 ) ;
V_2 -> V_27 = true ;
F_42 ( & V_2 -> V_32 ) ;
F_32 ( V_31 ) ;
V_2 -> V_30 = true ;
F_43 ( V_2 -> V_80 , F_44 () ) ;
return V_81 ;
}
static int F_45 ( struct V_64 * V_65 )
{
struct V_1 * V_2 = F_29 ( V_65 ) ;
int V_18 ;
V_2 -> V_80 = F_46 ( L_5 ,
F_47 ( V_2 -> V_17 ) -> V_94 ,
V_65 -> V_39 ) ;
if ( V_2 -> V_80 == NULL ) {
V_18 = - V_82 ;
goto V_83;
}
V_18 = F_48 ( V_2 -> V_17 -> V_31 ,
F_41 ,
V_95 ,
F_47 ( V_2 -> V_17 ) -> V_94 ,
V_65 ) ;
if ( V_18 )
goto V_96;
F_32 ( V_2 -> V_17 -> V_31 ) ;
V_2 -> V_30 = true ;
V_2 -> V_80 -> V_37 . V_97 = & V_2 -> V_17 -> V_37 ;
V_2 -> V_80 -> V_98 = V_99 ;
V_2 -> V_80 -> V_100 = V_65 ;
V_18 = F_49 ( V_2 -> V_80 ) ;
V_65 -> V_80 = V_2 -> V_80 ;
if ( V_18 )
goto V_101;
return 0 ;
V_101:
F_50 ( V_2 -> V_17 -> V_31 , V_65 ) ;
V_96:
F_51 ( V_2 -> V_80 ) ;
V_83:
return V_18 ;
}
static void F_52 ( struct V_64 * V_65 )
{
struct V_1 * V_2 = F_29 ( V_65 ) ;
F_53 ( V_2 -> V_80 ) ;
F_50 ( V_2 -> V_17 -> V_31 , V_65 ) ;
F_51 ( V_2 -> V_80 ) ;
}
static T_7 F_54 ( struct V_102 * V_37 ,
struct V_103 * V_104 ,
char * V_105 )
{
struct V_64 * V_65 = F_55 ( V_37 ) ;
struct V_1 * V_2 = F_29 ( V_65 ) ;
return sprintf ( V_105 , L_6 ,
V_106 [ F_56 ( V_2 -> V_23 ) ] ) ;
}
static T_7 F_57 ( struct V_102 * V_37 ,
struct V_103 * V_104 ,
const char * V_105 ,
T_4 V_12 )
{
struct V_64 * V_65 = F_55 ( V_37 ) ;
struct V_1 * V_2 = F_29 ( V_65 ) ;
long V_107 ;
int V_35 , V_18 ;
F_58 ( & V_65 -> V_108 ) ;
if ( F_59 ( V_65 ) ) {
F_60 ( & V_65 -> V_108 ) ;
return - V_61 ;
}
F_60 ( & V_65 -> V_108 ) ;
V_18 = F_61 ( V_105 , 10 , & V_107 ) ;
if ( V_18 )
return V_18 ;
V_18 = - V_16 ;
for ( V_35 = 0 ; V_35 < F_19 ( V_106 ) ; V_35 ++ )
if ( V_107 == V_106 [ V_35 ] ) {
F_58 ( & V_65 -> V_108 ) ;
V_2 -> V_23 &= ~ F_56 ( - 1 ) ;
V_2 -> V_23 |= F_56 ( V_35 ) ;
F_7 ( V_2 , V_28 ,
sizeof( V_2 -> V_23 ) , V_2 -> V_23 ) ;
F_60 ( & V_65 -> V_108 ) ;
V_18 = 0 ;
}
return V_18 ? V_18 : V_12 ;
}
static T_7 F_62 ( struct V_102 * V_37 ,
struct V_103 * V_104 , char * V_105 )
{
struct V_64 * V_65 = F_55 ( V_37 ) ;
struct V_1 * V_2 = F_29 ( V_65 ) ;
int V_35 , V_12 = 0 ;
for ( V_35 = 0 ; V_35 < F_19 ( V_2 -> V_47 ) ; V_35 ++ )
V_12 += sprintf ( V_105 + V_12 , L_7 , V_2 -> V_47 [ V_35 ] [ 0 ] ,
V_2 -> V_47 [ V_35 ] [ 1 ] ) ;
V_12 += sprintf ( V_105 + V_12 , L_8 ) ;
return V_12 ;
}
static int F_63 ( struct V_64 * V_65 ,
struct V_109 const * V_110 ,
int * V_7 ,
int * V_111 ,
long V_14 )
{
struct V_1 * V_2 = F_29 ( V_65 ) ;
int V_18 , V_112 = 0 ;
unsigned long long V_38 ;
bool V_113 = ! ! ( V_2 -> V_22 & V_54 ) ;
switch ( V_14 ) {
case 0 :
F_58 ( & V_65 -> V_108 ) ;
if ( F_59 ( V_65 ) )
V_18 = F_25 ( V_2 ,
V_110 -> V_114 , & V_112 ) ;
else
V_18 = F_10 ( V_2 , V_110 -> V_74 ,
V_110 -> V_52 . V_53 / 8 , & V_112 ) ;
F_60 ( & V_65 -> V_108 ) ;
if ( V_18 < 0 )
return V_18 ;
* V_7 = ( V_112 >> V_110 -> V_52 . V_115 ) &
( ( 1 << ( V_110 -> V_52 . V_53 ) ) - 1 ) ;
if ( ! V_113 )
* V_7 -= ( 1 << ( V_110 -> V_52 . V_53 - 1 ) ) ;
return V_116 ;
case ( 1 << V_117 ) :
* V_7 = V_2 -> V_47 [ ( V_2 -> V_22 >> 8 ) & 0x7 ] [ 0 ] ;
* V_111 = V_2 -> V_47 [ ( V_2 -> V_22 >> 8 ) & 0x7 ] [ 1 ] ;
return V_118 ;
case ( 1 << V_119 ) :
switch ( V_110 -> type ) {
case V_120 :
V_38 = ( 1170ULL * 100000000ULL * 6ULL )
>> ( V_110 -> V_52 . V_53 -
( V_113 ? 0 : 1 ) ) ;
break;
case V_121 :
V_38 = ( 2500ULL * 100000000ULL )
>> ( V_110 -> V_52 . V_53 -
( V_113 ? 0 : 1 ) ) ;
break;
default:
return - V_16 ;
}
* V_111 = F_24 ( V_38 , 100000000 ) * 10 ;
* V_7 = V_38 ;
return V_118 ;
}
return - V_16 ;
}
static int F_64 ( struct V_64 * V_65 ,
struct V_109 const * V_110 ,
int V_7 ,
int V_111 ,
long V_122 )
{
struct V_1 * V_2 = F_29 ( V_65 ) ;
int V_18 , V_35 ;
unsigned int V_123 ;
F_58 ( & V_65 -> V_108 ) ;
if ( F_59 ( V_65 ) ) {
F_60 ( & V_65 -> V_108 ) ;
return - V_61 ;
}
switch ( V_122 ) {
case ( 1 << V_117 ) :
V_18 = - V_16 ;
for ( V_35 = 0 ; V_35 < F_19 ( V_2 -> V_47 ) ; V_35 ++ )
if ( V_111 == V_2 -> V_47 [ V_35 ] [ 1 ] ) {
V_123 = V_2 -> V_22 ;
V_2 -> V_22 &= ~ F_65 ( - 1 ) ;
V_2 -> V_22 |= F_65 ( V_35 ) ;
if ( V_123 != V_2 -> V_22 ) {
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
F_60 ( & V_65 -> V_108 ) ;
return V_18 ;
}
static int F_66 ( struct V_64 * V_65 ,
struct V_124 * V_80 )
{
if ( V_65 -> V_80 != V_80 )
return - V_16 ;
return 0 ;
}
static int F_67 ( struct V_64 * V_65 ,
struct V_109 const * V_110 ,
long V_122 )
{
return V_118 ;
}
static int T_8 F_68 ( struct V_125 * V_17 )
{
struct V_126 * V_44 = V_17 -> V_37 . V_127 ;
struct V_1 * V_2 ;
struct V_64 * V_65 ;
int V_18 , V_35 , V_128 = 0 ;
if ( ! V_44 ) {
F_20 ( & V_17 -> V_37 , L_9 ) ;
return - V_129 ;
}
if ( ! V_17 -> V_31 ) {
F_20 ( & V_17 -> V_37 , L_10 ) ;
return - V_129 ;
}
V_65 = F_69 ( sizeof( * V_2 ) ) ;
if ( V_65 == NULL )
return - V_82 ;
V_2 = F_29 ( V_65 ) ;
V_2 -> V_5 = F_70 ( & V_17 -> V_37 , L_11 ) ;
if ( ! F_71 ( V_2 -> V_5 ) ) {
V_18 = F_72 ( V_2 -> V_5 ) ;
if ( V_18 )
goto V_130;
V_128 = F_73 ( V_2 -> V_5 ) ;
}
V_2 -> V_50 =
& V_131 [ F_47 ( V_17 ) -> V_132 ] ;
V_2 -> V_44 = V_44 ;
if ( V_44 && V_44 -> V_133 )
V_2 -> V_49 = V_44 -> V_133 ;
else if ( V_128 )
V_2 -> V_49 = V_128 / 1000 ;
else
V_2 -> V_49 = 2500 ;
F_74 ( V_17 , V_65 ) ;
V_2 -> V_17 = V_17 ;
V_65 -> V_37 . V_97 = & V_17 -> V_37 ;
V_65 -> V_94 = F_47 ( V_17 ) -> V_94 ;
V_65 -> V_91 = V_134 ;
V_65 -> V_69 = V_2 -> V_50 -> V_51 ;
V_65 -> V_135 = V_2 -> V_135 ;
V_65 -> V_136 = 7 ;
V_65 -> V_137 = & V_138 ;
for ( V_35 = 0 ; V_35 < V_65 -> V_136 ; V_35 ++ ) {
F_75 ( V_35 , & V_2 -> V_135 [ V_35 ] ) ;
F_75 ( V_65 ->
V_69 [ V_65 -> V_136 - 1 ] . V_114 ,
& V_2 -> V_135 [ V_35 ] ) ;
}
F_76 ( & V_2 -> V_32 ) ;
V_18 = F_35 ( V_65 ) ;
if ( V_18 )
goto V_139;
V_18 = F_45 ( V_65 ) ;
if ( V_18 )
goto V_140;
V_18 = F_77 ( V_65 ,
V_65 -> V_69 ,
V_65 -> V_136 ) ;
if ( V_18 )
goto V_141;
V_18 = F_21 ( V_2 ) ;
if ( V_18 )
goto V_142;
V_18 = F_78 ( V_65 ) ;
if ( V_18 )
goto V_142;
return 0 ;
V_142:
F_79 ( V_65 ) ;
V_141:
F_52 ( V_65 ) ;
V_140:
F_39 ( V_65 ) ;
V_139:
if ( ! F_71 ( V_2 -> V_5 ) )
F_80 ( V_2 -> V_5 ) ;
V_130:
if ( ! F_71 ( V_2 -> V_5 ) )
F_81 ( V_2 -> V_5 ) ;
F_82 ( V_65 ) ;
return V_18 ;
}
static int F_83 ( struct V_125 * V_17 )
{
struct V_64 * V_65 = F_84 ( V_17 ) ;
struct V_1 * V_2 = F_29 ( V_65 ) ;
F_85 ( V_65 ) ;
F_79 ( V_65 ) ;
F_52 ( V_65 ) ;
F_39 ( V_65 ) ;
if ( ! F_71 ( V_2 -> V_5 ) ) {
F_80 ( V_2 -> V_5 ) ;
F_81 ( V_2 -> V_5 ) ;
}
F_82 ( V_65 ) ;
return 0 ;
}
static int T_9 F_86 ( void )
{
return F_87 ( & V_143 ) ;
}
static void T_10 F_88 ( void )
{
F_89 ( & V_143 ) ;
}
