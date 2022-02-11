int F_1 ( struct V_1 * V_2 , int V_3 , T_1 * V_4 )
{
int V_5 ;
struct V_6 V_7 ;
T_1 * V_8 ;
if ( V_3 >= V_9 )
return - V_10 ;
V_7 . V_11 . V_12 = V_13 ;
V_7 . V_14 . V_15 . V_16 = F_2 ( 1 ) ;
V_7 . V_14 . V_15 . V_17 = F_3 ( V_18 ) ;
V_7 . V_14 . V_15 . V_19 = V_20 ;
memset ( V_7 . V_14 . V_15 . V_21 , 0 ,
sizeof( V_7 . V_14 . V_15 . V_21 ) ) ;
V_7 . V_14 . V_15 . V_21 [ V_3 >> 3 ] = 1 << ( V_3 & 0x7 ) ;
V_5 = F_4 ( V_2 , & V_7 , sizeof( V_7 ) ,
L_1 ) ;
if ( V_5 == 0 ) {
V_8 = V_7 . V_14 . V_22 . V_23 ;
memcpy ( V_4 , V_8 , V_24 ) ;
}
return V_5 ;
}
int F_5 ( struct V_1 * V_2 , int V_3 , const T_1 * V_25 )
{
struct V_6 V_7 ;
int V_5 ;
V_7 . V_11 . V_12 = V_26 ;
V_7 . V_14 . V_27 . V_3 = F_2 ( V_3 ) ;
V_7 . V_14 . V_27 . V_28 =
F_2 ( sizeof( struct V_29 ) ) ;
V_7 . V_14 . V_27 . V_30 . V_31 =
F_2 ( V_32 ) ;
V_7 . V_14 . V_27 . V_30 . V_33 = 0 ;
V_7 . V_14 . V_27 . V_30 . V_34 = 0 ;
V_7 . V_14 . V_27 . V_30 . V_35 = 0 ;
V_7 . V_14 . V_27 . V_36 = F_2 ( 1 ) ;
V_7 . V_14 . V_27 . V_17 = F_3 ( V_18 ) ;
memcpy ( V_7 . V_14 . V_27 . V_23 , V_25 , V_24 ) ;
V_5 = F_4 ( V_2 , & V_7 , sizeof( V_7 ) ,
L_2 ) ;
return V_5 ;
}
int F_6 ( struct V_1 * V_2 , T_1 * V_37 , T_2 V_38 )
{
struct V_6 V_7 ;
T_3 V_39 ;
T_3 V_40 ;
int V_41 ;
int V_42 = 0 ;
int V_43 = 5 ;
T_1 * V_44 = V_37 ;
V_40 = F_7 ( T_3 , V_38 , sizeof( V_7 . V_14 . V_45 . V_46 ) ) ;
if ( ! V_37 || ! V_40 ||
V_38 > sizeof( V_7 . V_14 . V_45 . V_46 ) )
return - V_10 ;
do {
V_7 . V_11 . V_12 = V_47 ;
V_7 . V_14 . V_48 . V_49 = F_3 ( V_40 ) ;
V_41 = F_4 ( V_2 , & V_7 , sizeof( V_7 ) ,
L_3 ) ;
if ( V_41 )
break;
V_39 = F_7 ( T_3 , F_8 ( V_7 . V_14 . V_45 . V_49 ) ,
V_40 ) ;
memcpy ( V_44 , V_7 . V_14 . V_45 . V_46 , V_39 ) ;
V_44 += V_39 ;
V_42 += V_39 ;
V_40 -= V_39 ;
} while ( V_43 -- && V_42 < V_38 );
return V_42 ? V_42 : - V_50 ;
}
static void F_9 ( struct V_51 * V_8 , T_3 V_52 ,
const T_1 * V_53 , T_4 V_54 ,
T_1 V_34 ,
const T_1 * V_55 , T_4 V_56 )
{
F_10 ( V_8 , 9 + V_54 + V_56 ) ;
F_10 ( V_8 , V_52 ) ;
F_11 ( V_8 , V_54 ) ;
if ( V_53 && V_54 )
F_12 ( V_8 , V_53 , V_54 ) ;
F_13 ( V_8 , V_34 ) ;
F_11 ( V_8 , V_56 ) ;
if ( V_55 && V_56 )
F_12 ( V_8 , V_55 , V_56 ) ;
}
int F_14 ( struct V_1 * V_2 ,
struct V_57 * V_58 ,
struct V_59 * V_60 )
{
unsigned int V_61 ;
struct V_51 V_8 ;
T_3 V_25 ;
int V_62 ;
int V_5 ;
for ( V_62 = 0 ; V_62 < F_15 ( V_63 ) ; V_62 ++ ) {
if ( V_60 -> V_25 == V_63 [ V_62 ] . V_64 ) {
V_25 = V_63 [ V_62 ] . V_65 ;
break;
}
}
if ( V_62 == F_15 ( V_63 ) )
return - V_10 ;
V_5 = F_16 ( & V_8 , V_66 , V_67 ) ;
if ( V_5 )
return V_5 ;
F_10 ( & V_8 , V_60 -> V_68 ) ;
F_9 ( & V_8 , V_32 ,
NULL , 0 ,
0 ,
V_60 -> V_69 ,
V_24 ) ;
F_11 ( & V_8 , 4 + V_24 + V_58 -> V_70 + 1 ) ;
F_11 ( & V_8 , V_24 ) ;
F_12 ( & V_8 , V_60 -> V_71 , V_24 ) ;
F_11 ( & V_8 , V_58 -> V_70 + 1 ) ;
F_12 ( & V_8 , V_58 -> V_72 , V_58 -> V_70 ) ;
F_13 ( & V_8 , V_58 -> V_73 ) ;
if ( V_60 -> V_74 )
F_11 ( & V_8 , 14 + V_60 -> V_75 ) ;
else
F_11 ( & V_8 , 14 ) ;
F_11 ( & V_8 , V_76 ) ;
F_11 ( & V_8 , V_25 ) ;
if ( V_60 -> V_74 ) {
F_10 ( & V_8 , 0 ) ;
F_11 ( & V_8 , V_60 -> V_75 ) ;
F_12 ( & V_8 , V_60 -> V_74 ,
V_60 -> V_75 ) ;
} else {
F_10 ( & V_8 , V_77 ) ;
F_11 ( & V_8 , 0 ) ;
}
F_11 ( & V_8 , V_78 ) ;
F_11 ( & V_8 , 0 ) ;
F_11 ( & V_8 , 0 ) ;
F_10 ( & V_8 , 0 ) ;
if ( V_8 . V_79 & V_80 ) {
V_5 = - V_81 ;
goto V_37;
}
V_5 = F_4 ( V_2 , V_8 . V_82 , V_83 , L_4 ) ;
if ( V_5 )
goto V_37;
V_61 = F_17 ( ( V_84 * ) & V_8 . V_82 [ V_85 ] ) ;
if ( V_61 > V_86 ) {
V_5 = - V_81 ;
goto V_37;
}
memcpy ( V_58 -> V_87 , & V_8 . V_82 [ V_85 + 4 ] , V_61 ) ;
V_58 -> V_61 = V_61 ;
V_37:
F_18 ( & V_8 ) ;
if ( V_5 > 0 ) {
if ( ( V_5 & V_88 ) == V_88 )
V_5 = - V_10 ;
else
V_5 = - V_89 ;
}
return V_5 ;
}
static int F_19 ( struct V_1 * V_2 ,
struct V_57 * V_58 ,
struct V_59 * V_60 ,
T_3 * V_90 )
{
struct V_51 V_8 ;
unsigned int V_91 ;
unsigned int V_92 ;
unsigned int V_61 ;
int V_5 ;
V_91 = F_20 ( ( V_93 * ) & V_58 -> V_87 [ 0 ] ) ;
if ( V_91 > ( V_58 -> V_61 - 2 ) )
return - V_81 ;
V_92 = F_20 ( ( V_93 * ) & V_58 -> V_87 [ 2 + V_91 ] ) ;
V_61 = V_91 + V_92 + 4 ;
if ( V_61 > V_58 -> V_61 )
return - V_81 ;
V_5 = F_16 ( & V_8 , V_66 , V_94 ) ;
if ( V_5 )
return V_5 ;
F_10 ( & V_8 , V_60 -> V_68 ) ;
F_9 ( & V_8 , V_32 ,
NULL , 0 ,
0 ,
V_60 -> V_69 ,
V_24 ) ;
F_12 ( & V_8 , V_58 -> V_87 , V_61 ) ;
if ( V_8 . V_79 & V_80 ) {
V_5 = - V_81 ;
goto V_37;
}
V_5 = F_4 ( V_2 , V_8 . V_82 , V_83 , L_5 ) ;
if ( ! V_5 )
* V_90 = F_17 (
( V_84 * ) & V_8 . V_82 [ V_85 ] ) ;
V_37:
F_18 ( & V_8 ) ;
if ( V_5 > 0 )
V_5 = - V_89 ;
return V_5 ;
}
static void F_21 ( struct V_1 * V_2 , T_3 V_31 )
{
struct V_51 V_8 ;
int V_5 ;
V_5 = F_16 ( & V_8 , V_95 , V_96 ) ;
if ( V_5 ) {
F_22 ( V_2 -> V_97 , L_6 ,
V_31 ) ;
return;
}
F_10 ( & V_8 , V_31 ) ;
V_5 = F_4 ( V_2 , V_8 . V_82 , V_83 , L_7 ) ;
if ( V_5 )
F_22 ( V_2 -> V_97 , L_8 , V_31 ,
V_5 ) ;
F_18 ( & V_8 ) ;
}
static int F_23 ( struct V_1 * V_2 ,
struct V_57 * V_58 ,
struct V_59 * V_60 ,
T_3 V_90 )
{
struct V_51 V_8 ;
T_4 V_98 ;
T_1 * V_82 ;
int V_5 ;
V_5 = F_16 ( & V_8 , V_66 , V_99 ) ;
if ( V_5 )
return V_5 ;
F_10 ( & V_8 , V_90 ) ;
F_9 ( & V_8 ,
V_60 -> V_100 ?
V_60 -> V_100 : V_32 ,
NULL , 0 ,
0 ,
V_60 -> V_71 ,
V_24 ) ;
V_5 = F_4 ( V_2 , V_8 . V_82 , V_83 , L_9 ) ;
if ( V_5 > 0 )
V_5 = - V_89 ;
if ( ! V_5 ) {
V_98 = F_20 (
( V_93 * ) & V_8 . V_82 [ V_85 + 4 ] ) ;
V_82 = & V_8 . V_82 [ V_85 + 6 ] ;
memcpy ( V_58 -> V_72 , V_82 , V_98 - 1 ) ;
V_58 -> V_70 = V_98 - 1 ;
V_58 -> V_73 = V_82 [ V_98 - 1 ] ;
}
F_18 ( & V_8 ) ;
return V_5 ;
}
int F_24 ( struct V_1 * V_2 ,
struct V_57 * V_58 ,
struct V_59 * V_60 )
{
T_3 V_90 ;
int V_5 ;
V_5 = F_19 ( V_2 , V_58 , V_60 , & V_90 ) ;
if ( V_5 )
return V_5 ;
V_5 = F_23 ( V_2 , V_58 , V_60 , V_90 ) ;
F_21 ( V_2 , V_90 ) ;
return V_5 ;
}
T_5 F_25 ( struct V_1 * V_2 , T_3 V_101 , T_3 * V_102 ,
const char * V_103 )
{
struct V_6 V_7 ;
int V_5 ;
V_7 . V_11 . V_12 = V_104 ;
V_7 . V_14 . V_105 . V_106 = F_2 ( V_107 ) ;
V_7 . V_14 . V_105 . V_101 = F_2 ( V_101 ) ;
V_7 . V_14 . V_105 . V_108 = F_2 ( 1 ) ;
V_5 = F_4 ( V_2 , & V_7 , sizeof( V_7 ) , V_103 ) ;
if ( ! V_5 )
* V_102 = V_7 . V_14 . V_109 . V_102 ;
return V_5 ;
}
int F_26 ( struct V_1 * V_2 , T_4 V_110 )
{
struct V_6 V_7 ;
V_7 . V_11 . V_12 = V_111 ;
V_7 . V_14 . V_112 . V_110 = F_3 ( V_110 ) ;
return F_4 ( V_2 , & V_7 , sizeof( V_7 ) ,
L_10 ) ;
}
void F_27 ( struct V_1 * V_2 , T_4 V_113 )
{
struct V_6 V_7 ;
int V_5 ;
V_7 . V_11 . V_12 = V_114 ;
V_7 . V_14 . V_112 . V_110 = F_3 ( V_113 ) ;
V_5 = F_4 ( V_2 , & V_7 , sizeof( V_7 ) , L_11 ) ;
if ( V_5 < 0 )
F_22 ( V_2 -> V_97 , L_12 ,
V_5 ) ;
}
unsigned long F_28 ( struct V_1 * V_2 , T_3 V_115 )
{
int V_116 = V_117 ;
int V_118 = 0 ;
if ( V_115 >= V_119 && V_115 <= V_120 )
V_116 = V_121 [ V_115 - V_119 ] ;
if ( V_116 != V_117 )
V_118 = V_2 -> V_122 . V_118 [ V_116 ] ;
if ( V_118 <= 0 )
V_118 = 2 * 60 * V_123 ;
return V_118 ;
}
static int F_29 ( struct V_1 * V_2 , bool V_124 )
{
int V_5 ;
struct V_6 V_7 ;
V_7 . V_11 . V_12 = V_125 ;
V_7 . V_14 . V_126 . V_127 = V_124 ;
V_5 = F_4 ( V_2 , & V_7 , V_128 ,
L_13 ) ;
if ( V_5 == V_129 ) {
F_22 ( V_2 -> V_97 , L_14 ) ;
V_5 = 0 ;
}
return V_5 ;
}
int F_30 ( struct V_1 * V_2 )
{
int V_5 ;
unsigned int V_130 ;
unsigned int V_131 = 100 ;
unsigned long V_118 ;
struct V_6 V_7 ;
int V_62 ;
V_118 = F_28 ( V_2 , V_132 ) ;
V_130 = F_31 ( V_118 ) / V_131 ;
V_5 = F_29 ( V_2 , true ) ;
if ( V_5 )
return V_5 ;
for ( V_62 = 0 ; V_62 < V_130 ; V_62 ++ ) {
V_7 . V_11 . V_12 = V_13 ;
V_7 . V_14 . V_15 . V_16 = F_2 ( 1 ) ;
V_7 . V_14 . V_15 . V_17 = F_3 ( V_18 ) ;
V_7 . V_14 . V_15 . V_19 = V_20 ;
V_7 . V_14 . V_15 . V_21 [ 0 ] = 0x01 ;
V_7 . V_14 . V_15 . V_21 [ 1 ] = 0x00 ;
V_7 . V_14 . V_15 . V_21 [ 2 ] = 0x00 ;
V_5 = F_4 ( V_2 , ( T_1 * ) & V_7 , sizeof( V_7 ) , NULL ) ;
if ( V_5 < 0 )
break;
V_5 = F_32 ( V_7 . V_11 . V_37 . V_133 ) ;
if ( V_5 != V_129 )
break;
F_33 ( V_131 ) ;
}
return V_5 ;
}
int F_34 ( struct V_1 * V_2 )
{
T_3 V_134 ;
return F_25 ( V_2 , 0x100 , & V_134 ,
L_15 ) ;
}
int F_35 ( struct V_1 * V_2 )
{
struct V_6 V_7 ;
int V_5 ;
V_7 . V_11 . V_12 = V_104 ;
V_7 . V_14 . V_105 . V_106 = F_2 ( V_107 ) ;
V_7 . V_14 . V_105 . V_101 = F_2 ( 0x100 ) ;
V_7 . V_14 . V_105 . V_108 = F_2 ( 1 ) ;
V_5 = F_36 ( V_2 , ( const char * ) & V_7 , sizeof( V_7 ) ) ;
if ( V_5 < 0 )
return V_5 ;
else if ( V_5 < V_85 )
return - V_135 ;
if ( F_8 ( V_7 . V_11 . V_37 . V_136 ) == V_95 )
V_2 -> V_79 |= V_137 ;
return 0 ;
}
