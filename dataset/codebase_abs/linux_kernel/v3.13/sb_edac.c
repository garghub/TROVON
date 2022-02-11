static char * F_1 ( T_1 V_1 )
{
switch( F_2 ( V_1 ) ) {
case 0 :
return L_1 ;
case 1 :
return L_2 ;
case 2 :
return L_3 ;
default:
return L_4 ;
}
}
static inline int F_3 ( const struct V_2 * V_3 , T_1 V_1 ,
int V_4 )
{
return F_4 ( V_1 , V_3 [ V_4 ] . V_5 ,
V_3 [ V_4 ] . V_6 ) ;
}
static inline int F_5 ( T_1 V_7 )
{
int V_8 = ( 1 << F_6 ( V_7 ) ) ;
if ( V_8 > 4 ) {
F_7 ( 0 , L_5 ,
V_8 , ( unsigned int ) F_6 ( V_7 ) , V_7 ) ;
return - V_9 ;
}
return V_8 ;
}
static inline int F_8 ( T_1 V_7 )
{
int V_10 = ( F_9 ( V_7 ) + 12 ) ;
if ( V_10 < 13 || V_10 > 18 ) {
F_7 ( 0 , L_6 ,
V_10 , ( unsigned int ) F_9 ( V_7 ) , V_7 ) ;
return - V_9 ;
}
return 1 << V_10 ;
}
static inline int F_10 ( T_1 V_7 )
{
int V_11 = ( F_11 ( V_7 ) + 10 ) ;
if ( V_11 > 12 ) {
F_7 ( 0 , L_7 ,
V_11 , ( unsigned int ) F_11 ( V_7 ) , V_7 ) ;
return - V_9 ;
}
return 1 << V_11 ;
}
static struct V_12 * F_12 ( T_2 V_13 )
{
struct V_12 * V_12 ;
F_13 (sbridge_dev, &sbridge_edac_list, list) {
if ( V_12 -> V_13 == V_13 )
return V_12 ;
}
return NULL ;
}
static struct V_12 * F_14 ( T_2 V_13 ,
const struct V_14 * V_3 )
{
struct V_12 * V_12 ;
V_12 = F_15 ( sizeof( * V_12 ) , V_15 ) ;
if ( ! V_12 )
return NULL ;
V_12 -> V_16 = F_15 ( sizeof( * V_12 -> V_16 ) * V_3 -> V_17 ,
V_15 ) ;
if ( ! V_12 -> V_16 ) {
F_16 ( V_12 ) ;
return NULL ;
}
V_12 -> V_13 = V_13 ;
V_12 -> V_17 = V_3 -> V_17 ;
F_17 ( & V_12 -> V_18 , & V_19 ) ;
return V_12 ;
}
static void F_18 ( struct V_12 * V_12 )
{
F_19 ( & V_12 -> V_18 ) ;
F_16 ( V_12 -> V_16 ) ;
F_16 ( V_12 ) ;
}
static T_3 F_20 ( struct V_20 * V_21 )
{
T_1 V_1 ;
F_21 ( V_21 -> V_22 , V_23 , & V_1 ) ;
return F_22 ( V_1 ) ;
}
static T_3 F_23 ( struct V_20 * V_21 )
{
T_1 V_1 ;
F_21 ( V_21 -> V_22 , V_24 , & V_1 ) ;
return F_24 ( V_1 ) ;
}
static T_3 F_25 ( struct V_20 * V_21 )
{
T_1 V_1 ;
F_21 ( V_21 -> V_25 , V_23 , & V_1 ) ;
return F_22 ( V_1 ) ;
}
static T_3 F_26 ( struct V_20 * V_21 )
{
T_1 V_1 ;
F_21 ( V_21 -> V_25 , V_24 , & V_1 ) ;
return F_24 ( V_1 ) ;
}
static inline T_2 F_27 ( T_2 V_26 )
{
return ( V_26 >> 3 ) | ( V_26 & 0x3 ) ;
}
static inline T_2 F_28 ( T_2 V_26 )
{
return ( V_26 >> 2 ) & 0x1 ;
}
static struct V_27 * F_29 ( T_2 V_13 , unsigned V_28 ,
unsigned V_29 )
{
struct V_12 * V_12 = F_12 ( V_13 ) ;
int V_30 ;
if ( ! V_12 )
return NULL ;
for ( V_30 = 0 ; V_30 < V_12 -> V_17 ; V_30 ++ ) {
if ( ! V_12 -> V_16 [ V_30 ] )
continue;
if ( F_30 ( V_12 -> V_16 [ V_30 ] -> V_31 ) == V_28 &&
F_31 ( V_12 -> V_16 [ V_30 ] -> V_31 ) == V_29 ) {
F_7 ( 1 , L_8 ,
V_13 , V_28 , V_29 , V_12 -> V_16 [ V_30 ] ) ;
return V_12 -> V_16 [ V_30 ] ;
}
}
return NULL ;
}
static int F_32 ( const T_2 V_13 )
{
struct V_27 * V_16 = NULL ;
T_1 V_32 ;
V_16 = F_29 ( V_13 , 15 , 0 ) ;
if ( ! V_16 ) {
F_33 ( V_33 , L_9
L_10 ,
V_13 , 15 , 0 ) ;
return - V_34 ;
}
F_21 ( V_16 , V_35 , & V_32 ) ;
if ( ! F_34 ( V_32 ) ) {
F_33 ( V_33 , L_11 ) ;
return - V_34 ;
}
return 0 ;
}
static int F_35 ( struct V_36 * V_37 )
{
struct V_20 * V_21 = V_37 -> V_38 ;
struct V_39 * V_40 ;
unsigned V_30 , V_41 , V_42 , V_8 , V_10 , V_11 , V_43 ;
T_3 V_44 ;
T_1 V_1 ;
enum V_45 V_46 ;
enum V_47 V_48 ;
F_21 ( V_21 -> V_49 , V_50 , & V_1 ) ;
V_21 -> V_12 -> V_51 = F_36 ( V_1 ) ;
F_21 ( V_21 -> V_49 , V_52 , & V_1 ) ;
V_21 -> V_12 -> V_53 = F_37 ( V_1 ) ;
F_7 ( 0 , L_12 ,
V_21 -> V_12 -> V_54 ,
V_21 -> V_12 -> V_53 ,
V_21 -> V_12 -> V_51 ) ;
F_21 ( V_21 -> V_55 , V_56 , & V_1 ) ;
if ( F_38 ( V_1 ) ) {
F_7 ( 0 , L_13 ) ;
V_21 -> V_57 = true ;
} else {
F_7 ( 0 , L_14 ) ;
V_21 -> V_57 = false ;
}
F_21 ( V_21 -> V_58 , V_35 , & V_21 -> V_59 . V_32 ) ;
if ( F_39 ( V_21 -> V_59 . V_32 ) ) {
F_7 ( 0 , L_15 ) ;
V_46 = V_60 ;
V_21 -> V_61 = true ;
} else {
F_7 ( 0 , L_16 ) ;
V_46 = V_62 ;
V_21 -> V_61 = false ;
}
if ( F_40 ( V_21 -> V_59 . V_32 ) ) {
F_7 ( 0 , L_17 ) ;
V_21 -> V_63 = true ;
} else {
F_7 ( 0 , L_18 ) ;
V_21 -> V_63 = false ;
}
if ( V_21 -> V_64 ) {
F_21 ( V_21 -> V_64 , V_21 -> V_59 . V_65 ,
& V_1 ) ;
if ( F_41 ( V_1 ) ) {
F_7 ( 0 , L_19 ) ;
V_48 = V_66 ;
} else {
F_7 ( 0 , L_20 ) ;
V_48 = V_67 ;
}
} else {
F_7 ( 0 , L_21 ) ;
V_48 = V_68 ;
}
V_42 = 8 ;
for ( V_30 = 0 ; V_30 < V_69 ; V_30 ++ ) {
T_1 V_7 ;
for ( V_41 = 0 ; V_41 < F_42 ( V_70 ) ; V_41 ++ ) {
V_40 = F_43 ( V_37 -> V_71 , V_37 -> V_72 , V_37 -> V_73 ,
V_30 , V_41 , 0 ) ;
F_21 ( V_21 -> V_74 [ V_30 ] ,
V_70 [ V_41 ] , & V_7 ) ;
F_7 ( 4 , L_22 , V_30 , V_41 , V_7 ) ;
if ( F_44 ( V_7 ) ) {
V_21 -> V_75 [ V_30 ] . V_72 ++ ;
V_8 = F_5 ( V_7 ) ;
V_10 = F_8 ( V_7 ) ;
V_11 = F_10 ( V_7 ) ;
V_44 = ( ( T_3 ) V_10 * V_11 * V_42 * V_8 ) >> ( 20 - 3 ) ;
V_43 = F_45 ( V_44 ) ;
F_7 ( 0 , L_23 ,
V_21 -> V_12 -> V_54 , V_30 , V_41 ,
V_44 , V_43 ,
V_42 , V_8 , V_10 , V_11 ) ;
V_40 -> V_76 = V_43 ;
V_40 -> V_77 = 32 ;
V_40 -> V_78 = ( V_42 == 8 ) ? V_79 : V_80 ;
V_40 -> V_48 = V_48 ;
V_40 -> V_81 = V_46 ;
snprintf ( V_40 -> V_82 , sizeof( V_40 -> V_82 ) ,
L_24 ,
V_21 -> V_12 -> V_51 , V_30 , V_41 ) ;
}
}
}
return 0 ;
}
static void F_46 ( const struct V_36 * V_37 )
{
struct V_20 * V_21 = V_37 -> V_38 ;
int V_30 , V_41 , V_83 , V_84 , V_85 , V_86 ;
T_1 V_1 ;
T_3 V_87 , V_88 = 0 ;
T_3 V_89 ;
T_1 V_90 , V_91 ;
T_1 V_92 ;
V_21 -> V_93 = V_21 -> V_59 . V_94 ( V_21 ) ;
V_89 = ( 1 + V_21 -> V_93 ) >> 20 ;
V_90 = F_47 ( V_89 , 1000 , & V_91 ) ;
F_7 ( 0 , L_25 , V_90 , V_91 , ( T_3 ) V_21 -> V_93 ) ;
V_21 -> V_95 = V_21 -> V_59 . V_96 ( V_21 ) ;
V_89 = ( 1 + V_21 -> V_95 ) >> 20 ;
V_90 = F_47 ( V_89 , 1000 , & V_91 ) ;
F_7 ( 0 , L_26 , V_90 , V_91 , ( T_3 ) V_21 -> V_95 ) ;
V_88 = 0 ;
for ( V_84 = 0 ; V_84 < V_21 -> V_59 . V_97 ; V_84 ++ ) {
F_21 ( V_21 -> V_98 , V_21 -> V_59 . V_99 [ V_84 ] ,
& V_1 ) ;
V_87 = F_48 ( V_1 ) ;
if ( ! F_49 ( V_1 ) )
continue;
if ( V_87 <= V_88 )
break;
V_89 = ( V_87 + 1 ) >> 20 ;
V_90 = F_47 ( V_89 , 1000 , & V_91 ) ;
F_7 ( 0 , L_27 ,
V_84 ,
F_1 ( V_1 ) ,
V_90 , V_91 ,
( ( T_3 ) V_89 ) << 20L ,
F_50 ( V_1 ) ? L_28 : L_29 ,
V_1 ) ;
V_88 = V_87 ;
F_21 ( V_21 -> V_98 , V_21 -> V_59 . V_100 [ V_84 ] ,
& V_1 ) ;
V_86 = F_3 ( V_21 -> V_59 . V_2 , V_1 , 0 ) ;
for ( V_41 = 0 ; V_41 < 8 ; V_41 ++ ) {
T_1 V_26 = F_3 ( V_21 -> V_59 . V_2 , V_1 , V_41 ) ;
if ( V_41 > 0 && V_86 == V_26 )
break;
F_7 ( 0 , L_30 ,
V_84 , V_41 , V_26 ) ;
}
}
V_88 = 0 ;
for ( V_85 = 0 ; V_85 < V_101 ; V_85 ++ ) {
F_21 ( V_21 -> V_102 , V_103 [ V_85 ] ,
& V_1 ) ;
V_87 = F_51 ( V_1 ) ;
if ( V_87 <= V_88 )
break;
V_89 = ( V_87 + 1 ) >> 20 ;
V_90 = F_47 ( V_89 , 1000 , & V_91 ) ;
F_7 ( 0 , L_31 ,
V_85 , V_90 , V_91 ,
( ( T_3 ) V_89 ) << 20L ,
( T_1 ) F_52 ( V_1 ) ,
( T_1 ) F_53 ( V_1 ) ,
( T_1 ) F_54 ( V_1 ) ,
( T_1 ) F_55 ( V_1 ) ,
( T_1 ) F_56 ( V_1 ) ,
( T_1 ) F_57 ( V_1 ) ,
V_1 ) ;
V_88 = V_87 ;
}
for ( V_30 = 0 ; V_30 < V_69 ; V_30 ++ ) {
if ( ! V_21 -> V_75 [ V_30 ] . V_72 )
continue;
for ( V_41 = 0 ; V_41 < V_85 ; V_41 ++ ) {
F_21 ( V_21 -> V_74 [ V_30 ] ,
V_104 [ V_41 ] ,
& V_1 ) ;
V_89 = F_58 ( V_1 ) >> 20 ;
V_90 = F_47 ( V_89 , 1000 , & V_91 ) ;
F_7 ( 0 , L_32 ,
V_30 , V_41 ,
V_90 , V_91 ,
( ( T_3 ) V_89 ) << 20L ,
V_1 ) ;
}
}
for ( V_30 = 0 ; V_30 < V_69 ; V_30 ++ ) {
if ( ! V_21 -> V_75 [ V_30 ] . V_72 )
continue;
for ( V_41 = 0 ; V_41 < V_105 ; V_41 ++ ) {
F_21 ( V_21 -> V_74 [ V_30 ] ,
V_106 [ V_41 ] ,
& V_1 ) ;
if ( ! F_59 ( V_1 ) )
continue;
V_89 = F_60 ( V_1 ) >> 20 ;
V_92 = 1 << F_61 ( V_1 ) ;
V_90 = F_47 ( V_89 , 1000 , & V_91 ) ;
F_7 ( 0 , L_33 ,
V_30 , V_41 ,
V_90 , V_91 ,
( ( T_3 ) V_89 ) << 20L ,
V_92 ,
V_1 ) ;
for ( V_83 = 0 ; V_83 < V_92 ; V_83 ++ ) {
F_21 ( V_21 -> V_74 [ V_30 ] ,
V_107 [ V_41 ] [ V_83 ] ,
& V_1 ) ;
V_89 = F_62 ( V_1 ) << 6 ;
V_90 = F_47 ( V_89 , 1000 , & V_91 ) ;
F_7 ( 0 , L_34 ,
V_30 , V_41 , V_83 ,
V_90 , V_91 ,
( ( T_3 ) V_89 ) << 20L ,
( T_1 ) F_63 ( V_1 ) ,
V_1 ) ;
}
}
}
}
struct V_36 * F_64 ( T_2 V_53 )
{
struct V_12 * V_12 ;
F_13 (sbridge_dev, &sbridge_edac_list, list) {
if ( V_12 -> V_53 == V_53 )
return V_12 -> V_37 ;
}
return NULL ;
}
static int F_65 ( struct V_36 * V_37 ,
T_3 V_108 ,
T_2 * V_109 ,
long * V_110 ,
T_2 * V_111 ,
char * * V_112 , char * V_113 )
{
struct V_36 * V_114 ;
struct V_20 * V_21 = V_37 -> V_38 ;
struct V_27 * V_115 ;
int V_116 , V_84 , V_85 , V_117 , V_118 ;
int V_86 , V_119 , V_120 ;
int V_121 ;
unsigned V_122 [ V_21 -> V_59 . V_123 ] ;
T_1 V_1 ;
T_2 V_124 , V_125 , V_26 , V_126 = 0 ;
T_1 V_127 ;
T_1 V_92 ;
T_1 V_90 , V_91 ;
T_3 V_128 , V_129 , V_87 = 0 , V_88 = 0 ;
if ( ( V_108 > ( T_3 ) V_21 -> V_93 ) && ( V_108 < ( 1LL << 32 ) ) ) {
sprintf ( V_113 , L_35 , V_108 ) ;
return - V_9 ;
}
if ( V_108 >= ( T_3 ) V_21 -> V_95 ) {
sprintf ( V_113 , L_36 , V_108 ) ;
return - V_9 ;
}
for ( V_84 = 0 ; V_84 < V_21 -> V_59 . V_97 ; V_84 ++ ) {
F_21 ( V_21 -> V_98 , V_21 -> V_59 . V_99 [ V_84 ] ,
& V_1 ) ;
if ( ! F_49 ( V_1 ) )
continue;
V_87 = F_48 ( V_1 ) ;
if ( V_87 <= V_88 ) {
sprintf ( V_113 , L_37 ) ;
return - V_9 ;
}
if ( V_108 <= V_87 )
break;
V_88 = V_87 ;
}
if ( V_84 == V_21 -> V_59 . V_97 ) {
sprintf ( V_113 , L_37 ) ;
return - V_9 ;
}
* V_112 = F_1 ( V_1 ) ;
V_121 = F_50 ( V_1 ) ;
F_21 ( V_21 -> V_98 , V_21 -> V_59 . V_100 [ V_84 ] ,
& V_1 ) ;
if ( V_21 -> V_59 . type == V_130 ) {
V_86 = F_3 ( V_21 -> V_59 . V_2 , V_1 , 0 ) ;
for ( V_117 = 0 ; V_117 < 8 ; V_117 ++ ) {
T_1 V_26 = F_3 ( V_21 -> V_59 . V_2 , V_1 , V_117 ) ;
if ( V_117 > 0 && V_86 == V_26 )
break;
V_122 [ V_117 ] = V_26 ;
F_7 ( 0 , L_38 ,
V_117 , V_122 [ V_117 ] ) ;
}
F_7 ( 0 , L_39 ,
V_21 -> V_12 -> V_54 ,
V_84 ,
V_108 ,
V_87 ,
V_117 + 7 ,
! V_121 ? L_40 : L_41 ) ;
if ( V_121 )
V_119 = ( ( V_108 >> 6 ) ^ ( V_108 >> 16 ) ) & 7 ;
else
V_119 = ( V_108 >> 6 ) & 7 ;
switch ( V_117 ) {
case 1 :
V_119 = 0 ;
break;
case 2 :
V_119 = V_119 & 1 ;
break;
case 4 :
V_119 = V_119 & 3 ;
break;
case 8 :
break;
default:
sprintf ( V_113 , L_42 ) ;
return - V_9 ;
}
* V_109 = V_122 [ V_119 ] ;
F_7 ( 0 , L_43 ,
V_119 , V_117 , * V_109 ) ;
} else {
V_119 = ( V_108 >> 6 ) & 7 ;
V_26 = F_3 ( V_21 -> V_59 . V_2 , V_1 , V_119 ) ;
* V_109 = F_27 ( V_26 ) ;
V_126 = F_28 ( V_26 ) ;
F_7 ( 0 , L_44 ,
V_119 , * V_109 , V_126 ) ;
}
V_114 = F_64 ( * V_109 ) ;
if ( ! V_114 ) {
sprintf ( V_113 , L_45 ,
* V_109 ) ;
return - V_9 ;
}
V_37 = V_114 ;
V_21 = V_37 -> V_38 ;
V_88 = 0 ;
if ( V_21 -> V_59 . type == V_130 )
V_115 = V_21 -> V_102 ;
else {
if ( V_126 )
V_115 = V_21 -> V_131 ;
else
V_115 = V_21 -> V_102 ;
}
for ( V_85 = 0 ; V_85 < V_101 ; V_85 ++ ) {
F_21 ( V_115 , V_103 [ V_85 ] , & V_1 ) ;
V_87 = F_51 ( V_1 ) ;
if ( V_87 <= V_88 ) {
sprintf ( V_113 , L_46 ) ;
return - V_9 ;
}
if ( V_108 <= V_87 )
break;
V_88 = V_87 ;
}
if ( V_85 == V_101 ) {
sprintf ( V_113 , L_46 ) ;
return - V_9 ;
}
V_124 = F_53 ( V_1 ) + 1 ;
V_125 = F_52 ( V_1 ) + 1 ;
if ( V_124 == 3 )
V_119 = V_108 >> 6 ;
else
V_119 = V_108 >> ( 6 + V_125 ) ;
V_119 = V_119 % V_124 ;
switch ( V_119 ) {
case 0 :
V_120 = F_54 ( V_1 ) ;
break;
case 1 :
V_120 = F_55 ( V_1 ) ;
break;
case 2 :
V_120 = F_56 ( V_1 ) ;
break;
case 3 :
V_120 = F_57 ( V_1 ) ;
break;
default:
sprintf ( V_113 , L_47 ) ;
return - V_9 ;
}
* V_110 = 1 << V_120 ;
F_21 ( V_21 -> V_74 [ V_120 ] ,
V_104 [ V_85 ] ,
& V_127 ) ;
if ( V_21 -> V_57 ) {
* V_110 |= 1 << ( ( V_120 + 2 ) % 4 ) ;
switch( V_124 ) {
case 2 :
case 4 :
V_118 = 1 << V_125 * ( V_124 >> 1 ) ;
break;
default:
sprintf ( V_113 , L_48 ) ;
return - V_9 ;
}
} else
V_118 = ( 1 << V_125 ) * V_124 ;
if ( V_21 -> V_61 )
* V_110 |= 1 << ( ( V_120 + 1 ) % 4 ) ;
V_129 = F_58 ( V_127 ) ;
F_7 ( 0 , L_49 ,
V_85 ,
V_108 ,
V_87 ,
( T_1 ) F_52 ( V_1 ) ,
V_124 ,
V_129 ,
V_119 ,
V_120 ,
* V_110 ) ;
if ( V_129 > V_108 ) {
sprintf ( V_113 , L_50 ,
V_129 , V_108 ) ;
return - V_9 ;
}
V_108 -= V_129 ;
V_128 = V_108 & 0x7f ;
V_108 >>= 6 ;
V_108 = F_66 ( V_108 , V_118 ) ;
#if 0
addr = addr / ch_way;
#endif
V_128 |= V_108 << 6 ;
for ( V_116 = 0 ; V_116 < V_105 ; V_116 ++ ) {
F_21 ( V_21 -> V_74 [ V_120 ] ,
V_106 [ V_116 ] ,
& V_1 ) ;
if ( ! F_59 ( V_1 ) )
continue;
V_87 = F_60 ( V_1 ) ;
V_90 = F_47 ( V_87 >> 20 , 1000 , & V_91 ) ;
F_7 ( 0 , L_51 ,
V_116 ,
V_90 , V_91 ,
V_87 ,
1 << F_61 ( V_1 ) ) ;
if ( V_128 <= V_87 )
break;
}
if ( V_116 == V_105 ) {
sprintf ( V_113 , L_52 ,
V_128 ) ;
return - V_9 ;
}
V_92 = F_61 ( V_1 ) ;
if ( V_21 -> V_63 )
V_119 = ( V_128 >> 6 ) ;
else
V_119 = ( V_128 >> 13 ) ;
V_119 %= 1 << V_92 ;
F_21 ( V_21 -> V_74 [ V_120 ] ,
V_107 [ V_116 ] [ V_119 ] ,
& V_1 ) ;
* V_111 = F_63 ( V_1 ) ;
F_7 ( 0 , L_53 ,
V_116 ,
V_128 ,
V_87 ,
V_92 ,
V_119 ) ;
return 0 ;
}
static void F_67 ( struct V_12 * V_12 )
{
int V_30 ;
F_7 ( 0 , L_54 ) ;
for ( V_30 = 0 ; V_30 < V_12 -> V_17 ; V_30 ++ ) {
struct V_27 * V_16 = V_12 -> V_16 [ V_30 ] ;
if ( ! V_16 )
continue;
F_7 ( 0 , L_55 ,
V_16 -> V_13 -> V_132 ,
F_30 ( V_16 -> V_31 ) , F_31 ( V_16 -> V_31 ) ) ;
F_68 ( V_16 ) ;
}
}
static void F_69 ( void )
{
struct V_12 * V_12 , * V_133 ;
F_70 (sbridge_dev, tmp, &sbridge_edac_list, list) {
F_67 ( V_12 ) ;
F_18 ( V_12 ) ;
}
}
static int F_71 ( struct V_27 * * V_134 ,
T_2 * V_135 ,
const struct V_14 * V_3 ,
const unsigned V_136 )
{
struct V_12 * V_12 ;
const struct V_137 * V_138 = & V_3 -> V_139 [ V_136 ] ;
struct V_27 * V_16 = NULL ;
T_2 V_13 = 0 ;
F_33 ( V_140 ,
L_56 ,
V_138 -> V_141 , V_138 -> V_29 ,
V_142 , V_138 -> V_143 ) ;
V_16 = F_72 ( V_142 ,
V_138 -> V_143 , * V_134 ) ;
if ( ! V_16 ) {
if ( * V_134 ) {
* V_134 = V_16 ;
return 0 ;
}
if ( V_138 -> V_144 )
return 0 ;
if ( V_136 == 0 )
return - V_34 ;
F_33 ( V_140 ,
L_57 ,
V_138 -> V_141 , V_138 -> V_29 ,
V_142 , V_138 -> V_143 ) ;
return - V_34 ;
}
V_13 = V_16 -> V_13 -> V_132 ;
V_12 = F_12 ( V_13 ) ;
if ( ! V_12 ) {
V_12 = F_14 ( V_13 , V_3 ) ;
if ( ! V_12 ) {
F_68 ( V_16 ) ;
return - V_145 ;
}
( * V_135 ) ++ ;
}
if ( V_12 -> V_16 [ V_136 ] ) {
F_33 ( V_33 ,
L_58
L_59 ,
V_13 , V_138 -> V_141 , V_138 -> V_29 ,
V_142 , V_138 -> V_143 ) ;
F_68 ( V_16 ) ;
return - V_34 ;
}
V_12 -> V_16 [ V_136 ] = V_16 ;
if ( F_73 ( F_30 ( V_16 -> V_31 ) != V_138 -> V_141 ||
F_31 ( V_16 -> V_31 ) != V_138 -> V_29 ) ) {
F_33 ( V_33 ,
L_60
L_61 ,
V_142 , V_138 -> V_143 ,
V_13 , F_30 ( V_16 -> V_31 ) , F_31 ( V_16 -> V_31 ) ,
V_13 , V_138 -> V_141 , V_138 -> V_29 ) ;
return - V_34 ;
}
if ( F_73 ( F_74 ( V_16 ) < 0 ) ) {
F_33 ( V_33 ,
L_62
L_59 ,
V_13 , V_138 -> V_141 , V_138 -> V_29 ,
V_142 , V_138 -> V_143 ) ;
return - V_34 ;
}
F_7 ( 0 , L_63 ,
V_13 , V_138 -> V_141 , V_138 -> V_29 ,
V_142 , V_138 -> V_143 ) ;
F_75 ( V_16 ) ;
* V_134 = V_16 ;
return 0 ;
}
static int F_76 ( T_2 * V_135 ,
const struct V_14 * V_3 )
{
int V_30 , V_146 ;
struct V_27 * V_16 = NULL ;
while ( V_3 && V_3 -> V_139 ) {
for ( V_30 = 0 ; V_30 < V_3 -> V_17 ; V_30 ++ ) {
V_16 = NULL ;
do {
V_146 = F_71 ( & V_16 , V_135 ,
V_3 , V_30 ) ;
if ( V_146 < 0 ) {
if ( V_30 == 0 ) {
V_30 = V_3 -> V_17 ;
break;
}
F_69 () ;
return - V_34 ;
}
} while ( V_16 );
}
V_3 ++ ;
}
return 0 ;
}
static int F_77 ( struct V_36 * V_37 ,
struct V_12 * V_12 )
{
struct V_20 * V_21 = V_37 -> V_38 ;
struct V_27 * V_16 ;
int V_30 , V_29 , V_28 ;
for ( V_30 = 0 ; V_30 < V_12 -> V_17 ; V_30 ++ ) {
V_16 = V_12 -> V_16 [ V_30 ] ;
if ( ! V_16 )
continue;
V_28 = F_30 ( V_16 -> V_31 ) ;
V_29 = F_31 ( V_16 -> V_31 ) ;
switch ( V_28 ) {
case 12 :
switch ( V_29 ) {
case 6 :
V_21 -> V_98 = V_16 ;
break;
case 7 :
V_21 -> V_22 = V_16 ;
break;
default:
goto error;
}
break;
case 13 :
switch ( V_29 ) {
case 6 :
V_21 -> V_49 = V_16 ;
break;
default:
goto error;
}
break;
case 14 :
switch ( V_29 ) {
case 0 :
V_21 -> V_102 = V_16 ;
break;
default:
goto error;
}
break;
case 15 :
switch ( V_29 ) {
case 0 :
V_21 -> V_58 = V_16 ;
break;
case 1 :
V_21 -> V_55 = V_16 ;
break;
case 2 :
case 3 :
case 4 :
case 5 :
V_21 -> V_74 [ V_29 - 2 ] = V_16 ;
break;
default:
goto error;
}
break;
case 17 :
switch ( V_29 ) {
case 0 :
V_21 -> V_64 = V_16 ;
break;
default:
goto error;
}
break;
default:
goto error;
}
F_7 ( 0 , L_64 ,
V_12 -> V_13 ,
F_30 ( V_16 -> V_31 ) , F_31 ( V_16 -> V_31 ) ,
V_16 ) ;
}
if ( ! V_21 -> V_98 || ! V_21 -> V_22 || ! V_21 -> V_102 ||
! V_21 -> V_74 || ! V_21 -> V_55 || ! V_21 -> V_58 )
goto V_147;
for ( V_30 = 0 ; V_30 < V_69 ; V_30 ++ ) {
if ( ! V_21 -> V_74 [ V_30 ] )
goto V_147;
}
return 0 ;
V_147:
F_33 ( V_33 , L_65 ) ;
return - V_34 ;
error:
F_33 ( V_33 , L_66
L_67 ,
V_28 , V_29 ) ;
return - V_9 ;
}
static int F_78 ( struct V_36 * V_37 ,
struct V_12 * V_12 )
{
struct V_20 * V_21 = V_37 -> V_38 ;
struct V_27 * V_16 , * V_133 ;
int V_30 , V_29 , V_28 ;
bool V_148 = false ;
V_133 = F_72 ( V_142 ,
V_149 , NULL ) ;
if ( V_133 ) {
V_148 = true ;
F_68 ( V_133 ) ;
}
for ( V_30 = 0 ; V_30 < V_12 -> V_17 ; V_30 ++ ) {
V_16 = V_12 -> V_16 [ V_30 ] ;
if ( ! V_16 )
continue;
V_28 = F_30 ( V_16 -> V_31 ) ;
V_29 = F_31 ( V_16 -> V_31 ) ;
switch ( V_28 ) {
case 14 :
if ( V_29 == 0 ) {
V_21 -> V_102 = V_16 ;
break;
}
goto error;
case 15 :
switch ( V_29 ) {
case 0 :
V_21 -> V_58 = V_16 ;
break;
case 1 :
V_21 -> V_55 = V_16 ;
break;
case 4 :
case 5 :
if ( V_148 )
break;
case 2 :
case 3 :
V_21 -> V_74 [ V_29 - 2 ] = V_16 ;
break;
default:
goto error;
}
break;
case 17 :
if ( V_29 == 4 ) {
V_21 -> V_64 = V_16 ;
break;
} else if ( V_29 == 0 ) {
if ( ! V_148 )
V_21 -> V_64 = V_16 ;
break;
}
goto error;
case 22 :
switch ( V_29 ) {
case 0 :
V_21 -> V_98 = V_16 ;
break;
case 1 :
V_21 -> V_49 = V_16 ;
break;
case 2 :
V_21 -> V_25 = V_16 ;
break;
default:
goto error;
}
break;
case 28 :
if ( V_29 == 0 ) {
V_21 -> V_131 = V_16 ;
break;
}
goto error;
case 29 :
F_79 ( ! V_148 ) ;
if ( V_29 == 2 || V_29 == 3 ) {
V_21 -> V_74 [ V_29 ] = V_16 ;
break;
}
goto error;
default:
goto error;
}
F_7 ( 0 , L_64 ,
V_12 -> V_13 ,
F_30 ( V_16 -> V_31 ) , F_31 ( V_16 -> V_31 ) ,
V_16 ) ;
}
if ( ! V_21 -> V_98 || ! V_21 -> V_102 || ! V_21 -> V_49 ||
! V_21 -> V_25 || ! V_21 -> V_74 || ! V_21 -> V_55 ||
! V_21 -> V_58 )
goto V_147;
for ( V_30 = 0 ; V_30 < V_69 ; V_30 ++ ) {
if ( ! V_21 -> V_74 [ V_30 ] )
goto V_147;
}
return 0 ;
V_147:
F_33 ( V_33 , L_65 ) ;
return - V_34 ;
error:
F_33 ( V_33 ,
L_68 ,
V_28 , V_29 ) ;
return - V_9 ;
}
static void F_80 ( struct V_36 * V_37 ,
const struct V_150 * V_151 )
{
struct V_36 * V_114 ;
struct V_20 * V_21 = V_37 -> V_38 ;
enum V_152 V_153 ;
char * type , * V_154 , V_113 [ 256 ] ;
bool V_155 = F_4 ( V_151 -> V_156 , 0 , 0 ) ;
bool V_157 = F_4 ( V_151 -> V_158 , 62 , 62 ) ;
bool V_159 = F_4 ( V_151 -> V_158 , 61 , 61 ) ;
bool V_160 ;
T_1 V_161 = F_4 ( V_151 -> V_158 , 38 , 52 ) ;
T_1 V_162 = F_4 ( V_151 -> V_158 , 16 , 31 ) ;
T_1 V_163 = F_4 ( V_151 -> V_158 , 0 , 15 ) ;
T_1 V_75 = F_4 ( V_151 -> V_158 , 0 , 3 ) ;
T_1 V_164 = F_4 ( V_151 -> V_158 , 4 , 6 ) ;
long V_110 , V_165 ;
T_2 V_111 , V_109 ;
int V_146 , V_40 ;
char * V_112 = NULL ;
if ( V_21 -> V_59 . type == V_166 )
V_160 = true ;
else
V_160 = F_4 ( V_151 -> V_158 , 56 , 56 ) ;
if ( V_159 ) {
if ( V_155 ) {
type = L_69 ;
V_153 = V_167 ;
} else {
type = L_70 ;
V_153 = V_168 ;
}
} else {
type = L_71 ;
V_153 = V_169 ;
}
if ( ! ( ( V_163 & 0xef80 ) == 0x80 ) ) {
V_154 = L_72 ;
} else {
switch ( V_164 ) {
case 0 :
V_154 = L_73 ;
break;
case 1 :
V_154 = L_74 ;
break;
case 2 :
V_154 = L_75 ;
break;
case 3 :
V_154 = L_76 ;
break;
case 4 :
V_154 = L_77 ;
break;
default:
V_154 = L_78 ;
break;
}
}
if ( ! F_4 ( V_151 -> V_158 , 58 , 58 ) )
return;
V_146 = F_65 ( V_37 , V_151 -> V_108 , & V_109 ,
& V_110 , & V_111 , & V_112 , V_113 ) ;
if ( V_146 < 0 )
goto V_170;
V_114 = F_64 ( V_109 ) ;
if ( ! V_114 ) {
strcpy ( V_113 , L_79 ) ;
goto V_170;
}
V_37 = V_114 ;
V_21 = V_37 -> V_38 ;
V_165 = F_81 ( & V_110 , V_69 ) ;
if ( V_111 < 4 )
V_40 = 0 ;
else if ( V_111 < 8 )
V_40 = 1 ;
else
V_40 = 2 ;
snprintf ( V_113 , sizeof( V_113 ) ,
L_80 ,
V_157 ? L_81 : L_40 ,
( V_159 && V_160 ) ? L_82 : L_40 ,
V_112 ,
V_162 , V_163 ,
V_109 ,
V_110 ,
V_111 ) ;
F_7 ( 0 , L_83 , V_113 ) ;
F_82 ( V_153 , V_37 , V_161 ,
V_151 -> V_108 >> V_171 , V_151 -> V_108 & ~ V_172 , 0 ,
V_75 , V_40 , - 1 ,
V_154 , V_113 ) ;
return;
V_170:
F_82 ( V_153 , V_37 , V_161 , 0 , 0 , 0 ,
- 1 , - 1 , - 1 ,
V_113 , L_40 ) ;
}
static void F_83 ( struct V_36 * V_37 )
{
struct V_20 * V_21 = V_37 -> V_38 ;
int V_30 ;
unsigned V_173 = 0 ;
struct V_150 * V_151 ;
F_84 () ;
V_173 = ( V_21 -> V_174 + V_175 - V_21 -> V_176 )
% V_175 ;
if ( ! V_173 )
return;
V_151 = V_21 -> V_177 ;
if ( V_21 -> V_176 + V_173 > V_175 ) {
unsigned V_178 = V_175 - V_21 -> V_176 ;
memcpy ( V_151 , & V_21 -> V_179 [ V_21 -> V_176 ] , sizeof( * V_151 ) * V_178 ) ;
F_85 () ;
V_21 -> V_176 = 0 ;
V_173 -= V_178 ;
V_151 += V_178 ;
}
memcpy ( V_151 , & V_21 -> V_179 [ V_21 -> V_176 ] , sizeof( * V_151 ) * V_173 ) ;
F_85 () ;
V_21 -> V_176 += V_173 ;
F_84 () ;
if ( V_21 -> V_180 ) {
F_33 ( V_33 , L_84 ,
V_21 -> V_180 ) ;
F_85 () ;
V_21 -> V_180 = 0 ;
}
for ( V_30 = 0 ; V_30 < V_173 ; V_30 ++ )
F_80 ( V_37 , & V_21 -> V_177 [ V_30 ] ) ;
}
static int F_86 ( struct V_181 * V_182 , unsigned long V_183 ,
void * V_184 )
{
struct V_150 * V_150 = (struct V_150 * ) V_184 ;
struct V_36 * V_37 ;
struct V_20 * V_21 ;
V_37 = F_64 ( V_150 -> V_185 ) ;
if ( ! V_37 )
return V_186 ;
V_21 = V_37 -> V_38 ;
if ( ( V_150 -> V_158 & 0xefff ) >> 7 != 1 )
return V_187 ;
F_87 ( L_85 ) ;
F_87 ( L_86 ,
V_150 -> V_188 , V_150 -> V_156 , V_150 -> V_189 , V_150 -> V_158 ) ;
F_87 ( L_87 , V_150 -> V_190 ) ;
F_87 ( L_88 , V_150 -> V_108 ) ;
F_87 ( L_89 , V_150 -> V_191 ) ;
F_87 ( L_90 ,
V_150 -> V_192 , V_150 -> V_193 , V_150 -> time ,
V_150 -> V_185 , V_150 -> V_194 ) ;
if ( F_88 ( V_150 -> V_195 ) . V_196 != V_21 -> V_12 -> V_54 )
return V_187 ;
F_84 () ;
if ( ( V_21 -> V_174 + 1 ) % V_175 == V_21 -> V_176 ) {
F_85 () ;
V_21 -> V_180 ++ ;
return V_187 ;
}
memcpy ( & V_21 -> V_179 [ V_21 -> V_174 ] , V_150 , sizeof( * V_150 ) ) ;
F_85 () ;
V_21 -> V_174 = ( V_21 -> V_174 + 1 ) % V_175 ;
if ( V_150 -> V_156 & 1 )
F_83 ( V_37 ) ;
return V_197 ;
}
static void F_89 ( struct V_12 * V_12 )
{
struct V_36 * V_37 = V_12 -> V_37 ;
struct V_20 * V_21 ;
if ( F_73 ( ! V_37 || ! V_37 -> V_38 ) ) {
F_7 ( 0 , L_91 , & V_12 -> V_16 [ 0 ] -> V_141 ) ;
F_33 ( V_33 , L_92 ) ;
return;
}
V_21 = V_37 -> V_38 ;
F_7 ( 0 , L_93 ,
V_37 , & V_12 -> V_16 [ 0 ] -> V_141 ) ;
F_90 ( V_37 -> V_16 ) ;
F_7 ( 1 , L_94 , V_37 -> V_198 ) ;
F_16 ( V_37 -> V_198 ) ;
F_91 ( V_37 ) ;
V_12 -> V_37 = NULL ;
}
static int F_92 ( struct V_12 * V_12 , enum type type )
{
struct V_36 * V_37 ;
struct V_199 V_71 [ 2 ] ;
struct V_20 * V_21 ;
struct V_27 * V_16 = V_12 -> V_16 [ 0 ] ;
int V_146 ;
V_146 = F_32 ( V_12 -> V_13 ) ;
if ( F_73 ( V_146 < 0 ) )
return V_146 ;
V_71 [ 0 ] . type = V_200 ;
V_71 [ 0 ] . V_44 = V_69 ;
V_71 [ 0 ] . V_201 = false ;
V_71 [ 1 ] . type = V_202 ;
V_71 [ 1 ] . V_44 = V_203 ;
V_71 [ 1 ] . V_201 = true ;
V_37 = F_93 ( V_12 -> V_54 , F_42 ( V_71 ) , V_71 ,
sizeof( * V_21 ) ) ;
if ( F_73 ( ! V_37 ) )
return - V_145 ;
F_7 ( 0 , L_93 ,
V_37 , & V_16 -> V_141 ) ;
V_21 = V_37 -> V_38 ;
memset ( V_21 , 0 , sizeof( * V_21 ) ) ;
V_21 -> V_12 = V_12 ;
V_12 -> V_37 = V_37 ;
V_37 -> V_204 = V_205 ;
V_37 -> V_206 = V_207 ;
V_37 -> V_208 = V_207 ;
V_37 -> V_209 = L_95 ;
V_37 -> V_210 = V_211 ;
V_37 -> V_212 = F_94 ( V_16 ) ;
V_37 -> V_213 = NULL ;
V_37 -> V_214 = F_83 ;
V_21 -> V_59 . type = type ;
if ( type == V_166 ) {
V_21 -> V_59 . V_65 = V_215 ;
V_21 -> V_59 . V_94 = F_25 ;
V_21 -> V_59 . V_96 = F_26 ;
V_21 -> V_59 . V_99 = V_216 ;
V_21 -> V_59 . V_97 = F_42 ( V_216 ) ;
V_21 -> V_59 . V_100 = V_217 ;
V_21 -> V_59 . V_123 = F_42 ( V_217 ) ;
V_21 -> V_59 . V_2 = V_218 ;
V_37 -> V_198 = F_95 ( V_15 , L_96 , V_37 -> V_219 ) ;
V_146 = F_78 ( V_37 , V_12 ) ;
if ( F_73 ( V_146 < 0 ) )
goto V_220;
} else {
V_21 -> V_59 . V_65 = V_221 ;
V_21 -> V_59 . V_94 = F_20 ;
V_21 -> V_59 . V_96 = F_23 ;
V_21 -> V_59 . V_99 = V_222 ;
V_21 -> V_59 . V_97 = F_42 ( V_222 ) ;
V_21 -> V_59 . V_100 = V_223 ;
V_21 -> V_59 . V_123 = F_42 ( V_223 ) ;
V_21 -> V_59 . V_2 = V_224 ;
V_37 -> V_198 = F_95 ( V_15 , L_97 , V_37 -> V_219 ) ;
V_146 = F_77 ( V_37 , V_12 ) ;
if ( F_73 ( V_146 < 0 ) )
goto V_220;
}
F_35 ( V_37 ) ;
F_46 ( V_37 ) ;
V_37 -> V_16 = & V_16 -> V_141 ;
if ( F_73 ( F_96 ( V_37 ) ) ) {
F_7 ( 0 , L_98 ) ;
V_146 = - V_9 ;
goto V_220;
}
return 0 ;
V_220:
F_16 ( V_37 -> V_198 ) ;
F_91 ( V_37 ) ;
V_12 -> V_37 = NULL ;
return V_146 ;
}
static int F_97 ( struct V_27 * V_16 , const struct V_225 * V_226 )
{
int V_146 ;
T_2 V_54 , V_135 = 0 ;
struct V_12 * V_12 ;
enum type type ;
F_98 ( & V_227 ) ;
if ( F_73 ( V_228 >= 1 ) ) {
F_99 ( & V_227 ) ;
return - V_34 ;
}
V_228 ++ ;
if ( V_16 -> V_229 == V_230 ) {
V_146 = F_76 ( & V_135 , V_231 ) ;
type = V_166 ;
} else {
V_146 = F_76 ( & V_135 , V_232 ) ;
type = V_130 ;
}
if ( F_73 ( V_146 < 0 ) )
goto V_220;
V_54 = 0 ;
F_13 (sbridge_dev, &sbridge_edac_list, list) {
F_7 ( 0 , L_99 ,
V_54 , V_54 + 1 , V_135 ) ;
V_12 -> V_54 = V_54 ++ ;
V_146 = F_92 ( V_12 , type ) ;
if ( F_73 ( V_146 < 0 ) )
goto V_233;
}
F_33 ( V_140 , L_100 ) ;
F_99 ( & V_227 ) ;
return 0 ;
V_233:
F_13 (sbridge_dev, &sbridge_edac_list, list)
F_89 ( V_12 ) ;
F_69 () ;
V_220:
F_99 ( & V_227 ) ;
return V_146 ;
}
static void F_100 ( struct V_27 * V_16 )
{
struct V_12 * V_12 ;
F_7 ( 0 , L_54 ) ;
F_98 ( & V_227 ) ;
if ( F_73 ( ! V_228 ) ) {
F_99 ( & V_227 ) ;
return;
}
F_13 (sbridge_dev, &sbridge_edac_list, list)
F_89 ( V_12 ) ;
F_69 () ;
V_228 -- ;
F_99 ( & V_227 ) ;
}
static int T_4 F_101 ( void )
{
int V_234 ;
F_7 ( 2 , L_54 ) ;
F_102 () ;
V_234 = F_103 ( & V_235 ) ;
if ( V_234 >= 0 ) {
F_104 ( & V_236 ) ;
return 0 ;
}
F_33 ( V_33 , L_101 ,
V_234 ) ;
return V_234 ;
}
static void T_5 F_105 ( void )
{
F_7 ( 2 , L_54 ) ;
F_106 ( & V_235 ) ;
F_107 ( & V_236 ) ;
}
