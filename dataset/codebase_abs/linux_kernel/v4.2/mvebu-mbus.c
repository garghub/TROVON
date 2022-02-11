const struct V_1 * F_1 ( void )
{
return & V_2 ;
}
const struct V_1 * F_2 ( void )
{
return & V_3 ;
}
static bool F_3 ( struct V_4 * V_5 ,
const int V_6 )
{
return V_5 -> V_7 -> V_8 ( V_6 ) != V_9 ;
}
static void F_4 ( struct V_4 * V_5 ,
int V_6 , int * V_10 , T_1 * V_11 ,
T_2 * V_12 , T_3 * V_13 , T_3 * V_14 ,
T_1 * V_15 )
{
void T_4 * V_16 = V_5 -> V_17 +
V_5 -> V_7 -> V_18 ( V_6 ) ;
T_2 V_19 = F_5 ( V_16 + V_20 ) ;
T_2 V_21 = F_5 ( V_16 + V_22 ) ;
if ( ! ( V_21 & V_23 ) ) {
* V_10 = 0 ;
return;
}
* V_10 = 1 ;
* V_11 = ( ( T_1 ) V_19 & V_24 ) << 32 ;
* V_11 |= ( V_19 & V_25 ) ;
* V_12 = ( V_21 | ~ V_26 ) + 1 ;
if ( V_13 )
* V_13 = ( V_21 & V_27 ) >> V_28 ;
if ( V_14 )
* V_14 = ( V_21 & V_29 ) >> V_30 ;
if ( V_15 ) {
if ( F_3 ( V_5 , V_6 ) ) {
T_2 V_31 , V_32 ;
void T_4 * V_33 = V_5 -> V_17 +
V_5 -> V_7 -> V_8 ( V_6 ) ;
V_31 = F_5 ( V_33 + V_34 ) ;
V_32 = F_5 ( V_33 + V_35 ) ;
* V_15 = ( ( T_1 ) V_32 << 32 ) | V_31 ;
} else
* V_15 = 0 ;
}
}
static void F_6 ( struct V_4 * V_5 ,
int V_6 )
{
void T_4 * V_16 ;
V_16 = V_5 -> V_17 + V_5 -> V_7 -> V_18 ( V_6 ) ;
F_7 ( 0 , V_16 + V_20 ) ;
F_7 ( 0 , V_16 + V_22 ) ;
if ( F_3 ( V_5 , V_6 ) ) {
V_16 = V_5 -> V_17 + V_5 -> V_7 -> V_8 ( V_6 ) ;
F_7 ( 0 , V_16 + V_34 ) ;
F_7 ( 0 , V_16 + V_35 ) ;
}
}
static int F_8 ( struct V_4 * V_5 ,
const int V_6 )
{
void T_4 * V_16 = V_5 -> V_17 +
V_5 -> V_7 -> V_18 ( V_6 ) ;
T_2 V_36 = F_5 ( V_16 + V_22 ) ;
return ! ( V_36 & V_23 ) ;
}
static int F_9 ( struct V_4 * V_5 ,
T_5 V_11 , T_6 V_12 ,
T_3 V_13 , T_3 V_14 )
{
T_1 V_37 = ( T_1 ) V_11 + V_12 ;
int V_6 ;
for ( V_6 = 0 ; V_6 < V_5 -> V_7 -> V_38 ; V_6 ++ ) {
T_1 V_39 , V_40 ;
T_2 V_41 ;
T_3 V_42 , V_43 ;
int V_10 ;
F_4 ( V_5 , V_6 ,
& V_10 , & V_39 , & V_41 ,
& V_42 , & V_43 , NULL ) ;
if ( ! V_10 )
continue;
V_40 = V_39 + V_41 ;
if ( ( T_1 ) V_11 < V_40 && V_37 > V_39 )
return 0 ;
}
return 1 ;
}
static int F_10 ( struct V_4 * V_5 ,
T_5 V_11 , T_6 V_12 )
{
int V_6 ;
for ( V_6 = 0 ; V_6 < V_5 -> V_7 -> V_38 ; V_6 ++ ) {
T_1 V_39 ;
T_2 V_41 ;
int V_10 ;
F_4 ( V_5 , V_6 ,
& V_10 , & V_39 , & V_41 ,
NULL , NULL , NULL ) ;
if ( ! V_10 )
continue;
if ( V_11 == V_39 && V_12 == V_41 )
return V_6 ;
}
return - V_44 ;
}
static int F_11 ( struct V_4 * V_5 ,
int V_6 , T_5 V_11 , T_6 V_12 ,
T_5 V_15 , T_3 V_13 ,
T_3 V_14 )
{
void T_4 * V_16 = V_5 -> V_17 +
V_5 -> V_7 -> V_18 ( V_6 ) ;
T_2 V_36 , V_45 ;
if ( ! F_12 ( V_12 ) ) {
F_13 ( true , L_1 , V_12 ) ;
return - V_46 ;
}
if ( ( V_11 & ( T_5 ) ( V_12 - 1 ) ) != 0 ) {
F_13 ( true , L_2 , & V_11 ,
V_12 ) ;
return - V_46 ;
}
V_36 = ( ( V_12 - 1 ) & V_26 ) |
( V_14 << V_30 ) |
( V_13 << V_28 ) |
V_23 ;
if ( V_5 -> V_47 )
V_36 |= V_48 ;
F_7 ( V_11 & V_25 , V_16 + V_20 ) ;
F_7 ( V_36 , V_16 + V_22 ) ;
if ( F_3 ( V_5 , V_6 ) ) {
void T_4 * V_33 = V_5 -> V_17 +
V_5 -> V_7 -> V_8 ( V_6 ) ;
if ( V_15 == V_9 )
V_45 = V_11 ;
else
V_45 = V_15 ;
F_7 ( V_45 & V_49 , V_33 + V_34 ) ;
F_7 ( 0 , V_33 + V_35 ) ;
}
return 0 ;
}
static int F_14 ( struct V_4 * V_5 ,
T_5 V_11 , T_6 V_12 ,
T_5 V_15 , T_3 V_13 ,
T_3 V_14 )
{
int V_6 ;
if ( V_15 == V_9 ) {
for ( V_6 = 0 ; V_6 < V_5 -> V_7 -> V_38 ; V_6 ++ ) {
if ( F_3 ( V_5 , V_6 ) )
continue;
if ( F_8 ( V_5 , V_6 ) )
return F_11 ( V_5 , V_6 , V_11 ,
V_12 , V_15 ,
V_13 , V_14 ) ;
}
}
for ( V_6 = 0 ; V_6 < V_5 -> V_7 -> V_38 ; V_6 ++ ) {
if ( ( V_15 != V_9 ) &&
! F_3 ( V_5 , V_6 ) )
continue;
if ( F_8 ( V_5 , V_6 ) )
return F_11 ( V_5 , V_6 , V_11 , V_12 ,
V_15 , V_13 , V_14 ) ;
}
return - V_50 ;
}
static int F_15 ( struct V_4 * V_5 ,
struct V_51 * V_52 , void * V_53 )
{
int V_54 ;
for ( V_54 = 0 ; V_54 < 4 ; V_54 ++ ) {
T_2 V_19 = F_5 ( V_5 -> V_55 + F_16 ( V_54 ) ) ;
T_2 V_56 = F_5 ( V_5 -> V_55 + F_17 ( V_54 ) ) ;
T_1 V_11 ;
T_2 V_12 ;
if ( ! ( V_56 & V_57 ) ) {
F_18 ( V_52 , L_3 , V_54 ) ;
continue;
}
V_11 = ( ( T_1 ) V_19 & V_58 ) << 32 ;
V_11 |= V_19 & V_59 ;
V_12 = ( V_56 | ~ V_60 ) ;
F_18 ( V_52 , L_4 ,
V_54 , ( unsigned long long ) V_11 ,
( unsigned long long ) V_11 + V_12 + 1 ,
( V_56 & V_61 ) >> V_62 ) ;
}
return 0 ;
}
static int F_19 ( struct V_4 * V_5 ,
struct V_51 * V_52 , void * V_53 )
{
int V_54 ;
for ( V_54 = 0 ; V_54 < 2 ; V_54 ++ ) {
T_2 V_63 = F_5 ( V_5 -> V_55 + F_20 ( V_54 ) ) ;
T_1 V_11 ;
T_2 V_12 ;
if ( ! ( V_63 & 1 ) ) {
F_18 ( V_52 , L_3 , V_54 ) ;
continue;
}
V_11 = V_63 & 0xff800000 ;
V_12 = 0x100000 << ( ( ( V_63 & 0x000f0000 ) >> 16 ) - 4 ) ;
F_18 ( V_52 , L_4 ,
V_54 , ( unsigned long long ) V_11 ,
( unsigned long long ) V_11 + V_12 , V_54 ) ;
}
return 0 ;
}
static int F_21 ( struct V_51 * V_52 , void * V_53 )
{
struct V_4 * V_5 = & V_64 ;
return V_5 -> V_7 -> V_65 ( V_5 , V_52 , V_53 ) ;
}
static int F_22 ( struct V_66 * V_66 , struct V_67 * V_67 )
{
return F_23 ( V_67 , F_21 , V_66 -> V_68 ) ;
}
static int F_24 ( struct V_51 * V_52 , void * V_53 )
{
struct V_4 * V_5 = & V_64 ;
int V_6 ;
for ( V_6 = 0 ; V_6 < V_5 -> V_7 -> V_38 ; V_6 ++ ) {
T_1 V_39 , V_69 ;
T_2 V_41 ;
T_3 V_42 , V_43 ;
int V_10 ;
F_4 ( V_5 , V_6 ,
& V_10 , & V_39 , & V_41 ,
& V_42 , & V_43 , & V_69 ) ;
if ( ! V_10 ) {
F_18 ( V_52 , L_5 , V_6 ) ;
continue;
}
F_18 ( V_52 , L_6 ,
V_6 , ( unsigned long long ) V_39 ,
( unsigned long long ) ( V_39 + V_41 ) , V_42 , V_43 ) ;
if ( ! F_12 ( V_41 ) ||
( ( V_39 & ( T_1 ) ( V_41 - 1 ) ) != 0 ) )
F_25 ( V_52 , L_7 ) ;
if ( F_3 ( V_5 , V_6 ) ) {
F_18 ( V_52 , L_8 ,
( unsigned long long ) V_69 ) ;
} else
F_18 ( V_52 , L_9 ) ;
}
return 0 ;
}
static int F_26 ( struct V_66 * V_66 , struct V_67 * V_67 )
{
return F_23 ( V_67 , F_24 , V_66 -> V_68 ) ;
}
static unsigned int F_27 ( int V_6 )
{
return V_6 << 4 ;
}
static unsigned int F_28 ( int V_6 )
{
if ( V_6 < 8 )
return V_6 << 4 ;
else
return 0x90 + ( ( V_6 - 8 ) << 3 ) ;
}
static unsigned int F_29 ( int V_6 )
{
if ( V_6 < 8 )
return V_6 << 4 ;
else
return 0x900 + ( ( V_6 - 8 ) << 4 ) ;
}
static unsigned int F_30 ( int V_6 )
{
if ( V_6 < 2 )
return F_27 ( V_6 ) ;
else
return V_9 ;
}
static unsigned int F_31 ( int V_6 )
{
if ( V_6 < 4 )
return F_27 ( V_6 ) ;
else
return V_9 ;
}
static unsigned int F_32 ( int V_6 )
{
if ( V_6 < 8 )
return F_27 ( V_6 ) ;
else
return V_9 ;
}
static unsigned int F_33 ( int V_6 )
{
if ( V_6 < 8 )
return F_27 ( V_6 ) ;
else if ( V_6 == 13 )
return 0xF0 - V_34 ;
else
return V_9 ;
}
static void T_7
F_34 ( T_8 * V_70 , T_8 * V_37 )
{
struct V_71 * V_72 ;
T_8 V_73 = 0 ;
F_35 (memory, r) {
if ( V_72 -> V_11 >= 0x100000000ULL )
continue;
if ( V_72 -> V_11 + V_72 -> V_12 > V_73 )
V_73 = V_72 -> V_11 + V_72 -> V_12 ;
}
* V_70 = V_73 ;
* V_37 = 0x100000000ULL ;
}
static void T_7
F_36 ( struct V_4 * V_5 )
{
T_8 V_74 , V_75 ;
int V_76 = 0 ;
int V_54 ;
F_34 ( & V_74 , & V_75 ) ;
for ( V_54 = 0 ; V_54 < V_2 . V_77 ; V_54 ++ ) {
struct V_78 * V_79 ;
T_1 V_11 , V_12 , V_37 ;
V_79 = & V_2 . V_80 [ V_54 ] ;
V_11 = V_79 -> V_11 ;
V_12 = V_79 -> V_12 ;
V_37 = V_11 + V_12 ;
if ( V_11 >= V_74 && V_37 <= V_75 )
continue;
if ( V_11 >= V_74 && V_37 > V_75 ) {
V_12 -= V_75 - V_11 ;
V_11 = V_75 ;
}
if ( V_11 < V_74 && V_37 > V_74 )
V_12 -= V_37 - V_74 ;
V_79 = & V_3 . V_80 [ V_76 ++ ] ;
V_79 -> V_81 = V_54 ;
V_79 -> V_82 = 0xf & ~ ( 1 << V_54 ) ;
if ( V_5 -> V_47 )
V_79 -> V_82 |= V_83 ;
V_79 -> V_11 = V_11 ;
V_79 -> V_12 = V_12 ;
}
V_3 . V_84 = V_85 ;
V_3 . V_77 = V_76 ;
}
static void T_7
F_37 ( struct V_4 * V_5 )
{
int V_54 ;
int V_80 ;
V_2 . V_84 = V_85 ;
for ( V_54 = 0 , V_80 = 0 ; V_54 < 4 ; V_54 ++ ) {
T_2 V_11 = F_5 ( V_5 -> V_55 + F_16 ( V_54 ) ) ;
T_2 V_12 = F_5 ( V_5 -> V_55 + F_17 ( V_54 ) ) ;
if ( ( V_12 & V_57 ) &&
! ( V_11 & V_58 ) ) {
struct V_78 * V_79 ;
V_79 = & V_2 . V_80 [ V_80 ++ ] ;
V_79 -> V_81 = V_54 ;
V_79 -> V_82 = 0xf & ~ ( 1 << V_54 ) ;
if ( V_5 -> V_47 )
V_79 -> V_82 |= V_83 ;
V_79 -> V_11 = V_11 & V_59 ;
V_79 -> V_12 = ( V_12 | ~ V_60 ) + 1 ;
}
}
V_2 . V_77 = V_80 ;
}
static int
F_38 ( struct V_4 * V_5 ,
T_2 * V_86 )
{
int V_54 ;
for ( V_54 = 0 ; V_54 < 4 ; V_54 ++ ) {
T_2 V_11 = F_5 ( V_5 -> V_55 + F_16 ( V_54 ) ) ;
T_2 V_12 = F_5 ( V_5 -> V_55 + F_17 ( V_54 ) ) ;
F_7 ( V_5 -> V_87 + F_16 ( V_54 ) ,
V_86 ++ ) ;
F_7 ( V_11 , V_86 ++ ) ;
F_7 ( V_5 -> V_87 + F_17 ( V_54 ) ,
V_86 ++ ) ;
F_7 ( V_12 , V_86 ++ ) ;
}
return 16 ;
}
static void T_7
F_39 ( struct V_4 * V_5 )
{
int V_54 ;
int V_80 ;
V_2 . V_84 = V_85 ;
for ( V_54 = 0 , V_80 = 0 ; V_54 < 2 ; V_54 ++ ) {
T_2 V_63 = F_5 ( V_5 -> V_55 + F_20 ( V_54 ) ) ;
if ( V_63 & 1 ) {
struct V_78 * V_79 ;
V_79 = & V_2 . V_80 [ V_80 ++ ] ;
V_79 -> V_81 = V_54 ;
V_79 -> V_82 = 0 ;
V_79 -> V_11 = V_63 & 0xff800000 ;
V_79 -> V_12 = 0x100000 << ( ( ( V_63 & 0x000f0000 ) >> 16 ) - 4 ) ;
}
}
V_2 . V_77 = V_80 ;
}
static int
F_40 ( struct V_4 * V_5 ,
T_2 * V_86 )
{
int V_54 ;
for ( V_54 = 0 ; V_54 < 2 ; V_54 ++ ) {
T_2 V_63 = F_5 ( V_5 -> V_55 + F_20 ( V_54 ) ) ;
F_7 ( V_5 -> V_87 + F_20 ( V_54 ) ,
V_86 ++ ) ;
F_7 ( V_63 , V_86 ++ ) ;
}
return 4 ;
}
int F_41 ( T_2 * V_86 )
{
return V_64 . V_7 -> V_88 ( & V_64 , V_86 ) ;
}
int F_42 ( unsigned int V_13 ,
unsigned int V_89 ,
T_5 V_11 , T_6 V_12 ,
T_5 V_15 )
{
struct V_4 * V_73 = & V_64 ;
if ( ! F_9 ( V_73 , V_11 , V_12 , V_13 , V_89 ) ) {
F_43 ( L_10 ,
V_13 , V_89 ) ;
return - V_46 ;
}
return F_14 ( V_73 , V_11 , V_12 , V_15 , V_13 , V_89 ) ;
}
int F_44 ( unsigned int V_13 , unsigned int V_89 ,
T_5 V_11 , T_6 V_12 )
{
return F_42 ( V_13 , V_89 , V_11 ,
V_12 , V_9 ) ;
}
int F_45 ( T_5 V_11 , T_6 V_12 )
{
int V_6 ;
V_6 = F_10 ( & V_64 , V_11 , V_12 ) ;
if ( V_6 < 0 )
return V_6 ;
F_6 ( & V_64 , V_6 ) ;
return 0 ;
}
void F_46 ( struct V_90 * V_91 )
{
if ( ! V_91 )
return;
* V_91 = V_64 . V_92 ;
}
void F_47 ( struct V_90 * V_91 )
{
if ( ! V_91 )
return;
* V_91 = V_64 . V_93 ;
}
static T_7 int F_48 ( void )
{
struct V_4 * V_73 = & V_64 ;
if ( ! V_73 -> V_17 )
return 0 ;
V_73 -> V_94 = F_49 ( L_11 , NULL ) ;
if ( V_73 -> V_94 ) {
V_73 -> V_95 = F_50 ( L_12 , V_96 ,
V_73 -> V_94 , NULL ,
& V_97 ) ;
V_73 -> V_98 = F_50 ( L_13 , V_96 ,
V_73 -> V_94 , NULL ,
& V_99 ) ;
}
return 0 ;
}
static int F_51 ( void )
{
struct V_4 * V_73 = & V_64 ;
int V_6 ;
if ( ! V_73 -> V_100 )
return - V_44 ;
for ( V_6 = 0 ; V_6 < V_73 -> V_7 -> V_38 ; V_6 ++ ) {
void T_4 * V_16 = V_73 -> V_17 +
V_73 -> V_7 -> V_18 ( V_6 ) ;
void T_4 * V_33 ;
V_73 -> V_101 [ V_6 ] . V_11 = F_5 ( V_16 + V_20 ) ;
V_73 -> V_101 [ V_6 ] . V_36 = F_5 ( V_16 + V_22 ) ;
if ( ! F_3 ( V_73 , V_6 ) )
continue;
V_33 = V_73 -> V_17 +
V_73 -> V_7 -> V_8 ( V_6 ) ;
V_73 -> V_101 [ V_6 ] . V_102 = F_5 ( V_33 + V_34 ) ;
V_73 -> V_101 [ V_6 ] . V_32 = F_5 ( V_33 + V_35 ) ;
}
V_73 -> V_103 = F_5 ( V_73 -> V_100 +
V_104 ) ;
V_73 -> V_74 = F_5 ( V_73 -> V_100 +
V_105 ) ;
return 0 ;
}
static void F_52 ( void )
{
struct V_4 * V_73 = & V_64 ;
int V_6 ;
F_7 ( V_73 -> V_103 ,
V_73 -> V_100 + V_104 ) ;
F_7 ( V_73 -> V_74 ,
V_73 -> V_100 + V_105 ) ;
for ( V_6 = 0 ; V_6 < V_73 -> V_7 -> V_38 ; V_6 ++ ) {
void T_4 * V_16 = V_73 -> V_17 +
V_73 -> V_7 -> V_18 ( V_6 ) ;
void T_4 * V_33 ;
F_7 ( V_73 -> V_101 [ V_6 ] . V_11 , V_16 + V_20 ) ;
F_7 ( V_73 -> V_101 [ V_6 ] . V_36 , V_16 + V_22 ) ;
if ( ! F_3 ( V_73 , V_6 ) )
continue;
V_33 = V_73 -> V_17 +
V_73 -> V_7 -> V_8 ( V_6 ) ;
F_7 ( V_73 -> V_101 [ V_6 ] . V_102 , V_33 + V_34 ) ;
F_7 ( V_73 -> V_101 [ V_6 ] . V_32 , V_33 + V_35 ) ;
}
}
static int T_7 F_53 ( struct V_4 * V_5 ,
T_5 V_106 ,
T_6 V_107 ,
T_5 V_87 ,
T_6 V_108 ,
T_5 V_109 ,
T_6 V_110 ,
bool V_111 )
{
int V_6 ;
V_5 -> V_17 = F_54 ( V_106 , V_107 ) ;
if ( ! V_5 -> V_17 )
return - V_50 ;
V_5 -> V_55 = F_54 ( V_87 , V_108 ) ;
if ( ! V_5 -> V_55 ) {
F_55 ( V_64 . V_17 ) ;
return - V_50 ;
}
V_5 -> V_87 = V_87 ;
if ( V_109 ) {
V_5 -> V_100 = F_54 ( V_109 ,
V_110 ) ;
if ( ! V_5 -> V_100 ) {
F_55 ( V_5 -> V_55 ) ;
F_55 ( V_5 -> V_17 ) ;
return - V_50 ;
}
} else
V_5 -> V_100 = NULL ;
for ( V_6 = 0 ; V_6 < V_5 -> V_7 -> V_38 ; V_6 ++ )
F_6 ( V_5 , V_6 ) ;
V_5 -> V_7 -> V_112 ( V_5 ) ;
F_36 ( V_5 ) ;
if ( V_111 )
F_7 ( V_113 ,
V_5 -> V_17 + V_114 ) ;
F_56 ( & V_115 ) ;
return 0 ;
}
int T_7 F_57 ( const char * V_7 , T_5 V_106 ,
T_6 V_107 ,
T_5 V_87 ,
T_6 V_108 )
{
const struct V_116 * V_117 ;
for ( V_117 = V_118 ; V_117 -> V_119 [ 0 ] ; V_117 ++ )
if ( ! strcmp ( V_117 -> V_119 , V_7 ) )
break;
if ( ! V_117 -> V_119 [ 0 ] ) {
F_43 ( L_14 ) ;
return - V_44 ;
}
V_64 . V_7 = V_117 -> V_120 ;
return F_53 ( & V_64 ,
V_106 ,
V_107 ,
V_87 ,
V_108 , 0 , 0 , false ) ;
}
static int T_7 F_58 ( struct V_4 * V_5 ,
T_2 V_11 , T_2 V_12 ,
T_3 V_13 , T_3 V_14 )
{
if ( ! F_9 ( V_5 , V_11 , V_12 , V_13 , V_14 ) ) {
F_43 ( L_15 ,
V_13 , V_14 ) ;
return - V_121 ;
}
if ( F_14 ( V_5 , V_11 , V_12 , V_9 ,
V_13 , V_14 ) ) {
F_43 ( L_16 ,
V_13 , V_14 ) ;
return - V_50 ;
}
return 0 ;
}
static int T_7
F_59 ( struct V_122 * V_123 ,
int * V_124 , int * V_125 , int * V_126 ,
int * V_127 , const T_9 * * V_128 ,
const T_9 * * V_129 )
{
const T_9 * V_130 ;
int V_131 , V_132 ;
* V_128 = F_60 ( V_123 , L_17 , & V_131 ) ;
if ( * V_128 == NULL ) {
* V_124 = * V_125 = * V_126 = * V_127 = 0 ;
* V_128 = * V_129 = NULL ;
return 0 ;
}
* V_129 = * V_128 + V_131 / sizeof( T_9 ) ;
* V_124 = F_61 ( V_123 ) ;
V_130 = F_60 ( V_123 , L_18 , NULL ) ;
* V_125 = F_62 ( V_130 ) ;
V_130 = F_60 ( V_123 , L_19 , NULL ) ;
* V_126 = F_62 ( V_130 ) ;
* V_127 = * V_124 + * V_125 + * V_126 ;
V_132 = ( * V_127 ) * sizeof( T_9 ) ;
if ( V_131 % V_132 ) {
F_63 ( L_20 , V_123 -> V_133 ) ;
return - V_46 ;
}
return 0 ;
}
static int T_7 F_64 ( struct V_4 * V_5 ,
struct V_122 * V_134 )
{
int V_124 , V_125 , V_126 ;
int V_54 , V_135 , V_127 ;
const T_9 * V_72 , * V_128 , * V_129 ;
V_135 = F_59 ( V_134 , & V_124 , & V_125 ,
& V_126 , & V_127 ,
& V_128 , & V_129 ) ;
if ( V_135 < 0 )
return V_135 ;
for ( V_54 = 0 , V_72 = V_128 ; V_72 < V_129 ; V_72 += V_127 , V_54 ++ ) {
T_2 V_136 , V_11 , V_12 ;
T_3 V_13 , V_14 ;
V_136 = F_65 ( V_72 , 1 ) ;
if ( F_66 ( V_136 ) )
continue;
V_13 = F_67 ( V_136 ) ;
V_14 = F_68 ( V_136 ) ;
V_11 = F_65 ( V_72 + V_125 , V_124 ) ;
V_12 = F_65 ( V_72 + V_125 + V_124 ,
V_126 ) ;
V_135 = F_58 ( V_5 , V_11 , V_12 , V_13 , V_14 ) ;
if ( V_135 < 0 )
return V_135 ;
}
return 0 ;
}
static void T_7 F_69 ( struct V_122 * V_134 ,
struct V_90 * V_137 ,
struct V_90 * V_138 )
{
T_2 V_139 [ 2 ] ;
int V_135 ;
memset ( V_137 , 0 , sizeof( struct V_90 ) ) ;
V_137 -> V_37 = - 1 ;
memset ( V_138 , 0 , sizeof( struct V_90 ) ) ;
V_138 -> V_37 = - 1 ;
V_135 = F_70 ( V_134 , L_21 , V_139 , F_71 ( V_139 ) ) ;
if ( ! V_135 ) {
V_137 -> V_70 = V_139 [ 0 ] ;
V_137 -> V_37 = V_137 -> V_70 + V_139 [ 1 ] - 1 ;
V_137 -> V_140 = V_141 ;
}
V_135 = F_70 ( V_134 , L_22 , V_139 , F_71 ( V_139 ) ) ;
if ( ! V_135 ) {
V_138 -> V_70 = V_139 [ 0 ] ;
V_138 -> V_37 = V_138 -> V_70 + V_139 [ 1 ] - 1 ;
V_138 -> V_140 = V_142 ;
}
}
int T_7 F_72 ( bool V_111 )
{
struct V_90 V_143 , V_144 , V_145 ;
struct V_122 * V_134 , * V_146 ;
const struct V_116 * V_117 ;
const T_9 * V_130 ;
int V_135 ;
V_134 = F_73 ( NULL , V_118 , & V_117 ) ;
if ( ! V_134 ) {
F_43 ( L_14 ) ;
return - V_44 ;
}
V_64 . V_7 = V_117 -> V_120 ;
V_130 = F_60 ( V_134 , L_23 , NULL ) ;
if ( ! V_130 ) {
F_43 ( L_24 ) ;
return - V_46 ;
}
V_146 = F_74 ( F_62 ( V_130 ) ) ;
if ( ! V_146 ) {
F_43 ( L_25 ) ;
return - V_44 ;
}
if ( F_75 ( V_146 , 0 , & V_143 ) ) {
F_43 ( L_26 ) ;
return - V_46 ;
}
if ( F_75 ( V_146 , 1 , & V_144 ) ) {
F_43 ( L_27 ) ;
return - V_46 ;
}
memset ( & V_145 , 0 , sizeof( V_145 ) ) ;
if ( V_64 . V_7 -> V_147 ) {
if ( F_75 ( V_146 , 2 , & V_145 ) )
F_63 ( V_148 L_28 ) ;
}
V_64 . V_47 = V_111 ;
F_69 ( V_134 , & V_64 . V_92 ,
& V_64 . V_93 ) ;
V_135 = F_53 ( & V_64 ,
V_143 . V_70 ,
F_76 ( & V_143 ) ,
V_144 . V_70 ,
F_76 ( & V_144 ) ,
V_145 . V_70 ,
F_76 ( & V_145 ) ,
V_111 ) ;
if ( V_135 )
return V_135 ;
return F_64 ( & V_64 , V_134 ) ;
}
