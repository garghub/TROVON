static void F_1 ( struct V_1 * V_2 , void * V_3 ,
struct V_4 * V_5 , T_1 V_6 )
{
struct V_7 * V_8 = (struct V_7 * ) V_5 ;
if ( V_8 != NULL ) {
if ( V_8 -> V_9 != V_10 )
F_2 ( & V_2 -> V_11 . V_12 , L_1 ,
F_3 ( V_8 -> V_9 ) , V_8 -> V_9 ) ;
} else
F_2 ( & V_2 -> V_11 . V_12 , L_2 ) ;
F_4 ( & V_2 -> V_13 ) ;
if ( V_2 -> V_14 > 1 ) {
V_2 -> V_14 = 0 ;
F_5 ( V_2 ) ;
} else {
V_2 -> V_14 = 0 ;
}
F_6 ( & V_2 -> V_13 ) ;
}
int F_7 ( struct V_1 * V_2 )
{
int V_15 ;
struct V_16 * V_17 ;
struct V_18 * V_19 ;
struct V_20 * V_21 ;
int V_22 = 0 ;
T_2 * V_23 ;
V_15 = - V_24 ;
F_8 (rsv, &rc->reservations, rc_node) {
if ( V_19 -> V_25 != NULL ) {
V_22 += V_19 -> V_25 -> V_26 . V_27 + 2 ;
if ( F_9 ( V_19 ) &&
( V_19 -> V_21 . V_28 != NULL ) ) {
V_21 = & V_19 -> V_21 ;
V_22 += V_21 -> V_28 -> V_26 . V_27 + 2 ;
}
}
}
V_22 += sizeof( V_2 -> V_29 . V_30 ) ;
V_17 = F_10 ( sizeof( * V_17 ) + V_22 , V_31 ) ;
if ( V_17 == NULL )
goto error;
V_17 -> V_32 . V_33 = V_34 ;
V_17 -> V_32 . V_35 = F_11 ( V_36 ) ;
V_17 -> V_37 = V_22 ;
V_23 = ( T_2 * ) & V_17 -> V_38 [ 0 ] ;
memcpy ( V_23 , & V_2 -> V_29 . V_30 , sizeof( V_2 -> V_29 . V_30 ) ) ;
V_23 += sizeof( struct V_39 ) ;
F_8 (rsv, &rc->reservations, rc_node) {
if ( V_19 -> V_25 != NULL ) {
memcpy ( V_23 , V_19 -> V_25 ,
V_19 -> V_25 -> V_26 . V_27 + 2 ) ;
V_23 += V_19 -> V_25 -> V_26 . V_27 + 2 ;
if ( F_9 ( V_19 ) &&
( V_19 -> V_21 . V_28 != NULL ) ) {
V_21 = & V_19 -> V_21 ;
memcpy ( V_23 , V_21 -> V_28 ,
V_21 -> V_28 -> V_26 . V_27 + 2 ) ;
V_23 += V_21 -> V_28 -> V_26 . V_27 + 2 ;
}
}
}
V_15 = F_12 ( V_2 , L_3 , & V_17 -> V_32 , sizeof( * V_17 ) + V_22 ,
V_34 , V_36 ,
F_1 , NULL ) ;
V_2 -> V_14 = 1 ;
F_13 ( V_17 ) ;
error:
return V_15 ;
}
static int F_14 ( struct V_40 * V_41 , int V_42 ,
struct V_18 * V_19 , int V_43 )
{
int V_44 = V_19 -> V_45 ;
int V_46 = V_19 -> type ;
int V_47 = V_19 -> V_2 -> V_11 . V_48 ;
int V_49 = F_15 ( V_41 ) ;
int V_50 = F_16 ( V_41 ) ;
int V_51 = F_17 ( V_41 ) ;
if ( V_51 == V_52 && V_46 == V_52 ) {
return V_53 ;
}
if ( V_46 == V_54 ) {
return V_53 ;
}
if ( V_51 == V_54 ) {
return V_55 ;
}
if ( V_43 == 0 && V_50 == 1 ) {
return V_56 ;
}
if ( V_43 == 1 && V_50 == 0 ) {
return V_53 ;
}
if ( V_44 == V_49 &&
V_47 < V_42 ) {
return V_53 ;
}
if ( V_44 != V_49 &&
V_47 > V_42 ) {
return V_53 ;
}
if ( V_43 == 0 ) {
if ( V_44 == V_49 ) {
if ( V_47 > V_42 ) {
return V_56 ;
}
} else {
if ( V_47 < V_42 ) {
return V_56 ;
}
}
} else {
if ( V_44 == V_49 ) {
if ( V_47 > V_42 ) {
return V_57 ;
}
} else {
if ( V_47 < V_42 ) {
return V_57 ;
}
}
}
return V_53 ;
}
static void F_18 ( struct V_40 * V_25 ,
int V_42 ,
struct V_18 * V_19 ,
struct V_58 * V_59 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
struct V_20 * V_21 = & V_19 -> V_21 ;
struct V_60 * V_61 = & V_2 -> V_61 ;
int V_62 ;
V_62 = F_14 ( V_25 , V_42 , V_19 , F_19 ( V_19 ) ) ;
if ( F_20 ( V_19 ) ) {
switch( V_62 ) {
case V_56 :
F_21 ( V_19 , V_63 ) ;
if ( V_61 -> V_64 == false )
F_22 ( V_2 ) ;
break;
case V_57 :
F_22 ( V_2 ) ;
F_23 ( V_21 -> V_65 . V_66 , V_19 -> V_67 . V_66 , V_59 -> V_66 , V_68 ) ;
F_21 ( V_19 , V_69 ) ;
default:
break;
}
} else {
switch( V_62 ) {
case V_56 :
case V_57 :
F_21 ( V_19 , V_70 ) ;
default:
break;
}
}
}
static void F_24 ( struct V_40 * V_25 , int V_42 ,
struct V_18 * V_19 , bool V_71 ,
struct V_58 * V_59 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
struct V_60 * V_61 = & V_2 -> V_61 ;
struct V_20 * V_21 = & V_19 -> V_21 ;
int V_62 ;
if ( V_71 ) {
V_62 = F_14 ( V_25 , V_42 , V_19 , 0 ) ;
if ( F_20 ( V_19 ) ) {
switch( V_62 ) {
case V_56 :
case V_57 :
F_21 ( V_19 , V_72 ) ;
V_19 -> V_73 = false ;
if ( V_61 -> V_64 == false )
F_22 ( V_2 ) ;
F_25 ( V_19 -> V_2 , & V_19 -> V_21 . V_65 ) ;
}
} else {
switch( V_62 ) {
case V_56 :
case V_57 :
F_21 ( V_19 , V_74 ) ;
}
}
} else {
if ( F_20 ( V_19 ) ) {
F_22 ( V_2 ) ;
F_25 ( V_19 -> V_2 , & V_19 -> V_21 . V_65 ) ;
F_26 ( V_21 -> V_65 . V_66 , V_19 -> V_67 . V_66 , V_59 -> V_66 , V_68 ) ;
F_21 ( V_19 , V_69 ) ;
} else {
F_21 ( V_19 , V_70 ) ;
}
}
}
static void F_27 ( struct V_1 * V_2 , struct V_18 * V_19 ,
struct V_75 * V_76 ,
struct V_40 * V_25 ,
struct V_58 * V_59 )
{
struct V_20 * V_21 ;
if ( F_9 ( V_19 ) ) {
V_21 = & V_19 -> V_21 ;
if ( F_28 ( V_19 -> V_67 . V_66 , V_59 -> V_66 , V_68 ) ) {
F_24 ( V_25 , V_76 -> V_77 ,
V_19 , false , V_59 ) ;
} else {
if ( F_28 ( V_21 -> V_65 . V_66 , V_59 -> V_66 , V_68 ) ) {
F_24 ( V_25 , V_76 -> V_77 ,
V_19 , true , V_59 ) ;
}
}
} else if ( F_28 ( V_19 -> V_67 . V_66 , V_59 -> V_66 , V_68 ) ) {
F_18 ( V_25 , V_76 -> V_77 , V_19 , V_59 ) ;
}
}
static void F_29 ( struct V_1 * V_2 ,
struct V_75 * V_76 ,
struct V_40 * V_25 ,
struct V_58 * V_59 )
{
struct V_18 * V_19 ;
F_8 (rsv, &rc->reservations, rc_node) {
F_27 ( V_2 , V_19 , V_76 , V_25 , V_59 ) ;
}
}
static void F_30 ( struct V_1 * V_2 , struct V_18 * V_19 ,
struct V_40 * V_25 , struct V_75 * V_76 )
{
struct V_78 * V_12 = & V_2 -> V_11 . V_12 ;
struct V_20 * V_21 = & V_19 -> V_21 ;
int V_79 ;
enum V_80 V_81 ;
struct V_58 V_67 ;
V_79 = F_16 ( V_25 ) ;
V_81 = F_31 ( V_25 ) ;
F_32 ( & V_67 , V_25 ) ;
switch ( V_81 ) {
case V_82 :
if ( V_19 -> V_83 == V_70 ) {
F_21 ( V_19 , V_70 ) ;
break;
}
if ( V_19 -> V_83 == V_84 ) {
if ( ! F_33 ( V_19 -> V_67 . V_66 , V_67 . V_66 , V_68 ) )
F_21 ( V_19 , V_84 ) ;
} else {
if ( ! F_33 ( V_19 -> V_67 . V_66 , V_67 . V_66 , V_68 ) ) {
if ( F_34 ( V_2 , & V_67 ) == - V_85 ) {
F_29 ( V_2 , V_76 , V_25 , & V_67 ) ;
} else {
F_35 ( V_21 -> V_65 . V_66 , V_67 . V_66 , V_68 ) ;
F_21 ( V_19 , V_84 ) ;
}
} else {
if ( V_79 ) {
F_21 ( V_19 , V_86 ) ;
}
}
}
break;
case V_87 :
if ( F_33 ( V_19 -> V_67 . V_66 , V_67 . V_66 , V_68 ) ) {
F_21 ( V_19 , V_86 ) ;
break;
}
if ( F_36 ( V_67 . V_66 , V_19 -> V_67 . V_66 , V_68 ) ) {
F_26 ( V_21 -> V_65 . V_66 , V_19 -> V_67 . V_66 , V_67 . V_66 , V_68 ) ;
F_25 ( V_19 -> V_2 , & V_21 -> V_65 ) ;
}
F_35 ( V_19 -> V_67 . V_66 , V_67 . V_66 , V_68 ) ;
F_21 ( V_19 , V_88 ) ;
break;
default:
F_37 ( V_12 , L_4 ,
V_81 , V_79 ) ;
}
}
static void F_38 ( struct V_1 * V_2 , struct V_18 * V_19 ,
struct V_11 * V_89 , struct V_40 * V_25 ,
struct V_75 * V_76 )
{
struct V_78 * V_12 = & V_2 -> V_11 . V_12 ;
struct V_20 * V_21 = & V_19 -> V_21 ;
int V_79 ;
enum V_80 V_81 ;
struct V_58 V_67 ;
V_79 = F_16 ( V_25 ) ;
V_81 = F_31 ( V_25 ) ;
F_32 ( & V_67 , V_25 ) ;
if ( V_79 ) {
switch ( V_81 ) {
case V_82 :
switch ( V_19 -> V_83 ) {
case V_90 :
case V_91 :
case V_72 :
F_21 ( V_19 , V_72 ) ;
break;
case V_69 :
if ( F_33 ( V_67 . V_66 , V_19 -> V_67 . V_66 , V_68 ) ) {
F_21 ( V_19 , V_72 ) ;
} else {
F_21 ( V_19 , V_69 ) ;
}
break;
case V_92 :
if ( F_33 ( V_67 . V_66 , V_19 -> V_67 . V_66 , V_68 ) ) {
F_21 ( V_19 , V_72 ) ;
} else {
F_21 ( V_19 , V_92 ) ;
}
break;
case V_93 :
if ( F_33 ( V_67 . V_66 , V_21 -> V_65 . V_66 , V_68 ) ) {
F_21 ( V_19 , V_94 ) ;
} else {
F_21 ( V_19 , V_93 ) ;
}
break;
case V_94 :
if ( F_33 ( V_67 . V_66 , V_19 -> V_67 . V_66 , V_68 ) )
F_21 ( V_19 , V_92 ) ;
else
F_21 ( V_19 , V_94 ) ;
break;
default:
break;
}
break;
default:
F_37 ( V_12 , L_4 ,
V_81 , V_79 ) ;
}
} else {
switch ( V_81 ) {
case V_95 :
F_21 ( V_19 , V_90 ) ;
break;
case V_96 :
F_21 ( V_19 , V_97 ) ;
break;
case V_98 :
F_39 ( V_67 . V_66 , V_89 -> V_99 ,
V_68 ) ;
F_27 ( V_2 , V_19 , V_76 , V_25 , & V_67 ) ;
break;
default:
F_37 ( V_12 , L_4 ,
V_81 , V_79 ) ;
}
}
}
static void F_40 ( struct V_100 * V_101 )
{
unsigned V_102 = V_103 * V_104 ;
F_41 ( & V_101 -> V_105 , V_106 + F_42 ( V_102 ) ) ;
}
static void F_43 ( struct V_107 * V_108 )
{
struct V_100 * V_101 = F_44 ( V_108 ,
struct V_100 ,
V_109 ) ;
struct V_100 * V_110 ;
struct V_1 * V_2 = V_101 -> V_2 ;
unsigned long V_111 = V_112 * V_113 ;
F_45 ( & V_2 -> V_114 ) ;
F_46 ( & V_101 -> V_115 ) ;
F_47 ( V_2 -> V_116 . V_66 , V_68 ) ;
F_8 (c, &rc->cnflt_alien_list, rc_node) {
F_48 ( V_2 -> V_116 . V_66 , V_2 -> V_116 . V_66 , V_110 -> V_67 . V_66 , V_68 ) ;
}
F_49 ( V_2 -> V_117 , & V_2 -> V_118 , F_42 ( V_111 ) ) ;
F_13 ( V_101 ) ;
F_50 ( & V_2 -> V_114 ) ;
}
static void F_51 ( unsigned long V_3 )
{
struct V_100 * V_101 = (struct V_100 * ) V_3 ;
F_52 ( V_101 -> V_2 -> V_117 , & V_101 -> V_109 ) ;
}
static void F_53 ( struct V_1 * V_2 , struct V_40 * V_25 )
{
struct V_78 * V_12 = & V_2 -> V_11 . V_12 ;
struct V_58 V_67 ;
struct V_100 * V_101 ;
char V_119 [ 72 ] ;
unsigned long V_111 = V_112 * V_113 ;
F_32 ( & V_67 , V_25 ) ;
F_54 ( V_119 , sizeof( V_119 ) , V_67 . V_66 , V_68 ) ;
F_8 (cnflt, &rc->cnflt_alien_list, rc_node) {
if ( F_33 ( V_101 -> V_67 . V_66 , V_67 . V_66 , V_68 ) ) {
F_40 ( V_101 ) ;
return;
}
}
V_101 = F_10 ( sizeof( struct V_100 ) , V_31 ) ;
if ( ! V_101 )
F_2 ( V_12 , L_5 ) ;
F_55 ( & V_101 -> V_115 ) ;
F_56 ( & V_101 -> V_105 ) ;
V_101 -> V_105 . V_120 = F_51 ;
V_101 -> V_105 . V_121 = ( unsigned long ) V_101 ;
V_101 -> V_2 = V_2 ;
F_57 ( & V_101 -> V_109 , F_43 ) ;
F_35 ( V_101 -> V_67 . V_66 , V_67 . V_66 , V_68 ) ;
F_58 ( & V_101 -> V_115 , & V_2 -> V_122 ) ;
F_48 ( V_2 -> V_116 . V_66 , V_2 -> V_116 . V_66 , V_67 . V_66 , V_68 ) ;
F_49 ( V_2 -> V_117 , & V_2 -> V_118 , F_42 ( V_111 ) ) ;
F_40 ( V_101 ) ;
}
static void F_59 ( struct V_1 * V_2 ,
struct V_75 * V_76 ,
struct V_40 * V_25 )
{
struct V_58 V_67 ;
F_32 ( & V_67 , V_25 ) ;
F_29 ( V_2 , V_76 , V_25 , & V_67 ) ;
}
static void F_60 ( struct V_1 * V_2 , struct V_11 * V_89 ,
struct V_75 * V_76 ,
struct V_40 * V_25 )
{
struct V_18 * V_19 ;
V_19 = F_61 ( V_2 , V_89 , V_25 ) ;
if ( ! V_19 ) {
return;
}
if ( V_19 -> V_83 == V_97 ) {
F_21 ( V_19 , V_97 ) ;
return;
}
if ( F_62 ( V_25 ) )
F_30 ( V_2 , V_19 , V_25 , V_76 ) ;
else
F_38 ( V_2 , V_19 , V_89 , V_25 , V_76 ) ;
}
static bool F_63 ( struct V_1 * V_2 , struct V_40 * V_25 )
{
return F_64 ( & V_2 -> V_11 . V_123 , & V_25 -> V_123 ) == 0 ;
}
static void F_65 ( struct V_1 * V_2 , struct V_75 * V_76 ,
struct V_11 * V_89 , struct V_40 * V_25 )
{
if ( F_17 ( V_25 ) == V_54 )
F_53 ( V_2 , V_25 ) ;
else if ( F_63 ( V_2 , V_25 ) )
F_60 ( V_2 , V_89 , V_76 , V_25 ) ;
else
F_59 ( V_2 , V_76 , V_25 ) ;
}
static void F_66 ( struct V_1 * V_2 , struct V_11 * V_89 ,
struct V_39 * V_124 )
{
F_35 ( V_89 -> V_99 ,
V_124 -> V_125 , V_68 ) ;
}
static
void F_67 ( struct V_1 * V_2 , struct V_75 * V_76 ,
T_3 V_126 , struct V_11 * V_127 )
{
struct V_78 * V_12 = & V_2 -> V_11 . V_12 ;
struct V_128 * V_129 ;
void * V_130 ;
V_130 = V_76 -> V_131 ;
for (; ; ) {
V_129 = F_68 ( & V_130 , & V_126 ) ;
if ( ! V_129 )
break;
switch ( V_129 -> V_132 ) {
case V_133 :
F_66 ( V_2 , V_127 , (struct V_39 * ) V_129 ) ;
break;
case V_134 :
F_65 ( V_2 , V_76 , V_127 , (struct V_40 * ) V_129 ) ;
break;
default:
F_37 ( V_12 , L_6 ) ;
break;
}
}
if ( V_126 > 0 )
F_37 ( V_12 , L_7 ,
( int ) V_126 ) ;
}
int F_69 ( struct V_135 * V_136 )
{
struct V_78 * V_12 = & V_136 -> V_2 -> V_11 . V_12 ;
struct V_1 * V_2 = V_136 -> V_2 ;
struct V_75 * V_76 ;
T_3 V_137 , V_138 ;
struct V_139 V_140 ;
struct V_11 * V_127 ;
if ( V_136 -> V_141 . V_142 < sizeof( * V_76 ) ) {
F_2 ( V_12 , L_8
L_9 ,
V_136 -> V_141 . V_142 , sizeof( * V_76 ) ) ;
return 0 ;
}
V_138 = V_136 -> V_141 . V_142 - sizeof( * V_76 ) ;
V_76 = F_44 ( V_136 -> V_141 . V_143 , struct V_75 , V_143 ) ;
V_137 = F_70 ( V_76 -> V_144 ) ;
if ( V_138 != V_137 ) {
F_2 ( V_12 , L_10
L_11 ,
V_138 , V_137 ) ;
return 0 ;
}
memcpy ( V_140 . V_121 , & V_76 -> V_140 , sizeof( V_140 ) ) ;
V_127 = F_71 ( V_2 , & V_140 ) ;
if ( ! V_127 ) {
return 0 ;
}
F_45 ( & V_2 -> V_114 ) ;
F_67 ( V_2 , V_76 , V_137 , V_127 ) ;
F_50 ( & V_2 -> V_114 ) ;
F_72 ( V_127 ) ;
return 0 ;
}
