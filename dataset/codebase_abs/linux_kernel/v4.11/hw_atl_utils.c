static int F_1 ( struct V_1 * V_2 , T_1 V_3 ,
T_1 * V_4 , T_1 V_5 )
{
int V_6 = 0 ;
F_2 ( F_3 ( V_2 ,
V_7 ) == 1U ,
1U , 10000U ) ;
if ( V_6 < 0 ) {
bool V_8 ;
F_4 ( V_2 , 1U , V_7 ) ;
V_8 = F_3 ( V_2 , V_7 ) ;
if ( ! V_8 ) {
V_6 = - V_9 ;
goto V_10;
}
}
F_5 ( V_2 , 0x00000208U , V_3 ) ;
for ( ++ V_5 ; -- V_5 ; ) {
T_1 V_11 = 0U ;
F_5 ( V_2 , 0x00000200U , 0x00008000U ) ;
for ( V_11 = 1024U ;
( 0x100U & F_6 ( V_2 , 0x00000200U ) ) && -- V_11 ; ) {
}
* ( V_4 ++ ) = F_6 ( V_2 , 0x0000020CU ) ;
}
F_4 ( V_2 , 1U , V_7 ) ;
V_10:
return V_6 ;
}
static int F_7 ( struct V_1 * V_2 , T_1 V_3 , T_1 * V_4 ,
T_1 V_5 )
{
int V_6 = 0 ;
bool V_8 ;
V_8 = F_3 ( V_2 , V_7 ) ;
if ( ! V_8 ) {
V_6 = - V_9 ;
goto V_10;
}
F_5 ( V_2 , 0x00000208U , V_3 ) ;
for ( ++ V_5 ; -- V_5 ; ) {
T_1 V_11 = 0U ;
F_5 ( V_2 , 0x0000020CU , * ( V_4 ++ ) ) ;
F_5 ( V_2 , 0x00000200U , 0xC000U ) ;
for ( V_11 = 1024U ;
( 0x100U & F_6 ( V_2 , 0x00000200U ) ) && -- V_11 ; ) {
}
}
F_4 ( V_2 , 1U , V_7 ) ;
V_10:
return V_6 ;
}
static int F_8 ( T_1 V_12 , T_1 V_13 )
{
int V_6 = 0 ;
const T_1 V_14 = 0xff000000U ;
const T_1 V_15 = 0x00ffffffU ;
V_6 = ( V_14 & ( V_12 ^ V_13 ) ) ? - V_16 : 0 ;
if ( V_6 < 0 )
goto V_10;
V_6 = ( ( V_15 & V_12 ) > ( V_15 & V_13 ) ) ?
- V_16 : 0 ;
V_10:
return V_6 ;
}
static int F_9 ( struct V_1 * V_2 ,
struct V_17 * V_18 )
{
int V_6 = 0 ;
if ( ! F_6 ( V_2 , 0x370U ) ) {
unsigned int V_19 = 0U ;
unsigned int V_20 = 0U ;
F_10 ( & V_19 , sizeof( unsigned int ) ) ;
V_20 = 0x02020202U | ( 0xFEFEFEFEU & V_19 ) ;
F_5 ( V_2 , V_21 , V_20 ) ;
}
F_11 ( V_2 , 0x00000000U , 25U ) ;
F_2 ( 0U != ( V_22 -> V_23 =
F_6 ( V_2 , 0x360U ) ) , 1000U , 10U ) ;
V_6 = F_8 ( V_18 -> V_24 ,
F_6 ( V_2 , 0x18U ) ) ;
return V_6 ;
}
static int F_12 ( struct V_1 * V_2 , unsigned int V_25 )
{
int V_6 = 0 ;
struct V_26 V_27 ;
if ( ! F_13 ( V_28 ) ) {
V_6 = - 1 ;
goto V_10;
}
V_6 = F_7 ( V_2 , V_29 -> V_30 ,
( T_1 * ) ( void * ) & V_29 -> V_31 ,
( V_25 + sizeof( T_1 ) -
sizeof( V_32 ) ) / sizeof( T_1 ) ) ;
if ( V_6 < 0 )
goto V_10;
V_27 . V_33 = 0xFFFFU & ( ++ V_29 -> V_34 ) ;
V_27 . V_35 = ( V_36 ) V_25 ;
F_5 ( V_2 , V_37 , V_27 . V_38 ) ;
V_10:
return V_6 ;
}
static int F_14 ( struct V_1 * V_2 ,
struct V_39 * * V_31 )
{
int V_6 = 0 ;
struct V_26 V_27 ;
struct V_26 V_40 ;
do {
V_27 . V_38 = F_6 ( V_2 , V_37 ) ;
V_29 -> V_34 = V_27 . V_33 ;
F_2 ( V_27 . V_33 ==
( V_40 . V_38 =
F_6 ( V_2 , V_41 ) ,
V_40 . V_33 ) , 1000U , 100U ) ;
if ( V_6 < 0 )
goto V_10;
if ( V_40 . V_35 == 0xFFFFU ) {
V_6 = F_12 ( V_2 , V_27 . V_35 ) ;
if ( V_6 < 0 )
goto V_10;
}
} while ( V_27 . V_33 != V_40 . V_33 || 0xFFFFU == V_40 . V_35 );
if ( V_6 < 0 )
goto V_10;
if ( V_31 ) {
if ( V_40 . V_35 ) {
V_6 =
F_1 ( V_2 ,
V_29 -> V_30 ,
( T_1 * ) ( void * )
& V_29 -> V_31 ,
( V_40 . V_35 + sizeof( T_1 ) -
sizeof( V_32 ) ) /
sizeof( T_1 ) ) ;
if ( V_6 < 0 )
goto V_10;
}
* V_31 = & V_29 -> V_31 ;
}
V_10:
return V_6 ;
}
static int F_15 ( struct V_1 * V_2 ,
struct V_17 * V_18 )
{
int V_6 = 0 ;
V_6 = F_9 ( V_2 , V_18 ) ;
if ( V_6 < 0 )
goto V_10;
V_6 = F_16 ( V_2 ) ;
if ( V_6 < 0 )
goto V_10;
V_10:
return V_6 ;
}
void F_17 ( struct V_1 * V_2 ,
struct V_42 * V_43 )
{
int V_6 = 0 ;
V_6 = F_1 ( V_2 ,
V_29 -> V_23 ,
( T_1 * ) ( void * ) V_43 ,
sizeof( * V_43 ) / sizeof( T_1 ) ) ;
if ( V_6 < 0 )
goto V_10;
if ( V_43 != & V_29 -> V_44 )
memcpy ( V_43 , & V_29 -> V_44 , sizeof( * V_43 ) ) ;
if ( F_13 ( V_45 ) ) {
unsigned int V_46 = V_2 -> V_47 ?
V_2 -> V_47 -> V_46 : 1514U ;
V_43 -> V_48 . V_49 = V_43 -> V_48 . V_50 * V_46 ;
V_43 -> V_48 . V_51 = V_43 -> V_48 . V_52 * V_46 ;
V_43 -> V_48 . V_53 = F_18 ( & V_22 -> V_53 ) ;
} else {
V_43 -> V_48 . V_53 = F_19 ( V_2 ) ;
}
V_10: ;
}
int F_20 ( struct V_1 * V_2 , T_1 V_54 ,
enum V_55 V_56 )
{
T_1 V_57 = 0 ;
V_57 = ( V_54 << V_58 ) | V_56 ;
F_5 ( V_2 , V_59 , V_57 ) ;
return 0 ;
}
void F_21 ( struct V_1 * V_2 ,
enum V_55 V_56 , T_1 V_54 )
{
int V_6 = 0 ;
T_1 V_60 = 0 ;
if ( V_56 == V_61 ) {
F_17 ( V_2 , & V_29 -> V_44 ) ;
V_60 = V_29 -> V_44 . V_60 ;
F_2 ( V_60 !=
( F_17
( V_2 , & V_29 -> V_44 ) ,
V_29 -> V_44 . V_60 ) ,
1000U , 100U ) ;
if ( V_6 < 0 )
goto V_10;
}
V_6 = F_20 ( V_2 , V_54 , V_56 ) ;
V_10: ;
}
int F_22 ( struct V_1 * V_2 ,
struct V_62 * V_63 )
{
T_1 V_64 = F_6 ( V_2 , V_65 ) ;
T_1 V_66 = V_64 >> V_58 ;
if ( ! V_66 ) {
V_63 -> V_67 = 0U ;
} else {
switch ( V_66 ) {
case V_68 :
V_63 -> V_67 = 10000U ;
break;
case V_69 :
case V_70 :
V_63 -> V_67 = 5000U ;
break;
case V_71 :
V_63 -> V_67 = 2500U ;
break;
case V_72 :
V_63 -> V_67 = 1000U ;
break;
case V_73 :
V_63 -> V_67 = 100U ;
break;
default:
V_63 -> V_67 = 0U ;
break;
}
}
return 0 ;
}
int F_23 ( struct V_1 * V_2 ,
struct V_17 * V_18 ,
V_32 * V_74 )
{
int V_6 = 0 ;
T_1 V_75 = 0U ;
T_1 V_76 = 0U ;
T_1 V_77 [ 2 ] ;
V_2 -> V_78 = F_24 ( V_2 -> V_79 ) ;
F_25 ( V_2 ,
& V_22 -> V_80 ) ;
V_6 = F_15 ( V_2 , V_18 ) ;
if ( V_6 < 0 )
goto V_10;
if ( ! F_6 ( V_2 , V_21 ) ) {
unsigned int V_19 = 0 ;
unsigned int V_20 = 0 ;
F_10 ( & V_19 , sizeof( unsigned int ) ) ;
V_20 = 0x02020202 | ( 0xFEFEFEFE & V_19 ) ;
F_5 ( V_2 , V_21 , V_20 ) ;
}
V_6 = F_1 ( V_2 ,
F_6 ( V_2 , 0x00000374U ) +
( 40U * 4U ) ,
V_77 ,
F_26 ( V_77 ) ) ;
if ( V_6 < 0 ) {
V_77 [ 0 ] = 0U ;
V_77 [ 1 ] = 0U ;
V_6 = 0 ;
} else {
V_77 [ 0 ] = F_27 ( V_77 [ 0 ] ) ;
V_77 [ 1 ] = F_27 ( V_77 [ 1 ] ) ;
}
F_28 ( V_74 , ( V_32 * ) V_77 ) ;
if ( ( V_74 [ 0 ] & 0x01U ) || ( ( V_74 [ 0 ] | V_74 [ 1 ] | V_74 [ 2 ] ) == 0x00U ) ) {
V_76 = 0xE3000000U
| ( 0xFFFFU & F_6 ( V_2 , V_21 ) )
| ( 0x00 << 16 ) ;
V_75 = 0x8001300EU ;
V_74 [ 5 ] = ( V_32 ) ( 0xFFU & V_76 ) ;
V_76 >>= 8 ;
V_74 [ 4 ] = ( V_32 ) ( 0xFFU & V_76 ) ;
V_76 >>= 8 ;
V_74 [ 3 ] = ( V_32 ) ( 0xFFU & V_76 ) ;
V_76 >>= 8 ;
V_74 [ 2 ] = ( V_32 ) ( 0xFFU & V_76 ) ;
V_74 [ 1 ] = ( V_32 ) ( 0xFFU & V_75 ) ;
V_75 >>= 8 ;
V_74 [ 0 ] = ( V_32 ) ( 0xFFU & V_75 ) ;
}
V_10:
return V_6 ;
}
unsigned int F_29 ( unsigned int V_67 )
{
unsigned int V_81 = 0U ;
switch ( V_67 ) {
case 100U :
V_81 = 5U ;
break;
case 1000U :
V_81 = 4U ;
break;
case 2500U :
V_81 = 3U ;
break;
case 5000U :
V_81 = 1U ;
break;
case 10000U :
V_81 = 0U ;
break;
default:
break;
}
return V_81 ;
}
void F_25 ( struct V_1 * V_2 , T_1 * V_4 )
{
T_1 V_80 = 0U ;
T_1 V_38 = F_30 ( V_2 ) ;
T_1 V_82 = V_38 & 0xFFU ;
if ( ( 3U & V_82 ) == 1U ) {
V_80 |=
V_83 |
V_84 |
V_85 ;
} else if ( ( 3U & V_82 ) == 2U ) {
V_80 |=
V_86 |
V_84 |
V_85 |
V_87 |
V_88 ;
}
* V_4 = V_80 ;
}
int F_31 ( struct V_1 * V_2 )
{
F_21 ( V_2 , V_89 , 0x0U ) ;
return 0 ;
}
int F_32 ( struct V_1 * V_2 ,
unsigned int V_90 )
{
F_21 ( V_2 , V_91 , 0x0U ) ;
return 0 ;
}
int F_33 ( struct V_1 * V_2 ,
T_2 * V_92 , unsigned int * V_93 )
{
struct V_94 * V_48 = NULL ;
int V_11 = 0 ;
F_17 ( V_2 , & V_29 -> V_44 ) ;
V_48 = & V_29 -> V_44 . V_48 ;
V_92 [ V_11 ] = V_48 -> V_50 + V_48 -> V_95 + V_48 -> V_96 ;
V_92 [ ++ V_11 ] = V_48 -> V_50 ;
V_92 [ ++ V_11 ] = V_48 -> V_95 ;
V_92 [ ++ V_11 ] = V_48 -> V_96 ;
V_92 [ ++ V_11 ] = V_48 -> V_97 ;
V_92 [ ++ V_11 ] = V_48 -> V_52 + V_48 -> V_98 + V_48 -> V_99 ;
V_92 [ ++ V_11 ] = V_48 -> V_52 ;
V_92 [ ++ V_11 ] = V_48 -> V_98 ;
V_92 [ ++ V_11 ] = V_48 -> V_99 ;
V_92 [ ++ V_11 ] = V_48 -> V_49 ;
V_92 [ ++ V_11 ] = V_48 -> V_51 ;
V_92 [ ++ V_11 ] = V_48 -> V_100 ;
V_92 [ ++ V_11 ] = V_48 -> V_101 ;
V_92 [ ++ V_11 ] = V_48 -> V_102 ;
V_92 [ ++ V_11 ] = V_48 -> V_103 ;
V_92 [ ++ V_11 ] = V_48 -> V_49 + V_48 -> V_100 + V_48 -> V_102 ;
V_92 [ ++ V_11 ] = V_48 -> V_51 + V_48 -> V_101 + V_48 -> V_103 ;
V_92 [ ++ V_11 ] = F_34 ( V_2 ) ;
V_92 [ ++ V_11 ] = F_35 ( V_2 ) ;
V_92 [ ++ V_11 ] = F_36 ( V_2 ) ;
V_92 [ ++ V_11 ] = F_37 ( V_2 ) ;
V_92 [ ++ V_11 ] = V_48 -> V_53 ;
if ( V_93 )
* V_93 = ++ V_11 ;
return 0 ;
}
int F_38 ( struct V_1 * V_2 ,
struct V_17 * V_18 ,
T_1 * V_104 )
{
unsigned int V_11 = 0U ;
for ( V_11 = 0 ; V_11 < V_18 -> V_105 ; V_11 ++ )
V_104 [ V_11 ] = F_6 ( V_2 ,
V_106 [ V_11 ] ) ;
return 0 ;
}
int F_39 ( struct V_1 * V_2 , T_1 * V_107 )
{
* V_107 = F_6 ( V_2 , 0x18U ) ;
return 0 ;
}
