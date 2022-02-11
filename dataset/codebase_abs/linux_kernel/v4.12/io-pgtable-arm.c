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
V_38 = F_3 ( F_22 ( V_18 ) ,
V_41 , V_5 ) ;
if ( ! V_38 )
return - V_42 ;
V_16 = F_23 ( V_38 ) | V_25 ;
if ( V_5 -> V_29 & V_30 )
V_16 |= V_43 ;
F_11 ( V_15 , V_16 , V_5 ) ;
} else if ( ! F_14 ( V_16 , V_22 ) ) {
V_38 = F_24 ( V_16 , V_18 ) ;
} else {
F_15 ( ! V_11 ) ;
return - V_24 ;
}
return F_21 ( V_18 , V_19 , V_20 , V_2 , V_21 , V_22 + 1 , V_38 ) ;
}
static T_4 F_25 ( struct V_17 * V_18 ,
int V_21 )
{
T_4 V_16 ;
if ( V_18 -> V_23 . V_44 == V_45 ||
V_18 -> V_23 . V_44 == V_46 ) {
V_16 = V_47 ;
if ( ! ( V_21 & V_48 ) && ( V_21 & V_49 ) )
V_16 |= V_50 ;
if ( ! ( V_21 & V_51 ) )
V_16 |= V_52 ;
if ( V_21 & V_53 )
V_16 |= ( V_54
<< V_55 ) ;
else if ( V_21 & V_56 )
V_16 |= ( V_57
<< V_55 ) ;
} else {
V_16 = V_58 ;
if ( V_21 & V_49 )
V_16 |= V_59 ;
if ( V_21 & V_48 )
V_16 |= V_60 ;
if ( V_21 & V_53 )
V_16 |= V_61 ;
else if ( V_21 & V_56 )
V_16 |= V_62 ;
else
V_16 |= V_63 ;
}
if ( V_21 & V_64 )
V_16 |= V_65 ;
return V_16 ;
}
static int F_26 ( struct V_66 * V_67 , unsigned long V_19 ,
T_5 V_20 , T_2 V_2 , int V_68 )
{
struct V_17 * V_18 = F_27 ( V_67 ) ;
T_4 * V_15 = V_18 -> V_69 ;
int V_70 , V_22 = F_28 ( V_18 ) ;
T_4 V_21 ;
if ( ! ( V_68 & ( V_49 | V_48 ) ) )
return 0 ;
V_21 = F_25 ( V_18 , V_68 ) ;
V_70 = F_21 ( V_18 , V_19 , V_20 , V_2 , V_21 , V_22 , V_15 ) ;
F_29 () ;
return V_70 ;
}
static void F_30 ( struct V_17 * V_18 , int V_22 ,
T_4 * V_15 )
{
T_4 * V_71 , * V_72 ;
unsigned long V_73 ;
if ( V_22 == F_28 ( V_18 ) )
V_73 = V_18 -> V_74 ;
else
V_73 = F_22 ( V_18 ) ;
V_71 = V_15 ;
if ( V_22 == V_32 - 1 )
V_72 = V_15 ;
else
V_72 = ( void * ) V_15 + V_73 ;
while ( V_15 != V_72 ) {
T_4 V_16 = * V_15 ++ ;
if ( ! V_16 || F_14 ( V_16 , V_22 ) )
continue;
F_30 ( V_18 , V_22 + 1 , F_24 ( V_16 , V_18 ) ) ;
}
F_10 ( V_71 , V_73 , & V_18 -> V_23 . V_5 ) ;
}
static void F_31 ( struct V_75 * V_23 )
{
struct V_17 * V_18 = F_32 ( V_23 ) ;
F_30 ( V_18 , F_28 ( V_18 ) , V_18 -> V_69 ) ;
F_33 ( V_18 ) ;
}
static int F_34 ( struct V_17 * V_18 ,
unsigned long V_19 , T_2 V_2 ,
T_4 V_21 , int V_22 ,
T_4 * V_15 , T_2 V_76 )
{
unsigned long V_77 , V_78 ;
T_5 V_79 ;
T_4 V_80 = 0 ;
V_77 = V_19 & ~ ( V_76 - 1 ) ;
V_78 = V_77 + V_76 ;
V_79 = F_35 ( * V_15 , V_18 ) << V_18 -> V_37 ;
for (; V_77 < V_78 ; V_77 += V_2 , V_79 += V_2 ) {
T_4 * V_81 ;
if ( V_77 == V_19 )
continue;
V_81 = & V_80 - F_18 ( V_77 , V_22 , V_18 ) ;
if ( F_21 ( V_18 , V_77 , V_79 , V_2 , V_21 , V_22 ,
V_81 ) < 0 ) {
if ( V_80 ) {
V_81 = F_24 ( V_80 , V_18 ) ;
F_30 ( V_18 , V_22 + 1 , V_81 ) ;
}
return 0 ;
}
}
F_11 ( V_15 , V_80 , & V_18 -> V_23 . V_5 ) ;
V_19 &= ~ ( V_76 - 1 ) ;
F_36 ( & V_18 -> V_23 , V_19 , V_76 , V_76 , true ) ;
return V_2 ;
}
static int F_19 ( struct V_17 * V_18 ,
unsigned long V_19 , T_2 V_2 , int V_22 ,
T_4 * V_15 )
{
T_4 V_16 ;
struct V_75 * V_23 = & V_18 -> V_23 ;
T_2 V_76 = F_17 ( V_22 , V_18 ) ;
if ( F_15 ( V_22 == V_32 ) )
return 0 ;
V_15 += F_18 ( V_19 , V_22 , V_18 ) ;
V_16 = * V_15 ;
if ( F_15 ( ! V_16 ) )
return 0 ;
if ( V_2 == V_76 ) {
F_11 ( V_15 , 0 , & V_23 -> V_5 ) ;
if ( ! F_14 ( V_16 , V_22 ) ) {
F_36 ( V_23 , V_19 , V_2 ,
F_22 ( V_18 ) , false ) ;
F_37 ( V_23 ) ;
V_15 = F_24 ( V_16 , V_18 ) ;
F_30 ( V_18 , V_22 + 1 , V_15 ) ;
} else {
F_36 ( V_23 , V_19 , V_2 , V_2 , true ) ;
}
return V_2 ;
} else if ( F_14 ( V_16 , V_22 ) ) {
return F_34 ( V_18 , V_19 , V_2 ,
F_38 ( V_16 ) , V_22 , V_15 ,
V_76 ) ;
}
V_15 = F_24 ( V_16 , V_18 ) ;
return F_19 ( V_18 , V_19 , V_2 , V_22 + 1 , V_15 ) ;
}
static int F_39 ( struct V_66 * V_67 , unsigned long V_19 ,
T_2 V_2 )
{
T_2 V_82 ;
struct V_17 * V_18 = F_27 ( V_67 ) ;
T_4 * V_15 = V_18 -> V_69 ;
int V_22 = F_28 ( V_18 ) ;
V_82 = F_19 ( V_18 , V_19 , V_2 , V_22 , V_15 ) ;
if ( V_82 )
F_37 ( & V_18 -> V_23 ) ;
return V_82 ;
}
static T_5 F_40 ( struct V_66 * V_67 ,
unsigned long V_19 )
{
struct V_17 * V_18 = F_27 ( V_67 ) ;
T_4 V_16 , * V_15 = V_18 -> V_69 ;
int V_22 = F_28 ( V_18 ) ;
do {
if ( ! V_15 )
return 0 ;
V_16 = * ( V_15 + F_18 ( V_19 , V_22 , V_18 ) ) ;
if ( ! V_16 )
return 0 ;
if ( F_14 ( V_16 , V_22 ) )
goto V_83;
V_15 = F_24 ( V_16 , V_18 ) ;
} while ( ++ V_22 < V_32 );
return 0 ;
V_83:
V_19 &= ( F_17 ( V_22 , V_18 ) - 1 ) ;
return ( ( T_5 ) F_35 ( V_16 , V_18 ) << V_18 -> V_37 ) | V_19 ;
}
static void F_41 ( struct V_4 * V_5 )
{
unsigned long V_84 ;
if ( V_5 -> V_40 & V_85 )
V_84 = V_85 ;
else if ( V_5 -> V_40 & ~ V_86 )
V_84 = 1UL << F_42 ( V_5 -> V_40 & ~ V_86 ) ;
else if ( V_5 -> V_40 & V_86 )
V_84 = 1UL << F_43 ( V_5 -> V_40 & V_86 ) ;
else
V_84 = 0 ;
switch ( V_84 ) {
case V_87 :
V_5 -> V_40 &= ( V_87 | V_88 | V_89 ) ;
break;
case V_90 :
V_5 -> V_40 &= ( V_90 | V_91 ) ;
break;
case V_92 :
V_5 -> V_40 &= ( V_92 | V_93 ) ;
break;
default:
V_5 -> V_40 = 0 ;
}
}
static struct V_17 *
F_44 ( struct V_4 * V_5 )
{
unsigned long V_94 , V_95 ;
struct V_17 * V_18 ;
F_41 ( V_5 ) ;
if ( ! ( V_5 -> V_40 & ( V_87 | V_90 | V_92 ) ) )
return NULL ;
if ( V_5 -> V_96 > V_97 )
return NULL ;
if ( V_5 -> V_98 > V_97 )
return NULL ;
if ( ! V_11 && V_5 -> V_8 -> V_99 ) {
F_7 ( V_5 -> V_8 , L_2 ) ;
return NULL ;
}
V_18 = F_45 ( sizeof( * V_18 ) , V_100 ) ;
if ( ! V_18 )
return NULL ;
V_18 -> V_37 = F_43 ( V_5 -> V_40 ) ;
V_18 -> V_101 = V_18 -> V_37 - F_46 ( sizeof( T_4 ) ) ;
V_94 = V_5 -> V_96 - V_18 -> V_37 ;
V_18 -> V_102 = F_47 ( V_94 , V_18 -> V_101 ) ;
V_95 = V_94 - ( V_18 -> V_101 * ( V_18 -> V_102 - 1 ) ) ;
V_18 -> V_74 = 1UL << ( V_95 + F_46 ( sizeof( T_4 ) ) ) ;
V_18 -> V_23 . V_67 = (struct V_66 ) {
. V_103 = F_26 ,
. V_104 = F_39 ,
. V_105 = F_40 ,
} ;
return V_18 ;
}
static struct V_75 *
F_48 ( struct V_4 * V_5 , void * V_106 )
{
T_6 V_107 ;
struct V_17 * V_18 ;
if ( V_5 -> V_29 & ~ V_30 )
return NULL ;
V_18 = F_44 ( V_5 ) ;
if ( ! V_18 )
return NULL ;
V_107 = ( V_108 << V_109 ) |
( V_110 << V_111 ) |
( V_110 << V_112 ) ;
switch ( F_22 ( V_18 ) ) {
case V_87 :
V_107 |= V_113 ;
break;
case V_90 :
V_107 |= V_114 ;
break;
case V_92 :
V_107 |= V_115 ;
break;
}
switch ( V_5 -> V_98 ) {
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
V_107 |= ( 64ULL - V_5 -> V_96 ) << V_124 ;
V_107 |= V_125 ;
V_5 -> V_126 . V_127 = V_107 ;
V_107 = ( V_128
<< F_49 ( V_129 ) ) |
( V_130
<< F_49 ( V_57 ) ) |
( V_131
<< F_49 ( V_54 ) ) ;
V_5 -> V_126 . V_132 [ 0 ] = V_107 ;
V_5 -> V_126 . V_132 [ 1 ] = 0 ;
V_18 -> V_69 = F_3 ( V_18 -> V_74 , V_100 , V_5 ) ;
if ( ! V_18 -> V_69 )
goto V_123;
F_29 () ;
V_5 -> V_126 . V_133 [ 0 ] = F_2 ( V_18 -> V_69 ) ;
V_5 -> V_126 . V_133 [ 1 ] = 0 ;
return & V_18 -> V_23 ;
V_123:
F_33 ( V_18 ) ;
return NULL ;
}
static struct V_75 *
F_50 ( struct V_4 * V_5 , void * V_106 )
{
T_6 V_107 , V_134 ;
struct V_17 * V_18 ;
if ( V_5 -> V_29 )
return NULL ;
V_18 = F_44 ( V_5 ) ;
if ( ! V_18 )
return NULL ;
if ( V_18 -> V_102 == V_32 ) {
unsigned long V_135 ;
V_135 = V_18 -> V_74 >> F_46 ( sizeof( T_4 ) ) ;
if ( V_135 <= V_136 ) {
V_18 -> V_74 = V_135 << V_18 -> V_37 ;
V_18 -> V_102 -- ;
}
}
V_107 = V_137 |
( V_108 << V_109 ) |
( V_110 << V_111 ) |
( V_110 << V_112 ) ;
V_134 = F_28 ( V_18 ) ;
switch ( F_22 ( V_18 ) ) {
case V_87 :
V_107 |= V_113 ;
V_134 ++ ;
break;
case V_90 :
V_107 |= V_114 ;
break;
case V_92 :
V_107 |= V_115 ;
break;
}
switch ( V_5 -> V_98 ) {
case 32 :
V_107 |= ( V_116 << V_138 ) ;
break;
case 36 :
V_107 |= ( V_118 << V_138 ) ;
break;
case 40 :
V_107 |= ( V_119 << V_138 ) ;
break;
case 42 :
V_107 |= ( V_120 << V_138 ) ;
break;
case 44 :
V_107 |= ( V_121 << V_138 ) ;
break;
case 48 :
V_107 |= ( V_122 << V_138 ) ;
break;
default:
goto V_123;
}
V_107 |= ( 64ULL - V_5 -> V_96 ) << V_124 ;
V_107 |= ( ~ V_134 & V_139 ) << V_140 ;
V_5 -> V_141 . V_142 = V_107 ;
V_18 -> V_69 = F_3 ( V_18 -> V_74 , V_100 , V_5 ) ;
if ( ! V_18 -> V_69 )
goto V_123;
F_29 () ;
V_5 -> V_141 . V_143 = F_2 ( V_18 -> V_69 ) ;
return & V_18 -> V_23 ;
V_123:
F_33 ( V_18 ) ;
return NULL ;
}
static struct V_75 *
F_51 ( struct V_4 * V_5 , void * V_106 )
{
struct V_75 * V_23 ;
if ( V_5 -> V_96 > 32 || V_5 -> V_98 > 40 )
return NULL ;
V_5 -> V_40 &= ( V_87 | V_88 | V_89 ) ;
V_23 = F_48 ( V_5 , V_106 ) ;
if ( V_23 ) {
V_5 -> V_126 . V_127 |= V_144 ;
V_5 -> V_126 . V_127 &= 0xffffffff ;
}
return V_23 ;
}
static struct V_75 *
F_52 ( struct V_4 * V_5 , void * V_106 )
{
struct V_75 * V_23 ;
if ( V_5 -> V_96 > 40 || V_5 -> V_98 > 40 )
return NULL ;
V_5 -> V_40 &= ( V_87 | V_88 | V_89 ) ;
V_23 = F_50 ( V_5 , V_106 ) ;
if ( V_23 )
V_5 -> V_141 . V_142 &= 0xffffffff ;
return V_23 ;
}
static void F_53 ( void * V_106 )
{
F_15 ( V_106 != V_145 ) ;
}
static void F_54 ( unsigned long V_19 , T_2 V_2 ,
T_2 V_84 , bool V_146 , void * V_106 )
{
F_15 ( V_106 != V_145 ) ;
F_15 ( ! ( V_2 & V_145 -> V_40 ) ) ;
}
static void F_55 ( void * V_106 )
{
F_15 ( V_106 != V_145 ) ;
}
static void T_7 F_56 ( struct V_66 * V_67 )
{
struct V_17 * V_18 = F_27 ( V_67 ) ;
struct V_4 * V_5 = & V_18 -> V_23 . V_5 ;
F_57 ( L_3 ,
V_5 -> V_40 , V_5 -> V_96 ) ;
F_57 ( L_4 ,
V_18 -> V_102 , V_18 -> V_74 , V_18 -> V_37 ,
V_18 -> V_101 , V_18 -> V_69 ) ;
}
static int T_7 F_58 ( struct V_4 * V_5 )
{
static const enum V_147 V_148 [] = {
V_45 ,
V_149 ,
} ;
int V_150 , V_151 ;
unsigned long V_19 ;
T_2 V_2 ;
struct V_66 * V_67 ;
V_11 = true ;
for ( V_150 = 0 ; V_150 < F_59 ( V_148 ) ; ++ V_150 ) {
V_145 = V_5 ;
V_67 = F_60 ( V_148 [ V_150 ] , V_5 , V_5 ) ;
if ( ! V_67 ) {
F_57 ( L_5 ) ;
return - V_42 ;
}
if ( V_67 -> V_105 ( V_67 , 42 ) )
return F_61 ( V_67 , V_150 ) ;
if ( V_67 -> V_105 ( V_67 , V_89 + 42 ) )
return F_61 ( V_67 , V_150 ) ;
if ( V_67 -> V_105 ( V_67 , V_152 + 42 ) )
return F_61 ( V_67 , V_150 ) ;
V_19 = 0 ;
F_62 (j, &cfg->pgsize_bitmap, BITS_PER_LONG) {
V_2 = 1UL << V_151 ;
if ( V_67 -> V_103 ( V_67 , V_19 , V_19 , V_2 , V_49 |
V_48 |
V_64 |
V_56 ) )
return F_61 ( V_67 , V_150 ) ;
if ( ! V_67 -> V_103 ( V_67 , V_19 , V_19 + V_2 , V_2 ,
V_49 | V_64 ) )
return F_61 ( V_67 , V_150 ) ;
if ( V_67 -> V_105 ( V_67 , V_19 + 42 ) != ( V_19 + 42 ) )
return F_61 ( V_67 , V_150 ) ;
V_19 += V_89 ;
}
V_2 = 1UL << F_43 ( V_5 -> V_40 ) ;
if ( V_67 -> V_104 ( V_67 , V_89 + V_2 , V_2 ) != V_2 )
return F_61 ( V_67 , V_150 ) ;
if ( V_67 -> V_103 ( V_67 , V_89 + V_2 , V_2 , V_2 , V_49 ) )
return F_61 ( V_67 , V_150 ) ;
if ( V_67 -> V_105 ( V_67 , V_89 + V_2 + 42 ) != ( V_2 + 42 ) )
return F_61 ( V_67 , V_150 ) ;
V_19 = 0 ;
V_151 = F_63 ( & V_5 -> V_40 , V_153 ) ;
while ( V_151 != V_153 ) {
V_2 = 1UL << V_151 ;
if ( V_67 -> V_104 ( V_67 , V_19 , V_2 ) != V_2 )
return F_61 ( V_67 , V_150 ) ;
if ( V_67 -> V_105 ( V_67 , V_19 + 42 ) )
return F_61 ( V_67 , V_150 ) ;
if ( V_67 -> V_103 ( V_67 , V_19 , V_19 , V_2 , V_48 ) )
return F_61 ( V_67 , V_150 ) ;
if ( V_67 -> V_105 ( V_67 , V_19 + 42 ) != ( V_19 + 42 ) )
return F_61 ( V_67 , V_150 ) ;
V_19 += V_89 ;
V_151 ++ ;
V_151 = F_64 ( & V_5 -> V_40 , V_153 , V_151 ) ;
}
F_65 ( V_67 ) ;
}
V_11 = false ;
return 0 ;
}
static int T_7 F_66 ( void )
{
static const unsigned long V_154 [] = {
V_87 | V_88 | V_89 ,
V_90 | V_91 ,
V_92 | V_93 ,
} ;
static const unsigned int V_96 [] = {
32 , 36 , 40 , 42 , 44 , 48 ,
} ;
int V_150 , V_151 , V_155 = 0 , V_156 = 0 ;
struct V_4 V_5 = {
. V_157 = & V_158 ,
. V_98 = 48 ,
} ;
for ( V_150 = 0 ; V_150 < F_59 ( V_154 ) ; ++ V_150 ) {
for ( V_151 = 0 ; V_151 < F_59 ( V_96 ) ; ++ V_151 ) {
V_5 . V_40 = V_154 [ V_150 ] ;
V_5 . V_96 = V_96 [ V_151 ] ;
F_67 ( L_6 ,
V_154 [ V_150 ] , V_96 [ V_151 ] ) ;
if ( F_58 ( & V_5 ) )
V_156 ++ ;
else
V_155 ++ ;
}
}
F_67 ( L_7 , V_155 , V_156 ) ;
return V_156 ? - V_159 : 0 ;
}
