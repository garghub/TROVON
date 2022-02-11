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
if ( V_52 < 0 )
return V_52 ;
}
V_13 -> V_65 = 1 ;
return 0 ;
}
int F_17 ( struct V_47 * V_48 ,
struct V_66 * V_67 )
{
struct V_12 * V_13 ;
struct V_1 * V_2 ;
struct V_68 * V_69 ;
unsigned int V_43 ;
int V_52 ;
V_52 = F_18 ( & V_48 -> V_70 ) ;
if ( V_52 < 0 )
return - V_71 ;
V_13 = F_13 ( V_48 , V_67 -> V_14 , & V_2 ) ;
if ( V_13 == NULL ) {
V_52 = - V_72 ;
goto V_73;
}
memset ( V_67 , 0 , sizeof *V_67 ) ;
V_67 -> V_14 = V_2 -> V_14 ;
V_67 -> type = V_2 -> V_25 ;
F_19 ( V_67 -> V_74 , V_2 -> V_74 , sizeof V_67 -> V_74 ) ;
V_67 -> V_53 = 0 ;
if ( ! ( V_13 -> V_16 . V_53 & V_75 ) )
V_67 -> V_53 |= V_76 ;
if ( ! ( V_13 -> V_16 . V_53 & V_77 ) )
V_67 -> V_53 |= V_78 ;
if ( ! V_13 -> V_65 ) {
V_52 = F_15 ( V_48 , V_13 ) ;
if ( V_52 < 0 )
goto V_73;
}
if ( V_13 -> V_16 . V_53 & V_54 ) {
V_67 -> V_79 = V_2 -> V_80 ( V_2 , V_10 ,
F_4 ( V_13 , V_58 ) ) ;
}
switch ( V_2 -> V_25 ) {
case V_81 :
V_67 -> V_82 = 0 ;
V_67 -> V_83 = V_2 -> V_84 - 1 ;
V_67 -> V_85 = 1 ;
V_69 = V_2 -> V_86 ;
for ( V_43 = 0 ; V_43 < V_2 -> V_84 ; ++ V_43 , ++ V_69 ) {
if ( V_69 -> V_11 == V_67 -> V_79 ) {
V_67 -> V_79 = V_43 ;
break;
}
}
goto V_73;
case V_87 :
V_67 -> V_82 = 0 ;
V_67 -> V_83 = 1 ;
V_67 -> V_85 = 1 ;
goto V_73;
case V_26 :
V_67 -> V_82 = 0 ;
V_67 -> V_83 = 0 ;
V_67 -> V_85 = 0 ;
goto V_73;
default:
break;
}
if ( V_13 -> V_16 . V_53 & V_59 )
V_67 -> V_82 = V_2 -> V_80 ( V_2 , V_7 ,
F_4 ( V_13 , V_60 ) ) ;
if ( V_13 -> V_16 . V_53 & V_61 )
V_67 -> V_83 = V_2 -> V_80 ( V_2 , V_8 ,
F_4 ( V_13 , V_62 ) ) ;
if ( V_13 -> V_16 . V_53 & V_63 )
V_67 -> V_85 = V_2 -> V_80 ( V_2 , V_9 ,
F_4 ( V_13 , V_64 ) ) ;
V_73:
F_20 ( & V_48 -> V_70 ) ;
return V_52 ;
}
int F_21 ( struct V_47 * V_48 ,
struct V_88 * V_89 )
{
struct V_68 * V_86 ;
struct V_1 * V_2 ;
struct V_12 * V_13 ;
T_5 V_90 = V_89 -> V_90 ;
T_5 V_14 = V_89 -> V_14 ;
int V_52 ;
memset ( V_89 , 0 , sizeof( * V_89 ) ) ;
V_89 -> V_14 = V_14 ;
V_89 -> V_90 = V_90 ;
V_52 = F_18 ( & V_48 -> V_70 ) ;
if ( V_52 < 0 )
return - V_71 ;
V_13 = F_13 ( V_48 , V_89 -> V_14 , & V_2 ) ;
if ( V_13 == NULL || V_2 -> V_25 != V_81 ) {
V_52 = - V_72 ;
goto V_73;
}
if ( V_89 -> V_90 >= V_2 -> V_84 ) {
V_52 = - V_72 ;
goto V_73;
}
V_86 = & V_2 -> V_86 [ V_89 -> V_90 ] ;
if ( V_2 -> V_23 == V_91 &&
( V_13 -> V_16 . V_53 & V_63 ) ) {
T_6 V_92 ;
if ( ! V_13 -> V_65 ) {
V_52 = F_15 ( V_48 , V_13 ) ;
if ( V_52 < 0 )
goto V_73;
}
V_92 = V_2 -> V_80 ( V_2 , V_9 ,
F_4 ( V_13 , V_64 ) ) ;
if ( ! ( V_92 & V_86 -> V_11 ) ) {
V_52 = - V_72 ;
goto V_73;
}
}
F_19 ( V_89 -> V_74 , V_86 -> V_74 , sizeof V_89 -> V_74 ) ;
V_73:
F_20 ( & V_48 -> V_70 ) ;
return V_52 ;
}
int F_22 ( struct V_47 * V_48 )
{
return F_18 ( & V_48 -> V_70 ) ? - V_71 : 0 ;
}
static int F_23 ( struct V_93 * V_55 ,
struct V_27 * V_28 , int V_94 )
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
if ( V_13 -> V_16 . V_53 & V_95 )
V_13 -> V_96 = 0 ;
if ( ! V_13 -> V_97 )
continue;
if ( ! V_94 )
V_52 = F_16 ( V_55 , V_98 , V_13 -> V_28 -> V_14 ,
V_55 -> V_56 , V_13 -> V_16 . V_57 ,
F_4 ( V_13 , V_99 ) ,
V_13 -> V_16 . V_17 ) ;
else
V_52 = 0 ;
if ( V_94 || V_52 < 0 )
memcpy ( F_4 ( V_13 , V_99 ) ,
F_4 ( V_13 , V_100 ) ,
V_13 -> V_16 . V_17 ) ;
V_13 -> V_97 = 0 ;
if ( V_52 < 0 )
return V_52 ;
}
return 0 ;
}
int F_24 ( struct V_47 * V_48 , int V_94 )
{
struct V_27 * V_28 ;
int V_52 = 0 ;
F_12 (entity, &chain->entities, chain) {
V_52 = F_23 ( V_48 -> V_55 , V_28 , V_94 ) ;
if ( V_52 < 0 )
goto V_73;
}
V_73:
F_20 ( & V_48 -> V_70 ) ;
return V_52 ;
}
int F_25 ( struct V_47 * V_48 ,
struct V_101 * V_102 )
{
struct V_12 * V_13 ;
struct V_1 * V_2 ;
struct V_68 * V_69 ;
unsigned int V_43 ;
int V_52 ;
V_13 = F_13 ( V_48 , V_102 -> V_14 , & V_2 ) ;
if ( V_13 == NULL || ( V_13 -> V_16 . V_53 & V_75 ) == 0 )
return - V_72 ;
if ( ! V_13 -> V_96 ) {
V_52 = F_16 ( V_48 -> V_55 , V_6 , V_13 -> V_28 -> V_14 ,
V_48 -> V_55 -> V_56 , V_13 -> V_16 . V_57 ,
F_4 ( V_13 , V_99 ) ,
V_13 -> V_16 . V_17 ) ;
if ( V_52 < 0 )
return V_52 ;
V_13 -> V_96 = 1 ;
}
V_102 -> V_11 = V_2 -> V_80 ( V_2 , V_6 ,
F_4 ( V_13 , V_99 ) ) ;
if ( V_2 -> V_25 == V_81 ) {
V_69 = V_2 -> V_86 ;
for ( V_43 = 0 ; V_43 < V_2 -> V_84 ; ++ V_43 , ++ V_69 ) {
if ( V_69 -> V_11 == V_102 -> V_11 ) {
V_102 -> V_11 = V_43 ;
break;
}
}
}
return 0 ;
}
int F_26 ( struct V_47 * V_48 ,
struct V_101 * V_102 )
{
struct V_12 * V_13 ;
struct V_1 * V_2 ;
T_6 V_11 ;
T_5 V_85 ;
T_6 F_3 ;
T_6 V_103 ;
int V_52 ;
V_13 = F_13 ( V_48 , V_102 -> V_14 , & V_2 ) ;
if ( V_13 == NULL || ( V_13 -> V_16 . V_53 & V_77 ) == 0 )
return - V_72 ;
switch ( V_2 -> V_25 ) {
case V_104 :
if ( ! V_13 -> V_65 ) {
V_52 = F_15 ( V_48 , V_13 ) ;
if ( V_52 < 0 )
return V_52 ;
}
F_3 = V_2 -> V_80 ( V_2 , V_7 ,
F_4 ( V_13 , V_60 ) ) ;
V_103 = V_2 -> V_80 ( V_2 , V_8 ,
F_4 ( V_13 , V_62 ) ) ;
V_85 = V_2 -> V_80 ( V_2 , V_9 ,
F_4 ( V_13 , V_64 ) ) ;
if ( V_85 == 0 )
V_85 = 1 ;
V_102 -> V_11 = F_3 + ( V_102 -> V_11 - F_3 + V_85 / 2 ) / V_85 * V_85 ;
V_102 -> V_11 = F_27 ( V_102 -> V_11 , F_3 , V_103 ) ;
V_11 = V_102 -> V_11 ;
break;
case V_87 :
V_102 -> V_11 = F_27 ( V_102 -> V_11 , 0 , 1 ) ;
V_11 = V_102 -> V_11 ;
break;
case V_81 :
if ( V_102 -> V_11 < 0 || V_102 -> V_11 >= V_2 -> V_84 )
return - V_105 ;
V_11 = V_2 -> V_86 [ V_102 -> V_11 ] . V_11 ;
if ( V_2 -> V_23 == V_91 &&
( V_13 -> V_16 . V_53 & V_63 ) ) {
if ( ! V_13 -> V_65 ) {
V_52 = F_15 ( V_48 , V_13 ) ;
if ( V_52 < 0 )
return V_52 ;
}
V_85 = V_2 -> V_80 ( V_2 , V_9 ,
F_4 ( V_13 , V_64 ) ) ;
if ( ! ( V_85 & V_11 ) )
return - V_105 ;
}
break;
default:
V_11 = V_102 -> V_11 ;
break;
}
if ( ! V_13 -> V_96 && ( V_13 -> V_16 . V_17 * 8 ) != V_2 -> V_17 ) {
if ( ( V_13 -> V_16 . V_53 & V_75 ) == 0 ) {
memset ( F_4 ( V_13 , V_99 ) ,
0 , V_13 -> V_16 . V_17 ) ;
} else {
V_52 = F_16 ( V_48 -> V_55 , V_6 ,
V_13 -> V_28 -> V_14 , V_48 -> V_55 -> V_56 ,
V_13 -> V_16 . V_57 ,
F_4 ( V_13 , V_99 ) ,
V_13 -> V_16 . V_17 ) ;
if ( V_52 < 0 )
return V_52 ;
}
V_13 -> V_96 = 1 ;
}
if ( ! V_13 -> V_97 ) {
memcpy ( F_4 ( V_13 , V_100 ) ,
F_4 ( V_13 , V_99 ) ,
V_13 -> V_16 . V_17 ) ;
}
V_2 -> V_106 ( V_2 , V_11 ,
F_4 ( V_13 , V_99 ) ) ;
V_13 -> V_97 = 1 ;
V_13 -> V_107 = 1 ;
return 0 ;
}
static void F_28 ( struct V_93 * V_55 ,
const struct V_12 * V_13 , struct V_108 * V_16 )
{
struct V_109 {
struct V_110 V_14 ;
T_7 V_28 ;
T_7 V_57 ;
T_7 V_53 ;
};
static const struct V_109 V_111 [] = {
{ { F_29 ( 0x046d , 0x08c2 ) } , 9 , 1 ,
V_59 | V_61 |
V_54 | V_77 |
V_95 } ,
{ { F_29 ( 0x046d , 0x08cc ) } , 9 , 1 ,
V_59 | V_61 |
V_54 | V_77 |
V_95 } ,
{ { F_29 ( 0x046d , 0x0994 ) } , 9 , 1 ,
V_59 | V_61 |
V_54 | V_77 |
V_95 } ,
} ;
unsigned int V_43 ;
for ( V_43 = 0 ; V_43 < F_30 ( V_111 ) ; ++ V_43 ) {
if ( ! F_31 ( V_55 -> V_112 , & V_111 [ V_43 ] . V_14 ) )
continue;
if ( V_111 [ V_43 ] . V_28 == V_13 -> V_28 -> V_14 &&
V_111 [ V_43 ] . V_57 == V_16 -> V_57 ) {
V_16 -> V_53 = V_111 [ V_43 ] . V_53 ;
return;
}
}
}
static int F_32 ( struct V_93 * V_55 ,
const struct V_12 * V_13 , struct V_108 * V_16 )
{
T_7 * V_4 ;
int V_52 ;
V_4 = F_33 ( 2 , V_113 ) ;
if ( V_4 == NULL )
return - V_114 ;
memcpy ( V_16 -> V_28 , V_13 -> V_28 -> V_37 . V_38 ,
sizeof( V_16 -> V_28 ) ) ;
V_16 -> V_90 = V_13 -> V_90 ;
V_16 -> V_57 = V_13 -> V_90 + 1 ;
V_52 = F_16 ( V_55 , V_115 , V_13 -> V_28 -> V_14 , V_55 -> V_56 ,
V_16 -> V_57 , V_4 , 2 ) ;
if ( V_52 < 0 ) {
F_14 ( V_51 ,
L_2 ,
V_16 -> V_28 , V_16 -> V_57 , V_52 ) ;
goto V_73;
}
V_16 -> V_17 = F_34 ( ( V_116 * ) V_4 ) ;
V_52 = F_16 ( V_55 , V_117 , V_13 -> V_28 -> V_14 , V_55 -> V_56 ,
V_16 -> V_57 , V_4 , 1 ) ;
if ( V_52 < 0 ) {
F_14 ( V_51 ,
L_3 ,
V_16 -> V_28 , V_16 -> V_57 , V_52 ) ;
goto V_73;
}
V_16 -> V_53 = V_59 | V_61
| V_63 | V_54
| ( V_4 [ 0 ] & V_118 ?
V_75 : 0 )
| ( V_4 [ 0 ] & V_119 ?
V_77 : 0 )
| ( V_4 [ 0 ] & V_120 ?
V_95 : 0 ) ;
F_28 ( V_55 , V_13 , V_16 ) ;
F_14 ( V_51 , L_4
L_5 ,
V_16 -> V_28 , V_16 -> V_57 , V_16 -> V_17 ,
( V_16 -> V_53 & V_75 ) ? 1 : 0 ,
( V_16 -> V_53 & V_77 ) ? 1 : 0 ,
( V_16 -> V_53 & V_95 ) ? 1 : 0 ) ;
V_73:
F_35 ( V_4 ) ;
return V_52 ;
}
static int F_36 ( struct V_93 * V_55 ,
struct V_12 * V_13 )
{
struct V_108 V_16 ;
int V_52 ;
if ( V_13 -> V_46 )
return 0 ;
V_52 = F_32 ( V_55 , V_13 , & V_16 ) ;
if ( V_52 < 0 )
return V_52 ;
V_52 = F_37 ( V_55 , V_13 , & V_16 ) ;
if ( V_52 < 0 )
F_14 ( V_51 , L_6
L_7 , V_16 . V_28 ,
V_16 . V_57 , V_55 -> V_121 -> V_122 , V_13 -> V_28 -> V_14 ) ;
return V_52 ;
}
int F_38 ( struct V_47 * V_48 ,
struct V_123 * V_124 )
{
struct V_27 * V_28 ;
struct V_12 * V_13 ;
unsigned int V_43 , V_125 = 0 ;
T_4 V_126 ;
T_8 V_17 ;
T_2 * V_4 = NULL ;
int V_52 ;
F_12 (entity, &chain->entities, chain) {
if ( F_10 ( V_28 ) == V_36 &&
V_28 -> V_14 == V_124 -> V_127 )
break;
}
if ( V_28 -> V_14 != V_124 -> V_127 ) {
F_14 ( V_51 , L_8 ,
V_124 -> V_127 ) ;
return - V_128 ;
}
for ( V_43 = 0 ; V_43 < V_28 -> V_44 ; ++ V_43 ) {
V_13 = & V_28 -> V_45 [ V_43 ] ;
if ( V_13 -> V_90 == V_124 -> V_57 - 1 ) {
V_125 = 1 ;
break;
}
}
if ( ! V_125 ) {
F_14 ( V_51 , L_9 ,
V_28 -> V_37 . V_38 , V_124 -> V_57 ) ;
return - V_128 ;
}
if ( F_18 ( & V_48 -> V_70 ) )
return - V_71 ;
V_52 = F_36 ( V_48 -> V_55 , V_13 ) ;
if ( V_52 < 0 ) {
V_52 = - V_128 ;
goto V_73;
}
V_126 = 0 ;
V_17 = V_13 -> V_16 . V_17 ;
switch ( V_124 -> V_3 ) {
case V_6 :
V_126 = V_75 ;
break;
case V_7 :
V_126 = V_59 ;
break;
case V_8 :
V_126 = V_61 ;
break;
case V_10 :
V_126 = V_54 ;
break;
case V_9 :
V_126 = V_63 ;
break;
case V_98 :
V_126 = V_77 ;
break;
case V_115 :
V_17 = 2 ;
break;
case V_117 :
V_17 = 1 ;
break;
default:
V_52 = - V_72 ;
goto V_73;
}
if ( V_17 != V_124 -> V_17 ) {
V_52 = - V_129 ;
goto V_73;
}
if ( V_126 && ! ( V_13 -> V_16 . V_53 & V_126 ) ) {
V_52 = - V_130 ;
goto V_73;
}
V_4 = F_33 ( V_17 , V_113 ) ;
if ( V_4 == NULL ) {
V_52 = - V_114 ;
goto V_73;
}
if ( V_124 -> V_3 == V_98 &&
F_39 ( V_4 , V_124 -> V_4 , V_17 ) ) {
V_52 = - V_131 ;
goto V_73;
}
V_52 = F_16 ( V_48 -> V_55 , V_124 -> V_3 , V_124 -> V_127 ,
V_48 -> V_55 -> V_56 , V_124 -> V_57 , V_4 , V_17 ) ;
if ( V_52 < 0 )
goto V_73;
if ( V_124 -> V_3 != V_98 &&
F_40 ( V_124 -> V_4 , V_4 , V_17 ) )
V_52 = - V_131 ;
V_73:
F_35 ( V_4 ) ;
F_20 ( & V_48 -> V_70 ) ;
return V_52 ;
}
int F_41 ( struct V_93 * V_55 )
{
struct V_12 * V_13 ;
struct V_27 * V_28 ;
unsigned int V_43 ;
int V_52 ;
F_12 (entity, &dev->entities, list) {
for ( V_43 = 0 ; V_43 < V_28 -> V_44 ; ++ V_43 ) {
V_13 = & V_28 -> V_45 [ V_43 ] ;
if ( ! V_13 -> V_46 || ! V_13 -> V_107 ||
( V_13 -> V_16 . V_53 & V_132 ) == 0 )
continue;
F_42 ( V_133 L_10 ,
V_13 -> V_16 . V_28 , V_13 -> V_16 . V_90 ,
V_13 -> V_16 . V_57 ) ;
V_13 -> V_97 = 1 ;
}
V_52 = F_23 ( V_55 , V_28 , 0 ) ;
if ( V_52 < 0 )
return V_52 ;
}
return 0 ;
}
static int F_37 ( struct V_93 * V_55 , struct V_12 * V_13 ,
const struct V_108 * V_16 )
{
int V_52 = 0 ;
memcpy ( & V_13 -> V_16 , V_16 , sizeof( * V_16 ) ) ;
F_43 ( & V_13 -> V_16 . V_134 ) ;
V_13 -> V_15 = F_44 ( V_13 -> V_16 . V_17 * V_135 + 1 ,
V_113 ) ;
if ( V_13 -> V_15 == NULL ) {
V_52 = - V_114 ;
goto V_73;
}
V_13 -> V_46 = 1 ;
F_14 ( V_51 , L_11
L_12 , V_13 -> V_16 . V_28 , V_13 -> V_16 . V_57 ,
V_55 -> V_121 -> V_122 , V_13 -> V_28 -> V_14 ) ;
V_73:
if ( V_52 < 0 )
F_35 ( V_13 -> V_15 ) ;
return V_52 ;
}
static int F_45 ( struct V_93 * V_55 ,
struct V_12 * V_13 , const struct V_1 * V_2 )
{
struct V_1 * V_42 ;
unsigned int V_17 ;
V_42 = F_46 ( V_2 , sizeof( * V_2 ) , V_113 ) ;
if ( V_42 == NULL )
return - V_114 ;
V_17 = sizeof( * V_2 -> V_86 ) * V_2 -> V_84 ;
V_42 -> V_86 = F_46 ( V_2 -> V_86 , V_17 , V_113 ) ;
if ( V_42 -> V_86 == NULL ) {
F_35 ( V_42 ) ;
return - V_114 ;
}
if ( V_42 -> V_80 == NULL )
V_42 -> V_80 = F_7 ;
if ( V_42 -> V_106 == NULL )
V_42 -> V_106 = F_8 ;
V_42 -> V_13 = & V_13 -> V_16 ;
F_47 ( & V_42 -> V_136 , & V_13 -> V_16 . V_134 ) ;
F_14 ( V_51 ,
L_13 ,
V_42 -> V_74 , V_13 -> V_16 . V_28 , V_13 -> V_16 . V_57 ) ;
return 0 ;
}
int F_48 ( struct V_47 * V_48 ,
const struct V_1 * V_2 )
{
struct V_93 * V_55 = V_48 -> V_55 ;
struct V_1 * V_42 ;
struct V_27 * V_28 ;
struct V_12 * V_13 ;
int V_125 = 0 ;
int V_52 ;
if ( V_2 -> V_14 & ~ V_50 ) {
F_14 ( V_51 , L_14
L_15 , V_2 -> V_74 ,
V_2 -> V_14 ) ;
return - V_72 ;
}
F_12 (entity, &chain->entities, chain) {
unsigned int V_43 ;
if ( F_10 ( V_28 ) != V_36 ||
! F_9 ( V_28 , V_2 -> V_28 ) )
continue;
for ( V_43 = 0 ; V_43 < V_28 -> V_44 ; ++ V_43 ) {
V_13 = & V_28 -> V_45 [ V_43 ] ;
if ( V_13 -> V_90 == V_2 -> V_57 - 1 ) {
V_125 = 1 ;
break;
}
}
if ( V_125 )
break;
}
if ( ! V_125 )
return - V_128 ;
if ( F_18 ( & V_48 -> V_70 ) )
return - V_71 ;
V_52 = F_36 ( V_55 , V_13 ) ;
if ( V_52 < 0 ) {
V_52 = - V_128 ;
goto V_73;
}
F_12 (map, &ctrl->info.mappings, list) {
if ( V_2 -> V_14 == V_42 -> V_14 ) {
F_14 ( V_51 , L_16
L_17 ,
V_2 -> V_74 , V_2 -> V_14 ) ;
V_52 = - V_137 ;
goto V_73;
}
}
if ( F_49 ( & V_55 -> V_138 ) > V_139 ) {
F_50 ( & V_55 -> V_138 ) ;
F_14 ( V_51 , L_18
L_19 , V_2 -> V_74 ,
V_139 ) ;
V_52 = - V_114 ;
goto V_73;
}
V_52 = F_45 ( V_55 , V_13 , V_2 ) ;
if ( V_52 < 0 )
F_50 ( & V_55 -> V_138 ) ;
V_73:
F_20 ( & V_48 -> V_70 ) ;
return V_52 ;
}
static void F_51 ( struct V_93 * V_55 ,
struct V_27 * V_28 )
{
struct V_140 {
struct V_110 V_14 ;
T_7 V_90 ;
};
static const struct V_140 V_141 [] = {
{ { F_29 ( 0x13d3 , 0x509b ) } , 9 } ,
{ { F_29 ( 0x1c4f , 0x3000 ) } , 6 } ,
{ { F_29 ( 0x5986 , 0x0241 ) } , 2 } ,
} ;
static const struct V_140 V_142 [] = {
{ { F_29 ( 0x06f8 , 0x3005 ) } , 9 } ,
} ;
const struct V_140 * V_143 ;
unsigned int V_17 ;
unsigned int V_144 ;
unsigned int V_43 ;
T_7 * V_45 ;
switch ( F_10 ( V_28 ) ) {
case V_34 :
V_143 = V_141 ;
V_144 = F_30 ( V_141 ) ;
V_45 = V_28 -> V_145 . V_146 ;
V_17 = V_28 -> V_145 . V_147 ;
break;
case V_30 :
V_143 = V_142 ;
V_144 = F_30 ( V_142 ) ;
V_45 = V_28 -> V_148 . V_146 ;
V_17 = V_28 -> V_148 . V_147 ;
break;
default:
return;
}
for ( V_43 = 0 ; V_43 < V_144 ; ++ V_43 ) {
if ( ! F_31 ( V_55 -> V_112 , & V_143 [ V_43 ] . V_14 ) )
continue;
if ( V_143 [ V_43 ] . V_90 >= 8 * V_17 ||
! F_5 ( V_45 , V_143 [ V_43 ] . V_90 ) )
continue;
F_14 ( V_51 , L_20
L_21 , V_28 -> V_14 , V_143 [ V_43 ] . V_90 ) ;
F_6 ( V_45 , V_143 [ V_43 ] . V_90 ) ;
}
}
static void F_52 ( struct V_93 * V_55 , struct V_12 * V_13 )
{
const struct V_108 * V_16 = V_149 ;
const struct V_108 * V_150 = V_16 + F_30 ( V_149 ) ;
const struct V_1 * V_2 = V_151 ;
const struct V_1 * V_152 =
V_2 + F_30 ( V_151 ) ;
if ( F_10 ( V_13 -> V_28 ) == V_36 )
return;
for (; V_16 < V_150 ; ++ V_16 ) {
if ( F_9 ( V_13 -> V_28 , V_16 -> V_28 ) &&
V_13 -> V_90 == V_16 -> V_90 ) {
F_37 ( V_55 , V_13 , V_16 ) ;
break;
}
}
if ( ! V_13 -> V_46 )
return;
for (; V_2 < V_152 ; ++ V_2 ) {
if ( F_9 ( V_13 -> V_28 , V_2 -> V_28 ) &&
V_13 -> V_16 . V_57 == V_2 -> V_57 )
F_45 ( V_55 , V_13 , V_2 ) ;
}
}
int F_53 ( struct V_93 * V_55 )
{
struct V_27 * V_28 ;
unsigned int V_43 ;
F_12 (entity, &dev->entities, list) {
struct V_12 * V_13 ;
unsigned int V_147 = 0 , V_44 = 0 ;
T_2 * V_146 = NULL ;
if ( F_10 ( V_28 ) == V_36 ) {
V_146 = V_28 -> V_37 . V_146 ;
V_147 = V_28 -> V_37 . V_147 ;
} else if ( F_10 ( V_28 ) == V_34 ) {
V_146 = V_28 -> V_145 . V_146 ;
V_147 = V_28 -> V_145 . V_147 ;
} else if ( F_10 ( V_28 ) == V_30 ) {
V_146 = V_28 -> V_148 . V_146 ;
V_147 = V_28 -> V_148 . V_147 ;
}
F_51 ( V_55 , V_28 ) ;
for ( V_43 = 0 ; V_43 < V_147 ; ++ V_43 )
V_44 += F_54 ( V_146 [ V_43 ] ) ;
if ( V_44 == 0 )
continue;
V_28 -> V_45 = F_44 ( V_44 * sizeof( * V_13 ) ,
V_113 ) ;
if ( V_28 -> V_45 == NULL )
return - V_114 ;
V_28 -> V_44 = V_44 ;
V_13 = V_28 -> V_45 ;
for ( V_43 = 0 ; V_43 < V_147 * 8 ; ++ V_43 ) {
if ( F_5 ( V_146 , V_43 ) == 0 )
continue;
V_13 -> V_28 = V_28 ;
V_13 -> V_90 = V_43 ;
F_52 ( V_55 , V_13 ) ;
V_13 ++ ;
}
}
return 0 ;
}
static void F_55 ( struct V_93 * V_55 ,
struct V_12 * V_13 )
{
struct V_1 * V_2 , * V_153 ;
F_56 (mapping, nm, &ctrl->info.mappings, list) {
F_57 ( & V_2 -> V_136 ) ;
F_35 ( V_2 -> V_86 ) ;
F_35 ( V_2 ) ;
}
}
void F_58 ( struct V_93 * V_55 )
{
struct V_27 * V_28 ;
unsigned int V_43 ;
F_12 (entity, &dev->entities, list) {
for ( V_43 = 0 ; V_43 < V_28 -> V_44 ; ++ V_43 ) {
struct V_12 * V_13 = & V_28 -> V_45 [ V_43 ] ;
if ( ! V_13 -> V_46 )
continue;
F_55 ( V_55 , V_13 ) ;
F_35 ( V_13 -> V_15 ) ;
}
F_35 ( V_28 -> V_45 ) ;
}
}
