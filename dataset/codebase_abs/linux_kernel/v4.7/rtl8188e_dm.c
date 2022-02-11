static void F_1 ( struct V_1 * V_2 )
{
T_1 V_3 ;
V_3 = F_2 ( V_2 , V_4 ) ;
V_3 &= ( V_5 | ~ V_6 ) ;
F_3 ( V_2 , V_4 , V_3 ) ;
}
static void F_4 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = F_5 ( V_2 ) ;
struct V_9 * V_10 = & V_8 -> V_11 ;
struct V_12 * V_13 = & ( V_8 -> V_14 ) ;
T_1 V_15 ;
memset ( V_13 , 0 , sizeof( * V_13 ) ) ;
V_13 -> V_2 = V_2 ;
F_6 ( V_13 , V_16 , V_17 ) ;
F_6 ( V_13 , V_18 , V_19 ) ;
V_15 = V_20 ;
F_6 ( V_13 , V_21 , V_15 ) ;
F_6 ( V_13 , V_22 , V_8 -> V_23 . V_24 == V_25 ? true : false ) ;
F_6 ( V_13 , V_26 , V_8 -> V_27 ) ;
F_6 ( V_13 , V_28 , V_2 -> V_29 . V_30 ) ;
if ( V_8 -> V_31 == V_32 )
F_7 ( V_13 , V_33 , V_34 ) ;
else if ( V_8 -> V_31 == V_35 )
F_7 ( V_13 , V_33 , V_36 ) ;
else if ( V_8 -> V_31 == V_37 )
F_7 ( V_13 , V_33 , V_38 ) ;
F_6 ( V_13 , V_39 , V_8 -> V_40 ) ;
V_10 -> V_41 = V_42 |
V_43 ;
F_7 ( V_13 , V_44 , V_10 -> V_41 ) ;
}
static void F_8 ( struct V_1 * V_2 )
{
struct V_45 * V_46 = & V_2 -> V_47 ;
struct V_48 * V_49 = & V_2 -> V_50 ;
struct V_51 * V_52 = & V_2 -> V_52 ;
struct V_7 * V_8 = F_5 ( V_2 ) ;
struct V_12 * V_13 = & ( V_8 -> V_14 ) ;
struct V_9 * V_10 = & V_8 -> V_11 ;
int V_53 ;
V_10 -> V_41 = V_54 |
V_55 |
V_56 |
V_57 |
V_58 |
V_59 |
V_60 |
V_61 |
V_42 |
V_43 ;
if ( V_8 -> V_62 )
V_10 -> V_41 |= V_63 ;
if ( V_2 -> V_29 . V_64 == 1 ) {
V_10 -> V_41 = V_42 |
V_43 ;
}
F_7 ( V_13 , V_44 , V_10 -> V_41 ) ;
F_9 ( V_13 , V_65 , & ( V_2 -> V_66 . V_67 ) ) ;
F_9 ( V_13 , V_68 , & ( V_2 -> V_69 . V_70 ) ) ;
F_9 ( V_13 , V_71 , & ( V_46 -> V_72 ) ) ;
F_9 ( V_13 , V_73 , & ( V_8 -> V_74 ) ) ;
F_9 ( V_13 , V_75 , & ( V_2 -> V_76 . V_77 ) ) ;
F_9 ( V_13 , V_78 , & ( V_8 -> V_79 ) ) ;
F_9 ( V_13 , V_80 , & ( V_8 -> V_81 ) ) ;
F_9 ( V_13 , V_82 , & ( V_2 -> V_83 ) ) ;
F_9 ( V_13 , V_84 , & ( V_2 -> V_29 . V_64 ) ) ;
F_9 ( V_13 , V_85 , & ( V_49 -> V_86 ) ) ;
F_9 ( V_13 , V_87 , & ( V_52 -> V_88 ) ) ;
F_6 ( V_13 , V_39 , V_8 -> V_40 ) ;
for ( V_53 = 0 ; V_53 < V_89 ; V_53 ++ )
F_10 ( V_13 , V_90 , V_53 , NULL ) ;
}
void F_11 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = F_5 ( V_2 ) ;
struct V_9 * V_10 = & V_8 -> V_11 ;
struct V_12 * V_13 = & ( V_8 -> V_14 ) ;
F_1 ( V_2 ) ;
V_10 -> V_91 = V_92 ;
V_10 -> V_93 = V_94 ;
F_8 ( V_2 ) ;
F_12 ( V_13 ) ;
V_2 -> V_95 = 0xFF ;
}
void F_13 ( struct V_1 * V_2 )
{
bool V_96 = true ;
T_1 V_97 = false ;
struct V_7 * V_8 = F_5 ( V_2 ) ;
struct V_48 * V_49 = NULL ;
T_1 V_98 = false ;
V_97 = V_2 -> V_97 ;
if ( ! V_97 )
goto V_99;
F_14 ( V_2 , V_100 , ( T_1 * ) ( & V_96 ) ) ;
if ( V_2 -> V_101 . V_102 )
V_96 = false ;
V_49 = & V_2 -> V_50 ;
if ( ( F_15 ( V_49 , V_103 ) ) ||
( F_15 ( V_49 , V_104 |
V_105 ) ) ) {
if ( V_2 -> V_106 . V_107 > 2 )
V_98 = true ;
} else {
if ( F_15 ( V_49 , V_108 ) )
V_98 = true ;
}
F_7 ( & V_8 -> V_14 , V_109 , V_98 ) ;
F_16 ( & V_8 -> V_14 ) ;
V_99:
return;
}
void F_17 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = F_5 ( V_2 ) ;
struct V_9 * V_10 = & V_8 -> V_11 ;
struct V_12 * V_110 = & V_8 -> V_14 ;
memset ( V_10 , 0 , sizeof( struct V_9 ) ) ;
F_4 ( V_2 ) ;
F_18 ( V_110 ) ;
}
void F_19 ( struct V_1 * V_2 , struct V_111 * V_112 , struct V_111 * V_113 )
{
struct V_7 * V_8 = F_5 ( V_2 ) ;
if ( 0 != V_8 -> V_62 ) {
if ( V_112 -> V_114 >= V_113 -> V_114 ) {
V_113 -> V_114 = V_112 -> V_114 ;
V_113 -> V_115 . V_116 = V_112 -> V_115 . V_116 ;
}
}
}
T_1 F_20 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = F_5 ( V_2 ) ;
struct V_12 * V_13 = & V_8 -> V_14 ;
struct V_117 * V_118 = & V_13 -> V_119 ;
struct V_48 * V_49 = & ( V_2 -> V_50 ) ;
if ( V_8 -> V_62 == 0 )
return false ;
if ( F_15 ( V_49 , V_108 ) )
return false ;
if ( V_118 -> V_120 == 0 ) {
V_118 -> V_120 = 1 ;
V_118 -> V_121 = ( V_118 -> V_121 == V_122 ) ? V_123 : V_122 ;
F_21 ( V_2 , V_118 -> V_121 , false ) ;
return true ;
} else {
V_118 -> V_120 = 0 ;
return false ;
}
}
