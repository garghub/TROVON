static void F_1 ( struct V_1 * V_2 )
{
}
static void F_2 ( struct V_1 * V_2 )
{
T_1 V_3 ;
V_3 = F_3 ( V_2 , V_4 ) ;
V_3 &= ( V_5 | ~ V_6 ) ;
F_4 ( V_2 , V_4 , V_3 ) ;
}
static void F_5 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = F_6 ( V_2 ) ;
struct V_9 * V_10 = & V_8 -> V_11 ;
struct V_12 * V_13 = & ( V_8 -> V_14 ) ;
T_1 V_15 , V_16 ;
F_7 ( V_13 , 0 , sizeof( * V_13 ) ) ;
V_13 -> V_2 = V_2 ;
F_8 ( V_13 , V_17 , V_18 ) ;
F_8 ( V_13 , V_19 , V_20 ) ;
V_16 = V_21 ;
V_15 = V_22 ;
F_8 ( V_13 , V_23 , V_16 ) ;
F_8 ( V_13 , V_24 , V_15 ) ;
F_8 ( V_13 , V_25 , F_9 ( V_8 -> V_26 ) ) ;
F_8 ( V_13 , V_27 , V_8 -> V_28 ) ;
F_8 ( V_13 , V_29 , V_2 -> V_30 . V_31 ) ;
if ( V_8 -> V_32 == V_33 )
F_10 ( V_13 , V_34 , V_35 ) ;
else if ( V_8 -> V_32 == V_36 )
F_10 ( V_13 , V_34 , V_37 ) ;
else if ( V_8 -> V_32 == V_38 )
F_10 ( V_13 , V_34 , V_39 ) ;
F_8 ( V_13 , V_40 , V_8 -> V_41 ) ;
V_10 -> V_42 = V_43 |
V_44 ;
F_10 ( V_13 , V_45 , V_10 -> V_42 ) ;
}
static void F_11 ( struct V_1 * V_2 )
{
struct V_46 * V_47 = & V_2 -> V_48 ;
struct V_49 * V_50 = & V_2 -> V_51 ;
struct V_52 * V_53 = & V_2 -> V_53 ;
struct V_7 * V_8 = F_6 ( V_2 ) ;
struct V_12 * V_13 = & ( V_8 -> V_14 ) ;
struct V_9 * V_10 = & V_8 -> V_11 ;
int V_54 ;
V_10 -> V_42 = V_55 |
V_56 |
V_57 |
V_58 |
V_59 |
V_60 |
V_61 |
V_62 |
V_43 |
V_44 ;
if ( V_8 -> V_63 )
V_10 -> V_42 |= V_64 ;
if ( V_2 -> V_30 . V_65 == 1 ) {
V_10 -> V_42 = V_43 |
V_44 ;
}
F_10 ( V_13 , V_45 , V_10 -> V_42 ) ;
F_12 ( V_13 , V_66 , & ( V_2 -> V_67 . V_68 ) ) ;
F_12 ( V_13 , V_69 , & ( V_2 -> V_70 . V_71 ) ) ;
F_12 ( V_13 , V_72 , & ( V_47 -> V_73 ) ) ;
F_12 ( V_13 , V_74 , & ( V_8 -> V_75 ) ) ;
F_12 ( V_13 , V_76 , & ( V_2 -> V_77 . V_78 ) ) ;
F_12 ( V_13 , V_79 , & ( V_8 -> V_80 ) ) ;
F_12 ( V_13 , V_81 , & ( V_8 -> V_82 ) ) ;
F_12 ( V_13 , V_83 , & ( V_2 -> V_84 ) ) ;
F_12 ( V_13 , V_85 , & ( V_2 -> V_30 . V_65 ) ) ;
F_12 ( V_13 , V_86 , & ( V_50 -> V_87 ) ) ;
F_12 ( V_13 , V_88 , & ( V_53 -> V_89 ) ) ;
F_8 ( V_13 , V_40 , V_8 -> V_41 ) ;
for ( V_54 = 0 ; V_54 < V_90 ; V_54 ++ )
F_13 ( V_13 , V_91 , V_54 , NULL ) ;
}
void F_14 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = F_6 ( V_2 ) ;
struct V_9 * V_10 = & V_8 -> V_11 ;
struct V_12 * V_13 = & ( V_8 -> V_14 ) ;
F_2 ( V_2 ) ;
V_10 -> V_92 = V_93 ;
V_10 -> V_94 = V_95 ;
F_11 ( V_2 ) ;
F_15 ( V_13 ) ;
V_2 -> V_96 = 0xFF ;
}
void F_16 ( struct V_1 * V_2 )
{
bool V_97 = false ;
bool V_98 = true ;
T_1 V_99 = false ;
struct V_7 * V_8 = F_6 ( V_2 ) ;
V_100 ;
V_99 = V_2 -> V_99 ;
if ( ! V_99 )
goto V_101;
V_97 = V_2 -> V_53 . V_102 ;
F_17 ( V_2 , V_103 , ( T_1 * ) ( & V_98 ) ) ;
if ( V_2 -> V_104 . V_105 )
V_98 = false ;
if ( V_99 && ( ( ! V_97 ) && V_98 ) ) {
F_1 ( V_2 ) ;
V_106 ;
}
if ( V_99 ) {
struct V_49 * V_50 = & V_2 -> V_51 ;
T_1 V_107 = false ;
if ( ( F_18 ( V_50 , V_108 ) ) ||
( F_18 ( V_50 , V_109 | V_110 ) ) ) {
if ( V_2 -> V_111 . V_112 > 2 )
V_107 = true ;
} else {
if ( F_18 ( V_50 , V_113 ) )
V_107 = true ;
}
F_10 ( & V_8 -> V_14 , V_114 , V_107 ) ;
F_19 ( & V_8 -> V_14 ) ;
}
V_101:
return;
}
void F_20 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = F_6 ( V_2 ) ;
struct V_9 * V_10 = & V_8 -> V_11 ;
struct V_12 * V_115 = & V_8 -> V_14 ;
F_7 ( V_10 , 0 , sizeof( struct V_9 ) ) ;
F_5 ( V_2 ) ;
F_21 ( V_115 ) ;
}
void F_22 ( struct V_1 * V_2 )
{
}
void F_23 ( struct V_1 * V_2 , struct V_116 * V_117 , struct V_116 * V_118 )
{
struct V_7 * V_8 = F_6 ( V_2 ) ;
if ( 0 != V_8 -> V_63 ) {
if ( V_117 -> V_119 >= V_118 -> V_119 ) {
V_118 -> V_119 = V_117 -> V_119 ;
V_118 -> V_120 . V_121 = V_117 -> V_120 . V_121 ;
}
}
}
T_1 F_24 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = F_6 ( V_2 ) ;
struct V_12 * V_13 = & V_8 -> V_14 ;
struct V_122 * V_123 = & V_13 -> V_124 ;
struct V_49 * V_50 = & ( V_2 -> V_51 ) ;
if ( V_8 -> V_63 == 0 )
return false ;
if ( F_18 ( V_50 , V_113 ) )
return false ;
if ( V_123 -> V_125 == 0 ) {
V_123 -> V_125 = 1 ;
V_123 -> V_126 = ( V_123 -> V_126 == V_127 ) ? V_128 : V_127 ;
F_25 ( V_2 , V_123 -> V_126 , false ) ;
return true ;
} else {
V_123 -> V_125 = 0 ;
return false ;
}
}
