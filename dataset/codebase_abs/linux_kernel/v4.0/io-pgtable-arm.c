static int F_1 ( struct V_1 * V_2 ,
unsigned long V_3 , T_1 V_4 ,
T_2 V_5 , int V_6 ,
T_2 * V_7 )
{
T_2 V_8 = V_5 ;
if ( F_2 ( * V_7 , V_6 ) ) {
F_3 ( ! V_9 ) ;
return - V_10 ;
}
if ( V_2 -> V_11 . V_12 . V_13 & V_14 )
V_8 |= V_15 ;
if ( V_6 == V_16 - 1 )
V_8 |= V_17 ;
else
V_8 |= V_18 ;
V_8 |= V_19 | V_20 ;
V_8 |= F_4 ( V_4 >> V_2 -> V_21 , V_2 ) ;
* V_7 = V_8 ;
V_2 -> V_11 . V_12 . V_22 -> V_23 ( V_7 , sizeof( * V_7 ) , V_2 -> V_11 . V_24 ) ;
return 0 ;
}
static int F_5 ( struct V_1 * V_2 , unsigned long V_3 ,
T_1 V_4 , T_3 V_25 , T_2 V_5 ,
int V_6 , T_2 * V_7 )
{
T_2 * V_26 , V_8 ;
void * V_24 = V_2 -> V_11 . V_24 ;
T_3 V_27 = F_6 ( V_6 , V_2 ) ;
V_7 += F_7 ( V_3 , V_6 , V_2 ) ;
if ( V_25 == V_27 && ( V_25 & V_2 -> V_11 . V_12 . V_28 ) )
return F_1 ( V_2 , V_3 , V_4 , V_5 , V_6 , V_7 ) ;
if ( F_3 ( V_6 >= V_16 - 1 ) )
return - V_29 ;
V_8 = * V_7 ;
if ( ! V_8 ) {
V_26 = F_8 ( 1UL << V_2 -> V_21 ,
V_30 | V_31 ) ;
if ( ! V_26 )
return - V_32 ;
V_2 -> V_11 . V_12 . V_22 -> V_23 ( V_26 , 1UL << V_2 -> V_21 ,
V_24 ) ;
V_8 = F_9 ( V_26 ) | V_33 ;
if ( V_2 -> V_11 . V_12 . V_13 & V_14 )
V_8 |= V_34 ;
* V_7 = V_8 ;
V_2 -> V_11 . V_12 . V_22 -> V_23 ( V_7 , sizeof( * V_7 ) , V_24 ) ;
} else {
V_26 = F_10 ( V_8 , V_2 ) ;
}
return F_5 ( V_2 , V_3 , V_4 , V_25 , V_5 , V_6 + 1 , V_26 ) ;
}
static T_2 F_11 ( struct V_1 * V_2 ,
int V_5 )
{
T_2 V_8 ;
if ( V_2 -> V_11 . V_35 == V_36 ||
V_2 -> V_11 . V_35 == V_37 ) {
V_8 = V_38 | V_39 ;
if ( ! ( V_5 & V_40 ) && ( V_5 & V_41 ) )
V_8 |= V_42 ;
if ( V_5 & V_43 )
V_8 |= ( V_44
<< V_45 ) ;
} else {
V_8 = V_46 ;
if ( V_5 & V_41 )
V_8 |= V_47 ;
if ( V_5 & V_40 )
V_8 |= V_48 ;
if ( V_5 & V_43 )
V_8 |= V_49 ;
else
V_8 |= V_50 ;
}
if ( V_5 & V_51 )
V_8 |= V_52 ;
return V_8 ;
}
static int F_12 ( struct V_53 * V_54 , unsigned long V_3 ,
T_1 V_4 , T_3 V_25 , int V_55 )
{
struct V_1 * V_2 = F_13 ( V_54 ) ;
T_2 * V_7 = V_2 -> V_56 ;
int V_6 = F_14 ( V_2 ) ;
T_2 V_5 ;
if ( ! ( V_55 & ( V_41 | V_40 ) ) )
return 0 ;
V_5 = F_11 ( V_2 , V_55 ) ;
return F_5 ( V_2 , V_3 , V_4 , V_25 , V_5 , V_6 , V_7 ) ;
}
static void F_15 ( struct V_1 * V_2 , int V_6 ,
T_2 * V_7 )
{
T_2 * V_57 , * V_58 ;
unsigned long V_59 ;
if ( V_6 == V_16 - 1 )
return;
if ( V_6 == F_14 ( V_2 ) )
V_59 = V_2 -> V_60 ;
else
V_59 = 1UL << V_2 -> V_21 ;
V_57 = V_7 ;
V_58 = ( void * ) V_7 + V_59 ;
while ( V_7 != V_58 ) {
T_2 V_8 = * V_7 ++ ;
if ( ! V_8 || F_2 ( V_8 , V_6 ) )
continue;
F_15 ( V_2 , V_6 + 1 , F_10 ( V_8 , V_2 ) ) ;
}
F_16 ( V_57 , V_59 ) ;
}
static void F_17 ( struct V_61 * V_11 )
{
struct V_1 * V_2 = F_18 ( V_11 ) ;
F_15 ( V_2 , F_14 ( V_2 ) , V_2 -> V_56 ) ;
F_19 ( V_2 ) ;
}
static int F_20 ( struct V_1 * V_2 ,
unsigned long V_3 , T_3 V_25 ,
T_2 V_5 , int V_6 ,
T_2 * V_7 , T_3 V_62 )
{
unsigned long V_63 , V_64 ;
T_1 V_65 ;
T_2 V_66 = 0 ;
void * V_24 = V_2 -> V_11 . V_24 ;
const struct V_67 * V_22 = V_2 -> V_11 . V_12 . V_22 ;
V_63 = V_3 & ~ ( V_62 - 1 ) ;
V_64 = V_63 + V_62 ;
V_65 = F_21 ( * V_7 , V_2 ) << V_2 -> V_21 ;
for (; V_63 < V_64 ; V_63 += V_25 , V_65 += V_25 ) {
T_2 * V_68 ;
if ( V_63 == V_3 )
continue;
V_68 = & V_66 - F_7 ( V_63 , V_6 , V_2 ) ;
if ( F_5 ( V_2 , V_63 , V_65 , V_25 , V_5 , V_6 ,
V_68 ) < 0 ) {
if ( V_66 ) {
V_68 = F_10 ( V_66 , V_2 ) ;
F_15 ( V_2 , V_6 + 1 , V_68 ) ;
}
return 0 ;
}
}
* V_7 = V_66 ;
V_22 -> V_23 ( V_7 , sizeof( * V_7 ) , V_24 ) ;
V_3 &= ~ ( V_62 - 1 ) ;
V_22 -> V_69 ( V_3 , V_62 , true , V_24 ) ;
return V_25 ;
}
static int F_22 ( struct V_1 * V_2 ,
unsigned long V_3 , T_3 V_25 , int V_6 ,
T_2 * V_7 )
{
T_2 V_8 ;
const struct V_67 * V_22 = V_2 -> V_11 . V_12 . V_22 ;
void * V_24 = V_2 -> V_11 . V_24 ;
T_3 V_62 = F_6 ( V_6 , V_2 ) ;
V_7 += F_7 ( V_3 , V_6 , V_2 ) ;
V_8 = * V_7 ;
if ( F_3 ( ! V_8 || ( V_6 == V_16 ) ) )
return 0 ;
if ( V_25 == V_62 ) {
* V_7 = 0 ;
V_22 -> V_23 ( V_7 , sizeof( * V_7 ) , V_24 ) ;
if ( ! F_2 ( V_8 , V_6 ) ) {
V_22 -> V_69 ( V_3 , V_25 , false , V_24 ) ;
V_22 -> V_70 ( V_2 -> V_11 . V_24 ) ;
V_7 = F_10 ( V_8 , V_2 ) ;
F_15 ( V_2 , V_6 + 1 , V_7 ) ;
} else {
V_22 -> V_69 ( V_3 , V_25 , true , V_24 ) ;
}
return V_25 ;
} else if ( F_2 ( V_8 , V_6 ) ) {
return F_20 ( V_2 , V_3 , V_25 ,
F_23 ( V_8 ) , V_6 , V_7 ,
V_62 ) ;
}
V_7 = F_10 ( V_8 , V_2 ) ;
return F_22 ( V_2 , V_3 , V_25 , V_6 + 1 , V_7 ) ;
}
static int F_24 ( struct V_53 * V_54 , unsigned long V_3 ,
T_3 V_25 )
{
T_3 V_71 ;
struct V_1 * V_2 = F_13 ( V_54 ) ;
struct V_61 * V_11 = & V_2 -> V_11 ;
T_2 * V_7 = V_2 -> V_56 ;
int V_6 = F_14 ( V_2 ) ;
V_71 = F_22 ( V_2 , V_3 , V_25 , V_6 , V_7 ) ;
if ( V_71 )
V_11 -> V_12 . V_22 -> V_70 ( V_11 -> V_24 ) ;
return V_71 ;
}
static T_1 F_25 ( struct V_53 * V_54 ,
unsigned long V_3 )
{
struct V_1 * V_2 = F_13 ( V_54 ) ;
T_2 V_8 , * V_7 = V_2 -> V_56 ;
int V_6 = F_14 ( V_2 ) ;
do {
if ( ! V_7 )
return 0 ;
V_8 = * ( V_7 + F_7 ( V_3 , V_6 , V_2 ) ) ;
if ( ! V_8 )
return 0 ;
if ( F_2 ( V_8 , V_6 ) )
goto V_72;
V_7 = F_10 ( V_8 , V_2 ) ;
} while ( ++ V_6 < V_16 );
return 0 ;
V_72:
V_3 &= ( ( 1 << V_2 -> V_21 ) - 1 ) ;
return ( ( T_1 ) F_21 ( V_8 , V_2 ) << V_2 -> V_21 ) | V_3 ;
}
static void F_26 ( struct V_73 * V_12 )
{
unsigned long V_74 ;
if ( V_12 -> V_28 & V_75 )
V_74 = V_75 ;
else if ( V_12 -> V_28 & ~ V_76 )
V_74 = 1UL << F_27 ( V_12 -> V_28 & ~ V_76 ) ;
else if ( V_12 -> V_28 & V_76 )
V_74 = 1UL << F_28 ( V_12 -> V_28 & V_76 ) ;
else
V_74 = 0 ;
switch ( V_74 ) {
case V_77 :
V_12 -> V_28 &= ( V_77 | V_78 | V_79 ) ;
break;
case V_80 :
V_12 -> V_28 &= ( V_80 | V_81 ) ;
break;
case V_82 :
V_12 -> V_28 &= ( V_82 | V_83 ) ;
break;
default:
V_12 -> V_28 = 0 ;
}
}
static struct V_1 *
F_29 ( struct V_73 * V_12 )
{
unsigned long V_84 , V_85 ;
struct V_1 * V_2 ;
F_26 ( V_12 ) ;
if ( ! ( V_12 -> V_28 & ( V_77 | V_80 | V_82 ) ) )
return NULL ;
if ( V_12 -> V_86 > V_87 )
return NULL ;
if ( V_12 -> V_88 > V_87 )
return NULL ;
V_2 = F_30 ( sizeof( * V_2 ) , V_89 ) ;
if ( ! V_2 )
return NULL ;
V_2 -> V_21 = F_28 ( V_12 -> V_28 ) ;
V_2 -> V_90 = V_2 -> V_21 - F_31 ( sizeof( T_2 ) ) ;
V_84 = V_12 -> V_86 - V_2 -> V_21 ;
V_2 -> V_91 = F_32 ( V_84 , V_2 -> V_90 ) ;
V_85 = V_84 - ( V_2 -> V_90 * ( V_2 -> V_91 - 1 ) ) ;
V_2 -> V_60 = 1UL << ( V_85 + F_31 ( sizeof( T_2 ) ) ) ;
V_2 -> V_11 . V_54 = (struct V_53 ) {
. V_92 = F_12 ,
. V_93 = F_24 ,
. V_94 = F_25 ,
} ;
return V_2 ;
}
static struct V_61 *
F_33 ( struct V_73 * V_12 , void * V_24 )
{
T_4 V_95 ;
struct V_1 * V_2 = F_29 ( V_12 ) ;
if ( ! V_2 )
return NULL ;
V_95 = ( V_96 << V_97 ) |
( V_98 << V_99 ) |
( V_98 << V_100 ) ;
switch ( 1 << V_2 -> V_21 ) {
case V_77 :
V_95 |= V_101 ;
break;
case V_80 :
V_95 |= V_102 ;
break;
case V_82 :
V_95 |= V_103 ;
break;
}
switch ( V_12 -> V_88 ) {
case 32 :
V_95 |= ( V_104 << V_105 ) ;
break;
case 36 :
V_95 |= ( V_106 << V_105 ) ;
break;
case 40 :
V_95 |= ( V_107 << V_105 ) ;
break;
case 42 :
V_95 |= ( V_108 << V_105 ) ;
break;
case 44 :
V_95 |= ( V_109 << V_105 ) ;
break;
case 48 :
V_95 |= ( V_110 << V_105 ) ;
break;
default:
goto V_111;
}
V_95 |= ( 64ULL - V_12 -> V_86 ) << V_112 ;
V_12 -> V_113 . V_114 = V_95 ;
V_95 = ( V_115
<< F_34 ( V_116 ) ) |
( V_117
<< F_34 ( V_44 ) ) |
( V_118
<< F_34 ( V_119 ) ) ;
V_12 -> V_113 . V_120 [ 0 ] = V_95 ;
V_12 -> V_113 . V_120 [ 1 ] = 0 ;
V_2 -> V_56 = F_8 ( V_2 -> V_60 , V_89 | V_31 ) ;
if ( ! V_2 -> V_56 )
goto V_111;
V_12 -> V_22 -> V_23 ( V_2 -> V_56 , V_2 -> V_60 , V_24 ) ;
V_12 -> V_113 . V_121 [ 0 ] = F_35 ( V_2 -> V_56 ) ;
V_12 -> V_113 . V_121 [ 1 ] = 0 ;
return & V_2 -> V_11 ;
V_111:
F_19 ( V_2 ) ;
return NULL ;
}
static struct V_61 *
F_36 ( struct V_73 * V_12 , void * V_24 )
{
T_4 V_95 , V_122 ;
struct V_1 * V_2 = F_29 ( V_12 ) ;
if ( ! V_2 )
return NULL ;
if ( V_2 -> V_91 == V_16 ) {
unsigned long V_123 ;
V_123 = V_2 -> V_60 >> F_31 ( sizeof( T_2 ) ) ;
if ( V_123 <= V_124 ) {
V_2 -> V_60 = V_123 << V_2 -> V_21 ;
V_2 -> V_91 -- ;
}
}
V_95 = V_125 |
( V_96 << V_97 ) |
( V_98 << V_99 ) |
( V_98 << V_100 ) ;
V_122 = F_14 ( V_2 ) ;
switch ( 1 << V_2 -> V_21 ) {
case V_77 :
V_95 |= V_101 ;
V_122 ++ ;
break;
case V_80 :
V_95 |= V_102 ;
break;
case V_82 :
V_95 |= V_103 ;
break;
}
switch ( V_12 -> V_88 ) {
case 32 :
V_95 |= ( V_104 << V_126 ) ;
break;
case 36 :
V_95 |= ( V_106 << V_126 ) ;
break;
case 40 :
V_95 |= ( V_107 << V_126 ) ;
break;
case 42 :
V_95 |= ( V_108 << V_126 ) ;
break;
case 44 :
V_95 |= ( V_109 << V_126 ) ;
break;
case 48 :
V_95 |= ( V_110 << V_126 ) ;
break;
default:
goto V_111;
}
V_95 |= ( 64ULL - V_12 -> V_86 ) << V_112 ;
V_95 |= ( ~ V_122 & V_127 ) << V_128 ;
V_12 -> V_129 . V_130 = V_95 ;
V_2 -> V_56 = F_8 ( V_2 -> V_60 , V_89 | V_31 ) ;
if ( ! V_2 -> V_56 )
goto V_111;
V_12 -> V_22 -> V_23 ( V_2 -> V_56 , V_2 -> V_60 , V_24 ) ;
V_12 -> V_129 . V_131 = F_35 ( V_2 -> V_56 ) ;
return & V_2 -> V_11 ;
V_111:
F_19 ( V_2 ) ;
return NULL ;
}
static struct V_61 *
F_37 ( struct V_73 * V_12 , void * V_24 )
{
struct V_61 * V_11 ;
if ( V_12 -> V_86 > 32 || V_12 -> V_88 > 40 )
return NULL ;
V_12 -> V_28 &= ( V_77 | V_78 | V_79 ) ;
V_11 = F_33 ( V_12 , V_24 ) ;
if ( V_11 ) {
V_12 -> V_113 . V_114 |= V_132 ;
V_12 -> V_113 . V_114 &= 0xffffffff ;
}
return V_11 ;
}
static struct V_61 *
F_38 ( struct V_73 * V_12 , void * V_24 )
{
struct V_61 * V_11 ;
if ( V_12 -> V_86 > 40 || V_12 -> V_88 > 40 )
return NULL ;
V_12 -> V_28 &= ( V_77 | V_78 | V_79 ) ;
V_11 = F_36 ( V_12 , V_24 ) ;
if ( V_11 )
V_12 -> V_129 . V_130 &= 0xffffffff ;
return V_11 ;
}
static void F_39 ( void * V_24 )
{
F_3 ( V_24 != V_133 ) ;
}
static void F_40 ( unsigned long V_3 , T_3 V_25 , bool V_134 ,
void * V_24 )
{
F_3 ( V_24 != V_133 ) ;
F_3 ( ! ( V_25 & V_133 -> V_28 ) ) ;
}
static void F_41 ( void * V_24 )
{
F_3 ( V_24 != V_133 ) ;
}
static void F_42 ( void * V_135 , T_3 V_25 , void * V_24 )
{
F_3 ( V_24 != V_133 ) ;
}
static void T_5 F_43 ( struct V_53 * V_54 )
{
struct V_1 * V_2 = F_13 ( V_54 ) ;
struct V_73 * V_12 = & V_2 -> V_11 . V_12 ;
F_44 ( L_1 ,
V_12 -> V_28 , V_12 -> V_86 ) ;
F_44 ( L_2 ,
V_2 -> V_91 , V_2 -> V_60 , V_2 -> V_21 ,
V_2 -> V_90 , V_2 -> V_56 ) ;
}
static int T_5 F_45 ( struct V_73 * V_12 )
{
static const enum V_136 V_137 [] = {
V_36 ,
V_138 ,
} ;
int V_139 , V_140 ;
unsigned long V_3 ;
T_3 V_25 ;
struct V_53 * V_54 ;
V_9 = true ;
for ( V_139 = 0 ; V_139 < F_46 ( V_137 ) ; ++ V_139 ) {
V_133 = V_12 ;
V_54 = F_47 ( V_137 [ V_139 ] , V_12 , V_12 ) ;
if ( ! V_54 ) {
F_44 ( L_3 ) ;
return - V_32 ;
}
if ( V_54 -> V_94 ( V_54 , 42 ) )
return F_48 ( V_54 , V_139 ) ;
if ( V_54 -> V_94 ( V_54 , V_79 + 42 ) )
return F_48 ( V_54 , V_139 ) ;
if ( V_54 -> V_94 ( V_54 , V_141 + 42 ) )
return F_48 ( V_54 , V_139 ) ;
V_3 = 0 ;
V_140 = F_49 ( & V_12 -> V_28 , V_142 ) ;
while ( V_140 != V_142 ) {
V_25 = 1UL << V_140 ;
if ( V_54 -> V_92 ( V_54 , V_3 , V_3 , V_25 , V_41 |
V_40 |
V_51 |
V_43 ) )
return F_48 ( V_54 , V_139 ) ;
if ( ! V_54 -> V_92 ( V_54 , V_3 , V_3 + V_25 , V_25 ,
V_41 | V_51 ) )
return F_48 ( V_54 , V_139 ) ;
if ( V_54 -> V_94 ( V_54 , V_3 + 42 ) != ( V_3 + 42 ) )
return F_48 ( V_54 , V_139 ) ;
V_3 += V_79 ;
V_140 ++ ;
V_140 = F_50 ( & V_12 -> V_28 , V_142 , V_140 ) ;
}
V_25 = 1UL << F_28 ( V_12 -> V_28 ) ;
if ( V_54 -> V_93 ( V_54 , V_79 + V_25 , V_25 ) != V_25 )
return F_48 ( V_54 , V_139 ) ;
if ( V_54 -> V_92 ( V_54 , V_79 + V_25 , V_25 , V_25 , V_41 ) )
return F_48 ( V_54 , V_139 ) ;
if ( V_54 -> V_94 ( V_54 , V_79 + V_25 + 42 ) != ( V_25 + 42 ) )
return F_48 ( V_54 , V_139 ) ;
V_3 = 0 ;
V_140 = F_49 ( & V_12 -> V_28 , V_142 ) ;
while ( V_140 != V_142 ) {
V_25 = 1UL << V_140 ;
if ( V_54 -> V_93 ( V_54 , V_3 , V_25 ) != V_25 )
return F_48 ( V_54 , V_139 ) ;
if ( V_54 -> V_94 ( V_54 , V_3 + 42 ) )
return F_48 ( V_54 , V_139 ) ;
if ( V_54 -> V_92 ( V_54 , V_3 , V_3 , V_25 , V_40 ) )
return F_48 ( V_54 , V_139 ) ;
if ( V_54 -> V_94 ( V_54 , V_3 + 42 ) != ( V_3 + 42 ) )
return F_48 ( V_54 , V_139 ) ;
V_3 += V_79 ;
V_140 ++ ;
V_140 = F_50 ( & V_12 -> V_28 , V_142 , V_140 ) ;
}
F_51 ( V_54 ) ;
}
V_9 = false ;
return 0 ;
}
static int T_5 F_52 ( void )
{
static const unsigned long V_143 [] = {
V_77 | V_78 | V_79 ,
V_80 | V_81 ,
V_82 | V_83 ,
} ;
static const unsigned int V_86 [] = {
32 , 36 , 40 , 42 , 44 , 48 ,
} ;
int V_139 , V_140 , V_144 = 0 , V_145 = 0 ;
struct V_73 V_12 = {
. V_22 = & V_146 ,
. V_88 = 48 ,
} ;
for ( V_139 = 0 ; V_139 < F_46 ( V_143 ) ; ++ V_139 ) {
for ( V_140 = 0 ; V_140 < F_46 ( V_86 ) ; ++ V_140 ) {
V_12 . V_28 = V_143 [ V_139 ] ;
V_12 . V_86 = V_86 [ V_140 ] ;
F_53 ( L_4 ,
V_143 [ V_139 ] , V_86 [ V_140 ] ) ;
if ( F_45 ( & V_12 ) )
V_145 ++ ;
else
V_144 ++ ;
}
}
F_53 ( L_5 , V_144 , V_145 ) ;
return V_145 ? - V_147 : 0 ;
}
