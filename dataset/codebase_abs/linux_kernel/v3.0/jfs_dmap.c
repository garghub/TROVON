int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
struct V_5 * V_6 ;
struct V_7 * V_8 ;
int V_9 ;
V_4 = F_2 ( sizeof( struct V_3 ) , V_10 ) ;
if ( V_4 == NULL )
return - V_11 ;
V_8 = F_3 ( V_2 ,
V_12 << F_4 ( V_2 -> V_13 ) -> V_14 ,
V_15 , 0 ) ;
if ( V_8 == NULL ) {
F_5 ( V_4 ) ;
return - V_16 ;
}
V_6 = (struct V_5 * ) V_8 -> V_17 ;
V_4 -> V_18 = F_6 ( V_6 -> V_19 ) ;
V_4 -> V_20 = F_6 ( V_6 -> V_21 ) ;
V_4 -> V_22 = F_7 ( V_6 -> V_23 ) ;
V_4 -> V_24 = F_7 ( V_6 -> V_25 ) ;
V_4 -> V_26 = F_7 ( V_6 -> V_27 ) ;
V_4 -> V_28 = F_7 ( V_6 -> V_29 ) ;
V_4 -> V_30 = F_7 ( V_6 -> V_31 ) ;
V_4 -> V_32 = F_7 ( V_6 -> V_33 ) ;
V_4 -> V_34 = F_7 ( V_6 -> V_35 ) ;
V_4 -> V_36 = F_7 ( V_6 -> V_37 ) ;
V_4 -> V_38 = F_7 ( V_6 -> V_39 ) ;
V_4 -> V_40 = F_7 ( V_6 -> V_41 ) ;
for ( V_9 = 0 ; V_9 < V_42 ; V_9 ++ )
V_4 -> V_43 [ V_9 ] = F_6 ( V_6 -> V_44 [ V_9 ] ) ;
V_4 -> V_45 = F_6 ( V_6 -> V_46 ) ;
V_4 -> V_47 = V_6 -> V_48 ;
F_8 ( V_8 ) ;
V_4 -> V_49 = V_2 ;
F_4 ( V_2 -> V_13 ) -> V_3 = V_4 ;
memset ( V_4 -> V_50 , 0 , sizeof( V_4 -> V_50 ) ) ;
F_9 ( V_4 ) ;
return ( 0 ) ;
}
int F_10 ( struct V_1 * V_2 , int V_51 )
{
struct V_3 * V_4 = F_4 ( V_2 -> V_13 ) -> V_3 ;
if ( ! ( V_51 || F_11 ( V_2 ) ) )
F_12 ( V_2 ) ;
F_13 ( V_2 -> V_52 , 0 ) ;
F_5 ( V_4 ) ;
return ( 0 ) ;
}
int F_12 ( struct V_1 * V_2 )
{
struct V_5 * V_6 ;
struct V_3 * V_4 = F_4 ( V_2 -> V_13 ) -> V_3 ;
struct V_7 * V_8 ;
int V_9 ;
V_8 = F_3 ( V_2 ,
V_12 << F_4 ( V_2 -> V_13 ) -> V_14 ,
V_15 , 0 ) ;
if ( V_8 == NULL ) {
F_14 ( L_1 ) ;
return - V_16 ;
}
V_6 = (struct V_5 * ) V_8 -> V_17 ;
V_6 -> V_19 = F_15 ( V_4 -> V_18 ) ;
V_6 -> V_21 = F_15 ( V_4 -> V_20 ) ;
V_6 -> V_23 = F_16 ( V_4 -> V_22 ) ;
V_6 -> V_25 = F_16 ( V_4 -> V_24 ) ;
V_6 -> V_27 = F_16 ( V_4 -> V_26 ) ;
V_6 -> V_29 = F_16 ( V_4 -> V_28 ) ;
V_6 -> V_31 = F_16 ( V_4 -> V_30 ) ;
V_6 -> V_33 = F_16 ( V_4 -> V_32 ) ;
V_6 -> V_35 = F_16 ( V_4 -> V_34 ) ;
V_6 -> V_37 = F_16 ( V_4 -> V_36 ) ;
V_6 -> V_39 = F_16 ( V_4 -> V_38 ) ;
V_6 -> V_41 = F_16 ( V_4 -> V_40 ) ;
for ( V_9 = 0 ; V_9 < V_42 ; V_9 ++ )
V_6 -> V_44 [ V_9 ] = F_15 ( V_4 -> V_43 [ V_9 ] ) ;
V_6 -> V_46 = F_15 ( V_4 -> V_45 ) ;
V_6 -> V_48 = V_4 -> V_47 ;
F_17 ( V_8 ) ;
F_18 ( V_2 -> V_52 ) ;
F_19 ( V_2 , 0 ) ;
return ( 0 ) ;
}
int F_20 ( struct V_1 * V_53 , T_1 V_54 , T_1 V_55 )
{
struct V_7 * V_8 ;
struct V_56 * V_57 ;
int V_58 , V_59 ;
T_1 V_60 , V_61 ;
struct V_1 * V_2 = F_4 ( V_53 -> V_13 ) -> V_2 ;
struct V_3 * V_4 = F_4 ( V_53 -> V_13 ) -> V_3 ;
F_21 ( V_2 , V_62 ) ;
if ( F_22 ( ( V_54 == 0 ) || ( V_54 + V_55 > V_4 -> V_18 ) ) ) {
F_23 ( V_2 ) ;
F_24 ( V_63 L_2 ,
( unsigned long long ) V_54 ,
( unsigned long long ) V_55 ) ;
F_25 ( V_53 -> V_13 ,
L_3 ) ;
return - V_16 ;
}
V_8 = NULL ;
for ( V_61 = V_55 ; V_61 > 0 ; V_61 -= V_58 , V_54 += V_58 ) {
if ( V_8 ) {
F_17 ( V_8 ) ;
}
V_60 = F_26 ( V_54 , V_4 -> V_22 ) ;
V_8 = F_3 ( V_2 , V_60 , V_15 , 0 ) ;
if ( V_8 == NULL ) {
F_23 ( V_2 ) ;
return - V_16 ;
}
V_57 = (struct V_56 * ) V_8 -> V_17 ;
V_58 = F_27 ( V_61 , V_64 - ( V_54 & ( V_64 - 1 ) ) ) ;
if ( ( V_59 = F_28 ( V_4 , V_57 , V_54 , V_58 ) ) ) {
F_25 ( V_53 -> V_13 , L_4 ) ;
F_8 ( V_8 ) ;
F_23 ( V_2 ) ;
return ( V_59 ) ;
}
}
F_17 ( V_8 ) ;
F_23 ( V_2 ) ;
return ( 0 ) ;
}
int
F_29 ( struct V_1 * V_2 ,
int free , T_1 V_54 , T_1 V_55 , struct V_65 * V_66 )
{
int V_67 , V_68 , V_69 , V_70 ;
int V_71 , V_72 , V_73 ;
struct V_3 * V_4 = F_4 ( V_2 -> V_13 ) -> V_3 ;
T_1 V_60 , V_61 , V_74 ;
T_2 V_75 ;
struct V_56 * V_57 ;
struct V_7 * V_8 ;
struct V_76 * log ;
int V_77 , V_78 , V_79 ;
unsigned long V_80 ;
if ( V_54 + V_55 > V_4 -> V_18 ) {
F_24 ( V_63 L_2 ,
( unsigned long long ) V_54 ,
( unsigned long long ) V_55 ) ;
F_25 ( V_2 -> V_13 ,
L_5 ) ;
return - V_16 ;
}
V_77 = V_66 -> V_77 ;
log = (struct V_76 * ) F_4 ( V_66 -> V_81 ) -> log ;
F_30 ( V_78 , V_77 , log ) ;
V_8 = NULL ;
V_74 = 0 ;
for ( V_61 = V_55 ; V_61 > 0 ; V_61 -= V_67 , V_54 += V_67 ) {
V_60 = F_26 ( V_54 , V_4 -> V_22 ) ;
if ( V_60 != V_74 ) {
if ( V_8 ) {
F_17 ( V_8 ) ;
}
V_8 = F_3 ( V_4 -> V_49 , V_60 , V_15 ,
0 ) ;
if ( V_8 == NULL )
return - V_16 ;
F_31 ( V_8 ) ;
}
V_57 = (struct V_56 * ) V_8 -> V_17 ;
V_68 = V_54 & ( V_64 - 1 ) ;
V_71 = V_68 >> V_82 ;
V_67 = F_27 ( V_61 , ( T_1 ) V_64 - V_68 ) ;
for ( V_70 = V_67 ; V_70 > 0 ;
V_70 -= V_72 , V_68 += V_72 ) {
V_69 = V_68 & ( V_83 - 1 ) ;
V_72 = F_27 ( V_70 , V_83 - V_69 ) ;
if ( V_72 < V_83 ) {
V_75 =
( V_84 << ( V_83 - V_72 ) >> V_69 ) ;
if ( free )
V_57 -> V_85 [ V_71 ] &=
F_16 ( ~ V_75 ) ;
else
V_57 -> V_85 [ V_71 ] |=
F_16 ( V_75 ) ;
V_71 += 1 ;
} else {
V_73 = V_70 >> V_82 ;
V_72 = V_73 << V_82 ;
if ( free )
memset ( & V_57 -> V_85 [ V_71 ] , 0 ,
V_73 * 4 ) ;
else
memset ( & V_57 -> V_85 [ V_71 ] , ( int ) V_84 ,
V_73 * 4 ) ;
V_71 += V_73 ;
}
}
if ( V_60 == V_74 )
continue;
V_74 = V_60 ;
F_32 ( log , V_80 ) ;
if ( V_8 -> V_77 != 0 ) {
F_30 ( V_79 , V_8 -> V_77 , log ) ;
if ( V_78 < V_79 ) {
V_8 -> V_77 = V_77 ;
F_33 ( & V_8 -> V_86 , & V_66 -> V_86 ) ;
}
F_30 ( V_78 , V_66 -> V_87 , log ) ;
F_30 ( V_79 , V_8 -> V_87 , log ) ;
if ( V_78 > V_79 )
V_8 -> V_87 = V_66 -> V_87 ;
} else {
V_8 -> log = log ;
V_8 -> V_77 = V_77 ;
log -> V_88 ++ ;
F_34 ( & V_8 -> V_86 , & V_66 -> V_86 ) ;
V_8 -> V_87 = V_66 -> V_87 ;
}
F_35 ( log , V_80 ) ;
}
if ( V_8 ) {
F_17 ( V_8 ) ;
}
return ( 0 ) ;
}
int F_36 ( struct V_1 * V_2 )
{
T_1 V_89 ;
int V_90 ;
T_1 V_91 = 0 ;
int V_9 ;
int V_92 = - 1 ;
struct V_3 * V_4 = F_4 ( V_2 -> V_13 ) -> V_3 ;
F_37 ( V_4 ) ;
V_89 = ( T_2 ) V_4 -> V_20 / V_4 -> V_24 ;
V_90 = V_4 -> V_30 ;
if ( ( F_38 ( & V_4 -> V_50 [ V_90 ] ) == 0 ) &&
( V_4 -> V_43 [ V_90 ] >= V_89 ) )
goto V_93;
for ( V_9 = 0 ; V_9 < V_4 -> V_24 ; V_9 ++ , V_90 ++ ) {
if ( V_90 == V_4 -> V_24 )
V_90 = 0 ;
if ( F_38 ( & V_4 -> V_50 [ V_90 ] ) )
continue;
if ( V_4 -> V_43 [ V_90 ] >= V_89 ) {
V_4 -> V_30 = V_90 ;
goto V_93;
} else if ( V_4 -> V_43 [ V_90 ] > V_91 ) {
V_91 = V_4 -> V_43 [ V_90 ] ;
V_92 = V_90 ;
}
}
if ( V_92 != - 1 )
V_4 -> V_30 = V_92 ;
V_93:
F_39 ( V_4 ) ;
return ( V_4 -> V_30 ) ;
}
int F_40 ( struct V_1 * V_53 , T_1 V_94 , T_1 V_55 , T_1 * V_95 )
{
int V_59 , V_96 ;
struct V_1 * V_2 = F_4 ( V_53 -> V_13 ) -> V_2 ;
struct V_3 * V_4 ;
struct V_7 * V_8 ;
T_1 V_60 , V_54 ;
struct V_56 * V_57 ;
int V_97 ;
T_1 V_98 ;
int V_99 ;
assert ( V_55 > 0 ) ;
V_97 = F_41 ( V_55 ) ;
V_4 = F_4 ( V_53 -> V_13 ) -> V_3 ;
V_98 = V_4 -> V_18 ;
if ( V_94 >= V_98 ) {
F_25 ( V_53 -> V_13 , L_6 ) ;
return - V_16 ;
}
if ( V_97 > V_4 -> V_40 ) {
F_42 ( V_2 , V_62 ) ;
V_59 = F_43 ( V_4 , V_55 , V_97 , V_95 ) ;
goto V_100;
}
if ( V_94 == 0 )
goto V_101;
V_54 = V_94 + 1 ;
if ( V_54 >= V_4 -> V_18 )
goto V_101;
V_96 = V_54 >> V_4 -> V_40 ;
if ( ( V_54 & ( V_4 -> V_45 - 1 ) ) == 0 )
if ( F_38 ( & V_4 -> V_50 [ V_96 ] ) )
goto V_101;
if ( V_55 <= V_64 ) {
F_21 ( V_2 , V_62 ) ;
V_59 = - V_16 ;
V_60 = F_26 ( V_54 , V_4 -> V_22 ) ;
V_8 = F_3 ( V_2 , V_60 , V_15 , 0 ) ;
if ( V_8 == NULL )
goto V_102;
V_57 = (struct V_56 * ) V_8 -> V_17 ;
if ( ( V_59 = F_44 ( V_4 , V_57 , V_54 , ( int ) V_55 ) )
!= - V_103 ) {
if ( V_59 == 0 ) {
* V_95 = V_54 ;
F_45 ( V_8 ) ;
}
F_8 ( V_8 ) ;
goto V_102;
}
V_99 = F_38 ( & V_4 -> V_50 [ V_96 ] ) ;
if ( ( V_99 > 1 ) ||
( ( V_99 == 1 ) && ( F_46 ( V_53 ) -> V_104 != V_96 ) ) ) {
F_8 ( V_8 ) ;
F_23 ( V_2 ) ;
goto V_101;
}
if ( ( V_59 =
F_47 ( V_4 , V_57 , V_54 , ( int ) V_55 , V_97 , V_95 ) )
!= - V_103 ) {
if ( V_59 == 0 )
F_45 ( V_8 ) ;
F_8 ( V_8 ) ;
goto V_102;
}
if ( ( V_59 = F_48 ( V_4 , V_57 , ( int ) V_55 , V_97 , V_95 ) )
!= - V_103 ) {
if ( V_59 == 0 )
F_45 ( V_8 ) ;
F_8 ( V_8 ) ;
goto V_102;
}
F_8 ( V_8 ) ;
F_23 ( V_2 ) ;
}
F_42 ( V_2 , V_62 ) ;
if ( ( V_59 = F_49 ( V_4 , V_96 , V_55 , V_97 , V_95 ) ) != - V_103 )
goto V_100;
F_50 ( V_2 ) ;
V_101:
V_96 = F_36 ( V_2 ) ;
F_42 ( V_2 , V_62 ) ;
if ( ( V_59 = F_49 ( V_4 , V_96 , V_55 , V_97 , V_95 ) ) == - V_103 )
V_59 = F_43 ( V_4 , V_55 , V_97 , V_95 ) ;
V_100:
F_50 ( V_2 ) ;
return ( V_59 ) ;
V_102:
F_23 ( V_2 ) ;
return ( V_59 ) ;
}
int F_51 ( struct V_1 * V_53 , T_1 V_54 , int V_55 )
{
int V_59 ;
struct V_1 * V_2 = F_4 ( V_53 -> V_13 ) -> V_2 ;
struct V_3 * V_4 = F_4 ( V_53 -> V_13 ) -> V_3 ;
struct V_56 * V_57 ;
T_1 V_60 ;
struct V_7 * V_8 ;
F_21 ( V_2 , V_62 ) ;
if ( V_55 <= 0 || V_55 > V_64 || V_54 >= V_4 -> V_18 ) {
F_23 ( V_2 ) ;
return - V_105 ;
}
if ( V_55 > ( ( T_1 ) 1 << V_4 -> V_47 ) ) {
F_23 ( V_2 ) ;
return - V_103 ;
}
V_60 = F_26 ( V_54 , V_4 -> V_22 ) ;
V_8 = F_3 ( V_2 , V_60 , V_15 , 0 ) ;
if ( V_8 == NULL ) {
F_23 ( V_2 ) ;
return - V_16 ;
}
V_57 = (struct V_56 * ) V_8 -> V_17 ;
V_59 = F_44 ( V_4 , V_57 , V_54 , V_55 ) ;
F_23 ( V_2 ) ;
if ( V_59 == 0 )
F_45 ( V_8 ) ;
F_8 ( V_8 ) ;
return ( V_59 ) ;
}
int
F_52 ( struct V_1 * V_53 ,
T_1 V_54 , T_1 V_55 , T_1 V_106 , T_1 * V_95 )
{
int V_59 ;
if ( ( V_59 = F_53 ( V_53 , V_54 , V_55 , V_106 ) ) == 0 ) {
* V_95 = V_54 ;
return ( 0 ) ;
} else {
if ( V_59 != - V_103 )
return ( V_59 ) ;
}
return ( F_40
( V_53 , V_54 + V_55 - 1 , V_106 + V_55 , V_95 ) ) ;
}
static int F_53 ( struct V_1 * V_53 , T_1 V_54 , T_1 V_55 , T_1 V_106 )
{
struct V_107 * V_108 = F_4 ( V_53 -> V_13 ) ;
T_1 V_60 , V_109 , V_110 ;
T_3 V_111 ;
struct V_7 * V_8 ;
struct V_56 * V_57 ;
int V_59 ;
struct V_1 * V_2 = V_108 -> V_2 ;
struct V_3 * V_4 ;
if ( ( ( V_111 = V_54 & ( V_108 -> V_112 - 1 ) ) ) &&
( V_111 + V_55 + V_106 > V_108 -> V_112 ) )
return - V_103 ;
V_109 = V_54 + V_55 - 1 ;
V_110 = V_109 + 1 ;
F_21 ( V_2 , V_62 ) ;
V_4 = V_108 -> V_3 ;
if ( V_109 < 0 || V_109 >= V_4 -> V_18 ) {
F_23 ( V_2 ) ;
F_25 ( V_53 -> V_13 ,
L_7 ) ;
return - V_16 ;
}
if ( V_106 > V_64 || V_110 >= V_4 -> V_18 ||
( V_110 & ( V_4 -> V_45 - 1 ) ) == 0 ) {
F_23 ( V_2 ) ;
return - V_103 ;
}
V_60 = F_26 ( V_110 , V_4 -> V_22 ) ;
V_8 = F_3 ( V_2 , V_60 , V_15 , 0 ) ;
if ( V_8 == NULL ) {
F_23 ( V_2 ) ;
return - V_16 ;
}
V_57 = (struct V_56 * ) V_8 -> V_17 ;
V_59 = F_44 ( V_4 , V_57 , V_110 , ( int ) V_106 ) ;
F_23 ( V_2 ) ;
if ( V_59 == 0 )
F_17 ( V_8 ) ;
else
F_8 ( V_8 ) ;
return ( V_59 ) ;
}
static int F_44 ( struct V_3 * V_4 , struct V_56 * V_57 , T_1 V_54 ,
int V_55 )
{
int V_68 , V_71 , V_113 , V_58 , V_73 , V_69 , V_114 ;
int V_115 ;
T_4 * V_116 ;
T_2 V_75 ;
if ( V_57 -> V_117 . V_118 != F_16 ( V_119 ) ) {
F_25 ( V_4 -> V_49 -> V_13 ,
L_8 ) ;
return - V_16 ;
}
V_116 = V_57 -> V_117 . V_120 + F_7 ( V_57 -> V_117 . V_118 ) ;
V_68 = V_54 & ( V_64 - 1 ) ;
V_71 = V_68 >> V_82 ;
if ( V_68 + V_55 > V_64 )
return - V_103 ;
if ( V_116 [ V_71 ] == V_121 )
return - V_103 ;
for ( V_113 = V_55 ; V_113 > 0 ; V_113 -= V_58 , V_68 += V_58 ) {
V_69 = V_68 & ( V_83 - 1 ) ;
V_58 = F_27 ( V_113 , V_83 - V_69 ) ;
if ( V_58 < V_83 ) {
V_75 = ( V_84 << ( V_83 - V_58 ) >> V_69 ) ;
if ( ( V_75 & ~ F_7 ( V_57 -> V_122 [ V_71 ] ) ) != V_75 )
return - V_103 ;
V_71 += 1 ;
} else {
V_73 = V_113 >> V_82 ;
V_58 = V_73 << V_82 ;
while ( V_73 > 0 ) {
if ( V_116 [ V_71 ] < V_123 )
return - V_103 ;
V_115 =
F_27 ( ( int ) V_116 [ V_71 ] , F_54 ( V_73 ) ) ;
V_114 = F_55 ( V_115 , V_123 ) ;
V_73 -= V_114 ;
V_71 += V_114 ;
}
}
}
return ( F_56 ( V_4 , V_57 , V_54 , V_55 ) ) ;
}
static int
F_47 ( struct V_3 * V_4 ,
struct V_56 * V_57 , T_1 V_54 , int V_55 , int V_97 , T_1 * V_95 )
{
int V_71 , V_124 , V_59 ;
T_4 * V_116 ;
if ( V_57 -> V_117 . V_118 != F_16 ( V_119 ) ) {
F_25 ( V_4 -> V_49 -> V_13 ,
L_9 ) ;
return - V_16 ;
}
V_116 = V_57 -> V_117 . V_120 + F_7 ( V_57 -> V_117 . V_118 ) ;
V_71 = ( V_54 & ( V_64 - 1 ) ) >> V_82 ;
V_124 = F_27 ( V_71 + 4 , V_125 ) ;
for (; V_71 < V_124 ; V_71 ++ ) {
if ( V_116 [ V_71 ] < V_97 )
continue;
V_54 = F_6 ( V_57 -> V_126 ) + ( V_71 << V_82 ) ;
if ( V_116 [ V_71 ] < V_123 )
V_54 +=
F_57 ( F_7 ( V_57 -> V_122 [ V_71 ] ) , V_97 ) ;
if ( ( V_59 = F_56 ( V_4 , V_57 , V_54 , V_55 ) ) == 0 )
* V_95 = V_54 ;
return ( V_59 ) ;
}
return - V_103 ;
}
static int
F_49 ( struct V_3 * V_4 , int V_96 , T_1 V_55 , int V_97 , T_1 * V_95 )
{
struct V_7 * V_8 ;
struct V_127 * V_128 ;
int V_59 , V_129 , V_9 , V_130 , V_131 , V_132 , V_133 ;
T_1 V_54 , V_60 ;
int V_134 ;
if ( V_97 > V_4 -> V_40 ) {
F_25 ( V_4 -> V_49 -> V_13 ,
L_10
L_11 ) ;
return - V_16 ;
}
V_54 = ( T_1 ) V_96 << V_4 -> V_40 ;
if ( V_4 -> V_45 == V_64
|| V_4 -> V_43 [ V_96 ] == V_4 -> V_45 ) {
V_59 = F_58 ( V_4 , V_55 , V_97 , V_54 , V_95 ) ;
if ( ( V_59 == - V_103 ) &&
( V_4 -> V_43 [ V_96 ] == V_4 -> V_45 ) ) {
F_24 ( V_63 L_12 ,
( unsigned long long ) V_54 ,
( unsigned long long ) V_55 ) ;
F_25 ( V_4 -> V_49 -> V_13 ,
L_13 ) ;
}
return ( V_59 ) ;
}
V_60 = F_59 ( V_54 , V_4 -> V_22 , V_4 -> V_32 ) ;
V_8 = F_3 ( V_4 -> V_49 , V_60 , V_15 , 0 ) ;
if ( V_8 == NULL )
return - V_16 ;
V_128 = (struct V_127 * ) V_8 -> V_17 ;
V_134 = V_128 -> V_134 ;
if ( V_128 -> V_118 != F_16 ( V_135 ) ) {
F_25 ( V_4 -> V_49 -> V_13 ,
L_14 ) ;
F_8 ( V_8 ) ;
return - V_16 ;
}
V_133 =
( 1 << ( V_136 - ( V_4 -> V_34 << 1 ) ) ) / V_4 -> V_36 ;
V_129 = V_4 -> V_38 + V_4 -> V_36 * ( V_96 & ( V_133 - 1 ) ) ;
for ( V_9 = 0 ; V_9 < V_4 -> V_36 ; V_9 ++ , V_129 ++ ) {
if ( V_97 > V_128 -> V_120 [ V_129 ] )
continue;
for ( V_130 = V_4 -> V_34 ; V_130 > 0 ; V_130 -- ) {
for ( V_132 = 0 , V_131 = ( V_129 << 2 ) + 1 ; V_132 < 4 ; V_132 ++ ) {
if ( V_97 <= V_128 -> V_120 [ V_131 + V_132 ] ) {
V_129 = V_131 + V_132 ;
break;
}
}
if ( V_132 == 4 ) {
F_25 ( V_4 -> V_49 -> V_13 ,
L_15 ) ;
F_8 ( V_8 ) ;
return - V_16 ;
}
}
if ( V_4 -> V_32 == 2 )
V_54 = 0 ;
else if ( V_4 -> V_32 == 1 )
V_54 &= ~ ( V_137 - 1 ) ;
else
V_54 &= ~ ( V_138 - 1 ) ;
V_54 +=
( ( T_1 ) ( V_129 - F_7 ( V_128 -> V_118 ) ) ) << V_134 ;
F_8 ( V_8 ) ;
if ( V_97 < V_134 ) {
if ( ( V_59 =
F_60 ( V_4 , V_97 , V_4 -> V_32 - 1 ,
& V_54 ) ) ) {
if ( V_59 == - V_103 ) {
F_25 ( V_4 -> V_49 -> V_13 ,
L_16
L_17 ) ;
return - V_16 ;
}
return ( V_59 ) ;
}
}
V_59 = F_58 ( V_4 , V_55 , V_97 , V_54 , V_95 ) ;
if ( V_59 == - V_103 ) {
F_25 ( V_4 -> V_49 -> V_13 ,
L_18 ) ;
V_59 = - V_16 ;
}
return ( V_59 ) ;
}
F_8 ( V_8 ) ;
return - V_103 ;
}
static int F_43 ( struct V_3 * V_4 , T_1 V_55 , int V_97 , T_1 * V_95 )
{
int V_59 ;
T_1 V_54 = 0 ;
if ( ( V_59 = F_60 ( V_4 , V_97 , V_4 -> V_26 , & V_54 ) ) )
return ( V_59 ) ;
V_59 = F_58 ( V_4 , V_55 , V_97 , V_54 , V_95 ) ;
if ( V_59 == - V_103 ) {
F_25 ( V_4 -> V_49 -> V_13 ,
L_19 ) ;
return - V_16 ;
}
return ( V_59 ) ;
}
static int F_60 ( struct V_3 * V_4 , int V_97 , int V_139 , T_1 * V_54 )
{
int V_59 , V_118 , V_140 ;
T_1 V_141 , V_60 ;
struct V_127 * V_128 ;
int V_134 ;
struct V_7 * V_8 ;
for ( V_140 = V_139 , V_141 = * V_54 ; V_140 >= 0 ; V_140 -- ) {
V_60 = F_59 ( V_141 , V_4 -> V_22 , V_140 ) ;
V_8 = F_3 ( V_4 -> V_49 , V_60 , V_15 , 0 ) ;
if ( V_8 == NULL )
return - V_16 ;
V_128 = (struct V_127 * ) V_8 -> V_17 ;
V_134 = V_128 -> V_134 ;
if ( V_128 -> V_118 != F_16 ( V_135 ) ) {
F_25 ( V_4 -> V_49 -> V_13 ,
L_20 ) ;
F_8 ( V_8 ) ;
return - V_16 ;
}
V_59 = F_61 ( ( V_142 * ) V_128 , V_97 , & V_118 ) ;
F_8 ( V_8 ) ;
if ( V_59 ) {
if ( V_140 != V_139 ) {
F_25 ( V_4 -> V_49 -> V_13 ,
L_21 ) ;
return - V_16 ;
}
return - V_103 ;
}
V_141 += ( ( ( T_1 ) V_118 ) << V_134 ) ;
if ( V_97 >= V_134 )
break;
}
* V_54 = V_141 ;
return ( 0 ) ;
}
static int
F_58 ( struct V_3 * V_4 , T_1 V_55 , int V_97 , T_1 V_54 , T_1 * V_95 )
{
int V_59 , V_58 ;
T_1 V_141 , V_60 , V_132 ;
struct V_7 * V_8 ;
struct V_56 * V_57 ;
if ( V_97 <= V_143 ) {
V_60 = F_26 ( V_54 , V_4 -> V_22 ) ;
V_8 = F_3 ( V_4 -> V_49 , V_60 , V_15 , 0 ) ;
if ( V_8 == NULL )
return - V_16 ;
V_57 = (struct V_56 * ) V_8 -> V_17 ;
V_59 = F_48 ( V_4 , V_57 , ( int ) V_55 , V_97 , V_95 ) ;
if ( V_59 == 0 )
F_45 ( V_8 ) ;
F_8 ( V_8 ) ;
return ( V_59 ) ;
}
assert ( ( V_54 & ( V_64 - 1 ) ) == 0 ) ;
for ( V_132 = V_55 , V_141 = V_54 ; V_132 > 0 ; V_132 -= V_58 , V_141 += V_58 ) {
V_60 = F_26 ( V_141 , V_4 -> V_22 ) ;
V_8 = F_3 ( V_4 -> V_49 , V_60 , V_15 , 0 ) ;
if ( V_8 == NULL ) {
V_59 = - V_16 ;
goto V_144;
}
V_57 = (struct V_56 * ) V_8 -> V_17 ;
if ( V_57 -> V_117 . V_120 [ V_145 ] != V_143 ) {
F_8 ( V_8 ) ;
F_25 ( V_4 -> V_49 -> V_13 ,
L_22 ) ;
V_59 = - V_16 ;
goto V_144;
}
V_58 = F_27 ( V_132 , ( T_1 ) V_64 ) ;
if ( ( V_59 = F_56 ( V_4 , V_57 , V_141 , V_58 ) ) ) {
F_8 ( V_8 ) ;
goto V_144;
}
F_17 ( V_8 ) ;
}
* V_95 = V_54 ;
return ( 0 ) ;
V_144:
for ( V_132 = V_55 - V_132 , V_141 = V_54 ; V_132 > 0 ;
V_132 -= V_64 , V_141 += V_64 ) {
V_60 = F_26 ( V_141 , V_4 -> V_22 ) ;
V_8 = F_3 ( V_4 -> V_49 , V_60 , V_15 , 0 ) ;
if ( V_8 == NULL ) {
F_25 ( V_4 -> V_49 -> V_13 ,
L_23 ) ;
continue;
}
V_57 = (struct V_56 * ) V_8 -> V_17 ;
if ( F_28 ( V_4 , V_57 , V_141 , V_64 ) ) {
F_8 ( V_8 ) ;
F_25 ( V_4 -> V_49 -> V_13 ,
L_24 ) ;
continue;
}
F_17 ( V_8 ) ;
}
return ( V_59 ) ;
}
static int
F_48 ( struct V_3 * V_4 ,
struct V_56 * V_57 , int V_55 , int V_97 , T_1 * V_95 )
{
T_1 V_54 ;
int V_118 , V_59 ;
assert ( V_97 <= V_143 ) ;
if ( F_61 ( ( V_142 * ) & V_57 -> V_117 , V_97 , & V_118 ) )
return - V_103 ;
V_54 = F_6 ( V_57 -> V_126 ) + ( V_118 << V_82 ) ;
if ( V_57 -> V_117 . V_120 [ V_118 + V_119 ] < V_123 )
V_54 += F_57 ( F_7 ( V_57 -> V_122 [ V_118 ] ) , V_97 ) ;
if ( ( V_59 = F_56 ( V_4 , V_57 , V_54 , V_55 ) ) == 0 )
* V_95 = V_54 ;
return ( V_59 ) ;
}
static int F_56 ( struct V_3 * V_4 , struct V_56 * V_57 , T_1 V_54 ,
int V_55 )
{
T_4 V_146 ;
int V_59 ;
V_146 = V_57 -> V_117 . V_120 [ V_145 ] ;
F_62 ( V_4 , V_57 , V_54 , V_55 ) ;
if ( V_57 -> V_117 . V_120 [ V_145 ] == V_146 )
return ( 0 ) ;
if ( ( V_59 = F_63 ( V_4 , V_54 , V_57 -> V_117 . V_120 [ V_145 ] , 1 , 0 ) ) )
F_64 ( V_4 , V_57 , V_54 , V_55 ) ;
return ( V_59 ) ;
}
static int F_28 ( struct V_3 * V_4 , struct V_56 * V_57 , T_1 V_54 ,
int V_55 )
{
T_4 V_146 ;
int V_59 = 0 , V_71 ;
V_146 = V_57 -> V_117 . V_120 [ V_145 ] ;
V_59 = F_64 ( V_4 , V_57 , V_54 , V_55 ) ;
if ( V_59 || ( V_57 -> V_117 . V_120 [ V_145 ] == V_146 ) )
return ( V_59 ) ;
if ( ( V_59 = F_63 ( V_4 , V_54 , V_57 -> V_117 . V_120 [ V_145 ] , 0 , 0 ) ) ) {
V_71 = ( V_54 & ( V_64 - 1 ) ) >> V_82 ;
if ( V_57 -> V_117 . V_120 [ V_71 ] == V_121 )
F_65 ( ( V_142 * ) & V_57 -> V_117 , V_71 ) ;
F_62 ( V_4 , V_57 , V_54 , V_55 ) ;
}
return ( V_59 ) ;
}
static void F_62 ( struct V_3 * V_4 , struct V_56 * V_57 , T_1 V_54 ,
int V_55 )
{
int V_68 , V_71 , V_113 , V_58 , V_73 , V_69 , V_114 , V_96 ;
V_142 * V_147 = ( V_142 * ) & V_57 -> V_117 ;
int V_148 ;
T_4 * V_116 ;
V_116 = V_57 -> V_117 . V_120 + V_119 ;
V_68 = V_54 & ( V_64 - 1 ) ;
V_71 = V_68 >> V_82 ;
assert ( V_68 + V_55 <= V_64 ) ;
for ( V_113 = V_55 ; V_113 > 0 ; V_113 -= V_58 , V_68 += V_58 ) {
V_69 = V_68 & ( V_83 - 1 ) ;
V_58 = F_27 ( V_113 , V_83 - V_69 ) ;
if ( V_58 < V_83 ) {
V_57 -> V_122 [ V_71 ] |= F_16 ( V_84 << ( V_83 - V_58 )
>> V_69 ) ;
F_66 ( V_147 , V_71 , V_123 ,
F_67 ( ( V_149 * ) & V_57 -> V_122 [ V_71 ] ) ) ;
V_71 += 1 ;
} else {
V_73 = V_113 >> V_82 ;
memset ( & V_57 -> V_122 [ V_71 ] , ( int ) V_84 , V_73 * 4 ) ;
V_58 = V_73 << V_82 ;
for (; V_73 > 0 ; V_73 -= V_114 ) {
if ( V_116 [ V_71 ] < V_123 ) {
F_25 ( V_4 -> V_49 -> V_13 ,
L_25
L_26 ) ;
break;
}
V_148 = F_27 ( ( int ) V_116 [ V_71 ] , F_54 ( V_73 ) ) ;
F_66 ( V_147 , V_71 , V_148 , V_121 ) ;
V_114 = F_55 ( V_148 , V_123 ) ;
V_71 += V_114 ;
}
}
}
F_68 ( & V_57 -> V_150 , - V_55 ) ;
F_37 ( V_4 ) ;
V_96 = V_54 >> V_4 -> V_40 ;
if ( V_96 > V_4 -> V_28 )
V_4 -> V_28 = V_96 ;
V_4 -> V_43 [ V_96 ] -= V_55 ;
V_4 -> V_20 -= V_55 ;
F_39 ( V_4 ) ;
}
static int F_64 ( struct V_3 * V_4 , struct V_56 * V_57 , T_1 V_54 ,
int V_55 )
{
int V_68 , V_71 , V_113 , V_58 , V_73 , V_69 , V_114 , V_96 ;
V_142 * V_147 = ( V_142 * ) & V_57 -> V_117 ;
int V_59 = 0 ;
int V_148 ;
V_68 = V_54 & ( V_64 - 1 ) ;
V_71 = V_68 >> V_82 ;
assert ( V_68 + V_55 <= V_64 ) ;
for ( V_113 = V_55 ; V_113 > 0 ; V_113 -= V_58 , V_68 += V_58 ) {
V_69 = V_68 & ( V_83 - 1 ) ;
V_58 = F_27 ( V_113 , V_83 - V_69 ) ;
if ( V_58 < V_83 ) {
V_57 -> V_122 [ V_71 ] &=
F_16 ( ~ ( V_84 << ( V_83 - V_58 )
>> V_69 ) ) ;
V_59 = F_69 ( V_147 , V_71 ,
F_67 ( ( V_149 * ) & V_57 -> V_122 [ V_71 ] ) ) ;
if ( V_59 )
return V_59 ;
V_71 += 1 ;
} else {
V_73 = V_113 >> V_82 ;
memset ( & V_57 -> V_122 [ V_71 ] , 0 , V_73 * 4 ) ;
V_58 = V_73 << V_82 ;
for (; V_73 > 0 ; V_73 -= V_114 ) {
V_148 =
F_27 ( F_70
( V_71 , V_151 , V_123 ) ,
F_54 ( V_73 ) ) ;
V_59 = F_69 ( V_147 , V_71 , V_148 ) ;
if ( V_59 )
return V_59 ;
V_114 = F_55 ( V_148 , V_123 ) ;
V_71 += V_114 ;
}
}
}
F_68 ( & V_57 -> V_150 , V_55 ) ;
F_37 ( V_4 ) ;
V_96 = V_54 >> V_4 -> V_40 ;
V_4 -> V_20 += V_55 ;
V_4 -> V_43 [ V_96 ] += V_55 ;
if ( ( V_4 -> V_43 [ V_96 ] == V_4 -> V_45 && V_96 == V_4 -> V_28 ) ||
( V_96 == V_4 -> V_24 - 1 &&
V_4 -> V_43 [ V_96 ] == ( V_4 -> V_18 & ( V_64 - 1 ) ) ) ) {
while ( V_4 -> V_28 > 0 ) {
V_4 -> V_28 -= 1 ;
if ( V_4 -> V_43 [ V_4 -> V_28 ] !=
V_4 -> V_45 )
break;
}
if ( V_4 -> V_30 > V_4 -> V_28 )
V_4 -> V_30 = V_4 -> V_28 ;
}
F_39 ( V_4 ) ;
return 0 ;
}
static int
F_63 ( struct V_3 * V_4 , T_1 V_54 , int V_152 , int V_153 , int V_139 )
{
struct V_7 * V_8 ;
T_4 V_146 ;
int V_154 ;
T_1 V_60 ;
struct V_127 * V_128 ;
int V_59 , V_155 , V_129 ;
V_60 = F_59 ( V_54 , V_4 -> V_22 , V_139 ) ;
V_8 = F_3 ( V_4 -> V_49 , V_60 , V_15 , 0 ) ;
if ( V_8 == NULL )
return - V_16 ;
V_128 = (struct V_127 * ) V_8 -> V_17 ;
if ( V_128 -> V_118 != F_16 ( V_135 ) ) {
F_25 ( V_4 -> V_49 -> V_13 ,
L_27 ) ;
F_8 ( V_8 ) ;
return - V_16 ;
}
V_155 = F_71 ( V_54 , V_128 -> V_134 ) ;
V_129 = V_155 + F_7 ( V_128 -> V_118 ) ;
V_154 = V_128 -> V_120 [ V_129 ] ;
V_146 = V_128 -> V_120 [ V_145 ] ;
if ( V_153 ) {
if ( V_154 == V_121 ) {
V_59 = F_65 ( ( V_142 * ) V_128 , V_155 ) ;
if ( V_59 )
return V_59 ;
V_154 = V_128 -> V_120 [ V_129 ] ;
}
F_66 ( ( V_142 * ) V_128 , V_155 , V_128 -> V_134 , V_152 ) ;
} else {
V_59 = F_69 ( ( V_142 * ) V_128 , V_155 , V_152 ) ;
if ( V_59 )
return V_59 ;
}
if ( V_128 -> V_120 [ V_145 ] != V_146 ) {
if ( V_139 < V_4 -> V_26 ) {
if ( ( V_59 =
F_63 ( V_4 , V_54 , V_128 -> V_120 [ V_145 ] , V_153 ,
V_139 + 1 ) ) ) {
if ( V_153 ) {
F_69 ( ( V_142 * ) V_128 , V_155 ,
V_154 ) ;
} else {
if ( V_128 -> V_120 [ V_129 ] == V_121 )
F_65 ( ( V_142 * )
V_128 , V_155 ) ;
F_66 ( ( V_142 * ) V_128 , V_155 ,
V_128 -> V_134 , V_154 ) ;
}
F_8 ( V_8 ) ;
return ( V_59 ) ;
}
} else {
assert ( V_139 == V_4 -> V_26 ) ;
if ( V_4 -> V_47 != V_146 ) {
F_25 ( V_4 -> V_49 -> V_13 ,
L_28
L_29 ) ;
}
V_4 -> V_47 = V_128 -> V_120 [ V_145 ] ;
}
}
F_17 ( V_8 ) ;
return ( 0 ) ;
}
static void F_66 ( V_142 * V_147 , int V_155 , int V_156 , int V_152 )
{
int V_157 ;
int V_158 ;
T_4 * V_116 = V_147 -> V_159 + F_7 ( V_147 -> V_160 ) ;
if ( V_116 [ V_155 ] > V_147 -> V_161 ) {
V_158 = V_116 [ V_155 ] - 1 ;
V_157 = F_55 ( V_158 , V_147 -> V_161 ) ;
while ( V_158 >= V_156 ) {
F_72 ( V_147 , V_155 ^ V_157 , V_158 ) ;
V_158 -= 1 ;
V_157 >>= 1 ;
}
}
F_72 ( V_147 , V_155 , V_152 ) ;
}
static int F_65 ( V_142 * V_147 , int V_155 )
{
int V_157 , V_162 , V_163 , V_164 , V_148 ;
int V_158 ;
T_4 * V_116 = V_147 -> V_159 + F_7 ( V_147 -> V_160 ) ;
assert ( V_116 [ V_155 ] == V_121 ) ;
V_148 =
F_70 ( V_155 , F_7 ( V_147 -> V_165 ) ,
V_147 -> V_161 ) ;
V_157 = F_55 ( V_148 , V_147 -> V_161 ) ;
while ( V_116 [ V_155 ] == V_121 ) {
for ( V_163 = V_155 , V_164 = V_157 ; ; V_164 <<= 1 ,
V_163 = ( V_163 < V_162 ) ? V_163 : V_162 ) {
if ( V_164 >= F_7 ( V_147 -> V_166 ) ) {
F_14 ( L_30 ) ;
return - V_16 ;
}
V_162 = V_163 ^ V_164 ;
if ( V_116 [ V_162 ] != V_121 ) {
V_158 = V_116 [ V_162 ] - 1 ;
F_66 ( V_147 , V_162 , V_158 , V_158 ) ;
break;
}
}
}
if ( V_116 [ V_155 ] != V_148 ) {
F_14 ( L_31 ) ;
return - V_16 ;
}
return 0 ;
}
static int F_69 ( V_142 * V_147 , int V_155 , int V_152 )
{
int V_157 , V_167 ;
T_4 * V_116 ;
if ( V_152 >= V_147 -> V_161 ) {
V_116 = V_147 -> V_159 + F_7 ( V_147 -> V_160 ) ;
V_157 = F_55 ( V_152 , V_147 -> V_161 ) ;
while ( V_157 < F_7 ( V_147 -> V_166 ) ) {
V_167 = V_155 ^ V_157 ;
if ( V_152 > V_116 [ V_167 ] )
break;
if ( V_152 < V_116 [ V_167 ] )
return - V_16 ;
if ( V_155 < V_167 ) {
F_72 ( V_147 , V_167 , V_121 ) ;
} else {
F_72 ( V_147 , V_155 , V_121 ) ;
V_155 = V_167 ;
}
V_152 += 1 ;
V_157 <<= 1 ;
}
}
F_72 ( V_147 , V_155 , V_152 ) ;
return 0 ;
}
static void F_72 ( V_142 * V_147 , int V_155 , int V_152 )
{
int V_168 , V_169 , V_130 ;
int V_170 ;
V_168 = V_155 + F_7 ( V_147 -> V_160 ) ;
if ( V_147 -> V_159 [ V_168 ] == V_152 )
return;
V_147 -> V_159 [ V_168 ] = V_152 ;
for ( V_130 = 0 ; V_130 < F_7 ( V_147 -> V_171 ) ; V_130 ++ ) {
V_168 = ( ( V_168 - 1 ) & ~ 0x03 ) + 1 ;
V_169 = ( V_168 - 1 ) >> 2 ;
V_170 = F_73 ( & V_147 -> V_159 [ V_168 ] ) ;
if ( V_147 -> V_159 [ V_169 ] == V_170 )
break;
V_147 -> V_159 [ V_169 ] = V_170 ;
V_168 = V_169 ;
}
}
static int F_61 ( V_142 * V_147 , int V_97 , int * V_118 )
{
int V_129 , V_132 = 0 , V_130 , V_172 = 0 ;
if ( V_97 > V_147 -> V_159 [ V_145 ] )
return - V_103 ;
for ( V_130 = F_7 ( V_147 -> V_171 ) , V_129 = 1 ;
V_130 > 0 ; V_130 -- , V_129 = ( ( V_129 + V_132 ) << 2 ) + 1 ) {
for ( V_172 = V_129 , V_132 = 0 ; V_132 < 4 ; V_132 ++ ) {
if ( V_97 <= V_147 -> V_159 [ V_172 + V_132 ] )
break;
}
assert ( V_132 < 4 ) ;
}
* V_118 = V_172 + V_132 - F_7 ( V_147 -> V_160 ) ;
return ( 0 ) ;
}
static int F_57 ( T_2 V_71 , int V_97 )
{
int V_173 , V_58 ;
T_2 V_75 ;
V_58 = 1 << V_97 ;
assert ( V_58 <= V_83 ) ;
V_71 = ~ V_71 ;
V_75 = V_84 << ( V_83 - V_58 ) ;
for ( V_173 = 0 ; V_75 != 0 ; V_173 += V_58 , V_75 >>= V_58 ) {
if ( ( V_75 & V_71 ) == V_75 )
break;
}
ASSERT ( V_173 < 32 ) ;
return ( V_173 ) ;
}
static int F_67 ( V_149 * V_174 )
{
signed char V_175 , V_176 ;
if ( * ( ( T_3 * ) V_174 ) == 0 )
return ( V_123 ) ;
if ( * ( ( V_177 * ) V_174 ) == 0 || * ( ( V_177 * ) V_174 + 1 ) == 0 )
return ( V_123 - 1 ) ;
V_175 = V_170 ( V_178 [ V_174 [ 2 ] ] , V_178 [ V_174 [ 3 ] ] ) ;
V_176 = V_170 ( V_178 [ V_174 [ 0 ] ] , V_178 [ V_174 [ 1 ] ] ) ;
return ( V_170 ( V_175 , V_176 ) ) ;
}
static int F_74 ( T_2 V_71 )
{
int V_132 ;
for ( V_132 = 0 ; V_132 < 32 ; V_132 ++ , V_71 >>= 1 ) {
if ( V_71 & 0x01 )
break;
}
return ( V_132 ) ;
}
static int F_75 ( T_2 V_179 )
{
int V_132 ;
for ( V_132 = 0 ; V_132 < 32 ; V_132 ++ , V_179 <<= 1 ) {
if ( V_179 & V_180 )
break;
}
return ( V_132 ) ;
}
static int F_76 ( T_1 V_58 )
{
int V_97 ;
T_1 V_75 ;
V_75 = ( T_1 ) 1 << ( 64 - 1 ) ;
for ( V_97 = 0 ; V_97 < 64 ; V_97 ++ , V_75 >>= 1 ) {
if ( V_58 & V_75 ) {
V_97 = ( 64 - 1 ) - V_97 ;
if ( ~ V_75 & V_58 )
V_97 ++ ;
return ( V_97 ) ;
}
}
assert ( 0 ) ;
return 0 ;
}
int F_77 ( struct V_1 * V_53 , T_1 V_54 , T_1 V_55 )
{
struct V_7 * V_8 ;
struct V_56 * V_57 ;
int V_58 , V_59 ;
T_1 V_60 , V_61 ;
struct V_1 * V_2 = F_4 ( V_53 -> V_13 ) -> V_2 ;
struct V_3 * V_4 = F_4 ( V_53 -> V_13 ) -> V_3 ;
F_21 ( V_2 , V_62 ) ;
ASSERT ( V_55 <= V_4 -> V_18 - V_54 ) ;
V_8 = NULL ;
for ( V_61 = V_55 ; V_61 > 0 ; V_61 -= V_58 , V_54 += V_58 ) {
if ( V_8 ) {
F_17 ( V_8 ) ;
}
V_60 = F_26 ( V_54 , V_4 -> V_22 ) ;
V_8 = F_3 ( V_2 , V_60 , V_15 , 0 ) ;
if ( V_8 == NULL ) {
F_23 ( V_2 ) ;
return - V_16 ;
}
V_57 = (struct V_56 * ) V_8 -> V_17 ;
V_58 = F_27 ( V_61 , V_64 - ( V_54 & ( V_64 - 1 ) ) ) ;
if ( ( V_59 = F_78 ( V_4 , V_57 , V_54 , V_58 ) ) ) {
F_8 ( V_8 ) ;
F_23 ( V_2 ) ;
return ( V_59 ) ;
}
}
F_17 ( V_8 ) ;
F_23 ( V_2 ) ;
return ( 0 ) ;
}
static int F_78 ( struct V_3 * V_4 , struct V_56 * V_57 , T_1 V_54 ,
int V_55 )
{
int V_59 ;
int V_68 , V_71 , V_113 , V_58 , V_73 , V_69 , V_96 ;
T_4 V_146 , * V_116 ;
struct V_181 * V_147 = (struct V_181 * ) & V_57 -> V_117 ;
V_146 = V_147 -> V_120 [ V_145 ] ;
V_116 = V_147 -> V_120 + V_119 ;
V_68 = V_54 & ( V_64 - 1 ) ;
V_71 = V_68 >> V_82 ;
assert ( V_68 + V_55 <= V_64 ) ;
for ( V_113 = V_55 ; V_113 > 0 ; V_113 -= V_58 , V_68 += V_58 ) {
V_69 = V_68 & ( V_83 - 1 ) ;
V_58 = F_27 ( V_113 , V_83 - V_69 ) ;
if ( V_58 < V_83 ) {
V_57 -> V_122 [ V_71 ] |= F_16 ( V_84 << ( V_83 - V_58 )
>> V_69 ) ;
V_71 ++ ;
} else {
V_73 = V_113 >> V_82 ;
memset ( & V_57 -> V_122 [ V_71 ] , ( int ) V_84 , V_73 * 4 ) ;
V_58 = V_73 << V_82 ;
V_71 += V_73 ;
}
}
F_68 ( & V_57 -> V_150 , - V_55 ) ;
F_79 ( V_57 ) ;
F_37 ( V_4 ) ;
V_96 = V_54 >> V_4 -> V_40 ;
if ( V_96 > V_4 -> V_28 )
V_4 -> V_28 = V_96 ;
V_4 -> V_43 [ V_96 ] -= V_55 ;
V_4 -> V_20 -= V_55 ;
F_39 ( V_4 ) ;
if ( V_147 -> V_120 [ V_145 ] == V_146 )
return ( 0 ) ;
if ( ( V_59 = F_63 ( V_4 , V_54 , V_147 -> V_120 [ V_145 ] , 1 , 0 ) ) )
F_64 ( V_4 , V_57 , V_54 , V_55 ) ;
return ( V_59 ) ;
}
int F_80 ( struct V_1 * V_2 , T_1 V_54 , T_1 V_55 )
{
struct V_107 * V_108 = F_4 ( V_2 -> V_13 ) ;
int V_112 = V_108 -> V_112 ;
int V_9 , V_182 = true , V_183 , j0 = true , V_130 , V_132 ;
T_1 V_184 ;
T_1 V_185 ;
struct V_7 * V_8 , * V_186 , * V_187 = NULL , * V_188 = NULL ;
struct V_127 * V_189 , * V_190 , * V_191 ;
struct V_56 * V_57 ;
T_4 * V_192 , * V_193 , * V_194 ;
struct V_3 * V_4 = V_108 -> V_3 ;
int V_96 , V_195 , V_196 ;
T_1 V_197 ;
V_184 = V_54 + V_55 ;
F_81 ( L_32 ,
( long long ) V_54 , ( long long ) V_55 , ( long long ) V_184 ) ;
V_4 -> V_18 = V_184 ;
V_4 -> V_26 = F_82 ( V_4 -> V_18 ) ;
V_195 = F_83 ( V_184 ) ;
V_196 = V_4 -> V_40 ;
V_4 -> V_40 = V_195 ;
V_4 -> V_45 = 1 << V_195 ;
V_96 = V_4 -> V_24 ;
V_4 -> V_24 = V_184 >> V_195 ;
V_4 -> V_24 += ( ( T_2 ) V_184 % ( T_2 ) V_4 -> V_45 ) ? 1 : 0 ;
if ( V_195 == V_196 )
goto V_198;
V_130 = 1 << ( V_195 - V_196 ) ;
V_197 = V_4 -> V_43 [ 0 ] ;
for ( V_9 = 0 , V_132 = 0 ; V_9 < V_96 ; V_132 ++ ) {
V_4 -> V_43 [ V_132 ] = 0 ;
for ( V_183 = 0 ; V_183 < V_130 && V_9 < V_96 ; V_183 ++ , V_9 ++ ) {
V_4 -> V_43 [ V_132 ] += V_4 -> V_43 [ V_9 ] ;
}
}
V_4 -> V_43 [ 0 ] += V_197 ;
for (; V_132 < V_42 ; V_132 ++ )
V_4 -> V_43 [ V_132 ] = 0 ;
V_4 -> V_28 = V_4 -> V_28 / V_130 ;
V_198:
V_185 = V_12 + V_112 ;
V_186 = F_3 ( V_2 , V_185 , V_15 , 0 ) ;
if ( ! V_186 ) {
F_25 ( V_2 -> V_13 , L_33 ) ;
return - V_16 ;
}
V_189 = (struct V_127 * ) V_186 -> V_17 ;
V_130 = V_54 >> V_199 ;
V_194 = V_189 -> V_120 + V_135 + V_130 ;
V_185 = F_84 ( V_54 , V_108 -> V_14 ) ;
for (; V_130 < V_200 ; V_130 ++ , V_185 += V_112 ) {
if ( j0 ) {
V_187 = F_3 ( V_2 , V_185 , V_15 , 0 ) ;
if ( V_187 == NULL )
goto V_201;
V_190 = (struct V_127 * ) V_187 -> V_17 ;
V_183 = ( V_54 & ( V_137 - 1 ) ) >> V_202 ;
V_193 = V_190 -> V_120 + V_135 + V_183 ;
V_185 = F_85 ( V_54 , V_108 -> V_14 ) ;
j0 = false ;
} else {
V_187 = F_86 ( V_2 , V_185 , V_15 , 0 ) ;
if ( V_187 == NULL )
goto V_201;
V_190 = (struct V_127 * ) V_187 -> V_17 ;
V_183 = 0 ;
V_193 = V_190 -> V_120 + V_135 ;
V_185 += V_112 ;
}
for (; V_183 < V_200 ; V_183 ++ ) {
if ( V_182 ) {
V_188 = F_3 ( V_2 , V_185 , V_15 , 0 ) ;
if ( V_188 == NULL )
goto V_201;
V_191 = (struct V_127 * ) V_188 -> V_17 ;
V_9 = ( V_54 & ( V_138 - 1 ) ) >>
V_143 ;
V_192 = V_191 -> V_120 + V_135 + V_9 ;
V_185 = F_26 ( V_54 ,
V_108 -> V_14 ) ;
V_182 = false ;
} else {
V_188 = F_86 ( V_2 , V_185 , V_15 , 0 ) ;
if ( V_188 == NULL )
goto V_201;
V_191 = (struct V_127 * ) V_188 -> V_17 ;
V_9 = 0 ;
V_192 = V_191 -> V_120 + V_135 ;
V_185 += V_112 ;
}
for (; V_9 < V_200 ; V_9 ++ ) {
if ( ( V_132 = V_54 & ( V_64 - 1 ) ) ) {
V_8 = F_3 ( V_2 , V_185 ,
V_15 , 0 ) ;
if ( V_8 == NULL )
goto V_201;
V_132 = F_27 ( V_55 , ( T_1 ) V_64 - V_132 ) ;
} else {
V_8 = F_3 ( V_2 , V_185 ,
V_15 , 0 ) ;
if ( V_8 == NULL )
goto V_201;
V_132 = F_27 ( V_55 , ( T_1 ) V_64 ) ;
}
V_57 = (struct V_56 * ) V_8 -> V_17 ;
* V_192 = F_87 ( V_57 , V_54 , V_132 ) ;
V_4 -> V_20 += V_132 ;
V_96 = F_6 ( V_57 -> V_126 ) >> V_195 ;
V_4 -> V_43 [ V_96 ] += V_132 ;
F_17 ( V_8 ) ;
V_192 ++ ;
V_185 += V_112 ;
V_54 += V_132 ;
V_55 -= V_132 ;
if ( V_55 == 0 )
break;
}
* V_193 = F_88 ( V_191 , 0 , ++ V_9 ) ;
F_17 ( V_188 ) ;
V_188 = NULL ;
if ( V_55 )
V_193 ++ ;
else {
if ( V_183 > 0 )
break;
else {
V_4 -> V_47 = * V_193 ;
F_8 ( V_187 ) ;
F_8 ( V_186 ) ;
goto V_203;
}
}
}
* V_194 = F_88 ( V_190 , 1 , ++ V_183 ) ;
F_17 ( V_187 ) ;
V_187 = NULL ;
if ( V_55 )
V_194 ++ ;
else {
if ( V_130 > 0 )
break;
else {
V_4 -> V_47 = * V_194 ;
F_8 ( V_186 ) ;
goto V_203;
}
}
}
F_25 ( V_2 -> V_13 ,
L_34 ) ;
V_201:
if ( V_188 )
F_8 ( V_188 ) ;
if ( V_187 )
F_8 ( V_187 ) ;
F_8 ( V_186 ) ;
return - V_16 ;
V_203:
return 0 ;
}
void F_89 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_4 ( V_2 -> V_13 ) -> V_3 ;
int V_204 , V_205 , V_206 ;
T_1 V_197 , V_207 , V_208 , V_89 ;
int V_9 , V_132 ;
V_204 = V_4 -> V_28 + 1 ;
V_205 = V_4 -> V_24 - V_204 ;
V_197 = V_4 -> V_18 & ( V_4 -> V_45 - 1 ) ;
V_208 = ( V_205 && V_197 ) ?
( ( V_205 - 1 ) << V_4 -> V_40 ) + V_197
: V_205 << V_4 -> V_40 ;
V_207 = V_4 -> V_20 - V_208 ;
V_89 = ( T_2 ) V_207 / ( T_2 ) V_204 ;
if ( V_4 -> V_43 [ V_4 -> V_30 ] < V_89 ) {
for ( V_4 -> V_30 = 0 ; V_4 -> V_30 < V_204 ;
V_4 -> V_30 ++ ) {
if ( V_4 -> V_43 [ V_4 -> V_30 ] >= V_89 )
break;
}
if ( V_4 -> V_30 >= V_4 -> V_24 ) {
F_25 ( V_2 -> V_13 ,
L_35 ) ;
}
}
V_4 -> V_32 = F_82 ( V_4 -> V_45 ) ;
V_206 =
V_4 -> V_40 - ( V_143 + V_4 -> V_32 * V_136 ) ;
V_4 -> V_34 = V_206 >> 1 ;
V_4 -> V_36 = 1 << ( V_206 - ( V_4 -> V_34 << 1 ) ) ;
for ( V_9 = 5 - V_4 -> V_34 , V_4 -> V_38 = 0 , V_132 = 1 ; V_9 > 0 ;
V_9 -- ) {
V_4 -> V_38 += V_132 ;
V_132 <<= 2 ;
}
}
static int F_87 ( struct V_56 * V_57 , T_1 V_209 , int V_55 )
{
int V_54 , V_163 , V_141 , V_210 , V_114 , V_58 , V_9 ;
V_54 = V_209 & ( V_64 - 1 ) ;
if ( V_54 == 0 ) {
V_57 -> V_55 = V_57 -> V_150 = F_16 ( V_55 ) ;
V_57 -> V_126 = F_15 ( V_209 ) ;
if ( V_55 == V_64 ) {
memset ( & V_57 -> V_122 [ 0 ] , 0 , V_125 * 4 ) ;
memset ( & V_57 -> V_85 [ 0 ] , 0 , V_125 * 4 ) ;
goto V_211;
}
} else {
F_68 ( & V_57 -> V_55 , V_55 ) ;
F_68 ( & V_57 -> V_150 , V_55 ) ;
}
V_163 = V_54 >> V_82 ;
for ( V_210 = V_55 ; V_210 > 0 ; V_210 -= V_58 , V_54 += V_58 ) {
V_141 = V_54 & ( V_83 - 1 ) ;
V_58 = F_27 ( V_210 , V_83 - V_141 ) ;
if ( V_58 < V_83 ) {
V_57 -> V_122 [ V_163 ] &= F_16 ( ~ ( V_84 << ( V_83 - V_58 )
>> V_141 ) ) ;
V_57 -> V_85 [ V_163 ] &= F_16 ( ~ ( V_84 << ( V_83 - V_58 )
>> V_141 ) ) ;
V_163 ++ ;
} else {
V_114 = V_210 >> V_82 ;
memset ( & V_57 -> V_122 [ V_163 ] , 0 , V_114 * 4 ) ;
memset ( & V_57 -> V_85 [ V_163 ] , 0 , V_114 * 4 ) ;
V_58 = V_114 << V_82 ;
V_163 += V_114 ;
}
}
if ( V_54 == V_64 )
goto V_211;
V_163 = V_54 >> V_82 ;
V_141 = V_54 & ( V_83 - 1 ) ;
if ( V_141 ) {
V_57 -> V_122 [ V_163 ] = V_57 -> V_85 [ V_163 ] = F_16 ( V_84 >> V_141 ) ;
V_163 ++ ;
}
for ( V_9 = V_163 ; V_9 < V_125 ; V_9 ++ )
V_57 -> V_85 [ V_9 ] = V_57 -> V_122 [ V_9 ] = F_16 ( V_84 ) ;
V_211:
return ( F_79 ( V_57 ) ) ;
}
static int F_79 ( struct V_56 * V_57 )
{
struct V_181 * V_147 ;
T_4 * V_174 ;
int V_9 ;
V_147 = & V_57 -> V_117 ;
V_147 -> V_212 = F_16 ( V_125 ) ;
V_147 -> V_213 = F_16 ( V_151 ) ;
V_147 -> V_118 = F_16 ( V_119 ) ;
V_147 -> V_214 = F_16 ( 4 ) ;
V_147 -> V_134 = V_123 ;
V_174 = V_147 -> V_120 + F_7 ( V_147 -> V_118 ) ;
for ( V_9 = 0 ; V_9 < V_125 ; V_9 ++ )
* V_174 ++ = F_67 ( ( V_149 * ) & V_57 -> V_122 [ V_9 ] ) ;
return ( F_90 ( V_147 ) ) ;
}
static int F_90 ( struct V_181 * V_215 )
{
int V_216 , V_217 , V_218 , V_219 , V_9 ;
int V_220 , V_221 , V_222 ;
T_4 * V_147 , * V_174 , * V_223 ;
V_147 = V_215 -> V_120 ;
V_216 = F_7 ( V_215 -> V_213 ) + V_215 -> V_134 ;
for ( V_217 = V_215 -> V_134 , V_218 = 1 ; V_217 < V_216 ;
V_217 ++ , V_218 = V_219 ) {
V_219 = V_218 << 1 ;
for ( V_9 = 0 , V_174 = V_147 + F_7 ( V_215 -> V_118 ) ;
V_9 < F_7 ( V_215 -> V_212 ) ;
V_9 += V_219 , V_174 += V_219 ) {
if ( * V_174 == V_217 && * ( V_174 + V_218 ) == V_217 ) {
* V_174 = V_217 + 1 ;
* ( V_174 + V_218 ) = - 1 ;
}
}
}
for ( V_220 = F_7 ( V_215 -> V_118 ) ,
V_222 = F_7 ( V_215 -> V_212 ) >> 2 ;
V_222 > 0 ; V_222 >>= 2 , V_220 = V_221 ) {
V_221 = ( V_220 - 1 ) >> 2 ;
for ( V_9 = 0 , V_174 = V_147 + V_220 , V_223 = V_147 + V_221 ;
V_9 < V_222 ; V_9 ++ , V_174 += 4 , V_223 ++ )
* V_223 = F_73 ( V_174 ) ;
}
return ( * V_147 ) ;
}
static int F_88 ( struct V_127 * V_128 , int V_139 , int V_9 )
{
T_4 * V_174 ;
V_128 -> V_212 = F_16 ( V_200 ) ;
V_128 -> V_213 = F_16 ( V_136 ) ;
V_128 -> V_118 = F_16 ( V_135 ) ;
V_128 -> V_214 = F_16 ( 5 ) ;
V_128 -> V_134 = V_143 + V_136 * V_139 ;
V_174 = & V_128 -> V_120 [ V_135 + V_9 ] ;
for (; V_9 < V_200 ; V_9 ++ )
* V_174 ++ = V_121 ;
return ( F_90 ( (struct V_181 * ) V_128 ) ) ;
}
static int F_83 ( T_1 V_55 )
{
T_1 V_224 ;
T_1 V_131 ;
int V_225 ;
if ( V_55 < V_64 * V_42 )
return ( V_143 ) ;
V_131 = ( ( V_226 ) 1 << ( 64 - 1 ) ) ;
for ( V_225 = 64 ; V_225 >= 0 ; V_225 -- , V_131 >>= 1 ) {
if ( V_131 & V_55 )
break;
}
V_224 = ( T_1 ) 1 << V_225 ;
if ( V_224 < V_55 )
V_225 += 1 ;
return ( V_225 - V_227 ) ;
}
T_1 F_91 ( struct V_1 * V_2 )
{
struct V_228 * V_81 = V_2 -> V_13 ;
T_1 V_55 ;
T_1 V_229 , V_230 ;
int V_139 , V_9 ;
int V_231 , V_232 ;
V_55 = V_2 -> V_233 >> F_4 ( V_81 ) -> V_234 ;
V_229 = V_55 >> F_4 ( V_81 ) -> V_14 ;
V_139 = F_92 ( V_229 ) ;
V_230 = 0 ;
V_229 -- ;
V_229 -= ( 2 - V_139 ) ;
V_229 -- ;
for ( V_9 = V_139 ; V_9 >= 0 ; V_9 -- ) {
V_232 =
( V_9 == 2 ) ? V_235 : ( ( V_9 == 1 ) ? V_236 : 1 ) ;
V_231 = ( T_2 ) V_229 / V_232 ;
V_230 += V_231 * ( ( V_9 == 2 ) ? V_200 * V_200 :
( ( V_9 == 1 ) ? V_200 : 1 ) ) ;
V_229 = ( T_2 ) V_229 % V_232 ;
V_229 -- ;
}
V_55 = V_230 << V_143 ;
return ( V_55 ) ;
}
