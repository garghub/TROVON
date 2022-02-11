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
if ( V_6 < 0 )
F_12 ( L_1 ,
V_25 ,
V_18 -> V_24 ,
F_6 ( V_2 , 0x18U ) ) ;
return V_6 ;
}
static int F_13 ( struct V_1 * V_2 , unsigned int V_26 )
{
int V_6 = 0 ;
struct V_27 V_28 ;
if ( ! F_14 ( V_29 ) ) {
V_6 = - 1 ;
goto V_10;
}
V_6 = F_7 ( V_2 , V_30 -> V_31 ,
( T_1 * ) ( void * ) & V_30 -> V_32 ,
( V_26 + sizeof( T_1 ) -
sizeof( V_33 ) ) / sizeof( T_1 ) ) ;
if ( V_6 < 0 )
goto V_10;
V_28 . V_34 = 0xFFFFU & ( ++ V_30 -> V_35 ) ;
V_28 . V_36 = ( V_37 ) V_26 ;
F_5 ( V_2 , V_38 , V_28 . V_39 ) ;
V_10:
return V_6 ;
}
static int F_15 ( struct V_1 * V_2 ,
struct V_40 * * V_32 )
{
int V_6 = 0 ;
struct V_27 V_28 ;
struct V_27 V_41 ;
do {
V_28 . V_39 = F_6 ( V_2 , V_38 ) ;
V_30 -> V_35 = V_28 . V_34 ;
F_2 ( V_28 . V_34 ==
( V_41 . V_39 =
F_6 ( V_2 , V_42 ) ,
V_41 . V_34 ) , 1000U , 100U ) ;
if ( V_6 < 0 )
goto V_10;
if ( V_41 . V_36 == 0xFFFFU ) {
V_6 = F_13 ( V_2 , V_28 . V_36 ) ;
if ( V_6 < 0 )
goto V_10;
}
} while ( V_28 . V_34 != V_41 . V_34 || 0xFFFFU == V_41 . V_36 );
if ( V_6 < 0 )
goto V_10;
if ( V_32 ) {
if ( V_41 . V_36 ) {
V_6 =
F_1 ( V_2 ,
V_30 -> V_31 ,
( T_1 * ) ( void * )
& V_30 -> V_32 ,
( V_41 . V_36 + sizeof( T_1 ) -
sizeof( V_33 ) ) /
sizeof( T_1 ) ) ;
if ( V_6 < 0 )
goto V_10;
}
* V_32 = & V_30 -> V_32 ;
}
V_10:
return V_6 ;
}
static int F_16 ( struct V_1 * V_2 ,
struct V_17 * V_18 )
{
int V_6 = 0 ;
V_6 = F_9 ( V_2 , V_18 ) ;
if ( V_6 < 0 )
goto V_10;
V_6 = F_17 ( V_2 ) ;
if ( V_6 < 0 )
goto V_10;
V_10:
return V_6 ;
}
int F_18 ( struct V_1 * V_2 ,
struct V_43 * V_44 )
{
return F_1 ( V_2 ,
V_30 -> V_23 ,
( T_1 * ) ( void * ) V_44 ,
sizeof( * V_44 ) / sizeof( T_1 ) ) ;
}
void F_19 ( struct V_1 * V_2 ,
struct V_45 * V_44 )
{
int V_6 = 0 ;
V_6 = F_1 ( V_2 ,
V_30 -> V_23 ,
( T_1 * ) ( void * ) V_44 ,
sizeof( * V_44 ) / sizeof( T_1 ) ) ;
if ( V_6 < 0 )
goto V_10;
if ( F_14 ( V_46 ) ) {
unsigned int V_47 = V_2 -> V_48 ?
V_2 -> V_48 -> V_47 : 1514U ;
V_44 -> V_49 . V_50 = V_44 -> V_49 . V_51 * V_47 ;
V_44 -> V_49 . V_52 = V_44 -> V_49 . V_53 * V_47 ;
V_44 -> V_49 . V_54 = F_20 ( & V_22 -> V_54 ) ;
} else {
V_44 -> V_49 . V_54 = F_21 ( V_2 ) ;
}
V_10: ;
}
int F_22 ( struct V_1 * V_2 , T_1 V_55 ,
enum V_56 V_57 )
{
T_1 V_58 = 0 ;
V_58 = ( V_55 << V_59 ) | V_57 ;
F_5 ( V_2 , V_60 , V_58 ) ;
return 0 ;
}
void F_23 ( struct V_1 * V_2 ,
enum V_56 V_57 , T_1 V_55 )
{
int V_6 = 0 ;
T_1 V_61 = 0 ;
struct V_43 V_62 ;
if ( V_57 == V_63 ) {
F_18 ( V_2 , & V_62 ) ;
V_61 = V_62 . V_61 ;
F_2 ( V_61 !=
( F_18 ( V_2 , & V_62 ) ,
V_62 . V_61 ) ,
1000U , 100U ) ;
if ( V_6 < 0 )
goto V_10;
}
V_6 = F_22 ( V_2 , V_55 , V_57 ) ;
V_10: ;
}
int F_24 ( struct V_1 * V_2 )
{
T_1 V_64 = F_6 ( V_2 , V_65 ) ;
T_1 V_66 = V_64 >> V_59 ;
struct V_67 * V_68 = & V_2 -> V_69 ;
if ( ! V_66 ) {
V_68 -> V_70 = 0U ;
} else {
switch ( V_66 ) {
case V_71 :
V_68 -> V_70 = 10000U ;
break;
case V_72 :
case V_73 :
V_68 -> V_70 = 5000U ;
break;
case V_74 :
V_68 -> V_70 = 2500U ;
break;
case V_75 :
V_68 -> V_70 = 1000U ;
break;
case V_76 :
V_68 -> V_70 = 100U ;
break;
default:
return - V_77 ;
}
}
return 0 ;
}
int F_25 ( struct V_1 * V_2 ,
struct V_17 * V_18 ,
V_33 * V_78 )
{
int V_6 = 0 ;
T_1 V_79 = 0U ;
T_1 V_80 = 0U ;
T_1 V_81 [ 2 ] ;
V_2 -> V_82 = F_26 ( V_2 -> V_83 ) ;
F_27 ( V_2 ,
& V_22 -> V_84 ) ;
V_6 = F_16 ( V_2 , V_18 ) ;
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
V_81 ,
F_28 ( V_81 ) ) ;
if ( V_6 < 0 ) {
V_81 [ 0 ] = 0U ;
V_81 [ 1 ] = 0U ;
V_6 = 0 ;
} else {
V_81 [ 0 ] = F_29 ( V_81 [ 0 ] ) ;
V_81 [ 1 ] = F_29 ( V_81 [ 1 ] ) ;
}
F_30 ( V_78 , ( V_33 * ) V_81 ) ;
if ( ( V_78 [ 0 ] & 0x01U ) || ( ( V_78 [ 0 ] | V_78 [ 1 ] | V_78 [ 2 ] ) == 0x00U ) ) {
V_80 = 0xE3000000U
| ( 0xFFFFU & F_6 ( V_2 , V_21 ) )
| ( 0x00 << 16 ) ;
V_79 = 0x8001300EU ;
V_78 [ 5 ] = ( V_33 ) ( 0xFFU & V_80 ) ;
V_80 >>= 8 ;
V_78 [ 4 ] = ( V_33 ) ( 0xFFU & V_80 ) ;
V_80 >>= 8 ;
V_78 [ 3 ] = ( V_33 ) ( 0xFFU & V_80 ) ;
V_80 >>= 8 ;
V_78 [ 2 ] = ( V_33 ) ( 0xFFU & V_80 ) ;
V_78 [ 1 ] = ( V_33 ) ( 0xFFU & V_79 ) ;
V_79 >>= 8 ;
V_78 [ 0 ] = ( V_33 ) ( 0xFFU & V_79 ) ;
}
V_10:
return V_6 ;
}
unsigned int F_31 ( unsigned int V_70 )
{
unsigned int V_85 = 0U ;
switch ( V_70 ) {
case 100U :
V_85 = 5U ;
break;
case 1000U :
V_85 = 4U ;
break;
case 2500U :
V_85 = 3U ;
break;
case 5000U :
V_85 = 1U ;
break;
case 10000U :
V_85 = 0U ;
break;
default:
break;
}
return V_85 ;
}
void F_27 ( struct V_1 * V_2 , T_1 * V_4 )
{
T_1 V_84 = 0U ;
T_1 V_39 = F_32 ( V_2 ) ;
T_1 V_86 = V_39 & 0xFFU ;
if ( ( 3U & V_86 ) == 1U ) {
V_84 |=
V_87 |
V_88 |
V_89 ;
} else if ( ( 3U & V_86 ) == 2U ) {
V_84 |=
V_90 |
V_88 |
V_89 |
V_91 |
V_92 ;
}
* V_4 = V_84 ;
}
int F_33 ( struct V_1 * V_2 )
{
F_23 ( V_2 , V_93 , 0x0U ) ;
return 0 ;
}
int F_34 ( struct V_1 * V_2 ,
unsigned int V_94 )
{
F_23 ( V_2 , V_95 , 0x0U ) ;
return 0 ;
}
int F_35 ( struct V_1 * V_2 )
{
struct V_96 * V_97 = V_30 ;
struct V_45 V_62 ;
if ( ! V_2 -> V_69 . V_70 )
return 0 ;
F_19 ( V_2 , & V_62 ) ;
#define F_36 ( T_2 ) (hw_self->curr_stats._N_ += \
mbox.stats._N_ - hw_self->last_stats._N_)
F_36 ( V_51 ) ;
F_36 ( V_98 ) ;
F_36 ( V_99 ) ;
F_36 ( V_100 ) ;
F_36 ( V_53 ) ;
F_36 ( V_101 ) ;
F_36 ( V_102 ) ;
F_36 ( V_103 ) ;
F_36 ( V_50 ) ;
F_36 ( V_52 ) ;
F_36 ( V_104 ) ;
F_36 ( V_105 ) ;
F_36 ( V_106 ) ;
F_36 ( V_107 ) ;
F_36 ( V_54 ) ;
#undef F_36
memcpy ( & V_97 -> V_108 , & V_62 . V_49 , sizeof( V_62 . V_49 ) ) ;
return 0 ;
}
int F_37 ( struct V_1 * V_2 ,
T_3 * V_109 , unsigned int * V_110 )
{
struct V_96 * V_97 = V_30 ;
struct V_111 * V_49 = & V_97 -> V_112 ;
int V_11 = 0 ;
V_109 [ V_11 ] = V_49 -> V_51 + V_49 -> V_98 + V_49 -> V_99 ;
V_109 [ ++ V_11 ] = V_49 -> V_51 ;
V_109 [ ++ V_11 ] = V_49 -> V_98 ;
V_109 [ ++ V_11 ] = V_49 -> V_99 ;
V_109 [ ++ V_11 ] = V_49 -> V_100 ;
V_109 [ ++ V_11 ] = V_49 -> V_53 + V_49 -> V_101 + V_49 -> V_102 ;
V_109 [ ++ V_11 ] = V_49 -> V_53 ;
V_109 [ ++ V_11 ] = V_49 -> V_101 ;
V_109 [ ++ V_11 ] = V_49 -> V_102 ;
V_109 [ ++ V_11 ] = V_49 -> V_50 ;
V_109 [ ++ V_11 ] = V_49 -> V_52 ;
V_109 [ ++ V_11 ] = V_49 -> V_104 ;
V_109 [ ++ V_11 ] = V_49 -> V_105 ;
V_109 [ ++ V_11 ] = V_49 -> V_106 ;
V_109 [ ++ V_11 ] = V_49 -> V_107 ;
V_109 [ ++ V_11 ] = V_49 -> V_50 + V_49 -> V_104 + V_49 -> V_106 ;
V_109 [ ++ V_11 ] = V_49 -> V_52 + V_49 -> V_105 + V_49 -> V_107 ;
V_109 [ ++ V_11 ] = F_38 ( V_2 ) ;
V_109 [ ++ V_11 ] = F_39 ( V_2 ) ;
V_109 [ ++ V_11 ] = F_40 ( V_2 ) ;
V_109 [ ++ V_11 ] = F_41 ( V_2 ) ;
V_109 [ ++ V_11 ] = V_49 -> V_54 ;
if ( V_110 )
* V_110 = ++ V_11 ;
return 0 ;
}
int F_42 ( struct V_1 * V_2 ,
struct V_17 * V_18 ,
T_1 * V_113 )
{
unsigned int V_11 = 0U ;
for ( V_11 = 0 ; V_11 < V_18 -> V_114 ; V_11 ++ )
V_113 [ V_11 ] = F_6 ( V_2 ,
V_115 [ V_11 ] ) ;
return 0 ;
}
int F_43 ( struct V_1 * V_2 , T_1 * V_116 )
{
* V_116 = F_6 ( V_2 , 0x18U ) ;
return 0 ;
}
