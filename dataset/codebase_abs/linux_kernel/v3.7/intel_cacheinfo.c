static void T_1
F_1 ( int V_1 , union V_2 * V_3 ,
union V_4 * V_5 ,
union V_6 * V_7 )
{
unsigned V_8 ;
unsigned V_9 , V_10 , V_11 , V_12 ;
union V_13 V_14 , V_15 ;
union V_16 V_17 ;
union V_18 V_19 ;
union V_13 * V_20 = & V_15 ;
V_3 -> V_21 = 0 ;
V_5 -> V_21 = 0 ;
V_7 -> V_21 = 0 ;
F_2 ( 0x80000005 , & V_8 , & V_8 , & V_15 . V_22 , & V_14 . V_22 ) ;
F_2 ( 0x80000006 , & V_8 , & V_8 , & V_17 . V_22 , & V_19 . V_22 ) ;
switch ( V_1 ) {
case 1 :
V_20 = & V_14 ;
case 0 :
if ( ! V_20 -> V_22 )
return;
V_11 = V_23 [ V_20 -> V_11 ] ;
V_9 = V_20 -> V_9 ;
V_10 = V_20 -> V_10 ;
V_12 = V_20 -> V_12 ;
break;
case 2 :
if ( ! V_17 . V_22 )
return;
V_11 = V_23 [ V_17 . V_11 ] ;
V_9 = V_17 . V_9 ;
V_10 = V_17 . V_10 ;
V_12 = F_3 ( V_24 . V_25 ) ;
break;
case 3 :
if ( ! V_19 . V_22 )
return;
V_11 = V_23 [ V_19 . V_11 ] ;
V_9 = V_19 . V_9 ;
V_10 = V_19 . V_10 ;
V_12 = V_19 . V_26 * 512 ;
if ( F_4 ( V_27 ) ) {
V_12 = V_12 >> 1 ;
V_11 = V_11 >> 1 ;
}
break;
default:
return;
}
V_3 -> V_28 . V_29 = 1 ;
V_3 -> V_28 . type = V_30 [ V_1 ] ;
V_3 -> V_28 . V_31 = V_32 [ V_1 ] ;
V_3 -> V_28 . V_33 = 0 ;
V_3 -> V_28 . V_34 = F_3 ( V_24 . V_35 ) - 1 ;
if ( V_11 == 0xffff )
V_3 -> V_28 . V_36 = 1 ;
V_5 -> V_28 . V_37 = V_9 - 1 ;
V_5 -> V_28 . V_38 = V_11 - 1 ;
V_5 -> V_28 . V_39 = V_10 - 1 ;
V_7 -> V_28 . V_40 = ( V_12 * 1024 ) / V_9 /
( V_5 -> V_28 . V_38 + 1 ) - 1 ;
}
static void T_1 F_5 ( struct V_41 * V_42 )
{
struct V_43 * V_19 = & V_42 -> V_18 ;
unsigned int V_44 , V_45 , V_46 , V_47 ;
T_2 V_22 = 0 ;
F_6 ( V_42 -> V_48 , 0x1C4 , & V_22 ) ;
V_19 -> V_49 [ 0 ] = V_44 = ! ( V_22 & F_7 ( 0 ) ) ;
V_19 -> V_49 [ 1 ] = V_45 = ! ( V_22 & F_7 ( 4 ) ) ;
if ( V_50 . V_51 == 0x15 ) {
V_19 -> V_49 [ 0 ] = V_44 += ! ( V_22 & F_7 ( 1 ) ) ;
V_19 -> V_49 [ 1 ] = V_45 += ! ( V_22 & F_7 ( 5 ) ) ;
}
V_19 -> V_49 [ 2 ] = V_46 = ! ( V_22 & F_7 ( 8 ) ) + ! ( V_22 & F_7 ( 9 ) ) ;
V_19 -> V_49 [ 3 ] = V_47 = ! ( V_22 & F_7 ( 12 ) ) + ! ( V_22 & F_7 ( 13 ) ) ;
V_19 -> V_52 = ( F_8 ( F_9 ( V_44 , V_45 , V_46 ) , V_47 ) << 10 ) - 1 ;
}
static void T_1 F_10 ( struct V_53 * V_54 , int V_55 )
{
int V_56 ;
if ( V_55 < 3 )
return;
V_56 = F_11 ( F_12 () ) ;
V_54 -> V_42 = F_13 ( V_56 ) ;
if ( V_54 -> V_42 && ! V_54 -> V_42 -> V_18 . V_52 )
F_5 ( V_54 -> V_42 ) ;
}
int F_14 ( struct V_41 * V_42 , unsigned V_57 )
{
unsigned int V_58 = 0 ;
F_6 ( V_42 -> V_48 , 0x1BC + V_57 * 4 , & V_58 ) ;
if ( V_58 & ( 3UL << 30 ) )
return V_58 & 0xfff ;
return - 1 ;
}
static T_3 F_15 ( struct V_59 * V_54 , char * V_60 ,
unsigned int V_57 )
{
int V_55 ;
if ( ! V_54 -> V_61 . V_42 || ! F_16 ( V_62 ) )
return - V_63 ;
V_55 = F_14 ( V_54 -> V_61 . V_42 , V_57 ) ;
if ( V_55 >= 0 )
return sprintf ( V_60 , L_1 , V_55 ) ;
return sprintf ( V_60 , L_2 ) ;
}
static void F_17 ( struct V_41 * V_42 , int V_64 ,
unsigned V_57 , unsigned long V_65 )
{
int V_66 ;
V_65 |= F_7 ( 30 ) ;
for ( V_66 = 0 ; V_66 < 4 ; V_66 ++ ) {
T_2 V_58 = V_65 | ( V_66 << 20 ) ;
if ( ! V_42 -> V_18 . V_49 [ V_66 ] )
continue;
F_18 ( V_42 -> V_48 , 0x1BC + V_57 * 4 , V_58 ) ;
F_19 ( V_64 ) ;
V_58 |= F_7 ( 31 ) ;
F_18 ( V_42 -> V_48 , 0x1BC + V_57 * 4 , V_58 ) ;
}
}
int F_20 ( struct V_41 * V_42 , int V_64 , unsigned V_57 ,
unsigned long V_55 )
{
int V_67 = 0 ;
V_67 = F_14 ( V_42 , V_57 ) ;
if ( V_67 >= 0 )
return - V_68 ;
if ( V_55 > V_42 -> V_18 . V_52 )
return - V_63 ;
if ( V_55 == F_14 ( V_42 , ! V_57 ) )
return - V_68 ;
F_17 ( V_42 , V_64 , V_57 , V_55 ) ;
return 0 ;
}
static T_3 F_21 ( struct V_59 * V_54 ,
const char * V_60 , T_4 V_69 ,
unsigned int V_57 )
{
unsigned long V_22 = 0 ;
int V_64 , V_70 = 0 ;
if ( ! F_22 ( V_71 ) )
return - V_72 ;
if ( ! V_54 -> V_61 . V_42 || ! F_16 ( V_62 ) )
return - V_63 ;
V_64 = F_23 ( F_24 ( V_54 -> V_73 ) ) ;
if ( F_25 ( V_60 , 10 , & V_22 ) < 0 )
return - V_63 ;
V_70 = F_20 ( V_54 -> V_61 . V_42 , V_64 , V_57 , V_22 ) ;
if ( V_70 ) {
if ( V_70 == - V_68 )
F_26 ( L_3 ,
V_57 ) ;
return V_70 ;
}
return V_69 ;
}
static T_3
F_27 ( struct V_59 * V_54 , char * V_60 , unsigned int V_64 )
{
if ( ! V_54 -> V_61 . V_42 || ! F_16 ( V_74 ) )
return - V_63 ;
return sprintf ( V_60 , L_4 , F_28 ( V_64 ) ) ;
}
static T_3
F_29 ( struct V_59 * V_54 , const char * V_60 , T_4 V_69 ,
unsigned int V_64 )
{
unsigned long V_22 ;
if ( ! F_22 ( V_71 ) )
return - V_72 ;
if ( ! V_54 -> V_61 . V_42 || ! F_16 ( V_74 ) )
return - V_63 ;
if ( F_25 ( V_60 , 16 , & V_22 ) < 0 )
return - V_63 ;
if ( F_30 ( V_64 , V_22 ) )
return - V_63 ;
return V_69 ;
}
static int
T_1 F_31 ( int V_55 ,
struct V_53 * V_54 )
{
union V_2 V_3 ;
union V_4 V_5 ;
union V_6 V_7 ;
unsigned V_75 ;
if ( V_50 . V_76 == V_77 ) {
F_1 ( V_55 , & V_3 , & V_5 , & V_7 ) ;
F_10 ( V_54 , V_55 ) ;
} else {
F_32 ( 4 , V_55 , & V_3 . V_21 , & V_5 . V_21 , & V_7 . V_21 , & V_75 ) ;
}
if ( V_3 . V_28 . type == V_78 )
return - V_79 ;
V_54 -> V_3 = V_3 ;
V_54 -> V_5 = V_5 ;
V_54 -> V_7 = V_7 ;
V_54 -> V_80 = ( V_7 . V_28 . V_40 + 1 ) *
( V_5 . V_28 . V_37 + 1 ) *
( V_5 . V_28 . V_39 + 1 ) *
( V_5 . V_28 . V_38 + 1 ) ;
return 0 ;
}
static int T_1 F_33 ( void )
{
unsigned int V_3 , V_5 , V_7 , V_75 ;
union V_2 V_81 ;
int V_66 = - 1 ;
do {
++ V_66 ;
F_32 ( 4 , V_66 , & V_3 , & V_5 , & V_7 , & V_75 ) ;
V_81 . V_21 = V_3 ;
} while ( V_81 . V_28 . type != V_78 );
return V_66 ;
}
unsigned int T_1 F_34 ( struct V_82 * V_83 )
{
unsigned int V_84 = 0 , V_14 = 0 , V_15 = 0 , V_17 = 0 , V_19 = 0 ;
unsigned int V_85 = 0 , V_86 = 0 ;
unsigned int V_87 = 0 , V_88 = 0 , V_66 ;
unsigned int V_89 = 0 , V_90 = 0 , V_33 , V_91 ;
#ifdef F_35
unsigned int V_64 = V_83 -> V_92 ;
#endif
if ( V_83 -> V_93 > 3 ) {
static int V_94 ;
if ( V_94 == 0 ) {
V_95 = F_33 () ;
V_94 ++ ;
}
for ( V_66 = 0 ; V_66 < V_95 ; V_66 ++ ) {
struct V_53 V_54 ;
int V_96 ;
V_96 = F_31 ( V_66 , & V_54 ) ;
if ( V_96 >= 0 ) {
switch ( V_54 . V_3 . V_28 . V_31 ) {
case 1 :
if ( V_54 . V_3 . V_28 . type ==
V_97 )
V_85 = V_54 . V_80 / 1024 ;
else if ( V_54 . V_3 . V_28 . type ==
V_98 )
V_86 = V_54 . V_80 / 1024 ;
break;
case 2 :
V_87 = V_54 . V_80 / 1024 ;
V_33 = 1 + V_54 . V_3 . V_28 . V_33 ;
V_91 = F_36 ( V_33 ) ;
V_89 = V_83 -> V_99 & ~ ( ( 1 << V_91 ) - 1 ) ;
break;
case 3 :
V_88 = V_54 . V_80 / 1024 ;
V_33 = 1 + V_54 . V_3 . V_28 . V_33 ;
V_91 = F_36 (
V_33 ) ;
V_90 = V_83 -> V_99 & ~ ( ( 1 << V_91 ) - 1 ) ;
break;
default:
break;
}
}
}
}
if ( ( V_95 == 0 || V_83 -> V_51 == 15 ) && V_83 -> V_93 > 1 ) {
int V_100 , V_101 ;
unsigned int V_102 [ 4 ] ;
unsigned char * V_103 = ( unsigned char * ) V_102 ;
int V_104 = 0 ;
if ( V_95 != 0 && V_83 -> V_51 == 15 )
V_104 = 1 ;
V_101 = F_37 ( 2 ) & 0xFF ;
for ( V_66 = 0 ; V_66 < V_101 ; V_66 ++ ) {
F_2 ( 2 , & V_102 [ 0 ] , & V_102 [ 1 ] , & V_102 [ 2 ] , & V_102 [ 3 ] ) ;
for ( V_100 = 0 ; V_100 < 3 ; V_100 ++ )
if ( V_102 [ V_100 ] & ( 1 << 31 ) )
V_102 [ V_100 ] = 0 ;
for ( V_100 = 1 ; V_100 < 16 ; V_100 ++ ) {
unsigned char V_105 = V_103 [ V_100 ] ;
unsigned char V_106 = 0 ;
while ( V_107 [ V_106 ] . V_108 != 0 ) {
if ( V_107 [ V_106 ] . V_108 == V_105 ) {
if ( V_104 && V_107 [ V_106 ] . V_109 != V_110 )
break;
switch ( V_107 [ V_106 ] . V_109 ) {
case V_111 :
V_14 += V_107 [ V_106 ] . V_80 ;
break;
case V_112 :
V_15 += V_107 [ V_106 ] . V_80 ;
break;
case V_113 :
V_17 += V_107 [ V_106 ] . V_80 ;
break;
case V_114 :
V_19 += V_107 [ V_106 ] . V_80 ;
break;
case V_110 :
V_84 += V_107 [ V_106 ] . V_80 ;
break;
}
break;
}
V_106 ++ ;
}
}
}
}
if ( V_85 )
V_15 = V_85 ;
if ( V_86 )
V_14 = V_86 ;
if ( V_87 ) {
V_17 = V_87 ;
#ifdef F_35
F_38 ( V_115 , V_64 ) = V_89 ;
#endif
}
if ( V_88 ) {
V_19 = V_88 ;
#ifdef F_35
F_38 ( V_115 , V_64 ) = V_90 ;
#endif
}
V_83 -> V_25 = V_19 ? V_19 : ( V_17 ? V_17 : ( V_14 + V_15 ) ) ;
return V_17 ;
}
static int T_1 F_39 ( unsigned int V_64 , int V_55 )
{
struct V_59 * V_54 ;
int V_67 , V_66 , V_116 ;
struct V_82 * V_83 = & F_40 ( V_64 ) ;
V_67 = 0 ;
if ( V_55 == 3 ) {
V_67 = 1 ;
F_41 (i, cpu_llc_shared_mask(cpu)) {
if ( ! F_38 ( V_117 , V_66 ) )
continue;
V_54 = F_42 ( V_66 , V_55 ) ;
F_41 (sibling, cpu_llc_shared_mask(cpu)) {
if ( ! F_43 ( V_116 ) )
continue;
F_44 ( V_116 , V_54 -> V_73 ) ;
}
}
} else if ( ( V_83 -> V_51 == 0x15 ) && ( ( V_55 == 1 ) || ( V_55 == 2 ) ) ) {
V_67 = 1 ;
F_41 (i, cpu_sibling_mask(cpu)) {
if ( ! F_38 ( V_117 , V_66 ) )
continue;
V_54 = F_42 ( V_66 , V_55 ) ;
F_41 (sibling, cpu_sibling_mask(cpu)) {
if ( ! F_43 ( V_116 ) )
continue;
F_44 ( V_116 , V_54 -> V_73 ) ;
}
}
}
return V_67 ;
}
static void T_1 F_45 ( unsigned int V_64 , int V_55 )
{
struct V_59 * V_54 , * V_118 ;
unsigned long V_33 ;
int V_91 , V_66 ;
struct V_82 * V_83 = & F_40 ( V_64 ) ;
if ( V_83 -> V_76 == V_77 ) {
if ( F_39 ( V_64 , V_55 ) )
return;
}
V_54 = F_42 ( V_64 , V_55 ) ;
V_33 = 1 + V_54 -> V_61 . V_3 . V_28 . V_33 ;
if ( V_33 == 1 )
F_46 ( V_64 , F_24 ( V_54 -> V_73 ) ) ;
else {
V_91 = F_36 ( V_33 ) ;
F_47 (i) {
if ( F_40 ( V_66 ) . V_99 >> V_91 ==
V_83 -> V_99 >> V_91 ) {
F_46 ( V_66 ,
F_24 ( V_54 -> V_73 ) ) ;
if ( V_66 != V_64 && F_38 ( V_117 , V_66 ) ) {
V_118 =
F_42 ( V_66 , V_55 ) ;
F_46 ( V_64 , F_24 (
V_118 -> V_73 ) ) ;
}
}
}
}
}
static void T_1 F_48 ( unsigned int V_64 , int V_55 )
{
struct V_59 * V_54 , * V_118 ;
int V_116 ;
V_54 = F_42 ( V_64 , V_55 ) ;
F_41 (sibling, to_cpumask(this_leaf->shared_cpu_map)) {
V_118 = F_42 ( V_116 , V_55 ) ;
F_49 ( V_64 ,
F_24 ( V_118 -> V_73 ) ) ;
}
}
static void T_1 F_45 ( unsigned int V_64 , int V_55 )
{
}
static void T_1 F_48 ( unsigned int V_64 , int V_55 )
{
}
static void T_1 F_50 ( unsigned int V_64 )
{
int V_66 ;
for ( V_66 = 0 ; V_66 < V_95 ; V_66 ++ )
F_48 ( V_64 , V_66 ) ;
F_51 ( F_38 ( V_117 , V_64 ) ) ;
F_38 ( V_117 , V_64 ) = NULL ;
}
static void T_1 F_52 ( void * V_119 )
{
int V_100 , * V_96 = V_119 , V_64 = F_12 () ;
for ( V_100 = 0 ; V_100 < V_95 ; V_100 ++ ) {
struct V_59 * V_54 = F_42 ( V_64 , V_100 ) ;
* V_96 = F_31 ( V_100 , & V_54 -> V_61 ) ;
if ( F_53 ( * V_96 < 0 ) ) {
int V_66 ;
for ( V_66 = 0 ; V_66 < V_100 ; V_66 ++ )
F_48 ( V_64 , V_66 ) ;
break;
}
F_45 ( V_64 , V_100 ) ;
}
}
static int T_1 F_54 ( unsigned int V_64 )
{
int V_96 ;
if ( V_95 == 0 )
return - V_120 ;
F_38 ( V_117 , V_64 ) = F_55 (
sizeof( struct V_59 ) * V_95 , V_121 ) ;
if ( F_38 ( V_117 , V_64 ) == NULL )
return - V_122 ;
F_56 ( V_64 , F_52 , & V_96 , true ) ;
if ( V_96 ) {
F_51 ( F_38 ( V_117 , V_64 ) ) ;
F_38 ( V_117 , V_64 ) = NULL ;
}
return V_96 ;
}
static T_3 F_57 ( struct V_59 * V_54 , char * V_60 ,
unsigned int V_64 )
{
return sprintf ( V_60 , L_5 , V_54 -> V_61 . V_80 / 1024 ) ;
}
static T_3 F_58 ( struct V_59 * V_54 ,
int type , char * V_60 )
{
T_5 V_123 = F_59 ( V_60 + V_124 - 1 , V_124 ) - V_60 ;
int V_101 = 0 ;
if ( V_123 > 1 ) {
const struct V_125 * V_126 ;
V_126 = F_24 ( V_54 -> V_73 ) ;
V_101 = type ?
F_60 ( V_60 , V_123 - 2 , V_126 ) :
F_61 ( V_60 , V_123 - 2 , V_126 ) ;
V_60 [ V_101 ++ ] = '\n' ;
V_60 [ V_101 ] = '\0' ;
}
return V_101 ;
}
static inline T_3 F_62 ( struct V_59 * V_1 , char * V_60 ,
unsigned int V_64 )
{
return F_58 ( V_1 , 0 , V_60 ) ;
}
static inline T_3 F_63 ( struct V_59 * V_1 , char * V_60 ,
unsigned int V_64 )
{
return F_58 ( V_1 , 1 , V_60 ) ;
}
static T_3 F_64 ( struct V_59 * V_54 , char * V_60 ,
unsigned int V_64 )
{
switch ( V_54 -> V_61 . V_3 . V_28 . type ) {
case V_97 :
return sprintf ( V_60 , L_6 ) ;
case V_98 :
return sprintf ( V_60 , L_7 ) ;
case V_127 :
return sprintf ( V_60 , L_8 ) ;
default:
return sprintf ( V_60 , L_9 ) ;
}
}
static struct V_128 * * T_1 F_65 ( void )
{
static struct V_128 * * V_129 ;
int V_101 ;
if ( V_129 )
return V_129 ;
V_101 = F_66 ( V_130 ) ;
if ( F_16 ( V_62 ) )
V_101 += 2 ;
if ( F_16 ( V_74 ) )
V_101 += 1 ;
V_129 = F_55 ( V_101 * sizeof ( struct V_128 * ) , V_121 ) ;
if ( V_129 == NULL )
return V_129 = V_130 ;
for ( V_101 = 0 ; V_130 [ V_101 ] ; V_101 ++ )
V_129 [ V_101 ] = V_130 [ V_101 ] ;
if ( F_16 ( V_62 ) ) {
V_129 [ V_101 ++ ] = & V_131 . V_132 ;
V_129 [ V_101 ++ ] = & V_133 . V_132 ;
}
if ( F_16 ( V_74 ) )
V_129 [ V_101 ++ ] = & V_49 . V_132 ;
return V_129 ;
}
static T_3 F_67 ( struct V_134 * V_135 , struct V_128 * V_132 , char * V_60 )
{
struct V_136 * V_137 = F_68 ( V_132 ) ;
struct V_138 * V_54 = F_69 ( V_135 ) ;
T_3 V_67 ;
V_67 = V_137 -> F_67 ?
V_137 -> F_67 ( F_42 ( V_54 -> V_64 , V_54 -> V_55 ) ,
V_60 , V_54 -> V_64 ) :
0 ;
return V_67 ;
}
static T_3 F_70 ( struct V_134 * V_135 , struct V_128 * V_132 ,
const char * V_60 , T_4 V_69 )
{
struct V_136 * V_137 = F_68 ( V_132 ) ;
struct V_138 * V_54 = F_69 ( V_135 ) ;
T_3 V_67 ;
V_67 = V_137 -> F_70 ?
V_137 -> F_70 ( F_42 ( V_54 -> V_64 , V_54 -> V_55 ) ,
V_60 , V_69 , V_54 -> V_64 ) :
0 ;
return V_67 ;
}
static void T_1 F_71 ( unsigned int V_64 )
{
F_51 ( F_38 ( V_139 , V_64 ) ) ;
F_51 ( F_38 ( V_140 , V_64 ) ) ;
F_38 ( V_139 , V_64 ) = NULL ;
F_38 ( V_140 , V_64 ) = NULL ;
F_50 ( V_64 ) ;
}
static int T_1 F_72 ( unsigned int V_64 )
{
int V_70 ;
if ( V_95 == 0 )
return - V_120 ;
V_70 = F_54 ( V_64 ) ;
if ( V_70 )
return V_70 ;
F_38 ( V_139 , V_64 ) =
F_55 ( sizeof( struct V_134 ) , V_121 ) ;
if ( F_53 ( F_38 ( V_139 , V_64 ) == NULL ) )
goto V_141;
F_38 ( V_140 , V_64 ) = F_55 (
sizeof( struct V_138 ) * V_95 , V_121 ) ;
if ( F_53 ( F_38 ( V_140 , V_64 ) == NULL ) )
goto V_141;
return 0 ;
V_141:
F_71 ( V_64 ) ;
return - V_122 ;
}
static int T_1 F_73 ( struct V_142 * V_143 )
{
unsigned int V_64 = V_143 -> V_144 ;
unsigned long V_66 , V_100 ;
struct V_138 * V_145 ;
struct V_59 * V_54 ;
int V_96 ;
V_96 = F_72 ( V_64 ) ;
if ( F_53 ( V_96 < 0 ) )
return V_96 ;
V_96 = F_74 ( F_38 ( V_139 , V_64 ) ,
& V_146 ,
& V_143 -> V_135 , L_10 , L_11 ) ;
if ( V_96 < 0 ) {
F_71 ( V_64 ) ;
return V_96 ;
}
for ( V_66 = 0 ; V_66 < V_95 ; V_66 ++ ) {
V_145 = F_75 ( V_64 , V_66 ) ;
V_145 -> V_64 = V_64 ;
V_145 -> V_55 = V_66 ;
V_54 = F_42 ( V_64 , V_66 ) ;
V_147 . V_130 = V_130 ;
#ifdef F_76
if ( V_54 -> V_61 . V_42 )
V_147 . V_130 = F_65 () ;
#endif
V_96 = F_74 ( & ( V_145 -> V_135 ) ,
& V_147 ,
F_38 ( V_139 , V_64 ) ,
L_12 , V_66 ) ;
if ( F_53 ( V_96 ) ) {
for ( V_100 = 0 ; V_100 < V_66 ; V_100 ++ )
F_77 ( & ( F_75 ( V_64 , V_100 ) -> V_135 ) ) ;
F_77 ( F_38 ( V_139 , V_64 ) ) ;
F_71 ( V_64 ) ;
return V_96 ;
}
F_78 ( & ( V_145 -> V_135 ) , V_148 ) ;
}
F_46 ( V_64 , F_24 ( V_149 ) ) ;
F_78 ( F_38 ( V_139 , V_64 ) , V_148 ) ;
return 0 ;
}
static void T_1 F_79 ( struct V_142 * V_143 )
{
unsigned int V_64 = V_143 -> V_144 ;
unsigned long V_66 ;
if ( F_38 ( V_117 , V_64 ) == NULL )
return;
if ( ! F_80 ( V_64 , F_24 ( V_149 ) ) )
return;
F_49 ( V_64 , F_24 ( V_149 ) ) ;
for ( V_66 = 0 ; V_66 < V_95 ; V_66 ++ )
F_77 ( & ( F_75 ( V_64 , V_66 ) -> V_135 ) ) ;
F_77 ( F_38 ( V_139 , V_64 ) ) ;
F_71 ( V_64 ) ;
}
static int T_1 F_81 ( struct V_150 * V_151 ,
unsigned long V_152 , void * V_153 )
{
unsigned int V_64 = ( unsigned long ) V_153 ;
struct V_142 * V_143 ;
V_143 = F_82 ( V_64 ) ;
switch ( V_152 ) {
case V_154 :
case V_155 :
F_73 ( V_143 ) ;
break;
case V_156 :
case V_157 :
F_79 ( V_143 ) ;
break;
}
return V_158 ;
}
static int T_1 F_83 ( void )
{
int V_66 ;
if ( V_95 == 0 )
return 0 ;
F_47 (i) {
int V_70 ;
struct V_142 * V_143 = F_82 ( V_66 ) ;
V_70 = F_73 ( V_143 ) ;
if ( V_70 )
return V_70 ;
}
F_84 ( & V_159 ) ;
return 0 ;
}
