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
static int F_31 ( const T_2 V_9 , unsigned * V_22 ,
unsigned * V_23 )
{
struct V_17 * V_13 = NULL ;
int V_20 , V_24 ;
T_1 V_25 ;
* V_22 = 0 ;
* V_23 = 0 ;
V_13 = F_27 ( V_9 , 15 , 0 ) ;
if ( ! V_13 ) {
F_32 ( V_26 , L_9
L_10 ,
V_9 , 15 , 0 ) ;
return - V_27 ;
}
F_33 ( V_13 , V_28 , & V_25 ) ;
if ( ! F_34 ( V_25 ) ) {
F_32 ( V_26 , L_11 ) ;
return - V_27 ;
}
for ( V_20 = 0 ; V_20 < V_29 ; V_20 ++ ) {
T_1 V_4 ;
V_13 = F_27 ( V_9 , 15 , 2 + V_20 ) ;
if ( ! V_13 ) {
F_32 ( V_26 , L_9
L_10 ,
V_9 , 15 , 2 + V_20 ) ;
return - V_27 ;
}
( * V_22 ) ++ ;
for ( V_24 = 0 ; V_24 < F_35 ( V_30 ) ; V_24 ++ ) {
F_33 ( V_13 , V_30 [ V_24 ] , & V_4 ) ;
F_30 ( L_12 , V_9 , V_20 , V_24 , V_4 ) ;
if ( F_36 ( V_4 ) )
( * V_23 ) ++ ;
}
}
F_14 ( L_13 ,
* V_22 , * V_23 ) ;
return 0 ;
}
static int F_37 ( const struct V_31 * V_32 )
{
struct V_33 * V_34 = V_32 -> V_35 ;
struct V_36 * V_37 ;
int V_20 , V_24 , V_38 , V_5 , V_6 , V_7 , V_39 , V_40 ;
int V_41 = 0 ;
unsigned long V_42 = 0 ;
T_1 V_1 ;
enum V_43 V_44 ;
enum V_45 V_46 ;
F_33 ( V_34 -> V_47 , V_48 , & V_1 ) ;
V_34 -> V_8 -> V_49 = F_38 ( V_1 ) ;
F_33 ( V_34 -> V_47 , V_50 , & V_1 ) ;
V_34 -> V_8 -> V_51 = F_39 ( V_1 ) ;
F_14 ( L_14 ,
V_34 -> V_8 -> V_52 ,
V_34 -> V_8 -> V_51 ,
V_34 -> V_8 -> V_49 ) ;
F_33 ( V_34 -> V_53 , V_54 , & V_1 ) ;
if ( F_40 ( V_1 ) ) {
F_14 ( L_15 ) ;
V_34 -> V_55 = true ;
} else {
F_14 ( L_16 ) ;
V_34 -> V_55 = false ;
}
F_33 ( V_34 -> V_56 , V_28 , & V_34 -> V_57 . V_25 ) ;
if ( F_41 ( V_34 -> V_57 . V_25 ) ) {
F_14 ( L_17 ) ;
V_44 = V_58 ;
V_34 -> V_59 = true ;
} else {
F_14 ( L_18 ) ;
V_44 = V_60 ;
V_34 -> V_59 = false ;
}
if ( F_42 ( V_34 -> V_57 . V_25 ) ) {
F_14 ( L_19 ) ;
V_34 -> V_61 = true ;
} else {
F_14 ( L_20 ) ;
V_34 -> V_61 = false ;
}
F_33 ( V_34 -> V_56 , V_62 , & V_1 ) ;
if ( F_43 ( V_1 ) ) {
F_14 ( L_21 ) ;
V_46 = V_63 ;
} else {
F_14 ( L_22 ) ;
V_46 = V_64 ;
}
V_38 = 8 ;
for ( V_20 = 0 ; V_20 < V_29 ; V_20 ++ ) {
T_1 V_4 ;
for ( V_24 = 0 ; V_24 < F_35 ( V_30 ) ; V_24 ++ ) {
F_33 ( V_34 -> V_65 [ V_20 ] ,
V_30 [ V_24 ] , & V_4 ) ;
F_44 ( L_23 , V_20 , V_24 , V_4 ) ;
if ( F_36 ( V_4 ) ) {
V_34 -> V_66 [ V_20 ] . V_67 ++ ;
V_5 = F_12 ( V_4 ) ;
V_6 = F_15 ( V_4 ) ;
V_7 = F_17 ( V_4 ) ;
V_39 = ( V_6 * V_7 * V_38 * V_5 ) >> ( 20 - 3 ) ;
V_40 = F_45 ( V_39 ) ;
F_14 ( L_24 ,
V_34 -> V_8 -> V_52 , V_20 , V_24 ,
V_39 , V_40 ,
V_38 , V_5 , V_6 , V_7 ) ;
V_37 = & V_32 -> V_23 [ V_41 ] ;
V_37 -> V_68 = V_42 ;
V_37 -> V_42 = V_42 + V_40 - 1 ;
V_37 -> V_69 = 0UL ;
V_37 -> V_70 = V_40 ;
V_37 -> V_71 = 32 ;
V_37 -> V_72 = V_41 ;
V_37 -> V_73 = ( V_38 == 8 ) ? V_74 : V_75 ;
V_37 -> V_76 = 0 ;
V_37 -> V_77 = 0 ;
V_37 -> V_46 = V_46 ;
V_37 -> V_78 = V_44 ;
V_37 -> V_79 = 1 ;
V_37 -> V_22 [ 0 ] . V_80 = V_20 ;
V_37 -> V_22 [ 0 ] . V_76 = 0 ;
V_34 -> V_81 [ V_20 ] [ V_24 ] = V_41 ;
snprintf ( V_37 -> V_22 [ 0 ] . V_82 ,
sizeof( V_37 -> V_22 [ 0 ] . V_82 ) ,
L_25 ,
V_34 -> V_8 -> V_49 , V_20 , V_24 ) ;
V_42 += V_40 ;
V_41 ++ ;
}
}
}
return 0 ;
}
static void F_46 ( const struct V_31 * V_32 )
{
struct V_33 * V_34 = V_32 -> V_35 ;
int V_20 , V_24 , V_83 , V_84 , V_85 , V_86 ;
T_1 V_1 ;
T_3 V_87 , V_88 = 0 ;
T_3 V_89 ;
T_1 V_90 ;
F_33 ( V_34 -> V_91 , V_92 ,
& V_1 ) ;
V_34 -> V_93 = F_47 ( V_1 ) ;
V_89 = ( 1 + V_34 -> V_93 ) >> 20 ;
F_14 ( L_26 ,
V_89 / 1000 , V_89 % 1000 , ( T_3 ) V_34 -> V_93 ) ;
F_33 ( V_34 -> V_91 , V_94 ,
& V_1 ) ;
V_34 -> V_95 = F_48 ( V_1 ) ;
V_89 = ( 1 + V_34 -> V_95 ) >> 20 ;
F_14 ( L_27 ,
V_89 / 1000 , V_89 % 1000 , ( T_3 ) V_34 -> V_95 ) ;
V_88 = 0 ;
for ( V_84 = 0 ; V_84 < V_96 ; V_84 ++ ) {
F_33 ( V_34 -> V_97 , V_98 [ V_84 ] ,
& V_1 ) ;
V_87 = F_49 ( V_1 ) ;
if ( ! F_50 ( V_1 ) )
continue;
if ( V_87 <= V_88 )
break;
V_89 = ( V_87 + 1 ) >> 20 ;
F_14 ( L_28 ,
V_84 ,
F_1 ( V_1 ) ,
V_89 / 1000 , V_89 % 1000 ,
( ( T_3 ) V_89 ) << 20L ,
F_51 ( V_1 ) ? L_29 : L_30 ,
V_1 ) ;
V_88 = V_87 ;
F_33 ( V_34 -> V_97 , V_99 [ V_84 ] ,
& V_1 ) ;
V_86 = F_3 ( V_1 , 0 ) ;
for ( V_24 = 0 ; V_24 < 8 ; V_24 ++ ) {
if ( V_24 > 0 && V_86 == F_3 ( V_1 , V_24 ) )
break;
F_14 ( L_31 ,
V_84 , V_24 , F_3 ( V_1 , V_24 ) ) ;
}
}
V_88 = 0 ;
for ( V_85 = 0 ; V_85 < V_100 ; V_85 ++ ) {
F_33 ( V_34 -> V_101 , V_102 [ V_85 ] ,
& V_1 ) ;
V_87 = F_52 ( V_1 ) ;
if ( V_87 <= V_88 )
break;
V_89 = ( V_87 + 1 ) >> 20 ;
F_14 ( L_32 ,
V_85 , V_89 / 1000 , V_89 % 1000 ,
( ( T_3 ) V_89 ) << 20L ,
( T_1 ) F_53 ( V_1 ) ,
( T_1 ) F_54 ( V_1 ) ,
( T_1 ) F_55 ( V_1 ) ,
( T_1 ) F_56 ( V_1 ) ,
( T_1 ) F_57 ( V_1 ) ,
( T_1 ) F_58 ( V_1 ) ,
V_1 ) ;
V_88 = V_89 ;
}
for ( V_20 = 0 ; V_20 < V_29 ; V_20 ++ ) {
if ( ! V_34 -> V_66 [ V_20 ] . V_67 )
continue;
for ( V_24 = 0 ; V_24 < V_85 ; V_24 ++ ) {
F_33 ( V_34 -> V_65 [ V_20 ] ,
V_103 [ V_24 ] ,
& V_1 ) ;
V_89 = F_59 ( V_1 ) >> 20 ;
F_14 ( L_33 ,
V_20 , V_24 ,
V_89 / 1000 , V_89 % 1000 ,
( ( T_3 ) V_89 ) << 20L ,
V_1 ) ;
}
}
for ( V_20 = 0 ; V_20 < V_29 ; V_20 ++ ) {
if ( ! V_34 -> V_66 [ V_20 ] . V_67 )
continue;
for ( V_24 = 0 ; V_24 < V_104 ; V_24 ++ ) {
F_33 ( V_34 -> V_65 [ V_20 ] ,
V_105 [ V_24 ] ,
& V_1 ) ;
if ( ! F_60 ( V_1 ) )
continue;
V_89 = F_61 ( V_1 ) >> 20 ;
V_90 = 1 << F_62 ( V_1 ) ;
F_14 ( L_34 ,
V_20 , V_24 ,
V_89 / 1000 , V_89 % 1000 ,
( ( T_3 ) V_89 ) << 20L ,
V_90 ,
V_1 ) ;
for ( V_83 = 0 ; V_83 < V_90 ; V_83 ++ ) {
F_33 ( V_34 -> V_65 [ V_20 ] ,
V_106 [ V_24 ] [ V_83 ] ,
& V_1 ) ;
V_89 = F_63 ( V_1 ) << 6 ;
F_14 ( L_35 ,
V_20 , V_24 , V_83 ,
V_89 / 1000 , V_89 % 1000 ,
( ( T_3 ) V_89 ) << 20L ,
( T_1 ) F_64 ( V_1 ) ,
V_1 ) ;
}
}
}
}
struct V_31 * F_65 ( T_2 V_51 )
{
struct V_8 * V_8 ;
F_20 (sbridge_dev, &sbridge_edac_list, list) {
if ( V_8 -> V_51 == V_51 )
return V_8 -> V_32 ;
}
return NULL ;
}
static int F_66 ( struct V_31 * V_32 ,
T_3 V_107 ,
T_2 * V_108 ,
long * V_109 ,
T_2 * V_110 ,
char * V_111 )
{
struct V_31 * V_112 ;
struct V_33 * V_34 = V_32 -> V_35 ;
char V_113 [ 256 ] ;
int V_114 , V_84 , V_85 , V_115 , V_116 ;
int V_86 , V_117 , V_118 ;
int V_119 ;
unsigned V_120 [ V_121 ] ;
T_1 V_1 ;
T_2 V_122 , V_123 ;
T_1 V_124 ;
T_1 V_90 ;
T_3 V_125 , V_126 , V_87 , V_88 = 0 ;
if ( ( V_107 > ( T_3 ) V_34 -> V_93 ) && ( V_107 < ( 1L << 32 ) ) ) {
sprintf ( V_113 , L_36 , V_107 ) ;
F_67 ( V_32 , V_113 ) ;
return - V_3 ;
}
if ( V_107 >= ( T_3 ) V_34 -> V_95 ) {
sprintf ( V_113 , L_37 , V_107 ) ;
F_67 ( V_32 , V_113 ) ;
return - V_3 ;
}
for ( V_84 = 0 ; V_84 < V_96 ; V_84 ++ ) {
F_33 ( V_34 -> V_97 , V_98 [ V_84 ] ,
& V_1 ) ;
if ( ! F_50 ( V_1 ) )
continue;
V_87 = F_49 ( V_1 ) ;
if ( V_87 <= V_88 ) {
sprintf ( V_113 , L_38 ) ;
F_67 ( V_32 , V_113 ) ;
return - V_3 ;
}
if ( V_107 <= V_87 )
break;
V_88 = V_87 ;
}
if ( V_84 == V_96 ) {
sprintf ( V_113 , L_38 ) ;
F_67 ( V_32 , V_113 ) ;
return - V_3 ;
}
V_111 = F_1 ( V_1 ) ;
V_119 = F_51 ( V_1 ) ;
F_33 ( V_34 -> V_97 , V_99 [ V_84 ] ,
& V_1 ) ;
V_86 = F_3 ( V_1 , 0 ) ;
for ( V_115 = 0 ; V_115 < 8 ; V_115 ++ ) {
if ( V_115 > 0 && V_86 == F_3 ( V_1 , V_115 ) )
break;
V_120 [ V_115 ] = F_3 ( V_1 , V_115 ) ;
F_14 ( L_39 ,
V_115 , V_120 [ V_115 ] ) ;
}
F_14 ( L_40 ,
V_34 -> V_8 -> V_52 ,
V_84 ,
V_107 ,
V_87 ,
V_115 + 7 ,
F_51 ( V_1 ) ? L_41 : L_42 ) ;
if ( V_119 )
V_117 = ( ( V_107 >> 6 ) ^ ( V_107 >> 16 ) ) & 7 ;
else
V_117 = ( V_107 >> 6 ) & 7 ;
switch ( V_115 ) {
case 1 :
V_117 = 0 ;
break;
case 2 :
V_117 = V_117 & 1 ;
break;
case 4 :
V_117 = V_117 & 3 ;
break;
case 8 :
break;
default:
sprintf ( V_113 , L_43 ) ;
F_67 ( V_32 , V_113 ) ;
return - V_3 ;
}
* V_108 = V_120 [ V_117 ] ;
F_14 ( L_44 ,
V_117 , V_115 , * V_108 ) ;
V_112 = F_65 ( * V_108 ) ;
if ( ! V_112 ) {
sprintf ( V_113 , L_45 ,
* V_108 ) ;
F_67 ( V_32 , V_113 ) ;
return - V_3 ;
}
V_32 = V_112 ;
V_34 = V_32 -> V_35 ;
V_88 = 0 ;
for ( V_85 = 0 ; V_85 < V_100 ; V_85 ++ ) {
F_33 ( V_34 -> V_101 , V_102 [ V_85 ] ,
& V_1 ) ;
V_87 = F_52 ( V_1 ) ;
if ( V_87 <= V_88 ) {
sprintf ( V_113 , L_46 ) ;
F_67 ( V_32 , V_113 ) ;
return - V_3 ;
}
if ( V_107 <= V_87 )
break;
V_88 = V_87 ;
}
V_122 = F_54 ( V_1 ) + 1 ;
V_123 = F_53 ( V_1 ) + 1 ;
F_33 ( V_34 -> V_65 [ 0 ] ,
V_103 [ V_85 ] ,
& V_124 ) ;
if ( V_122 == 3 )
V_117 = V_107 >> 6 ;
else
V_117 = V_107 >> ( 6 + V_123 ) ;
V_117 = V_117 % V_122 ;
switch ( V_117 ) {
case 0 :
V_118 = F_55 ( V_1 ) ;
break;
case 1 :
V_118 = F_56 ( V_1 ) ;
break;
case 2 :
V_118 = F_57 ( V_1 ) ;
break;
case 3 :
V_118 = F_58 ( V_1 ) ;
break;
default:
sprintf ( V_113 , L_47 ) ;
F_67 ( V_32 , V_113 ) ;
return - V_3 ;
}
* V_109 = 1 << V_118 ;
if ( V_34 -> V_55 ) {
* V_109 |= 1 << ( ( V_118 + 2 ) % 4 ) ;
switch( V_122 ) {
case 2 :
case 4 :
V_116 = 1 << V_123 * ( V_122 >> 1 ) ;
break;
default:
sprintf ( V_113 , L_48 ) ;
F_67 ( V_32 , V_113 ) ;
return - V_3 ;
}
} else
V_116 = ( 1 << V_123 ) * V_122 ;
if ( V_34 -> V_59 )
* V_109 |= 1 << ( ( V_118 + 1 ) % 4 ) ;
V_126 = F_59 ( V_124 ) ;
F_14 ( L_49 ,
V_85 ,
V_107 ,
V_87 ,
( T_1 ) F_53 ( V_1 ) ,
V_122 ,
V_126 ,
V_117 ,
V_118 ,
* V_109 ) ;
if ( V_126 > V_107 ) {
sprintf ( V_113 , L_50 ,
V_126 , V_107 ) ;
F_67 ( V_32 , V_113 ) ;
return - V_3 ;
}
V_107 -= V_126 ;
V_125 = V_107 & 0x7f ;
V_107 >>= 6 ;
V_107 /= V_116 ;
#if 0
addr = addr / ch_way;
#endif
V_125 |= V_107 << 6 ;
for ( V_114 = 0 ; V_114 < V_104 ; V_114 ++ ) {
F_33 ( V_34 -> V_65 [ V_118 ] ,
V_105 [ V_114 ] ,
& V_1 ) ;
if ( ! F_60 ( V_1 ) )
continue;
V_87 = F_61 ( V_1 ) ;
F_14 ( L_51 ,
V_114 ,
( V_87 >> 20 ) / 1000 , ( V_87 >> 20 ) % 1000 ,
V_87 ,
1 << F_62 ( V_1 ) ) ;
if ( V_125 <= V_87 )
break;
}
if ( V_114 == V_104 ) {
sprintf ( V_113 , L_52 ,
V_125 ) ;
F_67 ( V_32 , V_113 ) ;
return - V_3 ;
}
V_90 = F_62 ( V_1 ) ;
if ( V_34 -> V_61 )
V_117 = ( V_125 >> 6 ) ;
else
V_117 = ( V_125 >> 13 ) ;
V_117 %= 1 << V_90 ;
F_33 ( V_34 -> V_65 [ V_118 ] ,
V_106 [ V_114 ] [ V_117 ] ,
& V_1 ) ;
* V_110 = F_64 ( V_1 ) ;
F_14 ( L_53 ,
V_114 ,
V_125 ,
V_87 ,
V_90 ,
V_117 ) ;
return 0 ;
}
static void F_68 ( struct V_8 * V_8 )
{
int V_20 ;
F_14 ( __FILE__ L_54 , V_127 ) ;
for ( V_20 = 0 ; V_20 < V_8 -> V_14 ; V_20 ++ ) {
struct V_17 * V_13 = V_8 -> V_13 [ V_20 ] ;
if ( ! V_13 )
continue;
F_14 ( L_55 ,
V_13 -> V_9 -> V_128 ,
F_28 ( V_13 -> V_21 ) , F_29 ( V_13 -> V_21 ) ) ;
F_69 ( V_13 ) ;
}
}
static void F_70 ( void )
{
struct V_8 * V_8 , * V_129 ;
F_71 (sbridge_dev, tmp, &sbridge_edac_list, list) {
F_68 ( V_8 ) ;
F_25 ( V_8 ) ;
}
}
static int F_72 ( struct V_17 * * V_130 ,
T_2 * V_131 ,
const struct V_10 * V_11 ,
const unsigned V_132 )
{
struct V_8 * V_8 ;
const struct V_133 * V_134 = & V_11 -> V_135 [ V_132 ] ;
struct V_17 * V_13 = NULL ;
T_2 V_9 = 0 ;
F_32 ( V_136 ,
L_56 ,
V_134 -> V_137 , V_134 -> V_19 ,
V_138 , V_134 -> V_139 ) ;
V_13 = F_73 ( V_138 ,
V_134 -> V_139 , * V_130 ) ;
if ( ! V_13 ) {
if ( * V_130 ) {
* V_130 = V_13 ;
return 0 ;
}
if ( V_134 -> V_140 )
return 0 ;
if ( V_132 == 0 )
return - V_27 ;
F_32 ( V_136 ,
L_57 ,
V_134 -> V_137 , V_134 -> V_19 ,
V_138 , V_134 -> V_139 ) ;
return - V_27 ;
}
V_9 = V_13 -> V_9 -> V_128 ;
V_8 = F_19 ( V_9 ) ;
if ( ! V_8 ) {
V_8 = F_21 ( V_9 , V_11 ) ;
if ( ! V_8 ) {
F_69 ( V_13 ) ;
return - V_141 ;
}
( * V_131 ) ++ ;
}
if ( V_8 -> V_13 [ V_132 ] ) {
F_32 ( V_26 ,
L_58
L_59 ,
V_9 , V_134 -> V_137 , V_134 -> V_19 ,
V_138 , V_134 -> V_139 ) ;
F_69 ( V_13 ) ;
return - V_27 ;
}
V_8 -> V_13 [ V_132 ] = V_13 ;
if ( F_74 ( F_28 ( V_13 -> V_21 ) != V_134 -> V_137 ||
F_29 ( V_13 -> V_21 ) != V_134 -> V_19 ) ) {
F_32 ( V_26 ,
L_60
L_61 ,
V_138 , V_134 -> V_139 ,
V_9 , F_28 ( V_13 -> V_21 ) , F_29 ( V_13 -> V_21 ) ,
V_9 , V_134 -> V_137 , V_134 -> V_19 ) ;
return - V_27 ;
}
if ( F_74 ( F_75 ( V_13 ) < 0 ) ) {
F_32 ( V_26 ,
L_62
L_59 ,
V_9 , V_134 -> V_137 , V_134 -> V_19 ,
V_138 , V_134 -> V_139 ) ;
return - V_27 ;
}
F_14 ( L_63 ,
V_9 , V_134 -> V_137 ,
V_134 -> V_19 ,
V_138 , V_134 -> V_139 ) ;
F_76 ( V_13 ) ;
* V_130 = V_13 ;
return 0 ;
}
static int F_77 ( T_2 * V_131 )
{
int V_20 , V_142 ;
struct V_17 * V_13 = NULL ;
const struct V_10 * V_11 = V_143 ;
while ( V_11 && V_11 -> V_135 ) {
for ( V_20 = 0 ; V_20 < V_11 -> V_14 ; V_20 ++ ) {
V_13 = NULL ;
do {
V_142 = F_72 ( & V_13 , V_131 ,
V_11 , V_20 ) ;
if ( V_142 < 0 ) {
if ( V_20 == 0 ) {
V_20 = V_11 -> V_14 ;
break;
}
F_70 () ;
return - V_27 ;
}
} while ( V_13 );
}
V_11 ++ ;
}
return 0 ;
}
static int F_78 ( struct V_31 * V_32 ,
struct V_8 * V_8 )
{
struct V_33 * V_34 = V_32 -> V_35 ;
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
V_34 -> V_97 = V_13 ;
break;
case 7 :
V_34 -> V_91 = V_13 ;
break;
default:
goto error;
}
break;
case 13 :
switch ( V_19 ) {
case 6 :
V_34 -> V_47 = V_13 ;
break;
default:
goto error;
}
break;
case 14 :
switch ( V_19 ) {
case 0 :
V_34 -> V_101 = V_13 ;
break;
default:
goto error;
}
break;
case 15 :
switch ( V_19 ) {
case 0 :
V_34 -> V_56 = V_13 ;
break;
case 1 :
V_34 -> V_53 = V_13 ;
break;
case 2 :
case 3 :
case 4 :
case 5 :
V_34 -> V_65 [ V_19 - 2 ] = V_13 ;
break;
default:
goto error;
}
break;
case 17 :
switch ( V_19 ) {
case 0 :
V_34 -> V_144 = V_13 ;
break;
default:
goto error;
}
break;
default:
goto error;
}
F_14 ( L_64 ,
V_8 -> V_9 ,
F_28 ( V_13 -> V_21 ) , F_29 ( V_13 -> V_21 ) ,
V_13 ) ;
}
if ( ! V_34 -> V_97 || ! V_34 -> V_91 || ! V_34 -> V_101 ||
! V_34 -> V_65 || ! V_34 -> V_53 || ! V_34 -> V_56 ||
! V_34 -> V_144 )
goto V_145;
for ( V_20 = 0 ; V_20 < V_29 ; V_20 ++ ) {
if ( ! V_34 -> V_65 [ V_20 ] )
goto V_145;
}
return 0 ;
V_145:
F_32 ( V_26 , L_65 ) ;
return - V_27 ;
error:
F_32 ( V_26 , L_66
L_67 ,
V_18 , V_19 ) ;
return - V_3 ;
}
static void F_79 ( struct V_31 * V_32 ,
const struct V_146 * V_147 )
{
struct V_31 * V_112 ;
struct V_33 * V_34 = V_32 -> V_35 ;
char * type , * V_148 , * V_113 , * V_149 ;
bool V_150 = F_80 ( V_147 -> V_151 , 0 , 0 ) ;
bool V_152 = F_80 ( V_147 -> V_153 , 62 , 62 ) ;
bool V_154 = F_80 ( V_147 -> V_153 , 61 , 61 ) ;
bool V_155 = F_80 ( V_147 -> V_153 , 56 , 56 ) ;
T_1 V_156 = F_80 ( V_147 -> V_153 , 38 , 52 ) ;
T_1 V_157 = F_80 ( V_147 -> V_153 , 16 , 31 ) ;
T_1 V_158 = F_80 ( V_147 -> V_153 , 0 , 15 ) ;
T_1 V_66 = F_80 ( V_147 -> V_153 , 0 , 3 ) ;
T_1 V_159 = F_80 ( V_147 -> V_153 , 4 , 6 ) ;
long V_109 , V_160 ;
T_2 V_110 , V_108 ;
int V_41 , V_142 , V_161 ;
char * V_111 = L_68 ;
if ( V_150 )
type = L_69 ;
else
type = L_70 ;
if ( ! ( ( V_158 & 0xef80 ) == 0x80 ) ) {
V_148 = L_71 ;
} else {
switch ( V_159 ) {
case 0 :
V_148 = L_72 ;
break;
case 1 :
V_148 = L_73 ;
break;
case 2 :
V_148 = L_74 ;
break;
case 3 :
V_148 = L_75 ;
break;
case 4 :
V_148 = L_76 ;
break;
default:
V_148 = L_77 ;
break;
}
}
V_142 = F_66 ( V_32 , V_147 -> V_107 , & V_108 ,
& V_109 , & V_110 , V_111 ) ;
if ( V_142 < 0 )
return;
V_112 = F_65 ( V_108 ) ;
if ( ! V_112 ) {
F_67 ( V_32 , L_78 ) ;
return;
}
V_32 = V_112 ;
V_34 = V_32 -> V_35 ;
V_160 = F_81 ( & V_109 , V_29 ) ;
if ( V_110 < 4 )
V_161 = 0 ;
else if ( V_110 < 8 )
V_161 = 1 ;
else
V_161 = 2 ;
V_41 = V_34 -> V_81 [ V_160 ] [ V_161 ] ;
if ( V_154 && V_155 )
V_149 = L_79 ;
else
V_149 = L_41 ;
V_113 = F_82 ( V_162 ,
L_80
L_81 ,
V_156 ,
V_111 ,
V_148 ,
type ,
V_149 ,
V_152 ? L_82 : L_41 ,
V_147 -> V_163 ,
V_157 , V_158 ,
V_66 ,
( long long ) V_147 -> V_107 ,
V_108 ,
V_160 ,
V_109 ,
V_110 ) ;
F_14 ( L_83 , V_113 ) ;
if ( V_154 )
F_83 ( V_32 , V_41 , 0 , 0 , V_113 ) ;
else
F_84 ( V_32 , V_41 , 0 , V_113 ) ;
F_23 ( V_113 ) ;
}
static void F_85 ( struct V_31 * V_32 )
{
struct V_33 * V_34 = V_32 -> V_35 ;
int V_20 ;
unsigned V_164 = 0 ;
struct V_146 * V_147 ;
F_86 () ;
V_164 = ( V_34 -> V_165 + V_166 - V_34 -> V_167 )
% V_166 ;
if ( ! V_164 )
return;
V_147 = V_34 -> V_168 ;
if ( V_34 -> V_167 + V_164 > V_166 ) {
unsigned V_169 = V_166 - V_34 -> V_167 ;
memcpy ( V_147 , & V_34 -> V_170 [ V_34 -> V_167 ] , sizeof( * V_147 ) * V_169 ) ;
F_87 () ;
V_34 -> V_167 = 0 ;
V_164 -= V_169 ;
V_147 += V_169 ;
}
memcpy ( V_147 , & V_34 -> V_170 [ V_34 -> V_167 ] , sizeof( * V_147 ) * V_164 ) ;
F_87 () ;
V_34 -> V_167 += V_164 ;
F_86 () ;
if ( V_34 -> V_171 ) {
F_32 ( V_26 , L_84 ,
V_34 -> V_171 ) ;
F_87 () ;
V_34 -> V_171 = 0 ;
}
for ( V_20 = 0 ; V_20 < V_164 ; V_20 ++ )
F_79 ( V_32 , & V_34 -> V_168 [ V_20 ] ) ;
}
static int F_88 ( struct V_172 * V_173 , unsigned long V_174 ,
void * V_175 )
{
struct V_146 * V_146 = (struct V_146 * ) V_175 ;
struct V_31 * V_32 ;
struct V_33 * V_34 ;
V_32 = F_65 ( V_146 -> V_176 ) ;
if ( ! V_32 )
return V_177 ;
V_34 = V_32 -> V_35 ;
if ( ( V_146 -> V_153 & 0xefff ) >> 7 != 1 )
return V_178 ;
F_89 ( L_85 ) ;
F_89 ( L_86 ,
V_146 -> V_179 , V_146 -> V_151 , V_146 -> V_180 , V_146 -> V_153 ) ;
F_89 ( L_87 , V_146 -> V_181 ) ;
F_89 ( L_88 , V_146 -> V_107 ) ;
F_89 ( L_89 , V_146 -> V_182 ) ;
F_89 ( L_90 ,
V_146 -> V_183 , V_146 -> V_184 , V_146 -> time ,
V_146 -> V_176 , V_146 -> V_185 ) ;
if ( F_90 ( V_146 -> V_163 ) . V_186 != V_34 -> V_8 -> V_52 )
return V_178 ;
F_86 () ;
if ( ( V_34 -> V_165 + 1 ) % V_166 == V_34 -> V_167 ) {
F_87 () ;
V_34 -> V_171 ++ ;
return V_178 ;
}
memcpy ( & V_34 -> V_170 [ V_34 -> V_165 ] , V_146 , sizeof( * V_146 ) ) ;
F_87 () ;
V_34 -> V_165 = ( V_34 -> V_165 + 1 ) % V_166 ;
if ( V_146 -> V_151 & 1 )
F_85 ( V_32 ) ;
return V_187 ;
}
static void F_91 ( struct V_8 * V_8 )
{
struct V_31 * V_32 = V_8 -> V_32 ;
struct V_33 * V_34 ;
if ( F_74 ( ! V_32 || ! V_32 -> V_35 ) ) {
F_14 ( L_91 __FILE__ L_92 ,
V_127 , & V_8 -> V_13 [ 0 ] -> V_137 ) ;
F_32 ( V_26 , L_93 ) ;
return;
}
V_34 = V_32 -> V_35 ;
F_14 ( L_91 __FILE__ L_94 ,
V_127 , V_32 , & V_8 -> V_13 [ 0 ] -> V_137 ) ;
F_92 ( & V_188 ) ;
F_93 ( V_32 -> V_137 ) ;
F_30 ( L_95 , V_32 -> V_189 ) ;
F_23 ( V_32 -> V_189 ) ;
F_94 ( V_32 ) ;
V_8 -> V_32 = NULL ;
}
static int F_95 ( struct V_8 * V_8 )
{
struct V_31 * V_32 ;
struct V_33 * V_34 ;
int V_142 , V_22 , V_23 ;
V_142 = F_31 ( V_8 -> V_9 , & V_22 , & V_23 ) ;
if ( F_74 ( V_142 < 0 ) )
return V_142 ;
V_32 = F_96 ( sizeof( * V_34 ) , V_23 , V_22 , V_8 -> V_52 ) ;
if ( F_74 ( ! V_32 ) )
return - V_141 ;
F_14 ( L_91 __FILE__ L_94 ,
V_127 , V_32 , & V_8 -> V_13 [ 0 ] -> V_137 ) ;
V_34 = V_32 -> V_35 ;
memset ( V_34 , 0 , sizeof( * V_34 ) ) ;
V_34 -> V_8 = V_8 ;
V_8 -> V_32 = V_32 ;
V_32 -> V_190 = V_191 ;
V_32 -> V_192 = V_193 ;
V_32 -> V_194 = V_193 ;
V_32 -> V_195 = L_96 ;
V_32 -> V_196 = V_197 ;
V_32 -> V_189 = F_82 ( V_12 , L_97 , V_32 -> V_198 ) ;
V_32 -> V_199 = F_97 ( V_8 -> V_13 [ 0 ] ) ;
V_32 -> V_200 = NULL ;
V_32 -> V_201 = F_85 ;
V_142 = F_78 ( V_32 , V_8 ) ;
if ( F_74 ( V_142 < 0 ) )
goto V_202;
F_37 ( V_32 ) ;
F_46 ( V_32 ) ;
V_32 -> V_137 = & V_8 -> V_13 [ 0 ] -> V_137 ;
if ( F_74 ( F_98 ( V_32 ) ) ) {
F_14 ( L_91 __FILE__
L_98 , V_127 ) ;
V_142 = - V_3 ;
goto V_202;
}
F_99 ( & V_188 ) ;
return 0 ;
V_202:
F_23 ( V_32 -> V_189 ) ;
F_94 ( V_32 ) ;
V_8 -> V_32 = NULL ;
return V_142 ;
}
static int T_4 F_100 ( struct V_17 * V_13 ,
const struct V_203 * V_204 )
{
int V_142 ;
T_2 V_52 , V_131 = 0 ;
struct V_8 * V_8 ;
F_101 ( & V_205 ) ;
if ( F_74 ( V_206 >= 1 ) ) {
F_102 ( & V_205 ) ;
return - V_27 ;
}
V_206 ++ ;
V_142 = F_77 ( & V_131 ) ;
if ( F_74 ( V_142 < 0 ) )
goto V_202;
V_52 = 0 ;
F_20 (sbridge_dev, &sbridge_edac_list, list) {
F_14 ( L_99 , V_52 , V_52 + 1 , V_131 ) ;
V_8 -> V_52 = V_52 ++ ;
V_142 = F_95 ( V_8 ) ;
if ( F_74 ( V_142 < 0 ) )
goto V_207;
}
F_32 ( V_136 , L_100 ) ;
F_102 ( & V_205 ) ;
return 0 ;
V_207:
F_20 (sbridge_dev, &sbridge_edac_list, list)
F_91 ( V_8 ) ;
F_70 () ;
V_202:
F_102 ( & V_205 ) ;
return V_142 ;
}
static void T_5 F_103 ( struct V_17 * V_13 )
{
struct V_8 * V_8 ;
F_14 ( __FILE__ L_54 , V_127 ) ;
F_101 ( & V_205 ) ;
if ( F_74 ( ! V_206 ) ) {
F_102 ( & V_205 ) ;
return;
}
F_20 (sbridge_dev, &sbridge_edac_list, list)
F_91 ( V_8 ) ;
F_70 () ;
V_206 -- ;
F_102 ( & V_205 ) ;
}
static int T_6 F_104 ( void )
{
int V_208 ;
F_105 ( L_91 __FILE__ L_54 , V_127 ) ;
F_106 () ;
V_208 = F_107 ( & V_209 ) ;
if ( V_208 >= 0 )
return 0 ;
F_32 ( V_26 , L_101 ,
V_208 ) ;
return V_208 ;
}
static void T_7 F_108 ( void )
{
F_105 ( L_91 __FILE__ L_54 , V_127 ) ;
F_109 ( & V_209 ) ;
}
