static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = & V_6 -> V_8 ;
T_1 V_9 , V_10 ;
V_9 = ( V_11 |
V_12 |
V_13 |
V_14 |
V_15 |
V_16 ) ;
if ( V_8 -> V_17 & V_18 )
V_9 |= V_19 ;
V_10 = V_20 ;
V_10 |= V_8 -> V_21 ;
V_4 -> V_22 . V_23 = V_24 ;
V_4 -> V_22 . V_25 = 0 ;
if ( V_6 -> V_26 != V_27 ) {
V_4 -> V_22 . V_28 = V_6 -> V_26 ;
if ( V_6 -> V_29 == V_30 )
V_4 -> V_22 . V_31 = V_32 ;
else
V_4 -> V_22 . V_31 = V_33 ;
} else {
V_4 -> V_22 . V_28 = V_34 ;
V_4 -> V_22 . V_31 = V_35 ;
}
V_4 -> V_22 . V_36 = V_37 ;
F_3 ( V_4 -> V_38 . V_9 ,
V_9 ) ;
F_3 ( V_4 -> V_38 . V_10 ,
V_10 ) ;
return 0 ;
}
static int F_4 ( struct V_1 * V_2 ,
const struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = & V_6 -> V_8 ;
T_2 V_21 ;
while ( F_5 ( V_39 , & V_6 -> V_40 ) )
F_6 ( 1 ) ;
if ( V_4 -> V_22 . V_36 == V_37 ) {
V_21 = V_41 ;
} else {
T_1 V_28 = V_4 -> V_22 . V_28 ;
if ( V_28 == V_42 ) {
if ( V_4 -> V_22 . V_31 != V_32 ) {
if ( F_7 ( V_6 ) )
F_8 ( & V_6 -> V_43 -> V_44 ,
L_1 ) ;
F_9 ( V_39 , & V_6 -> V_40 ) ;
return - V_45 ;
}
V_21 = V_46 ;
} else if ( V_28 == V_47 ) {
if ( V_4 -> V_22 . V_31 == V_32 )
V_21 = V_48 ;
else
V_21 = V_49 ;
} else {
if ( V_4 -> V_22 . V_31 == V_32 )
V_21 = V_50 ;
else
V_21 = V_51 ;
}
}
if ( V_8 -> V_21 != V_21 ) {
V_8 -> V_21 = V_21 ;
if ( F_10 ( V_8 ) != 0 ) {
if ( F_7 ( V_6 ) )
F_8 ( & V_6 -> V_43 -> V_44 ,
L_2 ) ;
F_9 ( V_39 , & V_6 -> V_40 ) ;
return - V_45 ;
}
}
F_9 ( V_39 , & V_6 -> V_40 ) ;
return 0 ;
}
static T_1 F_11 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
return V_6 -> V_52 ;
}
static void F_12 ( struct V_1 * V_2 , T_1 V_53 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
V_6 -> V_52 = V_53 ;
}
static int F_13 ( struct V_1 * V_2 )
{
return V_54 ;
}
static void F_14 ( struct V_1 * V_2 ,
struct V_55 * V_56 , void * V_57 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = & V_6 -> V_8 ;
T_1 * V_58 = V_57 ;
T_2 V_59 ;
memset ( V_57 , 0 , V_54 ) ;
V_56 -> V_60 = 1 ;
F_15 ( V_8 , V_61 , V_57 ++ ) ;
F_15 ( V_8 , V_62 , V_57 ++ ) ;
F_15 ( V_8 , V_63 , V_57 ++ ) ;
F_15 ( V_8 , V_64 , V_57 ++ ) ;
F_15 ( V_8 , V_65 , V_57 ++ ) ;
F_15 ( V_8 , V_66 , V_57 ++ ) ;
F_15 ( V_8 , V_67 , V_57 ++ ) ;
F_15 ( V_8 , V_68 , V_57 ++ ) ;
F_15 ( V_8 , V_69 , V_57 ++ ) ;
F_15 ( V_8 , V_70 , V_57 ++ ) ;
F_15 ( V_8 , V_71 , V_57 ++ ) ;
F_15 ( V_8 , V_72 , V_57 ++ ) ;
F_15 ( V_8 , V_73 , V_57 ++ ) ;
F_15 ( V_8 , V_74 , V_57 ++ ) ;
F_15 ( V_8 , V_75 , V_57 ++ ) ;
F_15 ( V_8 , V_75 + 4 , V_57 ++ ) ;
F_15 ( V_8 , V_76 , V_57 ++ ) ;
F_15 ( V_8 , V_76 + 4 , V_57 ++ ) ;
F_15 ( V_8 , V_77 , V_57 ++ ) ;
F_15 ( V_8 , V_78 , V_57 ++ ) ;
F_15 ( V_8 , V_79 , V_57 ++ ) ;
F_15 ( V_8 , V_80 , V_57 ++ ) ;
F_16 ( V_8 , V_81 , & V_59 ) ;
V_58 [ V_54 / sizeof( T_1 ) - 2 ] = ( T_1 ) V_59 ;
F_16 ( V_8 , V_82 , & V_59 ) ;
V_58 [ V_54 / sizeof( T_1 ) - 1 ] = ( T_1 ) V_59 ;
}
static int F_17 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
if ( F_18 ( & V_6 -> V_8 ) )
return V_83 ;
else
return 0 ;
}
static int F_19 ( struct V_1 * V_2 ,
struct V_84 * V_85 , T_3 * V_86 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = & V_6 -> V_8 ;
T_1 * V_87 ;
int V_88 , V_89 ;
int V_90 = 0 ;
int V_91 ;
if ( V_85 -> V_92 == 0 )
return - V_45 ;
if ( ! F_18 ( V_8 ) )
return - V_45 ;
V_85 -> V_93 = V_6 -> V_43 -> V_94 |
( V_6 -> V_43 -> V_95 << 16 ) ;
V_88 = V_85 -> V_96 >> 2 ;
V_89 = ( V_85 -> V_96 + V_85 -> V_92 - 1 ) >> 2 ;
V_87 = F_20 ( sizeof( T_1 ) *
( V_89 - V_88 + 1 ) , V_97 ) ;
if ( V_87 == NULL )
return - V_98 ;
for ( V_91 = V_88 ; V_91 < V_89 ; V_91 ++ ) {
if ( ! F_21 ( V_8 , V_91 * 4 , & ( V_87 [ V_91 - V_88 ] ) ) ) {
F_22 ( V_87 ) ;
return - V_99 ;
}
}
memcpy ( V_86 , ( T_3 * ) V_87 + ( V_85 -> V_96 & 3 ) ,
V_85 -> V_92 ) ;
F_22 ( V_87 ) ;
return V_90 ;
return 0 ;
}
static void F_23 ( struct V_1 * V_2 ,
struct V_100 * V_101 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
F_24 ( V_101 -> V_102 , V_103 , sizeof( V_101 -> V_102 ) ) ;
F_24 ( V_101 -> V_60 , V_104 ,
sizeof( V_101 -> V_60 ) ) ;
F_24 ( V_101 -> V_105 , F_25 ( V_6 -> V_43 ) ,
sizeof( V_101 -> V_105 ) ) ;
}
static void F_26 ( struct V_1 * V_2 ,
struct V_106 * V_107 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
V_107 -> V_9 = V_108 | V_109 ;
V_107 -> V_110 = 0 ;
if ( V_6 -> V_107 & V_111 )
V_107 -> V_110 |= V_112 ;
if ( V_6 -> V_107 & V_113 )
V_107 -> V_110 |= V_114 ;
if ( V_6 -> V_107 & V_115 )
V_107 -> V_110 |= V_116 ;
if ( V_6 -> V_107 & V_117 )
V_107 -> V_110 |= V_108 ;
if ( V_6 -> V_107 & V_118 )
V_107 -> V_110 |= V_109 ;
}
static int F_27 ( struct V_1 * V_2 , struct V_106 * V_107 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
if ( V_107 -> V_110 & ( V_119 | V_120 |
V_112 | V_116 | V_114 ) )
return - V_121 ;
V_6 -> V_107 = 0 ;
if ( V_107 -> V_110 & V_108 )
V_6 -> V_107 |= V_117 ;
if ( V_107 -> V_110 & V_109 )
V_6 -> V_107 |= V_118 ;
F_28 ( & V_6 -> V_43 -> V_44 , V_6 -> V_107 ) ;
return 0 ;
}
static int F_29 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
if ( F_30 ( V_2 ) )
F_31 ( V_6 ) ;
return 0 ;
}
void F_32 ( struct V_1 * V_2 )
{
V_2 -> V_122 = & V_123 ;
}
