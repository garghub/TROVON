static void F_1 ( struct V_1 * V_2 )
{
int V_3 ;
T_1 * V_4 = V_2 -> V_5 ;
for ( V_3 = 0 ; V_3 < 12 * 4 ; V_3 += 4 )
F_2 ( & V_2 -> V_6 -> V_7 , L_1 ,
V_3 , * V_4 ++ ) ;
}
static int F_3 ( struct V_1 * V_2 )
{
V_2 -> V_5 = F_4 ( & V_2 -> V_6 -> V_7 ,
V_2 -> V_8 ,
& V_2 -> V_9 , V_10 ) ;
if ( ! V_2 -> V_5 ) {
F_5 ( & V_2 -> V_6 -> V_7 ,
L_2 ) ;
return - V_11 ;
}
F_2 ( & V_2 -> V_6 -> V_7 ,
L_3 ,
V_2 -> V_8 , V_2 -> V_5 ,
( unsigned long long ) V_2 -> V_9 ) ;
return 0 ;
}
static void F_6 ( struct V_1 * V_2 )
{
F_7 ( & V_2 -> V_6 -> V_7 , V_2 -> V_8 ,
V_2 -> V_5 , V_2 -> V_9 ) ;
}
static void * F_8 ( struct V_1 * V_2 ,
T_2 V_12 )
{
return V_2 -> V_5 + ( V_12 - V_2 -> V_9 ) ;
}
static int F_9 ( struct V_13 * V_14 , struct V_15 * V_16 )
{
struct V_1 * V_2 ;
V_2 = V_17 ;
V_16 -> V_18 = V_2 ;
if ( F_10 ( 0 , & V_2 -> V_19 ) )
return - V_20 ;
return 0 ;
}
static int F_11 ( struct V_13 * V_13 , struct V_15 * V_21 )
{
struct V_1 * V_2 ;
V_2 = V_17 ;
V_21 -> V_18 = V_2 ;
return 0 ;
}
static int F_12 ( struct V_13 * V_13 , struct V_15 * V_21 )
{
struct V_1 * V_2 = V_21 -> V_18 ;
F_13 ( 0 , & V_2 -> V_19 ) ;
return 0 ;
}
static int F_14 ( struct V_13 * V_13 , struct V_15 * V_21 )
{
struct V_1 * V_2 = V_17 ;
int error = 0 ;
V_21 -> V_18 = V_2 ;
if ( F_10 ( 0 , & V_2 -> V_22 ) )
error = - V_20 ;
return error ;
}
static int F_15 ( struct V_13 * V_13 , struct V_15 * V_21 )
{
struct V_1 * V_2 = V_21 -> V_18 ;
F_2 ( & V_2 -> V_6 -> V_7 , L_4 ,
V_23 -> V_24 ) ;
F_13 ( 0 , & V_2 -> V_22 ) ;
return 0 ;
}
static int F_16 ( struct V_1 * V_2 )
{
unsigned long V_25 ;
F_1 ( V_2 ) ;
F_17 ( & V_2 -> V_26 , V_25 ) ;
V_2 -> V_27 ++ ;
V_2 -> V_28 ++ ;
F_18 ( V_2 , V_29 , V_2 -> V_27 ) ;
V_2 -> V_27 ++ ;
F_19 ( & V_2 -> V_26 , V_25 ) ;
F_2 ( & V_2 -> V_6 -> V_7 ,
L_5 ,
V_2 -> V_27 , V_2 -> V_28 ) ;
return 0 ;
}
static int F_20 ( struct V_1 * V_2 )
{
int V_3 ;
int V_30 ;
struct V_31 * V_32 ;
for ( V_30 = 0 ; V_30 < V_2 -> V_33 ; V_30 ++ ) {
V_32 = & V_2 -> V_34 [ V_30 ] ;
if ( V_32 -> V_35 ) {
for ( V_3 = 0 ; V_3 < V_32 -> V_36 ; V_3 ++ ) {
F_21 ( & V_2 -> V_6 -> V_7 ,
V_32 -> V_35 [ V_3 ] . V_37 ,
V_32 -> V_35 [ V_3 ] . V_38 ,
V_39 ) ;
}
F_22 ( V_32 -> V_35 ) ;
}
if ( V_32 -> V_40 ) {
for ( V_3 = 0 ; V_3 < V_32 -> V_41 ; V_3 ++ ) {
F_21 ( & V_2 -> V_6 -> V_7 ,
V_32 -> V_40 [ V_3 ] . V_37 ,
V_32 -> V_40 [ V_3 ] . V_38 ,
V_42 ) ;
}
F_22 ( V_32 -> V_40 ) ;
}
if ( V_32 -> V_43 ) {
for ( V_3 = 0 ; V_3 < V_32 -> V_36 ; V_3 ++ ) {
F_23 ( V_32 -> V_43 [ V_3 ] ) ;
F_24 ( V_32 -> V_43 [ V_3 ] ) ;
}
F_22 ( V_32 -> V_43 ) ;
}
if ( V_32 -> V_44 ) {
for ( V_3 = 0 ; V_3 < V_32 -> V_41 ; V_3 ++ ) {
if ( ! F_25 ( V_32 -> V_44 [ V_3 ] ) )
F_26 ( V_32 -> V_44 [ V_3 ] ) ;
F_23 ( V_32 -> V_44 [ V_3 ] ) ;
F_24 ( V_32 -> V_44 [ V_3 ] ) ;
}
F_22 ( V_32 -> V_44 ) ;
}
V_32 -> V_43 = NULL ;
V_32 -> V_44 = NULL ;
V_32 -> V_36 = 0 ;
V_32 -> V_41 = 0 ;
V_32 -> V_35 = NULL ;
V_32 -> V_40 = NULL ;
V_32 -> V_45 = 0 ;
V_32 -> V_46 = 0 ;
}
V_2 -> V_33 = 0 ;
V_2 -> V_47 = 0 ;
return 0 ;
}
static int F_27 ( struct V_15 * V_21 ,
struct V_48 * V_49 )
{
struct V_1 * V_2 = V_21 -> V_18 ;
T_2 V_12 ;
int error = 0 ;
if ( ( V_49 -> V_50 - V_49 -> V_51 ) > V_52 ) {
error = - V_53 ;
goto V_54;
}
V_12 = V_2 -> V_9 ;
if ( F_28 ( V_49 , V_49 -> V_51 , V_12 >> V_55 ,
V_49 -> V_50 - V_49 -> V_51 , V_49 -> V_56 ) ) {
F_5 ( & V_2 -> V_6 -> V_7 , L_6 ) ;
error = - V_57 ;
goto V_54;
}
V_54:
return error ;
}
static unsigned int F_29 ( struct V_15 * V_21 ,
T_3 * V_58 )
{
T_1 V_59 = 0 ;
T_1 V_60 ;
unsigned long V_25 ;
struct V_1 * V_2 = V_21 -> V_18 ;
F_30 ( V_21 , & V_2 -> V_61 , V_58 ) ;
F_2 ( & V_2 -> V_6 -> V_7 , L_7 ,
V_2 -> V_27 , V_2 -> V_28 ) ;
F_17 ( & V_2 -> V_26 , V_25 ) ;
if ( V_2 -> V_27 == V_2 -> V_28 ) {
F_19 ( & V_2 -> V_26 , V_25 ) ;
V_60 = F_31 ( V_2 , V_62 ) ;
F_2 ( & V_2 -> V_6 -> V_7 ,
L_8 , V_60 ) ;
if ( ( V_60 >> 30 ) & 0x1 ) {
F_2 ( & V_2 -> V_6 -> V_7 , L_9 ) ;
V_59 |= V_63 ;
goto V_54;
}
if ( V_60 >> 31 ) {
F_2 ( & V_2 -> V_6 -> V_7 , L_10 ) ;
V_59 |= V_64 | V_65 ;
}
} else {
F_19 ( & V_2 -> V_26 , V_25 ) ;
F_2 ( & V_2 -> V_6 -> V_7 ,
L_11 ) ;
V_59 = 0 ;
}
V_54:
return V_59 ;
}
static int F_32 ( struct V_13 * V_13 , struct V_15 * V_21 )
{
struct V_1 * V_2 = V_21 -> V_18 ;
F_2 ( & V_2 -> V_6 -> V_7 , L_12 , V_23 -> V_24 ) ;
F_33 ( & V_2 -> V_66 ) ;
if ( V_2 -> V_67 == V_23 -> V_24 ) {
F_13 ( V_68 , & V_2 -> V_69 ) ;
F_13 ( V_70 , & V_2 -> V_69 ) ;
F_20 ( V_2 ) ;
F_34 ( & V_2 -> V_71 ) ;
V_2 -> V_67 = 0 ;
}
F_35 ( & V_2 -> V_66 ) ;
return 0 ;
}
static int F_36 ( struct V_15 * V_21 , struct V_48 * V_49 )
{
T_2 V_72 ;
struct V_1 * V_2 = V_21 -> V_18 ;
unsigned long error = 0 ;
F_37 ( V_2 -> V_71 ,
F_10 ( V_68 ,
& V_2 -> V_69 ) == 0 ) ;
if ( F_38 ( V_23 ) ) {
error = - V_73 ;
goto V_74;
}
F_33 ( & V_2 -> V_66 ) ;
V_2 -> V_67 = V_23 -> V_24 ;
F_35 ( & V_2 -> V_66 ) ;
V_2 -> V_75 = 0 ;
V_2 -> V_76 = 0 ;
if ( ( V_49 -> V_50 - V_49 -> V_51 ) > V_52 ) {
error = - V_53 ;
goto V_74;
}
F_2 ( & V_2 -> V_6 -> V_7 , L_13 , V_2 -> V_5 ) ;
V_72 = V_2 -> V_9 ;
if ( F_28 ( V_49 , V_49 -> V_51 , V_72 >> V_55 ,
V_49 -> V_50 - V_49 -> V_51 , V_49 -> V_56 ) ) {
F_5 ( & V_2 -> V_6 -> V_7 , L_6 ) ;
error = - V_57 ;
goto V_74;
}
goto V_54;
V_74:
F_13 ( V_68 , & V_2 -> V_69 ) ;
F_33 ( & V_2 -> V_66 ) ;
V_2 -> V_67 = 0 ;
F_35 ( & V_2 -> V_66 ) ;
F_34 ( & V_2 -> V_71 ) ;
V_54:
return error ;
}
static unsigned int F_39 ( struct V_15 * V_21 , T_3 * V_58 )
{
T_1 V_59 = 0 ;
T_1 V_77 = 0 ;
T_1 V_60 = 0 ;
unsigned long V_25 ;
struct V_1 * V_2 = V_21 -> V_18 ;
F_33 ( & V_2 -> V_66 ) ;
if ( V_23 -> V_24 != V_2 -> V_67 ) {
F_2 ( & V_2 -> V_6 -> V_7 , L_14 ) ;
V_59 = V_78 ;
F_35 ( & V_2 -> V_66 ) ;
goto V_54;
}
F_35 ( & V_2 -> V_66 ) ;
if ( ! F_40 ( V_70 , & V_2 -> V_69 ) ) {
V_59 = V_78 ;
goto V_54;
}
F_2 ( & V_2 -> V_6 -> V_7 , L_15 ) ;
F_30 ( V_21 , & V_2 -> V_71 , V_58 ) ;
F_2 ( & V_2 -> V_6 -> V_7 , L_16 ,
V_2 -> V_27 , V_2 -> V_28 ) ;
V_60 = F_31 ( V_2 , V_79 ) ;
if ( V_60 != 0x0 ) {
F_5 ( & V_2 -> V_6 -> V_7 , L_17 , V_60 ) ;
V_59 |= V_78 ;
goto V_54;
}
F_17 ( & V_2 -> V_26 , V_25 ) ;
if ( V_2 -> V_27 == V_2 -> V_28 ) {
F_19 ( & V_2 -> V_26 , V_25 ) ;
V_77 = F_31 ( V_2 , V_62 ) ;
F_2 ( & V_2 -> V_6 -> V_7 , L_18 ,
V_77 ) ;
if ( ( V_77 >> 30 ) & 0x1 ) {
F_2 ( & V_2 -> V_6 -> V_7 , L_19 ) ;
F_34 ( & V_2 -> V_61 ) ;
goto V_54;
}
if ( V_77 >> 31 ) {
F_2 ( & V_2 -> V_6 -> V_7 , L_20 ) ;
F_34 ( & V_2 -> V_61 ) ;
} else {
F_2 ( & V_2 -> V_6 -> V_7 , L_21 ) ;
F_13 ( V_70 , & V_2 -> V_69 ) ;
F_1 ( V_2 ) ;
F_2 ( & V_2 -> V_6 -> V_7 ,
L_22 ) ;
V_59 |= V_63 | V_80 ;
}
} else {
F_19 ( & V_2 -> V_26 , V_25 ) ;
F_2 ( & V_2 -> V_6 -> V_7 ,
L_23 ) ;
V_59 = 0 ;
}
V_54:
return V_59 ;
}
static T_1 * F_41 ( struct V_1 * V_2 )
{
return V_2 -> V_5 + V_81 ;
}
static unsigned long F_42 ( struct V_1 * V_2 )
{
struct V_82 time ;
T_1 * V_83 ;
F_43 ( & time ) ;
V_83 = F_41 ( V_2 ) ;
V_83 [ 0 ] = V_84 ;
V_83 [ 1 ] = time . V_85 ;
F_2 ( & V_2 -> V_6 -> V_7 , L_24 , time . V_85 ) ;
F_2 ( & V_2 -> V_6 -> V_7 , L_25 , V_83 ) ;
F_2 ( & V_2 -> V_6 -> V_7 , L_26 , V_2 -> V_5 ) ;
return time . V_85 ;
}
static int F_44 ( struct V_1 * V_2 , unsigned long V_86 )
{
void T_4 * V_87 ;
int error = 0 ;
int V_88 ;
struct V_89 V_90 ;
for ( V_88 = 0 ; V_88 < V_91 ; V_88 ++ ) {
if ( V_2 -> V_92 [ V_88 ] . V_24 == 0 )
break;
}
if ( V_88 == V_91 ) {
F_2 ( & V_2 -> V_6 -> V_7 , L_27 ) ;
F_2 ( & V_2 -> V_6 -> V_7 , L_28 ,
V_91 ) ;
error = - V_93 ;
goto V_54;
}
if ( F_45 ( & V_90 , ( void T_4 * ) V_86 ,
sizeof( V_90 ) ) ) {
error = - V_94 ;
goto V_54;
}
V_87 = ( void T_4 * ) ( unsigned long ) V_90 . V_95 ;
if ( ! V_90 . V_24 || ! V_90 . V_96 ) {
error = - V_53 ;
goto V_54;
}
F_2 ( & V_2 -> V_6 -> V_7 , L_29 , V_90 . V_24 ) ;
F_2 ( & V_2 -> V_6 -> V_7 , L_30 ,
V_90 . V_96 ) ;
if ( V_90 . V_96 >
V_97 ) {
error = - V_98 ;
goto V_54;
}
V_2 -> V_92 [ V_88 ] . V_24 = V_90 . V_24 ;
if ( F_45 ( V_2 -> V_92 [ V_88 ] . V_99 ,
V_87 , V_90 . V_96 ) )
error = - V_94 ;
V_54:
return error ;
}
static int F_46 ( struct V_1 * V_2 )
{
int V_88 ;
T_1 * V_100 ;
memset ( V_2 -> V_5 + V_101 ,
0 , V_97 ) ;
for ( V_88 = 0 ; V_88 < V_91 ; V_88 ++ ) {
if ( V_2 -> V_92 [ V_88 ] . V_24 == V_23 -> V_24 ) {
F_2 ( & V_2 -> V_6 -> V_7 , L_31 ) ;
memcpy ( V_2 -> V_5 + V_101 ,
( void * ) ( V_2 -> V_92 [ V_88 ] . V_99 ) ,
V_97 ) ;
break;
}
}
V_100 = ( T_1 * ) V_2 -> V_5 +
V_101 ;
for ( V_88 = 0 ; V_88 < V_102 ; V_88 ++ )
V_100 [ V_88 ] = F_47 ( V_100 [ V_88 ] ) ;
return 0 ;
}
static int F_48 ( struct V_1 * V_2 )
{
unsigned long V_25 ;
int error = 0 ;
if ( F_10 ( V_70 , & V_2 -> V_69 ) ) {
error = - V_103 ;
goto V_54;
}
F_42 ( V_2 ) ;
F_46 ( V_2 ) ;
F_1 ( V_2 ) ;
F_17 ( & V_2 -> V_26 , V_25 ) ;
V_2 -> V_27 ++ ;
F_19 ( & V_2 -> V_26 , V_25 ) ;
F_2 ( & V_2 -> V_6 -> V_7 ,
L_32 ,
V_2 -> V_27 , V_2 -> V_28 ) ;
F_18 ( V_2 , V_104 , 0x2 ) ;
V_54:
return error ;
}
static int F_49 ( struct V_1 * V_2 ,
unsigned long V_86 )
{
int error = 0 ;
struct V_105 V_90 ;
T_1 * V_106 ;
if ( F_45 ( & V_90 , ( void T_4 * ) V_86 ,
sizeof( struct V_105 ) ) ) {
error = - V_94 ;
goto V_54;
}
if ( ( V_2 -> V_75 + V_90 . V_107 ) >
V_108 ) {
error = - V_11 ;
goto V_54;
}
F_2 ( & V_2 -> V_6 -> V_7 ,
L_33 , ( int ) V_2 -> V_75 ) ;
F_2 ( & V_2 -> V_6 -> V_7 ,
L_34 , V_109 ) ;
V_90 . V_110 = V_109 +
V_2 -> V_75 ;
V_106 = ( T_1 * ) ( V_2 -> V_5 +
V_111 +
( V_2 -> V_76 ) * 2 * sizeof( T_1 ) ) ;
V_106 [ 0 ] = V_112 ;
V_106 [ 1 ] = ( T_1 ) V_2 -> V_9 +
V_109 +
V_2 -> V_75 ;
error = F_50 ( ( void * ) V_86 , ( void * ) & V_90 ,
sizeof( struct V_105 ) ) ;
if ( error ) {
error = - V_94 ;
goto V_54;
}
V_2 -> V_75 += V_90 . V_107 ;
V_2 -> V_76 += 1 ;
V_54:
return error ;
}
static int F_51 ( struct V_1 * V_2 ,
unsigned long V_113 ,
T_1 V_114 ,
struct V_115 * * V_116 ,
int V_117 )
{
int error = 0 ;
struct V_115 * V_118 ;
struct V_119 * V_120 ;
F_2 ( & V_2 -> V_6 -> V_7 , L_35 ,
( unsigned long ) V_113 ) ;
F_2 ( & V_2 -> V_6 -> V_7 , L_36 , V_114 ) ;
V_118 = F_52 ( sizeof( struct V_115 ) , V_121 ) ;
if ( ! V_118 ) {
error = - V_11 ;
goto V_54;
}
V_120 = F_52 ( sizeof( struct V_119 ) , V_121 ) ;
if ( ! V_120 ) {
error = - V_11 ;
goto V_74;
}
V_120 [ 0 ] . V_37 =
F_53 ( & V_2 -> V_6 -> V_7 , ( void * ) V_113 ,
V_114 , V_122 ) ;
V_120 [ 0 ] . V_38 = V_114 ;
V_118 [ 0 ] . V_12 = ( T_1 ) V_120 [ 0 ] . V_37 ;
V_118 [ 0 ] . V_123 = V_120 [ 0 ] . V_38 ;
F_2 ( & V_2 -> V_6 -> V_7 ,
L_37 ,
( unsigned long ) V_118 [ 0 ] . V_12 ,
V_118 [ 0 ] . V_123 ) ;
if ( V_117 == V_124 ) {
* V_116 = V_118 ;
V_2 -> V_34 [ V_2 -> V_33 ] . V_36 = 1 ;
V_2 -> V_34 [ V_2 -> V_33 ] . V_43 = NULL ;
V_2 -> V_34 [ V_2 -> V_33 ] . V_35 = V_120 ;
V_2 -> V_34 [ V_2 -> V_33 ] . V_45 = 1 ;
} else {
* V_116 = V_118 ;
V_2 -> V_34 [ V_2 -> V_33 ] . V_41 = 1 ;
V_2 -> V_34 [ V_2 -> V_33 ] . V_44 = NULL ;
V_2 -> V_34 [ V_2 -> V_33 ] . V_40 = V_120 ;
V_2 -> V_34 [ V_2 -> V_33 ] . V_46 = 1 ;
}
goto V_54;
V_74:
F_22 ( V_118 ) ;
V_54:
return error ;
}
static int F_54 ( struct V_1 * V_2 ,
T_1 V_125 ,
T_1 V_114 ,
struct V_115 * * V_116 ,
int V_117 )
{
int error = 0 ;
T_1 V_3 ;
int V_126 ;
T_1 V_127 ;
T_1 V_128 ;
T_1 V_129 ;
struct V_130 * * V_131 ;
struct V_115 * V_118 ;
struct V_119 * V_120 ;
enum V_132 V_133 ;
V_127 = ( V_125 + V_114 - 1 ) >> V_55 ;
V_128 = V_125 >> V_55 ;
V_129 = V_127 - V_128 + 1 ;
F_2 ( & V_2 -> V_6 -> V_7 , L_38 , V_125 ) ;
F_2 ( & V_2 -> V_6 -> V_7 , L_36 , V_114 ) ;
F_2 ( & V_2 -> V_6 -> V_7 , L_39 , V_128 ) ;
F_2 ( & V_2 -> V_6 -> V_7 , L_40 , V_127 ) ;
F_2 ( & V_2 -> V_6 -> V_7 , L_41 , V_129 ) ;
V_131 = F_52 ( sizeof( struct V_130 * ) * V_129 , V_121 ) ;
if ( ! V_131 ) {
error = - V_11 ;
goto V_54;
}
V_120 = F_52 ( sizeof( struct V_119 ) * V_129 , V_121 ) ;
if ( ! V_120 ) {
F_5 ( & V_2 -> V_6 -> V_7 , L_42 ) ;
error = - V_11 ;
goto V_134;
}
V_118 = F_52 ( sizeof( struct V_115 ) * V_129 ,
V_121 ) ;
if ( ! V_118 ) {
F_5 ( & V_2 -> V_6 -> V_7 , L_43 ) ;
error = - V_11 ;
goto V_135;
}
F_55 ( & V_23 -> V_136 -> V_137 ) ;
V_126 = F_56 ( V_23 , V_23 -> V_136 , V_125 ,
V_129 ,
( ( V_117 == V_124 ) ? 0 : 1 ) ,
0 , V_131 , NULL ) ;
F_57 ( & V_23 -> V_136 -> V_137 ) ;
if ( V_126 != V_129 ) {
F_5 ( & V_2 -> V_6 -> V_7 ,
L_44 ) ;
error = - V_11 ;
goto V_138;
}
F_2 ( & V_2 -> V_6 -> V_7 , L_45 ) ;
if ( V_117 == V_124 )
V_133 = V_39 ;
else
V_133 = V_42 ;
for ( V_3 = 0 ; V_3 < V_129 ; V_3 ++ ) {
V_120 [ V_3 ] . V_37 =
F_58 ( & V_2 -> V_6 -> V_7 , V_131 [ V_3 ] ,
0 , V_139 , V_122 ) ;
V_120 [ V_3 ] . V_38 = V_139 ;
V_118 [ V_3 ] . V_12 = ( T_1 ) V_120 [ V_3 ] . V_37 ;
V_118 [ V_3 ] . V_123 = V_139 ;
F_5 ( & V_2 -> V_6 -> V_7 , L_46 ,
V_3 , ( unsigned long ) V_118 [ V_3 ] . V_12 ,
V_3 , V_118 [ V_3 ] . V_123 ) ;
}
V_118 [ 0 ] . V_12 =
V_118 [ 0 ] . V_12 + ( V_125 & ( ~ V_140 ) ) ;
if ( ( V_139 - ( V_125 & ( ~ V_140 ) ) ) >= V_114 )
V_118 [ 0 ] . V_123 = V_114 ;
else
V_118 [ 0 ] . V_123 =
V_139 - ( V_125 & ( ~ V_140 ) ) ;
F_2 ( & V_2 -> V_6 -> V_7 ,
L_37 ,
( unsigned long ) V_118 [ V_3 ] . V_12 ,
V_118 [ V_3 ] . V_123 ) ;
if ( V_129 > 1 ) {
V_118 [ V_129 - 1 ] . V_123 =
( V_125 + V_114 ) & ( ~ V_140 ) ;
if ( V_118 [ V_129 - 1 ] . V_123 == 0 )
V_118 [ V_129 - 1 ] . V_123 = V_139 ;
F_5 ( & V_2 -> V_6 -> V_7 ,
L_47
L_48 ,
V_129 - 1 ,
( unsigned long ) V_118 [ V_129 - 1 ] . V_12 ,
V_129 - 1 ,
V_118 [ V_129 - 1 ] . V_123 ) ;
}
if ( V_117 == V_124 ) {
* V_116 = V_118 ;
V_2 -> V_34 [ V_2 -> V_33 ] . V_36 = V_129 ;
V_2 -> V_34 [ V_2 -> V_33 ] . V_43 = V_131 ;
V_2 -> V_34 [ V_2 -> V_33 ] . V_35 = V_120 ;
V_2 -> V_34 [ V_2 -> V_33 ] . V_45 =
V_129 ;
} else {
* V_116 = V_118 ;
V_2 -> V_34 [ V_2 -> V_33 ] . V_41 = V_129 ;
V_2 -> V_34 [ V_2 -> V_33 ] . V_44 =
V_131 ;
V_2 -> V_34 [ V_2 -> V_33 ] . V_40 = V_120 ;
V_2 -> V_34 [ V_2 -> V_33 ] . V_46 =
V_129 ;
}
goto V_54;
V_138:
F_22 ( V_118 ) ;
V_135:
F_22 ( V_120 ) ;
V_134:
F_22 ( V_131 ) ;
V_54:
return error ;
}
static T_1 F_59 ( struct V_1 * V_2 ,
struct V_115 * V_141 ,
T_1 V_142 ,
T_1 * V_143 )
{
T_1 V_144 ;
T_1 V_145 = 0 ;
T_1 V_146 ;
* V_143 = 0 ;
for ( V_144 = 0 ;
( V_144 < ( V_147 - 1 ) ) &&
( V_144 < V_142 ) ; V_144 ++ )
V_145 += V_141 [ V_144 ] . V_123 ;
if ( V_144 == V_142 ) {
* V_143 = 1 ;
goto V_54;
}
V_146 = 0 ;
for (; V_144 < V_142 ; V_144 ++ ) {
V_146 += V_141 [ V_144 ] . V_123 ;
if ( V_146 >= V_148 )
break;
}
if ( V_146 &&
V_146 < V_148 )
V_145 -= ( V_148 -
V_146 ) ;
V_54:
return V_145 ;
}
static void F_60 ( struct V_1 * V_2 ,
struct V_115 * V_116 ,
struct V_115 * V_149 ,
T_1 * V_150 ,
T_1 * V_151 ,
T_1 V_145 )
{
T_1 V_152 ;
T_1 V_153 ;
V_152 = 0 ;
V_153 = 0 ;
* V_151 = 1 ;
F_2 ( & V_2 -> V_6 -> V_7 , L_49 , V_145 ) ;
while ( V_152 < V_145 ) {
( * V_151 ) ++ ;
V_149 -> V_12 =
F_47 ( V_116 [ V_153 ] . V_12 ) ;
V_149 -> V_123 =
F_47 ( V_116 [ V_153 ] . V_123 ) ;
V_152 += V_116 [ V_153 ] . V_123 ;
F_2 ( & V_2 -> V_6 -> V_7 , L_50 ,
V_149 ) ;
F_2 ( & V_2 -> V_6 -> V_7 , L_51 ,
( unsigned long ) V_149 -> V_12 ) ;
F_2 ( & V_2 -> V_6 -> V_7 , L_52 ,
V_149 -> V_123 ) ;
if ( V_152 > V_145 ) {
F_2 ( & V_2 -> V_6 -> V_7 ,
L_53 ) ;
V_149 -> V_123 -=
F_47 ( ( V_152 - V_145 ) ) ;
V_116 [ V_153 ] . V_12 +=
F_47 ( V_149 -> V_123 ) ;
V_116 [ V_153 ] . V_123 =
( V_152 - V_145 ) ;
} else
V_153 ++ ;
F_2 ( & V_2 -> V_6 -> V_7 ,
L_51 ,
( unsigned long ) V_149 -> V_12 ) ;
F_2 ( & V_2 -> V_6 -> V_7 ,
L_52 ,
V_149 -> V_123 ) ;
V_149 ++ ;
}
V_149 -> V_12 = 0xffffffff ;
V_149 -> V_123 = 0 ;
* V_150 += V_153 ;
}
static T_2 F_61 ( struct V_1 * V_2 ,
void * V_154 )
{
F_2 ( & V_2 -> V_6 -> V_7 , L_54 , V_154 ) ;
F_2 ( & V_2 -> V_6 -> V_7 , L_55 ,
( unsigned long )
V_2 -> V_9 + ( V_154 - V_2 -> V_5 ) ) ;
return V_2 -> V_9 + ( V_155 ) ( V_154 - V_2 -> V_5 ) ;
}
static void * F_62 ( struct V_1 * V_2 ,
T_2 V_12 )
{
F_2 ( & V_2 -> V_6 -> V_7 , L_56 ,
( unsigned long ) V_12 , ( unsigned long ) ( V_2 -> V_5 +
( V_155 ) ( V_12 - V_2 -> V_9 ) ) ) ;
return V_2 -> V_5 + ( V_155 ) ( V_12 - V_2 -> V_9 ) ;
}
static void F_63 ( struct V_1 * V_2 ,
struct V_115 * V_149 ,
unsigned long V_156 ,
unsigned long V_145 )
{
unsigned long V_157 = 1 ;
unsigned long V_158 = 0 ;
F_2 ( & V_2 -> V_6 -> V_7 , L_57 ) ;
while ( ( unsigned long ) V_149 -> V_12 != 0xffffffff ) {
F_2 ( & V_2 -> V_6 -> V_7 ,
L_58 ,
V_157 , V_145 ) ;
F_2 ( & V_2 -> V_6 -> V_7 , L_59 ,
V_156 ) ;
for ( V_158 = 0 ; V_158 < V_156 ;
V_158 ++ , V_149 ++ ) {
F_2 ( & V_2 -> V_6 -> V_7 ,
L_60 ,
( unsigned long ) V_149 ) ;
F_2 ( & V_2 -> V_6 -> V_7 ,
L_61 ,
( unsigned long ) V_149 -> V_12 ,
V_149 -> V_123 ) ;
}
V_149 -- ;
F_2 ( & V_2 -> V_6 -> V_7 ,
L_62 ,
V_149 -> V_123 ) ;
F_2 ( & V_2 -> V_6 -> V_7 ,
L_63 ,
( unsigned long ) V_149 -> V_12 ) ;
V_145 = V_149 -> V_123 & 0xffffff ;
V_156 = ( V_149 -> V_123 >> 24 ) & 0xff ;
F_2 ( & V_2 -> V_6 -> V_7 ,
L_64
L_65 , V_145 ,
V_156 , ( unsigned long ) V_149 -> V_12 ) ;
if ( ( unsigned long ) V_149 -> V_12 != 0xffffffff )
V_149 = (struct V_115 * )
F_8 ( V_2 ,
( unsigned long ) V_149 -> V_12 ) ;
V_157 ++ ;
}
F_2 ( & V_2 -> V_6 -> V_7 , L_66 ) ;
}
static void F_64 ( struct V_1 * V_2 ,
T_2 * V_159 ,
T_1 * V_160 ,
T_1 * V_161 )
{
struct V_115 * V_149 ;
V_149 =
(struct V_115 * ) ( V_2 -> V_5 +
V_162 +
V_2 -> V_47 * sizeof( struct V_115 ) *
V_147 ) ;
V_149 -> V_12 = 0 ;
V_149 -> V_123 = 0 ;
V_149 ++ ;
V_149 -> V_12 = 0xFFFFFFFF ;
V_149 -> V_123 = 0 ;
* V_159 = V_2 -> V_9 +
V_162 +
V_2 -> V_47 *
sizeof( struct V_115 ) *
V_147 ;
* V_160 = 2 ;
* V_161 = 0 ;
V_2 -> V_47 ++ ;
}
static int F_65 ( struct V_1 * V_2 ,
unsigned long V_125 ,
T_1 V_114 ,
T_1 V_123 ,
T_2 * V_149 ,
T_1 * V_160 ,
T_1 * V_161 ,
bool V_163 )
{
int error = 0 ;
struct V_115 * V_164 ;
struct V_115 * V_116 ;
T_1 V_165 = 0 ;
T_1 V_166 = 0 ;
struct V_115 * V_167 ;
T_1 V_145 = 0 ;
T_1 V_143 = 0 ;
T_1 V_168 = 0 ;
void * V_169 = 0 ;
F_2 ( & V_2 -> V_6 -> V_7 , L_67 , V_114 ) ;
F_2 ( & V_2 -> V_6 -> V_7 , L_68 , V_123 ) ;
V_2 -> V_34 [ V_2 -> V_33 ] . V_43 = NULL ;
V_2 -> V_34 [ V_2 -> V_33 ] . V_36 = 0 ;
V_169 = ( void * ) ( V_2 -> V_5 +
V_162 +
V_2 -> V_47 * sizeof( struct V_115 ) *
V_147 ) ;
if ( V_114 == 0 ) {
F_64 ( V_2 , V_149 ,
V_160 , V_161 ) ;
goto V_170;
}
if ( V_163 == true )
error = F_51 ( V_2 , V_125 ,
V_114 , & V_116 , V_124 ) ;
else
error = F_54 ( V_2 , V_125 ,
V_114 , & V_116 , V_124 ) ;
if ( error )
goto V_54;
F_2 ( & V_2 -> V_6 -> V_7 , L_69 ,
V_2 -> V_34 [ V_2 -> V_33 ] . V_36 ) ;
V_165 = 0 ;
V_164 = NULL ;
V_166 = V_2 -> V_34 [ V_2 -> V_33 ] . V_36 ;
while ( V_165 < V_166 ) {
V_167 =
(struct V_115 * ) V_169 ;
V_169 += sizeof( struct V_115 ) *
V_147 ;
if ( V_169 >
( ( void * ) V_2 -> V_5 +
V_162 +
V_171 ) ) {
error = - V_11 ;
goto V_172;
}
V_2 -> V_47 ++ ;
V_145 = F_59 ( V_2 ,
& V_116 [ V_165 ] ,
( V_166 - V_165 ) ,
& V_143 ) ;
if ( ! V_143 )
V_145 =
( V_145 / V_123 ) * V_123 ;
F_2 ( & V_2 -> V_6 -> V_7 , L_70 ,
V_145 ) ;
F_60 ( V_2 , & V_116 [ V_165 ] ,
V_167 ,
& V_165 , & V_168 , V_145 ) ;
if ( V_164 == NULL ) {
* V_149 = F_61 ( V_2 ,
V_167 ) ;
* V_160 = V_168 ;
* V_161 = V_145 ;
F_2 ( & V_2 -> V_6 -> V_7 ,
L_71 ,
( unsigned long ) * V_149 ) ;
} else {
V_164 -> V_12 =
F_61 ( V_2 ,
V_167 ) ;
V_164 -> V_123 =
( ( V_168 ) << 24 ) |
( V_145 ) ;
}
V_164 = V_167 + V_168 - 1 ;
}
F_63 ( V_2 , (struct V_115 * )
F_62 ( V_2 , * V_149 ) ,
* V_160 , * V_161 ) ;
F_22 ( V_116 ) ;
V_170:
V_2 -> V_33 ++ ;
goto V_54;
V_172:
F_22 ( V_2 -> V_34 [ V_2 -> V_33 ] . V_35 ) ;
F_22 ( V_116 ) ;
F_22 ( V_2 -> V_34 [ V_2 -> V_33 ] . V_43 ) ;
V_54:
return error ;
}
static int F_66 (
struct V_1 * V_2 ,
struct V_115 * V_173 ,
T_1 V_174 ,
struct V_115 * V_175 ,
T_1 V_176 ,
T_1 V_123 ,
T_2 * V_177 ,
T_2 * V_178 ,
T_1 * V_179 ,
T_1 * V_180 ,
T_1 * V_161 )
{
void * V_169 = 0 ;
struct V_115 * V_167 = NULL ;
struct V_115 * V_181 = NULL ;
struct V_115 * V_182 = NULL ;
struct V_115 * V_183 = NULL ;
T_1 V_184 = 0 ;
T_1 V_185 = 0 ;
T_1 V_186 = 0 ;
T_1 V_187 = 0 ;
T_1 V_143 = 0 ;
T_1 V_145 = 0 ;
T_1 V_168 = 0 ;
T_1 V_188 = 0 ;
V_169 = ( void * ) ( V_2 -> V_5 +
V_162 +
( V_2 -> V_47 *
( sizeof( struct V_115 ) *
V_147 ) ) ) ;
while ( V_184 < V_174 ) {
V_167 =
(struct V_115 * ) V_169 ;
V_169 += sizeof( struct V_115 ) *
V_147 ;
V_181 =
(struct V_115 * ) V_169 ;
if ( ( V_169 + sizeof( struct V_115 ) *
V_147 ) >
( ( void * ) V_2 -> V_5 +
V_162 +
V_171 ) ) {
F_5 ( & V_2 -> V_6 -> V_7 , L_72 ) ;
return - V_11 ;
}
V_2 -> V_47 += 2 ;
V_169 += sizeof( struct V_115 ) *
V_147 ;
V_186 =
F_59 ( V_2 ,
& V_173 [ V_184 ] ,
( V_174 - V_184 ) ,
& V_143 ) ;
V_187 =
F_59 ( V_2 ,
& V_175 [ V_185 ] ,
( V_176 - V_185 ) ,
& V_143 ) ;
F_2 ( & V_2 -> V_6 -> V_7 ,
L_73 ,
V_186 ) ;
F_2 ( & V_2 -> V_6 -> V_7 ,
L_74 ,
V_187 ) ;
V_145 = V_186 ;
if ( ! V_143 ) {
if ( V_145 > V_187 )
V_145 = V_187 ;
V_145 = ( V_145 / V_123 ) *
V_123 ;
}
F_60 ( V_2 , & V_173 [ V_184 ] ,
V_167 ,
& V_184 ,
& V_168 ,
V_145 ) ;
F_60 ( V_2 , & V_175 [ V_185 ] ,
V_181 ,
& V_185 ,
& V_188 ,
V_145 ) ;
if ( V_182 == NULL ) {
* V_177 =
F_61 ( V_2 , V_167 ) ;
* V_179 = V_168 ;
* V_178 =
F_61 ( V_2 ,
V_181 ) ;
* V_180 = V_188 ;
* V_161 = V_145 ;
F_2 ( & V_2 -> V_6 -> V_7 ,
L_71 ,
( unsigned long ) * V_177 ) ;
F_2 ( & V_2 -> V_6 -> V_7 ,
L_75 ,
( unsigned long ) * V_178 ) ;
} else {
V_182 -> V_12 =
F_61 ( V_2 ,
V_167 ) ;
V_182 -> V_123 =
( ( V_168 ) << 24 ) |
( V_145 ) ;
V_183 -> V_12 =
F_61 ( V_2 ,
V_181 ) ;
V_183 -> V_123 =
( ( V_188 ) << 24 ) |
( V_145 ) ;
F_2 ( & V_2 -> V_6 -> V_7 ,
L_76 ,
( unsigned long ) V_182 -> V_12 ,
V_182 -> V_123 ) ;
F_2 ( & V_2 -> V_6 -> V_7 ,
L_77 ,
( unsigned long ) V_183 -> V_12 ,
V_183 -> V_123 ) ;
}
V_182 = V_167 +
V_168 - 1 ;
V_183 = V_181 +
V_188 - 1 ;
F_2 ( & V_2 -> V_6 -> V_7 ,
L_78 ,
( T_1 ) V_188 ) ;
F_2 ( & V_2 -> V_6 -> V_7 ,
L_79 ,
( unsigned long ) V_182 ) ;
F_2 ( & V_2 -> V_6 -> V_7 ,
L_80 ,
( unsigned long ) V_183 ) ;
}
F_63 ( V_2 ,
(struct V_115 * )
F_62 ( V_2 , * V_177 ) ,
* V_179 ,
* V_161 ) ;
F_63 ( V_2 ,
(struct V_115 * )
F_62 ( V_2 , * V_178 ) ,
* V_180 ,
* V_161 ) ;
return 0 ;
}
static int F_67 ( struct V_1 * V_2 ,
unsigned long V_189 ,
unsigned long V_190 ,
T_1 V_114 ,
T_1 V_123 ,
T_2 * V_177 ,
T_2 * V_178 ,
T_1 * V_179 ,
T_1 * V_180 ,
T_1 * V_161 ,
bool V_163 )
{
int error = 0 ;
struct V_115 * V_173 ;
struct V_115 * V_175 ;
if ( V_114 == 0 ) {
F_64 ( V_2 , V_177 ,
V_179 , V_161 ) ;
F_64 ( V_2 , V_178 ,
V_180 , V_161 ) ;
goto V_170;
}
V_2 -> V_34 [ V_2 -> V_33 ] . V_43 = NULL ;
V_2 -> V_34 [ V_2 -> V_33 ] . V_44 = NULL ;
if ( V_163 == true ) {
error = F_51 ( V_2 , V_189 ,
V_114 , & V_173 , V_124 ) ;
if ( error ) {
F_5 ( & V_2 -> V_6 -> V_7 ,
L_81 ) ;
goto V_54;
}
error = F_51 ( V_2 , V_190 ,
V_114 , & V_175 , V_191 ) ;
if ( error ) {
F_5 ( & V_2 -> V_6 -> V_7 ,
L_82 ) ;
goto V_54;
}
}
else {
error = F_54 ( V_2 , V_189 ,
V_114 , & V_173 , V_124 ) ;
if ( error ) {
F_5 ( & V_2 -> V_6 -> V_7 ,
L_83 ) ;
goto V_54;
}
error = F_54 ( V_2 , V_190 ,
V_114 , & V_175 , V_191 ) ;
if ( error ) {
F_5 ( & V_2 -> V_6 -> V_7 ,
L_84 ) ;
goto V_192;
}
}
F_2 ( & V_2 -> V_6 -> V_7 , L_85 ,
V_2 -> V_34 [ V_2 -> V_33 ] . V_36 ) ;
F_2 ( & V_2 -> V_6 -> V_7 , L_86 ,
V_2 -> V_34 [ V_2 -> V_33 ] . V_41 ) ;
F_2 ( & V_2 -> V_6 -> V_7 , L_87 ,
V_147 ) ;
error = F_66 ( V_2 , V_173 ,
V_2 -> V_34 [ V_2 -> V_33 ] . V_36 ,
V_175 ,
V_2 -> V_34 [ V_2 -> V_33 ] . V_41 ,
V_123 , V_177 , V_178 ,
V_179 , V_180 , V_161 ) ;
if ( error ) {
F_5 ( & V_2 -> V_6 -> V_7 ,
L_88 ) ;
goto V_74;
}
F_22 ( V_175 ) ;
F_22 ( V_173 ) ;
V_170:
V_2 -> V_33 ++ ;
goto V_54;
V_74:
F_22 ( V_2 -> V_34 [ V_2 -> V_33 ] . V_40 ) ;
F_22 ( V_2 -> V_34 [ V_2 -> V_33 ] . V_44 ) ;
F_22 ( V_175 ) ;
V_192:
F_22 ( V_2 -> V_34 [ V_2 -> V_33 ] . V_35 ) ;
F_22 ( V_2 -> V_34 [ V_2 -> V_33 ] . V_43 ) ;
F_22 ( V_173 ) ;
V_54:
return error ;
}
static int F_68 ( struct V_1 * V_2 ,
unsigned long V_193 ,
unsigned long V_194 ,
T_1 V_195 ,
T_1 V_123 ,
T_1 V_196 ,
bool V_197 ,
bool V_163 )
{
int error = 0 ;
T_1 V_198 = 0 ;
struct V_199 * V_200 = NULL ;
T_2 V_201 = 0 ;
T_1 V_202 = 0 ;
T_2 V_203 = 0 ;
T_1 V_204 = 0 ;
T_1 V_205 = 0 ;
if ( V_2 -> V_33 == V_206 ) {
F_5 ( & V_2 -> V_6 -> V_7 , L_89 ) ;
error = - V_207 ;
goto V_54;
}
V_200 = (struct V_199 * ) ( V_2 -> V_5 +
V_208 +
( V_2 -> V_33 * sizeof( struct V_199 ) ) ) ;
V_200 -> V_209 = 0 ;
V_200 -> V_210 = 0 ;
V_200 -> V_211 = 0 ;
V_200 -> V_212 = 0 ;
V_200 -> V_213 = 0 ;
V_200 -> V_214 = 0 ;
V_200 -> V_215 = 0 ;
V_200 -> V_216 = 0 ;
if ( V_197 == true ) {
if ( V_195 < V_148 ) {
if ( V_163 == true ) {
memcpy ( V_200 -> V_217 ,
( void * ) V_193 , V_195 ) ;
} else {
if ( F_45 ( V_200 -> V_217 ,
( void T_4 * ) V_193 ,
V_195 ) ) {
error = - V_94 ;
goto V_54;
}
}
V_200 -> V_215 = V_195 ;
if ( V_194 )
V_200 -> V_216 =
( V_218 ) V_194 ;
V_198 = 0x0 ;
V_195 = 0x0 ;
} else {
if ( ! V_194 ) {
V_198 = V_195 % V_123 ;
if ( ! V_198 ) {
if ( V_196 == V_123 )
V_198 = V_123 ;
}
} else {
V_198 = 0 ;
}
}
if ( V_198 ) {
if ( V_198 > sizeof( V_200 -> V_217 ) )
return - V_53 ;
if ( V_163 == true ) {
memcpy ( V_200 -> V_217 ,
( void * ) ( V_193 + V_195 -
V_198 ) , V_198 ) ;
} else {
if ( F_45 ( V_200 -> V_217 ,
( void * ) ( V_193 +
V_195 - V_198 ) , V_198 ) ) {
error = - V_94 ;
goto V_54;
}
}
if ( V_194 )
V_200 -> V_216 =
( V_218 ) V_194 + V_195
- V_198 ;
V_200 -> V_215 = V_198 ;
V_195 = ( V_195 - V_198 ) ;
}
}
if ( V_194 ) {
error = F_67 ( V_2 ,
V_193 ,
V_194 ,
V_195 ,
V_123 ,
& V_201 ,
& V_203 ,
& V_202 ,
& V_204 ,
& V_205 ,
V_163 ) ;
} else {
error = F_65 ( V_2 ,
V_193 ,
V_195 ,
V_123 ,
& V_201 ,
& V_202 ,
& V_205 ,
V_163 ) ;
}
if ( error ) {
F_5 ( & V_2 -> V_6 -> V_7 , L_90 ) ;
goto V_54;
}
V_200 -> V_209 = V_201 ;
V_200 -> V_210 = V_202 ;
V_200 -> V_211 = V_205 ;
V_200 -> V_212 = V_203 ;
V_200 -> V_213 = V_204 ;
V_200 -> V_214 = V_205 ;
V_54:
return error ;
}
static int F_69 ( struct V_1 * V_2 , bool V_197 ,
bool V_163 )
{
int V_88 = 0 ;
int error = 0 ;
int V_219 = 0 ;
struct V_199 * V_200 ;
unsigned long V_220 ;
void * V_221 ;
if ( V_197 == true ) {
V_200 = (struct V_199 * )
( V_2 -> V_5 +
V_208 ) ;
for ( V_88 = 0 ; V_88 < V_2 -> V_33 ; V_88 ++ , V_200 ++ ) {
if ( V_200 -> V_216 ) {
V_220 = ( unsigned long ) V_200 -> V_216 ;
V_221 = ( void * ) V_220 ;
if ( V_163 == true ) {
memcpy ( V_221 ,
V_200 -> V_217 ,
V_200 -> V_215 ) ;
} else {
V_219 = F_50 (
V_221 ,
V_200 -> V_217 ,
V_200 -> V_215 ) ;
}
if ( V_219 ) {
error = - V_94 ;
break;
}
}
}
}
F_20 ( V_2 ) ;
return error ;
}
static int F_70 ( struct V_1 * V_2 )
{
T_1 * V_222 = NULL ;
V_222 = ( T_1 * ) ( V_2 -> V_5 +
V_223 ) ;
V_222 [ 0 ] = V_224 ;
V_222 [ 1 ] = ( T_1 ) V_2 -> V_9 +
V_225 ;
F_2 ( & V_2 -> V_6 -> V_7 , L_91 ,
( T_1 ) V_222 [ 1 ] ) ;
return 0 ;
}
static int F_71 ( struct V_1 * V_2 )
{
memset ( ( void * ) ( V_2 -> V_5 +
V_111 ) ,
0 , V_2 -> V_76 * 2 * sizeof( T_1 ) ) ;
F_20 ( V_2 ) ;
F_13 ( V_68 , & V_2 -> V_69 ) ;
F_33 ( & V_2 -> V_66 ) ;
V_2 -> V_67 = 0 ;
F_35 ( & V_2 -> V_66 ) ;
F_34 ( & V_2 -> V_71 ) ;
return 0 ;
}
static int F_72 ( struct V_1 * V_2 , unsigned long V_86 )
{
int error ;
struct V_226 V_90 ;
if ( F_45 ( & V_90 , ( void T_4 * ) V_86 ,
sizeof( struct V_226 ) ) ) {
error = - V_94 ;
goto V_54;
}
F_2 ( & V_2 -> V_6 -> V_7 , L_92 ,
V_90 . V_193 ) ;
F_2 ( & V_2 -> V_6 -> V_7 , L_93 ,
V_90 . V_194 ) ;
F_2 ( & V_2 -> V_6 -> V_7 , L_36 ,
V_90 . V_195 ) ;
F_2 ( & V_2 -> V_6 -> V_7 , L_68 ,
V_90 . V_123 ) ;
F_2 ( & V_2 -> V_6 -> V_7 , L_94 ,
V_90 . V_196 ) ;
error = F_68 ( V_2 ,
( unsigned long ) V_90 . V_193 ,
( unsigned long ) V_90 . V_194 ,
V_90 . V_195 , V_90 . V_123 ,
V_90 . V_196 , true , false ) ;
V_54:
return error ;
}
static int F_73 ( struct V_1 * V_2 )
{
return F_69 ( V_2 , false , false ) ;
}
static int F_74 ( struct V_1 * V_2 ,
unsigned long V_86 )
{
int error = 0 ;
struct V_227 V_90 ;
T_2 V_228 = 0 ;
T_1 * V_229 ;
if ( F_45 ( & V_90 , ( void T_4 * ) V_86 ,
sizeof( V_90 ) ) ) {
error = - V_94 ;
goto V_54;
}
if ( V_90 . V_230 )
return - V_231 ;
F_2 ( & V_2 -> V_6 -> V_7 , L_95 , ( T_1 ) V_228 ) ;
V_229 = ( T_1 * ) ( V_2 -> V_5 +
V_223 ) ;
V_229 [ 0 ] = V_232 ;
V_229 [ 1 ] = V_228 ;
V_54:
return error ;
}
static long F_75 ( struct V_15 * V_21 , unsigned int V_233 , unsigned long V_86 )
{
int error = 0 ;
struct V_1 * V_2 = V_21 -> V_18 ;
F_33 ( & V_2 -> V_66 ) ;
if ( ( V_23 -> V_24 != V_2 -> V_67 ) &&
( V_2 -> V_67 != 0 ) ) {
F_2 ( & V_2 -> V_6 -> V_7 , L_96 ) ;
error = - V_234 ;
}
F_35 ( & V_2 -> V_66 ) ;
if ( error )
return error ;
if ( F_76 ( V_233 ) != V_235 )
return - V_236 ;
F_33 ( & V_2 -> V_237 ) ;
switch ( V_233 ) {
case V_238 :
error = F_48 ( V_2 ) ;
break;
case V_239 :
error = F_49 ( V_2 , V_86 ) ;
break;
case V_240 :
error = F_70 ( V_2 ) ;
break;
case V_241 :
error = F_71 ( V_2 ) ;
break;
case V_242 :
error = F_74 ( V_2 , V_86 ) ;
break;
case V_243 :
error = F_72 ( V_2 , V_86 ) ;
break;
case V_244 :
error = F_73 ( V_2 ) ;
break;
default:
error = - V_236 ;
break;
}
F_35 ( & V_2 -> V_237 ) ;
return error ;
}
static long F_77 ( struct V_15 * V_21 , T_1 V_233 , unsigned long V_86 )
{
long error = 0 ;
struct V_1 * V_2 = V_21 -> V_18 ;
if ( F_76 ( V_233 ) != V_235 )
return - V_236 ;
F_33 ( & V_2 -> V_66 ) ;
if ( ( V_23 -> V_24 != V_2 -> V_67 ) &&
( V_2 -> V_67 != 0 ) ) {
F_2 ( & V_2 -> V_6 -> V_7 , L_97 ) ;
F_35 ( & V_2 -> V_66 ) ;
return - V_234 ;
}
F_35 ( & V_2 -> V_66 ) ;
switch ( V_233 ) {
case V_245 :
F_33 ( & V_2 -> V_237 ) ;
error = F_44 ( V_2 , V_86 ) ;
F_35 ( & V_2 -> V_237 ) ;
break;
default:
error = F_75 ( V_21 , V_233 , V_86 ) ;
break;
}
return error ;
}
static long F_78 ( struct V_15 * V_21 , T_1 V_233 ,
unsigned long V_86 )
{
long error ;
struct V_1 * V_2 = V_21 -> V_18 ;
if ( F_76 ( V_233 ) != V_235 )
return - V_236 ;
F_33 ( & V_2 -> V_237 ) ;
switch ( V_233 ) {
case V_246 :
error = F_16 ( V_2 ) ;
break;
case V_241 :
error = 0 ;
break;
default:
error = - V_236 ;
}
F_35 ( & V_2 -> V_237 ) ;
return error ;
}
static T_5 F_79 ( int V_247 , void * V_248 )
{
T_5 V_249 = V_250 ;
unsigned long V_25 ;
T_1 V_251 , V_252 = 0 ;
struct V_1 * V_2 = V_248 ;
V_251 = F_31 ( V_2 , V_253 ) ;
if ( V_251 & ( 0x1 << 13 ) ) {
F_17 ( & V_2 -> V_26 , V_25 ) ;
V_2 -> V_28 ++ ;
F_19 ( & V_2 -> V_26 , V_25 ) ;
F_2 ( & V_2 -> V_6 -> V_7 , L_98 ,
V_2 -> V_27 , V_2 -> V_28 ) ;
V_252 = F_31 ( V_2 , V_62 ) ;
F_2 ( & V_2 -> V_6 -> V_7 ,
L_99 , V_252 ) ;
if ( ( V_252 >> 30 ) & 0x1 ) {
F_2 ( & V_2 -> V_6 -> V_7 , L_100 ) ;
F_34 ( & V_2 -> V_61 ) ;
} else if ( V_252 >> 31 ) {
F_2 ( & V_2 -> V_6 -> V_7 , L_101 ) ;
F_34 ( & V_2 -> V_61 ) ;
} else {
F_2 ( & V_2 -> V_6 -> V_7 , L_102 ) ;
F_34 ( & V_2 -> V_71 ) ;
}
} else {
F_2 ( & V_2 -> V_6 -> V_7 , L_103 ) ;
V_249 = V_254 ;
}
if ( V_249 == V_250 )
F_18 ( V_2 , V_255 , V_251 ) ;
return V_249 ;
}
static int F_80 ( struct V_1 * V_2 )
{
int V_256 ;
unsigned long V_257 ;
F_2 ( & V_2 -> V_6 -> V_7 , L_104 ,
( unsigned long long ) V_2 -> V_9 ) ;
F_18 ( V_2 , V_258 , V_2 -> V_9 ) ;
V_256 = F_31 ( V_2 , V_259 ) ;
V_257 = V_260 + ( V_261 * V_262 ) ;
while ( ( F_81 ( V_260 , V_257 ) ) && ( V_256 != 0xffffffff ) &&
( V_256 != V_2 -> V_9 ) )
V_256 = F_31 ( V_2 , V_259 ) ;
if ( V_256 != V_2 -> V_9 ) {
F_5 ( & V_2 -> V_6 -> V_7 , L_105 ) ;
F_5 ( & V_2 -> V_6 -> V_7 , L_106 , V_256 ) ;
V_256 = - V_11 ;
} else
V_256 = 0 ;
F_2 ( & V_2 -> V_6 -> V_7 , L_107 ) ;
return V_256 ;
}
static int F_82 ( struct V_1 * V_2 )
{
int V_256 ;
V_2 -> V_263 . V_264 = V_265 ;
V_2 -> V_263 . V_266 = V_267 ;
V_2 -> V_263 . V_268 = & V_269 ;
V_2 -> V_270 . V_264 = V_265 ;
V_2 -> V_270 . V_266 = V_271 ;
V_2 -> V_270 . V_268 = & V_272 ;
V_2 -> V_273 . V_264 = V_265 ;
V_2 -> V_273 . V_266 = V_274 ;
V_2 -> V_273 . V_268 = & V_275 ;
V_256 = F_83 ( & V_2 -> V_263 ) ;
if ( V_256 ) {
F_5 ( & V_2 -> V_6 -> V_7 , L_108 ,
V_256 ) ;
return V_256 ;
}
V_256 = F_83 ( & V_2 -> V_270 ) ;
if ( V_256 ) {
F_5 ( & V_2 -> V_6 -> V_7 , L_109 ,
V_256 ) ;
F_84 ( & V_2 -> V_263 ) ;
return V_256 ;
}
V_256 = F_83 ( & V_2 -> V_273 ) ;
if ( V_256 ) {
F_5 ( & V_2 -> V_6 -> V_7 , L_110 ,
V_256 ) ;
F_84 ( & V_2 -> V_263 ) ;
F_84 ( & V_2 -> V_270 ) ;
return V_256 ;
}
return V_256 ;
}
static int T_6 F_85 ( struct V_276 * V_6 ,
const struct V_277 * V_278 )
{
int error = 0 ;
struct V_1 * V_2 ;
if ( V_17 != NULL ) {
F_5 ( & V_6 -> V_7 , L_111 ) ;
return - V_20 ;
}
error = F_86 ( V_6 ) ;
if ( error ) {
F_5 ( & V_6 -> V_7 , L_112 ) ;
goto V_54;
}
V_17 = F_87 ( sizeof( struct V_1 ) , V_121 ) ;
if ( V_17 == NULL ) {
F_5 ( & V_6 -> V_7 ,
L_113 ) ;
error = - V_11 ;
goto V_279;
}
V_2 = V_17 ;
V_2 -> V_6 = F_88 ( V_6 ) ;
F_89 ( & V_2 -> V_71 ) ;
F_89 ( & V_2 -> V_61 ) ;
F_90 ( & V_2 -> V_26 ) ;
F_91 ( & V_2 -> V_66 ) ;
F_91 ( & V_2 -> V_237 ) ;
F_2 ( & V_2 -> V_6 -> V_7 , L_114 ) ;
F_2 ( & V_2 -> V_6 -> V_7 , L_115 , V_2 -> V_6 -> V_280 ) ;
V_2 -> V_281 = F_92 ( V_2 -> V_6 , 0 ) ;
if ( ! V_2 -> V_281 ) {
F_5 ( & V_2 -> V_6 -> V_7 , L_116 ) ;
error = - V_282 ;
goto V_283;
}
V_2 -> V_284 = F_93 ( V_2 -> V_6 , 0 ) ;
if ( ! V_2 -> V_284 ) {
F_5 ( & V_2 -> V_6 -> V_7 , L_117 ) ;
error = - V_282 ;
goto V_283;
}
V_2 -> V_285 = F_94 ( V_2 -> V_281 ,
( V_155 ) ( V_2 -> V_284 - V_2 -> V_281 + 1 ) ) ;
if ( ! V_2 -> V_285 ) {
F_5 ( & V_2 -> V_6 -> V_7 , L_118 ) ;
error = - V_282 ;
goto V_283;
}
F_2 ( & V_2 -> V_6 -> V_7 ,
L_119 ,
( unsigned long long ) V_2 -> V_281 ,
( unsigned long long ) V_2 -> V_284 ,
V_2 -> V_285 ) ;
V_2 -> V_8 = V_286 +
V_171 +
V_108 +
V_287 +
V_288 ;
if ( F_3 ( V_2 ) ) {
error = - V_11 ;
goto V_172;
}
F_18 ( V_2 , V_255 , 0xFFFFFFFF ) ;
F_18 ( V_2 , V_289 , ( ~ ( 0x1 << 13 ) ) ) ;
V_2 -> V_28 = F_31 ( V_2 , V_62 ) ;
V_2 -> V_28 &= 0x3FFFFFFF ;
V_2 -> V_27 = V_2 -> V_28 ;
error = F_95 ( V_6 -> V_247 , F_79 , V_290 ,
L_120 , V_2 ) ;
if ( error )
goto V_291;
if ( V_2 -> V_6 -> V_280 == 4 ) {
error = F_80 ( V_2 ) ;
if ( error )
goto V_292;
}
error = F_82 ( V_2 ) ;
if ( error == 0 )
return 0 ;
V_292:
F_96 ( V_6 -> V_247 , V_2 ) ;
V_291:
F_6 ( V_2 ) ;
V_172:
F_97 ( V_2 -> V_285 ) ;
V_283:
F_98 ( V_17 -> V_6 ) ;
F_22 ( V_17 ) ;
V_17 = NULL ;
V_279:
F_99 ( V_6 ) ;
V_54:
return error ;
}
static void F_100 ( struct V_276 * V_6 )
{
struct V_1 * V_2 = V_17 ;
F_84 ( & V_2 -> V_263 ) ;
F_84 ( & V_2 -> V_270 ) ;
F_84 ( & V_2 -> V_273 ) ;
F_96 ( V_2 -> V_6 -> V_247 , V_2 ) ;
F_6 ( V_17 ) ;
F_97 ( ( void * ) V_17 -> V_285 ) ;
}
static int T_7 F_101 ( void )
{
return F_102 ( & V_293 ) ;
}
static void T_8 F_103 ( void )
{
F_104 ( & V_293 ) ;
}
