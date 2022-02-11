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
static void T_1 F_5 ( struct V_41 * V_19 )
{
unsigned int V_42 , V_43 , V_44 , V_45 ;
T_2 V_22 = 0 ;
F_6 ( V_19 -> V_46 -> V_47 , 0x1C4 , & V_22 ) ;
V_19 -> V_48 [ 0 ] = V_42 = ! ( V_22 & F_7 ( 0 ) ) ;
V_19 -> V_48 [ 1 ] = V_43 = ! ( V_22 & F_7 ( 4 ) ) ;
V_19 -> V_48 [ 2 ] = V_44 = ! ( V_22 & F_7 ( 8 ) ) + ! ( V_22 & F_7 ( 9 ) ) ;
V_19 -> V_48 [ 3 ] = V_45 = ! ( V_22 & F_7 ( 12 ) ) + ! ( V_22 & F_7 ( 13 ) ) ;
V_19 -> V_49 = ( F_8 ( F_9 ( V_42 , V_43 , V_44 ) , V_45 ) << 10 ) - 1 ;
}
static void T_1 F_10 ( struct V_50 * V_51 ,
int V_52 )
{
static struct V_41 * T_3 V_53 ;
int V_54 ;
if ( V_52 < 3 || F_11 () == 0 )
return;
if ( ! V_53 ) {
int V_55 = F_11 () * sizeof( struct V_41 ) ;
V_53 = F_12 ( V_55 , V_56 ) ;
if ( ! V_53 )
return;
}
V_54 = F_13 ( F_14 () ) ;
if ( ! V_53 [ V_54 ] . V_46 ) {
V_53 [ V_54 ] . V_46 = F_15 ( V_54 ) ;
F_5 ( & V_53 [ V_54 ] ) ;
}
V_51 -> V_19 = & V_53 [ V_54 ] ;
}
int F_16 ( struct V_41 * V_19 , unsigned V_57 )
{
unsigned int V_58 = 0 ;
F_6 ( V_19 -> V_46 -> V_47 , 0x1BC + V_57 * 4 , & V_58 ) ;
if ( V_58 & ( 3UL << 30 ) )
return V_58 & 0xfff ;
return - 1 ;
}
static T_4 F_17 ( struct V_59 * V_51 , char * V_60 ,
unsigned int V_57 )
{
int V_52 ;
if ( ! V_51 -> V_19 ||
! F_18 ( V_61 ) )
return - V_62 ;
V_52 = F_16 ( V_51 -> V_19 , V_57 ) ;
if ( V_52 >= 0 )
return sprintf ( V_60 , L_1 , V_52 ) ;
return sprintf ( V_60 , L_2 ) ;
}
static void F_19 ( struct V_41 * V_19 , int V_63 ,
unsigned V_57 , unsigned long V_64 )
{
int V_65 ;
V_64 |= F_7 ( 30 ) ;
for ( V_65 = 0 ; V_65 < 4 ; V_65 ++ ) {
T_2 V_58 = V_64 | ( V_65 << 20 ) ;
if ( ! V_19 -> V_48 [ V_65 ] )
continue;
F_20 ( V_19 -> V_46 -> V_47 , 0x1BC + V_57 * 4 , V_58 ) ;
F_21 ( V_63 ) ;
V_58 |= F_7 ( 31 ) ;
F_20 ( V_19 -> V_46 -> V_47 , 0x1BC + V_57 * 4 , V_58 ) ;
}
}
int F_22 ( struct V_41 * V_19 , int V_63 , unsigned V_57 ,
unsigned long V_52 )
{
int V_66 = 0 ;
V_66 = F_16 ( V_19 , V_57 ) ;
if ( V_66 >= 0 )
return - V_62 ;
if ( V_52 > V_19 -> V_49 )
return - V_62 ;
if ( V_52 == F_16 ( V_19 , ! V_57 ) )
return - V_62 ;
F_19 ( V_19 , V_63 , V_57 , V_52 ) ;
return 0 ;
}
static T_4 F_23 ( struct V_59 * V_51 ,
const char * V_60 , T_5 V_67 ,
unsigned int V_57 )
{
unsigned long V_22 = 0 ;
int V_63 , V_68 = 0 ;
if ( ! F_24 ( V_69 ) )
return - V_70 ;
if ( ! V_51 -> V_19 ||
! F_18 ( V_61 ) )
return - V_62 ;
V_63 = F_25 ( F_26 ( V_51 -> V_71 ) ) ;
if ( F_27 ( V_60 , 10 , & V_22 ) < 0 )
return - V_62 ;
V_68 = F_22 ( V_51 -> V_19 , V_63 , V_57 , V_22 ) ;
if ( V_68 ) {
if ( V_68 == - V_72 )
F_28 ( V_73 L_3 ,
V_57 ) ;
return V_68 ;
}
return V_67 ;
}
static T_4
F_29 ( struct V_59 * V_51 , char * V_60 , unsigned int V_63 )
{
if ( ! V_51 -> V_19 || ! F_18 ( V_74 ) )
return - V_62 ;
return sprintf ( V_60 , L_4 , F_30 ( V_63 ) ) ;
}
static T_4
F_31 ( struct V_59 * V_51 , const char * V_60 , T_5 V_67 ,
unsigned int V_63 )
{
unsigned long V_22 ;
if ( ! F_24 ( V_69 ) )
return - V_70 ;
if ( ! V_51 -> V_19 || ! F_18 ( V_74 ) )
return - V_62 ;
if ( F_27 ( V_60 , 16 , & V_22 ) < 0 )
return - V_62 ;
if ( F_32 ( V_63 , V_22 ) )
return - V_62 ;
return V_67 ;
}
static int
T_1 F_33 ( int V_52 ,
struct V_50 * V_51 )
{
union V_2 V_3 ;
union V_4 V_5 ;
union V_6 V_7 ;
unsigned V_75 ;
if ( V_76 . V_77 == V_78 ) {
F_1 ( V_52 , & V_3 , & V_5 , & V_7 ) ;
F_10 ( V_51 , V_52 ) ;
} else {
F_34 ( 4 , V_52 , & V_3 . V_21 , & V_5 . V_21 , & V_7 . V_21 , & V_75 ) ;
}
if ( V_3 . V_28 . type == V_79 )
return - V_80 ;
V_51 -> V_3 = V_3 ;
V_51 -> V_5 = V_5 ;
V_51 -> V_7 = V_7 ;
V_51 -> V_55 = ( V_7 . V_28 . V_40 + 1 ) *
( V_5 . V_28 . V_37 + 1 ) *
( V_5 . V_28 . V_39 + 1 ) *
( V_5 . V_28 . V_38 + 1 ) ;
return 0 ;
}
static int T_1 F_35 ( void )
{
unsigned int V_3 , V_5 , V_7 , V_75 ;
union V_2 V_81 ;
int V_65 = - 1 ;
do {
++ V_65 ;
F_34 ( 4 , V_65 , & V_3 , & V_5 , & V_7 , & V_75 ) ;
V_81 . V_21 = V_3 ;
} while ( V_81 . V_28 . type != V_79 );
return V_65 ;
}
unsigned int T_1 F_36 ( struct V_82 * V_83 )
{
unsigned int V_84 = 0 , V_14 = 0 , V_15 = 0 , V_17 = 0 , V_19 = 0 ;
unsigned int V_85 = 0 , V_86 = 0 ;
unsigned int V_87 = 0 , V_88 = 0 , V_65 ;
unsigned int V_89 = 0 , V_90 = 0 , V_33 , V_91 ;
#ifdef F_37
unsigned int V_63 = V_83 -> V_92 ;
#endif
if ( V_83 -> V_93 > 3 ) {
static int V_94 ;
if ( V_94 == 0 ) {
V_95 = F_35 () ;
V_94 ++ ;
}
for ( V_65 = 0 ; V_65 < V_95 ; V_65 ++ ) {
struct V_50 V_51 ;
int V_96 ;
V_96 = F_33 ( V_65 , & V_51 ) ;
if ( V_96 >= 0 ) {
switch ( V_51 . V_3 . V_28 . V_31 ) {
case 1 :
if ( V_51 . V_3 . V_28 . type ==
V_97 )
V_85 = V_51 . V_55 / 1024 ;
else if ( V_51 . V_3 . V_28 . type ==
V_98 )
V_86 = V_51 . V_55 / 1024 ;
break;
case 2 :
V_87 = V_51 . V_55 / 1024 ;
V_33 = 1 + V_51 . V_3 . V_28 . V_33 ;
V_91 = F_38 ( V_33 ) ;
V_89 = V_83 -> V_99 >> V_91 ;
break;
case 3 :
V_88 = V_51 . V_55 / 1024 ;
V_33 = 1 + V_51 . V_3 . V_28 . V_33 ;
V_91 = F_38 (
V_33 ) ;
V_90 = V_83 -> V_99 >> V_91 ;
break;
default:
break;
}
}
}
}
if ( ( V_95 == 0 || V_83 -> V_100 == 15 ) && V_83 -> V_93 > 1 ) {
int V_101 , V_102 ;
unsigned int V_103 [ 4 ] ;
unsigned char * V_104 = ( unsigned char * ) V_103 ;
int V_105 = 0 ;
if ( V_95 != 0 && V_83 -> V_100 == 15 )
V_105 = 1 ;
V_102 = F_39 ( 2 ) & 0xFF ;
for ( V_65 = 0 ; V_65 < V_102 ; V_65 ++ ) {
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
V_14 += V_108 [ V_107 ] . V_55 ;
break;
case V_113 :
V_15 += V_108 [ V_107 ] . V_55 ;
break;
case V_114 :
V_17 += V_108 [ V_107 ] . V_55 ;
break;
case V_115 :
V_19 += V_108 [ V_107 ] . V_55 ;
break;
case V_111 :
V_84 += V_108 [ V_107 ] . V_55 ;
break;
}
break;
}
V_107 ++ ;
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
#ifdef F_37
F_40 ( V_116 , V_63 ) = V_89 ;
#endif
}
if ( V_88 ) {
V_19 = V_88 ;
#ifdef F_37
F_40 ( V_116 , V_63 ) = V_90 ;
#endif
}
V_83 -> V_25 = V_19 ? V_19 : ( V_17 ? V_17 : ( V_14 + V_15 ) ) ;
return V_17 ;
}
static void T_1 F_41 ( unsigned int V_63 , int V_52 )
{
struct V_59 * V_51 , * V_117 ;
unsigned long V_33 ;
int V_91 , V_65 , V_118 ;
struct V_82 * V_83 = & F_42 ( V_63 ) ;
if ( ( V_52 == 3 ) && ( V_83 -> V_77 == V_78 ) ) {
F_43 (i, cpu_llc_shared_mask(cpu)) {
if ( ! F_40 ( V_119 , V_65 ) )
continue;
V_51 = F_44 ( V_65 , V_52 ) ;
F_43 (sibling, cpu_llc_shared_mask(cpu)) {
if ( ! F_45 ( V_118 ) )
continue;
F_46 ( V_118 , V_51 -> V_71 ) ;
}
}
return;
}
V_51 = F_44 ( V_63 , V_52 ) ;
V_33 = 1 + V_51 -> V_3 . V_28 . V_33 ;
if ( V_33 == 1 )
F_47 ( V_63 , F_26 ( V_51 -> V_71 ) ) ;
else {
V_91 = F_38 ( V_33 ) ;
F_48 (i) {
if ( F_42 ( V_65 ) . V_99 >> V_91 ==
V_83 -> V_99 >> V_91 ) {
F_47 ( V_65 ,
F_26 ( V_51 -> V_71 ) ) ;
if ( V_65 != V_63 && F_40 ( V_119 , V_65 ) ) {
V_117 =
F_44 ( V_65 , V_52 ) ;
F_47 ( V_63 , F_26 (
V_117 -> V_71 ) ) ;
}
}
}
}
}
static void T_1 F_49 ( unsigned int V_63 , int V_52 )
{
struct V_59 * V_51 , * V_117 ;
int V_118 ;
V_51 = F_44 ( V_63 , V_52 ) ;
F_43 (sibling, to_cpumask(this_leaf->shared_cpu_map)) {
V_117 = F_44 ( V_118 , V_52 ) ;
F_50 ( V_63 ,
F_26 ( V_117 -> V_71 ) ) ;
}
}
static void T_1 F_41 ( unsigned int V_63 , int V_52 )
{
}
static void T_1 F_49 ( unsigned int V_63 , int V_52 )
{
}
static void T_1 F_51 ( unsigned int V_63 )
{
int V_65 ;
for ( V_65 = 0 ; V_65 < V_95 ; V_65 ++ )
F_49 ( V_63 , V_65 ) ;
F_52 ( F_40 ( V_119 , V_63 ) -> V_19 ) ;
F_52 ( F_40 ( V_119 , V_63 ) ) ;
F_40 ( V_119 , V_63 ) = NULL ;
}
static int
T_1 F_53 ( int V_52 , struct V_59 * V_51 )
{
struct V_50 * V_120 =
(struct V_50 * ) V_51 ;
return F_33 ( V_52 , V_120 ) ;
}
static void T_1 F_54 ( void * V_121 )
{
int V_101 , * V_96 = V_121 , V_63 = F_14 () ;
for ( V_101 = 0 ; V_101 < V_95 ; V_101 ++ ) {
struct V_59 * V_51 ;
V_51 = F_44 ( V_63 , V_101 ) ;
* V_96 = F_53 ( V_101 , V_51 ) ;
if ( F_55 ( * V_96 < 0 ) ) {
int V_65 ;
for ( V_65 = 0 ; V_65 < V_101 ; V_65 ++ )
F_49 ( V_63 , V_65 ) ;
break;
}
F_41 ( V_63 , V_101 ) ;
}
}
static int T_1 F_56 ( unsigned int V_63 )
{
int V_96 ;
if ( V_95 == 0 )
return - V_122 ;
F_40 ( V_119 , V_63 ) = F_12 (
sizeof( struct V_59 ) * V_95 , V_123 ) ;
if ( F_40 ( V_119 , V_63 ) == NULL )
return - V_124 ;
F_57 ( V_63 , F_54 , & V_96 , true ) ;
if ( V_96 ) {
F_52 ( F_40 ( V_119 , V_63 ) ) ;
F_40 ( V_119 , V_63 ) = NULL ;
}
return V_96 ;
}
static T_4 F_58 ( struct V_59 * V_51 , char * V_60 ,
unsigned int V_63 )
{
return sprintf ( V_60 , L_5 , V_51 -> V_55 / 1024 ) ;
}
static T_4 F_59 ( struct V_59 * V_51 ,
int type , char * V_60 )
{
T_6 V_125 = F_60 ( V_60 + V_126 - 1 , V_126 ) - V_60 ;
int V_102 = 0 ;
if ( V_125 > 1 ) {
const struct V_127 * V_128 ;
V_128 = F_26 ( V_51 -> V_71 ) ;
V_102 = type ?
F_61 ( V_60 , V_125 - 2 , V_128 ) :
F_62 ( V_60 , V_125 - 2 , V_128 ) ;
V_60 [ V_102 ++ ] = '\n' ;
V_60 [ V_102 ] = '\0' ;
}
return V_102 ;
}
static inline T_4 F_63 ( struct V_59 * V_1 , char * V_60 ,
unsigned int V_63 )
{
return F_59 ( V_1 , 0 , V_60 ) ;
}
static inline T_4 F_64 ( struct V_59 * V_1 , char * V_60 ,
unsigned int V_63 )
{
return F_59 ( V_1 , 1 , V_60 ) ;
}
static T_4 F_65 ( struct V_59 * V_51 , char * V_60 ,
unsigned int V_63 )
{
switch ( V_51 -> V_3 . V_28 . type ) {
case V_97 :
return sprintf ( V_60 , L_6 ) ;
case V_98 :
return sprintf ( V_60 , L_7 ) ;
case V_129 :
return sprintf ( V_60 , L_8 ) ;
default:
return sprintf ( V_60 , L_9 ) ;
}
}
static struct V_130 * * T_1 F_66 ( void )
{
static struct V_130 * * V_131 ;
int V_102 ;
if ( V_131 )
return V_131 ;
V_102 = sizeof ( V_132 ) / sizeof ( struct V_130 * ) ;
if ( F_18 ( V_61 ) )
V_102 += 2 ;
if ( F_18 ( V_74 ) )
V_102 += 1 ;
V_131 = F_12 ( V_102 * sizeof ( struct V_130 * ) , V_123 ) ;
if ( V_131 == NULL )
return V_131 = V_132 ;
for ( V_102 = 0 ; V_132 [ V_102 ] ; V_102 ++ )
V_131 [ V_102 ] = V_132 [ V_102 ] ;
if ( F_18 ( V_61 ) ) {
V_131 [ V_102 ++ ] = & V_133 . V_134 ;
V_131 [ V_102 ++ ] = & V_135 . V_134 ;
}
if ( F_18 ( V_74 ) )
V_131 [ V_102 ++ ] = & V_48 . V_134 ;
return V_131 ;
}
static T_4 F_67 ( struct V_136 * V_137 , struct V_130 * V_134 , char * V_60 )
{
struct V_138 * V_139 = F_68 ( V_134 ) ;
struct V_140 * V_51 = F_69 ( V_137 ) ;
T_4 V_66 ;
V_66 = V_139 -> F_67 ?
V_139 -> F_67 ( F_44 ( V_51 -> V_63 , V_51 -> V_52 ) ,
V_60 , V_51 -> V_63 ) :
0 ;
return V_66 ;
}
static T_4 F_70 ( struct V_136 * V_137 , struct V_130 * V_134 ,
const char * V_60 , T_5 V_67 )
{
struct V_138 * V_139 = F_68 ( V_134 ) ;
struct V_140 * V_51 = F_69 ( V_137 ) ;
T_4 V_66 ;
V_66 = V_139 -> F_70 ?
V_139 -> F_70 ( F_44 ( V_51 -> V_63 , V_51 -> V_52 ) ,
V_60 , V_67 , V_51 -> V_63 ) :
0 ;
return V_66 ;
}
static void T_1 F_71 ( unsigned int V_63 )
{
F_52 ( F_40 ( V_141 , V_63 ) ) ;
F_52 ( F_40 ( V_142 , V_63 ) ) ;
F_40 ( V_141 , V_63 ) = NULL ;
F_40 ( V_142 , V_63 ) = NULL ;
F_51 ( V_63 ) ;
}
static int T_1 F_72 ( unsigned int V_63 )
{
int V_68 ;
if ( V_95 == 0 )
return - V_122 ;
V_68 = F_56 ( V_63 ) ;
if ( V_68 )
return V_68 ;
F_40 ( V_141 , V_63 ) =
F_12 ( sizeof( struct V_136 ) , V_123 ) ;
if ( F_55 ( F_40 ( V_141 , V_63 ) == NULL ) )
goto V_143;
F_40 ( V_142 , V_63 ) = F_12 (
sizeof( struct V_140 ) * V_95 , V_123 ) ;
if ( F_55 ( F_40 ( V_142 , V_63 ) == NULL ) )
goto V_143;
return 0 ;
V_143:
F_71 ( V_63 ) ;
return - V_124 ;
}
static int T_1 F_73 ( struct V_144 * V_145 )
{
unsigned int V_63 = V_145 -> V_146 ;
unsigned long V_65 , V_101 ;
struct V_140 * V_147 ;
struct V_59 * V_51 ;
int V_96 ;
V_96 = F_72 ( V_63 ) ;
if ( F_55 ( V_96 < 0 ) )
return V_96 ;
V_96 = F_74 ( F_40 ( V_141 , V_63 ) ,
& V_148 ,
& V_145 -> V_137 , L_10 , L_11 ) ;
if ( V_96 < 0 ) {
F_71 ( V_63 ) ;
return V_96 ;
}
for ( V_65 = 0 ; V_65 < V_95 ; V_65 ++ ) {
V_147 = F_75 ( V_63 , V_65 ) ;
V_147 -> V_63 = V_63 ;
V_147 -> V_52 = V_65 ;
V_51 = F_44 ( V_63 , V_65 ) ;
V_149 . V_132 = V_132 ;
#ifdef F_76
if ( V_51 -> V_19 )
V_149 . V_132 = F_66 () ;
#endif
V_96 = F_74 ( & ( V_147 -> V_137 ) ,
& V_149 ,
F_40 ( V_141 , V_63 ) ,
L_12 , V_65 ) ;
if ( F_55 ( V_96 ) ) {
for ( V_101 = 0 ; V_101 < V_65 ; V_101 ++ )
F_77 ( & ( F_75 ( V_63 , V_101 ) -> V_137 ) ) ;
F_77 ( F_40 ( V_141 , V_63 ) ) ;
F_71 ( V_63 ) ;
return V_96 ;
}
F_78 ( & ( V_147 -> V_137 ) , V_150 ) ;
}
F_47 ( V_63 , F_26 ( V_151 ) ) ;
F_78 ( F_40 ( V_141 , V_63 ) , V_150 ) ;
return 0 ;
}
static void T_1 F_79 ( struct V_144 * V_145 )
{
unsigned int V_63 = V_145 -> V_146 ;
unsigned long V_65 ;
if ( F_40 ( V_119 , V_63 ) == NULL )
return;
if ( ! F_80 ( V_63 , F_26 ( V_151 ) ) )
return;
F_50 ( V_63 , F_26 ( V_151 ) ) ;
for ( V_65 = 0 ; V_65 < V_95 ; V_65 ++ )
F_77 ( & ( F_75 ( V_63 , V_65 ) -> V_137 ) ) ;
F_77 ( F_40 ( V_141 , V_63 ) ) ;
F_71 ( V_63 ) ;
}
static int T_1 F_81 ( struct V_152 * V_153 ,
unsigned long V_154 , void * V_155 )
{
unsigned int V_63 = ( unsigned long ) V_155 ;
struct V_144 * V_145 ;
V_145 = F_82 ( V_63 ) ;
switch ( V_154 ) {
case V_156 :
case V_157 :
F_73 ( V_145 ) ;
break;
case V_158 :
case V_159 :
F_79 ( V_145 ) ;
break;
}
return V_160 ;
}
static int T_1 F_83 ( void )
{
int V_65 ;
if ( V_95 == 0 )
return 0 ;
F_48 (i) {
int V_68 ;
struct V_144 * V_145 = F_82 ( V_65 ) ;
V_68 = F_73 ( V_145 ) ;
if ( V_68 )
return V_68 ;
}
F_84 ( & V_161 ) ;
return 0 ;
}
