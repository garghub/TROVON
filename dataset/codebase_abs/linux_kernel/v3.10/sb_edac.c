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
if ( V_29 -> V_56 ) {
F_32 ( V_29 -> V_56 , V_57 , & V_1 ) ;
if ( F_40 ( V_1 ) ) {
F_14 ( 0 , L_19 ) ;
V_40 = V_58 ;
} else {
F_14 ( 0 , L_20 ) ;
V_40 = V_59 ;
}
} else {
F_14 ( 0 , L_21 ) ;
V_40 = V_60 ;
}
V_34 = 8 ;
for ( V_20 = 0 ; V_20 < V_61 ; V_20 ++ ) {
T_1 V_4 ;
for ( V_33 = 0 ; V_33 < F_41 ( V_62 ) ; V_33 ++ ) {
V_32 = F_42 ( V_27 -> V_63 , V_27 -> V_64 , V_27 -> V_65 ,
V_20 , V_33 , 0 ) ;
F_32 ( V_29 -> V_66 [ V_20 ] ,
V_62 [ V_33 ] , & V_4 ) ;
F_14 ( 4 , L_22 , V_20 , V_33 , V_4 ) ;
if ( F_43 ( V_4 ) ) {
V_29 -> V_67 [ V_20 ] . V_64 ++ ;
V_5 = F_12 ( V_4 ) ;
V_6 = F_15 ( V_4 ) ;
V_7 = F_17 ( V_4 ) ;
V_36 = ( ( T_3 ) V_6 * V_7 * V_34 * V_5 ) >> ( 20 - 3 ) ;
V_35 = F_44 ( V_36 ) ;
F_14 ( 0 , L_23 ,
V_29 -> V_8 -> V_46 , V_20 , V_33 ,
V_36 , V_35 ,
V_34 , V_5 , V_6 , V_7 ) ;
V_32 -> V_68 = V_35 ;
V_32 -> V_69 = 32 ;
V_32 -> V_70 = ( V_34 == 8 ) ? V_71 : V_72 ;
V_32 -> V_40 = V_40 ;
V_32 -> V_73 = V_38 ;
snprintf ( V_32 -> V_74 , sizeof( V_32 -> V_74 ) ,
L_24 ,
V_29 -> V_8 -> V_43 , V_20 , V_33 ) ;
}
}
}
return 0 ;
}
static void F_45 ( const struct V_26 * V_27 )
{
struct V_28 * V_29 = V_27 -> V_30 ;
int V_20 , V_33 , V_75 , V_76 , V_77 , V_78 ;
T_1 V_1 ;
T_3 V_79 , V_80 = 0 ;
T_3 V_81 ;
T_1 V_82 , V_83 ;
T_1 V_84 ;
F_32 ( V_29 -> V_85 , V_86 ,
& V_1 ) ;
V_29 -> V_87 = F_46 ( V_1 ) ;
V_81 = ( 1 + V_29 -> V_87 ) >> 20 ;
V_82 = F_47 ( V_81 , 1000 , & V_83 ) ;
F_14 ( 0 , L_25 , V_82 , V_83 , ( T_3 ) V_29 -> V_87 ) ;
F_32 ( V_29 -> V_85 , V_88 ,
& V_1 ) ;
V_29 -> V_89 = F_48 ( V_1 ) ;
V_81 = ( 1 + V_29 -> V_89 ) >> 20 ;
V_82 = F_47 ( V_81 , 1000 , & V_83 ) ;
F_14 ( 0 , L_26 , V_82 , V_83 , ( T_3 ) V_29 -> V_89 ) ;
V_80 = 0 ;
for ( V_76 = 0 ; V_76 < V_90 ; V_76 ++ ) {
F_32 ( V_29 -> V_91 , V_92 [ V_76 ] ,
& V_1 ) ;
V_79 = F_49 ( V_1 ) ;
if ( ! F_50 ( V_1 ) )
continue;
if ( V_79 <= V_80 )
break;
V_81 = ( V_79 + 1 ) >> 20 ;
V_82 = F_47 ( V_81 , 1000 , & V_83 ) ;
F_14 ( 0 , L_27 ,
V_76 ,
F_1 ( V_1 ) ,
V_82 , V_83 ,
( ( T_3 ) V_81 ) << 20L ,
F_51 ( V_1 ) ? L_28 : L_29 ,
V_1 ) ;
V_80 = V_79 ;
F_32 ( V_29 -> V_91 , V_93 [ V_76 ] ,
& V_1 ) ;
V_78 = F_3 ( V_1 , 0 ) ;
for ( V_33 = 0 ; V_33 < 8 ; V_33 ++ ) {
if ( V_33 > 0 && V_78 == F_3 ( V_1 , V_33 ) )
break;
F_14 ( 0 , L_30 ,
V_76 , V_33 , F_3 ( V_1 , V_33 ) ) ;
}
}
V_80 = 0 ;
for ( V_77 = 0 ; V_77 < V_94 ; V_77 ++ ) {
F_32 ( V_29 -> V_95 , V_96 [ V_77 ] ,
& V_1 ) ;
V_79 = F_52 ( V_1 ) ;
if ( V_79 <= V_80 )
break;
V_81 = ( V_79 + 1 ) >> 20 ;
V_82 = F_47 ( V_81 , 1000 , & V_83 ) ;
F_14 ( 0 , L_31 ,
V_77 , V_82 , V_83 ,
( ( T_3 ) V_81 ) << 20L ,
( T_1 ) F_53 ( V_1 ) ,
( T_1 ) F_54 ( V_1 ) ,
( T_1 ) F_55 ( V_1 ) ,
( T_1 ) F_56 ( V_1 ) ,
( T_1 ) F_57 ( V_1 ) ,
( T_1 ) F_58 ( V_1 ) ,
V_1 ) ;
V_80 = V_79 ;
}
for ( V_20 = 0 ; V_20 < V_61 ; V_20 ++ ) {
if ( ! V_29 -> V_67 [ V_20 ] . V_64 )
continue;
for ( V_33 = 0 ; V_33 < V_77 ; V_33 ++ ) {
F_32 ( V_29 -> V_66 [ V_20 ] ,
V_97 [ V_33 ] ,
& V_1 ) ;
V_81 = F_59 ( V_1 ) >> 20 ;
V_82 = F_47 ( V_81 , 1000 , & V_83 ) ;
F_14 ( 0 , L_32 ,
V_20 , V_33 ,
V_82 , V_83 ,
( ( T_3 ) V_81 ) << 20L ,
V_1 ) ;
}
}
for ( V_20 = 0 ; V_20 < V_61 ; V_20 ++ ) {
if ( ! V_29 -> V_67 [ V_20 ] . V_64 )
continue;
for ( V_33 = 0 ; V_33 < V_98 ; V_33 ++ ) {
F_32 ( V_29 -> V_66 [ V_20 ] ,
V_99 [ V_33 ] ,
& V_1 ) ;
if ( ! F_60 ( V_1 ) )
continue;
V_81 = F_61 ( V_1 ) >> 20 ;
V_84 = 1 << F_62 ( V_1 ) ;
V_82 = F_47 ( V_81 , 1000 , & V_83 ) ;
F_14 ( 0 , L_33 ,
V_20 , V_33 ,
V_82 , V_83 ,
( ( T_3 ) V_81 ) << 20L ,
V_84 ,
V_1 ) ;
for ( V_75 = 0 ; V_75 < V_84 ; V_75 ++ ) {
F_32 ( V_29 -> V_66 [ V_20 ] ,
V_100 [ V_33 ] [ V_75 ] ,
& V_1 ) ;
V_81 = F_63 ( V_1 ) << 6 ;
V_82 = F_47 ( V_81 , 1000 , & V_83 ) ;
F_14 ( 0 , L_34 ,
V_20 , V_33 , V_75 ,
V_82 , V_83 ,
( ( T_3 ) V_81 ) << 20L ,
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
T_3 V_101 ,
T_2 * V_102 ,
long * V_103 ,
T_2 * V_104 ,
char * * V_105 , char * V_106 )
{
struct V_26 * V_107 ;
struct V_28 * V_29 = V_27 -> V_30 ;
int V_108 , V_76 , V_77 , V_109 , V_110 ;
int V_78 , V_111 , V_112 ;
int V_113 ;
unsigned V_114 [ V_115 ] ;
T_1 V_1 ;
T_2 V_116 , V_117 ;
T_1 V_118 ;
T_1 V_84 ;
T_1 V_82 , V_83 ;
T_3 V_119 , V_120 , V_79 , V_80 = 0 ;
if ( ( V_101 > ( T_3 ) V_29 -> V_87 ) && ( V_101 < ( 1LL << 32 ) ) ) {
sprintf ( V_106 , L_35 , V_101 ) ;
return - V_3 ;
}
if ( V_101 >= ( T_3 ) V_29 -> V_89 ) {
sprintf ( V_106 , L_36 , V_101 ) ;
return - V_3 ;
}
for ( V_76 = 0 ; V_76 < V_90 ; V_76 ++ ) {
F_32 ( V_29 -> V_91 , V_92 [ V_76 ] ,
& V_1 ) ;
if ( ! F_50 ( V_1 ) )
continue;
V_79 = F_49 ( V_1 ) ;
if ( V_79 <= V_80 ) {
sprintf ( V_106 , L_37 ) ;
return - V_3 ;
}
if ( V_101 <= V_79 )
break;
V_80 = V_79 ;
}
if ( V_76 == V_90 ) {
sprintf ( V_106 , L_37 ) ;
return - V_3 ;
}
* V_105 = F_1 ( V_1 ) ;
V_113 = F_51 ( V_1 ) ;
F_32 ( V_29 -> V_91 , V_93 [ V_76 ] ,
& V_1 ) ;
V_78 = F_3 ( V_1 , 0 ) ;
for ( V_109 = 0 ; V_109 < 8 ; V_109 ++ ) {
if ( V_109 > 0 && V_78 == F_3 ( V_1 , V_109 ) )
break;
V_114 [ V_109 ] = F_3 ( V_1 , V_109 ) ;
F_14 ( 0 , L_38 ,
V_109 , V_114 [ V_109 ] ) ;
}
F_14 ( 0 , L_39 ,
V_29 -> V_8 -> V_46 ,
V_76 ,
V_101 ,
V_79 ,
V_109 + 7 ,
V_113 ? L_40 : L_41 ) ;
if ( V_113 )
V_111 = ( ( V_101 >> 6 ) ^ ( V_101 >> 16 ) ) & 7 ;
else
V_111 = ( V_101 >> 6 ) & 7 ;
switch ( V_109 ) {
case 1 :
V_111 = 0 ;
break;
case 2 :
V_111 = V_111 & 1 ;
break;
case 4 :
V_111 = V_111 & 3 ;
break;
case 8 :
break;
default:
sprintf ( V_106 , L_42 ) ;
return - V_3 ;
}
* V_102 = V_114 [ V_111 ] ;
F_14 ( 0 , L_43 ,
V_111 , V_109 , * V_102 ) ;
V_107 = F_65 ( * V_102 ) ;
if ( ! V_107 ) {
sprintf ( V_106 , L_44 ,
* V_102 ) ;
return - V_3 ;
}
V_27 = V_107 ;
V_29 = V_27 -> V_30 ;
V_80 = 0 ;
for ( V_77 = 0 ; V_77 < V_94 ; V_77 ++ ) {
F_32 ( V_29 -> V_95 , V_96 [ V_77 ] ,
& V_1 ) ;
V_79 = F_52 ( V_1 ) ;
if ( V_79 <= V_80 ) {
sprintf ( V_106 , L_45 ) ;
return - V_3 ;
}
if ( V_101 <= V_79 )
break;
V_80 = V_79 ;
}
V_116 = F_54 ( V_1 ) + 1 ;
V_117 = F_53 ( V_1 ) + 1 ;
F_32 ( V_29 -> V_66 [ 0 ] ,
V_97 [ V_77 ] ,
& V_118 ) ;
if ( V_116 == 3 )
V_111 = V_101 >> 6 ;
else
V_111 = V_101 >> ( 6 + V_117 ) ;
V_111 = V_111 % V_116 ;
switch ( V_111 ) {
case 0 :
V_112 = F_55 ( V_1 ) ;
break;
case 1 :
V_112 = F_56 ( V_1 ) ;
break;
case 2 :
V_112 = F_57 ( V_1 ) ;
break;
case 3 :
V_112 = F_58 ( V_1 ) ;
break;
default:
sprintf ( V_106 , L_46 ) ;
return - V_3 ;
}
* V_103 = 1 << V_112 ;
if ( V_29 -> V_49 ) {
* V_103 |= 1 << ( ( V_112 + 2 ) % 4 ) ;
switch( V_116 ) {
case 2 :
case 4 :
V_110 = 1 << V_117 * ( V_116 >> 1 ) ;
break;
default:
sprintf ( V_106 , L_47 ) ;
return - V_3 ;
}
} else
V_110 = ( 1 << V_117 ) * V_116 ;
if ( V_29 -> V_53 )
* V_103 |= 1 << ( ( V_112 + 1 ) % 4 ) ;
V_120 = F_59 ( V_118 ) ;
F_14 ( 0 , L_48 ,
V_77 ,
V_101 ,
V_79 ,
( T_1 ) F_53 ( V_1 ) ,
V_116 ,
V_120 ,
V_111 ,
V_112 ,
* V_103 ) ;
if ( V_120 > V_101 ) {
sprintf ( V_106 , L_49 ,
V_120 , V_101 ) ;
return - V_3 ;
}
V_101 -= V_120 ;
V_119 = V_101 & 0x7f ;
V_101 >>= 6 ;
V_101 = F_67 ( V_101 , V_110 ) ;
#if 0
addr = addr / ch_way;
#endif
V_119 |= V_101 << 6 ;
for ( V_108 = 0 ; V_108 < V_98 ; V_108 ++ ) {
F_32 ( V_29 -> V_66 [ V_112 ] ,
V_99 [ V_108 ] ,
& V_1 ) ;
if ( ! F_60 ( V_1 ) )
continue;
V_79 = F_61 ( V_1 ) ;
V_82 = F_47 ( V_79 >> 20 , 1000 , & V_83 ) ;
F_14 ( 0 , L_50 ,
V_108 ,
V_82 , V_83 ,
V_79 ,
1 << F_62 ( V_1 ) ) ;
if ( V_119 <= V_79 )
break;
}
if ( V_108 == V_98 ) {
sprintf ( V_106 , L_51 ,
V_119 ) ;
return - V_3 ;
}
V_84 = F_62 ( V_1 ) ;
if ( V_29 -> V_55 )
V_111 = ( V_119 >> 6 ) ;
else
V_111 = ( V_119 >> 13 ) ;
V_111 %= 1 << V_84 ;
F_32 ( V_29 -> V_66 [ V_112 ] ,
V_100 [ V_108 ] [ V_111 ] ,
& V_1 ) ;
* V_104 = F_64 ( V_1 ) ;
F_14 ( 0 , L_52 ,
V_108 ,
V_119 ,
V_79 ,
V_84 ,
V_111 ) ;
return 0 ;
}
static void F_68 ( struct V_8 * V_8 )
{
int V_20 ;
F_14 ( 0 , L_53 ) ;
for ( V_20 = 0 ; V_20 < V_8 -> V_14 ; V_20 ++ ) {
struct V_17 * V_13 = V_8 -> V_13 [ V_20 ] ;
if ( ! V_13 )
continue;
F_14 ( 0 , L_54 ,
V_13 -> V_9 -> V_121 ,
F_28 ( V_13 -> V_21 ) , F_29 ( V_13 -> V_21 ) ) ;
F_69 ( V_13 ) ;
}
}
static void F_70 ( void )
{
struct V_8 * V_8 , * V_122 ;
F_71 (sbridge_dev, tmp, &sbridge_edac_list, list) {
F_68 ( V_8 ) ;
F_25 ( V_8 ) ;
}
}
static int F_72 ( struct V_17 * * V_123 ,
T_2 * V_124 ,
const struct V_10 * V_11 ,
const unsigned V_125 )
{
struct V_8 * V_8 ;
const struct V_126 * V_127 = & V_11 -> V_128 [ V_125 ] ;
struct V_17 * V_13 = NULL ;
T_2 V_9 = 0 ;
F_31 ( V_129 ,
L_55 ,
V_127 -> V_130 , V_127 -> V_19 ,
V_131 , V_127 -> V_132 ) ;
V_13 = F_73 ( V_131 ,
V_127 -> V_132 , * V_123 ) ;
if ( ! V_13 ) {
if ( * V_123 ) {
* V_123 = V_13 ;
return 0 ;
}
if ( V_127 -> V_133 )
return 0 ;
if ( V_125 == 0 )
return - V_24 ;
F_31 ( V_129 ,
L_56 ,
V_127 -> V_130 , V_127 -> V_19 ,
V_131 , V_127 -> V_132 ) ;
return - V_24 ;
}
V_9 = V_13 -> V_9 -> V_121 ;
V_8 = F_19 ( V_9 ) ;
if ( ! V_8 ) {
V_8 = F_21 ( V_9 , V_11 ) ;
if ( ! V_8 ) {
F_69 ( V_13 ) ;
return - V_134 ;
}
( * V_124 ) ++ ;
}
if ( V_8 -> V_13 [ V_125 ] ) {
F_31 ( V_23 ,
L_57
L_58 ,
V_9 , V_127 -> V_130 , V_127 -> V_19 ,
V_131 , V_127 -> V_132 ) ;
F_69 ( V_13 ) ;
return - V_24 ;
}
V_8 -> V_13 [ V_125 ] = V_13 ;
if ( F_74 ( F_28 ( V_13 -> V_21 ) != V_127 -> V_130 ||
F_29 ( V_13 -> V_21 ) != V_127 -> V_19 ) ) {
F_31 ( V_23 ,
L_59
L_60 ,
V_131 , V_127 -> V_132 ,
V_9 , F_28 ( V_13 -> V_21 ) , F_29 ( V_13 -> V_21 ) ,
V_9 , V_127 -> V_130 , V_127 -> V_19 ) ;
return - V_24 ;
}
if ( F_74 ( F_75 ( V_13 ) < 0 ) ) {
F_31 ( V_23 ,
L_61
L_58 ,
V_9 , V_127 -> V_130 , V_127 -> V_19 ,
V_131 , V_127 -> V_132 ) ;
return - V_24 ;
}
F_14 ( 0 , L_62 ,
V_9 , V_127 -> V_130 , V_127 -> V_19 ,
V_131 , V_127 -> V_132 ) ;
F_76 ( V_13 ) ;
* V_123 = V_13 ;
return 0 ;
}
static int F_77 ( T_2 * V_124 )
{
int V_20 , V_135 ;
struct V_17 * V_13 = NULL ;
const struct V_10 * V_11 = V_136 ;
while ( V_11 && V_11 -> V_128 ) {
for ( V_20 = 0 ; V_20 < V_11 -> V_14 ; V_20 ++ ) {
V_13 = NULL ;
do {
V_135 = F_72 ( & V_13 , V_124 ,
V_11 , V_20 ) ;
if ( V_135 < 0 ) {
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
V_29 -> V_91 = V_13 ;
break;
case 7 :
V_29 -> V_85 = V_13 ;
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
V_29 -> V_95 = V_13 ;
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
V_29 -> V_66 [ V_19 - 2 ] = V_13 ;
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
F_14 ( 0 , L_63 ,
V_8 -> V_9 ,
F_28 ( V_13 -> V_21 ) , F_29 ( V_13 -> V_21 ) ,
V_13 ) ;
}
if ( ! V_29 -> V_91 || ! V_29 -> V_85 || ! V_29 -> V_95 ||
! V_29 -> V_66 || ! V_29 -> V_47 || ! V_29 -> V_50 )
goto V_137;
for ( V_20 = 0 ; V_20 < V_61 ; V_20 ++ ) {
if ( ! V_29 -> V_66 [ V_20 ] )
goto V_137;
}
return 0 ;
V_137:
F_31 ( V_23 , L_64 ) ;
return - V_24 ;
error:
F_31 ( V_23 , L_65
L_66 ,
V_18 , V_19 ) ;
return - V_3 ;
}
static void F_79 ( struct V_26 * V_27 ,
const struct V_138 * V_139 )
{
struct V_26 * V_107 ;
struct V_28 * V_29 = V_27 -> V_30 ;
enum V_140 V_141 ;
char * type , * V_142 , V_106 [ 256 ] ;
bool V_143 = F_80 ( V_139 -> V_144 , 0 , 0 ) ;
bool V_145 = F_80 ( V_139 -> V_146 , 62 , 62 ) ;
bool V_147 = F_80 ( V_139 -> V_146 , 61 , 61 ) ;
bool V_148 = F_80 ( V_139 -> V_146 , 56 , 56 ) ;
T_1 V_149 = F_80 ( V_139 -> V_146 , 38 , 52 ) ;
T_1 V_150 = F_80 ( V_139 -> V_146 , 16 , 31 ) ;
T_1 V_151 = F_80 ( V_139 -> V_146 , 0 , 15 ) ;
T_1 V_67 = F_80 ( V_139 -> V_146 , 0 , 3 ) ;
T_1 V_152 = F_80 ( V_139 -> V_146 , 4 , 6 ) ;
long V_103 , V_153 ;
T_2 V_104 , V_102 ;
int V_135 , V_32 ;
char * V_105 = NULL ;
if ( V_147 ) {
if ( V_143 ) {
type = L_67 ;
V_141 = V_154 ;
} else {
type = L_68 ;
V_141 = V_155 ;
}
} else {
type = L_69 ;
V_141 = V_156 ;
}
if ( ! ( ( V_151 & 0xef80 ) == 0x80 ) ) {
V_142 = L_70 ;
} else {
switch ( V_152 ) {
case 0 :
V_142 = L_71 ;
break;
case 1 :
V_142 = L_72 ;
break;
case 2 :
V_142 = L_73 ;
break;
case 3 :
V_142 = L_74 ;
break;
case 4 :
V_142 = L_75 ;
break;
default:
V_142 = L_76 ;
break;
}
}
V_135 = F_66 ( V_27 , V_139 -> V_101 , & V_102 ,
& V_103 , & V_104 , & V_105 , V_106 ) ;
if ( V_135 < 0 )
goto V_157;
V_107 = F_65 ( V_102 ) ;
if ( ! V_107 ) {
strcpy ( V_106 , L_77 ) ;
goto V_157;
}
V_27 = V_107 ;
V_29 = V_27 -> V_30 ;
V_153 = F_81 ( & V_103 , V_61 ) ;
if ( V_104 < 4 )
V_32 = 0 ;
else if ( V_104 < 8 )
V_32 = 1 ;
else
V_32 = 2 ;
snprintf ( V_106 , sizeof( V_106 ) ,
L_78 ,
V_145 ? L_79 : L_40 ,
( V_147 && V_148 ) ? L_80 : L_40 ,
V_105 ,
V_150 , V_151 ,
V_102 ,
V_103 ,
V_104 ) ;
F_14 ( 0 , L_81 , V_106 ) ;
F_82 ( V_141 , V_27 , V_149 ,
V_139 -> V_101 >> V_158 , V_139 -> V_101 & ~ V_159 , 0 ,
V_67 , V_32 , - 1 ,
V_142 , V_106 ) ;
return;
V_157:
F_82 ( V_141 , V_27 , V_149 , 0 , 0 , 0 ,
- 1 , - 1 , - 1 ,
V_106 , L_40 ) ;
}
static void F_83 ( struct V_26 * V_27 )
{
struct V_28 * V_29 = V_27 -> V_30 ;
int V_20 ;
unsigned V_160 = 0 ;
struct V_138 * V_139 ;
F_84 () ;
V_160 = ( V_29 -> V_161 + V_162 - V_29 -> V_163 )
% V_162 ;
if ( ! V_160 )
return;
V_139 = V_29 -> V_164 ;
if ( V_29 -> V_163 + V_160 > V_162 ) {
unsigned V_165 = V_162 - V_29 -> V_163 ;
memcpy ( V_139 , & V_29 -> V_166 [ V_29 -> V_163 ] , sizeof( * V_139 ) * V_165 ) ;
F_85 () ;
V_29 -> V_163 = 0 ;
V_160 -= V_165 ;
V_139 += V_165 ;
}
memcpy ( V_139 , & V_29 -> V_166 [ V_29 -> V_163 ] , sizeof( * V_139 ) * V_160 ) ;
F_85 () ;
V_29 -> V_163 += V_160 ;
F_84 () ;
if ( V_29 -> V_167 ) {
F_31 ( V_23 , L_82 ,
V_29 -> V_167 ) ;
F_85 () ;
V_29 -> V_167 = 0 ;
}
for ( V_20 = 0 ; V_20 < V_160 ; V_20 ++ )
F_79 ( V_27 , & V_29 -> V_164 [ V_20 ] ) ;
}
static int F_86 ( struct V_168 * V_169 , unsigned long V_170 ,
void * V_171 )
{
struct V_138 * V_138 = (struct V_138 * ) V_171 ;
struct V_26 * V_27 ;
struct V_28 * V_29 ;
V_27 = F_65 ( V_138 -> V_172 ) ;
if ( ! V_27 )
return V_173 ;
V_29 = V_27 -> V_30 ;
if ( ( V_138 -> V_146 & 0xefff ) >> 7 != 1 )
return V_174 ;
F_87 ( L_83 ) ;
F_87 ( L_84 ,
V_138 -> V_175 , V_138 -> V_144 , V_138 -> V_176 , V_138 -> V_146 ) ;
F_87 ( L_85 , V_138 -> V_177 ) ;
F_87 ( L_86 , V_138 -> V_101 ) ;
F_87 ( L_87 , V_138 -> V_178 ) ;
F_87 ( L_88 ,
V_138 -> V_179 , V_138 -> V_180 , V_138 -> time ,
V_138 -> V_172 , V_138 -> V_181 ) ;
if ( F_88 ( V_138 -> V_182 ) . V_183 != V_29 -> V_8 -> V_46 )
return V_174 ;
F_84 () ;
if ( ( V_29 -> V_161 + 1 ) % V_162 == V_29 -> V_163 ) {
F_85 () ;
V_29 -> V_167 ++ ;
return V_174 ;
}
memcpy ( & V_29 -> V_166 [ V_29 -> V_161 ] , V_138 , sizeof( * V_138 ) ) ;
F_85 () ;
V_29 -> V_161 = ( V_29 -> V_161 + 1 ) % V_162 ;
if ( V_138 -> V_144 & 1 )
F_83 ( V_27 ) ;
return V_184 ;
}
static void F_89 ( struct V_8 * V_8 )
{
struct V_26 * V_27 = V_8 -> V_27 ;
struct V_28 * V_29 ;
if ( F_74 ( ! V_27 || ! V_27 -> V_30 ) ) {
F_14 ( 0 , L_89 , & V_8 -> V_13 [ 0 ] -> V_130 ) ;
F_31 ( V_23 , L_90 ) ;
return;
}
V_29 = V_27 -> V_30 ;
F_14 ( 0 , L_91 ,
V_27 , & V_8 -> V_13 [ 0 ] -> V_130 ) ;
F_90 ( V_27 -> V_13 ) ;
F_14 ( 1 , L_92 , V_27 -> V_185 ) ;
F_23 ( V_27 -> V_185 ) ;
F_91 ( V_27 ) ;
V_8 -> V_27 = NULL ;
}
static int F_92 ( struct V_8 * V_8 )
{
struct V_26 * V_27 ;
struct V_186 V_63 [ 2 ] ;
struct V_28 * V_29 ;
int V_135 ;
V_135 = F_30 ( V_8 -> V_9 ) ;
if ( F_74 ( V_135 < 0 ) )
return V_135 ;
V_63 [ 0 ] . type = V_187 ;
V_63 [ 0 ] . V_36 = V_61 ;
V_63 [ 0 ] . V_188 = false ;
V_63 [ 1 ] . type = V_189 ;
V_63 [ 1 ] . V_36 = V_190 ;
V_63 [ 1 ] . V_188 = true ;
V_27 = F_93 ( V_8 -> V_46 , F_41 ( V_63 ) , V_63 ,
sizeof( * V_29 ) ) ;
if ( F_74 ( ! V_27 ) )
return - V_134 ;
F_14 ( 0 , L_91 ,
V_27 , & V_8 -> V_13 [ 0 ] -> V_130 ) ;
V_29 = V_27 -> V_30 ;
memset ( V_29 , 0 , sizeof( * V_29 ) ) ;
V_29 -> V_8 = V_8 ;
V_8 -> V_27 = V_27 ;
V_27 -> V_191 = V_192 ;
V_27 -> V_193 = V_194 ;
V_27 -> V_195 = V_194 ;
V_27 -> V_196 = L_93 ;
V_27 -> V_197 = V_198 ;
V_27 -> V_185 = F_94 ( V_12 , L_94 , V_27 -> V_199 ) ;
V_27 -> V_200 = F_95 ( V_8 -> V_13 [ 0 ] ) ;
V_27 -> V_201 = NULL ;
V_27 -> V_202 = F_83 ;
V_135 = F_78 ( V_27 , V_8 ) ;
if ( F_74 ( V_135 < 0 ) )
goto V_203;
F_34 ( V_27 ) ;
F_45 ( V_27 ) ;
V_27 -> V_13 = & V_8 -> V_13 [ 0 ] -> V_130 ;
if ( F_74 ( F_96 ( V_27 ) ) ) {
F_14 ( 0 , L_95 ) ;
V_135 = - V_3 ;
goto V_203;
}
return 0 ;
V_203:
F_23 ( V_27 -> V_185 ) ;
F_91 ( V_27 ) ;
V_8 -> V_27 = NULL ;
return V_135 ;
}
static int F_97 ( struct V_17 * V_13 , const struct V_204 * V_205 )
{
int V_135 ;
T_2 V_46 , V_124 = 0 ;
struct V_8 * V_8 ;
F_98 ( & V_206 ) ;
if ( F_74 ( V_207 >= 1 ) ) {
F_99 ( & V_206 ) ;
return - V_24 ;
}
V_207 ++ ;
V_135 = F_77 ( & V_124 ) ;
if ( F_74 ( V_135 < 0 ) )
goto V_203;
V_46 = 0 ;
F_20 (sbridge_dev, &sbridge_edac_list, list) {
F_14 ( 0 , L_96 ,
V_46 , V_46 + 1 , V_124 ) ;
V_8 -> V_46 = V_46 ++ ;
V_135 = F_92 ( V_8 ) ;
if ( F_74 ( V_135 < 0 ) )
goto V_208;
}
F_31 ( V_129 , L_97 ) ;
F_99 ( & V_206 ) ;
return 0 ;
V_208:
F_20 (sbridge_dev, &sbridge_edac_list, list)
F_89 ( V_8 ) ;
F_70 () ;
V_203:
F_99 ( & V_206 ) ;
return V_135 ;
}
static void F_100 ( struct V_17 * V_13 )
{
struct V_8 * V_8 ;
F_14 ( 0 , L_53 ) ;
F_98 ( & V_206 ) ;
if ( F_74 ( ! V_207 ) ) {
F_99 ( & V_206 ) ;
return;
}
F_20 (sbridge_dev, &sbridge_edac_list, list)
F_89 ( V_8 ) ;
F_70 () ;
V_207 -- ;
F_99 ( & V_206 ) ;
}
static int T_4 F_101 ( void )
{
int V_209 ;
F_14 ( 2 , L_53 ) ;
F_102 () ;
V_209 = F_103 ( & V_210 ) ;
if ( V_209 >= 0 ) {
F_104 ( & V_211 ) ;
return 0 ;
}
F_31 ( V_23 , L_98 ,
V_209 ) ;
return V_209 ;
}
static void T_5 F_105 ( void )
{
F_14 ( 2 , L_53 ) ;
F_106 ( & V_210 ) ;
F_107 ( & V_211 ) ;
}
