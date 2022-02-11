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
T_3 V_12 ;
if ( ! F_12 ( ! V_20 || ! V_19 ) )
div = F_13 ( V_19 , V_20 ) ;
for ( V_12 = 0 ; V_12 < F_14 ( V_21 ) ; V_12 ++ ) {
if ( V_21 [ V_12 ] . div >= div )
break;
}
V_12 = F_15 ( int , V_12 , F_14 ( V_21 ) - 1 ) ;
F_4 ( V_2 , V_4 , V_21 [ V_12 ] . V_22 ) ;
if ( ! ( V_2 -> V_23 -> V_24 & V_25 ) )
F_4 ( V_2 , V_5 , V_21 [ V_12 ] . V_22 ) ;
}
static void F_16 ( struct V_1 * V_2 ,
T_1 V_26 , T_1 V_27 ,
T_1 V_28 , T_1 V_29 , T_1 V_30 )
{
T_1 V_31 ;
int V_32 ;
F_4 ( V_2 , V_33 , 0 ) ;
V_31 = V_34 | 1 << V_35 | V_36 ;
V_31 |= ! V_30 << V_37 ;
V_31 |= V_29 << V_38 ;
F_4 ( V_2 , V_39 , V_31 | V_40 | V_41 ) ;
if ( V_2 -> V_23 -> V_24 & V_25 ) {
V_31 &= ~ 0x0000ffff ;
}
F_4 ( V_2 , V_42 , V_31 ) ;
V_31 = 0 ;
V_31 |= V_43 | V_26 << V_44 ;
V_31 |= V_45 | V_26 << V_46 ;
V_32 = V_26 ^ ! V_27 ;
V_31 |= V_32 << V_47 ;
V_31 |= V_32 << V_48 ;
V_31 |= V_28 ? V_49 : V_50 ;
F_4 ( V_2 , V_13 , V_31 ) ;
}
static void F_17 ( struct V_1 * V_2 ,
const void * V_51 , void * V_52 ,
T_1 V_53 , T_1 V_54 )
{
T_1 V_55 = F_18 ( V_53 ) | F_19 ( V_54 ) ;
if ( V_51 || ( V_2 -> V_23 -> V_24 & V_25 ) )
F_4 ( V_2 , V_56 , V_55 ) ;
else
F_4 ( V_2 , V_56 , V_55 | V_57 ) ;
if ( V_52 )
F_4 ( V_2 , V_58 , V_55 ) ;
F_4 ( V_2 , V_16 , V_59 | V_60 ) ;
}
static void F_20 ( struct V_1 * V_2 )
{
F_4 ( V_2 , V_61 , F_1 ( V_2 , V_61 ) ) ;
}
static void F_21 ( struct V_1 * V_2 ,
const void * V_51 , int V_54 , int V_62 )
{
const T_4 * V_63 = V_51 ;
int V_12 ;
for ( V_12 = 0 ; V_12 < V_54 ; V_12 ++ )
F_4 ( V_2 , V_64 , V_63 [ V_12 ] << V_62 ) ;
}
static void F_22 ( struct V_1 * V_2 ,
const void * V_51 , int V_54 , int V_62 )
{
const T_5 * V_65 = V_51 ;
int V_12 ;
for ( V_12 = 0 ; V_12 < V_54 ; V_12 ++ )
F_4 ( V_2 , V_64 , V_65 [ V_12 ] << V_62 ) ;
}
static void F_23 ( struct V_1 * V_2 ,
const void * V_51 , int V_54 , int V_62 )
{
const T_5 * V_65 = V_51 ;
int V_12 ;
for ( V_12 = 0 ; V_12 < V_54 ; V_12 ++ )
F_4 ( V_2 , V_64 , F_24 ( & V_65 [ V_12 ] ) << V_62 ) ;
}
static void F_25 ( struct V_1 * V_2 ,
const void * V_51 , int V_54 , int V_62 )
{
const T_1 * V_66 = V_51 ;
int V_12 ;
for ( V_12 = 0 ; V_12 < V_54 ; V_12 ++ )
F_4 ( V_2 , V_64 , V_66 [ V_12 ] << V_62 ) ;
}
static void F_26 ( struct V_1 * V_2 ,
const void * V_51 , int V_54 , int V_62 )
{
const T_1 * V_66 = V_51 ;
int V_12 ;
for ( V_12 = 0 ; V_12 < V_54 ; V_12 ++ )
F_4 ( V_2 , V_64 , F_24 ( & V_66 [ V_12 ] ) << V_62 ) ;
}
static void F_27 ( struct V_1 * V_2 ,
const void * V_51 , int V_54 , int V_62 )
{
const T_1 * V_66 = V_51 ;
int V_12 ;
for ( V_12 = 0 ; V_12 < V_54 ; V_12 ++ )
F_4 ( V_2 , V_64 , F_28 ( V_66 [ V_12 ] << V_62 ) ) ;
}
static void F_29 ( struct V_1 * V_2 ,
const void * V_51 , int V_54 , int V_62 )
{
const T_1 * V_66 = V_51 ;
int V_12 ;
for ( V_12 = 0 ; V_12 < V_54 ; V_12 ++ )
F_4 ( V_2 , V_64 , F_28 ( F_24 ( & V_66 [ V_12 ] ) << V_62 ) ) ;
}
static void F_30 ( struct V_1 * V_2 ,
void * V_52 , int V_54 , int V_62 )
{
T_4 * V_63 = V_52 ;
int V_12 ;
for ( V_12 = 0 ; V_12 < V_54 ; V_12 ++ )
V_63 [ V_12 ] = F_1 ( V_2 , V_67 ) >> V_62 ;
}
static void F_31 ( struct V_1 * V_2 ,
void * V_52 , int V_54 , int V_62 )
{
T_5 * V_65 = V_52 ;
int V_12 ;
for ( V_12 = 0 ; V_12 < V_54 ; V_12 ++ )
V_65 [ V_12 ] = F_1 ( V_2 , V_67 ) >> V_62 ;
}
static void F_32 ( struct V_1 * V_2 ,
void * V_52 , int V_54 , int V_62 )
{
T_5 * V_65 = V_52 ;
int V_12 ;
for ( V_12 = 0 ; V_12 < V_54 ; V_12 ++ )
F_33 ( F_1 ( V_2 , V_67 ) >> V_62 , & V_65 [ V_12 ] ) ;
}
static void F_34 ( struct V_1 * V_2 ,
void * V_52 , int V_54 , int V_62 )
{
T_1 * V_66 = V_52 ;
int V_12 ;
for ( V_12 = 0 ; V_12 < V_54 ; V_12 ++ )
V_66 [ V_12 ] = F_1 ( V_2 , V_67 ) >> V_62 ;
}
static void F_35 ( struct V_1 * V_2 ,
void * V_52 , int V_54 , int V_62 )
{
T_1 * V_66 = V_52 ;
int V_12 ;
for ( V_12 = 0 ; V_12 < V_54 ; V_12 ++ )
F_33 ( F_1 ( V_2 , V_67 ) >> V_62 , & V_66 [ V_12 ] ) ;
}
static void F_36 ( struct V_1 * V_2 ,
void * V_52 , int V_54 , int V_62 )
{
T_1 * V_66 = V_52 ;
int V_12 ;
for ( V_12 = 0 ; V_12 < V_54 ; V_12 ++ )
V_66 [ V_12 ] = F_28 ( F_1 ( V_2 , V_67 ) >> V_62 ) ;
}
static void F_37 ( struct V_1 * V_2 ,
void * V_52 , int V_54 , int V_62 )
{
T_1 * V_66 = V_52 ;
int V_12 ;
for ( V_12 = 0 ; V_12 < V_54 ; V_12 ++ )
F_33 ( F_28 ( F_1 ( V_2 , V_67 ) >> V_62 ) , & V_66 [ V_12 ] ) ;
}
static int F_38 ( struct V_68 * V_69 )
{
struct V_70 * V_71 = V_69 -> V_72 -> V_73 . V_74 ;
struct V_1 * V_2 = F_39 ( V_69 -> V_72 ) ;
if ( ! V_71 ) {
V_69 -> V_75 = ( V_76 ) V_69 -> V_77 ;
}
F_16 ( V_2 , ! ! ( V_69 -> V_78 & V_79 ) ,
! ! ( V_69 -> V_78 & V_80 ) ,
! ! ( V_69 -> V_78 & V_81 ) ,
! ! ( V_69 -> V_78 & V_82 ) ,
! ! ( V_69 -> V_78 & V_83 ) ) ;
if ( V_69 -> V_75 >= 0 )
F_40 ( V_69 -> V_75 , ! ( V_69 -> V_78 & V_83 ) ) ;
return 0 ;
}
static int F_41 ( struct V_84 * V_72 ,
struct V_85 * V_86 )
{
struct V_1 * V_2 = F_39 ( V_72 ) ;
const struct V_68 * V_69 = V_86 -> V_69 ;
F_16 ( V_2 , ! ! ( V_69 -> V_78 & V_79 ) ,
! ! ( V_69 -> V_78 & V_80 ) ,
! ! ( V_69 -> V_78 & V_81 ) ,
! ! ( V_69 -> V_78 & V_82 ) ,
! ! ( V_69 -> V_78 & V_83 ) ) ;
return 0 ;
}
static int F_42 ( struct V_1 * V_2 ,
void (* F_43)( struct V_1 * ,
const void * , int , int ) ,
void (* F_44)( struct V_1 * ,
void * , int , int ) ,
const void * V_51 , void * V_52 ,
int V_54 , int V_53 )
{
int V_87 ;
int V_88 ;
if ( V_51 )
V_54 = F_15 ( int , V_54 , V_2 -> V_89 ) ;
if ( V_52 )
V_54 = F_15 ( int , V_54 , V_2 -> V_90 ) ;
V_87 = 32 - V_53 ;
F_17 ( V_2 , V_51 , V_52 , V_53 , V_54 ) ;
if ( V_51 )
F_43 ( V_2 , V_51 , V_54 , V_87 ) ;
V_88 = F_7 ( V_2 , 0 , V_91 ) ;
if ( V_52 )
V_88 = V_88 ? V_88 : F_7 ( V_2 , 0 , V_92 ) ;
V_88 = V_88 ? V_88 : F_7 ( V_2 , 0 , V_93 ) ;
F_45 ( & V_2 -> V_17 ) ;
V_88 = V_88 ? V_88 : F_7 ( V_2 , 0 , V_94 ) ;
if ( V_88 ) {
F_46 ( & V_2 -> V_95 -> V_73 , L_1 ) ;
goto V_96;
}
F_47 ( & V_2 -> V_17 ) ;
if ( V_52 )
F_44 ( V_2 , V_52 , V_54 , V_87 ) ;
F_20 ( V_2 ) ;
V_88 = F_7 ( V_2 , V_94 , 0 ) ;
V_88 = V_88 ? V_88 : F_7 ( V_2 , V_93 , 0 ) ;
if ( V_52 )
V_88 = V_88 ? V_88 : F_7 ( V_2 , V_92 , 0 ) ;
V_88 = V_88 ? V_88 : F_7 ( V_2 , V_91 , 0 ) ;
if ( V_88 ) {
F_46 ( & V_2 -> V_95 -> V_73 , L_2 ) ;
goto V_96;
}
return V_54 ;
V_96:
F_4 ( V_2 , V_16 , 0 ) ;
return V_88 ;
}
static int F_48 ( struct V_84 * V_72 ,
struct V_68 * V_69 ,
struct V_97 * V_98 )
{
struct V_1 * V_2 = F_39 ( V_72 ) ;
void (* F_43)( struct V_1 * , const void * , int , int );
void (* F_44)( struct V_1 * , void * , int , int );
int V_53 ;
int V_99 ;
int V_100 ;
int V_54 ;
int V_101 ;
bool V_102 ;
V_53 = V_98 -> V_103 ;
if ( V_53 <= 8 && V_98 -> V_104 > 15 && ! ( V_98 -> V_104 & 3 ) ) {
V_53 = 32 ;
V_102 = true ;
} else {
V_102 = false ;
}
if ( V_53 <= 8 ) {
V_99 = 1 ;
F_43 = F_21 ;
F_44 = F_30 ;
} else if ( V_53 <= 16 ) {
V_99 = 2 ;
if ( ( unsigned long ) V_98 -> V_51 & 0x01 )
F_43 = F_23 ;
else
F_43 = F_22 ;
if ( ( unsigned long ) V_98 -> V_52 & 0x01 )
F_44 = F_32 ;
else
F_44 = F_31 ;
} else if ( V_102 ) {
V_99 = 4 ;
if ( ( unsigned long ) V_98 -> V_51 & 0x03 )
F_43 = F_29 ;
else
F_43 = F_27 ;
if ( ( unsigned long ) V_98 -> V_52 & 0x03 )
F_44 = F_37 ;
else
F_44 = F_36 ;
} else {
V_99 = 4 ;
if ( ( unsigned long ) V_98 -> V_51 & 0x03 )
F_43 = F_26 ;
else
F_43 = F_25 ;
if ( ( unsigned long ) V_98 -> V_52 & 0x03 )
F_44 = F_35 ;
else
F_44 = F_34 ;
}
F_11 ( V_2 , F_49 ( V_2 -> V_105 ) , V_98 -> V_106 ) ;
V_54 = V_98 -> V_104 / V_99 ;
V_100 = 0 ;
while ( V_100 < V_98 -> V_104 ) {
void * V_52 = V_98 -> V_52 ? V_98 -> V_52 + V_100 : NULL ;
const void * V_51 = V_98 -> V_51 ? V_98 -> V_51 + V_100 : NULL ;
V_101 = F_42 ( V_2 , F_43 , F_44 ,
V_51 ,
V_52 ,
V_54 , V_53 ) ;
if ( V_101 < 0 )
break;
V_100 += V_101 * V_99 ;
V_54 -= V_101 ;
}
return 0 ;
}
static struct V_107 * F_50 ( struct V_108 * V_73 )
{
struct V_107 * V_109 ;
struct V_70 * V_71 = V_73 -> V_74 ;
T_1 V_110 = 1 ;
V_109 = F_51 ( V_73 , sizeof( struct V_107 ) , V_111 ) ;
if ( ! V_109 ) {
F_46 ( V_73 , L_3 ) ;
return NULL ;
}
F_52 ( V_71 , L_4 , & V_110 ) ;
F_52 ( V_71 , L_5 ,
& V_109 -> V_112 ) ;
F_52 ( V_71 , L_6 ,
& V_109 -> V_113 ) ;
V_109 -> V_114 = V_110 ;
return V_109 ;
}
static struct V_107 * F_50 ( struct V_108 * V_73 )
{
return NULL ;
}
static int F_53 ( struct V_115 * V_95 )
{
struct V_116 * V_117 ;
struct V_84 * V_72 ;
const struct V_118 * V_119 ;
struct V_1 * V_2 ;
int V_120 ;
int V_88 ;
V_72 = F_54 ( & V_95 -> V_73 , sizeof( struct V_1 ) ) ;
if ( V_72 == NULL ) {
F_46 ( & V_95 -> V_73 , L_7 ) ;
return - V_121 ;
}
V_2 = F_39 ( V_72 ) ;
F_55 ( V_95 , V_2 ) ;
V_119 = F_56 ( V_122 , & V_95 -> V_73 ) ;
if ( V_119 ) {
V_2 -> V_23 = V_119 -> V_11 ;
V_2 -> V_109 = F_50 ( & V_95 -> V_73 ) ;
} else {
V_2 -> V_23 = ( const void * ) V_95 -> V_123 -> V_124 ;
V_2 -> V_109 = F_57 ( & V_95 -> V_73 ) ;
}
if ( ! V_2 -> V_109 ) {
F_46 ( & V_95 -> V_73 , L_8 ) ;
V_88 = - V_125 ;
goto V_126;
}
F_58 ( & V_2 -> V_17 ) ;
V_2 -> V_105 = F_59 ( & V_95 -> V_73 , NULL ) ;
if ( F_60 ( V_2 -> V_105 ) ) {
F_46 ( & V_95 -> V_73 , L_9 ) ;
V_88 = F_61 ( V_2 -> V_105 ) ;
goto V_126;
}
V_120 = F_62 ( V_95 , 0 ) ;
if ( V_120 < 0 ) {
F_46 ( & V_95 -> V_73 , L_10 ) ;
V_88 = - V_127 ;
goto V_126;
}
V_117 = F_63 ( V_95 , V_128 , 0 ) ;
V_2 -> V_6 = F_64 ( & V_95 -> V_73 , V_117 ) ;
if ( F_60 ( V_2 -> V_6 ) ) {
V_88 = F_61 ( V_2 -> V_6 ) ;
goto V_126;
}
V_88 = F_65 ( & V_95 -> V_73 , V_120 , F_9 , 0 ,
F_66 ( & V_95 -> V_73 ) , V_2 ) ;
if ( V_88 ) {
F_46 ( & V_95 -> V_73 , L_11 ) ;
goto V_126;
}
V_2 -> V_95 = V_95 ;
F_67 ( & V_95 -> V_73 ) ;
V_2 -> V_89 = V_2 -> V_23 -> V_89 ;
V_2 -> V_90 = V_2 -> V_23 -> V_90 ;
if ( V_2 -> V_109 -> V_112 )
V_2 -> V_89 = V_2 -> V_109 -> V_112 ;
if ( V_2 -> V_109 -> V_113 )
V_2 -> V_90 = V_2 -> V_109 -> V_113 ;
V_72 -> V_129 = V_79 | V_80 | V_83 ;
V_72 -> V_129 |= V_82 | V_81 ;
V_72 -> V_130 = V_2 -> V_23 -> V_24 ;
V_72 -> V_131 = V_95 -> V_132 ;
V_72 -> V_73 . V_74 = V_95 -> V_73 . V_74 ;
V_72 -> V_114 = V_2 -> V_109 -> V_114 ;
V_72 -> V_133 = F_38 ;
V_72 -> V_134 = F_41 ;
V_72 -> V_135 = F_68 ( 8 , 32 ) ;
V_72 -> V_136 = true ;
V_72 -> V_137 = F_48 ;
V_88 = F_69 ( & V_95 -> V_73 , V_72 ) ;
if ( V_88 < 0 ) {
F_46 ( & V_95 -> V_73 , L_12 ) ;
goto V_138;
}
return 0 ;
V_138:
F_70 ( & V_95 -> V_73 ) ;
V_126:
F_71 ( V_72 ) ;
return V_88 ;
}
static int F_72 ( struct V_115 * V_95 )
{
F_70 ( & V_95 -> V_73 ) ;
return 0 ;
}
