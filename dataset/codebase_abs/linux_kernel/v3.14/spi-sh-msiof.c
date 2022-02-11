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
div = F_13 ( V_19 , V_20 ) ;
for ( V_12 = 0 ; V_12 < F_14 ( V_21 ) ; V_12 ++ ) {
if ( V_21 [ V_12 ] . div >= div )
break;
}
V_12 = F_15 ( int , V_12 , F_14 ( V_21 ) - 1 ) ;
F_4 ( V_2 , V_4 , V_21 [ V_12 ] . V_22 ) ;
F_4 ( V_2 , V_5 , V_21 [ V_12 ] . V_22 ) ;
}
static void F_16 ( struct V_1 * V_2 ,
T_1 V_23 , T_1 V_24 ,
T_1 V_25 , T_1 V_26 , T_1 V_27 )
{
T_1 V_28 ;
int V_29 ;
F_4 ( V_2 , V_30 , 0 ) ;
V_28 = 0 ;
V_28 |= ! V_27 << 25 ;
V_28 |= V_26 << 24 ;
F_4 ( V_2 , V_31 , 0xe0000005 | V_28 ) ;
F_4 ( V_2 , V_32 , 0x20000005 | V_28 ) ;
V_28 = 0xa0000000 ;
V_28 |= V_23 << 30 ;
V_28 |= V_23 << 28 ;
V_29 = V_23 ^ ! V_24 ;
V_28 |= V_29 << 27 ;
V_28 |= V_29 << 26 ;
V_28 |= ( V_25 ? 2 : 0 ) << 22 ;
F_4 ( V_2 , V_13 , V_28 ) ;
}
static void F_17 ( struct V_1 * V_2 ,
const void * V_33 , void * V_34 ,
T_1 V_35 , T_1 V_36 )
{
T_1 V_37 = ( ( V_35 - 1 ) << 24 ) | ( ( V_36 - 1 ) << 16 ) ;
if ( V_33 )
F_4 ( V_2 , V_38 , V_37 ) ;
else
F_4 ( V_2 , V_38 , V_37 | 1 ) ;
if ( V_34 )
F_4 ( V_2 , V_39 , V_37 ) ;
F_4 ( V_2 , V_16 , V_40 | V_41 ) ;
}
static void F_18 ( struct V_1 * V_2 )
{
F_4 ( V_2 , V_42 , F_1 ( V_2 , V_42 ) ) ;
}
static void F_19 ( struct V_1 * V_2 ,
const void * V_33 , int V_36 , int V_43 )
{
const T_4 * V_44 = V_33 ;
int V_12 ;
for ( V_12 = 0 ; V_12 < V_36 ; V_12 ++ )
F_4 ( V_2 , V_45 , V_44 [ V_12 ] << V_43 ) ;
}
static void F_20 ( struct V_1 * V_2 ,
const void * V_33 , int V_36 , int V_43 )
{
const T_5 * V_46 = V_33 ;
int V_12 ;
for ( V_12 = 0 ; V_12 < V_36 ; V_12 ++ )
F_4 ( V_2 , V_45 , V_46 [ V_12 ] << V_43 ) ;
}
static void F_21 ( struct V_1 * V_2 ,
const void * V_33 , int V_36 , int V_43 )
{
const T_5 * V_46 = V_33 ;
int V_12 ;
for ( V_12 = 0 ; V_12 < V_36 ; V_12 ++ )
F_4 ( V_2 , V_45 , F_22 ( & V_46 [ V_12 ] ) << V_43 ) ;
}
static void F_23 ( struct V_1 * V_2 ,
const void * V_33 , int V_36 , int V_43 )
{
const T_1 * V_47 = V_33 ;
int V_12 ;
for ( V_12 = 0 ; V_12 < V_36 ; V_12 ++ )
F_4 ( V_2 , V_45 , V_47 [ V_12 ] << V_43 ) ;
}
static void F_24 ( struct V_1 * V_2 ,
const void * V_33 , int V_36 , int V_43 )
{
const T_1 * V_47 = V_33 ;
int V_12 ;
for ( V_12 = 0 ; V_12 < V_36 ; V_12 ++ )
F_4 ( V_2 , V_45 , F_22 ( & V_47 [ V_12 ] ) << V_43 ) ;
}
static void F_25 ( struct V_1 * V_2 ,
const void * V_33 , int V_36 , int V_43 )
{
const T_1 * V_47 = V_33 ;
int V_12 ;
for ( V_12 = 0 ; V_12 < V_36 ; V_12 ++ )
F_4 ( V_2 , V_45 , F_26 ( V_47 [ V_12 ] << V_43 ) ) ;
}
static void F_27 ( struct V_1 * V_2 ,
const void * V_33 , int V_36 , int V_43 )
{
const T_1 * V_47 = V_33 ;
int V_12 ;
for ( V_12 = 0 ; V_12 < V_36 ; V_12 ++ )
F_4 ( V_2 , V_45 , F_26 ( F_22 ( & V_47 [ V_12 ] ) << V_43 ) ) ;
}
static void F_28 ( struct V_1 * V_2 ,
void * V_34 , int V_36 , int V_43 )
{
T_4 * V_44 = V_34 ;
int V_12 ;
for ( V_12 = 0 ; V_12 < V_36 ; V_12 ++ )
V_44 [ V_12 ] = F_1 ( V_2 , V_48 ) >> V_43 ;
}
static void F_29 ( struct V_1 * V_2 ,
void * V_34 , int V_36 , int V_43 )
{
T_5 * V_46 = V_34 ;
int V_12 ;
for ( V_12 = 0 ; V_12 < V_36 ; V_12 ++ )
V_46 [ V_12 ] = F_1 ( V_2 , V_48 ) >> V_43 ;
}
static void F_30 ( struct V_1 * V_2 ,
void * V_34 , int V_36 , int V_43 )
{
T_5 * V_46 = V_34 ;
int V_12 ;
for ( V_12 = 0 ; V_12 < V_36 ; V_12 ++ )
F_31 ( F_1 ( V_2 , V_48 ) >> V_43 , & V_46 [ V_12 ] ) ;
}
static void F_32 ( struct V_1 * V_2 ,
void * V_34 , int V_36 , int V_43 )
{
T_1 * V_47 = V_34 ;
int V_12 ;
for ( V_12 = 0 ; V_12 < V_36 ; V_12 ++ )
V_47 [ V_12 ] = F_1 ( V_2 , V_48 ) >> V_43 ;
}
static void F_33 ( struct V_1 * V_2 ,
void * V_34 , int V_36 , int V_43 )
{
T_1 * V_47 = V_34 ;
int V_12 ;
for ( V_12 = 0 ; V_12 < V_36 ; V_12 ++ )
F_31 ( F_1 ( V_2 , V_48 ) >> V_43 , & V_47 [ V_12 ] ) ;
}
static void F_34 ( struct V_1 * V_2 ,
void * V_34 , int V_36 , int V_43 )
{
T_1 * V_47 = V_34 ;
int V_12 ;
for ( V_12 = 0 ; V_12 < V_36 ; V_12 ++ )
V_47 [ V_12 ] = F_26 ( F_1 ( V_2 , V_48 ) >> V_43 ) ;
}
static void F_35 ( struct V_1 * V_2 ,
void * V_34 , int V_36 , int V_43 )
{
T_1 * V_47 = V_34 ;
int V_12 ;
for ( V_12 = 0 ; V_12 < V_36 ; V_12 ++ )
F_31 ( F_26 ( F_1 ( V_2 , V_48 ) >> V_43 ) , & V_47 [ V_12 ] ) ;
}
static int F_36 ( struct V_49 * V_50 , struct V_51 * V_52 )
{
int V_35 ;
V_35 = V_52 ? V_52 -> V_53 : 0 ;
if ( ! V_35 )
V_35 = V_50 -> V_53 ;
return V_35 ;
}
static unsigned long F_37 ( struct V_49 * V_50 ,
struct V_51 * V_52 )
{
unsigned long V_54 ;
V_54 = V_52 ? V_52 -> V_55 : 0 ;
if ( ! V_54 )
V_54 = V_50 -> V_56 ;
return V_54 ;
}
static int F_38 ( struct V_49 * V_50 ,
struct V_51 * V_52 )
{
int V_35 ;
V_35 = F_36 ( V_50 , V_52 ) ;
if ( V_35 < 8 )
return - V_57 ;
if ( V_35 > 32 )
return - V_57 ;
return F_39 ( V_50 , V_52 ) ;
}
static void F_40 ( struct V_49 * V_50 , int V_58 )
{
struct V_1 * V_2 = F_41 ( V_50 -> V_59 ) ;
int V_7 ;
if ( V_50 -> V_60 & V_61 )
V_7 = ( V_58 == V_62 ) ? 1 : 0 ;
else
V_7 = ( V_58 == V_62 ) ? 0 : 1 ;
if ( V_58 == V_62 ) {
if ( ! F_42 ( 0 , & V_2 -> V_63 ) ) {
F_43 ( & V_2 -> V_64 -> V_65 ) ;
F_44 ( V_2 -> V_66 ) ;
}
F_16 ( V_2 , ! ! ( V_50 -> V_60 & V_67 ) ,
! ! ( V_50 -> V_60 & V_68 ) ,
! ! ( V_50 -> V_60 & V_69 ) ,
! ! ( V_50 -> V_60 & V_70 ) ,
! ! ( V_50 -> V_60 & V_61 ) ) ;
}
F_45 ( ( V_71 ) V_50 -> V_72 , V_7 ) ;
if ( V_58 == V_73 ) {
if ( F_46 ( 0 , & V_2 -> V_63 ) ) {
F_47 ( V_2 -> V_66 ) ;
F_48 ( & V_2 -> V_64 -> V_65 ) ;
}
}
}
static int F_49 ( struct V_1 * V_2 ,
void (* F_50)( struct V_1 * ,
const void * , int , int ) ,
void (* F_51)( struct V_1 * ,
void * , int , int ) ,
const void * V_33 , void * V_34 ,
int V_36 , int V_35 )
{
int V_74 ;
int V_75 ;
if ( V_33 )
V_36 = F_15 ( int , V_36 , V_2 -> V_76 ) ;
if ( V_34 )
V_36 = F_15 ( int , V_36 , V_2 -> V_77 ) ;
V_74 = 32 - V_35 ;
F_17 ( V_2 , V_33 , V_34 , V_35 , V_36 ) ;
if ( V_33 )
F_50 ( V_2 , V_33 , V_36 , V_74 ) ;
V_75 = F_7 ( V_2 , 0 , V_78 ) ;
if ( V_34 )
V_75 = V_75 ? V_75 : F_7 ( V_2 , 0 , V_79 ) ;
V_75 = V_75 ? V_75 : F_7 ( V_2 , 0 , V_80 ) ;
F_52 ( & V_2 -> V_17 ) ;
V_75 = V_75 ? V_75 : F_7 ( V_2 , 0 , V_81 ) ;
if ( V_75 ) {
F_53 ( & V_2 -> V_64 -> V_65 , L_1 ) ;
goto V_82;
}
F_54 ( & V_2 -> V_17 ) ;
if ( V_34 )
F_51 ( V_2 , V_34 , V_36 , V_74 ) ;
F_18 ( V_2 ) ;
V_75 = F_7 ( V_2 , V_81 , 0 ) ;
V_75 = V_75 ? V_75 : F_7 ( V_2 , V_80 , 0 ) ;
if ( V_34 )
V_75 = V_75 ? V_75 : F_7 ( V_2 , V_79 , 0 ) ;
V_75 = V_75 ? V_75 : F_7 ( V_2 , V_78 , 0 ) ;
if ( V_75 ) {
F_53 ( & V_2 -> V_64 -> V_65 , L_2 ) ;
goto V_82;
}
return V_36 ;
V_82:
F_4 ( V_2 , V_16 , 0 ) ;
return V_75 ;
}
static int F_55 ( struct V_49 * V_50 , struct V_51 * V_52 )
{
struct V_1 * V_2 = F_41 ( V_50 -> V_59 ) ;
void (* F_50)( struct V_1 * , const void * , int , int );
void (* F_51)( struct V_1 * , void * , int , int );
int V_35 ;
int V_83 ;
int V_84 ;
int V_36 ;
int V_85 ;
bool V_86 ;
V_35 = F_36 ( V_50 , V_52 ) ;
if ( V_35 <= 8 && V_52 -> V_87 > 15 && ! ( V_52 -> V_87 & 3 ) ) {
V_35 = 32 ;
V_86 = true ;
} else {
V_86 = false ;
}
if ( V_35 <= 8 ) {
V_83 = 1 ;
F_50 = F_19 ;
F_51 = F_28 ;
} else if ( V_35 <= 16 ) {
V_83 = 2 ;
if ( ( unsigned long ) V_52 -> V_33 & 0x01 )
F_50 = F_21 ;
else
F_50 = F_20 ;
if ( ( unsigned long ) V_52 -> V_34 & 0x01 )
F_51 = F_30 ;
else
F_51 = F_29 ;
} else if ( V_86 ) {
V_83 = 4 ;
if ( ( unsigned long ) V_52 -> V_33 & 0x03 )
F_50 = F_27 ;
else
F_50 = F_25 ;
if ( ( unsigned long ) V_52 -> V_34 & 0x03 )
F_51 = F_35 ;
else
F_51 = F_34 ;
} else {
V_83 = 4 ;
if ( ( unsigned long ) V_52 -> V_33 & 0x03 )
F_50 = F_24 ;
else
F_50 = F_23 ;
if ( ( unsigned long ) V_52 -> V_34 & 0x03 )
F_51 = F_33 ;
else
F_51 = F_32 ;
}
F_11 ( V_2 , F_56 ( V_2 -> V_66 ) ,
F_37 ( V_50 , V_52 ) ) ;
V_36 = V_52 -> V_87 / V_83 ;
V_84 = 0 ;
while ( V_84 < V_52 -> V_87 ) {
void * V_34 = V_52 -> V_34 ? V_52 -> V_34 + V_84 : NULL ;
const void * V_33 = V_52 -> V_33 ? V_52 -> V_33 + V_84 : NULL ;
V_85 = F_49 ( V_2 , F_50 , F_51 ,
V_33 ,
V_34 ,
V_36 , V_35 ) ;
if ( V_85 < 0 )
break;
V_84 += V_85 * V_83 ;
V_36 -= V_85 ;
}
return V_84 ;
}
static T_1 F_57 ( struct V_49 * V_50 , unsigned V_88 ,
T_1 V_89 , T_4 V_35 )
{
F_58 () ;
return 0 ;
}
static struct V_90 * F_59 ( struct V_91 * V_65 )
{
struct V_90 * V_92 ;
struct V_93 * V_94 = V_65 -> V_95 ;
T_1 V_96 = 0 ;
V_92 = F_60 ( V_65 , sizeof( struct V_90 ) , V_97 ) ;
if ( ! V_92 ) {
F_53 ( V_65 , L_3 ) ;
return NULL ;
}
F_61 ( V_94 , L_4 , & V_96 ) ;
F_61 ( V_94 , L_5 ,
& V_92 -> V_98 ) ;
F_61 ( V_94 , L_6 ,
& V_92 -> V_99 ) ;
V_92 -> V_100 = V_96 ;
return V_92 ;
}
static struct V_90 * F_59 ( struct V_91 * V_65 )
{
return NULL ;
}
static int F_62 ( struct V_101 * V_64 )
{
struct V_102 * V_103 ;
struct V_104 * V_59 ;
struct V_1 * V_2 ;
int V_105 ;
int V_75 ;
V_59 = F_63 ( & V_64 -> V_65 , sizeof( struct V_1 ) ) ;
if ( V_59 == NULL ) {
F_53 ( & V_64 -> V_65 , L_7 ) ;
return - V_106 ;
}
V_2 = F_41 ( V_59 ) ;
F_64 ( V_64 , V_2 ) ;
if ( V_64 -> V_65 . V_95 )
V_2 -> V_92 = F_59 ( & V_64 -> V_65 ) ;
else
V_2 -> V_92 = F_65 ( & V_64 -> V_65 ) ;
if ( ! V_2 -> V_92 ) {
F_53 ( & V_64 -> V_65 , L_8 ) ;
V_75 = - V_107 ;
goto V_108;
}
F_66 ( & V_2 -> V_17 ) ;
V_2 -> V_66 = F_67 ( & V_64 -> V_65 , NULL ) ;
if ( F_68 ( V_2 -> V_66 ) ) {
F_53 ( & V_64 -> V_65 , L_9 ) ;
V_75 = F_69 ( V_2 -> V_66 ) ;
goto V_108;
}
V_105 = F_70 ( V_64 , 0 ) ;
if ( V_105 < 0 ) {
F_53 ( & V_64 -> V_65 , L_10 ) ;
V_75 = - V_109 ;
goto V_108;
}
V_103 = F_71 ( V_64 , V_110 , 0 ) ;
V_2 -> V_6 = F_72 ( & V_64 -> V_65 , V_103 ) ;
if ( F_68 ( V_2 -> V_6 ) ) {
V_75 = F_69 ( V_2 -> V_6 ) ;
goto V_108;
}
V_75 = F_73 ( & V_64 -> V_65 , V_105 , F_9 , 0 ,
F_74 ( & V_64 -> V_65 ) , V_2 ) ;
if ( V_75 ) {
F_53 ( & V_64 -> V_65 , L_11 ) ;
goto V_108;
}
V_75 = F_75 ( V_2 -> V_66 ) ;
if ( V_75 < 0 ) {
F_53 ( & V_64 -> V_65 , L_12 ) ;
goto V_108;
}
V_2 -> V_64 = V_64 ;
F_76 ( & V_64 -> V_65 ) ;
V_2 -> V_76 = 64 ;
V_2 -> V_77 = 64 ;
if ( V_2 -> V_92 -> V_98 )
V_2 -> V_76 = V_2 -> V_92 -> V_98 ;
if ( V_2 -> V_92 -> V_99 )
V_2 -> V_77 = V_2 -> V_92 -> V_99 ;
V_59 -> V_111 = V_67 | V_68 | V_61 ;
V_59 -> V_111 |= V_70 | V_69 ;
V_59 -> V_63 = 0 ;
V_59 -> V_112 = V_64 -> V_113 ;
V_59 -> V_100 = V_2 -> V_92 -> V_100 ;
V_59 -> V_114 = V_115 ;
V_59 -> V_116 = V_117 ;
V_2 -> V_118 . V_59 = V_59 ;
V_2 -> V_118 . V_119 = F_40 ;
V_2 -> V_118 . V_120 = F_38 ;
V_2 -> V_118 . V_121 = F_55 ;
V_2 -> V_118 . V_122 [ V_123 ] = F_57 ;
V_2 -> V_118 . V_122 [ V_124 ] = F_57 ;
V_2 -> V_118 . V_122 [ V_125 ] = F_57 ;
V_2 -> V_118 . V_122 [ V_126 ] = F_57 ;
V_75 = F_77 ( & V_2 -> V_118 ) ;
if ( V_75 == 0 )
return 0 ;
F_78 ( & V_64 -> V_65 ) ;
F_79 ( V_2 -> V_66 ) ;
V_108:
F_80 ( V_59 ) ;
return V_75 ;
}
static int F_81 ( struct V_101 * V_64 )
{
struct V_1 * V_2 = F_82 ( V_64 ) ;
int V_75 ;
V_75 = F_83 ( & V_2 -> V_118 ) ;
if ( ! V_75 ) {
F_78 ( & V_64 -> V_65 ) ;
F_79 ( V_2 -> V_66 ) ;
F_80 ( V_2 -> V_118 . V_59 ) ;
}
return V_75 ;
}
