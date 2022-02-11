static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_6 * V_7 = V_4 -> V_8 ;
F_2 ( V_9 , 0x67 ) ;
F_3 ( V_9 ) ;
F_2 ( 0x51a8 , 0x10 ) ;
F_3 ( 0x51a8 ) ;
F_2 ( V_10 , 0x1 ) ;
F_3 ( V_10 ) ;
}
static void F_4 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_6 * V_7 = V_4 -> V_8 ;
F_2 ( 0x51a8 , 0x0 ) ;
F_3 ( 0x51a8 ) ;
F_2 ( V_10 , 0x0 ) ;
F_3 ( V_10 ) ;
F_2 ( V_9 , 0x47 ) ;
F_3 ( V_9 ) ;
}
static void F_5 ( struct V_11 * V_12 , int V_13 )
{
static int V_14 = - 1 ;
struct V_1 * V_2 = V_12 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_6 * V_7 = V_4 -> V_8 ;
T_1 V_15 ;
if ( V_14 == V_13 )
return;
if ( V_13 != V_16 )
V_15 = 0x0 ;
else
V_15 = 0x99 ;
V_14 = V_13 ;
F_2 ( V_17 , V_15 ) ;
}
static int F_6 ( struct V_18 * V_19 ,
struct V_20 * V_13 )
{
struct V_3 * V_4 = V_19 -> V_2 -> V_5 ;
if ( V_13 -> clock > 165000 )
return V_21 ;
if ( V_13 -> clock < 20000 )
return V_22 ;
if ( V_13 -> V_23 & V_24 )
return V_25 ;
if ( ( F_7 ( V_13 -> V_26 * 4 , 64 ) * V_13 -> V_27 ) >
V_4 -> V_28 )
return V_29 ;
return V_30 ;
}
static bool F_8 ( struct V_11 * V_12 ,
struct V_20 * V_13 ,
struct V_20 * V_31 )
{
return true ;
}
static enum V_32
F_9 ( struct V_18 * V_19 , bool V_33 )
{
enum V_32 V_34 ;
struct V_1 * V_2 = V_19 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_6 * V_7 = V_4 -> V_8 ;
T_1 V_15 ;
V_15 = F_3 ( V_35 ) ;
F_10 ( L_1 , V_15 ) ;
if ( ( V_15 & V_36 ) != 0 )
V_34 = V_37 ;
else
V_34 = V_38 ;
return V_34 ;
}
static int F_11 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_39 * V_40 ;
struct V_41 * V_41 ;
struct V_20 * V_13 , * V_42 ;
int V_43 = 0 , V_44 = 0 ;
V_40 = F_12 ( 3 ) ;
if ( V_40 == NULL ) {
F_13 ( L_2 ) ;
V_41 = (struct V_41 * ) V_45 ;
} else {
V_41 = (struct V_41 * ) V_45 ;
}
if ( V_41 ) {
F_14 ( V_19 , V_41 ) ;
V_44 = F_15 ( V_19 , V_41 ) ;
V_19 -> V_46 . V_45 = NULL ;
}
F_16 (mode, t, &connector->probed_modes, head) {
if ( ( V_13 -> V_26 * V_13 -> V_27 * 4 ) >= V_4 -> V_28 ) {
V_43 ++ ;
F_17 ( V_19 , V_13 ) ;
}
}
return V_44 - V_43 ;
}
static void F_18 ( struct V_11 * V_12 ,
struct V_20 * V_13 ,
struct V_20 * V_31 )
{
struct V_1 * V_2 = V_12 -> V_2 ;
F_1 ( V_2 ) ;
return;
}
static void F_19 ( struct V_18 * V_19 )
{
return;
}
static void F_20 ( struct V_11 * V_12 )
{
F_21 ( V_12 ) ;
}
void F_22 ( struct V_1 * V_2 ,
struct V_47 * V_48 )
{
struct V_49 * V_49 ;
struct V_50 * V_50 ;
struct V_18 * V_19 ;
struct V_11 * V_12 ;
V_49 = F_23 ( sizeof( struct V_49 ) , V_51 ) ;
if ( ! V_49 )
return;
V_50 = F_23 ( sizeof( struct V_50 ) , V_51 ) ;
if ( ! V_50 )
goto V_52;
V_19 = & V_50 -> V_53 ;
V_12 = & V_49 -> V_53 ;
F_24 ( V_2 , V_19 ,
& V_54 ,
V_55 ) ;
F_25 ( V_2 , V_12 ,
& V_56 ,
V_57 ) ;
F_26 ( V_50 ,
V_49 ) ;
V_49 -> type = V_58 ;
F_27 ( V_12 , & V_59 ) ;
F_28 ( V_19 , & V_60 ) ;
V_19 -> V_46 . V_61 = V_62 ;
V_19 -> V_63 = false ;
V_19 -> V_64 = false ;
F_29 ( V_19 ) ;
return;
V_52:
F_30 ( V_49 ) ;
}
void F_31 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_65 * V_66 ;
struct V_6 * V_7 ;
int V_44 ;
V_66 = F_32 ( V_67 , 0x080d , NULL ) ;
if ( ! V_66 )
return;
V_7 = F_23 ( sizeof( struct V_6 ) , V_51 ) ;
if ( ! V_7 ) {
F_33 ( V_2 -> V_2 , L_3 ) ;
goto V_68;
}
V_44 = F_34 ( V_66 ) ;
if ( V_44 ) {
F_33 ( V_2 -> V_2 , L_4 ) ;
goto free;
}
V_7 -> V_69 = F_35 ( V_66 , 0 ) ;
V_7 -> V_70 = F_36 ( V_66 , 0 ) ;
V_7 -> V_71 = F_37 ( V_7 -> V_69 , V_7 -> V_70 ) ;
if ( ! V_7 -> V_71 ) {
F_33 ( V_2 -> V_2 , L_5 ) ;
goto free;
}
V_7 -> V_2 = V_66 ;
F_38 ( V_66 , V_7 ) ;
V_44 = F_39 ( V_7 -> V_2 ) ;
if ( V_44 )
F_33 ( V_2 -> V_2 , L_6 ) ;
V_4 -> V_8 = V_7 ;
F_4 ( V_2 ) ;
return;
free:
F_30 ( V_7 ) ;
V_68:
return;
}
void F_40 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_6 * V_7 = V_4 -> V_8 ;
struct V_65 * V_66 ;
if ( V_7 ) {
V_66 = V_7 -> V_2 ;
F_38 ( V_66 , NULL ) ;
F_41 ( V_66 ) ;
F_42 ( V_7 -> V_71 ) ;
F_30 ( V_7 ) ;
F_43 ( V_66 ) ;
}
}
void F_44 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_6 * V_7 = V_4 -> V_8 ;
struct V_72 * V_71 = & V_4 -> V_71 . V_73 ;
int V_43 ;
V_7 -> V_74 = F_45 ( V_75 ) ;
V_7 -> V_76 = F_45 ( V_77 ) ;
V_7 -> V_78 = F_45 ( V_79 ) ;
V_7 -> V_80 = F_45 ( V_81 ) ;
V_7 -> V_82 = F_45 ( V_83 ) ;
V_71 -> V_84 = F_45 ( V_85 ) ;
V_71 -> V_86 = F_45 ( V_87 ) ;
V_71 -> V_88 = F_45 ( V_89 ) ;
V_71 -> V_90 = F_45 ( V_91 ) ;
V_71 -> V_92 = F_45 ( V_93 ) ;
V_71 -> V_94 = F_45 ( V_95 ) ;
V_71 -> V_96 = F_45 ( V_97 ) ;
V_71 -> V_98 = F_45 ( V_99 ) ;
V_7 -> V_100 = F_45 ( V_101 ) ;
V_7 -> V_102 = F_45 ( V_103 ) ;
V_7 -> V_104 = F_45 ( V_105 ) ;
V_7 -> V_106 = F_45 ( V_107 ) ;
V_7 -> V_108 = F_45 ( V_109 ) ;
V_7 -> V_110 = F_45 ( V_111 ) ;
V_7 -> V_112 = F_45 ( V_113 ) ;
V_7 -> V_114 = F_45 ( V_115 ) ;
V_71 -> V_116 = F_45 ( V_117 ) ;
V_71 -> V_118 = F_45 ( V_119 ) ;
V_71 -> V_120 = F_45 ( V_121 ) ;
V_71 -> V_122 = F_45 ( V_123 ) ;
V_71 -> V_124 = F_45 ( V_125 ) ;
V_71 -> V_126 = F_45 ( V_127 ) ;
V_71 -> V_128 = F_45 ( V_129 ) ;
V_71 -> V_130 = F_45 ( V_131 ) ;
V_71 -> V_132 = F_45 ( V_133 ) ;
for ( V_43 = 0 ; V_43 < 256 ; V_43 ++ )
V_71 -> V_134 [ V_43 ] = F_45 ( V_135 + ( V_43 << 2 ) ) ;
}
void F_46 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_6 * V_7 = V_4 -> V_8 ;
struct V_72 * V_71 = & V_4 -> V_71 . V_73 ;
int V_43 ;
F_47 ( V_7 -> V_74 , V_75 ) ;
F_47 ( V_7 -> V_76 , V_77 ) ;
F_47 ( V_7 -> V_78 , V_79 ) ;
F_47 ( V_7 -> V_80 , V_81 ) ;
F_47 ( V_7 -> V_82 , V_83 ) ;
F_48 ( 150 ) ;
F_47 ( V_71 -> V_86 , V_87 ) ;
F_47 ( V_71 -> V_88 , V_89 ) ;
F_47 ( V_71 -> V_90 , V_91 ) ;
F_47 ( V_71 -> V_92 , V_93 ) ;
F_47 ( V_71 -> V_94 , V_95 ) ;
F_47 ( V_71 -> V_96 , V_97 ) ;
F_47 ( V_71 -> V_98 , V_99 ) ;
F_47 ( V_7 -> V_102 , V_103 ) ;
F_47 ( V_7 -> V_104 , V_105 ) ;
F_47 ( V_7 -> V_106 , V_107 ) ;
F_47 ( V_7 -> V_108 , V_109 ) ;
F_47 ( V_7 -> V_110 , V_111 ) ;
F_47 ( V_7 -> V_112 , V_113 ) ;
F_47 ( V_7 -> V_114 , V_115 ) ;
F_47 ( V_71 -> V_84 , V_85 ) ;
F_47 ( V_7 -> V_100 , V_101 ) ;
F_47 ( V_71 -> V_124 , V_125 ) ;
F_47 ( V_71 -> V_118 , V_119 ) ;
F_47 ( V_71 -> V_126 , V_127 ) ;
F_47 ( V_71 -> V_116 , V_117 ) ;
F_47 ( V_71 -> V_122 , V_123 ) ;
F_47 ( V_71 -> V_128 , V_129 ) ;
F_47 ( V_71 -> V_132 , V_133 ) ;
F_47 ( V_71 -> V_130 , V_131 ) ;
for ( V_43 = 0 ; V_43 < 256 ; V_43 ++ )
F_47 ( V_71 -> V_134 [ V_43 ] , V_135 + ( V_43 << 2 ) ) ;
}
