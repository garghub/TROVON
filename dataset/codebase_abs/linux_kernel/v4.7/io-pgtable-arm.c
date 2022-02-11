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
} else {
V_38 = F_24 ( V_16 , V_18 ) ;
}
return F_21 ( V_18 , V_19 , V_20 , V_2 , V_21 , V_22 + 1 , V_38 ) ;
}
static T_4 F_25 ( struct V_17 * V_18 ,
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
else if ( V_21 & V_55 )
V_16 |= ( V_56
<< V_54 ) ;
} else {
V_16 = V_57 ;
if ( V_21 & V_50 )
V_16 |= V_58 ;
if ( V_21 & V_49 )
V_16 |= V_59 ;
if ( V_21 & V_52 )
V_16 |= V_60 ;
else if ( V_21 & V_55 )
V_16 |= V_61 ;
else
V_16 |= V_62 ;
}
if ( V_21 & V_63 )
V_16 |= V_64 ;
return V_16 ;
}
static int F_26 ( struct V_65 * V_66 , unsigned long V_19 ,
T_5 V_20 , T_2 V_2 , int V_67 )
{
struct V_17 * V_18 = F_27 ( V_66 ) ;
T_4 * V_15 = V_18 -> V_68 ;
int V_69 , V_22 = F_28 ( V_18 ) ;
T_4 V_21 ;
if ( ! ( V_67 & ( V_50 | V_49 ) ) )
return 0 ;
V_21 = F_25 ( V_18 , V_67 ) ;
V_69 = F_21 ( V_18 , V_19 , V_20 , V_2 , V_21 , V_22 , V_15 ) ;
F_29 () ;
return V_69 ;
}
static void F_30 ( struct V_17 * V_18 , int V_22 ,
T_4 * V_15 )
{
T_4 * V_70 , * V_71 ;
unsigned long V_72 ;
if ( V_22 == F_28 ( V_18 ) )
V_72 = V_18 -> V_73 ;
else
V_72 = F_22 ( V_18 ) ;
V_70 = V_15 ;
if ( V_22 == V_32 - 1 )
V_71 = V_15 ;
else
V_71 = ( void * ) V_15 + V_72 ;
while ( V_15 != V_71 ) {
T_4 V_16 = * V_15 ++ ;
if ( ! V_16 || F_14 ( V_16 , V_22 ) )
continue;
F_30 ( V_18 , V_22 + 1 , F_24 ( V_16 , V_18 ) ) ;
}
F_10 ( V_70 , V_72 , & V_18 -> V_23 . V_5 ) ;
}
static void F_31 ( struct V_74 * V_23 )
{
struct V_17 * V_18 = F_32 ( V_23 ) ;
F_30 ( V_18 , F_28 ( V_18 ) , V_18 -> V_68 ) ;
F_33 ( V_18 ) ;
}
static int F_34 ( struct V_17 * V_18 ,
unsigned long V_19 , T_2 V_2 ,
T_4 V_21 , int V_22 ,
T_4 * V_15 , T_2 V_75 )
{
unsigned long V_76 , V_77 ;
T_5 V_78 ;
T_4 V_79 = 0 ;
V_76 = V_19 & ~ ( V_75 - 1 ) ;
V_77 = V_76 + V_75 ;
V_78 = F_35 ( * V_15 , V_18 ) << V_18 -> V_37 ;
for (; V_76 < V_77 ; V_76 += V_2 , V_78 += V_2 ) {
T_4 * V_80 ;
if ( V_76 == V_19 )
continue;
V_80 = & V_79 - F_18 ( V_76 , V_22 , V_18 ) ;
if ( F_21 ( V_18 , V_76 , V_78 , V_2 , V_21 , V_22 ,
V_80 ) < 0 ) {
if ( V_79 ) {
V_80 = F_24 ( V_79 , V_18 ) ;
F_30 ( V_18 , V_22 + 1 , V_80 ) ;
}
return 0 ;
}
}
F_11 ( V_15 , V_79 , & V_18 -> V_23 . V_5 ) ;
V_19 &= ~ ( V_75 - 1 ) ;
F_36 ( & V_18 -> V_23 , V_19 , V_75 , V_75 , true ) ;
return V_2 ;
}
static int F_19 ( struct V_17 * V_18 ,
unsigned long V_19 , T_2 V_2 , int V_22 ,
T_4 * V_15 )
{
T_4 V_16 ;
struct V_74 * V_23 = & V_18 -> V_23 ;
T_2 V_75 = F_17 ( V_22 , V_18 ) ;
if ( F_15 ( V_22 == V_32 ) )
return 0 ;
V_15 += F_18 ( V_19 , V_22 , V_18 ) ;
V_16 = * V_15 ;
if ( F_15 ( ! V_16 ) )
return 0 ;
if ( V_2 == V_75 ) {
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
V_75 ) ;
}
V_15 = F_24 ( V_16 , V_18 ) ;
return F_19 ( V_18 , V_19 , V_2 , V_22 + 1 , V_15 ) ;
}
static int F_39 ( struct V_65 * V_66 , unsigned long V_19 ,
T_2 V_2 )
{
T_2 V_81 ;
struct V_17 * V_18 = F_27 ( V_66 ) ;
T_4 * V_15 = V_18 -> V_68 ;
int V_22 = F_28 ( V_18 ) ;
V_81 = F_19 ( V_18 , V_19 , V_2 , V_22 , V_15 ) ;
if ( V_81 )
F_37 ( & V_18 -> V_23 ) ;
return V_81 ;
}
static T_5 F_40 ( struct V_65 * V_66 ,
unsigned long V_19 )
{
struct V_17 * V_18 = F_27 ( V_66 ) ;
T_4 V_16 , * V_15 = V_18 -> V_68 ;
int V_22 = F_28 ( V_18 ) ;
do {
if ( ! V_15 )
return 0 ;
V_16 = * ( V_15 + F_18 ( V_19 , V_22 , V_18 ) ) ;
if ( ! V_16 )
return 0 ;
if ( F_14 ( V_16 , V_22 ) )
goto V_82;
V_15 = F_24 ( V_16 , V_18 ) ;
} while ( ++ V_22 < V_32 );
return 0 ;
V_82:
V_19 &= ( F_22 ( V_18 ) - 1 ) ;
return ( ( T_5 ) F_35 ( V_16 , V_18 ) << V_18 -> V_37 ) | V_19 ;
}
static void F_41 ( struct V_4 * V_5 )
{
unsigned long V_83 ;
if ( V_5 -> V_40 & V_84 )
V_83 = V_84 ;
else if ( V_5 -> V_40 & ~ V_85 )
V_83 = 1UL << F_42 ( V_5 -> V_40 & ~ V_85 ) ;
else if ( V_5 -> V_40 & V_85 )
V_83 = 1UL << F_43 ( V_5 -> V_40 & V_85 ) ;
else
V_83 = 0 ;
switch ( V_83 ) {
case V_86 :
V_5 -> V_40 &= ( V_86 | V_87 | V_88 ) ;
break;
case V_89 :
V_5 -> V_40 &= ( V_89 | V_90 ) ;
break;
case V_91 :
V_5 -> V_40 &= ( V_91 | V_92 ) ;
break;
default:
V_5 -> V_40 = 0 ;
}
}
static struct V_17 *
F_44 ( struct V_4 * V_5 )
{
unsigned long V_93 , V_94 ;
struct V_17 * V_18 ;
F_41 ( V_5 ) ;
if ( ! ( V_5 -> V_40 & ( V_86 | V_89 | V_91 ) ) )
return NULL ;
if ( V_5 -> V_95 > V_96 )
return NULL ;
if ( V_5 -> V_97 > V_96 )
return NULL ;
if ( ! V_11 && V_5 -> V_8 -> V_98 ) {
F_7 ( V_5 -> V_8 , L_2 ) ;
return NULL ;
}
V_18 = F_45 ( sizeof( * V_18 ) , V_99 ) ;
if ( ! V_18 )
return NULL ;
V_18 -> V_37 = F_43 ( V_5 -> V_40 ) ;
V_18 -> V_100 = V_18 -> V_37 - F_46 ( sizeof( T_4 ) ) ;
V_93 = V_5 -> V_95 - V_18 -> V_37 ;
V_18 -> V_101 = F_47 ( V_93 , V_18 -> V_100 ) ;
V_94 = V_93 - ( V_18 -> V_100 * ( V_18 -> V_101 - 1 ) ) ;
V_18 -> V_73 = 1UL << ( V_94 + F_46 ( sizeof( T_4 ) ) ) ;
V_18 -> V_23 . V_66 = (struct V_65 ) {
. V_102 = F_26 ,
. V_103 = F_39 ,
. V_104 = F_40 ,
} ;
return V_18 ;
}
static struct V_74 *
F_48 ( struct V_4 * V_5 , void * V_105 )
{
T_6 V_106 ;
struct V_17 * V_18 ;
if ( V_5 -> V_29 & ~ V_30 )
return NULL ;
V_18 = F_44 ( V_5 ) ;
if ( ! V_18 )
return NULL ;
V_106 = ( V_107 << V_108 ) |
( V_109 << V_110 ) |
( V_109 << V_111 ) ;
switch ( F_22 ( V_18 ) ) {
case V_86 :
V_106 |= V_112 ;
break;
case V_89 :
V_106 |= V_113 ;
break;
case V_91 :
V_106 |= V_114 ;
break;
}
switch ( V_5 -> V_97 ) {
case 32 :
V_106 |= ( V_115 << V_116 ) ;
break;
case 36 :
V_106 |= ( V_117 << V_116 ) ;
break;
case 40 :
V_106 |= ( V_118 << V_116 ) ;
break;
case 42 :
V_106 |= ( V_119 << V_116 ) ;
break;
case 44 :
V_106 |= ( V_120 << V_116 ) ;
break;
case 48 :
V_106 |= ( V_121 << V_116 ) ;
break;
default:
goto V_122;
}
V_106 |= ( 64ULL - V_5 -> V_95 ) << V_123 ;
V_106 |= V_124 ;
V_5 -> V_125 . V_126 = V_106 ;
V_106 = ( V_127
<< F_49 ( V_128 ) ) |
( V_129
<< F_49 ( V_56 ) ) |
( V_130
<< F_49 ( V_53 ) ) ;
V_5 -> V_125 . V_131 [ 0 ] = V_106 ;
V_5 -> V_125 . V_131 [ 1 ] = 0 ;
V_18 -> V_68 = F_3 ( V_18 -> V_73 , V_99 , V_5 ) ;
if ( ! V_18 -> V_68 )
goto V_122;
F_29 () ;
V_5 -> V_125 . V_132 [ 0 ] = F_2 ( V_18 -> V_68 ) ;
V_5 -> V_125 . V_132 [ 1 ] = 0 ;
return & V_18 -> V_23 ;
V_122:
F_33 ( V_18 ) ;
return NULL ;
}
static struct V_74 *
F_50 ( struct V_4 * V_5 , void * V_105 )
{
T_6 V_106 , V_133 ;
struct V_17 * V_18 ;
if ( V_5 -> V_29 )
return NULL ;
V_18 = F_44 ( V_5 ) ;
if ( ! V_18 )
return NULL ;
if ( V_18 -> V_101 == V_32 ) {
unsigned long V_134 ;
V_134 = V_18 -> V_73 >> F_46 ( sizeof( T_4 ) ) ;
if ( V_134 <= V_135 ) {
V_18 -> V_73 = V_134 << V_18 -> V_37 ;
V_18 -> V_101 -- ;
}
}
V_106 = V_136 |
( V_107 << V_108 ) |
( V_109 << V_110 ) |
( V_109 << V_111 ) ;
V_133 = F_28 ( V_18 ) ;
switch ( F_22 ( V_18 ) ) {
case V_86 :
V_106 |= V_112 ;
V_133 ++ ;
break;
case V_89 :
V_106 |= V_113 ;
break;
case V_91 :
V_106 |= V_114 ;
break;
}
switch ( V_5 -> V_97 ) {
case 32 :
V_106 |= ( V_115 << V_137 ) ;
break;
case 36 :
V_106 |= ( V_117 << V_137 ) ;
break;
case 40 :
V_106 |= ( V_118 << V_137 ) ;
break;
case 42 :
V_106 |= ( V_119 << V_137 ) ;
break;
case 44 :
V_106 |= ( V_120 << V_137 ) ;
break;
case 48 :
V_106 |= ( V_121 << V_137 ) ;
break;
default:
goto V_122;
}
V_106 |= ( 64ULL - V_5 -> V_95 ) << V_123 ;
V_106 |= ( ~ V_133 & V_138 ) << V_139 ;
V_5 -> V_140 . V_141 = V_106 ;
V_18 -> V_68 = F_3 ( V_18 -> V_73 , V_99 , V_5 ) ;
if ( ! V_18 -> V_68 )
goto V_122;
F_29 () ;
V_5 -> V_140 . V_142 = F_2 ( V_18 -> V_68 ) ;
return & V_18 -> V_23 ;
V_122:
F_33 ( V_18 ) ;
return NULL ;
}
static struct V_74 *
F_51 ( struct V_4 * V_5 , void * V_105 )
{
struct V_74 * V_23 ;
if ( V_5 -> V_95 > 32 || V_5 -> V_97 > 40 )
return NULL ;
V_5 -> V_40 &= ( V_86 | V_87 | V_88 ) ;
V_23 = F_48 ( V_5 , V_105 ) ;
if ( V_23 ) {
V_5 -> V_125 . V_126 |= V_143 ;
V_5 -> V_125 . V_126 &= 0xffffffff ;
}
return V_23 ;
}
static struct V_74 *
F_52 ( struct V_4 * V_5 , void * V_105 )
{
struct V_74 * V_23 ;
if ( V_5 -> V_95 > 40 || V_5 -> V_97 > 40 )
return NULL ;
V_5 -> V_40 &= ( V_86 | V_87 | V_88 ) ;
V_23 = F_50 ( V_5 , V_105 ) ;
if ( V_23 )
V_5 -> V_140 . V_141 &= 0xffffffff ;
return V_23 ;
}
static void F_53 ( void * V_105 )
{
F_15 ( V_105 != V_144 ) ;
}
static void F_54 ( unsigned long V_19 , T_2 V_2 ,
T_2 V_83 , bool V_145 , void * V_105 )
{
F_15 ( V_105 != V_144 ) ;
F_15 ( ! ( V_2 & V_144 -> V_40 ) ) ;
}
static void F_55 ( void * V_105 )
{
F_15 ( V_105 != V_144 ) ;
}
static void T_7 F_56 ( struct V_65 * V_66 )
{
struct V_17 * V_18 = F_27 ( V_66 ) ;
struct V_4 * V_5 = & V_18 -> V_23 . V_5 ;
F_57 ( L_3 ,
V_5 -> V_40 , V_5 -> V_95 ) ;
F_57 ( L_4 ,
V_18 -> V_101 , V_18 -> V_73 , V_18 -> V_37 ,
V_18 -> V_100 , V_18 -> V_68 ) ;
}
static int T_7 F_58 ( struct V_4 * V_5 )
{
static const enum V_146 V_147 [] = {
V_45 ,
V_148 ,
} ;
int V_149 , V_150 ;
unsigned long V_19 ;
T_2 V_2 ;
struct V_65 * V_66 ;
V_11 = true ;
for ( V_149 = 0 ; V_149 < F_59 ( V_147 ) ; ++ V_149 ) {
V_144 = V_5 ;
V_66 = F_60 ( V_147 [ V_149 ] , V_5 , V_5 ) ;
if ( ! V_66 ) {
F_57 ( L_5 ) ;
return - V_42 ;
}
if ( V_66 -> V_104 ( V_66 , 42 ) )
return F_61 ( V_66 , V_149 ) ;
if ( V_66 -> V_104 ( V_66 , V_88 + 42 ) )
return F_61 ( V_66 , V_149 ) ;
if ( V_66 -> V_104 ( V_66 , V_151 + 42 ) )
return F_61 ( V_66 , V_149 ) ;
V_19 = 0 ;
V_150 = F_62 ( & V_5 -> V_40 , V_152 ) ;
while ( V_150 != V_152 ) {
V_2 = 1UL << V_150 ;
if ( V_66 -> V_102 ( V_66 , V_19 , V_19 , V_2 , V_50 |
V_49 |
V_63 |
V_55 ) )
return F_61 ( V_66 , V_149 ) ;
if ( ! V_66 -> V_102 ( V_66 , V_19 , V_19 + V_2 , V_2 ,
V_50 | V_63 ) )
return F_61 ( V_66 , V_149 ) ;
if ( V_66 -> V_104 ( V_66 , V_19 + 42 ) != ( V_19 + 42 ) )
return F_61 ( V_66 , V_149 ) ;
V_19 += V_88 ;
V_150 ++ ;
V_150 = F_63 ( & V_5 -> V_40 , V_152 , V_150 ) ;
}
V_2 = 1UL << F_43 ( V_5 -> V_40 ) ;
if ( V_66 -> V_103 ( V_66 , V_88 + V_2 , V_2 ) != V_2 )
return F_61 ( V_66 , V_149 ) ;
if ( V_66 -> V_102 ( V_66 , V_88 + V_2 , V_2 , V_2 , V_50 ) )
return F_61 ( V_66 , V_149 ) ;
if ( V_66 -> V_104 ( V_66 , V_88 + V_2 + 42 ) != ( V_2 + 42 ) )
return F_61 ( V_66 , V_149 ) ;
V_19 = 0 ;
V_150 = F_62 ( & V_5 -> V_40 , V_152 ) ;
while ( V_150 != V_152 ) {
V_2 = 1UL << V_150 ;
if ( V_66 -> V_103 ( V_66 , V_19 , V_2 ) != V_2 )
return F_61 ( V_66 , V_149 ) ;
if ( V_66 -> V_104 ( V_66 , V_19 + 42 ) )
return F_61 ( V_66 , V_149 ) ;
if ( V_66 -> V_102 ( V_66 , V_19 , V_19 , V_2 , V_49 ) )
return F_61 ( V_66 , V_149 ) ;
if ( V_66 -> V_104 ( V_66 , V_19 + 42 ) != ( V_19 + 42 ) )
return F_61 ( V_66 , V_149 ) ;
V_19 += V_88 ;
V_150 ++ ;
V_150 = F_63 ( & V_5 -> V_40 , V_152 , V_150 ) ;
}
F_64 ( V_66 ) ;
}
V_11 = false ;
return 0 ;
}
static int T_7 F_65 ( void )
{
static const unsigned long V_153 [] = {
V_86 | V_87 | V_88 ,
V_89 | V_90 ,
V_91 | V_92 ,
} ;
static const unsigned int V_95 [] = {
32 , 36 , 40 , 42 , 44 , 48 ,
} ;
int V_149 , V_150 , V_154 = 0 , V_155 = 0 ;
struct V_4 V_5 = {
. V_156 = & V_157 ,
. V_97 = 48 ,
} ;
for ( V_149 = 0 ; V_149 < F_59 ( V_153 ) ; ++ V_149 ) {
for ( V_150 = 0 ; V_150 < F_59 ( V_95 ) ; ++ V_150 ) {
V_5 . V_40 = V_153 [ V_149 ] ;
V_5 . V_95 = V_95 [ V_150 ] ;
F_66 ( L_6 ,
V_153 [ V_149 ] , V_95 [ V_150 ] ) ;
if ( F_58 ( & V_5 ) )
V_155 ++ ;
else
V_154 ++ ;
}
}
F_66 ( L_7 , V_154 , V_155 ) ;
return V_155 ? - V_158 : 0 ;
}
