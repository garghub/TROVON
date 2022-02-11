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
F_3 ( L_1 , V_15 , V_2 , V_11 ) ;
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
F_3 ( L_2 , V_15 , V_2 , V_16 ) ;
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
return V_2 ;
}
void F_10 ( struct V_1 * V_2 )
{
struct V_13 * V_14 , * V_34 ;
F_3 ( L_3 , V_15 , V_2 ) ;
F_11 (chunk, tmp, &packet->chunk_list, list) {
F_12 ( & V_14 -> V_35 ) ;
F_13 ( V_14 ) ;
}
}
T_4 F_14 ( struct V_1 * V_2 ,
struct V_13 * V_14 ,
int V_36 )
{
T_4 V_37 ;
int error = 0 ;
F_3 ( L_4 , V_15 , V_2 , V_14 ) ;
switch ( ( V_37 = ( F_6 ( V_2 , V_14 ) ) ) ) {
case V_38 :
if ( ! V_2 -> V_5 ) {
error = F_15 ( V_2 ) ;
if ( error < 0 )
V_14 -> V_39 -> V_28 -> V_40 = - error ;
if ( ! V_36 )
V_37 = F_6 ( V_2 ,
V_14 ) ;
}
break;
case V_41 :
case V_42 :
case V_43 :
break;
}
return V_37 ;
}
static T_4 F_16 ( struct V_1 * V_44 ,
struct V_13 * V_14 )
{
struct V_21 * V_17 = V_44 -> V_16 -> V_17 ;
struct V_13 * V_10 ;
T_4 V_37 = V_42 ;
if ( ! V_17 )
return V_37 ;
if ( V_14 -> V_45 -> type == V_46 || V_44 -> V_8 )
return V_37 ;
if ( ! V_14 -> V_10 )
return V_37 ;
V_10 = F_17 ( V_17 ) ;
if ( ! V_10 )
return V_37 ;
V_37 = F_18 ( V_44 , V_10 ) ;
if ( V_37 != V_42 )
F_13 ( V_10 ) ;
return V_37 ;
}
static T_4 F_19 ( struct V_1 * V_44 ,
struct V_13 * V_14 )
{
T_4 V_37 = V_42 ;
if ( F_20 ( V_14 ) && ! V_44 -> V_6 &&
! V_44 -> V_5 ) {
struct V_21 * V_17 ;
struct V_47 * V_48 ;
V_17 = V_44 -> V_16 -> V_17 ;
V_48 = & V_17 -> V_49 [ V_50 ] ;
if ( F_21 ( V_48 ) ) {
struct V_13 * V_51 ;
if ( V_44 -> V_16 -> V_52 !=
V_44 -> V_16 -> V_17 -> V_53 . V_52 )
return V_37 ;
V_17 -> V_54 = V_17 -> V_55 ;
V_51 = F_22 ( V_17 ) ;
if ( V_51 ) {
V_37 = F_18 ( V_44 , V_51 ) ;
if ( V_37 != V_42 ) {
F_13 ( V_51 ) ;
goto V_56;
}
V_17 -> V_53 . V_57 = 0 ;
if ( F_23 ( V_48 ) )
F_24 ( V_17 ) ;
}
}
}
V_56:
return V_37 ;
}
static T_4 F_18 ( struct V_1 * V_2 ,
struct V_13 * V_14 )
{
T_4 V_37 = V_42 ;
T_2 V_58 = F_25 ( F_26 ( V_14 -> V_45 -> V_59 ) ) ;
V_37 = F_27 ( V_2 , V_14 , V_58 ) ;
if ( V_37 != V_42 )
goto V_60;
switch ( V_14 -> V_45 -> type ) {
case V_61 :
F_28 ( V_2 , V_14 ) ;
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
if ( V_14 -> V_17 )
V_14 -> V_17 -> V_66 . V_67 ++ ;
break;
case V_46 :
V_2 -> V_8 = 1 ;
V_2 -> V_10 = V_14 ;
break;
}
F_29 ( & V_14 -> V_35 , & V_2 -> V_24 ) ;
V_2 -> V_3 += V_58 ;
V_14 -> V_16 = V_2 -> V_16 ;
V_60:
return V_37 ;
}
T_4 F_6 ( struct V_1 * V_2 ,
struct V_13 * V_14 )
{
T_4 V_37 = V_42 ;
F_3 ( L_4 , V_15 , V_2 , V_14 ) ;
if ( F_20 ( V_14 ) ) {
V_37 = F_30 ( V_2 , V_14 ) ;
if ( V_37 != V_42 )
goto V_60;
}
V_37 = F_16 ( V_2 , V_14 ) ;
if ( V_37 != V_42 )
goto V_60;
V_37 = F_19 ( V_2 , V_14 ) ;
if ( V_37 != V_42 )
goto V_60;
V_37 = F_18 ( V_2 , V_14 ) ;
V_60:
return V_37 ;
}
static void F_31 ( struct V_68 * V_39 )
{
F_32 ( V_39 -> V_28 ) ;
}
static void F_33 ( struct V_68 * V_39 , struct V_69 * V_28 )
{
F_34 ( V_39 ) ;
V_39 -> V_28 = V_28 ;
V_39 -> V_70 = F_31 ;
F_35 ( & V_28 -> V_71 ) ;
}
int F_15 ( struct V_1 * V_2 )
{
struct V_18 * V_72 = V_2 -> V_16 ;
struct V_21 * V_17 = V_72 -> V_17 ;
struct V_33 * V_73 ;
struct V_68 * V_74 ;
struct V_13 * V_14 , * V_34 ;
struct V_69 * V_28 ;
int V_75 = 0 ;
int V_76 ;
T_5 V_7 = 0 ;
struct V_77 * V_78 = V_72 -> V_78 ;
unsigned char * V_10 = NULL ;
T_1 V_79 = sizeof( struct V_33 ) ;
F_3 ( L_3 , V_15 , V_2 ) ;
if ( F_36 ( & V_2 -> V_24 ) )
return V_75 ;
V_14 = F_37 ( V_2 -> V_24 . V_80 , struct V_13 , V_35 ) ;
V_28 = V_14 -> V_39 -> V_28 ;
V_74 = F_38 ( V_2 -> V_3 + V_81 , V_82 ) ;
if ( ! V_74 )
goto V_83;
F_39 ( V_74 , V_2 -> V_4 + V_81 ) ;
F_33 ( V_74 , V_28 ) ;
if ( ! F_40 ( V_72 ) ) {
F_41 ( V_72 , NULL , F_9 ( V_28 ) ) ;
if ( V_17 && ( V_17 -> V_84 & V_85 ) ) {
F_42 ( V_28 , V_17 ) ;
}
}
V_78 = F_43 ( V_72 -> V_78 ) ;
F_44 ( V_74 , V_78 ) ;
if ( ! V_78 )
goto V_86;
V_73 = (struct V_33 * ) F_45 ( V_74 , sizeof( struct V_33 ) ) ;
F_46 ( V_74 ) ;
V_73 -> V_87 = F_47 ( V_2 -> V_22 ) ;
V_73 -> V_88 = F_47 ( V_2 -> V_23 ) ;
V_73 -> V_11 = F_48 ( V_2 -> V_11 ) ;
V_73 -> V_89 = 0 ;
F_3 ( L_5 ) ;
F_11 (chunk, tmp, &packet->chunk_list, list) {
F_12 ( & V_14 -> V_35 ) ;
if ( F_20 ( V_14 ) ) {
if ( ! V_72 -> V_90 ) {
V_14 -> V_91 = 1 ;
V_72 -> V_90 = 1 ;
}
V_7 = 1 ;
}
V_76 = F_25 ( V_14 -> V_39 -> V_92 ) - V_14 -> V_39 -> V_92 ;
if ( V_76 )
memset ( F_49 ( V_14 -> V_39 , V_76 ) , 0 , V_76 ) ;
if ( V_14 == V_2 -> V_10 )
V_10 = F_50 ( V_74 ) ;
V_79 += V_14 -> V_39 -> V_92 ;
memcpy ( F_49 ( V_74 , V_14 -> V_39 -> V_92 ) ,
V_14 -> V_39 -> V_93 , V_14 -> V_39 -> V_92 ) ;
F_3 ( L_6
L_7 , V_14 ,
F_51 ( F_52 ( V_14 -> V_45 -> type ) ) ,
V_14 -> V_94 ? L_8 : L_9 ,
V_14 -> V_94 ? F_53 ( V_14 -> V_95 . V_96 -> V_97 ) : 0 ,
F_26 ( V_14 -> V_45 -> V_59 ) , V_14 -> V_39 -> V_92 ,
V_14 -> V_91 ) ;
if ( ! F_20 ( V_14 ) )
F_13 ( V_14 ) ;
}
if ( V_10 )
F_54 ( V_17 , V_74 ,
(struct V_98 * ) V_10 ,
V_82 ) ;
if ( ! V_99 ) {
if ( ! ( V_78 -> V_100 -> V_101 & V_102 ) ||
( F_55 ( V_78 ) != NULL ) || V_2 -> V_9 ) {
T_1 V_103 = F_56 ( ( T_5 * ) V_73 , V_79 ) ;
V_73 -> V_89 = F_57 ( V_103 ) ;
} else {
V_74 -> V_104 = V_105 ;
V_74 -> V_106 = ( F_58 ( V_74 ) -
V_74 -> V_107 ) ;
V_74 -> V_108 = F_59 ( struct V_33 , V_89 ) ;
}
}
(* V_72 -> V_109 -> V_12 )( V_74 -> V_28 ) ;
if ( V_17 ) {
V_17 -> V_66 . V_110 ++ ;
if ( V_17 -> V_53 . V_111 != V_72 )
V_17 -> V_53 . V_111 = V_72 ;
}
if ( V_7 ) {
struct V_47 * V_48 ;
unsigned long V_112 ;
if ( F_60 ( V_17 , V_113 ) && V_17 -> V_114 ) {
V_48 = & V_17 -> V_49 [ V_115 ] ;
V_112 = V_17 -> V_116 [ V_115 ] ;
if ( ! F_61 ( V_48 , V_63 + V_112 ) )
F_62 ( V_17 ) ;
}
}
F_3 ( L_10 , V_74 -> V_92 ) ;
V_74 -> V_117 = V_2 -> V_9 ;
(* V_72 -> V_109 -> V_118 )( V_74 , V_72 ) ;
V_56:
F_1 ( V_2 ) ;
return V_75 ;
V_86:
F_63 ( V_74 ) ;
F_64 ( F_65 ( V_17 -> V_27 . V_28 ) , V_119 ) ;
V_75:
F_11 (chunk, tmp, &packet->chunk_list, list) {
F_12 ( & V_14 -> V_35 ) ;
if ( ! F_20 ( V_14 ) )
F_13 ( V_14 ) ;
}
goto V_56;
V_83:
V_75 = - V_120 ;
goto V_75;
}
static T_4 F_30 ( struct V_1 * V_2 ,
struct V_13 * V_14 )
{
T_4 V_37 = V_42 ;
T_3 V_121 , V_55 , V_122 , V_123 ;
struct V_18 * V_16 = V_2 -> V_16 ;
struct V_21 * V_17 = V_16 -> V_17 ;
struct V_124 * V_125 = & V_17 -> V_126 ;
V_55 = V_17 -> V_53 . V_55 ;
V_122 = V_125 -> V_127 ;
V_123 = V_16 -> V_123 ;
V_121 = F_66 ( V_14 ) ;
if ( V_121 > V_55 ) {
if ( V_122 > 0 ) {
V_37 = V_41 ;
goto V_60;
}
}
if ( V_14 -> V_128 != V_129 )
if ( V_123 >= V_16 -> V_130 ) {
V_37 = V_41 ;
goto V_60;
}
if ( ! F_9 ( V_17 -> V_27 . V_28 ) -> V_131 && F_4 ( V_2 ) &&
V_122 && F_60 ( V_17 , V_113 ) ) {
unsigned int V_132 = V_16 -> V_133 - V_2 -> V_4 ;
unsigned int V_92 = V_14 -> V_39 -> V_92 + V_125 -> V_134 ;
if ( ( V_92 < V_132 ) && V_14 -> V_135 -> V_136 ) {
V_37 = V_43 ;
goto V_60;
}
}
V_60:
return V_37 ;
}
static void F_28 ( struct V_1 * V_2 ,
struct V_13 * V_14 )
{
struct V_18 * V_16 = V_2 -> V_16 ;
T_3 V_121 = F_66 ( V_14 ) ;
struct V_21 * V_17 = V_16 -> V_17 ;
T_6 V_55 = V_17 -> V_53 . V_55 ;
V_16 -> V_123 += V_121 ;
V_17 -> V_126 . V_127 += V_121 ;
if ( V_121 < V_55 )
V_55 -= V_121 ;
else
V_55 = 0 ;
V_17 -> V_53 . V_55 = V_55 ;
if ( ! V_17 -> V_53 . V_137 )
V_14 -> V_135 -> V_138 = 0 ;
F_67 ( V_14 ) ;
F_68 ( V_14 ) ;
}
static T_4 F_27 ( struct V_1 * V_2 ,
struct V_13 * V_14 ,
T_7 V_58 )
{
T_3 V_139 ;
T_3 V_140 ;
int V_141 ;
T_4 V_37 = V_42 ;
V_139 = V_2 -> V_3 ;
V_140 = ( ( V_2 -> V_16 -> V_17 ) ?
( V_2 -> V_16 -> V_17 -> V_133 ) :
( V_2 -> V_16 -> V_133 ) ) ;
V_141 = ( V_139 + V_58 > V_140 ) ;
if ( V_141 ) {
if ( F_4 ( V_2 ) || ! F_20 ( V_14 ) ||
( ! V_2 -> V_7 && V_14 -> V_10 ) ) {
V_2 -> V_9 = 1 ;
} else {
V_37 = V_38 ;
}
}
return V_37 ;
}
