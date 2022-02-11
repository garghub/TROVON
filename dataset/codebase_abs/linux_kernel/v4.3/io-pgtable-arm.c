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
if ( ! V_11 ) {
V_9 = F_5 ( V_7 , V_1 , V_2 , V_12 ) ;
if ( F_6 ( V_7 , V_9 ) )
goto V_13;
if ( V_9 != F_2 ( V_1 ) )
goto V_14;
}
return V_1 ;
V_14:
F_7 ( V_7 , L_1 ) ;
F_8 ( V_7 , V_9 , V_2 , V_12 ) ;
V_13:
F_9 ( V_1 , V_2 ) ;
return NULL ;
}
static void F_10 ( void * V_1 , T_2 V_2 ,
struct V_4 * V_5 )
{
if ( ! V_11 )
F_8 ( V_5 -> V_8 , F_1 ( V_1 ) ,
V_2 , V_12 ) ;
F_9 ( V_1 , V_2 ) ;
}
static void F_11 ( T_4 * V_15 , T_4 V_16 ,
struct V_4 * V_5 )
{
* V_15 = V_16 ;
if ( ! V_11 )
F_12 ( V_5 -> V_8 ,
F_1 ( V_15 ) ,
sizeof( V_16 ) , V_12 ) ;
}
static int F_13 ( struct V_17 * V_18 ,
unsigned long V_19 , T_5 V_20 ,
T_4 V_21 , int V_22 ,
T_4 * V_15 )
{
T_4 V_16 = V_21 ;
struct V_4 * V_5 = & V_18 -> V_23 . V_5 ;
if ( F_14 ( * V_15 , V_22 ) ) {
F_15 ( ! V_11 ) ;
return - V_24 ;
} else if ( F_16 ( * V_15 , V_22 ) == V_25 ) {
T_4 * V_26 ;
T_2 V_27 = F_17 ( V_22 , V_18 ) ;
V_26 = V_15 - F_18 ( V_19 , V_22 , V_18 ) ;
if ( F_15 ( F_19 ( V_18 , V_19 , V_27 , V_22 , V_26 ) != V_27 ) )
return - V_28 ;
}
if ( V_5 -> V_29 & V_30 )
V_16 |= V_31 ;
if ( V_22 == V_32 - 1 )
V_16 |= V_33 ;
else
V_16 |= V_34 ;
V_16 |= V_35 | V_36 ;
V_16 |= F_20 ( V_20 >> V_18 -> V_37 , V_18 ) ;
F_11 ( V_15 , V_16 , V_5 ) ;
return 0 ;
}
static int F_21 ( struct V_17 * V_18 , unsigned long V_19 ,
T_5 V_20 , T_2 V_2 , T_4 V_21 ,
int V_22 , T_4 * V_15 )
{
T_4 * V_38 , V_16 ;
T_2 V_39 = F_17 ( V_22 , V_18 ) ;
struct V_4 * V_5 = & V_18 -> V_23 . V_5 ;
V_15 += F_18 ( V_19 , V_22 , V_18 ) ;
if ( V_2 == V_39 && ( V_2 & V_5 -> V_40 ) )
return F_13 ( V_18 , V_19 , V_20 , V_21 , V_22 , V_15 ) ;
if ( F_15 ( V_22 >= V_32 - 1 ) )
return - V_28 ;
V_16 = * V_15 ;
if ( ! V_16 ) {
V_38 = F_3 ( 1UL << V_18 -> V_37 ,
V_41 , V_5 ) ;
if ( ! V_38 )
return - V_42 ;
V_16 = F_22 ( V_38 ) | V_25 ;
if ( V_5 -> V_29 & V_30 )
V_16 |= V_43 ;
F_11 ( V_15 , V_16 , V_5 ) ;
} else {
V_38 = F_23 ( V_16 , V_18 ) ;
}
return F_21 ( V_18 , V_19 , V_20 , V_2 , V_21 , V_22 + 1 , V_38 ) ;
}
static T_4 F_24 ( struct V_17 * V_18 ,
int V_21 )
{
T_4 V_16 ;
if ( V_18 -> V_23 . V_44 == V_45 ||
V_18 -> V_23 . V_44 == V_46 ) {
V_16 = V_47 | V_48 ;
if ( ! ( V_21 & V_49 ) && ( V_21 & V_50 ) )
V_16 |= V_51 ;
if ( V_21 & V_52 )
V_16 |= ( V_53
<< V_54 ) ;
} else {
V_16 = V_55 ;
if ( V_21 & V_50 )
V_16 |= V_56 ;
if ( V_21 & V_49 )
V_16 |= V_57 ;
if ( V_21 & V_52 )
V_16 |= V_58 ;
else
V_16 |= V_59 ;
}
if ( V_21 & V_60 )
V_16 |= V_61 ;
return V_16 ;
}
static int F_25 ( struct V_62 * V_63 , unsigned long V_19 ,
T_5 V_20 , T_2 V_2 , int V_64 )
{
struct V_17 * V_18 = F_26 ( V_63 ) ;
T_4 * V_15 = V_18 -> V_65 ;
int V_66 , V_22 = F_27 ( V_18 ) ;
T_4 V_21 ;
if ( ! ( V_64 & ( V_50 | V_49 ) ) )
return 0 ;
V_21 = F_24 ( V_18 , V_64 ) ;
V_66 = F_21 ( V_18 , V_19 , V_20 , V_2 , V_21 , V_22 , V_15 ) ;
F_28 () ;
return V_66 ;
}
static void F_29 ( struct V_17 * V_18 , int V_22 ,
T_4 * V_15 )
{
T_4 * V_67 , * V_68 ;
unsigned long V_69 ;
if ( V_22 == V_32 - 1 )
return;
if ( V_22 == F_27 ( V_18 ) )
V_69 = V_18 -> V_70 ;
else
V_69 = 1UL << V_18 -> V_37 ;
V_67 = V_15 ;
V_68 = ( void * ) V_15 + V_69 ;
while ( V_15 != V_68 ) {
T_4 V_16 = * V_15 ++ ;
if ( ! V_16 || F_14 ( V_16 , V_22 ) )
continue;
F_29 ( V_18 , V_22 + 1 , F_23 ( V_16 , V_18 ) ) ;
}
F_10 ( V_67 , V_69 , & V_18 -> V_23 . V_5 ) ;
}
static void F_30 ( struct V_71 * V_23 )
{
struct V_17 * V_18 = F_31 ( V_23 ) ;
F_29 ( V_18 , F_27 ( V_18 ) , V_18 -> V_65 ) ;
F_32 ( V_18 ) ;
}
static int F_33 ( struct V_17 * V_18 ,
unsigned long V_19 , T_2 V_2 ,
T_4 V_21 , int V_22 ,
T_4 * V_15 , T_2 V_72 )
{
unsigned long V_73 , V_74 ;
T_5 V_75 ;
T_4 V_76 = 0 ;
struct V_4 * V_5 = & V_18 -> V_23 . V_5 ;
V_73 = V_19 & ~ ( V_72 - 1 ) ;
V_74 = V_73 + V_72 ;
V_75 = F_34 ( * V_15 , V_18 ) << V_18 -> V_37 ;
for (; V_73 < V_74 ; V_73 += V_2 , V_75 += V_2 ) {
T_4 * V_77 ;
if ( V_73 == V_19 )
continue;
V_77 = & V_76 - F_18 ( V_73 , V_22 , V_18 ) ;
if ( F_21 ( V_18 , V_73 , V_75 , V_2 , V_21 , V_22 ,
V_77 ) < 0 ) {
if ( V_76 ) {
V_77 = F_23 ( V_76 , V_18 ) ;
F_29 ( V_18 , V_22 + 1 , V_77 ) ;
}
return 0 ;
}
}
F_11 ( V_15 , V_76 , V_5 ) ;
V_19 &= ~ ( V_72 - 1 ) ;
V_5 -> V_78 -> V_79 ( V_19 , V_72 , true , V_18 -> V_23 . V_80 ) ;
return V_2 ;
}
static int F_19 ( struct V_17 * V_18 ,
unsigned long V_19 , T_2 V_2 , int V_22 ,
T_4 * V_15 )
{
T_4 V_16 ;
const struct V_81 * V_78 = V_18 -> V_23 . V_5 . V_78 ;
void * V_80 = V_18 -> V_23 . V_80 ;
T_2 V_72 = F_17 ( V_22 , V_18 ) ;
V_15 += F_18 ( V_19 , V_22 , V_18 ) ;
V_16 = * V_15 ;
if ( F_15 ( ! V_16 || ( V_22 == V_32 ) ) )
return 0 ;
if ( V_2 == V_72 ) {
F_11 ( V_15 , 0 , & V_18 -> V_23 . V_5 ) ;
if ( ! F_14 ( V_16 , V_22 ) ) {
V_78 -> V_79 ( V_19 , V_2 , false , V_80 ) ;
V_78 -> V_82 ( V_80 ) ;
V_15 = F_23 ( V_16 , V_18 ) ;
F_29 ( V_18 , V_22 + 1 , V_15 ) ;
} else {
V_78 -> V_79 ( V_19 , V_2 , true , V_80 ) ;
}
return V_2 ;
} else if ( F_14 ( V_16 , V_22 ) ) {
return F_33 ( V_18 , V_19 , V_2 ,
F_35 ( V_16 ) , V_22 , V_15 ,
V_72 ) ;
}
V_15 = F_23 ( V_16 , V_18 ) ;
return F_19 ( V_18 , V_19 , V_2 , V_22 + 1 , V_15 ) ;
}
static int F_36 ( struct V_62 * V_63 , unsigned long V_19 ,
T_2 V_2 )
{
T_2 V_83 ;
struct V_17 * V_18 = F_26 ( V_63 ) ;
struct V_71 * V_23 = & V_18 -> V_23 ;
T_4 * V_15 = V_18 -> V_65 ;
int V_22 = F_27 ( V_18 ) ;
V_83 = F_19 ( V_18 , V_19 , V_2 , V_22 , V_15 ) ;
if ( V_83 )
V_23 -> V_5 . V_78 -> V_82 ( V_23 -> V_80 ) ;
return V_83 ;
}
static T_5 F_37 ( struct V_62 * V_63 ,
unsigned long V_19 )
{
struct V_17 * V_18 = F_26 ( V_63 ) ;
T_4 V_16 , * V_15 = V_18 -> V_65 ;
int V_22 = F_27 ( V_18 ) ;
do {
if ( ! V_15 )
return 0 ;
V_16 = * ( V_15 + F_18 ( V_19 , V_22 , V_18 ) ) ;
if ( ! V_16 )
return 0 ;
if ( F_14 ( V_16 , V_22 ) )
goto V_84;
V_15 = F_23 ( V_16 , V_18 ) ;
} while ( ++ V_22 < V_32 );
return 0 ;
V_84:
V_19 &= ( ( 1 << V_18 -> V_37 ) - 1 ) ;
return ( ( T_5 ) F_34 ( V_16 , V_18 ) << V_18 -> V_37 ) | V_19 ;
}
static void F_38 ( struct V_4 * V_5 )
{
unsigned long V_85 ;
if ( V_5 -> V_40 & V_86 )
V_85 = V_86 ;
else if ( V_5 -> V_40 & ~ V_87 )
V_85 = 1UL << F_39 ( V_5 -> V_40 & ~ V_87 ) ;
else if ( V_5 -> V_40 & V_87 )
V_85 = 1UL << F_40 ( V_5 -> V_40 & V_87 ) ;
else
V_85 = 0 ;
switch ( V_85 ) {
case V_88 :
V_5 -> V_40 &= ( V_88 | V_89 | V_90 ) ;
break;
case V_91 :
V_5 -> V_40 &= ( V_91 | V_92 ) ;
break;
case V_93 :
V_5 -> V_40 &= ( V_93 | V_94 ) ;
break;
default:
V_5 -> V_40 = 0 ;
}
}
static struct V_17 *
F_41 ( struct V_4 * V_5 )
{
unsigned long V_95 , V_96 ;
struct V_17 * V_18 ;
F_38 ( V_5 ) ;
if ( ! ( V_5 -> V_40 & ( V_88 | V_91 | V_93 ) ) )
return NULL ;
if ( V_5 -> V_97 > V_98 )
return NULL ;
if ( V_5 -> V_99 > V_98 )
return NULL ;
if ( ! V_11 && V_5 -> V_8 -> V_100 ) {
F_7 ( V_5 -> V_8 , L_2 ) ;
return NULL ;
}
V_18 = F_42 ( sizeof( * V_18 ) , V_101 ) ;
if ( ! V_18 )
return NULL ;
V_18 -> V_37 = F_40 ( V_5 -> V_40 ) ;
V_18 -> V_102 = V_18 -> V_37 - F_43 ( sizeof( T_4 ) ) ;
V_95 = V_5 -> V_97 - V_18 -> V_37 ;
V_18 -> V_103 = F_44 ( V_95 , V_18 -> V_102 ) ;
V_96 = V_95 - ( V_18 -> V_102 * ( V_18 -> V_103 - 1 ) ) ;
V_18 -> V_70 = 1UL << ( V_96 + F_43 ( sizeof( T_4 ) ) ) ;
V_18 -> V_23 . V_63 = (struct V_62 ) {
. V_104 = F_25 ,
. V_105 = F_36 ,
. V_106 = F_37 ,
} ;
return V_18 ;
}
static struct V_71 *
F_45 ( struct V_4 * V_5 , void * V_80 )
{
T_6 V_107 ;
struct V_17 * V_18 = F_41 ( V_5 ) ;
if ( ! V_18 )
return NULL ;
V_107 = ( V_108 << V_109 ) |
( V_110 << V_111 ) |
( V_110 << V_112 ) ;
switch ( 1 << V_18 -> V_37 ) {
case V_88 :
V_107 |= V_113 ;
break;
case V_91 :
V_107 |= V_114 ;
break;
case V_93 :
V_107 |= V_115 ;
break;
}
switch ( V_5 -> V_99 ) {
case 32 :
V_107 |= ( V_116 << V_117 ) ;
break;
case 36 :
V_107 |= ( V_118 << V_117 ) ;
break;
case 40 :
V_107 |= ( V_119 << V_117 ) ;
break;
case 42 :
V_107 |= ( V_120 << V_117 ) ;
break;
case 44 :
V_107 |= ( V_121 << V_117 ) ;
break;
case 48 :
V_107 |= ( V_122 << V_117 ) ;
break;
default:
goto V_123;
}
V_107 |= ( 64ULL - V_5 -> V_97 ) << V_124 ;
V_107 |= V_125 ;
V_5 -> V_126 . V_127 = V_107 ;
V_107 = ( V_128
<< F_46 ( V_129 ) ) |
( V_130
<< F_46 ( V_53 ) ) |
( V_131
<< F_46 ( V_132 ) ) ;
V_5 -> V_126 . V_133 [ 0 ] = V_107 ;
V_5 -> V_126 . V_133 [ 1 ] = 0 ;
V_18 -> V_65 = F_3 ( V_18 -> V_70 , V_101 , V_5 ) ;
if ( ! V_18 -> V_65 )
goto V_123;
F_28 () ;
V_5 -> V_126 . V_134 [ 0 ] = F_2 ( V_18 -> V_65 ) ;
V_5 -> V_126 . V_134 [ 1 ] = 0 ;
return & V_18 -> V_23 ;
V_123:
F_32 ( V_18 ) ;
return NULL ;
}
static struct V_71 *
F_47 ( struct V_4 * V_5 , void * V_80 )
{
T_6 V_107 , V_135 ;
struct V_17 * V_18 = F_41 ( V_5 ) ;
if ( ! V_18 )
return NULL ;
if ( V_18 -> V_103 == V_32 ) {
unsigned long V_136 ;
V_136 = V_18 -> V_70 >> F_43 ( sizeof( T_4 ) ) ;
if ( V_136 <= V_137 ) {
V_18 -> V_70 = V_136 << V_18 -> V_37 ;
V_18 -> V_103 -- ;
}
}
V_107 = V_138 |
( V_108 << V_109 ) |
( V_110 << V_111 ) |
( V_110 << V_112 ) ;
V_135 = F_27 ( V_18 ) ;
switch ( 1 << V_18 -> V_37 ) {
case V_88 :
V_107 |= V_113 ;
V_135 ++ ;
break;
case V_91 :
V_107 |= V_114 ;
break;
case V_93 :
V_107 |= V_115 ;
break;
}
switch ( V_5 -> V_99 ) {
case 32 :
V_107 |= ( V_116 << V_139 ) ;
break;
case 36 :
V_107 |= ( V_118 << V_139 ) ;
break;
case 40 :
V_107 |= ( V_119 << V_139 ) ;
break;
case 42 :
V_107 |= ( V_120 << V_139 ) ;
break;
case 44 :
V_107 |= ( V_121 << V_139 ) ;
break;
case 48 :
V_107 |= ( V_122 << V_139 ) ;
break;
default:
goto V_123;
}
V_107 |= ( 64ULL - V_5 -> V_97 ) << V_124 ;
V_107 |= ( ~ V_135 & V_140 ) << V_141 ;
V_5 -> V_142 . V_143 = V_107 ;
V_18 -> V_65 = F_3 ( V_18 -> V_70 , V_101 , V_5 ) ;
if ( ! V_18 -> V_65 )
goto V_123;
F_28 () ;
V_5 -> V_142 . V_144 = F_2 ( V_18 -> V_65 ) ;
return & V_18 -> V_23 ;
V_123:
F_32 ( V_18 ) ;
return NULL ;
}
static struct V_71 *
F_48 ( struct V_4 * V_5 , void * V_80 )
{
struct V_71 * V_23 ;
if ( V_5 -> V_97 > 32 || V_5 -> V_99 > 40 )
return NULL ;
V_5 -> V_40 &= ( V_88 | V_89 | V_90 ) ;
V_23 = F_45 ( V_5 , V_80 ) ;
if ( V_23 ) {
V_5 -> V_126 . V_127 |= V_145 ;
V_5 -> V_126 . V_127 &= 0xffffffff ;
}
return V_23 ;
}
static struct V_71 *
F_49 ( struct V_4 * V_5 , void * V_80 )
{
struct V_71 * V_23 ;
if ( V_5 -> V_97 > 40 || V_5 -> V_99 > 40 )
return NULL ;
V_5 -> V_40 &= ( V_88 | V_89 | V_90 ) ;
V_23 = F_47 ( V_5 , V_80 ) ;
if ( V_23 )
V_5 -> V_142 . V_143 &= 0xffffffff ;
return V_23 ;
}
static void F_50 ( void * V_80 )
{
F_15 ( V_80 != V_146 ) ;
}
static void F_51 ( unsigned long V_19 , T_2 V_2 , bool V_147 ,
void * V_80 )
{
F_15 ( V_80 != V_146 ) ;
F_15 ( ! ( V_2 & V_146 -> V_40 ) ) ;
}
static void F_52 ( void * V_80 )
{
F_15 ( V_80 != V_146 ) ;
}
static void T_7 F_53 ( struct V_62 * V_63 )
{
struct V_17 * V_18 = F_26 ( V_63 ) ;
struct V_4 * V_5 = & V_18 -> V_23 . V_5 ;
F_54 ( L_3 ,
V_5 -> V_40 , V_5 -> V_97 ) ;
F_54 ( L_4 ,
V_18 -> V_103 , V_18 -> V_70 , V_18 -> V_37 ,
V_18 -> V_102 , V_18 -> V_65 ) ;
}
static int T_7 F_55 ( struct V_4 * V_5 )
{
static const enum V_148 V_149 [] = {
V_45 ,
V_150 ,
} ;
int V_151 , V_152 ;
unsigned long V_19 ;
T_2 V_2 ;
struct V_62 * V_63 ;
V_11 = true ;
for ( V_151 = 0 ; V_151 < F_56 ( V_149 ) ; ++ V_151 ) {
V_146 = V_5 ;
V_63 = F_57 ( V_149 [ V_151 ] , V_5 , V_5 ) ;
if ( ! V_63 ) {
F_54 ( L_5 ) ;
return - V_42 ;
}
if ( V_63 -> V_106 ( V_63 , 42 ) )
return F_58 ( V_63 , V_151 ) ;
if ( V_63 -> V_106 ( V_63 , V_90 + 42 ) )
return F_58 ( V_63 , V_151 ) ;
if ( V_63 -> V_106 ( V_63 , V_153 + 42 ) )
return F_58 ( V_63 , V_151 ) ;
V_19 = 0 ;
V_152 = F_59 ( & V_5 -> V_40 , V_154 ) ;
while ( V_152 != V_154 ) {
V_2 = 1UL << V_152 ;
if ( V_63 -> V_104 ( V_63 , V_19 , V_19 , V_2 , V_50 |
V_49 |
V_60 |
V_52 ) )
return F_58 ( V_63 , V_151 ) ;
if ( ! V_63 -> V_104 ( V_63 , V_19 , V_19 + V_2 , V_2 ,
V_50 | V_60 ) )
return F_58 ( V_63 , V_151 ) ;
if ( V_63 -> V_106 ( V_63 , V_19 + 42 ) != ( V_19 + 42 ) )
return F_58 ( V_63 , V_151 ) ;
V_19 += V_90 ;
V_152 ++ ;
V_152 = F_60 ( & V_5 -> V_40 , V_154 , V_152 ) ;
}
V_2 = 1UL << F_40 ( V_5 -> V_40 ) ;
if ( V_63 -> V_105 ( V_63 , V_90 + V_2 , V_2 ) != V_2 )
return F_58 ( V_63 , V_151 ) ;
if ( V_63 -> V_104 ( V_63 , V_90 + V_2 , V_2 , V_2 , V_50 ) )
return F_58 ( V_63 , V_151 ) ;
if ( V_63 -> V_106 ( V_63 , V_90 + V_2 + 42 ) != ( V_2 + 42 ) )
return F_58 ( V_63 , V_151 ) ;
V_19 = 0 ;
V_152 = F_59 ( & V_5 -> V_40 , V_154 ) ;
while ( V_152 != V_154 ) {
V_2 = 1UL << V_152 ;
if ( V_63 -> V_105 ( V_63 , V_19 , V_2 ) != V_2 )
return F_58 ( V_63 , V_151 ) ;
if ( V_63 -> V_106 ( V_63 , V_19 + 42 ) )
return F_58 ( V_63 , V_151 ) ;
if ( V_63 -> V_104 ( V_63 , V_19 , V_19 , V_2 , V_49 ) )
return F_58 ( V_63 , V_151 ) ;
if ( V_63 -> V_106 ( V_63 , V_19 + 42 ) != ( V_19 + 42 ) )
return F_58 ( V_63 , V_151 ) ;
V_19 += V_90 ;
V_152 ++ ;
V_152 = F_60 ( & V_5 -> V_40 , V_154 , V_152 ) ;
}
F_61 ( V_63 ) ;
}
V_11 = false ;
return 0 ;
}
static int T_7 F_62 ( void )
{
static const unsigned long V_155 [] = {
V_88 | V_89 | V_90 ,
V_91 | V_92 ,
V_93 | V_94 ,
} ;
static const unsigned int V_97 [] = {
32 , 36 , 40 , 42 , 44 , 48 ,
} ;
int V_151 , V_152 , V_156 = 0 , V_157 = 0 ;
struct V_4 V_5 = {
. V_78 = & V_158 ,
. V_99 = 48 ,
} ;
for ( V_151 = 0 ; V_151 < F_56 ( V_155 ) ; ++ V_151 ) {
for ( V_152 = 0 ; V_152 < F_56 ( V_97 ) ; ++ V_152 ) {
V_5 . V_40 = V_155 [ V_151 ] ;
V_5 . V_97 = V_97 [ V_152 ] ;
F_63 ( L_6 ,
V_155 [ V_151 ] , V_97 [ V_152 ] ) ;
if ( F_55 ( & V_5 ) )
V_157 ++ ;
else
V_156 ++ ;
}
}
F_63 ( L_7 , V_156 , V_157 ) ;
return V_157 ? - V_159 : 0 ;
}
