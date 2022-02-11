static T_1 F_1 ( struct V_1 * V_2 , int V_3 )
{
switch ( V_3 ) {
case V_4 :
case V_5 :
return F_2 ( V_2 -> V_6 + V_3 ) ;
default:
return F_3 ( V_2 -> V_6 + V_3 ) ;
}
}
static void F_4 ( struct V_1 * V_2 , int V_3 ,
T_1 V_7 )
{
switch ( V_3 ) {
case V_4 :
case V_5 :
F_5 ( V_7 , V_2 -> V_6 + V_3 ) ;
break;
default:
F_6 ( V_7 , V_2 -> V_6 + V_3 ) ;
break;
}
}
static int F_7 ( struct V_1 * V_2 ,
T_1 V_8 , T_1 V_9 )
{
T_1 V_10 = V_8 | V_9 ;
T_1 V_11 ;
int V_12 ;
V_11 = F_1 ( V_2 , V_13 ) ;
V_11 &= ~ V_8 ;
V_11 |= V_9 ;
F_4 ( V_2 , V_13 , V_11 ) ;
for ( V_12 = 100 ; V_12 > 0 ; V_12 -- ) {
if ( ( F_1 ( V_2 , V_13 ) & V_10 ) == V_9 )
break;
F_8 ( 10 ) ;
}
return V_12 > 0 ? 0 : - V_14 ;
}
static T_2 F_9 ( int V_15 , void * V_11 )
{
struct V_1 * V_2 = V_11 ;
F_4 ( V_2 , V_16 , 0 ) ;
F_10 ( & V_2 -> V_17 ) ;
return V_18 ;
}
static void F_11 ( struct V_1 * V_2 ,
unsigned long V_19 , T_1 V_20 )
{
unsigned long div = 1024 ;
T_1 V_21 , V_22 ;
T_3 V_12 ;
if ( ! F_12 ( ! V_20 || ! V_19 ) )
div = F_13 ( V_19 , V_20 ) ;
div = F_14 (unsigned long, div, p->min_div) ;
for ( V_12 = 0 ; V_12 < F_15 ( V_23 ) ; V_12 ++ ) {
V_21 = F_13 ( div , V_23 [ V_12 ] . div ) ;
if ( V_23 [ V_12 ] . div == 1 && V_21 > 2 )
continue;
if ( V_21 <= 32 )
break;
}
V_12 = F_16 ( int , V_12 , F_15 ( V_23 ) - 1 ) ;
V_22 = V_23 [ V_12 ] . V_24 | F_17 ( V_21 ) ;
F_4 ( V_2 , V_4 , V_22 ) ;
if ( ! ( V_2 -> V_25 -> V_26 & V_27 ) )
F_4 ( V_2 , V_5 , V_22 ) ;
}
static T_1 F_18 ( T_1 V_28 )
{
if ( V_28 % 100 )
return V_28 / 100 + 5 ;
else
return V_28 / 100 ;
}
static T_1 F_19 ( struct V_1 * V_2 )
{
T_1 V_29 ;
if ( ! V_2 -> V_30 )
return 0 ;
if ( V_2 -> V_30 -> V_31 > 200 || V_2 -> V_30 -> V_32 > 300 ) {
F_20 ( & V_2 -> V_33 -> V_34 , L_1 ) ;
return 0 ;
}
if ( ( V_2 -> V_30 -> V_31 + V_2 -> V_30 -> V_32 ) % 100 ) {
F_20 ( & V_2 -> V_33 -> V_34 , L_2 ) ;
return 0 ;
}
V_29 = F_18 ( V_2 -> V_30 -> V_31 ) << V_35 ;
V_29 |= F_18 ( V_2 -> V_30 -> V_32 ) << V_36 ;
return V_29 ;
}
static void F_21 ( struct V_1 * V_2 ,
T_1 V_37 , T_1 V_38 ,
T_1 V_39 , T_1 V_40 , T_1 V_41 )
{
T_1 V_42 ;
int V_43 ;
V_42 = V_44 | 1 << V_45 | V_46 ;
V_42 |= ! V_41 << V_47 ;
V_42 |= V_40 << V_48 ;
V_42 |= F_19 ( V_2 ) ;
if ( F_22 ( V_2 -> V_25 ) )
F_4 ( V_2 , V_49 , V_42 | V_50 ) ;
else
F_4 ( V_2 , V_49 , V_42 | V_51 | V_50 ) ;
if ( V_2 -> V_25 -> V_26 & V_27 ) {
V_42 &= ~ 0x0000ffff ;
}
F_4 ( V_2 , V_52 , V_42 ) ;
V_42 = 0 ;
V_42 |= V_53 | V_37 << V_54 ;
V_42 |= V_55 | V_37 << V_56 ;
V_43 = V_37 ^ ! V_38 ;
V_42 |= V_43 << V_57 ;
V_42 |= V_43 << V_58 ;
V_42 |= V_39 ? V_59 : V_60 ;
F_4 ( V_2 , V_13 , V_42 ) ;
}
static void F_23 ( struct V_1 * V_2 ,
const void * V_61 , void * V_62 ,
T_1 V_63 , T_1 V_64 )
{
T_1 V_65 = F_24 ( V_63 ) | F_25 ( V_64 ) ;
if ( V_61 || ( V_2 -> V_25 -> V_26 & V_27 ) )
F_4 ( V_2 , V_66 , V_65 ) ;
else
F_4 ( V_2 , V_66 , V_65 | V_67 ) ;
if ( V_62 )
F_4 ( V_2 , V_68 , V_65 ) ;
}
static void F_26 ( struct V_1 * V_2 )
{
F_4 ( V_2 , V_69 , F_1 ( V_2 , V_69 ) ) ;
}
static void F_27 ( struct V_1 * V_2 ,
const void * V_61 , int V_64 , int V_70 )
{
const T_4 * V_71 = V_61 ;
int V_12 ;
for ( V_12 = 0 ; V_12 < V_64 ; V_12 ++ )
F_4 ( V_2 , V_72 , V_71 [ V_12 ] << V_70 ) ;
}
static void F_28 ( struct V_1 * V_2 ,
const void * V_61 , int V_64 , int V_70 )
{
const T_5 * V_73 = V_61 ;
int V_12 ;
for ( V_12 = 0 ; V_12 < V_64 ; V_12 ++ )
F_4 ( V_2 , V_72 , V_73 [ V_12 ] << V_70 ) ;
}
static void F_29 ( struct V_1 * V_2 ,
const void * V_61 , int V_64 , int V_70 )
{
const T_5 * V_73 = V_61 ;
int V_12 ;
for ( V_12 = 0 ; V_12 < V_64 ; V_12 ++ )
F_4 ( V_2 , V_72 , F_30 ( & V_73 [ V_12 ] ) << V_70 ) ;
}
static void F_31 ( struct V_1 * V_2 ,
const void * V_61 , int V_64 , int V_70 )
{
const T_1 * V_74 = V_61 ;
int V_12 ;
for ( V_12 = 0 ; V_12 < V_64 ; V_12 ++ )
F_4 ( V_2 , V_72 , V_74 [ V_12 ] << V_70 ) ;
}
static void F_32 ( struct V_1 * V_2 ,
const void * V_61 , int V_64 , int V_70 )
{
const T_1 * V_74 = V_61 ;
int V_12 ;
for ( V_12 = 0 ; V_12 < V_64 ; V_12 ++ )
F_4 ( V_2 , V_72 , F_30 ( & V_74 [ V_12 ] ) << V_70 ) ;
}
static void F_33 ( struct V_1 * V_2 ,
const void * V_61 , int V_64 , int V_70 )
{
const T_1 * V_74 = V_61 ;
int V_12 ;
for ( V_12 = 0 ; V_12 < V_64 ; V_12 ++ )
F_4 ( V_2 , V_72 , F_34 ( V_74 [ V_12 ] << V_70 ) ) ;
}
static void F_35 ( struct V_1 * V_2 ,
const void * V_61 , int V_64 , int V_70 )
{
const T_1 * V_74 = V_61 ;
int V_12 ;
for ( V_12 = 0 ; V_12 < V_64 ; V_12 ++ )
F_4 ( V_2 , V_72 , F_34 ( F_30 ( & V_74 [ V_12 ] ) << V_70 ) ) ;
}
static void F_36 ( struct V_1 * V_2 ,
void * V_62 , int V_64 , int V_70 )
{
T_4 * V_71 = V_62 ;
int V_12 ;
for ( V_12 = 0 ; V_12 < V_64 ; V_12 ++ )
V_71 [ V_12 ] = F_1 ( V_2 , V_75 ) >> V_70 ;
}
static void F_37 ( struct V_1 * V_2 ,
void * V_62 , int V_64 , int V_70 )
{
T_5 * V_73 = V_62 ;
int V_12 ;
for ( V_12 = 0 ; V_12 < V_64 ; V_12 ++ )
V_73 [ V_12 ] = F_1 ( V_2 , V_75 ) >> V_70 ;
}
static void F_38 ( struct V_1 * V_2 ,
void * V_62 , int V_64 , int V_70 )
{
T_5 * V_73 = V_62 ;
int V_12 ;
for ( V_12 = 0 ; V_12 < V_64 ; V_12 ++ )
F_39 ( F_1 ( V_2 , V_75 ) >> V_70 , & V_73 [ V_12 ] ) ;
}
static void F_40 ( struct V_1 * V_2 ,
void * V_62 , int V_64 , int V_70 )
{
T_1 * V_74 = V_62 ;
int V_12 ;
for ( V_12 = 0 ; V_12 < V_64 ; V_12 ++ )
V_74 [ V_12 ] = F_1 ( V_2 , V_75 ) >> V_70 ;
}
static void F_41 ( struct V_1 * V_2 ,
void * V_62 , int V_64 , int V_70 )
{
T_1 * V_74 = V_62 ;
int V_12 ;
for ( V_12 = 0 ; V_12 < V_64 ; V_12 ++ )
F_39 ( F_1 ( V_2 , V_75 ) >> V_70 , & V_74 [ V_12 ] ) ;
}
static void F_42 ( struct V_1 * V_2 ,
void * V_62 , int V_64 , int V_70 )
{
T_1 * V_74 = V_62 ;
int V_12 ;
for ( V_12 = 0 ; V_12 < V_64 ; V_12 ++ )
V_74 [ V_12 ] = F_34 ( F_1 ( V_2 , V_75 ) >> V_70 ) ;
}
static void F_43 ( struct V_1 * V_2 ,
void * V_62 , int V_64 , int V_70 )
{
T_1 * V_74 = V_62 ;
int V_12 ;
for ( V_12 = 0 ; V_12 < V_64 ; V_12 ++ )
F_39 ( F_34 ( F_1 ( V_2 , V_75 ) >> V_70 ) , & V_74 [ V_12 ] ) ;
}
static int F_44 ( struct V_76 * V_77 )
{
struct V_78 * V_79 = V_77 -> V_25 -> V_34 . V_80 ;
struct V_1 * V_2 = F_45 ( V_77 -> V_25 ) ;
F_46 ( & V_2 -> V_33 -> V_34 ) ;
if ( ! V_79 ) {
V_77 -> V_81 = ( V_82 ) V_77 -> V_83 ;
}
F_21 ( V_2 , ! ! ( V_77 -> V_84 & V_85 ) ,
! ! ( V_77 -> V_84 & V_86 ) ,
! ! ( V_77 -> V_84 & V_87 ) ,
! ! ( V_77 -> V_84 & V_88 ) ,
! ! ( V_77 -> V_84 & V_89 ) ) ;
if ( V_77 -> V_81 >= 0 )
F_47 ( V_77 -> V_81 , ! ( V_77 -> V_84 & V_89 ) ) ;
F_48 ( & V_2 -> V_33 -> V_34 ) ;
return 0 ;
}
static int F_49 ( struct V_90 * V_25 ,
struct V_91 * V_92 )
{
struct V_1 * V_2 = F_45 ( V_25 ) ;
const struct V_76 * V_77 = V_92 -> V_77 ;
F_21 ( V_2 , ! ! ( V_77 -> V_84 & V_85 ) ,
! ! ( V_77 -> V_84 & V_86 ) ,
! ! ( V_77 -> V_84 & V_87 ) ,
! ! ( V_77 -> V_84 & V_88 ) ,
! ! ( V_77 -> V_84 & V_89 ) ) ;
return 0 ;
}
static int F_50 ( struct V_1 * V_2 , void * V_62 )
{
bool V_93 = F_22 ( V_2 -> V_25 ) ;
int V_94 = 0 ;
if ( ! V_93 )
V_94 = F_7 ( V_2 , 0 , V_95 ) ;
if ( V_62 && ! V_94 )
V_94 = F_7 ( V_2 , 0 , V_96 ) ;
if ( ! V_94 )
V_94 = F_7 ( V_2 , 0 , V_97 ) ;
if ( ! V_94 && ! V_93 )
V_94 = F_7 ( V_2 , 0 , V_98 ) ;
return V_94 ;
}
static int F_51 ( struct V_1 * V_2 , void * V_62 )
{
bool V_93 = F_22 ( V_2 -> V_25 ) ;
int V_94 = 0 ;
if ( ! V_93 )
V_94 = F_7 ( V_2 , V_98 , 0 ) ;
if ( ! V_94 )
V_94 = F_7 ( V_2 , V_97 , 0 ) ;
if ( V_62 && ! V_94 )
V_94 = F_7 ( V_2 , V_96 , 0 ) ;
if ( ! V_94 && ! V_93 )
V_94 = F_7 ( V_2 , V_95 , 0 ) ;
return V_94 ;
}
static int F_52 ( struct V_90 * V_25 )
{
struct V_1 * V_2 = F_45 ( V_25 ) ;
V_2 -> V_99 = true ;
F_10 ( & V_2 -> V_17 ) ;
return 0 ;
}
static int F_53 ( struct V_1 * V_2 )
{
if ( F_22 ( V_2 -> V_25 ) ) {
if ( F_54 ( & V_2 -> V_17 ) ||
V_2 -> V_99 ) {
F_55 ( & V_2 -> V_33 -> V_34 , L_3 ) ;
return - V_100 ;
}
} else {
if ( ! F_56 ( & V_2 -> V_17 , V_101 ) ) {
F_57 ( & V_2 -> V_33 -> V_34 , L_4 ) ;
return - V_14 ;
}
}
return 0 ;
}
static int F_58 ( struct V_1 * V_2 ,
void (* F_59)( struct V_1 * ,
const void * , int , int ) ,
void (* F_60)( struct V_1 * ,
void * , int , int ) ,
const void * V_61 , void * V_62 ,
int V_64 , int V_63 )
{
int V_102 ;
int V_94 ;
if ( V_61 )
V_64 = F_16 ( int , V_64 , V_2 -> V_103 ) ;
if ( V_62 )
V_64 = F_16 ( int , V_64 , V_2 -> V_104 ) ;
V_102 = 32 - V_63 ;
F_4 ( V_2 , V_105 , 0 ) ;
F_23 ( V_2 , V_61 , V_62 , V_63 , V_64 ) ;
F_4 ( V_2 , V_16 , V_106 | V_107 ) ;
if ( V_61 )
F_59 ( V_2 , V_61 , V_64 , V_102 ) ;
F_61 ( & V_2 -> V_17 ) ;
V_2 -> V_99 = false ;
V_94 = F_50 ( V_2 , V_62 ) ;
if ( V_94 ) {
F_57 ( & V_2 -> V_33 -> V_34 , L_5 ) ;
goto V_108;
}
V_94 = F_53 ( V_2 ) ;
if ( V_94 )
goto V_109;
if ( V_62 )
F_60 ( V_2 , V_62 , V_64 , V_102 ) ;
F_26 ( V_2 ) ;
V_94 = F_51 ( V_2 , V_62 ) ;
if ( V_94 ) {
F_57 ( & V_2 -> V_33 -> V_34 , L_6 ) ;
return V_94 ;
}
return V_64 ;
V_109:
F_26 ( V_2 ) ;
F_51 ( V_2 , V_62 ) ;
V_108:
F_4 ( V_2 , V_16 , 0 ) ;
return V_94 ;
}
static void F_62 ( void * V_110 )
{
struct V_1 * V_2 = V_110 ;
F_4 ( V_2 , V_16 , 0 ) ;
F_10 ( & V_2 -> V_17 ) ;
}
static int F_63 ( struct V_1 * V_2 , const void * V_111 ,
void * V_112 , unsigned int V_113 )
{
T_1 V_114 = 0 ;
struct V_115 * V_116 = NULL , * V_117 = NULL ;
T_6 V_118 ;
int V_94 ;
if ( V_112 ) {
V_114 |= V_119 | V_120 ;
V_117 = F_64 ( V_2 -> V_25 -> V_121 ,
V_2 -> V_122 , V_113 , V_123 ,
V_124 | V_125 ) ;
if ( ! V_117 )
return - V_126 ;
V_117 -> V_127 = F_62 ;
V_117 -> V_128 = V_2 ;
V_118 = F_65 ( V_117 ) ;
if ( F_66 ( V_118 ) )
return V_118 ;
}
if ( V_111 ) {
V_114 |= V_129 | V_130 ;
F_67 ( V_2 -> V_25 -> V_131 -> V_132 -> V_34 ,
V_2 -> V_133 , V_113 , V_134 ) ;
V_116 = F_64 ( V_2 -> V_25 -> V_131 ,
V_2 -> V_133 , V_113 , V_134 ,
V_124 | V_125 ) ;
if ( ! V_116 ) {
V_94 = - V_126 ;
goto V_135;
}
if ( V_112 ) {
V_116 -> V_127 = NULL ;
} else {
V_116 -> V_127 = F_62 ;
V_116 -> V_128 = V_2 ;
}
V_118 = F_65 ( V_116 ) ;
if ( F_66 ( V_118 ) ) {
V_94 = V_118 ;
goto V_135;
}
}
F_4 ( V_2 , V_105 , V_136 | V_137 ) ;
F_23 ( V_2 , V_111 , V_112 , 32 , V_113 / 4 ) ;
F_4 ( V_2 , V_16 , V_114 ) ;
F_61 ( & V_2 -> V_17 ) ;
V_2 -> V_99 = false ;
if ( V_112 )
F_68 ( V_2 -> V_25 -> V_121 ) ;
if ( V_111 )
F_68 ( V_2 -> V_25 -> V_131 ) ;
V_94 = F_50 ( V_2 , V_112 ) ;
if ( V_94 ) {
F_57 ( & V_2 -> V_33 -> V_34 , L_5 ) ;
goto V_138;
}
V_94 = F_53 ( V_2 ) ;
if ( V_94 )
goto V_109;
F_26 ( V_2 ) ;
V_94 = F_51 ( V_2 , V_112 ) ;
if ( V_94 ) {
F_57 ( & V_2 -> V_33 -> V_34 , L_6 ) ;
return V_94 ;
}
if ( V_112 )
F_69 ( V_2 -> V_25 -> V_121 -> V_132 -> V_34 ,
V_2 -> V_122 , V_113 ,
V_123 ) ;
return 0 ;
V_109:
F_26 ( V_2 ) ;
F_51 ( V_2 , V_112 ) ;
V_138:
if ( V_111 )
F_70 ( V_2 -> V_25 -> V_131 ) ;
V_135:
if ( V_112 )
F_70 ( V_2 -> V_25 -> V_121 ) ;
F_4 ( V_2 , V_16 , 0 ) ;
return V_94 ;
}
static void F_71 ( T_1 * V_139 , const T_1 * V_140 , unsigned int V_64 )
{
if ( ( unsigned long ) V_140 & 3 ) {
while ( V_64 -- ) {
* V_139 ++ = F_34 ( F_30 ( V_140 ) ) ;
V_140 ++ ;
}
} else if ( ( unsigned long ) V_139 & 3 ) {
while ( V_64 -- ) {
F_39 ( F_34 ( * V_140 ++ ) , V_139 ) ;
V_139 ++ ;
}
} else {
while ( V_64 -- )
* V_139 ++ = F_34 ( * V_140 ++ ) ;
}
}
static void F_72 ( T_1 * V_139 , const T_1 * V_140 , unsigned int V_64 )
{
if ( ( unsigned long ) V_140 & 3 ) {
while ( V_64 -- ) {
* V_139 ++ = F_73 ( F_30 ( V_140 ) ) ;
V_140 ++ ;
}
} else if ( ( unsigned long ) V_139 & 3 ) {
while ( V_64 -- ) {
F_39 ( F_73 ( * V_140 ++ ) , V_139 ) ;
V_139 ++ ;
}
} else {
while ( V_64 -- )
* V_139 ++ = F_73 ( * V_140 ++ ) ;
}
}
static void F_74 ( T_1 * V_139 , const T_1 * V_140 , unsigned int V_64 )
{
memcpy ( V_139 , V_140 , V_64 * 4 ) ;
}
static int F_75 ( struct V_90 * V_25 ,
struct V_76 * V_77 ,
struct V_141 * V_142 )
{
struct V_1 * V_2 = F_45 ( V_25 ) ;
void (* F_76)( T_1 * , const T_1 * , unsigned int );
void (* F_59)( struct V_1 * , const void * , int , int );
void (* F_60)( struct V_1 * , void * , int , int );
const void * V_61 = V_142 -> V_61 ;
void * V_62 = V_142 -> V_62 ;
unsigned int V_113 = V_142 -> V_113 ;
unsigned int V_63 = V_142 -> V_143 ;
unsigned int V_144 ;
unsigned int V_64 ;
int V_145 ;
bool V_146 ;
int V_94 ;
if ( ! F_22 ( V_2 -> V_25 ) )
F_11 ( V_2 , F_77 ( V_2 -> V_147 ) , V_142 -> V_148 ) ;
while ( V_25 -> V_131 && V_113 > 15 ) {
unsigned int V_149 = 0 ;
if ( V_61 )
V_149 = F_78 ( V_113 , V_2 -> V_103 * 4 ) ;
if ( V_62 )
V_149 = F_78 ( V_113 , V_2 -> V_104 * 4 ) ;
if ( V_63 <= 8 ) {
if ( V_149 & 3 )
break;
F_76 = F_71 ;
} else if ( V_63 <= 16 ) {
if ( V_149 & 1 )
break;
F_76 = F_72 ;
} else {
F_76 = F_74 ;
}
if ( V_61 )
F_76 ( V_2 -> V_150 , V_61 , V_149 / 4 ) ;
V_94 = F_63 ( V_2 , V_61 , V_62 , V_149 ) ;
if ( V_94 == - V_126 ) {
F_79 ( L_7 ,
F_80 ( & V_2 -> V_33 -> V_34 ) ,
F_81 ( & V_2 -> V_33 -> V_34 ) ) ;
break;
}
if ( V_94 )
return V_94 ;
if ( V_62 ) {
F_76 ( V_62 , V_2 -> V_151 , V_149 / 4 ) ;
V_62 += V_149 ;
}
if ( V_61 )
V_61 += V_149 ;
V_113 -= V_149 ;
if ( ! V_113 )
return 0 ;
}
if ( V_63 <= 8 && V_113 > 15 && ! ( V_113 & 3 ) ) {
V_63 = 32 ;
V_146 = true ;
} else {
V_146 = false ;
}
if ( V_63 <= 8 ) {
V_144 = 1 ;
F_59 = F_27 ;
F_60 = F_36 ;
} else if ( V_63 <= 16 ) {
V_144 = 2 ;
if ( ( unsigned long ) V_61 & 0x01 )
F_59 = F_29 ;
else
F_59 = F_28 ;
if ( ( unsigned long ) V_62 & 0x01 )
F_60 = F_38 ;
else
F_60 = F_37 ;
} else if ( V_146 ) {
V_144 = 4 ;
if ( ( unsigned long ) V_61 & 0x03 )
F_59 = F_35 ;
else
F_59 = F_33 ;
if ( ( unsigned long ) V_62 & 0x03 )
F_60 = F_43 ;
else
F_60 = F_42 ;
} else {
V_144 = 4 ;
if ( ( unsigned long ) V_61 & 0x03 )
F_59 = F_32 ;
else
F_59 = F_31 ;
if ( ( unsigned long ) V_62 & 0x03 )
F_60 = F_41 ;
else
F_60 = F_40 ;
}
V_64 = V_113 / V_144 ;
while ( V_64 > 0 ) {
V_145 = F_58 ( V_2 , F_59 , F_60 , V_61 , V_62 ,
V_64 , V_63 ) ;
if ( V_145 < 0 )
return V_145 ;
if ( V_61 )
V_61 += V_145 * V_144 ;
if ( V_62 )
V_62 += V_145 * V_144 ;
V_64 -= V_145 ;
}
return 0 ;
}
static struct V_152 * F_82 ( struct V_132 * V_34 )
{
struct V_152 * V_30 ;
struct V_78 * V_79 = V_34 -> V_80 ;
T_1 V_153 = 1 ;
V_30 = F_83 ( V_34 , sizeof( struct V_152 ) , V_154 ) ;
if ( ! V_30 )
return NULL ;
V_30 -> V_84 = F_84 ( V_79 , L_8 ) ? V_155
: V_156 ;
if ( V_30 -> V_84 == V_156 )
F_85 ( V_79 , L_9 , & V_153 ) ;
F_85 ( V_79 , L_10 ,
& V_30 -> V_157 ) ;
F_85 ( V_79 , L_11 ,
& V_30 -> V_158 ) ;
F_85 ( V_79 , L_12 , & V_30 -> V_31 ) ;
F_85 ( V_79 , L_13 , & V_30 -> V_32 ) ;
V_30 -> V_159 = V_153 ;
return V_30 ;
}
static struct V_152 * F_82 ( struct V_132 * V_34 )
{
return NULL ;
}
static struct V_160 * F_86 ( struct V_132 * V_34 ,
enum V_161 V_162 , unsigned int V_163 , T_7 V_164 )
{
T_8 V_10 ;
struct V_160 * V_165 ;
struct V_166 V_167 ;
int V_94 ;
F_87 ( V_10 ) ;
F_88 ( V_168 , V_10 ) ;
V_165 = F_89 ( V_10 , V_169 ,
( void * ) ( unsigned long ) V_163 , V_34 ,
V_162 == V_170 ? L_14 : L_15 ) ;
if ( ! V_165 ) {
F_20 ( V_34 , L_16 ) ;
return NULL ;
}
memset ( & V_167 , 0 , sizeof( V_167 ) ) ;
V_167 . V_171 = V_162 ;
if ( V_162 == V_170 ) {
V_167 . V_172 = V_164 ;
V_167 . V_173 = V_174 ;
} else {
V_167 . V_175 = V_164 ;
V_167 . V_176 = V_174 ;
}
V_94 = F_90 ( V_165 , & V_167 ) ;
if ( V_94 ) {
F_20 ( V_34 , L_17 , V_94 ) ;
F_91 ( V_165 ) ;
return NULL ;
}
return V_165 ;
}
static int F_92 ( struct V_1 * V_2 )
{
struct V_177 * V_33 = V_2 -> V_33 ;
struct V_132 * V_34 = & V_33 -> V_34 ;
const struct V_152 * V_30 = F_93 ( V_34 ) ;
unsigned int V_178 , V_179 ;
const struct V_180 * V_181 ;
struct V_90 * V_25 ;
struct V_132 * V_182 , * V_183 ;
if ( V_34 -> V_80 ) {
V_178 = 0 ;
V_179 = 0 ;
} else if ( V_30 && V_30 -> V_178 && V_30 -> V_179 ) {
V_178 = V_30 -> V_178 ;
V_179 = V_30 -> V_179 ;
} else {
return 0 ;
}
V_181 = F_94 ( V_33 , V_184 , 1 ) ;
if ( ! V_181 )
V_181 = F_94 ( V_33 , V_184 , 0 ) ;
V_25 = V_2 -> V_25 ;
V_25 -> V_131 = F_86 ( V_34 , V_170 ,
V_178 ,
V_181 -> V_185 + V_72 ) ;
if ( ! V_25 -> V_131 )
return - V_186 ;
V_25 -> V_121 = F_86 ( V_34 , V_187 ,
V_179 ,
V_181 -> V_185 + V_75 ) ;
if ( ! V_25 -> V_121 )
goto V_188;
V_2 -> V_150 = ( void * ) F_95 ( V_154 | V_189 ) ;
if ( ! V_2 -> V_150 )
goto V_190;
V_2 -> V_151 = ( void * ) F_95 ( V_154 | V_189 ) ;
if ( ! V_2 -> V_151 )
goto V_191;
V_182 = V_25 -> V_131 -> V_132 -> V_34 ;
V_2 -> V_133 = F_96 ( V_182 , V_2 -> V_150 , V_192 ,
V_134 ) ;
if ( F_97 ( V_182 , V_2 -> V_133 ) )
goto V_193;
V_183 = V_25 -> V_121 -> V_132 -> V_34 ;
V_2 -> V_122 = F_96 ( V_183 , V_2 -> V_151 , V_192 ,
V_123 ) ;
if ( F_97 ( V_183 , V_2 -> V_122 ) )
goto V_194;
F_98 ( V_34 , L_18 ) ;
return 0 ;
V_194:
F_99 ( V_182 , V_2 -> V_133 , V_192 , V_134 ) ;
V_193:
F_100 ( ( unsigned long ) V_2 -> V_151 ) ;
V_191:
F_100 ( ( unsigned long ) V_2 -> V_150 ) ;
V_190:
F_91 ( V_25 -> V_121 ) ;
V_188:
F_91 ( V_25 -> V_131 ) ;
V_25 -> V_131 = NULL ;
return - V_186 ;
}
static void F_101 ( struct V_1 * V_2 )
{
struct V_90 * V_25 = V_2 -> V_25 ;
struct V_132 * V_34 ;
if ( ! V_25 -> V_131 )
return;
V_34 = & V_2 -> V_33 -> V_34 ;
F_99 ( V_25 -> V_121 -> V_132 -> V_34 , V_2 -> V_122 ,
V_192 , V_123 ) ;
F_99 ( V_25 -> V_131 -> V_132 -> V_34 , V_2 -> V_133 ,
V_192 , V_134 ) ;
F_100 ( ( unsigned long ) V_2 -> V_151 ) ;
F_100 ( ( unsigned long ) V_2 -> V_150 ) ;
F_91 ( V_25 -> V_121 ) ;
F_91 ( V_25 -> V_131 ) ;
}
static int F_102 ( struct V_177 * V_33 )
{
struct V_180 * V_195 ;
struct V_90 * V_25 ;
const struct V_196 * V_197 ;
const struct V_198 * V_199 ;
struct V_152 * V_30 ;
struct V_1 * V_2 ;
int V_200 ;
int V_94 ;
V_199 = F_103 ( V_201 , & V_33 -> V_34 ) ;
if ( V_199 ) {
V_197 = V_199 -> V_11 ;
V_30 = F_82 ( & V_33 -> V_34 ) ;
} else {
V_197 = ( const void * ) V_33 -> V_202 -> V_203 ;
V_30 = F_93 ( & V_33 -> V_34 ) ;
}
if ( ! V_30 ) {
F_57 ( & V_33 -> V_34 , L_19 ) ;
return - V_204 ;
}
if ( V_30 -> V_84 == V_155 )
V_25 = F_104 ( & V_33 -> V_34 ,
sizeof( struct V_1 ) ) ;
else
V_25 = F_105 ( & V_33 -> V_34 ,
sizeof( struct V_1 ) ) ;
if ( V_25 == NULL )
return - V_205 ;
V_2 = F_45 ( V_25 ) ;
F_106 ( V_33 , V_2 ) ;
V_2 -> V_25 = V_25 ;
V_2 -> V_30 = V_30 ;
V_2 -> V_206 = V_197 -> V_206 ;
F_107 ( & V_2 -> V_17 ) ;
V_2 -> V_147 = F_108 ( & V_33 -> V_34 , NULL ) ;
if ( F_109 ( V_2 -> V_147 ) ) {
F_57 ( & V_33 -> V_34 , L_20 ) ;
V_94 = F_110 ( V_2 -> V_147 ) ;
goto V_207;
}
V_200 = F_111 ( V_33 , 0 ) ;
if ( V_200 < 0 ) {
F_57 ( & V_33 -> V_34 , L_21 ) ;
V_94 = - V_208 ;
goto V_207;
}
V_195 = F_94 ( V_33 , V_184 , 0 ) ;
V_2 -> V_6 = F_112 ( & V_33 -> V_34 , V_195 ) ;
if ( F_109 ( V_2 -> V_6 ) ) {
V_94 = F_110 ( V_2 -> V_6 ) ;
goto V_207;
}
V_94 = F_113 ( & V_33 -> V_34 , V_200 , F_9 , 0 ,
F_81 ( & V_33 -> V_34 ) , V_2 ) ;
if ( V_94 ) {
F_57 ( & V_33 -> V_34 , L_22 ) ;
goto V_207;
}
V_2 -> V_33 = V_33 ;
F_114 ( & V_33 -> V_34 ) ;
V_2 -> V_103 = V_197 -> V_103 ;
V_2 -> V_104 = V_197 -> V_104 ;
if ( V_2 -> V_30 -> V_157 )
V_2 -> V_103 = V_2 -> V_30 -> V_157 ;
if ( V_2 -> V_30 -> V_158 )
V_2 -> V_104 = V_2 -> V_30 -> V_158 ;
V_25 -> V_209 = V_85 | V_86 | V_89 ;
V_25 -> V_209 |= V_88 | V_87 ;
V_25 -> V_26 = V_197 -> V_210 ;
V_25 -> V_211 = V_33 -> V_163 ;
V_25 -> V_34 . V_80 = V_33 -> V_34 . V_80 ;
V_25 -> V_159 = V_2 -> V_30 -> V_159 ;
V_25 -> V_212 = F_44 ;
V_25 -> V_213 = F_49 ;
V_25 -> V_214 = F_52 ;
V_25 -> V_215 = F_115 ( 8 , 32 ) ;
V_25 -> V_216 = true ;
V_25 -> V_217 = F_75 ;
V_94 = F_92 ( V_2 ) ;
if ( V_94 < 0 )
F_20 ( & V_33 -> V_34 , L_23 ) ;
V_94 = F_116 ( & V_33 -> V_34 , V_25 ) ;
if ( V_94 < 0 ) {
F_57 ( & V_33 -> V_34 , L_24 ) ;
goto V_218;
}
return 0 ;
V_218:
F_101 ( V_2 ) ;
F_117 ( & V_33 -> V_34 ) ;
V_207:
F_118 ( V_25 ) ;
return V_94 ;
}
static int F_119 ( struct V_177 * V_33 )
{
struct V_1 * V_2 = F_120 ( V_33 ) ;
F_101 ( V_2 ) ;
F_117 ( & V_33 -> V_34 ) ;
return 0 ;
}
