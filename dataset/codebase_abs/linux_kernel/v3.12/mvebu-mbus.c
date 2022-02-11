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
if ( V_9 == V_39 && V_10 == V_40 )
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
V_33 = ( ( V_8 - 1 ) & V_23 ) |
( V_10 << V_27 ) |
( V_9 << V_25 ) |
V_20 ;
F_5 ( V_7 & V_22 , V_12 + V_17 ) ;
F_5 ( V_33 , V_12 + V_19 ) ;
if ( V_5 < V_4 -> V_14 -> V_28 ) {
if ( V_11 == V_43 )
V_42 = V_7 ;
else
V_42 = V_11 ;
F_5 ( V_42 & V_44 , V_12 + V_30 ) ;
F_5 ( 0 , V_12 + V_32 ) ;
}
return 0 ;
}
static int F_10 ( struct V_3 * V_4 ,
T_5 V_7 , T_6 V_8 ,
T_5 V_11 , T_3 V_9 ,
T_3 V_10 )
{
int V_5 ;
if ( V_11 == V_43 ) {
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
return - V_45 ;
}
static int F_11 ( struct V_3 * V_4 ,
struct V_46 * V_47 , void * V_48 )
{
int V_49 ;
for ( V_49 = 0 ; V_49 < 4 ; V_49 ++ ) {
T_2 V_16 = F_3 ( V_4 -> V_50 + F_12 ( V_49 ) ) ;
T_2 V_51 = F_3 ( V_4 -> V_50 + F_13 ( V_49 ) ) ;
T_1 V_7 ;
T_2 V_8 ;
if ( ! ( V_51 & V_52 ) ) {
F_14 ( V_47 , L_1 , V_49 ) ;
continue;
}
V_7 = ( ( T_1 ) V_16 & V_53 ) << 32 ;
V_7 |= V_16 & V_54 ;
V_8 = ( V_51 | ~ V_55 ) ;
F_14 ( V_47 , L_2 ,
V_49 , ( unsigned long long ) V_7 ,
( unsigned long long ) V_7 + V_8 + 1 ,
( V_51 & V_56 ) >> V_57 ) ;
}
return 0 ;
}
static int F_15 ( struct V_3 * V_4 ,
struct V_46 * V_47 , void * V_48 )
{
int V_49 ;
for ( V_49 = 0 ; V_49 < 2 ; V_49 ++ ) {
T_2 V_58 = F_3 ( V_4 -> V_50 + F_16 ( V_49 ) ) ;
T_1 V_7 ;
T_2 V_8 ;
if ( ! ( V_58 & 1 ) ) {
F_14 ( V_47 , L_1 , V_49 ) ;
continue;
}
V_7 = V_58 & 0xff800000 ;
V_8 = 0x100000 << ( ( ( V_58 & 0x000f0000 ) >> 16 ) - 4 ) ;
F_14 ( V_47 , L_2 ,
V_49 , ( unsigned long long ) V_7 ,
( unsigned long long ) V_7 + V_8 , V_49 ) ;
}
return 0 ;
}
static int F_17 ( struct V_46 * V_47 , void * V_48 )
{
struct V_3 * V_4 = & V_59 ;
return V_4 -> V_14 -> V_60 ( V_4 , V_47 , V_48 ) ;
}
static int F_18 ( struct V_61 * V_61 , struct V_62 * V_62 )
{
return F_19 ( V_62 , F_17 , V_61 -> V_63 ) ;
}
static int F_20 ( struct V_46 * V_47 , void * V_48 )
{
struct V_3 * V_4 = & V_59 ;
int V_5 ;
for ( V_5 = 0 ; V_5 < V_4 -> V_14 -> V_35 ; V_5 ++ ) {
T_1 V_36 , V_64 ;
T_2 V_38 ;
T_3 V_39 , V_40 ;
int V_6 ;
F_2 ( V_4 , V_5 ,
& V_6 , & V_36 , & V_38 ,
& V_39 , & V_40 , & V_64 ) ;
if ( ! V_6 ) {
F_14 ( V_47 , L_3 , V_5 ) ;
continue;
}
F_14 ( V_47 , L_4 ,
V_5 , ( unsigned long long ) V_36 ,
( unsigned long long ) ( V_36 + V_38 ) , V_39 , V_40 ) ;
if ( V_5 < V_4 -> V_14 -> V_28 ) {
F_14 ( V_47 , L_5 ,
( unsigned long long ) V_64 ) ;
} else
F_14 ( V_47 , L_6 ) ;
}
return 0 ;
}
static int F_21 ( struct V_61 * V_61 , struct V_62 * V_62 )
{
return F_19 ( V_62 , F_20 , V_61 -> V_63 ) ;
}
static unsigned int F_22 ( int V_5 )
{
return V_5 << 4 ;
}
static unsigned int F_23 ( int V_5 )
{
if ( V_5 < 8 )
return V_5 << 4 ;
else
return 0x90 + ( ( V_5 - 8 ) << 3 ) ;
}
static unsigned int F_24 ( int V_5 )
{
if ( V_5 < 8 )
return V_5 << 4 ;
else
return 0x900 + ( ( V_5 - 8 ) << 4 ) ;
}
static void T_7
F_25 ( struct V_3 * V_4 )
{
int V_49 ;
int V_65 ;
V_2 . V_66 = V_67 ;
for ( V_49 = 0 , V_65 = 0 ; V_49 < 4 ; V_49 ++ ) {
T_2 V_7 = F_3 ( V_4 -> V_50 + F_12 ( V_49 ) ) ;
T_2 V_8 = F_3 ( V_4 -> V_50 + F_13 ( V_49 ) ) ;
if ( ( V_8 & V_52 ) &&
! ( V_7 & V_53 ) ) {
struct V_68 * V_69 ;
V_69 = & V_2 . V_65 [ V_65 ++ ] ;
V_69 -> V_70 = V_49 ;
V_69 -> V_71 = 0xf & ~ ( 1 << V_49 ) ;
if ( V_4 -> V_72 )
V_69 -> V_71 |= V_73 ;
V_69 -> V_7 = V_7 & V_54 ;
V_69 -> V_8 = ( V_8 | ~ V_55 ) + 1 ;
}
}
V_2 . V_74 = V_65 ;
}
static void T_7
F_26 ( struct V_3 * V_4 )
{
int V_49 ;
int V_65 ;
V_2 . V_66 = V_67 ;
for ( V_49 = 0 , V_65 = 0 ; V_49 < 2 ; V_49 ++ ) {
T_2 V_58 = F_3 ( V_4 -> V_50 + F_16 ( V_49 ) ) ;
if ( V_58 & 1 ) {
struct V_68 * V_69 ;
V_69 = & V_2 . V_65 [ V_65 ++ ] ;
V_69 -> V_70 = V_49 ;
V_69 -> V_71 = 0 ;
V_69 -> V_7 = V_58 & 0xff800000 ;
V_69 -> V_8 = 0x100000 << ( ( ( V_58 & 0x000f0000 ) >> 16 ) - 4 ) ;
}
}
V_2 . V_74 = V_65 ;
}
int F_27 ( unsigned int V_9 ,
unsigned int V_75 ,
T_5 V_7 , T_6 V_8 ,
T_5 V_11 )
{
struct V_3 * V_76 = & V_59 ;
if ( ! F_7 ( V_76 , V_7 , V_8 , V_9 , V_75 ) ) {
F_28 ( L_7 ,
V_9 , V_75 ) ;
return - V_77 ;
}
return F_10 ( V_76 , V_7 , V_8 , V_11 , V_9 , V_75 ) ;
}
int F_29 ( unsigned int V_9 , unsigned int V_75 ,
T_5 V_7 , T_6 V_8 )
{
return F_27 ( V_9 , V_75 , V_7 ,
V_8 , V_43 ) ;
}
int F_30 ( T_5 V_7 , T_6 V_8 )
{
int V_5 ;
V_5 = F_8 ( & V_59 , V_7 , V_8 ) ;
if ( V_5 < 0 )
return V_5 ;
F_4 ( & V_59 , V_5 ) ;
return 0 ;
}
void F_31 ( struct V_78 * V_79 )
{
if ( ! V_79 )
return;
* V_79 = V_59 . V_80 ;
}
void F_32 ( struct V_78 * V_79 )
{
if ( ! V_79 )
return;
* V_79 = V_59 . V_81 ;
}
static T_7 int F_33 ( void )
{
struct V_3 * V_76 = & V_59 ;
if ( ! V_76 -> V_13 )
return 0 ;
V_76 -> V_82 = F_34 ( L_8 , NULL ) ;
if ( V_76 -> V_82 ) {
V_76 -> V_83 = F_35 ( L_9 , V_84 ,
V_76 -> V_82 , NULL ,
& V_85 ) ;
V_76 -> V_86 = F_35 ( L_10 , V_84 ,
V_76 -> V_82 , NULL ,
& V_87 ) ;
}
return 0 ;
}
static int T_7 F_36 ( struct V_3 * V_4 ,
T_5 V_88 ,
T_6 V_89 ,
T_5 V_90 ,
T_6 V_91 )
{
struct V_92 * V_93 ;
int V_5 ;
V_4 -> V_13 = F_37 ( V_88 , V_89 ) ;
if ( ! V_4 -> V_13 )
return - V_45 ;
V_4 -> V_50 = F_37 ( V_90 , V_91 ) ;
if ( ! V_4 -> V_50 ) {
F_38 ( V_59 . V_13 ) ;
return - V_45 ;
}
V_93 = F_39 ( NULL , NULL , L_11 ) ;
if ( V_93 ) {
V_4 -> V_72 = 1 ;
F_40 ( V_93 ) ;
}
for ( V_5 = 0 ; V_5 < V_4 -> V_14 -> V_35 ; V_5 ++ )
F_4 ( V_4 , V_5 ) ;
V_4 -> V_14 -> V_94 ( V_4 ) ;
return 0 ;
}
int T_7 F_41 ( const char * V_14 , T_5 V_88 ,
T_6 V_89 ,
T_5 V_90 ,
T_6 V_91 )
{
const struct V_95 * V_96 ;
for ( V_96 = V_97 ; V_96 -> V_98 ; V_96 ++ )
if ( ! strcmp ( V_96 -> V_98 , V_14 ) )
break;
if ( ! V_96 -> V_98 ) {
F_28 ( L_12 ) ;
return - V_41 ;
}
V_59 . V_14 = V_96 -> V_99 ;
return F_36 ( & V_59 ,
V_88 ,
V_89 ,
V_90 ,
V_91 ) ;
}
static int T_7 F_42 ( struct V_3 * V_4 ,
T_2 V_7 , T_2 V_8 ,
T_3 V_9 , T_3 V_10 )
{
if ( ! F_7 ( V_4 , V_7 , V_8 , V_9 , V_10 ) ) {
F_28 ( L_13 ,
V_9 , V_10 ) ;
return - V_100 ;
}
if ( F_10 ( V_4 , V_7 , V_8 , V_43 ,
V_9 , V_10 ) ) {
F_28 ( L_14 ,
V_9 , V_10 ) ;
return - V_45 ;
}
return 0 ;
}
static int T_7
F_43 ( struct V_92 * V_101 ,
int * V_102 , int * V_103 , int * V_104 ,
int * V_105 , const T_8 * * V_106 ,
const T_8 * * V_107 )
{
const T_8 * V_108 ;
int V_109 , V_110 ;
* V_106 = F_44 ( V_101 , L_15 , & V_109 ) ;
if ( * V_106 == NULL ) {
* V_102 = * V_103 = * V_104 = * V_105 = 0 ;
* V_106 = * V_107 = NULL ;
return 0 ;
}
* V_107 = * V_106 + V_109 / sizeof( T_8 ) ;
* V_102 = F_45 ( V_101 ) ;
V_108 = F_44 ( V_101 , L_16 , NULL ) ;
* V_103 = F_46 ( V_108 ) ;
V_108 = F_44 ( V_101 , L_17 , NULL ) ;
* V_104 = F_46 ( V_108 ) ;
* V_105 = * V_102 + * V_103 + * V_104 ;
V_110 = ( * V_105 ) * sizeof( T_8 ) ;
if ( V_109 % V_110 ) {
F_47 ( L_18 , V_101 -> V_111 ) ;
return - V_77 ;
}
return 0 ;
}
static int T_7 F_48 ( struct V_3 * V_4 ,
struct V_92 * V_93 )
{
int V_102 , V_103 , V_104 ;
int V_49 , V_112 , V_105 ;
const T_8 * V_113 , * V_106 , * V_107 ;
V_112 = F_43 ( V_93 , & V_102 , & V_103 ,
& V_104 , & V_105 ,
& V_106 , & V_107 ) ;
if ( V_112 < 0 )
return V_112 ;
for ( V_49 = 0 , V_113 = V_106 ; V_113 < V_107 ; V_113 += V_105 , V_49 ++ ) {
T_2 V_114 , V_7 , V_8 ;
T_3 V_9 , V_10 ;
V_114 = F_49 ( V_113 , 1 ) ;
if ( F_50 ( V_114 ) )
continue;
V_9 = F_51 ( V_114 ) ;
V_10 = F_52 ( V_114 ) ;
V_7 = F_49 ( V_113 + V_103 , V_102 ) ;
V_8 = F_49 ( V_113 + V_103 + V_102 ,
V_104 ) ;
V_112 = F_42 ( V_4 , V_7 , V_8 , V_9 , V_10 ) ;
if ( V_112 < 0 )
return V_112 ;
}
return 0 ;
}
static void T_7 F_53 ( struct V_92 * V_93 ,
struct V_78 * V_115 ,
struct V_78 * V_116 )
{
T_2 V_117 [ 2 ] ;
int V_112 ;
memset ( V_115 , 0 , sizeof( struct V_78 ) ) ;
V_115 -> V_34 = - 1 ;
memset ( V_116 , 0 , sizeof( struct V_78 ) ) ;
V_116 -> V_34 = - 1 ;
V_112 = F_54 ( V_93 , L_19 , V_117 , F_55 ( V_117 ) ) ;
if ( ! V_112 ) {
V_115 -> V_118 = V_117 [ 0 ] ;
V_115 -> V_34 = V_115 -> V_118 + V_117 [ 1 ] ;
V_115 -> V_119 = V_120 ;
}
V_112 = F_54 ( V_93 , L_20 , V_117 , F_55 ( V_117 ) ) ;
if ( ! V_112 ) {
V_116 -> V_118 = V_117 [ 0 ] ;
V_116 -> V_34 = V_116 -> V_118 + V_117 [ 1 ] ;
V_116 -> V_119 = V_121 ;
}
}
int T_7 F_56 ( void )
{
struct V_78 V_122 , V_123 ;
struct V_92 * V_93 , * V_124 ;
const struct V_95 * V_96 ;
const T_8 * V_108 ;
int V_112 ;
V_93 = F_57 ( NULL , V_97 ) ;
if ( ! V_93 ) {
F_28 ( L_12 ) ;
return - V_41 ;
}
V_96 = F_58 ( V_97 , V_93 ) ;
V_59 . V_14 = V_96 -> V_99 ;
V_108 = F_44 ( V_93 , L_21 , NULL ) ;
if ( ! V_108 ) {
F_28 ( L_22 ) ;
return - V_77 ;
}
V_124 = F_59 ( F_46 ( V_108 ) ) ;
if ( ! V_124 ) {
F_28 ( L_23 ) ;
return - V_41 ;
}
if ( F_60 ( V_124 , 0 , & V_122 ) ) {
F_28 ( L_24 ) ;
return - V_77 ;
}
if ( F_60 ( V_124 , 1 , & V_123 ) ) {
F_28 ( L_25 ) ;
return - V_77 ;
}
F_53 ( V_93 , & V_59 . V_80 ,
& V_59 . V_81 ) ;
V_112 = F_36 ( & V_59 ,
V_122 . V_118 ,
F_61 ( & V_122 ) ,
V_123 . V_118 ,
F_61 ( & V_123 ) ) ;
if ( V_112 )
return V_112 ;
return F_48 ( & V_59 , V_93 ) ;
}
