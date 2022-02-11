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
for ( V_12 = 0 ; V_12 < F_14 ( V_23 ) ; V_12 ++ ) {
V_21 = F_13 ( div , V_23 [ V_12 ] . div ) ;
if ( V_23 [ V_12 ] . div == 1 && V_21 > 2 )
continue;
if ( V_21 <= 32 )
break;
}
V_12 = F_15 ( int , V_12 , F_14 ( V_23 ) - 1 ) ;
V_22 = V_23 [ V_12 ] . V_24 | F_16 ( V_21 ) ;
F_4 ( V_2 , V_4 , V_22 ) ;
if ( ! ( V_2 -> V_25 -> V_26 & V_27 ) )
F_4 ( V_2 , V_5 , V_22 ) ;
}
static T_1 F_17 ( T_1 V_28 )
{
if ( V_28 % 100 )
return V_28 / 100 + 5 ;
else
return V_28 / 100 ;
}
static T_1 F_18 ( struct V_1 * V_2 )
{
T_1 V_29 ;
if ( ! V_2 -> V_30 )
return 0 ;
if ( V_2 -> V_30 -> V_31 > 200 || V_2 -> V_30 -> V_32 > 300 ) {
F_19 ( & V_2 -> V_33 -> V_34 , L_1 ) ;
return 0 ;
}
if ( ( V_2 -> V_30 -> V_31 + V_2 -> V_30 -> V_32 ) % 100 ) {
F_19 ( & V_2 -> V_33 -> V_34 , L_2 ) ;
return 0 ;
}
V_29 = F_17 ( V_2 -> V_30 -> V_31 ) << V_35 ;
V_29 |= F_17 ( V_2 -> V_30 -> V_32 ) << V_36 ;
return V_29 ;
}
static void F_20 ( struct V_1 * V_2 ,
T_1 V_37 , T_1 V_38 ,
T_1 V_39 , T_1 V_40 , T_1 V_41 )
{
T_1 V_42 ;
int V_43 ;
V_42 = V_44 | 1 << V_45 | V_46 ;
V_42 |= ! V_41 << V_47 ;
V_42 |= V_40 << V_48 ;
V_42 |= F_18 ( V_2 ) ;
F_4 ( V_2 , V_49 , V_42 | V_50 | V_51 ) ;
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
static void F_21 ( struct V_1 * V_2 ,
const void * V_61 , void * V_62 ,
T_1 V_63 , T_1 V_64 )
{
T_1 V_65 = F_22 ( V_63 ) | F_23 ( V_64 ) ;
if ( V_61 || ( V_2 -> V_25 -> V_26 & V_27 ) )
F_4 ( V_2 , V_66 , V_65 ) ;
else
F_4 ( V_2 , V_66 , V_65 | V_67 ) ;
if ( V_62 )
F_4 ( V_2 , V_68 , V_65 ) ;
}
static void F_24 ( struct V_1 * V_2 )
{
F_4 ( V_2 , V_69 , F_1 ( V_2 , V_69 ) ) ;
}
static void F_25 ( struct V_1 * V_2 ,
const void * V_61 , int V_64 , int V_70 )
{
const T_4 * V_71 = V_61 ;
int V_12 ;
for ( V_12 = 0 ; V_12 < V_64 ; V_12 ++ )
F_4 ( V_2 , V_72 , V_71 [ V_12 ] << V_70 ) ;
}
static void F_26 ( struct V_1 * V_2 ,
const void * V_61 , int V_64 , int V_70 )
{
const T_5 * V_73 = V_61 ;
int V_12 ;
for ( V_12 = 0 ; V_12 < V_64 ; V_12 ++ )
F_4 ( V_2 , V_72 , V_73 [ V_12 ] << V_70 ) ;
}
static void F_27 ( struct V_1 * V_2 ,
const void * V_61 , int V_64 , int V_70 )
{
const T_5 * V_73 = V_61 ;
int V_12 ;
for ( V_12 = 0 ; V_12 < V_64 ; V_12 ++ )
F_4 ( V_2 , V_72 , F_28 ( & V_73 [ V_12 ] ) << V_70 ) ;
}
static void F_29 ( struct V_1 * V_2 ,
const void * V_61 , int V_64 , int V_70 )
{
const T_1 * V_74 = V_61 ;
int V_12 ;
for ( V_12 = 0 ; V_12 < V_64 ; V_12 ++ )
F_4 ( V_2 , V_72 , V_74 [ V_12 ] << V_70 ) ;
}
static void F_30 ( struct V_1 * V_2 ,
const void * V_61 , int V_64 , int V_70 )
{
const T_1 * V_74 = V_61 ;
int V_12 ;
for ( V_12 = 0 ; V_12 < V_64 ; V_12 ++ )
F_4 ( V_2 , V_72 , F_28 ( & V_74 [ V_12 ] ) << V_70 ) ;
}
static void F_31 ( struct V_1 * V_2 ,
const void * V_61 , int V_64 , int V_70 )
{
const T_1 * V_74 = V_61 ;
int V_12 ;
for ( V_12 = 0 ; V_12 < V_64 ; V_12 ++ )
F_4 ( V_2 , V_72 , F_32 ( V_74 [ V_12 ] << V_70 ) ) ;
}
static void F_33 ( struct V_1 * V_2 ,
const void * V_61 , int V_64 , int V_70 )
{
const T_1 * V_74 = V_61 ;
int V_12 ;
for ( V_12 = 0 ; V_12 < V_64 ; V_12 ++ )
F_4 ( V_2 , V_72 , F_32 ( F_28 ( & V_74 [ V_12 ] ) << V_70 ) ) ;
}
static void F_34 ( struct V_1 * V_2 ,
void * V_62 , int V_64 , int V_70 )
{
T_4 * V_71 = V_62 ;
int V_12 ;
for ( V_12 = 0 ; V_12 < V_64 ; V_12 ++ )
V_71 [ V_12 ] = F_1 ( V_2 , V_75 ) >> V_70 ;
}
static void F_35 ( struct V_1 * V_2 ,
void * V_62 , int V_64 , int V_70 )
{
T_5 * V_73 = V_62 ;
int V_12 ;
for ( V_12 = 0 ; V_12 < V_64 ; V_12 ++ )
V_73 [ V_12 ] = F_1 ( V_2 , V_75 ) >> V_70 ;
}
static void F_36 ( struct V_1 * V_2 ,
void * V_62 , int V_64 , int V_70 )
{
T_5 * V_73 = V_62 ;
int V_12 ;
for ( V_12 = 0 ; V_12 < V_64 ; V_12 ++ )
F_37 ( F_1 ( V_2 , V_75 ) >> V_70 , & V_73 [ V_12 ] ) ;
}
static void F_38 ( struct V_1 * V_2 ,
void * V_62 , int V_64 , int V_70 )
{
T_1 * V_74 = V_62 ;
int V_12 ;
for ( V_12 = 0 ; V_12 < V_64 ; V_12 ++ )
V_74 [ V_12 ] = F_1 ( V_2 , V_75 ) >> V_70 ;
}
static void F_39 ( struct V_1 * V_2 ,
void * V_62 , int V_64 , int V_70 )
{
T_1 * V_74 = V_62 ;
int V_12 ;
for ( V_12 = 0 ; V_12 < V_64 ; V_12 ++ )
F_37 ( F_1 ( V_2 , V_75 ) >> V_70 , & V_74 [ V_12 ] ) ;
}
static void F_40 ( struct V_1 * V_2 ,
void * V_62 , int V_64 , int V_70 )
{
T_1 * V_74 = V_62 ;
int V_12 ;
for ( V_12 = 0 ; V_12 < V_64 ; V_12 ++ )
V_74 [ V_12 ] = F_32 ( F_1 ( V_2 , V_75 ) >> V_70 ) ;
}
static void F_41 ( struct V_1 * V_2 ,
void * V_62 , int V_64 , int V_70 )
{
T_1 * V_74 = V_62 ;
int V_12 ;
for ( V_12 = 0 ; V_12 < V_64 ; V_12 ++ )
F_37 ( F_32 ( F_1 ( V_2 , V_75 ) >> V_70 ) , & V_74 [ V_12 ] ) ;
}
static int F_42 ( struct V_76 * V_77 )
{
struct V_78 * V_79 = V_77 -> V_25 -> V_34 . V_80 ;
struct V_1 * V_2 = F_43 ( V_77 -> V_25 ) ;
F_44 ( & V_2 -> V_33 -> V_34 ) ;
if ( ! V_79 ) {
V_77 -> V_81 = ( V_82 ) V_77 -> V_83 ;
}
F_20 ( V_2 , ! ! ( V_77 -> V_84 & V_85 ) ,
! ! ( V_77 -> V_84 & V_86 ) ,
! ! ( V_77 -> V_84 & V_87 ) ,
! ! ( V_77 -> V_84 & V_88 ) ,
! ! ( V_77 -> V_84 & V_89 ) ) ;
if ( V_77 -> V_81 >= 0 )
F_45 ( V_77 -> V_81 , ! ( V_77 -> V_84 & V_89 ) ) ;
F_46 ( & V_2 -> V_33 -> V_34 ) ;
return 0 ;
}
static int F_47 ( struct V_90 * V_25 ,
struct V_91 * V_92 )
{
struct V_1 * V_2 = F_43 ( V_25 ) ;
const struct V_76 * V_77 = V_92 -> V_77 ;
F_20 ( V_2 , ! ! ( V_77 -> V_84 & V_85 ) ,
! ! ( V_77 -> V_84 & V_86 ) ,
! ! ( V_77 -> V_84 & V_87 ) ,
! ! ( V_77 -> V_84 & V_88 ) ,
! ! ( V_77 -> V_84 & V_89 ) ) ;
return 0 ;
}
static int F_48 ( struct V_1 * V_2 , void * V_62 )
{
int V_93 ;
V_93 = F_7 ( V_2 , 0 , V_94 ) ;
if ( V_62 && ! V_93 )
V_93 = F_7 ( V_2 , 0 , V_95 ) ;
if ( ! V_93 )
V_93 = F_7 ( V_2 , 0 , V_96 ) ;
if ( ! V_93 )
V_93 = F_7 ( V_2 , 0 , V_97 ) ;
return V_93 ;
}
static int F_49 ( struct V_1 * V_2 , void * V_62 )
{
int V_93 ;
V_93 = F_7 ( V_2 , V_97 , 0 ) ;
if ( ! V_93 )
V_93 = F_7 ( V_2 , V_96 , 0 ) ;
if ( V_62 && ! V_93 )
V_93 = F_7 ( V_2 , V_95 , 0 ) ;
if ( ! V_93 )
V_93 = F_7 ( V_2 , V_94 , 0 ) ;
return V_93 ;
}
static int F_50 ( struct V_1 * V_2 ,
void (* F_51)( struct V_1 * ,
const void * , int , int ) ,
void (* F_52)( struct V_1 * ,
void * , int , int ) ,
const void * V_61 , void * V_62 ,
int V_64 , int V_63 )
{
int V_98 ;
int V_93 ;
if ( V_61 )
V_64 = F_15 ( int , V_64 , V_2 -> V_99 ) ;
if ( V_62 )
V_64 = F_15 ( int , V_64 , V_2 -> V_100 ) ;
V_98 = 32 - V_63 ;
F_4 ( V_2 , V_101 , 0 ) ;
F_21 ( V_2 , V_61 , V_62 , V_63 , V_64 ) ;
F_4 ( V_2 , V_16 , V_102 | V_103 ) ;
if ( V_61 )
F_51 ( V_2 , V_61 , V_64 , V_98 ) ;
F_53 ( & V_2 -> V_17 ) ;
V_93 = F_48 ( V_2 , V_62 ) ;
if ( V_93 ) {
F_54 ( & V_2 -> V_33 -> V_34 , L_3 ) ;
goto V_104;
}
if ( ! F_55 ( & V_2 -> V_17 , V_105 ) ) {
F_54 ( & V_2 -> V_33 -> V_34 , L_4 ) ;
V_93 = - V_14 ;
goto V_106;
}
if ( V_62 )
F_52 ( V_2 , V_62 , V_64 , V_98 ) ;
F_24 ( V_2 ) ;
V_93 = F_49 ( V_2 , V_62 ) ;
if ( V_93 ) {
F_54 ( & V_2 -> V_33 -> V_34 , L_5 ) ;
return V_93 ;
}
return V_64 ;
V_106:
F_24 ( V_2 ) ;
F_49 ( V_2 , V_62 ) ;
V_104:
F_4 ( V_2 , V_16 , 0 ) ;
return V_93 ;
}
static void F_56 ( void * V_107 )
{
struct V_1 * V_2 = V_107 ;
F_4 ( V_2 , V_16 , 0 ) ;
F_10 ( & V_2 -> V_17 ) ;
}
static int F_57 ( struct V_1 * V_2 , const void * V_108 ,
void * V_109 , unsigned int V_110 )
{
T_1 V_111 = 0 ;
struct V_112 * V_113 = NULL , * V_114 = NULL ;
T_6 V_115 ;
int V_93 ;
if ( V_109 ) {
V_111 |= V_116 | V_117 ;
V_114 = F_58 ( V_2 -> V_25 -> V_118 ,
V_2 -> V_119 , V_110 , V_120 ,
V_121 | V_122 ) ;
if ( ! V_114 )
return - V_123 ;
V_114 -> V_124 = F_56 ;
V_114 -> V_125 = V_2 ;
V_115 = F_59 ( V_114 ) ;
if ( F_60 ( V_115 ) )
return V_115 ;
}
if ( V_108 ) {
V_111 |= V_126 | V_127 ;
F_61 ( V_2 -> V_25 -> V_128 -> V_129 -> V_34 ,
V_2 -> V_130 , V_110 , V_131 ) ;
V_113 = F_58 ( V_2 -> V_25 -> V_128 ,
V_2 -> V_130 , V_110 , V_131 ,
V_121 | V_122 ) ;
if ( ! V_113 ) {
V_93 = - V_123 ;
goto V_132;
}
if ( V_109 ) {
V_113 -> V_124 = NULL ;
} else {
V_113 -> V_124 = F_56 ;
V_113 -> V_125 = V_2 ;
}
V_115 = F_59 ( V_113 ) ;
if ( F_60 ( V_115 ) ) {
V_93 = V_115 ;
goto V_132;
}
}
F_4 ( V_2 , V_101 , V_133 | V_134 ) ;
F_21 ( V_2 , V_108 , V_109 , 32 , V_110 / 4 ) ;
F_4 ( V_2 , V_16 , V_111 ) ;
F_53 ( & V_2 -> V_17 ) ;
if ( V_109 )
F_62 ( V_2 -> V_25 -> V_118 ) ;
if ( V_108 )
F_62 ( V_2 -> V_25 -> V_128 ) ;
V_93 = F_48 ( V_2 , V_109 ) ;
if ( V_93 ) {
F_54 ( & V_2 -> V_33 -> V_34 , L_3 ) ;
goto V_135;
}
if ( ! F_55 ( & V_2 -> V_17 , V_105 ) ) {
F_54 ( & V_2 -> V_33 -> V_34 , L_6 ) ;
V_93 = - V_14 ;
goto V_106;
}
F_24 ( V_2 ) ;
V_93 = F_49 ( V_2 , V_109 ) ;
if ( V_93 ) {
F_54 ( & V_2 -> V_33 -> V_34 , L_5 ) ;
return V_93 ;
}
if ( V_109 )
F_63 ( V_2 -> V_25 -> V_118 -> V_129 -> V_34 ,
V_2 -> V_119 , V_110 ,
V_120 ) ;
return 0 ;
V_106:
F_24 ( V_2 ) ;
F_49 ( V_2 , V_109 ) ;
V_135:
if ( V_108 )
F_64 ( V_2 -> V_25 -> V_128 ) ;
V_132:
if ( V_109 )
F_64 ( V_2 -> V_25 -> V_118 ) ;
F_4 ( V_2 , V_16 , 0 ) ;
return V_93 ;
}
static void F_65 ( T_1 * V_136 , const T_1 * V_137 , unsigned int V_64 )
{
if ( ( unsigned long ) V_137 & 3 ) {
while ( V_64 -- ) {
* V_136 ++ = F_32 ( F_28 ( V_137 ) ) ;
V_137 ++ ;
}
} else if ( ( unsigned long ) V_136 & 3 ) {
while ( V_64 -- ) {
F_37 ( F_32 ( * V_137 ++ ) , V_136 ) ;
V_136 ++ ;
}
} else {
while ( V_64 -- )
* V_136 ++ = F_32 ( * V_137 ++ ) ;
}
}
static void F_66 ( T_1 * V_136 , const T_1 * V_137 , unsigned int V_64 )
{
if ( ( unsigned long ) V_137 & 3 ) {
while ( V_64 -- ) {
* V_136 ++ = F_67 ( F_28 ( V_137 ) ) ;
V_137 ++ ;
}
} else if ( ( unsigned long ) V_136 & 3 ) {
while ( V_64 -- ) {
F_37 ( F_67 ( * V_137 ++ ) , V_136 ) ;
V_136 ++ ;
}
} else {
while ( V_64 -- )
* V_136 ++ = F_67 ( * V_137 ++ ) ;
}
}
static void F_68 ( T_1 * V_136 , const T_1 * V_137 , unsigned int V_64 )
{
memcpy ( V_136 , V_137 , V_64 * 4 ) ;
}
static int F_69 ( struct V_90 * V_25 ,
struct V_76 * V_77 ,
struct V_138 * V_139 )
{
struct V_1 * V_2 = F_43 ( V_25 ) ;
void (* F_70)( T_1 * , const T_1 * , unsigned int );
void (* F_51)( struct V_1 * , const void * , int , int );
void (* F_52)( struct V_1 * , void * , int , int );
const void * V_61 = V_139 -> V_61 ;
void * V_62 = V_139 -> V_62 ;
unsigned int V_110 = V_139 -> V_110 ;
unsigned int V_63 = V_139 -> V_140 ;
unsigned int V_141 ;
unsigned int V_64 ;
int V_142 ;
bool V_143 ;
int V_93 ;
F_11 ( V_2 , F_71 ( V_2 -> V_144 ) , V_139 -> V_145 ) ;
while ( V_25 -> V_128 && V_110 > 15 ) {
unsigned int V_146 = 0 ;
if ( V_61 )
V_146 = F_72 ( V_110 , V_2 -> V_99 * 4 ) ;
if ( V_62 )
V_146 = F_72 ( V_110 , V_2 -> V_100 * 4 ) ;
if ( V_63 <= 8 ) {
if ( V_146 & 3 )
break;
F_70 = F_65 ;
} else if ( V_63 <= 16 ) {
if ( V_146 & 1 )
break;
F_70 = F_66 ;
} else {
F_70 = F_68 ;
}
if ( V_61 )
F_70 ( V_2 -> V_147 , V_61 , V_146 / 4 ) ;
V_93 = F_57 ( V_2 , V_61 , V_62 , V_146 ) ;
if ( V_93 == - V_123 ) {
F_73 ( L_7 ,
F_74 ( & V_2 -> V_33 -> V_34 ) ,
F_75 ( & V_2 -> V_33 -> V_34 ) ) ;
break;
}
if ( V_93 )
return V_93 ;
if ( V_62 ) {
F_70 ( V_62 , V_2 -> V_148 , V_146 / 4 ) ;
V_62 += V_146 ;
}
if ( V_61 )
V_61 += V_146 ;
V_110 -= V_146 ;
if ( ! V_110 )
return 0 ;
}
if ( V_63 <= 8 && V_110 > 15 && ! ( V_110 & 3 ) ) {
V_63 = 32 ;
V_143 = true ;
} else {
V_143 = false ;
}
if ( V_63 <= 8 ) {
V_141 = 1 ;
F_51 = F_25 ;
F_52 = F_34 ;
} else if ( V_63 <= 16 ) {
V_141 = 2 ;
if ( ( unsigned long ) V_61 & 0x01 )
F_51 = F_27 ;
else
F_51 = F_26 ;
if ( ( unsigned long ) V_62 & 0x01 )
F_52 = F_36 ;
else
F_52 = F_35 ;
} else if ( V_143 ) {
V_141 = 4 ;
if ( ( unsigned long ) V_61 & 0x03 )
F_51 = F_33 ;
else
F_51 = F_31 ;
if ( ( unsigned long ) V_62 & 0x03 )
F_52 = F_41 ;
else
F_52 = F_40 ;
} else {
V_141 = 4 ;
if ( ( unsigned long ) V_61 & 0x03 )
F_51 = F_30 ;
else
F_51 = F_29 ;
if ( ( unsigned long ) V_62 & 0x03 )
F_52 = F_39 ;
else
F_52 = F_38 ;
}
V_64 = V_110 / V_141 ;
while ( V_64 > 0 ) {
V_142 = F_50 ( V_2 , F_51 , F_52 , V_61 , V_62 ,
V_64 , V_63 ) ;
if ( V_142 < 0 )
return V_142 ;
if ( V_61 )
V_61 += V_142 * V_141 ;
if ( V_62 )
V_62 += V_142 * V_141 ;
V_64 -= V_142 ;
}
return 0 ;
}
static struct V_149 * F_76 ( struct V_129 * V_34 )
{
struct V_149 * V_30 ;
struct V_78 * V_79 = V_34 -> V_80 ;
T_1 V_150 = 1 ;
V_30 = F_77 ( V_34 , sizeof( struct V_149 ) , V_151 ) ;
if ( ! V_30 )
return NULL ;
F_78 ( V_79 , L_8 , & V_150 ) ;
F_78 ( V_79 , L_9 ,
& V_30 -> V_152 ) ;
F_78 ( V_79 , L_10 ,
& V_30 -> V_153 ) ;
F_78 ( V_79 , L_11 , & V_30 -> V_31 ) ;
F_78 ( V_79 , L_12 , & V_30 -> V_32 ) ;
V_30 -> V_154 = V_150 ;
return V_30 ;
}
static struct V_149 * F_76 ( struct V_129 * V_34 )
{
return NULL ;
}
static struct V_155 * F_79 ( struct V_129 * V_34 ,
enum V_156 V_157 , unsigned int V_158 , T_7 V_159 )
{
T_8 V_10 ;
struct V_155 * V_160 ;
struct V_161 V_162 ;
int V_93 ;
F_80 ( V_10 ) ;
F_81 ( V_163 , V_10 ) ;
V_160 = F_82 ( V_10 , V_164 ,
( void * ) ( unsigned long ) V_158 , V_34 ,
V_157 == V_165 ? L_13 : L_14 ) ;
if ( ! V_160 ) {
F_19 ( V_34 , L_15 ) ;
return NULL ;
}
memset ( & V_162 , 0 , sizeof( V_162 ) ) ;
V_162 . V_166 = V_157 ;
if ( V_157 == V_165 ) {
V_162 . V_167 = V_159 ;
V_162 . V_168 = V_169 ;
} else {
V_162 . V_170 = V_159 ;
V_162 . V_171 = V_169 ;
}
V_93 = F_83 ( V_160 , & V_162 ) ;
if ( V_93 ) {
F_19 ( V_34 , L_16 , V_93 ) ;
F_84 ( V_160 ) ;
return NULL ;
}
return V_160 ;
}
static int F_85 ( struct V_1 * V_2 )
{
struct V_172 * V_33 = V_2 -> V_33 ;
struct V_129 * V_34 = & V_33 -> V_34 ;
const struct V_149 * V_30 = F_86 ( V_34 ) ;
unsigned int V_173 , V_174 ;
const struct V_175 * V_176 ;
struct V_90 * V_25 ;
struct V_129 * V_177 , * V_178 ;
if ( V_34 -> V_80 ) {
V_173 = 0 ;
V_174 = 0 ;
} else if ( V_30 && V_30 -> V_173 && V_30 -> V_174 ) {
V_173 = V_30 -> V_173 ;
V_174 = V_30 -> V_174 ;
} else {
return 0 ;
}
V_176 = F_87 ( V_33 , V_179 , 1 ) ;
if ( ! V_176 )
V_176 = F_87 ( V_33 , V_179 , 0 ) ;
V_25 = V_2 -> V_25 ;
V_25 -> V_128 = F_79 ( V_34 , V_165 ,
V_173 ,
V_176 -> V_180 + V_72 ) ;
if ( ! V_25 -> V_128 )
return - V_181 ;
V_25 -> V_118 = F_79 ( V_34 , V_182 ,
V_174 ,
V_176 -> V_180 + V_75 ) ;
if ( ! V_25 -> V_118 )
goto V_183;
V_2 -> V_147 = ( void * ) F_88 ( V_151 | V_184 ) ;
if ( ! V_2 -> V_147 )
goto V_185;
V_2 -> V_148 = ( void * ) F_88 ( V_151 | V_184 ) ;
if ( ! V_2 -> V_148 )
goto V_186;
V_177 = V_25 -> V_128 -> V_129 -> V_34 ;
V_2 -> V_130 = F_89 ( V_177 , V_2 -> V_147 , V_187 ,
V_131 ) ;
if ( F_90 ( V_177 , V_2 -> V_130 ) )
goto V_188;
V_178 = V_25 -> V_118 -> V_129 -> V_34 ;
V_2 -> V_119 = F_89 ( V_178 , V_2 -> V_148 , V_187 ,
V_120 ) ;
if ( F_90 ( V_178 , V_2 -> V_119 ) )
goto V_189;
F_91 ( V_34 , L_17 ) ;
return 0 ;
V_189:
F_92 ( V_177 , V_2 -> V_130 , V_187 , V_131 ) ;
V_188:
F_93 ( ( unsigned long ) V_2 -> V_148 ) ;
V_186:
F_93 ( ( unsigned long ) V_2 -> V_147 ) ;
V_185:
F_84 ( V_25 -> V_118 ) ;
V_183:
F_84 ( V_25 -> V_128 ) ;
V_25 -> V_128 = NULL ;
return - V_181 ;
}
static void F_94 ( struct V_1 * V_2 )
{
struct V_90 * V_25 = V_2 -> V_25 ;
struct V_129 * V_34 ;
if ( ! V_25 -> V_128 )
return;
V_34 = & V_2 -> V_33 -> V_34 ;
F_92 ( V_25 -> V_118 -> V_129 -> V_34 , V_2 -> V_119 ,
V_187 , V_120 ) ;
F_92 ( V_25 -> V_128 -> V_129 -> V_34 , V_2 -> V_130 ,
V_187 , V_131 ) ;
F_93 ( ( unsigned long ) V_2 -> V_148 ) ;
F_93 ( ( unsigned long ) V_2 -> V_147 ) ;
F_84 ( V_25 -> V_118 ) ;
F_84 ( V_25 -> V_128 ) ;
}
static int F_95 ( struct V_172 * V_33 )
{
struct V_175 * V_190 ;
struct V_90 * V_25 ;
const struct V_191 * V_192 ;
const struct V_193 * V_194 ;
struct V_1 * V_2 ;
int V_195 ;
int V_93 ;
V_25 = F_96 ( & V_33 -> V_34 , sizeof( struct V_1 ) ) ;
if ( V_25 == NULL )
return - V_196 ;
V_2 = F_43 ( V_25 ) ;
F_97 ( V_33 , V_2 ) ;
V_2 -> V_25 = V_25 ;
V_194 = F_98 ( V_197 , & V_33 -> V_34 ) ;
if ( V_194 ) {
V_192 = V_194 -> V_11 ;
V_2 -> V_30 = F_76 ( & V_33 -> V_34 ) ;
} else {
V_192 = ( const void * ) V_33 -> V_198 -> V_199 ;
V_2 -> V_30 = F_86 ( & V_33 -> V_34 ) ;
}
if ( ! V_2 -> V_30 ) {
F_54 ( & V_33 -> V_34 , L_18 ) ;
V_93 = - V_200 ;
goto V_201;
}
F_99 ( & V_2 -> V_17 ) ;
V_2 -> V_144 = F_100 ( & V_33 -> V_34 , NULL ) ;
if ( F_101 ( V_2 -> V_144 ) ) {
F_54 ( & V_33 -> V_34 , L_19 ) ;
V_93 = F_102 ( V_2 -> V_144 ) ;
goto V_201;
}
V_195 = F_103 ( V_33 , 0 ) ;
if ( V_195 < 0 ) {
F_54 ( & V_33 -> V_34 , L_20 ) ;
V_93 = - V_202 ;
goto V_201;
}
V_190 = F_87 ( V_33 , V_179 , 0 ) ;
V_2 -> V_6 = F_104 ( & V_33 -> V_34 , V_190 ) ;
if ( F_101 ( V_2 -> V_6 ) ) {
V_93 = F_102 ( V_2 -> V_6 ) ;
goto V_201;
}
V_93 = F_105 ( & V_33 -> V_34 , V_195 , F_9 , 0 ,
F_75 ( & V_33 -> V_34 ) , V_2 ) ;
if ( V_93 ) {
F_54 ( & V_33 -> V_34 , L_21 ) ;
goto V_201;
}
V_2 -> V_33 = V_33 ;
F_106 ( & V_33 -> V_34 ) ;
V_2 -> V_99 = V_192 -> V_99 ;
V_2 -> V_100 = V_192 -> V_100 ;
if ( V_2 -> V_30 -> V_152 )
V_2 -> V_99 = V_2 -> V_30 -> V_152 ;
if ( V_2 -> V_30 -> V_153 )
V_2 -> V_100 = V_2 -> V_30 -> V_153 ;
V_25 -> V_203 = V_85 | V_86 | V_89 ;
V_25 -> V_203 |= V_88 | V_87 ;
V_25 -> V_26 = V_192 -> V_204 ;
V_25 -> V_205 = V_33 -> V_158 ;
V_25 -> V_34 . V_80 = V_33 -> V_34 . V_80 ;
V_25 -> V_154 = V_2 -> V_30 -> V_154 ;
V_25 -> V_206 = F_42 ;
V_25 -> V_207 = F_47 ;
V_25 -> V_208 = F_107 ( 8 , 32 ) ;
V_25 -> V_209 = true ;
V_25 -> V_210 = F_69 ;
V_93 = F_85 ( V_2 ) ;
if ( V_93 < 0 )
F_19 ( & V_33 -> V_34 , L_22 ) ;
V_93 = F_108 ( & V_33 -> V_34 , V_25 ) ;
if ( V_93 < 0 ) {
F_54 ( & V_33 -> V_34 , L_23 ) ;
goto V_211;
}
return 0 ;
V_211:
F_94 ( V_2 ) ;
F_109 ( & V_33 -> V_34 ) ;
V_201:
F_110 ( V_25 ) ;
return V_93 ;
}
static int F_111 ( struct V_172 * V_33 )
{
struct V_1 * V_2 = F_112 ( V_33 ) ;
F_94 ( V_2 ) ;
F_109 ( & V_33 -> V_34 ) ;
return 0 ;
}
