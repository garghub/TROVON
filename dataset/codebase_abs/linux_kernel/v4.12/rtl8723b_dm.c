static void F_1 ( struct V_1 * V_2 )
{
}
static void F_2 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_3 ( V_2 ) ;
T_1 V_5 = & ( V_4 -> V_6 ) ;
struct V_7 * V_8 = & V_4 -> V_9 ;
T_2 V_10 , V_11 ;
memset ( V_5 , 0 , sizeof( * V_5 ) ) ;
V_5 -> V_2 = V_2 ;
#define F_4 0x04
F_5 ( V_5 , V_12 , F_4 ) ;
F_5 ( V_5 , V_13 , V_14 ) ;
F_5 ( V_5 , V_15 , V_4 -> V_16 ) ;
F_5 ( V_5 , V_17 , V_18 ) ;
V_11 = V_19 ;
V_10 = V_20 ;
F_6 ( L_1 , V_21 , V_11 , V_10 ) ;
F_5 ( V_5 , V_22 , V_11 ) ;
F_5 ( V_5 , V_23 , V_10 ) ;
F_5 ( V_5 , V_24 , F_7 ( V_4 -> V_25 ) ) ;
F_5 ( V_5 , V_26 , V_4 -> V_27 ) ;
F_5 ( V_5 , V_28 , V_2 -> V_29 . V_30 ) ;
if ( V_4 -> V_31 == V_32 ) {
F_8 ( V_5 , V_33 , V_34 ) ;
} else if ( V_4 -> V_31 == V_35 ) {
F_8 ( V_5 , V_33 , V_36 ) ;
} else if ( V_4 -> V_31 == V_37 ) {
F_8 ( V_5 , V_33 , V_38 ) ;
}
V_8 -> V_39 = V_40 | V_41 ;
F_8 ( V_5 , V_42 , V_8 -> V_39 ) ;
}
static void F_9 ( struct V_1 * V_2 )
{
struct V_43 * V_44 = & V_2 -> V_45 ;
struct V_46 * V_47 = & V_2 -> V_48 ;
struct V_49 * V_50 = F_10 ( V_2 ) ;
struct V_51 * V_52 = F_11 ( V_2 ) ;
struct V_3 * V_4 = F_3 ( V_2 ) ;
T_1 V_5 = & ( V_4 -> V_6 ) ;
struct V_7 * V_8 = & V_4 -> V_9 ;
int V_53 ;
T_2 V_54 = 0 ;
V_8 -> V_39 = 0
| V_55
| V_56
| V_57
| V_58
| V_59
| V_60
| V_61
| V_62
| V_63
| V_41
| V_40
#ifdef F_12
| V_64
#endif
;
F_8 ( V_5 , V_42 , V_8 -> V_39 ) ;
F_13 ( V_5 , V_65 , & ( V_50 -> V_66 . V_67 ) ) ;
F_13 ( V_5 , V_68 , & ( V_50 -> V_66 . V_69 ) ) ;
F_13 ( V_5 , V_70 , & ( V_44 -> V_71 ) ) ;
F_13 ( V_5 , V_72 , & ( V_4 -> V_73 ) ) ;
F_13 ( V_5 , V_74 , & ( V_2 -> V_75 . V_76 ) ) ;
F_13 ( V_5 , V_77 , & ( V_4 -> V_78 ) ) ;
F_13 ( V_5 , V_79 , & ( V_4 -> V_80 ) ) ;
F_13 ( V_5 , V_81 , & ( V_2 -> V_82 ) ) ;
F_13 ( V_5 , V_83 , & V_54 ) ;
F_13 ( V_5 , V_84 , & ( V_4 -> V_85 ) ) ;
F_13 ( V_5 , V_86 , & ( V_4 -> V_87 ) ) ;
F_13 ( V_5 , V_88 , & ( V_4 -> V_89 ) ) ;
F_13 ( V_5 , V_90 , & ( V_47 -> V_91 ) ) ;
F_13 ( V_5 , V_92 , & ( V_52 -> V_93 ) ) ;
for ( V_53 = 0 ; V_53 < V_94 ; V_53 ++ )
F_14 ( V_5 , V_95 , V_53 , NULL ) ;
}
void F_15 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_3 ( V_2 ) ;
struct V_7 * V_8 = & V_4 -> V_9 ;
T_1 V_5 = & ( V_4 -> V_6 ) ;
V_8 -> V_96 = V_97 ;
V_8 -> V_98 = V_99 ;
V_8 -> V_98 |= V_100 ;
V_8 -> V_101 = V_8 -> V_98 ;
F_9 ( V_2 ) ;
F_16 ( V_5 ) ;
}
void F_17 ( struct V_1 * V_2 )
{
bool V_102 = false ;
bool V_103 = true ;
T_2 V_104 = false ;
struct V_3 * V_4 = F_3 ( V_2 ) ;
V_104 = V_2 -> V_104 ;
if ( V_104 == false )
goto V_105;
V_102 = F_11 ( V_2 ) -> V_102 ;
F_18 ( V_2 , V_106 , ( T_2 * ) ( & V_103 ) ) ;
if (
( V_104 == true ) &&
( ( ! V_102 ) && V_103 )
) {
F_1 ( V_2 ) ;
F_19 ( V_2 ) ;
}
if ( V_104 == true ) {
T_2 V_107 = false ;
T_2 V_108 = false ;
T_2 V_109 = true ;
if ( F_20 ( V_2 ) ) {
V_107 = true ;
if ( F_21 ( & V_2 -> V_48 , V_110 ) )
V_108 = true ;
}
F_8 ( & V_4 -> V_6 , V_111 , V_107 ) ;
F_8 ( & V_4 -> V_6 , V_112 , V_108 ) ;
V_109 = F_22 ( V_2 ) ;
F_8 ( & V_4 -> V_6 , V_113 , ( ( V_109 == true ) ? false : true ) ) ;
F_23 ( & V_4 -> V_6 ) ;
}
V_105:
return;
}
void F_24 ( struct V_1 * V_114 )
{
T_3 V_115 = 0 ;
struct V_46 * V_47 = & V_114 -> V_48 ;
struct V_3 * V_4 = F_3 ( V_114 ) ;
T_1 V_5 = & V_4 -> V_6 ;
struct V_116 * V_117 = & V_114 -> V_118 ;
struct V_119 * V_120 = NULL ;
F_6 ( L_2 , V_21 , V_5 -> V_121 ) ;
F_25 ( V_5 , V_5 -> V_121 ) ;
V_120 = F_26 ( V_117 , F_27 ( V_47 ) ) ;
if ( V_120 && ( V_120 -> V_122 . V_123 > 0 ) ) {
V_115 = ( V_120 -> V_124 | ( V_120 -> V_122 . V_123 << 16 ) ) ;
F_28 ( V_114 , ( T_2 * ) & V_115 ) ;
}
}
void F_29 ( struct V_1 * V_2 )
{
T_2 V_107 = false ;
struct V_3 * V_4 = F_3 ( V_2 ) ;
struct V_46 * V_47 = & V_2 -> V_48 ;
struct V_7 * V_8 = & V_4 -> V_9 ;
T_1 V_5 = & V_4 -> V_6 ;
T_4 V_125 = & V_5 -> V_126 ;
struct V_116 * V_117 = & V_2 -> V_118 ;
struct V_119 * V_120 = NULL ;
if ( V_2 -> V_104 == false )
goto V_127;
if ( F_20 ( V_2 ) )
V_107 = true ;
F_8 ( & V_4 -> V_6 , V_111 , V_107 ) ;
if ( V_107 == false )
goto V_127;
if ( ! ( V_5 -> V_128 & V_59 ) )
goto V_127;
V_120 = F_26 ( V_117 , F_27 ( V_47 ) ) ;
if ( V_120 == NULL )
goto V_127;
V_8 -> V_129 = V_120 -> V_122 . V_123 ;
F_6 ( L_3 , V_125 -> V_130 , V_8 -> V_129 ) ;
if ( V_8 -> V_129 <= 0 )
goto V_127;
V_8 -> V_131 = V_8 -> V_129 ;
V_5 -> V_121 = V_8 -> V_131 ;
if (
( V_125 -> V_130 > V_5 -> V_121 + 5 ) ||
( V_125 -> V_130 < V_5 -> V_121 - 5 )
)
F_30 ( V_2 ) ;
V_127:
return;
}
void F_31 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_3 ( V_2 ) ;
struct V_7 * V_8 = & V_4 -> V_9 ;
memset ( V_8 , 0 , sizeof( struct V_7 ) ) ;
F_2 ( V_2 ) ;
}
