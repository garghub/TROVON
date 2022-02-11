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
struct V_41 * V_42 = (struct V_41 * ) ( V_39 -> V_43 ) ;
F_5 ( V_44 , L_6 , V_11 -> V_24 ) ;
if ( V_2 -> V_45 -> V_46 != V_47 ) {
F_2 ( L_15 , V_2 -> V_45 -> V_46 ) ;
F_20 ( V_6 ) ;
F_21 ( V_39 ) ;
V_40 = - V_48 ;
goto V_49;
}
if ( ! V_2 -> V_5 [ V_11 -> V_24 ] ) {
F_2 ( L_16 , V_11 -> V_24 ) ;
F_20 ( V_6 ) ;
F_21 ( V_39 ) ;
V_40 = - V_48 ;
goto V_49;
}
if ( F_22 ( V_39 ) < V_2 -> V_50 ) {
struct V_38 * V_51 ;
F_5 ( V_52 , L_17 ,
F_1 ( V_2 , V_11 -> V_24 ) ) ;
V_2 -> V_45 -> V_53 ++ ;
V_51 = F_23 ( V_39 , V_2 -> V_50 ) ;
F_21 ( V_39 ) ;
V_39 = V_51 ;
if ( V_39 == NULL ) {
F_2 ( L_18 ,
F_1 ( V_2 , V_11 -> V_24 ) ) ;
V_40 = - V_54 ;
goto V_49;
}
}
if ( V_39 -> V_55 < sizeof( * V_42 ) ) {
V_40 = - V_56 ;
F_21 ( V_39 ) ;
goto V_49;
}
if ( V_42 -> V_57 == F_24 ( V_58 ) )
F_25 ( & V_11 -> V_59 ) ;
V_40 = F_26 ( V_11 , V_39 ) ;
V_49:
if ( V_40 ) {
V_11 -> V_60 . V_61 ++ ;
} else {
V_11 -> V_60 . V_62 ++ ;
V_11 -> V_60 . V_63 += V_39 -> V_55 ;
}
return V_64 ;
}
void F_27 ( struct V_10 * V_11 ,
enum V_65 V_66 , bool V_46 )
{
unsigned long V_25 ;
if ( ! V_11 || ! V_11 -> V_6 )
return;
F_5 ( V_23 , L_19 ,
V_11 -> V_24 , V_11 -> V_67 , V_66 , V_46 ) ;
F_28 ( & V_11 -> V_68 , V_25 ) ;
if ( V_46 ) {
if ( ! V_11 -> V_67 )
F_20 ( V_11 -> V_6 ) ;
V_11 -> V_67 |= V_66 ;
} else {
V_11 -> V_67 &= ~ V_66 ;
if ( ! V_11 -> V_67 )
F_29 ( V_11 -> V_6 ) ;
}
F_30 ( & V_11 -> V_68 , V_25 ) ;
}
void F_31 ( struct V_69 * V_70 , bool V_46 )
{
struct V_71 * V_45 = F_32 ( V_70 ) ;
struct V_1 * V_2 = V_45 -> V_2 ;
F_5 ( V_23 , L_20 ) ;
F_33 ( V_2 , V_46 ) ;
}
static void F_34 ( struct V_10 * V_11 , struct V_38 * V_39 )
{
V_39 -> V_70 = V_11 -> V_6 ;
V_39 -> V_72 = F_35 ( V_39 , V_39 -> V_70 ) ;
if ( V_39 -> V_73 == V_74 )
V_11 -> V_60 . V_75 ++ ;
F_36 ( V_11 -> V_2 , V_39 ) ;
if ( ! ( V_11 -> V_6 -> V_25 & V_76 ) ) {
F_37 ( V_39 ) ;
return;
}
V_11 -> V_60 . V_77 += V_39 -> V_55 ;
V_11 -> V_60 . V_78 ++ ;
F_5 ( V_44 , L_21 , F_38 ( V_39 -> V_72 ) ) ;
if ( F_39 () )
F_40 ( V_39 ) ;
else
F_41 ( V_39 ) ;
}
static void F_42 ( struct V_79 * V_80 ,
T_5 V_81 , T_5 V_82 ,
struct V_83 * V_84 )
{
F_43 ( V_84 ) ;
if ( V_80 -> V_85 == 0 ) {
F_5 ( V_52 , L_22 ) ;
return;
}
do {
if ( V_80 -> V_86 [ V_81 ] ) {
F_44 ( V_84 , V_80 -> V_86 [ V_81 ] ) ;
V_80 -> V_86 [ V_81 ] = NULL ;
}
V_81 ++ ;
if ( V_81 > V_80 -> V_87 )
V_81 = 0 ;
} while ( V_81 != V_82 );
V_80 -> V_85 -= F_45 ( V_84 ) ;
}
static void F_46 ( struct V_10 * V_11 , T_5 * V_88 ,
struct V_38 * V_89 )
{
T_5 V_90 , V_87 , V_91 , V_92 , V_93 ;
struct V_79 * V_80 ;
struct V_83 V_94 ;
struct V_38 * V_95 ;
T_5 V_25 ;
T_1 V_96 ;
V_90 = V_88 [ V_97 ] ;
V_25 = V_88 [ V_98 ] ;
if ( V_25 == 0xFF ) {
F_2 ( L_23 ) ;
F_34 ( V_11 , V_89 ) ;
return;
}
V_80 = V_11 -> V_2 -> V_99 [ V_90 ] ;
if ( V_25 & V_100 ) {
F_5 ( V_52 , L_24 ,
V_90 ) ;
if ( V_80 == NULL ) {
F_5 ( V_52 , L_25 ,
V_90 ) ;
F_34 ( V_11 , V_89 ) ;
return;
}
F_42 ( V_80 , V_80 -> V_92 , V_80 -> V_92 ,
& V_94 ) ;
F_44 ( & V_94 , V_89 ) ;
F_11 ( V_80 ) ;
V_11 -> V_2 -> V_99 [ V_90 ] = NULL ;
goto F_40;
}
if ( V_80 == NULL ) {
V_96 = sizeof( * V_80 ) ;
V_87 = V_88 [ V_101 ] ;
V_96 += ( V_87 + 1 ) * sizeof( V_89 ) ;
F_5 ( V_52 , L_26 ,
V_90 , V_87 ) ;
V_80 = F_47 ( V_96 , V_28 ) ;
if ( V_80 == NULL ) {
F_2 ( L_27 ) ;
F_34 ( V_11 , V_89 ) ;
return;
}
V_11 -> V_2 -> V_99 [ V_90 ] = V_80 ;
V_80 -> V_86 = (struct V_38 * * ) ( V_80 + 1 ) ;
V_80 -> V_87 = V_87 ;
}
if ( V_25 & V_102 ) {
if ( V_80 -> V_85 ) {
F_42 ( V_80 , V_80 -> V_92 ,
V_80 -> V_92 ,
& V_94 ) ;
F_48 ( V_80 -> V_85 ) ;
} else {
F_43 ( & V_94 ) ;
}
V_80 -> V_91 = V_88 [ V_103 ] ;
V_80 -> V_92 = V_88 [ V_104 ] ;
V_80 -> V_87 = V_88 [ V_101 ] ;
V_80 -> V_86 [ V_80 -> V_91 ] = V_89 ;
V_80 -> V_85 ++ ;
F_5 ( V_44 , L_28 ,
V_90 , V_80 -> V_91 , V_80 -> V_92 , V_80 -> V_85 ) ;
} else if ( V_25 & V_105 ) {
V_91 = V_88 [ V_103 ] ;
V_92 = V_88 [ V_104 ] ;
if ( ( V_92 == V_80 -> V_92 ) && ( V_91 != V_80 -> V_92 ) ) {
if ( V_80 -> V_86 [ V_91 ] != NULL ) {
F_5 ( V_52 , L_29 ) ;
F_37 ( V_80 -> V_86 [ V_91 ] ) ;
V_80 -> V_86 [ V_91 ] = NULL ;
}
V_80 -> V_86 [ V_91 ] = V_89 ;
V_80 -> V_85 ++ ;
V_80 -> V_91 = V_91 ;
F_5 ( V_44 , L_30 ,
V_90 , V_91 , V_92 , V_80 -> V_85 ) ;
return;
}
if ( V_80 -> V_92 == V_91 ) {
if ( V_80 -> V_86 [ V_91 ] != NULL ) {
F_5 ( V_52 , L_31 ) ;
F_37 ( V_80 -> V_86 [ V_91 ] ) ;
V_80 -> V_86 [ V_91 ] = NULL ;
}
V_80 -> V_86 [ V_91 ] = V_89 ;
V_80 -> V_85 ++ ;
F_5 ( V_44 , L_32 ,
V_90 , V_91 , V_92 , V_80 -> V_85 ) ;
V_80 -> V_91 = V_91 ;
V_80 -> V_92 = V_92 ;
F_42 ( V_80 , V_91 , V_92 ,
& V_94 ) ;
F_5 ( V_44 , L_33 ,
V_90 , F_45 ( & V_94 ) ,
V_80 -> V_85 ) ;
} else {
T_5 V_93 ;
F_5 ( V_44 , L_34 ,
V_90 , V_25 , V_80 -> V_91 , V_80 -> V_92 ,
V_91 , V_92 ) ;
if ( V_25 & V_106 )
V_93 = V_80 -> V_92 ;
else
V_93 = V_92 ;
F_42 ( V_80 , V_80 -> V_92 , V_93 ,
& V_94 ) ;
if ( V_92 == ( ( V_91 + 1 ) % ( V_80 -> V_87 + 1 ) ) ) {
F_44 ( & V_94 , V_89 ) ;
} else {
V_80 -> V_86 [ V_91 ] = V_89 ;
V_80 -> V_85 ++ ;
}
V_80 -> V_92 = V_92 ;
V_80 -> V_91 = V_91 ;
}
} else {
V_92 = V_88 [ V_104 ] ;
F_5 ( V_44 , L_35 ,
V_90 , V_25 , V_80 -> V_92 , V_92 ) ;
if ( V_25 & V_106 )
V_93 = V_80 -> V_92 ;
else
V_93 = V_92 ;
F_42 ( V_80 , V_80 -> V_92 , V_93 ,
& V_94 ) ;
F_44 ( & V_94 , V_89 ) ;
V_80 -> V_92 = V_92 ;
}
F_40:
F_49 (&reorder_list, pkt, pnext) {
F_50 ( V_89 , & V_94 ) ;
F_34 ( V_11 , V_89 ) ;
}
}
void F_51 ( struct V_69 * V_70 , struct V_38 * V_39 )
{
struct V_10 * V_11 ;
struct V_71 * V_45 = F_32 ( V_70 ) ;
struct V_1 * V_2 = V_45 -> V_2 ;
struct V_107 * V_108 ;
T_5 V_3 ;
int V_40 ;
F_5 ( V_44 , L_36 , F_52 ( V_70 ) , V_39 ) ;
V_40 = F_53 ( V_2 , true , & V_3 , V_39 ) ;
V_11 = V_2 -> V_5 [ V_3 ] ;
if ( V_40 || ! V_11 || ! V_11 -> V_6 ) {
if ( ( V_40 != - V_109 ) && V_11 )
V_11 -> V_60 . V_110 ++ ;
F_37 ( V_39 ) ;
return;
}
V_108 = (struct V_107 * ) V_39 -> V_111 ;
if ( V_108 -> V_112 )
F_46 ( V_11 , V_108 -> V_112 , V_39 ) ;
else
F_34 ( V_11 , V_39 ) ;
}
void F_54 ( struct V_1 * V_2 , struct V_38 * V_113 , T_5 V_3 ,
bool V_114 )
{
struct V_10 * V_11 ;
struct V_41 * V_42 ;
T_6 type ;
V_11 = V_2 -> V_5 [ V_3 ] ;
if ( ! V_11 )
goto V_49;
V_42 = (struct V_41 * ) ( V_113 -> V_43 ) ;
type = F_38 ( V_42 -> V_57 ) ;
if ( type == V_58 ) {
F_55 ( & V_11 -> V_59 ) ;
if ( F_56 ( & V_11 -> V_115 ) )
F_57 ( & V_11 -> V_115 ) ;
}
if ( ! V_114 )
V_11 -> V_60 . V_116 ++ ;
V_49:
F_37 ( V_113 ) ;
}
void F_58 ( struct V_69 * V_70 , struct V_38 * V_113 , bool V_114 )
{
struct V_71 * V_45 = F_32 ( V_70 ) ;
struct V_1 * V_2 = V_45 -> V_2 ;
T_5 V_3 ;
if ( F_59 ( V_2 -> V_117 ) ) {
if ( ! V_114 )
F_60 ( V_2 -> V_117 , V_113 ) ;
} else {
if ( F_53 ( V_2 , false , & V_3 , V_113 ) )
F_37 ( V_113 ) ;
else
F_54 ( V_2 , V_113 , V_3 , V_114 ) ;
}
}
static struct V_118 * F_61 ( struct V_12 * V_6 )
{
struct V_10 * V_11 = F_16 ( V_6 ) ;
F_5 ( V_23 , L_6 , V_11 -> V_24 ) ;
return & V_11 -> V_60 ;
}
static void F_62 ( struct V_12 * V_6 ,
struct V_119 * V_120 )
{
struct V_10 * V_11 = F_16 ( V_6 ) ;
struct V_1 * V_2 = V_11 -> V_2 ;
F_63 ( V_120 -> V_121 , V_122 , sizeof( V_120 -> V_121 ) ) ;
snprintf ( V_120 -> V_123 , sizeof( V_120 -> V_123 ) , L_37 ) ;
F_63 ( V_120 -> V_124 , V_2 -> V_125 , sizeof( V_120 -> V_124 ) ) ;
F_63 ( V_120 -> V_126 , F_52 ( V_2 -> V_45 -> V_70 ) ,
sizeof( V_120 -> V_126 ) ) ;
}
static int F_64 ( struct V_12 * V_6 )
{
struct V_10 * V_11 = F_16 ( V_6 ) ;
F_5 ( V_23 , L_6 , V_11 -> V_24 ) ;
F_65 ( V_6 ) ;
F_20 ( V_6 ) ;
return 0 ;
}
static int F_66 ( struct V_12 * V_6 )
{
struct V_10 * V_11 = F_16 ( V_6 ) ;
struct V_1 * V_2 = V_11 -> V_2 ;
struct V_71 * V_45 = V_2 -> V_45 ;
T_1 V_127 ;
F_5 ( V_23 , L_6 , V_11 -> V_24 ) ;
if ( V_45 -> V_46 != V_47 ) {
F_2 ( L_38 ) ;
return - V_128 ;
}
F_67 ( & V_11 -> V_59 , 0 ) ;
if ( F_68 ( V_11 , L_39 , & V_127 ) >= 0
&& ( V_127 & V_129 ) != 0 )
V_6 -> V_130 |= V_131 ;
else
V_6 -> V_130 &= ~ V_131 ;
if ( F_69 ( V_6 ) ) {
F_2 ( L_40 ) ;
return - V_132 ;
}
F_70 ( V_6 ) ;
return 0 ;
}
int F_71 ( struct V_10 * V_11 , bool V_133 )
{
struct V_1 * V_2 = V_11 -> V_2 ;
struct V_12 * V_6 ;
T_3 V_21 ;
F_5 ( V_23 , L_41 , V_11 -> V_24 ,
V_11 -> V_33 ) ;
V_6 = V_11 -> V_6 ;
V_6 -> V_134 = & V_135 ;
V_6 -> V_136 += V_2 -> V_50 ;
V_6 -> V_137 = & V_138 ;
V_2 -> V_139 = V_6 -> V_140 + V_6 -> V_136 +
V_2 -> V_50 ;
memcpy ( V_6 -> V_34 , V_11 -> V_33 , V_27 ) ;
F_72 ( & V_11 -> V_32 , F_14 ) ;
F_72 ( & V_11 -> V_22 , F_3 ) ;
if ( V_133 )
V_21 = F_73 ( V_6 ) ;
else
V_21 = F_74 ( V_6 ) ;
if ( V_21 != 0 ) {
F_2 ( L_42 ) ;
goto V_141;
}
F_5 ( V_52 , L_43 , V_6 -> V_7 ) ;
V_6 -> V_142 = V_143 ;
return 0 ;
V_141:
V_2 -> V_5 [ V_11 -> V_24 ] = NULL ;
V_6 -> V_134 = NULL ;
F_75 ( V_6 ) ;
return - V_144 ;
}
static int F_76 ( struct V_12 * V_6 )
{
F_5 ( V_23 , L_20 ) ;
return F_69 ( V_6 ) ;
}
static int F_77 ( struct V_12 * V_6 )
{
F_5 ( V_23 , L_20 ) ;
return F_65 ( V_6 ) ;
}
static T_4 F_78 ( struct V_38 * V_39 ,
struct V_12 * V_6 )
{
if ( V_39 )
F_79 ( V_39 ) ;
return V_64 ;
}
static int F_80 ( struct V_10 * V_11 )
{
struct V_12 * V_6 ;
F_5 ( V_23 , L_41 , V_11 -> V_24 ,
V_11 -> V_33 ) ;
V_6 = V_11 -> V_6 ;
V_6 -> V_134 = & V_145 ;
memcpy ( V_6 -> V_34 , V_11 -> V_33 , V_27 ) ;
if ( F_74 ( V_6 ) != 0 ) {
F_2 ( L_44 ) ;
goto V_141;
}
F_5 ( V_52 , L_43 , V_6 -> V_7 ) ;
return 0 ;
V_141:
V_11 -> V_2 -> V_5 [ V_11 -> V_24 ] = NULL ;
V_6 -> V_134 = NULL ;
F_75 ( V_6 ) ;
return - V_144 ;
}
struct V_10 * F_81 ( struct V_1 * V_2 , T_3 V_24 , T_3 V_3 ,
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
F_82 ( V_11 -> V_6 ) ;
F_75 ( V_11 -> V_6 ) ;
V_2 -> V_5 [ V_24 ] = NULL ;
} else {
F_2 ( L_47 ) ;
return F_83 ( - V_56 ) ;
}
}
if ( ! V_146 && V_24 == 1 ) {
F_5 ( V_52 , L_48 ) ;
V_11 = F_47 ( sizeof( * V_11 ) , V_147 ) ;
if ( ! V_11 )
return F_83 ( - V_54 ) ;
} else {
F_5 ( V_52 , L_49 ) ;
V_6 = F_84 ( sizeof( * V_11 ) , V_7 , V_148 ) ;
if ( ! V_6 )
return F_83 ( - V_54 ) ;
V_11 = F_16 ( V_6 ) ;
V_11 -> V_6 = V_6 ;
}
V_11 -> V_2 = V_2 ;
V_2 -> V_5 [ V_24 ] = V_11 ;
V_11 -> V_3 = V_3 ;
V_11 -> V_24 = V_24 ;
F_85 ( & V_11 -> V_115 ) ;
F_86 ( & V_11 -> V_68 ) ;
if ( V_33 != NULL )
memcpy ( V_11 -> V_33 , V_33 , V_27 ) ;
F_5 ( V_23 , L_50 ,
V_149 -> V_150 , V_7 , V_11 -> V_33 ) ;
return V_11 ;
}
void F_87 ( struct V_1 * V_2 , T_3 V_24 )
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
if ( V_11 -> V_6 -> V_134 == & V_135 ) {
F_88 () ;
F_64 ( V_11 -> V_6 ) ;
F_89 () ;
}
} else {
F_20 ( V_11 -> V_6 ) ;
}
if ( V_11 -> V_6 -> V_134 == & V_135 ) {
F_90 ( & V_11 -> V_32 ) ;
F_90 ( & V_11 -> V_22 ) ;
}
F_82 ( V_11 -> V_6 ) ;
} else {
F_11 ( V_11 ) ;
}
}
int F_91 ( struct V_69 * V_70 )
{
struct V_1 * V_2 = NULL ;
int V_40 = 0 ;
F_5 ( V_23 , L_20 ) ;
V_2 = F_47 ( sizeof( struct V_1 ) , V_28 ) ;
if ( ! V_2 )
return - V_54 ;
F_92 ( & V_2 -> V_151 ) ;
V_2 -> V_50 = 0 ;
V_2 -> V_45 = F_32 ( V_70 ) ;
V_2 -> V_45 -> V_2 = V_2 ;
F_93 ( V_2 ) ;
V_40 = F_94 ( V_2 ) ;
if ( V_40 != 0 ) {
F_2 ( L_52 ) ;
goto V_141;
}
F_95 ( V_2 ) ;
return V_40 ;
V_141:
F_96 ( V_70 ) ;
return V_40 ;
}
int F_97 ( struct V_69 * V_70 )
{
int V_40 = - 1 ;
struct V_71 * V_45 = F_32 ( V_70 ) ;
struct V_1 * V_2 = V_45 -> V_2 ;
struct V_10 * V_11 ;
struct V_10 * V_152 ;
F_5 ( V_23 , L_53 ) ;
V_11 = F_81 ( V_2 , 0 , 0 , L_54 , NULL ) ;
if ( F_98 ( V_11 ) )
return F_99 ( V_11 ) ;
if ( V_146 )
V_152 = F_81 ( V_2 , 1 , 0 , L_55 , NULL ) ;
else
V_152 = NULL ;
if ( F_98 ( V_152 ) )
V_152 = NULL ;
F_100 ( V_45 , V_47 ) ;
V_40 = F_101 ( V_11 ) ;
if ( V_40 < 0 )
goto V_141;
V_40 = F_102 ( V_2 ) ;
if ( V_40 < 0 )
goto V_141;
F_103 ( V_11 ) ;
V_2 -> V_153 = F_104 ( V_2 , V_45 -> V_70 ) ;
if ( V_2 -> V_153 == NULL ) {
V_40 = - V_54 ;
goto V_141;
}
V_40 = F_105 ( V_11 ) ;
if ( V_40 < 0 )
goto V_141;
V_40 = F_71 ( V_11 , false ) ;
V_141:
if ( V_40 < 0 ) {
F_2 ( L_56 , V_40 ) ;
F_106 ( V_2 -> V_153 ) ;
if ( V_2 -> V_117 ) {
F_107 ( V_11 ) ;
F_108 ( V_2 ) ;
}
if ( V_2 -> V_5 [ 0 ] ) {
F_75 ( V_11 -> V_6 ) ;
V_2 -> V_5 [ 0 ] = NULL ;
}
if ( V_152 ) {
F_75 ( V_152 -> V_6 ) ;
V_2 -> V_5 [ 1 ] = NULL ;
}
return V_40 ;
}
if ( ( V_146 ) && ( V_152 ) )
if ( F_80 ( V_152 ) < 0 )
V_146 = 0 ;
return 0 ;
}
void F_109 ( struct V_69 * V_70 , T_7 V_55 )
{
struct V_71 * V_45 = F_32 ( V_70 ) ;
struct V_1 * V_2 = V_45 -> V_2 ;
if ( V_2 ) {
V_2 -> V_50 += V_55 ;
}
}
static void F_110 ( struct V_1 * V_2 )
{
F_5 ( V_23 , L_20 ) ;
if ( V_2 ) {
F_111 ( V_2 -> V_45 ) ;
}
}
void F_112 ( struct V_69 * V_70 )
{
struct V_71 * V_45 = F_32 ( V_70 ) ;
struct V_1 * V_2 = V_45 -> V_2 ;
if ( V_2 == NULL )
return;
if ( V_2 -> V_5 [ 0 ] )
F_13 ( V_2 -> V_5 [ 0 ] , V_154 , 1 ) ;
}
void F_96 ( struct V_69 * V_70 )
{
T_3 V_155 ;
struct V_71 * V_45 = F_32 ( V_70 ) ;
struct V_1 * V_2 = V_45 -> V_2 ;
F_5 ( V_23 , L_20 ) ;
if ( V_2 == NULL )
return;
F_113 ( V_2 ) ;
F_100 ( V_45 , V_156 ) ;
for ( V_155 = V_4 - 1 ; V_155 > - 1 ; V_155 -- )
if ( V_2 -> V_5 [ V_155 ] ) {
F_107 ( V_2 -> V_5 [ V_155 ] ) ;
F_87 ( V_2 , V_155 ) ;
}
F_106 ( V_2 -> V_153 ) ;
F_108 ( V_2 ) ;
F_110 ( V_2 ) ;
F_114 ( V_2 ) ;
F_115 ( V_2 ) ;
V_45 -> V_2 = NULL ;
F_11 ( V_2 ) ;
}
T_3 F_116 ( struct V_69 * V_70 , char * V_7 , void * V_43 , T_1 V_55 )
{
struct V_71 * V_45 = F_32 ( V_70 ) ;
struct V_10 * V_11 = V_45 -> V_2 -> V_5 [ 0 ] ;
return F_10 ( V_11 , V_7 , V_43 , V_55 ) ;
}
static int F_117 ( struct V_10 * V_11 )
{
return F_118 ( & V_11 -> V_59 ) ;
}
int F_119 ( struct V_12 * V_6 )
{
struct V_10 * V_11 = F_16 ( V_6 ) ;
int V_21 ;
V_21 = F_120 ( V_11 -> V_115 ,
! F_117 ( V_11 ) ,
F_121 ( V_157 ) ) ;
F_48 ( ! V_21 ) ;
return ! V_21 ;
}
T_1 F_122 ( struct V_10 * V_11 )
{
struct V_71 * V_158 = V_11 -> V_2 -> V_45 ;
return V_158 -> V_159 << 4 | V_158 -> V_160 ;
}
static void F_123 ( struct V_8 * V_9 )
{
#ifdef F_124
F_125 () ;
#endif
#ifdef F_126
F_127 () ;
#endif
}
static int T_8 F_128 ( void )
{
F_129 () ;
#ifdef F_124
F_130 () ;
#endif
if ( ! F_17 ( & V_161 ) )
return - V_162 ;
return 0 ;
}
static void T_9 F_131 ( void )
{
F_90 ( & V_161 ) ;
#ifdef F_124
F_132 () ;
#endif
#ifdef F_126
F_133 () ;
#endif
F_134 () ;
}
