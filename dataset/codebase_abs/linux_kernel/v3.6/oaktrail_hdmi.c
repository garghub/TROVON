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
if ( V_13 -> clock > 165000 )
return V_21 ;
if ( V_13 -> clock < 20000 )
return V_22 ;
if ( V_13 -> V_23 & V_24 )
return V_25 ;
return V_26 ;
}
static bool F_7 ( struct V_11 * V_12 ,
const struct V_20 * V_13 ,
struct V_20 * V_27 )
{
return true ;
}
static enum V_28
F_8 ( struct V_18 * V_19 , bool V_29 )
{
enum V_28 V_30 ;
struct V_1 * V_2 = V_19 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_6 * V_7 = V_4 -> V_8 ;
T_1 V_15 ;
V_15 = F_3 ( V_31 ) ;
F_9 ( L_1 , V_15 ) ;
if ( ( V_15 & V_32 ) != 0 )
V_30 = V_33 ;
else
V_30 = V_34 ;
return V_30 ;
}
static int F_10 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_35 * V_36 ;
struct V_37 * V_37 ;
struct V_20 * V_13 , * V_38 ;
int V_39 = 0 , V_40 = 0 ;
V_36 = F_11 ( 3 ) ;
if ( V_36 == NULL ) {
F_12 ( L_2 ) ;
V_37 = (struct V_37 * ) V_41 ;
} else {
V_37 = (struct V_37 * ) V_41 ;
}
if ( V_37 ) {
F_13 ( V_19 , V_37 ) ;
V_40 = F_14 ( V_19 , V_37 ) ;
V_19 -> V_42 . V_41 = NULL ;
}
F_15 (mode, t, &connector->probed_modes, head) {
if ( ( V_13 -> V_43 * V_13 -> V_44 * 4 ) >= V_4 -> V_45 ) {
V_39 ++ ;
F_16 ( V_19 , V_13 ) ;
}
}
return V_40 - V_39 ;
}
static void F_17 ( struct V_11 * V_12 ,
struct V_20 * V_13 ,
struct V_20 * V_27 )
{
struct V_1 * V_2 = V_12 -> V_2 ;
F_1 ( V_2 ) ;
return;
}
static void F_18 ( struct V_18 * V_19 )
{
return;
}
static void F_19 ( struct V_11 * V_12 )
{
F_20 ( V_12 ) ;
}
void F_21 ( struct V_1 * V_2 ,
struct V_46 * V_47 )
{
struct V_48 * V_48 ;
struct V_49 * V_49 ;
struct V_18 * V_19 ;
struct V_11 * V_12 ;
V_48 = F_22 ( sizeof( struct V_48 ) , V_50 ) ;
if ( ! V_48 )
return;
V_49 = F_22 ( sizeof( struct V_49 ) , V_50 ) ;
if ( ! V_49 )
goto V_51;
V_19 = & V_49 -> V_52 ;
V_12 = & V_48 -> V_52 ;
F_23 ( V_2 , V_19 ,
& V_53 ,
V_54 ) ;
F_24 ( V_2 , V_12 ,
& V_55 ,
V_56 ) ;
F_25 ( V_49 ,
V_48 ) ;
V_48 -> type = V_57 ;
F_26 ( V_12 , & V_58 ) ;
F_27 ( V_19 , & V_59 ) ;
V_19 -> V_42 . V_60 = V_61 ;
V_19 -> V_62 = false ;
V_19 -> V_63 = false ;
F_28 ( V_19 ) ;
return;
V_51:
F_29 ( V_48 ) ;
}
void F_30 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_64 * V_65 ;
struct V_6 * V_7 ;
int V_40 ;
V_65 = F_31 ( V_66 , 0x080d , NULL ) ;
if ( ! V_65 )
return;
V_7 = F_22 ( sizeof( struct V_6 ) , V_50 ) ;
if ( ! V_7 ) {
F_32 ( V_2 -> V_2 , L_3 ) ;
goto V_67;
}
V_40 = F_33 ( V_65 ) ;
if ( V_40 ) {
F_32 ( V_2 -> V_2 , L_4 ) ;
goto free;
}
V_7 -> V_68 = F_34 ( V_65 , 0 ) ;
V_7 -> V_69 = F_35 ( V_65 , 0 ) ;
V_7 -> V_70 = F_36 ( V_7 -> V_68 , V_7 -> V_69 ) ;
if ( ! V_7 -> V_70 ) {
F_32 ( V_2 -> V_2 , L_5 ) ;
goto free;
}
V_7 -> V_2 = V_65 ;
F_37 ( V_65 , V_7 ) ;
V_40 = F_38 ( V_7 -> V_2 ) ;
if ( V_40 )
F_32 ( V_2 -> V_2 , L_6 ) ;
V_4 -> V_8 = V_7 ;
F_4 ( V_2 ) ;
return;
free:
F_29 ( V_7 ) ;
V_67:
return;
}
void F_39 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_6 * V_7 = V_4 -> V_8 ;
struct V_64 * V_65 ;
if ( V_7 ) {
V_65 = V_7 -> V_2 ;
F_37 ( V_65 , NULL ) ;
F_40 ( V_65 ) ;
F_41 ( V_7 -> V_70 ) ;
F_29 ( V_7 ) ;
F_42 ( V_65 ) ;
}
}
void F_43 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_6 * V_7 = V_4 -> V_8 ;
struct V_71 * V_70 = & V_4 -> V_70 . V_72 ;
struct V_73 * V_74 = & V_4 -> V_70 . V_75 [ 1 ] ;
int V_39 ;
V_7 -> V_76 = F_44 ( V_77 ) ;
V_7 -> V_78 = F_44 ( V_79 ) ;
V_7 -> V_80 = F_44 ( V_81 ) ;
V_7 -> V_82 = F_44 ( V_83 ) ;
V_7 -> V_84 = F_44 ( V_85 ) ;
V_74 -> V_86 = F_44 ( V_87 ) ;
V_74 -> V_88 = F_44 ( V_89 ) ;
V_74 -> V_90 = F_44 ( V_91 ) ;
V_74 -> V_92 = F_44 ( V_93 ) ;
V_74 -> V_94 = F_44 ( V_95 ) ;
V_74 -> V_96 = F_44 ( V_97 ) ;
V_74 -> V_98 = F_44 ( V_99 ) ;
V_74 -> V_100 = F_44 ( V_101 ) ;
V_7 -> V_102 = F_44 ( V_103 ) ;
V_7 -> V_104 = F_44 ( V_105 ) ;
V_7 -> V_106 = F_44 ( V_107 ) ;
V_7 -> V_108 = F_44 ( V_109 ) ;
V_7 -> V_110 = F_44 ( V_111 ) ;
V_7 -> V_112 = F_44 ( V_113 ) ;
V_7 -> V_114 = F_44 ( V_115 ) ;
V_7 -> V_116 = F_44 ( V_117 ) ;
V_74 -> V_118 = F_44 ( V_119 ) ;
V_74 -> V_120 = F_44 ( V_121 ) ;
V_74 -> V_122 = F_44 ( V_123 ) ;
V_74 -> V_124 = F_44 ( V_125 ) ;
V_74 -> V_126 = F_44 ( V_127 ) ;
V_74 -> V_128 = F_44 ( V_129 ) ;
V_70 -> V_130 = F_44 ( V_131 ) ;
V_70 -> V_132 = F_44 ( V_133 ) ;
V_70 -> V_134 = F_44 ( V_135 ) ;
for ( V_39 = 0 ; V_39 < 256 ; V_39 ++ )
V_74 -> V_136 [ V_39 ] = F_44 ( V_137 + ( V_39 << 2 ) ) ;
}
void F_45 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_6 * V_7 = V_4 -> V_8 ;
struct V_71 * V_70 = & V_4 -> V_70 . V_72 ;
struct V_73 * V_74 = & V_4 -> V_70 . V_75 [ 1 ] ;
int V_39 ;
F_46 ( V_7 -> V_76 , V_77 ) ;
F_46 ( V_7 -> V_78 , V_79 ) ;
F_46 ( V_7 -> V_80 , V_81 ) ;
F_46 ( V_7 -> V_82 , V_83 ) ;
F_46 ( V_7 -> V_84 , V_85 ) ;
F_47 ( 150 ) ;
F_46 ( V_74 -> V_88 , V_89 ) ;
F_46 ( V_74 -> V_90 , V_91 ) ;
F_46 ( V_74 -> V_92 , V_93 ) ;
F_46 ( V_74 -> V_94 , V_95 ) ;
F_46 ( V_74 -> V_96 , V_97 ) ;
F_46 ( V_74 -> V_98 , V_99 ) ;
F_46 ( V_74 -> V_100 , V_101 ) ;
F_46 ( V_7 -> V_104 , V_105 ) ;
F_46 ( V_7 -> V_106 , V_107 ) ;
F_46 ( V_7 -> V_108 , V_109 ) ;
F_46 ( V_7 -> V_110 , V_111 ) ;
F_46 ( V_7 -> V_112 , V_113 ) ;
F_46 ( V_7 -> V_114 , V_115 ) ;
F_46 ( V_7 -> V_116 , V_117 ) ;
F_46 ( V_74 -> V_86 , V_87 ) ;
F_46 ( V_7 -> V_102 , V_103 ) ;
F_46 ( V_74 -> V_126 , V_127 ) ;
F_46 ( V_74 -> V_120 , V_121 ) ;
F_46 ( V_74 -> V_128 , V_129 ) ;
F_46 ( V_74 -> V_118 , V_119 ) ;
F_46 ( V_74 -> V_124 , V_125 ) ;
F_46 ( V_70 -> V_130 , V_131 ) ;
F_46 ( V_70 -> V_134 , V_135 ) ;
F_46 ( V_70 -> V_132 , V_133 ) ;
for ( V_39 = 0 ; V_39 < 256 ; V_39 ++ )
F_46 ( V_74 -> V_136 [ V_39 ] , V_137 + ( V_39 << 2 ) ) ;
}
