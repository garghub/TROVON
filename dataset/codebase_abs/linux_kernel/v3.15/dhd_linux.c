char * F_1 ( struct V_1 * V_2 , int V_3 )
{
if ( V_3 < 0 || V_3 >= V_4 ) {
F_2 ( L_1 , V_3 ) ;
return L_2 ;
}
if ( V_2 -> V_5 [ V_3 ] == NULL ) {
F_2 ( L_3 , V_3 ) ;
return L_4 ;
}
if ( V_2 -> V_5 [ V_3 ] -> V_6 )
return V_2 -> V_5 [ V_3 ] -> V_6 -> V_7 ;
return L_5 ;
}
static void F_3 ( struct V_8 * V_9 )
{
struct V_10 * V_11 ;
struct V_12 * V_6 ;
struct V_13 * V_14 ;
T_1 V_15 , V_16 ;
T_2 V_17 ;
char * V_18 , * V_19 ;
T_1 V_20 ;
T_3 V_21 ;
V_11 = F_4 ( V_9 , struct V_10 , V_22 ) ;
F_5 ( V_23 , L_6 , V_11 -> V_24 ) ;
V_6 = V_11 -> V_6 ;
V_15 = ( V_6 -> V_25 & V_26 ) ? true : false ;
V_16 = F_6 ( V_6 ) ;
V_20 = sizeof( V_16 ) + ( V_16 * V_27 ) ;
V_18 = F_7 ( V_20 , V_28 ) ;
if ( ! V_18 )
return;
V_19 = V_18 ;
V_17 = F_8 ( V_16 ) ;
memcpy ( V_19 , & V_17 , sizeof( V_17 ) ) ;
V_19 += sizeof( V_17 ) ;
F_9 (ha, ndev) {
if ( ! V_16 )
break;
memcpy ( V_19 , V_14 -> V_29 , V_27 ) ;
V_19 += V_27 ;
V_16 -- ;
}
V_21 = F_10 ( V_11 , L_7 , V_18 , V_20 ) ;
if ( V_21 < 0 ) {
F_2 ( L_8 , V_21 ) ;
V_15 = V_16 ? true : V_15 ;
}
F_11 ( V_18 ) ;
V_21 = F_12 ( V_11 , L_9 , V_15 ) ;
if ( V_21 < 0 )
F_2 ( L_10 , V_21 ) ;
V_15 = ( V_6 -> V_25 & V_30 ) ? true : false ;
V_21 = F_13 ( V_11 , V_31 , V_15 ) ;
if ( V_21 < 0 )
F_2 ( L_11 ,
V_21 ) ;
}
static void
F_14 ( struct V_8 * V_9 )
{
struct V_10 * V_11 ;
T_3 V_21 ;
V_11 = F_4 ( V_9 , struct V_10 , V_32 ) ;
F_5 ( V_23 , L_6 , V_11 -> V_24 ) ;
V_21 = F_10 ( V_11 , L_12 , V_11 -> V_33 ,
V_27 ) ;
if ( V_21 < 0 ) {
F_2 ( L_13 , V_21 ) ;
} else {
F_5 ( V_23 , L_14 ,
V_11 -> V_33 ) ;
memcpy ( V_11 -> V_6 -> V_34 , V_11 -> V_33 , V_27 ) ;
}
}
static int F_15 ( struct V_12 * V_6 , void * V_29 )
{
struct V_10 * V_11 = F_16 ( V_6 ) ;
struct V_35 * V_36 = (struct V_35 * ) V_29 ;
memcpy ( & V_11 -> V_33 , V_36 -> V_37 , V_27 ) ;
F_17 ( & V_11 -> V_32 ) ;
return 0 ;
}
static void F_18 ( struct V_12 * V_6 )
{
struct V_10 * V_11 = F_16 ( V_6 ) ;
F_17 ( & V_11 -> V_22 ) ;
}
static T_4 F_19 ( struct V_38 * V_39 ,
struct V_12 * V_6 )
{
int V_40 ;
struct V_10 * V_11 = F_16 ( V_6 ) ;
struct V_1 * V_2 = V_11 -> V_2 ;
struct V_41 * V_42 ;
F_5 ( V_43 , L_6 , V_11 -> V_24 ) ;
if ( V_2 -> V_44 -> V_45 != V_46 ) {
F_2 ( L_15 , V_2 -> V_44 -> V_45 ) ;
F_20 ( V_6 ) ;
F_21 ( V_39 ) ;
V_40 = - V_47 ;
goto V_48;
}
if ( ! V_2 -> V_5 [ V_11 -> V_24 ] ) {
F_2 ( L_16 , V_11 -> V_24 ) ;
F_20 ( V_6 ) ;
F_21 ( V_39 ) ;
V_40 = - V_47 ;
goto V_48;
}
if ( F_22 ( V_39 ) < V_2 -> V_49 ) {
struct V_38 * V_50 ;
F_5 ( V_51 , L_17 ,
F_1 ( V_2 , V_11 -> V_24 ) ) ;
V_2 -> V_44 -> V_52 ++ ;
V_50 = F_23 ( V_39 , V_2 -> V_49 ) ;
F_21 ( V_39 ) ;
V_39 = V_50 ;
if ( V_39 == NULL ) {
F_2 ( L_18 ,
F_1 ( V_2 , V_11 -> V_24 ) ) ;
V_40 = - V_53 ;
goto V_48;
}
}
if ( V_39 -> V_54 < sizeof( * V_42 ) ) {
V_40 = - V_55 ;
F_21 ( V_39 ) ;
goto V_48;
}
V_40 = F_24 ( V_11 , V_39 ) ;
V_48:
if ( V_40 ) {
V_11 -> V_56 . V_57 ++ ;
} else {
V_11 -> V_56 . V_58 ++ ;
V_11 -> V_56 . V_59 += V_39 -> V_54 ;
}
return V_60 ;
}
void F_25 ( struct V_10 * V_11 ,
enum V_61 V_62 , bool V_45 )
{
unsigned long V_25 ;
if ( ! V_11 || ! V_11 -> V_6 )
return;
F_5 ( V_23 , L_19 ,
V_11 -> V_24 , V_11 -> V_63 , V_62 , V_45 ) ;
F_26 ( & V_11 -> V_64 , V_25 ) ;
if ( V_45 ) {
if ( ! V_11 -> V_63 )
F_20 ( V_11 -> V_6 ) ;
V_11 -> V_63 |= V_62 ;
} else {
V_11 -> V_63 &= ~ V_62 ;
if ( ! V_11 -> V_63 )
F_27 ( V_11 -> V_6 ) ;
}
F_28 ( & V_11 -> V_64 , V_25 ) ;
}
void F_29 ( struct V_65 * V_66 , bool V_45 )
{
struct V_67 * V_44 = F_30 ( V_66 ) ;
struct V_1 * V_2 = V_44 -> V_2 ;
F_5 ( V_23 , L_20 ) ;
F_31 ( V_2 , V_45 ) ;
}
static void F_32 ( struct V_10 * V_11 , struct V_38 * V_39 )
{
V_39 -> V_66 = V_11 -> V_6 ;
V_39 -> V_68 = F_33 ( V_39 , V_39 -> V_66 ) ;
if ( V_39 -> V_69 == V_70 )
V_11 -> V_56 . V_71 ++ ;
F_34 ( V_11 -> V_2 , V_39 ) ;
if ( ! ( V_11 -> V_6 -> V_25 & V_72 ) ) {
F_35 ( V_39 ) ;
return;
}
V_11 -> V_56 . V_73 += V_39 -> V_54 ;
V_11 -> V_56 . V_74 ++ ;
F_5 ( V_43 , L_21 , F_36 ( V_39 -> V_68 ) ) ;
if ( F_37 () )
F_38 ( V_39 ) ;
else
F_39 ( V_39 ) ;
}
static void F_40 ( struct V_75 * V_76 ,
T_5 V_77 , T_5 V_78 ,
struct V_79 * V_80 )
{
F_41 ( V_80 ) ;
if ( V_76 -> V_81 == 0 ) {
F_5 ( V_51 , L_22 ) ;
return;
}
do {
if ( V_76 -> V_82 [ V_77 ] ) {
F_42 ( V_80 , V_76 -> V_82 [ V_77 ] ) ;
V_76 -> V_82 [ V_77 ] = NULL ;
}
V_77 ++ ;
if ( V_77 > V_76 -> V_83 )
V_77 = 0 ;
} while ( V_77 != V_78 );
V_76 -> V_81 -= F_43 ( V_80 ) ;
}
static void F_44 ( struct V_10 * V_11 , T_5 * V_84 ,
struct V_38 * V_85 )
{
T_5 V_86 , V_83 , V_87 , V_88 , V_89 ;
struct V_75 * V_76 ;
struct V_79 V_90 ;
struct V_38 * V_91 ;
T_5 V_25 ;
T_1 V_92 ;
V_86 = V_84 [ V_93 ] ;
V_25 = V_84 [ V_94 ] ;
if ( V_25 == 0xFF ) {
F_2 ( L_23 ) ;
F_32 ( V_11 , V_85 ) ;
return;
}
V_76 = V_11 -> V_2 -> V_95 [ V_86 ] ;
if ( V_25 & V_96 ) {
F_5 ( V_51 , L_24 ,
V_86 ) ;
if ( V_76 == NULL ) {
F_5 ( V_51 , L_25 ,
V_86 ) ;
F_32 ( V_11 , V_85 ) ;
return;
}
F_40 ( V_76 , V_76 -> V_88 , V_76 -> V_88 ,
& V_90 ) ;
F_42 ( & V_90 , V_85 ) ;
F_11 ( V_76 ) ;
V_11 -> V_2 -> V_95 [ V_86 ] = NULL ;
goto F_38;
}
if ( V_76 == NULL ) {
V_92 = sizeof( * V_76 ) ;
V_83 = V_84 [ V_97 ] ;
V_92 += ( V_83 + 1 ) * sizeof( V_85 ) ;
F_5 ( V_51 , L_26 ,
V_86 , V_83 ) ;
V_76 = F_45 ( V_92 , V_28 ) ;
if ( V_76 == NULL ) {
F_2 ( L_27 ) ;
F_32 ( V_11 , V_85 ) ;
return;
}
V_11 -> V_2 -> V_95 [ V_86 ] = V_76 ;
V_76 -> V_82 = (struct V_38 * * ) ( V_76 + 1 ) ;
V_76 -> V_83 = V_83 ;
}
if ( V_25 & V_98 ) {
if ( V_76 -> V_81 ) {
F_40 ( V_76 , V_76 -> V_88 ,
V_76 -> V_88 ,
& V_90 ) ;
F_46 ( V_76 -> V_81 ) ;
} else {
F_41 ( & V_90 ) ;
}
V_76 -> V_87 = V_84 [ V_99 ] ;
V_76 -> V_88 = V_84 [ V_100 ] ;
V_76 -> V_83 = V_84 [ V_97 ] ;
V_76 -> V_82 [ V_76 -> V_87 ] = V_85 ;
V_76 -> V_81 ++ ;
F_5 ( V_43 , L_28 ,
V_86 , V_76 -> V_87 , V_76 -> V_88 , V_76 -> V_81 ) ;
} else if ( V_25 & V_101 ) {
V_87 = V_84 [ V_99 ] ;
V_88 = V_84 [ V_100 ] ;
if ( ( V_88 == V_76 -> V_88 ) && ( V_87 != V_76 -> V_88 ) ) {
if ( V_76 -> V_82 [ V_87 ] != NULL ) {
F_5 ( V_51 , L_29 ) ;
F_35 ( V_76 -> V_82 [ V_87 ] ) ;
V_76 -> V_82 [ V_87 ] = NULL ;
}
V_76 -> V_82 [ V_87 ] = V_85 ;
V_76 -> V_81 ++ ;
V_76 -> V_87 = V_87 ;
F_5 ( V_43 , L_30 ,
V_86 , V_87 , V_88 , V_76 -> V_81 ) ;
return;
}
if ( V_76 -> V_88 == V_87 ) {
if ( V_76 -> V_82 [ V_87 ] != NULL ) {
F_5 ( V_51 , L_31 ) ;
F_35 ( V_76 -> V_82 [ V_87 ] ) ;
V_76 -> V_82 [ V_87 ] = NULL ;
}
V_76 -> V_82 [ V_87 ] = V_85 ;
V_76 -> V_81 ++ ;
F_5 ( V_43 , L_32 ,
V_86 , V_87 , V_88 , V_76 -> V_81 ) ;
V_76 -> V_87 = V_87 ;
V_76 -> V_88 = V_88 ;
F_40 ( V_76 , V_87 , V_88 ,
& V_90 ) ;
F_5 ( V_43 , L_33 ,
V_86 , F_43 ( & V_90 ) ,
V_76 -> V_81 ) ;
} else {
T_5 V_89 ;
F_5 ( V_43 , L_34 ,
V_86 , V_25 , V_76 -> V_87 , V_76 -> V_88 ,
V_87 , V_88 ) ;
if ( V_25 & V_102 )
V_89 = V_76 -> V_88 ;
else
V_89 = V_88 ;
F_40 ( V_76 , V_76 -> V_88 , V_89 ,
& V_90 ) ;
if ( V_88 == ( ( V_87 + 1 ) % ( V_76 -> V_83 + 1 ) ) ) {
F_42 ( & V_90 , V_85 ) ;
} else {
V_76 -> V_82 [ V_87 ] = V_85 ;
V_76 -> V_81 ++ ;
}
V_76 -> V_88 = V_88 ;
V_76 -> V_87 = V_87 ;
}
} else {
V_88 = V_84 [ V_100 ] ;
F_5 ( V_43 , L_35 ,
V_86 , V_25 , V_76 -> V_88 , V_88 ) ;
if ( V_25 & V_102 )
V_89 = V_76 -> V_88 ;
else
V_89 = V_88 ;
F_40 ( V_76 , V_76 -> V_88 , V_89 ,
& V_90 ) ;
F_42 ( & V_90 , V_85 ) ;
V_76 -> V_88 = V_88 ;
}
F_38:
F_47 (&reorder_list, pkt, pnext) {
F_48 ( V_85 , & V_90 ) ;
F_32 ( V_11 , V_85 ) ;
}
}
void F_49 ( struct V_65 * V_66 , struct V_38 * V_39 )
{
struct V_10 * V_11 ;
struct V_67 * V_44 = F_30 ( V_66 ) ;
struct V_1 * V_2 = V_44 -> V_2 ;
struct V_103 * V_104 ;
T_5 V_3 ;
int V_40 ;
F_5 ( V_43 , L_36 , F_50 ( V_66 ) , V_39 ) ;
V_40 = F_51 ( V_2 , true , & V_3 , V_39 ) ;
V_11 = V_2 -> V_5 [ V_3 ] ;
if ( V_40 || ! V_11 || ! V_11 -> V_6 ) {
if ( ( V_40 != - V_105 ) && V_11 )
V_11 -> V_56 . V_106 ++ ;
F_35 ( V_39 ) ;
return;
}
V_104 = (struct V_103 * ) V_39 -> V_107 ;
if ( V_104 -> V_108 )
F_44 ( V_11 , V_104 -> V_108 , V_39 ) ;
else
F_32 ( V_11 , V_39 ) ;
}
void F_52 ( struct V_1 * V_2 , struct V_38 * V_109 ,
bool V_110 )
{
struct V_10 * V_11 ;
struct V_41 * V_42 ;
T_5 V_3 ;
T_6 type ;
int V_111 ;
V_111 = F_51 ( V_2 , false , & V_3 , V_109 ) ;
V_11 = V_2 -> V_5 [ V_3 ] ;
if ( ! V_11 )
goto V_48;
if ( V_111 == 0 ) {
V_42 = (struct V_41 * ) ( V_109 -> V_112 ) ;
type = F_36 ( V_42 -> V_113 ) ;
if ( type == V_114 ) {
F_53 ( & V_11 -> V_115 ) ;
if ( F_54 ( & V_11 -> V_116 ) )
F_55 ( & V_11 -> V_116 ) ;
}
}
if ( ! V_110 )
V_11 -> V_56 . V_117 ++ ;
V_48:
F_35 ( V_109 ) ;
}
void F_56 ( struct V_65 * V_66 , struct V_38 * V_109 , bool V_110 )
{
struct V_67 * V_44 = F_30 ( V_66 ) ;
struct V_1 * V_2 = V_44 -> V_2 ;
if ( F_57 ( V_2 -> V_118 ) ) {
if ( ! V_110 )
F_58 ( V_2 -> V_118 , V_109 ) ;
} else {
F_52 ( V_2 , V_109 , V_110 ) ;
}
}
static struct V_119 * F_59 ( struct V_12 * V_6 )
{
struct V_10 * V_11 = F_16 ( V_6 ) ;
F_5 ( V_23 , L_6 , V_11 -> V_24 ) ;
return & V_11 -> V_56 ;
}
static void F_60 ( struct V_12 * V_6 ,
struct V_120 * V_121 )
{
struct V_10 * V_11 = F_16 ( V_6 ) ;
struct V_1 * V_2 = V_11 -> V_2 ;
F_61 ( V_121 -> V_122 , V_123 , sizeof( V_121 -> V_122 ) ) ;
snprintf ( V_121 -> V_124 , sizeof( V_121 -> V_124 ) , L_37 ) ;
F_61 ( V_121 -> V_125 , V_2 -> V_126 , sizeof( V_121 -> V_125 ) ) ;
F_61 ( V_121 -> V_127 , F_50 ( V_2 -> V_44 -> V_66 ) ,
sizeof( V_121 -> V_127 ) ) ;
}
static int F_62 ( struct V_12 * V_6 )
{
struct V_10 * V_11 = F_16 ( V_6 ) ;
F_5 ( V_23 , L_6 , V_11 -> V_24 ) ;
F_63 ( V_6 ) ;
F_20 ( V_6 ) ;
return 0 ;
}
static int F_64 ( struct V_12 * V_6 )
{
struct V_10 * V_11 = F_16 ( V_6 ) ;
struct V_1 * V_2 = V_11 -> V_2 ;
struct V_67 * V_44 = V_2 -> V_44 ;
T_1 V_128 ;
F_5 ( V_23 , L_6 , V_11 -> V_24 ) ;
if ( V_44 -> V_45 != V_46 ) {
F_2 ( L_38 ) ;
return - V_129 ;
}
F_65 ( & V_11 -> V_115 , 0 ) ;
if ( F_66 ( V_11 , L_39 , & V_128 ) >= 0
&& ( V_128 & V_130 ) != 0 )
V_6 -> V_131 |= V_132 ;
else
V_6 -> V_131 &= ~ V_132 ;
if ( F_67 ( V_6 ) ) {
F_2 ( L_40 ) ;
return - V_133 ;
}
F_68 ( V_6 ) ;
return 0 ;
}
int F_69 ( struct V_10 * V_11 , bool V_134 )
{
struct V_1 * V_2 = V_11 -> V_2 ;
struct V_12 * V_6 ;
T_3 V_21 ;
F_5 ( V_23 , L_41 , V_11 -> V_24 ,
V_11 -> V_33 ) ;
V_6 = V_11 -> V_6 ;
V_6 -> V_135 = & V_136 ;
V_6 -> V_137 += V_2 -> V_49 ;
V_6 -> V_138 = & V_139 ;
V_2 -> V_140 = V_6 -> V_141 + V_6 -> V_137 +
V_2 -> V_49 ;
memcpy ( V_6 -> V_34 , V_11 -> V_33 , V_27 ) ;
F_70 ( & V_11 -> V_32 , F_14 ) ;
F_70 ( & V_11 -> V_22 , F_3 ) ;
if ( V_134 )
V_21 = F_71 ( V_6 ) ;
else
V_21 = F_72 ( V_6 ) ;
if ( V_21 != 0 ) {
F_2 ( L_42 ) ;
goto V_142;
}
F_5 ( V_51 , L_43 , V_6 -> V_7 ) ;
V_6 -> V_143 = V_144 ;
return 0 ;
V_142:
V_2 -> V_5 [ V_11 -> V_24 ] = NULL ;
V_6 -> V_135 = NULL ;
F_73 ( V_6 ) ;
return - V_145 ;
}
static int F_74 ( struct V_12 * V_6 )
{
F_5 ( V_23 , L_20 ) ;
return F_67 ( V_6 ) ;
}
static int F_75 ( struct V_12 * V_6 )
{
F_5 ( V_23 , L_20 ) ;
return F_63 ( V_6 ) ;
}
static T_4 F_76 ( struct V_38 * V_39 ,
struct V_12 * V_6 )
{
if ( V_39 )
F_77 ( V_39 ) ;
return V_60 ;
}
static int F_78 ( struct V_10 * V_11 )
{
struct V_12 * V_6 ;
F_5 ( V_23 , L_41 , V_11 -> V_24 ,
V_11 -> V_33 ) ;
V_6 = V_11 -> V_6 ;
V_6 -> V_135 = & V_146 ;
memcpy ( V_6 -> V_34 , V_11 -> V_33 , V_27 ) ;
if ( F_72 ( V_6 ) != 0 ) {
F_2 ( L_44 ) ;
goto V_142;
}
F_5 ( V_51 , L_43 , V_6 -> V_7 ) ;
return 0 ;
V_142:
V_11 -> V_2 -> V_5 [ V_11 -> V_24 ] = NULL ;
V_6 -> V_135 = NULL ;
F_73 ( V_6 ) ;
return - V_145 ;
}
struct V_10 * F_79 ( struct V_1 * V_2 , T_3 V_24 , T_3 V_3 ,
char * V_7 , T_5 * V_33 )
{
struct V_10 * V_11 ;
struct V_12 * V_6 ;
F_5 ( V_23 , L_45 , V_24 , V_3 ) ;
V_11 = V_2 -> V_5 [ V_24 ] ;
if ( V_11 ) {
F_2 ( L_46 ,
V_11 -> V_6 -> V_7 ) ;
if ( V_3 ) {
F_20 ( V_11 -> V_6 ) ;
F_80 ( V_11 -> V_6 ) ;
F_73 ( V_11 -> V_6 ) ;
V_2 -> V_5 [ V_24 ] = NULL ;
} else {
F_2 ( L_47 ) ;
return F_81 ( - V_55 ) ;
}
}
if ( ! V_147 && V_24 == 1 ) {
F_5 ( V_51 , L_48 ) ;
V_11 = F_45 ( sizeof( * V_11 ) , V_148 ) ;
if ( ! V_11 )
return F_81 ( - V_53 ) ;
} else {
F_5 ( V_51 , L_49 ) ;
V_6 = F_82 ( sizeof( * V_11 ) , V_7 , V_149 ) ;
if ( ! V_6 )
return F_81 ( - V_53 ) ;
V_11 = F_16 ( V_6 ) ;
V_11 -> V_6 = V_6 ;
}
V_11 -> V_2 = V_2 ;
V_2 -> V_5 [ V_24 ] = V_11 ;
V_11 -> V_3 = V_3 ;
V_11 -> V_24 = V_24 ;
F_83 ( & V_11 -> V_116 ) ;
F_84 ( & V_11 -> V_64 ) ;
if ( V_33 != NULL )
memcpy ( V_11 -> V_33 , V_33 , V_27 ) ;
F_5 ( V_23 , L_50 ,
V_150 -> V_151 , V_7 , V_11 -> V_33 ) ;
return V_11 ;
}
void F_85 ( struct V_1 * V_2 , T_3 V_24 )
{
struct V_10 * V_11 ;
V_11 = V_2 -> V_5 [ V_24 ] ;
V_2 -> V_5 [ V_24 ] = NULL ;
if ( ! V_11 ) {
F_2 ( L_51 , V_24 ) ;
return;
}
F_5 ( V_23 , L_45 , V_24 , V_11 -> V_3 ) ;
if ( V_11 -> V_6 ) {
if ( V_24 == 0 ) {
if ( V_11 -> V_6 -> V_135 == & V_136 ) {
F_86 () ;
F_62 ( V_11 -> V_6 ) ;
F_87 () ;
}
} else {
F_20 ( V_11 -> V_6 ) ;
}
if ( V_11 -> V_6 -> V_135 == & V_136 ) {
F_88 ( & V_11 -> V_32 ) ;
F_88 ( & V_11 -> V_22 ) ;
}
F_80 ( V_11 -> V_6 ) ;
} else {
F_11 ( V_11 ) ;
}
}
int F_89 ( struct V_65 * V_66 )
{
struct V_1 * V_2 = NULL ;
int V_40 = 0 ;
F_5 ( V_23 , L_20 ) ;
V_2 = F_45 ( sizeof( struct V_1 ) , V_28 ) ;
if ( ! V_2 )
return - V_53 ;
F_90 ( & V_2 -> V_152 ) ;
V_2 -> V_49 = 0 ;
V_2 -> V_44 = F_30 ( V_66 ) ;
V_2 -> V_44 -> V_2 = V_2 ;
F_91 ( V_2 ) ;
V_40 = F_92 ( V_2 ) ;
if ( V_40 != 0 ) {
F_2 ( L_52 ) ;
goto V_142;
}
F_93 ( V_2 ) ;
return V_40 ;
V_142:
F_94 ( V_66 ) ;
return V_40 ;
}
int F_95 ( struct V_65 * V_66 )
{
int V_40 = - 1 ;
struct V_67 * V_44 = F_30 ( V_66 ) ;
struct V_1 * V_2 = V_44 -> V_2 ;
struct V_10 * V_11 ;
struct V_10 * V_153 ;
F_5 ( V_23 , L_53 ) ;
V_40 = F_96 ( V_44 ) ;
if ( V_40 != 0 ) {
F_2 ( L_54 , V_40 ) ;
return V_40 ;
}
V_11 = F_79 ( V_2 , 0 , 0 , L_55 , NULL ) ;
if ( F_97 ( V_11 ) )
return F_98 ( V_11 ) ;
if ( V_147 )
V_153 = F_79 ( V_2 , 1 , 0 , L_56 , NULL ) ;
else
V_153 = NULL ;
if ( F_97 ( V_153 ) )
V_153 = NULL ;
F_99 ( V_44 , V_46 ) ;
V_40 = F_100 ( V_11 ) ;
if ( V_40 < 0 )
goto V_142;
V_40 = F_101 ( V_2 ) ;
if ( V_40 < 0 )
goto V_142;
F_102 ( V_11 ) ;
V_2 -> V_154 = F_103 ( V_2 , V_44 -> V_66 ) ;
if ( V_2 -> V_154 == NULL ) {
V_40 = - V_53 ;
goto V_142;
}
V_40 = F_104 ( V_11 ) ;
if ( V_40 < 0 )
goto V_142;
V_40 = F_69 ( V_11 , false ) ;
V_142:
if ( V_40 < 0 ) {
F_2 ( L_57 , V_40 ) ;
F_105 ( V_2 -> V_154 ) ;
if ( V_2 -> V_118 ) {
F_106 ( V_11 ) ;
F_107 ( V_2 ) ;
}
if ( V_2 -> V_5 [ 0 ] ) {
F_73 ( V_11 -> V_6 ) ;
V_2 -> V_5 [ 0 ] = NULL ;
}
if ( V_153 ) {
F_73 ( V_153 -> V_6 ) ;
V_2 -> V_5 [ 1 ] = NULL ;
}
return V_40 ;
}
if ( ( V_147 ) && ( V_153 ) )
if ( F_78 ( V_153 ) < 0 )
V_147 = 0 ;
return 0 ;
}
void F_108 ( struct V_65 * V_66 , T_7 V_54 )
{
struct V_67 * V_44 = F_30 ( V_66 ) ;
struct V_1 * V_2 = V_44 -> V_2 ;
if ( V_2 ) {
V_2 -> V_49 += V_54 ;
}
}
static void F_109 ( struct V_1 * V_2 )
{
F_5 ( V_23 , L_20 ) ;
if ( V_2 ) {
F_110 ( V_2 -> V_44 ) ;
}
}
void F_111 ( struct V_65 * V_66 )
{
struct V_67 * V_44 = F_30 ( V_66 ) ;
struct V_1 * V_2 = V_44 -> V_2 ;
if ( V_2 == NULL )
return;
if ( V_2 -> V_5 [ 0 ] )
F_13 ( V_2 -> V_5 [ 0 ] , V_155 , 1 ) ;
}
void F_94 ( struct V_65 * V_66 )
{
T_3 V_156 ;
struct V_67 * V_44 = F_30 ( V_66 ) ;
struct V_1 * V_2 = V_44 -> V_2 ;
F_5 ( V_23 , L_20 ) ;
if ( V_2 == NULL )
return;
F_112 ( V_2 ) ;
F_99 ( V_44 , V_157 ) ;
for ( V_156 = V_4 - 1 ; V_156 > - 1 ; V_156 -- )
if ( V_2 -> V_5 [ V_156 ] ) {
F_106 ( V_2 -> V_5 [ V_156 ] ) ;
F_85 ( V_2 , V_156 ) ;
}
F_105 ( V_2 -> V_154 ) ;
F_107 ( V_2 ) ;
F_109 ( V_2 ) ;
F_113 ( V_2 ) ;
F_114 ( V_2 ) ;
V_44 -> V_2 = NULL ;
F_11 ( V_2 ) ;
}
T_3 F_115 ( struct V_65 * V_66 , char * V_7 , void * V_112 , T_1 V_54 )
{
struct V_67 * V_44 = F_30 ( V_66 ) ;
struct V_10 * V_11 = V_44 -> V_2 -> V_5 [ 0 ] ;
return F_10 ( V_11 , V_7 , V_112 , V_54 ) ;
}
static int F_116 ( struct V_10 * V_11 )
{
return F_117 ( & V_11 -> V_115 ) ;
}
int F_118 ( struct V_12 * V_6 )
{
struct V_10 * V_11 = F_16 ( V_6 ) ;
int V_21 ;
V_21 = F_119 ( V_11 -> V_116 ,
! F_116 ( V_11 ) ,
F_120 ( V_158 ) ) ;
F_46 ( ! V_21 ) ;
return ! V_21 ;
}
T_1 F_121 ( struct V_10 * V_11 )
{
struct V_67 * V_159 = V_11 -> V_2 -> V_44 ;
return V_159 -> V_160 << 4 | V_159 -> V_161 ;
}
static void F_122 ( struct V_8 * V_9 )
{
#ifdef F_123
F_124 () ;
#endif
#ifdef F_125
F_126 () ;
#endif
}
static int T_8 F_127 ( void )
{
F_128 () ;
#ifdef F_123
F_129 () ;
#endif
if ( ! F_17 ( & V_162 ) )
return - V_163 ;
return 0 ;
}
static void T_9 F_130 ( void )
{
F_88 ( & V_162 ) ;
#ifdef F_123
F_131 () ;
#endif
#ifdef F_125
F_132 () ;
#endif
F_133 () ;
}
