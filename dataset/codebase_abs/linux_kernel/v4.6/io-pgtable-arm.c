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
static int F_26 ( struct V_62 * V_63 , unsigned long V_19 ,
T_5 V_20 , T_2 V_2 , int V_64 )
{
struct V_17 * V_18 = F_27 ( V_63 ) ;
T_4 * V_15 = V_18 -> V_65 ;
int V_66 , V_22 = F_28 ( V_18 ) ;
T_4 V_21 ;
if ( ! ( V_64 & ( V_50 | V_49 ) ) )
return 0 ;
V_21 = F_25 ( V_18 , V_64 ) ;
V_66 = F_21 ( V_18 , V_19 , V_20 , V_2 , V_21 , V_22 , V_15 ) ;
F_29 () ;
return V_66 ;
}
static void F_30 ( struct V_17 * V_18 , int V_22 ,
T_4 * V_15 )
{
T_4 * V_67 , * V_68 ;
unsigned long V_69 ;
if ( V_22 == F_28 ( V_18 ) )
V_69 = V_18 -> V_70 ;
else
V_69 = F_22 ( V_18 ) ;
V_67 = V_15 ;
if ( V_22 == V_32 - 1 )
V_68 = V_15 ;
else
V_68 = ( void * ) V_15 + V_69 ;
while ( V_15 != V_68 ) {
T_4 V_16 = * V_15 ++ ;
if ( ! V_16 || F_14 ( V_16 , V_22 ) )
continue;
F_30 ( V_18 , V_22 + 1 , F_24 ( V_16 , V_18 ) ) ;
}
F_10 ( V_67 , V_69 , & V_18 -> V_23 . V_5 ) ;
}
static void F_31 ( struct V_71 * V_23 )
{
struct V_17 * V_18 = F_32 ( V_23 ) ;
F_30 ( V_18 , F_28 ( V_18 ) , V_18 -> V_65 ) ;
F_33 ( V_18 ) ;
}
static int F_34 ( struct V_17 * V_18 ,
unsigned long V_19 , T_2 V_2 ,
T_4 V_21 , int V_22 ,
T_4 * V_15 , T_2 V_72 )
{
unsigned long V_73 , V_74 ;
T_5 V_75 ;
T_4 V_76 = 0 ;
V_73 = V_19 & ~ ( V_72 - 1 ) ;
V_74 = V_73 + V_72 ;
V_75 = F_35 ( * V_15 , V_18 ) << V_18 -> V_37 ;
for (; V_73 < V_74 ; V_73 += V_2 , V_75 += V_2 ) {
T_4 * V_77 ;
if ( V_73 == V_19 )
continue;
V_77 = & V_76 - F_18 ( V_73 , V_22 , V_18 ) ;
if ( F_21 ( V_18 , V_73 , V_75 , V_2 , V_21 , V_22 ,
V_77 ) < 0 ) {
if ( V_76 ) {
V_77 = F_24 ( V_76 , V_18 ) ;
F_30 ( V_18 , V_22 + 1 , V_77 ) ;
}
return 0 ;
}
}
F_11 ( V_15 , V_76 , & V_18 -> V_23 . V_5 ) ;
V_19 &= ~ ( V_72 - 1 ) ;
F_36 ( & V_18 -> V_23 , V_19 , V_72 , V_72 , true ) ;
return V_2 ;
}
static int F_19 ( struct V_17 * V_18 ,
unsigned long V_19 , T_2 V_2 , int V_22 ,
T_4 * V_15 )
{
T_4 V_16 ;
struct V_71 * V_23 = & V_18 -> V_23 ;
T_2 V_72 = F_17 ( V_22 , V_18 ) ;
if ( F_15 ( V_22 == V_32 ) )
return 0 ;
V_15 += F_18 ( V_19 , V_22 , V_18 ) ;
V_16 = * V_15 ;
if ( F_15 ( ! V_16 ) )
return 0 ;
if ( V_2 == V_72 ) {
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
V_72 ) ;
}
V_15 = F_24 ( V_16 , V_18 ) ;
return F_19 ( V_18 , V_19 , V_2 , V_22 + 1 , V_15 ) ;
}
static int F_39 ( struct V_62 * V_63 , unsigned long V_19 ,
T_2 V_2 )
{
T_2 V_78 ;
struct V_17 * V_18 = F_27 ( V_63 ) ;
T_4 * V_15 = V_18 -> V_65 ;
int V_22 = F_28 ( V_18 ) ;
V_78 = F_19 ( V_18 , V_19 , V_2 , V_22 , V_15 ) ;
if ( V_78 )
F_37 ( & V_18 -> V_23 ) ;
return V_78 ;
}
static T_5 F_40 ( struct V_62 * V_63 ,
unsigned long V_19 )
{
struct V_17 * V_18 = F_27 ( V_63 ) ;
T_4 V_16 , * V_15 = V_18 -> V_65 ;
int V_22 = F_28 ( V_18 ) ;
do {
if ( ! V_15 )
return 0 ;
V_16 = * ( V_15 + F_18 ( V_19 , V_22 , V_18 ) ) ;
if ( ! V_16 )
return 0 ;
if ( F_14 ( V_16 , V_22 ) )
goto V_79;
V_15 = F_24 ( V_16 , V_18 ) ;
} while ( ++ V_22 < V_32 );
return 0 ;
V_79:
V_19 &= ( F_22 ( V_18 ) - 1 ) ;
return ( ( T_5 ) F_35 ( V_16 , V_18 ) << V_18 -> V_37 ) | V_19 ;
}
static void F_41 ( struct V_4 * V_5 )
{
unsigned long V_80 ;
if ( V_5 -> V_40 & V_81 )
V_80 = V_81 ;
else if ( V_5 -> V_40 & ~ V_82 )
V_80 = 1UL << F_42 ( V_5 -> V_40 & ~ V_82 ) ;
else if ( V_5 -> V_40 & V_82 )
V_80 = 1UL << F_43 ( V_5 -> V_40 & V_82 ) ;
else
V_80 = 0 ;
switch ( V_80 ) {
case V_83 :
V_5 -> V_40 &= ( V_83 | V_84 | V_85 ) ;
break;
case V_86 :
V_5 -> V_40 &= ( V_86 | V_87 ) ;
break;
case V_88 :
V_5 -> V_40 &= ( V_88 | V_89 ) ;
break;
default:
V_5 -> V_40 = 0 ;
}
}
static struct V_17 *
F_44 ( struct V_4 * V_5 )
{
unsigned long V_90 , V_91 ;
struct V_17 * V_18 ;
F_41 ( V_5 ) ;
if ( ! ( V_5 -> V_40 & ( V_83 | V_86 | V_88 ) ) )
return NULL ;
if ( V_5 -> V_92 > V_93 )
return NULL ;
if ( V_5 -> V_94 > V_93 )
return NULL ;
if ( ! V_11 && V_5 -> V_8 -> V_95 ) {
F_7 ( V_5 -> V_8 , L_2 ) ;
return NULL ;
}
V_18 = F_45 ( sizeof( * V_18 ) , V_96 ) ;
if ( ! V_18 )
return NULL ;
V_18 -> V_37 = F_43 ( V_5 -> V_40 ) ;
V_18 -> V_97 = V_18 -> V_37 - F_46 ( sizeof( T_4 ) ) ;
V_90 = V_5 -> V_92 - V_18 -> V_37 ;
V_18 -> V_98 = F_47 ( V_90 , V_18 -> V_97 ) ;
V_91 = V_90 - ( V_18 -> V_97 * ( V_18 -> V_98 - 1 ) ) ;
V_18 -> V_70 = 1UL << ( V_91 + F_46 ( sizeof( T_4 ) ) ) ;
V_18 -> V_23 . V_63 = (struct V_62 ) {
. V_99 = F_26 ,
. V_100 = F_39 ,
. V_101 = F_40 ,
} ;
return V_18 ;
}
static struct V_71 *
F_48 ( struct V_4 * V_5 , void * V_102 )
{
T_6 V_103 ;
struct V_17 * V_18 ;
if ( V_5 -> V_29 & ~ V_30 )
return NULL ;
V_18 = F_44 ( V_5 ) ;
if ( ! V_18 )
return NULL ;
V_103 = ( V_104 << V_105 ) |
( V_106 << V_107 ) |
( V_106 << V_108 ) ;
switch ( F_22 ( V_18 ) ) {
case V_83 :
V_103 |= V_109 ;
break;
case V_86 :
V_103 |= V_110 ;
break;
case V_88 :
V_103 |= V_111 ;
break;
}
switch ( V_5 -> V_94 ) {
case 32 :
V_103 |= ( V_112 << V_113 ) ;
break;
case 36 :
V_103 |= ( V_114 << V_113 ) ;
break;
case 40 :
V_103 |= ( V_115 << V_113 ) ;
break;
case 42 :
V_103 |= ( V_116 << V_113 ) ;
break;
case 44 :
V_103 |= ( V_117 << V_113 ) ;
break;
case 48 :
V_103 |= ( V_118 << V_113 ) ;
break;
default:
goto V_119;
}
V_103 |= ( 64ULL - V_5 -> V_92 ) << V_120 ;
V_103 |= V_121 ;
V_5 -> V_122 . V_123 = V_103 ;
V_103 = ( V_124
<< F_49 ( V_125 ) ) |
( V_126
<< F_49 ( V_53 ) ) |
( V_127
<< F_49 ( V_128 ) ) ;
V_5 -> V_122 . V_129 [ 0 ] = V_103 ;
V_5 -> V_122 . V_129 [ 1 ] = 0 ;
V_18 -> V_65 = F_3 ( V_18 -> V_70 , V_96 , V_5 ) ;
if ( ! V_18 -> V_65 )
goto V_119;
F_29 () ;
V_5 -> V_122 . V_130 [ 0 ] = F_2 ( V_18 -> V_65 ) ;
V_5 -> V_122 . V_130 [ 1 ] = 0 ;
return & V_18 -> V_23 ;
V_119:
F_33 ( V_18 ) ;
return NULL ;
}
static struct V_71 *
F_50 ( struct V_4 * V_5 , void * V_102 )
{
T_6 V_103 , V_131 ;
struct V_17 * V_18 ;
if ( V_5 -> V_29 )
return NULL ;
V_18 = F_44 ( V_5 ) ;
if ( ! V_18 )
return NULL ;
if ( V_18 -> V_98 == V_32 ) {
unsigned long V_132 ;
V_132 = V_18 -> V_70 >> F_46 ( sizeof( T_4 ) ) ;
if ( V_132 <= V_133 ) {
V_18 -> V_70 = V_132 << V_18 -> V_37 ;
V_18 -> V_98 -- ;
}
}
V_103 = V_134 |
( V_104 << V_105 ) |
( V_106 << V_107 ) |
( V_106 << V_108 ) ;
V_131 = F_28 ( V_18 ) ;
switch ( F_22 ( V_18 ) ) {
case V_83 :
V_103 |= V_109 ;
V_131 ++ ;
break;
case V_86 :
V_103 |= V_110 ;
break;
case V_88 :
V_103 |= V_111 ;
break;
}
switch ( V_5 -> V_94 ) {
case 32 :
V_103 |= ( V_112 << V_135 ) ;
break;
case 36 :
V_103 |= ( V_114 << V_135 ) ;
break;
case 40 :
V_103 |= ( V_115 << V_135 ) ;
break;
case 42 :
V_103 |= ( V_116 << V_135 ) ;
break;
case 44 :
V_103 |= ( V_117 << V_135 ) ;
break;
case 48 :
V_103 |= ( V_118 << V_135 ) ;
break;
default:
goto V_119;
}
V_103 |= ( 64ULL - V_5 -> V_92 ) << V_120 ;
V_103 |= ( ~ V_131 & V_136 ) << V_137 ;
V_5 -> V_138 . V_139 = V_103 ;
V_18 -> V_65 = F_3 ( V_18 -> V_70 , V_96 , V_5 ) ;
if ( ! V_18 -> V_65 )
goto V_119;
F_29 () ;
V_5 -> V_138 . V_140 = F_2 ( V_18 -> V_65 ) ;
return & V_18 -> V_23 ;
V_119:
F_33 ( V_18 ) ;
return NULL ;
}
static struct V_71 *
F_51 ( struct V_4 * V_5 , void * V_102 )
{
struct V_71 * V_23 ;
if ( V_5 -> V_92 > 32 || V_5 -> V_94 > 40 )
return NULL ;
V_5 -> V_40 &= ( V_83 | V_84 | V_85 ) ;
V_23 = F_48 ( V_5 , V_102 ) ;
if ( V_23 ) {
V_5 -> V_122 . V_123 |= V_141 ;
V_5 -> V_122 . V_123 &= 0xffffffff ;
}
return V_23 ;
}
static struct V_71 *
F_52 ( struct V_4 * V_5 , void * V_102 )
{
struct V_71 * V_23 ;
if ( V_5 -> V_92 > 40 || V_5 -> V_94 > 40 )
return NULL ;
V_5 -> V_40 &= ( V_83 | V_84 | V_85 ) ;
V_23 = F_50 ( V_5 , V_102 ) ;
if ( V_23 )
V_5 -> V_138 . V_139 &= 0xffffffff ;
return V_23 ;
}
static void F_53 ( void * V_102 )
{
F_15 ( V_102 != V_142 ) ;
}
static void F_54 ( unsigned long V_19 , T_2 V_2 ,
T_2 V_80 , bool V_143 , void * V_102 )
{
F_15 ( V_102 != V_142 ) ;
F_15 ( ! ( V_2 & V_142 -> V_40 ) ) ;
}
static void F_55 ( void * V_102 )
{
F_15 ( V_102 != V_142 ) ;
}
static void T_7 F_56 ( struct V_62 * V_63 )
{
struct V_17 * V_18 = F_27 ( V_63 ) ;
struct V_4 * V_5 = & V_18 -> V_23 . V_5 ;
F_57 ( L_3 ,
V_5 -> V_40 , V_5 -> V_92 ) ;
F_57 ( L_4 ,
V_18 -> V_98 , V_18 -> V_70 , V_18 -> V_37 ,
V_18 -> V_97 , V_18 -> V_65 ) ;
}
static int T_7 F_58 ( struct V_4 * V_5 )
{
static const enum V_144 V_145 [] = {
V_45 ,
V_146 ,
} ;
int V_147 , V_148 ;
unsigned long V_19 ;
T_2 V_2 ;
struct V_62 * V_63 ;
V_11 = true ;
for ( V_147 = 0 ; V_147 < F_59 ( V_145 ) ; ++ V_147 ) {
V_142 = V_5 ;
V_63 = F_60 ( V_145 [ V_147 ] , V_5 , V_5 ) ;
if ( ! V_63 ) {
F_57 ( L_5 ) ;
return - V_42 ;
}
if ( V_63 -> V_101 ( V_63 , 42 ) )
return F_61 ( V_63 , V_147 ) ;
if ( V_63 -> V_101 ( V_63 , V_85 + 42 ) )
return F_61 ( V_63 , V_147 ) ;
if ( V_63 -> V_101 ( V_63 , V_149 + 42 ) )
return F_61 ( V_63 , V_147 ) ;
V_19 = 0 ;
V_148 = F_62 ( & V_5 -> V_40 , V_150 ) ;
while ( V_148 != V_150 ) {
V_2 = 1UL << V_148 ;
if ( V_63 -> V_99 ( V_63 , V_19 , V_19 , V_2 , V_50 |
V_49 |
V_60 |
V_52 ) )
return F_61 ( V_63 , V_147 ) ;
if ( ! V_63 -> V_99 ( V_63 , V_19 , V_19 + V_2 , V_2 ,
V_50 | V_60 ) )
return F_61 ( V_63 , V_147 ) ;
if ( V_63 -> V_101 ( V_63 , V_19 + 42 ) != ( V_19 + 42 ) )
return F_61 ( V_63 , V_147 ) ;
V_19 += V_85 ;
V_148 ++ ;
V_148 = F_63 ( & V_5 -> V_40 , V_150 , V_148 ) ;
}
V_2 = 1UL << F_43 ( V_5 -> V_40 ) ;
if ( V_63 -> V_100 ( V_63 , V_85 + V_2 , V_2 ) != V_2 )
return F_61 ( V_63 , V_147 ) ;
if ( V_63 -> V_99 ( V_63 , V_85 + V_2 , V_2 , V_2 , V_50 ) )
return F_61 ( V_63 , V_147 ) ;
if ( V_63 -> V_101 ( V_63 , V_85 + V_2 + 42 ) != ( V_2 + 42 ) )
return F_61 ( V_63 , V_147 ) ;
V_19 = 0 ;
V_148 = F_62 ( & V_5 -> V_40 , V_150 ) ;
while ( V_148 != V_150 ) {
V_2 = 1UL << V_148 ;
if ( V_63 -> V_100 ( V_63 , V_19 , V_2 ) != V_2 )
return F_61 ( V_63 , V_147 ) ;
if ( V_63 -> V_101 ( V_63 , V_19 + 42 ) )
return F_61 ( V_63 , V_147 ) ;
if ( V_63 -> V_99 ( V_63 , V_19 , V_19 , V_2 , V_49 ) )
return F_61 ( V_63 , V_147 ) ;
if ( V_63 -> V_101 ( V_63 , V_19 + 42 ) != ( V_19 + 42 ) )
return F_61 ( V_63 , V_147 ) ;
V_19 += V_85 ;
V_148 ++ ;
V_148 = F_63 ( & V_5 -> V_40 , V_150 , V_148 ) ;
}
F_64 ( V_63 ) ;
}
V_11 = false ;
return 0 ;
}
static int T_7 F_65 ( void )
{
static const unsigned long V_151 [] = {
V_83 | V_84 | V_85 ,
V_86 | V_87 ,
V_88 | V_89 ,
} ;
static const unsigned int V_92 [] = {
32 , 36 , 40 , 42 , 44 , 48 ,
} ;
int V_147 , V_148 , V_152 = 0 , V_153 = 0 ;
struct V_4 V_5 = {
. V_154 = & V_155 ,
. V_94 = 48 ,
} ;
for ( V_147 = 0 ; V_147 < F_59 ( V_151 ) ; ++ V_147 ) {
for ( V_148 = 0 ; V_148 < F_59 ( V_92 ) ; ++ V_148 ) {
V_5 . V_40 = V_151 [ V_147 ] ;
V_5 . V_92 = V_92 [ V_148 ] ;
F_66 ( L_6 ,
V_151 [ V_147 ] , V_92 [ V_148 ] ) ;
if ( F_58 ( & V_5 ) )
V_153 ++ ;
else
V_152 ++ ;
}
}
F_66 ( L_7 , V_152 , V_153 ) ;
return V_153 ? - V_156 : 0 ;
}
