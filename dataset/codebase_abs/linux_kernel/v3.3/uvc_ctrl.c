static T_1 F_1 ( struct V_1 * V_2 ,
T_2 V_3 , const T_2 * V_4 )
{
T_3 V_5 = ( T_3 ) V_4 [ 0 ] ;
switch ( V_3 ) {
case V_6 :
return ( V_5 == 0 ) ? 0 : ( V_5 > 0 ? V_4 [ 2 ] : - V_4 [ 2 ] ) ;
case V_7 :
case V_8 :
case V_9 :
case V_10 :
default:
return V_4 [ 2 ] ;
}
}
static void F_2 ( struct V_1 * V_2 ,
T_1 V_11 , T_2 * V_4 )
{
V_4 [ 0 ] = V_11 == 0 ? 0 : ( V_11 > 0 ) ? 1 : 0xff ;
V_4 [ 2 ] = F_3 ( ( int ) abs ( V_11 ) , 0xff ) ;
}
static inline T_2 * F_4 ( struct V_12 * V_13 , int V_14 )
{
return V_13 -> V_15 + V_14 * V_13 -> V_16 . V_17 ;
}
static inline int F_5 ( const T_2 * V_4 , int V_18 )
{
return ( V_4 [ V_18 >> 3 ] >> ( V_18 & 7 ) ) & 1 ;
}
static inline void F_6 ( T_2 * V_4 , int V_18 )
{
V_4 [ V_18 >> 3 ] &= ~ ( 1 << ( V_18 & 7 ) ) ;
}
static T_1 F_7 ( struct V_1 * V_2 ,
T_2 V_3 , const T_2 * V_4 )
{
int V_19 = V_2 -> V_17 ;
int V_20 = V_2 -> V_20 ;
T_1 V_11 = 0 ;
T_2 V_21 ;
V_4 += V_20 / 8 ;
V_20 &= 7 ;
V_21 = ( ( 1LL << V_19 ) - 1 ) << V_20 ;
for (; V_19 > 0 ; V_4 ++ ) {
T_2 V_22 = * V_4 & V_21 ;
V_11 |= V_20 > 0 ? ( V_22 >> V_20 ) : ( V_22 << ( - V_20 ) ) ;
V_19 -= 8 - ( V_20 > 0 ? V_20 : 0 ) ;
V_20 -= 8 ;
V_21 = ( 1 << V_19 ) - 1 ;
}
if ( V_2 -> V_23 == V_24 )
V_11 |= - ( V_11 & ( 1 << ( V_2 -> V_17 - 1 ) ) ) ;
return V_11 ;
}
static void F_8 ( struct V_1 * V_2 ,
T_1 V_11 , T_2 * V_4 )
{
int V_19 = V_2 -> V_17 ;
int V_20 = V_2 -> V_20 ;
T_2 V_21 ;
if ( V_2 -> V_25 == V_26 )
V_11 = - 1 ;
V_4 += V_20 / 8 ;
V_20 &= 7 ;
for (; V_19 > 0 ; V_4 ++ ) {
V_21 = ( ( 1LL << V_19 ) - 1 ) << V_20 ;
* V_4 = ( * V_4 & ~ V_21 ) | ( ( V_11 << V_20 ) & V_21 ) ;
V_11 >>= V_20 ? V_20 : 8 ;
V_19 -= 8 - V_20 ;
V_20 = 0 ;
}
}
static int F_9 ( const struct V_27 * V_28 ,
const T_2 V_29 [ 16 ] )
{
switch ( F_10 ( V_28 ) ) {
case V_30 :
return memcmp ( V_31 , V_29 , 16 ) == 0 ;
case V_32 :
return memcmp ( V_33 , V_29 , 16 ) == 0 ;
case V_34 :
return memcmp ( V_35 , V_29 , 16 ) == 0 ;
case V_36 :
return memcmp ( V_28 -> V_37 . V_38 ,
V_29 , 16 ) == 0 ;
default:
return 0 ;
}
}
static void F_11 ( struct V_27 * V_28 , T_4 V_39 ,
struct V_1 * * V_2 , struct V_12 * * V_40 ,
int V_41 )
{
struct V_12 * V_13 ;
struct V_1 * V_42 ;
unsigned int V_43 ;
if ( V_28 == NULL )
return;
for ( V_43 = 0 ; V_43 < V_28 -> V_44 ; ++ V_43 ) {
V_13 = & V_28 -> V_45 [ V_43 ] ;
if ( ! V_13 -> V_46 )
continue;
F_12 (map, &ctrl->info.mappings, list) {
if ( ( V_42 -> V_14 == V_39 ) && ! V_41 ) {
* V_40 = V_13 ;
* V_2 = V_42 ;
return;
}
if ( ( * V_2 == NULL || ( * V_2 ) -> V_14 > V_42 -> V_14 ) &&
( V_42 -> V_14 > V_39 ) && V_41 ) {
* V_40 = V_13 ;
* V_2 = V_42 ;
}
}
}
}
static struct V_12 * F_13 ( struct V_47 * V_48 ,
T_4 V_39 , struct V_1 * * V_2 )
{
struct V_12 * V_13 = NULL ;
struct V_27 * V_28 ;
int V_41 = V_39 & V_49 ;
* V_2 = NULL ;
V_39 &= V_50 ;
F_12 (entity, &chain->entities, chain) {
F_11 ( V_28 , V_39 , V_2 , & V_13 , V_41 ) ;
if ( V_13 && ! V_41 )
return V_13 ;
}
if ( V_13 == NULL && ! V_41 )
F_14 ( V_51 , L_1 ,
V_39 ) ;
return V_13 ;
}
static int F_15 ( struct V_47 * V_48 ,
struct V_12 * V_13 )
{
int V_52 ;
if ( V_13 -> V_16 . V_53 & V_54 ) {
V_52 = F_16 ( V_48 -> V_55 , V_10 , V_13 -> V_28 -> V_14 ,
V_48 -> V_55 -> V_56 , V_13 -> V_16 . V_57 ,
F_4 ( V_13 , V_58 ) ,
V_13 -> V_16 . V_17 ) ;
if ( V_52 < 0 )
return V_52 ;
}
if ( V_13 -> V_16 . V_53 & V_59 ) {
V_52 = F_16 ( V_48 -> V_55 , V_7 , V_13 -> V_28 -> V_14 ,
V_48 -> V_55 -> V_56 , V_13 -> V_16 . V_57 ,
F_4 ( V_13 , V_60 ) ,
V_13 -> V_16 . V_17 ) ;
if ( V_52 < 0 )
return V_52 ;
}
if ( V_13 -> V_16 . V_53 & V_61 ) {
V_52 = F_16 ( V_48 -> V_55 , V_8 , V_13 -> V_28 -> V_14 ,
V_48 -> V_55 -> V_56 , V_13 -> V_16 . V_57 ,
F_4 ( V_13 , V_62 ) ,
V_13 -> V_16 . V_17 ) ;
if ( V_52 < 0 )
return V_52 ;
}
if ( V_13 -> V_16 . V_53 & V_63 ) {
V_52 = F_16 ( V_48 -> V_55 , V_9 , V_13 -> V_28 -> V_14 ,
V_48 -> V_55 -> V_56 , V_13 -> V_16 . V_57 ,
F_4 ( V_13 , V_64 ) ,
V_13 -> V_16 . V_17 ) ;
if ( V_52 < 0 ) {
if ( F_10 ( V_13 -> V_28 ) !=
V_36 )
return V_52 ;
F_17 ( V_48 -> V_55 , V_65 ,
L_2
L_3 ) ;
memset ( F_4 ( V_13 , V_64 ) , 0 ,
V_13 -> V_16 . V_17 ) ;
}
}
V_13 -> V_66 = 1 ;
return 0 ;
}
int F_18 ( struct V_47 * V_48 ,
struct V_67 * V_68 )
{
struct V_12 * V_13 ;
struct V_1 * V_2 ;
struct V_69 * V_70 ;
unsigned int V_43 ;
int V_52 ;
V_52 = F_19 ( & V_48 -> V_71 ) ;
if ( V_52 < 0 )
return - V_72 ;
V_13 = F_13 ( V_48 , V_68 -> V_14 , & V_2 ) ;
if ( V_13 == NULL ) {
V_52 = - V_73 ;
goto V_74;
}
memset ( V_68 , 0 , sizeof *V_68 ) ;
V_68 -> V_14 = V_2 -> V_14 ;
V_68 -> type = V_2 -> V_25 ;
F_20 ( V_68 -> V_75 , V_2 -> V_75 , sizeof V_68 -> V_75 ) ;
V_68 -> V_53 = 0 ;
if ( ! ( V_13 -> V_16 . V_53 & V_76 ) )
V_68 -> V_53 |= V_77 ;
if ( ! ( V_13 -> V_16 . V_53 & V_78 ) )
V_68 -> V_53 |= V_79 ;
if ( ! V_13 -> V_66 ) {
V_52 = F_15 ( V_48 , V_13 ) ;
if ( V_52 < 0 )
goto V_74;
}
if ( V_13 -> V_16 . V_53 & V_54 ) {
V_68 -> V_80 = V_2 -> V_81 ( V_2 , V_10 ,
F_4 ( V_13 , V_58 ) ) ;
}
switch ( V_2 -> V_25 ) {
case V_82 :
V_68 -> V_83 = 0 ;
V_68 -> V_84 = V_2 -> V_85 - 1 ;
V_68 -> V_86 = 1 ;
V_70 = V_2 -> V_87 ;
for ( V_43 = 0 ; V_43 < V_2 -> V_85 ; ++ V_43 , ++ V_70 ) {
if ( V_70 -> V_11 == V_68 -> V_80 ) {
V_68 -> V_80 = V_43 ;
break;
}
}
goto V_74;
case V_88 :
V_68 -> V_83 = 0 ;
V_68 -> V_84 = 1 ;
V_68 -> V_86 = 1 ;
goto V_74;
case V_26 :
V_68 -> V_83 = 0 ;
V_68 -> V_84 = 0 ;
V_68 -> V_86 = 0 ;
goto V_74;
default:
break;
}
if ( V_13 -> V_16 . V_53 & V_59 )
V_68 -> V_83 = V_2 -> V_81 ( V_2 , V_7 ,
F_4 ( V_13 , V_60 ) ) ;
if ( V_13 -> V_16 . V_53 & V_61 )
V_68 -> V_84 = V_2 -> V_81 ( V_2 , V_8 ,
F_4 ( V_13 , V_62 ) ) ;
if ( V_13 -> V_16 . V_53 & V_63 )
V_68 -> V_86 = V_2 -> V_81 ( V_2 , V_9 ,
F_4 ( V_13 , V_64 ) ) ;
V_74:
F_21 ( & V_48 -> V_71 ) ;
return V_52 ;
}
int F_22 ( struct V_47 * V_48 ,
struct V_89 * V_90 )
{
struct V_69 * V_87 ;
struct V_1 * V_2 ;
struct V_12 * V_13 ;
T_5 V_91 = V_90 -> V_91 ;
T_5 V_14 = V_90 -> V_14 ;
int V_52 ;
memset ( V_90 , 0 , sizeof( * V_90 ) ) ;
V_90 -> V_14 = V_14 ;
V_90 -> V_91 = V_91 ;
V_52 = F_19 ( & V_48 -> V_71 ) ;
if ( V_52 < 0 )
return - V_72 ;
V_13 = F_13 ( V_48 , V_90 -> V_14 , & V_2 ) ;
if ( V_13 == NULL || V_2 -> V_25 != V_82 ) {
V_52 = - V_73 ;
goto V_74;
}
if ( V_90 -> V_91 >= V_2 -> V_85 ) {
V_52 = - V_73 ;
goto V_74;
}
V_87 = & V_2 -> V_87 [ V_90 -> V_91 ] ;
if ( V_2 -> V_23 == V_92 &&
( V_13 -> V_16 . V_53 & V_63 ) ) {
T_6 V_93 ;
if ( ! V_13 -> V_66 ) {
V_52 = F_15 ( V_48 , V_13 ) ;
if ( V_52 < 0 )
goto V_74;
}
V_93 = V_2 -> V_81 ( V_2 , V_9 ,
F_4 ( V_13 , V_64 ) ) ;
if ( ! ( V_93 & V_87 -> V_11 ) ) {
V_52 = - V_73 ;
goto V_74;
}
}
F_20 ( V_90 -> V_75 , V_87 -> V_75 , sizeof V_90 -> V_75 ) ;
V_74:
F_21 ( & V_48 -> V_71 ) ;
return V_52 ;
}
int F_23 ( struct V_47 * V_48 )
{
return F_19 ( & V_48 -> V_71 ) ? - V_72 : 0 ;
}
static int F_24 ( struct V_94 * V_55 ,
struct V_27 * V_28 , int V_95 )
{
struct V_12 * V_13 ;
unsigned int V_43 ;
int V_52 ;
if ( V_28 == NULL )
return 0 ;
for ( V_43 = 0 ; V_43 < V_28 -> V_44 ; ++ V_43 ) {
V_13 = & V_28 -> V_45 [ V_43 ] ;
if ( ! V_13 -> V_46 )
continue;
if ( V_13 -> V_16 . V_53 & V_96 )
V_13 -> V_97 = 0 ;
if ( ! V_13 -> V_98 )
continue;
if ( ! V_95 )
V_52 = F_16 ( V_55 , V_99 , V_13 -> V_28 -> V_14 ,
V_55 -> V_56 , V_13 -> V_16 . V_57 ,
F_4 ( V_13 , V_100 ) ,
V_13 -> V_16 . V_17 ) ;
else
V_52 = 0 ;
if ( V_95 || V_52 < 0 )
memcpy ( F_4 ( V_13 , V_100 ) ,
F_4 ( V_13 , V_101 ) ,
V_13 -> V_16 . V_17 ) ;
V_13 -> V_98 = 0 ;
if ( V_52 < 0 )
return V_52 ;
}
return 0 ;
}
int F_25 ( struct V_47 * V_48 , int V_95 )
{
struct V_27 * V_28 ;
int V_52 = 0 ;
F_12 (entity, &chain->entities, chain) {
V_52 = F_24 ( V_48 -> V_55 , V_28 , V_95 ) ;
if ( V_52 < 0 )
goto V_74;
}
V_74:
F_21 ( & V_48 -> V_71 ) ;
return V_52 ;
}
int F_26 ( struct V_47 * V_48 ,
struct V_102 * V_103 )
{
struct V_12 * V_13 ;
struct V_1 * V_2 ;
struct V_69 * V_70 ;
unsigned int V_43 ;
int V_52 ;
V_13 = F_13 ( V_48 , V_103 -> V_14 , & V_2 ) ;
if ( V_13 == NULL || ( V_13 -> V_16 . V_53 & V_76 ) == 0 )
return - V_73 ;
if ( ! V_13 -> V_97 ) {
V_52 = F_16 ( V_48 -> V_55 , V_6 , V_13 -> V_28 -> V_14 ,
V_48 -> V_55 -> V_56 , V_13 -> V_16 . V_57 ,
F_4 ( V_13 , V_100 ) ,
V_13 -> V_16 . V_17 ) ;
if ( V_52 < 0 )
return V_52 ;
V_13 -> V_97 = 1 ;
}
V_103 -> V_11 = V_2 -> V_81 ( V_2 , V_6 ,
F_4 ( V_13 , V_100 ) ) ;
if ( V_2 -> V_25 == V_82 ) {
V_70 = V_2 -> V_87 ;
for ( V_43 = 0 ; V_43 < V_2 -> V_85 ; ++ V_43 , ++ V_70 ) {
if ( V_70 -> V_11 == V_103 -> V_11 ) {
V_103 -> V_11 = V_43 ;
break;
}
}
}
return 0 ;
}
int F_27 ( struct V_47 * V_48 ,
struct V_102 * V_103 )
{
struct V_12 * V_13 ;
struct V_1 * V_2 ;
T_6 V_11 ;
T_5 V_86 ;
T_6 F_3 ;
T_6 V_104 ;
int V_52 ;
V_13 = F_13 ( V_48 , V_103 -> V_14 , & V_2 ) ;
if ( V_13 == NULL || ( V_13 -> V_16 . V_53 & V_78 ) == 0 )
return - V_73 ;
switch ( V_2 -> V_25 ) {
case V_105 :
if ( ! V_13 -> V_66 ) {
V_52 = F_15 ( V_48 , V_13 ) ;
if ( V_52 < 0 )
return V_52 ;
}
F_3 = V_2 -> V_81 ( V_2 , V_7 ,
F_4 ( V_13 , V_60 ) ) ;
V_104 = V_2 -> V_81 ( V_2 , V_8 ,
F_4 ( V_13 , V_62 ) ) ;
V_86 = V_2 -> V_81 ( V_2 , V_9 ,
F_4 ( V_13 , V_64 ) ) ;
if ( V_86 == 0 )
V_86 = 1 ;
V_103 -> V_11 = F_3 + ( V_103 -> V_11 - F_3 + V_86 / 2 ) / V_86 * V_86 ;
V_103 -> V_11 = F_28 ( V_103 -> V_11 , F_3 , V_104 ) ;
V_11 = V_103 -> V_11 ;
break;
case V_88 :
V_103 -> V_11 = F_28 ( V_103 -> V_11 , 0 , 1 ) ;
V_11 = V_103 -> V_11 ;
break;
case V_82 :
if ( V_103 -> V_11 < 0 || V_103 -> V_11 >= V_2 -> V_85 )
return - V_106 ;
V_11 = V_2 -> V_87 [ V_103 -> V_11 ] . V_11 ;
if ( V_2 -> V_23 == V_92 &&
( V_13 -> V_16 . V_53 & V_63 ) ) {
if ( ! V_13 -> V_66 ) {
V_52 = F_15 ( V_48 , V_13 ) ;
if ( V_52 < 0 )
return V_52 ;
}
V_86 = V_2 -> V_81 ( V_2 , V_9 ,
F_4 ( V_13 , V_64 ) ) ;
if ( ! ( V_86 & V_11 ) )
return - V_106 ;
}
break;
default:
V_11 = V_103 -> V_11 ;
break;
}
if ( ! V_13 -> V_97 && ( V_13 -> V_16 . V_17 * 8 ) != V_2 -> V_17 ) {
if ( ( V_13 -> V_16 . V_53 & V_76 ) == 0 ) {
memset ( F_4 ( V_13 , V_100 ) ,
0 , V_13 -> V_16 . V_17 ) ;
} else {
V_52 = F_16 ( V_48 -> V_55 , V_6 ,
V_13 -> V_28 -> V_14 , V_48 -> V_55 -> V_56 ,
V_13 -> V_16 . V_57 ,
F_4 ( V_13 , V_100 ) ,
V_13 -> V_16 . V_17 ) ;
if ( V_52 < 0 )
return V_52 ;
}
V_13 -> V_97 = 1 ;
}
if ( ! V_13 -> V_98 ) {
memcpy ( F_4 ( V_13 , V_101 ) ,
F_4 ( V_13 , V_100 ) ,
V_13 -> V_16 . V_17 ) ;
}
V_2 -> V_107 ( V_2 , V_11 ,
F_4 ( V_13 , V_100 ) ) ;
V_13 -> V_98 = 1 ;
V_13 -> V_108 = 1 ;
return 0 ;
}
static void F_29 ( struct V_94 * V_55 ,
const struct V_12 * V_13 , struct V_109 * V_16 )
{
struct V_110 {
struct V_111 V_14 ;
T_7 V_28 ;
T_7 V_57 ;
T_7 V_53 ;
};
static const struct V_110 V_112 [] = {
{ { F_30 ( 0x046d , 0x08c2 ) } , 9 , 1 ,
V_59 | V_61 |
V_54 | V_78 |
V_96 } ,
{ { F_30 ( 0x046d , 0x08cc ) } , 9 , 1 ,
V_59 | V_61 |
V_54 | V_78 |
V_96 } ,
{ { F_30 ( 0x046d , 0x0994 ) } , 9 , 1 ,
V_59 | V_61 |
V_54 | V_78 |
V_96 } ,
} ;
unsigned int V_43 ;
for ( V_43 = 0 ; V_43 < F_31 ( V_112 ) ; ++ V_43 ) {
if ( ! F_32 ( V_55 -> V_113 , & V_112 [ V_43 ] . V_14 ) )
continue;
if ( V_112 [ V_43 ] . V_28 == V_13 -> V_28 -> V_14 &&
V_112 [ V_43 ] . V_57 == V_16 -> V_57 ) {
V_16 -> V_53 = V_112 [ V_43 ] . V_53 ;
return;
}
}
}
static int F_33 ( struct V_94 * V_55 ,
const struct V_12 * V_13 , struct V_109 * V_16 )
{
T_7 * V_4 ;
int V_52 ;
V_4 = F_34 ( 2 , V_114 ) ;
if ( V_4 == NULL )
return - V_115 ;
memcpy ( V_16 -> V_28 , V_13 -> V_28 -> V_37 . V_38 ,
sizeof( V_16 -> V_28 ) ) ;
V_16 -> V_91 = V_13 -> V_91 ;
V_16 -> V_57 = V_13 -> V_91 + 1 ;
V_52 = F_16 ( V_55 , V_116 , V_13 -> V_28 -> V_14 , V_55 -> V_56 ,
V_16 -> V_57 , V_4 , 2 ) ;
if ( V_52 < 0 ) {
F_14 ( V_51 ,
L_4 ,
V_16 -> V_28 , V_16 -> V_57 , V_52 ) ;
goto V_74;
}
V_16 -> V_17 = F_35 ( ( V_117 * ) V_4 ) ;
V_52 = F_16 ( V_55 , V_118 , V_13 -> V_28 -> V_14 , V_55 -> V_56 ,
V_16 -> V_57 , V_4 , 1 ) ;
if ( V_52 < 0 ) {
F_14 ( V_51 ,
L_5 ,
V_16 -> V_28 , V_16 -> V_57 , V_52 ) ;
goto V_74;
}
V_16 -> V_53 = V_59 | V_61
| V_63 | V_54
| ( V_4 [ 0 ] & V_119 ?
V_76 : 0 )
| ( V_4 [ 0 ] & V_120 ?
V_78 : 0 )
| ( V_4 [ 0 ] & V_121 ?
V_96 : 0 ) ;
F_29 ( V_55 , V_13 , V_16 ) ;
F_14 ( V_51 , L_6
L_7 ,
V_16 -> V_28 , V_16 -> V_57 , V_16 -> V_17 ,
( V_16 -> V_53 & V_76 ) ? 1 : 0 ,
( V_16 -> V_53 & V_78 ) ? 1 : 0 ,
( V_16 -> V_53 & V_96 ) ? 1 : 0 ) ;
V_74:
F_36 ( V_4 ) ;
return V_52 ;
}
static int F_37 ( struct V_94 * V_55 ,
struct V_12 * V_13 )
{
struct V_109 V_16 ;
int V_52 ;
if ( V_13 -> V_46 )
return 0 ;
V_52 = F_33 ( V_55 , V_13 , & V_16 ) ;
if ( V_52 < 0 )
return V_52 ;
V_52 = F_38 ( V_55 , V_13 , & V_16 ) ;
if ( V_52 < 0 )
F_14 ( V_51 , L_8
L_9 , V_16 . V_28 ,
V_16 . V_57 , V_55 -> V_122 -> V_123 , V_13 -> V_28 -> V_14 ) ;
return V_52 ;
}
int F_39 ( struct V_47 * V_48 ,
struct V_124 * V_125 )
{
struct V_27 * V_28 ;
struct V_12 * V_13 ;
unsigned int V_43 , V_126 = 0 ;
T_4 V_127 ;
T_8 V_17 ;
T_2 * V_4 = NULL ;
int V_52 ;
F_12 (entity, &chain->entities, chain) {
if ( F_10 ( V_28 ) == V_36 &&
V_28 -> V_14 == V_125 -> V_128 )
break;
}
if ( V_28 -> V_14 != V_125 -> V_128 ) {
F_14 ( V_51 , L_10 ,
V_125 -> V_128 ) ;
return - V_129 ;
}
for ( V_43 = 0 ; V_43 < V_28 -> V_44 ; ++ V_43 ) {
V_13 = & V_28 -> V_45 [ V_43 ] ;
if ( V_13 -> V_91 == V_125 -> V_57 - 1 ) {
V_126 = 1 ;
break;
}
}
if ( ! V_126 ) {
F_14 ( V_51 , L_11 ,
V_28 -> V_37 . V_38 , V_125 -> V_57 ) ;
return - V_129 ;
}
if ( F_19 ( & V_48 -> V_71 ) )
return - V_72 ;
V_52 = F_37 ( V_48 -> V_55 , V_13 ) ;
if ( V_52 < 0 ) {
V_52 = - V_129 ;
goto V_74;
}
V_127 = 0 ;
V_17 = V_13 -> V_16 . V_17 ;
switch ( V_125 -> V_3 ) {
case V_6 :
V_127 = V_76 ;
break;
case V_7 :
V_127 = V_59 ;
break;
case V_8 :
V_127 = V_61 ;
break;
case V_10 :
V_127 = V_54 ;
break;
case V_9 :
V_127 = V_63 ;
break;
case V_99 :
V_127 = V_78 ;
break;
case V_116 :
V_17 = 2 ;
break;
case V_118 :
V_17 = 1 ;
break;
default:
V_52 = - V_73 ;
goto V_74;
}
if ( V_17 != V_125 -> V_17 ) {
V_52 = - V_130 ;
goto V_74;
}
if ( V_127 && ! ( V_13 -> V_16 . V_53 & V_127 ) ) {
V_52 = - V_131 ;
goto V_74;
}
V_4 = F_34 ( V_17 , V_114 ) ;
if ( V_4 == NULL ) {
V_52 = - V_115 ;
goto V_74;
}
if ( V_125 -> V_3 == V_99 &&
F_40 ( V_4 , V_125 -> V_4 , V_17 ) ) {
V_52 = - V_132 ;
goto V_74;
}
V_52 = F_16 ( V_48 -> V_55 , V_125 -> V_3 , V_125 -> V_128 ,
V_48 -> V_55 -> V_56 , V_125 -> V_57 , V_4 , V_17 ) ;
if ( V_52 < 0 )
goto V_74;
if ( V_125 -> V_3 != V_99 &&
F_41 ( V_125 -> V_4 , V_4 , V_17 ) )
V_52 = - V_132 ;
V_74:
F_36 ( V_4 ) ;
F_21 ( & V_48 -> V_71 ) ;
return V_52 ;
}
int F_42 ( struct V_94 * V_55 )
{
struct V_12 * V_13 ;
struct V_27 * V_28 ;
unsigned int V_43 ;
int V_52 ;
F_12 (entity, &dev->entities, list) {
for ( V_43 = 0 ; V_43 < V_28 -> V_44 ; ++ V_43 ) {
V_13 = & V_28 -> V_45 [ V_43 ] ;
if ( ! V_13 -> V_46 || ! V_13 -> V_108 ||
( V_13 -> V_16 . V_53 & V_133 ) == 0 )
continue;
F_43 ( V_134 L_12 ,
V_13 -> V_16 . V_28 , V_13 -> V_16 . V_91 ,
V_13 -> V_16 . V_57 ) ;
V_13 -> V_98 = 1 ;
}
V_52 = F_24 ( V_55 , V_28 , 0 ) ;
if ( V_52 < 0 )
return V_52 ;
}
return 0 ;
}
static int F_38 ( struct V_94 * V_55 , struct V_12 * V_13 ,
const struct V_109 * V_16 )
{
int V_52 = 0 ;
memcpy ( & V_13 -> V_16 , V_16 , sizeof( * V_16 ) ) ;
F_44 ( & V_13 -> V_16 . V_135 ) ;
V_13 -> V_15 = F_45 ( V_13 -> V_16 . V_17 * V_136 + 1 ,
V_114 ) ;
if ( V_13 -> V_15 == NULL ) {
V_52 = - V_115 ;
goto V_74;
}
V_13 -> V_46 = 1 ;
F_14 ( V_51 , L_13
L_14 , V_13 -> V_16 . V_28 , V_13 -> V_16 . V_57 ,
V_55 -> V_122 -> V_123 , V_13 -> V_28 -> V_14 ) ;
V_74:
if ( V_52 < 0 )
F_36 ( V_13 -> V_15 ) ;
return V_52 ;
}
static int F_46 ( struct V_94 * V_55 ,
struct V_12 * V_13 , const struct V_1 * V_2 )
{
struct V_1 * V_42 ;
unsigned int V_17 ;
V_42 = F_47 ( V_2 , sizeof( * V_2 ) , V_114 ) ;
if ( V_42 == NULL )
return - V_115 ;
V_17 = sizeof( * V_2 -> V_87 ) * V_2 -> V_85 ;
V_42 -> V_87 = F_47 ( V_2 -> V_87 , V_17 , V_114 ) ;
if ( V_42 -> V_87 == NULL ) {
F_36 ( V_42 ) ;
return - V_115 ;
}
if ( V_42 -> V_81 == NULL )
V_42 -> V_81 = F_7 ;
if ( V_42 -> V_107 == NULL )
V_42 -> V_107 = F_8 ;
V_42 -> V_13 = & V_13 -> V_16 ;
F_48 ( & V_42 -> V_137 , & V_13 -> V_16 . V_135 ) ;
F_14 ( V_51 ,
L_15 ,
V_42 -> V_75 , V_13 -> V_16 . V_28 , V_13 -> V_16 . V_57 ) ;
return 0 ;
}
int F_49 ( struct V_47 * V_48 ,
const struct V_1 * V_2 )
{
struct V_94 * V_55 = V_48 -> V_55 ;
struct V_1 * V_42 ;
struct V_27 * V_28 ;
struct V_12 * V_13 ;
int V_126 = 0 ;
int V_52 ;
if ( V_2 -> V_14 & ~ V_50 ) {
F_14 ( V_51 , L_16
L_17 , V_2 -> V_75 ,
V_2 -> V_14 ) ;
return - V_73 ;
}
F_12 (entity, &chain->entities, chain) {
unsigned int V_43 ;
if ( F_10 ( V_28 ) != V_36 ||
! F_9 ( V_28 , V_2 -> V_28 ) )
continue;
for ( V_43 = 0 ; V_43 < V_28 -> V_44 ; ++ V_43 ) {
V_13 = & V_28 -> V_45 [ V_43 ] ;
if ( V_13 -> V_91 == V_2 -> V_57 - 1 ) {
V_126 = 1 ;
break;
}
}
if ( V_126 )
break;
}
if ( ! V_126 )
return - V_129 ;
if ( F_19 ( & V_48 -> V_71 ) )
return - V_72 ;
V_52 = F_37 ( V_55 , V_13 ) ;
if ( V_52 < 0 ) {
V_52 = - V_129 ;
goto V_74;
}
F_12 (map, &ctrl->info.mappings, list) {
if ( V_2 -> V_14 == V_42 -> V_14 ) {
F_14 ( V_51 , L_18
L_19 ,
V_2 -> V_75 , V_2 -> V_14 ) ;
V_52 = - V_138 ;
goto V_74;
}
}
if ( F_50 ( & V_55 -> V_139 ) > V_140 ) {
F_51 ( & V_55 -> V_139 ) ;
F_14 ( V_51 , L_20
L_21 , V_2 -> V_75 ,
V_140 ) ;
V_52 = - V_115 ;
goto V_74;
}
V_52 = F_46 ( V_55 , V_13 , V_2 ) ;
if ( V_52 < 0 )
F_51 ( & V_55 -> V_139 ) ;
V_74:
F_21 ( & V_48 -> V_71 ) ;
return V_52 ;
}
static void F_52 ( struct V_94 * V_55 ,
struct V_27 * V_28 )
{
struct V_141 {
struct V_111 V_14 ;
T_7 V_91 ;
};
static const struct V_141 V_142 [] = {
{ { F_30 ( 0x13d3 , 0x509b ) } , 9 } ,
{ { F_30 ( 0x1c4f , 0x3000 ) } , 6 } ,
{ { F_30 ( 0x5986 , 0x0241 ) } , 2 } ,
} ;
static const struct V_141 V_143 [] = {
{ { F_30 ( 0x06f8 , 0x3005 ) } , 9 } ,
} ;
const struct V_141 * V_144 ;
unsigned int V_17 ;
unsigned int V_145 ;
unsigned int V_43 ;
T_7 * V_45 ;
switch ( F_10 ( V_28 ) ) {
case V_34 :
V_144 = V_142 ;
V_145 = F_31 ( V_142 ) ;
V_45 = V_28 -> V_146 . V_147 ;
V_17 = V_28 -> V_146 . V_148 ;
break;
case V_30 :
V_144 = V_143 ;
V_145 = F_31 ( V_143 ) ;
V_45 = V_28 -> V_149 . V_147 ;
V_17 = V_28 -> V_149 . V_148 ;
break;
default:
return;
}
for ( V_43 = 0 ; V_43 < V_145 ; ++ V_43 ) {
if ( ! F_32 ( V_55 -> V_113 , & V_144 [ V_43 ] . V_14 ) )
continue;
if ( V_144 [ V_43 ] . V_91 >= 8 * V_17 ||
! F_5 ( V_45 , V_144 [ V_43 ] . V_91 ) )
continue;
F_14 ( V_51 , L_22
L_23 , V_28 -> V_14 , V_144 [ V_43 ] . V_91 ) ;
F_6 ( V_45 , V_144 [ V_43 ] . V_91 ) ;
}
}
static void F_53 ( struct V_94 * V_55 , struct V_12 * V_13 )
{
const struct V_109 * V_16 = V_150 ;
const struct V_109 * V_151 = V_16 + F_31 ( V_150 ) ;
const struct V_1 * V_2 = V_152 ;
const struct V_1 * V_153 =
V_2 + F_31 ( V_152 ) ;
if ( F_10 ( V_13 -> V_28 ) == V_36 )
return;
for (; V_16 < V_151 ; ++ V_16 ) {
if ( F_9 ( V_13 -> V_28 , V_16 -> V_28 ) &&
V_13 -> V_91 == V_16 -> V_91 ) {
F_38 ( V_55 , V_13 , V_16 ) ;
break;
}
}
if ( ! V_13 -> V_46 )
return;
for (; V_2 < V_153 ; ++ V_2 ) {
if ( F_9 ( V_13 -> V_28 , V_2 -> V_28 ) &&
V_13 -> V_16 . V_57 == V_2 -> V_57 )
F_46 ( V_55 , V_13 , V_2 ) ;
}
}
int F_54 ( struct V_94 * V_55 )
{
struct V_27 * V_28 ;
unsigned int V_43 ;
F_12 (entity, &dev->entities, list) {
struct V_12 * V_13 ;
unsigned int V_148 = 0 , V_44 = 0 ;
T_2 * V_147 = NULL ;
if ( F_10 ( V_28 ) == V_36 ) {
V_147 = V_28 -> V_37 . V_147 ;
V_148 = V_28 -> V_37 . V_148 ;
} else if ( F_10 ( V_28 ) == V_34 ) {
V_147 = V_28 -> V_146 . V_147 ;
V_148 = V_28 -> V_146 . V_148 ;
} else if ( F_10 ( V_28 ) == V_30 ) {
V_147 = V_28 -> V_149 . V_147 ;
V_148 = V_28 -> V_149 . V_148 ;
}
F_52 ( V_55 , V_28 ) ;
for ( V_43 = 0 ; V_43 < V_148 ; ++ V_43 )
V_44 += F_55 ( V_147 [ V_43 ] ) ;
if ( V_44 == 0 )
continue;
V_28 -> V_45 = F_56 ( V_44 , sizeof( * V_13 ) ,
V_114 ) ;
if ( V_28 -> V_45 == NULL )
return - V_115 ;
V_28 -> V_44 = V_44 ;
V_13 = V_28 -> V_45 ;
for ( V_43 = 0 ; V_43 < V_148 * 8 ; ++ V_43 ) {
if ( F_5 ( V_147 , V_43 ) == 0 )
continue;
V_13 -> V_28 = V_28 ;
V_13 -> V_91 = V_43 ;
F_53 ( V_55 , V_13 ) ;
V_13 ++ ;
}
}
return 0 ;
}
static void F_57 ( struct V_94 * V_55 ,
struct V_12 * V_13 )
{
struct V_1 * V_2 , * V_154 ;
F_58 (mapping, nm, &ctrl->info.mappings, list) {
F_59 ( & V_2 -> V_137 ) ;
F_36 ( V_2 -> V_87 ) ;
F_36 ( V_2 ) ;
}
}
void F_60 ( struct V_94 * V_55 )
{
struct V_27 * V_28 ;
unsigned int V_43 ;
F_12 (entity, &dev->entities, list) {
for ( V_43 = 0 ; V_43 < V_28 -> V_44 ; ++ V_43 ) {
struct V_12 * V_13 = & V_28 -> V_45 [ V_43 ] ;
if ( ! V_13 -> V_46 )
continue;
F_57 ( V_55 , V_13 ) ;
F_36 ( V_13 -> V_15 ) ;
}
F_36 ( V_28 -> V_45 ) ;
}
}
