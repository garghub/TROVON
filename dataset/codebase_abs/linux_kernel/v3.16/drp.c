static void F_1 ( struct V_1 * V_2 , void * V_3 ,
struct V_4 * V_5 , T_1 V_6 )
{
struct V_7 * V_8 = (struct V_7 * ) V_5 ;
unsigned long V_9 ;
if ( V_8 != NULL ) {
if ( V_8 -> V_10 != V_11 )
F_2 ( & V_2 -> V_12 . V_13 , L_1 ,
F_3 ( V_8 -> V_10 ) , V_8 -> V_10 ) ;
} else
F_2 ( & V_2 -> V_12 . V_13 , L_2 ) ;
F_4 ( & V_2 -> V_14 , V_9 ) ;
if ( V_2 -> V_15 > 1 ) {
V_2 -> V_15 = 0 ;
F_5 ( V_2 ) ;
} else {
V_2 -> V_15 = 0 ;
}
F_6 ( & V_2 -> V_14 , V_9 ) ;
}
int F_7 ( struct V_1 * V_2 )
{
int V_16 ;
struct V_17 * V_18 ;
struct V_19 * V_20 ;
struct V_21 * V_22 ;
int V_23 = 0 ;
T_2 * V_24 ;
V_16 = - V_25 ;
F_8 (rsv, &rc->reservations, rc_node) {
if ( V_20 -> V_26 != NULL ) {
V_23 += V_20 -> V_26 -> V_27 . V_28 + 2 ;
if ( F_9 ( V_20 ) &&
( V_20 -> V_22 . V_29 != NULL ) ) {
V_22 = & V_20 -> V_22 ;
V_23 +=
V_22 -> V_29 -> V_27 . V_28 + 2 ;
}
}
}
V_23 += sizeof( V_2 -> V_30 . V_31 ) ;
V_18 = F_10 ( sizeof( * V_18 ) + V_23 , V_32 ) ;
if ( V_18 == NULL )
goto error;
V_18 -> V_33 . V_34 = V_35 ;
V_18 -> V_33 . V_36 = F_11 ( V_37 ) ;
V_18 -> V_38 = V_23 ;
V_24 = ( T_2 * ) & V_18 -> V_39 [ 0 ] ;
memcpy ( V_24 , & V_2 -> V_30 . V_31 , sizeof( V_2 -> V_30 . V_31 ) ) ;
V_24 += sizeof( struct V_40 ) ;
F_8 (rsv, &rc->reservations, rc_node) {
if ( V_20 -> V_26 != NULL ) {
memcpy ( V_24 , V_20 -> V_26 ,
V_20 -> V_26 -> V_27 . V_28 + 2 ) ;
V_24 += V_20 -> V_26 -> V_27 . V_28 + 2 ;
if ( F_9 ( V_20 ) &&
( V_20 -> V_22 . V_29 != NULL ) ) {
V_22 = & V_20 -> V_22 ;
memcpy ( V_24 , V_22 -> V_29 ,
V_22 -> V_29 -> V_27 . V_28 + 2 ) ;
V_24 +=
V_22 -> V_29 -> V_27 . V_28 + 2 ;
}
}
}
V_16 = F_12 ( V_2 , L_3 ,
& V_18 -> V_33 , sizeof( * V_18 ) + V_23 ,
V_35 , V_37 ,
F_1 , NULL ) ;
V_2 -> V_15 = 1 ;
F_13 ( V_18 ) ;
error:
return V_16 ;
}
static int F_14 ( struct V_41 * V_42 , int V_43 ,
struct V_19 * V_20 , int V_44 )
{
int V_45 = V_20 -> V_46 ;
int V_47 = V_20 -> type ;
int V_48 = V_20 -> V_2 -> V_12 . V_49 ;
int V_50 = F_15 ( V_42 ) ;
int V_51 = F_16 ( V_42 ) ;
int V_52 = F_17 ( V_42 ) ;
if ( V_52 == V_53 && V_47 == V_53 ) {
return V_54 ;
}
if ( V_47 == V_55 ) {
return V_54 ;
}
if ( V_52 == V_55 ) {
return V_56 ;
}
if ( V_44 == 0 && V_51 == 1 ) {
return V_57 ;
}
if ( V_44 == 1 && V_51 == 0 ) {
return V_54 ;
}
if ( V_45 == V_50 &&
V_48 < V_43 ) {
return V_54 ;
}
if ( V_45 != V_50 &&
V_48 > V_43 ) {
return V_54 ;
}
if ( V_44 == 0 ) {
if ( V_45 == V_50 ) {
if ( V_48 > V_43 ) {
return V_57 ;
}
} else {
if ( V_48 < V_43 ) {
return V_57 ;
}
}
} else {
if ( V_45 == V_50 ) {
if ( V_48 > V_43 ) {
return V_58 ;
}
} else {
if ( V_48 < V_43 ) {
return V_58 ;
}
}
}
return V_54 ;
}
static void F_18 ( struct V_41 * V_26 ,
int V_43 ,
struct V_19 * V_20 ,
struct V_59 * V_60 )
{
struct V_1 * V_2 = V_20 -> V_2 ;
struct V_21 * V_22 = & V_20 -> V_22 ;
struct V_61 * V_62 = & V_2 -> V_62 ;
int V_63 ;
V_63 = F_14 ( V_26 , V_43 , V_20 , F_19 ( V_20 ) ) ;
if ( F_20 ( V_20 ) ) {
switch( V_63 ) {
case V_57 :
F_21 ( V_20 , V_64 ) ;
if ( V_62 -> V_65 == false )
F_22 ( V_2 ) ;
break;
case V_58 :
F_22 ( V_2 ) ;
F_23 ( V_22 -> V_66 . V_67 , V_20 -> V_68 . V_67 , V_60 -> V_67 , V_69 ) ;
F_21 ( V_20 , V_70 ) ;
default:
break;
}
} else {
switch( V_63 ) {
case V_57 :
case V_58 :
F_21 ( V_20 , V_71 ) ;
default:
break;
}
}
}
static void F_24 ( struct V_41 * V_26 , int V_43 ,
struct V_19 * V_20 , bool V_72 ,
struct V_59 * V_60 )
{
struct V_1 * V_2 = V_20 -> V_2 ;
struct V_61 * V_62 = & V_2 -> V_62 ;
struct V_21 * V_22 = & V_20 -> V_22 ;
int V_63 ;
if ( V_72 ) {
V_63 = F_14 ( V_26 , V_43 , V_20 , 0 ) ;
if ( F_20 ( V_20 ) ) {
switch( V_63 ) {
case V_57 :
case V_58 :
F_21 ( V_20 ,
V_73 ) ;
V_20 -> V_74 = false ;
if ( V_62 -> V_65 == false )
F_22 ( V_2 ) ;
F_25 ( V_20 -> V_2 ,
& V_20 -> V_22 . V_66 ) ;
}
} else {
switch( V_63 ) {
case V_57 :
case V_58 :
F_21 ( V_20 ,
V_75 ) ;
}
}
} else {
if ( F_20 ( V_20 ) ) {
F_22 ( V_2 ) ;
F_25 ( V_20 -> V_2 , & V_20 -> V_22 . V_66 ) ;
F_26 ( V_22 -> V_66 . V_67 , V_20 -> V_68 . V_67 ,
V_60 -> V_67 , V_69 ) ;
F_21 ( V_20 , V_70 ) ;
} else {
F_21 ( V_20 , V_71 ) ;
}
}
}
static void F_27 ( struct V_1 * V_2 , struct V_19 * V_20 ,
struct V_76 * V_77 ,
struct V_41 * V_26 ,
struct V_59 * V_60 )
{
struct V_21 * V_22 ;
if ( F_9 ( V_20 ) ) {
V_22 = & V_20 -> V_22 ;
if ( F_28 ( V_20 -> V_68 . V_67 , V_60 -> V_67 ,
V_69 ) ) {
F_24 ( V_26 ,
V_77 -> V_78 ,
V_20 , false , V_60 ) ;
} else {
if ( F_28 ( V_22 -> V_66 . V_67 ,
V_60 -> V_67 , V_69 ) ) {
F_24 (
V_26 , V_77 -> V_78 ,
V_20 , true , V_60 ) ;
}
}
} else if ( F_28 ( V_20 -> V_68 . V_67 , V_60 -> V_67 ,
V_69 ) ) {
F_18 ( V_26 , V_77 -> V_78 ,
V_20 , V_60 ) ;
}
}
static void F_29 ( struct V_1 * V_2 ,
struct V_76 * V_77 ,
struct V_41 * V_26 ,
struct V_59 * V_60 )
{
struct V_19 * V_20 ;
F_8 (rsv, &rc->reservations, rc_node) {
F_27 ( V_2 , V_20 , V_77 , V_26 ,
V_60 ) ;
}
}
static void F_30 ( struct V_1 * V_2 ,
struct V_19 * V_20 , struct V_76 * V_77 ,
struct V_41 * V_26 , struct V_59 * V_68 )
{
struct V_21 * V_22 = & V_20 -> V_22 ;
int V_79 ;
V_79 = F_16 ( V_26 ) ;
if ( V_20 -> V_80 == V_71 ) {
F_21 ( V_20 , V_71 ) ;
return;
}
if ( V_20 -> V_80 == V_81 ) {
if ( ! F_31 ( V_20 -> V_68 . V_67 , V_68 -> V_67 , V_69 ) ) {
F_21 ( V_20 ,
V_81 ) ;
}
} else {
if ( ! F_31 ( V_20 -> V_68 . V_67 , V_68 -> V_67 , V_69 ) ) {
if ( F_32 ( V_2 , V_68 ) == - V_82 ) {
F_29 ( V_2 , V_77 ,
V_26 , V_68 ) ;
} else {
F_33 ( V_22 -> V_66 . V_67 , V_68 -> V_67 ,
V_69 ) ;
F_21 ( V_20 ,
V_81 ) ;
}
} else {
if ( V_79 ) {
F_21 ( V_20 ,
V_83 ) ;
}
}
}
}
static void F_34 ( struct V_1 * V_2 , struct V_19 * V_20 ,
struct V_41 * V_26 , struct V_76 * V_77 )
{
struct V_84 * V_13 = & V_2 -> V_12 . V_13 ;
struct V_21 * V_22 = & V_20 -> V_22 ;
int V_79 ;
enum V_85 V_86 ;
struct V_59 V_68 ;
V_79 = F_16 ( V_26 ) ;
V_86 = F_35 ( V_26 ) ;
F_36 ( & V_68 , V_26 ) ;
switch ( V_86 ) {
case V_87 :
F_30 ( V_2 , V_20 , V_77 , V_26 , & V_68 ) ;
break;
case V_88 :
if ( F_31 ( V_20 -> V_68 . V_67 , V_68 . V_67 , V_69 ) ) {
F_21 ( V_20 , V_83 ) ;
break;
}
if ( F_37 ( V_68 . V_67 , V_20 -> V_68 . V_67 , V_69 ) ) {
F_26 ( V_22 -> V_66 . V_67 , V_20 -> V_68 . V_67 , V_68 . V_67 ,
V_69 ) ;
F_25 ( V_20 -> V_2 , & V_22 -> V_66 ) ;
}
F_33 ( V_20 -> V_68 . V_67 , V_68 . V_67 , V_69 ) ;
F_21 ( V_20 , V_89 ) ;
break;
default:
F_38 ( V_13 , L_4 ,
V_86 , V_79 ) ;
}
}
static void F_39 ( struct V_19 * V_20 ,
struct V_59 * V_68 )
{
struct V_21 * V_22 = & V_20 -> V_22 ;
switch ( V_20 -> V_80 ) {
case V_90 :
case V_91 :
case V_73 :
F_21 ( V_20 , V_73 ) ;
break;
case V_70 :
if ( F_31 ( V_68 -> V_67 , V_20 -> V_68 . V_67 , V_69 ) )
F_21 ( V_20 , V_73 ) ;
else
F_21 ( V_20 , V_70 ) ;
break;
case V_92 :
if ( F_31 ( V_68 -> V_67 , V_20 -> V_68 . V_67 , V_69 ) )
F_21 ( V_20 , V_73 ) ;
else
F_21 ( V_20 , V_92 ) ;
break;
case V_93 :
if ( F_31 ( V_68 -> V_67 , V_22 -> V_66 . V_67 , V_69 ) ) {
F_21 ( V_20 , V_94 ) ;
} else {
F_21 ( V_20 , V_93 ) ;
}
break;
case V_94 :
if ( F_31 ( V_68 -> V_67 , V_20 -> V_68 . V_67 , V_69 ) )
F_21 ( V_20 , V_92 ) ;
else
F_21 ( V_20 , V_94 ) ;
break;
default:
break;
}
}
static void F_40 ( struct V_1 * V_2 , struct V_19 * V_20 ,
struct V_12 * V_95 , struct V_41 * V_26 ,
struct V_76 * V_77 )
{
struct V_84 * V_13 = & V_2 -> V_12 . V_13 ;
int V_79 ;
enum V_85 V_86 ;
struct V_59 V_68 ;
V_79 = F_16 ( V_26 ) ;
V_86 = F_35 ( V_26 ) ;
F_36 ( & V_68 , V_26 ) ;
if ( V_79 ) {
switch ( V_86 ) {
case V_87 :
F_39 ( V_20 , & V_68 ) ;
break;
default:
F_38 ( V_13 , L_4 ,
V_86 , V_79 ) ;
}
} else {
switch ( V_86 ) {
case V_96 :
F_21 ( V_20 , V_90 ) ;
break;
case V_97 :
F_21 ( V_20 , V_98 ) ;
break;
case V_99 :
F_41 ( V_68 . V_67 , V_95 -> V_100 ,
V_69 ) ;
F_27 ( V_2 , V_20 , V_77 , V_26 , & V_68 ) ;
break;
default:
F_38 ( V_13 , L_4 ,
V_86 , V_79 ) ;
}
}
}
static void F_42 ( struct V_101 * V_102 )
{
unsigned V_103 = V_104 * V_105 ;
F_43 ( & V_102 -> V_106 , V_107 + F_44 ( V_103 ) ) ;
}
static void F_45 ( struct V_108 * V_109 )
{
struct V_101 * V_102 = F_46 ( V_109 ,
struct V_101 ,
V_110 ) ;
struct V_101 * V_111 ;
struct V_1 * V_2 = V_102 -> V_2 ;
unsigned long V_112 = V_113 * V_114 ;
F_47 ( & V_2 -> V_115 ) ;
F_48 ( & V_102 -> V_116 ) ;
F_49 ( V_2 -> V_117 . V_67 , V_69 ) ;
F_8 (c, &rc->cnflt_alien_list, rc_node) {
F_50 ( V_2 -> V_117 . V_67 , V_2 -> V_117 . V_67 ,
V_111 -> V_68 . V_67 , V_69 ) ;
}
F_51 ( V_2 -> V_118 , & V_2 -> V_119 ,
F_44 ( V_112 ) ) ;
F_13 ( V_102 ) ;
F_52 ( & V_2 -> V_115 ) ;
}
static void F_53 ( unsigned long V_3 )
{
struct V_101 * V_102 = (struct V_101 * ) V_3 ;
F_54 ( V_102 -> V_2 -> V_118 , & V_102 -> V_110 ) ;
}
static void F_55 ( struct V_1 * V_2 , struct V_41 * V_26 )
{
struct V_84 * V_13 = & V_2 -> V_12 . V_13 ;
struct V_59 V_68 ;
struct V_101 * V_102 ;
char V_120 [ 72 ] ;
unsigned long V_112 = V_113 * V_114 ;
F_36 ( & V_68 , V_26 ) ;
F_56 ( V_120 , sizeof( V_120 ) , V_68 . V_67 , V_69 ) ;
F_8 (cnflt, &rc->cnflt_alien_list, rc_node) {
if ( F_31 ( V_102 -> V_68 . V_67 , V_68 . V_67 , V_69 ) ) {
F_42 ( V_102 ) ;
return;
}
}
V_102 = F_10 ( sizeof( struct V_101 ) , V_32 ) ;
if ( ! V_102 ) {
F_2 ( V_13 , L_5 ) ;
return;
}
F_57 ( & V_102 -> V_116 ) ;
F_58 ( & V_102 -> V_106 ) ;
V_102 -> V_106 . V_121 = F_53 ;
V_102 -> V_106 . V_122 = ( unsigned long ) V_102 ;
V_102 -> V_2 = V_2 ;
F_59 ( & V_102 -> V_110 , F_45 ) ;
F_33 ( V_102 -> V_68 . V_67 , V_68 . V_67 , V_69 ) ;
F_60 ( & V_102 -> V_116 , & V_2 -> V_123 ) ;
F_50 ( V_2 -> V_117 . V_67 , V_2 -> V_117 . V_67 , V_68 . V_67 , V_69 ) ;
F_51 ( V_2 -> V_118 , & V_2 -> V_119 , F_44 ( V_112 ) ) ;
F_42 ( V_102 ) ;
}
static void F_61 ( struct V_1 * V_2 ,
struct V_76 * V_77 ,
struct V_41 * V_26 )
{
struct V_59 V_68 ;
F_36 ( & V_68 , V_26 ) ;
F_29 ( V_2 , V_77 , V_26 , & V_68 ) ;
}
static void F_62 ( struct V_1 * V_2 , struct V_12 * V_95 ,
struct V_76 * V_77 ,
struct V_41 * V_26 )
{
struct V_19 * V_20 ;
V_20 = F_63 ( V_2 , V_95 , V_26 ) ;
if ( ! V_20 ) {
return;
}
if ( V_20 -> V_80 == V_98 ) {
F_21 ( V_20 , V_98 ) ;
return;
}
if ( F_64 ( V_26 ) )
F_34 ( V_2 , V_20 , V_26 , V_77 ) ;
else
F_40 ( V_2 , V_20 , V_95 , V_26 , V_77 ) ;
}
static bool F_65 ( struct V_1 * V_2 , struct V_41 * V_26 )
{
return F_66 ( & V_2 -> V_12 . V_124 , & V_26 -> V_124 ) == 0 ;
}
static void F_67 ( struct V_1 * V_2 , struct V_76 * V_77 ,
struct V_12 * V_95 , struct V_41 * V_26 )
{
if ( F_17 ( V_26 ) == V_55 )
F_55 ( V_2 , V_26 ) ;
else if ( F_65 ( V_2 , V_26 ) )
F_62 ( V_2 , V_95 , V_77 , V_26 ) ;
else
F_61 ( V_2 , V_77 , V_26 ) ;
}
static void F_68 ( struct V_1 * V_2 , struct V_12 * V_95 ,
struct V_40 * V_125 )
{
F_33 ( V_95 -> V_100 ,
V_125 -> V_126 , V_69 ) ;
}
static
void F_69 ( struct V_1 * V_2 , struct V_76 * V_77 ,
T_3 V_127 , struct V_12 * V_128 )
{
struct V_84 * V_13 = & V_2 -> V_12 . V_13 ;
struct V_129 * V_130 ;
void * V_131 ;
V_131 = V_77 -> V_132 ;
for (; ; ) {
V_130 = F_70 ( & V_131 , & V_127 ) ;
if ( ! V_130 )
break;
switch ( V_130 -> V_133 ) {
case V_134 :
F_68 ( V_2 , V_128 , (struct V_40 * ) V_130 ) ;
break;
case V_135 :
F_67 ( V_2 , V_77 , V_128 , (struct V_41 * ) V_130 ) ;
break;
default:
F_38 ( V_13 , L_6 ) ;
break;
}
}
if ( V_127 > 0 )
F_38 ( V_13 , L_7 ,
( int ) V_127 ) ;
}
int F_71 ( struct V_136 * V_137 )
{
struct V_84 * V_13 = & V_137 -> V_2 -> V_12 . V_13 ;
struct V_1 * V_2 = V_137 -> V_2 ;
struct V_76 * V_77 ;
T_3 V_138 , V_139 ;
struct V_140 V_141 ;
struct V_12 * V_128 ;
if ( V_137 -> V_142 . V_143 < sizeof( * V_77 ) ) {
F_2 ( V_13 , L_8
L_9 ,
V_137 -> V_142 . V_143 , sizeof( * V_77 ) ) ;
return 0 ;
}
V_139 = V_137 -> V_142 . V_143 - sizeof( * V_77 ) ;
V_77 = F_46 ( V_137 -> V_142 . V_144 , struct V_76 , V_144 ) ;
V_138 = F_72 ( V_77 -> V_145 ) ;
if ( V_139 != V_138 ) {
F_2 ( V_13 , L_10
L_11 ,
V_139 , V_138 ) ;
return 0 ;
}
memcpy ( V_141 . V_122 , & V_77 -> V_141 , sizeof( V_141 ) ) ;
V_128 = F_73 ( V_2 , & V_141 ) ;
if ( ! V_128 ) {
return 0 ;
}
F_47 ( & V_2 -> V_115 ) ;
F_69 ( V_2 , V_77 , V_138 , V_128 ) ;
F_52 ( & V_2 -> V_115 ) ;
F_74 ( V_128 ) ;
return 0 ;
}
