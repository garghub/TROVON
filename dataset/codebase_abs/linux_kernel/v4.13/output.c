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
T_4 F_24 ( struct V_1 * V_2 ,
struct V_26 * V_27 ,
int V_45 , T_5 V_46 )
{
T_4 V_47 ;
F_3 ( L_4 , V_20 ,
V_2 , V_2 -> V_3 , V_27 , V_27 -> V_48 ? V_27 -> V_48 -> V_49 : - 1 ) ;
switch ( ( V_47 = ( F_11 ( V_2 , V_27 ) ) ) ) {
case V_50 :
if ( ! V_2 -> V_5 ) {
int error = 0 ;
error = F_25 ( V_2 , V_46 ) ;
if ( error < 0 )
V_27 -> V_48 -> V_19 -> V_51 = - error ;
if ( ! V_45 )
V_47 = F_11 ( V_2 ,
V_27 ) ;
}
break;
case V_52 :
case V_53 :
case V_54 :
break;
}
return V_47 ;
}
static T_4 F_26 ( struct V_1 * V_55 ,
struct V_26 * V_27 )
{
struct V_16 * V_17 = V_55 -> V_15 -> V_17 ;
struct V_26 * V_10 ;
T_4 V_47 = V_53 ;
if ( ! V_17 )
return V_47 ;
if ( V_27 -> V_56 -> type == V_57 || V_55 -> V_8 )
return V_47 ;
if ( ! V_27 -> V_10 )
return V_47 ;
V_10 = F_27 ( V_17 ) ;
if ( ! V_10 )
return V_47 ;
V_47 = F_28 ( V_55 , V_10 ) ;
if ( V_47 != V_53 )
F_23 ( V_10 ) ;
return V_47 ;
}
static T_4 F_29 ( struct V_1 * V_55 ,
struct V_26 * V_27 )
{
T_4 V_47 = V_53 ;
if ( F_30 ( V_27 ) && ! V_55 -> V_6 &&
! V_55 -> V_5 ) {
struct V_16 * V_17 ;
struct V_58 * V_59 ;
V_17 = V_55 -> V_15 -> V_17 ;
V_59 = & V_17 -> V_60 [ V_61 ] ;
if ( F_31 ( V_59 ) ) {
struct V_26 * V_62 ;
if ( V_55 -> V_15 -> V_63 !=
V_55 -> V_15 -> V_17 -> V_64 . V_63 )
return V_47 ;
V_17 -> V_65 = V_17 -> V_66 ;
V_62 = F_32 ( V_17 ) ;
if ( V_62 ) {
V_47 = F_28 ( V_55 , V_62 ) ;
if ( V_47 != V_53 ) {
F_23 ( V_62 ) ;
goto V_67;
}
V_17 -> V_64 . V_68 = 0 ;
if ( F_33 ( V_59 ) )
F_34 ( V_17 ) ;
}
}
}
V_67:
return V_47 ;
}
static T_4 F_28 ( struct V_1 * V_2 ,
struct V_26 * V_27 )
{
T_4 V_47 = V_53 ;
T_2 V_69 = F_35 ( F_36 ( V_27 -> V_56 -> V_70 ) ) ;
V_47 = F_37 ( V_2 , V_27 , V_69 ) ;
if ( V_47 != V_53 )
goto V_71;
switch ( V_27 -> V_56 -> type ) {
case V_72 :
F_38 ( V_2 , V_27 ) ;
V_2 -> V_6 = 1 ;
V_2 -> V_8 = 1 ;
V_2 -> V_7 = 1 ;
V_27 -> V_73 = V_74 ;
V_27 -> V_75 ++ ;
break;
case V_76 :
V_2 -> V_5 = 1 ;
break;
case V_77 :
V_2 -> V_6 = 1 ;
if ( V_27 -> V_17 )
V_27 -> V_17 -> V_78 . V_79 ++ ;
break;
case V_57 :
V_2 -> V_8 = 1 ;
V_2 -> V_10 = V_27 ;
break;
}
F_39 ( & V_27 -> V_44 , & V_2 -> V_35 ) ;
V_2 -> V_3 += V_69 ;
V_27 -> V_15 = V_2 -> V_15 ;
V_71:
return V_47 ;
}
T_4 F_11 ( struct V_1 * V_2 ,
struct V_26 * V_27 )
{
T_4 V_47 = V_53 ;
F_3 ( L_5 , V_20 , V_2 , V_27 ) ;
if ( F_30 ( V_27 ) ) {
V_47 = F_40 ( V_2 , V_27 ) ;
if ( V_47 != V_53 )
goto V_71;
}
V_47 = F_26 ( V_2 , V_27 ) ;
if ( V_47 != V_53 )
goto V_71;
V_47 = F_29 ( V_2 , V_27 ) ;
if ( V_47 != V_53 )
goto V_71;
V_47 = F_28 ( V_2 , V_27 ) ;
V_71:
return V_47 ;
}
static void F_41 ( struct V_80 * V_48 )
{
F_42 ( V_48 -> V_19 ) ;
}
static void F_43 ( struct V_80 * V_48 , struct V_18 * V_19 )
{
F_44 ( V_48 ) ;
V_48 -> V_19 = V_19 ;
V_48 -> V_81 = F_41 ;
F_45 ( & V_19 -> V_82 ) ;
}
static int F_46 ( struct V_1 * V_2 ,
struct V_80 * V_83 , int V_84 , T_5 V_46 )
{
struct V_13 * V_14 = V_2 -> V_15 ;
struct V_85 * V_10 = NULL ;
struct V_26 * V_27 , * V_43 ;
int V_86 = 0 , V_87 ;
struct V_18 * V_19 = V_83 -> V_19 ;
struct V_80 * V_88 ;
int V_89 = 0 ;
if ( V_84 ) {
F_47 ( V_83 ) -> V_90 = V_19 -> V_91 ;
F_48 ( V_83 ) -> V_92 = V_83 ;
} else {
V_88 = V_83 ;
V_87 = V_2 -> V_3 ;
goto V_93;
}
do {
V_87 = V_2 -> V_4 ;
F_21 (chunk, tmp, &packet->chunk_list,
list) {
int V_94 = F_35 ( V_27 -> V_48 -> V_49 ) ;
if ( V_27 == V_2 -> V_10 )
V_89 = V_94 ;
else if ( V_89 + V_94 + V_2 -> V_4 >
V_14 -> V_22 )
return 0 ;
else if ( V_87 + V_94 > V_14 -> V_22 )
break;
V_87 += V_94 ;
}
V_88 = F_49 ( V_87 + V_95 , V_46 ) ;
if ( ! V_88 )
return 0 ;
F_50 ( V_88 , V_2 -> V_4 + V_95 ) ;
V_93:
V_87 -= V_2 -> V_4 ;
F_21 (chunk, tmp, &packet->chunk_list, list) {
int V_96 ;
F_22 ( & V_27 -> V_44 ) ;
if ( F_30 ( V_27 ) ) {
if ( ! F_51 ( V_27 ) &&
! V_14 -> V_97 ) {
V_27 -> V_98 = 1 ;
V_14 -> V_97 = 1 ;
}
}
V_96 = F_35 ( V_27 -> V_48 -> V_49 ) - V_27 -> V_48 -> V_49 ;
if ( V_96 )
F_52 ( V_27 -> V_48 , V_96 ) ;
if ( V_27 == V_2 -> V_10 )
V_10 = (struct V_85 * )
F_53 ( V_88 ) ;
F_54 ( V_88 , V_27 -> V_48 -> V_99 , V_27 -> V_48 -> V_49 ) ;
F_3 ( L_6 ,
V_27 ,
F_55 ( F_56 ( V_27 -> V_56 -> type ) ) ,
V_27 -> V_100 ? L_7 : L_8 ,
V_27 -> V_100 ? F_57 ( V_27 -> V_101 . V_102 -> V_103 ) : 0 ,
F_36 ( V_27 -> V_56 -> V_70 ) , V_27 -> V_48 -> V_49 ,
V_27 -> V_98 ) ;
V_87 -= F_35 ( V_27 -> V_48 -> V_49 ) ;
if ( ! F_30 ( V_27 ) && V_27 != V_2 -> V_10 )
F_23 ( V_27 ) ;
if ( ! V_87 )
break;
}
if ( V_10 ) {
F_58 ( V_14 -> V_17 , V_88 , V_10 , V_46 ) ;
if ( F_59 ( & V_2 -> V_35 ) )
F_23 ( V_2 -> V_10 ) ;
else
F_60 ( & V_2 -> V_10 -> V_44 ,
& V_2 -> V_35 ) ;
}
if ( V_84 ) {
if ( F_61 ( & V_83 , V_88 ) ) {
F_62 ( V_88 ) ;
return 0 ;
}
if ( F_63 ( F_47 ( V_83 ) -> V_104 >=
V_19 -> V_105 ) )
return 0 ;
}
V_86 ++ ;
} while ( ! F_59 ( & V_2 -> V_35 ) );
if ( V_84 ) {
memset ( V_83 -> V_106 , 0 , F_64 ( sizeof( struct V_107 ) ,
sizeof( struct V_108 ) ) ) ;
F_47 ( V_83 ) -> V_104 = V_86 ;
F_47 ( V_83 ) -> V_109 = V_110 ;
F_12 () ;
if ( F_65 ( V_83 ) != V_14 -> V_28 ) {
F_14 ( V_14 -> V_28 ) ;
F_15 ( V_19 , V_14 -> V_28 ) ;
}
F_17 () ;
goto V_111;
}
if ( V_112 )
return 1 ;
if ( ! ( F_65 ( V_83 ) -> V_29 -> V_113 & V_114 ) ||
F_66 ( F_65 ( V_83 ) ) || V_2 -> V_9 ) {
struct V_42 * V_115 =
(struct V_42 * ) F_67 ( V_83 ) ;
V_115 -> V_116 = F_68 ( V_83 , 0 ) ;
} else {
V_111:
V_83 -> V_117 = V_118 ;
V_83 -> V_119 = 1 ;
V_83 -> V_120 = F_67 ( V_83 ) - V_83 -> V_83 ;
V_83 -> V_121 = F_69 ( struct V_42 , V_116 ) ;
}
return V_86 ;
}
int F_25 ( struct V_1 * V_2 , T_5 V_46 )
{
struct V_13 * V_14 = V_2 -> V_15 ;
struct V_16 * V_17 = V_14 -> V_17 ;
struct V_26 * V_27 , * V_43 ;
int V_86 , V_84 = 0 ;
struct V_122 * V_28 ;
struct V_80 * V_83 ;
struct V_42 * V_115 ;
struct V_18 * V_19 ;
F_3 ( L_3 , V_20 , V_2 ) ;
if ( F_59 ( & V_2 -> V_35 ) )
return 0 ;
V_27 = F_70 ( V_2 -> V_35 . V_123 , struct V_26 , V_44 ) ;
V_19 = V_27 -> V_48 -> V_19 ;
if ( V_2 -> V_3 > V_14 -> V_22 && ! V_2 -> V_9 ) {
if ( ! F_16 ( V_19 ) ) {
F_71 ( L_9 ) ;
goto V_67;
}
V_84 = 1 ;
}
V_83 = F_49 ( ( V_84 ? V_2 -> V_4 : V_2 -> V_3 ) +
V_95 , V_46 ) ;
if ( ! V_83 )
goto V_67;
F_50 ( V_83 , V_2 -> V_4 + V_95 ) ;
F_43 ( V_83 , V_19 ) ;
V_115 = F_72 ( V_83 , sizeof( struct V_42 ) ) ;
F_73 ( V_83 ) ;
V_115 -> V_124 = F_74 ( V_2 -> V_33 ) ;
V_115 -> V_125 = F_74 ( V_2 -> V_34 ) ;
V_115 -> V_11 = F_75 ( V_2 -> V_11 ) ;
V_115 -> V_116 = 0 ;
V_28 = F_76 ( V_14 -> V_28 ) ;
if ( ! V_28 ) {
F_77 ( F_78 ( V_19 ) , V_126 ) ;
F_62 ( V_83 ) ;
goto V_67;
}
F_79 ( V_83 , V_28 ) ;
V_86 = F_46 ( V_2 , V_83 , V_84 , V_46 ) ;
if ( ! V_86 ) {
F_62 ( V_83 ) ;
goto V_67;
}
F_3 ( L_10 , V_83 -> V_49 ) ;
if ( V_2 -> V_7 && F_80 ( V_17 , V_127 ) &&
V_17 -> V_128 [ V_129 ] ) {
struct V_58 * V_59 =
& V_17 -> V_60 [ V_129 ] ;
unsigned long V_130 =
V_17 -> V_128 [ V_129 ] ;
if ( ! F_81 ( V_59 , V_74 + V_130 ) )
F_82 ( V_17 ) ;
}
V_14 -> V_131 -> V_12 ( V_19 ) ;
if ( V_17 ) {
V_17 -> V_78 . V_132 += V_86 ;
if ( V_17 -> V_64 . V_133 != V_14 )
V_17 -> V_64 . V_133 = V_14 ;
}
V_83 -> V_134 = V_2 -> V_9 ;
if ( V_14 -> V_135 )
F_83 ( V_83 , 1 ) ;
if ( V_14 -> V_131 -> V_136 ( V_83 , V_14 ) >= 0 &&
V_14 -> V_135 )
V_14 -> V_135 = 0 ;
V_67:
F_21 (chunk, tmp, &packet->chunk_list, list) {
F_22 ( & V_27 -> V_44 ) ;
if ( ! F_30 ( V_27 ) )
F_23 ( V_27 ) ;
}
F_1 ( V_2 ) ;
return 0 ;
}
static T_4 F_40 ( struct V_1 * V_2 ,
struct V_26 * V_27 )
{
T_3 V_137 , V_66 , V_138 , V_139 ;
struct V_13 * V_15 = V_2 -> V_15 ;
struct V_16 * V_17 = V_15 -> V_17 ;
struct V_140 * V_141 = & V_17 -> V_142 ;
V_66 = V_17 -> V_64 . V_66 ;
V_138 = V_141 -> V_143 ;
V_139 = V_15 -> V_139 ;
V_137 = F_84 ( V_27 ) ;
if ( V_137 > V_66 && V_138 > 0 )
return V_52 ;
if ( V_27 -> V_144 != V_145 &&
V_139 >= V_15 -> V_146 )
return V_52 ;
if ( ( F_7 ( V_17 -> V_23 . V_19 ) -> V_147 || V_138 == 0 ) &&
! V_17 -> V_148 )
return V_53 ;
if ( ! F_4 ( V_2 ) )
return V_53 ;
if ( ! F_80 ( V_17 , V_127 ) )
return V_53 ;
if ( V_27 -> V_48 -> V_49 + V_141 -> V_149 > V_15 -> V_22 -
V_2 -> V_4 - sizeof( struct V_150 ) - 4 )
return V_53 ;
if ( ! V_27 -> V_151 -> V_152 )
return V_53 ;
return V_54 ;
}
static void F_38 ( struct V_1 * V_2 ,
struct V_26 * V_27 )
{
struct V_13 * V_15 = V_2 -> V_15 ;
T_3 V_137 = F_84 ( V_27 ) ;
struct V_16 * V_17 = V_15 -> V_17 ;
T_6 V_66 = V_17 -> V_64 . V_66 ;
V_15 -> V_139 += V_137 ;
V_17 -> V_142 . V_143 += V_137 ;
if ( V_137 < V_66 )
V_66 -= V_137 ;
else
V_66 = 0 ;
V_17 -> V_64 . V_66 = V_66 ;
F_85 ( V_27 ) ;
F_86 ( V_27 ) ;
}
static T_4 F_37 ( struct V_1 * V_2 ,
struct V_26 * V_27 ,
T_7 V_69 )
{
T_3 V_153 , V_154 , V_155 ;
T_4 V_47 = V_53 ;
V_153 = V_2 -> V_3 ;
if ( V_2 -> V_15 -> V_17 )
V_154 = V_2 -> V_15 -> V_17 -> V_22 ;
else
V_154 = V_2 -> V_15 -> V_22 ;
if ( V_153 + V_69 > V_154 ) {
if ( F_4 ( V_2 ) ||
( ! V_2 -> V_7 && V_27 -> V_10 ) ) {
V_2 -> V_9 = 1 ;
goto V_67;
}
V_155 = V_154 - V_2 -> V_4 ;
if ( V_2 -> V_10 )
V_155 -= F_35 ( V_2 -> V_10 -> V_48 -> V_49 ) ;
if ( V_69 > V_155 )
V_47 = V_50 ;
if ( ! F_30 ( V_27 ) && V_2 -> V_7 )
V_47 = V_50 ;
if ( V_153 + V_69 > V_2 -> V_21 )
V_47 = V_50 ;
if ( ! V_2 -> V_15 -> V_156 &&
V_153 + V_69 > ( V_2 -> V_15 -> V_146 >> 1 ) )
V_47 = V_50 ;
if ( V_2 -> V_15 -> V_156 &&
V_153 + V_69 > ( V_2 -> V_15 -> V_156 >> 1 ) )
V_47 = V_50 ;
}
V_67:
return V_47 ;
}
