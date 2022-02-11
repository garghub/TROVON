static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = & V_6 -> V_8 ;
V_4 -> V_9 = ( V_10 |
V_11 |
V_12 |
V_13 |
V_14 |
V_15 ) ;
if ( V_8 -> V_16 & V_17 )
V_4 -> V_9 |= V_18 ;
V_4 -> V_19 = V_20 ;
V_4 -> V_19 |= V_8 -> V_21 ;
V_4 -> V_22 = V_23 ;
V_4 -> V_24 = 0 ;
V_4 -> V_25 = V_26 ;
if ( V_6 -> V_27 != V_28 ) {
F_3 ( V_4 , V_6 -> V_27 ) ;
if ( V_6 -> V_29 == V_30 )
V_4 -> V_31 = V_32 ;
else
V_4 -> V_31 = V_33 ;
} else {
F_3 ( V_4 , - 1 ) ;
V_4 -> V_31 = - 1 ;
}
V_4 -> V_34 = V_35 ;
return 0 ;
}
static int F_4 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = & V_6 -> V_8 ;
T_1 V_21 ;
while ( F_5 ( V_36 , & V_6 -> V_37 ) )
F_6 ( 1 ) ;
if ( V_4 -> V_34 == V_35 ) {
V_21 = V_38 ;
} else {
T_2 V_39 = F_7 ( V_4 ) ;
if ( V_39 == V_40 ) {
if ( V_4 -> V_31 != V_32 ) {
if ( F_8 ( V_6 ) )
F_9 ( & V_6 -> V_41 -> V_42 ,
L_1 ) ;
F_10 ( V_36 , & V_6 -> V_37 ) ;
return - V_43 ;
}
V_21 = V_44 ;
} else if ( V_39 == V_45 ) {
if ( V_4 -> V_31 == V_32 )
V_21 = V_46 ;
else
V_21 = V_47 ;
} else {
if ( V_4 -> V_31 == V_32 )
V_21 = V_48 ;
else
V_21 = V_49 ;
}
}
if ( V_8 -> V_21 != V_21 ) {
V_8 -> V_21 = V_21 ;
if ( F_11 ( V_8 ) != 0 ) {
if ( F_8 ( V_6 ) )
F_9 ( & V_6 -> V_41 -> V_42 ,
L_2 ) ;
F_10 ( V_36 , & V_6 -> V_37 ) ;
return - V_43 ;
}
}
F_10 ( V_36 , & V_6 -> V_37 ) ;
return 0 ;
}
static T_2 F_12 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
return V_6 -> V_50 ;
}
static void F_13 ( struct V_1 * V_2 , T_2 V_51 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
V_6 -> V_50 = V_51 ;
}
static int F_14 ( struct V_1 * V_2 )
{
return V_52 ;
}
static void F_15 ( struct V_1 * V_2 ,
struct V_53 * V_54 , void * V_55 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = & V_6 -> V_8 ;
T_2 * V_56 = V_55 ;
T_1 V_57 ;
memset ( V_55 , 0 , V_52 ) ;
V_54 -> V_58 = 1 ;
F_16 ( V_8 , V_59 , V_55 ++ ) ;
F_16 ( V_8 , V_60 , V_55 ++ ) ;
F_16 ( V_8 , V_61 , V_55 ++ ) ;
F_16 ( V_8 , V_62 , V_55 ++ ) ;
F_16 ( V_8 , V_63 , V_55 ++ ) ;
F_16 ( V_8 , V_64 , V_55 ++ ) ;
F_16 ( V_8 , V_65 , V_55 ++ ) ;
F_16 ( V_8 , V_66 , V_55 ++ ) ;
F_16 ( V_8 , V_67 , V_55 ++ ) ;
F_16 ( V_8 , V_68 , V_55 ++ ) ;
F_16 ( V_8 , V_69 , V_55 ++ ) ;
F_16 ( V_8 , V_70 , V_55 ++ ) ;
F_16 ( V_8 , V_71 , V_55 ++ ) ;
F_16 ( V_8 , V_72 , V_55 ++ ) ;
F_16 ( V_8 , V_73 , V_55 ++ ) ;
F_16 ( V_8 , V_73 + 4 , V_55 ++ ) ;
F_16 ( V_8 , V_74 , V_55 ++ ) ;
F_16 ( V_8 , V_74 + 4 , V_55 ++ ) ;
F_16 ( V_8 , V_75 , V_55 ++ ) ;
F_16 ( V_8 , V_76 , V_55 ++ ) ;
F_16 ( V_8 , V_77 , V_55 ++ ) ;
F_16 ( V_8 , V_78 , V_55 ++ ) ;
F_17 ( V_8 , V_79 , & V_57 ) ;
V_56 [ V_52 / sizeof( T_2 ) - 2 ] = ( T_2 ) V_57 ;
F_17 ( V_8 , V_80 , & V_57 ) ;
V_56 [ V_52 / sizeof( T_2 ) - 1 ] = ( T_2 ) V_57 ;
}
static int F_18 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
if ( F_19 ( & V_6 -> V_8 ) )
return V_81 ;
else
return 0 ;
}
static int F_20 ( struct V_1 * V_2 ,
struct V_82 * V_83 , T_3 * V_84 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = & V_6 -> V_8 ;
T_2 * V_85 ;
int V_86 , V_87 ;
int V_88 = 0 ;
int V_89 ;
if ( V_83 -> V_90 == 0 )
return - V_43 ;
if ( ! F_19 ( V_8 ) )
return - V_43 ;
V_83 -> V_91 = V_6 -> V_41 -> V_92 |
( V_6 -> V_41 -> V_93 << 16 ) ;
V_86 = V_83 -> V_94 >> 2 ;
V_87 = ( V_83 -> V_94 + V_83 -> V_90 - 1 ) >> 2 ;
V_85 = F_21 ( sizeof( T_2 ) *
( V_87 - V_86 + 1 ) , V_95 ) ;
if ( V_85 == NULL )
return - V_96 ;
for ( V_89 = V_86 ; V_89 < V_87 ; V_89 ++ ) {
if ( ! F_22 ( V_8 , V_89 * 4 , & ( V_85 [ V_89 - V_86 ] ) ) ) {
F_23 ( V_85 ) ;
return - V_97 ;
}
}
memcpy ( V_84 , ( T_3 * ) V_85 + ( V_83 -> V_94 & 3 ) ,
V_83 -> V_90 ) ;
F_23 ( V_85 ) ;
return V_88 ;
return 0 ;
}
static void F_24 ( struct V_1 * V_2 ,
struct V_98 * V_99 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
F_25 ( V_99 -> V_100 , V_101 , sizeof( V_99 -> V_100 ) ) ;
F_25 ( V_99 -> V_58 , V_102 ,
sizeof( V_99 -> V_58 ) ) ;
F_25 ( V_99 -> V_103 , F_26 ( V_6 -> V_41 ) ,
sizeof( V_99 -> V_103 ) ) ;
V_99 -> V_104 = 0 ;
V_99 -> V_105 = 0 ;
V_99 -> V_106 = F_14 ( V_2 ) ;
V_99 -> V_107 = F_18 ( V_2 ) ;
}
static void F_27 ( struct V_1 * V_2 ,
struct V_108 * V_109 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
V_109 -> V_9 = V_110 | V_111 ;
V_109 -> V_112 = 0 ;
if ( V_6 -> V_109 & V_113 )
V_109 -> V_112 |= V_114 ;
if ( V_6 -> V_109 & V_115 )
V_109 -> V_112 |= V_116 ;
if ( V_6 -> V_109 & V_117 )
V_109 -> V_112 |= V_118 ;
if ( V_6 -> V_109 & V_119 )
V_109 -> V_112 |= V_110 ;
if ( V_6 -> V_109 & V_120 )
V_109 -> V_112 |= V_111 ;
}
static int F_28 ( struct V_1 * V_2 , struct V_108 * V_109 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
if ( V_109 -> V_112 & ( V_121 | V_122 |
V_114 | V_118 | V_116 ) )
return - V_123 ;
V_6 -> V_109 = 0 ;
if ( V_109 -> V_112 & V_110 )
V_6 -> V_109 |= V_119 ;
if ( V_109 -> V_112 & V_111 )
V_6 -> V_109 |= V_120 ;
F_29 ( & V_6 -> V_41 -> V_42 , V_6 -> V_109 ) ;
return 0 ;
}
static int F_30 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
if ( F_31 ( V_2 ) )
F_32 ( V_6 ) ;
return 0 ;
}
void F_33 ( struct V_1 * V_2 )
{
F_34 ( V_2 , & V_124 ) ;
}
