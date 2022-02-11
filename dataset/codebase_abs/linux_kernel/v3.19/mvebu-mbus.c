const struct V_1 * F_1 ( void )
{
return & V_2 ;
}
static void F_2 ( struct V_3 * V_4 ,
int V_5 , int * V_6 , T_1 * V_7 ,
T_2 * V_8 , T_3 * V_9 , T_3 * V_10 ,
T_1 * V_11 )
{
void T_4 * V_12 = V_4 -> V_13 +
V_4 -> V_14 -> V_15 ( V_5 ) ;
T_2 V_16 = F_3 ( V_12 + V_17 ) ;
T_2 V_18 = F_3 ( V_12 + V_19 ) ;
if ( ! ( V_18 & V_20 ) ) {
* V_6 = 0 ;
return;
}
* V_6 = 1 ;
* V_7 = ( ( T_1 ) V_16 & V_21 ) << 32 ;
* V_7 |= ( V_16 & V_22 ) ;
* V_8 = ( V_18 | ~ V_23 ) + 1 ;
if ( V_9 )
* V_9 = ( V_18 & V_24 ) >> V_25 ;
if ( V_10 )
* V_10 = ( V_18 & V_26 ) >> V_27 ;
if ( V_11 ) {
if ( V_5 < V_4 -> V_14 -> V_28 ) {
T_2 V_29 = F_3 ( V_12 + V_30 ) ;
T_2 V_31 = F_3 ( V_12 + V_32 ) ;
* V_11 = ( ( T_1 ) V_31 << 32 ) | V_29 ;
} else
* V_11 = 0 ;
}
}
static void F_4 ( struct V_3 * V_4 ,
int V_5 )
{
void T_4 * V_12 ;
V_12 = V_4 -> V_13 + V_4 -> V_14 -> V_15 ( V_5 ) ;
F_5 ( 0 , V_12 + V_17 ) ;
F_5 ( 0 , V_12 + V_19 ) ;
if ( V_5 < V_4 -> V_14 -> V_28 ) {
F_5 ( 0 , V_12 + V_30 ) ;
F_5 ( 0 , V_12 + V_32 ) ;
}
}
static int F_6 ( struct V_3 * V_4 ,
const int V_5 )
{
void T_4 * V_12 = V_4 -> V_13 +
V_4 -> V_14 -> V_15 ( V_5 ) ;
T_2 V_33 = F_3 ( V_12 + V_19 ) ;
if ( V_5 == 13 )
return false ;
return ! ( V_33 & V_20 ) ;
}
static int F_7 ( struct V_3 * V_4 ,
T_5 V_7 , T_6 V_8 ,
T_3 V_9 , T_3 V_10 )
{
T_1 V_34 = ( T_1 ) V_7 + V_8 ;
int V_5 ;
for ( V_5 = 0 ; V_5 < V_4 -> V_14 -> V_35 ; V_5 ++ ) {
T_1 V_36 , V_37 ;
T_2 V_38 ;
T_3 V_39 , V_40 ;
int V_6 ;
F_2 ( V_4 , V_5 ,
& V_6 , & V_36 , & V_38 ,
& V_39 , & V_40 , NULL ) ;
if ( ! V_6 )
continue;
V_37 = V_36 + V_38 ;
if ( ( T_1 ) V_7 < V_37 && V_34 > V_36 )
return 0 ;
}
return 1 ;
}
static int F_8 ( struct V_3 * V_4 ,
T_5 V_7 , T_6 V_8 )
{
int V_5 ;
for ( V_5 = 0 ; V_5 < V_4 -> V_14 -> V_35 ; V_5 ++ ) {
T_1 V_36 ;
T_2 V_38 ;
int V_6 ;
F_2 ( V_4 , V_5 ,
& V_6 , & V_36 , & V_38 ,
NULL , NULL , NULL ) ;
if ( ! V_6 )
continue;
if ( V_7 == V_36 && V_8 == V_38 )
return V_5 ;
}
return - V_41 ;
}
static int F_9 ( struct V_3 * V_4 ,
int V_5 , T_5 V_7 , T_6 V_8 ,
T_5 V_11 , T_3 V_9 ,
T_3 V_10 )
{
void T_4 * V_12 = V_4 -> V_13 +
V_4 -> V_14 -> V_15 ( V_5 ) ;
T_2 V_33 , V_42 ;
if ( ! F_10 ( V_8 ) ) {
F_11 ( true , L_1 , V_8 ) ;
return - V_43 ;
}
if ( ( V_7 & ( T_5 ) ( V_8 - 1 ) ) != 0 ) {
F_11 ( true , L_2 , & V_7 ,
V_8 ) ;
return - V_43 ;
}
V_33 = ( ( V_8 - 1 ) & V_23 ) |
( V_10 << V_27 ) |
( V_9 << V_25 ) |
V_20 ;
F_5 ( V_7 & V_22 , V_12 + V_17 ) ;
F_5 ( V_33 , V_12 + V_19 ) ;
if ( V_5 < V_4 -> V_14 -> V_28 ) {
if ( V_11 == V_44 )
V_42 = V_7 ;
else
V_42 = V_11 ;
F_5 ( V_42 & V_45 , V_12 + V_30 ) ;
F_5 ( 0 , V_12 + V_32 ) ;
}
return 0 ;
}
static int F_12 ( struct V_3 * V_4 ,
T_5 V_7 , T_6 V_8 ,
T_5 V_11 , T_3 V_9 ,
T_3 V_10 )
{
int V_5 ;
if ( V_11 == V_44 ) {
for ( V_5 = V_4 -> V_14 -> V_28 ;
V_5 < V_4 -> V_14 -> V_35 ; V_5 ++ )
if ( F_6 ( V_4 , V_5 ) )
return F_9 ( V_4 , V_5 , V_7 ,
V_8 , V_11 ,
V_9 , V_10 ) ;
}
for ( V_5 = 0 ; V_5 < V_4 -> V_14 -> V_35 ; V_5 ++ )
if ( F_6 ( V_4 , V_5 ) )
return F_9 ( V_4 , V_5 , V_7 , V_8 ,
V_11 , V_9 , V_10 ) ;
return - V_46 ;
}
static int F_13 ( struct V_3 * V_4 ,
struct V_47 * V_48 , void * V_49 )
{
int V_50 ;
for ( V_50 = 0 ; V_50 < 4 ; V_50 ++ ) {
T_2 V_16 = F_3 ( V_4 -> V_51 + F_14 ( V_50 ) ) ;
T_2 V_52 = F_3 ( V_4 -> V_51 + F_15 ( V_50 ) ) ;
T_1 V_7 ;
T_2 V_8 ;
if ( ! ( V_52 & V_53 ) ) {
F_16 ( V_48 , L_3 , V_50 ) ;
continue;
}
V_7 = ( ( T_1 ) V_16 & V_54 ) << 32 ;
V_7 |= V_16 & V_55 ;
V_8 = ( V_52 | ~ V_56 ) ;
F_16 ( V_48 , L_4 ,
V_50 , ( unsigned long long ) V_7 ,
( unsigned long long ) V_7 + V_8 + 1 ,
( V_52 & V_57 ) >> V_58 ) ;
}
return 0 ;
}
static int F_17 ( struct V_3 * V_4 ,
struct V_47 * V_48 , void * V_49 )
{
int V_50 ;
for ( V_50 = 0 ; V_50 < 2 ; V_50 ++ ) {
T_2 V_59 = F_3 ( V_4 -> V_51 + F_18 ( V_50 ) ) ;
T_1 V_7 ;
T_2 V_8 ;
if ( ! ( V_59 & 1 ) ) {
F_16 ( V_48 , L_3 , V_50 ) ;
continue;
}
V_7 = V_59 & 0xff800000 ;
V_8 = 0x100000 << ( ( ( V_59 & 0x000f0000 ) >> 16 ) - 4 ) ;
F_16 ( V_48 , L_4 ,
V_50 , ( unsigned long long ) V_7 ,
( unsigned long long ) V_7 + V_8 , V_50 ) ;
}
return 0 ;
}
static int F_19 ( struct V_47 * V_48 , void * V_49 )
{
struct V_3 * V_4 = & V_60 ;
return V_4 -> V_14 -> V_61 ( V_4 , V_48 , V_49 ) ;
}
static int F_20 ( struct V_62 * V_62 , struct V_63 * V_63 )
{
return F_21 ( V_63 , F_19 , V_62 -> V_64 ) ;
}
static int F_22 ( struct V_47 * V_48 , void * V_49 )
{
struct V_3 * V_4 = & V_60 ;
int V_5 ;
for ( V_5 = 0 ; V_5 < V_4 -> V_14 -> V_35 ; V_5 ++ ) {
T_1 V_36 , V_65 ;
T_2 V_38 ;
T_3 V_39 , V_40 ;
int V_6 ;
F_2 ( V_4 , V_5 ,
& V_6 , & V_36 , & V_38 ,
& V_39 , & V_40 , & V_65 ) ;
if ( ! V_6 ) {
F_16 ( V_48 , L_5 , V_5 ) ;
continue;
}
F_16 ( V_48 , L_6 ,
V_5 , ( unsigned long long ) V_36 ,
( unsigned long long ) ( V_36 + V_38 ) , V_39 , V_40 ) ;
if ( ! F_10 ( V_38 ) ||
( ( V_36 & ( T_1 ) ( V_38 - 1 ) ) != 0 ) )
F_23 ( V_48 , L_7 ) ;
if ( V_5 < V_4 -> V_14 -> V_28 ) {
F_16 ( V_48 , L_8 ,
( unsigned long long ) V_65 ) ;
} else
F_16 ( V_48 , L_9 ) ;
}
return 0 ;
}
static int F_24 ( struct V_62 * V_62 , struct V_63 * V_63 )
{
return F_21 ( V_63 , F_22 , V_62 -> V_64 ) ;
}
static unsigned int F_25 ( int V_5 )
{
return V_5 << 4 ;
}
static unsigned int F_26 ( int V_5 )
{
if ( V_5 < 8 )
return V_5 << 4 ;
else
return 0x90 + ( ( V_5 - 8 ) << 3 ) ;
}
static unsigned int F_27 ( int V_5 )
{
if ( V_5 < 8 )
return V_5 << 4 ;
else
return 0x900 + ( ( V_5 - 8 ) << 4 ) ;
}
static void T_7
F_28 ( struct V_3 * V_4 )
{
int V_50 ;
int V_66 ;
V_2 . V_67 = V_68 ;
for ( V_50 = 0 , V_66 = 0 ; V_50 < 4 ; V_50 ++ ) {
T_2 V_7 = F_3 ( V_4 -> V_51 + F_14 ( V_50 ) ) ;
T_2 V_8 = F_3 ( V_4 -> V_51 + F_15 ( V_50 ) ) ;
if ( ( V_8 & V_53 ) &&
! ( V_7 & V_54 ) ) {
struct V_69 * V_70 ;
V_70 = & V_2 . V_66 [ V_66 ++ ] ;
V_70 -> V_71 = V_50 ;
V_70 -> V_72 = 0xf & ~ ( 1 << V_50 ) ;
if ( V_4 -> V_73 )
V_70 -> V_72 |= V_74 ;
V_70 -> V_7 = V_7 & V_55 ;
V_70 -> V_8 = ( V_8 | ~ V_56 ) + 1 ;
}
}
V_2 . V_75 = V_66 ;
}
static int
F_29 ( struct V_3 * V_4 ,
T_2 * V_76 )
{
int V_50 ;
for ( V_50 = 0 ; V_50 < 4 ; V_50 ++ ) {
T_2 V_7 = F_3 ( V_4 -> V_51 + F_14 ( V_50 ) ) ;
T_2 V_8 = F_3 ( V_4 -> V_51 + F_15 ( V_50 ) ) ;
F_5 ( V_4 -> V_77 + F_14 ( V_50 ) ,
V_76 ++ ) ;
F_5 ( V_7 , V_76 ++ ) ;
F_5 ( V_4 -> V_77 + F_15 ( V_50 ) ,
V_76 ++ ) ;
F_5 ( V_8 , V_76 ++ ) ;
}
return 16 ;
}
static void T_7
F_30 ( struct V_3 * V_4 )
{
int V_50 ;
int V_66 ;
V_2 . V_67 = V_68 ;
for ( V_50 = 0 , V_66 = 0 ; V_50 < 2 ; V_50 ++ ) {
T_2 V_59 = F_3 ( V_4 -> V_51 + F_18 ( V_50 ) ) ;
if ( V_59 & 1 ) {
struct V_69 * V_70 ;
V_70 = & V_2 . V_66 [ V_66 ++ ] ;
V_70 -> V_71 = V_50 ;
V_70 -> V_72 = 0 ;
V_70 -> V_7 = V_59 & 0xff800000 ;
V_70 -> V_8 = 0x100000 << ( ( ( V_59 & 0x000f0000 ) >> 16 ) - 4 ) ;
}
}
V_2 . V_75 = V_66 ;
}
static int
F_31 ( struct V_3 * V_4 ,
T_2 * V_76 )
{
int V_50 ;
for ( V_50 = 0 ; V_50 < 2 ; V_50 ++ ) {
T_2 V_59 = F_3 ( V_4 -> V_51 + F_18 ( V_50 ) ) ;
F_5 ( V_4 -> V_77 + F_18 ( V_50 ) ,
V_76 ++ ) ;
F_5 ( V_59 , V_76 ++ ) ;
}
return 4 ;
}
int F_32 ( T_2 * V_76 )
{
return V_60 . V_14 -> V_78 ( & V_60 , V_76 ) ;
}
int F_33 ( unsigned int V_9 ,
unsigned int V_79 ,
T_5 V_7 , T_6 V_8 ,
T_5 V_11 )
{
struct V_3 * V_80 = & V_60 ;
if ( ! F_7 ( V_80 , V_7 , V_8 , V_9 , V_79 ) ) {
F_34 ( L_10 ,
V_9 , V_79 ) ;
return - V_43 ;
}
return F_12 ( V_80 , V_7 , V_8 , V_11 , V_9 , V_79 ) ;
}
int F_35 ( unsigned int V_9 , unsigned int V_79 ,
T_5 V_7 , T_6 V_8 )
{
return F_33 ( V_9 , V_79 , V_7 ,
V_8 , V_44 ) ;
}
int F_36 ( T_5 V_7 , T_6 V_8 )
{
int V_5 ;
V_5 = F_8 ( & V_60 , V_7 , V_8 ) ;
if ( V_5 < 0 )
return V_5 ;
F_4 ( & V_60 , V_5 ) ;
return 0 ;
}
void F_37 ( struct V_81 * V_82 )
{
if ( ! V_82 )
return;
* V_82 = V_60 . V_83 ;
}
void F_38 ( struct V_81 * V_82 )
{
if ( ! V_82 )
return;
* V_82 = V_60 . V_84 ;
}
static T_7 int F_39 ( void )
{
struct V_3 * V_80 = & V_60 ;
if ( ! V_80 -> V_13 )
return 0 ;
V_80 -> V_85 = F_40 ( L_11 , NULL ) ;
if ( V_80 -> V_85 ) {
V_80 -> V_86 = F_41 ( L_12 , V_87 ,
V_80 -> V_85 , NULL ,
& V_88 ) ;
V_80 -> V_89 = F_41 ( L_13 , V_87 ,
V_80 -> V_85 , NULL ,
& V_90 ) ;
}
return 0 ;
}
static int F_42 ( void )
{
struct V_3 * V_80 = & V_60 ;
int V_5 ;
if ( ! V_80 -> V_91 )
return - V_41 ;
for ( V_5 = 0 ; V_5 < V_80 -> V_14 -> V_35 ; V_5 ++ ) {
void T_4 * V_12 = V_80 -> V_13 +
V_80 -> V_14 -> V_15 ( V_5 ) ;
V_80 -> V_92 [ V_5 ] . V_7 = F_3 ( V_12 + V_17 ) ;
V_80 -> V_92 [ V_5 ] . V_33 = F_3 ( V_12 + V_19 ) ;
if ( V_5 >= V_80 -> V_14 -> V_28 )
continue;
V_80 -> V_92 [ V_5 ] . V_93 = F_3 ( V_12 + V_30 ) ;
V_80 -> V_92 [ V_5 ] . V_31 = F_3 ( V_12 + V_32 ) ;
}
V_80 -> V_94 = F_3 ( V_80 -> V_91 +
V_95 ) ;
V_80 -> V_96 = F_3 ( V_80 -> V_91 +
V_97 ) ;
return 0 ;
}
static void F_43 ( void )
{
struct V_3 * V_80 = & V_60 ;
int V_5 ;
F_5 ( V_80 -> V_94 ,
V_80 -> V_91 + V_95 ) ;
F_5 ( V_80 -> V_96 ,
V_80 -> V_91 + V_97 ) ;
for ( V_5 = 0 ; V_5 < V_80 -> V_14 -> V_35 ; V_5 ++ ) {
void T_4 * V_12 = V_80 -> V_13 +
V_80 -> V_14 -> V_15 ( V_5 ) ;
F_5 ( V_80 -> V_92 [ V_5 ] . V_7 , V_12 + V_17 ) ;
F_5 ( V_80 -> V_92 [ V_5 ] . V_33 , V_12 + V_19 ) ;
if ( V_5 >= V_80 -> V_14 -> V_28 )
continue;
F_5 ( V_80 -> V_92 [ V_5 ] . V_93 , V_12 + V_30 ) ;
F_5 ( V_80 -> V_92 [ V_5 ] . V_31 , V_12 + V_32 ) ;
}
}
static int T_7 F_44 ( struct V_3 * V_4 ,
T_5 V_98 ,
T_6 V_99 ,
T_5 V_77 ,
T_6 V_100 ,
T_5 V_101 ,
T_6 V_102 )
{
int V_5 ;
V_4 -> V_13 = F_45 ( V_98 , V_99 ) ;
if ( ! V_4 -> V_13 )
return - V_46 ;
V_4 -> V_51 = F_45 ( V_77 , V_100 ) ;
if ( ! V_4 -> V_51 ) {
F_46 ( V_60 . V_13 ) ;
return - V_46 ;
}
V_4 -> V_77 = V_77 ;
if ( V_101 ) {
V_4 -> V_91 = F_45 ( V_101 ,
V_102 ) ;
if ( ! V_4 -> V_91 ) {
F_46 ( V_4 -> V_51 ) ;
F_46 ( V_4 -> V_13 ) ;
return - V_46 ;
}
} else
V_4 -> V_91 = NULL ;
for ( V_5 = 0 ; V_5 < V_4 -> V_14 -> V_35 ; V_5 ++ )
F_4 ( V_4 , V_5 ) ;
V_4 -> V_14 -> V_103 ( V_4 ) ;
F_47 ( & V_104 ) ;
return 0 ;
}
int T_7 F_48 ( const char * V_14 , T_5 V_98 ,
T_6 V_99 ,
T_5 V_77 ,
T_6 V_100 )
{
const struct V_105 * V_106 ;
for ( V_106 = V_107 ; V_106 -> V_108 [ 0 ] ; V_106 ++ )
if ( ! strcmp ( V_106 -> V_108 , V_14 ) )
break;
if ( ! V_106 -> V_108 [ 0 ] ) {
F_34 ( L_14 ) ;
return - V_41 ;
}
V_60 . V_14 = V_106 -> V_109 ;
return F_44 ( & V_60 ,
V_98 ,
V_99 ,
V_77 ,
V_100 , 0 , 0 ) ;
}
static int T_7 F_49 ( struct V_3 * V_4 ,
T_2 V_7 , T_2 V_8 ,
T_3 V_9 , T_3 V_10 )
{
if ( ! F_7 ( V_4 , V_7 , V_8 , V_9 , V_10 ) ) {
F_34 ( L_15 ,
V_9 , V_10 ) ;
return - V_110 ;
}
if ( F_12 ( V_4 , V_7 , V_8 , V_44 ,
V_9 , V_10 ) ) {
F_34 ( L_16 ,
V_9 , V_10 ) ;
return - V_46 ;
}
return 0 ;
}
static int T_7
F_50 ( struct V_111 * V_112 ,
int * V_113 , int * V_114 , int * V_115 ,
int * V_116 , const T_8 * * V_117 ,
const T_8 * * V_118 )
{
const T_8 * V_119 ;
int V_120 , V_121 ;
* V_117 = F_51 ( V_112 , L_17 , & V_120 ) ;
if ( * V_117 == NULL ) {
* V_113 = * V_114 = * V_115 = * V_116 = 0 ;
* V_117 = * V_118 = NULL ;
return 0 ;
}
* V_118 = * V_117 + V_120 / sizeof( T_8 ) ;
* V_113 = F_52 ( V_112 ) ;
V_119 = F_51 ( V_112 , L_18 , NULL ) ;
* V_114 = F_53 ( V_119 ) ;
V_119 = F_51 ( V_112 , L_19 , NULL ) ;
* V_115 = F_53 ( V_119 ) ;
* V_116 = * V_113 + * V_114 + * V_115 ;
V_121 = ( * V_116 ) * sizeof( T_8 ) ;
if ( V_120 % V_121 ) {
F_54 ( L_20 , V_112 -> V_122 ) ;
return - V_43 ;
}
return 0 ;
}
static int T_7 F_55 ( struct V_3 * V_4 ,
struct V_111 * V_123 )
{
int V_113 , V_114 , V_115 ;
int V_50 , V_124 , V_116 ;
const T_8 * V_125 , * V_117 , * V_118 ;
V_124 = F_50 ( V_123 , & V_113 , & V_114 ,
& V_115 , & V_116 ,
& V_117 , & V_118 ) ;
if ( V_124 < 0 )
return V_124 ;
for ( V_50 = 0 , V_125 = V_117 ; V_125 < V_118 ; V_125 += V_116 , V_50 ++ ) {
T_2 V_126 , V_7 , V_8 ;
T_3 V_9 , V_10 ;
V_126 = F_56 ( V_125 , 1 ) ;
if ( F_57 ( V_126 ) )
continue;
V_9 = F_58 ( V_126 ) ;
V_10 = F_59 ( V_126 ) ;
V_7 = F_56 ( V_125 + V_114 , V_113 ) ;
V_8 = F_56 ( V_125 + V_114 + V_113 ,
V_115 ) ;
V_124 = F_49 ( V_4 , V_7 , V_8 , V_9 , V_10 ) ;
if ( V_124 < 0 )
return V_124 ;
}
return 0 ;
}
static void T_7 F_60 ( struct V_111 * V_123 ,
struct V_81 * V_127 ,
struct V_81 * V_128 )
{
T_2 V_129 [ 2 ] ;
int V_124 ;
memset ( V_127 , 0 , sizeof( struct V_81 ) ) ;
V_127 -> V_34 = - 1 ;
memset ( V_128 , 0 , sizeof( struct V_81 ) ) ;
V_128 -> V_34 = - 1 ;
V_124 = F_61 ( V_123 , L_21 , V_129 , F_62 ( V_129 ) ) ;
if ( ! V_124 ) {
V_127 -> V_130 = V_129 [ 0 ] ;
V_127 -> V_34 = V_127 -> V_130 + V_129 [ 1 ] - 1 ;
V_127 -> V_131 = V_132 ;
}
V_124 = F_61 ( V_123 , L_22 , V_129 , F_62 ( V_129 ) ) ;
if ( ! V_124 ) {
V_128 -> V_130 = V_129 [ 0 ] ;
V_128 -> V_34 = V_128 -> V_130 + V_129 [ 1 ] - 1 ;
V_128 -> V_131 = V_133 ;
}
}
int T_7 F_63 ( bool V_134 )
{
struct V_81 V_135 , V_136 , V_137 ;
struct V_111 * V_123 , * V_138 ;
const struct V_105 * V_106 ;
const T_8 * V_119 ;
int V_124 ;
V_123 = F_64 ( NULL , V_107 , & V_106 ) ;
if ( ! V_123 ) {
F_34 ( L_14 ) ;
return - V_41 ;
}
V_60 . V_14 = V_106 -> V_109 ;
V_119 = F_51 ( V_123 , L_23 , NULL ) ;
if ( ! V_119 ) {
F_34 ( L_24 ) ;
return - V_43 ;
}
V_138 = F_65 ( F_53 ( V_119 ) ) ;
if ( ! V_138 ) {
F_34 ( L_25 ) ;
return - V_41 ;
}
if ( F_66 ( V_138 , 0 , & V_135 ) ) {
F_34 ( L_26 ) ;
return - V_43 ;
}
if ( F_66 ( V_138 , 1 , & V_136 ) ) {
F_34 ( L_27 ) ;
return - V_43 ;
}
memset ( & V_137 , 0 , sizeof( V_137 ) ) ;
if ( V_60 . V_14 -> V_139 ) {
if ( F_66 ( V_138 , 2 , & V_137 ) )
F_54 ( V_140 L_28 ) ;
}
V_60 . V_73 = V_134 ;
F_60 ( V_123 , & V_60 . V_83 ,
& V_60 . V_84 ) ;
V_124 = F_44 ( & V_60 ,
V_135 . V_130 ,
F_67 ( & V_135 ) ,
V_136 . V_130 ,
F_67 ( & V_136 ) ,
V_137 . V_130 ,
F_67 ( & V_137 ) ) ;
if ( V_124 )
return V_124 ;
return F_55 ( & V_60 , V_123 ) ;
}
