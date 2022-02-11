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
static int F_10 ( struct V_41 * V_42 , unsigned V_53 )
{
unsigned int V_54 = 0 ;
F_6 ( V_42 -> V_48 , 0x1BC + V_53 * 4 , & V_54 ) ;
if ( V_54 & ( 3UL << 30 ) )
return V_54 & 0xfff ;
return - 1 ;
}
static T_2 F_11 ( struct V_55 * V_56 , char * V_57 ,
unsigned int V_53 )
{
int V_58 ;
struct V_41 * V_42 = V_56 -> V_59 ;
V_58 = F_10 ( V_42 , V_53 ) ;
if ( V_58 >= 0 )
return sprintf ( V_57 , L_1 , V_58 ) ;
return sprintf ( V_57 , L_2 ) ;
}
static void F_12 ( struct V_41 * V_42 , int V_60 ,
unsigned V_53 , unsigned long V_61 )
{
int V_62 ;
V_61 |= F_7 ( 30 ) ;
for ( V_62 = 0 ; V_62 < 4 ; V_62 ++ ) {
T_1 V_54 = V_61 | ( V_62 << 20 ) ;
if ( ! V_42 -> V_18 . V_49 [ V_62 ] )
continue;
F_13 ( V_42 -> V_48 , 0x1BC + V_53 * 4 , V_54 ) ;
F_14 ( V_60 ) ;
V_54 |= F_7 ( 31 ) ;
F_13 ( V_42 -> V_48 , 0x1BC + V_53 * 4 , V_54 ) ;
}
}
static int F_15 ( struct V_41 * V_42 , int V_60 ,
unsigned V_53 , unsigned long V_58 )
{
int V_63 = 0 ;
V_63 = F_10 ( V_42 , V_53 ) ;
if ( V_63 >= 0 )
return - V_64 ;
if ( V_58 > V_42 -> V_18 . V_52 )
return - V_65 ;
if ( V_58 == F_10 ( V_42 , ! V_53 ) )
return - V_64 ;
F_12 ( V_42 , V_60 , V_53 , V_58 ) ;
return 0 ;
}
static T_2 F_16 ( struct V_55 * V_56 ,
const char * V_57 , T_3 V_66 ,
unsigned int V_53 )
{
unsigned long V_22 = 0 ;
int V_60 , V_67 = 0 ;
struct V_41 * V_42 = V_56 -> V_59 ;
if ( ! F_17 ( V_68 ) )
return - V_69 ;
V_60 = F_18 ( & V_56 -> V_70 ) ;
if ( F_19 ( V_57 , 10 , & V_22 ) < 0 )
return - V_65 ;
V_67 = F_15 ( V_42 , V_60 , V_53 , V_22 ) ;
if ( V_67 ) {
if ( V_67 == - V_64 )
F_20 ( L_3 ,
V_53 ) ;
return V_67 ;
}
return V_66 ;
}
static T_2 F_21 ( struct V_71 * V_72 ,
struct V_73 * V_74 , char * V_57 )
{
struct V_55 * V_56 = F_22 ( V_72 ) ;
int V_60 = F_18 ( & V_56 -> V_70 ) ;
return sprintf ( V_57 , L_4 , F_23 ( V_60 ) ) ;
}
static T_2 F_24 ( struct V_71 * V_72 ,
struct V_73 * V_74 ,
const char * V_57 , T_3 V_66 )
{
struct V_55 * V_56 = F_22 ( V_72 ) ;
int V_60 = F_18 ( & V_56 -> V_70 ) ;
unsigned long V_22 ;
if ( ! F_17 ( V_68 ) )
return - V_69 ;
if ( F_19 ( V_57 , 16 , & V_22 ) < 0 )
return - V_65 ;
if ( F_25 ( V_60 , V_22 ) )
return - V_65 ;
return V_66 ;
}
static T_4
F_26 ( struct V_75 * V_76 ,
struct V_77 * V_74 , int V_78 )
{
struct V_71 * V_72 = F_27 ( V_76 ) ;
struct V_55 * V_56 = F_22 ( V_72 ) ;
T_4 V_79 = V_74 -> V_79 ;
if ( ! V_56 -> V_59 )
return 0 ;
if ( ( V_74 == & V_80 . V_74 ) &&
F_28 ( V_81 ) )
return V_79 ;
if ( ( V_74 == & V_82 . V_74 ||
V_74 == & V_83 . V_74 ) &&
F_28 ( V_84 ) )
return V_79 ;
return 0 ;
}
static void F_29 ( void )
{
int V_85 = 1 ;
static struct V_77 * * V_86 ;
if ( V_86 )
return;
if ( F_28 ( V_84 ) )
V_85 += 2 ;
if ( F_28 ( V_81 ) )
V_85 += 1 ;
V_86 = F_30 ( V_85 , sizeof( * V_86 ) , V_87 ) ;
if ( ! V_86 )
return;
V_85 = 0 ;
if ( F_28 ( V_84 ) ) {
V_86 [ V_85 ++ ] = & V_82 . V_74 ;
V_86 [ V_85 ++ ] = & V_83 . V_74 ;
}
if ( F_28 ( V_81 ) )
V_86 [ V_85 ++ ] = & V_80 . V_74 ;
V_88 . V_89 = V_86 ;
}
const struct V_90 *
F_31 ( struct V_55 * V_56 )
{
struct V_41 * V_42 = V_56 -> V_59 ;
if ( V_56 -> V_31 < 3 || ! V_42 )
return NULL ;
if ( V_42 && V_42 -> V_18 . V_52 )
F_29 () ;
return & V_88 ;
}
static void F_32 ( struct V_91 * V_56 , int V_58 )
{
int V_92 ;
if ( V_58 < 3 )
return;
V_92 = F_33 ( F_34 () ) ;
V_56 -> V_42 = F_35 ( V_92 ) ;
if ( V_56 -> V_42 && ! V_56 -> V_42 -> V_18 . V_52 )
F_5 ( V_56 -> V_42 ) ;
}
static int
F_36 ( int V_58 , struct V_91 * V_56 )
{
union V_2 V_3 ;
union V_4 V_5 ;
union V_6 V_7 ;
unsigned V_93 ;
if ( V_50 . V_94 == V_95 ) {
if ( F_4 ( V_96 ) )
F_37 ( 0x8000001d , V_58 , & V_3 . V_21 ,
& V_5 . V_21 , & V_7 . V_21 , & V_93 ) ;
else
F_1 ( V_58 , & V_3 , & V_5 , & V_7 ) ;
F_32 ( V_56 , V_58 ) ;
} else {
F_37 ( 4 , V_58 , & V_3 . V_21 , & V_5 . V_21 , & V_7 . V_21 , & V_93 ) ;
}
if ( V_3 . V_28 . type == V_97 )
return - V_98 ;
V_56 -> V_3 = V_3 ;
V_56 -> V_5 = V_5 ;
V_56 -> V_7 = V_7 ;
V_56 -> V_99 = ( V_7 . V_28 . V_40 + 1 ) *
( V_5 . V_28 . V_37 + 1 ) *
( V_5 . V_28 . V_39 + 1 ) *
( V_5 . V_28 . V_38 + 1 ) ;
return 0 ;
}
static int F_38 ( struct V_100 * V_101 )
{
unsigned int V_3 , V_5 , V_7 , V_93 , V_102 ;
union V_2 V_103 ;
int V_62 = - 1 ;
if ( V_101 -> V_94 == V_95 )
V_102 = 0x8000001d ;
else
V_102 = 4 ;
do {
++ V_62 ;
F_37 ( V_102 , V_62 , & V_3 , & V_5 , & V_7 , & V_93 ) ;
V_103 . V_21 = V_3 ;
} while ( V_103 . V_28 . type != V_97 );
return V_62 ;
}
void F_39 ( struct V_100 * V_101 )
{
if ( F_4 ( V_96 ) ) {
V_104 = F_38 ( V_101 ) ;
} else if ( V_101 -> V_105 >= 0x80000006 ) {
if ( F_40 ( 0x80000006 ) & 0xf000 )
V_104 = 4 ;
else
V_104 = 3 ;
}
}
unsigned int F_41 ( struct V_100 * V_101 )
{
unsigned int V_106 = 0 , V_14 = 0 , V_15 = 0 , V_17 = 0 , V_19 = 0 ;
unsigned int V_107 = 0 , V_108 = 0 ;
unsigned int V_109 = 0 , V_110 = 0 , V_62 ;
unsigned int V_111 = 0 , V_112 = 0 , V_33 , V_113 ;
#ifdef F_42
unsigned int V_60 = V_101 -> V_114 ;
#endif
if ( V_101 -> V_115 > 3 ) {
static int V_116 ;
if ( V_116 == 0 ) {
V_104 = F_38 ( V_101 ) ;
V_116 ++ ;
}
for ( V_62 = 0 ; V_62 < V_104 ; V_62 ++ ) {
struct V_91 V_56 = {} ;
int V_117 ;
V_117 = F_36 ( V_62 , & V_56 ) ;
if ( V_117 < 0 )
continue;
switch ( V_56 . V_3 . V_28 . V_31 ) {
case 1 :
if ( V_56 . V_3 . V_28 . type == V_118 )
V_107 = V_56 . V_99 / 1024 ;
else if ( V_56 . V_3 . V_28 . type == V_119 )
V_108 = V_56 . V_99 / 1024 ;
break;
case 2 :
V_109 = V_56 . V_99 / 1024 ;
V_33 = 1 + V_56 . V_3 . V_28 . V_33 ;
V_113 = F_43 ( V_33 ) ;
V_111 = V_101 -> V_120 & ~ ( ( 1 << V_113 ) - 1 ) ;
break;
case 3 :
V_110 = V_56 . V_99 / 1024 ;
V_33 = 1 + V_56 . V_3 . V_28 . V_33 ;
V_113 = F_43 ( V_33 ) ;
V_112 = V_101 -> V_120 & ~ ( ( 1 << V_113 ) - 1 ) ;
break;
default:
break;
}
}
}
if ( ( V_104 == 0 || V_101 -> V_51 == 15 ) && V_101 -> V_115 > 1 ) {
int V_121 , V_85 ;
unsigned int V_122 [ 4 ] ;
unsigned char * V_123 = ( unsigned char * ) V_122 ;
int V_124 = 0 ;
if ( V_104 != 0 && V_101 -> V_51 == 15 )
V_124 = 1 ;
V_85 = F_44 ( 2 ) & 0xFF ;
for ( V_62 = 0 ; V_62 < V_85 ; V_62 ++ ) {
F_2 ( 2 , & V_122 [ 0 ] , & V_122 [ 1 ] , & V_122 [ 2 ] , & V_122 [ 3 ] ) ;
for ( V_121 = 0 ; V_121 < 3 ; V_121 ++ )
if ( V_122 [ V_121 ] & ( 1 << 31 ) )
V_122 [ V_121 ] = 0 ;
for ( V_121 = 1 ; V_121 < 16 ; V_121 ++ ) {
unsigned char V_125 = V_123 [ V_121 ] ;
unsigned char V_126 = 0 ;
while ( V_127 [ V_126 ] . V_128 != 0 ) {
if ( V_127 [ V_126 ] . V_128 == V_125 ) {
if ( V_124 && V_127 [ V_126 ] . V_129 != V_130 )
break;
switch ( V_127 [ V_126 ] . V_129 ) {
case V_131 :
V_14 += V_127 [ V_126 ] . V_99 ;
break;
case V_132 :
V_15 += V_127 [ V_126 ] . V_99 ;
break;
case V_133 :
V_17 += V_127 [ V_126 ] . V_99 ;
break;
case V_134 :
V_19 += V_127 [ V_126 ] . V_99 ;
break;
case V_130 :
V_106 += V_127 [ V_126 ] . V_99 ;
break;
}
break;
}
V_126 ++ ;
}
}
}
}
if ( V_107 )
V_15 = V_107 ;
if ( V_108 )
V_14 = V_108 ;
if ( V_109 ) {
V_17 = V_109 ;
#ifdef F_42
F_45 ( V_135 , V_60 ) = V_111 ;
#endif
}
if ( V_110 ) {
V_19 = V_110 ;
#ifdef F_42
F_45 ( V_135 , V_60 ) = V_112 ;
#endif
}
#ifdef F_42
if ( F_45 ( V_135 , V_60 ) == V_136 )
F_45 ( V_135 , V_60 ) = V_101 -> V_137 ;
#endif
V_101 -> V_25 = V_19 ? V_19 : ( V_17 ? V_17 : ( V_14 + V_15 ) ) ;
return V_17 ;
}
static int F_46 ( unsigned int V_60 , int V_58 ,
struct V_91 * V_138 )
{
struct V_139 * V_140 = F_47 ( V_60 ) ;
struct V_55 * V_56 ;
int V_62 , V_141 ;
if ( F_4 ( V_96 ) ) {
unsigned int V_120 , V_142 , V_143 , V_144 ;
V_56 = V_140 -> V_145 + V_58 ;
V_142 = V_138 -> V_3 . V_28 . V_33 + 1 ;
V_120 = F_48 ( V_60 ) . V_120 ;
V_143 = V_120 - ( V_120 % V_142 ) ;
V_144 = V_143 + V_142 - 1 ;
F_49 (i) {
V_140 = F_47 ( V_62 ) ;
if ( ! V_140 -> V_145 )
continue;
V_120 = F_48 ( V_62 ) . V_120 ;
if ( ( V_120 < V_143 ) || ( V_120 > V_144 ) )
continue;
V_56 = V_140 -> V_145 + V_58 ;
F_49 (sibling) {
V_120 = F_48 ( V_141 ) . V_120 ;
if ( ( V_120 < V_143 ) || ( V_120 > V_144 ) )
continue;
F_50 ( V_141 ,
& V_56 -> V_70 ) ;
}
}
} else if ( V_58 == 3 ) {
F_51 (i, cpu_llc_shared_mask(cpu)) {
V_140 = F_47 ( V_62 ) ;
if ( ! V_140 -> V_145 )
continue;
V_56 = V_140 -> V_145 + V_58 ;
F_51 (sibling, cpu_llc_shared_mask(cpu)) {
if ( ! F_52 ( V_141 ) )
continue;
F_50 ( V_141 ,
& V_56 -> V_70 ) ;
}
}
} else
return 0 ;
return 1 ;
}
static void F_53 ( unsigned int V_60 , int V_58 ,
struct V_91 * V_138 )
{
struct V_139 * V_140 = F_47 ( V_60 ) ;
struct V_55 * V_56 , * V_146 ;
unsigned long V_33 ;
int V_113 , V_62 ;
struct V_100 * V_101 = & F_48 ( V_60 ) ;
if ( V_101 -> V_94 == V_95 ) {
if ( F_46 ( V_60 , V_58 , V_138 ) )
return;
}
V_56 = V_140 -> V_145 + V_58 ;
V_33 = 1 + V_138 -> V_3 . V_28 . V_33 ;
F_50 ( V_60 , & V_56 -> V_70 ) ;
if ( V_33 == 1 )
return;
V_113 = F_43 ( V_33 ) ;
F_49 (i)
if ( F_48 ( V_62 ) . V_120 >> V_113 == V_101 -> V_120 >> V_113 ) {
struct V_139 * V_147 = F_47 ( V_62 ) ;
if ( V_62 == V_60 || ! V_147 -> V_145 )
continue;
V_146 = V_147 -> V_145 + V_58 ;
F_50 ( V_62 , & V_56 -> V_70 ) ;
F_50 ( V_60 , & V_146 -> V_70 ) ;
}
}
static void F_54 ( struct V_55 * V_56 ,
struct V_91 * V_138 )
{
V_56 -> V_31 = V_138 -> V_3 . V_28 . V_31 ;
V_56 -> type = V_148 [ V_138 -> V_3 . V_28 . type ] ;
V_56 -> V_37 =
V_138 -> V_5 . V_28 . V_37 + 1 ;
V_56 -> V_38 =
V_138 -> V_5 . V_28 . V_38 + 1 ;
V_56 -> V_99 = V_138 -> V_99 ;
V_56 -> V_40 = V_138 -> V_7 . V_28 . V_40 + 1 ;
V_56 -> V_39 =
V_138 -> V_5 . V_28 . V_39 + 1 ;
V_56 -> V_59 = V_138 -> V_42 ;
}
static int F_55 ( unsigned int V_60 )
{
struct V_139 * V_140 = F_47 ( V_60 ) ;
if ( ! V_104 )
return - V_149 ;
if ( ! V_140 )
return - V_65 ;
V_140 -> V_150 = 3 ;
V_140 -> V_151 = V_104 ;
return 0 ;
}
static int F_56 ( unsigned int V_60 )
{
unsigned int V_61 , V_63 ;
struct V_139 * V_140 = F_47 ( V_60 ) ;
struct V_55 * V_56 = V_140 -> V_145 ;
struct V_91 V_152 = {} ;
for ( V_61 = 0 ; V_61 < V_140 -> V_151 ; V_61 ++ ) {
V_63 = F_36 ( V_61 , & V_152 ) ;
if ( V_63 )
return V_63 ;
F_54 ( V_56 ++ , & V_152 ) ;
F_53 ( V_60 , V_61 , & V_152 ) ;
}
return 0 ;
}
