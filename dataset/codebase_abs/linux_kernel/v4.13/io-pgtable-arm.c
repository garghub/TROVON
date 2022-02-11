static T_1 F_1 ( void * V_1 )
{
return ( T_1 ) F_2 ( V_1 ) ;
}
static void * F_3 ( T_2 V_2 , T_3 V_3 ,
struct V_4 * V_5 )
{
struct V_6 * V_7 = V_5 -> V_8 ;
T_1 V_9 ;
void * V_1 = F_4 ( V_2 , V_3 | V_10 ) ;
if ( ! V_1 )
return NULL ;
if ( ! ( V_5 -> V_11 & V_12 ) ) {
V_9 = F_5 ( V_7 , V_1 , V_2 , V_13 ) ;
if ( F_6 ( V_7 , V_9 ) )
goto V_14;
if ( V_9 != F_2 ( V_1 ) )
goto V_15;
}
return V_1 ;
V_15:
F_7 ( V_7 , L_1 ) ;
F_8 ( V_7 , V_9 , V_2 , V_13 ) ;
V_14:
F_9 ( V_1 , V_2 ) ;
return NULL ;
}
static void F_10 ( void * V_1 , T_2 V_2 ,
struct V_4 * V_5 )
{
if ( ! ( V_5 -> V_11 & V_12 ) )
F_8 ( V_5 -> V_8 , F_1 ( V_1 ) ,
V_2 , V_13 ) ;
F_9 ( V_1 , V_2 ) ;
}
static void F_11 ( T_4 * V_16 ,
struct V_4 * V_5 )
{
F_12 ( V_5 -> V_8 , F_1 ( V_16 ) ,
sizeof( * V_16 ) , V_13 ) ;
}
static void F_13 ( T_4 * V_16 , T_4 V_17 ,
struct V_4 * V_5 )
{
* V_16 = V_17 ;
if ( ! ( V_5 -> V_11 & V_12 ) )
F_11 ( V_16 , V_5 ) ;
}
static void F_14 ( struct V_18 * V_19 ,
T_5 V_20 , T_4 V_21 ,
int V_22 , T_4 * V_16 )
{
T_4 V_17 = V_21 ;
if ( V_19 -> V_23 . V_5 . V_11 & V_24 )
V_17 |= V_25 ;
if ( V_22 == V_26 - 1 )
V_17 |= V_27 ;
else
V_17 |= V_28 ;
V_17 |= V_29 | V_30 ;
V_17 |= F_15 ( V_20 >> V_19 -> V_31 , V_19 ) ;
F_13 ( V_16 , V_17 , & V_19 -> V_23 . V_5 ) ;
}
static int F_16 ( struct V_18 * V_19 ,
unsigned long V_32 , T_5 V_20 ,
T_4 V_21 , int V_22 ,
T_4 * V_16 )
{
T_4 V_17 = * V_16 ;
if ( F_17 ( V_17 , V_22 ) ) {
F_18 ( ! V_33 ) ;
return - V_34 ;
} else if ( F_19 ( V_17 , V_22 ) == V_35 ) {
T_4 * V_36 ;
T_2 V_37 = F_20 ( V_22 , V_19 ) ;
V_36 = V_16 - F_21 ( V_32 , V_22 , V_19 ) ;
if ( F_18 ( F_22 ( V_19 , V_32 , V_37 , V_22 , V_36 ) != V_37 ) )
return - V_38 ;
}
F_14 ( V_19 , V_20 , V_21 , V_22 , V_16 ) ;
return 0 ;
}
static T_4 F_23 ( T_4 * V_39 ,
T_4 * V_16 ,
T_4 V_40 ,
struct V_4 * V_5 )
{
T_4 V_41 , V_42 ;
V_42 = F_24 ( V_39 ) | V_35 ;
if ( V_5 -> V_11 & V_24 )
V_42 |= V_43 ;
F_25 () ;
V_41 = F_26 ( V_16 , V_40 , V_42 ) ;
if ( ( V_5 -> V_11 & V_12 ) ||
( V_41 & V_44 ) )
return V_41 ;
F_11 ( V_16 , V_5 ) ;
if ( V_41 == V_40 )
F_27 ( * V_16 , V_42 | V_44 ) ;
return V_41 ;
}
static int F_28 ( struct V_18 * V_19 , unsigned long V_32 ,
T_5 V_20 , T_2 V_2 , T_4 V_21 ,
int V_22 , T_4 * V_16 )
{
T_4 * V_45 , V_17 ;
T_2 V_46 = F_20 ( V_22 , V_19 ) ;
T_2 V_47 = F_29 ( V_19 ) ;
struct V_4 * V_5 = & V_19 -> V_23 . V_5 ;
V_16 += F_21 ( V_32 , V_22 , V_19 ) ;
if ( V_2 == V_46 && ( V_2 & V_5 -> V_48 ) )
return F_16 ( V_19 , V_32 , V_20 , V_21 , V_22 , V_16 ) ;
if ( F_18 ( V_22 >= V_26 - 1 ) )
return - V_38 ;
V_17 = F_30 ( * V_16 ) ;
if ( ! V_17 ) {
V_45 = F_3 ( V_47 , V_49 , V_5 ) ;
if ( ! V_45 )
return - V_50 ;
V_17 = F_23 ( V_45 , V_16 , 0 , V_5 ) ;
if ( V_17 )
F_10 ( V_45 , V_47 , V_5 ) ;
} else if ( ! ( V_5 -> V_11 & V_12 ) &&
! ( V_17 & V_44 ) ) {
F_11 ( V_16 , V_5 ) ;
}
if ( V_17 && ! F_17 ( V_17 , V_22 ) ) {
V_45 = F_31 ( V_17 , V_19 ) ;
} else if ( V_17 ) {
F_18 ( ! V_33 ) ;
return - V_34 ;
}
return F_28 ( V_19 , V_32 , V_20 , V_2 , V_21 , V_22 + 1 , V_45 ) ;
}
static T_4 F_32 ( struct V_18 * V_19 ,
int V_21 )
{
T_4 V_17 ;
if ( V_19 -> V_23 . V_51 == V_52 ||
V_19 -> V_23 . V_51 == V_53 ) {
V_17 = V_54 ;
if ( ! ( V_21 & V_55 ) && ( V_21 & V_56 ) )
V_17 |= V_57 ;
if ( ! ( V_21 & V_58 ) )
V_17 |= V_59 ;
if ( V_21 & V_60 )
V_17 |= ( V_61
<< V_62 ) ;
else if ( V_21 & V_63 )
V_17 |= ( V_64
<< V_62 ) ;
} else {
V_17 = V_65 ;
if ( V_21 & V_56 )
V_17 |= V_66 ;
if ( V_21 & V_55 )
V_17 |= V_67 ;
if ( V_21 & V_60 )
V_17 |= V_68 ;
else if ( V_21 & V_63 )
V_17 |= V_69 ;
else
V_17 |= V_70 ;
}
if ( V_21 & V_71 )
V_17 |= V_72 ;
return V_17 ;
}
static int F_33 ( struct V_73 * V_74 , unsigned long V_32 ,
T_5 V_20 , T_2 V_2 , int V_75 )
{
struct V_18 * V_19 = F_34 ( V_74 ) ;
T_4 * V_16 = V_19 -> V_76 ;
int V_77 , V_22 = F_35 ( V_19 ) ;
T_4 V_21 ;
if ( ! ( V_75 & ( V_56 | V_55 ) ) )
return 0 ;
if ( F_18 ( V_32 >= ( 1ULL << V_19 -> V_23 . V_5 . V_78 ) ||
V_20 >= ( 1ULL << V_19 -> V_23 . V_5 . V_79 ) ) )
return - V_80 ;
V_21 = F_32 ( V_19 , V_75 ) ;
V_77 = F_28 ( V_19 , V_32 , V_20 , V_2 , V_21 , V_22 , V_16 ) ;
F_36 () ;
return V_77 ;
}
static void F_37 ( struct V_18 * V_19 , int V_22 ,
T_4 * V_16 )
{
T_4 * V_81 , * V_82 ;
unsigned long V_83 ;
if ( V_22 == F_35 ( V_19 ) )
V_83 = V_19 -> V_84 ;
else
V_83 = F_29 ( V_19 ) ;
V_81 = V_16 ;
if ( V_22 == V_26 - 1 )
V_82 = V_16 ;
else
V_82 = ( void * ) V_16 + V_83 ;
while ( V_16 != V_82 ) {
T_4 V_17 = * V_16 ++ ;
if ( ! V_17 || F_17 ( V_17 , V_22 ) )
continue;
F_37 ( V_19 , V_22 + 1 , F_31 ( V_17 , V_19 ) ) ;
}
F_10 ( V_81 , V_83 , & V_19 -> V_23 . V_5 ) ;
}
static void F_38 ( struct V_85 * V_23 )
{
struct V_18 * V_19 = F_39 ( V_23 ) ;
F_37 ( V_19 , F_35 ( V_19 ) , V_19 -> V_76 ) ;
F_40 ( V_19 ) ;
}
static int F_41 ( struct V_18 * V_19 ,
unsigned long V_32 , T_2 V_2 ,
T_4 V_86 , int V_22 ,
T_4 * V_16 )
{
struct V_4 * V_5 = & V_19 -> V_23 . V_5 ;
T_4 V_17 , * V_87 ;
T_5 V_88 ;
T_2 V_89 = F_29 ( V_19 ) ;
T_2 V_90 = F_20 ( V_22 , V_19 ) ;
int V_91 , V_92 = - 1 ;
if ( F_18 ( V_22 == V_26 ) )
return 0 ;
V_87 = F_3 ( V_89 , V_49 , V_5 ) ;
if ( ! V_87 )
return 0 ;
if ( V_2 == V_90 )
V_92 = F_21 ( V_32 , V_22 , V_19 ) ;
V_88 = F_42 ( V_86 , V_19 ) << V_19 -> V_31 ;
V_17 = F_43 ( V_86 ) ;
for ( V_91 = 0 ; V_91 < V_89 / sizeof( V_17 ) ; V_91 ++ , V_88 += V_90 ) {
if ( V_91 == V_92 )
continue;
F_14 ( V_19 , V_88 , V_17 , V_22 , & V_87 [ V_91 ] ) ;
}
V_17 = F_23 ( V_87 , V_16 , V_86 , V_5 ) ;
if ( V_17 != V_86 ) {
F_10 ( V_87 , V_89 , V_5 ) ;
if ( F_19 ( V_17 , V_22 - 1 ) != V_35 )
return 0 ;
V_87 = F_31 ( V_17 , V_19 ) ;
}
if ( V_92 < 0 )
return F_22 ( V_19 , V_32 , V_2 , V_22 , V_87 ) ;
F_44 ( & V_19 -> V_23 , V_32 , V_2 , V_2 , true ) ;
return V_2 ;
}
static int F_22 ( struct V_18 * V_19 ,
unsigned long V_32 , T_2 V_2 , int V_22 ,
T_4 * V_16 )
{
T_4 V_17 ;
struct V_85 * V_23 = & V_19 -> V_23 ;
if ( F_18 ( V_22 == V_26 ) )
return 0 ;
V_16 += F_21 ( V_32 , V_22 , V_19 ) ;
V_17 = F_30 ( * V_16 ) ;
if ( F_18 ( ! V_17 ) )
return 0 ;
if ( V_2 == F_20 ( V_22 , V_19 ) ) {
F_13 ( V_16 , 0 , & V_23 -> V_5 ) ;
if ( ! F_17 ( V_17 , V_22 ) ) {
F_44 ( V_23 , V_32 , V_2 ,
F_29 ( V_19 ) , false ) ;
F_45 ( V_23 ) ;
V_16 = F_31 ( V_17 , V_19 ) ;
F_37 ( V_19 , V_22 + 1 , V_16 ) ;
} else {
F_44 ( V_23 , V_32 , V_2 , V_2 , true ) ;
}
return V_2 ;
} else if ( F_17 ( V_17 , V_22 ) ) {
return F_41 ( V_19 , V_32 , V_2 , V_17 ,
V_22 + 1 , V_16 ) ;
}
V_16 = F_31 ( V_17 , V_19 ) ;
return F_22 ( V_19 , V_32 , V_2 , V_22 + 1 , V_16 ) ;
}
static int F_46 ( struct V_73 * V_74 , unsigned long V_32 ,
T_2 V_2 )
{
T_2 V_93 ;
struct V_18 * V_19 = F_34 ( V_74 ) ;
T_4 * V_16 = V_19 -> V_76 ;
int V_22 = F_35 ( V_19 ) ;
if ( F_18 ( V_32 >= ( 1ULL << V_19 -> V_23 . V_5 . V_78 ) ) )
return 0 ;
V_93 = F_22 ( V_19 , V_32 , V_2 , V_22 , V_16 ) ;
if ( V_93 )
F_45 ( & V_19 -> V_23 ) ;
return V_93 ;
}
static T_5 F_47 ( struct V_73 * V_74 ,
unsigned long V_32 )
{
struct V_18 * V_19 = F_34 ( V_74 ) ;
T_4 V_17 , * V_16 = V_19 -> V_76 ;
int V_22 = F_35 ( V_19 ) ;
do {
if ( ! V_16 )
return 0 ;
V_16 += F_21 ( V_32 , V_22 , V_19 ) ;
V_17 = F_30 ( * V_16 ) ;
if ( ! V_17 )
return 0 ;
if ( F_17 ( V_17 , V_22 ) )
goto V_94;
V_16 = F_31 ( V_17 , V_19 ) ;
} while ( ++ V_22 < V_26 );
return 0 ;
V_94:
V_32 &= ( F_20 ( V_22 , V_19 ) - 1 ) ;
return ( ( T_5 ) F_42 ( V_17 , V_19 ) << V_19 -> V_31 ) | V_32 ;
}
static void F_48 ( struct V_4 * V_5 )
{
unsigned long V_95 ;
if ( V_5 -> V_48 & V_96 )
V_95 = V_96 ;
else if ( V_5 -> V_48 & ~ V_97 )
V_95 = 1UL << F_49 ( V_5 -> V_48 & ~ V_97 ) ;
else if ( V_5 -> V_48 & V_97 )
V_95 = 1UL << F_50 ( V_5 -> V_48 & V_97 ) ;
else
V_95 = 0 ;
switch ( V_95 ) {
case V_98 :
V_5 -> V_48 &= ( V_98 | V_99 | V_100 ) ;
break;
case V_101 :
V_5 -> V_48 &= ( V_101 | V_102 ) ;
break;
case V_103 :
V_5 -> V_48 &= ( V_103 | V_104 ) ;
break;
default:
V_5 -> V_48 = 0 ;
}
}
static struct V_18 *
F_51 ( struct V_4 * V_5 )
{
unsigned long V_105 , V_106 ;
struct V_18 * V_19 ;
F_48 ( V_5 ) ;
if ( ! ( V_5 -> V_48 & ( V_98 | V_101 | V_103 ) ) )
return NULL ;
if ( V_5 -> V_78 > V_107 )
return NULL ;
if ( V_5 -> V_79 > V_107 )
return NULL ;
if ( ! V_33 && V_5 -> V_8 -> V_108 ) {
F_7 ( V_5 -> V_8 , L_2 ) ;
return NULL ;
}
V_19 = F_52 ( sizeof( * V_19 ) , V_109 ) ;
if ( ! V_19 )
return NULL ;
V_19 -> V_31 = F_50 ( V_5 -> V_48 ) ;
V_19 -> V_110 = V_19 -> V_31 - F_53 ( sizeof( T_4 ) ) ;
V_105 = V_5 -> V_78 - V_19 -> V_31 ;
V_19 -> V_111 = F_54 ( V_105 , V_19 -> V_110 ) ;
V_106 = V_105 - ( V_19 -> V_110 * ( V_19 -> V_111 - 1 ) ) ;
V_19 -> V_84 = 1UL << ( V_106 + F_53 ( sizeof( T_4 ) ) ) ;
V_19 -> V_23 . V_74 = (struct V_73 ) {
. V_112 = F_33 ,
. V_113 = F_46 ,
. V_114 = F_47 ,
} ;
return V_19 ;
}
static struct V_85 *
F_55 ( struct V_4 * V_5 , void * V_115 )
{
T_6 V_116 ;
struct V_18 * V_19 ;
if ( V_5 -> V_11 & ~ ( V_24 | V_12 ) )
return NULL ;
V_19 = F_51 ( V_5 ) ;
if ( ! V_19 )
return NULL ;
V_116 = ( V_117 << V_118 ) |
( V_119 << V_120 ) |
( V_119 << V_121 ) ;
switch ( F_29 ( V_19 ) ) {
case V_98 :
V_116 |= V_122 ;
break;
case V_101 :
V_116 |= V_123 ;
break;
case V_103 :
V_116 |= V_124 ;
break;
}
switch ( V_5 -> V_79 ) {
case 32 :
V_116 |= ( V_125 << V_126 ) ;
break;
case 36 :
V_116 |= ( V_127 << V_126 ) ;
break;
case 40 :
V_116 |= ( V_128 << V_126 ) ;
break;
case 42 :
V_116 |= ( V_129 << V_126 ) ;
break;
case 44 :
V_116 |= ( V_130 << V_126 ) ;
break;
case 48 :
V_116 |= ( V_131 << V_126 ) ;
break;
default:
goto V_132;
}
V_116 |= ( 64ULL - V_5 -> V_78 ) << V_133 ;
V_116 |= V_134 ;
V_5 -> V_135 . V_136 = V_116 ;
V_116 = ( V_137
<< F_56 ( V_138 ) ) |
( V_139
<< F_56 ( V_64 ) ) |
( V_140
<< F_56 ( V_61 ) ) ;
V_5 -> V_135 . V_141 [ 0 ] = V_116 ;
V_5 -> V_135 . V_141 [ 1 ] = 0 ;
V_19 -> V_76 = F_3 ( V_19 -> V_84 , V_109 , V_5 ) ;
if ( ! V_19 -> V_76 )
goto V_132;
F_36 () ;
V_5 -> V_135 . V_142 [ 0 ] = F_2 ( V_19 -> V_76 ) ;
V_5 -> V_135 . V_142 [ 1 ] = 0 ;
return & V_19 -> V_23 ;
V_132:
F_40 ( V_19 ) ;
return NULL ;
}
static struct V_85 *
F_57 ( struct V_4 * V_5 , void * V_115 )
{
T_6 V_116 , V_143 ;
struct V_18 * V_19 ;
if ( V_5 -> V_11 & ~ V_12 )
return NULL ;
V_19 = F_51 ( V_5 ) ;
if ( ! V_19 )
return NULL ;
if ( V_19 -> V_111 == V_26 ) {
unsigned long V_144 ;
V_144 = V_19 -> V_84 >> F_53 ( sizeof( T_4 ) ) ;
if ( V_144 <= V_145 ) {
V_19 -> V_84 = V_144 << V_19 -> V_31 ;
V_19 -> V_111 -- ;
}
}
V_116 = V_146 |
( V_117 << V_118 ) |
( V_119 << V_120 ) |
( V_119 << V_121 ) ;
V_143 = F_35 ( V_19 ) ;
switch ( F_29 ( V_19 ) ) {
case V_98 :
V_116 |= V_122 ;
V_143 ++ ;
break;
case V_101 :
V_116 |= V_123 ;
break;
case V_103 :
V_116 |= V_124 ;
break;
}
switch ( V_5 -> V_79 ) {
case 32 :
V_116 |= ( V_125 << V_147 ) ;
break;
case 36 :
V_116 |= ( V_127 << V_147 ) ;
break;
case 40 :
V_116 |= ( V_128 << V_147 ) ;
break;
case 42 :
V_116 |= ( V_129 << V_147 ) ;
break;
case 44 :
V_116 |= ( V_130 << V_147 ) ;
break;
case 48 :
V_116 |= ( V_131 << V_147 ) ;
break;
default:
goto V_132;
}
V_116 |= ( 64ULL - V_5 -> V_78 ) << V_133 ;
V_116 |= ( ~ V_143 & V_148 ) << V_149 ;
V_5 -> V_150 . V_151 = V_116 ;
V_19 -> V_76 = F_3 ( V_19 -> V_84 , V_109 , V_5 ) ;
if ( ! V_19 -> V_76 )
goto V_132;
F_36 () ;
V_5 -> V_150 . V_152 = F_2 ( V_19 -> V_76 ) ;
return & V_19 -> V_23 ;
V_132:
F_40 ( V_19 ) ;
return NULL ;
}
static struct V_85 *
F_58 ( struct V_4 * V_5 , void * V_115 )
{
struct V_85 * V_23 ;
if ( V_5 -> V_78 > 32 || V_5 -> V_79 > 40 )
return NULL ;
V_5 -> V_48 &= ( V_98 | V_99 | V_100 ) ;
V_23 = F_55 ( V_5 , V_115 ) ;
if ( V_23 ) {
V_5 -> V_135 . V_136 |= V_153 ;
V_5 -> V_135 . V_136 &= 0xffffffff ;
}
return V_23 ;
}
static struct V_85 *
F_59 ( struct V_4 * V_5 , void * V_115 )
{
struct V_85 * V_23 ;
if ( V_5 -> V_78 > 40 || V_5 -> V_79 > 40 )
return NULL ;
V_5 -> V_48 &= ( V_98 | V_99 | V_100 ) ;
V_23 = F_57 ( V_5 , V_115 ) ;
if ( V_23 )
V_5 -> V_150 . V_151 &= 0xffffffff ;
return V_23 ;
}
static void F_60 ( void * V_115 )
{
F_18 ( V_115 != V_154 ) ;
}
static void F_61 ( unsigned long V_32 , T_2 V_2 ,
T_2 V_95 , bool V_155 , void * V_115 )
{
F_18 ( V_115 != V_154 ) ;
F_18 ( ! ( V_2 & V_154 -> V_48 ) ) ;
}
static void F_62 ( void * V_115 )
{
F_18 ( V_115 != V_154 ) ;
}
static void T_7 F_63 ( struct V_73 * V_74 )
{
struct V_18 * V_19 = F_34 ( V_74 ) ;
struct V_4 * V_5 = & V_19 -> V_23 . V_5 ;
F_64 ( L_3 ,
V_5 -> V_48 , V_5 -> V_78 ) ;
F_64 ( L_4 ,
V_19 -> V_111 , V_19 -> V_84 , V_19 -> V_31 ,
V_19 -> V_110 , V_19 -> V_76 ) ;
}
static int T_7 F_65 ( struct V_4 * V_5 )
{
static const enum V_156 V_157 [] = {
V_52 ,
V_158 ,
} ;
int V_91 , V_159 ;
unsigned long V_32 ;
T_2 V_2 ;
struct V_73 * V_74 ;
V_33 = true ;
for ( V_91 = 0 ; V_91 < F_66 ( V_157 ) ; ++ V_91 ) {
V_154 = V_5 ;
V_74 = F_67 ( V_157 [ V_91 ] , V_5 , V_5 ) ;
if ( ! V_74 ) {
F_64 ( L_5 ) ;
return - V_50 ;
}
if ( V_74 -> V_114 ( V_74 , 42 ) )
return F_68 ( V_74 , V_91 ) ;
if ( V_74 -> V_114 ( V_74 , V_100 + 42 ) )
return F_68 ( V_74 , V_91 ) ;
if ( V_74 -> V_114 ( V_74 , V_160 + 42 ) )
return F_68 ( V_74 , V_91 ) ;
V_32 = 0 ;
F_69 (j, &cfg->pgsize_bitmap, BITS_PER_LONG) {
V_2 = 1UL << V_159 ;
if ( V_74 -> V_112 ( V_74 , V_32 , V_32 , V_2 , V_56 |
V_55 |
V_71 |
V_63 ) )
return F_68 ( V_74 , V_91 ) ;
if ( ! V_74 -> V_112 ( V_74 , V_32 , V_32 + V_2 , V_2 ,
V_56 | V_71 ) )
return F_68 ( V_74 , V_91 ) ;
if ( V_74 -> V_114 ( V_74 , V_32 + 42 ) != ( V_32 + 42 ) )
return F_68 ( V_74 , V_91 ) ;
V_32 += V_100 ;
}
V_2 = 1UL << F_50 ( V_5 -> V_48 ) ;
if ( V_74 -> V_113 ( V_74 , V_100 + V_2 , V_2 ) != V_2 )
return F_68 ( V_74 , V_91 ) ;
if ( V_74 -> V_112 ( V_74 , V_100 + V_2 , V_2 , V_2 , V_56 ) )
return F_68 ( V_74 , V_91 ) ;
if ( V_74 -> V_114 ( V_74 , V_100 + V_2 + 42 ) != ( V_2 + 42 ) )
return F_68 ( V_74 , V_91 ) ;
V_32 = 0 ;
V_159 = F_70 ( & V_5 -> V_48 , V_161 ) ;
while ( V_159 != V_161 ) {
V_2 = 1UL << V_159 ;
if ( V_74 -> V_113 ( V_74 , V_32 , V_2 ) != V_2 )
return F_68 ( V_74 , V_91 ) ;
if ( V_74 -> V_114 ( V_74 , V_32 + 42 ) )
return F_68 ( V_74 , V_91 ) ;
if ( V_74 -> V_112 ( V_74 , V_32 , V_32 , V_2 , V_55 ) )
return F_68 ( V_74 , V_91 ) ;
if ( V_74 -> V_114 ( V_74 , V_32 + 42 ) != ( V_32 + 42 ) )
return F_68 ( V_74 , V_91 ) ;
V_32 += V_100 ;
V_159 ++ ;
V_159 = F_71 ( & V_5 -> V_48 , V_161 , V_159 ) ;
}
F_72 ( V_74 ) ;
}
V_33 = false ;
return 0 ;
}
static int T_7 F_73 ( void )
{
static const unsigned long V_162 [] = {
V_98 | V_99 | V_100 ,
V_101 | V_102 ,
V_103 | V_104 ,
} ;
static const unsigned int V_78 [] = {
32 , 36 , 40 , 42 , 44 , 48 ,
} ;
int V_91 , V_159 , V_163 = 0 , V_164 = 0 ;
struct V_4 V_5 = {
. V_165 = & V_166 ,
. V_79 = 48 ,
. V_11 = V_12 ,
} ;
for ( V_91 = 0 ; V_91 < F_66 ( V_162 ) ; ++ V_91 ) {
for ( V_159 = 0 ; V_159 < F_66 ( V_78 ) ; ++ V_159 ) {
V_5 . V_48 = V_162 [ V_91 ] ;
V_5 . V_78 = V_78 [ V_159 ] ;
F_74 ( L_6 ,
V_162 [ V_91 ] , V_78 [ V_159 ] ) ;
if ( F_65 ( & V_5 ) )
V_164 ++ ;
else
V_163 ++ ;
}
}
F_74 ( L_7 , V_163 , V_164 ) ;
return V_164 ? - V_167 : 0 ;
}
