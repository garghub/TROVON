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
int V_5 ;
V_5 = F_15 ( & V_8 , V_62 , V_63 ) ;
if ( V_5 )
return V_5 ;
F_10 ( & V_8 , V_60 -> V_64 ) ;
F_9 ( & V_8 , V_32 ,
NULL , 0 ,
0 ,
V_60 -> V_65 ,
V_24 ) ;
F_11 ( & V_8 , 4 + V_24 + V_58 -> V_66 + 1 ) ;
F_11 ( & V_8 , V_24 ) ;
F_12 ( & V_8 , V_60 -> V_67 , V_24 ) ;
F_11 ( & V_8 , V_58 -> V_66 + 1 ) ;
F_12 ( & V_8 , V_58 -> V_68 , V_58 -> V_66 ) ;
F_13 ( & V_8 , V_58 -> V_69 ) ;
F_11 ( & V_8 , 14 ) ;
F_11 ( & V_8 , V_70 ) ;
F_11 ( & V_8 , V_71 ) ;
F_10 ( & V_8 , V_72 ) ;
F_11 ( & V_8 , 0 ) ;
F_11 ( & V_8 , V_73 ) ;
F_11 ( & V_8 , 0 ) ;
F_11 ( & V_8 , 0 ) ;
F_10 ( & V_8 , 0 ) ;
if ( V_8 . V_74 & V_75 ) {
V_5 = - V_76 ;
goto V_37;
}
V_5 = F_4 ( V_2 , V_8 . V_77 , V_78 , L_4 ) ;
if ( V_5 )
goto V_37;
V_61 = F_16 ( ( V_79 * ) & V_8 . V_77 [ V_80 ] ) ;
if ( V_61 > V_81 ) {
V_5 = - V_76 ;
goto V_37;
}
memcpy ( V_58 -> V_82 , & V_8 . V_77 [ V_80 + 4 ] , V_61 ) ;
V_58 -> V_61 = V_61 ;
V_37:
F_17 ( & V_8 ) ;
if ( V_5 > 0 )
V_5 = - V_83 ;
return V_5 ;
}
static int F_18 ( struct V_1 * V_2 ,
struct V_57 * V_58 ,
struct V_59 * V_60 ,
T_3 * V_84 )
{
struct V_51 V_8 ;
unsigned int V_85 ;
unsigned int V_86 ;
unsigned int V_61 ;
int V_5 ;
V_85 = F_19 ( ( V_87 * ) & V_58 -> V_82 [ 0 ] ) ;
if ( V_85 > ( V_58 -> V_61 - 2 ) )
return - V_76 ;
V_86 = F_19 ( ( V_87 * ) & V_58 -> V_82 [ 2 + V_85 ] ) ;
V_61 = V_85 + V_86 + 4 ;
if ( V_61 > V_58 -> V_61 )
return - V_76 ;
V_5 = F_15 ( & V_8 , V_62 , V_88 ) ;
if ( V_5 )
return V_5 ;
F_10 ( & V_8 , V_60 -> V_64 ) ;
F_9 ( & V_8 , V_32 ,
NULL , 0 ,
0 ,
V_60 -> V_65 ,
V_24 ) ;
F_12 ( & V_8 , V_58 -> V_82 , V_61 ) ;
if ( V_8 . V_74 & V_75 ) {
V_5 = - V_76 ;
goto V_37;
}
V_5 = F_4 ( V_2 , V_8 . V_77 , V_78 , L_5 ) ;
if ( ! V_5 )
* V_84 = F_16 (
( V_79 * ) & V_8 . V_77 [ V_80 ] ) ;
V_37:
F_17 ( & V_8 ) ;
if ( V_5 > 0 )
V_5 = - V_83 ;
return V_5 ;
}
static void F_20 ( struct V_1 * V_2 , T_3 V_31 )
{
struct V_51 V_8 ;
int V_5 ;
V_5 = F_15 ( & V_8 , V_89 , V_90 ) ;
if ( V_5 ) {
F_21 ( V_2 -> V_91 , L_6 ,
V_31 ) ;
return;
}
F_10 ( & V_8 , V_31 ) ;
V_5 = F_4 ( V_2 , V_8 . V_77 , V_78 , L_7 ) ;
if ( V_5 )
F_21 ( V_2 -> V_91 , L_8 , V_31 ,
V_5 ) ;
F_17 ( & V_8 ) ;
}
static int F_22 ( struct V_1 * V_2 ,
struct V_57 * V_58 ,
struct V_59 * V_60 ,
T_3 V_84 )
{
struct V_51 V_8 ;
T_4 V_92 ;
T_1 * V_77 ;
int V_5 ;
V_5 = F_15 ( & V_8 , V_62 , V_93 ) ;
if ( V_5 )
return V_5 ;
F_10 ( & V_8 , V_84 ) ;
F_9 ( & V_8 , V_32 ,
NULL , 0 ,
0 ,
V_60 -> V_67 ,
V_24 ) ;
V_5 = F_4 ( V_2 , V_8 . V_77 , V_78 , L_9 ) ;
if ( V_5 > 0 )
V_5 = - V_83 ;
if ( ! V_5 ) {
V_92 = F_19 (
( V_87 * ) & V_8 . V_77 [ V_80 + 4 ] ) ;
V_77 = & V_8 . V_77 [ V_80 + 6 ] ;
memcpy ( V_58 -> V_68 , V_77 , V_92 - 1 ) ;
V_58 -> V_66 = V_92 - 1 ;
V_58 -> V_69 = V_77 [ V_92 - 1 ] ;
}
F_17 ( & V_8 ) ;
return V_5 ;
}
int F_23 ( struct V_1 * V_2 ,
struct V_57 * V_58 ,
struct V_59 * V_60 )
{
T_3 V_84 ;
int V_5 ;
V_5 = F_18 ( V_2 , V_58 , V_60 , & V_84 ) ;
if ( V_5 )
return V_5 ;
V_5 = F_22 ( V_2 , V_58 , V_60 , V_84 ) ;
F_20 ( V_2 , V_84 ) ;
return V_5 ;
}
T_5 F_24 ( struct V_1 * V_2 , T_3 V_94 , T_3 * V_95 ,
const char * V_96 )
{
struct V_6 V_7 ;
int V_5 ;
V_7 . V_11 . V_12 = V_97 ;
V_7 . V_14 . V_98 . V_99 = F_2 ( V_100 ) ;
V_7 . V_14 . V_98 . V_94 = F_2 ( V_94 ) ;
V_7 . V_14 . V_98 . V_101 = F_2 ( 1 ) ;
V_5 = F_4 ( V_2 , & V_7 , sizeof( V_7 ) , V_96 ) ;
if ( ! V_5 )
* V_95 = V_7 . V_14 . V_102 . V_95 ;
return V_5 ;
}
int F_25 ( struct V_1 * V_2 , T_4 V_103 )
{
struct V_6 V_7 ;
V_7 . V_11 . V_12 = V_104 ;
V_7 . V_14 . V_105 . V_103 = F_3 ( V_103 ) ;
return F_4 ( V_2 , & V_7 , sizeof( V_7 ) ,
L_10 ) ;
}
void F_26 ( struct V_1 * V_2 , T_4 V_106 )
{
struct V_6 V_7 ;
int V_5 ;
V_7 . V_11 . V_12 = V_107 ;
V_7 . V_14 . V_105 . V_103 = F_3 ( V_106 ) ;
V_5 = F_4 ( V_2 , & V_7 , sizeof( V_7 ) , L_11 ) ;
if ( V_5 < 0 )
F_21 ( V_2 -> V_91 , L_12 ,
V_5 ) ;
}
unsigned long F_27 ( struct V_1 * V_2 , T_3 V_108 )
{
int V_109 = V_110 ;
int V_111 = 0 ;
if ( V_108 >= V_112 && V_108 <= V_113 )
V_109 = V_114 [ V_108 - V_112 ] ;
if ( V_109 != V_110 )
V_111 = V_2 -> V_115 . V_111 [ V_109 ] ;
if ( V_111 <= 0 )
V_111 = 2 * 60 * V_116 ;
return V_111 ;
}
static int F_28 ( struct V_1 * V_2 , bool V_117 )
{
int V_5 ;
struct V_6 V_7 ;
V_7 . V_11 . V_12 = V_118 ;
V_7 . V_14 . V_119 . V_120 = V_117 ;
V_5 = F_4 ( V_2 , & V_7 , V_121 ,
L_13 ) ;
if ( V_5 == V_122 ) {
F_21 ( V_2 -> V_91 , L_14 ) ;
V_5 = 0 ;
}
return V_5 ;
}
int F_29 ( struct V_1 * V_2 )
{
int V_5 ;
unsigned int V_123 ;
unsigned int V_124 = 100 ;
unsigned long V_111 ;
struct V_6 V_7 ;
int V_125 ;
V_111 = F_27 ( V_2 , V_126 ) ;
V_123 = F_30 ( V_111 ) / V_124 ;
V_5 = F_28 ( V_2 , true ) ;
if ( V_5 )
return V_5 ;
for ( V_125 = 0 ; V_125 < V_123 ; V_125 ++ ) {
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
V_5 = F_31 ( V_7 . V_11 . V_37 . V_127 ) ;
if ( V_5 != V_122 )
break;
F_32 ( V_124 ) ;
}
return V_5 ;
}
int F_33 ( struct V_1 * V_2 )
{
T_3 V_128 ;
return F_24 ( V_2 , 0x100 , & V_128 ,
L_15 ) ;
}
int F_34 ( struct V_1 * V_2 )
{
struct V_6 V_7 ;
int V_5 ;
V_7 . V_11 . V_12 = V_97 ;
V_7 . V_14 . V_98 . V_99 = F_2 ( V_100 ) ;
V_7 . V_14 . V_98 . V_94 = F_2 ( 0x100 ) ;
V_7 . V_14 . V_98 . V_101 = F_2 ( 1 ) ;
V_5 = F_35 ( V_2 , ( const char * ) & V_7 , sizeof( V_7 ) ) ;
if ( V_5 < 0 )
return V_5 ;
else if ( V_5 < V_80 )
return - V_129 ;
if ( F_8 ( V_7 . V_11 . V_37 . V_130 ) == V_89 )
V_2 -> V_74 |= V_131 ;
return 0 ;
}
