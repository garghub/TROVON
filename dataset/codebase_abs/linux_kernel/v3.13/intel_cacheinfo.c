static void
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
static void F_5 ( struct V_41 * V_42 )
{
struct V_43 * V_19 = & V_42 -> V_18 ;
unsigned int V_44 , V_45 , V_46 , V_47 ;
T_1 V_22 = 0 ;
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
static void F_10 ( struct V_53 * V_54 , int V_55 )
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
static T_2 F_15 ( struct V_59 * V_54 , char * V_60 ,
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
T_1 V_58 = V_65 | ( V_66 << 20 ) ;
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
static T_2 F_21 ( struct V_59 * V_54 ,
const char * V_60 , T_3 V_69 ,
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
static T_2
F_27 ( struct V_59 * V_54 , char * V_60 , unsigned int V_64 )
{
if ( ! V_54 -> V_61 . V_42 || ! F_16 ( V_74 ) )
return - V_63 ;
return sprintf ( V_60 , L_4 , F_28 ( V_64 ) ) ;
}
static T_2
F_29 ( struct V_59 * V_54 , const char * V_60 , T_3 V_69 ,
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
F_31 ( int V_55 , struct V_53 * V_54 )
{
union V_2 V_3 ;
union V_4 V_5 ;
union V_6 V_7 ;
unsigned V_75 ;
if ( V_50 . V_76 == V_77 ) {
if ( V_78 )
F_32 ( 0x8000001d , V_55 , & V_3 . V_21 ,
& V_5 . V_21 , & V_7 . V_21 , & V_75 ) ;
else
F_1 ( V_55 , & V_3 , & V_5 , & V_7 ) ;
F_10 ( V_54 , V_55 ) ;
} else {
F_32 ( 4 , V_55 , & V_3 . V_21 , & V_5 . V_21 , & V_7 . V_21 , & V_75 ) ;
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
static int F_33 ( struct V_82 * V_83 )
{
unsigned int V_3 , V_5 , V_7 , V_75 , V_84 ;
union V_2 V_85 ;
int V_66 = - 1 ;
if ( V_83 -> V_76 == V_77 )
V_84 = 0x8000001d ;
else
V_84 = 4 ;
do {
++ V_66 ;
F_32 ( V_84 , V_66 , & V_3 , & V_5 , & V_7 , & V_75 ) ;
V_85 . V_21 = V_3 ;
} while ( V_85 . V_28 . type != V_79 );
return V_66 ;
}
void F_34 ( struct V_82 * V_83 )
{
if ( V_78 ) {
V_86 = F_33 ( V_83 ) ;
} else if ( V_83 -> V_87 >= 0x80000006 ) {
if ( F_35 ( 0x80000006 ) & 0xf000 )
V_86 = 4 ;
else
V_86 = 3 ;
}
}
unsigned int F_36 ( struct V_82 * V_83 )
{
unsigned int V_88 = 0 , V_14 = 0 , V_15 = 0 , V_17 = 0 , V_19 = 0 ;
unsigned int V_89 = 0 , V_90 = 0 ;
unsigned int V_91 = 0 , V_92 = 0 , V_66 ;
unsigned int V_93 = 0 , V_94 = 0 , V_33 , V_95 ;
#ifdef F_37
unsigned int V_64 = V_83 -> V_96 ;
#endif
if ( V_83 -> V_97 > 3 ) {
static int V_98 ;
if ( V_98 == 0 ) {
V_86 = F_33 ( V_83 ) ;
V_98 ++ ;
}
for ( V_66 = 0 ; V_66 < V_86 ; V_66 ++ ) {
struct V_53 V_54 = {} ;
int V_99 ;
V_99 = F_31 ( V_66 , & V_54 ) ;
if ( V_99 < 0 )
continue;
switch ( V_54 . V_3 . V_28 . V_31 ) {
case 1 :
if ( V_54 . V_3 . V_28 . type == V_100 )
V_89 = V_54 . V_81 / 1024 ;
else if ( V_54 . V_3 . V_28 . type == V_101 )
V_90 = V_54 . V_81 / 1024 ;
break;
case 2 :
V_91 = V_54 . V_81 / 1024 ;
V_33 = 1 + V_54 . V_3 . V_28 . V_33 ;
V_95 = F_38 ( V_33 ) ;
V_93 = V_83 -> V_102 & ~ ( ( 1 << V_95 ) - 1 ) ;
break;
case 3 :
V_92 = V_54 . V_81 / 1024 ;
V_33 = 1 + V_54 . V_3 . V_28 . V_33 ;
V_95 = F_38 ( V_33 ) ;
V_94 = V_83 -> V_102 & ~ ( ( 1 << V_95 ) - 1 ) ;
break;
default:
break;
}
}
}
if ( ( V_86 == 0 || V_83 -> V_51 == 15 ) && V_83 -> V_97 > 1 ) {
int V_103 , V_104 ;
unsigned int V_105 [ 4 ] ;
unsigned char * V_106 = ( unsigned char * ) V_105 ;
int V_107 = 0 ;
if ( V_86 != 0 && V_83 -> V_51 == 15 )
V_107 = 1 ;
V_104 = F_39 ( 2 ) & 0xFF ;
for ( V_66 = 0 ; V_66 < V_104 ; V_66 ++ ) {
F_2 ( 2 , & V_105 [ 0 ] , & V_105 [ 1 ] , & V_105 [ 2 ] , & V_105 [ 3 ] ) ;
for ( V_103 = 0 ; V_103 < 3 ; V_103 ++ )
if ( V_105 [ V_103 ] & ( 1 << 31 ) )
V_105 [ V_103 ] = 0 ;
for ( V_103 = 1 ; V_103 < 16 ; V_103 ++ ) {
unsigned char V_108 = V_106 [ V_103 ] ;
unsigned char V_109 = 0 ;
while ( V_110 [ V_109 ] . V_111 != 0 ) {
if ( V_110 [ V_109 ] . V_111 == V_108 ) {
if ( V_107 && V_110 [ V_109 ] . V_112 != V_113 )
break;
switch ( V_110 [ V_109 ] . V_112 ) {
case V_114 :
V_14 += V_110 [ V_109 ] . V_81 ;
break;
case V_115 :
V_15 += V_110 [ V_109 ] . V_81 ;
break;
case V_116 :
V_17 += V_110 [ V_109 ] . V_81 ;
break;
case V_117 :
V_19 += V_110 [ V_109 ] . V_81 ;
break;
case V_113 :
V_88 += V_110 [ V_109 ] . V_81 ;
break;
}
break;
}
V_109 ++ ;
}
}
}
}
if ( V_89 )
V_15 = V_89 ;
if ( V_90 )
V_14 = V_90 ;
if ( V_91 ) {
V_17 = V_91 ;
#ifdef F_37
F_40 ( V_118 , V_64 ) = V_93 ;
#endif
}
if ( V_92 ) {
V_19 = V_92 ;
#ifdef F_37
F_40 ( V_118 , V_64 ) = V_94 ;
#endif
}
V_83 -> V_25 = V_19 ? V_19 : ( V_17 ? V_17 : ( V_14 + V_15 ) ) ;
return V_17 ;
}
static int F_41 ( unsigned int V_64 , int V_55 )
{
struct V_59 * V_54 ;
int V_66 , V_119 ;
if ( V_78 ) {
unsigned int V_102 , V_120 , V_121 , V_122 ;
if ( ! F_40 ( V_123 , V_64 ) )
return 0 ;
V_54 = F_42 ( V_64 , V_55 ) ;
V_120 = V_54 -> V_61 . V_3 . V_28 . V_33 + 1 ;
V_102 = F_43 ( V_64 ) . V_102 ;
V_121 = V_102 - ( V_102 % V_120 ) ;
V_122 = V_121 + V_120 - 1 ;
F_44 (i) {
V_102 = F_43 ( V_66 ) . V_102 ;
if ( ( V_102 < V_121 ) || ( V_102 > V_122 ) )
continue;
if ( ! F_40 ( V_123 , V_66 ) )
continue;
V_54 = F_42 ( V_66 , V_55 ) ;
F_44 (sibling) {
V_102 = F_43 ( V_119 ) . V_102 ;
if ( ( V_102 < V_121 ) || ( V_102 > V_122 ) )
continue;
F_45 ( V_119 , V_54 -> V_73 ) ;
}
}
} else if ( V_55 == 3 ) {
F_46 (i, cpu_llc_shared_mask(cpu)) {
if ( ! F_40 ( V_123 , V_66 ) )
continue;
V_54 = F_42 ( V_66 , V_55 ) ;
F_46 (sibling, cpu_llc_shared_mask(cpu)) {
if ( ! F_47 ( V_119 ) )
continue;
F_45 ( V_119 , V_54 -> V_73 ) ;
}
}
} else
return 0 ;
return 1 ;
}
static void F_48 ( unsigned int V_64 , int V_55 )
{
struct V_59 * V_54 , * V_124 ;
unsigned long V_33 ;
int V_95 , V_66 ;
struct V_82 * V_83 = & F_43 ( V_64 ) ;
if ( V_83 -> V_76 == V_77 ) {
if ( F_41 ( V_64 , V_55 ) )
return;
}
V_54 = F_42 ( V_64 , V_55 ) ;
V_33 = 1 + V_54 -> V_61 . V_3 . V_28 . V_33 ;
if ( V_33 == 1 )
F_49 ( V_64 , F_24 ( V_54 -> V_73 ) ) ;
else {
V_95 = F_38 ( V_33 ) ;
F_44 (i) {
if ( F_43 ( V_66 ) . V_102 >> V_95 ==
V_83 -> V_102 >> V_95 ) {
F_49 ( V_66 ,
F_24 ( V_54 -> V_73 ) ) ;
if ( V_66 != V_64 && F_40 ( V_123 , V_66 ) ) {
V_124 =
F_42 ( V_66 , V_55 ) ;
F_49 ( V_64 , F_24 (
V_124 -> V_73 ) ) ;
}
}
}
}
}
static void F_50 ( unsigned int V_64 , int V_55 )
{
struct V_59 * V_54 , * V_124 ;
int V_119 ;
V_54 = F_42 ( V_64 , V_55 ) ;
F_46 (sibling, to_cpumask(this_leaf->shared_cpu_map)) {
V_124 = F_42 ( V_119 , V_55 ) ;
F_51 ( V_64 ,
F_24 ( V_124 -> V_73 ) ) ;
}
}
static void F_48 ( unsigned int V_64 , int V_55 )
{
}
static void F_50 ( unsigned int V_64 , int V_55 )
{
}
static void F_52 ( unsigned int V_64 )
{
int V_66 ;
for ( V_66 = 0 ; V_66 < V_86 ; V_66 ++ )
F_50 ( V_64 , V_66 ) ;
F_53 ( F_40 ( V_123 , V_64 ) ) ;
F_40 ( V_123 , V_64 ) = NULL ;
}
static void F_54 ( void * V_125 )
{
int V_103 , * V_99 = V_125 , V_64 = F_12 () ;
for ( V_103 = 0 ; V_103 < V_86 ; V_103 ++ ) {
struct V_59 * V_54 = F_42 ( V_64 , V_103 ) ;
* V_99 = F_31 ( V_103 , & V_54 -> V_61 ) ;
if ( F_55 ( * V_99 < 0 ) ) {
int V_66 ;
for ( V_66 = 0 ; V_66 < V_103 ; V_66 ++ )
F_50 ( V_64 , V_66 ) ;
break;
}
F_48 ( V_64 , V_103 ) ;
}
}
static int F_56 ( unsigned int V_64 )
{
int V_99 ;
if ( V_86 == 0 )
return - V_126 ;
F_40 ( V_123 , V_64 ) = F_57 (
sizeof( struct V_59 ) * V_86 , V_127 ) ;
if ( F_40 ( V_123 , V_64 ) == NULL )
return - V_128 ;
F_58 ( V_64 , F_54 , & V_99 , true ) ;
if ( V_99 ) {
F_53 ( F_40 ( V_123 , V_64 ) ) ;
F_40 ( V_123 , V_64 ) = NULL ;
}
return V_99 ;
}
static T_2 F_59 ( struct V_59 * V_54 , char * V_60 ,
unsigned int V_64 )
{
return sprintf ( V_60 , L_5 , V_54 -> V_61 . V_81 / 1024 ) ;
}
static T_2 F_60 ( struct V_59 * V_54 ,
int type , char * V_60 )
{
T_4 V_129 = F_61 ( V_60 + V_130 - 1 , V_130 ) - V_60 ;
int V_104 = 0 ;
if ( V_129 > 1 ) {
const struct V_131 * V_132 ;
V_132 = F_24 ( V_54 -> V_73 ) ;
V_104 = type ?
F_62 ( V_60 , V_129 - 2 , V_132 ) :
F_63 ( V_60 , V_129 - 2 , V_132 ) ;
V_60 [ V_104 ++ ] = '\n' ;
V_60 [ V_104 ] = '\0' ;
}
return V_104 ;
}
static inline T_2 F_64 ( struct V_59 * V_1 , char * V_60 ,
unsigned int V_64 )
{
return F_60 ( V_1 , 0 , V_60 ) ;
}
static inline T_2 F_65 ( struct V_59 * V_1 , char * V_60 ,
unsigned int V_64 )
{
return F_60 ( V_1 , 1 , V_60 ) ;
}
static T_2 F_66 ( struct V_59 * V_54 , char * V_60 ,
unsigned int V_64 )
{
switch ( V_54 -> V_61 . V_3 . V_28 . type ) {
case V_100 :
return sprintf ( V_60 , L_6 ) ;
case V_101 :
return sprintf ( V_60 , L_7 ) ;
case V_133 :
return sprintf ( V_60 , L_8 ) ;
default:
return sprintf ( V_60 , L_9 ) ;
}
}
static struct V_134 * * F_67 ( void )
{
static struct V_134 * * V_135 ;
int V_104 ;
if ( V_135 )
return V_135 ;
V_104 = F_68 ( V_136 ) ;
if ( F_16 ( V_62 ) )
V_104 += 2 ;
if ( F_16 ( V_74 ) )
V_104 += 1 ;
V_135 = F_57 ( V_104 * sizeof ( struct V_134 * ) , V_127 ) ;
if ( V_135 == NULL )
return V_135 = V_136 ;
for ( V_104 = 0 ; V_136 [ V_104 ] ; V_104 ++ )
V_135 [ V_104 ] = V_136 [ V_104 ] ;
if ( F_16 ( V_62 ) ) {
V_135 [ V_104 ++ ] = & V_137 . V_138 ;
V_135 [ V_104 ++ ] = & V_139 . V_138 ;
}
if ( F_16 ( V_74 ) )
V_135 [ V_104 ++ ] = & V_49 . V_138 ;
return V_135 ;
}
static T_2 F_69 ( struct V_140 * V_141 , struct V_134 * V_138 , char * V_60 )
{
struct V_142 * V_143 = F_70 ( V_138 ) ;
struct V_144 * V_54 = F_71 ( V_141 ) ;
T_2 V_67 ;
V_67 = V_143 -> F_69 ?
V_143 -> F_69 ( F_42 ( V_54 -> V_64 , V_54 -> V_55 ) ,
V_60 , V_54 -> V_64 ) :
0 ;
return V_67 ;
}
static T_2 F_72 ( struct V_140 * V_141 , struct V_134 * V_138 ,
const char * V_60 , T_3 V_69 )
{
struct V_142 * V_143 = F_70 ( V_138 ) ;
struct V_144 * V_54 = F_71 ( V_141 ) ;
T_2 V_67 ;
V_67 = V_143 -> F_72 ?
V_143 -> F_72 ( F_42 ( V_54 -> V_64 , V_54 -> V_55 ) ,
V_60 , V_69 , V_54 -> V_64 ) :
0 ;
return V_67 ;
}
static void F_73 ( unsigned int V_64 )
{
F_53 ( F_40 ( V_145 , V_64 ) ) ;
F_53 ( F_40 ( V_146 , V_64 ) ) ;
F_40 ( V_145 , V_64 ) = NULL ;
F_40 ( V_146 , V_64 ) = NULL ;
F_52 ( V_64 ) ;
}
static int F_74 ( unsigned int V_64 )
{
int V_70 ;
if ( V_86 == 0 )
return - V_126 ;
V_70 = F_56 ( V_64 ) ;
if ( V_70 )
return V_70 ;
F_40 ( V_145 , V_64 ) =
F_57 ( sizeof( struct V_140 ) , V_127 ) ;
if ( F_55 ( F_40 ( V_145 , V_64 ) == NULL ) )
goto V_147;
F_40 ( V_146 , V_64 ) = F_57 (
sizeof( struct V_144 ) * V_86 , V_127 ) ;
if ( F_55 ( F_40 ( V_146 , V_64 ) == NULL ) )
goto V_147;
return 0 ;
V_147:
F_73 ( V_64 ) ;
return - V_128 ;
}
static int F_75 ( struct V_148 * V_149 )
{
unsigned int V_64 = V_149 -> V_150 ;
unsigned long V_66 , V_103 ;
struct V_144 * V_151 ;
struct V_59 * V_54 ;
int V_99 ;
V_99 = F_74 ( V_64 ) ;
if ( F_55 ( V_99 < 0 ) )
return V_99 ;
V_99 = F_76 ( F_40 ( V_145 , V_64 ) ,
& V_152 ,
& V_149 -> V_141 , L_10 , L_11 ) ;
if ( V_99 < 0 ) {
F_73 ( V_64 ) ;
return V_99 ;
}
for ( V_66 = 0 ; V_66 < V_86 ; V_66 ++ ) {
V_151 = F_77 ( V_64 , V_66 ) ;
V_151 -> V_64 = V_64 ;
V_151 -> V_55 = V_66 ;
V_54 = F_42 ( V_64 , V_66 ) ;
V_153 . V_136 = V_136 ;
#ifdef F_78
if ( V_54 -> V_61 . V_42 )
V_153 . V_136 = F_67 () ;
#endif
V_99 = F_76 ( & ( V_151 -> V_141 ) ,
& V_153 ,
F_40 ( V_145 , V_64 ) ,
L_12 , V_66 ) ;
if ( F_55 ( V_99 ) ) {
for ( V_103 = 0 ; V_103 < V_66 ; V_103 ++ )
F_79 ( & ( F_77 ( V_64 , V_103 ) -> V_141 ) ) ;
F_79 ( F_40 ( V_145 , V_64 ) ) ;
F_73 ( V_64 ) ;
return V_99 ;
}
F_80 ( & ( V_151 -> V_141 ) , V_154 ) ;
}
F_49 ( V_64 , F_24 ( V_155 ) ) ;
F_80 ( F_40 ( V_145 , V_64 ) , V_154 ) ;
return 0 ;
}
static void F_81 ( struct V_148 * V_149 )
{
unsigned int V_64 = V_149 -> V_150 ;
unsigned long V_66 ;
if ( F_40 ( V_123 , V_64 ) == NULL )
return;
if ( ! F_82 ( V_64 , F_24 ( V_155 ) ) )
return;
F_51 ( V_64 , F_24 ( V_155 ) ) ;
for ( V_66 = 0 ; V_66 < V_86 ; V_66 ++ )
F_79 ( & ( F_77 ( V_64 , V_66 ) -> V_141 ) ) ;
F_79 ( F_40 ( V_145 , V_64 ) ) ;
F_73 ( V_64 ) ;
}
static int F_83 ( struct V_156 * V_157 ,
unsigned long V_158 , void * V_159 )
{
unsigned int V_64 = ( unsigned long ) V_159 ;
struct V_148 * V_149 ;
V_149 = F_84 ( V_64 ) ;
switch ( V_158 ) {
case V_160 :
case V_161 :
F_75 ( V_149 ) ;
break;
case V_162 :
case V_163 :
F_81 ( V_149 ) ;
break;
}
return V_164 ;
}
static int T_5 F_85 ( void )
{
int V_66 ;
if ( V_86 == 0 )
return 0 ;
F_44 (i) {
int V_70 ;
struct V_148 * V_149 = F_84 ( V_66 ) ;
V_70 = F_75 ( V_149 ) ;
if ( V_70 )
return V_70 ;
}
F_86 ( & V_165 ) ;
return 0 ;
}
