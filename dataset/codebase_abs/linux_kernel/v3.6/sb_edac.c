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
static inline int F_3 ( T_1 V_1 , int V_2 )
{
switch ( V_2 ) {
case 0 :
return F_4 ( V_1 ) ;
case 1 :
return F_5 ( V_1 ) ;
case 2 :
return F_6 ( V_1 ) ;
case 3 :
return F_7 ( V_1 ) ;
case 4 :
return F_8 ( V_1 ) ;
case 5 :
return F_9 ( V_1 ) ;
case 6 :
return F_10 ( V_1 ) ;
case 7 :
return F_11 ( V_1 ) ;
default:
return - V_3 ;
}
}
static inline int F_12 ( T_1 V_4 )
{
int V_5 = ( 1 << F_13 ( V_4 ) ) ;
if ( V_5 > 4 ) {
F_14 ( 0 , L_5 ,
V_5 , ( unsigned int ) F_13 ( V_4 ) , V_4 ) ;
return - V_3 ;
}
return V_5 ;
}
static inline int F_15 ( T_1 V_4 )
{
int V_6 = ( F_16 ( V_4 ) + 12 ) ;
if ( V_6 < 13 || V_6 > 18 ) {
F_14 ( 0 , L_6 ,
V_6 , ( unsigned int ) F_16 ( V_4 ) , V_4 ) ;
return - V_3 ;
}
return 1 << V_6 ;
}
static inline int F_17 ( T_1 V_4 )
{
int V_7 = ( F_18 ( V_4 ) + 10 ) ;
if ( V_7 > 12 ) {
F_14 ( 0 , L_7 ,
V_7 , ( unsigned int ) F_18 ( V_4 ) , V_4 ) ;
return - V_3 ;
}
return 1 << V_7 ;
}
static struct V_8 * F_19 ( T_2 V_9 )
{
struct V_8 * V_8 ;
F_20 (sbridge_dev, &sbridge_edac_list, list) {
if ( V_8 -> V_9 == V_9 )
return V_8 ;
}
return NULL ;
}
static struct V_8 * F_21 ( T_2 V_9 ,
const struct V_10 * V_11 )
{
struct V_8 * V_8 ;
V_8 = F_22 ( sizeof( * V_8 ) , V_12 ) ;
if ( ! V_8 )
return NULL ;
V_8 -> V_13 = F_22 ( sizeof( * V_8 -> V_13 ) * V_11 -> V_14 ,
V_12 ) ;
if ( ! V_8 -> V_13 ) {
F_23 ( V_8 ) ;
return NULL ;
}
V_8 -> V_9 = V_9 ;
V_8 -> V_14 = V_11 -> V_14 ;
F_24 ( & V_8 -> V_15 , & V_16 ) ;
return V_8 ;
}
static void F_25 ( struct V_8 * V_8 )
{
F_26 ( & V_8 -> V_15 ) ;
F_23 ( V_8 -> V_13 ) ;
F_23 ( V_8 ) ;
}
static struct V_17 * F_27 ( T_2 V_9 , unsigned V_18 ,
unsigned V_19 )
{
struct V_8 * V_8 = F_19 ( V_9 ) ;
int V_20 ;
if ( ! V_8 )
return NULL ;
for ( V_20 = 0 ; V_20 < V_8 -> V_14 ; V_20 ++ ) {
if ( ! V_8 -> V_13 [ V_20 ] )
continue;
if ( F_28 ( V_8 -> V_13 [ V_20 ] -> V_21 ) == V_18 &&
F_29 ( V_8 -> V_13 [ V_20 ] -> V_21 ) == V_19 ) {
F_14 ( 1 , L_8 ,
V_9 , V_18 , V_19 , V_8 -> V_13 [ V_20 ] ) ;
return V_8 -> V_13 [ V_20 ] ;
}
}
return NULL ;
}
static int F_30 ( const T_2 V_9 )
{
struct V_17 * V_13 = NULL ;
T_1 V_22 ;
V_13 = F_27 ( V_9 , 15 , 0 ) ;
if ( ! V_13 ) {
F_31 ( V_23 , L_9
L_10 ,
V_9 , 15 , 0 ) ;
return - V_24 ;
}
F_32 ( V_13 , V_25 , & V_22 ) ;
if ( ! F_33 ( V_22 ) ) {
F_31 ( V_23 , L_11 ) ;
return - V_24 ;
}
return 0 ;
}
static int F_34 ( struct V_26 * V_27 )
{
struct V_28 * V_29 = V_27 -> V_30 ;
struct V_31 * V_32 ;
unsigned V_20 , V_33 , V_34 , V_5 , V_6 , V_7 , V_35 ;
T_3 V_36 ;
T_1 V_1 ;
enum V_37 V_38 ;
enum V_39 V_40 ;
F_32 ( V_29 -> V_41 , V_42 , & V_1 ) ;
V_29 -> V_8 -> V_43 = F_35 ( V_1 ) ;
F_32 ( V_29 -> V_41 , V_44 , & V_1 ) ;
V_29 -> V_8 -> V_45 = F_36 ( V_1 ) ;
F_14 ( 0 , L_12 ,
V_29 -> V_8 -> V_46 ,
V_29 -> V_8 -> V_45 ,
V_29 -> V_8 -> V_43 ) ;
F_32 ( V_29 -> V_47 , V_48 , & V_1 ) ;
if ( F_37 ( V_1 ) ) {
F_14 ( 0 , L_13 ) ;
V_29 -> V_49 = true ;
} else {
F_14 ( 0 , L_14 ) ;
V_29 -> V_49 = false ;
}
F_32 ( V_29 -> V_50 , V_25 , & V_29 -> V_51 . V_22 ) ;
if ( F_38 ( V_29 -> V_51 . V_22 ) ) {
F_14 ( 0 , L_15 ) ;
V_38 = V_52 ;
V_29 -> V_53 = true ;
} else {
F_14 ( 0 , L_16 ) ;
V_38 = V_54 ;
V_29 -> V_53 = false ;
}
if ( F_39 ( V_29 -> V_51 . V_22 ) ) {
F_14 ( 0 , L_17 ) ;
V_29 -> V_55 = true ;
} else {
F_14 ( 0 , L_18 ) ;
V_29 -> V_55 = false ;
}
F_32 ( V_29 -> V_56 , V_57 , & V_1 ) ;
if ( F_40 ( V_1 ) ) {
F_14 ( 0 , L_19 ) ;
V_40 = V_58 ;
} else {
F_14 ( 0 , L_20 ) ;
V_40 = V_59 ;
}
V_34 = 8 ;
for ( V_20 = 0 ; V_20 < V_60 ; V_20 ++ ) {
T_1 V_4 ;
for ( V_33 = 0 ; V_33 < F_41 ( V_61 ) ; V_33 ++ ) {
V_32 = F_42 ( V_27 -> V_62 , V_27 -> V_63 , V_27 -> V_64 ,
V_20 , V_33 , 0 ) ;
F_32 ( V_29 -> V_65 [ V_20 ] ,
V_61 [ V_33 ] , & V_4 ) ;
F_14 ( 4 , L_21 , V_20 , V_33 , V_4 ) ;
if ( F_43 ( V_4 ) ) {
V_29 -> V_66 [ V_20 ] . V_63 ++ ;
V_5 = F_12 ( V_4 ) ;
V_6 = F_15 ( V_4 ) ;
V_7 = F_17 ( V_4 ) ;
V_36 = ( ( T_3 ) V_6 * V_7 * V_34 * V_5 ) >> ( 20 - 3 ) ;
V_35 = F_44 ( V_36 ) ;
F_14 ( 0 , L_22 ,
V_29 -> V_8 -> V_46 , V_20 , V_33 ,
V_36 , V_35 ,
V_34 , V_5 , V_6 , V_7 ) ;
V_32 -> V_67 = V_35 ;
V_32 -> V_68 = 32 ;
V_32 -> V_69 = ( V_34 == 8 ) ? V_70 : V_71 ;
V_32 -> V_40 = V_40 ;
V_32 -> V_72 = V_38 ;
snprintf ( V_32 -> V_73 , sizeof( V_32 -> V_73 ) ,
L_23 ,
V_29 -> V_8 -> V_43 , V_20 , V_33 ) ;
}
}
}
return 0 ;
}
static void F_45 ( const struct V_26 * V_27 )
{
struct V_28 * V_29 = V_27 -> V_30 ;
int V_20 , V_33 , V_74 , V_75 , V_76 , V_77 ;
T_1 V_1 ;
T_3 V_78 , V_79 = 0 ;
T_3 V_80 ;
T_1 V_81 , V_82 ;
T_1 V_83 ;
F_32 ( V_29 -> V_84 , V_85 ,
& V_1 ) ;
V_29 -> V_86 = F_46 ( V_1 ) ;
V_80 = ( 1 + V_29 -> V_86 ) >> 20 ;
V_81 = F_47 ( V_80 , 1000 , & V_82 ) ;
F_14 ( 0 , L_24 , V_81 , V_82 , ( T_3 ) V_29 -> V_86 ) ;
F_32 ( V_29 -> V_84 , V_87 ,
& V_1 ) ;
V_29 -> V_88 = F_48 ( V_1 ) ;
V_80 = ( 1 + V_29 -> V_88 ) >> 20 ;
V_81 = F_47 ( V_80 , 1000 , & V_82 ) ;
F_14 ( 0 , L_25 , V_81 , V_82 , ( T_3 ) V_29 -> V_88 ) ;
V_79 = 0 ;
for ( V_75 = 0 ; V_75 < V_89 ; V_75 ++ ) {
F_32 ( V_29 -> V_90 , V_91 [ V_75 ] ,
& V_1 ) ;
V_78 = F_49 ( V_1 ) ;
if ( ! F_50 ( V_1 ) )
continue;
if ( V_78 <= V_79 )
break;
V_80 = ( V_78 + 1 ) >> 20 ;
V_81 = F_47 ( V_80 , 1000 , & V_82 ) ;
F_14 ( 0 , L_26 ,
V_75 ,
F_1 ( V_1 ) ,
V_81 , V_82 ,
( ( T_3 ) V_80 ) << 20L ,
F_51 ( V_1 ) ? L_27 : L_28 ,
V_1 ) ;
V_79 = V_78 ;
F_32 ( V_29 -> V_90 , V_92 [ V_75 ] ,
& V_1 ) ;
V_77 = F_3 ( V_1 , 0 ) ;
for ( V_33 = 0 ; V_33 < 8 ; V_33 ++ ) {
if ( V_33 > 0 && V_77 == F_3 ( V_1 , V_33 ) )
break;
F_14 ( 0 , L_29 ,
V_75 , V_33 , F_3 ( V_1 , V_33 ) ) ;
}
}
V_79 = 0 ;
for ( V_76 = 0 ; V_76 < V_93 ; V_76 ++ ) {
F_32 ( V_29 -> V_94 , V_95 [ V_76 ] ,
& V_1 ) ;
V_78 = F_52 ( V_1 ) ;
if ( V_78 <= V_79 )
break;
V_80 = ( V_78 + 1 ) >> 20 ;
V_81 = F_47 ( V_80 , 1000 , & V_82 ) ;
F_14 ( 0 , L_30 ,
V_76 , V_81 , V_82 ,
( ( T_3 ) V_80 ) << 20L ,
( T_1 ) F_53 ( V_1 ) ,
( T_1 ) F_54 ( V_1 ) ,
( T_1 ) F_55 ( V_1 ) ,
( T_1 ) F_56 ( V_1 ) ,
( T_1 ) F_57 ( V_1 ) ,
( T_1 ) F_58 ( V_1 ) ,
V_1 ) ;
V_79 = V_78 ;
}
for ( V_20 = 0 ; V_20 < V_60 ; V_20 ++ ) {
if ( ! V_29 -> V_66 [ V_20 ] . V_63 )
continue;
for ( V_33 = 0 ; V_33 < V_76 ; V_33 ++ ) {
F_32 ( V_29 -> V_65 [ V_20 ] ,
V_96 [ V_33 ] ,
& V_1 ) ;
V_80 = F_59 ( V_1 ) >> 20 ;
V_81 = F_47 ( V_80 , 1000 , & V_82 ) ;
F_14 ( 0 , L_31 ,
V_20 , V_33 ,
V_81 , V_82 ,
( ( T_3 ) V_80 ) << 20L ,
V_1 ) ;
}
}
for ( V_20 = 0 ; V_20 < V_60 ; V_20 ++ ) {
if ( ! V_29 -> V_66 [ V_20 ] . V_63 )
continue;
for ( V_33 = 0 ; V_33 < V_97 ; V_33 ++ ) {
F_32 ( V_29 -> V_65 [ V_20 ] ,
V_98 [ V_33 ] ,
& V_1 ) ;
if ( ! F_60 ( V_1 ) )
continue;
V_80 = F_61 ( V_1 ) >> 20 ;
V_83 = 1 << F_62 ( V_1 ) ;
V_81 = F_47 ( V_80 , 1000 , & V_82 ) ;
F_14 ( 0 , L_32 ,
V_20 , V_33 ,
V_81 , V_82 ,
( ( T_3 ) V_80 ) << 20L ,
V_83 ,
V_1 ) ;
for ( V_74 = 0 ; V_74 < V_83 ; V_74 ++ ) {
F_32 ( V_29 -> V_65 [ V_20 ] ,
V_99 [ V_33 ] [ V_74 ] ,
& V_1 ) ;
V_80 = F_63 ( V_1 ) << 6 ;
V_81 = F_47 ( V_80 , 1000 , & V_82 ) ;
F_14 ( 0 , L_33 ,
V_20 , V_33 , V_74 ,
V_81 , V_82 ,
( ( T_3 ) V_80 ) << 20L ,
( T_1 ) F_64 ( V_1 ) ,
V_1 ) ;
}
}
}
}
struct V_26 * F_65 ( T_2 V_45 )
{
struct V_8 * V_8 ;
F_20 (sbridge_dev, &sbridge_edac_list, list) {
if ( V_8 -> V_45 == V_45 )
return V_8 -> V_27 ;
}
return NULL ;
}
static int F_66 ( struct V_26 * V_27 ,
T_3 V_100 ,
T_2 * V_101 ,
long * V_102 ,
T_2 * V_103 ,
char * * V_104 , char * V_105 )
{
struct V_26 * V_106 ;
struct V_28 * V_29 = V_27 -> V_30 ;
int V_107 , V_75 , V_76 , V_108 , V_109 ;
int V_77 , V_110 , V_111 ;
int V_112 ;
unsigned V_113 [ V_114 ] ;
T_1 V_1 ;
T_2 V_115 , V_116 ;
T_1 V_117 ;
T_1 V_83 ;
T_1 V_81 , V_82 ;
T_3 V_118 , V_119 , V_78 , V_79 = 0 ;
if ( ( V_100 > ( T_3 ) V_29 -> V_86 ) && ( V_100 < ( 1LL << 32 ) ) ) {
sprintf ( V_105 , L_34 , V_100 ) ;
return - V_3 ;
}
if ( V_100 >= ( T_3 ) V_29 -> V_88 ) {
sprintf ( V_105 , L_35 , V_100 ) ;
return - V_3 ;
}
for ( V_75 = 0 ; V_75 < V_89 ; V_75 ++ ) {
F_32 ( V_29 -> V_90 , V_91 [ V_75 ] ,
& V_1 ) ;
if ( ! F_50 ( V_1 ) )
continue;
V_78 = F_49 ( V_1 ) ;
if ( V_78 <= V_79 ) {
sprintf ( V_105 , L_36 ) ;
return - V_3 ;
}
if ( V_100 <= V_78 )
break;
V_79 = V_78 ;
}
if ( V_75 == V_89 ) {
sprintf ( V_105 , L_36 ) ;
return - V_3 ;
}
* V_104 = F_1 ( V_1 ) ;
V_112 = F_51 ( V_1 ) ;
F_32 ( V_29 -> V_90 , V_92 [ V_75 ] ,
& V_1 ) ;
V_77 = F_3 ( V_1 , 0 ) ;
for ( V_108 = 0 ; V_108 < 8 ; V_108 ++ ) {
if ( V_108 > 0 && V_77 == F_3 ( V_1 , V_108 ) )
break;
V_113 [ V_108 ] = F_3 ( V_1 , V_108 ) ;
F_14 ( 0 , L_37 ,
V_108 , V_113 [ V_108 ] ) ;
}
F_14 ( 0 , L_38 ,
V_29 -> V_8 -> V_46 ,
V_75 ,
V_100 ,
V_78 ,
V_108 + 7 ,
V_112 ? L_39 : L_40 ) ;
if ( V_112 )
V_110 = ( ( V_100 >> 6 ) ^ ( V_100 >> 16 ) ) & 7 ;
else
V_110 = ( V_100 >> 6 ) & 7 ;
switch ( V_108 ) {
case 1 :
V_110 = 0 ;
break;
case 2 :
V_110 = V_110 & 1 ;
break;
case 4 :
V_110 = V_110 & 3 ;
break;
case 8 :
break;
default:
sprintf ( V_105 , L_41 ) ;
return - V_3 ;
}
* V_101 = V_113 [ V_110 ] ;
F_14 ( 0 , L_42 ,
V_110 , V_108 , * V_101 ) ;
V_106 = F_65 ( * V_101 ) ;
if ( ! V_106 ) {
sprintf ( V_105 , L_43 ,
* V_101 ) ;
return - V_3 ;
}
V_27 = V_106 ;
V_29 = V_27 -> V_30 ;
V_79 = 0 ;
for ( V_76 = 0 ; V_76 < V_93 ; V_76 ++ ) {
F_32 ( V_29 -> V_94 , V_95 [ V_76 ] ,
& V_1 ) ;
V_78 = F_52 ( V_1 ) ;
if ( V_78 <= V_79 ) {
sprintf ( V_105 , L_44 ) ;
return - V_3 ;
}
if ( V_100 <= V_78 )
break;
V_79 = V_78 ;
}
V_115 = F_54 ( V_1 ) + 1 ;
V_116 = F_53 ( V_1 ) + 1 ;
F_32 ( V_29 -> V_65 [ 0 ] ,
V_96 [ V_76 ] ,
& V_117 ) ;
if ( V_115 == 3 )
V_110 = V_100 >> 6 ;
else
V_110 = V_100 >> ( 6 + V_116 ) ;
V_110 = V_110 % V_115 ;
switch ( V_110 ) {
case 0 :
V_111 = F_55 ( V_1 ) ;
break;
case 1 :
V_111 = F_56 ( V_1 ) ;
break;
case 2 :
V_111 = F_57 ( V_1 ) ;
break;
case 3 :
V_111 = F_58 ( V_1 ) ;
break;
default:
sprintf ( V_105 , L_45 ) ;
return - V_3 ;
}
* V_102 = 1 << V_111 ;
if ( V_29 -> V_49 ) {
* V_102 |= 1 << ( ( V_111 + 2 ) % 4 ) ;
switch( V_115 ) {
case 2 :
case 4 :
V_109 = 1 << V_116 * ( V_115 >> 1 ) ;
break;
default:
sprintf ( V_105 , L_46 ) ;
return - V_3 ;
}
} else
V_109 = ( 1 << V_116 ) * V_115 ;
if ( V_29 -> V_53 )
* V_102 |= 1 << ( ( V_111 + 1 ) % 4 ) ;
V_119 = F_59 ( V_117 ) ;
F_14 ( 0 , L_47 ,
V_76 ,
V_100 ,
V_78 ,
( T_1 ) F_53 ( V_1 ) ,
V_115 ,
V_119 ,
V_110 ,
V_111 ,
* V_102 ) ;
if ( V_119 > V_100 ) {
sprintf ( V_105 , L_48 ,
V_119 , V_100 ) ;
return - V_3 ;
}
V_100 -= V_119 ;
V_118 = V_100 & 0x7f ;
V_100 >>= 6 ;
V_100 = F_67 ( V_100 , V_109 ) ;
#if 0
addr = addr / ch_way;
#endif
V_118 |= V_100 << 6 ;
for ( V_107 = 0 ; V_107 < V_97 ; V_107 ++ ) {
F_32 ( V_29 -> V_65 [ V_111 ] ,
V_98 [ V_107 ] ,
& V_1 ) ;
if ( ! F_60 ( V_1 ) )
continue;
V_78 = F_61 ( V_1 ) ;
V_81 = F_47 ( V_78 >> 20 , 1000 , & V_82 ) ;
F_14 ( 0 , L_49 ,
V_107 ,
V_81 , V_82 ,
V_78 ,
1 << F_62 ( V_1 ) ) ;
if ( V_118 <= V_78 )
break;
}
if ( V_107 == V_97 ) {
sprintf ( V_105 , L_50 ,
V_118 ) ;
return - V_3 ;
}
V_83 = F_62 ( V_1 ) ;
if ( V_29 -> V_55 )
V_110 = ( V_118 >> 6 ) ;
else
V_110 = ( V_118 >> 13 ) ;
V_110 %= 1 << V_83 ;
F_32 ( V_29 -> V_65 [ V_111 ] ,
V_99 [ V_107 ] [ V_110 ] ,
& V_1 ) ;
* V_103 = F_64 ( V_1 ) ;
F_14 ( 0 , L_51 ,
V_107 ,
V_118 ,
V_78 ,
V_83 ,
V_110 ) ;
return 0 ;
}
static void F_68 ( struct V_8 * V_8 )
{
int V_20 ;
F_14 ( 0 , L_52 ) ;
for ( V_20 = 0 ; V_20 < V_8 -> V_14 ; V_20 ++ ) {
struct V_17 * V_13 = V_8 -> V_13 [ V_20 ] ;
if ( ! V_13 )
continue;
F_14 ( 0 , L_53 ,
V_13 -> V_9 -> V_120 ,
F_28 ( V_13 -> V_21 ) , F_29 ( V_13 -> V_21 ) ) ;
F_69 ( V_13 ) ;
}
}
static void F_70 ( void )
{
struct V_8 * V_8 , * V_121 ;
F_71 (sbridge_dev, tmp, &sbridge_edac_list, list) {
F_68 ( V_8 ) ;
F_25 ( V_8 ) ;
}
}
static int F_72 ( struct V_17 * * V_122 ,
T_2 * V_123 ,
const struct V_10 * V_11 ,
const unsigned V_124 )
{
struct V_8 * V_8 ;
const struct V_125 * V_126 = & V_11 -> V_127 [ V_124 ] ;
struct V_17 * V_13 = NULL ;
T_2 V_9 = 0 ;
F_31 ( V_128 ,
L_54 ,
V_126 -> V_129 , V_126 -> V_19 ,
V_130 , V_126 -> V_131 ) ;
V_13 = F_73 ( V_130 ,
V_126 -> V_131 , * V_122 ) ;
if ( ! V_13 ) {
if ( * V_122 ) {
* V_122 = V_13 ;
return 0 ;
}
if ( V_126 -> V_132 )
return 0 ;
if ( V_124 == 0 )
return - V_24 ;
F_31 ( V_128 ,
L_55 ,
V_126 -> V_129 , V_126 -> V_19 ,
V_130 , V_126 -> V_131 ) ;
return - V_24 ;
}
V_9 = V_13 -> V_9 -> V_120 ;
V_8 = F_19 ( V_9 ) ;
if ( ! V_8 ) {
V_8 = F_21 ( V_9 , V_11 ) ;
if ( ! V_8 ) {
F_69 ( V_13 ) ;
return - V_133 ;
}
( * V_123 ) ++ ;
}
if ( V_8 -> V_13 [ V_124 ] ) {
F_31 ( V_23 ,
L_56
L_57 ,
V_9 , V_126 -> V_129 , V_126 -> V_19 ,
V_130 , V_126 -> V_131 ) ;
F_69 ( V_13 ) ;
return - V_24 ;
}
V_8 -> V_13 [ V_124 ] = V_13 ;
if ( F_74 ( F_28 ( V_13 -> V_21 ) != V_126 -> V_129 ||
F_29 ( V_13 -> V_21 ) != V_126 -> V_19 ) ) {
F_31 ( V_23 ,
L_58
L_59 ,
V_130 , V_126 -> V_131 ,
V_9 , F_28 ( V_13 -> V_21 ) , F_29 ( V_13 -> V_21 ) ,
V_9 , V_126 -> V_129 , V_126 -> V_19 ) ;
return - V_24 ;
}
if ( F_74 ( F_75 ( V_13 ) < 0 ) ) {
F_31 ( V_23 ,
L_60
L_57 ,
V_9 , V_126 -> V_129 , V_126 -> V_19 ,
V_130 , V_126 -> V_131 ) ;
return - V_24 ;
}
F_14 ( 0 , L_61 ,
V_9 , V_126 -> V_129 , V_126 -> V_19 ,
V_130 , V_126 -> V_131 ) ;
F_76 ( V_13 ) ;
* V_122 = V_13 ;
return 0 ;
}
static int F_77 ( T_2 * V_123 )
{
int V_20 , V_134 ;
struct V_17 * V_13 = NULL ;
const struct V_10 * V_11 = V_135 ;
while ( V_11 && V_11 -> V_127 ) {
for ( V_20 = 0 ; V_20 < V_11 -> V_14 ; V_20 ++ ) {
V_13 = NULL ;
do {
V_134 = F_72 ( & V_13 , V_123 ,
V_11 , V_20 ) ;
if ( V_134 < 0 ) {
if ( V_20 == 0 ) {
V_20 = V_11 -> V_14 ;
break;
}
F_70 () ;
return - V_24 ;
}
} while ( V_13 );
}
V_11 ++ ;
}
return 0 ;
}
static int F_78 ( struct V_26 * V_27 ,
struct V_8 * V_8 )
{
struct V_28 * V_29 = V_27 -> V_30 ;
struct V_17 * V_13 ;
int V_20 , V_19 , V_18 ;
for ( V_20 = 0 ; V_20 < V_8 -> V_14 ; V_20 ++ ) {
V_13 = V_8 -> V_13 [ V_20 ] ;
if ( ! V_13 )
continue;
V_18 = F_28 ( V_13 -> V_21 ) ;
V_19 = F_29 ( V_13 -> V_21 ) ;
switch ( V_18 ) {
case 12 :
switch ( V_19 ) {
case 6 :
V_29 -> V_90 = V_13 ;
break;
case 7 :
V_29 -> V_84 = V_13 ;
break;
default:
goto error;
}
break;
case 13 :
switch ( V_19 ) {
case 6 :
V_29 -> V_41 = V_13 ;
break;
default:
goto error;
}
break;
case 14 :
switch ( V_19 ) {
case 0 :
V_29 -> V_94 = V_13 ;
break;
default:
goto error;
}
break;
case 15 :
switch ( V_19 ) {
case 0 :
V_29 -> V_50 = V_13 ;
break;
case 1 :
V_29 -> V_47 = V_13 ;
break;
case 2 :
case 3 :
case 4 :
case 5 :
V_29 -> V_65 [ V_19 - 2 ] = V_13 ;
break;
default:
goto error;
}
break;
case 17 :
switch ( V_19 ) {
case 0 :
V_29 -> V_56 = V_13 ;
break;
default:
goto error;
}
break;
default:
goto error;
}
F_14 ( 0 , L_62 ,
V_8 -> V_9 ,
F_28 ( V_13 -> V_21 ) , F_29 ( V_13 -> V_21 ) ,
V_13 ) ;
}
if ( ! V_29 -> V_90 || ! V_29 -> V_84 || ! V_29 -> V_94 ||
! V_29 -> V_65 || ! V_29 -> V_47 || ! V_29 -> V_50 ||
! V_29 -> V_56 )
goto V_136;
for ( V_20 = 0 ; V_20 < V_60 ; V_20 ++ ) {
if ( ! V_29 -> V_65 [ V_20 ] )
goto V_136;
}
return 0 ;
V_136:
F_31 ( V_23 , L_63 ) ;
return - V_24 ;
error:
F_31 ( V_23 , L_64
L_65 ,
V_18 , V_19 ) ;
return - V_3 ;
}
static void F_79 ( struct V_26 * V_27 ,
const struct V_137 * V_138 )
{
struct V_26 * V_106 ;
struct V_28 * V_29 = V_27 -> V_30 ;
enum V_139 V_140 ;
char * type , * V_141 , V_105 [ 256 ] ;
bool V_142 = F_80 ( V_138 -> V_143 , 0 , 0 ) ;
bool V_144 = F_80 ( V_138 -> V_145 , 62 , 62 ) ;
bool V_146 = F_80 ( V_138 -> V_145 , 61 , 61 ) ;
bool V_147 = F_80 ( V_138 -> V_145 , 56 , 56 ) ;
T_1 V_148 = F_80 ( V_138 -> V_145 , 38 , 52 ) ;
T_1 V_149 = F_80 ( V_138 -> V_145 , 16 , 31 ) ;
T_1 V_150 = F_80 ( V_138 -> V_145 , 0 , 15 ) ;
T_1 V_66 = F_80 ( V_138 -> V_145 , 0 , 3 ) ;
T_1 V_151 = F_80 ( V_138 -> V_145 , 4 , 6 ) ;
long V_102 , V_152 ;
T_2 V_103 , V_101 ;
int V_134 , V_32 ;
char * V_104 = NULL ;
if ( V_146 ) {
if ( V_142 ) {
type = L_66 ;
V_140 = V_153 ;
} else {
type = L_67 ;
V_140 = V_154 ;
}
} else {
type = L_68 ;
V_140 = V_155 ;
}
if ( ! ( ( V_150 & 0xef80 ) == 0x80 ) ) {
V_141 = L_69 ;
} else {
switch ( V_151 ) {
case 0 :
V_141 = L_70 ;
break;
case 1 :
V_141 = L_71 ;
break;
case 2 :
V_141 = L_72 ;
break;
case 3 :
V_141 = L_73 ;
break;
case 4 :
V_141 = L_74 ;
break;
default:
V_141 = L_75 ;
break;
}
}
V_134 = F_66 ( V_27 , V_138 -> V_100 , & V_101 ,
& V_102 , & V_103 , & V_104 , V_105 ) ;
if ( V_134 < 0 )
goto V_156;
V_106 = F_65 ( V_101 ) ;
if ( ! V_106 ) {
strcpy ( V_105 , L_76 ) ;
goto V_156;
}
V_27 = V_106 ;
V_29 = V_27 -> V_30 ;
V_152 = F_81 ( & V_102 , V_60 ) ;
if ( V_103 < 4 )
V_32 = 0 ;
else if ( V_103 < 8 )
V_32 = 1 ;
else
V_32 = 2 ;
snprintf ( V_105 , sizeof( V_105 ) ,
L_77 ,
V_144 ? L_78 : L_39 ,
( V_146 && V_147 ) ? L_79 : L_39 ,
V_104 ,
V_149 , V_150 ,
V_101 ,
V_102 ,
V_103 ) ;
F_14 ( 0 , L_80 , V_105 ) ;
F_82 ( V_140 , V_27 , V_148 ,
V_138 -> V_100 >> V_157 , V_138 -> V_100 & ~ V_158 , 0 ,
V_66 , V_32 , - 1 ,
V_141 , V_105 ) ;
return;
V_156:
F_82 ( V_140 , V_27 , V_148 , 0 , 0 , 0 ,
- 1 , - 1 , - 1 ,
V_105 , L_39 ) ;
}
static void F_83 ( struct V_26 * V_27 )
{
struct V_28 * V_29 = V_27 -> V_30 ;
int V_20 ;
unsigned V_159 = 0 ;
struct V_137 * V_138 ;
F_84 () ;
V_159 = ( V_29 -> V_160 + V_161 - V_29 -> V_162 )
% V_161 ;
if ( ! V_159 )
return;
V_138 = V_29 -> V_163 ;
if ( V_29 -> V_162 + V_159 > V_161 ) {
unsigned V_164 = V_161 - V_29 -> V_162 ;
memcpy ( V_138 , & V_29 -> V_165 [ V_29 -> V_162 ] , sizeof( * V_138 ) * V_164 ) ;
F_85 () ;
V_29 -> V_162 = 0 ;
V_159 -= V_164 ;
V_138 += V_164 ;
}
memcpy ( V_138 , & V_29 -> V_165 [ V_29 -> V_162 ] , sizeof( * V_138 ) * V_159 ) ;
F_85 () ;
V_29 -> V_162 += V_159 ;
F_84 () ;
if ( V_29 -> V_166 ) {
F_31 ( V_23 , L_81 ,
V_29 -> V_166 ) ;
F_85 () ;
V_29 -> V_166 = 0 ;
}
for ( V_20 = 0 ; V_20 < V_159 ; V_20 ++ )
F_79 ( V_27 , & V_29 -> V_163 [ V_20 ] ) ;
}
static int F_86 ( struct V_167 * V_168 , unsigned long V_169 ,
void * V_170 )
{
struct V_137 * V_137 = (struct V_137 * ) V_170 ;
struct V_26 * V_27 ;
struct V_28 * V_29 ;
V_27 = F_65 ( V_137 -> V_171 ) ;
if ( ! V_27 )
return V_172 ;
V_29 = V_27 -> V_30 ;
if ( ( V_137 -> V_145 & 0xefff ) >> 7 != 1 )
return V_173 ;
F_87 ( L_82 ) ;
F_87 ( L_83 ,
V_137 -> V_174 , V_137 -> V_143 , V_137 -> V_175 , V_137 -> V_145 ) ;
F_87 ( L_84 , V_137 -> V_176 ) ;
F_87 ( L_85 , V_137 -> V_100 ) ;
F_87 ( L_86 , V_137 -> V_177 ) ;
F_87 ( L_87 ,
V_137 -> V_178 , V_137 -> V_179 , V_137 -> time ,
V_137 -> V_171 , V_137 -> V_180 ) ;
if ( F_88 ( V_137 -> V_181 ) . V_182 != V_29 -> V_8 -> V_46 )
return V_173 ;
F_84 () ;
if ( ( V_29 -> V_160 + 1 ) % V_161 == V_29 -> V_162 ) {
F_85 () ;
V_29 -> V_166 ++ ;
return V_173 ;
}
memcpy ( & V_29 -> V_165 [ V_29 -> V_160 ] , V_137 , sizeof( * V_137 ) ) ;
F_85 () ;
V_29 -> V_160 = ( V_29 -> V_160 + 1 ) % V_161 ;
if ( V_137 -> V_143 & 1 )
F_83 ( V_27 ) ;
return V_183 ;
}
static void F_89 ( struct V_8 * V_8 )
{
struct V_26 * V_27 = V_8 -> V_27 ;
struct V_28 * V_29 ;
if ( F_74 ( ! V_27 || ! V_27 -> V_30 ) ) {
F_14 ( 0 , L_88 , & V_8 -> V_13 [ 0 ] -> V_129 ) ;
F_31 ( V_23 , L_89 ) ;
return;
}
V_29 = V_27 -> V_30 ;
F_14 ( 0 , L_90 ,
V_27 , & V_8 -> V_13 [ 0 ] -> V_129 ) ;
F_90 ( V_27 -> V_13 ) ;
F_14 ( 1 , L_91 , V_27 -> V_184 ) ;
F_23 ( V_27 -> V_184 ) ;
F_91 ( V_27 ) ;
V_8 -> V_27 = NULL ;
}
static int F_92 ( struct V_8 * V_8 )
{
struct V_26 * V_27 ;
struct V_185 V_62 [ 2 ] ;
struct V_28 * V_29 ;
int V_134 ;
V_134 = F_30 ( V_8 -> V_9 ) ;
if ( F_74 ( V_134 < 0 ) )
return V_134 ;
V_62 [ 0 ] . type = V_186 ;
V_62 [ 0 ] . V_36 = V_60 ;
V_62 [ 0 ] . V_187 = false ;
V_62 [ 1 ] . type = V_188 ;
V_62 [ 1 ] . V_36 = V_189 ;
V_62 [ 1 ] . V_187 = true ;
V_27 = F_93 ( V_8 -> V_46 , F_41 ( V_62 ) , V_62 ,
sizeof( * V_29 ) ) ;
if ( F_74 ( ! V_27 ) )
return - V_133 ;
F_14 ( 0 , L_90 ,
V_27 , & V_8 -> V_13 [ 0 ] -> V_129 ) ;
V_29 = V_27 -> V_30 ;
memset ( V_29 , 0 , sizeof( * V_29 ) ) ;
V_29 -> V_8 = V_8 ;
V_8 -> V_27 = V_27 ;
V_27 -> V_190 = V_191 ;
V_27 -> V_192 = V_193 ;
V_27 -> V_194 = V_193 ;
V_27 -> V_195 = L_92 ;
V_27 -> V_196 = V_197 ;
V_27 -> V_184 = F_94 ( V_12 , L_93 , V_27 -> V_198 ) ;
V_27 -> V_199 = F_95 ( V_8 -> V_13 [ 0 ] ) ;
V_27 -> V_200 = NULL ;
V_27 -> V_201 = F_83 ;
V_134 = F_78 ( V_27 , V_8 ) ;
if ( F_74 ( V_134 < 0 ) )
goto V_202;
F_34 ( V_27 ) ;
F_45 ( V_27 ) ;
V_27 -> V_13 = & V_8 -> V_13 [ 0 ] -> V_129 ;
if ( F_74 ( F_96 ( V_27 ) ) ) {
F_14 ( 0 , L_94 ) ;
V_134 = - V_3 ;
goto V_202;
}
return 0 ;
V_202:
F_23 ( V_27 -> V_184 ) ;
F_91 ( V_27 ) ;
V_8 -> V_27 = NULL ;
return V_134 ;
}
static int T_4 F_97 ( struct V_17 * V_13 ,
const struct V_203 * V_204 )
{
int V_134 ;
T_2 V_46 , V_123 = 0 ;
struct V_8 * V_8 ;
F_98 ( & V_205 ) ;
if ( F_74 ( V_206 >= 1 ) ) {
F_99 ( & V_205 ) ;
return - V_24 ;
}
V_206 ++ ;
V_134 = F_77 ( & V_123 ) ;
if ( F_74 ( V_134 < 0 ) )
goto V_202;
V_46 = 0 ;
F_20 (sbridge_dev, &sbridge_edac_list, list) {
F_14 ( 0 , L_95 ,
V_46 , V_46 + 1 , V_123 ) ;
V_8 -> V_46 = V_46 ++ ;
V_134 = F_92 ( V_8 ) ;
if ( F_74 ( V_134 < 0 ) )
goto V_207;
}
F_31 ( V_128 , L_96 ) ;
F_99 ( & V_205 ) ;
return 0 ;
V_207:
F_20 (sbridge_dev, &sbridge_edac_list, list)
F_89 ( V_8 ) ;
F_70 () ;
V_202:
F_99 ( & V_205 ) ;
return V_134 ;
}
static void T_5 F_100 ( struct V_17 * V_13 )
{
struct V_8 * V_8 ;
F_14 ( 0 , L_52 ) ;
F_98 ( & V_205 ) ;
if ( F_74 ( ! V_206 ) ) {
F_99 ( & V_205 ) ;
return;
}
F_20 (sbridge_dev, &sbridge_edac_list, list)
F_89 ( V_8 ) ;
F_70 () ;
V_206 -- ;
F_99 ( & V_205 ) ;
}
static int T_6 F_101 ( void )
{
int V_208 ;
F_14 ( 2 , L_52 ) ;
F_102 () ;
V_208 = F_103 ( & V_209 ) ;
if ( V_208 >= 0 ) {
F_104 ( & V_210 ) ;
return 0 ;
}
F_31 ( V_23 , L_97 ,
V_208 ) ;
return V_208 ;
}
static void T_7 F_105 ( void )
{
F_14 ( 2 , L_52 ) ;
F_106 ( & V_209 ) ;
F_107 ( & V_210 ) ;
}
