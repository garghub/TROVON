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
struct V_1 * F_2 ( struct V_1 * V_2 ,
T_1 V_11 , int V_12 )
{
struct V_13 * V_14 = NULL ;
F_3 ( L_1 , V_15 ,
V_2 , V_11 ) ;
V_2 -> V_11 = V_11 ;
if ( V_12 && F_4 ( V_2 ) ) {
V_14 = F_5 ( V_2 -> V_16 -> V_17 ) ;
if ( V_14 )
F_6 ( V_2 , V_14 ) ;
}
return V_2 ;
}
struct V_1 * F_7 ( struct V_1 * V_2 ,
struct V_18 * V_16 ,
T_2 V_19 , T_2 V_20 )
{
struct V_21 * V_17 = V_16 -> V_17 ;
T_3 V_4 ;
F_3 ( L_2 , V_15 ,
V_2 , V_16 ) ;
V_2 -> V_16 = V_16 ;
V_2 -> V_22 = V_19 ;
V_2 -> V_23 = V_20 ;
F_8 ( & V_2 -> V_24 ) ;
if ( V_17 ) {
struct V_25 * V_26 = F_9 ( V_17 -> V_27 . V_28 ) ;
V_4 = V_26 -> V_29 -> V_30 -> V_31 ;
} else {
V_4 = sizeof( struct V_32 ) ;
}
V_4 += sizeof( struct V_33 ) ;
V_2 -> V_4 = V_4 ;
F_1 ( V_2 ) ;
V_2 -> V_11 = 0 ;
V_2 -> V_34 = 0 ;
return V_2 ;
}
void F_10 ( struct V_1 * V_2 )
{
struct V_13 * V_14 , * V_35 ;
F_3 ( L_3 , V_15 , V_2 ) ;
F_11 (chunk, tmp, &packet->chunk_list, list) {
F_12 ( & V_14 -> V_36 ) ;
F_13 ( V_14 ) ;
}
if ( V_2 -> V_34 )
F_14 ( V_2 ) ;
}
T_4 F_15 ( struct V_1 * V_2 ,
struct V_13 * V_14 ,
int V_37 )
{
T_4 V_38 ;
int error = 0 ;
F_3 ( L_4 , V_15 ,
V_2 , V_14 ) ;
switch ( ( V_38 = ( F_6 ( V_2 , V_14 ) ) ) ) {
case V_39 :
if ( ! V_2 -> V_5 ) {
error = F_16 ( V_2 ) ;
if ( error < 0 )
V_14 -> V_40 -> V_28 -> V_41 = - error ;
if ( ! V_37 )
V_38 = F_6 ( V_2 ,
V_14 ) ;
}
break;
case V_42 :
case V_43 :
case V_44 :
break;
}
return V_38 ;
}
static T_4 F_17 ( struct V_1 * V_45 ,
struct V_13 * V_14 )
{
struct V_21 * V_17 = V_45 -> V_16 -> V_17 ;
struct V_13 * V_10 ;
T_4 V_38 = V_43 ;
if ( ! V_17 )
return V_38 ;
if ( V_14 -> V_46 -> type == V_47 || V_45 -> V_8 )
return V_38 ;
if ( ! V_14 -> V_10 )
return V_38 ;
V_10 = F_18 ( V_17 ) ;
if ( ! V_10 )
return V_38 ;
V_38 = F_6 ( V_45 , V_10 ) ;
return V_38 ;
}
static T_4 F_19 ( struct V_1 * V_45 ,
struct V_13 * V_14 )
{
T_4 V_38 = V_43 ;
if ( F_20 ( V_14 ) && ! V_45 -> V_6 &&
! V_45 -> V_5 ) {
struct V_21 * V_17 ;
struct V_48 * V_49 ;
V_17 = V_45 -> V_16 -> V_17 ;
V_49 = & V_17 -> V_50 [ V_51 ] ;
if ( F_21 ( V_49 ) ) {
struct V_13 * V_52 ;
if ( V_45 -> V_16 -> V_53 !=
V_45 -> V_16 -> V_17 -> V_54 . V_53 )
return V_38 ;
V_17 -> V_55 = V_17 -> V_56 ;
V_52 = F_22 ( V_17 ) ;
if ( V_52 ) {
V_38 = F_6 ( V_45 , V_52 ) ;
V_17 -> V_54 . V_57 = 0 ;
if ( F_23 ( V_49 ) )
F_24 ( V_17 ) ;
}
}
}
return V_38 ;
}
T_4 F_6 ( struct V_1 * V_2 ,
struct V_13 * V_14 )
{
T_4 V_38 = V_43 ;
T_2 V_58 = F_25 ( F_26 ( V_14 -> V_46 -> V_59 ) ) ;
F_3 ( L_4 , V_15 , V_2 ,
V_14 ) ;
if ( F_20 ( V_14 ) ) {
V_38 = F_27 ( V_2 , V_14 ) ;
if ( V_38 != V_43 )
goto V_60;
}
V_38 = F_17 ( V_2 , V_14 ) ;
if ( V_38 != V_43 )
goto V_60;
V_38 = F_19 ( V_2 , V_14 ) ;
if ( V_38 != V_43 )
goto V_60;
V_38 = F_28 ( V_2 , V_14 , V_58 ) ;
if ( V_38 != V_43 )
goto V_60;
switch ( V_14 -> V_46 -> type ) {
case V_61 :
F_29 ( V_2 , V_14 ) ;
V_2 -> V_6 = 1 ;
V_2 -> V_8 = 1 ;
V_2 -> V_7 = 1 ;
V_14 -> V_62 = V_63 ;
break;
case V_64 :
V_2 -> V_5 = 1 ;
break;
case V_65 :
V_2 -> V_6 = 1 ;
break;
case V_47 :
V_2 -> V_8 = 1 ;
V_2 -> V_10 = V_14 ;
break;
}
F_30 ( & V_14 -> V_36 , & V_2 -> V_24 ) ;
V_2 -> V_3 += V_58 ;
V_14 -> V_16 = V_2 -> V_16 ;
V_60:
return V_38 ;
}
int F_16 ( struct V_1 * V_2 )
{
struct V_18 * V_66 = V_2 -> V_16 ;
struct V_21 * V_17 = V_66 -> V_17 ;
struct V_33 * V_67 ;
struct V_68 * V_69 ;
struct V_13 * V_14 , * V_35 ;
struct V_70 * V_28 ;
int V_71 = 0 ;
int V_72 ;
T_5 V_7 = 0 ;
struct V_73 * V_74 = V_66 -> V_74 ;
unsigned char * V_10 = NULL ;
T_1 V_75 = sizeof( struct V_33 ) ;
F_3 ( L_3 , V_15 , V_2 ) ;
if ( F_31 ( & V_2 -> V_24 ) )
return V_71 ;
V_14 = F_32 ( V_2 -> V_24 . V_76 , struct V_13 , V_36 ) ;
V_28 = V_14 -> V_40 -> V_28 ;
V_69 = F_33 ( V_2 -> V_3 + V_77 , V_78 ) ;
if ( ! V_69 )
goto V_79;
F_34 ( V_69 , V_2 -> V_4 + V_77 ) ;
F_35 ( V_69 , V_28 ) ;
if ( ! F_36 ( V_66 ) ) {
F_37 ( V_66 , NULL , F_9 ( V_28 ) ) ;
if ( V_17 && ( V_17 -> V_80 & V_81 ) ) {
F_38 ( V_17 ) ;
}
}
V_74 = F_39 ( V_66 -> V_74 ) ;
F_40 ( V_69 , V_74 ) ;
if ( ! V_74 )
goto V_82;
V_67 = (struct V_33 * ) F_41 ( V_69 , sizeof( struct V_33 ) ) ;
F_42 ( V_69 ) ;
V_67 -> V_83 = F_43 ( V_2 -> V_22 ) ;
V_67 -> V_84 = F_43 ( V_2 -> V_23 ) ;
V_67 -> V_11 = F_44 ( V_2 -> V_11 ) ;
V_67 -> V_85 = 0 ;
F_3 ( L_5 ) ;
F_11 (chunk, tmp, &packet->chunk_list, list) {
F_12 ( & V_14 -> V_36 ) ;
if ( F_20 ( V_14 ) ) {
if ( ! V_66 -> V_86 ) {
V_14 -> V_87 = 1 ;
V_66 -> V_86 = 1 ;
}
V_7 = 1 ;
}
V_72 = F_25 ( V_14 -> V_40 -> V_88 ) - V_14 -> V_40 -> V_88 ;
if ( V_72 )
memset ( F_45 ( V_14 -> V_40 , V_72 ) , 0 , V_72 ) ;
if ( V_14 == V_2 -> V_10 )
V_10 = F_46 ( V_69 ) ;
V_75 += V_14 -> V_40 -> V_88 ;
memcpy ( F_45 ( V_69 , V_14 -> V_40 -> V_88 ) ,
V_14 -> V_40 -> V_89 , V_14 -> V_40 -> V_88 ) ;
F_3 ( L_6 ,
L_7 , V_14 ,
F_47 ( F_48 (
V_14 -> V_46 -> type ) ) ,
V_14 -> V_90 ? L_8 : L_9 ,
V_14 -> V_90 ?
F_49 ( V_14 -> V_91 . V_92 -> V_93 ) : 0 ,
L_10 , F_26 ( V_14 -> V_46 -> V_59 ) ,
L_11 , V_14 -> V_40 -> V_88 ,
L_12 , V_14 -> V_87 ) ;
if ( ! F_20 ( V_14 ) )
F_13 ( V_14 ) ;
}
if ( V_10 )
F_50 ( V_17 , V_69 ,
(struct V_94 * ) V_10 ,
V_78 ) ;
if ( ! V_95 ) {
if ( ! ( V_74 -> V_96 -> V_97 & V_98 ) ) {
T_1 V_99 = F_51 ( ( T_5 * ) V_67 , V_75 ) ;
V_67 -> V_85 = F_52 ( V_99 ) ;
} else {
V_69 -> V_100 = V_101 ;
V_69 -> V_102 = ( F_53 ( V_69 ) -
V_69 -> V_103 ) ;
V_69 -> V_104 = F_54 ( struct V_33 , V_85 ) ;
}
}
(* V_66 -> V_105 -> V_12 )( V_69 -> V_28 ) ;
if ( V_17 && V_17 -> V_54 . V_106 != V_66 ) {
V_17 -> V_54 . V_106 = V_66 ;
}
if ( V_7 ) {
struct V_48 * V_49 ;
unsigned long V_107 ;
if ( F_55 ( V_17 , V_108 ) && V_17 -> V_109 ) {
V_49 = & V_17 -> V_50 [ V_110 ] ;
V_107 = V_17 -> V_111 [ V_110 ] ;
if ( ! F_56 ( V_49 , V_63 + V_107 ) )
F_57 ( V_17 ) ;
}
}
F_3 ( L_13 ,
V_69 -> V_88 ) ;
V_69 -> V_112 = V_2 -> V_9 ;
(* V_66 -> V_105 -> V_113 )( V_69 , V_66 ) ;
V_114:
F_1 ( V_2 ) ;
return V_71 ;
V_82:
F_58 ( V_69 ) ;
F_59 ( & V_115 , V_116 ) ;
V_71:
F_11 (chunk, tmp, &packet->chunk_list, list) {
F_12 ( & V_14 -> V_36 ) ;
if ( ! F_20 ( V_14 ) )
F_13 ( V_14 ) ;
}
goto V_114;
V_79:
V_71 = - V_117 ;
goto V_71;
}
static T_4 F_27 ( struct V_1 * V_2 ,
struct V_13 * V_14 )
{
T_4 V_38 = V_43 ;
T_3 V_118 , V_56 , V_119 , V_120 ;
struct V_18 * V_16 = V_2 -> V_16 ;
struct V_21 * V_17 = V_16 -> V_17 ;
struct V_121 * V_122 = & V_17 -> V_123 ;
V_56 = V_17 -> V_54 . V_56 ;
V_119 = V_122 -> V_124 ;
V_120 = V_16 -> V_120 ;
V_118 = F_60 ( V_14 ) ;
if ( V_118 > V_56 ) {
if ( V_119 > 0 ) {
V_38 = V_42 ;
goto V_60;
}
}
if ( V_14 -> V_125 != V_126 )
if ( V_120 >= V_16 -> V_127 ) {
V_38 = V_42 ;
goto V_60;
}
if ( ! F_9 ( V_17 -> V_27 . V_28 ) -> V_128 && F_4 ( V_2 ) &&
V_119 && F_55 ( V_17 , V_108 ) ) {
unsigned int V_129 = V_16 -> V_130 - V_2 -> V_4 ;
unsigned int V_88 = V_14 -> V_40 -> V_88 + V_122 -> V_131 ;
if ( ( V_88 < V_129 ) && V_14 -> V_132 -> V_133 ) {
V_38 = V_44 ;
goto V_60;
}
}
V_60:
return V_38 ;
}
static void F_29 ( struct V_1 * V_2 ,
struct V_13 * V_14 )
{
struct V_18 * V_16 = V_2 -> V_16 ;
T_3 V_118 = F_60 ( V_14 ) ;
struct V_21 * V_17 = V_16 -> V_17 ;
T_6 V_56 = V_17 -> V_54 . V_56 ;
V_16 -> V_120 += V_118 ;
V_17 -> V_123 . V_124 += V_118 ;
if ( V_118 < V_56 )
V_56 -= V_118 ;
else
V_56 = 0 ;
V_17 -> V_54 . V_56 = V_56 ;
if ( ! V_17 -> V_54 . V_134 )
V_14 -> V_132 -> V_135 = 0 ;
F_61 ( V_14 ) ;
F_62 ( V_14 ) ;
}
static T_4 F_28 ( struct V_1 * V_2 ,
struct V_13 * V_14 ,
T_7 V_58 )
{
T_3 V_136 ;
T_3 V_137 ;
int V_138 ;
T_4 V_38 = V_43 ;
V_136 = V_2 -> V_3 ;
V_137 = ( ( V_2 -> V_16 -> V_17 ) ?
( V_2 -> V_16 -> V_17 -> V_130 ) :
( V_2 -> V_16 -> V_130 ) ) ;
V_138 = ( V_136 + V_58 > V_137 ) ;
if ( V_138 ) {
if ( F_4 ( V_2 ) || ! F_20 ( V_14 ) ||
( ! V_2 -> V_7 && V_14 -> V_10 ) ) {
V_2 -> V_9 = 1 ;
} else {
V_38 = V_39 ;
}
}
return V_38 ;
}
