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
unsigned long V_19 ,
unsigned long V_20 )
{
unsigned long div = 1024 ;
T_3 V_12 ;
if ( ! F_12 ( ! V_20 || ! V_19 ) )
div = V_19 / V_20 ;
for ( V_12 = 0 ; V_12 < F_13 ( V_21 ) ; V_12 ++ ) {
if ( V_21 [ V_12 ] . div >= div )
break;
}
V_12 = F_14 ( int , V_12 , F_13 ( V_21 ) - 1 ) ;
F_4 ( V_2 , V_4 , V_21 [ V_12 ] . V_22 ) ;
F_4 ( V_2 , V_5 , V_21 [ V_12 ] . V_22 ) ;
}
static void F_15 ( struct V_1 * V_2 ,
T_1 V_23 , T_1 V_24 ,
T_1 V_25 , T_1 V_26 )
{
T_1 V_27 ;
int V_28 ;
F_4 ( V_2 , V_29 , 0 ) ;
F_4 ( V_2 , V_30 , 0xe2000005 | ( V_26 << 24 ) ) ;
F_4 ( V_2 , V_31 , 0x22000005 | ( V_26 << 24 ) ) ;
V_27 = 0xa0000000 ;
V_27 |= V_23 << 30 ;
V_27 |= V_23 << 28 ;
V_28 = V_23 ^ ! V_24 ;
V_27 |= V_28 << 27 ;
V_27 |= V_28 << 26 ;
V_27 |= ( V_25 ? 2 : 0 ) << 22 ;
F_4 ( V_2 , V_13 , V_27 ) ;
}
static void F_16 ( struct V_1 * V_2 ,
const void * V_32 , void * V_33 ,
T_1 V_34 , T_1 V_35 )
{
T_1 V_36 = ( ( V_34 - 1 ) << 24 ) | ( ( V_35 - 1 ) << 16 ) ;
if ( V_32 )
F_4 ( V_2 , V_37 , V_36 ) ;
else
F_4 ( V_2 , V_37 , V_36 | 1 ) ;
if ( V_33 )
F_4 ( V_2 , V_38 , V_36 ) ;
F_4 ( V_2 , V_16 , V_39 | V_40 ) ;
}
static void F_17 ( struct V_1 * V_2 )
{
F_4 ( V_2 , V_41 , F_1 ( V_2 , V_41 ) ) ;
}
static void F_18 ( struct V_1 * V_2 ,
const void * V_32 , int V_35 , int V_42 )
{
const T_4 * V_43 = V_32 ;
int V_12 ;
for ( V_12 = 0 ; V_12 < V_35 ; V_12 ++ )
F_4 ( V_2 , V_44 , V_43 [ V_12 ] << V_42 ) ;
}
static void F_19 ( struct V_1 * V_2 ,
const void * V_32 , int V_35 , int V_42 )
{
const T_5 * V_45 = V_32 ;
int V_12 ;
for ( V_12 = 0 ; V_12 < V_35 ; V_12 ++ )
F_4 ( V_2 , V_44 , V_45 [ V_12 ] << V_42 ) ;
}
static void F_20 ( struct V_1 * V_2 ,
const void * V_32 , int V_35 , int V_42 )
{
const T_5 * V_45 = V_32 ;
int V_12 ;
for ( V_12 = 0 ; V_12 < V_35 ; V_12 ++ )
F_4 ( V_2 , V_44 , F_21 ( & V_45 [ V_12 ] ) << V_42 ) ;
}
static void F_22 ( struct V_1 * V_2 ,
const void * V_32 , int V_35 , int V_42 )
{
const T_1 * V_46 = V_32 ;
int V_12 ;
for ( V_12 = 0 ; V_12 < V_35 ; V_12 ++ )
F_4 ( V_2 , V_44 , V_46 [ V_12 ] << V_42 ) ;
}
static void F_23 ( struct V_1 * V_2 ,
const void * V_32 , int V_35 , int V_42 )
{
const T_1 * V_46 = V_32 ;
int V_12 ;
for ( V_12 = 0 ; V_12 < V_35 ; V_12 ++ )
F_4 ( V_2 , V_44 , F_21 ( & V_46 [ V_12 ] ) << V_42 ) ;
}
static void F_24 ( struct V_1 * V_2 ,
const void * V_32 , int V_35 , int V_42 )
{
const T_1 * V_46 = V_32 ;
int V_12 ;
for ( V_12 = 0 ; V_12 < V_35 ; V_12 ++ )
F_4 ( V_2 , V_44 , F_25 ( V_46 [ V_12 ] << V_42 ) ) ;
}
static void F_26 ( struct V_1 * V_2 ,
const void * V_32 , int V_35 , int V_42 )
{
const T_1 * V_46 = V_32 ;
int V_12 ;
for ( V_12 = 0 ; V_12 < V_35 ; V_12 ++ )
F_4 ( V_2 , V_44 , F_25 ( F_21 ( & V_46 [ V_12 ] ) << V_42 ) ) ;
}
static void F_27 ( struct V_1 * V_2 ,
void * V_33 , int V_35 , int V_42 )
{
T_4 * V_43 = V_33 ;
int V_12 ;
for ( V_12 = 0 ; V_12 < V_35 ; V_12 ++ )
V_43 [ V_12 ] = F_1 ( V_2 , V_47 ) >> V_42 ;
}
static void F_28 ( struct V_1 * V_2 ,
void * V_33 , int V_35 , int V_42 )
{
T_5 * V_45 = V_33 ;
int V_12 ;
for ( V_12 = 0 ; V_12 < V_35 ; V_12 ++ )
V_45 [ V_12 ] = F_1 ( V_2 , V_47 ) >> V_42 ;
}
static void F_29 ( struct V_1 * V_2 ,
void * V_33 , int V_35 , int V_42 )
{
T_5 * V_45 = V_33 ;
int V_12 ;
for ( V_12 = 0 ; V_12 < V_35 ; V_12 ++ )
F_30 ( F_1 ( V_2 , V_47 ) >> V_42 , & V_45 [ V_12 ] ) ;
}
static void F_31 ( struct V_1 * V_2 ,
void * V_33 , int V_35 , int V_42 )
{
T_1 * V_46 = V_33 ;
int V_12 ;
for ( V_12 = 0 ; V_12 < V_35 ; V_12 ++ )
V_46 [ V_12 ] = F_1 ( V_2 , V_47 ) >> V_42 ;
}
static void F_32 ( struct V_1 * V_2 ,
void * V_33 , int V_35 , int V_42 )
{
T_1 * V_46 = V_33 ;
int V_12 ;
for ( V_12 = 0 ; V_12 < V_35 ; V_12 ++ )
F_30 ( F_1 ( V_2 , V_47 ) >> V_42 , & V_46 [ V_12 ] ) ;
}
static void F_33 ( struct V_1 * V_2 ,
void * V_33 , int V_35 , int V_42 )
{
T_1 * V_46 = V_33 ;
int V_12 ;
for ( V_12 = 0 ; V_12 < V_35 ; V_12 ++ )
V_46 [ V_12 ] = F_25 ( F_1 ( V_2 , V_47 ) >> V_42 ) ;
}
static void F_34 ( struct V_1 * V_2 ,
void * V_33 , int V_35 , int V_42 )
{
T_1 * V_46 = V_33 ;
int V_12 ;
for ( V_12 = 0 ; V_12 < V_35 ; V_12 ++ )
F_30 ( F_25 ( F_1 ( V_2 , V_47 ) >> V_42 ) , & V_46 [ V_12 ] ) ;
}
static int F_35 ( struct V_48 * V_49 , struct V_50 * V_51 )
{
int V_34 ;
V_34 = V_51 ? V_51 -> V_52 : 0 ;
if ( ! V_34 )
V_34 = V_49 -> V_52 ;
return V_34 ;
}
static unsigned long F_36 ( struct V_48 * V_49 ,
struct V_50 * V_51 )
{
unsigned long V_53 ;
V_53 = V_51 ? V_51 -> V_54 : 0 ;
if ( ! V_53 )
V_53 = V_49 -> V_55 ;
return V_53 ;
}
static int F_37 ( struct V_48 * V_49 ,
struct V_50 * V_51 )
{
int V_34 ;
V_34 = F_35 ( V_49 , V_51 ) ;
if ( V_34 < 8 )
return - V_56 ;
if ( V_34 > 32 )
return - V_56 ;
return F_38 ( V_49 , V_51 ) ;
}
static void F_39 ( struct V_48 * V_49 , int V_57 )
{
struct V_1 * V_2 = F_40 ( V_49 -> V_58 ) ;
int V_7 ;
if ( V_49 -> V_59 & V_60 )
V_7 = ( V_57 == V_61 ) ? 1 : 0 ;
else
V_7 = ( V_57 == V_61 ) ? 0 : 1 ;
if ( V_57 == V_61 ) {
if ( ! F_41 ( 0 , & V_2 -> V_62 ) ) {
F_42 ( & V_2 -> V_63 -> V_64 ) ;
F_43 ( V_2 -> V_65 ) ;
}
F_15 ( V_2 , ! ! ( V_49 -> V_59 & V_66 ) ,
! ! ( V_49 -> V_59 & V_67 ) ,
! ! ( V_49 -> V_59 & V_68 ) ,
! ! ( V_49 -> V_59 & V_69 ) ) ;
}
F_44 ( ( unsigned ) V_49 -> V_70 , V_7 ) ;
if ( V_57 == V_71 ) {
if ( F_45 ( 0 , & V_2 -> V_62 ) ) {
F_46 ( V_2 -> V_65 ) ;
F_47 ( & V_2 -> V_63 -> V_64 ) ;
}
}
}
static int F_48 ( struct V_1 * V_2 ,
void (* F_49)( struct V_1 * ,
const void * , int , int ) ,
void (* F_50)( struct V_1 * ,
void * , int , int ) ,
const void * V_32 , void * V_33 ,
int V_35 , int V_34 )
{
int V_72 ;
int V_73 ;
if ( V_32 )
V_35 = F_14 ( int , V_35 , V_2 -> V_74 ) ;
if ( V_33 )
V_35 = F_14 ( int , V_35 , V_2 -> V_75 ) ;
V_72 = 32 - V_34 ;
F_16 ( V_2 , V_32 , V_33 , V_34 , V_35 ) ;
if ( V_32 )
F_49 ( V_2 , V_32 , V_35 , V_72 ) ;
V_73 = F_7 ( V_2 , 0 , V_76 ) ;
if ( V_33 )
V_73 = V_73 ? V_73 : F_7 ( V_2 , 0 , V_77 ) ;
V_73 = V_73 ? V_73 : F_7 ( V_2 , 0 , V_78 ) ;
F_51 ( V_2 -> V_17 ) ;
V_73 = V_73 ? V_73 : F_7 ( V_2 , 0 , V_79 ) ;
if ( V_73 ) {
F_52 ( & V_2 -> V_63 -> V_64 , L_1 ) ;
goto V_80;
}
F_53 ( & V_2 -> V_17 ) ;
if ( V_33 )
F_50 ( V_2 , V_33 , V_35 , V_72 ) ;
F_17 ( V_2 ) ;
V_73 = F_7 ( V_2 , V_79 , 0 ) ;
V_73 = V_73 ? V_73 : F_7 ( V_2 , V_78 , 0 ) ;
if ( V_33 )
V_73 = V_73 ? V_73 : F_7 ( V_2 , V_77 , 0 ) ;
V_73 = V_73 ? V_73 : F_7 ( V_2 , V_76 , 0 ) ;
if ( V_73 ) {
F_52 ( & V_2 -> V_63 -> V_64 , L_2 ) ;
goto V_80;
}
return V_35 ;
V_80:
F_4 ( V_2 , V_16 , 0 ) ;
return V_73 ;
}
static int F_54 ( struct V_48 * V_49 , struct V_50 * V_51 )
{
struct V_1 * V_2 = F_40 ( V_49 -> V_58 ) ;
void (* F_49)( struct V_1 * , const void * , int , int );
void (* F_50)( struct V_1 * , void * , int , int );
int V_34 ;
int V_81 ;
int V_82 ;
int V_35 ;
int V_83 ;
bool V_84 ;
V_34 = F_35 ( V_49 , V_51 ) ;
if ( V_34 <= 8 && V_51 -> V_85 > 15 && ! ( V_51 -> V_85 & 3 ) ) {
V_34 = 32 ;
V_84 = true ;
} else {
V_84 = false ;
}
if ( V_34 <= 8 ) {
V_81 = 1 ;
F_49 = F_18 ;
F_50 = F_27 ;
} else if ( V_34 <= 16 ) {
V_81 = 2 ;
if ( ( unsigned long ) V_51 -> V_32 & 0x01 )
F_49 = F_20 ;
else
F_49 = F_19 ;
if ( ( unsigned long ) V_51 -> V_33 & 0x01 )
F_50 = F_29 ;
else
F_50 = F_28 ;
} else if ( V_84 ) {
V_81 = 4 ;
if ( ( unsigned long ) V_51 -> V_32 & 0x03 )
F_49 = F_26 ;
else
F_49 = F_24 ;
if ( ( unsigned long ) V_51 -> V_33 & 0x03 )
F_50 = F_34 ;
else
F_50 = F_33 ;
} else {
V_81 = 4 ;
if ( ( unsigned long ) V_51 -> V_32 & 0x03 )
F_49 = F_23 ;
else
F_49 = F_22 ;
if ( ( unsigned long ) V_51 -> V_33 & 0x03 )
F_50 = F_32 ;
else
F_50 = F_31 ;
}
F_11 ( V_2 , F_55 ( V_2 -> V_65 ) ,
F_36 ( V_49 , V_51 ) ) ;
V_35 = V_51 -> V_85 / V_81 ;
V_82 = 0 ;
while ( V_82 < V_51 -> V_85 ) {
void * V_33 = V_51 -> V_33 ? V_51 -> V_33 + V_82 : NULL ;
const void * V_32 = V_51 -> V_32 ? V_51 -> V_32 + V_82 : NULL ;
V_83 = F_48 ( V_2 , F_49 , F_50 ,
V_32 ,
V_33 ,
V_35 , V_34 ) ;
if ( V_83 < 0 )
break;
V_82 += V_83 * V_81 ;
V_35 -= V_83 ;
}
return V_82 ;
}
static T_1 F_56 ( struct V_48 * V_49 , unsigned V_86 ,
T_1 V_87 , T_4 V_34 )
{
F_57 () ;
return 0 ;
}
static int F_58 ( struct V_88 * V_63 )
{
struct V_89 * V_90 ;
struct V_91 * V_58 ;
struct V_1 * V_2 ;
char V_92 [ 16 ] ;
int V_93 ;
int V_73 ;
V_58 = F_59 ( & V_63 -> V_64 , sizeof( struct V_1 ) ) ;
if ( V_58 == NULL ) {
F_52 ( & V_63 -> V_64 , L_3 ) ;
V_73 = - V_94 ;
goto V_95;
}
V_2 = F_40 ( V_58 ) ;
F_60 ( V_63 , V_2 ) ;
V_2 -> V_96 = V_63 -> V_64 . V_97 ;
F_61 ( & V_2 -> V_17 ) ;
snprintf ( V_92 , sizeof( V_92 ) , L_4 , V_63 -> V_98 ) ;
V_2 -> V_65 = F_62 ( & V_63 -> V_64 , V_92 ) ;
if ( F_63 ( V_2 -> V_65 ) ) {
F_52 ( & V_63 -> V_64 , L_5 , V_92 ) ;
V_73 = F_64 ( V_2 -> V_65 ) ;
goto V_99;
}
V_90 = F_65 ( V_63 , V_100 , 0 ) ;
V_93 = F_66 ( V_63 , 0 ) ;
if ( ! V_90 || V_93 < 0 ) {
F_52 ( & V_63 -> V_64 , L_6 ) ;
V_73 = - V_101 ;
goto V_102;
}
V_2 -> V_6 = F_67 ( V_90 -> V_103 , F_68 ( V_90 ) ) ;
if ( ! V_2 -> V_6 ) {
F_52 ( & V_63 -> V_64 , L_7 ) ;
V_73 = - V_104 ;
goto V_102;
}
V_73 = F_69 ( V_93 , F_9 , V_105 ,
F_70 ( & V_63 -> V_64 ) , V_2 ) ;
if ( V_73 ) {
F_52 ( & V_63 -> V_64 , L_8 ) ;
goto V_106;
}
V_2 -> V_63 = V_63 ;
F_71 ( & V_63 -> V_64 ) ;
V_2 -> V_74 = 64 ;
V_2 -> V_75 = 64 ;
if ( V_2 -> V_96 -> V_107 )
V_2 -> V_74 = V_2 -> V_96 -> V_107 ;
if ( V_2 -> V_96 -> V_108 )
V_2 -> V_75 = V_2 -> V_96 -> V_108 ;
V_58 -> V_109 = V_66 | V_67 | V_60 ;
V_58 -> V_109 |= V_69 | V_68 ;
V_58 -> V_62 = 0 ;
V_58 -> V_110 = V_63 -> V_98 ;
V_58 -> V_111 = V_2 -> V_96 -> V_111 ;
V_58 -> V_112 = V_113 ;
V_58 -> V_114 = V_115 ;
V_2 -> V_116 . V_58 = V_58 ;
V_2 -> V_116 . V_117 = F_39 ;
V_2 -> V_116 . V_118 = F_37 ;
V_2 -> V_116 . V_119 = F_54 ;
V_2 -> V_116 . V_120 [ V_121 ] = F_56 ;
V_2 -> V_116 . V_120 [ V_122 ] = F_56 ;
V_2 -> V_116 . V_120 [ V_123 ] = F_56 ;
V_2 -> V_116 . V_120 [ V_124 ] = F_56 ;
V_73 = F_72 ( & V_2 -> V_116 ) ;
if ( V_73 == 0 )
return 0 ;
F_73 ( & V_63 -> V_64 ) ;
V_106:
F_74 ( V_2 -> V_6 ) ;
V_102:
F_75 ( V_2 -> V_65 ) ;
V_99:
F_76 ( V_58 ) ;
V_95:
return V_73 ;
}
static int F_77 ( struct V_88 * V_63 )
{
struct V_1 * V_2 = F_78 ( V_63 ) ;
int V_73 ;
V_73 = F_79 ( & V_2 -> V_116 ) ;
if ( ! V_73 ) {
F_73 ( & V_63 -> V_64 ) ;
F_80 ( F_66 ( V_63 , 0 ) , V_2 ) ;
F_74 ( V_2 -> V_6 ) ;
F_75 ( V_2 -> V_65 ) ;
F_76 ( V_2 -> V_116 . V_58 ) ;
}
return V_73 ;
}
static int F_81 ( struct V_125 * V_64 )
{
return 0 ;
}
static int T_6 F_82 ( void )
{
return F_83 ( & V_126 ) ;
}
static void T_7 F_84 ( void )
{
F_85 ( & V_126 ) ;
}
