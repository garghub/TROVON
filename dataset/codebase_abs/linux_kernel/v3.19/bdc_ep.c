static void F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
struct V_4 * V_4 = & V_2 -> V_4 ;
struct V_5 * V_5 = V_2 -> V_5 ;
struct V_6 * V_6 ;
int V_7 ;
F_2 ( V_5 -> V_8 , L_1 ,
V_9 , V_2 -> V_10 , V_3 ) ;
if ( ! V_4 -> V_11 ) {
F_2 ( V_5 -> V_8 , L_2 , V_2 -> V_10 ) ;
return;
}
for ( V_7 = 0 ; V_7 < V_3 ; V_7 ++ ) {
V_6 = V_4 -> V_11 [ V_7 ] ;
F_2 ( V_5 -> V_8 , L_3 , V_6 , V_7 ) ;
if ( ! V_6 ) {
F_2 ( V_5 -> V_8 , L_4 ) ;
continue;
}
if ( ! V_6 -> V_12 ) {
F_2 ( V_5 -> V_8 , L_5 ) ;
continue;
}
F_2 ( V_5 -> V_8 ,
L_6 ,
V_6 -> V_12 ,
( unsigned long long ) V_6 -> V_13 ) ;
F_3 ( V_5 -> V_14 ,
V_6 -> V_12 ,
V_6 -> V_13 ) ;
F_4 ( V_6 ) ;
}
F_4 ( V_2 -> V_4 . V_11 ) ;
}
static inline void F_5 ( struct V_6 * V_15 ,
struct V_6 * V_16 ,
T_1 V_17 )
{
V_15 -> V_12 [ V_17 - 1 ] . V_18 [ 0 ] =
F_6 ( F_7 ( V_16 -> V_13 ) ) ;
V_15 -> V_12 [ V_17 - 1 ] . V_18 [ 1 ] =
F_6 ( F_8 ( V_16 -> V_13 ) ) ;
V_15 -> V_12 [ V_17 - 1 ] . V_18 [ 2 ] =
0x0 ;
V_15 -> V_12 [ V_17 - 1 ] . V_18 [ 3 ] =
F_6 ( V_19 ) ;
}
static int F_9 ( struct V_1 * V_2 )
{
struct V_6 * V_15 = NULL ;
int V_7 , V_3 , V_17 ;
struct V_5 * V_5 = V_2 -> V_5 ;
struct V_6 * V_6 ;
T_2 V_13 ;
if ( F_10 ( V_2 -> V_20 ) )
V_3 = V_21 ;
else
V_3 = V_22 ;
V_17 = V_23 ;
F_2 ( V_5 -> V_8 ,
L_7 ,
V_9 , V_2 , V_3 ) ;
V_2 -> V_4 . V_11 = F_11 (
V_3 * sizeof( struct V_6 * ) ,
V_24 ) ;
if ( ! V_2 -> V_4 . V_11 )
return - V_25 ;
for ( V_7 = 0 ; V_7 < V_3 ; V_7 ++ ) {
V_6 = F_11 ( sizeof( struct V_6 ) , V_24 ) ;
if ( ! V_6 )
goto V_26;
V_6 -> V_12 = F_12 ( V_5 -> V_14 ,
V_24 ,
& V_13 ) ;
if ( ! V_6 -> V_12 )
goto V_26;
V_6 -> V_13 = V_13 ;
F_2 ( V_5 -> V_8 ,
L_8 ,
V_7 , V_6 -> V_12 ,
( unsigned long long ) V_6 -> V_13 , V_15 ) ;
V_2 -> V_4 . V_11 [ V_7 ] = V_6 ;
memset ( V_6 -> V_12 , 0 , V_17 * sizeof( struct V_27 ) ) ;
if ( V_15 )
F_5 ( V_15 , V_6 , V_17 ) ;
V_15 = V_6 ;
}
F_5 ( V_15 , V_2 -> V_4 . V_11 [ 0 ] , V_17 ) ;
V_2 -> V_4 . V_3 = V_3 ;
V_2 -> V_4 . V_28 = ( V_3 * V_17 ) - 1 ;
V_2 -> V_4 . V_3 = V_3 ;
V_2 -> V_4 . V_29 = V_17 ;
V_2 -> V_4 . V_30 = 0 ;
V_2 -> V_4 . V_31 = 0 ;
return 0 ;
V_26:
F_1 ( V_2 , V_3 ) ;
return - V_25 ;
}
static inline int F_13 ( struct V_32 * V_33 )
{
int V_34 = 0 ;
int V_35 ;
if ( V_33 -> V_36 . V_37 == 0 )
return 1 ;
V_35 = V_33 -> V_36 . V_37 % V_38 ;
if ( V_35 )
V_34 ++ ;
V_35 = V_33 -> V_36 . V_37 / V_38 ;
V_34 += V_35 ;
return V_34 ;
}
static int F_14 ( struct V_1 * V_2 , T_2 V_39 )
{
struct V_4 * V_4 = & V_2 -> V_4 ;
T_2 V_40 , V_41 ;
struct V_5 * V_5 = V_2 -> V_5 ;
struct V_6 * V_6 ;
bool V_42 = false ;
int V_43 , V_44 ;
V_40 = V_41 = 0 ;
F_2 ( V_5 -> V_8 , L_9 ,
V_9 , ( unsigned long long ) V_39 ) ;
for ( V_43 = 0 ; V_43 < V_4 -> V_3 ; V_43 ++ ) {
V_6 = V_4 -> V_11 [ V_43 ] ;
V_40 = V_6 -> V_13 ;
V_41 = V_6 -> V_13 +
( sizeof( struct V_27 ) *
( V_4 -> V_29 - 1 ) ) ;
F_2 ( V_5 -> V_8 , L_10 ,
( unsigned long long ) V_40 ,
( unsigned long long ) V_41 ) ;
if ( V_39 >= V_40 && V_39 <= V_41 ) {
V_42 = true ;
break;
}
}
if ( F_15 ( ! V_42 ) ) {
F_16 ( V_5 -> V_8 , L_11 , V_9 ) ;
return - V_45 ;
}
V_44 = ( V_39 - V_40 ) / sizeof( struct V_27 ) ;
return ( V_44 + ( V_43 * V_4 -> V_29 ) ) ;
}
static int F_17 ( struct V_1 * V_2 , int V_44 )
{
int V_43 ;
V_43 = V_44 / V_2 -> V_4 . V_29 ;
F_18 ( V_2 -> V_5 -> V_8 ,
L_12 ,
V_44 , V_2 -> V_4 . V_29 , V_43 ) ;
return V_43 ;
}
static inline int F_19 ( struct V_1 * V_2 , int V_46 )
{
int V_47 ;
V_47 = V_46 - 1 ;
if ( V_47 < 0 )
V_47 = V_2 -> V_4 . V_28 - 1 ;
else if ( ( V_47 % ( V_2 -> V_4 . V_29 - 1 ) ) == 0 )
V_47 -- ;
return V_47 ;
}
static int F_20 ( struct V_1 * V_2 )
{
struct V_4 * V_4 = & V_2 -> V_4 ;
int V_48 , V_49 ;
struct V_5 * V_5 = V_2 -> V_5 ;
int V_50 , V_51 ;
int V_52 = 0 ;
V_48 = V_49 = V_50 = V_51 = 0 ;
if ( V_4 -> V_30 == V_4 -> V_31 )
return V_4 -> V_28 - V_4 -> V_3 ;
if ( V_4 -> V_31 < V_4 -> V_30 ) {
V_48 = V_4 -> V_28 - V_4 -> V_30 ;
V_49 = V_4 -> V_31 ;
V_50 = V_48 / V_4 -> V_29 ;
V_51 = V_49 / V_4 -> V_29 ;
F_18 ( V_5 -> V_8 , L_13 ,
V_50 , V_51 ) ;
V_52 = V_48 + V_49 - V_50 - V_51 ;
} else {
V_48 = V_4 -> V_31 - V_4 -> V_30 ;
if ( ( V_4 -> V_31 - V_4 -> V_30 )
<= V_4 -> V_29 ) {
if ( ! ( F_17 ( V_2 , V_4 -> V_31 )
== F_17 ( V_2 , V_4 -> V_30 ) ) ) {
V_52 = V_48 - 1 ;
}
} else {
V_50 = V_48 / V_4 -> V_29 ;
V_52 = V_48 - V_50 ;
}
}
V_52 -- ;
F_18 ( V_5 -> V_8 , L_14 , V_52 ) ;
return V_52 ;
}
void F_21 ( struct V_5 * V_5 , T_1 V_53 )
{
struct V_1 * V_2 = V_5 -> V_54 [ V_53 ] ;
F_18 ( V_5 -> V_8 , L_15 , V_9 , V_53 ) ;
if ( F_15 ( V_2 -> V_55 & V_56 ) )
V_2 -> V_55 &= ~ V_56 ;
F_22 ( V_5 -> V_57 , V_58 , V_53 ) ;
}
static struct V_27 * F_23 ( struct V_1 * V_2 , int V_44 )
{
int V_43 = F_17 ( V_2 , V_44 ) ;
int V_59 = 0 ;
V_59 = V_44 - ( V_43 * V_2 -> V_4 . V_29 ) ;
F_18 ( V_2 -> V_5 -> V_8 ,
L_16 ,
V_9 , V_44 , V_59 ) ;
return ( V_2 -> V_4 . V_11 [ V_43 ] -> V_12 + V_59 ) ;
}
static void F_24 ( struct V_1 * V_2 )
{
V_2 -> V_4 . V_30 ++ ;
if ( ( ( V_2 -> V_4 . V_30 + 1 ) % V_2 -> V_4 . V_29 ) == 0 )
V_2 -> V_4 . V_30 ++ ;
if ( V_2 -> V_4 . V_30 == ( V_2 -> V_4 . V_28 + 1 ) )
V_2 -> V_4 . V_30 = 0 ;
}
static int F_25 ( struct V_5 * V_5 , struct V_32 * V_33 , T_1 * V_60 )
{
T_3 V_61 ;
T_1 V_62 ;
V_33 -> V_2 -> V_63 = 0 ;
V_62 = V_33 -> V_36 . V_37 ;
switch ( V_5 -> V_64 ) {
case V_65 :
* V_60 |= V_66 ;
if ( V_5 -> V_67 . V_68 & V_69 )
* V_60 |= V_70 ;
V_61 = F_26 ( V_5 -> V_67 . V_61 ) ;
if ( ( V_61 > V_62 ) &&
( V_62 % V_5 -> V_71 . V_72 -> V_73 == 0 ) ) {
F_2 ( V_5 -> V_8 , L_17 ,
V_61 , V_62 ,
V_5 -> V_71 . V_72 -> V_73 ) ;
V_5 -> V_74 = true ;
}
break;
case V_75 :
* V_60 |= V_76 ;
if ( ! F_26 ( V_5 -> V_67 . V_77 ) ||
! ( V_5 -> V_67 . V_68 & V_69 ) )
* V_60 |= V_70 ;
break;
default:
F_16 ( V_5 -> V_8 ,
L_18 ,
V_78 [ V_5 -> V_64 ] ) ;
return - V_45 ;
}
return 0 ;
}
static int F_27 ( struct V_5 * V_5 , struct V_32 * V_33 , int V_79 )
{
T_2 V_80 = V_33 -> V_36 . V_13 ;
T_1 V_81 , V_82 , V_83 , V_60 ;
struct V_84 * V_85 ;
struct V_4 * V_4 ;
struct V_1 * V_2 ;
struct V_27 * V_86 ;
int V_87 , V_88 ;
T_1 V_62 ;
V_2 = V_33 -> V_2 ;
V_4 = & V_2 -> V_4 ;
V_85 = & V_33 -> V_85 ;
V_85 -> V_33 = V_33 ;
V_85 -> V_89 = V_4 -> V_30 ;
V_86 = F_23 ( V_2 , V_4 -> V_30 ) ;
V_62 = V_33 -> V_36 . V_37 ;
V_81 = F_28 ( V_2 -> V_20 ) & 0x7ff ;
V_82 = F_29 ( V_33 -> V_36 . V_37 , V_81 ) ;
V_82 = V_82 / V_81 ;
F_18 ( V_5 -> V_8 , L_19 ,
V_9 , V_2 -> V_10 , V_79 , V_82 , V_62 , V_86 ) ;
for ( V_88 = 0 ; V_88 < V_79 ; V_88 ++ ) {
V_83 = V_60 = 0 ;
if ( ! V_88 ) {
V_60 |= V_90 | V_91 | ( V_82 << V_92 ) ;
V_83 |= V_93 ;
if ( V_2 -> V_94 == 1 ) {
V_87 = F_25 ( V_5 , V_33 , & V_60 ) ;
if ( V_87 )
return V_87 ;
}
}
if ( ! V_33 -> V_2 -> V_63 )
V_60 |= V_95 ;
if ( V_62 > V_38 ) {
V_83 |= V_38 ;
V_62 -= V_38 ;
} else {
V_83 |= V_62 ;
V_60 |= V_96 ;
V_60 |= V_97 ;
}
V_83 |= F_30 ( 0 ) ;
V_86 = F_23 ( V_2 , V_2 -> V_4 . V_30 ) ;
if ( F_15 ( ! V_86 ) ) {
F_16 ( V_5 -> V_8 , L_20 ) ;
return - V_45 ;
}
V_86 -> V_18 [ 0 ] = F_6 ( F_7 ( V_80 ) ) ;
V_86 -> V_18 [ 1 ] = F_6 ( F_8 ( V_80 ) ) ;
V_86 -> V_18 [ 2 ] = F_6 ( V_83 ) ;
V_86 -> V_18 [ 3 ] = F_6 ( V_60 ) ;
F_24 ( V_2 ) ;
V_80 += V_38 ;
F_18 ( V_5 -> V_8 , L_21 ,
( unsigned long long ) V_80 , V_62 , V_86 ,
V_2 -> V_4 . V_30 ) ;
V_86 = F_23 ( V_2 , V_2 -> V_4 . V_30 ) ;
V_86 -> V_18 [ 3 ] = F_6 ( V_91 ) ;
}
V_86 = F_23 ( V_2 , V_85 -> V_89 ) ;
V_86 -> V_18 [ 3 ] &= F_6 ( ~ V_91 ) ;
V_85 -> V_79 = V_79 ;
V_85 -> V_46 = V_2 -> V_4 . V_30 ;
F_31 () ;
return 0 ;
}
static int F_32 ( struct V_5 * V_5 , struct V_32 * V_33 )
{
int V_79 , V_98 ;
struct V_1 * V_2 ;
int V_87 ;
V_2 = V_33 -> V_2 ;
F_2 ( V_5 -> V_8 , L_22 , V_9 , V_33 ) ;
F_2 ( V_5 -> V_8 , L_23 ,
V_2 -> V_4 . V_30 , V_2 -> V_4 . V_31 ) ;
V_79 = F_13 ( V_33 ) ;
V_98 = F_20 ( V_2 ) ;
if ( V_79 > V_98 )
return - V_25 ;
V_87 = F_27 ( V_5 , V_33 , V_79 ) ;
if ( V_87 )
return V_87 ;
F_33 ( & V_33 -> V_99 , & V_2 -> V_99 ) ;
F_34 ( V_5 , V_2 ) ;
F_21 ( V_5 , V_2 -> V_94 ) ;
return 0 ;
}
static void F_35 ( struct V_1 * V_2 , struct V_32 * V_33 ,
int V_100 )
{
struct V_5 * V_5 = V_2 -> V_5 ;
if ( V_33 == NULL || & V_33 -> V_99 == NULL || & V_33 -> V_36 == NULL )
return;
F_2 ( V_5 -> V_8 , L_24 , V_9 , V_2 -> V_10 , V_100 ) ;
F_36 ( & V_33 -> V_99 ) ;
V_33 -> V_36 . V_100 = V_100 ;
F_37 ( & V_5 -> V_71 , & V_33 -> V_36 , V_2 -> V_63 ) ;
if ( V_33 -> V_36 . V_101 ) {
F_38 ( & V_5 -> V_102 ) ;
F_39 ( & V_2 -> V_103 , & V_33 -> V_36 ) ;
F_40 ( & V_5 -> V_102 ) ;
}
}
int F_41 ( struct V_1 * V_2 )
{
struct V_32 * V_33 ;
struct V_5 * V_5 ;
int V_87 ;
V_87 = 0 ;
V_5 = V_2 -> V_5 ;
F_2 ( V_5 -> V_8 , L_25 , V_9 , V_2 -> V_94 ) ;
V_87 = F_42 ( V_5 , V_2 -> V_94 ) ;
while ( ! F_43 ( & V_2 -> V_99 ) ) {
V_33 = F_44 ( V_2 -> V_99 . V_104 , struct V_32 ,
V_99 ) ;
F_35 ( V_2 , V_33 , - V_105 ) ;
}
V_87 = F_45 ( V_5 , V_2 ) ;
if ( V_87 )
F_46 ( V_5 -> V_8 ,
L_26 ) ;
V_2 -> V_55 = 0 ;
if ( V_2 -> V_94 == 1 )
return 0 ;
F_1 ( V_2 , V_2 -> V_4 . V_3 ) ;
V_2 -> V_20 = NULL ;
V_2 -> V_106 = NULL ;
V_2 -> V_103 . V_20 = NULL ;
V_2 -> V_107 = 0 ;
return V_87 ;
}
int F_47 ( struct V_1 * V_2 )
{
struct V_5 * V_5 ;
int V_87 = 0 ;
V_5 = V_2 -> V_5 ;
F_2 ( V_5 -> V_8 , L_27 ,
V_9 , V_22 , V_21 ) ;
V_87 = F_9 ( V_2 ) ;
if ( V_87 ) {
F_16 ( V_5 -> V_8 , L_28 , V_87 ) ;
return - V_25 ;
}
F_34 ( V_5 , V_2 ) ;
V_2 -> V_55 |= V_108 ;
if ( V_2 -> V_94 == 1 )
return V_87 ;
V_87 = F_48 ( V_5 , V_2 ) ;
if ( V_87 )
return V_87 ;
V_2 -> V_103 . V_73 = F_28 ( V_2 -> V_20 ) ;
V_2 -> V_103 . V_20 = V_2 -> V_20 ;
V_2 -> V_103 . V_106 = V_2 -> V_106 ;
V_2 -> V_107 = F_49 ( V_2 -> V_20 ) ;
V_2 -> V_55 |= V_108 ;
return 0 ;
}
static int F_50 ( struct V_5 * V_5 )
{
struct V_32 * V_109 ;
struct V_1 * V_2 ;
V_109 = & V_5 -> V_109 ;
V_2 = V_5 -> V_54 [ 1 ] ;
V_109 -> V_2 = V_2 ;
V_109 -> V_36 . V_37 = 0 ;
V_109 -> V_36 . V_100 = - V_110 ;
V_109 -> V_36 . V_111 = 0 ;
V_109 -> V_36 . V_101 = NULL ;
F_32 ( V_5 , V_109 ) ;
return 0 ;
}
static int F_51 ( struct V_1 * V_2 , struct V_32 * V_33 )
{
struct V_5 * V_5 ;
int V_87 ;
V_5 = V_2 -> V_5 ;
F_2 ( V_5 -> V_8 , L_29 , V_9 ) ;
V_33 -> V_36 . V_111 = 0 ;
V_33 -> V_36 . V_100 = - V_110 ;
V_33 -> V_53 = V_2 -> V_94 ;
if ( V_5 -> V_112 ) {
V_5 -> V_112 = false ;
if ( V_5 -> V_64 == V_75 ) {
F_50 ( V_5 ) ;
V_5 -> V_64 = V_113 ;
return 0 ;
}
} else {
if ( V_33 -> V_36 . V_37 == 0 )
return 0 ;
}
V_87 = F_52 ( & V_5 -> V_71 , & V_33 -> V_36 , V_2 -> V_63 ) ;
if ( V_87 ) {
F_16 ( V_5 -> V_8 , L_30 , V_2 -> V_10 ) ;
return V_87 ;
}
return F_32 ( V_5 , V_33 ) ;
}
static int F_53 ( struct V_5 * V_5 )
{
struct V_114 * V_115 ;
struct V_1 * V_2 ;
F_2 ( V_5 -> V_8 , L_31 , V_9 ) ;
V_115 = & V_5 -> V_116 . V_36 ;
V_2 = V_5 -> V_54 [ 1 ] ;
V_5 -> V_116 . V_2 = V_2 ;
V_5 -> V_116 . V_36 . V_101 = NULL ;
return F_51 ( V_2 , & V_5 -> V_116 ) ;
}
static int F_54 ( struct V_1 * V_2 , struct V_32 * V_33 )
{
struct V_5 * V_5 ;
int V_87 = 0 ;
if ( ! V_33 || ! V_2 || ! V_2 -> V_103 . V_20 )
return - V_45 ;
V_5 = V_2 -> V_5 ;
V_33 -> V_36 . V_111 = 0 ;
V_33 -> V_36 . V_100 = - V_110 ;
V_33 -> V_53 = V_2 -> V_94 ;
V_87 = F_52 ( & V_5 -> V_71 , & V_33 -> V_36 , V_2 -> V_63 ) ;
if ( V_87 ) {
F_16 ( V_5 -> V_8 , L_32 ) ;
return V_87 ;
}
return F_32 ( V_5 , V_33 ) ;
}
static int F_55 ( struct V_1 * V_2 , struct V_32 * V_33 )
{
int V_89 , V_47 , V_43 , V_30 , V_117 ;
bool V_118 , V_119 ;
bool V_120 = false ;
struct V_32 * V_121 ;
struct V_27 * V_122 ;
struct V_6 * V_123 ;
T_2 V_124 ;
T_4 V_125 = 0 ;
struct V_5 * V_5 ;
T_1 V_126 ;
int V_87 ;
V_5 = V_2 -> V_5 ;
V_118 = V_119 = false ;
V_30 = V_2 -> V_4 . V_30 - 1 ;
if ( V_30 < 0 )
V_30 = V_2 -> V_4 . V_28 ;
V_89 = V_33 -> V_85 . V_89 ;
V_47 = F_19 ( V_2 , V_33 -> V_85 . V_46 ) ;
F_2 ( V_5 -> V_8 , L_33 ,
V_9 , V_2 -> V_10 , V_89 , V_47 ) ;
F_2 ( V_5 -> V_8 , L_34 ,
V_2 , ( void * ) V_2 -> V_103 . V_20 ) ;
V_87 = F_42 ( V_5 , V_2 -> V_94 ) ;
if ( V_87 )
return 0 ;
V_126 = F_56 ( V_5 -> V_57 , F_57 ( 0 ) ) ;
V_125 = V_126 ;
V_126 = F_56 ( V_5 -> V_57 , F_57 ( 1 ) ) ;
V_125 |= ( ( T_4 ) V_126 << 32 ) ;
V_117 = F_14 ( V_2 , V_125 ) ;
if ( V_117 < 0 )
return V_117 ;
if ( V_117 > V_30 ) {
if ( V_89 >= V_117 || V_89 <= V_30 ) {
V_118 = true ;
V_119 = true ;
} else if ( V_47 >= V_117 || V_47 <= V_30 ) {
V_119 = true ;
}
} else {
if ( V_89 >= V_117 ) {
V_118 = true ;
V_119 = true ;
} else if ( V_47 >= V_117 ) {
V_119 = true ;
}
}
F_2 ( V_5 -> V_8 ,
L_35 ,
V_118 , V_119 , V_5 -> V_71 . V_127 ) ;
if ( ! V_118 && ! V_119 )
return - V_45 ;
if ( V_5 -> V_71 . V_127 == V_128 )
return 0 ;
V_43 = F_17 ( V_2 , V_33 -> V_85 . V_46 ) ;
V_123 = V_2 -> V_4 . V_11 [ V_43 ] ;
V_124 = V_123 -> V_13 +
sizeof( struct V_27 ) * ( V_33 -> V_85 . V_46 -
V_43 * V_2 -> V_4 . V_29 ) ;
V_121 = F_58 ( & V_2 -> V_99 , struct V_32 ,
V_99 ) ;
if ( V_33 == V_121 )
V_120 = true ;
if ( V_118 && ! V_120 ) {
V_122 = F_23 ( V_2 , V_89 ) ;
V_122 -> V_18 [ 0 ] = F_6 ( F_7 ( V_124 ) ) ;
V_122 -> V_18 [ 1 ] = F_6 ( F_8 ( V_124 ) ) ;
V_122 -> V_18 [ 2 ] = 0x0 ;
V_122 -> V_18 [ 3 ] = F_6 ( V_19 ) ;
F_34 ( V_5 , V_2 ) ;
} else if ( V_119 ) {
V_87 = F_59 ( V_5 , V_2 , V_124 ) ;
if ( V_87 ) {
F_16 ( V_5 -> V_8 , L_36 , V_87 ) ;
return V_87 ;
}
}
return 0 ;
}
static int F_60 ( struct V_1 * V_2 , T_1 V_129 )
{
struct V_5 * V_5 ;
int V_87 ;
V_5 = V_2 -> V_5 ;
F_2 ( V_5 -> V_8 , L_37 , V_9 , V_2 -> V_10 , V_129 ) ;
if ( V_129 ) {
F_2 ( V_5 -> V_8 , L_38 ) ;
if ( V_2 -> V_94 == 1 )
V_5 -> V_64 = V_130 ;
V_87 = F_61 ( V_5 , V_2 -> V_94 ) ;
if ( V_87 )
F_16 ( V_5 -> V_8 , L_39 ,
V_129 ? L_40 : L_41 , V_2 -> V_10 ) ;
else
V_2 -> V_55 |= V_131 ;
} else {
F_2 ( V_5 -> V_8 , L_42 ) ;
V_87 = F_62 ( V_5 , V_2 -> V_94 ) ;
if ( V_87 )
F_16 ( V_5 -> V_8 , L_39 ,
V_129 ? L_40 : L_41 , V_2 -> V_10 ) ;
else
V_2 -> V_55 &= ~ V_131 ;
F_2 ( V_5 -> V_8 , L_43 ) ;
}
return V_87 ;
}
void F_63 ( struct V_5 * V_5 )
{
struct V_1 * V_2 ;
T_5 V_53 ;
F_2 ( V_5 -> V_8 , L_31 , V_9 ) ;
for ( V_53 = 1 ; V_53 < V_5 -> V_132 ; V_53 ++ ) {
V_2 = V_5 -> V_54 [ V_53 ] ;
if ( ! V_2 )
continue;
if ( V_2 -> V_55 & V_108 )
F_1 ( V_2 , V_2 -> V_4 . V_3 ) ;
if ( V_53 != 1 )
F_36 ( & V_2 -> V_103 . V_133 ) ;
F_4 ( V_2 ) ;
}
}
static int F_64 ( struct V_5 * V_5 )
{
T_1 V_134 ;
V_134 = F_56 ( V_5 -> V_57 , V_135 ) ;
V_134 &= ~ V_136 ;
F_2 ( V_5 -> V_8 , L_31 , V_9 ) ;
switch ( V_5 -> V_137 ) {
case V_138 :
case V_139 :
case V_140 :
case V_141 :
case V_142 :
V_134 |= V_5 -> V_137 << 28 ;
break;
default:
return - V_45 ;
}
F_2 ( V_5 -> V_8 , L_44 , V_134 ) ;
F_22 ( V_5 -> V_57 , V_135 , V_134 ) ;
return 0 ;
}
static void F_65 ( struct V_5 * V_5 , struct V_1 * V_2 ,
struct V_143 * V_144 )
{
int V_145 , V_89 , V_47 , V_146 , V_147 ;
struct V_4 * V_4 = & V_2 -> V_4 ;
int V_148 , V_149 ;
struct V_84 * V_85 ;
struct V_27 * V_150 ;
struct V_32 * V_33 ;
T_4 V_125 = 0 ;
int V_100 = 0 ;
int V_151 ;
T_1 V_126 ;
F_2 ( V_5 -> V_8 , L_45 , V_9 , V_2 ) ;
F_66 ( V_5 , 0 ) ;
if ( V_2 -> V_152 ) {
V_2 -> V_152 = false ;
return;
}
if ( F_15 ( F_43 ( & V_2 -> V_99 ) ) ) {
F_46 ( V_5 -> V_8 , L_46 ) ;
return;
}
V_33 = F_44 ( V_2 -> V_99 . V_104 , struct V_32 ,
V_99 ) ;
V_85 = & V_33 -> V_85 ;
V_151 = F_67 ( F_68 ( V_144 -> V_18 [ 3 ] ) ) ;
if ( V_151 == V_153 && V_85 -> V_79 > 1 ) {
V_126 = F_68 ( V_144 -> V_18 [ 0 ] ) ;
V_125 = V_126 ;
V_126 = F_68 ( V_144 -> V_18 [ 1 ] ) ;
V_125 |= ( ( T_4 ) V_126 << 32 ) ;
V_145 = F_14 ( V_2 , V_125 ) ;
if ( F_15 ( V_145 < 0 ) )
F_46 ( V_5 -> V_8 , L_47 ) ;
V_89 = V_85 -> V_89 ;
if ( V_89 <= V_145 ) {
V_146 = V_145 - V_89 ;
if ( V_146 <= V_4 -> V_29 ) {
if ( ! ( F_17 ( V_2 , V_89 ) ==
F_17 ( V_2 , V_145 ) ) )
V_146 -- ;
} else {
V_147 = V_146 / V_4 -> V_29 ;
V_146 -= V_147 ;
}
} else {
V_147 = ( V_4 -> V_28 - V_89 ) /
V_4 -> V_29 ;
V_147 += V_145 / V_4 -> V_29 ;
V_146 = V_4 -> V_28 - V_89 ;
V_146 += V_145 ;
V_146 -= V_147 ;
}
V_47 = F_19 ( V_2 , V_85 -> V_46 ) ;
if ( ! ( V_47 == V_145 ) )
V_2 -> V_152 = true ;
V_148 = V_146 * V_38 ;
V_150 = F_23 ( V_2 , V_145 ) ;
V_149 = F_68 ( V_150 -> V_18 [ 2 ] ) & 0x1FFFFF ;
V_149 -= F_69 ( F_68 ( V_144 -> V_18 [ 2 ] ) ) ;
V_148 += V_149 ;
V_33 -> V_36 . V_111 = V_148 ;
} else {
V_33 -> V_36 . V_111 = V_33 -> V_36 . V_37 -
F_69 ( F_68 ( V_144 -> V_18 [ 2 ] ) ) ;
F_2 ( V_5 -> V_8 ,
L_48 ,
V_33 -> V_36 . V_37 , V_33 -> V_36 . V_111 ,
V_85 -> V_46 ) ;
}
V_2 -> V_4 . V_31 = V_85 -> V_46 ;
if ( V_33 -> V_36 . V_111 < V_33 -> V_36 . V_37 ) {
F_2 ( V_5 -> V_8 , L_49 , V_2 -> V_94 ) ;
if ( V_33 -> V_36 . V_154 )
V_100 = - V_155 ;
}
F_35 ( V_2 , V_85 -> V_33 , V_100 ) ;
}
void F_70 ( struct V_5 * V_5 , struct V_143 * V_144 )
{
struct V_156 * V_67 ;
T_1 V_157 ;
F_2 ( V_5 -> V_8 ,
L_50 ,
V_9 , V_78 [ V_5 -> V_64 ] ) ;
V_67 = & V_5 -> V_67 ;
memcpy ( V_67 , & V_144 -> V_18 [ 0 ] , sizeof( * V_67 ) ) ;
V_157 = F_26 ( V_67 -> V_77 ) ;
if ( ! V_157 )
V_5 -> V_64 = V_75 ;
else
V_5 -> V_64 = V_65 ;
F_2 ( V_5 -> V_8 ,
L_51 ,
V_9 , V_78 [ V_5 -> V_64 ] ) ;
}
static void F_71 ( struct V_5 * V_5 )
{
struct V_1 * V_2 = V_5 -> V_54 [ 1 ] ;
struct V_32 * V_33 ;
F_2 ( V_5 -> V_8 , L_31 , V_9 ) ;
V_5 -> V_112 = false ;
F_60 ( V_2 , 1 ) ;
while ( ! F_43 ( & V_2 -> V_99 ) ) {
V_33 = F_44 ( V_2 -> V_99 . V_104 , struct V_32 ,
V_99 ) ;
F_35 ( V_2 , V_33 , - V_105 ) ;
}
}
static int F_72 ( struct V_5 * V_5 , struct V_156 * V_158 )
{
enum V_159 V_160 = V_5 -> V_71 . V_160 ;
int V_87 = 0 ;
T_1 V_161 ;
V_161 = F_26 ( V_158 -> V_61 ) ;
F_2 ( V_5 -> V_8 ,
L_52 ,
V_9 , V_161 , V_160 ) ;
if ( V_161 > 127 )
return - V_45 ;
switch ( V_160 ) {
case V_162 :
case V_163 :
V_87 = F_73 ( V_5 , V_161 ) ;
if ( V_87 )
return V_87 ;
if ( V_161 )
F_74 ( & V_5 -> V_71 , V_163 ) ;
else
F_74 ( & V_5 -> V_71 , V_162 ) ;
V_5 -> V_164 = V_161 ;
break;
default:
F_46 ( V_5 -> V_8 ,
L_53 ,
V_160 ) ;
V_87 = - V_45 ;
}
return V_87 ;
}
static int F_75 ( struct V_5 * V_5 , T_3 V_61 ,
T_3 V_165 , bool V_166 )
{
enum V_159 V_160 = V_5 -> V_71 . V_160 ;
T_1 V_167 = 0 ;
F_2 ( V_5 -> V_8 , L_54 ,
V_9 , V_166 , V_160 ) ;
switch ( V_61 ) {
case V_168 :
F_2 ( V_5 -> V_8 , L_55 ) ;
if ( V_166 )
V_5 -> V_169 |= V_170 ;
else
V_5 -> V_169 &= ~ V_170 ;
break;
case V_171 :
F_2 ( V_5 -> V_8 , L_56 ) ;
if ( ( V_165 & 0xFF ) ||
( V_5 -> V_71 . V_127 != V_172 ) || ! V_166 )
return - V_45 ;
V_5 -> V_137 = V_165 >> 8 ;
break;
case V_173 :
F_2 ( V_5 -> V_8 , L_57 ) ;
if ( V_5 -> V_71 . V_127 != V_174 ||
V_160 != V_175 )
return - V_45 ;
V_167 = F_56 ( V_5 -> V_57 , V_176 ) ;
if ( V_166 ) {
V_167 &= ~ F_76 ( V_177 ) ;
V_167 |= F_76 ( V_178 ) ;
V_167 |= V_179 | V_180 ;
V_5 -> V_169 |= ( 1 << V_181 ) ;
} else {
V_167 &= ~ V_179 ;
V_167 |= V_180 ;
V_5 -> V_169 &= ~ ( 1 << V_181 ) ;
}
F_22 ( V_5 -> V_57 , V_176 , V_167 ) ;
break;
case V_182 :
F_2 ( V_5 -> V_8 , L_58 ) ;
if ( V_5 -> V_71 . V_127 != V_174 ||
V_160 != V_175 )
return - V_45 ;
V_167 = F_56 ( V_5 -> V_57 , V_176 ) ;
if ( V_166 ) {
V_167 |= V_183 ;
V_167 |= V_184 ;
V_5 -> V_169 |= ( 1 << V_185 ) ;
} else {
V_167 &= ~ V_183 ;
V_167 &= ~ V_184 ;
V_5 -> V_169 &= ~ ( 1 << V_185 ) ;
}
F_22 ( V_5 -> V_57 , V_176 , V_167 ) ;
break;
case V_186 :
F_2 ( V_5 -> V_8 , L_59 ) ;
if ( V_5 -> V_71 . V_127 != V_174 ||
V_160 != V_175 )
return - V_45 ;
break;
default:
F_16 ( V_5 -> V_8 , L_60 , V_61 ) ;
return - V_187 ;
}
return 0 ;
}
static int F_77 ( struct V_5 * V_5 ,
struct V_156 * V_67 , bool V_166 )
{
enum V_159 V_160 = V_5 -> V_71 . V_160 ;
struct V_1 * V_2 ;
T_3 V_61 ;
T_3 V_165 ;
int V_53 ;
V_61 = F_26 ( V_67 -> V_61 ) ;
V_165 = F_26 ( V_67 -> V_165 ) ;
F_2 ( V_5 -> V_8 ,
L_61 ,
V_9 , V_61 , V_165 , V_160 ,
V_5 -> V_71 . V_127 , V_166 ) ;
switch ( V_67 -> V_68 & V_188 ) {
case V_189 :
return F_75 ( V_5 , V_61 , V_165 , V_166 ) ;
case V_190 :
F_2 ( V_5 -> V_8 , L_62 ) ;
if ( V_61 != V_191 )
return - V_45 ;
if ( V_166 ) {
if ( V_165 & V_192 ) {
F_2 ( V_5 -> V_8 , L_63 ) ;
V_5 -> V_169 |= V_170 ;
} else {
F_2 ( V_5 -> V_8 , L_64 ) ;
V_5 -> V_169 &= ~ V_170 ;
}
}
break;
case V_193 :
F_2 ( V_5 -> V_8 , L_65 ) ;
if ( V_61 != V_194 )
return - V_45 ;
V_53 = V_165 & V_195 ;
if ( V_53 ) {
if ( ( V_165 & V_196 ) == V_69 )
V_53 = V_53 * 2 + 1 ;
else
V_53 *= 2 ;
} else {
V_53 = 1 ;
}
if ( V_53 == 1 && ! V_166 ) {
F_2 ( V_5 -> V_8 , L_66 ) ;
return 0 ;
}
F_2 ( V_5 -> V_8 , L_67 , V_53 ) ;
V_2 = V_5 -> V_54 [ V_53 ] ;
if ( ! V_2 )
return - V_45 ;
return F_60 ( V_2 , V_166 ) ;
default:
F_16 ( V_5 -> V_8 , L_68 ) ;
return - V_45 ;
}
return 0 ;
}
static int F_78 ( struct V_5 * V_5 ,
struct V_156 * V_67 )
{
enum V_159 V_160 = V_5 -> V_71 . V_160 ;
struct V_1 * V_2 ;
T_3 V_197 = 0 ;
T_1 V_53 ;
T_3 V_165 ;
if ( V_160 == V_162 )
return - V_45 ;
V_165 = F_26 ( V_67 -> V_165 ) ;
F_2 ( V_5 -> V_8 , L_31 , V_9 ) ;
V_197 = V_5 -> V_169 ;
switch ( V_67 -> V_68 & V_188 ) {
case V_189 :
F_2 ( V_5 -> V_8 ,
L_69 ,
V_5 -> V_169 ) ;
if ( V_5 -> V_71 . V_127 == V_174 )
V_197 &= ~ V_170 ;
break;
case V_190 :
F_2 ( V_5 -> V_8 , L_62 ) ;
if ( V_5 -> V_71 . V_127 == V_174 ) {
if ( V_5 -> V_169 & V_170 )
V_197 |= V_170 ;
} else {
V_197 = 0 ;
}
break;
case V_193 :
F_2 ( V_5 -> V_8 , L_65 ) ;
V_53 = V_165 & V_195 ;
if ( V_53 ) {
if ( ( V_165 & V_196 ) == V_69 )
V_53 = V_53 * 2 + 1 ;
else
V_53 *= 2 ;
} else {
V_53 = 1 ;
}
V_2 = V_5 -> V_54 [ V_53 ] ;
if ( ! V_2 ) {
F_16 ( V_5 -> V_8 , L_70 ) ;
return - V_45 ;
}
if ( V_2 -> V_55 & V_131 )
V_197 |= 1 << V_194 ;
break;
default:
F_16 ( V_5 -> V_8 , L_71 ) ;
return - V_45 ;
}
F_2 ( V_5 -> V_8 , L_72 , V_197 ) ;
* ( V_198 * ) V_5 -> V_199 = F_79 ( V_197 ) ;
V_5 -> V_116 . V_36 . V_37 = 2 ;
V_5 -> V_116 . V_36 . V_200 = & V_5 -> V_199 ;
F_53 ( V_5 ) ;
return 0 ;
}
static void F_80 ( struct V_103 * V_201 , struct V_114 * V_202 )
{
}
static int F_81 ( struct V_5 * V_5 ,
struct V_156 * V_67 )
{
struct V_1 * V_2 ;
T_3 V_77 ;
T_3 V_61 ;
F_2 ( V_5 -> V_8 , L_31 , V_9 ) ;
V_61 = F_26 ( V_67 -> V_61 ) ;
V_77 = F_26 ( V_67 -> V_77 ) ;
if ( F_15 ( V_77 != 6 ) ) {
F_16 ( V_5 -> V_8 , L_73 , V_9 , V_77 ) ;
return - V_45 ;
}
V_2 = V_5 -> V_54 [ 1 ] ;
V_5 -> V_116 . V_2 = V_2 ;
V_5 -> V_116 . V_36 . V_37 = 6 ;
V_5 -> V_116 . V_36 . V_200 = V_5 -> V_199 ;
V_5 -> V_116 . V_36 . V_101 = F_80 ;
F_53 ( V_5 ) ;
return 0 ;
}
static int F_82 ( struct V_5 * V_5 )
{
int V_87 ;
F_2 ( V_5 -> V_8 , L_31 , V_9 ) ;
V_5 -> V_116 . V_2 = V_5 -> V_54 [ 1 ] ;
V_5 -> V_116 . V_36 . V_37 = 0 ;
V_5 -> V_116 . V_36 . V_101 = NULL ;
V_5 -> V_64 = V_65 ;
V_87 = F_32 ( V_5 , & V_5 -> V_116 ) ;
if ( V_87 ) {
F_16 ( V_5 -> V_8 , L_74 , V_87 ) ;
return V_87 ;
}
V_5 -> V_64 = V_203 ;
return 0 ;
}
static int F_83 ( struct V_5 * V_5 )
{
enum V_159 V_160 = V_5 -> V_71 . V_160 ;
struct V_156 * V_67 ;
int V_204 = 0 ;
int V_87 = 0 ;
int V_205 = 0 ;
V_67 = & V_5 -> V_67 ;
F_2 ( V_5 -> V_8 , L_31 , V_9 ) ;
if ( ( V_67 -> V_68 & V_206 ) == V_207 ) {
switch ( V_67 -> V_208 ) {
case V_209 :
F_2 ( V_5 -> V_8 , L_75 ) ;
V_87 = F_72 ( V_5 , V_67 ) ;
V_5 -> V_169 &= V_210 ;
break;
case V_211 :
F_2 ( V_5 -> V_8 , L_76 ) ;
if ( V_160 == V_163 ) {
F_74 ( & V_5 -> V_71 ,
V_175 ) ;
} else if ( V_160 == V_175 ) {
V_205 = F_26 ( V_67 -> V_61 ) ;
if ( ! V_205 )
F_74 (
& V_5 -> V_71 ,
V_163 ) ;
}
V_204 = 1 ;
break;
case V_212 :
F_2 ( V_5 -> V_8 , L_77 ) ;
V_87 = F_77 ( V_5 , V_67 , 1 ) ;
break;
case V_213 :
F_2 ( V_5 -> V_8 , L_78 ) ;
V_87 = F_77 ( V_5 , V_67 , 0 ) ;
break;
case V_214 :
F_2 ( V_5 -> V_8 , L_79 ) ;
V_87 = F_78 ( V_5 , V_67 ) ;
break;
case V_215 :
F_2 ( V_5 -> V_8 , L_80 ) ;
V_87 = F_81 ( V_5 , V_67 ) ;
break;
case V_216 :
F_46 ( V_5 -> V_8 ,
L_81 ) ;
V_87 = 0 ;
break;
default:
V_204 = 1 ;
}
} else {
V_204 = 1 ;
}
if ( V_204 ) {
F_38 ( & V_5 -> V_102 ) ;
V_87 = V_5 -> V_217 -> V_218 ( & V_5 -> V_71 , V_67 ) ;
F_40 ( & V_5 -> V_102 ) ;
}
return V_87 ;
}
void F_84 ( struct V_5 * V_5 , struct V_143 * V_144 )
{
struct V_1 * V_2 ;
int V_87 = 0 ;
F_2 ( V_5 -> V_8 , L_31 , V_9 ) ;
V_2 = V_5 -> V_54 [ 1 ] ;
if ( V_2 -> V_55 & V_131 ) {
V_87 = F_60 ( V_2 , 0 ) ;
if ( V_87 )
goto V_219;
}
if ( V_5 -> V_64 != V_65 )
F_46 ( V_5 -> V_8 ,
L_82 ,
V_78 [ V_5 -> V_64 ] ) ;
V_87 = F_83 ( V_5 ) ;
if ( V_87 == V_220 ) {
V_5 -> V_112 = true ;
return;
}
if ( ! V_87 ) {
V_5 -> V_64 = V_203 ;
F_2 ( V_5 -> V_8 ,
L_83 , V_78 [ V_5 -> V_64 ] ) ;
return;
}
V_219:
F_71 ( V_5 ) ;
}
void F_85 ( struct V_5 * V_5 , struct V_143 * V_144 )
{
struct V_156 * V_67 ;
struct V_1 * V_2 ;
int V_87 = 0 ;
F_2 ( V_5 -> V_8 ,
L_84 ,
V_9 , V_78 [ V_5 -> V_64 ] ) ;
V_2 = V_5 -> V_54 [ 1 ] ;
if ( V_5 -> V_74 )
V_5 -> V_74 = false ;
if ( V_2 -> V_55 & V_131 ) {
V_87 = F_60 ( V_2 , 0 ) ;
if ( V_87 )
goto V_219;
}
if ( ( V_5 -> V_64 != V_75 ) &&
( V_5 -> V_64 != V_203 ) )
F_16 ( V_5 -> V_8 ,
L_85 ,
V_78 [ V_5 -> V_64 ] ) ;
if ( V_5 -> V_64 == V_203 ) {
V_5 -> V_64 = V_221 ;
F_2 ( V_5 -> V_8 ,
L_86 ) ;
return;
}
V_67 = & V_5 -> V_67 ;
if ( ! F_26 ( V_67 -> V_77 ) ) {
V_87 = F_83 ( V_5 ) ;
if ( V_87 == V_220 ) {
V_5 -> V_112 = true ;
return;
}
}
if ( ! V_87 ) {
F_50 ( V_5 ) ;
V_5 -> V_64 = V_113 ;
F_2 ( V_5 -> V_8 ,
L_83 , V_78 [ V_5 -> V_64 ] ) ;
return;
}
V_219:
F_71 ( V_5 ) ;
}
static void F_86 ( struct V_5 * V_5 , struct V_143 * V_144 )
{
F_2 ( V_5 -> V_8 , L_31 , V_9 ) ;
switch ( V_5 -> V_64 ) {
case V_203 :
V_5 -> V_64 = V_75 ;
break;
case V_113 :
V_5 -> V_64 = V_130 ;
if ( V_5 -> V_137 ) {
int V_87 ;
F_2 ( V_5 -> V_8 , L_87 , V_5 -> V_137 ) ;
V_87 = F_64 ( V_5 ) ;
if ( V_87 < 0 ) {
F_16 ( V_5 -> V_8 , L_88 ) ;
return;
}
V_5 -> V_137 = 0 ;
}
break;
case V_221 :
F_85 ( V_5 , V_144 ) ;
break;
default:
F_16 ( V_5 -> V_8 ,
L_89 ,
V_78 [ V_5 -> V_64 ] ) ;
}
}
void F_87 ( struct V_5 * V_5 , struct V_143 * V_144 )
{
struct V_1 * V_2 ;
T_1 V_151 ;
T_5 V_94 ;
V_94 = ( F_68 ( V_144 -> V_18 [ 3 ] ) >> 4 ) & 0x1f ;
V_2 = V_5 -> V_54 [ V_94 ] ;
if ( ! V_2 || ! ( V_2 -> V_55 & V_108 ) ) {
F_16 ( V_5 -> V_8 , L_90 ) ;
return;
}
if ( V_5 -> V_169 & V_222 ) {
V_5 -> V_169 &= ~ ( V_222 ) ;
F_2 ( V_5 -> V_8 , L_91 ,
V_9 ) ;
}
V_151 = F_67 ( F_68 ( V_144 -> V_18 [ 3 ] ) ) ;
F_88 ( V_5 -> V_8 , L_92 ,
V_9 , V_151 , V_2 -> V_10 ) ;
switch ( V_151 ) {
case V_223 :
case V_153 :
F_65 ( V_5 , V_2 , V_144 ) ;
if ( V_94 == 1 )
F_86 ( V_5 , V_144 ) ;
break;
case V_224 :
case V_225 :
case V_226 :
if ( V_94 != 1 ) {
F_16 ( V_5 -> V_8 ,
L_93 ) ;
return;
}
V_5 -> V_227 [ V_151 - V_224 ] ( V_5 , V_144 ) ;
break;
case V_228 :
if ( V_94 == 1 ) {
F_2 ( V_5 -> V_8 , L_94 ,
V_5 -> V_74 ) ;
if ( V_5 -> V_74 ) {
F_82 ( V_5 ) ;
return;
}
}
F_46 ( V_5 -> V_8 , L_95 ) ;
break;
default:
F_46 ( V_5 -> V_8 , L_96 , V_151 ) ;
break;
}
}
static int F_89 ( struct V_103 * V_201 ,
struct V_114 * V_202 , T_6 V_229 )
{
struct V_32 * V_33 ;
unsigned long V_55 ;
struct V_1 * V_2 ;
struct V_5 * V_5 ;
int V_87 ;
if ( ! V_201 || ! V_201 -> V_20 )
return - V_105 ;
if ( ! V_202 || ! V_202 -> V_101 || ! V_202 -> V_200 )
return - V_45 ;
V_2 = F_90 ( V_201 ) ;
V_33 = F_91 ( V_202 ) ;
V_5 = V_2 -> V_5 ;
F_2 ( V_5 -> V_8 , L_97 , V_9 , V_2 , V_33 ) ;
F_2 ( V_5 -> V_8 , L_98 ,
V_202 , V_2 -> V_10 , V_202 -> V_37 , V_202 -> V_230 ) ;
if ( ! V_2 -> V_103 . V_20 ) {
F_46 ( V_5 -> V_8 ,
L_99 ,
V_202 , V_2 -> V_10 ) ;
return - V_105 ;
}
if ( V_202 -> V_37 > V_231 ) {
F_46 ( V_5 -> V_8 ,
L_100 ,
V_231 , V_202 -> V_37 ) ;
return - V_187 ;
}
F_92 ( & V_5 -> V_102 , V_55 ) ;
if ( V_2 == V_5 -> V_54 [ 1 ] )
V_87 = F_51 ( V_2 , V_33 ) ;
else
V_87 = F_54 ( V_2 , V_33 ) ;
F_93 ( & V_5 -> V_102 , V_55 ) ;
return V_87 ;
}
static int F_94 ( struct V_103 * V_201 ,
struct V_114 * V_202 )
{
struct V_32 * V_33 ;
unsigned long V_55 ;
struct V_1 * V_2 ;
struct V_5 * V_5 ;
int V_87 ;
if ( ! V_201 || ! V_202 )
return - V_45 ;
V_2 = F_90 ( V_201 ) ;
V_33 = F_91 ( V_202 ) ;
V_5 = V_2 -> V_5 ;
F_2 ( V_5 -> V_8 , L_101 , V_9 , V_2 -> V_10 , V_33 ) ;
F_34 ( V_5 , V_2 ) ;
F_92 ( & V_5 -> V_102 , V_55 ) ;
F_95 (req, &ep->queue, queue) {
if ( & V_33 -> V_36 == V_202 )
break;
}
if ( & V_33 -> V_36 != V_202 ) {
F_93 ( & V_5 -> V_102 , V_55 ) ;
F_16 ( V_5 -> V_8 , L_102 ) ;
return - V_45 ;
}
V_87 = F_55 ( V_2 , V_33 ) ;
if ( V_87 ) {
V_87 = - V_187 ;
goto V_219;
}
F_35 ( V_2 , V_33 , - V_232 ) ;
V_219:
F_34 ( V_5 , V_2 ) ;
F_93 ( & V_5 -> V_102 , V_55 ) ;
return V_87 ;
}
static int F_96 ( struct V_103 * V_201 , int V_129 )
{
unsigned long V_55 ;
struct V_1 * V_2 ;
struct V_5 * V_5 ;
int V_87 ;
V_2 = F_90 ( V_201 ) ;
V_5 = V_2 -> V_5 ;
F_2 ( V_5 -> V_8 , L_37 , V_9 , V_2 -> V_10 , V_129 ) ;
F_92 ( & V_5 -> V_102 , V_55 ) ;
if ( F_10 ( V_2 -> V_103 . V_20 ) )
V_87 = - V_45 ;
else if ( ! F_43 ( & V_2 -> V_99 ) )
V_87 = - V_233 ;
else
V_87 = F_60 ( V_2 , V_129 ) ;
F_93 ( & V_5 -> V_102 , V_55 ) ;
return V_87 ;
}
static struct V_114 * F_97 ( struct V_103 * V_201 ,
T_6 V_229 )
{
struct V_32 * V_33 ;
struct V_1 * V_2 ;
V_33 = F_11 ( sizeof( * V_33 ) , V_229 ) ;
if ( ! V_33 )
return NULL ;
V_2 = F_90 ( V_201 ) ;
V_33 -> V_2 = V_2 ;
V_33 -> V_53 = V_2 -> V_94 ;
V_33 -> V_36 . V_13 = V_234 ;
F_2 ( V_2 -> V_5 -> V_8 , L_101 , V_9 , V_2 -> V_10 , V_33 ) ;
return & V_33 -> V_36 ;
}
static void F_98 ( struct V_103 * V_201 ,
struct V_114 * V_202 )
{
struct V_32 * V_33 ;
V_33 = F_91 ( V_202 ) ;
F_4 ( V_33 ) ;
}
static int F_99 ( struct V_103 * V_201 ,
const struct V_235 * V_20 )
{
unsigned long V_55 ;
struct V_1 * V_2 ;
struct V_5 * V_5 ;
int V_87 ;
if ( ! V_201 || ! V_20 || V_20 -> V_236 != V_237 ) {
F_100 ( L_103 ) ;
return - V_45 ;
}
if ( ! V_20 -> V_238 ) {
F_100 ( L_104 ) ;
return - V_45 ;
}
V_2 = F_90 ( V_201 ) ;
V_5 = V_2 -> V_5 ;
if ( V_2 == V_5 -> V_54 [ 1 ] )
return - V_45 ;
if ( ! V_5 -> V_217
|| V_5 -> V_71 . V_127 == V_128 ) {
return - V_105 ;
}
F_2 ( V_5 -> V_8 , L_105 , V_9 , V_2 -> V_10 ) ;
F_92 ( & V_5 -> V_102 , V_55 ) ;
V_2 -> V_20 = V_20 ;
V_2 -> V_106 = V_201 -> V_106 ;
V_87 = F_47 ( V_2 ) ;
F_93 ( & V_5 -> V_102 , V_55 ) ;
return V_87 ;
}
static int F_101 ( struct V_103 * V_201 )
{
unsigned long V_55 ;
struct V_1 * V_2 ;
struct V_5 * V_5 ;
int V_87 ;
if ( ! V_201 ) {
F_100 ( L_106 ) ;
return - V_45 ;
}
V_2 = F_90 ( V_201 ) ;
V_5 = V_2 -> V_5 ;
if ( V_2 == V_5 -> V_54 [ 1 ] ) {
F_46 ( V_5 -> V_8 , L_107 , V_9 ) ;
return - V_45 ;
}
F_2 ( V_5 -> V_8 ,
L_108 ,
V_9 , V_2 -> V_10 , V_2 -> V_55 ) ;
if ( ! ( V_2 -> V_55 & V_108 ) ) {
F_46 ( V_5 -> V_8 , L_109 , V_2 -> V_10 ) ;
return 0 ;
}
F_92 ( & V_5 -> V_102 , V_55 ) ;
V_87 = F_41 ( V_2 ) ;
F_93 ( & V_5 -> V_102 , V_55 ) ;
return V_87 ;
}
static int F_102 ( struct V_5 * V_5 , T_1 V_53 , T_1 V_63 )
{
struct V_1 * V_2 ;
F_2 ( V_5 -> V_8 , L_110 , V_9 , V_53 , V_63 ) ;
V_2 = F_11 ( sizeof( * V_2 ) , V_239 ) ;
if ( ! V_2 )
return - V_25 ;
V_2 -> V_5 = V_5 ;
V_2 -> V_63 = V_63 ;
if ( V_53 == 1 ) {
V_2 -> V_94 = 1 ;
V_5 -> V_54 [ V_2 -> V_94 ] = V_2 ;
snprintf ( V_2 -> V_10 , sizeof( V_2 -> V_10 ) , L_111 , V_53 - 1 ) ;
F_103 ( & V_2 -> V_103 , V_240 ) ;
V_2 -> V_106 = NULL ;
V_5 -> V_71 . V_72 = & V_2 -> V_103 ;
} else {
if ( V_63 )
V_2 -> V_94 = V_53 * 2 - 1 ;
else
V_2 -> V_94 = V_53 * 2 - 2 ;
V_5 -> V_54 [ V_2 -> V_94 ] = V_2 ;
snprintf ( V_2 -> V_10 , sizeof( V_2 -> V_10 ) , L_112 , V_53 - 1 ,
V_63 & 1 ? L_113 : L_114 ) ;
F_103 ( & V_2 -> V_103 , 1024 ) ;
V_2 -> V_103 . V_241 = 0 ;
F_33 ( & V_2 -> V_103 . V_133 , & V_5 -> V_71 . V_133 ) ;
}
V_2 -> V_103 . V_242 = & V_243 ;
V_2 -> V_103 . V_10 = V_2 -> V_10 ;
V_2 -> V_55 = 0 ;
V_2 -> V_152 = false ;
F_2 ( V_5 -> V_8 , L_115 ,
V_2 , V_2 -> V_103 . V_10 , V_53 , V_2 -> V_94 ) ;
F_104 ( & V_2 -> V_99 ) ;
return 0 ;
}
int F_105 ( struct V_5 * V_5 )
{
T_5 V_53 ;
int V_87 ;
F_2 ( V_5 -> V_8 , L_29 , V_9 ) ;
F_104 ( & V_5 -> V_71 . V_133 ) ;
V_87 = F_102 ( V_5 , 1 , 0 ) ;
if ( V_87 ) {
F_16 ( V_5 -> V_8 , L_116 , V_87 ) ;
return V_87 ;
}
for ( V_53 = 2 ; V_53 <= V_5 -> V_132 / 2 ; V_53 ++ ) {
V_87 = F_102 ( V_5 , V_53 , 0 ) ;
if ( V_87 ) {
F_16 ( V_5 -> V_8 ,
L_117 ,
V_53 , V_87 ) ;
return V_87 ;
}
V_87 = F_102 ( V_5 , V_53 , 1 ) ;
if ( V_87 ) {
F_16 ( V_5 -> V_8 ,
L_117 ,
V_53 , V_87 ) ;
return V_87 ;
}
}
return 0 ;
}
