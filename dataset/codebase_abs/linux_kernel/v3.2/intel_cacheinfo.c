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
static void T_1 F_10 ( struct V_53 * V_54 ,
int V_55 )
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
return - V_63 ;
if ( V_55 > V_42 -> V_18 . V_52 )
return - V_63 ;
if ( V_55 == F_14 ( V_42 , ! V_57 ) )
return - V_63 ;
F_17 ( V_42 , V_64 , V_57 , V_55 ) ;
return 0 ;
}
static T_3 F_21 ( struct V_59 * V_54 ,
const char * V_60 , T_4 V_68 ,
unsigned int V_57 )
{
unsigned long V_22 = 0 ;
int V_64 , V_69 = 0 ;
if ( ! F_22 ( V_70 ) )
return - V_71 ;
if ( ! V_54 -> V_61 . V_42 || ! F_16 ( V_62 ) )
return - V_63 ;
V_64 = F_23 ( F_24 ( V_54 -> V_72 ) ) ;
if ( F_25 ( V_60 , 10 , & V_22 ) < 0 )
return - V_63 ;
V_69 = F_20 ( V_54 -> V_61 . V_42 , V_64 , V_57 , V_22 ) ;
if ( V_69 ) {
if ( V_69 == - V_73 )
F_26 ( V_74 L_3 ,
V_57 ) ;
return V_69 ;
}
return V_68 ;
}
static T_3
F_27 ( struct V_59 * V_54 , char * V_60 , unsigned int V_64 )
{
if ( ! V_54 -> V_61 . V_42 || ! F_16 ( V_75 ) )
return - V_63 ;
return sprintf ( V_60 , L_4 , F_28 ( V_64 ) ) ;
}
static T_3
F_29 ( struct V_59 * V_54 , const char * V_60 , T_4 V_68 ,
unsigned int V_64 )
{
unsigned long V_22 ;
if ( ! F_22 ( V_70 ) )
return - V_71 ;
if ( ! V_54 -> V_61 . V_42 || ! F_16 ( V_75 ) )
return - V_63 ;
if ( F_25 ( V_60 , 16 , & V_22 ) < 0 )
return - V_63 ;
if ( F_30 ( V_64 , V_22 ) )
return - V_63 ;
return V_68 ;
}
static int
T_1 F_31 ( int V_55 ,
struct V_53 * V_54 )
{
union V_2 V_3 ;
union V_4 V_5 ;
union V_6 V_7 ;
unsigned V_76 ;
if ( V_50 . V_77 == V_78 ) {
F_1 ( V_55 , & V_3 , & V_5 , & V_7 ) ;
F_10 ( V_54 , V_55 ) ;
} else {
F_32 ( 4 , V_55 , & V_3 . V_21 , & V_5 . V_21 , & V_7 . V_21 , & V_76 ) ;
}
if ( V_3 . V_28 . type == V_79 )
return - V_80 ;
V_54 -> V_3 = V_3 ;
V_54 -> V_5 = V_5 ;
V_54 -> V_7 = V_7 ;
V_54 -> V_81 = ( V_7 . V_28 . V_40 + 1 ) *
( V_5 . V_28 . V_37 + 1 ) *
( V_5 . V_28 . V_39 + 1 ) *
( V_5 . V_28 . V_38 + 1 ) ;
return 0 ;
}
static int T_1 F_33 ( void )
{
unsigned int V_3 , V_5 , V_7 , V_76 ;
union V_2 V_82 ;
int V_66 = - 1 ;
do {
++ V_66 ;
F_32 ( 4 , V_66 , & V_3 , & V_5 , & V_7 , & V_76 ) ;
V_82 . V_21 = V_3 ;
} while ( V_82 . V_28 . type != V_79 );
return V_66 ;
}
unsigned int T_1 F_34 ( struct V_83 * V_84 )
{
unsigned int V_85 = 0 , V_14 = 0 , V_15 = 0 , V_17 = 0 , V_19 = 0 ;
unsigned int V_86 = 0 , V_87 = 0 ;
unsigned int V_88 = 0 , V_89 = 0 , V_66 ;
unsigned int V_90 = 0 , V_91 = 0 , V_33 , V_92 ;
#ifdef F_35
unsigned int V_64 = V_84 -> V_93 ;
#endif
if ( V_84 -> V_94 > 3 ) {
static int V_95 ;
if ( V_95 == 0 ) {
V_96 = F_33 () ;
V_95 ++ ;
}
for ( V_66 = 0 ; V_66 < V_96 ; V_66 ++ ) {
struct V_53 V_54 ;
int V_97 ;
V_97 = F_31 ( V_66 , & V_54 ) ;
if ( V_97 >= 0 ) {
switch ( V_54 . V_3 . V_28 . V_31 ) {
case 1 :
if ( V_54 . V_3 . V_28 . type ==
V_98 )
V_86 = V_54 . V_81 / 1024 ;
else if ( V_54 . V_3 . V_28 . type ==
V_99 )
V_87 = V_54 . V_81 / 1024 ;
break;
case 2 :
V_88 = V_54 . V_81 / 1024 ;
V_33 = 1 + V_54 . V_3 . V_28 . V_33 ;
V_92 = F_36 ( V_33 ) ;
V_90 = V_84 -> V_100 >> V_92 ;
break;
case 3 :
V_89 = V_54 . V_81 / 1024 ;
V_33 = 1 + V_54 . V_3 . V_28 . V_33 ;
V_92 = F_36 (
V_33 ) ;
V_91 = V_84 -> V_100 >> V_92 ;
break;
default:
break;
}
}
}
}
if ( ( V_96 == 0 || V_84 -> V_51 == 15 ) && V_84 -> V_94 > 1 ) {
int V_101 , V_102 ;
unsigned int V_103 [ 4 ] ;
unsigned char * V_104 = ( unsigned char * ) V_103 ;
int V_105 = 0 ;
if ( V_96 != 0 && V_84 -> V_51 == 15 )
V_105 = 1 ;
V_102 = F_37 ( 2 ) & 0xFF ;
for ( V_66 = 0 ; V_66 < V_102 ; V_66 ++ ) {
F_2 ( 2 , & V_103 [ 0 ] , & V_103 [ 1 ] , & V_103 [ 2 ] , & V_103 [ 3 ] ) ;
for ( V_101 = 0 ; V_101 < 3 ; V_101 ++ )
if ( V_103 [ V_101 ] & ( 1 << 31 ) )
V_103 [ V_101 ] = 0 ;
for ( V_101 = 1 ; V_101 < 16 ; V_101 ++ ) {
unsigned char V_106 = V_104 [ V_101 ] ;
unsigned char V_107 = 0 ;
while ( V_108 [ V_107 ] . V_109 != 0 ) {
if ( V_108 [ V_107 ] . V_109 == V_106 ) {
if ( V_105 && V_108 [ V_107 ] . V_110 != V_111 )
break;
switch ( V_108 [ V_107 ] . V_110 ) {
case V_112 :
V_14 += V_108 [ V_107 ] . V_81 ;
break;
case V_113 :
V_15 += V_108 [ V_107 ] . V_81 ;
break;
case V_114 :
V_17 += V_108 [ V_107 ] . V_81 ;
break;
case V_115 :
V_19 += V_108 [ V_107 ] . V_81 ;
break;
case V_111 :
V_85 += V_108 [ V_107 ] . V_81 ;
break;
}
break;
}
V_107 ++ ;
}
}
}
}
if ( V_86 )
V_15 = V_86 ;
if ( V_87 )
V_14 = V_87 ;
if ( V_88 ) {
V_17 = V_88 ;
#ifdef F_35
F_38 ( V_116 , V_64 ) = V_90 ;
#endif
}
if ( V_89 ) {
V_19 = V_89 ;
#ifdef F_35
F_38 ( V_116 , V_64 ) = V_91 ;
#endif
}
V_84 -> V_25 = V_19 ? V_19 : ( V_17 ? V_17 : ( V_14 + V_15 ) ) ;
return V_17 ;
}
static void T_1 F_39 ( unsigned int V_64 , int V_55 )
{
struct V_59 * V_54 , * V_117 ;
unsigned long V_33 ;
int V_92 , V_66 , V_118 ;
struct V_83 * V_84 = & F_40 ( V_64 ) ;
if ( ( V_55 == 3 ) && ( V_84 -> V_77 == V_78 ) ) {
F_41 (i, cpu_llc_shared_mask(cpu)) {
if ( ! F_38 ( V_119 , V_66 ) )
continue;
V_54 = F_42 ( V_66 , V_55 ) ;
F_41 (sibling, cpu_llc_shared_mask(cpu)) {
if ( ! F_43 ( V_118 ) )
continue;
F_44 ( V_118 , V_54 -> V_72 ) ;
}
}
return;
}
V_54 = F_42 ( V_64 , V_55 ) ;
V_33 = 1 + V_54 -> V_61 . V_3 . V_28 . V_33 ;
if ( V_33 == 1 )
F_45 ( V_64 , F_24 ( V_54 -> V_72 ) ) ;
else {
V_92 = F_36 ( V_33 ) ;
F_46 (i) {
if ( F_40 ( V_66 ) . V_100 >> V_92 ==
V_84 -> V_100 >> V_92 ) {
F_45 ( V_66 ,
F_24 ( V_54 -> V_72 ) ) ;
if ( V_66 != V_64 && F_38 ( V_119 , V_66 ) ) {
V_117 =
F_42 ( V_66 , V_55 ) ;
F_45 ( V_64 , F_24 (
V_117 -> V_72 ) ) ;
}
}
}
}
}
static void T_1 F_47 ( unsigned int V_64 , int V_55 )
{
struct V_59 * V_54 , * V_117 ;
int V_118 ;
V_54 = F_42 ( V_64 , V_55 ) ;
F_41 (sibling, to_cpumask(this_leaf->shared_cpu_map)) {
V_117 = F_42 ( V_118 , V_55 ) ;
F_48 ( V_64 ,
F_24 ( V_117 -> V_72 ) ) ;
}
}
static void T_1 F_39 ( unsigned int V_64 , int V_55 )
{
}
static void T_1 F_47 ( unsigned int V_64 , int V_55 )
{
}
static void T_1 F_49 ( unsigned int V_64 )
{
int V_66 ;
for ( V_66 = 0 ; V_66 < V_96 ; V_66 ++ )
F_47 ( V_64 , V_66 ) ;
F_50 ( F_38 ( V_119 , V_64 ) ) ;
F_38 ( V_119 , V_64 ) = NULL ;
}
static void T_1 F_51 ( void * V_120 )
{
int V_101 , * V_97 = V_120 , V_64 = F_12 () ;
for ( V_101 = 0 ; V_101 < V_96 ; V_101 ++ ) {
struct V_59 * V_54 = F_42 ( V_64 , V_101 ) ;
* V_97 = F_31 ( V_101 , & V_54 -> V_61 ) ;
if ( F_52 ( * V_97 < 0 ) ) {
int V_66 ;
for ( V_66 = 0 ; V_66 < V_101 ; V_66 ++ )
F_47 ( V_64 , V_66 ) ;
break;
}
F_39 ( V_64 , V_101 ) ;
}
}
static int T_1 F_53 ( unsigned int V_64 )
{
int V_97 ;
if ( V_96 == 0 )
return - V_121 ;
F_38 ( V_119 , V_64 ) = F_54 (
sizeof( struct V_59 ) * V_96 , V_122 ) ;
if ( F_38 ( V_119 , V_64 ) == NULL )
return - V_123 ;
F_55 ( V_64 , F_51 , & V_97 , true ) ;
if ( V_97 ) {
F_50 ( F_38 ( V_119 , V_64 ) ) ;
F_38 ( V_119 , V_64 ) = NULL ;
}
return V_97 ;
}
static T_3 F_56 ( struct V_59 * V_54 , char * V_60 ,
unsigned int V_64 )
{
return sprintf ( V_60 , L_5 , V_54 -> V_61 . V_81 / 1024 ) ;
}
static T_3 F_57 ( struct V_59 * V_54 ,
int type , char * V_60 )
{
T_5 V_124 = F_58 ( V_60 + V_125 - 1 , V_125 ) - V_60 ;
int V_102 = 0 ;
if ( V_124 > 1 ) {
const struct V_126 * V_127 ;
V_127 = F_24 ( V_54 -> V_72 ) ;
V_102 = type ?
F_59 ( V_60 , V_124 - 2 , V_127 ) :
F_60 ( V_60 , V_124 - 2 , V_127 ) ;
V_60 [ V_102 ++ ] = '\n' ;
V_60 [ V_102 ] = '\0' ;
}
return V_102 ;
}
static inline T_3 F_61 ( struct V_59 * V_1 , char * V_60 ,
unsigned int V_64 )
{
return F_57 ( V_1 , 0 , V_60 ) ;
}
static inline T_3 F_62 ( struct V_59 * V_1 , char * V_60 ,
unsigned int V_64 )
{
return F_57 ( V_1 , 1 , V_60 ) ;
}
static T_3 F_63 ( struct V_59 * V_54 , char * V_60 ,
unsigned int V_64 )
{
switch ( V_54 -> V_61 . V_3 . V_28 . type ) {
case V_98 :
return sprintf ( V_60 , L_6 ) ;
case V_99 :
return sprintf ( V_60 , L_7 ) ;
case V_128 :
return sprintf ( V_60 , L_8 ) ;
default:
return sprintf ( V_60 , L_9 ) ;
}
}
static struct V_129 * * T_1 F_64 ( void )
{
static struct V_129 * * V_130 ;
int V_102 ;
if ( V_130 )
return V_130 ;
V_102 = sizeof ( V_131 ) / sizeof ( struct V_129 * ) ;
if ( F_16 ( V_62 ) )
V_102 += 2 ;
if ( F_16 ( V_75 ) )
V_102 += 1 ;
V_130 = F_54 ( V_102 * sizeof ( struct V_129 * ) , V_122 ) ;
if ( V_130 == NULL )
return V_130 = V_131 ;
for ( V_102 = 0 ; V_131 [ V_102 ] ; V_102 ++ )
V_130 [ V_102 ] = V_131 [ V_102 ] ;
if ( F_16 ( V_62 ) ) {
V_130 [ V_102 ++ ] = & V_132 . V_133 ;
V_130 [ V_102 ++ ] = & V_134 . V_133 ;
}
if ( F_16 ( V_75 ) )
V_130 [ V_102 ++ ] = & V_49 . V_133 ;
return V_130 ;
}
static T_3 F_65 ( struct V_135 * V_136 , struct V_129 * V_133 , char * V_60 )
{
struct V_137 * V_138 = F_66 ( V_133 ) ;
struct V_139 * V_54 = F_67 ( V_136 ) ;
T_3 V_67 ;
V_67 = V_138 -> F_65 ?
V_138 -> F_65 ( F_42 ( V_54 -> V_64 , V_54 -> V_55 ) ,
V_60 , V_54 -> V_64 ) :
0 ;
return V_67 ;
}
static T_3 F_68 ( struct V_135 * V_136 , struct V_129 * V_133 ,
const char * V_60 , T_4 V_68 )
{
struct V_137 * V_138 = F_66 ( V_133 ) ;
struct V_139 * V_54 = F_67 ( V_136 ) ;
T_3 V_67 ;
V_67 = V_138 -> F_68 ?
V_138 -> F_68 ( F_42 ( V_54 -> V_64 , V_54 -> V_55 ) ,
V_60 , V_68 , V_54 -> V_64 ) :
0 ;
return V_67 ;
}
static void T_1 F_69 ( unsigned int V_64 )
{
F_50 ( F_38 ( V_140 , V_64 ) ) ;
F_50 ( F_38 ( V_141 , V_64 ) ) ;
F_38 ( V_140 , V_64 ) = NULL ;
F_38 ( V_141 , V_64 ) = NULL ;
F_49 ( V_64 ) ;
}
static int T_1 F_70 ( unsigned int V_64 )
{
int V_69 ;
if ( V_96 == 0 )
return - V_121 ;
V_69 = F_53 ( V_64 ) ;
if ( V_69 )
return V_69 ;
F_38 ( V_140 , V_64 ) =
F_54 ( sizeof( struct V_135 ) , V_122 ) ;
if ( F_52 ( F_38 ( V_140 , V_64 ) == NULL ) )
goto V_142;
F_38 ( V_141 , V_64 ) = F_54 (
sizeof( struct V_139 ) * V_96 , V_122 ) ;
if ( F_52 ( F_38 ( V_141 , V_64 ) == NULL ) )
goto V_142;
return 0 ;
V_142:
F_69 ( V_64 ) ;
return - V_123 ;
}
static int T_1 F_71 ( struct V_143 * V_144 )
{
unsigned int V_64 = V_144 -> V_145 ;
unsigned long V_66 , V_101 ;
struct V_139 * V_146 ;
struct V_59 * V_54 ;
int V_97 ;
V_97 = F_70 ( V_64 ) ;
if ( F_52 ( V_97 < 0 ) )
return V_97 ;
V_97 = F_72 ( F_38 ( V_140 , V_64 ) ,
& V_147 ,
& V_144 -> V_136 , L_10 , L_11 ) ;
if ( V_97 < 0 ) {
F_69 ( V_64 ) ;
return V_97 ;
}
for ( V_66 = 0 ; V_66 < V_96 ; V_66 ++ ) {
V_146 = F_73 ( V_64 , V_66 ) ;
V_146 -> V_64 = V_64 ;
V_146 -> V_55 = V_66 ;
V_54 = F_42 ( V_64 , V_66 ) ;
V_148 . V_131 = V_131 ;
#ifdef F_74
if ( V_54 -> V_61 . V_42 )
V_148 . V_131 = F_64 () ;
#endif
V_97 = F_72 ( & ( V_146 -> V_136 ) ,
& V_148 ,
F_38 ( V_140 , V_64 ) ,
L_12 , V_66 ) ;
if ( F_52 ( V_97 ) ) {
for ( V_101 = 0 ; V_101 < V_66 ; V_101 ++ )
F_75 ( & ( F_73 ( V_64 , V_101 ) -> V_136 ) ) ;
F_75 ( F_38 ( V_140 , V_64 ) ) ;
F_69 ( V_64 ) ;
return V_97 ;
}
F_76 ( & ( V_146 -> V_136 ) , V_149 ) ;
}
F_45 ( V_64 , F_24 ( V_150 ) ) ;
F_76 ( F_38 ( V_140 , V_64 ) , V_149 ) ;
return 0 ;
}
static void T_1 F_77 ( struct V_143 * V_144 )
{
unsigned int V_64 = V_144 -> V_145 ;
unsigned long V_66 ;
if ( F_38 ( V_119 , V_64 ) == NULL )
return;
if ( ! F_78 ( V_64 , F_24 ( V_150 ) ) )
return;
F_48 ( V_64 , F_24 ( V_150 ) ) ;
for ( V_66 = 0 ; V_66 < V_96 ; V_66 ++ )
F_75 ( & ( F_73 ( V_64 , V_66 ) -> V_136 ) ) ;
F_75 ( F_38 ( V_140 , V_64 ) ) ;
F_69 ( V_64 ) ;
}
static int T_1 F_79 ( struct V_151 * V_152 ,
unsigned long V_153 , void * V_154 )
{
unsigned int V_64 = ( unsigned long ) V_154 ;
struct V_143 * V_144 ;
V_144 = F_80 ( V_64 ) ;
switch ( V_153 ) {
case V_155 :
case V_156 :
F_71 ( V_144 ) ;
break;
case V_157 :
case V_158 :
F_77 ( V_144 ) ;
break;
}
return V_159 ;
}
static int T_1 F_81 ( void )
{
int V_66 ;
if ( V_96 == 0 )
return 0 ;
F_46 (i) {
int V_69 ;
struct V_143 * V_144 = F_80 ( V_66 ) ;
V_69 = F_71 ( V_144 ) ;
if ( V_69 )
return V_69 ;
}
F_82 ( & V_160 ) ;
return 0 ;
}
