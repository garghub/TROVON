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
static void T_7
F_29 ( struct V_3 * V_4 )
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
int F_30 ( unsigned int V_9 ,
unsigned int V_76 ,
T_5 V_7 , T_6 V_8 ,
T_5 V_11 )
{
struct V_3 * V_77 = & V_60 ;
if ( ! F_7 ( V_77 , V_7 , V_8 , V_9 , V_76 ) ) {
F_31 ( L_10 ,
V_9 , V_76 ) ;
return - V_43 ;
}
return F_12 ( V_77 , V_7 , V_8 , V_11 , V_9 , V_76 ) ;
}
int F_32 ( unsigned int V_9 , unsigned int V_76 ,
T_5 V_7 , T_6 V_8 )
{
return F_30 ( V_9 , V_76 , V_7 ,
V_8 , V_44 ) ;
}
int F_33 ( T_5 V_7 , T_6 V_8 )
{
int V_5 ;
V_5 = F_8 ( & V_60 , V_7 , V_8 ) ;
if ( V_5 < 0 )
return V_5 ;
F_4 ( & V_60 , V_5 ) ;
return 0 ;
}
void F_34 ( struct V_78 * V_79 )
{
if ( ! V_79 )
return;
* V_79 = V_60 . V_80 ;
}
void F_35 ( struct V_78 * V_79 )
{
if ( ! V_79 )
return;
* V_79 = V_60 . V_81 ;
}
static T_7 int F_36 ( void )
{
struct V_3 * V_77 = & V_60 ;
if ( ! V_77 -> V_13 )
return 0 ;
V_77 -> V_82 = F_37 ( L_11 , NULL ) ;
if ( V_77 -> V_82 ) {
V_77 -> V_83 = F_38 ( L_12 , V_84 ,
V_77 -> V_82 , NULL ,
& V_85 ) ;
V_77 -> V_86 = F_38 ( L_13 , V_84 ,
V_77 -> V_82 , NULL ,
& V_87 ) ;
}
return 0 ;
}
static int T_7 F_39 ( struct V_3 * V_4 ,
T_5 V_88 ,
T_6 V_89 ,
T_5 V_90 ,
T_6 V_91 )
{
struct V_92 * V_93 ;
int V_5 ;
V_4 -> V_13 = F_40 ( V_88 , V_89 ) ;
if ( ! V_4 -> V_13 )
return - V_46 ;
V_4 -> V_51 = F_40 ( V_90 , V_91 ) ;
if ( ! V_4 -> V_51 ) {
F_41 ( V_60 . V_13 ) ;
return - V_46 ;
}
V_93 = F_42 ( NULL , NULL , L_14 ) ;
if ( V_93 ) {
V_4 -> V_73 = 1 ;
F_43 ( V_93 ) ;
}
for ( V_5 = 0 ; V_5 < V_4 -> V_14 -> V_35 ; V_5 ++ )
F_4 ( V_4 , V_5 ) ;
V_4 -> V_14 -> V_94 ( V_4 ) ;
return 0 ;
}
int T_7 F_44 ( const char * V_14 , T_5 V_88 ,
T_6 V_89 ,
T_5 V_90 ,
T_6 V_91 )
{
const struct V_95 * V_96 ;
for ( V_96 = V_97 ; V_96 -> V_98 [ 0 ] ; V_96 ++ )
if ( ! strcmp ( V_96 -> V_98 , V_14 ) )
break;
if ( ! V_96 -> V_98 [ 0 ] ) {
F_31 ( L_15 ) ;
return - V_41 ;
}
V_60 . V_14 = V_96 -> V_99 ;
return F_39 ( & V_60 ,
V_88 ,
V_89 ,
V_90 ,
V_91 ) ;
}
static int T_7 F_45 ( struct V_3 * V_4 ,
T_2 V_7 , T_2 V_8 ,
T_3 V_9 , T_3 V_10 )
{
if ( ! F_7 ( V_4 , V_7 , V_8 , V_9 , V_10 ) ) {
F_31 ( L_16 ,
V_9 , V_10 ) ;
return - V_100 ;
}
if ( F_12 ( V_4 , V_7 , V_8 , V_44 ,
V_9 , V_10 ) ) {
F_31 ( L_17 ,
V_9 , V_10 ) ;
return - V_46 ;
}
return 0 ;
}
static int T_7
F_46 ( struct V_92 * V_101 ,
int * V_102 , int * V_103 , int * V_104 ,
int * V_105 , const T_8 * * V_106 ,
const T_8 * * V_107 )
{
const T_8 * V_108 ;
int V_109 , V_110 ;
* V_106 = F_47 ( V_101 , L_18 , & V_109 ) ;
if ( * V_106 == NULL ) {
* V_102 = * V_103 = * V_104 = * V_105 = 0 ;
* V_106 = * V_107 = NULL ;
return 0 ;
}
* V_107 = * V_106 + V_109 / sizeof( T_8 ) ;
* V_102 = F_48 ( V_101 ) ;
V_108 = F_47 ( V_101 , L_19 , NULL ) ;
* V_103 = F_49 ( V_108 ) ;
V_108 = F_47 ( V_101 , L_20 , NULL ) ;
* V_104 = F_49 ( V_108 ) ;
* V_105 = * V_102 + * V_103 + * V_104 ;
V_110 = ( * V_105 ) * sizeof( T_8 ) ;
if ( V_109 % V_110 ) {
F_50 ( L_21 , V_101 -> V_111 ) ;
return - V_43 ;
}
return 0 ;
}
static int T_7 F_51 ( struct V_3 * V_4 ,
struct V_92 * V_93 )
{
int V_102 , V_103 , V_104 ;
int V_50 , V_112 , V_105 ;
const T_8 * V_113 , * V_106 , * V_107 ;
V_112 = F_46 ( V_93 , & V_102 , & V_103 ,
& V_104 , & V_105 ,
& V_106 , & V_107 ) ;
if ( V_112 < 0 )
return V_112 ;
for ( V_50 = 0 , V_113 = V_106 ; V_113 < V_107 ; V_113 += V_105 , V_50 ++ ) {
T_2 V_114 , V_7 , V_8 ;
T_3 V_9 , V_10 ;
V_114 = F_52 ( V_113 , 1 ) ;
if ( F_53 ( V_114 ) )
continue;
V_9 = F_54 ( V_114 ) ;
V_10 = F_55 ( V_114 ) ;
V_7 = F_52 ( V_113 + V_103 , V_102 ) ;
V_8 = F_52 ( V_113 + V_103 + V_102 ,
V_104 ) ;
V_112 = F_45 ( V_4 , V_7 , V_8 , V_9 , V_10 ) ;
if ( V_112 < 0 )
return V_112 ;
}
return 0 ;
}
static void T_7 F_56 ( struct V_92 * V_93 ,
struct V_78 * V_115 ,
struct V_78 * V_116 )
{
T_2 V_117 [ 2 ] ;
int V_112 ;
memset ( V_115 , 0 , sizeof( struct V_78 ) ) ;
V_115 -> V_34 = - 1 ;
memset ( V_116 , 0 , sizeof( struct V_78 ) ) ;
V_116 -> V_34 = - 1 ;
V_112 = F_57 ( V_93 , L_22 , V_117 , F_58 ( V_117 ) ) ;
if ( ! V_112 ) {
V_115 -> V_118 = V_117 [ 0 ] ;
V_115 -> V_34 = V_115 -> V_118 + V_117 [ 1 ] - 1 ;
V_115 -> V_119 = V_120 ;
}
V_112 = F_57 ( V_93 , L_23 , V_117 , F_58 ( V_117 ) ) ;
if ( ! V_112 ) {
V_116 -> V_118 = V_117 [ 0 ] ;
V_116 -> V_34 = V_116 -> V_118 + V_117 [ 1 ] - 1 ;
V_116 -> V_119 = V_121 ;
}
}
int T_7 F_59 ( void )
{
struct V_78 V_122 , V_123 ;
struct V_92 * V_93 , * V_124 ;
const struct V_95 * V_96 ;
const T_8 * V_108 ;
int V_112 ;
V_93 = F_60 ( NULL , V_97 , & V_96 ) ;
if ( ! V_93 ) {
F_31 ( L_15 ) ;
return - V_41 ;
}
V_60 . V_14 = V_96 -> V_99 ;
V_108 = F_47 ( V_93 , L_24 , NULL ) ;
if ( ! V_108 ) {
F_31 ( L_25 ) ;
return - V_43 ;
}
V_124 = F_61 ( F_49 ( V_108 ) ) ;
if ( ! V_124 ) {
F_31 ( L_26 ) ;
return - V_41 ;
}
if ( F_62 ( V_124 , 0 , & V_122 ) ) {
F_31 ( L_27 ) ;
return - V_43 ;
}
if ( F_62 ( V_124 , 1 , & V_123 ) ) {
F_31 ( L_28 ) ;
return - V_43 ;
}
F_56 ( V_93 , & V_60 . V_80 ,
& V_60 . V_81 ) ;
V_112 = F_39 ( & V_60 ,
V_122 . V_118 ,
F_63 ( & V_122 ) ,
V_123 . V_118 ,
F_63 ( & V_123 ) ) ;
if ( V_112 )
return V_112 ;
return F_51 ( & V_60 , V_93 ) ;
}
