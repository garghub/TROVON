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
V_38 = F_19 ( V_45 , V_10 ) ;
if ( V_38 != V_43 )
F_13 ( V_10 ) ;
return V_38 ;
}
static T_4 F_20 ( struct V_1 * V_45 ,
struct V_13 * V_14 )
{
T_4 V_38 = V_43 ;
if ( F_21 ( V_14 ) && ! V_45 -> V_6 &&
! V_45 -> V_5 ) {
struct V_21 * V_17 ;
struct V_48 * V_49 ;
V_17 = V_45 -> V_16 -> V_17 ;
V_49 = & V_17 -> V_50 [ V_51 ] ;
if ( F_22 ( V_49 ) ) {
struct V_13 * V_52 ;
if ( V_45 -> V_16 -> V_53 !=
V_45 -> V_16 -> V_17 -> V_54 . V_53 )
return V_38 ;
V_17 -> V_55 = V_17 -> V_56 ;
V_52 = F_23 ( V_17 ) ;
if ( V_52 ) {
V_38 = F_19 ( V_45 , V_52 ) ;
if ( V_38 != V_43 ) {
F_13 ( V_52 ) ;
goto V_57;
}
V_17 -> V_54 . V_58 = 0 ;
if ( F_24 ( V_49 ) )
F_25 ( V_17 ) ;
}
}
}
V_57:
return V_38 ;
}
static T_4 F_19 ( struct V_1 * V_2 ,
struct V_13 * V_14 )
{
T_4 V_38 = V_43 ;
T_2 V_59 = F_26 ( F_27 ( V_14 -> V_46 -> V_60 ) ) ;
V_38 = F_28 ( V_2 , V_14 , V_59 ) ;
if ( V_38 != V_43 )
goto V_61;
switch ( V_14 -> V_46 -> type ) {
case V_62 :
F_29 ( V_2 , V_14 ) ;
V_2 -> V_6 = 1 ;
V_2 -> V_8 = 1 ;
V_2 -> V_7 = 1 ;
V_14 -> V_63 = V_64 ;
break;
case V_65 :
V_2 -> V_5 = 1 ;
break;
case V_66 :
V_2 -> V_6 = 1 ;
break;
case V_47 :
V_2 -> V_8 = 1 ;
V_2 -> V_10 = V_14 ;
break;
}
F_30 ( & V_14 -> V_36 , & V_2 -> V_24 ) ;
V_2 -> V_3 += V_59 ;
V_14 -> V_16 = V_2 -> V_16 ;
V_61:
return V_38 ;
}
T_4 F_6 ( struct V_1 * V_2 ,
struct V_13 * V_14 )
{
T_4 V_38 = V_43 ;
F_3 ( L_4 , V_15 , V_2 ,
V_14 ) ;
if ( F_21 ( V_14 ) ) {
V_38 = F_31 ( V_2 , V_14 ) ;
if ( V_38 != V_43 )
goto V_61;
}
V_38 = F_17 ( V_2 , V_14 ) ;
if ( V_38 != V_43 )
goto V_61;
V_38 = F_20 ( V_2 , V_14 ) ;
if ( V_38 != V_43 )
goto V_61;
V_38 = F_19 ( V_2 , V_14 ) ;
V_61:
return V_38 ;
}
static void F_32 ( struct V_67 * V_40 )
{
F_33 ( V_40 -> V_28 ) ;
}
static void F_34 ( struct V_67 * V_40 , struct V_68 * V_28 )
{
F_35 ( V_40 ) ;
V_40 -> V_28 = V_28 ;
V_40 -> V_69 = F_32 ;
F_36 ( & V_28 -> V_70 ) ;
}
int F_16 ( struct V_1 * V_2 )
{
struct V_18 * V_71 = V_2 -> V_16 ;
struct V_21 * V_17 = V_71 -> V_17 ;
struct V_33 * V_72 ;
struct V_67 * V_73 ;
struct V_13 * V_14 , * V_35 ;
struct V_68 * V_28 ;
int V_74 = 0 ;
int V_75 ;
T_5 V_7 = 0 ;
struct V_76 * V_77 = V_71 -> V_77 ;
unsigned char * V_10 = NULL ;
T_1 V_78 = sizeof( struct V_33 ) ;
F_3 ( L_3 , V_15 , V_2 ) ;
if ( F_37 ( & V_2 -> V_24 ) )
return V_74 ;
V_14 = F_38 ( V_2 -> V_24 . V_79 , struct V_13 , V_36 ) ;
V_28 = V_14 -> V_40 -> V_28 ;
V_73 = F_39 ( V_2 -> V_3 + V_80 , V_81 ) ;
if ( ! V_73 )
goto V_82;
F_40 ( V_73 , V_2 -> V_4 + V_80 ) ;
F_34 ( V_73 , V_28 ) ;
if ( ! F_41 ( V_71 ) ) {
F_42 ( V_71 , NULL , F_9 ( V_28 ) ) ;
if ( V_17 && ( V_17 -> V_83 & V_84 ) ) {
F_43 ( V_28 , V_17 ) ;
}
}
V_77 = F_44 ( V_71 -> V_77 ) ;
F_45 ( V_73 , V_77 ) ;
if ( ! V_77 )
goto V_85;
V_72 = (struct V_33 * ) F_46 ( V_73 , sizeof( struct V_33 ) ) ;
F_47 ( V_73 ) ;
V_72 -> V_86 = F_48 ( V_2 -> V_22 ) ;
V_72 -> V_87 = F_48 ( V_2 -> V_23 ) ;
V_72 -> V_11 = F_49 ( V_2 -> V_11 ) ;
V_72 -> V_88 = 0 ;
F_3 ( L_5 ) ;
F_11 (chunk, tmp, &packet->chunk_list, list) {
F_12 ( & V_14 -> V_36 ) ;
if ( F_21 ( V_14 ) ) {
if ( ! V_71 -> V_89 ) {
V_14 -> V_90 = 1 ;
V_71 -> V_89 = 1 ;
}
V_7 = 1 ;
}
V_75 = F_26 ( V_14 -> V_40 -> V_91 ) - V_14 -> V_40 -> V_91 ;
if ( V_75 )
memset ( F_50 ( V_14 -> V_40 , V_75 ) , 0 , V_75 ) ;
if ( V_14 == V_2 -> V_10 )
V_10 = F_51 ( V_73 ) ;
V_78 += V_14 -> V_40 -> V_91 ;
memcpy ( F_50 ( V_73 , V_14 -> V_40 -> V_91 ) ,
V_14 -> V_40 -> V_92 , V_14 -> V_40 -> V_91 ) ;
F_3 ( L_6 ,
L_7 , V_14 ,
F_52 ( F_53 (
V_14 -> V_46 -> type ) ) ,
V_14 -> V_93 ? L_8 : L_9 ,
V_14 -> V_93 ?
F_54 ( V_14 -> V_94 . V_95 -> V_96 ) : 0 ,
L_10 , F_27 ( V_14 -> V_46 -> V_60 ) ,
L_11 , V_14 -> V_40 -> V_91 ,
L_12 , V_14 -> V_90 ) ;
if ( ! F_21 ( V_14 ) )
F_13 ( V_14 ) ;
}
if ( V_10 )
F_55 ( V_17 , V_73 ,
(struct V_97 * ) V_10 ,
V_81 ) ;
if ( ! V_98 ) {
if ( ! ( V_77 -> V_99 -> V_100 & V_101 ) ) {
T_1 V_102 = F_56 ( ( T_5 * ) V_72 , V_78 ) ;
V_72 -> V_88 = F_57 ( V_102 ) ;
} else {
V_73 -> V_103 = V_104 ;
V_73 -> V_105 = ( F_58 ( V_73 ) -
V_73 -> V_106 ) ;
V_73 -> V_107 = F_59 ( struct V_33 , V_88 ) ;
}
}
(* V_71 -> V_108 -> V_12 )( V_73 -> V_28 ) ;
if ( V_17 && V_17 -> V_54 . V_109 != V_71 ) {
V_17 -> V_54 . V_109 = V_71 ;
}
if ( V_7 ) {
struct V_48 * V_49 ;
unsigned long V_110 ;
if ( F_60 ( V_17 , V_111 ) && V_17 -> V_112 ) {
V_49 = & V_17 -> V_50 [ V_113 ] ;
V_110 = V_17 -> V_114 [ V_113 ] ;
if ( ! F_61 ( V_49 , V_64 + V_110 ) )
F_62 ( V_17 ) ;
}
}
F_3 ( L_13 ,
V_73 -> V_91 ) ;
V_73 -> V_115 = V_2 -> V_9 ;
(* V_71 -> V_108 -> V_116 )( V_73 , V_71 ) ;
V_57:
F_1 ( V_2 ) ;
return V_74 ;
V_85:
F_63 ( V_73 ) ;
F_64 ( F_65 ( V_17 -> V_27 . V_28 ) , V_117 ) ;
V_74:
F_11 (chunk, tmp, &packet->chunk_list, list) {
F_12 ( & V_14 -> V_36 ) ;
if ( ! F_21 ( V_14 ) )
F_13 ( V_14 ) ;
}
goto V_57;
V_82:
V_74 = - V_118 ;
goto V_74;
}
static T_4 F_31 ( struct V_1 * V_2 ,
struct V_13 * V_14 )
{
T_4 V_38 = V_43 ;
T_3 V_119 , V_56 , V_120 , V_121 ;
struct V_18 * V_16 = V_2 -> V_16 ;
struct V_21 * V_17 = V_16 -> V_17 ;
struct V_122 * V_123 = & V_17 -> V_124 ;
V_56 = V_17 -> V_54 . V_56 ;
V_120 = V_123 -> V_125 ;
V_121 = V_16 -> V_121 ;
V_119 = F_66 ( V_14 ) ;
if ( V_119 > V_56 ) {
if ( V_120 > 0 ) {
V_38 = V_42 ;
goto V_61;
}
}
if ( V_14 -> V_126 != V_127 )
if ( V_121 >= V_16 -> V_128 ) {
V_38 = V_42 ;
goto V_61;
}
if ( ! F_9 ( V_17 -> V_27 . V_28 ) -> V_129 && F_4 ( V_2 ) &&
V_120 && F_60 ( V_17 , V_111 ) ) {
unsigned int V_130 = V_16 -> V_131 - V_2 -> V_4 ;
unsigned int V_91 = V_14 -> V_40 -> V_91 + V_123 -> V_132 ;
if ( ( V_91 < V_130 ) && V_14 -> V_133 -> V_134 ) {
V_38 = V_44 ;
goto V_61;
}
}
V_61:
return V_38 ;
}
static void F_29 ( struct V_1 * V_2 ,
struct V_13 * V_14 )
{
struct V_18 * V_16 = V_2 -> V_16 ;
T_3 V_119 = F_66 ( V_14 ) ;
struct V_21 * V_17 = V_16 -> V_17 ;
T_6 V_56 = V_17 -> V_54 . V_56 ;
V_16 -> V_121 += V_119 ;
V_17 -> V_124 . V_125 += V_119 ;
if ( V_119 < V_56 )
V_56 -= V_119 ;
else
V_56 = 0 ;
V_17 -> V_54 . V_56 = V_56 ;
if ( ! V_17 -> V_54 . V_135 )
V_14 -> V_133 -> V_136 = 0 ;
F_67 ( V_14 ) ;
F_68 ( V_14 ) ;
}
static T_4 F_28 ( struct V_1 * V_2 ,
struct V_13 * V_14 ,
T_7 V_59 )
{
T_3 V_137 ;
T_3 V_138 ;
int V_139 ;
T_4 V_38 = V_43 ;
V_137 = V_2 -> V_3 ;
V_138 = ( ( V_2 -> V_16 -> V_17 ) ?
( V_2 -> V_16 -> V_17 -> V_131 ) :
( V_2 -> V_16 -> V_131 ) ) ;
V_139 = ( V_137 + V_59 > V_138 ) ;
if ( V_139 ) {
if ( F_4 ( V_2 ) || ! F_21 ( V_14 ) ||
( ! V_2 -> V_7 && V_14 -> V_10 ) ) {
V_2 -> V_9 = 1 ;
} else {
V_38 = V_39 ;
}
}
return V_38 ;
}
