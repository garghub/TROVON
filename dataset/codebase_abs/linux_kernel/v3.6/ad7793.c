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
return F_35 ( V_56 , & V_76 ,
& F_32 , & V_77 ) ;
}
static void F_36 ( struct V_55 * V_56 )
{
F_37 ( V_56 ) ;
}
static T_3 F_38 ( int V_31 , void * V_78 )
{
struct V_1 * V_2 = F_26 ( V_78 ) ;
V_2 -> V_27 = true ;
F_39 ( & V_2 -> V_32 ) ;
F_31 ( V_31 ) ;
V_2 -> V_30 = true ;
F_40 ( V_2 -> V_74 , F_41 () ) ;
return V_75 ;
}
static int F_42 ( struct V_55 * V_56 )
{
struct V_1 * V_2 = F_26 ( V_56 ) ;
int V_18 ;
V_2 -> V_74 = F_43 ( L_4 ,
F_44 ( V_2 -> V_17 ) -> V_79 ,
V_56 -> V_39 ) ;
if ( V_2 -> V_74 == NULL ) {
V_18 = - V_80 ;
goto V_81;
}
V_2 -> V_74 -> V_82 = & V_83 ;
V_18 = F_45 ( V_2 -> V_17 -> V_31 ,
F_38 ,
V_84 ,
F_44 ( V_2 -> V_17 ) -> V_79 ,
V_56 ) ;
if ( V_18 )
goto V_85;
F_31 ( V_2 -> V_17 -> V_31 ) ;
V_2 -> V_30 = true ;
V_2 -> V_74 -> V_37 . V_86 = & V_2 -> V_17 -> V_37 ;
V_2 -> V_74 -> V_87 = V_56 ;
V_18 = F_46 ( V_2 -> V_74 ) ;
V_56 -> V_74 = V_2 -> V_74 ;
if ( V_18 )
goto V_88;
return 0 ;
V_88:
F_47 ( V_2 -> V_17 -> V_31 , V_56 ) ;
V_85:
F_48 ( V_2 -> V_74 ) ;
V_81:
return V_18 ;
}
static void F_49 ( struct V_55 * V_56 )
{
struct V_1 * V_2 = F_26 ( V_56 ) ;
F_50 ( V_2 -> V_74 ) ;
F_47 ( V_2 -> V_17 -> V_31 , V_56 ) ;
F_48 ( V_2 -> V_74 ) ;
}
static T_6 F_51 ( struct V_89 * V_37 ,
struct V_90 * V_91 ,
char * V_92 )
{
struct V_55 * V_56 = F_52 ( V_37 ) ;
struct V_1 * V_2 = F_26 ( V_56 ) ;
return sprintf ( V_92 , L_5 ,
V_93 [ F_53 ( V_2 -> V_23 ) ] ) ;
}
static T_6 F_54 ( struct V_89 * V_37 ,
struct V_90 * V_91 ,
const char * V_92 ,
T_7 V_12 )
{
struct V_55 * V_56 = F_52 ( V_37 ) ;
struct V_1 * V_2 = F_26 ( V_56 ) ;
long V_94 ;
int V_35 , V_18 ;
F_55 ( & V_56 -> V_95 ) ;
if ( F_56 ( V_56 ) ) {
F_57 ( & V_56 -> V_95 ) ;
return - V_96 ;
}
F_57 ( & V_56 -> V_95 ) ;
V_18 = F_58 ( V_92 , 10 , & V_94 ) ;
if ( V_18 )
return V_18 ;
V_18 = - V_16 ;
for ( V_35 = 0 ; V_35 < F_19 ( V_93 ) ; V_35 ++ )
if ( V_94 == V_93 [ V_35 ] ) {
F_55 ( & V_56 -> V_95 ) ;
V_2 -> V_23 &= ~ F_53 ( - 1 ) ;
V_2 -> V_23 |= F_53 ( V_35 ) ;
F_7 ( V_2 , V_28 ,
sizeof( V_2 -> V_23 ) , V_2 -> V_23 ) ;
F_57 ( & V_56 -> V_95 ) ;
V_18 = 0 ;
}
return V_18 ? V_18 : V_12 ;
}
static T_6 F_59 ( struct V_89 * V_37 ,
struct V_90 * V_91 , char * V_92 )
{
struct V_55 * V_56 = F_52 ( V_37 ) ;
struct V_1 * V_2 = F_26 ( V_56 ) ;
int V_35 , V_12 = 0 ;
for ( V_35 = 0 ; V_35 < F_19 ( V_2 -> V_47 ) ; V_35 ++ )
V_12 += sprintf ( V_92 + V_12 , L_6 , V_2 -> V_47 [ V_35 ] [ 0 ] ,
V_2 -> V_47 [ V_35 ] [ 1 ] ) ;
V_12 += sprintf ( V_92 + V_12 , L_7 ) ;
return V_12 ;
}
static int F_60 ( struct V_55 * V_56 ,
struct V_97 const * V_98 ,
int * V_7 ,
int * V_99 ,
long V_14 )
{
struct V_1 * V_2 = F_26 ( V_56 ) ;
int V_18 , V_100 = 0 ;
unsigned long long V_38 ;
bool V_101 = ! ! ( V_2 -> V_22 & V_54 ) ;
switch ( V_14 ) {
case V_102 :
F_55 ( & V_56 -> V_95 ) ;
if ( F_56 ( V_56 ) )
V_18 = - V_96 ;
else
V_18 = F_10 ( V_2 , V_98 -> V_61 ,
V_98 -> V_52 . V_53 / 8 , & V_100 ) ;
F_57 ( & V_56 -> V_95 ) ;
if ( V_18 < 0 )
return V_18 ;
* V_7 = ( V_100 >> V_98 -> V_52 . V_103 ) &
( ( 1 << ( V_98 -> V_52 . V_53 ) ) - 1 ) ;
return V_104 ;
case V_105 :
switch ( V_98 -> type ) {
case V_106 :
if ( V_98 -> V_107 ) {
* V_7 = V_2 ->
V_47 [ ( V_2 -> V_22 >> 8 ) & 0x7 ] [ 0 ] ;
* V_99 = V_2 ->
V_47 [ ( V_2 -> V_22 >> 8 ) & 0x7 ] [ 1 ] ;
return V_108 ;
} else {
V_38 = ( 1170ULL * 100000000ULL * 6ULL ) ;
}
break;
case V_109 :
V_38 = 1444444444444ULL ;
break;
default:
return - V_16 ;
}
V_38 >>= ( V_98 -> V_52 . V_53 - ( V_101 ? 0 : 1 ) ) ;
* V_7 = 0 ;
* V_99 = V_38 ;
return V_108 ;
case V_110 :
if ( ! V_101 )
* V_7 = - ( 1 << ( V_98 -> V_52 . V_53 - 1 ) ) ;
else
* V_7 = 0 ;
if ( V_98 -> type == V_109 ) {
unsigned long long V_111 ;
unsigned int V_103 ;
V_103 = V_98 -> V_52 . V_53 - ( V_101 ? 0 : 1 ) ;
V_111 = 273ULL << V_103 ;
F_24 ( V_111 , 1444 ) ;
* V_7 -= V_111 ;
}
return V_104 ;
}
return - V_16 ;
}
static int F_61 ( struct V_55 * V_56 ,
struct V_97 const * V_98 ,
int V_7 ,
int V_99 ,
long V_112 )
{
struct V_1 * V_2 = F_26 ( V_56 ) ;
int V_18 , V_35 ;
unsigned int V_113 ;
F_55 ( & V_56 -> V_95 ) ;
if ( F_56 ( V_56 ) ) {
F_57 ( & V_56 -> V_95 ) ;
return - V_96 ;
}
switch ( V_112 ) {
case V_105 :
V_18 = - V_16 ;
for ( V_35 = 0 ; V_35 < F_19 ( V_2 -> V_47 ) ; V_35 ++ )
if ( V_99 == V_2 -> V_47 [ V_35 ] [ 1 ] ) {
V_113 = V_2 -> V_22 ;
V_2 -> V_22 &= ~ F_62 ( - 1 ) ;
V_2 -> V_22 |= F_62 ( V_35 ) ;
if ( V_113 != V_2 -> V_22 ) {
F_7 ( V_2 , V_25 ,
sizeof( V_2 -> V_22 ) ,
V_2 -> V_22 ) ;
F_18 ( V_2 ) ;
}
V_18 = 0 ;
}
break;
default:
V_18 = - V_16 ;
}
F_57 ( & V_56 -> V_95 ) ;
return V_18 ;
}
static int F_63 ( struct V_55 * V_56 ,
struct V_114 * V_74 )
{
if ( V_56 -> V_74 != V_74 )
return - V_16 ;
return 0 ;
}
static int F_64 ( struct V_55 * V_56 ,
struct V_97 const * V_98 ,
long V_112 )
{
return V_108 ;
}
static int T_8 F_65 ( struct V_115 * V_17 )
{
struct V_116 * V_44 = V_17 -> V_37 . V_117 ;
struct V_1 * V_2 ;
struct V_55 * V_56 ;
int V_18 , V_118 = 0 ;
if ( ! V_44 ) {
F_20 ( & V_17 -> V_37 , L_8 ) ;
return - V_119 ;
}
if ( ! V_17 -> V_31 ) {
F_20 ( & V_17 -> V_37 , L_9 ) ;
return - V_119 ;
}
V_56 = F_66 ( sizeof( * V_2 ) ) ;
if ( V_56 == NULL )
return - V_80 ;
V_2 = F_26 ( V_56 ) ;
V_2 -> V_5 = F_67 ( & V_17 -> V_37 , L_10 ) ;
if ( ! F_68 ( V_2 -> V_5 ) ) {
V_18 = F_69 ( V_2 -> V_5 ) ;
if ( V_18 )
goto V_120;
V_118 = F_70 ( V_2 -> V_5 ) ;
}
V_2 -> V_50 =
& V_121 [ F_44 ( V_17 ) -> V_122 ] ;
V_2 -> V_44 = V_44 ;
if ( V_44 && V_44 -> V_123 )
V_2 -> V_49 = V_44 -> V_123 ;
else if ( V_118 )
V_2 -> V_49 = V_118 / 1000 ;
else
V_2 -> V_49 = 1170 ;
F_71 ( V_17 , V_56 ) ;
V_2 -> V_17 = V_17 ;
V_56 -> V_37 . V_86 = & V_17 -> V_37 ;
V_56 -> V_79 = F_44 ( V_17 ) -> V_79 ;
V_56 -> V_124 = V_125 ;
V_56 -> V_60 = V_2 -> V_50 -> V_51 ;
V_56 -> V_126 = 7 ;
V_56 -> V_127 = & V_128 ;
F_72 ( & V_2 -> V_32 ) ;
V_18 = F_34 ( V_56 ) ;
if ( V_18 )
goto V_129;
V_18 = F_42 ( V_56 ) ;
if ( V_18 )
goto V_130;
V_18 = F_21 ( V_2 ) ;
if ( V_18 )
goto V_131;
V_18 = F_73 ( V_56 ) ;
if ( V_18 )
goto V_131;
return 0 ;
V_131:
F_49 ( V_56 ) ;
V_130:
F_36 ( V_56 ) ;
V_129:
if ( ! F_68 ( V_2 -> V_5 ) )
F_74 ( V_2 -> V_5 ) ;
V_120:
if ( ! F_68 ( V_2 -> V_5 ) )
F_75 ( V_2 -> V_5 ) ;
F_76 ( V_56 ) ;
return V_18 ;
}
static int F_77 ( struct V_115 * V_17 )
{
struct V_55 * V_56 = F_78 ( V_17 ) ;
struct V_1 * V_2 = F_26 ( V_56 ) ;
F_79 ( V_56 ) ;
F_49 ( V_56 ) ;
F_36 ( V_56 ) ;
if ( ! F_68 ( V_2 -> V_5 ) ) {
F_74 ( V_2 -> V_5 ) ;
F_75 ( V_2 -> V_5 ) ;
}
F_76 ( V_56 ) ;
return 0 ;
}
