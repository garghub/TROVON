const struct V_1 * F_1 ( void )
{
return & V_2 ;
}
static bool F_2 ( struct V_3 * V_4 ,
const int V_5 )
{
return V_4 -> V_6 -> V_7 ( V_5 ) != V_8 ;
}
static void F_3 ( struct V_3 * V_4 ,
int V_5 , int * V_9 , T_1 * V_10 ,
T_2 * V_11 , T_3 * V_12 , T_3 * V_13 ,
T_1 * V_14 )
{
void T_4 * V_15 = V_4 -> V_16 +
V_4 -> V_6 -> V_17 ( V_5 ) ;
T_2 V_18 = F_4 ( V_15 + V_19 ) ;
T_2 V_20 = F_4 ( V_15 + V_21 ) ;
if ( ! ( V_20 & V_22 ) ) {
* V_9 = 0 ;
return;
}
* V_9 = 1 ;
* V_10 = ( ( T_1 ) V_18 & V_23 ) << 32 ;
* V_10 |= ( V_18 & V_24 ) ;
* V_11 = ( V_20 | ~ V_25 ) + 1 ;
if ( V_12 )
* V_12 = ( V_20 & V_26 ) >> V_27 ;
if ( V_13 )
* V_13 = ( V_20 & V_28 ) >> V_29 ;
if ( V_14 ) {
if ( F_2 ( V_4 , V_5 ) ) {
T_2 V_30 , V_31 ;
void T_4 * V_32 = V_4 -> V_16 +
V_4 -> V_6 -> V_7 ( V_5 ) ;
V_30 = F_4 ( V_32 + V_33 ) ;
V_31 = F_4 ( V_32 + V_34 ) ;
* V_14 = ( ( T_1 ) V_31 << 32 ) | V_30 ;
} else
* V_14 = 0 ;
}
}
static void F_5 ( struct V_3 * V_4 ,
int V_5 )
{
void T_4 * V_15 ;
V_15 = V_4 -> V_16 + V_4 -> V_6 -> V_17 ( V_5 ) ;
F_6 ( 0 , V_15 + V_19 ) ;
F_6 ( 0 , V_15 + V_21 ) ;
if ( F_2 ( V_4 , V_5 ) ) {
V_15 = V_4 -> V_16 + V_4 -> V_6 -> V_7 ( V_5 ) ;
F_6 ( 0 , V_15 + V_33 ) ;
F_6 ( 0 , V_15 + V_34 ) ;
}
}
static int F_7 ( struct V_3 * V_4 ,
const int V_5 )
{
void T_4 * V_15 = V_4 -> V_16 +
V_4 -> V_6 -> V_17 ( V_5 ) ;
T_2 V_35 = F_4 ( V_15 + V_21 ) ;
return ! ( V_35 & V_22 ) ;
}
static int F_8 ( struct V_3 * V_4 ,
T_5 V_10 , T_6 V_11 ,
T_3 V_12 , T_3 V_13 )
{
T_1 V_36 = ( T_1 ) V_10 + V_11 ;
int V_5 ;
for ( V_5 = 0 ; V_5 < V_4 -> V_6 -> V_37 ; V_5 ++ ) {
T_1 V_38 , V_39 ;
T_2 V_40 ;
T_3 V_41 , V_42 ;
int V_9 ;
F_3 ( V_4 , V_5 ,
& V_9 , & V_38 , & V_40 ,
& V_41 , & V_42 , NULL ) ;
if ( ! V_9 )
continue;
V_39 = V_38 + V_40 ;
if ( ( T_1 ) V_10 < V_39 && V_36 > V_38 )
return 0 ;
}
return 1 ;
}
static int F_9 ( struct V_3 * V_4 ,
T_5 V_10 , T_6 V_11 )
{
int V_5 ;
for ( V_5 = 0 ; V_5 < V_4 -> V_6 -> V_37 ; V_5 ++ ) {
T_1 V_38 ;
T_2 V_40 ;
int V_9 ;
F_3 ( V_4 , V_5 ,
& V_9 , & V_38 , & V_40 ,
NULL , NULL , NULL ) ;
if ( ! V_9 )
continue;
if ( V_10 == V_38 && V_11 == V_40 )
return V_5 ;
}
return - V_43 ;
}
static int F_10 ( struct V_3 * V_4 ,
int V_5 , T_5 V_10 , T_6 V_11 ,
T_5 V_14 , T_3 V_12 ,
T_3 V_13 )
{
void T_4 * V_15 = V_4 -> V_16 +
V_4 -> V_6 -> V_17 ( V_5 ) ;
T_2 V_35 , V_44 ;
if ( ! F_11 ( V_11 ) ) {
F_12 ( true , L_1 , V_11 ) ;
return - V_45 ;
}
if ( ( V_10 & ( T_5 ) ( V_11 - 1 ) ) != 0 ) {
F_12 ( true , L_2 , & V_10 ,
V_11 ) ;
return - V_45 ;
}
V_35 = ( ( V_11 - 1 ) & V_25 ) |
( V_13 << V_29 ) |
( V_12 << V_27 ) |
V_46 |
V_22 ;
F_6 ( V_10 & V_24 , V_15 + V_19 ) ;
F_6 ( V_35 , V_15 + V_21 ) ;
if ( F_2 ( V_4 , V_5 ) ) {
void T_4 * V_32 = V_4 -> V_16 +
V_4 -> V_6 -> V_7 ( V_5 ) ;
if ( V_14 == V_8 )
V_44 = V_10 ;
else
V_44 = V_14 ;
F_6 ( V_44 & V_47 , V_32 + V_33 ) ;
F_6 ( 0 , V_32 + V_34 ) ;
}
return 0 ;
}
static int F_13 ( struct V_3 * V_4 ,
T_5 V_10 , T_6 V_11 ,
T_5 V_14 , T_3 V_12 ,
T_3 V_13 )
{
int V_5 ;
if ( V_14 == V_8 ) {
for ( V_5 = 0 ; V_5 < V_4 -> V_6 -> V_37 ; V_5 ++ ) {
if ( F_2 ( V_4 , V_5 ) )
continue;
if ( F_7 ( V_4 , V_5 ) )
return F_10 ( V_4 , V_5 , V_10 ,
V_11 , V_14 ,
V_12 , V_13 ) ;
}
}
for ( V_5 = 0 ; V_5 < V_4 -> V_6 -> V_37 ; V_5 ++ ) {
if ( ( V_14 != V_8 ) &&
! F_2 ( V_4 , V_5 ) )
continue;
if ( F_7 ( V_4 , V_5 ) )
return F_10 ( V_4 , V_5 , V_10 , V_11 ,
V_14 , V_12 , V_13 ) ;
}
return - V_48 ;
}
static int F_14 ( struct V_3 * V_4 ,
struct V_49 * V_50 , void * V_51 )
{
int V_52 ;
for ( V_52 = 0 ; V_52 < 4 ; V_52 ++ ) {
T_2 V_18 = F_4 ( V_4 -> V_53 + F_15 ( V_52 ) ) ;
T_2 V_54 = F_4 ( V_4 -> V_53 + F_16 ( V_52 ) ) ;
T_1 V_10 ;
T_2 V_11 ;
if ( ! ( V_54 & V_55 ) ) {
F_17 ( V_50 , L_3 , V_52 ) ;
continue;
}
V_10 = ( ( T_1 ) V_18 & V_56 ) << 32 ;
V_10 |= V_18 & V_57 ;
V_11 = ( V_54 | ~ V_58 ) ;
F_17 ( V_50 , L_4 ,
V_52 , ( unsigned long long ) V_10 ,
( unsigned long long ) V_10 + V_11 + 1 ,
( V_54 & V_59 ) >> V_60 ) ;
}
return 0 ;
}
static int F_18 ( struct V_3 * V_4 ,
struct V_49 * V_50 , void * V_51 )
{
int V_52 ;
for ( V_52 = 0 ; V_52 < 2 ; V_52 ++ ) {
T_2 V_61 = F_4 ( V_4 -> V_53 + F_19 ( V_52 ) ) ;
T_1 V_10 ;
T_2 V_11 ;
if ( ! ( V_61 & 1 ) ) {
F_17 ( V_50 , L_3 , V_52 ) ;
continue;
}
V_10 = V_61 & 0xff800000 ;
V_11 = 0x100000 << ( ( ( V_61 & 0x000f0000 ) >> 16 ) - 4 ) ;
F_17 ( V_50 , L_4 ,
V_52 , ( unsigned long long ) V_10 ,
( unsigned long long ) V_10 + V_11 , V_52 ) ;
}
return 0 ;
}
static int F_20 ( struct V_49 * V_50 , void * V_51 )
{
struct V_3 * V_4 = & V_62 ;
return V_4 -> V_6 -> V_63 ( V_4 , V_50 , V_51 ) ;
}
static int F_21 ( struct V_64 * V_64 , struct V_65 * V_65 )
{
return F_22 ( V_65 , F_20 , V_64 -> V_66 ) ;
}
static int F_23 ( struct V_49 * V_50 , void * V_51 )
{
struct V_3 * V_4 = & V_62 ;
int V_5 ;
for ( V_5 = 0 ; V_5 < V_4 -> V_6 -> V_37 ; V_5 ++ ) {
T_1 V_38 , V_67 ;
T_2 V_40 ;
T_3 V_41 , V_42 ;
int V_9 ;
F_3 ( V_4 , V_5 ,
& V_9 , & V_38 , & V_40 ,
& V_41 , & V_42 , & V_67 ) ;
if ( ! V_9 ) {
F_17 ( V_50 , L_5 , V_5 ) ;
continue;
}
F_17 ( V_50 , L_6 ,
V_5 , ( unsigned long long ) V_38 ,
( unsigned long long ) ( V_38 + V_40 ) , V_41 , V_42 ) ;
if ( ! F_11 ( V_40 ) ||
( ( V_38 & ( T_1 ) ( V_40 - 1 ) ) != 0 ) )
F_24 ( V_50 , L_7 ) ;
if ( F_2 ( V_4 , V_5 ) ) {
F_17 ( V_50 , L_8 ,
( unsigned long long ) V_67 ) ;
} else
F_17 ( V_50 , L_9 ) ;
}
return 0 ;
}
static int F_25 ( struct V_64 * V_64 , struct V_65 * V_65 )
{
return F_22 ( V_65 , F_23 , V_64 -> V_66 ) ;
}
static unsigned int F_26 ( int V_5 )
{
return V_5 << 4 ;
}
static unsigned int F_27 ( int V_5 )
{
if ( V_5 < 8 )
return V_5 << 4 ;
else
return 0x90 + ( ( V_5 - 8 ) << 3 ) ;
}
static unsigned int F_28 ( int V_5 )
{
if ( V_5 < 8 )
return V_5 << 4 ;
else
return 0x900 + ( ( V_5 - 8 ) << 4 ) ;
}
static unsigned int F_29 ( int V_5 )
{
if ( V_5 < 2 )
return F_26 ( V_5 ) ;
else
return V_8 ;
}
static unsigned int F_30 ( int V_5 )
{
if ( V_5 < 4 )
return F_26 ( V_5 ) ;
else
return V_8 ;
}
static unsigned int F_31 ( int V_5 )
{
if ( V_5 < 8 )
return F_26 ( V_5 ) ;
else
return V_8 ;
}
static unsigned int F_32 ( int V_5 )
{
if ( V_5 < 8 )
return F_26 ( V_5 ) ;
else if ( V_5 == 13 )
return 0xF0 - V_33 ;
else
return V_8 ;
}
static void T_7
F_33 ( T_8 * V_68 , T_8 * V_36 )
{
struct V_69 * V_70 ;
T_8 V_71 = 0 ;
F_34 (memory, r) {
if ( V_70 -> V_10 >= 0x100000000 )
continue;
if ( V_70 -> V_10 + V_70 -> V_11 > V_71 )
V_71 = V_70 -> V_10 + V_70 -> V_11 ;
}
* V_68 = V_71 ;
* V_36 = 0x100000000 ;
}
static void T_7
F_35 ( struct V_3 * V_4 )
{
int V_52 ;
int V_72 ;
T_8 V_73 , V_74 ;
V_2 . V_75 = V_76 ;
F_33 ( & V_73 , & V_74 ) ;
for ( V_52 = 0 , V_72 = 0 ; V_52 < 4 ; V_52 ++ ) {
T_1 V_10 = F_4 ( V_4 -> V_53 + F_15 ( V_52 ) ) ;
T_1 V_11 = F_4 ( V_4 -> V_53 + F_16 ( V_52 ) ) ;
T_1 V_36 ;
struct V_77 * V_78 ;
if ( ! ( V_11 & V_55 ) )
continue;
if ( V_10 & V_56 )
continue;
V_10 = V_10 & V_57 ;
V_11 = ( V_11 | ~ V_58 ) + 1 ;
V_36 = V_10 + V_11 ;
if ( V_10 >= V_73 && V_36 <= V_74 )
continue;
if ( V_10 >= V_73 && V_36 > V_74 ) {
V_11 -= V_74 - V_10 ;
V_10 = V_74 ;
}
if ( V_10 < V_73 && V_36 > V_73 )
V_11 -= V_36 - V_73 ;
V_78 = & V_2 . V_72 [ V_72 ++ ] ;
V_78 -> V_79 = V_52 ;
V_78 -> V_80 = 0xf & ~ ( 1 << V_52 ) ;
if ( V_4 -> V_81 )
V_78 -> V_80 |= V_82 ;
V_78 -> V_10 = V_10 ;
V_78 -> V_11 = V_11 ;
}
V_2 . V_83 = V_72 ;
}
static int
F_36 ( struct V_3 * V_4 ,
T_2 * V_84 )
{
int V_52 ;
for ( V_52 = 0 ; V_52 < 4 ; V_52 ++ ) {
T_2 V_10 = F_4 ( V_4 -> V_53 + F_15 ( V_52 ) ) ;
T_2 V_11 = F_4 ( V_4 -> V_53 + F_16 ( V_52 ) ) ;
F_6 ( V_4 -> V_85 + F_15 ( V_52 ) ,
V_84 ++ ) ;
F_6 ( V_10 , V_84 ++ ) ;
F_6 ( V_4 -> V_85 + F_16 ( V_52 ) ,
V_84 ++ ) ;
F_6 ( V_11 , V_84 ++ ) ;
}
return 16 ;
}
static void T_7
F_37 ( struct V_3 * V_4 )
{
int V_52 ;
int V_72 ;
V_2 . V_75 = V_76 ;
for ( V_52 = 0 , V_72 = 0 ; V_52 < 2 ; V_52 ++ ) {
T_2 V_61 = F_4 ( V_4 -> V_53 + F_19 ( V_52 ) ) ;
if ( V_61 & 1 ) {
struct V_77 * V_78 ;
V_78 = & V_2 . V_72 [ V_72 ++ ] ;
V_78 -> V_79 = V_52 ;
V_78 -> V_80 = 0 ;
V_78 -> V_10 = V_61 & 0xff800000 ;
V_78 -> V_11 = 0x100000 << ( ( ( V_61 & 0x000f0000 ) >> 16 ) - 4 ) ;
}
}
V_2 . V_83 = V_72 ;
}
static int
F_38 ( struct V_3 * V_4 ,
T_2 * V_84 )
{
int V_52 ;
for ( V_52 = 0 ; V_52 < 2 ; V_52 ++ ) {
T_2 V_61 = F_4 ( V_4 -> V_53 + F_19 ( V_52 ) ) ;
F_6 ( V_4 -> V_85 + F_19 ( V_52 ) ,
V_84 ++ ) ;
F_6 ( V_61 , V_84 ++ ) ;
}
return 4 ;
}
int F_39 ( T_2 * V_84 )
{
return V_62 . V_6 -> V_86 ( & V_62 , V_84 ) ;
}
int F_40 ( unsigned int V_12 ,
unsigned int V_87 ,
T_5 V_10 , T_6 V_11 ,
T_5 V_14 )
{
struct V_3 * V_71 = & V_62 ;
if ( ! F_8 ( V_71 , V_10 , V_11 , V_12 , V_87 ) ) {
F_41 ( L_10 ,
V_12 , V_87 ) ;
return - V_45 ;
}
return F_13 ( V_71 , V_10 , V_11 , V_14 , V_12 , V_87 ) ;
}
int F_42 ( unsigned int V_12 , unsigned int V_87 ,
T_5 V_10 , T_6 V_11 )
{
return F_40 ( V_12 , V_87 , V_10 ,
V_11 , V_8 ) ;
}
int F_43 ( T_5 V_10 , T_6 V_11 )
{
int V_5 ;
V_5 = F_9 ( & V_62 , V_10 , V_11 ) ;
if ( V_5 < 0 )
return V_5 ;
F_5 ( & V_62 , V_5 ) ;
return 0 ;
}
void F_44 ( struct V_88 * V_89 )
{
if ( ! V_89 )
return;
* V_89 = V_62 . V_90 ;
}
void F_45 ( struct V_88 * V_89 )
{
if ( ! V_89 )
return;
* V_89 = V_62 . V_91 ;
}
static T_7 int F_46 ( void )
{
struct V_3 * V_71 = & V_62 ;
if ( ! V_71 -> V_16 )
return 0 ;
V_71 -> V_92 = F_47 ( L_11 , NULL ) ;
if ( V_71 -> V_92 ) {
V_71 -> V_93 = F_48 ( L_12 , V_94 ,
V_71 -> V_92 , NULL ,
& V_95 ) ;
V_71 -> V_96 = F_48 ( L_13 , V_94 ,
V_71 -> V_92 , NULL ,
& V_97 ) ;
}
return 0 ;
}
static int F_49 ( void )
{
struct V_3 * V_71 = & V_62 ;
int V_5 ;
if ( ! V_71 -> V_98 )
return - V_43 ;
for ( V_5 = 0 ; V_5 < V_71 -> V_6 -> V_37 ; V_5 ++ ) {
void T_4 * V_15 = V_71 -> V_16 +
V_71 -> V_6 -> V_17 ( V_5 ) ;
void T_4 * V_32 ;
V_71 -> V_99 [ V_5 ] . V_10 = F_4 ( V_15 + V_19 ) ;
V_71 -> V_99 [ V_5 ] . V_35 = F_4 ( V_15 + V_21 ) ;
if ( ! F_2 ( V_71 , V_5 ) )
continue;
V_32 = V_71 -> V_16 +
V_71 -> V_6 -> V_7 ( V_5 ) ;
V_71 -> V_99 [ V_5 ] . V_100 = F_4 ( V_32 + V_33 ) ;
V_71 -> V_99 [ V_5 ] . V_31 = F_4 ( V_32 + V_34 ) ;
}
V_71 -> V_101 = F_4 ( V_71 -> V_98 +
V_102 ) ;
V_71 -> V_73 = F_4 ( V_71 -> V_98 +
V_103 ) ;
return 0 ;
}
static void F_50 ( void )
{
struct V_3 * V_71 = & V_62 ;
int V_5 ;
F_6 ( V_71 -> V_101 ,
V_71 -> V_98 + V_102 ) ;
F_6 ( V_71 -> V_73 ,
V_71 -> V_98 + V_103 ) ;
for ( V_5 = 0 ; V_5 < V_71 -> V_6 -> V_37 ; V_5 ++ ) {
void T_4 * V_15 = V_71 -> V_16 +
V_71 -> V_6 -> V_17 ( V_5 ) ;
void T_4 * V_32 ;
F_6 ( V_71 -> V_99 [ V_5 ] . V_10 , V_15 + V_19 ) ;
F_6 ( V_71 -> V_99 [ V_5 ] . V_35 , V_15 + V_21 ) ;
if ( ! F_2 ( V_71 , V_5 ) )
continue;
V_32 = V_71 -> V_16 +
V_71 -> V_6 -> V_7 ( V_5 ) ;
F_6 ( V_71 -> V_99 [ V_5 ] . V_100 , V_32 + V_33 ) ;
F_6 ( V_71 -> V_99 [ V_5 ] . V_31 , V_32 + V_34 ) ;
}
}
static int T_7 F_51 ( struct V_3 * V_4 ,
T_5 V_104 ,
T_6 V_105 ,
T_5 V_85 ,
T_6 V_106 ,
T_5 V_107 ,
T_6 V_108 ,
bool V_109 )
{
int V_5 ;
V_4 -> V_16 = F_52 ( V_104 , V_105 ) ;
if ( ! V_4 -> V_16 )
return - V_48 ;
V_4 -> V_53 = F_52 ( V_85 , V_106 ) ;
if ( ! V_4 -> V_53 ) {
F_53 ( V_62 . V_16 ) ;
return - V_48 ;
}
V_4 -> V_85 = V_85 ;
if ( V_107 ) {
V_4 -> V_98 = F_52 ( V_107 ,
V_108 ) ;
if ( ! V_4 -> V_98 ) {
F_53 ( V_4 -> V_53 ) ;
F_53 ( V_4 -> V_16 ) ;
return - V_48 ;
}
} else
V_4 -> V_98 = NULL ;
for ( V_5 = 0 ; V_5 < V_4 -> V_6 -> V_37 ; V_5 ++ )
F_5 ( V_4 , V_5 ) ;
V_4 -> V_6 -> V_110 ( V_4 ) ;
if ( V_109 )
F_6 ( V_111 ,
V_4 -> V_16 + V_112 ) ;
F_54 ( & V_113 ) ;
return 0 ;
}
int T_7 F_55 ( const char * V_6 , T_5 V_104 ,
T_6 V_105 ,
T_5 V_85 ,
T_6 V_106 )
{
const struct V_114 * V_115 ;
for ( V_115 = V_116 ; V_115 -> V_117 [ 0 ] ; V_115 ++ )
if ( ! strcmp ( V_115 -> V_117 , V_6 ) )
break;
if ( ! V_115 -> V_117 [ 0 ] ) {
F_41 ( L_14 ) ;
return - V_43 ;
}
V_62 . V_6 = V_115 -> V_118 ;
return F_51 ( & V_62 ,
V_104 ,
V_105 ,
V_85 ,
V_106 , 0 , 0 , false ) ;
}
static int T_7 F_56 ( struct V_3 * V_4 ,
T_2 V_10 , T_2 V_11 ,
T_3 V_12 , T_3 V_13 )
{
if ( ! F_8 ( V_4 , V_10 , V_11 , V_12 , V_13 ) ) {
F_41 ( L_15 ,
V_12 , V_13 ) ;
return - V_119 ;
}
if ( F_13 ( V_4 , V_10 , V_11 , V_8 ,
V_12 , V_13 ) ) {
F_41 ( L_16 ,
V_12 , V_13 ) ;
return - V_48 ;
}
return 0 ;
}
static int T_7
F_57 ( struct V_120 * V_121 ,
int * V_122 , int * V_123 , int * V_124 ,
int * V_125 , const T_9 * * V_126 ,
const T_9 * * V_127 )
{
const T_9 * V_128 ;
int V_129 , V_130 ;
* V_126 = F_58 ( V_121 , L_17 , & V_129 ) ;
if ( * V_126 == NULL ) {
* V_122 = * V_123 = * V_124 = * V_125 = 0 ;
* V_126 = * V_127 = NULL ;
return 0 ;
}
* V_127 = * V_126 + V_129 / sizeof( T_9 ) ;
* V_122 = F_59 ( V_121 ) ;
V_128 = F_58 ( V_121 , L_18 , NULL ) ;
* V_123 = F_60 ( V_128 ) ;
V_128 = F_58 ( V_121 , L_19 , NULL ) ;
* V_124 = F_60 ( V_128 ) ;
* V_125 = * V_122 + * V_123 + * V_124 ;
V_130 = ( * V_125 ) * sizeof( T_9 ) ;
if ( V_129 % V_130 ) {
F_61 ( L_20 , V_121 -> V_131 ) ;
return - V_45 ;
}
return 0 ;
}
static int T_7 F_62 ( struct V_3 * V_4 ,
struct V_120 * V_132 )
{
int V_122 , V_123 , V_124 ;
int V_52 , V_133 , V_125 ;
const T_9 * V_70 , * V_126 , * V_127 ;
V_133 = F_57 ( V_132 , & V_122 , & V_123 ,
& V_124 , & V_125 ,
& V_126 , & V_127 ) ;
if ( V_133 < 0 )
return V_133 ;
for ( V_52 = 0 , V_70 = V_126 ; V_70 < V_127 ; V_70 += V_125 , V_52 ++ ) {
T_2 V_134 , V_10 , V_11 ;
T_3 V_12 , V_13 ;
V_134 = F_63 ( V_70 , 1 ) ;
if ( F_64 ( V_134 ) )
continue;
V_12 = F_65 ( V_134 ) ;
V_13 = F_66 ( V_134 ) ;
V_10 = F_63 ( V_70 + V_123 , V_122 ) ;
V_11 = F_63 ( V_70 + V_123 + V_122 ,
V_124 ) ;
V_133 = F_56 ( V_4 , V_10 , V_11 , V_12 , V_13 ) ;
if ( V_133 < 0 )
return V_133 ;
}
return 0 ;
}
static void T_7 F_67 ( struct V_120 * V_132 ,
struct V_88 * V_135 ,
struct V_88 * V_136 )
{
T_2 V_137 [ 2 ] ;
int V_133 ;
memset ( V_135 , 0 , sizeof( struct V_88 ) ) ;
V_135 -> V_36 = - 1 ;
memset ( V_136 , 0 , sizeof( struct V_88 ) ) ;
V_136 -> V_36 = - 1 ;
V_133 = F_68 ( V_132 , L_21 , V_137 , F_69 ( V_137 ) ) ;
if ( ! V_133 ) {
V_135 -> V_68 = V_137 [ 0 ] ;
V_135 -> V_36 = V_135 -> V_68 + V_137 [ 1 ] - 1 ;
V_135 -> V_138 = V_139 ;
}
V_133 = F_68 ( V_132 , L_22 , V_137 , F_69 ( V_137 ) ) ;
if ( ! V_133 ) {
V_136 -> V_68 = V_137 [ 0 ] ;
V_136 -> V_36 = V_136 -> V_68 + V_137 [ 1 ] - 1 ;
V_136 -> V_138 = V_140 ;
}
}
int T_7 F_70 ( bool V_109 )
{
struct V_88 V_141 , V_142 , V_143 ;
struct V_120 * V_132 , * V_144 ;
const struct V_114 * V_115 ;
const T_9 * V_128 ;
int V_133 ;
V_132 = F_71 ( NULL , V_116 , & V_115 ) ;
if ( ! V_132 ) {
F_41 ( L_14 ) ;
return - V_43 ;
}
V_62 . V_6 = V_115 -> V_118 ;
V_128 = F_58 ( V_132 , L_23 , NULL ) ;
if ( ! V_128 ) {
F_41 ( L_24 ) ;
return - V_45 ;
}
V_144 = F_72 ( F_60 ( V_128 ) ) ;
if ( ! V_144 ) {
F_41 ( L_25 ) ;
return - V_43 ;
}
if ( F_73 ( V_144 , 0 , & V_141 ) ) {
F_41 ( L_26 ) ;
return - V_45 ;
}
if ( F_73 ( V_144 , 1 , & V_142 ) ) {
F_41 ( L_27 ) ;
return - V_45 ;
}
memset ( & V_143 , 0 , sizeof( V_143 ) ) ;
if ( V_62 . V_6 -> V_145 ) {
if ( F_73 ( V_144 , 2 , & V_143 ) )
F_61 ( V_146 L_28 ) ;
}
V_62 . V_81 = V_109 ;
F_67 ( V_132 , & V_62 . V_90 ,
& V_62 . V_91 ) ;
V_133 = F_51 ( & V_62 ,
V_141 . V_68 ,
F_74 ( & V_141 ) ,
V_142 . V_68 ,
F_74 ( & V_142 ) ,
V_143 . V_68 ,
F_74 ( & V_143 ) ,
V_109 ) ;
if ( V_133 )
return V_133 ;
return F_62 ( & V_62 , V_132 ) ;
}
