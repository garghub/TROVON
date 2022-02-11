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
static int F_25 ( struct V_55 * V_56 )
{
struct V_1 * V_2 = F_26 ( V_56 ) ;
unsigned V_51 ;
int V_18 ;
if ( F_27 ( V_56 -> V_57 , V_56 -> V_58 ) )
return - V_16 ;
V_18 = F_28 ( V_56 ) ;
if ( V_18 < 0 )
return V_18 ;
V_51 = F_29 ( V_56 -> V_57 ,
V_56 -> V_58 ) ;
V_2 -> V_23 = ( V_2 -> V_23 & ~ F_12 ( - 1 ) ) |
F_12 ( V_59 ) ;
V_2 -> V_22 = ( V_2 -> V_22 & ~ F_11 ( - 1 ) ) |
F_11 ( V_56 -> V_60 [ V_51 ] . V_61 ) ;
F_7 ( V_2 , V_25 , sizeof( V_2 -> V_22 ) , V_2 -> V_22 ) ;
F_13 ( V_2 -> V_17 -> V_26 ) ;
F_1 ( V_2 , 1 , 1 , V_28 ,
sizeof( V_2 -> V_23 ) , V_2 -> V_23 ) ;
V_2 -> V_30 = false ;
F_14 ( V_2 -> V_17 -> V_31 ) ;
return 0 ;
}
static int F_30 ( struct V_55 * V_56 )
{
struct V_1 * V_2 = F_26 ( V_56 ) ;
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
static T_3 F_32 ( int V_31 , void * V_62 )
{
struct V_63 * V_64 = V_62 ;
struct V_55 * V_56 = V_64 -> V_56 ;
struct V_65 * V_66 = V_56 -> V_67 ;
struct V_1 * V_2 = F_26 ( V_56 ) ;
T_4 V_68 [ 2 ] ;
T_5 * V_69 = ( T_5 * ) V_68 ;
if ( ! F_27 ( V_56 -> V_57 , V_56 -> V_58 ) )
F_8 ( V_2 , 1 , 1 , V_33 ,
V_69 ,
V_56 -> V_60 [ 0 ] . V_52 . V_53 / 8 ) ;
if ( V_56 -> V_70 )
V_68 [ 1 ] = V_64 -> V_71 ;
V_66 -> V_72 -> V_73 ( V_66 , ( T_1 * ) V_68 , V_64 -> V_71 ) ;
F_33 ( V_56 -> V_74 ) ;
V_2 -> V_30 = false ;
F_14 ( V_2 -> V_17 -> V_31 ) ;
return V_75 ;
}
static int F_34 ( struct V_55 * V_56 )
{
int V_18 ;
V_56 -> V_67 = F_35 ( V_56 ) ;
if ( ! V_56 -> V_67 ) {
V_18 = - V_76 ;
goto V_77;
}
V_56 -> V_78 = F_36 ( & V_79 ,
& F_32 ,
V_80 ,
V_56 ,
L_4 ,
V_56 -> V_39 ) ;
if ( V_56 -> V_78 == NULL ) {
V_18 = - V_76 ;
goto V_81;
}
V_56 -> V_82 = & V_83 ;
V_56 -> V_84 |= V_85 ;
return 0 ;
V_81:
F_37 ( V_56 -> V_67 ) ;
V_77:
return V_18 ;
}
static void F_38 ( struct V_55 * V_56 )
{
F_39 ( V_56 -> V_78 ) ;
F_37 ( V_56 -> V_67 ) ;
}
static T_3 F_40 ( int V_31 , void * V_86 )
{
struct V_1 * V_2 = F_26 ( V_86 ) ;
V_2 -> V_27 = true ;
F_41 ( & V_2 -> V_32 ) ;
F_31 ( V_31 ) ;
V_2 -> V_30 = true ;
F_42 ( V_2 -> V_74 , F_43 () ) ;
return V_75 ;
}
static int F_44 ( struct V_55 * V_56 )
{
struct V_1 * V_2 = F_26 ( V_56 ) ;
int V_18 ;
V_2 -> V_74 = F_45 ( L_5 ,
F_46 ( V_2 -> V_17 ) -> V_87 ,
V_56 -> V_39 ) ;
if ( V_2 -> V_74 == NULL ) {
V_18 = - V_76 ;
goto V_77;
}
V_2 -> V_74 -> V_88 = & V_89 ;
V_18 = F_47 ( V_2 -> V_17 -> V_31 ,
F_40 ,
V_90 ,
F_46 ( V_2 -> V_17 ) -> V_87 ,
V_56 ) ;
if ( V_18 )
goto V_91;
F_31 ( V_2 -> V_17 -> V_31 ) ;
V_2 -> V_30 = true ;
V_2 -> V_74 -> V_37 . V_92 = & V_2 -> V_17 -> V_37 ;
V_2 -> V_74 -> V_93 = V_56 ;
V_18 = F_48 ( V_2 -> V_74 ) ;
V_56 -> V_74 = V_2 -> V_74 ;
if ( V_18 )
goto V_94;
return 0 ;
V_94:
F_49 ( V_2 -> V_17 -> V_31 , V_56 ) ;
V_91:
F_50 ( V_2 -> V_74 ) ;
V_77:
return V_18 ;
}
static void F_51 ( struct V_55 * V_56 )
{
struct V_1 * V_2 = F_26 ( V_56 ) ;
F_52 ( V_2 -> V_74 ) ;
F_49 ( V_2 -> V_17 -> V_31 , V_56 ) ;
F_50 ( V_2 -> V_74 ) ;
}
static T_6 F_53 ( struct V_95 * V_37 ,
struct V_96 * V_97 ,
char * V_98 )
{
struct V_55 * V_56 = F_54 ( V_37 ) ;
struct V_1 * V_2 = F_26 ( V_56 ) ;
return sprintf ( V_98 , L_6 ,
V_99 [ F_55 ( V_2 -> V_23 ) ] ) ;
}
static T_6 F_56 ( struct V_95 * V_37 ,
struct V_96 * V_97 ,
const char * V_98 ,
T_7 V_12 )
{
struct V_55 * V_56 = F_54 ( V_37 ) ;
struct V_1 * V_2 = F_26 ( V_56 ) ;
long V_100 ;
int V_35 , V_18 ;
F_57 ( & V_56 -> V_101 ) ;
if ( F_58 ( V_56 ) ) {
F_59 ( & V_56 -> V_101 ) ;
return - V_102 ;
}
F_59 ( & V_56 -> V_101 ) ;
V_18 = F_60 ( V_98 , 10 , & V_100 ) ;
if ( V_18 )
return V_18 ;
V_18 = - V_16 ;
for ( V_35 = 0 ; V_35 < F_19 ( V_99 ) ; V_35 ++ )
if ( V_100 == V_99 [ V_35 ] ) {
F_57 ( & V_56 -> V_101 ) ;
V_2 -> V_23 &= ~ F_55 ( - 1 ) ;
V_2 -> V_23 |= F_55 ( V_35 ) ;
F_7 ( V_2 , V_28 ,
sizeof( V_2 -> V_23 ) , V_2 -> V_23 ) ;
F_59 ( & V_56 -> V_101 ) ;
V_18 = 0 ;
}
return V_18 ? V_18 : V_12 ;
}
static T_6 F_61 ( struct V_95 * V_37 ,
struct V_96 * V_97 , char * V_98 )
{
struct V_55 * V_56 = F_54 ( V_37 ) ;
struct V_1 * V_2 = F_26 ( V_56 ) ;
int V_35 , V_12 = 0 ;
for ( V_35 = 0 ; V_35 < F_19 ( V_2 -> V_47 ) ; V_35 ++ )
V_12 += sprintf ( V_98 + V_12 , L_7 , V_2 -> V_47 [ V_35 ] [ 0 ] ,
V_2 -> V_47 [ V_35 ] [ 1 ] ) ;
V_12 += sprintf ( V_98 + V_12 , L_8 ) ;
return V_12 ;
}
static int F_62 ( struct V_55 * V_56 ,
struct V_103 const * V_104 ,
int * V_7 ,
int * V_105 ,
long V_14 )
{
struct V_1 * V_2 = F_26 ( V_56 ) ;
int V_18 , V_106 = 0 ;
unsigned long long V_38 ;
bool V_107 = ! ! ( V_2 -> V_22 & V_54 ) ;
switch ( V_14 ) {
case V_108 :
F_57 ( & V_56 -> V_101 ) ;
if ( F_58 ( V_56 ) )
V_18 = - V_102 ;
else
V_18 = F_10 ( V_2 , V_104 -> V_61 ,
V_104 -> V_52 . V_53 / 8 , & V_106 ) ;
F_59 ( & V_56 -> V_101 ) ;
if ( V_18 < 0 )
return V_18 ;
* V_7 = ( V_106 >> V_104 -> V_52 . V_109 ) &
( ( 1 << ( V_104 -> V_52 . V_53 ) ) - 1 ) ;
if ( ! V_107 )
* V_7 -= ( 1 << ( V_104 -> V_52 . V_53 - 1 ) ) ;
return V_110 ;
case V_111 :
switch ( V_104 -> type ) {
case V_112 :
if ( V_104 -> V_113 ) {
* V_7 = V_2 ->
V_47 [ ( V_2 -> V_22 >> 8 ) & 0x7 ] [ 0 ] ;
* V_105 = V_2 ->
V_47 [ ( V_2 -> V_22 >> 8 ) & 0x7 ] [ 1 ] ;
return V_114 ;
} else {
V_38 = ( 1170ULL * 100000000ULL * 6ULL )
>> ( V_104 -> V_52 . V_53 -
( V_107 ? 0 : 1 ) ) ;
}
break;
case V_115 :
V_38 = ( 2500ULL * 100000000ULL )
>> ( V_104 -> V_52 . V_53 -
( V_107 ? 0 : 1 ) ) ;
break;
default:
return - V_16 ;
}
* V_105 = F_24 ( V_38 , 100000000 ) * 10 ;
* V_7 = V_38 ;
return V_114 ;
}
return - V_16 ;
}
static int F_63 ( struct V_55 * V_56 ,
struct V_103 const * V_104 ,
int V_7 ,
int V_105 ,
long V_116 )
{
struct V_1 * V_2 = F_26 ( V_56 ) ;
int V_18 , V_35 ;
unsigned int V_117 ;
F_57 ( & V_56 -> V_101 ) ;
if ( F_58 ( V_56 ) ) {
F_59 ( & V_56 -> V_101 ) ;
return - V_102 ;
}
switch ( V_116 ) {
case V_111 :
V_18 = - V_16 ;
for ( V_35 = 0 ; V_35 < F_19 ( V_2 -> V_47 ) ; V_35 ++ )
if ( V_105 == V_2 -> V_47 [ V_35 ] [ 1 ] ) {
V_117 = V_2 -> V_22 ;
V_2 -> V_22 &= ~ F_64 ( - 1 ) ;
V_2 -> V_22 |= F_64 ( V_35 ) ;
if ( V_117 != V_2 -> V_22 ) {
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
F_59 ( & V_56 -> V_101 ) ;
return V_18 ;
}
static int F_65 ( struct V_55 * V_56 ,
struct V_118 * V_74 )
{
if ( V_56 -> V_74 != V_74 )
return - V_16 ;
return 0 ;
}
static int F_66 ( struct V_55 * V_56 ,
struct V_103 const * V_104 ,
long V_116 )
{
return V_114 ;
}
static int T_8 F_67 ( struct V_119 * V_17 )
{
struct V_120 * V_44 = V_17 -> V_37 . V_121 ;
struct V_1 * V_2 ;
struct V_55 * V_56 ;
int V_18 , V_35 , V_122 = 0 ;
if ( ! V_44 ) {
F_20 ( & V_17 -> V_37 , L_9 ) ;
return - V_123 ;
}
if ( ! V_17 -> V_31 ) {
F_20 ( & V_17 -> V_37 , L_10 ) ;
return - V_123 ;
}
V_56 = F_68 ( sizeof( * V_2 ) ) ;
if ( V_56 == NULL )
return - V_76 ;
V_2 = F_26 ( V_56 ) ;
V_2 -> V_5 = F_69 ( & V_17 -> V_37 , L_11 ) ;
if ( ! F_70 ( V_2 -> V_5 ) ) {
V_18 = F_71 ( V_2 -> V_5 ) ;
if ( V_18 )
goto V_124;
V_122 = F_72 ( V_2 -> V_5 ) ;
}
V_2 -> V_50 =
& V_125 [ F_46 ( V_17 ) -> V_126 ] ;
V_2 -> V_44 = V_44 ;
if ( V_44 && V_44 -> V_127 )
V_2 -> V_49 = V_44 -> V_127 ;
else if ( V_122 )
V_2 -> V_49 = V_122 / 1000 ;
else
V_2 -> V_49 = 2500 ;
F_73 ( V_17 , V_56 ) ;
V_2 -> V_17 = V_17 ;
V_56 -> V_37 . V_92 = & V_17 -> V_37 ;
V_56 -> V_87 = F_46 ( V_17 ) -> V_87 ;
V_56 -> V_84 = V_128 ;
V_56 -> V_60 = V_2 -> V_50 -> V_51 ;
V_56 -> V_129 = V_2 -> V_129 ;
V_56 -> V_130 = 7 ;
V_56 -> V_131 = & V_132 ;
for ( V_35 = 0 ; V_35 < V_56 -> V_130 ; V_35 ++ ) {
F_74 ( V_35 , & V_2 -> V_129 [ V_35 ] ) ;
F_74 ( V_56 ->
V_60 [ V_56 -> V_130 - 1 ] . V_133 ,
& V_2 -> V_129 [ V_35 ] ) ;
}
F_75 ( & V_2 -> V_32 ) ;
V_18 = F_34 ( V_56 ) ;
if ( V_18 )
goto V_134;
V_18 = F_44 ( V_56 ) ;
if ( V_18 )
goto V_135;
V_18 = F_76 ( V_56 ,
V_56 -> V_60 ,
V_56 -> V_130 ) ;
if ( V_18 )
goto V_136;
V_18 = F_21 ( V_2 ) ;
if ( V_18 )
goto V_137;
V_18 = F_77 ( V_56 ) ;
if ( V_18 )
goto V_137;
return 0 ;
V_137:
F_78 ( V_56 ) ;
V_136:
F_51 ( V_56 ) ;
V_135:
F_38 ( V_56 ) ;
V_134:
if ( ! F_70 ( V_2 -> V_5 ) )
F_79 ( V_2 -> V_5 ) ;
V_124:
if ( ! F_70 ( V_2 -> V_5 ) )
F_80 ( V_2 -> V_5 ) ;
F_81 ( V_56 ) ;
return V_18 ;
}
static int F_82 ( struct V_119 * V_17 )
{
struct V_55 * V_56 = F_83 ( V_17 ) ;
struct V_1 * V_2 = F_26 ( V_56 ) ;
F_84 ( V_56 ) ;
F_78 ( V_56 ) ;
F_51 ( V_56 ) ;
F_38 ( V_56 ) ;
if ( ! F_70 ( V_2 -> V_5 ) ) {
F_79 ( V_2 -> V_5 ) ;
F_80 ( V_2 -> V_5 ) ;
}
F_81 ( V_56 ) ;
return 0 ;
}
