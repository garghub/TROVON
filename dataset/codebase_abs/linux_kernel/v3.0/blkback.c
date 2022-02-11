static inline int F_1 ( struct V_1 * V_2 , int V_3 )
{
return ( V_2 - V_4 -> V_5 ) *
V_6 + V_3 ;
}
static inline unsigned long F_2 ( struct V_1 * V_2 , int V_3 )
{
unsigned long V_7 = F_3 ( V_4 -> V_8 ( V_2 , V_3 ) ) ;
return ( unsigned long ) F_4 ( V_7 ) ;
}
static struct V_1 * F_5 ( void )
{
struct V_1 * V_2 = NULL ;
unsigned long V_9 ;
F_6 ( & V_4 -> V_10 , V_9 ) ;
if ( ! F_7 ( & V_4 -> V_11 ) ) {
V_2 = F_8 ( V_4 -> V_11 . V_12 , struct V_1 ,
V_13 ) ;
F_9 ( & V_2 -> V_13 ) ;
}
F_10 ( & V_4 -> V_10 , V_9 ) ;
return V_2 ;
}
static void F_11 ( struct V_1 * V_2 )
{
unsigned long V_9 ;
int V_14 ;
F_6 ( & V_4 -> V_10 , V_9 ) ;
V_14 = F_7 ( & V_4 -> V_11 ) ;
F_12 ( & V_2 -> V_13 , & V_4 -> V_11 ) ;
F_10 ( & V_4 -> V_10 , V_9 ) ;
if ( V_14 )
F_13 ( & V_4 -> V_15 ) ;
}
static int F_14 ( struct V_16 * V_2 , struct V_17 * V_18 ,
int V_19 )
{
struct V_20 * V_21 = & V_18 -> V_21 ;
int V_22 = - V_23 ;
if ( ( V_19 != V_24 ) && V_21 -> V_25 )
goto V_26;
if ( F_15 ( V_2 -> V_27 ) ) {
T_1 V_28 = V_2 -> V_29 + V_2 -> V_27 ;
if ( F_16 ( V_28 < V_2 -> V_29 ) )
goto V_26;
if ( F_16 ( V_28 > F_17 ( V_21 ) ) )
goto V_26;
}
V_2 -> V_30 = V_21 -> V_31 ;
V_2 -> V_32 = V_21 -> V_32 ;
V_22 = 0 ;
V_26:
return V_22 ;
}
static void F_18 ( struct V_17 * V_18 )
{
struct V_20 * V_21 = & V_18 -> V_21 ;
struct V_33 V_34 ;
int V_35 ;
struct V_36 * V_30 = F_19 ( V_18 -> V_37 ) ;
unsigned long long V_38 = F_17 ( V_21 ) ;
F_20 ( V_39 L_1 ,
V_18 -> V_40 , F_21 ( V_21 -> V_31 ) , F_22 ( V_21 -> V_31 ) ) ;
F_20 ( V_39 L_2 , V_38 ) ;
V_21 -> V_41 = V_38 ;
V_42:
V_35 = F_23 ( & V_34 ) ;
if ( V_35 ) {
F_24 ( V_39 L_3 ) ;
return;
}
V_35 = F_25 ( V_34 , V_30 -> V_43 , L_4 , L_5 ,
( unsigned long long ) F_17 ( V_21 ) ) ;
if ( V_35 ) {
F_24 ( V_39 L_6 ) ;
goto abort;
}
V_35 = F_25 ( V_34 , V_30 -> V_43 , L_7 , L_8 , V_30 -> V_44 ) ;
if ( V_35 ) {
F_24 ( V_39 L_9 ) ;
goto abort;
}
V_35 = F_26 ( V_34 , 0 ) ;
if ( V_35 == - V_45 )
goto V_42;
if ( V_35 )
F_24 ( V_39 L_10 ) ;
return;
abort:
F_26 ( V_34 , 1 ) ;
}
static void F_27 ( struct V_17 * V_18 )
{
V_18 -> V_46 = 1 ;
F_13 ( & V_18 -> V_47 ) ;
}
T_2 F_28 ( int V_48 , void * V_49 )
{
F_27 ( V_49 ) ;
return V_50 ;
}
static void F_29 ( struct V_17 * V_18 )
{
F_20 ( L_11 ,
V_51 -> V_52 , V_18 -> V_53 ,
V_18 -> V_54 , V_18 -> V_55 , V_18 -> V_56 ) ;
V_18 -> V_57 = V_58 + F_30 ( 10 * 1000 ) ;
V_18 -> V_54 = 0 ;
V_18 -> V_55 = 0 ;
V_18 -> V_53 = 0 ;
}
int F_31 ( void * V_59 )
{
struct V_17 * V_18 = V_59 ;
struct V_20 * V_21 = & V_18 -> V_21 ;
F_32 ( V_18 ) ;
while ( ! F_33 () ) {
if ( F_34 () )
continue;
if ( F_16 ( V_21 -> V_41 != F_17 ( V_21 ) ) )
F_18 ( V_18 ) ;
F_35 (
V_18 -> V_47 ,
V_18 -> V_46 || F_33 () ) ;
F_35 (
V_4 -> V_15 ,
! F_7 ( & V_4 -> V_11 ) ||
F_33 () ) ;
V_18 -> V_46 = 0 ;
F_36 () ;
if ( F_37 ( V_18 ) )
V_18 -> V_46 = 1 ;
if ( V_60 && F_38 ( V_58 , V_18 -> V_57 ) )
F_29 ( V_18 ) ;
}
if ( V_60 )
F_29 ( V_18 ) ;
V_18 -> V_61 = NULL ;
F_39 ( V_18 ) ;
return 0 ;
}
static void F_40 ( struct V_1 * V_2 )
{
struct V_62 V_63 [ V_6 ] ;
unsigned int V_64 , V_65 = 0 ;
T_3 V_66 ;
int V_67 ;
for ( V_64 = 0 ; V_64 < V_2 -> V_68 ; V_64 ++ ) {
V_66 = F_41 ( V_2 , V_64 ) ;
if ( V_66 == V_69 )
continue;
F_42 ( & V_63 [ V_65 ] , F_2 ( V_2 , V_64 ) ,
V_70 , V_66 ) ;
F_41 ( V_2 , V_64 ) = V_69 ;
V_65 ++ ;
}
V_67 = F_43 (
V_71 , V_63 , V_65 ) ;
F_44 ( V_67 ) ;
for ( V_64 = 0 ; V_64 < V_65 ; V_64 ++ ) {
V_67 = F_45 (
F_46 ( V_63 [ V_64 ] . V_72 ) , false ) ;
if ( V_67 ) {
F_47 ( V_39 L_12 ,
( unsigned long ) V_63 [ V_64 ] . V_72 ) ;
continue;
}
}
}
static int F_48 ( struct V_73 * V_2 ,
struct V_1 * V_1 ,
struct V_74 V_3 [] )
{
struct V_75 V_76 [ V_6 ] ;
int V_64 ;
int V_77 = V_2 -> V_78 ;
int V_67 = 0 ;
for ( V_64 = 0 ; V_64 < V_77 ; V_64 ++ ) {
T_4 V_9 ;
V_9 = V_70 ;
if ( V_1 -> V_19 != V_79 )
V_9 |= V_80 ;
F_49 ( & V_76 [ V_64 ] , F_2 ( V_1 , V_64 ) , V_9 ,
V_2 -> V_81 . V_82 . V_3 [ V_64 ] . V_83 ,
V_1 -> V_18 -> V_40 ) ;
}
V_67 = F_43 ( V_84 , V_76 , V_77 ) ;
F_44 ( V_67 ) ;
for ( V_64 = 0 ; V_64 < V_77 ; V_64 ++ ) {
if ( F_16 ( V_76 [ V_64 ] . V_85 != 0 ) ) {
F_50 ( V_39 L_13 ) ;
V_76 [ V_64 ] . V_66 = V_69 ;
V_67 |= 1 ;
}
F_41 ( V_1 , V_64 ) = V_76 [ V_64 ] . V_66 ;
if ( V_67 )
continue;
V_67 = F_51 ( F_52 ( V_76 [ V_64 ] . V_86 ) ,
V_4 -> V_8 ( V_1 , V_64 ) , false ) ;
if ( V_67 ) {
F_47 ( V_39 L_14 ,
( unsigned long ) V_76 [ V_64 ] . V_86 , V_67 ) ;
continue;
}
V_3 [ V_64 ] . V_87 = V_76 [ V_64 ] . V_86 |
( V_2 -> V_81 . V_82 . V_3 [ V_64 ] . V_88 << 9 ) ;
}
return V_67 ;
}
static void F_53 ( struct V_1 * V_1 , int error )
{
if ( ( V_1 -> V_19 == V_89 ) &&
( error == - V_90 ) ) {
F_50 ( V_39 L_15 ) ;
F_54 ( V_91 , V_1 -> V_18 -> V_37 , 0 ) ;
V_1 -> V_85 = V_92 ;
} else if ( error ) {
F_50 ( V_39 L_16
L_17 , error ) ;
V_1 -> V_85 = V_93 ;
}
if ( F_55 ( & V_1 -> V_94 ) ) {
F_40 ( V_1 ) ;
F_56 ( V_1 -> V_18 , V_1 -> V_95 ,
V_1 -> V_19 , V_1 -> V_85 ) ;
F_39 ( V_1 -> V_18 ) ;
F_11 ( V_1 ) ;
}
}
static void F_57 ( struct V_96 * V_96 , int error )
{
F_53 ( V_96 -> V_97 , error ) ;
F_58 ( V_96 ) ;
}
static int F_37 ( struct V_17 * V_18 )
{
union V_98 * V_99 = & V_18 -> V_99 ;
struct V_73 V_2 ;
struct V_1 * V_1 ;
T_5 V_22 , V_100 ;
int V_101 = 0 ;
V_22 = V_99 -> V_102 . V_103 ;
V_100 = V_99 -> V_102 . V_104 -> V_105 ;
F_59 () ;
while ( V_22 != V_100 ) {
if ( F_60 ( & V_99 -> V_102 , V_22 ) )
break;
if ( F_33 () ) {
V_101 = 1 ;
break;
}
V_1 = F_5 () ;
if ( NULL == V_1 ) {
V_18 -> V_53 ++ ;
V_101 = 1 ;
break;
}
switch ( V_18 -> V_106 ) {
case V_107 :
memcpy ( & V_2 , F_61 ( & V_99 -> V_108 , V_22 ) , sizeof( V_2 ) ) ;
break;
case V_109 :
F_62 ( & V_2 , F_61 ( & V_99 -> V_110 , V_22 ) ) ;
break;
case V_111 :
F_63 ( & V_2 , F_61 ( & V_99 -> V_112 , V_22 ) ) ;
break;
default:
F_64 () ;
}
V_99 -> V_102 . V_103 = ++ V_22 ;
F_65 () ;
if ( F_66 ( V_18 , & V_2 , V_1 ) )
break;
F_67 () ;
}
return V_101 ;
}
static int F_66 ( struct V_17 * V_18 ,
struct V_73 * V_2 ,
struct V_1 * V_1 )
{
struct V_16 V_113 ;
struct V_74 V_3 [ V_6 ] ;
unsigned int V_77 ;
struct V_96 * V_96 = NULL ;
struct V_96 * V_114 [ V_6 ] ;
int V_64 , V_115 = 0 ;
int V_19 ;
struct V_116 V_117 ;
switch ( V_2 -> V_19 ) {
case V_79 :
V_18 -> V_54 ++ ;
V_19 = V_24 ;
break;
case V_118 :
V_18 -> V_55 ++ ;
V_19 = V_119 ;
break;
case V_89 :
V_18 -> V_56 ++ ;
V_19 = V_120 ;
break;
case V_121 :
default:
V_19 = 0 ;
goto V_122;
break;
}
V_77 = V_2 -> V_78 ;
if ( F_16 ( V_77 == 0 && V_19 != V_120 ) ||
F_16 ( V_77 > V_6 ) ) {
F_50 ( V_39 L_18 ,
V_77 ) ;
goto V_122;
}
V_113 . V_30 = V_2 -> V_66 ;
V_113 . V_29 = V_2 -> V_81 . V_82 . V_29 ;
V_113 . V_27 = 0 ;
V_1 -> V_18 = V_18 ;
V_1 -> V_95 = V_2 -> V_95 ;
V_1 -> V_19 = V_2 -> V_19 ;
V_1 -> V_85 = V_123 ;
V_1 -> V_68 = V_77 ;
for ( V_64 = 0 ; V_64 < V_77 ; V_64 ++ ) {
V_3 [ V_64 ] . V_124 = V_2 -> V_81 . V_82 . V_3 [ V_64 ] . V_125 -
V_2 -> V_81 . V_82 . V_3 [ V_64 ] . V_88 + 1 ;
if ( ( V_2 -> V_81 . V_82 . V_3 [ V_64 ] . V_125 >= ( V_126 >> 9 ) ) ||
( V_2 -> V_81 . V_82 . V_3 [ V_64 ] . V_125 < V_2 -> V_81 . V_82 . V_3 [ V_64 ] . V_88 ) )
goto V_122;
V_113 . V_27 += V_3 [ V_64 ] . V_124 ;
}
if ( F_14 ( & V_113 , V_18 , V_19 ) != 0 ) {
F_50 ( V_39 L_19 ,
V_19 == V_24 ? L_20 : L_21 ,
V_113 . V_29 ,
V_113 . V_29 + V_113 . V_27 , V_113 . V_30 ) ;
goto V_122;
}
for ( V_64 = 0 ; V_64 < V_77 ; V_64 ++ ) {
if ( ( ( int ) V_113 . V_29 | ( int ) V_3 [ V_64 ] . V_124 ) &
( ( F_68 ( V_113 . V_32 ) >> 9 ) - 1 ) ) {
F_50 ( V_39 L_22 ,
V_18 -> V_40 ) ;
goto V_122;
}
}
if ( F_48 ( V_2 , V_1 , V_3 ) )
goto V_127;
F_32 ( V_18 ) ;
for ( V_64 = 0 ; V_64 < V_77 ; V_64 ++ ) {
while ( ( V_96 == NULL ) ||
( F_69 ( V_96 ,
V_4 -> V_8 ( V_1 , V_64 ) ,
V_3 [ V_64 ] . V_124 << 9 ,
V_3 [ V_64 ] . V_87 & ~ V_128 ) == 0 ) ) {
V_96 = F_70 ( V_129 , V_77 - V_64 ) ;
if ( F_16 ( V_96 == NULL ) )
goto V_130;
V_114 [ V_115 ++ ] = V_96 ;
V_96 -> V_131 = V_113 . V_32 ;
V_96 -> V_97 = V_1 ;
V_96 -> V_132 = F_57 ;
V_96 -> V_133 = V_113 . V_29 ;
}
V_113 . V_29 += V_3 [ V_64 ] . V_124 ;
}
if ( ! V_96 ) {
F_44 ( V_19 != V_120 ) ;
V_96 = F_70 ( V_129 , 0 ) ;
if ( F_16 ( V_96 == NULL ) )
goto V_130;
V_114 [ V_115 ++ ] = V_96 ;
V_96 -> V_131 = V_113 . V_32 ;
V_96 -> V_97 = V_1 ;
V_96 -> V_132 = F_57 ;
}
F_71 ( & V_1 -> V_94 , V_115 ) ;
F_72 ( & V_117 ) ;
for ( V_64 = 0 ; V_64 < V_115 ; V_64 ++ )
F_73 ( V_19 , V_114 [ V_64 ] ) ;
F_74 ( & V_117 ) ;
if ( V_19 == V_24 )
V_18 -> V_134 += V_113 . V_27 ;
else if ( V_19 == V_135 || V_19 == V_120 )
V_18 -> V_136 += V_113 . V_27 ;
return 0 ;
V_127:
F_40 ( V_1 ) ;
V_122:
F_56 ( V_18 , V_2 -> V_95 , V_2 -> V_19 , V_93 ) ;
F_11 ( V_1 ) ;
F_75 ( 1 ) ;
return - V_137 ;
V_130:
for ( V_64 = 0 ; V_64 < V_115 ; V_64 ++ )
F_58 ( V_114 [ V_64 ] ) ;
F_53 ( V_1 , - V_138 ) ;
F_75 ( 1 ) ;
return - V_137 ;
}
static void F_56 ( struct V_17 * V_18 , T_6 V_95 ,
unsigned short V_139 , int V_140 )
{
struct V_141 V_142 ;
unsigned long V_9 ;
union V_98 * V_99 = & V_18 -> V_99 ;
int V_101 = 0 ;
int V_143 ;
V_142 . V_95 = V_95 ;
V_142 . V_19 = V_139 ;
V_142 . V_85 = V_140 ;
F_6 ( & V_18 -> V_144 , V_9 ) ;
switch ( V_18 -> V_106 ) {
case V_107 :
memcpy ( F_76 ( & V_99 -> V_108 , V_99 -> V_108 . V_145 ) ,
& V_142 , sizeof( V_142 ) ) ;
break;
case V_109 :
memcpy ( F_76 ( & V_99 -> V_110 , V_99 -> V_110 . V_145 ) ,
& V_142 , sizeof( V_142 ) ) ;
break;
case V_111 :
memcpy ( F_76 ( & V_99 -> V_112 , V_99 -> V_112 . V_145 ) ,
& V_142 , sizeof( V_142 ) ) ;
break;
default:
F_64 () ;
}
V_99 -> V_102 . V_145 ++ ;
F_77 ( & V_99 -> V_102 , V_143 ) ;
if ( V_99 -> V_102 . V_145 == V_99 -> V_102 . V_103 ) {
F_78 ( & V_99 -> V_102 , V_101 ) ;
} else if ( F_79 ( & V_99 -> V_102 ) ) {
V_101 = 1 ;
}
F_10 ( & V_18 -> V_144 , V_9 ) ;
if ( V_101 )
F_27 ( V_18 ) ;
if ( V_143 )
F_80 ( V_18 -> V_48 ) ;
}
static int T_7 F_81 ( void )
{
int V_64 , V_146 ;
int V_22 = 0 ;
if ( ! F_82 () )
return - V_147 ;
V_4 = F_83 ( sizeof( struct V_148 ) , V_129 ) ;
if ( ! V_4 ) {
F_47 ( V_39 L_23 , V_149 ) ;
return - V_150 ;
}
V_146 = V_151 * V_6 ;
V_4 -> V_5 = F_84 ( sizeof( V_4 -> V_5 [ 0 ] ) *
V_151 , V_129 ) ;
V_4 -> V_152 = F_83 ( sizeof( V_4 -> V_152 [ 0 ] ) *
V_146 , V_129 ) ;
V_4 -> V_153 = F_83 ( sizeof( V_4 -> V_153 [ 0 ] ) *
V_146 , V_129 ) ;
if ( ! V_4 -> V_5 || ! V_4 -> V_152 ||
! V_4 -> V_153 ) {
V_22 = - V_150 ;
goto V_154;
}
for ( V_64 = 0 ; V_64 < V_146 ; V_64 ++ ) {
V_4 -> V_152 [ V_64 ] = V_69 ;
V_4 -> V_153 [ V_64 ] = F_85 ( V_129 ) ;
if ( V_4 -> V_153 [ V_64 ] == NULL ) {
V_22 = - V_150 ;
goto V_154;
}
}
V_22 = F_86 () ;
if ( V_22 )
goto V_155;
memset ( V_4 -> V_5 , 0 , sizeof( V_4 -> V_5 ) ) ;
F_87 ( & V_4 -> V_11 ) ;
F_88 ( & V_4 -> V_10 ) ;
F_89 ( & V_4 -> V_15 ) ;
for ( V_64 = 0 ; V_64 < V_151 ; V_64 ++ )
F_90 ( & V_4 -> V_5 [ V_64 ] . V_13 ,
& V_4 -> V_11 ) ;
V_22 = F_91 () ;
if ( V_22 )
goto V_155;
return 0 ;
V_154:
F_47 ( V_39 L_24 , V_149 ) ;
V_155:
F_92 ( V_4 -> V_5 ) ;
F_92 ( V_4 -> V_152 ) ;
if ( V_4 -> V_153 ) {
for ( V_64 = 0 ; V_64 < V_146 ; V_64 ++ ) {
if ( V_4 -> V_153 [ V_64 ] )
F_93 ( V_4 -> V_153 [ V_64 ] ) ;
}
F_92 ( V_4 -> V_153 ) ;
}
F_92 ( V_4 ) ;
V_4 = NULL ;
return V_22 ;
}
