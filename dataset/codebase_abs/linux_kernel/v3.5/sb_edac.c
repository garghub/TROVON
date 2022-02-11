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
F_14 ( L_5 ,
V_5 , ( unsigned int ) F_13 ( V_4 ) , V_4 ) ;
return - V_3 ;
}
return V_5 ;
}
static inline int F_15 ( T_1 V_4 )
{
int V_6 = ( F_16 ( V_4 ) + 12 ) ;
if ( V_6 < 13 || V_6 > 18 ) {
F_14 ( L_6 ,
V_6 , ( unsigned int ) F_16 ( V_4 ) , V_4 ) ;
return - V_3 ;
}
return 1 << V_6 ;
}
static inline int F_17 ( T_1 V_4 )
{
int V_7 = ( F_18 ( V_4 ) + 10 ) ;
if ( V_7 > 12 ) {
F_14 ( L_7 ,
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
F_30 ( L_8 ,
V_9 , V_18 , V_19 , V_8 -> V_13 [ V_20 ] ) ;
return V_8 -> V_13 [ V_20 ] ;
}
}
return NULL ;
}
static int F_31 ( const T_2 V_9 )
{
struct V_17 * V_13 = NULL ;
T_1 V_22 ;
V_13 = F_27 ( V_9 , 15 , 0 ) ;
if ( ! V_13 ) {
F_32 ( V_23 , L_9
L_10 ,
V_9 , 15 , 0 ) ;
return - V_24 ;
}
F_33 ( V_13 , V_25 , & V_22 ) ;
if ( ! F_34 ( V_22 ) ) {
F_32 ( V_23 , L_11 ) ;
return - V_24 ;
}
return 0 ;
}
static int F_35 ( struct V_26 * V_27 )
{
struct V_28 * V_29 = V_27 -> V_30 ;
struct V_31 * V_32 ;
int V_20 , V_33 , V_34 , V_5 , V_6 , V_7 , V_35 , V_36 ;
T_1 V_1 ;
enum V_37 V_38 ;
enum V_39 V_40 ;
F_33 ( V_29 -> V_41 , V_42 , & V_1 ) ;
V_29 -> V_8 -> V_43 = F_36 ( V_1 ) ;
F_33 ( V_29 -> V_41 , V_44 , & V_1 ) ;
V_29 -> V_8 -> V_45 = F_37 ( V_1 ) ;
F_14 ( L_12 ,
V_29 -> V_8 -> V_46 ,
V_29 -> V_8 -> V_45 ,
V_29 -> V_8 -> V_43 ) ;
F_33 ( V_29 -> V_47 , V_48 , & V_1 ) ;
if ( F_38 ( V_1 ) ) {
F_14 ( L_13 ) ;
V_29 -> V_49 = true ;
} else {
F_14 ( L_14 ) ;
V_29 -> V_49 = false ;
}
F_33 ( V_29 -> V_50 , V_25 , & V_29 -> V_51 . V_22 ) ;
if ( F_39 ( V_29 -> V_51 . V_22 ) ) {
F_14 ( L_15 ) ;
V_38 = V_52 ;
V_29 -> V_53 = true ;
} else {
F_14 ( L_16 ) ;
V_38 = V_54 ;
V_29 -> V_53 = false ;
}
if ( F_40 ( V_29 -> V_51 . V_22 ) ) {
F_14 ( L_17 ) ;
V_29 -> V_55 = true ;
} else {
F_14 ( L_18 ) ;
V_29 -> V_55 = false ;
}
F_33 ( V_29 -> V_56 , V_57 , & V_1 ) ;
if ( F_41 ( V_1 ) ) {
F_14 ( L_19 ) ;
V_40 = V_58 ;
} else {
F_14 ( L_20 ) ;
V_40 = V_59 ;
}
V_34 = 8 ;
for ( V_20 = 0 ; V_20 < V_60 ; V_20 ++ ) {
T_1 V_4 ;
for ( V_33 = 0 ; V_33 < F_42 ( V_61 ) ; V_33 ++ ) {
V_32 = F_43 ( V_27 -> V_62 , V_27 -> V_63 , V_27 -> V_64 ,
V_20 , V_33 , 0 ) ;
F_33 ( V_29 -> V_65 [ V_20 ] ,
V_61 [ V_33 ] , & V_4 ) ;
F_44 ( L_21 , V_20 , V_33 , V_4 ) ;
if ( F_45 ( V_4 ) ) {
V_29 -> V_66 [ V_20 ] . V_63 ++ ;
V_5 = F_12 ( V_4 ) ;
V_6 = F_15 ( V_4 ) ;
V_7 = F_17 ( V_4 ) ;
V_35 = ( V_6 * V_7 * V_34 * V_5 ) >> ( 20 - 3 ) ;
V_36 = F_46 ( V_35 ) ;
F_14 ( L_22 ,
V_29 -> V_8 -> V_46 , V_20 , V_33 ,
V_35 , V_36 ,
V_34 , V_5 , V_6 , V_7 ) ;
V_32 -> V_67 = V_36 ;
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
static void F_47 ( const struct V_26 * V_27 )
{
struct V_28 * V_29 = V_27 -> V_30 ;
int V_20 , V_33 , V_74 , V_75 , V_76 , V_77 ;
T_1 V_1 ;
T_3 V_78 , V_79 = 0 ;
T_3 V_80 ;
T_1 V_81 , V_82 ;
T_1 V_83 ;
F_33 ( V_29 -> V_84 , V_85 ,
& V_1 ) ;
V_29 -> V_86 = F_48 ( V_1 ) ;
V_80 = ( 1 + V_29 -> V_86 ) >> 20 ;
V_81 = F_49 ( V_80 , 1000 , & V_82 ) ;
F_14 ( L_24 ,
V_81 , V_82 , ( T_3 ) V_29 -> V_86 ) ;
F_33 ( V_29 -> V_84 , V_87 ,
& V_1 ) ;
V_29 -> V_88 = F_50 ( V_1 ) ;
V_80 = ( 1 + V_29 -> V_88 ) >> 20 ;
V_81 = F_49 ( V_80 , 1000 , & V_82 ) ;
F_14 ( L_25 ,
V_81 , V_82 , ( T_3 ) V_29 -> V_88 ) ;
V_79 = 0 ;
for ( V_75 = 0 ; V_75 < V_89 ; V_75 ++ ) {
F_33 ( V_29 -> V_90 , V_91 [ V_75 ] ,
& V_1 ) ;
V_78 = F_51 ( V_1 ) ;
if ( ! F_52 ( V_1 ) )
continue;
if ( V_78 <= V_79 )
break;
V_80 = ( V_78 + 1 ) >> 20 ;
V_81 = F_49 ( V_80 , 1000 , & V_82 ) ;
F_14 ( L_26 ,
V_75 ,
F_1 ( V_1 ) ,
V_81 , V_82 ,
( ( T_3 ) V_80 ) << 20L ,
F_53 ( V_1 ) ? L_27 : L_28 ,
V_1 ) ;
V_79 = V_78 ;
F_33 ( V_29 -> V_90 , V_92 [ V_75 ] ,
& V_1 ) ;
V_77 = F_3 ( V_1 , 0 ) ;
for ( V_33 = 0 ; V_33 < 8 ; V_33 ++ ) {
if ( V_33 > 0 && V_77 == F_3 ( V_1 , V_33 ) )
break;
F_14 ( L_29 ,
V_75 , V_33 , F_3 ( V_1 , V_33 ) ) ;
}
}
V_79 = 0 ;
for ( V_76 = 0 ; V_76 < V_93 ; V_76 ++ ) {
F_33 ( V_29 -> V_94 , V_95 [ V_76 ] ,
& V_1 ) ;
V_78 = F_54 ( V_1 ) ;
if ( V_78 <= V_79 )
break;
V_80 = ( V_78 + 1 ) >> 20 ;
V_81 = F_49 ( V_80 , 1000 , & V_82 ) ;
F_14 ( L_30 ,
V_76 , V_81 , V_82 ,
( ( T_3 ) V_80 ) << 20L ,
( T_1 ) F_55 ( V_1 ) ,
( T_1 ) F_56 ( V_1 ) ,
( T_1 ) F_57 ( V_1 ) ,
( T_1 ) F_58 ( V_1 ) ,
( T_1 ) F_59 ( V_1 ) ,
( T_1 ) F_60 ( V_1 ) ,
V_1 ) ;
V_79 = V_78 ;
}
for ( V_20 = 0 ; V_20 < V_60 ; V_20 ++ ) {
if ( ! V_29 -> V_66 [ V_20 ] . V_63 )
continue;
for ( V_33 = 0 ; V_33 < V_76 ; V_33 ++ ) {
F_33 ( V_29 -> V_65 [ V_20 ] ,
V_96 [ V_33 ] ,
& V_1 ) ;
V_80 = F_61 ( V_1 ) >> 20 ;
V_81 = F_49 ( V_80 , 1000 , & V_82 ) ;
F_14 ( L_31 ,
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
F_33 ( V_29 -> V_65 [ V_20 ] ,
V_98 [ V_33 ] ,
& V_1 ) ;
if ( ! F_62 ( V_1 ) )
continue;
V_80 = F_63 ( V_1 ) >> 20 ;
V_83 = 1 << F_64 ( V_1 ) ;
V_81 = F_49 ( V_80 , 1000 , & V_82 ) ;
F_14 ( L_32 ,
V_20 , V_33 ,
V_81 , V_82 ,
( ( T_3 ) V_80 ) << 20L ,
V_83 ,
V_1 ) ;
for ( V_74 = 0 ; V_74 < V_83 ; V_74 ++ ) {
F_33 ( V_29 -> V_65 [ V_20 ] ,
V_99 [ V_33 ] [ V_74 ] ,
& V_1 ) ;
V_80 = F_65 ( V_1 ) << 6 ;
V_81 = F_49 ( V_80 , 1000 , & V_82 ) ;
F_14 ( L_33 ,
V_20 , V_33 , V_74 ,
V_81 , V_82 ,
( ( T_3 ) V_80 ) << 20L ,
( T_1 ) F_66 ( V_1 ) ,
V_1 ) ;
}
}
}
}
struct V_26 * F_67 ( T_2 V_45 )
{
struct V_8 * V_8 ;
F_20 (sbridge_dev, &sbridge_edac_list, list) {
if ( V_8 -> V_45 == V_45 )
return V_8 -> V_27 ;
}
return NULL ;
}
static int F_68 ( struct V_26 * V_27 ,
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
F_33 ( V_29 -> V_90 , V_91 [ V_75 ] ,
& V_1 ) ;
if ( ! F_52 ( V_1 ) )
continue;
V_78 = F_51 ( V_1 ) ;
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
V_112 = F_53 ( V_1 ) ;
F_33 ( V_29 -> V_90 , V_92 [ V_75 ] ,
& V_1 ) ;
V_77 = F_3 ( V_1 , 0 ) ;
for ( V_108 = 0 ; V_108 < 8 ; V_108 ++ ) {
if ( V_108 > 0 && V_77 == F_3 ( V_1 , V_108 ) )
break;
V_113 [ V_108 ] = F_3 ( V_1 , V_108 ) ;
F_14 ( L_37 ,
V_108 , V_113 [ V_108 ] ) ;
}
F_14 ( L_38 ,
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
F_14 ( L_42 ,
V_110 , V_108 , * V_101 ) ;
V_106 = F_67 ( * V_101 ) ;
if ( ! V_106 ) {
sprintf ( V_105 , L_43 ,
* V_101 ) ;
return - V_3 ;
}
V_27 = V_106 ;
V_29 = V_27 -> V_30 ;
V_79 = 0 ;
for ( V_76 = 0 ; V_76 < V_93 ; V_76 ++ ) {
F_33 ( V_29 -> V_94 , V_95 [ V_76 ] ,
& V_1 ) ;
V_78 = F_54 ( V_1 ) ;
if ( V_78 <= V_79 ) {
sprintf ( V_105 , L_44 ) ;
return - V_3 ;
}
if ( V_100 <= V_78 )
break;
V_79 = V_78 ;
}
V_115 = F_56 ( V_1 ) + 1 ;
V_116 = F_55 ( V_1 ) + 1 ;
F_33 ( V_29 -> V_65 [ 0 ] ,
V_96 [ V_76 ] ,
& V_117 ) ;
if ( V_115 == 3 )
V_110 = V_100 >> 6 ;
else
V_110 = V_100 >> ( 6 + V_116 ) ;
V_110 = V_110 % V_115 ;
switch ( V_110 ) {
case 0 :
V_111 = F_57 ( V_1 ) ;
break;
case 1 :
V_111 = F_58 ( V_1 ) ;
break;
case 2 :
V_111 = F_59 ( V_1 ) ;
break;
case 3 :
V_111 = F_60 ( V_1 ) ;
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
V_119 = F_61 ( V_117 ) ;
F_14 ( L_47 ,
V_76 ,
V_100 ,
V_78 ,
( T_1 ) F_55 ( V_1 ) ,
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
V_100 = F_69 ( V_100 , V_109 ) ;
#if 0
addr = addr / ch_way;
#endif
V_118 |= V_100 << 6 ;
for ( V_107 = 0 ; V_107 < V_97 ; V_107 ++ ) {
F_33 ( V_29 -> V_65 [ V_111 ] ,
V_98 [ V_107 ] ,
& V_1 ) ;
if ( ! F_62 ( V_1 ) )
continue;
V_78 = F_63 ( V_1 ) ;
V_81 = F_49 ( V_78 >> 20 , 1000 , & V_82 ) ;
F_14 ( L_49 ,
V_107 ,
V_81 , V_82 ,
V_78 ,
1 << F_64 ( V_1 ) ) ;
if ( V_118 <= V_78 )
break;
}
if ( V_107 == V_97 ) {
sprintf ( V_105 , L_50 ,
V_118 ) ;
return - V_3 ;
}
V_83 = F_64 ( V_1 ) ;
if ( V_29 -> V_55 )
V_110 = ( V_118 >> 6 ) ;
else
V_110 = ( V_118 >> 13 ) ;
V_110 %= 1 << V_83 ;
F_33 ( V_29 -> V_65 [ V_111 ] ,
V_99 [ V_107 ] [ V_110 ] ,
& V_1 ) ;
* V_103 = F_66 ( V_1 ) ;
F_14 ( L_51 ,
V_107 ,
V_118 ,
V_78 ,
V_83 ,
V_110 ) ;
return 0 ;
}
static void F_70 ( struct V_8 * V_8 )
{
int V_20 ;
F_14 ( __FILE__ L_52 , V_120 ) ;
for ( V_20 = 0 ; V_20 < V_8 -> V_14 ; V_20 ++ ) {
struct V_17 * V_13 = V_8 -> V_13 [ V_20 ] ;
if ( ! V_13 )
continue;
F_14 ( L_53 ,
V_13 -> V_9 -> V_121 ,
F_28 ( V_13 -> V_21 ) , F_29 ( V_13 -> V_21 ) ) ;
F_71 ( V_13 ) ;
}
}
static void F_72 ( void )
{
struct V_8 * V_8 , * V_122 ;
F_73 (sbridge_dev, tmp, &sbridge_edac_list, list) {
F_70 ( V_8 ) ;
F_25 ( V_8 ) ;
}
}
static int F_74 ( struct V_17 * * V_123 ,
T_2 * V_124 ,
const struct V_10 * V_11 ,
const unsigned V_125 )
{
struct V_8 * V_8 ;
const struct V_126 * V_127 = & V_11 -> V_128 [ V_125 ] ;
struct V_17 * V_13 = NULL ;
T_2 V_9 = 0 ;
F_32 ( V_129 ,
L_54 ,
V_127 -> V_130 , V_127 -> V_19 ,
V_131 , V_127 -> V_132 ) ;
V_13 = F_75 ( V_131 ,
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
F_32 ( V_129 ,
L_55 ,
V_127 -> V_130 , V_127 -> V_19 ,
V_131 , V_127 -> V_132 ) ;
return - V_24 ;
}
V_9 = V_13 -> V_9 -> V_121 ;
V_8 = F_19 ( V_9 ) ;
if ( ! V_8 ) {
V_8 = F_21 ( V_9 , V_11 ) ;
if ( ! V_8 ) {
F_71 ( V_13 ) ;
return - V_134 ;
}
( * V_124 ) ++ ;
}
if ( V_8 -> V_13 [ V_125 ] ) {
F_32 ( V_23 ,
L_56
L_57 ,
V_9 , V_127 -> V_130 , V_127 -> V_19 ,
V_131 , V_127 -> V_132 ) ;
F_71 ( V_13 ) ;
return - V_24 ;
}
V_8 -> V_13 [ V_125 ] = V_13 ;
if ( F_76 ( F_28 ( V_13 -> V_21 ) != V_127 -> V_130 ||
F_29 ( V_13 -> V_21 ) != V_127 -> V_19 ) ) {
F_32 ( V_23 ,
L_58
L_59 ,
V_131 , V_127 -> V_132 ,
V_9 , F_28 ( V_13 -> V_21 ) , F_29 ( V_13 -> V_21 ) ,
V_9 , V_127 -> V_130 , V_127 -> V_19 ) ;
return - V_24 ;
}
if ( F_76 ( F_77 ( V_13 ) < 0 ) ) {
F_32 ( V_23 ,
L_60
L_57 ,
V_9 , V_127 -> V_130 , V_127 -> V_19 ,
V_131 , V_127 -> V_132 ) ;
return - V_24 ;
}
F_14 ( L_61 ,
V_9 , V_127 -> V_130 ,
V_127 -> V_19 ,
V_131 , V_127 -> V_132 ) ;
F_78 ( V_13 ) ;
* V_123 = V_13 ;
return 0 ;
}
static int F_79 ( T_2 * V_124 )
{
int V_20 , V_135 ;
struct V_17 * V_13 = NULL ;
const struct V_10 * V_11 = V_136 ;
while ( V_11 && V_11 -> V_128 ) {
for ( V_20 = 0 ; V_20 < V_11 -> V_14 ; V_20 ++ ) {
V_13 = NULL ;
do {
V_135 = F_74 ( & V_13 , V_124 ,
V_11 , V_20 ) ;
if ( V_135 < 0 ) {
if ( V_20 == 0 ) {
V_20 = V_11 -> V_14 ;
break;
}
F_72 () ;
return - V_24 ;
}
} while ( V_13 );
}
V_11 ++ ;
}
return 0 ;
}
static int F_80 ( struct V_26 * V_27 ,
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
F_14 ( L_62 ,
V_8 -> V_9 ,
F_28 ( V_13 -> V_21 ) , F_29 ( V_13 -> V_21 ) ,
V_13 ) ;
}
if ( ! V_29 -> V_90 || ! V_29 -> V_84 || ! V_29 -> V_94 ||
! V_29 -> V_65 || ! V_29 -> V_47 || ! V_29 -> V_50 ||
! V_29 -> V_56 )
goto V_137;
for ( V_20 = 0 ; V_20 < V_60 ; V_20 ++ ) {
if ( ! V_29 -> V_65 [ V_20 ] )
goto V_137;
}
return 0 ;
V_137:
F_32 ( V_23 , L_63 ) ;
return - V_24 ;
error:
F_32 ( V_23 , L_64
L_65 ,
V_18 , V_19 ) ;
return - V_3 ;
}
static void F_81 ( struct V_26 * V_27 ,
const struct V_138 * V_139 )
{
struct V_26 * V_106 ;
struct V_28 * V_29 = V_27 -> V_30 ;
enum V_140 V_141 ;
char * type , * V_142 , V_105 [ 256 ] ;
bool V_143 = F_82 ( V_139 -> V_144 , 0 , 0 ) ;
bool V_145 = F_82 ( V_139 -> V_146 , 62 , 62 ) ;
bool V_147 = F_82 ( V_139 -> V_146 , 61 , 61 ) ;
bool V_148 = F_82 ( V_139 -> V_146 , 56 , 56 ) ;
T_1 V_149 = F_82 ( V_139 -> V_146 , 38 , 52 ) ;
T_1 V_150 = F_82 ( V_139 -> V_146 , 16 , 31 ) ;
T_1 V_151 = F_82 ( V_139 -> V_146 , 0 , 15 ) ;
T_1 V_66 = F_82 ( V_139 -> V_146 , 0 , 3 ) ;
T_1 V_152 = F_82 ( V_139 -> V_146 , 4 , 6 ) ;
long V_102 , V_153 ;
T_2 V_103 , V_101 ;
int V_135 , V_32 ;
char * V_104 = NULL ;
if ( V_147 ) {
if ( V_143 ) {
type = L_66 ;
V_141 = V_154 ;
} else {
type = L_67 ;
V_141 = V_155 ;
}
} else {
type = L_68 ;
V_141 = V_156 ;
}
if ( ! ( ( V_151 & 0xef80 ) == 0x80 ) ) {
V_142 = L_69 ;
} else {
switch ( V_152 ) {
case 0 :
V_142 = L_70 ;
break;
case 1 :
V_142 = L_71 ;
break;
case 2 :
V_142 = L_72 ;
break;
case 3 :
V_142 = L_73 ;
break;
case 4 :
V_142 = L_74 ;
break;
default:
V_142 = L_75 ;
break;
}
}
V_135 = F_68 ( V_27 , V_139 -> V_100 , & V_101 ,
& V_102 , & V_103 , & V_104 , V_105 ) ;
if ( V_135 < 0 )
goto V_157;
V_106 = F_67 ( V_101 ) ;
if ( ! V_106 ) {
strcpy ( V_105 , L_76 ) ;
goto V_157;
}
V_27 = V_106 ;
V_29 = V_27 -> V_30 ;
V_153 = F_83 ( & V_102 , V_60 ) ;
if ( V_103 < 4 )
V_32 = 0 ;
else if ( V_103 < 8 )
V_32 = 1 ;
else
V_32 = 2 ;
snprintf ( V_105 , sizeof( V_105 ) ,
L_77 ,
V_149 ,
V_145 ? L_78 : L_39 ,
( V_147 && V_148 ) ? L_79 : L_39 ,
V_104 ,
V_150 , V_151 ,
V_101 ,
V_102 ,
V_103 ) ;
F_14 ( L_80 , V_105 ) ;
F_84 ( V_141 , V_27 ,
V_139 -> V_100 >> V_158 , V_139 -> V_100 & ~ V_159 , 0 ,
V_66 , V_32 , - 1 ,
V_142 , V_105 , V_139 ) ;
return;
V_157:
F_84 ( V_141 , V_27 , 0 , 0 , 0 ,
- 1 , - 1 , - 1 ,
V_105 , L_39 , V_139 ) ;
}
static void F_85 ( struct V_26 * V_27 )
{
struct V_28 * V_29 = V_27 -> V_30 ;
int V_20 ;
unsigned V_160 = 0 ;
struct V_138 * V_139 ;
F_86 () ;
V_160 = ( V_29 -> V_161 + V_162 - V_29 -> V_163 )
% V_162 ;
if ( ! V_160 )
return;
V_139 = V_29 -> V_164 ;
if ( V_29 -> V_163 + V_160 > V_162 ) {
unsigned V_165 = V_162 - V_29 -> V_163 ;
memcpy ( V_139 , & V_29 -> V_166 [ V_29 -> V_163 ] , sizeof( * V_139 ) * V_165 ) ;
F_87 () ;
V_29 -> V_163 = 0 ;
V_160 -= V_165 ;
V_139 += V_165 ;
}
memcpy ( V_139 , & V_29 -> V_166 [ V_29 -> V_163 ] , sizeof( * V_139 ) * V_160 ) ;
F_87 () ;
V_29 -> V_163 += V_160 ;
F_86 () ;
if ( V_29 -> V_167 ) {
F_32 ( V_23 , L_81 ,
V_29 -> V_167 ) ;
F_87 () ;
V_29 -> V_167 = 0 ;
}
for ( V_20 = 0 ; V_20 < V_160 ; V_20 ++ )
F_81 ( V_27 , & V_29 -> V_164 [ V_20 ] ) ;
}
static int F_88 ( struct V_168 * V_169 , unsigned long V_170 ,
void * V_171 )
{
struct V_138 * V_138 = (struct V_138 * ) V_171 ;
struct V_26 * V_27 ;
struct V_28 * V_29 ;
V_27 = F_67 ( V_138 -> V_172 ) ;
if ( ! V_27 )
return V_173 ;
V_29 = V_27 -> V_30 ;
if ( ( V_138 -> V_146 & 0xefff ) >> 7 != 1 )
return V_174 ;
F_89 ( L_82 ) ;
F_89 ( L_83 ,
V_138 -> V_175 , V_138 -> V_144 , V_138 -> V_176 , V_138 -> V_146 ) ;
F_89 ( L_84 , V_138 -> V_177 ) ;
F_89 ( L_85 , V_138 -> V_100 ) ;
F_89 ( L_86 , V_138 -> V_178 ) ;
F_89 ( L_87 ,
V_138 -> V_179 , V_138 -> V_180 , V_138 -> time ,
V_138 -> V_172 , V_138 -> V_181 ) ;
if ( F_90 ( V_138 -> V_182 ) . V_183 != V_29 -> V_8 -> V_46 )
return V_174 ;
F_86 () ;
if ( ( V_29 -> V_161 + 1 ) % V_162 == V_29 -> V_163 ) {
F_87 () ;
V_29 -> V_167 ++ ;
return V_174 ;
}
memcpy ( & V_29 -> V_166 [ V_29 -> V_161 ] , V_138 , sizeof( * V_138 ) ) ;
F_87 () ;
V_29 -> V_161 = ( V_29 -> V_161 + 1 ) % V_162 ;
if ( V_138 -> V_144 & 1 )
F_85 ( V_27 ) ;
return V_184 ;
}
static void F_91 ( struct V_8 * V_8 )
{
struct V_26 * V_27 = V_8 -> V_27 ;
struct V_28 * V_29 ;
if ( F_76 ( ! V_27 || ! V_27 -> V_30 ) ) {
F_14 ( L_88 __FILE__ L_89 ,
V_120 , & V_8 -> V_13 [ 0 ] -> V_130 ) ;
F_32 ( V_23 , L_90 ) ;
return;
}
V_29 = V_27 -> V_30 ;
F_14 ( L_88 __FILE__ L_91 ,
V_120 , V_27 , & V_8 -> V_13 [ 0 ] -> V_130 ) ;
F_92 ( V_27 -> V_130 ) ;
F_30 ( L_92 , V_27 -> V_185 ) ;
F_23 ( V_27 -> V_185 ) ;
F_93 ( V_27 ) ;
V_8 -> V_27 = NULL ;
}
static int F_94 ( struct V_8 * V_8 )
{
struct V_26 * V_27 ;
struct V_186 V_62 [ 2 ] ;
struct V_28 * V_29 ;
int V_135 ;
V_135 = F_31 ( V_8 -> V_9 ) ;
if ( F_76 ( V_135 < 0 ) )
return V_135 ;
V_62 [ 0 ] . type = V_187 ;
V_62 [ 0 ] . V_35 = V_60 ;
V_62 [ 0 ] . V_188 = false ;
V_62 [ 1 ] . type = V_189 ;
V_62 [ 1 ] . V_35 = V_190 ;
V_62 [ 1 ] . V_188 = true ;
V_27 = F_95 ( V_8 -> V_46 , F_42 ( V_62 ) , V_62 ,
sizeof( * V_29 ) ) ;
if ( F_76 ( ! V_27 ) )
return - V_134 ;
F_14 ( L_88 __FILE__ L_91 ,
V_120 , V_27 , & V_8 -> V_13 [ 0 ] -> V_130 ) ;
V_29 = V_27 -> V_30 ;
memset ( V_29 , 0 , sizeof( * V_29 ) ) ;
V_29 -> V_8 = V_8 ;
V_8 -> V_27 = V_27 ;
V_27 -> V_191 = V_192 ;
V_27 -> V_193 = V_194 ;
V_27 -> V_195 = V_194 ;
V_27 -> V_196 = L_93 ;
V_27 -> V_197 = V_198 ;
V_27 -> V_185 = F_96 ( V_12 , L_94 , V_27 -> V_199 ) ;
V_27 -> V_200 = F_97 ( V_8 -> V_13 [ 0 ] ) ;
V_27 -> V_201 = NULL ;
V_27 -> V_202 = F_85 ;
V_135 = F_80 ( V_27 , V_8 ) ;
if ( F_76 ( V_135 < 0 ) )
goto V_203;
F_35 ( V_27 ) ;
F_47 ( V_27 ) ;
V_27 -> V_130 = & V_8 -> V_13 [ 0 ] -> V_130 ;
if ( F_76 ( F_98 ( V_27 ) ) ) {
F_14 ( L_88 __FILE__
L_95 , V_120 ) ;
V_135 = - V_3 ;
goto V_203;
}
return 0 ;
V_203:
F_23 ( V_27 -> V_185 ) ;
F_93 ( V_27 ) ;
V_8 -> V_27 = NULL ;
return V_135 ;
}
static int T_4 F_99 ( struct V_17 * V_13 ,
const struct V_204 * V_205 )
{
int V_135 ;
T_2 V_46 , V_124 = 0 ;
struct V_8 * V_8 ;
F_100 ( & V_206 ) ;
if ( F_76 ( V_207 >= 1 ) ) {
F_101 ( & V_206 ) ;
return - V_24 ;
}
V_207 ++ ;
V_135 = F_79 ( & V_124 ) ;
if ( F_76 ( V_135 < 0 ) )
goto V_203;
V_46 = 0 ;
F_20 (sbridge_dev, &sbridge_edac_list, list) {
F_14 ( L_96 , V_46 , V_46 + 1 , V_124 ) ;
V_8 -> V_46 = V_46 ++ ;
V_135 = F_94 ( V_8 ) ;
if ( F_76 ( V_135 < 0 ) )
goto V_208;
}
F_32 ( V_129 , L_97 ) ;
F_101 ( & V_206 ) ;
return 0 ;
V_208:
F_20 (sbridge_dev, &sbridge_edac_list, list)
F_91 ( V_8 ) ;
F_72 () ;
V_203:
F_101 ( & V_206 ) ;
return V_135 ;
}
static void T_5 F_102 ( struct V_17 * V_13 )
{
struct V_8 * V_8 ;
F_14 ( __FILE__ L_52 , V_120 ) ;
F_100 ( & V_206 ) ;
if ( F_76 ( ! V_207 ) ) {
F_101 ( & V_206 ) ;
return;
}
F_20 (sbridge_dev, &sbridge_edac_list, list)
F_91 ( V_8 ) ;
F_72 () ;
V_207 -- ;
F_101 ( & V_206 ) ;
}
static int T_6 F_103 ( void )
{
int V_209 ;
F_104 ( L_88 __FILE__ L_52 , V_120 ) ;
F_105 () ;
V_209 = F_106 ( & V_210 ) ;
if ( V_209 >= 0 ) {
F_107 ( & V_211 ) ;
return 0 ;
}
F_32 ( V_23 , L_98 ,
V_209 ) ;
return V_209 ;
}
static void T_7 F_108 ( void )
{
F_104 ( L_88 __FILE__ L_52 , V_120 ) ;
F_109 ( & V_210 ) ;
F_110 ( & V_211 ) ;
}
