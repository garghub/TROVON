static void F_1 ( struct V_1 * V_2 )
{
V_2 -> V_3 = V_2 -> V_4 ;
V_2 -> V_5 = 0 ;
V_2 -> V_6 = 0 ;
V_2 -> V_7 = 0 ;
V_2 -> V_8 = 0 ;
V_2 -> V_9 = 0 ;
V_2 -> V_10 = NULL ;
}
void F_2 ( struct V_1 * V_2 , T_1 V_11 ,
int V_12 )
{
struct V_13 * V_14 = V_2 -> V_15 ;
struct V_16 * V_17 = V_14 -> V_17 ;
struct V_18 * V_19 ;
F_3 ( L_1 , V_20 , V_2 , V_11 ) ;
V_2 -> V_11 = V_11 ;
if ( ! F_4 ( V_2 ) )
return;
V_2 -> V_21 = V_14 -> V_22 ;
if ( ! V_17 )
return;
V_19 = V_17 -> V_23 . V_19 ;
if ( ! F_5 ( V_14 ) ) {
F_6 ( V_14 , NULL , F_7 ( V_19 ) ) ;
if ( V_17 -> V_24 & V_25 )
F_8 ( V_17 ) ;
} else if ( ! F_9 ( V_14 ) ) {
if ( V_17 -> V_24 & V_25 )
F_8 ( V_17 ) ;
}
if ( V_12 ) {
struct V_26 * V_27 = F_10 ( V_17 ) ;
if ( V_27 )
F_11 ( V_2 , V_27 ) ;
}
if ( ! V_14 -> V_28 )
return;
F_12 () ;
if ( F_13 ( V_19 ) != V_14 -> V_28 ) {
F_14 ( V_14 -> V_28 ) ;
F_15 ( V_19 , V_14 -> V_28 ) ;
}
V_2 -> V_21 = F_16 ( V_19 ) ? V_14 -> V_28 -> V_29 -> V_30
: V_17 -> V_22 ;
F_17 () ;
}
void F_18 ( struct V_1 * V_2 ,
struct V_13 * V_15 ,
T_2 V_31 , T_2 V_32 )
{
struct V_16 * V_17 = V_15 -> V_17 ;
T_3 V_4 ;
F_3 ( L_2 , V_20 , V_2 , V_15 ) ;
V_2 -> V_15 = V_15 ;
V_2 -> V_33 = V_31 ;
V_2 -> V_34 = V_32 ;
F_19 ( & V_2 -> V_35 ) ;
if ( V_17 ) {
struct V_36 * V_37 = F_7 ( V_17 -> V_23 . V_19 ) ;
V_4 = V_37 -> V_38 -> V_39 -> V_40 ;
} else {
V_4 = sizeof( struct V_41 ) ;
}
V_4 += sizeof( struct V_42 ) ;
V_2 -> V_4 = V_4 ;
F_1 ( V_2 ) ;
V_2 -> V_11 = 0 ;
}
void F_20 ( struct V_1 * V_2 )
{
struct V_26 * V_27 , * V_43 ;
F_3 ( L_3 , V_20 , V_2 ) ;
F_21 (chunk, tmp, &packet->chunk_list, list) {
F_22 ( & V_27 -> V_44 ) ;
F_23 ( V_27 ) ;
}
}
enum V_45 F_24 ( struct V_1 * V_2 ,
struct V_26 * V_27 ,
int V_46 , T_4 V_47 )
{
enum V_45 V_48 ;
F_3 ( L_4 , V_20 ,
V_2 , V_2 -> V_3 , V_27 , V_27 -> V_49 ? V_27 -> V_49 -> V_50 : - 1 ) ;
switch ( ( V_48 = ( F_11 ( V_2 , V_27 ) ) ) ) {
case V_51 :
if ( ! V_2 -> V_5 ) {
int error = 0 ;
error = F_25 ( V_2 , V_47 ) ;
if ( error < 0 )
V_27 -> V_49 -> V_19 -> V_52 = - error ;
if ( ! V_46 )
V_48 = F_11 ( V_2 ,
V_27 ) ;
}
break;
case V_53 :
case V_54 :
case V_55 :
break;
}
return V_48 ;
}
static enum V_45 F_26 ( struct V_1 * V_56 ,
struct V_26 * V_27 )
{
struct V_16 * V_17 = V_56 -> V_15 -> V_17 ;
enum V_45 V_48 = V_54 ;
struct V_26 * V_10 ;
if ( ! V_17 )
return V_48 ;
if ( V_27 -> V_57 -> type == V_58 || V_56 -> V_8 )
return V_48 ;
if ( ! V_27 -> V_10 )
return V_48 ;
V_10 = F_27 ( V_17 ) ;
if ( ! V_10 )
return V_48 ;
V_48 = F_28 ( V_56 , V_10 ) ;
if ( V_48 != V_54 )
F_23 ( V_10 ) ;
return V_48 ;
}
static enum V_45 F_29 ( struct V_1 * V_56 ,
struct V_26 * V_27 )
{
enum V_45 V_48 = V_54 ;
if ( F_30 ( V_27 ) && ! V_56 -> V_6 &&
! V_56 -> V_5 ) {
struct V_16 * V_17 ;
struct V_59 * V_60 ;
V_17 = V_56 -> V_15 -> V_17 ;
V_60 = & V_17 -> V_61 [ V_62 ] ;
if ( F_31 ( V_60 ) ) {
struct V_26 * V_63 ;
if ( V_56 -> V_15 -> V_64 !=
V_56 -> V_15 -> V_17 -> V_65 . V_64 )
return V_48 ;
V_17 -> V_66 = V_17 -> V_67 ;
V_63 = F_32 ( V_17 ) ;
if ( V_63 ) {
V_48 = F_28 ( V_56 , V_63 ) ;
if ( V_48 != V_54 ) {
F_23 ( V_63 ) ;
goto V_68;
}
V_17 -> V_65 . V_69 = 0 ;
if ( F_33 ( V_60 ) )
F_34 ( V_17 ) ;
}
}
}
V_68:
return V_48 ;
}
static enum V_45 F_28 ( struct V_1 * V_2 ,
struct V_26 * V_27 )
{
T_2 V_70 = F_35 ( F_36 ( V_27 -> V_57 -> V_71 ) ) ;
enum V_45 V_48 = V_54 ;
V_48 = F_37 ( V_2 , V_27 , V_70 ) ;
if ( V_48 != V_54 )
goto V_72;
switch ( V_27 -> V_57 -> type ) {
case V_73 :
F_38 ( V_2 , V_27 ) ;
V_2 -> V_6 = 1 ;
V_2 -> V_8 = 1 ;
V_2 -> V_7 = 1 ;
V_27 -> V_74 = V_75 ;
V_27 -> V_76 ++ ;
break;
case V_77 :
V_2 -> V_5 = 1 ;
break;
case V_78 :
V_2 -> V_6 = 1 ;
if ( V_27 -> V_17 )
V_27 -> V_17 -> V_79 . V_80 ++ ;
break;
case V_58 :
V_2 -> V_8 = 1 ;
V_2 -> V_10 = V_27 ;
break;
}
F_39 ( & V_27 -> V_44 , & V_2 -> V_35 ) ;
V_2 -> V_3 += V_70 ;
V_27 -> V_15 = V_2 -> V_15 ;
V_72:
return V_48 ;
}
enum V_45 F_11 ( struct V_1 * V_2 ,
struct V_26 * V_27 )
{
enum V_45 V_48 = V_54 ;
F_3 ( L_5 , V_20 , V_2 , V_27 ) ;
if ( F_30 ( V_27 ) ) {
V_48 = F_40 ( V_2 , V_27 ) ;
if ( V_48 != V_54 )
goto V_72;
}
V_48 = F_26 ( V_2 , V_27 ) ;
if ( V_48 != V_54 )
goto V_72;
V_48 = F_29 ( V_2 , V_27 ) ;
if ( V_48 != V_54 )
goto V_72;
V_48 = F_28 ( V_2 , V_27 ) ;
V_72:
return V_48 ;
}
static void F_41 ( struct V_81 * V_49 )
{
F_42 ( V_49 -> V_19 ) ;
}
static void F_43 ( struct V_81 * V_49 , struct V_18 * V_19 )
{
F_44 ( V_49 ) ;
V_49 -> V_19 = V_19 ;
V_49 -> V_82 = F_41 ;
F_45 ( & V_19 -> V_83 ) ;
}
static int F_46 ( struct V_1 * V_2 ,
struct V_81 * V_84 , int V_85 , T_4 V_47 )
{
struct V_13 * V_14 = V_2 -> V_15 ;
struct V_86 * V_10 = NULL ;
struct V_26 * V_27 , * V_43 ;
int V_87 = 0 , V_88 ;
struct V_18 * V_19 = V_84 -> V_19 ;
struct V_81 * V_89 ;
int V_90 = 0 ;
if ( V_85 ) {
F_47 ( V_84 ) -> V_91 = V_19 -> V_92 ;
F_48 ( V_84 ) -> V_93 = V_84 ;
} else {
V_89 = V_84 ;
V_88 = V_2 -> V_3 ;
goto V_94;
}
do {
V_88 = V_2 -> V_4 ;
F_21 (chunk, tmp, &packet->chunk_list,
list) {
int V_95 = F_35 ( V_27 -> V_49 -> V_50 ) ;
if ( V_27 == V_2 -> V_10 )
V_90 = V_95 ;
else if ( V_90 + V_95 + V_2 -> V_4 >
V_14 -> V_22 )
return 0 ;
else if ( V_88 + V_95 > V_14 -> V_22 )
break;
V_88 += V_95 ;
}
V_89 = F_49 ( V_88 + V_96 , V_47 ) ;
if ( ! V_89 )
return 0 ;
F_50 ( V_89 , V_2 -> V_4 + V_96 ) ;
V_94:
V_88 -= V_2 -> V_4 ;
F_21 (chunk, tmp, &packet->chunk_list, list) {
int V_97 ;
F_22 ( & V_27 -> V_44 ) ;
if ( F_30 ( V_27 ) ) {
if ( ! F_51 ( V_27 ) &&
! V_14 -> V_98 ) {
V_27 -> V_99 = 1 ;
V_14 -> V_98 = 1 ;
}
}
V_97 = F_35 ( V_27 -> V_49 -> V_50 ) - V_27 -> V_49 -> V_50 ;
if ( V_97 )
F_52 ( V_27 -> V_49 , V_97 ) ;
if ( V_27 == V_2 -> V_10 )
V_10 = (struct V_86 * )
F_53 ( V_89 ) ;
F_54 ( V_89 , V_27 -> V_49 -> V_100 , V_27 -> V_49 -> V_50 ) ;
F_3 ( L_6 ,
V_27 ,
F_55 ( F_56 ( V_27 -> V_57 -> type ) ) ,
V_27 -> V_101 ? L_7 : L_8 ,
V_27 -> V_101 ? F_57 ( V_27 -> V_102 . V_103 -> V_104 ) : 0 ,
F_36 ( V_27 -> V_57 -> V_71 ) , V_27 -> V_49 -> V_50 ,
V_27 -> V_99 ) ;
V_88 -= F_35 ( V_27 -> V_49 -> V_50 ) ;
if ( ! F_30 ( V_27 ) && V_27 != V_2 -> V_10 )
F_23 ( V_27 ) ;
if ( ! V_88 )
break;
}
if ( V_10 ) {
F_58 ( V_14 -> V_17 , V_89 , V_10 , V_47 ) ;
if ( F_59 ( & V_2 -> V_35 ) )
F_23 ( V_2 -> V_10 ) ;
else
F_60 ( & V_2 -> V_10 -> V_44 ,
& V_2 -> V_35 ) ;
}
if ( V_85 ) {
if ( F_61 ( & V_84 , V_89 ) ) {
F_62 ( V_89 ) ;
return 0 ;
}
if ( F_63 ( F_47 ( V_84 ) -> V_105 >=
V_19 -> V_106 ) )
return 0 ;
}
V_87 ++ ;
} while ( ! F_59 ( & V_2 -> V_35 ) );
if ( V_85 ) {
memset ( V_84 -> V_107 , 0 , F_64 ( sizeof( struct V_108 ) ,
sizeof( struct V_109 ) ) ) ;
F_47 ( V_84 ) -> V_105 = V_87 ;
F_47 ( V_84 ) -> V_110 = V_111 ;
F_12 () ;
if ( F_65 ( V_84 ) != V_14 -> V_28 ) {
F_14 ( V_14 -> V_28 ) ;
F_15 ( V_19 , V_14 -> V_28 ) ;
}
F_17 () ;
goto V_112;
}
if ( V_113 )
return 1 ;
if ( ! ( F_65 ( V_84 ) -> V_29 -> V_114 & V_115 ) ||
F_66 ( F_65 ( V_84 ) ) || V_2 -> V_9 ) {
struct V_42 * V_116 =
(struct V_42 * ) F_67 ( V_84 ) ;
V_116 -> V_117 = F_68 ( V_84 , 0 ) ;
} else {
V_112:
V_84 -> V_118 = V_119 ;
V_84 -> V_120 = 1 ;
V_84 -> V_121 = F_67 ( V_84 ) - V_84 -> V_84 ;
V_84 -> V_122 = F_69 ( struct V_42 , V_117 ) ;
}
return V_87 ;
}
int F_25 ( struct V_1 * V_2 , T_4 V_47 )
{
struct V_13 * V_14 = V_2 -> V_15 ;
struct V_16 * V_17 = V_14 -> V_17 ;
struct V_26 * V_27 , * V_43 ;
int V_87 , V_85 = 0 ;
struct V_123 * V_28 ;
struct V_81 * V_84 ;
struct V_42 * V_116 ;
struct V_18 * V_19 ;
F_3 ( L_3 , V_20 , V_2 ) ;
if ( F_59 ( & V_2 -> V_35 ) )
return 0 ;
V_27 = F_70 ( V_2 -> V_35 . V_124 , struct V_26 , V_44 ) ;
V_19 = V_27 -> V_49 -> V_19 ;
if ( V_2 -> V_3 > V_14 -> V_22 && ! V_2 -> V_9 ) {
if ( ! F_16 ( V_19 ) ) {
F_71 ( L_9 ) ;
goto V_68;
}
V_85 = 1 ;
}
V_84 = F_49 ( ( V_85 ? V_2 -> V_4 : V_2 -> V_3 ) +
V_96 , V_47 ) ;
if ( ! V_84 )
goto V_68;
F_50 ( V_84 , V_2 -> V_4 + V_96 ) ;
F_43 ( V_84 , V_19 ) ;
V_116 = F_72 ( V_84 , sizeof( struct V_42 ) ) ;
F_73 ( V_84 ) ;
V_116 -> V_125 = F_74 ( V_2 -> V_33 ) ;
V_116 -> V_126 = F_74 ( V_2 -> V_34 ) ;
V_116 -> V_11 = F_75 ( V_2 -> V_11 ) ;
V_116 -> V_117 = 0 ;
V_28 = F_76 ( V_14 -> V_28 ) ;
if ( ! V_28 ) {
F_77 ( F_78 ( V_19 ) , V_127 ) ;
F_62 ( V_84 ) ;
goto V_68;
}
F_79 ( V_84 , V_28 ) ;
V_87 = F_46 ( V_2 , V_84 , V_85 , V_47 ) ;
if ( ! V_87 ) {
F_62 ( V_84 ) ;
goto V_68;
}
F_3 ( L_10 , V_84 -> V_50 ) ;
if ( V_2 -> V_7 && F_80 ( V_17 , V_128 ) &&
V_17 -> V_129 [ V_130 ] ) {
struct V_59 * V_60 =
& V_17 -> V_61 [ V_130 ] ;
unsigned long V_131 =
V_17 -> V_129 [ V_130 ] ;
if ( ! F_81 ( V_60 , V_75 + V_131 ) )
F_82 ( V_17 ) ;
}
V_14 -> V_132 -> V_12 ( V_19 ) ;
if ( V_17 ) {
V_17 -> V_79 . V_133 += V_87 ;
if ( V_17 -> V_65 . V_134 != V_14 )
V_17 -> V_65 . V_134 = V_14 ;
}
V_84 -> V_135 = V_2 -> V_9 ;
if ( V_14 -> V_136 )
F_83 ( V_84 , 1 ) ;
if ( V_14 -> V_132 -> V_45 ( V_84 , V_14 ) >= 0 &&
V_14 -> V_136 )
V_14 -> V_136 = 0 ;
V_68:
F_21 (chunk, tmp, &packet->chunk_list, list) {
F_22 ( & V_27 -> V_44 ) ;
if ( ! F_30 ( V_27 ) )
F_23 ( V_27 ) ;
}
F_1 ( V_2 ) ;
return 0 ;
}
static enum V_45 F_40 ( struct V_1 * V_2 ,
struct V_26 * V_27 )
{
T_3 V_137 , V_67 , V_138 , V_139 ;
struct V_13 * V_15 = V_2 -> V_15 ;
struct V_16 * V_17 = V_15 -> V_17 ;
struct V_140 * V_141 = & V_17 -> V_142 ;
V_67 = V_17 -> V_65 . V_67 ;
V_138 = V_141 -> V_143 ;
V_139 = V_15 -> V_139 ;
V_137 = F_84 ( V_27 ) ;
if ( V_137 > V_67 && V_138 > 0 )
return V_53 ;
if ( V_27 -> V_144 != V_145 &&
V_139 >= V_15 -> V_146 )
return V_53 ;
if ( ( F_7 ( V_17 -> V_23 . V_19 ) -> V_147 || V_138 == 0 ) &&
! V_17 -> V_148 )
return V_54 ;
if ( ! F_4 ( V_2 ) )
return V_54 ;
if ( ! F_80 ( V_17 , V_128 ) )
return V_54 ;
if ( V_27 -> V_49 -> V_50 + V_141 -> V_149 > V_15 -> V_22 -
V_2 -> V_4 - sizeof( struct V_150 ) - 4 )
return V_54 ;
if ( ! V_27 -> V_151 -> V_152 )
return V_54 ;
return V_55 ;
}
static void F_38 ( struct V_1 * V_2 ,
struct V_26 * V_27 )
{
struct V_13 * V_15 = V_2 -> V_15 ;
T_3 V_137 = F_84 ( V_27 ) ;
struct V_16 * V_17 = V_15 -> V_17 ;
T_5 V_67 = V_17 -> V_65 . V_67 ;
V_15 -> V_139 += V_137 ;
V_17 -> V_142 . V_143 += V_137 ;
if ( V_137 < V_67 )
V_67 -= V_137 ;
else
V_67 = 0 ;
V_17 -> V_65 . V_67 = V_67 ;
F_85 ( V_27 ) ;
F_86 ( V_27 ) ;
}
static enum V_45 F_37 ( struct V_1 * V_2 ,
struct V_26 * V_27 ,
T_6 V_70 )
{
enum V_45 V_48 = V_54 ;
T_3 V_153 , V_154 , V_155 ;
V_153 = V_2 -> V_3 ;
if ( V_2 -> V_15 -> V_17 )
V_154 = V_2 -> V_15 -> V_17 -> V_22 ;
else
V_154 = V_2 -> V_15 -> V_22 ;
if ( V_153 + V_70 > V_154 ) {
if ( F_4 ( V_2 ) ||
( ! V_2 -> V_7 && V_27 -> V_10 ) ) {
V_2 -> V_9 = 1 ;
goto V_68;
}
V_155 = V_154 - V_2 -> V_4 ;
if ( V_2 -> V_10 )
V_155 -= F_35 ( V_2 -> V_10 -> V_49 -> V_50 ) ;
if ( V_70 > V_155 )
V_48 = V_51 ;
if ( ! F_30 ( V_27 ) && V_2 -> V_7 )
V_48 = V_51 ;
if ( V_153 + V_70 > V_2 -> V_21 )
V_48 = V_51 ;
if ( ! V_2 -> V_15 -> V_156 &&
V_153 + V_70 > ( V_2 -> V_15 -> V_146 >> 1 ) )
V_48 = V_51 ;
if ( V_2 -> V_15 -> V_156 &&
V_153 + V_70 > ( V_2 -> V_15 -> V_156 >> 1 ) )
V_48 = V_51 ;
}
V_68:
return V_48 ;
}
